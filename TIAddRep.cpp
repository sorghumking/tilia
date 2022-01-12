//---------------------------------------------------------------------------

#include <vcl.h>
#include "pch.h"
#pragma hdrstop

#include "TIAddRep.h"
#ifndef TISpreadH
#include "TISpread.h"
#endif
#ifndef TINeotomaH
#include "TINeotoma.h"
#endif
#ifndef TNLoginH
#include "TNLogin.h"
#endif

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxBlobEdit"
#pragma link "cxButtons"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDropDownEdit"
#pragma link "cxEdit"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeels"
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
#pragma link "cxLabel"
#pragma link "ipsjsons"
#pragma resource "*.dfm"
TAddRepositoryForm *AddRepositoryForm;
TEditRepositoryForm *EditRepositoryForm;

//---------------------------------------------------------------------------
__fastcall TAddRepositoryForm::TAddRepositoryForm(TAdvColumnGrid* advcolgrid, TComponent* Owner)
		: TForm(Owner)
{
   AdvColumnGrid2 = advcolgrid;
   if (tiLicense->Type() != verNEOTOMASTEWARD) {
	 cxButton3->Visible = false;
	 FlowPanel1->Left += cxButton3->Width/2;
	 }
   CancelClicked = false;
}
//---------------------------------------------------------------------------

bool TAddRepositoryForm::AcronymExists(void)
{
   UnicodeString Acronym = cxTextEdit1->Text;
   for (int i=1; i<AdvColumnGrid2->RowCount; i++) {
	 if (SameText(Acronym, AdvColumnGrid2->Cells[1][i]))
	   return true;
	 }
   return false;
}
//---------------------------------------------------------------------------

bool TAddRepositoryForm::RepositoryExists(void)
{
   UnicodeString Repository = cxTextEdit2->Text;
   for (int i=1; i<AdvColumnGrid2->RowCount; i++) {
	 if (SameText(Repository, AdvColumnGrid2->Cells[2][i]))
	   return true;
	 }
   return false;
}
//---------------------------------------------------------------------------

