//---------------------------------------------------------------------------
#include <Registry.hpp>
#include <vcl.h>
#include "pch.h"
#pragma hdrstop

#ifndef TGParentH
#include "TGParent.h"
#endif
#ifndef TGUtilsH
#include "TGUtils.h"
#endif
#ifndef TIVersionH
#include "TIVersion.h"
#endif
#include "TGReg.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxCheckBox"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxLabel"
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
TRegistrationForm *RegistrationForm;

//---------------------------------------------------------------------------
__fastcall TRegistrationForm::TRegistrationForm(UnicodeString owner, UnicodeString key, TComponent* Owner)
		: TForm(Owner)
{
   ParentForm = (TParentForm*)Owner;
   OldOwner = "";
   OldKey = "";
   Set(owner, key);
   if (!CheckBox1->Checked)
	 CheckBox1->Caption = L"Check to register a free version.";
}
//---------------------------------------------------------------------------

void TRegistrationForm::Set(UnicodeString owner, UnicodeString key)
{
   cxTextEdit3->Text = owner;
   cxTextEdit1->Text = key;
   OldOwner = owner;
   OldKey = key;

   if (key.IsEmpty()) {      // this is new
	 CheckBox1->Checked = true;
	 ToggleFreeVersion();
	 return;
	 }
   /*
   else if (key == "verFREE") {
	 CheckBox1->Checked = true;
	 ToggleFreeVersion();
	 cxLabel3->Caption =
	   "The free version of this product is already registered.\nYou may enter a new valid Owner Name and Product Key.";
	 return;
	 }
   else {
	 cxTextEdit1->Text = key;
	 cxLabel3->Caption =
	   "This product is already registered. You may enter a new valid Owner Name and Product Key.";
	 }
   */
   cxTextEdit1->Text = key;
   cxLabel3->Caption =
	 "This product is already registered. You may enter a new valid Owner Name and Product Key.";

   Encryption Encrypt(owner);
   //bool error = false;
   if (Encrypt.Decrypt(key)) {   // converts Product Key to GUID
	 UnicodeString DateStr;
	 switch (key[1]) {
	   case 'S':
		 cxTextEdit4->Text = L"Student";
		 DateStr = key.SubString(3,6);
		 break;
	   case 'L':
		 cxTextEdit4->Text = L"Professional";
		 break;
	   case 'P':
		 cxTextEdit4->Text = L"Professional";
		 break;
	   case 'M':
		 cxTextEdit4->Text = L"Multiple-use Teaching";
		 break;
	   case 'N':
		 cxTextEdit4->Text = L"Neotoma Steward";
		 break;
	   case 'F':
		 cxTextEdit4->Text = L"Free";
		 CheckBox1->Checked = true;
		 ToggleFreeVersion();
		 cxLabel3->Caption =
		   "The free version of this product is already registered.\nYou may enter a new valid Owner Name and Product Key.";
		 break;
	   case 'T':
		 cxTextEdit4->Text = L"Training";
		 DateStr = key.SubString(3,6);
		 break;
	   }

	 if (!DateStr.IsEmpty()) {
	   UnicodeString ExpirationDate;
	   TDateTime expiration_date = tiLicense->GetExpirationDate(DateStr, ExpirationDate);
	   cxTextEdit2->Text = ExpirationDate;
	   if (CompareDate(expiration_date, Today()) == LessThanValue) {
		 UnicodeString msg = "License has expired. You may enter a new valid Owner Name and Product Key,";
		 msg += L"\nor check Free Version to convert to a Free license.";
		 cxLabel3->Caption = msg;
		 }
	   }
	 else
	   cxTextEdit2->Text = L"Never";

	 cxTextEdit1->Enabled = !cxTextEdit3->Text.IsEmpty();
   }
}
//---------------------------------------------------------------------------

