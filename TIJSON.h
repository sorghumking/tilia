//---------------------------------------------------------------------------

#ifndef TIJSONH
#define TIJSONH
//---------------------------------------------------------------------------
#include "ipwcore.h"
#include "ipworks.h"
#include "ipwhttp.h"
#include "ipwjson.h"
#include "ipshttps.h"
#include "ipsjsons.h"
#include <Sockets.hpp>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#ifndef TGUtilsH
#include "TGUtils.h"
#endif

//---------------------------------------------------------------------------

UnicodeString TransJSONescapes(UnicodeString);
UnicodeString TransJSONescapes(Variant);
//---------------------------------------------------------------------------

class EncodeURL
{
private:
   UnicodeString delimiters;
   map<UnicodeString, UnicodeString> SafeCodes;
public:
   EncodeURL();
   UnicodeString Encode(UnicodeString Value);
};
//---------------------------------------------------------------------------

/*
typedef struct
{
  UnicodeString Code;
  UnicodeString Name;
} CODENAME;
*/
//---------------------------------------------------------------------------

struct mapSameText
{
  bool operator() (const UnicodeString& lhs, const UnicodeString& rhs) const
  { return lhs.LowerCase() < rhs.LowerCase(); }
};
//---------------------------------------------------------------------------

typedef struct
{
  UnicodeString Name;
  int Type;
  multimap<UnicodeString, void*, mapSameText> SIndex;
  multimap<int, void*> Index;
} JSONFIELD;
//---------------------------------------------------------------------------

/*
class JSONDOM       // uses http component
{
private:
  TipwHTTP *ipwHTTP;
protected:
  UnicodeString webservice;
  map<UnicodeString, UnicodeString> Parameters;
  vector<JSONFIELD> Fields;
  map<UnicodeString, int> FieldPos;
  int FindID(int id);
private:
  bool ParseRecord(UnicodeString Record);
  virtual void AddRecord(vector<Variant>& Record) = 0;
  virtual void IndexItems(void) = 0;
  virtual unsigned int Size(void) = 0;
  virtual int GetID(int idx) = 0;
public:
  JSONDOM(TipwHTTP *ipwhttp, TTcpClient *tcpClient);
  void AddField(UnicodeString ElementName, int Type);
  bool Get(UnicodeString url);
  UnicodeString WebServiceName(void) { return webservice; }
  bool Execute(void);
  int Find(UnicodeString FieldName, UnicodeString Value, vector<void*>& vptrs);
  int Find(UnicodeString FieldName, int ID, vector<void*>& vptrs);
};
//---------------------------------------------------------------------------
*/

class JSONTABLE      // uses json component
{
private:
  TipwJSON *ipwJSON;
  UnicodeString Furl;
protected:
  UnicodeString webservice;
  map<UnicodeString, UnicodeString> FParameters;
  vector<JSONFIELD> FFields;
  map<UnicodeString, int> FieldPos;
protected:
  int FindID(int id);
  virtual void AddRecord(vector<Variant>& Record) = 0;
  virtual void IndexItems(void) = 0;
private:
  bool Parse(void);
  EncodeURL encode_url;
  virtual unsigned int Size(void) = 0;
  virtual int GetID(int idx) = 0;
  vector<vector<Variant> > FTable;
public:
  JSONTABLE(TipwJSON *ipwjson, TTcpClient *tcpClient);
  JSONTABLE() { };
  void AddParam(UnicodeString Param, UnicodeString Value);
  void AddParam(UnicodeString Param, int Value);
  void AddParam(UnicodeString Param, bool Value);
  void AddParam(UnicodeString Param, double Value);
  void AddField(UnicodeString FieldName, int Type);
  bool Get(UnicodeString url);
  UnicodeString WebServiceName(void) { return webservice; }
  bool Execute(void);
  int Find(UnicodeString FieldName, UnicodeString Value, vector<void*>& vptrs);
  int Find(UnicodeString FieldName, int ID, vector<void*>& vptrs);
  UnicodeString TransferredData(void) { return ipwJSON->TransferredData; }
  __property map<UnicodeString, UnicodeString> Parameters = {read = FParameters, write = FParameters};
  __property vector<JSONFIELD> Fields = {read = FFields, write = FFields};
  __property vector<vector<Variant> > Table = {read = FTable};
  __property UnicodeString url = {read = Furl, write = Furl};
};
//---------------------------------------------------------------------------

