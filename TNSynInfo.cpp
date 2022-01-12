//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "TNSynInfo.h"
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
#pragma link "cxMemo"
#pragma link "cxTextEdit"
#pragma link "cxGroupBox"
#pragma link "dxGDIPlusClasses"
#pragma link "ipwjson"
#pragma link "cxLabel"
#pragma link "cxListView"
#pragma link "cxListBox"
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
TSynonymInfoForm *SynonymInfoForm;
//---------------------------------------------------------------------------
__fastcall TSynonymInfoForm::TSynonymInfoForm(vector<SYNONYMROW>::pointer srptr, TComponent* Owner)
	: TForm(Owner)
{
   synrow_ptr = srptr;
   SavedSynonymName = synrow_ptr->SynonymName;
   activated = false;
   local = false;
}
//---------------------------------------------------------------------------

void __fastcall TSynonymInfoForm::FormActivate(TObject *Sender)
{
   if (!activated)
	 ShowInfo();
}
//---------------------------------------------------------------------------

void TSynonymInfoForm::ShowInfo(void)
{
   cxTextEdit3->Text = synrow_ptr->SynonymName;

   // local lookup file, need to get synonym info from Neotoma
   bool found;
   if (synrow_ptr->SynRec.TaxonName.IsEmpty()) {
	 if (!GetValidName(synrow_ptr->SynonymName, found))
	   return;

	 if (!found) {
	   cxGroupBox1->Enabled = false;
	   cxGroupBox2->Visible = true;
	   return;
	   }
	 local = true;
	 }

   Screen->Cursor = crHourGlass;
   cxTextEdit4->Text = VarToStr(synrow_ptr->SynRec.Author);
   cxTextEdit5->Text = VarToStr(synrow_ptr->TaxaRec.TaxonName);
   cxTextEdit6->Text = VarToStr(synrow_ptr->TaxaRec.Author);
   cxMemo2->Text = VarToStr(synrow_ptr->SynRec.Notes);
   cxMemo3->Text = VarToStr(synrow_ptr->TaxaRec.Notes);
   cxTextEdit2->Text = VarToStr(synrow_ptr->SynRec.ValidateDate);

   int PubID = VariantToInt(synrow_ptr->SynRec.PublicationID, -1);
   if (PubID != -1) {
	 NeotomaPublicationsByPubID Pub(ipsJSONS1, TcpClient1);
	 StatusBar1->SimpleText = Pub.WebServiceName();
	 Pub.AddParam(L"PUBLICATIONID", PubID);
	 if (Pub.Execute()) {
	   if (Pub.Size() > 0)
		 cxMemo1->Text = Pub.Items[0].Citation;
	   }
	 }

   int ContactID = VariantToInt(synrow_ptr->SynRec.ValidatorID, -1);
   if (ContactID != -1) {
	 NeotomaContactByID Validator(ipsJSONS1, TcpClient1);
	 Validator.AddParam(L"CONTACTID", ContactID);
	 StatusBar1->SimpleText = Validator.WebServiceName();
	 if (Validator.Execute()) {
	   if (Validator.Size() > 0) {
		 UnicodeString FamilyName = Validator.Items[0].FamilyName;
		 UnicodeString GivenNames = Validator.Items[0].GivenNames;
		 UnicodeString Initials = Validator.Items[0].LeadingInitials;
		 UnicodeString Suffix = Validator.Items[0].Suffix;
		 UnicodeString Name;
		 if (!GivenNames.IsEmpty())
		   Name = GivenNames;
		 else if (!GivenNames.IsEmpty())
		   Name = Initials;
		 if (!Name.IsEmpty())
		   Name += L" ";
		 Name += FamilyName;
		 if (!Suffix.IsEmpty())
		   Name += (L" " + Suffix);
		 cxTextEdit1->Text = Name;
		 }
	   }
	 }

   StatusBar1->SimpleText = L"";
   Screen->Cursor = crDefault;
   activated = true;
}
//---------------------------------------------------------------------------

