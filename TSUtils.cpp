//---------------------------------------------------------------------------
#define VCL_IOSTREAM
#include <vcl.h>
#include "pch.h"
#include "io.h"
#pragma hdrstop

#include <DateUtils.hpp>
#include <Character.hpp>
#include <iostream.h>
#include <fstream.h>

#include "TSUtils.h"
#ifndef TIGlobalsH
#include "TIGlobals.h"
#endif

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "ipwCore"
#pragma link "ipwxmlp"
//---------------------------------------------------------------------------

/*
TAPHSYSTEMS::TAPHSYSTEMS(TAPHSYSTEMS* ts)
{
   DatasetType = ts->DatasetType;
   for (unsigned int i=0; i<ts->Systems.size(); i++) {
	 if (ts->Systems[i].Types.size() > 0)
	   Systems.push_back(ts->Systems[i]);
	 }
}
//---------------------------------------------------------------------------

void TAPHSYSTEMS::RemoveSystem(UnicodeString System)
{
   vector<TAPHSYSTEM>::iterator itr;
   for (itr = Systems.begin(); itr != Systems.end(); itr++) {
	 if (SameText(itr->Name, System)) {
	   Systems.erase(itr);
	   return;
	   }
	 }
}
//---------------------------------------------------------------------------

void TAPHSYSTEMS::RemoveType(UnicodeString System, UnicodeString Type)
{
   for (unsigned int i=0; i<Systems.size(); i++) {
	 if (SameText(Systems[i].Name, System)) {
	   if (Systems[i].Types.count(Type) > 0)
		 Systems[i].Types.erase(Type);
	   return;
	   }
	 }
}
//---------------------------------------------------------------------------

void TAPHSYSTEMS::AddType(UnicodeString System, UnicodeString Type)
{
   for (unsigned int i=0; i<Systems.size(); i++) {
	 if (SameText(Systems[i].Name, System)) {
	   if (Systems[i].Types.count(Type) == 0)
		 Systems[i].Types.insert(Type);
	   return;
	   }
	 }
   // System not found, so add
   TAPHSYSTEM TaphSystem;
   TaphSystem.Name = System;
   TaphSystem.Types.insert(Type);
   Systems.push_back(TaphSystem);
}
//---------------------------------------------------------------------------

UnicodeString TAPHSYSTEMS::Text(void)
{
   // FAUNMAP:burned;butchered|Behrensmeyer:Stage1
   UnicodeString text;
   set<UnicodeString>::iterator itr;
   for (unsigned int i=0; i<Systems.size(); i++) {
	 if (Systems[i].Types.size() > 0) {
	   if (!text.IsEmpty())
		 text += L"|";
	   if (!SameText(Systems[i].Name, L"none"))
		 text += (Systems[i].Name + L":");
	   set<UnicodeString>::iterator begin = Systems[i].Types.begin();
	   set<UnicodeString>::iterator end = Systems[i].Types.end();
	   for (itr = begin; itr != end; itr++) {
		 if (itr != begin)
		   text += L";";
		 text += *itr;
		 }
	   }
	 }
   return text;
}
//---------------------------------------------------------------------------

bool TAPHSYSTEM::TypesEqual(TAPHSYSTEM& compare)
{
   if (compare.Types.size() != Types.size()) return false;
   set<UnicodeString>::iterator itr1;
   set<UnicodeString>::iterator itr2;
   for (itr1=Types.begin(), itr2=compare.Types.begin(); itr1 != Types.end(); itr1++, itr2++)
	 if (!SameText(*itr1, *itr2)) return false;
   return true;
}
//---------------------------------------------------------------------------

void TAPHSYSTEM::AddTypes(TAPHSYSTEM& source)
{
   set<UnicodeString>::iterator itr = source.Types.begin();
   while (itr != source.Types.end()) {
	 if (Types.find(*itr) == Types.end())
	   Types.insert(*itr);
	 itr++;
	 }
}
//---------------------------------------------------------------------------

MANAGEPROGRESSBAR::MANAGEPROGRESSBAR(TProgressBar* pb, long mv)
{
   ProgressBar = pb;
   if (pb) {
     ProgressBar->Min = 0;
     ProgressBar->Max = 1000;
     ProgressBar->Position = 0;
     }
   Max = (double)mv;
   Min = 0;
   Position = 0;
}
//---------------------------------------------------------------------------

void MANAGEPROGRESSBAR::IncrementPosition(int increment)
{
   Position += (1000.0 * (double)increment/Max);
   ProgressBar->Position = (int)Position;
}
//---------------------------------------------------------------------------

__fastcall ELEMENTLOOKUP::ELEMENTLOOKUP(vector<TAXAECOLGROUPS>& TaxaEcolGroups)
{
   for (unsigned int i=0; i<TaxaEcolGroups.size(); i++)
	 TaxaGroups[TaxaEcolGroups[i].TaxaGroup.Code] = TaxaEcolGroups[i].TaxaGroup.Name;
}
//---------------------------------------------------------------------------

__fastcall ELEMENTLOOKUP::ELEMENTLOOKUP(ELEMENTLOOKUP* Source)
{
   Elements.clear();
   TaxaGroups.clear();
   Elements = Source->Elements;
   TaxaGroups = Source->TaxaGroups;
   PathName = Source->PathName;
}
//---------------------------------------------------------------------------

UnicodeString ELEMENTLOOKUP::Dataset(int idx)
{
   UnicodeString dataset;
   if (idx >= DatasetsCount())
	 return dataset;
   ELEMENTDATASET::iterator t_itr;
   t_itr = Elements.begin();
   advance(t_itr, idx);
   return t_itr->first;
}
//---------------------------------------------------------------------------

bool ELEMENTLOOKUP::Load(UnicodeString ElementsFile, TipwXMLp* ipwXMLp1, bool Parsed)
{
   UnicodeString Version, DatasetType, TaxonGroup, ElementName;
   UTF8String RootXPath, XPath;
   int Count;
   double version;

   //ipwXMLp1->Config("CodePage=65001");
   if (!Parsed) {
	 try {
	   if (FileExists(ElementsFile)) {
		 //ipwXMLp1->Config("CodePage=0");
		 ipwXMLp1->ParseFile(ElementsFile);
		 }
	   else {
		 MessageDlg("File " + ElementsFile + " does not exist.", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 return false;
		 }
	   }
	 catch(...) {
	   MessageDlg("Cannot open " + ElementsFile + ".", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return false;
	   }
	 }

   ParseXMLUnicode* xmlin = new ParseXMLUnicode(ipwXMLp1);

   try {
   try {
	 if (xmlin->RootElement() != "VariableModifiers")
	   throw(Exception(ElementsFile + " is not a valid modifiers file."));

	 RootXPath = "/VariableModifiers/";

	 xmlin->GetAttrStr(RootXPath, "Version", Version);
	 version = IntlStrToDouble::GetDouble(Version);
	 if (version < 2.0)
	   throw(Exception(L"File is version " + FloatToStr(version) + L". It must be version 2."));

	 int XElemChildren = xmlin->XChildrenCount();

	 int nelem = 1;
	 for (int i=0; i<XElemChildren; i++) {
	   if (i>0)
		 xmlin->SetXPath(RootXPath);
	   if (xmlin->GetChildName(i) == "Elements") {
		 XPath = "/VariableModifiers/Elements[" + IntToStr(nelem++) + "]/";
		 xmlin->GetAttrStr(XPath, "DatasetType", DatasetType);
		 int nTaxonGroups = xmlin->XChildrenCount();
		 for (int n=1; n<=nTaxonGroups; n++) {
		   UTF8String XPath1 = XPath + "TaxonGroup[" + IntToStr(n) + "]/";
		   xmlin->GetAttrStr(XPath1, "Group", TaxonGroup);
		   int nElements = xmlin->XChildrenCount();

		   for (int j=1; j<=nElements; j++) {
			 UTF8String XPath2 = XPath1 + "Element[" + IntToStr(j) + "]/";
			 if (!xmlin->GetTextValue(XPath2, "Name", ElementName)) continue;
			 ELEMENTMODIFIERS mods;
			 UnicodeString Symmetry, Portion, Maturity;
			 if (xmlin->ValidChild(XPath2, "Symmetries", Count)) {
			   UTF8String XPath3 = XPath2 + "Symmetries/";
			   for (int k=0; k<Count; k++) {
				 if (xmlin->GetChildText(k, Symmetry))
				   mods.Symmetry.insert(Symmetry);
				 }
			   }
			 if (xmlin->ValidChild(XPath2, "Portions", Count)) {
			   UTF8String XPath3 = XPath2 + "Portions/";
			   for (int k=0; k<Count; k++) {
				 if (xmlin->GetChildText(k, Portion))
				   mods.Portion.insert(Portion);
				 }
			   }
			 if (xmlin->ValidChild(XPath2, "Maturities", Count)) {
			   UTF8String XPath3 = XPath2 + "Maturities/";
			   for (int k=0; k<Count; k++) {
				 if (xmlin->GetChildText(k, Maturity))
				   mods.Maturity.insert(Maturity);
				 }
			   }
			 Elements[DatasetType.LowerCase()][TaxonGroup.LowerCase()][ElementName.LowerCase()] = mods;
			 }
		   }
		 }
	   }
	 }
   catch(Exception &e) {
	 MessageDlg("Error in " + ElementsFile + ": " + e.Message, Dialogs::mtError,
				TMsgDlgButtons() << mbOK, 0);
	 Loaded = false;
	 return false;
	 }
   }
   __finally
	 {
	 delete xmlin;
	 }
   Loaded = true;
   PathName = ElementsFile;
   return true;
}
//---------------------------------------------------------------------------

void ELEMENTLOOKUP::AssignElements(UnicodeString DatasetType, UnicodeString TaxaGroup, TStrings* Items)
{
   DatasetType = DatasetType.LowerCase();
   if (Elements.find(DatasetType) != Elements.end()) {
	 ConvertTaxaGroupID(TaxaGroup);
	 TaxaGroup = TaxaGroup.LowerCase();
	 if (Elements[DatasetType].find(TaxaGroup) != Elements[DatasetType].end()) {
       Items->Clear();
	   ELEMENTNAME::iterator itr;
	   ELEMENTNAME::iterator begin = Elements[DatasetType][TaxaGroup].begin();
	   ELEMENTNAME::iterator end = Elements[DatasetType][TaxaGroup].end();
	   for (itr = begin; itr != end; itr++) {
		 UnicodeString Element = itr->first;
		 int pos = Element.Pos(L"°c");
		 if (pos > 0) {
		   Element.Delete(pos+1,1);
		   Element.Insert(L"C",pos+1);
		   }
		 Items->Add(Element);
		 }
	   }
	 }
}
//---------------------------------------------------------------------------

// check whether TaxaGroup is a TaxaGroup (e.g. vascular plants) or ID (e.g. VPL)
void ELEMENTLOOKUP::ConvertTaxaGroupID(UnicodeString& TaxaGroup)
{
   bool is_id = false;
   if (TaxaGroup.Length() == 3) {
	 is_id = true;
	 for (int i=1; i<=3; i++) {
	   if (!IsUpper(TaxaGroup,i)) {
		 is_id = false;
		 break;
		 }
	   }
	 }
   if (is_id)
	 TaxaGroup = TaxaGroups[TaxaGroup];
}
//---------------------------------------------------------------------------

void ELEMENTLOOKUP::AssignSymmetries(UnicodeString DatasetType, UnicodeString TaxaGroup,
	UnicodeString Element, TStrings* Items)
{
   Items->Clear();
   set<UnicodeString>::iterator itr;
   set<UnicodeString>::iterator begin = Elements[DatasetType][TaxaGroup][Element].Symmetry.begin();
   set<UnicodeString>::iterator end = Elements[DatasetType][TaxaGroup][Element].Symmetry.end();
   for (itr = begin; itr != end; itr++)
	 Items->Add(*itr);
}
//---------------------------------------------------------------------------

void ELEMENTLOOKUP::AssignPortions(UnicodeString DatasetType, UnicodeString TaxaGroup,
	UnicodeString Element, TStrings* Items)
{
   Items->Clear();
   set<UnicodeString>::iterator itr;
   set<UnicodeString>::iterator begin = Elements[DatasetType][TaxaGroup][Element].Portion.begin();
   set<UnicodeString>::iterator end = Elements[DatasetType][TaxaGroup][Element].Portion.end();
   for (itr = begin; itr != end; itr++)
	 Items->Add(*itr);
}
//---------------------------------------------------------------------------

void ELEMENTLOOKUP::AssignMaturities(UnicodeString DatasetType, UnicodeString TaxaGroup,
	UnicodeString Element, TStrings* Items)
{
   Items->Clear();
   set<UnicodeString>::iterator itr;
   set<UnicodeString>::iterator begin = Elements[DatasetType][TaxaGroup][Element].Maturity.begin();
   set<UnicodeString>::iterator end = Elements[DatasetType][TaxaGroup][Element].Maturity.end();
   for (itr = begin; itr != end; itr++)
	 Items->Add(*itr);
}
//---------------------------------------------------------------------------

void ELEMENTLOOKUP::GetDatasetTypes(vector<UnicodeString>& DatasetTypes)
{
   DatasetTypes.clear();
   ELEMENTDATASET::iterator itr;
   ELEMENTDATASET::iterator begin = Elements.begin();
   ELEMENTDATASET::iterator end = Elements.end();
   for (itr = begin; itr != end; itr++)
	 DatasetTypes.push_back(itr->first);
}
//---------------------------------------------------------------------------

void ELEMENTLOOKUP::GetTaxaGroups(UnicodeString DatasetType, vector<UnicodeString>& TaxaGroups)
{
   TaxaGroups.clear();
   DatasetType = DatasetType.LowerCase();
   if (Elements.find(DatasetType) != Elements.end()) {
	 ELEMENTTAXONGROUP::iterator itr;
	 ELEMENTTAXONGROUP::iterator begin = Elements[DatasetType].begin();
	 ELEMENTTAXONGROUP::iterator end = Elements[DatasetType].end();
	 for (itr = begin; itr != end; itr++)
	   TaxaGroups.push_back(itr->first);
	 }
}
//---------------------------------------------------------------------------

void ELEMENTLOOKUP::GetElements(UnicodeString DatasetType, UnicodeString TaxaGroup, vector<UnicodeString>& ElementList)
{
   ElementList.clear();
   DatasetType = DatasetType.LowerCase();
   if (Elements.find(DatasetType) != Elements.end()) {
	 ConvertTaxaGroupID(TaxaGroup);
	 if (Elements[DatasetType].find(TaxaGroup) != Elements[DatasetType].end()) {
	   ELEMENTNAME::iterator itr;
	   ELEMENTNAME::iterator begin = Elements[DatasetType][TaxaGroup].begin();
	   ELEMENTNAME::iterator end = Elements[DatasetType][TaxaGroup].end();
	   for (itr = begin; itr != end; itr++)
		 ElementList.push_back(itr->first);
	   }
	 }
}
//---------------------------------------------------------------------------

void ELEMENTLOOKUP::GetElementsForTaxonGroup(UnicodeString TaxaGroupID, set<UnicodeString>& ElementList)
{
   UnicodeString TaxaGroup;
   if (TaxaGroups.find(TaxaGroupID) != TaxaGroups.end())
	 TaxaGroup = TaxaGroups[TaxaGroupID].LowerCase();
   else
	 return;

   ELEMENTDATASET::iterator itr;
   ELEMENTDATASET::iterator begin = Elements.begin();
   ELEMENTDATASET::iterator end = Elements.end();
   for (itr = begin; itr != end; itr++) {
	 UnicodeString DatasetType = itr->first;
	 if (Elements[DatasetType].find(TaxaGroup) != Elements[DatasetType].end()) {
	   ELEMENTNAME::iterator e_itr;
	   ELEMENTNAME::iterator e_begin = Elements[DatasetType][TaxaGroup].begin();
	   ELEMENTNAME::iterator e_end = Elements[DatasetType][TaxaGroup].end();
	   for (e_itr = e_begin; e_itr != e_end; e_itr++)
		 ElementList.insert(e_itr->first);
	   }
	 }
}
//---------------------------------------------------------------------------

void ELEMENTLOOKUP::GetAllModifiers(map<UnicodeString, map<UnicodeString, ELEMENTMODIFIERS> >&  AllModifiers)
{
   int Index;
   UnicodeString DatasetType, TaxaGroup, Element;

   AllModifiers.clear();

   ELEMENTDATASET::iterator d_itr;
   ELEMENTDATASET::iterator d_begin = Elements.begin();
   ELEMENTDATASET::iterator d_end = Elements.end();

   ELEMENTTAXONGROUP::iterator t_itr;
   ELEMENTTAXONGROUP::iterator t_begin;
   ELEMENTTAXONGROUP::iterator t_end;

   ELEMENTNAME::iterator e_itr;
   ELEMENTNAME::iterator e_begin;
   ELEMENTNAME::iterator e_end;

   set<UnicodeString>::iterator s_itr;
   set<UnicodeString>::iterator s_begin;
   set<UnicodeString>::iterator s_end;

   for (d_itr = d_begin; d_itr != d_end; d_itr++) {
	 DatasetType = d_itr->first;
	 map<UnicodeString, ELEMENTMODIFIERS> TaxaGroups;
	 AllModifiers[DatasetType] = TaxaGroups;
	 t_begin = Elements[DatasetType].begin();
	 t_end = Elements[DatasetType].end();
	 for (t_itr = t_begin; t_itr != t_end; t_itr++) {
	   TaxaGroup = t_itr->first;
	   ELEMENTMODIFIERS ElementModifiers;
	   AllModifiers[DatasetType][TaxaGroup] = ElementModifiers;
	   e_begin = Elements[DatasetType][TaxaGroup].begin();
	   e_end = Elements[DatasetType][TaxaGroup].end();
	   for (e_itr = e_begin; e_itr != e_end; e_itr++) {
		 Element = e_itr->first;
		 if (Elements[DatasetType][TaxaGroup][Element].Symmetry.size() > 0) {
		   s_begin = Elements[DatasetType][TaxaGroup][Element].Symmetry.begin();
		   s_end = Elements[DatasetType][TaxaGroup][Element].Symmetry.end();
		   for (s_itr = s_begin; s_itr != s_end; s_itr++)
			 AllModifiers[DatasetType][TaxaGroup].Symmetry.insert(*s_itr);
		   }
		 if (Elements[DatasetType][TaxaGroup][Element].Portion.size() > 0) {
		   s_begin = Elements[DatasetType][TaxaGroup][Element].Portion.begin();
		   s_end = Elements[DatasetType][TaxaGroup][Element].Portion.end();
		   for (s_itr = s_begin; s_itr != s_end; s_itr++)
			 AllModifiers[DatasetType][TaxaGroup].Portion.insert(*s_itr);
		   }
		 if (Elements[DatasetType][TaxaGroup][Element].Maturity.size() > 0) {
		   s_begin = Elements[DatasetType][TaxaGroup][Element].Maturity.begin();
		   s_end = Elements[DatasetType][TaxaGroup][Element].Maturity.end();
		   for (s_itr = s_begin; s_itr != s_end; s_itr++)
			 AllModifiers[DatasetType][TaxaGroup].Maturity.insert(*s_itr);
		   }
		 }
	   }
	 }
}
//---------------------------------------------------------------------------

__fastcall MODIFIERLOOKUP::MODIFIERLOOKUP()
{
   Sorted = true;
}
//---------------------------------------------------------------------------

__fastcall MODIFIERLOOKUP::~MODIFIERLOOKUP()
{
   for (int i=0; i<Count; i++)
	 delete Objects[i];
}
//---------------------------------------------------------------------------

void UNITLOOKUP::Assign(UnicodeString DatasetType, TStrings* Strings)
{
   Strings->Clear();
   DatasetType = DatasetType.LowerCase();
   if (Units.find(DatasetType) != Units.end()) {
	 set<UnicodeString>::iterator itr;
	 for (itr = Units[DatasetType].begin(); itr != Units[DatasetType].end(); itr++)
	   Strings->Add(*itr);
	 }
}
//---------------------------------------------------------------------------

bool UNITLOOKUP::Load(UnicodeString UnitsFile, TipwXMLp* ipwXMLp1, bool Parsed)
{
   UnicodeString Version, DatasetType, UnitsName;
   UTF8String RootXPath, XPath;
   double version;
   int XChildren;

   //ipwXMLp1->Config("CodePage=65001");
   if (!Parsed) {
	 try {
	   if (FileExists(UnitsFile)) {
         //ipwXMLp1->Config("CodePage=0");
		 ipwXMLp1->ParseFile(UnitsFile);
		 }
	   else {
		 MessageDlg("File " + UnitsFile + " does not exist.", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 return false;
		 }
	   }
	 catch(...) {
	   MessageDlg("Cannot open " + UnitsFile + ".", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return false;
	   }
	 }

   ParseXMLUnicode* xmlin = new ParseXMLUnicode(ipwXMLp1);

   try {
   try {
	 if (xmlin->RootElement() != "VariableModifiers")
	   throw(Exception(UnitsFile + " is not a valid modifiers file."));

	 RootXPath = "/VariableModifiers/";

	 xmlin->GetAttrStr(RootXPath, "Version", Version);
	 version = IntlStrToDouble::GetDouble(Version);
	 if (version < 2.0)
	   throw(Exception(L"File is version " + FloatToStr(version) + L". It must be version 2."));

	 XChildren = xmlin->XChildrenCount();
	 int nunit = 1;

	 for (int i=0; i<XChildren; i++) {
	   if (i>0)
		 xmlin->SetXPath(RootXPath);
	   if (xmlin->GetChildName(i) == "Units") {
		 XPath = "/VariableModifiers/Units[" + IntToStr(nunit++) + "]/";
		 xmlin->GetAttrStr(XPath, "DatasetType", DatasetType);
		 set<UnicodeString> Names;
		 Units[DatasetType] = Names;
		 int nunits = xmlin->XChildrenCount();
		 for (int j=0; j<nunits; j++) {
		   if (xmlin->GetChildText(j, UnitsName))
			 Units[DatasetType].insert(UnitsName);
		   }
		 }
	   }
	 }
   catch(Exception &e) {
	 MessageDlg("Error in " + UnitsFile + ": " + e.Message, Dialogs::mtError,
				TMsgDlgButtons() << mbOK, 0);
	 Loaded = false;
	 return false;
	 }
   }
   __finally
	 {
	 delete xmlin;
	 }

   Loaded = true;
   PathName = UnitsFile;
   return true;
}
//---------------------------------------------------------------------------

void CONTEXTLOOKUP::Assign(UnicodeString DatasetType, TStrings* Strings)
{
   Strings->Clear();
   DatasetType = DatasetType.LowerCase();
   if (Contexts.find(DatasetType) != Contexts.end()) {
	 set<UnicodeString>::iterator itr;
	 for (itr = Contexts[DatasetType].begin(); itr != Contexts[DatasetType].end(); itr++)
	   Strings->Add(*itr);
	 }
}
//---------------------------------------------------------------------------

bool CONTEXTLOOKUP::Load(UnicodeString ContextsFile, TipwXMLp* ipwXMLp1, bool Parsed)
{
   UnicodeString Version, DatasetType, ContextsName;
   UTF8String RootXPath, XPath;
   double version;
   int XChildren;

   //ipwXMLp1->Config("CodePage=65001");
   if (!Parsed) {
	 try {
	   if (FileExists(ContextsFile)) {
		 //ipwXMLp1->Config("CodePage=0");
		 ipwXMLp1->ParseFile(ContextsFile);
		 }
	   else {
		 MessageDlg("File " + ContextsFile + " does not exist.", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 return false;
		 }
	   }
	 catch(...) {
	   MessageDlg("Cannot open " + ContextsFile + ".", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return false;
	   }
	 }

   ParseXMLUnicode* xmlin = new ParseXMLUnicode(ipwXMLp1);

   try {
   try {
     if (xmlin->RootElement() != "VariableModifiers")
	   throw(Exception(ContextsFile + " is not a valid modifiers file."));

	 RootXPath = "/VariableModifiers/";

	 xmlin->GetAttrStr(RootXPath, "Version", Version);
	 version = IntlStrToDouble::GetDouble(Version);
	 if (version < 2.0)
	   throw(Exception(L"File is version " + FloatToStr(version) + L". It must be version 2."));

	 XChildren = xmlin->XChildrenCount();
	 int nctxts = 1;

	 for (int i=0; i<XChildren; i++) {
	   if (i>0)
		 xmlin->SetXPath(RootXPath);
	   if (xmlin->GetChildName(i) == "Contexts") {
		 XPath = "/VariableModifiers/Contexts[" + IntToStr(nctxts++) + "]/";
		 xmlin->GetAttrStr(XPath, "DatasetType", DatasetType);
		 set<UnicodeString> Names;
		 Contexts[DatasetType] = Names;
		 int ncontexts = xmlin->XChildrenCount();
		 for (int j=0; j<ncontexts; j++) {
		   if (xmlin->GetChildText(j, ContextsName))
			 Contexts[DatasetType].insert(ContextsName);
		   }
		 }
	   }
	 }
   catch(Exception &e) {
	 MessageDlg("Error in " + ContextsFile + ": " + e.Message, Dialogs::mtError,
				TMsgDlgButtons() << mbOK, 0);
	 Loaded = false;
	 return false;
	 }
   }
   __finally
	 {
	 delete xmlin;
	 }

   Loaded = true;
   PathName = ContextsFile;
   return true;
}
//---------------------------------------------------------------------------

bool TAPHONOMYLOOKUP::Load(UnicodeString TaphonomyFile, TipwXMLp* ipwXMLp1, bool Parsed)
{
   UnicodeString Version, DatasetTypeName, TaphonomicSystem, TaphonomicType;
   UTF8String RootXPath, XPath;
   double version;
   int XChildren;

   //ipwXMLp1->Config("CodePage=65001");
   if (!Parsed) {
	 try {
	   if (FileExists(TaphonomyFile)) {
		 //ipwXMLp1->Config("CodePage=0");
		 ipwXMLp1->ParseFile(TaphonomyFile);
		 }
	   else {
		 MessageDlg("File " + TaphonomyFile + " does not exist.", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 return false;
		 }
	   }
	 catch(...) {
	   MessageDlg("Cannot open " + TaphonomyFile + ".", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return false;
	   }
	 }

   // define the default "none" system
   TAPHONOMICSYSTEM System;
   DatasetType[L"none"] = System;
   set<UnicodeString> Types;
   DatasetType[L"none"][L"none"] = Types;

   ParseXMLUnicode* xmlin = new ParseXMLUnicode(ipwXMLp1);

   try {
   try {
     if (xmlin->RootElement() != "VariableModifiers")
	   throw(Exception(TaphonomyFile + " is not a valid modifiers file."));

	 RootXPath = "/VariableModifiers/";

	 xmlin->GetAttrStr(RootXPath, "Version", Version);
	 version = IntlStrToDouble::GetDouble(Version);
	 if (version < 2.0)
	   throw(Exception(L"File is version " + FloatToStr(version) + L". It must be version 2."));

	 XChildren = xmlin->XChildrenCount();
	 int ntaph = 1;

	 for (int i=0; i<XChildren; i++) {
	   if (i>0)
		 xmlin->SetXPath(RootXPath);
	   if (xmlin->GetChildName(i) == "Taphonomy") {
		 XPath = "/VariableModifiers/Taphonomy[" + IntToStr(ntaph++) + "]/";
		 xmlin->GetAttrStr(XPath, "DatasetType", DatasetTypeName);
		 TAPHONOMICSYSTEM System;
		 DatasetType[DatasetTypeName] = System;
		 int nsyst = xmlin->XChildrenCount();

		 // <Taphonomy DatasetType="pollen">
		 //   <TaphonomicSystem System="Neotoma Pollen">
		 //     <TaphonomicType>1/2 grains</TaphonomicType>
		 for (int ns=1; ns<=nsyst; ns++) {
		   UnicodeString XPath1 = XPath + L"TaphonomicSystem[" + IntToStr(ns) + L"]/";
		   xmlin->GetAttrStr(XPath1, "System", TaphonomicSystem);
		   set<UnicodeString> Types;
		   DatasetTypeName = DatasetTypeName.LowerCase();
		   DatasetType[DatasetTypeName][TaphonomicSystem] = Types;
		   int ntypes = xmlin->XChildrenCount();
		   for (int nt=0; nt<ntypes; nt++) {
			 if (xmlin->GetChildText(nt, TaphonomicType))
			   DatasetType[DatasetTypeName][TaphonomicSystem].insert(TaphonomicType);
			 }
		   }
		 }
	   }
	 }
   catch(Exception &e) {
	 MessageDlg("Error in " + TaphonomyFile + ": " + e.Message, Dialogs::mtError,
				TMsgDlgButtons() << mbOK, 0);
	 Loaded = false;
	 return false;
	 }
   }
   __finally
	 {
	 delete xmlin;
	 }

   PathName = TaphonomyFile;
   Loaded = true;
   return true;
}
//---------------------------------------------------------------------------

void TAPHONOMYLOOKUP::Add(UnicodeString DatasetTypeName, UnicodeString TaphonomicSystem)
{
   if (DatasetType.find(DatasetTypeName) == DatasetType.end()) {
	 TAPHONOMICSYSTEM System;
	 DatasetType[DatasetTypeName] = System;
	 set<UnicodeString> Types;
	 DatasetType[DatasetTypeName][TaphonomicSystem] = Types;
	 }
   else if (DatasetType[DatasetTypeName].find(TaphonomicSystem) ==  DatasetType[DatasetTypeName].end()) {
	 set<UnicodeString> Types;
	 DatasetType[DatasetTypeName][TaphonomicSystem] = Types;
	 }
}
//---------------------------------------------------------------------------

void TAPHONOMYLOOKUP::Add(UnicodeString DatasetTypeName, UnicodeString TaphonomicSystem, UnicodeString Type)
{
   DatasetTypeName = DatasetTypeName.LowerCase();
   Add(DatasetTypeName, TaphonomicSystem);
   if (DatasetType[DatasetTypeName][TaphonomicSystem].find(Type) == DatasetType[DatasetTypeName][TaphonomicSystem].end()) {
	 DatasetType[DatasetTypeName][TaphonomicSystem].insert(Type);
     }
}
//---------------------------------------------------------------------------

bool TAPHONOMYLOOKUP::TypeExists(UnicodeString DatasetTypeName, UnicodeString TaphonomicSystem, UnicodeString Type)
{
   bool exists = false;
   DatasetTypeName = DatasetTypeName.LowerCase();
   if (DatasetType.find(DatasetTypeName) != DatasetType.end()) {
	 if (DatasetType[DatasetTypeName].find(TaphonomicSystem) != DatasetType[DatasetTypeName].end()) {
	   if (DatasetType[DatasetTypeName][TaphonomicSystem].find(Type) != DatasetType[DatasetTypeName][TaphonomicSystem].end())
		 exists = true;
	   }
	 }
   return exists;
}
//---------------------------------------------------------------------------

void TAPHONOMYLOOKUP::GetTypes(UnicodeString DatasetTypeName, UnicodeString TaphonomicSystem, set<UnicodeString>& Types)
{
   Types.clear();
   DatasetTypeName = DatasetTypeName.LowerCase();
   if (DatasetType.find(DatasetTypeName) != DatasetType.end()) {
	 if (DatasetType[DatasetTypeName].find(TaphonomicSystem) != DatasetType[DatasetTypeName].end())
	   Types = DatasetType[DatasetTypeName][TaphonomicSystem];
	 }
}
//---------------------------------------------------------------------------

bool TAPHONOMYLOOKUP::SystemExists(UnicodeString DatasetTypeName, UnicodeString TaphonomicSystem)
{
   bool exists = false;
   DatasetTypeName = DatasetTypeName.LowerCase();
   if (DatasetType.find(DatasetTypeName) != DatasetType.end()) {
	 if (DatasetType[DatasetTypeName].find(TaphonomicSystem) != DatasetType[DatasetTypeName].end())
	   exists = true;
	 }
   return exists;
}
//---------------------------------------------------------------------------

bool TAPHONOMYLOOKUP::DatasetTypeExists(UnicodeString DatasetTypeName)
{
   DatasetTypeName = DatasetTypeName.LowerCase();
   return (DatasetType.find(DatasetTypeName) != DatasetType.end());
}
//---------------------------------------------------------------------------

void TAPHONOMYLOOKUP::GetSystems(UnicodeString DatasetTypeName, set<UnicodeString>& Systems)
{
   Systems.clear();
   map<UnicodeString, set<UnicodeString> >::iterator itr;
   map<UnicodeString, set<UnicodeString> >::iterator begin = DatasetType[DatasetTypeName].begin();
   map<UnicodeString, set<UnicodeString> >::iterator end = DatasetType[DatasetTypeName].end();
   for (itr = begin; itr != end; itr++)
	 Systems.insert(itr->first);
}
//---------------------------------------------------------------------------

UnicodeString VARIABLELOOKUP::GetElementPath(void)
{
   UnicodeString PathName;
   if (ElementLookup)
	 PathName = ElementLookup->GetPathName();
   return PathName;
}
//---------------------------------------------------------------------------

UnicodeString VARIABLELOOKUP::GetUnitPath(void)
{
   UnicodeString PathName;
   if (UnitLookup)
     PathName = UnitLookup->GetPathName();
   return PathName;
}
//---------------------------------------------------------------------------

UnicodeString VARIABLELOOKUP::GetContextPath(void)
{
   UnicodeString PathName;
   if (ContextLookup)
     PathName = ContextLookup->GetPathName();
   return PathName;
}
//---------------------------------------------------------------------------

UnicodeString VARIABLELOOKUP::GetTaphonomyPath(void)
{
   UnicodeString PathName;
   if (TaphonomyLookup)
     PathName = TaphonomyLookup->GetPathName();
   return PathName;
}
//---------------------------------------------------------------------------

void VARIABLELOOKUP::SetElementPath(UnicodeString PathName)
{
   if (ElementLookup)
     ElementLookup->SetPathName(PathName);
}
//---------------------------------------------------------------------------

void VARIABLELOOKUP::SetUnitPath(UnicodeString PathName)
{
   if (UnitLookup)
     UnitLookup->SetPathName(PathName);
}
//---------------------------------------------------------------------------

void VARIABLELOOKUP::SetContextPath(UnicodeString PathName)
{
   if (ContextLookup)
     ContextLookup->SetPathName(PathName);
}
//---------------------------------------------------------------------------

void VARIABLELOOKUP::SetTaphonomyPath(UnicodeString PathName)
{
   if (TaphonomyLookup)
     TaphonomyLookup->SetPathName(PathName);
}
//---------------------------------------------------------------------------

bool SaveVariableModifiers(int ModType, UnicodeString& PathName, VARIABLELOOKUP* VarLookup,
	 TComponent* AOwner)
{
   UnicodeString FileName;
   int pos;
   bool rv = true;
   bool WriteElements, WriteUnits, WriteContexts, WriteTaph;
   set<UnicodeString>::iterator itr;
   set<UnicodeString>::iterator begin;
   set<UnicodeString>::iterator end;

   UnicodeString ElementsFile = VarLookup->GetElementPath();
   UnicodeString UnitsFile = VarLookup->GetUnitPath();
   UnicodeString ContextsFile = VarLookup->GetContextPath();
   UnicodeString TaphFile = VarLookup->GetTaphonomyPath();

   switch (ModType) {
	 case MOD_ELEMENT:
	   WriteElements = true;
	   WriteUnits = SameText(ElementsFile, UnitsFile);
	   WriteContexts = SameText(ElementsFile, ContextsFile);
	   WriteTaph = SameText(ElementsFile, TaphFile);
	   tiGlobals->ElementsFile = ExtractFileName(ElementsFile);
	   break;
	 case MOD_UNIT:
	   WriteUnits = true;
	   WriteElements = SameText(UnitsFile, ElementsFile);
	   WriteContexts = SameText(UnitsFile, ContextsFile);
	   WriteTaph = SameText(UnitsFile, TaphFile);
	   tiGlobals->UnitsFile = ExtractFileName(UnitsFile);
	   break;
	 case MOD_CONTEXT:
	   WriteContexts = true;
	   WriteElements = SameText(ContextsFile, ElementsFile);
	   WriteUnits = SameText(ContextsFile, UnitsFile);
	   WriteTaph = SameText(ContextsFile, TaphFile);
	   tiGlobals->ContextFile = ExtractFileName(ContextsFile);
	   break;
	 case MOD_TAPHONOMY:
	   WriteTaph = true;
	   WriteElements = SameText(TaphFile, ElementsFile);
	   WriteUnits = SameText(TaphFile, UnitsFile);
	   WriteContexts = SameText(TaphFile, ContextsFile);
	   tiGlobals->TaphonomyFile = ExtractFileName(TaphFile);
	   break;
	 }

   TSaveDialog* SaveDialog1 = new TSaveDialog(AOwner);
   SaveDialog1->DefaultExt = "xml";
   SaveDialog1->Filter = "XML Lookup File (*.xml)|*.xml";
   SaveDialog1->FilterIndex = 1;
   SaveDialog1->Options.Clear();
   SaveDialog1->Options << ofOverwritePrompt << ofHideReadOnly << ofEnableSizing;
   SaveDialog1->InitialDir = ExtractFilePath(PathName);
   SaveDialog1->FileName = ExtractFileName(PathName);

   if (SaveDialog1->Execute()) {
	 FileName = SaveDialog1->FileName;
	 UnicodeString FileExt = LowerCase(ExtractFileExt(FileName));
	 if (FileExt != ".xml") {
	   UnicodeString NewFileName = ExtractFilePath(FileName) + ExtractFileName(FileName) + ".xml";
	   FileName = NewFileName;
	   }

	 WriteXML* xmlout = new WriteXML(FileName);

	 try
	   {
	   try
		 {
		 xmlout->Declaration("1.0", "UTF-8", "yes");
		 xmlout->DateTime();
		 xmlout->BeginTag("VariableModifiers", "version", "2.0");
		 // write elements
		 if (WriteElements) {
		   ELEMENTLOOKUP* ElementLookup = VarLookup->GetElementLookup();
		   vector<UnicodeString> DatasetTypes;
		   ElementLookup->GetDatasetTypes(DatasetTypes);
		   for (unsigned int i=0; i<DatasetTypes.size(); i++) {
			 UnicodeString DatasetType = DatasetTypes[i];
			 xmlout->BeginTag("Elements", "DatasetType", DatasetTypes[i]);
			 vector<UnicodeString> TaxaGroups;
			 ElementLookup->GetTaxaGroups(DatasetTypes[i], TaxaGroups);
			 for (unsigned int j=0; j<TaxaGroups.size(); j++) {
			   xmlout->BeginTag("TaxonGroup", "Group", TaxaGroups[j]);
			   vector<UnicodeString> Elements;
			   ElementLookup->GetElements(DatasetTypes[i], TaxaGroups[j], Elements);
			   for (unsigned int k=0; k<Elements.size(); k++) {
				 xmlout->BeginTag("Element");
				 xmlout->Element("Name", Elements[k]);
				 // symmetries
				 if (ElementLookup->Elements[DatasetTypes[i]][TaxaGroups[j]][Elements[k]].Symmetry.size() > 0) {
				   xmlout->BeginTag("Symmetries");
				   begin = ElementLookup->Elements[DatasetTypes[i]][TaxaGroups[j]][Elements[k]].Symmetry.begin();
				   end = ElementLookup->Elements[DatasetTypes[i]][TaxaGroups[j]][Elements[k]].Symmetry.end();
				   for (itr = begin; itr != end; itr++)
					 xmlout->Element("Symmetry", *itr);
				   xmlout->EndTag("Symmetries");
				   }
				 else
				   xmlout->EmptyElement("Symmetries");
				 // portions
				 if (ElementLookup->Elements[DatasetTypes[i]][TaxaGroups[j]][Elements[k]].Portion.size() > 0) {
				   xmlout->BeginTag("Portions");
				   begin =  ElementLookup->Elements[DatasetTypes[i]][TaxaGroups[j]][Elements[k]].Portion.begin();
				   end = ElementLookup->Elements[DatasetTypes[i]][TaxaGroups[j]][Elements[k]].Portion.end();
				   for (itr = begin; itr != end; itr++)
					 xmlout->Element("Portion", *itr);
				   xmlout->EndTag("Portions");
				   }
				 else
				   xmlout->EmptyElement("Portions");
				 // maturities
				 if (ElementLookup->Elements[DatasetTypes[i]][TaxaGroups[j]][Elements[k]].Maturity.size() > 0) {
				   xmlout->BeginTag("Maturities");
				   begin =  ElementLookup->Elements[DatasetTypes[i]][TaxaGroups[j]][Elements[k]].Maturity.begin();
				   end = ElementLookup->Elements[DatasetTypes[i]][TaxaGroups[j]][Elements[k]].Maturity.end();
				   for (itr = begin; itr != end; itr++)
					 xmlout->Element("Maturity", *itr);
				   xmlout->EndTag("Maturities");
				   }
				 else
				   xmlout->EmptyElement("Maturities");
				 xmlout->EndTag("Element");
				 }
			   xmlout->EndTag("TaxonGroup");
			   }
			 xmlout->EndTag("Elements");
			 }
		   }

		 // write units
		 if (WriteUnits) {
		   UNITLOOKUP* UnitLookup = VarLookup->GetUnitLookup();
		   map<UnicodeString, set<UnicodeString> >::iterator itr;
		   for (itr = UnitLookup->Units.begin(); itr != UnitLookup->Units.end(); itr++) {
			 xmlout->BeginTag("Units", "DatasetType", itr->first);
			 set<UnicodeString>::iterator it;
			 for (it = itr->second.begin(); it != itr->second.end(); it++)
			   xmlout->Element("Unit", *it);
			 xmlout->EndTag("Units");
			 }
		   }

		 // write units
		 if (WriteContexts) {
		   CONTEXTLOOKUP* ContextLookup = VarLookup->GetContextLookup();
		   map<UnicodeString, set<UnicodeString> >::iterator itr;
		   for (itr = ContextLookup->Contexts.begin(); itr != ContextLookup->Contexts.end(); itr++) {
			 xmlout->BeginTag("Contexts", "DatasetType", itr->first);
			 set<UnicodeString>::iterator it;
			 for (it = itr->second.begin(); it != itr->second.end(); it++)
			   xmlout->Element("Context", *it);
			 xmlout->EndTag("Contexts");
			 }
		   }

		 // write taphonomy
		 if (WriteTaph) {
		   TAPHONOMYLOOKUP* TaphLookup = VarLookup->GetTaphonomyLookup();
		   map<UnicodeString, TAPHONOMICSYSTEM>::iterator itr1;
		   for (itr1 = TaphLookup->DatasetType.begin(); itr1 != TaphLookup->DatasetType.end(); itr1++) {
			 UnicodeString DatasetType = itr1->first;
			 if (SameText(DatasetType, L"none")) continue;
			 xmlout->BeginTag("Taphonomy", "DatasetType", DatasetType);
			 map<UnicodeString, set<UnicodeString> >::iterator itr2;
			 map<UnicodeString, set<UnicodeString> >::iterator begin2 =
			   TaphLookup->DatasetType[DatasetType].begin();
			 map<UnicodeString, set<UnicodeString> >::iterator end2 =
			   TaphLookup->DatasetType[DatasetType].end();
			 for (itr2 = begin2; itr2 != end2; itr2++) {
			   UnicodeString System = itr2->first;
			   xmlout->BeginTag("TaphonomicSystem", "System", System);
			   set<UnicodeString>::iterator itr3;
			   set<UnicodeString>::iterator begin3 =
				 TaphLookup->DatasetType[DatasetType][System].begin();
			   set<UnicodeString>::iterator end3 =
				 TaphLookup->DatasetType[DatasetType][System].end();
			   for (itr3 = begin3; itr3 != end3; itr3++)
				 xmlout->Element("TaphonomicType", *itr3);
			   xmlout->EndTag("TaphonomicSystem");
			   }
			 xmlout->EndTag("Taphonomy");
			 }
		   }
		 xmlout->EndTag("VariableModifiers");
		 xmlout->Finish();
		 }
	   catch(Exception &e) {
		 MessageDlg(e.Message, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 rv = false;
		 }
	   }
	 __finally
	   {
	   delete xmlout;
	   }
	 }
   else
	 rv = false;

   if (rv)
	 PathName = FileName;
   return rv;
}
//---------------------------------------------------------------------------

bool VARIABLELOOKUP::ElementsLoaded(void)
{
   if (ElementLookup == NULL)
	 return false;
   else
	 return ElementLookup->IsLoaded;
}
//---------------------------------------------------------------------------

bool VARIABLELOOKUP::UnitsLoaded(void)
{
   if (UnitLookup == NULL)
	 return false;
   else
	 return UnitLookup->IsLoaded;
}
//---------------------------------------------------------------------------

bool VARIABLELOOKUP::ContextsLoaded(void)
{
   if (ContextLookup == NULL)
	 return false;
   else
	 return ContextLookup->IsLoaded;
}
//---------------------------------------------------------------------------

bool VARIABLELOOKUP::TaphonomyLoaded(void)
{
   if (TaphonomyLookup == NULL)
	 return false;
   else
	 return TaphonomyLookup->IsLoaded;
}
//---------------------------------------------------------------------------
*/

