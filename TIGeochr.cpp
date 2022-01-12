//---------------------------------------------------------------------------
#pragma hdrstop

#include <algorithm>
#include "TIGeochr.h"
#ifndef TGUtilsH
#include "TGUtils.h"
#endif
#ifndef TIUtilsH
#include "TIUtils.h"
#endif
//---------------------------------------------------------------------------

#pragma package(smart_init)

GEOCHRON::GEOCHRON()
{
  FID = -1;
  FNeotomaAnalUnitID = -1;
  Sigma = 1;
  GreaterThan = false;
}
//---------------------------------------------------------------------------

void GEOCHRON::Clear(void)
{
  FID = -1;
  FNeotomaGeochronID = -1;
  Sigma = 1;
  GreaterThan = false;
}
//---------------------------------------------------------------------------

TGeochronList::TGeochronList(TComponent* Owner)
{
  MaxID = 0;
  publications = new TStringList;
  TSSForm = (TTilSpreadSheetForm*)Owner;
}
//---------------------------------------------------------------------------

__fastcall TGeochronList::~TGeochronList()
{
  delete publications;
}
//---------------------------------------------------------------------------

vector<GEOCHRON>::pointer TGeochronList::GetDate(int AIndex)
{
  return &Items[AIndex];
}
//---------------------------------------------------------------------------

void __fastcall TGeochronList::Clear(void)
{
  Items.clear();
}
//---------------------------------------------------------------------------

void __fastcall TGeochronList::Add(GEOCHRON& Date)
{
   if (Date.ID == -1)
	 Date.SetID(++MaxID);
   else if (Date.ID > MaxID)
	 MaxID = Date.ID;
   Items.push_back(Date);
}
//---------------------------------------------------------------------------

void TGeochronList::Delete(int AIndex)
{
   vector<GEOCHRON>::iterator itr = Items.begin() + AIndex;
   if (TSSForm->Downloaded && tiLicense->Type() == verNEOTOMASTEWARD)
	 TSSForm->DeleteGeochron(itr->NeotomaGeochronID);
   Items.erase(itr);
}
//---------------------------------------------------------------------------

void TGeochronList::Insert(int AIndex, GEOCHRON& Date)
{
   vector<GEOCHRON>::iterator itr = Items.begin() + AIndex;
   Items.insert(itr, Date);
}
//---------------------------------------------------------------------------

void TGeochronList::SortAscending(void)
{
   std::sort(Items.begin(), Items.end(), DateDepthCompare);
}
//---------------------------------------------------------------------------

bool TGeochronList::DepthCompare(GEOCHRON& Date1, GEOCHRON& Date2)
{
   if (Date2.Depth.IsEmpty())
	 return false;
   else if (Date1.Depth.IsEmpty())
	 return true;
   else
	 return (Date1.Depth < Date2.Depth);
}
//---------------------------------------------------------------------------

//static bool DateDepthCompare (int i, int j) { return (i<j); }
//static bool DateDepthCompare (GEOCHRON& Date1, GEOCHRON& Date2);
bool __fastcall TGeochronList::DateDepthCompare(GEOCHRON& Date1, GEOCHRON& Date2)
{
   if (Date1.Depth.IsEmpty() && Date2.Depth.IsEmpty())
	 return false;
   else if (Date1.Depth.IsEmpty())
	 return true;
   else if (Date2.Depth.IsEmpty())
	 return false;

   if (Date1.Depth < Date2.Depth)
	 return true;
   else if (Date1.Depth > Date2.Depth)
	 return false;
   else {   // Depths are equal
	 if (Date1.Method < Date2.Method)
	   return true;
	 else if (Date1.Method > Date2.Method)
	   return false;
	 else {  // Methods are the same
	   if (Date1.Age < Date2.Age)
		 return true;
	   else
		 return false;
	   }
	 }
}
//---------------------------------------------------------------------------

