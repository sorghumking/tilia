//---------------------------------------------------------------------------

#include <vcl.h>
#include "pch.h"
#pragma hdrstop

#include "TNFindTaxon.h"
#ifndef TINeotomaH
#include "TINeotoma.h"
#endif
#ifndef TINewTxnH
#include "TINewTxn.h"
#endif
#ifndef TNConfTaxNamChngH
#include "TNConfTaxNamChng.h"
#endif
#ifndef TNLoginH
#include "TNLogin.h"
#endif

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "ipwjson"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxTextEdit"
#pragma link "cxLabel"
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
//---------------------------------------------------------------------------
TFindTaxonForm *FindTaxonForm;
//TNeotomaFindTaxonForm *NeotomaFindTaxonForm;
//---------------------------------------------------------------------------
__fastcall TFindTaxonForm::TFindTaxonForm(vector<SSTAXANAME>* tnf,
	TTilSpreadSheetForm *tssform, TComponent* Owner) : TForm(Owner)
{
   // This class can be used for searching either the local taxa lookup file
   // or the Neotoma taxa table
   TSSForm = tssform;
   taxa_not_found = tnf;

   UnicodeString ClassName = Owner->ClassName();

   if (SameText(ClassName, L"TCheckVarForm")) {
	 TCheckVarForm *CheckVarForm = (TCheckVarForm*)Owner;
	 SubVarCodes = CheckVarForm->SubVarCodes;
	 SubGroups = CheckVarForm->SubGroups;
	 SubElements = CheckVarForm->SubElements;
	 SubUnits = CheckVarForm->SubUnits;
	 UnitsValue = CheckVarForm->UnitsValue;
	 }

   for (unsigned int i=0; i<taxa_not_found->size(); i++) {
	 UnicodeString TaxonName = taxa_not_found->at(i).Name;
	 if (ListBox1->Items->IndexOf(TaxonName) == -1)
	   ListBox1->Items->Add(TaxonName);
	 }
   if (ListBox1->Count > 0) {
	 ListBox1->ItemIndex = 0;
	 //cxButton1->Enabled = true;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TFindTaxonForm::FormDestroy(TObject *Sender)
{
   return;
}
//---------------------------------------------------------------------------

void __fastcall TFindTaxonForm::cxTextEdit1PropertiesChange(TObject *Sender)
{
   cxButton1->Enabled = !cxTextEdit1->Text.IsEmpty();
}
//---------------------------------------------------------------------------

// search button
void __fastcall TFindTaxonForm::cxButton1Click(TObject *Sender)
{
   Search();
}
//---------------------------------------------------------------------------

void __fastcall TFindTaxonForm::cxTextEdit1KeyPress(TObject *Sender, wchar_t &Key)
{
   if (Key == VK_RETURN)
	 Search();
}
//---------------------------------------------------------------------------

bool TFindTaxonForm::Search(void)
{
   ListBox2->Clear();
   bool PartialStrBeg = false;
   bool PartialStrEnd = false;
   UnicodeString SearchStr = cxTextEdit1->Text;
   if (SearchStr.SubString(1,1) == L"%") {
	 SearchStr.Delete(1,1);
	 PartialStrEnd = true;
	 }
   if (*SearchStr.LastChar() == L'%') {
	 SearchStr.Delete(SearchStr.Length(), 1);
	 PartialStrBeg = true;
	 }

   if (PartialStrBeg && PartialStrEnd) {
	 //for (int i=0; i<TaxaList->Count; i++) {
	 //  TAXON* Taxon = TaxaList->Taxa[i];
	 //  if (ContainsText(Taxon->Name, SearchStr))
	 //	 ListBox2->Items->AddObject(Taxon->Name, (TObject*)Taxon);
	 //  }
	 for (unsigned int i=0; i<TaxaList->size(); i++) {
	   vector<TAXON>::pointer Taxon = &TaxaList->at(i);
	   if (ContainsText(Taxon->Name, SearchStr))
		 ListBox2->Items->AddObject(Taxon->Name, (TObject*)Taxon);
	   }
	 }
   else if (PartialStrBeg) {
	 int sLen = SearchStr.Length();
	 //for (int i=0; i<TaxaList->Count; i++) [
	 for (unsigned int i=0; i<TaxaList->size(); i++) {
	   //TAXON* Taxon = TaxaList->Taxa[i];
	   vector<TAXON>::pointer Taxon = &TaxaList->at(i);
	   if (Taxon->Name.Length() >= sLen) {
		 if (SameText(Taxon->Name.SubString(1,sLen), SearchStr))
		   ListBox2->Items->AddObject(Taxon->Name, (TObject*)Taxon);
		 }
	   }
	 }
   else if (PartialStrEnd) {
	 int sLen = SearchStr.Length();
	 //for (int i=0; i<TaxaList->Count; i++) [
	 for (unsigned int i=0; i<TaxaList->size(); i++) {
	   //TAXON* Taxon = TaxaList->Taxa[i];
	   vector<TAXON>::pointer Taxon = &TaxaList->at(i);
	   int tLen = Taxon->Name.Length();
	   if (tLen >= sLen) {
		 if (SameText(Taxon->Name.SubString(tLen-sLen+1,sLen), SearchStr))
		   ListBox2->Items->AddObject(Taxon->Name, (TObject*)Taxon);
		 }
	   }
	 }
   else {
	 //for (int i=0; i<TaxaList->Count; i++) [
	 for (unsigned int i=0; i<TaxaList->size(); i++) {
	   //TAXON* Taxon = TaxaList->Taxa[i];
	   vector<TAXON>::pointer Taxon = &TaxaList->at(i);
	   if (SameText(Taxon->Name, SearchStr)) {
		 ListBox2->Items->AddObject(Taxon->Name, (TObject*)Taxon);
		 break;
		 }
	   }
	 }

   if (ListBox2->Count == 0)
	 StatusBar1->SimpleText = L"No taxa found";
   return true;
}
//---------------------------------------------------------------------------

// replace button
void __fastcall TFindTaxonForm::cxButton2Click(TObject *Sender)
{
   ReplaceTaxonName();
}
//---------------------------------------------------------------------------

// upload to Neotoma button
void __fastcall TFindTaxonForm::cxButton3Click(TObject *Sender)
{
   return;
}
//---------------------------------------------------------------------------v

bool TFindTaxonForm::ReplaceTaxonName(void)
{
  bool rv = false;

  if (ListBox2->ItemIndex > -1) {
	 TAXON *Taxon = (TAXON*)ListBox2->Items->Objects[ListBox2->ItemIndex];
	 OldName = ListBox1->Items->Strings[ListBox1->ItemIndex];
	 ConfirmReplaceTaxonForm = new TConfirmReplaceTaxonForm(OldName, Taxon->Name, this);
	 //UnicodeString msg = L"Replace «" + OldName + L"» with «" + Taxon->Name + L"»?";
	 //if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes)
	 if (ConfirmReplaceTaxonForm->ShowModal() == mrOk) {
	   //SSRow = taxa_not_found->at(ListBox1->ItemIndex).Row;
	   int idx;
	   for (unsigned int i=0; i<taxa_not_found->size(); i++) {
		 if (SameText(OldName, taxa_not_found->at(i).Name)) {
		   SSRow = taxa_not_found->at(i).Row;
		   idx = i;
		   break;
		   }
		 }
	   NewName = Taxon->Name;
	   TSSForm->ProfGrid1->AbsoluteCells[2][SSRow]->Value = NewName;
	   TSSForm->ReplaceVarCodes(Taxon, SSRow, SubVarCodes);
	   TSSForm->ReplaceGroupCodes(Taxon, SSRow, SubGroups);
	   TSSForm->ReplaceElements(Taxon, SSRow, SubElements);
	   TSSForm->ReplaceUnits(Taxon, SSRow, SubUnits, UnitsValue);
	   TSSForm->SpreadSheetChanged = true;
	   cxButton2->Visible = false;
	   ListBox2->Clear();

	   //TODO: deal with original ID

	   // delete resolved taxon from both TaxaNotFound and ListBox1
	   int ItemIndex1 = ListBox1->ItemIndex;
	   ListBox1->Items->Delete(ItemIndex1);
	   vector<SSTAXANAME>::iterator itr = taxa_not_found->begin() + idx;
	   taxa_not_found->erase(itr);

	   if (ListBox1->Count > 0)
		 ListBox1->ItemIndex = 0;
	   else {
		 cxTextEdit1->Enabled = false;
		 cxButton1->Enabled = false;
		 ListBox2->Enabled = false;
		 ListBox2->Color = clBtnFace;
		 }

	   if (taxa_not_found->size() == 0) {
		 MessageDlg(L"All taxa names resolved!", mtInformation, TMsgDlgButtons() << mbOK, 0);
		 ModalResult = mrOk;
		 }
	   rv = true;
	   }
	 delete ConfirmReplaceTaxonForm;
	 }
   return rv;
}
//---------------------------------------------------------------------------

void __fastcall TFindTaxonForm::ListBox1Click(TObject *Sender)
{
   return;
}
//---------------------------------------------------------------------------

void __fastcall TFindTaxonForm::ListBox2Click(TObject *Sender)
{
   if (ListBox2->ItemIndex > -1)
	 cxButton2->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TFindTaxonForm::cxButton4Click(TObject *Sender)
{
   UnicodeString msg;
   if (taxa_not_found->size() == 1)
	 msg = L"Taxon name not resolved.";
   else
	 msg = IntToStr((int)taxa_not_found->size()) + L" taxa names not resolved.";
   int rv = MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK << mbRetry, 0);
   switch (rv) {
	 case mrOk:
	   ModalResult = mrClose;
	   break;
	 default:
	   ModalResult = mrNone;
	   break;
	 }
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

__fastcall TNeotomaFindTaxonForm::TNeotomaFindTaxonForm(vector<SSTAXANAME>* tnf,
	void (__closure *output_line)(UnicodeString), TTilSpreadSheetForm *tssform, TComponent* Owner)
	: TFindTaxonForm(tnf, tssform, Owner)
{
   OutputLine = output_line;
   SubVarCodes = SUBALL;
   SubGroups = SUBNONE;
   SubElements = SUBNONE;
   SubUnits = SUBNONE;
   UnitsValue = L"";
   TaxonPtrs = new TList;
   if (tiLicense->Type() == verNEOTOMASTEWARD)
	 cxButton3->Visible = true;
   NewTaxonForm = NULL;
   NewSynonyms = false;
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaFindTaxonForm::FormDestroy(TObject *Sender)
{
   ClearTaxonPtrs();
   delete TaxonPtrs;
   if (NewTaxonForm != NULL)
	 delete NewTaxonForm;
}
//---------------------------------------------------------------------------

// search button
void __fastcall TNeotomaFindTaxonForm::cxButton1Click(TObject *Sender)
{
   Search();
}
//---------------------------------------------------------------------------

// replace button
void __fastcall TNeotomaFindTaxonForm::cxButton2Click(TObject *Sender)
{
   if (ReplaceTaxonName())
	 OutputLine(L"Taxon «" + OldName + L"» in row " +
	   IntToStr(SSRow) + " replaced with «" + NewName + L"».");
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaFindTaxonForm::cxTextEdit1KeyPress(TObject *Sender, wchar_t &Key)
{
   if (Key == VK_RETURN)
	 Search();
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaFindTaxonForm::ListBox1Click(TObject *Sender)
{
   cxButton3->Enabled = true;
}
//---------------------------------------------------------------------------

bool TNeotomaFindTaxonForm::Search(void)
{
   bool rv = true;
   ListBox2->Clear();
   UnicodeString SearchStr = cxTextEdit1->Text;
   Screen->Cursor = crHourGlass;
   ClearTaxonPtrs();
   ValidTaxonByName Taxa(ipsJSONS1, TcpClient1);
   Taxa.AddParam(L"TAXONNAME", SearchStr);
   StatusBar1->SimpleText = Taxa.WebServiceName();
   if (Taxa.Execute()) {
	 if (Taxa.Size() > 0) {
	   for (unsigned int i=0; i<Taxa.Size(); i++) {
		 TAXON *Taxon =  new TAXON();
		 Taxon->ID = Taxa.Items[i].TaxonID;
		 Taxon->Name = Taxa.Items[i].TaxonName;
		 Taxon->Code = Taxa.Items[i].TaxonCode;
		 TaxonPtrs->Add(Taxon);
		 ListBox2->Items->AddObject(Taxon->Name, (TObject*)Taxon);
		 }
	   }
	 else {
	   StatusBar1->SimpleText = L"No taxa found";
	   }
	 }
   else
	 rv = false;

   Screen->Cursor = crDefault;
   return rv;
}
//---------------------------------------------------------------------------

void TNeotomaFindTaxonForm::ClearTaxonPtrs(void)
{
   if (TaxonPtrs->Count > 0) {
	 for (int i=0; i<TaxonPtrs->Count; i++) {
	   TAXON* Taxon = (TAXON*)TaxonPtrs->Items[i];
	   delete Taxon;
	   TaxonPtrs->Items[i] = 0;
	   }
	 TaxonPtrs->Clear();
	 }
}
//---------------------------------------------------------------------------

// upload to Neotoma button
void __fastcall TNeotomaFindTaxonForm::cxButton3Click(TObject *Sender)
{
   if (!Login->IsLoggedIn) {
	 NeotomaLoginForm = new TNeotomaLoginForm(this);
	 NeotomaLoginForm->ShowModal();
	 delete NeotomaLoginForm;
	 }
   if (!Login->IsLoggedIn) return;

   if (NewTaxonForm == NULL)
	 NewTaxonForm = new TNewTaxonForm(this);

   UnicodeString Name = ListBox1->Items->Strings[ListBox1->ItemIndex];
   //int row = taxa_not_found->at(ListBox1->ItemIndex).Row;
   int row = 0;
   UnicodeString Author;
   for (unsigned int i=0; i<taxa_not_found->size(); i++) {
	 if (SameText(Name, taxa_not_found->at(i).Name)) {
	   row = taxa_not_found->at(i).Row;
	   Author = taxa_not_found->at(i).Author;
	   break;
	   }
	 }

   UnicodeString Code = TSSForm->ProfGrid1->AbsoluteCells[1][row]->Text;
   NewTaxonForm->AddNewTaxon(Name, Code, Author);
   NewTaxonForm->ShowModal();

   if (NewTaxonForm->TaxaUploaded.size() > 0) {
	 for (unsigned int i=0; i<NewTaxonForm->TaxaUploaded.size(); i++) {
	   UnicodeString msg = L"Taxon «" + NewTaxonForm->TaxaUploaded[i].Name +
		   L"» uploaded to Neotoma: ID = " + IntToStr(NewTaxonForm->TaxaUploaded[i].ID);
	   msg += (NewTaxonForm->TaxaUploaded[i].IsSynonym) ? L", Valid = false" : L", Valid = true";
	   OutputLine(msg);
	   if (!NewTaxonForm->TaxaUploaded[i].IsSynonym) {
		 if (SameText(Name, NewTaxonForm->TaxaUploaded[i].Name)) {
		   int ItemIndex = ListBox1->ItemIndex;
		   ListBox1->Items->Delete(ItemIndex);
		   switch (ListBox1->Items->Count) {
			 case 0:
			   ListBox1->ItemIndex = -1;
			   cxButton3->Enabled = false;
			   break;
			 case 1:
			   ListBox1->ItemIndex = 0;
			   break;
			 default:
			   ListBox1->ItemIndex = ItemIndex;
			 }
		   break;
		   }
		 }
	   else
		 NewSynonyms = true;
	   }
	 }

   if (!NewTaxonForm->AllowReactivate) {
	 delete NewTaxonForm;
	 NewTaxonForm = NULL;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaFindTaxonForm::cxButton4Click(TObject *Sender)
{
   UnicodeString msg;
   if (taxa_not_found->size() == 1)
	 msg = L"Taxon name not resolved.";
   else
	 msg = IntToStr((int)taxa_not_found->size()) + L" taxa names not resolved.";
   int rv = MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK << mbRetry << mbAbort, 0);
   switch (rv) {
	 case mrOk:
	   ModalResult = mrClose;
	   break;
	 case mrAbort:
	   ModalResult = mrAbort;
	   break;
	 default:
	   ModalResult = mrNone;
	   break;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TFindTaxonForm::ipsJSONS1SSLServerAuthentication(TObject *Sender,
          TipsJSONSSSLServerAuthenticationEventParams *e)
{
   e->Accept = true;
}
//---------------------------------------------------------------------------

