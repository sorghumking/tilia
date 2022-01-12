//---------------------------------------------------------------------------

#include <vcl.h>
#include "pch.h"
#pragma hdrstop

#include "TIUpload3.h"
#ifndef TIChkVarUnitsFrmH
#include "TIChkVarUnitsFrm.h"
#endif
#ifndef TIChkVarFrmH
#include "TIChkVarFrm.h"
#endif
#ifndef TISynFrmH
#include "TISynFrm.h"
#endif
#ifndef TNFindTaxonH
#include "TNFindTaxon.h"
#endif

//---------------------------------------------------------------------------

#pragma package(smart_init)

bool TNeotomaUploadForm::AssembleIsoDataset(void)
{
   int BeginRow = 0;
   int EndRow;
   UnicodeString VarCode;

   int nrows = TSSForm->AbsContentRowCount(TSSForm->ProfGrid1);
   int start = TSSForm->AbsHeaderRowCount(TSSForm->ProfGrid1);

   UnicodeString DatasetType = TSSForm->ProfGrid1->AbsoluteCells[1][1]->Text;
   if (SameText(DatasetType,L"Stable isotope"))
	 BeginRow = 3;
   else {
	 for (int row=start; row<=nrows; row++) {
	   VarCode = TSSForm->ProfGrid1->AbsoluteCells[1][row]->Text;
	   if (SameText(VarCode, L"#Data.Type")) {
		 DatasetType = TSSForm->ProfGrid1->AbsoluteCells[2][row]->Text;
		 if (SameText(DatasetType,L"Stable isotope")) {
		   BeginRow = row+1;
		   break;
		   }
		 }
	   }
	 }
   if (BeginRow > 0) {
	 for (int row=BeginRow; row<=nrows; row++) {
	   VarCode = TSSForm->ProfGrid1->AbsoluteCells[1][row]->Text;
	   if (SameText(VarCode, L"#Data.Type"))
		 break;
	   else
		 EndRow = row;
	   }

	 for (int row = BeginRow; row <= EndRow; row++) {
	   VarCode = TSSForm->ProfGrid1->AbsoluteCells[1][row]->Text;
	   if (VarCode[1] != L'#') {
		 ISOSSDATA IsoData;
		 IsoData.Row = row;
		 IsoData.Code = TSSForm->ProfGrid1->AbsoluteCells[1][row]->Text;
		 IsoData.Name = TSSForm->ProfGrid1->AbsoluteCells[2][row]->Text;
		 IsoData.Element = TSSForm->ProfGrid1->AbsoluteCells[3][row]->Text;
		 IsoDataset.push_back(IsoData);
		 }
	   }
	 }

   bool errors = false;
   if (IsoDataset.size() > 0) {
	 for (int row = BeginRow; row <= EndRow; row++) {
	   VarCode = TSSForm->ProfGrid1->AbsoluteCells[1][row]->Text;
	   //if (VarCode[1] == L'#') [
	   if (SameText(VarCode.SubString(1,5),L"#iso.")) {
		 UnicodeString VarCode1 = VarCode;
		 VarCode.Delete(1,5);
		 int pos = VarCode.Pos(L".");
		 UnicodeString IsoCode = VarCode.SubString(1,pos-1);
		 UnicodeString MetadataCode = VarCode.Delete(1,pos);
		 UnicodeString Element = TSSForm->ProfGrid1->AbsoluteCells[3][row]->Text;
		 //ShowMessage(L"VarCode = " + VarCode + L", IsoCode = " + IsoCode + L", MetadataCode = " + MetadataCode);
		 bool found = false;
		 for (unsigned int i=0; i<IsoDataset.size(); i++) {
		   if (SameText(IsoCode,IsoDataset[i].Code)) {
			 if (SameText(Element,IsoDataset[i].Element)) {
			   //ShowMessage(L"IsoCode = " + IsoCode + L", Element = " + Element + L", VarCode1 = " + VarCode1);
			   IsoDataset[i].MetadataCodes[row] = pair<UnicodeString,UnicodeString>(VarCode1,MetadataCode);
			   found = true;
			   }
			 }
		   }
		 if (!found) {
		   UnicodeString msg = L"ERROR: Stable isotope metadata in row " + IntToStr(row) +
			 L" not associated with isotope data row.";
		   OutputError(msg);
		   errors = true;
		   }
		 }
	   }

	 // validate isotope metadata
	 int start = TSSForm->AbsHeaderColCount(TSSForm->ProfGrid1);
	 int ncols = TSSForm->AbsContentColCount(TSSForm->ProfGrid1);
	 map<int,pair<UnicodeString,UnicodeString> >::iterator itr;
	 for (unsigned int i=0; i<IsoDataset.size(); i++) {
	   for (itr = IsoDataset[i].MetadataCodes.begin(); itr != IsoDataset[i].MetadataCodes.end(); itr++) {
		 int row = itr->first;
		 UnicodeString MetadataItem = itr->second.second;
		 if (SameText(MetadataItem,L"SD")) {
		   for (int col=start; col<=ncols; col++) {
			 TProfGridCell* Cell = TSSForm->ProfGrid1->AbsoluteCells[col][row];
			 if (!Cell->IsEmpty()) {
			   Variant Value = Cell->Value;
			   if (Value.Type() != varDouble) {
				 OutputError(L"ERROR: Cell " + Cell->A1Name + L" contains an invalid value: «" +
					 Cell->Text + L"». Numerical value expected."  );
				 errors = true;
				 }
			   }
			 }
		   }
		 }
	   }
	 if (!errors)
	   OutputLine(L"Stable isotope metadata validated.");
	 }

   SetProgressBarPosition();
   Screen->Cursor = crDefault;
   return !errors;
}
//---------------------------------------------------------------------------
/*
typedef struct
{
  int Row;
  UnicodeString Code;
  UnicodeString Name;
  UnicodeString Element;
  map<int,pair<UnicodeString,UnicodeString> > MetadataCodes;  // row, <complete code, code>, e.g. #dD.SD, SD
} ISOSSDATA;
*/

