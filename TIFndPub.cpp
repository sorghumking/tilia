//---------------------------------------------------------------------------

#include <vcl.h>
#include "pch.h"
#include <map>
#pragma hdrstop

#include "TIFndPub.h"
#ifndef TIUtilsH
#include "TIUtils.h"
#endif
#ifndef TIPubH
#include "TIPub.h"
#endif
#ifndef TINewTxnH
#include "TINewTxn.h"
#endif

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvCGrid"
#pragma link "AdvGrid"
#pragma link "AdvObj"
#pragma link "BaseGrid"
#pragma link "cxButtons"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "ipwjson"
#pragma link "AdvControlDropDown"
#pragma link "AdvDropDown"
#pragma link "frmctrllink"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxMemo"
#pragma link "cxTextEdit"
#pragma link "AdvCGrid"
#pragma link "AdvControlDropDown"
#pragma link "AdvDropDown"
#pragma link "AdvGrid"
#pragma link "AdvObj"
#pragma link "BaseGrid"
#pragma link "cxButtons"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxMemo"
#pragma link "cxTextEdit"
#pragma link "frmctrllink"
#pragma link "ipwjson"
#pragma link "AdvCGrid"
#pragma link "AdvControlDropDown"
#pragma link "AdvDropDown"
#pragma link "AdvGrid"
#pragma link "AdvObj"
#pragma link "BaseGrid"
#pragma link "cxButtons"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxMemo"
#pragma link "cxTextEdit"
#pragma link "frmctrllink"
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
#pragma link "AdvUtil"
#pragma link "dxSkinOffice2016Colorful"
#pragma link "dxSkinOffice2016Dark"
#pragma link "dxSkinVisualStudio2013Blue"
#pragma link "dxSkinVisualStudio2013Dark"
#pragma link "dxSkinVisualStudio2013Light"
#pragma link "ipsjsons"
#pragma resource "*.dfm"
TFindPubForm *FindPubForm;

//---------------------------------------------------------------------------
__fastcall TFindPubForm::TFindPubForm(TContactList* contact_list, TComponent* Owner) : TForm(Owner)
{
   ContactList = contact_list;
}
//---------------------------------------------------------------------------

__fastcall TFindPubForm::TFindPubForm(TContactList* contact_list, int pub_id, TComponent* Owner) : TForm(Owner)
{
   ContactList = contact_list;
   SetPub(pub_id);
}
//---------------------------------------------------------------------------

void __fastcall TFindPubForm::FormCreate(TObject *Sender)
{
   if (!AdvColumnGrid1->HasCheckBox(0,1))
	 AdvColumnGrid1->AddCheckBoxColumn(0, false, false);
   AdvColumnGrid1->Row = 1;
   AdvColumnGrid1->GotoCell(0,1);
}
//---------------------------------------------------------------------------

void __fastcall TFindPubForm::Edit1Change(TObject *Sender)
{
   cxButton4->Enabled = !Edit1->Text.IsEmpty();
}
//---------------------------------------------------------------------------

