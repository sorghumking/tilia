//---------------------------------------------------------------------------
#pragma hdrstop
#include "VarHlpr.hpp"
#include "TIAgeMod.h"
#ifndef TGUtilsH
#include "TGUtils.h"
#endif

//---------------------------------------------------------------------------

#pragma package(smart_init)

AGEMODEL::AGEMODEL()
{
  ChronNumber = 0;
  NeotomaChronologyID = -1;
  Default = false;
  DatePrepared = Unassigned();
  AgeBoundOlder = Unassigned();
  AgeBoundYounger = Unassigned();
  ChronControls = new TList;
}
//---------------------------------------------------------------------------

AGEMODEL::~AGEMODEL()
{
   for (int i=0; i<ChronControls->Count; i++) {
	CHRON *Chron = (CHRON*)ChronControls->Items[i];
	delete Chron;
	ChronControls->Items[i] = 0;
	}
   ChronControls->Clear();
   delete ChronControls;
}
//---------------------------------------------------------------------------

int __fastcall AGEMODEL::ChronControlsDepthAgeCompare(void * Item1, void * Item2)
{
   CHRON* Chron1 = (CHRON*)Item1;
   CHRON* Chron2 = (CHRON*)Item2;

   Variant vdepth1 = Chron1->Depth;
   Variant vdepth2 = Chron2->Depth;
   Variant vage1 = Chron1->AgeValue;
   Variant vage2 = Chron2->AgeValue;
   bool nodepth1 = vdepth1.IsEmpty() || vdepth1.IsNull();
   bool nodepth2 = vdepth2.IsEmpty() || vdepth2.IsNull();

   if (nodepth1 && !nodepth2)
	 return -1;
   else if (nodepth2 && !nodepth1)
	 return 1;
   else if (!nodepth1 && !nodepth2) {
	 double depth1 = vdepth1;
	 double depth2 = vdepth2;
	 if (depth1 < depth2)
	   return -1;
	 else if (depth1 > depth2)
	   return 1;
	 }

   bool noage1 = vage1.IsEmpty() || vage1.IsNull();
   bool noage2 = vage2.IsEmpty() || vage2.IsNull();

   if (noage1 && !noage2)
	 return -1;
   else if (noage2 && !noage1)
	 return 1;
   else if (noage1 && noage2)
	 return 0;
   else {
	 double age1 = vage1;
	 double age2 = vage2;
	 if (age1 < age2)
	   return -1;
	 else if (age1 > age2)
	   return 1;
	 else
	   return 0;
	 }
}
//---------------------------------------------------------------------------

void TAgeModelList::ReleaseAllAgeModels()
{
  for (int i = 0; i < Count; i++)
    ReleaseAgeModel(i);
}
//---------------------------------------------------------------------------

void TAgeModelList::ReleaseAgeModel(int AIndex)
{
  delete (AGEMODEL*)Items[AIndex];
}
//---------------------------------------------------------------------------

AGEMODEL* TAgeModelList::GetAgeModel(int AIndex)
{
  return (AGEMODEL*)Items[AIndex];
}
//---------------------------------------------------------------------------

void __fastcall TAgeModelList::Notify(void * Ptr, TListNotification Action)
{
  if (FOnNotify != NULL)
    FOnNotify(Ptr, Action);
}
//---------------------------------------------------------------------------

void __fastcall TAgeModelList::Clear(void)
{
  ReleaseAllAgeModels();
}
//---------------------------------------------------------------------------

void TAgeModelList::Add(AGEMODEL* AgeModel)
{
  TList::Add(AgeModel);
}
//---------------------------------------------------------------------------

void TAgeModelList::Delete(int AIndex)
{
  ReleaseAgeModel(AIndex);
  TList::Delete(AIndex);
}
//---------------------------------------------------------------------------

void TAgeModelList::Insert(int AIndex, AGEMODEL* AgeModel)
{
  TList::Insert(AIndex, AgeModel);
}
//---------------------------------------------------------------------------

__fastcall TAgeModelDataSource::TAgeModelDataSource(TAgeModelList* AAgeModelList)
{
  FAgeModels = AAgeModelList;
  FAgeModels->OnNotify = Notify;
}
//---------------------------------------------------------------------------

void __fastcall TAgeModelDataSource::DeleteRecord(void * ARecordHandle)
{
  FAgeModels->Delete((int)ARecordHandle);
}
//---------------------------------------------------------------------------

int __fastcall TAgeModelDataSource::GetRecordCount(void)
{
  return(FAgeModels->Count);
}
//---------------------------------------------------------------------------

