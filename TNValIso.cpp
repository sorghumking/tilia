//---------------------------------------------------------------------------
#include <vcl.h>
#include "pch.h"

#pragma hdrstop

#include "TNValIso.h"
#ifndef TIUploadH
#include "TIUpload.h"
#endif
#ifndef TICommonH
#include "TICommon.h"
#endif

//---------------------------------------------------------------------------

#pragma package(smart_init)

template <class T> void ValidateIsotope<T>::GetIsoData(vector<T>& vec)
{
   map<int,T>::iterator itr;
   for (itr = IsoType.begin(); itr != IsoType.end(); itr++)
	 vec.push_back(itr->second);
}
//---------------------------------------------------------------------------

template <class T> bool ValidateIsotope<T>::GetDataRows(map<int,int>& SpecimenRows)
{
   if (GetFloats(IsoName)) {
	 for (unsigned int i=0; i<dv.size(); i++) {
	   int row = dv[i].first;
	   if (FDataRows.count(row) == 0) {
		 FDataRows.insert(row);
		 IsoType[row] = T(SpecimenRows[row]);
		 }
	   }
	 }
   else
	 return false;
   return true;
}
//---------------------------------------------------------------------------

template <class T> bool ValidateIsotope<T>::GetValue(void)
{
   if (GetFloats(IsoName)) {
	 for (unsigned int i=0; i<dv.size(); i++) {
	   if (FDataRows.count(dv[i].first) > 0)
		 IsoType[dv[i].first].Value = dv[i].second;
	   }
	 }
   else
	 return false;
   return true;
}
//---------------------------------------------------------------------------

template <class T> bool ValidateIsotope<T>::GetSD(void)
{
   if (GetFloats(L"SD")) {
	 for (unsigned int i=0; i<dv.size(); i++) {
	   if (FDataRows.count(dv[i].first) > 0)
		 IsoType[dv[i].first].SD = dv[i].second;
	   }
	 }
   else
	 return false;
   return true;
}
//---------------------------------------------------------------------------

template <class T> bool ValidateIsotope<T>::GetMass(void)
{
   if (GetFloats(L"Mass (mg)")) {
	 for (unsigned int i=0; i<dv.size(); i++) {
	   if (FDataRows.count(dv[i].first) > 0)
		 IsoType[dv[i].first].Mass = dv[i].second;
	   }
	 }
   else
	 return false;
   return true;
}
//---------------------------------------------------------------------------

template <class T> bool ValidateSrRatio<T>::GetTotalSr(void)
{
   if (GetFloats(L"Total Sr (ppm)")) {
	 for (unsigned int i=0; i<dv.size(); i++) {
	   if (FDataRows.count(dv[i].first) > 0)
		 IsoType[dv[i].first].TotalSr = dv[i].second;
	   }
	 }
   else
	 return false;
   return true;
}
//---------------------------------------------------------------------------

template <class T> bool ValidateIsotope<T>::GetWeightPercent(void)
{
   if (GetFloats(L"Weight %")) {
	 for (unsigned int i=0; i<dv.size(); i++) {
	   if (FDataRows.count(dv[i].first) > 0)
		 IsoType[dv[i].first].WeightPercent = dv[i].second;
		}
	  }
	else
	  return false;
	return true;
}
//---------------------------------------------------------------------------

template <class T> bool ValidateIsotope<T>::GetAtomicPercent(void)
{
   if (GetFloats(L"Atomic %")) {
	 for (unsigned int i=0; i<dv.size(); i++) {
	   if (FDataRows.count(dv[i].first) > 0)
		 IsoType[dv[i].first].AtomicPercent = dv[i].second;
		}
	  }
	else
	  return false;
	return true;
}
//---------------------------------------------------------------------------

template <class T> bool ValidateIsotope<T>::GetMaterialAnalyzed(map<int,UnicodeString>& Items)
{
	ParentIDs.clear();
	if (GetIDs(L"Material Analyzed", Items)) {
	  for (unsigned int i=0; i<iv.size(); i++) {
		if (FDataRows.count(iv[i].first) > 0) {
		  IsoType[iv[i].first].IsoMatAnalTypeID = iv[i].second;
		  ParentIDs[iv[i].first] = iv[i].second;
		  }
		}
	  }
   else
	 return false;
   return true;
}
//---------------------------------------------------------------------------

template <class T> bool ValidateIsotope<T>::GetSubstrate(multimap<int, pair<int,UnicodeString> >& Items)
{
   if (GetChildIDs(L"Substrate", Items)) {
	 for (unsigned int i=0; i<iv.size(); i++) {
	   if (FDataRows.count(iv[i].first) > 0)
		 IsoType[iv[i].first].IsoSubstrateTypeID = iv[i].second;
	   }
	 }
   else
	 return false;
   return true;
}
//---------------------------------------------------------------------------

template <class T> bool ValidateIsotope<T>::GetPretreatment(vector<NEOTOMAPRETREATMENT>& Items)
{
   if (GetPretreatments(L"Pretreatment", Items)) {
	 for (unsigned int i=0; i<iv.size(); i++) {
	   if (FDataRows.count(iv[i].first) > 0)
		 IsoType[iv[i].first].IsoPretreatments = pv;
	   }
	 }
   else
	 return false;
   return true;
}
//---------------------------------------------------------------------------

template <class T> bool ValidateIsotope<T>::GetAnalyst(void)
{
   if (GetContact(L"Analyst") ) {
	 for (unsigned int i=0; i<iv.size(); i++) {
	   if (FDataRows.count(iv[i].first) > 0)
		 IsoType[iv[i].first].AnalystID = iv[i].second;
	   }
	 }
   else
	 return false;
   return true;
}
//---------------------------------------------------------------------------

template <class T> bool ValidateIsotope<T>::GetLab(void)
{
   if (GetStrings(L"Lab") ) {
	 for (unsigned int i=0; i<sv.size(); i++) {
	   if (FDataRows.count(sv[i].first) > 0)
		 IsoType[sv[i].first].Lab = sv[i].second;
	   }
	 }
   else
	 return false;
   return true;
}
//---------------------------------------------------------------------------

