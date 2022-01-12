//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TIChkVarUnitsFrm.h"
#ifndef TINoUnitsH
#include "TINoUnits.h"
#endif
#ifndef TIJSONH
#include "TIJSON.h"
#endif
#ifndef TINeotomaH
#include "TINeotoma.h"
#endif
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvGrid"
#pragma link "AdvObj"
#pragma link "BaseGrid"
#pragma link "cxButtons"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "ipwjson"
#pragma link "AdvCGrid"
#pragma link "AdvUtil"
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
#pragma link "dxSkinOffice2016Colorful"
#pragma link "dxSkinOffice2016Dark"
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
#pragma link "dxSkinVisualStudio2013Blue"
#pragma link "dxSkinVisualStudio2013Dark"
#pragma link "dxSkinVisualStudio2013Light"
#pragma link "dxSkinVS2010"
#pragma link "dxSkinWhiteprint"
#pragma link "dxSkinXmas2008Blue"
#pragma link "ipsjsons"
#pragma resource "*.dfm"
TCheckVarUnitsForm *CheckVarUnitsForm;

//---------------------------------------------------------------------------
__fastcall TCheckVarUnitsForm::TCheckVarUnitsForm(TComponent* Owner)
	: TForm(Owner)
{
   UploadForm = (TNeotomaUploadForm*)Owner;
}
//---------------------------------------------------------------------------

void __fastcall TCheckVarUnitsForm::FormCreate(TObject *Sender)
{
   CloseQuery = true;
   RatGlyph = new Graphics::TBitmap;
   AdvColumnGrid1->AddCheckBox(0, 0, false, false);
}
//---------------------------------------------------------------------------

void __fastcall TCheckVarUnitsForm::FormDestroy(TObject *Sender)
{
   delete RatGlyph;
}
//---------------------------------------------------------------------------

void TCheckVarUnitsForm::FillEmptyUnits(vector<EMPTYVAR>& EmptyUnits)
{
   ImageList1->GetBitmap(0, RatGlyph);
   AdvColumnGrid1->ControlLook->NoDisabledButtonLook = true;
   AdvColumnGrid1->RowCount = EmptyUnits.size() + 1;
   AdvColumnGrid1->AddCheckBoxColumn(0, false, false);

   for (unsigned int i=0, row=1; i<EmptyUnits.size(); i++, row++) {
	 AdvColumnGrid1->Cells[1][row] = EmptyUnits[i].row;
	 AdvColumnGrid1->ReadOnly[1][row] = true;
	 AdvColumnGrid1->Cells[2][row] = EmptyUnits[i].code;
	 AdvColumnGrid1->ReadOnly[2][row] = true;
	 AdvColumnGrid1->Cells[3][row] = EmptyUnits[i].name;
	 AdvColumnGrid1->ReadOnly[3][row] = true;
	 AdvColumnGrid1->Cells[4][row] = EmptyUnits[i].element;
	 AdvColumnGrid1->ReadOnly[4][row] = true;
	 AdvColumnGrid1->AddBitButton(5, row, 18, 18, L"", RatGlyph, Advgrid::haRight, vaFull);
	 }
}
//---------------------------------------------------------------------------

void __fastcall TCheckVarUnitsForm::AdvColumnGrid1CheckBoxClick(TObject *Sender, int ACol,
		  int ARow, bool State)
{
   if (State) {
	 if (ARow > 0)
	   FindTaxonUnits(AdvColumnGrid1->Cells[3][ARow], ARow);
	 }
   else
	 AdvColumnGrid1->Cells[5][ARow] = L"";
}
//---------------------------------------------------------------------------

void __fastcall TCheckVarUnitsForm::AdvColumnGrid1ButtonClick(TObject *Sender, int ACol,
		  int ARow)
{
   AdvColumnGrid1->Row = ARow;
   FindTaxonUnits(AdvColumnGrid1->Cells[3][ARow], ARow);
}
//---------------------------------------------------------------------------

