//---------------------------------------------------------------------------
#include "pch.h"
#include <vcl.h>
#include <math.h>
#pragma hdrstop

#include "TIFuzzy.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDropDownEdit"
#pragma link "cxEdit"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"
TFuzzyForm *FuzzyForm;
//---------------------------------------------------------------------------
__fastcall TFuzzyForm::TFuzzyForm(TComponent* Owner)
        : TForm(Owner)
{
   TSSForm = (TTilSpreadSheetForm*)Owner;
   cxPopupEdit1->Properties->PopupControl = TSSForm->Panel2;
   cxPopupEdit2->Properties->PopupControl = TSSForm->Panel2;

   SetPreciseCoordinates(TSSForm->cxPopupEdit4->Text, TSSForm->cxPopupEdit6->Text);

   dmin = 1;
   dmax = 5;
}
//---------------------------------------------------------------------------

// Ok button
void __fastcall TFuzzyForm::cxButton1Click(TObject *Sender)
{
   double Value;
   int Result;

   Result = SetLatitude();
   if (Result == mrAbort) {
     ModalResult = mrCancel;
     return;
     }
   if (Result == mrRetry) {
     ModalResult = mrNone;
     return;
     }

   Result = SetLongitude();
   if (Result == mrAbort) {
     ModalResult = mrCancel;
     return;
     }
   if (Result == mrRetry) {
     ModalResult = mrNone;
     return;
     }

   // min/max distance values for donut
   if (TryStrToFloat(LabeledEdit1->Text, Value))
     dmin = Value;
   else {
	 MessageDlg("Minimum distance must be floating point number", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
     ModalResult = mrNone;
     }
   if (TryStrToFloat(LabeledEdit2->Text, Value))
     dmax = Value;
   else {
     MessageDlg("Maximum distance must be floating point number", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
     ModalResult = mrNone;
     }
}
//---------------------------------------------------------------------------

void TFuzzyForm::SetPreciseCoordinates(UnicodeString slat, UnicodeString slong)
{
   double Value;

   if (!slat.IsEmpty()) {
     if (TryStrToFloat(slat, Value))
       cxPopupEdit1->Text = slat;
     }
   if (!slong.IsEmpty()) {
     if (TryStrToFloat(slong, Value))
       cxPopupEdit2->Text = slong;
     }
}
//---------------------------------------------------------------------------

int TFuzzyForm::SetLatitude(void)
{
   if (cxPopupEdit1->Text.IsEmpty())
     return MessageDlg("Precise latitude not set.", mtWarning, TMsgDlgButtons() << mbRetry << mbAbort, 0);

   try {
       latitude = cxPopupEdit1->Text.ToDouble();
       double fabsLat = fabs(latitude);
       if (fabsLat < 0.0 || fabsLat > 90.0)
		 return MessageDlg("Degrees latitude must be >= 0 and <= 90", Dialogs::mtError, TMsgDlgButtons() << mbRetry << mbAbort, 0);
       }
   catch(Exception &e) {
       return MessageDlg(e.Message, Dialogs::mtError, TMsgDlgButtons() << mbRetry << mbAbort, 0);
       }

   return mrOk;
}
//---------------------------------------------------------------------------

int TFuzzyForm::SetLongitude(void)
{
   if (cxPopupEdit2->Text.IsEmpty())
     return MessageDlg("Precise longitude not set.", mtWarning, TMsgDlgButtons() << mbRetry << mbAbort, 0);

   try {
       longitude = cxPopupEdit2->Text.ToDouble();
       double fabsLong = fabs(longitude);
       if (fabsLong < -180.0 || fabsLong > 180.0)
         return MessageDlg("Degrees longitude must be >= -180 and <= 180", Dialogs::mtError, TMsgDlgButtons() << mbRetry << mbAbort, 0);
       }
   catch(Exception &e) {
	   return MessageDlg(e.Message, Dialogs::mtError, TMsgDlgButtons() << mbRetry << mbAbort, 0);
       }

   return mrOk;
}
//---------------------------------------------------------------------------

void __fastcall TFuzzyForm::cxPopupEdit1PropertiesPopup(TObject *Sender)
{
   double dd;

   TSSForm->dms = new DMSPANEL(this, TSSForm->ToolButton5, TSSForm->ToolButton7,
         TSSForm->ToolButton8, TSSForm->LabeledEdit16, TSSForm->LabeledEdit13,
         TSSForm->LabeledEdit15, TSSForm->LabeledEdit3, TSSForm->LabeledEdit9,
         TSSForm->LabeledEdit12, TSSForm->ComboBox2);

   if (cxPopupEdit1->Text.IsEmpty())
     dd = NaN;
   else if (!TryStrToFloat(cxPopupEdit1->Text, dd))
     dd = NaN;

   TSSForm->dms->initialize(TSSForm->DMSStyle, dd, LATITUDE);
   TSSForm->SetLatLongPopupEdit(cxPopupEdit1);
}
//---------------------------------------------------------------------------

void __fastcall TFuzzyForm::cxPopupEdit1PropertiesCloseUp(TObject *Sender)
{
   TSSForm->DMSStyle = TSSForm->dms->DMSStyle;
   delete TSSForm->dms;
   SetLatitude();
}
//---------------------------------------------------------------------------

void __fastcall TFuzzyForm::cxPopupEdit2PropertiesPopup(TObject *Sender)
{
   double dd;

   TSSForm->dms = new DMSPANEL(this, TSSForm->ToolButton5, TSSForm->ToolButton7,
         TSSForm->ToolButton8, TSSForm->LabeledEdit16, TSSForm->LabeledEdit13,
         TSSForm->LabeledEdit15, TSSForm->LabeledEdit3, TSSForm->LabeledEdit9,
         TSSForm->LabeledEdit12, TSSForm->ComboBox2);

   if (cxPopupEdit2->Text.IsEmpty())
     dd = NaN;
   else if (!TryStrToFloat(cxPopupEdit2->Text, dd))
     dd = NaN;

   TSSForm->dms->initialize(TSSForm->DMSStyle, dd, LONGITUDE);
   TSSForm->SetLatLongPopupEdit(cxPopupEdit2);
}
//---------------------------------------------------------------------------

void __fastcall TFuzzyForm::cxPopupEdit2PropertiesCloseUp(TObject *Sender)
{
   TSSForm->DMSStyle = TSSForm->dms->DMSStyle;
   delete TSSForm->dms;
   SetLongitude();
}
//---------------------------------------------------------------------------