template <class T> bool ValidateIsotope<T>::GetLabNr(void)
{
   if (GetStrings(L"Lab Nr") ) {
	 for (unsigned int i=0; i<sv.size(); i++) {
	   if (FDataRows.count(sv[i].first) > 0)
		 IsoType[sv[i].first].LabNr = sv[i].second;
	   }
	 }
   else
	 return false;
   return true;
}
//---------------------------------------------------------------------------

template <class T> bool ValidateIsotope<T>::GetScale(multimap<UnicodeString,pair<int,UnicodeString> >& Items)
{
   if (GetIsoSpecificIDs(L"Scale", Items) ) {
	 for (unsigned int i=0; i<iv.size(); i++) {
	   if (FDataRows.count(iv[i].first) > 0)
		 IsoType[iv[i].first].IsoScaleTypeID = iv[i].second;
	   }
	 }
   else
	 return false;
   return true;
}
//---------------------------------------------------------------------------

template <class T> bool ValidateIsotope<T>::GetFloats(UnicodeString ColumnName)
{
   double Value;
   bool success = true;

   dv.clear();
   int col = GetColumn(isotope, ColumnName);
   if (col != -1) {
	 for (int row=2; row<RowCount; row++) {
	   UnicodeString Text = TSSForm->AdvIsotopeStringGrid->AllCells[col][row];
	   if (!Text.IsEmpty()) {
		 if (TryStrToFloat(Text,Value))
		   dv.push_back(pair<int,double>(row,Value));
		 else {
		   UploadForm->OutputError(L"ERROR: " + ColumnName + L" value in isotope grid row " +
					   IntToStr(row) + L" is not valid.");
		   success = false;
		   }
		 }
	   }
	 }
   else {   // this should never happen, but...
	 UploadForm->OutputError(L"ERROR: Column «" +  ColumnName + L"» not found in isotope grid");
	 success = false;
	 }
   return success;
}
//---------------------------------------------------------------------------

template <class T> bool ValidateIsotope<T>::GetInts(UnicodeString ColumnName)
{
   int Value;
   bool success = true;

   iv.clear();
   int col = GetColumn(isotope, ColumnName);
   if (col != -1) {
	 for (int row=2; row<RowCount; row++) {
	   UnicodeString Text = TSSForm->AdvIsotopeStringGrid->AllCells[col][row];
	   if (!Text.IsEmpty()) {
		 if (TryStrToInt(Text,Value))
		   iv.push_back(pair<int,int>(row,Value));
		 else {
		   UploadForm->OutputError(L"ERROR: " + ColumnName + L" value in isotope grid row " +
					   IntToStr(row) + L" is not valid.");
		   success = false;
		   }
		 }
	   }
	 }
   else {   // this should never happen, but...
	 UploadForm->OutputError(L"ERROR: Column «" +  ColumnName + L"» not found in isotope grid");
	 success = false;
	 }
   return success;
}
//---------------------------------------------------------------------------

template <class T> bool ValidateIsotope<T>::GetStrings(UnicodeString ColumnName)
{
   bool success = true;

   sv.clear();
   int col = GetColumn(isotope, ColumnName);
   if (col != -1) {
	 for (int row=2; row<RowCount; row++) {
	   UnicodeString Text = TSSForm->AdvIsotopeStringGrid->AllCells[col][row];
	   if (!Text.IsEmpty())
		 sv.push_back(pair<int,UnicodeString>(row,Text));
	   }
	 }
   else {   // this should never happen, but...
	 UploadForm->OutputError(L"ERROR: Column «" +  ColumnName + L"» not found in isotope grid");
	 success = false;
	 }
   return success;
}
//---------------------------------------------------------------------------

template <class T> bool ValidateIsotope<T>::GetIDs(UnicodeString ColumnName,
	map<int,UnicodeString>& idmap)
{
   bool success = true;

   iv.clear();
   int col = GetColumn(isotope, ColumnName);
   if (col != -1) {
	 for (int row=2; row<RowCount; row++) {
	   UnicodeString Text = TSSForm->AdvIsotopeStringGrid->AllCells[col][row];
	   if (!Text.IsEmpty()) {
		 bool found = false;
		 map<int,UnicodeString>::iterator itr;
		 for (itr = idmap.begin(); itr != idmap.end(); itr++) {
		   if (SameText(Text,itr->second)) {
			 iv.push_back(pair<int,int>(row,itr->first));
			 found = true;
			 break;
			 }
		   }
		 if (!found) {
		   UploadForm->OutputError(L"ERROR: " + ColumnName + L" «" + Text + L"» in isotope grid row " +
			 IntToStr(row) + L" not found in Neotoma.");
		   success = false;
		   }
		 }
	   }
	 }
   else {   // this should never happen, but...
	 UploadForm->OutputError(L"ERROR: Column «" +  ColumnName + L"» not found in isotope grid");
	 success = false;
	 }
   return success;
}
//---------------------------------------------------------------------------

template <class T> bool ValidateIsotope<T>::GetIsoSpecificIDs(UnicodeString ColumnName,
	multimap<UnicodeString,pair<int,UnicodeString> >& Items)
{
   bool success = true;
   iv.clear();
   int col = GetColumn(isotope, ColumnName);

   if (col != -1) {
	 for (int row=2; row<RowCount; row++) {
	   UnicodeString Text = TSSForm->AdvIsotopeStringGrid->AllCells[col][row];
	   if (!Text.IsEmpty()) {
		 bool found = false;
		 multimap<UnicodeString,pair<int,UnicodeString> >::iterator itr;
		 pair<multimap<UnicodeString,pair<int,UnicodeString> >::iterator, multimap<UnicodeString,pair<int,UnicodeString> >::iterator> range;
		 range = Items.equal_range(IsoName);
		 if (range.first != Items.end()) {
		   for (itr=range.first; itr!=range.second; itr++) {
			 if (SameText(Text,itr->second.second)) {
			   iv.push_back(pair<int,int>(row,itr->second.first));
			   found = true;
			   break;
			   }
			 }
		   }
		 if (!found) {
		   UploadForm->OutputError(L"ERROR: " + ColumnName + L" «" + Text + L"» for isotope " +
			 IsoName + L" in grid row " + IntToStr(row) + L" not found in Neotoma.");
		   success = false;
		   }
		 }
	   }
	 }
   else {   // this should never happen, but...
	 UploadForm->OutputError(L"ERROR: Column «" +  ColumnName + L"» not found in isotope grid");
	 success = false;
	 }
   return success;
}
//---------------------------------------------------------------------------

