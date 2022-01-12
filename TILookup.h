//---------------------------------------------------------------------------

#ifndef TILookupH
#define TILookupH
#include <ComCtrls.hpp>
#include <Math.hpp>
#ifndef TIXMLH
#include "TIXML.h"
#endif

//---------------------------------------------------------------------------

class GEOPOLITICALXML
{
public:
   UnicodeString XText;
   bool GeoPolitical;
   bool GeoPoliticalName;
   bool GeoPoliticalUnit;
   bool Rank;
   bool HigherGeoPoliticalID;
public:
   GEOPOLITICALXML() {
	 GeoPolitical = false;
	 GeoPoliticalUnit = false;
	 GeoPoliticalName = false;
	 Rank = false;
	 HigherGeoPoliticalID = false;
	 }
};
//---------------------------------------------------------------------------

typedef struct
{
  UnicodeString Parameter;
  map<int,UnicodeString> Categories;
} GEOCHRONPARAM;
//---------------------------------------------------------------------------

/*
typedef struct
{
  UnicodeString Type;
  vector<GEOCHRONPARAM> Parameters;
} GEOCHRONTYPE;
//---------------------------------------------------------------------------
*/

typedef struct {
  int ID;
  int HigherID;
  UnicodeString Name;
} TREENODE;
//---------------------------------------------------------------------------

typedef struct {
  int ID;
  int HigherID;
  UnicodeString RockType;
  UnicodeString Description;
} SUBSTRATE;
//---------------------------------------------------------------------------

class RELATIVEAGE : TObject
{
public:
  double C14AgeYounger;
  double C14AgeOlder;
  double CalAgeYounger;
  double CalAgeOlder;
  double ArchAgeScaleID;
public:
  RELATIVEAGE() { C14AgeYounger = NaN; C14AgeOlder = NaN;
                  CalAgeYounger = NaN; CalAgeOlder = NaN; }
  bool AgesSet() { return (!(IsNan(C14AgeYounger) && IsNan(C14AgeOlder) &&
                             IsNan(CalAgeYounger) && IsNan(CalAgeOlder))); }
  void XMLOut(WriteXML*);
};
//---------------------------------------------------------------------------

class EVENT : TObject
{
public:
  UnicodeString Name;
  double C14Age;
  double C14AgeYounger;
  double C14AgeOlder;
  double CalAge;
  double CalAgeYounger;
  double CalAgeOlder;
  UnicodeString Notes;
public:
  EVENT() { C14Age = NaN; C14AgeYounger = NaN; C14AgeOlder = NaN;
			CalAge = NaN; CalAgeYounger = NaN; CalAgeOlder = NaN; }
  bool AgesSet() { return (!(IsNan(C14Age) && IsNan(C14AgeYounger) &&
							 IsNan(C14AgeOlder) && IsNan(CalAge) &&
							 IsNan(CalAgeYounger) &&  IsNan(CalAgeOlder))); }
  void XMLOut(WriteXML*);
};
//---------------------------------------------------------------------------

typedef struct
{
  UnicodeString EventType;
  UnicodeString ChronControl;
  UnicodeString SortType;
  UnicodeString EventName;
} XMLEVENT;
//---------------------------------------------------------------------------

class CHRONCONTROL
{
public:
  int ID;
  int HigherID;
  bool AddedToTree;
public:
  CHRONCONTROL() { AddedToTree = false; }
};
//---------------------------------------------------------------------------

class GEOPOLRECORD
{
public:
  int ID;
  UnicodeString Name;
  UnicodeString Unit;
  int Rank;
  int HigherID;
  GEOPOLRECORD* HigherRec;
  TList* SubUnits;
  TList* AdminUnits;
public:
  GEOPOLRECORD() { HigherRec = NULL; SubUnits = new TList; AdminUnits = new TList; }
  ~GEOPOLRECORD() { delete SubUnits; delete AdminUnits; }
};
//---------------------------------------------------------------------------

class GEOPOLITICAL
{
private:
   void __fastcall FindID(int, GEOPOLRECORD**);
   TList* GP;
   TList* GP1;
   TList* GP2;
   TList* GP3;
   GEOPOLRECORD* GeoPolRecord1;
   GEOPOLRECORD* GeoPolRecord2;
   GEOPOLRECORD* GeoPolRecord3;
   GEOPOLRECORD* GeoPolRecord4;
   int HighestID;
private:
   void GetAdminUnits(GEOPOLRECORD*, TStringList*);
public:
   GEOPOLITICAL();
   ~GEOPOLITICAL();
   void AddGeoPol(GEOPOLRECORD*);
   int GetNextID(void);
   void GeoPol1(TStrings*);
   void GeoPol2(UnicodeString, TStrings*);
   void GeoPol3(UnicodeString, TStrings*);
   void GeoPol4Unit1(UnicodeString, TStrings*);
   void GeoPol4Unit2(UnicodeString, TStrings*);
   void GeoPol4Unit3(UnicodeString, TStrings*);
   void SetGeoPolRec1(UnicodeString);
   void SetGeoPolRec2(UnicodeString);
   void SetGeoPolRec3(UnicodeString);
   bool SetGeoPolRec4(UnicodeString);
   UnicodeString GetUnit1(void);
   UnicodeString GetUnit2(void);
   UnicodeString GetUnit3(void);
   UnicodeString GetUnit4(void);
   UnicodeString GetUnitForGeoPol2(UnicodeString);
   UnicodeString GetUnitForGeoPol3(UnicodeString);
   void AddAdminUnit1(UnicodeString, UnicodeString);
   void AddAdminUnit2(TStringList*, UnicodeString, UnicodeString);
   void AddAdminUnit3(TStringList*, UnicodeString, UnicodeString);
   void Save(void);
   bool SetGeoPol2(void);
   bool SetGeoPol3(void);
   int GPCount(void) { return GP->Count; }
   GEOPOLRECORD* GetGPRec(int i) { return ((i < GP->Count) ? (GEOPOLRECORD*)GP->Items[i] : NULL); }
   GEOPOLRECORD* FindGPName(UnicodeString);
};
//---------------------------------------------------------------------------

#endif
