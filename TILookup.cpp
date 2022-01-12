//---------------------------------------------------------------------------
#define VCL_IOSTREAM
#include <vcl.h>
#include "pch.h"
#pragma hdrstop

#include <vector>
#include <algorithm>
#include <functional>
#include <io.h>
#include "TILookup.h"
#ifndef TIGlobalsH
#include "TIGlobals.h"
#endif
#ifndef TISpreadH
#include "TISpread.h"
#endif
#ifndef TGUtilsH
#include "TGUtils.h"
#endif


//---------------------------------------------------------------------------

#pragma package(smart_init)
#pragma link "ipwCore"
#pragma link "ipwxmlp"


GEOPOLITICAL::GEOPOLITICAL()
{
   GP = new TList;
   GP1 = new TList;
   GeoPolRecord1 = NULL;
   GeoPolRecord2 = NULL;
   GeoPolRecord3 = NULL;
   HighestID = -1;
}
//---------------------------------------------------------------------------

GEOPOLITICAL::~GEOPOLITICAL()
{
   delete GP1;
   DeleteList(GP);
}
//---------------------------------------------------------------------------

int GEOPOLITICAL::GetNextID(void)
{
   return(++HighestID);
}
//---------------------------------------------------------------------------

void GEOPOLITICAL::AddGeoPol(GEOPOLRECORD* GeoPolRec)
{
   int idx;
   GEOPOLRECORD* HigherRec;

   GP->Add(GeoPolRec);
   if (GeoPolRec->ID > HighestID)
     HighestID = GeoPolRec->ID;
   switch (GeoPolRec->Rank)
    {
    case 1:     // countries
      GP1->Add(GeoPolRec);
      break;
    case 2:     // states
	  FindID(GeoPolRec->HigherID, &HigherRec);
      HigherRec->SubUnits->Add(GeoPolRec);
      GeoPolRec->HigherRec = HigherRec;
      break;
    case 3:     // counties
      FindID(GeoPolRec->HigherID, &HigherRec);
      HigherRec->SubUnits->Add(GeoPolRec);
      GeoPolRec->HigherRec = HigherRec;
      break;
    case 4:     // Admin Units
      FindID(GeoPolRec->HigherID, &HigherRec);
      HigherRec->AdminUnits->Add(GeoPolRec);
      GeoPolRec->HigherRec = HigherRec;
      break;
    }
}
//---------------------------------------------------------------------------

void __fastcall GEOPOLITICAL::FindID(int ID, GEOPOLRECORD** GeoPolRec)
{
   *GeoPolRec = NULL;
   for (int i=GP->Count-1; i>=0; i--) {
	 GEOPOLRECORD* GPRec = (GEOPOLRECORD*)GP->Items[i];
	 if (GPRec->ID == ID) {
	   *GeoPolRec = GPRec;
	   return;
	   }
	 }
}
//---------------------------------------------------------------------------

GEOPOLRECORD* GEOPOLITICAL::FindGPName(UnicodeString Name)
{
   for (int i=GP->Count-1; i>=0; i--) {
	 GEOPOLRECORD* GPRec = (GEOPOLRECORD*)GP->Items[i];
	 if (SameText(GPRec->Name, Name))
	   return GPRec;
	 }
   return NULL;
}
//---------------------------------------------------------------------------

void GEOPOLITICAL::SetGeoPolRec1(UnicodeString Name)
{
   GeoPolRecord1 = NULL;
   for (int i=0; i<GP1->Count; i++) {
     GEOPOLRECORD* GeoPolRec1 = (GEOPOLRECORD*)GP1->Items[i];
     if (SameText(GeoPolRec1->Name, Name)) {
       GeoPolRecord1 = GeoPolRec1;
       break;
       }
     }
}
//---------------------------------------------------------------------------

void GEOPOLITICAL::SetGeoPolRec2(UnicodeString Name)
{
   GeoPolRecord2 = NULL;
   for (int i=0; i<GP2->Count; i++) {
     GEOPOLRECORD* GeoPolRec2 = (GEOPOLRECORD*)GP2->Items[i];
	 if (SameText(GeoPolRec2->Name, Name)) {
       GeoPolRecord2 = GeoPolRec2;
       break;
	   }
	 }
}
//---------------------------------------------------------------------------

void GEOPOLITICAL::SetGeoPolRec3(UnicodeString Name)
{
   GeoPolRecord3 = NULL;
   for (int i=0; i<GP3->Count; i++) {
     GEOPOLRECORD* GeoPolRec3 = (GEOPOLRECORD*)GP3->Items[i];
     if (SameText(GeoPolRec3->Name, Name)) {
       GeoPolRecord3 = GeoPolRec3;
       break;
       }
     }
}
//---------------------------------------------------------------------------

bool GEOPOLITICAL::SetGeoPolRec4(UnicodeString Name)
{
   GEOPOLRECORD* GeoPolRec;
   GeoPolRecord4 = NULL;
   if (GeoPolRecord1) {
     for (int i=0; i<GeoPolRecord1->AdminUnits->Count; i++) {
       GeoPolRec = (GEOPOLRECORD*)GeoPolRecord1->AdminUnits->Items[i];
       if (SameText(Name, GeoPolRec->Name)) {
         GeoPolRecord4 = GeoPolRec;
         return true;
         }
       }
     if (!GeoPolRecord4 && GeoPolRecord2) {
       for (int i=0; i<GeoPolRecord2->AdminUnits->Count; i++) {
         GeoPolRec = (GEOPOLRECORD*)GeoPolRecord2->AdminUnits->Items[i];
         if (SameText(Name, GeoPolRec->Name)) {
           GeoPolRecord4 = GeoPolRec;
           return true;
           }
         }
       if (!GeoPolRecord4 && GeoPolRecord3) {
         for (int i=0; i<GeoPolRecord3->AdminUnits->Count; i++) {
           GeoPolRec = (GEOPOLRECORD*)GeoPolRecord3->AdminUnits->Items[i];
		   if (SameText(Name, GeoPolRec->Name)) {
             GeoPolRecord4 = GeoPolRec;
             return true;
             }
           }
         }
       }
     }
   return false;
}
//---------------------------------------------------------------------------

void GEOPOLITICAL::GeoPol1(TStrings* Strings)
{
   TStringList* Countries = new TStringList;
   for (int i=0; i<GP1->Count; i++) {
     GEOPOLRECORD* GeoPolRec = (GEOPOLRECORD*)GP1->Items[i];
     Countries->Append(GeoPolRec->Name);
     }
   Countries->Sort();
   Strings->AddStrings(Countries);
   delete Countries;
}
//---------------------------------------------------------------------------

bool GEOPOLITICAL::SetGeoPol2(void)
{
   if (GeoPolRecord1) {
	 GP2 = GeoPolRecord1->SubUnits;
	 return true;
	 }
   else
	 return false;
}
//---------------------------------------------------------------------------

bool GEOPOLITICAL::SetGeoPol3(void)
{
   if (GeoPolRecord2) {
	 GP3 = GeoPolRecord2->SubUnits;
	 return true;
	 }
   else
	 return false;
}
//---------------------------------------------------------------------------

void GEOPOLITICAL::GeoPol2(UnicodeString Name, TStrings* Strings)
{
   TStringList* States = new TStringList;
   if (GeoPolRecord1) {
	 GP2 = GeoPolRecord1->SubUnits;
	 for (int j=0; j<GP2->Count; j++) {
       GEOPOLRECORD* GeoPolRec2 = (GEOPOLRECORD*)GP2->Items[j];
       if (GeoPolRec2->HigherID == GeoPolRecord1->ID)
         States->Append(GeoPolRec2->Name);
       }
     if (States->Count) {
       States->Sort();
       Strings->AddStrings(States);
       }
     }
   delete States;
}
//---------------------------------------------------------------------------

void GEOPOLITICAL::GeoPol3(UnicodeString Name, TStrings* Strings)
{
   TStringList* Counties = new TStringList;
   if (GeoPolRecord2) {
	 GP3 = GeoPolRecord2->SubUnits;
     for (int j=0; j<GP3->Count; j++) {
       GEOPOLRECORD* GeoPolRec3 = (GEOPOLRECORD*)GP3->Items[j];
       if (GeoPolRec3->HigherID == GeoPolRecord2->ID)
         Counties->Append(GeoPolRec3->Name);
       }
     if (Counties->Count) {
       Counties->Sort();
       Strings->AddStrings(Counties);
       }
     }
   delete Counties;
}
//---------------------------------------------------------------------------

// country level
void GEOPOLITICAL::GeoPol4Unit1(UnicodeString Name, TStrings* Strings)
{
   TStringList* AdminUnits = new TStringList;
   if (GeoPolRecord1) {
     GetAdminUnits(GeoPolRecord1, AdminUnits);
     if (AdminUnits->Count) {
       AdminUnits->Sort();
       Strings->AddStrings(AdminUnits);
       }
     }
   delete AdminUnits;
}
//---------------------------------------------------------------------------

// state level
void GEOPOLITICAL::GeoPol4Unit2(UnicodeString Name, TStrings* Strings)
{
   TStringList* AdminUnits = new TStringList;
   if (GeoPolRecord2) {
     GetAdminUnits(GeoPolRecord2, AdminUnits);
     GetAdminUnits(GeoPolRecord2->HigherRec, AdminUnits);
     if (AdminUnits->Count) {
       AdminUnits->Sort();
       Strings->AddStrings(AdminUnits);
       }
     }
   delete AdminUnits;
}
//---------------------------------------------------------------------------

