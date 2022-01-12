//---------------------------------------------------------------------------


#pragma hdrstop

#include "io.h"
#include <DateUtils.hpp>
#include <Character.hpp>
#include <iostream.h>
#include <fstream.h>
#include "TICommon.h"
#ifndef TITaxSynH
#include "TITaxSyn.h"
#endif
#ifndef TIGlobalsH
#include "TIGlobals.h"
#endif

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "ipwCore"
#pragma link "ipwxmlp"
//---------------------------------------------------------------------------

/*
bool LAKEPARAM::operator == (const LAKEPARAM& comp)
{
   // return false if any of the variables are not equal
   if (this == &comp) return true;
   if (Name != comp.Name) return false;
   if (Value != comp.Value) return false;
   return true;
}
//---------------------------------------------------------------------------
*/

void DATASET::operator = (const DATASET& copy)
{
   if (this == &copy) return;
   NeotomaDatasetTypeID = copy.NeotomaDatasetTypeID;
   NeotomaDatasetID = copy.NeotomaDatasetID;
   NeotomaDatabaseID = copy.NeotomaDatabaseID;
   NeotomaSubmissionTypeID = copy.NeotomaSubmissionTypeID;
   NeotomaSubmissionNotes = copy.NeotomaSubmissionNotes;
   DatasetType = copy.DatasetType;
   Name = copy.Name;
   Notes = copy.Notes;
   AggregateOrder = copy.AggregateOrder;
   IsSSamp = copy.IsSSamp;
   IsAggregate = copy.IsAggregate;
   WhitmoreID1 = copy.WhitmoreID1;
   WhitmoreData = copy.WhitmoreData;
   Submissions = copy.Submissions;
   Investigators = copy.Investigators;
   Processors = copy.Processors;
   Publications = copy.Publications;
   Repositories = copy.Repositories;
}
//---------------------------------------------------------------------------

UnicodeString DATASET::RepositoryText(void)
{
   UnicodeString Text;
   if (Repositories.size() > 0) {
	 for (unsigned int i=0; i<Repositories.size(); i++) {
	   if (i != 0) Text += L";";
	   Text += Repositories[i].Acronym;
	   }
	 }
   return Text;
}
//---------------------------------------------------------------------------

SITE::SITE()
{
  NeotomaSiteID = -1;
  LongEast = Unassigned();
  LongWest = Unassigned();
  LatNorth = Unassigned();
  LatSouth = Unassigned();
  Altitude = Unassigned();
  Area = Unassigned();
  COLLECTION CollUnit;
  CollUnits.push_back(CollUnit);  // default collection unit
}
//---------------------------------------------------------------------------

SITE::SITE(SITE* site)
{
  NeotomaGeoPolID = site->NeotomaGeoPolID;
  NeotomaLakeParams = site->NeotomaLakeParams;
  NeotomaSiteID = site->NeotomaSiteID;
  SiteName = site->SiteName;
  LongEast = site->LongEast;
  LongWest = site->LongWest;
  LatNorth = site->LatNorth;
  LatSouth = site->LatSouth;
  Altitude = site->Altitude;
  Area = site->Area;
  Country = site->Country;
  State = site->State;
  County = site->County;
  AdminUnit = site->AdminUnit;
  SiteDescription = site->SiteDescription;
  Notes = site->Notes;
  LakeParams = site->LakeParams;
  CollUnits = site->CollUnits;
}
//---------------------------------------------------------------------------

bool SITE::SameSite(SITE* site)
{
   // compares site metadata only. Collection units could vary
   if (NeotomaGeoPolID != site->NeotomaGeoPolID)
	 return false;
   if (NeotomaLakeParams != site->NeotomaLakeParams)
	 return false;
   if (NeotomaSiteID != site->NeotomaSiteID)
	 return false;
   if (SiteName != site->SiteName)
	 return false;
   if (LongEast != site->LongEast)
	 return false;
   if (LongWest != site->LongWest)
	 return false;
   if (LatNorth != site->LatNorth)
	 return false;
   if (LatSouth != site->LatSouth)
	 return false;
   if (Altitude != site->Altitude)
	 return false;
   if (Area != site->Area)
	 return false;
   if (Country != site->Country)
	 return false;
   if (State != site->State)
	 return false;
   if (County != site->County)
	 return false;
   if (AdminUnit != site->AdminUnit)
	 return false;
   if (SiteDescription != site->SiteDescription)
	 return false;
   if (Notes != site->Notes)
	 return false;
   if (LakeParams.size() != site->LakeParams.size())
	 return false;
   else {
	 for (unsigned int i=0; i<LakeParams.size(); i++) {
	   if (LakeParams[i].Name != site->LakeParams[i].Name)
		 return false;
	   if (LakeParams[i].Value != site->LakeParams[i].Value)
		 return false;
	   }
	 }
   return true;
}
//---------------------------------------------------------------------------

