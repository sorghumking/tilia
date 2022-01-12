//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TIsoSer.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDropDownEdit"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxLabel"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxMaskEdit"
#pragma link "cxSpinEdit"
#pragma link "cxTextEdit"
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
#pragma link "cxButtons"
#pragma resource "*.dfm"
TIsotopeSeriesForm *IsotopeSeriesForm;
//---------------------------------------------------------------------------
__fastcall TIsotopeSeriesForm::TIsotopeSeriesForm(TPoint& pos, TComponent* Owner)
	: TForm(Owner)
{
   TSSForm = (TTilSpreadSheetForm*)Owner;
   Position = pos;
   FillComboBoxes();
}
//---------------------------------------------------------------------------

__fastcall TIsotopeSeriesForm::TIsotopeSeriesForm(TPoint& pos, ISOTOPESERIES* series, TComponent* Owner)
	: TForm(Owner)
{
   TSSForm = (TTilSpreadSheetForm*)Owner;
   Position = pos;
   FSeries = *series;
   FillComboBoxes();
   cxSpinEdit1->Value = FSeries.NumberOfSamples;
   cxComboBox1->Text = FSeries.SamplingOrigin;
   cxComboBox3->Text = FSeries.SampleDistUnits;
   if (!FSeries.SampleInterval.IsEmpty())
	 cxTextEdit1->Text = FSeries.SampleInterval;
   if (!FSeries.TransectWidth.IsEmpty())
	 cxTextEdit1->Text = FSeries.TransectWidth;
   if (!FSeries.DrillBitSize.IsEmpty())
	 cxTextEdit1->Text = FSeries.DrillBitSize;
   if (!FSeries.SampledBiolMarker.IsEmpty())
	 cxComboBox2->Text = FSeries.SampledBiolMarker;
}
//---------------------------------------------------------------------------

void TIsotopeSeriesForm::FillComboBoxes(void)
{
   set<UnicodeString>::iterator itr;
   set<UnicodeString>::iterator begin = TSSForm->IsoSamplingOrigins.begin();
   set<UnicodeString>::iterator end = TSSForm->IsoSamplingOrigins.end();
   for (itr = begin; itr != end; itr++)
	 cxComboBox1->Properties->Items->Add(*itr);

   multimap<UnicodeString,UnicodeString>::iterator mitr;
   multimap<UnicodeString,UnicodeString>::iterator mbegin = TSSForm->IsoBioMarkers.begin();
   multimap<UnicodeString,UnicodeString>::iterator mend = TSSForm->IsoBioMarkers.end();
   for (mitr = mbegin; mitr != mend; mitr++) {
	 if (cxComboBox2->Properties->Items->IndexOf(mitr->first) == -1)
	   cxComboBox2->Properties->Items->Add(mitr->first);
	 }
}
//---------------------------------------------------------------------------

void __fastcall TIsotopeSeriesForm::FormActivate(TObject *Sender)
{
   Left = Position.X;
   Top = Position.Y;
}
//---------------------------------------------------------------------------

// Ok button
void __fastcall TIsotopeSeriesForm::cxButton1Click(TObject *Sender)
{
   UnicodeString ErrorMsg;

   int n = cxSpinEdit1->Value;
   if (n < 2)
	 ErrorMsg = L"Number in series must be at least 2.";
   else {
	 FSeries.NumberOfSamples = n;
	 if (cxComboBox1->ItemIndex == -1)
	   ErrorMsg = L"Sampling origin must be selected.";
	 else {
	   FSeries.SamplingOrigin = cxComboBox1->Text;
	   FSeries.SampleDistUnits = cxComboBox3->Text;
	   //UnicodeString Text = cxTextEdit1->Text;
	   AssignFloatParam((UnicodeString&)cxTextEdit1->Text, FSeries.SampleInterval);
	   //Text = cxTextEdit2->Text;
	   AssignFloatParam((UnicodeString&)cxTextEdit2->Text, FSeries.TransectWidth);
	   //Text = cxTextEdit1->Text;
	   AssignFloatParam((UnicodeString&)cxTextEdit3->Text, FSeries.DrillBitSize);
	   FSeries.SampledBiolMarker = cxComboBox2->Text;
	   }
	 }

   if (ErrorMsg.IsEmpty())
	 ModalResult = mrOk;
   else
	 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
}
//---------------------------------------------------------------------------

void TIsotopeSeriesForm::AssignFloatParam(UnicodeString& Text, Variant& Param)
{
   double dVal;

   if (Text.IsEmpty())
	 Param = Unassigned();
   else if (TryStrToFloat(Text, dVal))
	 Param = dVal;
   else
	 Param = Unassigned();
}
//---------------------------------------------------------------------------

void __fastcall TIsotopeSeriesForm::cxTextEdit1PropertiesValidate(TObject *Sender,
          Variant &DisplayValue, TCaption &ErrorText, bool &Error)
{
   Error = ValidateNumerical(DisplayValue, ErrorText);
}
//---------------------------------------------------------------------------

void __fastcall TIsotopeSeriesForm::cxTextEdit2PropertiesValidate(TObject *Sender,
          Variant &DisplayValue, TCaption &ErrorText, bool &Error)
{
   Error = ValidateNumerical(DisplayValue, ErrorText);
}
//---------------------------------------------------------------------------

void __fastcall TIsotopeSeriesForm::cxTextEdit3PropertiesValidate(TObject *Sender,
          Variant &DisplayValue, TCaption &ErrorText, bool &Error)
{
   Error = ValidateNumerical(DisplayValue, ErrorText);
}
//---------------------------------------------------------------------------

bool TIsotopeSeriesForm::ValidateNumerical(Variant &DisplayValue, TCaption &ErrorText)
{
   double dVal;
   UnicodeString text;
   bool Error = false;

   text = DisplayValue;
   if (!text.IsEmpty()) {
	 if (!TryStrToFloat(text, dVal)) {
	   ErrorText = L"Value must be numerical.";
	   Error = true;
	   }
	 }

   return Error;
}
//---------------------------------------------------------------------------

