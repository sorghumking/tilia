//---------------------------------------------------------------------------

#ifndef TICommonH
#define TICommonH
//---------------------------------------------------------------------------
#include <vcl.h>
#include "pch.h"
#include <Classes.hpp>
#include <ComCtrls.hpp>
#include "ProfGrid.hpp"
#include "ipwCore.h"
#include "ipwxmlp.h"
#include <vector>
#include <map>
#include <set>
#include <vector>
#include <ADODB.hpp>
#ifndef TIPubH
#include "TIPub.h"
#endif
#ifndef TIUtilsH
#include "TIUtils.h"
#endif

//---------------------------------------------------------------------------
enum CELLOBJECTTYPES { CELLTAXONNOTES, CELLSITE, CELLCONTACTS, CELLPUBLICATIONS, CELLTAPHONOMY, CELLSPECIMENS };
enum isoIMPORT { isoINSERT, isoAPPEND };
enum isoDATASET { isoCarbon, isoNitrogen, isoOxygen, isoSulfur, isoHydrogen, isoStrontium,
				  isoCNratio, isoOHratio };
enum MODTYPES { MOD_ELEMENT, MOD_UNIT, MOD_CONTEXT, MOD_TAPHONOMY };
enum VALIDATIONLEVEL { valERROR, valWARNING };
enum diagramTYPE { dtCustom, dtDefault };
//---------------------------------------------------------------------------

class TTilSpreadSheetForm;
class AGEMODEL;
class CHRON;
class GEOCHRON;
class TGeochronList;
class TGeochronDataSource;
class TTaxonDatedDataSource;
class TAgeModelList;
class TAgeModelDataSource;
class TChronDataSource;
//---------------------------------------------------------------------------

class IntlStrToDouble
{
private:
  static short DecimalSeparator;
public:
  static void SetDecimalSeparator(void);
  static double GetDouble(UnicodeString&);
  static double GetDouble(UnicodeString*);
  static double GetDouble(UnicodeString&, double);
  static double GetDouble(UnicodeString*, double);
  static UnicodeString XMLDouble(UnicodeString);
};
//---------------------------------------------------------------------------

short IntlStrToDouble::DecimalSeparator;
//---------------------------------------------------------------------------

class DiagramParams
{
private:
	vector<pair<UnicodeString,bool> > FVarNames;   // VarName, Show
	TProfGrid* FProfGrid;
	UnicodeString FFileName;
	UnicodeString FHeading;
public:
	DiagramParams() { };
	DiagramParams(UnicodeString filename) { FFileName = filename; FProfGrid = NULL; }
	DiagramParams(UnicodeString filename, TProfGrid* profgrid)
		{ FFileName = filename; FProfGrid = profgrid; }
	__property vector<pair<UnicodeString,bool> > VarNames = {read = FVarNames, write = FVarNames};
	__property TProfGrid* ProfGrid = {read = FProfGrid, write = FProfGrid};
	__property UnicodeString FileName = {read = FFileName, write = FFileName};
	__property UnicodeString Heading = {read = FHeading, write = FHeading};
};
//---------------------------------------------------------------------------

class XMLSubElement
{
private:
   UTF8String ElementPath;
public:
   XMLSubElement(UTF8String xpath) { ElementPath = xpath; }
   UTF8String __fastcall XPath(int);
};
//---------------------------------------------------------------------------

class XMLATTR
{
public:
  UTF8String Name;
  UTF8String Value;
public:
  XMLATTR(UTF8String name) { Name = name; }
  XMLATTR(UTF8String name, UTF8String value) { Name = name; Value = value; }
};
//---------------------------------------------------------------------------

class ParseXMLUnicode
{
private:
  TipwXMLp* ipwXMLp;
public:
  ParseXMLUnicode(TipwXMLp* ipwxmlp);  // { ipwXMLp = ipwxmlp; }
  UnicodeString RootElement(void);
  bool __fastcall ValidChild(UTF8String, UTF8String);
  bool __fastcall ValidChild(UTF8String, UTF8String, int&);
  bool __fastcall GetTextValue(UTF8String XPath, UnicodeString& Value);
  bool __fastcall GetTextValue(UTF8String, UTF8String, UnicodeString&);
  bool __fastcall GetBoolValue(UTF8String, UTF8String, bool&);
  bool __fastcall GetDoubleValue(UTF8String, UTF8String, double&);
  bool __fastcall GetIntValue(UTF8String, UTF8String, int&);
  bool __fastcall GetIntValue(UTF8String, UTF8String, Variant&);
  bool __fastcall GetChildText(int, UnicodeString&);
  bool __fastcall GetAttrInt(UTF8String, int&);
  bool __fastcall GetAttrInt(UTF8String, UTF8String, int&);
  bool __fastcall GetAttrStr(UTF8String, UTF8String, UnicodeString&);
  int __fastcall XChildrenCount(void);
  bool __fastcall SetXPath(UTF8String);
  UnicodeString __fastcall GetChildName(int);
  UnicodeString __fastcall GetElementName(UTF8String);
};
//---------------------------------------------------------------------------