bool TNeotomaUploadForm::ValidateSSMetadata(void)
{
   vector<UnicodeString> SSMD;
   SSMD.push_back(L"#Site.Name");
   SSMD.push_back(L"#Site.LatN");
   SSMD.push_back(L"#Site.LatS");
   SSMD.push_back(L"#Site.LongW");
   SSMD.push_back(L"#Site.LongE");
   SSMD.push_back(L"#Site.GeoPol1");
   SSMD.push_back(L"#Site.GeoPol2");
   SSMD.push_back(L"#Site.GeoPol3");
   SSMD.push_back(L"#Site.Admin");
   SSMD.push_back(L"#Site.Altitude");
   SSMD.push_back(L"#Site.Area");
   SSMD.push_back(L"#Site.Desc");
   SSMD.push_back(L"#Site.Notes");
   SSMD.push_back(L"#Lake.MaxDep");
   SSMD.push_back(L"#Lake.MeanDep");
   SSMD.push_back(L"#Lake.Area");
   SSMD.push_back(L"#Lake.ShoreLen");
   SSMD.push_back(L"#Lake.Length");
   SSMD.push_back(L"#Lake.Volume");
   SSMD.push_back(L"#Lake.WtrShdAg");
   SSMD.push_back(L"#Lake.WtrShdArea");
   SSMD.push_back(L"#Lake.WtrShdDistb");
   SSMD.push_back(L"#Lake.WtrShdWater");
   SSMD.push_back(L"#Lake.WtrShdNonResUrb");
   SSMD.push_back(L"#Lake.WtrShdUrb");
   SSMD.push_back(L"#Lake.WtrShdBarren");
   SSMD.push_back(L"#Lake.WtrShdForest");
   SSMD.push_back(L"#Lake.WtrShdMine");
   SSMD.push_back(L"#Lake.WtrShdLake");
   SSMD.push_back(L"#Lake.WtrShedWetland");
   SSMD.push_back(L"#Lake.WtrShedGrass");
   SSMD.push_back(L"#Lake.WtrShedPast");
   SSMD.push_back(L"#Lake.WtrShedShrub");
   SSMD.push_back(L"#Lake.WtrShedWaterIncLake");
   SSMD.push_back(L"#Coll.Handle");
   SSMD.push_back(L"#Coll.Name");
   SSMD.push_back(L"#Coll.Type");
   SSMD.push_back(L"#Coll.Device");
   SSMD.push_back(L"#Coll.Contacts");
   SSMD.push_back(L"#Coll.Date");
   SSMD.push_back(L"#Coll.Loc");
   SSMD.push_back(L"#Coll.GPSLat");
   SSMD.push_back(L"#Coll.GPSLong");
   SSMD.push_back(L"#Coll.GPSErr");
   SSMD.push_back(L"#Coll.GPSAlt");
   SSMD.push_back(L"#Coll.DepEnv");
   SSMD.push_back(L"#Coll.Substrate");
   SSMD.push_back(L"#Coll.Angle");
   SSMD.push_back(L"#Coll.Aspect");
   SSMD.push_back(L"#Coll.WaterDep");
   SSMD.push_back(L"#Coll.Notes");
   SSMD.push_back(L"#Anal.Thick");
   SSMD.push_back(L"#Anal.Facies");
   SSMD.push_back(L"#Anal.DepAgent");
   SSMD.push_back(L"#Anal.Mixed");
   SSMD.push_back(L"#Anal.IGSN");
   SSMD.push_back(L"#Anal.Notes");
   SSMD.push_back(L"#Anal.Bottom");
   SSMD.push_back(L"#Anal.DepBot");
   SSMD.push_back(L"#Anal.NameBot");
   SSMD.push_back(L"#Samp.Name");
   SSMD.push_back(L"#Samp.Keywords");
   SSMD.push_back(L"#Samp.DateSamp");
   SSMD.push_back(L"#Samp.Analyst");
   SSMD.push_back(L"#Samp.DateAnal");
   SSMD.push_back(L"#Samp.Taxon");
   SSMD.push_back(L"#Samp.LabNum");
   SSMD.push_back(L"#Samp.Method");
   SSMD.push_back(L"#Samp.Notes");
   SSMD.push_back(L"#Data.Type");

   // Add IsoDataset metadata codes
   if (IsoDataset.size() > 0) {
	 map<int,pair<UnicodeString,UnicodeString> >::iterator itr;
	 for (unsigned int i=0; i<IsoDataset.size(); i++) {
	   for (itr = IsoDataset[i].MetadataCodes.begin(); itr != IsoDataset[i].MetadataCodes.end(); itr++)
		 SSMD.push_back(itr->second.first);
	   }
	 }

   UnicodeString msg, msg2;
   int nrows = TSSForm->AbsContentRowCount(TSSForm->ProfGrid1);
   TProfGrid* ProfGrid = TSSForm->ProfGrid1;
   for (int row=3; row<=nrows; row++) {
	 UnicodeString Code = ProfGrid->AbsoluteCells[1][row]->Value;
	 if (!Code.IsEmpty()) {
	   if (Code[1] == L'#') {
		 bool found = false;
		 if (SameText(Code, L"#Analyst")) {
		   UnicodeString SampAnalyst = L"#Samp.Analyst";  // this way to accommodate WideString
		   ProfGrid->AbsoluteCells[1][row]->Value = SampAnalyst;
		   OutputNote(L"NOTE: Obsolete metadata code «#Analyst» in row " + IntToStr(row) +
			 L" changed to «#Samp.Analyst».");
		   found = true;
		   }
		 else if (SameText(Code, L"#Thick")) {
		   UnicodeString AnalThick = L"#Anal.Thick";
		   ProfGrid->AbsoluteCells[1][row]->Value = AnalThick;
		   OutputNote(L"NOTE: Obsolete metadata code «#Thick» in row " + IntToStr(row) +
			 L" changed to «#Anal.Thick».");
		   found = true;
		   }
		 else if (SameText(Code, L"#Samp.Taxon")) {     // validate sampled taxon
		   found = true;
		   set<UnicodeString> TaxaNames;
		   int start = TSSForm->AbsHeaderColCount(TSSForm->ProfGrid1);
		   int ncols = TSSForm->AbsContentColCount(TSSForm->ProfGrid1);
		   TProfGrid* ProfGrid = TSSForm->ProfGrid1;
		   for (int col=start; col<=ncols; col++) {
			 UnicodeString TaxonName = ProfGrid->AbsoluteCells[col][row]->Text;
			 if (!TaxonName.IsEmpty()) {
			   if (TaxaNames.count(TaxonName) == 0)
				 TaxaNames.insert(TaxonName);
			   }
			 }
		   if (TaxaNames.size() > 0) {
			 UnicodeString TaxaList;
			 set<UnicodeString>::iterator itr;
			 for (itr = TaxaNames.begin(); itr != TaxaNames.end(); itr++) {
			   if (!TaxaList.IsEmpty())
				 TaxaList += L"$";
			   TaxaList += *itr;
			   }
			 NeotomaTaxaByNameList NeotomaTaxa(ipsJSONS1, TcpClient1);
			 NeotomaTaxa.AddParam(L"TAXANAMES", TaxaList);
			 StatusBar1->SimpleText = NeotomaTaxa.WebServiceName();
			 if (!NeotomaTaxa.Execute())
			   return false;

			 // check that all TaxaNames are in NeotomaTaxa.Items
			 bool error = false;
			 if (TaxaNames.size() != NeotomaTaxa.Size()) {
			   for (int col=start; col<=ncols; col++) {
				 UnicodeString TaxonName = ProfGrid->AbsoluteCells[col][row]->Text;
				 if (!TaxonName.IsEmpty()) {
				   bool taxon_found = false;
				   for (unsigned int i=0; i < NeotomaTaxa.Size(); i++) {
					 if (SameText(TaxonName,NeotomaTaxa.Items[i].TaxonName)) {
					   taxon_found = true;
					   break;
					   }
					 }
				   if (!taxon_found) {
					 error = true;
					 msg = L"ERROR: Sample taxon «" + TaxonName + L"» in cell " +
					       ProfGrid->AbsoluteCells[col][row]->A1Name +
						   L" is not int the Neotoma Taxa table.";
					 OutputError(msg);
					 }
				   }
				 }
			   }

			 if (!error) {
			   for (unsigned int i=0; i<NeotomaTaxa.Size(); i++)
				 SampledTaxa[NeotomaTaxa.Items[i].TaxonName] = NeotomaTaxa.Items[i].TaxonID;
			   OutputLine(L"Sampled taxa validated.");
			   }
			 }
		   }
		 else if (SameText(Code, L"#Samp.Keywords")) {  //  validate keywords in all samples
		   found = true;
		   if (!GetNeotomaKeywords())
			 return false;
		   int start = TSSForm->AbsHeaderColCount(TSSForm->ProfGrid1);
		   int ncols = TSSForm->AbsContentColCount(TSSForm->ProfGrid1);
		   TProfGrid* ProfGrid = TSSForm->ProfGrid1;
		   bool errors = false;
		   for (int col=start; col<=ncols; col++) {
			 TProfGridCell* Cell = ProfGrid->AbsoluteCells[col][row];
			 UnicodeString KeywordList = Cell->Value;
			 if (!KeywordList.IsEmpty()) {
			   vector<UnicodeString> Keywords;
			   ParsePartsIC(KeywordList, L";", Keywords);
			   for (unsigned int i=0; i<Keywords.size(); i++) {
				 bool found = false;
				 map<int,UnicodeString>::iterator itr;
				 for (itr = NeotomaKeywords.begin(); itr != NeotomaKeywords.end(); itr++) {
				   if (SameText(itr->second, Keywords[i])) {
					 found = true;
					 break;
					 }
				   }
				 // if (TiliaKeywords.count(Keywords[i].LowerCase()) == 0) [
				 if (!found) {
				   errors = true;
				   msg = L"Keyword «" + Keywords[i] + L"» in cell " + Cell->A1Name +
					 L" is not a valid Neotoma sample keyword.";
				   OutputError(L"ERROR: " + msg);
				   if (MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbIgnore << mbAbort, 0) == mrAbort)
					 return false;
				   }
				 }
			   }
			 }
		   if (!errors)
			 OutputLine(L"Keywords validated.");
		   }
		 else if (SameText(Code.SubString(1,11), L"#Anal.Depth")) {
		   found = true;
		   if (Code.Length() > 11) {
			 UnicodeString DepthStr = Code;
			 DepthStr.Delete(1,11);
			 int DepthNo;
			 if (TryStrToInt(DepthStr,DepthNo)) {
			   if (DepthNo > 9 || DepthNo < 1) {
				 msg = L"Number in metadata code «" + Code + L"» in row " +
				   IntToStr(row) + L" must be in the range 1-9.";
				 OutputError(L"ERROR: " + msg);
				 if (MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbIgnore << mbAbort, 0) == mrAbort)
				   return false;
				 }
			   }
			 else {
			   msg = L"Depth metadata code «" + Code + L"» in row " + IntToStr(row) +
				 L" is not formatted correctly.";
			   msg2 += L"Must be in the form «#Anal.DepthX», where X is an integer number 1-9.";
			   OutputError(L"ERROR: " + msg + L" " + msg2);
			   if (MessageDlg(msg + L"\n" + msg2, Dialogs::mtError, TMsgDlgButtons() << mbIgnore << mbAbort, 0) == mrAbort)
				 return false;
			   }
			 }
		   else {  // no number
			 msg = L"Metadata code «#Anal.Depth» in row " + IntToStr(row) +
			   " must be followed by a number in the range 1-9.";
			 OutputError(L"ERROR: " + msg);
			 if (MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbIgnore << mbAbort, 0) == mrAbort)
			   return false;
			 }
		   }
		 else if (SameText(Code.SubString(1,6), L"#Chron")) {
		   found = true;
		   bool error = false;
		   UnicodeString ChronStr;
		   UnicodeString Suffix;
		   int pos = Code.Pos(L".");
		   if (pos > 0) {
			 if (pos == Code.Length()) {
			   error = true;
			   msg = L"#Chron code in row " + IntToStr(row) + L" has no suffix following the period.";
			   OutputError(L"ERROR: " + msg);
			   if (MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbIgnore << mbAbort, 0) == mrAbort)
				 return false;
			   }
			 else {
			   ChronStr = Code.SubString(1,pos-1);
			   Suffix = Code;
			   Suffix.Delete(1,pos);
			   }
			 }
		   else
			 ChronStr = Code;

		   if (!error) {
			 if (ChronStr.Length() > 6) {
			   ChronStr.Delete(1,6);
			   int ChronNo;
			   if (TryStrToInt(ChronStr,ChronNo)) {
				 if (ChronNo > 9 || ChronNo < 1) {
				   error = true;
				   msg = L"Number in Chron code «" + Code + L"» in row " +
					 IntToStr(row) + L" must be in the range 1-9.";
				   OutputError(L"ERROR: " + msg);
				   if (MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbIgnore << mbAbort, 0) == mrAbort)
					 return false;
				   }
				 }
			   else {
				 error = true;
				 msg = L"Chron code «" + Code + L"» in row " + IntToStr(row) +
				   L" is not formatted correctly.";
				 msg2 += L"Must be in the form «#ChronX[.Old|Young]», where X is an integer number 1-9.";
				 OutputError(L"ERROR: " + msg + L" " + msg2);
				 if (MessageDlg(msg + L"\n" + msg2, Dialogs::mtError, TMsgDlgButtons() << mbIgnore << mbAbort, 0) == mrAbort)
				   return false;
				 }
			   }
			 else {
			   error = true;
			   msg = L"Chron code «#Chron» in row " + IntToStr(row) + L" must be followed by an integer number 1-9.";
			   OutputError(L"ERROR: " + msg);
			   if (MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbIgnore << mbAbort, 0) == mrAbort)
				 return false;
			   }
			 }

		   if (!error) {
			 if (!Suffix.IsEmpty()) {
			   if (!SameText(Suffix, L"Old") && !SameText(Suffix, L"Young") && !SameText(Suffix, L"Acc.Rate")) {
				 msg = L"Chron code suffix «" + Suffix + L"» in Chron code «" + Code +
				   L"» int row " + IntToStr(row) + L" is not valid.";
				 msg2 = L"Valid suffixes are «Young» and «Old».";
				 OutputError(L"ERROR: " + msg + L" " + msg2);
				 if (MessageDlg(msg + L"\n" + msg2, Dialogs::mtError, TMsgDlgButtons() << mbIgnore << mbAbort, 0) == mrAbort)
				   return false;
				 }
			   }
			 }
		   }
		 else {
		   for (unsigned int i=0; i<SSMD.size(); i++) {
			 if (SameText(Code, SSMD[i])) {
			   found = true;
			   break;
			   }
			 }
		   }
		 if (!found) {
		   msg = L"WARNING: Metadata code «" + Code + L"» in row " + IntToStr(row) + L" is not recognized.";
		   OutputWarning(msg);
		   if (MessageDlg(msg + L"\n" + msg2, mtWarning, TMsgDlgButtons() << mbIgnore << mbAbort, 0) == mrAbort)
			 return false;
		   }
		 }
	   }
	 }

   OutputLine(L"Spreadsheet metadata validated.");
   SetProgressBarPosition();
   return true;
}
//---------------------------------------------------------------------------