// Ok button
void __fastcall TAddRepositoryForm::cxButton1Click(TObject *Sender)
{
   if (cxTextEdit1->Text.IsEmpty()) {
	 MessageDlg("No Acronym entered!", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 ModalResult = mrNone;
	 FocusControl(cxTextEdit1);
	 return;
	 }
   if (AcronymExists()) {
	 MessageDlg("Acronym already exists!", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 ModalResult = mrNone;
	 FocusControl(cxTextEdit1);
	 return;
	 }
   if (cxTextEdit2->Text.IsEmpty()) {
	 MessageDlg("No Repository entered!", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 ModalResult = mrNone;
	 FocusControl(cxTextEdit2);
	 return;
	 }
   if (RepositoryExists()) {
	 MessageDlg("Repository already exists!", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 ModalResult = mrNone;
	 FocusControl(cxTextEdit2);
	 return;
	 }
}
//---------------------------------------------------------------------------

// Upload button
void __fastcall TAddRepositoryForm::cxButton3Click(TObject *Sender)
{
   UnicodeString msg, ErrorMsg;
   UnicodeString Acronym = cxTextEdit1->Text.UpperCase();
   UnicodeString Repository = cxTextEdit2->Text;
   UnicodeString Notes = cxBlobEdit1->Text;
   bool error = false;

   try {
	   Screen->Cursor = crHourGlass;
	   if (Acronym.IsEmpty()) {
		 ErrorMsg = L"No Acronym entered!";
		 return;
		 }
	   if (Repository.IsEmpty()) {
		 ErrorMsg = L"No Repository entered!";
		 return;
		 }

	   // check if acronym already exists in Neotoma
	   if (AcronymInNeotoma(Acronym, error)) {
		 ErrorMsg = L"Acronym «" + Acronym + L"» already exists in Neotoma for repository «" +
					Repository + L"»!";
		 return;
		 }
	   else if (error)
		 return;

	   // check if repository already exists in Neotoma
	   if (RepositoryInNeotoma(Repository, error)) {
		 ErrorMsg = L"Repository «" + Repository + L"» already exists in Neotoma!";
		 return;
		 }
	   else if (error)
		 return;

	   msg = L"Upload repository «" + Acronym + L" | " + Repository + L"» to Neotoma?";
	   if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) != mrYes) {
		 error = true;
		 return;
		 }

	   // upload repository
	   if (!Login->IsLoggedIn) {
		 Screen->Cursor = crDefault;
		 NeotomaLoginForm = new TNeotomaLoginForm(this);
		 NeotomaLoginForm->ShowModal();
		 delete NeotomaLoginForm;
		 Screen->Cursor = crHourGlass;
		 }
	   if (!Login->IsLoggedIn) {
		 error = true;
		 return;
		 }

	   vector<int> newids;
	   InsertData InsertRepository(L"InsertRepositoryInstitution", 3, ipsHTTPS1, ipsJSONS1, TcpClient1);
	   StatusBar1->SimpleText = L"InsertRepositoryInstitution";
	   InsertRepository.Add(L"ACRONYM", Acronym);
	   InsertRepository.Add(L"REPOSITORY", Repository);
	   InsertRepository.Add(L"NOTES", Notes);
	   InsertRepository.PostData();
	   if (InsertRepository.Post(newids, ErrorMsg)) {
		 if (newids.size() == 1) {
		   msg = L"Success! Repository «" + Acronym + L" | " + Repository +
				 L"» uploaded to Neotoma RepositoryInstitutions table.";
		   MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
		   }
		 else {
		   error = true;
		   ErrorMsg = L"Error uploading «" + Acronym + L" | " + Repository +
					  L"» to Neotoma RepositoryInstitutions table.";
		   }
		 }
	   else
		 error = true;
	   }
   __finally {
	   if (!ErrorMsg.IsEmpty())
		 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   FocusControl(cxTextEdit1);
	   StatusBar1->SimpleText = L"";
	   Screen->Cursor = crDefault;
	   if (!error)
		 ModalResult = mrOk;
	   }
}
//---------------------------------------------------------------------------

bool TAddRepositoryForm::AcronymInNeotoma(UnicodeString Acronym, bool& error)
{
   error = false;
   NeotomaRepositoryInstitution Repository(ipsJSONS1, TcpClient1);
   Repository.AddParam(L"ACRONYM", Acronym);
   StatusBar1->SimpleText = Repository.WebServiceName();
   if (Repository.Execute()) {
	 if (Repository.Size() > 0)
	   return true;
	 }
   else
	 error = true;
   return false;
}
//---------------------------------------------------------------------------

bool TAddRepositoryForm::RepositoryInNeotoma(UnicodeString Repository, bool& error)
{
   error = false;
   NeotomaRepositoryInstitution Insitution(ipsJSONS1, TcpClient1);
   Insitution.AddParam(L"REPOSITORY", Repository);
   StatusBar1->SimpleText = Insitution.WebServiceName();
   if (Insitution.Execute()) {
	 if (Insitution.Size() > 0)
	   return true;
	 }
   else
	 error = true;
   return false;
}
//---------------------------------------------------------------------------

void __fastcall TAddRepositoryForm::cxTextEdit1PropertiesChange(TObject *Sender)
{
   if (tiLicense->Type() == verNEOTOMASTEWARD)
	 cxButton3->Enabled = (!cxTextEdit1->Text.IsEmpty() && !cxTextEdit2->Text.IsEmpty());
}
//---------------------------------------------------------------------------

void __fastcall TAddRepositoryForm::cxTextEdit2PropertiesChange(TObject *Sender)
{
   if (tiLicense->Type() == verNEOTOMASTEWARD)
	 cxButton3->Enabled = (!cxTextEdit1->Text.IsEmpty() && !cxTextEdit2->Text.IsEmpty());
}
//---------------------------------------------------------------------------

void __fastcall TAddRepositoryForm::cxButton2MouseEnter(TObject *Sender)
{
   CancelClicked = true;
}
//---------------------------------------------------------------------------

void __fastcall TAddRepositoryForm::cxButton2MouseLeave(TObject *Sender)
{
   CancelClicked = false;
}
//---------------------------------------------------------------------------

void __fastcall TAddRepositoryForm::cxTextEdit1PropertiesValidate(TObject *Sender,
		  Variant &DisplayValue, TCaption &ErrorText, bool &Error)
{
   if (!CancelClicked && AcronymExists()) {
	 ErrorText = L"Acronym already exists.";
	 Error = true;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TAddRepositoryForm::cxTextEdit2PropertiesValidate(TObject *Sender,
		  Variant &DisplayValue, TCaption &ErrorText, bool &Error)
{
   if (!CancelClicked && RepositoryExists()) {
	 ErrorText = L"Repository already exists.";
	 Error = true;
	 }
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

__fastcall TEditRepositoryForm::TEditRepositoryForm(TAdvColumnGrid* advcolgrid,
	UnicodeString notes, TComponent* Owner) : TAddRepositoryForm(advcolgrid, Owner)
{
   Caption = L"Edit Repository";
   cxButton3->Caption = L"Update";

   int ARow = AdvColumnGrid2->Row;
   cxTextEdit1->Text = AdvColumnGrid2->Cells[1][ARow];
   cxTextEdit2->Text = AdvColumnGrid2->Cells[2][ARow];
   cxBlobEdit1->Text = notes;
   OriginalAcronym = cxTextEdit1->Text;
   OriginalRepository = cxTextEdit2->Text;
   OriginalNotes = cxBlobEdit1->Text;
}
//---------------------------------------------------------------------------

// Update button
void __fastcall TEditRepositoryForm::cxButton3Click(TObject *Sender)
{
   if (cxTextEdit1->Text == OriginalAcronym &&
	   cxTextEdit2->Text == OriginalRepository &&
	   cxBlobEdit1->Text == OriginalNotes) {
	 MessageDlg(L"Repository not changed. No update necessary.", mtInformation, TMsgDlgButtons() << mbOK, 0);
	 return;
	 }


}
//---------------------------------------------------------------------------

void __fastcall TAddRepositoryForm::ipsJSONS1SSLServerAuthentication(TObject *Sender,
          TipsJSONSSSLServerAuthenticationEventParams *e)
{
   e->Accept = true;
}
//---------------------------------------------------------------------------