class WriteXML
{
private:
	UnicodeString FileName;
	TFileStream* TempFileStream;
	UnicodeString TempFileName;
	TStreamWriter* writer;
	short BoolStyle;
public:
	WriteXML(UnicodeString);
	~WriteXML();
	void SetBoolStyle(int bs) { BoolStyle = bs; }
	void Declaration(UnicodeString, UnicodeString, UnicodeString);
	void BeginTag(UnicodeString);
	void BeginTag(UnicodeString, UnicodeString, int);
	void BeginTag(UnicodeString, UnicodeString, UnicodeString);
	void BeginTag(UnicodeString, UnicodeString, int, UnicodeString, UnicodeString);
	void BeginTag(UnicodeString, UnicodeString, int, UnicodeString, int);
	void BeginTag(UnicodeString, UnicodeString, UnicodeString, UnicodeString, UnicodeString);
	void BeginTag(UnicodeString, UnicodeString, UnicodeString, UnicodeString, int);
	void BeginTag(UnicodeString, list<XMLATTR>&);
	void EndTag(UnicodeString);
	void Comment(UnicodeString);
	void DateTime(void);
	void Element(UnicodeString, UnicodeString);
	void Element(UnicodeString, WideString);
	void Element(UnicodeString, Variant);
	void Element(UnicodeString, int);
	void Element(UnicodeString, unsigned int);
	void Element(UnicodeString, double);
	void Element(UnicodeString, long double);
	void Element(UnicodeString, bool);
	void Element(UnicodeString, UnicodeString, int, UnicodeString);
	void ElementAttr(UnicodeString, double, UnicodeString, bool, UnicodeString, bool);
	void EmptyElement(UnicodeString);
	void EmptyElement(UnicodeString, UnicodeString, int);
	void EmptyElement(UnicodeString, UnicodeString, UnicodeString);
	void EmptyElement(UnicodeString, UnicodeString, UnicodeString, UnicodeString, int);
	void CDATA(UnicodeString, UnicodeString);
	void Finish(void);
};
//---------------------------------------------------------------------------

// <Taphonomy DatasetType="pollen">
//   <TaphonomicSystem System="Neotoma Pollen">
//     <TaphonomicType>1/2 grains</TaphonomicType>

typedef map<UnicodeString, set<UnicodeString> > TAPHONOMICSYSTEM;   // system, set of types
//---------------------------------------------------------------------------

typedef struct
{
  UnicodeString SiteName;
  Variant LatDD;
  Variant LonDD;
  Variant Elevation;
  Variant AreaOfSite;
  UnicodeString PolDiv1;
  UnicodeString PolDiv2;
  UnicodeString PolDiv3;
  UnicodeString UseStatus;
} EPDSITELOC;
//---------------------------------------------------------------------------

typedef struct
{
  int PublNr;  // Publ#
  UnicodeString YearOfPubl;
  UnicodeString Citation;
} EPDPUBL;
//---------------------------------------------------------------------------

typedef struct
{
  UnicodeString Name;
  double Value;
} LAKEPARAM;
//---------------------------------------------------------------------------

class SUBMISSION
{
public:
  bool Archived;
  UnicodeString SubmittedForm;
  UnicodeString SubmissionType;
  double SubmissionDate;             // fill out when contributed
  UnicodeString Notes;                  // fill out when contributed
  //TList *Submitters;                 // fill out when contributed
  vector<CONTACT*> Submitters;
  UnicodeString SubmittersComboBoxText;
public:
  SUBMISSION();
  SUBMISSION(UnicodeString&);
  ~SUBMISSION();
};
//---------------------------------------------------------------------------

