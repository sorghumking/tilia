//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TISynFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvGrid"
#pragma link "AdvObj"
#pragma link "BaseGrid"
#pragma link "cxButtons"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "AdvCGrid"
#pragma resource "*.dfm"
TSynonymsForm *SynonymsForm;
TLocalSynonymsForm *LocalSynonymsForm;

//---------------------------------------------------------------------------
__fastcall TSynonymsForm::TSynonymsForm(vector<SYNONYMROW>& sr, TComponent* Owner)
	: TForm(Owner)
{
   TSSForm = (TTilSpreadSheetForm*)Owner;
   Glyph = new Graphics::TBitmap;
   SetSynonyms(sr);
}
//---------------------------------------------------------------------------

void __fastcall TSynonymsForm::FormDestroy(TObject *Sender)
{
   delete Glyph;
}
//---------------------------------------------------------------------------

void TSynonymsForm::SetSynonyms(vector<SYNONYMROW>& sr)
{
   ImageList1->GetBitmap(0, Glyph);

   synrows.assign(sr.begin(), sr.end());
   AdvColumnGrid1->RowCount = synrows.size() + 1;
   AdvColumnGrid1->AddCheckBoxColumn(0, false, false);
   AdvColumnGrid1->AddCheckBoxColumn(4, false, false);
   AdvColumnGrid1->AddBitButton(3, 1, 18, 18, L"", Glyph, Advgrid::haFull, Advgrid::vaFull);
   unsigned int row = 1;
   for (unsigned int i=0; i<synrows.size(); i++) {
	 UnicodeString SynonymName = synrows[i].SynonymName;
	 bool found = false;
	 if (row > 1) {
	   for (unsigned int r2=1; r2<row; r2++) {
		 if (SynonymName == AdvColumnGrid1->Cells[1][r2]) {
		   found = true;
		   break;
		   }
		 }
	   }
	 if (!found) {
	   idx[row] = i;
	   AdvColumnGrid1->Cells[1][row] = SynonymName;
	   AdvColumnGrid1->Cells[2][row] = synrows[i].taxon->Name;
	   AdvColumnGrid1->AddBitButton(3, row, 18, 18, L"", Glyph, Advgrid::haFull, Advgrid::vaFull);
	   row++;
	   }
	 }
   AdvColumnGrid1->RowCount = row;
   AdvColumnGrid1->CheckAll(0);
}
//---------------------------------------------------------------------------

void TSynonymsForm::GetSynonyms(vector<SYNONYMROW>& sr)
{
   sr.clear();
   sr.assign(synrows.begin(), synrows.end());

}
//---------------------------------------------------------------------------

// Replace button
void __fastcall TSynonymsForm::cxButton7Click(TObject *Sender)
{
   UnicodeString msg;
   bool AllReplaced = true;
   bool SomeReplaced = false;
   for (int row=1; row<AdvColumnGrid1->RowCount; row++) {
	 if (AdvColumnGrid1->IsChecked(0, row))
	   SomeReplaced = true;
	 else
	   AllReplaced = false;
	 }
   if (!AllReplaced) {
	 if (SomeReplaced)
	   msg = L"Not all depreciated taxon names will be replaced with valid names.";
	 else
	   msg = L"No depreciated names will be replaced with valid names.";
	 int rv = MessageDlg(msg, mtWarning, TMsgDlgButtons() << mbOK << mbRetry << mbAbort, 0);
	 switch (rv) {
	   case mrOk:
		 ModalResult = mrOk;
		 break;
	   case mrRetry:
		 ModalResult = mrNone;
		 return;
	   case mrAbort:
		 ModalResult = mrAbort;
		 return;
	   }
	 }

   int orig_ids_saved = 0;
   int nsyn = AdvColumnGrid1->RowCount - 1;
   // apply to multiple instances of the same taxon name
   for (unsigned int i=0; i<synrows.size(); i++) {
	 for (int row=1; row<AdvColumnGrid1->RowCount; row++) {
	   if (synrows[i].SynonymName == AdvColumnGrid1->Cells[1][row]) {
		 synrows[i].replace = AdvColumnGrid1->IsChecked(0, row);
		 synrows[i].orig_id = AdvColumnGrid1->IsChecked(4, row);
		 if (synrows[i].orig_id)
		   orig_ids_saved++;
		 }
	   }
	 }

   msg = L"";
   if (orig_ids_saved == 0)
	 msg = L"No original identifications will be saved.";
   else if (orig_ids_saved < nsyn)
	 msg = L"Not all original identifications are checked for saving.";

   if (msg.IsEmpty())
	 ModalResult = mrOk;
   else {
	 int rv = MessageDlg(msg, mtWarning, TMsgDlgButtons() << mbOK << mbRetry << mbAbort, 0);
	 switch (rv) {
	   case mrOk:
		 ModalResult = mrOk;
		 break;
	   case mrRetry:
		 ModalResult = mrNone;
		 return;
	   case mrAbort:
		 ModalResult = mrAbort;
		 break;
	   }
	 }
}
//---------------------------------------------------------------------------

