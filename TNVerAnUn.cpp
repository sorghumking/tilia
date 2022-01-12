//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TNVerAnUn.h"
#include <VarHlpr.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvEdit"
#pragma link "AdvLabel"
#pragma link "cxButtons"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
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
#pragma resource "*.dfm"
TVerifyAnalUnitForm *VerifyAnalUnitForm;
//---------------------------------------------------------------------------
__fastcall TVerifyAnalUnitForm::TVerifyAnalUnitForm(Variant depth,
	UnicodeString name, Variant thick, TComponent* Owner)
	: TForm(Owner)
{
   UnicodeString Text;
   FAnalUnitDepth = depth;
   FAnalUnitName = name;
   FAnalUnitThick = thick;

   if (!FAnalUnitDepth.IsEmpty())  {
	 VariantToUnicodeString(FAnalUnitDepth, Text);
	 AdvEdit1->Text = Text;
	 }
   if (!FAnalUnitName.IsEmpty())
	 AdvEdit2->Text = FAnalUnitName;
   if (!FAnalUnitThick.IsEmpty()) {
	 VariantToUnicodeString(FAnalUnitThick, Text);
	 AdvEdit3->Text = Text;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TVerifyAnalUnitForm::cxButton1Click(TObject *Sender)
{
   double Value;
   UnicodeString msg;

   if (AdvEdit1->Text.IsEmpty())
	 FAnalUnitDepth = Unassigned();
   else {
	 if (TryStrToFloat(AdvEdit1->Text,Value))
	   FAnalUnitDepth = Value;
	 else {
	   msg = L"Invalid value for depth.";
	   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return;
	   }
	 }

   if (AdvEdit3->Text.IsEmpty())
	 FAnalUnitThick = Unassigned();
   else {
	 if (TryStrToFloat(AdvEdit3->Text,Value))
	   FAnalUnitThick = Value;
	 else {
	   msg = L"Invalid value for thickness.";
	   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return;
	   }
	 }

   if (AdvEdit1->Text.IsEmpty() && AdvEdit2->Text.IsEmpty()) {
	 msg = L"Both depth and name cannot be blank.";
     MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 return;
	 }
   FAnalUnitName = AdvEdit2->Text;

   ModalResult = mrOk;
}
//---------------------------------------------------------------------------

