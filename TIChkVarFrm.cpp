//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TIChkVarFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxCheckListBox"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "AdvCGrid"
#pragma link "AdvGrid"
#pragma link "AdvObj"
#pragma link "BaseGrid"
#pragma link "dxSkinBlack"
#pragma link "dxSkinBlue"
#pragma link "dxSkinBlueprint"
#pragma link "dxSkinCaramel"
#pragma link "dxSkinCoffee"
#pragma link "dxSkinDarkRoom"
#pragma link "dxSkinDarkSide"
#pragma link "dxSkinDevExpressDarkStyle"
#pragma link "dxSkinDevExpressStyle"
#pragma link "dxSkinFoggy"
#pragma link "dxSkinGlassOceans"
#pragma link "dxSkinHighContrast"
#pragma link "dxSkiniMaginary"
#pragma link "dxSkinLilian"
#pragma link "dxSkinLiquidSky"
#pragma link "dxSkinLondonLiquidSky"
#pragma link "dxSkinMcSkin"
#pragma link "dxSkinMetropolis"
#pragma link "dxSkinMetropolisDark"
#pragma link "dxSkinMoneyTwins"
#pragma link "dxSkinOffice2007Black"
#pragma link "dxSkinOffice2007Blue"
#pragma link "dxSkinOffice2007Green"
#pragma link "dxSkinOffice2007Pink"
#pragma link "dxSkinOffice2007Silver"
#pragma link "dxSkinOffice2010Black"
#pragma link "dxSkinOffice2010Blue"
#pragma link "dxSkinOffice2010Silver"
#pragma link "dxSkinOffice2013DarkGray"
#pragma link "dxSkinOffice2013LightGray"
#pragma link "dxSkinOffice2013White"
#pragma link "dxSkinPumpkin"
#pragma link "dxSkinsCore"
#pragma link "dxSkinsDefaultPainters"
#pragma link "dxSkinSeven"
#pragma link "dxSkinSevenClassic"
#pragma link "dxSkinSharp"
#pragma link "dxSkinSharpPlus"
#pragma link "dxSkinSilver"
#pragma link "dxSkinSpringTime"
#pragma link "dxSkinStardust"
#pragma link "dxSkinSummer2008"
#pragma link "dxSkinTheAsphaltWorld"
#pragma link "dxSkinValentine"
#pragma link "dxSkinVS2010"
#pragma link "dxSkinWhiteprint"
#pragma link "dxSkinXmas2008Blue"
#pragma link "AdvUtil"
#pragma link "dxSkinOffice2016Colorful"
#pragma link "dxSkinOffice2016Dark"
#pragma link "dxSkinVisualStudio2013Blue"
#pragma link "dxSkinVisualStudio2013Dark"
#pragma link "dxSkinVisualStudio2013Light"
#pragma resource "*.dfm"
TCheckListVarForm *CheckListVarForm;
//---------------------------------------------------------------------------
__fastcall TCheckListVarForm::TCheckListVarForm(TComponent* Owner)
	: TForm(Owner)
{
   UploadForm = (TNeotomaUploadForm*)Owner;
   TSSForm = UploadForm->TSSForm;
}
//---------------------------------------------------------------------------

void __fastcall TCheckListVarForm::FormCreate(TObject *Sender)
{
   //messages = new TStringList;
   CloseQuery = false;
   FItemChecked = -1;
}
//---------------------------------------------------------------------------

void __fastcall TCheckListVarForm::FormDestroy(TObject *Sender)
{
   //delete messages;
}
//---------------------------------------------------------------------------

void __fastcall TCheckListVarForm::cxButton7Click(TObject *Sender)
{
   return;
}
//---------------------------------------------------------------------------

void __fastcall TCheckListVarForm::cxButton8Click(TObject *Sender)
{
   return;
}
//---------------------------------------------------------------------------

// ok button
void __fastcall TCheckListVarForm::cxButton1Click(TObject *Sender)
{
   return;
}
//---------------------------------------------------------------------------

