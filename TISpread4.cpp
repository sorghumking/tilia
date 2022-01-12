//---------------------------------------------------------------------------
#include <vcl.h>
#include "pch.h"

#pragma hdrstop

#include "TISpread4.h"
#ifndef TGParentH
#include "TGParent.h"
#endif
#ifndef TISpreadH
#include "TISpread.h"
#endif
#ifndef TIVrLkUpH
#include "TIVrLkUp.h"
#endif
#ifndef TIEdTreeH
#include "TIEdTree.h"
#endif
#ifndef TIEdTaxaH
#include "TIEdTaxa.h"
#endif
#ifndef TIEdtElmH
#include "TIEdtElm.h"
#endif
#ifndef TIEdtModH
#include "TIEdtMod.h"
#endif
#ifndef TIEdTaphH
#include "TIEdTaph.h"
#endif
#ifndef TIPltModH
#include "TIPltMod.h"
#endif
#ifndef TIOptionH
#include "TIOption.h"
#endif
#ifndef TISumsH
#include "TISums.h"
#endif
#ifndef TIConFrmH
#include "TIConFrm.h"
#endif
#ifndef TIDecH
#include "TIDec.h"
#endif
#ifndef TIFuzzyH
#include "TIFuzzy.h"
#endif
#ifndef TIDelEmpH
#include "TIDelEmp.h"
#endif
#ifndef TISitHirH
#include "TISitHir.h"
#endif
#ifndef TISpecH
#include "TISpec.h"
#endif
#ifndef TIJSONH
#include "TIJSON.h"
#endif
#ifndef TICommonH
#include "TICommon.h"
#endif
#ifndef TNSSAgeH
#include "TNSSAge.h"
#endif
#ifndef TNLoginH
#include "TNLogin.h"
#endif

//---------------------------------------------------------------------------

#pragma package(smart_init)

