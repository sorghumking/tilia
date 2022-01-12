//---------------------------------------------------------------------------
#include <vcl.h>
#include "pch.h"
#include <VarHlpr.hpp>
#pragma hdrstop

#include "TIUpload2.h"
#ifndef TIUploadH
#include "TIUpload.h"
#endif
#ifndef TNUtilsH
#include "TNUtils.h"
#endif
#ifndef TNSubmitH
#include "TNSubmit.h"
#endif
#ifndef TIUpLatLongH
#include "TIUpLatLong.h"
#endif
#ifndef TIUpDepEnvH
#include "TIUpDepEnv.h"
#endif
#ifndef TIAdmUntH
#include "TIAdmUnt.h"
#endif
#ifndef TINtmSitFrmH
#include "TINtmSitFrm.h"
#endif
#ifndef TNColUntH
#include "TNColUnt.h"
#endif
#ifndef TNUpdSitH
#include "TNUpdSit.h"
#endif
#ifndef TNAnlUntH
#include "TNAnlUnt.h"
#endif

//---------------------------------------------------------------------------

#pragma package(smart_init)

bool TNeotomaUploadForm::UploadSite(int& SiteID)
{
   vector<int> newids;
   UnicodeString ErrorMsg;

   if (site_ptr->NeotomaSiteID > 0) {  // site already in Neotoma
	 SiteID = site_ptr->NeotomaSiteID;
	 NeotomaSiteIDs[SiteID] = site_ptr->NeotomaSiteID;
	 OutputLine(L"Data to be added to existing SiteID " + IntToStr(SiteID) + L".");
	 }
   else {   // new site
	 InsertData InsertSite(L"InsertSite", 9, ipsHTTPS1, ipsJSONS1, TcpClient1);
	 InsertSite.Add(L"SITENAME", site_ptr->SiteName);
	 InsertSite.AddDouble(L"EAST", site_ptr->LongEast);
	 InsertSite.AddDouble(L"NORTH", site_ptr->LatNorth);
	 InsertSite.AddDouble(L"WEST", site_ptr->LongWest);
	 InsertSite.AddDouble(L"SOUTH", site_ptr->LatSouth);
	 InsertSite.AddInt(L"ALTITUDE", site_ptr->Altitude);
	 InsertSite.AddDouble(L"AREA", site_ptr->Area);
	 InsertSite.Add(L"DESCRIPT", site_ptr->SiteDescription);
	 InsertSite.Add(L"NOTES", site_ptr->Notes);
	 StatusBar1->SimpleText = L"InsertSite";
	 InsertSite.PostData();
	 if (InsertSite.Post(newids, ErrorMsg)) {
	   if (newids.size() == 1) {
		 SiteID = newids[0];
		 NeotomaSiteIDs[SiteID] = site_ptr->NeotomaSiteID;
		 OutputLine(L"Site «" + site_ptr->SiteName + L"» uploaded to Sites table: SiteID = " +
		   IntToStr(SiteID) + L".");
		 }
	   else {
		 ErrorMsg = L"Error inserting into Sites table!";
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

	 // upload lake parameters
	 if (site_ptr->NeotomaLakeParams.size() > 0) {
	   InsertData InsertLakeParam(L"InsertLakeParameter", 3, ipsHTTPS1, ipsJSONS1, TcpClient1);
	   map<int,double>::iterator itr;
	   map<int,double>::iterator begin = site_ptr->NeotomaLakeParams.begin();
	   map<int,double>::iterator end = site_ptr->NeotomaLakeParams.end();
	   for (itr = begin; itr != end; itr++) {
		 InsertLakeParam.Add(L"SITEID", SiteID, -1);
		 InsertLakeParam.Add(L"LAKEPARAMETERID", itr->first);
		 InsertLakeParam.Add(L"VALUE", itr->second);
		 }
	   StatusBar1->SimpleText = L"InsertLakeParameter";
	   InsertLakeParam.PostData();
	   if (InsertLakeParam.Post(ErrorMsg))
		 OutputLine(L"Lake parameters uploaded to LakeParameters table");
	   else {
		 OutputError(L"ERROR: " + ErrorMsg);
		 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 return false;
		 }
	   }

	 // insert GeoPolitical units
	 InsertData InsertGeoPol(L"InsertSiteGeoPol", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
	 map<int,int>::iterator itr;
	 map<int,int>::iterator begin = site_ptr->NeotomaGeoPolID.begin();
	 map<int,int>::iterator end = site_ptr->NeotomaGeoPolID.end();
	 for (itr = begin; itr != end; itr++) {
	   InsertGeoPol.Add(L"SITEID", SiteID);
	   InsertGeoPol.Add(L"GEOPOLITICALID", itr->second);
	   }
	 StatusBar1->SimpleText = L"InsertSiteGeoPol";
	 InsertGeoPol.PostData();
	 if (InsertGeoPol.Post(newids, ErrorMsg)) {
	   if (newids.size() == site_ptr->NeotomaGeoPolID.size()) {
		 int i = 0;
		 for (itr = begin; itr != end; itr++) {
		   UnicodeString msg = L"Geopolitical unit «";
		   switch (itr->first) {
			 case NTM_COUNTRY:
			   msg += site_ptr->Country;
			   break;
			 case NTM_STATE:
			   msg += site_ptr->State;
			   break;
			 case NTM_COUNTY:
			   msg += site_ptr->County;
			   break;
			 case NTM_ADMINUNIT:
			   msg += site_ptr->AdminUnit;
			   break;
			 }
		   OutputLine(msg + L"» uploaded to SiteGeoPolitical table: SiteGeoPoliticalID = " +
			 IntToStr(newids[i++]) + L".");
		   }
		 }
	   else {
		 ErrorMsg = L"Error inserting into SiteGeoPolitical table!";
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

bool TNeotomaUploadForm::UploadCollUnit(int SiteID, COLLECTION& CollUnit, int& CollUnitID)
{
   // InsertCollectionUnit
   vector<int> newids;
   UnicodeString msg, ErrorMsg;

   if (CollUnit.NeotomaCollUnitID < 0) {   // new collection unit
	 AddDataToExistingCollUnit = false;
	 AddGeochronToExistingCollUnit = false;
	 InsertData InsertCollUnit(L"InsertCollectionUnit", 17, ipsHTTPS1, ipsJSONS1, TcpClient1);
	 InsertCollUnit.Add(L"HANDLE", CollUnit.Handle);
	 InsertCollUnit.Add(L"SITEID", SiteID, -1);
	 InsertCollUnit.Add(L"COLLTYPEID", CollUnit.NeotomaCollTypeID, -1);
	 InsertCollUnit.Add(L"DEPENVTID", CollUnit.NeotomaDepEnvtID, -1);
	 InsertCollUnit.Add(L"COLLUNITNAME", CollUnit.CollectionName);
	 InsertCollUnit.Add(L"COLLDATE", DateStr(CollUnit.CollDate));
	 InsertCollUnit.Add(L"COLLDEVICE", CollUnit.CollectionDevice);
	 InsertCollUnit.AddDouble(L"GPSLATITUDE", CollUnit.GPSLat);
	 InsertCollUnit.AddDouble(L"GPSLONGITUDE", CollUnit.GPSLong);
	 InsertCollUnit.AddDouble(L"GPSALTITUDE", CollUnit.GPSAltitude);
	 InsertCollUnit.AddDouble(L"GPSERROR", CollUnit.GPSError);
	 InsertCollUnit.AddDouble(L"WATERDEPTH", CollUnit.WaterDepth);
	 InsertCollUnit.Add(L"SUBSTRATEID", CollUnit.NeotomaRockTypeID, -1);
	 InsertCollUnit.Add(L"SLOPEASPECT", VariantToInt(CollUnit.SlopeAspect, -1), -1);
	 InsertCollUnit.Add(L"SLOPEANGLE", VariantToInt(CollUnit.SlopeAngle, -1), -1);
	 InsertCollUnit.Add(L"LOCATION", CollUnit.Location);
	 InsertCollUnit.Add(L"NOTES", CollUnit.Notes);
	 StatusBar1->SimpleText = L"InsertCollectionUnit";
	 InsertCollUnit.PostData();
	 if (InsertCollUnit.Post(newids, ErrorMsg)) {
	   if (newids.size() == 1) {
		 CollUnitID = newids[0];
		 NeotomaCollUnitIDs[CollUnit.NeotomaCollUnitID] = CollUnitID;
		 msg = L"Collection unit ";
		 if (!CollUnit.CollectionName.IsEmpty())
		   msg += (L"«" + CollUnit.CollectionName + L"» ");
		 msg += (L"uploaded to CollectionUnits table: CollUnitID = " + IntToStr(CollUnitID) + L".");
		 OutputLine(msg);
		 }
	   else {
		 ErrorMsg = L"Error inserting into CollectionUnits table!";
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

	 // collectors
	 if (CollUnit.Collectors.size() > 0) {
	   int order = 1;
	   InsertData InsertCollector(L"InsertCollector", 3, ipsHTTPS1, ipsJSONS1, TcpClient1);
	   for (unsigned int i=0; i<CollUnit.Collectors.size(); i++) {
		 InsertCollector.Add(L"COLLUNITID", CollUnitID, -1);
		 InsertCollector.Add(L"CONTACTID", CollUnit.Collectors[i]->NeotomaContactID, -1);
		 InsertCollector.Add(L"COLLECTORORDER", order++, -1);
		 }
	   StatusBar1->SimpleText = L"InsertCollector";
	   InsertCollector.PostData();
	   if (InsertCollector.Post(newids, ErrorMsg)) {
		 if (newids.size() == CollUnit.Collectors.size()) {
		   for (unsigned int i=0; i<newids.size(); i++) {
			 OutputLine(L"Collector «" + CollUnit.Collectors[i]->ShortContactName +
			   L"» uploaded to Collectors table: CollectorID = " + IntToStr(newids[i]) + L".");
			 }
		   }
		 else {
		   ErrorMsg = L"Error inserting into Collectors table!";
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
	 }
   else { // CollUnit already exists, adding to existing CollUnit
	 AddDataToExistingCollUnit = true;
	 CollUnitID = CollUnit.NeotomaCollUnitID;
	 NeotomaCollUnitIDs[CollUnit.NeotomaCollUnitID] = CollUnitID;
	 msg = L"Data to be added to existing CollectionUnitID " +
		   IntToStr(CollUnit.NeotomaCollUnitID) + L".";
	 OutputLine(msg);
	 }
   return true;
}
//---------------------------------------------------------------------------

/*
InsertLithology
@COLLECTIONUNITID int,
@DEPTHTOP float = null,
@DEPTHBOTTOM float = null,
@LOWERBOUNDARY nvarchar(255) = null,
@DESCRIPTION nvarchar(MAX) = null
*/
bool TNeotomaUploadForm::UploadLithology(int CollUnitID)
{
   vector<int> newids;
   UnicodeString msg, ErrorMsg;

   if (NeotomaLithUnits.size() == 0)   // nothing to upload
	 return true;

   for (unsigned int i=0; i<NeotomaLithUnits.size(); i++) {
	 if (CollUnitID != NeotomaCollUnitIDs[NeotomaLithUnits[i].CollUnitID]) {
	   OutputWarning(L"WARNING: CollUnitID " + IntToStr(CollUnitID) +
		 L" does not agree with Lithology CollUnitID + " +
		 IntToStr(NeotomaCollUnitIDs[NeotomaLithUnits[i].CollUnitID]) +
		 L". Lithology not uploaded.");
	   return true;
	   }
	 }

   InsertData InsertLithology(L"InsertLithology", 5, ipsHTTPS1, ipsJSONS1, TcpClient1);
   for (unsigned int i=0; i<NeotomaLithUnits.size(); i++) {
	 InsertLithology.Add(L"COLLECTIONUNITID", CollUnitID, -1);
	 InsertLithology.AddDouble(L"DEPTHTOP", NeotomaLithUnits[i].DepthTop);
	 InsertLithology.AddDouble(L"DEPTHBOTTOM", NeotomaLithUnits[i].DepthBottom);
	 InsertLithology.Add(L"LOWERBOUNDARY", NeotomaLithUnits[i].LowerBoundary);
	 InsertLithology.Add(L"DESCRIPTION", NeotomaLithUnits[i].UnitDescription);
	 }
   StatusBar1->SimpleText = L"InsertLithology";
   InsertLithology.PostData();
   if (InsertLithology.Post(newids, ErrorMsg)) {
	 if (newids.size() == NeotomaLithUnits.size()) {
	   msg = IntToStr((int)newids.size()) + L" lithologic unit";
	   if (newids.size() > 1)
		 msg += L"s";
	   msg += L" uploaded to Lithology table: LithologyID";
	   if (newids.size() == 1)
		 msg += (L" = " + IntToStr(newids[0]) + L".");
	   else
		 msg += (L"s = " + IntToStr(newids[0]) + L".." + IntToStr(newids.back()) + L".");
	   OutputLine(msg);
	   }
	 else {
	   ErrorMsg = L"Error inserting into Lithology table!";
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

   return true;
}
//---------------------------------------------------------------------------

/*
@COLLECTIONUNITID int,
@ANALYSISUNITNAME nvarchar(80) = null,
@DEPTH float = null,
@THICKNESS float = null,
@FACIESID int = null,
@MIXED bit = null,
@IGSN nvarchar(40) = null,
@NOTES nvarchar(MAX) = null
*/
bool TNeotomaUploadForm::UploadAnalysisUnits(int CollUnitID, vector<int>& AnalysisUnitIDs)
{
   vector<int> newids;
   UnicodeString msg, ErrorMsg;
   map<int,int> AltDepthScaleIDs;  // AltDepthID, NeotomaAltDepthScaleID

   // upload alternative depth scales
   // Note: nparams = 3 because Notes not yet operational
   if (AltDepthScales.size() > 0) {
	 InsertData InsertAltDepthScale(L"InsertAnalysisUnitAltDepthScale", 3, ipsHTTPS1, ipsJSONS1, TcpClient1);
	 map<int,ALTDEPTHS>::iterator itr;
	 for (itr = AltDepthScales.begin(); itr != AltDepthScales.end(); itr++) {
	   InsertAltDepthScale.Add(L"ALTDEPTHID", itr->first);
	   InsertAltDepthScale.Add(L"ALTDEPTHNAME", itr->second.AltDepthName);
	   InsertAltDepthScale.Add(L"VARIABLEUNITSID", itr->second.VariableUnitsID);
	   }
	 StatusBar1->SimpleText = L"InsertAnalysisUnitAltDepthScale";
	 InsertAltDepthScale.PostData();
	 if (InsertAltDepthScale.Post(newids, ErrorMsg)) {
	   if (newids.size() == AltDepthScales.size()) {
		 unsigned int i = 0;
		 for (itr = AltDepthScales.begin(); itr != AltDepthScales.end(); itr++) {
		   OutputLine(L"Alternative depth scale " + IntToStr(itr->first) + " «" +
					  itr->second.AltDepthName +
					  L"» uploaded to AnalysisUnitAltDepthScales table: AltDepthScaleID = " +
					  IntToStr(newids[i]) + L".");
		   AltDepthScaleIDs[itr->first] = newids[i++];
		   }
		 }
	   else {
		 ErrorMsg = L"Error inserting into AnalysisUnitAltDepthScales table!";
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

   // upload Analysis Units

   // check if EPD datasets are being replaced, and, if so, delete all samples in existing datasests
   if (TSSForm->EPD.SiteID > -1 && ReplaceEPDDataset) {
	 if (TSSForm->EPD.Datasets.count(1) == 1) {
	   DeleteData ClearDataset(L"UpdateEPDDataset", 1, ipsHTTPS1, ipsJSONS1, TcpClient1);
	   StatusBar1->SimpleText = L"UpdateEPDDataset";
	   int DatasetID = TSSForm->EPD.Datasets[1];
	   ClearDataset.Add(L"DATASETID", DatasetID);
	   if (ClearDataset.Post(ErrorMsg)) {
		 UnicodeString msg = L"Existing EPD geochronology dataset cleared. DatasetID = " + IntToStr(DatasetID) + L".";
		 OutputLine(msg);
		 }
	   else {
		 // ErrorMsg = L"Error clearing existing EPD geochronology DatasetID " + IntToStr(DatasetID) + L".";
		 OutputError(ErrorMsg);
		 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 return false;
		 }
	   }

	 if (TSSForm->EPD.Datasets.count(2) == 1) {
	   DeleteData ClearDataset(L"UpdateEPDDataset", 1, ipsHTTPS1, ipsJSONS1, TcpClient1);
	   StatusBar1->SimpleText = L"UpdateEPDDataset";
	   int DatasetID = TSSForm->EPD.Datasets[2];
	   ClearDataset.Add(L"DATASETID", DatasetID);
	   if (ClearDataset.Post(ErrorMsg)) {
		 UnicodeString msg = L"Existing EPD LOI dataset cleared. DatasetID = " + IntToStr(DatasetID) + L".";
		 OutputLine(msg);
		 }
	   else {
		 ErrorMsg = L"Error clearing existing EPD LOI DatasetID " + IntToStr(DatasetID) + L".";
		 OutputError(ErrorMsg);
		 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 return false;
		 }
	   }

	 if (TSSForm->EPD.Datasets.count(3) == 1) {
	   DeleteData ClearDataset(L"UpdateEPDDataset", 1, ipsHTTPS1, ipsJSONS1, TcpClient1);
	   int DatasetID = TSSForm->EPD.Datasets[3];
	   StatusBar1->SimpleText = L"UpdateEPDDataset";
	   ClearDataset.Add(L"DATASETID", DatasetID);
	   if (ClearDataset.Post(ErrorMsg)) {
		 UnicodeString msg = L"Existing EPD pollen dataset cleared. DatasetID = " + IntToStr(DatasetID) + L".";
		OutputLine(msg);
		}
	   else {
		 ErrorMsg = L"Error clearing existing EPD pollen DatasetID " + IntToStr(DatasetID) + L".";
		 OutputError(ErrorMsg);
		 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 return false;
		 }
	   }
	 }

   vector<unsigned int> AnalUnitsUploaded;
   // vector<pair<unsigned int,bool> > AnalUnitsUploaded;
   int TempCollUnitID = FindTempNeotomaCollUnitID(CollUnitID);
   InsertData InsertAnalysisUnit(L"InsertAnalysisUnit", 8, ipsHTTPS1, ipsJSONS1, TcpClient1);
   for (unsigned int i=0; i<NeotomaAnalysisUnits.size(); i++) {
	 if (NeotomaAnalysisUnits[i].CollectionUnitID == TempCollUnitID) {
	   if (NeotomaAnalysisUnits[i].AnalysisUnitID < 0) {
		 InsertAnalysisUnit.Add(L"COLLECTIONUNITID", CollUnitID);
		 InsertAnalysisUnit.Add(L"ANALYSISUNITNAME", NeotomaAnalysisUnits[i].AnalysisUnitName);
		 InsertAnalysisUnit.AddDouble(L"DEPTH", NeotomaAnalysisUnits[i].Depth);
		 InsertAnalysisUnit.AddDouble(L"THICKNESS", NeotomaAnalysisUnits[i].Thickness);
		 InsertAnalysisUnit.Add(L"FACIESID", NeotomaAnalysisUnits[i].FaciesID, -1);
		 InsertAnalysisUnit.Add(L"MIXED", NeotomaAnalysisUnits[i].Mixed);
		 InsertAnalysisUnit.Add(L"IGSN", NeotomaAnalysisUnits[i].IGSN);
		 InsertAnalysisUnit.Add(L"NOTES", NeotomaAnalysisUnits[i].Notes);
		 AnalUnitsUploaded.push_back(i);
		 }
	   else {
		 NeotomaAnalUnitIDs[NeotomaAnalysisUnits[i].AnalysisUnitID] = NeotomaAnalysisUnits[i].AnalysisUnitID;
		 AnalysisUnitIDs.push_back(NeotomaAnalysisUnits[i].AnalysisUnitID);
		 }
	   }
	 }

   if (AnalUnitsUploaded.size() > 0) {
	 newids.clear();
	 StatusBar1->SimpleText = L"InsertAnalysisUnit";
	 InsertAnalysisUnit.PostData();
	 if (InsertAnalysisUnit.Post(newids, ErrorMsg)) {
	   if (newids.size() == AnalUnitsUploaded.size()) {
		 for (unsigned int i=0; i<newids.size(); i++) {
		   int AnalUnitID = newids[i];
		   unsigned int idx = AnalUnitsUploaded[i];

		   NeotomaAnalUnitIDs[NeotomaAnalysisUnits[idx].AnalysisUnitID] = AnalUnitID;
		   AnalysisUnitIDs.push_back(AnalUnitID);

		   msg = L"Analysis unit ";
		   if (!NeotomaAnalysisUnits[idx].AnalysisUnitName.IsEmpty()) {
			 msg += (L"«" + NeotomaAnalysisUnits[idx].AnalysisUnitName + L"»");
			 if (!NeotomaAnalysisUnits[idx].Depth.IsEmpty()) {
			   msg += (L" (Depth = " + FloatToStr((double)NeotomaAnalysisUnits[idx].Depth));
			   if (!NeotomaAnalysisUnits[idx].Thickness.IsEmpty())
				 msg += (L", Thickness = " + FloatToStr((double)NeotomaAnalysisUnits[idx].Thickness));
			   msg += L")";
			   }
			 }
		   else {
			 msg += (L"«Depth = " + FloatToStr((double)NeotomaAnalysisUnits[idx].Depth));
			 if (!NeotomaAnalysisUnits[idx].Thickness.IsEmpty())
			   msg += (L", Thickness = " + FloatToStr((double)NeotomaAnalysisUnits[idx].Thickness));
			 msg += L"»";
			 }
		   msg += (L" uploaded to AnalysisUnits table: AnalysisUnitID = " + IntToStr(AnalUnitID) + L".");
		   OutputLine(msg);
		   }
		 }
	   else {
		 ErrorMsg = L"Error inserting into AnalysisUnits table!";
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

   // upload alternative depths
   if (AltDepthScales.size() > 0) {
	 InsertData InsertAltDepth(L"InsertAnalysisUnitAltDepth", 3, ipsHTTPS1, ipsJSONS1, TcpClient1);
	 for (unsigned int i=0; i<NeotomaAnalysisUnits.size(); i++) {
	   if (NeotomaAnalysisUnits[i].CollectionUnitID == TempCollUnitID) {
		 if (NeotomaAnalysisUnits[i].AltDepths.size() > 0) {
		   int AnalysisUnitID = NeotomaAnalUnitIDs[NeotomaAnalysisUnits[i].AnalysisUnitID];
		   map<int,double>::iterator itr;
		   map<int,double>::iterator begin = NeotomaAnalysisUnits[i].AltDepths.begin();
		   map<int,double>::iterator end = NeotomaAnalysisUnits[i].AltDepths.end();
		   for (itr = begin; itr != end; itr++) {
			 InsertAltDepth.Add(L"ANALYSISUNITID", AnalysisUnitID);
			 InsertAltDepth.Add(L"ALTDEPTHSCALEID", AltDepthScaleIDs[itr->first]);
			 InsertAltDepth.Add(L"ALTDEPTH", itr->second);
			 }
		   }
		 }
	   }
	 StatusBar1->SimpleText = L"InsertAnalysisUnitAltDepth";
	 InsertAltDepth.PostData();
	 if (InsertAltDepth.Post(ErrorMsg))
	   OutputLine("Analysis Unit alternative depths uploaded to AnalysisUnitAltDepths table.");
	 else {
	   OutputError(L"ERROR: " + ErrorMsg);
	   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return false;
	   }
	 }

   // InsertDepAgent](@ANALYSISUNITID int, @DEPAGENTID int)
   // upload depositional agents
   int n = 0;
   InsertData InsertDepAgent(L"InsertDepAgent", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
   for (unsigned int i=0; i<NeotomaAnalysisUnits.size(); i++) {
	 if (NeotomaAnalysisUnits[i].CollectionUnitID == TempCollUnitID) {
	   if (NeotomaAnalysisUnits[i].DepAgentID > -1) {
		 //int AnalysisUnitID = FindNeotomaAnalUnitID(NeotomaAnalysisUnits[i].AnalysisUnitID);
		 int AnalysisUnitID = NeotomaAnalUnitIDs[NeotomaAnalysisUnits[i].AnalysisUnitID];
		 InsertDepAgent.Add(L"ANALYSISUNITID", AnalysisUnitID);
		 InsertDepAgent.Add(L"DEPAGENTID", NeotomaAnalysisUnits[i].DepAgentID);
		 n++;
		 }
	   }
	 }
   if (n > 0) {
	 StatusBar1->SimpleText = L"InsertDepAgent";
	 InsertDepAgent.PostData();
	 if (InsertDepAgent.Post(ErrorMsg))
	   OutputLine("Analysis Unit depositional agents uploaded to DepAgents table.");
	 else {
	   OutputError(L"ERROR: " + ErrorMsg);
	   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return false;
	   }
	 }
   return true;
}
//---------------------------------------------------------------------------

bool TNeotomaUploadForm::UploadGeochronology(int CollUnitID, DATASETSUBMISSION& GeochronSubmission)
{
   vector<int> newids;
   vector<int> sample_ids;
   UnicodeString msg, ErrorMsg;
   int GeochronDatasetID;

   if (NeotomaGeochrons.size() == 0)
	 return true;

   // get vector of NeotomaGeochrons assigned to CollUnitID
   vector<unsigned int> idx;
   for (unsigned int i=0; i<NeotomaGeochrons.size(); i++) {
	 int GeochronCollUnitID = FindCollUnitID(NeotomaGeochrons[i].AnalysisUnitID);
	 int TempCollUnitID = FindTempNeotomaCollUnitID(CollUnitID);
	 if (GeochronCollUnitID == TempCollUnitID)
	   idx.push_back(i);
	 }
   if (idx.size() == 0)
	 return true;

   // upload geochronology dataset
   int DatasetTypeID = 1;
   UnicodeString DatasetName;
   UnicodeString DatasetNotes = TSSForm->GeochronDataset.Notes;

   if (TSSForm->EPD.SiteID > -1 && ReplaceEPDDataset && TSSForm->EPD.Datasets.count(1) == 1) {
	 GeochronDatasetID = TSSForm->EPD.Datasets[1];
     GeochronSubmission.DatasetID = GeochronDatasetID;
	 int TempDatasetID = NextTempDatasetID();
	 NeotomaDatasetIDs[TempDatasetID] = GeochronDatasetID;

	 // update dataset notes
	 UpdateData UpdateDatasetNotes(L"UpdateDatasetNotes", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
	 StatusBar1->SimpleText = L"UpdateDatasetNotes";
	 UpdateDatasetNotes.Add(L"DATASETID", GeochronDatasetID);
	 UpdateDatasetNotes.Add(L"DATASETNOTES", DatasetNotes);
	 if (UpdateDatasetNotes.Post(ErrorMsg)) {
	   if (!DatasetNotes.IsEmpty()) {
		 msg = L"Geochronology dataset notes updated.";
		 OutputLine(msg);
		 }
	   }
	 else {
	   OutputError(L"ERROR: " + ErrorMsg);
	   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return false;
	   }
	 msg = L"Geochronology data will be assigned to existing EPD DatasestID " + IntToStr(GeochronDatasetID);
	 OutputLine(msg);
	 }
   else {
	 InsertData InsertDataset(L"InsertDataset", 4, ipsHTTPS1, ipsJSONS1, TcpClient1);
	 InsertDataset.Add(L"COLLECTIONUNITID", CollUnitID, -1);
	 InsertDataset.Add(L"DATASETTYPEID", DatasetTypeID, -1);
	 InsertDataset.Add(L"DATASETNAME", DatasetName);
	 InsertDataset.Add(L"NOTES", DatasetNotes);
	 StatusBar1->SimpleText = L"InsertDataset";
	 InsertDataset.PostData();
	 if (InsertDataset.Post(newids, ErrorMsg)) {
	   if (newids.size() == 1) {
		 //map<int,int> NeotomaDatasetIDs;    // TempDatasetID, NeotomaDatasetID
		 GeochronDatasetID = newids[0];
		 GeochronSubmission.DatasetID = GeochronDatasetID;
		 int TempDatasetID = NextTempDatasetID();
		 NeotomaDatasetIDs[TempDatasetID] = GeochronDatasetID;
		 OutputLine(L"Geochronology dataset uploaded to Datasets table: CollectionUnitID = " +
		   IntToStr(CollUnitID) + L", DatasetTypeID = 1, DatasetID = " +
		   IntToStr(GeochronDatasetID) + L".");
		 }
	   else {
		 ErrorMsg = L"Error inserting into Datasets table!";
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

   // upload geochronology samples
   //vector<int> TempSampleIDs;
   unsigned int nrecs = 0;
   int NeotomaAnalUnitID;
   NEOTOMASAMPLE Sample;  // blank sample
   InsertData InsertSample(L"InsertSample", 9, ipsHTTPS1, ipsJSONS1, TcpClient1);
   for (unsigned int j=0; j<idx.size(); j++) {
	 int i = idx[j];
	 if (NeotomaGeochrons[i].AnalysisUnitID > 0) {
	   NeotomaAnalUnitID = NeotomaGeochrons[i].AnalysisUnitID;
	   }
	 else {
	   int TempAnalysisUnitID = NeotomaGeochrons[i].AnalysisUnitID;
	   NeotomaAnalUnitID = NeotomaAnalUnitIDs[TempAnalysisUnitID];
	   }
	 InsertSample.Add(L"ANALYSISUNITID", NeotomaAnalUnitID);
	 InsertSample.Add(L"DATASETID", GeochronDatasetID);
	 InsertSample.Add(L"SAMPLENAME", Sample.SampleName);
	 InsertSample.Add(L"SAMPLEDATE", DateStr(Sample.DateSampled));
	 InsertSample.Add(L"ANALYSISDATE", DateStr(Sample.DateAnalyzed));
	 InsertSample.Add(L"TAXONID", Sample.TaxonID, -1);
	 InsertSample.Add(L"LABNUMBER", NeotomaGeochrons[i].LabNumber);
	 InsertSample.Add(L"PREPMETHOD", Sample.PrepMethod);
	 InsertSample.Add(L"NOTES", NeotomaGeochrons[i].Notes);
	 nrecs++;
	 }
   StatusBar1->SimpleText = L"InsertSample";
   InsertSample.PostData();
   if (InsertSample.Post(sample_ids, ErrorMsg)) {
	 if (sample_ids.size() == nrecs) {
	   msg = IntToStr((int)sample_ids.size()) + L" geochronolgy sample";
	   if (sample_ids.size() != 1)
		 msg += L"s";
	   msg += L" uploaded to Samples table: SampleID";
	   if (sample_ids.size() == 1)
		 msg += (L" = " + IntToStr(sample_ids[0]) + L".");
	   else
		 msg += (L"s = " + IntToStr(sample_ids[0]) + L".." + IntToStr(sample_ids.back()) + L".");
	   OutputLine(msg);
	   }
	 else {
	   ErrorMsg = L"Error inserting into Samples table!";
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

   // upload geochronology data
   nrecs = 0;
   InsertData InsertGeochron(L"InsertGeochron", 10, ipsHTTPS1, ipsJSONS1, TcpClient1);
   for (unsigned int j=0; j<idx.size(); j++) {
	 int i = idx[j];
	 InsertGeochron.Add(L"SAMPLEID", sample_ids[j], -1);
	 InsertGeochron.Add(L"GEOCHRONTYPEID", NeotomaGeochrons[i].GeochronTypeID, -1);
	 InsertGeochron.Add(L"AGETYPEID", NeotomaGeochrons[i].AgeTypeID, -1);
	 InsertGeochron.AddDouble(L"AGE", NeotomaGeochrons[i].Age);
	 InsertGeochron.AddDouble(L"ERROROLDER", NeotomaGeochrons[i].ErrorOlder);
	 InsertGeochron.AddDouble(L"ERRORYOUNGER", NeotomaGeochrons[i].ErrorYounger);
	 InsertGeochron.Add(L"INFINITE", NeotomaGeochrons[i].GreaterThan);
	 InsertGeochron.Add(L"LABNUMBER", NeotomaGeochrons[i].LabNumber);
	 InsertGeochron.Add(L"MATERIALDATED", NeotomaGeochrons[i].MaterialDated);
	 InsertGeochron.Add(L"NOTES", NeotomaGeochrons[i].Notes);
	 nrecs++;
	 }
   newids.clear();
   StatusBar1->SimpleText = L"InsertGeochron";
   InsertGeochron.PostData();
   if (InsertGeochron.Post(newids, ErrorMsg)) {
	 if (newids.size() == nrecs) {
	   for (unsigned int i=0; i<newids.size(); i++)
		 NeotomaGeochronIDs[NeotomaGeochrons[idx[i]].GeochronID] = newids[i];

	   msg = IntToStr((int)newids.size()) + L" geochronologic measurement";
	   if (newids.size() != 1)
		 msg += L"s";
	   msg += L" uploaded to Geochronology table: GeochronID";
	   if (newids.size() == 1)
		 msg += (L" = " + IntToStr(newids[0]) + L".");
	   else
		 msg += (L"s = " + IntToStr(newids[0]) + L".." + IntToStr(newids.back()) + L".");
	   OutputLine(msg);
	   }
	 else {
	   ErrorMsg = L"Error inserting into Geochronology table!";
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

   // upload radiocarbon parameters
   vector<int> C14ParamGeochronIDs;
   InsertData InsertRadiocarbon(L"InsertRadiocarbon", 10, ipsHTTPS1, ipsJSONS1, TcpClient1);
   for (unsigned int j=0; j<idx.size(); j++) {
	 int i = idx[j];
	 if (NeotomaGeochrons[i].RadiocarbonParams.size() > 0) {
	   C14ParamGeochronIDs.push_back(newids[j]);
	   InsertRadiocarbon.Add(L"GEOCHRONID", newids[j], -1);
	   InsertRadiocarbon.AddInt(L"RADIOCARBONMETHODID", GeochronParam(NeotomaGeochrons[i].RadiocarbonParams, L"Method"));
	   InsertRadiocarbon.AddDouble(L"MASSCMG", GeochronParam(NeotomaGeochrons[i].RadiocarbonParams, L"Mass C (mg)"));
	   InsertRadiocarbon.AddDouble(L"PERCENTC", GeochronParam(NeotomaGeochrons[i].RadiocarbonParams, L"%C"));
	   InsertRadiocarbon.AddDouble(L"PERCENTN", GeochronParam(NeotomaGeochrons[i].RadiocarbonParams, L"%N"));
	   InsertRadiocarbon.AddDouble(L"CNRATIO", GeochronParam(NeotomaGeochrons[i].RadiocarbonParams, L"C:N"));
	   InsertRadiocarbon.AddDouble(L"DELTA13C", GeochronParam(NeotomaGeochrons[i].RadiocarbonParams, L"δ13C"));
	   InsertRadiocarbon.AddDouble(L"DELTA15N", GeochronParam(NeotomaGeochrons[i].RadiocarbonParams, L"δ15N"));
	   InsertRadiocarbon.AddDouble(L"PERCENTCOLLAGEN", GeochronParam(NeotomaGeochrons[i].RadiocarbonParams, L"%collagen"));
	   InsertRadiocarbon.AddDouble(L"RESERVOIR", GeochronParam(NeotomaGeochrons[i].RadiocarbonParams, L"Reservoir (yrs)"));
	   }
	 }
   if (C14ParamGeochronIDs.size() > 0) {
	 StatusBar1->SimpleText = L"InsertRadiocarbon";
	 InsertRadiocarbon.PostData();
	 if (InsertRadiocarbon.Post(ErrorMsg)) {
	   if (C14ParamGeochronIDs.size() == 1) {
		 msg = L"Geochron parameters for radiocarbon date uploaded to the Radiocarbon table. GeochronID = " +
			   IntToStr(C14ParamGeochronIDs[0]) + L".";
		 }
	   else {
		 msg = L"Geochron parameters for " + IntToStr((int)C14ParamGeochronIDs.size()) +
			   L" radiocarbon dates uploaded to Radiocarbon table.";
		 }
	   OutputLine(msg);
	   }
	 else {
	   OutputError(L"ERROR: " + ErrorMsg);
	   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return false;
	   }
	 }

   // upload geochron publications
   // InsertGeochronPublication @GEOCHRONID int, @PUBLICATIONID int
   vector<pair<int,int> > GeochronPubs;    // GeochronID, PublicationID
   set<int> GeochronDatasetPubIDs;
   for (unsigned int k=0; k<idx.size(); k++) {
	 int i = idx[k];
	 if (NeotomaGeochrons[i].PublicationIDs.size() > 0) {
	   int GeochronID = NeotomaGeochronIDs[NeotomaGeochrons[i].GeochronID];
	   for (unsigned int j=0; j<NeotomaGeochrons[i].PublicationIDs.size(); j++) {
		 int PubID = NeotomaGeochrons[i].PublicationIDs[j];
		 GeochronPubs.push_back(pair<int,int>(GeochronID,PubID));
         GeochronDatasetPubIDs.insert(PubID);
		 }
	   }
	 }
   if (GeochronPubs.size() > 0) {
	 InsertData InsertGeochronPubs(L"InsertGeochronPublication", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
	 for (unsigned int i=0; i<GeochronPubs.size(); i++) {
	   InsertGeochronPubs.Add(L"GEOCHRONID", GeochronPubs[i].first, -1);
	   InsertGeochronPubs.Add(L"PUBLICATIONID", GeochronPubs[i].second, -1);
	   }
	 StatusBar1->SimpleText = L"InsertGeochronPublication";
	 InsertGeochronPubs.PostData();
	 if (InsertGeochronPubs.Post(ErrorMsg)) {
	   msg = IntToStr((int)GeochronPubs.size()) + L" record";
	   if (GeochronPubs.size() > 1)
		 msg += L"s";
	   msg += L" uploaded to the GeochronPublications table.";
	   OutputLine(msg);
	   }
	 else {
	   OutputError(L"ERROR: " + ErrorMsg);
	   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return false;
	   }
	 }

   // upload geochron dataset publications
   if (GeochronDatasetPubIDs.size() > 0) {
	 InsertData InsertDatasetPub(L"InsertDatasetPublication", 3, ipsHTTPS1, ipsJSONS1, TcpClient1);
	 bool primary = false;
	 for (set<int>::iterator itr = GeochronDatasetPubIDs.begin(); itr != GeochronDatasetPubIDs.end(); itr++) {
	   InsertDatasetPub.Add(L"DATASETID", GeochronDatasetID, -1);
	   InsertDatasetPub.Add(L"PUBLICATIONID", *itr, -1);
	   InsertDatasetPub.Add(L"PRIMARYPUB", primary);
	   }

	 StatusBar1->SimpleText = L"InsertDatasetPublication";
	 InsertDatasetPub.PostData();
	 if (InsertDatasetPub.Post(ErrorMsg)) {
	   for (set<int>::iterator itr = GeochronDatasetPubIDs.begin(); itr != GeochronDatasetPubIDs.end(); itr++) {
		 OutputLine(L"Geochron publication uploaded to DatasetPublications table: PublicationID = " +
		   IntToStr(*itr) + L".");
		 }
	   }
	 else {
	   OutputError(L"ERROR: " + ErrorMsg);
	   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return false;
	   }
	 }

   // upload investigators
   if (TSSForm->GeochronDataset.Investigators.size() > 0) {
	 InsertData InsertDatasetPI(L"InsertDatasetPI", 3, ipsHTTPS1, ipsJSONS1, TcpClient1);
	 int order = 1;
	 for (unsigned int j=0; j<TSSForm->GeochronDataset.Investigators.size(); j++) {
	   InsertDatasetPI.Add(L"DATASETID", GeochronDatasetID, -1);
	   InsertDatasetPI.Add(L"CONTACTID", TSSForm->GeochronDataset.Investigators[j]->NeotomaContactID, -1);
	   InsertDatasetPI.Add(L"PIORDER", order++, -1);
	   }
	 StatusBar1->SimpleText = L"InsertDatasetPI";
	 InsertDatasetPI.PostData();
	 if (InsertDatasetPI.Post(ErrorMsg)) {
	   for (unsigned int j=0; j<TSSForm->GeochronDataset.Investigators.size(); j++) {
		 OutputLine(L"Geochronology investigator uploaded to DatasetPIs table: DatasetID = " +
		   IntToStr(GeochronDatasetID) + L", ContactID = " +
		   IntToStr(TSSForm->GeochronDataset.Investigators[j]->NeotomaContactID) + L".");
		 }
	   }
	 else {
	   OutputError(L"ERROR: " + ErrorMsg);
	   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return false;
	   }
	 }

   // upload dataset database
   InsertData InsertDatasetDatabase(L"InsertDatasetDatabase", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
   InsertDatasetDatabase.Add(L"DATASETID", GeochronDatasetID, -1);
   InsertDatasetDatabase.Add(L"DATABASEID", GeochronSubmission.DatabaseID, -1);
   StatusBar1->SimpleText = L"InsertDatasetDatabase";
   InsertDatasetDatabase.PostData();
   if (InsertDatasetDatabase.Post(ErrorMsg)) {
	 OutputLine(L"Geochronology DatasetID " + IntToStr(GeochronDatasetID) +
	   L" assigned to Neotoma constituent DatabaseID " + IntToStr(GeochronSubmission.DatabaseID) +
	   L" in the DatasetDatabases table.");
	   }
   else {
	 OutputError(L"ERROR: " + ErrorMsg);
	 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 return false;
	 }

   return true;
}
//---------------------------------------------------------------------------

bool TNeotomaUploadForm::UploadChronologies(int CollUnitID)
{
   vector<int> newids;
   UnicodeString msg, ErrorMsg;
   int NeotomaChronID;

   // map<int,NEOTOMASAMPLEAGE> NeotomaSampleAges;  // map<ChronNo, map<SampleID,NEOTOMAAGE> >
   // map<int,int> NeotomaCollUnitIDs;   // TempCollUnitID, NeotomaCollUnitID
   // map<int,int> NeotomaChronIDs;      // TempChronID, NeotomaChronID


   // delete any existing legacy EPD chronologies
   if (TSSForm->EPD.SiteID > -1 && TSSForm->EPD.CollectionUnitID > -1) {

	 }

   bool multi_coll_units = false;
   SITE* site_ptr = (SITE*)TSSForm->Sites->Items[0];
   if (TSSForm->Sites->Count > 1 || site_ptr->CollUnits.size() > 1)
	 multi_coll_units = true;

   // upload chronologies one at a time
   // map<int,int> TiliaChronIDs;        // TempChronID, ChronNo
   for (unsigned int i=0; i<NeotomaChrons.size(); i++) {
	 if (NeotomaCollUnitIDs[NeotomaChrons[i].CollectionUnitID] == CollUnitID) {
	   double AgeBoundOlder = NeotomaChrons[i].AgeBoundOlder;
	   double AgeBoundYounger = NeotomaChrons[i].AgeBoundYounger;
	   if (multi_coll_units) {
		 AgeBoundOlder = NeotomaChrons[i].AgeBoundYounger;
		 AgeBoundYounger = NeotomaChrons[i].AgeBoundOlder;
		 for (unsigned int j=0; j<NeotomaChrons[i].ChronControls.size(); j++) {
		   if (NeotomaChrons[i].ChronControls[j].AgeLimitOlder > AgeBoundOlder)
			 AgeBoundOlder = NeotomaChrons[i].ChronControls[j].AgeLimitOlder;
		   if (NeotomaChrons[i].ChronControls[j].AgeLimitYounger < AgeBoundYounger)
			 AgeBoundYounger = NeotomaChrons[i].ChronControls[j].AgeLimitYounger;
		   }
		 AgeBoundOlder = SimpleRoundTo(AgeBoundOlder,1);
		 AgeBoundYounger = SimpleRoundTo(AgeBoundYounger,1) - 10;
		 }

	   InsertData InsertChron(L"InsertChronology", 10, ipsHTTPS1, ipsJSONS1, TcpClient1);
	   int TempChronID = NeotomaChrons[i].ChronologyID;
	   int ChronNo = TiliaChronIDs[TempChronID];
	   InsertChron.Add(L"COLLECTIONUNITID", CollUnitID, -1);
	   InsertChron.Add(L"AGETYPEID", NeotomaChrons[i].AgeTypeID, -1);
	   InsertChron.Add(L"CONTACTID", NeotomaChrons[i].ContactID, -1);
	   InsertChron.Add(L"ISDEFAULT", NeotomaChrons[i].IsDefault);
	   InsertChron.Add(L"CHRONOLOGYNAME", NeotomaChrons[i].ChronologyName);
	   InsertChron.Add(L"DATEPREPARED", DateStr(NeotomaChrons[i].DatePrepared));
	   InsertChron.Add(L"AGEMODEL", NeotomaChrons[i].AgeModel);
	   InsertChron.AddInt(L"AGEBOUNDYOUNGER", AgeBoundYounger);
	   InsertChron.AddInt(L"AGEBOUNDOLDER", AgeBoundOlder);
	   InsertChron.Add(L"NOTES", NeotomaChrons[i].Notes);

	   StatusBar1->SimpleText = L"InsertChronology";
	   InsertChron.PostData();
	   newids.clear();
	   if (InsertChron.Post(newids, ErrorMsg)) {
		 if (newids.size() == 1) {
		   NeotomaChronID = newids[0];
		   NeotomaChronIDs[TempChronID] = NeotomaChronID;
		   OutputLine(L"Chron" + IntToStr(ChronNo) + L" uploaded to Chronologies table: CollectionUnitID = " +
			 IntToStr(CollUnitID) + L", ChronologyID = " + IntToStr(NeotomaChronID) + L".");
		   }
		 else {
		   ErrorMsg = L"Error inserting into Chronologies table!";
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

	   // upload chron controls

	   if (NeotomaChrons[i].ChronControls.size() > 0) {
		 UnicodeString Str;
		 vector<NEOTOMACALIB> CalibDates;
		 InsertData InsertControl(L"InsertChronControl", 10, ipsHTTPS1, ipsJSONS1, TcpClient1);
		 for (unsigned int j=0; j<NeotomaChrons[i].ChronControls.size(); j++) {
		   NEOTOMACHRONCONTROL& ChronControl = NeotomaChrons[i].ChronControls[j];
		   InsertControl.Add(L"CHRONOLOGYID", NeotomaChronID, -1);
		   InsertControl.Add(L"CHRONCONTROLTYPEID", ChronControl.ChronControlTypeID, -1);
		   int AnalysisUnitID = -1;
		   if (NeotomaAnalUnitIDs.count(ChronControl.AnalysisUnitID) == 1)
			 AnalysisUnitID = NeotomaAnalUnitIDs[ChronControl.AnalysisUnitID];
		   InsertControl.Add(L"ANALYSISUNITID", AnalysisUnitID, -1);
		   InsertControl.AddDouble(L"DEPTH", ChronControl.Depth);
		   InsertControl.AddDouble(L"THICKNESS", ChronControl.Thickness);
		   InsertControl.AddInt(L"AGETYPEID", ChronControl.AgeTypeID);
		   InsertControl.AddDouble(L"AGE", ChronControl.Age);
		   InsertControl.AddDouble(L"AGELIMITYOUNGER", ChronControl.AgeLimitYounger);
		   InsertControl.AddDouble(L"AGELIMITOLDER", ChronControl.AgeLimitOlder);
		   InsertControl.Add(L"NOTES", ChronControl.Notes);
		   if (ChronControl.CalibrationCurveID > -1 && ChronControl.CalibrationProgramID > -1) {
			 NEOTOMACALIB CalibDate(ChronControl.ChronControlID,
			   ChronControl.CalibrationCurveID,
			   ChronControl.CalibrationProgramID);
			   CalibDates.push_back(CalibDate);
			 }

		   if (ChronControl.GeoChronIDs.size() > 0) {
			 for (unsigned int k=0; k<ChronControl.GeoChronIDs.size(); k++) {
			   int ChronControlID = ChronControl.ChronControlID;
			   int GeochronID = ChronControl.GeoChronIDs[k];          // TempGeochronID, NeotomaGeochronID
			   GeochronControls.push_back(pair<int,int>(ChronControlID,GeochronID));
			   }
			 }
		   }

		 StatusBar1->SimpleText = L"InsertChronControl";
		 InsertControl.PostData();

		 newids.clear();
		 if (InsertControl.Post(newids, ErrorMsg)) {
		   if (newids.size() == NeotomaChrons[i].ChronControls.size()) {
			 for (unsigned int j=0; j<newids.size(); j++)
			   NeotomaChronControlIDs[NeotomaChrons[i].ChronControls[j].ChronControlID] = newids[j];

			 msg = L"ChronologyID " + IntToStr(NeotomaChronID) + L": " +
			   IntToStr((int)newids.size()) + L" ChronControl";
			 if (newids.size() > 1)
			   msg += L"s";
			 msg += L" uploaded to ChronControls table: ChronControlID";
			 if (newids.size() == 1)
			   msg += (L" = " + IntToStr(newids[0]) + L".");
			 else
			   msg += (L"s = " + IntToStr(newids[0]) + L".." + IntToStr(newids.back()) + L".");
			 OutputLine(msg);
			 }
		   else {
			 ErrorMsg = L"Error inserting into ChronControls table!";
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

		 // upload calibration data
		 if (CalibDates.size() > 0) {
		   InsertData InsertCalib(L"InsertChronControlCal14C", 3, ipsHTTPS1, ipsJSONS1, TcpClient1);
		   for (unsigned int j=0; j<CalibDates.size(); j++) {
			 int ChronControlID = NeotomaChronControlIDs[CalibDates[j].ChronControlID];
			 InsertCalib.Add(L"CHRONCONTROLID", ChronControlID, -1);
			 InsertCalib.Add(L"CALIBRATIONCURVEID", CalibDates[j].CalibrationCurveID, -1);
			 InsertCalib.Add(L"CALIBRATIONPROGRAMID", CalibDates[j].CalibrationProgramID, -1);
			 }
		   StatusBar1->SimpleText = L"InsertChronControlCal14C";
		   InsertCalib.PostData();
		   if (InsertCalib.Post(ErrorMsg)) {
			 msg = L"ChronologyID " + IntToStr(NeotomaChronID) + L": data for " +
			   IntToStr((int)CalibDates.size()) + L" calibrated radiocarbon date";
			 if (CalibDates.size() > 1)
			   msg += L"s";
			 msg += L" uploaded to ChronControlCal14C table.";
			 OutputLine(msg);
			 }
		   else {
			 OutputError(L"ERROR: " + ErrorMsg);
			 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			 return false;
			 }
		   }
		 }
	   }
	 }

   // InsertEventChronology](@ANALYSISUNITID int, @EVENTID int, @CHRONCONTROLID int, @NOTES nvarchar(MAX) = null
   // insert events used in chronologies
   if (NetomaEventChronology.size() > 0) {
	 newids.clear();
	 InsertData InsertEventChron(L"InsertEventChronology", 4, ipsHTTPS1, ipsJSONS1, TcpClient1);
	 for (unsigned int i=0; i<NetomaEventChronology.size(); i++) {
	   int AnalysisUnitID = NeotomaAnalUnitIDs[NetomaEventChronology[i].AnalysisUnitID];
	   InsertEventChron.Add(L"ANALYSISUNITID", AnalysisUnitID, -1);
	   InsertEventChron.Add(L"EVENTID", NetomaEventChronology[i].EventID, -1);
	   int ChronControlID = NeotomaChronControlIDs[NetomaEventChronology[i].ChronControlID];
	   InsertEventChron.Add(L"CHRONCONTROLID", ChronControlID, -1);
	   InsertEventChron.Add(L"NOTES", NetomaEventChronology[i].Notes);
	   }
	 StatusBar1->SimpleText = L"InsertEventChronology";
	 InsertEventChron.PostData();
	 if (InsertEventChron.Post(newids, ErrorMsg)) {
	   if (newids.size() == NetomaEventChronology.size()) {
		 msg = IntToStr((int)newids.size()) + L" chronology event";
		 if (newids.size() > 1) msg += L"s";
		 msg += " uploaded to EventChronology table: EventChronologyID";
		 if (newids.size() == 1)
		   msg += (L" = " + IntToStr(newids[0]) + L".");
		 else
		   msg += (L"s = " + IntToStr(newids[0]) + L".." + IntToStr(newids.back()) + L".");
		 OutputLine(msg);
		 }
	   else {
		 ErrorMsg = L"Error inserting into EventChronology table!";
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
	 NetomaEventChronology.clear();
	 }

   // insert relative ages
   // Insert NeotomaChronControl.AnalysisUnitID, RelativeAgeID, ChronControlID,
   // and NeotomaChronControl.Notes into RelativeChronology table
   // NeotomaRelAges
   if (NeotomaRelAges.size() > 0) {   // relative ages exist
	 newids.clear();
	 InsertData InsertRelativeAge(L"InsertRelativeChronology", 4, ipsHTTPS1, ipsJSONS1, TcpClient1);
	 for (unsigned int i=0; i<NeotomaRelAges.size(); i++) {
	   int AnalysisUnitID = NeotomaAnalUnitIDs[NeotomaRelAges[i].AnalysisUnitID];
	   InsertRelativeAge.Add(L"ANALYSISUNITID", AnalysisUnitID, -1);
	   InsertRelativeAge.Add(L"RELATIVEAGEID", NeotomaRelAges[i].RelativeAgeID, -1);
	   int ChronControlID = NeotomaChronControlIDs[NeotomaRelAges[i].ChronControlID];
	   InsertRelativeAge.Add(L"CHRONCONTROLID", ChronControlID, -1);
	   InsertRelativeAge.Add(L"NOTES", NeotomaRelAges[i].Notes);
	   }
	 StatusBar1->SimpleText = L"InsertRelativeChronology";
	 InsertRelativeAge.PostData();
	 if (InsertRelativeAge.Post(newids, ErrorMsg)) {
	   if (newids.size() == NeotomaRelAges.size()) {
		 msg = IntToStr((int)newids.size()) + L" relative age";
		 if (newids.size() > 1) msg += L"s";
		 msg += " uploaded to RelativeChronology table: RelativeChronID";
		 if (newids.size() == 1)
		   msg += (L" = " + IntToStr(newids[0]) + L".");
		 else
		   msg += (L"s = " + IntToStr(newids[0]) + L".." + IntToStr(newids.back()) + L".");
		 OutputLine(msg);
		 }
	   else {
		 ErrorMsg = L"Error inserting into RelativeChronology table!";
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
	 NeotomaRelAges.clear();
	 }
   return true;
}
//---------------------------------------------------------------------------

bool TNeotomaUploadForm::UploadGeochronControls(void)
{
   UnicodeString msg, ErrorMsg;

   if (GeochronControls.size() > 0) {
	 InsertData InsertGeoChronControl(L"InsertGeoChronControl", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
	 for (unsigned int j=0; j<GeochronControls.size(); j++) {
	   int ChronControlID = NeotomaChronControlIDs[GeochronControls[j].first];
	   int NeotomaGeochronID = NeotomaGeochronIDs[GeochronControls[j].second];
	   InsertGeoChronControl.Add(L"CHRONCONTROLID", ChronControlID, -1);
	   InsertGeoChronControl.Add(L"GEOCHRONID", NeotomaGeochronID, -1);
	   }
	 StatusBar1->SimpleText = L"InsertGeoChronControl";
	 InsertGeoChronControl.PostData();
	 if (InsertGeoChronControl.Post(ErrorMsg)) {
	   msg = IntToStr((int)GeochronControls.size()) + L" Geochronology link";
	   if (GeochronControls.size() > 1)
		 msg += L"s";
	   msg += L" uploaded to GeoChronControls table.";
	   OutputLine(msg);
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

bool TNeotomaUploadForm::UploadTephras(int CollUnitID)
{
   vector<int> newids;
   UnicodeString msg, ErrorMsg;

   // get vector of NeotomaTephras assigned to CollUnitID
   vector<unsigned int> idx;
   for (unsigned int i=0; i<NeotomaTephras.size(); i++) {
	 if (FindCollUnitID(NeotomaTephras[i].AnalysisUnitID) == FindTempNeotomaCollUnitID(CollUnitID))
	   idx.push_back(i);
	 }
   if (idx.size() == 0)
	 return true;

	 // [InsertTephra](@EVENTID int, @ANALYSISUNITID int, @NOTES nvarchar(MAX) = null)
	 newids.clear();
	 InsertData InsertTephra(L"InsertTephra", 3, ipsHTTPS1, ipsJSONS1, TcpClient1);
	 for (unsigned int j=0; j<idx.size(); j++) {
	   int i = idx[j];
	   InsertTephra.Add(L"EVENTID", NeotomaTephras[i].EventID, -1);
	   int AnalysisUnitID = NeotomaAnalUnitIDs[NeotomaTephras[i].AnalysisUnitID];
	   InsertTephra.Add(L"ANALYSISUNITID", AnalysisUnitID, -1);
	   InsertTephra.Add(L"NOTES", NeotomaTephras[i].Notes);
	   }
	 StatusBar1->SimpleText = L"InsertTephra";
	 InsertTephra.PostData();
	 if (InsertTephra.Post(newids, ErrorMsg)) {
	   if (newids.size() == NeotomaTephras.size()) {
		 msg = IntToStr((int)newids.size()) + L" tephra";
		 if (newids.size() > 1)
		   msg += L"s";
		 msg += (" for CollectionUnitID " + IntToStr(CollUnitID) + " uploaded to Tephras table: TephraID");
		 if (newids.size() == 1)
		   msg += (L" = " + IntToStr(newids[0]) + L".");
		 else
		   msg += (L"s = " + IntToStr(newids[0]) + L".." + IntToStr(newids.back()) + L".");
		 OutputLine(msg);
		 }
	   else {
		 ErrorMsg = L"Error inserting into Tephras table!";
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
	 NeotomaTephras.clear();
   return true;
}
//---------------------------------------------------------------------------

bool TNeotomaUploadForm::UploadDatasets(int CollUnitID, COLLECTION& CollUnit, vector<NEOTOMADATASET>& NeotomaDatasets)
{
   vector<int> newids;
   UnicodeString msg, ErrorMsg;

   // NeotomaCollUnitIDs[-1001] = 7735;
   // get set of all sample TempDatasetIDs in CollectionUnit CollUnitID
   set<int> TempDatasetIDs;

   int TempCollUnitID = FindTempNeotomaCollUnitID(CollUnitID);
   for (unsigned int i=0; i<NeotomaSamples.size(); i++) {
	 if (NeotomaSamples[i].CollUnitID == TempCollUnitID) {
	   int TempDatasetID = NeotomaSamples[i].DatasetID;
	   if (TempDatasetIDs.count(TempDatasetID) == 0)
		 TempDatasetIDs.insert(TempDatasetID);
	   }
	 }
   // stable isotope dataset, which doesn't have samples in the spreadsheet
   for (unsigned int i=0; i<CollUnit.NeotomaDatasets.size(); i++) {
	 if (CollUnit.NeotomaDatasets[i].NeotomaDatasetTypeID == 24) {
	   int TempDatasetID = CollUnit.NeotomaDatasets[i].NeotomaDatasetID;
	   if (TempDatasetIDs.count(TempDatasetID) == 0)
		 TempDatasetIDs.insert(TempDatasetID);
	   }
	 }

   if (GeochronOnly && NeotomaDatasets.size() == 1) {
	 int TempDatasetID = CollUnit.NeotomaDatasets[0].NeotomaDatasetID;
	 if (TempDatasetIDs.count(TempDatasetID) == 0)
	   TempDatasetIDs.insert(TempDatasetID);
	 }

   // asssemble all metadata for datasets to be uploaded for CollectionUnit CollUnitID
   set<int>::iterator itr;
   for (itr = TempDatasetIDs.begin(); itr != TempDatasetIDs.end(); itr++) {
	 for (unsigned int i=0; i<CollUnit.NeotomaDatasets.size(); i++) {
	   if (CollUnit.NeotomaDatasets[i].NeotomaDatasetID == *itr) {
		 NEOTOMADATASET nd;
		 nd.DatasetID = *itr;
		 nd.NeotomaCollUnitID = CollUnitID;
		 nd.NeotomaDatasetTypeID = CollUnit.NeotomaDatasets[i].NeotomaDatasetTypeID;
		 nd.NeotomaDatabaseID = CollUnit.NeotomaDatasets[i].NeotomaDatabaseID;
		 nd.NeotomaSubmissionTypeID = CollUnit.NeotomaDatasets[i].NeotomaSubmissionTypeID;
		 nd.NeotomaSubmissionNotes = CollUnit.NeotomaDatasets[i].NeotomaSubmissionNotes;
		 if (!CollUnit.NeotomaDatasets[i].IsAggregate)
		   nd.DatasetName = CollUnit.NeotomaDatasets[i].Name;
		 nd.Notes = CollUnit.NeotomaDatasets[i].Notes;
		 nd.Investigators = CollUnit.NeotomaDatasets[i].Investigators;
		 nd.Processors = CollUnit.NeotomaDatasets[i].Processors;
		 nd.Publications = CollUnit.NeotomaDatasets[i].Publications;
		 nd.Repositories = CollUnit.NeotomaDatasets[i].Repositories;
#ifdef WHITMORE
		 nd.WhitmoreID1 = WhitmoreIDs[CollUnit.Handle];
#endif
		 NeotomaDatasets.push_back(nd);
		 break;
		 }
	   }
	 }

   // DatasetID = -1001, CollUnitID = 7735, DatasetTypeID = 3
   // upload datasets
   // int first_dataset = (GeochronOnly) ? 1 : 0;
   for (unsigned int i=0; i<NeotomaDatasets.size(); i++) {
	 int NeotomaDatasetID;

	 if (TSSForm->EPD.SiteID > -1 && ReplaceEPDDataset &&
		 TSSForm->EPD.Datasets.count(NeotomaDatasets[i].NeotomaDatasetTypeID) == 1) {

	   NeotomaDatasetID = TSSForm->EPD.Datasets[NeotomaDatasets[i].NeotomaDatasetTypeID];
	   TempDatasetID = NeotomaDatasets[i].DatasetID;
	   NeotomaDatasetIDs[TempDatasetID] = NeotomaDatasetID;

	   // update dataset name
	   UpdateData UpdateDatasetName(L"UpdateDatasetName", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
	   StatusBar1->SimpleText = L"UpdateDatasetName";
	   UpdateDatasetName.Add(L"DATASETID", NeotomaDatasetID);
	   UpdateDatasetName.Add(L"DATASETNAME", NeotomaDatasets[i].DatasetName);
	   if (UpdateDatasetName.Post(ErrorMsg)) {
		 if (!NeotomaDatasets[i].DatasetName.IsEmpty()) {
		   msg = L"Dataset name updated to «" + NeotomaDatasets[i].DatasetName + L"».";
		   OutputLine(msg);
		   }
		 }
	   else {
		 OutputError(L"ERROR: " + ErrorMsg);
		 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 return false;
		 }
	   // update dataset notes
	   UpdateData UpdateDatasetNotes(L"UpdateDatasetNotes", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
	   StatusBar1->SimpleText = L"UpdateDatasetNotes";
	   UpdateDatasetNotes.Add(L"DATASETID", NeotomaDatasetID);
	   UpdateDatasetNotes.Add(L"DATASETNOTES", NeotomaDatasets[i].Notes);
	   if (UpdateDatasetNotes.Post(ErrorMsg)) {
		 if (!NeotomaDatasets[i].Notes.IsEmpty()) {
		   msg = L"Dataset notes updated.";
		   OutputLine(msg);
		   }
		 }
	   else {
		 OutputError(L"ERROR: " + ErrorMsg);
		 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 return false;
		 }
	   msg = L"Data will be assigned to existing EPD DatasestID " + IntToStr(NeotomaDatasetID);
	   OutputLine(msg);
	   }
	 else {
	   InsertData InsertDataset(L"InsertDataset", 4, ipsHTTPS1, ipsJSONS1, TcpClient1);
	   InsertDataset.Add(L"COLLECTIONUNITID", NeotomaDatasets[i].NeotomaCollUnitID, -1);
	   InsertDataset.Add(L"DATASETTYPEID", NeotomaDatasets[i].NeotomaDatasetTypeID, -1);
	   InsertDataset.Add(L"DATASETNAME", NeotomaDatasets[i].DatasetName);
	   InsertDataset.Add(L"NOTES", NeotomaDatasets[i].Notes);
	   newids.clear();
	   StatusBar1->SimpleText = L"InsertDataset";
	   InsertDataset.PostData();
	   if (InsertDataset.Post(newids, ErrorMsg)) {
		 if (newids.size() == 1) {
		   NeotomaDatasetID = newids[0];
		   TempDatasetID = NeotomaDatasets[i].DatasetID;
		   NeotomaDatasetIDs[TempDatasetID] = NeotomaDatasetID;
		   UnicodeString DatasetType = NeotomaDatasetTypes[NeotomaDatasets[i].NeotomaDatasetTypeID];
		   UnicodeString FirstLetter = DatasetType.SubString(1,1).UpperCase();
		   DatasetType.Delete(1,1);
		   DatasetType.Insert(FirstLetter,1);
		   OutputLine(DatasetType + L" dataset uploaded to Datasets table: CollectionUnitID = " +
			 IntToStr(NeotomaDatasets[i].NeotomaCollUnitID) +
			 L", DatasetTypeID = " + IntToStr(NeotomaDatasets[i].NeotomaDatasetTypeID) +
			 L", DatasetID = " + IntToStr(NeotomaDatasetID) + L".");
		   }
		 else {
		   ErrorMsg = L"Error inserting into Datasets table!";
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

	 // upload investigators
	 //InsertDatasetPI @DATASETID int, @CONTACTID int, @PIORDER int
	 if (NeotomaDatasets[i].Investigators.size() > 0) {
	   InsertData InsertDatasetPI(L"InsertDatasetPI", 3, ipsHTTPS1, ipsJSONS1, TcpClient1);
	   int order = 1;
	   for (unsigned int j=0; j<NeotomaDatasets[i].Investigators.size(); j++) {
		 InsertDatasetPI.Add(L"DATASETID", NeotomaDatasetID, -1);
		 InsertDatasetPI.Add(L"CONTACTID", NeotomaDatasets[i].Investigators[j]->NeotomaContactID, -1);
		 InsertDatasetPI.Add(L"PIORDER", order++, -1);
		 }
	   StatusBar1->SimpleText = L"InsertDatasetPI";
	   InsertDatasetPI.PostData();
	   if (InsertDatasetPI.Post(ErrorMsg)) {
		 for (unsigned int j=0; j<NeotomaDatasets[i].Investigators.size(); j++) {
		   OutputLine(L"Dataset investigator uploaded to DatasetPIs table: DatasetID = " +
			 IntToStr(NeotomaDatasetID) + L", ContactID = " +
			 IntToStr(NeotomaDatasets[i].Investigators[j]->NeotomaContactID) + L".");
		   }
		 }
	   else {
		 OutputError(L"ERROR: " + ErrorMsg);
		 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 return false;
		 }
	   }

	 // upload data processors
	 // InsertDataProcessor @DATASETID int, @CONTACTID int
	 if (NeotomaDatasets[i].Processors.size() > 0) {
	   InsertData InsertDataProcessor(L"InsertDataProcessor", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
	   for (unsigned int j=0; j<NeotomaDatasets[i].Processors.size(); j++) {
		 InsertDataProcessor.Add(L"DATASETID", NeotomaDatasetID, -1);
		 InsertDataProcessor.Add(L"CONTACTID", NeotomaDatasets[i].Processors[j]->NeotomaContactID, -1);
		 }
	   StatusBar1->SimpleText = L"InsertDataProcessor";
	   InsertDataProcessor.PostData();
	   if (InsertDataProcessor.Post(ErrorMsg)) {
		 for (unsigned int j=0; j<NeotomaDatasets[i].Processors.size(); j++) {
		   OutputLine(L"Data processor uploaded to DataProcessors table: DatasetID = " +
			 IntToStr(NeotomaDatasetID) + L", ContactID = " +
			 IntToStr(NeotomaDatasets[i].Processors[j]->NeotomaContactID) + L".");
		   }
		 }
	   else {
		 OutputError(L"ERROR: " + ErrorMsg);
		 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 return false;
		 }
	   }


	 // upload publications
	 // InsertDatasetPublication @DATASETID int, @PUBLICATIONID int, @PRIMARYPUB bit
	 if (NeotomaDatasets[i].Publications.size() > 0) {
	   // bool primary_pub = (NeotomaDatasets[i].Publications.size() == 1);  // TODO: this is temporary
	   InsertData InsertDatasetPub(L"InsertDatasetPublication", 3, ipsHTTPS1, ipsJSONS1, TcpClient1);
	   for (unsigned int j=0; j<NeotomaDatasets[i].Publications.size(); j++) {
		 InsertDatasetPub.Add(L"DATASETID", NeotomaDatasetID, -1);
		 InsertDatasetPub.Add(L"PUBLICATIONID", NeotomaDatasets[i].Publications[j]->NeotomaID, -1);
		 InsertDatasetPub.Add(L"PRIMARYPUB", NeotomaDatasets[i].Publications[j]->Primary);
		 }
	   StatusBar1->SimpleText = L"InsertDatasetPublication";
	   InsertDatasetPub.PostData();
	   if (InsertDatasetPub.Post(ErrorMsg)) {
		 for (unsigned int j=0; j<NeotomaDatasets[i].Publications.size(); j++) {
		   OutputLine(L"Dataset publication uploaded to DatasetPublications table: DatasetID = " +
			 IntToStr(NeotomaDatasetID) + L", PublicationID = " +
			 IntToStr(NeotomaDatasets[i].Publications[j]->NeotomaID) + L".");
		   }
		 }
	   else {
		 OutputError(L"ERROR: " + ErrorMsg);
		 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 return false;
		 }
	   }

	 // upload repositories
	 // InsertDatasetRepository @DATASETID int, @REPOSITORYID int, @NOTES nvarchar(MAX)
	 if (NeotomaDatasets[i].Repositories.size() > 0) {
	   InsertData InsertDatasetRepository(L"InsertDatasetRepository", 3, ipsHTTPS1, ipsJSONS1, TcpClient1);
	   for (unsigned int j=0; j<NeotomaDatasets[i].Repositories.size(); j++) {
		 InsertDatasetRepository.Add(L"DATASETID", NeotomaDatasetID, -1);
		 InsertDatasetRepository.Add(L"REPOSITORYID", NeotomaDatasets[i].Repositories[j].RepositoryID, -1);
		 InsertDatasetRepository.Add(L"NOTES", NeotomaDatasets[i].Repositories[j].SpecimenNotes);
		 }
	   StatusBar1->SimpleText = L"InsertDatasetRepository";
	   InsertDatasetRepository.PostData();
	   if (InsertDatasetRepository.Post(ErrorMsg)) {
		 for (unsigned int j=0; j<NeotomaDatasets[i].Repositories.size(); j++) {
		   OutputLine(L"Dataset repository uploaded to RepositorySpecimens table: DatasetID = " +
			 IntToStr(NeotomaDatasetID) + L", RepositoryID = " +
			 IntToStr(NeotomaDatasets[i].Repositories[j].RepositoryID) + L".");
		   }
		 }
	   else {
		 OutputError(L"ERROR: " + ErrorMsg);
		 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 return false;
		 }
	   }

	   set<int> SynonymTaxonIDs;
	   set<int> NotesTaxonIDs;
	   set<int> VariableIDs;

	   // get set of all unique VariableIDs for current DatasetID
	   for (unsigned int j=0; j<NeotomaSamples.size(); j++) {
		 if (NeotomaDatasetID == NeotomaDatasetIDs[NeotomaSamples[j].DatasetID]) {
		   for (unsigned int k=0; k<NeotomaSamples[j].data.size(); k++)
			 VariableIDs.insert(NeotomaSamples[j].data[k].VariableID);
		   }
		 }

	   // upload synonyms and taxon notes
	   map<int,NEOTOMAVARIABLE>::iterator vitr;

	   // loop through all variables, limiting selection to those in current DatasetID
	   for (vitr = NeotomaVariables.begin(); vitr != NeotomaVariables.end(); vitr++) {
		 NEOTOMAVARIABLE& var = vitr->second;
		 if (VariableIDs.count(var.VariableID) > 0) {
		   if (var.Synonymy.size() > 0) {
			 int TaxonID = var.TaxonID;
			 if (SynonymTaxonIDs.count(TaxonID) == 0) {
			   SynonymTaxonIDs.insert(TaxonID);
			   for (unsigned int k=0; k<var.Synonymy.size(); k++) {
				 newids.clear();
				 InsertData InsertSynonymy(L"InsertSynonymy", 8, ipsHTTPS1, ipsJSONS1, TcpClient1);
				 InsertSynonymy.Add(L"DATASETID", NeotomaDatasetID, -1);
				 InsertSynonymy.Add(L"TAXONID", TaxonID, -1);
				 InsertSynonymy.Add(L"REFTAXONID", var.Synonymy[k].TaxonID, -1);
				 InsertSynonymy.Add(L"FROMCONTRIBUTOR", var.Synonymy[k].Contrib);
				 InsertSynonymy.Add(L"PUBLICATIONID", var.Synonymy[k].NeotomaPubID(), -1);
				 InsertSynonymy.Add(L"NOTES", var.Synonymy[k].Notes);
				 InsertSynonymy.Add(L"CONTACTID", Login->ContactID, -1);
				 InsertSynonymy.Add(L"DATESYNONYMIZED", DateStr(UTCDateTime()));
				 StatusBar1->SimpleText = L"InsertSynonymy";
				 InsertSynonymy.PostData();
				 if (InsertSynonymy.Post(newids, ErrorMsg)) {
				   if (newids.size() == 1) {
					 OutputLine(L"Synonym or invalid taxon uploaded to Synonymy table: DatasetID = " +
					   IntToStr(NeotomaDatasetID) + L", TaxonID = " + IntToStr(TaxonID) +
					   L", RefTaxonID = " + IntToStr(var.Synonymy[k].TaxonID) +
					   L", SyonymyID = " + IntToStr(newids[0]) + L".");
					 }
				   else {
					 ErrorMsg = L"Error inserting into Synonymy table!";
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
			   }
			 }

		   if (!var.Notes.IsEmpty()) {
			 int TaxonID = var.TaxonID;
			 if (NotesTaxonIDs.count(TaxonID) == 0) {
			   NotesTaxonIDs.insert(TaxonID);
			   InsertData InsertTaxonNotes(L"InsertDatasetTaxonNotes", 6, ipsHTTPS1, ipsJSONS1, TcpClient1);
			   InsertTaxonNotes.Add(L"DATASETID", NeotomaDatasetID, -1);
			   InsertTaxonNotes.Add(L"TAXONID", TaxonID, -1);
			   InsertTaxonNotes.Add(L"CONTACTID", Login->ContactID, -1);
			   InsertTaxonNotes.Add(L"DATE", DateStr(UTCDateTime()));
			   InsertTaxonNotes.Add(L"NOTES", vitr->second.Notes);
			   InsertTaxonNotes.Add(L"UPDATE", false);
			   StatusBar1->SimpleText = L"InsertDatasetTaxonNotes";
			   InsertTaxonNotes.PostData();
			   if (InsertTaxonNotes.Post(ErrorMsg)) {
				 OutputLine(L"Taxon notes uploaded to DatasetTaxonNotes table: DatasetID = " +
				   IntToStr(NeotomaDatasetID) + L", TaxonID = " + IntToStr(TaxonID) + L".");
				 }
			   else {
				 OutputError(L"ERROR: " + ErrorMsg);
				 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
				 return false;
				 }
			   }
			 }
		   }
		 }

	 // upload dataset database
	 InsertData InsertDatasetDatabase(L"InsertDatasetDatabase", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
	 InsertDatasetDatabase.Add(L"DATASETID", NeotomaDatasetID, -1);
	 int DatabaseID = NeotomaDatasets[i].NeotomaDatabaseID;
	 InsertDatasetDatabase.Add(L"DATABASEID", DatabaseID, -1);
	 StatusBar1->SimpleText = L"InsertDatasetDatabase";
	 InsertDatasetDatabase.PostData();
	 if (InsertDatasetDatabase.Post(ErrorMsg)) {
	   OutputLine(L"DatasetID " + IntToStr(NeotomaDatasetID) +
		 L" assigned to Neotoma constituent DatabaseID " + IntToStr(DatabaseID) +
		 L" in the DatasetDatabases table.");
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

bool TNeotomaUploadForm::UploadSamples(vector<NEOTOMADATASET>& NeotomaDatasets)
{
   // gets called for each Collection Unit
   // NeotomaDatasets[0].DatasetID is the TempDatasetID
   vector<int> newids;
   UnicodeString msg, ErrorMsg;
   vector<NEOTOMASAMPLEANALYSTS> SampleAnalysts;
   vector<NEOTOMAKEYWORD> SampleKeywords;
   vector<int> TempSampleIDs;  // vector of all temp SampleIDs

   if (NeotomaDatasets.size() == 0)  // no datasets to upload
	 return true;

   for (unsigned int i=0; i<NeotomaDatasets.size(); i++) {
	 if (NeotomaDatasets[i].NeotomaDatasetTypeID == 24)  // specimen stable isotope samples not uploaded here
	   continue;
	 vector<int> NewTempSampleIDs;  // vector of temp SampleIDs for this Dataset, e.g. -1001,-1002,...
	 InsertData InsertSample(L"InsertSample", 9, ipsHTTPS1, ipsJSONS1, TcpClient1);
	 int TempDatasetID = NeotomaDatasets[i].DatasetID;
	 int NeotomaDatasetID = NeotomaDatasetIDs[TempDatasetID];
	 for (unsigned int j=0; j<NeotomaSamples.size(); j++) {
	   if (NeotomaSamples[j].DatasetID == TempDatasetID) {
		 int NeotomaAnalUnitID = NeotomaAnalUnitIDs[NeotomaSamples[j].AnalysisUnitID];
		 InsertSample.Add(L"ANALYSISUNITID", NeotomaAnalUnitID);
		 InsertSample.Add(L"DATASETID", NeotomaDatasetID);
		 InsertSample.Add(L"SAMPLENAME", NeotomaSamples[j].SampleName);
		 InsertSample.Add(L"SAMPLEDATE", DateStr(NeotomaSamples[j].DateSampled));
		 InsertSample.Add(L"ANALYSISDATE", DateStr(NeotomaSamples[j].DateAnalyzed));
		 InsertSample.Add(L"TAXONID", NeotomaSamples[j].TaxonID, -1);
		 InsertSample.Add(L"LABNUMBER", NeotomaSamples[j].LabNumber);
		 InsertSample.Add(L"PREPMETHOD", NeotomaSamples[j].PrepMethod);
		 InsertSample.Add(L"NOTES", NeotomaSamples[j].Notes);
		 NewTempSampleIDs.push_back(NeotomaSamples[j].SampleID);
		 TempSampleIDs.push_back(NeotomaSamples[j].SampleID);

		 if (NeotomaSamples[j].Keywords.size() > 0) {
		   for (unsigned k = 0; k < NeotomaSamples[j].Keywords.size(); k++) {
			 NEOTOMAKEYWORD Keyword;
			 Keyword.SampleID = NeotomaSamples[j].SampleID;
			 map<int,UnicodeString>::iterator itr;
			 for (itr = NeotomaKeywords.begin(); itr != NeotomaKeywords.end(); itr++) {
			   if (SameText(itr->second, NeotomaSamples[j].Keywords[k])) {
				 Keyword.KeywordID = itr->first;
				 SampleKeywords.push_back(Keyword);
				 break;
				 }
			   }
			 }
		   }

		 if (NeotomaSamples[j].AnalystIDs.size() > 0) {
		   int order = 1;
		   for (unsigned int k=0; k<NeotomaSamples[j].AnalystIDs.size(); k++) {
			 NEOTOMASAMPLEANALYSTS Analyst;
			 Analyst.SampleID = NeotomaSamples[j].SampleID;
			 Analyst.ContactID = NeotomaSamples[j].AnalystIDs[k];
			 Analyst.AnalystOrder = order++;
			 SampleAnalysts.push_back(Analyst);
			 }
		   }
		 }
	   }
	 newids.clear();
	 StatusBar1->SimpleText = L"InsertSample";
	 InsertSample.PostData();
	 if (InsertSample.Post(newids, ErrorMsg)) {
	   if (newids.size() == NewTempSampleIDs.size()) {
		 msg = L"DatasetID " + IntToStr(NeotomaDatasetID) + L": " +
			   IntToStr((int)newids.size()) + L" sample";
		 if (newids.size() != 1)
		   msg += L"s";
		 msg += L" uploaded to Samples table: SampleID";
		 if (newids.size() == 1)
		   msg += (L" = " + IntToStr(newids[0]) + L".");
		 else
		   msg += (L"s = " + IntToStr(newids[0]) + L".." + IntToStr(newids.back()) + L".");
		 OutputLine(msg);
		 for (unsigned int j=0; j<newids.size(); j++) {
		   NeotomaSampleIDs[NewTempSampleIDs[j]] = newids[j];  // e.g. NeotomaSampleIDs[-1001] = 167771
		   }
#ifdef WHITMORE
		 if (NeotomaDatasets[i].WhitmoreID1 != -1 && TSSForm->Datasets[0].WhitmoreData)
		   WhitmoreSamples[NeotomaDatasets[i].WhitmoreID1] = newids[0];
#endif
		 }
	   else {
		 ErrorMsg = L"Error inserting into Samples table!";
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

   // upload keywords
   if (SampleKeywords.size() > 0) {
	 InsertData InsertSampleKeyword(L"InsertSampleKeyword", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
	 for (unsigned int i = 0; i < SampleKeywords.size(); i++) {
	   InsertSampleKeyword.Add(L"SAMPLEID", NeotomaSampleIDs[SampleKeywords[i].SampleID]);
	   InsertSampleKeyword.Add(L"KEYWORDID", SampleKeywords[i].KeywordID);
	   }

	 StatusBar1->SimpleText = L"InsertSampleKeyword";
	 InsertSampleKeyword.PostData();
	 if (InsertSampleKeyword.Post(ErrorMsg)) {
	   for (unsigned int i=0; i<SampleKeywords.size(); i++) {
		 msg = L"Sample keyword uploaded to SampleKeywords table: SampleID = " +
		   IntToStr(NeotomaSampleIDs[SampleKeywords[i].SampleID]) + L", KeywordID = " +
		   IntToStr(SampleKeywords[i].KeywordID) + L".";
		 OutputLine(msg);
		 }
	   }
	 else {
	   OutputError(L"ERROR: " + ErrorMsg);
	   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return false;
	   }
	 }

   // upload sample analysts
   if (SampleAnalysts.size() > 0) {
	 InsertData InsertSampleAnalyst(L"InsertSampleAnalyst", 3, ipsHTTPS1, ipsJSONS1, TcpClient1);
	 for (unsigned int i=0; i<SampleAnalysts.size(); i++) {
	   InsertSampleAnalyst.Add(L"SAMPLEID", NeotomaSampleIDs[SampleAnalysts[i].SampleID]);
	   InsertSampleAnalyst.Add(L"CONTACTID", SampleAnalysts[i].ContactID);
	   InsertSampleAnalyst.Add(L"ANALYSTORDER", SampleAnalysts[i].AnalystOrder);
	   }
	 newids.clear();
	 StatusBar1->SimpleText = L"InsertSampleAnalyst";
	 InsertSampleAnalyst.PostData();
	 if (InsertSampleAnalyst.Post(newids, ErrorMsg)) {
	   if (newids.size() == SampleAnalysts.size()) {
		 msg = L"Sample analyst";
		 if (newids.size() > 1)
		   msg += L"s";
		 msg += L" uploaded to SampleAnalysts table: AnalystID";
		 if (newids.size() == 1)
		   msg += (L" = " + IntToStr(newids[0]) + L".");
		 else
		   msg += (L"s = " + IntToStr(newids[0]) + L".." + IntToStr(newids.back()) + L".");
		 OutputLine(msg);
		 }
	   else {
		 ErrorMsg = L"Error inserting into SampleAnalysts table!";
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

   // upload sample ages
   if (!UploadSampleAges(TempSampleIDs))
	 return false;

   // assign NeotomaAnalysisUnitID's to specimens -- needed for isotope data
   for (unsigned int i=0; i<NeotomaSamples.size(); i++) {
	 if (NeotomaSamples[i].data.size() > 0) {
	   int NeotomaAnalysisUnitID = NeotomaAnalUnitIDs[NeotomaSamples[i].AnalysisUnitID];
	   vector<NEOTOMADATA>::iterator itr;
	   vector<NEOTOMADATA>::iterator begin = NeotomaSamples[i].data.begin();
	   vector<NEOTOMADATA>::iterator end = NeotomaSamples[i].data.end();
	   for (itr = begin; itr != end; itr++) {
		 if (itr->Specimens != NULL) {
		   for (int j = 0; j < itr->Specimens->Count; j++) {
			 SPECIMEN* Specimen = (SPECIMEN*)itr->Specimens->Items[j];
			 Specimen->NeotomaAnalysisUnitID = NeotomaAnalysisUnitID;
			 }
		   }
		 }
	   }
	 }

   // upload data and taphonomy
   for (unsigned int i=0; i<NeotomaDatasets.size(); i++) {
     if (NeotomaDatasets[i].NeotomaDatasetTypeID == 24)  // specimen stable isotope datasets not uploaded here
	   continue;
	 unsigned int ndata = 0;
	 vector<pair<int,TList*> > DataSpecimens; // ndata, Specimen pointer
	 vector<pair<int,int> > Taphonomy;  // ndata, TaphID
	 vector<pair<int,ISOSTRATDATA> > IsoStratMetaData; // ndata, ISOSTRATDATA


	 newids.clear();
	 unsigned int nsamples = 0;
	 int TempDatasetID = NeotomaDatasets[i].DatasetID;
	 do {
		  UploadData(TempDatasetID, nsamples, ndata, newids, NeotomaDatasets,
			DataSpecimens, Taphonomy, IsoStratMetaData);
		} while (nsamples < NeotomaSamples.size());

	   if (newids.size() == ndata) {
		 // upload specimens
		 if (DataSpecimens.size() > 0) {
		   if (!UploadSpecimens(DataSpecimens, newids))
			 return false;
		   }

		 // upload taphonomy
		 if (Taphonomy.size() > 0) {
		   InsertData InsertTaphonomy(L"InsertSummaryDataTaphonomy", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
		   for (unsigned int j=0; j<Taphonomy.size(); j++) {
			 InsertTaphonomy.Add(L"DATAID", newids[Taphonomy[j].first], -1);
			 InsertTaphonomy.Add(L"TAPHONOMICTYPEID", Taphonomy[j].second, -1);
			 }
		   StatusBar1->SimpleText = L"InsertSummaryDataTaphonomy";
		   InsertTaphonomy.PostData();
		   if (InsertTaphonomy.Post(ErrorMsg)) {
			 msg = IntToStr((int)Taphonomy.size()) + L" record";
			 if (Taphonomy.size() > 1) msg += L"s";
			 msg += L" uploaded to SummaryDataTaphonomy table.";
			 OutputLine(msg);
			 }
		   else {
			 OutputError(L"ERROR: " + ErrorMsg);
			 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			 return false;
			 }
		   }

		 // upload stable isotope metadata
		 if (IsoStratMetaData.size() > 0) {
		   InsertData InsertIsoStratData(L"InsertIsoStratData", 4, ipsHTTPS1, ipsJSONS1, TcpClient1);
		   for (unsigned int j=0; j<IsoStratMetaData.size(); j++) {
			 InsertIsoStratData.Add(L"DATAID", newids[IsoStratMetaData[j].first], -1);
			 InsertIsoStratData.AddDouble(L"SD", IsoStratMetaData[j].second.SD);
			 InsertIsoStratData.AddInt(L"TAXONID", IsoStratMetaData[j].second.TaxonID);
			 InsertIsoStratData.AddInt(L"ELEMENTTYPEID", IsoStratMetaData[j].second.ElementTypeID);
			 }
		   StatusBar1->SimpleText = L"InsertIsoStratData";
		   InsertIsoStratData.PostData();
		   if (InsertIsoStratData.Post(ErrorMsg)) {
			 msg = IntToStr((int)IsoStratMetaData.size()) + L" record";
			 if (IsoStratMetaData.size() > 1) msg += L"s";
			 msg += L" uploaded to IsoStratData table.";
			 OutputLine(msg);
			 }
		   else {
			 OutputError(L"ERROR: " + ErrorMsg);
			 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			 return false;
			 }
		   }
		 }
	   else {
		 ErrorMsg = L"Error inserting into Data table!";
		 OutputError(L"ERROR: " + ErrorMsg);
		 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 return false;
		 }
	 }
   return true;
}
//---------------------------------------------------------------------------

bool TNeotomaUploadForm::UploadData(int TempDatasetID, unsigned int& nsamples,
	unsigned int& ndata, vector<int>& ids, vector<NEOTOMADATASET>& NeotomaDatasets,
	vector<pair<int,TList*> >& DataSpecimens, vector<pair<int,int> >& Taphonomy,
	vector<pair<int,ISOSTRATDATA> >& IsoStratMetaData)
{
   unsigned int new_data = 0;
   InsertData Insert_Data(L"InsertData", 3, ipsHTTPS1, ipsJSONS1, TcpClient1);
   // int TempDatasetID = NeotomaDatasets[i].DatasetID;
   unsigned int start = nsamples;
   for (unsigned int j=start; j<NeotomaSamples.size(); j++) {
	 if (NeotomaSamples[j].DatasetID == TempDatasetID) {
	   if (NeotomaSamples[j].data.size() > 0) {
		 int NeotomaSampleID = NeotomaSampleIDs[NeotomaSamples[j].SampleID];
		 vector<NEOTOMADATA>::iterator itr;
		 vector<NEOTOMADATA>::iterator begin = NeotomaSamples[j].data.begin();
		 vector<NEOTOMADATA>::iterator end = NeotomaSamples[j].data.end();
		 for (itr = begin; itr != end; itr++) {
		   Insert_Data.Add(L"SAMPLEID", NeotomaSampleID, -1);
		   Insert_Data.Add(L"VARIABLEID", itr->VariableID, -1);
		   Insert_Data.Add(L"VALUE", itr->Value);

		   if (itr->Specimens != NULL)
			 DataSpecimens.push_back(pair<int,TList*>(ndata,itr->Specimens));

		   if (itr->TaphTypeIDs.size() > 0) {
			 for (unsigned int k=0; k<itr->TaphTypeIDs.size(); k++)
			   Taphonomy.push_back(pair<int,int>(ndata,itr->TaphTypeIDs[k]));
			 }

		   if (!itr->IsoStratData.empty)
			 IsoStratMetaData.push_back(pair<int,ISOSTRATDATA>(ndata,itr->IsoStratData));

		   new_data++;
		   ndata++;
		   }
		 }
	   }
	 nsamples++;
	 // if (new_data > 5000)
	 if (new_data > 1000) {
	   // OutputLine(L"ts.insertdata: postdata length = " + IntToStr(Insert_Data.Length()));
	   break;
	   }
	 }

   UnicodeString ErrorMsg;
   vector<int> newids;
   StatusBar1->SimpleText = L"InsertData";
   Insert_Data.PostData();
   if (Insert_Data.Post(newids, ErrorMsg)) {
	 ids.insert(ids.end(), newids.begin(), newids.end());
	 UnicodeString msg = IntToStr((int)new_data) + L" data value";
	 if (new_data != 1)
	   msg += L"s";
	 msg += L" uploaded to Data table: DataID";
	 if (new_data == 1)
	   msg += (L" = " + IntToStr(newids[0]) + L".");
	 else if (new_data > 1)
	   msg += L"s = " + IntToStr(newids[0]) + L".." + IntToStr(newids.back()) + L".";
	 OutputLine(msg);
	 }
   else {
	 OutputError(L"ERROR: " + ErrorMsg);
	 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 return false;
	 }
   return true;
}
//---------------------------------------------------------------------------

bool TNeotomaUploadForm::UploadAccRates(void)
{
   UnicodeString msg, ErrorMsg;
   vector<int> newids;

   if (AccRates.size() == 0)
	 return true;

   // [InsertAccumulationRate](@ANALYSISUNITID int, @CHRONOLOGYID int, @ACCRATE float, @VARIABLEUNITSID int)

   InsertData InsertAccRate(L"InsertAccumulationRate", 4, ipsHTTPS1, ipsJSONS1, TcpClient1);
   for (unsigned int i=0; i<AccRates.size(); i++) {
	 int AnalysisUnitID = NeotomaAnalUnitIDs[AccRates[i].AnalysisUnitID];
	 int ChronologyID = ChronNoToNeotomaChronID(AccRates[i].ChronologyID);
	 InsertAccRate.Add(L"ANALYSISUNITID", AnalysisUnitID, -1);
	 InsertAccRate.Add(L"CHRONOLOGYID", ChronologyID, -1);
	 InsertAccRate.Add(L"ACCRATE", AccRates[i].AccumulationRate);
	 InsertAccRate.Add(L"VARIABLEUNITSID", AccRates[i].VariableUnitsID, -1);
	 }
   newids.clear();
   StatusBar1->SimpleText = L"InsertAccumulationRate";
   InsertAccRate.PostData();
   if (InsertAccRate.Post(ErrorMsg)) {
	 int n = AccRates.size();
	 msg = IntToStr(n) + L" accumulation rate";
	 if (n > 1)
	   msg += L"s";
	 msg += L" uploaded to AccumulationRates table.";
	 OutputLine(msg);
	 }
   else {
	 OutputError(L"ERROR: " + ErrorMsg);
	 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 return false;
	 }
   return true;
}
//---------------------------------------------------------------------------

/*
[TS].[InsertSpecimen]
@DATAID int,
@ELEMENTTYPEID int = null,
@SYMMETRYID int = null,
@PORTIONID int = null,
@MATURITYID int = null,
@SEXID int = null,
@DOMESTICSTATUSID int = null,
@PRESERVATIVE nvarchar(256) = null,
@NISP float = null,
@REPOSITORYID int = null,
@SPECIMENNR nvarchar(50) = null,
@FIELDNR nvarchar(50) = null,
@ARCTOSNR nvarchar(50) = null,
@NOTES nvarchar(MAX) = null
*/

bool TNeotomaUploadForm::UploadSpecimens(vector<pair<int, TList*> >& DataSpecimens, vector<int>& dataids)
{
   UnicodeString ErrorMsg, msg;
   vector<int> newids;
   vector<pair<int,UnicodeString> > GenBankNrs;   // specimen ordinal, GenBankNr
   vector<pair<int,set<int> > > SpecTaph;  // specimen ordinal, <TaphonomicTypeID>
   map<int,int> TSpecimenIDs;  // Tilia SpecimenID, specimen ordinal,
   vector<int> TiliaSpecimenIDs;   // vector of Tilia SpecimenIDs
   int nspec = 0;

   InsertData InsertSpecimen(L"InsertSpecimen", 14, ipsHTTPS1, ipsJSONS1, TcpClient1);
   for (unsigned int i=0; i<DataSpecimens.size(); i++) {
	 int DataID = dataids[DataSpecimens[i].first];
	 TList* Specimens = DataSpecimens[i].second;
	 for (int j=0; j<Specimens->Count; j++) {
	   SPECIMEN* Specimen = (SPECIMEN*)Specimens->Items[j];
	   Specimen->NeotomaDataID = DataID;    // assign NeotomaDataID to specimen -- needed for isotopes
	   InsertSpecimen.Add(L"DATAID", DataID, -1);
	   InsertSpecimen.Add(L"ELEMENTTYPEID", Specimen->NeotomaElementID, -1);
	   InsertSpecimen.Add(L"SYMMETRYID", Specimen->NeotomaSymmetryID, -1);
	   InsertSpecimen.Add(L"PORTIONID", Specimen->NeotomaPortionID, -1);
	   InsertSpecimen.Add(L"MATURITYID", Specimen->NeotomaMaturityID, -1);
	   InsertSpecimen.Add(L"SEXID", Specimen->NeotomaSexID, -1);
	   InsertSpecimen.Add(L"DOMESTICSTATUSID", Specimen->NeotomaDomesticStatusID, -1);
	   InsertSpecimen.Add(L"PRESERVATIVE", Specimen->Preservative);
	   InsertSpecimen.AddDouble(L"NISP", Specimen->NISP);
	   InsertSpecimen.Add(L"REPOSITORYID", Specimen->NeotomaRepositoryID, -1);
	   InsertSpecimen.Add(L"SPECIMENNR", Specimen->SpecNr);
	   InsertSpecimen.Add(L"FIELDNR", Specimen->FieldNr);
	   InsertSpecimen.Add(L"ARCTOSNR", Specimen->ArctosNr);
	   InsertSpecimen.Add(L"NOTES", Specimen->Notes);
	   if (Specimen->GenBankNrs.size() > 0) {
		 set<UnicodeString>::iterator itr;
		 for (itr = Specimen->GenBankNrs.begin(); itr != Specimen->GenBankNrs.end(); itr++)
		   GenBankNrs.push_back(pair<int,UnicodeString>(nspec,*itr));
		 }
	   if (Specimen->NeotomaTaphonomy.size() > 0)
		 SpecTaph.push_back(pair<int,set<int> >(nspec,Specimen->NeotomaTaphonomy));
	   TiliaSpecimenIDs.push_back(Specimen->SpecimenID);
	   TSpecimenIDs[Specimen->SpecimenID] = nspec;
	   nspec++;
	   }
	 }

   StatusBar1->SimpleText = L"InsertSpecimen";
   InsertSpecimen.PostData();
   if (InsertSpecimen.Post(newids, ErrorMsg)) {
	 msg = IntToStr(nspec) + L" record";
	 if (nspec > 1) msg += L"s";
	 msg += L" uploaded to Specimens table: SpecimenID";
	 if (nspec == 1)
	   msg += (L" = " + IntToStr(newids[0]) + L".");
	 else if (nspec > 1)
	   msg += L"s = " + IntToStr(newids[0]) + L".." + IntToStr(newids.back()) + L".";
	 OutputLine(msg);

	 // assign Neotoma SpecimenIDs to Tilia SpecimenIDs
	 for (unsigned int i = 0; i < TiliaSpecimenIDs.size(); i++)
	   NeotomaSpecimenIDs[TiliaSpecimenIDs[i]] = newids[i];

	 // assign Neotoma SpecimenIDs to NeotomaTaxaDated
	 for (unsigned int i=0; i<NeotomaTaxaDated.size(); i++) {   // NeotomaTaxaDated[i].SampleID
	   if (NeotomaTaxaDated[i].SpecimenID != -1) {
		 if (TSpecimenIDs.count(NeotomaTaxaDated[i].SpecimenID) == 1)
		   NeotomaTaxaDated[i].NeotomaSpecimenID = newids[TSpecimenIDs[NeotomaTaxaDated[i].SpecimenID]];
		 }
	   }
	 }
   else {
	 OutputError(L"ERROR: " + ErrorMsg);
	 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 return false;
	 }

   if (GenBankNrs.size() > 0) {
	 InsertData InsertGenBankNr(L"InsertSpecimenGenBankNr", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
	 for (unsigned int i=0; i<GenBankNrs.size(); i++) {
	   InsertGenBankNr.Add(L"SPECIMENID", newids[GenBankNrs[i].first], -1);
	   InsertGenBankNr.Add(L"GENBANKNR", GenBankNrs[i].second);
	   }

	 StatusBar1->SimpleText = L"InsertSpecimenGenBankNr";
	 InsertGenBankNr.PostData();
	 if (InsertGenBankNr.Post(ErrorMsg)) {
	   msg = IntToStr((int)GenBankNrs.size()) + L" record";
	   if (GenBankNrs.size() > 1) msg += L"s";
	   msg += L" uploaded to SpecimenGenBank table.";
	   OutputLine(msg);
	   }
	 else {
	   OutputError(L"ERROR: " + ErrorMsg);
	   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return false;
	   }
	 }

   if (SpecTaph.size() > 0) {
	 InsertData InsertSpecTaph(L"InsertSpecimenTaphonomy", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
	 for (unsigned int i=0; i<SpecTaph.size(); i++) {
	   int SpecimenID = newids[SpecTaph[i].first];
	   set<int>& Types = SpecTaph[i].second;
	   set<int>::iterator itr;
	   for (itr = Types.begin(); itr != Types.end(); itr++) {
		 InsertSpecTaph.Add(L"SPECIMENID",SpecimenID,-1);
		 InsertSpecTaph.Add(L"TAPHONOMICTYPEID",*itr,-1);
		 }
	   }

	 StatusBar1->SimpleText = L"InsertSpecimenTaphonomy";
	 InsertSpecTaph.PostData();
	 if (InsertSpecTaph.Post(ErrorMsg)) {
	   msg = IntToStr((int)SpecTaph.size()) + L" record";
	   if (SpecTaph.size() > 1) msg += L"s";
	   msg += L" uploaded to SpecimenTaphonomy table.";
	   OutputLine(msg);
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

bool TNeotomaUploadForm::UploadSampleAges(vector<int>& TempSampleIDs)
{
   vector<int> newids;
   UnicodeString msg, ErrorMsg;

   // typedef map<int,NEOTOMAAGE> NEOTOMASAMPLEAGE;  // SampleID, NEOTOMASAMPLEAGE
   // map<int,NEOTOMASAMPLEAGE> NeotomaSampleAges;   // map<ChronNo, map<SampleID,NEOTOMAAGE> >

   if (NeotomaSampleAges.size() > 0) {
	 set<int> TempSampleIDSet(TempSampleIDs.begin(), TempSampleIDs.end());
	 InsertData InsertSampleAge(L"InsertSampleAge", 5, ipsHTTPS1, ipsJSONS1, TcpClient1);
	 map<int,NEOTOMASAMPLEAGE>::iterator chron_itr;
	 map<int,NEOTOMASAMPLEAGE>::iterator chron_begin = NeotomaSampleAges.begin();
	 map<int,NEOTOMASAMPLEAGE>::iterator chron_end = NeotomaSampleAges.end();
	 unsigned int ns = 0;
	 for (chron_itr = chron_begin; chron_itr != chron_end; chron_itr++) {
	   int ChronologyID = ChronNoToNeotomaChronID(chron_itr->first);
	   // this was a temporary hack to upload a charcoal dataset to an existing chronology
	   // int ChronologyID = 13316;
	   map<int,NEOTOMAAGE>::reverse_iterator samp_itr;
	   map<int,NEOTOMAAGE>::reverse_iterator samp_begin = chron_itr->second.rbegin();
	   map<int,NEOTOMAAGE>::reverse_iterator samp_end = chron_itr->second.rend();
	   for (samp_itr = samp_begin; samp_itr != samp_end; samp_itr++) {
		 if (TempSampleIDSet.count(samp_itr->first) > 0) {
		   int SampleID = NeotomaSampleIDs[samp_itr->first];
		   InsertSampleAge.Add(L"SAMPLEID", SampleID, -1);
		   InsertSampleAge.Add(L"CHRONOLOGYID", ChronologyID, -1);
		   InsertSampleAge.Add(L"AGE", samp_itr->second.Age);
		   InsertSampleAge.Add(L"AGEYOUNGER", samp_itr->second.AgeYounger);
		   InsertSampleAge.Add(L"AGEOLDER", samp_itr->second.AgeOlder);
		   ns++;
		   }
		 }
	   }

	 if (ns == 0)      // no samples to upload
	   return true;

	 newids.clear();
	 StatusBar1->SimpleText = L"InsertSampleAge";
	 InsertSampleAge.PostData();
	 if (InsertSampleAge.Post(newids, ErrorMsg)) {
	   if (newids.size() == ns) {
		 msg = IntToStr((int)ns) + L" sample age";
		 if (ns > 1)
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

// map<int,int> TiliaChronIDs;        // TempChronID, ChronNo
// map<int,int> NeotomaChronIDs;      // TempChronID, NeotomaChronID
// ChronNo to NeotomaChronologyID

// This function finds the NeotomaChronID for the Tilia ChronNo.
// Both are mapped to the TempChronID.
int TNeotomaUploadForm::ChronNoToNeotomaChronID(int ChronNo)
{
   int NeotomaChronID = -1;
   map<int,int>::iterator itr;
   for (itr = TiliaChronIDs.begin(); itr != TiliaChronIDs.end(); itr++) {
	 if (itr->second == ChronNo) {
	   NeotomaChronID = NeotomaChronIDs[itr->first];
	   break;
	   }
	 }
   return NeotomaChronID;
}
//---------------------------------------------------------------------------

int TNeotomaUploadForm::FindTempNeotomaCollUnitID(int CollUnitID)
{
   int TempCollUnitID = -1;
   map<int,int>::iterator itr;
   for (itr = NeotomaCollUnitIDs.begin(); itr != NeotomaCollUnitIDs.end(); itr++) {
	 if (CollUnitID == itr->second) {
	   TempCollUnitID = itr->first;
	   break;
	   }
	 }
   return TempCollUnitID;
}
//---------------------------------------------------------------------------

int TNeotomaUploadForm::FindTempNeotomaAnalUnitID(int AnalUnitID)
{
   int TempAnalUnitID = -1;
   map<int,int>::iterator itr;
   for (itr = NeotomaAnalUnitIDs.begin(); itr != NeotomaAnalUnitIDs.end(); itr++) {
	 if (AnalUnitID == itr->second) {
	   TempAnalUnitID = itr->first;
	   break;
	   }
	 }
   return TempAnalUnitID;
}
//---------------------------------------------------------------------------

int TNeotomaUploadForm::FindCollUnitID(int AnalUnitID)
{
   int CollUnitID = -1;
   for (unsigned int i=0; i<NeotomaAnalysisUnits.size(); i++) {
	 if (NeotomaAnalysisUnits[i].AnalysisUnitID == AnalUnitID) {
	   CollUnitID = NeotomaAnalysisUnits[i].CollectionUnitID;
	   break;
	   }
	 }
   return CollUnitID;
}
//---------------------------------------------------------------------------

/*
InsertDatasetSubmission
@DATASETID int,
@DATABASEID int,
@CONTACTID int,
@SUBMISSIONTYPEID int,
@SUBMISSIONDATE date,
@NOTES nvarchar(MAX) = null
*/
// map<int,int> NeotomaDatasetIDs;    // TempDatasetID, NeotomaDatasetID

bool TNeotomaUploadForm::UploadDatasetSubmissions(int CollUnitID,
	vector<NEOTOMADATASET>& NeotomaDatasets, DATASETSUBMISSION& GeochronSubmission)
{
   vector<int> newids;
   vector<int> DatasetIDs;
   vector<pair<int,int> > SubmissionIDs;  // DatabaseID, SubmissionTypeID
   UnicodeString ErrorMsg;

   // map<int,int> NeotomaDatasetIDs;    // TempDatasetID, NeotomaDatasetID
   map<int,int>::iterator itr;
   map<int,int>::iterator begin = NeotomaDatasetIDs.begin();
   map<int,int>::iterator end = NeotomaDatasetIDs.end();

   unsigned int ndatasets = 0;
   InsertData InsertDatasetSubmission(L"InsertDatasetSubmission", 6, ipsHTTPS1, ipsJSONS1, TcpClient1);
   for (itr = begin; itr != end; itr++) {
	 int DatabaseID;
	 int SubmissionTypeID;
	 UnicodeString SubmissionNotes;
	 int TempDatasetID = itr->first;
	 int NeotomaDatasetID = itr->second;

	 //int DatabaseID;
	 DatasetIDs.push_back(NeotomaDatasetID);

	 bool found = false;
	 if (NeotomaDatasetID == GeochronSubmission.DatasetID) {
	   DatabaseID = GeochronSubmission.DatabaseID;
	   SubmissionTypeID = GeochronSubmission.SubmissionTypeID;
	   SubmissionNotes = GeochronSubmission.Notes;
	   found = true;
	   }
	 else {
	   for (unsigned int i=0; i<NeotomaDatasets.size(); i++) {
		 if (NeotomaDatasets[i].DatasetID == TempDatasetID) {    // NeotomaDatasets[i].DatasetID == 0
		   DatabaseID = NeotomaDatasets[i].NeotomaDatabaseID;
		   SubmissionTypeID = NeotomaDatasets[i].NeotomaSubmissionTypeID;
		   SubmissionNotes = NeotomaDatasets[i].NeotomaSubmissionNotes;
		   found = true;
		   break;
		   }
		 }
	   }

	 if (found) {
	   SubmissionIDs.push_back(pair<int,int>(DatabaseID,SubmissionTypeID));
	   InsertDatasetSubmission.Add(L"DATASETID", NeotomaDatasetID, -1);
	   InsertDatasetSubmission.Add(L"DATABASEID", DatabaseID, -1);
	   InsertDatasetSubmission.Add(L"CONTACTID", Login->ContactID, -1);
	   InsertDatasetSubmission.Add(L"SUBMISSIONTYPEID", SubmissionTypeID, -1);
	   InsertDatasetSubmission.Add(L"SUBMISSIONDATE", DateStr(UTCDateTime()));
	   InsertDatasetSubmission.Add(L"NOTES", SubmissionNotes);
	   ndatasets++;
	   }
	 }

   StatusBar1->SimpleText = L"InsertDatasetSubmission";
   InsertDatasetSubmission.PostData();
   if (InsertDatasetSubmission.Post(newids, ErrorMsg)) {
	 if (newids.size() == ndatasets) {
	   for (unsigned int i=0; i<newids.size(); i++) {
		 OutputLine(L"Dataset submission uploaded to DatasetSubmissions table: DatasetSubmissionID = " +
		   IntToStr(newids[i]) + L"; DatasetID = " + IntToStr(DatasetIDs[i]) +
		   L", DatabaseID = " + IntToStr(SubmissionIDs[i].first) + L", ContactID = " +
		   IntToStr(Login->ContactID) + L", SubmissionTypeID = " +
		   IntToStr(SubmissionIDs[i].second) + L", SubmissionDate = «" + DateStr(UTCDateTime()) + L"».");
		 }
	   }
	 else {
	   ErrorMsg = L"Error inserting into DatasetSubmissions table!";
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

   return true;
}
//---------------------------------------------------------------------------

// Copy button
void __fastcall TNeotomaUploadForm::cxButton4Click(TObject *Sender)
{
   RichEdit1->SelectAll();
   RichEdit1->CopyToClipboard();
}
//---------------------------------------------------------------------------

// Save button
void __fastcall TNeotomaUploadForm::cxButton1Click(TObject *Sender)
{
   UnicodeString FileName = TSSForm->TilFileName;
   if (!FileName.IsEmpty()) {
	 UnicodeString InitialDir = ExtractFilePath(FileName);
	 if (*InitialDir.LastChar() == L'\\')
	   InitialDir.Delete(InitialDir.Length(),1);
	 SaveDialog1->InitialDir = InitialDir;
	 }

   if (SaveDialog1->Execute()) {
	 bool save = true;
	 FileName = SaveDialog1->FileName;
	 UnicodeString ext = ExtractFileExt(FileName);
	 if (ext.IsEmpty())
	   FileName += L".rtf";
	 else if (!SameText(ext, L".rtf")) {
	   save = false;
	   MessageDlg(L"File extension not valid.", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   }
	 if (save) {
	   RichEdit1->Lines->SaveToFile(FileName, TEncoding::UTF8);
	   MessageDlg(L"File saved: " + FileName, mtInformation, TMsgDlgButtons() << mbOK, 0);
	   }
	 }
}
//---------------------------------------------------------------------------

UnicodeString TNeotomaUploadForm::FormatPostDataInsert(UnicodeString method, vector<UnicodeString>& records)
{
   UnicodeString json;
   json = L"{\"method\":\"";
   json += method;
   json += L"\", \"data\":[";
   for (unsigned int i=0; i<records.size(); i++) {
	 if (i > 0)
	   json += L",";
	 json += records[i];
	 }
   json += L"]}";
   return json;
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaUploadForm::ipsHTTPS1Error(TObject *Sender, TipsHTTPSErrorEventParams *e)
{
   UnicodeString msg = L"Error Code " + IntToStr(e->ErrorCode) + L": " + e->Description;
   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
}
//---------------------------------------------------------------------------

void TNeotomaUploadForm::ResetJSONParser(TipwJSON* ipwJSON)
{
   ipwJSON->Reset();
   if (tiGlobals->InternetTimeout > 60)
	 ipwJSON->Timeout = tiGlobals->InternetTimeout;
   ipwJSON->Config("KeepAlive=true");
   ipwJSON->Config("CodePage=65001");   // UTF-8 CodePage
   ipwJSON->BuildDOM = true;
   ipwJSON->LocalHost = TcpClient1->LocalHostAddr();
   ipwJSON->TransferredDataLimit = 0;
}
//---------------------------------------------------------------------------

bool TNeotomaUploadForm::ParseUploadResponse(UnicodeString TransferredData, vector<int>& newids)
{
   if (TransferredData.SubString(3,7) != L"success") {
	 ShowMessage(TransferredData);
	 OutputLine(TransferredData);
	 return false;
	 }

   newids.clear();
   ResetJSONParser(ipwJSON2);
   ipwJSON2->Input(TransferredData);
   ipwJSON2->XPath = L"/json/success/";

   int success;
   if (!TryStrToInt(ipwJSON2->XText, success))
	 return false;
   if (!success)
	 return false;

   ipwJSON2->XPath = L"/json/";
   int count = ipwJSON2->XChildrenCount;
   if (count > 1) {
	 ipwJSON2->XPath = L"/json/newids/";
	 count = ipwJSON2->XChildrenCount;
	 int newid;
	 for (int i=1; i<=count; i++) {
	   ipwJSON2->XPath = L"/json/newids/[" + IntToStr(i) + L"]/";
	   if (TryStrToInt(ipwJSON2->XText, newid))
		 newids.push_back(newid);
	   else
		 return false;
	   }
	 }
   return true;
}
//---------------------------------------------------------------------------

int TNeotomaUploadForm::CheckSiteName(SITE* site_ptr)
{
   UnicodeString Line;
   int rv = mrOk;

   if (site_ptr->SiteName.IsEmpty()) {
	 OutputError(L"ERROR: Site name missing.");
	 rv = MessageDlg(L"Site name is missing!", Dialogs::mtError, TMsgDlgButtons() << mbIgnore << mbAbort, 0);
	 }
   else
	 OutputLine(L"Site name is «" + site_ptr->SiteName + L"».");
   SetProgressBarPosition();
   return rv;
}
//---------------------------------------------------------------------------

void TNeotomaUploadForm::CheckSiteAltitude(SITE* site_ptr)
{
   UnicodeString Line;

   if (site_ptr->Altitude.IsEmpty())
	 OutputWarning(L"WARNING: No site altitude entered.");
   else
	 OutputLine(L"Site altitude is " + site_ptr->Altitude.AsType(varOleStr) + L" m.");
   //SetProgressBarPosition();
}
//---------------------------------------------------------------------------

void TNeotomaUploadForm::CheckSiteArea(SITE* site_ptr)
{
   UnicodeString Line;

   if (site_ptr->Area.IsEmpty())
	 OutputNote(L"NOTE: No site area entered.");
   else
	 OutputLine(L"Site area is " + site_ptr->Area.AsType(varOleStr) + L" ha.");
   // SetProgressBarPosition();
}
//---------------------------------------------------------------------------

void TNeotomaUploadForm::CheckLakeParameters(SITE* site_ptr)
{
   vector<void*> vptrs;

   if (site_ptr->LakeParams.size() > 0) {
	 site_ptr->NeotomaLakeParams.clear();
	 NeotomaLakeParameterTypesTable LakeParameterTypes(ipsJSONS1, TcpClient1);
	 StatusBar1->SimpleText = LakeParameterTypes.WebServiceName();
	 Screen->Cursor = crHourGlass;
	 if (LakeParameterTypes.Execute()) {
	   if (LakeParameterTypes.Size() > 0) {
         for (unsigned int i=0; i<site_ptr->LakeParams.size(); i++) {
		   UnicodeString LakeParam = site_ptr->LakeParams[i].Name;
		   if (LakeParameterTypes.Find(L"LakeParameter", LakeParam, vptrs) == 1) {
			 LAKEPARAMRECORD *lpRec = (LAKEPARAMRECORD*)vptrs[0];
			 int ID = lpRec->LakeParameterID;
			 double Value = site_ptr->LakeParams[i].Value;
			 site_ptr->NeotomaLakeParams[ID] = Value;
			 OutputLine(L"Lake parameter «" + LakeParam + L"» validated: LakeParameterID = " +
						IntToStr(ID) + L", Value = " + FloatToStr(Value));
			 }
		   else
			 OutputError(L"ERROR: Lake parameter «" + LakeParam + L"» not in Neotoma LakeParameterTypes table." );
		   }
		 }
	   }
	 StatusBar1->SimpleText = L"";
	 Screen->Cursor = crHourGlass;
	 }

   // SetProgressBarPosition();
}
//---------------------------------------------------------------------------

bool TNeotomaUploadForm::CheckSiteLatLong(SITE* site_ptr)
{
   UnicodeString Line;
   int Errors1 = TotalMessages.Errors;

   // Check site lat/long coordinates
   if (TSSForm->cxRadioButton1->Checked) {     // point coordinate
	 if (site_ptr->LatNorth.IsEmpty())
	   OutputError(L"ERROR: Site latitude missing.");
	 else if (site_ptr->LatNorth > 90.0 || site_ptr->LatNorth < -90.0)
	   OutputError(L"ERROR: Latitude " + site_ptr->LatNorth.AsType(varOleStr) +
				   L" is not valid. Must be in the range -90.0 to 90.0.");
	 if (site_ptr->LongWest.IsEmpty())
	   OutputError(L"ERROR: Site longitude missing.");
	 }
   else {      // box coordinates
	 if (site_ptr->LatNorth.IsEmpty() || site_ptr->LatSouth.IsEmpty())
	   OutputError(L"ERROR: Site latitude missing.");
	 if (site_ptr->LongWest.IsEmpty() || site_ptr->LongEast.IsEmpty())
	   OutputError(L"ERROR: Site longitude missing.");
	 if (TotalMessages.Errors == Errors1) {
	   if (site_ptr->LatNorth < site_ptr->LatSouth)
		 OutputError(L"ERROR: Site south latitude is greater than north latitude.");
	   if (site_ptr->LongWest > site_ptr->LongEast)
		 OutputError(L"ERROR: Site west longitude is greater than east longitude.");
	   }
	 }

   if (TotalMessages.Errors > Errors1) {
	 //SetProgressBarPosition();
	 return false;
	 }

   ValidateLatLongForm = new TValidateLatLongForm(this);
   int rv = ValidateLatLongForm->ShowModal();
   delete ValidateLatLongForm;
   //SetProgressBarPosition();
   return(rv == mrYes);
}
//---------------------------------------------------------------------------

bool TNeotomaUploadForm::CheckGeoPolUnits(SITE* site_ptr)
{
   vector<void*> vptrs;
   UnicodeString Line;
   int CountryID;
   int StateID = -1;
   int CountyID = -1;
   int count;
   bool rv = true;

   if (site_ptr->Country.IsEmpty()) {
	 OutputError(L"ERROR: First GeoPolitical Division is missing.");
	 //SetProgressBarPosition();
	 return rv;
	 }

   SetProgressBar(MARQUEE);
   Screen->Cursor = crHourGlass;

   GeoPolUnitsByNameAndRank Country(ipsJSONS1, TcpClient1);
   Country.AddParam(L"GEOPOLNAME", site_ptr->Country);
   Country.AddParam(L"RANK", 1);
   StatusBar1->SimpleText = Country.WebServiceName();
   Screen->Cursor = crHourGlass;
   if (Country.Execute()) {
	 if (Country.Size() == 1) {
	   CountryID = Country.Items[0].GeoPoliticalID;
	   site_ptr->NeotomaGeoPolID[NTM_COUNTRY] = CountryID;
	   OutputLine(L"First Geopolitical Division «" + site_ptr->Country +
				  L"» validated. GeoPoliticalID = " + IntToStr(CountryID) + L".");

	   // now check states
	   if (!site_ptr->State.IsEmpty()) {
		 GeoPolUnitByNameAndHigherID State(ipsJSONS1, TcpClient1);
		 State.AddParam(L"GEOPOLNAME", site_ptr->State);
		 State.AddParam(L"HIGHERGEOPOLID", CountryID);
		 StatusBar1->SimpleText = State.WebServiceName();
		 if (State.Execute()) {
		   if (State.Size() == 1) {
			 StateID = State.Items[0].GeoPoliticalID;
			 site_ptr->NeotomaGeoPolID[NTM_STATE] = StateID;
			 OutputLine(L"Second Geopolitical Division «" + site_ptr->State +
						L"» validated. GeoPoliticalID = " + IntToStr(StateID) + L".");

			 // now check counties
			 if (!site_ptr->County.IsEmpty()) {
			   GeoPolUnitByNameAndHigherID County(ipsJSONS1, TcpClient1);
			   County.AddParam(L"GEOPOLNAME", site_ptr->County);
			   County.AddParam(L"HIGHERGEOPOLID", StateID);
			   StatusBar1->SimpleText = County.WebServiceName();
			   if (County.Execute()) {
				 if (County.Size() == 1) {
				   CountyID = County.Items[0].GeoPoliticalID;
				   site_ptr->NeotomaGeoPolID[NTM_COUNTY] = CountyID;
				   OutputLine(L"Third Geopolitical Division «" + site_ptr->County +
							  L"» validated. GeoPoliticalID = " + IntToStr(CountyID) + L".");
				   }
				 else
				   OutputError(L"ERROR: Third Geopolicital Division «" + site_ptr->Country +L"» is not valid.");
				 }
			   else {
				 rv = false;
				 }
			   }
			 else { // check if tertiary subdivisions exist
			   NumberOfGeoPolSubdivs Counties(ipsJSONS1, TcpClient1);
			   Counties.AddParam(L"HIGHERGEOPOLID", StateID);
			   StatusBar1->SimpleText = Counties.WebServiceName();
			   if (Counties.Execute()) {
				 int nCounties = Counties.NumberOfSubdivs;
				 if (nCounties > 0) {
				   OutputWarning(L"WARNING: Tertiary Geopolitical divisions exist for «" +
					   site_ptr->State + L"», but a tertiary division has not been selected.");
				   }
				 }
			   else {
				 rv = false;
				 }
			   }
			 }
		   else
			 OutputError(L"ERROR: Second Geopolicital Division «" + site_ptr->State +L"» is not valid.");
		   }
		 else {
		   rv = false;
		   }
		 }
	   else {  // check if secondary subdivisions exist
		 NumberOfGeoPolSubdivs States(ipsJSONS1, TcpClient1);
		 States.AddParam(L"HIGHERGEOPOLID", StateID);
		 StatusBar1->SimpleText = States.WebServiceName();
		 if (States.Execute()) {
		   int nStates = States.NumberOfSubdivs;
		   if (nStates > 0) {
			 OutputWarning(L"WARNING: Secondary Geopolitical divisions exist for «" +
				 site_ptr->Country + L"», but a secondary division has not been selected.");
			 }
		   }
		 else {
		   rv = false;
		   }
		 }

	   // Check AdminUnit
	   if (!site_ptr->AdminUnit.IsEmpty())
		 CheckAdminUnit(CountryID, StateID, CountyID, false);
	   }
	 else
	   OutputError(L"ERROR: First Geopolicital Division «" + site_ptr->Country +L"» is not valid.");
	 }
   else {
	 rv = mrAbort;
	 }

   Screen->Cursor = crDefault;
   StatusBar1->SimpleText = L"";
   SetProgressBar(CORE);
   //SetProgressBarPosition();
   return rv;
}
//---------------------------------------------------------------------------

int TNeotomaUploadForm::CheckAdminUnit(int CountryID, int StateID, int CountyID, bool Recheck)
{
   int rv = mrOk;
   int AdminUnitID;
   vector<int> AdminUnitHigherIDs;

   GeoPolUnitsByNameAndRank AdminUnit(ipsJSONS1, TcpClient1);
   AdminUnit.AddParam(L"GEOPOLNAME", site_ptr->AdminUnit);
   AdminUnit.AddParam(L"RANK", 4);
   StatusBar1->SimpleText = AdminUnit.WebServiceName();

   if (AdminUnit.Execute()) {
	 if (AdminUnit.Size() > 0) {
	   for (unsigned int i=0; i<AdminUnit.Size(); i++)  // get list of HigherIDs for AdminUnit
		 AdminUnitHigherIDs.push_back(AdminUnit.Items[i].HigherGeoPoliticalID);
	   bool found = false;
	   vector<int>::iterator itr;
	   vector<int>::iterator begin = AdminUnitHigherIDs.begin();
	   vector<int>::iterator end = AdminUnitHigherIDs.end();
	   if ((itr = find(begin, end, CountryID)) != end)
		 found = true;
	   else if ((itr = find(begin, end, StateID)) != end)
		 found = true;
	   else if ((itr = find(begin, end, CountyID)) != end)
		 found = true;
	   if (found) {
		 int HigherID = *itr;
		 for (unsigned int i=0; i<AdminUnit.Size(); i++) {
		   if (HigherID == AdminUnit.Items[i].HigherGeoPoliticalID) {
			 AdminUnitID = AdminUnit.Items[i].GeoPoliticalID;
			 site_ptr->NeotomaGeoPolID[NTM_ADMINUNIT] = AdminUnitID;
			 OutputLine(L"Administrative Unit «" + site_ptr->AdminUnit +
						L"» validated. GeoPoliticalID = " + IntToStr(AdminUnitID) + L".");
			 break;
			 }
		   }
		 }
	   else if (Recheck) {
		 rv = mrCancel;
		 }
	   else {
		 vector<UnicodeString> AdminUnitParents;
		 for (unsigned int i=0; i<AdminUnitHigherIDs.size(); i++)
		   AdminUnitParents.push_back(GetGeoPolNameByID(AdminUnitHigherIDs[i]));
		   UnicodeString msg = L"«" + site_ptr->AdminUnit + L"» is in Neotoma and is assigned to ";
		   unsigned int size = AdminUnitParents.size();
		   for (unsigned int i=0; i<size; i++) {
			 if (i > 0) {
			   if (i == 1 && size == 2)
				 msg += L" and ";
			   else if (i == size-1)
				 msg += L", and ";
			   else
				 msg += L", ";
			   }
			 msg += (L"«" + AdminUnitParents[i] + L"»");
			 }
		   msg += (L".\nAssign «" + site_ptr->AdminUnit + L"» to «" + site_ptr->Country + L"»");
		   if (StateID > -1) {
			 if (CountyID == -1)
			   msg += (L" or «" + site_ptr->State + L"».");
			 else
			   msg += (L", «" + site_ptr->State + L"», or «" + site_ptr->County + L"»");
			 }
		   msg += L"?\n(This admin unit may be a different unit with the same name.)";
		   while (AddNewAdminUnit(msg, site_ptr->AdminUnit, CountryID, StateID, CountyID) == mrRetry);
		 }
	   }
	 else {  // AdminUnit does not exist
	   UnicodeString msg = L"Administrative Unit «" + site_ptr->AdminUnit +
		  L"» is not in Neotoma. Add it to the database?";
	   while (AddNewAdminUnit(msg, site_ptr->AdminUnit, CountryID, StateID, CountyID) == mrRetry);
	   }
	 }
   return rv;
}
//---------------------------------------------------------------------------

UnicodeString TNeotomaUploadForm::GetGeoPolNameByID(int ID)
{
   UnicodeString GeoPoliticalName;

   GeoPolUnitByID GeoPolUnit(ipsJSONS1, TcpClient1);
   GeoPolUnit.AddParam(L"GEOPOLID", ID);
   StatusBar1->SimpleText = GeoPolUnit.WebServiceName();
   if (GeoPolUnit.Execute())
	 GeoPoliticalName = GeoPolUnit.Items[0].GeoPoliticalName;
   return GeoPoliticalName;
}
//---------------------------------------------------------------------------

int TNeotomaUploadForm::AddNewAdminUnit(UnicodeString msg, UnicodeString AdminUnit,
		int CountryID, int StateID, int CountyID)
{
   int rv = mrOk;
   map<UnicodeString, UnicodeString> GeoPol2Units;
   map<UnicodeString, UnicodeString> GeoPol3Units;

   SetProgressBar(CORE);
   if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes) {
	 NewAdminUnit = new TNewAdminUnit(TSSForm);
	 NewAdminUnit->ShowUploadButton();
	 NewAdminUnit->LabeledEdit1->Text = site_ptr->AdminUnit;
	 NewAdminUnit->Edit1->Text = site_ptr->Country;

	 GeoPolUnitByHigherID CountrySubDivs(ipsJSONS1, TcpClient1);
	 CountrySubDivs.AddParam(L"HIGHERGEOPOLID", CountryID);
	 StatusBar1->SimpleText = CountrySubDivs.WebServiceName();
	 if (CountrySubDivs.Execute()) {
	   if (CountrySubDivs.Size() > 0) {
		 NewAdminUnit->cxCheckComboBox1->Properties->Sorted = true;
		 NewAdminUnit->cxCheckComboBox1->Properties->Items->BeginUpdate();
		 for (unsigned int i=0; i<CountrySubDivs.Size(); i++) {
		   UnicodeString State = CountrySubDivs.Items[i].GeoPoliticalName;
		   NewAdminUnit->cxCheckComboBox1->Properties->Items->AddCheckItem(State);
		   GeoPol2Units[State] = CountrySubDivs.Items[i].GeoPoliticalUnit;
		   }
		 NewAdminUnit->cxCheckComboBox1->Properties->Items->EndUpdate();
		 NewAdminUnit->SetGeoPol2Units(GeoPol2Units);

		 for (int i=0; i<NewAdminUnit->cxCheckComboBox1->Properties->Items->Count; i++) {
		   if (SameText(site_ptr->State, NewAdminUnit->cxCheckComboBox1->Properties->Items->Items[i]->Description)) {
			 NewAdminUnit->cxCheckComboBox1->ItemIndex = i;
			 NewAdminUnit->cxCheckComboBox1->States[i] = cbsChecked;
			 NewAdminUnit->RadioButton2->Caption = Capitalize(GeoPol2Units[site_ptr->State]);
			 break;
			 }
		   }
		 // get state subdivisions (counties)
		 if (StateID > -1) {
		   GeoPolUnitByHigherID StateSubDivs(ipsJSONS1, TcpClient1);
		   StateSubDivs.AddParam(L"HIGHERGEOPOLID", StateID);
		   StatusBar1->SimpleText = StateSubDivs.WebServiceName();
		   if (StateSubDivs.Execute()) {
			 if (StateSubDivs.Size() > 0) {
			   NewAdminUnit->cxCheckComboBox2->Properties->Sorted = true;
			   NewAdminUnit->cxCheckComboBox2->Properties->Items->BeginUpdate();
			   for (unsigned int i=0; i<StateSubDivs.Size(); i++) {
				 UnicodeString County = StateSubDivs.Items[i].GeoPoliticalName;
				 NewAdminUnit->cxCheckComboBox2->Properties->Items->AddCheckItem(County);
				 GeoPol3Units[County] = StateSubDivs.Items[i].GeoPoliticalUnit;
				 }
			   NewAdminUnit->cxCheckComboBox2->Properties->Items->EndUpdate();
			   NewAdminUnit->SetGeoPol3Units(GeoPol3Units);

			   for (int i=0; i<NewAdminUnit->cxCheckComboBox2->Properties->Items->Count; i++) {
				 if (SameText(site_ptr->County, NewAdminUnit->cxCheckComboBox2->Properties->Items->Items[i]->Description)) {
				   NewAdminUnit->cxCheckComboBox2->ItemIndex = i;
				   NewAdminUnit->cxCheckComboBox2->States[i] = cbsChecked;
				   NewAdminUnit->RadioButton3->Caption = Capitalize(GeoPol3Units[site_ptr->County]);
				   break;
				   }
				 }
			   }
			 else {
			   NewAdminUnit->cxCheckComboBox2->Enabled = false;
			   NewAdminUnit->RadioButton3->Caption = "Third Geopolitical Divsion";
			   NewAdminUnit->RadioButton3->Enabled = false;
			   }
			 }
		   }
		 else {
		   NewAdminUnit->cxCheckComboBox1->Enabled = false;
		   NewAdminUnit->RadioButton2->Caption = "Second Geopolitical Divsion";
		   NewAdminUnit->RadioButton2->Enabled = false;
		   NewAdminUnit->cxCheckComboBox2->Enabled = false;
		   NewAdminUnit->RadioButton3->Caption = "Third Geopolitical Divsion";
		   NewAdminUnit->RadioButton3->Enabled = false;
		   }
		 }
	   else {
		 NewAdminUnit->cxCheckComboBox1->Enabled = false;
		 NewAdminUnit->RadioButton2->Caption = "Second Geopolitical Divsion";
		 NewAdminUnit->RadioButton2->Enabled = false;
		 NewAdminUnit->cxCheckComboBox2->Enabled = false;
		 NewAdminUnit->RadioButton3->Caption = "Third Geopolitical Divsion";
		 NewAdminUnit->RadioButton3->Enabled = false;
		 }
	   }

	 vector<PARENTGEOPOL> Parents;
	 if (NewAdminUnit->ShowModal() == mrOk) {
	   try {
		   if (NewAdminUnit->RadioButton1->Checked) {
			 PARENTGEOPOL parent;
			 parent.HigherID = CountryID;
			 parent.Name = site_ptr->Country;
			 Parents.push_back(parent);
			 }
		   else if (NewAdminUnit->RadioButton2->Checked) {
			 for (int i=0; i<NewAdminUnit->cxCheckComboBox1->Properties->Items->Count; i++) {
			   if (NewAdminUnit->cxCheckComboBox1->States[i] == cbsChecked) {
				 UnicodeString StateName = NewAdminUnit->cxCheckComboBox1->Properties->Items->Items[i]->Description;
				 if (SameText(StateName, site_ptr->State)) {
				   PARENTGEOPOL parent;
				   parent.HigherID = StateID;
				   parent.Name = site_ptr->Country + L":" + site_ptr->State;
				   Parents.push_back(parent);
				   }
				 else {  // get StateID via webservice
				   GeoPolUnitByNameAndHigherID State(ipsJSONS1, TcpClient1);
				   State.AddParam(L"GEOPOLNAME", StateName);
				   State.AddParam(L"HIGHERGEOPOLID", CountryID);
				   StatusBar1->SimpleText = State.WebServiceName();
				   if (State.Execute()) {
					 if (State.Size() == 1) {
					   int ID = State.Items[0].GeoPoliticalID;
					   PARENTGEOPOL parent;
					   parent.HigherID = ID;
					   parent.Name = site_ptr->Country + L":" + StateName;
					   Parents.push_back(parent);
					   }
					 }
				   }
				 }
			   }
			 }
		   else if (NewAdminUnit->RadioButton3->Checked) {
			 for (int i=0; i<NewAdminUnit->cxCheckComboBox2->Properties->Items->Count; i++) {
			   if (NewAdminUnit->cxCheckComboBox2->States[i] == cbsChecked) {
				 UnicodeString CountyName = NewAdminUnit->cxCheckComboBox2->Properties->Items->Items[i]->Description;
				 if (SameText(CountyName, site_ptr->County)) {
				   PARENTGEOPOL parent;
				   parent.HigherID = CountyID;
				   parent.Name = site_ptr->Country + L":" + site_ptr->State + L":" + site_ptr->County;
				   Parents.push_back(parent);
				   }
				 else {  // get CountyID via webservice
				   GeoPolUnitByNameAndHigherID County(ipsJSONS1, TcpClient1);
				   County.AddParam(L"GEOPOLNAME", CountyName);
				   County.AddParam(L"HIGHERGEOPOLID", StateID);
				   StatusBar1->SimpleText = County.WebServiceName();
				   if (County.Execute()) {
					 if (County.Size() == 1) {
					   int ID = County.Items[0].GeoPoliticalID;
					   PARENTGEOPOL parent;
					   parent.HigherID = ID;
					   parent.Name = site_ptr->Country + L":" + site_ptr->State + L":" + CountyName;
					   Parents.push_back(parent);
					   }
					 }
				   }
				 }
			   }
			 }

		   UnicodeString msg;
		   if (Parents.size() == 1) {
			 msg = L"Upload Administrative Unit «" + site_ptr->AdminUnit +
				   L"» as a child of «" + Parents[0].Name + L"»?";
			 }
		   else if (Parents.size() > 1) {
			 msg = L"Upload Administrative Unit «" + site_ptr->AdminUnit +
				   L"» as a child of the following Geopolitical Units?\n";
			 for (unsigned int i=0; i<Parents.size(); i++)
			   msg += (L"\n    " + Parents[i].Name);
			 }
		   rv = MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo << mbRetry, 0);
		   if (rv == mrYes) {
			 rv = UploadGeoPoliticalUnit(site_ptr->AdminUnit, NewAdminUnit->GetGeoPoliticalUnitType(), Parents);
			 if (rv == mrOk) {
			   if (CheckAdminUnit(CountryID, StateID, CountyID, true) != mrOk) {
				 OutputError(L"ERROR: Attempt to upload Administrative Unit «" + site_ptr->AdminUnit +
				             L"» to Neotoma was apparently successful, but recheck failed.");
				 }
			   }
			 }
		   else if (rv == mrNo)
			 rv = mrCancel;
		 }
	   catch (Exception& e)
		 {
		 MessageDlg(e.Message, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 rv = mrCancel;
		 }
	   }
	 else
	   rv = mrCancel;
	 delete NewAdminUnit;
	 }
   else
	 rv = mrCancel;

   if (rv == mrCancel)
	 OutputError(L"ERROR: Administrative Unit «" + site_ptr->AdminUnit + L"» not in Neotoma.");
   return rv;
}
//---------------------------------------------------------------------------

/*  InsertGeoPoliticalUnit
	@GEOPOLNAME = N'Grand Teton National Park',   site_ptr->AdminUnit
	@GEOPOLUNIT = N'national park',               site_ptr->Country
	@RANK = 4,
	@HIGHERID = 9300
*/
int TNeotomaUploadForm::UploadGeoPoliticalUnit(UnicodeString AdminUnit,
	UnicodeString UnitType, vector<PARENTGEOPOL>& Parents)
{
   int rv = mrOk;
   vector<int> newids;
   UnicodeString ErrorMsg;

   InsertData InsertGeoPolUnit(L"InsertGeoPoliticalUnit", 4, ipsHTTPS1, ipsJSONS1, TcpClient1);
   for (unsigned int i=0; i<Parents.size(); i++) {
	 InsertGeoPolUnit.Add(L"GEOPOLNAME", AdminUnit);
	 InsertGeoPolUnit.Add(L"GEOPOLUNIT", UnitType);
	 InsertGeoPolUnit.Add(L"RANK", 4, -1);
	 InsertGeoPolUnit.Add(L"HIGHERID", Parents[i].HigherID, -1);
	 }

   InsertGeoPolUnit.PostData();
   if (InsertGeoPolUnit.Post(newids, ErrorMsg)) {
	 for (unsigned int i=0; i<newids.size(); i++) {
	   UnicodeString Line = L"New Administrative Unit uploaded to Neotoma: ID = " +
		 IntToStr(newids[i]) + L", Name = «" + AdminUnit + L"», Unit = «" +
		 UnitType + L"», Rank = 4, HigherID = " + IntToStr(Parents[i].HigherID);
	   OutputLine(Line);
	   }
	 }
   else {
	 OutputError(L"ERROR: Attempt to upload new Administrative Unit «" + AdminUnit + L"» failed.");
	 rv = mrAbort;
	 }

   return rv;
}
//---------------------------------------------------------------------------

int TNeotomaUploadForm::CheckNeotomaSite(SITE* site_ptr)
{
   int rv = mrOk;

   try {
	   NeotomaSiteForm = new TNeotomaSiteForm(this);
	   if (NeotomaSiteForm->InitializationSuccess) {
		 rv = NeotomaSiteForm->ShowModal();
		 if (rv == mrCancel) {
		   OutputError(L"ERROR: Site validation cancelled.");
		   rv = mrAbort;
		   }
		 else if (rv == mrOk) {
		   if (NeotomaSiteForm->NeotomaSiteID == -1)   // site doesn't exist
			 OutputLine(L"Site «" + site_ptr->SiteName + L"» is not in Neotoma.");
		   else {
			 UnicodeString msg = L"Site «" + site_ptr->SiteName + L"» is already in Neotoma. SiteID = " +
				 IntToStr(NeotomaSiteForm->NeotomaSiteID) + L". Add new datasets to this site?";
			 if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes) {
			   OutputLine(L"Site «" + site_ptr->SiteName + L"» is already in Neotoma. SiteID = " +
				 IntToStr(NeotomaSiteForm->NeotomaSiteID) +  L".");
			   site_ptr->NeotomaSiteID = NeotomaSiteForm->NeotomaSiteID;
			   }
			 else
			   rv = mrAbort;
			 }
		   }
		 }
	   else
		 rv = mrAbort;
	   delete NeotomaSiteForm;
	   }
   catch (Exception& e)
	   {
	   Screen->Cursor = crDefault;
	   MessageDlg(e.Message, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   PostMessage(Handle, WM_CLOSE, 0, 0);
	   }

   SetProgressBarPosition();
   return rv;
}
//---------------------------------------------------------------------------

bool TNeotomaUploadForm::ValidateCollectionUnit(SITE* site_ptr)
{
   UnicodeString msg, ErrorMsg;
   bool rv = true;
   int CollectionUnitID = -1;
   vector<NEOTOMACOLLUNIT> SiteCollUnits;

   Screen->Cursor = crHourGlass;

   try {
	 if (site_ptr->NeotomaSiteID > 0) {   // site already exists
	   NeotomaCollUnitsBySiteID NtmCollUnits(ipsJSONS1, TcpClient1);
	   NtmCollUnits.AddParam(L"SITEID", site_ptr->NeotomaSiteID);
	   StatusBar1->SimpleText = NtmCollUnits.WebServiceName();
	   if (NtmCollUnits.Execute()) {
		 if (NtmCollUnits.Size() > 0)
		   SiteCollUnits = NtmCollUnits.Items;
		 else {
		   // this should never happen, but..
		   msg = L"No collection units assigned to site «" + site_ptr->SiteName + L"».";
		   OutputError(L"ERROR: " + msg);
		   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   return (rv = false);
		   }
		 }
	   else
		 return (rv = false);

	   unsigned int start = (site_ptr->CollUnits.size() == 1) ? 0 : 1;
	   for (unsigned int i=start; i<site_ptr->CollUnits.size(); i++) {
		 NeotomaCollUnitForm = new TNeotomaCollUnitForm(site_ptr->CollUnits[i].Handle, site_ptr, SiteCollUnits, this);
		 int curv = NeotomaCollUnitForm->ShowModal();
		 if (curv == mrOk) // == continue
		   CollectionUnitID = NeotomaCollUnitForm->CollectionUnitID;
		 delete NeotomaCollUnitForm;

		 if (curv == mrOk && NeotomaCollUnitForm->CollectionUnitID != -1) {
		   if (TSSForm->Datasets[0].WhitmoreData) {
			 msg = L"Cannot upload Whitmore sample to existing collection unit.";
             MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			 return (rv = false);
			 }
		   msg = L"Collection unit «" + site_ptr->CollUnits[i].Handle +
				 L"» is already in Neotoma. CollectionUnitID = " +
				 IntToStr(NeotomaCollUnitForm->CollectionUnitID) +
				 L". Add new datasets to this collection unit?";
		   if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes) {
			 OutputLine(L"Add data to existing collection unit «" + site_ptr->CollUnits[i].Handle +
						L"». CollectionUnitID = " + IntToStr(NeotomaCollUnitForm->CollectionUnitID) + L".");
			 }
		   else
			 return (rv = false);
		   }
		 else if (curv == mrCancel)
		   return (rv = false);

		 site_ptr->CollUnits[i].NeotomaCollUnitID = CollectionUnitID;
		 COLLECTION* coll_ptr = &site_ptr->CollUnits[i];

		 if (CollectionUnitID != -1) {  // add dataset to existing collection unit
		   UpdateNeotomaCollUnitForm = new TUpdateNeotomaCollUnitForm(site_ptr, coll_ptr, true, TSSForm, this);
		   UpdateNeotomaCollUnitForm->ShowModal();
		   delete UpdateNeotomaCollUnitForm;

		   // get analysis units from spreadsheet
		   int thick_row = TSSForm->FindRowCodeIC("#Anal.Thick", TSSForm->ProfGrid1);
		   int handle_row = TSSForm->FindRowCodeIC("#Coll.Handle", TSSForm->ProfGrid1);
		   UnicodeString Handle = site_ptr->CollUnits[i].Handle;
		   int start = TSSForm->AbsHeaderColCount(TSSForm->ProfGrid1);
		   int ncols = TSSForm->AbsContentColCount(TSSForm->ProfGrid1);
		   vector<NEOTOMAANALUNIT> TiliaAnalysisUnits;

		   for (int col=start; col<=ncols; col++) {
			 if (handle_row > 0) {  // multi collection unit spreadsheet
			   UnicodeString ColHandle = TSSForm->ProfGrid1->AbsoluteCells[col][handle_row]->Text;
			   if (!SameText(ColHandle,Handle))
				 continue;
			   }
			 NEOTOMAANALUNIT AnalUnit;
			 if (!GetAnalUnitDepth(col, AnalUnit.Depth))
			   return false;
			 AnalUnit.AnalysisUnitName = TSSForm->ProfGrid1->AbsoluteCells[col][2]->Text;
			 if (thick_row > 0) {
			   if (!TSSForm->ProfGrid1->AbsoluteCells[col][thick_row]->IsEmpty()) {
				 if (!GetAnalUnitThickness(col, thick_row, AnalUnit.Thickness))
				   return false;
				 }
			   }
			 AnalUnit.CollectionUnitID = CollectionUnitID;
			 TiliaAnalysisUnits.push_back(AnalUnit);
			 }

		   // get analysis units from geochronology
		   for (int j=0; j<TSSForm->GeochronList->Count(); j++) {
			 GEOCHRON& Date = TSSForm->GeochronList->Dates[j];
			 bool found = false;
			 for (unsigned int k=0; k < TiliaAnalysisUnits.size(); k++) {
			   if (SameAnalysisUnit(Date.Depth, Date.Thickness, Date.AnalUnit,
				   TiliaAnalysisUnits[k].Depth, TiliaAnalysisUnits[k].Thickness,
				   TiliaAnalysisUnits[k].AnalysisUnitName)) {
				 found = true;
				 break;
				 }
			   }
			 if (!found) {
			   NEOTOMAANALUNIT AnalUnit;
			   AnalUnit.Depth = Date.Depth;
			   AnalUnit.Thickness = Date.Thickness;
			   AnalUnit.AnalysisUnitName = Date.AnalUnit;
			   AnalUnit.CollectionUnitID = CollectionUnitID;
			   TiliaAnalysisUnits.push_back(AnalUnit);
			   }
			 }

		   // get analysis units for collecion unit from Neotoma
		   vector<NTMANALYSISUNIT> AnalUnitsFromNeotoma;
		   NeotomaGetAnalUnitsByCollUnitID AnalUnits(ipsJSONS1, TcpClient1);
		   AnalUnits.AddParam(L"COLLUNITID", CollectionUnitID);
		   StatusBar1->SimpleText = AnalUnits.WebServiceName();
		   if (AnalUnits.Execute()) {
			 if (AnalUnits.Size() > 0)
			   AnalUnitsFromNeotoma = AnalUnits.Items;
			 }
		   else
			 return (rv = false);

		   AnalUnitMatchForm = new TAnalUnitMatchForm(&TiliaAnalysisUnits,
								   &AnalUnitsFromNeotoma, TSSForm->EPD.SiteID, this);
		   int aurv = AnalUnitMatchForm->ShowModal();
		   ReplaceEPDDataset = AnalUnitMatchForm->ReplaceEPDDataset;
		   delete AnalUnitMatchForm;
		   if (aurv == mrCancel)
			 return (rv = false);

		   NeotomaAnalysisUnits.insert(NeotomaAnalysisUnits.end(), TiliaAnalysisUnits.begin(), TiliaAnalysisUnits.end());
		   }
		 else {  // validate new collection unit site_ptr->CollUnits[i]
		   if (ValidateCollUnitMetaData(site_ptr, coll_ptr)) {
			 msg = L"Collection unit «" + coll_ptr->Handle + L"» validated for site «" +
				   site_ptr->SiteName + L"».";
			 OutputLine(msg);
			 }
		   else
			 return (rv = false);
		   }
		 }
	   }
	 else {  // !AddToExistingCollUnit
	   unsigned int start = (site_ptr->CollUnits.size() == 1) ? 0 : 1;
	   for (unsigned int i=start; i<site_ptr->CollUnits.size(); i++) {
		 coll_ptr = &site_ptr->CollUnits[i];
		 coll_ptr->NeotomaCollUnitID = NextTempCollUnitID();
		 if (ValidateCollUnitMetaData(site_ptr, coll_ptr)) {
		   msg = L"Collection unit «" + coll_ptr->Handle + L"» validated for site «" +
				 site_ptr->SiteName + L"».";
		   OutputLine(msg);
		   }
		 else
		   return (rv = false);
		 }
	   }
	 }
   __finally {
	 SetProgressBarPosition();
	 StatusBar1->SimpleText = L"";
	 Screen->Cursor = crDefault;
	 }
   return rv;
}
//---------------------------------------------------------------------------

bool TNeotomaUploadForm::SameAnalysisUnit(Variant Depth1, Variant Thick1, UnicodeString Name1,
		Variant Depth2, Variant Thick2, UnicodeString Name2)
{
   if (!Depth1.IsEmpty() && !Thick1.IsEmpty() && !Name1.IsEmpty() &&
	   !Depth2.IsEmpty() && !Thick2.IsEmpty() && !Name2.IsEmpty() &&
	   Depth1 == Depth2 && Thick1 == Thick2 && Name1 == Name2)
		  return true;
   else if (!Depth1.IsEmpty() && !Thick1.IsEmpty() && Name1.IsEmpty() &&
			!Depth2.IsEmpty() && !Thick2.IsEmpty() && Name2.IsEmpty() &&
			 Depth1 == Depth2 && Thick1 == Thick2)
		  return true;
   else if (!Depth1.IsEmpty() && Thick1.IsEmpty() && !Name1.IsEmpty() &&
			!Depth2.IsEmpty() && Thick2.IsEmpty() && !Name2.IsEmpty() &&
			Depth1 == Depth2 && Name1 == Name2)
		  return true;
   else if (!Depth1.IsEmpty() && Thick1.IsEmpty() && Name1.IsEmpty() &&
			!Depth2.IsEmpty() && Thick2.IsEmpty() && Name2.IsEmpty() &&
			Depth1 == Depth2)
		  return true;
   else if (Depth1.IsEmpty() && !Name1.IsEmpty() &&
			Depth2.IsEmpty() && !Name2.IsEmpty() &&
			Name1 == Name2)
		  return true;
   return false;
}
//---------------------------------------------------------------------------

bool TNeotomaUploadForm::ValidateCollUnitMetaData(SITE* site_ptr, COLLECTION* coll_ptr)
{
   UnicodeString msg;

   // validate Handle
   if (!ValidateHandle(coll_ptr))
	 return false;
   UnicodeString Handle = coll_ptr->Handle;
   // validate collection unit type
   if (!ValidateCollUnitType(coll_ptr))
	 return false;
   // Collection unit name
   ValidateCollUnitName(coll_ptr);

   // validate collection date
   if (!coll_ptr->CollDate.IsEmpty()) {
	 if (coll_ptr->CollDate.Type() != varDate) {
	   msg = L"Collection date «" + VarToStr(coll_ptr->CollDate) +
		 L"» is not valid.";
	   OutputError(L"ERROR: " + msg);
	   if (MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbIgnore << mbAbort, 0) == mrAbort) {
		 Screen->Cursor = crDefault;
		 return false;
		 }
	   }
	 else {
	   unsigned short year, month, day, thisyear;
	   TDateTime Date = VarToDateTime(coll_ptr->CollDate);
	   Date.DecodeDate(&year, &month, &day);
	   TDateTime today = Today();
	   today.DecodeDate(&thisyear, &month, &day);

	   if (year < 1000) {
		 msg = L"Collection date year «" + VarToStr(coll_ptr->CollDate) + L"» is not valid.";
		 OutputError(L"ERROR: " + msg);
		 if (MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbIgnore << mbAbort, 0) == mrAbort) {
		   Screen->Cursor = crDefault;
		   return false;
		   }
		 }
	   else if (year < 1800) {
		 msg = L"Collection date year «" + VarToStr(coll_ptr->CollDate) + L"» is <1800.";
		 OutputWarning(L"WARNING: " + msg);
		 MessageDlg(msg, mtWarning, TMsgDlgButtons() << mbOK, 0);
		 }
	   else if (year > thisyear) {
		 msg = L"Collection date year «" + VarToStr(coll_ptr->CollDate) + L"» is in the future.";
		 OutputError(L"ERROR: " + msg);
		 if (MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbIgnore << mbAbort, 0) == mrAbort) {
		   Screen->Cursor = crDefault;
		   return false;
		   }
		 }
	   }
	 }

   // lat-long validation
   if (!ValidateCollUnitGPS(coll_ptr, site_ptr))
	 return false;
   // depositional environments
   int rv;
   do {
	  rv = ValidateCollUnitDepEnvt(coll_ptr, site_ptr);
	  } while (rv == mrRetry);
   if (rv == mrAbort)
	 return false;
   // substrate
   if (!ValidateCollUnitSubstrate(coll_ptr))
	 return false;
   ValidateCollectors(coll_ptr);
   return true;
}
//---------------------------------------------------------------------------

bool TNeotomaUploadForm::ValidateHandle(COLLECTION* coll_ptr)
{
   UnicodeString msg, ErrorMsg;

   if (SameText(coll_ptr->Handle, coll_ptr->NeotomaHandle))
	 return true;

   if (coll_ptr->Handle.IsEmpty())
	 ErrorMsg = L" Collection Unit Handle not entered.";
   else if (coll_ptr->Handle.Length() > 10) {
	 ErrorMsg = L" Collection Unit Handle «" + coll_ptr->Handle + L"» is longer than 10 characters. ";
	 ErrorMsg += L"Handles are normally 8 characters or less, with a maximum of 10 allowed.";
	 }
   else if (coll_ptr->Handle.Length() > 8) {
	 msg = L"WARNING: Collection Unit Handle «" + coll_ptr->Handle + L"» is longer than 8 characters. ";
	 msg += L"Handles are normally 8 characters or less, with a maximum of 10 allowed.";
	 OutputWarning(msg);
	 }

   if (ErrorMsg.IsEmpty()) {  // check for invalid characters
	 bool error = false;
	 for (int i=1; i<=coll_ptr->Handle.Length(); i++) {
	   switch (coll_ptr->Handle[i]) {
		 case L'<':
		 case L'>':
		 case L':':
		 case L'\"':
		 case L'/':
		 case L'\\':
		 case L'|':
		 case L'?':
		 case L'*':
		   error = true;
		   break;
		 }
	   if (error)
		 break;
	   }
	 if (error) {
	   ErrorMsg = L"Invalid character in the Collection Unit Handle «" + coll_ptr->Handle +
		 L"». Invalid characters are: <>:\"/\\|?*";
	   }
	 }

   if (!ErrorMsg.IsEmpty()) {
	 OutputError(L"ERROR: " + ErrorMsg);
	 if (MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbIgnore << mbAbort, 0) == mrAbort) {
	   Screen->Cursor = crDefault;
	   return false;
	   }
	 }
   else {
	 UnicodeString ucHandle = coll_ptr->Handle.UpperCase();
	 if (coll_ptr->Handle != ucHandle) {
	   msg = L"NOTE: Collection Unit Handle «" + coll_ptr->Handle + "» changed to uppercase.";
	   OutputNote(msg);
	   coll_ptr->Handle = ucHandle;
	   }
	 OutputLine(L"Collection Unit Handle: «" + coll_ptr->Handle + L"».");
	 }

   UnicodeString Handle = coll_ptr->Handle;
   NeotomaCollUnitHandleCount HandleCount(ipsJSONS1, TcpClient1);
   HandleCount.AddParam(L"HANDLE", Handle);
   StatusBar1->SimpleText = HandleCount.WebServiceName();
   if (HandleCount.Execute()) {
	 if (HandleCount.Size() == 1) {
	   if (HandleCount.Items[0] > 0) {
		 ErrorMsg = L"Collection Unit Handle «" + Handle + L"» already exists in Neotoma. Handles must be unique.";
		 OutputError(L"ERROR: " + ErrorMsg);
		 if (MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbIgnore << mbAbort, 0) == mrAbort) {
		   Screen->Cursor = crDefault;
		   return false;
		   }
		 }
	   }
	 else {
	   msg = L"Error accessing Neotoma CollectionUnits table.";
	   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   Screen->Cursor = crDefault;
	   return false;
	   }
	 }
   else {
	 Screen->Cursor = crDefault;
	 return false;
	 }
   return true;
}
//---------------------------------------------------------------------------

bool TNeotomaUploadForm::ValidateCollUnitType(COLLECTION* coll_ptr)
{
   UnicodeString ErrorMsg;

   if (coll_ptr->CollectionType.IsEmpty()) {
	 ErrorMsg = L"Collection Unit Type for «" + coll_ptr->Handle + L"»  not entered.";
	 OutputError(L"ERROR: " + ErrorMsg);
	 if (MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbIgnore << mbAbort, 0) == mrAbort) {
	   Screen->Cursor = crDefault;
	   return false;
	   }
	 }

   NeotomaCollectionTypesTable CollectionTypes(ipsJSONS1, TcpClient1);
   StatusBar1->SimpleText = CollectionTypes.WebServiceName();
   if (CollectionTypes.Execute()) {
	 map<int, UnicodeString>::iterator begin = CollectionTypes.Items.begin();
	 map<int, UnicodeString>::iterator end = CollectionTypes.Items.end();
	 map<int, UnicodeString>::iterator itr;
	 bool found = false;
	 for (itr=begin; itr != end; itr++) {
	   if (SameText(itr->second, coll_ptr->CollectionType)) {
		 coll_ptr->NeotomaCollTypeID = itr->first;
		 found = true;
		 break;
		 }
	   }
	 if (found)
	   OutputLine(L"Collection Unit type: «" + coll_ptr->CollectionType + L"»: CollTypeID = " +
				  IntToStr(coll_ptr->NeotomaCollTypeID) + L".");
	 else {
	   ErrorMsg = L"Collection Unit type «" + coll_ptr->CollectionType +
				  L"» not currently in the Neotoma CollectionTypes table.";
	   OutputError(L"ERROR: " + ErrorMsg);
	   if (MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbIgnore << mbAbort, 0) == mrAbort) {
		 Screen->Cursor = crDefault;
		 return false;
		 }
	   }
	 }
   else {
	 Screen->Cursor = crDefault;
	 return false;
	 }
   return true;
}
//---------------------------------------------------------------------------

void TNeotomaUploadForm::ValidateCollUnitName(COLLECTION* coll_ptr)
{
   if (coll_ptr->CollectionName.IsEmpty()) {
	 bool vf = false;
	 for (unsigned int i=0; i<TSSForm->Datasets.size(); i++) {
	   if (SameText(TSSForm->Datasets[i].DatasetType, L"vertebrate fauna")) {
		 vf = true;
		 break;
		 }
	   }
	 if (vf)
	   OutputWarning(L"WARNING: Collection Unit Name not entered.");
	 else
	   OutputNote(L"NOTE: Collection Unit Name not entered.");
	 }
   else
	 OutputLine(L"Collection Unit Name: «" + coll_ptr->CollectionName + L"».");
}
//---------------------------------------------------------------------------

bool TNeotomaUploadForm::ValidateCollUnitGPS(COLLECTION* coll_ptr, SITE* site_ptr)
{
   UnicodeString ErrorMsg, ErrorMsg2;

   UnicodeString Handle = coll_ptr->Handle;

   if (coll_ptr->GPSLat.IsEmpty() && !coll_ptr->GPSLong.IsEmpty())
	 ErrorMsg = L"Collection Unit «" + Handle + L"» GPS longitude entered but not GPS Latitude.";
   else if (!coll_ptr->GPSLat.IsEmpty() && coll_ptr->GPSLong.IsEmpty())
	 ErrorMsg = L"Collection Unit «" + Handle + L"» GPS latitude entered but not GPS Longitude.";
   else if (!coll_ptr->GPSLat.IsEmpty() && !coll_ptr->GPSLong.IsEmpty()) {
	 if (coll_ptr->GPSLat > site_ptr->LatNorth)
	   ErrorMsg = L"Collection Unit «" + Handle + L"» GPS latitude is north of Site latitude bounding.";
	 else if (coll_ptr->GPSLat < site_ptr->LatSouth)
	   ErrorMsg = L"Collection Unit «" + Handle + L"» GPS latitude is south of Site latitude bounding.";
	 if (coll_ptr->GPSLong > site_ptr->LongEast)
	   ErrorMsg2 = L"Collection Unit «" + Handle + L"» GPS longitude is east of Site longitude bounding.";
	 else if (coll_ptr->GPSLong < site_ptr->LongWest)
	   ErrorMsg2 = L"Collection Unit «" + Handle + L"» GPS longitude is west of Site longitude bounding.";
	 }
   if (!ErrorMsg.IsEmpty())
	 OutputError(L"ERROR: " + ErrorMsg);
   if (!ErrorMsg2.IsEmpty())
	 OutputError(L"ERROR: " + ErrorMsg2);
   if (!ErrorMsg.IsEmpty() || !ErrorMsg2.IsEmpty()) {
	 ErrorMsg = L"Errors in Collection Unit «" + Handle + L"» GPS coordinates.";
	 if (MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbIgnore << mbAbort, 0) == mrAbort) {
	   Screen->Cursor = crDefault;
	   return false;
	   }
	 }
   else if (!coll_ptr->GPSLat.IsEmpty() && !coll_ptr->GPSLong.IsEmpty()) {
	 OutputLine(L"Collection Unit GPS latitude: " + FloatToStr((double)coll_ptr->GPSLat) + L".");
	 OutputLine(L"Collection Unit GPS longitude: " + FloatToStr((double)coll_ptr->GPSLong) + L".");
	 }
   return true;
}
//---------------------------------------------------------------------------

bool TNeotomaUploadForm::ValidateCollUnitSubstrate(COLLECTION* coll_ptr)
{
   UnicodeString ErrorMsg;

   if (!coll_ptr->Substrate.IsEmpty()) {
	 NeotomaRockTypeByName RockType(ipsJSONS1, TcpClient1);
	 RockType.AddParam(L"ROCKTYPE", coll_ptr->Substrate);
	 StatusBar1->SimpleText = RockType.WebServiceName();
	 if (RockType.Execute()) {
	   if (RockType.Size() == 1) {
		 coll_ptr->NeotomaRockTypeID = RockType.Items[0].RockTypeID;
		 OutputLine(L"Substrate «" + coll_ptr->Substrate + L"» vallidated: RockTypeID = " +
		   IntToStr(RockType.Items[0].RockTypeID) + L".");
		 }
	   else {
		 ErrorMsg = L"Substrate «" + coll_ptr->Substrate + L"» not in the Neotoma RockTypes table.";
		 OutputError(L"ERROR: " + ErrorMsg);
		 if (MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbIgnore << mbAbort, 0) == mrAbort) {
		   Screen->Cursor = crDefault;
		   return false;
		   }
		 }
	   }
	 else {
	   Screen->Cursor = crDefault;
	   return false;
	   }
	 }
   return true;
}
//---------------------------------------------------------------------------

void TNeotomaUploadForm::ValidateCollectors(COLLECTION* coll_ptr)
{
   UnicodeString msg;

   vector<CONTACT*>::iterator itr;
   if (coll_ptr->Collectors.size() == 0)
	 OutputNote(L"NOTE: No Collectors entered.");
   else {
	 if (coll_ptr->Collectors.size() == 1)
	   msg = L"Collector: ";
	 else
	   msg = L"Collectors: ";
	 for (unsigned int i=0; i<coll_ptr->Collectors.size(); i++) {
	   if (i > 0) msg += L"; ";
	   msg += coll_ptr->Collectors[i]->ShortContactName;
	   msg += (L", ID = " + IntToStr(coll_ptr->Collectors[i]->NeotomaContactID) + L".");
	   }
	 OutputLine(msg);
	 }
}
//---------------------------------------------------------------------------

int TNeotomaUploadForm::ValidateCollUnitDepEnvt(COLLECTION* coll_ptr, SITE* site_ptr)
{
   vector<void*> vptrs;
   UnicodeString Line;
   int rv = mrOk;

   if (coll_ptr->DepEnv.IsEmpty()) {
	 Line = L"Depositional Environment for Collection Unit not designated. Designate as «Unknown»?";
	 Line += L"\nIf Depositional Environment is known, click «No», and designate under Collection Unit metadata.";
	 if (MessageDlg(Line, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes) {
	   coll_ptr->DepEnv = L"Unknown";
	   if (TSSForm->Sites->Count == 1 && site_ptr->CollUnits.size() == 1) {
		 TSSForm->CollPtr = coll_ptr;
		 TSSForm->FillCollUnitMetaData();
		 }
	   OutputLine(L"Depositional Environment changed to «Unknown»");
	   }
	 else
	   OutputError(L"ERROR: Depositional Environment not designated.");
	 SetProgressBarPosition();
	 return true;
	 }

   try {
   try {
	 Screen->Cursor = crHourGlass;
	 DepEnvtTypes = new NeotomaDepEnvtTypesTable(ipsJSONS1, TcpClient1);
	 StatusBar1->SimpleText = DepEnvtTypes->WebServiceName();
	 if (DepEnvtTypes->Execute()) {
	   StatusBar1->SimpleText = L"";
	   if (DepEnvtTypes->Find("DepEnvt", coll_ptr->DepEnv, vptrs) == 1) {
		 DEPENVTRECORD* DepEnvtRec = (DEPENVTRECORD*)vptrs[0];
		 coll_ptr->NeotomaDepEnvtID = DepEnvtRec->DepEnvtID;
		 OutputLine(L"Depositional Environment «" +
		   coll_ptr->DepEnv +L"» validated: DepEnvtID = " +
		   IntToStr(coll_ptr->NeotomaDepEnvtID) + L".");
		 }
	   else {  // Depositional Environment not found
		 NewDepEnvtForm = new TNewDepEnvtForm(this);
		 NewDepEnvtForm->ShowModal();
		 bool Uploaded = NewDepEnvtForm->Uploaded;
		 delete NewDepEnvtForm;
		 if (Uploaded)
		   rv = mrRetry;
		 else {
		   UnicodeString msg = L"New Depositional Environment not uploaded.";
		   rv = MessageDlg(msg, mtWarning, TMsgDlgButtons() << mbRetry << mbAbort, 0);
		   }
		 }
	   }
	 else {
	   Screen->Cursor = crDefault;
	   rv = mrAbort;
	   }
	 }
   catch (Exception& e)
	 {
	 Screen->Cursor = crDefault;
	 MessageDlg(e.Message, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 rv = mrAbort;
	 }
	 }
   __finally {
	 delete DepEnvtTypes;
	 Screen->Cursor = crDefault;
	 StatusBar1->SimpleText = L"";
	 }
   SetProgressBarPosition();
   return rv;
}
//---------------------------------------------------------------------------

bool TNeotomaUploadForm::ValidateLithology(void)
{
   UnicodeString msg;

   if (TilSpreadSheetForm->LithologyUnitList == NULL) {
     OutputLine(L"No lithology data entered.");
	 SetProgressBarPosition();
	 return true;
	 }

   if (TilSpreadSheetForm->LithologyUnitList->Count == 0) {
	 OutputLine(L"No lithology data entered.");
	 SetProgressBarPosition();
	 return true;
	 }

   if (TSSForm->Sites->Count > 1) {
	 msg = L"Lithology data cannot be uploaded for multisite datasets.";
	 OutputWarning(L"WARNING: " + msg);
	 MessageDlg(msg, mtWarning, TMsgDlgButtons() << mbOK, 0);
	 SetProgressBarPosition();
	 return true;
	 }

   if (site_ptr->CollUnits.size() > 1) {
	 msg = L"Lithology data cannot be uploaded for multi Collection Unit datasets.";
	 OutputWarning(L"WARNING: " + msg);
	 MessageDlg(msg, mtWarning, TMsgDlgButtons() << mbOK, 0);
	 SetProgressBarPosition();
	 return true;
	 }

   coll_ptr = &site_ptr->CollUnits[0];  // this was commented out for some reason

   int nerrors = 0;
   for (int i=0; i<TSSForm->LithologyUnitList->Count; i++) {
	 bool error = false;
	 LITHOLOGYUNIT* LithUnit = (LITHOLOGYUNIT*)TSSForm->LithologyUnitList->LithologyUnits[i];
	 if (IsNan(LithUnit->DepthTop)) {
	   OutputError(L"ERROR: Top depth not entered for Lithology Unit.");
	   error = true;
	   }
	 if (IsNan(LithUnit->DepthBottom)) {
	   OutputError(L"ERROR: Bottom depth not entered for Lithology Unit.");
	   error = true;
	   }
	 if (!error) {
	   if (LithUnit->DepthTop > LithUnit->DepthBottom) {
		 OutputError(L"ERROR: Lithology top depth " + FloatToStr(LithUnit->DepthTop) +
		   L" is greater than bottom depth " + FloatToStr(LithUnit->DepthBottom) + L".");
		 error = true;
		 }
	   }
	 if (LithUnit->UnitDescription.IsEmpty()) {
	   msg = L"ERROR: Description missing for Lithology Unit";
	   if (error)
		 msg += L": Top depth = " + FloatToStr(LithUnit->DepthTop) +
		   L", Bottom depth = " + FloatToStr(LithUnit->DepthBottom);
	   msg += L".";
	   OutputError(msg);
	   error = true;
	   }
	 if (error) nerrors++;

	 if (nerrors == 0) {
	   NEOTOMALITHUNIT NeotomaLithUnit;
	   NeotomaLithUnit.CollUnitID = coll_ptr->NeotomaCollUnitID;
	   NeotomaLithUnit.DepthTop = LithUnit->DepthTop;
	   NeotomaLithUnit.DepthBottom = LithUnit->DepthBottom;
	   NeotomaLithUnit.UnitDescription = LithUnit->UnitDescription;
	   NeotomaLithUnit.LowerBoundary = LithUnit->LowerBoundary;
	   NeotomaLithUnits.push_back(NeotomaLithUnit);
	   }
	 }
   if (nerrors > 0)
	 NeotomaLithUnits.clear();

   SetProgressBarPosition();
   return true;
}
//---------------------------------------------------------------------------

void TNeotomaUploadForm::InvalidSSNumber(int col, int row, UnicodeString Item, UnicodeString& msg)
{
   msg = L"Invalid value «" + TSSForm->ProfGrid1->AbsoluteCells[col][row]->Text +
		 L"» in cell " + TSSForm->ProfGrid1->AbsoluteCells[col][row]->A1Name;
   if (!Item.IsEmpty())
	 msg += (L" " + Item);
   msg += L". Value must be a number.";
}
//---------------------------------------------------------------------------


