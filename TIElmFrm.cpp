//---------------------------------------------------------------------------

#include <vcl.h>
#include "pch.h"
#pragma hdrstop

#include "TIElmFrm.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDropDownEdit"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "cxCheckComboBox"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxCheckBox"
#pragma link "cxCheckListBox"
#pragma link "cxListBox"
#pragma link "cxButtons"
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
TElementForm *ElementForm;
//---------------------------------------------------------------------------
__fastcall TElementForm::TElementForm(UnicodeString dataset_type,
	UnicodeString TaxaGroupID, UnicodeString element, ELEMENTLOOKUP* elem_lookup,
	TComponent* Owner) : TForm(Owner)
{
   int Index;
   UnicodeString DatasetType = dataset_type.LowerCase();
   Element = element;
   ElementLookup = elem_lookup;
   vector<UnicodeString> DatasetTypes;
   vector<UnicodeString> TaxaGroups;

   ElementLookup->GetDatasetTypes(DatasetTypes);
   for (unsigned int i=0; i<DatasetTypes.size(); i++)
	 cxComboBox4->Properties->Items->Add(DatasetTypes[i]);
   if ((Index = cxComboBox4->Properties->Items->IndexOf(DatasetType)) > -1)
	 cxComboBox4->ItemIndex = Index;

   if (!TaxaGroupID.IsEmpty()) {
	 ElementLookup->ConvertTaxaGroupID(TaxaGroupID);
	 ElementLookup->GetTaxaGroups(DatasetType, TaxaGroups);
	 ElementLookup->GetAllModifiers(AllModifiers);

     cxComboBox3->Properties->Items->Clear();
	 for (unsigned int i=0; i<TaxaGroups.size(); i++)
	   cxComboBox3->Properties->Items->Add(TaxaGroups[i]);
	 if ((Index = cxComboBox3->Properties->Items->IndexOf(TaxaGroupID)) > -1)
	   cxComboBox3->ItemIndex = Index;

	 vector<UnicodeString> parts;
	 int pos = element.Pos(L";");
	 while (pos > 0) {
	   parts.push_back(element.SubString(1,pos-1).Trim());
	   element.Delete(1,pos);
	   pos = element.Pos(L";");
	   }
	 parts.push_back(element.Trim());

	 if (!Element.IsEmpty()) {
	   Label1->Caption = Element;
	   int idx = cxListBox1->Items->IndexOf(parts[0]);
	   if (idx > -1) {
		 cxListBox1->ItemIndex = idx;
		 Element = parts[0];
		 cxCheckListBox1->Enabled = true;
		 cxCheckListBox2->Enabled = true;
		 cxCheckListBox3->Enabled = true;
		 }
	   if (parts.size() > 1) {
		 for (unsigned int i=0; i<parts.size(); i++) {
		   if ((idx = cxCheckListBox1->Items->IndexOf(parts[i])) > -1) {
			 cxCheckListBox1->ItemIndex = idx;
			 cxCheckListBox1->Items->Items[idx]->Checked = true;
			 Symmetry = parts[i];
			 }
		   else if ((idx = cxCheckListBox2->Items->IndexOf(parts[i])) > -1) {
			 cxCheckListBox2->ItemIndex = idx;
			 cxCheckListBox2->Items->Items[idx]->Checked = true;
			 Portion = parts[i];
			 }
		   else if ((idx = cxCheckListBox3->Items->IndexOf(parts[i])) > -1) {
			 cxCheckListBox3->ItemIndex = idx;
			 cxCheckListBox3->Items->Items[idx]->Checked = true;
			 Maturity = parts[i];
			 }
		   }
		 }


	   }
	 else
	   Label1->Caption = L"";
	 }
}
//---------------------------------------------------------------------------

// select dataset type
void __fastcall TElementForm::cxComboBox4Click(TObject *Sender)
{
   vector<UnicodeString> TaxaGroups;
   DatasetType = cxComboBox4->Text;
   ElementLookup->GetTaxaGroups(DatasetType, TaxaGroups);
   cxComboBox3->Properties->Items->Clear();
   for (unsigned int i=0; i<TaxaGroups.size(); i++)
	 cxComboBox3->Properties->Items->Add(TaxaGroups[i]);
   if (cxComboBox3->Properties->Items->Count > 0) {
	 cxComboBox3->ItemIndex = 0;
	 UnicodeString TaxaGroup = cxComboBox3->Properties->Items->Strings[0];
	 }
}
//---------------------------------------------------------------------------

// select taxa group
void __fastcall TElementForm::cxComboBox3Click(TObject *Sender)
{
   TaxaGroup = cxComboBox3->Properties->Items->Strings[cxComboBox3->ItemIndex];

   if (AllModifiers.size() == 0) {
	 ElementLookup->ConvertTaxaGroupID(TaxaGroup);
	 ElementLookup->GetAllModifiers(AllModifiers);
	 }

   SetElements(DatasetType, TaxaGroup);
}
//---------------------------------------------------------------------------