__fastcall TGeochronDataSource::TGeochronDataSource(TGeochronList* AGeochronList)
{
  FGeochronList = AGeochronList;
}
//---------------------------------------------------------------------------

void __fastcall TGeochronDataSource::DeleteRecord(void * ARecordHandle)
{
  FGeochronList->Delete((int)ARecordHandle);
  DataChanged();   // new
}
//---------------------------------------------------------------------------

int __fastcall TGeochronDataSource::GetRecordCount(void)
{
  return(FGeochronList->Count());
}
//---------------------------------------------------------------------------

void * __fastcall TGeochronDataSource::InsertRecord(void * ARecordHandle)
{
  GEOCHRON Date;
  FGeochronList->Insert((int)ARecordHandle, Date);
  TcxDataRecordHandle* Result = (TcxDataRecordHandle*)ARecordHandle;
  DataChanged();
  return (Result);
}
//---------------------------------------------------------------------------

void * __fastcall TGeochronDataSource::AppendRecord(void)
{
  TcxDataRecordHandle* Result = (TcxDataRecordHandle*)FGeochronList->Count();
  GEOCHRON Date;
  FGeochronList->Add(Date);
  DataChanged();
  return (Result);
}
//---------------------------------------------------------------------------

Variant __fastcall TGeochronDataSource::GetValue(void * ARecordHandle, void * AItemHandle)
{
  // displays value in grid based on stored data
  int AColumnId = GetDefaultItemID((int)AItemHandle);
  vector<GEOCHRON>::pointer DatePtr = FGeochronList->Date[(int)ARecordHandle];
  Variant Result;
  UnicodeString ParamStr;

  switch (AColumnId) {
    case IndexOfgeMethod:
	  Result = DatePtr->Method;
      break;
    case IndexOfgeAgeUnits:
	  Result = DatePtr->AgeUnits;
      break;
    case IndexOfgeDepth:
	  if (DatePtr->Depth.IsEmpty())
		Result.ChangeType(varEmpty);
      else
		Result = DatePtr->Depth;
	  break;
	case IndexOfgeThickness:
	  if (DatePtr->Thickness.IsEmpty())
        Result.ChangeType(varEmpty);
      else
		Result = DatePtr->Thickness;
      break;
    case IndexOfgeAnalUnit:
	  Result = DatePtr->AnalUnit;
	  break;
	case IndexOfgeAnalUnitID:
	  if (DatePtr->NeotomaAnalUnitID == -1)
		Result = Unassigned();
	  else
		Result = DatePtr->NeotomaAnalUnitID;
	  break;
    case IndexOfgeLabNumber:
	  Result = DatePtr->LabNumber;
	  break;
    case IndexOfgeAge:
	  if (DatePtr->Age.IsEmpty())
		Result.ChangeType(varEmpty);
	  else
		Result = DatePtr->Age;
      break;
    case IndexOfgeErrorOlder:
	  if (DatePtr->ErrorOlder.IsEmpty())
		Result.ChangeType(varEmpty);
      else
		Result = DatePtr->ErrorOlder;
      break;
    case IndexOfgeErrorYounger:
      if (DatePtr->ErrorYounger.IsEmpty())
        Result.ChangeType(varEmpty);
      else
		Result = DatePtr->ErrorYounger;
      break;
    case IndexOfgeSigma:
	  Result = DatePtr->Sigma;
      break;
    case IndexOfgeSD:
	  if (DatePtr->StdDev.IsEmpty())
        Result.ChangeType(varEmpty);
      else
		Result = DatePtr->StdDev;
      break;
    case IndexOfgeInfinite:
	  Result = DatePtr->GreaterThan;
      break;
	case IndexOfgeParams:
	  ParamStr = L"";
	  if (DatePtr->Parameters.size() > 0) {
		map<UnicodeString,Variant>::iterator begin = DatePtr->Parameters.begin();
		map<UnicodeString,Variant>::iterator end = DatePtr->Parameters.end();
		map<UnicodeString,Variant>::iterator itr;
		for (itr = begin; itr != end; itr++) {
		  if (!ParamStr.IsEmpty())
			ParamStr += L";";
		  ParamStr += (itr->first + L":" + VarToStr(itr->second));
		  }
		}
	  Result = ParamStr;
	  break;
    case IndexOfgeMaterialDated:
	  Result = DatePtr->MaterialDated;
      break;
    case IndexOfgePublication:
      break;
    case IndexOfgeNotes:
      Result = DatePtr->Notes;
      break;
  }
  return (Result);
}
//---------------------------------------------------------------------------