template <class T> bool ValidateIsotope<T>::GetChildIDs(UnicodeString ColumnName,
	multimap<int, pair<int,UnicodeString> >& idmap)
{
   bool success = true;
   iv.clear();
   int col = GetColumn(isotope, ColumnName);

   if (col != -1) {
	 for (int row=2; row<RowCount; row++) {
	   UnicodeString Text = TSSForm->AdvIsotopeStringGrid->AllCells[col][row];
	   if (!Text.IsEmpty()) {
		 bool found = false;
		 if (ParentIDs.count(row) > 0) {
		   multimap<int,pair<int,UnicodeString> >::iterator itr;
		   pair<multimap<int,pair<int,UnicodeString> >::iterator, multimap<int,pair<int,UnicodeString> >::iterator> range;
		   range = idmap.equal_range(ParentIDs[row]);
		   if (range.first != idmap.end()) {
			 for (itr=range.first; itr!=range.second; itr++) {
			   if (SameText(Text,itr->second.second)) {
				 iv.push_back(pair<int,int>(row,itr->second.first));
				 found = true;
				 break;
				 }
			   }
			 }

		   if (!found) {
			 UploadForm->OutputError(L"ERROR: " + ColumnName + L" «" + Text + L"» in isotope grid row " +
			   IntToStr(row) + L" not found in Neotoma.");
			 success = false;
			 }
		   }
		 }
	   }
	 }
   else {   // this should never happen, but...
	 UploadForm->OutputError(L"ERROR: Column «" +  ColumnName + L"» not found in isotope grid");
	 success = false;
	 }
   return success;
}
//---------------------------------------------------------------------------

template <class T> bool ValidateIsotope<T>::GetPretreatments(UnicodeString ColumnName,
	vector<NEOTOMAPRETREATMENT>& Items)
{
   bool success = true;

   pv.clear();
   int col = GetColumn(isotope, ColumnName);
   if (col != -1) {
	 for (int row=2; row<RowCount; row++) {
	   UnicodeString Text = TSSForm->AdvIsotopeStringGrid->AllCells[col][row];
	   if (!Text.IsEmpty()) {
		 vector<NEOTOMAPRETREATMENT> Pretreatments;
		 vector<UnicodeString> Treatments;
		 ParsePartsIC(Text, L";", Treatments);
		 vector<UnicodeString>::iterator itr;
		 for (unsigned int i=0; i<Treatments.size(); i++) {
		   int order;
		   int ID;
		   double dvalue;
		   Variant Value;
		   NEOTOMAPRETREATMENT Pretreatment;
		   vector<UnicodeString> Elements;
		   ParsePartsIC(Treatments[i], L",", Elements);
		   bool err = false;
		   if (TryStrToInt(Elements[0],order)) {
			 if (order <= 0)
			   err = true;
			 }
		   else
			 err = true;
		   if (err) {
			 success = false;
			 UploadForm->OutputError(L"ERROR: " + ColumnName + L" pretreatment order value in isotope grid row " +
			   IntToStr(row) + L" is invalid.");
			 continue;
			 }
		   UnicodeString Treatment = Elements[1].SubString(2,Elements[1].Length()-2);
		   UnicodeString Qualifier;
		   if (Elements[2].Length() > 2)
			 Qualifier = Elements[2].SubString(2,Elements[2].Length()-2);

		   bool found = false;
		   for (unsigned int j=0; j<Items.size(); j++) {
			 if (SameText(Treatment, Items[j].IsoPretreatmentType) && SameText(Qualifier, Items[j].IsoPretreatmentQualifier)) {
			   ID = Items[j].IsoPretreatmentTypeID;
			   if (Elements.size() == 4) {
				 if (TryStrToFloat(Elements[3],dvalue))
				   Value = dvalue;
				 else {
				   success = false;
				   UploadForm->OutputError(L"ERROR: " + ColumnName + L" pretreatment value in isotope grid row " +
					 IntToStr(row) + L" is invalid.");
				   }
				 }
			   else {
				 found = true;
				 Value = Unassigned();
				 }
			   if (success) {
				 found = true;
				 pv[order] = pair<int,double>(ID,Value);
				 }
			   break;
			   }
			 }

		   if (!found) {
			 UnicodeString msg = L"ERROR: " + ColumnName + L" «" + Treatment;
			 if (!Qualifier.IsEmpty())
			   msg += (L"|" + Qualifier);
			 msg += (L"» in isotope grid row " + IntToStr(row) + L" not found in Neotoma.");
			 UploadForm->OutputError(msg);
			 success = false;
			 }
		   }
		 }
	   }
	 }
   else {   // this should never happen, but...
	 UploadForm->OutputError(L"ERROR: Column «" +  ColumnName + L"» not found in isotope grid");
	 success = false;
	 }
   return success;
}
//---------------------------------------------------------------------------

template <class T> bool ValidateIsotope<T>::GetContact(UnicodeString ColumnName)
{
   bool success = true;

   iv.clear();
   int col = GetColumn(isotope, ColumnName);
   if (col != -1) {
	 for (int row=2; row<RowCount; row++) {
	   if (TSSForm->AdvIsotopeStringGrid->Objects[col][row] != NULL) {
		 CONTACT* Contact = (CONTACT*)TSSForm->AdvIsotopeStringGrid->Objects[col][row];
		 iv.push_back(pair<int,int>(row,Contact->NeotomaContactID));
		 vector<CONTACT*>::iterator begin = UploadForm->LinkedContacts.begin();;
		 vector<CONTACT*>::iterator end = UploadForm->LinkedContacts.end();
         if (find(begin, end, Contact) == end)
		   UploadForm->LinkedContacts.push_back(Contact);
		 }
	   }
	 }
   else {   // this should never happen, but...
	 UploadForm->OutputError(L"ERROR: Column «" +  ColumnName + L"» not found in isotope grid");
	 success = false;
	 }
   return success;
}
//---------------------------------------------------------------------------

