//---------------------------------------------------------------------------
#ifndef TIUtilsH
#define TIUtilsH
//---------------------------------------------------------------------------
#include <vcl.h>
#include <map>
#include <ComCtrls.hpp>
#include "cxCustomData.hpp"
#include "ipwCore.h"
#include "ipwxmlp.h"

#ifndef TITrainH
#include "TITrain.h"
#endif
#ifndef TGUtilsH
#include "TGUtils.h"
#endif
#ifndef TIContacH
#include "TIContac.h"
#endif
#ifndef TIPubH
#include "TIPub.h"
#endif

//---------------------------------------------------------------------------

UnicodeString __fastcall TranslateEntityRefs(UnicodeString&);
int VariantToInt(const Variant& var, int default_val);
bool VariantToBool(Variant& var, bool default_val);
double VariantToDouble(Variant& var, double default_val);
bool TryVariantToDouble(Variant& var, double& value);
bool GetAuthorContact(vector<AUTHOR>::pointer Author, TContactList* ContactList);
UnicodeString StripTextQuotes(UnicodeString Text);
UnicodeString DateStr(Variant vDate);
UnicodeString DateStr(TDateTime Date);
UnicodeString DateTimeStr(TDateTime Date);
Variant GeochronParam(map<UnicodeString,double>& Params, UnicodeString ParamName);
//---------------------------------------------------------------------------

typedef void __fastcall (__closure *TcxNotifyEvent)(void * Ptr, TListNotification Action);
//---------------------------------------------------------------------------

typedef struct
{
  UnicodeString Program;
  UnicodeString Version;
} CALIBRATION;
//---------------------------------------------------------------------------

typedef struct
{
  CODENAME TaxaGroup;
  vector<CODENAME> EcolGroups;
  set<UnicodeString> Elements;
} TAXAECOLGROUPS;
//---------------------------------------------------------------------------

bool TaxaGroupNameComp (TAXAECOLGROUPS& te1, TAXAECOLGROUPS& te2)
	{ return (CompareText(te1.TaxaGroup.Name ,te2.TaxaGroup.Name) < 0);  }
//---------------------------------------------------------------------------

class PARSEXMLSAX
{
public:
  UnicodeString CurrentElementValue;
  int ParentGroup;
  int CurrentGroup;
  int CurrentElement;
public:
  UnicodeString GetElement(UnicodeString&);
  void __fastcall SetElement(UnicodeString&, int);
  void __fastcall SetElement(UnicodeString&, int, int);
};
//---------------------------------------------------------------------------

class TTaxaEcolGroups
{
private:
	vector<TAXAECOLGROUPS> Items;
	vector<TAXAECOLGROUPS>::pointer GetTaxaEcolGroup(int AIndex);
public:
	TTaxaEcolGroups() {}
	TTaxaEcolGroups(vector<TAXAECOLGROUPS>* TaxaEcolGroups);
	__fastcall ~TTaxaEcolGroups() {}
	void __fastcall Clear(void);
	void __fastcall Add(TAXAECOLGROUPS& TaxaEcolGroup);
	void Delete(int AIndex);
	void Insert(int AIndex, TAXAECOLGROUPS& TaxaEcolGroup);
	int Count(void) { return Items.size(); }
	__property vector<TAXAECOLGROUPS>::pointer TaxaEcolGroup[int Index] = {read = GetTaxaEcolGroup};
	__property vector<TAXAECOLGROUPS> TaxaEcolGroups = {read = Items};
};
//---------------------------------------------------------------------------

class TTaxaGroupDataSource : public TcxCustomDataSource
{
private:
	TTaxaEcolGroups* FTaxaEcolGroups;
protected:
	void * __fastcall InsertRecord(void * ARecordHandle);
	void * __fastcall AppendRecord(void);
	void __fastcall DeleteRecord(void * ARecordHandle);
	int __fastcall GetRecordCount(void);
	Variant __fastcall GetValue(void * ARecordHandle, void * AItemHandle);
	void __fastcall SetValue(void * ARecordHandle, void * AItemHandle, const Variant &AValue);
public:
	__fastcall TTaxaGroupDataSource(TTaxaEcolGroups* ATaxaEcolGroups);
	__fastcall ~TTaxaGroupDataSource() { }
	__property TTaxaEcolGroups* TaxaEcolGroups = {read = FTaxaEcolGroups};
};
//---------------------------------------------------------------------------