bool TNeotomaUploadForm::GetNeotomaKeywords(void)
{
   bool success = false;
   Screen->Cursor = crHourGlass;
   NeotomaKeywordsTable Keywords(ipsJSONS1, TcpClient1);
   StatusBar1->SimpleText = Keywords.WebServiceName();
   Screen->Cursor = crHourGlass;
   if (Keywords.Execute()) {
	 success = true;
	 if (Keywords.Size() > 0)
	   NeotomaKeywords = Keywords.Items;
	 }
   Screen->Cursor = crDefault;
   return success;
}
//---------------------------------------------------------------------------

// this function actually runs the web service that gets the Neotoma valid taxa records
bool TNeotomaUploadForm::LoadNeotomaTaxa(NeotomaTaxaByNameList& Taxa, NeotomaTaxaByNameList& Synonyms, bool set_progress_bar)
{
   if (set_progress_bar)
	 SetProgressBar(MARQUEE);
   Screen->Cursor = crHourGlass;
   // StatusBar1->SimpleText = Taxa.WebServiceName();

   set<TAXONAUTHOR, TaxonAuthorComp>::iterator itr;
   set<TAXONAUTHOR, TaxonAuthorComp>::iterator begin = TaxaSet.begin();
   set<TAXONAUTHOR, TaxonAuthorComp>::iterator end = TaxaSet.end();

   bool success = true;
   NeotomaTaxaByNameList Taxa1(ipsJSONS1, TcpClient1);
   while (success && itr != end) {
	 Taxa1.Items.clear();
	 jsonTaxaNames = L"";
	 for (itr = begin; itr != end; itr++) {
	   if (jsonTaxaNames.IsEmpty())
		 jsonTaxaNames = itr->name;
	   else if ((jsonTaxaNames.Length()+itr->name.Length()) < 200)
		 jsonTaxaNames += (L"$" + itr->name);
	   else {
		 begin = itr;
		 break;
		 }
	   }

	 Taxa1.AddParam(L"TAXANAMES", jsonTaxaNames);
	 StatusBar1->SimpleText = Taxa1.WebServiceName();
	 // ShowMessage(Taxa1.WebServiceName());
	 success = Taxa1.Execute();
	 if (success) {
	   for (unsigned int i=0; i<Taxa1.Size(); i++) {
		 if (Taxa1.Items[i].Valid)
		   Taxa.Items.push_back(Taxa1.Items[i]);
		 else
		   Synonyms.Items.push_back(Taxa1.Items[i]);
		 }
	   }
	 }
   Taxa.ReIndexItems();
   Synonyms.ReIndexItems();

   if (set_progress_bar) {
	 SetProgressBar(CORE);
	 SetProgressBarPosition();
	 }
   Screen->Cursor = crDefault;
   return success;
}
//---------------------------------------------------------------------------

