//---------------------------------------------------------------------------

#ifndef TILithH
#define TILithH

#include "cxGridTableView.hpp"
//---------------------------------------------------------------------------

class LITHOLOGYUNIT
{
public:
  int NeotomaLithologyID;
  double DepthTop;
  double DepthBottom;
  UnicodeString UnitDescription;
  UnicodeString LowerBoundary;
public:
  LITHOLOGYUNIT() { NeotomaLithologyID = -1; DepthTop = NaN; DepthBottom = NaN; }
  LITHOLOGYUNIT(double top, double bot, UnicodeString ud, UnicodeString lb)
     { NeotomaLithologyID = -1; DepthTop = top; DepthBottom = bot; UnitDescription = ud;
       LowerBoundary = lb; }
};
//---------------------------------------------------------------------------

typedef void __fastcall (__closure *TcxNotifyEvent)(void * Ptr, TListNotification Action);

class TLithologyUnitList : public TList
{
private:
	::TcxNotifyEvent FOnNotify;
	void ReleaseAllLithologyUnits();
	void ReleaseLithologyUnit(int AIndex);
	LITHOLOGYUNIT* GetLithologyUnit(int AIndex);
protected:
	void __fastcall Notify(void * Ptr, TListNotification Action);
	__property Items;
public:
	TLithologyUnitList() {}
	__fastcall ~TLithologyUnitList() {}
	void __fastcall Clear(void);
	void Add(LITHOLOGYUNIT* LithologyUnit);
	void Delete(int AIndex);
	void Insert(int AIndex, LITHOLOGYUNIT* LithologyUnit);
	__property LITHOLOGYUNIT* LithologyUnits[int Index] = {read = GetLithologyUnit};
    __property ::TcxNotifyEvent OnNotify = {read=FOnNotify, write=FOnNotify};
    void SortAscending(void);
    static int __fastcall LithUnitDepthCompare(void*, void*);
};
//---------------------------------------------------------------------------

class TLithologyUnitDataSource : public TcxCustomDataSource
{
private:
    TLithologyUnitList* FLithologyUnits;
protected:
    void * __fastcall InsertRecord(void * ARecordHandle);
    void * __fastcall AppendRecord(void);
    void __fastcall DeleteRecord(void * ARecordHandle);
    int __fastcall GetRecordCount(void);
    Variant __fastcall GetValue(void * ARecordHandle, void * AItemHandle);
    void __fastcall Notify(void * Ptr, TListNotification Action);
    void __fastcall SetValue(void * ARecordHandle, void * AItemHandle, const Variant &AValue);
public:
    __fastcall TLithologyUnitDataSource(TLithologyUnitList* ALithologyUnitList);
    __fastcall ~TLithologyUnitDataSource() { }
};
//---------------------------------------------------------------------------

const int IndexOfliTop         = 0;
const int IndexOfliBottom      = 1;
const int IndexOfliDescription = 2;
const int IndexOfliLowerBound  = 3;
//---------------------------------------------------------------------------

#endif