// Register button
void __fastcall TRegistrationForm::cxButton1Click(TObject *Sender)
{
   Owner = cxTextEdit3->Text.Trim();
   ProductKey = cxTextEdit1->Text.Trim();

   if (Owner.IsEmpty()) {
	 MessageDlg(L"Owner Name not entered!", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 return;
	 }
   if (ProductKey.IsEmpty() && !CheckBox1->Checked) {
	 MessageDlg(L"Either Free Version must checked or Product Key entered!",
	   Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 return;
	 }
   /*
   if (CheckBox1->Checked) {
	 tiLicense->RegisterFreeVersion(Owner);
	 tiLicense->SetLicenseType(verFREE);
	 // ProductKey = "verFREE";
	 ModalResult = mrOk;
	 return;
	 }
   */

   UnicodeString Key = ProductKey;
   Encryption Encrypt(Owner);
   bool error;
   short LicenseType;
   if (Encrypt.Decrypt(Key)) {   // converts Product Key to GUID
	 UnicodeString DateStr;
	 tiLicense->ParseProductKey(LicenseType, Key, DateStr);

	 if (!DateStr.IsEmpty()) {    // validate expiration date
	   UnicodeString ExpirationDate;
	   TDateTime expiration_date = tiLicense->GetExpirationDate(DateStr, ExpirationDate);
	   if (CompareDate(expiration_date, Today()) == LessThanValue) {
		 UnicodeString msg = L"This Product Key expired on " + ExpirationDate;
		 msg += L". License will be converted to Free.";
		 MessageDlg(msg, mtWarning, TMsgDlgButtons() << mbOK, 0);
		 CheckBox1->Checked = true;
		 ToggleFreeVersion();
		 return;
		 }
	   }
	 // tiLicense->SetLicenseType(LicenseType);    // TODO: move to below?
	 UnicodeString Prefix;
	 error = Register(Key);
	 if (error) {
	   for (unsigned int i=0; i<tiLicense->GUIDS.size()-1; i++) {
		 if (Key == tiLicense->GUIDS[i].GUID) {
		   Key = tiLicense->GUIDS.back().GUID;  // new GUID
		   switch (LicenseType) {
			 case verPROFESSIONAL:
			 case verLEGACY:
			   Key.Insert("P:",1);
			   break;
			 case verMULTIUSE:
			   Key.Insert("M:",1);
			   break;
			 case verNEOTOMASTEWARD:
			   Key.Insert("N:",1);
			   break;
			 case verFREE:
			   Key.Insert("F:",1);
			   break;
			 case verSTUDENT:
			   Prefix = "S:" + DateStr + ":";
			   Key.Insert(Prefix,1);
			   break;
			 case verTRAINING:
			   Prefix = "T:" + DateStr + ":";
			   Key.Insert(Prefix,1);
			   break;
			 }

		   Encrypt.Encrypt(Key);          // assign new Product Key
		   tiLicense->UpgradeRegistration(i, Owner, ProductKey);
		   error = false;
		   ModalResult = mrOk;
		   break;
		   }
		 }
	   if (error) {
		 MessageDlg("Invalid User Name or Product Key", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 error = true;
		 }
	   }
	 }
   else
	 error = true;

   if (error) {
	 if (!OldOwner.IsEmpty())
	   cxTextEdit3->Text = OldOwner;
	 if (!OldKey.IsEmpty())
	   cxTextEdit1->Text = OldKey;
	 }
   else
	 tiLicense->SetLicenseType(LicenseType);
}
//---------------------------------------------------------------------------

bool TRegistrationForm::Register(UnicodeString& Key)
{
   bool error = false;

   if (Key == tiLicense->GUIDS.back().GUID) {
	 UnicodeString Path = tiGlobals->AppDataTiliaPath;
	 if (!Path.IsEmpty()) {
	   UnicodeString Dir = Path.SubString(1,Path.Length()-1);
	   if (!DirectoryExists(Dir)) {
		 if (!CreateDir(Path))
		   return false;
		 }

	   Path += L"Tilia.INI";

	   TIniFile *SettingsFile = new TIniFile(Path);

	   try {
	       tiLicense->SetOwner(Owner);
		   tiLicense->SetProductKey(ProductKey);
		   SettingsFile->WriteString(L"Registration", L"Owner", Owner);
		   SettingsFile->WriteString(L"Registration", L"ProductKey", ProductKey);
		   SettingsFile->WriteString(L"Registration", L"Hash", tiLicense->GetHash());
		   MessageDlg("Tilia successfully registered!", mtInformation, TMsgDlgButtons() << mbOK, 0);
		   }
	   catch(Exception &e) {
		   MessageDlg(e.Message, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   error = true;
		   }

	   ModalResult = mrOk;
	   tiGlobals->MyLookupPath = tiGlobals->AppDataTiliaLookupPath;

	   delete SettingsFile;
	   }
	 else {
	   // MessageDlg(L"Error accessing %CSIDL_LOCAL_APPDATA%\\Tilia", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   MessageDlg(L"Error accessing %CSIDL_COMMON_APPDATA%\\Tilia", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   error = true;
	   }
	 }
   else
	 error = true;
   return error;
}
//---------------------------------------------------------------------------

// Help button
void __fastcall TRegistrationForm::cxButton3Click(TObject *Sender)
{
   MessageDlg("To obtain a Product Key go to www.TiliaIT.com.",
			   mtInformation, TMsgDlgButtons() << mbOK, 0);
}
//---------------------------------------------------------------------------

void __fastcall TRegistrationForm::CheckBox1Click(TObject *Sender)
{
   ToggleFreeVersion();
}
//---------------------------------------------------------------------------

void TRegistrationForm::ToggleFreeVersion(void)
{
   if (CheckBox1->Checked) {
	 cxTextEdit1->Enabled = false;
	 cxTextEdit1->Text = L"";
	 cxTextEdit4->Text = L"Free";
	 cxTextEdit2->Enabled = false;
	 cxTextEdit2->Text = L"";
	 CheckBox1->Caption = L"Free Version (uncheck to enter Product Key)";
	 if (!cxTextEdit3->Text.IsEmpty())
	   GenerateFreeProductKey();
	 }
   else {
	 cxTextEdit1->Text = L"";
	 cxTextEdit1->Enabled = true;
	 cxTextEdit4->Text = L"";
	 cxTextEdit2->Text = L"";
	 //cxTextEdit2->Enabled = true;
	 CheckBox1->Caption = L"Check to register a free version.";
	 }
}
//---------------------------------------------------------------------------

void TRegistrationForm::GenerateFreeProductKey(void)
{
   UnicodeString owner = cxTextEdit3->Text;
   Encryption Encrypt(owner);
   UnicodeString Key = tiLicense->GUIDS.back().GUID;
   Key.Insert("F:",1);
   Encrypt.Encrypt(Key);
   cxTextEdit1->Text = Key;
}
//---------------------------------------------------------------------------

void __fastcall TRegistrationForm::cxTextEdit1PropertiesChange(TObject *Sender)
{
   if (!cxTextEdit3->Text.IsEmpty() && cxTextEdit1->Text.Length() >= 72) {
	 short LicenseType;
	 UnicodeString DateStr;
	 UnicodeString Key = cxTextEdit1->Text;
	 UnicodeString owner = cxTextEdit3->Text;
	 Beep();
	 Encryption Encrypt(owner);
	 if (Encrypt.Decrypt(Key)) {
	   tiLicense->ParseProductKey(LicenseType, Key, DateStr);
	   switch (LicenseType) {
		 case verFREE:
		   cxTextEdit4->Text = L"Free";
		   break;
		 case verSTUDENT:
		   cxTextEdit4->Text = L"Student";
		   break;
		 case verPROFESSIONAL:
		   cxTextEdit4->Text = L"Professional";
		   break;
		 case verMULTIUSE:
		   cxTextEdit4->Text = L"Multiple-use Teaching";
		   break;
		 case verNEOTOMASTEWARD:
		   cxTextEdit4->Text = L"Neotoma Steward";
		   break;
		 case verTRAINING:
		   cxTextEdit4->Text = L"Training";
		   break;
		 case verLEGACY:
		   cxTextEdit4->Text = L"Legacy";
		   break;
		 }

	   if (!DateStr.IsEmpty()) {
		 UnicodeString ExpirationDate;
		 tiLicense->GetExpirationDate(DateStr, ExpirationDate);
		 cxTextEdit2->Text = ExpirationDate;
		 }
	   else
		 cxTextEdit2->Text = L"Never";
	   }
	 }
   else if (cxTextEdit1->Text.IsEmpty()) {
     cxTextEdit2->Text = L"";
	 cxTextEdit4->Text = L"";
	 }
}
//---------------------------------------------------------------------------

void __fastcall TRegistrationForm::cxTextEdit3PropertiesChange(TObject *Sender)
{
   cxTextEdit1->Enabled = (!cxTextEdit3->Text.IsEmpty() && !CheckBox1->Checked);
   if (cxTextEdit3->Text.IsEmpty()) {
	 cxTextEdit1->Text = L"";
	 cxTextEdit2->Text = L"";
	 cxTextEdit4->Text = L"";
	 }
}
//---------------------------------------------------------------------------

