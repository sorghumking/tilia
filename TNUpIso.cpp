//---------------------------------------------------------------------------

#include <vcl.h>
#include "pch.h"
#pragma hdrstop

#include "TNUpIso.h"
#ifndef TIUploadH
#include "TIUpload.h"
#endif

//---------------------------------------------------------------------------

#pragma package(smart_init)

bool TNeotomaUploadForm::UploadSpecimenDates(int CollUnitID)
{
   vector<int> newids;
   UnicodeString msg, ErrorMsg;

   if (NeotomaTaxaDated.size() == 0)
	 return true;

   // get vector of NeotomaTaxaDated assigned to CollUnitID
   int TempCollUnitID = FindTempNeotomaCollUnitID(CollUnitID);
   vector<unsigned int> idx;
   for (unsigned int i=0; i<NeotomaTaxaDated.size(); i++) {
	 for (unsigned int j=0; j<NeotomaGeochrons.size(); j++) {
	   if (NeotomaTaxaDated[i].GeochronID == NeotomaGeochrons[j].GeochronID) {
		 if (TempCollUnitID == FindCollUnitID(NeotomaGeochrons[j].AnalysisUnitID)) {
		   idx.push_back(i);
		   break;
		   }
		 }
	   }
	 }
   if (idx.size() == 0)
	 return true;

   unsigned int nrecs = 0;
   InsertData InsertSpecimenDate(L"InsertSpecimenDate", 7, ipsHTTPS1, ipsJSONS1, TcpClient1);
   for (unsigned int j=0; j<idx.size(); j++) {
	 int i = idx[j];
	 InsertSpecimenDate.Add(L"GEOCHRONID", NeotomaGeochronIDs[NeotomaTaxaDated[i].GeochronID], -1);
	 InsertSpecimenDate.Add(L"SPECIMENID", NeotomaTaxaDated[i].NeotomaSpecimenID, -1);
	 InsertSpecimenDate.Add(L"TAXONID", NeotomaTaxaDated[i].NeotomaTaxonID, -1);
	 InsertSpecimenDate.Add(L"ELEMENTTYPEID", NeotomaTaxaDated[i].NeotomaElementTypeID, -1);
	 InsertSpecimenDate.Add(L"FRACTIONID", NeotomaTaxaDated[i].NeotomaFractionID, -1);
	 InsertSpecimenDate.Add(L"SAMPLEID", NeotomaSampleIDs[NeotomaTaxaDated[i].SampleID], -1);
	 InsertSpecimenDate.Add(L"NOTES", NeotomaTaxaDated[i].Notes);
	 nrecs++;
	 }

   StatusBar1->SimpleText = L"InsertSpecimenDate";
   InsertSpecimenDate.PostData();
   if (InsertSpecimenDate.Post(newids, ErrorMsg)) {
	 if (newids.size() == nrecs) {
	   msg = L"Specimen date";
       if (newids.size() > 1)
		 msg += L"s";
	   msg += L" uploaded to SpecimenDates table: SpecimenDateID";
	   if (newids.size() == 1)
		 msg += (L" = " + IntToStr(newids[0]) + L".");
	   else
		 msg += (L"s = " + IntToStr(newids[0]) + L".." + IntToStr(newids.back()) + L".");
	   OutputLine(msg);
	   }
	 else {
	   ErrorMsg = L"Error inserting into SpecimenDates table!";
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

   /*
   @SPECIMENDATEID int,
   @CALAGE float = null,
   @CALAGEOLDER float = null,
   @CALAGEYOUNGER float = null,
   @CALIBRATIONCURVEID int = null,
   @CALIBRATIONPROGRAMID int = null,
   @DATECALIBRATED date = null
   */

   unsigned int cal_ages = 0;
   InsertData InsertSpecimenDateCal(L"InsertSpecimenDateCal", 7, ipsHTTPS1, ipsJSONS1, TcpClient1);
   for (unsigned int j=0; j<idx.size(); j++) {
	 int i = idx[j];
	 if (!NeotomaTaxaDated[i].Cal.Age.IsEmpty() || !NeotomaTaxaDated[i].Cal.AgeOlder.IsEmpty()) {
	   InsertSpecimenDateCal.Add(L"SPECIMENDATEID", newids[j], -1);
	   InsertSpecimenDateCal.AddDouble(L"CALAGE", NeotomaTaxaDated[i].Cal.Age);
	   InsertSpecimenDateCal.AddDouble(L"CALAGEOLDER", NeotomaTaxaDated[i].Cal.AgeOlder);
	   InsertSpecimenDateCal.AddDouble(L"CALAGEYOUNGER", NeotomaTaxaDated[i].Cal.AgeYounger);
	   InsertSpecimenDateCal.Add(L"CALIBRATIONCURVEID", NeotomaTaxaDated[i].Cal.CurveID, -1);
	   InsertSpecimenDateCal.Add(L"CALIBRATIONPROGRAMID", NeotomaTaxaDated[i].Cal.ProgramID, -1);
	   InsertSpecimenDateCal.Add(L"DATECALIBRATED", DateStr(NeotomaTaxaDated[i].Cal.Date));
	   cal_ages++;
	   }
	 }
   if (cal_ages > 0) {
	 newids.clear();
	 StatusBar1->SimpleText = L"InsertSpecimenDateCal";
	 InsertSpecimenDateCal.PostData();
	 if (InsertSpecimenDateCal.Post(newids, ErrorMsg)) {
	   if (newids.size() == cal_ages) {
		 msg = L"Calibrated specimen date";
		 if (newids.size() > 1)
		   msg += L"s";
		 msg += L" uploaded to SpecimenDatesCal table: SpecimenDateCalID";
		 if (newids.size() == 1)
		   msg += (L" = " + IntToStr(newids[0]) + L".");
		 else
		   msg += (L"s = " + IntToStr(newids[0]) + L".." + IntToStr(newids.back()) + L".");
		 OutputLine(msg);
		 }
	   else {
		 ErrorMsg = L"Error inserting into SpecimenDatesCal table!";
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

   StatusBar1->SimpleText = L"";
   return true;
}
//---------------------------------------------------------------------------

bool TNeotomaUploadForm::UploadSpecimenIsotopes(int CollUnitID,
	vector<NEOTOMADATASET>& NeotomaDatasets)
{
   vector<int> newids;
   UnicodeString msg, ErrorMsg;
   map<int,SPECIMEN*> SpecimenSampleIDs;  // NeotomaSampleID, specimen pointer
   int IsoDatasetID = -1;

   if (IsoVarID.IsEmpty())
	 return true;

   // map<int,int> NeotomaDatasetIDs;    // TempDatasetID, NeotomaDatasetID

   // find DatasetID for the specimen stable isotope dataset
   for (unsigned int i = 0; i < NeotomaDatasets.size(); i++) {
	 if (NeotomaDatasets[i].NeotomaDatasetTypeID == 24) {
	   IsoDatasetID = NeotomaDatasetIDs[NeotomaDatasets[i].DatasetID];
	   break;
	   }
	 }
   if (IsoDatasetID == -1) {   // this should never happen, but...
	 ErrorMsg = L"ERROR: Specimen stable isotope dataset not uploaded.";
	 OutputError(ErrorMsg);
	 return false;
	 }

   // upload isotope samples

   //vector<int> NewTempSampleIDs;  // vector of temp SampleIDs for this Dataset, e.g. -1001,-1002,...
   InsertData InsertSample(L"InsertSample", 9, ipsHTTPS1, ipsJSONS1, TcpClient1);
   // int NeotomaDatasetID = NeotomaDatasetIDs[TempDatasetID];
   NEOTOMASAMPLE NeotomaSample;

   // if (NeotomaSamples[j].DatasetID == TempDatasetID) {
   unsigned int nspec = 0;
   map<int,SPECIMEN*> SpecimenSamples;  // ordinal position, specimen pointer
   for (set<int>::iterator itr = IsoDataRows.begin(); itr != IsoDataRows.end(); itr++) {
	 SPECIMEN* Specimen = SpecimenRowObj[*itr];

	 //int NeotomaAnalUnitID = NeotomaAnalUnitIDs[NeotomaSamples[j].AnalysisUnitID];

	 InsertSample.Add(L"ANALYSISUNITID", Specimen->NeotomaAnalysisUnitID);
	 InsertSample.Add(L"DATASETID", IsoDatasetID);
	 InsertSample.Add(L"SAMPLENAME", NeotomaSample.SampleName);
	 InsertSample.Add(L"SAMPLEDATE", DateStr(NeotomaSample.DateSampled));
	 InsertSample.Add(L"ANALYSISDATE", DateStr(NeotomaSample.DateAnalyzed));
     InsertSample.Add(L"TAXONID", NeotomaSample.TaxonID, -1);
	 InsertSample.Add(L"LABNUMBER", NeotomaSample.LabNumber);
	 InsertSample.Add(L"PREPMETHOD", NeotomaSample.PrepMethod);
	 InsertSample.Add(L"NOTES", NeotomaSample.Notes);
	 //NewTempSampleIDs.push_back(NeotomaSamples.SampleID);   // ??
	 //TempSampleIDs.push_back(NeotomaSample.SampleID);
	 SpecimenSamples[nspec++] = Specimen;
	 }
   newids.clear();
   StatusBar1->SimpleText = L"InsertSample";
   InsertSample.PostData();
   if (InsertSample.Post(newids, ErrorMsg)) {
	 if (newids.size() == nspec) {
	   for (unsigned int i=0; i<nspec; i++)
		 SpecimenSampleIDs[newids[i]] = SpecimenSamples[i];

	   // msg = L"DatasetID " + IntToStr(NeotomaDatasetID) + L": " +
	   msg = L"DatasetID " + IntToStr(IsoDatasetID) + L": " +
			 IntToStr((int)newids.size()) + L" sample";
	   if (newids.size() != 1)
		 msg += L"s";
	   msg += L" uploaded to Samples table: SampleID";
	   if (newids.size() == 1)
		 msg += (L" = " + IntToStr(newids[0]) + L".");
	   else
		 msg += (L"s = " + IntToStr(newids[0]) + L".." + IntToStr(newids.back()) + L".");
	   OutputLine(msg);
	   //for (unsigned int j=0; j<newids.size(); j++) {
	   //	 NeotomaSampleIDs[NewTempSampleIDs[j]] = newids[j];  // e.g. NeotomaSampleIDs[-1001] = 167771
	   //}
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


   // upload isotope sample ages

   // IsoChronologyID = 0;
   // map<int,NEOTOMAAGE> IsoSpecimenAges;   // LocalSpecimenID, NEOTOMAAGE
   /*
   InsertSampleAge
   @SAMPLEID int,
   @CHRONOLOGYID int,
   @AGE float = null,
   @AGEYOUNGER float = null,
   @AGEOLDER float = null
   */
   // map<int,int> NeotomaChronIDs;      // TempChronID, NeotomaChronID

   // int TempChronID = NeotomaChrons[i].ChronologyID;
   // int ChronNo = TiliaChronIDs[TempChronID];
   // NeotomaChronIDs[TempChronID] = NeotomaChronID;

   map<int,SPECIMEN*>::iterator itr;

   if (NeotomaChronIDs.count(IsoChronologyID) == 1) {
	 if (IsoSpecimenAges.size() > 0) {
       newids.clear();
	   unsigned int ns = 0;
	   InsertData InsertSampleAge(L"InsertSampleAge", 5, ipsHTTPS1, ipsJSONS1, TcpClient1);
	   int NeotomaChronologyID = NeotomaChronIDs[IsoChronologyID];
	   map<int,NEOTOMAAGE>::iterator it;
	   for (it = IsoSpecimenAges.begin(); it != IsoSpecimenAges.end(); it++) {
		 int SpecimenID = it->first;
		 // find SampleID for isotope data
		 int NeotomaIsoSampleID = -1;
		 for (itr = SpecimenSampleIDs.begin(); itr != SpecimenSampleIDs.end(); itr++) {
		   if (SpecimenID == itr->second->SpecimenID) {
			 NeotomaIsoSampleID = itr->first;
			 break;
			 }
		   }
		 if (NeotomaIsoSampleID != -1) {
		   InsertSampleAge.Add(L"SAMPLEID", NeotomaIsoSampleID, -1);
		   InsertSampleAge.Add(L"CHRONOLOGYID", NeotomaChronologyID, -1);
		   InsertSampleAge.Add(L"AGE", it->second.Age);
		   InsertSampleAge.Add(L"AGEYOUNGER", it->second.AgeYounger);
		   InsertSampleAge.Add(L"AGEOLDER", it->second.AgeOlder);
		   ns++;
		   }
		 }
	   if (ns > 0) {
		 StatusBar1->SimpleText = L"InsertSampleAge";
		 InsertSampleAge.PostData();
		 if (InsertSampleAge.Post(newids, ErrorMsg)) {
		   if (newids.size() == ns) {
			 msg = IntToStr((int)ns) + L" sample age";
			 if (ns != 0)
			   msg += L"s";
			 msg += L" for specimen stable isotope samples uploaded to SampleAges table: SampleAgeID";
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
		 }  // ---
	   }
	 }

   /*
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
   */



   // -------------------------

   // map<int,int> NeotomaSpecimenIDs;       // TiliaSpecimenID, NeotomaSpecimenID
   // map<int,SPECIMEN*> SpecimenSampleIDs;  // NeotomaIsotopeSampleID, specimen pointer
   // SpecimenSampleIDs[0]->SpecimenID
   // SpecimenSampleIDs[0]->NeotomaSpecimenID
   // assign Neotoma SpecimenIDs to Specimens

   for (itr = SpecimenSampleIDs.begin(); itr != SpecimenSampleIDs.end(); itr++)
	 itr->second->NeotomaSpecimenID = NeotomaSpecimenIDs[itr->second->SpecimenID];

   if (IsoVarID.d13C != -1) {
	 if (!UploadIsoInstrumentation(isoCarbon, L"carbon", IsoDatasetID, IsoVarID.d13C))
	   return false;
	 if (!UploadIsoData(L"δ13C", delta13C, IsoVarID.d13C, SpecimenSampleIDs))
	   return false;
	 }
   if (IsoVarID.CN != -1) {
	 if (!UploadIsoData(L"CN", CNratio, IsoVarID.CN, SpecimenSampleIDs))
	   return false;
	 }
   if (IsoVarID.d15N != -1) {
	 if (!UploadIsoInstrumentation(isoNitrogen, L"nitrogen", IsoDatasetID, IsoVarID.d15N))
	   return false;
	 if (!UploadIsoData(L"δ15N", delta15N, IsoVarID.d15N, SpecimenSampleIDs))
	   return false;
	 }
   if (IsoVarID.d18O != -1) {
	 if (!UploadIsoInstrumentation(isoOxygen, L"oxygen", IsoDatasetID, IsoVarID.d18O))
	   return false;
	 if (!UploadIsoData(L"δ18O", delta18O, IsoVarID.d18O, SpecimenSampleIDs))
	   return false;
	 }
   if (IsoVarID.OH != -1) {
	 if (!UploadIsoData(L"OH", OHratio, IsoVarID.OH, SpecimenSampleIDs))
	   return false;
	 }
   if (IsoVarID.dD != -1) {
	 if (!UploadIsoInstrumentation(isoHydrogen, L"hydrogen", IsoDatasetID, IsoVarID.dD))
	   return false;
	 if (!UploadIsoData(L"δD", deltaD, IsoVarID.dD, SpecimenSampleIDs))
	   return false;
	 }
   if (IsoVarID.d34S != -1) {
	 if (!UploadIsoInstrumentation(isoSulfur, L"sulfur", IsoDatasetID, IsoVarID.d34S))
	   return false;
	 if (!UploadIsoData(L"δ34S", delta34S, IsoVarID.d34S, SpecimenSampleIDs))
	   return false;
	 }
   if (IsoVarID.Sr87Sr86 != -1) {
	 if (!UploadIsoInstrumentation(isoStrontium, L"strontium", IsoDatasetID, IsoVarID.Sr87Sr86))
	   return false;
	 // TODO: Need to add code for uploading strontium isotopes
	 }

   return true;
}
//---------------------------------------------------------------------------

bool TNeotomaUploadForm::UploadIsoData(UnicodeString isotope, vector<DELTARATIO>& drdata,
	int VariableID, map<int,SPECIMEN*>& SpecimenSampleIDs)
{
   vector<int> newids;
   UnicodeString msg, ErrorMsg;

   // map<int,SPECIMEN*> SpecimenSampleIDs;  // NeotomaSampleID, specimen pointer
   map<int,int> SpecSampIDs;  // local SpecimenID, NeotomaSampleID

   map<int,SPECIMEN*>::iterator itr;
   for (itr = SpecimenSampleIDs.begin(); itr != SpecimenSampleIDs.end(); itr++) {
	 SpecSampIDs[itr->second->SpecimenID] = itr->first;
	 }

   // upload data
   unsigned int ndata = 0;
   InsertData Insert_Data(L"InsertData", 3, ipsHTTPS1, ipsJSONS1, TcpClient1);
   for (unsigned int i = 0; i < drdata.size(); i++) {
	 Insert_Data.Add(L"SAMPLEID", SpecSampIDs[drdata[i].SpecimenID], -1);
	 Insert_Data.Add(L"VARIABLEID", VariableID, -1);
	 Insert_Data.AddDouble(L"VALUE", drdata[i].Value);
	 ndata++;
	 }
   StatusBar1->SimpleText = L"InsertData";
   Insert_Data.PostData();
   if (Insert_Data.Post(newids, ErrorMsg)) {
	 if (newids.size() == ndata) {
	   for (unsigned int i=0; i<ndata; i++)
		 drdata[i].NeotomaDataID = newids[i];
	   msg = IntToStr((int)ndata) + L" data value";
	   if (ndata != 1)
		 msg += L"s";
	   msg += L" for " + isotope + L" uploaded to Data table: DataID";
	   if (ndata == 1)
		 msg += (L" = " + IntToStr(newids[0]) + L".");
	   else if (ndata > 1)
		 msg += L"s = " + IntToStr(newids[0]) + L".." + IntToStr(newids.back()) + L".";
	   OutputLine(msg);
	   }
	 else {
	   ErrorMsg = L"Error inserting into Data table!";
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

   vector<ISOSPECIMENDATA> IsoSpecimenData;
   for (unsigned int i = 0; i < drdata.size(); i++) {
	 ISOSPECIMENDATA isd;
	 isd.DataID = drdata[i].NeotomaDataID;     // drdata[i].SpecimenID
	 isd.SpecimenID = NeotomaSpecimenIDs[drdata[i].SpecimenID];
	 isd.SD = drdata[i].SD;
	 IsoSpecimenData.push_back(isd);
	 }

   // upload IsoSpecimenData
   if (!UploadIsoSpecimenData(isotope, IsoSpecimenData))
	 return false;

   if (!UploadIsoMetadata(isotope, drdata))
	 return false;

   return true;
}
//---------------------------------------------------------------------------

bool TNeotomaUploadForm::UploadIsoData(UnicodeString ratio, vector<ELEMENTRATIO>& rdata,
	int VariableID, map<int,SPECIMEN*>& SpecimenSampleIDs)
{
   vector<int> newids;
   UnicodeString msg, ErrorMsg;

   // map<int,SPECIMEN*> SpecimenSampleIDs;  // NeotomaSampleID, specimen pointer
   map<int,int> SpecSampIDs;  // local SpecimenID, NeotomaSampleID

   map<int,SPECIMEN*>::iterator itr;
   for (itr = SpecimenSampleIDs.begin(); itr != SpecimenSampleIDs.end(); itr++) {
	 // itr->second->NeotomaSpecimenID
	 SpecSampIDs[itr->second->SpecimenID] = itr->first;
	 }

   // upload data
   unsigned int ndata = 0;
   InsertData Insert_Data(L"InsertData", 3, ipsHTTPS1, ipsJSONS1, TcpClient1);
   for (unsigned int i = 0; i < rdata.size(); i++) {
	 //Insert_Data.Add(L"SAMPLEID", rdata[i].NeotomaSampleID, -1);
	 Insert_Data.Add(L"SAMPLEID", SpecSampIDs[rdata[i].SpecimenID], -1);
	 Insert_Data.Add(L"VARIABLEID", VariableID, -1);
	 Insert_Data.AddDouble(L"VALUE", rdata[i].Value);
	 ndata++;
	 }
   StatusBar1->SimpleText = L"InsertData";
   Insert_Data.PostData();
   if (Insert_Data.Post(newids, ErrorMsg)) {
	 if (newids.size() == ndata) {
	   for (unsigned int i=0; i<ndata; i++)
		 rdata[i].NeotomaDataID = newids[i];
	   msg = IntToStr((int)ndata) + L" data value";
	   if (ndata != 1)
		 msg += L"s";
	   msg += L" for " + ratio + L" uploaded to Data table: DataID";
	   if (ndata == 1)
		 msg += (L" = " + IntToStr(newids[0]) + L".");
	   else if (ndata > 1)
		 msg += L"s = " + IntToStr(newids[0]) + L".." + IntToStr(newids.back()) + L".";
	   OutputLine(msg);
	   }
	 else {
	   ErrorMsg = L"Error inserting into Data table!";
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

   vector<ISOSPECIMENDATA> IsoSpecimenData;
   for (unsigned int i = 0; i < rdata.size(); i++) {
	 ISOSPECIMENDATA isd;
	 isd.DataID = rdata[i].NeotomaDataID;
	 //isd.SpecimenID = SpecimenSampleIDs[rdata[i].NeotomaSampleID]->NeotomaSpecimenID;
     isd.SpecimenID = NeotomaSpecimenIDs[rdata[i].SpecimenID];
	 IsoSpecimenData.push_back(isd);
	 }

   // upload IsoSpecimenData
   if (!UploadIsoSpecimenData(ratio, IsoSpecimenData))
	 return false;

   //if (!UploadIsoMetadata(isotope, drdata))
   //	 return false;

   return true;
}
//---------------------------------------------------------------------------

bool TNeotomaUploadForm::UploadIsoSpecimenData(UnicodeString isotope, vector<ISOSPECIMENDATA>& IsoSpecimenData)
{
   UnicodeString ErrorMsg, msg;

   // InsertIsoSpecimenData
   // @DATAID int
   // @SPECIMENID int
   // @SD float

   InsertData InsertIsoSpecimenData(L"InsertIsoSpecimenData", 3, ipsHTTPS1, ipsJSONS1, TcpClient1);
   for (unsigned int i=0; i < IsoSpecimenData.size(); i++) {
	 InsertIsoSpecimenData.Add(L"DATAID", IsoSpecimenData[i].DataID, -1);
	 InsertIsoSpecimenData.Add(L"SPECIMENID", IsoSpecimenData[i].SpecimenID, -1);
	 InsertIsoSpecimenData.AddDouble(L"SD", IsoSpecimenData[i].SD);
	 }
   StatusBar1->SimpleText = L"InsertIsoSpecimenData";
   InsertIsoSpecimenData.PostData();
   if (InsertIsoSpecimenData.Post(ErrorMsg)) {
	 msg = isotope + L" data uploaded to IsoSpecimenData table.";
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

bool TNeotomaUploadForm::UploadIsoMetadata(UnicodeString isotope, vector<DELTARATIO>& drdata)
{
   UnicodeString ErrorMsg, msg;
   /*
   InsertIsoMetadata
   @DATAID int,
   @ISOMATANALTYPEID int,
   @ISOSUBSTRATETYPEID int,
   @ANALYSTID int,
   @LAB nvarchar(255),
   @LABNUMBER nvarchar(64),
   @MASSMG float,
   @WEIGHTPERCENT float,
   @ATOMICPERCENT float,
   @REPS int
   */

   InsertData InsertIsoMetadata(L"InsertIsoMetadata", 10, ipsHTTPS1, ipsJSONS1, TcpClient1);
   int nullvalue;
   for (unsigned int i=0; i<drdata.size(); i++) {
	 nullvalue = (drdata[i].NeotomaDataID == 0) ? 0 : -1;
	 InsertIsoMetadata.Add(L"DATAID", drdata[i].NeotomaDataID, nullvalue);
	 nullvalue = (drdata[i].IsoMatAnalTypeID == 0) ? 0 : -1;
	 InsertIsoMetadata.Add(L"ISOMATANALTYPEID", drdata[i].IsoMatAnalTypeID, nullvalue);
	 nullvalue = (drdata[i].IsoSubstrateTypeID == 0) ? 0 : -1;
	 InsertIsoMetadata.Add(L"ISOSUBSTRATETYPEID", drdata[i].IsoSubstrateTypeID, nullvalue);
	 nullvalue = (drdata[i].AnalystID == 0) ? 0 : -1;
	 InsertIsoMetadata.Add(L"ANALYSTID", drdata[i].AnalystID, nullvalue);
	 InsertIsoMetadata.Add(L"LAB", drdata[i].Lab);
	 InsertIsoMetadata.Add(L"LABNUMBER", drdata[i].LabNr);
	 InsertIsoMetadata.AddDouble(L"MASSMG", drdata[i].Mass);
	 InsertIsoMetadata.AddDouble(L"WEIGHTPERCENT", drdata[i].WeightPercent);
	 InsertIsoMetadata.AddDouble(L"ATOMICPERCENT", drdata[i].AtomicPercent);
	 nullvalue = (drdata[i].Reps == 0) ? 0 : -1;
	 InsertIsoMetadata.Add(L"REPS", drdata[i].Reps, nullvalue);
	 }
   StatusBar1->SimpleText = L"InsertIsoMetadata";
   InsertIsoMetadata.PostData();
   if (InsertIsoMetadata.Post(ErrorMsg)) {
	 msg = isotope + L" metadata uploaded to IsoMetadata table.";
	 OutputLine(msg);
	 }
   else {
	 OutputError(L"ERROR: " + ErrorMsg);
	 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 return false;
	 }

   // InsertIsoSamplePretreatments
   // @DATAID int
   // @ISOPRETREATMENTTYPEID int
   // @ORDER int
   // @VALUE float

   // map<int,pair<int,double> > IsoPretreatments;  // order, IsoPretreatmentTypeID, value

   bool pretreatments = false;
   InsertData InsertIsoSamplePretreatments(L"InsertIsoSamplePretreatments", 4, ipsHTTPS1, ipsJSONS1, TcpClient1);
   for (unsigned int i=0; i<drdata.size(); i++) {
	 if (drdata[i].IsoPretreatments.size() > 0) {
	   map<int,pair<int,Variant> >::iterator itr;
	   map<int,pair<int,Variant> >::iterator begin = drdata[i].IsoPretreatments.begin();
	   map<int,pair<int,Variant> >::iterator end = drdata[i].IsoPretreatments.end();
	   for (itr = begin; itr != end; itr++) {
		 InsertIsoSamplePretreatments.Add(L"DATAID", drdata[i].NeotomaDataID, -1);
		 InsertIsoSamplePretreatments.Add(L"ISOPRETREATMENTTYPEID", itr->second.first, -1);
		 InsertIsoSamplePretreatments.Add(L"ORDER", itr->first, -1);
		 InsertIsoSamplePretreatments.AddDouble(L"VALUE", itr->second.second);
		 }
	   pretreatments = true;
	   }
	 }
   if (pretreatments) {
	 StatusBar1->SimpleText = L"InsertIsoSamplePretreatments";
	 InsertIsoSamplePretreatments.PostData();
	 if (InsertIsoSamplePretreatments.Post(ErrorMsg)) {
	   msg = isotope + L" pretreatments uploaded to IsoSamplePretreatments table.";
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

// upload isotope instrumentation
bool TNeotomaUploadForm::UploadIsoInstrumentation(short isotope, UnicodeString element,
	int DatasetID, int VariableID)
{
   UnicodeString msg, ErrorMsg;

   if (TSSForm->IsoMetadata.count(isotope) == 0)
	 return true;

   ISOMETADATA& IsoMetadata = TSSForm->IsoMetadata[isotope];
   if (IsoMetadata.IsEmpty())
	 return true;
   /*
   InsertIsoInstrumention
   @DATASETID int,
   @VARIABLEID int,
   @ISOINSTRUMENTATIONTYPEID int = null,
   @ISOSAMPLEINTROSYSTEMTYPEID int = null,
   @INSTERRORPERCENT float = null,
   @INSTERRORRUNSD float = null,
   @INSTERRORLONGTERMPERCENT float = null,
   @NOTES nvarchar(MAX) = null
   */

   // upload instrumentation
   InsertData InsertIsoInst(L"InsertIsoInstrumention", 8, ipsHTTPS1, ipsJSONS1, TcpClient1);
   InsertIsoInst.Add(L"DATASETID", DatasetID, -1);
   InsertIsoInst.Add(L"VARIABLEID", VariableID, -1);
   InsertIsoInst.Add(L"ISOINSTRUMENTATIONTYPEID", IsoMetadata.IsoInstrumentationTypeID, -1);
   InsertIsoInst.Add(L"ISOSAMPLEINTROSYSTEMTYPEID", IsoMetadata.IsoSampleIntroSystemTypeID, -1);
   InsertIsoInst.AddDouble(L"INSTERRORPERCENT", IsoMetadata.TechError);
   InsertIsoInst.AddDouble(L"INSTERRORRUNSD", IsoMetadata.TechErrorSD);
   InsertIsoInst.AddDouble(L"INSTERRORLONGTERMPERCENT", IsoMetadata.LongTermError);
   InsertIsoInst.Add(L"NOTES", IsoMetadata.Notes);
   StatusBar1->SimpleText = L"InsertIsoInstrumention";
   InsertIsoInst.PostData();
   if (InsertIsoInst.Post(ErrorMsg)) {
	 msg = L"Instumentation for " + element + L" isotope data uploaded to IsoInstrumentation table.";
	 OutputLine(msg);
	 }
   else {
	 OutputError(L"ERROR: " + ErrorMsg);
	 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 return false;
	 }

   // upload measurments on isttopic standards
   /*
   InsertIsoStandards
   @DATASETID int,
   @VARIABLEID int,
   @ISOSTANDARDID int,
   @VALUE float
   */

   if (IsoMetadata.IsoStandards.size() > 0) {
	 InsertData InsertIsoStandard(L"InsertIsoStandards", 4, ipsHTTPS1, ipsJSONS1, TcpClient1);
	 for (unsigned int i = 0; i < IsoMetadata.IsoStandards.size(); i++) {
	   InsertIsoStandard.Add(L"DATASETID", DatasetID, -1);
	   InsertIsoStandard.Add(L"VARIABLEID", VariableID, -1);
	   InsertIsoStandard.Add(L"ISOSTANDARDID", IsoMetadata.IsoStandards[i].first, -1);
	   InsertIsoStandard.Add(L"VALUE", IsoMetadata.IsoStandards[i].second);
	   }
	 StatusBar1->SimpleText = L"InsertIsoStandards";
	 InsertIsoStandard.PostData();
	 if (InsertIsoStandard.Post(ErrorMsg)) {
	   msg = L"Isotopic measurments on standards for " + element + L" uploaded to IsoStandards table.";
	   OutputLine(msg);
	   }
	 else {
	   OutputError(L"ERROR: " + ErrorMsg);
	   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return false;
	   }
	 }

   // Strontium metadata
   /*
   InsertIsoSrMetadata
   @DATASETID int,
   @VARIABLEID int,
   @SRLOCALVALUE float = null,
   @SRLOCALVALUESD float = null,
   @SRLOCALGEOLCONTEXT nvarchar(MAX) = null
   */

   if (isotope == isoStrontium) {
	 if (!IsoMetadata.SrLocalValue.IsEmpty() || !IsoMetadata.SrLocalGeolContext.IsEmpty()) {
	   InsertData InsertIsoSr(L"InsertIsoSrMetadata", 4, ipsHTTPS1, ipsJSONS1, TcpClient1);
	   InsertIsoSr.Add(L"DATASETID", DatasetID, -1);
	   InsertIsoSr.Add(L"VARIABLEID", VariableID, -1);
	   InsertIsoSr.AddDouble(L"SRLOCALVALUE", IsoMetadata.SrLocalValue);
	   InsertIsoSr.AddDouble(L"SRLOCALVALUESD", IsoMetadata.SrLocalValueSD);
	   InsertIsoSr.Add(L"SRLOCALGEOLCONTEXT", IsoMetadata.SrLocalGeolContext);
	   StatusBar1->SimpleText = L"InsertIsoSrMetadata";
	   InsertIsoSr.PostData();
	   if (InsertIsoSr.Post(ErrorMsg)) {
		 msg = L"Strontium metadata uploaded to IsoSrMetadta table.";
		 OutputLine(msg);
		 }
	   else {
		 OutputError(L"ERROR: " + ErrorMsg);
		 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 return false;
		 }
	   }
	 }

   return true;
}
//---------------------------------------------------------------------------

