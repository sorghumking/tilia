//---------------------------------------------------------------------------


#pragma hdrstop

#include "TIGetFM2.h"
#include "TISpread.h"
#ifndef TGParentH
#include "TGParent.h"
#endif
#ifndef TIJSONH
#include "TIJSON.h"
#endif
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------

void TTilSpreadSheetForm::DownloadFAUNMAP2Data(FM2LOCALITY& Locality,
	vector<pair<UnicodeString,UnicodeString> >& AnalysisUnits)
{
   int MachineNo = Locality.MachineNo;
   SITE* SitePtr = (SITE*)Sites->Items[0];
   SitePtr->SiteName = Locality.SiteName;
   SitePtr->State = Locality.State;
   if (SameText(Locality.State, L"Alberta") ||
	   SameText(Locality.State, L"British Columbia") ||
	   SameText(Locality.State, L"Labrador") ||
	   SameText(Locality.State, L"Manitoba") ||
	   SameText(Locality.State, L"New Brunswick") ||
	   SameText(Locality.State, L"Newfoundland") ||
	   SameText(Locality.State, L"Northwest Territories") ||
	   SameText(Locality.State, L"Nova Scotia") ||
	   SameText(Locality.State, L"Nunavut") ||
	   SameText(Locality.State, L"Ontario") ||
	   SameText(Locality.State, L"Prince Edward Island") ||
	   SameText(Locality.State, L"Quebec") ||
	   SameText(Locality.State, L"Saskatchewan") ||
	   SameText(Locality.State, L"Yukon")) {
	 SitePtr->Country = L"Canada";
	 }
   else
	 SitePtr->Country = L"United States";
   SitePtr->County = Locality.County;
   SitePtr->Notes = Locality.SiteNotes;
   SitePtr->LongEast = Locality.LongitudeEast;
   SitePtr->LongWest = Locality.LongitudeWest;
   SitePtr->LatNorth = Locality.LatitudeNorth;
   SitePtr->LatSouth = Locality.LatitudeSouth;
   SitePtr->Altitude = Locality.Altitude;

   bool success = GetFAUNMAP2Fauna(MachineNo, AnalysisUnits);
   if (success)
	 success = GetFAUNMAP2AbsoluteDates(MachineNo);

   ParentForm->StatusBar1->Panels->Items[0]->Text = L"";
}
//---------------------------------------------------------------------------

bool TTilSpreadSheetForm::GetFAUNMAP2Fauna(int MachineNo,
	vector<pair<UnicodeString,UnicodeString> >& AnalysisUnits)
{
   FM2GetLocalityFauna Fauna(ipwJSON1, TcpClient1);
   Fauna.AddParam(L"MACHINENO", MachineNo);
   ParentForm->StatusBar1->Panels->Items[0]->Text = Fauna.WebServiceName();
   if (Fauna.Execute()) {
	 if (Fauna.Size() > 0) {
	   int row = 3;
	   int col = 8;
	   set<UnicodeString> CollUnitSet;
	   map<pair<UnicodeString,UnicodeString>,int> AnalUnitCol;
	   for (unsigned int i=0; i<Fauna.Size(); i++) {
		 UnicodeString CollUnit = Fauna.Items[i].CollectionUnit;
		 if (CollUnit.IsEmpty())
		   CollUnit = L"Locality";
		 UnicodeString AnalUnit = Fauna.Items[i].AnalysisUnit;
		 pair<UnicodeString,UnicodeString> CollAnalUnit(CollUnit, AnalUnit);

		 if (find(AnalysisUnits.begin(), AnalysisUnits.end(), CollAnalUnit) != AnalysisUnits.end()) {
		   CollUnitSet.insert(CollUnit);
		   UnicodeString AnalUnit = Fauna.Items[i].AnalysisUnit;
		   pair<UnicodeString,UnicodeString> CollAnalUnit(CollUnit, AnalUnit);
		   if (AnalUnitCol.count(CollAnalUnit) == 0)
			 AnalUnitCol[CollAnalUnit] = col++;
		   }
		 }

	   if (CollUnitSet.size() > 1) {
		 ProfGrid1->AbsoluteCells[1][row]->Value = WideString(L"#Coll.Name");
		 ProfGrid1->AbsoluteCells[2][row++]->Value = WideString(L"Collection Unit Name");
		 ProfGrid1->AbsoluteCells[1][row]->Value = WideString(L"#Coll.Handle");
		 ProfGrid1->AbsoluteCells[2][row++]->Value = WideString(L"Handle");
		 }

	   map<UnicodeString,int> TaxonRow;
	   for (unsigned int i=0; i<Fauna.Size(); i++) {
		 UnicodeString CollUnit = Fauna.Items[i].CollectionUnit;
		 if (CollUnit.IsEmpty())
		   CollUnit = L"Locality";
         UnicodeString AnalUnit = Fauna.Items[i].AnalysisUnit;
		 pair<UnicodeString,UnicodeString> CollAnalUnit(CollUnit, AnalUnit);
		 if (find(AnalysisUnits.begin(), AnalysisUnits.end(), CollAnalUnit) != AnalysisUnits.end()) {
		   UnicodeString Taxon = Fauna.Items[i].TaxonName;
		   if (TaxonRow.count(Taxon) == 0) {
			 ProfGrid1->AbsoluteCells[2][row]->Value = WideString(Taxon);
			 TaxonRow[Taxon] = row++;
			 }
		   }
		 }

	   // write analysis unit and collection unit names
	   col = 8;
	   map<pair<UnicodeString,UnicodeString>,int>::iterator itr;
	   map<pair<UnicodeString,UnicodeString>,int>::iterator begin = AnalUnitCol.begin();
	   map<pair<UnicodeString,UnicodeString>,int>::iterator end = AnalUnitCol.end();
	   for (itr = begin; itr != end; itr++) {
		 ProfGrid1->AbsoluteCells[itr->second][2]->Value = WideString(itr->first.second);
		 if (CollUnitSet.size() > 1)
		   ProfGrid1->AbsoluteCells[itr->second][3]->Value = WideString(itr->first.first);
		 col++;
		 }

	   for (unsigned int i=0; i<Fauna.Size(); i++) {
		 UnicodeString CollUnit = Fauna.Items[i].CollectionUnit;
		 if (CollUnit.IsEmpty())
		   CollUnit = L"Locality";
		 UnicodeString AnalUnit = Fauna.Items[i].AnalysisUnit;
		 pair<UnicodeString,UnicodeString> CollAnalUnit(CollUnit, AnalUnit);

		 vector<pair<UnicodeString,UnicodeString> >::iterator it;

		 if (find(AnalysisUnits.begin(), AnalysisUnits.end(), CollAnalUnit) != AnalysisUnits.end()) {
		   col = AnalUnitCol[CollAnalUnit];
		   UnicodeString Taxon = Fauna.Items[i].TaxonName;
		   row = TaxonRow[Taxon];
		   if (!Fauna.Items[i].MNI.IsEmpty()) {
			 ProfGrid1->AbsoluteCells[4][row]->Value = WideString(L"MNI");
			 ProfGrid1->AbsoluteCells[col][row]->Value = Fauna.Items[i].MNI;
			 }
		   if (!Fauna.Items[i].NISP.IsEmpty()) {
			 ProfGrid1->AbsoluteCells[4][row]->Value = WideString(L"NISP");
			 ProfGrid1->AbsoluteCells[col][row]->Value = Fauna.Items[i].NISP;
			 }
		   if (Fauna.Items[i].MNI.IsEmpty() && Fauna.Items[i].NISP.IsEmpty()) {
             ProfGrid1->AbsoluteCells[4][row]->Value = WideString(L"present/absent");
			 ProfGrid1->AbsoluteCells[col][row]->Value = 1;
			 }
		   if (!Fauna.Items[i].Context.IsEmpty())
			 ProfGrid1->AbsoluteCells[5][row]->Value = WideString(Fauna.Items[i].Context);
		   if (!Fauna.Items[i].Modification.IsEmpty()) {
			 // TODO: Modification
			 }
		   }
		 }
	   }
	 }
   else {
	 return false;
	 }
   return true;
}
//---------------------------------------------------------------------------