template <class T> int ValidateIsotope<T>::GetColumn(short isotope, UnicodeString ColumnName)
{
   for (int col = TSSForm->IsoCols[isotope].first; col <= TSSForm->IsoCols[isotope].second; col++) {
	 UnicodeString PlainName = TSSForm->AdvIsotopeStringGrid->StrippedCells[col][1];
	 if (SameText(PlainName, ColumnName))
	   return col;
	 }
   return -1;
}
//---------------------------------------------------------------------------

template <class T> bool ValidateIsotope<T>::GetReps(void)
{
   if (GetInts(L"Reps")) {
	 for (unsigned int i=0; i<iv.size(); i++) {
	   if (FDataRows.count(iv[i].first) > 0)
		 IsoType[iv[i].first].Reps = iv[i].second;
	   }
	 }
   else
	 return false;
   return true;
}
//---------------------------------------------------------------------------

bool TNeotomaUploadForm::ValidateIsotopeDataset(bool is_surface_sample)
{
   bool success = true;
   bool overall_success = true;
   UnicodeString msg;
   map<int,int> SpecimenRows;  // row, SpecimenID

   NeotomaIsoInstrumentationTypes Instrument(ipsJSONS1, TcpClient1);
   StatusBar1->SimpleText = Instrument.WebServiceName();
   if (!Instrument.Execute())
	 return false;

   NeotomaIsoSampleIntroSystemTypes IntroSys(ipsJSONS1, TcpClient1);
   StatusBar1->SimpleText = IntroSys.WebServiceName();
   if (!IntroSys.Execute())
	 return false;

   NeotomaIsoStandardTypes Standards(ipsJSONS1, TcpClient1);
   StatusBar1->SimpleText = Standards.WebServiceName();
   if (!Standards.Execute())
	 return false;

   NeotomaGetIsoMaterialAnalyzedTypes MatAnal(ipsJSONS1, TcpClient1);
   StatusBar1->SimpleText = MatAnal.WebServiceName();
   if (!MatAnal.Execute())
	 return false;

   NeotomaGetIsoSubstrates Substrate(ipsJSONS1, TcpClient1);
   StatusBar1->SimpleText = Substrate.WebServiceName();
   if (!Substrate.Execute())
	 return false;

   NeotomaGetIsoPretreatmentTypes Pretreatments(ipsJSONS1, TcpClient1);
   StatusBar1->SimpleText = Pretreatments.WebServiceName();
   if (!Pretreatments.Execute())
	 return false;

   NeotomaGetIsoVariableScaleIDs Scales(ipsJSONS1, TcpClient1);
   StatusBar1->SimpleText = Scales.WebServiceName();
   if (!Scales.Execute())
	 return false;

   // validate specimen objects
   int RowCount = TSSForm->AdvIsotopeStringGrid->RowCount;
   for (int row=2; row<RowCount; row++) {
	 if (TSSForm->AdvIsotopeStringGrid->Objects[0][row] != NULL) {
	   SPECIMEN* Specimen = (SPECIMEN*)TSSForm->AdvIsotopeStringGrid->Objects[0][row];
	   //OutputLine(L"row = " + IntToStr(row-1) + L". Specimen exists.");
	   UnicodeString Type = TSSForm->AdvIsotopeStringGrid->AllCells[6][row];
	   if (all_specimens.count(Specimen) == 0) {
		 OutputError(L"ERROR: Specimen in isotope grid row " + IntToStr(row-1) + L" does not exist.");
		 success = false;
		 }
	   else {
		 SpecimenRows[row] = Specimen->SpecimenID;  // map of specimen rows and SpecimenIDs
		 SpecimenRowObj[row] = Specimen;            // map of specimen rows and specimen objects
		 }
	   }
	 else {
	   OutputError(L"ERROR: Specimen in isotope grid row " + IntToStr(row-1) + L" does not exist.");
	   success = false;
	   }
	 }
   if (!success)
	 return false;
   OutputLine(L"Isotope specimens validated.");

   for (int row=2; row<RowCount; row++) {
	 UnicodeString Type = TSSForm->AdvIsotopeStringGrid->AllCells[6][row];
	 if (!SameText(Type, L"bulk")) {
	   if (Type.IsEmpty())
		 OutputError(L"ERROR: Type missing in isotope grid row " + IntToStr(row) + L" is not valid.");
	   else if (SameText(Type, L"serial"))
		 OutputError(L"ERROR: Upload of serial isotope samples not yet enabled.");
	   else
		 OutputError(L"ERROR: Type «" + Type + L"» in isotope grid row " + IntToStr(row) + L" is not valid.");
	   success = false;
	   }
	 }
   if (!success)
	 return false;
   OutputLine(L"Isotope types validated.");

   // validate d13C
   if (TSSForm->HTMLCheckBox1->Checked) {     // carbon
	 ValidateIsotope<DELTARATIO> d13C(isoCarbon, L"δ13C", RowCount, TSSForm, this);
	 if (!d13C.GetDataRows(SpecimenRows)) success = false;    // this can be called for each isotope type
	 IsoDataRows.insert(d13C.DataRows.begin(),d13C.DataRows.end());
	 if (!d13C.GetValue()) success = false;
	 if (!d13C.GetSD()) success = false;
	 if (!d13C.GetMass()) success = false;
	 if (!d13C.GetWeightPercent()) success = false;
	 if (!d13C.GetAtomicPercent()) success = false;
	 if (!d13C.GetMaterialAnalyzed(MatAnal.Items)) success = false;
	 if (!d13C.GetSubstrate(Substrate.Items)) success = false;
	 if (!d13C.GetPretreatment(Pretreatments.Items)) success = false;
	 if (!d13C.GetAnalyst()) success = false;
	 if (!d13C.GetLab()) success = false;
	 if (!d13C.GetLabNr()) success = false;
	 if (!d13C.GetScale(Scales.Items)) success = false;
	 if (!d13C.GetReps()) success = false;
	 if (!ValidateIsoMetadata(isoCarbon, L"carbon", Instrument.Items, IntroSys.Items, Standards.Items)) success = false;
	 if (success) {
	   d13C.GetIsoData(delta13C);
	   // ShowMessage(L"delta13C[0].AnalystID = " + IntToStr(delta13C[0].AnalystID));
	   OutputLine(L"δ13C data validated.");
	   }
	 else
	   overall_success = false;
	 }

   if (TSSForm->HTMLCheckBox1->Checked || TSSForm->HTMLCheckBox2->Checked) {     // C:N
	 success = true;
	 ValidateIsotope<ELEMENTRATIO> CN(isoCNratio, L"C:N Ratio", RowCount, TSSForm, this);
	 if (!CN.GetDataRows(SpecimenRows)) success = false;    // this can be called for each isotope type
	 IsoDataRows.insert(CN.DataRows.begin(),CN.DataRows.end());
	 if (!CN.GetValue()) success = false;
	 if (success) {
	   CN.GetIsoData(CNratio);
	   OutputLine(L"C:N data validated.");
	   }
	 else
	   overall_success = false;
	 }

   if (TSSForm->HTMLCheckBox2->Checked) {     // nitrogen
	 success = true;
	 ValidateIsotope<DELTARATIO> d15N(isoNitrogen, L"δ15N", RowCount, TSSForm, this);
	 if (!d15N.GetDataRows(SpecimenRows)) success = false;    // this can be called for each isotope type
	 IsoDataRows.insert(d15N.DataRows.begin(),d15N.DataRows.end());
	 if (!d15N.GetValue()) success = false;
	 if (!d15N.GetSD()) success = false;
	 if (!d15N.GetMass()) success = false;
	 if (!d15N.GetWeightPercent()) success = false;
	 if (!d15N.GetAtomicPercent()) success = false;
	 if (!d15N.GetMaterialAnalyzed(MatAnal.Items)) success = false;
	 if (!d15N.GetSubstrate(Substrate.Items)) success = false;
	 if (!d15N.GetPretreatment(Pretreatments.Items)) success = false;
	 if (!d15N.GetAnalyst()) success = false;
	 if (!d15N.GetLab()) success = false;
	 if (!d15N.GetLabNr()) success = false;
	 if (!d15N.GetScale(Scales.Items)) success = false;
	 if (!d15N.GetReps()) success = false;
	 if (!ValidateIsoMetadata(isoCarbon, L"nitrogen", Instrument.Items, IntroSys.Items, Standards.Items)) success = false;
	 if (success) {
	   d15N.GetIsoData(delta15N);
	   OutputLine(L"δ15N data validated.");
	   }
	 else
	   overall_success = false;
	 }

   if (TSSForm->HTMLCheckBox3->Checked) {     // oxygen
	 success = true;
	 ValidateIsotope<DELTARATIO> d18O(isoOxygen, L"δ18O", RowCount, TSSForm, this);
	 if (!d18O.GetDataRows(SpecimenRows)) success = false;    // this can be called for each isotope type
	 IsoDataRows.insert(d18O.DataRows.begin(),d18O.DataRows.end());
	 if (!d18O.GetValue()) success = false;
	 if (!d18O.GetSD()) success = false;
	 if (!d18O.GetMass()) success = false;
	 if (!d18O.GetWeightPercent()) success = false;
	 if (!d18O.GetAtomicPercent()) success = false;
	 if (!d18O.GetMaterialAnalyzed(MatAnal.Items)) success = false;
	 if (!d18O.GetSubstrate(Substrate.Items)) success = false;
	 if (!d18O.GetPretreatment(Pretreatments.Items)) success = false;
	 if (!d18O.GetAnalyst()) success = false;
	 if (!d18O.GetLab()) success = false;
	 if (!d18O.GetLabNr()) success = false;
	 if (!d18O.GetScale(Scales.Items)) success = false;
	 if (!d18O.GetReps()) success = false;
	 if (!ValidateIsoMetadata(isoCarbon, L"oxygen", Instrument.Items, IntroSys.Items, Standards.Items)) success = false;
	 if (success) {
	   d18O.GetIsoData(delta18O);
	   OutputLine(L"δ18O data validated.");
	   }
	 else
	   overall_success = false;
	 }

   if (TSSForm->HTMLCheckBox3->Checked || TSSForm->HTMLCheckBox5->Checked) {     // O:H
	 success = true;
	 ValidateIsotope<ELEMENTRATIO> OH(isoOHratio, L"O:H Ratio", RowCount, TSSForm, this);
	 if (!OH.GetDataRows(SpecimenRows)) success = false;    // this can be called for each isotope type
	 IsoDataRows.insert(OH.DataRows.begin(),OH.DataRows.end());
	 if (!OH.GetValue()) success = false;
	 if (success) {
	   OH.GetIsoData(OHratio);
	   OutputLine(L"O:H data validated.");
	   }
	 else
	   overall_success = false;
	 }

   if (TSSForm->HTMLCheckBox5->Checked) {     // hydrogen
	 success = true;
	 ValidateIsotope<DELTARATIO> dD(isoHydrogen, L"δD", RowCount, TSSForm, this);
	 if (!dD.GetDataRows(SpecimenRows)) success = false;    // this can be called for each isotope type
	 IsoDataRows.insert(dD.DataRows.begin(),dD.DataRows.end());
	 if (!dD.GetValue()) success = false;
	 if (!dD.GetSD()) success = false;
	 if (!dD.GetMass()) success = false;
	 if (!dD.GetWeightPercent()) success = false;
	 if (!dD.GetAtomicPercent()) success = false;
	 if (!dD.GetMaterialAnalyzed(MatAnal.Items)) success = false;
	 if (!dD.GetSubstrate(Substrate.Items)) success = false;
	 if (!dD.GetPretreatment(Pretreatments.Items)) success = false;
	 if (!dD.GetAnalyst()) success = false;
	 if (!dD.GetLab()) success = false;
	 if (!dD.GetLabNr()) success = false;
	 if (!dD.GetScale(Scales.Items)) success = false;
	 if (!dD.GetReps()) success = false;
	 if (!ValidateIsoMetadata(isoHydrogen, L"hydrogen", Instrument.Items, IntroSys.Items, Standards.Items)) success = false;
	 if (success) {
	   dD.GetIsoData(deltaD);
	   OutputLine(L"δD data validated.");
	   }
	 else
	   overall_success = false;
	 }

   if (TSSForm->HTMLCheckBox4->Checked) {     // sulfer
	 success = true;
	 ValidateIsotope<DELTARATIO> d34S(isoSulfur, L"δ34S", RowCount, TSSForm, this);
	 if (!d34S.GetDataRows(SpecimenRows)) success = false;    // this can be called for each isotope type
	 IsoDataRows.insert(d34S.DataRows.begin(),d34S.DataRows.end());
	 if (!d34S.GetValue()) success = false;
	 if (!d34S.GetSD()) success = false;
	 if (!d34S.GetMass()) success = false;
	 if (!d34S.GetWeightPercent()) success = false;
	 if (!d34S.GetAtomicPercent()) success = false;
	 if (!d34S.GetMaterialAnalyzed(MatAnal.Items)) success = false;
	 if (!d34S.GetSubstrate(Substrate.Items)) success = false;
	 if (!d34S.GetPretreatment(Pretreatments.Items)) success = false;
	 if (!d34S.GetAnalyst()) success = false;
	 if (!d34S.GetLab()) success = false;
	 if (!d34S.GetLabNr()) success = false;
	 if (!d34S.GetScale(Scales.Items)) success = false;
	 if (!d34S.GetReps()) success = false;
	 if (!ValidateIsoMetadata(isoSulfur, L"sulfur", Instrument.Items, IntroSys.Items, Standards.Items)) success = false;
	 if (success) {
	   d34S.GetIsoData(delta34S);
	   OutputLine(L"δ34S data validated.");
	   }
	 else
	   overall_success = false;
	 }

   if (TSSForm->HTMLCheckBox6->Checked) {     // strontium
	 success = true;
	 ValidateSrRatio<SrRATIO> Sr(isoStrontium, L"87Sr/86Sr", RowCount, TSSForm, this);
	 if (!Sr.GetDataRows(SpecimenRows)) success = false;    // this can be called for each isotope type
     IsoDataRows.insert(Sr.DataRows.begin(),Sr.DataRows.end());
	 if (!Sr.GetValue()) success = false;
	 if (!Sr.GetSD()) success = false;
	 if (!Sr.GetMass()) success = false;
	 if (!Sr.GetWeightPercent()) success = false;
	 if (!Sr.GetAtomicPercent()) success = false;
	 if (!Sr.GetTotalSr()) success = false;
	 if (!Sr.GetMaterialAnalyzed(MatAnal.Items)) success = false;
	 if (!Sr.GetSubstrate(Substrate.Items)) success = false;
	 if (!Sr.GetPretreatment(Pretreatments.Items)) success = false;
	 if (!Sr.GetAnalyst()) success = false;
	 if (!Sr.GetLab()) success = false;
	 if (!Sr.GetLabNr()) success = false;
	 if (!Sr.GetReps()) success = false;
	 if (!ValidateIsoMetadata(isoStrontium, L"strontium", Instrument.Items, IntroSys.Items, Standards.Items)) success = false;
	 if (success) {
	   Sr.GetIsoData(Sr87Sr86);
	   OutputLine(L"Sr87/Sr86 data validated.");
	   }
	 else
	   overall_success = false;
	 }

   // get isotope variable IDs
   if (delta13C.size() > 0) {
	 if (!GetIsotopeVariableID(IsoVarID.d13C, L"δ13C", L"per mille"))
	   overall_success = false;
	 }
   if (delta15N.size() > 0) {
	 if (!GetIsotopeVariableID(IsoVarID.d15N, L"δ15N", L"per mille"))
	   overall_success = false;
	 }
   if (delta18O.size() > 0) {
	 if (!GetIsotopeVariableID(IsoVarID.d18O, L"δ18O", L"per mille"))
	   overall_success = false;
	 }
   if (deltaD.size() > 0) {
	 if (!GetIsotopeVariableID(IsoVarID.dD, L"δD", L"per mille"))
	   overall_success = false;
	 }
   if (delta34S.size() > 0) {
	 if (!GetIsotopeVariableID(IsoVarID.d34S, L"δ34S", L"per mille"))
	   overall_success = false;
	 }
   if (Sr87Sr86.size() > 0) {
	 if (!GetIsotopeVariableID(IsoVarID.Sr87Sr86, L"87Sr/86Sr", L"ratio"))
	   overall_success = false;
	 if (!GetIsotopeVariableID(IsoVarID.TotalSr, L"Total Sr", L"ppm"))
	   overall_success = false;
	 }
   if (CNratio.size() > 0) {
	 if (!GetIsotopeVariableID(IsoVarID.CN, L"Carbon:Nitrogen", L"ratio"))
	   overall_success = false;
	 }
   if (OHratio.size() > 0) {
	 if (!GetIsotopeVariableID(IsoVarID.OH, L"Oxygen:Hydrogen", L"ratio"))
	   overall_success = false;
	 }

   if (!overall_success)
	 return overall_success;

   // get isotope sample ages
   if (!is_surface_sample) {
	 // NeotomaTaxaDated
	 // SpecimenRows[row] = Specimen->SpecimenID;  // map of specimen rows and SpecimenIDs
	 // SpecimenRowObj[row] = Specimen;            // map of specimen rows and specimen objects

	 // vector<NEOTOMATAXONDATE> NeotomaTaxaDated;
	 // NeotomaTaxaDated[0].SpecimenID
	 // NeotomaTaxaDated[0].GeochronID
	 // vector<NEOTOMAGEOCHRON> NeotomaGeochrons;
	 // NeotomaGeochrons[0].GeochronID
	 // AGEMODEL* AgeModel = TSSForm->AgeModelList->AgeModels[i];
	 // vector<NEOTOMAANALUNIT> NeotomaAnalysisUnits;

	 // map<int,NEOTOMASAMPLEAGE> NeotomaSampleAges;  // map<ChronNo, map<SampleID,NEOTOMAAGE> >

	 /*
     SampleID
	 ChronologyID
	 Age              NEOTOMAAGE
	 AgeYounger
	 AgeOlder
	 -------------
	 int TempChronID = NeotomaChrons[i].ChronologyID;
	 int ChronNo = TiliaChronIDs[TempChronID];
	 NeotomaChronIDs[TempChronID] = NeotomaChronID;
	 */

	 IsoChronologyID = 0;
	 //map<int,NEOTOMAAGE> IsoSpecimenAges;   // LocalSpecimenID, NEOTOMAAGE
	 //OutputLine(L"IsoChronologyID = " + IntToStr(IsoChronologyID));

	 // find calendar or calibrated calendar year age model

	 // TiliaChronIDs[NeotomaChron.ChronologyID] = NeotomaAgeModels[i].ChronNumber;   TiliaChronIDs[23496] = 1
	 //	NeotomaChronIDs[NeotomaChron.ChronologyID] = NeotomaChron.ChronologyID;       TiliaChronIDs[23496] = 23496

	 if (NeotomaChrons.size() == 0) {  // this happens if isotope dataset being added to existing collunit
	   map<int,int>::iterator itr = TiliaChronIDs.begin();
	   //ShowMessage(L"TiliaChronIDs: " + IntToStr(itr->first) + L", " + IntToStr(itr->second));
	   //itr = NeotomaChronIDs.begin();
	   //ShowMessage(L"TiliaChronIDs: " + IntToStr(itr->first) + L", " + IntToStr(itr->second));

	   for (unsigned int i=0; i<NeotomaAgeModels.size(); i++) {
		 //ShowMessage(L"ChronNumber = " + IntToStr(NeotomaAgeModels[i].ChronNumber) +
		 //  L", NeotomaChronologyID = "  + IntToStr(NeotomaAgeModels[i].NeotomaChronologyID));
		 if (NeotomaAgeModels[i].Default && (SameText(NeotomaAgeModels[i].AgeUnits,L"Calendar years BP") ||
			 SameText(NeotomaAgeModels[i].AgeUnits,L"Calibrated radiocarbon years BP"))) {
		   for (itr = TiliaChronIDs.begin(); itr != TiliaChronIDs.end(); itr++) {
			 if (itr->second == NeotomaAgeModels[i].ChronNumber) {
			   IsoChronologyID = itr->first;
			   break;
			   }
		     }
		   }
		 if (IsoChronologyID != 0) break;
		 }
	   }
	 else {
	   for (unsigned int i=0; i<NeotomaAgeModels.size(); i++) {
		 if (NeotomaChrons[i].IsDefault && (NeotomaChrons[i].AgeTypeID == 2 || NeotomaChrons[i].AgeTypeID == 3)) {
		   IsoChronologyID = NeotomaChrons[i].ChronologyID;
		   break;
		   }
		 }
	   }

	 if (IsoChronologyID != 0) {
	   map<int,int>::iterator itr;
	   for (itr = SpecimenRows.begin(); itr != SpecimenRows.end(); itr++) {
		 int SpecimenID = itr->second;
		 //OutputLine(L"row = " + IntToStr(itr->first) + L", SpecimenID = " + IntToStr(SpecimenID));
		 for (unsigned int i = 0; i < NeotomaTaxaDated.size(); i++) {
		   if (NeotomaTaxaDated[i].SpecimenID == SpecimenID) {
			 NEOTOMAAGE NeotomaAge;
			 if (!NeotomaTaxaDated[i].Cal.Age.IsEmpty())
			   NeotomaAge.Age = (double)NeotomaTaxaDated[i].Cal.Age;
			 if (!NeotomaTaxaDated[i].Cal.AgeOlder.IsEmpty())
			   NeotomaAge.AgeOlder = (double)NeotomaTaxaDated[i].Cal.AgeOlder;
			 if (!NeotomaTaxaDated[i].Cal.AgeYounger.IsEmpty())
			   NeotomaAge.AgeYounger = (double)NeotomaTaxaDated[i].Cal.AgeYounger;
			 IsoSpecimenAges[SpecimenID] = NeotomaAge;
			 break;
			 }
		   }
		 }
	   //msg = L"SpecimenRows.size = " + IntToStr((int)SpecimenRows.size()) +
	   //		 L", IsoSpecimenAges.size = " + IntToStr((int)IsoSpecimenAges.size());
	   //OutputLine(msg);

	   int nSpecimenAges = IsoSpecimenAges.size();

	   int ChronNo = TiliaChronIDs[IsoChronologyID];

	   // get ages for specimens not directly dated
	   for (itr = SpecimenRows.begin(); itr != SpecimenRows.end(); itr++) {
		 int SpecimenID = itr->second;
		 //OutputLine(L"1. SpecimenID = " + IntToStr(SpecimenID));
		 if (IsoSpecimenAges.count(SpecimenID) == 0) {
		   int SampleID = SpecimenRowObj[itr->first]->SampleID;
		   if (NeotomaSampleAges[ChronNo].count(SampleID) == 1) {
			 IsoSpecimenAges[SpecimenID] = NeotomaSampleAges[ChronNo][SampleID];
			 // OutputLine(L"2. SpecimenID = " + IntToStr(SpecimenID));
			 }
		   }
		 }

	   int nChronAges = IsoSpecimenAges.size() - nSpecimenAges;
	   bool warning = false;
	   msg = L"Sample ages generated for specimen stable isotope dataset: ";
	   if (nSpecimenAges > 0 && nChronAges > 0) {
		 msg += (IntToStr(nSpecimenAges) + L" directly dated specimens, " +
				 IntToStr(nChronAges) + L" ages from Chron " + IntToStr(ChronNo) + L".");
		 }
	   else if (nSpecimenAges > 0 && nChronAges == 0) {
		 msg += (IntToStr(nSpecimenAges) + L" directly dated specimens.");
		 }
	   else if (nSpecimenAges == 0 && nChronAges > 0) {
		 msg += (IntToStr(nChronAges) + L" ages from Chron " + IntToStr(ChronNo) + L".");
		 }
	   else {
		 msg = L"WARNING: No sample ages generated for specimen stable isotope dataset";
		 warning = true;
		 }

	   if (!warning)
		 OutputLine(msg);
	   else
		 OutputWarning(msg);
	   }
	 }

   return overall_success;
}
//---------------------------------------------------------------------------