// county level
void GEOPOLITICAL::GeoPol4Unit3(UnicodeString Name, TStrings* Strings)
{
   TStringList* AdminUnits = new TStringList;
   if (GeoPolRecord3) {
     GetAdminUnits(GeoPolRecord3, AdminUnits);
     GetAdminUnits(GeoPolRecord3->HigherRec, AdminUnits);
     GetAdminUnits(GeoPolRecord3->HigherRec->HigherRec, AdminUnits);
     if (AdminUnits->Count) {
       AdminUnits->Sort();
       Strings->AddStrings(AdminUnits);
       }
     }
   delete AdminUnits;
}
//---------------------------------------------------------------------------

void GEOPOLITICAL::GetAdminUnits(GEOPOLRECORD* GeoPolRec, TStringList* AdminUnits)
{
   TList* AUList = GeoPolRec->AdminUnits;
   for (int j=0; j<AUList->Count; j++) {
     GEOPOLRECORD* GeoPolRec4 = (GEOPOLRECORD*)AUList->Items[j];
     if (GeoPolRec4->HigherID == GeoPolRec->ID)
       AdminUnits->Append(GeoPolRec4->Name);
     }
}
//---------------------------------------------------------------------------

UnicodeString GEOPOLITICAL::GetUnit1(void)
{
   UnicodeString Unit;
   if (GeoPolRecord1)
     Unit = GeoPolRecord1->Unit;
   return Unit;
}
//---------------------------------------------------------------------------

//UnicodeString GEOPOLITICAL::GetUnit2(UnicodeString Name)
UnicodeString GEOPOLITICAL::GetUnit2(void)
{
   UnicodeString Unit;
   if (GeoPolRecord2)
     Unit = GeoPolRecord2->Unit;
   return Unit;
}
//---------------------------------------------------------------------------

UnicodeString GEOPOLITICAL::GetUnitForGeoPol2(UnicodeString StateName)
{
   UnicodeString GeoPolUnit;
   for (int i=0; i<GP2->Count; i++) {
	 GEOPOLRECORD* GeoPolRec2 = (GEOPOLRECORD*)GP2->Items[i];
	 if (SameText(GeoPolRec2->Name, StateName)) {
	   GeoPolUnit = GeoPolRec2->Unit;
	   break;
	   }
	 }
   return GeoPolUnit;
}
//---------------------------------------------------------------------------

UnicodeString GEOPOLITICAL::GetUnit3(void)
{
   UnicodeString Unit;
   if (GeoPolRecord3)
	 Unit = GeoPolRecord3->Unit;
   return Unit;
}
//---------------------------------------------------------------------------

UnicodeString GEOPOLITICAL::GetUnitForGeoPol3(UnicodeString CountyName)
{
   UnicodeString GeoPolUnit;
   for (int i=0; i<GP3->Count; i++) {
	 GEOPOLRECORD* GeoPolRec3 = (GEOPOLRECORD*)GP3->Items[i];
	 if (SameText(GeoPolRec3->Name, CountyName)) {
	   GeoPolUnit = GeoPolRec3->Unit;
	   break;
	   }
	 }
   return GeoPolUnit;
}
//---------------------------------------------------------------------------

UnicodeString GEOPOLITICAL::GetUnit4(void)
{
   UnicodeString Unit;
   if (GeoPolRecord4)
     Unit = GeoPolRecord4->Unit;
   return Unit;
}
//---------------------------------------------------------------------------

void GEOPOLITICAL::AddAdminUnit1(UnicodeString Name, UnicodeString Unit)
{
   GEOPOLRECORD* GeoPolRec = new GEOPOLRECORD;
   GeoPolRec->ID = GetNextID();
   GeoPolRec->Name = Name;
   GeoPolRec->Unit = Unit;
   GeoPolRec->Rank = 4;
   GeoPolRec->HigherID = GeoPolRecord1->ID;
   GeoPolRec->HigherRec = GeoPolRecord1;
   GP->Add(GeoPolRec);
   GeoPolRecord1->AdminUnits->Add(GeoPolRec);
}
//---------------------------------------------------------------------------

void GEOPOLITICAL::AddAdminUnit2(TStringList* States, UnicodeString Name, UnicodeString Unit)
{
   int NextID;

   for (int i=0; i<States->Count; i++) {
     for (int j=0; j<GeoPolRecord1->SubUnits->Count; j++) {
       GEOPOLRECORD* GeoPolRec2 = (GEOPOLRECORD*)GeoPolRecord1->SubUnits->Items[j];
       if (SameText(GeoPolRec2->Name, States->Strings[i])) {
         GEOPOLRECORD* GeoPolRec = new GEOPOLRECORD;
         if (i == 0)
           NextID = GetNextID();
         GeoPolRec->ID = NextID;
         GeoPolRec->Name = Name;
         GeoPolRec->Unit = Unit;
         GeoPolRec->Rank = 4;
         GeoPolRec->HigherID = GeoPolRec2->ID;
         GeoPolRec->HigherRec = GeoPolRec2;
         GP->Add(GeoPolRec);
         GeoPolRec2->AdminUnits->Add(GeoPolRec);
         break;
         }
       }
     }
}
//---------------------------------------------------------------------------

void GEOPOLITICAL::AddAdminUnit3(TStringList* Counties, UnicodeString Name, UnicodeString Unit)
{
   int NextID;

   for (int i=0; i<Counties->Count; i++) {
     for (int j=0; j<GeoPolRecord2->SubUnits->Count; j++) {
       GEOPOLRECORD* GeoPolRec3 = (GEOPOLRECORD*)GeoPolRecord2->SubUnits->Items[j];
       if (SameText(GeoPolRec3->Name, Counties->Strings[i])) {
         GEOPOLRECORD* GeoPolRec = new GEOPOLRECORD;
		 if (i == 0)
           NextID = GetNextID();
         GeoPolRec->ID = NextID;
         GeoPolRec->Name = Name;
         GeoPolRec->Unit = Unit;
         GeoPolRec->Rank = 4;
         GeoPolRec->HigherID = GeoPolRec3->ID;
         GeoPolRec->HigherRec = GeoPolRec3;
         GP->Add(GeoPolRec);
         GeoPolRec3->AdminUnits->Add(GeoPolRec);
         break;
         }
       }
     }
}
//---------------------------------------------------------------------------

