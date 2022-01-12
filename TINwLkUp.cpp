//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TINwLkUp.h"
#ifndef TIVersionH
#include "TIVersion.h"
#endif
#ifndef TNLoginH
#include "TNLogin.h"
#endif
#ifndef TINeotomaH
#include "TINeotoma.h"
#endif
#ifndef TIJSONH
#include "TIJSON.h"
#endif

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxTextEdit"
#pragma link "ipshttps"
#pragma link "ipwjson"
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
#pragma link "ipsjsons"
#pragma resource "*.dfm"
TNewLookupItemForm *NewLookupItemForm;
TNewFractionForm *NewFractionForm;
//---------------------------------------------------------------------------
__fastcall TNewLookupItemForm::TNewLookupItemForm(TComponent* Owner)
	: TForm(Owner)
{
   TSSForm = (TTilSpreadSheetForm*)Owner;
   if (tiLicense->Type() != verNEOTOMASTEWARD) {
	 cxButton1->Visible = false;
	 FlowPanel1->Left = (StatusBar1->Width - cxButton2->Width - cxButton3->Width)/2;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TNewLookupItemForm::cxButton1Click(TObject *Sender)
{
   return;
}
//---------------------------------------------------------------------------

void __fastcall TNewLookupItemForm::cxButton2Click(TObject *Sender)
{
   return;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

__fastcall TNewFractionForm::TNewFractionForm(TComponent* Owner)
	: TNewLookupItemForm(Owner)
{
   Caption = L"New Fraction";
   TSSForm = (TTilSpreadSheetForm*)Owner;
}
//---------------------------------------------------------------------------

void __fastcall TNewFractionForm::cxButton1Click(TObject *Sender)
{
   UnicodeString msg, ErrorMsg;

   UnicodeString NewFraction = cxTextEdit1->Text.Trim();
   if (NewFraction.IsEmpty()) {
	 Beep();
	 return;
	 }

   //if (FractionExists(NewFraction))
   //	 return;

   Screen->Cursor = crHourGlass;
   NeotomaFractionsDatedByList NeotomaFractions(ipsJSONS1, TcpClient1);
   NeotomaFractions.AddParam(L"FRACTIONS", NewFraction);
   StatusBar1->Caption = NeotomaFractions.WebServiceName();
   if (NeotomaFractions.Execute()) {
	 if (NeotomaFractions.Size() > 0) {
	   UnicodeString msg = L"Fraction «" + NewFraction + L"» already exists in Neotoma!";
	   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   StatusBar1->Caption = L"";
	   Screen->Cursor = crDefault;
	   return;
	   }
	 }
   else {
	 StatusBar1->Caption = L"";
	 Screen->Cursor = crDefault;
	 return;
	 }
   StatusBar1->Caption = L"";
   Screen->Cursor = crDefault;

   msg = L"Upload new Fraction type «" + NewFraction + L"» to Neotoma?";
   if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) != mrYes)
	 return;

   // add new fraction to ComboBox
   TcxComboBoxProperties* Fractions = (TcxComboBoxProperties*)(TSSForm->txFraction->Properties);
   Fractions->Items->Add(NewFraction);

   // upload to Neotoma
   if (tiLicense->Type() == verNEOTOMASTEWARD) {
	 if (!Login->IsLoggedIn) {
	   NeotomaLoginForm = new TNeotomaLoginForm(this);
	   NeotomaLoginForm->ShowModal();
	   delete NeotomaLoginForm;
	   }
	 if (Login->IsLoggedIn) {
	   vector<int> newids;
	   Screen->Cursor = crHourGlass;
	   InsertData InsertFraction(L"InsertFractionDated", 1, ipsHTTPS1, ipsJSONS1, TcpClient1);
	   InsertFraction.Add(L"FRACTION", NewFraction);
	   StatusBar1->Caption = L"InsertFractionDated";
	   InsertFraction.PostData();
	   if (InsertFraction.Post(newids, ErrorMsg)) {
		 if (newids.size() == 1) {
		   if (!FractionExists(NewFraction))
			 TSSForm->SaveLookupFile();
		   msg = L"Success! New fraction «" + NewFraction + L"» uploaded to Neotoma.";
		   MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
		   }
		 else {
		   ErrorMsg = L"Error inserting into FractionDated table!";
		   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   }
		 }
	   else {
		 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 }
	   StatusBar1->Caption = L"";
	   cxButton3->Caption = L"Close";
	   cxButton3->ImageIndex = 3;
	   Screen->Cursor = crDefault;
	   }
	 }

}
//---------------------------------------------------------------------------

bool TNewFractionForm::FractionExists(UnicodeString NewFraction)
{
   bool exists = false;
   TcxComboBoxProperties* Fractions = (TcxComboBoxProperties*)(TSSForm->txFraction->Properties);
   for (int i=0; i<Fractions->Items->Count; i++) {
	 if (SameText(Fractions->Items->Strings[i], NewFraction)) {
	   UnicodeString msg = L"Fraction «" + NewFraction + L"» already exists in lookup list!";
	   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   exists = true;
	   break;
	   }
	 }
   return exists;
}
//---------------------------------------------------------------------------

void __fastcall TNewFractionForm::cxButton2Click(TObject *Sender)
{
   UnicodeString NewFraction = cxTextEdit1->Text.Trim();
   if (NewFraction.IsEmpty()) {
	 Beep();
	 return;
	 }
   if (FractionExists(NewFraction))
	 return;
   UnicodeString msg = L"Save new Fraction type «" + NewFraction + L"» to lookup file?";
   if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes) {
	 TSSForm->SaveLookupFile();
     cxButton3->Caption = L"Close";
	 cxButton3->ImageIndex = 3;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TNewLookupItemForm::ipsJSONS1SSLServerAuthentication(TObject *Sender,
          TipsJSONSSSLServerAuthenticationEventParams *e)
{
   e->Accept = true;
}
//---------------------------------------------------------------------------