void __fastcall TGeochronDataSource::SetValue(void * ARecordHandle, void * AItemHandle, const Variant &AValue)
{
  // gets values from grid and stores them
  int OldSigma;
  UnicodeString Value;

  int AColumnId = GetDefaultItemID((int)AItemHandle);
  vector<GEOCHRON>::pointer DatePtr = FGeochronList->Date[(int)ARecordHandle];

  switch (AColumnId) {
    case IndexOfgeMethod:
	  DatePtr->Method = VarToStr(AValue);
	  break;
	case IndexOfgeAgeUnits:
	  DatePtr->AgeUnits = VarToStr(AValue);
      break;
    case IndexOfgeDepth:
	  if (AValue.IsNull())
		DatePtr->Depth = Unassigned();
	  else {
		DatePtr->Depth = AValue;
		DatePtr->Depth.ChangeType(varDouble);
		}
	  break;
	case IndexOfgeThickness:
	  if (AValue.IsNull())
		DatePtr->Thickness = Unassigned();
	  else {
		DatePtr->Thickness = AValue;
		DatePtr->Thickness.ChangeType(varDouble);
		}
	  break;
	case IndexOfgeAnalUnit:
	  DatePtr->AnalUnit = VarToStr(AValue);
	  break;
	case IndexOfgeAnalUnitID:
	  if (AValue.IsNull())
		DatePtr->NeotomaAnalUnitID = -1;
	  else
		DatePtr->NeotomaAnalUnitID = AValue;
	  break;
    case IndexOfgeLabNumber:
	  DatePtr->LabNumber = VarToStr(AValue);
      break;
    case IndexOfgeAge:
	  if (AValue.IsNull())
		DatePtr->Age = Unassigned();
	  else {
		DatePtr->Age = AValue;
		DatePtr->Age.ChangeType(varDouble);
		}
      break;
    case IndexOfgeErrorOlder:
	  if (AValue.IsNull()) {
		DatePtr->ErrorOlder = Unassigned();
		DatePtr->StdDev = Unassigned();
        }
      else {
		DatePtr->ErrorOlder = AValue;
		if (!DatePtr->ErrorOlder.IsEmpty() && !DatePtr->ErrorYounger.IsEmpty())
		  DatePtr->StdDev = (DatePtr->ErrorOlder == DatePtr->ErrorYounger) ?
			 (double)DatePtr->ErrorOlder/(double)DatePtr->Sigma : Unassigned();
		else
		  DatePtr->StdDev = Unassigned();
		}
      break;
    case IndexOfgeErrorYounger:
	  if (AValue.IsNull()) {
		DatePtr->ErrorYounger = Unassigned();
		DatePtr->StdDev = Unassigned();
        }
      else {
		DatePtr->ErrorYounger = AValue;
		if (!DatePtr->ErrorOlder.IsEmpty() && !DatePtr->ErrorYounger.IsEmpty())
		  DatePtr->StdDev = (DatePtr->ErrorOlder == DatePtr->ErrorYounger) ?
						  (double)DatePtr->ErrorOlder/(double)DatePtr->Sigma : Unassigned();
        else
		  DatePtr->StdDev = Unassigned();
        }
      break;
    case IndexOfgeSigma:
	  OldSigma = DatePtr->Sigma;
	  DatePtr->Sigma = (AValue.IsNull()) ? 1 : AValue;
	  if (!DatePtr->StdDev.IsEmpty()) {
		if (OldSigma == 1 && DatePtr->Sigma == 2)
		  DatePtr->StdDev *= 0.5;
		else if (OldSigma == 2 && DatePtr->Sigma == 1)
		  DatePtr->StdDev *= 2.0;
        }
      break;
    case IndexOfgeSD:
	  if (AValue.IsNull())
		DatePtr->StdDev = Unassigned();
      else
		DatePtr->StdDev = AValue;
	  DatePtr->ErrorOlder = DatePtr->StdDev;
	  DatePtr->ErrorYounger = DatePtr->StdDev;
	  DatePtr->Sigma = 1;
      break;
    case IndexOfgeInfinite:
	  DatePtr->GreaterThan = (AValue.IsNull()) ? false : AValue;
	  if (DatePtr->GreaterThan) {
		DatePtr->StdDev = Unassigned();
		DatePtr->ErrorOlder = Unassigned();
		DatePtr->ErrorYounger = Unassigned();
        }
	  break;
	case IndexOfgeParams:
	  break;
    case IndexOfgeMaterialDated:
	  DatePtr->MaterialDated = VarToStr(AValue);
	  break;
	case IndexOfgePublication:
	  //Beep();
      break;
    case IndexOfgeNotes:
	  DatePtr->Notes = VarToStr(AValue);
      break;
  }
}
//---------------------------------------------------------------------------