COLLECTION::COLLECTION()
{
  GPSLat = Unassigned();
  GPSLong = Unassigned();
  GPSError = Unassigned();
  GPSAltitude = Unassigned();
  WaterDepth = Unassigned();
  CollDate = Unassigned();
  SlopeAngle = Unassigned();
  SlopeAspect = Unassigned();
  NeotomaCollUnitID = -1;
  NeotomaCollTypeID = -1;
  NeotomaDepEnvtID = -1;
  NeotomaRockTypeID = -1;
  //WhitmoreID1 = -1;
}
//---------------------------------------------------------------------------

SPECIMEN::SPECIMEN()
{
   FSpecimenID = -1;
   FNeotomaSpecimenID = -1;
   FDataID = -1;
   FNeotomaDataID = -1;
   FNeotomaElementID = -1;
   FNeotomaSymmetryID = -1;
   FNeotomaPortionID = -1;
   FNeotomaMaturityID = -1;
   FNeotomaSexID = -1;
   FNeotomaDomesticStatusID = -1;
   FNeotomaRepositoryID = -1;
}
//---------------------------------------------------------------------------

SPECIMEN::SPECIMEN(SPECIMEN* sp)
{
   FSpecimenID = sp->SpecimenID;
   FNeotomaSpecimenID = sp->NeotomaSpecimenID;
   FDataID = sp->DataID;
   FNeotomaDataID = sp->NeotomaDataID;
   FNeotomaElementID = sp->NeotomaElementID;
   FNeotomaSymmetryID = sp->FNeotomaSymmetryID;
   FNeotomaPortionID = sp->FNeotomaPortionID;
   FNeotomaMaturityID = sp->FNeotomaMaturityID;
   FNeotomaSexID = sp->FNeotomaSexID;
   FNeotomaDomesticStatusID = sp->FNeotomaDomesticStatusID;
   FNeotomaRepositoryID = sp->FNeotomaRepositoryID;
   FTaxaGroup = sp->TaxaGroup;
   FUserSpecimenID = sp->UserSpecimenID;
   FTaxon = sp->Taxon;
   FElement = sp->Element;
   FSymmetry = sp->Symmetry;
   FPortion = sp->Portion;
   FMaturity = sp->Maturity;
   FSex = sp->Sex;
   FDomesticStatus = sp->DomesticStatus;
   FPreservative = sp->Preservative;
   FNISP = sp->NISP;
   FRepository = sp->Repository;
   FSpecNr = sp->SpecNr;
   FFieldNr = sp->FieldNr;
   FArctosNr = sp->ArctosNr;
   FGenBankNrs = sp->GenBankNrs;
   FNotes = sp->Notes;
   FTaphonomy = sp->Taphonomy;
   FNeotomaTaphonomy = sp->NeotomaTaphonomy;
}
//---------------------------------------------------------------------------

void SPECIMEN::operator = (const SPECIMEN& copy)
{
   if (this == &copy) return;
   FSpecimenID = copy.SpecimenID;
   FNeotomaSpecimenID = copy.NeotomaSpecimenID;
   FDataID = copy.DataID;
   FNeotomaDataID = copy.NeotomaDataID;
   FNeotomaElementID = copy.NeotomaElementID;
   FNeotomaSymmetryID = copy.FNeotomaSymmetryID;
   FNeotomaPortionID = copy.FNeotomaPortionID;
   FNeotomaMaturityID = copy.FNeotomaMaturityID;
   FNeotomaSexID = copy.FNeotomaSexID;
   FNeotomaDomesticStatusID = copy.FNeotomaDomesticStatusID;
   FNeotomaRepositoryID = copy.FNeotomaRepositoryID;
   FTaxaGroup = copy.TaxaGroup;
   FTaxon = copy.Taxon;
   FElement = copy.Element;
   FSymmetry = copy.Symmetry;
   FPortion = copy.Portion;
   FMaturity = copy.Maturity;
   FSex = copy.Sex;
   FDomesticStatus = copy.DomesticStatus;
   FPreservative = copy.Preservative;
   FNISP = copy.NISP;
   FRepository = copy.Repository;
   FSpecNr = copy.SpecNr;
   FFieldNr = copy.FieldNr;
   FArctosNr = copy.ArctosNr;
   FGenBankNrs = copy.GenBankNrs;
   FNotes = copy.Notes;
   FTaphonomy = copy.Taphonomy;
   FNeotomaTaphonomy = copy.NeotomaTaphonomy;
}
//---------------------------------------------------------------------------

