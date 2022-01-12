//---------------------------------------------------------------------------

#ifndef TIUploadH
#define TIUploadH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include "ipwcore.h"
#include "ipworks.h"
#include "cxButtons.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include <Menus.hpp>
#include "ipwjson.h"
#include "ipwhttp.h"
#include <CheckLst.hpp>
#include "ProfGrid.hpp"
#include <Grids.hpp>
#include <Sockets.hpp>
#include <ImgList.hpp>
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxEdit.hpp"
#include "cxMemo.hpp"
#include "cxTextEdit.hpp"
#include "cxGroupBox.hpp"
#include <Graphics.hpp>
#include <OleCtrls.hpp>
#include "cxProgressBar.hpp"
#include <Mask.hpp>
#include "ipshttps.h"
#include "ipsjsons.h"
#include "cxCheckListBox.hpp"
#include "cxLabel.hpp"
#include "cxCheckBox.hpp"
#include "dxGDIPlusClasses.hpp"
#include <Dialogs.hpp>
#include "dxSkinBlack.hpp"
#include "dxSkinBlue.hpp"
#include "dxSkinBlueprint.hpp"
#include "dxSkinCaramel.hpp"
#include "dxSkinCoffee.hpp"
#include "dxSkinDarkRoom.hpp"
#include "dxSkinDarkSide.hpp"
#include "dxSkinDevExpressDarkStyle.hpp"
#include "dxSkinDevExpressStyle.hpp"
#include "dxSkinFoggy.hpp"
#include "dxSkinGlassOceans.hpp"
#include "dxSkinHighContrast.hpp"
#include "dxSkiniMaginary.hpp"
#include "dxSkinLilian.hpp"
#include "dxSkinLiquidSky.hpp"
#include "dxSkinLondonLiquidSky.hpp"
#include "dxSkinMcSkin.hpp"
#include "dxSkinMetropolis.hpp"
#include "dxSkinMetropolisDark.hpp"
#include "dxSkinMoneyTwins.hpp"
#include "dxSkinOffice2007Black.hpp"
#include "dxSkinOffice2007Blue.hpp"
#include "dxSkinOffice2007Green.hpp"
#include "dxSkinOffice2007Pink.hpp"
#include "dxSkinOffice2007Silver.hpp"
#include "dxSkinOffice2010Black.hpp"
#include "dxSkinOffice2010Blue.hpp"
#include "dxSkinOffice2010Silver.hpp"
#include "dxSkinOffice2013DarkGray.hpp"
#include "dxSkinOffice2013LightGray.hpp"
#include "dxSkinOffice2013White.hpp"
#include "dxSkinPumpkin.hpp"
#include "dxSkinsCore.hpp"
#include "dxSkinsDefaultPainters.hpp"
#include "dxSkinSeven.hpp"
#include "dxSkinSevenClassic.hpp"
#include "dxSkinSharp.hpp"
#include "dxSkinSharpPlus.hpp"
#include "dxSkinSilver.hpp"
#include "dxSkinSpringTime.hpp"
#include "dxSkinStardust.hpp"
#include "dxSkinSummer2008.hpp"
#include "dxSkinTheAsphaltWorld.hpp"
#include "dxSkinValentine.hpp"
#include "dxSkinVS2010.hpp"
#include "dxSkinWhiteprint.hpp"
#include "dxSkinXmas2008Blue.hpp"
#include "dxSkinOffice2016Colorful.hpp"
#include "dxSkinOffice2016Dark.hpp"
#include "dxSkinVisualStudio2013Blue.hpp"
#include "dxSkinVisualStudio2013Dark.hpp"
#include "dxSkinVisualStudio2013Light.hpp"
#include <ADODB.hpp>
#include <DB.hpp>
#ifndef TGParentH
#include "TGParent.h"
#endif
#ifndef TISpreadH
#include "TISpread.h"
#endif
#ifndef TIJSONH
#include "TIJSON.h"
#endif
#ifndef TINeotomaH
#include "TINeotoma.h"
#endif
#ifndef TNSubmitH
#include "TNSubmit.h"
#endif
#ifndef TIAgeModH
#include "TIAgeMod.h"
#endif
#ifndef TUpUtilsH
#include "TUpUtils.h"
#endif
#ifndef TICommonH
#include "TICommon.h"
#endif

//---------------------------------------------------------------------------
class TNeotomaTaxaValidationForm;
//---------------------------------------------------------------------------

enum UPLOADCONTROL { INITIALIZE, VALIDATIONCANCELLED, LATLONGVALIDATED,
	 DEPENVTVALIDATED };
enum PROGRESSBARSYTLE { MARQUEE, CORE, NOBAR };
//---------------------------------------------------------------------------

typedef struct
{
  UnicodeString Name;
  int HigherID;
} PARENTGEOPOL;
//---------------------------------------------------------------------------

typedef struct
{
  int TaxonID;
  UnicodeString TaxonName;
  UnicodeString TaxaGroupID;
} NEOTOMATAXON;
//---------------------------------------------------------------------------

class NEOTOMASYNONYMY : public SYNONYMY
{
public:
  int TaxonID;
public:
  NEOTOMASYNONYMY(SYNONYMY& syn) { TaxonName = syn.TaxonName; Contrib = syn.Contrib;
	Pub = syn.Pub; Notes = syn.Notes; TaxonID = -1; }
};
//---------------------------------------------------------------------------

class NEOTOMATAPHSYSTEM
{
public:
  UnicodeString DatasetType;
  UnicodeString SystemName;
  set<UnicodeString> Types;
  int DatasetTypeID;
  int SystemID;
  map<UnicodeString,int> TypeIDs;  // TypeName, TypeID
  vector<int> rows;
public:
  NEOTOMATAPHSYSTEM() { }
  NEOTOMATAPHSYSTEM(UnicodeString dataset_type, UnicodeString system_name, set<UnicodeString> types )
	{ DatasetType = dataset_type; SystemName = system_name; Types = types; }
  bool operator == (const NEOTOMATAPHSYSTEM& compare);
  void AddTypes(set<UnicodeString>& types);
};
//---------------------------------------------------------------------------