// search button
void __fastcall TFindPubForm::cxButton4Click(TObject *Sender)
{
   bool found = false;
   bool error = false;

   Screen->Cursor = crHourGlass;
   if (ComboBox1->ItemIndex == 0) {  // author
	 NeotomaPublicationsByFamilyName Publications(ipsJSONS1, TcpClient1);
	 Publications.AddParam(L"FAMILYNAME", Edit1->Text);
	 StatusBar1->SimpleText = Publications.WebServiceName();
	 if (Publications.Execute()) {
	   if (Publications.Size() > 0)
		 ntm_pubs = Publications.Items;
	   }
	 }
   else if (ComboBox1->ItemIndex == 1) {   // citation
	 NeotomaPublicationsByCitation Publications(ipsJSONS1, TcpClient1);
	 Publications.AddParam(L"CITATION", Edit1->Text);
	 StatusBar1->SimpleText = Publications.WebServiceName();
	 if (Publications.Execute()) {
	   if (Publications.Size() > 0)
		 ntm_pubs = Publications.Items;
	   }
	 }
   else if (ComboBox1->ItemIndex == 2) {   // PublicationID
	 int PubID;
	 if (!TryStrToInt(Edit1->Text, PubID))
	   error = true;
	 if (!error && PubID < 1)
	   error = true;
	 if (error)
	   MessageDlg(L"Invalid PublicationID! Must be a positive integer value.", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 else {
	   NeotomaPublicationsByPubID Publications(ipsJSONS1, TcpClient1);
	   Publications.AddParam(L"PUBLICATIONID", PubID);
	   if (Publications.Execute()) {
		 if (Publications.Size() > 0)
		   ntm_pubs = Publications.Items;
		 }
	   }
	 }

   map<int,NTMPUBLICATION> pubmap;
   for (unsigned int i=0; i<ntm_pubs.size(); i++) {
	 if (pubmap.count(ntm_pubs[i].PublicationID) == 0)
	   pubmap[ntm_pubs[i].PublicationID] = ntm_pubs[i];
	 }
   ntm_pubs.clear();
   map<int,NTMPUBLICATION>::iterator itr;
   for (itr = pubmap.begin(); itr != pubmap.end(); itr++)
	 ntm_pubs.push_back(itr->second);
   pubmap.clear();

   if (ntm_pubs.size() > 0) {
	 Panel4->Caption = L"";
	 PubTypes.clear();
	 set<int> PubIDs;
	 int row = 1;
	 for (unsigned int i=0; i<ntm_pubs.size(); i++) {
	   int PubID = ntm_pubs[i].PublicationID;
	   if (PubIDs.count(PubID) == 0) {
		 PubIDs.insert(PubID);
		 AdvColumnGrid1->Cells[1][row] = PubID;
		 AdvColumnGrid1->Cells[2][row] = ntm_pubs[i].Citation;
		 PubTypes[AdvColumnGrid1->Cells[1][row++].ToInt()] = ntm_pubs[i].PubTypeID;
		 }
	   }
	 AdvColumnGrid1->RowCount = PubIDs.size() + 1;
	 AdvColumnGrid1->AddCheckBoxColumn(0, false, false);
	 found = true;
	 }

   Screen->Cursor = crDefault;
   StatusBar1->SimpleText = L"";
   if (!found)
	 Panel4->Caption = L"No Publications Found";
   if (error || !found) {
	 AdvColumnGrid1->RowCount = 2;
	 AdvColumnGrid1->SetCheckBoxState(0,1,false);
	 AdvColumnGrid1->Cells[1][1] = L"";
	 AdvColumnGrid1->Cells[2][1] = L"";
	 }
}
//---------------------------------------------------------------------------

void TFindPubForm::SetPub(int PubID)
{
   NeotomaPublicationsByPubID Pub(ipsJSONS1, TcpClient1);
   Pub.AddParam(L"PUBLICATIONID", PubID);
   Screen->Cursor = crHourGlass;
   ntm_pubs.clear();
   if (Pub.Execute()) {
	 if (Pub.Size() > 0) {
	   PubTypes.clear();
	   AdvColumnGrid1->RowCount = 2;
	   AdvColumnGrid1->Cells[1][1] = Pub.Items[0].PublicationID;
	   AdvColumnGrid1->Cells[2][1] = Pub.Items[0].Citation;
	   PubTypes[AdvColumnGrid1->Cells[1][1].ToInt()] = Pub.Items[0].PubTypeID;
	   ntm_pubs.push_back(Pub.Items[0]);
	   AdvColumnGrid1->AddCheckBoxColumn(0, false, false);
	   AdvColumnGrid1->SetCheckBoxState(0, 1, true);
	   }
	 }
   Screen->Cursor = crDefault;
}
//---------------------------------------------------------------------------

// gets value from the dropdown editor after dropping up
void __fastcall TFindPubForm::FormControlEditLink1GetEditorValue(TObject *Sender,
		  TAdvStringGrid *Grid, UnicodeString &AValue)
{
   AValue = Citation;
}
//---------------------------------------------------------------------------

// sets the value in the editor for the dropdown
void __fastcall TFindPubForm::FormControlEditLink1SetEditorValue(TObject *Sender,
		  TAdvStringGrid *Grid, UnicodeString AValue)
{
   Citation = AValue;
   AdvControlDropDown1->Text = AValue;
}
//---------------------------------------------------------------------------

// sets text in the memo control
void __fastcall TFindPubForm::AdvColumnGrid1GetEditorProp(TObject *Sender, int ACol,
		  int ARow, TEditLink *AEditLink)
{
   if (ACol == 2) {
	 cxMemo1->Text = AdvColumnGrid1->Cells[ACol][ARow];
	 if (AdvControlDropDown1->DropDownWidth == 0)
	   AdvControlDropDown1->DropDownWidth = AdvColumnGrid1->Columns->Items[2]->Width - 6;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TFindPubForm::AdvColumnGrid1CheckBoxClick(TObject *Sender, int ACol,
          int ARow, bool State)
{
   AdvColumnGrid1->Row =  ARow;
   if (State) {
	 for (int row=1; row<AdvColumnGrid1->RowCount; row++) {
	   if (row != ARow)
		 AdvColumnGrid1->SetCheckBoxState(0,row,false);
	   }
	 cxButton2->Enabled = true;
	 }
   else
     cxButton2->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TFindPubForm::AdvColumnGrid1MouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y)
{
   int ACol, ARow;
   AdvColumnGrid1->MouseToCell(X, Y, ACol, ARow);
   if (ACol == 2) {
	 if (AdvColumnGrid1->Options.Contains(goRowSelect))
	   AdvColumnGrid1->Options = AdvColumnGrid1->Options >> goRowSelect;
	 }
   else if (!AdvColumnGrid1->Options.Contains(goRowSelect))
	 AdvColumnGrid1->Options = AdvColumnGrid1->Options << goRowSelect;
}
//---------------------------------------------------------------------------

// Use button
void __fastcall TFindPubForm::cxButton2Click(TObject *Sender)
{
   bool state;
   PubID = -1;
   for (int row=1; row<AdvColumnGrid1->RowCount; row++) {
	 AdvColumnGrid1->GetCheckBoxState(0, row, state);
	 if (state) {
	   PubID = AdvColumnGrid1->Cells[1][row].ToInt();
	   ntm_pub = ntm_pubs[row-1];
	   break;
	   }
	 }
}
//---------------------------------------------------------------------------

void TFindPubForm::GetAuthors(void)
{
   bool state;

   PubID = -1;
   for (int row=1; row<AdvColumnGrid1->RowCount; row++) {
	 AdvColumnGrid1->GetCheckBoxState(0, row, state);
	 if (state) {
	   PubID = AdvColumnGrid1->Cells[1][row].ToInt();
	   ntm_pub = ntm_pubs[row-1];
	   break;
	   }
	 }

   if (PubID > -1) {
	 NeotomaPublicationAuthors GetAuthors(ipsJSONS1, TcpClient1);
	 GetAuthors.AddParam(L"PUBLICATIONID", PubID);
	 StatusBar1->SimpleText = GetAuthors.WebServiceName();
	 Screen->Cursor = crHourGlass;
	 Authors.clear();
	 if (GetAuthors.Execute()) {
	   if (GetAuthors.Size() > 0) {
		 for (unsigned int i=0; i<GetAuthors.Size(); i++) {
		   PUBAUTHOR Author;
		   Author.FamilyName = GetAuthors.Items[i].FamilyName;
		   Author.Initials = GetAuthors.Items[i].Initials;
		   Author.Suffix = GetAuthors.Items[i].Suffix;
		   Author.ContactID = GetAuthors.Items[i].ContactID;
		   Authors.push_back(Author);
		   }
		 }
	   }

	 // get contact metadata
	 if (Authors.size() > 0) {
	   // get contact statuses
	   map<int, UnicodeString> ContactStatus;
	   //NeotomaContactStatusesTable Statuses(ipsJSONS1, TcpClient1);
	   NeotomaContactStatusesTable Statuses(ipsJSONS1, TcpClient1);
	   StatusBar1->SimpleText = Statuses.WebServiceName();
	   if (Statuses.Execute()) {
		 if (Statuses.Size() > 0) {
		   for (unsigned int i=0; i<Statuses.Size(); i++)
			 ContactStatus[Statuses.Items[i].ContactStatusID] = Statuses.Items[i].ContactStatus;
		   }
		 }

	   for (unsigned int i=0; i<Authors.size(); i++) {
		 NeotomaContactByID GetContact(ipsJSONS1, TcpClient1);
		 GetContact.AddParam(L"CONTACTID", Authors[i].ContactID);
		 StatusBar1->SimpleText = GetContact.WebServiceName();
		 if (GetContact.Execute()) {
		   if (GetContact.Size() > 0) {
			 CONTACT Contact;
			 Contact.NeotomaContactID = GetContact.Items[0].ContactID;
			 Contact.NeotomaAliasID = GetContact.Items[0].AliasID;
			 int StatusID = GetContact.Items[0].ContactStatusID;
			 if (StatusID > -1) {
			   if (ContactStatus.find(StatusID) != ContactStatus.end())
				 Contact.Status = ContactStatus[StatusID];
			   }
			 Contact.FamilyName = GetContact.Items[0].FamilyName;
			 Contact.GivenNames = GetContact.Items[0].GivenNames;
			 Contact.LeadingInitials = GetContact.Items[0].LeadingInitials;
			 Contact.Suffix = GetContact.Items[0].Suffix;
			 Contact.Title = GetContact.Items[0].Title;
			 Contact.Telephone = GetContact.Items[0].Phone;
			 Contact.Fax = GetContact.Items[0].Fax;
			 Contact.Email = GetContact.Items[0].Email;
			 Contact.URL = GetContact.Items[0].URL;
			 Contact.Address = GetContact.Items[0].Address;
			 int idx;
			 while ((idx = Contact.Address.Pos(L"\\r\\n")) > 0) {
			   Contact.Address.Delete(idx, 4);
			   Contact.Address.Insert(L"\n", idx);
			   }
			 Contact.Notes = GetContact.Items[0].Notes;
			 Contact.FormatContactName();
			 Contacts.push_back(Contact);
			 }
		   }
		 }
	   }

	 // get editors
	 switch (PubTypes[PubID]) {
	   case BOOK_CHAPTER:
	   case BOOKCHAPTER:
		 NeotomaPublicationEditors GetEditors(ipsJSONS1, TcpClient1);
		 GetEditors.AddParam(L"PUBLICATIONID", PubID);
		 StatusBar1->SimpleText = GetEditors.WebServiceName();
		 Editors.clear();
		 if (GetEditors.Execute()) {
		   if (GetEditors.Size() > 0) {
			 for (unsigned int i=0; i<GetEditors.Size(); i++) {
			   EDITOR Editor;
			   Editor.LastName = GetEditors.Items[i].FamilyName;
			   Editor.Initials = GetEditors.Items[i].Initials;
			   Editor.Suffix = GetEditors.Items[i].Suffix;
			   Editors.push_back(Editor);
			   }
			 }
		   }
		 break;
	   }

	 // get translators
	 switch (PubTypes[PubID]) {
	   case BOOK_CHAPTER:
	   case AUTHORED_BOOK:
	   case EDITED_BOOK:
	   case BOOKCHAPTER:
	   case BOOK:
	   case EDITEDBOOK:
		 NeotomaPublicationTranslators GetTranslators(ipsJSONS1, TcpClient1);
		 GetTranslators.AddParam(L"PUBLICATIONID", PubID);
		 StatusBar1->SimpleText = GetTranslators.WebServiceName();
		 Translators.clear();
		 if (GetTranslators.Execute()) {
		   if (GetTranslators.Size() > 0) {
			 for (unsigned int i=0; i<GetTranslators.Size(); i++) {
			   EDITOR Translator;
			   Translator.LastName = GetTranslators.Items[i].FamilyName;
			   Translator.Initials = GetTranslators.Items[i].Initials;
			   Translator.Suffix = GetTranslators.Items[i].Suffix;
			   Translators.push_back(Translator);
			   }
			 }
		   }
		 break;
	   }

	 //local_pub->NeotomaID = PubID;
	 //local_pub->pub_type = ntm_pub.PubTypeID;
	 //local_pub->SetPublication(&ntm_pub, Authors, Editors, Translators);

	 StatusBar1->SimpleText = L"";
	 Screen->Cursor = crDefault;
	 }
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

// for use by non-stewards
__fastcall TGetPubForm::TGetPubForm(PUBLICATION *pub, TComponent* Owner) : TFindPubForm(NULL, Owner)
{
   cxButton1->Visible = false;
   local_pub = pub;
}
//---------------------------------------------------------------------------

// Use button
void __fastcall TGetPubForm::cxButton2Click(TObject *Sender)
{
   GetAuthors();
   local_pub->NeotomaID = PubID;
   local_pub->pub_type = ntm_pub.PubTypeID;
   local_pub->SetPublication(&ntm_pub, Authors, Editors, Translators);
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

__fastcall TMatchPubForm::TMatchPubForm(PUBLICATION *pub, set<int>& PubIDs, TComponent* Owner)
	: TFindPubForm(NULL, Owner)
{
   Caption = L"Match Neotoma Publication";
   cxButton1->Visible = false;
   cxButton2->Caption = L"Match";
   local_pub = pub;
   if (PubIDs.size() > 0) {
	 FlowPanel1->Visible = false;
	 cxMemo2->Left = 8;
	 cxMemo2->Top = 8;
	 cxMemo2->Width = Panel1->Width - 16;
	 cxMemo2->Height = Panel1->Height - 16;
	 cxMemo2->Visible = true;
	 SetPubs(pub, PubIDs);
	 }
}
//---------------------------------------------------------------------------

void TMatchPubForm::SetPubs(PUBLICATION *pub, set<int>& PubIDs)
{
   set<int>::iterator itr;
   unsigned int nAuth = pub->AuthorList.size();
   UnicodeString msg = L"Neotoma has the following publication";
   if (PubIDs.size() > 1)
	 msg += L"s";
   msg += L" with author";
   if (nAuth > 1)
	 msg += L"s";
   msg += (L" " + pub->AuthorList[0].LastName);
   for (unsigned int i=1; i<nAuth; i++) {
	 if (i == nAuth-1) {
	   if (i > 1)
		 msg += L",";
	   msg += L" and ";
	   }
	 else
	   msg += L", ";
	 msg += pub->AuthorList[i].LastName;
	 if (i == 4 && nAuth > 5) {
	   msg += L", et al.";
	   break;
	   }
	 }
   msg += (L" published in " + pub->PublicationYear + L". ");
   if (PubIDs.size() == 1)
	 msg += L"If this publication matches ";
   else
	 msg += L"If any of these match ";
   msg += L"your publication, check it, and click the Match button.";
   cxMemo2->Text = msg;

   Screen->Cursor = crHourGlass;
   ntm_pubs.clear();
   int Row = 1;
   for (itr = PubIDs.begin(); itr != PubIDs.end(); itr++) {
	 NeotomaPublicationsByPubID Pub(ipsJSONS1, TcpClient1);
	 Pub.AddParam(L"PUBLICATIONID", *itr);
	 if (Pub.Execute()) {
	   if (Pub.Size() > 0) {
		 AdvColumnGrid1->Cells[1][Row] = Pub.Items[0].PublicationID;
		 AdvColumnGrid1->Cells[2][Row] = Pub.Items[0].Citation;
		 PubTypes[AdvColumnGrid1->Cells[1][1].ToInt()] = Pub.Items[0].PubTypeID;
		 ntm_pubs.push_back(Pub.Items[0]);
		 //AdvColumnGrid1->AddCheckBoxColumn(0, false, false);
		 //AdvColumnGrid1->SetCheckBoxState(0, 1, true);
		 Row++;
		 }
	   }
	 }

   AdvColumnGrid1->RowCount = Row;
   Screen->Cursor = crDefault;
}
//---------------------------------------------------------------------------

// Match button
void __fastcall TMatchPubForm::cxButton2Click(TObject *Sender)
{
   bool state;
   PubID = -1;
   for (int row=1; row<AdvColumnGrid1->RowCount; row++) {
	 AdvColumnGrid1->GetCheckBoxState(0, row, state);
	 if (state) {
	   PubID = AdvColumnGrid1->Cells[1][row].ToInt();
	   ntm_pub = ntm_pubs[row-1];
	   break;
	   }
	 }

   int rv = mrOk;
   if (!MatchPub()) {
	 UnicodeString msg = L"Match with Neotoma PublicationID " + IntToStr(PubID) +
		 L"; however, the following differences exist in bibliographic data:\n\n";
	 for (unsigned int i=0; i<Differences.size(); i++)
	   msg += (L"  " + Differences[i] + L"\n");
	 msg += L"\nDo you want to update reference with details from Neotoma?";
	 int ntm_PubTypeID = ntm_pub.PubTypeID;
	 if (ntm_PubTypeID == LEGACY)
	   msg += L"\n\nNOTE: The Neotoma publication is a legacy entry, which has not been parsed into bibliogrphic fields.";
	 rv = MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo << mbCancel, 0);
	 if (rv == mrYes)  {     // replace with Neotoma reference
	   local_pub->SetPublication(&ntm_pub, Authors, Editors, Translators);
	   for (unsigned int i=0; i<Authors.size(); i++)
		 local_pub->AuthorList[i].NeotomaContactID = Authors[i].ContactID;
	   ModalResult = mrYes;
	   }
	 if (rv == mrCancel)   // add PubID
	   ModalResult = mrCancel;
	 }
   if (rv != mrCancel)   // add PubID
	 local_pub->NeotomaID = PubID;
}
//---------------------------------------------------------------------------

bool TMatchPubForm::MatchPub(void)
{
   UnicodeString Value;
   bool SameNames, BlankNames;
   bool rv = true;

   GetAuthors();

   if (!CompPubFields(local_pub->pub_type, ntm_pub.PubTypeID, L"Publication Type", true))
	 rv = false;

   if (local_pub->AuthorList.size() > 0 || Authors.size() > 0) {
	 if (local_pub->AuthorList.size() != Authors.size()) {
	   Differences.push_back(L"Number of authors differs");
	   rv = false;
	   }
	 else {
	   SameNames = true;
	   for (unsigned int i=0; i<Authors.size(); i++) {
		 if (local_pub->AuthorList[i].LastName != Authors[i].FamilyName) {
		   if (ntm_pub.PubTypeID == LEGACY && Authors[i].FamilyName.IsEmpty())
			 Differences.push_back(L"Author name(s) for Neotoma legacy entry have not been parsed");
		   else
			 Differences.push_back(L"Author family names differ or are in different order");
		   SameNames = false;
		   rv = false;
		   break;
		   }
		 }
	   if (SameNames) {
		 for (unsigned int i=0; i<Authors.size(); i++) {
		   if (local_pub->AuthorList[i].Initials != Authors[i].Initials) {
			 Differences.push_back(L"Author initials differ");
			 SameNames = false;
			 rv = false;
			 break;
			 }
		   }
		 }
	   if (SameNames) {
		 for (unsigned int i=0; i<Authors.size(); i++) {
		   if (local_pub->AuthorList[i].Suffix != Authors[i].Suffix) {
			 Differences.push_back(L"Author suffixes differ");
			 SameNames = false;
			 rv = false;
			 break;
			 }
		   }
		 }
	   if (SameNames) {
		 for (unsigned int i=0; i<Authors.size(); i++)
		   local_pub->AuthorList[i].NeotomaContactID = Authors[i].ContactID;
		 }
	   }
	 }

   if (local_pub->EditorList.size() > 0 || Editors.size() > 0) {
	 if (local_pub->EditorList.size() != Editors.size()) {
	   Differences.push_back(L"Number of Editors differs");
	   rv = false;
	   }
	 else {
	   SameNames = true;
	   for (unsigned int i=0; i<Editors.size(); i++) {
		 if (local_pub->EditorList[i].LastName != Editors[i].LastName) {
		   Differences.push_back(L"Editor family names differ or are in different order");
		   SameNames = false;
		   rv = false;
		   break;
		   }
		 }
	   if (SameNames) {
		 for (unsigned int i=0; i<Editors.size(); i++) {
		   if (local_pub->EditorList[i].Initials != Editors[i].Initials) {
			 Differences.push_back(L"Editor initials differ");
			 SameNames = false;
			 rv = false;
			 break;
			 }
		   }
		 }
	   if (SameNames) {
		 for (unsigned int i=0; i<Editors.size(); i++) {
		   if (local_pub->EditorList[i].Suffix != Editors[i].Suffix) {
			 Differences.push_back(L"Editor suffixes differ");
			 rv = false;
			 break;
			 }
		   }
		 }
	   }
	 }

   if (local_pub->TranslatorList.size() > 0 || Translators.size() > 0) {
	 if (local_pub->TranslatorList.size() != Translators.size()) {
	   Differences.push_back(L"Number of Translators differs");
	   rv = false;
	   }
	 else {
	   SameNames = true;
	   for (unsigned int i=0; i<Translators.size(); i++) {
		 if (local_pub->TranslatorList[i].LastName != Translators[i].LastName) {
		   Differences.push_back(L"Translator family names differ or are in different order");
		   SameNames = false;
		   rv = false;
		   break;
		   }
		 }
	   if (SameNames) {
		 for (unsigned int i=0; i<Translators.size(); i++) {
		   if (local_pub->TranslatorList[i].Initials != Translators[i].Initials) {
			 Differences.push_back(L"Translator initials differ");
			 SameNames = false;
			 rv = false;
			 break;
			 }
		   }
		 }
	   if (SameNames) {
		 for (unsigned int i=0; i<Translators.size(); i++) {
		   if (local_pub->TranslatorList[i].Suffix != Translators[i].Suffix) {
			 Differences.push_back(L"Translator suffixes differ");
			 rv = false;
			 break;
			 }
		   }
		 }
	   }
	 }

   if (!CompPubFields(local_pub->Title, ntm_pub.ArticleTitle, L"Titles", true))
	 rv = false;
   if (!CompPubFields(local_pub->Journal, ntm_pub.Journal, L"Journal", true))
	 rv = false;
   if (!CompPubFields(local_pub->Volume, ntm_pub.Volume, L"Volume number", false))
	 rv = false;
   if (!CompPubFields(local_pub->Issue, ntm_pub.Issue, L"Issue number", false))
	 rv = false;
   if (!CompPubFields(local_pub->Pages, ntm_pub.Pages, L"Pages", false))
	 rv = false;
   if (!CompPubFields(local_pub->CitationNumber, ntm_pub.CitationNumber, L"Citation Number", true))
	 rv = false;
   if (!CompPubFields(local_pub->DOI, ntm_pub.DOI, L"Digital Object Identifier", true))
	 rv = false;
   if (!CompPubFields(local_pub->BookTitle, ntm_pub.BookTitle , L"Book Title", true))
	 rv = false;
   if (!CompPubFields(local_pub->Edition, ntm_pub.Edition, L"Edition", true))
	 rv = false;
   if (!CompPubFields(local_pub->NumVolumes, ntm_pub.NumVolumes, L"Number of Volumes", false))
	 rv = false;
   if (!CompPubFields(local_pub->VolumeTitle, ntm_pub.VolumeTitle, L"Volume Title", true))
	 rv = false;
   if (!CompPubFields(local_pub->SeriesTitle, ntm_pub.SeriesTitle, L"Series Title", true))
	 rv = false;
   if (!CompPubFields(local_pub->SeriesNumber, ntm_pub.SeriesVolume, L"Series Volume Number", false))
	 rv = false;
   switch (ntm_pub.PubTypeID) {
	 case MASTERS_THESIS:
	 case DOCTORAL_THESIS:
	 case UNDERGRAD_THESIS:
	 case THESIS:
	   if (!CompPubFields(local_pub->University, ntm_pub.Publisher, L"University", true))
		 rv = false;
	   break;
	 default:
	   if (!CompPubFields(local_pub->Publisher, ntm_pub.Publisher, L"Publisher", true))
		 rv = false;
	   break;
	 }
   if (!CompPubFields(local_pub->City, ntm_pub.City, L"City", true))
	 rv = false;
   if (!CompPubFields(local_pub->State, ntm_pub.State, L"State", true))
	 rv = false;
   if (!CompPubFields(local_pub->Country, ntm_pub.Country, L"Country", true))
	 rv = false;
   if (!CompPubFields(local_pub->URL, ntm_pub.URL, L"URL", true))
	 rv = false;
   if (!CompPubFields(local_pub->OrigLang, ntm_pub.OriginalLanguage, L"Original Language", true))
	 rv = false;
   if (!CompPubFields(local_pub->Notes, ntm_pub.Notes, L"Notes", true))
	 rv = false;
   return rv;
}
//---------------------------------------------------------------------------

//bool TMatchPubForm::CompPubFields(UnicodeString LocalPubField, Variant vNtmPubField,
//	UnicodeString Field, bool CheckCaps)
bool TMatchPubForm::CompPubFields(UnicodeString LocalPubField, UnicodeString vNtmPubField,
	UnicodeString Field, bool CheckCaps)
{
   bool rv = true;
   if (!LocalPubField.IsEmpty() && !vNtmPubField.IsEmpty()) {
	 UnicodeString NtmPubField = vNtmPubField;
	 if (LocalPubField != NtmPubField) {
	   if (CheckCaps && SameText(LocalPubField, NtmPubField))
		 Differences.push_back(Field + L" are the same, but capitalization differs");
	   else {
		 if (*Field.LastChar() == L's')
		   Field += L" differ";
		 else
		   Field += L" differs";
		 Differences.push_back(Field);
		 }
	   rv = false;
	   }
	 }
   else if (!LocalPubField.IsEmpty() || !vNtmPubField.IsEmpty()) {
	 if (*Field.LastChar() == L's')
	   Field += L" differ";
	 else
	   Field += L" differs";
	 Differences.push_back(Field);
	 rv = false;
	 }
   return rv;
}
//---------------------------------------------------------------------------

// add new publication
void __fastcall TFindPubForm::cxButton1Click(TObject *Sender)
{
   PUBLICATION *pub = new PUBLICATION(JOURNAL_ARTICLE);
   TStewardPubForm *PubForm = new TStewardPubForm(pub, NEWPUB, ContactList, this);
   PubForm->ShowModal();
   delete pub;
   delete PubForm;
}
//---------------------------------------------------------------------------

void __fastcall TFindPubForm::ipsJSONS1SSLServerAuthentication(TObject *Sender,
	TipsJSONSSSLServerAuthenticationEventParams *e)
{
   e->Accept = true;
}
//---------------------------------------------------------------------------

