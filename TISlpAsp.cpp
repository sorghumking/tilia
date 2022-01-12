//---------------------------------------------------------------------------

#include <vcl.h>
#include "pch.h"
#pragma hdrstop

#include "TISlpAsp.h"
#ifndef TISpreadH
#include "TISpread.h"
#endif

//---------------------------------------------------------------------------

#pragma package(smart_init)
//---------------------------------------------------------------------------

// Slope Angle
// degrees slope
void __fastcall TTilSpreadSheetForm::cxButton7Click(TObject *Sender)
{
   // convert percent to degrees
   double Y =  cxSpinEdit1->Value;
   double X =  100.0;
   double theta = RadToDeg(Math::ArcTan2(Y, X));
   cxSpinEdit1->Value = SimpleRoundTo(theta, 0);
   // max of 90 deg
   cxSpinEdit1->Properties->MaxValue = 90;
}
//---------------------------------------------------------------------------

// percent slope
void __fastcall TTilSpreadSheetForm::cxButton8Click(TObject *Sender)
{
   // convert degrees to percent
   double theta =  cxSpinEdit1->Value;
   double Y = 100.0*Tan(DegToRad(theta));
   cxSpinEdit1->Value = SimpleRoundTo(Y, 0);
   // max of 100%
   cxSpinEdit1->Properties->MaxValue = 100;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxSpinEdit1PropertiesValidate(
      TObject *Sender, Variant &DisplayValue, TCaption &ErrorText,
      bool &Error)
{
   int Value = DisplayValue;
   if (cxButton7->Down)
     cxButton8->Enabled = (Value <= 45);
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxSpinEdit1PropertiesChange(
      TObject *Sender)
{
   int Value = cxSpinEdit1->Value;
   if (cxButton7->Down)
     cxButton8->Enabled = (Value <= 45);
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxPopupEdit13PropertiesInitPopup(
      TObject *Sender)
{
   cxButton7->Down = true;

   double Slope;
   if (cxPopupEdit13->Text.IsEmpty())
     cxSpinEdit1->Value = 0;
   else if (TryStrToFloat(cxPopupEdit13->Text, Slope))
     cxSpinEdit1->Value = SimpleRoundTo(Slope, 0);
   else if (!CollPtr->SlopeAngle.IsEmpty())
     cxSpinEdit1->Value = CollPtr->SlopeAngle;
   else
     cxSpinEdit1->Value = 0;
}
//---------------------------------------------------------------------------

// Ok button
void __fastcall TTilSpreadSheetForm::cxButton9Click(TObject *Sender)
{
   if (cxButton7->Down)
     cxPopupEdit13->Text = cxSpinEdit1->Value;
   else {
     // convert percent to degrees
     double Y =  cxSpinEdit1->Value;
     double X =  100.0;
     double theta = RadToDeg(Math::ArcTan2(Y, X));
     cxPopupEdit13->Text = FloatToStr(SimpleRoundTo(theta, 0));
     }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxPopupEdit13PropertiesValidate(
      TObject *Sender, Variant &DisplayValue, TCaption &ErrorText,
      bool &Error)
{
   double Slope;
   UnicodeString Text = DisplayValue;
   if (!Text.IsEmpty()) {
	 if (TryStrToFloat(Text, Slope)) {
	   if (Slope > 90.0 || Slope < 0.0) {
		 MessageDlg("Slope must be a value between 0 and 90.", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 DisplayValue = Variant::Empty();
		 if (PageControl1->ActivePage == TabSheet2)
		   FocusControl(cxPopupEdit13);
		 }
	   else
		 DisplayValue = SimpleRoundTo(Slope, 0);   // in case rounded
	   }
     else {
	   MessageDlg("Slope must be an integer number.", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   DisplayValue = Variant::Empty();
       if (PageControl1->ActivePage == TabSheet2)
         FocusControl(cxPopupEdit13);
       }
     }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxPopupEdit13Exit(TObject *Sender)
{
   double Slope;

   if (PageControl1->ActivePage == TabSheet1)
     ProfGrid1->RowHeights[ProfGrid1->Row] = CurrentRowHeight;
   else if (PageControl1->ActivePage == TabSheet2) {
     if (cxPopupEdit13->Text.IsEmpty())
	   CollPtr->SlopeAngle = Unassigned();
     else
       CollPtr->SlopeAngle = StrToInt(cxPopupEdit13->Text);
	 }
}
//---------------------------------------------------------------------------

// Slope Aspect
void __fastcall TTilSpreadSheetForm::cxPopupEdit14PropertiesInitPopup(
      TObject *Sender)
{
   double Aspect;

   vector<TWinControl*> Buttons;
   Buttons.push_back(cxAspectButtonN);
   Buttons.push_back(cxAspectButtonNNE);
   Buttons.push_back(cxAspectButtonNE);
   Buttons.push_back(cxAspectButtonENE);
   Buttons.push_back(cxAspectButtonE);
   Buttons.push_back(cxAspectButtonESE);
   Buttons.push_back(cxAspectButtonSE);
   Buttons.push_back(cxAspectButtonSSE);
   Buttons.push_back(cxAspectButtonS);
   Buttons.push_back(cxAspectButtonSSW);
   Buttons.push_back(cxAspectButtonSW);
   Buttons.push_back(cxAspectButtonWSW);
   Buttons.push_back(cxAspectButtonW);
   Buttons.push_back(cxAspectButtonWNW);
   Buttons.push_back(cxAspectButtonNW);
   Buttons.push_back(cxAspectButtonNNW);

   int FirstButton;
   if (cxPopupEdit14->Text.IsEmpty())
     FirstButton = 16;
   else if (TryStrToFloat(cxPopupEdit14->Text, Aspect)) {
     int iAspect = SimpleRoundTo(Aspect, 0);
     switch (iAspect) {
       case 0:   FirstButton = 0;  break;
       case 23:  FirstButton = 1;  break;
       case 45:  FirstButton = 2;  break;
       case 68:  FirstButton = 3;  break;
       case 90:  FirstButton = 4;  break;
       case 113: FirstButton = 5;  break;
       case 135: FirstButton = 6;  break;
       case 158: FirstButton = 7;  break;
       case 180: FirstButton = 8;  break;
       case 203: FirstButton = 9;  break;
       case 225: FirstButton = 10; break;
       case 248: FirstButton = 11; break;
       case 270: FirstButton = 12; break;
       case 293: FirstButton = 13; break;
       case 315: FirstButton = 14; break;
       case 338: FirstButton = 15; break;
       default:  // find nearest button
         float degrees = 0.0;
         FirstButton = 0;
         while (degrees < 360.0) {
           float nextstep = degrees + 22.5;
           if (Aspect > nextstep) {
             degrees = nextstep;
             FirstButton++;
             }
           else {
             if (Aspect-degrees > nextstep-Aspect)
               FirstButton++;
             degrees = 361.0;
             }
           }
         break;
       }
     }
   else
     FirstButton = 16;

   if (FirstButton < 16) {
     int TabOrder = 0;
     for (int i=FirstButton; i<16; i++)
       Buttons[i]->TabOrder = TabOrder++;
     for (int i=0; i<FirstButton; i++)
       Buttons[i]->TabOrder = TabOrder++;
     }
   else {
     Panel13->TabOrder = 0;
     for (int i=0; i<16; i++)
       Buttons[i]->TabOrder = i+1;
     }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxAspectButtonNClick(TObject *Sender)
{
   cxPopupEdit14->Text = "0";
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxAspectButtonNNEClick(
      TObject *Sender)
{
   cxPopupEdit14->Text = "23";
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxAspectButtonNEClick(TObject *Sender)
{
   cxPopupEdit14->Text = "45";
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxAspectButtonENEClick(
      TObject *Sender)
{
   cxPopupEdit14->Text = "68";
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxAspectButtonEClick(TObject *Sender)
{
   cxPopupEdit14->Text = "90";
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxAspectButtonESEClick(
      TObject *Sender)
{
   cxPopupEdit14->Text = "113";
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxAspectButtonSEClick(TObject *Sender)
{
   cxPopupEdit14->Text = "135";
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxAspectButtonSSEClick(
      TObject *Sender)
{
   cxPopupEdit14->Text = "158";
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxAspectButtonSClick(TObject *Sender)
{
   cxPopupEdit14->Text = "180";
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxAspectButtonSSWClick(
      TObject *Sender)
{
   cxPopupEdit14->Text = "203";
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxAspectButtonSWClick(TObject *Sender)
{
   cxPopupEdit14->Text = "225";
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxAspectButtonWSWClick(
      TObject *Sender)
{
   cxPopupEdit14->Text = "148";
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxAspectButtonWClick(TObject *Sender)
{
   cxPopupEdit14->Text = "270";
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxAspectButtonWNWClick(
      TObject *Sender)
{
   cxPopupEdit14->Text = "293";
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxAspectButtonNWClick(TObject *Sender)
{
   cxPopupEdit14->Text = "315";
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxAspectButtonNNWClick(
      TObject *Sender)
{
   cxPopupEdit14->Text = "338";
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxPopupEdit14PropertiesValidate(
      TObject *Sender, Variant &DisplayValue, TCaption &ErrorText,
      bool &Error)
{
   double Aspect;
   UnicodeString Text = DisplayValue;
   if (!Text.IsEmpty()) {
     if (TryStrToFloat(Text, Aspect))  {
       DisplayValue = SimpleRoundTo(Aspect, 0);   // in case rounded
       if (Aspect > 360.0) {
		 MessageDlg("Aspect can be no greater than 360°", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
         DisplayValue = "360";
		 if (PageControl1->ActivePage == TabSheet2)
		   FocusControl(cxPopupEdit14);
         }
       else if (Aspect < 0.0) {
		 MessageDlg("Aspect can be no less than 0°", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
         DisplayValue = "0";
         if (PageControl1->ActivePage == TabSheet2)
           FocusControl(cxPopupEdit14);
         }
       }
     else {
	   MessageDlg("Aspect must be an integer number.", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
       DisplayValue = Variant::Empty();
       if (PageControl1->ActivePage == TabSheet2)
         FocusControl(cxPopupEdit14);
       }
     }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxPopupEdit14Exit(TObject *Sender)
{
   if (PageControl1->ActivePage == TabSheet1)
     ProfGrid1->RowHeights[ProfGrid1->Row] = CurrentRowHeight;
   else if (PageControl1->ActivePage == TabSheet2) {
     if (cxPopupEdit14->Text.IsEmpty())
	   CollPtr->SlopeAspect = Unassigned();
     else
       CollPtr->SlopeAspect = StrToInt(cxPopupEdit14->Text);
     }
}
//---------------------------------------------------------------------------