typedef struct
{
  int row;
  UnicodeString code;
} SAMPLEMETADATAROW;
//---------------------------------------------------------------------------

class NEOTOMADATASET
{
public:
  int DatasetID;
  int NeotomaCollUnitID;
  int NeotomaDatasetTypeID;
  int NeotomaDatabaseID;
  int NeotomaSubmissionTypeID;
  int WhitmoreID1;
  UnicodeString NeotomaSubmissionNotes;
  UnicodeString DatasetName;
  UnicodeString Notes;
  vector<CONTACT*> Investigators;
  vector<CONTACT*> Processors;
  vector<PUBLICATION*> Publications;
  vector<REPOSITORY> Repositories;
public:
  NEOTOMADATASET() { DatasetID = -1; NeotomaCollUnitID = -1; NeotomaDatasetTypeID = -1;
	WhitmoreID1 = -1; }
};
//---------------------------------------------------------------------------

class NEOTOMALITHUNIT
{
public:
  int CollUnitID;
  Variant DepthTop;
  Variant DepthBottom;
  UnicodeString UnitDescription;
  UnicodeString LowerBoundary;
public:
  NEOTOMALITHUNIT() { CollUnitID = -1; }
};
//---------------------------------------------------------------------------

class ISOSTRATDATA
{
public:
  bool empty;
  Variant SD;
  Variant TaxonID;
  Variant ElementTypeID;
public:
  ISOSTRATDATA() { empty = true; }
};
//---------------------------------------------------------------------------

class NEOTOMADATA
{
public:
  int VariableID;
  double Value;
  vector<int> TaphTypeIDs;
  TList* Specimens;
  ISOSTRATDATA IsoStratData;
public:
  NEOTOMADATA() { Specimens = NULL; };
  NEOTOMADATA(int var_id, double value, TList* spec) { VariableID = var_id; Value = value; Specimens = spec; }
};
//---------------------------------------------------------------------------

class NEOTOMASAMPLE
{
public:
  int col;
  int SampleID;
  int AnalysisUnitID;
  int CollUnitID;
  int SiteID;
  int DatasetTypeID;
  int DatasetID;
  int TaxonID;               // NeotomaTaxonID
  UnicodeString SampleName;
  vector<UnicodeString> Keywords;
  vector<int> AnalystIDs;
  Variant DateSampled;
  Variant DateAnalyzed;
  UnicodeString LabNumber;
  UnicodeString PrepMethod;
  UnicodeString Notes;
  vector<NEOTOMADATA> data;
public:
  NEOTOMASAMPLE() { col = -1; DatasetTypeID = -1; DatasetID = -1; SiteID = -1;
					CollUnitID = -1; AnalysisUnitID = -1; SampleID = -1;
					TaxonID = -1; }
};
//---------------------------------------------------------------------------

typedef struct
{
  int SampleID;
  int KeywordID;
} NEOTOMAKEYWORD;
//---------------------------------------------------------------------------

typedef struct
{
  int SampleID;
  int ContactID;
  int AnalystOrder;
} NEOTOMASAMPLEANALYSTS;
//---------------------------------------------------------------------------

class NEOTOMAVARIABLE
{
public:
  int VariableID;
  UnicodeString TaxonName;
  UnicodeString Notes;
  vector<NEOTOMASYNONYMY> Synonymy;
  UnicodeString Element;
  UnicodeString TaxaGroupID;
  int TaxonID;
  int ElementID;
  int UnitsID;
  int ContextID;
  int DatasetTypeID;
  int DatasetID;
  int TaxonAnalyzedID;
  int ElementAnalyzedID;
  vector<int> TaphTypeIDs;
public:
  NEOTOMAVARIABLE() { VariableID = -1; TaxonID = -1; ElementID = -1;
					  UnitsID = -1; ContextID = -1; DatasetTypeID = -1;
					  TaxonAnalyzedID = -1; ElementAnalyzedID = -1; }
};
//---------------------------------------------------------------------------

typedef struct
{
  int TempVariableID;
  UnicodeString TaxonName;
  int TaxonID;
  int VariableElementID;
  int VariableUnitsID;
  int VariableContextID;
} NEWNEOTOMAVARIABLE;
//---------------------------------------------------------------------------

class ALTDEPTHS
{
public:
  UnicodeString AltDepthName;
  int VariableUnitsID;
  UnicodeString Notes;
public:
  ALTDEPTHS() { VariableUnitsID = -1; }
};
//---------------------------------------------------------------------------

class NEOTOMAGEOCHRON
{
public:
	int TiliaID;
	int GeochronID;      // Temp GeochronID
	int AnalysisUnitID;
	int GeochronTypeID;
	int AgeTypeID;
	UnicodeString LabNumber;
	Variant Depth;
	Variant Thickness;
	Variant Age;
	Variant ErrorOlder;
	Variant ErrorYounger;
	Variant CalAge;
	Variant CalAgeOlder;
	Variant CalAgeYounger;
	bool GreaterThan;
	map<UnicodeString,double> RadiocarbonParams;
	UnicodeString MaterialDated;
	UnicodeString Notes;
	vector<int> PublicationIDs;
public:
	NEOTOMAGEOCHRON() { GeochronID = -1; AnalysisUnitID = -1; GeochronTypeID = -1;
		AgeTypeID = -1; GreaterThan = false; };
};
//---------------------------------------------------------------------------

class NEOTOMATAXONDATE
{
public:
	int GeochronID;    // Tilia GeochronID
	int SpecimenID;    // Tilia SpecimenID -- new
	int NeotomaSpecimenID;  // new
	int SampleID;      // Tilia SampleID -- new
	int NeotomaTaxonID;
	int NeotomaElementTypeID;
	int NeotomaFractionID;
	UnicodeString TaxaGroupID;
	UnicodeString DateDescript;
	UnicodeString Taxon;
	UnicodeString ElementType;
	UnicodeString Fraction;
	UnicodeString Notes;
	vector<PUBLICATION*> Publications;
	struct {
	  Variant Age;
	  Variant AgeOlder;
	  Variant AgeYounger;
	  int CurveID;
	  int ProgramID;
	  Variant Date;
	} Cal;
public:
	NEOTOMATAXONDATE(int gcid, TAXONDATED td, vector<PUBLICATION*>& pubs, UnicodeString dd);
};
//---------------------------------------------------------------------------

