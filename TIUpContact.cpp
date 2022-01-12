//---------------------------------------------------------------------------

#include <vcl.h>
#include "pch.h"
#pragma hdrstop

#include "TIUpContact.h"
#ifndef TIUtilsH
#include "TIUtils.h"
#endif
#ifndef TIJSONH
#include "TIJSON.h"
#endif
#ifndef TINeotomaH
#include "TINeotoma.h"
#endif
#ifndef TNLoginH
#include "TNLogin.h"
#endif
#ifndef TIPublH
#include "TIPubl.h"
#endif
#ifndef TNtmPubsH
#include "TNtmPubs.h"
#endif
#ifndef TNConDstH
#include "TNConDst.h"
#endif
#ifndef TIVersionH
#include "TIVersion.h"
#endif

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxListBox"
#pragma link "cxTextEdit"
#pragma link "cxDropDownEdit"
#pragma link "cxMaskEdit"
#pragma link "cxMemo"
#pragma link "ipwjson"
#pragma link "cxGroupBox"
#pragma link "cxLabel"
#pragma link "cxCheckBox"
#pragma link "cxRichEdit"
#pragma link "cxSpinEdit"
#pragma link "ipshttps"
#pragma link "cxProgressBar"
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
#pragma link "ipsjsons"
#pragma resource "*.dfm"
TNeotomaContactForm *NeotomaContactForm;
//---------------------------------------------------------------------------
__fastcall TNeotomaContactForm::TNeotomaContactForm(TComponent* Owner)
	: TForm(Owner)
{
   Activated = false;
   CurrentContact = NULL;
   ManualSpin = true;
   ManualEdit = false;
}
//---------------------------------------------------------------------------