int TNeotomaUploadForm::CheckTaxaNames(NeotomaTaxaBase& Taxa)
{
   vector<void*> vptrs;
   int rv = mrOk;

   for (unsigned int i=0; i<SSVarList.size(); i++) {
	 UnicodeString SSTaxonName = SSVarList[i].name;
	 UnicodeString SSTaxonAuth = SSVarList[i].author;
	 int SSRow = SSVarList[i].row;
	 int count = Taxa.Find("TaxonName", SSTaxonName, vptrs);
	 if (count == 0)  {
	   //ShowMessage(SSTaxonName);
	   //for (unsigned int j = 0; j < Taxa.Size(); j++) {
	   //	 ShowMessage(IntToStr((int)j) + L", " + Taxa.Items[j].TaxonName);
	   //	 }
	   TaxaNotFound.push_back(SSTAXANAME(SSTaxonName, SSTaxonAuth, SSRow));
	   }
	 else if (count == 1) {
	   TAXONRECORD* TaxonRec = (TAXONRECORD*)vptrs[0];
	   NEOTOMAVARIABLE NeotomaVariable;
	   NeotomaVariable.TaxonID = TaxonRec->TaxonID;
	   NeotomaVariable.TaxonName = SSTaxonName;
	   NeotomaVariable.TaxaGroupID = TaxonRec->TaxaGroupID;
	   NeotomaVariables[SSRow] = NeotomaVariable;
	   TSSForm->ProfGrid1->AbsoluteCells[1][SSRow]->Value = TaxonRec->TaxonCode;
	   }
	 else if (count > 1) {  // taxon with same name in more than one TaxaGroup
	   bool authfound = false;
	   for (unsigned int j=0; j<vptrs.size(); j++) {
		 TAXONRECORD* TaxonRec = (TAXONRECORD*)vptrs[j];
		 if (!SSTaxonAuth.IsEmpty() && !TaxonRec->Author.IsEmpty() && SameText(SSTaxonAuth,TaxonRec->Author)) {
		   NEOTOMAVARIABLE NeotomaVariable;
		   NeotomaVariable.TaxonID = TaxonRec->TaxonID;
		   NeotomaVariable.TaxonName = SSTaxonName;
		   //ShowMessage(L"TaxonID = " + IntToStr(NeotomaVariable.TaxonID) + L": " + TaxonRec->TaxonCode);
		   NeotomaVariables[SSRow] = NeotomaVariable;
		   TSSForm->ProfGrid1->AbsoluteCells[1][SSRow]->Value = TaxonRec->TaxonCode;
		   authfound = true;
		   break;
		   }
		 }

	   if (!authfound) {
		 if (!GetTaxaGroups())
		   return mrAbort;
		 vector<UnicodeString> TaxaGroupNames;
		 for (unsigned int j=0; j<vptrs.size(); j++) {
		   TAXONRECORD* TaxonRec = (TAXONRECORD*)vptrs[j];
		   UnicodeString TaxaGroupID = TaxonRec->TaxaGroupID;  // convert from Variant
		   if (NeotomaTaxaGroups.count(TaxaGroupID) > 0)
			 TaxaGroupNames.push_back(NeotomaTaxaGroups[TaxaGroupID]);
		   }
		 TMultiTaxonNamesForm* MultiTaxonNamesForm = new TMultiTaxonNamesForm(TSSForm);
		 MultiTaxonNamesForm->FillMultiTaxonNames(SSRow, SSTaxonName, TaxaGroupNames);
		 rv = MultiTaxonNamesForm->ShowModal();
		 if (rv == mrOk && MultiTaxonNamesForm->ItemChecked > -1) {
		   TAXONRECORD* TaxonRec = (TAXONRECORD*)vptrs[MultiTaxonNamesForm->ItemChecked];
		   NEOTOMAVARIABLE NeotomaVariable;
		   NeotomaVariable.TaxonID = TaxonRec->TaxonID;
		   NeotomaVariable.TaxonName = SSTaxonName;
		   NeotomaVariable.TaxaGroupID = TaxonRec->TaxaGroupID;
		   NeotomaVariables[SSRow] = NeotomaVariable;
		   UnicodeString TaxaGroupID = TaxonRec->TaxaGroupID;
		   OutputLine(L"Taxon «" + SSTaxonName + L"» assigned to Taxa Group «" + NeotomaTaxaGroups[TaxaGroupID] + L"».");
		   }
		 else if (rv == mrIgnore)
		   OutputError(L"ERROR: Taxon Group not resolved for taxon «" + SSTaxonName + L"».");
		 delete MultiTaxonNamesForm;
		 }
	   }
	 }

   SetProgressBarPosition();
   return rv;
}
//---------------------------------------------------------------------------

bool TNeotomaUploadForm::GetTaxaGroups(void)
{
   bool success = false;
   if (NeotomaTaxaGroups.size() > 0)
	 return true;

   NeotomaTaxaGroupTypesTable TaxaGroupCodes(ipsJSONS1, TcpClient1);
   StatusBar1->SimpleText = TaxaGroupCodes.WebServiceName();
   Screen->Cursor = crHourGlass;
   if (TaxaGroupCodes.Execute()) {
	 success = true;
	 if (TaxaGroupCodes.Size() > 0)
	   NeotomaTaxaGroups = TaxaGroupCodes.Items;
	 }
   Screen->Cursor = crDefault;
   return success;
}
//---------------------------------------------------------------------------