bool SPECIMEN::operator == (const SPECIMEN& comp)
{
   // return false if any of the variables are not equal
   if (this == &comp) return true;
   if (FSpecimenID != comp.SpecimenID) return false;
   if (FNeotomaSpecimenID != comp.NeotomaSpecimenID) return false;
   if (FDataID != comp.DataID) return false;
   if (FNeotomaDataID != comp.NeotomaDataID) return false;
   if (FNeotomaElementID != comp.NeotomaElementID) return false;
   if (FNeotomaSymmetryID != comp.NeotomaSymmetryID) return false;
   if (FNeotomaPortionID != comp.NeotomaPortionID) return false;
   if (FNeotomaMaturityID != comp.NeotomaMaturityID) return false;
   if (FNeotomaSexID != comp.NeotomaSexID) return false;
   if (FNeotomaDomesticStatusID != comp.NeotomaDomesticStatusID) return false;
   if (FNeotomaRepositoryID != comp.NeotomaRepositoryID) return false;
   if (FTaxaGroup != comp.TaxaGroup) return false;
   if (FTaxon != comp.Taxon) return false;
   if (FElement != comp.Element) return false;
   if (FSymmetry != comp.Symmetry) return false;
   if (FPortion != comp.Portion) return false;
   if (FMaturity != comp.Maturity) return false;
   if (FSex != comp.Sex) return false;
   if (FDomesticStatus != comp.DomesticStatus) return false;
   if (FPreservative != comp.Preservative) return false;
   if (FNISP != comp.NISP) return false;
   if (FRepository != comp.Repository) return false;
   if (FSpecNr != comp.SpecNr) return false;
   if (FFieldNr != comp.FieldNr) return false;
   if (FArctosNr != comp.ArctosNr) return false;
   if (FGenBankNrs.size() != comp.GenBankNrs.size())
	 return false;
   else {
	 set<UnicodeString> GenBankNrs2 = comp.GenBankNrs;
	 set<UnicodeString>::iterator it1, it2;
	 set<UnicodeString>::iterator begin1 = FGenBankNrs.begin();
	 set<UnicodeString>::iterator begin2 = GenBankNrs2.begin();
	 for (it1 = begin1, it2 = begin2; it1 != FGenBankNrs.end(); it1++, it2++) {
	   if (*it1 != *it2)
		 return false;
	   }
	 }
   if (FNotes != comp.Notes) return false;
   if (FTaphonomy.size() != comp.Taphonomy.size())
	 return false;
   else if (FTaphonomy.size() > 0) {    // TAPHONOMICSYSTEM
	 TAPHONOMICSYSTEM::iterator its1;
	 TAPHONOMICSYSTEM::const_iterator its2 = comp.Taphonomy.begin();
	 for (its1 = FTaphonomy.begin(); its1 != FTaphonomy.end(); its1++) {
	   if (its1->first != its2->first)
		 return false;
	   else
		 its2++;
	   }
	 its2 = comp.Taphonomy.begin();
	 for (its1 = FTaphonomy.begin(); its1 != FTaphonomy.end(); its1++) {
	   set<UnicodeString>& types = its1->second;
	   const set<UnicodeString>& comptypes = its2->second;
	   if (types.size() != comptypes.size())
		 return false;
	   else if (types.size() > 0) {
		 set<UnicodeString>::iterator itt1;
		 set<UnicodeString>::const_iterator itt2 = comptypes.begin();
		 for (itt1 = types.begin(); itt1 != types.end(); itt1++) {
		   if (*itt1 != *itt2)
			 return false;
		   else
			 itt2++;
		   }
		 }
	   its2++;
	   }
	 }
   if (FNeotomaTaphonomy.size() != comp.NeotomaTaphonomy.size())
	 return false;
   else if (FNeotomaTaphonomy.size() > 0) {
	 set<int>::iterator it1;
	 set<int>::const_iterator it2 = comp.NeotomaTaphonomy.begin();
	 for (it1 = FNeotomaTaphonomy.begin(); it1 != FNeotomaTaphonomy.end(); it1++) {
	   if (*it1 != *it2)
		 return false;
       it2++;
	   }
	 }
   return true;
}
//---------------------------------------------------------------------------

