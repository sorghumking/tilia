//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TIPoly.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxMaskEdit"
#pragma link "cxSpinEdit"
#pragma link "cxTextEdit"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"
TPolynomialOptionsForm *PolynomialOptionsForm;
//---------------------------------------------------------------------------
__fastcall TPolynomialOptionsForm::TPolynomialOptionsForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TPolynomialOptionsForm::FormActivate(TObject *Sender)
{
   if (CheckBox1->Checked) {
     LabeledEdit1->Enabled = true;
     LabeledEdit1->Color = clWindow;
     LabeledEdit1->Text = FloatToStr(pFixedY);
     }
}
//---------------------------------------------------------------------------

void __fastcall TPolynomialOptionsForm::CheckBox1Click(TObject *Sender)
{
   if (CheckBox1->Checked) {
     LabeledEdit1->Enabled = true;
     LabeledEdit1->Color = clWindow;
     LabeledEdit1->Text = FloatToStr(pFixedY);
     }
   else {
     LabeledEdit1->Enabled = false;
     LabeledEdit1->Color = clBtnFace;
     }
}
//---------------------------------------------------------------------------

// Ok button
void __fastcall TPolynomialOptionsForm::Button1Click(TObject *Sender)
{
   int rv;
   double Value;

   if (CheckBox1->Checked) {
     if (LabeledEdit1->Text.Length() == 0) {
       rv = MessageDlg("No value set for minimum age.\nSet to value of first chronology control?", mtError,
                TMsgDlgButtons() << mbYes << mbNo, 0);
       if (rv == mrYes)
         pFixedY = pY0;
       else {
         rv = mrNone;
         FocusControl(LabeledEdit1);
         }
       }
     else if (TryStrToFloat(LabeledEdit1->Text, Value))
       pFixedY = Value;
     else {
       MessageDlg("Invalid input value. Must be numerical value.", mtError,
         TMsgDlgButtons() << mbOK, 0);
       FocusControl(LabeledEdit1);
       rv = mrNone;
       }

     if (rv == mrNone)
       ModalResult = mrNone;
     }
}
//---------------------------------------------------------------------------

