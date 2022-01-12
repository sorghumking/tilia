//---------------------------------------------------------------------------

#include <vcl.h>
#include "pch.h"
#pragma hdrstop

#include "TIEdtElm.h"
#ifndef TIVersionH
#include "TIVersion.h"
#endif
#ifndef TINeotomaH
#include "TINeotoma.h"
#endif
#ifndef TNLoginH
#include "TNLogin.h"
#endif
#ifndef TNNewTaxGrpH
#include "TNNewTaxGrp.h"
#endif

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "ipshttps"
#pragma link "ipwjson"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxGroupBox"
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
#pragma link "ipsjsons"
#pragma resource "*.dfm"
TEditElementsForm *EditElementsForm;
//---------------------------------------------------------------------------
__fastcall TEditElementsForm::TEditElementsForm(VARIABLELOOKUP* var_lookup,
	TComponent* Owner) : TForm(Owner)
{
   ElementLookup = var_lookup->GetElementLookup();
   //PathName = path_name;
   VarLookup = var_lookup;
   Activated = false;

   if (tiLicense->Type() != verNEOTOMASTEWARD) {
	 cxButton16->Visible = false;
	 FlowPanel8->Width = 3*cxButton13->Width + 1;
	 FlowPanel8->Left = (Width - FlowPanel8->Width)/2 + 1;
	 StatusBar1->Visible = false;
	 Height -= StatusBar1->Height;
	 }

   LoadElementLookup();
   LocalElementLookup = new ELEMENTLOOKUP(ElementLookup);

   if (ListBox1->Items->Count) {
	 ListBox1->ItemIndex = 0;
	 ListBox1Click(this);
	 }

   UnicodeString PathName = ElementLookup->GetPathName();
   if (!PathName.IsEmpty())
	 Caption = PathName;
}
//---------------------------------------------------------------------------

void __fastcall TEditElementsForm::FormActivate(TObject *Sender)
{
   if (Activated) return;
   /*
   LoadElementLookup();
   LocalElementLookup = new ELEMENTLOOKUP(ElementLookup);

   if (ListBox1->Items->Count) {
	 ListBox1->ItemIndex = 0;
	 ListBox1Click(this);
	 }
   if (PathName.Length())
	 Caption = PathName;
   */
   Activated = true;
}
//---------------------------------------------------------------------------

void __fastcall TEditElementsForm::FormDestroy(TObject *Sender)
{
   delete LocalElementLookup;
}
//---------------------------------------------------------------------------

void TEditElementsForm::LoadElementLookup(void)
{
   ListBox1->Clear();
   ListBox3->Clear();
   ListBox2->Clear();
   CheckListBox1->Clear();
   CheckListBox2->Clear();
   CheckListBox3->Clear();
   ElementLookup->GetAllModifiers(AllModifiers);
   vector<UnicodeString> DatasetTypes;
   ElementLookup->GetDatasetTypes(DatasetTypes);
   for (unsigned int i=0; i<DatasetTypes.size(); i++)
	 ListBox1->Items->Add(DatasetTypes[i]);
}
//---------------------------------------------------------------------------

void __fastcall TEditElementsForm::ListBox1Click(TObject *Sender)
{
   ChangeDatasetType();
}
//---------------------------------------------------------------------------

void TEditElementsForm::ChangeDatasetType(void)
{
   ListBox3->Items->Clear();

   if (ListBox1->ItemIndex > -1) {
	 UnicodeString DatasetType = CurrentDatasetType();
	 if (LocalElementLookup->Elements[DatasetType].size() > 0) {
	   ELEMENTTAXONGROUP::iterator itr;
	   ELEMENTTAXONGROUP::iterator begin = LocalElementLookup->Elements[DatasetType].begin();
	   ELEMENTTAXONGROUP::iterator end = LocalElementLookup->Elements[DatasetType].end();
	   for (itr = begin; itr != end; itr++)
		 ListBox3->Items->Add(itr->first);
	   }
	 }
   ListBox3->ItemIndex = (ListBox3->Count > 0) ? 0 : -1;

   cxButton2->Enabled = (ListBox1->Count > 0);
   ChangeTaxaGroup();
}
//---------------------------------------------------------------------------

void __fastcall TEditElementsForm::ListBox3Click(TObject *Sender)
{
   ChangeTaxaGroup();
}
//---------------------------------------------------------------------------

void TEditElementsForm::ChangeTaxaGroup(void)
{
   ListBox2->Items->Clear();
   CheckListBox1->Items->Clear();
   CheckListBox2->Items->Clear();
   CheckListBox3->Items->Clear();

   if (ListBox3->ItemIndex > -1) {
	 UnicodeString DatasetType = CurrentDatasetType();
	 UnicodeString TaxaGroup = CurrentTaxaGroup();
	 if (LocalElementLookup->Elements[DatasetType][TaxaGroup].size() > 0) {
	   ELEMENTNAME::iterator itr;
	   ELEMENTNAME::iterator begin = LocalElementLookup->Elements[DatasetType][TaxaGroup].begin();
	   ELEMENTNAME::iterator end = LocalElementLookup->Elements[DatasetType][TaxaGroup].end();
	   for (itr = begin; itr != end; itr++)
		 ListBox2->Items->Add(itr->first);
	   ListBox2->ItemIndex = 0;
	   ListBox2Click(this);

	   set<UnicodeString>::iterator s_itr;
	   set<UnicodeString>::iterator s_begin = AllModifiers[DatasetType][TaxaGroup].Symmetry.begin();
	   set<UnicodeString>::iterator s_end = AllModifiers[DatasetType][TaxaGroup].Symmetry.end();
	   for (s_itr = s_begin; s_itr != s_end; s_itr++)
		 CheckListBox1->Items->Add(*s_itr);
	   s_begin = AllModifiers[DatasetType][TaxaGroup].Portion.begin();
	   s_end = AllModifiers[DatasetType][TaxaGroup].Portion.end();
	   for (s_itr = s_begin; s_itr != s_end; s_itr++)
		 CheckListBox2->Items->Add(*s_itr);
	   s_begin = AllModifiers[DatasetType][TaxaGroup].Maturity.begin();
	   s_end = AllModifiers[DatasetType][TaxaGroup].Maturity.end();
	   for (s_itr = s_begin; s_itr != s_end; s_itr++)
		 CheckListBox3->Items->Add(*s_itr);
	   }
	 }
   ListBox2->ItemIndex = (ListBox2->Count > 0) ? 0 : -1;

   cxButton4->Enabled = (ListBox3->Count > 0);
   ChangeElement();
}
//---------------------------------------------------------------------------

// click on element
void __fastcall TEditElementsForm::ListBox2Click(TObject *Sender)
{
   ChangeElement();
}
//---------------------------------------------------------------------------

void TEditElementsForm::ChangeElement(void)
{
   int Index;
   if (ListBox2->ItemIndex > -1) {
	 for (int i=0; i<CheckListBox1->Items->Count; i++)
	   CheckListBox1->Checked[i] = false;
	 for (int i=0; i<CheckListBox2->Items->Count; i++)
	   CheckListBox2->Checked[i] = false;
	 for (int i=0; i<CheckListBox3->Items->Count; i++)
	   CheckListBox3->Checked[i] = false;

	 UnicodeString DatasetType = CurrentDatasetType();
	 UnicodeString TaxaGroup = CurrentTaxaGroup();
	 UnicodeString Element = CurrentElement();

	 set<UnicodeString>::iterator itr;
	 set<UnicodeString>::iterator begin;
	 set<UnicodeString>::iterator end;

	 if (LocalElementLookup->Elements[DatasetType][TaxaGroup][Element].Symmetry.size() > 0) {
	   begin = LocalElementLookup->Elements[DatasetType][TaxaGroup][Element].Symmetry.begin();
	   end = LocalElementLookup->Elements[DatasetType][TaxaGroup][Element].Symmetry.end();
	   for (itr = begin; itr != end; itr++) {
		 if ((Index = CheckListBox1->Items->IndexOf(*itr)) > -1)
		   CheckListBox1->Checked[Index] = true;
		 }
	   //CheckListBox1->ItemIndex = 0;
	   }

	 if (LocalElementLookup->Elements[DatasetType][TaxaGroup][Element].Portion.size() > 0) {
	   begin = LocalElementLookup->Elements[DatasetType][TaxaGroup][Element].Portion.begin();
	   end = LocalElementLookup->Elements[DatasetType][TaxaGroup][Element].Portion.end();
	   for (itr = begin; itr != end; itr++) {
		 if ((Index = CheckListBox2->Items->IndexOf(*itr)) > -1)
		   CheckListBox2->Checked[Index] = true;
		 }
	   //CheckListBox2->ItemIndex = 0;
	   }

	 if (LocalElementLookup->Elements[DatasetType][TaxaGroup][Element].Maturity.size() > 0) {
	   begin = LocalElementLookup->Elements[DatasetType][TaxaGroup][Element].Maturity.begin();
	   end = LocalElementLookup->Elements[DatasetType][TaxaGroup][Element].Maturity.end();
	   for (itr = begin; itr != end; itr++) {
		 if ((Index = CheckListBox3->Items->IndexOf(*itr)) > -1)
		   CheckListBox3->Checked[Index] = true;
		 }
	   //CheckListBox3->ItemIndex = 0;
	   }
	 }

   CheckListBox1->ItemIndex = (CheckListBox1->Count > 0) ? 0 : -1;
   CheckListBox2->ItemIndex = (CheckListBox2->Count > 0) ? 0 : -1;
   CheckListBox3->ItemIndex = (CheckListBox3->Count > 0) ? 0 : -1;

   cxButton6->Enabled = (ListBox2->Count > 0);
   cxButton8->Enabled = (CheckListBox1->Count > 0);
   cxButton10->Enabled = (CheckListBox2->Count > 0);
   cxButton12->Enabled = (CheckListBox3->Count > 0);
}
//---------------------------------------------------------------------------