void __fastcall TCheckListVarForm::FormCloseQuery(TObject *Sender, bool &CanClose)
{
   CanClose = true;
}
//---------------------------------------------------------------------------

void __fastcall TCheckListVarForm::cxButton3Click(TObject *Sender)
{
   if (TSSForm->ProfGrid1->Row == TSSForm->ProfGrid1->TopRow)
	 TSSForm->ProfGrid1->Row++;
   TSSForm->ProfGrid1->TopRow++;
}
//---------------------------------------------------------------------------

void __fastcall TCheckListVarForm::cxButton4Click(TObject *Sender)
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

void __fastcall TCheckListVarForm::cxButton5Click(TObject *Sender)
{
   TSSForm->ProfGrid1->TopRow += TSSForm->ProfGrid1->VisibleRowCount;
   TSSForm->ProfGrid1->Row = TSSForm->ProfGrid1->TopRow;
}
//---------------------------------------------------------------------------

void __fastcall TCheckListVarForm::cxButton6Click(TObject *Sender)
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

void __fastcall TCheckListVarForm::AdvColumnGrid1CheckBoxClick(TObject *Sender, int ACol,
		  int ARow, bool State)
{
   if (State) {
	 FItemChecked = ARow - 1;
	 for (int row=1; row<AdvColumnGrid1->RowCount; row++) {
	   if (row == ARow) continue;
	   if (AdvColumnGrid1->IsChecked(0, row))
		 AdvColumnGrid1->SetCheckBoxState(0,row,false);
	   }
	 cxButton7->Enabled = true;
	 }
   else {
	 FItemChecked = -1;
	 cxButton7->Enabled = false;
	 }
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

__fastcall TCheckDupsForm::TCheckDupsForm(TComponent* Owner)
	: TCheckListVarForm(Owner)
{
   TSSForm = (TTilSpreadSheetForm*)Owner;
   Caption = L"Check Duplicates";
   Memo1->Height = 32;
   AdvColumnGrid1->ColCount = 3;
   int width = FlowPanel1->Width - cxButton1->Width;
   FlowPanel1->Left = (Panel2->Width - width)/2;
   cxButton1->Visible = false;
}
//---------------------------------------------------------------------------

void TCheckDupsForm::FillDupVars(vector<DUPVAR>& dp)
{
   DupVars.assign(dp.begin(), dp.end());
   AdvColumnGrid1->RowCount = DupVars.size() + 1;
   AdvColumnGrid1->AddCheckBoxColumn(0, false, false);
   for (unsigned int i=0, row=1; i<DupVars.size(); i++, row++) {
	 AdvColumnGrid1->Cells[1][row] = DupVars[i].DupName;
	 UnicodeString msg = L"in row " + IntToStr(DupVars[i].row1) +
						 L" also in row " + IntToStr(DupVars[i].row2);
	 AdvColumnGrid1->Cells[2][row] = msg;
	 }
   AdvColumnGrid1->CheckAll(0);
}
//---------------------------------------------------------------------------

// Add button
void __fastcall TCheckDupsForm::cxButton7Click(TObject *Sender)
{
   UnicodeString msg = L"Data from the variable with the higher row number will\n";
   msg += L"be added to the variable with the lower row number.";
   if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbOK << mbCancel, 0) == mrCancel)
	 return;

   vector<DUPVAR>::iterator itr;
   vector<DUPVAR>::iterator maxitr;
   vector<DUPVAR>::iterator start = DupVars.begin();

   int nchecked = 0;
   for (int i=0, row=1; row<AdvColumnGrid1->RowCount; i++, row++) {
	 DupVars[i].checked = AdvColumnGrid1->IsChecked(0, row);
	 if (DupVars[i].checked)
	   nchecked++;
	 }

   // find first checked item
   for (itr=start; itr != DupVars.end(); itr++) {
	 if (itr->checked) {
	   start = itr;
	   break;
	   }
	 }

   // next, delete duplicate rows, max row first
   TSSForm->ProfGrid1->DisableControls();
   TSSForm->ProfGrid1->SpreadsheetEnabled = false;
   while (nchecked > 0) {
	 maxitr = start;
	 for (itr=start+1; itr != DupVars.end(); itr++) {   // find max row
	   if (itr->checked && (itr->row2 > maxitr->row2))
		 maxitr = itr;
	   }
	 // add rows if necessary
	 int row1 = maxitr->row1;
	 int row2 = maxitr->row2;
	 int ColCount = TSSForm->AbsContentColCount(TSSForm->ProfGrid1);
	 int HeaderCols = TSSForm->AbsHeaderColCount(TSSForm->ProfGrid1);
	 for (int col=HeaderCols; col<=ColCount; col++) {
	   TProfGridCell* ACell1 = TSSForm->ProfGrid1->AbsoluteCells[col][row1];
	   TProfGridCell* ACell2 = TSSForm->ProfGrid1->AbsoluteCells[col][row2];
	   if (ACell1->Value.Type() == varDouble && ACell2->Value.Type() == varDouble) {
		 double x1 = ACell1->Value;
		 double x2 = ACell2->Value;
		 ACell1->Value = x1 + x2;
		 TSSForm->SpreadSheetChanged = true;
		 }
	   }

	 TSSForm->ProfGrid1->DeleteRow(maxitr->row2);
	 TSSForm->SpreadSheetChanged = true;
	 UnicodeString msg = "Variable «" + maxitr->DupName + "» in row " +
	   maxitr->row2 + L" added to «" + maxitr->DupName + L"» in row " +
	   maxitr->row1 + L".";
	 OutputLines.push_back(msg);
	 msg = "Variable «" + maxitr->DupName + "» in row " + maxitr->row2 + L" deleted.";
	 OutputLines.push_back(msg);
	 int delrow = maxitr->row2;
	 DupVars.erase(maxitr);
	 // decrement any row2's greater than the one deleted
	 for (itr=DupVars.begin(); itr != DupVars.end(); itr++) {
	   if (itr->row2 > delrow)
		 itr->row2--;
	   }
	 nchecked--;
	 }
   TSSForm->ProfGrid1->SpreadsheetEnabled = true;
   TSSForm->ProfGrid1->EnableControls();
   // remove deleted (checked) duplicates from list box
   int InitRowCount = AdvColumnGrid1->RowCount;
   for (int row=AdvColumnGrid1->RowCount-1; row>=1; row--) {
	 if (AdvColumnGrid1->IsChecked(0, row))
	   AdvColumnGrid1->RemoveRows(row,1);
	 }

   if (DupVars.size() == 0)   // otherwise ModalResult stays mrNone
	 ModalResult = mrOk;
   else if (AdvColumnGrid1->RowCount < InitRowCount) {
	 vector<UnicodeString> ErrMsgs;
	 TSSForm->GetSSVarList(SSVarList, false, ErrMsgs);
	 vector<DUPVAR> dp;
	 TSSForm->CheckVarDuplicates(SSVarList, dp);
	 FillDupVars(dp);
	 }
}
//---------------------------------------------------------------------------