int __fastcall TTaxonDatedDataSource::GetRecordCount(void)
{
  int Result = 0;
  if (GetMasterRecordIndex() >= 0) {
	GEOCHRON& Geochron = MasterDataSource->GeochronList->Dates[GetMasterRecordIndex()];
	Result = Geochron.TaxaDated.size();
	}
  return (Result);
}
//---------------------------------------------------------------------------

Variant __fastcall TTaxonDatedDataSource::GetValue(void * ARecordHandle, void * AItemHandle)
{
  int AColumnId = GetDefaultItemID(int(AItemHandle));

  GEOCHRON& Geochron = MasterDataSource->GeochronList->Dates[GetMasterRecordIndex()];
  TAXONDATED* TaxonDated = &Geochron.TaxaDated[(int)ARecordHandle];

  UnicodeString CalibProgram;
  Variant Result;
  switch (AColumnId) {
	//case IndexOftxID:
	//  Result = TaxonDated->ID;
	//  break;
	case IndexOftxUserSpecimenID:
	  Result = TaxonDated->UserSpecID;
	  //ShowMessage(TaxonDated->UserSpecID);
	  break;
	case IndexOftxTaxon:
	  Result = TaxonDated->Taxon;
	  break;
	case IndexOftxElement:
	  Result = TaxonDated->Element;
	  break;
	case IndexOftxFraction:
	  Result = TaxonDated->Fraction;
	  break;
	case IndexOftxCalAgeMedian:
	  Result = TaxonDated->CalAgeMedian;
	  break;
	case IndexOftxCalAgeOlder:
	  Result = TaxonDated->CalAgeOlder;
	  break;
	case IndexOftxCalAgeYounger:
	  Result = TaxonDated->CalAgeYounger;
	  break;
	case IndexOftxCalCurve:
	  Result = TaxonDated->CalibCurve;
	  break;
	case IndexOftxCalProgram:
	  CalibProgram = TaxonDated->Calib.Program;
	  if (!CalibProgram.IsEmpty() && !TaxonDated->Calib.Version.IsEmpty())
		CalibProgram += (" " + TaxonDated->Calib.Version);
	  Result = CalibProgram;
	  break;
	case IndexOftxNotes:
	  Result = TaxonDated->Notes;
	  break;
	}
  return (Result);
}
//---------------------------------------------------------------------------

