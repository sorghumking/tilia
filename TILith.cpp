//---------------------------------------------------------------------------
#pragma hdrstop

#include "TILith.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

void TLithologyUnitList::ReleaseAllLithologyUnits()
{
  for (int i = 0; i < Count; i++)
    ReleaseLithologyUnit(i);
}
//---------------------------------------------------------------------------

void TLithologyUnitList::ReleaseLithologyUnit(int AIndex)
{
  delete (LITHOLOGYUNIT*)Items[AIndex];
}
//---------------------------------------------------------------------------

LITHOLOGYUNIT* TLithologyUnitList::GetLithologyUnit(int AIndex)
{
  return (LITHOLOGYUNIT*)Items[AIndex];
}
//---------------------------------------------------------------------------

void __fastcall TLithologyUnitList::Notify(void * Ptr, TListNotification Action)
{
  if (FOnNotify != NULL)
    FOnNotify(Ptr, Action);
}
//---------------------------------------------------------------------------

void __fastcall TLithologyUnitList::Clear(void)
{
  ReleaseAllLithologyUnits();
}
//---------------------------------------------------------------------------

void TLithologyUnitList::Add(LITHOLOGYUNIT* LithologyUnit)
{
  TList::Add(LithologyUnit);
}
//---------------------------------------------------------------------------

void TLithologyUnitList::Delete(int AIndex)
{
  ReleaseLithologyUnit(AIndex);
  TList::Delete(AIndex);
}
//---------------------------------------------------------------------------

void TLithologyUnitList::Insert(int AIndex, LITHOLOGYUNIT* LithologyUnit)
{
  TList::Insert(AIndex, LithologyUnit);
}
//---------------------------------------------------------------------------

void TLithologyUnitList::SortAscending(void)
{
   Sort(LithUnitDepthCompare);
}
//---------------------------------------------------------------------------

int __fastcall TLithologyUnitList::LithUnitDepthCompare(void * Item1, void * Item2)
{
   LITHOLOGYUNIT* Unit1 = (LITHOLOGYUNIT*)Item1;
   LITHOLOGYUNIT* Unit2 = (LITHOLOGYUNIT*)Item2;

   if (Unit1->DepthTop < Unit2->DepthTop)
     return -1;
   else if (Unit1->DepthTop > Unit2->DepthTop)
     return 1;
   else
     return 0;
}
//---------------------------------------------------------------------------

__fastcall TLithologyUnitDataSource::TLithologyUnitDataSource(TLithologyUnitList* ALithologyUnitList)
{
  FLithologyUnits = ALithologyUnitList;
  FLithologyUnits->OnNotify = Notify;
}
//---------------------------------------------------------------------------

void __fastcall TLithologyUnitDataSource::DeleteRecord(void * ARecordHandle)
{
  FLithologyUnits->Delete((int)ARecordHandle);
}
//---------------------------------------------------------------------------

int __fastcall TLithologyUnitDataSource::GetRecordCount(void)
{
  return(FLithologyUnits->Count);
}
//---------------------------------------------------------------------------

Variant __fastcall TLithologyUnitDataSource::GetValue(void * ARecordHandle, void * AItemHandle)
{
  // displays value in grid based on stored data
  int AColumnId = GetDefaultItemID((int)AItemHandle);
  LITHOLOGYUNIT* LithologyUnit = FLithologyUnits->LithologyUnits[(int)ARecordHandle];
  Variant Result;
  switch (AColumnId) {
    case IndexOfliTop:
      if (IsNan(LithologyUnit->DepthTop))
		Result.ChangeType(varEmpty);
      else
        Result = LithologyUnit->DepthTop;
      break;
    case IndexOfliBottom:
      if (IsNan(LithologyUnit->DepthBottom))
		Result.ChangeType(varEmpty);
      else
        Result = LithologyUnit->DepthBottom;
      break;
    case IndexOfliDescription:
      Result = LithologyUnit->UnitDescription;
      break;
    case IndexOfliLowerBound:
      Result = LithologyUnit->LowerBoundary;
      break;
  }
  return (Result);
}
//---------------------------------------------------------------------------

void __fastcall TLithologyUnitDataSource::Notify(void * Ptr, TListNotification Action)
{
  DataChanged();
}
//---------------------------------------------------------------------------

void * __fastcall TLithologyUnitDataSource::InsertRecord(void * ARecordHandle)
{
  LITHOLOGYUNIT* LithologyUnit = new LITHOLOGYUNIT;
  FLithologyUnits->Insert((int)ARecordHandle, LithologyUnit);
  TcxDataRecordHandle* Result = (TcxDataRecordHandle*)ARecordHandle;
  return (Result);
}
//---------------------------------------------------------------------------

void * __fastcall TLithologyUnitDataSource::AppendRecord(void)
{
  TcxDataRecordHandle* Result = (TcxDataRecordHandle*)FLithologyUnits->Count;
  LITHOLOGYUNIT* LithologyUnit = new LITHOLOGYUNIT;
  FLithologyUnits->Add(LithologyUnit);
  return (Result);
}
//---------------------------------------------------------------------------

void __fastcall TLithologyUnitDataSource::SetValue(void * ARecordHandle, void * AItemHandle, const Variant &AValue)
{
  // gets values from grid and stores them
  int AColumnId = GetDefaultItemID((int)AItemHandle);
  LITHOLOGYUNIT* LithologyUnit = FLithologyUnits->LithologyUnits[(int)ARecordHandle];
  switch (AColumnId) {
    case IndexOfliTop:
	  if (AValue.IsNull())
		LithologyUnit->DepthTop = NaN;
      else
        LithologyUnit->DepthTop = AValue;
      break;
    case IndexOfliBottom:
	  if (AValue.IsNull())
        LithologyUnit->DepthBottom = NaN;
	  else
        LithologyUnit->DepthBottom = AValue;
      break;
    case IndexOfliDescription:
	  LithologyUnit->UnitDescription = VarToStr(AValue);
      break;
    case IndexOfliLowerBound:
      LithologyUnit->LowerBoundary = VarToStr(AValue);
      break;
  }
}
//---------------------------------------------------------------------------