Variant __fastcall TAgeModelDataSource::GetValue(void * ARecordHandle, void * AItemHandle)
{
  // displays value in grid based on stored data
  int AColumnId = GetDefaultItemID((int)AItemHandle);
  AGEMODEL* AgeModel = FAgeModels->AgeModels[(int)ARecordHandle];
  Variant Result;
  switch (AColumnId) {
    case IndexOfamChronNo:
      Result = AgeModel->ChronNumber;
      break;
    case IndexOfamName:
      Result = AgeModel->ChronologyName;
      break;
    case IndexOfamAgeUnits:
      Result = AgeModel->AgeUnits;
      break;
    case IndexOfamDefault:
      Result = AgeModel->Default;
      break;
    case IndexOfamAgeModel:
      Result = AgeModel->AgeModel;
      break;
    case IndexOfamOlderBound:
	  Result = AgeModel->AgeBoundOlder;
	  break;
	case IndexOfamYoungerBound:
	  Result = AgeModel->AgeBoundYounger;
      break;
    case IndexOfamPreparers:
      Result = AgeModel->PreparersComboBoxText;
      break;
	case IndexOfamDatePrepared:
	  Result = AgeModel->DatePrepared;
	  break;
    case IndexOfamNotes:
      Result = AgeModel->Notes;
      break;
  }
  return (Result);
}
//---------------------------------------------------------------------------

void __fastcall TAgeModelDataSource::Notify(void * Ptr, TListNotification Action)
{
  DataChanged();
}
//---------------------------------------------------------------------------

void * __fastcall TAgeModelDataSource::InsertRecord(void * ARecordHandle)
{
  AGEMODEL* AgeModel = new AGEMODEL;
  FAgeModels->Insert((int)ARecordHandle, AgeModel);
  TcxDataRecordHandle* Result = (TcxDataRecordHandle*)ARecordHandle;
  return (Result);
}
//---------------------------------------------------------------------------

void * __fastcall TAgeModelDataSource::AppendRecord(void)
{
  TcxDataRecordHandle* Result = (TcxDataRecordHandle*)FAgeModels->Count;
  AGEMODEL* AgeModel = new AGEMODEL;
  FAgeModels->Add(AgeModel);
  return (Result);
}
//---------------------------------------------------------------------------

void __fastcall TAgeModelDataSource::SetValue(void * ARecordHandle, void * AItemHandle, const Variant &AValue)
{
  // gets values from grid and stores them
  UnicodeString Value;
  int AColumnId = GetDefaultItemID((int)AItemHandle);
  AGEMODEL* AgeModel = FAgeModels->AgeModels[(int)ARecordHandle];
  switch (AColumnId) {
    case IndexOfamChronNo:
      AgeModel->ChronNumber = (AValue.IsNull()) ? NaN : StrToInt(AValue);
      break;
    case IndexOfamName:
	  AgeModel->ChronologyName = VarToStr(AValue);
	  break;
	case IndexOfamAgeUnits:
	  AgeModel->AgeUnits = VarToStr(AValue);
      break;
	case IndexOfamDefault:
	  AgeModel->Default = (AValue.IsNull()) ? false : AValue;
	  break;
	case IndexOfamAgeModel:
	  AgeModel->AgeModel = VarToStr(AValue);
      break;
	case IndexOfamOlderBound:
	  if (AValue.IsNull())
		AgeModel->AgeBoundOlder = Unassigned();
	  else {
		AgeModel->AgeBoundOlder = AValue;
		AgeModel->AgeBoundOlder.ChangeType(varDouble);
		}
	  break;
	case IndexOfamYoungerBound:
	  if (AValue.IsNull())
		AgeModel->AgeBoundYounger = Unassigned();
	  else {
		AgeModel->AgeBoundYounger = AValue;
		AgeModel->AgeBoundYounger.ChangeType(varDouble);
		}
	  break;
    case IndexOfamPreparers:
      break;
	case IndexOfamDatePrepared:
	  AgeModel->DatePrepared = AValue;
	  break;
    case IndexOfamNotes:
	  AgeModel->Notes = VarToStr(AValue);
	  break;
  }
}
//---------------------------------------------------------------------------