class DATASETSUBMISSION
{
public:
	int DatasetID;
	int DatabaseID;
	int SubmissionTypeID;
	UnicodeString Notes;
public:
	DATASETSUBMISSION() { DatasetID = -1; }
};
//---------------------------------------------------------------------------

class LAKEPARAMETER
{
public:
   UnicodeString Code;
   UnicodeString Name;
   UnicodeString Menu;
public:
   LAKEPARAMETER(UnicodeString code, UnicodeString name, UnicodeString menu)
     { Code = code; Name = name; Menu = menu; }
};
//---------------------------------------------------------------------------

class DATASET
{
public:
  int NeotomaDatasetTypeID;
  int NeotomaDatasetID;
  int NeotomaDatabaseID;
  int NeotomaSubmissionTypeID;
  UnicodeString NeotomaSubmissionNotes;
  UnicodeString DatasetType;
  UnicodeString Name;
  UnicodeString Notes;
  UnicodeString AggregateOrder;
  bool IsSSamp;
  bool IsAggregate;
  int WhitmoreID1;
  bool WhitmoreData;
  vector<SUBMISSION> Submissions;
  vector<CONTACT*> Investigators;
  vector<CONTACT*> Processors;
  vector<PUBLICATION*> Publications;
  vector<REPOSITORY> Repositories;
public:
  UnicodeString RepositoryText();
  void operator = (const DATASET& copy);
public:
  DATASET() { IsSSamp = false; IsAggregate = false; WhitmoreID1 = -1; WhitmoreData = false;
			  NeotomaDatasetTypeID = -1; NeotomaDatasetID = -1; NeotomaDatabaseID = -1;
			  NeotomaSubmissionTypeID = -1; };
};
//---------------------------------------------------------------------------

class COLLECTION
{
public:
  vector<DATASET> NeotomaDatasets;
  int NeotomaCollUnitID;          // for upload to Neotoma
  int NeotomaCollTypeID;
  int NeotomaDepEnvtID;
  int NeotomaRockTypeID;
  // int WhitmoreID1;
  UnicodeString NeotomaHandle;
  UnicodeString CollectionType;
  UnicodeString DepEnv;
  UnicodeString Substrate;
  UnicodeString Handle;
  UnicodeString CollectionName;
  UnicodeString Location;
  UnicodeString CollectionDevice;
  UnicodeString Notes;
  Variant GPSLat;
  Variant GPSLong;
  Variant GPSError;
  Variant GPSAltitude;
  Variant CollDate;
  Variant WaterDepth;
  Variant SlopeAngle;
  Variant SlopeAspect;
  vector<CONTACT*> Collectors;   // keyed to contacts list
public:
  COLLECTION();
};
//---------------------------------------------------------------------------

class SITE
{
public:
  map<int,int> NeotomaGeoPolID;        // for upload to Neotoma
  map<int,double> NeotomaLakeParams;   // for upload to Neotoma
  int NeotomaSiteID;                   // for upload to Neotoma
  UnicodeString SiteName;
  Variant LongEast;
  Variant LongWest;
  Variant LatNorth;
  Variant LatSouth;
  Variant Altitude;
  Variant Area;
  UnicodeString Country;
  UnicodeString State;
  UnicodeString County;
  UnicodeString AdminUnit;
  UnicodeString SiteDescription;
  UnicodeString Notes;
  vector<LAKEPARAM> LakeParams;
  vector<COLLECTION> CollUnits;
public:
  SITE();
  SITE(SITE* site);
  bool SameSite(SITE* site);
};
//---------------------------------------------------------------------------

