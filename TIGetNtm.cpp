//---------------------------------------------------------------------------

#pragma hdrstop

#include "TIGetNtm.h"
//#include "TISpread.h"
#ifndef TISpreadH
#include "TISpread.h"
#endif
#ifndef TGParentH
#include "TGParent.h"
#endif
#ifndef TIJSONH
#include "TIJSON.h"
#endif
#ifndef TINtmLOIH
#include "TINtmLOI.h"
#endif
#ifndef TICommonH
#include "TICommon.h"
#endif
//#ifndef TIShoMemH
//#include "TIShoMem.h"
//#endif
#ifndef TIJSONH
#include "TIJSON.h"
#endif


//---------------------------------------------------------------------------

#pragma package(smart_init)

bool VARTAPH::operator == (const VARTAPH& compare)
{
   if (this == &compare) return true;
   if (VariableID == compare.VariableID && sets_equal(TaphIDs, compare.TaphIDs))
	 return true;
   else
	 return false;
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::DownloadNeotomaData(vector<MAPDATASET>& MapDatasets)
{
   set<int> SiteIDs;
   vector<NTMDATASET> NeotomaDatasets;

   Screen->Cursor = crHourGlass;
   SiteIDs.insert(MapDatasets[0].SiteID);
   if (MapDatasets.size() > 1) {
	 for (unsigned int i=1; i<MapDatasets.size(); i++) {
	   int SiteID = MapDatasets[i].SiteID;
	   if (SiteIDs.count(SiteID) == 0)
		 SiteIDs.insert(SiteID);
	   }
	 }

   bool error = false;
   int SiteNo = 0;
   for (set<int>::iterator itr = SiteIDs.begin(); itr != SiteIDs.end(); itr++) {
	 int SiteID = *itr;
	 if (SiteNo > 0) {
	   SITE* site = new SITE();
	   Sites->Add(site);
	   }
	 SITE* SitePtr = (SITE*)Sites->Items[SiteNo++];
	 set<int> CollUnitIDs;
	 for (unsigned int i=0; i<MapDatasets.size(); i++) {
	   if (MapDatasets[i].SiteID == SiteID) {
		 int CollUnitID = MapDatasets[i].CollUnitID;
		 if (CollUnitIDs.count(CollUnitID) == 0)
		   CollUnitIDs.insert(CollUnitID);
		 }
	   }
	 if (!GetNeotomaSite(SiteID, SitePtr, &CollUnitIDs)) {
	   error = true;
	   break;
	   }
	 if (SiteIDs.size() == 1 && CollUnitIDs.size() == 1) {
	   if (!GetNeotomaLithology(CollUnitIDs)) {
         error = true;
		 break;
		 }
	   }
	 }

   bool success;
   if (!error)
	 success = GetNeotomaDatasets(Datasets, MapDatasets, NeotomaDatasets, Publications);
   if (success)
	 success = GetNeotomaData();
   if (success)
	 success = GetNeotomaGeochron(NeotomaDatasets);
   if (success)
	 success = GetNeotomaChron(NeotomaDatasets);

   if (success) {
	 FillPubGrid();
	 if (tiLicense->Type() == verNEOTOMASTEWARD) {
	   Downloaded = true;
	   chAnalUnit->Properties->ReadOnly = true;
	   }
	 }

   if (tiLicense->Type() == verNEOTOMASTEWARD) {
	 cxButton28->Visible = true;  // update lat-long data
	 Panel18->Visible = true;     // includes cxButton29 -- update site metadata
	 NeotomaVar1->Visible = true;
	 cxButton30->Visible = true;  // update collection unit data
	 LabeledEdit4->Left = 57;
	 cxComboBox13->Left = 57;
	 Label21->Left = 57;
	 cxButton23->Visible = true;  // update dataset metadata
	 cxComboBox1->Left = 152;
	 Label12->Left = 152;
	 cxComboBox1->Width = 145;
	 }

   // see line 524 in TItlxin for adding publications to spreadsheet
   // see line 1049 in TISpread
   Screen->Cursor = crDefault;
}
//---------------------------------------------------------------------------

bool TTilSpreadSheetForm::GetNeotomaSite(int SiteID, SITE* SitePtr, set<int>* CollUnitIDs)
{
   double dValue;
   int iValue;
   int CollUnitID;
   UnicodeString ConnectError = L"Error connecting to Neotoma server.";

   //bool error = false;
   bool success = true;
   try {
	   // Site data
	   NeotomaSiteMetaDataBySiteID SiteData(ipsJSONS1, TcpClient1);
	   SiteData.AddParam(L"SITEID", SiteID);
	   ParentForm->StatusBar1->Panels->Items[0]->Text = SiteData.WebServiceName();
	   if (SiteData.Execute()) {
		 if (SiteData.Size() > 0) {
		   SitePtr->NeotomaSiteID = SiteData.Items[0].SiteID;
		   SitePtr->SiteName = SiteData.Items[0].SiteName;
		   SitePtr->LongEast = SiteData.Items[0].LongitudeEast;
		   SitePtr->LatNorth = SiteData.Items[0].LatitudeNorth;
		   SitePtr->LongWest = SiteData.Items[0].LongitudeWest;
		   SitePtr->LatSouth = SiteData.Items[0].LatitudeSouth;
		   dValue = VariantToDouble(SiteData.Items[0].Altitude, -99999.0);
		   if (dValue > -99999.0)
			 SitePtr->Altitude = dValue;
		   dValue = VariantToDouble(SiteData.Items[0].Area, -99999.0);
		   if (dValue > -99999.0)
			 SitePtr->Area = dValue;
		   SitePtr->SiteDescription = SiteData.Items[0].SiteDescription;
		   SitePtr->Notes = SiteData.Items[0].Notes;
		   }
		 }
	   else {
		 //error = true;
		 //return false;
		 return (success = false);
		 }

	   // GeoPolitical data
	   GeoPolUnitsBySiteID SiteGeoPolUnits(ipsJSONS1, TcpClient1);
	   SiteGeoPolUnits.AddParam(L"SITEID", SiteID);
	   ParentForm->StatusBar1->Panels->Items[0]->Text = SiteGeoPolUnits.WebServiceName();
	   if (SiteGeoPolUnits.Execute()) {
		 if (SiteGeoPolUnits.Size() > 0) {
		   for (unsigned int i=0; i<SiteGeoPolUnits.Size(); i++) {
			 switch (SiteGeoPolUnits.Items[i].Rank) {
			   case 1:
				 SitePtr->Country = SiteGeoPolUnits.Items[i].GeoPoliticalName;
				 break;
			   case 2:
				 SitePtr->State = SiteGeoPolUnits.Items[i].GeoPoliticalName;
				 break;
			   case 3:
				 SitePtr->County = SiteGeoPolUnits.Items[i].GeoPoliticalName;
				 break;
			   case 4:
				 SitePtr->AdminUnit = SiteGeoPolUnits.Items[i].GeoPoliticalName;
				 break;
			   }
			 }
		   }
		 }
	   else
		 return (success = false);

	   // get lake parameters
       SitePtr->LakeParams.clear();
	   NeotomaSiteLakeParams LakeParams(ipsJSONS1, TcpClient1);
	   LakeParams.AddParam(L"SITEID", SiteID);
	   ParentForm->StatusBar1->Panels->Items[0]->Text = LakeParams.WebServiceName();
	   if (LakeParams.Execute()) {
		 if (LakeParams.Size() > 0) {
		   for (unsigned int i=0; i<LakeParams.Size(); i++) {
			 LAKEPARAM LakeParam;
			 LakeParam.Name = LakeParams.Items[i].first;
			 LakeParam.Value = LakeParams.Items[i].second;
			 SitePtr->LakeParams.push_back(LakeParam);
			 }
		   }
		 }
	   else
		 return (success = false);

	   if (CollUnitIDs == NULL)
		 return (success = true);

	   // get all analysis units -- this is for data management
	   if (tiLicense->Type() == verNEOTOMASTEWARD && (*CollUnitIDs).size() == 1) {
		 set<int>::iterator itr = (*CollUnitIDs).begin();
		 CollUnitID = *itr;
		 NeotomaGetAnalUnitsByCollUnitID AnalUnits(ipsJSONS1, TcpClient1);
		 AnalUnits.AddParam(L"COLLUNITID", CollUnitID);
		 ParentForm->StatusBar1->Panels->Items[0]->Text = AnalUnits.WebServiceName();
		 if (AnalUnits.Execute()) {
		   if (AnalUnits.Size() > 0) {
			 AllAnalUnits = AnalUnits.Items;
			 AdvColumnGrid7->RowCount = AnalUnits.Size() + 1;
			 AdvColumnGrid8->RowCount = AnalUnits.Size() + 1;
			 bool has_names = false;
			 bool has_depths = false;
			 for (unsigned int i=0,row=1; i<AnalUnits.Size(); i++,row++) {
			   AdvColumnGrid7->Cells[0][row] = AnalUnits.Items[i].AnalysisUnitID;
			   AdvColumnGrid8->Cells[0][row] = AnalUnits.Items[i].AnalysisUnitID;
			   if (!AnalUnits.Items[i].AnalysisUnitName.IsEmpty()) {
				 AdvColumnGrid7->Cells[1][row] = AnalUnits.Items[i].AnalysisUnitName;
				 AdvColumnGrid8->Cells[1][row] = AnalUnits.Items[i].AnalysisUnitName;
				 has_names = true;
				 }
			   if (!AnalUnits.Items[i].Depth.IsEmpty()) {
				 AdvColumnGrid7->Cells[2][row] = AnalUnits.Items[i].Depth;
				 AdvColumnGrid8->Cells[2][row] = AnalUnits.Items[i].Depth;
				 has_depths = true;
				 }
			   if (!AnalUnits.Items[i].Thickness.IsEmpty()) {
				 AdvColumnGrid7->Cells[3][row] = AnalUnits.Items[i].Thickness;
				 AdvColumnGrid8->Cells[3][row] = AnalUnits.Items[i].Thickness;
				 }
			   }
			 if (has_names) {
			   AdvColumnGrid7->SortSettings->Column = 1;
			   AdvColumnGrid8->SortSettings->Column = 1;
			   }
			 else if (has_depths) {
			   AdvColumnGrid7->SortSettings->Column = 2;
			   AdvColumnGrid8->SortSettings->Column = 2;
			   }
			 else {
			   AdvColumnGrid7->SortSettings->Column = 0;
			   AdvColumnGrid8->SortSettings->Column = 0;
			   }
			 }
		   }
		 else
		   return (success = false);
		 }

	   // get collection units
	   int n = 0;
	   for (set<int>::iterator itr = (*CollUnitIDs).begin(); itr != (*CollUnitIDs).end(); itr++) {
		 CollUnitID = *itr;
		 if (n > 0) {
		   COLLECTION CollUnit;
		   SitePtr->CollUnits.push_back(CollUnit);
		   }
		 SitePtr->CollUnits[n].NeotomaCollUnitID = CollUnitID;

		 NeotomaCollUnitByID CollectionUnit(ipsJSONS1, TcpClient1);
		 CollectionUnit.AddParam(L"COLLECTIONUNITID", CollUnitID);
		 ParentForm->StatusBar1->Panels->Items[0]->Text = CollectionUnit.WebServiceName();
		 if (CollectionUnit.Execute()) {
		   if (CollectionUnit.Size() > 0) {
			 SitePtr->CollUnits[n].Handle = CollectionUnit.Items[0].Handle;
			 SitePtr->CollUnits[n].NeotomaHandle = CollectionUnit.Items[0].Handle;
			 SitePtr->CollUnits[n].CollectionName = CollectionUnit.Items[0].CollUnitName;
			 SitePtr->CollUnits[n].CollDate = CollectionUnit.Items[0].CollDate;
			 if (SitePtr->CollUnits[n].CollDate.IsNull())
			   SitePtr->CollUnits[n].CollDate = Unassigned();
			 SitePtr->CollUnits[n].CollectionDevice = CollectionUnit.Items[0].CollDevice;
			 dValue = VariantToDouble(CollectionUnit.Items[0].GPSLatitude, -99999.0);
			 if (dValue > -99999.0)
			   SitePtr->CollUnits[n].GPSLat = dValue;
			 dValue = VariantToDouble(CollectionUnit.Items[0].GPSLongitude, -99999.0);
			 if (dValue > -99999.0)
			   SitePtr->CollUnits[n].GPSLong = dValue;
			 dValue = VariantToDouble(CollectionUnit.Items[0].GPSAltitude, -99999.0);
			 if (dValue > -99999.0)
			   SitePtr->CollUnits[n].GPSAltitude = dValue;
			 dValue = VariantToDouble(CollectionUnit.Items[0].GPSError, -99999.0);
			 if (dValue > -99999.0)
			   SitePtr->CollUnits[n].GPSError = dValue;
			 dValue = VariantToDouble(CollectionUnit.Items[0].WaterDepth, -99999.0);
			 if (dValue > -99999.0)
			   SitePtr->CollUnits[n].WaterDepth = dValue;
			 iValue = VariantToInt(CollectionUnit.Items[0].SlopeAspect, -99999);
			 if (iValue > -99999.0)
			   SitePtr->CollUnits[n].SlopeAspect = iValue;
			 iValue = VariantToInt(CollectionUnit.Items[0].SlopeAngle, -99999);
			 if (iValue > -99999.0)
			   SitePtr->CollUnits[n].SlopeAngle = iValue;
			 SitePtr->CollUnits[n].Location = CollectionUnit.Items[0].Location;
			 SitePtr->CollUnits[n].Notes = CollectionUnit.Items[0].Notes;

			 // Collection type
			 int CollTypeID = CollectionUnit.Items[0].CollTypeID;
			 if (CollTypeID > -1) {
			   NeotomaCollectionTypeByID CollUnitType(ipsJSONS1, TcpClient1);
			   CollUnitType.AddParam(L"COLLTYPEID", CollTypeID);
			   ParentForm->StatusBar1->Panels->Items[0]->Text = CollUnitType.WebServiceName();
			   if (CollUnitType.Execute()) {
				 if (CollUnitType.Items.count(CollTypeID) == 1)
				   SitePtr->CollUnits[n].CollectionType = CollUnitType.Items[CollTypeID];
				 }
			   else
				 return (success = false);
			   }

			 // DepEnvt type
			 int DepEnvtID = CollectionUnit.Items[0].DepEnvtID;
			 if (DepEnvtID > -1) {
			   NeotomaDepEnvtTypeByID DepEnvtType(ipsJSONS1, TcpClient1);
			   DepEnvtType.AddParam(L"DEPENVTID", DepEnvtID);
			   ParentForm->StatusBar1->Panels->Items[0]->Text = DepEnvtType.WebServiceName();
			   if (DepEnvtType.Execute()) {
				 if (DepEnvtType.Size() > 0)
				   SitePtr->CollUnits[n].DepEnv = DepEnvtType.Items[0].DepEnvt;
				 }
			   else
				 return (success = false);
			   }

			 // Substrate
			 int RockTypeID = CollectionUnit.Items[0].SubstrateID;
			 if (RockTypeID > -1) {
			   NeotomaRockTypeByID RockType(ipsJSONS1, TcpClient1);
			   RockType.AddParam(L"ROCKTYPEID", RockTypeID);
			   ParentForm->StatusBar1->Panels->Items[0]->Text = RockType.WebServiceName();
			   if (RockType.Execute()) {
				 if (RockType.Size() > 0)
				   SitePtr->CollUnits[n].Substrate = RockType.Items[0].RockType;
				 }
			   else
				 return (success = false);
			   }

			 // Collectors
			 NeotomaCollector Collectors(ipsJSONS1, TcpClient1);
			 Collectors.AddParam(L"COLLECTIONUNITID", CollUnitID);
			 ParentForm->StatusBar1->Panels->Items[0]->Text = Collectors.WebServiceName();
			 if (Collectors.Execute()) {
			   if (Collectors.Size() > 0) {
				 for (unsigned int i=0; i<Collectors.Size(); i++) {
				   CONTACT* Contact = GetNeotomaContact(Collectors.Items[i]);
				   if (Contact != NULL) {
					 SitePtr->CollUnits[n].Collectors.push_back(Contact);
                     //SitePtr->CollUnits[n].NeotomaCollectorIDs.insert(Contact->NeotomaContactID);
					 }
				   }
				 }
			   }
			 else
			   return (success = false);
			 }
		   }
		 else
		   return (success = false);
		 n++;
		 }
	   }
   __finally {
	   if (!success)
		 MessageDlg(ConnectError, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   ParentForm->StatusBar1->Panels->Items[0]->Text = L"";
	   }
   return success;
}
//---------------------------------------------------------------------------

bool TTilSpreadSheetForm::GetNeotomaLithology(set<int>& CollUnitIDs)
{
   UnicodeString ConnectError = L"Error connecting to Neotoma server.";

   bool success = true;
   try {
	   set<int>::iterator itr = CollUnitIDs.begin();
	   int CollUnitID = *itr;
	   NeotomaLithologyByCollUnitID Lithology(ipsJSONS1, TcpClient1);
	   Lithology.AddParam(L"COLLUNITID", CollUnitID);
	   ParentForm->StatusBar1->Panels->Items[0]->Text = Lithology.WebServiceName();
	   if (Lithology.Execute()) {
		 if (Lithology.Size() > 0) {
		   for (unsigned int i=0; i<Lithology.Size(); i++) {
			 NEOTOMALITH& ntmlithunit = Lithology.Items[i];
			 LITHOLOGYUNIT *lithunit = new LITHOLOGYUNIT();
			 lithunit->NeotomaLithologyID = ntmlithunit.LithologyID;
			 lithunit->DepthTop = ntmlithunit.DepthTop;
			 lithunit->DepthBottom = ntmlithunit.DepthBottom;
			 lithunit->UnitDescription = ntmlithunit.Description;
			 lithunit->LowerBoundary = ntmlithunit.LowerBoundary;
			 LithologyUnitList->Add(lithunit);
			 LithologyUnitDataSource->DataChanged();
			 }
		   }
		 }
	   else {
		 success = false;
		 }
	   }
   __finally {
	   if (!success)
		 MessageDlg(ConnectError, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   ParentForm->StatusBar1->Panels->Items[0]->Text = L"";
	   }

   return success;
}
//---------------------------------------------------------------------------


bool TTilSpreadSheetForm::GetNeotomaChron(vector<NTMDATASET>& NeotomaDatasets)
{
   UnicodeString ConnectError = L"Error connecting to Neotoma server.";

   int CollUnitID = NeotomaDatasets[0].CollectionUnitID;

   bool success = true;
   try {
	   NeotomaChronologiesByCollUnitID Chronologies(ipsJSONS1, TcpClient1);
	   Chronologies.AddParam(L"COLLECTIONUNITID", CollUnitID);
	   ParentForm->StatusBar1->Panels->Items[0]->Text = Chronologies.WebServiceName();
	   if (!Chronologies.Execute())
		 return (success = false);
	   int ChronNumber = 1;

	   bool has_depths = false;
	   bool has_analunits = false;
	   //bool has_analunitIDs = false;
	   for (unsigned int i=0; i<Chronologies.Items.size(); i++) {
		 AGEMODEL* agemodel = new AGEMODEL();
		 NTMCHRONOLOGY& chron = Chronologies.Items[i];
		 agemodel->ChronNumber = ChronNumber++;
		 agemodel->NeotomaChronologyID = chron.ChronologyID;
		 agemodel->ChronologyName = chron.ChronologyName;
		 agemodel->AgeUnits = chron.AgeType;
		 agemodel->Default = chron.IsDefault;
		 agemodel->DatePrepared = chron.DatePrepared;
		 agemodel->AgeModel = chron.AgeModel;
		 if (!chron.AgeBoundOlder.IsEmpty())
		   agemodel->AgeBoundOlder = chron.AgeBoundOlder;
		 if (!chron.AgeBoundYounger.IsEmpty())
		   agemodel->AgeBoundYounger = chron.AgeBoundYounger;
		 agemodel->Notes = RemoveCR(chron.Notes);

		 // preparers
		 if (chron.ContactID > -1) {
		   NeotomaContactByID Preparer(ipsJSONS1, TcpClient1);
		   Preparer.AddParam(L"CONTACTID", chron.ContactID);
		   ParentForm->StatusBar1->Panels->Items[0]->Text = Preparer.WebServiceName();
		   if (!Preparer.Execute())
			 return (success = false);
		   if (Preparer.Size() > 0) {
			 CONTACT* Contact = GetNeotomaContact(Preparer.Items[0]);
			 if (Contact != NULL) {
			   agemodel->Preparers.push_back(Contact);
			   agemodel->PreparersComboBoxText = Contact->ShortContactName;
			   }
			 }
		   }

		 // chron controls
		 NeotomaChronoControlsByChronologyID ChronControls(ipsJSONS1, TcpClient1);
		 ChronControls.AddParam(L"CHRONOLOGYID", chron.ChronologyID);
		 ParentForm->StatusBar1->Panels->Items[0]->Text = ChronControls.WebServiceName();
		 if (!ChronControls.Execute())
		   return (success = false);

		 // GeoChronControls
		 NeotomaGeoChronControlsByChronologyID GeoChronControls(ipsJSONS1, TcpClient1);
		 GeoChronControls.AddParam(L"CHRONOLOGYID", chron.ChronologyID);
		 ParentForm->StatusBar1->Panels->Items[0]->Text = GeoChronControls.WebServiceName();
		 if (!GeoChronControls.Execute())
		   return (success = false);

		 // relative chron controls
		 NeotomaRelativeAgesByChronologyID RelativeAges(ipsJSONS1, TcpClient1);
		 RelativeAges.AddParam(L"CHRONOLOGYID", chron.ChronologyID);
		 ParentForm->StatusBar1->Panels->Items[0]->Text = RelativeAges.WebServiceName();
		 if (!RelativeAges.Execute())
		   return (success = false);

		 // event chron controls
		 NeotomaEventsByChronologyID Events(ipsJSONS1, TcpClient1);
		 Events.AddParam(L"CHRONOLOGYID", chron.ChronologyID);
		 ParentForm->StatusBar1->Panels->Items[0]->Text = Events.WebServiceName();
		 if (!Events.Execute())
		   return (success = false);

		 for (unsigned int j=0; j<ChronControls.Size(); j++) {
		   CHRON* ChronControl = new CHRON();
		   NTMCHRONCONTROL& nChronControl = ChronControls.Items[j];
		   ChronControl->NeotomaChronControlID = nChronControl.ChronControlID;
		   if (!nChronControl.Depth.IsEmpty()) {
			 ChronControl->Depth = nChronControl.Depth;
			 has_depths = true;
			 }
		   if (!nChronControl.Thickness.IsEmpty())
			 ChronControl->Thickness = nChronControl.Thickness;
		   ChronControl->AnalUnit = nChronControl.AnalysisUnitName;
		   if (!ChronControl->AnalUnit.IsEmpty())
			 has_analunits = true;
		   if (nChronControl.AnalysisUnitID != -1) {
			 ChronControl->NeotomaAnalUnitID = nChronControl.AnalysisUnitID;
			 }

		   if (!nChronControl.AgeTypeID.IsEmpty()) {
			 int AgeTypeID = nChronControl.AgeTypeID;
			 switch (AgeTypeID) {
			   case 2:
				 ChronControl->AgeUnits = L"Calendar";
				 break;
			   case 4:
				 ChronControl->AgeUnits = L"Radiocarbon";
				 break;
			   }
		     }

		   if (!nChronControl.Age.IsEmpty())
			 ChronControl->AgeValue = nChronControl.Age;
		   if (!nChronControl.AgeLimitOlder.IsEmpty())
			 ChronControl->AgeLimitOlder = nChronControl.AgeLimitOlder;
		   if (!nChronControl.AgeLimitYounger.IsEmpty())
			 ChronControl->AgeLimitYounger = nChronControl.AgeLimitYounger;
		   UnicodeString ChronControlType = nChronControl.ChronControlType;

		   if (Events.Size() > 0) {
			 if (Events.Items.count(nChronControl.ChronControlID) > 0)
			   ChronControlType = Events.Items[nChronControl.ChronControlID];
			 }

		   if (RelativeAges.Size() > 0) {
			 if (RelativeAges.Items.count(nChronControl.ChronControlID) > 0)
			   ChronControlType = RelativeAges.Items[nChronControl.ChronControlID];
			 }

		   ChronControl->ControlType = ChronControlType;
		   ChronControl->Notes = nChronControl.Notes;
		   ChronControl->CalibCurve = nChronControl.CalibrationCurve;
		   ChronControl->Calib.Program = nChronControl.CalibrationProgram;
		   ChronControl->Calib.Version = nChronControl.Version;

		   // get GeochronControls
		   if (GeoChronControls.Items.count(ChronControl->NeotomaChronControlID) > 0) {
			 multimap<int,int>::iterator itr;      // ChronControlID, GeochronID
			 pair<multimap<int,int>::iterator, multimap<int,int>::iterator> range;
			 range = GeoChronControls.Items.equal_range(ChronControl->NeotomaChronControlID);
			 for (itr=range.first; itr!=range.second; itr++) {
			   int GeochronID = itr->second;
			   for (int j=0; j<GeochronList->Count(); j++) {
				 GEOCHRON* date = GeochronList->Date[j];
				 if (GeochronID == date->NeotomaGeochronID) {
                   ChronControl->GeochronIDs.push_back(date->ID);
				   break;
				   }
				 }
			   }
			 }
		   agemodel->ChronControls->Add(ChronControl);
		   }
		 AgeModelList->Add(agemodel);
		 }
	   if (has_depths) {
		 CheckBox1->Checked = true;
		 chDepth->Visible = true;
		 chThickness->Visible = true;
		 }
	   if (has_analunits) {
		 CheckBox3->Checked = true;
		 chAnalUnit->Visible = true;
		 }
	   if (tiLicense->Type() == verNEOTOMASTEWARD) {
		 chAnalUnitID->Visible = true;
		 geAnalUnitID->Visible = true;
		 }

	   AgeModelDataSource->DataChanged();
	   }
   __finally {
	   if (!success)
		 MessageDlg(ConnectError, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   ParentForm->StatusBar1->Panels->Items[0]->Text = L"";
	   }
   return success;
}
//---------------------------------------------------------------------------

bool TTilSpreadSheetForm::GetNeotomaGeochron(vector<NTMDATASET>& NeotomaDatasets)
{
   UnicodeString ConnectError = L"Error connecting to Neotoma server.";

   bool success = true;
   try {
	   for (unsigned int i=0; i<NeotomaDatasets.size(); i++) {
		 if (NeotomaDatasets[i].DatasetTypeID == 1) {  // geochron dataset
		   GeochronDataset.NeotomaDatasetID = NeotomaDatasets[i].DatasetID;
		   cxLabel7->Visible = true;
		   cxLabel7->Caption = L"   Neotoma DatasetID: " + IntToStr(GeochronDataset.NeotomaDatasetID);
		   GeochronDataset.Notes = NeotomaDatasets[i].Notes;
		   cxBlobEdit1->Text = GeochronDataset.Notes;
		   NeotomaGeochronByDatasetID NeotomaGeochron(ipsJSONS1, TcpClient1);
		   NeotomaGeochron.AddParam(L"DATASETID", NeotomaDatasets[i].DatasetID);
		   ParentForm->StatusBar1->Panels->Items[0]->Text = NeotomaGeochron.WebServiceName();
		   if (!NeotomaGeochron.Execute())
			 return (success = false);
		   if (NeotomaGeochron.Size() == 0) continue;
		   for (unsigned int j=0; j<NeotomaGeochron.Size(); j++) {
			 NTMGEOCHRON& ndate = NeotomaGeochron.Items[j];
			 GEOCHRON date;
			 date.NeotomaGeochronID = ndate.GeochronID;
			 date.NeotomaAnalUnitID = ndate.AnalysisUnitID;
			 date.Method = ndate.GeochronType;
			 date.AgeUnits = ndate.AgeType;
			 if (!ndate.Depth.IsEmpty())
			   date.Depth = ndate.Depth;
			 if (!ndate.Thickness.IsEmpty())
			   date.Thickness = ndate.Thickness;
			 date.AnalUnit = ndate.AnalysisUnitName;
			 date.LabNumber = ndate.LabNumber;
			 if (!ndate.Age.IsEmpty())
			   date.Age = ndate.Age;
			 if (!ndate.ErrorOlder.IsEmpty())
			   date.ErrorOlder = ndate.ErrorOlder;
			 if (!ndate.ErrorYounger.IsEmpty())
			   date.ErrorYounger = ndate.ErrorYounger;
			 date.GreaterThan = ndate.Infinite;
			 date.Sigma = 1;
			 if (date.ErrorYounger == date.ErrorOlder)
			   date.StdDev = date.ErrorYounger;
			 date.MaterialDated = ndate.MaterialDated;
			 date.Notes = ndate.Notes;
			 GeochronList->Add(date);
			 GeochronDataSource->DataChanged();
			 }

		   // get radiocarbon metadata
		   int nr = 0;
		   UnicodeString GeochronIDList;
		   for (unsigned int j=0; j<NeotomaGeochron.Size(); j++) {
			 if (NeotomaGeochron.Items[j].GeochronTypeID == 2) {
			   if (nr > 0) GeochronIDList += L"$";
			   GeochronIDList += IntToStr(NeotomaGeochron.Items[j].GeochronID);
			   nr++;
			   }
			 }
		   if (nr > 0) {
			 NeotomaRadiocarbonByGeochronID Radiocarbon(ipsJSONS1, TcpClient1);
			 Radiocarbon.AddParam(L"GEOCHRONIDLIST", GeochronIDList);
			 ParentForm->StatusBar1->Panels->Items[0]->Text = Radiocarbon.WebServiceName();
			 if (!Radiocarbon.Execute())
			   return (success = false);
			 for (int j=0; j<GeochronList->Count(); j++) {
			   GEOCHRON* date = GeochronList->Date[j];
			   map<int,NTMRADIOCARBON>::iterator itr = Radiocarbon.Items.find(date->NeotomaGeochronID);
			   if (itr != Radiocarbon.Items.end()) {
				 if (!itr->second.RadiocarbonMethod.IsEmpty())
				   date->Parameters[L"Method"] = itr->second.RadiocarbonMethod;
				 if (!itr->second.MassCmg.IsEmpty())
				   date->Parameters[L"Mass C (mg)"] = itr->second.MassCmg;
				 if (!itr->second.PercentC.IsEmpty())
				   date->Parameters[L"%C"] = itr->second.PercentC;
				 if (!itr->second.PercentN.IsEmpty())
				   date->Parameters[L"%N"] = itr->second.PercentN;
				 if (!itr->second.CNRatio.IsEmpty())
				   date->Parameters[L"C:N"] = itr->second.CNRatio;
				 if (!itr->second.Delta13C.IsEmpty())
				   date->Parameters[L"δ13C"] = itr->second.Delta13C;
				 if (!itr->second.Delta15N.IsEmpty())
				   date->Parameters[L"δ15N"] = itr->second.Delta15N;
				 if (!itr->second.PercentCollagen.IsEmpty())
				   date->Parameters[L"%collagen"] = itr->second.PercentCollagen;
				 if (!itr->second.Reservoir.IsEmpty())
				   date->Parameters[L"Reservoir (yrs)"] = itr->second.Reservoir;
				 }
			   }
			 }

		   // get publications
		   GeochronIDList = NeotomaGeochron.Items[0].GeochronID;
		   for (unsigned int j=1; j<NeotomaGeochron.Size(); j++)
			 GeochronIDList += (L"$" + IntToStr(NeotomaGeochron.Items[j].GeochronID));
		   NeotomaPublicationsByGeochronID GeochronPubIDs(ipsJSONS1, TcpClient1);
		   GeochronPubIDs.AddParam(L"GEOCHRONIDLIST", GeochronIDList);
		   ParentForm->StatusBar1->Panels->Items[0]->Text = GeochronPubIDs.WebServiceName();
		   if (!GeochronPubIDs.Execute())       // GeochronID, PublicationID
			 return (success = false);
		   if (GeochronPubIDs.Size() > 0) {
			 set<int> PubIDs;
			 for (unsigned int j=0; j<GeochronPubIDs.Size(); j++) {
			   if (PubIDs.count(GeochronPubIDs.Items[j].second) == 0)
				 PubIDs.insert(GeochronPubIDs.Items[j].second);
			   }
			 set<int>::iterator pid_begin = PubIDs.begin();
			 UnicodeString PubIDList = IntToStr(*pid_begin);
			 pid_begin++;
			 for (set<int>::iterator itr = pid_begin; itr != PubIDs.end(); itr++)
			   PubIDList += (L"$" + IntToStr(*itr));
			 NeotomaPublicationsByPubIDList NtmPublications(ipsJSONS1, TcpClient1);
			 NtmPublications.AddParam(L"PUBLICATIONIDLIST", PubIDList);
			 ParentForm->StatusBar1->Panels->Items[0]->Text = NtmPublications.WebServiceName();
			 if (!NtmPublications.Execute())
			   return (success = false);
			 for (unsigned int j=0; j<GeochronPubIDs.Size(); j++) {
			   for (int k=0; k<GeochronList->Count(); k++) {
				 GEOCHRON* date = GeochronList->Date[k];
				 if (date->NeotomaGeochronID == GeochronPubIDs.Items[j].first) {
				   for (unsigned int m=0; m<NtmPublications.Size(); m++) {
					 if (NtmPublications.Items[m].PublicationID == GeochronPubIDs.Items[j].second) {
					   PUBLICATION* pub = GetNeotomaPub(NeotomaDatasets[i].DatasetID, Publications, NtmPublications.Items[m]);
					   if (pub != NULL)
						 date->publications.push_back(pub);
					   break;
					   }
					 }
				   break;
				   }
				 }
			   }

			 for (int j=0; j<GeochronList->Count(); j++) {
			   GEOCHRON* date = GeochronList->Date[j];
			   UnicodeString PubComboBoxText;
			   for (unsigned int k=0; k<date->publications.size(); k++) {
				 if (k > 0) PubComboBoxText += L";";
				 PubComboBoxText += getPubShortDescription(date->publications[k]);
				 }
			   date->PubComboBoxText = PubComboBoxText;
			   }
			 GeochronDataSource->DataChanged();
			 }

		   // get PubIDs
		   NeotomaGetDatasetPublicationIDs PublicationIDs(ipsJSONS1, TcpClient1);
		   PublicationIDs.AddParam(L"DATASETID", GeochronDataset.NeotomaDatasetID);
		   ParentForm->StatusBar1->Panels->Items[0]->Text = PublicationIDs.WebServiceName();
		   if (PublicationIDs.Execute()) {
			 if (PublicationIDs.Size() > 0) {
			   for (unsigned int j=0; j<PublicationIDs.Size(); j++) {
				 GeochronDataset.NeotomaPublicationIDs.insert(PublicationIDs.Items[j]);
				 }
			   }
			 }
		   else
			 return (success = false);

		   NeotomaInvestigator Investigators(ipsJSONS1, TcpClient1);
		   Investigators.AddParam(L"DATASETID", GeochronDataset.NeotomaDatasetID);
		   ParentForm->StatusBar1->Panels->Items[0]->Text = Investigators.WebServiceName();
		   if (Investigators.Execute()) {
			 if (Investigators.Size() > 0) {
			   for (unsigned int j=0; j<Investigators.Size(); j++) {
				 CONTACT* Contact = GetNeotomaContact(Investigators.Items[j]);
				 if (Contact != NULL)
				   GeochronDataset.Investigators.push_back(Contact);
				 }
			   }
			 }
		   else
			 return (success = false);

		   // get specimens dated
		   NeotomaGeochronDatasetSpecimenDates SpecimenDates(ipsJSONS1, TcpClient1);
		   SpecimenDates.AddParam(L"GEOCHRONDATASETID", GeochronDataset.NeotomaDatasetID);
		   ParentForm->StatusBar1->Panels->Items[0]->Text = SpecimenDates.WebServiceName();
		   if (SpecimenDates.Execute()) {
			 if (SpecimenDates.Size() > 0) {
			   for (unsigned int j = 0; j < SpecimenDates.Size(); j++) {
				 SPECIMENDATE& SpecDate = SpecimenDates.Items[j];
				 for (int k = 0; k < GeochronList->Count(); k++) {
				   GEOCHRON& Date = GeochronList->Dates[k];
				   if (SpecDate.GeochronID == Date.NeotomaGeochronID) {
					 TAXONDATED Taxon;
					 Taxon.NeotomaSpecimenDateID = SpecDate.SpecimenDateID;
					 if (SpecDate.SpecimenID != -1)
					   Taxon.UserSpecID = IntToStr(SpecDate.SpecimenID);
					 Taxon.Taxon = SpecDate.TaxonName;
					 Taxon.Element = SpecDate.ElementType;
					 Taxon.Fraction = SpecDate.Fraction;
					 Taxon.Notes = SpecDate.Notes;
					 Taxon.CalAgeMedian = SpecDate.CalAge;
					 Taxon.CalAgeOlder = SpecDate.CalAgeOlder;
					 Taxon.CalAgeYounger = SpecDate.CalAgeYounger;
					 Taxon.CalibCurve = SpecDate.CalibrationCurve;
					 Taxon.Calib.Program = SpecDate.CalibrationProgram;
					 Taxon.Calib.Version = SpecDate.Version;
					 list<CELLOBJECT*>::iterator itr;
					 for (itr = CellObjects.begin(); itr != CellObjects.end(); itr++) {
					   if ((*itr)->ObjectType == CELLSPECIMENS) {
						 TList* Specimens = (TList*)(*itr)->Object;
						 for (int n=0; n<Specimens->Count; n++) {
						   SPECIMEN* Specimen = (SPECIMEN*)Specimens->Items[n];
						   if (Specimen->NeotomaSpecimenID == SpecDate.SpecimenID) {
							 Taxon.Specimen = Specimen;
							 break;
							 }
						   }
						 }
					   }
					 Date.TaxaDated.push_back(Taxon);
					 break;
					 }
				   }
				 }
			   }
			 }
		   else
			 return (success = false);

		   // add any geochron analysis units to spreadsheet that aren't already there

		   if (tiLicense->Type() == verNEOTOMASTEWARD) {
			 set<int> auids;
			 int ColCount = AbsContentColCount(ProfGrid1);
			 int next_col = ColCount + 1;
			 int StartCol = AbsHeaderColCount(ProfGrid1);
			 for (int col=StartCol; col<=ColCount; col++) {
			   int auid = ProfGrid1->AbsoluteCells[col][2]->CustomData;
			   auids.insert(auid);
			   }
			 bool add_analunits = false;
			 int thick_row = -1;
			 for (unsigned int j=0; j<NeotomaGeochron.Size(); j++) {
			   if (auids.count(NeotomaGeochron.Items[j].AnalysisUnitID) == 0) {
				 if (!add_analunits) {
				   UnicodeString msg = L"Some geochronology analysis units are not in the spreadsheet. Add them?";
				   if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes)
					 add_analunits = true;
				   else
					 break;
				   }
				 if (!NeotomaGeochron.Items[j].Depth.IsEmpty())
				   ProfGrid1->AbsoluteCells[next_col][1]->Value = NeotomaGeochron.Items[j].Depth;
				 if (!NeotomaGeochron.Items[j].Thickness.IsEmpty()) {
				   if (thick_row == -1) {
					 thick_row = FindRowCodeIC("#Anal.Thick", ProfGrid1);
					 if (thick_row == 0) {
					   ProfGrid1->Row = 3;
					   EnterSSMetadataCode("#Anal.Thick", "Analysis Unit Thickness");
					   thick_row = 3;
					   }
					 }
                   ProfGrid1->AbsoluteCells[next_col][thick_row]->Value = NeotomaGeochron.Items[j].Thickness;
				   }
				 ProfGrid1->AbsoluteCells[next_col][2]->Value = NeotomaGeochron.Items[j].AnalysisUnitName;
				 ProfGrid1->AbsoluteCells[next_col++][2]->CustomData = NeotomaGeochron.Items[j].AnalysisUnitID;
				 auids.insert(NeotomaGeochron.Items[j].AnalysisUnitID);
				 }
			   }
			 }

		   break;
		   }
		 }
	   }
   __finally {
	   if (!success)
		 MessageDlg(ConnectError, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   ParentForm->StatusBar1->Panels->Items[0]->Text = L"";
	   }
   return success;
}
//---------------------------------------------------------------------------

bool TTilSpreadSheetForm::GetNeotomaDatasets(vector<DATASET>& Datasets,
	vector<MAPDATASET>& MapDatasets, vector<NTMDATASET>& neotoma_datasets, TList* Publications)
{
   UnicodeString ConnectError = L"Error connecting to Neotoma server.";

   UnicodeString datasetlist;
   for (unsigned int i=0; i<MapDatasets.size(); i++) {
	 if (i > 0) datasetlist += L"$";
	 datasetlist += IntToStr(MapDatasets[i].DatasetID);
	 }

   //ShowMessage(datasetlist);
   bool success = true;
   try {
	   NeotomaDatasetsByID NeotomaDatasets(ipsJSONS1, TcpClient1);
	   NeotomaDatasets.AddParam(L"DATASETS", datasetlist);
	   ParentForm->StatusBar1->Panels->Items[0]->Text = NeotomaDatasets.WebServiceName();
	   if (NeotomaDatasets.Execute()) {
		 if (NeotomaDatasets.Size() > 0) {
		   //ShowMessage(L"Breakpoint 1");
		   neotoma_datasets = NeotomaDatasets.Items;
		   int n = 0;
		   for (unsigned int i=0; i<NeotomaDatasets.Size(); i++) {
			 int DatasetTypeID = NeotomaDatasets.Items[i].DatasetTypeID;
			 if (DatasetTypeID > 1) {  // dataset other than Geochron
			   if (n > 0) {
				 DATASET dataset;
				 Datasets.push_back(dataset);
				 }
			   DATASET& Dataset = Datasets.back();
			   Dataset.NeotomaDatasetID = NeotomaDatasets.Items[i].DatasetID;
			   Dataset.NeotomaDatasetTypeID = NeotomaDatasets.Items[i].DatasetTypeID;
			   Dataset.DatasetType = NeotomaDatasets.Items[i].DatasetType;
			   Dataset.Name = NeotomaDatasets.Items[i].DatasetName;
			   Dataset.Notes = NeotomaDatasets.Items[i].Notes;
			   n++;
			   }
			 }
		   //ShowMessage(L"Breakpoint 2");
		   if (!Datasets[0].DatasetType.IsEmpty()) {  // dataset other than Geochron exists
			 int idx = cxComboBox2->Properties->Items->IndexOf(Datasets[0].DatasetType);
			 if (idx > -1)
			   cxComboBox2->ItemIndex = idx;
			 }

		   //ShowMessage(L"Breakpoint 3");
		   // get rest of dataset metadata
		   for (unsigned int i=0; i<Datasets.size(); i++) {
			 // Dataset investigators
			 NeotomaInvestigator Investigators(ipsJSONS1, TcpClient1);
			 Investigators.AddParam(L"DATASETID", Datasets[i].NeotomaDatasetID);
			 ParentForm->StatusBar1->Panels->Items[0]->Text = Investigators.WebServiceName();
			 if (Investigators.Execute()) {
			   if (Investigators.Size() > 0) {
				 for (unsigned int j=0; j<Investigators.Size(); j++) {
				   CONTACT* Contact = GetNeotomaContact(Investigators.Items[j]);
				   if (Contact != NULL)
					 Datasets[i].Investigators.push_back(Contact);
				   }
				 }
			   }
			 else
			   return (success = false);

			 // data processors
			 NeotomaDataProcessor DataProcessor(ipsJSONS1, TcpClient1);
			 DataProcessor.AddParam(L"DATASETID", Datasets[i].NeotomaDatasetID);
			 ParentForm->StatusBar1->Panels->Items[0]->Text = DataProcessor.WebServiceName();
			 if (DataProcessor.Execute()) {
			   if (DataProcessor.Size() > 0) {
				 for (unsigned int j=0; j<DataProcessor.Size(); j++) {
				   CONTACT* Contact = GetNeotomaContact(DataProcessor.Items[j]);
				   if (Contact != NULL)
					 Datasets[i].Processors.push_back(Contact);
				   }
				 }
			   }
			 else
			   return (success = false);

			 // repositories
			 NeotomaDatasetRepository NeotomaRepository(ipsJSONS1, TcpClient1);
			 NeotomaRepository.AddParam(L"DATASETID", Datasets[i].NeotomaDatasetID);
			 ParentForm->StatusBar1->Panels->Items[0]->Text = NeotomaRepository.WebServiceName();
			 if (NeotomaRepository.Execute()) {
			   if (NeotomaRepository.Size() > 0) {
				 for (unsigned int j=0; j<NeotomaRepository.Size(); j++) {
				   REPOSITORY Repository;
				   Repository.RepositoryID = NeotomaRepository.Items[j].RepositoryID;
				   Repository.Acronym = NeotomaRepository.Items[j].Acronym;
				   Repository.Repository = NeotomaRepository.Items[j].Repository;
				   Repository.Notes = NeotomaRepository.Items[j].Notes;
				   Datasets[i].Repositories.push_back(Repository);
				   }
				 }
			   }
			 else
			   return (success = false);

			 // repository specimen notes
			 if (Datasets[i].Repositories.size() > 0) {
			   NeotomaDatasetRepositorySpecimenNotes RepSpecNotes(ipsJSONS1, TcpClient1);
			   RepSpecNotes.AddParam(L"DATASETID", Datasets[i].NeotomaDatasetID);
			   ParentForm->StatusBar1->Panels->Items[0]->Text = RepSpecNotes.WebServiceName();
			   if (RepSpecNotes.Execute()) {
				 if (RepSpecNotes.Size() > 0) {
				   map<int,UnicodeString>::iterator itr;
				   for (itr = RepSpecNotes.Items.begin(); itr != RepSpecNotes.Items.end(); itr++) {
					 for (unsigned int j=0; j<Datasets[i].Repositories.size(); j++) {
					   if (Datasets[i].Repositories[j].RepositoryID == itr->first) {
						 Datasets[i].Repositories[j].SpecimenNotes = itr->second;
						 break;
					     }
					   }
					 }
				   }
				 }
			   else
				 return (success = false);
			   }

			 // publications
			 NeotomaDatasetPublications NeotomaPubs(ipsJSONS1, TcpClient1);
			 NeotomaPubs.AddParam(L"DATASETID", Datasets[i].NeotomaDatasetID);
			 ParentForm->StatusBar1->Panels->Items[0]->Text = NeotomaPubs.WebServiceName();
			 if (NeotomaPubs.Execute()) {
			   if (NeotomaPubs.Size() > 0) {
				 for (unsigned int j=0; j<NeotomaPubs.Size(); j++) {
				   PUBLICATION* pub = GetNeotomaPub(Datasets[i].NeotomaDatasetID, Publications, NeotomaPubs.Items[j]);
				   if (pub != NULL)
					 Datasets[i].Publications.push_back(pub);
				   }
				 }
			   }
			 else
			   return (success = false);

			 }
		   }
		 }
	   else
		 return (success = false);

	   }
   __finally {
	   //ShowMessage(L"Breakpoint 10");
	   if (!success)
		 MessageDlg(ConnectError, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   ParentForm->StatusBar1->Panels->Items[0]->Text = L"";
	   }
   return success;
}
//---------------------------------------------------------------------------

bool TTilSpreadSheetForm::GetNeotomaData(void)
{
   bool success = true;
   UnicodeString ConnectError = L"Error connecting to Neotoma server.";
   UnicodeString msg;
   map<int,int> col_idx;          // SampleID, column
   vector<pair<int,int> > sampleid_col_idx;  // SampleID, column
   map<int,int> au_col_idx;       // AnalysisUnitID, column
   map<int,AGEROWS> age_rows;     // ChronologyID, AGEROWS
   int next_col;
   int next_row = 3;
   int thick_row = 0;
   int dateanal_row = 0;
   int datesamp_row = 0;
   int labnumber_row = 0;
   int analyst_row = 0;
   int keywords_row = 0;
   int facies_row = 0;
   int depagents_row = 0;
   int mixed_row = 0;
   int IGSN_row = 0;
   int analunitnotes_row = 0;
   int sampname_row = 0;
   int method_row = 0;
   int sampnotes_row = 0;
   int sampid_row = 1;
   int loi_where = loiNone;
   int loi_dataset_idx = -1;

   bool special_formatting = false;
   int nssdatasets = 0; // number of spreadsheet datasets
   try {
	   ProfGrid1->DisableControls();
	   ProfGrid1->SpreadsheetEnabled = false;
	   for (unsigned int i=0; i<Datasets.size(); i++) {
		 if (Datasets[i].NeotomaDatasetTypeID == 2) {  // LOI dataset
		   loi_dataset_idx = i;
		   // get variables
		   NeotomaDatasetVariables DatasetVars(ipsJSONS1, TcpClient1);
		   DatasetVars.AddParam(L"DATASETID", Datasets[i].NeotomaDatasetID);
		   ParentForm->StatusBar1->Panels->Items[0]->Text = DatasetVars.WebServiceName();
		   if (!DatasetVars.Execute())
			 return (success = false);
		   for (unsigned int i=0; i<DatasetVars.Size(); i++) {
			 UnicodeString TaxonName = DatasetVars.Items[i].TaxonName;
			 if (!SameText(TaxonName, L"loss-on-ignition") && !SameText(TaxonName, L"bulk density")) {
			   loi_where = loiSpread;
			   break;
			   }
			 }
		   if (loi_where == loiNone) {
			 DownloadLOIForm = new TDownloadLOIForm(this);
			 if (DownloadLOIForm->ShowModal() == mrOk)
			   loi_where = DownloadLOIForm->LOIWhere;
			 delete DownloadLOIForm;
			 }
		   }

		 if (Datasets[i].NeotomaDatasetTypeID > 1) {  // not Geochron
		   if (Datasets[i].NeotomaDatasetTypeID == 2 && (loi_where == loiNone || loi_where == loiTab))
			 continue;   // enter loi dataset in LOI tabsheet

		   // get samples
		   NeotomaSampleAnalUnits NeotomaSamples(ipsJSONS1, TcpClient1);
		   NeotomaSamples.AddParam(L"DATASETID", Datasets[i].NeotomaDatasetID);
		   ParentForm->StatusBar1->Panels->Items[0]->Text = NeotomaSamples.WebServiceName();
		   if (!NeotomaSamples.Execute())
			 return (success = false);

		   // get chrons
		   NeotomaDatasetChrons DatasetChrons(ipsJSONS1, TcpClient1);
		   DatasetChrons.AddParam(L"DATASETID", Datasets[i].NeotomaDatasetID);
		   ParentForm->StatusBar1->Panels->Items[0]->Text = DatasetChrons.WebServiceName();
		   if (!DatasetChrons.Execute())
			 return (success = false);

		   // get chron controls
		   map<int,map<int,NTMSAMPLEAGE> > ChronSampleAges;  // ChronologyID, SampleID, NTMSAMPLEAGE
		   if (DatasetChrons.Size() > 0) {
			 for (unsigned int j=0; j<DatasetChrons.Size(); j++) {
			   NeotomaSampleAgesByChronID SampleAges(ipsJSONS1, TcpClient1);
			   SampleAges.AddParam(L"CHRONOLOGYID", DatasetChrons.Items[j].ChronologyID);
			   ParentForm->StatusBar1->Panels->Items[0]->Text = SampleAges.WebServiceName();
			   if (SampleAges.Execute())
				 ChronSampleAges[DatasetChrons.Items[j].ChronologyID] = SampleAges.Items;
			   else
				 return (success = false);
			   }
			 }

		   // get sample analysts
		   NeotomaDatasetSampleAnalysts SampleAnalysts(ipsJSONS1, TcpClient1);
		   SampleAnalysts.AddParam(L"DATASETID", Datasets[i].NeotomaDatasetID);
		   ParentForm->StatusBar1->Panels->Items[0]->Text = SampleAnalysts.WebServiceName();
		   if (!SampleAnalysts.Execute())
			 return (success = false);

		   // get sample keywords
		   NeotomaDatasetSampleKeywords SampleKeywords(ipsJSONS1, TcpClient1);
		   SampleKeywords.AddParam(L"DATASETID", Datasets[i].NeotomaDatasetID);
		   ParentForm->StatusBar1->Panels->Items[0]->Text = SampleKeywords.WebServiceName();
		   if (!SampleKeywords.Execute())
			 return (success = false);

		   // get sample depositional agents
		   NeotomaDatasetSampleDepAgents SampleDepAgents(ipsJSONS1, TcpClient1);
		   SampleDepAgents.AddParam(L"DATASETID", Datasets[i].NeotomaDatasetID);
		   ParentForm->StatusBar1->Panels->Items[0]->Text = SampleDepAgents.WebServiceName();
		   if (!SampleDepAgents.Execute())
			 return (success = false);

		   map<int,CONTACT*> ContactMap;  // ContactID, CONTACT*
		   if (!GetSampleAnalysts(ContactMap, SampleAnalysts))
             return (success = false);

		   if (NeotomaSamples.Size() == 0) {
			 msg = L"Dataset " + IntToStr(Datasets[i].NeotomaDatasetID) + L" has no samples.";
			 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
			 continue;
			 }

		   nssdatasets++;
		   bool all_depths = true;   // true if all samples have depths
		   // see if all samples have depths
		   for (unsigned int j=0; j<NeotomaSamples.Size(); j++) {
			 if (NeotomaSamples.Items[j].Depth.IsEmpty()) {
			   all_depths = false;
			   break;
			   }
			 }
		   if (all_depths)  // if so, sort by depths
			 NeotomaSamples.SortSampleDepths();

		   if (nssdatasets == 1) {
			 ProfGrid1->AbsoluteCells[1][1]->Value = WideString(Datasets[0].DatasetType);
			 cxComboBox2->Text = Datasets[0].DatasetType;
			 next_col = AbsHeaderColCount(ProfGrid1);
			 for (unsigned int j=0; j<NeotomaSamples.Size(); j++) {
			   ProfGrid1->AbsoluteCells[next_col][1]->CustomData = NeotomaSamples.Items[j].SampleID;   // SampleID to SS
			   ProfGrid1->AbsoluteCells[next_col][2]->CustomData = NeotomaSamples.Items[j].AnalysisUnitID;  //AnalysisUnitID to SS
			   au_col_idx[NeotomaSamples.Items[j].AnalysisUnitID] = next_col;
			   col_idx[NeotomaSamples.Items[j].SampleID] = next_col++;
			   if (next_col >= ProfGrid1->ColCount)
				 ProfGrid1->ColCount += 256;
			   }
			 }
		   else {
			 sampleid_col_idx.clear();
			 for (unsigned int j=0; j<NeotomaSamples.Size(); j++) {
			   if (au_col_idx.count(NeotomaSamples.Items[j].AnalysisUnitID) == 0) {
				 ProfGrid1->AbsoluteCells[next_col][2]->CustomData = NeotomaSamples.Items[j].AnalysisUnitID;
				 au_col_idx[NeotomaSamples.Items[j].AnalysisUnitID] = next_col;
				 sampleid_col_idx.push_back(pair<int,int>(NeotomaSamples.Items[j].SampleID,next_col));
				 col_idx[NeotomaSamples.Items[j].SampleID] = next_col++;
                 if (next_col >= ProfGrid1->ColCount)
				   ProfGrid1->ColCount += 256;
				 }
			   else {
				 sampleid_col_idx.push_back(pair<int,int>(NeotomaSamples.Items[j].SampleID,au_col_idx[NeotomaSamples.Items[j].AnalysisUnitID]));
				 col_idx[NeotomaSamples.Items[j].SampleID] = au_col_idx[NeotomaSamples.Items[j].AnalysisUnitID];
				 }
			   }
			 }

		   // if first dataset, get chron variables
		   // map<int,map<int,NTMSAMPLEAGE> > ChronSampleAges;  // ChronologyID, SampleID, NTMSAMPLEAGE
		   if (nssdatasets == 1) {
			 if (DatasetChrons.Size() > 0) {
			   int ChronNo = 1;
			   for (unsigned int j=0; j<DatasetChrons.Size(); j++) {
				 int ChronID = DatasetChrons.Items[j].ChronologyID;
				 map<int,NTMSAMPLEAGE>::iterator itr;
				 map<int,NTMSAMPLEAGE>::iterator begin = ChronSampleAges[ChronID].begin();
				 map<int,NTMSAMPLEAGE>::iterator end = ChronSampleAges[ChronID].end();
				 bool age = false;
				 bool age_younger = false;
				 bool age_older = false;;
				 for (itr = begin; itr != end; itr++) {
				   if (!age && !itr->second.Age.IsEmpty())
					 age = true;
				   if (!age_younger && !itr->second.AgeYounger.IsEmpty())
					 age_younger = true;
				   if (!age_older && !itr->second.AgeOlder.IsEmpty())
					 age_older = true;
				   if (age && age_younger && age_older)
					 break;
				   }
				 AGEROWS AgeRows;
				 WideString VarCode = WideString("#Chron" + IntToStr(ChronNo++));  // #Chron1
				 WideString ChronName = WideString(DatasetChrons.Items[j].ChronologyName);
				 WideString AgeType = WideString(DatasetChrons.Items[j].ShortAgeType);
				 if (age) {
				   int row = next_row++;
				   AgeRows.Row = row;
				   ProfGrid1->AbsoluteCells[1][row]->Value = VarCode;
				   ProfGrid1->AbsoluteCells[2][row]->Value = ChronName;
				   ProfGrid1->AbsoluteCells[4][row]->Value = AgeType;
				   ProfGrid1->AbsoluteCells[1][row]->CustomData = ChronID;
				   }
				 if (age_older) {
				   int row = next_row++;
				   AgeRows.OlderRow = row;
				   ProfGrid1->AbsoluteCells[1][row]->Value = VarCode + WideString(".Old");
				   ProfGrid1->AbsoluteCells[2][row]->Value = ChronName + WideString(" Older Bound");
				   ProfGrid1->AbsoluteCells[4][row]->Value = AgeType;
				   ProfGrid1->AbsoluteCells[1][row]->CustomData = ChronID;
				   }
				 if (age_younger) {
				   int row = next_row++;
				   AgeRows.YoungerRow = row;
				   ProfGrid1->AbsoluteCells[1][row]->Value = VarCode + WideString(".Young");
				   ProfGrid1->AbsoluteCells[2][row]->Value = ChronName + WideString(" Younger Bound");
				   ProfGrid1->AbsoluteCells[4][row]->Value = AgeType;
				   ProfGrid1->AbsoluteCells[1][row]->CustomData = ChronID;
				   }
				 age_rows[ChronID] = AgeRows;
				 }
			   }
			 }
		   else {  // enter dataset line
			 int row = next_row++;
			 sampid_row = row;
			 ProfGrid1->AbsoluteCells[1][row]->Value = WideString("#Data.Type");
			 ProfGrid1->AbsoluteCells[2][row]->Value = WideString(Datasets[i].DatasetType);

			 for (unsigned int j = 0; j < sampleid_col_idx.size(); j++)
			   ProfGrid1->AbsoluteCells[sampleid_col_idx[j].second][row]->CustomData = sampleid_col_idx[j].first;

			 special_formatting = true;
			 }

		   // write sample and analysis unit metadata to spreadsheet
		   for (unsigned int j=0; j<NeotomaSamples.Size(); j++) {
			 int SampleID = NeotomaSamples.Items[j].SampleID;
			 int col = col_idx[SampleID];
			 // Neotoma SampleID
			 ProfGrid1->AbsoluteCells[col][sampid_row]->CustomData = SampleID;

			 // analysis unit depth
			 if (!NeotomaSamples.Items[j].Depth.IsEmpty()) {
			   double depth = NeotomaSamples.Items[j].Depth;
			   ProfGrid1->AbsoluteCells[col][1]->Value = depth;
			   }
			 // analysis unit name
			 if (!NeotomaSamples.Items[j].AnalysisUnitName.IsEmpty())
			   ProfGrid1->AbsoluteCells[col][2]->Value = WideString(NeotomaSamples.Items[j].AnalysisUnitName);

			 // TODO: Alt Depth Scales

			 // chronologies
			 // map<int,map<int,NTMSAMPLEAGE> > ChronSampleAges;  // ChronologyID, SampleID, NTMSAMPLEAGE
			 for (unsigned int j=0; j<DatasetChrons.Size(); j++) {
			   int ChronID = DatasetChrons.Items[j].ChronologyID;
			   map<int,NTMSAMPLEAGE>::iterator itr = ChronSampleAges[ChronID].find(SampleID);
			   if (itr != ChronSampleAges[ChronID].end()) {
				 if (!itr->second.Age.IsEmpty()) {
				   double age = itr->second.Age;
				   ProfGrid1->AbsoluteCells[col][age_rows[ChronID].Row]->Value = age;
				   }
				 if (!itr->second.AgeOlder.IsEmpty()) {
				   double age_older = itr->second.AgeOlder;
				   ProfGrid1->AbsoluteCells[col][age_rows[ChronID].OlderRow]->Value = age_older;
				   }
				 if (!itr->second.AgeYounger.IsEmpty()) {
				   double age_younger = itr->second.AgeYounger;
				   ProfGrid1->AbsoluteCells[col][age_rows[ChronID].YoungerRow]->Value = age_younger;
				   }
				 }
			   }

			 // analysis unit thickness
			 if (!NeotomaSamples.Items[j].Thickness.IsEmpty()) {
			   if (thick_row == 0) {
				 thick_row = next_row++;
				 ProfGrid1->AbsoluteCells[1][thick_row]->Value = WideString("#Anal.Thick");
				 ProfGrid1->AbsoluteCells[2][thick_row]->Value = WideString("Analysis Unit Thickness");
				 }
			   double thick = NeotomaSamples.Items[j].Thickness;
			   ProfGrid1->AbsoluteCells[col][thick_row]->Value = thick;
			   }

			 // facies
			 if (!NeotomaSamples.Items[j].Facies.IsEmpty()) {
			   if (facies_row == 0) {
				 facies_row = next_row++;
				 ProfGrid1->AbsoluteCells[1][facies_row]->Value = WideString("#Anal.Facies");
				 ProfGrid1->AbsoluteCells[2][facies_row]->Value = WideString("Analysis Unit Facies");
				 }
			   ProfGrid1->AbsoluteCells[col][facies_row]->Value = WideString(NeotomaSamples.Items[j].Facies);
			   }

			 // depositional agents
			 if (SampleDepAgents.Items.count(SampleID) > 0) {
			   if (depagents_row == 0) {
				 depagents_row = next_row++;
				 ProfGrid1->AbsoluteCells[1][depagents_row]->Value = WideString("#Anal.DepAgent");
				 ProfGrid1->AbsoluteCells[2][depagents_row]->Value = WideString("Analysis Unit Depositional Agent");
				 }
			   multimap<int,UnicodeString>::iterator itr;      // SampleID, DepAgent
			   pair<multimap<int,UnicodeString>::iterator, multimap<int,UnicodeString>::iterator> range;
			   range = SampleDepAgents.Items.equal_range(SampleID);
			   WideString Text;
			   for (itr=range.first; itr!=range.second; itr++) {
				 if (!Text.IsEmpty())
				   Text += WideString(";");
				 Text += WideString(itr->second);
				 }
			   ProfGrid1->AbsoluteCells[col][depagents_row]->Value = Text;
			   }

			 // mixed
			 if (NeotomaSamples.Items[j].Mixed) {
			   if (mixed_row == 0) {
				 mixed_row = next_row++;
				 ProfGrid1->AbsoluteCells[1][mixed_row]->Value = WideString("#Anal.Mixed");
				 ProfGrid1->AbsoluteCells[2][mixed_row]->Value = WideString("Analysis Unit Mixed");
				 int StartCol = AbsHeaderColCount(ProfGrid1);
				 int EndCol = ProfGrid1->AbsoluteColCount;
				 for (int col=StartCol; col<EndCol; col++) {
				   TProfGridCell *ACell = ProfGrid1->AbsoluteCells[col][mixed_row];
				   ACell->CheckBox = true;
				   }
				 }
			   ProfGrid1->AbsoluteCells[col][mixed_row]->CheckBoxChecked = true;
			   special_formatting = true;
			   }

			 // IGSN
			 if (!NeotomaSamples.Items[j].IGSN.IsEmpty()) {
			   if (IGSN_row == 0) {
				 IGSN_row = next_row++;
				 ProfGrid1->AbsoluteCells[1][IGSN_row]->Value = WideString("#Anal.IGSN");
				 ProfGrid1->AbsoluteCells[2][IGSN_row]->Value = WideString("International Geo Sample Number");
				 }
			   ProfGrid1->AbsoluteCells[col][IGSN_row]->Value = WideString(NeotomaSamples.Items[j].IGSN);
			   }

			 // analysis unit notes
			 if (!NeotomaSamples.Items[j].AnalUnitNotes.IsEmpty()) {
			   if (analunitnotes_row == 0) {
				 analunitnotes_row = next_row++;
				 ProfGrid1->AbsoluteCells[1][analunitnotes_row]->Value = WideString("#Anal.Notes");
				 ProfGrid1->AbsoluteCells[2][analunitnotes_row]->Value = WideString("Analysis Unit Notes");
				 }
			   ProfGrid1->AbsoluteCells[col][analunitnotes_row]->Value = WideString(NeotomaSamples.Items[j].AnalUnitNotes);
			   }

			 // sample name
			 if (!NeotomaSamples.Items[j].SampleName.IsEmpty()) {
			   if (sampname_row == 0) {
				 sampname_row = next_row++;
				 ProfGrid1->AbsoluteCells[1][sampname_row]->Value = WideString("#Samp.Name");
				 ProfGrid1->AbsoluteCells[2][sampname_row]->Value = WideString("Sample Name");
				 }
			   ProfGrid1->AbsoluteCells[col][sampname_row]->Value = WideString(NeotomaSamples.Items[j].SampleName);
			   }

			 // TODO: sampled taxon

			 // sample analyst
			 if (SampleAnalysts.Items.count(SampleID) > 0) {
			   if (analyst_row == 0) {
				 analyst_row = next_row++;
				 ProfGrid1->AbsoluteCells[1][analyst_row]->Value = WideString("#Samp.Analyst");
				 ProfGrid1->AbsoluteCells[2][analyst_row]->Value = WideString("Sample Analyst");
				 }
			   multimap<int,int>::iterator itr;      // SampleID, ContactID
			   pair<multimap<int,int>::iterator, multimap<int,int>::iterator> range;
			   range = SampleAnalysts.Items.equal_range(SampleID);
			   set<UnicodeString> Names;
			   TProfGridCell *ACell = ProfGrid1->AbsoluteCells[col][analyst_row];
			   TList* Contacts;
			   CELLOBJECT* CellObject;
			   if (ACell->CellObject != NULL)
				 CellObject = (CELLOBJECT*)ACell->CellObject;
			   else {
				 CellObject = new CELLOBJECT(CELLCONTACTS);
				 AddCellObject(ACell, CellObject);
				 }
			   Contacts = (TList*)CellObject->Object;
			   for (itr=range.first; itr!=range.second; itr++) {
				 CONTACT* Contact = ContactMap[itr->second];
				 Contacts->Add(Contact);
				 Names.insert(Contact->ShortContactName);
				 }
			   WideString Text;
			   for (set<UnicodeString>::iterator itr = Names.begin(); itr != Names.end(); itr++) {
				 if (!Text.IsEmpty())
				   Text += WideString(";");
				 Text += WideString(*itr);
				 }
			   ACell->Value = Text;
			   }

			 // date analyzed
			 if (!NeotomaSamples.Items[j].AnalysisDate.IsEmpty()) {
			   if (dateanal_row == 0) {
				 dateanal_row = next_row++;
				 ProfGrid1->AbsoluteCells[1][dateanal_row]->Value = WideString("#Samp.DateAnal");
				 ProfGrid1->AbsoluteCells[2][dateanal_row]->Value = WideString("Date Analyzed");
				 }
			   ProfGrid1->AbsoluteCells[col][dateanal_row]->Value = NeotomaSamples.Items[j].AnalysisDate;
			   }

			 // date sampled
			 if (!NeotomaSamples.Items[j].SampleDate.IsEmpty()) {
			   if (datesamp_row == 0) {
				 datesamp_row = next_row++;
				 ProfGrid1->AbsoluteCells[1][datesamp_row]->Value = WideString("#Samp.DateSamp");
				 ProfGrid1->AbsoluteCells[2][datesamp_row]->Value = WideString("Date Sampled");
				 }
			   ProfGrid1->AbsoluteCells[col][datesamp_row]->Value = NeotomaSamples.Items[j].SampleDate;
			   }

			 // lab number
			 if (!NeotomaSamples.Items[j].LabNumber.IsEmpty()) {
			   if (labnumber_row == 0) {
				 labnumber_row = next_row++;
				 ProfGrid1->AbsoluteCells[1][labnumber_row]->Value = WideString("#Samp.LabNum");
				 ProfGrid1->AbsoluteCells[2][labnumber_row]->Value = WideString("Lab Number");
				 }
			   ProfGrid1->AbsoluteCells[col][labnumber_row]->Value = WideString(NeotomaSamples.Items[j].LabNumber);
			   }

			 // preparation method
			 if (!NeotomaSamples.Items[j].PreparationMethod.IsEmpty()) {
			   if (method_row == 0) {
				 method_row = next_row++;
				 ProfGrid1->AbsoluteCells[1][method_row]->Value = WideString("#Samp.Method");
				 ProfGrid1->AbsoluteCells[2][method_row]->Value = WideString("Preparation Method");
				 }
			   ProfGrid1->AbsoluteCells[col][method_row]->Value = WideString(NeotomaSamples.Items[j].PreparationMethod);
			   }

			 // sample notes
			 if (!NeotomaSamples.Items[j].SampleNotes.IsEmpty()) {
			   if (sampnotes_row == 0) {
				 sampnotes_row = next_row++;
				 ProfGrid1->AbsoluteCells[1][sampnotes_row]->Value = WideString("#Samp.Notes");
				 ProfGrid1->AbsoluteCells[2][sampnotes_row]->Value = WideString("Sample Notes");
				 }
			   ProfGrid1->AbsoluteCells[col][sampnotes_row]->Value = WideString(NeotomaSamples.Items[j].SampleNotes);
			   }

			 // key words
			 if (SampleKeywords.Items.count(SampleID) > 0) {
			   if (keywords_row == 0) {
				 keywords_row = next_row++;
				 ProfGrid1->AbsoluteCells[1][keywords_row]->Value = WideString("#Samp.Keywords");
				 ProfGrid1->AbsoluteCells[2][keywords_row]->Value = WideString("Sample Keywords");
				 }
			   multimap<int,UnicodeString>::iterator itr;      // SampleID, Keyword
			   pair<multimap<int,UnicodeString>::iterator, multimap<int,UnicodeString>::iterator> range;
			   range = SampleKeywords.Items.equal_range(SampleID);
			   WideString Text;
			   for (itr=range.first; itr!=range.second; itr++) {
				 if (SameText(itr->second, L"modern"))
				   Datasets[i].IsSSamp = true;
				 if (!Text.IsEmpty())
				   Text += WideString(";");
				 Text += WideString(itr->second);
				 }
			   ProfGrid1->AbsoluteCells[col][keywords_row]->Value = Text;
			   }
			 }

		   // get variables
		   NeotomaDatasetVariables DatasetVars(ipsJSONS1, TcpClient1);
		   DatasetVars.AddParam(L"DATASETID", Datasets[i].NeotomaDatasetID);
		   ParentForm->StatusBar1->Panels->Items[0]->Text = DatasetVars.WebServiceName();
		   if (!DatasetVars.Execute())
			 return (success = false);

		   // get synonyms
		   NeotomaDatasetSynonyms DatasetSynonyms(ipsJSONS1, TcpClient1);
		   DatasetSynonyms.AddParam(L"DATASETID", Datasets[i].NeotomaDatasetID);
		   ParentForm->StatusBar1->Panels->Items[0]->Text = DatasetSynonyms.WebServiceName();
		   if (!DatasetSynonyms.Execute())
			 return (success = false);

		   // get dataset taxon notes
		   NeotomaDatasetTaxonNotes DatasetTaxonNotes(ipsJSONS1, TcpClient1);
		   DatasetTaxonNotes.AddParam(L"DATASETID", Datasets[i].NeotomaDatasetID);
		   ParentForm->StatusBar1->Panels->Items[0]->Text = DatasetTaxonNotes.WebServiceName();
		   if (!DatasetTaxonNotes.Execute())
			 return (success = false);

		   // get data
		   NeotomaDatasetData DatasetData(ipsJSONS1, TcpClient1);
		   DatasetData.AddParam(L"DATASETID", Datasets[i].NeotomaDatasetID);
		   ParentForm->StatusBar1->Panels->Items[0]->Text = DatasetData.WebServiceName();
		   if (!DatasetData.Execute())
			 return (success = false);

		   // If variable has multiple taphonomic types, they will occur as
		   // multiple records in DatasetData. Accumulate everything into
		   // a single record for each DataID, placing TaphonomicTypeIDs in a set.
		   map<int,TILIADATA> TilData; // DataID, TILIADATA
		   for (unsigned int j=0; j<DatasetData.Size(); j++) {
			 NTMDATASETDATA& ddata = DatasetData.Items[j];
			 map<int,TILIADATA>::iterator itr = TilData.find(ddata.DataID);
			 if (itr == TilData.end()) {
			   TILIADATA ndata;
			   ndata.SampleID = ddata.SampleID;
			   ndata.VariableID = ddata.VariableID;
			   ndata.Value = ddata.Value;
			   if (ddata.TaphonomicTypeID > -1)
				 ndata.TaphTypeIDs.insert(ddata.TaphonomicTypeID);
			   TilData[ddata.DataID] = ndata;
			   }
			 else if (ddata.TaphonomicTypeID > -1)
			   itr->second.TaphTypeIDs.insert(ddata.TaphonomicTypeID);
			 }

		   // check if any variables have different combinations of TaphonomicTypeIDs
		   // first get multimap of VariableIDs and TaphonomicTypeID sets
		   multimap<int,set<int> > VarTaph;  // VariableID, set of TaphonomicTypeIDs
		   map<int,TILIADATA>::iterator titr;
		   map<int,TILIADATA>::iterator tbegin = TilData.begin();
		   map<int,TILIADATA>::iterator tend = TilData.end();
		   for (titr = tbegin; titr != tend; titr++) {
			 TILIADATA& ndata = titr->second;
			 if (VarTaph.count(ndata.VariableID) == 0) {
			   VarTaph.insert(pair<int,set<int> >(ndata.VariableID, ndata.TaphTypeIDs));
			   }
			 else {
			   multimap<int,set<int> >::iterator itr;
			   pair<multimap<int,set<int> >::iterator, multimap<int,set<int> >::iterator> range;
			   range = VarTaph.equal_range(ndata.VariableID);
			   bool taphset_found = false;
			   for (itr = range.first; itr != range.second; itr++) {
				 if (sets_equal(ndata.TaphTypeIDs, itr->second)) {
				   taphset_found = true;
				   break;
				   }
				 }
			   if (!taphset_found)
				 VarTaph.insert(pair<int,set<int> >(ndata.VariableID, ndata.TaphTypeIDs));
			   }
			 }

		   // get all TaphonomicTypeIDs
		   NeotomaTaphonomicTypesByIDList TaphTypes(ipsJSONS1, TcpClient1);
		   if (VarTaph.size() > 0) {
			 set<int> TaphTypeIDs;
			 multimap<int,set<int> >::iterator itr;
			 for (itr = VarTaph.begin(); itr != VarTaph.end(); itr++) {
			   set<int>& TaphIDs = itr->second;
			   if (TaphIDs.size() > 0) {
				 for (set<int>::iterator it=TaphIDs.begin(); it != TaphIDs.end(); it++) {
				   if (TaphTypeIDs.count(*it) == 0)
					 TaphTypeIDs.insert(*it);
				   }
				 }
			   }
			 // get names for TaphonomicTypeIDs
			 set<int>::iterator tbegin = TaphTypeIDs.begin();
			 UnicodeString TaphTypeIDList = IntToStr(*tbegin);
			 tbegin++;
			 for (set<int>::iterator titr=tbegin; titr != TaphTypeIDs.end(); titr++)
			   TaphTypeIDList += (L"$" + IntToStr(*titr));
			 TaphTypes.AddParam(L"TAPHONOMICTYPEIDS", TaphTypeIDList);
			 ParentForm->StatusBar1->Panels->Items[0]->Text = TaphTypes.WebServiceName();
			 if (!TaphTypes.Execute())
			   return (success = false);
			 }

		   // write variables to spreadsheet and generate variable row index
		   int dataset_row1 = next_row;
		   vector<pair<VARTAPH,int> > row_idx;  // VARTAPH {VariableID, set<int> TaphIDs}, row
		   for (unsigned int j=0; j<DatasetVars.Size(); j++) {
			 NTMDATASETVARIABLE& var = DatasetVars.Items[j];
			 multimap<int,set<int> >::iterator itr;
			 pair<multimap<int,set<int> >::iterator, multimap<int,set<int> >::iterator> range;
			 range = VarTaph.equal_range(var.VariableID);
			 for (itr = range.first; itr != range.second; itr++) {
			   //ProfGrid1->AbsoluteCells[0][next_row]->CustomData = var.VariableID;
			   ProfGrid1->AbsoluteCells[1][next_row]->CustomData = var.VariableID;
			   ProfGrid1->AbsoluteCells[1][next_row]->Value = WideString(var.TaxonCode);
			   ProfGrid1->AbsoluteCells[2][next_row]->Value = WideString(var.TaxonName);
			   ProfGrid1->AbsoluteCells[3][next_row]->Value = WideString(var.VariableElement);
			   ProfGrid1->AbsoluteCells[4][next_row]->Value = WideString(var.VariableUnits);
			   ProfGrid1->AbsoluteCells[5][next_row]->Value = WideString(var.VariableContext);
			   // taphonomy
			   set<int>& TaphIDs = itr->second;
			   VARTAPH VarTaph(var.VariableID, TaphIDs);
			   row_idx.push_back(pair<VARTAPH,int>(VarTaph,next_row));
			   if (TaphIDs.size() > 0) {
				 TProfGridCell* ACell = ProfGrid1->AbsoluteCells[6][next_row];
				 CELLOBJECT* CellObject = new CELLOBJECT(CELLTAPHONOMY);
				 TAPHSYSTEMS* TaphSystems = (TAPHSYSTEMS*)CellObject->Object;
				 TaphSystems->DatasetType = Datasets[i].DatasetType;
				 AddCellObject(ACell, CellObject);
				 for (set<int>::iterator it = TaphIDs.begin(); it != TaphIDs.end(); it++) {
				   UnicodeString SystemName = TaphTypes.Items[*it].TaphonomicSystem;
				   UnicodeString Type = TaphTypes.Items[*it].TaphonomicType;
				   vector<TAPHSYSTEM>::iterator sysitr;
				   vector<TAPHSYSTEM>::iterator sysbegin = TaphSystems->Systems.begin();
				   vector<TAPHSYSTEM>::iterator sysend = TaphSystems->Systems.end();
				   int idx = -1;
				   for (unsigned int k=0; k<TaphSystems->Systems.size(); k++) {
					 if (SameText(TaphSystems->Systems[k].Name, SystemName)) {
					   idx = k;
					   break;
					   }
					 }
				   if (idx == -1) {
					 TAPHSYSTEM TaphSystem;
					 TaphSystem.Name = TaphTypes.Items[*it].TaphonomicSystem;
					 TaphSystems->Systems.push_back(TaphSystem);
					 idx = TaphSystems->Systems.size() - 1;
					 }

				   if (TaphonomyLookup == NULL) {
					 TaphonomyLookup = new TAPHONOMYLOOKUP;
					 VarLookup->SetTaphonomyLookup(TaphonomyLookup);
					 }

				   if (TaphSystems->Systems[idx].Types.count(Type) == 0)
					 TaphSystems->Systems[idx].Types.insert(Type);
				   TaphonomyLookup->Add(TaphSystems->DatasetType, SystemName, Type);
				   }
				 ProfGrid1->AbsoluteCells[6][next_row]->Value = WideString(TaphSystems->Text());
				 }
			   next_row++;
			   }
			 }
		   int dataset_row2 = next_row;
		   BuildTaphonomy();

		   vector<NTMVARECOLGROUP> VarGroups;

		   // groups
		   unsigned int varend = 1;
		   unsigned int varbeg = 0;
		   do {
				UnicodeString VarIDs = IntToStr(DatasetVars.Items[varbeg++].VariableID);
				for (unsigned int j=varbeg; j<DatasetVars.Size(); j++) {
				  UnicodeString NextVar = L"$" + IntToStr(DatasetVars.Items[j].VariableID);
				  if (VarIDs.Length() + NextVar.Length() < 1500) {
					VarIDs += NextVar;
					varend = j + 1;
					}
				  else {
					varbeg = j;
					varend = j + 1;
					break;
					}
				  }
				NeotomaEcolGroupsByVariableIDList Groups(ipsJSONS1, TcpClient1);
				Groups.AddParam(L"VARIABLEIDS", VarIDs);
				ParentForm->StatusBar1->Panels->Items[0]->Text = Groups.WebServiceName();
				if (Groups.Execute())
				  VarGroups.insert(VarGroups.end(),Groups.Items.begin(),Groups.Items.end());
				else
				  return (success = false);
			  } while (varend < DatasetVars.Size());

		   // TODO: in future deal with situation if multi EcolSets oxist

		   for (unsigned int j=0; j<row_idx.size(); j++) {
			 int VariableID = row_idx[j].first.VariableID;
			 int row = row_idx[j].second;
			 for (unsigned int k=0; k<VarGroups.size(); k++) {
			   if (VariableID == VarGroups[k].VariableID) {
				 ProfGrid1->AbsoluteCells[7][row]->Value = WideString(VarGroups[k].EcolGroupID);
				 break;
				 }
			   }
			 }

		   // synonyms
		   TAXON_NOTES* TaxonNotes;
		   for (unsigned int j=0; j<DatasetSynonyms.Size(); j++) {
			 for (int row=dataset_row1; row<dataset_row2; row++) {
			   TProfGridCell* ACell = ProfGrid1->AbsoluteCells[2][row];
			   if (SameText(ACell->Text, DatasetSynonyms.Items[j].ValidName)) {
				 CELLOBJECT* CellObject;
				 if (ACell->CellObject != NULL)
				   CellObject = (CELLOBJECT*)ACell->CellObject;
				 else {
				   CellObject = new CELLOBJECT(CELLTAXONNOTES);
				   AddCellObject(ACell, CellObject);
				   AddTaxonNotesIcon(ACell);
				   }
				 TaxonNotes = (TAXON_NOTES*)CellObject->Object;
				 SYNONYMY Synonym;
				 Synonym.NeotomaSynonymyID = DatasetSynonyms.Items[j].SynonymyID;
				 Synonym.TaxonName = DatasetSynonyms.Items[j].RefName;
				 Synonym.Contrib = DatasetSynonyms.Items[j].FromContributor;
				 if (!DatasetSynonyms.Items[j].PublicationID.IsEmpty()) {
				   Synonym.PubID = DatasetSynonyms.Items[j].PublicationID;
				   if (Publications->Count > 0) {
					 for (int i=0; i<Publications->Count; i++) {
					   PUBLICATION* pub = (PUBLICATION*)Publications->Items[i];
					   if (Synonym.PubID == pub->NeotomaID)
						 Synonym.Pub = pub;
						 break;
					   }
					 }
				   if (Synonym.Pub == NULL) {
					 NeotomaPublicationsByPubID NeotomaPub(ipsJSONS1, TcpClient1);
					 NeotomaPub.AddParam(L"PUBLICATIONID", Synonym.PubID);
					 ParentForm->StatusBar1->Panels->Items[0]->Text = NeotomaPub.WebServiceName();
					 if (NeotomaPub.Execute()) {
					   if (NeotomaPub.Size() > 0)
						 Synonym.Pub = GetNeotomaPub(Datasets[i].NeotomaDatasetID, Publications, NeotomaPub.Items[0]);
					   }
					 else
					   return (success = false);
					 }
				   }
				 Synonym.Notes = DatasetSynonyms.Items[j].Notes;
				 TaxonNotes->Synonymy.push_back(Synonym);
				 break;
				 }
			   }
			 }

		   // DatasetTaxonNotes  DATASETTAXONNOTES
		   for (unsigned int j=0; j<DatasetTaxonNotes.Size(); j++) {
			 for (int row=dataset_row1; row<dataset_row2; row++) {
			   TProfGridCell* ACell = ProfGrid1->AbsoluteCells[2][row];
			   if (SameText(ACell->Text, DatasetTaxonNotes.Items[j].TaxonName)) {
				 CELLOBJECT* CellObject;
				 if (ACell->CellObject != NULL)
				   CellObject = (CELLOBJECT*)ACell->CellObject;
				 else {
				   CellObject = new CELLOBJECT(CELLTAXONNOTES);
				   AddCellObject(ACell, CellObject);
				   }
				 TaxonNotes = (TAXON_NOTES*)CellObject->Object;
				 TaxonNotes->Notes = DatasetTaxonNotes.Items[j].Notes;
				 break;
				 }
			   }
			 }

		   // get specimen data
		   NeotomaDatasetSpecimens Specimens(ipsJSONS1, TcpClient1);
		   Specimens.AddParam(L"DATASETID", Datasets[i].NeotomaDatasetID);
		   ParentForm->StatusBar1->Panels->Items[0]->Text = Specimens.WebServiceName();
		   if (!Specimens.Execute())
			 return (success = false);

		   NeotomaDatasetSpecimenGenBankNrs GenBank(ipsJSONS1, TcpClient1);
		   NeotomaDatasetSpecimenTaphonomy SpecTaph(ipsJSONS1, TcpClient1);
		   bool has_specimens = (Specimens.Size() > 0);
		   if (has_specimens) {
			 // get specimen GenBank numbers
			 GenBank.AddParam(L"DATASETID", Datasets[i].NeotomaDatasetID);
			 ParentForm->StatusBar1->Panels->Items[0]->Text = GenBank.WebServiceName();
			 if (!GenBank.Execute())
			   return (success = false);
			 // get specimen taphonomy
			 SpecTaph.AddParam(L"DATASETID", Datasets[i].NeotomaDatasetID);
			 ParentForm->StatusBar1->Panels->Items[0]->Text = SpecTaph.WebServiceName();
			 if (!SpecTaph.Execute())
			   return (success = false);
			 }

		   // Alright! Load data
		   // map<int,TILIADATA> TilData; // DataID, TILIADATA
		   map<int,TILIADATA>::iterator itr;
		   map<int,TILIADATA>::iterator begin = TilData.begin();
		   map<int,TILIADATA>::iterator end = TilData.end();
		   for (itr = begin; itr != end; itr++) {
			 int DataID = itr->first;
			 TILIADATA& data = itr->second;
			 int col = col_idx[data.SampleID];
			 int row;
			 VARTAPH VarTaph(data.VariableID, data.TaphTypeIDs);
			 for (unsigned int j=0; j<row_idx.size(); j++) {
			   if (row_idx[j].first == VarTaph) {
				 row = row_idx[j].second;
				 break;
				 }
			   }

			 TProfGridCell* ACell = ProfGrid1->AbsoluteCells[col][row];
			 ACell->Value = data.Value;
			 ACell->CustomData = DataID;
			 if (has_specimens && Specimens.Items.count(DataID) > 0) {
			   CELLOBJECT* CellObject = new CELLOBJECT(CELLSPECIMENS);
			   AddCellObject(ACell, CellObject);
			   TList* SpecimenList = (TList*)CellObject->Object;
			   multimap<int,DATASETSPECIMEN>::iterator itr;      // DataID, DATASETSPECIMEN
			   pair<multimap<int,DATASETSPECIMEN>::iterator, multimap<int,DATASETSPECIMEN>::iterator> range;
			   range = Specimens.Items.equal_range(DataID);
			   for (itr=range.first; itr!=range.second; itr++) {
				 DATASETSPECIMEN& spec = itr->second;
				 SPECIMEN* Specimen = new SPECIMEN();
				 if (SpecimenIDs.empty())
				   Specimen->SpecimenID = 1;
				 else
				   Specimen->SpecimenID = *(SpecimenIDs.rbegin()) + 1;
				 Specimen->NeotomaSpecimenID = spec.SpecimenID;
				 Specimen->NeotomaDataID = DataID;
				 Specimen->UserSpecimenID = spec.SpecimenID;
				 Specimen->Element = spec.ElementType;
				 Specimen->Symmetry = spec.Symmetry;
				 Specimen->Portion = spec.Portion;
				 Specimen->Maturity = spec.Maturity;
				 Specimen->Sex = spec.Sex;
				 Specimen->DomesticStatus = spec.DomesticStatus;
				 Specimen->Preservative = spec.Preservative;
				 Specimen->NISP = spec.NISP;
				 Specimen->Repository = spec.Repository;
				 Specimen->SpecNr = spec.SpecimenNr;
				 Specimen->FieldNr = spec.FieldNr;
				 Specimen->ArctosNr = spec.ArctosNr;
				 Specimen->Notes = spec.Notes;
				 Specimen->Taxon = spec.TaxonName;
				 Specimen->TaxaGroup = spec.TaxaGroup;
				 // Specimen->Taphonomy
				 // typedef map<UnicodeString, set<UnicodeString> > TAPHONOMICSYSTEM;   // system, set of types
				 if (SpecTaph.Items.count(spec.SpecimenID) > 0) {
				   multimap<int,pair<UnicodeString,UnicodeString> >::iterator it;   // SpecimenID, <TaphonomicSystem, TaphonomicType>
				   pair<multimap<int,pair<UnicodeString,UnicodeString> >::iterator, multimap<int,pair<UnicodeString,UnicodeString> >::iterator> rng;
				   rng = SpecTaph.Items.equal_range(spec.SpecimenID);
				   for (it=rng.first; it!=rng.second; it++) {
					 UnicodeString System = it->second.first;
					 UnicodeString Type = it->second.second;
					 if (Specimen->Taphonomy.count(System) == 0) {
					   set<UnicodeString> Types;
					   Specimen->Taphonomy[System] = Types;
					   }
					 Specimen->Taphonomy[System].insert(Type);
					 }
				   }

				 if (GenBank.Items.count(spec.SpecimenID) > 0) {
				   multimap<int,UnicodeString>::iterator it;      // SpecimenID, GenBankNr
				   pair<multimap<int,UnicodeString>::iterator, multimap<int,UnicodeString>::iterator> rng;
				   rng = GenBank.Items.equal_range(spec.SpecimenID);
				   for (it=rng.first; it!=rng.second; it++)
					 Specimen->GenBankNrs.insert(it->second);
				   }
				 SpecimenList->Add(Specimen);
				 }
			   }
			 }
		   }
		 }

	   if (special_formatting)
		 SpecialFormating();

	   // get LOI dataset
       if ((loi_where == loiTab || loi_where == loiBoth) && loi_dataset_idx > -1) {
		 unsigned int idx = loi_dataset_idx;
		 // get samples
		 NeotomaSampleAnalUnits LOISamples(ipsJSONS1, TcpClient1);
		 LOISamples.AddParam(L"DATASETID", Datasets[idx].NeotomaDatasetID);
		 ParentForm->StatusBar1->Panels->Items[0]->Text = LOISamples.WebServiceName();
		 if (!LOISamples.Execute())
		   return (success = false);

		 // get sample analysts
		 NeotomaDatasetSampleAnalysts LOIAnalysts(ipsJSONS1, TcpClient1);
		 LOIAnalysts.AddParam(L"DATASETID", Datasets[idx].NeotomaDatasetID);
		 ParentForm->StatusBar1->Panels->Items[0]->Text = LOIAnalysts.WebServiceName();
		 if (!LOIAnalysts.Execute())
		   return (success = false);

		 map<int,CONTACT*> ContactMap;  // ContactID, CONTACT*
		 if (!GetSampleAnalysts(ContactMap, LOIAnalysts))
		   return (success = false);

		 // get variables
		 NeotomaDatasetVariables LOIVars(ipsJSONS1, TcpClient1);
		 LOIVars.AddParam(L"DATASETID", Datasets[idx].NeotomaDatasetID);
		 ParentForm->StatusBar1->Panels->Items[0]->Text = LOIVars.WebServiceName();
		 if (!LOIVars.Execute())
		   return (success = false);

		 // get data
		 NeotomaDatasetData LOIData(ipsJSONS1, TcpClient1);
		 LOIData.AddParam(L"DATASETID", Datasets[idx].NeotomaDatasetID);
		 ParentForm->StatusBar1->Panels->Items[0]->Text = LOIData.WebServiceName();
		 if (!LOIData.Execute())
		   return (success = false);

		 int temp;
		 map<int,int> VariableCols;     // VariableID, column
		 map<int,Variant> LOIVarTemps;  // VariableID, temp
		 for (unsigned int i=0; i<LOIVars.Size(); i++) {
		   if (SameText(LOIVars.Items[i].TaxonName, L"loss-on-ignition")) {
			 temp = 0;
			 if (!LOIVars.Items[i].VariableElement.IsEmpty()) {
			   UnicodeString TempStr = LOIVars.Items[i].VariableElement;
			   int pos = TempStr.Pos(L"°");
			   if (pos > 0) {
				 if (TryStrToInt(TempStr.SubString(1,pos-1), temp)) {
				   VariableCols[LOIVars.Items[i].VariableID] = (temp < 700) ? 4 : 6;
				   LOIVarTemps[LOIVars.Items[i].VariableID] = temp;
				   }
				 else {
				   VariableCols[LOIVars.Items[i].VariableID] = 4;
				   LOIVarTemps[LOIVars.Items[i].VariableID] = Variant::Empty();
				   }
				 }
			   else if (SameText(TempStr, L"organic matter")) {
				 VariableCols[LOIVars.Items[i].VariableID] = 4;
				 LOIVarTemps[LOIVars.Items[i].VariableID] = L"organic matter";
				 }
			   else if (SameText(TempStr, L"carbonate")) {
				 VariableCols[LOIVars.Items[i].VariableID] = 6;
				 LOIVarTemps[LOIVars.Items[i].VariableID] = L"carbonate";
				 }
			   }
			 }
		   else if (SameText(LOIVars.Items[i].TaxonName, L"bulk density"))
			 VariableCols[LOIVars.Items[i].VariableID] = 7;
		   }

		 map<int,int> SampleRows;  // SampleID, row

		 int row = 1;
		 for (unsigned int i=0; i<LOISamples.Size(); i++) {
		   SampleRows[LOISamples.Items[i].SampleID] = row;
		   if (!LOISamples.Items[i].Depth.IsEmpty())
			 AdvColumnGrid5->AllCells[1][row] = VariantToDouble(LOISamples.Items[i].Depth,0.0);
		   if (!LOISamples.Items[i].Thickness.IsEmpty())
			 AdvColumnGrid5->AllCells[2][row] = VariantToDouble(LOISamples.Items[i].Thickness,0.0);
		   if (!LOISamples.Items[i].AnalysisDate.IsEmpty())
			 AdvColumnGrid5->AllCells[8][row] = LOISamples.Items[i].AnalysisDate;
		   row++;
		   }

		 for (unsigned int i=0; i<LOIData.Size(); i++) {
		   int row = SampleRows[LOIData.Items[i].SampleID];
		   int col = VariableCols[LOIData.Items[i].VariableID];
		   AdvColumnGrid5->AllCells[col][row] = LOIData.Items[i].Value;
		   if (col == 4 || col == 6) {  // LOI variable
			 if (!LOIVarTemps[LOIData.Items[i].VariableID].IsEmpty())
			   AdvColumnGrid5->AllCells[col-1][row] = LOIVarTemps[LOIData.Items[i].VariableID];
			 }

		   // sample analyst
		   int SampleID = LOIData.Items[i].SampleID;
		   if (LOIAnalysts.Items.count(SampleID) > 0) {
			 pair<multimap<int,int>::iterator, multimap<int,int>::iterator> range;
			 range = LOIAnalysts.Items.equal_range(SampleID);
			 multimap<int,int>::iterator itr = range.first;  // SampleID, ContactID; only one analyst allowed
			 CONTACT* Contact = ContactMap[itr->second];
			 AdvColumnGrid5->AllObjects[9][row] = (TObject*)Contact;
			 AdvColumnGrid5->AllCells[9][row] = Contact->ShortContactName;
			 }
		   }

		 // see if all the same temp
		 GetLOITemp(3,ComboBox7);
		 GetLOITemp(5,ComboBox8);

		 loi.Investigators = Datasets[idx].Investigators;
		 loi.Publications = Datasets[idx].Publications;
		 UpdateContacts(cxCheckComboBox3, loi.Investigators);
		 UpdatePublications(cxCheckComboBox7, loi.Publications);
		 }
	   }
   __finally {
	   ProfGrid1->SpreadsheetEnabled = true;
	   ProfGrid1->EnableControls();
	   if (!success)
		 MessageDlg(ConnectError, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   ParentForm->StatusBar1->Panels->Items[0]->Text = L"";
	   }

   return success;
}
//---------------------------------------------------------------------------

bool TTilSpreadSheetForm::GetSampleAnalysts(map<int,CONTACT*>& ContactMap,
	NeotomaDatasetSampleAnalysts& SampleAnalysts)
{
   if (SampleAnalysts.Size() > 0) {
	 // get ContactIDs
	 set<int> ContactIDs;
	 multimap<int,int>::iterator itr;    // SampleID, ContactID
	 for (itr = SampleAnalysts.Items.begin(); itr != SampleAnalysts.Items.end(); itr++) {
	   if (ContactIDs.count(itr->second) == 0)
		 ContactIDs.insert(itr->second);
	   }
	 // see if Contacts already in ContactList
	 for (set<int>::iterator it = ContactIDs.begin(); it != ContactIDs.end(); it++) {
	   int AnalystContactID = *it;
	   for (int j=0; j<ContactList->Count; j++) {
		 CONTACT* Contact = ContactList->Contacts[j];
		 if (AnalystContactID == Contact->NeotomaContactID) {
		   ContactMap[AnalystContactID] = Contact;
		   break;
		   }
		 }
	   if (ContactMap.count(AnalystContactID) == 0) {  // Contact not yet in ContactList
		 NeotomaContactByID AnalystContact(ipsJSONS1, TcpClient1);
		 AnalystContact.AddParam(L"CONTACTID", AnalystContactID);
		 ParentForm->StatusBar1->Panels->Items[0]->Text = AnalystContact.WebServiceName();
		 if (AnalystContact.Execute()) {
		   if (AnalystContact.Size() > 0) {
			 CONTACT* Contact = GetNeotomaContact(AnalystContact.Items[0]);
			 if (Contact != NULL)
			   ContactMap[AnalystContactID] = Contact;
			 }
		   }
		 else
		   return false;
		 }
	   }
	 }
   return true;
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::GetLOITemp(int col, TComboBox* ComboBox)
{
   int temp;
   int temp1 = 0;
   if (TryStrToInt(AdvColumnGrid5->Cells[col][1], temp1)) {
	 for (int row=2; row<AdvColumnGrid5->RowCount; row++) {
	   if (AdvColumnGrid5->Cells[1][row].IsEmpty())  // end of data
		 break;
	   if (TryStrToInt(AdvColumnGrid5->Cells[col][row], temp)) {
		 if (temp != temp1) {
		   temp1 = 0;
		   break;
		   }
		 }
	   else {
		 temp1 = 0;
		 break;
		 }
	   }
	 }
   if (temp1 != 0)
	 ComboBox->ItemIndex = ComboBox->Items->IndexOf(IntToStr(temp1));
}
//---------------------------------------------------------------------------