// symmetry checked or unchecked
void __fastcall TEditElementsForm::CheckListBox1ClickCheck(TObject *Sender)
{
   UnicodeString DatasetType = CurrentDatasetType();
   UnicodeString TaxaGroup = CurrentTaxaGroup();
   UnicodeString Element = CurrentElement();
   UnicodeString Symmetry = CheckListBox1->Items->Strings[CheckListBox1->ItemIndex];
   bool checked = CheckListBox1->Checked[CheckListBox1->ItemIndex];

   set<UnicodeString>::iterator end =
	 LocalElementLookup->Elements[DatasetType][TaxaGroup][Element].Symmetry.end();
   set<UnicodeString>::iterator itr =
	 LocalElementLookup->Elements[DatasetType][TaxaGroup][Element].Symmetry.find(Symmetry);

   bool changed = true;
   if (checked && itr == end)
	 LocalElementLookup->Elements[DatasetType][TaxaGroup][Element].Symmetry.insert(Symmetry);
   else if (!checked && itr != end)
	 LocalElementLookup->Elements[DatasetType][TaxaGroup][Element].Symmetry.erase(itr);
   else
	 changed = false;

   if (changed) {
	 cxButton15->Enabled = true;
     cxButton16->Enabled = true;
	 }
}
//---------------------------------------------------------------------------

// portion checked or unchecked
void __fastcall TEditElementsForm::CheckListBox2ClickCheck(TObject *Sender)
{
   UnicodeString DatasetType = CurrentDatasetType();
   UnicodeString TaxaGroup = CurrentTaxaGroup();
   UnicodeString Element = CurrentElement();
   UnicodeString Portion = CheckListBox2->Items->Strings[CheckListBox2->ItemIndex];
   bool checked = CheckListBox2->Checked[CheckListBox2->ItemIndex];

   set<UnicodeString>::iterator end =
	 LocalElementLookup->Elements[DatasetType][TaxaGroup][Element].Portion.end();
   set<UnicodeString>::iterator itr =
	 LocalElementLookup->Elements[DatasetType][TaxaGroup][Element].Portion.find(Portion);

   bool changed = true;
   if (checked && itr == end)
	 LocalElementLookup->Elements[DatasetType][TaxaGroup][Element].Portion.insert(Portion);
   else if (!checked && itr != end)
	 LocalElementLookup->Elements[DatasetType][TaxaGroup][Element].Portion.erase(itr);
   else
	 changed = false;

   if (changed) {
	 cxButton15->Enabled = true;
     cxButton16->Enabled = true;
	 }
}
//---------------------------------------------------------------------------

// maturity checked or unchecked
void __fastcall TEditElementsForm::CheckListBox3ClickCheck(TObject *Sender)
{
   UnicodeString DatasetType = CurrentDatasetType();
   UnicodeString TaxaGroup = CurrentTaxaGroup();
   UnicodeString Element = CurrentElement();
   UnicodeString Maturity = CheckListBox3->Items->Strings[CheckListBox3->ItemIndex];
   bool checked = CheckListBox3->Checked[CheckListBox3->ItemIndex];

   set<UnicodeString>::iterator end =
	 LocalElementLookup->Elements[DatasetType][TaxaGroup][Element].Maturity.end();
   set<UnicodeString>::iterator itr =
	 LocalElementLookup->Elements[DatasetType][TaxaGroup][Element].Maturity.find(Maturity);

   bool changed = true;
   if (checked && itr == end)
	 LocalElementLookup->Elements[DatasetType][TaxaGroup][Element].Maturity.insert(Maturity);
   else if (!checked && itr != end)
	 LocalElementLookup->Elements[DatasetType][TaxaGroup][Element].Maturity.erase(itr);
   else
	 changed = false;

   if (changed) {
	 cxButton15->Enabled = true;
     cxButton16->Enabled = true;
	 }
}
//---------------------------------------------------------------------------

// add new DatasetType
void __fastcall TEditElementsForm::cxButton1Click(TObject *Sender)
{
   UnicodeString DatasetType, TaxaGroup;

   if (!Edit1->Text.IsEmpty()) {
	 UnicodeString DatasetType = LowerCase(Edit1->Text);
	 if (ListBox1->Items->IndexOf(DatasetType) > -1) {
	   UnicodeString msg = "Dataset Type \"" + DatasetType + "\" already in list.";
	   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   FocusControl(Edit1);
	   return;
	   }

	 ListBox1->Items->Add(DatasetType);
	 ListBox1->ItemIndex = ListBox1->Items->IndexOf(DatasetType);
	 ELEMENTTAXONGROUP ElementTaxonGroup;
	 LocalElementLookup->Elements[DatasetType] = ElementTaxonGroup;
	 ListBox1Click(this);
	 Edit1->Clear();
	 cxButton1->Enabled = false;
	 cxButton2->Enabled = (LocalElementLookup->Elements.size() > 0);
	 cxButton15->Enabled = true;
	 cxButton16->Enabled = true;
	 }
}
//---------------------------------------------------------------------------

// delete dataset type
void __fastcall TEditElementsForm::cxButton2Click(TObject *Sender)
{
   int Index = ListBox1->ItemIndex;
   UnicodeString DatasetType = CurrentDatasetType();
   //LocalElementLookup->Elements[DatasetType][TaxaGroup][Element].Maturity
   LocalElementLookup->Elements.erase(DatasetType);
   ListBox1->Items->Delete(Index);
   if (Index > 0)
	 ListBox1->ItemIndex = Index - 1;
   else
	 ListBox1->ItemIndex = (ListBox1->Count > 0) ? 0 : -1;
   ChangeDatasetType();
   cxButton2->Enabled = (LocalElementLookup->Elements.size() > 0);
   cxButton15->Enabled = true;
   cxButton16->Enabled = true;
}
//---------------------------------------------------------------------------

// add new TaxaGroup
void __fastcall TEditElementsForm::cxButton3Click(TObject *Sender)
{
   UnicodeString DatasetType, TaxaGroup;

   if (!Edit6->Text.IsEmpty()) {
	 UnicodeString TaxaGroup = LowerCase(Edit6->Text);
	 if (ListBox3->Items->IndexOf(TaxaGroup) > -1) {
	   UnicodeString msg = "Taxa Group \"" + TaxaGroup + "\" already in list.";
	   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   FocusControl(Edit6);
	   return;
	   }

	 UnicodeString DatasetType = CurrentDatasetType();
	 ListBox3->Items->Add(TaxaGroup);
	 ListBox3->ItemIndex = ListBox3->Items->IndexOf(TaxaGroup);
	 ELEMENTNAME ElementName;
	 LocalElementLookup->Elements[DatasetType][TaxaGroup] = ElementName;
	 ChangeTaxaGroup();
	 Edit6->Clear();
	 cxButton3->Enabled = false;
	 cxButton15->Enabled = true;
	 cxButton16->Enabled = true;
	 }
}
//---------------------------------------------------------------------------

// delete TaxaGroup
void __fastcall TEditElementsForm::cxButton4Click(TObject *Sender)
{
   UnicodeString DatasetType = CurrentDatasetType();
   int Index = ListBox3->ItemIndex;
   UnicodeString TaxaGroup = CurrentTaxaGroup();
   LocalElementLookup->Elements[DatasetType].erase(TaxaGroup);
   ListBox3->Items->Delete(Index);
   if (Index > 0)
	 ListBox3->ItemIndex = Index - 1;
   else
	 ListBox3->ItemIndex = (ListBox3->Count > 0) ? 0 : -1;
   ChangeTaxaGroup();
   cxButton4->Enabled = (LocalElementLookup->Elements[DatasetType].size() > 0);
   cxButton15->Enabled = true;
   cxButton16->Enabled = true;
}
//---------------------------------------------------------------------------

