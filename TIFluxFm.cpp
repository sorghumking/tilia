//---------------------------------------------------------------------------
#include "pch.h"
#include <vcl.h>
#pragma hdrstop

#include "TIFluxFm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxCheckListBox"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"
TInfluxForm *InfluxForm;
//---------------------------------------------------------------------------
__fastcall TInfluxForm::TInfluxForm(TComponent* Owner)
		: TForm(Owner)
{
   UnicodeString VarCode, VarName, GroupCode;
   ErrorCode = 0;
   Method = -1;

   TSSForm = (TTilSpreadSheetForm*)Owner;

   int DTRow;

   int RowCount = TSSForm->AbsContentRowCount(TSSForm->ConcGrid);

   DepthList.push_back(L"Header Row 1");
   DepthRows.push_back(1);

   for (int row=3; row<=RowCount; row++) {
	 VarCode = TSSForm->ConcGrid->AbsoluteCells[1][row]->Value;
	 if (VarCode.SubString(1,6) == L"#Chron") {
	   VarName = TSSForm->ConcGrid->AbsoluteCells[2][row]->Value;
	   ChronList.push_back(VarCode + " | " + VarName);
	   ChronRows.push_back(row);
	   }
	 if (VarCode.SubString(1,6) == "L#Depth") {
	   VarName = TSSForm->ConcGrid->AbsoluteCells[2][row]->Value;
	   DepthList.push_back(VarCode + L" | " + VarName);
	   DepthRows.push_back(row);
	   }
	 else {
	   GroupCode = TSSForm->ConcGrid->AbsoluteCells[7][row]->Value;
	   if (GroupCode == L"CONC") {
		 VarName = TSSForm->ConcGrid->AbsoluteCells[2][row]->Value;
		 DTList.push_back(VarCode + " | " + VarName);
		 DTRows.push_back(row);
		 }
	   }
	 }

   if (ChronList.size() == 0) {        // if no chrons, use deposition time
	 RadioGroup1->Items->Delete(0);
	 RadioGroup1->ItemIndex = 0;
	 Method = USEDEPTIMEVAR;
	 if (DTList.size() == 0) {         // if no CONC codes, error
	   MessageDlg(L"No Chronology or Deposition Time variables in Concentrations worksheeet.\nCannot calculate influx!",
				  Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   ErrorCode = 1;
	   return;
	   }
	 else {
	   for (unsigned int i=0; i<DTList.size(); i++) {
		 TcxCheckListBoxItem* Item = cxCheckListBox1->Items->Add();
		 Item->Text = DTList[i];
		 }
	   Label1->Caption = L"Select variable for Deposition Time";
	   }
	 }
   else {
	 for (unsigned int i=0; i<ChronList.size(); i++) {
	   TcxCheckListBoxItem* Item = cxCheckListBox1->Items->Add();
	   Item->Text = ChronList[i];
	   }
	 }

   if (DTList.size() == 0) {        // No CONC and therefore no DT data
	 RadioGroup1->Items->Delete(1);
	 RadioGroup1->ItemIndex = 0;
	 }

   for (unsigned int i=0; i<DepthList.size(); i++) {
	 TcxCheckListBoxItem* Item = cxCheckListBox2->Items->Add();
	 Item->Text = DepthList[i];
	 }
   if (DepthRows.size() == 1) {     // no #Depth codes
	 cxCheckListBox2->Items->Items[0]->Checked = true;
	 cxCheckListBox2->ReadOnly = true;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TInfluxForm::cxCheckListBox1ClickCheck(TObject *Sender,
      int AIndex, TcxCheckBoxState APrevState, TcxCheckBoxState ANewState)
{
   if (ANewState == cbsChecked) {
     for (int i=0; i<cxCheckListBox1->Count; i++) {
       if (i != AIndex)
         cxCheckListBox1->Items->Items[i]->Checked = false;
       }
	 }
}
//---------------------------------------------------------------------------

void __fastcall TInfluxForm::cxCheckListBox2ClickCheck(TObject *Sender,
	  int AIndex, TcxCheckBoxState APrevState, TcxCheckBoxState ANewState)
{
   if (ANewState == cbsChecked) {
	 for (int i=0; i<cxCheckListBox2->Count; i++) {
	   if (i != AIndex)
		 cxCheckListBox2->Items->Items[i]->Checked = false;
	   }
	 }
}
//---------------------------------------------------------------------------

void __fastcall TInfluxForm::RadioGroup1Click(TObject *Sender)
{
   cxCheckListBox1->Items->Clear();
   switch (RadioGroup1->ItemIndex)
	{
	case 0:
	  for (unsigned int i=0; i<ChronList.size(); i++) {
		TcxCheckListBoxItem* Item = cxCheckListBox1->Items->Add();
		Item->Text = ChronList[i];
		}
	  Label1->Caption = L"Use Chronology";
	  break;
	case 1:
	  for (unsigned int i=0; i<DTList.size(); i++) {
		TcxCheckListBoxItem* Item = cxCheckListBox1->Items->Add();
		Item->Text = DTList[i];
		}
	  Label1->Caption = L"Select variable for Deposition Time";
	  break;
	}
}
//---------------------------------------------------------------------------

// Ok button
void __fastcall TInfluxForm::Button1Click(TObject *Sender)
{
   VarRow = -1;
   if (Method == -1)
	 Method = (RadioGroup1->ItemIndex == 0) ? CALCDEPTIME : USEDEPTIMEVAR;
   Units = RadioGroup2->ItemIndex;
   TreatNulls = RadioGroup3->ItemIndex;

   for (int i=0; i<cxCheckListBox1->Count; i++) {
	 if (cxCheckListBox1->Items->Items[i]->Checked) {
	   if (Method == CALCDEPTIME)           // calculate deposition time
		 VarRow = ChronRows[i];
	   else if (Method == USEDEPTIMEVAR)    // use deposition time variable
		 VarRow = DTRows[i];
	   break;
	   }
	 }

   if (VarRow == -1) {
	 UnicodeString msg;
	 if (Method == 0)
		msg = L"No Chronology selected!";
	 else if (Method == 1)
		msg = L"No Depostion Time selected";
	 int Result = MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbRetry << mbCancel, 0);
	 ModalResult = (Result == mrRetry) ? mrNone : mrCancel;
	 return;
	 }

   for (int i=0; i<cxCheckListBox2->Count; i++) {
	 if (cxCheckListBox2->Items->Items[i]->Checked) {
	   DepthRow = DepthRows[i];
	   break;
	   }
	 }
}
//---------------------------------------------------------------------------

