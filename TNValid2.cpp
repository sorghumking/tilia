//---------------------------------------------------------------------------
#include <vcl.h>
#include "pch.h"

#pragma hdrstop

#include "TNValid2.h"
#ifndef TIUploadH
#include "TIUpload.h"
#endif
#ifndef TNSSAgeH
#include "TNSSAge.h"
#endif
#ifndef TNUtilsH
#include "TNUtils.h"
#endif

//---------------------------------------------------------------------------

#pragma package(smart_init)

bool TNeotomaUploadForm::ValidateSurfaceSample(bool& is_surface_sample)
{
   is_surface_sample = false;
   bool is_water_chem_sample = false;
   bool chron_defined = false;
   int crow;
   int corow;
   int cyrow;
   bool rv = true;
   UnicodeString msg;

   for (unsigned int i=0; i<TSSForm->Datasets.size(); i++) {
	 switch (TSSForm->Datasets[i].NeotomaDatasetTypeID) {
	   case 7:   // pollen surface sample
	   case 12:  // ostracode surface sample
	   case 13:  // diatom surface sample
	   case 22:  // modern plant biomarker
	   case 27:  // modern biochemistry
	   case 29:  // insect modern
	   case 32:  // testate amoebae surface sample
		 is_surface_sample = true;
		 break;
	   case 10:  // water chemistry sample (to accommodate lone WCH samples)
		 is_surface_sample = true;
		 is_water_chem_sample = true;
		 break;
	   }
	 if (is_surface_sample)
	   break;
	 }

   try {
   if (!is_surface_sample)
	 return (rv = true);
   else if (is_water_chem_sample && TSSForm->AgeModelList->Count > 0)
	 return (rv = true);

   OutputLine(L"");
   OutputBoldLine(L"Surface sample validation:");

   UnicodeString ControlType;
   if (TSSForm->AgeModelList->Count > 1) {
	 OutputError(L"ERROR: Only one age model can be assigned to surface samples.");
	 return (rv = false);
	 }
   else if (TSSForm->AgeModelList->Count == 1) {
	 AGEMODEL* AgeModel = TSSForm->AgeModelList->AgeModels[0];
	 if (AgeModel->ChronNumber != 1) {
	   OutputError(L"ERROR: ChronNo for age model must = 1.");
	   return (rv = false);
	   }
	 crow = TSSForm->FindRowCodeIC("#Chron1", TSSForm->ProfGrid1);
	 corow = TSSForm->FindRowCodeIC("#Chron1.Old", TSSForm->ProfGrid1);
	 cyrow = TSSForm->FindRowCodeIC("#Chron1.Young", TSSForm->ProfGrid1);

	 if (crow > 0 && ((corow == 0 && cyrow == 0) || (corow > 0 && cyrow > 0)))
	   chron_defined = true;
	 else if (crow == 0 && corow > 0 && cyrow > 0)
	   chron_defined = true;
	 if (!chron_defined) {
	   OutputError(L"ERROR: #Chron1 not properly defined in spreadsheet.");
	   return (rv = false);
	   }

	 if (!SameText(AgeModel->AgeModel,L"collection date") && !SameText(AgeModel->AgeModel,L"collection period")) {
	   OutputError(L"ERROR: Age model for surface samples must be «collection date» or «collection period»");
	   return (rv = false);
	   }
	 if (!SameText(AgeModel->AgeUnits, L"Calendar years BP")) {
	   OutputError(L"ERROR: Age units for surface samples must be «Calendar years BP»");
	   return (rv = false);
	   }

	 for (int i=0; i<AgeModel->ChronControls->Count; i++) {
	   CHRON* AgeControl = (CHRON*)AgeModel->ChronControls->Items[i];
	   if (AgeControl->AnalUnit.IsEmpty()) {
		 OutputError(L"ERROR: Chronology controls must be assigned to analysis units.");
		 return (rv = false);
		 }
	   if (!SameText(AgeControl->ControlType,L"Collection date") && !SameText(AgeControl->ControlType,L"Collection period")) {
		 OutputError(L"ERROR: Age basis for surface samples must be «Collection date» or «Collection period»");
		 return (rv = false);
		 }
	   if (ControlType.IsEmpty())
		 ControlType = AgeControl->ControlType;
	   else if (!SameText(ControlType,AgeControl->ControlType)) {
		 OutputError(L"ERROR: Age basis for surface samples must all be the same");
		 return (rv = false);
		 }

	   if (!AgeControl->AgeValue.IsEmpty() &&
		  ((AgeControl->AgeLimitOlder.IsEmpty() && !AgeControl->AgeLimitYounger.IsEmpty()) ||
		   (!AgeControl->AgeLimitOlder.IsEmpty() && AgeControl->AgeLimitYounger.IsEmpty())))
		 rv = false;
	   else if (AgeControl->AgeValue.IsEmpty() && (AgeControl->AgeLimitOlder.IsEmpty() || AgeControl->AgeLimitYounger.IsEmpty()))
		 rv = false;
	   if (!rv) {
		 OutputError(L"ERROR: Ages not properly defined for surface sample chronology controls.");
		 return (false);
		 }
	   }
	 // this prevents chron from being deleted
	 ChronNumbers.insert(AgeModel->ChronNumber);
	 }

   bool aggregate = false;
   for (unsigned int i=0; i<TSSForm->Datasets.size(); i++) {
	 if (TSSForm->Datasets[i].IsAggregate) {
	   aggregate = true;
	   break;
	   }
	 }

   struct { int rv; double YearBP; double YearOlderBP; double YearYoungerBP; } SampleAge;
   SampleAge.rv = mrOk;

   // map of analysis unit names and ids
   map<UnicodeString,int> AnalUnitMap;
   for (unsigned int i=0; i<NeotomaAnalysisUnits.size(); i++)
	 AnalUnitMap[NeotomaAnalysisUnits[i].AnalysisUnitName] = NeotomaAnalysisUnits[i].AnalysisUnitID;

   int ChronNo = 1;
   //double YearBP;
   //double YearOlderBP;
   //double YearYoungerBP;
   vector<SSAMPLEAGE> Years;
   UnicodeString Text;
   int first_site = (TSSForm->Sites->Count > 1) ? 1 : 0;
   for (int i=first_site; i<TSSForm->Sites->Count; i++) {
	 SITE* site_ptr = (SITE*)TSSForm->Sites->Items[i];
	 int first_collunit = (site_ptr->CollUnits.size() > 1) ? 1 : 0;
	 for (unsigned int j = first_collunit; j < site_ptr->CollUnits.size(); j++) {
	   NEOTOMAAGEMODEL NeotomaAgeModel;
	   COLLECTION& CollUnit = site_ptr->CollUnits[j];
	   //YearBP = -9999;
	   //YearOlderBP = -9999;
	   //YearYoungerBP = -9999;
	   if (chron_defined) {
		 AGEMODEL* AgeModel = TSSForm->AgeModelList->AgeModels[0];
		 for (unsigned int k=0; k<NeotomaSamples.size(); k++) {
		   if (NeotomaSamples[k].CollUnitID == CollUnit.NeotomaCollUnitID) {
			 SSAMPLEAGE Year(NeotomaSamples[k].AnalysisUnitID, NeotomaSamples[k].SampleID, ControlType);
			 int col = NeotomaSamples[k].col;
			 UnicodeString A1Name = TSSForm->ProfGrid1->AbsoluteCols[col]->A1Name;
			 if (crow > 0) {
			   Text = TSSForm->ProfGrid1->AbsoluteCells[col][crow]->Text;
			   if (Text.IsEmpty()) {
				 msg = L"ERROR: #Chron1 in column " + A1Name + L" cannot be empty.";
				 OutputError(msg);
				 return (rv = false);
				 }
			   else if (!TryStrToFloat(Text,Year.BP)) {
				 msg = L"ERROR: Invalid value for #Chron1 in column " + A1Name + L".";
				 OutputError(msg);
				 return (rv = false);
				 }
			   }
			 if (corow > 0) {
			   Text = TSSForm->ProfGrid1->AbsoluteCells[col][corow]->Text;
			   if (Text.IsEmpty()) {
				 msg = L"ERROR: #Chron1.Old in column " + A1Name + L" cannot be empty.";
				 OutputError(msg);
				 return (rv = false);
				 }
			   else if (!TryStrToFloat(Text,Year.OldBP)) {
				 msg = L"ERROR: Invalid value for #Chron1.Old in column " + A1Name + L".";
				 OutputError(msg);
				 return (rv = false);
				 }
			   }
			 if (cyrow > 0) {
			   Text = TSSForm->ProfGrid1->AbsoluteCells[col][cyrow]->Text;
			   if (Text.IsEmpty()) {
				 msg = L"ERROR: #Chron1.Young in column " + A1Name + L" cannot be empty.";
				 OutputError(msg);
				 return (rv = false);
				 }
			   else if (!TryStrToFloat(Text,Year.YoungBP)) {
				 msg = L"ERROR: Invalid value for #Chron1.Young in column " + A1Name + L".";
				 OutputError(msg);
				 return (rv = false);
				 }
			   }
			 if (corow > 0) {
			   if (Year.OldBP < Year.YoungBP) {
				 msg = L"ERROR: #Chron1.Old is younger than #Chron1.Young in column " + A1Name + L".";
				 OutputError(msg);
				 return (rv = false);
				 }
			   }
			 Years.push_back(Year);
			 }
		   }
		 if (!AgeModel->ChronologyName.IsEmpty())
		   NeotomaAgeModel.ChronologyName = AgeModel->ChronologyName;
		 else
		   NeotomaAgeModel.ChronologyName = L"Collection date";
		 if (AgeModel->Preparers.size() > 0)
		   NeotomaAgeModel.Preparers.push_back(AgeModel->Preparers[0]);
		 if (!AgeModel->DatePrepared.IsEmpty() && AgeModel->DatePrepared.Type() == varDate)
		   NeotomaAgeModel.DatePrepared = AgeModel->DatePrepared;
		 NeotomaAgeModel.AgeModel = AgeModel->AgeModel;
		 }
	   else {
		 unsigned short year, month, day;
		 int SampleAgeStyle;
		 TDateTime Date;

		 int idx = -1;
		 for (unsigned int k=0; k<NeotomaSamples.size(); k++) {
		   if (NeotomaSamples[k].CollUnitID == CollUnit.NeotomaCollUnitID) {
			 // SSAMPLEAGE Year(NeotomaSamples[k].AnalysisUnitID, NeotomaSamples[k].SampleID, ControlType);
			 idx = k;
			 break;
			 }
		   }

		 // This should never happen, but..
		 if (idx == -1) {
		   msg = L"ERROR: Sample collection unit not found.";
		   OutputError(msg);
		   return (rv = false);
		   }

		 // SSAMPLEAGE Year(-1,-1,ControlType);
		 SSAMPLEAGE Year(NeotomaSamples[idx].AnalysisUnitID, NeotomaSamples[idx].SampleID, ControlType);

		 if (CollUnit.CollDate.Type() == varDate) {
		   Date = VarToDateTime(CollUnit.CollDate);
		   Date.DecodeDate(&year, &month, &day);
		   Year.BP = 1950 - year;
		   }
		 if (Year.BP == -9999) {
		   if (SampleAge.rv == mrYesToAll) {
			 Year.BP = SampleAge.YearBP;
			 Year.OldBP = SampleAge.YearOlderBP;
			 Year.YoungBP = SampleAge.YearYoungerBP;
			 }
		   else {
			 SurfaceSampleAgeForm = new TSurfaceSampleAgeForm(this);
			 int rv = SurfaceSampleAgeForm->ShowModal();
			 if (rv == mrOk || rv == mrYesToAll) {
			   SampleAgeStyle = SurfaceSampleAgeForm->SampleAgeStyle;
			   switch (SampleAgeStyle) {
				 case dsEXACTDATE:
				   CollUnit.CollDate = SurfaceSampleAgeForm->cxDateEdit1->Date;
				   Date = VarToDateTime(CollUnit.CollDate);
				   Date.DecodeDate(&year, &month, &day);
				   Year.BP = 1950 - year;
				   break;
				 case dsYEAR:
				   Year.BP = SurfaceSampleAgeForm->YearBP;
				   break;
				 case dsYEARRANGE:
				   Year.OldBP = SurfaceSampleAgeForm->YearOlderBP;
				   Year.YoungBP = SurfaceSampleAgeForm->YearYoungerBP;
				   break;
				 }
			   if (rv == mrYesToAll) {
				 SampleAge.rv = mrYesToAll;
				 SampleAge.YearBP = Year.BP;
				 SampleAge.YearOlderBP = Year.OldBP;
				 SampleAge.YearYoungerBP = Year.YoungBP;
				 }
			   }
			 delete SurfaceSampleAgeForm;

			 if (rv == mrIgnore || rv == mrAbort) {
			   OutputError(L"ERROR: Age of surface sample not set.");
			   return (rv = false);
			   }
			 if (Year.BP == -9999 && (Year.OldBP == -9999 || Year.YoungBP == -9999)) {
			   // this should never happen, but...
			   OutputError(L"ERROR: Age of surface sample not set correctly.");
			   return (rv = false);
			   }
			 }
		   }
		 NeotomaAgeModel.ChronologyName = L"Collection date";
		 CONTACT *Preparer = GetStewardContact();
		 if (Preparer != NULL)
		   NeotomaAgeModel.Preparers.push_back(Preparer);
		 NeotomaAgeModel.DatePrepared = Today();
		 NeotomaAgeModel.AgeModel = L"collection date";
		 Years.push_back(Year);
		 }

	   NeotomaAgeModel.ChronNumber = ChronNo;    // formerly 1
	   NeotomaAgeModel.AgeUnits = L"Calendar years BP";
	   NeotomaAgeModel.Default = true;

	   double AgeBoundOld = -9999;
	   double AgeBoundYoung = -9999;
	   for (unsigned int i=0; i<Years.size(); i++) {
		 if (Years[i].OldBP != -9999 && Years[i].YoungBP != -9999) {
		   if (AgeBoundOld == -9999 || Years[i].OldBP > AgeBoundOld)
			 AgeBoundOld = Years[i].OldBP;
		   if (AgeBoundYoung == -9999 || Years[i].YoungBP < AgeBoundYoung)
			 AgeBoundYoung = Years[i].YoungBP;
		   }
		 else {
		   if (AgeBoundOld == -9999 || Years[i].BP > AgeBoundOld)
			 AgeBoundOld = Years[i].BP;
		   if (AgeBoundYoung == -9999 || Years[i].BP < AgeBoundYoung)
			 AgeBoundYoung = Years[i].BP;
		   }
		 }
	   NeotomaAgeModel.AgeBoundOlder = Ceil(AgeBoundOld);
	   NeotomaAgeModel.AgeBoundYounger = Floor(AgeBoundYoung);

	   OutputLine(L"Surface sample age model instantiated.");

	   if (aggregate) {
		 if (NeotomaAgeTypes.size() == 0) {
		  NeotomaAgeTypesTable AgeTypesTable(ipsJSONS1, TcpClient1);
		  StatusBar1->SimpleText = AgeTypesTable.WebServiceName();
		  if (AgeTypesTable.Execute())
			NeotomaAgeTypes = AgeTypesTable.Items;
		  else
			return (rv = false);
		  }

		 if (ChronNo == 1) {
		   int AgeTypeID = FindAgeType(NeotomaAgeModel.AgeUnits, NeotomaAgeTypes);
		   AggregateChron.AgeTypeID = AgeTypeID;
		   AggregateChron.IsDefault = true;
		   AggregateChron.ChronologyName = NeotomaAgeModel.ChronologyName;
		   AggregateChron.AgeBoundYounger = NeotomaAgeModel.AgeBoundYounger;
		   AggregateChron.AgeBoundOlder = NeotomaAgeModel.AgeBoundOlder;
		   }
		 else {
		   AggregateChron.AgeBoundYounger = NeotomaAgeModel.AgeBoundYounger;
		   AggregateChron.AgeBoundOlder = NeotomaAgeModel.AgeBoundOlder;
		   }
		 }

	   /*
	   CHRON AgeControl;
	   if (ControlType.IsEmpty())
		 AgeControl.ControlType = L"Collection date";
	   else
		 AgeControl.ControlType = ControlType;

	   // AgeControl.NeotomaAnalUnitID
	   // AgeControl.AnalUnit

	   if (YearBP != -9999) {
		 AgeControl.AgeValue = YearBP;
		 OutputLine(L"Surface sample age: " + FloatToStr(YearBP) + L" cal yr BP.");
		 }
	   else {
		 AgeControl.AgeLimitOlder = YearOlderBP;
		 AgeControl.AgeLimitYounger = YearYoungerBP;
		 OutputLine(L"Surface sample older age limit: " + FloatToStr(YearOlderBP) + L" cal yr BP.");
		 OutputLine(L"Surface sample younger age limit: " + FloatToStr(YearYoungerBP) + L" cal yr BP.");
		 }
	   */

	   if (j == site_ptr->CollUnits.size() - 1)
		 SetProgressBarPosition(2);

	   // in place of ValidateAgeModels
	   NEOTOMACHRONOLOGY NeotomaChron;
	   NeotomaChron.CollectionUnitID = CollUnit.NeotomaCollUnitID;
	   NeotomaChron.ChronologyID = NextTempChronologyID();
	   TiliaChronIDs[NeotomaChron.ChronologyID] = NeotomaAgeModel.ChronNumber;
	   NeotomaChron.ChronologyName = NeotomaAgeModel.ChronologyName;
	   NeotomaChron.AgeTypeID = 2;
	   NeotomaChron.AgeModel = NeotomaAgeModel.AgeModel;
	   NeotomaChron.AgeBoundOlder = NeotomaAgeModel.AgeBoundOlder;
	   NeotomaChron.AgeBoundYounger = NeotomaAgeModel.AgeBoundYounger;
	   NeotomaChron.ContactID = NeotomaAgeModel.Preparers[0]->NeotomaContactID;
	   NeotomaChron.DatePrepared = NeotomaAgeModel.DatePrepared;
	   NeotomaChron.IsDefault = NeotomaAgeModel.Default;
	   NeotomaChrons.push_back(NeotomaChron);

	   if (j == site_ptr->CollUnits.size() - 1)
		 SetProgressBarPosition(2);  // includes check default age models

	   // in place of validate ChronControls (in ValidateAgeModels)
	   for (unsigned int i=0; i<NeotomaAnalysisUnits.size(); i++) {
		 if (NeotomaAnalysisUnits[i].CollectionUnitID == CollUnit.NeotomaCollUnitID) {
		   NEOTOMACHRONCONTROL NeotomaChronControl;
		   NeotomaChronControl.ChronControlID = NextTempChronControlID();

		   int idx = -1;
		   if (Years.size() == 1 && Years[0].AnalUnitID == -1)
			 idx = 0;
		   else {
			 int AnalUnitID = AnalUnitMap[NeotomaAnalysisUnits[i].AnalysisUnitName];
			 for (unsigned int j=0; j<Years.size(); j++) {
			   if (Years[j].AnalUnitID == AnalUnitID) {
				 idx = j;
				 break;
				 }
			   }
			 }
		   // this should never happen, but..
		   if (idx == -1) {
			 msg = L"ERROR: Analysis unit name in chron control not matched with one in spreadsheet.";
			 OutputError(msg);
			 return (rv = false);
			 }

		   if (SameText(Years[idx].ControlType,L"Collection period"))
			 NeotomaChronControl.ChronControlTypeID = 115;
		   else
			 NeotomaChronControl.ChronControlTypeID = 74;  // Collection date
		   NeotomaChronControl.AnalysisUnitID = NeotomaAnalysisUnits[i].AnalysisUnitID;
		   NeotomaChronControl.AgeTypeID = 2;  // Calendar
		   //if (!AgeControl.AgeValue.IsEmpty())
		   //	 NeotomaChronControl.Age = AgeControl.AgeValue;
		   //else {
		   //	 NeotomaChronControl.AgeLimitOlder = AgeControl.AgeLimitOlder;
		   //	 NeotomaChronControl.AgeLimitYounger = AgeControl.AgeLimitYounger;
		   //	 }

		   if (Years[idx].BP != -9999) {
			 NeotomaChronControl.Age = Years[idx].BP;
			 OutputLine(L"Surface sample age: " + FloatToStr(Years[idx].BP) + L" cal yr BP.");
			 }
		   if (Years[idx].OldBP != -9999 && Years[idx].YoungBP != -9999) {
			 NeotomaChronControl.AgeLimitOlder = Years[idx].OldBP;
			 NeotomaChronControl.AgeLimitYounger = Years[idx].YoungBP;
			 OutputLine(L"Surface sample older age limit: " + FloatToStr(Years[idx].OldBP) + L" cal yr BP.");
			 OutputLine(L"Surface sample younger age limit: " + FloatToStr(Years[idx].YoungBP) + L" cal yr BP.");
			 }

		   NeotomaChrons[ChronNo-1].ChronControls.push_back(NeotomaChronControl);
		   UnicodeString msg = L"Analysis Unit «" + NeotomaAnalysisUnits[i].AnalysisUnitName + L"»: Chron Control assigned.";
		   OutputLine(msg);
		   }
		 }

	   if (j == site_ptr->CollUnits.size() - 1)
		 SetProgressBarPosition();

	   // in place of ValidateSampleAges
	   NEOTOMASAMPLEAGE SampleAge;
	   NeotomaSampleAges[ChronNo] = SampleAge;
	   for (unsigned int i=0; i<NeotomaSamples.size(); i++) {
		 if (NeotomaSamples[i].CollUnitID == CollUnit.NeotomaCollUnitID) {
		   NEOTOMAAGE Age;
		   int SampleID = NeotomaSamples[i].SampleID;
		   NeotomaSampleAges[ChronNo][SampleID] = Age;    // ChronNo == 1
		   int idx = -1;
		   if (Years.size() == 1 && Years[0].SampleID == -1)
			 idx = 0;
		   else {
			 for (unsigned int j=0; j<Years.size(); j++) {
			   if (Years[j].SampleID == SampleID) {
				 idx = j;
				 break;
				 }
			   }
			 }
		   // this should never happen but..
		   if (idx == -1) {
			 msg = L"ERROR: SampleID for age not matched with sample.";
			 OutputError(msg);
			 return (rv = false);
			 }

		   int AnalUnitID = NeotomaSamples[i].AnalysisUnitID;
		   UnicodeString AnalUnitName;
		   map<UnicodeString,int>::iterator itr;
		   for (itr = AnalUnitMap.begin(); itr != AnalUnitMap.end(); itr++) {
			 if (itr->second == AnalUnitID) {
			   AnalUnitName = itr->first;
			   break;
			   }
			 }

		   UnicodeString BPStr = L"_";
		   UnicodeString OldBPStr = L"_";
		   UnicodeString YoungBPStr = L"_";
		   if (Years[idx].BP != -9999) {
			 NeotomaSampleAges[ChronNo][SampleID].Age = Years[idx].BP;
			 BPStr = FloatToStr(Years[idx].BP);
			 }
		   if (Years[idx].OldBP != -9999 && Years[idx].YoungBP != -9999) {
			 NeotomaSampleAges[ChronNo][SampleID].AgeOlder = Years[idx].OldBP;
			 NeotomaSampleAges[ChronNo][SampleID].AgeYounger = Years[idx].YoungBP;
			 OldBPStr = FloatToStr(Years[idx].OldBP);
			 YoungBPStr = FloatToStr(Years[idx].YoungBP);
			 }
		   UnicodeString AgeStr = OldBPStr + L"/" + BPStr + L"/" + YoungBPStr;

		   UnicodeString msg = L"Sample age " + OldBPStr + L"/" + BPStr + L"/" +
		     YoungBPStr + L" assigned to " + NeotomaDatasetTypes[NeotomaSamples[i].DatasetTypeID];
		   if (!SameText(msg.SubString(msg.Length()-5,6), L"sample"))
			 msg += L" sample";
		   msg += (L" " + AnalUnitName + L".");
		   OutputLine(msg);
		   }
		 }
	   ChronNo++;
	   }
	 }
   }
   __finally {
	 Screen->Cursor = crDefault;
	 StatusBar1->SimpleText = L"";
	 SetProgressBarPosition();
	 }
   return rv;
}
//---------------------------------------------------------------------------