// add element
void __fastcall TEditElementsForm::cxButton5Click(TObject *Sender)
{
   if (!Edit2->Text.IsEmpty()) {
	 UnicodeString Element = LowerCase(Edit2->Text);
	 if (ListBox2->Items->IndexOf(Element) > -1) {
	   UnicodeString msg = "Element \"" + Element + "\" already in list.";
	   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   FocusControl(Edit2);
	   return;
	   }
	 UnicodeString DatasetType = CurrentDatasetType();
	 UnicodeString TaxaGroup = CurrentTaxaGroup();

	 ListBox2->Items->Add(Element);
	 ListBox2->ItemIndex = ListBox2->Items->IndexOf(Element);
	 ELEMENTMODIFIERS Modifiers;
	 LocalElementLookup->Elements[DatasetType][TaxaGroup][Element] = Modifiers;
	 ChangeElement();
	 Edit2->Clear();
	 cxButton5->Enabled = false;
	 cxButton15->Enabled = true;
	 cxButton16->Enabled = true;
	 }
}
//---------------------------------------------------------------------------

// delete element
 void __fastcall TEditElementsForm::cxButton6Click(TObject *Sender)
{
   UnicodeString DatasetType = CurrentDatasetType();
   UnicodeString TaxaGroup = CurrentTaxaGroup();
   int Index = ListBox2->ItemIndex;
   UnicodeString Element = CurrentElement();
   LocalElementLookup->Elements[DatasetType][TaxaGroup].erase(Element);
   ListBox2->Items->Delete(Index);
   if (Index > 0)
	 ListBox2->ItemIndex = Index - 1;
   else
	 ListBox2->ItemIndex = (ListBox2->Count > 0) ? 0 : -1;
   ChangeElement();
   cxButton6->Enabled = (LocalElementLookup->Elements[DatasetType][TaxaGroup].size() > 0);
   cxButton15->Enabled = true;
   cxButton16->Enabled = true;
}
//---------------------------------------------------------------------------

// add symmetry
void __fastcall TEditElementsForm::cxButton7Click(TObject *Sender)
{
   if (!Edit3->Text.IsEmpty()) {
	 UnicodeString Symmetry = LowerCase(Edit3->Text);
	 if (CheckListBox1->Items->IndexOf(Symmetry) > -1) {
	   UnicodeString msg = "Symmetry \"" + Symmetry + "\" already in list.";
	   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   FocusControl(Edit3);
	   return;
	   }
	 UnicodeString DatasetType = CurrentDatasetType();
	 UnicodeString TaxaGroup = CurrentTaxaGroup();
	 UnicodeString Element = CurrentElement();
	 CheckListBox1->Items->Add(Symmetry);
	 CheckListBox1->ItemIndex = CheckListBox1->Items->IndexOf(Symmetry);
	 AllModifiers[DatasetType][TaxaGroup].Symmetry.insert(Symmetry);

	 Edit3->Clear();
	 cxButton7->Enabled = false;
	 cxButton8->Enabled = true;
	 cxButton15->Enabled = true;
	 cxButton16->Enabled = true;
	 }
}
//---------------------------------------------------------------------------

// delete symmetry
//LocalElementLookup->Elements[DatasetType][TaxaGroup][Element].Symmetry.end();
void __fastcall TEditElementsForm::cxButton8Click(TObject *Sender)
{
   int Index = CheckListBox1->ItemIndex;
   UnicodeString DatasetType = CurrentDatasetType();
   UnicodeString TaxaGroup = CurrentTaxaGroup();
   UnicodeString Symmetry2Delete = CheckListBox1->Items->Strings[Index];

   set<UnicodeString>::iterator s_itr;
   set<UnicodeString>::iterator s_end;
   ELEMENTNAME::iterator e_itr;
   ELEMENTNAME::iterator e_begin = LocalElementLookup->Elements[DatasetType][TaxaGroup].begin();
   ELEMENTNAME::iterator e_end = LocalElementLookup->Elements[DatasetType][TaxaGroup].end();
   int Proceed = mrYes;
   for (e_itr = e_begin; e_itr != e_end; e_itr++) {
	 UnicodeString Element = e_itr->first;
	 s_end = LocalElementLookup->Elements[DatasetType][TaxaGroup][Element].Symmetry.end();
	 s_itr = LocalElementLookup->Elements[DatasetType][TaxaGroup][Element].Symmetry.find(Symmetry2Delete);
	 if (s_itr != s_end) {
	   UnicodeString msg = L"Symmmetry «" + Symmetry2Delete + L"» is checked for other elements.";
	   msg += L" Delete anyway?";
	   Proceed = MessageDlg(msg, mtWarning, TMsgDlgButtons() << mbYes << mbNo, 0);
	   break;
	   }
	 }

   if (Proceed == mrYes) {
	 CheckListBox1->Items->Delete(Index);
	 if (Index > 0)
	   CheckListBox1->ItemIndex = Index - 1;
	 else
	   CheckListBox1->ItemIndex = (CheckListBox1->Count > 0) ? 0 : -1;

	 for (e_itr = e_begin; e_itr != e_end; e_itr++) {
	   UnicodeString Element = e_itr->first;
	   s_end = LocalElementLookup->Elements[DatasetType][TaxaGroup][Element].Symmetry.end();
	   s_itr = LocalElementLookup->Elements[DatasetType][TaxaGroup][Element].Symmetry.find(Symmetry2Delete);
	   if (s_itr != s_end)
		 LocalElementLookup->Elements[DatasetType][TaxaGroup][Element].Symmetry.erase(s_itr);
	   }
	 AllModifiers[DatasetType][TaxaGroup].Symmetry.erase(Symmetry2Delete);
	 cxButton8->Enabled = (CheckListBox1->Count > 0);
	 cxButton15->Enabled = true;
	 cxButton16->Enabled = true;
	 }
}
//---------------------------------------------------------------------------

// add portion
void __fastcall TEditElementsForm::cxButton9Click(TObject *Sender)
{
   if (!Edit4->Text.IsEmpty()) {
	 UnicodeString Portion = LowerCase(Edit4->Text);
	 if (CheckListBox2->Items->IndexOf(Portion) > -1) {
	   UnicodeString msg = "Portion \"" + Portion + "\" already in list.";
	   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   FocusControl(Edit4);
	   return;
	   }
	 UnicodeString DatasetType = CurrentDatasetType();
	 UnicodeString TaxaGroup = CurrentTaxaGroup();
	 //UnicodeString Element = CurrentElement();
	 CheckListBox2->Items->Add(Portion);
	 CheckListBox2->ItemIndex = CheckListBox2->Items->IndexOf(Portion);
	 AllModifiers[DatasetType][TaxaGroup].Portion.insert(Portion);

	 Edit4->Clear();
	 cxButton9->Enabled = false;
	 cxButton10->Enabled = true;
	 cxButton15->Enabled = true;
	 cxButton16->Enabled = true;
	 }
}
//---------------------------------------------------------------------------

// delete portion
void __fastcall TEditElementsForm::cxButton10Click(TObject *Sender)
{
   int Index = CheckListBox2->ItemIndex;
   UnicodeString DatasetType = CurrentDatasetType();
   UnicodeString TaxaGroup = CurrentTaxaGroup();
   UnicodeString Portion2Delete = CheckListBox2->Items->Strings[Index];

   set<UnicodeString>::iterator s_itr;
   set<UnicodeString>::iterator s_end;
   ELEMENTNAME::iterator e_itr;
   ELEMENTNAME::iterator e_begin = LocalElementLookup->Elements[DatasetType][TaxaGroup].begin();
   ELEMENTNAME::iterator e_end = LocalElementLookup->Elements[DatasetType][TaxaGroup].end();
   int Proceed = mrYes;
   for (e_itr = e_begin; e_itr != e_end; e_itr++) {
	 UnicodeString Element = e_itr->first;
	 s_end = LocalElementLookup->Elements[DatasetType][TaxaGroup][Element].Portion.end();
	 s_itr = LocalElementLookup->Elements[DatasetType][TaxaGroup][Element].Portion.find(Portion2Delete);
	 if (s_itr != s_end) {
	   UnicodeString msg = L"Portion «" + Portion2Delete + L"» is checked for other elements.";
	   msg += L" Delete anyway?";
	   Proceed = MessageDlg(msg, mtWarning, TMsgDlgButtons() << mbYes << mbNo, 0);
	   break;
	   }
	 }

   if (Proceed == mrYes) {
	 CheckListBox2->Items->Delete(Index);
	 if (Index > 0)
	   CheckListBox2->ItemIndex = Index - 1;
	 else
	   CheckListBox2->ItemIndex = (CheckListBox2->Count > 0) ? 0 : -1;

	 for (e_itr = e_begin; e_itr != e_end; e_itr++) {
	   UnicodeString Element = e_itr->first;
	   s_end = LocalElementLookup->Elements[DatasetType][TaxaGroup][Element].Portion.end();
	   s_itr = LocalElementLookup->Elements[DatasetType][TaxaGroup][Element].Portion.find(Portion2Delete);
	   if (s_itr != s_end)
		 LocalElementLookup->Elements[DatasetType][TaxaGroup][Element].Portion.erase(s_itr);
	   }
	 AllModifiers[DatasetType][TaxaGroup].Portion.erase(Portion2Delete);
	 cxButton10->Enabled = (CheckListBox2->Count > 0);
	 cxButton15->Enabled = true;
	 cxButton16->Enabled = true;
	 }
}
//---------------------------------------------------------------------------