int TNeotomaUploadForm::CheckSynonyms(NeotomaTaxaBase& Taxa, NeotomaTaxaBase& Synonyms)
{
   int rv = mrOk;
   vector<void*> syn_vptrs;
   vector<void*> taxa_vptrs;
   TList *TaxonPtrs = new TList;
   vector<SYNONYMROW> synrows;
   int ValidTaxonID;

   for (unsigned int i=0; i<TaxaNotFound.size(); i++) {
	 int SynCount = Synonyms.Find("TaxonName", TaxaNotFound[i].Name, syn_vptrs);
	 if (SynCount > 0) {  // synonym exists
	   TAXONRECORD* SynRec = (TAXONRECORD*)syn_vptrs[0];
	   int InvalidTaxonID = SynRec->TaxonID;

	   ValidTaxonID = -1;
	   NeotomaSynonym InvalidName(ipsJSONS1, TcpClient1);
	   InvalidName.AddParam(L"INVALIDTAXONID", InvalidTaxonID);
	   StatusBar1->SimpleText = InvalidName.WebServiceName();
	   if (InvalidName.Execute()) {
		 if (InvalidName.Size() == 1)
		   ValidTaxonID = InvalidName.Items[0].ValidTaxonID;
		 }
	   else
		 return mrAbort;

	   if (ValidTaxonID > -1) {
		 NeotomaTaxonByID ValidName(ipsJSONS1, TcpClient1);
		 ValidName.AddParam(L"TAXONID", ValidTaxonID);
		 StatusBar1->SimpleText = ValidName.WebServiceName();
		 if (ValidName.Execute()) {
		   if (ValidName.Size() == 1) {
			 TAXON *Taxon =  new TAXON();
			 TaxonPtrs->Add(Taxon);
			 Taxon->ID = VariantToInt(ValidName.Items[0].TaxonID, -1);
			 Taxon->Name = VarToStr(ValidName.Items[0].TaxonName);
			 Taxon->Code = VarToStr(ValidName.Items[0].TaxonCode);
			 Taxon->TaxaGroup = VarToStr(ValidName.Items[0].TaxaGroupID);
			 SYNONYMROW sr(TaxaNotFound[i].Row, SynRec, ValidName.Items[0], Taxon);
			 synrows.push_back(sr);
			 }
		   }
		 }
	   }
	 }

   if (synrows.size() > 0) {
	 SynonymsForm = new TSynonymsForm(synrows, TSSForm);
	 rv = SynonymsForm->ShowModal();
	 if (rv == mrOk) {
	   SynonymsForm->GetSynonyms(synrows);
	   TSSForm->ReplaceSynonyms(synrows, SUBALL, SUBNONE, SUBNONE, SUBNONE, L"");
	   }
	 delete SynonymsForm;

	 if (rv == mrOk) {   // delete taxa with replaced synonyms from TaxaNotFound
	   vector<SSTAXANAME>::iterator itr;
	   for (unsigned int i=0; i<synrows.size(); i++) {
		 if (synrows[i].replace) {
		   OutputLine(L"Depreciated taxon «" + synrows[i].SynonymName + L"» in row " +
			 IntToStr(synrows[i].row) + L" replaced with valid synonym «" +
			 synrows[i].taxon->Name + L"».");

		   NEOTOMAVARIABLE NeotomaVariable;
		   NeotomaVariable.TaxonID = synrows[i].taxon->ID;
		   NeotomaVariable.TaxonName = synrows[i].taxon->Name;
		   NeotomaVariable.TaxaGroupID = synrows[i].taxon->TaxaGroup;    // this currently null
		   NeotomaVariables[synrows[i].row] = NeotomaVariable;

		   for (itr = TaxaNotFound.begin(); itr != TaxaNotFound.end(); itr++) {
			 if (synrows[i].row == itr->Row) {
			   TaxaNotFound.erase(itr);
			   break;
			   }
			 }
		   }
		 else {
		   OutputError(L"ERROR: Depreciated taxon «" + synrows[i].SynonymName +
			 L"» in row " + IntToStr(synrows[i].row) + L" has a valid synonym «" +
			 synrows[i].taxon->Name + L"», but was not replaced." );
		   }
		 }
	   }
	 else {
	   for (unsigned int i=0; i<synrows.size(); i++) {
		 OutputError(L"ERROR: Depreciated taxon «" + synrows[i].SynonymName +
			 L"» in row " + IntToStr(synrows[i].row) + L" has a valid synonym «" +
			 synrows[i].taxon->Name + L"», but was not replaced." );
		 }
	   }
	 }
   DeleteList(TaxonPtrs);
   SetProgressBarPosition();
   return rv;
}
//---------------------------------------------------------------------------

int TNeotomaUploadForm::ResolveRemainingTaxaNotFound(bool& NewSynonyms)
{
   int rv = mrOk;
   if (TaxaNotFound.size() == 0) {
	 OutputLine(L"All taxa names validated.");
	 SetProgressBarPosition();
	 return rv;
	 }

   TNeotomaFindTaxonForm* NeotomaFindTaxonForm =
	 new TNeotomaFindTaxonForm(&TaxaNotFound, &OutputLine, TSSForm, this);
   rv = NeotomaFindTaxonForm->ShowModal();
   NewSynonyms = NeotomaFindTaxonForm->NewSynonyms;
   delete NeotomaFindTaxonForm;

   if (TaxaNotFound.size() > 0) {
	 for (unsigned int i=0; i<TaxaNotFound.size(); i++)
	   OutputError(L"ERROR: Taxon name «" + TaxaNotFound[i].Name + L"» not resolved.");
	 }
   else
	 OutputLine(L"All taxa names validated.");

   SetProgressBarPosition();
   return rv;
}
//---------------------------------------------------------------------------

bool TNeotomaUploadForm::CheckTopBottom(void)
{
   UnicodeString msg;
   bool error = false;
   if (ContainsText(TSSForm->Datasets[0].DatasetType,L"top-bottom")) {
	 Screen->Cursor = crHourGlass;
	 int ntb = 0;
	 int nrows = TSSForm->AbsContentRowCount(TSSForm->ProfGrid1);
	 TProfGrid* ProfGrid = TSSForm->ProfGrid1;
	 for (int row=3; row<=nrows; row++) {
	   UnicodeString Code = ProfGrid->AbsoluteCells[1][row]->Text;
	   if (SameText(Code,L"#Anal.Bottom"))
		 ntb++;
	   }
	 if (ntb == 0) {
	   msg = L"#Anal.Bottom not found for top=bottom dataset.";
	   OutputError(L"ERROR: " + msg);
	   if (MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbIgnore << mbAbort, 0) == mrAbort)
		 error = true;
	   }
	 else if (ntb > 1) {   // this should never happen, but..
	   msg = L"Only one #Anal.Bottom row can exist.";
	   OutputError(L"ERROR: " + msg);
	   if (MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbIgnore << mbAbort, 0) == mrAbort)
		 error = true;
	   }
	 if (!error) {
	   for (int row=3; row<=nrows; row++) {
		 UnicodeString Code = ProfGrid->AbsoluteCells[1][row]->Text;
		 if (SameText(Code,L"#Data.Type")) {
		   msg = L"No other dataset types can be uploaded with " +
				 TSSForm->Datasets[0].DatasetType + L"dataset type.";
		   OutputError(L"ERROR: " + msg);
		   if (MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbIgnore << mbAbort, 0) == mrAbort)
			 error = true;
		   break;
		   }
		 }
	   }
	 if (!error) {
	   int bdrow = TSSForm->FindRowCodeIC(L"#Anal.DepBot", TSSForm->ProfGrid1);
	   if (bdrow == 0) {
		 msg = L"#Anal.DepBot not found for bottom analysis unit.";
		 OutputError(L"ERROR: " + msg);
		 if (MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbIgnore << mbAbort, 0) == mrAbort)
		   error = true;
		 }
	   else {
		 double dValue;
		 int start = TSSForm->AbsHeaderColCount(TSSForm->ProfGrid1);
		 int ncols = TSSForm->AbsContentColCount(TSSForm->ProfGrid1);
		 for (int col=start; col<=ncols; col++) {
		   TProfGridCell* Cell = TSSForm->ProfGrid1->AbsoluteCells[col][bdrow];
		   UnicodeString strValue = Cell->Text;
		   if (strValue.IsEmpty()) {
			 msg = L"ERROR: #Anal.DepBot in column " + Cell->A1Name + L" is empty.";
			 OutputError(msg);
			 error = true;
			 }
		   else if (!TryStrToFloat(strValue,dValue)) {
			 msg = L"ERROR: Value for #Anal.DepBot in column " + Cell->A1Name + L" is invalid.";
			 OutputError(msg);
			 error = true;
			 }
		   }
		 if (error) {
		   msg = L"Blank or invalid values exist for #Anal.DepBot.";
		   if (MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbIgnore << mbAbort, 0) == mrAbort)
			 error = true;
		   else
			 error = false;
		   }
		 }
	   }
	 if (!error)
	   OutputLine(L"Top-bottom dataset validated.");
	 Screen->Cursor = crDefault;
	 }

   SetProgressBarPosition();
   return !error;
}
//---------------------------------------------------------------------------

