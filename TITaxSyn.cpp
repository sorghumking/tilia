//---------------------------------------------------------------------------
#include <vcl.h>
#include "pch.h"
#pragma hdrstop

#include "TITaxSyn.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
//---------------------------------------------------------------------------

int SYNONYMY::NeotomaPubID(void)
{
   if (Pub != NULL)
	 return Pub->NeotomaID;
   else
	 return -1;
}
//---------------------------------------------------------------------------

void TAXON_NOTES::operator = (const TAXON_NOTES& copy)
{
   if (this == &copy) return;
   Notes = copy.Notes;
   Synonymy = copy.Synonymy;
}
//---------------------------------------------------------------------------

TSynonymy::TSynonymy(vector<SYNONYMY>& Synonyms)
{
   Items = Synonyms;
}
//---------------------------------------------------------------------------

vector<SYNONYMY>::pointer TSynonymy::GetSynonym(int AIndex)
{
  return &Items[AIndex];
}
//---------------------------------------------------------------------------

void __fastcall TSynonymy::Clear(void)
{
  Items.clear();
}
//---------------------------------------------------------------------------

void __fastcall TSynonymy::Add(SYNONYMY& Synonym)
{
   Items.push_back(Synonym);
}
//---------------------------------------------------------------------------

void TSynonymy::Delete(int AIndex)
{
   vector<SYNONYMY>::iterator itr = Items.begin() + AIndex;
   Items.erase(itr);
}
//---------------------------------------------------------------------------

void TSynonymy::Insert(int AIndex, SYNONYMY& Synonym)
{
   vector<SYNONYMY>::iterator itr = Items.begin() + AIndex;
   Items.insert(itr, Synonym);
}
//---------------------------------------------------------------------------

__fastcall TSynonymyDataSource::TSynonymyDataSource(TSynonymy* ASynonymy)
{
   FSynonymy = ASynonymy;
}
//---------------------------------------------------------------------------

int __fastcall TSynonymyDataSource::GetRecordCount(void)
{
  return(FSynonymy->Count());
}
//---------------------------------------------------------------------------

void __fastcall TSynonymyDataSource::DeleteRecord(void * ARecordHandle)
{
  FSynonymy->Delete((int)ARecordHandle);
  DataChanged();
}
//---------------------------------------------------------------------------

void * __fastcall TSynonymyDataSource::InsertRecord(void * ARecordHandle)
{
  SYNONYMY Synonym;
  FSynonymy->Insert((int)ARecordHandle, Synonym);
  TcxDataRecordHandle* Result = (TcxDataRecordHandle*)ARecordHandle;
  DataChanged();
  return (Result);
}
//---------------------------------------------------------------------------

void * __fastcall TSynonymyDataSource::AppendRecord(void)
{
  TcxDataRecordHandle* Result = (TcxDataRecordHandle*)FSynonymy->Count();
  SYNONYMY Synonym;
  FSynonymy->Add(Synonym);
  DataChanged();
  return (Result);
}
//---------------------------------------------------------------------------

Variant __fastcall TSynonymyDataSource::GetValue(void * ARecordHandle, void * AItemHandle)
{
  int AColumnId = GetDefaultItemID((int)AItemHandle);
  vector<SYNONYMY>::pointer SynonymPtr = FSynonymy->Synonym[(int)ARecordHandle];
  Variant Result;
  map<UnicodeString, PUBLICATION*>::iterator itr;
  switch (AColumnId) {
	case IndexOfsynName:
	  Result = SynonymPtr->TaxonName;
	  break;
	case IndexOfsynContrib:
	  Result = SynonymPtr->Contrib;
	  break;
	case IndexOfsynPub:
	  for (itr = FSynonymy->Publications.begin(); itr != FSynonymy->Publications.end(); itr++) {
		if (SynonymPtr->Pub == itr->second) {
		  Result = itr->first;
		  break;
		  }
		}
	  break;
	case IndexOfsynNotes:
	  Result = SynonymPtr->Notes;
	  break;
  }
  return (Result);
}
//---------------------------------------------------------------------------

void __fastcall TSynonymyDataSource::SetValue(void * ARecordHandle, void * AItemHandle, const Variant &AValue)
{
  int AColumnId = GetDefaultItemID((int)AItemHandle);
  SYNONYMY* SynonymyPtr = FSynonymy->Synonym[(int)ARecordHandle];
  UnicodeString blank = L"";
  switch (AColumnId) {
	case IndexOfsynName:
	  SynonymyPtr->TaxonName = (AValue.IsNull()) ? blank : VarToStr(AValue);
	  break;
	case IndexOfsynContrib:
	  SynonymyPtr->Contrib = (AValue.IsNull()) ? false : AValue;
	  break;
	case IndexOfsynPub:
	  if (!AValue.IsNull())
		SynonymyPtr->Pub = FSynonymy->Publications[VarToStr(AValue)];
	  else
		SynonymyPtr->Pub = NULL;
	  break;
	case IndexOfsynNotes:
	  SynonymyPtr->Notes = (AValue.IsNull()) ? blank : VarToStr(AValue);
	  break;
	}
}
//---------------------------------------------------------------------------

