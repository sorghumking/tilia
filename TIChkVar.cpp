//---------------------------------------------------------------------------
#include <Registry.hpp>
#include <vcl.h>
#include "pch.h"
#include <algorithm>
#include <vector>
#pragma hdrstop

#include "TIChkVar.h"
#ifndef TIGlobalsH
#include "TIGlobals.h"
#endif
//#ifndef TIFndTaxH
//#include "TIFndTax.h"
//#endif
#ifndef TNFindTaxonH
#include "TNFindTaxon.h"
#endif
#ifndef TISynFrmH
#include "TISynFrm.h"
#endif
#ifndef TIChkVarFrmH
#include "TIChkVarFrm.h"
#endif

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxCheckListBox"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxLabel"
#pragma link "cxTextEdit"
#pragma link "cxDropDownEdit"
#pragma link "cxMaskEdit"
#pragma link "cxGroupBox"
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
TCheckVarForm *CheckVarForm;
TNeotomaValidateTaxaForm *NeotomaValidateTaxaForm;

//---------------------------------------------------------------------------
__fastcall TCheckVarForm::TCheckVarForm(TComponent* Owner)
		: TForm(Owner)
{
   TSSForm = (TTilSpreadSheetForm*)Owner;
   FixType = -1;
   LocalTaxaLookupOpen = false;
}
//---------------------------------------------------------------------------

void __fastcall TCheckVarForm::FormCreate(TObject *Sender)
{
   UnicodeString LookupPath;

   TSSForm->ParseTaxa = NULL;

   if (!tiGlobals->MyLookupPath.IsEmpty())
	 LookupPath = tiGlobals->MyLookupPath;
   else
	 LookupPath = tiGlobals->AppDataTiliaLookupPath;

   if (!tiGlobals->TaxaFile.IsEmpty())
	 TaxaFile = LookupPath + ExtractFileName(tiGlobals->TaxaFile);
   else
	 TaxaFile = LookupPath + L"NeotomaPollenVars.xml";

   if (FileExists(TaxaFile))
	 Edit1->Text = TaxaFile;
   else
	 TaxaFile.SetLength(0);

   if (TSSForm->TaxaLookupOpen) {
	 LoadElements();
	 }

   RadioGroup1->ItemIndex = tiGlobals->ReplaceVarCodes;
   RadioGroup2->ItemIndex = tiGlobals->ReplaceElements;
   RadioGroup3->ItemIndex = tiGlobals->ReplaceUnits;
   RadioGroup4->ItemIndex = tiGlobals->ReplaceGroups;
   TrainForm = new TTrainForm(this);
}
//---------------------------------------------------------------------------

void __fastcall TCheckVarForm::FormClose(TObject *Sender, TCloseAction &Action)
{
   if (TSSForm->ParseTaxa)
	 delete TSSForm->ParseTaxa;
   TrainForm->Close();
   delete TrainForm;
}
//---------------------------------------------------------------------------