bool TSynonymInfoForm::GetValidName(UnicodeString InvalidName, bool& found)
{
   bool rv = true;
   found = false;
   Screen->Cursor = crHourGlass;
   InvalidTaxonByName InvalidTaxon(ipsJSONS1, TcpClient1);
   StatusBar1->SimpleText = InvalidTaxon.WebServiceName();
   InvalidTaxon.AddParam(L"TAXONNAME", InvalidName);
   if (InvalidTaxon.Execute()) {
	 if (InvalidTaxon.Size() > 0) {
	   synrow_ptr->SynRec = InvalidTaxon.Items[0];
	   found = true;
	   }
	 }
   else
	 rv = false;

   if (!rv || !found) {
	 StatusBar1->SimpleText = L"";
	 Screen->Cursor = crDefault;
	 return rv;
	 }

   int ValidTaxonID = -1;
   int InvalidTaxonID = VariantToInt(synrow_ptr->SynRec.TaxonID, -1);
   NeotomaSynonym GetInvalidName(ipsJSONS1, TcpClient1);
   GetInvalidName.AddParam(L"INVALIDTAXONID", InvalidTaxonID);
   StatusBar1->SimpleText = GetInvalidName.WebServiceName();
   if (GetInvalidName.Execute()) {
	 if (GetInvalidName.Size() == 1)
	   ValidTaxonID = GetInvalidName.Items[0].ValidTaxonID;
	 }
   else
	 rv = false;

   if (ValidTaxonID > -1) {
	 NeotomaTaxonByID ValidTaxon(ipsJSONS1, TcpClient1);
	 StatusBar1->SimpleText = ValidTaxon.WebServiceName();
	 ValidTaxon.AddParam(L"TAXONID", ValidTaxonID);
	 if (ValidTaxon.Execute()) {
	   if (ValidTaxon.Size() > 0)
		 synrow_ptr->TaxaRec = ValidTaxon.Items[0];     // here
	   }
	 else
	   rv = false;
	 }

   StatusBar1->SimpleText = L"";
   Screen->Cursor = crDefault;
   return rv;
}
//---------------------------------------------------------------------------

void __fastcall TSynonymInfoForm::cxTextEdit7PropertiesChange(TObject *Sender)
{
   cxButton2->Enabled = !cxTextEdit7->Text.IsEmpty();
}
//---------------------------------------------------------------------------

void __fastcall TSynonymInfoForm::cxButton4Click(TObject *Sender)
{
   cxGroupBox2->Visible = false;
   cxGroupBox1->Enabled = true;
}
//---------------------------------------------------------------------------

// synonym search
void __fastcall TSynonymInfoForm::cxButton2Click(TObject *Sender)
{
   SynonymSearch();
}
//---------------------------------------------------------------------------

void __fastcall TSynonymInfoForm::cxTextEdit7KeyPress(TObject *Sender, wchar_t &Key)
{
   if (Key == VK_RETURN)
	 SynonymSearch();
}
//---------------------------------------------------------------------------

void TSynonymInfoForm::SynonymSearch(void)
{
   Screen->Cursor = crHourGlass;
   InvalidTaxonByName InvalidTaxon(ipsJSONS1, TcpClient1);
   StatusBar1->SimpleText = InvalidTaxon.WebServiceName();
   InvalidTaxon.AddParam(L"TAXONNAME", cxTextEdit7->Text);
   if (InvalidTaxon.Execute()) {
	 if (InvalidTaxon.Size() > 0) {
	   cxLabel11->Caption = L"Select a name:";
	   for (unsigned int i=0; i < InvalidTaxon.Size(); i++) {
		 UnicodeString TaxonName = VarToStr(InvalidTaxon.Items[i].TaxonName);
		 cxListBox1->Items->Add(TaxonName);
		 }
	   cxListBox1->ItemIndex = 0;
	   FocusControl(cxListBox1);
	   cxButton3->Enabled = true;
	   }
	 else {
       cxLabel11->Caption = L"No synonyms found!";
	   cxButton3->Enabled = false;
	   }
	 }
   StatusBar1->SimpleText = L"";
   Screen->Cursor = crHourGlass;
}
//---------------------------------------------------------------------------

// show details
void __fastcall TSynonymInfoForm::cxButton3Click(TObject *Sender)
{
   synrow_ptr->SynonymName = cxListBox1->Items->Strings[cxListBox1->ItemIndex];
   cxGroupBox2->Visible = false;
   cxGroupBox1->Enabled = true;
   ShowInfo();
}
//---------------------------------------------------------------------------

// close
void __fastcall TSynonymInfoForm::FormClose(TObject *Sender, TCloseAction &Action)
{
   if (local) {
	 synrow_ptr->SynonymName = SavedSynonymName;
	 TAXONRECORD* SynRec = new TAXONRECORD;
	 TAXONRECORD* TaxaRec = new TAXONRECORD;
	 synrow_ptr->SynRec = *SynRec;
	 synrow_ptr->TaxaRec = *TaxaRec;
	 delete SynRec;
	 delete TaxaRec;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TSynonymInfoForm::ipsJSONS1SSLServerAuthentication(TObject *Sender,
          TipsJSONSSSLServerAuthenticationEventParams *e)
{
   e->Accept = true;
}
//---------------------------------------------------------------------------