class SPECIMEN
{
private:
	int FSpecimenID;
	int FSampleID;   // local SampleID to which the specimen is assigned
	int FNeotomaSpecimenID;
	int FNeotomaAnalysisUnitID;
	int FDataID;     // is this needed?
	int FNeotomaDataID;
	int FNeotomaElementID;
	int FNeotomaSymmetryID;
	int FNeotomaPortionID;
	int FNeotomaMaturityID;
	int FNeotomaSexID;
	int FNeotomaDomesticStatusID;
	int FNeotomaRepositoryID;
	set<int> FNeotomaTaphonomy;  // TaphonomicSystemID, TaphonomicTypeID
	UnicodeString FTaxaGroup;
	UnicodeString FUserSpecimenID;
	UnicodeString FTaxon;
	UnicodeString FElement;
	UnicodeString FSymmetry;
	UnicodeString FPortion;
	UnicodeString FMaturity;
	UnicodeString FSex;
	UnicodeString FDomesticStatus;
	UnicodeString FPreservative;
	Variant FNISP;
	UnicodeString FRepository;
	UnicodeString FSpecNr;
	UnicodeString FFieldNr;
	UnicodeString FArctosNr;
	set<UnicodeString> FGenBankNrs;
	UnicodeString FNotes;
	TAPHONOMICSYSTEM FTaphonomy;
public:
	SPECIMEN();
	SPECIMEN(SPECIMEN* sp);
	void operator = (const SPECIMEN& copy);
	bool operator == (const SPECIMEN& compare);
	__property int SpecimenID = {read = FSpecimenID, write = FSpecimenID};
	__property int SampleID = {read = FSampleID, write = FSampleID};
	__property int NeotomaSpecimenID = {read = FNeotomaSpecimenID, write = FNeotomaSpecimenID};
	__property int NeotomaAnalysisUnitID = {read = FNeotomaAnalysisUnitID, write = FNeotomaAnalysisUnitID};
	__property int DataID = {read = FDataID, write = FDataID};
	__property int NeotomaDataID = {read = FNeotomaDataID, write = FNeotomaDataID};
	__property int NeotomaElementID = {read = FNeotomaElementID, write = FNeotomaElementID};
	__property int NeotomaSymmetryID = {read = FNeotomaSymmetryID, write = FNeotomaSymmetryID};
	__property int NeotomaPortionID = {read = FNeotomaPortionID, write = FNeotomaPortionID};
	__property int NeotomaMaturityID = {read = FNeotomaMaturityID, write = FNeotomaMaturityID};
	__property int NeotomaSexID = {read = FNeotomaSexID, write = FNeotomaSexID};
	__property int NeotomaDomesticStatusID = {read = FNeotomaDomesticStatusID, write = FNeotomaDomesticStatusID};
	__property int NeotomaRepositoryID = {read = FNeotomaRepositoryID, write = FNeotomaRepositoryID};
	__property UnicodeString TaxaGroup = {read = FTaxaGroup, write = FTaxaGroup};
	__property UnicodeString UserSpecimenID = {read = FUserSpecimenID, write = FUserSpecimenID};
	__property UnicodeString Taxon = {read = FTaxon, write = FTaxon};
	__property UnicodeString Element = {read = FElement, write = FElement};
	__property UnicodeString Symmetry = {read = FSymmetry, write = FSymmetry};
	__property UnicodeString Portion = {read = FPortion, write = FPortion};
	__property UnicodeString Maturity = {read = FMaturity, write = FMaturity};
	__property UnicodeString Sex = {read = FSex, write = FSex};
	__property UnicodeString DomesticStatus = {read = FDomesticStatus, write = FDomesticStatus};
	__property UnicodeString Preservative = {read = FPreservative, write = FPreservative};
	__property Variant NISP = {read = FNISP, write = FNISP};
	__property UnicodeString Repository = {read = FRepository, write = FRepository};
	__property UnicodeString SpecNr = {read = FSpecNr, write = FSpecNr};
	__property UnicodeString FieldNr = {read = FFieldNr, write = FFieldNr};
	__property UnicodeString ArctosNr = {read = FArctosNr, write = FArctosNr};
	__property set<UnicodeString> GenBankNrs = {read = FGenBankNrs, write = FGenBankNrs};
	__property UnicodeString Notes = {read = FNotes, write = FNotes};
	__property TAPHONOMICSYSTEM Taphonomy = {read = FTaphonomy, write = FTaphonomy};
	__property set<int> NeotomaTaphonomy = {read = FNeotomaTaphonomy, write = FNeotomaTaphonomy};
};
//---------------------------------------------------------------------------

class TAXONDATED
{
public:
  int NeotomaSpecimenDateID;
  UnicodeString UserSpecID;
  SPECIMEN* Specimen;
  UnicodeString Taxon;
  UnicodeString Element;
  UnicodeString Fraction;
  Variant CalAgeMedian;
  Variant CalAgeOlder;
  Variant CalAgeYounger;
  UnicodeString CalibCurve;
  CALIBRATION Calib;
  UnicodeString Notes;
public:
  TAXONDATED() { NeotomaSpecimenDateID = -1; CalAgeOlder = Unassigned();
				 CalAgeYounger = Unassigned(); Specimen = NULL; }
};
//---------------------------------------------------------------------------

