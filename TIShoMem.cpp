//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TIShoMem.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxMemo"
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
#pragma link "cxRichEdit"
#pragma resource "*.dfm"
TShowMemoForm *ShowMemoForm;
//---------------------------------------------------------------------------
__fastcall TShowMemoForm::TShowMemoForm(UnicodeString caption, UnicodeString text,
	TComponent* Owner) : TForm(Owner)
{
   Caption = caption;
   if (!text.IsEmpty())
	 cxRichEdit1->Lines->Add(text);
}
//---------------------------------------------------------------------------

void __fastcall TShowMemoForm::cxButton2Click(TObject *Sender)
{
   cxRichEdit1->CopyToClipboard();
}
//---------------------------------------------------------------------------

void __fastcall TShowMemoForm::cxButton3Click(TObject *Sender)
{
   cxRichEdit1->SelectAll();
   cxRichEdit1->CopyToClipboard();
}
//---------------------------------------------------------------------------

void __fastcall TShowMemoForm::Panel1Resize(TObject *Sender)
{
   FlowPanel1->Left = (Panel1->Width-FlowPanel1->Width)/2;
}
//---------------------------------------------------------------------------

void TShowMemoForm::AddLine(UnicodeString Text, TFontStyles Style, TColor Color)
{
   if (cxRichEdit1->SelStart == 0)
	 cxRichEdit1->SelStart = 1;
   cxRichEdit1->SelAttributes->Style = Style;
   cxRichEdit1->SelAttributes->Color = Color;
   cxRichEdit1->Lines->Add(Text);
}
//---------------------------------------------------------------------------