void GEOPOLITICAL::Save(void)
{
   UnicodeString GeoPolFileName = tiGlobals->AppDataTiliaLookupPath;
   GeoPolFileName += L"GeoPoliticalUnits.xml";

   WriteXML *xmlout = new WriteXML(GeoPolFileName);
   Screen->Cursor = crHourGlass;

   try {
   try {
	xmlout->Declaration(L"1.0", L"UTF-8", L"yes");
	xmlout->DateTime();
	xmlout->BeginTag(L"GeoPoliticalUnits");
	for (int i=0; i<GP->Count; i++) {
	  GEOPOLRECORD* GeoPolRec = (GEOPOLRECORD*)GP->Items[i];
	  xmlout->BeginTag(L"GeoPolitical", L"ID", GeoPolRec->ID);
	  xmlout->Element(L"GeoPoliticalName", GeoPolRec->Name);
	  xmlout->Element(L"GeoPoliticalUnit", GeoPolRec->Unit);
	  xmlout->Element(L"Rank", GeoPolRec->Rank);
	  xmlout->Element(L"HigherGeoPoliticalID", GeoPolRec->HigherID);
	  xmlout->EndTag(L"GeoPolitical");
	  }
	xmlout->EndTag(L"GeoPoliticalUnits");
	xmlout->Finish();
	}
   catch(Exception &e)
	{
	MessageDlg(e.Message, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	}
	}
   __finally
	{
	delete xmlout;
	Screen->Cursor = crDefault;
	}
}
//---------------------------------------------------------------------------

void RELATIVEAGE::XMLOut(WriteXML* xmlout)
{
   if (!IsNan(C14AgeYounger))
	 xmlout->Element(L"C14AgeYounger", C14AgeYounger);
   if (!IsNan(C14AgeOlder))
	 xmlout->Element(L"C14AgeOlder", C14AgeOlder);
   if (!IsNan(CalAgeYounger))
	 xmlout->Element(L"CalAgeYounger", CalAgeYounger);
   if (!IsNan(CalAgeYounger))
	 xmlout->Element(L"CalAgeOlder", CalAgeOlder);
}
//---------------------------------------------------------------------------

void EVENT::XMLOut(WriteXML* xmlout)
{
   if (!IsNan(C14Age))
	 xmlout->Element(L"C14Age", C14Age);
   if (!IsNan(C14AgeYounger))
	 xmlout->Element(L"C14AgeYounger", C14AgeYounger);
   if (!IsNan(C14AgeOlder))
	 xmlout->Element(L"C14AgeOlder", C14AgeOlder);
   if (!IsNan(CalAge))
	 xmlout->Element(L"CalAge", CalAge);
   if (!IsNan(CalAgeYounger))
	 xmlout->Element(L"CalAgeYounger", CalAgeYounger);
   if (!IsNan(CalAgeYounger))
	 xmlout->Element(L"CalAgeOlder", CalAgeOlder);
   if (!Notes.IsEmpty())
	 xmlout->Element(L"Notes", Notes);

}
//---------------------------------------------------------------------------

int __fastcall TTilSpreadSheetForm::EventNameCompare(void * Item1, void * Item2)
{
   EVENT* Event1 = (EVENT*)Item1;
   EVENT* Event2 = (EVENT*)Item2;
   return CompareText(Event1->Name, Event2->Name);
}
//---------------------------------------------------------------------------

int __fastcall TTilSpreadSheetForm::EventCalAgeCompare(void * Item1, void * Item2)
{
   EVENT* Event1 = (EVENT*)Item1;
   EVENT* Event2 = (EVENT*)Item2;

   if (Event1->CalAge < Event2->CalAge)
     return -1;
   else if (Event1->CalAge > Event2->CalAge)
     return 1;
   else
     return 0;
}
//---------------------------------------------------------------------------

UnicodeString TTilSpreadSheetForm::SetXMLFileName(UnicodeString FileName)
{
   UnicodeString Path = tiGlobals->AppDataTiliaLookupPath;
   Path += FileName;
   return Path;
}
//---------------------------------------------------------------------------

bool __fastcall TTilSpreadSheetForm::OpenCountriesXML(void)
{
   bool success = true;
   try {
	   try {
		   gpx = new GEOPOLITICALXML();
		   ipwXMLp5->Config(L"CodePage=65001");
		   //ShowMessage(L"Start parsing");
		   ipwXMLp5->ParseFile(SetXMLFileName(L"GeoPoliticalUnits.xml"));
		   }
	   catch(...) {
		   MessageDlg(L"Cannot parse GeoPoliticalUnits.xml lookup file.", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   XMLLookUpError = true;
		   XMLFileName.SetLength(0);
		   success = false;;
		   }
	   }
   __finally
	   {
	   delete gpx;
	   }
   return success;
}
//---------------------------------------------------------------------------

bool TTilSpreadSheetForm::GetLookupItems(void)
{
   int version = 1;
   int n, ival, count;
   UnicodeString FilePathName;
   UnicodeString utext;
   UTF8String XPath, XPath1, XPath2, XPath3;
   TipwXMLp *LookUp;
   double dValue;
   WideString WideValue;

   try {
	   FilePathName = SetXMLFileName(L"Lookup.xml");
	   LookUp = GetXMLFilePtr();
	   LookUp->Config(L"CodePage=65001");
	   LookUp->ParseFile(FilePathName);
	   }
   catch (Exception &e) {
	   //throw EReadBinaryFileError(e.Message + L": Lookup.xml");
	   UnicodeString msg = e.Message + L": Lookup.xml";
	   msg += L"\nFull path: " + FilePathName;
	   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return false;
	   }

   bool rv = true;
   xmlin = new ParseXMLUnicode(LookUp);

   try {
	 try {

	 if (!SameText(xmlin->RootElement(), "TiliaLookup"))
	   throw(Exception(L"Lookup.xml is not a valid Tilia Lookup file."));

	 XPath = L"/TiliaLookup/";
	 if (xmlin->GetIntValue(XPath, L"Version", ival))
	   version = ival;

	 // read lake parameters

	 if (version >= 4) {
	   if (xmlin->ValidChild(XPath, L"LakeParameters", count)) {
		 UnicodeString Code, Name, Menu;
		 XMLSubElement LakeParameter(L"/TiliaLookup/LakeParameters/LakeParameter");
		 AdvStringGridLake->RowCount = count + 1;
		 AdvStringGridLake->AutoSizeCol(1,4);
		 for (int i=1; i<=count; i++) {
		   XPath = LakeParameter.XPath(i);
		   xmlin->GetTextValue(XPath, L"Code", Code);
		   xmlin->GetTextValue(XPath, L"Name", Name);
		   xmlin->GetTextValue(XPath, L"Menu", Menu);
		   LAKEPARAMETER LakePar(Code, Name, Menu);
		   LakeChar.push_back(LakePar);
		   AdvStringGridLake->Cells[0][i] = Name;
		   }
		 AdvStringGridLake->AutoSizeCol(0,4);
		 AdvStringGridLake->CellProperties[0][0]->FontStyle = TFontStyles() << fsBold;
		 AdvStringGridLake->CellProperties[1][0]->FontStyle = TFontStyles() << fsBold;
		 AdvStringGridLake->CellProperties[0][0]->Alignment = taCenter;
		 AdvStringGridLake->CellProperties[1][0]->Alignment = taCenter;
		 AdvStringGridLake->CellProperties[0][0]->BrushColor = (TColor)0x00FFDDC4;
		 AdvStringGridLake->CellProperties[1][0]->BrushColor = (TColor)0x00FFDDC4;
		 AdvStringGridLake->QSort();

		 // Add LakeParameters to spreadsheet PopupMenu
		 TMenuItem* MenuItem;
		 list<LAKEPARAMETER>::iterator itr = LakeChar.begin();
		 while (itr != LakeChar.end()) {
		   UnicodeString ItemCaption = itr->Menu;
		   UnicodeString ItemName = itr->Code;
		   ItemName.Insert(L"md", 1);
		   ItemName += L"1";
		   MenuItem = NewItem(ItemCaption, 0, false, true, LakeCharacteristicMenuItem, 0, ItemName);
		   MenuItem->Hint = itr->Name;
		   mdLakeCharacteristics1->Add(MenuItem);
		   itr++;
		   }
		 }
	   }

	 if (xmlin->ValidChild(L"/TiliaLookup/", L"CollectionTypes", count)) {
	   cxComboBox1->Properties->Items->Clear();
	   for (int i=0; i<count; i++) {
		 if (xmlin->GetChildText(i, utext))
		   cxComboBox1->Properties->Items->Add(utext);
		 }
	   cxComboBox1->ItemIndex = -1;
	   }

	 if (xmlin->ValidChild(L"/TiliaLookup/", L"DepositionalEnvironments", count)) {
	   if (count > 0) {
		 TREENODE DepEnvt;
		 vector<TREENODE> DepEnvts;
		 XMLSubElement DepEnvtElement(L"/TiliaLookup/DepositionalEnvironments/Context");
		 for (int i=1; i<=count; i++) {
		   XPath = DepEnvtElement.XPath(i);
		   xmlin->GetAttrInt(XPath, L"ID", DepEnvt.ID);
		   xmlin->GetIntValue(XPath, L"HigherID", DepEnvt.HigherID);
		   xmlin->GetTextValue(XPath, L"Name", DepEnvt.Name);
		   DepEnvts.push_back(DepEnvt);
		   }
		 BuilddxTreeViewEdit(DepEnvts, dxTreeViewEdit1);
		 dxTreeViewEdit1->Items->AlphaSort();
		 }
	   }

	 // substrates
	 if (version >= 4) {
	   if (xmlin->ValidChild(L"/TiliaLookup/", L"Substrates", count)) {
		 if (count > 0) {
		   SUBSTRATE Substrate;
		   vector<SUBSTRATE> Substrates;
		   vector<int> idx(count, 0);
		   SubstrateDescriptions = new TStringList;

		   dxTreeViewEdit2->Items->BeginUpdate();
		   XMLSubElement SubstrateElement(L"/TiliaLookup/Substrates/Substrate");

		   // parse substrates into a vector
		   // retrievals from a vector are much faster than from XML DOM
		   for (int i=1; i<=count; i++) {
			 XPath = SubstrateElement.XPath(i);
			 xmlin->GetAttrInt(XPath, L"ID", Substrate.ID);
			 xmlin->GetIntValue(XPath, L"HigherID", Substrate.HigherID);
			 xmlin->GetTextValue(XPath, L"RockType", Substrate.RockType);
			 xmlin->GetTextValue(XPath, L"Description", Substrate.Description);
			 Substrates.push_back(Substrate);
			 }

		   // first pass
		   for (int i=0; i<count; i++) {
			 if (Substrates[i].ID == Substrates[i].HigherID) {
			   SubstrateDescriptions->Add(Substrates[i].Description);
			   int last = SubstrateDescriptions->Count - 1;
			   dxTreeViewEdit2->Items->AddObject(NULL, Substrates[i].RockType, SubstrateDescriptions->Strings[last].c_str());
			   idx[i] = 1;
			   }
			 }

		   int level = 1;
		   bool NewAdded = true;
		   TTreeNode *Node;
		   while (dxTreeViewEdit2->Items->Count < count && NewAdded) {
			 NewAdded = false;
			 for (int i=0; i<count; i++) {
			   if (idx[i] == level) {
				 for (int k=0; k<dxTreeViewEdit2->Items->Count; k++) {
				   Node = dxTreeViewEdit2->Items->Item[k];
				   if (SameText(Node->Text, Substrates[i].RockType))
					 break;
				   }
				 for (int k=count-1; k>=0; k--) {
				   if (Substrates[k].HigherID == Substrates[i].ID && Substrates[k].HigherID != Substrates[k].ID) {
					 SubstrateDescriptions->Add(Substrates[k].Description);
					 int last = SubstrateDescriptions->Count - 1;
					 dxTreeViewEdit2->Items->AddChildObject(Node, Substrates[k].RockType, SubstrateDescriptions->Strings[last].c_str());
					 idx[k] = level + 1;
					 NewAdded = true;
					 }
				   }
				 }
			   }
			 level++;
			 }
		   dxTreeViewEdit2->Items->EndUpdate();
		   }
		 }
	   }

	 // facies
	 if (version >= 3) {
	   if (xmlin->ValidChild(L"/TiliaLookup/", L"Facies", count)) {
		 if (count > 0) {
		   for (int i=0; i<count; i++) {
			 if (xmlin->GetChildText(i, utext))
			   FaciesTypes.push_back(utext.LowerCase());
			 }
		   sort(FaciesTypes.begin(), FaciesTypes.end());
		   }
		 }
	   }

	 // sample keywords;
	 if (version >= 8) {
	   if (xmlin->ValidChild(L"/TiliaLookup/", L"Keywords", count)) {
		 if (count > 0) {
		   for (int i=0; i<count; i++) {
			 if (xmlin->GetChildText(i, utext))
			   SampleKeywords.push_back(utext);
			 }
		   sort(SampleKeywords.begin(), SampleKeywords.end());
		   for (unsigned int i=0; i<SampleKeywords.size(); i++) {
			 cxCheckComboBox4->Properties->Items->AddCheckItem(SampleKeywords[i], SampleKeywords[i]);
			 }
		   }
		 }
	   }
	 cxCheckComboBox4->Properties->Sorted = true;

	 // depositional agents
	 if (version >= 5) {
	   if (xmlin->ValidChild(L"/TiliaLookup/", L"DepAgents", count)) {
		 if (count > 0) {
		   for (int i=0; i<count; i++) {
			 if (xmlin->GetChildText(i, utext))
			   DepAgents.push_back(utext.LowerCase());
			 }
		   sort(DepAgents.begin(), DepAgents.end());
		   }
		 }
	   }

	 // Dataset types
	 UnicodeString DataType;
	 if (xmlin->ValidChild(L"/TiliaLookup/", L"DatasetTypes", count)) {
	   if (count) {
		 for (int i=0; i<count; i++) {
		   if (xmlin->GetChildText(i, utext))
			 DataTypes.insert(utext);
		   }
		 set<UnicodeString>::iterator itr;
		 for (itr = DataTypes.begin(); itr != DataTypes.end(); itr++) {
		   cxComboBox2->Properties->Items->Add(*itr);
		   }
		 cxComboBox2->ItemIndex = cxComboBox2->Properties->Items->IndexOf(tiGlobals->DatasetType);
		 }
	   }

	 // Aggregate orders
	 if (xmlin->ValidChild(L"/TiliaLookup/", L"AggregateOrders", count)) {
	   if (count) {
		 cxComboBox14->Properties->Items->Clear();
		 for (int i=0; i<count; i++) {
		   if (xmlin->GetChildText(i, utext))
			 cxComboBox14->Properties->Items->Add(utext);
		   }
		 }
	   }

	 // Repositories
	 if (version >= 4) {
	   if (xmlin->ValidChild(L"/TiliaLookup/", L"Repositories", count)) {
		 if (count > 0) {
		   XMLSubElement Repository(L"/TiliaLookup/Repositories/Repository");
		   AdvColumnGrid2->RowCount = count + 1;
		   UnicodeString Institution;
		   UnicodeString Acronym;
		   for (int i=1; i<=count; i++) {
			 XPath = Repository.XPath(i);
			 xmlin->GetTextValue(XPath, L"Acronym", Acronym);
			 AdvColumnGrid2->Cells[1][i] = Acronym;
			 xmlin->GetTextValue(XPath, L"Institution", Institution);
			 AdvColumnGrid2->Cells[2][i] = Institution;
			 Repositories[Institution] = Acronym;
			 if (xmlin->GetTextValue(XPath, L"Notes", utext))
			   // AdvColumnGrid2->Cells[3][i] = utext;
			   RepositoryNotes[Acronym] = utext;
			 }
		   AdvColumnGrid2->QSort();
		   AdvColumnGrid2->AddCheckBoxColumn(0, false, false);
		   }
		 }
	   }

	 if (version >= 8) {
	   if (xmlin->ValidChild(L"/TiliaLookup/", L"AggregateOrderTypes", count)) {
		 if (count > 0) {
		   cxComboBox14->Properties->Items->Clear();
		   for (int i=0; i<count; i++) {
			 if (xmlin->GetChildText(i, utext))
			   cxComboBox14->Properties->Items->Add(utext);
			 }
		   }
		 }
	   }

	 // Age types
	 TcxComboBoxProperties* ge_ageunits = (TcxComboBoxProperties*)(geAgeUnits->Properties);
	 TcxComboBoxProperties* am_ageunits = (TcxComboBoxProperties*)(amAgeUnits->Properties);
	 if (xmlin->ValidChild(L"/TiliaLookup/", "AgeTypes", count)) {
	   if (count > 0) {
		 XMLSubElement AgeType(L"/TiliaLookup/AgeTypes/AgeType");
		 if (version > 1) {
		   UnicodeString LongName;
		   UnicodeString ShortName;
		   for (int i=1; i<=count; i++) {
			 XPath = AgeType.XPath(i);
			 xmlin->GetTextValue(XPath, L"LongName", LongName);
			 xmlin->GetTextValue(XPath, L"ShortName", ShortName);
			 ge_ageunits->Items->Add(LongName);
			 am_ageunits->Items->Add(LongName);
			 AgeUnits[LongName] = ShortName;
			 }
		   }
		 else {
		   for (int i=0; i<count; i++) {
			 if (xmlin->GetChildText(i, utext)) {
			   ge_ageunits->Items->Add(utext);
			   am_ageunits->Items->Add(utext);
			   AgeUnits[utext] = utext;
			   }
			 }
		   }
		 }
	   }

	 // GeochronTypes
	 // vector<GEOCHRONPARAM> RadiocarbonParams;

	 GEOCHRONPARAM GeochronParam;
	 GeochronParam.Parameter = L"Method";
	 RadiocarbonParams.push_back(GeochronParam);
	 GeochronParam.Parameter = L"Mass C (mg)";
	 RadiocarbonParams.push_back(GeochronParam);
	 GeochronParam.Parameter = L"%C";
	 RadiocarbonParams.push_back(GeochronParam);
	 GeochronParam.Parameter = L"%N";
	 RadiocarbonParams.push_back(GeochronParam);
	 GeochronParam.Parameter = L"C:N";
	 RadiocarbonParams.push_back(GeochronParam);
	 GeochronParam.Parameter = L"δ13C";
	 RadiocarbonParams.push_back(GeochronParam);
	 GeochronParam.Parameter = L"δ15N";
	 RadiocarbonParams.push_back(GeochronParam);
	 GeochronParam.Parameter = L"%collagen";
	 RadiocarbonParams.push_back(GeochronParam);
	 GeochronParam.Parameter = L"Reservoir (yrs)";
	 RadiocarbonParams.push_back(GeochronParam);

	 TcxComboBoxProperties* Method = (TcxComboBoxProperties*)(geMethod->Properties);
	 if (xmlin->ValidChild(L"/TiliaLookup/", L"GeochronTypes", count)) {
	   if (count > 0) {
		 if (version >= 6) {
		   XMLSubElement GeochronType(L"/TiliaLookup/GeochronTypes/GeochronType");
		   //int nparams;
		   for (int i=1; i<=count; i++) {
			 //GEOCHRONTYPE Type;
			 UnicodeString Type;
			 XPath = GeochronType.XPath(i);
			 xmlin->GetTextValue(XPath, L"Type", Type);
			 Method->Items->Add(Type);
			 if (SameText(Type, L"Carbon-14")) {
			   int nMethods;
			   if (xmlin->ValidChild(XPath, L"Methods", nMethods)) {
				 XPath1 = XPath + L"/Methods/Method";
				 XMLSubElement Method(XPath1);
				 int ID;
				 UnicodeString Category;
				 for (int j=1; j<=nMethods; j++) {
				   XPath2 = Method.XPath(j);
				   xmlin->GetAttrInt(XPath2, L"ID", ID);
				   xmlin->GetTextValue(XPath2, Category);
				   RadiocarbonParams[0].Categories[ID] = Category;
				   }
				 }
			   }
			 GeochronTypes.push_back(Type);
			 }
		   }
		 else {
           for (int i=0; i<count; i++) {
			 if (xmlin->GetChildText(i, utext))
			   Method->Items->Add(utext);
			 }
		   }
		 }
	   }

	 // Fraction dated
	 if (version >= 4) {
	   TcxComboBoxProperties* Fractions = (TcxComboBoxProperties*)(txFraction->Properties);
	   if (xmlin->ValidChild(L"/TiliaLookup/", L"FractionDated", count)) {
		 if (count > 0) {
		   for (int i=0; i<count; i++) {
			 if (xmlin->GetChildText(i, utext))
			   Fractions->Items->Add(utext);
			 }
		   }
		 }
	   }

	 // Chronology control lookup items
	 if (xmlin->ValidChild(L"/TiliaLookup/", L"ChronologyControls", count)) {
	   if (count > 0) {
		 TREENODE ChronControl;
		 vector<TREENODE> ChronControls;
		 XMLSubElement ChronControlType(L"/TiliaLookup/ChronologyControls/ChronControlType");
		 for (int i=1; i<=count; i++) {
		   XPath = ChronControlType.XPath(i);
		   xmlin->GetAttrInt(XPath, L"ID", ChronControl.ID);
		   xmlin->GetIntValue(XPath, L"HigherID", ChronControl.HigherID);
		   xmlin->GetTextValue(XPath, L"Name", ChronControl.Name);
		   ChronControls.push_back(ChronControl);
		   }
		 BuildTree(ChronControls, cxTreeView1);
		 cxTreeView1->AlphaSort();
		 // lookup items

		 TcxPopupEditProperties* AgeBasisProperties = (TcxPopupEditProperties*)(chAgeBasis->Properties);
		 for (int i=0; i<cxTreeView1->Items->Count; i++) {
		   TTreeNode *Node = cxTreeView1->Items->Item[i];
		   AgeBasisProperties->LookupItems->Add(Node->Text);
		   }
		 }
	   }

	 // Events
	 if (xmlin->ValidChild(L"/TiliaLookup/", L"Events", count)) {
	   if (count > 0) {
		 XMLEVENT xmlEvent;
		 TTreeNode *EventNode;
		 XMLSubElement EventType(L"/TiliaLookup/Events/");
		 bool AlphaSort = false;
		 for (int i=1; i<=count; i++) {
		   XPath = EventType.XPath(i);
		   xmlEvent.EventType = xmlin->GetElementName(XPath);     // e.g. Tephras
		   xmlin->GetAttrStr(XPath, L"ChronologyControl", xmlEvent.ChronControl);    // e.g. Tephra
		   xmlin->GetAttrStr(XPath, L"Sort", xmlEvent.SortType);  // e.g. Name
		   XMLSubElement Events(L"/TiliaLookup/Events/" + xmlEvent.EventType + L"/");
		   if (xmlin->XChildrenCount() > 0) {
			 XPath1 = Events.XPath(1);
			 xmlEvent.EventName = xmlin->GetElementName(XPath1);     // e.g. Tephra
			 xmlEventTypes.push_back(xmlEvent);   // list of Event Types
			 bool found = false;
			 // the event classes (e.g. Tephra, Geomagnetic polarity reversal) will
			 // be found in this loop if they are stored as ChronControls. This is
			 // true for lookup files generated from Neotoma
			 for (int k=0; k<cxTreeView1->Items->Count; k++) {
			   EventNode = cxTreeView1->Items->Item[k];
			   if (SameText(EventNode->Text, xmlEvent.ChronControl)) {
				 found = true;
				 if (!GetLookupEvents(xmlin, EventNode, xmlEvent, Events, version)) return false;
				 break;
				 }
			   }
			 // the event classes will be found in this loop if they are not stored
			 // as ChronControls. This is true for lookup files written by Tilia.
			 if (!found) {  // add Event node
			   TTreeNode *Node;
			   TcxPopupEditProperties* AgeBasisProperties = (TcxPopupEditProperties*)(chAgeBasis->Properties);
			   for (int k=0; k<cxTreeView1->Items->Count; k++) {
				 Node = cxTreeView1->Items->Item[k];
				 if (SameText(Node->Text, L"Event stratigraphic")) {
				   EventNode = cxTreeView1->Items->AddChild(Node, xmlEvent.ChronControl);
				   if (!GetLookupEvents(xmlin, EventNode, xmlEvent, Events, version)) return false;
				   AgeBasisProperties->LookupItems->Add(EventNode->Text);
				   AlphaSort = true;
				   break;
				   }
				 }
			   }
		     }
		   }
		 if (AlphaSort)
		   cxTreeView1->AlphaSort();
		 }
	   }

	 // Relative Age Scales
	 if (xmlin->ValidChild(L"/TiliaLookup/", L"RelativeAgeScales", count)) {
	   int nscales = count;
	   if (nscales > 0) {
		 UnicodeString ScaleName;
		 XMLSubElement RelativeAgeScale(L"/TiliaLookup/RelativeAgeScales/RelativeAgeScale");
		 for (int i=1; i<=nscales; i++) {
		   // these are e.g. North American archaeological time scale, Geologic time scale
		   XPath = RelativeAgeScale.XPath(i);
		   xmlin->GetAttrStr(XPath, L"Name", ScaleName);
		   bool ArchTimeScale = ContainsText(ScaleName, L"archaeological time scale");
		   int ItemCount = cxTreeView1->Items->Count;
		   for (int k=0; k<ItemCount; k++) {
			 TTreeNode *Node = cxTreeView1->Items->Item[k];
			 if (SameText(Node->Text, ScaleName)) {
			   XMLSubElement RelativeAge(XPath + L"/RelativeAge");
			   int count = xmlin->XChildrenCount();

			   for (int j=1; j<=count; j++) {
				 XPath1 = RelativeAge.XPath(j);
				 UnicodeString Name;
				 if (version >= 4)
				   xmlin->GetTextValue(XPath1, L"Name", Name);
				 else
				   xmlin->GetAttrStr(XPath1, L"Name", Name);
				 RELATIVEAGE *RelativeAgeValues = new RELATIVEAGE();
				 if (xmlin->GetDoubleValue(XPath1, L"C14AgeYounger", dValue))
				   RelativeAgeValues->C14AgeYounger = (int)dValue;
				 if (xmlin->GetDoubleValue(XPath1, L"C14AgeOlder", dValue))
				   RelativeAgeValues->C14AgeOlder = (int)dValue;
				 if (xmlin->GetDoubleValue(XPath1, L"CalAgeYounger", dValue))
				   RelativeAgeValues->CalAgeYounger = (int)dValue;
				 if (xmlin->GetDoubleValue(XPath1, L"CalAgeOlder", dValue))
				   RelativeAgeValues->CalAgeOlder = (int)dValue;
				 if (RelativeAgeValues->AgesSet()) {
				   if (ArchTimeScale) {
					 int ID;
					 if ((ID = ArchAgeScales->IndexOf(ScaleName)) == -1)
					   ID = ArchAgeScales->Add(ScaleName);
					 RelativeAgeValues->ArchAgeScaleID = ID;
					 ArchAges->AddObject(Name, (TObject*)RelativeAgeValues);
					 }
				   else  {
					 cxTreeView1->Items->AddChildObject(Node, Name, RelativeAgeValues);
					 //AgeBasisProperties->LookupItems->Add(Node->Text);   // new
					 }
				   RelativeAges->Add(RelativeAgeValues);  // list of pointers for eventual deleting
				   }
				 else {
				   delete RelativeAgeValues;
				   if (ArchTimeScale) {
					 RELATIVEAGE *RelativeAgeValues = new RELATIVEAGE();
					 int ID;
					 if ((ID = ArchAgeScales->IndexOf(ScaleName)) == -1)
					   ID = ArchAgeScales->Add(ScaleName);
					 RelativeAgeValues->ArchAgeScaleID = ID;
					 ArchAges->AddObject(Name, (TObject*)RelativeAgeValues);
					 RelativeAges->Add(RelativeAgeValues);
					 }
				   else {
					 cxTreeView1->Items->AddChild(Node, Name);
                     //AgeBasisProperties->LookupItems->Add(Node->Text);  // new
					 }
				   }
				 }
			   break;
			   }
			 }
		   }
		 if (ArchAges->Count)
			ArchAges->Sort();
		 }
	   }

	 // Calibration Curves
	 if (version >= 4) {
	   TcxComboBoxProperties* CalibCurves = (TcxComboBoxProperties*)(chCalibCurve->Properties);
	   TcxComboBoxProperties* GeochronCalibCurves = (TcxComboBoxProperties*)(txCalibCurve->Properties);
	   if (xmlin->ValidChild(L"/TiliaLookup/", L"CalibrationCurves", count)) {
		 if (count > 0) {
		   for (int i=0; i<count; i++) {
			 if (xmlin->GetChildText(i, utext)) {
			   CalibCurves->Items->Add(utext);
			   GeochronCalibCurves->Items->Add(utext);
			   }
			 }
		   }
		 }

	   // Calibration Programs
	   map<UnicodeString, pair<UnicodeString,UnicodeString> > calibprogs;
	   UnicodeString calibprog, prog, version;
	   if (xmlin->ValidChild(L"/TiliaLookup/", L"CalibrationPrograms", count)) {
		 if (count > 0) {
		   AdvColumnGrid9->RowCount = count + 1;
		   Panel10->Width = 180;
		   XMLSubElement CalibProg(L"/TiliaLookup/CalibrationPrograms/CalibrationProgram");
		   for (int i=1; i<=count; i++) {
			 XPath = CalibProg.XPath(i);
			 xmlin->GetTextValue(XPath, L"Name", prog);
			 xmlin->GetTextValue(XPath, L"Version", version);
			 calibprog = prog + L" " + version;
			 calibprogs[calibprog] = pair<UnicodeString,UnicodeString>(prog,version);
			 }
		   map<UnicodeString, pair<UnicodeString,UnicodeString> >::iterator itr;
		   int i = 1;
		   for (itr = calibprogs.begin(); itr != calibprogs.end(); itr++) {
			 AdvColumnGrid9->Cells[0][i] = itr->second.first;
			 AdvColumnGrid9->Cells[1][i++] = itr->second.second;
		     }
		   }
		 }
	   }

	 if (version >= 7) {
	   if (xmlin->ValidChild(L"/TiliaLookup/", L"IsoMaterialsAnalyzed", count)) {
		 if (count > 0) {
		   XMLSubElement MatAnal(L"/TiliaLookup/IsoMaterialsAnalyzed/IsoMaterialAnalyzed");
		   UnicodeString IsoMaterial;
		   UnicodeString IsoSubstrate;
		   for (int i=1; i<=count; i++) {
			 XPath = MatAnal.XPath(i);
			 xmlin->GetTextValue(XPath, L"IsoMaterial", IsoMaterial);
			 xmlin->GetTextValue(XPath, L"IsoSubstrate", IsoSubstrate);
			 IsoMaterialsAnalyzed.insert(IsoMaterial);
			 IsoSubstrates.insert(pair<UnicodeString,UnicodeString>(IsoMaterial,IsoSubstrate));
			 }
		   }
		 }

	   if (xmlin->ValidChild(L"/TiliaLookup/", L"IsoPretreatments", count)) {
		 if (count > 0) {
		   XMLSubElement Pretreatment(L"/TiliaLookup/IsoPretreatments/IsoPretreatment");
		   UnicodeString type;
		   UnicodeString qualifier;
		   for (int i=1; i<=count; i++) {
			 XPath = Pretreatment.XPath(i);
			 xmlin->GetTextValue(XPath, L"IsoPretreatmentType", type);
			 xmlin->GetTextValue(XPath, L"IsoPretreatmentQualifier", qualifier);
			 IsoPretreatments.insert(pair<UnicodeString,UnicodeString>(type,qualifier));
			 }
		   }
		 }

	   if (xmlin->ValidChild(L"/TiliaLookup/", L"IsoSamplingOrigins", count)) {
		 if (count > 0) {
		   for (int i=0; i<count; i++) {
			 if (xmlin->GetChildText(i, utext))
			   IsoSamplingOrigins.insert(utext);
			 }
		   }
		 }

	   if (xmlin->ValidChild(L"/TiliaLookup/", L"IsoBioMarkers", count)) {
		 if (count > 0) {
		   XMLSubElement BioMarker(L"/TiliaLookup/IsoBioMarkers/IsoBioMarker");
		   UnicodeString type;
		   UnicodeString band;
		   for (int i=1; i<=count; i++) {
			 XPath = BioMarker.XPath(i);
			 xmlin->GetTextValue(XPath, L"IsoBioMarkerType", type);
			 xmlin->GetTextValue(XPath, L"IsoBioMarkerBandType", band);
			 IsoBioMarkers.insert(pair<UnicodeString,UnicodeString>(type,band));
			 }
		   }
		 }

	   if (xmlin->ValidChild(L"/TiliaLookup/", L"IsoInstrumentation", count)) {
		 if (count > 0) {
		   for (int i=0; i<count; i++) {
			 if (xmlin->GetChildText(i, utext))
			   IsoInstrumentation.insert(utext);
			 }
		   }
		 }

	   if (xmlin->ValidChild(L"/TiliaLookup/", L"IsoSampleIntroSystems", count)) {
		 if (count > 0) {
		   for (int i=0; i<count; i++) {
			 if (xmlin->GetChildText(i, utext))
			   IsoSampleIntroSystems.insert(utext);
			 }
		   }
		 }

	   if (xmlin->ValidChild(L"/TiliaLookup/", L"IsoStandards", count)) {
		 if (count > 0) {
		   XMLSubElement IsoStandard(L"/TiliaLookup/IsoStandards/IsoStandard");
		   UnicodeString name;
		   UnicodeString material;
		   for (int i=1; i<=count; i++) {
			 XPath = IsoStandard.XPath(i);
			 xmlin->GetTextValue(XPath, L"IsoStandardName", name);
			 xmlin->GetTextValue(XPath, L"IsoStandardMaterial", material);
			 IsoStandards[name] = material;
			 }
		   }
		 }                                                             // IsoVariableScales

	   // if (xmlin->ValidChild(L"/TiliaLookup/", L"IsoTypeVariables", count)) [
	   if (xmlin->ValidChild(L"/TiliaLookup/", L"IsoVariableScales", count)) {
		 if (count > 0) {
		   //XMLSubElement IsoType(L"/TiliaLookup/IsoTypeVariables/IsoTypeVariable");
		   XMLSubElement IsoType(L"/TiliaLookup/IsoVariableScales/IsoVariableScale");
		   UnicodeString type;
		   UnicodeString scale;
		   for (int i=1; i<=count; i++) {
			 XPath = IsoType.XPath(i);
			 xmlin->GetTextValue(XPath, L"IsoVariable", type);
			 xmlin->GetTextValue(XPath, L"IsoScale", scale);
			 IsoTypeVariables.insert(pair<UnicodeString,UnicodeString>(type,scale));
			 }
		   }
		 }

	   if (xmlin->ValidChild(L"/TiliaLookup/", L"SpecimenSex", count)) {
		 if (count > 0) {
		   for (int i=0; i<count; i++) {
			 if (xmlin->GetChildText(i, utext))
			   SpecimenSex.insert(utext);
			 }
		   }
		 }

	   if (xmlin->ValidChild(L"/TiliaLookup/", L"SpecimenDomesticStatus", count)) {
		 if (count > 0) {
		   for (int i=0; i<count; i++) {
			 if (xmlin->GetChildText(i, utext))
			   DomesticStatus.insert(utext);
			 }
		   }
		 }

	   }
	 }
   catch (Exception &e) {
	 MessageDlg(e.Message, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 rv = false;
	 }
   }
   __finally
	 {
	 delete xmlin;
	 }
   return rv;
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::BuilddxTreeViewEdit(vector<TREENODE>& Nodes, TdxTreeViewEdit* dxTreeViewEdit)
{
   int count = Nodes.size();
   vector<int> idx(count, 0);

   dxTreeViewEdit->Items->BeginUpdate();
   // first pass
   for (int i=0; i<count; i++) {
	 if (Nodes[i].ID == Nodes[i].HigherID) {
	   dxTreeViewEdit->Items->Add(NULL, Nodes[i].Name);
	   idx[i] = 1;
	   }
	 }

   int level = 1;
   bool NewAdded = true;
   TTreeNode *Node;

   while (dxTreeViewEdit->Items->Count < count && NewAdded) {
	 NewAdded = false;
	 for (int i=0; i<count; i++) {
	   if (idx[i] == level) {
		 for (int k=0; k<dxTreeViewEdit->Items->Count; k++) {
		   Node = dxTreeViewEdit->Items->Item[k];
		   if (SameText(Node->Text, Nodes[i].Name))
			 break;
		   }
		 for (int k=count-1; k>=0; k--) {
		   if (Nodes[k].HigherID == Nodes[i].ID && Nodes[k].HigherID != Nodes[k].ID) {
			 dxTreeViewEdit->Items->AddChild(Node, Nodes[k].Name);
			 idx[k] = level + 1;
			 NewAdded = true;
			 }
		   }
		 }
	   }
	 level++;
	 }
   dxTreeViewEdit->Items->EndUpdate();
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::BuilddxTree(vector<TREENODE>& Nodes, TdxTreeView* dxTreeView)
{
   int count = Nodes.size();
   vector<int> idx(count, 0);

   dxTreeView->Items->BeginUpdate();
   // first pass
   for (int i=0; i<count; i++) {
	 if (Nodes[i].ID == Nodes[i].HigherID) {
	   dxTreeView->Items->Add(NULL, Nodes[i].Name);
	   idx[i] = 1;
	   }
	 }

   int level = 1;
   bool NewAdded = true;
   TTreeNode *Node;

   while (dxTreeView->Items->Count < count && NewAdded) {
	 NewAdded = false;
	 for (int i=0; i<count; i++) {
	   if (idx[i] == level) {
		 for (int k=0; k<dxTreeView->Items->Count; k++) {
		   Node = dxTreeView->Items->Item[k];
		   if (SameText(Node->Text, Nodes[i].Name))
			 break;
		   }
		 for (int k=count-1; k>=0; k--) {
		   if (Nodes[k].HigherID == Nodes[i].ID && Nodes[k].HigherID != Nodes[k].ID) {
			 dxTreeView->Items->AddChild(Node, Nodes[k].Name);
			 idx[k] = level + 1;
			 NewAdded = true;
			 }
		   }
		 }
	   }
	 level++;
	 }
   dxTreeView->Items->EndUpdate();
}
//---------------------------------------------------------------------------

// builds cxTreeView with vector of nodes with ID and HigherID
void TTilSpreadSheetForm::BuildTree(vector<TREENODE>& Nodes, TcxTreeView* cxTreeView)
{
   int count = Nodes.size();
   vector<int> idx(count, 0);

   cxTreeView->Items->BeginUpdate();
   // first pass
   for (int i=0; i<count; i++) {
	 if (Nodes[i].ID == Nodes[i].HigherID) {
	   cxTreeView->Items->Add(NULL, Nodes[i].Name);
	   idx[i] = 1;
	   }
	 }

   int level = 1;
   bool NewAdded = true;
   TTreeNode *Node;

   while (cxTreeView->Items->Count < count && NewAdded) {
	 NewAdded = false;
	 for (int i=0; i<count; i++) {
	   if (idx[i] == level) {
		 for (int k=0; k<cxTreeView->Items->Count; k++) {
		   Node = cxTreeView->Items->Item[k];
		   if (SameText(Node->Text, Nodes[i].Name))
			 break;
		   }
		 for (int k=count-1; k>=0; k--) {
		   if (Nodes[k].HigherID == Nodes[i].ID && Nodes[k].HigherID != Nodes[k].ID) {
			 cxTreeView->Items->AddChild(Node, Nodes[k].Name);
			 idx[k] = level + 1;
			 NewAdded = true;
			 }
		   }
		 }
	   }
	 level++;
	 }
   cxTreeView->Items->EndUpdate();
}
//---------------------------------------------------------------------------

bool TTilSpreadSheetForm::GetLookupEvents(ParseXMLUnicode* xmlin, TTreeNode *EventNode,
	 XMLEVENT& xmlEvent, XMLSubElement& xmlEvents, int version)
{
   bool success = false;
   double dValue;
   int count;
   UTF8String XPath;
   TList *NewEvents = new TList;
   UnicodeString ustr;

   try {
	   try {
		   xmlin->ValidChild(L"/TiliaLookup/Events/", xmlEvent.EventType, count);
		   for (int i=1; i<=count; i++) {
			 EVENT *Event = new EVENT();
			 XPath = xmlEvents.XPath(i);
			 if (version >= 4)
			   xmlin->GetTextValue(XPath, L"Name", Event->Name);
			 else
			   xmlin->GetAttrStr(XPath, L"Name", Event->Name);  // e.g. Name
			 if (xmlin->GetDoubleValue(XPath, L"C14Age", dValue))
			   Event->C14Age = (int)dValue;
			 if (xmlin->GetDoubleValue(XPath, L"C14AgeYounger", dValue))
			   Event->C14AgeYounger = (int)dValue;
			 if (xmlin->GetDoubleValue(XPath, L"C14AgeOlder", dValue))
			   Event->C14AgeOlder = (int)dValue;
			 if (xmlin->GetDoubleValue(XPath, L"CalAge", dValue))
			   Event->CalAge = (int)dValue;
			 if (xmlin->GetDoubleValue(XPath, L"CalAgeYounger", dValue))
			   Event->CalAgeYounger = (int)dValue;
			 if (xmlin->GetDoubleValue(XPath, L"CalAgeOlder", dValue))
			   Event->CalAgeOlder = (int)dValue;
			 //xmlin->GetTextValue(XPath, L"Name", Event->Name);

			 xmlin->GetTextValue(XPath, L"Notes", ustr);
			 Event->Notes = ustr;

			 NewEvents->Add(Event);
			 }
		   if (NewEvents->Count > 1) {
			 if (SameText(xmlEvent.SortType, L"Name"))
			   NewEvents->Sort(EventNameCompare);
			 else if (SameText(xmlEvent.SortType, L"CalAge"))
			   NewEvents->Sort(EventCalAgeCompare);
			 }
		   for (int i=0; i<NewEvents->Count; i++) {
			 EVENT* Event = (EVENT*)NewEvents->Items[i];
			 Events->Add(Event);
			 cxTreeView1->Items->AddChildObject(EventNode, Event->Name, Event);
			 }
		   success = true;
		   }
	   catch (Exception &e) {
		   MessageDlg(e.Message, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   }
	   }
   __finally
	   {
	   delete NewEvents;
	   }

   return success;
}
//---------------------------------------------------------------------------

UnicodeString TTilSpreadSheetForm::SaveLookupFile(void)
{
   UnicodeString ReturnString;
   UnicodeString LookupVersion(L"6");
   int count;

   UnicodeString LookupFileName = tiGlobals->AppDataTiliaLookupPath;
   LookupFileName += L"Lookup.xml";

   WriteXML *xmlout = new WriteXML(LookupFileName);
   Screen->Cursor = crHourGlass;

   try {
   try {
	xmlout->Declaration(L"1.0", L"UTF-8", L"yes");
	xmlout->DateTime();
	xmlout->BeginTag(L"TiliaLookup");
	xmlout->Element(L"Version", LookupVersion);

	// DatasetTypes
	if (DataTypes.size() > 0) {
	  xmlout->BeginTag(L"DatasetTypes");
	  set<UnicodeString>::iterator itr;
	  for (itr = DataTypes.begin(); itr != DataTypes.end(); itr++)
		xmlout->Element(L"DatasetType", *itr);
	  xmlout->EndTag(L"DatasetTypes");
	  }
	else
	  xmlout->EmptyElement(L"DatasetTypes");

	if (LakeChar.size() > 0) {
	  xmlout->BeginTag(L"LakeParameters");
	  list<LAKEPARAMETER>::iterator itr = LakeChar.begin();
	  while (itr != LakeChar.end()) {
		xmlout->BeginTag(L"LakeParameter");
		xmlout->Element(L"Code", (*itr).Code);
		xmlout->Element(L"Name", (*itr).Name);
		xmlout->Element(L"Menu", (*itr).Menu);
		xmlout->EndTag(L"LakeParameter");
		itr++;
		}
	  xmlout->EndTag(L"LakeParameters");
	  }
	else
	  xmlout->EmptyElement(L"LakeParameters");

	if (cxComboBox1->Properties->Items->Count > 0) {
	  xmlout->BeginTag(L"CollectionTypes");
	  for (int i=0; i<cxComboBox1->Properties->Items->Count; i++)
		xmlout->Element(L"CollectionType", cxComboBox1->Properties->Items->Strings[i]);
	  xmlout->EndTag(L"CollectionTypes");
	  }
	else
	  xmlout->EmptyElement(L"CollectionTypes");

	// DepositionalEnvironments
	count = dxTreeViewEdit1->Items->Count;
	if (count > 0) {
	  int HigherID;
	  xmlout->BeginTag(L"DepositionalEnvironments");
	  for (int i=0; i<count; i++) {
		xmlout->BeginTag(L"Context", L"ID", i+1);
		TTreeNode* Node = dxTreeViewEdit1->Items->Item[i];
		xmlout->Element(L"Name", Node->Text);
		if (Node->Level == 0)
		  HigherID = i+1;
		else
		  HigherID = Node->Parent->AbsoluteIndex + 1;
		xmlout->Element(L"HigherID", HigherID);
		xmlout->EndTag(L"Context");
		}
	  xmlout->EndTag(L"DepositionalEnvironments");
	  }
	else
	  xmlout->EmptyElement(L"DepositionalEnvironments");

	// Substrates
	count = dxTreeViewEdit2->Items->Count;
	if (count > 0) {
	  xmlout->BeginTag(L"Substrates");
	  int HigherID;
	  for (int i=0; i<count; i++) {
		xmlout->BeginTag(L"Substrate", L"ID", i+1);
		TTreeNode* Node = dxTreeViewEdit2->Items->Item[i];
		xmlout->Element(L"RockType", Node->Text);
		if (Node->Level == 0)
		  HigherID = i+1;
		else
		  HigherID = Node->Parent->AbsoluteIndex + 1;
		xmlout->Element(L"HigherID", HigherID);
		UnicodeString Description = (wchar_t*)(Node->Data);
		xmlout->Element(L"Description", Description);
		xmlout->EndTag(L"Substrate");
		}
	  xmlout->EndTag(L"Substrates");
	  }
	else
	  xmlout->EmptyElement(L"Substrates");

	// Facies
	if (FaciesTypes.size() > 0) {
	  xmlout->BeginTag(L"Facies");
	  for (unsigned int i=0; i<FaciesTypes.size(); i++)
		xmlout->Element(L"FaciesType", FaciesTypes[i]);
	  xmlout->EndTag(L"Facies");
	  }
	else
	  xmlout->EmptyElement(L"Facies");

	// Depositional agents
	if (DepAgents.size() > 0) {
	  xmlout->BeginTag(L"DepAgents");
	  for (unsigned int i=0; i<DepAgents.size(); i++)
		xmlout->Element(L"DepAgent", DepAgents[i]);
	  xmlout->EndTag(L"DepAgents");
	  }
	else
	  xmlout->EmptyElement(L"DepAgents");

	// AgeTypes
	if (AgeUnits.size() > 0) {
	  xmlout->BeginTag(L"AgeTypes");
	  map<UnicodeString, UnicodeString>::iterator itr = AgeUnits.begin();
	  while (itr != AgeUnits.end()) {
		xmlout->BeginTag(L"AgeType");
		xmlout->Element(L"LongName", (*itr).first);
		xmlout->Element(L"ShortName", (*itr).second);
		xmlout->EndTag(L"AgeType");
		itr++;
		}
	  xmlout->EndTag(L"AgeTypes");
	  }
	else
	  xmlout->EmptyElement(L"AgeTypes");

	// aggregate dataset sample order
	if (cxComboBox14->Properties->Items->Count > 0) {
	  xmlout->BeginTag(L"AggregateOrderTypes");
	  for (int i=0; i<cxComboBox14->Properties->Items->Count; i++)
		xmlout->Element(L"AggregateOrderType", cxComboBox14->Properties->Items->Strings[i]);
	  xmlout->EndTag(L"AggregateOrderTypes");
	  }
	else
	  xmlout->EmptyElement(L"AggregateOrderTypes");

	//Repositories
	if (AdvColumnGrid2->RowCount > 1) {
	  xmlout->BeginTag(L"Repositories");
	  for (int row=1; row<AdvColumnGrid2->RowCount; row++) {
		xmlout->BeginTag(L"Repository");
		xmlout->Element(L"Acronym", AdvColumnGrid2->Cells[1][row]);
		xmlout->Element(L"Institution", AdvColumnGrid2->Cells[2][row]);
		xmlout->Element(L"Notes", AdvColumnGrid2->Cells[3][row]);
		xmlout->EndTag(L"Repository");
		}
	  xmlout->EndTag(L"Repositories");
	  }
	else
	  xmlout->EmptyElement(L"Repositories");

	//GeochronTypes
	if (GeochronTypes.size() > 0) {
	  xmlout->BeginTag(L"GeochronTypes");
	  for (unsigned int i=0; i<GeochronTypes.size(); i++) {
		xmlout->BeginTag(L"GeochronType");
		xmlout->Element(L"Type", GeochronTypes[i]);
		if (SameText(GeochronTypes[i], L"Carbon-14")) {
		  xmlout->BeginTag(L"Methods");
		  map<int,UnicodeString>::iterator itr;
		  for (itr = RadiocarbonParams[0].Categories.begin(); itr != RadiocarbonParams[0].Categories.end(); itr++)
			xmlout->Element(L"Method", L"ID", itr->first, itr->second);
		  xmlout->EndTag(L"Methods");
		  }

		xmlout->EndTag(L"GeochronType");
		}
	  xmlout->EndTag(L"GeochronTypes");
	  }
	else
	  xmlout->EmptyElement(L"GeochronTypes");

	// FractionDated
	TcxComboBoxProperties* Fractions = (TcxComboBoxProperties*)(txFraction->Properties);
	if (Fractions->Items->Count) {
	  xmlout->BeginTag(L"FractionDated");
	  for (int i=0; i<Fractions->Items->Count; i++)
		xmlout->Element(L"Fraction", Fractions->Items->Strings[i]);
	  xmlout->EndTag(L"FractionDated");
	  }
	else
	  xmlout->EmptyElement(L"FractionDated");

	// ChronologyControls
	if (cxAgeBasisTreeView->Items->Count) {
	  xmlout->BeginTag(L"ChronologyControls");
	  for (int i=0; i<cxAgeBasisTreeView->Items->Count; i++) {
		TTreeNode* Node = cxAgeBasisTreeView->Items->Item[i];
		// skip Event nodes that are not an event type
		bool IsEventNode = IsEventAge(Node);
		if (!IsRelativeAge(Node) && !IsEventNode) {
		  int ID = Node->AbsoluteIndex;
		  xmlout->BeginTag(L"ChronControlType", L"ID", ID+1);
		  xmlout->Element(L"Name", Node->Text);
		  int HigherID = (Node->Level > 0) ? Node->Parent->AbsoluteIndex : ID;
		  xmlout->Element(L"HigherID", HigherID+1);
		  xmlout->EndTag(L"ChronControlType");
		  }
		}
	  xmlout->EndTag(L"ChronologyControls");
	  }
	else
	  xmlout->EmptyElement(L"ChronologyControls");

	int size = xmlEventTypes.size();
	if (size > 0) {   // then events exist
	  xmlout->BeginTag(L"Events");
	  for (int i=0; i<size; i++) {
		xmlout->BeginTag(xmlEventTypes[i].EventType, L"ChronologyControl",
		   xmlEventTypes[i].ChronControl, L"Sort", xmlEventTypes[i].SortType);

		TTreeNode* EventNode =  NULL;
		UnicodeString EventName = xmlEventTypes[i].EventName;
		UnicodeString ChronControl = xmlEventTypes[i].ChronControl;
		for (int j=0; j<cxAgeBasisTreeView->Items->Count; j++) {
		  TTreeNode* Node = cxAgeBasisTreeView->Items->Item[j];
		  if (SameText(Node->Text, ChronControl)) {
			EventNode = Node;
			break;
			}
		  }

		if (EventNode) {
		  TTreeNode* ChildNode = EventNode->getFirstChild();
		  if (ChildNode) {
			EVENT* Event = (EVENT*)ChildNode->Data;
			//if (Event != NULL) {   // new: this doesn't work
			  xmlout->BeginTag(L"EventName");
			  xmlout->Element(L"Name", ChildNode->Text);
			  if (Event->AgesSet())   // test if Event == NULL?
				Event->XMLOut(xmlout);
			  xmlout->EndTag(L"EventName");
			  while ((ChildNode = EventNode->GetNextChild(ChildNode)) != NULL) {
				EVENT* Event = (EVENT*)ChildNode->Data;
				xmlout->BeginTag(L"EventName");
				xmlout->Element(L"Name", ChildNode->Text);
				if (Event->AgesSet())
				  Event->XMLOut(xmlout);
				xmlout->EndTag(L"EventName");
				}
			//  }
			}
		  }
		xmlout->EndTag(xmlEventTypes[i].EventType);
		}
	  xmlout->EndTag(L"Events");
	  }
	else
	  xmlout->EmptyElement(L"Events");

	// RelativeAgeScales
	TTreeNode* RelTimeNode =  NULL;
	for (int i=0; i<cxAgeBasisTreeView->Items->Count; i++) {
	  TTreeNode* Node = cxAgeBasisTreeView->Items->Item[i];
	  if (SameText(Node->Text, L"Relative time scale")) {
		RelTimeNode = Node;
		break;
		}
	  }

	if (RelTimeNode) {
	  xmlout->BeginTag(L"RelativeAgeScales");
	  TTreeNode* ChildNode = RelTimeNode->getFirstChild();
	  if (ChildNode) {
		xmlout->BeginTag(L"RelativeAgeScale", L"Name", ChildNode->Text);
		TTreeNode* ChildNode2 = ChildNode->getFirstChild();
		if (ChildNode2) {
		  RELATIVEAGE* RelAge = (RELATIVEAGE*)ChildNode2->Data;
		  xmlout->BeginTag(L"RelativeAge");
		  xmlout->Element(L"Name", ChildNode2->Text);
		  if (RelAge->AgesSet())
			RelAge->XMLOut(xmlout);
		  xmlout->EndTag(L"RelativeAge");
		  while ((ChildNode2 = ChildNode->GetNextChild(ChildNode2)) != NULL) {
			RELATIVEAGE* RelAge = (RELATIVEAGE*)ChildNode2->Data;
			xmlout->BeginTag(L"RelativeAge");
			xmlout->Element(L"Name", ChildNode2->Text);
			if (RelAge->AgesSet())
			  RelAge->XMLOut(xmlout);
			xmlout->EndTag(L"RelativeAge");
			}
		  }
		xmlout->EndTag(L"RelativeAgeScale");

		while ((ChildNode = RelTimeNode->GetNextChild(ChildNode)) != NULL) {
		  xmlout->BeginTag(L"RelativeAgeScale", L"Name", ChildNode->Text);
		  ChildNode2 = ChildNode->getFirstChild();
		  if (ChildNode2) {
			RELATIVEAGE* RelAge = (RELATIVEAGE*)ChildNode2->Data;
			xmlout->BeginTag(L"RelativeAge");
			xmlout->Element(L"Name", ChildNode2->Text);
			if (RelAge->AgesSet())
			  RelAge->XMLOut(xmlout);
			xmlout->EndTag(L"RelativeAge");
			while ((ChildNode2 = ChildNode->GetNextChild(ChildNode2)) != NULL) {
			  RelAge = (RELATIVEAGE*)ChildNode2->Data;
			  xmlout->BeginTag(L"RelativeAge");
			  xmlout->Element(L"Name", ChildNode2->Text);
			  if (RelAge->AgesSet())
				RelAge->XMLOut(xmlout);
			  xmlout->EndTag(L"RelativeAge");
			  }
			}
		  else if (ContainsText(ChildNode->Text, L"archaeological time scale")) {
			for (int i=0; i<ArchAges->Count; i++) {
			  RELATIVEAGE* ArchAge = (RELATIVEAGE*)ArchAges->Objects[i];
			  xmlout->BeginTag(L"RelativeAge");
			  xmlout->Element(L"Name", ArchAges->Strings[i]);
			  if (ArchAge->AgesSet())
				ArchAge->XMLOut(xmlout);
			  xmlout->EndTag(L"RelativeAge");
			  }
			}
		  xmlout->EndTag(L"RelativeAgeScale");
		  }
		}
	  xmlout->EndTag(L"RelativeAgeScales");
	  }
	else
	  xmlout->EmptyElement(L"RelativeAgeScales");

	// Calibration curves
	TcxComboBoxProperties* CalibCurves = (TcxComboBoxProperties*)(chCalibCurve->Properties);
	if (CalibCurves->Items->Count) {
	  xmlout->BeginTag(L"CalibrationCurves");
	  for (int i=0; i<CalibCurves->Items->Count; i++)
		xmlout->Element(L"CalibrationCurve", CalibCurves->Items->Strings[i]);
	  xmlout->EndTag(L"CalibrationCurves");
	  }
	else
	  xmlout->EmptyElement(L"CalibrationCurves");

	// Calibration programs
	if (AdvColumnGrid9->RowCount > 1) {
	  xmlout->BeginTag(L"CalibrationPrograms");
	  for (int i=1; i<AdvColumnGrid9->RowCount; i++) {
		xmlout->BeginTag(L"CalibrationProgram");
		xmlout->Element(L"Name", AdvColumnGrid9->Cells[0][i]);
		xmlout->Element(L"Version", AdvColumnGrid9->Cells[1][i]);
		xmlout->EndTag(L"CalibrationProgram");
		}
	  xmlout->EndTag(L"CalibrationPrograms");
	  }
	else
	  xmlout->EmptyElement(L"CalibrationPrograms");

	xmlout->EndTag(L"TiliaLookup");
	xmlout->Finish();
	ReturnString = LookupFileName;
	}
   catch(Exception &e)
	{
	MessageDlg(e.Message, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	}
  }
   __finally
	{
	delete xmlout;
	Screen->Cursor = crDefault;
	}
  return ReturnString;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::ipwXMLp5StartElement(TObject *Sender,
	  TipwXMLpStartElementEventParams *e)
{
   gpx->XText.SetLength(0);
   UnicodeString Element = e->Element.w_str();

   if (SameText(Element, L"GeoPolitical")) {
	 GeoPolRec = new GEOPOLRECORD;
	 GeoPolRec->ID = ipwXMLp5->Attr(L"ID").ToInt();
	 //XMLParsingStatus(L"ID = " + IntToStr(GeoPolRec->ID));
	 gpx->GeoPolitical = true;
	 }
   else if (SameText(Element, L"GeoPoliticalUnit"))
	 gpx->GeoPoliticalUnit = true;
   else if (SameText(Element, L"GeoPoliticalName"))
	 gpx->GeoPoliticalName = true;
   else if (SameText(Element, L"Rank"))
	 gpx->Rank = true;
   else if (SameText(Element, L"HigherGeoPoliticalID"))
	 gpx->HigherGeoPoliticalID = true;
   else if (SameText(Element, L"GeoPoliticalUnits"))   // root element, set CodePage to UTF-8
	 ipwXMLp5->Config(L"CodePage=65001");
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::ipwXMLp5Characters(TObject *Sender,
	  TipwXMLpCharactersEventParams *e)
{
   UnicodeString ustr = e->Text.w_str();
   gpx->XText += ustr;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::ipwXMLp5EndElement(TObject *Sender,
	  TipwXMLpEndElementEventParams *e)
{
   int Index;
   UnicodeString Element = e->Element.w_str();

   if (gpx->GeoPolitical) {
	 if (SameText(Element, L"GeoPolitical")) {
	   GeoPolUnits->AddGeoPol(GeoPolRec);
	   if (GeoPolRec->Rank == 4) {
		 if (!AdminUnitTypes->Find(GeoPolRec->Unit, Index))
			 AdminUnitTypes->Add(GeoPolRec->Unit);
		 }
	   gpx->GeoPolitical = false;
	   }
	 else if (gpx->GeoPoliticalName) {
	   GeoPolRec->Name = TranslateEntityRefs(gpx->XText);
	   gpx->GeoPoliticalName = false;
	   }
	 else if (gpx->GeoPoliticalUnit) {
	   GeoPolRec->Unit = TranslateEntityRefs(gpx->XText);
	   gpx->GeoPoliticalUnit = false;
	   }
	 else if (gpx->Rank) {
	   GeoPolRec->Rank = gpx->XText.ToInt();
	   gpx->Rank = false;
	   }
	 else if (gpx->HigherGeoPoliticalID) {
	   GeoPolRec->HigherID = gpx->XText.ToInt();
	   gpx->HigherGeoPoliticalID = false;
	   }
	 }
}
//---------------------------------------------------------------------------




