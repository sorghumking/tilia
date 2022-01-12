//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TNSSAge.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxLabel"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxRadioGroup"
#pragma link "cxCalendar"
#pragma link "cxDateUtils"
#pragma link "cxDropDownEdit"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "dxCore"
#pragma link "cxButtons"
#pragma link "cxImage"
#pragma link "dxGDIPlusClasses"
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
#pragma link "dxSkinOffice2016Colorful"
#pragma link "dxSkinOffice2016Dark"
#pragma link "dxSkinVisualStudio2013Blue"
#pragma link "dxSkinVisualStudio2013Dark"
#pragma link "dxSkinVisualStudio2013Light"
#pragma link "cxCheckBox"
#pragma resource "*.dfm"
TSurfaceSampleAgeForm *SurfaceSampleAgeForm;
//---------------------------------------------------------------------------
__fastcall TSurfaceSampleAgeForm::TSurfaceSampleAgeForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void TSurfaceSampleAgeForm::SetManual(void)
{
   cxButton2->Visible = false;
   cxButton3->Caption = L"Cancel";
   cxButton3->ModalResult = mrCancel;
   FlowPanel4->Left += cxButton2->Width/2;
   cxCheckBox1->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TSurfaceSampleAgeForm::cxRadioButton1Click(TObject *Sender)
{
   if (cxRadioButton1->Checked) {
	 cxRadioButton2->Checked = false;
	 cxRadioButton3->Checked = false;
	 cxDateEdit1->Enabled = true;
	 cxTextEdit1->Enabled = false;
	 cxRadioButton4->Enabled = false;
	 cxRadioButton5->Enabled = false;
	 cxTextEdit2->Enabled = false;
	 cxTextEdit3->Enabled = false;
	 cxRadioButton6->Enabled = false;
	 cxRadioButton7->Enabled = false;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TSurfaceSampleAgeForm::cxRadioButton2Click(TObject *Sender)
{
   if (cxRadioButton2->Checked) {
	 cxRadioButton1->Checked = false;
	 cxRadioButton3->Checked = false;
	 cxDateEdit1->Enabled = false;
	 cxTextEdit1->Enabled = true;
	 cxRadioButton4->Enabled = true;
	 cxRadioButton5->Enabled = true;
	 cxTextEdit2->Enabled = false;
	 cxTextEdit3->Enabled = false;
	 cxRadioButton6->Enabled = false;
	 cxRadioButton7->Enabled = false;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TSurfaceSampleAgeForm::cxRadioButton3Click(TObject *Sender)
{
   if (cxRadioButton2->Checked) {
	 cxRadioButton1->Checked = false;
	 cxRadioButton2->Checked = false;
	 cxDateEdit1->Enabled = false;
	 cxTextEdit1->Enabled = false;
	 cxRadioButton4->Enabled = false;
	 cxRadioButton5->Enabled = false;
	 cxTextEdit2->Enabled = true;
	 cxTextEdit3->Enabled = true;
	 cxRadioButton6->Enabled = true;
	 cxRadioButton7->Enabled = true;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TSurfaceSampleAgeForm::cxTextEdit1PropertiesValidate(TObject *Sender,
          Variant &DisplayValue, TCaption &ErrorText, bool &Error)
{
   GetYear(DisplayValue, ErrorText, Error, Year1);
}
//---------------------------------------------------------------------------

void __fastcall TSurfaceSampleAgeForm::cxTextEdit3PropertiesValidate(TObject *Sender,
		  Variant &DisplayValue, TCaption &ErrorText, bool &Error)
{
   GetYear(DisplayValue, ErrorText, Error, Year2);
}
//---------------------------------------------------------------------------

void TSurfaceSampleAgeForm::GetYear(Variant &DisplayValue,
	UnicodeString &ErrorText, bool &Error, int &Year)
{
   double dValue;
   UnicodeString sValue = VarToStr(DisplayValue);
   Error = false;
   if (!sValue.IsEmpty()) {
	 if (TryStrToFloat(sValue, dValue))
	   Year = dValue;
	 else {
	   Error = true;
	   ErrorText = L"Invalid year entered.";
	   }
	 }
}
//---------------------------------------------------------------------------

// Ok button
void __fastcall TSurfaceSampleAgeForm::cxButton1Click(TObject *Sender)
{
   UnicodeString msg;
   ModalResult = (cxCheckBox1->Checked) ? mrYesToAll : mrOk;
   if (cxRadioButton1->Checked) {
	 if (cxDateEdit1->Text.IsEmpty()) {
	   msg = L"Exact date is empty!";
	   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   ModalResult = mrNone;
	   }
	 else
	   FSampleAgeStyle = dsEXACTDATE;
	 }
   else if (cxRadioButton2->Checked) {
	 if (cxTextEdit1->Text.IsEmpty()) {
	   msg = L"Year is empty!";
	   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   ModalResult = mrNone;
	   }
	 else if (cxRadioButton4->Checked) {  // AD/BC
	   FYearBP = 1950 - Year1;
	   FSampleAgeStyle = dsYEAR;
	   }
	 }
   else if (cxRadioButton3->Checked) {
	 if (cxTextEdit2->Text.IsEmpty() || cxTextEdit3->Text.IsEmpty()) {
	   msg = L"Year is empty!";
	   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   ModalResult = mrNone;
	   }
	 else {
	   if (cxRadioButton6->Checked) {  // AD/BC
		 Year1 = 1950 - Year1;
		 Year2 = 1950 - Year2;
		 }
	   if (Year1 > Year2) {
		 FYearOlderBP = Year1;
		 FYearYoungerBP = Year2;
		 FSampleAgeStyle = dsYEARRANGE;
		 }
	   else if (Year1 < Year2) {
		 FYearOlderBP = Year2;
		 FYearYoungerBP = Year1;
		 FSampleAgeStyle = dsYEARRANGE;
		 }
	   else {
		 FYearBP = Year1;
		 FSampleAgeStyle = dsYEAR;
		 }
	   }
	 }
}
//---------------------------------------------------------------------------