int TNeotomaUploadForm::GetNeotomaUnitsID(UnicodeString Units)
{
   int UnitsID = -1;

   NeotomaVariableUnitsID VariableUnits(ipsJSONS1, TcpClient1);
   VariableUnits.AddParam(L"VARIABLEUNITS", Units);
   StatusBar1->SimpleText = VariableUnits.WebServiceName();
   if (VariableUnits.Execute()) {
	 if (VariableUnits.Size() == 1)
	   UnitsID = VariableUnits.Items[0];
	 else {
	   UnicodeString msg = L"ERROR: VariableUnits «" + Units + L"» not found in Neotoma VariableUnits table.";
	   OutputError(msg);
	   }
	 }
   return UnitsID;
}
//---------------------------------------------------------------------------

bool TNeotomaUploadForm::GetNeotomaVariableElementID(NEOTOMATAXONDATE& TaxonDated,
	int& VariableElementID)
{
   UnicodeString ErrorMsg;

   if (!TaxonDated.ElementType.IsEmpty()) {
	 NeotomaVariableElementByPartIDs VariableElement(ipsJSONS1, TcpClient1);
	 VariableElement.AddParam(L"ELEMENTTYPEID", TaxonDated.NeotomaElementTypeID);
	 VariableElement.AddParam(L"SYMMETRYID", -1);
	 VariableElement.AddParam(L"PORTIONID", -1);
	 VariableElement.AddParam(L"MATURITYID", -1);
	 StatusBar1->SimpleText = VariableElement.WebServiceName();
	 if (VariableElement.Execute()) {
	   if (VariableElement.Size() == 1)
		 VariableElementID = VariableElement.Items[0];
	   else {  // upload new VariableElement
		 vector<int> newids;
		 InsertData InsertVariableElement(L"InsertVariableElement", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
		 InsertVariableElement.Add(L"VARIABLEELEMENT", TaxonDated.ElementType);
		 InsertVariableElement.Add(L"ELEMENTTYPEID", TaxonDated.NeotomaElementTypeID, -1);
		 StatusBar1->SimpleText = L"InsertVariableElement";
		 InsertVariableElement.PostData();
		 if (InsertVariableElement.Post(newids, ErrorMsg)) {
		   if (newids.size() == 1) {
			 VariableElementID = newids[0];
			 OutputLine(L"New variable element uploaded: " + TaxonDated.ElementType +
			   L", ID = " + IntToStr(VariableElementID) + L".");
			 }
		   else {
			 ErrorMsg = L"Error inserting into VariableElements table!";
			 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			 return false;
			 }
		   }
		 else {
		   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   return false;
		   }
		 }
	   }
	 else
	   return false;
	 }
   return true;
}
//---------------------------------------------------------------------------

bool TNeotomaUploadForm::GetNeotomaVariable(NEOTOMATAXONDATE& TaxonDated,
	int VariableElementID, int UnitsID, int& VariableID)
{
   UnicodeString msg, ErrorMsg;

   NeotomaVariableByComponents Variable(ipsJSONS1, TcpClient1);
   Variable.AddParam(L"TAXONID", TaxonDated.NeotomaTaxonID);
   if (VariableElementID > -1)
	 Variable.AddParam(L"VARIABLEELEMENTID", VariableElementID);
   Variable.AddParam(L"VARIABLEUNITSID", UnitsID);
   if (Variable.Execute()) {
	 if (Variable.Size() == 1) {
	   VariableID = Variable.Items[0].VariableID;
	   msg = L"Variable validated: VariableID = " + IntToStr(VariableID) +
			 ", «" + TaxonDated.Taxon + L"», TaxonID = " + IntToStr(TaxonDated.NeotomaTaxonID);
	   if (TaxonDated.NeotomaElementTypeID > -1)
		  msg += (L", ElementID = " + IntToStr(TaxonDated.NeotomaElementTypeID));
	   msg += (L", UnitsID = " + IntToStr(UnitsID) + L".");
	   OutputLine(msg);
	   }
	 else if (Variable.Size() > 1) { // database error: more than one variable with same components
	   msg = L"DATABASE ERROR: Database has multiple entries of the same variable. ";
	   msg += L"VariableID = " + IntToStr(VariableID) + ", «" + TaxonDated.Taxon +
			  L"», TaxonID = " + IntToStr(TaxonDated.NeotomaTaxonID);
	   if (TaxonDated.NeotomaElementTypeID > -1)
		 msg += (L", ElementID = " + IntToStr(TaxonDated.NeotomaElementTypeID));
	   msg += (L", UnitsID = " + IntToStr(UnitsID) + L".");
	   OutputError(msg);
	   }
	 else {  // new variable
	   vector<int> newids;
	   InsertData InsertVariable(L"InsertVariable", 3, ipsHTTPS1, ipsJSONS1, TcpClient1);
	   InsertVariable.Add(L"TAXONID", TaxonDated.NeotomaTaxonID, -1);
	   InsertVariable.Add(L"VARIABLEELEMENTID", VariableElementID, -1);
	   InsertVariable.Add(L"VARIABLEUNITSID", UnitsID, -1);
	   StatusBar1->SimpleText = L"InsertVariable";
	   InsertVariable.PostData();
	   if (InsertVariable.Post(newids, ErrorMsg)) {
		 if (newids.size() == 1) {
		   VariableID = newids[0];
		   msg = L"New variable uploaded: VariableID = " + IntToStr(VariableID) +
				 ", «" + TaxonDated.Taxon + L"», TaxonID = " + IntToStr(TaxonDated.NeotomaTaxonID);
		   if (TaxonDated.NeotomaElementTypeID > -1)
			 msg += (L", ElementID = " + IntToStr(TaxonDated.NeotomaElementTypeID));
		   msg += (L", UnitsID = " + IntToStr(UnitsID) + L".");
		   OutputLine(msg);
		   }
		 else {
		   ErrorMsg = L"Error inserting into Variables table!";
		   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   return false;
		   }
		 }
	   else {
		 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 return false;
		 }
	   } // end
	 }

   return true;
}
//---------------------------------------------------------------------------

bool TNeotomaUploadForm::ValidateAgeModels(AGEMODEL* NewAgeModel)
{
   UnicodeString msg;

   Screen->Cursor = crHourGlass;
   if (NeotomaAgeTypes.size() == 0) {
	 NeotomaAgeTypesTable AgeTypesTable(ipsJSONS1, TcpClient1);
	 StatusBar1->SimpleText = AgeTypesTable.WebServiceName();
	 if (AgeTypesTable.Execute())
	   NeotomaAgeTypes = AgeTypesTable.Items;
	 else {
	   Screen->Cursor = crDefault;
	   return false;
	   }
	 }

   // if multi collection units, chron controls must be assigned to spreadsheet analysis units
   site_ptr = (SITE*)TSSForm->Sites->Items[0];
   if (TSSForm->Sites->Count > 1 || site_ptr->CollUnits.size() > 1) {
	 if (NewAgeModel != NULL) {
	   if (!ValidateMultiAnalUnits(NewAgeModel))
		 return false;
	   }
	 else {
	   for (int i=0; i<TSSForm->AgeModelList->Count; i++) {
		 AGEMODEL* AgeModel = TSSForm->AgeModelList->AgeModels[i];
		 if (!ValidateMultiAnalUnits(AgeModel))
		   return false;
		 }
	   }
	 }

   // get set of AgeTypes for all age models
   set<UnicodeString> AgeTypes;
   if (NewAgeModel != NULL)
	 AgeTypes.insert(NewAgeModel->AgeUnits);
   else {
	 for (int i=0; i<TSSForm->AgeModelList->Count; i++) {
	   AGEMODEL* AgeModel = TSSForm->AgeModelList->AgeModels[i];
	   if (AgeTypes.count(AgeModel->AgeUnits) == 0)
		 AgeTypes.insert(AgeModel->AgeUnits);
	   }
	 }

   // check that default age model exists for each AgeType
   for (set<UnicodeString>::iterator itr = AgeTypes.begin(); itr != AgeTypes.end(); itr++) {
	 UnicodeString AgeType = *itr;
	 int n = 0;
	 int IsDefault = 0;
	 int ChronNo;
	 for (int i=0; i<TSSForm->AgeModelList->Count; i++) {
	   AGEMODEL* AgeModel = TSSForm->AgeModelList->AgeModels[i];
	   if (SameText(AgeModel->AgeUnits, AgeType)) {
		 n++;
		 if (AgeModel->Default) {
		   ChronNo = i;
		   IsDefault++;
		   }
		 }
	   }
	 if (n == 1 && IsDefault == 0) {  // only one chron with age type, no default
	   bool make_default = false;
	   if (GeochronOnly)
		 make_default = true;
	   else {
		 msg = L"No default age model set for age type «" + AgeType + L"».";
		 msg += L"\nOnly one age model has this age type. Set this one as the default?";
		 if (MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes)
		   make_default = true;
		 }
	   if (make_default) {
		 for (int i=0; i<TSSForm->AgeModelList->Count; i++) {
		   AGEMODEL* AgeModel = TSSForm->AgeModelList->AgeModels[i];
		   if (SameText(AgeModel->AgeUnits, AgeType)) {
			 AgeModel->Default = true;
			 msg = L"Chron " + IntToStr(AgeModel->ChronNumber) + L" set as default for age type «" +
				   AgeType + L"».";
			 OutputLine(msg);
			 break;
			 }
		   }
		 }
	   }
	 else if (n > 1 && IsDefault == 0) {  // more than one chron with age type, no default
	   msg = L"No default age model set for age type «" + AgeType + L"».";
	   OutputError(L"ERROR: " + msg);
	   if (MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbIgnore << mbAbort, 0) == mrAbort) {
		 Screen->Cursor = crDefault;
		 return false;
		 }
	   }
	 else if (IsDefault > 1) {  // more than one default set
	   msg = L"More than one default age model set for age type «" + AgeType + L"».";
	   OutputError(L"ERROR: " + msg);
	   if (MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbIgnore << mbAbort, 0) == mrAbort) {
		 Screen->Cursor = crDefault;
		 return false;
		 }
	   }
	 else {  // everything hunky-dory
	   AGEMODEL* AgeModel = TSSForm->AgeModelList->AgeModels[ChronNo];
	   msg = L"Chron " + IntToStr(AgeModel->ChronNumber) + L" set as default for age type «" +
			 AgeType + L"».";
	   OutputLine(msg);
	   }
	 }
   SetProgressBarPosition();
   // --------- end default age model check -----------

   // Transfer AGEMODEL metadata to NEOTOMAAGEMODEL

   //vector<pair<int,int> > CollUnitAgeModels;  // OldChronNo, CollUnitID
   int NewChronNo = 1;   // uncommented this
   SITE* site_ptr = (SITE*)TSSForm->Sites->Items[0];
   if (TSSForm->Sites->Count > 1 || site_ptr->CollUnits.size() > 1) {
	 if (NewAgeModel != NULL) {
	   if (!TransferAgeModelToNeotomaAgeModel(NewAgeModel, NewChronNo)) {
		 Screen->Cursor = crDefault;
		 return false;
		 }
	   }
	 else {
	   for (int i=0; i<TSSForm->AgeModelList->Count; i++) {
		 AGEMODEL* AgeModel = TSSForm->AgeModelList->AgeModels[i];
		 if (!TransferAgeModelToNeotomaAgeModel(AgeModel, NewChronNo)) {
		   Screen->Cursor = crDefault;
		   return false;
		   }
		 }
	   }
	 }
   else {
	 int CollUnitID = site_ptr->CollUnits[0].NeotomaCollUnitID;

	 if (NewAgeModel != NULL) {
	   NEOTOMAAGEMODEL NeotomaAgeModel(NewAgeModel->ChronNumber, NewAgeModel, NewAgeModel->ChronControls);
	   NeotomaAgeModel.CollUnitID = CollUnitID;
	   NeotomaAgeModels.push_back(NeotomaAgeModel);
	   pair<int,int> CollUnitAgeModel(NewAgeModel->ChronNumber,CollUnitID);
	   NeotomaChronNoMap[CollUnitAgeModel] = NewAgeModel->ChronNumber;
	   }
	 else {
	   for (int i=0; i<TSSForm->AgeModelList->Count; i++) {
		 AGEMODEL* AgeModel = TSSForm->AgeModelList->AgeModels[i];
		 NEOTOMAAGEMODEL NeotomaAgeModel(AgeModel->ChronNumber, AgeModel, AgeModel->ChronControls);
		 NeotomaAgeModel.CollUnitID = CollUnitID;
		 NeotomaAgeModels.push_back(NeotomaAgeModel);
		 pair<int,int> CollUnitAgeModel(AgeModel->ChronNumber,CollUnitID);
		 NeotomaChronNoMap[CollUnitAgeModel] = AgeModel->ChronNumber;
		 }
	   }
	 }

   // --------- End transferring AGEMODEL metadata to NEOTOMAAGEMODEL  -----------

   if (TSSForm->AgeModelList->Count == 0) {
	 bool rv = true;
	 if (!ContainsText(TSSForm->Datasets[0].DatasetType, L"surface sample")) {
	   if (TSSForm->GeochronList->Count() > 0)
		 msg = L"Geochronolgy data entered but no Age Model entered";
	   else
		 msg = L"No Age Model entered";
	   OutputWarning(L"WARNING: " + msg + L".");
	   if (MessageDlg(msg + L"!", mtWarning, TMsgDlgButtons() << mbOK << mbAbort, 0) == mrAbort)
		 rv = false;
	   }
	 SetProgressBarPosition(3);
	 Screen->Cursor = crDefault;
	 return rv;
	 }

   // transfer everything from NeotomaAgeModels to NeotomaChrons
   vector<NTMCHRONOLOGY> NtmChrons;
   int CurrCollUnitID = -1;
   for (unsigned int i=0; i<NeotomaAgeModels.size(); i++) {
	 NEOTOMACHRONOLOGY NeotomaChron;
	 UnicodeString msgPrefix = L"Chron " + IntToStr(NeotomaAgeModels[i].ChronNumber);

	 NeotomaChron.CollectionUnitID = NeotomaAgeModels[i].CollUnitID;

	 if (NeotomaChron.CollectionUnitID > 0 && TSSForm->EPD.SiteID == -1) {
	   // this happens when either a new chron is being added to an existing collection unit
	   // or when sample ages from a new dataset are being added to an existing chron
	   // get existing chrons
	   if (NeotomaChron.CollectionUnitID != CurrCollUnitID) {
		 NeotomaChronologiesByCollUnitID Chronologies(ipsJSONS1, TcpClient1);
		 Chronologies.AddParam(L"COLLECTIONUNITID", NeotomaChron.CollectionUnitID);
		 StatusBar1->SimpleText = Chronologies.WebServiceName();
		 if (Chronologies.Execute()) {
		   NtmChrons = Chronologies.Items;
		   CurrCollUnitID = NeotomaChron.CollectionUnitID;
		   }
		 else
		   return false;
		 }

	   // assign temporary ChronologyID
	   bool found = false;
	   for (unsigned int j=0; j<NtmChrons.size(); j++) {
		 if (SameText(NeotomaAgeModels[i].ChronologyName, NtmChrons[j].ChronologyName)) {
		   NeotomaChron.ChronologyID = NtmChrons[j].ChronologyID;
		   found = true;
		   break;
		   }
		 }
	   if (found) {
	     TiliaChronIDs[NeotomaChron.ChronologyID] = NeotomaAgeModels[i].ChronNumber;
		 NeotomaChronIDs[NeotomaChron.ChronologyID] = NeotomaChron.ChronologyID;
		 msg = L"Chronology «" + NeotomaAgeModels[i].ChronologyName +
			   L"» = Neotoma ChronologyID " + NeotomaChron.ChronologyID + L".";
		 OutputLine(msg);
		 continue;
		 }
	   else if (NewAgeModel == NULL) {
		 msg = L"Chronology «" + NeotomaAgeModels[i].ChronologyName +
			   L"» does not exist in Neotoma. Check for exact chronology name matches.";
		 OutputWarning(L"WARNING: " + msg);
		 MessageDlg(msg, mtWarning, TMsgDlgButtons() << mbOK, 0);
		 }
	   }

	 NeotomaChron.ChronologyID = NextTempChronologyID();
	 TiliaChronIDs[NeotomaChron.ChronologyID] = NeotomaAgeModels[i].ChronNumber;

	 // Check that chronology has a name
	 if (NeotomaAgeModels[i].ChronologyName.IsEmpty()) {
	   msg = msgPrefix + L" does not have a name.";
	   OutputError(L"ERROR: " + msg);
	   if (MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbIgnore << mbAbort, 0) == mrAbort) {
		 Screen->Cursor = crDefault;
		 return false;
		 }
	   }
	 else
	   NeotomaChron.ChronologyName = NeotomaAgeModels[i].ChronologyName.Trim();

	 // get AgeTypeID
	 for (unsigned int j=0; j<NeotomaAgeTypes.size(); j++) {
	   if (SameText(NeotomaAgeModels[i].AgeUnits, NeotomaAgeTypes[j].AgeType)) {
		 NeotomaChron.AgeTypeID = NeotomaAgeTypes[j].AgeTypeID;
		 break;
		 }
	   }
	 if (NeotomaChron.AgeTypeID == -1) {
	   msg = msgPrefix + L" age units «" + NeotomaAgeModels[i].AgeUnits + L"» are not in the Neotoma AgeTypes table.";
	   OutputError(L"ERROR: " + msg);
	   if (MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbIgnore << mbAbort, 0) == mrAbort) {
		 Screen->Cursor = crDefault;
		 return false;
		 }
	   }
	 else  {// everything ok, output progress so far
	   OutputLine(msgPrefix + L": " + NeotomaChron.ChronologyName + L".");
	   OutputLine(msgPrefix + L": AgeTypeID = " + IntToStr(NeotomaChron.AgeTypeID) + L".");
	   }

	 // AgeModel
	 if (NeotomaAgeModels[i].AgeModel.IsEmpty()) {
	   msg = msgPrefix + L" does not have an age model.";
	   OutputError(L"ERROR: " + msg);
	   if (MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbIgnore << mbAbort, 0) == mrAbort) {
		 Screen->Cursor = crDefault;
		 return false;
		 }
	   }
	 else
	   NeotomaChron.AgeModel = NeotomaAgeModels[i].AgeModel.Trim();

	 // AgeBoundOlder & AgeBoundYounger
	 if (NeotomaAgeModels[i].AgeBoundOlder.IsEmpty() && NeotomaAgeModels[i].AgeBoundYounger.IsEmpty()) {
	   msg = msgPrefix + L" does not have age bounds.";
	   OutputError(L"ERROR: " + msg);
	   if (MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbIgnore << mbAbort, 0) == mrAbort) {
		 Screen->Cursor = crDefault;
		 return false;
		 }
	   }
	 else if (NeotomaAgeModels[i].AgeBoundOlder.IsEmpty()) {
	   msg = msgPrefix + L" does not have an older age bound.";
	   OutputError(L"ERROR: " + msg);
	   if (MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbIgnore << mbAbort, 0) == mrAbort) {
		 Screen->Cursor = crDefault;
		 return false;
		 }
	   }
	 else if (NeotomaAgeModels[i].AgeBoundYounger.IsEmpty()) {
	   msg = msgPrefix + L" does not have an younger age bound.";
	   OutputError(L"ERROR: " + msg);
	   if (MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbIgnore << mbAbort, 0) == mrAbort) {
		 Screen->Cursor = crDefault;
		 return false;
		 }
	   }
	 else {
	   NeotomaChron.AgeBoundOlder = (int)NeotomaAgeModels[i].AgeBoundOlder;
	   NeotomaChron.AgeBoundYounger = (int)NeotomaAgeModels[i].AgeBoundYounger;
	   bool error;
	   if (NeotomaChron.AgeTypeID == 1)   // AD/BC
		 error = (NeotomaChron.AgeBoundOlder > NeotomaChron.AgeBoundYounger);
	   else
		 error = (NeotomaChron.AgeBoundOlder < NeotomaChron.AgeBoundYounger);
	   if (error) {
		 msg = msgPrefix + L" AgeBoundOlder and AgeBoundYounger are reversed.";
		 OutputError(L"ERROR: " + msg);
		 if (MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbIgnore << mbAbort, 0) == mrAbort) {
		   Screen->Cursor = crDefault;
		   return false;
		   }
		 }
	   else {
		 OutputLine(msgPrefix + L": AgeBoundOlder = " + IntToStr((int)NeotomaChron.AgeBoundOlder));
		 OutputLine(msgPrefix + L": AgeBoundYounger = " + IntToStr((int)NeotomaChron.AgeBoundYounger));
		 }
	   }

	 // get preparer ContactID
	 if (NeotomaAgeModels[i].Preparers.size() == 0) {
	   msg = L"WARNING: No preparer designated for " + msgPrefix + L".";
	   OutputWarning(msg);
	   }
	 else if (NeotomaAgeModels[i].Preparers.size() > 1) {
	   msg = L"ERROR: " + msgPrefix +
			 L". At this time only one preparer can be designated for Neotoma.";
	   OutputError(msg);
	   }
	 else {
	   NeotomaChron.ContactID = NeotomaAgeModels[i].Preparers[0]->NeotomaContactID;
	   OutputLine(msgPrefix + L": Preparer ContactID = " + IntToStr(NeotomaChron.ContactID) + L".");
	   }

	 // date prepared
	 if (!NeotomaAgeModels[i].DatePrepared.IsEmpty() && !NeotomaAgeModels[i].DatePrepared.IsNull()) {
	   NeotomaChron.DatePrepared = NeotomaAgeModels[i].DatePrepared;
	   TDateTime date = NeotomaChron.DatePrepared;
	   OutputLine(msgPrefix + L": Date prepared: " + date.FormatString(L"yyyy-mm-dd"));
	   }

	 // notes
	 NeotomaChron.Notes = NeotomaAgeModels[i].Notes.Trim();

	 // default
	 NeotomaChron.IsDefault = NeotomaAgeModels[i].Default;
	 NeotomaChrons.push_back(NeotomaChron);
	 }
   SetProgressBarPosition();

   // validate ChronControls

   // get calibration curves and programs
   NeotomaCalibrationCurvesTable CalibCurves(ipsJSONS1, TcpClient1);
   NeotomaCalibrationProgramsTable CalibPrograms(ipsJSONS1, TcpClient1);

   multimap<int,UnicodeString> ChronControlTypes;   // ChronControlTypeID, ControlType
   set<int> GeochronControlTypeIDs;
   map<UnicodeString,vector<pair<int,CHRON> > > ChronTephras;  // tephra name, vector of ChronNo and ChronControl pairs
   for (unsigned int i=0; i<NeotomaChrons.size(); i++) {
     // continue if chronology already in Neotoma
	 if (NeotomaChrons[i].ChronologyID > 0)
	   continue;

	 int ChronNo = NeotomaAgeModels[i].ChronNumber;

	 int count = NeotomaAgeModels[i].ChronControls.size();
	 int ndepths = 0;
	 int nanalunits = 0;
	 for (int j=0; j<count; j++) {
	   CHRON& chron = NeotomaAgeModels[i].ChronControls[j];
	   if (!chron.Depth.IsEmpty())
		 ndepths++;
	   if (!chron.AnalUnit.IsEmpty())
		 nanalunits++;
	   }
	 if (ndepths != count && nanalunits != count) {
	   msg = L"Not all controls for Chron " + IntToStr(ChronNo) + L" are assigned depths or analysis units.";
	   OutputError(L"ERROR: " + msg);
	   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   Screen->Cursor = crDefault;
	   return false;
	   }

	 bool IDByDepth = (ndepths == count);

	 for (unsigned int j=0; j<NeotomaAgeModels[i].ChronControls.size(); j++) {
	   CHRON& ChronControl = NeotomaAgeModels[i].ChronControls[j];
	   NEOTOMACHRONCONTROL NeotomaChronControl;
	   // assign temporary ChronControlID
	   NeotomaChronControl.ChronControlID = NextTempChronControlID();

	   // see ChronControlTypeID if already in local list
	   if (ChronControlTypes.size() > 0) {
		 multimap<int,UnicodeString>::iterator itr;
		 for (itr = ChronControlTypes.begin(); itr != ChronControlTypes.end(); itr++) {
		   if (SameText(ChronControl.ControlType, itr->second)) {
			 NeotomaChronControl.ChronControlTypeID = itr->first;
			 if (ChronTephras.count(ChronControl.ControlType) == 1)
			   ChronTephras[ChronControl.ControlType].push_back(pair<int,CHRON>(ChronNo,ChronControl));
			 if (!ValidateChronControlAnalUnit(ChronNo, NeotomaChronControl, ChronControl, IDByDepth)) {
			   Screen->Cursor = crDefault;
			   return false;
			   }
			 break;
			 }
		   }
		 }

	   // if ChronControlTypeID not already in list...
	   if (NeotomaChronControl.ChronControlTypeID == -1) {    // B
		 bool found = false;
		 NeotomaChronControlTypeByName ChronControlType(ipsJSONS1, TcpClient1);
		 ChronControlType.AddParam(L"CHRONCONTROLTYPE", ChronControl.ControlType);
		 StatusBar1->SimpleText = ChronControlType.WebServiceName();
		 if (ChronControlType.Execute()) {
		   if (ChronControlType.Size() == 1) {
			 found = true;
			 NeotomaChronControl.ChronControlTypeID = ChronControlType.Items[0].ChronControlTypeID;
			 ChronControlTypes.insert(pair<int,UnicodeString>(NeotomaChronControl.ChronControlTypeID,ChronControl.ControlType));
			 if (IsGeochronControlType(NeotomaChronControl.ChronControlTypeID))
			   GeochronControlTypeIDs.insert(NeotomaChronControl.ChronControlTypeID);
			 if (!ValidateChronControlAnalUnit(ChronNo, NeotomaChronControl, ChronControl, IDByDepth)) {
			   Screen->Cursor = crDefault;
			   return false;
			   }
			 }
		   }
		 else {
		   Screen->Cursor = crDefault;
		   return false;
		   }

		 if (!found) {  // check if ChronControlType is an event
		   NeotomaEventChronControlTypeID Event(ipsJSONS1, TcpClient1);
		   Event.AddParam(L"EVENTNAME", ChronControl.ControlType);
		   StatusBar1->SimpleText = Event.WebServiceName();
		   if (Event.Execute()) {
			 if (Event.Size() == 1) {      // EventID, ChronControlTypeID
			   int EventID = Event.Items[0].first;
			   found = true;
			   NeotomaChronControl.ChronControlTypeID = Event.Items[0].second;
			   ChronControlTypes.insert(pair<int,UnicodeString>(NeotomaChronControl.ChronControlTypeID,ChronControl.ControlType));
			   if (!ValidateChronControlAnalUnit(ChronNo, NeotomaChronControl, ChronControl, IDByDepth)) {
				 Screen->Cursor = crDefault;
				 return false;
				 }
			   if (NeotomaChronControl.ChronControlTypeID == 3) {  // ChronControl is a tephra
				 int TephraAnalUnitID = NeotomaChronControl.AnalysisUnitID;
				 if (TephraAnalUnitID == -1) {
				   // see if tephra analysis unit already created for another chronology
				   if (NeotomaTephras.size() > 0) {
					 for (unsigned int k=0; k<NeotomaTephras.size(); k++) {
					   if (NeotomaTephras[k].EventID == EventID) {
						 TephraAnalUnitID = NeotomaTephras[k].AnalysisUnitID;
						 break;
						 }
					   }
					 }
				   }

				 if (TephraAnalUnitID == -1) {
				   // create AnalysisUnit for tephra
				   TephraAnalUnitID = NextTempAnalUnitID();
				   NEOTOMAANALUNIT AnalUnit;
				   AnalUnit.AnalysisUnitID = TephraAnalUnitID;
				   AnalUnit.Depth = ChronControl.Depth;
				   AnalUnit.Thickness = ChronControl.Thickness;
				   AnalUnit.AnalysisUnitName = ChronControl.ControlType;
				   AnalUnit.FaciesID = 46;

				   AnalUnit.CollectionUnitID = NeotomaAgeModels[i].CollUnitID;

				   NeotomaAnalysisUnits.push_back(AnalUnit);
				   msg = L"Analysis unit created for " + AnalUnit.AnalysisUnitName;
				   if (!ContainsText(AnalUnit.AnalysisUnitName, L"tephra"))
					 msg += L" tephra";
				   OutputLine(msg);
				   }

				 // check if AnalysisUnitID has been assigned to tephra ChronControl
				 if (NeotomaChronControl.AnalysisUnitID == -1)
				   NeotomaChronControl.AnalysisUnitID = TephraAnalUnitID;

				 // vector<NEOTOMATEPHRA> NeotomaTephras;
				 NEOTOMATEPHRA Tephra;
				 Tephra.EventID = EventID;
				 Tephra.AnalysisUnitID = TephraAnalUnitID;  // temp value, may need to create!
				 Tephra.Notes = NeotomaChronControl.Notes;
				 NeotomaTephras.push_back(Tephra);

				 // vector<NEOTOMAEVENTCHRONOLOGY> NetomaEventChronology;
				 NEOTOMAEVENTCHRONOLOGY EventChron;
				 EventChron.AnalysisUnitID = TephraAnalUnitID;  // temp value, may need to create!
				 EventChron.EventID = EventID;
				 EventChron.ChronControlID  = NeotomaChronControl.ChronControlID;  // temp value
				 EventChron.Notes = NeotomaChronControl.Notes;
				 NetomaEventChronology.push_back(EventChron);

				 // create set of ChronNumbers for tephra map
				 vector<pair<int,CHRON> > ChronControls;
				 ChronControls.push_back(pair<int,CHRON>(ChronNo,ChronControl));
				 ChronTephras[ChronControl.ControlType] = ChronControls;
				 }
			   else if (IsGeochronControlType(NeotomaChronControl.ChronControlTypeID))
				 GeochronControlTypeIDs.insert(NeotomaChronControl.ChronControlTypeID);
			   }
			 }
		   else {
			 Screen->Cursor = crDefault;
			 return false;
			 }
		   }

		 // multimap<int,UnicodeString> ChronControlTypes;   // ChronControlTypeID, ControlType
		 // ControlType = e.g. Geologic time scale, ChronControlTypeID = 60

		 if (!found) {  // check if ChronControlType is a relative age    // D
		   NeotomaRelativeAgeByName RelativeAge(ipsJSONS1, TcpClient1);
		   RelativeAge.AddParam(L"RELATIVEAGE", ChronControl.ControlType);
		   StatusBar1->SimpleText = RelativeAge.WebServiceName();
		   if (RelativeAge.Execute()) {    // E
			 if (RelativeAge.Size() == 1) { // relative age was found in the RelativeAges table  // F
			   int RelativeAgeID = RelativeAge.Items[0].RelativeAgeID;

               if (!ValidateChronControlAnalUnit(ChronNo, NeotomaChronControl, ChronControl, IDByDepth)) {
				 Screen->Cursor = crDefault;
				 return false;
				 }
			   if (NeotomaChronControl.AnalysisUnitID == -1) {
				 msg = L"Relative age «" + ChronControl.ControlType + L"» in Chron " +
					   IntToStr(ChronNo) + L" is not assigned to an analysis unit.";
                 OutputError(L"ERROR: " + msg);
				 if (MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbIgnore << mbAbort, 0) == mrAbort) {
				   Screen->Cursor = crDefault;
				   return false;
				   }
				 else
				   continue;
				 }

			   msg = L"Relative age «" + ChronControl.ControlType + L"» in Chron " +
					 IntToStr(ChronNo) + L" found in RelativeAges table, RelativeAgeID = " +
					 IntToStr(RelativeAgeID) + L".";
			   OutputLine(msg);

			   // first check if ChronControlType is in local ChronControlTypes list
			   if (ChronControlTypes.size() > 0) {
				 multimap<int,UnicodeString>::iterator itr;
				 for (itr = ChronControlTypes.begin(); itr != ChronControlTypes.end(); itr++) {
				   if (SameText(ChronControl.ControlType, itr->second)) {
					 NeotomaChronControl.ChronControlTypeID = itr->first;
					 break;
					 }
				   }
				 }

			   // if not, get the ChronControlTypeID for the RelativeAge, e.g. Geologic Time Scale
			   if (NeotomaChronControl.ChronControlTypeID == -1) {
				 NeotomaRelativeAgeChronControlType RelAgeChronControlType(ipsJSONS1, TcpClient1);
				 RelAgeChronControlType.AddParam(L"RELATIVEAGE", ChronControl.ControlType);
				 StatusBar1->SimpleText = RelAgeChronControlType.WebServiceName();
				 if (RelAgeChronControlType.Execute()) {
				   if (RelAgeChronControlType.Size() == 1) {
					 found = true;
					 NeotomaChronControl.ChronControlTypeID = RelAgeChronControlType.Items[0].first;
					 ChronControlTypes.insert(pair<int,UnicodeString>(NeotomaChronControl.ChronControlTypeID,ChronControl.ControlType));
					 msg = L"Relative age «" + ChronControl.ControlType + L"» is assigned to ChronControlType «" +
						   RelAgeChronControlType.Items[0].second + L"».";
					 OutputLine(msg);

					 // Insert NeotomaChronControl.AnalysisUnitID, RelativeAgeID, ChronControlID, and NeotomaChronControl.Notes into RelativeChronology table
					 NEOTOMARELAGE RelAge;
					 RelAge.RelativeAgeID = RelativeAgeID;
					 RelAge.AnalysisUnitID = NeotomaChronControl.AnalysisUnitID;   // = -1, will need to create!
					 RelAge.ChronControlID  = NeotomaChronControl.ChronControlID;  // = e.g. -1001, temp value
					 RelAge.Notes = NeotomaChronControl.Notes;
					 NeotomaRelAges.push_back(RelAge);
					 }
				   else {
					 msg = L"Relative age «" + ChronControl.ControlType + L"» is not assigned to a ChronControlType.";
					 OutputError(L"ERROR: " + msg);
					 if (MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbIgnore << mbAbort, 0) == mrAbort) {
					   Screen->Cursor = crDefault;
					   return false;
					   }
					 else
					   continue;
					 }
				   }
				 else {
				   Screen->Cursor = crDefault;
				   return false;
				   }
				 }
			   }   // F
			 else {
			   msg = L"Error: Relative age «" + ChronControl.ControlType + L"» in Chron " +
					 IntToStr(ChronNo) + L" not found in RelativeAges table";
			   OutputError(msg);
			   }
			 }    // E
		   }    // D

		 if (!found) {  // CronControlType not found
		   msg = L"ChronControl type «" + ChronControl.ControlType + L"» in Chron " +
				 IntToStr(ChronNo) + L" is not in the Neotoma ChronControlTypes table.";
		   OutputError(L"ERROR: " + msg);
		   if (MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbIgnore << mbAbort, 0) == mrAbort) {
			 Screen->Cursor = crDefault;
			 return false;
			 }
		   else
			 continue;
		   }
		 }

	   // AgeControlType
	   if (SameText(ChronControl.AgeUnits, L"Radiocarbon"))
		 NeotomaChronControl.AgeTypeID = 4;
	   else if (SameText(ChronControl.AgeUnits, L"Calendar"))
		 NeotomaChronControl.AgeTypeID = 2;
	   else {
		 msg = L"WARNING: No Age Units entered for ChronControl in Chron " + IntToStr(ChronNo) + L".";
		 OutputWarning(msg);
		 }

       // depths or named analysis units?
	   UnicodeString what;
	   if (!ChronControl.Depth.IsEmpty())
		 what = L"«Depth " + FloatToStr((double)NeotomaChronControl.Depth) + L"»";
	   else
		 what = L"Analysis Unit «" + ChronControl.AnalUnit + L"»";

	   // age
	   if (!ChronControl.AgeValue.IsEmpty())
		 NeotomaChronControl.Age = ChronControl.AgeValue;

	   if (!ChronControl.AgeLimitOlder.IsEmpty())
		 NeotomaChronControl.AgeLimitOlder = ChronControl.AgeLimitOlder;

	   if (!ChronControl.AgeLimitYounger.IsEmpty())
		 NeotomaChronControl.AgeLimitYounger = ChronControl.AgeLimitYounger;

	   bool age_error = false;
	   if (NeotomaChronControl.AgeLimitOlder.IsEmpty() && !ChronControl.AgeLimitYounger.IsEmpty()) {
		 age_error = true;
		 msg = L"AgeLimitOlder not set for Chron " + IntToStr(ChronNo) +
			   L", " + what + L".";
		 }
	   else if (!NeotomaChronControl.AgeLimitOlder.IsEmpty() && ChronControl.AgeLimitYounger.IsEmpty()) {
		 age_error = true;
		 msg = L"AgeLimitYounger not set for Chron " + IntToStr(ChronNo) +
			   L", " + what + L".";
		 }
	   else if (NeotomaChronControl.Age.IsEmpty() && NeotomaChronControl.AgeLimitOlder.IsEmpty() &&
				ChronControl.AgeLimitYounger.IsEmpty()) {
		 age_error = true;
		 msg = L"Neither age nor age limits set for Chron " + IntToStr(ChronNo) +
			   L", " + what + L".";
		 }

	   // if AgeLimitOlder and AgeLimitYounger set, check that AgeLimitOlder >= AgeLimitYounger
	   if (!age_error) {
		 if (!NeotomaChronControl.AgeLimitOlder.IsEmpty() && !NeotomaChronControl.AgeLimitYounger.IsEmpty()) {
		   double AgeLimitOlder = NeotomaChronControl.AgeLimitOlder;
		   double AgeLimitYounger = NeotomaChronControl.AgeLimitYounger;

           // get AgeTypeID
		   int AgeTypeID;
		   for (unsigned int j=0; j<NeotomaAgeTypes.size(); j++) {
			 if (SameText(NeotomaAgeModels[i].AgeUnits, NeotomaAgeTypes[j].AgeType)) {
			   AgeTypeID = NeotomaAgeTypes[j].AgeTypeID;
			   break;
			   }
			 }

		   if ((AgeTypeID == 1 && AgeLimitOlder > AgeLimitYounger) ||    // AD/BC
			   (AgeTypeID != 1 && AgeLimitOlder < AgeLimitYounger)) {
			 msg = L"Older and younger age limits are reversed for Chron " + IntToStr(ChronNo) +
			   L", " + what + L".";
             age_error = true;
			 }
		   }
		 }

	   if (age_error) {
		 OutputError(L"ERROR: " + msg);
		 if (MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbIgnore << mbAbort, 0) == mrAbort) {
		   Screen->Cursor = crDefault;
		   return false;
		   }
		 }

	   // notes
	   NeotomaChronControl.Notes = ChronControl.Notes;
	   //OutputLine(L"Notes: " + NeotomaChronControl.Notes);

	   // calibration curve
	   if (!ChronControl.CalibCurve.IsEmpty()) {
		 if (CalibCurves.Size() == 0) {
		   StatusBar1->SimpleText = CalibCurves.WebServiceName();
		   if (!CalibCurves.Execute()) {
			 Screen->Cursor = crDefault;
			 return false;
			 }
		   }
		 for (unsigned int k=0; k<CalibCurves.Size(); k++) {
		   if (SameText(ChronControl.CalibCurve, CalibCurves.Items[k].CalibrationCurve)) {
			 NeotomaChronControl.CalibrationCurveID = CalibCurves.Items[k].CalibrationCurveID;
			 break;
			 }
		   }
		 if (NeotomaChronControl.CalibrationCurveID == -1) {
		   msg = L"Calibration curve «" + ChronControl.CalibCurve +
				 L"» for Chron " + IntToStr(ChronNo) + L", Chron Control " + what +
				 L" is not in the Neotoma CalibrationCurves table.";
		   OutputError(L"ERROR: " + msg);
		   if (MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbIgnore << mbAbort, 0) == mrAbort) {
			 Screen->Cursor = crDefault;
			 return false;
			 }
		   }
		 }

	   // calibration programs
	   if (!ChronControl.Calib.Program.IsEmpty()) {
		 if (CalibPrograms.Size() == 0) {
		   StatusBar1->SimpleText = CalibPrograms.WebServiceName();
		   if (!CalibPrograms.Execute()) {
			 Screen->Cursor = crDefault;
			 return false;
			 }
		   }
		 for (unsigned int k=0; k<CalibPrograms.Size(); k++) {
		   if (SameText(ChronControl.Calib.Program, CalibPrograms.Items[k].CalibrationProgram) &&
			   SameText(ChronControl.Calib.Version, CalibPrograms.Items[k].Version)) {
			 NeotomaChronControl.CalibrationProgramID = CalibPrograms.Items[k].CalibrationProgramID;
			 break;
			 }
		   }
		 if (NeotomaChronControl.CalibrationProgramID == -1) {
		   msg = L"Calibration program «" + ChronControl.Calib.Program;
		   if (!ChronControl.Calib.Version.IsEmpty())
			 msg += (L" " + ChronControl.Calib.Version);
		   msg += L"» for Chron " + IntToStr(ChronNo) + L", Chron Control " + what +
			 L" is not in the Neotoma CalibrationPrograms table.";
		   OutputError(L"ERROR: " + msg);
		   if (MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbIgnore << mbAbort, 0) == mrAbort) {
			 Screen->Cursor = crDefault;
			 return false;
			 }
		   }
		 }

	   // get GeoChronIDs
	   if (ChronControl.GeochronIDs.size() > 0) {
		 for (unsigned int k=0; k<ChronControl.GeochronIDs.size(); k++) {
		   int ID = ChronControl.GeochronIDs[k];
		   int GeochronID = -1;
		   for (unsigned int n=0; n<NeotomaGeochrons.size(); n++) {
			 if (ID == NeotomaGeochrons[n].TiliaID) {
			   GeochronID = NeotomaGeochrons[n].GeochronID;
			   break;
			   }
			 }
		   if (GeochronID != -1) {
			 NeotomaChronControl.GeoChronIDs.push_back(GeochronID);
			 //OutputLine(L"GeochronID = " + IntToStr(GeochronID));  // temp for testing
			 }
		   else {  // GeochronID no longer in geochrons
			 msg = L"Geochronology link for Chron " + IntToStr(ChronNo) +
			   L", Chron Control " + what + L" is not in the Geochronology tab sheet.";
			 OutputError(L"ERROR: " + msg);
			 if (MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbIgnore << mbAbort, 0) == mrAbort) {
			   Screen->Cursor = crDefault;
			   return false;
			   }
			 }
		   }
		 }
	   else if (GeochronControlTypeIDs.count(NeotomaChronControl.ChronControlTypeID) > 0) {
		 msg = L"WARNING: Geochronology links not set for Chron " + IntToStr(ChronNo) +
		   L", Chron Control " + what + L".";
		 OutputWarning(msg);
		 }
	   NeotomaChrons[i].ChronControls.push_back(NeotomaChronControl);

	   // this added to account for relative ages for newly added chronologies
	   if (NeotomaAnalUnitIDs.count(NeotomaChronControl.AnalysisUnitID) == 0)
		 NeotomaAnalUnitIDs[NeotomaChronControl.AnalysisUnitID] = NeotomaChronControl.AnalysisUnitID;
	   }
	 }

   // check for consistency in tephra analysis units that were added from chrons
   if (ChronTephras.size() > 0) {
	 map<UnicodeString,vector<pair<int,CHRON> > >::iterator itr;
	 for (itr = ChronTephras.begin(); itr != ChronTephras.end(); itr++) {
	   if (itr->second.size() > 1) {
		 for (unsigned int i = 1; i<itr->second.size(); i++) {
		   if (itr->second[i].second.Depth != itr->second[0].second.Depth ||
			   itr->second[i].second.Thickness != itr->second[0].second.Thickness) {
			 msg = L"ERROR: Analysis unit for " + itr->first +
				   L" tephra differs in depth or thickness in Chronologies " +
				   IntToStr(itr->second[0].first) + L" and " +
				   IntToStr(itr->second[i].first) + L".";
			 OutputError(msg);
			 }
		   }
		 }
	   }
	 }


   //if (NewAgeModel != NULL) {
   //	  OutputLine(L"New age model validation completed.");
   //	  return true;
   //	  }

   Screen->Cursor = crDefault;
   StatusBar1->SimpleText = L"";
   SetProgressBarPosition();
   return true;
}
//---------------------------------------------------------------------------