bool CHRON::operator != (const CHRON& comp)
{
   // return true if any of the variables are not equal
   if (this == &comp) return false;
   if (NeotomaChronControlID != comp.NeotomaChronControlID) return true;
   if (NeotomaAnalUnitID != comp.NeotomaAnalUnitID) return true;
   if (Depth != comp.Depth) return true;
   if (Thickness != comp.Thickness) return true;
   if (AgeValue != comp.AgeValue) return true;
   if (AgeLimitOlder != comp.AgeLimitOlder) return true;
   if (AgeLimitYounger != comp.AgeLimitYounger) return true;
   if (AnalUnit != comp.AnalUnit) return true;
   if (AgeUnits != comp.AgeUnits) return true;
   if (ControlType != comp.ControlType) return true;
   if (CalibCurve != comp.CalibCurve) return true;
   if (Calib.Program != comp.Calib.Program) return true;
   if (Calib.Version != comp.Calib.Version) return true;
   if (Notes != comp.Notes) return true;

   if (GeochronIDs.size() != comp.GeochronIDs.size())
	 return true;
   else if (GeochronIDs.size() != 0) {
	 for (unsigned int i=0; i<comp.GeochronIDs.size(); i++) {
	   if (find(GeochronIDs.begin(), GeochronIDs.end(), comp.GeochronIDs[i]) == GeochronIDs.end())
		 return true;
	   }
	 }

   return false;
}
//---------------------------------------------------------------------------

int __fastcall TChronDataSource::GetRecordCount(void)
{
  int Result = 0;
  if (GetMasterRecordIndex() >= 0) {
    AGEMODEL *AgeModel = (AGEMODEL*)MasterDataSource->AgeModelList->AgeModels[GetMasterRecordIndex()];
    Result = AgeModel->ChronControls->Count;
    }
  return (Result);
}
//---------------------------------------------------------------------------

Variant __fastcall TChronDataSource::GetValue(void * ARecordHandle, void * AItemHandle)
{
  int AColumnId = GetDefaultItemID(int(AItemHandle));

  AGEMODEL *AgeModel = (AGEMODEL*)MasterDataSource->AgeModelList->AgeModels[GetMasterRecordIndex()];
  CHRON *Chron = (CHRON*)AgeModel->ChronControls->Items[(int)ARecordHandle];
  UnicodeString Links, NewLink;

  UnicodeString CalibProgram;
  Variant Result;
  switch (AColumnId) {
	case IndexOfchDepth:
	  Result = Chron->Depth;
	  break;
	case IndexOfchThickness:
	  Result = Chron->Thickness;
	  break;
	case IndexOfchAnalUnit:
	  Result = Chron->AnalUnit;
	  break;
	case IndexOfchAnalUnitID:
	  if (Chron->NeotomaAnalUnitID == -1)
		Result = Unassigned();
	  else
	    Result = Chron->NeotomaAnalUnitID;
	  break;
	case IndexOfchAgeUnits:
	  Result = Chron->AgeUnits;
	  break;
	case IndexOfchAge:
	  Result = Chron->AgeValue;
	  break;
	case IndexOfchOlderLimit:
	  Result = Chron->AgeLimitOlder;
	  break;
	case IndexOfchYoungerLimit:
	  Result = Chron->AgeLimitYounger;
	  break;
	case IndexOfchAgeBasis:
	  Result = Chron->ControlType;
	  break;
    case IndexOfchCalibCurve:
	  Result = Chron->CalibCurve;
      break;
	case IndexOfchCalibProgram:
	  CalibProgram = Chron->Calib.Program;
	  if (!CalibProgram.IsEmpty() && !Chron->Calib.Version.IsEmpty())
        CalibProgram += (" " + Chron->Calib.Version);
      Result = CalibProgram;
      break;
	case IndexOfchGeochron:
	  for (unsigned int i=0; i<Chron->GeochronIDs.size(); i++) {
		int ID = Chron->GeochronIDs[i];
		vector<GEOCHRON>::iterator itr;
		vector<GEOCHRON>::iterator begin = MasterDataSource->AgeModelList->GeochronList->Dates.begin();
		vector<GEOCHRON>::iterator end = MasterDataSource->AgeModelList->GeochronList->Dates.end();
		for (itr = begin; itr != end; itr++) {
		  if (ID == itr->ID)
			break;
		  }
		if (itr != end) {
		  if (!itr->LabNumber.IsEmpty() && !itr->Age.IsEmpty())
			NewLink = "{" + itr->LabNumber + ";" + VarToStr(itr->Age) + "}";
		  else if (!itr->LabNumber.IsEmpty())
			NewLink = "{" + itr->LabNumber + "}";
		  else if (!itr->Age.IsEmpty())
			NewLink = "{" + VarToStr(itr->Age) + "}";
		  else
			NewLink = "{}";
		  if (Links.IsEmpty())
			Links = NewLink;
		  else {
			Links += ",";
			Links += NewLink;
			}
		  }
		}
	  if (Links.IsEmpty())
		//Result.ChangeType(varEmpty);
		Result = Unassigned();
	  else
		Result = Links;
	  break;
	case IndexOfchNotes:
	  Result = Chron->Notes;
	  break;
	}
  return (Result);
}
//---------------------------------------------------------------------------