// add maturity
void __fastcall TEditElementsForm::cxButton11Click(TObject *Sender)
{
   if (!Edit5->Text.IsEmpty()) {
	 UnicodeString Maturity = LowerCase(Edit5->Text);
	 if (CheckListBox3->Items->IndexOf(Maturity) > -1) {
	   UnicodeString msg = "Maturity \"" + Maturity + "\" already in list.";
	   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   FocusControl(Edit5);
	   return;
	   }
	 UnicodeString DatasetType = CurrentDatasetType();
	 UnicodeString TaxaGroup = CurrentTaxaGroup();
	 UnicodeString Element = CurrentElement();
	 CheckListBox3->Items->Add(Maturity);
	 CheckListBox3->ItemIndex = CheckListBox3->Items->IndexOf(Maturity);
	 AllModifiers[DatasetType][TaxaGroup].Maturity.insert(Maturity);

	 Edit5->Clear();
	 cxButton11->Enabled = false;
	 cxButton12->Enabled = true;
	 cxButton15->Enabled = true;
	 cxButton16->Enabled = true;
	 }
}
//---------------------------------------------------------------------------

// delete maturity
void __fastcall TEditElementsForm::cxButton12Click(TObject *Sender)
{
   int Index = CheckListBox3->ItemIndex;
   UnicodeString DatasetType = CurrentDatasetType();
   UnicodeString TaxaGroup = CurrentTaxaGroup();
   UnicodeString Maturity2Delete = CheckListBox3->Items->Strings[Index];

   set<UnicodeString>::iterator s_itr;
   set<UnicodeString>::iterator s_end;
   ELEMENTNAME::iterator e_itr;
   ELEMENTNAME::iterator e_begin = LocalElementLookup->Elements[DatasetType][TaxaGroup].begin();
   ELEMENTNAME::iterator e_end = LocalElementLookup->Elements[DatasetType][TaxaGroup].end();
   int Proceed = mrYes;
   for (e_itr = e_begin; e_itr != e_end; e_itr++) {
	 UnicodeString Element = e_itr->first;
	 s_end = LocalElementLookup->Elements[DatasetType][TaxaGroup][Element].Maturity.end();
	 s_itr = LocalElementLookup->Elements[DatasetType][TaxaGroup][Element].Maturity.find(Maturity2Delete);
	 if (s_itr != s_end) {
	   UnicodeString msg = L"Maturity «" + Maturity2Delete + L"» is checked for other elements.";
	   msg += L" Delete anyway?";
	   Proceed = MessageDlg(msg, mtWarning, TMsgDlgButtons() << mbYes << mbNo, 0);
	   break;
	   }
	 }

   if (Proceed == mrYes) {
	 CheckListBox3->Items->Delete(Index);
	 if (Index > 0)
	   CheckListBox3->ItemIndex = Index - 1;
	 else
	   CheckListBox3->ItemIndex = (CheckListBox3->Count > 0) ? 0 : -1;

	 for (e_itr = e_begin; e_itr != e_end; e_itr++) {
	   UnicodeString Element = e_itr->first;
	   s_end = LocalElementLookup->Elements[DatasetType][TaxaGroup][Element].Maturity.end();
	   s_itr = LocalElementLookup->Elements[DatasetType][TaxaGroup][Element].Maturity.find(Maturity2Delete);
	   if (s_itr != s_end)
		 LocalElementLookup->Elements[DatasetType][TaxaGroup][Element].Maturity.erase(s_itr);
	   }
	 AllModifiers[DatasetType][TaxaGroup].Maturity.erase(Maturity2Delete);
	 cxButton12->Enabled = (CheckListBox3->Count > 0);
	 cxButton15->Enabled = true;
	 cxButton16->Enabled = true;
	 }
}
//---------------------------------------------------------------------------

// Datasets
void __fastcall TEditElementsForm::Edit1Change(TObject *Sender)
{
   cxButton1->Enabled = (Edit1->Text.Length()) ? true : false;
}
//---------------------------------------------------------------------------

// TaxaGroups
void __fastcall TEditElementsForm::Edit6Change(TObject *Sender)
{
   cxButton3->Enabled = (Edit6->Text.Length()) ? true : false;
}
//---------------------------------------------------------------------------

void __fastcall TEditElementsForm::Edit2Change(TObject *Sender)
{
   cxButton5->Enabled = (Edit2->Text.Length()) ? true : false;
}
//---------------------------------------------------------------------------

void __fastcall TEditElementsForm::Edit3Change(TObject *Sender)
{
   cxButton7->Enabled = (Edit3->Text.Length()) ? true : false;
}
//---------------------------------------------------------------------------

void __fastcall TEditElementsForm::Edit4Change(TObject *Sender)
{
   cxButton9->Enabled = (Edit4->Text.Length()) ? true : false;
}
//---------------------------------------------------------------------------

void __fastcall TEditElementsForm::Edit5Change(TObject *Sender)
{
   cxButton11->Enabled = (Edit5->Text.Length()) ? true : false;
}
//---------------------------------------------------------------------------

