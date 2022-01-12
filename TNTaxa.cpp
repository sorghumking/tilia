//---------------------------------------------------------------------------

#include <vcl.h>
#include "pch.h"
#pragma hdrstop
#include <StrUtils.hpp>
#include <set>

#include "TNTaxa.h"
#ifndef TIJSONH
#include "TIJSON.h"
#endif
#ifndef TIXMLH
#include "TIXML.h"
#endif
#ifndef TIGlobalsH
#include "TIGlobals.h"
#endif
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "ipwjson"
#pragma link "ipsjsons"
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
TNeotomaTaxaLookupForm *NeotomaTaxaLookupForm;
//---------------------------------------------------------------------------
__fastcall TNeotomaTaxaLookupForm::TNeotomaTaxaLookupForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaTaxaLookupForm::FormCreate(TObject *Sender)
{
   activated = false;
   DatasetTypes = NULL;

   // TODO: this not currently used
   vector<UnicodeString> MicrofossilUnits;
   MicrofossilUnits.push_back(L"NISP");
   MicrofossilUnits.push_back(L"percent");
   MicrofossilUnits.push_back(L"present/absent");
   MicrofossilUnits.push_back(L"NISP digitized");
   MicrofossilUnits.push_back(L"percent digitized");
   DefaultUnits[POLLEN] = MicrofossilUnits;

   // TODO: replace this with results from GetElementTypesForDatasetTypeTaxaGroup webservice.
   //       Needs database at CEI to be updated
   PollenElements.push_back(L"anther");
   PollenElements.push_back(L"glochidia");
   PollenElements.push_back(L"leaf hair");
   PollenElements.push_back(L"leaf spine");
   PollenElements.push_back(L"leaf-hair base");
   PollenElements.push_back(L"massulae");
   PollenElements.push_back(L"megaspore");
   PollenElements.push_back(L"palynomorph");
   PollenElements.push_back(L"pollen");
   PollenElements.push_back(L"spore");
   PollenElements.push_back(L"stomate");

   //int size = DefaultUnits[POLLEN].size();
   //UnicodeString units = DefaultUnits[POLLEN][1];
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaTaxaLookupForm::FormActivate(TObject *Sender)
{
   if (!activated) {
	 Panel1->Visible = true;
	 Screen->Cursor = crHourGlass;
	 DatasetTypes = new NeotomaDatasetTypesTable(ipsJSONS1, TcpClient1);
	 StatusBar1->SimpleText = DatasetTypes->WebServiceName();
	 bool success = DatasetTypes->Execute();
	 if (success) {
	   map<int,UnicodeString>::iterator begin = DatasetTypes->Items.begin();
	   map<int,UnicodeString>::iterator end = DatasetTypes->Items.end();
	   map<int,UnicodeString>::iterator itr;
	   for (itr = begin; itr != end; itr++) {
		 UnicodeString DatasetType = itr->second;
		 if (SameText(DatasetType, L"geochronologic")) continue;
		 //if (SameText(DatasetType, L"loss-on-ignition")) continue;
		 if (ContainsText(DatasetType, "surface sample")) continue;
		 GenericDatasetTypes.push_back(GENERICDATASETTYPE(DatasetType));
		 UnicodeString NeotomaLookupFile = L"Neotoma " + DatasetType;
		 NeotomaLookupFiles.push_back(NeotomaLookupFile);
		 LookupFileDatasetTypes[NeotomaLookupFile] = DatasetType;
		 }

	   for (unsigned int i=0; i<NeotomaLookupFiles.size(); i++)
		 CheckListBox1->Items->Add(NeotomaLookupFiles[i]);
	   CheckListBox1->Sorted = true;
	   //-----------------------
	   // get vector of all DatasetTypes for a particular genric type
	   // e.g. pollen and pollen surface sample
	   for (unsigned int i=0; i<GenericDatasetTypes.size(); i++) {
		 for (itr=begin; itr != end; itr++) {
		   if (ContainsText(itr->second, GenericDatasetTypes[i].Type))
			 GenericDatasetTypes[i].DatasetTypes.push_back(itr->second);
		   }
		 }
	   }

	 StatusBar1->SimpleText = L"";
	 Panel1->Visible = false;;
	 Screen->Cursor = crDefault;
	 if (!success)
	   Close();
	 cxButton6->Visible = true;
	 activated = true;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaTaxaLookupForm::FormClose(TObject *Sender, TCloseAction &Action)

{
   if (DatasetTypes)
	 delete DatasetTypes;
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaTaxaLookupForm::CheckListBox1ClickCheck(TObject *Sender)
{
   bool visible = false;
   int i = 0;
   while (i<CheckListBox1->Count && !visible) {
	 if (CheckListBox1->Checked[i++])
	   visible = true;
	 }
   cxButton1->Visible = visible;
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaTaxaLookupForm::cxButton1Click(TObject *Sender)
{
   RadioGroup1->Enabled = false;

   vector<UnicodeString> TaxaLookup;
   for (int i=0; i<CheckListBox1->Count; i++) {
	 if (CheckListBox1->Checked[i])
	   TaxaLookup.push_back(CheckListBox1->Items->Strings[i]);
	 }

   if (RadioGroup1->ItemIndex == 0)
	 GetDynamicTaxaGroups(TaxaLookup);
   else
	 GetPredefinedTaxaGroups(TaxaLookup);

   GroupBox1->Caption = L"Taxa Lookup File";
   GroupBox2->Caption = L"Taxa Groups Included";
   cxButton3->Visible = true;
   CheckListBox2->CheckAll(cbChecked);
   CheckListBox2->Enabled = false;
   CheckListBox2->Color = clBtnFace;
   CheckListBox2->AllowGrayed = true;
   for (int i=0; i<CheckListBox2->Count; i++) {
	 if (CheckListBox2->State[i] == cbChecked)
	   CheckListBox2->State[i] = cbGrayed;
	 }
   CheckListBox1->ItemIndex = -1;
   CheckListBox1->Enabled = false;
   GroupBox3->Visible = true;
   Panel1->Visible = false;
   FocusControl(Edit1);
   cxButton6->Visible = true;

   UnicodeString Title;
   if (TaxaLookup.size() == 1) {
	 Title = TaxaLookup[0];
	 // capitalize all words if only a single selection
	 for (int idx=1, next=2; idx<Title.Length(); idx++, next++) {
	   if (Title[idx] == L' ') {
		 UnicodeString FirstLetter = Title.SubString(next,1);
		 Title.Delete(next,1);
		 Title.Insert(FirstLetter.UpperCase(),next);
		 }
	   }
	 Title += L" Taxa";
	 }
   else
	 Title = L"Custom Lookup File";
   Edit1->Text = Title;
   cxButton8->Visible = false;
   cxButton5->Visible = true;
}
//---------------------------------------------------------------------------

void TNeotomaTaxaLookupForm::GetDynamicTaxaGroups(vector<UnicodeString>& TaxaLookup)
{
   NeotomaDynamicTaxaGroupCodes TaxaGroupCodes(ipsJSONS1, TcpClient1);
   GetTaxaGroups(TaxaLookup, TaxaGroupCodes);
}
//---------------------------------------------------------------------------

void TNeotomaTaxaLookupForm::GetPredefinedTaxaGroups(vector<UnicodeString>& TaxaLookup)
{
   NeotomaPredefinedTaxaGroupCodes TaxaGroupCodes(ipsJSONS1, TcpClient1);
   GetTaxaGroups(TaxaLookup, TaxaGroupCodes);
}
//---------------------------------------------------------------------------

void TNeotomaTaxaLookupForm::GetTaxaGroups(vector<UnicodeString>& TaxaLookup,
	 NeotomaTaxaGroupCodesBase& TaxaGroupCodes)
{
   // e.g. TaxaLookup = "Neotoma pollen"
   vector<int> DatasetTypeIDs;
   for (unsigned int i=0; i<TaxaLookup.size(); i++) {
	 UnicodeString LookupType = TaxaLookup[i];
	 int idx;
	 for (unsigned i=0; i<GenericDatasetTypes.size(); i++) {
	   // e.g. SameText["Neotoma pollen"] = "pollen"
	   if (SameText(LookupFileDatasetTypes[LookupType], GenericDatasetTypes[i].Type) ) {
		 idx = i;
		 break;
		 }
	   }
	 for (unsigned int i=0; i<GenericDatasetTypes[idx].DatasetTypes.size(); i++) {
	   UnicodeString DatasetType = GenericDatasetTypes[idx].DatasetTypes[i];   // e.g. pollen
	   LookupDatasetTypes.push_back(DatasetType);
	   map<int,UnicodeString>::iterator itr;
	   for (itr = DatasetTypes->Items.begin(); itr != DatasetTypes->Items.end(); itr++) {
		 if (SameText(DatasetType, itr->second)) {
		   DatasetTypeIDs.push_back(itr->first);
		   break;
		   }
		 }
	   }
	 }

   // now have list of DatasetType ID's in DatasetTypeIDs vector
   // e.g. ID's for DatasetTypes "pollen" and "pollen surface sample"
   UnicodeString DatasetTypeList;
   for (unsigned int i=0; i<DatasetTypeIDs.size(); i++) {
	 if (i > 0)
	   DatasetTypeList += L",";
	 DatasetTypeList += IntToStr(DatasetTypeIDs[i]);
	 }
   Screen->Cursor = crHourGlass;
   TaxaGroupCodes.AddParam(L"DATASETTYPEIDS", DatasetTypeList);
   StatusBar1->SimpleText = TaxaGroupCodes.WebServiceName();
   if (TaxaGroupCodes.Execute()) {
	 for (unsigned int i=0; i < TaxaGroupCodes.Size(); i++) {
	   UnicodeString TaxaGroup = TaxaGroupCodes.Items[i].TaxaGroup;
	   UnicodeString TaxaGroupID = TaxaGroupCodes.Items[i].TaxaGroupID;
	   if (DatasetTypeTaxaGroups.find(TaxaGroup) == DatasetTypeTaxaGroups.end()) {   // new TaxaGroup
		 DatasetTypeTaxaGroups[TaxaGroup] = TaxaGroupID;
		 ECOLOGICALGROUP EcologicalGroup;
		 EcologicalGroup.TaxaGroup.Name = TaxaGroup;
		 EcologicalGroup.TaxaGroup.Code = TaxaGroupID;
		 CODENAME EcolGroup;
		 EcolGroup.Code = TaxaGroupCodes.Items[i].EcolGroupID;
		 EcolGroup.Name = TaxaGroupCodes.Items[i].EcolGroup;
		 EcologicalGroup.EcolGroups.push_back(EcolGroup);
		 EcologicalGroups.push_back(EcologicalGroup);
		 }
	   else {  // TaxaGroup already in list
		 vector<ECOLOGICALGROUP>::iterator itr;
		 for (itr = EcologicalGroups.begin(); itr != EcologicalGroups.end(); itr++) {
		   if (itr->TaxaGroup.Code == TaxaGroupID) {
			 CODENAME EcolGroup;
			 EcolGroup.Code = TaxaGroupCodes.Items[i].EcolGroupID;
			 EcolGroup.Name = TaxaGroupCodes.Items[i].EcolGroup;
			 itr->EcolGroups.push_back(EcolGroup);
			 }
		   }
		 }
	   }
	 }
   StatusBar1->SimpleText = L"";
   Screen->Cursor = crDefault;

   map<UnicodeString, UnicodeString>::iterator begin = DatasetTypeTaxaGroups.begin();
   map<UnicodeString, UnicodeString>::iterator end = DatasetTypeTaxaGroups.end();
   map<UnicodeString, UnicodeString>::iterator itr;
   for (itr=begin; itr != end; itr++)
	 CheckListBox2->Items->Add(itr->first);
   GroupBox2->Visible = true;
   //GroupBox1->Enabled = false;
   CheckListBox1->Color = clBtnFace;
   CheckListBox1->AllowGrayed = true;
   for (int i=0; i<CheckListBox1->Count; i++) {
	 if (CheckListBox1->State[i] == cbChecked)
	   CheckListBox1->State[i] = cbGrayed;
	 }
   CheckListBox1->ItemIndex = -1;
   cxButton1->Visible = false;
   Panel1->Visible = false;
}
//---------------------------------------------------------------------------

// back button
void __fastcall TNeotomaTaxaLookupForm::cxButton3Click(TObject *Sender)
{
   EcologicalGroups.clear();
   DatasetTypeTaxaGroups.clear();
   CheckListBox2->Items->Clear();
   GroupBox2->Visible = false;
   CheckListBox1->Color = clWindow;
   for (int i=0; i<CheckListBox1->Count; i++) {
	 if (CheckListBox1->State[i] == cbGrayed)
	   CheckListBox1->State[i] = cbChecked;
	 }
   CheckListBox1->AllowGrayed = false;
   cxButton1->Visible = true;
   CheckListBox1->Enabled = true;
   RadioGroup1->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaTaxaLookupForm::Edit1Change(TObject *Sender)
{
   if (cxButton5->Visible)
	 cxButton5->Visible = false;
   if (Edit1->Text.IsEmpty())
	 cxButton8->Visible = false;
   else if (!cxButton8->Visible)
	 cxButton8->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaTaxaLookupForm::cxButton8Click(TObject *Sender)
{
   cxButton5->Visible = true;
   cxButton8->Visible = false;
}
//---------------------------------------------------------------------------

void ElementUnits::Add(UnicodeString& element, UnicodeString& units)
{
   bool found = false;
   for (unsigned int i=0; i<eu.size(); i++) {
	 if (element == eu[i].Element && units == eu[i].Units) {
	   found = true;
	   break;
	   }
	 }
   if (!found)
	 eu.push_back(ELEMENTUNIT(element, units));
}
//---------------------------------------------------------------------------

void ElementUnits::BuildElementTree(void)
{
   map<UnicodeString, vector<UnicodeString> >::iterator itr;
   for (unsigned int i=0; i<eu.size(); i++) {
	 itr = ElementTree.find(eu[i].Element);
	 if (itr == ElementTree.end()) {  // element doesn't exist yet
	   vector<UnicodeString> Units;
	   Units.push_back(eu[i].Units);
	   ElementTree[eu[i].Element] = Units;
	   }
	 else
	   itr->second.push_back(eu[i].Units);
	 }
}
//---------------------------------------------------------------------------

// Finish button
void __fastcall TNeotomaTaxaLookupForm::cxButton5Click(TObject *Sender)
{
   //int ID, count;
   TAXONRECORD TaxonRec;
   TAXONRECORD SynRec;
   vector<void*> vptrs;
   VARIABLERECORD *VarRec;
   int ElementID, UnitsID;
   UnicodeString Element, Units;
   set<int> TaxaLookup;  // ordered list of taxa IDs incluced in Lookup file: used for synonyms

   if (!GetFileName())
	 return;

   Panel1->Visible = true;
   cxButton6->Visible = false;
   Screen->Cursor = crHourGlass;

   // get vector of TaxaGroups to be included in lookup file
   vector<UnicodeString> TaxaGroups;
   for (unsigned int i=0; i<EcologicalGroups.size(); i++)
	 TaxaGroups.push_back(EcologicalGroups[i].TaxaGroup.Code);
   sort(TaxaGroups.begin(), TaxaGroups.end());
   cxButton6->Visible = false;

   UnicodeString TaxaGroupsList;
   for (unsigned int i=0; i<TaxaGroups.size(); i++) {
	 if (i > 0)
	   TaxaGroupsList += L"$";
	 TaxaGroupsList += TaxaGroups[i];
	 }
   NeotomaValidTaxaByTaxaGroupIDList Taxa(ipsJSONS1, TcpClient1);
   Taxa.AddParam(L"TAXAGROUPLIST", TaxaGroupsList);
   StatusBar1->SimpleText = Taxa.WebServiceName();
   if (!Taxa.Execute())
	 return;

   NeotomaVariablesByTaxaGroupIDList Variables(ipsJSONS1, TcpClient1);
   Variables.AddParam(L"TAXAGROUPLIST", TaxaGroupsList);
   StatusBar1->SimpleText = Variables.WebServiceName();
   if (!Variables.Execute())
	 return;

   NeotomaVariableElementsTable VariableElements(ipsJSONS1, TcpClient1);
   StatusBar1->SimpleText = VariableElements.WebServiceName();
   if (!VariableElements.Execute())
	 return;

   NeotomaVariableUnitsTable VariableUnits(ipsJSONS1, TcpClient1);
   StatusBar1->SimpleText = VariableUnits.WebServiceName();
   if (!VariableUnits.Execute())
	 return;

   NeotomaEcolGroupsByTaxaGroupIDList EcolGroups(ipsJSONS1, TcpClient1);
   EcolGroups.AddParam(L"TAXAGROUPLIST", TaxaGroupsList);
   StatusBar1->SimpleText = EcolGroups.WebServiceName();
   if (!EcolGroups.Execute())
	 return;

   NeotomaLookupSynonym LookupSynonyms(ipsJSONS1, TcpClient1);
   LookupSynonyms.AddParam(L"TAXAGROUPLIST", TaxaGroupsList);
   StatusBar1->SimpleText = LookupSynonyms.WebServiceName();
   if (!LookupSynonyms.Execute())
	 return;

   NeotomaTaxaGroupElementTypes TaxaGroupElements(ipsJSONS1, TcpClient1);
   StatusBar1->SimpleText = TaxaGroupElements.WebServiceName();
   if (!TaxaGroupElements.Execute())
	 return;

   //if (LookupDatasetsInclude(L"pollen")) {
	 // TODO: Use GetElementTypesForDatasetTypeTaxaGroup procedure to get elements for pollen
   //	 }

   WriteXML* xmlout = new WriteXML(FileName);

   try {
   try {
	   StatusBar1->SimpleText = L"Writing " + FileName;
	   xmlout->Declaration("1.0", "UTF-8", "yes");
	   xmlout->DateTime();
	   xmlout->BeginTag("TiliaTaxa", "version", "4.0");
	   xmlout->Element("Title", Edit1->Text);
	   xmlout->BeginTag("EcologicalGroups");
	   for (unsigned int i=0; i<EcologicalGroups.size(); i++) {
		 UnicodeString TaxaGroupID = EcologicalGroups[i].TaxaGroup.Code;
		 xmlout->BeginTag("TaxaGroup", "Code", InsertEntityRefs(TaxaGroupID),
						 "Name", InsertEntityRefs(EcologicalGroups[i].TaxaGroup.Name));
		 for (unsigned int j=0; j<EcologicalGroups[i].EcolGroups.size(); j++) {
		   xmlout->BeginTag("EcologicalGroup");
		   xmlout->Element("Code", EcologicalGroups[i].EcolGroups[j].Code);
		   xmlout->Element("Name", EcologicalGroups[i].EcolGroups[j].Name);
		   xmlout->EndTag("EcologicalGroup");
		   }

		 if (TaxaGroupElements.Items.count(TaxaGroupID) > 0) {
		   pair<multimap<UnicodeString,UnicodeString>::iterator, multimap<UnicodeString,UnicodeString>::iterator> rng;
		   rng = TaxaGroupElements.Items.equal_range(TaxaGroupID);
		   multimap<UnicodeString,UnicodeString>::iterator itr;
		   xmlout->BeginTag("Elements");
		   for (itr = rng.first; itr != rng.second; itr++)
			 xmlout->Element("Element", itr->second);
		   xmlout->EndTag("Elements");
		   }

		 xmlout->EndTag("TaxaGroup");
		 }
	   xmlout->EndTag("EcologicalGroups");

	   xmlout->BeginTag("Taxa");
	   for (unsigned int i=0; i<Taxa.Size(); i++) {
		 TaxonRec = Taxa.Items[i];
		 UnicodeString TaxaGroupID = VarToStr(TaxonRec.TaxaGroupID);
		 // check if taxon is in list of TaxaGroups (e.g VPL) to be included in lookup file
		 if (binary_search(TaxaGroups.begin(), TaxaGroups.end(), TaxaGroupID, CompStr)) {
		   int TaxonID = VariantToInt(TaxonRec.TaxonID, -1);
		   TaxaLookup.insert(TaxonID);
		   xmlout->BeginTag("Taxon", "ID", TaxonID);
		   xmlout->Element("Name", VarToStr(TaxonRec.TaxonName));
		   xmlout->Element("Author", VarToStr(TaxonRec.Author));
		   xmlout->Element("Code", VarToStr(TaxonRec.TaxonCode));
		   xmlout->Element("TaxaGroup", VarToStr(TaxonRec.TaxaGroupID));
		   UnicodeString EcolGroup;
		   int count = EcolGroups.Find("TaxonID", TaxonID, vptrs);  // find EcolGroup for taxon
		   if (count > 0) {   // count should always be >0
			 ECOLGROUPRECORD *EcolGroupRec = (ECOLGROUPRECORD*)vptrs[0];
			 EcolGroup = EcolGroupRec->EcolGroupID;
			 xmlout->Element("EcolGroup", EcolGroup);
			 }
		   int HigherTaxonID = VariantToInt(TaxonRec.HigherTaxonID, -1);
		   xmlout->Element("HigherID", HigherTaxonID);

		   // write elements and units
		   count = Variables.Find("TaxonID", TaxonID, vptrs);

		   //if (dataset_type == POLLEN)
		   if (LookupDatasetsInclude(L"pollen")) {
			 ElementUnits elun;
			 // parse variable records into unique pairs of element and units
			 for (unsigned int i=0; i<vptrs.size(); i++) {
			   VarRec = (VARIABLERECORD*)vptrs[i];
			   if (VarRec->VariableElementID == -1)
				 Element = "";
			   else {
				 int ElementID = VarRec->VariableElementID;
				 Element = VariableElements.Items[ElementID];
				 }
			   if (VarRec->VariableUnitsID == -1)
				 Units = "";
			   else {
				 int UnitsID = VarRec->VariableUnitsID;
				 Units = VariableUnits.Items[UnitsID];
				 }
			   elun.Add(Element, Units);
			   }
			 if (TaxaGroupID == L"VPL") {    // vascular plants
			   set<UnicodeString> Elements;  // an ordered unique list
			   vector<UnicodeString>::iterator start = PollenElements.begin();
			   vector<UnicodeString>::iterator end = PollenElements.end();
			   // Null elements?
			   for (unsigned int i=0; i<elun.eu.size(); i++) {
				 if (find(start, end, elun.eu[i].Element) != end)
					Elements.insert(elun.eu[i].Element);
				 }
			   if (Elements.size() > 0) {
				 set<UnicodeString>::iterator itr;
				 for (itr=Elements.begin(); itr != Elements.end(); itr++)
				   xmlout->EmptyElement("Element", "Type", *itr);
				 }
			   else if (EcolGroup == "VACR")   // element pollen or spore depending on EcolGroup
				 xmlout->EmptyElement("Element", "Type", "spore");
			   else if (!EcolGroup.IsEmpty())
				 xmlout->EmptyElement("Element", "Type", "pollen");
			   }
			 else {    // not a VPL
			   elun.BuildElementTree();
			   map<UnicodeString, vector<UnicodeString> >::iterator itr;
			   for (itr=elun.ElementTree.begin(); itr != elun.ElementTree.end(); itr++) {
				 if (itr->second.size() == 0)
				   xmlout->EmptyElement("Element", "Type", itr->first);
				 else {
				   xmlout->BeginTag("Element", "Type", itr->first);
				   for (unsigned int j=0; j<itr->second.size(); j++)
					 xmlout->Element("Units", itr->second[j]);
				   xmlout->EndTag("Element");
				   }
				 }
			   }
			 }
		   xmlout->EndTag("Taxon");
		   }
		 }
	   xmlout->EndTag("Taxa");

	   set<int>::iterator EndTaxaLookup = TaxaLookup.end();
	   if (LookupSynonyms.Size() > 0) {
		 xmlout->BeginTag("Synonyms");
		 for (unsigned int i=0; i<LookupSynonyms.Size(); i++) {
		   xmlout->BeginTag("Synonym", "ID", LookupSynonyms.Items[i].TaxonID);
		   xmlout->Element("Name", LookupSynonyms.Items[i].TaxonName);
		   xmlout->Element("TaxonID", LookupSynonyms.Items[i].ValidTaxonID);
		   xmlout->EndTag("Synonym");
		   }
		 xmlout->EndTag("Synonyms");
		 }

	   xmlout->EndTag("TiliaTaxa");
	   xmlout->Finish();
	   }
   catch(Exception &e) {
	   MessageDlg(e.Message, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   }
	   }
   __finally
	   {
	   delete xmlout;
	   Panel1->Visible = false;
	   Screen->Cursor = crDefault;
	   StatusBar1->SimpleText = L"";
	   //ShowMessage("Taxa lookup file written: " + FileName);
	   MessageDlg("Taxa lookup file written: " + FileName, mtInformation, TMsgDlgButtons() << mbOK, 0);
	   ModalResult = mrClose;
	   }
}
//---------------------------------------------------------------------------

bool TNeotomaTaxaLookupForm::LookupDatasetsInclude(UnicodeString DatasetType)
{
   for (unsigned int i=0; i<LookupDatasetTypes.size(); i++) {
	 if (SameText(LookupDatasetTypes[i], DatasetType))
	   return true;
	 }
   return false;
}
//---------------------------------------------------------------------------

bool TNeotomaTaxaLookupForm::GetFileName(void)
{
   UnicodeString InvalidChars = L"\\/:*?\"<>|";
   FileName = Edit1->Text;
   FileName = StringReplace(FileName, L" ", "", TReplaceFlags() << rfReplaceAll);
   int pos;
   while ((pos = FileName.LastDelimiter(InvalidChars)) > 0)
	 FileName.Delete(pos, 1);

   if (!tiGlobals->MyLookupPath.IsEmpty())
	 SaveDialog1->InitialDir = tiGlobals->MyLookupPath;
   else
	 SaveDialog1->InitialDir = tiGlobals->AppDataTiliaLookupPath;

   SaveDialog1->FileName = FileName + ".xml";
   if (SaveDialog1->Execute()) {
	 FileName = SaveDialog1->FileName;
	 UnicodeString FileExt = ExtractFileExt(FileName);
	 //if (FileExt.CompareIC(".xml") == 0)
	 if (SameText(FileExt, L".xml"))
	   return true;
	 else {
	   MessageDlg("Taxa file must be *.xml", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return false;
	   }
	 }
   else
	 return false;
}
//---------------------------------------------------------------------------


void __fastcall TNeotomaTaxaLookupForm::ipsJSONS1SSLServerAuthentication(TObject *Sender,
          TipsJSONSSSLServerAuthenticationEventParams *e)
{
   e->Accept = true;
}
//---------------------------------------------------------------------------