void TCheckVarUnitsForm::FindTaxonUnits(UnicodeString TaxonName, int ARow)
{
   vector<UnicodeString> Units;

   Screen->Cursor = crHourGlass;
   UploadForm->SetProgressBar(MARQUEE);

   NeotomaTaxonUnits TaxonUnits(ipsJSONS1, TcpClient1);
   TaxonUnits.AddParam(L"TAXONNAME", TaxonName);
   UploadForm->StatusBar1->SimpleText = TaxonUnits.WebServiceName();
   bool success = false;
   if (TaxonUnits.Execute()) {
	 success = true;
	 if (TaxonUnits.Size() > 0)
	   Units.assign(TaxonUnits.Items.begin(), TaxonUnits.Items.end());
	 }
   Screen->Cursor = crDefault;
   UploadForm->StatusBar1->SimpleText = L"";
   if (!success) return;

   UploadForm->SetProgressBar(CORE);
   if (Units.size() > 0) {
	 ConfirmNoUnitsForm = new TConfirmNoUnitsForm(this);
	 ConfirmNoUnitsForm->LabeledEdit1->Text = TaxonName;
	 for (unsigned int j=0; j<Units.size(); j++) {
	   TcxCheckListBoxItem* Item = ConfirmNoUnitsForm->cxCheckListBox1->Items->Add();
	   Item->Text = Units[j];
	   }
	 if (ConfirmNoUnitsForm->ShowModal() == mrOk) {
	   switch (ConfirmNoUnitsForm->RadioGroup1->ItemIndex) {
		 case 0:
		   AdvColumnGrid1->Cells[5][ARow] = ConfirmNoUnitsForm->Units;
		   AdvColumnGrid1->SetCheckBoxState(0, ARow, false);
		   break;
		 case 1:
		   MessageDlg(L"Enter the units in the worksheet, or cancel and enter units in spreadsheet.",
			 mtInformation, TMsgDlgButtons() << mbOK, 0);
		   AdvColumnGrid1->GotoCell(5,ARow);
		   break;
		 case 2:
		   AdvColumnGrid1->SetCheckBoxState(0, ARow, true);
           AdvColumnGrid1->Cells[5][ARow] = L"";
		   break;
		 }
	   }
	 delete ConfirmNoUnitsForm;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TCheckVarUnitsForm::AdvColumnGrid1EditCellDone(TObject *Sender, int ACol,
		  int ARow)
{
   if (ACol == 5) {
	 if (!AdvColumnGrid1->Cells[5][ARow].IsEmpty())
	   AdvColumnGrid1->SetCheckBoxState(0, ARow, false);
	 }
}
//---------------------------------------------------------------------------

// Ok button
void __fastcall TCheckVarUnitsForm::cxButton1Click(TObject *Sender)
{
   bool checked;
   bool NewUnits = false;

   ModalResult = mrOk;
   for (int row=1; row<AdvColumnGrid1->RowCount; row++) {
	 if (!AdvColumnGrid1->Cells[5][row].IsEmpty()) {
	   NewUnits = true;
	   break;
	   }
	 }

   for (int row=1; row<AdvColumnGrid1->RowCount; row++) {
	 if (!AdvColumnGrid1->IsChecked(0, row) && AdvColumnGrid1->Cells[5][row].IsEmpty()) {
	   ModalResult = mrCancel;
	   break;
	   }
	 }

   if (ModalResult == mrCancel) {
	 ModalResult = MessageDlg(L"A variable has either not been checked as unitless or no units have been entered.",
		 mtWarning, TMsgDlgButtons() << mbRetry << mbIgnore << mbAbort, 0);
	 if (ModalResult == mrRetry)
	   ModalResult = mrNone;
	 }
   //else if (NewUnits) {   // not retry
   //	 if (MessageDlg(L"Save units to spreadsheet?",
   //		 mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrNo)
   //	 NewUnits = false;
   //	 }

   if (NewUnits) {
	 for (int row=1; row<AdvColumnGrid1->RowCount; row++) {
	   UnicodeString Units = AdvColumnGrid1->Cells[5][row];
	   if (!Units.IsEmpty()) {
		 int ARow = StrToInt(AdvColumnGrid1->Cells[1][row]);
		 UploadForm->TSSForm->ProfGrid1->AbsoluteCells[4][ARow]->Value = Units;
		 UnicodeString Var = AdvColumnGrid1->Cells[3][row];
		 if (!AdvColumnGrid1->Cells[4][row].IsEmpty())
		   Var += (L":" + AdvColumnGrid1->Cells[4][row]);
		 UploadForm->OutputLine(L"Units of variable «" + Var + L"» updated to " +
								L"«" + Units + L"».");
		 }
	   }
	 }

   if (ModalResult == mrOk) {
	 for (int row=1; row<AdvColumnGrid1->RowCount; row++) {
	   AdvColumnGrid1->GetCheckBoxState(0, row, checked);
	   if (checked) {
		 UnicodeString Var = AdvColumnGrid1->Cells[3][row];
		 if (!AdvColumnGrid1->Cells[4][row].IsEmpty())
		   Var += (L":" + AdvColumnGrid1->Cells[4][row]);
		 UploadForm->OutputLine(L"Variable «" + Var + L"» confirmed as unitless.");
		 }
	   }
	 }
   CloseQuery = (ModalResult == mrNone);
}
//---------------------------------------------------------------------------

void __fastcall TCheckVarUnitsForm::cxButton3Click(TObject *Sender)
{
   TProfGrid* ProfGrid1 = UploadForm->TSSForm->ProfGrid1;
   if (ProfGrid1->Row == ProfGrid1->TopRow)
	 ProfGrid1->Row++;
   ProfGrid1->TopRow++;
}
//---------------------------------------------------------------------------

void __fastcall TCheckVarUnitsForm::cxButton4Click(TObject *Sender)
{
   TProfGrid* ProfGrid1 = UploadForm->TSSForm->ProfGrid1;
   if (ProfGrid1->TopRow > 3) {
	 ProfGrid1->DisableControls();
	 ProfGrid1->SpreadsheetEnabled = false;
	 ProfGrid1->TopRow--;
	 if (ProfGrid1->Row > ProfGrid1->TopRow + ProfGrid1->VisibleRowCount - 1)
	   ProfGrid1->Row = ProfGrid1->TopRow + ProfGrid1->VisibleRowCount + 1;
	 ProfGrid1->SpreadsheetEnabled = true;
	 ProfGrid1->EnableControls();
	 }
}
//---------------------------------------------------------------------------

void __fastcall TCheckVarUnitsForm::cxButton5Click(TObject *Sender)
{
   TProfGrid* ProfGrid1 = UploadForm->TSSForm->ProfGrid1;
   ProfGrid1->TopRow += ProfGrid1->VisibleRowCount;
   ProfGrid1->Row = ProfGrid1->TopRow;
}
//---------------------------------------------------------------------------

void __fastcall TCheckVarUnitsForm::cxButton6Click(TObject *Sender)
{
   TProfGrid* ProfGrid1 = UploadForm->TSSForm->ProfGrid1;
   if (ProfGrid1->TopRow > 3) {
	 int TopRow = ProfGrid1->TopRow - ProfGrid1->VisibleRowCount;
	 if (TopRow < 3)
	   TopRow = 3;
	 ProfGrid1->TopRow = TopRow;
	 ProfGrid1->Row = ProfGrid1->TopRow + ProfGrid1->VisibleRowCount - 1;
	 }
}

//---------------------------------------------------------------------------

void __fastcall TCheckVarUnitsForm::FormCloseQuery(TObject *Sender, bool &CanClose)
{
   if (CloseQuery) {
	 bool NoSelection = false;
	 for (int row=1; row<AdvColumnGrid1->RowCount; row++) {
	   if (!AdvColumnGrid1->IsChecked(0, row) && AdvColumnGrid1->Cells[5][row].IsEmpty()) {
		 NoSelection = true;
		 break;
		 }
	   }
	 if (NoSelection) {
	   ModalResult = MessageDlg(L"Either a variable has not been checked as unitless or no units have been entered.",
		   mtWarning, TMsgDlgButtons() << mbRetry << mbIgnore << mbAbort, 0);
	   if (ModalResult == mrRetry)
		  ModalResult = mrNone;
	   }
	 }
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

__fastcall TCheckVarElementsForm::TCheckVarElementsForm(TComponent* Owner)
	: TCheckVarUnitsForm(Owner)
{
   UploadForm = (TNeotomaUploadForm*)Owner;
   Caption = L"Check Variable Elements";
   Label1->Caption = L"The following variables have no elements specified. Check the box in the first column if the variable has no elements. This situation is uncommon.";
}
//---------------------------------------------------------------------------

void TCheckVarElementsForm::FillEmptyElements(vector<EMPTYVAR>& EmptyElements)
{
   ImageList1->GetBitmap(0, RatGlyph);
   AdvColumnGrid1->ControlLook->NoDisabledButtonLook = true;
   AdvColumnGrid1->RowCount = EmptyElements.size() + 1;
   AdvColumnGrid1->AddCheckBoxColumn(0, false, false);

   for (unsigned int i=0, row=1; i<EmptyElements.size(); i++, row++) {
	 AdvColumnGrid1->Cells[1][row] = EmptyElements[i].row;
	 AdvColumnGrid1->ReadOnly[1][row] = true;
	 AdvColumnGrid1->Cells[2][row] = EmptyElements[i].code;
	 AdvColumnGrid1->ReadOnly[2][row] = true;
	 AdvColumnGrid1->Cells[3][row] = EmptyElements[i].name;
	 AdvColumnGrid1->ReadOnly[3][row] = true;
	 AdvColumnGrid1->Cells[5][row] = EmptyElements[i].units;
	 AdvColumnGrid1->ReadOnly[5][row] = true;
	 AdvColumnGrid1->AddBitButton(4, row, 18, 18, L"", RatGlyph, Advgrid::haRight, vaFull);
	 }
}
//---------------------------------------------------------------------------

void __fastcall TCheckVarElementsForm::AdvColumnGrid1CheckBoxClick(TObject *Sender, int ACol,
		  int ARow, bool State)
{
   if (State) {
	 if (ARow > 0) {
	   FindTaxonElements(AdvColumnGrid1->Cells[3][ARow], ARow);
	   }
	 }
   else {
	 AdvColumnGrid1->Cells[4][ARow] = L"";
	 }
}
//---------------------------------------------------------------------------

void __fastcall TCheckVarElementsForm::AdvColumnGrid1ButtonClick(TObject *Sender, int ACol,
		  int ARow)
{
   AdvColumnGrid1->Row = ARow;
   FindTaxonElements(AdvColumnGrid1->Cells[3][ARow], ARow);
}
//---------------------------------------------------------------------------

void __fastcall TCheckVarElementsForm::AdvColumnGrid1EditCellDone(TObject *Sender, int ACol,
		  int ARow)
{
   if (ACol == 4) {
	 if (!AdvColumnGrid1->Cells[4][ARow].IsEmpty())
	   AdvColumnGrid1->SetCheckBoxState(0, ARow, false);
	 }
}
//---------------------------------------------------------------------------

void TCheckVarElementsForm::FindTaxonElements(UnicodeString TaxonName, int ARow)
{
   vector<UnicodeString> Elements;
   Screen->Cursor = crHourGlass;
   UploadForm->SetProgressBar(MARQUEE);
   NeotomaTaxonElements TaxonElements(ipsJSONS1, TcpClient1);
   TaxonElements.AddParam(L"TAXONNAME", TaxonName);
   UploadForm->StatusBar1->SimpleText = TaxonElements.WebServiceName();
   bool success = false;
   if (TaxonElements.Execute()) {
	 success = true;
	 if (TaxonElements.Size() > 0)
	   Elements.assign(TaxonElements.Items.begin(), TaxonElements.Items.end());
	 }
   Screen->Cursor = crDefault;
   UploadForm->StatusBar1->SimpleText = L"";
   if (!success) return;

   UploadForm->SetProgressBar(CORE);
   if (Elements.size() > 0) {
	 TConfirmNoElementsForm* ConfirmNoElementsForm = new TConfirmNoElementsForm(this);
	 ConfirmNoElementsForm->LabeledEdit1->Text = TaxonName;
	 for (unsigned int j=0; j<Elements.size(); j++) {
	   TcxCheckListBoxItem* Item = ConfirmNoElementsForm->cxCheckListBox1->Items->Add();
	   Item->Text = Elements[j];
	   }
	 if (ConfirmNoElementsForm->ShowModal() == mrOk) {
	   switch (ConfirmNoElementsForm->RadioGroup1->ItemIndex) {
		 case 0:
		   AdvColumnGrid1->Cells[4][ARow] = ConfirmNoElementsForm->Elements;
		   AdvColumnGrid1->SetCheckBoxState(0, ARow, false);
		   break;
		 case 1:
		   MessageDlg(L"Enter the elements in the worksheet, or cancel and enter elements in spreadsheet.",
			 mtInformation, TMsgDlgButtons() << mbOK, 0);
		   AdvColumnGrid1->GotoCell(4,ARow);
		   break;
		 case 2:
		   AdvColumnGrid1->SetCheckBoxState(0, ARow, true);
           AdvColumnGrid1->Cells[4][ARow] = L"";
		   break;
		 }
	   }
	 delete ConfirmNoElementsForm;
	 }
}
//---------------------------------------------------------------------------

// Ok button
void __fastcall TCheckVarElementsForm::cxButton1Click(TObject *Sender)
{
   bool checked;
   bool NewElements = false;

   ModalResult = mrOk;
   for (int row=1; row<AdvColumnGrid1->RowCount; row++) {
	 if (!AdvColumnGrid1->Cells[4][row].IsEmpty()) {
	   NewElements = true;
	   break;
	   }
	 }

   for (int row=1; row<AdvColumnGrid1->RowCount; row++) {
	 if (!AdvColumnGrid1->IsChecked(0, row) && AdvColumnGrid1->Cells[4][row].IsEmpty()) {
	   ModalResult = mrCancel;
	   break;
	   }
	 }

   if (ModalResult == mrCancel) {
	 ModalResult = MessageDlg(L"Either a variable has not been checked as having no elements or no elements have been entered.",
		 mtWarning, TMsgDlgButtons() << mbRetry << mbIgnore << mbAbort, 0);
	 if (ModalResult == mrRetry)
	   ModalResult = mrNone;
	 }
   //else if (NewElements) {
   //	 if (MessageDlg(L"Save elements to spreadsheet?",
   //		 mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrNo)
   //	 NewElements = false;
   //	 }

   if (NewElements) {
	 for (int row=1; row<AdvColumnGrid1->RowCount; row++) {
	   UnicodeString Elements = AdvColumnGrid1->Cells[4][row];
	   if (!Elements.IsEmpty()) {
		 int ARow = StrToInt(AdvColumnGrid1->Cells[1][row]);
		 UploadForm->TSSForm->ProfGrid1->AbsoluteCells[3][ARow]->Value = Elements;
		 UnicodeString Var = AdvColumnGrid1->Cells[3][row];
		 if (!AdvColumnGrid1->Cells[5][row].IsEmpty())
		   Var += (L"::" + AdvColumnGrid1->Cells[5][row]);
		 UploadForm->OutputLine(L"Element of variable «" + Var + L"» updated to " +
								L"«" + Elements + L"».");
		 }
	   }
	 }

   if (ModalResult == mrOk) {
	 for (int row=1; row<AdvColumnGrid1->RowCount; row++) {
	   AdvColumnGrid1->GetCheckBoxState(0, row, checked);
	   if (checked) {
		 UnicodeString Var = AdvColumnGrid1->Cells[3][row];
		 if (!AdvColumnGrid1->Cells[5][row].IsEmpty())
		   Var += (L"::" + AdvColumnGrid1->Cells[5][row]);
		 UploadForm->OutputLine(L"Variable «" + Var + L"» confirmed as having no elements.");
		 }
	   }
	 }
   CloseQuery = (ModalResult == mrNone);
}
//---------------------------------------------------------------------------

void __fastcall TCheckVarElementsForm::FormCloseQuery(TObject *Sender, bool &CanClose)
{
   if (CloseQuery) {
	 bool NoSelection = false;
	 for (int row=1; row<AdvColumnGrid1->RowCount; row++) {
	   if (!AdvColumnGrid1->IsChecked(0, row) && AdvColumnGrid1->Cells[4][row].IsEmpty()) {
		 NoSelection = true;
		 break;
		 }
	   }
	 if (NoSelection) {
	   ModalResult = MessageDlg(L"A variable has either not been checked as unitless or no units have been entered.",
		   mtWarning, TMsgDlgButtons() << mbRetry << mbIgnore << mbAbort, 0);
	   if (ModalResult == mrRetry)
		  ModalResult = mrNone;
	   }
	 }
}
//---------------------------------------------------------------------------

void __fastcall TCheckVarUnitsForm::ipsJSONS1SSLServerAuthentication(TObject *Sender,
          TipsJSONSSSLServerAuthenticationEventParams *e)
{
   e->Accept = true;
}
//---------------------------------------------------------------------------