void __fastcall TTaxonDatedDataSource::SetValue(void * ARecordHandle, void * AItemHandle, const Variant &AValue)
{
  int AColumnId = GetDefaultItemID((int)AItemHandle);

  int Index = GetMasterRecordIndex();

  GEOCHRON& Geochron = MasterDataSource->GeochronList->Dates[Index];
  TAXONDATED *TaxonDated = &Geochron.TaxaDated[(int)ARecordHandle];

  switch (AColumnId) {
	//case IndexOftxID:
	//  if ((TaxonDated->ID = VariantToInt(AValue,-1)) == -1)
	//	TaxonDated->ID = ++TaxonDatedID;
	//  break;
	case IndexOftxUserSpecimenID:
	  TaxonDated->UserSpecID = VarToStr(AValue);
      //ShowMessage(TaxonDated->UserSpecID);
	  if (!TaxonDated->UserSpecID.IsEmpty())
		TaxonDated->Specimen = Specimens[TaxonDated->UserSpecID];
	  else
		TaxonDated->Specimen = NULL;
	  break;
	case IndexOftxTaxon:
	  TaxonDated->Taxon = VarToStr(AValue);
	  break;
	case IndexOftxElement:
	  TaxonDated->Element = VarToStr(AValue);
	  break;
	case IndexOftxFraction:
	  TaxonDated->Fraction = VarToStr(AValue);
	  break;
	case IndexOftxCalAgeMedian:
	  if (AValue.IsNull())
		TaxonDated->CalAgeMedian = Unassigned();
	  else
		TaxonDated->CalAgeMedian = AValue;
	  break;
	case IndexOftxCalAgeOlder:
	  if (AValue.IsNull())
		TaxonDated->CalAgeOlder = Unassigned();
	  else
		TaxonDated->CalAgeOlder = AValue;
	  break;
	case IndexOftxCalAgeYounger:
	  if (AValue.IsNull())
		TaxonDated->CalAgeYounger = Unassigned();
	  else
		TaxonDated->CalAgeYounger = AValue;
	  break;
	case IndexOftxCalCurve:
	  TaxonDated->CalibCurve = VarToStr(AValue);
	  break;
	case IndexOftxNotes:
	  TaxonDated->Notes = VarToStr(AValue);
	  break;
	}
}
//---------------------------------------------------------------------------

void * __fastcall TTaxonDatedDataSource::AppendRecord(void)
{
  GEOCHRON& Geochron = MasterDataSource->GeochronList->Dates[GetMasterRecordIndex()];

  // TAXONDATED TaxonDated(-1);
  TAXONDATED TaxonDated;
  Geochron.TaxaDated.push_back(TaxonDated);
  void* Result = (void*)(Geochron.TaxaDated.size() - 1);
  DataChanged();
  return (Result);
}
//---------------------------------------------------------------------------

void * __fastcall TTaxonDatedDataSource::InsertRecord(void * ARecordHandle)
{
  GEOCHRON& Geochron = MasterDataSource->GeochronList->Dates[GetMasterRecordIndex()];
  // TAXONDATED TaxonDated(-1);
  TAXONDATED TaxonDated;
  vector<TAXONDATED>::iterator itr = Geochron.TaxaDated.begin() + (int)ARecordHandle;
  Geochron.TaxaDated.insert(itr, TaxonDated);
  void * Result = ARecordHandle;
  DataChanged();
  return (Result);
}
//---------------------------------------------------------------------------

void __fastcall TTaxonDatedDataSource::DeleteRecord(void * ARecordHandle)
{
  GEOCHRON& Geochron = MasterDataSource->GeochronList->Dates[GetMasterRecordIndex()];

  vector<TAXONDATED>::iterator itr = Geochron.TaxaDated.begin() + (int)ARecordHandle;
  Geochron.TaxaDated.erase(itr);
  DataChanged();
}
//---------------------------------------------------------------------------

int TTaxonDatedDataSource::GetMasterRecordIndex()
{
  return (DataController->GetMasterRecordIndex());
}
//---------------------------------------------------------------------------

