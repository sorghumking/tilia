//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TNConfTaxNamChng.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxLabel"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxButtons"
#pragma link "cxGroupBox"
#pragma link "cxRadioGroup"
#pragma link "cxTextEdit"
#pragma resource "*.dfm"
TConfirmReplaceTaxonForm *ConfirmReplaceTaxonForm;
//---------------------------------------------------------------------------
__fastcall TConfirmReplaceTaxonForm::TConfirmReplaceTaxonForm(UnicodeString OldName,
	UnicodeString NewName, TComponent* Owner) : TForm(Owner)
{
   SaveOrigID = false;
   cxTextEdit1->Text = OldName;
   cxTextEdit2->Text = NewName;
   cxRadioGroup1->ItemIndex = -1;
}
//---------------------------------------------------------------------------

// Ok button
void __fastcall TConfirmReplaceTaxonForm::cxButton1Click(TObject *Sender)
{
   if (cxRadioGroup1->ItemIndex == -1) {
	 int rv = MessageDlg(L"Save original identification?", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo << mbCancel, 0);
	 switch (rv) {
	   case mrYes:
		 SaveOrigID = true;
		 ModalResult = mrOk;
		 break;
	   case mrNo:
		 SaveOrigID = false;
		 ModalResult = mrOk;
		 break;
	   default:
		 ModalResult = mrNone;
		 break;
	   }
	 }
   else  {
	 ModalResult = mrOk;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TConfirmReplaceTaxonForm::cxRadioGroup1Click(TObject *Sender)
{
   switch (cxRadioGroup1->ItemIndex) {
	 case 0:
	   SaveOrigID = true;
	   break;
	 case 1:
	   SaveOrigID = false;
	   break;
	 }
}
//---------------------------------------------------------------------------