bool TNeotomaUploadForm::ValidateMultiAnalUnits(AGEMODEL* AgeModel)
{
   for (int j=0; j<AgeModel->ChronControls->Count; j++) {
	 CHRON* ChronControl = (CHRON*)AgeModel->ChronControls->Items[j];
	 if (ChronControl->AnalUnit.IsEmpty()) {
	   UnicodeString msg = L"For multi site or multi collection unit datasets, ";
	   msg += L"geochron samples must be assigned to analysis units in the spreadsheet.";
	   OutputError(L"ERROR: " + msg);
	   Screen->Cursor = crDefault;
	   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return false;
	   }
	 }
   return true;
}
//---------------------------------------------------------------------------

bool TNeotomaUploadForm::TransferAgeModelToNeotomaAgeModel(AGEMODEL* AgeModel, int& NewChronNo)
{
   UnicodeString msg;
   vector<pair<int,int> > CollUnitAgeModels;  // OldChronNo, CollUnitID
   //int NewChronNo = 1;

   for (int j=0; j<AgeModel->ChronControls->Count; j++) {
	 CHRON* ChronControl = (CHRON*)AgeModel->ChronControls->Items[j];

	 bool found = false;
	 for (unsigned int k=0; k<NeotomaAnalysisUnits.size(); k++) {
	   if (!ChronControl->AnalUnit.IsEmpty()) {
		 if (SameText(ChronControl->AnalUnit, NeotomaAnalysisUnits[k].AnalysisUnitName)) {
		   found = true;
		   ChronControl->NeotomaAnalUnitID = NeotomaAnalysisUnits[k].AnalysisUnitID;
		   break;
		   }
		 }
	   }
	 if (!found) {
	   msg = L"ERROR: Chron " + IntToStr(AgeModel->ChronNumber) +
			 L" in the Chronologies tabsheet has controls not linked to any analysis unit.";
	   OutputError(msg);
	   return false;
	   }

	 // unique combination is original ChronNo, collection unit
	 int CurChronNo;
	 int OldChronNo = AgeModel->ChronNumber;
	 int CollUnitID = FindCollUnitID(ChronControl->NeotomaAnalUnitID);
	 pair<int,int> CollUnitAgeModel(OldChronNo,CollUnitID);
	 vector<pair<int,int> >::iterator itr =
	   find(CollUnitAgeModels.begin(), CollUnitAgeModels.end(), CollUnitAgeModel);
	 unsigned int aidx;
	 if (itr == CollUnitAgeModels.end()) {
	   CollUnitAgeModels.push_back(CollUnitAgeModel);
	   CurChronNo = NewChronNo++;
	   NeotomaChronNoMap[CollUnitAgeModel] = CurChronNo;
	   NEOTOMAAGEMODEL NeotomaAgeModel(CurChronNo, AgeModel, NULL);
	   CHRON ChronControlCopy(ChronControl);
	   NeotomaAgeModel.ChronControls.push_back(ChronControlCopy);
	   NeotomaAgeModel.CollUnitID = CollUnitID;
	   NeotomaAgeModels.push_back(NeotomaAgeModel);
	   aidx = NeotomaAgeModels.size() - 1;
	   }
	 else {
	   CurChronNo = NeotomaChronNoMap[CollUnitAgeModel];
	   for (unsigned int j=0; j<NeotomaAgeModels.size(); j++) {
		 if (NeotomaAgeModels[j].ChronNumber == CurChronNo) {
		   CHRON ChronCongrolCopy(ChronControl);
		   NeotomaAgeModels[j].ChronControls.push_back(ChronCongrolCopy);
		   aidx = j;
		   break;
		   }
		 }
	   }

	 if (OldChronNo != CurChronNo) {
	   msg = L"Chron " + IntToStr(OldChronNo) + L" changed to Chron " + IntToStr(CurChronNo) +
			 L" for Collection Unit " + IntToStr(CollUnitID);
	   OutputLine(msg);
	   }

	 CHRON& NewChronControl = NeotomaAgeModels[aidx].ChronControls.back();
	 msg = L"Chron " + IntToStr(CurChronNo) + L": ChronControl «" +
		   NewChronControl.AnalUnit + L"», CollUnitID = " + IntToStr(CollUnitID) +
		   L", AnalysisUnitID = " + IntToStr(NewChronControl.NeotomaAnalUnitID);
	 OutputLine(msg);
	 }
   return true;
}
//---------------------------------------------------------------------------