class TEcolGroupDataSource : public TcxCustomDataSource
{
private:
	TTaxaGroupDataSource* FDataSource; // master
protected:
    void * __fastcall InsertRecord(void * ARecordHandle);
    void * __fastcall AppendRecord(void);
    void __fastcall DeleteRecord(void * ARecordHandle);
    int __fastcall GetRecordCount(void);
    Variant __fastcall GetValue(void * ARecordHandle, void * AItemHandle);
	void __fastcall SetValue(void * ARecordHandle, void * AItemHandle, const Variant &AValue);
public:
    __fastcall TEcolGroupDataSource(TTaxaGroupDataSource* ADataSource) { FDataSource = ADataSource;};
    int GetMasterRecordIndex();
	__property TTaxaGroupDataSource* MasterDataSource = {read = FDataSource};
};
//---------------------------------------------------------------------------

typedef struct
{
  UnicodeString Name;
  vector<UnicodeString> Units;
} ELEMENT;
//---------------------------------------------------------------------------

class TAXON
{
public:
  int ID;
  int HigherID;
  UnicodeString Code;
  UnicodeString Name;
  UnicodeString Author;
  UnicodeString TaxaGroup;
  UnicodeString EcolGroup;
  vector<ELEMENT> Elements;
public:
  TAXON() { ID = -1; HigherID = -1; }
  TAXON(TAXON*);
  void Clear(void) { ID = -1; HigherID = -1; Code = L""; Name = L"";
	Author = L""; TaxaGroup = L""; EcolGroup = L""; Elements.clear(); }
};
//---------------------------------------------------------------------------

class TTaxaVector
{
private:
   vector<TAXON> Taxa;
   multimap<UnicodeString, unsigned int> IdxName;
   map<int, unsigned int> IdxID;     // ID, index to Taxa
   vector<unsigned int> IdxSorted;   // sorted order, actual order
public:
   TAXON& operator[] (const int idx) { return Taxa[IdxSorted[idx]]; }
   void operator = (const TTaxaVector& copy);
   void push_back(const TAXON Taxon) { Taxa.push_back(Taxon); }
   unsigned int size(void) { return Taxa.size(); }
   void Index(void);
   unsigned int FindName(UnicodeString Name, vector<TAXON>& TaxaFound);
   bool FindID(int ID, vector<TAXON>::pointer* TaxonPtr);
   TAXON& at(const unsigned int idx) { return Taxa[IdxSorted[idx]]; }
   TAXON& at(const int idx) { return Taxa[IdxSorted[(unsigned int)idx]]; }
   void clear(void) { Taxa.clear(); IdxName.clear(); IdxID.clear(); IdxSorted.clear(); }
   __property vector<TAXON> TaxaVector = {read = Taxa};
};
//---------------------------------------------------------------------------

class TTaxaList : public TList
{
private:
	::TcxNotifyEvent FOnNotify;
	void ReleaseAllTaxa();
	void ReleaseTaxon(int AIndex);
	TAXON* GetTaxon(int AIndex);
protected:
	void __fastcall Notify(void * Ptr, TListNotification Action);
	__property Items;
public:
	TTaxaList() {}
	TTaxaList(TTaxaList*);
	__fastcall ~TTaxaList() {}
	void __fastcall Clear(void);
	void __fastcall Add(TAXON* Taxon);
	void Delete(int AIndex);
	void Insert(int AIndex, TAXON* Taxon);
	__property TAXON* Taxa[int Index] = {read = GetTaxon};
	__property ::TcxNotifyEvent OnNotify = {read=FOnNotify, write=FOnNotify};
	bool FindID(int id, int& index);
};
//---------------------------------------------------------------------------