bool TNeotomaUploadForm::CheckZeroData(void)
{
   //int rv = mrOk;
   int rv;
   vector<EMPTYVAR> ZeroVars;

   int start = TSSForm->AbsHeaderColCount(TSSForm->ProfGrid1);
   int ncols = TSSForm->AbsContentColCount(TSSForm->ProfGrid1);

   Screen->Cursor = crHourGlass;
   TProfGrid* ProfGrid = TSSForm->ProfGrid1;
   for (unsigned int i=0; i<SSVarList.size(); i++) {
	 bool zero = true;
	 bool empty = true;
	 int row = SSVarList[i].row;
	 for (int col=start; col<=ncols; col++) {
	   TProfGridCell* Cell = ProfGrid->AbsoluteCells[col][row];
	   if (!Cell->IsEmpty()) {
		 empty = false;
		 Variant Value = Cell->Value;
		 if (Value.Type() != varDouble) {
		   OutputError(L"ERROR: Cell " + Cell->A1Name + L" contains an invalid value: «" +
			   Cell->Text + L"». Numerical value expected."  );
		   Screen->Cursor = crDefault;
		   return false;
		   }
		 else if (zero && Value.Type() == varDouble) {
		   double dVal = Value;
		   if (dVal != 0)
			 zero = false;
		   }
		 }
	   }
	 if (!empty && zero) {
	   EMPTYVAR EmptyVar;
	   UnicodeString name = SSVarList[i].name;
	   if (!TSSForm->GridCellIsEmpty(ProfGrid->AbsoluteCells[3][row]))
		 name += (L":" + ProfGrid->AbsoluteCells[3][row]->Text);
	   if (!TSSForm->GridCellIsEmpty(ProfGrid->AbsoluteCells[4][row]))
		 name += (L":" + ProfGrid->AbsoluteCells[4][row]->Text);
	   if (!TSSForm->GridCellIsEmpty(ProfGrid->AbsoluteCells[5][row]))
		 name += (L":" + ProfGrid->AbsoluteCells[5][row]->Text);

	   EmptyVar.name = name;
	   EmptyVar.row = row;
	   ZeroVars.push_back(EmptyVar);
	   }
	 }

   if (ZeroVars.size() > 0) {
	 int InitRowCount = TSSForm->AbsContentRowCount(TSSForm->ProfGrid1);
	 TCheckZeroDataForm* CheckZeroDataForm = new TCheckZeroDataForm(TSSForm);
	 CheckZeroDataForm->FillZeroVars(ZeroVars);
	 rv = CheckZeroDataForm->ShowModal();
	 if (CheckZeroDataForm->OutputLines.size() > 0) {
	   ZeroVarsAllowed = CheckZeroDataForm->ZeroVarsAllowed;
	   for (unsigned int i = 0; i<CheckZeroDataForm->OutputLines.size(); i++)
		 OutputLine(CheckZeroDataForm->OutputLines[i]);
	   }
	 if (CheckZeroDataForm->OutputErrors.size() > 0) {
	   for (unsigned int i = 0; i<CheckZeroDataForm->OutputErrors.size(); i++)
		 OutputError(CheckZeroDataForm->OutputErrors[i]);
	   }
	 delete CheckZeroDataForm;
	 if (rv == mrAbort) {
	   Screen->Cursor = crDefault;
	   return false;
	   }
	 int RowCount = TSSForm->AbsContentRowCount(TSSForm->ProfGrid1);
	 if (RowCount < InitRowCount)
	   GetVariables();
	 }
   else // if (rv == mrOk)
	 OutputLine(L"Zero data check passed.");

   // check for all zero analysis units


   SetProgressBarPosition();
   return true;
}
//---------------------------------------------------------------------------

bool TNeotomaUploadForm::CheckDepthsNames(void)
{
   UnicodeString msg;
   bool depth_error;
   bool name_error = false;

   Screen->Cursor = crHourGlass;
   int start = TSSForm->AbsHeaderColCount(TSSForm->ProfGrid1);
   int ncols = TSSForm->AbsContentColCount(TSSForm->ProfGrid1);
   TProfGrid* ProfGrid = TSSForm->ProfGrid1;

   // check for numbers in row 1
   for (int col=start; col<ncols; col++) {
	 TProfGridCell* ACell = ProfGrid->AbsoluteCells[col][1];
	 if (ACell->Value.Type() != varDouble && !TSSForm->GridCellIsEmpty(ACell)) {
	   InvalidSSNumber(col, 1, L"for Analysis Unit depth or number", msg);
	   OutputError(L"ERROR: " + msg);
	   Screen->Cursor = crDefault;
	   if (MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbIgnore << mbAbort, 0) == mrAbort)
		 return false;
	   else {
		 OutputError(L"ERROR: Validation of analysis unit depths and names not completed.");
		 return true;
		 }
	   }
	 }

   // check that either a number or name exists
   for (int col=start; col<ncols; col++) {
	 TProfGridCell* ACell1 = ProfGrid->AbsoluteCells[col][1];
	 TProfGridCell* ACell2 = ProfGrid->AbsoluteCells[col][2];
	 if (TSSForm->GridCellIsEmpty(ACell1) && TSSForm->GridCellIsEmpty(ACell2)) {
	   msg = L"Analysis unit in column " + ProfGrid->AbsoluteCols[col]->A1Name +
			 L" must have either a number or name, or both, in rows 1 or 2.";
	   OutputError(L"ERROR: " + msg);
	   Screen->Cursor = crDefault;
       if (MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbIgnore << mbAbort, 0) == mrAbort)
		 return false;
	   else {
		 OutputError(L"ERROR: Validation of analysis unit depths and names not completed.");
		 return true;
		 }
	   }
	 }

   depth_error = !CheckDepthsNamesRow(1, start, ncols);
   if (depth_error) {
	 msg = L"WARNING: Some, but not all, analysis units have depths or sample numbers in row 1.";
	 msg += L" Usually either all or no analysis units have depths or numbers.";
	 OutputWarning(msg);
	 }

   switch (TSSForm->HeaderRow2) {
	 case ANAL_UNIT_NAME:
	   name_error = !CheckDepthsNamesRow(2, start, ncols);
	   if (name_error) {
		 msg = L"WARNING: Some, but not all, analysis units have names in row 2.";
		 msg += L" Usually either all or no analysis units have names.";
		 OutputWarning(msg);
		 }
	   break;
	 case COLL_UNIT_NAME:
	   break;
	 case COLL_UNIT_HANDLE:
	   break;
	 case SITE_NAME:
	   break;
	 }

   if (!depth_error && !name_error)
	 OutputLine(L"Analysis unit depths or numbers and names validated.");

   Screen->Cursor = crDefault;
   SetProgressBarPosition();
   return true;
}
//---------------------------------------------------------------------------

