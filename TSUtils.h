//---------------------------------------------------------------------------
#include <vcl.h>

#ifndef TSUtilsH
#define TSUtilsH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <ComCtrls.hpp>
#include "ipwCore.h"
#include "ipwxmlp.h"
#include <vector>
#include <map>
#include <set>
//#ifndef TIUtilsH
//#include "TIUtils.h"
//#endif
//#ifndef TICommonH
//#include "TICommon.h"
//#endif
//#ifndef TIXMLH
//#include "TIXML.h"
//#endif


/*
//---------------------------------------------------------------------------
enum MODTYPES { MOD_ELEMENT, MOD_UNIT, MOD_CONTEXT, MOD_TAPHONOMY };
//---------------------------------------------------------------------------

class MANAGEPROGRESSBAR
{
private:
   TProgressBar* ProgressBar;
   double Min;
   double Max;
   double Position;
public:
   MANAGEPROGRESSBAR(TProgressBar*, long);
   void IncrementPosition(int);
   void SetMax(double mx) { Max = mx; }
   TProgressBar* GetProgressBar(void) { return ProgressBar; }
   void SetProgressBar(TProgressBar* pb)
     { ProgressBar = pb;
       ProgressBar->Min = 0;
       ProgressBar->Max = 1000;
       ProgressBar->Position = 0; }
};
//---------------------------------------------------------------------------

typedef struct
{
  set<UnicodeString> Symmetry;
  set<UnicodeString> Portion;
  set<UnicodeString> Maturity;
} ELEMENTMODIFIERS;
//---------------------------------------------------------------------------

typedef map<UnicodeString, ELEMENTMODIFIERS> ELEMENTNAME;
typedef map<UnicodeString, ELEMENTNAME> ELEMENTTAXONGROUP;
typedef map<UnicodeString, ELEMENTTAXONGROUP> ELEMENTDATASET;
//---------------------------------------------------------------------------

class MODIFIERBASE
{
protected:
  UnicodeString PathName;
  bool Loaded;
public:
  MODIFIERBASE() { Loaded = false; }
  virtual bool Load(const UnicodeString, TipwXMLp*, bool) = 0;
  UnicodeString GetPathName(void) { return PathName; }
  void SetPathName(UnicodeString& pn) { PathName = pn; }
  __property bool IsLoaded = {read = Loaded};
};
//---------------------------------------------------------------------------

class ELEMENTLOOKUP : public MODIFIERBASE
{
public:
	map<UnicodeString, UnicodeString> TaxaGroups;   // TaxaGroupID, TaxaGroup
	ELEMENTDATASET Elements;
public:
	__fastcall ELEMENTLOOKUP() { }
	__fastcall ELEMENTLOOKUP(vector<TAXAECOLGROUPS>& TaxaEcolGroups);
	__fastcall ELEMENTLOOKUP(ELEMENTLOOKUP*);
	bool Load(const UnicodeString, TipwXMLp*, bool);
	int DatasetsCount(void) { return Elements.size(); }
	int TaxaGroupsCount(UnicodeString tg) { return Elements[tg].size(); }
	UnicodeString Dataset(int idx);
	void ConvertTaxaGroupID(UnicodeString& TaxaGroup);
	void AssignElements(UnicodeString DatasetType, UnicodeString TaxaGroupID, TStrings* Items);
	void AssignSymmetries(UnicodeString DatasetType, UnicodeString TaxaGroup, UnicodeString Element, TStrings* Items);
	void AssignPortions(UnicodeString DatasetType, UnicodeString TaxaGroup, UnicodeString Element, TStrings* Items);
	void AssignMaturities(UnicodeString DatasetType, UnicodeString TaxaGroup, UnicodeString Element, TStrings* Items);
	void GetDatasetTypes(vector<UnicodeString>& DatasetTypes);
	void GetTaxaGroups(UnicodeString DatasetType, vector<UnicodeString>& TaxaGroups);
	void GetElements(UnicodeString DatasetType, UnicodeString TaxaGroupID, vector<UnicodeString>& ElementList);
	void GetElementsForTaxonGroup(UnicodeString TaxaGroupID, set<UnicodeString>& ElementList);
	void GetAllModifiers(map<UnicodeString, map<UnicodeString, ELEMENTMODIFIERS> >&  AllModifiers);
};
//---------------------------------------------------------------------------

class UNITLOOKUP;
class CONTEXTLOOKUP;
class TAPHONOMYLOOKUP;
//---------------------------------------------------------------------------

class MODIFIERLOOKUP : public TStringList
{
private:
  UnicodeString PathName;
public:
  __fastcall MODIFIERLOOKUP();
  __fastcall ~MODIFIERLOOKUP();
  UnicodeString GetPathName(void) { return PathName; }
  void SetPathName(UnicodeString& pn) { PathName = pn; }
};
//---------------------------------------------------------------------------

class UNITLOOKUP : public MODIFIERBASE
{
public:
  map<UnicodeString, set<UnicodeString> > Units;    // DatasetType, Units
public:
  bool Load(const UnicodeString, TipwXMLp*, bool);
  void Assign(UnicodeString DatasetType, TStrings* Strings);
};
//---------------------------------------------------------------------------

class CONTEXTLOOKUP : public MODIFIERBASE
{
public:
  map<UnicodeString, set<UnicodeString> > Contexts;
public:
  bool Load(const UnicodeString, TipwXMLp*, bool);
  void Assign(UnicodeString DatasetType, TStrings* Strings);
};
//---------------------------------------------------------------------------

// <Taphonomy DatasetType="pollen">
//   <TaphonomicSystem System="Neotoma Pollen">
//     <TaphonomicType>1/2 grains</TaphonomicType>

typedef map<UnicodeString, set<UnicodeString> > TAPHONOMICSYSTEM;   // system, set of types
//---------------------------------------------------------------------------

class TAPHONOMYLOOKUP : public MODIFIERBASE
{
public:
  map<UnicodeString, TAPHONOMICSYSTEM> DatasetType;   // DatasetType, TAPHONOMICSYSTEM
public:
  TAPHONOMYLOOKUP() { }
  TAPHONOMYLOOKUP(TAPHONOMYLOOKUP* tl) { DatasetType = tl->DatasetType; PathName = tl->PathName; }
  bool Load(const UnicodeString, TipwXMLp*, bool);
  void Add(UnicodeString DatasetType, UnicodeString System);
  void Add(UnicodeString DatasetType, UnicodeString System, UnicodeString Type);
  bool DatasetTypeExists(UnicodeString DatasetTypeName);
  bool SystemExists(UnicodeString DatasetTypeName, UnicodeString TaphonomicSystem);
  bool TypeExists(UnicodeString DatasetTypeName, UnicodeString TaphonomicSystem, UnicodeString Type);
  void GetSystems(UnicodeString DatasetTypeName, set<UnicodeString>& Systems);
  void GetTypes(UnicodeString DatasetTypeName, UnicodeString TaphonomicSystem, set<UnicodeString>& Types);
};
//---------------------------------------------------------------------------

class VARIABLELOOKUP
{
private:
  ELEMENTLOOKUP* ElementLookup;
  UNITLOOKUP* UnitLookup;
  CONTEXTLOOKUP* ContextLookup;
  TAPHONOMYLOOKUP* TaphonomyLookup;
public:
  VARIABLELOOKUP() { ElementLookup = NULL; UnitLookup = NULL;
                     ContextLookup = NULL; TaphonomyLookup = NULL; }
  void SetElementLookup(ELEMENTLOOKUP* el) { ElementLookup = el; }
  void SetUnitLookup (UNITLOOKUP* un) { UnitLookup = un; }
  void SetContextLookup (CONTEXTLOOKUP* co) { ContextLookup = co; }
  void SetTaphonomyLookup (TAPHONOMYLOOKUP* ta) { TaphonomyLookup = ta; }
  bool ElementOpen(void) { return (ElementLookup != NULL); }
  bool UnitOpen(void) { return (UnitLookup != NULL); }
  bool ContextOpen(void) { return (ContextLookup != NULL); }
  bool TaphonomyOpen(void) { return (TaphonomyLookup != NULL); }
  bool ElementsLoaded(void);
  bool UnitsLoaded(void);
  bool ContextsLoaded(void);
  bool TaphonomyLoaded(void);
  UnicodeString GetElementPath(void);
  UnicodeString GetUnitPath(void);
  UnicodeString GetContextPath(void);
  UnicodeString GetTaphonomyPath(void);
  void SetElementPath(UnicodeString);
  void SetUnitPath(UnicodeString);
  void SetContextPath(UnicodeString);
  void SetTaphonomyPath(UnicodeString);
  ELEMENTLOOKUP* GetElementLookup(void) { return ElementLookup; }
  UNITLOOKUP* GetUnitLookup(void) { return UnitLookup; }
  CONTEXTLOOKUP* GetContextLookup(void) { return ContextLookup; }
  TAPHONOMYLOOKUP* GetTaphonomyLookup(void) { return TaphonomyLookup; }
};
//---------------------------------------------------------------------------

bool SaveVariableModifiers(int, UnicodeString&, VARIABLELOOKUP*, TComponent*);

*/
#endif


