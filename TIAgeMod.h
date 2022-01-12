//---------------------------------------------------------------------------

#ifndef TIAgeModH
#define TIAgeModH
#include "pch.h"

#include "cxGridTableView.hpp"
#include <vector>
#include <list>
#ifndef TICommonH
#include "TICommon.h"
#endif
#ifndef TIGeochrH
#include "TIGeochr.h"
#endif
#ifndef TIContacH
#include "TIContac.h"
#endif
#ifndef TIUtilsH
#include "TIUtils.h"
#endif

//---------------------------------------------------------------------------

typedef void __fastcall (__closure *TcxNotifyEvent)(void * Ptr, TListNotification Action);

class AGEMODEL
{
public:
  int ChronNumber;
  int NeotomaChronologyID;
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
  TList *ChronControls;
public:
  AGEMODEL();
  ~AGEMODEL();
  static int __fastcall ChronControlsDepthAgeCompare(void*, void*);
};
//---------------------------------------------------------------------------

class CHRON
{
public:
	int NeotomaChronControlID;
	int NeotomaAnalUnitID;
	Variant Depth;
	Variant Thickness;
	Variant AgeValue;
	Variant AgeLimitOlder;
	Variant AgeLimitYounger;
	UnicodeString AnalUnit;
	UnicodeString AgeUnits;
	UnicodeString ControlType;
	UnicodeString CalibCurve;
	CALIBRATION Calib;
	vector<int> GeochronIDs;
	UnicodeString Notes;
public:
	CHRON() { NeotomaChronControlID = -1; NeotomaAnalUnitID = -1; }
	CHRON(CHRON* cc) { NeotomaChronControlID = cc->NeotomaChronControlID;
		NeotomaAnalUnitID = cc->NeotomaAnalUnitID; AgeUnits = cc->AgeUnits;
		Depth = cc->Depth; Thickness = cc->Thickness; AgeValue = cc->AgeValue;
		AgeLimitOlder = cc->AgeLimitOlder; AgeLimitYounger = cc->AgeLimitYounger;
		AnalUnit = cc->AnalUnit; ControlType = cc->ControlType; CalibCurve = cc->CalibCurve;
		Calib = cc->Calib; GeochronIDs = cc->GeochronIDs; Notes = cc->Notes; }
	bool operator != (const CHRON& compare);
};
//---------------------------------------------------------------------------

class TAgeModelList : public TList
{
private:
	::TcxNotifyEvent FOnNotify;
	void ReleaseAllAgeModels();
	void ReleaseAgeModel(int AIndex);
	AGEMODEL* GetAgeModel(int AIndex);
	TGeochronList* FGeochronList;       // for making geochron links
protected:
	void __fastcall Notify(void * Ptr, TListNotification Action);
	__property Items;
public:
	TAgeModelList(TGeochronList* gcl) { FGeochronList = gcl; }
	__fastcall ~TAgeModelList() {}
	void __fastcall Clear(void);
	void Add(AGEMODEL* AgeModel);
	void Delete(int AIndex);
	void Insert(int AIndex, AGEMODEL* AgeModel);
	__property AGEMODEL* AgeModels[int Index] = {read = GetAgeModel};
    __property ::TcxNotifyEvent OnNotify = {read=FOnNotify, write=FOnNotify};
	__property TGeochronList* GeochronList = {read = FGeochronList};
};
//---------------------------------------------------------------------------

class TAgeModelDataSource : public TcxCustomDataSource
{
private:
    TAgeModelList* FAgeModels;
protected:
    void * __fastcall InsertRecord(void * ARecordHandle);
    void * __fastcall AppendRecord(void);
    void __fastcall DeleteRecord(void * ARecordHandle);
    int __fastcall GetRecordCount(void);
    Variant __fastcall GetValue(void * ARecordHandle, void * AItemHandle);
    void __fastcall Notify(void * Ptr, TListNotification Action);
    void __fastcall SetValue(void * ARecordHandle, void * AItemHandle, const Variant &AValue);
public:
    __fastcall TAgeModelDataSource(TAgeModelList* AAgeModelList);
    __fastcall ~TAgeModelDataSource() { }
    __property TAgeModelList* AgeModelList = {read = FAgeModels};
};
//---------------------------------------------------------------------------

class TChronDataSource : public TcxCustomDataSource
{
private:
    TAgeModelDataSource* FDataSource; // master
protected:
    void * __fastcall InsertRecord(void * ARecordHandle);
    void * __fastcall AppendRecord(void);
    void __fastcall DeleteRecord(void * ARecordHandle);
    int __fastcall GetRecordCount(void);
    Variant __fastcall GetValue(void * ARecordHandle, void * AItemHandle);
    void __fastcall Notify(void * Ptr, TListNotification Action);
    void __fastcall SetValue(void * ARecordHandle, void * AItemHandle, const Variant &AValue);
public:
    __fastcall TChronDataSource(TAgeModelDataSource* ADataSource)
      { FDataSource = ADataSource; };
    int GetMasterRecordIndex();
    __property TAgeModelDataSource* MasterDataSource = {read = FDataSource};
};
//---------------------------------------------------------------------------

const int IndexOfamChronNo      = 0;
const int IndexOfamName         = 1;
const int IndexOfamAgeUnits     = 2;
const int IndexOfamDefault      = 3;
const int IndexOfamAgeModel     = 4;
const int IndexOfamOlderBound   = 5;
const int IndexOfamYoungerBound = 6;
const int IndexOfamPreparers    = 7;
const int IndexOfamDatePrepared = 8;
const int IndexOfamNotes        = 9;

const int IndexOfchDepth        = 0;
const int IndexOfchThickness    = 1;
const int IndexOfchAnalUnit     = 2;
const int IndexOfchAnalUnitID   = 3;
const int IndexOfchAgeUnits     = 4;
const int IndexOfchAge          = 5;
const int IndexOfchOlderLimit   = 6;
const int IndexOfchYoungerLimit = 7;
const int IndexOfchAgeBasis     = 8;
const int IndexOfchCalibCurve   = 9;
const int IndexOfchCalibProgram = 10;
const int IndexOfchGeochron     = 11;
const int IndexOfchNotes        = 12;


//---------------------------------------------------------------------------


#endif