void CELLOBJECT::operator = (const CELLOBJECT& copy)
{
   if (this == &copy) return;
   FObjectType = copy.ObjectType;
   FNeotomaDataID = copy.NeotomaDataID;
   FObject = copy.Object;
}
//---------------------------------------------------------------------------

CELLOBJECT::CELLOBJECT(int object_type)
{
   TAXON_NOTES* TaxonNotes;
   TList* Contacts;
   TList* Pubs;
   TList* Specimens;
   TAPHSYSTEMS* TaphSystems;

   FObject = NULL;
   FNeotomaDataID = -1;
   FObjectType = object_type;

   switch (object_type) {
	 case CELLTAXONNOTES:
	   TaxonNotes = new TAXON_NOTES();
	   FObject = (TObject*)TaxonNotes;
	   break;
	 case CELLCONTACTS:
	   Contacts = new TList;
	   FObject = (TObject*)Contacts;
	   break;
	 case CELLPUBLICATIONS:
	   Pubs = new TList;
	   FObject = (TObject*)Pubs;
	   break;
	 case CELLTAPHONOMY:
	   TaphSystems = new TAPHSYSTEMS();
	   FObject = (TObject*)TaphSystems;
	   break;
	 case CELLSPECIMENS:
	   Specimens = new TList;
	   FObject = (TObject*)Specimens;
	   break;
	 }
}
//---------------------------------------------------------------------------

CELLOBJECT::CELLOBJECT(CELLOBJECT* cell_object)
{
   TAXON_NOTES* TaxonNotes;
   TAXON_NOTES* NewTaxonNotes;
   TAPHSYSTEMS* NewTaphSystems;
   SPECIMEN* NewSpecimen;
   TList* Specimens;
   TList* NewSpecimens;
   TList* Contacts;

   FObject = NULL;
   FObjectType = cell_object->ObjectType;
   FNeotomaDataID = cell_object->NeotomaDataID;

   switch (cell_object->ObjectType) {
	 case CELLTAXONNOTES:
	   TaxonNotes = (TAXON_NOTES*)cell_object->Object;
	   NewTaxonNotes = new TAXON_NOTES(TaxonNotes);
	   FObject = (TObject*)NewTaxonNotes;
	   break;
	 case CELLCONTACTS:
	   Contacts = new TList;
	   Contacts->Assign((TList*)cell_object->Object);
	   FObject = (TObject*)Contacts;
	   break;
	 case CELLSITE:
       FObject = cell_object->Object;
	   break;
	 case CELLTAPHONOMY:
	   NewTaphSystems = new TAPHSYSTEMS((TAPHSYSTEMS*)cell_object->Object);
	   FObject = (TObject*)NewTaphSystems;
	   break;
	 case CELLSPECIMENS:
	   Specimens = (TList*)cell_object->Object;
	   NewSpecimens = new TList;
	   for (int i=0; i<Specimens->Count; i++) {
		 NewSpecimen = new SPECIMEN((SPECIMEN*)Specimens->Items[i]);
		 NewSpecimens->Add(NewSpecimen);
		 }
	   FObject = (TObject*)NewSpecimens;
	   break;
	 }
}
//---------------------------------------------------------------------------

CELLOBJECT::~CELLOBJECT()
{
   TAXON_NOTES* TaxonNotes;
   TList* FList;
   TAPHSYSTEMS* TaphSystems;

   switch (FObjectType) {
	 case CELLTAXONNOTES:
	   TaxonNotes = (TAXON_NOTES*)FObject;
	   delete TaxonNotes;
	   break;
	 case CELLCONTACTS:
	   FList = (TList*)FObject;
	   FList->Clear();
	   delete FList;
	   break;
	 case CELLPUBLICATIONS:
	   FList = (TList*)FObject;
	   FList->Clear();
	   delete FList;
	   break;
	 case CELLTAPHONOMY:
	   TaphSystems = (TAPHSYSTEMS*)FObject;
	   delete TaphSystems;
	   break;
	 case CELLSPECIMENS:
	   TList* FList = (TList*)FObject;
	   for (int i=0; i<FList->Count; i++) {
		 SPECIMEN *specimen = (SPECIMEN*)FList->Items[i];
		 if (specimen != NULL) {
		   delete specimen;
		   FList->Items[i] = NULL;
		   }
		 }
	   FList->Clear();
	   delete FList;
	   break;
	 }
}
//---------------------------------------------------------------------------

