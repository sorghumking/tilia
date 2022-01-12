//---------------------------------------------------------------------------

#include <vcl.h>
#include <Math.hpp>
#pragma hdrstop

#include "TILOWESS.h"
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
TLOWESSOptionsForm *LOWESSOptionsForm;
//---------------------------------------------------------------------------
__fastcall TLOWESSOptionsForm::TLOWESSOptionsForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TLOWESSOptionsForm::FormCreate(TObject *Sender)
{
   DepthWindow = NaN;
   AgeWindow = NaN;
}
//---------------------------------------------------------------------------

void __fastcall TLOWESSOptionsForm::FormActivate(TObject *Sender)
{
   if (!IsNan(DepthWindow))
     Edit1->Text = FloatToStr(DepthWindow);
   if (!IsNan(AgeWindow))
     Edit2->Text = FloatToStr(AgeWindow);
   switch (RadioGroup1->ItemIndex) {
     case 1:
       cxSpinEdit1->Enabled = false;
       Edit1->Enabled = true;
       Edit1->Color = clWindow;
       break;
     case 2:
       cxSpinEdit1->Enabled = false;
       Edit2->Enabled = true;
       Edit2->Color = clWindow;
       break;
     }
}
//---------------------------------------------------------------------------

void __fastcall TLOWESSOptionsForm::RadioGroup1Click(TObject *Sender)
{
   switch (RadioGroup1->ItemIndex) {
     case 0:
       cxSpinEdit1->Enabled = true;
       Edit1->Enabled = false;
       Edit2->Enabled = false;
       Edit1->Color = clBtnFace;
       Edit2->Color = clBtnFace;
       break;
     case 1:
       cxSpinEdit1->Enabled = false;
       Edit1->Enabled = true;
       Edit1->Color = clWindow;
       Edit2->Enabled = false;
       Edit2->Color = clBtnFace;
       break;
     case 2:
       cxSpinEdit1->Enabled = false;
       Edit2->Enabled = true;
       Edit2->Color = clWindow;
       Edit1->Enabled = false;
       Edit1->Color = clBtnFace;
       break;
     }
}
//---------------------------------------------------------------------------

// Ok button
void __fastcall TLOWESSOptionsForm::Button1Click(TObject *Sender)
{
   double Value;
   int rv = mrOk;

   switch (RadioGroup1->ItemIndex) {
     case 1:
       if (Edit1->Text.Length() == 0)
         rv = MessageDlg("No value set for window.", mtError, TMsgDlgButtons() << mbCancel << mbRetry, 0);
       else if (TryStrToFloat(Edit1->Text, Value)) {
         if (Value > MaxDepth-MinDepth) {
           MessageDlg("Depth window cannot be greater than depth range (" +
                      FloatToStr(MaxDepth-MinDepth) + ").", mtError,
                      TMsgDlgButtons() << mbOK, 0);
           DepthWindow = NaN;
           FocusControl(Edit1);
           rv = mrRetry;
           }
         else if (Value <= 0) {
           MessageDlg("Depth window must be >0.", mtError, TMsgDlgButtons() << mbOK, 0);
           DepthWindow = NaN;
           FocusControl(Edit1);
           rv = mrRetry;
           }
         else if (Value < 2.0*(MaxDepth-MinDepth)/nChronControls) {
           rv = MessageDlg("Window is narrow relative to average spacing between dates.\nMay give poor results. Accept anyway?",
                mtWarning, TMsgDlgButtons() << mbYes << mbNo, 0);
           if (rv == mrNo) {
             FocusControl(Edit1);
             rv = mrRetry;
             }
           else
             DepthWindow = Value;
           }
         else
            DepthWindow = Value;
         }
       else {
         MessageDlg("Invalid input value. Must be numerical value.", mtError,
           TMsgDlgButtons() << mbOK, 0);
         DepthWindow = NaN;
         FocusControl(Edit1);
         rv = mrRetry;
         }
       break;
     case 2:
       if (Edit2->Text.Length() == 0)
         rv = MessageDlg("No value set for window.", mtError, TMsgDlgButtons() << mbCancel << mbRetry, 0);
       else if (TryStrToFloat(Edit2->Text, Value)) {
         if (Value > MaxAge-MinAge) {
           MessageDlg("Age window cannot be greater than age range (" +
                      FloatToStr(MaxAge-MinAge) + ").", mtError,
                      TMsgDlgButtons() << mbOK, 0);
           AgeWindow = NaN;
           FocusControl(Edit2);
           rv = mrRetry;
           }
         else if (Value <= 0) {
           MessageDlg("Age window must be >0.", mtError, TMsgDlgButtons() << mbOK, 0);
           AgeWindow = NaN;
           FocusControl(Edit2);
           rv = mrRetry;
           }
         else if (Value < 2.0*(MaxAge-MinAge)/nChronControls) {
           rv = MessageDlg("Window is narrow relative to average spacing between dates.\nMay give poor results.",
                mtWarning, TMsgDlgButtons() << mbYes << mbNo, 0);
           if (rv == mrNo) {
             FocusControl(Edit2);
             rv = mrRetry;
             }
           else
             AgeWindow = Value;
           }
         else
           AgeWindow = Value;
         }
       else {
         MessageDlg("Invalid input value. Must be numerical value.", mtError,
           TMsgDlgButtons() << mbOK, 0);
         AgeWindow = NaN;
         FocusControl(Edit2);
         rv = mrRetry;
         }
       break;
     }
   if (rv == mrCancel)
     ModalResult = mrCancel;
   else if (rv == mrRetry)
     ModalResult = mrNone;
}
//---------------------------------------------------------------------------