void __fastcall TTilSpreadSheetForm::ProfGrid1GetEditControl(
	  TProfGrid *Sender, int ACol, int ARow, TWinControl *&AControl)
{
   int AbsCol = ProfGrid1->Cols[ACol]->AbsoluteNumber;
   CurrentRowHeight = ProfGrid1->RowHeights[ProfGrid1->Row];

   if ((AbsCol == 1 || AbsCol == 2) && (ARow == 1 || ARow == 2)) {    // Dataset type
     if (ProfGrid1->AbsoluteCols[1]->Visible)
	   cxComboBox2->Text = ProfGrid1->Cells[1][1]->Text;
	 else
	   cxComboBox2->Text = ProfGrid1->Cells[2][1]->Text;
	 AControl = cxComboBox2;
	 }
   else if (AbsCol == 2 && ARow >= ProfGrid1->FixedRows) {     // Taxa file
	 UnicodeString Code = ProfGrid1->AbsoluteCells[1][ARow]->Value;
	 if (SameText(Code, "#DATA.TYPE"))   // data type
	   AControl = cxComboBox2;
	 else {
	   TaxonName.text = ProfGrid1->AbsoluteCells[2][ARow]->Text;
	   TaxonName.pos = TaxonName.text.Length() + 1;
	   VarBeforeEdit.TaxonName = TaxonName.text;
	   AControl = cxComboBox15;
	   }
	 }
   else if (AbsCol == 3 && ARow >= ProfGrid1->FixedRows) {    // Elements file
	 VarBeforeEdit.Element = ProfGrid1->AbsoluteCells[3][ARow]->Text;
	 cxComboBox3->Properties->Items->Clear();
	 cxComboBox3->Properties->Sorted = true;
	 bool DefaultElements = true;
	 TAXON Taxon;
	 bool TaxonFound = false;
	 if (TaxaLookupOpen) {   // get default elements for taxon
	   int AbsRow = ProfGrid1->Rows[ARow]->AbsoluteNumber;
	   UnicodeString TaxonName = ProfGrid1->AbsoluteCells[2][AbsRow]->Text;
	   if (!TaxonName.IsEmpty()) {
		 if (GetTaxon(ARow, Taxon)) {
		   TaxonFound = true;
		   if (Taxon.Elements.size() > 0) {
			 for (unsigned int i=0; i<Taxon.Elements.size(); i++)
			   cxComboBox3->Properties->Items->Add(Taxon.Elements[i].Name);
			 DefaultElements = false;
			 }
		   }
		 }
	   }

	 if (VarLookup->ElementOpen()) {
	   if (TaxonFound) {
		 if (DefaultElements) {
		   ElementLookup->AssignElements(Datasets[DatasetNum].DatasetType, Taxon.TaxaGroup, cxComboBox3->Properties->Items);
		   }
		 else if (cxComboBox3->Properties->Items->Count > 0) {
		   UnicodeString DatasetType = GenericDatasetType(Datasets[DatasetNum].DatasetType);
		   map<UnicodeString, UnicodeString>::iterator itr = ElementLookup->TaxaGroups.find(Taxon.TaxaGroup);
		   if (itr != ElementLookup->TaxaGroups.end()) {
			 UnicodeString TaxaGroup = LowerCase(itr->second);
			 if (ElementLookup->Elements[DatasetType][TaxaGroup].size() > Taxon.Elements.size()) {
			   cxComboBox3->Properties->Sorted = false;
			   cxComboBox3->Properties->Items->Add(L"more...");
			   }
			 }
		   }
		 }
	   else {
		 ModifierType = MODELEMENT;
		 Label37->Caption = L"Taxa Group:";
		 cxCheckListBox1->ShowChecks = false;
		 cxComboBox12->Properties->Items->Clear();
		 cxCheckListBox1->Items->Clear();
		 UnicodeString DatasetType = GenericDatasetType(Datasets[DatasetNum].DatasetType);
		 vector<UnicodeString> TaxaGroups;
		 ElementLookup->GetTaxaGroups(DatasetType, TaxaGroups);
		 for (unsigned int i=0; i<TaxaGroups.size(); i++)
		   cxComboBox12->Properties->Items->Add(TaxaGroups[i]);
		 if (TaxaGroups.size() > 0) {
		   int Index = cxComboBox12->ItemIndex;
		   cxComboBox12->ItemIndex = cxComboBox12->Properties->Items->IndexOf(CurrentTaxaGroup);
		   if (cxComboBox12->ItemIndex == -1)
			 cxComboBox12->ItemIndex = 0;
		   if (cxComboBox12->ItemIndex == Index)
			 cxComboBox12Click(this);
		   UnicodeString Element = ProfGrid1->AbsoluteCells[AbsCol][ARow]->Text;
		   cxCheckListBox1->ItemIndex = cxCheckListBox1->Items->IndexOf(Element);
		   }
		 AControl = AdvControlDropDown3;
		 }
	   }

	 if (cxComboBox3->Properties->Items->Count > 0) {
	   ProfGrid1->FocusCell(ACol,ARow);
	   cxComboBox3->Text = ProfGrid1->AbsoluteCells[3][ARow]->Value;
	   AControl = cxComboBox3;
	   }
	 }
   else if (AbsCol == 4 && ARow >= ProfGrid1->FixedRows) {    // Units file
	 VarBeforeEdit.Units = ProfGrid1->AbsoluteCells[4][ARow]->Text;
	 cxComboBox4->Properties->Items->Clear();
	 TAXON Taxon;
	 if (TaxaLookupOpen) {
	   int AbsRow = ProfGrid1->Rows[ARow]->AbsoluteNumber;
	   UnicodeString TaxonName = ProfGrid1->AbsoluteCells[2][AbsRow]->Value;
	   if (GetTaxon(TaxonName, Taxon)) {
		 UnicodeString Element = ProfGrid1->AbsoluteCells[3][AbsRow]->Value;
		 for (unsigned int i=0; i<Taxon.Elements.size(); i++) {
		   if (SameText(Taxon.Elements[i].Name, Element)) {
			 if (Taxon.Elements[i].Units.size() > 0) {
			   for (unsigned int j=0; j<Taxon.Elements[i].Units.size(); j++)
				 cxComboBox4->Properties->Items->Add(Taxon.Elements[i].Units[j]);
			   }
			 break;
			 }
		   }
		 }
	   }

	 UnicodeString DatasetType = GenericDatasetType(Datasets[DatasetNum].DatasetType);
	 if (!DatasetType.IsEmpty() && VarLookup->UnitOpen()) {
	   UnitLookup->Assign(DatasetType, cxComboBox4->Properties->Items);
	   }

	 if (cxComboBox4->Properties->Items->Count > 0) {
	   ProfGrid1->FocusCell(ACol,ARow);
	   cxComboBox4->Text = ProfGrid1->AbsoluteCells[4][ARow]->Value;
	   AControl = cxComboBox4;
	   }
	 }
   else if (AbsCol == 5 && ARow >= ProfGrid1->FixedRows) {   // context
	 VarBeforeEdit.Context = ProfGrid1->AbsoluteCells[5][ARow]->Text;
	 cxComboBox5->Properties->Items->Clear();
	 UnicodeString DatasetType = GenericDatasetType(Datasets[DatasetNum].DatasetType);
	 if (!DatasetType.IsEmpty() && VarLookup->ContextOpen())
	   ContextLookup->Assign(DatasetType, cxComboBox5->Properties->Items);
	 if (cxComboBox5->Properties->Items->Count > 0) {
	   ProfGrid1->FocusCell(ACol,ARow);
	   cxComboBox5->Text = ProfGrid1->AbsoluteCells[5][ARow]->Value;
	   AControl = cxComboBox5;
	   }
	 }
   else if (AbsCol == 6 && ARow >= ProfGrid1->FixedRows) {    // Taphonomy file
	 ModifierType = MODTAPH;
	 Label37->Caption = L"Taphonomic System:";
	 cxCheckListBox1->ShowChecks = true;
	 set<UnicodeString> Systems;
	 set<UnicodeString> Types;
	 TaphonomyPosted = false;
	 if (TaphonomyLookup) {
	   cxCheckListBox1->Items->Clear();
	   cxComboBox12->Properties->Items->Clear();
	   TProfGridCell* ACell = ProfGrid1->AbsoluteCells[AbsCol][ARow];

	   CreateTaphSystems(&TempTaphSystems);

	   // determine DatasetType
	   if (ACell->CellObject) {
		 CELLOBJECT* CellObject = (CELLOBJECT*)ACell->CellObject;
		 TAPHSYSTEMS* TaphSystems = (TAPHSYSTEMS*)CellObject->Object;
		 for (unsigned int i=0; i<TaphSystems->Systems.size(); i++) {
		   UnicodeString SystemName = TaphSystems->Systems[i].Name;
		   for (unsigned int j=0; j<TempTaphSystems->Systems.size(); j++) {
			 UnicodeString TempSystemName = TempTaphSystems->Systems[j].Name;
			 if (SameText(TempSystemName, SystemName)) {
			   set<UnicodeString>::iterator itr;
			   set<UnicodeString>::iterator begin = TaphSystems->Systems[i].Types.begin();
			   set<UnicodeString>::iterator end = TaphSystems->Systems[i].Types.end();
			   for (itr = begin; itr != end; itr++)
				 TempTaphSystems->Systems[j].Types.insert(*itr);
			   break;
			   }
			 }
		   }
		 }

	   for (unsigned int i=0; i<TempTaphSystems->Systems.size(); i++)
		 cxComboBox12->Properties->Items->Add(TempTaphSystems->Systems[i].Name);

	   UnicodeString SystemName = L"none";
	   int idx = cxComboBox12->Properties->Items->IndexOf(CurrentTaphSystem);
	   if (idx > -1)
		 SystemName = CurrentTaphSystem;

	   // if CurrentTaphName doesn't have any types, but another system does, switch to that one
	   unsigned int ntypes = 0;
	   for (unsigned int i=0; i<TempTaphSystems->Systems.size(); i++) {
		 if (SameText(TempTaphSystems->Systems[i].Name, SystemName)) {
		   ntypes = TempTaphSystems->Systems[i].Types.size();
		   break;
		   }
		 }
	   if (ntypes == 0) {
		 for (unsigned int i=0; i<TempTaphSystems->Systems.size(); i++) {
		   if (!SameText(TempTaphSystems->Systems[i].Name, SystemName)) {
			 if (TempTaphSystems->Systems[i].Types.size() > 0) {
			   SystemName = TempTaphSystems->Systems[i].Name;
			   break;
			   }
		     }
		   }
		 }

	   cxComboBox12->ItemIndex = cxComboBox12->Properties->Items->IndexOf(SystemName);

	   TaphonomyLookup->GetTypes(TempTaphSystems->DatasetType, SystemName, Types);
       set<UnicodeString>::iterator itr;
	   set<UnicodeString>::iterator begin = Types.begin();
	   set<UnicodeString>::iterator end = Types.end();
	   cxCheckListBox1->Items->BeginUpdate();
	   cxCheckListBox1->Items->Clear();
	   for (itr = begin; itr != end; itr++) {
		 TcxCheckListBoxItem* Item = cxCheckListBox1->Items->Add();
		 Item->Text = *itr;
		 Item->Checked = false;
		 }
	   for (unsigned int i=0; i<TempTaphSystems->Systems.size(); i++) {
		 if (SameText(TempTaphSystems->Systems[i].Name, SystemName)) {
		   begin = TempTaphSystems->Systems[i].Types.begin();
		   end = TempTaphSystems->Systems[i].Types.end();
		   for (itr = begin; itr != end; itr++) {
			 int index = cxCheckListBox1->Items->IndexOf(*itr);
			 if (index > -1) {
			   TcxCheckListBoxItem* Item = cxCheckListBox1->Items->Items[index];
			   Item->Checked = true;
			  }
			 }
		   }
		 }

	   cxCheckListBox1->Items->EndUpdate();
	   AControl = AdvControlDropDown3;
	   }
	 }
   else if (AbsCol == 7 && ARow >= ProfGrid1->FixedRows) {     // Groups
	 AdvControlDropDown4->Text = ProfGrid1->AbsoluteCells[7][ARow]->Text;
	 AControl = AdvControlDropDown4;
	 }
   else if (AbsCol > 7 && ARow >= ProfGrid1->FixedRows) {    // Main part of worksheet
	 UnicodeString Code = ProfGrid1->AbsoluteCells[1][ARow]->Text;
	 Code = Code.UpperCase();
	 if (Code.SubString(1,1) == L"#") {
	   if (SameText(Code.SubString(1,6), L"#SAMP.")) {
		 Code.Delete(1,6);
		 if (SameText(Code, L"ANALYST")) {
		   if (SSContactMetaData(ACol, ARow, L"Analysts"))
			 AControl = cxCheckComboBox5;
		   }
		 else if (SameText(Code, L"DATEANAL"))                    // Date
		   AControl = cxDateEdit2;
		 else if (SameText(Code, L"DATESAMP"))                    // Date
		   AControl = cxDateEdit2;
		 else if (SameText(Code, L"Taxon"))                       // Taxon sampled
		   AControl = cxComboBox15;
		 else if (SameText(Code, L"METHOD") || SameText(Code, L"NOTES")) {
		   cxBlobEdit2->Clear();
		   AControl = cxBlobEdit2;
		   }
		 else if (SameText(Code, L"KEYWORDS")) {
		   vector<UnicodeString> Keywords;
		   UnicodeString KeywordList = ProfGrid1->Cells[ACol][ARow]->Value;
		   ParsePartsIC(KeywordList, L";", Keywords);
		   for (int i=0; i<cxCheckComboBox4->Properties->Items->Count; i++) {
			 cxCheckComboBox4->States[i] = cbsUnchecked;
			 for (unsigned int j=0; j<Keywords.size(); j++) {
			   if (SameText(cxCheckComboBox4->Properties->Items->Items[i]->Description, Keywords[j]))
				 cxCheckComboBox4->States[i] = cbsChecked;
			   }
			 }
		   AControl = cxCheckComboBox4;
		   }
		 }
	   else if (SameText(Code.SubString(1,6), L"#ANAL.")) {
		 Code.Delete(1,6);
		 if (SameText(Code, "FACIES")) {
		   if (FaciesTypes.size() > 0) {
			 cxComboBox6->Properties->Items->Clear();
			 for (unsigned int i=0; i<FaciesTypes.size(); i++)
			   cxComboBox6->Properties->Items->Add(FaciesTypes[i]);
			 AControl = cxComboBox6;
			 }
		   }
		 else if (SameText(Code, "DEPAGENT")) {
		   if (DepAgents.size() > 0) {
			 cxComboBox6->Properties->Items->Clear();
			 for (unsigned int i=0; i<DepAgents.size(); i++)
			   cxComboBox6->Properties->Items->Add(DepAgents[i]);
			 AControl = cxComboBox6;
			 }
		   }
		 else if (SameText(Code, "NOTES")) {
		   cxBlobEdit2->Clear();
		   AControl = cxBlobEdit2;
		   }
		 }
	   else if (SameText(Code.SubString(1,6), L"#SITE.")) {
		 Code.Delete(1,6);
		 if (!SameText(Code.SubString(1,4), L"NAME")) {
		   int SiteRow = FindRowMD(SITE_NAME);
		   if (SiteRow > 0) {
			 if (ProfGrid1->AbsoluteCells[AbsCol][SiteRow]->IsEmpty())
			   SiteRow = 0;
			 }
		   if (!SiteRow) {
			 MessageDlg(L"Site Name must be entered before any other site metadata.",
						Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			 return;
			 }
		   }
		 if (SameText(Code.SubString(1,3), L"LAT")) {
		   LatLongPopup = LATITUDE;
		   AControl = cxPopupEdit3;
		   }
		 else if (SameText(Code.SubString(1,4), L"LONG")) {
		   LatLongPopup = LONGITUDE;
		   AControl = cxPopupEdit3;
		   }
		 else if (SameText(Code, L"GEOPOL1")) {
		   cxComboBox11->Properties->Items->Clear();
		   GeoPolUnits->GeoPol1(cxComboBox11->Properties->Items);
		   AControl = cxComboBox11;
		   }
		 else if (SameText(Code, L"GEOPOL2")) {
		   int row1 = FindRowCodeIC("#SITE.GEOPOL1", ProfGrid1);
		   if (row1) {
			 UnicodeString Country = ProfGrid1->AbsoluteCells[AbsCol][row1]->Value;
			 if (!Country.IsEmpty()) {
			   cxComboBox11->Properties->Items->Clear();
			   GeoPolUnits->SetGeoPolRec1(Country);
			   GeoPolUnits->GeoPol2(Country, cxComboBox11->Properties->Items);
			   AControl = cxComboBox11;
			   }
			 }
		   }
		 else if (SameText(Code, L"GEOPOL3")) {
		   int row1 = FindRowCodeIC("#SITE.GEOPOL1", ProfGrid1);
		   int row2 = FindRowCodeIC("#SITE.GEOPOL2", ProfGrid1);
		   if (row1 && row2) {
			 UnicodeString Country = ProfGrid1->AbsoluteCells[AbsCol][row1]->Value;
			 UnicodeString State = ProfGrid1->AbsoluteCells[AbsCol][row2]->Value;
			 if (!State.IsEmpty()) {
			   cxComboBox11->Properties->Items->Clear();
			   GeoPolUnits->SetGeoPolRec1(Country);
			   GeoPolUnits->GeoPol2(Country, cxComboBox11->Properties->Items);
			   cxComboBox11->Properties->Items->Clear();
			   GeoPolUnits->SetGeoPolRec2(State);
			   GeoPolUnits->GeoPol3(State, cxComboBox11->Properties->Items);
			   AControl = cxComboBox11;
			   }
			 }
		   }
		 else if (SameText(Code, L"ADMIN")) {
		   cxComboBox6->Properties->Items->Clear();
		   int row1 = FindRowCodeIC("#SITE.GEOPOL3", ProfGrid1);
		   UnicodeString County = ProfGrid1->AbsoluteCells[AbsCol][row1]->Value;
		   if (!County.IsEmpty()) {
			 GeoPolUnits->SetGeoPolRec3(County);
			 GeoPolUnits->GeoPol4Unit3(County, cxComboBox6->Properties->Items);
			 }
		   else {
			 row1 = FindRowCodeIC("#SITE.GEOPOL2", ProfGrid1);
			 UnicodeString State = ProfGrid1->AbsoluteCells[AbsCol][row1]->Value;
			 if (!State.IsEmpty()) {
			   GeoPolUnits->SetGeoPolRec2(State);
			   GeoPolUnits->GeoPol4Unit2(State, cxComboBox6->Properties->Items);
			   }
			 else {
			   row1 = FindRowCodeIC("#SITE.GEOPOL1", ProfGrid1);
			   UnicodeString Country = ProfGrid1->AbsoluteCells[AbsCol][row1]->Value;
			   if (!Country.IsEmpty()) {
				 GeoPolUnits->SetGeoPolRec1(Country);
				 GeoPolUnits->GeoPol4Unit1(Country, cxComboBox6->Properties->Items);
				 }
			   }
			 }
		   if (cxComboBox6->Properties->Items->Count)
			 AControl = cxComboBox6;
		   }
		 else if (SameText(Code, L"NOTES")) {
		   cxBlobEdit2->Clear();
		   AControl = cxBlobEdit2;
		   }
		 else if (SameText(Code, L"DESC")) {
           cxBlobEdit2->Clear();
		   AControl = cxBlobEdit2;
           }
		 }
       else if (SameText(Code.SubString(1,6), L"#COLL.")) {
         Code.Delete(1,6);
		 if (SameText(Code, L"NAME")) {
		   InitialCollName = ProfGrid1->AbsoluteCells[AbsCol][ARow]->Text;
		   }
		 else if (SameText(Code, L"TYPE")) {
		   if (cxComboBox1->Properties->Items->Count > 0) {
			 cxComboBox6->Properties->Items->Clear();
			 cxComboBox6->Properties->Items->Assign(cxComboBox1->Properties->Items);
			 AControl = cxComboBox6;
			 }
		   }
		 else if (SameText(Code, L"CONTACTS")) {
		   if (SSContactMetaData(ACol, ARow, L"Collectors"))
			 AControl = cxCheckComboBox5;
		   }
         else if (SameText(Code, L"DATE"))                    // Date
           AControl = cxDateEdit2;
         else if (SameText(Code, L"GPSLAT")) {
		   LatLongPopup = LATITUDE;
           AControl = cxPopupEdit3;
           }
         else if (SameText(Code, L"GPSLONG")) {
           LatLongPopup = LONGITUDE;
           AControl = cxPopupEdit3;
           }
		 else if (SameText(Code, L"DEPENV")) {
		   AControl = dxTreeViewEdit1;
		   UnicodeString Text = ProfGrid1->Cells[ACol][ARow]->Text;
		   for (int i=0; i<dxTreeViewEdit1->Items->Count; i++) {
			 TTreeNode* Node = dxTreeViewEdit1->Items->Item[i];
			 if (SameText(Text,Node->Text)) {
			   dxTreeViewEdit1->Text = Text;
			   break;
			   }
			 }
		   }
		 else if (SameText(Code, L"SUBSTRATE"))
		   AControl = dxTreeViewEdit2;
         else if (SameText(Code, L"ANGLE"))
           AControl = cxPopupEdit13;
         else if (SameText(Code, L"ASPECT"))
           AControl = cxPopupEdit14;
         else if (SameText(Code, L"NOTES")) {
		   cxBlobEdit2->Clear();
           AControl = cxBlobEdit2;
           }
		 }
	   }
     }
   else if (AbsCol == 1 && ARow >= ProfGrid1->FixedRows) {  // metadata items
     if (!cxComboBox7->Text.IsEmpty())
	   GeoPolUnits->GeoPol4Unit1(cxComboBox7->Text, cxComboBox10->Properties->Items);
     }
}
//---------------------------------------------------------------------------

UnicodeString TTilSpreadSheetForm::GenericDatasetType(UnicodeString DatasetType)
{
   UnicodeString genDatasetType;
   for (int i=0; i<cxComboBox2->Properties->Items->Count; i++) {
	 genDatasetType = cxComboBox2->Properties->Items->Strings[i];
	 if (!SameText(DatasetType, genDatasetType)) {
	   if (ContainsText(DatasetType, genDatasetType))
		 return genDatasetType.LowerCase();
	   }
	 }
   return(DatasetType.LowerCase());
}
//---------------------------------------------------------------------------

bool TTilSpreadSheetForm::SSContactMetaData(int ACol, int ARow, UnicodeString ContactType)
{
   cxCheckComboBox5->Properties->Items->Clear();
   if (ContactList->Count == 0) {
	 MessageDlg(ContactType + " must first be entered under the\nContacts tab on the Metadata tabsheet.",
		mtInformation, TMsgDlgButtons() << mbOK, 0);
	 return false;
	 }

   map<UnicodeString,CONTACT*> SortedContacts;
   for (int i=0; i<ContactList->Count; i++) {
	 CONTACT* Contact = ContactList->Contacts[i];
	 SortedContacts[Contact->ShortContactName] = Contact;
	 }

   map<UnicodeString,CONTACT*>::iterator itr;
   for (itr = SortedContacts.begin(); itr != SortedContacts.end(); itr++) {
	 TcxCheckComboBoxItem* Item = cxCheckComboBox5->Properties->Items->AddCheckItem(itr->first,itr->first);
	 Item->Tag = (Longint)itr->second;
	 }

   CELLOBJECT* CellObject = (CELLOBJECT*)ProfGrid1->Cells[ACol][ARow]->CellObject;
   if (CellObject != NULL) {
	 TList* CellContacts= (TList*)CellObject->Object;
	 for (int i=0; i<CellContacts->Count; i++) {
	   CONTACT* Contact1 = (CONTACT*)CellContacts->Items[i];
	   for (int j=0; j <cxCheckComboBox5->Properties->Items->Count; j++) {
		 CONTACT* Contact2 = (CONTACT*)cxCheckComboBox5->Properties->Items->Items[j]->Tag;
		 if (Contact1 == Contact2) {
		   cxCheckComboBox5->States[j] = cbsChecked;
		   break;
		   }
		 }
	   }
	 }
   return true;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxCheckComboBox5PropertiesCloseUp(TObject *Sender)
{
   CELLOBJECT* CellObject;

   TProfGridCell* ACell = ProfGrid1->Cells[ProfGrid1->Col][ProfGrid1->Row];
   if (ACell->CellObject == NULL) {
	 CellObject = new CELLOBJECT(CELLCONTACTS);
	 AddCellObject(ACell, CellObject);
	 }
   else
	 CellObject = (CELLOBJECT*)ACell->CellObject;

   TList* CellContacts = (TList*)CellObject->Object;
   CellContacts->Clear();
   for (int i=0; i < cxCheckComboBox5->Properties->Items->Count; i++) {
	 if (cxCheckComboBox5->States[i] == cbsChecked) {
	   CONTACT* Contact = (CONTACT*)cxCheckComboBox5->Properties->Items->Items[i]->Tag;
	   CellContacts->Add(Contact);
	   }
	 }
}
//---------------------------------------------------------------------------

// find row code ignoring case
// returns 0 if not found
int TTilSpreadSheetForm::FindRowCodeIC(UnicodeString Code, TProfGrid* ProfGrid, int StartRow)
{
   UnicodeString Code1;
   TProfGridColumn* CodeCol = ProfGrid->AbsoluteCols[1];
   int row1 = 0;
   int RowCount = ContentRowCount(ProfGrid);
   for (int row=StartRow; row<=RowCount; row++) {
	 Code1 = CodeCol->AbsoluteCells[row]->Value;
	 if (SameText(Code, Code1)) {
	   row1 = row;
	   break;
	   }
	 }
   return row1;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxPopupEdit3PropertiesPopup(
      TObject *Sender)
{
   double Coordinate;

   dms = new DMSPANEL(this, ToolButton5, ToolButton7, ToolButton8, LabeledEdit16,
         LabeledEdit13, LabeledEdit15, LabeledEdit3, LabeledEdit9, LabeledEdit12,
         ComboBox2);

   TProfGridCell* ACell = ProfGrid1->Cells[ProfGrid1->Col][ProfGrid1->Row];
   cxPopupEdit3->Text = ACell->Text;
   if (ACell->Value.Type() == varDouble)
     Coordinate = ACell->Value;
   else
     Coordinate = NaN;

   dms->initialize(DMSStyle, Coordinate, LatLongPopup);
   LatLongPopupEdit = cxPopupEdit3;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxPopupEdit3PropertiesCloseUp(
      TObject *Sender)
{
   if (cxPopupEdit3->Text.Length() > 0) {
     ProfGrid1->DisableControls();
     double dd;
     TProfGridCell* ACell = ProfGrid1->Cells[ProfGrid1->Col][ProfGrid1->Row];
	 if (TryStrToFloat(cxPopupEdit3->Text, dd))
       ACell->Value = dd;
	 else
	   ACell->Value.ChangeType(varEmpty);
	 ProfGrid1->EnableControls();
     }
   DMSStyle = dms->DMSStyle;
   delete dms;
   dms = NULL;
   ProfGrid1->EditorMode = false;
   ProfGrid1->RowHeights[ProfGrid1->Row] = CurrentRowHeight;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxPopupEdit3Exit(TObject *Sender)
{
   ProfGrid1->RowHeights[ProfGrid1->Row] = CurrentRowHeight;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxDateEdit2Exit(TObject *Sender)
{
   ProfGrid1->RowHeights[ProfGrid1->Row] = CurrentRowHeight;
}
//---------------------------------------------------------------------------

// Dataset Type
void __fastcall TTilSpreadSheetForm::cxComboBox2Exit(TObject *Sender)
{
   UnicodeString OldDataType = ProfGrid1->Selection->Cells[0]->Text;
   UnicodeString NewDataType = cxComboBox2->Text;

   int idx = -1;
   if (ProfGrid1->Row == 1) {    // default DataType
	 Datasets[0].DatasetType = NewDataType;
	 tiGlobals->DatasetType = NewDataType;
	 idx = 0;
	 }
   else if (NewDataType.IsEmpty()) {   // DataType has been blanked
	 for (unsigned int i=1; i<Datasets.size(); i++) {
	   if (SameText(OldDataType, Datasets[i].DatasetType)) {
		 Datasets.erase(Datasets.begin()+i);
		 break;
		 }
	   }
	 }
   else if (OldDataType.IsEmpty()) {     // no DataType defined, add a new DataType
	 DATASET dataset;
	 dataset.DatasetType = NewDataType;
	 Datasets.push_back(dataset);
	 }
   else {                           // DataType has been changed
	 for (unsigned int i=0; i<Datasets.size(); i++) {
	   if (SameText(OldDataType, Datasets[i].DatasetType)) {
		 Datasets[i].DatasetType = NewDataType;
		 idx = i;
		 break;
		 }
	   }
	 }

   if (idx > -1) {
	 if (Downloaded && tiLicense->Type() == verNEOTOMASTEWARD)
	   UpdateDatasetType(Datasets[idx].NeotomaDatasetID, NewDataType);
	 }

   ProfGrid1->RowHeights[ProfGrid1->Row] = CurrentRowHeight;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxComboBox2PropertiesValidate(TObject *Sender,
		  Variant &DisplayValue, TCaption &ErrorText, bool &Error)
{
   bool found = false;
   for (unsigned int i=0; i<Datasets.size(); i++) {
	 if (SameText(VarToStr(DisplayValue), Datasets[0].DatasetType)) {
	   found = true;
	   break;
	   }
	 }
   if (found) {
	 // this will give an error in the debugger, but not otherwise
	 ErrorText = L"Dataset type \"" + DisplayValue + L"\" already exists!";
	 MessageDlg(ErrorText, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 DisplayValue = L"";
	 Error = true;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxComboBox3Exit(TObject *Sender)
{
   ProfGrid1->RowHeights[ProfGrid1->Row] = CurrentRowHeight;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxComboBox4Exit(TObject *Sender)
{
   ProfGrid1->RowHeights[ProfGrid1->Row] = CurrentRowHeight;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxComboBox5Exit(TObject *Sender)
{
   ProfGrid1->RowHeights[ProfGrid1->Row] = CurrentRowHeight;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxComboBox6Exit(TObject *Sender)
{
   ProfGrid1->RowHeights[ProfGrid1->Row] = CurrentRowHeight;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxCheckComboBox4Exit(TObject *Sender)
{
   ProfGrid1->RowHeights[ProfGrid1->Row] = CurrentRowHeight;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxBlobEdit2Exit(TObject *Sender)
{
  ProfGrid1->RowHeights[ProfGrid1->Row] = CurrentRowHeight;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::ProfGrid1CellChanged(
      TProfGrid *Sender, int ACol, int ARow, const WideString OldText,
      WideString &NewText, bool &AllowExit)
{
   if (NewText != OldText) {
#ifdef WHITMORE
	 // if (Datasets[0].WhitmoreID1 != -1) [
	 if (Datasets[0].WhitmoreData) {
	   UnicodeString VarCode = ProfGrid1->AbsoluteCells[1][ARow]->Text;
	   if (SameText(VarCode,L"#Samp.Name")) {
		 NewText = OldText;
		 Beep();
		 return;
		 }
	   }
#endif
	 UNDO undo(CELLSCHANGED, Sender, ACol, ARow);
	 AddUnDo(undo);
	 }
   SpreadSheetChanged = true;

   // ShowMessage(L"Data value changed!");

   if (Downloaded && tiLicense->Type() == verNEOTOMASTEWARD) {
	 int DatasetIdx;
	 if (!ValidateSteward(DatasetIdx))   // TODO: change so that this is done only once
	   return;
	 TProfGridCell* ACell = ProfGrid1->Cells[ACol][ARow];
	 try {
		 if (ACell->AbsoluteCol >= 8 && ACell->AbsoluteRow > 2) {   // data columns
		   Screen->Cursor = crHourGlass;
		   UnicodeString VarCode = ProfGrid1->AbsoluteCells[1][ARow]->Text;
		   if (VarCode[1] == L'#') {   // metadata item
			 if (SameText(VarCode.SubString(2,5),L"Chron"))
			   UpdateSampleAge(VarCode, UnicodeString(NewText), ACell->AbsoluteCol,ACell->AbsoluteRow);
			 else if (SameText(VarCode,L"#Samp.Analyst"))
			   UpdateSampleAnalyst(ACell->AbsoluteCol,ACell->AbsoluteRow);
			 else if (SameText(VarCode,L"#Samp.Keywords"))
			   UpdateSampleKeywords(ACell->AbsoluteCol, ACell->AbsoluteRow, UnicodeString(NewText));
			 else if (SameText(VarCode,L"#Samp.Name"))
			   UpdateSampleName(ACell->AbsoluteCol, ACell->AbsoluteRow, UnicodeString(NewText));
			 else if (SameText(VarCode,L"#Anal.Thick"))
			   UpdateAnalThickness(ACell->AbsoluteCol, ACell->AbsoluteRow, UnicodeString(NewText), mrIgnore);
			 }
		   else {
			 if (ACell->CustomData.IsEmpty()) {  // data value is empty
			   if (MessageDlg(L"Insert data value into Neotoma?", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes)
				 InsertDataValue(ACell->AbsoluteCol, ACell->AbsoluteRow, UnicodeString(NewText));
			   else
				 ACell->Color = TColor(0x00B7B8E6);   // light red
			   }
			 else {  // data value exists
			   if (MessageDlg(L"Update data value in Neotoma?", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes)
				 UpdateDataValue(ACell->AbsoluteCol, ACell->AbsoluteRow, UnicodeString(NewText));
			   else
				 ACell->Color = TColor(0x00ADCBF8);   // light orange
			   }
			 }
		   }
		 else if (ACell->AbsoluteRow == 1 && ACell->AbsoluteCol >= 8) {   // Analysis unit depth row
		   int AnalysisUnitID = ProfGrid1->AbsoluteCells[ACell->AbsoluteCol][2]->CustomData;
		   if (AnalysisUnitID > 0)
			 UpdateAnalysisUnitDepth(ACol, ARow, AnalysisUnitID, UnicodeString(NewText));
		   }
		 else if (ACell->AbsoluteRow == 2 && ACell->AbsoluteCol >= 8) {   // Analysis unit name row
		   int AnalysisUnitID = ProfGrid1->AbsoluteCells[ACell->AbsoluteCol][2]->CustomData;
		   if (AnalysisUnitID > 0)
			 UpdateAnalysisUnitName(ACol, ARow, AnalysisUnitID, UnicodeString(NewText));
		   }
		 }
	 __finally {
		 Screen->Cursor = crDefault;
		 ParentForm->StatusBar1->Panels->Items[0]->Text = L"";
		 }
   }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::ProfGrid1CheckBoxChanged(
      TProfGrid *Sender, int ACol, int ARow, bool Checked)
{
   if (CheckBoxUndoEnabled) {
     UNDO undo(CELLSCHANGED, Sender, ACol, ARow, !Checked);
     AddUnDo(undo);
     }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::ProfGridCellChanged(
      TProfGrid *Sender, int ACol, int ARow, const WideString OldText,
      WideString &NewText, bool &AllowExit)
{
   if (NewText != OldText) {
     UNDO undo(CELLSCHANGED, Sender, ACol, ARow);
     AddUnDo(undo);
     }
   SpreadSheetChanged = true;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::ProfGrid1CellExit(TProfGrid *Sender,
	  int ACol, int ARow)
{
   int AbsCol = ProfGrid1->Cols[ACol]->AbsoluteNumber;

   if (AbsCol > 7 && ARow >= ProfGrid1->FixedRows) {    // Main part of worksheet
	 UnicodeString Code = ProfGrid1->AbsoluteCells[1][ARow]->Value;
	 if (Code.SubString(1,1) == "#") {
	   Code = Code.UpperCase();
	   Variant Value = Sender->Cells[ACol][ARow]->Value;
	   EnterSSMetaData(Code, Value, ACol, ARow);
	   if (Value.IsEmpty())
		 Sender->Cells[ACol][ARow]->Value = Unassigned();
	   }
	 }
   else if (AbsCol > 7 && ARow == 2) {   // 2nd header row
	 if (!HeaderNameEntered) {
	   UnicodeString HeaderType;
	   switch (HeaderRow2) {
		 case ANAL_UNIT_NAME:   HeaderType = L"Analysis Unit name";     break;
		 case COLL_UNIT_NAME:   HeaderType = L"Collection Unit name";   break;
		 case COLL_UNIT_HANDLE: HeaderType = L"Collection Unit handle"; break;
		 case SITE_NAME:        HeaderType = L"Site name";     break;
		 }
	   HeaderNameEntered = true;
	   }
	 if (HeaderRow2 == SITE_NAME) {
	   Variant Value = Sender->Cells[ACol][ARow]->Value;
	   EnterSSSite(Value, ACol, ARow);
	   }
	 else if (HeaderRow2 == COLL_UNIT_NAME) {
	   Variant Value = Sender->Cells[ACol][ARow]->Value;
	   EnterSSCollUnit(Value, ACol, ARow);
	   }
	 }
   else if (AbsCol == 2 && ARow >= ProfGrid1->FixedRows) {    // name column
	 UnicodeString TaxonName = ProfGrid1->AbsoluteCells[AbsCol][ARow]->Text;
	 bool metadataitem = false;
	 UnicodeString TaxonCode = ProfGrid1->AbsoluteCells[1][ARow]->Text;
	 if (!TaxonCode.IsEmpty() && TaxonCode[1] == L'#')
	   metadataitem = true;

	 // if (TaxonName != OriginalTaxonName) [
	 if (TaxonName != VarBeforeEdit.TaxonName) {
	   TAXON Taxon;
	   vector<TAXON>::pointer TaxonPtr = NULL;
	   if (GetTaxon(TaxonName, Taxon)) {
		 TaxonPtr = &Taxon;
		 }
	   else if (Synonyms.size() > 0) {   // check for synonyms
		 map<UnicodeString, int>::iterator itr;
		 if ((itr = Synonyms.find(TaxonName)) != Synonyms.end()) {
		   int TaxonID = itr->second;
		   if (TaxaList.FindID(TaxonID, &TaxonPtr)) {
			 UnicodeString msg = L"Replace \"" + TaxonName + L"\" with prefered synonym \"" +
								 TaxonPtr->Name + L"\"?";
			 if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes) {
			   ProfGrid1->AbsoluteCells[2][ProfGrid1->Row]->Value = TaxonPtr->Name;
			   }
			 }
		   }
		 }

	   if (TaxonPtr != NULL && !metadataitem) {
		 ProfGrid1->AbsoluteCells[1][ARow]->Value = TaxonPtr->Code;
		 ProfGrid1->AbsoluteCells[7][ARow]->Value = TaxonPtr->EcolGroup;
		 if (TaxonPtr->Elements.size() == 1)
		   ProfGrid1->AbsoluteCells[3][ARow]->Value = TaxonPtr->Elements[0].Name;
		 }

	   if (Downloaded && tiLicense->Type() == verNEOTOMASTEWARD)
		 ProfGrid1->AbsoluteCells[ACol][ARow]->Color = TColor(0x00B7B8E6);  // light red
	   SpreadSheetChanged = true;
	   }
	 TProfGridCell* ACell = ProfGrid1->AbsoluteCells[2][ARow];
	 if (ACell->CellObject) {
	   CELLOBJECT* CellObject = (CELLOBJECT*)ACell->CellObject;
	   TAXON_NOTES* TaxonNotes = (TAXON_NOTES*)CellObject->Object;
	   if (ACell->Graphic == NULL && (!TaxonNotes->Notes.IsEmpty() || TaxonNotes->Synonymy.size() > 0))
		 AddTaxonNotesIcon(ACell);
	   }
	 }
   else if (AbsCol == 1 && ARow >= ProfGrid1->FixedRows) {    // code column
	 if (tiGlobals->CodeOptionDups) {
	   bool CaseSensitive = tiGlobals->CodeOptionCase;
       TProfGridColumn* Codes = ProfGrid1->AbsoluteCols[1];
	   UnicodeString NewCode = Codes->Cells[ARow]->Value;
         if (!NewCode.IsEmpty()) {
		 int RowCount = ContentRowCount(ProfGrid1);
		 for (int row=3; row<=RowCount; row++) {
		   if (row == ARow) continue;
		   UnicodeString Code = Codes->Cells[row]->Value;
             bool CodesEqual;
           if (CaseSensitive)
             CodesEqual = (NewCode == Code);
           else
             CodesEqual = (NewCode.UpperCase() == Code.UpperCase());
           if (CodesEqual) {
			 if (MessageDlg("Code \"" + Code + "\" already exists in row " + IntToStr(row) + ".",
                 mtWarning, TMsgDlgButtons() << mbOK << mbIgnore, 0) == mrOk) {
               Codes->Cells[ARow]->Value.Clear();
               }
             break;
             }
		   }
         }
       }
	 UnicodeString Code = ProfGrid1->AbsoluteCells[1][ARow]->Value;
	 // if (SameText(Code, L"#SAMP.MODERN") || SameText(Code, L"#ANAL.MIXED")) [
	 if (SameText(Code, L"#ANAL.MIXED")) {
	   int StartCol = AbsHeaderColCount(ProfGrid1);
	   int EndCol = ProfGrid1->AbsoluteColCount;
	   for (int col=StartCol; col<EndCol; col++) {
		 TProfGridCell *ACell = ProfGrid1->AbsoluteCells[col][ARow];
		 UnicodeString bVal = ACell->Value;
		 bool checked = (bVal == "1");
		 ACell->Value.Clear();
		 ACell->CheckBox = true;
		 ACell->CheckBoxChecked = checked;
		 }
	   }
	 }
   else if (AbsCol == 3 && ARow >= ProfGrid1->FixedRows) {    // element column
	 if (Downloaded && tiLicense->Type() == verNEOTOMASTEWARD) {
	   UnicodeString Element = ProfGrid1->AbsoluteCells[AbsCol][ARow]->Text;
	   if (!SameText(Element, VarBeforeEdit.Element)) {
		 ProfGrid1->AbsoluteCells[AbsCol][ARow]->Color = TColor(0x00B7B8E6);  // light red
		 SpreadSheetChanged = true;
		 }
	   }
	 }
   else if (AbsCol == 4 && ARow >= ProfGrid1->FixedRows) {    // units column
	 if (Downloaded && tiLicense->Type() == verNEOTOMASTEWARD) {
	   UnicodeString Units = ProfGrid1->AbsoluteCells[AbsCol][ARow]->Text;
	   if (!SameText(Units, VarBeforeEdit.Units)) {
		 ProfGrid1->AbsoluteCells[AbsCol][ARow]->Color = TColor(0x00B7B8E6);  // light red
		 SpreadSheetChanged = true;
		 }
	   }
	 }
   else if (AbsCol == 5 && ARow >= ProfGrid1->FixedRows) {    // context column
	 if (Downloaded && tiLicense->Type() == verNEOTOMASTEWARD) {
	   UnicodeString Context = ProfGrid1->AbsoluteCells[AbsCol][ARow]->Text;
	   if (!SameText(Context, VarBeforeEdit.Context)) {
		 ProfGrid1->AbsoluteCells[AbsCol][ARow]->Color = TColor(0x00B7B8E6);  // light red
		 SpreadSheetChanged = true;
		 }
	   }
	 }
   else if (AbsCol == 6 && ARow >= ProfGrid1->FixedRows) {    // taphonomy column
	 if (TaphStatus != TAPHCANCELED && !TaphonomyPosted) {
	   TAPHSYSTEMS* TaphSystems;
	   TProfGridCell* ACell = Sender->AbsoluteCells[AbsCol][ARow];
	   UnicodeString Text = ACell->Text;
	   if (ACell->CellObject != NULL) {
		 CELLOBJECT* CellObject = (CELLOBJECT*)ACell->CellObject;
		 TaphSystems = (TAPHSYSTEMS*)CellObject->Object;
		 DeleteCellObject(ACell);
		 }
	   if (!Text.IsEmpty()) {
		 // FAUNMAP:burned;butchered|Behrensmeyer:Stage1
		 if (TaphonomyLookup == NULL) {
		   TaphonomyLookup = new TAPHONOMYLOOKUP;
		   VarLookup->SetTaphonomyLookup(TaphonomyLookup);
		   }
		 TaphSystems = NULL;
		 CreateTaphSystems(&TaphSystems);
		 vector<UnicodeString> Systems;
		 ParsePartsIC(Text, L"|", Systems);
		 for (unsigned int i=0; i<Systems.size(); i++) {
		   UnicodeString SystemName = L"none";  // default name
		   int pos = Systems[i].Pos(L":");
		   if (pos > 0) {
			 SystemName = Systems[i].SubString(1,pos-1).TrimLeft();
			 Systems[i].Delete(1,pos);
			 }

		   if (!TaphonomyLookup->SystemExists(TaphSystems->DatasetType, SystemName)) {
			 TaphonomyLookup->Add(TaphSystems->DatasetType, SystemName);
			 if (TaphonomyLookup->IsLoaded) {
			   UnicodeString msg = L"Taphonomic system «" + SystemName +
				 L"» is not in lookup file.\nAdd to lookup file?";
			   if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes) {
				 UnicodeString PathName = TaphonomyLookup->GetPathName();
				 SaveVariableModifiers(MOD_TAPHONOMY, PathName, VarLookup, this);
				 }
			   }
			 }

		   int idx = -1;
		   for (unsigned int j=0; j<TaphSystems->Systems.size(); j++) {
			 if (SameText(TaphSystems->Systems[j].Name, SystemName)) {
			   idx = j;
			   break;
			   }
			 }
		   if (idx == -1) {
			 TAPHSYSTEM TaphSystem;
			 TaphSystem.Name = SystemName;
			 TaphSystems->Systems.push_back(TaphSystem);
			 idx = TaphSystems->Systems.size() - 1;
			 }

		   vector<UnicodeString> Types;
		   ParsePartsIC(Systems[i], L";", Types);
		   for (unsigned int j=0; j<Types.size(); j++) {
			 if (!TaphonomyLookup->TypeExists(TaphSystems->DatasetType, SystemName, Types[j])) {
			   TaphonomyLookup->Add(TaphSystems->DatasetType, SystemName, Types[j]);
			   if (TaphonomyLookup->IsLoaded) {
				 UnicodeString msg = L"Taphonomic type «" + Types[j] + L"» in system «" +
				   SystemName + L"» is not in lookup file.\nAdd to lookup file?";
				 if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes) {
				   UnicodeString PathName = TaphonomyLookup->GetPathName();
				   SaveVariableModifiers(MOD_TAPHONOMY, PathName, VarLookup, this);
				   }
				 }
			   }
			 TaphSystems->Systems[idx].Types.insert(Types[j]);
			 }
		   CurrentTaphSystem = SystemName;
		   }
		 ACell->Value = TaphSystems->Text();
		 CELLOBJECT* CellObject = new CELLOBJECT(TaphSystems);
		 AddCellObject(ACell, CellObject);
		 }
	   }
	 delete TempTaphSystems;
	 TempTaphSystems = NULL;
	 }
}
//---------------------------------------------------------------------------

bool TTilSpreadSheetForm::UniqueCollUnitHandle(SITE* site_ptr, UnicodeString Handle, UnicodeString Name, int CurCol, int SiteRow)
{
   int NameRow;
   int HandleRow;

   if (Name.IsEmpty() || Handle.IsEmpty())
	 return 0;
   if ((NameRow = FindRowMD(COLL_UNIT_NAME)) == 0)
	 return true;
   if ((HandleRow = FindRowMD(COLL_UNIT_HANDLE)) == 0)
	 return true;

   int StartCol = AbsHeaderColCount(ProfGrid1);
   int EndCol = AbsContentColCount(ProfGrid1);
   SITE* col_site_ptr;
   int Col = StartCol;
   while ((col_site_ptr = GetNextColSitePtr(CurCol, Col, EndCol, SiteRow)) != NULL) {
	 if (col_site_ptr == site_ptr) {
	   UnicodeString ColName = ProfGrid1->AbsoluteCells[Col][NameRow]->Text;
	   UnicodeString ColHandle = ProfGrid1->AbsoluteCells[Col][HandleRow]->Text;
	   if (!ColName.IsEmpty() && !ColHandle.IsEmpty()) {
		 if ((SameText(Name, ColName) && !SameText(Handle, ColHandle)) ||
			 (SameText(Handle, ColHandle) && !SameText(Name, ColName))) {
		   UnicodeString msg = L"Collection Unit Name \"" + Name + L"\" and Handle \"" +
			 Handle + L"\" conflicts with Name and Handle in column " +
			 ProfGrid1->AbsoluteCols[Col]->A1Name + L".";
		   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK << mbCancel, 0);
		   return false;
		   }
		 }
	   }
	 Col++;
	 }
   return true;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::ProfGrid1KeyDown(TObject *Sender,
	  WORD &Key, TShiftState Shift)
{
   SSAction = SSKEY;
   if (EndKey) {
	 if (ProcessEndKey(Key, ProfGrid1))
       return;
     }
   if (Key == VK_END) {
     EndKey = true;
     Key = NULL;
	 }
   else if ((Key == 'R' || Key == 'r') && Shift.Contains(ssCtrl))
	 MarkRareTypes(ProfGrid1);
   else if ((Key == 'X' || Key == 'x') && Shift.Contains(ssCtrl)) {
	 if (!CheckSelectionCut(ProfGrid1->Selection)) {
	   Key = NULL;
	   return;
	   }
	 }

   TProfGridCell* ACell = ProfGrid1->Cells[ProfGrid1->Col][ProfGrid1->Row];
   if (ACell->CheckBox) {
	 switch (Key) {
	   case 'T':
	   case 't':
	   case 'Y':
	   case 'y':
		 ACell->CheckBoxChecked = true;
		 break;
	   case 'F':
	   case 'f':
	   case 'N':
	   case 'n':
		 ACell->CheckBoxChecked = false;
		 break;
	   }
     }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::ProfGrid2KeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
   if (EndKey) {
     if (ProcessEndKey(Key, ProfGrid2))
       return;
     }
   if (Key == VK_END) {
     EndKey = true;
     Key = NULL;
     }
}
//---------------------------------------------------------------------------

// generic OnKeyDown event for dynamically created worksheets
void __fastcall TTilSpreadSheetForm::ProfGridKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
   if (EndKey) {
     if (ProcessEndKey(Key, (TProfGrid*)Sender))
       return;
     }
   if (Key == VK_END) {
     EndKey = true;
     Key = NULL;
     }
}
//---------------------------------------------------------------------------

bool __fastcall TTilSpreadSheetForm::ProcessEndKey(WORD &Key, TProfGrid* ProfGrid)
{
   EndKey = false;
   switch (Key) {
     case VK_RIGHT:
	   ProfGrid->Col = ContentColCount(ProfGrid);
       Key = NULL;
       break;
     case VK_LEFT:
       ProfGrid->Col = (ProfGrid->Row < ProfGrid->FixedRows) ? ProfGrid->FixedCols : 1;
       Key = NULL;
       break;
     case VK_DOWN:
       ProfGrid->Row = ContentRowCount(ProfGrid);
       Key = NULL;
       break;
     case VK_UP:
       ProfGrid->Row = (ProfGrid->Col < ProfGrid->FixedCols) ? ProfGrid->FixedRows : 1;
       Key = NULL;
       break;
     };
   return (Key == NULL);   // true if Key == NULL
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::ProfGrid1MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
   SSAction = SSMOUSE;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::ProfGrid1Click(TObject *Sender)
{
   SetDatasetNum();
   ProfGrid1->SelectionFontColor = clWindowText;
   switch (ProfGrid1->Cols[ProfGrid1->Col]->AbsoluteNumber) {
     case 1:  // Code
	   ProfGrid1->PopupMenu = PopupMenuCodes;
       break;
     case 2:  // Name
	   ProfGrid1->PopupMenu = PopupMenu9;
       break;
     case 3:  // Element
       ProfGrid1->PopupMenu = PopupMenu3;
       break;
     case 4:  // Units
       ProfGrid1->PopupMenu = PopupMenu4;
       break;
     case 5:  // Context
       ProfGrid1->PopupMenu = PopupMenu5;
       break;
	 case 6:  // Taphonomy
       ProfGrid1->PopupMenu = PopupMenu6;
       break;
     case 7:  // Group
       ProfGrid1->PopupMenu = PopupMenu7;
       break;
     default:
       ProfGrid1->PopupMenu = PopupMenu1;
       break;
     }
}
//---------------------------------------------------------------------------

TProfGrid* __fastcall TTilSpreadSheetForm::ProfGrid(void)
{
   return Workbook->Sheets[cxPageControl1->ActivePage];
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::PopupMenu1Popup(TObject *Sender)
{
   TMenuItem* MenuItem;
   int Index;

   if (cxPageControl1->ActivePage == cxTabSheet1) {
	 if (ProfGrid1->Cols[ProfGrid1->Col]->AbsoluteNumber >= AbsHeaderColCount(ProfGrid1) &&
		 ProfGrid1->Row < ProfGrid1->FixedRows) {  // header rows
	   Format1->Visible = false;
	   DataType1->Visible = (ProfGrid1->Row == 2);
	   RareType1->Visible = false;
	   ShowNeotomaIDs1->Visible = false;
	   Specimens1->Visible = false;
#ifdef WHITMORE
	   WhitmoreTasks1->Visible = false;
	   // WhitmoreTasks1->Visible = (Datasets[0].WhitmoreData && ProfGrid1->Row == 2);
#endif
	   }
	 else {
	   UnicodeString VarCode = ProfGrid1->AbsoluteCells[1][ProfGrid1->Row]->Text;
	   bool MetadataRow = (!VarCode.IsEmpty() && VarCode[1] == L'#');
	   bool SampNameRow = SameText(VarCode,L"#Samp.Name");

	   Format1->Visible = true;
	   DataType1->Visible = false;
	   WhitmoreTasks1->Visible = false;
	   ShowNeotomaIDs1->Visible = false;
	   if (Downloaded && !ProfGrid1->Cells[ProfGrid1->Col][ProfGrid1->Row]->Text.IsEmpty()) {
		 UnicodeString VarCode = ProfGrid1->Cells[1][ProfGrid1->Row]->Text;
		 if (!MetadataRow)
		   ShowNeotomaIDs1->Visible = true;
		 }
	   RareType1->Visible = (!MetadataRow && ProfGrid1->Col >= ProfGrid1->FixedCols &&
							 ProfGrid1->Row >= ProfGrid1->FixedRows);
	   Specimens1->Visible = (!MetadataRow && !ProfGrid1->Cells[ProfGrid1->Col][ProfGrid1->Row]->Text.IsEmpty());
#ifdef WHITMORE
	   WhitmoreTasks1->Visible = (SampNameRow && Datasets[0].WhitmoreData);
#endif
	   }
	 }
   else {
	 RareType1->Visible = false;
	 Specimens1->Visible = false;
	 ShowNeotomaIDs1->Visible = false;
	 WhitmoreTasks1->Visible = false;
     }
}
//---------------------------------------------------------------------------

// for current DatasetType (Datasets[DatasetNum].DatasetType), get the list
// of TaxaGroups for elements and assign them as popup menu options
void __fastcall TTilSpreadSheetForm::PopupMenu3Popup(TObject *Sender)
{
   BuildElement3->Visible = (TaxaLookupOpen && VarLookup->ElementOpen());
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::PopupMenu7Popup(TObject *Sender)
{
   EditGroups1->Visible = (TaxaEcolGroups.size() > 0);
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::PopupMenu9Popup(TObject *Sender)
{
   EditTaxa1->Visible = (TaxaList.size() > 0);

   TProfGridCell* ACell = ProfGrid1->AbsoluteCells[2][ProfGrid1->Row];
   if (ACell->CellObject != NULL) {
	 CELLOBJECT* CellObject = (CELLOBJECT*)ACell->CellObject;
	 TAXON_NOTES *TaxonNotes = (TAXON_NOTES*)CellObject->Object;
	 Synonyms1->ImageIndex = (TaxonNotes->Synonymy.size() > 0) ? 44 : -1;
	 TaxonNotes1->ImageIndex = (TaxonNotes->Notes.IsEmpty()) ? -1 : 44;
	 }
   else {
	 Synonyms1->ImageIndex = -1;
	 TaxonNotes1->ImageIndex = -1;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxComboBox3Click(TObject *Sender)
{
   if (cxComboBox3->ItemIndex == -1) return;
   if (cxComboBox3->Properties->Items->Strings[cxComboBox3->ItemIndex] == L"more...") {
	 TAXON Taxon;
	 if (GetTaxon(ProfGrid1->Row, Taxon)) {
	   UnicodeString TaxaGroup = ElementLookup->TaxaGroups[Taxon.TaxaGroup];
	   cxComboBox3->Properties->BeginUpdate();
	   cxComboBox3->Properties->Sorted = true;
	   UnicodeString DatasetType = GenericDatasetType(Datasets[DatasetNum].DatasetType);
	   ElementLookup->AssignElements(DatasetType, TaxaGroup, cxComboBox3->Properties->Items);
	   MoreElements = true;
	   }
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxComboBox3PropertiesCloseUp(TObject *Sender)
{
   if (MoreElements) {
	 cxComboBox3->DroppedDown = true;
	 cxComboBox3->Clear();
	 cxComboBox3->Properties->EndUpdate();
	 MoreElements = false;
	 }
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::VariableLookup(void)
{
   //UnicodeString XPath;
   //UnicodeString AttrValue;
   UnicodeString Name, Code, EcolGroup, Text;
   //UnicodeString LookupPath;
   UnicodeString TaxaFile, ElementsFile, UnitsFile, ContextFile, TaphonomyFile;
   int ID, HigherID;

   VarLookupForm = new TVarLookupForm(this);

   if (VarLookupForm->ShowModal() == mrOk) {
	 Repaint();
	 TaxaFile = VarLookupForm->cxTextEdit1->Text;
	 ElementsFile = VarLookupForm->cxTextEdit2->Text;
	 UnitsFile = VarLookupForm->cxTextEdit3->Text;
	 ContextFile = VarLookupForm->cxTextEdit4->Text;
	 TaphonomyFile = VarLookupForm->cxTextEdit5->Text;
	 Screen->Cursor = crHourGlass;

	 // ---------------------------
	 if (!TaxaFile.IsEmpty()) {
	   txml = new TAXAXML();
	   ParseTaxa = new PARSETAXA(ipwXMLp6, this);
	   bool rv = ParseTaxa->Parse(TaxaFile);
	   delete txml;

	   TaxaEcolGroups.clear();
	   TaxaEcolGroups = ParseTaxa->TaxaEcolGroups;

	   TaxaList = ParseTaxa->TaxaList;
	   Synonyms.clear();
	   Synonyms = ParseTaxa->Synonyms;

	   map<UnicodeString, int>::iterator itr;
	   for (itr=Synonyms.begin(); itr != Synonyms.end(); itr++)
		 MultiSynonyms.insert( pair<int, UnicodeString>(itr->second, itr->first));

	   GroupLookup = false;

	   if (rv && TaxaList.size() > 0) {
		 cxComboBox15->Properties->Items->BeginUpdate();
		 cxComboBox15->Clear();
		 cxComboBox15->Properties->Items->Clear();
		 for (unsigned int i=0; i<TaxaList.size(); i++) {
		   cxComboBox15->Properties->Items->Add(TaxaList[i].Name);
		   }
		 cxComboBox15->Properties->Items->EndUpdate();

		 // populate taxa list for geochronology grid
		 if (!GeochronTaxaOpen) {
		   TcxComboBoxProperties* TaxaDated = (TcxComboBoxProperties*)(txTaxon->Properties);
		   TaxaDated->Items->BeginUpdate();
		   TaxaDated->Items->Clear();
		   for (unsigned int i=0; i<TaxaList.size(); i++)
			 TaxaDated->Items->Add(TaxaList[i].Name);
		   TaxaDated->Items->EndUpdate();
		   }

		 tiGlobals->TaxaFile = ExtractFileName(TaxaFile);
		 TaxaLookupOpen = true;
		 }
	   else {
		 TaxaLookupOpen = false;
		 GroupLookup = false;
		 }
	   delete ParseTaxa;
	   CurrentTaxaFile.SetLength(0);
	   }
	 else {
	   TaxaLookupOpen = false;
       GroupLookup = false;
       }
     // ---------------------------

	 if (!ElementsFile.IsEmpty()) {
	   if (ElementLookup) {
		 delete ElementLookup;
         ElementLookup = NULL;
		 VarLookup->SetElementLookup(NULL);
		 }
       ElementLookup = new ELEMENTLOOKUP(TaxaEcolGroups);
	   if (ElementLookup->Load(ElementsFile, ipwXMLp1, false)) {
		 VarLookup->SetElementLookup(ElementLookup);
		 // populate TaxaGroups list for geochronology grid
		 vector<UnicodeString> DatasetTypes;
		 ElementLookup->GetDatasetTypes(DatasetTypes);
		 }
	   else {
		 delete ElementLookup;
		 ElementLookup = NULL;
		 VarLookup->SetElementLookup(NULL);
         }
       }
     // ---------------------------

	 if (!UnitsFile.IsEmpty()) {
	   if (UnitLookup) {
		 delete UnitLookup;
         UnitLookup = NULL;
		 VarLookup->SetUnitLookup(NULL);
         }
	   if (UnitsFile != ElementsFile) {
		 UnitLookup = new UNITLOOKUP;
         if (UnitLookup->Load(UnitsFile, ipwXMLp1, false))
           VarLookup->SetUnitLookup(UnitLookup);
         else {
		   delete UnitLookup;
           UnitLookup = NULL;
           VarLookup->SetUnitLookup(NULL);
           }
         }
       else if (SameText(UnitsFile, ElementsFile) && VarLookup->ElementOpen()) {
         UnitLookup = new UNITLOOKUP;
         if (UnitLookup->Load(UnitsFile, ipwXMLp1, true))
           VarLookup->SetUnitLookup(UnitLookup);
         else {
           delete UnitLookup;
           UnitLookup = NULL;
           VarLookup->SetUnitLookup(NULL);
           }
         }
       }
	 // ---------------------------

     if (!ContextFile.IsEmpty()) {
       if (ContextLookup) {
         delete ContextLookup;
         ContextLookup = NULL;
         VarLookup->SetContextLookup(NULL);
         }
       if (ContextFile != UnitsFile) {
         ContextLookup = new CONTEXTLOOKUP;
         if (ContextLookup->Load(ContextFile, ipwXMLp1, false))
           VarLookup->SetContextLookup(ContextLookup);
         else {
           delete ContextLookup;
           ContextLookup = NULL;
           VarLookup->SetContextLookup(NULL);
           }
         }
       else if (SameText(ContextFile, UnitsFile) && VarLookup->UnitOpen()) {
         ContextLookup = new CONTEXTLOOKUP;
         if (ContextLookup->Load(ContextFile, ipwXMLp1, true))
           VarLookup->SetContextLookup(ContextLookup);
         else {
           delete ContextLookup;
           ContextLookup = NULL;
           VarLookup->SetContextLookup(NULL);
           }
         }
       }
	 // ---------------------------
	 //typedef map<UnicodeString, set<UnicodeString> > TAPHONOMICSYSTEM;
	 //map<UnicodeString, TAPHONOMICSYSTEM> DatasetType;
	 // DatasetType[vertebrate fauna][none]

	 if (!TaphonomyFile.IsEmpty()) {
	   if (TaphonomyLookup) {
		 delete TaphonomyLookup;
		 TaphonomyLookup = NULL;
		 VarLookup->SetTaphonomyLookup(NULL);
		 }
	   if (TaphonomyFile != ContextFile) {
		 TaphonomyLookup = new TAPHONOMYLOOKUP;
         if (TaphonomyLookup->Load(TaphonomyFile, ipwXMLp1, false))
           VarLookup->SetTaphonomyLookup(TaphonomyLookup);
         else {
           delete TaphonomyLookup;
		   TaphonomyLookup = NULL;
           VarLookup->SetTaphonomyLookup(NULL);
           }
         }
	   else if (SameText(TaphonomyFile, ContextFile) && VarLookup->ContextOpen()) {
		 TaphonomyLookup = new TAPHONOMYLOOKUP;
		 if (TaphonomyLookup->Load(TaphonomyFile, ipwXMLp1, true))
		   VarLookup->SetTaphonomyLookup(TaphonomyLookup);
		 else {
		   delete TaphonomyLookup;
		   TaphonomyLookup = NULL;
		   VarLookup->SetTaphonomyLookup(NULL);
		   }
		 }
	   if (TaphonomyLookup != NULL)
		 CheckTaphonomy();
	   }
     // ---------------------------
     }

   tiGlobals->TaxaFile = (TaxaLookupOpen) ? ExtractFileName(TaxaFile) : EmptyStr;
   tiGlobals->ElementsFile = (VarLookup->ElementOpen()) ?  ExtractFileName(ElementsFile) : EmptyStr;
   tiGlobals->UnitsFile = (VarLookup->UnitOpen()) ? ExtractFileName(UnitsFile) : EmptyStr;
   tiGlobals->ContextFile = (VarLookup->ContextOpen()) ? ExtractFileName(ContextFile) : EmptyStr;
   tiGlobals->TaphonomyFile = (VarLookup->TaphonomyOpen()) ? ExtractFileName(TaphonomyFile) : EmptyStr;
   delete VarLookupForm;
   Screen->Cursor = crDefault;
}
//---------------------------------------------------------------------------

// change data worksheets
void __fastcall TTilSpreadSheetForm::cxPageControl1Change(TObject *Sender)
{
   TProfGrid* ProfGrid;
   TProfGridSpreadsheetOptions SSOptions;

   EndKey = false;

   ParentForm->ActivateSpreadsheetMenu(true, PageControl1, cxPageControl1, PageControl2);

   // The following code adds the ability to form formulas with the mouse
   // by setting the soMouseBuildUpFormula value for the active sheet, except
   // the Data sheet. For some reason soMouseBuildUpFormula cannot be set
   // beforehand except for ProfGrid1. If set, the program crashes.

   // remove soMouseBuildUpFormula from inactive grids
   for (int i=1; i<cxPageControl1->PageCount; i++) {
     if (cxPageControl1->Pages[i] != cxPageControl1->ActivePage) {
       ProfGrid = Workbook->Sheets[cxPageControl1->Pages[i]];
       SSOptions = ProfGrid->SpreadsheetOptions;
       if (SSOptions.Contains(soMouseBuildUpFormula)) {
         SSOptions >> soMouseBuildUpFormula;                       // remove
         ProfGrid->SpreadsheetOptions = SSOptions;
         }
       }
     }
   // add soMouseBuildUpFormula to active grid
   ProfGrid = Workbook->Sheets[cxPageControl1->ActivePage];
   SSOptions = ProfGrid->SpreadsheetOptions;
   if (!SSOptions.Contains(soMouseBuildUpFormula)) {
     SSOptions << soMouseBuildUpFormula;                           // add
     ProfGrid->SpreadsheetOptions = SSOptions;
     }
}
//---------------------------------------------------------------------------

// Change between Data and Metadata tabsheets
void __fastcall TTilSpreadSheetForm::PageControl1Changing(TObject *Sender, bool &AllowChange)
{
   if (PageControl1->ActivePage == TabSheet2) {         // back to data tabsheet
	 if (SitePtr) {
	   bool site_deleted = false;
	   if (TabSheetSite->TabVisible && Sites->Count > 1 && Edit1->Text.IsEmpty()) {
		 if (MessageDlg("Site name has been deleted. Click \"Ok\" to delete site from spreadsheet.",
			 mtConfirmation, TMsgDlgButtons() << mbOK << mbCancel, 0) == mrCancel)
		   AllowChange = false;
		 else
		   site_deleted = true;
		 }
	   if (TabSheetCollectionUnit->TabVisible && CollPtr && LabeledEdit5->Text.IsEmpty() &&
		   AllowChange && !site_deleted && SitePtr->CollUnits.size() > 1) {
		 if (MessageDlg("Collection unit name has been deleted. Click \"Ok\" to delete collection unit from spreadsheet.",
			 mtConfirmation, TMsgDlgButtons() << mbOK << mbCancel, 0) == mrCancel)
		   AllowChange = false;
		 }
	   }
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::PageControl1Change(TObject *Sender)
{
   ParentForm->ActivateSpreadsheetMenu(true, PageControl1, cxPageControl1, PageControl2);

   if (PageControl1->ActivePage == TabSheet1) {         // back to data tabsheet
	 int site_row;
	 SITE* site_ptr = GetSSSitePtr(ProfGrid1->Col, site_row);
	 if (site_ptr != NULL) {   // multi-site spreadsheet
	   int update_col;
	   if (CurrSS.SiteCol > 0) {
		 update_col = CurrSS.SiteCol;
		 }
	   else {
		 update_col = ProfGrid1->Cols[ProfGrid1->Col]->AbsoluteNumber;
		 }
	   SiteMetaDataToSS(update_col);

	   if (CollPtr && site_ptr->CollUnits.size() > 1) {
		 int HandleRow = FindRowMD(COLL_UNIT_HANDLE);
		 if (HandleRow > 0) {
		   CollUnitMetaDataToSS(update_col);
		   }
		 }
	   int CurrSSVisCol = ProfGrid1->AbsoluteCols[CurrSS.SiteCol]->VisibleNumber;
	   if (CurrSSVisCol != ProfGrid1->Col)
		 ProfGrid1->Col = CurrSSVisCol;
	   }
	 else {
	   if (SitePtr && CollPtr && SitePtr->CollUnits.size() > 1) {  // single site, multi-collection unit spreadsheet
		 for (unsigned int i=1; i<SitePtr->CollUnits.size(); i++) {
		   if (CollPtr == &SitePtr->CollUnits[i]) {
			 int ACol = ProfGrid1->Cols[ProfGrid1->Col]->AbsoluteNumber;
			 CollUnitMetaDataToSS(ACol);
			 break;
			 }
		   }
		 }
	   }
	 }
   else if (PageControl1->ActivePage == TabSheet2) {    // to metadata tabsheet
	 if (NewAgeModels) {
	   if (PageControl2->ActivePage == TabSheetAgeModels) {
		 FocusControl(cxGrid3);
		 cxGrid3TableView1->Controller->FocusedItem = amAgeModel;
		 for (int i=cxGrid3TableView1->DataController->RecordCount-1; i>=0; i--)
		   cxGrid3TableView1->Controller->FocusedRecordIndex = i;
		 }
	   NewAgeModels = false;
	   }

	 UnicodeString DatasetType = ProfGrid1->AbsoluteCells[1][1]->Text;
	 bool visible = false;
	 if (ContainsText(DatasetType,L"surface") && AbsContentColCount(ProfGrid1) == 8) {
	   if (Sites->Count == 1) {
		 SITE *Site = (SITE*)Sites->Items[0];
		 if (Site->CollUnits.size() ==  1) {
		   bool found = false;
		   for (int i=0; i<AgeModelList->Count; i++) {
			 AGEMODEL* AgeModel = AgeModelList->AgeModels[i];
			 if (SameText(AgeModel->AgeModel,L"collection date")) {
			   found = true;
			   break;
			   }
			 }
		   if (!found)
			 visible = true;
		   }
		 }
	   }
	 cxButton39->Visible = visible;

	 // Hide Site and CollectionUnit tabsheets if #Site.Name exists in Data sheet
	 // and selection is more than one column
	 int SSCol = ProfGrid1->Col;
	 TabSheetSite->TabVisible = true;
	 TabSheetCollectionUnit->TabVisible = true;
	 if (ProfGrid1->Selection->Count > 1) {
	   SSCol = ProfGrid1->Selection->Rect.Left;
	   if (ProfGrid1->Selection->Rect.Right > SSCol) {
		 if (FindRowMD(SITE_NAME)) {
		   TabSheetSite->TabVisible = false;
		   TabSheetCollectionUnit->TabVisible = false;
		   }
		 else if (FindRowMD(COLL_UNIT_NAME))
		   TabSheetCollectionUnit->TabVisible = false;
		 }
	   }

	 // default SitePtr
	 SitePtr = (SITE*)Sites->Items[0];
	 bool DefaultSite = false;

	 if (TabSheetSite->TabVisible) {
	   CurrSS.MultiSite = false;
	   CurrSS.SiteCol = 0;
	   CurrSS.SiteRow = 0;
	   CurrSS.FirstCol = 0;
	   CurrSS.LastCol = 0;
	   FlowPanel2->Visible = false;
	   int site_row = FindRowMD(SITE_NAME);
	   if (Sites->Count == 1) { // default single site
		 // if only a default single site, check that an empty #Site.Name
		 // doesn't exist in Data sheet. If it does, hide Site tabsheet.
		 if (site_row == 0) {     // single site, no #Site.Name in SS
		   FillSiteMetaData(SitePtr);
		   DefaultSite = true;
		   }
		 else                   // #Site.Name in SS
		   TabSheetSite->TabVisible = false;
		 }
	   else {   // SS sites exist
		 if (Sites->Count > 1) {   // do not allow editing of site or coll unit names
		   Edit1->Enabled = false;
		   LabeledEdit4->Enabled = false;
		   LabeledEdit5->Enabled = false;
		   }
		 TProfGridCell *ACell = ProfGrid1->Cells[SSCol][site_row];
		 bool SiteTabVisible = false;
		 if (ACell->CellObject) {         // #Site.Name/Object exist
		   CELLOBJECT* CellObject = (CELLOBJECT*)ACell->CellObject;
		   if (CellObject->ObjectType == CELLSITE) {
			 CurrSS.MultiSite = true;
			 CurrSS.SiteCol = ACell->AbsoluteCol;
			 CurrSS.SiteRow = site_row;
			 CurrSS.FirstCol = AbsHeaderColCount(ProfGrid1);
			 CurrSS.LastCol = AbsContentColCount(ProfGrid1);
			 SiteTabVisible = true;
			 FlowPanel2->Visible = (Sites->Count > 2);
			 SitePtr = (SITE*)CellObject->Object;
			 FillSiteMetaData(SitePtr);
			 }
		   }
		 TabSheetSite->TabVisible = SiteTabVisible;
		 }
	   }

	 CollPtr = NULL;
	 if (TabSheetCollectionUnit->TabVisible) {
	   int coll_row = FindRowMD(COLL_UNIT_NAME);
	   if (DefaultSite && coll_row == 0) {
		 // default single site with no SS collection units
		 CollPtr = &SitePtr->CollUnits[0];
		 FillCollUnitMetaData();
		 }
	   else if (coll_row > 0) {
		 // either default single site or multi-site with SS collection units
		 bool CollTabVisible = false;
		 UnicodeString CollName = ProfGrid1->Cells[SSCol][coll_row]->Text;
		 if (!CollName.IsEmpty()) {
		   for (unsigned int i=1; i<SitePtr->CollUnits.size(); i++) {
			 if (SameText(CollName, SitePtr->CollUnits[i].CollectionName)) {
			   CollPtr = &SitePtr->CollUnits[i];
			   CollTabVisible = true;
			   FillCollUnitMetaData();
			   break;
			   }
			 }
		   }
		 TabSheetCollectionUnit->TabVisible = CollTabVisible;
		 }
	   else {  // multi-site with no SS collection units
		 TabSheetCollectionUnit->TabVisible = false;
		 }
	   }

	 if (TabSheetCollectionUnit->TabVisible) {
	   InsertMedadataControls(TabSheetCollectionUnit, dxTreeViewEdit1);
	   dxTreeViewEdit1->Text = CollPtr->DepEnv;
	   InsertMedadataControls(TabSheetCollectionUnit, dxTreeViewEdit2);
	   dxTreeViewEdit2->Text = CollPtr->Substrate;
	   InsertMedadataControls(TabSheetCollectionUnit, cxPopupEdit13);
	   if (CollPtr->SlopeAngle.IsEmpty())
		 cxPopupEdit13->Text = "";
	   else
		 cxPopupEdit13->Text = CollPtr->SlopeAngle;
	   InsertMedadataControls(TabSheetCollectionUnit, cxPopupEdit14);
	   if (CollPtr->SlopeAspect.IsEmpty())
		 cxPopupEdit14->Text = "";
	   else
		 cxPopupEdit14->Text = CollPtr->SlopeAspect;
	   }

	 DatasetNum = 0;
	 // get all #Data.Type rows
	 if (Datasets.size() > 1) {
	   TProfGridColumn* CodeCol = ProfGrid1->AbsoluteCols[1];
	   TProfGridColumn* NameCol = ProfGrid1->AbsoluteCols[2];
	   for (int row=ProfGrid1->Row; row>=3; row--) {
		 UnicodeString Code = CodeCol->AbsoluteCells[row]->Text;
		 if (SameText(Code, L"#Data.Type")) {
		   UnicodeString DatasetType = NameCol->AbsoluteCells[row]->Text;
		   if (DatasetType.IsEmpty()) continue;
		   bool found = false;
		   for (unsigned int i=1; i<Datasets.size(); i++) {
			 if (SameText(DatasetType, Datasets[i].DatasetType)) {
			   DatasetNum = i;
			   found = true;
			   break;
			   }
			 }
		   if (found) break;
		   }
		 }
	   }
	 FillDatasetMetaData(DatasetNum);
	 UpdateContacts(cxCheckComboBox10, GeochronDataset.Investigators);

	 for (int i=0; i<PageControl2->PageCount; i++) {
	   if (PageControl2->Pages[i]->TabVisible) {
		 PageControl2->ActivePage = PageControl2->Pages[i];
		 break;
		 }
	   }
	 }
}
//---------------------------------------------------------------------------

// first
void __fastcall TTilSpreadSheetForm::cxButton34Click(TObject *Sender)
{
   if (CurrSS.MultiSite && CurrSS.SiteCol > CurrSS.FirstCol) {
	 if (MoveToSSSite(CurrSS.FirstCol))
	   return;
	 else {  // if the first column does not have a site object
	   int col = CurrSS.FirstCol;
	   while (++col < CurrSS.SiteCol) {
		 if (MoveToSSSite(col))
		   return;
		 }
	   }
	 }
   Beep();
}
//---------------------------------------------------------------------------

// prior
void __fastcall TTilSpreadSheetForm::cxButton35Click(TObject *Sender)
{
   if (CurrSS.MultiSite && CurrSS.SiteCol > CurrSS.FirstCol) {
	 int col = CurrSS.SiteCol;
	 while (--col >= CurrSS.FirstCol) {
	   if (MoveToSSSite(col))
		 return;
	   }
	 }
   Beep();
}
//---------------------------------------------------------------------------

// next
void __fastcall TTilSpreadSheetForm::cxButton36Click(TObject *Sender)
{
   if (CurrSS.MultiSite && CurrSS.SiteCol < CurrSS.LastCol) {
	 int col = CurrSS.SiteCol;
	 while (++col <= CurrSS.LastCol) {
	   if (MoveToSSSite(col))
		 return;
	   }
	 }
   Beep();
}
//---------------------------------------------------------------------------

// last
void __fastcall TTilSpreadSheetForm::cxButton37Click(TObject *Sender)
{
   if (CurrSS.MultiSite && CurrSS.SiteCol < CurrSS.LastCol) {
	 if (MoveToSSSite(CurrSS.LastCol))
	   return;
	 else {  // if the last column does not have a site object
	   int col = CurrSS.LastCol;
	   while (--col > CurrSS.SiteCol) {
		 if (MoveToSSSite(col))
		   return;
		 }
	   }
	 }
   Beep();
}
//---------------------------------------------------------------------------

bool TTilSpreadSheetForm::MoveToSSSite(int ACol)
{
   TProfGridCell *ACell = ProfGrid1->AbsoluteCells[ACol][CurrSS.SiteRow];
   if (ACell->CellObject != NULL) {         // #Site.Name/Object exist
	 CELLOBJECT* CellObject = (CELLOBJECT*)ACell->CellObject;
	 if (CellObject->ObjectType == CELLSITE) {
	   SiteMetaDataToSS(CurrSS.SiteCol);  // before updating SitePtr
	   CollUnitMetaDataToSS(CurrSS.SiteCol);
	   SitePtr = (SITE*)CellObject->Object;
	   FillSiteMetaData(SitePtr);
	   if (SitePtr->CollUnits.size() > 1) {  // should always be the case, but..
		 CollPtr = &SitePtr->CollUnits[1];
		 FillCollUnitMetaData();
		 }
	   CurrSS.SiteCol = ACol;
	   return true;
	   }
	 }
   return false;
}
//---------------------------------------------------------------------------

// re-inserts controls used for spreadsheet metadata
void TTilSpreadSheetForm::InsertMedadataControls(TTabSheet* TabSheet,
	  TWinControl* Control)
{
   if (!TabSheet->ContainsControl(Control)) {
	 Control->Parent->RemoveControl(Control);
     TabSheet->InsertControl(Control);
     Control->Left = InitialControlProperties[Control].Left;
     Control->Top = InitialControlProperties[Control].Top;
	 Control->Width = InitialControlProperties[Control].Width;
     Control->Visible = true;
     }
}
//---------------------------------------------------------------------------

// Change metadata tabsheets
void __fastcall TTilSpreadSheetForm::PageControl2Change(TObject *Sender)
{
   ParentForm->ActivateSpreadsheetMenu(true, PageControl1, cxPageControl1, PageControl2);
}
//---------------------------------------------------------------------------

// this before all cells are pasted
void __fastcall TTilSpreadSheetForm::ProfGrid1BeforePaste(TObject *Sender)
{
   // this is to control pastes into downloaded datasets, in which only one
   // row may be pasted at a time
   if (Downloaded && tiLicense->Type() == verNEOTOMASTEWARD) {
	 DownloadPaste.Pasting = true;
	 DownloadPaste.n = 1;
	 DownloadPaste.ncols = ProfGrid1->Selection->Right - ProfGrid1->Selection->Left + 1;
	 Screen->Cursor = crHourGlass;
	 }
}
//---------------------------------------------------------------------------

// this is after all cells are pasted, called from an internal paste
void __fastcall TTilSpreadSheetForm::ProfGrid1EndPaste(TObject *Sender)
{
   UnicodeString msg;

   if (PasteError != NO_PASTE_ERROR) {
	 switch (PasteError) {
	   case PASTE_INTO_CHECKBOX:
		 msg = "Attempt to paste invalid data into CheckBox ignored.";
		 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 break;
	   case PASTE_FROM_CHECKBOX:
		 msg = "CheckBox data pasted into non-CheckBox cell(s) converted.";
		 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
		 break;
	   }
	 PasteError = NO_PASTE_ERROR;
	 }

   if (MetadataPaste) {
	 // This is only true if data are being copied and pasted from within the Tilia spreadsheet.
	 // It's not true, for instance, if pasting from Excel
	 Screen->Cursor = crHourGlass;
	 CurrentRowHeight = ProfGrid1->RowHeights[CellPasted.Row];
	 if (CellPasted.n == 1)
	   EnterSSMetaData(CellPasted.Code, CellPasted.Value, CellPasted.Col, CellPasted.Row);
	 else
	   ResetSSMetadata();
	 CellPasted.n = 0;
	 MetadataPaste = false;
	 Screen->Cursor = crDefault;
	 }

   if (Downloaded && tiLicense->Type() == verNEOTOMASTEWARD) {   // data paste
	 //ShowMessage(L"EndPaste");
	 UploadDataValues();
	 DownloadPaste.Pasting = false;
	 DownloadPaste.Error = false;
	 DownloadPaste.Row = -1;
	 Screen->Cursor = crDefault;
	 }

   SpreadSheetChanged = true;
}
//---------------------------------------------------------------------------

// This routine processes pasting of cells copied from other ProfGrid cells
// It is not called if pasting from, for example, Excel
void __fastcall TTilSpreadSheetForm::ProfGridPaste(TProfGrid *Sender,
	  int ACol, int ARow, TProfGridClipboardCell *ACell, bool &CanPaste)
{
#ifdef WHITMORE
   // if (Datasets[0].WhitmoreID1 != -1) [
   if (Datasets[0].WhitmoreData) {
	 UnicodeString VarCode = ProfGrid1->AbsoluteCells[1][ARow]->Text;
	 if (SameText(VarCode,L"#Samp.Name")) {
	   CanPaste = false;
	   Beep();
	   return;
	   }
	 }
#endif

   //ShowMessage(L"GridPaste");

   // if (!ACell->CustomData.IsEmpty())

   TProfGridCell* DestCell = Sender->Cells[ACol][ARow];
   SaveCells(Sender, DestCell);   // for UnDo

   if (Downloaded && tiLicense->Type() == verNEOTOMASTEWARD && Sender == ProfGrid1) {
	 CheckDownloadPaste(DestCell->AbsoluteCol, DestCell->AbsoluteRow, CanPaste);
	 if (CanPaste) {
	   if (!ACell->CustomData.IsEmpty())
		 ACell->CustomData = Unassigned();
	   }
	 else
	   return;
	 }

   UnicodeString Code = Sender->AbsoluteCells[1][ARow]->Text;

   if (DestCell->CheckBox) {
	 int Type = ACell->Value.Type();
	 if (Type == varDouble) {
	   if (ACell->Value == 1)
		 DestCell->CheckBoxChecked = true;
	   else if (ACell->Value == 0)
		 DestCell->CheckBoxChecked = false;
	   else
		 PasteError = PASTE_INTO_CHECKBOX;
	   }
	 else if (Type == varBoolean)
	   DestCell->CheckBoxChecked = ACell->Value;
	 else if (ACell->CheckBox)
	   DestCell->CheckBoxChecked = ACell->CheckBoxChecked;
	 else
	   PasteError = PASTE_INTO_CHECKBOX;
	 CanPaste = false;
	 }
   else if (ACell->CheckBox) {   // attempting to paste from checkbox in to non-checkbox
	 DestCell->Value = ACell->CheckBoxChecked;
	 CanPaste = false;
	 PasteError = PASTE_FROM_CHECKBOX;
	 }
   else {
	 // copy CellObject
	 int AbsCol = Sender->Cols[ACol]->AbsoluteNumber;
	 int AbsRow = Sender->Rows[ARow]->AbsoluteNumber;
	 if (AbsCol > 7 && ARow == 2) {   // second header row
	   if (HeaderRow2 == SITE_NAME)
		 EnterSSSite(ACell->Value, ACol, ARow);
	   else if (HeaderRow2 == COLL_UNIT_NAME) {
		 EnterSSCollUnit(ACell->Value, ACol, ARow);
		 }
	   }
	 else if (AbsCol > 7 && Code.SubString(1,1) == L"#") {  // metadata row in main spreadsheet
	   CellPasted.n++;
	   if (CellPasted.n == 1) {
		 CellPasted.Save(Code.UpperCase(), ACell->Value, ACol, ARow);
		 if (DestCell->CellObject != NULL)
		   DeleteCellObject(DestCell);
		 if (ACell->AbsoluteRow == ARow) {
		   TProfGridCell* SourceCell = Sender->AbsoluteCells[ACell->AbsoluteCol][ACell->AbsoluteRow];
		   if (SourceCell->CellObject != NULL) {
			 CELLOBJECT* CellObject = new CELLOBJECT((CELLOBJECT*)SourceCell->CellObject);
			 AddCellObject(DestCell, CellObject);
			 }
		   }
		 }
	   MetadataPaste = true;
	   }
	 else if (AbsCol > 7 && AbsRow > 2) {   // body of spreadsheet
	   TProfGridCell* SourceCell = Sender->AbsoluteCells[ACell->AbsoluteCol][ACell->AbsoluteRow];
	   if (SourceCell->CellObject != NULL) {
		 CELLOBJECT* CellObject = (CELLOBJECT*)SourceCell->CellObject;
		 if (CellObject->ObjectType == CELLSPECIMENS) {
		   CELLOBJECT* NewCellObject = new CELLOBJECT(CellObject);
		   AddCellObject(DestCell, NewCellObject);
		   }
		 }
	   }
	 }

   // paste specimen objects from cut cells
   if (CutObjects.size() > 0 && Sender == ProfGrid1) {
	 CELLOBJECT* CellObject = CutObjects.front();
	 if (CellObject != NULL) {
	   if (DestCell->AbsoluteCol > 7 && DestCell->AbsoluteRow > 2 && Code.SubString(1,1) != L"#")
		 AddCellObject(DestCell, CellObject);
	   }
	 CutObjects.pop_front();
	 }
}
//---------------------------------------------------------------------------

// this routine processes pastes copied from other sources (e.g. Excel)
void __fastcall TTilSpreadSheetForm::ProfGrid1PastePlainText(TProfGrid *Sender, int ACol,
		  int ARow, WideString &AText, bool &CanPaste)
{
   TProfGridCell* DestCell = Sender->Cells[ACol][ARow];
   SaveCells(Sender, DestCell);   // for UnDo
   if (Downloaded && tiLicense->Type() == verNEOTOMASTEWARD)
	 CheckDownloadPaste(DestCell->AbsoluteCol, DestCell->AbsoluteRow, CanPaste);
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::CheckDownloadPaste(int ACol, int ARow, bool &CanPaste)
{
   // ACol and ARow are absolute cells
   if (DownloadPaste.Row == -1)
	 DownloadPaste.Row = ARow;
   else if (ARow != DownloadPaste.Row) {
	 CanPaste = false;
	 if (!DownloadPaste.Error) {
	   MessageDlg(L"Only one row at a time may be pasted into a downloaded dataset!",
		 Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   DownloadPaste.Error = true;
	   }
	 }
   if (CanPaste && ACol >= 8 && ARow >= 3) {
	 DownloadPasteCells.push_back(pair<int,int>(ACol,ARow));
	 UnicodeString VarCode = ProfGrid1->AbsoluteCells[1][ARow]->Text;
	 // if (VarCode[1] != L'#') {
	   if (ProfGrid1->AbsoluteCells[ACol][ARow]->CustomData.IsEmpty())
		 ProfGrid1->AbsoluteCells[ACol][ARow]->Color = TColor(0x00B7B8E6);  // light red
	   else
		 ProfGrid1->AbsoluteCells[ACol][ARow]->Color = TColor(0x00ADCBF8);  // light orange
	 //  }
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::ProfGridCutCell(TProfGrid *Sender, TProfGridCell *Cell,
		  bool &Allow)
{
   SaveCells(Sender, Cell);
   if (Sender == ProfGrid1) {
	 if (Cell->CellObject != NULL) {
	   CELLOBJECT* CellObject = (CELLOBJECT*)Cell->CellObject;
	   CutObjects.push_back(CellObject);
	   CellObjects.remove(CellObject);
	   Cell->CellObject = NULL;
	   }
	 else
	   CutObjects.push_back((CELLOBJECT*)NULL);
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::dxTreeViewEdit1Exit(TObject *Sender)
{

   if (PageControl1->ActivePage == TabSheet1) {
	 ProfGrid1->Cells[ProfGrid1->Col][ProfGrid1->Row]->Value = dxTreeViewEdit1->Text;
	 ProfGrid1->RowHeights[ProfGrid1->Row] = CurrentRowHeight;
	 }
   else if (PageControl1->ActivePage == TabSheet2)
	 CollPtr->DepEnv = dxTreeViewEdit1->Text;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::dxTreeViewEdit1Click(TObject *Sender)
{
   TTreeNode* Node = dxTreeViewEdit1->Selected;
   dxTreeViewEdit1->Text = Node->Text;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxButton12Click(TObject *Sender)
{
   EditTreeForm = new TEditTreeForm(this);
   EditTreeForm->Caption = L"Depositional Environments";
   EditTreeForm->dxTreeView1->Items->Assign(dxTreeViewEdit1->Items);
   EditTreeForm->dxTreeView1->AlphaSort();
   for (int i=0; i<EditTreeForm->dxTreeView1->Items->Count; i++) {
	 TTreeNode* Node = EditTreeForm->dxTreeView1->Items->Item[i];
	 if (SameText(Node->Text, dxTreeViewEdit1->Text)) {
	   EditTreeForm->dxTreeView1->Selected = Node;
	   break;
	   }
	 }

   if (EditTreeForm->ShowModal() == mrOk) {
	 if (EditTreeForm->TreeModified()) {
	   dxTreeViewEdit1->Items->Clear();
	   dxTreeViewEdit1->Items->Assign(EditTreeForm->dxTreeView1->Items);
	   UnicodeString msg = "Depositional Environments were changed. Save to Lookup file?";
	   if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes)
		 SaveLookupFile();
	   }
	 }

   delete EditTreeForm;
   FocusControl(dxTreeViewEdit1);
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::dxTreeViewEdit2Exit(TObject *Sender)
{
   if (PageControl1->ActivePage == TabSheet1) {
	 ProfGrid1->Cells[ProfGrid1->Col][ProfGrid1->Row]->Value = dxTreeViewEdit2->Text;
	 ProfGrid1->RowHeights[ProfGrid1->Row] = CurrentRowHeight;
	 }
   else if (PageControl1->ActivePage == TabSheet2)
	 CollPtr->Substrate = dxTreeViewEdit2->Text;
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::EditTaxa(void)
{
   //bool TaxaLoaded;
   int MaxTxID = -1;

   if (!TaxaLookupOpen) {
	 if (!LoadLookupTaxa(TaxaList, TaxaEcolGroups))
	   return;
	 }

   Screen->Cursor = crHourGlass;
   for (unsigned int i=0; i<TaxaList.size(); i++) {
	 if (TaxaList[i].ID > MaxTxID)
	   MaxTxID = TaxaList[i].ID;
	 }

   EditTaxaForm = new TEditTaxaForm(&TaxaList, &TaxaEcolGroups, MaxTxID, false, this);
   EditTaxaForm->SetTaxaFile(tiGlobals->TaxaFile);
   EditTaxaForm->SetTaxaTitle(xml_TaxaTitle);

   Screen->Cursor = crDefault;

   if (EditTaxaForm->ShowModal() == mrOk) {
	 if (TaxaLookupOpen) {
	   TaxaList.clear();
	   EditTaxaForm->ConvertTaxaList(TaxaList);
	   cxComboBox15->Clear();
	   cxComboBox15->Properties->Items->Clear();
	   for (unsigned int i=0; i<TaxaList.size(); i++)
		 cxComboBox15->Properties->Items->Add(TaxaList[i].Name);
	   cxComboBox15->Properties->Items->EndUpdate();
	   }
	 }

   if (!TaxaLookupOpen) {
	 TaxaList.clear();
	 TaxaEcolGroups.clear();
	 }
   delete EditTaxaForm;
}
//---------------------------------------------------------------------------

bool TTilSpreadSheetForm::LoadLookupTaxa(TTaxaVector& TaxaList, vector<TAXAECOLGROUPS>& TaxaEcolGroups)
{
   UnicodeString LookupPath;
   UnicodeString TaxaFile;

   if (!tiGlobals->MyLookupPath.IsEmpty())
	 LookupPath = tiGlobals->MyLookupPath;
   else
	 LookupPath = tiGlobals->AppDataTiliaLookupPath;

   if (!tiGlobals->TaxaFile.IsEmpty())
	 TaxaFile = LookupPath + ExtractFileName(tiGlobals->TaxaFile);
   if (TaxaFile.IsEmpty())
	 TaxaFile = LookupPath + L"NeotomaPollenTaxa.xml";

   if (!TaxaFile.IsEmpty()) {
	 if (FileExists(TaxaFile)) {
       OpenDialog1->DefaultExt = "xml";
       OpenDialog1->FileName = TaxaFile;
       OpenDialog1->InitialDir = ExtractFilePath(TaxaFile);
       OpenDialog1->Filter = "XML Lookup File (*.xml)|*.xml";
       }
     }
   if (OpenDialog1->Execute()) {
     TaxaFile = OpenDialog1->FileName;
     UnicodeString FileExt = ExtractFileExt(TaxaFile);
     if (FileExt.CompareIC(".xml") != 0) {
       MessageDlg("Taxa file must be *.xml", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
       return false;
       }
     else if (!FileExists(TaxaFile)) {
       MessageDlg("File <" + TaxaFile + "> does not exist.", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
       return false;
       }
     }
   else
     return false;

   txml = new TAXAXML();
   ParseTaxa = new PARSETAXA(ipwXMLp6, this);
   bool rv = ParseTaxa->Parse(TaxaFile);
   delete txml;
   //if (ParseTaxa->GroupCategoryList)
   //	 *GroupCategoryList = new TGroupCategoryList(ParseTaxa->GroupCategoryList);
   if (ParseTaxa->TaxaEcolGroups.size() > 0) {
	 TaxaEcolGroups.clear();
	 TaxaEcolGroups = ParseTaxa->TaxaEcolGroups;
	 }

   //if (rv && ParseTaxa->TaxaList->Count) {
   //	 tiGlobals->SetTaxaFile(TaxaFile);
   //	 *TaxaList = new TTaxaList(ParseTaxa->TaxaList);
   //	 }
   if (rv && ParseTaxa->TaxaList.size() > 0) {
	 tiGlobals->TaxaFile = ExtractFileName(TaxaFile);
	 TaxaList = ParseTaxa->TaxaList;
	 }
   delete ParseTaxa;
   return true;
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::EditGroups(void)
{
   //bool TaxaLoaded = (cxComboBox1->Properties->Items->Count > 0);

   if (!TaxaLookupOpen) {
	 if (!LoadLookupTaxa(TaxaList, TaxaEcolGroups))
	   return;
	 }

   EditGroupsForm = new TEditGroupsForm(&TaxaEcolGroups, this);
   EditGroupsForm->SetTaxa(tiGlobals->TaxaFile, xml_TaxaTitle, &TaxaList);

   EditGroupsForm->ShowModal();

   if (!TaxaLookupOpen) {
	 TaxaEcolGroups.clear();
	 TaxaList.clear();
	 }
   delete EditGroupsForm;
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::EditElements(void)
{
   if (!VarLookup->ElementOpen()) {
	 ElementLookup = new ELEMENTLOOKUP();
	 VarLookup->SetElementLookup(ElementLookup);
	 for (unsigned int i=0; i<Datasets.size(); i++) {
	   UnicodeString DatasetType = Datasets[i].DatasetType.LowerCase();
	   int pos = DatasetType.LowerCase().Pos(L"surface sample");
	   if (pos > 0) {
		 DatasetType.Delete(pos,14);
		 DatasetType = DatasetType.Trim();
		 }
	   if (ElementLookup->Elements.count(DatasetType) == 0) {
		 ELEMENTTAXONGROUP ElementTaxonGroup;
		 ElementLookup->Elements[DatasetType] = ElementTaxonGroup;
		 }
	   }
	 }
   else
	 VarLookup->SetElementPath(tiGlobals->ElementsFile);

   EditElementsForm = new TEditElementsForm(VarLookup, this);
   EditElementsForm->ShowModal();
   delete EditElementsForm;
   ElementLookup = VarLookup->GetElementLookup();
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::EditUnits(void)
{
   UnicodeString DatasetType;

   if (!VarLookup->UnitsLoaded()) {
	 UnicodeString msg = L"Units lookup file has not been opened.";
	 msg += L"\nOnly units in this dataset will be shown.";
	 MessageDlg(msg, mtWarning, TMsgDlgButtons() << mbOK, 0);
	 }

   if (!VarLookup->UnitOpen()) {
	 UnitLookup = new UNITLOOKUP();
	 VarLookup->SetUnitLookup(UnitLookup);
	 DatasetType = GenericDatasetType(Datasets[0].DatasetType);
	 int RowCount = ContentRowCount(ProfGrid1);
	 for (int row=3; row<=RowCount; row++) {
	   TProfGridCell* ACell = ProfGrid1->AbsoluteCells[1][row];
	   UnicodeString Code = ACell->Text;
	   if (SameText(Code, L"#Data.Type"))
		 DatasetType = GenericDatasetType(ProfGrid1->AbsoluteCells[2][row]->Text.LowerCase());
	   else if (Code[1] != L'#' && !SameText(Code.SubString(1,3),L"SUM") && !SameText(Code.SubString(1,4),L"SSUM")) {
		 UnicodeString Units = ProfGrid1->AbsoluteCells[4][row]->Text;
		 if (UnitLookup->Units.count(DatasetType) == 0) {
		   set<UnicodeString> Units;
		   UnitLookup->Units[DatasetType] = Units;
		   }
		 if (!Units.IsEmpty()) {
		   if (UnitLookup->Units[DatasetType].count(Units) == 0)
			 UnitLookup->Units[DatasetType].insert(Units);
		   }
		 }
	   }
	 }

   DatasetType = GenericDatasetType(Datasets[DatasetNum].DatasetType);
   EditUnitsForm = new TEditUnitsForm(VarLookup, cxComboBox2->Properties->Items, DatasetType, this);
   if (EditUnitsForm->ShowModal() == mrOk) {
	 map<UnicodeString, set<UnicodeString> >::iterator itr;
	 map<UnicodeString, set<UnicodeString> >::iterator begin = UnitLookup->Units.begin();
	 map<UnicodeString, set<UnicodeString> >::iterator end = UnitLookup->Units.end();
	 bool NewDatsetType = false;
	 for (itr = begin; itr != end; itr++) {
	   UnicodeString DatasetType = itr->first;
	   if (DataTypes.count(DatasetType) == 0) {
		 UnicodeString FirstLetter = DatasetType.SubString(1,1).UpperCase();
		 DatasetType.Delete(1,1);
		 DatasetType.Insert(FirstLetter,1);
		 DataTypes.insert(DatasetType);
		 cxComboBox2->Properties->Items->Add(DatasetType);
		 NewDatsetType = true;
		 }
	   }
	 if (NewDatsetType)
	   SaveLookupFile();
	 }
   delete EditUnitsForm;
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::EditContexts(void)
{
   UnicodeString DatasetType;

   if (!VarLookup->ContextsLoaded()) {
	 UnicodeString msg = L"Contexts lookup file has not been opened.";
	 msg += L"\nOnly Contexts in this dataset will be shown.";
	 MessageDlg(msg, mtWarning, TMsgDlgButtons() << mbOK, 0);
	 }

   if (!VarLookup->ContextOpen()) {
	 ContextLookup = new CONTEXTLOOKUP();
	 VarLookup->SetContextLookup(ContextLookup);
	 DatasetType = GenericDatasetType(Datasets[0].DatasetType);
	 int RowCount = ContentRowCount(ProfGrid1);
	 for (int row=3; row<=RowCount; row++) {
	   TProfGridCell* ACell = ProfGrid1->AbsoluteCells[1][row];
	   UnicodeString Code = ACell->Text;
	   if (SameText(Code, L"#Data.Type"))
		 DatasetType = GenericDatasetType(ProfGrid1->AbsoluteCells[2][row]->Text.LowerCase());
	   else if (Code[1] != L'#' && !SameText(Code.SubString(1,3),L"SUM") && !SameText(Code.SubString(1,4),L"SSUM")) {
		 UnicodeString Context = ProfGrid1->AbsoluteCells[5][row]->Text;
		 if (ContextLookup->Contexts.count(DatasetType) == 0) {
		   set<UnicodeString> Contexts;
		   ContextLookup->Contexts[DatasetType] = Contexts;
		   }
		 if (!Context.IsEmpty()) {
		   if (ContextLookup->Contexts[DatasetType].count(Context) == 0)
			 ContextLookup->Contexts[DatasetType].insert(Context);
		   }
		 }
	   }
	 }

   DatasetType = GenericDatasetType(Datasets[DatasetNum].DatasetType);
   EditContextsForm = new TEditContextsForm(VarLookup, cxComboBox2->Properties->Items, DatasetType, this);
   if (EditContextsForm->ShowModal() == mrOk) {
	 // add any new dataset types
	 map<UnicodeString, set<UnicodeString> >::iterator itr;
	 map<UnicodeString, set<UnicodeString> >::iterator begin = ContextLookup->Contexts.begin();
	 map<UnicodeString, set<UnicodeString> >::iterator end = ContextLookup->Contexts.end();
	 bool NewDatsetType = false;
	 for (itr = begin; itr != end; itr++) {
	   UnicodeString DatasetType = itr->first;
	   if (DataTypes.count(DatasetType) == 0) {
		 UnicodeString FirstLetter = DatasetType.SubString(1,1).UpperCase();
		 DatasetType.Delete(1,1);
		 DatasetType.Insert(FirstLetter,1);
		 DataTypes.insert(DatasetType);
		 cxComboBox2->Properties->Items->Add(DatasetType);
		 NewDatsetType = true;
		 }
	   }
	 if (NewDatsetType)
	   SaveLookupFile();
	 }
   delete EditContextsForm;
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::EditTaphonomy(void)
{
   if (!VarLookup->TaphonomyLoaded()) {
	 UnicodeString msg = L"Taphonomy lookup file has not been opened.";
	 msg += L"\nOnly taphonomic types in this dataset will be shown.";
	 MessageDlg(msg, mtWarning, TMsgDlgButtons() << mbOK, 0);
	 }

   if (TaphonomyLookup == NULL) {
	 TaphonomyLookup = new TAPHONOMYLOOKUP;
	 VarLookup->SetTaphonomyLookup(TaphonomyLookup);
	 TaphonomyLookup->Add(L"none", L"none");
	 }
   EditTaphonomyForm = new TEditTaphonomyForm(VarLookup, cxComboBox2->Properties->Items, this);
   EditTaphonomyForm->ShowModal();

   delete EditTaphonomyForm;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::ipwXMLp6StartElement(TObject *Sender,
	  TipwXMLpStartElementEventParams *e)
{
   txml->XText.SetLength(0);
   UnicodeString Element = e->Element.w_str();

   if (SameText(Element, L"EcologicalGroups"))
	 txml->EcologicalGroups = true;
   else if (txml->EcologicalGroups) {
	 if (SameText(Element, L"TaxaGroup")) {
	   txml->TaxaGroup = true;
	   txml->TaxaEcolGroup.TaxaGroup.Code = ipwXMLp6->Attr("Code");
	   txml->TaxaEcolGroup.TaxaGroup.Name = ipwXMLp6->Attr("Name");
	   txml->TaxaEcolGroup.EcolGroups.clear();
	   }
	 else if (txml->TaxaGroup) {
	   if (SameText(Element, L"EcologicalGroup")) {
		 txml->EcologicalGroup = true;
		 txml->ecolgroup.Code = L"";
		 txml->ecolgroup.Name = L"";
		 }
	   else if (SameText(Element, L"Elements"))
		 txml->Elements = true;
	   else if (txml->EcologicalGroup) {
		 if (SameText(Element, L"Code"))
		   txml->Code = true;
		 else if (SameText(Element, L"Name"))
		   txml->Name = true;
		 }
	   else if (txml->Elements) {
		 if (SameText(Element, L"Element"))
		   txml->Element = true;
		 }
	   }
	 }
   else if (SameText(Element, L"Taxa"))
	 txml->Taxa = true;
   else if (txml->Taxa) {
	 if (SameText(Element, L"Taxon")) {
	   txml->Taxon = true;
	   txml->taxon.Clear();
	   txml->taxon.ID = ipwXMLp6->Attr("ID").ToInt();
	   }
	 else if (txml->Taxon) {
	   if (SameText(Element, L"Name"))
		 txml->Name = true;
	   else if (SameText(Element, L"Author"))
		 txml->Author = true;
	   else if (SameText(Element, L"Code"))
		 txml->Code = true;
	   else if (SameText(Element, L"TaxaGroup"))
		 txml->TaxaGroup = true;
	   else if (SameText(Element, L"EcolGroup"))
		 txml->EcolGroup = true;
	   else if (SameText(Element, L"HigherID"))
		 txml->HigherID = true;
	   else if (SameText(Element, L"Element")) {
		 txml->Element = true;
		 ELEMENT element;
		 element.Name = ipwXMLp6->Attr("Type");
		 txml->taxon.Elements.push_back(element);
		 }
	   else if (txml->Element && SameText(Element, L"Units"))
		 txml->Units = true;
	   }
	 }
   else if (SameText(Element, L"Synonyms"))
	 txml->Synonyms = true;
   else if (txml->Synonyms) {
	 if (SameText(Element, L"Synonym"))
	   txml->Synonym = true;
	 else if (txml->Synonym) {
	   if (SameText(Element, L"Name"))
		 txml->Name = true;
	   else if (SameText(Element, L"TaxonID"))
		 txml->TaxonID = true;
	   }
	 }
   else if (SameText(Element, L"Title"))
	 txml->Title = true;
   //else if (Element == "TiliaTaxa")      // root element, set CodePage to UTF-8
   //	 ipwXMLp6->Config("CodePage=65001");
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::ipwXMLp6Characters(TObject *Sender,
	  TipwXMLpCharactersEventParams *e)
{
   UnicodeString ustr = e->Text.w_str();
   txml->XText += ustr;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::ipwXMLp6EndElement(TObject *Sender,
	  TipwXMLpEndElementEventParams *e)
{
   UnicodeString Element = e->Element.w_str();

   if (SameText(Element, L"EcologicalGroups"))
	 txml->EcologicalGroups = false;
   else if (txml->EcologicalGroups) {
	 if (SameText(Element, L"TaxaGroup")) {
	   txml->TaxaGroup = false;
	   ParseTaxa->TaxaEcolGroups.push_back(txml->TaxaEcolGroup);
	   }
	 else if (txml->TaxaGroup) {
	   if (SameText(Element, L"EcologicalGroup")) {
		 txml->EcologicalGroup = false;
		 txml->TaxaEcolGroup.EcolGroups.push_back(txml->ecolgroup);
		 }
	   else if (SameText(Element, L"Elements"))
		 txml->Elements = false;
	   else if (txml->EcologicalGroup) {
		 if (txml->Code) {
		   txml->Code = false;
		   txml->ecolgroup.Code = txml->XText;
		   }
		 else if (txml->Name) {
		   txml->Name = false;
		   txml->ecolgroup.Name = txml->XText;
		   }
		 }
	   else if (txml->Elements) {
		 if (txml->Element) {
		   txml->Element = false;
		   txml->TaxaEcolGroup.Elements.insert(txml->XText);
		   }
		 }
	   }
	 }
   else if (SameText(Element, L"Taxa"))
	 txml->Taxa = false;
   else if (txml->Taxa) {
	 if (SameText(Element, L"Taxon")) {
	   txml->Taxon = false;
	   ParseTaxa->TaxaList.push_back(txml->taxon);
	   ParseTaxa->TrainForm->Chug();
	   }
	 else if (txml->Taxon) {
	   if (txml->Name) {
		 txml->Name = false;
		 txml->taxon.Name = txml->XText;
		 }
	   else if (txml->Author) {
		 txml->Author = false;
		 txml->taxon.Author = txml->XText;
		 }
	   else if (txml->Code) {
		 txml->Code = false;
		 txml->taxon.Code = txml->XText;
		 }
	   else if (txml->TaxaGroup) {
		 txml->TaxaGroup = false;
		 txml->taxon.TaxaGroup = txml->XText;
		 }
	   else if (txml->EcolGroup) {
		 txml->EcolGroup = false;
		 txml->taxon.EcolGroup = txml->XText;
		 }
	   else if (txml->HigherID) {
		 txml->HigherID = false;
		 if (txml->XText.IsEmpty())
		   txml->taxon.HigherID = -1;
		 else
		   txml->taxon.HigherID = txml->XText.ToInt();
		 }
	   else if (txml->Element) {
		 if (SameText(Element, L"Element"))
		   txml->Element = false;
		 else if (txml->Units) {
		   txml->Units = false;
		   txml->taxon.Elements.back().Units.push_back(txml->XText);
		   }
		 }
	   }
	 }
   else if (SameText(Element, L"Synonyms"))
	 txml->Synonyms = false;
   else if (txml->Synonyms) {
	 if (SameText(Element, L"Synonym")) {
	   txml->Synonym = false;
	   ParseTaxa->Synonyms[txml->SynonymName] = txml->SynTaxonID;
	   }
	 else if (txml->Synonym) {
	   if (txml->Name) {
		 txml->Name = false;
		 txml->SynonymName = txml->XText;
		 }
	   else if (txml->TaxonID) {
		 txml->TaxonID = false;
		 txml->SynTaxonID = txml->XText.ToInt();
		 }
	   }
	 }
   else if (SameText(Element, L"Title")) {
	 txml->Title = false;
	 xml_TaxaTitle = txml->XText;
	 }
   else if (SameText(Element, L"Title"))
	 xml_TaxaTitle = SAX.CurrentElementValue;
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::NewTaxa(void)
{
   bool SSTaxa = false;
   int ID = 0;
   int RowCount;
   Variant Value;
   UnicodeString Code;
   UnicodeString Name;

   RowCount = ContentRowCount(ProfGrid1);
   for (int row=3; row<=RowCount; row++) {
	 Value = ProfGrid1->AbsoluteCells[1][row]->Value;
	 if (Value.Type() == varOleStr) {
	   Code = Value;
       if (Code.SubString(1,1) != "#" &&
           Code.SubString(1,3) != "SUM" &&
           Code.SubString(1,4) != "SSUM") {
         Value = ProfGrid1->AbsoluteCells[2][row]->Value;
         if (Value.Type() == varOleStr) {
           SSTaxa = true;
           break;
           }
         }
       }
     }

   if (SSTaxa) {
     if (MessageDlg("Copy taxa in spreadsheet to Taxa lookup file?", mtConfirmation,
         TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes) {
	   //if (TaxaList)
	   //	 delete TaxaList;
	   //TaxaList = new TTaxaList();
       TaxaList.clear();
	   for (int row=3; row<=RowCount; row++) {
         Value = ProfGrid1->AbsoluteCells[1][row]->Value;
         if (Value.Type() == varOleStr) {
           Code = Value;
           if (Code.SubString(1,1) != "#" &&
               Code.SubString(1,3) != "SUM" &&
               Code.SubString(1,4) != "SSUM") {
			 //TAXON* Taxon = new TAXON;
			 //Taxon->ID = ++ID;
			 //Taxon->Code = Code;
			 TAXON Taxon;
			 Taxon.ID = ++ID;
			 Taxon.Code = Code;
			 Value = ProfGrid1->AbsoluteCells[2][row]->Value;
			 if (Value.Type() == varOleStr)
			   //Taxon->Name = Value;
			   Taxon.Name = Value;
			 Value = ProfGrid1->AbsoluteCells[7][row]->Value;
			 if (Value.Type() == varOleStr)
			   //Taxon->EcolGroup = Value;
			   Taxon.EcolGroup = Value;
			 //TaxaList->Add(Taxon);
			 TaxaList.push_back(Taxon);
             }
           }
         }
       }
     }


   EditTaxaForm = new TEditTaxaForm(&TaxaList, &TaxaEcolGroups, ID, true, this);
   //EditTaxaForm->TaxaList = new TTaxaList(TaxaList);
   //EditTaxaForm->SetMaxID(ID);
   //EditTaxaForm->NewTaxa = true;

   if (EditTaxaForm->ShowModal() == mrOk) {
	 //cxComboBox1->Properties->Items->Clear();
	 //if (TaxaList)
	 //  delete TaxaList;

	 TaxaList.clear();
	 // TODO: this is a temporary fix, after fixed do this:
	 // TaxaList = EditTaxaForm->TaxaList;
	 EditTaxaForm->ConvertTaxaList(TaxaList);

	 //TaxaList = new TTaxaList(EditTaxaForm->TaxaList);
	 //cxComboBox1->Properties->Items->BeginUpdate();
	 //for (int i=0; i<TaxaList->Count; i++) {
	 //  TAXON* Taxon = TaxaList->Taxa[i];
	 //  cxComboBox1->Properties->Items->AddObject(Taxon->Name, (TObject*)Taxon);
	 //  }
	 //cxComboBox1->Properties->Items->EndUpdate();

	 TaxaLookupOpen = true;   // this is the key
	 }
   else
     TaxaLookupOpen = false;
   delete EditTaxaForm;
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::NewGroups(void)
{
   TaxaEcolGroups.clear();
   EditGroupsForm = new TEditGroupsForm(&TaxaEcolGroups, this);
   EditGroupsForm->SetTaxa("", "", &TaxaList);
   EditGroupsForm->ShowModal();
   delete EditGroupsForm;
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::NewElements(void)
{
   EditElements();
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::NewUnits(void)
{
   EditUnits();
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::NewContexts(void)
{
   EditContexts();
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::NewTaphonomy(void)
{
   EditTaphonomy();
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::MakeDiagram(void)
{
   int Index;
   UnicodeString VarName;
   UnicodeString SSFileName = TilFileName;

   if (SSFileName.Length() > 0) {
     if (SpreadSheetChanged) {
       if (MessageDlg("Spreadsheet must be saved first. Save now?", mtConfirmation,
           TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes)
         Save();
       if (SpreadSheetChanged) return;
       }
     }
   else {
     if (MessageDlg("Spreadsheet must be saved first. Save now?", mtConfirmation,
         TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes)
       SaveAs();
	 if (SpreadSheetChanged) return;
	 SSFileName = TilFileName;
     }

   SSFileName = ChangeFileExt(SSFileName,".$$$");

   TProfGrid* Grid = ProfGrid();

   if (Grid) {
     // check that depth values are numerical and are in ascending order
     Variant Value;
     int depth1, depth2;
     //int StartCol = Grid->FixedCols + 1;
     int StartCol = Grid->FixedCols;
     int ColCount = ContentColCount(Grid);
     Value = Grid->Cells[StartCol][1]->Value;
	 if (Value.Type() == varDouble)
       depth1 = (double)Value;
     else {
       MessageDlg("Sample number in column " + Grid->Cols[StartCol]->A1Name + " not valid.",
         Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
       return;
       }
     for (int i=StartCol+1; i<=ColCount; i++) {
       Value = Grid->Cells[i][1]->Value;
       if (Value.Type() == varDouble)
         depth2 = (double)Value;
       else {
		 MessageDlg("Sample number in column " + Grid->Cols[i]->A1Name + " not valid.",
           Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
         return;
         }
	   if (depth2 < depth1) {
		 MessageDlg("Sample numbers not in ascending order.", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
         return;
		 }
	   depth1 = depth2;
       }

     // plot elements?
     // first get list of unique elements
	 // TStringList* VarNames = new TStringList;
	 DiagramParams Params(SSFileName, Grid);
     TStringList* Elements = new TStringList;
     TStringList* Contexts = new TStringList;
     Elements->Sorted = true;
     Contexts->Sorted = true;
     int StartRow = Grid->FixedRows;
	 int EndRow = ContentRowCount(Grid);
	 for (int i=StartRow; i<=EndRow; i++) {   // name
	   Value = Grid->AbsoluteCells[2][i]->Value;
       if (Value.Type() == varOleStr)
		 Params.VarNames.push_back(pair<UnicodeString,bool>(Value.AsType(varOleStr),true));
	   else
		 Params.VarNames.push_back(pair<UnicodeString,bool>(EmptyStr,true));

       // elements
       Value = Grid->AbsoluteCells[3][i]->Value;
       if (Value.Type() == varOleStr) {
		 UnicodeString Element = Value;
         if (!Element.IsEmpty() && !Elements->Find(Element, Index))
           Elements->Add(Element);
         }

	   // contexts
	   Value = Grid->AbsoluteCells[5][i]->Value;
       if (Value.Type() == varOleStr) {
		 UnicodeString Context = Value;
         if (!Context.IsEmpty() && !Contexts->Find(Context, Index))
           Contexts->Add(Context);
         }
       }

     //TODO: do for other modifiers

     PlotModsForm = new TPlotModsForm(this);
     bool ShowForm = false;

	 // for pollen datasets, uncheck pollen, spore, etc.
     if (Elements->Count > 0) {
	   ShowForm = true;
       PlotModsForm->CheckListBox1->Items->AddStrings(Elements);
	   //if (dataset->DatasetType.SubString(1,6).CompareIC("pollen") == 0) {
	   if (SameText(Datasets[0].DatasetType.SubString(1,6), L"pollen")) {
		 for (int i=0; i<Elements->Count; i++) {
           UnicodeString Element = Elements->Strings[i];
           PlotModsForm->CheckListBox1->Checked[i] = true;
		   if (SameText(Element, L"pollen") ||
			   SameText(Element, L"spore") ||
			   SameText(Element, L"pollen/spore") ||
			   SameText(Element, L"palynomorph"))
             PlotModsForm->CheckListBox1->Checked[i] = false;
           }
         }
       else {  // for all other dataset types, check all elements
         for (int i=0; i<Elements->Count; i++)
           PlotModsForm->CheckListBox1->Checked[i] = true;
         }
       }
     else {
       PlotModsForm->GroupBox1->Enabled = false;
       PlotModsForm->CheckListBox1->Enabled = false;
       }

     if (Contexts->Count > 0) {
       ShowForm = true;
       PlotModsForm->CheckListBox2->Items->AddStrings(Contexts);
       for (int i=0; i<Contexts->Count; i++)
         PlotModsForm->CheckListBox2->Checked[i] = true;
       }
     else {
       PlotModsForm->GroupBox2->Enabled = false;
       PlotModsForm->CheckListBox2->Enabled = false;
       }

     bool OpenDiagram = false;
     if (ShowForm) {
	   if (PlotModsForm->ShowModal() == mrOk) {
         int separator = PlotModsForm->RadioGroup1->ItemIndex;
		 for (int row=StartRow, i=0; row<=EndRow; row++, i++) {
		   bool modifier = false;                        // if a modifier already exists
           // elements
           Value = Grid->AbsoluteCells[3][row]->Value;   // element
           if (Value.Type() == varOleStr) {              // element exists
             UnicodeString Element = Value;
             Index = PlotModsForm->CheckListBox1->Items->IndexOf(Element);
             if (PlotModsForm->CheckListBox1->Checked[Index]) {
			   // VarName = VarNames->Strings[i];
			   VarName = Params.VarNames[i].first;
               if (VarName.IsEmpty())
                 VarName = Element;
               else {
                 switch (separator) {
                   case 0:  // none
					 VarName += (" " + Element);
                     break;
                   case 1:  // colon
                     VarName += (": " + Element);
                     break;
				   case 2:  // comma
                     VarName += (", " + Element);
                     break;
                   case 3:  // hyphen
                     VarName += (" - " + Element);
                     break;
                   case 4:  // parentheses
                     VarName += (" (" + Element + ")");
                     break;
                   };
                 }
			   // VarNames->Strings[i] = VarName;
			   Params.VarNames[i].first = VarName;
			   modifier = true;
               }
             }
           // contexts
           Value = Grid->AbsoluteCells[5][row]->Value;   // context
           if (Value.Type() == varOleStr) {              // context exists
			 UnicodeString Context = Value;
             Index = PlotModsForm->CheckListBox2->Items->IndexOf(Context);

             if (PlotModsForm->CheckListBox2->Checked[Index]) {
			   // VarName = VarNames->Strings[i];
			   VarName = Params.VarNames[i].first;
               if (VarName.IsEmpty())
				 VarName = Context;
               else {
                 switch (separator) {
                   case 0:  // none
                     if (modifier)
                       VarName += ",";
                     VarName += (" " + Context);
                     break;
                   case 1:  // colon
					 if (modifier)
                       VarName += (", " + Context);
                     else
                       VarName += (": " + Context);
                     break;
                   case 2:  // comma
                     VarName += (", " + Context);
                     break;
                   case 3:  // hyphen
                     if (modifier)
                       VarName += (", " + Context);
                     else
                       VarName += (" - " + Context);
                     break;
                   case 4:  // parentheses
                     if (modifier)
                       VarName.Insert((", " + Context), VarName.Length());
                     else
                       VarName += (" (" + Context + ")");
                     break;
                   };
                 }
			   // VarNames->Strings[i] = VarName;
			   Params.VarNames[i].first = VarName;
			   }
             }
		   }
         OpenDiagram = true;
         }
       }
     else
       OpenDiagram = true;

     if (OpenDiagram) {
	   delete PlotModsForm;
	   delete Elements;
	   delete Contexts;
	   // ParentForm->OpenTGDiagramWindow(SSFileName, Grid, VarNames);
	   ParentForm->OpenTGDiagramWindow(Params);
	   ParentForm->ZoomComboBox->Text = "Fit";
	   // delete VarNames;
       }
     }
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::Options(void)
{
   TProfGrid *ProfGrid;
   SSOptionsForm = new TSSOptionsForm(this);

   if (SSOptionsForm->ShowModal() == mrOk) {
	 if (SSOptionsForm->PercentDecimalPlaces > -1)
	   FormatPercents(SSOptionsForm->PercentDecimalPlaces);
	 if (SSOptionsForm->ConcDecimalPlaces > -1)
	   WSDecimalPoints("Concentrations", SSOptionsForm->ConcDecimalPlaces);
	 if (SSOptionsForm->InfluxDecimalPlaces > -1)
	   WSDecimalPoints("Influx", SSOptionsForm->InfluxDecimalPlaces);

	 // this hides/shows columns: first show them all,
	 // then any get hidden in the FormatWorksheet call
	 for (int npages=0; npages<cxPageControl1->PageCount; npages++) {
	   ProfGrid = Workbook->Sheets[cxPageControl1->Pages[npages]];
	   ProfGrid->DisableControls();
	   ProfGrid->SpreadsheetEnabled = false;
	   ProfGrid->AbsoluteCols[1]->Visible = true;
	   ProfGrid->AbsoluteCols[3]->Visible = true;
	   ProfGrid->AbsoluteCols[4]->Visible = true;
	   ProfGrid->AbsoluteCols[5]->Visible = true;
	   ProfGrid->AbsoluteCols[6]->Visible = true;
	   ProfGrid->AbsoluteCols[7]->Visible = true;
	   for (int i=1; i<=7; i++)
		 for (int j=1; j<=2; j++) {
		   ProfGrid->AbsoluteCells[i][j]->Split();
		   ProfGrid->AbsoluteCells[i][j]->Value = Unassigned();
		   }
	   FormatWorksheet(ProfGrid);
	   ProfGrid->SpreadsheetEnabled = true;
	   ProfGrid->EnableControls();
	   }
	 }
   delete SSOptionsForm;
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::WSDecimalPoints(UnicodeString WSName, int dec)
{
   TProfGrid* ProfGrid = NULL;

   for (int i=0; i<cxPageControl1->PageCount; i++) {
     TcxTabSheet* TabSheet = cxPageControl1->Pages[i];
	 if (TabSheet->Caption == WSName) {
       ProfGrid = Workbook->Sheets[cxPageControl1->Pages[i]];
       break;
       }
     }
   if (!ProfGrid) return;

   Screen->Cursor = crHourGlass;
   int RowCount = AbsContentRowCount(ProfGrid);
   int ColCount = AbsContentColCount(ProfGrid);
   int HeaderRows = AbsHeaderRowCount(ProfGrid);
   int HeaderCols = AbsHeaderColCount(ProfGrid);
   WideString Format = "0.";
   for (int i=0; i<dec; i++)
	 Format += "0";

   ProfGrid->DisableControls();
   ProfGrid->SpreadsheetEnabled = false;
   for (int i=HeaderRows; i<=RowCount; i++) {
	 UnicodeString VarCode = ProfGrid->AbsoluteCells[1][i]->Text;
     if (VarCode.SubString(1,1) != "#") {
       for (int j=HeaderCols; j<ColCount; j++)
         ProfGrid->AbsoluteCells[j][i]->Format = Format;
       }
     }
  ProfGrid->SpreadsheetEnabled = true;
  ProfGrid->EnableControls();
  Screen->Cursor = crDefault;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::FileCloseAction1Execute(
      TObject *Sender)
{
   Close();
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::FileSaveAction1Execute(
      TObject *Sender)
{
   Save();
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::FileSaveAsAction1Execute(
      TObject *Sender)
{
   SaveAs();
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::FileExportAction1Execute(
      TObject *Sender)
{
   Export();
}
//---------------------------------------------------------------------------

bool TTilSpreadSheetForm::CheckSelectionCut(TProfGridSelection *Selection)
{
   for (int i=0; i<Selection->Count; i++) {
	 TProfGridCell* ACell = Selection->Cells[i];
	 if (ACell->CellObject) {
	   CELLOBJECT* CellObject = (CELLOBJECT*)ACell->CellObject;
	   if (CellObject->ObjectType == CELLSITE) {
		 MessageDlg(L"Site Name cannot be cut.", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 return false;
		 }
	   }
	 }
   return true;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::SSCutAction1Execute(TObject *Sender)
{
   TcxGridTableView* CurrentTableView;

   if (PageControl1->ActivePage == TabSheet1) {
	 if (ProfGrid() == ProfGrid1) {
	   if (!CheckSelectionCut(ProfGrid1->Selection))
		 return;
	   }
	 ClearCutObjects();
	 ProfGrid()->Selection->CutToClipboard();
	 SpreadSheetChanged = true;
     }
   else if (PageControl1->ActivePage == TabSheet2) {
     if (PageControl2->ActivePage == TabSheetLithology) {
       CurrentTableView = dynamic_cast< TcxGridTableView *>(cxGrid1->FocusedView);
       CutGrid(CurrentTableView);
	   }
     else if (PageControl2->ActivePage == TabSheetGeochron) {
       CurrentTableView = dynamic_cast< TcxGridTableView *>(cxGrid2->FocusedView);
       CutGrid(CurrentTableView);
       }
     else if (PageControl2->ActivePage == TabSheetAgeModels) {
       CurrentTableView = dynamic_cast< TcxGridTableView *>(cxGrid3->FocusedView);
       CutGrid(CurrentTableView);
       }
	 else if (PageControl2->ActivePage == TabSheetLOI) {
	   if (PageControl3->ActivePage == TabSheetLOIData)
		 AdvColumnGrid5->CutSelectionToClipboard();
	   }
     else
       SendMessage(ActiveControl->Handle, WM_CUT, 0, 0);
     }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::CutGrid(TcxGridTableView *Grid)
{
   Grid->CopyToClipboard(false);
   for (int j=0; j<Grid->Controller->SelectedColumnCount; j++) {
     int ItemIndex = Grid->Controller->SelectedColumns[j]->Index;
     for (int i=0; i<Grid->Controller->SelectedRecordCount; i++) {
       int RecordIndex = Grid->Controller->SelectedRecords[i]->RecordIndex;
	   Grid->DataController->Values[RecordIndex][ItemIndex] = Unassigned();
       }
     }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::SSCopyAction1Execute(TObject *Sender)
{
   if (PageControl1->ActivePage == TabSheet1) {
	 Screen->Cursor = crHourGlass;
	 ProfGrid()->DisableControls();
	 ProfGrid()->SpreadsheetEnabled = false;
	 ProfGrid()->Selection->CopyToClipboard();
	 ProfGrid()->SpreadsheetEnabled = true;
	 ProfGrid()->EnableControls();
	 Screen->Cursor = crDefault;
	 }
   else if (PageControl1->ActivePage == TabSheet2) {
	 if (PageControl2->ActivePage == TabSheetLithology)
	   ((TcxGridTableView *)cxGrid1->FocusedView)->CopyToClipboard(false);
	 else if (PageControl2->ActivePage == TabSheetGeochron)
	   ((TcxGridTableView *)cxGrid2->FocusedView)->CopyToClipboard(false);
	 else if (PageControl2->ActivePage == TabSheetAgeModels)
	   ((TcxGridTableView *)cxGrid3->FocusedView)->CopyToClipboard(false);
	 else if (PageControl2->ActivePage == TabSheetLOI) {
	   AdvColumnGrid5->CopySelectionToClipboard();

	   }
	 else
       SendMessage(ActiveControl->Handle, WM_COPY, 0, 0);
     }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::SSCopyAllAction1Execute(TObject *Sender)
{
   if (PageControl1->ActivePage == TabSheet1) {
     int nrows = ContentRowCount(ProfGrid());
     int ncols = ContentColCount(ProfGrid());
     if (ncols*nrows > 20000) {
	   if (MessageDlg("Copying more than 20,000 cells to the clipboard can be very slow. Continue anyway?",
           mtWarning, TMsgDlgButtons() << mbYes << mbNo, 0) == mrNo)
             return;
       }
     int col = ProfGrid()->Col;
     int row = ProfGrid()->Row;
     int TopRow = ProfGrid()->TopRow;
     int LeftCol = ProfGrid()->LeftCol;
     Screen->Cursor = crHourGlass;
     ProfGrid()->DisableControls();
     ProfGrid()->SpreadsheetEnabled = false;
     ProfGrid()->SetSelection(1, 1, ncols, nrows);
     ProfGrid()->Selection->CopyToClipboard();
     ProfGrid()->Col = col;
     ProfGrid()->Row = row;
     ProfGrid()->TopRow = TopRow;
     ProfGrid()->LeftCol = LeftCol;
     ProfGrid()->SpreadsheetEnabled = true;
     ProfGrid()->EnableControls();
     Screen->Cursor = crDefault;
     }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::SSPasteAction1Execute(TObject *Sender)
{
   TcxGridTableView* CurrentTableView = NULL;

   if (PageControl1->ActivePage == TabSheet1) {
	 ProfGrid()->PasteFromClipboard();
     SpreadSheetChanged = true;
     }
   else if (PageControl1->ActivePage == TabSheet2) {
     //SendMessage(ActiveControl->Handle, WM_PASTE, 0, 0);
     if (PageControl2->ActivePage == TabSheetLithology)
       CurrentTableView = dynamic_cast< TcxGridTableView *>(cxGrid1->FocusedView);
     else if (PageControl2->ActivePage == TabSheetGeochron)
       CurrentTableView = dynamic_cast< TcxGridTableView *>(cxGrid2->FocusedView);
     else if (PageControl2->ActivePage == TabSheetAgeModels)
       CurrentTableView = dynamic_cast< TcxGridTableView *>(cxGrid3->FocusedView);
	 else if (PageControl2->ActivePage == TabSheetLOI)
	   AdvColumnGrid5->PasteSelectionFromClipboard();

     if (CurrentTableView) {
	   PasteGrid((TcxCustomGridTableView*)CurrentTableView);
	   Clipboard()->Open();
       Clipboard()->SetTextBuf(GridPaste.c_str());
	   Clipboard()->Close();
	   //GridPaste.SetLength(0);
 	   AfterGridPaste(GridPaste, CurrentTableView);
	   }
     else
       SendMessage(ActiveControl->Handle, WM_PASTE, 0, 0);
     }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::ClearAllAction1Execute(
      TObject *Sender)
{
   TProfGrid* Grid = ProfGrid();
   if (!Grid) return;

   if (MessageDlg("Clear entire worksheet?", mtConfirmation,
       TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes) {
       Grid->ResetCells();
       SpreadSheetChanged = true;
       }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::SortAction1Execute(TObject *Sender)
{
   SSSort();
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::ToggleRareAction1Execute(
      TObject *Sender)
{
   MarkRareTypes(ProfGrid1);  //raretype
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::InsertRowAction1Execute(
      TObject *Sender)
{
   TProfGrid* Grid = ProfGrid();
   if (!Grid) return;

   int ARow = Grid->Row;
   if (ARow < Grid->FixedRows)
     MessageDlg("Cannot insert row in header.", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
   else {
	 Grid->InsertRow(ARow);
	 UNDO undo(ROWSINSERTED, Grid);
     undo.rc.push_back(ARow-1);
     AddUnDo(undo);
	 SpreadSheetChanged = true;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::DeleteRowAction1Execute(
      TObject *Sender)
{
   UnicodeString msg;

   TProfGrid* Grid = ProfGrid();
   if (!Grid) return;

   int Top = Grid->Selection->Rect.Top;

   if (Top < Grid->FixedRows)
     MessageDlg("Cannot delete row in header.", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
   else {
     int Bottom = Grid->Selection->Rect.Bottom;
     int Left = Grid->Selection->Rect.Left;
	 int Right = Grid->Selection->Rect.Right;
     Grid->DisableControls();
     Grid->SpreadsheetEnabled = false;

	 if (Downloaded && tiLicense->Type() == verNEOTOMASTEWARD && Grid == ProfGrid1) {
	   for (int row = Bottom; row >= Top; row--) {
		 UnicodeString VarCode = Grid->AbsoluteCells[1][row]->Text;
		 if (VarCode[1] == L'#') {
		   msg = L"Cannot delete metadata item " + VarCode + L".";
		   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   }
		 else {
		   UnicodeString VarName = Grid->AbsoluteCells[2][row]->Text;
		   msg = L"Delete variable «" + VarName + L"» from Neotoma? Deletion cannot be undone.";
		   if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes) {
			 if (DeleteNeotomaVariable(row))
			   Grid->DeleteRow(row);
			 }
		   }
		 }
	   Grid->SpreadsheetEnabled = true;
	   Grid->EnableControls();
	   SpreadSheetChanged = true;
	   return;
	   }

	 if (Left == 1 && Right == Grid->ColCount-1) {  // whole rows marked
	   UNDO undo(ROWSDELETED, Grid);
       int CurrentRow = Top;
       undo.rc.push_back(Top);
	   for (int i=0; i<Grid->Selection->Count; i++) {
		 TProfGridCell* ACell = Grid->Selection->Cells[i];
         if (ACell->AbsoluteRow != CurrentRow) {
           CurrentRow = ACell->AbsoluteRow;
           undo.rc.push_back(CurrentRow);
           }
		 if (!GridCellIsEmpty(ACell)) {
		   UNDOCELL Cell;
		   Cell.Col = ACell->AbsoluteCol;
           Cell.Row = ACell->AbsoluteRow;
           Cell.Value = ACell->Value;
		   if (ACell->CellObject != NULL) {
			 CELLOBJECT* CellObject = new CELLOBJECT((CELLOBJECT*)ACell->CellObject);
			 Cell.Object = (TObject*)CellObject;
			 }
		   undo.Cells.push_back(Cell);
		   }
		 else if (ACell->CheckBox) {
		   UNDOCELL Cell;
		   Cell.Col = ACell->AbsoluteCol;
		   Cell.Row = ACell->AbsoluteRow;
		   Cell.CheckBox = true;
		   Cell.Value = ACell->CheckBoxChecked;
		   if (ACell->CellObject != NULL) {
			 CELLOBJECT* CellObject = new CELLOBJECT((CELLOBJECT*)ACell->CellObject);
			 Cell.Object = (TObject*)CellObject;
			 }
		   undo.Cells.push_back(Cell);
           }
         }
	   list<int>::reverse_iterator ritr = undo.rc.rbegin();
	   while (ritr != undo.rc.rend()) {
		 CheckDatasetDelete(Grid, *ritr, undo);
		 DeleteSSMetadataItem(Grid, *ritr);
		 Grid->DeleteRow(*ritr);
		 ritr++;
		 }
	   AddUnDo(undo);
       Grid->SetSelection(Left, Top, Left, Top);
	   }
	 else {
	   UNDO undo(ROWSDELETED, Grid);
       for (int row=Top; row<=Bottom; row++) {
         undo.rc.push_back(row);
         for (int col=1; col<Grid->AbsoluteColCount; col++) {
           TProfGridCell* ACell = Grid->AbsoluteCells[col][row];
           if (!ACell->Value.IsNull() && !ACell->Value.IsEmpty()) {
             UNDOCELL Cell;
             Cell.Col = ACell->AbsoluteCol;
             Cell.Row = ACell->AbsoluteRow;
             Cell.Value = ACell->Value;
			 if (ACell->CellObject != NULL) {
			   CELLOBJECT* CellObject = new CELLOBJECT((CELLOBJECT*)ACell->CellObject);
			   Cell.Object = (TObject*)CellObject;
			   }
			 undo.Cells.push_back(Cell);
             }
		   }
		 }
	   for (int row=Bottom; row>=Top; row--) {
		 CheckDatasetDelete(Grid, row, undo);
		 DeleteSSMetadataItem(Grid, row);
		 Grid->DeleteRow(row);
		 }
	   AddUnDo(undo);
	   Grid->SetSelection(Left, Top, Left, Top);
	   }

	 Grid->SpreadsheetEnabled = true;
	 Grid->EnableControls();
	 SpreadSheetChanged = true;
	 }
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::DeleteSSMetadataItem(TProfGrid* Grid, int ARow)
{
   if (Grid != ProfGrid1)
	 return;
   UnicodeString VarCode = Grid->AbsoluteCells[1][ARow]->Text;
   if (VarCode.IsEmpty() || VarCode[1] != L'#')
	 return;
   if (SameText(VarCode.SubString(2,4), L"Site")) {
	 VarCode.Delete(1,6);
	 if (SameText(VarCode, L"LatN")) {
	   for (int i = 0; i < Sites->Count; i++) {
		 SITE* Site = (SITE*)Sites->Items[i];
		 Site->LatNorth = Unassigned();
		 }
	   }
	 else if (SameText(VarCode, L"LatSN")) {
	   for (int i = 0; i < Sites->Count; i++) {
		 SITE* Site = (SITE*)Sites->Items[i];
		 Site->LatSouth = Unassigned();
		 }
	   }
	 else if (SameText(VarCode, L"LongW")) {
	   for (int i = 0; i < Sites->Count; i++) {
		 SITE* Site = (SITE*)Sites->Items[i];
		 Site->LongWest = Unassigned();
		 }
	   }
	 else if (SameText(VarCode, L"LongE")) {
	   for (int i = 0; i < Sites->Count; i++) {
		 SITE* Site = (SITE*)Sites->Items[i];
		 Site->LongEast = Unassigned();
		 }
	   }
	 else if (SameText(VarCode, L"GeoPol1")) {
	   for (int i = 0; i < Sites->Count; i++) {
		 SITE* Site = (SITE*)Sites->Items[i];
		 Site->Country = L"";
		 }
	   }
	 else if (SameText(VarCode, L"GeoPol2")) {
	   for (int i = 0; i < Sites->Count; i++) {
		 SITE* Site = (SITE*)Sites->Items[i];
		 Site->State = L"";
		 }
	   }
	 else if (SameText(VarCode, L"GeoPol3")) {
	   for (int i = 0; i < Sites->Count; i++) {
		 SITE* Site = (SITE*)Sites->Items[i];
		 Site->County = L"";
		 }
	   }
	 else if (SameText(VarCode, L"Admin")) {
	   for (int i = 0; i < Sites->Count; i++) {
		 SITE* Site = (SITE*)Sites->Items[i];
		 Site->AdminUnit = L"";
		 }
	   }
	 else if (SameText(VarCode, L"Altitude")) {
	   for (int i = 0; i < Sites->Count; i++) {
		 SITE* Site = (SITE*)Sites->Items[i];
		 Site->Altitude = Unassigned();
		 }
	   }
	 else if (SameText(VarCode, L"Area")) {
	   for (int i = 0; i < Sites->Count; i++) {
		 SITE* Site = (SITE*)Sites->Items[i];
		 Site->Area = Unassigned();
		 }
	   }
	 else if (SameText(VarCode, L"Desc")) {
	   for (int i = 0; i < Sites->Count; i++) {
		 SITE* Site = (SITE*)Sites->Items[i];
		 Site->SiteDescription = L"";
		 }
	   }
	 else if (SameText(VarCode, L"Notes")) {
	   for (int i = 0; i < Sites->Count; i++) {
		 SITE* Site = (SITE*)Sites->Items[i];
		 Site->Notes = L"";
		 }
	   }
	 }
   else if (SameText(VarCode.SubString(2,4), L"Lake")) {
	 VarCode.Delete(1,6);
	 UnicodeString LakeParamName;
	 list<LAKEPARAMETER>::iterator it;
	 for (it = LakeChar.begin(); it != LakeChar.end(); it++) {
	   if (SameText(it->Code, VarCode)) {
		 LakeParamName = it->Name;
		 break;
		 }
	   }
     for (int i = 0; i < Sites->Count; i++) {
	   SITE* Site = (SITE*)Sites->Items[i];
	   vector<LAKEPARAM>::iterator itr;
	   for (itr = Site->LakeParams.begin(); itr != Site->LakeParams.end(); itr++) {
		 if (SameText(itr->Name, LakeParamName)) {
		   Site->LakeParams.erase(itr);
		   break;
		   }
		 }
	   }
	 }
   else if (SameText(VarCode.SubString(2,4), L"Coll")) {
	 VarCode.Delete(1,6);
	 if (SameText(VarCode, L"Handle")) {
	   for (int i=0; i<Sites->Count; i++) {
		 SITE* Site = (SITE*)Sites->Items[i];
		 for (unsigned int j = 0; j < Site->CollUnits.size(); j++)
		   Site->CollUnits[j].Handle = L"";
		 }
	   }
	 else if (SameText(VarCode, L"Name")) {
	   for (int i=0; i<Sites->Count; i++) {
		 SITE* Site = (SITE*)Sites->Items[i];
		 for (unsigned int j = 0; j < Site->CollUnits.size(); j++)
		   Site->CollUnits[j].CollectionName = L"";
		 }
	   }
	 else if (SameText(VarCode, L"Type")) {
	   for (int i=0; i<Sites->Count; i++) {
		 SITE* Site = (SITE*)Sites->Items[i];
		 for (unsigned int j = 0; j < Site->CollUnits.size(); j++)
		   Site->CollUnits[j].CollectionType = L"";
		 }
	   }
	 else if (SameText(VarCode, L"Device")) {
	   for (int i=0; i<Sites->Count; i++) {
		 SITE* Site = (SITE*)Sites->Items[i];
		 for (unsigned int j = 0; j < Site->CollUnits.size(); j++)
		   Site->CollUnits[j].CollectionDevice = L"";
		 }
	   }
	 else if (SameText(VarCode, L"Contacts")) {
	   for (int i=0; i<Sites->Count; i++) {
		 SITE* Site = (SITE*)Sites->Items[i];
		 for (unsigned int j = 0; j < Site->CollUnits.size(); j++)
		   Site->CollUnits[j].Collectors.clear();
		 }
	   }
	 else if (SameText(VarCode, L"Date")) {
	   for (int i=0; i<Sites->Count; i++) {
		 SITE* Site = (SITE*)Sites->Items[i];
		 for (unsigned int j = 0; j < Site->CollUnits.size(); j++)
		   Site->CollUnits[j].CollDate = Unassigned();
		 }
	   }
	 else if (SameText(VarCode, L"Loc")) {
	   for (int i=0; i<Sites->Count; i++) {
		 SITE* Site = (SITE*)Sites->Items[i];
		 for (unsigned int j = 0; j < Site->CollUnits.size(); j++)
		   Site->CollUnits[j].Location = L"";
		 }
	   }
	 else if (SameText(VarCode, L"GPSLat")) {
	   for (int i=0; i<Sites->Count; i++) {
		 SITE* Site = (SITE*)Sites->Items[i];
		 for (unsigned int j = 0; j < Site->CollUnits.size(); j++)
		   Site->CollUnits[j].GPSLat = Unassigned();
		 }
	   }
	 else if (SameText(VarCode, L"GPSLong")) {
	   for (int i=0; i<Sites->Count; i++) {
		 SITE* Site = (SITE*)Sites->Items[i];
		 for (unsigned int j = 0; j < Site->CollUnits.size(); j++)
		   Site->CollUnits[j].GPSLong = Unassigned();
		 }
	   }
	 else if (SameText(VarCode, L"GPSErr")) {
	   for (int i=0; i<Sites->Count; i++) {
		 SITE* Site = (SITE*)Sites->Items[i];
		 for (unsigned int j = 0; j < Site->CollUnits.size(); j++)
		   Site->CollUnits[j].GPSError = Unassigned();
		 }
	   }
	 else if (SameText(VarCode, L"GPSAlt")) {
	   for (int i=0; i<Sites->Count; i++) {
		 SITE* Site = (SITE*)Sites->Items[i];
		 for (unsigned int j = 0; j < Site->CollUnits.size(); j++)
		   Site->CollUnits[j].GPSAltitude = Unassigned();
		 }
	   }
	 else if (SameText(VarCode, L"DepEnv")) {
	   for (int i=0; i<Sites->Count; i++) {
		 SITE* Site = (SITE*)Sites->Items[i];
		 for (unsigned int j = 0; j < Site->CollUnits.size(); j++)
		   Site->CollUnits[j].DepEnv = L"";
		 }
	   }
	 else if (SameText(VarCode, L"Substrate")) {
	   for (int i=0; i<Sites->Count; i++) {
		 SITE* Site = (SITE*)Sites->Items[i];
		 for (unsigned int j = 0; j < Site->CollUnits.size(); j++)
		   Site->CollUnits[j].Substrate = L"";
		 }
	   }
	 else if (SameText(VarCode, L"Angle")) {
	   for (int i=0; i<Sites->Count; i++) {
		 SITE* Site = (SITE*)Sites->Items[i];
		 for (unsigned int j = 0; j < Site->CollUnits.size(); j++)
		   Site->CollUnits[j].SlopeAngle = Unassigned();
		 }
	   }
	 else if (SameText(VarCode, L"Aspect")) {
	   for (int i=0; i<Sites->Count; i++) {
		 SITE* Site = (SITE*)Sites->Items[i];
		 for (unsigned int j = 0; j < Site->CollUnits.size(); j++)
		   Site->CollUnits[j].SlopeAspect = Unassigned();
		 }
	   }
	 else if (SameText(VarCode, L"WaterDep")) {
	   for (int i=0; i<Sites->Count; i++) {
		 SITE* Site = (SITE*)Sites->Items[i];
		 for (unsigned int j = 0; j < Site->CollUnits.size(); j++)
		   Site->CollUnits[j].WaterDepth = Unassigned();
		 }
	   }
	 else if (SameText(VarCode, L"Notes")) {
	   for (int i=0; i<Sites->Count; i++) {
		 SITE* Site = (SITE*)Sites->Items[i];
		 for (unsigned int j = 0; j < Site->CollUnits.size(); j++)
		   Site->CollUnits[j].Notes = L"";
		 }
	   }
	 }
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::CheckDatasetDelete(TProfGrid* Grid, int row, UNDO& undo)
{
   if (Grid == ProfGrid1) {
	 UnicodeString Text = Grid->AbsoluteCells[1][row]->Text;
	 if (SameText(Text, L"#Data.Type")) {
	   UnicodeString msg = L"Cannot undo deletion of #Data.Type.";
	   if (MessageDlg(msg, mtWarning, TMsgDlgButtons() << mbOK << mbCancel, 0) == mrOk) {
		 UnicodeString DatasetType = Grid->AbsoluteCells[2][row]->Text;
		 list<UNDOCELL>::iterator it;
		 it = undo.Cells.begin();
		 bool start_over;
		 while (it != undo.Cells.end()) {
		   start_over = false;
		   if (it->Row == row) {
			 if (it->Col == 1 || it->Col == 2) {
			   if (it->Object != NULL) {
				 CELLOBJECT* CellObject = (CELLOBJECT*)it->Object;
				 delete CellObject;
				 }
			   undo.Cells.erase(it);
			   it = undo.Cells.begin();
			   start_over = true;
			   }
			 }
		   if (!start_over) it++;
		   }

		 vector<DATASET>::iterator itr;
		 for (itr = Datasets.begin()+1; itr != Datasets.end(); itr++) {
		   if (SameText(itr->DatasetType, DatasetType)) {
			 Datasets.erase(itr);
			 break;
			 }
		   }
		 }
	   }
     }
}
//---------------------------------------------------------------------------

bool TTilSpreadSheetForm::GridCellIsEmpty(TProfGridCell* ACell)
{
   return (ACell->Value.IsNull() || ACell->Value.IsEmpty());
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::InsertColumnAction1Execute(
      TObject *Sender)
{
   TProfGrid* Grid = ProfGrid();
   if (!Grid) return;

   if (Grid->Col < Grid->FixedCols)
     MessageDlg("Cannot insert column in header.\nSee Tools->Options to show header columns.", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
   else {
     Grid->InsertColumn(Grid->Col);
     // checkbox rows
     int RowCount = ContentRowCount(Grid);
     TProfGridColumn* Codes = Grid->AbsoluteCols[1];
     for (int r=3; r<=RowCount; r++) {
       UnicodeString Code = Codes->Cells[r]->Text;
	   //if (SameText(Code, "#SAMP.MODERN") || SameText(Code, "#ANAL.MIXED")) [
	   if (SameText(Code, "#ANAL.MIXED")) {
		 Grid->Cells[Grid->Col-1][r]->CheckBox = true;
         break;
		 }
	   }
	 UNDO undo(COLSINSERTED, Grid);
     undo.rc.push_back(Grid->Cols[Grid->Col-1]->AbsoluteNumber);
     AddUnDo(undo);
     SpreadSheetChanged = true;
     }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::DeleteColumnAction1Execute(
      TObject *Sender)
{
   TProfGrid* Grid = ProfGrid();
   if (!Grid) return;

   if (Grid->Col < Grid->FixedCols)
     MessageDlg("Cannot delete column in header.\nSee Tools->Options to hide header columns.", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
   else {
	 int Left = Grid->Selection->Rect.Left;
	 int Right = Grid->Selection->Rect.Right;
	 int Top = Grid->Selection->Rect.Top;
	 int Bottom = Grid->Selection->Rect.Bottom;
	 Grid->DisableControls();
	 Grid->SpreadsheetEnabled = false;

	 // delete #Site.Name if necessary
	 if (Grid == ProfGrid1) {
	   int SiteNameRow = FindRowMD(SITE_NAME);
	   if (SiteNameRow > 0) {
		 bool found = false;
		 for (int col=Left; col<=Right; col++) {
		   if (!Grid->Cells[col][SiteNameRow]->IsEmpty()) {
			 found = true;
			 break;
			 }
		   }
		 if (found) {
		   UnicodeString msg = L"Deleting Site cannot be undone.";
		   if (MessageDlg(msg, mtWarning, TMsgDlgButtons() << mbOK << mbCancel, 0) == mrOk) {
			 Variant Value = Unassigned();
			 for (int col=Right; col>=Left; col--) {
			   TProfGridCell* ACell = Grid->Cells[col][SiteNameRow];
			   DeleteSSSiteName(Value, ACell, col, SiteNameRow, false);
			   //Grid->DeleteColumn(col);
			   DeleteColumn(Grid,col);
			   }
			 }
		   Grid->SpreadsheetEnabled = true;
		   Grid->EnableControls();
		   return;
		   }
		 }
	   int CollNameRow = FindRowMD(COLL_UNIT_NAME);
	   if (CollNameRow > 0) {
		 bool found = false;
		 for (int col=Left; col<=Right; col++) {
		   if (!Grid->Cells[col][CollNameRow]->IsEmpty()) {
			 found = true;
			 break;
			 }
		   }
		 if (found) {
		   UnicodeString msg = L"Deleting Collection Unit cannot be undone.";
		   if (MessageDlg(msg, mtWarning, TMsgDlgButtons() << mbOK << mbCancel, 0) == mrOk) {
			 SITE* site_ptr = (SITE*)Sites->Items[0];;
			 Variant Value = Unassigned();
			 for (int col=Left; col<=Right; col++) {
			   TProfGridCell* ACell = Grid->Cells[col][SiteNameRow];
			   DeleteSSCollName(Value, site_ptr, ACell, ACell->Text, 0, col, CollNameRow, false);
			   //Grid->DeleteColumn(col);
               DeleteColumn(Grid,col);
			   }
			 }
		   Grid->SpreadsheetEnabled = true;
		   Grid->EnableControls();
		   return;
		   }
		 }
	   }

	 if (Top == 1 && Bottom == Grid->RowCount-1) {  // whole columns marked
	   UNDO undo(COLSDELETED, Grid);
	   undo.rc.push_back(Grid->Cols[Left]->AbsoluteNumber);
	   for (int i=0; i<Grid->Selection->Count; i++) {
		 TProfGridCell* ACell = Grid->Selection->Cells[i];
		 list<int>::iterator it = find(undo.rc.begin(), undo.rc.end(), ACell->AbsoluteCol);
		 if (it == undo.rc.end())
		   undo.rc.push_back(ACell->AbsoluteCol);
		 if (!ACell->IsEmpty()) {
		   UNDOCELL Cell;
		   Cell.Col = ACell->AbsoluteCol;
		   Cell.Row = ACell->AbsoluteRow;
		   Cell.Value = ACell->Value;
		   if (ACell->CellObject != NULL) {
			 CELLOBJECT* CellObject = new CELLOBJECT((CELLOBJECT*)ACell->CellObject);
			 if (CellObject->ObjectType == CELLSPECIMENS)
			   DeleteCellObject(ACell);
			 else
			   Cell.Object = (TObject*)CellObject;
			 }
		   undo.Cells.push_back(Cell);
		   }
		 else if (ACell->CheckBox) {
           UNDOCELL Cell;
           Cell.Col = ACell->AbsoluteCol;
           Cell.Row = ACell->AbsoluteRow;
           Cell.CheckBox = true;
           Cell.Value = ACell->CheckBoxChecked;
		   if (ACell->CellObject != NULL) {
			 CELLOBJECT* CellObject = new CELLOBJECT((CELLOBJECT*)ACell->CellObject);
			 Cell.Object = (TObject*)CellObject;
			 }
		   undo.Cells.push_back(Cell);
           }
         }
       AddUnDo(undo);
       list<int>::reverse_iterator citr = undo.rc.rbegin();
       while (citr != undo.rc.rend()) {
         int col = Grid->AbsoluteCols[*citr]->VisibleNumber;
		 //Grid->DeleteColumn(col);
         DeleteColumn(Grid,col);
		 citr++;
         }
       Grid->SetSelection(Left, Top, Left, Top);
       }
     else {
       UNDO undo(COLSDELETED, Grid);
       for (int col=Left; col<=Right; col++) {
         undo.rc.push_back(Grid->Cols[col]->AbsoluteNumber);
         for (int row=1; row<Grid->AbsoluteRowCount; row++) {
           TProfGridCell* ACell = Grid->Cells[col][row];
		   if (!ACell->IsEmpty()) {
             UNDOCELL Cell;
             Cell.Col = ACell->AbsoluteCol;
			 Cell.Row = ACell->AbsoluteRow;
             Cell.Value = ACell->Value;
			 if (ACell->CellObject != NULL) {
			   CELLOBJECT* CellObject = new CELLOBJECT((CELLOBJECT*)ACell->CellObject);
			   if (CellObject->ObjectType == CELLSPECIMENS)
				 DeleteCellObject(ACell);
			   else
			     Cell.Object = (TObject*)CellObject;
			   }
			 undo.Cells.push_back(Cell);
             }
           }
         }
       AddUnDo(undo);
       for (int col=Right; col>=Left; col--)
		 //Grid->DeleteColumn(col);
		 DeleteColumn(Grid,col);
       Grid->SetSelection(Left, Top, Left, Top);
       }

	 Grid->SpreadsheetEnabled = true;
	 Grid->EnableControls();
     SpreadSheetChanged = true;
     }
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::DeleteColumn(TProfGrid *Grid, int col)
{
   UnicodeString msg, ErrorMsg;

   if (Grid != ProfGrid1)
	 return;

   if (Downloaded && tiLicense->Type() == verNEOTOMASTEWARD) {
	 int DatasetIdx;
	 if (!ValidateSteward(DatasetIdx))
	   return;
	 int SampleID;
	 if (!Grid->Cells[col][1]->CustomData.IsEmpty()) {
	   SampleID = VariantToInt(Grid->Cells[col][1]->CustomData, -1);
	   if (SampleID != -1) {
		 // ShowMessage(L"col = " + IntToStr(col) + L", SampleID = " + IntToStr(SampleID));
		 UnicodeString DatasetType = Grid->AbsoluteCells[1][1]->Text;
		 msg = L"Delete " + DatasetType + L" sample " + IntToStr(SampleID) + L"?";
		 if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes) {
		   Screen->Cursor = crHourGlass;
		   DeleteData DeleteSample(L"DeleteSampleAnalysisUnit", 1, ipsHTTPS1, ipsJSONS1, TcpClient1);
		   DeleteSample.Add(L"SAMPLEID", SampleID);
		   if (DeleteSample.Post(ErrorMsg)) {
			 msg = DatasetType + L" sample " + IntToStr(SampleID) + L" deleted from Neotoma.";
			 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
			 }
		   else {
			 msg = L"Attempt to delete sample " + IntToStr(SampleID) + L" failed.";
			 if (!ErrorMsg.IsEmpty())
			   msg += (L": " + ErrorMsg);
			 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			 }
		   Screen->Cursor = crDefault;
		   }
		 }
	   }
	 }

   Grid->DeleteColumn(col);
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::DeleteWorksheetAction1Execute(
      TObject *Sender)
{
   DeleteSheet();
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::InsertCONISSSheetAction1Execute(
      TObject *Sender)
{
   InsertCONISSSheet();
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::SumsAction1Execute(TObject *Sender)
{
   TSumsForm *SumsForm = new TSumsForm(this);
   //SumsForm->TilSpreadSheetForm = this;

   int result = SumsForm->ShowModal();
   int SumsAs = SumsForm->RadioGroup1->ItemIndex;
   delete SumsForm;
   if (result == mrOk)
	 CalculateSums(SumsAs);
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::PercentsAction1Execute(
      TObject *Sender)
{
   CalculatePercents(dtCustom);
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::VariableLookupAction1Execute(
      TObject *Sender)
{
   VariableLookup();
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::EditTaxaAction1Execute(
      TObject *Sender)
{
   EditTaxa();
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::EditGroupsAction1Execute(
      TObject *Sender)
{
   EditGroups();
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::EditElementsAction1Execute(
      TObject *Sender)
{
   EditElements();
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::EditUnitsAction1Execute(
      TObject *Sender)
{
   EditUnits();
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::EditContextsAction1Execute(
      TObject *Sender)
{
   EditContexts();
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::EditTaphonomyAction1Execute(
      TObject *Sender)
{
   EditTaphonomy();
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::EditFaciesAction1Execute(TObject *Sender)
{
   EditFacies();
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::EditDepAgentAction1Execute(TObject *Sender)
{
   EditDepAgents();
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::NewTaxaAction1Execute(TObject *Sender)
{
   NewTaxa();
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::NewGroupsAction1Execute(
      TObject *Sender)
{
   NewGroups();
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::NewElementsAction1Execute(
      TObject *Sender)
{
   NewElements();
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::NewUnitsAction1Execute(
      TObject *Sender)
{
   NewUnits();
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::NewContextsAction1Execute(
      TObject *Sender)
{
   NewContexts();
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::NewTaphonomyAction1Execute(
      TObject *Sender)
{
   NewTaphonomy();
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::CheckVariablesAction1Execute(
      TObject *Sender)
{
   CheckVariables();
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::ChronologyAction1Execute(
      TObject *Sender)
{
   Chronology();
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::ClusterAnalysisAction1Execute(
      TObject *Sender)
{
   double x;
   bool Unconstrained = false;

   ConissForm = new TConissForm(this);
   //if (ConissForm->ShowModal() == mrCancel) return;
   ConissForm->ShowModal();
   if (ConissForm->Unconstrained()) {
     Reorder.clear();
     Reorder = ConissForm->order;
     Unconstrained = true;
     }
   delete ConissForm;

   if (Unconstrained)
     ReorderSamples();

   if (MessageDlg("Convert values in CONISS worksheeet to percentages?",
	 mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes)
	 {
     Screen->Cursor = crHourGlass;
     TProfGrid* Grid = Workbook->Sheets[cxPageControl1->ActivePage];
     Grid->DisableControls();
     Grid->SpreadsheetEnabled = false;
     int HeaderCols = AbsHeaderColCount(Grid);
     int HeaderRows = AbsHeaderRowCount(Grid);
     int ColCount = AbsContentColCount(Grid);
     int RowCount = AbsContentRowCount(Grid);
     for (int col=HeaderCols; col<=ColCount; col++) {
       double sum = 0.0;
       for (int row=HeaderRows; row<=RowCount; row++) {
         x = Grid->AbsoluteCells[col][row]->Value;
         sum += x;
         }
       for (int row=HeaderRows; row<=RowCount; row++) {
         x = Grid->AbsoluteCells[col][row]->Value;
         Grid->AbsoluteCells[col][row]->Value = 100.0*x/sum;
         }
       }
     Grid->SpreadsheetEnabled = true;
     Grid->EnableControls();
     Screen->Cursor = crDefault;
     }
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::ReorderSamples(void)
{
   int HeaderCols;
   int ColCount;
   int size;
   int nsamples;

   Screen->Cursor = crHourGlass;
   TcxTabSheet* ActiveTabSheet = cxPageControl1->ActivePage;
   TProfGrid* Grid = Workbook->Sheets[ActiveTabSheet];
   HeaderCols = AbsHeaderColCount(Grid);
   size = Reorder.size();
   Grid->DisableControls();
   Grid->SpreadsheetEnabled = false;
   for (int j=0; j<size; j++)
     Grid->AbsoluteCells[HeaderCols+Reorder[j]][1]->Value = (double)(j+1);
   Grid->SpreadsheetEnabled = true;
   Grid->EnableControls();
   SortSampleNumbers(Grid);

   if (MessageDlg("Reorder samples in other worksheets?",
	 mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes)
     {
     for (int i=0; i<cxPageControl1->PageCount; i++) {
       TcxTabSheet* TabSheet = cxPageControl1->Pages[i];
       if (TabSheet != ActiveTabSheet) {
         Grid = Workbook->Sheets[TabSheet];
         HeaderCols = AbsHeaderColCount(Grid);
         ColCount = AbsContentColCount(Grid);
         nsamples = ColCount - HeaderCols + 1;
         size = Reorder.size();
         if (nsamples == size) {
           Grid->DisableControls();
           Grid->SpreadsheetEnabled = false;
           for (int j=0; j<size; j++)
             Grid->AbsoluteCells[HeaderCols+Reorder[j]][1]->Value = (double)(j+1);
           Grid->SpreadsheetEnabled = true;
           Grid->EnableControls();
           SortSampleNumbers(Grid);
           }
         }
       }
     }
   Screen->Cursor = crDefault;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::DiagramAction1Execute(TObject *Sender)
{
   MakeDiagram();
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::DefaultDiagramAction1Execute(TObject *Sender)
{
   if (MakeDefaultSums()) {
	 CalculatePercents(dtDefault);
	 SortSampleNumbers(ProfGrid2);
	 SortDefaultPercents();
	 MakeDefaultDiagram();
	 }
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::MakeDefaultDiagram(void)
{
   set<UnicodeString> DefaultElements;
   UnicodeString DatabaseType = ProfGrid1->AbsoluteCells[1][1]->Text;
   if (ContainsText(DatabaseType,L"pollen")) {
	 DefaultElements.insert(L"pollen");
	 DefaultElements.insert(L"spore");
	 DefaultElements.insert(L"pollen/spore");
	 DefaultElements.insert(L"spore/pollen");
	 DefaultElements.insert(L"palynomorph");
	 }
   DiagramParams Params(L"DefaultDiagram.$$$", ProfGrid2);
   if (Sites->Count == 1) {
	 UnicodeString Heading;
	 SitePtr = (SITE*)Sites->Items[0];
	 if (!SitePtr->SiteName.IsEmpty()) {
	   Heading = SitePtr->SiteName;
       int coll_row = FindRowMD(COLL_UNIT_NAME);
	   if (coll_row == 0) {
		 CollPtr = &SitePtr->CollUnits[0];
		 if (!CollPtr->CollectionName.IsEmpty())
		   Heading += (L", " + CollPtr->CollectionName);
		 }
	   Params.Heading = Heading;
	   }
	 }

   int RowCount = AbsContentRowCount(ProfGrid2);
   for (int i=3; i<=RowCount; i++) {
	 UnicodeString VarCode = ProfGrid2->AbsoluteCells[1][i]->Text;
	 UnicodeString VarName = ProfGrid2->AbsoluteCells[2][i]->Text;
	 UnicodeString Element = ProfGrid2->AbsoluteCells[3][i]->Text;
	 UnicodeString Context = ProfGrid2->AbsoluteCells[5][i]->Text;
	 if (!Element.IsEmpty()) {
	   if (DefaultElements.count(Element) == 0)
		 VarName += (L" " + Element);
	   }
	 if (!Context.IsEmpty())
	   VarName += (L" " + Context);
	 bool show = true;
	 if (SameText(VarCode.SubString(1,3),L"SUM"))
	   show = false;
	 else if (SameText(VarCode.SubString(1,4),L"SSUM"))
	   show = false;
	 Params.VarNames.push_back(pair<UnicodeString,bool>(VarName,show));
	 }

   ParentForm->OpenTGDiagramWindow(Params);
   ParentForm->ZoomComboBox->Text = "Fit";
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::SortDefaultPercents()
{
   vector<UnicodeString> MasterOrder;
   set<UnicodeString> PercentGroups;
   TStringList* SortOrder = new TStringList;

   UnicodeString DatabaseType = ProfGrid1->AbsoluteCells[1][1]->Text;
   if (ContainsText(DatabaseType,L"pollen")) {
	 MasterOrder.push_back(L"CHRN");   // chron
	 MasterOrder.push_back(L"");
	 MasterOrder.push_back(L"TRSH");
	 MasterOrder.push_back(L"PALM");
	 MasterOrder.push_back(L"SUCC");
	 MasterOrder.push_back(L"UPHE");
	 MasterOrder.push_back(L"PCON");
	 MasterOrder.push_back(L"ANGI");
	 MasterOrder.push_back(L"EUDI");
	 MasterOrder.push_back(L"SEED");
	 MasterOrder.push_back(L"VASC");
	 MasterOrder.push_back(L"PTER");
	 MasterOrder.push_back(L"VACR");
	 MasterOrder.push_back(L"UPBR");
	 MasterOrder.push_back(L"MANG");
	 MasterOrder.push_back(L"AQVP");
	 MasterOrder.push_back(L"AQBR");
	 MasterOrder.push_back(L"FUNG");
	 MasterOrder.push_back(L"ANAC");
	 MasterOrder.push_back(L"PLNT");
	 MasterOrder.push_back(L"UNID");
	 MasterOrder.push_back(L"NOPO");
	 MasterOrder.push_back(L"ACRI");
	 MasterOrder.push_back(L"ALGA");
	 MasterOrder.push_back(L"ANIM");
	 MasterOrder.push_back(L"ANNL");
	 MasterOrder.push_back(L"ACAR");
	 MasterOrder.push_back(L"ARTH");
	 MasterOrder.push_back(L"CHRM");
	 MasterOrder.push_back(L"CLAD");
	 MasterOrder.push_back(L"COPE");
	 MasterOrder.push_back(L"CRUS");
	 MasterOrder.push_back(L"DIAT");
	 MasterOrder.push_back(L"DINO");
	 MasterOrder.push_back(L"FLWO");
	 MasterOrder.push_back(L"FORM");
	 MasterOrder.push_back(L"DIPT");
	 MasterOrder.push_back(L"LEPI");
	 MasterOrder.push_back(L"NEMA");
	 MasterOrder.push_back(L"EMBR");
	 MasterOrder.push_back(L"PROT");
	 MasterOrder.push_back(L"ROTI");
	 MasterOrder.push_back(L"SPNG");
	 MasterOrder.push_back(L"TEAM");
	 MasterOrder.push_back(L"SILC");
	 MasterOrder.push_back(L"GSUM");  // sums
	 MasterOrder.push_back(L"SSUM");  // super sums
	 }

   int RowCount = AbsContentRowCount(ProfGrid2);
   for (int i=3; i<=RowCount; i++) {
	 UnicodeString VarCode = ProfGrid2->AbsoluteCells[1][i]->Text;
	 if (VarCode[1] == L'#')
	   ProfGrid2->AbsoluteCells[7][i]->Value = WideString(L"CHRN");
	 if (SameText(VarCode.SubString(1,3),L"SUM"))
	   ProfGrid2->AbsoluteCells[7][i]->Value = WideString(L"GSUM");
	 if (SameText(VarCode.SubString(1,4),L"SSUM"))
	   ProfGrid2->AbsoluteCells[7][i]->Value = WideString(L"SSUM");
	 }

   for (int i=3; i<=RowCount; i++) {
	 UnicodeString GroupCode = ProfGrid2->AbsoluteCells[7][i]->Text;
	 if (PercentGroups.count(GroupCode) == 0)
	   PercentGroups.insert(GroupCode);
	 }

   for (unsigned int i=0; i<MasterOrder.size(); i++) {
	 if (PercentGroups.count(MasterOrder[i]) > 0)
	   SortOrder->Add(MasterOrder[i]);
	 }

   ProfGrid2->DisableControls();
   ProfGrid2->SpreadsheetEnabled = false;
   SortRows(2, ProfGrid2);
   SortRows(7, SortOrder, ProfGrid2);
   ProfGrid2->SpreadsheetEnabled = true;
   ProfGrid2->EnableControls();
   delete SortOrder;
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::GetValidElements(set<UnicodeString>& ValidElements,
	map<int,pair<UnicodeString,UnicodeString> >& ElementGroupCodes, UnicodeString& InvalidGroup)
{
   UnicodeString DatabaseType = ProfGrid1->AbsoluteCells[1][1]->Text;
   if (ContainsText(DatabaseType,L"pollen")) {
	 ValidElements.insert(L"pollen");
	 ValidElements.insert(L"spore");
	 ValidElements.insert(L"pollen/spore");
	 ValidElements.insert(L"spore/pollen");
	 InvalidGroup = L"NOPO";
	 }

   int RowCount = AbsContentRowCount(ProfGrid1);
   for (int i=3; i<=RowCount; i++) {
	 UnicodeString Element = ProfGrid1->AbsoluteCells[3][i]->Text.LowerCase();
	 UnicodeString GroupCode = ProfGrid1->AbsoluteCells[7][i]->Text;
	 ElementGroupCodes[i] = pair<UnicodeString,UnicodeString>(Element,GroupCode);
	 }
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::ReplaceDefaultElementGroups(map<int,pair<UnicodeString,UnicodeString> >& ElementGroupCodes)
{
   map<int,pair<UnicodeString,UnicodeString> >::iterator itr;
   for (itr = ElementGroupCodes.begin(); itr != ElementGroupCodes.end(); itr++) {
	 UnicodeString GroupCode = ProfGrid1->AbsoluteCells[7][itr->first]->Value;
	 if (!SameText(GroupCode,itr->second.second))
	   ProfGrid1->AbsoluteCells[7][itr->first]->Value = WideString(itr->second.second);
	 }
}
//---------------------------------------------------------------------------

bool TTilSpreadSheetForm::MakeDefaultSums(void)
{
   vector<SUPERSUM> SuperSums;
   set<UnicodeString> ValidElements;
   map<int,pair<UnicodeString,UnicodeString> > ElementGroupCodes;
   UnicodeString InvalidGroup;
   int Row;

   TSumList* SumList = new TSumList();
   LoadSumData(SumList);

   GetValidElements(ValidElements, ElementGroupCodes, InvalidGroup);
   SUMS Sums(SumList, ValidElements, ElementGroupCodes, InvalidGroup);
   if (!Sums.ValidCodes) {
	 MessageDlg("Unrecognized Group code. Cannot calculate default sums.",
				Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 return false;
	 }

   ReplaceDefaultElementGroups(ElementGroupCodes);

   UnicodeString SumCode;
   vector<UnicodeString>::iterator itr;
   vector<SUPERSUMVARIABLE>::iterator start = Sums.SSVar.begin();
   vector<SUPERSUMVARIABLE>::iterator stop = Sums.SSVar.end();
   vector<SUPERSUMVARIABLE>::iterator ssitr;

   for (ssitr=start; ssitr != stop; ssitr++) {
	 itr = find(Sums.UsedBases.begin(), Sums.UsedBases.end(), (*ssitr).Code);
	 if (itr != Sums.UsedBases.end()) {      // PPPRRPPPTTT   one letter code found
	   SumCode = L"";
	   for (int i=0; i<SumList->Count; i++) {
		 FSUM* fsum = SumList->Sums[i];
		 UnicodeString Base = Sums.SVar[fsum->Code].Base;
		 vector<UnicodeString>::iterator it = find((*ssitr).Base.begin(), (*ssitr).Base.end(), Base);
		 if (it != (*ssitr).Base.end()) {
		   if (SumCode.Length() == 0)
			 SumCode = fsum->Code;
		   else {
			 SumCode += ";";
			 SumCode += fsum->Code;
			 }
		   }
		 }
	   SUPERSUM SSum;
	   SSum.Code = *itr;
	   SSum.Name = (*ssitr).Name;
	   SSum.Sums = SumCode;
	   SuperSums.push_back(SSum);
	   }
	 }

   for (int i=0; i<SumList->Count; i++) {
	 FSUM* fsum = SumList->Sums[i];
	 fsum->Base = Sums.UsedBases[i];
	 }

   MakeSumVars(Row, SumList);

   for (unsigned int i=0; i<SuperSums.size(); i++) {
	 ProfGrid1->AbsoluteCells[1][Row]->Value = WideString(L"SSUM(" + SuperSums[i].Code + L")");
	 ProfGrid1->AbsoluteCells[2][Row]->Value = WideString(SuperSums[i].Name);
	 ProfGrid1->AbsoluteCells[7][Row]->Value = WideString(SuperSums[i].Sums);
	 AddSSum(SuperSums[i].Code, SuperSums[i].Sums, Row++);
	 }

   CalculateSums(0);

   SpreadSheetChanged = true;
   delete SumList;
   return true;
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::LoadSumData(TSumList* SumList)
{
  UnicodeString SumCode, VarCode;

  int RowCount = AbsContentRowCount(ProfGrid1);
  for (int i=3; i<=RowCount; i++) {
	SumCode = ProfGrid1->AbsoluteCells[7][i]->Text;
	bool found = false;
	if (!SumCode.IsEmpty()) {
	  VarCode = ProfGrid1->AbsoluteCells[1][i]->Text;
	  if (SumCode[1] != '-' && VarCode.SubString(1,3) != L"SUM" &&
		  VarCode.SubString(1,4) != L"SSUM") {
		for (int k=0; k<SumList->Count; k++) {
		  FSUM* Sum = (FSUM*)SumList->Items[k];
		  if (SumCode == Sum->Code) {
			found = true;
			break;
			}
		  }
		if (!found) {
		  FSUM* Sum = new FSUM(SumCode);
		  Sum->Base = L"none";
		  SumList->Add(Sum);
		  }
		}
	  }
	}
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::MakeSumVars(int& Row, TSumList* SumList)
{
   ClearSums();
   ClearSSums();

   int StartSumsRow = AbsContentRowCount(ProfGrid1) + 1;
   Row = StartSumsRow;

   for (int i=0; i<SumList->Count; i++) {
	 FSUM* Sum = (FSUM*)SumList->Items[i];
	 if (Sum->Skip) continue;
	 AddSum(Sum->Code, Sum->Base, Sum->Percent, Row);
	 UnicodeString SumCode = L"SUM(" + Sum->Code + L")";
	 ProfGrid1->AbsoluteCells[1][Row]->Value = WideString(SumCode);
	 ProfGrid1->AbsoluteCells[2][Row]->Value = WideString(Sum->Name);
	 if (Sum->Percent)
	   ProfGrid1->AbsoluteCells[4][Row]->Value = WideString(L"percent");
	 else
	   ProfGrid1->AbsoluteCells[4][Row]->Value = L"";
	 if (!SameText(Sum->Base, L"none"))
	   ProfGrid1->AbsoluteCells[7][Row]->Value = WideString(Sum->Base);
	 Row++;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::OptionsAction1Execute(TObject *Sender)
{
   Options();
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::BuildElementAction1Execute(
      TObject *Sender)
{
   int ARow = ProfGrid1->Row;
   int ACol = ProfGrid1->Col;

   UnicodeString TaxaGroupID;
   if (TaxaLookupOpen) {
	 TAXON Taxon;
	 if (GetTaxon(ARow, Taxon))
	   TaxaGroupID = Taxon.TaxaGroup;
	 else {
	   int index;
	   int AbsRow = ProfGrid1->Rows[ARow]->AbsoluteNumber;
	   UnicodeString TaxonName = ProfGrid1->AbsoluteCells[2][AbsRow]->Text;
	   if (!TaxonName.IsEmpty()) {
		 TAXON Taxon;
		 if (GetTaxon(ARow, Taxon))
		   TaxaGroupID = Taxon.TaxaGroup;
		 }
	   }
	 }

   if (TaxaGroupID.IsEmpty() && !CurrentTaxaGroup.IsEmpty()) {
	 for (unsigned int i= 0; i<TaxaEcolGroups.size(); i++) {
	   if (SameText(CurrentTaxaGroup, TaxaEcolGroups[i].TaxaGroup.Name)) {
		 TaxaGroupID = TaxaEcolGroups[i].TaxaGroup.Code;
		 break;
		 }
	   }
	 }
   UnicodeString Element = ProfGrid1->Cells[ACol][ARow]->Text;
   ElementForm = new TElementForm(Datasets[DatasetNum].DatasetType, TaxaGroupID, Element, ElementLookup, this);

   if (ElementForm->ShowModal() == mrOk) {
	 ProfGrid1->Cells[ACol][ARow]->Value = WideString(ElementForm->Label1->Caption);
	 ProfGrid1->FocusCell(ACol,ARow);
	 CurrentTaxaGroup = ElementForm->cxComboBox3->Text;
	 }
   delete ElementForm;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::FormatTextAction1Execute(
      TObject *Sender)
{
   for (int col=ProfGrid()->Selection->Rect.Left; col<=ProfGrid()->Selection->Rect.Right; col++) {
     for (int row=ProfGrid()->Selection->Rect.Top; row<=ProfGrid()->Selection->Rect.Bottom; row++) {
       try
         {
         ProfGrid()->Cells[col][row]->Value.ChangeType(varOleStr);
		 SpreadSheetChanged = true;
		 }
	   catch(Exception &e)
         {
         MessageDlg(e.Message, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
         return;
         }
	   }
     }
   ProfGrid()->Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::FormatNumberAction1Execute(
      TObject *Sender)
{
   for (int col=ProfGrid()->Selection->Rect.Left; col<=ProfGrid()->Selection->Rect.Right; col++) {
     for (int row=ProfGrid()->Selection->Rect.Top; row<=ProfGrid()->Selection->Rect.Bottom; row++) {
       try
         {
         ProfGrid()->Cells[col][row]->Value.ChangeType(varDouble);
         SpreadSheetChanged = true;
         }
       catch(Exception &e)
         {
         MessageDlg(e.Message, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
         return;
         }
       }
     }
   ProfGrid()->Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::FormatDateAction1Execute(
      TObject *Sender)
{
   for (int col=ProfGrid()->Selection->Rect.Left; col<=ProfGrid()->Selection->Rect.Right; col++) {
     for (int row=ProfGrid()->Selection->Rect.Top; row<=ProfGrid()->Selection->Rect.Bottom; row++) {
       try
         {
         ProfGrid()->Cells[col][row]->Value.ChangeType(varDate);
         SpreadSheetChanged = true;
         }
       catch(Exception &e)
         {
         MessageDlg(e.Message, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
         return;
         }
       }
     }
   ProfGrid()->Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::FormulaToValueAction1Execute(
      TObject *Sender)
{
   TProfGrid* Grid = ProfGrid();
   Grid->DisableControls();
   Grid->SpreadsheetEnabled = false;
   for (int i=0; i<Grid->Selection->Count; i++) {
     Variant Value = Grid->Selection->Cells[i]->Value;
     if (Value.Type() == varDouble) {
       double x = Value;
       Grid->Selection->Cells[i]->Value = x;
       }
     }
   Grid->SpreadsheetEnabled = true;
   Grid->EnableControls();
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::FormatCellsAction1Execute(
      TObject *Sender)
{
   Variant Value;
   WideString Format;
   TProfGridCell* ACell;
   int dec;
   int left, right, top, bottom;
   int VarType;
   UnicodeString msg;

   TSSFormatForm* FormatForm = new TSSFormatForm(this);
   TProfGrid* Grid = ProfGrid();

   TGridRect Rect = Grid->Selection->Rect;

   // select first cell in data region
   if (Rect.Bottom >= Grid->FixedRows && Rect.Right >= Grid->FixedCols) {
     int col = max(Grid->FixedCols, Rect.Left);
     int row = max(Grid->FixedRows, Rect.Top);
     ACell = Grid->Cells[col][row];
     }
   else
     ACell = Grid->Selection->Cells[0];    // selction is within headers

   Format = ACell->Format;
   if (Format.IsEmpty()) {
     FormatForm->RadioButton1->Checked = true;
     FormatForm->cxSpinEdit1->Enabled = false;
     }
   else {
     FormatForm->RadioButton2->Checked = true;
     FormatForm->cxSpinEdit1->Value = Format.Length() - 2;
     }

   Value = ACell->Value;
   // format of first cell in selection
   switch (Value.Type()) {
     case varOleStr:
       FormatForm->RadioGroup2->ItemIndex = 0;
       Panel1->Visible = false;
       break;
     case varDouble:
       FormatForm->RadioGroup2->ItemIndex = 1;
       break;
     case varDate:
       FormatForm->RadioGroup2->ItemIndex = 2;
       Panel1->Visible = false;
       break;
     };

   if (Grid->Selection->Count > 1) {
     FormatForm->RadioGroup1->ItemIndex = 1;        // set to selection
     if (Rect.Right >= Grid->FixedCols && Rect.Bottom >= Grid->FixedRows)
       FormatForm->CheckBox1->Checked = true;       // skip headers
     if (Rect.Left >= Grid->FixedCols && Rect.Bottom >= Grid->FixedRows)
       FormatForm->CheckBox2->Checked = true;       // skip metadata
     }

   Format = Grid->Cells[Grid->Col][Grid->Row]->Format;

   if (FormatForm->ShowModal() == mrOk) {
     Screen->Cursor = crHourGlass;
     Grid->DisableControls();
     Grid->SpreadsheetEnabled = false;

     bool DecimalFormat = FormatForm->RadioButton2->Checked;
	 if (DecimalFormat) {
       dec = FormatForm->cxSpinEdit1->Value;
       Format = "0.";
       for (int i=0; i<dec; i++)
         Format += "0";
       }
     else
       Format.Empty();

     bool SkipHeaders = FormatForm->CheckBox1->Checked;
	 bool SkipMetadata = FormatForm->CheckBox2->Checked;
     switch (FormatForm->RadioGroup2->ItemIndex) {
       case 0: VarType = varOleStr; break;
       case 1: VarType = varDouble; break;
       case 2: VarType = varDate; break;
       };

     if (FormatForm->RadioGroup1->ItemIndex == 2) {   // sheet
       left = 1;
       right = ContentColCount(Grid);
       top = 1;
       bottom = ContentRowCount(Grid);
       }
     else {
       left = Rect.Left;
       right = Rect.Right;
       top = Rect.Top;
       bottom = Rect.Bottom;
       }

     bool Abort = false;
     for (int row=top; row<=bottom; row++) {
       if (SkipHeaders && row < Grid->FixedRows) continue;
       if (SkipMetadata) {
         WideString VarCode = Grid->AbsoluteCells[1][row]->Text;
         if (VarCode.Pos(WideString("#")) == 1) continue;
         }
       for (int col=left; col<=right; col++) {
		 if (SkipHeaders && col < Grid->FixedCols) continue;
         ACell = Grid->Cells[col][row];
         switch (VarType) {
           case varOleStr:
             try {
                 if (ACell->Value.Type() != varOleStr)
                   ACell->Value.ChangeType(varOleStr);
                 }
             catch(Exception &e) {
                 msg = e.Message + ".\nError in cell " + ACell->A1Name + ".";
                 if (MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbIgnore << mbAbort, 0) == mrAbort)
                   Abort = true;
                 }
             break;
           case varDate:
             try {
                 if (ACell->Value.Type() != varDate)
                   ACell->Value.ChangeType(varDate);
                 }
             catch(Exception &e) {
                 msg = e.Message + ".\nError in cell " + ACell->A1Name + ".";
                 if (MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbIgnore << mbAbort, 0) == mrAbort)
                   Abort = true;
                 }
             break;
           case varDouble:
             try {
                 if (ACell->Value.Type() != varDouble)
                   ACell->Value.ChangeType(varDouble);
                 }
             catch(Exception &e) {
                 msg = e.Message + ".\nError in cell " + ACell->A1Name + ".";
                 if (MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbIgnore << mbAbort, 0) == mrAbort) {
                   Abort = true;
                   break;
                   }
                 }
             if (DecimalFormat || !ACell->Format.IsEmpty())
               ACell->Format = Format;
             break;
           }
         if (Abort) break;
         }
       if (Abort) break;
       }
     SpreadSheetChanged = true;
     Grid->SpreadsheetEnabled = true;
     Grid->EnableControls();
     Screen->Cursor = crDefault;
     }
   delete FormatForm;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::chGeochronPropertiesPopup(
      TObject *Sender)
{
   int RecordIndex1 = cxGrid3TableView1->Controller->FocusedRecordIndex;
   int RecordIndex2 = CurrentChronControlView->DataController->FocusedRecordIndex;
   AGEMODEL* AgeModel = AgeModelList->AgeModels[RecordIndex1];

   if (RecordIndex2 >= 0) {
	 CHRON* ChronControl = (CHRON*)AgeModel->ChronControls->Items[RecordIndex2];
	 int size = ChronControl->GeochronIDs.size();

	 // uncheck all Geochron reoords in grid
	 for (int i=1; i<ProfGridGeochron->RowCount; i++)
	   ProfGridGeochron->AbsoluteCells[0][i]->CheckBoxChecked = false;

	 // check any Geochron records in grid already linked
	 if (size > 0) {
	   for (int i=0; i<size; i++) {
		 int ID = ChronControl->GeochronIDs[i];
		 // find the record for this GeoChronControl
		 for (int i=1; i<ProfGridGeochron->RowCount; i++) {
		   int iptr = ProfGridGeochron->AbsoluteCells[1][i]->CustomData;
		   vector<GEOCHRON>::pointer DatePtr = (vector<GEOCHRON>::pointer)iptr;
		   if (ID == DatePtr->ID) {
			 ProfGridGeochron->AbsoluteCells[0][i]->CheckBoxChecked = true;
			 break;
			 }
		   }
		 }
	   }
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::chGeochronPropertiesCloseUp(
      TObject *Sender)
{
   CHRON* ChronControl;
   UnicodeString msg, ErrorMsg;

   int RecordIndex1 = cxGrid3TableView1->Controller->FocusedRecordIndex;
   int RecordIndex2 = CurrentChronControlView->DataController->FocusedRecordIndex;

   if (RecordIndex2 == -1) {
	 NewGeochronIDs.clear();
	 // add any new checked items to GeochronControls
	 for (int i=1; i<ProfGridGeochron->RowCount; i++) {
	   if (ProfGridGeochron->AbsoluteCells[0][i]->CheckBoxChecked) {
		 int iptr = ProfGridGeochron->AbsoluteCells[1][i]->CustomData;
		 vector<GEOCHRON>::pointer DatePtr = (vector<GEOCHRON>::pointer)iptr;
		 NewGeochronIDs.push_back(DatePtr->ID);
		 }
	   }
	 ((TcxPopupEdit*)Sender)->Text = FormatGeochronLinks(NewGeochronIDs);
	 }
   else {
	 AGEMODEL* AgeModel = AgeModelList->AgeModels[RecordIndex1];
	 ChronControl = (CHRON*)AgeModel->ChronControls->Items[RecordIndex2];
	 // add any new checked items to GeochronControls
	 ChronControl->GeochronIDs.clear();

	 bool update_neotoma = false;
	 if (Downloaded && tiLicense->Type() == verNEOTOMASTEWARD) {
	   msg = L"Update GeochronControl in Neotoma?";
	   if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes) {
		 if (!Login->IsLoggedIn) {
		   NeotomaLoginForm = new TNeotomaLoginForm(this);
		   NeotomaLoginForm->ShowModal();
		   delete NeotomaLoginForm;
		   }
		 if (Login->IsLoggedIn) {
		   Screen->Cursor = crHourGlass;
		   update_neotoma = true;
		   DeleteData DeleteGeoChronControl(L"DeleteGeochronControl", 1, ipsHTTPS1, ipsJSONS1, TcpClient1);
		   DeleteGeoChronControl.Add(L"CHRONCONTROLID", ChronControl->NeotomaChronControlID);
		   ParentForm->StatusBar1->Panels->Items[0]->Text = L"DeleteGeochronControl";
		   if (!DeleteGeoChronControl.Post(ErrorMsg)) {
			 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			 Screen->Cursor = crDefault;
			 return;
			 }
		   }
		 }
	   }

	 for (int i=1; i<ProfGridGeochron->RowCount; i++) {
	   if (ProfGridGeochron->AbsoluteCells[0][i]->CheckBoxChecked) {
		 int iptr = ProfGridGeochron->AbsoluteCells[1][i]->CustomData;
		 vector<GEOCHRON>::pointer DatePtr = (vector<GEOCHRON>::pointer)iptr;
		 ChronControl->GeochronIDs.push_back(DatePtr->ID);
		 if (update_neotoma) {
		   //ShowMessage(L"ChronControlID = " + IntToStr(ChronControl->NeotomaChronControlID) +
		   //	 L", GeochronID = " + IntToStr(DatePtr->NeotomaGeochronID));
		   InsertData InsertGeoChronControl(L"InsertGeoChronControl", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
		   InsertGeoChronControl.Add(L"CHRONCONTROLID", ChronControl->NeotomaChronControlID, -1);
		   InsertGeoChronControl.Add(L"GEOCHRONID", DatePtr->NeotomaGeochronID, -1);
		   ParentForm->StatusBar1->Panels->Items[0]->Text = L"InsertGeoChronControl";
		   InsertGeoChronControl.PostData();
		   if (!InsertGeoChronControl.Post(ErrorMsg)) {
			 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			 Screen->Cursor = crDefault;
			 return;
			 }
		   }
		 }
	   }
	 ((TcxPopupEdit*)Sender)->Text = FormatGeochronLinks(ChronControl->GeochronIDs);
	 if (update_neotoma) {
	   msg = L"GeochronControl updated.";
	   MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
	   ParentForm->StatusBar1->Panels->Items[0]->Text = L"";
	   Screen->Cursor = crDefault;
	   }
	 }
}
//---------------------------------------------------------------------------

UnicodeString TTilSpreadSheetForm::FormatGeochronLinks(vector<int>& GeochronIDs)
{
   UnicodeString Links, NewLink;

   for (unsigned int i=0; i<GeochronIDs.size(); i++) {
	 int ID = GeochronIDs[i];
	 for (int j=0; j<GeochronList->Count(); j++) {
	   GEOCHRON& Date = GeochronList->Dates[j];
	   if (ID == Date.ID) {
		 if (!Date.LabNumber.IsEmpty() && !Date.Age.IsEmpty())
		   NewLink = "{" + Date.LabNumber + ";" + VarToStr(Date.Age) + "}";
		 else if (!Date.LabNumber.IsEmpty())
		   NewLink = "{" + Date.LabNumber + "}";
		 else if (!Date.Age.IsEmpty())
		   NewLink = "{" + VarToStr(Date.Age) + "}";
		 else
		   NewLink = "{}";
		 if (Links.IsEmpty())
		   Links = NewLink;
		 else {
		   Links += ",";
		   Links += NewLink;
		   }
		 break;
		 }
	   }
	 }
   return Links;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::chGeochronGetDisplayText(TcxCustomGridTableItem *Sender,
		  TcxCustomGridRecord *ARecord, UnicodeString &AText)
{
   // display calibration program info
   if (!ARecord) return;

   if (ARecord->RecordIndex == -1)
	 AText = FormatGeochronLinks(NewGeochronIDs);
}
//---------------------------------------------------------------------------

// Autolink button
void __fastcall TTilSpreadSheetForm::cxButton11Click(TObject *Sender)
{
   int RecordIndex1 = cxGrid3TableView1->Controller->FocusedRecordIndex;
   if (RecordIndex1 < 0) {
	 MessageDlg("No chronology selected.", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 return;
	 }

   AGEMODEL* AgeModel = AgeModelList->AgeModels[RecordIndex1];

   // see if there are already links
   bool LinksExist = false;
   for (int i=0; i<AgeModel->ChronControls->Count; i++) {
     CHRON* ChronControl = (CHRON*)AgeModel->ChronControls->Items[i];
	 if (ChronControl->GeochronIDs.size() > 0) {
       LinksExist = true;
       break;
       }
     }

   if (LinksExist) {
     if (MessageDlg("Links to geochronolgy already exist. Replace existing links?",
         mtWarning, TMsgDlgButtons() << mbYes << mbNo, 0) == mrNo)
       return;
     else {
       for (int i=0; i<AgeModel->ChronControls->Count; i++) {
		 CHRON* ChronControl = (CHRON*)AgeModel->ChronControls->Items[i];
		 if (ChronControl->GeochronIDs.size() > 0)
		   ChronControl->GeochronIDs.clear();
		 }
       }
     }

   Screen->Cursor = crHourGlass;
   for (int i=0; i<AgeModel->ChronControls->Count; i++) {
	 CHRON* ChronControl = (CHRON*)AgeModel->ChronControls->Items[i];
	 if (ChronControl->Depth.IsEmpty()) continue;
	 for (int j=0; j<GeochronList->Count(); j++) {
	   GEOCHRON& Date = GeochronList->Dates[j];
	   if (Date.Depth.IsEmpty()) continue;
	   if (ChronControl->Depth == Date.Depth)
         ChronControl->GeochronIDs.push_back(Date.ID);
       }
     }
   ChronDataSource->DataChanged();
   FocusControl(cxGrid3);
   Screen->Cursor = crDefault;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::ToolButton5Click(TObject *Sender)
{
   dms->dclick();
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::ToolButton7Click(TObject *Sender)
{
   dms->dmclick();
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::ToolButton8Click(TObject *Sender)
{
   dms->dmsclick();
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::LabeledEdit16Exit(TObject *Sender)
{
   dms->dexit();
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::LabeledEdit13Exit(TObject *Sender)
{
   dms->dmdexit();
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::LabeledEdit15Exit(TObject *Sender)
{
   dms->dmmexit();
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::LabeledEdit3Exit(TObject *Sender)
{
   dms->dmsdexit();
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::LabeledEdit9Exit(TObject *Sender)
{
   dms->dmsmexit();
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::LabeledEdit12Exit(TObject *Sender)
{
   dms->dmssexit();
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxButton1Click(TObject *Sender)
{
   double Coordinate = dms->GetDD();
   if (IsNan(Coordinate))
     LatLongPopupEdit->Text = "";
   else
     LatLongPopupEdit->Text = Coordinate;
}
//---------------------------------------------------------------------------

// fuzzy coordinates
void __fastcall TTilSpreadSheetForm::cxButton3Click(TObject *Sender)
{
   double rdist, hdist, rbearing;
   double lat1, lat2, lat3, lat4, long1, long2, long3, long4;
   int imin, imax;

   TFuzzyForm* FuzzyForm = new TFuzzyForm(this);
   if (FuzzyForm->ShowModal() == mrOk) {
     imin = 1000*FuzzyForm->dmin;
     imax = 1000*FuzzyForm->dmax;
     // calculate random distance and bearing
     Randomize();
     rdist = RandomRange(imin, imax);
	 rdist /= 1000.0;
     rbearing = RandomRange(0, 359);
     rbearing = DegToRad(rbearing);  // convert to radians

     lat1 = DegToRad(FuzzyForm->latitude);
     long1 = DegToRad(FuzzyForm->longitude);

     if (FuzzyForm->RadioGroup1->ItemIndex == 0) {  // point
       DistBearingToLatLong(rdist, rbearing, lat1, long1, &lat2, &long2);
       cxPopupEdit5->Visible = false;
       cxPopupEdit7->Visible = false;
	   cxRadioButton1->Checked = true;
	   Label8->Caption = "Latitude";
       Label10->Caption = "Longitude";
       Label9->Visible = false;
	   Label11->Visible = false;

	   SitePtr->LatNorth = (double)RoundTo(RadToDeg(lat2), -5);
	   SitePtr->LatSouth = SitePtr->LatNorth;
	   SitePtr->LongWest = (double)RoundTo(RadToDeg(long2), -5);
	   SitePtr->LongEast = SitePtr->LongWest;
	   cxPopupEdit4->Text = VarToStr(SitePtr->LatNorth);
	   cxPopupEdit6->Text = VarToStr(SitePtr->LongWest);
	   ShowMessage("Fuzzy point bears " + FloatToStr(RadToDeg(rbearing)) + " degrees, " +
				   FloatToStr(rdist) + " km from true point. ");
	   }
	 else if (FuzzyForm->RadioGroup1->ItemIndex == 1) {  // box
	   cxPopupEdit5->Visible = true;
       cxPopupEdit7->Visible = true;
       cxRadioButton2->Checked = true;
       Label8->Caption = "North Bounding Latitude";
       Label10->Caption = "West Bounding Longitude";
       Label9->Visible = true;
       Label11->Visible = true;
       hdist = 0.5*rdist;
       DistBearingToLatLong(hdist, rbearing, lat1, long1, &lat2, &long2);
       hdist = 0.5*FuzzyForm->dmax*sqrt(2.0);
	   // northeast point
	   DistBearingToLatLong(hdist, 0.25*M_PI, lat2, long2, &lat3, &long3);
	   SitePtr->LatNorth = (double)RoundTo(RadToDeg(lat3), -5);
	   SitePtr->LongEast = (double)RoundTo(RadToDeg(long3), -5);
	   cxPopupEdit4->Text = VarToStr(SitePtr->LatNorth);
	   cxPopupEdit7->Text = VarToStr(SitePtr->LongEast);
	   // southwest point
	   DistBearingToLatLong(hdist, 1.25*M_PI, lat2, long2, &lat4, &long4);
	   SitePtr->LatSouth = (double)RoundTo(RadToDeg(lat4), -5);
	   SitePtr->LongWest = (double)RoundTo(RadToDeg(long4), -5);
	   cxPopupEdit5->Text = VarToStr(SitePtr->LatSouth);
	   cxPopupEdit6->Text = VarToStr(SitePtr->LongWest);
	   ShowMessage("True point lies in a box " + FloatToStr(FuzzyForm->dmax) +
                   " km square, with midpoint bearing " + FloatToStr(RadToDeg(rbearing)) +
				   " degrees, " + FloatToStr(0.5*rdist) + " km from true point. ");
       }

     if (FuzzyForm->CheckBox1->Checked) {  // add note
       UnicodeString Note = "Site latitude-longitude coordinates are approximate. ";
       Note += "For legitimate purposes, contact the relevant land management agency.";
	   cxMemo2->Lines->Add(Note);
	   SitePtr->Notes = cxMemo2->Text;
       }
     }
   delete FuzzyForm;
}
//---------------------------------------------------------------------------

// calculate destination lat/long given distance and bearing from start lat/long
void TTilSpreadSheetForm::DistBearingToLatLong(double dist, double bearing, double lat1,
   double long1, double* lat2, double* long2)
{
   const double R = 6371; // Earth's radius in km
   *lat2 = asin(sin(lat1)*cos(dist/R) + cos(lat1)*sin(dist/R)*cos(bearing));
   *long2 = long1 + atan2(sin(bearing)*sin(dist/R)*cos(lat1), cos(dist/R)-sin(lat1)*sin(*lat2));
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::ProfGridCellCleared(
      TProfGrid *Sender, int ACol, int ARow)
{
   if (Sender == ProfGrid1) {
	 int AbsCol = ProfGrid1->Cols[ACol]->AbsoluteNumber;
	 TProfGridCell* ACell = Sender->AbsoluteCells[AbsCol][ARow];
	 if (ACell->CellObject != NULL)
	   DeleteCellObject(ACell);
	 SpreadSheetChanged = true;

	 if (Downloaded && tiLicense->Type() == verNEOTOMASTEWARD) {
	   int DatasetIdx;
	   if (!ValidateSteward(DatasetIdx))
		 return;
	   try {
		   if (ACell->AbsoluteCol >= 8 && ACell->AbsoluteRow > 2) {   // data columns
			 Screen->Cursor = crHourGlass;
			 UnicodeString VarCode = ProfGrid1->AbsoluteCells[1][ARow]->Text;
			 if (VarCode[1] == L'#') {   // metadata item
			   ShowMessage(L"Deleting metadata items from Neotoma not yet enabled.");
			   }
			 else {
			   if (!ACell->CustomData.IsEmpty()) {  // data value exists
				 if (MessageDlg(L"Delete data value in Neotoma?", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes)
				   UpdateDataValue(ACell->AbsoluteCol, ACell->AbsoluteRow, L"");
				 else
				   ACell->Color = TColor(0x00ADCBF8);   // light orange
				 }
			   }
			 }
		   }
	   __finally {
		   Screen->Cursor = crDefault;
		   ParentForm->StatusBar1->Panels->Items[0]->Text = L"";
		   }
	   }
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::ProfGridClearCell(TProfGrid *Sender,
	  int ACol, int ARow, bool &CanClear)
{
   TProfGridCell* ACell = Sender->Cells[ACol][ARow];
   SaveCells(Sender, ACell);

   if (Sender == ProfGrid1) {    // deal with deleted metadata
	 if (ACell->AbsoluteCol == 2 && ACell->AbsoluteRow != 1) {
	   if (Sysutils::SameText(L"#Data.Type", ProfGrid1->AbsoluteCells[1][ACell->AbsoluteRow]->Text)) {
		 cxComboBox2->Text = L"";
		 cxComboBox2Exit(cxComboBox2);
		 }
	   }
	 else if (ACell->AbsoluteCol > 7 && ARow >= ProfGrid1->FixedRows) {    // Main part of worksheet
	   UnicodeString Code = ProfGrid1->AbsoluteCells[1][ARow]->Value;
	   if (Code.SubString(1,1) == "#") {
		 Code = Code.UpperCase();
		 Variant Value = Unassigned();
		 EnterSSMetaData(Code, Value, ACol, ARow);
		 if (!Value.IsEmpty())
		   CanClear = false;
		 }
	   }
	 }
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::SaveCells(TProfGrid *Sender, TProfGridCell* ACell)
{
   UNDOCELL Cell;
   Cell.Col = ACell->AbsoluteCol;
   Cell.Row = ACell->AbsoluteRow;
   Cell.Value = ACell->Value;
   if (ACell->CellObject != NULL) {
	 CELLOBJECT* CellObject = new CELLOBJECT((CELLOBJECT*)ACell->CellObject);
	 Cell.Object = (TObject*)CellObject;
	 }

   UNDOSELECTION CurrentUndoSelection(Sender);

   if (CurrentUndoSelection != UndoSelection) {
	 UndoSelection = CurrentUndoSelection;
	 UNDO undo(CELLSCHANGED, Sender);
	 undo.Cells.push_back(Cell);
	 AddUnDo(undo);
	 }
   else {
	 UnDo.back().Cells.push_back(Cell);
	 }
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::AddUnDo(UNDO& undo)
{
   unsigned int UndoLimit = tiGlobals->UndoLimit;
   if (UnDo.size() == UndoLimit) {
	 list<UNDOCELL> UndoCells = UnDo.front().Cells;
	 list<UNDOCELL>::iterator itr;
	 for (itr = UndoCells.begin(); itr != UndoCells.end(); itr++) {
	   if (itr->Object != NULL) {
		 CELLOBJECT* CellObject = (CELLOBJECT*)itr->Object;
		 delete CellObject;
		 }
	   }
	 UnDo.pop_front();
	 }
   UnDo.push_back(undo);
   Undo1->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::UndoAction1Execute(TObject *Sender)
{
   if (UnDo.size() > 0) {
	 UNDO undo = UnDo.back();
     cxPageControl1->ActivePage = (TcxTabSheet*)undo.ProfGrid->Parent;

	 undo.ProfGrid->DisableControls();
	 undo.ProfGrid->SpreadsheetEnabled = false;

	 if (undo.Type == ROWSDELETED) {
	   list<int>::iterator ritr = undo.rc.begin();
	   while (ritr != undo.rc.end()) {
		 undo.ProfGrid->InsertRow(*ritr);
		 ritr++;
		 }
	   undo.rc.clear();
	   }
	 else if (undo.Type == COLSDELETED) {
	   list<int>::iterator citr = undo.rc.begin();
	   while (citr != undo.rc.end()) {
		 int col = undo.ProfGrid->AbsoluteCols[*citr]->VisibleNumber;
         undo.ProfGrid->InsertColumn(col);
         citr++;
         }
       undo.rc.clear();
       }
	 else if (undo.Type == ROWSINSERTED) {
       list<int>::iterator ritr = undo.rc.begin();
       while (ritr != undo.rc.end()) {
		 undo.ProfGrid->DeleteRow(*ritr);
         ritr++;
		 }
       undo.rc.clear();
       }
     else if (undo.Type == COLSINSERTED) {
       list<int>::iterator citr = undo.rc.begin();
       while (citr != undo.rc.end()) {
         int col = undo.ProfGrid->AbsoluteCols[*citr]->VisibleNumber;
         undo.ProfGrid->DeleteColumn(col);
         citr++;
         }
       undo.rc.clear();
       }

	 list<UNDOCELL>::iterator itr = undo.Cells.begin();
     while (itr != undo.Cells.end()) {
       UNDOCELL Cell = *itr;
       TProfGridCell *ACell = undo.ProfGrid->AbsoluteCells[Cell.Col][Cell.Row];
       if (Cell.CheckBox) {
         CheckBoxUndoEnabled = false;
         ACell->CheckBox = true;
         ACell->CheckBoxChecked = Cell.Value;
         CheckBoxUndoEnabled = true;
         }
       else
         ACell->Value = Cell.Value;
	   if (Cell.Object != NULL) {
		 CELLOBJECT* CellObject = new CELLOBJECT((CELLOBJECT*)Cell.Object);
		 AddCellObject(ACell, CellObject);
		 }
       itr++;
       }

     undo.ProfGrid->FocusCell(undo.Rect.Left, undo.Rect.Top);
     UnDo.pop_back();

     if (UnDo.size() == 0)
       Undo1->Enabled = false;

	 UndoSelection.Left = -1;  //
	 Clipboard()->Open();
	 Clipboard()->Clear();
	 Clipboard()->Close();
     undo.ProfGrid->SpreadsheetEnabled = true;
	 undo.ProfGrid->EnableControls();
     }
   else
	 Beep();
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::DeleteEmptyRowsAction1Execute(
	  TObject *Sender)
{
   TProfGrid* Grid = ProfGrid();
   int ColCount = AbsContentColCount(Grid);
   int RowCount = AbsContentRowCount(Grid);

   bool HeadersEmpty;
   bool DeleteZero;
   int StartCol;

   TDelEmptyRowColForm* DelRowsForm = new TDelEmptyRowColForm(this);
   int rv = DelRowsForm->ShowModal();
   if (rv == mrOk) {
	 HeadersEmpty = DelRowsForm->CheckBox1->Checked;
	 DeleteZero = DelRowsForm->RadioButton1->Checked;
	 }
   delete DelRowsForm;
   if (rv == mrCancel) return;

   if (HeadersEmpty)
	 StartCol = 1;
   else
	 StartCol = AbsHeaderColCount(Grid);

   Grid->DisableControls();
   Grid->SpreadsheetEnabled = false;
   try {
   try {
	   for (int row=RowCount; row>=3; row--) {
		 UnicodeString VarCode = Grid->AbsoluteCells[1][row]->Text;
		 if (!VarCode.IsEmpty() && VarCode[1] == L'#') continue;
		 bool empty = true;
		 TProfGridRow* ARow = Grid->AbsoluteRows[row];
		 for (int col=StartCol; col<=ColCount; col++) {
		   TProfGridCell *ACell = ARow->AbsoluteCells[col];
		   if (!ACell->IsEmpty()) {
			 if (DeleteZero && ACell->Value.Type() == varDouble) {
			   double dval = ACell->Value;
			   if (dval != 0)
				 empty = false;
			   }
			 else
			   empty = false;
			 if (!empty) break;
			 }
		   }
		 if (empty)
		   Grid->DeleteRow(ARow->VisibleNumber);
		 }
	   }
   catch(Exception &e) {
	   MessageDlg(e.Message, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   }
   }
   __finally {
   Grid->SpreadsheetEnabled = true;
   Grid->EnableControls();
   }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::DeleteEmptyColumnsAction1Execute(
	  TObject *Sender)
{
   TProfGrid* Grid = ProfGrid();
   int HeaderCols = AbsHeaderColCount(Grid);
   int ColCount = AbsContentColCount(Grid);
   int RowCount = AbsContentRowCount(Grid);

   bool HeadersEmpty;
   bool DeleteZero;
   int StartRow;

   TDelEmptyRowColForm* DelColsForm = new TDelEmptyRowColForm(this);
   DelColsForm->SetColumns();
   int rv = DelColsForm->ShowModal();
   if (rv == mrOk) {
	 HeadersEmpty = DelColsForm->CheckBox1->Checked;
	 DeleteZero = DelColsForm->RadioButton1->Checked;
	 }
   delete DelColsForm;
   if (rv == mrCancel) return;

   if (HeadersEmpty)
	 StartRow = 1;
   else
	 StartRow = 3;

   Grid->DisableControls();
   Grid->SpreadsheetEnabled = false;
   for (int col=ColCount; col>=HeaderCols; col--) {
	 bool empty = true;
	 TProfGridColumn* ACol = Grid->AbsoluteCols[col];
	 for (int row=StartRow; row<=RowCount; row++) {
	   TProfGridCell *ACell = ACol->Cells[row];
	   if (!ACell->IsEmpty()) {
		 if (DeleteZero && ACell->Value.Type() == varDouble) {
		   double dval = ACell->Value;
		   if (dval != 0)
			 empty = false;
		   }
		 else
		   empty = false;
		 if (!empty) break;
		 }
	   }
	 if (empty)
	   Grid->DeleteColumn(ACol->VisibleNumber);
	 }
   Grid->SpreadsheetEnabled = true;
   Grid->EnableControls();
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::EnterSSMetadataCode(UnicodeString Code, UnicodeString Name)
{
   int row = ProfGrid1->Row;
   ProfGrid1->DisableControls();
   ProfGrid1->SpreadsheetEnabled = false;
   if (!ProfGrid1->AbsoluteCells[1][row]->IsEmpty()) {
     ProfGrid1->InsertRow(row);
     ProfGrid1->Row = row;
     }
   if (!Code.IsEmpty())
     ProfGrid1->AbsoluteCells[1][row]->Value = WideString(Code);
   ProfGrid1->AbsoluteCells[2][row]->Value = WideString(Name);
   ProfGrid1->SpreadsheetEnabled = true;
   ProfGrid1->EnableControls();
   SpreadSheetChanged = true;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::mdSite1Click(TObject *Sender)
{
   if (HeaderRow2 == SITE_NAME) {
	 mdSiteName1->Enabled = false;
	 EnableSSSiteMD(true);
	 }
   else {
	 bool found = FindRowCodeIC("#Site.Name", ProfGrid1);
	 mdSiteName1->Enabled = !found;
	 EnableSSSiteMD(found);
	 }
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::EnableSSSiteMD(bool enable)
{
   if (enable) {
	 set<UnicodeString> Codes;
	 MetaDataRowsExist(L"#SITE.", Codes);
	 set<UnicodeString>::iterator end = Codes.end();
	 mdGeoPol1->Enabled = (Codes.find(L"GEOPOL1") == end);
	 mdGeoPol2->Enabled = (Codes.find(L"GEOPOL2") == end);
	 mdGeoPol3->Enabled = (Codes.find(L"GEOPOL3") == end);
	 mdAdmin1->Enabled = (Codes.find(L"ADMIN") == end);
	 mdLatNorth1->Enabled = (Codes.find(L"LATN") == end);
	 mdLatSouth1->Enabled = (Codes.find(L"LATS") == end);
	 mdLongWest1->Enabled = (Codes.find(L"LONGW") == end);
	 mdLongEast1->Enabled = (Codes.find(L"LONGE") == end);
	 mdAltitude1->Enabled = (Codes.find(L"ALTITUDE") == end);
	 mdArea1->Enabled = (Codes.find(L"AREA") == end);
	 mdSiteDesc1->Enabled = (Codes.find(L"DESC") == end);
	 mdSiteNotes1->Enabled = (Codes.find(L"NOTES") == end);
	 mdLakeCharacteristics1->Enabled = true;
	 }
   else {
	 mdGeoPol1->Enabled = false;
	 mdGeoPol2->Enabled = false;
	 mdGeoPol3->Enabled = false;
	 mdAdmin1->Enabled = false;
	 mdLatNorth1->Enabled = false;
	 mdLatSouth1->Enabled = false;
	 mdLongWest1->Enabled = false;
	 mdLongEast1->Enabled = false;
	 mdAltitude1->Enabled = false;
	 mdArea1->Enabled = false;
	 mdSiteDesc1->Enabled = false;
	 mdSiteNotes1->Enabled = false;
	 mdLakeCharacteristics1->Enabled = false;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::mdLakeCharacteristics1Click(TObject *Sender)
{
   set<UnicodeString> Codes;
   MetaDataRowsExist(L"#LAKE.", Codes);
   set<UnicodeString>::iterator end = Codes.end();
   list<LAKEPARAMETER>::iterator itr = LakeChar.begin();
   for (int i=0; i<mdLakeCharacteristics1->Count; i++) {
	 mdLakeCharacteristics1->Items[i]->Enabled = (Codes.find(itr->Code.UpperCase()) == end);
	 itr++;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::mdCollectionUnit1Click(TObject *Sender)
{
   bool found1, found2;

   if (HeaderRow2 == COLL_UNIT_NAME) {
	 mdCollName1->Enabled = false;
	 found1 = FindRowCodeIC("#Coll.Handle", ProfGrid1);
	 mdHandle1->Enabled = !found1;
	 EnableSSCollUnitMD(true);
	 }
   else if (HeaderRow2 == COLL_UNIT_HANDLE) {
	 mdHandle1->Enabled = false;
	 found1 = FindRowCodeIC("#Coll.Name", ProfGrid1);
	 mdCollName1->Enabled = !found1;
	 EnableSSCollUnitMD(found1);
	 }
   else {
	 found1 = FindRowCodeIC("#Coll.Handle", ProfGrid1);
	 mdHandle1->Enabled = !found1;
	 found2 = FindRowCodeIC("#Coll.Name", ProfGrid1);
	 mdCollName1->Enabled = !found2;
	 EnableSSCollUnitMD(found1 && found2);
	 }
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::EnableSSCollUnitMD(bool enable)
{
   if (enable) {
	 set<UnicodeString> Codes;
	 MetaDataRowsExist(L"#COLL.", Codes);
	 set<UnicodeString>::iterator end = Codes.end();
	 mdCollType1->Enabled = (Codes.find(L"TYPE") == end);
	 mdCollDevice1->Enabled = (Codes.find(L"DEVICE") == end);
	 mdCollectors1->Enabled = (Codes.find(L"CONTACTS") == end);
	 mdDateColl1->Enabled = (Codes.find(L"DATE") == end);
	 mdCollLoc1->Enabled = (Codes.find(L"LOC") == end);
	 mdLatGPS1->Enabled = (Codes.find(L"GPSLAT") == end);
	 mdLongGPS1->Enabled = (Codes.find(L"GPSLONG") == end);
	 mdGPSErr1->Enabled = (Codes.find(L"GPSERR") == end);
	 mdGPSAlt1->Enabled = (Codes.find(L"GPSALT") == end);
	 mdDepEnv1->Enabled = (Codes.find(L"DEPENV") == end);
	 mdSubstrate1->Enabled = (Codes.find(L"SUBSTRATE") == end);
	 mdSlopeAngle1->Enabled = (Codes.find(L"ANGLE") == end);
	 mdSlopeAspect1->Enabled = (Codes.find(L"ASPECT") == end);
	 mdWaterDep1->Enabled = (Codes.find(L"WATERDEP") == end);
	 mdCollNotes1->Enabled = (Codes.find(L"NOTES") == end);
	 }
   else {
	 mdCollType1->Enabled = false;
	 mdCollDevice1->Enabled = false;
	 mdCollectors1->Enabled = false;
	 mdDateColl1->Enabled = false;
	 mdCollLoc1->Enabled = false;
	 mdLatGPS1->Enabled = false;
	 mdLongGPS1->Enabled = false;
	 mdGPSErr1->Enabled = false;
	 mdGPSAlt1->Enabled = false;
	 mdDepEnv1->Enabled = false;
	 mdSubstrate1->Enabled = false;
	 mdSlopeAngle1->Enabled = false;
	 mdSlopeAspect1->Enabled = false;
	 mdWaterDep1->Enabled = false;
	 mdCollNotes1->Enabled = false;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::Metadata1Click(TObject *Sender)
{
   mdDataset1->Visible = !ContainsText(Datasets[0].DatasetType, L"top-bottom");
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::mdAnalysisUnit1Click(TObject *Sender)
{
   set<UnicodeString> Codes;

   if (HeaderRow2 == ANAL_UNIT_NAME)
	 mdAnalUnit1->Enabled = false;
   else
	 mdAnalUnit1->Enabled = !FindRowCodeIC("#Anal.Name", ProfGrid1);

   //for (unsigned int i=0; i<TSSForm->Datasets.size(); i++) {
   //	 DatasetPtr = &TSSForm->Datasets[i];

   if (ContainsText(Datasets[0].DatasetType, L"top-bottom")) {
	 mdBottom1->Visible = true;
	 int bottom_row = FindRowCodeIC("#Anal.Bottom", ProfGrid1);
	 mdBottom1->Enabled = (bottom_row == 0);

	 if (bottom_row > 0 && ProfGrid1->Row > bottom_row)
	   MetaDataRowsExist(L"#ANAL.", Codes, bottom_row);
	 }

   if (Codes.size() == 0)
	 MetaDataRowsExist(L"#ANAL.", Codes);
   set<UnicodeString>::iterator end = Codes.end();
   mdThick1->Enabled = (Codes.find(L"THICK") == end);
   mdFacies1->Enabled = (Codes.find(L"FACIES") == end);
   mdDepAgent1->Enabled = (Codes.find(L"DEPAGENT") == end);
   mdMixed1->Enabled = (Codes.find(L"MIXED") == end);
   mdIGSN1->Enabled = (Codes.find(L"IGSN") == end);
   mdAnalUnitNotes1->Enabled = (Codes.find(L"NOTES") == end);

   mdAltDepth1->Visible = (Codes.find(L"DEPTH1") == end);
   mdAltDepth2->Visible = (Codes.find(L"DEPTH2") == end);
   mdAltDepth3->Visible = (Codes.find(L"DEPTH3") == end);
   mdAltDepth4->Visible = (Codes.find(L"DEPTH4") == end);
   mdAltDepth5->Visible = (Codes.find(L"DEPTH5") == end);
   mdAltDepth6->Visible = (Codes.find(L"DEPTH6") == end);
   mdAltDepth7->Visible = (Codes.find(L"DEPTH7") == end);
   mdAltDepth8->Visible = (Codes.find(L"DEPTH8") == end);
   mdAltDepth9->Visible = (Codes.find(L"DEPTH9") == end);
   }
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::mdSample1Click(TObject *Sender)
{
   int RowCount = ContentRowCount(ProfGrid1);
   int row2 = RowCount;
   int row1 = 3;
   UnicodeString Code;
   TProfGridColumn* CodeCol = ProfGrid1->AbsoluteCols[1];

   if (Datasets.size() > 1) {
	 Code = CodeCol->AbsoluteCells[ProfGrid1->Row]->Text;
	 if (SameText(Code, L"#Data.Type"))
	   row2 = ProfGrid1->Row - 1;
	 else {
	   for (int row=ProfGrid1->Row+1; row<=RowCount; row++) {
		 Code = CodeCol->AbsoluteCells[row]->Text;
		 if (SameText(Code, L"#Data.Type")) {
		   row2 = row - 1;
		   break;
		   }
		 }
	   }
	 for (int row=row2; row>=3; row--) {
	   Code = CodeCol->AbsoluteCells[row]->Text;
	   if (SameText(Code, L"#Data.Type")) {
		 row1 = row + 1;
		 break;
		 }
	   }
	 }

   set<UnicodeString> Codes;
   for (int row=row1; row<=row2; row++) {
	 Code = CodeCol->AbsoluteCells[row]->Value;
	 if (SameText(Code.SubString(1,6), L"#SAMP.")) {
	   Code.Delete(1,6);
	   Codes.insert(Code.UpperCase());
	   }
	 }

   set<UnicodeString>::iterator end = Codes.end();
   mdSampleName1->Enabled = (Codes.find(L"NAME") == end);
   mdKeywords1->Enabled = (Codes.find(L"KEYWORDS") == end);
   mdAnalyst1->Enabled = (Codes.find(L"ANALYST") == end);
   mdDateAnal1->Enabled = (Codes.find(L"DATEANAL") == end);
   mdDateSampled1->Enabled = (Codes.find(L"DATESAMP") == end);
   mdTaxonSampled1->Enabled = (Codes.find(L"TAXON") == end);
   mdLabNumber1->Enabled = (Codes.find(L"LABNUM") == end);
   mdPrepMethod1->Enabled = (Codes.find(L"METHOD") == end);
   mdSampleNotes1->Enabled = (Codes.find(L"NOTES") == end);
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::mdBottom1Click(TObject *Sender)
{
   EnterSSMetadataCode("#Anal.NameBot", "Bottom Name");
   EnterSSMetadataCode("#Anal.DepBot", "Bottom Depth");
   EnterSSMetadataCode("#Anal.Bottom", "Bottom Analysis Unit");

   int EndCol = ProfGrid1->AbsoluteColCount;
   TProfGridRow* DTRow = ProfGrid1->AbsoluteRows[ProfGrid1->Row];
   for (int col=1; col<EndCol; col++) {
	 TProfGridCell *ACell = DTRow->AbsoluteCells[col];
	 ACell->Color = (TColor)0x00EACAB6;
	 ACell->Font->Color = clNavy;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::mdDataset1Click(TObject *Sender)
{
   EnterSSMetadataCode("#Data.Type", "");
   EnterSSDataType();
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::EnterSSDataType(void)
{
   int EndCol = ProfGrid1->AbsoluteColCount;
   TProfGridRow* DTRow = ProfGrid1->AbsoluteRows[ProfGrid1->Row];
   for (int col=1; col<EndCol; col++) {
	 TProfGridCell *ACell = DTRow->AbsoluteCells[col];
	 ACell->Color = (TColor)0x00EACAB6;
	 ACell->Font->Color = clNavy;
	 }
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::MetaDataRowsExist(UnicodeString Prefix, set<UnicodeString>& Codes, int start_row)
{
   UnicodeString Code;
   TProfGridColumn* CodeCol = ProfGrid1->AbsoluteCols[1];
   int RowCount = ContentRowCount(ProfGrid1);
   for (int row=start_row; row<=RowCount; row++) {
	 Code = CodeCol->AbsoluteCells[row]->Value;
	 Code = Code.UpperCase();
	 int len = Prefix.Length();
	 if (Code.SubString(1,len) == Prefix) {
	   Code.Delete(1,len);
	   Codes.insert(Code);
	   }
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::mdAllSiteItems1Click(TObject *Sender)
{
   if (mdSiteName1->Enabled) {
	 EnterSSMetadataCode("#Site.Notes", "Site Notes");
	 EnterSSMetadataCode("#Site.Desc", "Site Description");
	 EnterSSMetadataCode("#Site.Area", "Area of Site (ha)");
	 EnterSSMetadataCode("#Site.Altitude", "Altitude (m)");
	 EnterSSMetadataCode("#Site.Admin", "Administrative Unit");
	 EnterSSMetadataCode("#Site.GeoPol3", "Third Geopolitical Division");
	 EnterSSMetadataCode("#Site.GeoPol2", "Second Geopolitical Division");
	 EnterSSMetadataCode("#Site.GeoPol1", "First Geopolitical Division");
	 EnterSSMetadataCode("#Site.LongE", "East Longitude");
	 EnterSSMetadataCode("#Site.LongW", "West Longitude");
	 EnterSSMetadataCode("#Site.LatS", "South Latitude");
	 EnterSSMetadataCode("#Site.LatN", "North Latitude");
	 EnterSSMetadataCode("#Site.Name", "Site Name");
	 }
   else {
	 if (mdSiteNotes1->Enabled)
	   EnterSSMetadataCode("#Site.Notes", "Site Notes");
	 if (mdSiteDesc1->Enabled)
	   EnterSSMetadataCode("#Site.Desc", "Site Description");
	 if (mdArea1->Enabled)
	   EnterSSMetadataCode("#Site.Area", "Area of Site (ha)");
	 if (mdAltitude1->Enabled)
	   EnterSSMetadataCode("#Site.Altitude", "Altitude (m)");
	 if (mdAdmin1->Enabled)
	   EnterSSMetadataCode("#Site.Admin", "Administrative Unit");
	 if (mdGeoPol3->Enabled)
	   EnterSSMetadataCode("#Site.GeoPol3", "Third Geopolitical Division");
	 if (mdGeoPol2->Enabled)
	   EnterSSMetadataCode("#Site.GeoPol2", "Second Geopolitical Division");
	 if (mdGeoPol1->Enabled)
	   EnterSSMetadataCode("#Site.GeoPol1", "First Geopolitical Division");
	 if (mdLongEast1->Enabled)
	   EnterSSMetadataCode("#Site.LongE", "East Longitude");
	 if (mdLongWest1->Enabled)
	   EnterSSMetadataCode("#Site.LongW", "West Longitude");
	 if (mdLatSouth1->Enabled)
	   EnterSSMetadataCode("#Site.LatS", "South Latitude");
	 if (mdLatNorth1->Enabled)
	   EnterSSMetadataCode("#Site.LatN", "North Latitude");
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::mdSiteName1Click(TObject *Sender)
{
   EnterSSMetadataCode("#Site.Name", "Site Name");
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::mdLatNorth1Click(TObject *Sender)
{
   EnterSSMetadataCode("#Site.LatN", "North Latitude");
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::mdLatSouth1Click(TObject *Sender)
{
   EnterSSMetadataCode("#Site.LatS", "South Latitude");
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::mdLongWest1Click(TObject *Sender)
{
   EnterSSMetadataCode("#Site.LongW", "West Longitude");
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::mdLongEast1Click(TObject *Sender)
{
   EnterSSMetadataCode("#Site.LongE", "East Longitude");
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::mdGeoPol1Click(TObject *Sender)
{
   EnterSSMetadataCode("#Site.GeoPol1", "First Geopolitical Division");
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::mdGeoPol2Click(TObject *Sender)
{
   EnterSSMetadataCode("#Site.GeoPol2", "Second Geopolitical Division");
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::mdGeoPol3Click(TObject *Sender)
{
   EnterSSMetadataCode("#Site.GeoPol3", "Third Geopolitical Division");
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::mdAdmin1Click(TObject *Sender)
{
   EnterSSMetadataCode("#Site.Admin", "Administrative Unit");
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::mdAltitude1Click(TObject *Sender)
{
   EnterSSMetadataCode("#Site.Altitude", "Altitude (m)");
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::mdArea1Click(TObject *Sender)
{
   EnterSSMetadataCode("#Site.Area", "Area of Site (ha)");
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::mdSiteDesc1Click(TObject *Sender)
{
   EnterSSMetadataCode("#Site.Desc", "Site Description");
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::mdSiteNotes1Click(TObject *Sender)
{
   EnterSSMetadataCode("#Site.Notes", "Site Notes");
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::LakeCharacteristicMenuItem(TObject *Sender)
{
   UnicodeString Code, Name;

   TMenuItem* MenuItem = (TMenuItem*)Sender;
   UnicodeString Caption = MenuItem->Caption;
   int pos = Caption.Pos("&");
   if (pos > 0)
     Caption.Delete(pos, 1);

   list<LAKEPARAMETER>::iterator itr = LakeChar.begin();
   while (itr != LakeChar.end()) {
	 if (Caption.Compare(itr->Menu) == 0) {
	   Name = itr->Name;
	   Code = itr->Code;
	   Code.Insert("#Lake.", 1);
	   break;
	   }
	 itr++;
	 }

   EnterSSMetadataCode(Code, Name);
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::mdAllCollectionUnitItems1Click(
	  TObject *Sender)
{
   if (mdCollName1->Enabled || mdHandle1->Enabled) {
     map<UnicodeString, int> MDRows;
	 GetMetaDataRows(L"#COLL.", MDRows);
	 map<UnicodeString, int>::iterator end = MDRows.end();
	 EnterSSMetadataCode("#Coll.Notes", "Collection Unit Notes");
	 EnterSSMetadataCode("#Coll.WaterDep", "Water Depth");
	 EnterSSMetadataCode("#Coll.Aspect", "Slope Aspect");
	 EnterSSMetadataCode("#Coll.Angle", "Slope Angle");
	 EnterSSMetadataCode("#Coll.Substrate", "Substrate");
	 EnterSSMetadataCode("#Coll.DepEnv", "Depositional Environment");
	 EnterSSMetadataCode("#Coll.GPSAlt", "GPS Altitude");
	 EnterSSMetadataCode("#Coll.GPSErr", "GPS Error");
	 EnterSSMetadataCode("#Coll.GPSLong", "GPS Longitude");
	 EnterSSMetadataCode("#Coll.GPSLat", "GPS Latitude");
	 EnterSSMetadataCode("#Coll.Loc", "Location in Site");
	 EnterSSMetadataCode("#Coll.Date", "Date Collected");
	 EnterSSMetadataCode("#Coll.Contacts", "Collectors");
	 EnterSSMetadataCode("#Coll.Device", "Collection Device");
	 EnterSSMetadataCode("#Coll.Type", "Collection Unit Type");
	 if (HeaderRow2 != COLL_UNIT_NAME && MDRows.find(L"NAME") == MDRows.end())
	   EnterSSMetadataCode("#Coll.Name", "Collection Unit Name");
	 if (HeaderRow2 != COLL_UNIT_HANDLE && MDRows.find(L"HANDLE") == MDRows.end())
	   EnterSSMetadataCode("#Coll.Handle", "Handle");
	 }
   else {
	 if (mdSiteNotes1->Enabled)
	   EnterSSMetadataCode("#Coll.Notes", "Collection Unit Notes");
	 if (mdWaterDep1->Enabled)
	   EnterSSMetadataCode("#Coll.WaterDep", "Water Depth");
	 if (mdSlopeAspect1->Enabled)
	   EnterSSMetadataCode("#Coll.Aspect", "Slope Aspect");
	 if (mdSlopeAngle1->Enabled)
	   EnterSSMetadataCode("#Coll.Angle", "Slope Angle");
	 if (mdSubstrate1->Enabled)
	   EnterSSMetadataCode("#Coll.Substrate", "Substrate");
	 if (mdDepEnv1->Enabled)
	   EnterSSMetadataCode("#Coll.DepEnv", "Depositional Environment");
	 if (mdGPSAlt1->Enabled)
	   EnterSSMetadataCode("#Coll.GPSAlt", "GPS Altitude");
	 if (mdGPSErr1->Enabled)
	   EnterSSMetadataCode("#Coll.GPSErr", "GPS Error");
	 if (mdLongGPS1->Enabled)
	   EnterSSMetadataCode("#Coll.GPSLong", "GPS Longitude");
	 if (mdLatGPS1->Enabled)
	   EnterSSMetadataCode("#Coll.GPSLat", "GPS Latitude");
	 if (mdCollLoc1->Enabled)
	   EnterSSMetadataCode("#Coll.Loc", "Location in Site");
	 if (mdDateColl1->Enabled)
	   EnterSSMetadataCode("#Coll.Date", "Date Collected");
	 if (mdCollectors1->Enabled)
	   EnterSSMetadataCode("#Coll.Contacts", "Collectors");
	 if (mdCollDevice1->Enabled)
	   EnterSSMetadataCode("#Coll.Device", "Collection Device");
	 if (mdCollType1->Enabled)
	   EnterSSMetadataCode("#Coll.Type", "Collection Unit Type");
	 if (mdCollName1->Enabled)
	   EnterSSMetadataCode("#Coll.Name", "Collection Unit Name");
	 if (mdHandle1->Enabled)
	   EnterSSMetadataCode("#Coll.Handle", "Handle");
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::mdHandle1Click(TObject *Sender)
{
   EnterSSMetadataCode("#Coll.Handle", "Handle");
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::mdCollName1Click(TObject *Sender)
{
   EnterSSMetadataCode("#Coll.Name", "Collection Unit Name");
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::mdCollType1Click(TObject *Sender)
{
   EnterSSMetadataCode("#Coll.Type", "Collection Unit Type");
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::mdCollDevice1Click(TObject *Sender)
{
   EnterSSMetadataCode("#Coll.Device", "Collection Device");
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::mdCollectors1Click(TObject *Sender)
{
   EnterSSMetadataCode("#Coll.Contacts", "Collectors");
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::mdDateColl1Click(TObject *Sender)
{
   EnterSSMetadataCode("#Coll.Date", "Date Collected");
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::mdCollLoc1Click(TObject *Sender)
{
   EnterSSMetadataCode("#Coll.Loc", "Location in Site");
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::mdDepEnv1Click(TObject *Sender)
{
   EnterSSMetadataCode("#Coll.DepEnv", "Depositional Environment");
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::mdWaterDep1Click(TObject *Sender)
{
   EnterSSMetadataCode("#Coll.WaterDep", "Water Depth");
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::mdSubstrate1Click(TObject *Sender)
{
   EnterSSMetadataCode("#Coll.Substrate", "Substrate");
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::mdSlopeAngle1Click(TObject *Sender)
{
   EnterSSMetadataCode("#Coll.Angle", "Slope Angle");
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::mdSlopeAspect1Click(TObject *Sender)
{
   EnterSSMetadataCode("#Coll.Aspect", "Slope Aspect");
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::mdLatGPS1Click(TObject *Sender)
{
   EnterSSMetadataCode("#Coll.GPSLat", "GPS Latitude");
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::mdLongGPS1Click(TObject *Sender)
{
   EnterSSMetadataCode("#Coll.GPSLong", "GPS Longitude");
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::mdGPSErr1Click(TObject *Sender)
{
   EnterSSMetadataCode("#Coll.GPSErr", "GPS Error");
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::mdGPSAlt1Click(TObject *Sender)
{
   EnterSSMetadataCode("#Coll.GPSAlt", "GPS Altitude");
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::mdCollNotes1Click(TObject *Sender)
{
   EnterSSMetadataCode("#Coll.Notes", "Collection Unit Notes");
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::mdChron1Click(TObject *Sender)
{
   int pos;
   UnicodeString Code, Name;

   UnicodeString Parent = ((TMenuItem*)Sender)->Parent->Caption;
   if ((pos = Parent.Pos("&")) > 0)
     Parent.Delete(pos,1);
   UnicodeString ChronNo = ((TMenuItem*)Sender)->Caption;
   if ((pos = ChronNo.Pos("&")) > 0)
     ChronNo.Delete(pos,1);

   Code = "#Chron" + ChronNo;
   if (SameText(Parent, L"Chron"))
     Name = "Age (Chron" + ChronNo + ")";
   else if (SameText(Parent, L"Chron.Old")) {
     Code += ".Old";
     Name = "Age (Chron" + ChronNo + " Older Bound)";
     }
   else if (SameText(Parent, L"Chron.Young")) {
     Code += ".Young";
     Name = "Age (Chron" + ChronNo + " Younger Bound)";
     }
  EnterSSMetadataCode(Code, Name);
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::mdAltDepth1Click(TObject *Sender)
{
   int pos;

   UnicodeString DepthNo = ((TMenuItem*)Sender)->Caption;
   if ((pos = DepthNo.Pos("&")) > 0)
     DepthNo.Delete(pos,1);

   UnicodeString Code = "#Anal.Depth" + DepthNo;
   UnicodeString Name = "Depth Scale " + DepthNo;
   EnterSSMetadataCode(Code, Name);
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::mdAnalUnit1Click(TObject *Sender)
{
   EnterSSMetadataCode("#Anal.Name", "Analysis Unit Name");
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::mdThick1Click(TObject *Sender)
{
   EnterSSMetadataCode("#Anal.Thick", "Analysis Unit Thickness");
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::mdFacies1Click(TObject *Sender)
{
   EnterSSMetadataCode("#Anal.Facies", "Analysis Unit Facies");
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::mdDepAgent1Click(TObject *Sender)
{
   EnterSSMetadataCode("#Anal.DepAgent", "Analysis Unit Depositional Agent");
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::mdMixed1Click(TObject *Sender)
{
   EnterSSMetadataCode("#Anal.Mixed", "Analysis Unit Mixed");
   int StartCol = AbsHeaderColCount(ProfGrid1);
   int EndCol = ProfGrid1->AbsoluteColCount;
   TProfGridRow* MRow = ProfGrid1->AbsoluteRows[ProfGrid1->Row];
   for (int col=StartCol; col<EndCol; col++) {
	 TProfGridCell *ACell = MRow->AbsoluteCells[col];
	 ACell->Value.Clear();
	 ACell->CheckBox = true;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::mdIGSN1Click(TObject *Sender)
{
   EnterSSMetadataCode("#Anal.IGSN", "International Geo Sample Number");
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::mdAnalUnitNotes1Click(TObject *Sender)
{
   EnterSSMetadataCode("#Anal.Notes", "Analysis Unit Notes");
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::AllSampleItems1Click(TObject *Sender)
{
   if (mdSampleNotes1->Enabled)
	 EnterSSMetadataCode("#Samp.Notes", "Sample Notes");
   if (mdPrepMethod1->Enabled)
	 EnterSSMetadataCode("#Samp.Method", "Preparation Method");
   if (mdLabNumber1->Enabled)
	 EnterSSMetadataCode("#Samp.LabNum", "Lab Number");
   if (mdLabNumber1->Enabled)
	 EnterSSMetadataCode("#Samp.Taxon", "Taxon Sampled");
   if (mdDateAnal1->Enabled)
	 EnterSSMetadataCode("#Samp.DateAnal", "Date Analyzed");
   if (mdAnalyst1->Enabled)
	 EnterSSMetadataCode("#Samp.Analyst", "Sample Analyst");
   if (mdDateAnal1->Enabled)
	 EnterSSMetadataCode("#Samp.DateSamp", "Date Sampled");
   if (mdDateSampled1->Enabled)
	 EnterSSMetadataCode("#Samp.Keywords", "Sample Keywords");
   if (mdSampleName1->Enabled)
	 EnterSSMetadataCode("#Samp.Name", "Sample Name");
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::mdSampleName1Click(TObject *Sender)
{
   EnterSSMetadataCode("#Samp.Name", "Sample Name");
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::mdKeywords1Click(TObject *Sender)
{
   EnterSSMetadataCode("#Samp.Keywords", "Sample Keywords");
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::mdAnalyst1Click(TObject *Sender)
{
   int StartCol = AbsHeaderColCount(ProfGrid1);
   int EndCol = ProfGrid1->AbsoluteColCount;
   int ARow = ProfGrid1->Rows[ProfGrid1->Row]->AbsoluteNumber;
   bool DataFound = false;
   for (int col=StartCol; col<EndCol; col++) {
	 if (!ProfGrid1->AbsoluteCells[col][ARow]->IsEmpty()) {
	   DataFound = true;
	   break;
	   }
	 }
   if (DataFound) {
	 UnicodeString msg = L"Cells in row already contain data. Do you want to convert data to analyst contacts?";
	 msg += L"\nClicking «No» will clear all data.";
	 int query = MessageDlg(msg, mtWarning, TMsgDlgButtons() << mbYes << mbNo << mbCancel, 0);
	 switch (query) {
	   case mrYes:
		 int col;
		 col = StartCol;
		 bool repeat;
		 while (col < EndCol) {
		   repeat = false;
		   TProfGridCell* ACell = ProfGrid1->AbsoluteCells[col][ARow];
		   if (!ACell->IsEmpty()) {
			 UnicodeString Analyst = VarToStr(ACell->Value);
			 bool found = false;
			 for (int j=0; j<ContactList->Count; j++) {
			   CONTACT *Contact = ContactList->Contacts[j];
			   UnicodeString ShortName = Contact->FamilyName;
			   if (!Contact->LeadingInitials.IsEmpty())
				 ShortName += (L", " + Contact->LeadingInitials);
			   if (SameText(Analyst, ShortName) || SameText(Analyst, Contact->ShortContactName)) {
				 if (Analyst != Contact->ShortContactName)
				   ACell->Value = Contact->ShortContactName;
				 TList* CellContacts = InitCellContactsList(ACell);
				 CellContacts->Add(Contact);
				 found = true;
				 break;
				 }
			   }
			 if (!found) {
			   msg = L"Analyst «" + Analyst + L"» is not in the Contacts list. Would you like to add this analyst?";
			   msg += L"\nClicking «No» will delete this analyst.";
			   int query1 = MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo << mbCancel, 0);
			   switch (query1) {
				 case mrYes:
				   CONTACT* Contact;
				   Contact = NewContact(Analyst);
				   if (Contact != NULL)
					 ACell->Value = Contact->ShortContactName;
				   repeat = true;
				   break;
				 case mrNo:  // not added, delete analyst
				   for (int i=col; i<EndCol; i++) {
					 UnicodeString Text = ProfGrid1->AbsoluteCells[i][ARow]->Value;
					 if (SameText(Text, Analyst))
					   ProfGrid1->AbsoluteCells[i][ARow]->Value = Unassigned();
					 }
				   break;
				 default:
				   return;
				 }
			   }
			 }
		   if (!repeat) col++;
		   }
		 break;
	   case mrNo: // clear all data
		 for (int col=StartCol; col<EndCol; col++) {
		   if (!ProfGrid1->AbsoluteCells[col][ARow]->IsEmpty())
			 ProfGrid1->AbsoluteCells[col][ARow]->Value = Unassigned();
		   }
		 break;
	   default:
		 return;
	   }
	 }

   EnterSSMetadataCode("#Samp.Analyst", "Sample Analyst");
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::mdDateSampled1Click(TObject *Sender)
{
   EnterSSMetadataCode("#Samp.DateSamp", "Date Sampled");
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::mdDateAnal1Click(TObject *Sender)
{
   EnterSSMetadataCode("#Samp.DateAnal", "Date Analyzed");
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::mdTaxonSampled1Click(TObject *Sender)
{
   EnterSSMetadataCode("#Samp.Taxon", "Taxon Sampled");
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::mdLabNumber1Click(TObject *Sender)
{
   EnterSSMetadataCode("#Samp.LabNum", "Lab Number");
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::mdPrepMethod1Click(TObject *Sender)
{
   EnterSSMetadataCode("#Samp.Method", "Preparation Method");
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::mdSampleNotes1Click(TObject *Sender)
{
   EnterSSMetadataCode("#Samp.Notes", "Sample Notes");
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::AdvControlDropDown2BeforeDropDown(TObject *Sender)
{
   LakeParamChanged = false;
   for (int i=1; i<AdvStringGridLake->RowCount; i++)
	 AdvStringGridLake->Cells[1][i] = L"";
   for (unsigned int i=0; i<SitePtr->LakeParams.size(); i++) {
	 UnicodeString ParamName = SitePtr->LakeParams[i].Name;
	 for (int row=1; row<AdvStringGridLake->RowCount; row++) {
	   if (SameText(ParamName, AdvStringGridLake->Cells[0][row])) {
		 AdvStringGridLake->Cells[1][row] = FloatToStr(SitePtr->LakeParams[i].Value);
		 break;
		 }
	   }
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::AdvControlDropDown2DropDownFooterButtonClick(TObject *Sender,
		  int ButtonIndex)
{
   LakeParamChanged = false;
   if (ButtonIndex == 0) {    // Post button
	 ResetLakeParams();
	 AdvControlDropDown2->HideDropDown();
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::AdvControlDropDown2BeforeDropUp(TObject *Sender)
{
   if (LakeParamChanged) {
	 if (MessageDlg(L"Changes made to lake parameters. Do you want to save them?",
		 mtWarning, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes)
	   ResetLakeParams();
	 }
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::ResetLakeParams(void)
{
   double dVal;
   UnicodeString Text, Code;

   SitePtr->LakeParams.clear();
   for (int i=1; i<AdvStringGridLake->RowCount; i++) {
	 UnicodeString ParamValue = AdvStringGridLake->Cells[1][i];
	 if (!ParamValue.IsEmpty()) {
	   UnicodeString ParamName = AdvStringGridLake->Cells[0][i];
	   if (TryStrToFloat(ParamValue, dVal)) {
		 LAKEPARAM LakeParam;
		 LakeParam.Name = ParamName;
		 LakeParam.Value = dVal;
		 SitePtr->LakeParams.push_back(LakeParam);
		 // set AdvControlDropDown text
		 Code = L"";
		 list<LAKEPARAMETER>::iterator itr;
		 for (itr=LakeChar.begin(); itr != LakeChar.end(); itr++) {
		   if (SameText(itr->Name, ParamName)) {
			 Code = itr->Code;
			 break;
			 }
		   }
		 if (!Text.IsEmpty())
		   Text += L",";
		 Text += ("\"" + Code + L"\":" + ParamValue);
		 }
	   }
	 }
   AdvControlDropDown2->Text = Text;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::AdvStringGridLakeEditChange(TObject *Sender,
		  int ACol, int ARow, UnicodeString Value)
{
   LakeParamChanged = true;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::ShowDescription1Click(TObject *Sender)
{
   TTreeNode* Node = dxTreeViewEdit2->Selected;
   UnicodeString Hint = Node->Text + L": " + (wchar_t*)(Node->Data);
   // word wrap at 100 characters
   int Start = 1;
   int MaxLen = 100;
   UnicodeString Space = " ";
   UnicodeString Character;
   while (Hint.Length() > MaxLen) {
	 for (int idx=MaxLen; idx>=Start; idx--) {
	   Character = Hint.SubString(idx,1);
	   if (Character.Compare(Space) == 0) {
		 Hint.Delete(idx,1);
		 Hint.Insert("\n", idx);
		 Start = idx + 1;
		 MaxLen = idx + 100;
		 break;
		 }
	   }
	 }
   MessageDlg(Hint, mtInformation, TMsgDlgButtons() << mbOK, 0);
   FocusControl(dxTreeViewEdit2);
   dxTreeViewEdit2->DropDown();
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::DisplayHint(TObject *Sender)
{
   ParentForm->StatusBar1->Panels->Items[1]->Text = Application->Hint;;
}
//---------------------------------------------------------------------------

// taxa lookup for Geochronology
void __fastcall TTilSpreadSheetForm::txElementGetPropertiesForEdit(
	  TcxCustomGridTableItem *Sender, TcxCustomGridRecord *ARecord,
	  TcxCustomEditProperties *&AProperties)
{
   TcxComboBoxProperties* ElementDated = (TcxComboBoxProperties*)AProperties;
   ElementDated->Items->Clear();

   UnicodeString TaxonName = ARecord->DisplayTexts[txTaxon->Index];
   if (!TaxonName.IsEmpty()) {
	 TAXON Taxon;
	 set<UnicodeString> Elements;
	 if (GeochronTaxaOpen) {
	   if (GetGeochronTaxon(TaxonName, Taxon))
		 GeochronElementLookup->GetElementsForTaxonGroup(Taxon.TaxaGroup, Elements);
	   }
	 else if (TaxaLookupOpen) {
	   if (GetTaxon(TaxonName, Taxon))
		 ElementLookup->GetElementsForTaxonGroup(Taxon.TaxaGroup, Elements);
	   }

	 if (Elements.size() > 0) {
	   set<UnicodeString>::iterator itr;
	   ElementDated->Items->BeginUpdate();
	   ElementDated->Items->Clear();
	   for (itr = Elements.begin(); itr != Elements.end(); itr++)
		 ElementDated->Items->Add(*itr);
	   ElementDated->Items->EndUpdate();
	   }
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::txTaxonGetPropertiesForEdit(
      TcxCustomGridTableItem *Sender, TcxCustomGridRecord *ARecord,
      TcxCustomEditProperties *&AProperties)
{
   if (GeochronTaxaOpen) {
	 TcxComboBoxProperties* TaxonDated = (TcxComboBoxProperties*)AProperties;
	 if (TaxonDated->Items->Count != (int)GeochronTaxaList.size()) {
	   TaxonDated->BeginUpdate();
	   TaxonDated->Items->Clear();
	   for (unsigned int i=0; i<GeochronTaxaList.size(); i++)
		 TaxonDated->Items->Add(GeochronTaxaList[i].Name);
	   TaxonDated->EndUpdate();
	   }
	 }
   else if (TaxaList.size() > 0) {
	 TcxComboBoxProperties* TaxonDated = (TcxComboBoxProperties*)AProperties;
	 if (TaxonDated->Items->Count != (int)TaxaList.size()) {
	   TaxonDated->BeginUpdate();
	   TaxonDated->Items->Clear();
	   for (unsigned int i=0; i<TaxaList.size(); i++)
		 TaxonDated->Items->Add(TaxaList[i].Name);
       TaxonDated->EndUpdate();
       }
     }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::txTaxonPropertiesInitPopup(
      TObject *Sender)
{
   if (GeochronTaxaOpen) {
     TcxComboBoxProperties* TaxonDated = ((TcxComboBox*)Sender)->Properties;
	 if (TaxonDated->Items->Count != (int)GeochronTaxaList.size()) {
	   TaxonDated->BeginUpdate();
	   TaxonDated->Items->Clear();
	   for (unsigned int i=0; i<GeochronTaxaList.size(); i++)
		 TaxonDated->Items->Add(GeochronTaxaList[i].Name);
	   TaxonDated->EndUpdate();
	   }
	 }
   else if (TaxaList.size() > 0) {
	 TcxComboBoxProperties* TaxonDated = ((TcxComboBox*)Sender)->Properties;
	 if (TaxonDated->Items->Count != (int)TaxaList.size()) {
	   TaxonDated->BeginUpdate();
	   TaxonDated->Items->Clear();
	   for (unsigned int i=0; i<TaxaList.size(); i++)
		 TaxonDated->Items->Add(TaxaList[i].Name);
	   TaxonDated->EndUpdate();
       }
     }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::txUserSpecimenIDPropertiesValidate(TObject *Sender, Variant &DisplayValue,
          TCaption &ErrorText, bool &Error)
{
   UnicodeString UserSpecID = DisplayValue;
   if (!UserSpecID.IsEmpty()) {
	 SPECIMEN* specimen = TaxonDatedDataSource->Specimens[UserSpecID];
	 int idx1 = cxGrid2TableView1->DataController->FocusedRecordIndex;
	 int idx2 = cxGrid2TableView1->DataController->GetDetailDataController(idx1,0)->FocusedRecordIndex;
	 cxGrid2TableView1->DataController->GetDetailDataController(idx1,0)->Values[idx2][1] = specimen->Taxon;
	 if (!specimen->Element.IsEmpty())
	   cxGrid2TableView1->DataController->GetDetailDataController(idx1,0)->Values[idx2][2] = specimen->Element;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxGrid2TableView2InitEdit(
      TcxCustomGridTableView *Sender, TcxCustomGridTableItem *AItem,
      TcxCustomEdit *AEdit)
{
   cxCheckBox2->Visible = false;
   cxCheckBox3->Visible = false;
   cxRadioButton7->Visible = false;
   cxRadioButton8->Visible = false;

   int idx1 = cxGrid2TableView1->DataController->FocusedRecordIndex;
   if (idx1 >= 0) {
	 int idx2 = cxGrid2TableView1->DataController->GetDetailDataController(idx1,0)->FocusedRecordIndex;
	 cxButton4->Visible = true;
	 cxButton17->Visible = false;
	 cxButton18->Visible = false;
	 GEOCHRON* Geochron = &GeochronList->Dates[idx1];

	 if (ContainsText(Geochron->AgeUnits, L"Radiocarbon") && idx2 >= 0) {
	   if (!Geochron->TaxaDated[idx2].Taxon.IsEmpty()) {
		 cxButton17->Visible = true;
		 cxButton18->Visible = true;
		 }
	   }
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxGrid2TableView1DataControllerDetailExpanding(TcxCustomDataController *ADataController,
		  int ARecordIndex, bool &AAllow)
{
   GEOCHRON* Geochron = &GeochronList->Dates[ARecordIndex];
   if (!Geochron->AnalUnit.IsEmpty()) {
	 TcxComboBoxProperties* UserSpecIDs = (TcxComboBoxProperties*)(txUserSpecimenID->Properties);
	 UserSpecIDs->Items->BeginUpdate();
	 UserSpecIDs->Items->Clear();
	 TaxonDatedDataSource->Specimens.clear();

	 int StartCol = AbsHeaderColCount(ProfGrid1);
	 int EndCol = AbsContentColCount(ProfGrid1);
	 int acol = 0;
	 for (int col=StartCol; col<=EndCol; col++) {
	   if (SameText(Geochron->AnalUnit,ProfGrid1->AbsoluteCells[col][2]->Text)) {
		 acol = col;
		 break;
		 }
	   }
	 if (acol > 0) {
	   int EndRow = AbsContentRowCount(ProfGrid1);;
	   for (int row=3; row<=EndRow; row++) {
		 TProfGridCell* ACell = ProfGrid1->AbsoluteCells[acol][row];
		 if (ACell->CellObject != NULL) {
		   CELLOBJECT* CellObject = (CELLOBJECT*)ACell->CellObject;
		   if (CellObject->ObjectType == CELLSPECIMENS) {
			 TList* Specimens = (TList*)CellObject->Object;
			 for (int i=0; i<Specimens->Count; i++) {
			   SPECIMEN *specimen = (SPECIMEN*)Specimens->Items[i];
			   if (!specimen->UserSpecimenID.IsEmpty()) {
				 UserSpecIDs->Items->Add(specimen->UserSpecimenID);
				 TaxonDatedDataSource->Specimens[specimen->UserSpecimenID] = specimen;
				 }
			   }
			 }
		   }
		 }
	   }
	   UserSpecIDs->Items->EndUpdate();
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxGrid2TableView2FocusedItemChanged(TcxCustomGridTableView *Sender,
		  TcxCustomGridTableItem *APrevFocusedItem, TcxCustomGridTableItem *AFocusedItem)
{
   cxButton18->Visible = (AFocusedItem->Index == txFraction->Index);
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxGrid2TableView1InitEdit(
      TcxCustomGridTableView *Sender, TcxCustomGridTableItem *AItem,
      TcxCustomEdit *AEdit)
{
   cxCheckBox2->Visible = true;
   cxCheckBox3->Visible = true;
   cxRadioButton7->Visible = true;
   cxRadioButton8->Visible = true;
   cxButton4->Visible = false;
   cxButton17->Visible = false;
   cxButton18->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::Test1Click(TObject *Sender)
{
   TSiteHierarchyForm* SiteHierarchyForm = new TSiteHierarchyForm(this);
   SiteHierarchyForm->ShowModal();
   delete SiteHierarchyForm;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxBlobEdit1PropertiesCloseUp(TObject *Sender)
{
   GeochronDataset.Notes = cxBlobEdit1->Text;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxButton39Click(TObject *Sender)
{
   UnicodeString msg;
   unsigned short year, month, day;
   TDateTime Date;
   double YearBP;
   double Age = -9999;
   double AgeOlder;
   double AgeYounger;

   int ChronNo = 0;
   for (int i=0; i<AgeModelList->Count; i++) {
	 AGEMODEL* AgeModel = AgeModelList->AgeModels[i];
	 if (AgeModel->ChronNumber > ChronNo)
	   ChronNo = AgeModel->ChronNumber;
	 }
   ChronNo++;

   AGEMODEL *AgeModel = new AGEMODEL();
   AgeModel->ChronNumber = ChronNo;
   AgeModel->ChronologyName = L"Calendar date";
   AgeModel->AgeUnits = L"Calendar years BP";
   AgeModel->AgeModel = L"collection date";
   AgeModel->DatePrepared = Today();
   if (AgeModelList->Count == 0)
	 AgeModel->Default = true;

   CHRON* ChronControl = new CHRON();
   ChronControl->AgeUnits = L"Calendar";
   ChronControl->ControlType = L"Collection date";

   if (!ProfGrid1->AbsoluteCells[8][2]->Text.IsEmpty()) {
	 //geAnalUnit->Visible = true;
	 CheckBox3->Checked = true;
	 ChronControl->AnalUnit = ProfGrid1->AbsoluteCells[8][2]->Text;
	 }
   else if (!ProfGrid1->AbsoluteCells[8][1]->Text.IsEmpty()) {
	 double depth;
	 if (TryStrToFloat(ProfGrid1->AbsoluteCells[8][1]->Text, depth)) {
	   ChronControl->Depth = depth;
	   int thick_row = FindRowCodeIC("#Anal.Thick", ProfGrid1);
	   if (thick_row > 0) {
		 if (!ProfGrid1->AbsoluteCells[8][thick_row]->Text.IsEmpty()) {
		   double thickness;
		   if (TryStrToFloat(ProfGrid1->AbsoluteCells[8][thick_row]->Text, thickness))
			 ChronControl->Thickness = thickness;
		   }
		 }
	   }
	 else {
	   delete ChronControl;
	   delete AgeModel;
	   msg = L"Analysis unit depth in spreadsheet is invalid.";
	   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return;
	   }
	 }
   else {
	 delete ChronControl;
	 delete AgeModel;
	 msg = L"Analysis unit does not have depth or name in spreadsheeet.";
	 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 return;
	 }

   SITE *Site = (SITE*)Sites->Items[0];
   if (!Site->CollUnits[0].CollDate.IsEmpty() && Site->CollUnits[0].CollDate.Type() == varDate) {
	 Date = VarToDateTime(Site->CollUnits[0].CollDate);
	 Date.DecodeDate(&year, &month, &day);
	 double YearBP = 1950-year;
	 AgeModel->AgeBoundOlder = YearBP;
	 AgeModel->AgeBoundYounger = YearBP;
	 ChronControl->AgeValue = YearBP;
	 ChronControl->AgeLimitOlder = YearBP;
	 ChronControl->AgeLimitYounger = YearBP;
	 Age = YearBP;
	 AgeOlder = YearBP;
	 AgeYounger = YearBP;
	 }
   else {
	 SurfaceSampleAgeForm = new TSurfaceSampleAgeForm(this);
     SurfaceSampleAgeForm->SetManual();
	 if (SurfaceSampleAgeForm->ShowModal() == mrOk) {
	   int SampleAgeStyle = SurfaceSampleAgeForm->SampleAgeStyle;
	   switch (SampleAgeStyle) {
		 case dsEXACTDATE:
		   Site->CollUnits[0].CollDate = SurfaceSampleAgeForm->cxDateEdit1->Date;
		   cxDateEdit1->Date = Site->CollUnits[0].CollDate;
		   Date = VarToDateTime(SurfaceSampleAgeForm->cxDateEdit1->Date);
		   Date.DecodeDate(&year, &month, &day);
		   Age = 1950 - year;
		   AgeOlder = Age;
		   AgeYounger = Age;
		   ChronControl->AgeValue = Age;
		   break;
		 case dsYEAR:
		   Age = SurfaceSampleAgeForm->YearBP;
		   AgeOlder = Age;
		   AgeYounger = Age;
		   ChronControl->AgeValue = Age;
		   year = 1950 - Age;
		   Site->CollUnits[0].CollDate = TDateTime(year,1,1);
		   cxDateEdit1->Date = Site->CollUnits[0].CollDate;
		   break;
		 case dsYEARRANGE:
		   AgeOlder = SurfaceSampleAgeForm->YearOlderBP;
		   AgeYounger = SurfaceSampleAgeForm->YearYoungerBP;
		   break;
		 }
	   delete SurfaceSampleAgeForm;
	   AgeModel->AgeBoundOlder = AgeOlder;
	   AgeModel->AgeBoundYounger = AgeYounger;
	   ChronControl->AgeLimitOlder = AgeOlder;
	   ChronControl->AgeLimitYounger = AgeYounger;
	   }
	 else {
	   delete SurfaceSampleAgeForm;
	   delete ChronControl;
	   delete AgeModel;
	   return;
	   }

	 if (Age == -9999 && (AgeOlder == -9999 || AgeYounger == -9999)) {
		// this should never happen, but...
		delete ChronControl;
		delete AgeModel;
		msg = L"Age of surface sample not set correctly.";
		MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		return;
	   }
	 }

   UnicodeString ChronCode = L"#Chron" + IntToStr(ChronNo);
   UnicodeString ChronCodeOld = ChronCode + L".Old";
   UnicodeString ChronCodeYoung = ChronCode + L".Young";

   int chron_row = FindRowCodeIC(ChronCode, ProfGrid1);
   int chron_row_old = FindRowCodeIC(ChronCodeOld, ProfGrid1);
   int chron_row_young = FindRowCodeIC(ChronCodeYoung, ProfGrid1);

   ProfGrid1->DisableControls();
   ProfGrid1->SpreadsheetEnabled = false;

   if (Age != -9999) {
	 if (chron_row == 0) {
	   chron_row = 3;
	   ProfGrid1->InsertRow(chron_row);
	   ProfGrid1->AbsoluteCells[1][chron_row]->Value = WideString(ChronCode);
	   ProfGrid1->AbsoluteCells[2][chron_row]->Value = WideString(L"Collection date");
	   ProfGrid1->AbsoluteCells[4][chron_row]->Value = WideString(L"calendar yr BP");
	   }
	 ProfGrid1->AbsoluteCells[8][chron_row]->Value = Age;
	 }
   if (chron_row_old == 0) {
	 chron_row_old = (chron_row == 0) ? 3 : chron_row+1;
	 ProfGrid1->InsertRow(chron_row_old);
	 ProfGrid1->AbsoluteCells[1][chron_row_old]->Value = WideString(ChronCodeOld);
	 ProfGrid1->AbsoluteCells[2][chron_row_old]->Value = WideString(L"Collection date Older Bound");
	 ProfGrid1->AbsoluteCells[4][chron_row_old]->Value = WideString(L"calendar yr BP");
	 }
   ProfGrid1->AbsoluteCells[8][chron_row_old]->Value = AgeOlder;
   if (chron_row_young == 0) {
	 chron_row_young = chron_row_old + 1;
	 ProfGrid1->InsertRow(chron_row_young);
	 ProfGrid1->AbsoluteCells[1][chron_row_young]->Value = WideString(ChronCodeYoung);
	 ProfGrid1->AbsoluteCells[2][chron_row_young]->Value = WideString(L"Collection date Younger Bound");
	 ProfGrid1->AbsoluteCells[4][chron_row_young]->Value = WideString(L"calendar yr BP");
	 }
   ProfGrid1->AbsoluteCells[8][chron_row_young]->Value = AgeYounger;

   SpreadSheetChanged = true;
   ProfGrid1->SpreadsheetEnabled = true;
   ProfGrid1->EnableControls();

   AgeModel->ChronControls->Add(ChronControl);
   AgeModelList->Add(AgeModel);
   cxButton39->Visible = false;
}
//---------------------------------------------------------------------------