class NEOTOMAAGEMODEL
{
public:
  int ChronNumber;
  int NeotomaChronologyID;
  int CollUnitID;
  UnicodeString ChronologyName;
  UnicodeString AgeUnits;
  bool Default;
  Variant DatePrepared;
  UnicodeString AgeModel;
  Variant AgeBoundOlder;
  Variant AgeBoundYounger;
  UnicodeString Notes;
  vector<CONTACT*> Preparers;
  UnicodeString PreparersComboBoxText;
  vector<CHRON> ChronControls;
public:
  NEOTOMAAGEMODEL() { ChronNumber = 0; NeotomaChronologyID = -1; Default = false;
	DatePrepared = Unassigned(); AgeBoundOlder = Unassigned(); AgeBoundYounger = Unassigned(); };
  NEOTOMAAGEMODEL(int chron_number, AGEMODEL* age_model, TList* chron_controls);
};
//---------------------------------------------------------------------------

class NEOTOMACHRONCONTROL
{
public:
	int ChronControlID;
	int ChronControlTypeID;
	int AnalysisUnitID;
	Variant Depth;
	Variant Thickness;
	Variant AgeTypeID;
    Variant Age;
	Variant AgeLimitOlder;
	Variant AgeLimitYounger;
	UnicodeString Notes;
	int CalibrationCurveID;
	int CalibrationProgramID;
	vector<int> GeoChronIDs;
public:
	NEOTOMACHRONCONTROL() { ChronControlID = -1; ChronControlTypeID = -1;
		AnalysisUnitID = -1; CalibrationCurveID = -1; CalibrationProgramID = -1; }
};
//---------------------------------------------------------------------------

class NEOTOMACALIB
{
public:
  int ChronControlID;
  int CalibrationCurveID;
  int CalibrationProgramID;
public:
  NEOTOMACALIB(int control_id, int curve_id, int prog_id)
	{ ChronControlID = control_id; CalibrationCurveID = curve_id;
	  CalibrationProgramID = prog_id; }
};
//---------------------------------------------------------------------------

class NEOTOMACHRONOLOGY
{
public:
	int ChronologyID;
	int CollectionUnitID;
	int AgeTypeID;
	int ContactID;
	bool IsDefault;
	UnicodeString ChronologyName;
	Variant DatePrepared;
	UnicodeString AgeModel;
	Variant AgeBoundYounger;
	Variant AgeBoundOlder;
	UnicodeString Notes;
	vector<int> PreparerIDs;
	vector<NEOTOMACHRONCONTROL> ChronControls;
public:
	NEOTOMACHRONOLOGY() { ChronologyID = -1; AgeTypeID = -1;
		 ContactID = -1; IsDefault = false; }
};
//---------------------------------------------------------------------------

class ACCRATE
{
private:
	pair<int,int> PK; // AnalysisUnitID, ChronologyID
	double FAccumulationRate;
	int FVariableUnitsID;
public:
	ACCRATE(int analunitid, int chronid, double accrate, int varunitsid)
	  { PK = make_pair(analunitid,chronid); FAccumulationRate = accrate; FVariableUnitsID = varunitsid; };
	__property int AnalysisUnitID = {read = PK.first};
	__property int ChronologyID = {read = PK.second};
	__property double AccumulationRate = {read = FAccumulationRate};
	__property int VariableUnitsID = {read = FVariableUnitsID};
	bool operator == (const ACCRATE& comp) { return (PK == comp.PK); }
};
//---------------------------------------------------------------------------

class SPECIMENAGE
{
public:
  int GeochronIndex;
  double Age;
  double AgeYounger;
  double AgeOlder;
  double CalAge;
  double CalAgeYounger;
  double CalAgeOlder;
public:
  SPECIMENAGE() { GeochronIndex = -1; Age = NaN; AgeYounger = NaN; AgeOlder = NaN;
                  CalAge = NaN; CalAgeYounger = NaN; CalAgeOlder = NaN; }
};
//---------------------------------------------------------------------------

class NEOTOMAAGE
{
public:
  double Age;
  double AgeYounger;
  double AgeOlder;
public:
  NEOTOMAAGE() { Age = NaN; AgeYounger = NaN; AgeOlder = NaN; }
  NEOTOMAAGE(SPECIMENAGE sa) { Age = sa.Age; AgeYounger = sa.AgeYounger; AgeOlder = sa.AgeOlder; }
};
//---------------------------------------------------------------------------
typedef map<int,NEOTOMAAGE> NEOTOMASAMPLEAGE;     // SampleID, NEOTOMASAMPLEAGE
//---------------------------------------------------------------------------

class TAXAGROUPDATASETTYPE
{
public:
   UnicodeString TaxaGroupID;
   int DatasetTypeID;
public:
   TAXAGROUPDATASETTYPE() { DatasetTypeID = -1; };
   TAXAGROUPDATASETTYPE(int dtid, UnicodeString tgid )
	 { DatasetTypeID = dtid; TaxaGroupID = tgid; }
   bool operator == (const TAXAGROUPDATASETTYPE& compare);
};
//---------------------------------------------------------------------------

typedef struct
{
  UnicodeString name;
  UnicodeString author;
} TAXONAUTHOR;
//---------------------------------------------------------------------------

typedef struct
{
  int EventID;
  int AnalysisUnitID;
  UnicodeString Notes;
} NEOTOMATEPHRA;
//---------------------------------------------------------------------------

typedef struct
{
  int AnalysisUnitID;  // this column will ultimately be deleted
  int EventID;
  int ChronControlID;
  UnicodeString Notes;
} NEOTOMAEVENTCHRONOLOGY;
//---------------------------------------------------------------------------

typedef struct
{
  int AnalysisUnitID;  // this column will ultimately be deleted
  int RelativeAgeID;
  int ChronControlID;
  UnicodeString Notes;
} NEOTOMARELAGE;
//---------------------------------------------------------------------------