class GEOCHRON
{
private:
  int FID;
  int FNeotomaGeochronID;
  int FNeotomaAnalUnitID;
public:
  UnicodeString Method;
  UnicodeString AgeUnits;
  Variant Depth;
  Variant Thickness;
  UnicodeString AnalUnit;
  UnicodeString LabNumber;
  Variant Age;
  Variant ErrorOlder;
  Variant ErrorYounger;
  int Sigma;
  Variant StdDev;
  bool GreaterThan;
  map<UnicodeString,Variant> Parameters;
  UnicodeString MaterialDated;
  vector<PUBLICATION*> publications;
  UnicodeString PubComboBoxText;
  UnicodeString Notes;
  vector<TAXONDATED> TaxaDated;
public:
  GEOCHRON();
  void Clear(void);
  void SetID(int id) { FID = id; }
  __property int ID = {read = FID};
  __property int NeotomaGeochronID = {read = FNeotomaGeochronID, write = FNeotomaGeochronID};
  __property int NeotomaAnalUnitID = {read = FNeotomaAnalUnitID, write = FNeotomaAnalUnitID};
};
//---------------------------------------------------------------------------

class SYNONYMY
{
public:
  int NeotomaSynonymyID;
  UnicodeString TaxonName;
  bool Contrib;
  int PubID;  // used for tlxin
  PUBLICATION* Pub;
  UnicodeString Notes;
public:
  SYNONYMY() { NeotomaSynonymyID = -1; Contrib = false; PubID = -1; Pub = NULL; }
  SYNONYMY(UnicodeString name) { TaxonName = name; NeotomaSynonymyID = -1; Contrib = false; PubID = -1; Pub = NULL; }
  void Clear(void) { TaxonName = L""; NeotomaSynonymyID = -1; Contrib = false; Pub = NULL; Notes = L""; PubID = -1; }
  int NeotomaPubID(void);
};
//---------------------------------------------------------------------------

class TAXON_NOTES
{
public:
  UnicodeString Notes;
  vector<SYNONYMY> Synonymy;
public:
  TAXON_NOTES() { }
  TAXON_NOTES(TAXON_NOTES* tn) { Notes = tn->Notes; Synonymy = tn->Synonymy; }
  void operator = (const TAXON_NOTES& copy);
};
//---------------------------------------------------------------------------

class TAPHSYSTEM
{
public:
  UnicodeString Name;
  set<UnicodeString> Types;
public:
  bool TypesEqual(TAPHSYSTEM& compare);
  void AddTypes(TAPHSYSTEM& source);
};
//---------------------------------------------------------------------------

class TAPHSYSTEMS
{
public:
  UnicodeString DatasetType;
  vector<TAPHSYSTEM> Systems;
public:
  TAPHSYSTEMS() { };
  TAPHSYSTEMS(TAPHSYSTEMS* ts);
  UnicodeString Text(void);
  void RemoveType(UnicodeString System, UnicodeString Type);
  void RemoveSystem(UnicodeString System);
  void AddType(UnicodeString System, UnicodeString Type);
};
//---------------------------------------------------------------------------

class CELLOBJECT
{
private:
	int FObjectType;
	int FNeotomaDataID;
	TObject* FObject;
public:
	CELLOBJECT() { FObject = NULL; FNeotomaDataID = -1; FObjectType = -1; }
    CELLOBJECT(int object_type);
	CELLOBJECT(CELLOBJECT* cell_object);
	CELLOBJECT(TAPHSYSTEMS* ts) { FObject = (TObject*)ts; FNeotomaDataID = -1; FObjectType = CELLTAPHONOMY;}
	CELLOBJECT(SITE* site) { FObject = (TObject*)site; FNeotomaDataID = -1; FObjectType = CELLSITE; }
	~CELLOBJECT();
	void operator = (const CELLOBJECT& copy);
	__property int ObjectType = {read = FObjectType, write = FObjectType};
	__property int NeotomaDataID = {read = FNeotomaDataID, write = FNeotomaDataID};
	__property TObject* Object = {read = FObject, write = FObject};
};
//---------------------------------------------------------------------------

