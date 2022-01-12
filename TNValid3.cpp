//---------------------------------------------------------------------------
#include <vcl.h>
#include "pch.h"

#pragma hdrstop

#include "TNValid3.h"
#ifndef TIUploadH
#include "TIUpload.h"
#endif
#ifndef TICalibH
#include "TICalib.h"
#endif
#ifndef TNUtilsH
#include "TNUtils.h"
#endif

//---------------------------------------------------------------------------

#pragma package(smart_init)

bool TNeotomaUploadForm::ValidateGeochron(void)
{
   UnicodeString msg, ErrorMsg;
   SITE* site_ptr;
   set<UnicodeString> DatasetGeochronTypes;  // list of all GeochronTypes in dataset
   AGEMODEL* mfAgeModel = NULL;

   // first assign taxa groups to dataset types
   SPECIMENDATETAXAGROUPS TaxaGroupDatasetTypes;

   // store existng Chron Numbers in case a new one is added for plant macrofossils
   // need to do this even if no geochron measurements
   for (int i=0; i<TSSForm->AgeModelList->Count; i++) {
	 AGEMODEL* AgeModel = TSSForm->AgeModelList->AgeModels[i];
	 ChronNumbers.insert(AgeModel->ChronNumber);
	 }

   try {
   Screen->Cursor = crHourGlass;
   int gcount = TSSForm->GeochronList->Count();

   if (gcount == 0) {
	 OutputWarning(L"WARNING: No geochronological data entered.");
	 return true;
	 }


   // if multi collection units, geochron samples must be assigned to spreadsheet analysis units
   site_ptr = (SITE*)TSSForm->Sites->Items[0];

   // ----------------
   int CollUnitID = site_ptr->CollUnits[0].NeotomaCollUnitID;
   if (CollUnitID > 0) {
	 NeotomaSiteDatasets NtmSiteDatasets(ipsJSONS1, TcpClient1);
	 NtmSiteDatasets.AddParam(L"SITEID", site_ptr->NeotomaSiteID);
	 StatusBar1->SimpleText = NtmSiteDatasets.WebServiceName();
	 if (NtmSiteDatasets.Execute()) {
	   if (NtmSiteDatasets.Size() > 0) {
		 bool geochron_exists = false;
		 for (unsigned int i=0; i<NtmSiteDatasets.Size(); i++) {
		   UnicodeString DatasetType = NtmSiteDatasets.Items[i].DatasetType;
		   if (NtmSiteDatasets.Items[i].CollectionUnitID == CollUnitID &&
			   SameText(DatasetType,L"geochronologic")) {
			 geochron_exists = true;
			 break;
			 }
		   }
		 AddGeochronToExistingCollUnit = !geochron_exists;
		 }
	   }
	 else
	   return false;
	 }
   // ----------------


   if (TSSForm->Sites->Count > 1 || site_ptr->CollUnits.size() > 1) {
	 for (int i=0; i<gcount; i++) {
	   GEOCHRON* Date = &TSSForm->GeochronList->Dates[i];
	   if (Date->AnalUnit.IsEmpty()) {
		 msg = L"For multi site or multi collection unit datasets, ";
		 msg += L"geochron samples must be assigned to analysis units in the spreadsheet.";
		 OutputError(L"ERROR: " + msg);
		 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 return false;
		 }
	   }
	 }

   // investigators
   if (TSSForm->GeochronDataset.Investigators.size() > 0) {
	 for (unsigned int i=0; i<TSSForm->GeochronDataset.Investigators.size(); i++) {
	   OutputLine(L"Geochronology dataset investigator «" +
		 TSSForm->GeochronDataset.Investigators[i]->FullContactName + L"»: ID = " +
		 IntToStr(TSSForm->GeochronDataset.Investigators[i]->NeotomaContactID) + L".");
	   }
	 }
   else {
	 msg = L"No investigators are assigned to geochronology dataset.";
	 OutputError(L"ERROR: " + msg);
	 if (MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbIgnore << mbAbort, 0) == mrAbort)
	   return false;
	 }

   NeotomaGeochronTypesTable GeochronTypes(ipsJSONS1, TcpClient1);
   StatusBar1->SimpleText = GeochronTypes.WebServiceName();
   if (!GeochronTypes.Execute())
	 return false;

   if (NeotomaAgeTypes.size() == 0) {
	 NeotomaAgeTypesTable AgeTypes(ipsJSONS1, TcpClient1);
	 StatusBar1->SimpleText = AgeTypes.WebServiceName();
	 if (AgeTypes.Execute())
	   NeotomaAgeTypes = AgeTypes.Items;
	 else
	   return false;
	 }

   int errors = 0;
   int new_errors = 0;
   int warnings;

   // assign TempGeochronIDs;
   for (int i=0; i<gcount; i++) {
	 GEOCHRON* Date = &TSSForm->GeochronList->Dates[i];
	 NEOTOMAGEOCHRON NeotomaGeochron;
	 NeotomaGeochron.TiliaID = Date->ID;
	 NeotomaGeochron.GeochronID = NextTempGeochronID();
	 NeotomaGeochrons.push_back(NeotomaGeochron);
	 }

   // validate age exists
   for (int i=0; i<gcount; i++) {
	 GEOCHRON* Date = &TSSForm->GeochronList->Dates[i];
	 if (Date->Age.IsEmpty()) {
	   if (!Date->GreaterThan) {
		 msg = L"Age missing for geochronologic date.";
		 OutputError(L"ERROR: " + msg);
		 if (MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbIgnore << mbAbort, 0) == mrAbort)
		   return false;
		 else {
		   OutputError(L"ERROR: Remaining geochronology validation skipped.");
		   return true;
		   }
		 }
	   else {
		 OutputWarning(L"WARNING: Geochronologic date " + DateDescript(Date) +
		   L" is marked as «greater than». Infinite dates are permissible, but are usually indated as > some minimum age.");
		 }
	   }
	 else
	   NeotomaGeochrons[i].Age = Date->Age;
	 }
   OutputLine(L"Geochronology ages validated.");

   // check for lab numbers
   warnings = 0;
   for (int i=0; i<gcount; i++) {
	 GEOCHRON* Date = &TSSForm->GeochronList->Dates[i];
	 if (!Date->LabNumber.IsEmpty())
	   NeotomaGeochrons[i].LabNumber = Date->LabNumber;
	 else {
	   OutputWarning(L"WARNING: No lab number for geochronologic date " +
		 DateDescript(Date) + L".");
	   warnings++;
	   }
	 }
   if (warnings == 0)
	 OutputLine(L"Geochronology lab numbers validated.");
   else
	 OutputLine(L"Geochronology lab numbers validated, but warnings exist.");

   // validate geochronologic methods
   for (int i=0; i<gcount; i++) {
	 GEOCHRON* Date = &TSSForm->GeochronList->Dates[i];
	 int GeochronTypeID = FindGeochronType(Date->Method, GeochronTypes.Items);
	 if (GeochronTypeID != -1) {
	   NeotomaGeochrons[i].GeochronTypeID = GeochronTypeID;
	   UnicodeString method = Date->Method.LowerCase();
	   if (DatasetGeochronTypes.count(method) == 0)
		 DatasetGeochronTypes.insert(method);
	   }
	 else {
	   msg = L"ERROR: Geochronology Method «" + Date->Method + L"» in date " +
		 DateDescript(Date) + L" not valid.";
	   OutputError(msg);
	   errors++;
	   }
	 }
   if (errors == 0)
	 OutputLine(L"Geochronology methods validated.");

   // validate age units
   for (int i=0; i<gcount; i++) {
	 GEOCHRON* Date = &TSSForm->GeochronList->Dates[i];
	 int AgeTypeID = FindAgeType(Date->AgeUnits, NeotomaAgeTypes);
	 if (AgeTypeID != -1) {
	   bool agetype_error = false;
	   if (ContainsText(Date->AgeUnits, L"calibrated")) {
		 msg = L"ERROR: Geochronologic method «" + Date->Method + L"» in date " +
		   DateDescript(Date) + " cannot be assigned calibrated radiocarbon age units.";
		 OutputError(msg);
		 agetype_error = true;
		 }
	   else if (ContainsText(Date->Method, L"Carbon-14") || ContainsText(Date->Method, L"Radiocarbon")) {
		 if (!SameText(Date->AgeUnits, L"Radiocarbon years BP")) {
		   msg = L"ERROR: Geochronologic method «" + Date->Method +
			 "» for date " + DateDescript(Date) + " must be assigned «Radiocarbon years BP» age units.";
		   OutputError(msg);
		   agetype_error = true;
		   }
		 }
	   else if (!ContainsText(Date->AgeUnits, L"Calendar")) {
		 msg = L"ERROR: Geochronologic method «" + Date->Method +
		   L"» for date " + DateDescript(Date) + " must be assigned age units in calendar years.";
		 OutputError(msg);
		 agetype_error = true;
		 }
	   if (!agetype_error)
		 NeotomaGeochrons[i].AgeTypeID = AgeTypeID;
	   else
		 new_errors++;
	   }
	 else {
	   msg = L"ERROR: Geochronology Age Units «" + Date->AgeUnits + L"» for date " +
		 DateDescript(Date) + L" not valid.";
	   OutputError(msg);
	   new_errors++;
	   }
	 }
   if (new_errors == 0)
	 OutputLine(L"Geochronology age units validated.");
   else
	 errors += new_errors;

   // see if dates are assigned to analysis units or depths
   int ndepths = 0;
   int nanalunits = 0;
   for (int i=0; i<gcount; i++) {
	 GEOCHRON* Date = &TSSForm->GeochronList->Dates[i];
	 if (!Date->Depth.IsEmpty())
	   ndepths++;
	 if (!Date->AnalUnit.IsEmpty())
	   nanalunits++;
	 }
   if (ndepths != gcount && nanalunits != gcount) {
	 msg = L"Not all geochronology dates assigned to depth or analysis unit.";
	 OutputError(L"ERROR: " + msg);
	 if (MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbIgnore << mbAbort, 0) == mrAbort)
	   return false;
	 else {
	   OutputError(L"ERROR: Remaining geochronology validation skipped.");
	   return true;
	   }
	 }

   // if cxRadioButton5->Checked, validate analysis units by depth
   // Assign dates either an existing TempAnalysisUnitID or a new one
   // if (TSSForm->cxRadioButton5->Checked) [
   if (ndepths == gcount && nanalunits != gcount) {
	 // if dataset has multi sites or collection units, then geochrons must be
	 // assigned to analysis units, not depths.
	 int TempCollUnitID;
	 msg = L"";
	 if (TSSForm->Sites->Count > 1)
	   msg = L"For multisite datasets, geochronologic dates must be assigned to analysis units.";
	 else {
	   site_ptr = (SITE*)TSSForm->Sites->Items[0];
	   if (site_ptr->CollUnits.size() > 1)
		 msg = L"For multi collection unit datasets, geochronologic dates must be assigned to analysis units.";
	   else
		 TempCollUnitID = site_ptr->CollUnits[0].NeotomaCollUnitID;
	   }

	 if (!msg.IsEmpty()) {
	   OutputError(L"ERROR: " + msg);
	   if (MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbIgnore << mbAbort, 0) == mrAbort)
		 return false;
	   else {
		 OutputError(L"ERROR: Remaining geochronology validation skipped.");
		 return true;
		 }
	   }

	 int depth_errors = 0;
	 warnings = 0;
	 // check that geochrons have depths and thicknesses
	 for (int i=0; i<gcount; i++) {
	   GEOCHRON* Date = &TSSForm->GeochronList->Dates[i];
	   if (!Date->Depth.IsEmpty())
		 NeotomaGeochrons[i].Depth = Date->Depth;
	   else {
		 OutputError(L"ERROR: Geochronologic date " + DateDescript(Date) + L" has no depth.");
		 depth_errors++;
		 }
	   if (!Date->Thickness.IsEmpty())
		 NeotomaGeochrons[i].Thickness = Date->Thickness;
	   else {
		 OutputWarning(L"WARNING: Geochronologic date " + DateDescript(Date) + L" has no thickness.");
		 warnings++;
		 }
	   }
	 if (depth_errors == 0) {
	   if (warnings == 0)
		 OutputLine(L"Geochronology depths and thicknesses validated.");
	   else
		 OutputLine(L"Geochronology depths and thicknesses validated, but warnings exist.");
	   }
	 else
	   errors += depth_errors;

	 // vector<NEOTOMAANALUNIT> TiliaAnalysisUnits;
	 // vector<NEOTOMAANALUNIT>* tilAnalUnits
	 // (*TilAnalUnits)[*idxptr].AnalysisUnitID = AdvColumnGrid1->Cells[7][row].ToInt();
	 // NeotomaAnalysisUnits.insert(NeotomaAnalysisUnits.end(), TiliaAnalysisUnits.begin(), TiliaAnalysisUnits.end());

	 warnings = 0;
	 if (depth_errors == 0) {
	   // check for analysis units the same as those in the spreadsheet. Also check for
	   // ones with the same depths, but thicknesses not given
	   // vector<GEOCHRONANALUNIT> EPDGeochronAnalUnits;

	   if (TSSForm->EPD.SiteID > -1) {  // legacy EPD data
		 if (TSSForm->EPD.Datasets.count(1) == 1) {
		   NeotomaGetGeochronAnalysisUnitByDatasetID GeochronAnalUnits(ipsJSONS1, TcpClient1);
		   GeochronAnalUnits.AddParam(L"DATASETID", TSSForm->EPD.Datasets[1]);
		   StatusBar1->SimpleText = GeochronAnalUnits.WebServiceName();
		   if (!GeochronAnalUnits.Execute()) {
			 OutputError(L"ERROR: Servcie GetGeochronAnalysisUnitByDatasetID failed.");
			 return false;
			 }
           for (unsigned int i=0; i<NeotomaGeochrons.size(); i++) {
			 // GEOCHRON* Date = &TSSForm->GeochronList->Dates[i];
			 bool found = false;
			 for (unsigned int j=0; j<GeochronAnalUnits.Size(); j++) {
			   if (NeotomaGeochrons[i].Depth == GeochronAnalUnits.Items[j].Depth) {
				 if (NeotomaGeochrons[i].Thickness.IsEmpty() && GeochronAnalUnits.Items[j].Thickness.IsEmpty())
				   found = true;
				 else if (!NeotomaGeochrons[i].Thickness.IsEmpty() && !GeochronAnalUnits.Items[j].Thickness.IsEmpty()) {
				   if (NeotomaGeochrons[i].Thickness == GeochronAnalUnits.Items[j].Thickness)
					 found = true;
				   }
				 else if (!NeotomaGeochrons[i].Thickness.IsEmpty() && GeochronAnalUnits.Items[j].Thickness.IsEmpty())
				   found = true;
				 }
			   if (found) {
				 NeotomaGeochrons[i].AnalysisUnitID = GeochronAnalUnits.Items[j].AnalysisUnitID;
				 NEOTOMAANALUNIT AnalUnit;
				 AnalUnit.AnalysisUnitID = GeochronAnalUnits.Items[j].AnalysisUnitID;
				 AnalUnit.CollectionUnitID = GeochronAnalUnits.Items[j].CollectionUnitID;
				 AnalUnit.Depth = GeochronAnalUnits.Items[j].Depth;
				 AnalUnit.Thickness = NeotomaGeochrons[i].Thickness;
				 NeotomaAnalysisUnits.push_back(AnalUnit);

				 msg = L"Geochron date at depth " + FloatToStr((double)AnalUnit.Depth);
				 if (!AnalUnit.Thickness.IsEmpty())
				   msg += (L", thickness " + FloatToStr((double)AnalUnit.Thickness));
				 msg += (L" matched with AnalysisUnitID " + IntToStr(AnalUnit.AnalysisUnitID) + L".");
				 OutputLine(msg);
                 break;
				 }
			   }
			 }
		   }
		 }

	   for (unsigned int i=0; i<NeotomaGeochrons.size(); i++) {
		 GEOCHRON* Date = &TSSForm->GeochronList->Dates[i];  // still needed for output
		 bool depthfound = false;
		 for (unsigned int j=0; j<NeotomaAnalysisUnits.size(); j++) {
		   if (NeotomaGeochrons[i].Depth == NeotomaAnalysisUnits[j].Depth) {
			 depthfound = true;
			 // check if depth and thickness match
			 if (!NeotomaGeochrons[i].Thickness.IsEmpty() && !NeotomaAnalysisUnits[j].Thickness.IsEmpty()) {
			   if (NeotomaGeochrons[i].Thickness == NeotomaAnalysisUnits[j].Thickness)
				 NeotomaGeochrons[i].AnalysisUnitID = NeotomaAnalysisUnits[j].AnalysisUnitID;
			   }
			 if (NeotomaGeochrons[i].AnalysisUnitID == -1) {
			   NeotomaGeochrons[i].AnalysisUnitID = NextTempAnalUnitID();
			   NEOTOMAANALUNIT AnalUnit;
			   AnalUnit.AnalysisUnitID = NeotomaGeochrons[i].AnalysisUnitID;
			   AnalUnit.CollectionUnitID = TempCollUnitID;
			   AnalUnit.Depth = NeotomaGeochrons[i].Depth;
			   AnalUnit.Thickness = NeotomaGeochrons[i].Thickness;
			   NeotomaAnalysisUnits.push_back(AnalUnit);

			   if (NeotomaGeochrons[i].Thickness.IsEmpty() && !NeotomaAnalysisUnits[j].Thickness.IsEmpty()) {
				 msg = L"WARNING: Geochronologic date " + DateDescript(Date) +
				   L" has the same depth as an analysis unit in the spreadsheet, ";
				 msg += L"but the date has no thickness, so is assigned to a different analysis unit.";
				 OutputWarning(msg);
				 warnings++;
				 }
			   else if (!NeotomaGeochrons[i].Thickness.IsEmpty() && NeotomaAnalysisUnits[j].Thickness.IsEmpty()) {
				 msg = L"WARNING: Geochronologic date " + DateDescript(Date) +
				   L" has the same depth as an analysis unit in the spreadsheet, ";
				 msg += L"but the analysis unit has no thickness, so date is assigned to a different analysis unit.";
				 OutputWarning(msg);
				 warnings++;
				 }
			   else if (NeotomaGeochrons[i].Thickness.IsEmpty() && NeotomaAnalysisUnits[j].Thickness.IsEmpty()) {
				 msg = L"WARNING: Geochronologic date " + DateDescript(Date) +
				   L" has the same depth as an analysis unit in the spreadsheet, ";
				 msg += L"but the analysis unit and date have no thickness values assigned, ";
				 msg += L"so are assigned to a different analysis units.";
				 OutputWarning(msg);
				 warnings++;
				 }
			   }
			 break;
			 }
		   }
		 if (!depthfound) {
		   NeotomaGeochrons[i].AnalysisUnitID = NextTempAnalUnitID();
		   NEOTOMAANALUNIT AnalUnit;
		   AnalUnit.AnalysisUnitID = NeotomaGeochrons[i].AnalysisUnitID;
		   AnalUnit.CollectionUnitID = TempCollUnitID;
		   AnalUnit.Depth = NeotomaGeochrons[i].Depth;
		   AnalUnit.Thickness = NeotomaGeochrons[i].Thickness;
		   NeotomaAnalysisUnits.push_back(AnalUnit);
		   }
		 OutputLine(L"Depth " + FloatToStr((double)NeotomaGeochrons[i].Depth) +     // this for testing
			L", CollUnitID = " + IntToStr(TempCollUnitID) +
			L", Geochron AnalysisUnitID = " + IntToStr(NeotomaGeochrons[i].AnalysisUnitID));
		 }
	   if (warnings == 0)
		 OutputLine(L"Geochronology analysis units validated.");
	   else
		 OutputLine(L"Geochronology analysis units validated, but warnings exist.");
	   }
	 }
   else {  // geochrons assigned to analysis units
	 new_errors = 0;
	 for (int i=0; i<gcount; i++) {
	   GEOCHRON* Date = &TSSForm->GeochronList->Dates[i];
	   if (!Date->AnalUnit.IsEmpty()) {
		 // check that analysis unit is in spreadsheet
		 for (unsigned int j=0; j<NeotomaAnalysisUnits.size(); j++) {
		   if (SameText(Date->AnalUnit, NeotomaAnalysisUnits[j].AnalysisUnitName)) {
			 NeotomaGeochrons[i].AnalysisUnitID = NeotomaAnalysisUnits[j].AnalysisUnitID;
			 break;
			 }
		   }
		 if (NeotomaGeochrons[i].AnalysisUnitID == -1) {
		   msg = L"Analysis unit «" + Date->AnalUnit + L"» for geochronologic date "
			 + DateDescript(Date) + L" is not in the spreadsheet.";
		   OutputError(L"ERROR: " + msg);
		   if (MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbIgnore << mbAbort, 0) == mrAbort)
			 return false;
		   new_errors++;
		   }
		 }
	   else {
		 msg = L"No Analysis Unit name for geochronologic date " +  DateDescript(Date) + L".";
		 OutputError(L"ERROR: " + msg);
		 if (MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbIgnore << mbAbort, 0) == mrAbort)
		   return false;
		 new_errors++;
		 }
	   }
	 if (new_errors == 0)
	   OutputLine(L"Geochronology analysis units validated.");
	 }

   // check that age does falls between the ErrorOlder/ErrorYounger values
   warnings = 0;
   new_errors = 0;
   // check that ErrorOlder/ErrorYounger values exist
   for (int i=0; i<gcount; i++) {
	 GEOCHRON* Date = &TSSForm->GeochronList->Dates[i];
	 if (!Date->GreaterThan) {
	   if (Date->ErrorOlder.IsEmpty() && Date->ErrorYounger.IsEmpty()) {
		 msg = L"WARNING: No error values entered for geochronologic date " + DateDescript(Date) + L".";
		 OutputLine(msg);
		 warnings++;
		 }
	   else if (Date->ErrorOlder.IsEmpty()) {
		 msg = L"ERROR: AgeYounger value entered for geochronologic date " + DateDescript(Date) +
		   L", but not AgeOlder value.";
		 if (MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbIgnore << mbAbort, 0) == mrAbort)
		   return false;
		 new_errors++;
		 }
	   else if (Date->ErrorYounger.IsEmpty()) {
		 msg = L"ERROR: AgeOlder value entered for geochronologic date " + DateDescript(Date) +
		   L", but not AgeYounger value.";
		 if (MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbIgnore << mbAbort, 0) == mrAbort)
		   return false;
		 new_errors++;
		 }
	   else {
		 double sigma = Date->Sigma;
		 NeotomaGeochrons[i].ErrorOlder = (double)Date->ErrorOlder/sigma;
		 NeotomaGeochrons[i].ErrorYounger = (double)Date->ErrorYounger/sigma;
		 }
	   }
	 else if (!Date->ErrorOlder.IsEmpty() || !Date->ErrorYounger.IsEmpty()) {
	   msg = L"ERROR: Geochronologic date " + DateDescript(Date) +
		 L" has error values and is marked as a «greater than» date. ";
	   msg += L"«Greater than» dates cannot have error values.";
	   if (MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbIgnore << mbAbort, 0) == mrAbort)
		 return false;
	   new_errors++;
	   }
	 else
	   NeotomaGeochrons[i].GreaterThan = true;
	 }

   // check that error values are not limits
   if (new_errors == 0) {
	 for (int i=0; i<gcount; i++) {
	   GEOCHRON* Date = &TSSForm->GeochronList->Dates[i];
	   if ((Date->Age < Date->ErrorOlder && Date->Age > Date->ErrorYounger) ||
		   (Date->Age > Date->ErrorOlder && Date->Age < Date->ErrorYounger)) {  // even the order is wrong
		 msg = L"WARNING: Error values for geochronologic date " + DateDescript(Date) +
		   L" appear to be error limits rather than ± error values.";
		 OutputWarning(msg);
		 warnings++;
		 }
	   }
	 }
   if (new_errors == 0) {
	 if (warnings == 0)
	   OutputLine(L"Geochronology ErrorOlder/ErrorYounger values validated.");
	 else
	   OutputLine(L"Geochronology ErrorOlder/ErrorYounger values validated, but warnings exist.");
	 }

   // validate parameters
   new_errors = 0;
   warnings = 0;
   for (int i=0; i<gcount; i++) {
	 GEOCHRON* Date = &TSSForm->GeochronList->Dates[i];
	 // find GeochronTypeID
	 int GeochronTypeID = -1;
	 map<int,UnicodeString>::iterator itr;
	 for (itr = GeochronTypes.Items.begin(); itr != GeochronTypes.Items.end(); itr++) {
	   if (SameText(Date->Method, itr->second)) {
		 GeochronTypeID = itr->first;
		 break;
		 }
	   }

	 // if GeochronTypeID found, validate parameter
	 // get needed parameters
	 map<int,UnicodeString> RadiocarbonMethods;
	 if (DatasetGeochronTypes.count(L"carbon-14") > 0) {
	   NeotomaRadiocarbonMethodsTable Methods(ipsJSONS1, TcpClient1);
	   StatusBar1->SimpleText = Methods.WebServiceName();
	   if (Methods.Execute())
		 RadiocarbonMethods = Methods.Items;
	   else
		 return false;
	   }

	 if (GeochronTypeID > -1) {
	   if (Date->Parameters.size() > 0) {
		 map<UnicodeString,Variant>::iterator itr;
		 for (itr = Date->Parameters.begin(); itr != Date->Parameters.end(); itr++) {
		   if (SameText(Date->Method, L"Carbon-14")) {
			 if (SameText(itr->first, L"Method")) {
			   UnicodeString C14Method = VarToStr(itr->second);
			   bool found = false;
			   map<int,UnicodeString>::iterator rit;
			   for (rit = RadiocarbonMethods.begin(); rit != RadiocarbonMethods.end(); rit++) {
				 if (SameText(C14Method, rit->second)) {
				   NeotomaGeochrons[i].RadiocarbonParams[L"Method"] = rit->first;
				   found = true;
				   break;
				   }
				 }
			   if (!found) {
				 msg = L"ERROR: Radiocarbon method " + C14Method + L" for date " +
				   DateDescript(Date) + L" is not valid.";
				 OutputError(msg);
				 new_errors++;
				 }
			   }
			 else {
			   if (itr->second.Type() == varDouble) {
				 NeotomaGeochrons[i].RadiocarbonParams[itr->first] = itr->second;
				 if (SameText(itr->first, L"δ13C")) {
				   double Delta13C = itr->second;
				   if (Delta13C > 0) {
					 msg = L"WARNING: δ13C value for geochronologic date " + DateDescript(Date) +
					   L" is >0. Most δ13C values are negative.";
					 OutputWarning(msg);
					 warnings++;
					 }
				   }
				 }
			   else {
				 msg = L"ERROR: Radiocarbon parameter value " + VarToStr(itr->second.Type()) +
				   L" for date " + DateDescript(Date) + L" is not a floating point number.";
				 OutputError(msg);
				 new_errors++;
				 }
			   }
			 }
		   }
		 }
	   }
	 else {
	   msg = L"ERROR: Geochron type " + Date->Method + L" for date " + DateDescript(Date) +
			 L" is not valid.";
	   OutputError(msg);
	   new_errors++;
	   }
	 }
   if (new_errors == 0) {
	 if (warnings == 0)
	   OutputLine(L"Geochronology validated.");
	 else
	   OutputLine(L"Geochronology validated, but warnings exist.");
	 }

   // validate material dated
   warnings = 0;
   for (int i=0; i<gcount; i++) {
	 GEOCHRON* Date = &TSSForm->GeochronList->Dates[i];
	 if (Date->MaterialDated.IsEmpty()) {
	   msg = L"WARNING: No material dated for geochronologic date " + DateDescript(Date) + L".";
	   OutputWarning(msg);
	   warnings++;
	   }
	 else
	   NeotomaGeochrons[i].MaterialDated = Date->MaterialDated;
	 }
   if (warnings == 0)
	 OutputLine(L"Geochronology material dated validated.");
   else
	 OutputLine(L"Geochronology material dated validated, but warnings exist.");

   // get notes
   for (int i=0; i<gcount; i++) {
	 GEOCHRON* Date = &TSSForm->GeochronList->Dates[i];
	 if (!Date->Notes.IsEmpty())
	   NeotomaGeochrons[i].Notes = Date->Notes;
	 }

   // get publications
   warnings = 0;
   for (int i=0; i<gcount; i++) {
	 GEOCHRON* Date = &TSSForm->GeochronList->Dates[i];
	 if (Date->publications.size() > 0) {
	   for (unsigned int j=0; j<Date->publications.size(); j++) {
		 int PubID = Date->publications[j]->NeotomaID;
		 NeotomaGeochrons[i].PublicationIDs.push_back(PubID);
		 OutputLine(L"Geochronology PublicationID = " + IntToStr(PubID));
		 }
	   }
	 else {
	   msg = L"WARNING: No publications for geochronologic date " + DateDescript(Date) + L".";
	   OutputWarning(msg);
	   warnings++;
	   }
	 }
   if (warnings == 0)
	 OutputLine(L"Geochronology publications validated.");
   else
	 OutputLine(L"Geochronology publications validated, but warnings exist.");


   NeotomaCalibrationCurvesTable CalibCurves(ipsJSONS1, TcpClient1);
   StatusBar1->SimpleText = CalibCurves.WebServiceName();
   if (!CalibCurves.Execute())
	  return false;

   NeotomaCalibrationProgramsTable CalibPrograms(ipsJSONS1, TcpClient1);
   StatusBar1->SimpleText = CalibPrograms.WebServiceName();
   if (!CalibPrograms.Execute())
	 return false;

   StatusBar1->SimpleText = L"";
   int CalCurveID = -1;
   int CalProgID = -1;

   // validate specimen dates
   // first get vector of all taxa dated (NeotomaTaxaDated)
   new_errors = 0;
   bool missing_data = false;
   int rv = mrNo;
   for (int i=0; i<gcount; i++) {
	 GEOCHRON* Date = &TSSForm->GeochronList->Dates[i];
	 if (Date->Age.IsEmpty() || (!Date->GreaterThan && (Date->ErrorOlder.IsEmpty() || Date->ErrorYounger.IsEmpty()))) {
	   msg = L"Age or error limits are missing for " + DateDescript(Date) +
		 L" from anaysis unit «" + AnalysisUnitDescript(NeotomaGeochrons[i].AnalysisUnitID) + L"».";
	   if (Date->TaxaDated.size() > 1)
		 msg += L" Data not sufficient for taxon date.";
	   OutputWarning(L"WARNING: " + msg);
	   missing_data = true;
	   }
	 if (missing_data) continue;

	 bool calibrated = false;
	 bool finite_C14_date = (!Date->GreaterThan &&
		  (ContainsText(Date->Method, L"Carbon-14") || ContainsText(Date->Method, L"radiocarbon")));
	 if (finite_C14_date && Date->TaxaDated.size() > 0) {
	   // calibrate date
	   bool calibrate = false;
	   for (unsigned int j=0; j<Date->TaxaDated.size(); j++) {
		 if (Date->TaxaDated[j].CalAgeOlder.IsEmpty() && Date->TaxaDated[j].CalAgeYounger.IsEmpty())
		   calibrate = true;
		 else {
		   NeotomaGeochrons[i].CalAge = Date->TaxaDated[j].CalAgeMedian;
		   NeotomaGeochrons[i].CalAgeYounger = Date->TaxaDated[j].CalAgeYounger;
		   NeotomaGeochrons[i].CalAgeOlder = Date->TaxaDated[j].CalAgeOlder;
		   }
		 }

	   OXCAL OxCal(ipsJSONS1, TcpClient1);
	   pair<double,double> ConfLimits;
	   int iAge;
	   int iError;
	   UnicodeString CalibCurveStr;
	   UnicodeString Program;
	   UnicodeString Version;

	   if (calibrate) {
		 double latitude = GetSiteLatitude(NeotomaGeochrons[i].AnalysisUnitID);
		 CalibCurveStr = (latitude >= 0.0) ? L"IntCal13" : L"SHCal13";
		 msg = L"Radiocarbon date " + DateDescript(Date) +
			   L" on individual taxon has not been calibrated.\nCalibrate with OxCal using the " +
			   CalibCurveStr + L" calibration curve?";
		 if (rv != mrYesToAll)
		   rv = MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbYesToAll << mbNo, 0);
		 if (rv == mrYes || rv == mrYesToAll) {
		   iAge = (int)Date->Age;
		   iError;
		   if (Date->ErrorYounger == Date->ErrorOlder)
			 iError = (int)Date->ErrorYounger;
		   else
			 iError = (int)Max((double)Date->ErrorYounger, (double)Date->ErrorOlder);

		   vector<CALIBDATE> CalibDates;
		   CALIBDATE CalibDate;

           if (!Date->LabNumber.IsEmpty())
			 CalibDate.LabNumber = Date->LabNumber;
		   else
			 CalibDate.LabNumber = L"Dummy";

		   CalibDate.Age = iAge;
		   CalibDate.SD = iError;

		   map<UnicodeString,Variant>::iterator itr = Date->Parameters.find(L"Reservoir (yrs)");
		   if (itr != Date->Parameters.end()) {
			 int iReservoir = (int)VariantToDouble(itr->second, 0);
			 if (iReservoir > 0)
			   CalibDate.Age -= iReservoir;
			 }
		   CalibDates.push_back(CalibDate);

		   if (OxCal.Calibrate(CalibCurveStr,CalibDates)) {
			 NeotomaGeochrons[i].CalAge = OxCal.ConvertAge(CalibDates[0].Median,1);
			 NeotomaGeochrons[i].CalAgeYounger = OxCal.ConvertAge(CalibDates[0].Ranges.back().Younger,1);
			 NeotomaGeochrons[i].CalAgeOlder = OxCal.ConvertAge(CalibDates[0].Ranges[0].Older,1);

			 Program = CalibDates[0].ProgramVersion;
			 // OxCal v4.2.4 Bronk Ramsey (2013); r:5
			 int pos = Program.Pos(L"v");
			 if (pos > 1) {
			   Program.Delete(1,pos);
			   pos = Program.Pos(L" ");
			   if (pos > 1)
				 Version = Program.SubString(1,pos-1);
			   }
			 Program = L"OxCal";
			 calibrated = true;
			 }
		   }
		 else {
		   msg = L"WARNING: Radiocarbon date " + DateDescript(Date) +
				 L" on individual taxa has not been calibrated.";
		   OutputWarning(msg);
		   }
		 }

	   for (unsigned int j=0; j<Date->TaxaDated.size(); j++) {
		 NEOTOMATAXONDATE NeotomaTaxonDate(NeotomaGeochrons[i].GeochronID,
		   Date->TaxaDated[j], Date->publications, DateDescript(Date));
		 if (Date->TaxaDated[j].CalAgeOlder.IsEmpty() && Date->TaxaDated[j].CalAgeYounger.IsEmpty()) {
		   if (calibrated && new_errors == 0) {
			 Date->TaxaDated[j].CalAgeMedian = NeotomaGeochrons[i].CalAge;
			 Date->TaxaDated[j].CalAgeYounger = NeotomaGeochrons[i].CalAgeYounger;
			 Date->TaxaDated[j].CalAgeOlder = NeotomaGeochrons[i].CalAgeOlder;
			 Date->TaxaDated[j].CalibCurve = CalibCurveStr;
			 Date->TaxaDated[j].Calib.Program = Program;
			 Date->TaxaDated[j].Calib.Version = Version;

			 msg = L"Specimen age " + IntToStr(iAge) + L"±" + IntToStr(iError) +
			   L" 14C yr BP for «" + Date->TaxaDated[j].Taxon;
			 if (!Date->TaxaDated[j].Element.IsEmpty())
			   msg += (L" " + Date->TaxaDated[j].Element);
			 msg += (L"» in analysis unit «" + AnalysisUnitDescript(NeotomaGeochrons[i].AnalysisUnitID));
			 msg += (L"». cal age: 2σ range " + VarToStr(NeotomaGeochrons[i].CalAgeYounger) + L"-" +
					VarToStr(NeotomaGeochrons[i].CalAgeOlder));
			 msg += (L", median = " + VarToStr(NeotomaGeochrons[i].CalAge));
			 msg += (L"; Calibration program: " + Program + L" " + Version);
			 msg += (L"; Calibration Curve: " + CalibCurveStr + L".");
			 OutputLine(msg);

			 if (CalCurveID == -1) {
			   for (unsigned int j=0; j<CalibCurves.Size(); j++) {
				 if (SameText(CalibCurves.Items[j].CalibrationCurve, CalibCurveStr)) {
				   CalCurveID = CalibCurves.Items[j].CalibrationCurveID;
				   break;
				   }
				 }
			   }
			 if (CalProgID == -1) {
			   for (unsigned int j=0; j<CalibPrograms.Size(); j++) {
				 if (SameText(CalibPrograms.Items[j].CalibrationProgram, Program) &&
					 SameText(CalibPrograms.Items[j].Version, Version)) {
				   CalProgID = CalibPrograms.Items[j].CalibrationProgramID;
				   break;
				   }
				 }
			   }
			 if (CalProgID == -1) {
			   msg = L"Calibration program " + Program + L" " + Version +
					 L" is not in the Neotoma CalibrationPrograms table.";
			   OutputError(L"ERROR: " + msg);
			   NeotomaTaxaDated.clear();
			   new_errors++;
			   if (MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbIgnore << mbAbort, 0) == mrAbort)
				 return false;
			   }
			 else {
			   NeotomaTaxonDate.Cal.Age = NeotomaGeochrons[i].CalAge;
			   NeotomaTaxonDate.Cal.AgeYounger = NeotomaGeochrons[i].CalAgeYounger;
			   NeotomaTaxonDate.Cal.AgeOlder = NeotomaGeochrons[i].CalAgeOlder;
			   NeotomaTaxonDate.Cal.CurveID = CalCurveID;
			   NeotomaTaxonDate.Cal.ProgramID = CalProgID;
			   NeotomaTaxonDate.Cal.Date = UTCDateTime();
			   }
			 }
		   }  // end not calibrated
		 else {
		   if (Date->TaxaDated[j].CalAgeOlder < Date->TaxaDated[j].CalAgeYounger) {
			 msg = L"ERROR: Cal Age Older and Cal Age Younger are reversed for taxon «" +
				   Date->TaxaDated[j].Taxon + L"» for geochronologic date " + DateDescript(Date) + L".";
			 OutputError(msg);
			 NeotomaTaxaDated.clear();
			 new_errors++;
			 }
		   else if (Date->TaxaDated[j].CalibCurve.IsEmpty() || Date->TaxaDated[j].Calib.Program.IsEmpty()) {
			 msg = L"WARNING: Calibration curve or calibration program not entered for directly dated taxon «" +
				   Date->TaxaDated[j].Taxon + L"» for geochronologic date " + DateDescript(Date) + L".";
			 OutputWarning(msg);
			 }
		   if (new_errors == 0) {
			 int CalCurveID = -1;
			 for (unsigned int k=0; k<CalibCurves.Size(); k++) {
			   if (SameText(CalibCurves.Items[k].CalibrationCurve, Date->TaxaDated[j].CalibCurve)) {
				 CalCurveID = CalibCurves.Items[k].CalibrationCurveID;
				 break;
				 }
			   }
			 if (CalCurveID == -1) {
			   msg = L"Calibration curve «" + Date->TaxaDated[j].CalibCurve +
				 L"» for " + DateDescript(Date) +
				 L" taxa dated is not in the Neotoma CalibrationCurves table.";
			   OutputError(L"ERROR: " + msg);
			   if (MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbIgnore << mbAbort, 0) == mrAbort)
				 return false;
			   }

			 int CalProgID = -1;
			 for (unsigned int k=0; k<CalibPrograms.Size(); k++) {
			   if (SameText(CalibPrograms.Items[k].CalibrationProgram, Date->TaxaDated[j].Calib.Program) &&
				   SameText(CalibPrograms.Items[k].Version, Date->TaxaDated[j].Calib.Version)) {
				 CalProgID = CalibPrograms.Items[k].CalibrationProgramID;
				 break;
				 }
			   }
			 if (CalProgID == -1) {
			   msg = L"Calibration Program " + Date->TaxaDated[j].Calib.Program;
			   if (!Date->TaxaDated[j].Calib.Version.IsEmpty())
				 msg += (L" " + Date->TaxaDated[j].Calib.Version);
			   msg += (L" for " + DateDescript(Date));
			   msg += L" is not in the Neotoma CalibrationPrograms table.";
			   OutputError(L"ERROR: " + msg);
			   if (MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbIgnore << mbAbort, 0) == mrAbort)
				 return false;
			   }
			 NeotomaTaxonDate.Cal.Age = Date->TaxaDated[j].CalAgeMedian;
			 NeotomaTaxonDate.Cal.AgeYounger = Date->TaxaDated[j].CalAgeYounger;
			 NeotomaTaxonDate.Cal.AgeOlder = Date->TaxaDated[j].CalAgeOlder;
			 NeotomaTaxonDate.Cal.CurveID = CalCurveID;
			 NeotomaTaxonDate.Cal.ProgramID = CalProgID;
			 NeotomaTaxonDate.Cal.Date = UTCDateTime();
			 }
		   }
		 if (new_errors == 0) {
		   NeotomaTaxaDated.push_back(NeotomaTaxonDate);   // SampleIDs not yet set
		   }
		 }
	   }
	 }

   // now check that taxon name, element, and fraction exist and assign IDs
   if (NeotomaTaxaDated.size() > 0) {
	 vector<pair<UnicodeString,int> > Taxa;    // int value is the ID
	 vector<pair<UnicodeString,int> > ElementTypes;
	 vector<pair<UnicodeString,int> > Fractions;
	 // get vectors of all unique taxa, element types, and fractions, temporarily set IDs to -1
	 for (unsigned int i=0; i<NeotomaTaxaDated.size(); i++) {
	   if (!PairFirstExists(Taxa, NeotomaTaxaDated[i].Taxon))
		 Taxa.push_back(pair<UnicodeString,int>(NeotomaTaxaDated[i].Taxon, -1));
	   if (!NeotomaTaxaDated[i].ElementType.IsEmpty()) {
		 if (!PairFirstExists(ElementTypes, NeotomaTaxaDated[i].ElementType))
		   ElementTypes.push_back(pair<UnicodeString,int>(NeotomaTaxaDated[i].ElementType, -1));
		 }
	   if (!NeotomaTaxaDated[i].Fraction.IsEmpty()) {
		 if (!PairFirstExists(Fractions, NeotomaTaxaDated[i].Fraction))
		   Fractions.push_back(pair<UnicodeString,int>(NeotomaTaxaDated[i].Fraction, -1));
		 }
	   }

	 // validate taxa
	 UnicodeString ParamList =  Taxa[0].first;
	 if (Taxa.size() > 1) {
	   for (unsigned int i=1; i<Taxa.size(); i++)
		 ParamList += (L"$" + Taxa[i].first);
	   }
	 NeotomaTaxaByNameList NeotomaTaxa(ipsJSONS1, TcpClient1);
	 NeotomaTaxa.AddParam(L"TAXANAMES", ParamList);
	 StatusBar1->SimpleText = NeotomaTaxa.WebServiceName();
	 if (!NeotomaTaxa.Execute())
	   return false;

	 bool all_found = true;
	 // get TaxonIDs
	 for (unsigned int i=0; i<Taxa.size(); i++) {
	   for (unsigned int j=0; j<NeotomaTaxa.Items.size(); j++) {
		 if (SameText(Taxa[i].first, VarToStr(NeotomaTaxa.Items[j].TaxonName))) {
		   Taxa[i].second = NeotomaTaxa.Items[j].TaxonID;
		   break;
		   }
		 }
	   if (Taxa[i].second == -1) {
		 all_found = false;
		 msg = L"Taxon dated «" + Taxa[i].first + L"» in Geochronlogy tabsheet not in Neotoma.";
		 OutputError(L"ERROR: " + msg);
		 if (MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbIgnore << mbAbort, 0) == mrAbort)
		   return false;
		 }
	   }

	 // get ElementTypeIDs
	 if (ElementTypes.size() > 0) {
	   ParamList =  ElementTypes[0].first;
	   if (ElementTypes.size() > 1) {
		 for (unsigned int i=1; i<ElementTypes.size(); i++)
		   ParamList += (L"$" + ElementTypes[i].first);
		 }
	   NeotomaElementTypesByNameList NeotomaElementTypes(ipsJSONS1, TcpClient1);
	   NeotomaElementTypes.AddParam(L"ELEMENTTYPES", ParamList);
	   StatusBar1->SimpleText = NeotomaElementTypes.WebServiceName();
	   if (!NeotomaElementTypes.Execute())
		 return false;

	   map<int, UnicodeString>::iterator itr;
	   for (unsigned int i=0; i<ElementTypes.size(); i++) {
		 for (itr = NeotomaElementTypes.Items.begin(); itr != NeotomaElementTypes.Items.end(); itr++) {
		   if (SameText(ElementTypes[i].first, itr->second)) {
			 ElementTypes[i].second = itr->first;
			 break;
			 }
		   }
		 if (ElementTypes[i].second == -1) {
		   all_found = false;
		   msg = L"Element type «" + ElementTypes[i].first + L"» of taxon dated in Geochronlogy tabsheet not in Neotoma.";
		   OutputError(L"ERROR: " + msg);
		   if (MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbIgnore << mbAbort, 0) == mrAbort)
			 return false;
		   }
		 }
	   }

	 // get FractionIDs
	 if (Fractions.size() > 0) {
	   ParamList =  Fractions[0].first;
	   if (Fractions.size() > 1) {
		 for (unsigned int i=1; i<Fractions.size(); i++)
		   ParamList += (L"$" + Fractions[i].first);
		 }
	   NeotomaFractionsDatedByList NeotomaFractions(ipsJSONS1, TcpClient1);
	   NeotomaFractions.AddParam(L"FRACTIONS", ParamList);
	   StatusBar1->SimpleText = NeotomaFractions.WebServiceName();
	   if (!NeotomaFractions.Execute())
		 return false;

	   map<int, UnicodeString>::iterator itr;
	   for (unsigned int i=0; i<Fractions.size(); i++) {
		 for (itr = NeotomaFractions.Items.begin(); itr != NeotomaFractions.Items.end(); itr++) {
		   if (SameText(Fractions[i].first, itr->second)) {
			 Fractions[i].second = itr->first;
			 break;
			 }
		   }
		 if (Fractions[i].second == -1) {
		   all_found = false;
		   msg = L"Fraction «" + Fractions[i].first + L"» of taxon dated in Geochronlogy tabsheet not in Neotoma.";
		   OutputError(L"ERROR: " + msg);
		   if (MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbIgnore << mbAbort, 0) == mrAbort)
			 return false;
		   }
		 }
	   }

	 // ------------------------------
	 for (unsigned int i=0; i<NeotomaTaxaDated.size(); i++) {
	   NeotomaTaxaDated[i].NeotomaTaxonID = FindPairSecond(Taxa, NeotomaTaxaDated[i].Taxon);
	   for (unsigned int j=0; j<NeotomaTaxa.Size(); j++) {       // get TaxaGroupID
		 if (NeotomaTaxaDated[i].NeotomaTaxonID == NeotomaTaxa.Items[j].TaxonID) {
		   NeotomaTaxaDated[i].TaxaGroupID = NeotomaTaxa.Items[j].TaxaGroupID;
		   break;
		   }
		 }
	   NeotomaTaxaDated[i].NeotomaElementTypeID = FindPairSecond(ElementTypes, NeotomaTaxaDated[i].ElementType);
	   NeotomaTaxaDated[i].NeotomaFractionID = FindPairSecond(Fractions, NeotomaTaxaDated[i].Fraction);
	   }
	 OutputLine(L"Taxon dates validated.");
	 // ------------------------------

	 // if all taxa, element types, and fractions found, add a new plant macrofossil
	 // dataset if necessary.

	 bool make_macro_dataset = all_found;
	 bool add_to_existing = false;
	 // can only do if only 1 site with 1 collection unit

	 if (make_macro_dataset) {
	   if (TSSForm->Sites->Count != 1)
		 make_macro_dataset = false;
	   else {
		 if (TSSForm->Sites->Count > 1)
		   make_macro_dataset = false;
		 else {
		   SITE* s_ptr = (SITE*)TSSForm->Sites->Items[0];
		   if (s_ptr->CollUnits.size() != 1) {
			 make_macro_dataset = false;
			 add_to_existing = true;
			 }
		   }
		 }
	   }

	 if (add_to_existing) { // assign SampleID for existing dataset
	   for (unsigned int i=0; i<NeotomaTaxaDated.size(); i++) {
		 UnicodeString TaxaGroupID = NeotomaTaxaDated[i].TaxaGroupID;
		 int SpecimenDatasetTypeID = TaxaGroupDatasetTypes.GetDatasetTypeID(TaxaGroupID);
		 if (SpecimenDatasetTypeID == -1) {
		   msg = L"ERROR: Specimen dates for TaxaGroup " + TaxaGroupID + L" are not currently accommodated.";
		   OutputError(msg);
		   return false;
		   }

		 vector<NEOTOMAGEOCHRON>::pointer gptr = GetNeotomaGeochron(NeotomaTaxaDated[i].GeochronID);
		 bool found = false;
		 for (unsigned int j=0; j<NeotomaSamples.size(); j++) {
		   if (NeotomaSamples[j].AnalysisUnitID == gptr->AnalysisUnitID) {
			 if (NeotomaSamples[j].DatasetTypeID == SpecimenDatasetTypeID) {
			   NeotomaTaxaDated[i].SampleID = NeotomaSamples[j].SampleID;
			   found = true;
			   }
			 }
		   }
		 if (!found) {  // probably should never happen, but...
		   msg = L"ERROR: An Analysis Unit with the same Dataset Type as dated specimen «" +
				 NeotomaTaxaDated[i].Taxon + L"» does not exist in spreadsheet.";
		   OutputError(msg);
		   return false;
		   }
		 }
	   }

	 if (make_macro_dataset) {
	   // get set of TaxaGroupIDS for taxon dates
	   set<UnicodeString> TaxaGroupIDs;
	   for (unsigned int i=0; i<NeotomaTaxa.Size(); i++) {
		 if (TaxaGroupIDs.count(NeotomaTaxa.Items[i].TaxaGroupID) == 0)
		   TaxaGroupIDs.insert(NeotomaTaxa.Items[i].TaxaGroupID);
		 }

	   // Add a new Plant Macrofossil dataset if necessary
	   if (TaxaGroupIDs.count(L"VPL") > 0 || TaxaGroupIDs.count(L"BRY") > 0) {  // check if any dated taxa are VPL or BRY
		 // get TaxaGroupIDs
		 for (unsigned int i=0; i<NeotomaTaxaDated.size(); i++) {
		   for (unsigned int j=0; j<NeotomaTaxa.Size(); j++) {
			 if (SameText(NeotomaTaxaDated[i].Taxon, NeotomaTaxa.Items[j].TaxonName)) {
			   NeotomaTaxaDated[i].TaxaGroupID = NeotomaTaxa.Items[j].TaxaGroupID;
			   break;
			   }
			 }
		   }

		 int PlantMacroDatasetID = -1;
		 for (unsigned int k=0; k<site_ptr->CollUnits[0].NeotomaDatasets.size(); k++) {
		   if (site_ptr->CollUnits[0].NeotomaDatasets[k].NeotomaDatasetTypeID == 4) {
			 PlantMacroDatasetID = site_ptr->CollUnits[0].NeotomaDatasets[k].NeotomaDatasetID;
			 break;
			 }
		   }

		 if (PlantMacroDatasetID != -1) {
		   map<int,int> GeochronAnalUnit;
		   for (unsigned int i=0; i<NeotomaGeochrons.size(); i++)
			 GeochronAnalUnit[NeotomaGeochrons[i].GeochronID] = NeotomaGeochrons[i].AnalysisUnitID;
		   map<int,int>	VariableTaxon;
		   map<int,NEOTOMAVARIABLE>::iterator itr;
		   for (itr = NeotomaVariables.begin(); itr != NeotomaVariables.end(); itr++)
			 VariableTaxon[itr->second.VariableID] = itr->second.TaxonID;

		   // get SampleID for taxon dated
		   for (unsigned int i=0; i<NeotomaTaxaDated.size(); i++) {
			 UnicodeString TaxaGroupID = NeotomaTaxaDated[i].TaxaGroupID;
			 int TaxonAnalUnit = GeochronAnalUnit[NeotomaTaxaDated[i].GeochronID];
			 if (SameText(TaxaGroupID, L"VPL") || SameText(TaxaGroupID, L"BRY")) {
			   // see if a macrofossil dataset sample has the same Analysis Unit as the dated taxon
			   for (unsigned int j=0; j<NeotomaSamples.size(); j++) {
				 if (NeotomaSamples[j].DatasetTypeID == 4 && NeotomaSamples[j].AnalysisUnitID == TaxonAnalUnit) {
				   NeotomaTaxaDated[i].SampleID = NeotomaSamples[j].SampleID;
				   // see if dated taxon occurs in existing sample
				   bool taxon_found = false;
				   for (unsigned int k=0; k<NeotomaSamples[j].data.size(); k++) {
					 int VariableID = NeotomaSamples[j].data[k].VariableID;
					 if (NeotomaTaxaDated[i].NeotomaTaxonID == VariableTaxon[VariableID]) {
					   taxon_found = true;
					   break;
					   }
					 }
				   if (!taxon_found) {
					 // need to add taxon to macrofossil sample
					 // NeotomaSamples[j].data[0].VariableID
					 // NeotomaSamples[j].data[0].Value
					 int UnitsID;
					 if ((UnitsID = GetNeotomaUnitsID(L"present/absent")) == -1)
					   return false;
					 int VariableElementID = -1;
					 if (!GetNeotomaVariableElementID(NeotomaTaxaDated[i], VariableElementID))
					   return false;
					 int VariableID;
					 if (!GetNeotomaVariable(NeotomaTaxaDated[i], VariableElementID, UnitsID, VariableID))
					   return false;
					 NEOTOMADATA Data;
					 Data.VariableID = VariableID;
					 Data.Value = 1;
					 NeotomaSamples[j].data.push_back(Data);
					 msg = L"VariableID " + IntToStr(VariableID) + L" added to macrofossil SampleID " +
						   IntToStr(NeotomaSamples[j].SampleID) + L".";
					 OutputLine(msg);
					 }
				   break;
				   }
				 }
			   if (NeotomaTaxaDated[i].SampleID == -1) {  // sample does not exist for dated macrofossil
				 NEOTOMASAMPLE Sample;
				 Sample.SampleID = NextTempSampleID();
				 Sample.AnalysisUnitID = GeochronAnalUnit[NeotomaTaxaDated[i].GeochronID];
				 Sample.CollUnitID = FindCollUnitID(Sample.AnalysisUnitID);
				 Sample.SiteID = site_ptr->NeotomaSiteID;
				 Sample.DatasetTypeID = 4;
				 Sample.DatasetID = PlantMacroDatasetID;

				 int UnitsID;
				 if ((UnitsID = GetNeotomaUnitsID(L"present/absent")) == -1)
				   return false;
				 int VariableElementID = -1;
				 if (!GetNeotomaVariableElementID(NeotomaTaxaDated[i], VariableElementID))
				   return false;
				 int VariableID;
				 if (!GetNeotomaVariable(NeotomaTaxaDated[i], VariableElementID, UnitsID, VariableID))
				   return false;
				 NEOTOMADATA Data;
				 Data.VariableID = VariableID;
				 Data.Value = 1;
				 Sample.data.push_back(Data);
				 NeotomaSamples.push_back(Sample);
				 OutputLine(L"Plant macrofossil sample defined for dated specimens: analysis unit «" +
					AnalysisUnitDescript(Sample.AnalysisUnitID) + L"»");
				 }
			   }
			 }
		   }
		 else {
		   msg = L"Add dated plant macrofossils in the geochronology tab sheet ";
		   msg += L"to a plant macrofossil dataset?";
		   if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes) {
			 // get present/absent UnitdID
			 int UnitsID;
			 if ((UnitsID = GetNeotomaUnitsID(L"present/absent")) == -1)
			   return false;

			 DATASET dataset;
			 map<int,UnicodeString>::iterator itr;
			 for (itr = NeotomaDatasetTypes.begin(); itr != NeotomaDatasetTypes.end(); itr++) {
			   if (ContainsText(itr->second, L"plant macrofossil")) {
				 dataset.DatasetType = itr->second;
				 break;
				 }
			   }

			 // get dataset publications
			 for (unsigned int i=0; i<NeotomaTaxaDated.size(); i++) {
			   if (SameText(NeotomaTaxaDated[i].TaxaGroupID, L"VPL") || SameText(NeotomaTaxaDated[i].TaxaGroupID, L"BRY")) {
				 if (NeotomaTaxaDated[i].Publications.size() > 0) {
				   for (unsigned int j=0; j<NeotomaTaxaDated[i].Publications.size(); j++) {
					 vector<PUBLICATION*>::iterator begin = dataset.Publications.begin();
					 vector<PUBLICATION*>::iterator end = dataset.Publications.end();
					 if (find(begin, end, NeotomaTaxaDated[i].Publications[j]) == end)
					   dataset.Publications.push_back(NeotomaTaxaDated[i].Publications[j]);
					 }
				   }
				 else {
				   msg = L"WARNING: No publication for geochronologic date " +
					 NeotomaTaxaDated[i].DateDescript + L" for " + dataset.DatasetType +
					 L" dataset.";
				   OutputWarning(msg);
				   }
				 }
			   }

			 // get dataset investigators
			 dataset.Investigators = TSSForm->GeochronDataset.Investigators;

			 map<int,UnicodeString>::iterator ditr;
			 for (ditr = NeotomaDatasetTypes.begin(); ditr != NeotomaDatasetTypes.end(); ditr++) {
			   if (SameText(dataset.DatasetType, ditr->second)) {
				 dataset.NeotomaDatasetTypeID = ditr->first;
				 dataset.NeotomaDatasetID = NextTempDatasetID();
				 SpecimenDateDatasetID = dataset.NeotomaDatasetID;
				 break;
				 }
			   }

			 TSSForm->Datasets.push_back(dataset);
			 site_ptr = (SITE*)TSSForm->Sites->Items[0];
			 site_ptr->CollUnits[0].NeotomaDatasets.push_back(dataset);

			 OutputLine(L"«" + dataset.DatasetType +
			   L"» dataset defined for directly dated taxa. DatasetTyepID = " +
			   IntToStr(dataset.NeotomaDatasetTypeID) + L".");

			 // get analysis unit
			 // NEOTOMAGEOCHRON
			 // NEOTOMASAMPLE
			 // define samples and add data
			 map<int,NEOTOMASAMPLE> PlantMFSamples;    // AnalysisUnitID, NeotomaSample
			 for (unsigned int i=0; i<NeotomaTaxaDated.size(); i++) {
			   if (SameText(NeotomaTaxaDated[i].TaxaGroupID, L"VPL") || SameText(NeotomaTaxaDated[i].TaxaGroupID, L"BRY")) {
				 map<int,NEOTOMASAMPLE>::iterator sample_itr;
				 for (unsigned int j=0; j<NeotomaGeochrons.size(); j++) {
				   if (NeotomaTaxaDated[i].GeochronID == NeotomaGeochrons[j].GeochronID) {
					 int AnalysisUnitID = NeotomaGeochrons[j].AnalysisUnitID;
					 sample_itr = PlantMFSamples.find(AnalysisUnitID);
					 if (sample_itr == PlantMFSamples.end()) {
					   NEOTOMASAMPLE Sample;
					   pair<map<int,NEOTOMASAMPLE>::iterator, bool> ret;
					   ret = PlantMFSamples.insert(pair<int,NEOTOMASAMPLE>(AnalysisUnitID, Sample));
					   sample_itr = ret.first;
					   }
					 break;
					 }
				   }

				 if (sample_itr->second.SampleID == -1) {  // new sample
				   sample_itr->second.AnalysisUnitID = sample_itr->first;
				   sample_itr->second.SampleID = NextTempSampleID();
				   sample_itr->second.DatasetTypeID = dataset.NeotomaDatasetTypeID;
				   sample_itr->second.DatasetID = dataset.NeotomaDatasetID;
				   for (unsigned int j=0; j<NeotomaAnalysisUnits.size(); j++) {
					 if (sample_itr->second.AnalysisUnitID == NeotomaAnalysisUnits[j].AnalysisUnitID) {
					   sample_itr->second.CollUnitID = NeotomaAnalysisUnits[j].CollectionUnitID;
					   break;
					   }
					 }
				   OutputLine(L"Plant macrofossil sample defined for analysis unit «" +
					 AnalysisUnitDescript(sample_itr->second.AnalysisUnitID) + L"»");
				   }

				 // get VariableID
				 // get VariableElement

				 int VariableElementID = -1;
				 if (!GetNeotomaVariableElementID(NeotomaTaxaDated[i], VariableElementID))
				   return false;

				 int VariableID;
				 if (!GetNeotomaVariable(NeotomaTaxaDated[i], VariableElementID, UnitsID, VariableID))
				   return false;
				 // add data to sample
				 sample_itr->second.data.push_back(NEOTOMADATA(VariableID,1.0,NULL));
				 }
			   }

			 // copy new plant macrofossil samples to NeotomaSamples
			 map<int,NEOTOMASAMPLE>::reverse_iterator sample_itr;
			 for (sample_itr = PlantMFSamples.rbegin(); sample_itr != PlantMFSamples.rend(); sample_itr++)
			   NeotomaSamples.push_back(sample_itr->second);


			 // map<int,NEOTOMASAMPLEAGE> NeotomaSampleAges;  // map<ChronNo, map<SampleID,NEOTOMAAGE> >
			 // sample ages

			 // get ChronNo for age model
			 int ChronNo = -1;
			 if (TSSForm->AgeModelList->Count == 0)
			   ChronNo = 1;
			 else {  //first get largest ChronNo...
			   AGEMODEL* AgeModel = TSSForm->AgeModelList->AgeModels[0];
			   ChronNo = AgeModel->ChronNumber;
			   if (TSSForm->AgeModelList->Count > 1) {
				 for (int i=1; i<TSSForm->AgeModelList->Count; i++) {
				   AGEMODEL* AgeModel = TSSForm->AgeModelList->AgeModels[i];
				   if (AgeModel->ChronNumber > ChronNo)
					 ChronNo = AgeModel->ChronNumber;
				   }
				 }
			   ChronNo++;   // ...then add 1
			   }

			 mfAgeModel = new AGEMODEL();
			 mfAgeModel->ChronNumber = ChronNo;
			 SpecimenDateChronNo = ChronNo;
			 mfAgeModel->ChronologyName = L"Specimen dates";
			 mfAgeModel->AgeModel = L"individually dated analysis units";
			 mfAgeModel->DatePrepared = Today();

			 // get age model preparer

			 CONTACT *Preparer = GetStewardContact();
			 if (Preparer != NULL)
			   mfAgeModel->Preparers.push_back(Preparer);

			 TSSForm->AgeModelList->Add(mfAgeModel);
			 OutputLine(L"Chron " + IntToStr(mfAgeModel->ChronNumber) +
			   L" defined for directly dated plant macrofossil dataset.");

			 // assign sample ages to new plant macrofossil samples
			 vector<pair<int,vector<SPECIMENAGE> > > MacroFossilAges;  // SampleID, vector<SPECIMENAGE>
			 for (sample_itr = PlantMFSamples.rbegin(); sample_itr != PlantMFSamples.rend(); sample_itr++) {
			   int SampleID = sample_itr->second.SampleID;
			   vector<SPECIMENAGE> Ages;
			   MacroFossilAges.push_back(pair<int,vector<SPECIMENAGE> >(SampleID,Ages));

			   // get 14C ages
			   for (unsigned int i=0; i<NeotomaGeochrons.size(); i++) {
				 if (sample_itr->second.AnalysisUnitID == NeotomaGeochrons[i].AnalysisUnitID) {
				   SPECIMENAGE Age;
				   Age.GeochronIndex = i;

				   if (NeotomaGeochrons[i].Age.IsEmpty())
					 Age.Age = NaN;
				   else
					 Age.Age = NeotomaGeochrons[i].Age;

				   if (NeotomaGeochrons[i].ErrorOlder.IsEmpty())
					 Age.AgeOlder = NaN;
				   else
					 Age.AgeOlder = NeotomaGeochrons[i].ErrorOlder;

				   if (NeotomaGeochrons[i].ErrorYounger.IsEmpty())
					 Age.AgeYounger = NaN;
				   else
					 Age.AgeYounger = NeotomaGeochrons[i].ErrorYounger;

				   if (NeotomaGeochrons[i].CalAge.IsEmpty())
					 Age.CalAge = NaN;
				   else
					 Age.CalAge = NeotomaGeochrons[i].CalAge;

				   if (NeotomaGeochrons[i].CalAgeOlder.IsEmpty())
					 Age.CalAgeOlder = NaN;
				   else
					 Age.CalAgeOlder = NeotomaGeochrons[i].CalAgeOlder;

				   if (NeotomaGeochrons[i].CalAgeYounger.IsEmpty())
					 Age.CalAgeYounger = NaN;
				   else
					 Age.CalAgeYounger = NeotomaGeochrons[i].CalAgeYounger;

				   MacroFossilAges.back().second.push_back(Age);
				   }
				 }
			   }

			 double AgeBoundYounger;
			 double AgeBoundOlder;
			 bool bounds_set = false;

			 NEOTOMASAMPLEAGE SampleAge;
			 NeotomaSampleAges[ChronNo] = SampleAge;

			 for (unsigned int i=0; i<MacroFossilAges.size(); i++) {
			   set<int> AgeTypes;
			   for (unsigned int j=0; j<MacroFossilAges[i].second.size(); j++) {
				 int idx = MacroFossilAges[i].second[j].GeochronIndex;
				 AgeTypes.insert(NeotomaGeochrons[idx].AgeTypeID);
				 }

			   if (AgeTypes.size() == 1) {    // can create chrons only if there is one kind of age type
				 int AgeType = *AgeTypes.begin();
				 if (MacroFossilAges[i].second.size() == 1) {
				   int SampleID = MacroFossilAges[i].first;
				   if (AgeType == 4) {  // radiocarbon years
					 if (IsNan(MacroFossilAges[i].second[0].CalAgeYounger)) {
					   mfAgeModel->AgeUnits = GetNeotomaAgeType(4);  // 14C yr BP
					   NEOTOMAAGE Age(MacroFossilAges[i].second[0]);
					   NeotomaSampleAges[ChronNo][SampleID] = Age;
					   }
					 else {
					   mfAgeModel->AgeUnits = GetNeotomaAgeType(3);  // cal yr BP
					   NEOTOMAAGE Age;
					   Age.Age = MacroFossilAges[i].second[0].CalAge;
					   Age.AgeYounger = MacroFossilAges[i].second[0].CalAgeYounger;
					   Age.AgeOlder = MacroFossilAges[i].second[0].CalAgeOlder;
					   NeotomaSampleAges[ChronNo][SampleID] = Age;
					   }
					 }
				   else {
					 mfAgeModel->AgeUnits = GetNeotomaAgeType(AgeType);
					 NEOTOMAAGE Age(MacroFossilAges[i].second[0]);
					 NeotomaSampleAges[ChronNo][SampleID] = Age;
					 }
				   if (bounds_set) {
					 if (NeotomaSampleAges[ChronNo][SampleID].AgeYounger < AgeBoundYounger)
					   AgeBoundYounger = NeotomaSampleAges[ChronNo][SampleID].AgeYounger;
					 if (NeotomaSampleAges[ChronNo][SampleID].AgeOlder > AgeBoundOlder)
					   AgeBoundOlder = NeotomaSampleAges[ChronNo][SampleID].AgeOlder;
					 }
				   else {
					 AgeBoundYounger = NeotomaSampleAges[ChronNo][SampleID].AgeYounger;
					 AgeBoundOlder = NeotomaSampleAges[ChronNo][SampleID].AgeOlder;
					 bounds_set = true;
					 }
				   }
				 else {
				   msg = L"ERROR: Multiple ages exist for dated plant macrofossils in the same sample.";
				   msg += L" Sample age cannot be assigned automatically to plant macrofossil sample.";
				   OutputError(msg);
				   }
				 }
			   else {
				 msg = L"ERROR: Dated plant macrofossils have mixed age types.";
				 msg += L" Sample age cannot be assigned to plant macrofossil sample.";
				 OutputError(msg);
				 }
			   }

			 mfAgeModel->AgeBoundOlder = SimpleRoundTo(AgeBoundOlder,1);
			 mfAgeModel->AgeBoundYounger = SimpleRoundTo(AgeBoundYounger,1) - 10;
			 }  // end add new macrofossil dataset
		   else {
			 msg = L"WARNING: Dated plant macrofossils in the geochronology tab sheet ";
			 msg += L"are not included in a plant macrofossil dataset.";
			 OutputWarning(msg);
			 }
		   }
		 }    // end check if any dated taxa are VPL or BRY

	   // assign SampleIDs to TaxaDated
	   for (unsigned int i=0; i<NeotomaTaxaDated.size(); i++) {
		 UnicodeString TaxaGroupID = NeotomaTaxaDated[i].TaxaGroupID;
		 for (unsigned int j=0; j<NeotomaGeochrons.size(); j++) {
		   if (NeotomaTaxaDated[i].GeochronID == NeotomaGeochrons[j].GeochronID) {
			 for (unsigned int k=0; k<NeotomaSamples.size(); k++) {
			   if (NeotomaSamples[k].AnalysisUnitID == NeotomaGeochrons[j].AnalysisUnitID) {
				 int DatasetTypeID = NeotomaSamples[k].DatasetTypeID;
				 if (TaxaGroupDatasetTypes.IsTaxaGroupInDatasetType(TaxaGroupID,DatasetTypeID)) {
				   NeotomaTaxaDated[i].SampleID = NeotomaSamples[k].SampleID;
				   break;
				   }
				 }
			   }
			 break;
			 }
		   }
		 }

	   // now check that all TaxaDated have been assigned SampleIDs
	   for (unsigned int i=0; i<NeotomaTaxaDated.size(); i++) {
		 if (NeotomaTaxaDated[i].SampleID == -1) {
		   msg = L"ERROR: Dated Taxon «" + NeotomaTaxaDated[i].Taxon + L"» in geochronologic date " +
			 NeotomaTaxaDated[i].DateDescript + L" in Taxa Group " + NeotomaTaxaDated[i].TaxaGroupID +
			 L" is not currently assigned to a sample";
		   OutputError(msg);
		   }
		 }

	   // generate ChronControls
	   if (mfAgeModel != NULL) {
		 set<int> SampleIDs; // list of used SampleIDs
		 for (unsigned int i=0; i<NeotomaTaxaDated.size(); i++) {
		   int SampleID = NeotomaTaxaDated[i].SampleID;
		   if (SampleIDs.count(SampleID) == 0) {
			 SampleIDs.insert(SampleID);
			 int AnalysisUnitID;
			 vector<NEOTOMASAMPLE>::iterator samp_itr;
			 for (samp_itr = NeotomaSamples.begin(); samp_itr != NeotomaSamples.end(); samp_itr++) {
			   if (SampleID == samp_itr->SampleID) {
				 AnalysisUnitID = samp_itr->AnalysisUnitID;
				 break;
				 }
			   }
             CHRON* chron = new CHRON();
			 for (unsigned int j=0; j<NeotomaAnalysisUnits.size(); j++) {
			   if (AnalysisUnitID == NeotomaAnalysisUnits[j].AnalysisUnitID) {
				 chron->Depth = NeotomaAnalysisUnits[j].Depth;
				 chron->Thickness = NeotomaAnalysisUnits[j].Thickness;
				 chron->AnalUnit = NeotomaAnalysisUnits[j].AnalysisUnitName;
				 break;
				 }
			   }
			 chron->AgeValue = NeotomaTaxaDated[i].Cal.Age;
			 chron->AgeLimitOlder = NeotomaTaxaDated[i].Cal.AgeOlder;
			 chron->AgeLimitYounger = NeotomaTaxaDated[i].Cal.AgeYounger;
			 chron->ControlType = L"Radiocarbon, calibrated";
			 chron->AgeUnits = L"Calendar";
             int CalibCurveID = NeotomaTaxaDated[i].Cal.CurveID;
			 for (unsigned int k=0; k<CalibCurves.Size(); k++) {
			   if (CalibCurveID == CalibCurves.Items[k].CalibrationCurveID) {
				 chron->CalibCurve = CalibCurves.Items[k].CalibrationCurve;
				 break;
				 }
			   }
			 int CalibProgID = NeotomaTaxaDated[i].Cal.ProgramID;
			 for (unsigned int k=0; k<CalibPrograms.Size(); k++) {
			   if (CalibProgID == CalibPrograms.Items[k].CalibrationProgramID) {
				 chron->Calib.Program = CalibPrograms.Items[k].CalibrationProgram;
				 chron->Calib.Version = CalibPrograms.Items[k].Version;
				 break;
				 }
			   }
			 int GeochronID = NeotomaTaxaDated[i].GeochronID;
			 for (unsigned int j=0; j<NeotomaGeochrons.size(); j++) {
			   if (GeochronID == NeotomaGeochrons[j].GeochronID) {
				 chron->GeochronIDs.push_back(NeotomaGeochrons[j].TiliaID);
				 break;
				 }
			   }
			 mfAgeModel->ChronControls->Add(chron);
			 }
		   }
		 //mfAgeModel->Default = true;
		 }
	   }  // end make_macro_dataset
	 }    // end all taxa, element types, and fractions found
   }
   __finally {
   Screen->Cursor = crDefault;
   SetProgressBarPosition();
   }

   return true;
}
//---------------------------------------------------------------------------