struct TaxonAuthorComp {
  bool operator() (const TAXONAUTHOR& lhs, const TAXONAUTHOR& rhs) const
  {return lhs.name < rhs.name;}
};
//---------------------------------------------------------------------------

class ValidationMessages
{
public:
  int Errors;
  int Warnings;
  int Notes;
public:
  ValidationMessages() { Errors = 0; Warnings = 0; Notes = 0; }
  void SetMessages(ValidationMessages& vm)
	{ Errors = vm.Errors; Warnings = vm.Warnings; Notes = vm.Notes; }
  void SetMessages(ValidationMessages& m1, ValidationMessages& m2)
	{ Errors = m1.Errors-m2.Errors; Warnings = m1.Warnings-m2.Warnings;
      Notes = m1.Notes-m2.Notes; }
};
//---------------------------------------------------------------------------

template <class T> class ValidateIsotope
{
public:
	map<int,T> IsoType;  // row, isotope class
protected:
	TTilSpreadSheetForm* TSSForm;
	TNeotomaUploadForm* UploadForm;
	short isotope;
	int RowCount;
	UnicodeString IsoName;
	vector<pair<int,double> > dv;        // row, double value
	set<int> FDataRows;
private:
	vector<pair<int,int> > iv;            // row, int value
	map<int,pair<int,Variant> > pv;       // order, IsoPretreatmentTypeID, value
	vector<pair<int,UnicodeString> > sv;  // row, int value
	map<int,int> ParentIDs;               // row, ParentID
protected:
	bool GetFloats(UnicodeString ColumnName);
private:
	int GetColumn(short isotope, UnicodeString ColumnName);
	bool GetInts(UnicodeString ColumnName);
	bool GetStrings(UnicodeString ColumnName);
	bool GetIDs(UnicodeString ColumnName, map<int,UnicodeString>& idmap);
	bool GetIsoSpecificIDs(UnicodeString ColumnName, multimap<UnicodeString,pair<int,UnicodeString> >& Items);
	bool GetChildIDs(UnicodeString ColumnName, multimap<int, pair<int,UnicodeString> >& idmap);
	bool GetPretreatments(UnicodeString ColumnName, vector<NEOTOMAPRETREATMENT>& Items);
	bool GetContact(UnicodeString ColumnName);
public:
    ValidateIsotope() { };
	ValidateIsotope(short iso, UnicodeString name, int rc, TTilSpreadSheetForm* tssform, TNeotomaUploadForm* upform)
		{ isotope = iso; IsoName = name, RowCount = rc; TSSForm = tssform; UploadForm = upform; }
	bool GetDataRows(map<int,int>& SpecimenRows);
	bool GetValue(void);
	bool GetSD(void);
	bool GetMass(void);
	bool GetWeightPercent(void);
	bool GetAtomicPercent(void);
	bool GetMaterialAnalyzed(map<int,UnicodeString>& Items);
	bool GetSubstrate(multimap<int, pair<int,UnicodeString> >& Items);
	bool GetPretreatment(vector<NEOTOMAPRETREATMENT>& Items);
	bool GetAnalyst(void);
	bool GetLab(void);
	bool GetLabNr(void);
	bool GetScale(multimap<UnicodeString,pair<int,UnicodeString> >& Items);
	bool GetReps(void);
	void GetIsoData(vector<T>& vec);
	__property set<int> DataRows = {read = FDataRows};
};
//---------------------------------------------------------------------------

template <class T> class ValidateSrRatio : public ValidateIsotope<T>
{
public:
	ValidateSrRatio(short iso, UnicodeString name, int rc, TTilSpreadSheetForm* tssform, TNeotomaUploadForm* upform)
		{ isotope = iso; IsoName = name, RowCount = rc; TSSForm = tssform; UploadForm = upform; }
	bool GetTotalSr(void);
};
//---------------------------------------------------------------------------

class ISODATA
{
public:
	int NeotomaSampleID;
	int row;
	int SpecimenID;
	int IsoMatAnalTypeID;
	int IsoSubstrateTypeID;
	map<int,pair<int,Variant> > IsoPretreatments;  // order, IsoPretreatmentTypeID, value
	int AnalystID;
	UnicodeString Lab;
	UnicodeString LabNr;
	Variant Mass;
	Variant WeightPercent;
	Variant AtomicPercent;
	int Reps;
public:
	ISODATA() { NeotomaSampleID = -1; SpecimenID = -1; IsoMatAnalTypeID = -1;
				IsoSubstrateTypeID = -1; Reps = -1;  }
};
//---------------------------------------------------------------------------

class DELTARATIO : public ISODATA
{
public:
    int NeotomaDataID;
	int IsoScaleTypeID;
	Variant Value;
	Variant SD;
public:
	DELTARATIO() { }
	DELTARATIO(int specid) { SpecimenID = specid; IsoScaleTypeID = -1; }
};
//---------------------------------------------------------------------------

class ELEMENTRATIO : public ISODATA
{
public:
	int NeotomaDataID;
	Variant Value;
public:
	ELEMENTRATIO() { }
	ELEMENTRATIO(int specid) { SpecimenID = specid; }
};
//---------------------------------------------------------------------------

class SrRATIO : public ISODATA
{
public:
	struct NeotomaDataID { int SrRatio; int TotalSr; };
	Variant TotalSr;
	Variant Value;
	Variant SD;
public:
	SrRATIO() { }
	SrRATIO(int specid) { SpecimenID = specid; }
};
//---------------------------------------------------------------------------

class Sr8786 : public ISODATA
{
public:
	double TotalSr;
	double Value;
	double SD;
};
//---------------------------------------------------------------------------

class ISOVARID  // holds VariableIDs for isotopic variables
{
public:
	int d13C;
	int d15N;
	int d18O;
	int dD;
	int d34S;
	int Sr87Sr86;
	int TotalSr;
	int CN;
	int OH;
public:
	ISOVARID() { d13C = -1; d15N = -1; d18O = -1; dD = -1; d34S = -1;
		Sr87Sr86 = -1; TotalSr = -1; CN = -1; OH = -1; }
	bool IsEmpty(void);
};
//---------------------------------------------------------------------------