// Cancel button
void __fastcall TSynonymsForm::cxButton8Click(TObject *Sender)
{
   int rv = MessageDlg(L"Synonyms not resolved!", mtWarning, TMsgDlgButtons() << mbRetry << mbIgnore << mbAbort, 0);
   switch (rv) {
	 case mrIgnore:
	   ModalResult = mrIgnore;
	   break;
	 case mrAbort:
	   ModalResult = mrAbort;
	   break;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TSynonymsForm::AdvColumnGrid1CheckBoxClick(TObject *Sender, int ACol,
		  int ARow, bool State)
{
   if (ACol == 0) {
	 if (State)
	   AdvColumnGrid1->ReadOnly[4][ARow] = false;
	 else {
	   AdvColumnGrid1->SetCheckBoxState(4, ARow, false);
	   AdvColumnGrid1->ReadOnly[4][ARow] = true;
	   }
	 }
}
//---------------------------------------------------------------------------

// scroll spreadsheet row down
void __fastcall TSynonymsForm::cxButton3Click(TObject *Sender)
{
   if (TSSForm->ProfGrid1->Row == TSSForm->ProfGrid1->TopRow)
	 TSSForm->ProfGrid1->Row++;
   TSSForm->ProfGrid1->TopRow++;
}
//---------------------------------------------------------------------------

// scroll spreadsheet row up
void __fastcall TSynonymsForm::cxButton4Click(TObject *Sender)
{
   if (TSSForm->ProfGrid1->TopRow > 3) {
     TSSForm->ProfGrid1->DisableControls();
	 TSSForm->ProfGrid1->SpreadsheetEnabled = false;
	 TSSForm->ProfGrid1->TopRow--;
	 if (TSSForm->ProfGrid1->Row > TSSForm->ProfGrid1->TopRow + TSSForm->ProfGrid1->VisibleRowCount - 1)
	   TSSForm->ProfGrid1->Row = TSSForm->ProfGrid1->TopRow + TSSForm->ProfGrid1->VisibleRowCount + 1;
     TSSForm->ProfGrid1->SpreadsheetEnabled = true;
	 TSSForm->ProfGrid1->EnableControls();
	 }
}
//---------------------------------------------------------------------------

// scroll spreadsheet page down
void __fastcall TSynonymsForm::cxButton5Click(TObject *Sender)
{
   TSSForm->ProfGrid1->TopRow += TSSForm->ProfGrid1->VisibleRowCount;
   TSSForm->ProfGrid1->Row = TSSForm->ProfGrid1->TopRow;
}
//---------------------------------------------------------------------------

// scroll spreadsheet page up
void __fastcall TSynonymsForm::cxButton6Click(TObject *Sender)
{
   if (TSSForm->ProfGrid1->TopRow > 3) {
	 int TopRow = TSSForm->ProfGrid1->TopRow - TSSForm->ProfGrid1->VisibleRowCount;
	 if (TopRow < 3)
	   TopRow = 3;
	 TSSForm->ProfGrid1->TopRow = TopRow;
	 TSSForm->ProfGrid1->Row = TSSForm->ProfGrid1->TopRow + TSSForm->ProfGrid1->VisibleRowCount - 1;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TSynonymsForm::AdvColumnGrid1GridHint(TObject *Sender, int ARow, int ACol,
		  UnicodeString &hintstr)
{
   if (ACol == 3)
	 hintstr = L"Show synonymy details";
   else
	 hintstr = L"";
}
//---------------------------------------------------------------------------

// show synonyms info from Neotoma
void __fastcall TSynonymsForm::AdvColumnGrid1ButtonClick(TObject *Sender, int ACol,
		  int ARow)
{
   //vector<SYNONYMROW>::pointer srptr = &synrows[ARow-1];
   vector<SYNONYMROW>::pointer srptr = &synrows[idx[ARow]];
   SynonymInfoForm = new TSynonymInfoForm(srptr, this);
   SynonymInfoForm->ShowModal();
   delete SynonymInfoForm;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

__fastcall TLocalSynonymsForm::TLocalSynonymsForm(vector<SYNONYMROW>& sr, TComponent* Owner)
	: TSynonymsForm(sr, Owner)
{
   Label1->Caption = L"Synonyms have been found. Check rows to replace depreciated names with valid names.";
   AdvColumnGrid1->Columns->Items[2]->Header = L"Valid Name";
}
//---------------------------------------------------------------------------

void __fastcall TLocalSynonymsForm::AdvColumnGrid1GridHint(TObject *Sender, int ARow, int ACol,
		  UnicodeString &hintstr)
{
   if (ACol == 3)
	 hintstr = L"Show synonymy details from Neotoma";
   else
	 hintstr = L"";
}
//---------------------------------------------------------------------------

// Replace button
void __fastcall TLocalSynonymsForm::cxButton7Click(TObject *Sender)
{
   UnicodeString msg;
   bool AllReplaced = true;
   bool SomeReplaced = false;
   for (int row=1; row<AdvColumnGrid1->RowCount; row++) {
	 if (AdvColumnGrid1->IsChecked(0, row))
	   SomeReplaced = true;
	 else
	   AllReplaced = false;
	 }
   if (!AllReplaced) {
	 if (SomeReplaced)
	   msg = L"Not all depreciated taxon names will be replaced with valid names.";
	 else
	   msg = L"No depreciated names will be replaced with valid names.";
	 int rv = MessageDlg(msg, mtWarning, TMsgDlgButtons() << mbOK << mbRetry, 0);
	 switch (rv) {
	   case mrOk:
		 ModalResult = mrOk;
		 break;
	   case mrRetry:
		 ModalResult = mrNone;
		 return;
	   }
	 }

   int orig_ids_saved = 0;
   int nsyn = AdvColumnGrid1->RowCount - 1;
   // apply to multiple instances of the same taxon name
   for (unsigned int i=0; i<synrows.size(); i++) {
	 for (int row=1; row<AdvColumnGrid1->RowCount; row++) {
	   if (synrows[i].SynonymName == AdvColumnGrid1->Cells[1][row]) {
		 synrows[i].replace = AdvColumnGrid1->IsChecked(0, row);
		 synrows[i].orig_id = AdvColumnGrid1->IsChecked(4, row);
		 if (synrows[i].orig_id)
		   orig_ids_saved++;
		 }
	   }
	 }

   msg = L"";
   if (orig_ids_saved == 0)
	 msg = L"No original identifications will be saved.";
   else if (orig_ids_saved < nsyn)
	 msg = L"Not all original identifications are checked for saving.";

   if (msg.IsEmpty())
	 ModalResult = mrOk;
   else {
	 int rv = MessageDlg(msg, mtWarning, TMsgDlgButtons() << mbOK << mbRetry, 0);
	 switch (rv) {
	   case mrOk:
		 ModalResult = mrOk;
		 break;
	   case mrRetry:
		 ModalResult = mrNone;
		 return;
	   }
	 }
}
//---------------------------------------------------------------------------