void __fastcall TChronDataSource::SetValue(void * ARecordHandle, void * AItemHandle, const Variant &AValue)
{
  int AColumnId = GetDefaultItemID((int)AItemHandle);
  int Index = GetMasterRecordIndex();
  AGEMODEL *AgeModel = (AGEMODEL*)MasterDataSource->AgeModelList->AgeModels[Index];
  CHRON *Chron = (CHRON*)AgeModel->ChronControls->Items[(int)ARecordHandle];
  switch (AColumnId) {
	case IndexOfchDepth:
	  if (AValue.IsNull())
		Chron->Depth = Unassigned();
	  else {
		Chron->Depth = AValue;
		Chron->Depth.ChangeType(varDouble);
		}
	  break;
	case IndexOfchThickness:
	  if (AValue.IsNull())
		Chron->Thickness = Unassigned();
	  else {
		Chron->Thickness = AValue;
		Chron->Thickness.ChangeType(varDouble);
		}
	  break;
	case IndexOfchAnalUnit:
	  Chron->AnalUnit = VarToStr(AValue);
	  break;
	case IndexOfchAnalUnitID:
	  if (AValue.IsNull())
		Chron->NeotomaAnalUnitID = -1;
	  else
		Chron->NeotomaAnalUnitID = AValue;
	  break;
	case IndexOfchAgeUnits:
	  Chron->AgeUnits = VarToStr(AValue);
	  break;
	case IndexOfchAge:
	  if (AValue.IsNull())
		Chron->AgeValue = Unassigned();
	  else {
		Chron->AgeValue = AValue;
		Chron->AgeValue.ChangeType(varDouble);
		}
	  break;
	case IndexOfchOlderLimit:
	  if (AValue.IsNull())
		Chron->AgeLimitOlder = Unassigned();
	  else {
		Chron->AgeLimitOlder = AValue;
		Chron->AgeLimitOlder.ChangeType(varDouble);
		}
	  break;
	case IndexOfchYoungerLimit:
	  if (AValue.IsNull())
		Chron->AgeLimitYounger = Unassigned();
	  else {
		Chron->AgeLimitYounger = AValue;
		Chron->AgeLimitYounger.ChangeType(varDouble);
		}
	  break;
	case IndexOfchAgeBasis:
	  Chron->ControlType = VarToStr(AValue);
	  break;
	case IndexOfchCalibCurve:
	  Chron->CalibCurve = VarToStr(AValue);
      break;
	case IndexOfchNotes:
	  Chron->Notes = VarToStr(AValue);
	  break;
    }
}
//---------------------------------------------------------------------------

void * __fastcall TChronDataSource::AppendRecord(void)
{
  AGEMODEL *AgeModel = (AGEMODEL*)MasterDataSource->AgeModelList->AgeModels[GetMasterRecordIndex()];
  CHRON* Chron = new CHRON;
  void* Result = (TcxDataRecordHandle*)AgeModel->ChronControls->Add(Chron);
  DataChanged();
  return (Result);
}
//---------------------------------------------------------------------------

void __fastcall TChronDataSource::Notify(void * Ptr, TListNotification Action)
{
  DataChanged();
}
//---------------------------------------------------------------------------

void * __fastcall TChronDataSource::InsertRecord(void * ARecordHandle)
{
  AGEMODEL *AgeModel = (AGEMODEL*)MasterDataSource->AgeModelList->AgeModels[GetMasterRecordIndex()];
  CHRON* Chron = new CHRON;
  AgeModel->ChronControls->Insert((int)ARecordHandle, Chron);
  void * Result = ARecordHandle;
  DataChanged();
  return (Result);
}
//---------------------------------------------------------------------------

void __fastcall TChronDataSource::DeleteRecord(void * ARecordHandle)
{
  AGEMODEL *AgeModel = (AGEMODEL*)MasterDataSource->AgeModelList->AgeModels[GetMasterRecordIndex()];
  CHRON *Chron = (CHRON*)AgeModel->ChronControls->Items[(int)ARecordHandle];
  AgeModel->ChronControls->Delete((int)ARecordHandle);
  delete Chron;
  DataChanged();
}
//---------------------------------------------------------------------------

int TChronDataSource::GetMasterRecordIndex()
{
  return (DataController->GetMasterRecordIndex());
}
//---------------------------------------------------------------------------