typedef struct
{
  int Row;
  UnicodeString Code;
  UnicodeString Name;
  UnicodeString Element;
  map<int,pair<UnicodeString,UnicodeString> > MetadataCodes;  // row, <complete code, code>, e.g. #dD.SD, SD
} ISOSSDATA;
//---------------------------------------------------------------------------

typedef struct
{
  int DataID;
  int SpecimenID;
  Variant SD;
} ISOSPECIMENDATA;
//---------------------------------------------------------------------------

class AGGDATASET
{
public:
  UnicodeString Name;
  int ID;
  int DatasetTypeID;
  int OrderTypeID;
  int ChronID;
public:
  AGGDATASET() { ID = -1; DatasetTypeID = -1; OrderTypeID = -1; ChronID = -1; }
};
//---------------------------------------------------------------------------

class TNeotomaUploadForm : public TForm
{
__published:	// IDE-managed Components
	TStatusBar *StatusBar1;
	TipwHTTP *ipwHTTP1;
	TTcpClient *TcpClient1;
	TcxButton *cxButton2;
	TcxButton *cxButton3;
	TcxButton *cxButton4;
	TcxProgressBar *cxProgressBar1;
	TipsHTTPS *ipsHTTPS1;
	TipsJSONS *ipsJSONS1;
	TRichEdit *RichEdit1;
	TImage *Image2;
	TImage *Image1;
	TTimer *Timer1;
	TFlowPanel *FlowPanel1;
	TcxButton *cxButton1;
	TcxImageList *cxImageList1;
	TSaveDialog *SaveDialog1;
	TADOConnection *ADOConnection1;
	TADOQuery *ADOQuery1;
	TipwJSON *ipwJSON2;
	void __fastcall cxButton4Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall ipsHTTPS1Error(TObject *Sender, TipsHTTPSErrorEventParams *e);
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall cxButton2Click(TObject *Sender);
	void __fastcall cxButton1Click(TObject *Sender);
	void __fastcall ipsJSONS1SSLServerAuthentication(TObject *Sender, TipsJSONSSSLServerAuthenticationEventParams *e);

private:    // User declarations
	friend class TNeotomaTaxaValidationForm;
	friend class TNeotomaUploadChronForm;
	friend class TNeotomaSiteValidationForm;
	friend class TNeotomaCollUnitValidationForm;
	friend class TNeotomaDatasetValidationForm;
	friend class TCheckVarUnitsForm;
	friend class TCheckVarElementsForm;
	friend class TValidateLatLongForm;
	friend class TNewDepEnvtForm;
	friend class TNeotomaSiteForm;
	friend class TNewTaxonForm;
	friend class TNeotomaFindTaxonForm;
	friend class TCheckListVarForm;
	friend class TCheckZeroDataForm;
	friend class TUpdateNeotomaSiteForm;
	template<typename T> friend class ValidateIsotope;
	TTilSpreadSheetForm* TSSForm;
	bool Activated;
	bool GeochronOnly;
	vector<SSVAR> SSVarList;
	SITE* site_ptr;
	COLLECTION* coll_ptr;
	NeotomaDepEnvtTypesTable* DepEnvtTypes;
	ValidationMessages TotalMessages;
	ValidationMessages ArchiveMessages;
	ValidationMessages NewMessages;
	int nSteps;
	int Step;
	UnicodeString OtherHeaders;
	vector<SSTAXANAME> TaxaNotFound;
	int RatStart;
	int RatEnd;
	int RatPos;
	set<TAXONAUTHOR, TaxonAuthorComp> TaxaSet;
	UnicodeString jsonTaxaNames;
	bool VarErrors;
	int SpecimenDateChronNo;
	int SpecimenDateDatasetID;
	bool DataUploaded;
	int TempSiteID;
	int TempCollUnitID;
	int TempAnalUnitID;
	int TempSampleID;
	int TempDatasetID;
	int TempGeochronID;
	int TempChronID;
	int TempChronControlID;
	set<int> ChronNumbers;
	// bool SurfaceSampleAgeModel;
	bool Aggregates;
	set<int> ZeroVarsAllowed;
	set<SPECIMEN*> all_specimens;
	bool AddDataToExistingCollUnit;
	bool AddGeochronToExistingCollUnit;
	bool ElementErrors;
	bool MultiSiteUpload;
	NEOTOMACHRONOLOGY AggregateChron;
	bool ReplaceEPDDataset;
	map<UnicodeString,int> WhitmoreIDs;
private:    // Neotoma Lookups
	map<int,UnicodeString> NeotomaKeywords;
	map<UnicodeString, UnicodeString> NeotomaTaxaGroups;
	map<int,UnicodeString> NeotomaDatasetTypes;     // DatasetTypeID, DatasetType
	map<int,UnicodeString> NeotomaContactStatuses;  // ContactStatusID, ContactStatus
	vector<AGETYPE> NeotomaAgeTypes;
	vector<NTMTAPHONOMICSYSTEMS> NeotomaTaphSystems;
	multimap<int,int> NeotomaTaphDatasetTypes;
private:    // NeotomaIDs
	vector<CONTACT*> LinkedContacts;   // all contacts linked to some data object
	map<int,NEOTOMAVARIABLE> NeotomaVariables;  // row, Variable
	vector<NEOTOMAANALUNIT> NeotomaAnalysisUnits;
	vector<NEOTOMASAMPLE> NeotomaSamples;
	vector<NEOTOMAGEOCHRON> NeotomaGeochrons;
	map<pair<int,int> ,int> NeotomaChronNoMap;    // pair<OrigChronNo,CollUnitID>, NewChronNo -- for multicollection untis
	vector<NEOTOMACHRONOLOGY> NeotomaChrons;
	vector<NEOTOMAAGEMODEL> NeotomaAgeModels;
	map<int,NEOTOMASAMPLEAGE> NeotomaSampleAges;  // map<ChronNo, map<SampleID,NEOTOMAAGE> >
	vector<ACCRATE> AccRates;
	vector<NEOTOMALITHUNIT> NeotomaLithUnits;
	vector<NEOTOMATAXONDATE> NeotomaTaxaDated;
	vector<NEOTOMATEPHRA> NeotomaTephras;
	vector<NEOTOMARELAGE> NeotomaRelAges;
	vector<NEOTOMAEVENTCHRONOLOGY> NetomaEventChronology;
	map<int,ALTDEPTHS> AltDepthScales; // AltDepthID, ALTDEPTH
	map<int,int> NeotomaSiteIDs;       // NeotomaSiteID, TempSiteID
	map<int,int> NeotomaCollUnitIDs;   // TempCollUnitID, NeotomaCollUnitID
	map<int,int> NeotomaAnalUnitIDs;   // TempAnalUnitID, NeotomaAnalUnitID
	map<int,int> NeotomaDatasetIDs;    // TempDatasetID, NeotomaDatasetID
	map<int,int> NeotomaSampleIDs;     // TempSampleID, NeotomaSampleID
	map<int,int> NeotomaGeochronIDs;   // TempGeochronID, NeotomaGeochronID
	map<int,int> TiliaChronIDs;        // TempChronID, ChronNo
	map<int,int> NeotomaChronIDs;      // TempChronID, NeotomaChronID
	map<int,int> NeotomaChronControlIDs; // TempChronControlID, NeotomaChronControlID
	map<int,int> NeotomaSpecimenIDs;   // TiliaSpecimenID, NeotomaSpecimenID
	map<UnicodeString,int> SampledTaxa; // taxon name, NeotomaTaxonID
	vector<pair<int,int> > GeochronControls;  // ChronControlID, GeochronID
	int FindTempNeotomaAnalUnitID(int AnalUnitID);
	int FindTempNeotomaCollUnitID(int CollUnitID);
	int FindCollUnitID(int AnalUnitID);
	int FindAnalUnitID(int SampleID);
	map<int,SPECIMEN*> SpecimenRowObj;  // row, specimen object
	set<int> IsoDataRows;       // set of all rows having isotope data
	int IsoChronologyID;        // Isotope local chron
	map<int,NEOTOMAAGE> IsoSpecimenAges;  // // LocalSpecimenID, NEOTOMAAGE
	vector<DELTARATIO> delta13C;
	vector<ELEMENTRATIO> CNratio;
	vector<DELTARATIO> delta15N;
	vector<DELTARATIO> delta18O;
	vector<ELEMENTRATIO> OHratio;
	vector<DELTARATIO> deltaD;
	vector<DELTARATIO> delta34S;
	vector<SrRATIO> Sr87Sr86;
	ISOVARID IsoVarID;
	vector<ISOSSDATA> IsoDataset;
	vector<AGGDATASET> AggregateDatasets;
	map<int,int> WhitmoreSamples;  // ID1, SampleID
	Access *WhitmoreAccess;

private:	// User declarations
	void SetProgressBar(short);
	void ResetJSONParser(TipwJSON*);
	void ResetControlButtons(bool);
	void SetProgressBarPosition(void);
	void SetProgressBarPosition(int steps);
	bool InitialValidation(void);
	void Validate(void);
	bool RunValidation(void);
	int GetVariables(void);
	bool GetNeotomaKeywords(void);
	bool ValidateTaxa(void);
	bool ValidateTaxaDatasetTypes(void);
	bool ValidateVariables(void);
	bool ValidateSamples(void);
	bool ValidateGeochron(void);
	CONTACT* GetStewardContact(void);
	bool ValidateSurfaceSample(bool& is_surface_sample);
	UnicodeString DateDescript(GEOCHRON* Date);
	UnicodeString AnalysisUnitDescript(int AnalysisUnitID);
	int FindGeochronType(UnicodeString Method, map<int,UnicodeString>& GeochronTypes);
	int FindAgeType(UnicodeString AgeUnits, vector<AGETYPE>& AgeTypes);
	bool ValidateAgeModels(AGEMODEL* NewAgeModel);
	bool ValidateMultiAnalUnits(AGEMODEL* AgeModel);
	bool TransferAgeModelToNeotomaAgeModel(AGEMODEL* AgeModel, int& NewChronNo);
	bool IsGeochronControlType(int ChronControlTypeID);
	bool ValidateChronControlAnalUnit(int ChronNo, NEOTOMACHRONCONTROL&
		NeotomaChronControl, CHRON& ChronControl, bool IDByDepth);
	bool ValidateSampleAges(void);
	void InvalidSSNumber(int col, int row, UnicodeString Item, UnicodeString& msg);
	bool ProcessFacies(NEOTOMAANALUNIT& AnalUnit, TProfGridCell* ACell);
	bool ProcessDepAgent(NEOTOMAANALUNIT& AnalUnit, TProfGridCell* ACell);
	bool ValidateTaphonomy(void);
	bool ValidateTaxonNotes(void);
	bool ValidateSpecimens(void);
	bool ValidateSpecimenTaphonomy(SPECIMEN* Specimen, map<int,map<int,UnicodeString> >& TaphTypes);
	bool ValidateIsotopeDataset(bool is_surface_sample);
	bool ValidateIsoMetadata(short isotope, UnicodeString element,
		map<int,UnicodeString>& Instrument, map<int,UnicodeString>& IntroSys,
		vector<NEOTOMAISOSTANDARD>& Standards);
	bool GetIsotopeVariableID(int& VariableID, UnicodeString Taxon, UnicodeString Units);
	bool GetSpecimenLookupItems(map<int,UnicodeString>& element_types,
		map<int,UnicodeString>& symmetries, map<int,UnicodeString>& portions,
		map<int,UnicodeString>& maturities, map<int,UnicodeString>& sex_types,
		map<int,UnicodeString>& domestic_status_types, map<int,UnicodeString>& repositories);
	bool Validate(UnicodeString Item, map<int,UnicodeString>& Items, int& ID);
	bool ValidateElements(map<UnicodeString,SSELEMENT>& SSElements,
		multimap<UnicodeString,int>& SSElementRows);
	UnicodeString SpecimenErrMsg(CELLOBJECT* CellObject, UnicodeString ErrMsg);
	bool ValidateUnits(map<UnicodeString,set<int> >& SSUnitTypes);
	bool UploadUnitsDatasetType(UnicodeString Units, int VariableUnitsID, int DatasetTypeID);
	bool ValidateContexts(map<UnicodeString,set<int> >& SSContextTypes);
	bool UploadContextDatasetType(UnicodeString Context, int VariableContextID, int DatasetTypeID);
	bool ParseNewElement(UnicodeString& NewElement, SSELEMENT* sselement,
		multimap<UnicodeString,int>& SSElementRows);
	bool SetVariableElementID(UnicodeString ElementKey, SSELEMENT& sselement,
		multimap<UnicodeString,int>& SSElementRows);
	bool UploadNewElementCombination(UnicodeString ElementKey, SSELEMENT& sselement,
		multimap<UnicodeString,int>& SSElementRows);
	bool FindSimilarDatasetType(UnicodeString& dataset_type, int& DatasetTypeID);
	bool GetNeotomaDatasetTypes(void);
	int GetDatasetTypeID(UnicodeString DatasetType);
	int GetTaphonomicSystemID(vector<NTMTAPHONOMICSYSTEMS>& Items, UnicodeString System);
	int CheckSiteName(SITE*);
	void CheckSiteAltitude(SITE*);
	void CheckSiteArea(SITE*);
	void CheckLakeParameters(SITE*);
	bool CheckSiteLatLong(SITE*);
	bool CheckGeoPolUnits(SITE*);
	int AddNewAdminUnit(UnicodeString, UnicodeString, int, int, int);
	int UploadGeoPoliticalUnit(UnicodeString, UnicodeString, vector<PARENTGEOPOL>&);
	int CheckAdminUnit(int, int, int, bool);
	UnicodeString GetGeoPolNameByID(int);
	int  CheckNeotomaSite(SITE*);
	bool ValidateCollectionUnit(SITE* site_ptr);
	bool ValidateCollUnitMetaData(SITE* site_ptr, COLLECTION* coll_ptr);
	bool ValidateHandle(COLLECTION* coll_ptr);
	bool ValidateCollUnitType(COLLECTION* coll_ptr);
	void ValidateCollUnitName(COLLECTION* coll_ptr);
	bool ValidateCollUnitGPS(COLLECTION* coll_ptr, SITE* site_ptr);
	bool ValidateCollUnitSubstrate(COLLECTION* coll_ptr);
	int ValidateCollUnitDepEnvt(COLLECTION* coll_ptr, SITE* site_ptr);
	void ValidateCollectors(COLLECTION* coll_ptr);
	bool ValidateLithology(void);
	bool ValidateDatasets(void);
	bool ValidateDatasetType(DATASET* DatasetPtr);
	bool ValidateDatasetInvestigators(DATASET* DatasetPtr, int ValLev);
	bool ValidateDatasetProcessors(DATASET* DatasetPtr, int ValLev);
	bool ValidateDatasetPubs(DATASET* DatasetPtr);
	bool ValidateDatasetRepositories(DATASET* DatasetPtr);
	void AddContact(CONTACT*);
	UnicodeString ValidationMsg(ValidationMessages&);
	UnicodeString FormatPostDataInsert(UnicodeString, vector<UnicodeString>&);
	bool ParseUploadResponse(UnicodeString, vector<int>&);
	void OutputLine(UnicodeString);
	void OutputBoldLine(UnicodeString);
	void OutputError(UnicodeString);
	void OutputWarning(UnicodeString);
	void OutputNote(UnicodeString);
	bool CheckDuplicates(void);
	void Check_cfs(void);
	bool CheckEmptyData(void);
	bool CheckZeroData(void);
	bool AssembleIsoDataset(void);
	bool ValidateSSMetadata(void);
	bool CheckDepthsNames(void);
	bool CheckDepthsNamesRow(int row, int start, int ncols);
	bool CheckTopBottom(void);
	void CheckEmptyRows(void);
	void CheckEmptyColumns(void);
	int CheckUnits(void);
	int CheckElements(void);
	bool LoadNeotomaTaxa(NeotomaTaxaByNameList& Taxa, NeotomaTaxaByNameList& Synonyms, bool set_progress_bar);
	virtual int CheckTaxaNames(NeotomaTaxaBase&);
	int CheckSynonyms(NeotomaTaxaBase& Taxa, NeotomaTaxaBase& Synonyms);
	bool GetTaxaGroups(void);
	int ResolveRemainingTaxaNotFound(bool& NewSynonyms);
	bool ValidatePublications(void);
	bool ValidatePublicationIDs(void);
	bool ValidateContacts(void);
	bool IsNeotomaContact(CONTACT* Contact, NTMCONTACT& NeotomaContact);
	UnicodeString FormatCitation(vector<AUTHOR>& AuthorList, UnicodeString& Year);
	bool GetNeotomaPub(PUBLICATION* pub, NTMPUBLICATION& ntm_pub, vector<NTMAUTHOR>& ntm_authors,
		vector<NTMEDITOR>& ntm_editors, vector<NTMTRANSLATOR>& ntm_translators, bool& found);
	static bool ntm_author_comp (NTMAUTHOR auth1, NTMAUTHOR auth2)
		{ return (auth1.AuthorOrder < auth2.AuthorOrder); }
	static bool ntm_editor_comp (NTMEDITOR edit1, NTMEDITOR edit2)
		{ return (edit1.EditorOrder < edit2.EditorOrder); }
	static bool ntm_translator_comp (NTMTRANSLATOR trans1, NTMTRANSLATOR trans2)
		{ return (trans1.TranslatorOrder < trans2.TranslatorOrder); }
	bool SamePub(PUBLICATION *pub, NTMPUBLICATION& ntm_pub, vector<NTMAUTHOR>& ntm_authors,
		vector<NTMEDITOR>& ntm_editors, vector<NTMTRANSLATOR>& ntm_translators,
		bool& AuthorMatch, bool& YearMatch);
	void StartRat();
	void EndRat();
	//int NextTempContactID(void) { return --TempContactID; }
	int NextTempSiteID(void) { return --TempSiteID; }
	int NextTempCollUnitID(void) { return --TempCollUnitID; }
	int NextTempAnalUnitID(void) { return --TempAnalUnitID; }
	int NextTempSampleID(void) { return --TempSampleID; }
	int NextTempDatasetID(void) { return --TempDatasetID; }
	int NextTempGeochronID(void) { return --TempGeochronID; }
	int NextTempChronologyID(void) { return --TempChronID; }
	int NextTempChronControlID(void) { return --TempChronControlID; }
	int ChronNoToNeotomaChronID(int ChronNo);
	bool UploadSite(int& SiteID);
	bool UploadCollUnit(int SiteID, COLLECTION& CollUnit, int& CollUnitID);
	bool UploadLithology(int CollUnitID);
	bool UploadAnalysisUnits(int CollUnitID, vector<int>& AnalysisUnitIDs);
	bool UploadGeochronology(int CollUnitID, DATASETSUBMISSION& GeochronSubmission);
	bool UploadChronologies(int CollUnitID);
	bool UploadGeochronControls(void);
	bool UploadEPDEntityDatasetIDs(UnicodeString EPDDatasetName, int EPDDatasetID);
	bool UploadSpecimenDates(int CollUnitID);
	bool UploadSpecimenIsotopes(int CollUnitID, vector<NEOTOMADATASET>& NeotomaDatasets);
	bool UploadIsoInstrumentation(short isotope, UnicodeString element, int DatasetID, int VariableID);
	bool UploadIsoData(UnicodeString isotope, vector<DELTARATIO>& drdata, int VariableID,
		map<int,SPECIMEN*>& SpecimenSampleIDs);
	bool UploadIsoData(UnicodeString isotope, vector<ELEMENTRATIO>& rdata, int VariableID,
		map<int,SPECIMEN*>& SpecimenSampleIDs);
	bool UploadIsoSpecimenData(UnicodeString isotope, vector<ISOSPECIMENDATA>& IsoSpecimenData);
	bool UploadIsoMetadata(UnicodeString isotope, vector<DELTARATIO>& drdata);
	bool UploadTephras(int CollUnitID);
	bool UploadDatasets(int CollUnitID, COLLECTION& CollUnit, vector<NEOTOMADATASET>& NeotomaDatasets);
	bool UploadSamples(vector<NEOTOMADATASET>& NeotomaDatasets);
	bool UploadData(int TempDatasetID, unsigned int& nsamples, unsigned int& ndata, vector<int>& ids,
		vector<NEOTOMADATASET>& NeotomaDatasets, vector<pair<int,TList*> >& DataSpecimens,
		vector<pair<int,int> >& Taphonomy, vector<pair<int,ISOSTRATDATA> >& IsoStratMetaData);
	bool UploadAccRates(void);
	bool UploadSpecimens(vector<pair<int, TList*> >& DataSpecimens, vector<int>& dataids);
	bool UploadSampleAges(vector<int>& TempSampleIDs);
	bool UploadDatasetSubmissions(int CollUnitID, vector<NEOTOMADATASET>& NeotomaDatasets,
		DATASETSUBMISSION& GeochronSubmission);
	bool PairFirstExists(vector<pair<UnicodeString,int> >& vec, UnicodeString item);
	int FindPairSecond(vector<pair<UnicodeString,int> >& vec, UnicodeString item);
	UnicodeString GetNeotomaAgeType(int AgeTypeID);
	double GetSiteLatitude(int AnalysisUnitID);
	vector<NEOTOMAGEOCHRON>::pointer GetNeotomaGeochron(int GeochronID);
	int GetNeotomaUnitsID(UnicodeString Units);
	bool GetNeotomaVariableElementID(NEOTOMATAXONDATE& TaxonDated, int& VariableElementID);
	bool GetNeotomaVariable(NEOTOMATAXONDATE& TaxonDated, int VariableElementID,
		int UnitsID, int& VariableID);
	bool GetAnalUnitDepth(int col, Variant& Depth);
	bool GetAnalUnitThickness(int col, int row, Variant& Thickness);
	bool ValidateSite(SITE* site_ptr);
	bool ValidateSiteExists(SITE* site_ptr);
	bool UploadAggregate(void);
	bool ValidateAggregateChrons(void);
	void RegisterWhitmoreSamples(void);
	bool SameAnalysisUnit(Variant Depth1, Variant Thick1, UnicodeString Name1,
		Variant Depth2, Variant Thick2, UnicodeString Name2);
public:		// User declarations
	__fastcall TNeotomaUploadForm(TComponent* Owner);
	SITE* GetSitePtr(void) { return site_ptr; }
};
//---------------------------------------------------------------------------