bool TNeotomaUploadForm::IsGeochronControlType(int ChronControlTypeID)
{
   bool rv = false;
   NeotomaChronControlTypeHighestID ChronControlType(ipsJSONS1, TcpClient1);
   ChronControlType.AddParam(L"CHRONCONTROLTYPEID", ChronControlTypeID);
   StatusBar1->SimpleText = ChronControlType.WebServiceName();
   if (ChronControlType.Execute()) {
	 if (ChronControlType.Size() == 1) {
	   if (SameText(ChronControlType.Items[0].ChronControlType, L"Geochronologic"))
		 rv = true;
	   }
	 }
   return rv;
}
//---------------------------------------------------------------------------

bool TNeotomaUploadForm::ValidateChronControlAnalUnit(int ChronNo, NEOTOMACHRONCONTROL& NeotomaChronControl,
	CHRON& ChronControl, bool IDByDepth)
{
   UnicodeString msg;

   if (IDByDepth) {      // ages identified by depth, true if all chron controls have a depth
	 NeotomaChronControl.Depth = ChronControl.Depth;
	 if (!ChronControl.Thickness.IsEmpty()) {
	   NeotomaChronControl.Thickness = ChronControl.Thickness;
	   // check if analysis unit with same depth and thickness exists
	   for (unsigned int k=0; k<NeotomaAnalysisUnits.size(); k++) {
		 if (NeotomaChronControl.Depth == NeotomaAnalysisUnits[k].Depth &&
			 NeotomaChronControl.Thickness == NeotomaAnalysisUnits[k].Thickness) {
		   NeotomaChronControl.AnalysisUnitID = NeotomaAnalysisUnits[k].AnalysisUnitID;
		   break;
		   }
		 }
	   }
	 }
   else {   // Analysis Unit
	 if (!ChronControl.AnalUnit.IsEmpty()) {
	   for (unsigned int k=0; k<NeotomaAnalysisUnits.size(); k++) {
		 if (SameText(ChronControl.AnalUnit, NeotomaAnalysisUnits[k].AnalysisUnitName)) {
		   NeotomaChronControl.AnalysisUnitID = NeotomaAnalysisUnits[k].AnalysisUnitID;
		   break;
		   }
		 }
	   if (NeotomaChronControl.AnalysisUnitID == -1) {   // analysis unit not found in spreadsheet
		 msg = L"Analysis Unit «" + ChronControl.AnalUnit + L"» in Chron " +
			   IntToStr(ChronNo) + L" does not exist in row 2 of the spreadsheet.";
		 OutputError(L"ERROR: " + msg);
		 if (MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbIgnore << mbAbort, 0) == mrAbort)
		   return false;
		 }
	   }
	 else {
	   msg = L"Analysis unit not entered for Chron " + IntToStr(ChronNo) + L" .";
	   OutputError(L"ERROR: " + msg);
	   if (MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbIgnore << mbAbort, 0) == mrAbort)
		 return false;
	   }
	 }

   return true;
}
//---------------------------------------------------------------------------