bool TNeotomaUploadForm::CheckDepthsNamesRow(int row, int start, int ncols)
{
   TProfGrid* ProfGrid = TSSForm->ProfGrid1;
   bool HasValue = !TSSForm->GridCellIsEmpty(ProfGrid->AbsoluteCells[start][row]);
   if (HasValue) {
	 for (int col=start+1; col<ncols; col++) {
	   if (TSSForm->GridCellIsEmpty(ProfGrid->AbsoluteCells[col][row]))
		 return false;
	   }
	 }
   else {
	 for (int col=start+1; col<ncols; col++) {
	   if (!TSSForm->GridCellIsEmpty(ProfGrid->AbsoluteCells[col][row]))
		 return false;
	   }
	 }
   return true;
}
//---------------------------------------------------------------------------

int TNeotomaUploadForm::CheckUnits(void)
{
   int rv = mrOk;
   vector<EMPTYVAR> EmptyUnits;

   TProfGrid* ProfGrid = TSSForm->ProfGrid1;
   for (unsigned int i=0; i<SSVarList.size(); i++) {
	 int row = SSVarList[i].row;
	 if (ProfGrid->AbsoluteCells[4][row]->IsEmpty()) {
	   EMPTYVAR EmptyUnit;
	   EmptyUnit.row = SSVarList[i].row;
	   EmptyUnit.name = SSVarList[i].name;
	   EmptyUnit.code = TSSForm->ProfGrid1->AbsoluteCells[1][EmptyUnit.row]->Text;
	   EmptyUnit.element = TSSForm->ProfGrid1->AbsoluteCells[3][EmptyUnit.row]->Text;
	   EmptyUnits.push_back(EmptyUnit);
	   }
	 }

   if (EmptyUnits.size() > 0) {
	 CheckVarUnitsForm = new TCheckVarUnitsForm(this);
	 CheckVarUnitsForm->FillEmptyUnits(EmptyUnits);
	 rv = CheckVarUnitsForm->ShowModal();
	 if (rv != mrOk)
	   OutputError(L"ERROR: Variables not assigned units.");
	 delete CheckVarUnitsForm;
	 }
   else
	 OutputLine(L"Units assigned to all variables.");

   SetProgressBarPosition();
   return rv;
}
//---------------------------------------------------------------------------

int TNeotomaUploadForm::CheckElements(void)
{
   int rv = mrOk;
   vector<EMPTYVAR> EmptyElements;

   TProfGrid* ProfGrid = TSSForm->ProfGrid1;
   for (unsigned int i=0; i<SSVarList.size(); i++) {
	 int row = SSVarList[i].row;
	 if (ProfGrid->AbsoluteCells[3][row]->IsEmpty()) {
	   EMPTYVAR EmptyUnit;
	   EmptyUnit.row = SSVarList[i].row;
	   EmptyUnit.name = SSVarList[i].name;
	   EmptyUnit.code = TSSForm->ProfGrid1->AbsoluteCells[1][EmptyUnit.row]->Text;
	   EmptyUnit.units = TSSForm->ProfGrid1->AbsoluteCells[4][EmptyUnit.row]->Text;
	   EmptyElements.push_back(EmptyUnit);
	   }
	 }

   if (EmptyElements.size() > 0) {
	 TCheckVarElementsForm* CheckVarElementsForm = new TCheckVarElementsForm(this);
	 CheckVarElementsForm->FillEmptyElements(EmptyElements);
	 rv = CheckVarElementsForm->ShowModal();
	 if (rv != mrOk)
	   OutputError(L"ERROR: Variables not assigned elements.");
	 delete CheckVarElementsForm;
	 }
   else
	 OutputLine(L"Elements assigned to all variables.");

   SetProgressBarPosition();
   return rv;
}
//---------------------------------------------------------------------------

bool TNeotomaUploadForm::CheckDuplicates(void)
{
   int rv;
   vector<DUPVAR> DupVars;

   TSSForm->CheckVarDuplicates(SSVarList, DupVars);
   if (DupVars.size() > 0 && ContainsText(TSSForm->Datasets[0].DatasetType, L"top-bottom")) {
	 int bdrow = TSSForm->FindRowCodeIC(L"#Anal.DepBot", TSSForm->ProfGrid1);
	 int end = DupVars.size()-1;
	 for (int i=end; i>=0; i--) {
	   unsigned int u = (unsigned int)i;
	   if (DupVars[u].row1 < bdrow && DupVars[u].row2 > bdrow)
		 DupVars.erase(DupVars.begin()+u);
	   }
	 }

   if (DupVars.size() > 0) {
	 int InitRowCount = TSSForm->AbsContentRowCount(TSSForm->ProfGrid1);
	 TCheckDupsForm* CheckDupsForm = new TCheckDupsForm(TSSForm);
	 CheckDupsForm->FillDupVars(DupVars);
	 rv = CheckDupsForm->ShowModal();
	 if (CheckDupsForm->OutputLines.size() > 0) {
	   for (unsigned int i=0; i<CheckDupsForm->OutputLines.size(); i++)
		 OutputLine(CheckDupsForm->OutputLines[i]);
	   }
	 if (CheckDupsForm->OutputErrors.size() > 0) {
	   for (unsigned int i = 0; i<CheckDupsForm->OutputErrors.size(); i++)
		 OutputError(CheckDupsForm->OutputErrors[i]);
	   }
	 if (rv == mrAbort) {
	   Screen->Cursor = crDefault;
	   return false;
	   }
	 delete CheckDupsForm;
	 int RowCount = TSSForm->AbsContentRowCount(TSSForm->ProfGrid1);
	 if (RowCount < InitRowCount)
	   GetVariables();
	 }
   else
	 OutputLine(L"Duplicate variable check passed.");
   SetProgressBarPosition();
   return true;
}
//---------------------------------------------------------------------------