class TNeotomaTaxaValidationForm : public TNeotomaUploadForm
{
__published:	// IDE-managed Components
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);
private:	// User declarations
	void Validate(void);
	bool RunValidation(void);
	int CheckTaxaNames(NeotomaTaxaBase&);
public:		// User declarations
	__fastcall TNeotomaTaxaValidationForm(TComponent* Owner);
};
//---------------------------------------------------------------------------

// form for uploading a new chronology
class TNeotomaUploadChronForm : public TNeotomaUploadForm
{
__published:	// IDE-managed Components
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall cxButton2Click(TObject *Sender);
private:	// User declarations
	AGEMODEL* AgeModel;
	NEOTOMASAMPLEAGE NeotomaSampleAges;
	bool Fvalidation_aborted;
	bool success;
	int chron_row;
	int chron_row_young;
	int chron_row_old;
private:	// User declarations
	void Validate(void);
	bool RunValidation(void);
	bool UploadSampleAges(void);
	bool ProcessTephras(int CollUnitID);
public:		// User declarations
	__fastcall TNeotomaUploadChronForm(AGEMODEL* age_model, TComponent* Owner);
	__property bool validation_aborted = {read = Fvalidation_aborted};
	__property bool upload_success = {read = success};
	__property int ChronRow = {read = chron_row};
	__property int ChronRowYoung = {read = chron_row_young};
	__property int ChronRowOld = {read = chron_row_old};
};
//---------------------------------------------------------------------------
extern PACKAGE TNeotomaUploadForm *NeotomaUploadForm;
extern PACKAGE TNeotomaTaxaValidationForm *NeotomaTaxaValidationForm;
extern PACKAGE TNeotomaUploadChronForm *NeotomaUploadChronForm;
//---------------------------------------------------------------------------
#endif