// Ok button
void __fastcall TEditElementsForm::cxButton13Click(TObject *Sender)
{
   if (cxButton15->Enabled) {     // save to file button
     // save changes locally
	 delete ElementLookup;
	 ElementLookup = new ELEMENTLOOKUP(LocalElementLookup);
	 VarLookup->SetElementLookup(ElementLookup);
     // save to lookup file
	 if (MessageDlg("Save changes?", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes)
	   Save();
	 }
}
//---------------------------------------------------------------------------

// save button
void __fastcall TEditElementsForm::cxButton15Click(TObject *Sender)
{
   Save();
}
//---------------------------------------------------------------------------

void TEditElementsForm::Save(void)
{
   delete ElementLookup;
   ElementLookup = new ELEMENTLOOKUP(LocalElementLookup);
   VarLookup->SetElementLookup(ElementLookup);
   UnicodeString PathName = ElementLookup->GetPathName();
   if (SaveVariableModifiers(MOD_ELEMENT, PathName, VarLookup, this)) {
	 VarLookup->SetElementPath(PathName);
	 Caption = PathName;
	 cxButton15->Enabled = false;
	 }
}
//---------------------------------------------------------------------------

UnicodeString TEditElementsForm::CurrentCategory(void)
{
   if (ListBox1->ItemIndex > -1)
     return (ListBox1->Items->Strings[ListBox1->ItemIndex]);
   else
	 return UnicodeString(EmptyStr);
}
//---------------------------------------------------------------------------

UnicodeString TEditElementsForm::CurrentElement(void)
{
   if (ListBox2->ItemIndex > -1)
     return (ListBox2->Items->Strings[ListBox2->ItemIndex]);
   else
	 return UnicodeString(EmptyStr);
}
//---------------------------------------------------------------------------

UnicodeString TEditElementsForm::CurrentSymmetry(void)
{
   if (CheckListBox1->ItemIndex > -1)
     return (CheckListBox1->Items->Strings[CheckListBox1->ItemIndex]);
   else
	 return UnicodeString(EmptyStr);
}
//---------------------------------------------------------------------------

UnicodeString TEditElementsForm::CurrentPortion(void)
{
   if (CheckListBox2->ItemIndex > -1)
     return (CheckListBox2->Items->Strings[CheckListBox2->ItemIndex]);
   else
	 return UnicodeString(EmptyStr);
}
//---------------------------------------------------------------------------

UnicodeString TEditElementsForm::CurrentMaturity(void)
{
   if (CheckListBox3->ItemIndex > -1)
	 return (CheckListBox3->Items->Strings[CheckListBox3->ItemIndex]);
   else
	 return UnicodeString(EmptyStr);
}
//---------------------------------------------------------------------------

// upload button
void __fastcall TEditElementsForm::cxButton16Click(TObject *Sender)
{
   MessageDlg(L"Element uploads/updates will be for current Dataset Type and Taxa Group only.",
	 mtInformation, TMsgDlgButtons() << mbOK, 0);

   if (!Login->IsLoggedIn) {
	 NeotomaLoginForm = new TNeotomaLoginForm(this);
	 NeotomaLoginForm->ShowModal();
	 delete NeotomaLoginForm;
	 }
   if (Login->IsLoggedIn) {
	 UploadElements();
	 Screen->Cursor = crDefault;
	 }
}
//---------------------------------------------------------------------------

void TEditElementsForm::UploadElements()
{
   vector<int> DatasetTypeIDs;  // accommodates surface samples
   UnicodeString TaxaGroupID;
   UnicodeString msg;

   Screen->Cursor = crHourGlass;
   UnicodeString DatasetType = CurrentDatasetType();
   UnicodeString TaxaGroup = CurrentTaxaGroup();

   // validate DatasetType
   if (!ValidateDatasetType(DatasetType, DatasetTypeIDs))
	 return;
   if (DatasetTypeIDs.size() == 0) {
	 msg = L"«" + DatasetType + L"» is not a valid Neotoma Dataset Type! ";
	 msg += L"\nElements cannot be uploaded for this Dataset Type.";
	 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
	 return;
	 }

   // validate TaxaGroup
   if (!ValidateTaxaGroup(TaxaGroup, TaxaGroupID))
	 return;
   if (TaxaGroupID.IsEmpty()) {
	 NewTaxaGroupForm = new TNewTaxaGroupForm(&TaxaGroupID, &TaxaGroup, this);
	 int rv = NewTaxaGroupForm->ShowModal();
	 delete NewTaxaGroupForm;
	 if (rv == mrCancel)
	   return;
	 if (!ValidateTaxaGroup(TaxaGroup, TaxaGroupID))
	   return;
	 if (TaxaGroupID.IsEmpty()) {
	   MessageDlg(L"Error uploading new Taxa Group.", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return;
	   }
	 }

   if (!ValidateElementTypes(DatasetTypeIDs, TaxaGroupID))
	 return;
   if (!ValidateSymmetries(TaxaGroupID))
	 return;
   if (!ValidatePortions(TaxaGroupID))
	 return;
   if (!ValidateMaturities(TaxaGroupID))
	 return;
   cxButton16->Enabled = false;
   msg = L"New Elements or Element modifiers uploaded to Neotoma for Dataset Type «";
   msg += DatasetType + L"», Taxa Group «" + TaxaGroup + L"»!";
   msg += L"\nRemember to either save Elements or regenerate the Variables Modifiers lookup file from Neotoma.";
   MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
}
//---------------------------------------------------------------------------

bool TEditElementsForm::ValidateSymmetries(UnicodeString TaxaGroupID)
{
   UnicodeString msg;
   UnicodeString ErrorMsg;

   UnicodeString DatasetType = CurrentDatasetType();
   UnicodeString TaxaGroup = CurrentTaxaGroup();
   set<UnicodeString> localSymmetries;
   vector<UnicodeString> NewSymmetries;

   // upload any new portions
   set<UnicodeString>::iterator s_itr;
   set<UnicodeString>::iterator s_begin = AllModifiers[DatasetType][TaxaGroup].Symmetry.begin();
   set<UnicodeString>::iterator s_end = AllModifiers[DatasetType][TaxaGroup].Symmetry.end();

   for (s_itr = s_begin; s_itr != s_end; s_itr++) {
	 if (localSymmetries.find(*s_itr) == localSymmetries.end())
	   localSymmetries.insert(*s_itr);
	 }

   // get Neotoma symmetries
   NeotomaElementSymmetriesTable ElementSymmetries(ipsJSONS1, TcpClient1);
   StatusBar1->SimpleText = ElementSymmetries.WebServiceName();
   if (!ElementSymmetries.Execute())
	 return false;
   // find new local symmetries
   for (s_itr = localSymmetries.begin(); s_itr != localSymmetries.end(); s_itr++) {
	 map<int, UnicodeString>::iterator itr;
	 map<int, UnicodeString>::iterator begin = ElementSymmetries.Items.begin();
	 map<int, UnicodeString>::iterator end = ElementSymmetries.Items.end();
	 bool found = false;
	 for (itr = begin; itr != end; itr++) {
	   if (SameText(*s_itr, itr->second)) {
		 found = true;
		 break;
		 }
	   }
	 if (!found)
	   NewSymmetries.push_back(*s_itr);
	 }

   // upload new symmetries to ElementSymmetries table
   if (NewSymmetries.size() > 0) {
	 vector<int> newids;
	 InsertData InsertSymmetry(L"InsertElementSymmetry", 1, ipsHTTPS1, ipsJSONS1, TcpClient1);
	 for (unsigned int i=0; i<NewSymmetries.size(); i++) {
	   UnicodeString Symmetry = NewSymmetries[i].LowerCase();
	   msg = L"Upload new Element Symmetry «" + Symmetry + L"» to Neotoma?";
	   if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes)
		 InsertSymmetry.Add(L"SYMMETRY", Symmetry);
	   else
		 return false;
	   }
	 StatusBar1->SimpleText = L"InsertElementSymmetry";
	 InsertSymmetry.PostData();
	 if (InsertSymmetry.Post(newids, ErrorMsg)) {
	   if (newids.size() != NewSymmetries.size()) {
		 msg = L"Error inserting into ElementSymmetries table!";
		 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 return false;
		 }
	   }
	 else {
	   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return false;
	   }
	 }

   // update ElementTaxaGroupSymmetries table
   InsertData InsertElementTaxaGroupSymmetry(L"InsertElementTaxaGroupSymmetry", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
   bool insert = false;
   ELEMENTNAME::iterator e_itr;
   ELEMENTNAME::iterator e_begin = LocalElementLookup->Elements[DatasetType][TaxaGroup].begin();
   ELEMENTNAME::iterator e_end = LocalElementLookup->Elements[DatasetType][TaxaGroup].end();
   set<UnicodeString>::iterator ns_itr;
   set<UnicodeString>::iterator ns_begin;
   set<UnicodeString>::iterator ns_end;
   ELEMENTNAME::iterator ne_end = ElementLookup->Elements[DatasetType][TaxaGroup].end();
   for (e_itr = e_begin; e_itr != e_end; e_itr++) {
	 UnicodeString Element = e_itr->first;
	 NewSymmetries.clear();
	 if (ElementLookup->Elements[DatasetType][TaxaGroup].find(Element) != ne_end) {  // element did exist in Neotoma
	   bool update_symmetries = false;
	   if (LocalElementLookup->Elements[DatasetType][TaxaGroup][Element].Symmetry.size() !=
		   ElementLookup->Elements[DatasetType][TaxaGroup][Element].Symmetry.size())
			 update_symmetries = true;
	   else {
		 s_begin = LocalElementLookup->Elements[DatasetType][TaxaGroup][Element].Symmetry.begin();
		 s_end = LocalElementLookup->Elements[DatasetType][TaxaGroup][Element].Symmetry.end();
		 ns_begin = ElementLookup->Elements[DatasetType][TaxaGroup][Element].Symmetry.begin();
		 ns_end = ElementLookup->Elements[DatasetType][TaxaGroup][Element].Symmetry.end();
		 for (s_itr = s_begin, ns_itr = ns_begin; s_itr != s_end; s_itr++, ns_itr++) {
		   if (*s_itr != *ns_itr) {
			 update_symmetries = true;
			 break;
			 }
		   }
		 }
	   if (update_symmetries) {
		 s_begin = LocalElementLookup->Elements[DatasetType][TaxaGroup][Element].Symmetry.begin();
		 s_end = LocalElementLookup->Elements[DatasetType][TaxaGroup][Element].Symmetry.end();
		 ns_end = ElementLookup->Elements[DatasetType][TaxaGroup][Element].Symmetry.end();
		 for (s_itr = s_begin; s_itr != s_end; s_itr++) {
		   if (ElementLookup->Elements[DatasetType][TaxaGroup][Element].Symmetry.find(*s_itr) == ns_end)
			 NewSymmetries.push_back(*s_itr);
		   }
		 }
	   }
	 else {  // element did not exist in Neotoma
	   s_begin = LocalElementLookup->Elements[DatasetType][TaxaGroup][Element].Symmetry.begin();
	   s_end = LocalElementLookup->Elements[DatasetType][TaxaGroup][Element].Symmetry.end();
	   for (s_itr = s_begin; s_itr != s_end; s_itr++)
		 NewSymmetries.push_back(*s_itr);
	   }

	 if (NewSymmetries.size() > 0) {  // upload new element, symmetry combinations
	   // get symmetries: need to redo because new symmetries may have been added
	   map<UnicodeString, int> SymmetryID;
	   NeotomaElementSymmetriesTable ElementSymmetries(ipsJSONS1, TcpClient1);
	   StatusBar1->SimpleText = ElementSymmetries.WebServiceName();
	   if (ElementSymmetries.Execute()) {
		 map<int,UnicodeString>::iterator sym_itr;
		 map<int,UnicodeString>::iterator sym_begin = ElementSymmetries.Items.begin();
		 map<int,UnicodeString>::iterator sym_end = ElementSymmetries.Items.end();
		 for (sym_itr = sym_begin; sym_itr != sym_end; sym_itr++)
		   SymmetryID[sym_itr->second] = sym_itr->first;
		 }
	   else
		 return false;

	   NeotomaElementTypeByName ElementType(ipsJSONS1, TcpClient1);
	   StatusBar1->SimpleText = ElementType.WebServiceName();
	   ElementType.AddParam(L"ELEMENTTYPE", Element);
	   if (ElementType.Execute()) {
		 if (ElementType.Size() == 1) {
		   int ElementTypeID = ElementType.Items.begin()->first;
           NeotomaElementTaxaGroupID GetElementTaxaGroupID(ipsJSONS1, TcpClient1);
		   StatusBar1->SimpleText = GetElementTaxaGroupID.WebServiceName();
		   GetElementTaxaGroupID.AddParam(L"TAXAGROUPID", TaxaGroupID);
		   GetElementTaxaGroupID.AddParam(L"ELEMENTTYPEID", ElementTypeID);
		   if (GetElementTaxaGroupID.Execute()) {
			 if (GetElementTaxaGroupID.Size() == 1) {
			   int ElementTaxaGroupID = GetElementTaxaGroupID.Items[0];
			   for (unsigned int i=0; i<NewSymmetries.size(); i++) {
				 InsertElementTaxaGroupSymmetry.Add(L"ELEMENTTAXAGROUPID", ElementTaxaGroupID, -1);
				 InsertElementTaxaGroupSymmetry.Add(L"SYMMETRYID", SymmetryID[NewSymmetries[i]], -1);
				 insert = true;
				 }
			   }
			 }
		  else
			 return false;
		   }
		 }
	   else
		 return false;
	   }
	 }

   if (insert) {
	 StatusBar1->SimpleText = L"InsertElementTaxaGroupSymmetry";
	 InsertElementTaxaGroupSymmetry.PostData();
	 if (!InsertElementTaxaGroupSymmetry.Post(ErrorMsg)) {
	   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return false;
	   }
	 }

   return true;
}
//---------------------------------------------------------------------------

bool TEditElementsForm::ValidatePortions(UnicodeString TaxaGroupID)
{
   UnicodeString msg;
   UnicodeString ErrorMsg;

   UnicodeString DatasetType = CurrentDatasetType();
   UnicodeString TaxaGroup = CurrentTaxaGroup();
   set<UnicodeString> localPortions;
   vector<UnicodeString> NewPortions;

   // upload any new portions
   set<UnicodeString>::iterator s_itr;
   set<UnicodeString>::iterator s_begin = AllModifiers[DatasetType][TaxaGroup].Portion.begin();
   set<UnicodeString>::iterator s_end = AllModifiers[DatasetType][TaxaGroup].Portion.end();

   for (s_itr = s_begin; s_itr != s_end; s_itr++) {
	 if (localPortions.find(*s_itr) == localPortions.end())
	   localPortions.insert(*s_itr);
	 }

   // get Neotoma portions
   NeotomaElementPortionsTable ElementPortions(ipsJSONS1, TcpClient1);
   StatusBar1->SimpleText = ElementPortions.WebServiceName();
   if (!ElementPortions.Execute())
	 return false;
   // find new local portions
   for (s_itr = localPortions.begin(); s_itr != localPortions.end(); s_itr++) {
	 map<int, UnicodeString>::iterator itr;
	 map<int, UnicodeString>::iterator begin = ElementPortions.Items.begin();
	 map<int, UnicodeString>::iterator end = ElementPortions.Items.end();
	 bool found = false;
	 for (itr = begin; itr != end; itr++) {
	   if (SameText(*s_itr, itr->second)) {
		 found = true;
		 break;
		 }
	   }
	 if (!found)
	   NewPortions.push_back(*s_itr);
	 }

   // ShowMessage(L"NewPortions.size() = " + IntToStr((int)NewPortions.size()));

   // upload new portions to ElementPortions table
   if (NewPortions.size() > 0) {
	 vector<int> newids;
	 InsertData InsertPortion(L"InsertElementPortion", 1, ipsHTTPS1, ipsJSONS1, TcpClient1);
	 for (unsigned int i=0; i<NewPortions.size(); i++) {
	   UnicodeString Portion = NewPortions[i].LowerCase();
	   msg = L"Upload new Element Portion «" + Portion + L"» to Neotoma?";
	   if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes)
		 InsertPortion.Add(L"PORTION", Portion);
	   else
		 return false;
	   }
	 StatusBar1->SimpleText = L"InsertElementPortion";
	 InsertPortion.PostData();
	 if (InsertPortion.Post(newids, ErrorMsg)) {
	   if (newids.size() != NewPortions.size()) {
		 msg = L"Error inserting into ElementPortions table!";
		 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 return false;
		 }
	   }
	 else {
	   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return false;
	   }
	 }

   // update ElementTaxaGroupPortions table
   InsertData InsertElementTaxaGroupPortion(L"InsertElementTaxaGroupPortion", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
   bool insert = false;
   ELEMENTNAME::iterator e_itr;
   ELEMENTNAME::iterator e_begin = LocalElementLookup->Elements[DatasetType][TaxaGroup].begin();
   ELEMENTNAME::iterator e_end = LocalElementLookup->Elements[DatasetType][TaxaGroup].end();
   set<UnicodeString>::iterator ns_itr;
   set<UnicodeString>::iterator ns_begin;
   set<UnicodeString>::iterator ns_end;
   ELEMENTNAME::iterator ne_end = ElementLookup->Elements[DatasetType][TaxaGroup].end();
   for (e_itr = e_begin; e_itr != e_end; e_itr++) {
	 UnicodeString Element = e_itr->first;
	 NewPortions.clear();
	 if (ElementLookup->Elements[DatasetType][TaxaGroup].find(Element) != ne_end) {  // element did exist in Neotoma
	   bool update_portions = false;
	   if (LocalElementLookup->Elements[DatasetType][TaxaGroup][Element].Portion.size() !=
		   ElementLookup->Elements[DatasetType][TaxaGroup][Element].Portion.size())
			 update_portions = true;
	   else {
		 s_begin = LocalElementLookup->Elements[DatasetType][TaxaGroup][Element].Portion.begin();
		 s_end = LocalElementLookup->Elements[DatasetType][TaxaGroup][Element].Portion.end();
		 ns_begin = ElementLookup->Elements[DatasetType][TaxaGroup][Element].Portion.begin();
		 ns_end = ElementLookup->Elements[DatasetType][TaxaGroup][Element].Portion.end();
		 for (s_itr = s_begin, ns_itr = ns_begin; s_itr != s_end; s_itr++, ns_itr++) {
		   if (*s_itr != *ns_itr) {
			 update_portions = true;
			 break;
			 }
		   }
		 }
	   if (update_portions) {
		 s_begin = LocalElementLookup->Elements[DatasetType][TaxaGroup][Element].Portion.begin();
		 s_end = LocalElementLookup->Elements[DatasetType][TaxaGroup][Element].Portion.end();
		 ns_end = ElementLookup->Elements[DatasetType][TaxaGroup][Element].Portion.end();
		 for (s_itr = s_begin; s_itr != s_end; s_itr++) {
		   if (ElementLookup->Elements[DatasetType][TaxaGroup][Element].Portion.find(*s_itr) == ns_end)
			 NewPortions.push_back(*s_itr);
		   }
		 }
	   }
	 else {  // element did not exist in Neotoma
	   s_begin = LocalElementLookup->Elements[DatasetType][TaxaGroup][Element].Portion.begin();
	   s_end = LocalElementLookup->Elements[DatasetType][TaxaGroup][Element].Portion.end();
	   for (s_itr = s_begin; s_itr != s_end; s_itr++)
		 NewPortions.push_back(*s_itr);
	   }

	 //ShowMessage(L"NewPortions.size() = " + IntToStr((int)NewPortions.size()));   // == 0
	 if (NewPortions.size() > 0) {  // upload new element, portion combinations
	   // get portions: need to redo because new portions may have been added
	   map<UnicodeString, int> PortionID;
	   NeotomaElementPortionsTable ElementPortions(ipsJSONS1, TcpClient1);
	   StatusBar1->SimpleText = ElementPortions.WebServiceName();
	   if (ElementPortions.Execute()) {
		 map<int,UnicodeString>::iterator p_itr;
		 map<int,UnicodeString>::iterator p_begin = ElementPortions.Items.begin();
		 map<int,UnicodeString>::iterator p_end = ElementPortions.Items.end();
		 for (p_itr = p_begin; p_itr != p_end; p_itr++)
		   PortionID[p_itr->second] = p_itr->first;
		 }
	   else
		 return false;

	   NeotomaElementTypeByName ElementType(ipsJSONS1, TcpClient1);
	   StatusBar1->SimpleText = ElementType.WebServiceName();
	   ElementType.AddParam(L"ELEMENTTYPE", Element);
	   if (ElementType.Execute()) {
		 if (ElementType.Size() == 1) {
		   int ElementTypeID = ElementType.Items.begin()->first;
		   NeotomaElementTaxaGroupID GetElementTaxaGroupID(ipsJSONS1, TcpClient1);
		   StatusBar1->SimpleText = GetElementTaxaGroupID.WebServiceName();
		   GetElementTaxaGroupID.AddParam(L"TAXAGROUPID", TaxaGroupID);
		   GetElementTaxaGroupID.AddParam(L"ELEMENTTYPEID", ElementTypeID);
		   if (GetElementTaxaGroupID.Execute()) {
			 if (GetElementTaxaGroupID.Size() == 1) {
			   int ElementTaxaGroupID = GetElementTaxaGroupID.Items[0];
			   for (unsigned int i=0; i<NewPortions.size(); i++) {
				 InsertElementTaxaGroupPortion.Add(L"ELEMENTTAXAGROUPID", ElementTaxaGroupID, -1);
				 InsertElementTaxaGroupPortion.Add(L"PORTIONID", PortionID[NewPortions[i]], -1);
				 //ShowMessage(L"NewPortionID = " + IntToStr(PortionID[NewPortions[i]]));
				 insert = true;
				 }
			   }
			 }
		  else
			 return false;
		   }
		 }
	   else
		 return false;
	   }
	 }

   if (insert) {
	 StatusBar1->SimpleText = L"InsertElementTaxaGroupPortion";
	 InsertElementTaxaGroupPortion.PostData();
	 if (!InsertElementTaxaGroupPortion.Post(ErrorMsg)) {
	   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return false;
	   }
	 }

   return true;
}
//---------------------------------------------------------------------------

bool TEditElementsForm::ValidateMaturities(UnicodeString TaxaGroupID)
{
   UnicodeString msg;
   UnicodeString ErrorMsg;

   UnicodeString DatasetType = CurrentDatasetType();
   UnicodeString TaxaGroup = CurrentTaxaGroup();
   set<UnicodeString> localMaturities;
   vector<UnicodeString> NewMaturities;

   set<UnicodeString>::iterator s_itr;
   set<UnicodeString>::iterator s_begin = AllModifiers[DatasetType][TaxaGroup].Maturity.begin();
   set<UnicodeString>::iterator s_end = AllModifiers[DatasetType][TaxaGroup].Maturity.end();

   for (s_itr = s_begin; s_itr != s_end; s_itr++) {
	 if (localMaturities.find(*s_itr) == localMaturities.end())
	   localMaturities.insert(*s_itr);
	 }

   // get Neotoma maturities
   NeotomaElementMaturitiesTable ElementMaturities(ipsJSONS1, TcpClient1);
   StatusBar1->SimpleText = ElementMaturities.WebServiceName();
   if (!ElementMaturities.Execute())
	 return false;
   // find new local maturities
   for (s_itr = localMaturities.begin(); s_itr != localMaturities.end(); s_itr++) {
	 map<int, UnicodeString>::iterator itr;
	 map<int, UnicodeString>::iterator begin = ElementMaturities.Items.begin();
	 map<int, UnicodeString>::iterator end = ElementMaturities.Items.end();
	 bool found = false;
	 for (itr = begin; itr != end; itr++) {
	   if (SameText(*s_itr, itr->second)) {
		 found = true;
		 break;
		 }
	   }
	 if (!found)
	   NewMaturities.push_back(*s_itr);
	 }

   // upload new maturities to ElementMaturities table
   if (NewMaturities.size() > 0) {
	 vector<int> newids;
	 InsertData InsertMaturity(L"InsertElementMaturity", 1, ipsHTTPS1, ipsJSONS1, TcpClient1);
	 for (unsigned int i=0; i<NewMaturities.size(); i++) {
	   UnicodeString Maturity = NewMaturities[i].LowerCase();
	   msg = L"Upload new Element Maturity «" + Maturity + L"» to Neotoma?";
	   if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes)
		 InsertMaturity.Add(L"MATURITY", Maturity);
	   else
		 return false;
	   }
	 StatusBar1->SimpleText = L"InsertElementMaturity";
	 InsertMaturity.PostData();
	 if (InsertMaturity.Post(newids, ErrorMsg)) {
	   if (newids.size() != NewMaturities.size()) {
		 msg = L"Error inserting into ElementMaturities table!";
		 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 return false;
		 }
	   }
	 else {
	   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return false;
	   }
	 }

   // update ElementTaxaGroupMaturities table
   InsertData InsertElementTaxaGroupMaturity(L"InsertElementTaxaGroupMaturity", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
   bool insert = false;
   ELEMENTNAME::iterator e_itr;
   ELEMENTNAME::iterator e_begin = LocalElementLookup->Elements[DatasetType][TaxaGroup].begin();
   ELEMENTNAME::iterator e_end = LocalElementLookup->Elements[DatasetType][TaxaGroup].end();
   set<UnicodeString>::iterator ns_itr;
   set<UnicodeString>::iterator ns_begin;
   set<UnicodeString>::iterator ns_end;
   ELEMENTNAME::iterator ne_end = ElementLookup->Elements[DatasetType][TaxaGroup].end();
   for (e_itr = e_begin; e_itr != e_end; e_itr++) {
	 UnicodeString Element = e_itr->first;
	 NewMaturities.clear();
	 if (ElementLookup->Elements[DatasetType][TaxaGroup].find(Element) != ne_end) {  // element did exist in Neotoma
	   bool update_maturities = false;
	   if (LocalElementLookup->Elements[DatasetType][TaxaGroup][Element].Maturity.size() !=
		   ElementLookup->Elements[DatasetType][TaxaGroup][Element].Maturity.size())
			 update_maturities = true;
	   else {
		 s_begin = LocalElementLookup->Elements[DatasetType][TaxaGroup][Element].Maturity.begin();
		 s_end = LocalElementLookup->Elements[DatasetType][TaxaGroup][Element].Maturity.end();
		 ns_begin = ElementLookup->Elements[DatasetType][TaxaGroup][Element].Maturity.begin();
		 ns_end = ElementLookup->Elements[DatasetType][TaxaGroup][Element].Maturity.end();
		 for (s_itr = s_begin, ns_itr = ns_begin; s_itr != s_end; s_itr++, ns_itr++) {
		   if (*s_itr != *ns_itr) {
			 update_maturities = true;
			 break;
			 }
		   }
		 }
	   if (update_maturities) {
		 s_begin = LocalElementLookup->Elements[DatasetType][TaxaGroup][Element].Maturity.begin();
		 s_end = LocalElementLookup->Elements[DatasetType][TaxaGroup][Element].Maturity.end();
		 ns_end = ElementLookup->Elements[DatasetType][TaxaGroup][Element].Maturity.end();
		 for (s_itr = s_begin; s_itr != s_end; s_itr++) {
		   if (ElementLookup->Elements[DatasetType][TaxaGroup][Element].Maturity.find(*s_itr) == ns_end)
			 NewMaturities.push_back(*s_itr);
		   }
		 }
	   }
	 else {  // element did not exist in Neotoma
	   s_begin = LocalElementLookup->Elements[DatasetType][TaxaGroup][Element].Maturity.begin();
	   s_end = LocalElementLookup->Elements[DatasetType][TaxaGroup][Element].Maturity.end();
	   for (s_itr = s_begin; s_itr != s_end; s_itr++)
		 NewMaturities.push_back(*s_itr);
	   }

	 if (NewMaturities.size() > 0) {  // upload new element, maturity combinations
	   // get maturities: need to redo because new maturity may have been added
	   map<UnicodeString, int> MaturityID;
	   NeotomaElementMaturitiesTable ElementMaturities(ipsJSONS1, TcpClient1);
	   StatusBar1->SimpleText = ElementMaturities.WebServiceName();
	   if (ElementMaturities.Execute()) {
		 map<int,UnicodeString>::iterator m_itr;
		 map<int,UnicodeString>::iterator m_begin = ElementMaturities.Items.begin();
		 map<int,UnicodeString>::iterator m_end = ElementMaturities.Items.end();
		 for (m_itr = m_begin; m_itr != m_end; m_itr++)
		   MaturityID[m_itr->second] = m_itr->first;
		 }
	   else
		 return false;

	   NeotomaElementTypeByName ElementType(ipsJSONS1, TcpClient1);
	   StatusBar1->SimpleText = ElementType.WebServiceName();
	   ElementType.AddParam(L"ELEMENTTYPE", Element);
	   if (ElementType.Execute()) {
		 if (ElementType.Size() == 1) {
		   int ElementTypeID = ElementType.Items.begin()->first;
		   NeotomaElementTaxaGroupID GetElementTaxaGroupID(ipsJSONS1, TcpClient1);
		   StatusBar1->SimpleText = GetElementTaxaGroupID.WebServiceName();
		   GetElementTaxaGroupID.AddParam(L"TAXAGROUPID", TaxaGroupID);
		   GetElementTaxaGroupID.AddParam(L"ELEMENTTYPEID", ElementTypeID);
		   if (GetElementTaxaGroupID.Execute()) {
			 if (GetElementTaxaGroupID.Size() == 1) {
			   int ElementTaxaGroupID = GetElementTaxaGroupID.Items[0];
			   for (unsigned int i=0; i<NewMaturities.size(); i++) {
				 InsertElementTaxaGroupMaturity.Add(L"ELEMENTTAXAGROUPID", ElementTaxaGroupID, -1);
				 InsertElementTaxaGroupMaturity.Add(L"MATURITYID", MaturityID[NewMaturities[i]], -1);
				 insert = true;
				 }
			   }
			 }
		  else
			 return false;
		   }
		 }
	   else
		 return false;
	   }
	 }

   if (insert) {
	 StatusBar1->SimpleText = L"InsertElementTaxaGroupMaturity";
	 InsertElementTaxaGroupMaturity.PostData();
	 if (!InsertElementTaxaGroupMaturity.Post(ErrorMsg)) {
	   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return false;
	   }
	 }

   return true;
}
//---------------------------------------------------------------------------

bool TEditElementsForm::ValidateElementTypes(vector<int>& DatasetTypeIDs, UnicodeString TaxaGroupID)
{
   UnicodeString msg;
   vector<UnicodeString> NewElements;
   vector<pair<int,UnicodeString> > NewAssignedElements;  // ElementID, Element
   vector<pair<int,UnicodeString> > ExistingElements;     // ElementID, Element
   vector<int> newids;
   UnicodeString DatasetType = CurrentDatasetType();
   UnicodeString TaxaGroup = CurrentTaxaGroup();
   UnicodeString ErrorMsg;

   NeotomaElementTypesTable ElementTypes(ipsJSONS1, TcpClient1);
   StatusBar1->SimpleText = ElementTypes.WebServiceName();
   if (ElementTypes.Execute()) {
	 ELEMENTNAME::iterator itr;
	 ELEMENTNAME::iterator begin = LocalElementLookup->Elements[DatasetType][TaxaGroup].begin();
	 ELEMENTNAME::iterator end = LocalElementLookup->Elements[DatasetType][TaxaGroup].end();
	 map<int,UnicodeString>::iterator e_itr;
	 map<int,UnicodeString>::iterator e_begin = ElementTypes.Items.begin();
	 map<int,UnicodeString>::iterator e_end = ElementTypes.Items.end();
	 for (itr = begin; itr != end; itr++) {
	   UnicodeString localElement = itr->first;
	   bool found = false;
	   for (e_itr = e_begin; e_itr != e_end; e_itr++) {
		 UnicodeString ntmElement = e_itr->second;
		 if (SameText(localElement, ntmElement)) {
		   ExistingElements.push_back(pair<int,UnicodeString>(e_itr->first,localElement));
		   found = true;
		   break;
		   }
		 }
	   if (!found)
		 NewElements.push_back(itr->first);
	   }
	 // store ElementTypeIDs for later
	 for (e_itr = e_begin; e_itr != e_end; e_itr++)
	   ElementTypeIDs[e_itr->second] = e_itr->first;
	 }
   else
	 return false;

   // get element types currently assigned to taxa group
   NeotomaElementTypesByTaxaGroupID TaxaGroupElementTypes(ipsJSONS1, TcpClient1);
   StatusBar1->SimpleText = TaxaGroupElementTypes.WebServiceName();
   TaxaGroupElementTypes.AddParam(L"TAXAGROUPID", TaxaGroupID);
   if (!TaxaGroupElementTypes.Execute())
	 return false;

   // if any elements in ExistingElements is not assigned to this group, add to NewAssignedElements
   for (unsigned int i = 0; i < ExistingElements.size(); i++) {
	 UnicodeString element = ExistingElements[i].second;
	 map<int,UnicodeString>::iterator itr;
	 map<int,UnicodeString>::iterator begin = TaxaGroupElementTypes.Items.begin();
	 map<int,UnicodeString>::iterator end = TaxaGroupElementTypes.Items.end();
	 bool found = false;
	 for (itr = begin; itr != end; itr++) {
	   if (SameText(element,itr->second)) {
		 found = true;
		 break;
		 }
	   }
	 if (!found)
	   NewAssignedElements.push_back(pair<int,UnicodeString>(ExistingElements[i].first,element));
	 }

   if (NewElements.size() > 0) {
	 // insert new ElementTypes into ElementTypes table
	 InsertData InsertElement(L"InsertElementType", 1, ipsHTTPS1, ipsJSONS1, TcpClient1);
	 for (unsigned int i=0; i<NewElements.size(); i++) {
	   msg = L"Upload new Element «" + NewElements[i] + L"» to Neotoma?";
	   if (MessageDlg(msg, Dialogs::mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes)
		 InsertElement.Add(L"ELEMENTTYPE", NewElements[i]);
	   else
		 return false;
	   }
	 StatusBar1->SimpleText = L"InsertElementType";
	 InsertElement.PostData();
	 if (InsertElement.Post(newids, ErrorMsg)) {
	   if (newids.size() != NewElements.size()) {
		 msg = L"Error inserting into ElementTypes table!";
		 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 return false;
		 }
	   }
	 else {
	   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return false;
	   }
	 }

   unsigned int totalsize = newids.size() + NewAssignedElements.size();
   if (totalsize > 0) {
	 // insert new ElementTypes into ElementTaxaGroups table
	 vector<int> new_etg_ids;
	 InsertData InsertElemTaxaGroups(L"InsertElementTaxaGroups", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
	 StatusBar1->SimpleText = L"InsertElementTaxaGroups";
	 if (newids.size() > 0) {
	   for (unsigned int i=0; i<newids.size(); i++) {
		 InsertElemTaxaGroups.Add(L"TAXAGROUPID", TaxaGroupID);
		 InsertElemTaxaGroups.Add(L"ELEMENTTYPEID", newids[i], -1);
		 }
	   }
	 if (NewAssignedElements.size() > 0) {
	   for (unsigned int i=0; i<NewAssignedElements.size(); i++) {
		 InsertElemTaxaGroups.Add(L"TAXAGROUPID", TaxaGroupID);
		 InsertElemTaxaGroups.Add(L"ELEMENTTYPEID", NewAssignedElements[i].first, -1);
		 }
	   }
	 InsertElemTaxaGroups.PostData();
	 if (InsertElemTaxaGroups.Post(new_etg_ids, ErrorMsg)) {
	   if (new_etg_ids.size() != totalsize) {
		 msg = L"Error inserting into ElementTaxaGroups table!";
		 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 return false;
		 }
	   }
	 else {
	   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return false;
	   }

	 // insert new ElementTypes into ElementDatasetTaxaGroups table
	 InsertData InsertElemDatasetTaxaGroups(L"InsertElementDatasetTaxaGroups", 3, ipsHTTPS1, ipsJSONS1, TcpClient1);
	 StatusBar1->SimpleText = L"InsertElementDatasetTaxaGroups";
	 //ShowMessage(L"newids.size() = " + IntToStr((int)newids.size()));
	 if (newids.size() > 0) {
	   for (unsigned int i=0; i<DatasetTypeIDs.size(); i++) {
		 for (unsigned int j=0; j<newids.size(); j++) {
		   InsertElemDatasetTaxaGroups.Add(L"DATASETTYPEID", DatasetTypeIDs[i], -1);
		   InsertElemDatasetTaxaGroups.Add(L"TAXAGROUPID", TaxaGroupID);
		   InsertElemDatasetTaxaGroups.Add(L"ELEMENTTYPEID", newids[j], -1);
		   }
		 }
	   }
	 //ShowMessage(L"NewAssignedElements.size() = " + IntToStr((int)NewAssignedElements.size()));
	 if (NewAssignedElements.size() > 0) {
	   for (unsigned int i=0; i<DatasetTypeIDs.size(); i++) {
		 for (unsigned int j=0; j<NewAssignedElements.size(); j++) {
		   InsertElemDatasetTaxaGroups.Add(L"DATASETTYPEID", DatasetTypeIDs[i], -1);
		   InsertElemDatasetTaxaGroups.Add(L"TAXAGROUPID", TaxaGroupID);
		   InsertElemDatasetTaxaGroups.Add(L"ELEMENTTYPEID", NewAssignedElements[j].first, -1);
		   }
		 }
	   }
	 InsertElemDatasetTaxaGroups.PostData();
	 if (!InsertElemDatasetTaxaGroups.Post(ErrorMsg)) {
	   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return false;
	   }
	 }

   return true;
}
//---------------------------------------------------------------------------

bool TEditElementsForm::ValidateDatasetType(UnicodeString DatasetType, vector<int>& DatasetTypeIDs)
{
   DatasetTypeIDs.clear();
   NeotomaDatasetTypesTable DatasetTypes(ipsJSONS1, TcpClient1);
   StatusBar1->SimpleText = DatasetTypes.WebServiceName();
   bool rv = false;
   if (DatasetTypes.Execute()) {
	 rv = true;
	 map<int, UnicodeString>::iterator itr;
	 map<int, UnicodeString>::iterator begin = DatasetTypes.Items.begin();
	 map<int, UnicodeString>::iterator end = DatasetTypes.Items.end();
	 itr = begin;
	 while (itr != end) {
	   if (ContainsText(itr->second, DatasetType))
		 DatasetTypeIDs.push_back(itr->first);
	   itr++;
	   }
	 }
   return rv;
}
//---------------------------------------------------------------------------

bool TEditElementsForm::ValidateTaxaGroup(UnicodeString& TaxaGroup, UnicodeString& TaxaGroupID)
{
   NeotomaGetTaxaGroupID GetTaxaGroup(ipsJSONS1, TcpClient1);

   StatusBar1->SimpleText = GetTaxaGroup.WebServiceName();
   GetTaxaGroup.AddParam(L"TAXAGROUP", TaxaGroup);
   TaxaGroupID = L"";
   bool rv = false;
   if (GetTaxaGroup.Execute()) {
	 rv = true;
	 if (GetTaxaGroup.Size() > 0) {
	   map<UnicodeString, UnicodeString>::iterator itr = GetTaxaGroup.Items.begin();
	   TaxaGroupID = itr->first;
	   TaxaGroup = itr->second;
	   }
	 }
   return rv;
}
//---------------------------------------------------------------------------

void __fastcall TEditElementsForm::ipsJSONS1SSLServerAuthentication(TObject *Sender,
          TipsJSONSSSLServerAuthenticationEventParams *e)
{
   e->Accept = true;
}
//---------------------------------------------------------------------------

