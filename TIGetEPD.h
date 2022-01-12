//---------------------------------------------------------------------------

#ifndef TIGetEPDH
#define TIGetEPDH
#ifndef TICommonH
#include "TICommon.h"
#endif
//---------------------------------------------------------------------------

bool EPDDecodeDateStr(UnicodeString DateStr, TDateTime& Date);

class EPDGetCountriesWithSitesNotInNeotoma : public SJSONTABLE
{
public:
  map<UnicodeString,int> Items;
private:
  int GetID(int idx) { return 1; }
public:
  EPDGetCountriesWithSitesNotInNeotoma(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class EPDGetSiteBase : public SJSONTABLE
{
public:
  map<int,EPDSITELOC> Items;
private:
  int GetID(int idx) { return 1; }
public:
  EPDGetSiteBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class EPDGetSiteByName : public EPDGetSiteBase
{
public:
  EPDGetSiteByName(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class EPDGetSitesNotInNeotomaByCountry : public EPDGetSiteBase
{
public:
  EPDGetSitesNotInNeotomaByCountry(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class EPDGetEntitiesBySiteNr : public SJSONTABLE
{
public:
  map<int,pair<UnicodeString,UnicodeString> > Items;  // E#, Sigle, Name
private:
  int GetID(int idx) { return 1; }
public:
  EPDGetEntitiesBySiteNr(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

typedef struct
{
  UnicodeString SiteDescript;
  UnicodeString Physiography;
  UnicodeString SurroundVeg;
  UnicodeString VegFormation;
} EPDSITEDESC;
//---------------------------------------------------------------------------

class EPDGetSiteDescription : public SJSONTABLE
{
public:
  vector<EPDSITEDESC> Items;
private:
  int GetID(int idx) { return 1; }
public:
  EPDGetSiteDescription(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

typedef struct
{
  UnicodeString Sigle;
  UnicodeString Name;
  bool IsCore;
  bool IsSect;
  bool IsSSamp;
  UnicodeString DepEnvt;
  UnicodeString EntLoc;
  UnicodeString LocalVeg;
  Variant CollNr;
  Variant SampDate;
  Variant DepthAtLoc;
  UnicodeString SampDevice;
  Variant CoreDiamCM;
  UnicodeString Notes;
} EPDENTITY;
//---------------------------------------------------------------------------

class EPDGetEntity : public SJSONTABLE
{
public:
  vector<EPDENTITY> Items;
private:
  int GetID(int idx) { return 1; }
public:
  EPDGetEntity(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

typedef struct
{
  UnicodeString Status;
  UnicodeString LastName;
  UnicodeString Initials;
  UnicodeString FirstName;
  UnicodeString Suffix;
  UnicodeString Title;
  UnicodeString Country;
  UnicodeString Phone;
  UnicodeString Fax;
  UnicodeString EMailAddr;
  UnicodeString Address;
} EPDWORKER;
//---------------------------------------------------------------------------

class EPDGetWorker : public SJSONTABLE
{
public:
  vector<EPDWORKER> Items;
private:
  int GetID(int idx) { return 1; }
public:
  EPDGetWorker(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class EPDGetPublBase : public SJSONTABLE
{
public:
  vector<EPDPUBL> Items;
private:
  int GetID(int idx) { return 1; }
public:
  EPDGetPublBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class EPDGetPublEnt : public EPDGetPublBase
{
public:
  EPDGetPublEnt(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class EPDGetPubl : public EPDGetPublBase
{
public:
  EPDGetPubl(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class EPDGetAuthors : public SJSONTABLE
{
public:
  map<int,int> Items;   // Order, Worker#
private:
  int GetID(int idx) { return 1; }
public:
  EPDGetAuthors(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

typedef struct
{
  int ContactNr;  // Contact#
  UnicodeString DataSource;
} EPDPENTITY;
//---------------------------------------------------------------------------

class EPDGetPEntity : public SJSONTABLE
{
public:
  vector<EPDPENTITY> Items;
private:
  int GetID(int idx) { return 1; }
public:
  EPDGetPEntity(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

typedef struct
{
  int SampleNr;       // Sample#
  double DepthCM;
  Variant Thickness;
  Variant AnalystNr;  // Analyst#
  UnicodeString AnalyDate;
  UnicodeString Notes;
} EPDPSAMPLE;
//---------------------------------------------------------------------------

class EPDGetPSample : public SJSONTABLE
{
public:
  vector<EPDPSAMPLE> Items;
private:
  int GetID(int idx) { return 1; }
public:
  EPDGetPSample(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

typedef struct
{
  int VarNr;              // Var#
  UnicodeString VarName;
  UnicodeString TaxonCode;
  UnicodeString TaxonName;
  UnicodeString Element;
  UnicodeString Units;
  UnicodeString Context;
  UnicodeString Taphonomy;
  UnicodeString EcolGroup;
} EPDPVAR;
//---------------------------------------------------------------------------

class EPDGetPVars : public SJSONTABLE
{
public:
  vector<EPDPVAR> Items;
private:
  int GetID(int idx) { return 1; }
public:
  EPDGetPVars(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

typedef struct
{
  int SampleNr;    // Sample#
  int VarNr;       // Var#
  double Count;
} EPDPCOUNT;
//---------------------------------------------------------------------------

class EPDGetPCounts : public SJSONTABLE
{
public:
  vector<EPDPCOUNT> Items;
private:
  int GetID(int idx) { return 1; }
public:
  EPDGetPCounts(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

typedef struct
{
  int SampleNr;
  UnicodeString Method;
  double DepthCM;
  Variant Thickness;
  UnicodeString MaterialDated;
  Variant PublNr;    // Publ#
} EPDGEOCHRON;
//---------------------------------------------------------------------------

class EPDGetGeochron : public SJSONTABLE
{
public:
  vector<EPDGEOCHRON> Items;
private:
  int GetID(int idx) { return 1; }
public:
  EPDGetGeochron(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

typedef struct
{
  Variant AgeBP;
  Variant AgeSDUp;
  Variant AgeSDLo;
  bool GrThanAge;     // Y,N
  UnicodeString Basis;
  UnicodeString LabNumber;
  Variant DeltaC13;
  UnicodeString Notes;
} EPDC14;
//---------------------------------------------------------------------------

class EPDGetC14 : public SJSONTABLE
{
public:
  map<int,EPDC14> Items;   // Sample#, EPDC14
private:
  int GetID(int idx) { return 1; }
public:
  EPDGetC14(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

typedef struct
{
  Variant AgeAD;
  Variant AgeSE;
  bool GrThanAge;     // Y,N
  UnicodeString Notes;
} EPDPB210;
//---------------------------------------------------------------------------

class EPDGetPb210 : public SJSONTABLE
{
public:
  map<int,EPDPB210> Items;   // Sample#, EPDPB210
private:
  int GetID(int idx) { return 1; }
public:
  EPDGetPb210(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

typedef struct
{
  Variant AgeBP;
  Variant ErrorLimits;
  UnicodeString GrainSize;
  UnicodeString LabNumber;
  UnicodeString Notes;
} EPDTL;
//---------------------------------------------------------------------------

class EPDGetTL : public SJSONTABLE
{
public:
  map<int,EPDTL> Items;   // Sample#, EPDTL
private:
  int GetID(int idx) { return 1; }
public:
  EPDGetTL(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

typedef struct
{
  Variant AgeBP;
  Variant ErrorLimits;
  UnicodeString LabNumber;
  UnicodeString Notes;
} EPDUSERIES;
//---------------------------------------------------------------------------

class EPDGetUSeries : public SJSONTABLE
{
public:
  map<int,EPDUSERIES> Items;   // Sample#, EPDTL
private:
  int GetID(int idx) { return 1; }
public:
  EPDGetUSeries(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

typedef struct
{
  int ChronNr;   // Chron#
  bool Default;  // Y,N
  UnicodeString Name;
  Variant DatePrepared;
  UnicodeString Model;
  UnicodeString Notes;
  Variant NeotomaContactID;
  Variant WorkerNr;
  Variant Top;
  Variant Bottom;
} EPDCHRON;
//---------------------------------------------------------------------------

class EPDGetChron : public SJSONTABLE
{
public:
  vector<EPDCHRON> Items;
private:
  int GetID(int idx) { return 1; }
public:
  EPDGetChron(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

typedef struct
{
  double DepthCM;
  Variant Thickness;
  Variant Age;
  Variant AgeUp;
  Variant AgeLo;
  UnicodeString RCode;
} EPDAGEBASIS;
//---------------------------------------------------------------------------

class EPDGetAgeBasis : public SJSONTABLE
{
public:
  vector<EPDAGEBASIS> Items;
private:
  int GetID(int idx) { return 1; }
public:
  EPDGetAgeBasis(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

typedef struct
{
  double DepthCM;
  Variant Thickness;
  UnicodeString Name;
  Variant AgeBP;
  Variant AgeUncertUp;
  Variant AgeUncertLo;
} EPDSYNEVENT;
//---------------------------------------------------------------------------

class EPDGetSynEvent : public SJSONTABLE
{
public:
  vector<EPDSYNEVENT> Items;
private:
  int GetID(int idx) { return 1; }
public:
  EPDGetSynEvent(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

typedef struct
{
  Variant AgeBP;
  Variant AgeUp;
  Variant AgeLo;
} EPDGETPAGEDPT;
//---------------------------------------------------------------------------

class EPDGetPAgeDpt : public SJSONTABLE
{
public:
  map<int,EPDGETPAGEDPT> Items;  // Sample#, EPDGETPAGEDPT
private:
  int GetID(int idx) { return 1; }
public:
  EPDGetPAgeDpt(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

typedef struct
{
  UnicodeString Descript;
  double DepthTopCM;
  double DepthBotCM;
  UnicodeString LoBoundary;
} EPDLITHOLOGY;
//---------------------------------------------------------------------------

class EPDGetLithology : public SJSONTABLE
{
public:
  vector<EPDLITHOLOGY> Items;
private:
  int GetID(int idx) { return 1; }
public:
  EPDGetLithology(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

typedef struct
{
  double DepthCM;
  Variant Thickness;
  Variant TempLo;
  Variant LOILo;
  Variant TempHi;
  Variant LOIHi;
  Variant BulkDens;
} EPDLOI;
//---------------------------------------------------------------------------

class EPDGetLOI : public SJSONTABLE
{
public:
  vector<EPDLOI> Items;
private:
  int GetID(int idx) { return 1; }
public:
  EPDGetLOI(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class EPDGetMADCAPAgeModel : public SJSONTABLE
{
public:
  vector<int> Items;
private:
  int GetID(int idx) { return 1; }
public:
  EPDGetMADCAPAgeModel(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

typedef struct
{
  double DepthCM;
  Variant Thickness;
  UnicodeString RCode;
  UnicodeString LabNr;
  Variant Age14C;
  Variant AgeCal;
  Variant SD;
  Variant Reservoir;
} MADCAPCHRONCONTROL;
//---------------------------------------------------------------------------

class EPDGetMADCAPChronControls : public SJSONTABLE
{
public:
  vector<MADCAPCHRONCONTROL> Items;
private:
  int GetID(int idx) { return 1; }
public:
  EPDGetMADCAPChronControls(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class EPDGetMADCAPContactNotes : public SJSONTABLE
{
public:
  vector<pair<int,UnicodeString> > Items;
private:
  int GetID(int idx) { return 1; }
public:
  EPDGetMADCAPContactNotes(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class EPDGetMADCAPReliableAges : public SJSONTABLE
{
public:
  vector<pair<Variant,Variant> > Items;
private:
  int GetID(int idx) { return 1; }
public:
  EPDGetMADCAPReliableAges(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

typedef struct
{
  double Age;
  double AgeMin;
  double AgeMax;
} MADCAPSAMPLEAGE;
//---------------------------------------------------------------------------

class EPDGetMADCAPSampleAges : public SJSONTABLE
{
public:
  map<double,MADCAPSAMPLEAGE> Items;
private:
  int GetID(int idx) { return 1; }
public:
  EPDGetMADCAPSampleAges(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class EPDGetNeotomaSiteCollUnitIDs : public SJSONTABLE
{
public:
  vector<pair<int,int> > Items;
private:
  int GetID(int idx) { return 1; }
public:
  EPDGetNeotomaSiteCollUnitIDs(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class EPDGetNeotomaDatasetIDs : public SJSONTABLE
{
public:
  map<int,int> Items;
private:
  int GetID(int idx) { return 1; }
public:
  EPDGetNeotomaDatasetIDs(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

#endif
