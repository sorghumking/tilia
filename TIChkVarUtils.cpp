//---------------------------------------------------------------------------

#include <algorithm>
#pragma hdrstop

#include "TIChkVarUtils.h"
#ifndef TISpreadH
#include "TISpread.h"
#endif

//---------------------------------------------------------------------------

#pragma package(smart_init)

bool TTilSpreadSheetForm::GetSSVarList(vector<SSVAR>& SSVarList, bool SortByName, vector<UnicodeString>& ErrMsgs)
{
   int pos, bapos, eapos, vbpos;

   SSVarList.clear();
   int nrows = AbsContentRowCount(ProfGrid1);
   int start = AbsHeaderRowCount(ProfGrid1);
   for (int row=start; row<=nrows; row++) {
	 UnicodeString VarCode = ProfGrid1->AbsoluteCells[1][row]->Value;
	 if (VarCode.IsEmpty() ||
		(VarCode.SubString(1,1) != "#" &&
		 VarCode.SubString(1,3) != "SUM" &&
		 VarCode.SubString(1,4) != "SSUM")) {
	   UnicodeString VarName = ProfGrid1->AbsoluteCells[2][row]->Value;

	   while ((pos = VarName.Pos(L"  ")) > 0) // delete double spaces
		 VarName.Delete(pos,1);
	   VarName = VarName.Trim();
	   ProfGrid1->AbsoluteCells[2][row]->Value = VarName;

	   if (!VarName.IsEmpty()) {
		 SSVAR ssvar;

		 if ((bapos = VarName.Pos(L"{")) > 0) {
		   if ((eapos = VarName.Pos(L"}")) > 0) {
			 ssvar.author = VarName.SubString(bapos+1, eapos-bapos-1);
			 VarName = VarName.SubString(1,bapos-1).TrimRight();
			 }
		   else {
			 UnicodeString msg = L"Taxon name in row " + IntToStr(row) +
				L" has a left brace \'{\' but no right brace \'}'. Author ignored.";
			 ErrMsgs.push_back(msg);
			 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			 }
		   }
		 else if (VarName.Pos(L"}") > 0) {
		   UnicodeString msg = L"Taxon name in row " + IntToStr(row) +
				L" has a right brace \'}\' but no left brace \'{'. Author ignored.";
		   ErrMsgs.push_back(msg);
		   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   }

		 if ((vbpos = VarName.Pos(L"|")) > 0) {
		   ssvar.author = VarName.SubString(vbpos+1, VarName.Length()-vbpos).Trim();
		   VarName = VarName.SubString(1,vbpos-1);
		   }

		 ssvar.name = VarName.Trim();
		 ssvar.row = row;
		 SSVarList.push_back(ssvar);
		 }
	   }
	 }
   if (SortByName)
	 SortSSVarList(SSVarList);
   return (ErrMsgs.size() == 0);
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::SortSSVarList(vector<SSVAR>& SSVarList)
{
   sort(SSVarList.begin(), SSVarList.end(), SSVARComp);
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::CheckVarDuplicates(vector<SSVAR>& SSVarList, vector<DUPVAR>& DupVars)
{
   UnicodeString Element, Units, Context, Taphonomy;
   UnicodeString DatasetType = Datasets[0].DatasetType;

   DupVars.clear();
   for (unsigned int i=0; i<SSVarList.size()-1; i++) {
	 int irow = SSVarList[i].row;

	 UnicodeString VarCode = ProfGrid1->AbsoluteCells[1][irow]->Text;

	 // skip any rows already a duplicate
	 bool skip = false;
	 if (DupVars.size() > 0) {
	   for (unsigned int k=0; k<DupVars.size(); k++) {
		 if (irow == DupVars[k].row2) {
		   skip = true;
		   break;
		   }
		 }
	   }
	 if (skip) continue;

	 for (unsigned int j=i+1; j<SSVarList.size(); j++) {
	   if (SameText(SSVarList[i].name, SSVarList[j].name)) {
		 // check other variable components for equality
		 int jrow = SSVarList[j].row;
		 Variant ival = ProfGrid1->AbsoluteCells[3][irow]->Value;
		 Variant jval = ProfGrid1->AbsoluteCells[3][jrow]->Value;
		 if (ival == jval) {         // elements are also equal
		   Element = ProfGrid1->AbsoluteCells[3][irow]->Value;
		   ival = ProfGrid1->AbsoluteCells[4][irow]->Value;
		   jval = ProfGrid1->AbsoluteCells[4][jrow]->Value;
		   if (ival == jval) {       // units are also equal
			 Units = ProfGrid1->AbsoluteCells[4][irow]->Value;
			 ival = ProfGrid1->AbsoluteCells[5][irow]->Value;
			 jval = ProfGrid1->AbsoluteCells[5][jrow]->Value;
			 if (ival == jval) {     // contexts are also equal
			   Context = ival = ProfGrid1->AbsoluteCells[5][irow]->Value;
			   ival = ProfGrid1->AbsoluteCells[6][irow]->Value;
			   jval = ProfGrid1->AbsoluteCells[6][jrow]->Value;
			   if (ival == jval) {   // taphonomies are also equal
				 Taphonomy = ProfGrid1->AbsoluteCells[6][irow]->Value;
				 DUPVAR DupVar;
				 DupVar.DupName = SSVarList[i].name + L":" + Element + L":" + Units;
				 if (!Context.IsEmpty()) {
				   DupVar.DupName += (L":" + Context);
				   if (!Taphonomy.IsEmpty())
					 DupVar.DupName += (L":" + Taphonomy);
				   }
				 else if (!Taphonomy.IsEmpty())
				   DupVar.DupName += (L"::" + Taphonomy);
				 DupVar.row1 = irow;
				 DupVar.row2 = jrow;
				 DupVars.push_back(DupVar);
				 }
			   }
			 }
		   }
		 }
	   }
	 }

   // check if duplicates are in different datasets
   if (DupVars.size() > 0) {
	 int RowCount = AbsContentRowCount(ProfGrid1);
	 map<int,UnicodeString> VarDataset;
	 UnicodeString DatasetType = ProfGrid1->AbsoluteCells[1][1]->Text;
	 for (int row=3; row<RowCount; row++) {
	   UnicodeString VarCode = ProfGrid1->AbsoluteCells[1][row]->Text;
	   if (SameText(VarCode, L"#Data.Type"))
		 DatasetType = ProfGrid1->AbsoluteCells[2][row]->Text;
	   else
		 VarDataset[row] = DatasetType;
	   }
	 int end = DupVars.size()-1;
	 for (int i=end; i>=0; i--) {
	   unsigned int u = (unsigned int)i;
	   if (VarDataset[DupVars[u].row1] != VarDataset[DupVars[u].row2])
		 DupVars.erase(DupVars.begin()+u);
	   }
	 }
}
//---------------------------------------------------------------------------