class NEOTOMAVARIABLEPARTS
{
private:
	UnicodeString FTaxonName;
	UnicodeString FElement;
	UnicodeString FUnits;
	UnicodeString FContext;
	int FTaxonID;
	int FElementID;
	int FUnitsID;
	int FContextID;
	int FVariableID;
public:
	NEOTOMAVARIABLEPARTS() { FTaxonID = -1; FElementID = -1;
		FUnitsID = -1; FContextID = -1; FVariableID = -1; }
	__property UnicodeString TaxonName = {read = FTaxonName, write = FTaxonName};
	__property UnicodeString Element = {read = FElement, write = FElement};
	__property UnicodeString Units = {read = FUnits, write = FUnits};
	__property UnicodeString Context = {read = FContext, write = FContext};
	__property int TaxonID = {read = FTaxonID, write = FTaxonID};
	__property int ElementID = {read = FElementID, write = FElementID};
	__property int UnitsID = {read = FUnitsID, write = FUnitsID};
	__property int ContextID = {read = FContextID, write = FContextID};
	__property int VariableID = {read = FVariableID, write = FVariableID};
};
//---------------------------------------------------------------------------

class ISOTOPESERIES
{
public:
	int NumberOfSamples;
	UnicodeString SamplingOrigin;
	UnicodeString SampleDistUnits;
	Variant SampleInterval;
	Variant TransectWidth;
	Variant DrillBitSize;
	UnicodeString SampledBiolMarker;
public:
	ISOTOPESERIES() { NumberOfSamples = 0; }
	ISOTOPESERIES(ISOTOPESERIES& ser) { NumberOfSamples = ser.NumberOfSamples;
		SamplingOrigin = ser.SamplingOrigin; SampleDistUnits = ser.SampleDistUnits;
		SampleInterval = ser.SampleInterval; TransectWidth = ser.TransectWidth;
		DrillBitSize = ser.DrillBitSize; SampledBiolMarker = ser.SampledBiolMarker;  }
	void Update(ISOTOPESERIES& ser) { NumberOfSamples = ser.NumberOfSamples;
		SamplingOrigin = ser.SamplingOrigin; SampleDistUnits = ser.SampleDistUnits;
		SampleInterval = ser.SampleInterval; TransectWidth = ser.TransectWidth;
		DrillBitSize = ser.DrillBitSize; SampledBiolMarker = ser.SampledBiolMarker;  }
};
//---------------------------------------------------------------------------

class ISOMETADATA
{
public:
	int IsoInstrumentationTypeID;
	int IsoSampleIntroSystemTypeID;
	vector<pair<int,double> > IsoStandards;  // IsoStandardTypeID, Value
	Variant TechError;
	Variant TechErrorSD;
	Variant LongTermError;
	UnicodeString Instrument;
	UnicodeString IntroSystem;
	vector<pair<UnicodeString,Variant> > Standards;
	Variant SrLocalValue;
	Variant SrLocalValueSD;
	UnicodeString SrLocalGeolContext;
	UnicodeString Notes;
public:
	ISOMETADATA() { IsoInstrumentationTypeID = -1; IsoSampleIntroSystemTypeID = -1; }
	bool IsEmpty(void);
};
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

class SPECIMENDATETAXAGROUPS
{
private:
	map<UnicodeString,int> TaxaGroupDatasetType;  // TaxaGroupID, DatasetTypeID
public:
	SPECIMENDATETAXAGROUPS();
	int GetDatasetTypeID(UnicodeString TaxaGroupID);
	bool IsTaxaGroupInDatasetType(UnicodeString TaxaGroupID, int DatasetTypeID);
};
//---------------------------------------------------------------------------

bool SaveVariableModifiers(int, UnicodeString&, VARIABLELOOKUP*, TComponent*);
//---------------------------------------------------------------------------

class FSUM
{
public:
  UnicodeString Code;
  UnicodeString Name;
  UnicodeString Base;
  bool Percent;
  bool Skip;
  int Row;

public:
  FSUM() { Percent=true; Skip=false; }
  FSUM(UnicodeString& code) { Code = code; Percent=true; Skip=false; }
  FSUM(UnicodeString code, UnicodeString name, UnicodeString base)
    { Code = code; Name = name; Base = base; Percent=true; Skip=false; }
};
//---------------------------------------------------------------------------

class SUPERSUM
{
public:
  UnicodeString Code;
  UnicodeString Name;
  UnicodeString Sums;
  int Row;

public:
  SUPERSUM() {}
};
//---------------------------------------------------------------------------