class TTaxaDataSource : public TcxCustomDataSource
{
private:
    TTaxaList* FTaxa;
protected:
    void * __fastcall InsertRecord(void * ARecordHandle);
    void * __fastcall AppendRecord(void);
    void __fastcall DeleteRecord(void * ARecordHandle);
    int __fastcall GetRecordCount(void);
    Variant __fastcall GetValue(void * ARecordHandle, void * AItemHandle);
    void __fastcall Notify(void * Ptr, TListNotification Action);
    void __fastcall SetValue(void * ARecordHandle, void * AItemHandle, const Variant &AValue);
public:
    __fastcall TTaxaDataSource(TTaxaList* ATaxaList);
    __fastcall ~TTaxaDataSource() { }
	__property TTaxaList* TaxaList = {read = FTaxa};
};
//---------------------------------------------------------------------------

class TElementsDataSource : public TcxCustomDataSource
{
private:
    TTaxaDataSource* FDataSource; // master
protected:
    void * __fastcall InsertRecord(void * ARecordHandle);
    void * __fastcall AppendRecord(void);
    void __fastcall DeleteRecord(void * ARecordHandle);
    int __fastcall GetRecordCount(void);
    Variant __fastcall GetValue(void * ARecordHandle, void * AItemHandle);
    void __fastcall Notify(void * Ptr, TListNotification Action);
    void __fastcall SetValue(void * ARecordHandle, void * AItemHandle, const Variant &AValue);
public:
    __fastcall TElementsDataSource(TTaxaDataSource* ADataSource) { FDataSource = ADataSource;};
    int GetMasterRecordIndex();
    __property TTaxaDataSource* MasterDataSource = {read = FDataSource};
};
//---------------------------------------------------------------------------

class TUnitsDataSource : public TcxCustomDataSource
{
private:
    TTaxaDataSource* FDataSource;    // master
protected:
    void * __fastcall InsertRecord(void * ARecordHandle);
    void * __fastcall AppendRecord(void);
    void __fastcall DeleteRecord(void * ARecordHandle);
    int __fastcall GetRecordCount(void);
    Variant __fastcall GetValue(void * ARecordHandle, void * AItemHandle);
    void __fastcall Notify(void * Ptr, TListNotification Action);
    void __fastcall SetValue(void * ARecordHandle, void * AItemHandle, const Variant &AValue);
public:
    __fastcall TUnitsDataSource(TTaxaDataSource* DataSource) { FDataSource = DataSource; }
    int GetElementsMasterRecordIndex();
    int GetTaxaMasterRecordIndex();
    __property TTaxaDataSource* MasterDataSource = {read = FDataSource};
};
//---------------------------------------------------------------------------

class PARSETAXA
{
private:
  TForm* OwnerForm;
  UnicodeString FileName;
  TipwXMLp *ipwXMLp6;
private:
  bool ParseTaxaList(void);
  static bool __fastcall CompareName1(TAXON Taxon1, TAXON Taxon2);
  static bool __fastcall CompareName2(TAXON& Taxon, UnicodeString Name);
public:
  TTrainForm* TrainForm;
  TTaxaVector TaxaList;
  map<UnicodeString, int> Synonyms;
  vector<TAXAECOLGROUPS> TaxaEcolGroups;
public:
  PARSETAXA(TipwXMLp*, TForm*);
  bool Parse(UnicodeString);
  bool Parse(UnicodeString, TTrainForm*);
  bool FindName(UnicodeString, vector<TAXON>&);
};
//---------------------------------------------------------------------------

class SAVETAXALOOKUP
{
private:
  UnicodeString TaxaFile;
  UnicodeString TaxaTitle;
  vector<TAXAECOLGROUPS>* TaxaEcolGroupsPtr;
  TTaxaVector* TaxaList;
  TComponent* Owner;
  TSaveDialog* SaveDialog1;
public:
  SAVETAXALOOKUP(UnicodeString, UnicodeString, vector<TAXAECOLGROUPS>*, TTaxaVector*, TComponent*);
  ~SAVETAXALOOKUP();
  void Save(void);
};
//---------------------------------------------------------------------------

#endif
