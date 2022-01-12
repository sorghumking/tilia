//---------------------------------------------------------------------------

#ifndef TITaxSynH
#define TITaxSynH
#include <vector>
#include "cxGridTableView.hpp"
#ifndef TIPubH
#include "TIPub.h"
#endif
#ifndef TICommonH
#include "TICommon.h"
#endif
//---------------------------------------------------------------------------

class TSynonymy
{
private:
	vector<SYNONYMY> Items;
	vector<SYNONYMY>::pointer GetSynonym(int AIndex);
public:
	map<UnicodeString, PUBLICATION*> Publications;
public:
	TSynonymy() {}
	TSynonymy(vector<SYNONYMY>& Synonyms);
	__fastcall ~TSynonymy() {}
	void __fastcall Clear(void);
	void __fastcall Add(SYNONYMY& Synonym);
	void Delete(int AIndex);
	void Insert(int AIndex, SYNONYMY& Synonym);
	int Count(void) { return Items.size(); }
	__property vector<SYNONYMY>::pointer Synonym[int Index] = {read = GetSynonym};
	__property vector<SYNONYMY> Synonyms = {read = Items};
};
//---------------------------------------------------------------------------

class TSynonymyDataSource : public TcxCustomDataSource
{
private:
	TSynonymy* FSynonymy;
protected:
	void * __fastcall InsertRecord(void * ARecordHandle);
	void * __fastcall AppendRecord(void);
	void __fastcall DeleteRecord(void * ARecordHandle);
	int __fastcall GetRecordCount(void);
	Variant __fastcall GetValue(void * ARecordHandle, void * AItemHandle);
	void __fastcall SetValue(void * ARecordHandle, void * AItemHandle, const Variant &AValue);
public:
	__fastcall TSynonymyDataSource(TSynonymy* ASynonymy);
	__fastcall ~TSynonymyDataSource() { }
	__property TSynonymy* Synonymy = {read = FSynonymy};
};
//---------------------------------------------------------------------------

const int IndexOfsynName    = 0;
const int IndexOfsynContrib = 1;
const int IndexOfsynPub     = 2;
const int IndexOfsynNotes   = 3;
//---------------------------------------------------------------------------

#endif