bool TNeotomaUploadForm::UploadAggregate(void)
{
   if (AggregateDatasets.size() == 0)
	 return true;

   vector<int> newids;
   UnicodeString msg;
   UnicodeString ErrorMsg;
   UnicodeString Notes;

   for (unsigned int i = 0; i < AggregateDatasets.size(); i++) {
	 if (AggregateDatasets[i].ID == -1) {
	   InsertData InsertAggDataset(L"InsertAggregateDataset", 3, ipsHTTPS1, ipsJSONS1, TcpClient1);
	   InsertAggDataset.Add(L"NAME", AggregateDatasets[i].Name);
	   InsertAggDataset.Add(L"ORDERTYPEID", AggregateDatasets[i].OrderTypeID, -1);
	   InsertAggDataset.Add(L"NOTES", Notes);
	   StatusBar1->SimpleText = L"InsertAggregateDataset";
	   InsertAggDataset.PostData();
	   if (InsertAggDataset.Post(newids, ErrorMsg)) {
		 if (newids.size() == 1) {
		   AggregateDatasets[i].ID = newids[0];
		   msg = L"Aggregate dataset «" + AggregateDatasets[i].Name +
				 L"» uploaded to AggregateDatasets table. AggregateDatasetID = " +
				 IntToStr(newids[0]) + L".";
		   OutputLine(msg);
		   }
		 else {
		   ErrorMsg = L"Error inserting into AggregateDatasets table!";
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

   // [InsertAggregateSample](@AGGREGATEDATASETID int, @SAMPLEID int)
   for (unsigned int i = 0; i < AggregateDatasets.size(); i++) {
	 int nsamps = 0;
	 InsertData InsertAggSample(L"InsertAggregateSample", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
	 for (unsigned int j = 0; j < NeotomaSamples.size(); j++) {
	   if (NeotomaSamples[j].DatasetTypeID == AggregateDatasets[i].DatasetTypeID) {
		 InsertAggSample.Add(L"AGGREGATEDATASETID", AggregateDatasets[i].ID);
		 int SampleID = NeotomaSampleIDs[NeotomaSamples[j].SampleID];
		 InsertAggSample.Add(L"SAMPLEID", SampleID);
		 nsamps++;
		 }
	   }
	 StatusBar1->SimpleText = L"InsertAggregateSample";
	 InsertAggSample.PostData();
	 if (InsertAggSample.Post(ErrorMsg)) {
	   msg = L"Aggregate dataset «" + AggregateDatasets[i].Name + L"»: ";
	   msg += (IntToStr(nsamps) + L" sample");
	   if (nsamps > 1)
		 msg += L"s";
	   msg += L" uploaded to AggregateSamples table.";
	   OutputLine(msg);
	   }
	 else {
	   OutputError(L"ERROR: " + ErrorMsg);
	   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return false;
	   }
	 }

/*
[InsertAggregateChronology](@AGGREGATEDATASETID int,
@AGETYPEID int,
@ISDEFAULT bit,
@CHRONOLOGYNAME nvarchar(80),
@AGEBOUNDYOUNGER int,
@AGEBOUNDOLDER int,
@NOTES nvarchar(MAX) = null)
*/

   // vector<int> AggregateChronIDs;
   // std::vector<int> second (4,100);    // four ints with value 100
   map<int,bool> NewChron;

   // upload aggregate chronology
   for (unsigned int i = 0; i < AggregateDatasets.size(); i++) {
	 if (AggregateDatasets[i].ChronID == -1) {
	   InsertData InsertAggChron(L"InsertAggregateChronology", 7, ipsHTTPS1, ipsJSONS1, TcpClient1);
	   InsertAggChron.Add(L"AGGREGATEDATASETID", AggregateDatasets[i].ID, -1);
	   InsertAggChron.Add(L"AGETYPEID", AggregateChron.AgeTypeID, -1);
	   InsertAggChron.Add(L"ISDEFAULT", AggregateChron.IsDefault);
	   InsertAggChron.Add(L"CHRONOLOGYNAME", AggregateChron.ChronologyName);
	   InsertAggChron.AddInt(L"AGEBOUNDYOUNGER", AggregateChron.AgeBoundYounger);
	   InsertAggChron.AddInt(L"AGEBOUNDOLDER", AggregateChron.AgeBoundOlder);
	   InsertAggChron.Add(L"NOTES", Notes);
	   StatusBar1->SimpleText = L"InsertAggregateChronology";
	   InsertAggChron.PostData();
	   newids.clear();
	   if (InsertAggChron.Post(newids, ErrorMsg)) {
		 if (newids.size() == 1) {
		   // AggregateChronIDs.push_back(newids[0]);
		   AggregateDatasets[i].ChronID = newids[0];
		   NewChron[AggregateDatasets[i].ChronID] = true;
		   msg = L"Aggregate dataset «" + AggregateDatasets[i].Name +
				 L"» chronology «" + AggregateChron.ChronologyName +
				 L"» uploaded to AggregateChronologies table. AggregateChronID = " +
				 IntToStr(newids[0]) + L".";
		   OutputLine(msg);
		   }
		 else {
		   ErrorMsg = L"Error inserting into AggregateChronologies table!";
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
	 else
	   NewChron[AggregateDatasets[i].ChronID] = false;
	 }

   // upload aggregate sample ages -- most work done on server
   // [InsertAggregateSampleAges](@AGGREGATEDATASETID int, @AGGREGATECHRONID int)

   for (unsigned int i = 0; i < AggregateDatasets.size(); i++) {
	 InsertData InsertAggSampleAges(L"InsertAggregateSampleAges", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
	 InsertAggSampleAges.Add(L"AGGREGATEDATASETID", AggregateDatasets[i].ID);
	 // InsertAggSampleAges.Add(L"AGGREGATECHRONID", AggregateChronIDs[i]);
	 InsertAggSampleAges.Add(L"AGGREGATECHRONID", AggregateDatasets[i].ChronID);
	 StatusBar1->SimpleText = L"InsertAggregateSampleAges";
	 InsertAggSampleAges.PostData();
	 if (InsertAggSampleAges.Post(ErrorMsg)) {
	   msg = L"Aggregate dataset «" + AggregateDatasets[i].Name +
			 L"» sample ages uploaded to AggregateSampleAges table: AggregateDatasetID = " +
			 IntToStr(AggregateDatasets[i].ID) + L", AggregrateChronID = " +
			 IntToStr(AggregateDatasets[i].ChronID) + L".";
	   OutputLine(msg);
	   }
	 else {
	   OutputError(L"ERROR: " + ErrorMsg);
	   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return false;
	   }
	 }

   // adjust younger and older age bounds if necessary
   for (unsigned int i = 0; i < AggregateDatasets.size(); i++) {
	 if (!NewChron[AggregateDatasets[i].ChronID]) {
	   NeotomaAggregateChronByDatasetID AggregateChrons(ipsJSONS1, TcpClient1);
	   StatusBar1->SimpleText = AggregateChrons.WebServiceName();
	   AggregateChrons.AddParam(L"AGGREGATEDATASETID", AggregateDatasets[i].ID);
	   if (!AggregateChrons.Execute())
		 return false;
	   if (AggregateChrons.Size() == 1) {
		 bool update_younger = false;
		 bool update_older = false;
		 if (AggregateChrons.Items[0].AgeTypeID != 1) {   // != AD/BC
		   if (AggregateChron.AgeBoundYounger < AggregateChrons.Items[0].AgeBoundYounger)
			 update_younger = true;
		   if (AggregateChron.AgeBoundOlder > AggregateChrons.Items[0].AgeBoundOlder)
			 update_older = true;
		   }
		 else {
		   if (AggregateChron.AgeBoundYounger > AggregateChrons.Items[0].AgeBoundYounger)
			 update_younger = true;
		   if (AggregateChron.AgeBoundOlder < AggregateChrons.Items[0].AgeBoundOlder)
			 update_older = true;
		   }
		 if (update_younger || update_older) {
		   // [UpdateAggregateChronAgeBounds](@AGGREGATECHRONID int, @AGEBOUNDYOUNGER int, @AGEBOUNDOLDER int)
		   UpdateData UpdateAgeBounds(L"UpdateAggregateChronAgeBounds", 3, ipsHTTPS1, ipsJSONS1, TcpClient1);
		   UpdateAgeBounds.Add(L"AGGREGATECHRONID", AggregateDatasets[i].ChronID);
		   UpdateAgeBounds.AddInt(L"AGEBOUNDYOUNGER", AggregateChron.AgeBoundYounger);
		   UpdateAgeBounds.AddInt(L"AGEBOUNDOLDER", AggregateChron.AgeBoundOlder);
		   StatusBar1->SimpleText = L"UpdateAggregateChronAgeBounds";
		   if (UpdateAgeBounds.Post(ErrorMsg)) {
			 if (update_younger) {
			   msg = L"AggregateChronology: ID = " + IntToStr(AggregateDatasets[i].ChronID) +
					 L", AgeBoundYounger updated to " + IntToStr((int)AggregateChron.AgeBoundYounger);
			   OutputLine(msg);
			   }
			 if (update_older) {
			   msg = L"AggregateChronology: ID = " + IntToStr(AggregateDatasets[i].ChronID) +
					 L", AgeBoundOlder updated to " + IntToStr((int)AggregateChron.AgeBoundOlder);
			   OutputLine(msg);
			   }
			 }
		   else {
			 if (!ErrorMsg.IsEmpty())
			   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			 return false;
			 }
		   }
		 }
	   }
     }

   return true;
}
//---------------------------------------------------------------------------
