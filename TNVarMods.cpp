//---------------------------------------------------------------------------

#include <vcl.h>
#include "pch.h"
#pragma hdrstop
#include <StrUtils.hpp>
#include <set>
#include "TNVarMods.h"
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
TNeotomaVarModsLookupForm *NeotomaVarModsLookupForm;
//---------------------------------------------------------------------------
__fastcall TNeotomaVarModsLookupForm::TNeotomaVarModsLookupForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaVarModsLookupForm::FormCreate(TObject *Sender)
{
   activated = false;
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaVarModsLookupForm::FormActivate(TObject *Sender)
{
   if (!activated) {
	 Panel1->Visible = true;
	 Screen->Cursor = crHourGlass;
	 DatasetTypes = new NeotomaDatasetTypesTable(ipsJSONS1, TcpClient1);
	 StatusBar1->Caption = DatasetTypes->WebServiceName();
	 bool success = DatasetTypes->Execute();
	 if (success) {
	   map<int,UnicodeString>::iterator begin = DatasetTypes->Items.begin();
	   map<int,UnicodeString>::iterator end = DatasetTypes->Items.end();
	   map<int,UnicodeString>::iterator itr;
	   for (itr = begin; itr != end; itr++) {
		 UnicodeString DatasetType = itr->second;
		 if (SameText(DatasetType, L"geochronologic")) continue;
		 if (ContainsText(DatasetType, "surface sample")) continue;
		 if (ContainsText(DatasetType, "modern")) continue;
		 GenericDatasetTypes.push_back(GENERICDATASETTYPE(DatasetType));
		 CheckListBox1->Items->Add(DatasetType);
		 }

	   CheckListBox1->Sorted = true;
	   CheckListBox1->CheckAll(cbChecked);

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

	 StatusBar1->Caption = L"";
	 Panel1->Visible = false;;
	 Screen->Cursor = crDefault;
	 if (!success)
	   Close();
     cxButton1->Visible = true;
	 cxButton2->Visible = true;
	 activated = true;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaVarModsLookupForm::FormClose(TObject *Sender, TCloseAction &Action)
{
   if (DatasetTypes)
	 delete DatasetTypes;
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaVarModsLookupForm::CheckListBox1ClickCheck(TObject *Sender)
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

// Finish button
void __fastcall TNeotomaVarModsLookupForm::cxButton1Click(TObject *Sender)
{
   if (!GetFileName())
	 return;

   CheckListBox1->Enabled = false;
   cxButton2->Enabled = false;
   Panel1->Visible = true;

   WriteVarMods(StatusBar1, FileName);
   Panel1->Visible = false;
   ModalResult = mrClose;
}
//---------------------------------------------------------------------------

void TNeotomaVarModsLookupForm::WriteVarMods(TPanel* StatusBar1, UnicodeString FileName, bool ShowMessage)
{
   NeotomaElementDatasetTaxaGroupsTable ElDSTGTypes(ipsJSONS1, TcpClient1);
   StatusBar1->Caption = ElDSTGTypes.WebServiceName();
   if (!ElDSTGTypes.Execute())
	 return;

   NeotomaTaxaGroupTypesTable TaxaGroupTypes(ipsJSONS1, TcpClient1);
   StatusBar1->Caption = TaxaGroupTypes.WebServiceName();
   if (!TaxaGroupTypes.Execute())
	 return;

   NeotomaElementTypesTable ElementTypes(ipsJSONS1, TcpClient1);
   StatusBar1->Caption = ElementTypes.WebServiceName();
   if (!ElementTypes.Execute())
	 return;

   NeotomaElementTaxaGroupsTable ElementTaxaGroups(ipsJSONS1, TcpClient1);
   StatusBar1->Caption = ElementTaxaGroups.WebServiceName();
   if (!ElementTaxaGroups.Execute())
	 return;

   NeotomaElementSymmetriesTable ElementSymmetries(ipsJSONS1, TcpClient1);
   StatusBar1->Caption = ElementSymmetries.WebServiceName();
   if (!ElementSymmetries.Execute())
	 return;

   NeotomaElementTaxaGroupSymmetriesTable ElementTaxaGroupSymmetries(ipsJSONS1, TcpClient1);
   StatusBar1->Caption = ElementTaxaGroupSymmetries.WebServiceName();
   if (!ElementTaxaGroupSymmetries.Execute())
	 return;

   NeotomaElementPortionsTable ElementPortions(ipsJSONS1, TcpClient1);
   StatusBar1->Caption = ElementPortions.WebServiceName();
   if (!ElementPortions.Execute())
	 return;

   NeotomaElementTaxaGroupPortionsTable ElementTaxaGroupPortions(ipsJSONS1, TcpClient1);
   StatusBar1->Caption = ElementTaxaGroupPortions.WebServiceName();
   if (!ElementTaxaGroupPortions.Execute())
	 return;

   NeotomaElementMaturitiesTable ElementMaturities(ipsJSONS1, TcpClient1);
   StatusBar1->Caption = ElementMaturities.WebServiceName();
   if (!ElementMaturities.Execute())
	 return;

   NeotomaElementTaxaGroupMaturitiesTable ElementTaxaGroupMaturities(ipsJSONS1, TcpClient1);
   StatusBar1->Caption = ElementTaxaGroupMaturities.WebServiceName();
   if (!ElementTaxaGroupMaturities.Execute())
	 return;

   NeotomaVariableUnitsTable VariableUnits(ipsJSONS1, TcpClient1);
   StatusBar1->Caption = VariableUnits.WebServiceName();
   if (!VariableUnits.Execute())
	 return;

   NeotomaUnitsDatasetTypesTable UnitsDatasetTypes(ipsJSONS1, TcpClient1);
   StatusBar1->Caption = UnitsDatasetTypes.WebServiceName();
   if (!UnitsDatasetTypes.Execute())
	 return;

   NeotomaVariableContextsTable VariableContexts(ipsJSONS1, TcpClient1);
   StatusBar1->Caption = VariableContexts.WebServiceName();
   if (!VariableContexts.Execute())
	 return;

   NeotomaContextsDatasetTypesTable ContextsDatasetTypes(ipsJSONS1, TcpClient1);
   StatusBar1->Caption = ContextsDatasetTypes.WebServiceName();
   if (!ContextsDatasetTypes.Execute())
	 return;

   NeotomaTaphonomicSystemsTable TaphSystems(ipsJSONS1, TcpClient1);
   StatusBar1->Caption = TaphSystems.WebServiceName();
   if (!TaphSystems.Execute())
	 return;

   NeotomaTaphonomicSystemsDatasetTypesTable TaphDatasets(ipsJSONS1, TcpClient1);
   StatusBar1->Caption = TaphDatasets.WebServiceName();
   if (!TaphDatasets.Execute())
	 return;

   NeotomaTaphonomicTypesTable TaphTypes(ipsJSONS1, TcpClient1);
   StatusBar1->Caption = TaphTypes.WebServiceName();
   if (!TaphTypes.Execute())
	 return;

   WriteXML* xmlout = new WriteXML(FileName);

   try {
   try {
	   StatusBar1->Caption = L"Writing " + FileName;
	   xmlout->Declaration("1.0", "UTF-8", "yes");
	   xmlout->DateTime();
	   xmlout->BeginTag("VariableModifiers", "version", "2.0");

	   // elements
	   for (unsigned int i=0; i<GenericDatasetTypes.size(); i++) {
		 //xmlout->BeginTag("Elements", "DatasetType", GenericDatasetTypes[i].Type);
		 vector<int> DatasetTypeIDs;
		 GetDatasetTypeIDs(DatasetTypeIDs, i);

		 multimap<UnicodeString, int> TaxonGroupElements;
		 pair<multimap<UnicodeString,int>::iterator, multimap<UnicodeString,int>::iterator> range;
		 int first, last;
		 for (unsigned int j=0; j<DatasetTypeIDs.size(); j++) {
		   GetElDSTGLimits(ElDSTGTypes, DatasetTypeIDs[j], first, last);
		   if (first > -1) {
			 for (int k=first; k<=last; k++) {
			   UnicodeString TaxaGroupID = ElDSTGTypes.Items[k].TaxaGroupID;
			   int ElementTypeID = ElDSTGTypes.Items[k].ElementTypeID;
			   bool found = false;
			   if (TaxonGroupElements.count(TaxaGroupID) > 0) {
				 range = TaxonGroupElements.equal_range(TaxaGroupID);
				 for (multimap<UnicodeString,int>::iterator m_itr=range.first; m_itr != range.second; m_itr++) {
				   if (m_itr->second == ElementTypeID) {
					 found = true;
					 break;
					 }
				   }
				 }
			   if (!found)
				 TaxonGroupElements.insert(pair<UnicodeString,int>(TaxaGroupID,ElementTypeID));  // BRY, 4
			   }
			 }
		   }

		 if (TaxonGroupElements.size() == 0)
		   continue;

		 //else {
		 xmlout->BeginTag("Elements", "DatasetType", GenericDatasetTypes[i].Type);
		 multimap<UnicodeString, int>::iterator m_itr;
		 UnicodeString TaxaGroupID = TaxonGroupElements.begin()->first;

		 map<int,int> TaxaGroupElements;  // TaxaGroupElements[ElementTypeID] = ElementTaxaGroupID;
		 GetTaxaGroupElements(TaxaGroupID, TaxaGroupElements, ElementTaxaGroups);

		 xmlout->BeginTag("TaxonGroup", "Group", TaxaGroupTypes.Items[TaxaGroupID]);
		 for (m_itr = TaxonGroupElements.begin(); m_itr != TaxonGroupElements.end(); m_itr++) {
		   if (m_itr->first != TaxaGroupID) {
			 xmlout->EndTag("TaxonGroup");
			 TaxaGroupID = m_itr->first;
			 GetTaxaGroupElements(TaxaGroupID, TaxaGroupElements, ElementTaxaGroups);
			 xmlout->BeginTag("TaxonGroup", "Group", TaxaGroupTypes.Items[TaxaGroupID]);
			 }
		   xmlout->BeginTag("Element");
		   int ElementTypeID = m_itr->second;
		   xmlout->Element("Name", ElementTypes.Items[ElementTypeID]);

		   map<int,int>::iterator it = TaxaGroupElements.find(ElementTypeID);
		   if (it != TaxaGroupElements.end()) {
			 int ElementTaxaGroupID = it->second;
			 // symmetries
			 if (ElementTaxaGroupSymmetries.Items.count(ElementTaxaGroupID) > 0) {
			   xmlout->BeginTag("Symmetries");
			   pair<multimap<int,int>::iterator, multimap<int,int>::iterator> rng;
			   rng = ElementTaxaGroupSymmetries.Items.equal_range(ElementTaxaGroupID);
			   for (multimap<int,int>::iterator r_itr=rng.first; r_itr != rng.second; r_itr++) {
				 int SymmetryID = r_itr->second;
				 xmlout->Element("Symmetry", ElementSymmetries.Items[SymmetryID]);
				 }
			   xmlout->EndTag("Symmetries");
			   }
			 else
			   xmlout->EmptyElement("Symmetries");

			 // portions
			 if (ElementTaxaGroupPortions.Items.count(ElementTaxaGroupID) > 0) {
			   xmlout->BeginTag("Portions");
			   pair<multimap<int,int>::iterator, multimap<int,int>::iterator> rng;
			   rng = ElementTaxaGroupPortions.Items.equal_range(ElementTaxaGroupID);
			   for (multimap<int,int>::iterator r_itr=rng.first; r_itr != rng.second; r_itr++) {
				 int PortionID = r_itr->second;
				 xmlout->Element("Portion", ElementPortions.Items[PortionID]);
				 }
			   xmlout->EndTag("Portions");
			   }
			 else
			   xmlout->EmptyElement("Portions");

			 // maturities
			 if (ElementTaxaGroupMaturities.Items.count(ElementTaxaGroupID) > 0) {
			   xmlout->BeginTag("Maturities");
			   pair<multimap<int,int>::iterator, multimap<int,int>::iterator> rng;
			   rng = ElementTaxaGroupMaturities.Items.equal_range(ElementTaxaGroupID);
			   for (multimap<int,int>::iterator r_itr=rng.first; r_itr != rng.second; r_itr++) {
				 int MaturityID = r_itr->second;
				 xmlout->Element("Maturity", ElementMaturities.Items[MaturityID]);
				 }
			   xmlout->EndTag("Maturities");
			   }
			 else
			   xmlout->EmptyElement("Maturities");
			 }
		   else {
			 xmlout->EmptyElement("Symmetries");
			 xmlout->EmptyElement("Portions");
			 xmlout->EmptyElement("Maturities");
			 }
		   xmlout->EndTag("Element");
		   }
		 xmlout->EndTag("TaxonGroup");
		 //  }
		 xmlout->EndTag("Elements");
		 }
	   /*
	   <Units DatasetType="insect">
		 <Unit>MNI</Unit>
		 <Unit>NISP</Unit>
		 <Unit>present/absent</Unit>
	   </Units>
	   */
	   // units
	   for (unsigned int i=0; i<GenericDatasetTypes.size(); i++) {
		 vector<int> DatasetTypeIDs;
		 GetDatasetTypeIDs(DatasetTypeIDs, i);
		 //UnitsDatasetTypes  DatasetTypeID, VariableUnitsID
		 pair<multimap<int,int>::iterator, multimap<int,int>::iterator> range;
		 set<UnicodeString> Units;
		 for (unsigned int j=0; j<DatasetTypeIDs.size(); j++) {
		   range = UnitsDatasetTypes.Items.equal_range(DatasetTypeIDs[j]);
		   for (multimap<int,int>::iterator m_itr=range.first; m_itr != range.second; m_itr++)
			 Units.insert(VariableUnits.Items[m_itr->second]);
		   }

		 if (Units.size() > 0) {
		   xmlout->BeginTag("Units", "DatasetType", GenericDatasetTypes[i].Type);
		   set<UnicodeString>::iterator itr;
		   for (itr = Units.begin(); itr != Units.end(); itr++)
			 xmlout->Element("Unit", *itr);
		   xmlout->EndTag("Units");
		   }
		 }

	   // contexts
	   for (unsigned int i=0; i<GenericDatasetTypes.size(); i++) {
		 vector<int> DatasetTypeIDs;
		 GetDatasetTypeIDs(DatasetTypeIDs, i);
		 //ContextsDatasetTypes  DatasetTypeID, VariableContextID
		 pair<multimap<int,int>::iterator, multimap<int,int>::iterator> range;
		 set<UnicodeString> Contexts;
		 for (unsigned int j=0; j<DatasetTypeIDs.size(); j++) {
		   range = ContextsDatasetTypes.Items.equal_range(DatasetTypeIDs[j]);
		   for (multimap<int,int>::iterator m_itr=range.first; m_itr != range.second; m_itr++)
			 Contexts.insert(VariableContexts.Items[m_itr->second]);
		   }

		 if (Contexts.size() > 0) {
		   xmlout->BeginTag("Contexts", "DatasetType", GenericDatasetTypes[i].Type);
		   set<UnicodeString>::iterator itr;
		   for (itr = Contexts.begin(); itr != Contexts.end(); itr++)
			 xmlout->Element("Context", *itr);
		   xmlout->EndTag("Contexts");
		   }
		 }

	   // taphonomy
	   /*
	   <Taphonomy DatasetType="ostracode">
		 <TaphonomicSystem System="Neotoma Ostracode">
			<TaphonomicType>broken</TaphonomicType>
			<TaphonomicType>corrroded</TaphonomicType>
			<TaphonomicType>juvenile</TaphonomicType>
			<TaphonomicType>setae present</TaphonomicType>
			<TaphonomicType>visceral mass present</TaphonomicType>
		 </TaphonomicSystem>
	   </Taphonomy>
	   */
	   map<int, UnicodeString> TaphSystemsMap;
	   for (unsigned int i=0; i<TaphSystems.Items.size(); i++)
		 TaphSystemsMap[TaphSystems.Items[i].TaphonomicSystemID] = TaphSystems.Items[i].TaphonomicSystem;

	   for (unsigned int i=0; i<GenericDatasetTypes.size(); i++) {
		 vector<int> DatasetTypeIDs;
		 GetDatasetTypeIDs(DatasetTypeIDs, i);
         pair<multimap<int,int>::iterator, multimap<int,int>::iterator> range;

		 set<UnicodeString> TaphSystemNames;
		 for (unsigned int j=0; j<DatasetTypeIDs.size(); j++) {
		   range = TaphDatasets.Items.equal_range(DatasetTypeIDs[j]);
		   for (multimap<int,int>::iterator m_itr=range.first; m_itr != range.second; m_itr++) {
			 TaphSystemNames.insert(TaphSystemsMap[m_itr->second]);
			 }
		   }
		 if (TaphSystemNames.size() > 0) {
		   xmlout->BeginTag("Taphonomy", "DatasetType", GenericDatasetTypes[i].Type);
		   set<UnicodeString>::iterator itr;
		   for (itr = TaphSystemNames.begin(); itr != TaphSystemNames.end(); itr++) {
			 UnicodeString TaphonomicSystem = *itr;
			 xmlout->BeginTag("TaphonomicSystem", "System", TaphonomicSystem);
			 int TaphonomicSystemID;
			 for (map<int,UnicodeString>::iterator it = TaphSystemsMap.begin(); it != TaphSystemsMap.end(); it++) {
			   if (SameText(it->second, TaphonomicSystem)) {
				 TaphonomicSystemID = it->first;
				 break;
			     }
			   }
			 set<UnicodeString> TaphTypeNames;
			 for (unsigned int j=0; j < TaphTypes.Items.size(); j++) {
			   if (TaphTypes.Items[j].TaphonomicSystemID == TaphonomicSystemID)
				 TaphTypeNames.insert(TaphTypes.Items[j].TaphonomicType);
			   }
			 for (set<UnicodeString>::iterator it = TaphTypeNames.begin(); it != TaphTypeNames.end(); it++)
			   xmlout->Element("TaphonomicType", *it);
			 xmlout->EndTag("TaphonomicSystem");
			 }
		   xmlout->EndTag("Taphonomy");
		   }
		 }

	   xmlout->EndTag("VariableModifiers");
	   xmlout->Finish();
	   FLookupCreated = true;
	   }
   catch(Exception &e) {
       FLookupCreated = false;
	   MessageDlg(e.Message, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   }
	   }
   __finally
	   {
	   delete xmlout;
	   Screen->Cursor = crDefault;
	   StatusBar1->Caption = L"";
	   if (ShowMessage)
	     MessageDlg("Variable Modifiers lookup file written: " + FileName, mtInformation, TMsgDlgButtons() << mbOK, 0);
	   }
}
//---------------------------------------------------------------------------

void TNeotomaVarModsLookupForm::GetDatasetTypeIDs(vector<int>& DatasetTypeIDs, int id)
{
   // get vector of DatasetTypeIDs for e.g. all "pollen" DatasetTypes (3,7)
   map<int,UnicodeString>::iterator itr;
   for (unsigned int i=0; i<GenericDatasetTypes[id].DatasetTypes.size(); i++) {
	 UnicodeString DatasetType = GenericDatasetTypes[id].DatasetTypes[i];
	 for (itr = DatasetTypes->Items.begin(); itr != DatasetTypes->Items.end(); itr++) {
	   if (SameText(DatasetType, itr->second)) {
		 DatasetTypeIDs.push_back(itr->first);
		 break;
		 }
	   }
	 }
}
//---------------------------------------------------------------------------

void TNeotomaVarModsLookupForm::GetTaxaGroupElements(UnicodeString TaxaGroupID,
	map<int,int>& TaxaGroupElements, NeotomaElementTaxaGroupsTable& ElementTaxaGroups)
{
   TaxaGroupElements.clear();
   for (unsigned int i=0; i<ElementTaxaGroups.Size(); i++) {
	 if (VarToStr(ElementTaxaGroups.Items[i].TaxaGroupID) == TaxaGroupID ) {
	   int ElementTypeID = VariantToInt(ElementTaxaGroups.Items[i].ElementTypeID, -1);
	   int ElementTaxaGroupID = VariantToInt(ElementTaxaGroups.Items[i].ElementTaxaGroupID, -1);
	   TaxaGroupElements[ElementTypeID] = ElementTaxaGroupID;
	   }
	 }
}
//---------------------------------------------------------------------------

void TNeotomaVarModsLookupForm::GetElDSTGLimits(NeotomaElementDatasetTaxaGroupsTable& ElDSTGTypes,
	int DatasetTypeID, int& first, int& last)
{
   first = -1;
   unsigned int size = ElDSTGTypes.Size();
   for (unsigned int i=0; i<size; i++) {
	 if (ElDSTGTypes.Items[i].DatasetTypeID == DatasetTypeID) {
	   first = i;
	   break;
	   }
	 }
   if (first > -1) {
	 last = first;
	 int next = first + 1;
	 while (next < (int)size && ElDSTGTypes.Items[next].DatasetTypeID == DatasetTypeID) {
	   last++;
	   next++;
	   }
	 }
}
//---------------------------------------------------------------------------

bool TNeotomaVarModsLookupForm::GetFileName(void)
{
   FileName = L"NeotomaVariableModifiers.xml";

   SaveDialog1->InitialDir = tiGlobals->MyLookupPath;
   SaveDialog1->FileName = FileName;
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

void __fastcall TNeotomaVarModsLookupForm::ipsJSONS1SSLServerAuthentication(TObject *Sender,
          TipsJSONSSSLServerAuthenticationEventParams *e)
{
   e->Accept = true;
}
//---------------------------------------------------------------------------