class TSumList : public TList
{
private:
	::TcxNotifyEvent FOnNotify;
	void ReleaseAllSums();
	void ReleaseSum(int AIndex);
	FSUM* GetSum(int AIndex);
protected:
	void __fastcall Notify(void * Ptr, TListNotification Action);
public:
	TSumList() {}
	__fastcall ~TSumList() {}
	void __fastcall Clear(void);
	void Add(FSUM* Sum);
	void Delete(int AIndex);
	void Insert(int AIndex, FSUM* Sum);
	__property Items;
	__property FSUM* Sums[int Index] = {read = GetSum};
	__property ::TcxNotifyEvent OnNotify = {read=FOnNotify, write=FOnNotify};
};
//---------------------------------------------------------------------------

class TSuperSumList : public TList
{
private:
	::TcxNotifyEvent FOnNotify;
	void ReleaseAllSuperSums();
	void ReleaseSuperSum(int AIndex);
	SUPERSUM* GetSuperSum(int AIndex);
protected:
	void __fastcall Notify(void * Ptr, TListNotification Action);

public:
	TSuperSumList() {}
	__fastcall ~TSuperSumList() {}
	void __fastcall Clear(void);
	void Add(SUPERSUM* SuperSum);
	void Delete(int AIndex);
	void Insert(int AIndex, SUPERSUM* SuperSum);
	__property Items;
	__property SUPERSUM* SuperSums[int Index] = {read = GetSuperSum};
	__property ::TcxNotifyEvent OnNotify = {read=FOnNotify, write=FOnNotify};
};
//---------------------------------------------------------------------------

class SUMVARIABLE
{
public:
  UnicodeString Name;
  UnicodeString Base;
  bool Valid;
public:
  SUMVARIABLE(UnicodeString name, char base, bool valid) { Name = name; Base = base; Valid = valid; }
  SUMVARIABLE(){};
};
//---------------------------------------------------------------------------

class SUPERSUMVARIABLE
{
public:
  UnicodeString Code;
  UnicodeString Name;
  vector<UnicodeString> Base;
public:
  SUPERSUMVARIABLE(UnicodeString code, UnicodeString name){ Code = code; Name = name; };
  SUPERSUMVARIABLE(){};
};
//---------------------------------------------------------------------------

class SUMS
{
private:
	TSumList *SumList;
public:
	map<UnicodeString, SUMVARIABLE> SVar;
	vector<SUPERSUMVARIABLE> SSVar;
	vector<UnicodeString> UsedBases;
	bool ValidCodes;
public:
	SUMS(TSumList *sumlist, set<UnicodeString>& ValidElements,
	  map<int,pair<UnicodeString,UnicodeString> >& ElementGroupCodes,
	  UnicodeString InvalidGroup);
};
//---------------------------------------------------------------------------

class Access
{
private:
   UnicodeString ConnectionString;
   TADOConnection *ADOConnection1;
   UnicodeString FileName;
public:
   Access(TADOConnection *ado, UnicodeString fn);
   ~Access();
   bool Connect(void);
   bool Disconnect(void);
};
//---------------------------------------------------------------------------

class ANALUNIT
{
private:
	Variant FDepth;
	Variant FThickness;
	Variant FName;
public:
	ANALUNIT() {FDepth = Unassigned(); FThickness = Unassigned(); FName = Unassigned(); }
	__property Variant Depth = {read = FDepth, write = FDepth};
	__property Variant Thickness = {read = FThickness, write = FThickness};
	__property Variant Name = {read = FName, write = FName};
	bool operator == (const ANALUNIT& compare);
};
//---------------------------------------------------------------------------

class NEOTOMAANALUNIT
{
public:
  int AnalysisUnitID;
  int CollectionUnitID;
  UnicodeString AnalysisUnitName;
  Variant Depth;
  Variant Thickness;
  int FaciesID;
  int DepAgentID;
  bool Mixed;
  UnicodeString IGSN;
  UnicodeString Notes;
  map<int,double> AltDepths;  // AltDepthID, Depth
public:
  NEOTOMAANALUNIT() { AnalysisUnitID = -1; CollectionUnitID = -1; FaciesID = -1;
					  DepAgentID = -1; Mixed = false; }
};
//---------------------------------------------------------------------------

class UPDSAMPLEAGE
{
public:
  bool update;
  int ACol;
  int ARow;
  int SampleAgeID;
  int SampleID;
  Variant Age;
  Variant AgeYounger;
  Variant AgeOlder;
public:
  UPDSAMPLEAGE() { update = false; SampleAgeID = -1; }
};

#endif
