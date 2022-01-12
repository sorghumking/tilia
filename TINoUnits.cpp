//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TINoUnits.h"
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
#pragma resource "*.dfm"
TConfirmNoUnitsForm *ConfirmNoUnitsForm;
//---------------------------------------------------------------------------
__fastcall TConfirmNoUnitsForm::TConfirmNoUnitsForm(TComponent* Owner)
	: TForm(Owner)
{
   RadioCheck = true;
}
//---------------------------------------------------------------------------

void __fastcall TConfirmNoUnitsForm::cxCheckListBox1ClickCheck(TObject *Sender, int AIndex,
		  TcxCheckBoxState APrevState, TcxCheckBoxState ANewState)
{
   if (ANewState == cbsChecked) {
	 for (int i=0; i<cxCheckListBox1->Count; i++) {
	   if (i != AIndex) {
		 TcxCheckListBoxItem* Item = cxCheckListBox1->Items->Items[i];
		 Item->Checked = false;
		 }
	   }
	 RadioCheck = false;
	 RadioGroup1->ItemIndex = 0;
	 RadioCheck = true;
	 }
   else
	 RadioGroup1->ItemIndex = -1;
}
//---------------------------------------------------------------------------

// Ok button
void __fastcall TConfirmNoUnitsForm::cxButton1Click(TObject *Sender)
{
  if (RadioGroup1->ItemIndex < 0) {
	MessageDlg(L"No confirmation has been selected!", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	ModalResult = mrNone;
	}
  else {
	if (RadioGroup1->ItemIndex == 0) {
	  for (int i=0; i<cxCheckListBox1->Count; i++) {
		TcxCheckListBoxItem* Item = cxCheckListBox1->Items->Items[i];
		if (Item->Checked) {
		  Units = cxCheckListBox1->Items->Items[i]->Text;
		  break;
		  }
		}
	  }
	ModalResult = mrOk;
	}
}
//---------------------------------------------------------------------------

void __fastcall TConfirmNoUnitsForm::RadioGroup1Click(TObject *Sender)
{
  bool checked;

  if (!RadioCheck)
	return;

  switch (RadioGroup1->ItemIndex) {
	case 0:
	  checked = false;
	  for (int i=0; i<cxCheckListBox1->Count; i++) {
		TcxCheckListBoxItem* Item = cxCheckListBox1->Items->Items[i];
		if (Item->Checked) {
		  checked = true;
		  break;
		  }
		}
	  if (!checked) {
		MessageDlg(L"No units checked!", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		RadioGroup1->ItemIndex = -1;
		}
	  break;
	case 1:
	case 2:
	  for (int i=0; i<cxCheckListBox1->Count; i++) {
		TcxCheckListBoxItem* Item = cxCheckListBox1->Items->Items[i];
		Item->Checked = false;
		}
	  break;
	}
}
//---------------------------------------------------------------------------

__fastcall TConfirmNoElementsForm::TConfirmNoElementsForm(TComponent* Owner)
	: TConfirmNoUnitsForm(Owner)
{
   Caption = L"Confirm No Elements";
   Label2->Caption = L"Has variables with the following elements in Neotoma:";
   RadioGroup1->Items->Clear();
   RadioGroup1->Items->Add(L"Variable should have elements checked above");
   RadioGroup1->Items->Add(L"Variable should have elements, but are not in list above");
   RadioGroup1->Items->Add(L"Variable does not have elements");
}
//---------------------------------------------------------------------------

// Ok button
void __fastcall TConfirmNoElementsForm::cxButton1Click(TObject *Sender)
{
  if (RadioGroup1->ItemIndex < 0) {
	MessageDlg(L"No confirmation has been selected!", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	ModalResult = mrNone;
	}
  else {
	if (RadioGroup1->ItemIndex == 0) {
	  for (int i=0; i<cxCheckListBox1->Count; i++) {
		TcxCheckListBoxItem* Item = cxCheckListBox1->Items->Items[i];
		if (Item->Checked) {
		  Elements = cxCheckListBox1->Items->Items[i]->Text;
		  break;
		  }
		}
	  }
	ModalResult = mrOk;
	}
}
//---------------------------------------------------------------------------

void __fastcall TConfirmNoElementsForm::RadioGroup1Click(TObject *Sender)
{
  bool checked;

  if (!RadioCheck)
	return;

  switch (RadioGroup1->ItemIndex) {
	case 0:
	  checked = false;
	  for (int i=0; i<cxCheckListBox1->Count; i++) {
		TcxCheckListBoxItem* Item = cxCheckListBox1->Items->Items[i];
		if (Item->Checked) {
		  checked = true;
		  break;
		  }
		}
	  if (!checked) {
		MessageDlg(L"No elements checked!", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		RadioGroup1->ItemIndex = -1;
		}
	  break;
	case 1:
	case 2:
	  for (int i=0; i<cxCheckListBox1->Count; i++) {
		TcxCheckListBoxItem* Item = cxCheckListBox1->Items->Items[i];
		Item->Checked = false;
		}
	  break;
	}
}
//---------------------------------------------------------------------------



