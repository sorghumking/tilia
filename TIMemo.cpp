//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TIMemo.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeels"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
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
#pragma resource "*.dfm"
TMemoForm *MemoForm;
TTaxonNotesForm *TaxonNotesForm;
TEPDNotesPrepForm *EPDNotesPrepForm;
//---------------------------------------------------------------------------
__fastcall TMemoForm::TMemoForm(UnicodeString caption, UnicodeString Text,
	MemoFormOptions options, TComponent* Owner) : TForm(Owner)
{
   Caption = caption;
   Options.Clear();
   Options = options;
   int nbuttons = 1;

   cxButton3->Visible = Options.Contains(mfoCancelButton);
   if (cxButton3->Visible)
	 nbuttons++;
   cxButton2->Visible = Options.Contains(mfoBlankButton);
   if (cxButton2->Visible)
	 nbuttons++;

   FlowPanel1->Left = (Panel1->Width - nbuttons*cxButton1->Width)/2;

   if (Options.Contains(mfoTextEdit)) {
	 Memo1->Visible = false;
	 cxTextEdit1->Visible = true;
	 cxTextEdit1->Text = Text;
	 Height = 132;

	 }
   else {
	 Memo1->ReadOnly = Options.Contains(mfoReadOnly);
	 if (!Text.IsEmpty()) {
	   int pos = Text.Pos(L"\n");
	   while (pos > 0) {
		 Memo1->Lines->Add(Text.SubString(1,pos-1));
		 Text.Delete(1,pos);
         pos = Text.Pos(L"\n");
		 }
	   Memo1->Lines->Add(Text);
	   }
	 }
}
//---------------------------------------------------------------------------

void __fastcall TMemoForm::FormActivate(TObject *Sender)
{
   if (cxTextEdit1->Visible)
     FocusControl(cxTextEdit1);
   return;
}
//---------------------------------------------------------------------------

UnicodeString TMemoForm::gettext(void)
{
   if (Options.Contains(mfoTextEdit))
	 return cxTextEdit1->Text;
   else
     return Memo1->Text;
}
//---------------------------------------------------------------------------

void __fastcall TMemoForm::cxButton1Click(TObject *Sender)
{
   return;
}
//---------------------------------------------------------------------------

void __fastcall TMemoForm::cxButton2Click(TObject *Sender)
{
   return;
}
//---------------------------------------------------------------------------

void __fastcall TMemoForm::FormResize(TObject *Sender)
{
   FlowPanel1->Left = (Panel1->Width - FlowPanel1->Width)/2;
}
//---------------------------------------------------------------------------

void __fastcall TMemoForm::cxTextEdit1KeyPress(TObject *Sender, wchar_t &Key)
{
   if (Key == VK_RETURN && Options.Contains(mfoOkOnEnter)) {
	 ModalResult = mrClose;
	 Close();
	 }
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

__fastcall TTaxonNotesForm::TTaxonNotesForm(UnicodeString caption, UnicodeString Text,
	MemoFormOptions options, TPoint& Pos, TComponent* Owner)
	: TMemoForm(caption, Text, options, Owner)
{
   Position = Pos;
   cxButton2->Caption = L"Update";
   cxButton2->OptionsImage->ImageIndex = 2;
   cxButton2->ModalResult = mrYes;
}
//---------------------------------------------------------------------------

void __fastcall TTaxonNotesForm::FormActivate(TObject *Sender)
{
   Left = Position.X;
   Top = Position.Y;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

__fastcall TEPDNotesPrepForm::TEPDNotesPrepForm(UnicodeString caption, UnicodeString Text,
	MemoFormOptions options, TComponent* Owner)
	: TMemoForm(caption, Text, options, Owner)
{
   FCommentType = 0;
   Memo1->WordWrap = false;
   cxButton1->Caption = L"Notes";
   cxButton1->OptionsImage->ImageIndex = 3;
   cxButton1->ModalResult = mrOk;
   cxButton2->Caption = L"Prep";
   cxButton2->OptionsImage->ImageIndex = 4;
   cxButton2->ModalResult = mrOk;
}
//---------------------------------------------------------------------------

void __fastcall TEPDNotesPrepForm::cxButton1Click(TObject *Sender)
{
   FCommentType = 1;  // Notes
}
//---------------------------------------------------------------------------

void __fastcall TEPDNotesPrepForm::cxButton2Click(TObject *Sender)
{
   FCommentType = 2;  // Preparation method
}
//---------------------------------------------------------------------------

