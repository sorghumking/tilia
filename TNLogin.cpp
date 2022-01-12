//---------------------------------------------------------------------------

#include <vcl.h>
#include "pch.h"
#pragma hdrstop

#include "TNLogin.h"
#ifndef TINeotomaH
#include "TINeotoma.h"
#endif
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxCheckBox"
#pragma link "cxCheckListBox"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxGroupBox"
#pragma link "cxLabel"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxTextEdit"
#pragma link "ipsjsons"
#pragma link "ipwjson"
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
#pragma resource "*.dfm"
TNeotomaLoginForm *NeotomaLoginForm;
//---------------------------------------------------------------------------
__fastcall TNeotomaLoginForm::TNeotomaLoginForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaLoginForm::FormCreate(TObject *Sender)
{
   RatStart = 16;
   RatEnd = 465;
   RatPos = 16;
   Login->Setup(cxTextEdit1, cxTextEdit2, cxCheckBox1);
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaLoginForm::FormActivate(TObject *Sender)
{
   // login bypass
   // if (cxTextEdit1->Text == L"ecgrimm")
   //	 cxTextEdit2->Text = L"Opuntia!";

   if (cxTextEdit1->Text.IsEmpty())
	 FocusControl(cxTextEdit1);
   else if (cxTextEdit2->Text.IsEmpty())
	 FocusControl(cxTextEdit2);
   else {
     cxButton1->Enabled = true;
	 FocusControl(cxButton1);
	 }
}
//---------------------------------------------------------------------------

// login button
void __fastcall TNeotomaLoginForm::cxButton1Click(TObject *Sender)
{
   Timer1->Enabled = true;

   if (Login->Execute(cxTextEdit1->Text, cxTextEdit2->Text, cxCheckBox1->Checked,
	   cxCheckListBox1, ipsJSONS1, TcpClient1, StatusBar1))
	 {
	 cxCheckListBox1->Visible = true;
	 cxLabel1->Visible = false;
	 cxCheckBox1->Visible = false;
	 cxButton3->Visible = true;   // Continue button
	 Image1->Left = RatEnd;
	 Label1->Visible = true;
     cxCheckBox2->Visible = Login->IsTaxonomyExpert;
	 }
   Screen->Cursor = crDefault;
   Timer1->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaLoginForm::Timer1Timer(TObject *Sender)
{
   RatPos += 48;
   if (RatPos > RatEnd)
	 RatPos = RatStart;
   Image1->Left = RatPos;
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaLoginForm::cxTextEdit1PropertiesEditValueChanged(TObject *Sender)
{
   cxButton1->Enabled = (!cxTextEdit1->Text.IsEmpty() && !cxTextEdit2->Text.IsEmpty());
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaLoginForm::cxTextEdit2KeyUp(TObject *Sender, WORD &Key, TShiftState Shift)
{
   cxButton1->Enabled = (!cxTextEdit1->Text.IsEmpty() && !cxTextEdit2->Text.IsEmpty());
}
//---------------------------------------------------------------------------

// Cancel button
void __fastcall TNeotomaLoginForm::cxButton2Click(TObject *Sender)
{
   Login->Logout();
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaLoginForm::cxCheckListBox1ClickCheck(TObject *Sender, int AIndex,
          TcxCheckBoxState APrevState, TcxCheckBoxState ANewState)
{
   if (ANewState == cbsChecked) {
	 for (int i=0; i<cxCheckListBox1->Items->Count; i++) {
	   if (i != AIndex)
		 cxCheckListBox1->Items->Items[i]->Checked = false;
	   }
	 }
}
//---------------------------------------------------------------------------

// Continue button
void __fastcall TNeotomaLoginForm::cxButton3Click(TObject *Sender)
{
   if (ConfirmDatabaseID())
	 ModalResult = mrOk;
   else
     MessageDlg(L"No constituent database selected!", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
}
//---------------------------------------------------------------------------

bool TNeotomaLoginForm::ConfirmDatabaseID(void)
{
   Login->DatabaseID = -1;
   for (int i=0; i<cxCheckListBox1->Items->Count; i++) {
	 if (cxCheckListBox1->Items->Items[i]->Checked) {
	   UnicodeString DatabaseName = cxCheckListBox1->Items->Items[i]->Text;
	   Login->SetDatabaseID(DatabaseName);
	   break;
	   }
	 }
   return (Login->DatabaseID != -1);
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaLoginForm::ipsJSONS1SSLServerAuthentication(TObject *Sender,
          TipsJSONSSSLServerAuthenticationEventParams *e)
{
   e->Accept = true;
}
//---------------------------------------------------------------------------