void TNeotomaContactForm::GetContactStatuses(void)
{
   map<int, UnicodeString> ContactStatus;
   //NeotomaContactStatusesTable Statuses(ipwJSON1, TcpClient1);
   //ShowMessage(L"Getting Statuses");
   NeotomaContactStatusesTable Statuses(ipsJSONS1, TcpClient1);
   StatusBar1->SimpleText = Statuses.WebServiceName();
   Screen->Cursor = crHourGlass;
   if (Statuses.Execute()) {
	 if (Statuses.Size() > 0) {
	   for (unsigned int i=0; i<Statuses.Size(); i++) {
		 int ID = Statuses.Items[i].ContactStatusID;
		 UnicodeString Status = Statuses.Items[i].ContactStatus;
		 ContactStatuses[ID] = Status;
		 }
	   }
	 }

   cxComboBoxStatus1->Properties->Items->Clear();
   cxComboBoxStatus2->Properties->Items->Clear();
   map<int, UnicodeString>::iterator itr;
   for (itr = ContactStatuses.begin(); itr != ContactStatuses.end(); itr++) {
	 cxComboBoxStatus1->Properties->Items->Add(itr->second);
	 cxComboBoxStatus2->Properties->Items->Add(itr->second);
	 }

   StatusBar1->SimpleText = L"";
   Screen->Cursor = crDefault;
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaContactForm::FormDestroy(TObject *Sender)
{
   ClearContactsList();
}
//---------------------------------------------------------------------------

void TNeotomaContactForm::ClearContactsList(void)
{
   for (int i=0; i<cxListBox1->Items->Count; i++) {
	 CONTACT* Contact = (CONTACT*)cxListBox1->Items->Objects[i];
	 delete Contact;
	 }
   cxListBox1->Clear();
   cxButton1->Enabled = false;
}
//---------------------------------------------------------------------------

void TNeotomaContactForm::FillNeotomaContactCard(CONTACT* Contact)
{
  int TitleIndex, StatusIndex;

  cxTextEditID2->Text = IntToStr(Contact->NeotomaContactID);
  cxTextEditFamilyName2->Text = Contact->FamilyName;
  cxTextEditGivenNames2->Text = Contact->GivenNames;
  cxTextEditInitials2->Text = Contact->LeadingInitials;
  cxTextEditSuffix2->Text = Contact->Suffix;
  //cxComboBoxTitle2->Text = Contact->Title;

  if (Contact->Title.IsEmpty())
	cxComboBoxTitle2->ItemIndex = -1;
  else {
	TitleIndex = cxComboBoxTitle2->Properties->Items->IndexOf(Contact->Title);
	cxComboBoxTitle2->ItemIndex = TitleIndex;
	}

  if (Contact->Status.IsEmpty())
	StatusIndex = cxComboBoxStatus2->Properties->Items->IndexOf(L"unknown");
  else
	StatusIndex = cxComboBoxStatus2->Properties->Items->IndexOf(Contact->Status);
  cxComboBoxStatus2->ItemIndex = StatusIndex;

  cxTextEditPhone2->Text = Contact->Telephone;
  cxTextEditFax2->Text = Contact->Fax;
  cxTextEditEmail2->Text = Contact->Email;
  cxTextEditURL2->Text = Contact->URL;

  int idx;
  UnicodeString Address = Contact->Address;
  while ((idx = Address.Pos(L"\\r\\n")) > 0) {
	Address.Delete(idx,4);
	Address.Insert(L"\r\n",idx);
	}
  cxMemoAddress2->Text = Address;

  UnicodeString Notes = Contact->Notes;
  while ((idx = Notes.Pos(L"\\r\\n")) > 0) {
	Notes.Delete(idx,4);
	Notes.Insert(L"\r\n",idx);
	}

  cxMemoNotes2->Text = Notes;
}
//---------------------------------------------------------------------------

void TNeotomaContactForm::FillContactCard(CONTACT* Contact)
{
  int TitleIndex, StatusIndex;

  if (Contact->NeotomaContactID > -1)
	cxTextEditID1->Text = IntToStr(Contact->NeotomaContactID);
  else
    cxTextEditID1->Clear();
  cxTextEditFamilyName1->Text = Contact->FamilyName;
  cxTextEditGivenNames1->Text = Contact->GivenNames;
  cxTextEditInitials1->Text = Contact->LeadingInitials;
  cxTextEditSuffix1->Text = Contact->Suffix;
  //cxComboBoxTitle1->Text = Contact->Title;

  if (Contact->Title.IsEmpty())
	cxComboBoxTitle1->ItemIndex = -1;
  else {
	TitleIndex = cxComboBoxTitle1->Properties->Items->IndexOf(Contact->Title);
	cxComboBoxTitle1->ItemIndex = TitleIndex;
	}

  if (Contact->Status.IsEmpty())
	cxComboBoxStatus1->ItemIndex = -1;
  else {
	StatusIndex = cxComboBoxStatus1->Properties->Items->IndexOf(Contact->Status);
	cxComboBoxStatus1->ItemIndex = StatusIndex;
	}

  cxTextEditPhone1->Text = Contact->Telephone;
  cxTextEditFax1->Text = Contact->Fax;
  cxTextEditEmail1->Text = Contact->Email;
  cxTextEditURL1->Text = Contact->URL;

  int idx;
  UnicodeString Address = Contact->Address;
  while ((idx = Address.Pos(L"\\r\\n")) > 0) {
	Address.Delete(idx,4);
	Address.Insert("\r\n",idx);
	}
  cxMemoAddress1->Text = Address;

  UnicodeString Notes = Contact->Notes;
  while ((idx = Notes.Pos(L"\\r\\n")) > 0) {
	Notes.Delete(idx,4);
	Notes.Insert("\r\n",idx);
	}

  cxMemoNotes1->Text = Notes;
}
//---------------------------------------------------------------------------

void TNeotomaContactForm::ClearNeotomaContactCard(void)
{
   cxTextEditID2->Clear();
   cxTextEditFamilyName2->Clear();
   cxTextEditInitials2->Clear();
   cxTextEditSuffix2->Clear();
   cxTextEditGivenNames2->Clear();
   cxComboBoxTitle2->Clear();
   cxComboBoxStatus2->Clear();
   cxTextEditPhone2->Clear();
   cxTextEditFax2->Clear();
   cxTextEditEmail2->Clear();
   cxTextEditURL2->Clear();
   cxMemoAddress2->Clear();
   cxMemoNotes2->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaContactForm::cxButtonRightArrowClick(TObject *Sender)
{
   return;
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaContactForm::cxButtonUpdateClick(TObject *Sender)
{
   return;
}
//---------------------------------------------------------------------------

void TNeotomaContactForm::SearchContact(UnicodeString LastName, UnicodeString Initials, int& size)
{
   cxTextEdit1->Text = LastName;
   cxTextEdit2->Text = Initials;
   NeotomaContactByFamilyNameAndInitials GetContact(ipsJSONS1, TcpClient1);
   GetContact.AddParam(L"FAMILYNAME", LastName);
   GetContact.AddParam(L"INITIALS", Initials);
   StatusBar1->SimpleText = GetContact.WebServiceName();
   Screen->Cursor = crHourGlass;
   CONTACT *Contact;
   if (GetContact.Execute()) {
	 size = GetContact.Size();
	 ClearContactsList();
	 if (size > 0) {
	   for (int i=0; i<size; i++)
		 ProcessAuthor(LastName, Initials, GetContact.Items[i]);
	   cxListBox1->ItemIndex = 0;
	   Contact = (CONTACT*)cxListBox1->Items->Objects[0];
	   FillNeotomaContactCard(Contact);
	   CurrentContact = Contact;
	   cxButton1->Enabled = true;
	   cxButton6->Visible = true;
	   }
	 else {
	   ClearNeotomaContactCard();
	   CurrentContact = NULL;
	   cxButton6->Visible = false;
	   }
	 }
   Screen->Cursor = crDefault;
   StatusBar1->SimpleText = L"";
}
//---------------------------------------------------------------------------

void TNeotomaContactForm::SearchContact(UnicodeString LastName, int& size)
{
   cxTextEdit1->Text = LastName;
   cxTextEdit2->Clear();
   NeotomaContactByFamilyName GetContact(ipsJSONS1, TcpClient1);
   GetContact.AddParam(L"FAMILYNAME", LastName);
   StatusBar1->SimpleText = GetContact.WebServiceName();
   Screen->Cursor = crHourGlass;
   CONTACT *Contact;
   if (GetContact.Execute()) {
	 size = GetContact.Size();
	 ClearContactsList();
	 if (size > 0) {
	   for (int i=0; i<size; i++)
		 ProcessAuthor(LastName, L"", GetContact.Items[i]);
	   cxListBox1->ItemIndex = 0;
	   Contact = (CONTACT*)cxListBox1->Items->Objects[0];
	   FillNeotomaContactCard(Contact);
	   CurrentContact = Contact;
	   cxButton1->Enabled = true;
	   cxButton6->Visible = true;
	   }
	 else {
	   ClearNeotomaContactCard();
	   CurrentContact = NULL;
	   cxButton6->Visible = false;
	   }
	 }
   Screen->Cursor = crDefault;
   StatusBar1->SimpleText = L"";
}
//---------------------------------------------------------------------------

void TNeotomaContactForm::ProcessAuthor(UnicodeString LastName, UnicodeString Initials,
	 NTMCONTACT& ntm_contact)
{
   NTMCONTACT ContactAlias;
   CONTACT *Contact;

   int ContactID = ntm_contact.ContactID;
   int AliasID = ntm_contact.AliasID;
   bool AliasFound = false;
   UnicodeString Name;
   if (ContactID != AliasID && ContactID != -1 && ContactID != -1)
	 AliasFound = GetContactByID(AliasID, ContactAlias);
   if (AliasFound) {
	 Contact = new CONTACT(ContactAlias, ContactStatuses);
	 Name = L"*";
	 cxListBox1->ShowHint = true;
	 UnicodeString Hint = L"Alias for " + LastName;
	 if (!Initials.IsEmpty())
	   Hint += (L", " + Initials);
	 if (!ntm_contact.Suffix.IsEmpty())
	   Hint += (L", " + ntm_contact.Suffix);
	 cxListBox1->Hint = Hint;
	 }
   else {
	 Contact = new CONTACT(ntm_contact, ContactStatuses);
	 cxListBox1->ShowHint = false;
	 }

   Name += FormatAuthorName(Contact->FamilyName, Contact->LeadingInitials, Contact->Suffix);
   cxListBox1->Items->AddObject(Name, (TObject*)Contact);
}
//---------------------------------------------------------------------------

UnicodeString TNeotomaContactForm::FormatAuthorName(UnicodeString LastName,
   UnicodeString Initials, UnicodeString Suffix)
{
   UnicodeString Name = LastName;
   if (!Initials.IsEmpty())
	 Name += (L", " + Initials);
   if (!Suffix.IsEmpty())
	 Name += (L", " + Suffix);
   return Name;
}
//---------------------------------------------------------------------------

UnicodeString TNeotomaContactForm::FormatContactName(UnicodeString LastName,
   UnicodeString GivenNames, UnicodeString Initials, UnicodeString Suffix)
{
   UnicodeString ContactName = LastName;
   if (!GivenNames.IsEmpty())
	 ContactName += (L", " + GivenNames);
   else if (!Initials.IsEmpty())
	 ContactName += (L", " + Initials);
   if (!Suffix.IsEmpty())
	 ContactName += (L", " + Suffix);
   return ContactName;
}
//---------------------------------------------------------------------------

int TNeotomaContactForm::GetSetStatusIndex(TcxComboBox* cxComboBoxStatus)
{
   int StatusIndex;
   // if status not set, set to "unknown"
   if (cxComboBoxStatus->Text.IsEmpty() || cxComboBoxStatus->ItemIndex == -1) {     // or 0 !
	 StatusIndex = cxComboBoxStatus->Properties->Items->IndexOf(L"unknown");
	 cxComboBoxStatus->ItemIndex = StatusIndex;
	 }
   // get StatusIndex
   UnicodeString Status = cxComboBoxStatus->Text;
   map<int, UnicodeString>::iterator itr;
   for (itr = ContactStatuses.begin(); itr != ContactStatuses.end(); itr++) {
	 if (SameText(Status, itr->second)) {
	   StatusIndex = itr->first;
	   break;
	   }
	 }
   return StatusIndex;
}
//---------------------------------------------------------------------------

bool TNeotomaContactForm::GetContactByID(int ContactID, NTMCONTACT& ntm_contact)
{
   bool rv = false;

   NeotomaContactByID GetContact(ipsJSONS1, TcpClient1);
   GetContact.AddParam(L"CONTACTID", ContactID);
   StatusBar1->SimpleText = GetContact.WebServiceName();
   if (GetContact.Execute()) {
	 if (GetContact.Size() > 0) {
	   ntm_contact = GetContact.Items[0];
	   rv = true;
	   }
	 }
   StatusBar1->SimpleText = L"";
   return rv;
}
//---------------------------------------------------------------------------

void TNeotomaContactForm::HighLight(map<int, int>& highlights)
{
   map<int, int>::iterator itr;
   for (itr=highlights.begin(); itr != highlights.end(); itr++) {
	 cxRichEdit1->SelStart = itr->first;
	 cxRichEdit1->SelLength = itr->second;
	 TTextAttributes* tattrib = cxRichEdit1->SelAttributes;
	 tattrib->Style = tattrib->Style << fsBold;
	 tattrib->Color = clNavy;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaContactForm::cxListBox1Click(TObject *Sender)
{
   CurrentContact = (CONTACT*)cxListBox1->Items->Objects[cxListBox1->ItemIndex];
   FillNeotomaContactCard(CurrentContact);
//#ifdef stewardversion
   if (tiLicense->Type() == verNEOTOMASTEWARD) {
	 cxButton3->Caption = L"Update Contact";
	 cxButton3->Enabled = false;
	 ManualEdit = false;
	 }
//#endif
}
//---------------------------------------------------------------------------

// search button
void __fastcall TNeotomaContactForm::cxButton2Click(TObject *Sender)
{
   int size;
   UnicodeString LastName = cxTextEdit1->Text;
   UnicodeString Initials = cxTextEdit2->Text;
   if (LastName.IsEmpty()) {
	 Beep();
	 MessageDlg(L"No Family Name entered!", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 return;
	 }
   if (Initials.IsEmpty())
	 SearchContact(LastName, size);
   else
	 SearchContact(LastName, Initials, size);

   Instructions(LastName, L"", Initials, L"", size);
//#ifdef stewardversion
   if (tiLicense->Type() == verNEOTOMASTEWARD) {
	 cxButton3->Caption = L"Update Contact";
	 cxButton3->Enabled = false;
	 }
//#endif

   if (size == 0) {
	 CurrentContact = NULL;
	 ClearNeotomaContactCard();
	 MessageDlg(L"No matching name found. Try an alternative spelling or wildcard.", mtInformation, TMsgDlgButtons() << mbOK, 0);
	 }
}
//---------------------------------------------------------------------------

// Match button
void __fastcall TNeotomaContactForm::cxButton1Click(TObject *Sender)
{
   return;
}
//---------------------------------------------------------------------------

UnicodeString TNeotomaContactForm::CheckGivenNameSpaces(UnicodeString Name)
{
   UnicodeString GivenNames;
   Name = Name.Trim();
   int pos = 1;
   int len = Name.Length();
   int end = len + 1;
   while (pos < end) {
	 UnicodeString Letter = Name.SubString(pos,1);
	 GivenNames += Letter;
	 if (Letter == L"." && pos < len) {
	   UnicodeString NextLetter = Name.SubString(pos+1,1);
	   if (NextLetter != L" " && NextLetter != L"-")
		 GivenNames += L" ";
	   }
	 pos++;
	 }
   return GivenNames;
}
//---------------------------------------------------------------------------

UnicodeString TNeotomaContactForm::InitialsFromGivenNames(UnicodeString GivenNames)
{
   UnicodeString Initials;
   UnicodeString delimiters = L" .-";
   GivenNames = GivenNames.Trim();
   int pos = 1;
   int len = GivenNames.Length();
   int end = len + 1;
   bool NewInitial = true;
   while (pos < end) {
	 UnicodeString Letter = GivenNames.SubString(pos,1);
	 if (NewInitial) {
	   if (!Letter.IsDelimiter(delimiters,1)) {
		 Initials += (Letter + L".");
		 NewInitial = false;
		 }
	   }
	 else if (Letter == L"-") {
	   Initials += Letter;
	   NewInitial = true;
	   }
	 else if (Letter == L" ") {
	   NewInitial = true;
	   }
	 pos++;
	 }
   return Initials;
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaContactForm::cxTextEditGivenNames2PropertiesValidate(TObject *Sender,
		  Variant &DisplayValue, TCaption &ErrorText, bool &Error)
{
   UnicodeString OldNames = VarToStr(DisplayValue);
   UnicodeString NewNames = CheckGivenNameSpaces(OldNames);

   if (!SameText(OldNames, NewNames))
     DisplayValue = NewNames;
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaContactForm::cxComboBoxStatusPropertiesValidate(TObject *Sender,
		  Variant &DisplayValue, TCaption &ErrorText, bool &Error)
{
   UnicodeString Status = VarToStr(DisplayValue);
   if (!Status.IsEmpty() && cxComboBoxStatus2->Properties->Items->IndexOf(Status) == -1) { // invalid status entered
	 Error = true;
	 ErrorText = "Invalid status entered!";
	 DisplayValue = L"";
	 }
}
//---------------------------------------------------------------------------

bool TNeotomaContactForm::CheckUploadData(UnicodeString& FamilyName, UnicodeString& GivenNames, UnicodeString& Initials)
{
   UnicodeString msg;

   // check for missing data
   cxTextEditFamilyName2->Text = cxTextEditFamilyName2->Text.Trim();
   cxTextEditGivenNames2->Text = cxTextEditGivenNames2->Text.Trim();
   cxTextEditInitials2->Text = cxTextEditInitials2->Text.Trim();
   FamilyName = cxTextEditFamilyName2->Text;
   GivenNames = cxTextEditGivenNames2->Text;
   Initials = cxTextEditInitials2->Text;

   bool ShouldBeInitials = true;
   if (FamilyName.IsEmpty()) {
	 MessageDlg(L"Family name cannot be blank!", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 return false;
	 }
   if (Initials.IsEmpty()) {
	 if (!GivenNames.IsEmpty()) {
	   msg = L"Leading initials are blank. Form initials from given names?";
	   if (MessageDlg(msg, mtWarning, TMsgDlgButtons() << mbYes << mbNo << mbAbort, 0) == mrYes) {
		 Initials = InitialsFromGivenNames(GivenNames);
		 msg = L"Leading initials formed from given names as \"" + Initials + L"\"";
		 if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbOK << mbAbort, 0) == mrOk)
		   cxTextEditInitials2->Text = Initials;
		 else
		   return false;
		 }
	   else
		 return false;
	   }
	 else {
	   msg = L"Leading initials are blank. Should there be leading initials?";
	   if (MessageDlg(msg, mtWarning, TMsgDlgButtons() << mbYes << mbNo << mbAbort, 0) == mrNo)
		 ShouldBeInitials = false;
	   else
		 return false;
	   }
	 }

   if (ShouldBeInitials && GivenNames.IsEmpty()) {
	 msg = L"Given names are blank. Use leading initials as given names?";
	 if (MessageDlg(msg, mtWarning, TMsgDlgButtons() << mbYes << mbNo << mbAbort, 0) == mrYes) {
	   GivenNames = CheckGivenNameSpaces(Initials);
	   msg = L"Leading initials converted to given names as \"" + GivenNames + L"\"";
	   if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbOK << mbAbort, 0) == mrOk)
		 cxTextEditGivenNames2->Text = GivenNames;
	   else
		 return false;
	   }
	 else
	   return false;
	 }
   return true;
}
//---------------------------------------------------------------------------

void TNeotomaContactForm::UploadContact(UnicodeString FamilyName, UnicodeString GivenNames, UnicodeString Initials)
{
   UnicodeString msg;
   UnicodeString ErrorMsg;
   int ContactID = -1;
   vector<int> newids;

   UnicodeString Address = cxMemoAddress2->Text;
   if (!Address.IsEmpty()) {
	 int len = Address.Length();
	 Address = Address.Trim();
	 int pos;
	 while ((pos = Address.Pos(L" \r\n")) > 0)
	   Address.Delete(pos,1);
	 if (Address.Length() < len)
	   cxMemoAddress2->Text = Address;
	 }

   if (cxTextEditID2->Text.IsEmpty()) {  // upload new contact
	 InsertData InsertContact(L"InsertContact", 13, ipsHTTPS1, ipsJSONS1, TcpClient1);
	 StatusBar1->SimpleText = L"InsertContact";

	 UnicodeString Suffix = cxTextEditSuffix2->Text;
	 UnicodeString ContactName = FormatContactName(FamilyName, GivenNames, Initials, Suffix);
	 InsertContact.Add(L"CONTACTNAME", ContactName);
	 InsertContact.Add(L"STATUSID", GetSetStatusIndex(cxComboBoxStatus2), -1);
	 InsertContact.Add(L"FAMILYNAME", FamilyName);
	 InsertContact.Add(L"INITIALS", Initials);
	 InsertContact.Add(L"GIVENNAMES", GivenNames);
	 InsertContact.Add(L"SUFFIX", Suffix);
	 InsertContact.Add(L"TITLE", cxComboBoxTitle2->Text);
	 InsertContact.Add(L"PHONE", cxTextEditPhone2->Text);
	 InsertContact.Add(L"FAX", cxTextEditFax2->Text);
	 InsertContact.Add(L"EMAIL", cxTextEditEmail2->Text);
	 InsertContact.Add(L"URL", cxTextEditURL2->Text);
	 InsertContact.Add(L"ADDRESS", cxMemoAddress2->Text);
	 InsertContact.Add(L"NOTES", cxMemoNotes2->Text);

	 Screen->Cursor = crHourGlass;
	 InsertContact.PostData();

	 //ShowMessage(L"Breakpoint 1");
	 if (InsertContact.Post(newids, ErrorMsg)) {
	   if (newids.size() > 0) {
		 int newid = newids[0];
		 // ShowMessage(L"newid = " + IntToStr(newid));
		 UpdateData UpdateAliasID(L"UpdateContactAliasID", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
		 StatusBar1->SimpleText = L"UpdateContactAliasID";
		 UpdateAliasID.Add(L"CONTACTID", newid);
		 UpdateAliasID.Add(L"ALIASID", newid);
		 if (UpdateAliasID.Post(ErrorMsg)) {
		   cxTextEditID2->Text = IntToStr(newid);
		   cxButton1->Enabled = true;
		   cxButton3->Caption = L"Update Contact";
		   cxButton3->Enabled = false;
		   msg = L"New contact «" + ContactName + L"» uploaded to Neotoma. ContactID = " +
				 IntToStr(newid) + L".";
		   ContactID = newid;
		   CurrentContact = NULL;  //new
		   }
		 }
	   }
	 }
   else {  // update contact
	 UpdateData UpdateContact(L"UpdateContact", 15, ipsHTTPS1, ipsJSONS1, TcpClient1);
	 StatusBar1->SimpleText = L"UpdateContact";
	 UpdateContact.Add(L"CONTACTID", CurrentContact->NeotomaContactID);
	 UpdateContact.Add(L"ALIASID", CurrentContact->NeotomaAliasID);
	 UnicodeString Suffix = cxTextEditSuffix2->Text;
	 UnicodeString ContactName = FormatContactName(FamilyName, GivenNames, Initials, Suffix);
	 UpdateContact.Add(L"CONTACTNAME", ContactName);
	 UpdateContact.Add(L"STATUSID", GetSetStatusIndex(cxComboBoxStatus2));
	 UpdateContact.Add(L"FAMILYNAME", FamilyName);
	 UpdateContact.Add(L"INITIALS", Initials);
	 UpdateContact.Add(L"GIVENNAMES", GivenNames);
	 UpdateContact.Add(L"SUFFIX", Suffix);
	 UpdateContact.Add(L"TITLE", cxComboBoxTitle2->Text);
	 UpdateContact.Add(L"PHONE", cxTextEditPhone2->Text);
	 UpdateContact.Add(L"FAX", cxTextEditFax2->Text);
	 UpdateContact.Add(L"EMAIL", cxTextEditEmail2->Text);
	 UpdateContact.Add(L"URL", cxTextEditURL2->Text);
	 UpdateContact.Add(L"ADDRESS", cxMemoAddress2->Text);
	 UpdateContact.Add(L"NOTES", cxMemoNotes2->Text);

	 Screen->Cursor = crHourGlass;
	 if (UpdateContact.Post(ErrorMsg)) {
	   msg = L"Update successful!";
	   cxButton3->Enabled = false;
	   ManualEdit = false;
	   ContactID = CurrentContact->NeotomaContactID;
	   }
	 }

   if (ContactID > -1) {
	 NTMCONTACT ntm_contact;
	 if (GetContactByID(ContactID, ntm_contact)) {
	   CONTACT* NewContact = new CONTACT(ntm_contact, ContactStatuses);
	   cxListBox1->ShowHint = false;
	   UnicodeString Name = FormatAuthorName(NewContact->FamilyName, NewContact->LeadingInitials, NewContact->Suffix);

	   if (CurrentContact != NULL) {
		 CONTACT* OldContact = (CONTACT*)cxListBox1->Items->Objects[cxListBox1->ItemIndex];
		 delete OldContact;
		 cxListBox1->Items->Delete(cxListBox1->ItemIndex);
		 }
	   cxListBox1->Items->AddObject(Name, (TObject*)NewContact);
	   cxListBox1->ItemObject = (TObject*)NewContact;
	   CurrentContact = NewContact;
	   FillNeotomaContactCard(NewContact);
	   CurrentContact = NewContact;
	   MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
	   }
	 }
   else
	 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);

   StatusBar1->SimpleText = L"";
   Screen->Cursor = crDefault;
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaContactForm::FormActivate(TObject *Sender)
{
   return;
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaContactForm::cxSpinEdit1PropertiesChange(TObject *Sender)
{
   return;
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaContactForm::cxButton3Click(TObject *Sender)
{
   return;
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaContactForm::cxExit(TObject *Sender)
{
//#ifdef stewardversion
   if (tiLicense->Type() == verNEOTOMASTEWARD) {
	 if (!cxButton3->Enabled)
	   ManualEdit = false;
	 }
//#endif
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaContactForm::Publications1Click(TObject *Sender)
{
   NeotomaContactPubForm = new TNeotomaContactPubForm(CurrentContact->NeotomaContactID,
	 CurrentContact->ShortContactName, StatusBar1, this);
   NeotomaContactPubForm->ShowModal();
   delete NeotomaContactPubForm;
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaContactForm::Datasets1Click(TObject *Sender)
{
   NeotomaContactDatasetsForm = new TNeotomaContactDatasetsForm(CurrentContact->NeotomaContactID,
	 CurrentContact->ShortContactName, StatusBar1, this);
   NeotomaContactDatasetsForm->ShowModal();
   delete NeotomaContactDatasetsForm;
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaContactForm::cxTextEditPropertiesChange(TObject *Sender)
{
//#ifdef stewardversion
   if (tiLicense->Type() == verNEOTOMASTEWARD) {
	 if (ManualEdit) {
	   UnicodeString newtext = ((TcxTextEdit*)Sender)->Text;
	   cxButton3->Enabled = !SameText(newtext, oldtext);
	   }
	 }
//#endif
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaContactForm::cxComboBoxPropertiesChange(TObject *Sender)
{
//#ifdef stewardversion
   if (tiLicense->Type() == verNEOTOMASTEWARD) {
	 if (ManualEdit) {
	   UnicodeString newtext = ((TcxComboBox*)Sender)->Text;
	   cxButton3->Enabled = !SameText(newtext, oldtext);
	   }
	 }
//#endif
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaContactForm::cxMemoPropertiesChange(TObject *Sender)
{
//#ifdef stewardversion
   if (tiLicense->Type() == verNEOTOMASTEWARD) {
	 if (ManualEdit) {
	   UnicodeString newtext = ((TcxMemo*)Sender)->Text;
	   cxButton3->Enabled = !SameText(newtext, oldtext);
	   }
	 }
//#endif
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaContactForm::cxTextEditEnter(TObject *Sender)
{
//#ifdef stewardversion
   if (tiLicense->Type() == verNEOTOMASTEWARD) {
	 if (!cxButton3->Enabled) {
	   oldtext = ((TcxTextEdit*)Sender)->Text;
	   ManualEdit = true;
	   }
	 }
//#endif
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaContactForm::cxComboBoxEnter(TObject *Sender)
{
//#ifdef stewardversion
   if (tiLicense->Type() == verNEOTOMASTEWARD) {
	 if (!cxButton3->Enabled) {
	   oldtext = ((TcxComboBox*)Sender)->Text;
	   ManualEdit = true;
	   }
	 }
//#endif
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaContactForm::cxMemoEnter(TObject *Sender)
{
//#ifdef stewardversion
   if (tiLicense->Type() == verNEOTOMASTEWARD) {
	 if (!cxButton3->Enabled) {
	   oldtext = ((TcxMemo*)Sender)->Text;
	   ManualEdit = true;
	   }
	 }
//#endif
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

__fastcall TUploadAuthorForm::TUploadAuthorForm(vector<AUTHOR>& author_list,
	TContactList* contact_list, TComponent* Owner) : TNeotomaContactForm(Owner)
{
   if (contact_list != NULL) {
	 ContactList = contact_list;
	 LocalContactList = false;
	 }
   else {
	 ContactList = new TContactList();
	 LocalContactList = true;
	 }

   SetAuthorList(author_list);

   Caption = L"Neotoma Author Contact";
   Panel4->Caption = L"Author";
   cxButton3->Visible = true;
   cxButton7->Visible = true;

   cxTextEditID1->Visible = false;
   LabelGivenNames1->Visible = false;
   cxTextEditGivenNames1->Visible = false;
   LabelTitle1->Visible = false;
   cxComboBoxTitle1->Visible = false;
   LabelStatus1->Visible = false;
   cxComboBoxStatus1->Visible = false;
   LabelPhone1->Visible = false;
   cxTextEditPhone1->Visible = false;
   LabelFax1->Visible = false;
   cxTextEditFax1->Visible = false;
   LabelEmail1->Visible = false;
   cxTextEditEmail1->Visible = false;
   LabelURL1->Visible = false;
   cxTextEditURL1->Visible = false;
   LabelAddress1->Visible = false;
   cxMemoAddress1->Visible = false;
   LabelNotes1->Visible = false;
   cxMemoNotes1->Visible = false;
   cxButtonUpdate->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TUploadAuthorForm::FormActivate(TObject *Sender)
{
   if (!Activated) {
	 GetContactStatuses();
	 SetAuthor(0);
	 Instructions(AuthorList[0].LastName, L"", AuthorList[0].Initials, L"", cxListBox1->Count);
	 Activated = true;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TUploadAuthorForm::FormDestroy(TObject *Sender)
{
   ClearContactsList();
   if (LocalContactList)
	 delete ContactList;
}
//---------------------------------------------------------------------------

void TUploadAuthorForm::SetAuthorList(vector<AUTHOR>& author_list)
{
   //AuthorList.assign(author_list.begin(), author_list.end());
   AuthorList = author_list;

   // AuthorList[NextAuthorIndex].contact->NeotomaContactID == -1
   for (unsigned int i=0; i<AuthorList.size(); i++) {
	 if (AuthorList[i].contact != NULL)
	   AuthorList[i].contact->NeotomaContactID = -1;
	 }

   CurrentAuthorIndex = 0;
   if (AuthorList.size() > 1) {
	 cxSpinEdit1->Visible = true;
	 cxSpinEdit1->Properties->MinValue = 1;
	 cxSpinEdit1->Properties->MaxValue = AuthorList.size();
	 }
   else
	 cxSpinEdit1->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TUploadAuthorForm::cxButtonRightArrowClick(TObject *Sender)
{
   cxTextEditID2->Clear();
   cxTextEditFamilyName2->Text = cxTextEditFamilyName1->Text;
   cxTextEditInitials2->Text = cxTextEditInitials1->Text;
   cxTextEditSuffix2->Text = cxTextEditSuffix1->Text;
   cxTextEditGivenNames2->Clear();
   cxComboBoxTitle2->Clear();
   cxComboBoxStatus2->Clear();
   cxTextEditPhone2->Clear();
   cxTextEditFax2->Clear();
   cxTextEditEmail2->Clear();
   cxTextEditURL2->Clear();
   cxMemoAddress2->Clear();
   cxMemoNotes2->Clear();
   ClearContactsList();
   cxButton1->Enabled = false;
   cxButton3->Caption = L"Upload Contact";
   cxButton3->Enabled = true;
}
//---------------------------------------------------------------------------

void TUploadAuthorForm::SetAuthor(int idx)
{
   if (AuthorList.size() == 0)
     return;
   if (AuthorList[idx].contact == NULL) {
	 cxLabelID1->Visible = false;
	 cxTextEditID1->Visible = false;
	 }
   else {
	 cxLabelID1->Visible = true;
	 cxTextEditID1->Visible = true;
	 if (AuthorList[idx].contact->NeotomaContactID > -1)
	   cxTextEditID1->Text = IntToStr(AuthorList[idx].contact->NeotomaContactID);
	 else
	   cxTextEditID1->Clear();
	 }

   cxTextEditFamilyName1->Text = AuthorList[idx].LastName;
   cxTextEditGivenNames1->Text = AuthorList[idx].GivenNames;
   UnicodeString Initials = AuthorList[idx].Initials;

   int pos = Initials.Pos(L" ");
   while (pos > 0) {            // delete any spaces
	 Initials.Delete(pos,1);
	 pos = Initials.Pos(L" ");
	 }
   cxTextEditInitials1->Text = Initials;
   pos = Initials.Pos(L".");
   while (pos > 0) {            // delete any periods
	 Initials.Delete(pos,1);
	 pos = Initials.Pos(L".");
	 }
   int nInitials = Initials.Length();
   cxTextEditSuffix1->Text = AuthorList[idx].Suffix;

   int size = 0;
   if (nInitials > 1) {  // attempt to find Neotoma contact with same last name and exact initials
	 SearchContact(AuthorList[idx].LastName, AuthorList[idx].Initials, size);
	 if (size == 0) {
	   Initials.SetLength(1);
	   nInitials = 1;
	   }
	 }
   if (nInitials == 1) {   // attempt to find Neotoma contact with same last name and first initial
	 Initials += L"%";
	 SearchContact(AuthorList[idx].LastName, Initials, size);
	 }
   else if (nInitials == 0)                // attempt to find Neotoma contact with same last name
	 SearchContact(AuthorList[idx].LastName, size);
}
//---------------------------------------------------------------------------

void TUploadAuthorForm::Instructions(UnicodeString LastName, UnicodeString GivenNames,
	UnicodeString Initials, UnicodeString Suffix, int size)
{
   UnicodeString msg;
   UnicodeString AuthorName = FormatAuthorName(LastName, Initials, L"");

   map<int, int> highlights;
   if (size == 1) {
	 msg = L"Neotoma contact matching " + AuthorName + L" found";
	 highlights[25] = AuthorName.Length();
	 UnicodeString ListAuthor = cxListBox1->Items->Strings[0];
	 if (ListAuthor.SubString(1,1) == L"*") {  // alias author
	   ListAuthor.Delete(1,1);
	   msg += (L" with alias " + ListAuthor);
	   highlights[msg.Length()-ListAuthor.Length()] = ListAuthor.Length();
	   }
	 if (msg.SubString(msg.Length(),1) != L"." )
	   msg += L".";
	 msg += " If this contact matches the author, click the Match button. ";
	 highlights[msg.Length()-14] = 5;
	 msg += L"If not, either search for an alternative spelling of the author's name, ";
	 msg += L"or click the right arrow button, add missing details, and upload the new contact.";
	 }
   else if (size > 1) {
	 msg = IntToStr(size) + L" Neotoma contacts found matching author name " + AuthorName;
	 highlights[msg.Length()-AuthorName.Length()] = AuthorName.Length();
	 if (msg.SubString(msg.Length(),1) != L"." )
	   msg += L".";
	 msg += L" If the highlighted contact matches the author, click the Match button. ";
	 highlights[msg.Length()-14] = 5;
	 msg += L"If no contacts match the author, either search for an alternative spelling of the author's name, ";
	 msg += L"or click the right arrow button, add missing details, and upload the new contact.";
	 }
   else {   // size == 0
	 msg = L"No Neotoma match for author " + AuthorName;
	 highlights[msg.Length()-AuthorName.Length()] = AuthorName.Length();
	 if (msg.SubString(msg.Length(),1) != L"." )
	   msg += L".";
	 msg += L" Either search for an alternative spelling of the author's name, ";
	 msg += L"or click the right arrow button, add missing details, and upload the new contact.";
	 }

   cxRichEdit1->Text = msg;
   HighLight(highlights);
}
//---------------------------------------------------------------------------

int TUploadAuthorForm::GetContactID(void)
{
   return CurrentContact->NeotomaContactID;
}
//---------------------------------------------------------------------------

// Match button
void __fastcall TUploadAuthorForm::cxButton1Click(TObject *Sender)
{
   //TODO: looks like with a new publication with new author, the contact doesn't yet exist
   CurrentContact->FormatContactName();
   if (AuthorList[CurrentAuthorIndex].contact == NULL) {
	 vector<AUTHOR>::pointer Author = &AuthorList[CurrentAuthorIndex];
	 if (!GetAuthorContact(Author, ContactList)) {
	   CONTACT* contact = new CONTACT(Author);
	   Author->contact = contact;
	   ContactList->Add(contact);
	   }
	 }
   else
	 AuthorList[CurrentAuthorIndex].contact->Copy(CurrentContact);

   AuthorList[CurrentAuthorIndex].NeotomaContactID = CurrentContact->NeotomaContactID;
   AuthorList[CurrentAuthorIndex].contact->NeotomaContactID = CurrentContact->NeotomaContactID;

   cxLabelID1->Visible = true;
   cxTextEditID1->Visible = true;
   if (CurrentContact->NeotomaContactID > -1)
	 cxTextEditID1->Text = IntToStr(CurrentContact->NeotomaContactID);
   else
	 cxTextEditID1->Clear();
   cxTextEditFamilyName1->Text = CurrentContact->FamilyName;
   cxTextEditInitials1->Text = CurrentContact->LeadingInitials;
   cxTextEditSuffix1->Text = CurrentContact->Suffix;

   bool AllMatched = true;
   // go to next author
   if (AuthorList.size() > 1) {
	 int NextAuthorIndex = CurrentAuthorIndex + 1;
	 if (NextAuthorIndex < (int)AuthorList.size()) {       // a next author exists
	   if (AuthorList[NextAuthorIndex].contact == NULL ||
		   AuthorList[NextAuthorIndex].contact->NeotomaContactID == -1) {  // contact has not been set
		 CurrentAuthorIndex = NextAuthorIndex;
		 cxTextEditID1->Clear();
		 SetAuthor(CurrentAuthorIndex);
		 ManualSpin = false;
		 cxSpinEdit1->Value = CurrentAuthorIndex + 1;
		 Instructions(AuthorList[CurrentAuthorIndex].LastName, L"",
		 	AuthorList[CurrentAuthorIndex].Initials, L"", cxListBox1->Count);
		 }
	   }
	 for (unsigned int i=0; i<AuthorList.size(); i++) {
	   if (AuthorList[i].contact == NULL ||
		   AuthorList[i].contact->NeotomaContactID == -1) {
		 AllMatched = false;
		 break;
		 }
	   }
	 }

   if (AllMatched) {
	 UnicodeString msg;
	 if (AuthorList.size() == 1)
	   msg = L"Author matched with Neotoma contact. Finish?";
	 else
	   msg = L"All authors matched with Neotoma contacts. Finish?";
	 if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes) {
	   for (unsigned int i=0; i<AuthorList.size(); i++)
		 AuthorList[i].contact->NeotomaContactID = AuthorList[i].NeotomaContactID;
	   ModalResult = mrOk;
	   }
	 else
	   cxButton5->Enabled = true;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TUploadAuthorForm::cxSpinEdit1PropertiesChange(TObject *Sender)
{
   if (!ManualSpin) {
	 ManualSpin = true;
	 return;
	 }

   UnicodeString msg;
   map<int, int> highlights;

   int Value = cxSpinEdit1->Value;
   CurrentAuthorIndex = Value - 1;
   SetAuthor(CurrentAuthorIndex);
   CurrentContact = AuthorList[CurrentAuthorIndex].contact;

   UnicodeString AuthorName = FormatAuthorName(AuthorList[CurrentAuthorIndex].LastName,
	 AuthorList[CurrentAuthorIndex].Initials, AuthorList[CurrentAuthorIndex].Suffix);
   msg = L"Author " + AuthorName;
   highlights[7] = AuthorName.Length();
   if (CurrentContact != NULL) {
	 FillNeotomaContactCard(CurrentContact);
	 msg += L" has been matched with a Neotoma contact.";
	 }
   else {
	 if (cxListBox1->Count > 0) {
	   cxListBox1->ItemIndex = 0;
	   CurrentContact = (CONTACT*)cxListBox1->Items->Objects[0];
	   }
	 msg += L" has not been matched with a Neotoma contact. ";
	 msg += L" Either search for the author's name, ";
	 msg += L"or click the right arrow button, add missing details, and upload the new contact.";
	 }
   cxRichEdit1->Text = msg;
   HighLight(highlights);
}
//---------------------------------------------------------------------------

// update/upload button
void __fastcall TUploadAuthorForm::cxButton3Click(TObject *Sender)
{
   UnicodeString FamilyName, GivenNames, Initials, msg;
   if (CheckUploadData(FamilyName, GivenNames, Initials))
	 UploadContact(FamilyName, GivenNames, Initials);
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaContactForm::cxButton7Click(TObject *Sender)
{
   ShowMessage(L"Alias function not yet enabled");
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

__fastcall TGetNeotomaContact::TGetNeotomaContact(CONTACT* contact,
	TComponent* Owner) : TNeotomaContactForm(Owner)
{
   Contact = contact;
   cxButton5->Visible = false;
   if (tiLicense->Type() == verNEOTOMASTEWARD) {
	 cxButton3->Visible = true;
	 int ButtonWidth = cxButton1->Width + cxButton3->Width + cxButton4->Width + 12;
	 cxButton1->Left = (Panel2->Width - ButtonWidth)/2;
	 cxButton3->Left = cxButton1->Left + cxButton1->Width + 6;
	 cxButton4->Left = cxButton3->Left + cxButton3->Width + 6;
	 }
   else {
	 int ButtonWidth = cxButton1->Width + cxButton4->Width + 6;
	 cxButton1->Left = (Panel2->Width - ButtonWidth)/2;
	 cxButton4->Left = cxButton1->Left + cxButton1->Width + 6;
	 cxButtonRightArrow->Visible = false;
	 cxTextEditFamilyName2->Properties->ReadOnly = true;
	 cxTextEditGivenNames2->Properties->ReadOnly = true;
	 cxTextEditInitials2->Properties->ReadOnly = true;
	 cxTextEditSuffix2->Properties->ReadOnly = true;
	 cxComboBoxTitle2->Properties->ReadOnly = true;
	 cxComboBoxStatus2->Properties->ReadOnly = true;
	 cxTextEditPhone2->Properties->ReadOnly = true;
	 cxTextEditFax2->Properties->ReadOnly = true;
	 cxTextEditEmail2->Properties->ReadOnly = true;
	 cxTextEditURL2->Properties->ReadOnly = true;
	 cxMemoAddress2->Properties->ReadOnly = true;
	 cxMemoNotes2->Properties->ReadOnly = true;
	 }

   FillContactCard(Contact);
}
//---------------------------------------------------------------------------

void __fastcall TGetNeotomaContact::FormActivate(TObject *Sender)
{
   if (!Activated) {
	 cxGroupBox4->Visible = true;
	 GetContactStatuses();
	 SetContact();
	 Instructions(Contact->FamilyName, Contact->GivenNames, Contact->LeadingInitials,
	 	Contact->Suffix, cxListBox1->Count);
	 Activated = true;
	 cxGroupBox4->Visible = false;
	 }
}
//---------------------------------------------------------------------------

void TGetNeotomaContact::SetContact(void)
{
   if (Contact->NeotomaContactID == -1) {
	 cxLabelID1->Visible = false;
	 cxTextEditID1->Visible = false;
	 }

   UnicodeString Initials = Contact->LeadingInitials;

   int pos = Initials.Pos(L" ");
   while (pos > 0) {            // delete any spaces
	 Initials.Delete(pos,1);
	 pos = Initials.Pos(L" ");
	 }
   cxTextEditInitials1->Text = Initials;
   pos = Initials.Pos(L".");
   while (pos > 0) {            // delete any periods
	 Initials.Delete(pos,1);
	 pos = Initials.Pos(L".");
	 }
   int nInitials = Initials.Length();

   int size = 0;
   if (nInitials > 1) {  // attempt to find Neotoma contact with same last name and exact initials
	 SearchContact(Contact->FamilyName, Contact->LeadingInitials, size);
	 if (size == 0) {
	   Initials.SetLength(1);
	   nInitials = 1;
	   }
	 }
   if (nInitials == 1) {   // attempt to find Neotoma contact with same last name and first initial
	 Initials += L"%";
	 SearchContact(Contact->FamilyName, Initials, size);
	 }
   else if (nInitials == 0)                // attempt to find Neotoma contact with same last name
	 SearchContact(Contact->FamilyName, size);
}
//---------------------------------------------------------------------------

void TGetNeotomaContact::Instructions(UnicodeString LastName, UnicodeString GivenNames,
	UnicodeString Initials, UnicodeString Suffix, int size)
{
   UnicodeString msg;
   UnicodeString ContactName = FormatContactName(LastName, GivenNames, Initials, Suffix);

   map<int, int> highlights;
   if (size == 1) {
	 msg = L"Neotoma contact matching " + ContactName + L" found";
	 highlights[25] = ContactName.Length();
	 UnicodeString ListContact = cxListBox1->Items->Strings[0];
	 if (ListContact.SubString(1,1) == L"*") {  // alias author
	   ListContact.Delete(1,1);
	   msg += (L" with alias " + ListContact);
	   highlights[msg.Length()-ListContact.Length()] = ListContact.Length();
	   }
	 if (msg.SubString(msg.Length(),1) != L"." )
	   msg += L".";
	 msg += " If the Neotoma contact matches the contact, click the Match button. ";
	 highlights[msg.Length()-14] = 5;
	 msg += L"If not, try searching for an alternative spelling of the contact's name.";
	 if (tiLicense->Type() == verNEOTOMASTEWARD)
	   msg += L" If the contact is new, you can click the right arrow button, add missing details, and upload the new contact.";
	 }
   else if (size > 1) {
	 msg = IntToStr(size) + L" Neotoma contacts found matching contact name " + ContactName;
	 highlights[msg.Length()-ContactName.Length()] = ContactName.Length();
	 if (msg.SubString(msg.Length(),1) != L"." )
	   msg += L".";
	 msg += L" If the highlighted Neotoma contact matches the contact, click the Match button. ";
	 highlights[msg.Length()-14] = 5;
	 msg += L"If not, try searching for an alternative spelling of the contact's name.";
	 if (tiLicense->Type() == verNEOTOMASTEWARD)
	   msg += L" If the contact is new, you can click the right arrow button, add missing details, and upload the new contact.";
	 }
   else {   // size == 0
	 msg = L"No Neotoma match for contact " + ContactName;
	 highlights[msg.Length()-ContactName.Length()] = ContactName.Length();
	 if (msg.SubString(msg.Length(),1) != L"." )
	   msg += L".";
	 msg += L" Try searching for a alternative spelling of the contact's name. ";
	 if (tiLicense->Type() == verNEOTOMASTEWARD) {
	   msg += L"If the contact is new, you may may click the right arrow button, add additional details in the right panel, ";
	   msg += L"optionally upload the new contact, ";
	   msg += L"then click the Match button.";
	   highlights[msg.Length()-13] = 5;
	   }
	 }

   cxRichEdit1->Text = msg;
   HighLight(highlights);
}
//---------------------------------------------------------------------------

void __fastcall TGetNeotomaContact::cxButtonRightArrowClick(TObject *Sender)
{
   cxTextEditID2->Text = cxTextEditID1->Text;
   UpdateNeotomaContact();
   if (tiLicense->Type() == verNEOTOMASTEWARD) {
	 cxButton3->Enabled = true;
	 cxButton3->Caption = L"Upload Contact";
	 }
}
//---------------------------------------------------------------------------

void __fastcall TGetNeotomaContact::cxButtonUpdateClick(TObject *Sender)
{
   UpdateNeotomaContact();
   if (tiLicense->Type() == verNEOTOMASTEWARD) {
	 cxButton3->Enabled = true;
	 cxButton3->Caption = L"Update Contact";
	 }
}
//---------------------------------------------------------------------------

void TGetNeotomaContact::UpdateNeotomaContact(void)
{
   cxTextEditFamilyName2->Text = cxTextEditFamilyName1->Text;
   cxTextEditGivenNames2->Text = cxTextEditGivenNames1->Text;
   cxTextEditInitials2->Text = cxTextEditInitials1->Text;
   cxTextEditSuffix2->Text = cxTextEditSuffix1->Text;
   cxComboBoxTitle2->ItemIndex = cxComboBoxTitle1->ItemIndex;
   cxComboBoxStatus2->ItemIndex = cxComboBoxStatus1->ItemIndex;
   cxTextEditPhone2->Text = cxTextEditPhone1->Text;
   cxTextEditFax2->Text = cxTextEditFax1->Text;
   cxTextEditEmail2->Text = cxTextEditEmail1->Text;
   cxTextEditURL2->Text = cxTextEditURL1->Text;
   cxMemoAddress2->Text = cxMemoAddress1->Text;
   cxMemoNotes2->Text = cxMemoNotes1->Text;
}
//---------------------------------------------------------------------------

// Match button
void __fastcall TGetNeotomaContact::cxButton1Click(TObject *Sender)
{
   *Contact = *CurrentContact;

   int idx;
   UnicodeString Address = Contact->Address;
   while ((idx = Address.Pos(L"\\r\\n")) > 0) {
	 Address.Delete(idx,4);
	 Address.Insert("\r\n",idx);
	 }
   Contact->Address = Address;

   UnicodeString Notes = Contact->Notes;
   while ((idx = Notes.Pos(L"\\r\\n")) > 0) {
	 Notes.Delete(idx,4);
	 Notes.Insert("\r\n",idx);
	 }
   Contact->Notes = Notes;

   int ContactID;
   if (TryStrToInt(cxTextEditID2->Text, ContactID))
	 Contact->NeotomaContactID = ContactID;

   ModalResult = mrOk;
}
//---------------------------------------------------------------------------

// update/upload button
void __fastcall TGetNeotomaContact::cxButton3Click(TObject *Sender)
{
   if (tiLicense->Type() == verNEOTOMASTEWARD) {
	 if (!Login->IsLoggedIn) {
	   NeotomaLoginForm = new TNeotomaLoginForm(this);
	   NeotomaLoginForm->ShowModal();
	   delete NeotomaLoginForm;
	   }
	 if (Login->IsLoggedIn) {
	   UnicodeString FamilyName, GivenNames, Initials, msg;
	   if (CheckUploadData(FamilyName, GivenNames, Initials)) {
		 UploadContact(FamilyName, GivenNames, Initials);
		 }
	   }
	 }
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaContactForm::ipsJSONS1SSLServerAuthentication(TObject *Sender,
          TipsJSONSSSLServerAuthenticationEventParams *e)
{
   e->Accept = true;
}
//---------------------------------------------------------------------------