void __fastcall TCheckDupsForm::cxButton8Click(TObject *Sender)
{
   UnicodeString msg = L"ERROR: Duplicates not resolved.";
   OutputErrors.push_back(msg);
}
//---------------------------------------------------------------------------

void __fastcall TCheckDupsForm::AdvColumnGrid1CheckBoxClick(TObject *Sender, int ACol,
		  int ARow, bool State)
{
   return;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

__fastcall TCheckNoDataForm::TCheckNoDataForm(TComponent* Owner)
	: TCheckListVarForm(Owner)
{
   TSSForm = (TTilSpreadSheetForm*)Owner;
   Caption = L"Empty Variables";

   Memo1->Lines->Clear();
   Memo1->Lines->Add(L"Variables with no data found.");

   Memo1->Height = 32;
   cxButton7->Caption = L"Delete Checked Rows";
   int width = FlowPanel1->Width - cxButton1->Width;
   FlowPanel1->Left = (Panel2->Width - width)/2;
   cxButton1->Visible = false;

   AdvColumnGrid1->ColCount = 3;
   AdvColumnGrid1->Columns->Items[0]->Header = L"Delete";
   AdvColumnGrid1->Columns->Items[2]->Header = L"Row";
   AdvColumnGrid1->Columns->Items[2]->Width = 64;
   AdvColumnGrid1->Columns->Items[2]->Alignment = taRightJustify;
}
//---------------------------------------------------------------------------

void TCheckNoDataForm::FillEmptyVars(vector<EMPTYVAR>& ev)
{
   EmptyVars.assign(ev.begin(), ev.end());
   AdvColumnGrid1->RowCount = EmptyVars.size() + 1;
   AdvColumnGrid1->AddCheckBoxColumn(0, false, false);
   for (unsigned int i=0, row=1; i<EmptyVars.size(); i++, row++) {
	 AdvColumnGrid1->Cells[1][row] = EmptyVars[i].name;
	 AdvColumnGrid1->Cells[2][row] = IntToStr(EmptyVars[i].row);
	 }
   AdvColumnGrid1->CheckAll(0);
}
//---------------------------------------------------------------------------

// delete checked rows
void __fastcall TCheckNoDataForm::cxButton7Click(TObject *Sender)
{
   vector<EMPTYVAR>::iterator itr;
   TSSForm->ProfGrid1->DisableControls();
   TSSForm->ProfGrid1->SpreadsheetEnabled = false;
   for (unsigned int row=AdvColumnGrid1->RowCount-1; row>=1; row--) {
	 if (AdvColumnGrid1->IsChecked(0, row)) {
	   unsigned int i = row-1;
	   TSSForm->ProfGrid1->DeleteRow(EmptyVars[i].row);
	   TSSForm->SpreadSheetChanged = true;
	   UnicodeString msg = "Variable «" + EmptyVars[i].name + "» with no data in row " + EmptyVars[i].row + L" deleted.";
	   OutputLines.push_back(msg);
	   AdvColumnGrid1->RemoveRows(row,1);
	   for (int i=row; i<AdvColumnGrid1->RowCount; i++)  // decrement SS row numbes
		 AdvColumnGrid1->Cells[2][i] = IntToStr(AdvColumnGrid1->Cells[2][i].ToInt()-1);
	   vector<EMPTYVAR>::iterator eitr = EmptyVars.begin()+i;  // element to erase
	   for (vector<EMPTYVAR>::iterator itr = eitr+1; itr != EmptyVars.end(); itr++)
		 itr->row--;  // decrement rows to account for erasure
	   EmptyVars.erase(eitr);
	   }
	 }
   TSSForm->ProfGrid1->SpreadsheetEnabled = true;
   TSSForm->ProfGrid1->EnableControls();
   if (EmptyVars.size() == 0)
     ModalResult = mrOk;
}
//---------------------------------------------------------------------------

// ignore button
void __fastcall TCheckNoDataForm::cxButton8Click(TObject *Sender)
{
   UnicodeString msg = L"ERROR: Empty data rows not resolved.";
   OutputErrors.push_back(msg);
}
//---------------------------------------------------------------------------

void __fastcall TCheckNoDataForm::FormCloseQuery(TObject *Sender, bool &CanClose)
{
   return;
}
//---------------------------------------------------------------------------

void __fastcall TCheckNoDataForm::AdvColumnGrid1CheckBoxClick(TObject *Sender, int ACol,
		  int ARow, bool State)
{
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

__fastcall TMultiTaxonNamesForm::TMultiTaxonNamesForm(TComponent* Owner)
	: TCheckListVarForm(Owner)
{
   TSSForm = (TTilSpreadSheetForm*)Owner;
   Caption = L"Multi Taxon Names";
   Memo1->Height = 32;
   cxButton7->Visible = false;
   int bwid = cxButton1->Width + cxButton8->Width + cxButton2->Width;
   FlowPanel1->Left = (Panel2->Width - bwid)/2;
   AdvColumnGrid1->ColCount = 3;
   AdvColumnGrid1->Columns->Items[0]->Header = L"Select";
   AdvColumnGrid1->Columns->Items[2]->Header = L"Taxon Name";
   AdvColumnGrid1->Columns->Items[2]->Header = L"Taxa Group Name";
}
//---------------------------------------------------------------------------

void TMultiTaxonNamesForm::FillMultiTaxonNames(int Row, UnicodeString TaxonName,
	vector<UnicodeString>& TaxaGroupNames)
{
   Memo1->Lines->Clear();
   Memo1->Text = L"Taxon «" + TaxonName + L"» in row " + IntToStr(Row) +
				 L" occurs in more than one taxon group. Check correct one.";
   AdvColumnGrid1->RowCount = TaxaGroupNames.size() + 1;
   AdvColumnGrid1->AddCheckBoxColumn(0, false, false);
   for (unsigned int i=0, row=1; i<TaxaGroupNames.size(); i++, row++) {
	 AdvColumnGrid1->Cells[1][row] = TaxonName;
	 AdvColumnGrid1->Cells[2][row] = TaxaGroupNames[i];
	 }
}
//---------------------------------------------------------------------------

// Ok button
void __fastcall TMultiTaxonNamesForm::cxButton1Click(TObject *Sender)
{
   ModalResult = mrOk;
}
//---------------------------------------------------------------------------

void __fastcall TMultiTaxonNamesForm::cxButton8Click(TObject *Sender)
{
   int rv = MessageDlg(L"No Taxon Group selected!", mtWarning, TMsgDlgButtons() << mbRetry << mbIgnore << mbAbort, 0);
   switch (rv) {
	 case mrAbort:
	   ModalResult = mrAbort;
	   CloseQuery = false;
	   break;
	 case mrIgnore:
	   ModalResult = mrIgnore;
	   CloseQuery = false;
	   break;
	 default:
	   CloseQuery = true;
	   break;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TMultiTaxonNamesForm::FormCloseQuery(TObject *Sender, bool &CanClose)
{
   if (CloseQuery) {
	 int rv = MessageDlg(L"No Taxon Group selected!", mtWarning, TMsgDlgButtons() << mbRetry << mbIgnore << mbAbort, 0);
	 switch (rv) {
	   case mrAbort:
		 ModalResult = mrAbort;
		 CanClose = true;
		 break;
	   case mrIgnore:
		 ModalResult = mrIgnore;
		 CanClose = true;
		 break;
	   default:
		 CanClose = false;
		 break;
	   }
	 }
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

__fastcall TCheckZeroDataForm::TCheckZeroDataForm(TComponent* Owner)
	: TCheckListVarForm(Owner)
{
   TSSForm = (TTilSpreadSheetForm*)Owner;
   Caption = L"Zero Variables";
   Memo1->Lines->Clear();
   Memo1->Lines->Add(L"Variables with all zero values found.");
   Memo1->Lines->Add(L"Check «Permitted» to permit zero values for that variable.");

   Memo1->Height = 32;
   cxButton7->Caption = L"Delete Checked Rows";

   AdvColumnGrid1->Columns->Items[0]->Header = L"Delete";
   AdvColumnGrid1->Columns->Items[2]->Header = L"Row";
   AdvColumnGrid1->Columns->Items[2]->Width = 64;
   AdvColumnGrid1->Columns->Items[2]->Alignment = taRightJustify;
}
//---------------------------------------------------------------------------

void TCheckZeroDataForm::FillZeroVars(vector<EMPTYVAR>& ev)
{
   ZeroVars.assign(ev.begin(), ev.end());
   AdvColumnGrid1->RowCount = ZeroVars.size() + 1;
   AdvColumnGrid1->AddCheckBoxColumn(0, false, false);
   AdvColumnGrid1->AddCheckBoxColumn(3, false, false);
   for (unsigned int i=0, row=1; i<ZeroVars.size(); i++, row++) {
	 AdvColumnGrid1->Cells[1][row] = ZeroVars[i].name;
	 AdvColumnGrid1->Cells[2][row] = IntToStr(ZeroVars[i].row);
	 }
   AdvColumnGrid1->CheckAll(0);
}
//---------------------------------------------------------------------------

// delete checked rows
void __fastcall TCheckZeroDataForm::cxButton7Click(TObject *Sender)
{
   DeleteCheckedRows();
   if (AdvColumnGrid1->RowCount == 1) {
	 MessageDlg(L"All zero rows resolved!", mtInformation, TMsgDlgButtons() << mbOK, 0);
	 ModalResult = mrOk;
     }
}
//---------------------------------------------------------------------------

void TCheckZeroDataForm::DeleteCheckedRows(void)
{
   TSSForm->ProfGrid1->DisableControls();
   TSSForm->ProfGrid1->SpreadsheetEnabled = false;
   for (unsigned int row=AdvColumnGrid1->RowCount-1; row>=1; row--) {
	 if (AdvColumnGrid1->IsChecked(0, row)) {
	   unsigned int i = row-1;
	   TSSForm->ProfGrid1->DeleteRow(ZeroVars[i].row);
	   TSSForm->SpreadSheetChanged = true;
	   UnicodeString msg = "Variable «" + ZeroVars[i].name + "» with all zero values in row " +
		   IntToStr(ZeroVars[i].row) + L" deleted.";
	   OutputLines.push_back(msg);
	   AdvColumnGrid1->RemoveRows(row,1);
       for (int i=row; i<AdvColumnGrid1->RowCount; i++)  // decrement SS row numbes
		 AdvColumnGrid1->Cells[2][i] = IntToStr(AdvColumnGrid1->Cells[2][i].ToInt()-1);
	   vector<EMPTYVAR>::iterator eitr = ZeroVars.begin()+i;  // element to erase
	   for (vector<EMPTYVAR>::iterator itr = eitr+1; itr != ZeroVars.end(); itr++)
		 itr->row--;  // decrement rows to account for erasure
	   ZeroVars.erase(eitr);
	   }
	 }
   TSSForm->ProfGrid1->SpreadsheetEnabled = true;
   TSSForm->ProfGrid1->EnableControls();
}
//---------------------------------------------------------------------------

// Ok button
void __fastcall TCheckZeroDataForm::cxButton1Click(TObject *Sender)
{
   bool error = false;
   for (int row=1, i=0; row<AdvColumnGrid1->RowCount; row++, i++) {
	 if (!(AdvColumnGrid1->IsChecked(0, row) || AdvColumnGrid1->IsChecked(3, row))) {
	   UnicodeString msg = L"Not all rows are checked for either deletion or zeros permitted!";
	   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   error = true;
	   break;
	   }
	 }
   if (!error) {
	 DeleteCheckedRows();
	 for (unsigned int i=0; i<ZeroVars.size(); i++) {
	   FZeroVarsAllowed.insert(ZeroVars[i].row);
	   UnicodeString msg = "All zero values permitted for variable «" + ZeroVars[i].name +
		 "» in row " + IntToStr(ZeroVars[i].row) + L".";
	   OutputLines.push_back(msg);
	   }
	 ModalResult = mrOk;
	 }
}
//---------------------------------------------------------------------------

// ignore button
void __fastcall TCheckZeroDataForm::cxButton8Click(TObject *Sender)
{
   UnicodeString msg = L"ERROR: Rows with all zeros not resolved.";
   OutputErrors.push_back(msg);
}
//---------------------------------------------------------------------------

void __fastcall TCheckZeroDataForm::FormCloseQuery(TObject *Sender, bool &CanClose)
{
   return;
}
//---------------------------------------------------------------------------

void __fastcall TCheckZeroDataForm::AdvColumnGrid1CheckBoxClick(TObject *Sender,
	int ACol, int ARow, bool State)
{
   if (State) {
	 if (ACol == 0)
	   AdvColumnGrid1->SetCheckBoxState(3,ARow,false);
	 else
	   AdvColumnGrid1->SetCheckBoxState(0,ARow,false);
	 }
}
//---------------------------------------------------------------------------