void __fastcall TCheckVarForm::cxButton1Click(TObject *Sender)
{
   if (FileExists(Edit1->Text)) {
	 OpenDialog1->FileName = Edit1->Text;
	 OpenDialog1->InitialDir = ExtractFilePath(Edit1->Text);
	 }
   if (OpenDialog1->Execute()) {
	 UnicodeString FileExt = ExtractFileExt(OpenDialog1->FileName);
	 if (SameText(FileExt, L".xml")) {
	   Edit1->Text = OpenDialog1->FileName;
	   TaxaFile = Edit1->Text;
	   cxComboBox1->Properties->Items->Clear();
	   cxComboBox1->Clear();
	   LoadTaxaLookup();
	   }
	 else
	   MessageDlg("Variables file must be *.xml", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 }
}
//---------------------------------------------------------------------------

bool TCheckVarForm::LoadTaxaLookup(void)
{
   bool rv;
   //TSSForm->txml = NULL;

   if (TSSForm->ParseTaxa != NULL) {
	 delete TSSForm->ParseTaxa;
	 TSSForm->ParseTaxa = NULL;
	 }
   TSSForm->txml = new TAXAXML();
   TSSForm->ParseTaxa = new PARSETAXA(TSSForm->ipwXMLp6, this);
   TrainForm->Caption = "Parsing Taxa File";
   rv = TSSForm->ParseTaxa->Parse(TaxaFile, TrainForm);
   if (rv) {
	 TaxaVector = &TSSForm->ParseTaxa->TaxaList;
	 Synonyms = &TSSForm->ParseTaxa->Synonyms;
	 TaxaEcolGroups = TSSForm->ParseTaxa->TaxaEcolGroups;
	 LocalTaxaLookupOpen = true;
	 }
   delete TSSForm->txml;
   return rv;
}
//---------------------------------------------------------------------------

void TCheckVarForm::LoadElements(void)
{
   set<UnicodeString>::iterator itr;
   set<UnicodeString>::iterator begin;
   set<UnicodeString>::iterator end;
   if (LocalTaxaLookupOpen) {
	 for (unsigned int i=0; i<TaxaEcolGroups.size(); i++) {
	   begin = TaxaEcolGroups[i].Elements.begin();
	   end = TaxaEcolGroups[i].Elements.end();
	   for (itr = begin; itr != end; itr++)
		 Elements.insert(*itr);
	   }
	 }
   else if (TSSForm->TaxaLookupOpen) {
	 for (unsigned int i=0; i<TSSForm->TaxaEcolGroups.size(); i++) {
	   begin = TSSForm->TaxaEcolGroups[i].Elements.begin();
	   end = TSSForm->TaxaEcolGroups[i].Elements.end();
	   for (itr = begin; itr != end; itr++)
		 Elements.insert(*itr);
	   }
	 }

   begin = Elements.begin();
   end = Elements.end();
   for (itr = begin; itr != end; itr++)
	 cxComboBox1->Properties->Items->Add(*itr);
}
//---------------------------------------------------------------------------

void __fastcall TCheckVarForm::cxComboBox1PropertiesInitPopup(TObject *Sender)
{
   if (cxComboBox1->Properties->Items->Count == 0) {
	 if (!TSSForm->TaxaLookupOpen && !LocalTaxaLookupOpen)
	   LoadTaxaLookup();
	 LoadElements();
	 }
}
//---------------------------------------------------------------------------

// run check
void __fastcall TCheckVarForm::cxButton3Click(TObject *Sender)
{
   short CheckType;
   UnicodeString TaxaFile;
   UnicodeString HierarchyFile;
   UnicodeString VarName;
   UnicodeString VarCode;
   UnicodeString VarGroup;

   bool SpellingChecked = false;
   //bool HierarchyChecked = false;
   TProfGridCell *ACell;
   //TAXON *Taxon;
   Variant Value;

   int RowCount = TSSForm->AbsContentRowCount(TSSForm->ProfGrid1);

   //CheckType = (RadioButton1->Checked) ? SPELLING : HIERARCHY;
   CheckType = SPELLING;
   TaxaFile = Edit1->Text;
   //HierarchyFile = Edit2->Text;
   SubVarCodes = RadioGroup1->ItemIndex;
   SubElements = RadioGroup2->ItemIndex;
   SubUnits = RadioGroup3->ItemIndex;
   SubGroups = RadioGroup4->ItemIndex;

   TaxaNotFound.clear();
   TaxaIDIndex.clear();
   vector<UnicodeString> ErrorList;
   //TSSForm->txml = NULL;

   try {
   try {
   Screen->Cursor = crHourGlass;

   if (CheckType == SPELLING) {
	 bool rv = true;;
	 if (TSSForm->TaxaLookupOpen) {
	   TaxaVector = &TSSForm->TaxaList;
	   Synonyms = &TSSForm->Synonyms;
	   }
	 else if (!LocalTaxaLookupOpen) {
	   rv = LoadTaxaLookup();
	   }

	 if (rv) {
	   TSSForm->CurrentTaxaFile = TaxaFile;
	   TrainForm->Caption = "Checking Taxa";
	   TrainForm->SetMinMaxPos(3, RowCount, 3);
	   TrainForm->Show();

	   // get units if only one
	   if (TSSForm->VarLookup->UnitOpen() && TSSForm->UnitLookup->Units.size() > 0) {
		 map<UnicodeString, set<UnicodeString> >::iterator itr;
		 map<UnicodeString, set<UnicodeString> >::iterator begin = TSSForm->UnitLookup->Units.begin();
		 map<UnicodeString, set<UnicodeString> >::iterator end = TSSForm->UnitLookup->Units.end();
		 for (itr = begin; itr != end; itr++) {
		   if (SameText(TSSForm->Datasets[0].DatasetType, itr->first)) {
			 if (TSSForm->UnitLookup->Units[itr->first].size() == 1) {
			   set<UnicodeString>::iterator it = TSSForm->UnitLookup->Units[itr->first].begin();
			   UnitsValue = *it;
			   }
			 break;
			 }
		   }
		 }
	   // if UnitsValue still empty and dataset type is pollen, set to NISP
	   if (UnitsValue.IsEmpty() && TSSForm->Datasets[0].DatasetType.CompareIC("Pollen") == 0)
		 UnitsValue = "NISP";

	   TSSForm->ProfGrid1->DisableControls();
	   TSSForm->ProfGrid1->SpreadsheetEnabled = false;

	   // If taxon is found, replace VarCode etc. with those in lookup file
	   // If taxon is not found, put in TaxaNotFound list
	   int nrows = RowCount;
	   int start = TSSForm->AbsHeaderRowCount(TSSForm->ProfGrid1);
	   for (int row=start; row<=nrows; row++) {
		 Value = TSSForm->ProfGrid1->AbsoluteCells[1][row]->Value;
		 if (Value.Type() == varOleStr)
		   VarCode = Value;
		 else
		   VarCode.SetLength(0);
		 if (VarCode.SubString(1,1) != "#" &&
			 VarCode.SubString(1,3) != "SUM" &&
			 VarCode.SubString(1,4) != "SSUM") {
		   TProfGridCell* ACell = TSSForm->ProfGrid1->AbsoluteCells[2][row];
		   Value = ACell->Value;
		   if (Value.Type() == varOleStr) {
			 VarName = Value;
			 vector<TAXON> TaxaFound;
			 if (TaxaVector->FindName(VarName, TaxaFound)) {
			   TSSForm->ReplaceVarCodes(&TaxaFound[0], row, SubVarCodes);
			   TSSForm->ReplaceGroupCodes(&TaxaFound[0], row, SubGroups);

			   if (TaxaFound[0].Elements.size() == 0 && !cxComboBox1->Text.IsEmpty()) {
				 ELEMENT Element;
				 Element.Name = cxComboBox1->Text;
				 TaxaFound[0].Elements.push_back(Element);
				 }

			   TSSForm->ReplaceElements(&TaxaFound[0], row, SubElements);
			   TSSForm->ReplaceUnits(&TaxaFound[0], row, SubUnits, UnitsValue);
			   }
			 else {
			   TaxaNotFound.push_back(SSTAXANAME(VarName, L"", row));
			   }
			 }
		   }
		 TrainForm->SetPosition(row);
		 }

	   TSSForm->ProfGrid1->SpreadsheetEnabled = true;
	   TSSForm->ProfGrid1->EnableControls();

	   TrainForm->Hide();   // probably move these down
	   Screen->Cursor = crDefault;

	   //FixType = FIXSYNONYMS;
	   if (TaxaNotFound.size() > 0) {
		 FixSynonyms();
		 if (TaxaNotFound.size() > 0) {
		   OtherTaxaNotFound();
           ModalResult = mrClose;
		   }
		 else {
		   MessageDlg("All taxa names resolved.", mtInformation, TMsgDlgButtons() << mbOK, 0);
		   ModalResult = mrOk;
		   }
		 }
	   else  {
		 MessageDlg("All taxa found.", mtInformation, TMsgDlgButtons() << mbOK, 0);
		 ModalResult = mrOk;
		 }
	   SpellingChecked = true;
	   }
	 }
   }
   catch(Exception &e)  {
	 MessageDlg(e.Message, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
   }
   }
   __finally {
	 TSSForm->CurrentTaxaFile.SetLength(0);
	 Screen->Cursor = crDefault;
	 cxButton4->Caption = L"Close";
	 if (SpellingChecked)
	   tiGlobals->TaxaFile = ExtractFileName(TaxaFile);
   }
}
//---------------------------------------------------------------------------

void TCheckVarForm::FixSynonyms(void)
{
   //if (TSSForm->ParseTaxa->Synonyms.size() > 0) [
   if (Synonyms->size() > 0) {
	 //unsigned int count = TSSForm->ParseTaxa->TaxaList.size();
	 unsigned int count = TaxaVector->size();
	 for (unsigned int i=0; i<count; i++) {     // make index to Taxa by TaxonID
	   //vector<TAXON>::pointer Taxon = &TSSForm->ParseTaxa->TaxaList[i];
	   vector<TAXON>::pointer Taxon = &TaxaVector->at(i);
	   TaxaIDIndex[Taxon->ID] = Taxon;
	   }
	 map<UnicodeString, int>::iterator itr;
	 //map<UnicodeString, int>::iterator end = TSSForm->ParseTaxa->Synonyms.end();
     map<UnicodeString, int>::iterator end = Synonyms->end();

	 vector<SYNONYMROW> synrows;
	 for (unsigned int i=0; i<TaxaNotFound.size(); i++) {
	   //if ((itr = TSSForm->ParseTaxa->Synonyms.find(TaxaNotFound[i].Name)) != end) [
	   if ((itr = Synonyms->find(TaxaNotFound[i].Name)) != end) {
		 int TaxonID = itr->second;
		 TAXON* Taxon = TaxaIDIndex[TaxonID];
		 SYNONYMROW sr(TaxaNotFound[i].Row, TaxaNotFound[i].Name, Taxon);
		 synrows.push_back(sr);
		 }
	   }
	 if (synrows.size() > 0) {
	   LocalSynonymsForm = new TLocalSynonymsForm(synrows, TSSForm);
	   if (LocalSynonymsForm->ShowModal() == mrOk) {
		 LocalSynonymsForm->GetSynonyms(synrows);
		 TSSForm->ReplaceSynonyms(synrows, SubVarCodes, SubGroups, SubElements, SubUnits, UnitsValue);
		 }
	   delete LocalSynonymsForm;

	   // delete taxa with synonyms from TaxaNotFound
	   vector<SSTAXANAME>::iterator itr;
	   for (unsigned int i=0; i<synrows.size(); i++) {
		 for (itr = TaxaNotFound.begin(); itr != TaxaNotFound.end(); itr++) {
		   if (synrows[i].row == itr->Row) {
			 TaxaNotFound.erase(itr);
			 break;
			 }
		   }
		 }
	   }
	 }
}
//---------------------------------------------------------------------------

void TCheckVarForm::CheckDuplicates(vector<SSVAR>& SSVarList)
{
   TSSForm->CheckVarDuplicates(SSVarList, DupVars);
   if (DupVars.size() > 0) {
	 TCheckDupsForm* CheckDupsForm = new TCheckDupsForm(TSSForm);
	 CheckDupsForm->FillDupVars(DupVars);
	 CheckDupsForm->ShowModal();
	 delete CheckDupsForm;
	 }
}
//---------------------------------------------------------------------------

void TCheckVarForm::OtherTaxaNotFound(void)
{
   TFindTaxonForm *FindTaxonForm = new TFindTaxonForm(&TaxaNotFound, TSSForm, this);
   FindTaxonForm->SetTaxaList(TaxaVector);  // complete lookup list
   FindTaxonForm->ShowModal();
   delete FindTaxonForm;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

__fastcall TNeotomaValidateTaxaForm::TNeotomaValidateTaxaForm(TComponent* Owner)
		: TCheckVarForm(Owner)
{
   Label1->Visible = false;
   FlowPanel1->Visible = false;
   Panel1->Visible = false;
   RadioGroup1->Caption = L"Replace Var Codes:";
   RadioGroup1->Width = 128;
   RadioGroup2->Visible = false;
   RadioGroup3->Visible = false;
   RadioGroup4->Visible = false;
   cxButton3->Width = 64;
   cxButton4->Width = 64;
   FlowPanel2->Width = 128;
   cxGroupBox1->Top = 12;
   cxGroupBox1->Left = 36;
   cxGroupBox1->Width = RadioGroup1->Left + RadioGroup1->Width + 8;
   cxGroupBox1->Caption = L"";
   cxGroupBox1->Style->BorderStyle = ebsNone;
   Width = cxGroupBox1->Left + cxGroupBox1->Width + 44;
   int dh = FlowPanel2->Top - 130;
   FlowPanel2->Top = 130;
   FlowPanel2->Left = 44;
   Height = Height - dh;
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaValidateTaxaForm::FormCreate(TObject *Sender)
{
   RadioGroup1->ItemIndex = tiGlobals->ReplaceVarCodes;
   TrainForm = new TTrainForm(this);
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaValidateTaxaForm::FormClose(TObject *Sender, TCloseAction &Action)
{
   TrainForm->Close();
   delete TrainForm;
}
//---------------------------------------------------------------------------

// run check
void __fastcall TNeotomaValidateTaxaForm::cxButton3Click(TObject *Sender)
{
   ModalResult = mrOk;
}
//---------------------------------------------------------------------------

void __fastcall TCheckVarForm::RadioGroup2Click(TObject *Sender)
{
   switch (RadioGroup2->ItemIndex) {
	 case 0:
	 case 1:

	 default:
	   ;
	 }

}
//---------------------------------------------------------------------------


