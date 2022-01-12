//---------------------------------------------------------------------------

#ifndef TIGeochrH
#define TIGeochrH

#include "cxGridTableView.hpp"
#include "pch.h"
#include <vector>
#ifndef TIPubH
#include "TIPub.h"
#endif
#ifndef TIUtilsH
#include "TIUtils.h"
#endif
#ifndef TICommonH
#include "TICommon.h"
#endif
#ifndef TISpreadH
#include "TISpread.h"
#endif

typedef void __fastcall (__closure *TcxNotifyEvent)(void * Ptr, TListNotification Action);
//---------------------------------------------------------------------------

class TGeochronList
{
private:
	int MaxID;
	vector<GEOCHRON> Items;                        // new
	vector<GEOCHRON>::pointer GetDate(int AIndex); // new
	TTilSpreadSheetForm* TSSForm;
public:
	TStringList *publications;
public:
	TGeochronList(TComponent* Owner);
	__fastcall ~TGeochronList();
	void __fastcall Clear(void);
	void __fastcall Add(GEOCHRON& Date);  // new
	void Delete(int AIndex);
	void Insert(int AIndex, GEOCHRON& Date);  // new
	int Count(void) { return Items.size(); }  // new
	__property vector<GEOCHRON>::pointer Date[int Index] = {read = GetDate};  // new
	__property vector<GEOCHRON> Dates = {read = Items};                       // new
	void SortAscending(void);
	static bool __fastcall DateDepthCompare(GEOCHRON& Date1, GEOCHRON& Date2);
	static bool DepthCompare(GEOCHRON& Date1, GEOCHRON& Date2);
};
//---------------------------------------------------------------------------

class TGeochronDataSource : public TcxCustomDataSource
{
private:
	TGeochronList* FGeochronList;
protected:
	void * __fastcall InsertRecord(void * ARecordHandle);
	void * __fastcall AppendRecord(void);
	void __fastcall DeleteRecord(void * ARecordHandle);
	int __fastcall GetRecordCount(void);
	Variant __fastcall GetValue(void * ARecordHandle, void * AItemHandle);
	//void __fastcall Notify(void * Ptr, TListNotification Action);
	void __fastcall SetValue(void * ARecordHandle, void * AItemHandle, const Variant &AValue);
public:
	__fastcall TGeochronDataSource(TGeochronList* AGeochronList);
	__fastcall ~TGeochronDataSource() { }
	__property TGeochronList* GeochronList = {read = FGeochronList};
};
//---------------------------------------------------------------------------

class TTaxonDatedDataSource : public TcxCustomDataSource
{
private:
	TGeochronDataSource* FDataSource; // master
	int TaxonDatedID;
protected:
	void * __fastcall InsertRecord(void * ARecordHandle);
	void * __fastcall AppendRecord(void);
    void __fastcall DeleteRecord(void * ARecordHandle);
    int __fastcall GetRecordCount(void);
    Variant __fastcall GetValue(void * ARecordHandle, void * AItemHandle);
	void __fastcall SetValue(void * ARecordHandle, void * AItemHandle, const Variant &AValue);
public:
	__fastcall TTaxonDatedDataSource(TGeochronDataSource* ADataSource)
		{ FDataSource = ADataSource; TaxonDatedID = 0; };
    int GetMasterRecordIndex();
	__property TGeochronDataSource* MasterDataSource = {read = FDataSource};
	int NextTaxonDatedID(void) { return ++TaxonDatedID; }
	void SetTaxonDatedID(int id) { if (id>TaxonDatedID) TaxonDatedID=id; };
	map<UnicodeString,SPECIMEN*> Specimens;  // UserSpecID, Specimen pointer
};
//---------------------------------------------------------------------------

const int IndexOfgeMethod        = 0;
const int IndexOfgeAgeUnits      = 1;
const int IndexOfgeDepth         = 2;
const int IndexOfgeThickness     = 3;
const int IndexOfgeAnalUnit      = 4;
const int IndexOfgeAnalUnitID    = 5;
const int IndexOfgeLabNumber     = 6;
const int IndexOfgeAge           = 7;
const int IndexOfgeErrorOlder    = 8;
const int IndexOfgeErrorYounger  = 9;
const int IndexOfgeSigma         = 10;
const int IndexOfgeSD            = 11;
const int IndexOfgeInfinite      = 12;
const int IndexOfgeParams        = 13;
const int IndexOfgeMaterialDated = 14;
const int IndexOfgePublication   = 15;
const int IndexOfgeNotes         = 16;

//const int IndexOftxID             = 0;
const int IndexOftxUserSpecimenID = 0;
const int IndexOftxTaxon          = 1;
const int IndexOftxElement        = 2;
const int IndexOftxFraction       = 3;
const int IndexOftxCalAgeMedian   = 4;
const int IndexOftxCalAgeOlder    = 5;
const int IndexOftxCalAgeYounger  = 6;
const int IndexOftxCalCurve       = 7;
const int IndexOftxCalProgram     = 8;
const int IndexOftxNotes          = 9;
//---------------------------------------------------------------------------

#endif
