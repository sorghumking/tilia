//---------------------------------------------------------------------------
#include <vcl.h>
#include "pch.h"

#pragma hdrstop

#include "TIRepos.h"
#ifndef TIMemoH
#include "TIMemo.h"
#endif
#ifndef TIAddRepH
#include "TIAddRep.h"
#endif
#ifndef TISpreadH
#include "TISpread.h"
#endif

//---------------------------------------------------------------------------

#pragma package(smart_init)

//---------------------------------------------------------------------------
void __fastcall TTilSpreadSheetForm::cxPopupEdit12PropertiesInitPopup(
	  TObject *Sender)
{
   AdvColumnGrid2->UnCheckAll(0);
   AdvColumnGrid2->ClearCols(3,1);

   int dataset_num = DatasetTabsheetNum();
   for (unsigned int i=0; i<Datasets[dataset_num].Repositories.size(); i++) {
	 UnicodeString Acronym = Datasets[dataset_num].Repositories[i].Acronym;
	 for (int row=1; row<AdvColumnGrid2->RowCount; row++) {
	   if (SameText(AdvColumnGrid2->Cells[1][row], Acronym)) {
		 AdvColumnGrid2->SetCheckBoxState(0,row,true);
		 AdvColumnGrid2->Cells[3][row] = Datasets[dataset_num].Repositories[i].SpecimenNotes;
		 break;
		 }
	   }
	 }

   AdvColumnGrid2->TopRow = 1;
   for (int row=1; row<AdvColumnGrid2->RowCount; row++) {
	 if (AdvColumnGrid2->IsChecked(0,row)) {
	   AdvColumnGrid2->TopRow = min(row, AdvColumnGrid2->RowCount-AdvColumnGrid2->VisibleRowCount+1);
	   break;
	   }
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::AdvColumnGrid2HoverButtonsShow(TObject *Sender,
		  int X, int Y, bool &Allow)
{
   int ACol, ARow;
   AdvColumnGrid2->MouseToCell(X, Y, ACol, ARow);
   if (ACol == 3) {
	 AdvColumnGrid2->HoverButtons->Buttons->Assign(SpecHoverButtons);
	 AdvColumnGrid2->HoverButtons->Column = 3;
	 AdvColumnGrid2->HoverButtons->Buttons->Items[0]->ImageIndex = 72;
	 AdvColumnGrid2->HoverButtons->Buttons->Items[0]->Hint = L"Edit specimen notes";
	 }
   else {
	 AdvColumnGrid2->HoverButtons->Buttons->Assign(RepHoverButtons);
	 AdvColumnGrid2->HoverButtons->Column = 2;
	 AdvColumnGrid2->HoverButtons->Buttons->Items[1]->ImageIndex = 73;
	 AdvColumnGrid2->HoverButtons->Buttons->Items[2]->ImageIndex = 74;
	 AdvColumnGrid2->HoverButtons->Buttons->Items[0]->Hint = L"Show repository notes";
	 UnicodeString Acronym = AdvColumnGrid2->Cells[1][ARow];
	 if (RepositoryNotes.count(Acronym) > 0) {
	   AdvColumnGrid2->HoverButtons->Buttons->Items[0]->ImageIndex = 72;
	   AdvColumnGrid2->HoverButtons->Buttons->Items[0]->Enabled = true;
	   }
	 else {
	   AdvColumnGrid2->HoverButtons->Buttons->Items[0]->ImageIndex = 75;
	   AdvColumnGrid2->HoverButtons->Buttons->Items[0]->Enabled = false;
	   }
	 }

}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::AdvColumnGrid2CheckBoxChange(TObject *Sender,
		  int ACol, int ARow, bool State)
{
   if (!AdvColumnGrid2->Visible)
	 return;
   int dataset_num = DatasetTabsheetNum();
   if (State) {
	 REPOSITORY rep;
	 rep.Acronym = AdvColumnGrid2->Cells[1][ARow];
	 rep.Repository = AdvColumnGrid2->Cells[2][ARow];
	 if (RepositoryNotes.count(rep.Acronym) > 0)
	   rep.Notes = RepositoryNotes[rep.Acronym];
	 rep.SpecimenNotes = AdvColumnGrid2->Cells[3][ARow];
	 Datasets[dataset_num].Repositories.push_back(rep);
	 }
   else {
	 UnicodeString Repository = AdvColumnGrid2->Cells[2][ARow];
	 vector<REPOSITORY>::iterator itr;
	 for (itr = Datasets[dataset_num].Repositories.begin(); itr != Datasets[dataset_num].Repositories.end(); itr++) {
	   if (SameText(Repository, itr->Repository)) {
		 Datasets[dataset_num].Repositories.erase(itr);
		 break;
		 }
	   }
	 }
   cxPopupEdit12->Text = Datasets[dataset_num].RepositoryText();
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::AdvColumnGrid2HoverButtonClick(TObject *Sender,
		  int ARow, THoverButtonsCollectionItem *AButton)
{
   UnicodeString Notes;
   TMemoForm* MemoForm;
   UnicodeString Acronym, Repository;

   switch (AButton->Index) {
	 case 0:
	   if (AdvColumnGrid2->HoverButtons->Column == 3) {
		 MemoForm = new TMemoForm(L"Specimen Notes", AdvColumnGrid2->Cells[3][ARow],
			MemoFormOptions() << mfoCancelButton, this);
		 if (MemoForm->ShowModal() == mrOk) {
		   AdvColumnGrid2->Cells[3][ARow] = MemoForm->Memo1->Text;
		   Acronym = AdvColumnGrid2->Cells[1][ARow];
		   int dataset_num = DatasetTabsheetNum();
		   for (unsigned int i=0; i<Datasets[dataset_num].Repositories.size(); i++) {
			 if (SameText(Acronym, Datasets[dataset_num].Repositories[i].Acronym)) {
			   Datasets[dataset_num].Repositories[i].SpecimenNotes = MemoForm->Memo1->Text;
			   break;
			   }
			 }
		   }
		 delete MemoForm;
		 }
	   else {
		 Acronym = AdvColumnGrid2->Cells[1][ARow];
		 if (RepositoryNotes.count(Acronym) > 0) {
		   Notes = RepositoryNotes[Acronym];
		   Notes = Notes.Trim();
		   }
		 MemoForm = new TMemoForm(L"Repository Notes", Notes,
			MemoFormOptions() << mfoReadOnly, this);
		 MemoForm->ShowModal();
		 delete MemoForm;
		 }
	   break;
	 case 1:
	   if (RepositoryNotes.count(Acronym) > 0)
		 Notes = RepositoryNotes[Acronym];
	   EditRepositoryForm = new TEditRepositoryForm(AdvColumnGrid2, Notes, this);
	   if (EditRepositoryForm->ShowModal() == mrOk) {

		 }
	   delete EditRepositoryForm;
	   break;
	 case 2:
	   AddRepositoryForm = new TAddRepositoryForm(AdvColumnGrid2, this);
	   if (AddRepositoryForm->ShowModal() == mrOk) {
		 AdvColumnGrid2->RowCount++;
		 int row = AdvColumnGrid2->RowCount - 1;
		 Acronym = AddRepositoryForm->cxTextEdit1->Text;
		 Repository = AddRepositoryForm->cxTextEdit2->Text;
		 AdvColumnGrid2->Cells[1][row] = Acronym;
		 AdvColumnGrid2->Cells[2][row] = Repository;
		 if (!AddRepositoryForm->cxBlobEdit1->Text.IsEmpty())
		   AdvColumnGrid2->Cells[3][row] = AddRepositoryForm->cxBlobEdit1->Text;
		 AdvColumnGrid2->AddCheckBox(0,row,cbUnchecked);

		 AdvColumnGrid2->QSort();
		 row = 0;
		 for (int i=1; i<AdvColumnGrid2->RowCount; i++) {
		   if (SameText(Repository, AdvColumnGrid2->Cells[2][i])) {
			 row = i;
			 break;
			 }
		   }

		 if (row > 0) {
		   AdvColumnGrid2->Row = row;
		   int TopRow = row - 1;
		   if (TopRow < 1)
			 TopRow = 1;
		   else if (TopRow > AdvColumnGrid2->RowCount - AdvColumnGrid2->VisibleRowCount)
			 TopRow = AdvColumnGrid2->RowCount - AdvColumnGrid2->VisibleRowCount;
		   AdvColumnGrid2->TopRow = TopRow;
		   }

		 UnicodeString msg = L"Save repository «" + Acronym + L" | " + Repository + "» to local lookup file?";
		 if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes) {
		   SaveLookupFile();
		   MessageDlg("Lookup file saved!", mtInformation, TMsgDlgButtons() << mbOK, 0);
		   }
		 }
	   delete AddRepositoryForm;
	   break;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxPopupEdit12KeyUp(TObject *Sender, WORD &Key,
		  TShiftState Shift)
{
   if (Key == VK_DELETE) {
	 int dataset_num = DatasetTabsheetNum();
	 Datasets[dataset_num].Repositories.clear();
	 cxPopupEdit12->Clear();
	 }
}
//---------------------------------------------------------------------------