void TElementForm::SetElements(UnicodeString DatasetType, UnicodeString TaxaGroup)
{
   vector<UnicodeString> Elements;
   cxListBox1->Clear();
   cxCheckListBox1->Clear();
   cxCheckListBox2->Clear();
   cxCheckListBox3->Clear();
   Label1->Caption = L"";

   ElementLookup->GetElements(DatasetType, TaxaGroup, Elements);
   for (unsigned int i=0; i<Elements.size(); i++)
	 cxListBox1->Items->Add(Elements[i]);

   set<UnicodeString>::iterator itr;
   set<UnicodeString>::iterator begin = AllModifiers[DatasetType][TaxaGroup].Symmetry.begin();
   set<UnicodeString>::iterator end = AllModifiers[DatasetType][TaxaGroup].Symmetry.end();
   for (itr = begin; itr != end; itr++) {
	 TcxCheckListBoxItem* Item = cxCheckListBox1->Items->Add();
	 Item->Text = *itr;
	 }

   begin = AllModifiers[DatasetType][TaxaGroup].Portion.begin();
   end = AllModifiers[DatasetType][TaxaGroup].Portion.end();
   for (itr = begin; itr != end; itr++) {
	 TcxCheckListBoxItem* Item = cxCheckListBox2->Items->Add();
	 Item->Text = *itr;
	 }

   begin = AllModifiers[DatasetType][TaxaGroup].Maturity.begin();
   end = AllModifiers[DatasetType][TaxaGroup].Maturity.end();
   for (itr = begin; itr != end; itr++) {
	 TcxCheckListBoxItem* Item = cxCheckListBox3->Items->Add();
	 Item->Text = *itr;
	 }
}
//---------------------------------------------------------------------------

// click element
void __fastcall TElementForm::cxListBox1Click(TObject *Sender)
{
   SetElement();
}
//---------------------------------------------------------------------------

void TElementForm::SetElement(void)
{
   Element = cxListBox1->Items->Strings[cxListBox1->ItemIndex];
   UnicodeString Text = Label1->Caption;
   if (Text.IsEmpty())
	 Text = Element;
   else {
	 int pos = Text.Pos(L"; ");
	 if (pos == 0)
	   Text = Element;
	 else {
	   Text.Delete(1,pos-1);
	   Text.Insert(Element,1);
	   }
	 }
   Label1->Caption = Text;

   Symmetry = L"";
   Portion = L"";
   Maturity = L"";
   UncheckAll(cxCheckListBox1);
   cxCheckListBox1->Enabled = true;
   UncheckAll(cxCheckListBox2);
   cxCheckListBox2->Enabled = true;
   UncheckAll(cxCheckListBox3);
   cxCheckListBox3->Enabled = true;

   BuildElement();
}
//---------------------------------------------------------------------------

void TElementForm::UncheckAll(TcxCheckListBox* cxCheckListBox)
{
   for (int i=0; i<cxCheckListBox->Items->Count; i++)
	 cxCheckListBox->Items->Items[i]->Checked = false;
}
//---------------------------------------------------------------------------

// symmetry
void __fastcall TElementForm::cxCheckListBox1ClickCheck(TObject *Sender, int AIndex,
		  TcxCheckBoxState APrevState, TcxCheckBoxState ANewState)
{
   if (ANewState == cbsChecked) {
	 Symmetry = cxCheckListBox1->Items->Items[AIndex]->Text;
	 for (int i=0; i<cxCheckListBox1->Items->Count; i++) {
	   if (i == AIndex) continue;
	   cxCheckListBox1->Items->Items[i]->Checked = false;
	   }
	 }
   else
	 Symmetry = L"";
   BuildElement();
}
//---------------------------------------------------------------------------

// portion
void __fastcall TElementForm::cxCheckListBox2ClickCheck(TObject *Sender, int AIndex,
		  TcxCheckBoxState APrevState, TcxCheckBoxState ANewState)
{
   /* UnicodeString Portion = cxCheckListBox2->Items->Items[AIndex]->Text;
   if (ANewState == cbsChecked)
	 Portions.insert(Portion);
   else
	 Portions.erase(Portion);  */

   if (ANewState == cbsChecked) {
	 Portion = cxCheckListBox2->Items->Items[AIndex]->Text;
	 for (int i=0; i<cxCheckListBox2->Items->Count; i++) {
	   if (i == AIndex) continue;
	   cxCheckListBox2->Items->Items[i]->Checked = false;
	   }
	 }
   else
	 Portion = L"";
   BuildElement();
}
//---------------------------------------------------------------------------

// maturity
void __fastcall TElementForm::cxCheckListBox3ClickCheck(TObject *Sender, int AIndex,
		  TcxCheckBoxState APrevState, TcxCheckBoxState ANewState)
{
   /* UnicodeString Maturity = cxCheckListBox3->Items->Items[AIndex]->Text;
   if (ANewState == cbsChecked)
	 Maturities.insert(Maturity);
   else
	 Maturities.erase(Maturity);  */

   if (ANewState == cbsChecked) {
	 Maturity = cxCheckListBox3->Items->Items[AIndex]->Text;
	 for (int i=0; i<cxCheckListBox3->Items->Count; i++) {
	   if (i == AIndex) continue;
	   cxCheckListBox3->Items->Items[i]->Checked = false;
	   }
	 }
   else
	 Maturity = L"";
   BuildElement();
}
//---------------------------------------------------------------------------

void TElementForm::BuildElement(void)
{
   UnicodeString Text = Element;
   if (!Symmetry.IsEmpty())
	 Text += (L";" + Symmetry);
   if (!Portion.IsEmpty())
	 Text += (L";" + Portion);
   if (!Maturity.IsEmpty())
	 Text += (L";" + Maturity);
   Label1->Caption = Text;
}
//---------------------------------------------------------------------------