class SJSONTABLE : public JSONTABLE
{
private:
	TipsJSONS *ipsJSONS;
private:
	bool Parse(void);
public:
	SJSONTABLE(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
	bool Get(UnicodeString url);
	bool Execute(void);
	UnicodeString TransferredData(void) { return ipsJSONS->TransferredData; }
};
//---------------------------------------------------------------------------

//class TAXONRECORD
typedef struct
{
  Variant TaxonID;
  Variant TaxonCode;
  Variant TaxonName;
  Variant Author;
  Variant Valid;
  Variant HigherTaxonID;
  Variant Extinct;
  Variant TaxaGroupID;
  Variant PublicationID;
  Variant ValidatorID;
  Variant ValidateDate;
  Variant Notes;
} TAXONRECORD;
//---------------------------------------------------------------------------

class NeotomaTaxaBase : public SJSONTABLE
{
public:
  vector<TAXONRECORD> Items;
private:
  // int GetID(int idx) { return Items[idx].TaxonID; }
  // int GetID(int idx);
  int GetID(int idx) { return 0; }
public:
  NeotomaTaxaBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  unsigned int Size(void) { return Items.size(); }
  void IndexItems(void);
  // TAXONRECORD* FindID(int id) { int idx = JSONTABLE::FindID(id); return((idx >= 0) ? &Items[idx] : NULL ); }
  TAXONRECORD* FindID(int id);
};
//---------------------------------------------------------------------------

class NeotomaTaxaTable : public NeotomaTaxaBase
{
public:
  NeotomaTaxaTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaTaxaByTaxaGroupID : public NeotomaTaxaBase
{
public:
  NeotomaTaxaByTaxaGroupID(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaTaxaByNameList : public NeotomaTaxaBase
{
public:
  NeotomaTaxaByNameList(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void ReIndexItems(void) { IndexItems(); };
};
//---------------------------------------------------------------------------

class NeotomaValidTaxaByTaxaGroupIDList : public NeotomaTaxaBase
{
public:
  NeotomaValidTaxaByTaxaGroupIDList(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaInvalidTaxaByTaxaGroupIDList : public NeotomaTaxaBase
{
public:
  NeotomaInvalidTaxaByTaxaGroupIDList(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaValidTaxaByTaxaGroupID : public NeotomaTaxaBase
{
public:
  NeotomaValidTaxaByTaxaGroupID(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaInvalidTaxaByTaxaGroupID : public NeotomaTaxaBase
{
public:
  NeotomaInvalidTaxaByTaxaGroupID(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaTaxonByID : public NeotomaTaxaBase
{
public:
  NeotomaTaxonByID(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class TaxonByName : public NeotomaTaxaBase
{
public:
  TaxonByName(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class ValidTaxonByName : public NeotomaTaxaBase
{
public:
  ValidTaxonByName(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class InvalidTaxonByName : public NeotomaTaxaBase
{
public:
  InvalidTaxonByName(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaTaxaByCodeAndTaxaGroupID : public NeotomaTaxaBase
{
public:
  NeotomaTaxaByCodeAndTaxaGroupID(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

typedef struct
{
  Variant TaxonID;
  Variant TaxonCode;
  Variant TaxonName;
  Variant Author;
  Variant Valid;
  Variant HigherTaxonID;
  Variant Extinct;
  Variant TaxaGroupID;
  Variant PublicationID;
  Variant ValidatorID;
  Variant ValidateDate;
  Variant Notes;
  Variant SynonymTypeID;
} SYNONYMTAXONRECORD;
//---------------------------------------------------------------------------

class NeotomaSynonymsBase : public SJSONTABLE
{
public:
  vector<SYNONYMTAXONRECORD> Items;
private:
  int GetID(int idx) { return Items[idx].TaxonID; }
public:
  NeotomaSynonymsBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  unsigned int Size(void) { return Items.size(); }
  void IndexItems(void) { }
};
//---------------------------------------------------------------------------

class NeotomaSynonymsForValidTaxonID : public NeotomaSynonymsBase
{
public:
  NeotomaSynonymsForValidTaxonID(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaSynonymsForInvalidTaxonID : public NeotomaSynonymsBase
{
public:
  NeotomaSynonymsForInvalidTaxonID(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaDatasetTypesBase : public SJSONTABLE
{
public:
  map<int,UnicodeString> Items;
private:
  int GetID(int idx) { return 0; }
public:
  NeotomaDatasetTypesBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaDatasetTypesTable : public NeotomaDatasetTypesBase
{
public:
  NeotomaDatasetTypesTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaDatasetTypesHavingData : public NeotomaDatasetTypesBase
{
public:
  NeotomaDatasetTypesHavingData(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaDatasetTypesByTaxaGroupID : public NeotomaDatasetTypesBase
{
public:
  NeotomaDatasetTypesByTaxaGroupID(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaDatasetTypesByName : public NeotomaDatasetTypesBase
{
public:
  NeotomaDatasetTypesByName(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class TaxaGroupsBase : public SJSONTABLE
{
public:
  map<UnicodeString, UnicodeString> Items;
private:
  int GetID(int idx) { return 0; }
public:
  TaxaGroupsBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class TaxaGroupsForDatasetType : public TaxaGroupsBase
{
public:
  TaxaGroupsForDatasetType(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaGetTaxaGroupID : public TaxaGroupsBase
{
public:
  NeotomaGetTaxaGroupID(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaGetTaxaGroupByID : public TaxaGroupsBase
{
public:
  NeotomaGetTaxaGroupByID(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

/*
//{"TaxaGroup":"Vascular plants","TaxaGroupID":"VPL"}
typedef struct
{
  Variant TaxaGroupID;
  Variant TaxaGroup;
} TAXAGROUPRECORD;
//---------------------------------------------------------------------------
*/

typedef struct
{
  Variant TaxaGroupID;
  Variant TaxaGroup;
  Variant EcolGroupID;
  Variant EcolGroup;
} TAXAGROUPCODERECORD;
//---------------------------------------------------------------------------

class NeotomaTaxaGroupCodesBase : public SJSONTABLE
{
public:
  vector<TAXAGROUPCODERECORD> Items;
private:
  int GetID(int idx) { return 0; }
public:
  NeotomaTaxaGroupCodesBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { };
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaDynamicTaxaGroupCodes : public NeotomaTaxaGroupCodesBase
{
public:
  NeotomaDynamicTaxaGroupCodes(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaPredefinedTaxaGroupCodes : public NeotomaTaxaGroupCodesBase
{
public:
  NeotomaPredefinedTaxaGroupCodes(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

//{"EcolSetID":2,"TaxonID":8005,"EcolGroupID":"ACCI"}
typedef struct
{
  Variant EcolSetID;
  Variant TaxonID;
  Variant EcolGroupID;
} ECOLGROUPRECORD;
//---------------------------------------------------------------------------

class NeotomaEcolGroupsTableBase : public SJSONTABLE
{
public:
  vector<ECOLGROUPRECORD> Items;
private:
  int GetID(int idx) { return 0; }
public:
  NeotomaEcolGroupsTableBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void);
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaEcolGroupsTable : public NeotomaEcolGroupsTableBase
{
public:
  NeotomaEcolGroupsTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaEcolGroupsByTaxaGroupIDList : public NeotomaEcolGroupsTableBase
{
public:
  NeotomaEcolGroupsByTaxaGroupIDList(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

//{"VariableElement":"pollen","VariableElementID":141}
class NeotomaVariableElementsTable : public SJSONTABLE
{
public:
  map<int, UnicodeString> Items;
private:
  int GetID(int idx) { return 0; }
public:
  NeotomaVariableElementsTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

//{"VariableUnitsID":19,"VariableUnits":"NISP"}
class NeotomaVariableUnitsTable : public SJSONTABLE
{
public:
  map<int, UnicodeString> Items;
private:
  int GetID(int idx) { return 0; }
public:
  NeotomaVariableUnitsTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaVariableContextsTable : public SJSONTABLE
{
public:
  map<int, UnicodeString> Items;
private:
  int GetID(int idx) { return 0; }
public:
  NeotomaVariableContextsTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

typedef struct
{
  int VariableID;
  int TaxonID;
  int VariableElementID;
  int VariableUnitsID;
  int VariableContextID;
} VARIABLERECORD;
//---------------------------------------------------------------------------

class NeotomaVariablesBase : public SJSONTABLE
{
public:
  vector<VARIABLERECORD> Items;
private:
  int GetID(int idx) { return Items[idx].VariableID; }
public:
  NeotomaVariablesBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  unsigned int Size(void) { return Items.size(); }
  void IndexItems(void);
  VARIABLERECORD* FindID(int id) { int idx = JSONTABLE::FindID(id); return((idx >=0) ? &Items[idx] : NULL ); }
};
//---------------------------------------------------------------------------

/*
class NeotomaVariablesTable : public NeotomaVariablesBase
{
public:
  NeotomaVariablesTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------
*/

class NeotomaVariablesByTaxaGroupIDList : public NeotomaVariablesBase
{
public:
  NeotomaVariablesByTaxaGroupIDList(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaVariablesByTaxonID : public NeotomaVariablesBase
{
public:
  NeotomaVariablesByTaxonID(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaVariableByComponents : public NeotomaVariablesBase
{
public:
  NeotomaVariableByComponents(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaVariableByID : public NeotomaVariablesBase
{
public:
  NeotomaVariableByID(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

typedef struct
{
  int GeoPoliticalID;
  UnicodeString GeoPoliticalName;
  UnicodeString GeoPoliticalUnit;
  int Rank;
  int HigherGeoPoliticalID;
} NTMGEOPOLRECORD;
//---------------------------------------------------------------------------

class NeotomaCollectionTypesBase : public SJSONTABLE
{
public:
  map<int, UnicodeString> Items;
private:
  int GetID(int idx) { return 0; }
public:
  NeotomaCollectionTypesBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaCollectionTypesTable : public NeotomaCollectionTypesBase
{
public:
  NeotomaCollectionTypesTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaCollectionTypeByID : public NeotomaCollectionTypesBase
{
public:
  NeotomaCollectionTypeByID(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

typedef struct
{
  int DepEnvtID;
  UnicodeString DepEnvt;
  int DepEnvtHigherID;
} DEPENVTRECORD;
//---------------------------------------------------------------------------

class NeotomaDepEnvtTypeBase : public SJSONTABLE
{
public:
  vector<DEPENVTRECORD> Items;
private:
  int GetID(int idx) { return Items[idx].DepEnvtID; }
public:
  NeotomaDepEnvtTypeBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void);
  unsigned int Size(void) { return Items.size(); }
  DEPENVTRECORD* FindID(int id) { int idx = JSONTABLE::FindID(id); return((idx >=0) ? &Items[idx] : NULL ); }
};
//---------------------------------------------------------------------------

class NeotomaDepEnvtTypesTable : public NeotomaDepEnvtTypeBase
{
public:
  NeotomaDepEnvtTypesTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaDepEnvtTypeByID : public NeotomaDepEnvtTypeBase
{
public:
  NeotomaDepEnvtTypeByID(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------


//{"DatabaseID":1,"DatabaseName":"Cooperative Holocene Mapping Project"},
//{"DatabaseID":2,"DatabaseName":"African Pollen Database"},

class ConstituentDatabases : public SJSONTABLE
{
public:
  map<int, UnicodeString> Items;
private:
  int GetID(int idx) { return 0; }
public:
  ConstituentDatabases(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class SSL_ConstituentDatabases : public SJSONTABLE
{
public:
  map<int, UnicodeString> Items;
private:
  int GetID(int idx) { return 0; }
public:
  SSL_ConstituentDatabases(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class ConstituentDatabaseNameByID : public SJSONTABLE
{
public:
  vector<UnicodeString> Items;
private:
  int GetID(int idx) { return 1; }
public:
  ConstituentDatabaseNameByID(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

//"DatabaseID":11
class ValidatedDatabases : public SJSONTABLE
{
public:
  vector<int> Items;
private:
  int GetID(int idx) { return 0; }
public:
  ValidatedDatabases(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

//"username":1
class ValidateUserName : public SJSONTABLE
{
public:
  //vector<UnicodeString> Items;
  map<int, bool> Items;
private:
  int GetID(int idx) { return 0; }
public:
  ValidateUserName(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class GeoPoliticalUnits : public SJSONTABLE
{
public:
  vector<NTMGEOPOLRECORD> Items;
private:
  int GetID(int idx) { return Items[idx].GeoPoliticalID; }
  static bool GeoPolComp (NTMGEOPOLRECORD gp1, NTMGEOPOLRECORD gp2)
	{ return (gp1.GeoPoliticalID < gp2.GeoPoliticalID); }
public:
  GeoPoliticalUnits(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { };
  unsigned int Size(void) { return Items.size(); }
  void Sort(void);
};
//---------------------------------------------------------------------------

class GeoPolUnitsByRank : public GeoPoliticalUnits
{
public:
  GeoPolUnitsByRank(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class GeoPolUnitsByNameAndRank : public GeoPoliticalUnits
{
public:
  GeoPolUnitsByNameAndRank(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class GeoPolUnitByNameAndHigherID : public GeoPoliticalUnits
{
public:
  GeoPolUnitByNameAndHigherID(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class GeoPolUnitByID : public GeoPoliticalUnits
{
public:
  GeoPolUnitByID(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class GeoPolUnitByHigherID : public GeoPoliticalUnits
{
public:
  GeoPolUnitByHigherID(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class GeoPolUnitsBySiteID : public GeoPoliticalUnits
{
public:
  GeoPolUnitsBySiteID(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NumberOfGeoPolSubdivs : public SJSONTABLE
{
public:
  Variant NumberOfSubdivs;
private:
  int GetID(int idx) { return 0; }
public:
  NumberOfGeoPolSubdivs(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { };
  unsigned int Size(void) { return (NumberOfSubdivs.IsEmpty() ? 0 : 1); }
};
//---------------------------------------------------------------------------

typedef struct
{
  int LakeParameterID;
  UnicodeString LakeParameterCode;
  UnicodeString LakeParameter;
  UnicodeString LakeParameterShortName;
} LAKEPARAMRECORD;
//---------------------------------------------------------------------------

class NeotomaLakeParameterTypesTable : public SJSONTABLE
{
public:
  vector<LAKEPARAMRECORD> Items;
private:
  int GetID(int idx) { return Items[idx].LakeParameterID; }
public:
  NeotomaLakeParameterTypesTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void);
  unsigned int Size(void) { return Items.size(); }
  //LAKEPARAMRECORD* FindID(int id) { int idx = JSONTABLE::FindID(id); return((idx >=0) ? &Items[idx] : NULL ); }
};
//---------------------------------------------------------------------------

class NeotomaSiteLakeParams : public SJSONTABLE
{
public:
  vector<pair<UnicodeString,double> > Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaSiteLakeParams(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------


typedef struct
{
  int SiteID;
  UnicodeString SiteName;
  double DistKm;
  UnicodeString Geopolitical;
} NEOTOMASITE;
//---------------------------------------------------------------------------

class NeotomaSiteGeoPolBase : public SJSONTABLE
{
public:
  vector<NEOTOMASITE> Items;
private:
  int GetID(int idx) { return Items[idx].SiteID; }
public:
  NeotomaSiteGeoPolBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaGeoPolBySiteName : public NeotomaSiteGeoPolBase
{
public:
  NeotomaGeoPolBySiteName(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaNearestSites : public NeotomaSiteGeoPolBase
{
public:
  NeotomaNearestSites(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

void DecodeGeog(UnicodeString geog, double& East, double& North, double& West, double& South);
//---------------------------------------------------------------------------

typedef struct
{
  int SiteID;
  UnicodeString SiteName;
  double LongitudeEast;
  double LatitudeNorth;
  double LongitudeWest;
  double LatitudeSouth;
  Variant Altitude;
  Variant Area;
  UnicodeString SiteDescription;
  UnicodeString Notes;
} NEOTOMASITEMETADATA;
//---------------------------------------------------------------------------

class NeotomaSiteMetaDataBase : public SJSONTABLE
{
public:
  vector<NEOTOMASITEMETADATA> Items;
private:
  int GetID(int idx) { return Items[idx].SiteID; }
public:
  NeotomaSiteMetaDataBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

//GetSiteMetaData
class NeotomaSiteMetaDataBySiteID: public NeotomaSiteMetaDataBase
{
public:
  NeotomaSiteMetaDataBySiteID(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

typedef struct
{
  UnicodeString SiteName;
  double LongitudeEast;
  double LatitudeNorth;
  double LongitudeWest;
  double LatitudeSouth;
  UnicodeString GeoPolName1;
  UnicodeString GeoPolName2;
} NEOTOMASITELOC;
//---------------------------------------------------------------------------

class NeotomaSiteLocBase : public SJSONTABLE
{
public:
  map<int,NEOTOMASITELOC> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaSiteLocBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaSites : public NeotomaSiteLocBase
{
public:
  NeotomaSites(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

typedef struct
{
  int SiteID;
  UnicodeString SiteName;
  double Longitude;
  double Latitude;
  double Area;
  double Altitude;
} NEOTOMASITELOC2;
//---------------------------------------------------------------------------

class NeotomaSiteBase : public SJSONTABLE
{
public:
  vector<NEOTOMASITELOC2> Items;
private:
  int GetID(int idx) { return Items[idx].SiteID; }
public:
  NeotomaSiteBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaSitesByDatabaseAndDatasetType : public NeotomaSiteBase
{
public:
  NeotomaSitesByDatabaseAndDatasetType(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaSitesByDatasetType : public NeotomaSiteBase
{
public:
  NeotomaSitesByDatasetType(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

typedef struct
{
  Variant CollectionUnitID;
  Variant CollUnitName;
  Variant DatasetID;
  Variant DatasetType;
} NTMSITEDATASETS;
//---------------------------------------------------------------------------

class NeotomaSiteDatasets : public SJSONTABLE
{
public:
  vector<NTMSITEDATASETS> Items;
private:
  int GetID(int idx) { return Items[idx].DatasetID; }
public:
  NeotomaSiteDatasets(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

typedef struct
{
  Variant PIOrder;
  Variant FamilyName;
  Variant LeadingInitials;
} NTMDATASETPIS;
//---------------------------------------------------------------------------

class NeotomaDatasetPIsBase : public SJSONTABLE
{
public:
  vector<NTMDATASETPIS> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaDatasetPIsBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaDatasetPIs : public NeotomaDatasetPIsBase
{
public:
  NeotomaDatasetPIs(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

typedef struct
{
  int ContactID;
  UnicodeString ContactName;
  int DatasetID;
  int DatasetTypeID;
} NTMPIAUTHORDATASET;
//---------------------------------------------------------------------------

class NeotomaDatasetContactsDatasetTypesBase : public SJSONTABLE
{
public:
  vector<NTMPIAUTHORDATASET> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaDatasetContactsDatasetTypesBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaDatasetPIsDatasetTypes : public NeotomaDatasetContactsDatasetTypesBase
{
public:
  NeotomaDatasetPIsDatasetTypes(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaDatasetAuthorsDatasetTypes : public NeotomaDatasetContactsDatasetTypesBase
{
public:
  NeotomaDatasetAuthorsDatasetTypes(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

typedef struct
{
  Variant PrimaryPub;
  Variant PublicationID;
  Variant Citation;
} NTMDATASETPUBS;
//---------------------------------------------------------------------------

class NeotomaDatasetPubs : public SJSONTABLE
{
public:
  vector<NTMDATASETPUBS> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaDatasetPubs(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaTaxonUnits : public SJSONTABLE
{
public:
  vector<UnicodeString> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaTaxonUnits(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaTaxonElements : public SJSONTABLE
{
public:
  vector<UnicodeString> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaTaxonElements(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaTaxaGroupTypesTable : public SJSONTABLE
{
public:
  map<UnicodeString, UnicodeString> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaTaxaGroupTypesTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

typedef struct
{
  int PublicationID;
  int PubTypeID;
  UnicodeString Year;
  UnicodeString Citation;
  UnicodeString ArticleTitle;
  UnicodeString Journal;
  UnicodeString Volume;
  UnicodeString Issue;
  UnicodeString Pages;
  UnicodeString CitationNumber;
  UnicodeString DOI;
  UnicodeString BookTitle;
  UnicodeString Edition;
  UnicodeString VolumeTitle;
  UnicodeString NumVolumes;
  UnicodeString SeriesTitle;
  UnicodeString SeriesVolume;
  UnicodeString Publisher;
  UnicodeString URL;
  UnicodeString City;
  UnicodeString State;
  UnicodeString Country;
  UnicodeString OriginalLanguage;
  UnicodeString Notes;
} NTMPUBLICATION;
//---------------------------------------------------------------------------

class NeotomaPublicationsBase : public SJSONTABLE
{
public:
  vector<NTMPUBLICATION> Items;
private:
  int GetID(int idx) { return Items[idx].PublicationID; }
public:
  NeotomaPublicationsBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void);
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaPublicationsByPubID : public NeotomaPublicationsBase
{
public:
  NeotomaPublicationsByPubID(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaPublicationsByPubIDList : public NeotomaPublicationsBase
{
public:
  NeotomaPublicationsByPubIDList(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaPublicationsByCitation : public NeotomaPublicationsBase
{
public:
  NeotomaPublicationsByCitation(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaPublicationsByFamilyName : public NeotomaPublicationsBase
{
public:
  NeotomaPublicationsByFamilyName(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaPublicationsByContactID : public NeotomaPublicationsBase
{
public:
  NeotomaPublicationsByContactID(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaNextPublicationByID : public NeotomaPublicationsBase
{
public:
  NeotomaNextPublicationByID(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaPreviousPublicationByID : public NeotomaPublicationsBase
{
public:
  NeotomaPreviousPublicationByID(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaNextPublicationByIDAndPubTypeID : public NeotomaPublicationsBase
{
public:
  NeotomaNextPublicationByIDAndPubTypeID(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaPreviousPublicationByIDAndPubTypeID : public NeotomaPublicationsBase
{
public:
  NeotomaPreviousPublicationByIDAndPubTypeID(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaEventPublications : public NeotomaPublicationsBase
{
public:
  NeotomaEventPublications(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaRelativeAgePublications : public NeotomaPublicationsBase
{
public:
  NeotomaRelativeAgePublications(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaDatasetPublications : public NeotomaPublicationsBase
{
public:
  NeotomaDatasetPublications(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

typedef struct
{
  int AuthorID;
  int PublicationID;
  int AuthorOrder;
  UnicodeString FamilyName;
  UnicodeString Initials;
  UnicodeString Suffix;
  int ContactID;
} NTMAUTHOR;
//---------------------------------------------------------------------------

class NeotomaPublicationAuthors : public SJSONTABLE
{
public:
  vector<NTMAUTHOR> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaPublicationAuthors(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

typedef struct
{
  int EditorID;
  int PublicationID;
  int EditorOrder;
  UnicodeString FamilyName;
  UnicodeString Initials;
  UnicodeString Suffix;
} NTMEDITOR;
//---------------------------------------------------------------------------

class NeotomaPublicationEditors : public SJSONTABLE
{
public:
  vector<NTMEDITOR> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaPublicationEditors(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

typedef struct
{
  int TranslatorID;
  int PublicationID;
  int TranslatorOrder;
  UnicodeString FamilyName;
  UnicodeString Initials;
  UnicodeString Suffix;
} NTMTRANSLATOR;
//---------------------------------------------------------------------------

class NeotomaPublicationTranslators : public SJSONTABLE
{
public:
  vector<NTMTRANSLATOR> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaPublicationTranslators(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

typedef struct
{
  int ContactID;
  int AliasID;
  int ContactStatusID;
  UnicodeString ContactName;
  UnicodeString FamilyName;
  UnicodeString GivenNames;
  UnicodeString LeadingInitials;
  UnicodeString Suffix;
  UnicodeString Title;
  UnicodeString Email;
  UnicodeString Phone;
  UnicodeString Fax;
  UnicodeString URL;
  UnicodeString Address;
  UnicodeString Notes;
} NTMCONTACT;
//---------------------------------------------------------------------------

class NeotomaContactBase : public SJSONTABLE
{
public:
  vector<NTMCONTACT> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaContactBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaContactByID : public NeotomaContactBase
{
public:
  NeotomaContactByID(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaContactByFamilyName : public NeotomaContactBase
{
public:
  NeotomaContactByFamilyName(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaContactByFamilyNameAndInitials : public NeotomaContactBase
{
public:
  NeotomaContactByFamilyNameAndInitials(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaContactByContactName : public NeotomaContactBase
{
public:
  NeotomaContactByContactName(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaCollector : public NeotomaContactBase
{
public:
  NeotomaCollector(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaInvestigator : public NeotomaContactBase
{
public:
  NeotomaInvestigator(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaDataProcessor : public NeotomaContactBase
{
public:
  NeotomaDataProcessor(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

typedef struct
{
  int ContactStatusID;
  UnicodeString ContactStatus;
  UnicodeString StatusDescription;
} NTMCONTACTSTATUS;
//---------------------------------------------------------------------------

//class NeotomaContactStatusesTable : public SJSONTABLE
class NeotomaContactStatusesTable : public SJSONTABLE
{
public:
  vector<NTMCONTACTSTATUS> Items;
private:
  int GetID(int idx) { return Items[idx].ContactStatusID; }
public:
  //NeotomaContactStatusesTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  NeotomaContactStatusesTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void);
  unsigned int Size(void) { return Items.size(); }
  NTMCONTACTSTATUS* FindID(int id) { int idx = JSONTABLE::FindID(id); return((idx >=0) ? &Items[idx] : NULL ); }
};
//---------------------------------------------------------------------------

typedef struct
{
  Variant DatasetID;
  Variant SiteID;
  Variant DatasetType;
  Variant SiteName;
  Variant GeoPolName1;
  Variant GeoPolName2;
  Variant GeoPolName3;
} NTMCONTACTDATASET;
//---------------------------------------------------------------------------

class NeotomaContactDatasets : public SJSONTABLE
{
public:
  vector<NTMCONTACTDATASET> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaContactDatasets(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaTaxaElements : public SJSONTABLE
{
public:
  multimap<int, UnicodeString> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaTaxaElements(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

typedef struct
{
  Variant DatasetTypeID;
  Variant TaxaGroupID;
  Variant ElementTypeID;
} NTMDATASETTAXAGROUPELEMET;
//---------------------------------------------------------------------------

class NeotomaElementDatasetTaxaGroupsTable : public SJSONTABLE
{
public:
  vector<NTMDATASETTAXAGROUPELEMET> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaElementDatasetTaxaGroupsTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaElementTypesBase : public SJSONTABLE
{
public:
  map<int, UnicodeString> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaElementTypesBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaElementTypesTable : public NeotomaElementTypesBase
{
public:
   NeotomaElementTypesTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaElementTypeByName : public NeotomaElementTypesBase
{
public:
   NeotomaElementTypeByName(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaElementTypesByTaxaGroupID : public NeotomaElementTypesBase
{
public:
   NeotomaElementTypesByTaxaGroupID(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaElementTypeFromVariableElement : public NeotomaElementTypesBase
{
public:
   NeotomaElementTypeFromVariableElement(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaElementTypesByNameList : public NeotomaElementTypesBase
{
public:
   NeotomaElementTypesByNameList(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

typedef struct
{
  Variant ElementTaxaGroupID;
  Variant TaxaGroupID;
  Variant ElementTypeID;
} NTMELEMENTTAXAGROUPS;
//---------------------------------------------------------------------------

class NeotomaElementTaxaGroupsTable : public SJSONTABLE
{
public:
  vector<NTMELEMENTTAXAGROUPS> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaElementTaxaGroupsTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaElementSymmetriesBase : public SJSONTABLE
{
public:
  map<int, UnicodeString> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaElementSymmetriesBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaElementSymmetriesTable : public NeotomaElementSymmetriesBase
{
public:
  NeotomaElementSymmetriesTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaElementSymmetryByName : public NeotomaElementSymmetriesBase
{
public:
  NeotomaElementSymmetryByName(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaElementTaxaGroupSymmetriesTable : public SJSONTABLE
{
public:
  multimap<int, int> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaElementTaxaGroupSymmetriesTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaElementPortionsBase : public SJSONTABLE
{
public:
  map<int, UnicodeString> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaElementPortionsBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaElementPortionsTable : public NeotomaElementPortionsBase
{
public:
  NeotomaElementPortionsTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaElementPortionByName : public NeotomaElementPortionsBase
{
public:
  NeotomaElementPortionByName(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaElementTaxaGroupPortionsTable : public SJSONTABLE
{
public:
  multimap<int, int> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaElementTaxaGroupPortionsTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaElementMaturitiesBase : public SJSONTABLE
{
public:
  map<int, UnicodeString> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaElementMaturitiesBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaElementMaturitiesTable : public NeotomaElementMaturitiesBase
{
public:
  NeotomaElementMaturitiesTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaElementMaturityByName : public NeotomaElementMaturitiesBase
{
public:
  NeotomaElementMaturityByName(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaElementTaxaGroupMaturitiesTable : public SJSONTABLE
{
public:
  multimap<int, int> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaElementTaxaGroupMaturitiesTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaUnitsDatasetTypesTable : public SJSONTABLE
{
public:
  multimap<int, int> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaUnitsDatasetTypesTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaContextsDatasetTypesTable : public SJSONTABLE
{
public:
  multimap<int, int> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaContextsDatasetTypesTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

typedef struct
{
  int TaphonomicSystemID;
  UnicodeString TaphonomicSystem;
  UnicodeString Notes;
} NTMTAPHONOMICSYSTEMS;
//---------------------------------------------------------------------------

class NeotomaTaphonomicSystemsBase : public SJSONTABLE
{
public:
  vector<NTMTAPHONOMICSYSTEMS> Items;
private:
  int GetID(int idx) { return Items[idx].TaphonomicSystemID; }
public:
  NeotomaTaphonomicSystemsBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void);
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaTaphonomicSystemsTable : public NeotomaTaphonomicSystemsBase
{
public:
  NeotomaTaphonomicSystemsTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaTaphonomicSystemsByDatasetType : public NeotomaTaphonomicSystemsBase
{
public:
  NeotomaTaphonomicSystemsByDatasetType(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaTaphonomicSystemByName : public NeotomaTaphonomicSystemsBase
{
public:
  NeotomaTaphonomicSystemByName(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaTaphonomicSystemsDatasetTypesTable : public SJSONTABLE
{
public:
  multimap<int,int> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaTaphonomicSystemsDatasetTypesTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

typedef struct
{
  int TaphonomicTypeID;
  int TaphonomicSystemID;
  UnicodeString TaphonomicType;
  UnicodeString Notes;
} NTMTAPHONOMICTYPES;
//---------------------------------------------------------------------------

class NeotomaTaphonomicTypesBase : public SJSONTABLE
{
public:
  vector<NTMTAPHONOMICTYPES> Items;
private:
  int GetID(int idx) { return Items[idx].TaphonomicTypeID; }
public:
  NeotomaTaphonomicTypesBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaTaphonomicTypesTable : public NeotomaTaphonomicTypesBase
{
public:
  NeotomaTaphonomicTypesTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaTaphonomicTypesBySystem : public NeotomaTaphonomicTypesBase
{
public:
  NeotomaTaphonomicTypesBySystem(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void IndexItems(void);
};
//---------------------------------------------------------------------------

typedef struct
{
  int SynonymID;
  int InvalidTaxonID;
  int ValidTaxonID;
  int SynonymTypeID;
} NTMSYNONYM;
//---------------------------------------------------------------------------

class NeotomaSynonym : public SJSONTABLE
{
public:
  vector<NTMSYNONYM> Items;
private:
  int GetID(int idx) { return Items[idx].SynonymID; }
public:
  NeotomaSynonym(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

typedef struct
{
  int TaxonID;
  UnicodeString TaxonName;
  int ValidTaxonID;
} NTMLOOKUPSYNONYM;
//---------------------------------------------------------------------------

// for xml lookup files
class NeotomaLookupSynonym : public SJSONTABLE
{
public:
  vector<NTMLOOKUPSYNONYM> Items;
private:
  int GetID(int idx) { return Items[idx].TaxonID; }
public:
  NeotomaLookupSynonym(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaElementTaxaGroupID : public SJSONTABLE
{
public:
  vector<int> Items;
private:
  int GetID(int idx) { return Items[idx]; }
public:
  NeotomaElementTaxaGroupID(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaVariableUnitsTableByDatasetTypeID : public SJSONTABLE
{
public:
  set<UnicodeString> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaVariableUnitsTableByDatasetTypeID(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaVariableUnitsID : public SJSONTABLE
{
public:
  vector<int> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaVariableUnitsID(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaVariableContextsTableByDatasetTypeID : public SJSONTABLE
{
public:
  set<UnicodeString> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaVariableContextsTableByDatasetTypeID(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaVariableContextID : public SJSONTABLE
{
public:
  vector<int> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaVariableContextID(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

typedef struct
{
  int RockTypeID;
  UnicodeString RockType;
  int HigherRockTypeID;
  UnicodeString Description;
} ROCKTYPE;
//---------------------------------------------------------------------------

class NeotomaRockTypesBase : public SJSONTABLE
{
public:
  vector<ROCKTYPE> Items;
private:
  int GetID(int idx) { return Items[idx].RockTypeID; }
public:
  NeotomaRockTypesBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaRockTypesTable : public NeotomaRockTypesBase
{
public:
  NeotomaRockTypesTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaRockTypeByName : public NeotomaRockTypesBase
{
public:
  NeotomaRockTypeByName(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaRockTypeByID : public NeotomaRockTypesBase
{
public:
  NeotomaRockTypeByID(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaFaciesTypesBase : public SJSONTABLE
{
public:
  map<int, UnicodeString> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaFaciesTypesBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaFaciesTypesTable : public NeotomaFaciesTypesBase
{
public:
  NeotomaFaciesTypesTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaFaciesTypeByName : public NeotomaFaciesTypesBase
{
public:
  NeotomaFaciesTypeByName(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaDepAgentsBase : public SJSONTABLE
{
public:
  map<int, UnicodeString> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaDepAgentsBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaDepAgentsTable : public NeotomaDepAgentsBase
{
public:
  NeotomaDepAgentsTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaDepAgentByName : public NeotomaDepAgentsBase
{
public:
  NeotomaDepAgentByName(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class REPOSITORY
{
public:
  int RepositoryID;
  UnicodeString Acronym;
  UnicodeString Repository;
  UnicodeString Notes;
  UnicodeString SpecimenNotes;  // obtained with NeotomaDatasetRepositorySpecimenNotes
public:
  REPOSITORY() { RepositoryID = -1; };
};
//---------------------------------------------------------------------------

class NeotomaRepositoryInstitutionBase : public SJSONTABLE
{
public:
  vector<REPOSITORY> Items;
private:
  int GetID(int idx) { return Items[idx].RepositoryID; }
public:
  NeotomaRepositoryInstitutionBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaRepositoryInstitutionsTable : public NeotomaRepositoryInstitutionBase
{
public:
   NeotomaRepositoryInstitutionsTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaDatasetRepository : public NeotomaRepositoryInstitutionBase
{
public:
   NeotomaDatasetRepository(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaRepositoryInstitution : public NeotomaRepositoryInstitutionBase
{
public:
   NeotomaRepositoryInstitution(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaDatasetRepositorySpecimenNotes : public SJSONTABLE
{
public:
  map<int,UnicodeString> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaDatasetRepositorySpecimenNotes(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaGeochronTypesTable : public SJSONTABLE
{
public:
  map<int, UnicodeString> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaGeochronTypesTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaRadiocarbonMethodsTable : public SJSONTABLE
{
public:
  map<int, UnicodeString> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaRadiocarbonMethodsTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaFractionDatedBase : public SJSONTABLE
{
public:
  map<int, UnicodeString> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaFractionDatedBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaFractionDatedTable : public NeotomaFractionDatedBase
{
public:
   NeotomaFractionDatedTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaFractionsDatedByList : public NeotomaFractionDatedBase
{
public:
   NeotomaFractionsDatedByList(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaFractionDatedByName : public NeotomaFractionDatedBase
{
public:
   NeotomaFractionDatedByName(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

typedef struct
{
  int ChronControlTypeID;
  UnicodeString ChronControlType;
  int HigherChronControlTypeID;
} CHRONCONTROLTYPE;
//---------------------------------------------------------------------------

class NeotomaChronControlTypesBase : public SJSONTABLE
{
public:
  vector<CHRONCONTROLTYPE> Items;
private:
  int GetID(int idx) { return Items[idx].ChronControlTypeID; }
public:
  NeotomaChronControlTypesBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaChronControlTypesTable : public NeotomaChronControlTypesBase
{
public:
  NeotomaChronControlTypesTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaChronControlTypeByName : public NeotomaChronControlTypesBase
{
public:
  NeotomaChronControlTypeByName(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaChronControlTypeHighestID : public NeotomaChronControlTypesBase
{
public:
  NeotomaChronControlTypeHighestID(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaEventTypesBase : public SJSONTABLE
{
public:
  map<int, UnicodeString> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaEventTypesBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaEventTypesTable : public NeotomaEventTypesBase
{
public:
  NeotomaEventTypesTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaEventTypeByName : public NeotomaEventTypesBase
{
public:
  NeotomaEventTypeByName(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

typedef struct
{
  int EventID;
  int EventTypeID;
  UnicodeString EventName;
  Variant C14Age;            // needs to be Variant to accommodate nulls
  Variant C14AgeYounger;
  Variant C14AgeOlder;
  Variant CalAge;
  Variant CalAgeYounger;
  Variant CalAgeOlder;
  UnicodeString Notes;
} NTMEVENT;
//---------------------------------------------------------------------------

class NeotomaEventsBase : public SJSONTABLE
{
public:
  vector<NTMEVENT> Items;
private:
  int GetID(int idx) { return Items[idx].EventID; }
public:
  NeotomaEventsBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaEventsTable : public NeotomaEventsBase
{
public:
  NeotomaEventsTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaEventByName : public NeotomaEventsBase
{
public:
  NeotomaEventByName(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

typedef struct
{
  int AgeTypeID;
  UnicodeString AgeType;
  UnicodeString ShortAgeType;
  int Precedence;
} AGETYPE;
//---------------------------------------------------------------------------

/*
class NeotomaAgeTypesTable : public SJSONTABLE
{
public:
  vector<AGETYPE> Items;
private:
  int GetID(int idx) { return Items[idx].AgeTypeID; }
public:
  NeotomaAgeTypesTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------
*/

class NeotomaAgeTypesTable : public SJSONTABLE
{
public:
  vector<AGETYPE> Items;
private:
  int GetID(int idx) { return Items[idx].AgeTypeID; }
public:
  NeotomaAgeTypesTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaRelativeAgeScalesBase : public SJSONTABLE
{
public:
  map<int, UnicodeString> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaRelativeAgeScalesBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaRelativeAgeScalesTable : public NeotomaRelativeAgeScalesBase
{
public:
  NeotomaRelativeAgeScalesTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaRelativeAgeScaleByName : public NeotomaRelativeAgeScalesBase
{
public:
  NeotomaRelativeAgeScaleByName(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

typedef struct
{
  int RelativeAgeID;
  int RelativeAgeUnitID;
  int RelativeAgeScaleID;
  UnicodeString RelativeAge;
  Variant C14AgeYounger;     // needs to be Variant to accommodate nulls
  Variant C14AgeOlder;
  Variant CalAgeYounger;
  Variant CalAgeOlder;
  UnicodeString Notes;
} NTMRELATIVEAGE;
//---------------------------------------------------------------------------

class NeotomaRelativeAgesBase : public SJSONTABLE
{
public:
  vector<NTMRELATIVEAGE> Items;
private:
  int GetID(int idx) { return Items[idx].RelativeAgeID; }
public:
  NeotomaRelativeAgesBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaRelativeAgesTable : public NeotomaRelativeAgesBase
{
public:
  NeotomaRelativeAgesTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaRelativeAgeByName : public NeotomaRelativeAgesBase
{
public:
  NeotomaRelativeAgeByName(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

typedef struct
{
  int CalibrationCurveID;
  UnicodeString CalibrationCurve;
  int PublicationID;
} CALIBRATIONCURVE;
//---------------------------------------------------------------------------

class NeotomaCalibrationCurvesTable : public SJSONTABLE
{
public:
  vector<CALIBRATIONCURVE> Items;
private:
  int GetID(int idx) { return Items[idx].CalibrationCurveID; }
public:
  NeotomaCalibrationCurvesTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

typedef struct
{
  int CalibrationProgramID;
  UnicodeString CalibrationProgram;
  UnicodeString Version;
} CALIBRATIONPROGRAM;
//---------------------------------------------------------------------------

class NeotomaCalibrationProgramsTable : public SJSONTABLE
{
public:
  vector<CALIBRATIONPROGRAM> Items;
private:
  int GetID(int idx) { return Items[idx].CalibrationProgramID; }
public:
  NeotomaCalibrationProgramsTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaTaxaGroupElementTypes : public SJSONTABLE
{
public:
  multimap<UnicodeString,UnicodeString> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaTaxaGroupElementTypes(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

typedef struct
{
  int TaxonID;
  int EcolSetID;
  UnicodeString EcolSetName;
  UnicodeString EcolGroupID;
  UnicodeString EcolGroup;
} ECOLSETGROUP;
//---------------------------------------------------------------------------

class NeotomaEcolSetsGroups : public SJSONTABLE
{
public:
  vector<ECOLSETGROUP> Items;
private:
  int GetID(int idx) { return Items[idx].TaxonID; }
public:
  NeotomaEcolSetsGroups(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaEcolSetTypesTable : public SJSONTABLE
{
public:
  map<int,UnicodeString> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaEcolSetTypesTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

typedef struct
{
  int EcolSetID;
  UnicodeString EcolSetName;
  int Count;
} ECOLSETCOUNT;
//---------------------------------------------------------------------------

class NeotomaEcolSetCounts : public SJSONTABLE
{
public:
  vector<ECOLSETCOUNT> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaEcolSetCounts(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaEcolGroupsByEcolSetID : public SJSONTABLE
{
public:
  map<UnicodeString,UnicodeString> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaEcolGroupsByEcolSetID(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaEcolGroupTypesTable : public SJSONTABLE
{
public:
  map<UnicodeString,UnicodeString> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaEcolGroupTypesTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaSynonymTypesTable : public SJSONTABLE
{
public:
  map<int,UnicodeString> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaSynonymTypesTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaSynonymType : public NeotomaSynonymTypesTable
{
public:
  NeotomaSynonymType(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaCount : public SJSONTABLE
{
public:
  vector<int> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaCount(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaTaxaByNamesCount : public NeotomaCount
{
public:
  NeotomaTaxaByNamesCount(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaTableRecordCount : public NeotomaCount
{
public:
  NeotomaTableRecordCount(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaChildTaxaCount : public NeotomaCount
{
public:
  NeotomaChildTaxaCount(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaTaxonDataRecordsCount : public NeotomaCount
{
public:
  NeotomaTaxonDataRecordsCount(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaVariableDataRecordsCount : public NeotomaCount
{
public:
  NeotomaVariableDataRecordsCount(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaTaxonSpecimenDatesCount : public NeotomaCount
{
public:
  NeotomaTaxonSpecimenDatesCount(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaTaxonSynonymsCount : public NeotomaCount
{
public:
  NeotomaTaxonSynonymsCount(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaTaxonSynonymyCount : public NeotomaCount
{
public:
  NeotomaTaxonSynonymyCount(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaInvalidTaxonSynonymyCount : public NeotomaCount
{
public:
  NeotomaInvalidTaxonSynonymyCount(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaElementDatasetTaxaGroupCount : public NeotomaCount
{
public:
  NeotomaElementDatasetTaxaGroupCount(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaUnitsDatasetTypeCount : public NeotomaCount
{
public:
  NeotomaUnitsDatasetTypeCount(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaContextDatasetTypeCount : public NeotomaCount
{
public:
  NeotomaContextDatasetTypeCount(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaCollUnitHandleCount : public NeotomaCount
{
public:
  NeotomaCollUnitHandleCount(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaNextLowerGeoPolCountByNames : public NeotomaCount
{
public:
  NeotomaNextLowerGeoPolCountByNames(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaSpecimenByIDCount : public NeotomaCount
{
public:
  NeotomaSpecimenByIDCount(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaSampleTaxonCount : public NeotomaCount
{
public:
  NeotomaSampleTaxonCount(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaPublicationTypesTable : public SJSONTABLE
{
public:
  map<int,UnicodeString> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaPublicationTypesTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaTableMinID : public SJSONTABLE
{
public:
  vector<int> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaTableMinID(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaTableMaxID : public SJSONTABLE
{
public:
  vector<int> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaTableMaxID(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaGetMinPubIDByPubIDType : public SJSONTABLE
{
public:
  vector<int> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaGetMinPubIDByPubIDType(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaGetMaxPubIDByPubIDType : public SJSONTABLE
{
public:
  vector<int> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaGetMaxPubIDByPubIDType(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

typedef struct
{
  int VariableElementID;
  UnicodeString ElementType;
  UnicodeString Symmetry;
  UnicodeString Portion;
  UnicodeString Maturity;
} NEOTOMAELEMENT;
//---------------------------------------------------------------------------

class NeotomaGetElementByTaxonID : public SJSONTABLE
{
public:
  vector<NEOTOMAELEMENT> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaGetElementByTaxonID(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

typedef struct
{
  int VariableElementID;
  int ElementTypeID;
  int SymmetryID;
  int PortionID;
  int MaturityID;
} NEOTOMAVARIABLEELEMENTIDS;
//---------------------------------------------------------------------------

class NeotomaGetVariableElementByName : public SJSONTABLE
{
public:
  vector<NEOTOMAVARIABLEELEMENTIDS> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaGetVariableElementByName(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

typedef struct
{
  int SymmetryID;
  int PortionID;
  int MaturityID;
} NEOTOMAELEMENTPARTIDS;
//---------------------------------------------------------------------------

class NeotomaGetElementPartID : public SJSONTABLE
{
public:
  vector<NEOTOMAELEMENTPARTIDS> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaGetElementPartID(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaVariableElementByPartIDs : public SJSONTABLE
{
public:
  vector<int> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaVariableElementByPartIDs(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

typedef struct
{
  int SpecimenDateID;
  int GeochronID;
  int TaxonID;
  int FractionID;     // can be null
  int SampleID;
  int ElementTypeID;  // can be null
  UnicodeString Notes;
} NEOTOMASPECIMENDATE;
//---------------------------------------------------------------------------

class NeotomaSpecimenDatesBase : public SJSONTABLE
{
public:
  vector<NEOTOMASPECIMENDATE> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaSpecimenDatesBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaSpecimenDatesByTaxonID : public NeotomaSpecimenDatesBase
{
public:
  NeotomaSpecimenDatesByTaxonID(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaDatasetIDsByTaxonID : public SJSONTABLE
{
public:
  vector<int> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaDatasetIDsByTaxonID(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaRelativeAgeUnitsByAgeScale : public SJSONTABLE
{
public:
  map<int,UnicodeString> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaRelativeAgeUnitsByAgeScale(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

typedef struct
{
  int TaxonID;
  UnicodeString TaxonName;
  bool Valid;
  int HigherTaxonID;
} NEOTOMATAXONHIERARCHY;
//---------------------------------------------------------------------------

class NeotomaTaxonHierarchy : public SJSONTABLE
{
public:
  vector<NEOTOMATAXONHIERARCHY> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaTaxonHierarchy(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaKeywordsTable : public SJSONTABLE
{
public:
  map<int,UnicodeString> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaKeywordsTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaSampleKeywords : public SJSONTABLE
{
public:
  map<int,UnicodeString> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaSampleKeywords(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

typedef struct
{
  int CollectionUnitID;
  UnicodeString Handle;
  int SiteID;
  int CollTypeID;
  int DepEnvtID;
  UnicodeString CollUnitName;
  Variant CollDate;
  UnicodeString CollDevice;
  Variant GPSLatitude;
  Variant GPSLongitude;
  Variant GPSAltitude;
  Variant GPSError;
  Variant WaterDepth;
  int SubstrateID;
  Variant SlopeAspect;
  Variant SlopeAngle;
  UnicodeString Location;
  UnicodeString Notes;
} NEOTOMACOLLUNIT;
//---------------------------------------------------------------------------

class NeotomaCollUnitBase : public SJSONTABLE
{
public:
  vector<NEOTOMACOLLUNIT> Items;
private:
  int GetID(int idx) { return Items[idx].CollectionUnitID; }
public:
  NeotomaCollUnitBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { };
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaCollUnitByID : public NeotomaCollUnitBase
{
public:
  NeotomaCollUnitByID(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaCollUnitsBySiteID : public NeotomaCollUnitBase
{
public:
  NeotomaCollUnitsBySiteID(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------


typedef struct
{
  int CollectionUnitID;
  UnicodeString Handle;
  UnicodeString CollUnitName;
  UnicodeString CollType;
  Variant CollDate;
} NTMCOLLUNITSUMMARY;
//---------------------------------------------------------------------------

class NeotomaCollUnitSummaryBySiteID : public SJSONTABLE
{
public:
  vector<NTMCOLLUNITSUMMARY> Items;
private:
  int GetID(int idx) { return Items[idx].CollectionUnitID; }
public:
  NeotomaCollUnitSummaryBySiteID(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

typedef struct
{
  int DatasetID;
  int CollectionUnitID;
  int DatasetTypeID;
  UnicodeString DatasetType;
  UnicodeString DatasetName;
  UnicodeString Notes;
} NTMDATASET;
//---------------------------------------------------------------------------

class NeotomaDatasetsBase : public SJSONTABLE
{
public:
  vector<NTMDATASET> Items;
private:
  int GetID(int idx) { return Items[idx].DatasetID; }
public:
  NeotomaDatasetsBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaDatasetsByID : public NeotomaDatasetsBase
{
public:
  NeotomaDatasetsByID(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

typedef struct
{
  int SampleID;
  UnicodeString SampleName;
  Variant SampleDate;
  Variant AnalysisDate;
  UnicodeString LabNumber;
  UnicodeString PreparationMethod;
  UnicodeString SampleNotes;
  int AnalysisUnitID;
  UnicodeString AnalysisUnitName;
  Variant Depth;
  Variant Thickness;
  int FaciesID;
  UnicodeString Facies;
  bool Mixed;
  UnicodeString IGSN;
  UnicodeString AnalUnitNotes;
} NTMSAMPLEANALUNIT;
//---------------------------------------------------------------------------

class NeotomaSampleAnalUnits : public SJSONTABLE
{
public:
  vector<NTMSAMPLEANALUNIT> Items;
private:
  int GetID(int idx) { return Items[idx].SampleID; }
  static bool compare_depths(NTMSAMPLEANALUNIT Samp1, NTMSAMPLEANALUNIT Samp2);
public:
  NeotomaSampleAnalUnits(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
  void SortSampleDepths(void);
};
//---------------------------------------------------------------------------

class NeotomaDatasetSampleAnalysts : public SJSONTABLE
{
public:
  multimap<int,int> Items;  // SampleID, ContactID
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaDatasetSampleAnalysts(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaDatasetSampleKeywords : public SJSONTABLE
{
public:
  multimap<int,UnicodeString> Items;  // SampleID, Keyword
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaDatasetSampleKeywords(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaDatasetSampleDepAgents : public SJSONTABLE
{
public:
  multimap<int,UnicodeString> Items;  // SampleID, DepAgent
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaDatasetSampleDepAgents(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

typedef struct
{
  int ChronologyID;
  UnicodeString ChronologyName;
  UnicodeString ShortAgeType;
} NTMDATASETCHRON;
//---------------------------------------------------------------------------

class NeotomaDatasetChrons : public SJSONTABLE
{
public:
  vector<NTMDATASETCHRON> Items;
private:
  int GetID(int idx) { return Items[idx].ChronologyID; }
public:
  NeotomaDatasetChrons(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

typedef struct
{
  Variant Age;
  Variant AgeYounger;
  Variant AgeOlder;
} NTMSAMPLEAGE;
//---------------------------------------------------------------------------

class NeotomaSampleAgesByChronID : public SJSONTABLE
{
public:
  map<int,NTMSAMPLEAGE> Items;  // SampleID, NTMSAMPLEAGE
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaSampleAgesByChronID(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaSampleAge : public SJSONTABLE
{
public:
  map<int,NTMSAMPLEAGE> Items;  // SampleAgeID, NTMSAMPLEAGE
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaSampleAge(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

typedef struct
{
  int VariableID;
  UnicodeString TaxonCode;
  UnicodeString TaxonName;
  UnicodeString Author;
  UnicodeString VariableElement;
  UnicodeString VariableUnits;
  UnicodeString VariableContext;
} NTMDATASETVARIABLE;
//---------------------------------------------------------------------------

class NeotomaDatasetVariables : public SJSONTABLE
{
public:
  vector<NTMDATASETVARIABLE> Items;
private:
  int GetID(int idx) { return Items[idx].VariableID; }
public:
  NeotomaDatasetVariables(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

typedef struct
{
  int DataID;
  int SampleID;
  int VariableID;
  double Value;
  int TaphonomicTypeID;
} NTMDATASETDATA;
//---------------------------------------------------------------------------

class NeotomaDatasetData : public SJSONTABLE
{
public:
  vector<NTMDATASETDATA> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaDatasetData(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

typedef struct
{
  UnicodeString TaphonomicType;
  UnicodeString TaphonomicSystem;
} NTMTAPHTYPE;
//---------------------------------------------------------------------------

class NeotomaTaphonomicTypesByIDList : public SJSONTABLE
{
public:
  map<int,NTMTAPHTYPE> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaTaphonomicTypesByIDList(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

typedef struct
{
  int VariableID;
  UnicodeString TaxaGroupID;
  UnicodeString EcolSetName;
  UnicodeString EcolGroupID;
} NTMVARECOLGROUP;
//---------------------------------------------------------------------------

class NeotomaEcolGroupsByVariableIDList : public SJSONTABLE
{
public:
  vector<NTMVARECOLGROUP> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaEcolGroupsByVariableIDList(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

typedef struct
{
  int GeochronID;
  int SampleID;
  int GeochronTypeID;
  UnicodeString GeochronType;
  int AgeTypeID;
  UnicodeString AgeType;
  Variant Depth;
  Variant Thickness;
  int AnalysisUnitID;
  UnicodeString AnalysisUnitName;
  Variant Age;
  Variant ErrorOlder;
  Variant ErrorYounger;
  bool Infinite;
  UnicodeString LabNumber;
  UnicodeString MaterialDated;
  UnicodeString Notes;
} NTMGEOCHRON;
//---------------------------------------------------------------------------

class NeotomaGeochronByDatasetID : public SJSONTABLE
{
public:
  vector<NTMGEOCHRON> Items;
private:
  int GetID(int idx) { return Items[idx].GeochronID; }
public:
  NeotomaGeochronByDatasetID(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaGetGeochronByGeochronID : public SJSONTABLE
{
public:
  vector<NTMGEOCHRON> Items;
private:
  int GetID(int idx) { return Items[idx].GeochronID; }
public:
  NeotomaGetGeochronByGeochronID(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

typedef struct
{
  UnicodeString RadiocarbonMethod;
  Variant MassCmg;
  Variant PercentC;
  Variant PercentN;
  Variant CNRatio;
  Variant Delta13C;
  Variant Delta15N;
  Variant PercentCollagen;
  Variant Reservoir;
} NTMRADIOCARBON;
//---------------------------------------------------------------------------

class NeotomaRadiocarbonByGeochronID : public SJSONTABLE
{
public:
  map<int,NTMRADIOCARBON> Items;  // GeochronID, NTMRADIOCARBON
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaRadiocarbonByGeochronID(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaPublicationsByGeochronID : public SJSONTABLE
{
public:
  vector<pair<int,int> > Items;   // GeochronID, PublicationID
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaPublicationsByGeochronID(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

typedef struct
{
  int ChronologyID;
  UnicodeString AgeType;
  UnicodeString ChronologyName;
  bool IsDefault;
  UnicodeString AgeModel;
  Variant AgeBoundOlder;
  Variant AgeBoundYounger;
  int ContactID;
  Variant DatePrepared;
  UnicodeString Notes;
} NTMCHRONOLOGY;
//---------------------------------------------------------------------------

class NeotomaChronologiesByCollUnitID : public SJSONTABLE
{
public:
  vector<NTMCHRONOLOGY> Items;
private:
  int GetID(int idx) { return Items[idx].ChronologyID; }
public:
  NeotomaChronologiesByCollUnitID(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

typedef struct
{
  int ChronControlID;
  int ChronControlTypeID;
  UnicodeString ChronControlType;
  Variant Depth;
  Variant Thickness;
  int AnalysisUnitID;
  UnicodeString AnalysisUnitName;
  Variant AgeTypeID;
  Variant Age;
  Variant AgeLimitYounger;
  Variant AgeLimitOlder;
  UnicodeString Notes;
  UnicodeString CalibrationCurve;
  UnicodeString CalibrationProgram;
  UnicodeString Version;
} NTMCHRONCONTROL;
//---------------------------------------------------------------------------

class NeotomaChronoControlsBase : public SJSONTABLE
{
public:
  vector<NTMCHRONCONTROL> Items;
private:
  int GetID(int idx) { return Items[idx].ChronControlID; }
public:
  NeotomaChronoControlsBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaChronoControlsByChronologyID : public NeotomaChronoControlsBase
{
public:
  NeotomaChronoControlsByChronologyID(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaChronoControlsByChronControlID : public NeotomaChronoControlsBase
{
public:
  NeotomaChronoControlsByChronControlID(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaGeoChronControlsByChronologyID : public SJSONTABLE
{
public:
  multimap<int,int> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaGeoChronControlsByChronologyID(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaRelativeAgesByChronologyID : public SJSONTABLE
{
public:
  map<int,UnicodeString> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaRelativeAgesByChronologyID(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

typedef struct
{
  int AliasContactID;
  UnicodeString AliasContactName;
  int CurrentContactID;
  UnicodeString CurrentContactName;
} NTMALIASNAME;
//---------------------------------------------------------------------------

// GetAliasContactNames
class NeotomaAliasContactNames : public SJSONTABLE
{
public:
  vector<NTMALIASNAME> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaAliasContactNames(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaEventChronControlTypeID : public SJSONTABLE
{
public:
  vector<pair<int,int> > Items;   // EventID, ChronControlTypeID
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaEventChronControlTypeID(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaEventsByChronologyID : public SJSONTABLE
{
public:
  map<int,UnicodeString> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaEventsByChronologyID(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaAllDatasetContacts : public SJSONTABLE
{
public:
  vector<UnicodeString> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaAllDatasetContacts(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaAllDatasetPIs : public NeotomaAllDatasetContacts
{
public:
  NeotomaAllDatasetPIs(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaAllDatasetAuthors : public NeotomaAllDatasetContacts
{
public:
  NeotomaAllDatasetAuthors(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaRelativeAgeChronControlType : public SJSONTABLE
{
public:
  vector<pair<int,UnicodeString> > Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaRelativeAgeChronControlType(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

typedef struct
{
  int SynonymyID;
  UnicodeString ValidName;
  UnicodeString RefName;
  bool FromContributor;
  Variant PublicationID;
  UnicodeString Notes;
} DATASETSYNONYM;
//---------------------------------------------------------------------------

class NeotomaDatasetSynonyms : public SJSONTABLE
{
public:
  vector<DATASETSYNONYM> Items;
private:
  int GetID(int idx) { return Items[idx].SynonymyID; }
public:
  NeotomaDatasetSynonyms(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

typedef struct
{
  int SynonymyID;
  UnicodeString RefTaxonName;
  bool FromContributor;
  Variant PublicationID;
  UnicodeString Notes;
} DATASETVARSYNONYM;
//---------------------------------------------------------------------------

class NeotomaDatasetVariableSynonyms : public SJSONTABLE
{
public:
  vector<DATASETVARSYNONYM> Items;
private:
  int GetID(int idx) { return Items[idx].SynonymyID; }
public:
  NeotomaDatasetVariableSynonyms(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaVariableTaxonID : public SJSONTABLE
{
public:
  vector<int> Items;
private:
  int GetID(int idx) { return Items[idx]; }
public:
  NeotomaVariableTaxonID(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

typedef struct
{
  int TaxonID;
  UnicodeString TaxonName;
  UnicodeString Notes;
} DATASETTAXONNOTES;
//---------------------------------------------------------------------------

class NeotomaDatasetTaxonNotesBase : public SJSONTABLE
{
public:
  vector<DATASETTAXONNOTES> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaDatasetTaxonNotesBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaDatasetTaxonNotes : public NeotomaDatasetTaxonNotesBase
{
public:
  NeotomaDatasetTaxonNotes(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

// GetDatasetTaxonNotesByTaxonID
class NeotomaDatasetTaxonNotesByTaxonID : public NeotomaDatasetTaxonNotesBase
{
public:
  NeotomaDatasetTaxonNotesByTaxonID(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaDatasetDatabase : public SJSONTABLE
{
public:
  map<int,UnicodeString> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaDatasetDatabase(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

typedef struct
{
  UnicodeString TaxonName;
  UnicodeString VariableElement;
  UnicodeString VariableUnits;
  UnicodeString VariableContext;
} VARIABLETEXT;
//---------------------------------------------------------------------------

class NeotomaVariableTextByID : public SJSONTABLE
{
public:
  vector<VARIABLETEXT> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaVariableTextByID(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

typedef struct
{
  int LithologyID;
  double DepthTop;
  double DepthBottom;
  UnicodeString LowerBoundary;
  UnicodeString Description;
} NEOTOMALITH;
//---------------------------------------------------------------------------

class NeotomaLithologyByCollUnitID : public SJSONTABLE
{
public:
  vector<NEOTOMALITH> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaLithologyByCollUnitID(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaGetIsoMaterialAnalyzedAndSubstrate : public SJSONTABLE
{
public:
  multimap<UnicodeString,UnicodeString> Items;    // IsoMaterialAnalyzed, IsoSubstrate
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaGetIsoMaterialAnalyzedAndSubstrate(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaGetIsoMaterialAnalyzedTypes : public SJSONTABLE
{
public:
  map<int,UnicodeString> Items;    // IsoMatAnalID, IsoMaterialAnalyzed
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaGetIsoMaterialAnalyzedTypes(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaGetIsoSubstrates : public SJSONTABLE
{
public:
  multimap<int, pair<int,UnicodeString> > Items;    // IsoMatAnalID, <IsoSubstrateID, IsoSubstrate>
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaGetIsoSubstrates(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

typedef struct
{
  int IsoPretreatmentTypeID;
  UnicodeString IsoPretreatmentType;
  UnicodeString IsoPretreatmentQualifier;
} NEOTOMAPRETREATMENT;
//---------------------------------------------------------------------------

class NeotomaGetIsoPretreatmentTypes : public SJSONTABLE
{
public:
  vector<NEOTOMAPRETREATMENT> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaGetIsoPretreatmentTypes(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaSampleOriginTypes : public SJSONTABLE
{
public:
  map<int,UnicodeString> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaSampleOriginTypes(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaGetIsoBioMarkers : public SJSONTABLE
{
public:
  multimap<UnicodeString,UnicodeString> Items;    // IsoBioMarkerType, IsoBioMarkerBandType
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaGetIsoBioMarkers(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaGetIDMapBase : public SJSONTABLE
{
public:
  map<int,UnicodeString> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaGetIDMapBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaIsoInstrumentationTypes : public NeotomaGetIDMapBase
{
public:
  NeotomaIsoInstrumentationTypes(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaIsoSampleIntroSystemTypes : public NeotomaGetIDMapBase
{
public:
  NeotomaIsoSampleIntroSystemTypes(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

typedef struct
{
  int IsoStandardTypeID;
  UnicodeString IsoStandardType;
  UnicodeString IsoStandardMaterial;
} NEOTOMAISOSTANDARD;
//---------------------------------------------------------------------------

class NeotomaIsoStandardTypes : public SJSONTABLE
{
public:
  vector<NEOTOMAISOSTANDARD> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaIsoStandardTypes(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaGetIsoVariableScaleTypes : public SJSONTABLE
{
public:
  multimap<UnicodeString,UnicodeString> Items;    // IsoType, IsoScaleAcronym
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaGetIsoVariableScaleTypes(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaGetIsoVariableScaleIDs : public SJSONTABLE
{
public:
  multimap<UnicodeString,pair<int,UnicodeString> > Items;    // IsoType, IsoScaleTypeID, IsoScaleAcronym
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaGetIsoVariableScaleIDs(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

typedef struct
{
  int SpecimenID;
  UnicodeString AnalysisUnit;
  Variant Depth;
  Variant Thickness;
  UnicodeString Taxon;
  UnicodeString Element;
  UnicodeString Variable;
  UnicodeString Units;
  Variant Value;
  Variant SD;
  UnicodeString MaterialAnalyzed;
  UnicodeString Substrate;
  UnicodeString Pretreatments;
  UnicodeString Analyst;
  UnicodeString Lab;
  UnicodeString LabNumber;
  Variant Mass_mg;
  Variant WeightPercent;
  Variant AtomicPercent;
  Variant Reps;
} NTMISODATASET;
//---------------------------------------------------------------------------

class NeotomaSpecimenIsotopeDataset : public SJSONTABLE
{
public:
  vector<NTMISODATASET> Items;
private:
  int GetID(int idx) { return Items[idx].SpecimenID; }
public:
  NeotomaSpecimenIsotopeDataset(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaSpecimenSexBase : public SJSONTABLE
{
public:
  map<int, UnicodeString> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaSpecimenSexBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaSpecimenSexTypes : public NeotomaSpecimenSexBase
{
public:
  NeotomaSpecimenSexTypes(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaSpecimenSexByName : public NeotomaSpecimenSexBase
{
public:
  NeotomaSpecimenSexByName(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaSpecimenDomStatBase : public SJSONTABLE
{
public:
  map<int, UnicodeString> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaSpecimenDomStatBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaSpecimenDomStatTypes : public NeotomaSpecimenDomStatBase
{
public:
  NeotomaSpecimenDomStatTypes(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaSpecimenDomStatByName : public NeotomaSpecimenDomStatBase
{
public:
  NeotomaSpecimenDomStatByName(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaGetDatasetSampleIDs : public SJSONTABLE
{
public:
  vector<int> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaGetDatasetSampleIDs(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

typedef struct
{
  int SampleID;
  int CollectionUnitID;
  int AnalysisUnitID;
  UnicodeString AnalysisUnitName;
  Variant Depth;
  Variant Thickness;
} GEOCHRONANALUNIT;
//---------------------------------------------------------------------------

class NeotomaGetGeochronAnalysisUnitBase : public SJSONTABLE
{
public:
  vector<GEOCHRONANALUNIT> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaGetGeochronAnalysisUnitBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaGetGeochronAnalysisUnit : public NeotomaGetGeochronAnalysisUnitBase
{
public:
  NeotomaGetGeochronAnalysisUnit(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaGetGeochronAnalysisUnitByDatasetID : public NeotomaGetGeochronAnalysisUnitBase
{
public:
  NeotomaGetGeochronAnalysisUnitByDatasetID(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaGetAnalysisUnit : public SJSONTABLE
{
public:
  vector<int> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaGetAnalysisUnit(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

typedef struct
{
  int AnalysisUnitID;
  int CollectionUnitID;
  Variant Depth;
  Variant Thickness;
  UnicodeString AnalysisUnitName;
} NTMANALYSISUNIT;
//---------------------------------------------------------------------------

class NeotomaGetAnalUnitBase : public SJSONTABLE
{
public:
  vector<NTMANALYSISUNIT> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaGetAnalUnitBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaGetAnalUnitsByCollUnitID : public NeotomaGetAnalUnitBase
{
public:
  NeotomaGetAnalUnitsByCollUnitID(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaGetAnalUnitByID : public SJSONTABLE
{
public:
  vector<NTMANALYSISUNIT> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaGetAnalUnitByID(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

/*
class NeotomaGetAnalUnitByID : public NeotomaGetAnalUnitBase
{
public:
  NeotomaGetAnalUnitByID(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------
*/

class NeotomaGetCountBase : public SJSONTABLE
{
public:
  vector<int> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaGetCountBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaGetAnalysisUnitSampleCount : public NeotomaGetCountBase
{
public:
  NeotomaGetAnalysisUnitSampleCount(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaGetGeochronControlCount : public NeotomaGetCountBase
{
public:
  NeotomaGetGeochronControlCount(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaGetGeochronIDCount : public NeotomaGetCountBase
{
public:
  NeotomaGetGeochronIDCount(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaGetIDBase : public SJSONTABLE
{
public:
  vector<int> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaGetIDBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaGetAgeTypeID : public NeotomaGetIDBase
{
public:
  NeotomaGetAgeTypeID(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaGetGeochronTypeID : public NeotomaGetIDBase
{
public:
  NeotomaGetGeochronTypeID(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaGetRadiocarbonMethodID : public NeotomaGetIDBase
{
public:
  NeotomaGetRadiocarbonMethodID(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaGetDatasetPublicationIDs : public NeotomaGetIDBase
{
public:
  NeotomaGetDatasetPublicationIDs(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaVariableByComponentNames : public NeotomaGetIDBase
{
public:
  NeotomaVariableByComponentNames(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaTaphonomicTypeID : public NeotomaGetIDBase
{
public:
  NeotomaTaphonomicTypeID(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

typedef struct
{
  int SpecimenID;
  UnicodeString ElementType;
  UnicodeString Symmetry;
  UnicodeString Portion;
  UnicodeString Maturity;
  UnicodeString Sex;
  UnicodeString DomesticStatus;
  UnicodeString Preservative;
  double NISP;
  UnicodeString Repository;
  UnicodeString SpecimenNr;
  UnicodeString FieldNr;
  UnicodeString ArctosNr;
  UnicodeString Notes;
  UnicodeString TaxonName;
  UnicodeString TaxaGroup;
} DATASETSPECIMEN;
//---------------------------------------------------------------------------

class NeotomaDatasetSpecimens : public SJSONTABLE
{
public:
  multimap<int, DATASETSPECIMEN> Items;   // DataID, DATASETSPECIMEN
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaDatasetSpecimens(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaDatasetSpecimenGenBankNrs : public SJSONTABLE
{
public:
  multimap<int, UnicodeString> Items;   // DataID, DATASETSPECIMEN
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaDatasetSpecimenGenBankNrs(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaDatasetSpecimenTaphonomy : public SJSONTABLE
{
public:
  multimap<int, pair<UnicodeString,UnicodeString> > Items;   // SpecimenID, <TaphonomicSystem, TaphonomicType>
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaDatasetSpecimenTaphonomy(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaGetDatasetIDByCollUnitAndType : public SJSONTABLE
{
public:
  vector<int> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaGetDatasetIDByCollUnitAndType(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaGetChronoControlsByAnalUnitID : public SJSONTABLE
{
public:
  vector<int> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaGetChronoControlsByAnalUnitID(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaGetPollenSporeHigherTaxa : public SJSONTABLE
{
public:
  // vector<pair<int,int> > Items;
  map<int,int> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaGetPollenSporeHigherTaxa(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaGetDatasetPublicationStatus : public SJSONTABLE
{
public:
  vector<bool> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaGetDatasetPublicationStatus(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//--------------------------------------------------------------------------

typedef struct
{
  int AggregateDatasetID;
  UnicodeString AggregateDatasetName;
  int AggregateOrderTypeID;
  UnicodeString Notes;
} AGGREGATEDATASET;
//---------------------------------------------------------------------------

class NeotomaAggregateDatasetBase : public SJSONTABLE
{
public:
  vector<AGGREGATEDATASET> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaAggregateDatasetBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaAggregateDatasetByName : public NeotomaAggregateDatasetBase
{
public:
  NeotomaAggregateDatasetByName(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaAggregateOrderTypes : public SJSONTABLE
{
public:
  map<int,UnicodeString> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaAggregateOrderTypes(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

typedef struct
{
  int AggregateChronID;
  int AggregateDatasetID;
  int AgeTypeID;
  bool IsDefault;
  UnicodeString ChronologyName;
  int AgeBoundYounger;
  int AgeBoundOlder;
  UnicodeString Notes;
} AGGREGATECHRON;
//---------------------------------------------------------------------------

class NeotomaAggregateChronBase : public SJSONTABLE
{
public:
  vector<AGGREGATECHRON> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaAggregateChronBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaAggregateChronByDatasetID : public NeotomaAggregateChronBase
{
public:
  NeotomaAggregateChronByDatasetID(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaElementTypesForTaxonTaxaGroup : public SJSONTABLE
{
public:
  map<int,UnicodeString> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaElementTypesForTaxonTaxaGroup(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaSampleIDBase : public SJSONTABLE
{
public:
  vector<int> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaSampleIDBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaSpecimenSampleID : public NeotomaSampleIDBase
{
public:
  NeotomaSpecimenSampleID(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaSampleIDForDatasetIDFromGeochronAnalUnit : public NeotomaSampleIDBase
{
public:
  NeotomaSampleIDForDatasetIDFromGeochronAnalUnit(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaSampleIDForDatasetTypeIDFromGeochronAnalUnit : public NeotomaSampleIDBase
{
public:
  NeotomaSampleIDForDatasetTypeIDFromGeochronAnalUnit(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaDatasetIDforDatasetTypeIDforGeochronAnalUnit : public SJSONTABLE
{
public:
  vector<int> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaDatasetIDforDatasetTypeIDforGeochronAnalUnit(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

typedef struct
{
  int SpecimenDateID;
  int SpecimenID;
  int GeochronID;
  int SampleID;
  UnicodeString TaxonName;
  UnicodeString ElementType;
  UnicodeString Fraction;
  UnicodeString Notes;
  double CalAge;
  double CalAgeOlder;
  double CalAgeYounger;
  UnicodeString CalibrationCurve;
  UnicodeString CalibrationProgram;
  UnicodeString Version;
} SPECIMENDATE;
//---------------------------------------------------------------------------

class NeotomaGeochronDatasetSpecimenDates : public SJSONTABLE
{
public:
  vector<SPECIMENDATE> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaGeochronDatasetSpecimenDates(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

typedef struct
{
  int SpecimenID;
  int TaxonID;
  UnicodeString TaxonName;
  int ElementTypeID;
  UnicodeString ElementType;
  int FractionID;
  UnicodeString Fraction;
  int SampleID;
  UnicodeString Notes;
} SPECIMENDATEUPDATE;
//---------------------------------------------------------------------------

class NeotomaSpecimenDateBySpecimenDateID : public SJSONTABLE
{
public:
  vector<SPECIMENDATEUPDATE> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaSpecimenDateBySpecimenDateID(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

typedef struct
{
  int SpecimenDateCalID;
  double CalAge;
  double CalAgeOlder;
  double CalAgeYounger;
  int CalibrationCurveID;
  UnicodeString CalibrationCurve;
  int CalibrationProgramID;
  UnicodeString CalibrationProgram;
  UnicodeString Version;
} SPECIMENCALDATE;
//---------------------------------------------------------------------------

class NeotomaSpecimenDateCalBySpecimenDateID : public SJSONTABLE
{
public:
  vector<SPECIMENCALDATE> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaSpecimenDateCalBySpecimenDateID(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaSpecimenTaxonID : public SJSONTABLE
{
public:
  vector<int> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaSpecimenTaxonID(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

typedef struct
{
  UnicodeString name;
  UnicodeString type;
  bool has_default_value;
} INPUTPARAMS;
//---------------------------------------------------------------------------

class NeotomaFuncInputParams : public SJSONTABLE
{
public:
  map<int,INPUTPARAMS> Items;  // order, name, type
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaFuncInputParams(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

typedef struct
{
  int SiteID;
  UnicodeString SiteName;
  int CollectionUnitID;
  UnicodeString Handle;
  int AnalysisUnitID;
  double Depth;
} SAMPLEPARENT;
//---------------------------------------------------------------------------

class NeotomaSampleParents : public SJSONTABLE
{
public:
  vector<SAMPLEPARENT> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaSampleParents(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

typedef struct
{
  int TaxonID;
  UnicodeString TaxonName;
  UnicodeString Author;
  int level;
  int HigherTaxonID;
} CHILDTAXA;
//---------------------------------------------------------------------------

class NeotomaChildTaxa : public SJSONTABLE
{
public:
  vector<CHILDTAXA> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaChildTaxa(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

typedef struct
{
  int TaxonID;
  UnicodeString TaxonName;
  UnicodeString SiteName;
} CHILDTAXASITES;
//---------------------------------------------------------------------------

class NeotomaChildTaxaSites : public SJSONTABLE
{
public:
  vector<CHILDTAXASITES> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaChildTaxaSites(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

typedef struct
{
  int DatasetID;
  UnicodeString DatasetType;
  int SiteID;
  UnicodeString SiteName;
  UnicodeString GeoPolitical;
  UnicodeString DatabaseName;
  UnicodeString Investigator;
  UnicodeString RecDateCreated;
  UnicodeString Steward;
} NTMRECENTUPLOADS;
//---------------------------------------------------------------------------

class NeotomaGetRecentUploadsBase : public SJSONTABLE
{
public:
  vector<NTMRECENTUPLOADS> Items;
private:
  int GetID(int idx) { return 1; }
public:
  NeotomaGetRecentUploadsBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
  void IndexItems(void) { }
  unsigned int Size(void) { return Items.size(); }
};
//---------------------------------------------------------------------------

class NeotomaGetRecentUploads400 : public NeotomaGetRecentUploadsBase
{
public:
  NeotomaGetRecentUploads400(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
};
//---------------------------------------------------------------------------

class NeotomaGetRecentUploads : public NeotomaGetRecentUploadsBase
{
public:
  NeotomaGetRecentUploads(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
  void AddRecord(vector<Variant>& Record);
};

#endif