bool TNeotomaUploadForm::GetIsotopeVariableID(int& VariableID, UnicodeString Taxon,
	UnicodeString Units)
{
   bool found = false;

   NeotomaVariableByComponentNames VarID(ipsJSONS1, TcpClient1);
   VarID.AddParam(L"TAXON", Taxon);
   VarID.AddParam(L"UNITS", Units);
   StatusBar1->SimpleText = VarID.WebServiceName();
   if (VarID.Execute()) {
	 if (VarID.Size() == 1) {
	   VariableID = VarID.Items[0];
	   found = true;
	   OutputLine(L"VariableID for «" + Taxon + L" " + Units + L"» = " + IntToStr(VariableID));
	   }
	 else
	   OutputError(L"ERROR: VariableID for «" + Taxon + L" " + Units + L"» not found in Neotoma Variables table.");
	 }
   return found;
}
//---------------------------------------------------------------------------

/*
class ISOMETADATA
{
public:
	Variant TechError;
	Variant TechErrorSD;
	Variant LongTermError;
	UnicodeString Instrument;
	UnicodeString IntroSystem;
	vector<pair<UnicodeString,Variant> > Standards;
	UnicodeString SrLocalValue;
	UnicodeString SrLocalGeolContext;
	UnicodeString Notes;
public:
	ISOMETADATA() { }
	bool IsEmpty(void);
};
*/
bool TNeotomaUploadForm::ValidateIsoMetadata(short isotope, UnicodeString element,
	map<int,UnicodeString>& Instrument, map<int,UnicodeString>& IntroSys,
	vector<NEOTOMAISOSTANDARD>& Standards)
{
   UnicodeString msg;

   if (TSSForm->IsoMetadata.count(isotope) == 0) {
	 OutputWarning(L"WARNING: No instrumentation or standards metadata entered for " + element + L" isotopes.");
	 return true;
	 }

   ISOMETADATA& IsoMetadata = TSSForm->IsoMetadata[isotope];
   if (IsoMetadata.IsEmpty()) {
	 OutputWarning(L"WARNING: No instrumentation or standards metadata entered for " + element + L" isotopes.");
	 return true;
	 }

   map<int,UnicodeString>::iterator itr;
   if (!IsoMetadata.Instrument.IsEmpty()) {
	 for (itr = Instrument.begin(); itr != Instrument.end(); itr++) {
	   if (SameText(IsoMetadata.Instrument,itr->second)) {
		 IsoMetadata.IsoInstrumentationTypeID = itr->first;
		 break;
		 }
	   }
	 if (IsoMetadata.IsoInstrumentationTypeID != -1) {
	   msg = L"Instrumentation for " + element + L" validated. IsoInstrumentationTypeID = " +
			 IntToStr(IsoMetadata.IsoInstrumentationTypeID);
	   OutputLine(msg);
	   }
	 else {
	   msg = L"ERROR: Instrumentation for " + element + L" «" + IsoMetadata.Instrument +
			 L"» not in Neotoma IsoInstrumentationTypes table.";
	   OutputError(msg);
	   }
	 }

   if (!IsoMetadata.IntroSystem.IsEmpty()) {
	 for (itr = IntroSys.begin(); itr != IntroSys.end(); itr++) {
	   if (SameText(IsoMetadata.IntroSystem,itr->second)) {
		 IsoMetadata.IsoSampleIntroSystemTypeID = itr->first;
		 break;
		 }
	   }
	 if (IsoMetadata.IsoSampleIntroSystemTypeID != -1) {
	   msg = L"Sample Introduction System for " + element + L" validated. IsoSampleIntroSystemTypeID = " +
			 IntToStr(IsoMetadata.IsoSampleIntroSystemTypeID);
	   OutputLine(msg);
	   }
	 else {
	   msg = L"ERROR: Sample Introduction System for " + element + L" «" + IsoMetadata.IntroSystem +
			 L"» not in Neotoma IsoSampleIntroSystemTypes table.";
	   OutputError(msg);
	   }
	 }

   if (IsoMetadata.Standards.size() > 0) {
	 for (unsigned int i=0; i<IsoMetadata.Standards.size(); i++) {
	   if (!IsoMetadata.Standards[i].second.IsEmpty()) {
		 double Value = VariantToDouble(IsoMetadata.Standards[i].second, NaN);
		 if (!IsNan(Value)) {
		   bool found = false;
		   for (unsigned j = 0; j < Standards.size(); j++) {
			 if (SameText(IsoMetadata.Standards[i].first, Standards[j].IsoStandardType)) {
			   IsoMetadata.IsoStandards.push_back(pair<int,double>(Standards[j].IsoStandardTypeID,Value));
			   msg = L"Standard «" + Standards[j].IsoStandardType + L"» validated for " + element +
					 L". IsoStandardTypeID = " + IntToStr(Standards[j].IsoStandardTypeID) +
					 L", Value = " + FloatToStr(Value) + L".";
			   OutputLine(msg);
			   found = true;
			   break;
			   }
			 }
		   if (!found) {
			 msg = L"ERROR: Standard «" + IsoMetadata.Standards[i].first + L"» for " + element +
				   L" not found in Neotoma IsoStandardTypes table.";
			 OutputError(msg);
			 }
		   }
		 else {
		   msg = L"WARNING: No value or invalid value entered for " + element +
				 L" standard «" + IsoMetadata.Standards[i].first + L"». Standard ignored.";
		   OutputWarning(msg);
		   }
		 }
	   }
	 }

   return true;
}
//---------------------------------------------------------------------------