bool TNeotomaUploadForm::ValidateSampleAges(void)
{
   UnicodeString msg;
   UnicodeString NumStr, Suffix;
   int ChronNo;
   short age_param;
   int AnalUnitID;
   int AccRateUnitsID = -1;
   bool rv = true;

   Screen->Cursor = crHourGlass;

   // get multimap of columns and samples: needs to be multimap because a single
   // column may have more than one sample (e.g. pollen and macrofossil)

   try {
   multimap<int,int> SampleCols;  // column, sample
   map<int,int> CollUnitCols;     // column, CollUnit   // new
   for (unsigned int i=0; i<NeotomaSamples.size(); i++) {
	 if (NeotomaSamples[i].col > -1) {     // to avoid geochron taxa dated
	   SampleCols.insert(pair<int,int>(NeotomaSamples[i].col, NeotomaSamples[i].SampleID));
	   CollUnitCols[NeotomaSamples[i].col] = NeotomaSamples[i].CollUnitID;   // new
	   }
	 }

   // pair<int,int> CollUnitAgeModel(AgeModel->ChronNumber,CollUnitID);
   // NeotomaChronNoMap[CollUnitAgeModel] = AgeModel->ChronNumber;

   set<int> OrigChronNos;
   for (map<pair<int,int>,int>::iterator it = NeotomaChronNoMap.begin(); it != NeotomaChronNoMap.end(); it++) {
	 int OrigChronNo = it->first.first;
	 OrigChronNos.insert(OrigChronNo);
	 }

   multimap<int,int>::iterator itr;
   multimap<int,int>::iterator begin = SampleCols.begin();
   multimap<int,int>::iterator end = SampleCols.end();

   int StartRow = TSSForm->AbsHeaderRowCount(TSSForm->ProfGrid1);
   int RowCount = TSSForm->AbsContentRowCount(TSSForm->ProfGrid1);

   bool errors = false;
   int nages = 0;
   for (int row=StartRow; row<=RowCount; row++) {
	 UnicodeString Code = TSSForm->ProfGrid1->AbsoluteCells[1][row]->Text;
	 if (SameText(Code.SubString(1,6), L"#Chron")) {
	   bool error = false;
	   Code.Delete(1,6);
	   if (!Code.IsEmpty()) {
		 int idx = Code.Pos(L".");
		 if (idx == 0)  { // no period
		   NumStr = Code;
		   Suffix = L"";
		   }
		 else {
		   NumStr = Code.SubString(1,idx-1);
		   Suffix = Code.Delete(1,idx);
		   }
		 if (TryStrToInt(NumStr,ChronNo)) {
		   if (OrigChronNos.count(ChronNo) == 0) {
			 msg = TSSForm->ProfGrid1->AbsoluteCells[1][row]->Text +
			   L" in the spreadsheet does not have a matching Chron No. in the Age Models tabsheet.";
			 OutputError(L"ERROR: " + msg);
			 if (MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbIgnore << mbAbort, 0) == mrAbort)
			   return (rv = false);
			 continue;
			 }

		   if (Suffix.IsEmpty())
			 age_param = 1;
		   else if (SameText(Suffix, L"Young"))
			 age_param = 2;
		   else if (SameText(Suffix, L"Old"))
			 age_param = 3;
		   else if (SameText(Suffix, L"Acc.Rate"))
			 age_param = 4;
		   else
			 error = true;

		   if (!error) {
			 for (itr = begin; itr != end; itr++) {  // iterate through all sample cols
			   int col = itr->first;
			   int SampleID = itr->second;
			   TProfGridCell* ACell = TSSForm->ProfGrid1->AbsoluteCells[col][row];
			   if (ACell->Value.Type() == varDouble || ACell->Value.Type() == varInteger) {
				 double aVal = (double)ACell->Value;
				 int NewChronNo = ChronNo;

				 pair<int,int> CollUnitAgeModel(ChronNo,CollUnitCols[col]);
				 if (NeotomaChronNoMap.count(CollUnitAgeModel) > 0)
				   NewChronNo = NeotomaChronNoMap[CollUnitAgeModel];

				 if (NeotomaSampleAges.count(NewChronNo) > 0) {
				   if (NeotomaSampleAges[NewChronNo].count(SampleID) == 0) {
					 NEOTOMAAGE Age;
					 NeotomaSampleAges[NewChronNo][SampleID] = Age;
					 }
				   }
				 else {  // == 0
				   NEOTOMASAMPLEAGE SampleAge;
				   NeotomaSampleAges[NewChronNo] = SampleAge;
				   NEOTOMAAGE Age;
				   NeotomaSampleAges[NewChronNo][SampleID] = Age;
				   }

				 switch (age_param) {
				   case 1:  // age
					 NeotomaSampleAges[NewChronNo][SampleID].Age = aVal;
					 nages++;
					 break;
				   case 2:  // younger
					 NeotomaSampleAges[NewChronNo][SampleID].AgeYounger = aVal;
					 nages++;
					 break;
				   case 3:  // older
					 NeotomaSampleAges[NewChronNo][SampleID].AgeOlder = aVal;
					 nages++;
					 break;
				   case 4: // acc.rate
					 if (AnalUnitID != 0) {
					   AnalUnitID = FindAnalUnitID(SampleID);
					   if (AnalUnitID != -1) {
						 if (AccRateUnitsID == -1) {
						   UnicodeString units = TSSForm->ProfGrid1->AbsoluteCells[4][row]->Text;
						   if (SameText(units,L"yr/cm"))
							 AccRateUnitsID = 115;
						   else if (SameText(units,L"yr/m"))
							 AccRateUnitsID = 116;
						   else {
							 AccRateUnitsID = 0;
							 msg = L"Units «" + units + L"» not valid for accumulation rate. Must be «cm/yr» or «m/yr».";
							 OutputError(L"ERROR: " + msg);
							 if (MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbIgnore << mbAbort, 0) == mrAbort)
							   return (rv = false);
							 }
						   }
						 ACCRATE AccRate(AnalUnitID, NewChronNo, aVal, AccRateUnitsID);
						 if (find(AccRates.begin(),AccRates.end(),AccRate) == AccRates.end())
						   AccRates.push_back(AccRate);
						 }
					   }
					 break;
				   }
				 }
			   else if (!ACell->IsEmpty()) {
				 InvalidSSNumber(col, row, L"for " + TSSForm->ProfGrid1->AbsoluteCells[1][row]->Text, msg);
				 OutputError(L"ERROR: " + msg);
				 if (MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbIgnore << mbAbort, 0) == mrAbort)
				   return (rv = false);
				 }
			   }
			 }
		   }
		 else
		   error = true;
		 }
	   else
		 error = true;

	   if (error) {
		 errors = true;
		 msg = L"Chron code " + TSSForm->ProfGrid1->AbsoluteCells[1][row]->Text +
			   L" is not valid.";
		 OutputError(L"ERROR: " + msg);
		 if (MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbIgnore << mbAbort, 0) == mrAbort)
		   return (rv = false);
		 }
	   }
	 }

   if (!errors && nages == 0) {
	 if (NeotomaAgeModels.size() > 0 && !GeochronOnly) {
	   msg = L"Age model has been entered, but no sample ages are entered in the spreadsheet.";
	   OutputWarning(L"WARNING: " + msg);
	   if (MessageDlg(msg, mtWarning, TMsgDlgButtons() << mbOK << mbAbort, 0) == mrAbort)
		 return (rv = false);
	   }
	 }

   // map<int,int> SampleCols;  // column, sample
   // map<int,NEOTOMASAMPLEAGE> NeotomaSampleAges;  // ChronNo, SampleAge
   // check for inconsistencies in AgeOlder and AgeYounger
   if (!errors) {
	 map<int,int> ColSamples;
	 for (itr = begin; itr != end; itr++)   // iterate through all sample cols
	   ColSamples[itr->second] = itr->first;   // sample, column

	 map<int,NEOTOMASAMPLEAGE>::iterator chron_itr;
	 map<int,NEOTOMASAMPLEAGE>::iterator chron_begin = NeotomaSampleAges.begin();
	 map<int,NEOTOMASAMPLEAGE>::iterator chron_end = NeotomaSampleAges.end();

	 for (chron_itr = chron_begin; chron_itr != chron_end; chron_itr++) {
	   map<int,NEOTOMAAGE>::iterator samp_itr;
	   map<int,NEOTOMAAGE>::iterator samp_begin = chron_itr->second.begin();
	   map<int,NEOTOMAAGE>::iterator samp_end = chron_itr->second.end();
	   for (samp_itr = samp_begin; samp_itr != samp_end; samp_itr++) {
		 int SampleID = samp_itr->first;
		 if (!IsNan(samp_itr->second.AgeYounger)) {
		   if (IsNan(samp_itr->second.AgeOlder)) {
			 msg = L"AgeOlder is missing in column " +
			   TSSForm->ProfGrid1->AbsoluteCols[ColSamples[SampleID]]->A1Name + L".";
			 OutputError(L"ERROR: " + msg);
			 if (MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbIgnore << mbAbort, 0) == mrAbort)
			   return (rv = false);
			 continue;
			 }
		   }
		 if (!IsNan(samp_itr->second.AgeOlder)) {
		   if (IsNan(samp_itr->second.AgeYounger)) {
			 msg = L"AgeYounger is missing in column " +
			   TSSForm->ProfGrid1->AbsoluteCols[ColSamples[SampleID]]->A1Name + L".";
			 OutputError(L"ERROR: " + msg);
			 if (MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbIgnore << mbAbort, 0) == mrAbort)
			   return (rv = false);
			 continue;
			 }
		   }
		 // vector<NEOTOMACHRONOLOGY> NeotomaChrons;
		 //	map<int,NEOTOMASAMPLEAGE> NeotomaSampleAges;  // map<ChronNo, map<SampleID,NEOTOMAAGE> >
		 if (!IsNan(samp_itr->second.AgeYounger) && !IsNan(samp_itr->second.AgeOlder)) {
		   int AgeTypeID = -1;
		   for (unsigned int i=0; i<NeotomaChrons.size(); i++) {
			 if (chron_itr->first == TiliaChronIDs[NeotomaChrons[i].ChronologyID]) {
			   AgeTypeID = NeotomaChrons[i].AgeTypeID;
			   break;
			   }
			 }
		   bool error;
		   if (AgeTypeID == 1)   // AD/BC
			 error = (samp_itr->second.AgeOlder > samp_itr->second.AgeYounger);
		   else
			 error = (samp_itr->second.AgeOlder < samp_itr->second.AgeYounger);
		   if (error) {
			 msg = L"AgeYounger and AgeOlder are reversed in column " +
			   TSSForm->ProfGrid1->AbsoluteCols[ColSamples[SampleID]]->A1Name + L".";
			 OutputError(L"ERROR: " + msg);
			 if (MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbIgnore << mbAbort, 0) == mrAbort)
			   return (rv = false);
			 continue;
			 }
		   }
		 if (!IsNan(samp_itr->second.Age) && !IsNan(samp_itr->second.AgeYounger) && !IsNan(samp_itr->second.AgeOlder)) {
		   if (samp_itr->second.Age < samp_itr->second.AgeYounger || samp_itr->second.Age > samp_itr->second.AgeOlder) {
			 msg = L"Chron" + IntToStr(chron_itr->first) + L" age «" + FloatToStr(samp_itr->second.Age) +
			   L"» falls outside the AgeYounger-AgeOlder range «" + FloatToStr(samp_itr->second.AgeOlder) + L"-" +
			   FloatToStr(samp_itr->second.AgeYounger) + L"» in column " +
			   TSSForm->ProfGrid1->AbsoluteCols[ColSamples[SampleID]]->A1Name + L".";
			 OutputError(L"ERROR: " + msg);
			 if (MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbIgnore << mbAbort, 0) == mrAbort)
			   return (rv = false);
			 }
		   }
		 }
	   }

	 bool done;
	 do {
		done = true;
		for (unsigned int i=0; i<NeotomaChrons.size(); i++) {
		  int ChronNo = TiliaChronIDs[NeotomaChrons[i].ChronologyID];
		  if (NeotomaSampleAges.count(ChronNo) == 0) {
			msg = L"Chron" + IntToStr(ChronNo) +
			  L" in the Age Models tabsheet does not have ages in the spreadsheet and will not be uploaded.";
			OutputWarning(L"WARNING: " + msg);
			if (MessageDlg(msg, mtWarning, TMsgDlgButtons() << mbIgnore << mbAbort, 0) == mrAbort)
			  return (rv = false);
			NeotomaChrons.erase(NeotomaChrons.begin()+i);
			done = false;
			break;
			}
		  }
	   } while(!done);
	 }

   // check for surface samples
   if (!errors) {
	 for (unsigned int i=0; i<TSSForm->Datasets.size(); i++) {
	   UnicodeString DatasetType = TSSForm->Datasets[i].DatasetType;
	   if (!GeochronOnly && !TSSForm->Datasets[i].IsSSamp &&
		   !ContainsText(DatasetType, L"surface") &&
		   (ContainsText(DatasetType, L"pollen") ||
			ContainsText(DatasetType, L"ostracode") ||
			ContainsText(DatasetType, L"diatom"))) {
		 msg = L"NOTE: Top sample of «" + TSSForm->Datasets[i].DatasetType +
			   L"» dataset is not designated as a modern surface sample in the Dataset form";
		 OutputNote(msg);
		 }
	   }
	 }
	 }
   __finally {
	 Screen->Cursor = crDefault;
	 StatusBar1->SimpleText = L"";
	 SetProgressBarPosition();
	 }
   return rv;
}
//---------------------------------------------------------------------------