bool ISOMETADATA::IsEmpty(void)
{
   if (!TechError.IsEmpty())
	 return false;
   if (!TechErrorSD.IsEmpty())
	 return false;
   if (!LongTermError.IsEmpty())
	 return false;
   if (!Instrument.IsEmpty())
	 return false;
   if (!IntroSystem.IsEmpty())
	 return false;
   if (Standards.size() > 0)
	 return false;
   if (!SrLocalValue.IsEmpty())
	 return false;
   if (!SrLocalGeolContext.IsEmpty())
	 return false;
   if (!Notes.IsEmpty())
	 return false;
   return true;
}
//---------------------------------------------------------------------------


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
   UnicodeString microchar = L"microcharcoal";
   UnicodeString macrochar = L"macrocharcoal";

   if (!Parsed) {
	 try {
	   if (FileExists(ElementsFile)) {
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
			 UnicodeString dt = DatasetType.LowerCase();
			 Elements[dt][TaxonGroup.LowerCase()][ElementName.LowerCase()] = mods;
			 if (ContainsText(dt,L"charcoal")) {
			   if (dt != microchar)
				 Elements[microchar][TaxonGroup.LowerCase()][ElementName.LowerCase()] = mods;
			   if (dt != macrochar)
				 Elements[macrochar][TaxonGroup.LowerCase()][ElementName.LowerCase()] = mods;
			   }
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

   /*
   <Units DatasetType="pollen">
	 <Unit>NISP</Unit>
	 <Unit>percent</Unit>
	 <Unit>present/absent</Unit>
   </Units>
   */

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

SPECIMENDATETAXAGROUPS::SPECIMENDATETAXAGROUPS()
{
   // plant macrofossils
   TaxaGroupDatasetType[L"VPL"] = 4;
   TaxaGroupDatasetType[L"BRY"] = 4;
   // vertebrate fauna
   TaxaGroupDatasetType[L"AVE"] = 5;
   TaxaGroupDatasetType[L"FSH"] = 5;
   TaxaGroupDatasetType[L"HRP"] = 5;
   TaxaGroupDatasetType[L"MAM"] = 5;
   // macroinvertebrates
   TaxaGroupDatasetType[L"CRU"] = 6;
   TaxaGroupDatasetType[L"ECH"] = 6;
   TaxaGroupDatasetType[L"MOL"] = 6;
   // insects
   TaxaGroupDatasetType[L"ART"] = 8;
   TaxaGroupDatasetType[L"INS"] = 8;
}
//---------------------------------------------------------------------------

int SPECIMENDATETAXAGROUPS::GetDatasetTypeID(UnicodeString TaxaGroupID)
{
   if (TaxaGroupDatasetType.count(TaxaGroupID) == 1)
	 return TaxaGroupDatasetType[TaxaGroupID];
   else
	 return -1;
}
//---------------------------------------------------------------------------

bool SPECIMENDATETAXAGROUPS::IsTaxaGroupInDatasetType(UnicodeString TaxaGroupID, int DatasetTypeID)
{
   if (TaxaGroupDatasetType.count(TaxaGroupID) == 1)
	 return (TaxaGroupDatasetType[TaxaGroupID] == DatasetTypeID);
   else
	 return false;
}
//---------------------------------------------------------------------------

void TSumList::ReleaseAllSums()
{
  for (int i = 0; i < Count; i++)
	ReleaseSum(i);
}
//---------------------------------------------------------------------------

void TSumList::ReleaseSum(int AIndex)
{
  delete (FSUM*)Items[AIndex];
}
//---------------------------------------------------------------------------

FSUM* TSumList::GetSum(int AIndex)
{
  return (FSUM*)Items[AIndex];
}
//---------------------------------------------------------------------------

void __fastcall TSumList::Notify(void * Ptr, TListNotification Action)
{
  if (FOnNotify != NULL)
    FOnNotify(Ptr, Action);
}
//---------------------------------------------------------------------------

void __fastcall TSumList::Clear(void)
{
  ReleaseAllSums();
}
//---------------------------------------------------------------------------

void TSumList::Add(FSUM* Sum)
{
  TList::Add(Sum);
}
//---------------------------------------------------------------------------

void TSumList::Delete(int AIndex)
{
  ReleaseSum(AIndex);
  TList::Delete(AIndex);
}
//---------------------------------------------------------------------------

void TSumList::Insert(int AIndex, FSUM* Sum)
{
  TList::Insert(AIndex, Sum);
}
//---------------------------------------------------------------------------

void TSuperSumList::ReleaseAllSuperSums()
{
  for (int i = 0; i < Count; i++)
    ReleaseSuperSum(i);
}
//---------------------------------------------------------------------------

void TSuperSumList::ReleaseSuperSum(int AIndex)
{
  delete (SUPERSUM*)Items[AIndex];
}
//---------------------------------------------------------------------------

SUPERSUM* TSuperSumList::GetSuperSum(int AIndex)
{
  return (SUPERSUM*)Items[AIndex];
}
//---------------------------------------------------------------------------

void __fastcall TSuperSumList::Notify(void * Ptr, TListNotification Action)
{
  if (FOnNotify != NULL)
    FOnNotify(Ptr, Action);
}
//---------------------------------------------------------------------------

void __fastcall TSuperSumList::Clear(void)
{
  ReleaseAllSuperSums();
}
//---------------------------------------------------------------------------

void TSuperSumList::Add(SUPERSUM* SuperSum)
{
  TList::Add(SuperSum);
}
//---------------------------------------------------------------------------

void TSuperSumList::Delete(int AIndex)
{
  ReleaseSuperSum(AIndex);
  TList::Delete(AIndex);
}
//---------------------------------------------------------------------------

void TSuperSumList::Insert(int AIndex, SUPERSUM* SuperSum)
{
  TList::Insert(AIndex, SuperSum);
}
//---------------------------------------------------------------------------

SUMS::SUMS(TSumList *sumlist, set<UnicodeString>& ValidElements,
	map<int,pair<UnicodeString,UnicodeString> >& ElementGroupCodes,
	UnicodeString InvalidGroup)
{
   ValidCodes = true;
   SumList = sumlist;
   if (!SumList->Count) return;

   FSUM* fsum = SumList->Sums[0];
   UnicodeString SumCode = fsum->Code;

   // set up sum variables
   if (SumCode.Length() == 1) {
	 SVar["A"] = SUMVARIABLE("Trees and Shrubs", 'P', true);
	 SVar["B"] = SUMVARIABLE("Upland Herbs", 'P', true);
	 SVar["F"] = SUMVARIABLE("Terrestrial Vascular Cryptogams", 'P', true);
	 SVar["Q"] = SUMVARIABLE("Aquatics", 'R', true);
	 SVar["S"] = SUMVARIABLE("Spores", 'T', true);
	 SVar["X"] = SUMVARIABLE("Unknown and Indeterminable", 'T', true);
	 SVar["Z"] = SUMVARIABLE("Anachronic", 'T', false);
	 }
   else if (SumCode.Length() == 4) {
	 SVar["TRSH"] = SUMVARIABLE("Trees and Shrubs", 'P', true);
	 SVar["PALM"] = SUMVARIABLE("Palms", 'P', true);
	 SVar["SUCC"] = SUMVARIABLE("Succulents", 'P', true);
	 SVar["UPHE"] = SUMVARIABLE("Upland Herbs", 'P', true);
	 SVar["PCON"] = SUMVARIABLE("Pan-Coniferae", 'P', true);
	 SVar["ANGI"] = SUMVARIABLE("Angiospermae", 'P', true);
	 SVar["EUDI"] = SUMVARIABLE("Eudicotyledoneae", 'P', true);
	 SVar["SEED"] = SUMVARIABLE("Spermatophyte rank or clade above order", 'P', true);
	 SVar["VASC"] = SUMVARIABLE("Vascular plants", 'P', true);
	 SVar["PTER"] = SUMVARIABLE("Pteridophyta", 'P', true);
	 SVar["VACR"] = SUMVARIABLE("Terrestrial Vascular Cryptogams", 'P', true);
	 SVar["UPBR"] = SUMVARIABLE("Upland Bryophytes", 'P', true);
	 SVar["MANG"] = SUMVARIABLE("Mangroves", 'R', true);
	 SVar["AQVP"] = SUMVARIABLE("Aquatic Vascular Plants", 'R', true);
	 SVar["AQBR"] = SUMVARIABLE("Aquatic Bryophytes", 'R', true);
	 SVar["FUNG"] = SUMVARIABLE("Fungi", 'F', false);
	 SVar["ANAC"] = SUMVARIABLE("Anachronic", 'T', false);
	 SVar["PLNT"] = SUMVARIABLE("Plant", 'T', true);
	 SVar["UNID"] = SUMVARIABLE("Unknown and Indeterminable", 'T', true);
	 SVar["NOPO"] = SUMVARIABLE("Undifferentiated Non-pollen Palynomorphs", 'N', false);
	 SVar["ACRI"] = SUMVARIABLE("Acritarchs", 'N', false);
	 SVar["ALGA"] = SUMVARIABLE("Algae", 'N', false);
	 SVar["ANIM"] = SUMVARIABLE("Undifferentiated Animals", 'N', false);
	 SVar["ANNL"] = SUMVARIABLE("Annelida", 'N', false);
	 SVar["ACAR"] = SUMVARIABLE("Acari", 'N', false);
	 SVar["ARTH"] = SUMVARIABLE("Undifferentiated Arthropods", 'N', false);
	 SVar["CHRM"] = SUMVARIABLE("Chromista", 'N', false);
	 SVar["SILC"] = SUMVARIABLE("Silicoflagellates", 'N', false);
	 SVar["CLAD"] = SUMVARIABLE("Cladocera", 'N', false);
	 SVar["COPE"] = SUMVARIABLE("Copepods", 'N', false);
	 SVar["CRUS"] = SUMVARIABLE("Undifferentiated Crustaceans", 'N', false);
	 SVar["DIAT"] = SUMVARIABLE("Diatoms", 'N', false);
	 SVar["DINO"] = SUMVARIABLE("Dinoflagellates", 'N', false);
	 SVar["FLWO"] = SUMVARIABLE("Flatworms", 'N', false);
	 SVar["FORM"] = SUMVARIABLE("Foraminifera", 'N', false);
	 SVar["DIPT"] = SUMVARIABLE("Diptera", 'N', false);
	 SVar["LEPI"] = SUMVARIABLE("Lepidoptera", 'N', false);
	 SVar["NEMA"] = SUMVARIABLE("Nematodes", 'N', false);
	 SVar["EMBR"] = SUMVARIABLE("Undifferentiated Embryophyta", 'N', false);
	 SVar["PROT"] = SUMVARIABLE("Undifferentiated Protists", 'N', false);
	 SVar["ROTI"] = SUMVARIABLE("Undifferentiated Rotifers", 'N', false);
	 SVar["SPNG"] = SUMVARIABLE("Sponges", 'N', false);
	 SVar["TEAM"] = SUMVARIABLE("Testate Amoebae", 'N', false);
	 SVar["LABO"] = SUMVARIABLE("Laboratory Analyses", '-', false);
	 SVar["CONC"] = SUMVARIABLE("Concentration Variables", '-', false);
	 SVar["CHAR"] = SUMVARIABLE("Charcoal", '-', false);
	 SVar["MNRL"] = SUMVARIABLE("Mineral", '-', false);
	 SVar["BIOM"] = SUMVARIABLE("Biometric Measurements", '-', false);
	 }
   else {
	 ValidCodes = false;
	 return;
	 }

   // set up supersum variables
   SSVar.push_back(SUPERSUMVARIABLE("P", "Pollen Sum"));
   SSVar.back().Base.push_back("P");
   SSVar.push_back(SUPERSUMVARIABLE("F", "Fungi + Pollen Sum"));
   SSVar.back().Base.push_back("P");
   SSVar.back().Base.push_back("F");
   SSVar.push_back(SUPERSUMVARIABLE("N", "NPPs + Pollen Sum"));
   SSVar.back().Base.push_back("P");
   SSVar.back().Base.push_back("N");
   SSVar.push_back(SUPERSUMVARIABLE("R", "Aquatics + Pollen Sum"));
   SSVar.back().Base.push_back("P");
   SSVar.back().Base.push_back("R");
   SSVar.push_back(SUPERSUMVARIABLE("T", "Total Pollen Sum"));
   SSVar.back().Base.push_back("P");
   // SSVar.back().Base.push_back("F");
   SSVar.back().Base.push_back("R");
   SSVar.back().Base.push_back("T");

   if (ValidCodes) {
	 bool nopo = false;
	 map<int,pair<UnicodeString,UnicodeString> >::iterator itr;
	 for (itr = ElementGroupCodes.begin(); itr != ElementGroupCodes.end(); itr++) {
	   UnicodeString GroupCode = itr->second.second;
	   if (SVar.find(GroupCode) != SVar.end()) {
		 if (SVar[GroupCode].Valid) {
		   UnicodeString Element = itr->second.first;
		   if (ValidElements.count(Element) == 0) {
			 itr->second.second = InvalidGroup;
			 nopo = true;
			 }
		   }
		 }
	   }

	 if (nopo) {
	   bool found = false;
	   for (int i=0; i<SumList->Count; i++) {
		 FSUM* fsum = SumList->Sums[i];
		 if (SameText(fsum->Code,L"NOPO")) {
		   found = true;
		   break;
		   }
		 }
	   if (!found) {
		 UnicodeString NOPO = L"NOPO";
		 FSUM* Sum = new FSUM(NOPO);
		 Sum->Base = L"none";
		 SumList->Add(Sum);
	     }
	   }

	 for (int i=0; i<SumList->Count; i++) {
	   FSUM* fsum = SumList->Sums[i];
	   if (!SVar.count(fsum->Code)) {
		 ValidCodes = false;
		 break;
		 }
	   }

	 for (int i=0; i<SumList->Count; i++) {
	   FSUM* fsum = SumList->Sums[i];
	   UsedBases.push_back(SVar[fsum->Code].Base);
	   }

	 for (int i=0; i<SumList->Count; i++) {
	   FSUM* fsum = SumList->Sums[i];
	   fsum->Name = SVar[fsum->Code].Name;
	   if (SVar[fsum->Code].Base == "-") {
		 fsum->Skip = true;
		 fsum->Percent = false;
		 }
	   }
	 }
}
//---------------------------------------------------------------------------

bool ANALUNIT::operator == (const ANALUNIT& comp)
{
   // return false if any of the variables are not equal
   if (this == &comp) return true;
   if (FDepth != comp.Depth) return false;
   if (FThickness != comp.Thickness) return false;
   if (FName != comp.Name) return false;
   return true;
}
//---------------------------------------------------------------------------

Access::Access(TADOConnection *ado, UnicodeString fn)
{
   ConnectionString  = L"Provider=Microsoft.Jet.OLEDB.4.0;";
   ConnectionString += L"User ID=Admin;Data Source=?;";
   ConnectionString += L"Mode=Share Deny None;";
   ConnectionString += L"Jet OLEDB:System database=\"\";";
   ConnectionString += L"Jet OLEDB:Registry Path=\"\";";
   ConnectionString += L"Jet OLEDB:Database Password=\"\";";
   ConnectionString += L"Jet OLEDB:Engine Type=5;";
   ConnectionString += L"Jet OLEDB:Database Locking Mode=1;";
   ConnectionString += L"Jet OLEDB:Global Partial Bulk Ops=2;";
   ConnectionString += L"Jet OLEDB:Global Bulk Transactions=1;";
   ConnectionString += L"Jet OLEDB:New Database Password=\"\";";
   ConnectionString += L"Jet OLEDB:Create System Database=False;";
   ConnectionString += L"Jet OLEDB:Encrypt Database=False;";
   ConnectionString += L"Jet OLEDB:Don't Copy Locale on Compact=False;";
   ConnectionString += L"Jet OLEDB:Compact Without Replica Repair=False;";
   ConnectionString += L"Jet OLEDB:SFP=False;";

   ADOConnection1 = ado;
   FileName = fn;
}
//---------------------------------------------------------------------------

Access::~Access()
{
   Disconnect();
}
//---------------------------------------------------------------------------

bool Access::Connect(void)
{
   int pos = ConnectionString.Pos(L"?");
   ConnectionString.Delete(pos,1);
   ConnectionString.Insert(FileName,pos);
   ADOConnection1->ConnectionString = WideString(FileName);

   try
	{
	   ADOConnection1->Connected = true;
	}
	catch (EADOError *e)
	{
		MessageDlg("Error while connecting to " + FileName, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		return false;
	}
   return true;
}
//---------------------------------------------------------------------------

bool Access::Disconnect(void)
{
   ADOConnection1->Connected = false;

   try
	{
	   if (ADOConnection1->Connected)
		 ADOConnection1->Connected = false;
	}
	catch (EADOError *e)
	{
		MessageDlg("Error while disconnecting from " + FileName, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		return false;
	}
   return true;
}
//---------------------------------------------------------------------------