bool TTilSpreadSheetForm::GetFAUNMAP2AbsoluteDates(int MachineNo)
{
   FM2GetAbsoluteDates Absolute(ipwJSON1, TcpClient1);
   Absolute.AddParam(L"MACHINENO", MachineNo);
   ParentForm->StatusBar1->Panels->Items[0]->Text = Absolute.WebServiceName();
   if (Absolute.Execute()) {
	 if (Absolute.Size() > 0) {
	   cxCheckBox3->Checked = true;
	   for (unsigned int i=0; i<Absolute.Size(); i++) {
		 FM2ABSOLUTE& fdate = Absolute.Items[i];
		 GEOCHRON date;
		 //  date.NeotomaGeochronID = ndate.GeochronID;
		 date.Method = fdate.GeochronType;
		 date.AgeUnits = (SameText(date.Method, L"Carbon-14")) ? L"Radiocarbon years BP" : L"Calendar years BP";
		 date.AnalUnit = fdate.Analysisunit;
		 date.LabNumber = fdate.Lab;
		 if (!fdate.AssociatedDate.IsEmpty())
		   date.Age = fdate.AssociatedDate;
		 if (!fdate.StandardDeviation.IsEmpty()) {
		   date.ErrorOlder = fdate.StandardDeviation;
		   date.ErrorYounger = fdate.StandardDeviation;
		   date.StdDev = fdate.StandardDeviation;
		   date.Sigma = 1;
		   }
		 if (SameText(fdate.DateConfidence, L"Infinite"))
		   date.GreaterThan = true;
		 date.MaterialDated = fdate.MaterialDated;
		 if (!fdate.DateConfidence.IsEmpty())
		   date.Notes = L"FAUNMAP date confidence: " + fdate.DateConfidence + L".";
		 if (!fdate.DatePosition.IsEmpty()) {
		   if (!date.Notes.IsEmpty())
			 date.Notes += L" ";
		   date.Notes += fdate.DatePosition;
		   }
		 GeochronList->Add(date);
		 GeochronDataSource->DataChanged();
		 }
	   }
	 }
   else {
	 return false;
	 }

   return true;
}
//---------------------------------------------------------------------------

/*
  //int AbsoluteID;
  //int MachineNo;
  //UnicodeString Analysisunit;
  //int AgeID;
  //Variant AssociatedDate;
  //Variant StandardDeviation;
  ////UnicodeString DatingMethod;
  //UnicodeString GeochronType;
  UnicodeString RadiocarbonMethod;
  UnicodeString Fraction;
  //UnicodeString MaterialDated;
  //UnicodeString Lab;
  //UnicodeString DatePosition;
  //UnicodeString DateConfidence;
  UnicodeString TaxonName;
  int TaxonID;
*/