int TNeotomaUploadForm::FindAnalUnitID(int SampleID)
{
   for (unsigned int i=0; i<NeotomaSamples.size(); i++) {
	 if (SampleID == NeotomaSamples[i].SampleID)
	   return NeotomaSamples[i].AnalysisUnitID;
	 }
   return -1;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

_fastcall TNeotomaUploadChronForm::TNeotomaUploadChronForm(AGEMODEL* age_model, TComponent* Owner)
	: TNeotomaUploadForm(Owner)
{
   AgeModel = age_model;
   cxButton2->Visible = false;
   Fvalidation_aborted = false;
   success = false;
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaUploadChronForm::FormCreate(TObject *Sender)
{
   Step = 0;
   nSteps = 3;
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaUploadChronForm::FormActivate(TObject *Sender)
{
   if (!Activated) {
	 Activated = true;
	 Validate();
	 }
}
//---------------------------------------------------------------------------

void TNeotomaUploadChronForm::Validate(void)
{
   if (!RunValidation()) {
	 OutputError(L"VALIDATION ABORTED");
	 Fvalidation_aborted = true;
	 }
   cxButton3->Visible = true;
   cxButton1->Visible = true;
   cxButton4->Visible = true;
   SetProgressBar(CORE);
}
//---------------------------------------------------------------------------

bool TNeotomaUploadChronForm::RunValidation(void)
{
   UnicodeString msg;
   double Age, Depth, Thickness;
   vector<int> DatasetRows;

   // check that chron controls exist for new chron
   if (AgeModel->ChronControls->Count == 0) {
	  OutputError(L"ERROR: Chronolgy does not have any chronolgy controls.");
	  return false;
	  }

   UnicodeString ChronCode = L"#Chron" + IntToStr(AgeModel->ChronNumber);
   UnicodeString ChronCodeYoung = ChronCode + L".Young";
   UnicodeString ChronCodeOld = ChronCode + L".Old";
   chron_row = 0;
   chron_row_young = 0;
   chron_row_old = 0;
   int RowCount = TSSForm->AbsContentRowCount(TSSForm->ProfGrid1);
   int ColCount = TSSForm->AbsContentColCount(TSSForm->ProfGrid1);
   int HeaderCols = TSSForm->AbsHeaderColCount(TSSForm->ProfGrid1);
   bool chron_found = false;
   bool chron_value = false;

   // get chron and dataset rows
   //DatasetRows.push_back(0);
   DatasetRows.push_back(1);
   for (int row=3; row <= RowCount; row++) {
	 UnicodeString VarCode = TSSForm->ProfGrid1->AbsoluteCells[1][row]->Text;
	 if (SameText(ChronCode, VarCode))
	   chron_row = row;
	 else if (SameText(ChronCodeYoung, VarCode))
	   chron_row_young = row;
	 else if (SameText(ChronCodeOld, VarCode))
	   chron_row_old = row;
	 else if (SameText(L"#Data.Type", VarCode))
	   DatasetRows.push_back(row);
	 }

   if (chron_row > 0 || (chron_row_young > 0 && chron_row_old > 0)) {
	 chron_found = true;
	 for (int col=HeaderCols; col<=ColCount; col++) {
	   NEOTOMAAGE NeotomaAge;
	   UnicodeString AgeText;
	   int error_row = 0;

	   if (chron_row > 0) {
		 AgeText = TSSForm->ProfGrid1->AbsoluteCells[col][chron_row]->Text;
		 if (!AgeText.IsEmpty()) {
		   if (TryStrToFloat(AgeText, Age))
			 NeotomaAge.Age = Age;
		   else
			 error_row = chron_row;
		   }
		 }
	   if (error_row == 0 && chron_row_young > 0) {
		 AgeText = TSSForm->ProfGrid1->AbsoluteCells[col][chron_row_young]->Text;
		 if (!AgeText.IsEmpty()) {
		   if (TryStrToFloat(AgeText, Age))
			 NeotomaAge.AgeYounger = Age;
		   else
			 error_row = chron_row_young;
		   }
		 }
	   if (error_row == 0 && chron_row_old > 0) {
		 AgeText = TSSForm->ProfGrid1->AbsoluteCells[col][chron_row_old]->Text;
		 if (!AgeText.IsEmpty()) {
		   if (TryStrToFloat(AgeText, Age))
			 NeotomaAge.AgeOlder = Age;
		   else
			 error_row = chron_row_old;
		   }
		 }
	   if (error_row > 0) {
		 msg = L"Value in cell " + TSSForm->ProfGrid1->AbsoluteCells[col][error_row]->A1Name +
			   L" is not a valid number.";
		 OutputError(msg);
		 return false;
		 }
	   if (!IsNan(NeotomaAge.AgeYounger) && IsNan(NeotomaAge.AgeOlder)) {
		 msg = L"AgeYounger exists in cell " + TSSForm->ProfGrid1->AbsoluteCells[col][chron_row_young]->A1Name +
			   L", but no value entered for AgeOlder in cell " +
			   TSSForm->ProfGrid1->AbsoluteCells[col][chron_row_old]->A1Name + L".";
		 OutputError(msg);
		 return false;
		 }
	   if (!IsNan(NeotomaAge.AgeOlder) && IsNan(NeotomaAge.AgeYounger)) {
		 msg = L"AgeOlder exists in cell " + TSSForm->ProfGrid1->AbsoluteCells[col][chron_row_old]->A1Name +
			   L", but no value entered for AgeYounger in cell " +
			   TSSForm->ProfGrid1->AbsoluteCells[col][chron_row_young]->A1Name + L".";
		 OutputError(msg);
		 return false;
		 }
	   if (!IsNan(NeotomaAge.AgeYounger) && !IsNan(NeotomaAge.AgeOlder)) {
		 if (NeotomaAge.AgeYounger > NeotomaAge.AgeOlder) {
		   msg = L"AgeOlder and AgeYounger are reversed in cells " +
				 TSSForm->ProfGrid1->AbsoluteCells[col][chron_row_young]->A1Name +
				 L" and " + TSSForm->ProfGrid1->AbsoluteCells[col][chron_row_old]->A1Name + L".";
		   OutputError(msg);
		   return false;
		   }
		 }

	   if (!IsNan(NeotomaAge.Age) || (!IsNan(NeotomaAge.AgeYounger) && !IsNan(NeotomaAge.AgeOlder))) {
		 chron_value = true;
		 for (unsigned int i=0; i<DatasetRows.size(); i++) {
		   Variant CustomData = TSSForm->ProfGrid1->AbsoluteCells[col][DatasetRows[i]]->CustomData;
		   if (CustomData.Type() == varInteger) {
			 int SampleID = CustomData;
			 NeotomaSampleAges[SampleID] = NeotomaAge;
			 }
		   }
		 }
	   }
	 }

   if (!chron_found) {
	 msg = L"Chronology " + IntToStr(AgeModel->ChronNumber) + " «" +
		   AgeModel->ChronologyName + L"» is not in the spreadsheet.";
	 OutputError(msg);
	 return false;
	 }
   else if (!chron_value) {
	 msg = L"Chronology " + IntToStr(AgeModel->ChronNumber) + " «" +
		   AgeModel->ChronologyName + L"» does not have any ages assigned in the spreadsheet.";
	 OutputError(msg);
	 return false;
	 }


   // NeotomaAnalysisUnits
   // vector<NEOTOMAANALUNIT> NeotomaAnalysisUnits;
   int thick_row = TSSForm->FindRowCodeIC("#Anal.Thick", TSSForm->ProfGrid1);

   for (int col=HeaderCols; col<=ColCount; col++) {
	 NEOTOMAANALUNIT NeotomaAnalUnit;
	 NeotomaAnalUnit.AnalysisUnitID = VariantToInt(TSSForm->ProfGrid1->AbsoluteCells[col][2]->CustomData,-1);
	 if (!TSSForm->ProfGrid1->AbsoluteCells[col][1]->Text.IsEmpty()) {
	   if (TryStrToFloat(TSSForm->ProfGrid1->AbsoluteCells[col][1]->Text, Depth))
		 NeotomaAnalUnit.Depth = Depth;
	   }
	 if (thick_row > 0) {
	   if (TryStrToFloat(TSSForm->ProfGrid1->AbsoluteCells[col][thick_row]->Text, Thickness))
		 NeotomaAnalUnit.Thickness = Thickness;
	   }
	 NeotomaAnalUnit.AnalysisUnitName = TSSForm->ProfGrid1->AbsoluteCells[col][2]->Text;
	 NeotomaAnalysisUnits.push_back(NeotomaAnalUnit);
	 }

   for (int i=0; i < TSSForm->GeochronList->Count(); i++) {
	 GEOCHRON& Date = TSSForm->GeochronList->Dates[i];
	 NEOTOMAGEOCHRON NeotomaGeochron;
	 NeotomaGeochron.TiliaID = Date.ID;
	 NeotomaGeochron.GeochronID = Date.NeotomaGeochronID;
     NeotomaGeochrons.push_back(NeotomaGeochron);
	 }

   if (!ValidateAgeModels(AgeModel))
	 return false;

   NewMessages.SetMessages(TotalMessages, ArchiveMessages);
   OutputBoldLine(L"Chronology validation completed: " + ValidationMsg(NewMessages));

   if (TotalMessages.Errors == 0) {
	 cxButton2->Visible = true;
	 OutputBoldLine(L"Click the Upload button to upload the new chronology to Neotoma.");
	 }

   // NeotomaChronIDs[TempChronID] = NeotomaChronID;

   return true;
}
//---------------------------------------------------------------------------

// upload button
void __fastcall TNeotomaUploadChronForm::cxButton2Click(TObject *Sender)
{
   site_ptr = (SITE*)TSSForm->Sites->Items[0];
   int CollUnitID = site_ptr->CollUnits[0].NeotomaCollUnitID;
   NeotomaCollUnitIDs[CollUnitID] = CollUnitID;

   cxButton2->Visible = false;

   if (!ProcessTephras(CollUnitID)) return;
   if (!UploadChronologies(CollUnitID)) return;
   for (unsigned int i=0; i<GeochronControls.size(); i++) {
	 int GeochronID = GeochronControls[i].second;
	 NeotomaGeochronIDs[GeochronID] = GeochronID;
	 }
   if (!UploadGeochronControls()) return;
   if (!UploadSampleAges()) return;

   StatusBar1->SimpleText = L"";
   UnicodeString msg = L"New chronology " + IntToStr(AgeModel->ChronNumber) +
		   " «" + AgeModel->ChronologyName + L"» assigned to SiteID " +
		   IntToStr(site_ptr->NeotomaSiteID) + ", CollectionUnitID " +
		   IntToStr(CollUnitID) + " uploaded to Neotoma at " +
		   DateTimeStr(UTCDateTime()) + L" UTC.";
   OutputLine(msg);
   success = true;

   AgeModel->NeotomaChronologyID = NeotomaChronIDs[-1001];
}
//---------------------------------------------------------------------------

bool TNeotomaUploadChronForm::ProcessTephras(int CollUnitID)
{
   // int AnalysisUnitID = -1;
   // if (NeotomaAnalUnitIDs.count(ChronControl.AnalysisUnitID) == 1)
   //  AnalysisUnitID = NeotomaAnalUnitIDs[ChronControl.AnalysisUnitID];
   // InsertControl.Add(L"ANALYSISUNITID", AnalysisUnitID, -1);

   // map<int,int> NeotomaAnalUnitIDs;   // TempAnalUnitID, NeotomaAnalUnitID

   UnicodeString msg, ErrorMsg;
   vector<NTMANALYSISUNIT> NtmAnalUnits;
   vector<int> newids;

   for (unsigned int i=0; i<NeotomaChrons[0].ChronControls.size(); i++) {
	 NEOTOMACHRONCONTROL& ChronControl = NeotomaChrons[0].ChronControls[i];
	 if (ChronControl.ChronControlTypeID == 3) {  // tephra
	   int TephraAnalUnitID = -1;
	   // see if analunit already in Neotoma
	   if (!ChronControl.Depth.IsEmpty() && !ChronControl.Thickness.IsEmpty()) {
		 if (NtmAnalUnits.size() == 0) {
		   NeotomaGetAnalUnitsByCollUnitID AnalUnits(ipsJSONS1, TcpClient1);
		   AnalUnits.AddParam(L"COLLUNITID", CollUnitID);
		   StatusBar1->SimpleText = AnalUnits.WebServiceName();
		   if (AnalUnits.Execute()) {
			 if (AnalUnits.Size() > 0)
			   NtmAnalUnits = AnalUnits.Items;
			 }
		   else
			 return false;
		   }
		 for (unsigned int j=0; j<NtmAnalUnits.size(); j++) {
		   if (!NtmAnalUnits[j].Depth.IsEmpty() && !NtmAnalUnits[j].Thickness.IsEmpty()) {
			 if (ChronControl.Depth == NtmAnalUnits[j].Depth && ChronControl.Thickness == NtmAnalUnits[j].Thickness) {
			   TephraAnalUnitID = NtmAnalUnits[j].AnalysisUnitID;
			   break;
			   }
			 }
		   }
		 }
	   // tephra analusis unit not in Neotoma. create analysis unit.
	   if (TephraAnalUnitID == -1) {
		 // upload a new analysis unit
		 InsertData InsertAnalysisUnit(L"InsertAnalysisUnit", 4, ipsHTTPS1, ipsJSONS1, TcpClient1);
		 InsertAnalysisUnit.Add(L"COLLECTIONUNITID", CollUnitID);
		 InsertAnalysisUnit.AddDouble(L"DEPTH", ChronControl.Depth);
		 InsertAnalysisUnit.AddDouble(L"THICKNESS", ChronControl.Thickness);
		 InsertAnalysisUnit.Add(L"MIXED", false);
		 StatusBar1->SimpleText = L"InsertAnalysisUnit";
		 InsertAnalysisUnit.PostData();
		 if (InsertAnalysisUnit.Post(newids, ErrorMsg)) {
		   if (newids.size() == 1) {
			 TephraAnalUnitID = newids[0];
			 msg = L"Tephra analysis unit uploaded. AnalysisUnitID = " + IntToStr(newids[0]) + L".";
			 OutputLine(msg);
			 }
		   else {
			 ErrorMsg = L"Error inserting into AnalysisUnits table!";
			 OutputError(ErrorMsg);
			 return false;
			 }
		   }
		 else {
		   OutputError(ErrorMsg);
		   return false;
		   }
		 }
	   NeotomaAnalUnitIDs[ChronControl.AnalysisUnitID] = TephraAnalUnitID;
	   }
	 }
   return true;
}
//---------------------------------------------------------------------------

// uploads a new chronology
bool TNeotomaUploadChronForm::UploadSampleAges(void)
{
   vector<int> newids;
   UnicodeString msg, ErrorMsg;

   if (NeotomaSampleAges.size() > 0) {
	 InsertData InsertSampleAge(L"InsertSampleAge", 5, ipsHTTPS1, ipsJSONS1, TcpClient1);
	 map<int,NEOTOMAAGE>::iterator itr;
	 map<int,NEOTOMAAGE>::iterator begin = NeotomaSampleAges.begin();
	 map<int,NEOTOMAAGE>::iterator end = NeotomaSampleAges.end();

	 unsigned int ns = 0;

	 int ChronologyID = NeotomaChronIDs[-1001];
	 for (itr = begin; itr != end; itr++) {
	   int SampleID = itr->first;
	   InsertSampleAge.Add(L"SAMPLEID", SampleID, -1);
	   InsertSampleAge.Add(L"CHRONOLOGYID", ChronologyID, -1);
	   InsertSampleAge.Add(L"AGE", itr->second.Age);
	   InsertSampleAge.Add(L"AGEYOUNGER", itr->second.AgeYounger);
	   InsertSampleAge.Add(L"AGEOLDER", itr->second.AgeOlder);
	   ns++;
	   }

	 if (ns == 0)      // no samples to upload
	   return true;

	 StatusBar1->SimpleText = L"InsertSampleAge";
	 InsertSampleAge.PostData();
	 if (InsertSampleAge.Post(newids, ErrorMsg)) {
	   if (newids.size() == ns) {
		 msg = IntToStr((int)ns) + L" sample age";
		 if (ns != 0)
		   msg += L"s";
		 msg += L" uploaded to SampleAges table: SampleAgeID";
		 if (ns == 1)
		   msg += (L" = " + IntToStr(newids[0]) + L".");
		 else
		   msg += (L"s = " + IntToStr(newids[0]) + L".." + IntToStr(newids.back()) + L".");
		 OutputLine(msg);
		 }
	   else {
		 ErrorMsg = L"Error inserting into SampleAges table!";
		 OutputError(L"ERROR: " + ErrorMsg);
		 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 return false;
		 }
	   }
	 else {
	   OutputError(L"ERROR: " + ErrorMsg);
	   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return false;
	   }
	 }
   return true;
}
//---------------------------------------------------------------------------




