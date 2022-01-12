//---------------------------------------------------------------------------

#include <vcl.h>
#include "pch.h"
#include <algorithm>
#pragma hdrstop

#include "TINewTxn.h"
#ifndef TIUtilsH
#include "TIUtils.h"
#endif
#ifndef TINeotomaH
#include "TINeotoma.h"
#endif
#ifndef TIFndPubH
#include "TIFndPub.h"
#endif
#ifndef TNFindTaxonH
#include "TNFindTaxon.h"
#endif
#ifndef TNNewEcGrH
#include "TNNewEcGr.h"
#endif
#ifndef TNLoginH
#include "TNLogin.h"
#endif
#ifndef TIShoMemH
#include "TIShoMem.h"
#endif
#ifndef TNNewSynH
#include "TNNewSyn.h"
#endif
#ifndef TNUtilsH
#include "TNUtils.h"
#endif
#ifndef TIQueryH
#include "TIQuery.h"
#endif
#ifndef TNSelItmH
#include "TNSelItm.h"
#endif

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxListBox"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxTextEdit"
#pragma link "cxButtons"
#pragma link "ipwjson"
#pragma link "AdvCGrid"
#pragma link "AdvGrid"
#pragma link "AdvObj"
#pragma link "BaseGrid"
#pragma link "dxtree"
#pragma link "AdvDropDown"
#pragma link "AdvMultiColumnDropDown"
#pragma link "cxDropDownEdit"
#pragma link "cxMaskEdit"
#pragma link "AdvCGrid"
#pragma link "AdvGrid"
#pragma link "AdvObj"
#pragma link "BaseGrid"
#pragma link "AdvMemoDropDown"
#pragma link "frmctrllink"
#pragma link "AdvControlDropDown"
#pragma link "cxMemo"
#pragma link "cxGroupBox"
#pragma link "cxRadioGroup"
#pragma link "cxImage"
#pragma link "cxLabel"
#pragma link "ipshttps"
#pragma link "cxClasses"
#pragma link "cxCustomData"
#pragma link "cxData"
#pragma link "cxDataStorage"
#pragma link "cxDBData"
#pragma link "cxFilter"
#pragma link "cxGrid"
#pragma link "cxGridCustomTableView"
#pragma link "cxGridCustomView"
#pragma link "cxGridDBTableView"
#pragma link "cxGridLevel"
#pragma link "cxGridTableView"
#pragma link "cxNavigator"
#pragma link "cxStyles"
#pragma link "cxBlobEdit"
#pragma link "cxCheckBox"
#pragma link "cxCalendar"
#pragma link "cxButtonEdit"
#pragma link "cxListView"
#pragma link "dxSkinBlack"
#pragma link "dxSkinBlue"
#pragma link "dxSkinBlueprint"
#pragma link "dxSkinCaramel"
#pragma link "dxSkinCoffee"
#pragma link "dxSkinDarkRoom"
#pragma link "dxSkinDarkSide"
#pragma link "dxSkinDevExpressDarkStyle"
#pragma link "dxSkinDevExpressStyle"
#pragma link "dxSkinFoggy"
#pragma link "dxSkinGlassOceans"
#pragma link "dxSkinHighContrast"
#pragma link "dxSkiniMaginary"
#pragma link "dxSkinLilian"
#pragma link "dxSkinLiquidSky"
#pragma link "dxSkinLondonLiquidSky"
#pragma link "dxSkinMcSkin"
#pragma link "dxSkinMetropolis"
#pragma link "dxSkinMetropolisDark"
#pragma link "dxSkinMoneyTwins"
#pragma link "dxSkinOffice2007Black"
#pragma link "dxSkinOffice2007Blue"
#pragma link "dxSkinOffice2007Green"
#pragma link "dxSkinOffice2007Pink"
#pragma link "dxSkinOffice2007Silver"
#pragma link "dxSkinOffice2010Black"
#pragma link "dxSkinOffice2010Blue"
#pragma link "dxSkinOffice2010Silver"
#pragma link "dxSkinOffice2013DarkGray"
#pragma link "dxSkinOffice2013LightGray"
#pragma link "dxSkinOffice2013White"
#pragma link "dxSkinPumpkin"
#pragma link "dxSkinsCore"
#pragma link "dxSkinscxPCPainter"
#pragma link "dxSkinsDefaultPainters"
#pragma link "dxSkinSeven"
#pragma link "dxSkinSevenClassic"
#pragma link "dxSkinSharp"
#pragma link "dxSkinSharpPlus"
#pragma link "dxSkinSilver"
#pragma link "dxSkinSpringTime"
#pragma link "dxSkinStardust"
#pragma link "dxSkinSummer2008"
#pragma link "dxSkinTheAsphaltWorld"
#pragma link "dxSkinValentine"
#pragma link "dxSkinVS2010"
#pragma link "dxSkinWhiteprint"
#pragma link "dxSkinXmas2008Blue"
#pragma link "AdvUtil"
#pragma link "dxSkinOffice2016Colorful"
#pragma link "dxSkinOffice2016Dark"
#pragma link "dxSkinVisualStudio2013Blue"
#pragma link "dxSkinVisualStudio2013Dark"
#pragma link "dxSkinVisualStudio2013Light"
#pragma link "ipsjsons"
#pragma resource "*.dfm"
TNewTaxonForm *NewTaxonForm;
//---------------------------------------------------------------------------

NTMTAXONMAP::NTMTAXONMAP()
{
  HigherTaxonID.ChangeType(varEmpty);
  Extinct = false;
  PublicationID.ChangeType(varEmpty);
  ValidatorID.ChangeType(varEmpty);
  ValidateDate.ChangeType(varEmpty);
}
//---------------------------------------------------------------------------

void NTMTAXONMAP::Clear(void)
{
  TaxonCode = L"";
  TaxonName = L"";
  Author = L"";
  HigherTaxonID.ChangeType(varEmpty);
  Extinct = false;
  TaxaGroupID = L"";
  PublicationID.ChangeType(varEmpty);
  Notes = L"";
  ValidatorID.ChangeType(varEmpty);
  ValidateDate.ChangeType(varEmpty);
  EcolSetsGroups.clear();
}
//---------------------------------------------------------------------------

NTMSYNONYMREC::NTMSYNONYMREC()
{
  TaxonID.ChangeType(varEmpty);
  SynonymTypeID.ChangeType(varEmpty);
}
//---------------------------------------------------------------------------

void NTMSYNONYMREC::Clear(void)
{
  TaxonID.ChangeType(varEmpty);
  TaxonCode = L"";
  TaxonName = L"";
  Author = L"";
  SynonymTypeID.ChangeType(varEmpty);
  Extinct = false;
  TaxaGroupID = L"";
  PublicationID.ChangeType(varEmpty);
  Notes = L"";
  ValidatorID.ChangeType(varEmpty);
  ValidateDate.ChangeType(varEmpty);
}
//---------------------------------------------------------------------------

NTMTAXONREC::NTMTAXONREC()
{
  TaxonID.ChangeType(varEmpty);
}
//---------------------------------------------------------------------------

void NTMTAXONREC::Clear(void)
{
  TaxonID.ChangeType(varEmpty);
  TaxonCode = L"";
  TaxonName = L"";
  Author = L"";
  HigherTaxonID.ChangeType(varEmpty);
  Extinct = false;
  TaxaGroupID = L"";
  PublicationID.ChangeType(varEmpty);
  Notes = L"";
  ValidatorID.ChangeType(varEmpty);
  ValidateDate.ChangeType(varEmpty);
  EcolSetsGroups.clear();
  Synonyms.clear();
}
//---------------------------------------------------------------------------

vector<NTMTAXONREC>::pointer TEditNeotomaTaxa::GetTaxon(int AIndex)
{
  return &Items[AIndex];
}
//---------------------------------------------------------------------------

void __fastcall TEditNeotomaTaxa::Clear(void)
{
   Items.clear();
}
//---------------------------------------------------------------------------

void __fastcall TEditNeotomaTaxa::Add(NTMTAXONREC& Taxon)
{
   Items.push_back(Taxon);
}
//---------------------------------------------------------------------------

void TEditNeotomaTaxa::Delete(int AIndex)
{
   vector<NTMTAXONREC>::iterator itr = Items.begin() + AIndex;
   Items.erase(itr);
}
//---------------------------------------------------------------------------

__fastcall TEditNeotomaTaxaDataSource::TEditNeotomaTaxaDataSource(TEditNeotomaTaxa* AEditNeotomaTaxa,
	map<int,UnicodeString>* AEcolSetTypes)
{
   FEditNeotomaTaxa = AEditNeotomaTaxa;
   EcolSetTypes = AEcolSetTypes;
}
//---------------------------------------------------------------------------

int TEditNeotomaTaxaDataSource::GetEcolSetID(UnicodeString EcolSetName)
{
   int EcolSetID = -1;
   map<int,UnicodeString>::iterator itr;
   map<int,UnicodeString>::iterator begin = EcolSetTypes->begin();
   map<int,UnicodeString>::iterator end = EcolSetTypes->end();
   for (itr = begin; itr != end; itr++) {
	 if (SameText(EcolSetName, itr->second)) {
	   EcolSetID = itr->first;
	   break;
	   }
	 }
   return EcolSetID;
}
//---------------------------------------------------------------------------

void __fastcall TEditNeotomaTaxaDataSource::DeleteRecord(void * ARecordHandle)
{
  FEditNeotomaTaxa->Delete((int)ARecordHandle);
  DataChanged();
}
//---------------------------------------------------------------------------

int __fastcall TEditNeotomaTaxaDataSource::GetRecordCount(void)
{
  return(FEditNeotomaTaxa->Count());
}
//---------------------------------------------------------------------------

void * __fastcall TEditNeotomaTaxaDataSource::AppendRecord(void)
{
  TcxDataRecordHandle* Result = (TcxDataRecordHandle*)FEditNeotomaTaxa->Count();
  NTMTAXONREC Taxon;
  FEditNeotomaTaxa->Add(Taxon);
  DataChanged();
  return (Result);
}
//---------------------------------------------------------------------------

bool __fastcall TEditNeotomaTaxaDataSource::GetDetailHasChildren(int ARecordIndex, int ARelationIndex)
{
  return (ARecordIndex == 0);
}
//---------------------------------------------------------------------------

Variant __fastcall TEditNeotomaTaxaDataSource::GetValue(void * ARecordHandle, void * AItemHandle)
{
  // displays value in grid based on stored data
  int AColumnId = GetDefaultItemID((int)AItemHandle);
  vector<NTMTAXONREC>::pointer TaxonPtr = FEditNeotomaTaxa->Taxon[(int)ARecordHandle];
  Variant Result;

  switch (AColumnId) {
	case IndexOftxnID:
	  Result = TaxonPtr->TaxonID;
	  break;
	case IndexOftxnCode:
	  Result = TaxonPtr->TaxonCode;
	  break;
	case IndexOftxnName:
	  Result = TaxonPtr->TaxonName;
	  break;
	case IndexOftxnAuthor:
	  Result = TaxonPtr->Author;
	  break;
	case IndexOftxnHigherID:
	  Result = TaxonPtr->HigherTaxonID;
	  break;
	case IndexOftxnExtinct:
	  Result = TaxonPtr->Extinct;
	  break;
	case IndexOftxnGroupID:
	  Result = TaxonPtr->TaxaGroupID;
	  break;
	case IndexOftxnPubID:
	  Result = TaxonPtr->PublicationID;
	  break;
	case IndexOftxnNotes:
	  Result = TaxonPtr->Notes;
	  break;
	case IndexOftxnEcolGroup:
	  if (TaxonPtr->EcolSetsGroups.size() > 0) {
		UnicodeString Text;
		map<UnicodeString,UnicodeString>::iterator itr;
		map<UnicodeString,UnicodeString>::iterator begin = TaxonPtr->EcolSetsGroups.begin();
		map<UnicodeString,UnicodeString>::iterator end = TaxonPtr->EcolSetsGroups.end();
		map<int,UnicodeString> SetGroup;
		for (itr = begin; itr != end; itr++) {
		  int EcolSetID = GetEcolSetID(itr->first);
		  if (EcolSetID > -1)
			SetGroup[EcolSetID] = itr->second;
		  }
		map<int,UnicodeString>::iterator it;
		for (it = SetGroup.begin(); it != SetGroup.end(); it++) {
		  if (!Text.IsEmpty()) Text += L";";
		  Text += IntToStr(it->first);
		  Text += L":";
		  Text += it->second;
		  }
		Result = Text;
		}
	  break;
	case IndexOftxnValidator:
	  Result = TaxonPtr->ValidatorID;
	  break;
	case IndexOftxnValidDate:
	  Result = TaxonPtr->ValidateDate;
	  break;
    }
  return (Result);
}
//---------------------------------------------------------------------------

void __fastcall TEditNeotomaTaxaDataSource::SetValue(void * ARecordHandle, void * AItemHandle, const Variant &AValue)
{
  // gets values from grid and stores them
  UnicodeString Value;

  int AColumnId = GetDefaultItemID((int)AItemHandle);
  vector<NTMTAXONREC>::pointer TaxonPtr = FEditNeotomaTaxa->Taxon[(int)ARecordHandle];

  switch (AColumnId) {
	case IndexOftxnID:
	  if (AValue.IsNull())
		TaxonPtr->TaxonID = Unassigned();
	  else
		TaxonPtr->TaxonID = AValue;
	  break;
	case IndexOftxnCode:
	  //TaxonPtr->TaxonCode = VarToStr(AValue);
	  break;
	case IndexOftxnName:
	  TaxonPtr->TaxonName = VarToStr(AValue);
	  break;
	case IndexOftxnAuthor:
	  TaxonPtr->Author = VarToStr(AValue);
	  break;
	case IndexOftxnHigherID:
	  if (AValue.IsNull())
		TaxonPtr->HigherTaxonID = Unassigned();
	  else
		TaxonPtr->HigherTaxonID = AValue;
	  break;
	case IndexOftxnExtinct:
	  TaxonPtr->Extinct = (AValue.IsNull()) ? false : AValue;
	  break;
	case IndexOftxnGroupID:
	  TaxonPtr->TaxaGroupID = VarToStr(AValue);
	  break;
	case IndexOftxnPubID:
	  break;
	case IndexOftxnNotes:
	  TaxonPtr->Notes = VarToStr(AValue);
	  break;
	case IndexOftxnEcolGroup:
	  break;
	case IndexOftxnValidator:
	  if (AValue.IsNull())
		TaxonPtr->ValidatorID = Unassigned();
	  else
		TaxonPtr->ValidatorID = AValue;
	  break;
	case IndexOftxnValidDate:
	  if (AValue.IsNull())
		TaxonPtr->ValidateDate = Unassigned();
	  else
		TaxonPtr->ValidateDate = AValue;
	  break;
  }
}
//---------------------------------------------------------------------------

int __fastcall TEditNeotomaSynonymDataSource::GetRecordCount(void)
{
  int Result = 0;
  if (GetMasterRecordIndex() >= 0) {
	NTMTAXONREC& Taxon = MasterDataSource->EditNeotomaTaxa->Taxa[GetMasterRecordIndex()];
	Result = Taxon.Synonyms.size();
	}
  return (Result);
}
//---------------------------------------------------------------------------

void * __fastcall TEditNeotomaSynonymDataSource::AppendRecord(void)
{
  NTMTAXONREC& Taxon = MasterDataSource->EditNeotomaTaxa->Taxa[GetMasterRecordIndex()];
  NTMSYNONYMREC Synonym;
  Taxon.Synonyms.push_back(Synonym);
  void* Result = (void*)(Taxon.Synonyms.size() - 1);
  DataChanged();
  return (Result);
}
//---------------------------------------------------------------------------

void __fastcall TEditNeotomaSynonymDataSource::DeleteRecord(void * ARecordHandle)
{
  NTMTAXONREC& Taxon = MasterDataSource->EditNeotomaTaxa->Taxa[GetMasterRecordIndex()];
  vector<NTMSYNONYMREC>::iterator itr = Taxon.Synonyms.begin() + (int)ARecordHandle;
  Taxon.Synonyms.erase(itr);
  DataChanged();
}
//---------------------------------------------------------------------------
/*
//const int IndexOfsyID         = 0;
//const int IndexOfsyCode       = 1;
//const int IndexOfsyName       = 2;
//const int IndexOfsyAuthor     = 3;
//const int IndexOfsySynTypeID  = 4;
//const int IndexOfsyExtinct    = 5;
//const int IndexOfsyGroupID    = 6;
//const int IndexOfsyPubID      = 7;
const int IndexOfsyNotes      = 8;
const int IndexOfsyValidator  = 9;
const int IndexOfsyValidDate  = 10;

//Variant TaxonID;
//UnicodeString TaxonCode;
//UnicodeString TaxonName;
//UnicodeString Author;
//Variant SynonymTypeID;
//bool Extinct;
//UnicodeString TaxaGroupID;
//Variant PublicationID;
UnicodeString Notes;
Variant ValidatorID;
UnicodeString ValidateDate;
*/
Variant __fastcall TEditNeotomaSynonymDataSource::GetValue(void * ARecordHandle, void * AItemHandle)
{
  int AColumnId = GetDefaultItemID(int(AItemHandle));

  NTMTAXONREC& Taxon = MasterDataSource->EditNeotomaTaxa->Taxa[GetMasterRecordIndex()];
  NTMSYNONYMREC* Synonym = &Taxon.Synonyms[(int)ARecordHandle];

  Variant Result;
  switch (AColumnId) {
	case IndexOfsyID:
	  Result = Synonym->TaxonID;
	  break;
	case IndexOfsyCode:
	  Result = Synonym->TaxonCode;
	  break;
	case IndexOfsyName:
	  Result = Synonym->TaxonName;
	  break;
	case IndexOfsyAuthor:
	  Result = Synonym->Author;
	  break;
	case IndexOfsySynTypeID:
	  Result = Synonym->SynonymTypeID;
	  break;
	case IndexOfsyExtinct:
	  Result = Synonym->Extinct;
	  break;
	case IndexOfsyGroupID:
	  Result = Synonym->TaxaGroupID;
	  break;
	case IndexOfsyPubID:
	  Result = Synonym->PublicationID;
	  break;
	case IndexOfsyNotes:
	  Result = Synonym->Notes;
	  break;
	case IndexOfsyValidator:
	  Result = Synonym->ValidatorID;
	  break;
	case IndexOfsyValidDate:
	  Result = Synonym->ValidateDate;
	  break;
    }
  return (Result);
}
//---------------------------------------------------------------------------

void __fastcall TEditNeotomaSynonymDataSource::SetValue(void * ARecordHandle, void * AItemHandle, const Variant &AValue)
{
  int AColumnId = GetDefaultItemID((int)AItemHandle);

  int Index = GetMasterRecordIndex();

  NTMTAXONREC& Taxon = MasterDataSource->EditNeotomaTaxa->Taxa[Index];
  NTMSYNONYMREC *Synonym = &Taxon.Synonyms[(int)ARecordHandle];

  switch (AColumnId) {
	case IndexOfsyID:
	  if (AValue.IsNull())
		Synonym->TaxonID = Unassigned();
	  else
		Synonym->TaxonID = AValue;
	  break;
	case IndexOfsyCode:
	  Synonym->TaxonCode = VarToStr(AValue);
	  break;
	case IndexOfsyName:
	  Synonym->TaxonName = VarToStr(AValue);
	  break;
	case IndexOfsyAuthor:
	  Synonym->Author = VarToStr(AValue);
	  break;
	case IndexOfsySynTypeID:
	  if (AValue.IsNull())
		Synonym->SynonymTypeID = Unassigned();
	  else
		Synonym->SynonymTypeID = AValue;
	  break;
	case IndexOfsyExtinct:
	  Synonym->Extinct = (AValue.IsNull()) ? false : AValue;
	  break;
	case IndexOfsyGroupID:
	  if (AValue.IsNull())
		Synonym->TaxaGroupID = Unassigned();
	  else
		Synonym->TaxaGroupID = VarToStr(AValue);
	  break;
	case IndexOfsyPubID:
	  break;
	case IndexOfsyNotes:
	  Synonym->Notes = VarToStr(AValue);
	  break;
	case IndexOfsyValidator:
	  if (AValue.IsNull())
		Synonym->ValidatorID = Unassigned();
	  else
		Synonym->ValidatorID = AValue;
	  break;
	case IndexOfsyValidDate:
	  if (AValue.IsNull())
		Synonym->ValidateDate = Unassigned();
	  else
		Synonym->ValidateDate = AValue;
	  break;
    }
}
//---------------------------------------------------------------------------

int TEditNeotomaSynonymDataSource::GetMasterRecordIndex()
{
  return (DataController->GetMasterRecordIndex());
}
//---------------------------------------------------------------------------

__fastcall TNewTaxonForm::TNewTaxonForm(TComponent* Owner) : TForm(Owner)
{
   from_ss = true;
   EditingLocked = true;
   Activated = false;
   loading_taxa = false;
   dbTaxonAction = dbaUPLOAD;
   MarkedTaxonID = 0;
   MarkedNode = NULL;
   Row2 = 2;
   //SynonymView = NULL;
   Panel5->Width = 350;

   UnicodeString ClassName = Owner->ClassName();
   if (SameText(ClassName, L"TNeotomaFindTaxonForm")) {
	 NtmFindTaxForm = (TNeotomaFindTaxonForm*)Owner;
	 }

   TaxonIDPtrs = new TList;
   EcolSetGroup = NULL;

   if (!Login->IsTaxonomyExpert) {
	 txnValidator->Visible = false;
	 txnValidDate->Visible = false;
	 syValidator->Visible = false;
	 syValidDate->Visible = false;
	 cxButton9->Visible = false;
	 PopupMenu1->AutoPopup = false;
	 cxButton17->Visible = false;
	 }

   EditNeotomaTaxa = new TEditNeotomaTaxa();
   TaxaDataSource = new TEditNeotomaTaxaDataSource(EditNeotomaTaxa, &EcolSetTypes);
   SynonymDataSource = new TEditNeotomaSynonymDataSource(TaxaDataSource);
   GenerateTaxonColumns();
   NTMTAXONREC Taxon;
   EditNeotomaTaxa->Add(Taxon);
   if (!Login->IsTaxonomyExpert)  // hide button to make new SynonymType
	 cxButton10->Visible = false;

   //AdvMultiColumnDropDown1->
}
//---------------------------------------------------------------------------

void TNewTaxonForm::SetCellStyle(int RecordIndex, TcxStyle *&AStyle)
{
   int StyleNo;
   switch (RecordIndex) {
	 case 0:
	   StyleNo = (EditingLocked) ? 0 : 1;
	   break;
	 case 1:
	   StyleNo = (EditingLocked) ? 1 : 0;
	   break;
	 }
   AStyle = (TcxStyle*)cxStyleRepository1->Items[StyleNo];
}
//---------------------------------------------------------------------------

void __fastcall TNewTaxonForm::txnCodeStylesGetContentStyle(TcxCustomGridTableView *Sender,
		  TcxCustomGridRecord *ARecord, TcxCustomGridTableItem *AItem,
		  TcxStyle *&AStyle)
{
   SetCellStyle(ARecord->RecordIndex, AStyle);
}
//---------------------------------------------------------------------------

void __fastcall TNewTaxonForm::txnNameStylesGetContentStyle(TcxCustomGridTableView *Sender,
		  TcxCustomGridRecord *ARecord, TcxCustomGridTableItem *AItem,
		  TcxStyle *&AStyle)
{
   if (ARecord->RecordIndex == 0) {
	 int StyleNo = (EditingLocked) ? 0 : 1;
	 AStyle = (TcxStyle*)cxStyleRepository1->Items[StyleNo];
	 }
}
//---------------------------------------------------------------------------

void __fastcall TNewTaxonForm::txnAuthorStylesGetContentStyle(TcxCustomGridTableView *Sender,
		  TcxCustomGridRecord *ARecord, TcxCustomGridTableItem *AItem,
		  TcxStyle *&AStyle)
{
   SetCellStyle(ARecord->RecordIndex, AStyle);
}
//---------------------------------------------------------------------------

void __fastcall TNewTaxonForm::txnExtinctStylesGetContentStyle(TcxCustomGridTableView *Sender,
		  TcxCustomGridRecord *ARecord, TcxCustomGridTableItem *AItem,
		  TcxStyle *&AStyle)
{
   SetCellStyle(ARecord->RecordIndex, AStyle);
}
//---------------------------------------------------------------------------

void __fastcall TNewTaxonForm::txnPubIDStylesGetContentStyle(TcxCustomGridTableView *Sender,
		  TcxCustomGridRecord *ARecord, TcxCustomGridTableItem *AItem,
		  TcxStyle *&AStyle)
{
   SetCellStyle(ARecord->RecordIndex, AStyle);
}
//---------------------------------------------------------------------------

void __fastcall TNewTaxonForm::txnNotesStylesGetContentStyle(TcxCustomGridTableView *Sender,
		  TcxCustomGridRecord *ARecord, TcxCustomGridTableItem *AItem,
		  TcxStyle *&AStyle)
{
   SetCellStyle(ARecord->RecordIndex, AStyle);
}
//---------------------------------------------------------------------------

void __fastcall TNewTaxonForm::txnEcolGroupStylesGetContentStyle(TcxCustomGridTableView *Sender,
		  TcxCustomGridRecord *ARecord, TcxCustomGridTableItem *AItem,
		  TcxStyle *&AStyle)
{
   SetCellStyle(ARecord->RecordIndex, AStyle);
}
//---------------------------------------------------------------------------

void __fastcall TNewTaxonForm::syCodeStylesGetContentStyle(TcxCustomGridTableView *Sender,
		  TcxCustomGridRecord *ARecord, TcxCustomGridTableItem *AItem,
		  TcxStyle *&AStyle)
{
   int StyleNo = (EditingLocked) ? 0 : 1;
   AStyle = (TcxStyle*)cxStyleRepository1->Items[StyleNo];
}
//---------------------------------------------------------------------------

void __fastcall TNewTaxonForm::syNameStylesGetContentStyle(TcxCustomGridTableView *Sender,
          TcxCustomGridRecord *ARecord, TcxCustomGridTableItem *AItem,
          TcxStyle *&AStyle)
{
   int StyleNo = (EditingLocked) ? 0 : 1;
   AStyle = (TcxStyle*)cxStyleRepository1->Items[StyleNo];
}
//---------------------------------------------------------------------------

void __fastcall TNewTaxonForm::syAuthorStylesGetContentStyle(TcxCustomGridTableView *Sender,
          TcxCustomGridRecord *ARecord, TcxCustomGridTableItem *AItem,
          TcxStyle *&AStyle)
{
   int StyleNo = (EditingLocked) ? 0 : 1;
   AStyle = (TcxStyle*)cxStyleRepository1->Items[StyleNo];
}
//---------------------------------------------------------------------------

void __fastcall TNewTaxonForm::sySynTypeIDStylesGetContentStyle(TcxCustomGridTableView *Sender,
          TcxCustomGridRecord *ARecord, TcxCustomGridTableItem *AItem,
          TcxStyle *&AStyle)
{
   int StyleNo = (EditingLocked) ? 0 : 1;
   AStyle = (TcxStyle*)cxStyleRepository1->Items[StyleNo];
}
//---------------------------------------------------------------------------

void __fastcall TNewTaxonForm::syExtinctStylesGetContentStyle(TcxCustomGridTableView *Sender,
          TcxCustomGridRecord *ARecord, TcxCustomGridTableItem *AItem,
          TcxStyle *&AStyle)
{
   int StyleNo = (EditingLocked) ? 0 : 1;
   AStyle = (TcxStyle*)cxStyleRepository1->Items[StyleNo];
}
//---------------------------------------------------------------------------

void __fastcall TNewTaxonForm::syPubIDStylesGetContentStyle(TcxCustomGridTableView *Sender,
          TcxCustomGridRecord *ARecord, TcxCustomGridTableItem *AItem,
          TcxStyle *&AStyle)
{
   int StyleNo = (EditingLocked) ? 0 : 1;
   AStyle = (TcxStyle*)cxStyleRepository1->Items[StyleNo];
}
//---------------------------------------------------------------------------

void __fastcall TNewTaxonForm::syNotesStylesGetContentStyle(TcxCustomGridTableView *Sender,
          TcxCustomGridRecord *ARecord, TcxCustomGridTableItem *AItem,
          TcxStyle *&AStyle)
{
   int StyleNo = (EditingLocked) ? 0 : 1;
   AStyle = (TcxStyle*)cxStyleRepository1->Items[StyleNo];
}
//---------------------------------------------------------------------------

void __fastcall TNewTaxonForm::cxGrid1TableView1Editing(TcxCustomGridTableView *Sender,
		  TcxCustomGridTableItem *AItem, bool &AAllow)
{
   switch (AItem->Index) {
	 case 1:   // Code
	 case 3:   // Author
	 case 5:   // Extinct
	 case 7:   // PubID
	 case 8:   // Notes
	 case 9:   // EcolGroup
	   switch (Sender->DataController->FocusedRecordIndex) {
		 case 0:
		   AAllow = !EditingLocked;
		   break;
		 case 1:
		   AAllow = EditingLocked;
		   break;
		 }
	   break;
	 case 2:   // Name
	   switch (Sender->DataController->FocusedRecordIndex) {
		 case 0:
		   AAllow = !EditingLocked;
		   break;
		 case 1:
		   AAllow = false;
		   break;
		 }
	   break;
	 default:
	   AAllow = false;
	   break;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TNewTaxonForm::cxGrid1TableView2Editing(TcxCustomGridTableView *Sender,
		  TcxCustomGridTableItem *AItem, bool &AAllow)
{
   switch (AItem->Index) {
	 case 1:   // Code
	 case 2:   // Name
	 case 3:   // Author
	 case 4:   // SynType
	 case 5:   // Extinct
	 case 7:   // PubID
	 case 8:   // Notes
	   AAllow = !EditingLocked;
	   break;
	 default:
	   AAllow = false;
	   break;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TNewTaxonForm::FormDestroy(TObject *Sender)
{
   ClearTaxonIDPtrs();
   delete TaxonIDPtrs;
   if (EcolSetGroup != NULL)
	 delete EcolSetGroup;
   delete EditNeotomaTaxa;
   delete TaxaDataSource;
   delete SynonymDataSource;
}
//---------------------------------------------------------------------------

void __fastcall TNewTaxonForm::FormActivate(TObject *Sender)
{
   if (Activated)
	 return;
   else
     Activated = true;
   AllowReactivate = false;
   Panel8->Enabled = true;
   Panel9->Enabled = true;
   if (dxTreeView1->Items->Count > 0) {
	 //Label1->Visible = true;
	 //cxComboBox1->Visible = true;
	 //cxButton2->Visible = true;
	 Panel3->Visible = true;
	 }
   TaxaUploaded.clear();
   if (AdvMultiColumnDropDown1->Items->Count == 0) {
	 if (!GetTaxaGroups()) {
	   MessageDlg(L"Error accessing Neotoma GetTaxaGroupTypes web service.", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   Close();
	   }
	 }
}
//---------------------------------------------------------------------------

void __fastcall TNewTaxonForm::GenerateTaxonColumns()
{
   txnID->DataBinding->Data = (TObject*)IndexOftxnID;
   txnCode->DataBinding->Data = (TObject*)IndexOftxnCode;
   txnName->DataBinding->Data = (TObject*)IndexOftxnName;
   txnAuthor->DataBinding->Data = (TObject*)IndexOftxnAuthor;
   txnHigherID->DataBinding->Data = (TObject*)IndexOftxnHigherID;
   txnExtinct->DataBinding->Data = (TObject*)IndexOftxnExtinct;
   txnGroupID->DataBinding->Data = (TObject*)IndexOftxnGroupID;
   txnPubID->DataBinding->Data = (TObject*)IndexOftxnPubID;
   txnNotes->DataBinding->Data = (TObject*)IndexOftxnNotes;
   txnEcolGroup->DataBinding->Data = (TObject*)IndexOftxnEcolGroup;
   txnValidator->DataBinding->Data = (TObject*)IndexOftxnValidator;
   txnValidDate->DataBinding->Data = (TObject*)IndexOftxnValidDate;
   // this line is critical
   cxGrid1TableView1->DataController->CustomDataSource = TaxaDataSource;

   syID->DataBinding->Data = (TObject*)IndexOfsyID;
   syCode->DataBinding->Data = (TObject*)IndexOfsyCode;
   syName->DataBinding->Data = (TObject*)IndexOfsyName;
   syAuthor->DataBinding->Data = (TObject*)IndexOfsyAuthor;
   sySynTypeID->DataBinding->Data = (TObject*)IndexOfsySynTypeID;
   syExtinct->DataBinding->Data = (TObject*)IndexOfsyExtinct;
   syGroupID->DataBinding->Data = (TObject*)IndexOfsyGroupID;
   syPubID->DataBinding->Data = (TObject*)IndexOfsyPubID;
   syNotes->DataBinding->Data = (TObject*)IndexOfsyNotes;
   syValidator->DataBinding->Data = (TObject*)IndexOfsyValidator;
   syValidDate->DataBinding->Data = (TObject*)IndexOfsyValidDate;

   // this line is critical
   cxGrid1TableView2->DataController->CustomDataSource = SynonymDataSource;
}
//---------------------------------------------------------------------------

TcxGridTableView* TNewTaxonForm::SynonymGridView(int idx1)
{
   return (TcxGridTableView*)cxGrid1TableView1->DataController->GetDetailDataController(idx1,0)->GetOwner();
}
//---------------------------------------------------------------------------

TcxGridTableView* TNewTaxonForm::SynonymGridView(void)
{
   int idx1 = cxGrid1TableView1->Controller->FocusedRecordIndex;
   return (TcxGridTableView*)cxGrid1TableView1->DataController->GetDetailDataController(idx1,0)->GetOwner();
}
//---------------------------------------------------------------------------

TcxCustomDataController* TNewTaxonForm::SynonymDataController(int idx1)
{
   return cxGrid1TableView1->DataController->GetDetailDataController(idx1,0);
}
//---------------------------------------------------------------------------

TcxCustomDataController* TNewTaxonForm::SynonymDataController(void)
{
   int idx1 = cxGrid1TableView1->Controller->FocusedRecordIndex;
   return cxGrid1TableView1->DataController->GetDetailDataController(idx1,0);
}
//---------------------------------------------------------------------------


bool TNewTaxonForm::GetTaxaGroups(void)
{
   bool rv = false;

   NeotomaTaxaGroupTypesTable TaxaGroupTypes(ipsJSONS1, TcpClient1);
   StatusBar1->SimpleText = TaxaGroupTypes.WebServiceName();
   Screen->Cursor = crHourGlass;
   if (TaxaGroupTypes.Execute()) {
	 map<UnicodeString, UnicodeString>::iterator itr;
	 map<UnicodeString, UnicodeString>::iterator begin = TaxaGroupTypes.Items.begin();
	 map<UnicodeString, UnicodeString>::iterator end = TaxaGroupTypes.Items.end();
	 for (itr = begin; itr != end; itr++) {
	   Advmulticolumndropdown::TDropDownItem *Item;
	   Item = AdvMultiColumnDropDown1->Items->Add();
	   Item->Text->Add(itr->first);
	   Item->Text->Add(itr->second);
	   }
	 rv = true;
	 }
   StatusBar1->SimpleText = L"";
   Screen->Cursor = crDefault;
   return rv;
}
//---------------------------------------------------------------------------

void TNewTaxonForm::UpdateBuildTreeStatus(int level, int& n, int& inc)
{
   n++;
   inc--;
   if (inc == 0) {
	 StatusBar1->SimpleText = L"Building Tree: Level " + IntToStr(level) +
	   L", Taxa Processed = " + IntToStr(n);
	 inc = 10;
	 }
}
//---------------------------------------------------------------------------

void TNewTaxonForm::BadHigherTaxonIDMsg(int HigherID, TAXONRECORD& TaxonRec)
{
   UnicodeString TaxonName = VarToStr(TaxonRec.TaxonName);
   int TaxonID = VariantToInt(TaxonRec.TaxonID, -1);

   UnicodeString msg = L"DATABASE ERROR: HigherTaxonID " + IntToStr(HigherID) +
	 L" for «" + TaxonName + L"» (TaxonID = " + IntToStr(TaxonID) +
	 L") is not a valid TaxonID.";
   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
}
//---------------------------------------------------------------------------

bool TNewTaxonForm::GetTaxa(vector<WSPARAMETER>& Parameters, NeotomaTaxaBase& Taxa)
{
   bool rv = true;

   if (Parameters.size() > 0) {
	 for (unsigned int i=0; i<Parameters.size(); i++)
	   Taxa.AddParam(Parameters[i].Name, Parameters[i].Value);
	 }

   StatusBar1->SimpleText = Taxa.WebServiceName();
   if (Taxa.Execute()) {
	 if (Taxa.Size() > 0) {
	   for (unsigned int i=0; i<Taxa.Size(); i++) {
		 NTMTAXONMAP Taxon;
		 TaxaRecordToMap(Taxa.Items[i], Taxon);
		 int TaxonID = VariantToInt(Taxa.Items[i].TaxonID, -1);
		 if (Taxon.Valid)
		   TaxaMap.insert(pair<int, NTMTAXONMAP>(TaxonID, Taxon));
		 TaxaNameIndex.insert(pair<UnicodeString,int>(Taxon.TaxonName,TaxonID));
		 TaxaCodeIndex.insert(pair<UnicodeString,int>(Taxon.TaxonCode,TaxonID));
		 }
	   }
	 else {
	   StatusBar1->SimpleText = L"No taxa found";
	   }
	 }
   else
	 rv = false;

   StatusBar1->SimpleText = L"";
   return rv;
}
//---------------------------------------------------------------------------

void TNewTaxonForm::TaxaRecordToMap(TAXONRECORD& tr, NTMTAXONMAP& tm)
{
   tm.TaxonCode = VarToStr(tr.TaxonCode);
   tm.TaxonName = VarToStr(tr.TaxonName);
   tm.Author = VarToStr(tr.Author);
   tm.Valid = VariantToBool(tr.Valid, false);
   tm.HigherTaxonID = tr.HigherTaxonID;
   tm.Extinct = tr.Extinct;
   tm.TaxaGroupID = VarToStr(tr.TaxaGroupID);
   tm.PublicationID = tr.PublicationID;
   tm.ValidatorID = tr.ValidatorID;
   tm.ValidateDate = tr.ValidateDate;
   tm.Notes = VarToStr(tr.Notes);
}
//---------------------------------------------------------------------------

void TNewTaxonForm::ClearTaxonIDPtrs(void)
{
   if (TaxonIDPtrs->Count > 0) {
	 for (int i=0; i<TaxonIDPtrs->Count; i++) {
	   int* TaxonID = (int*)TaxonIDPtrs->Items[i];
	   delete TaxonID;
	   TaxonIDPtrs->Items[i] = 0;
	   }
	 TaxonIDPtrs->Clear();
	 }
}
//---------------------------------------------------------------------------

void __fastcall TNewTaxonForm::AdvMultiColumnDropDown1Select(TObject *Sender)
{
   PleaseWaitStart(L"Please Wait");
   Screen->Cursor = crHourGlass;
   UnvalidatedTaxa.clear();
   cxButton17->Hint = L"Show unvalidated taxa";
   GetTaxaFromNeotoma();
   Screen->Cursor = crDefault;
   Timer1->Enabled = false;
   PleaseWaitGroupBox->Visible = false;
}
//---------------------------------------------------------------------------

void TNewTaxonForm::PleaseWaitStart(UnicodeString Caption)
{
   PleaseWaitGroupBox->Width = 300;
   PleaseWaitGroupBox->Height = 133;
   PleaseWaitGroupBox->Left = (Width-300)/2;
   PleaseWaitGroupBox->Top = (Height-133)/2 - 40;
   cxLabel3->Caption = Caption;
   cxLabel3->AutoSize = true;
   cxLabel3->Left = (300-cxLabel3->Width)/2;
   cxLabel3->Top = (133-cxLabel3->Height)/2;
   RatStart = 0;
   RatEnd = 300-Image1->Width;
   RatPos = 0;
   PleaseWaitGroupBox->Visible = true;
   Timer1->Enabled = true;
}
//---------------------------------------------------------------------------

void TNewTaxonForm::PleaseWaitEnd(void)
{
   Timer1->Enabled = false;
   PleaseWaitGroupBox->Visible = false;
}
//---------------------------------------------------------------------------

void TNewTaxonForm::GetTaxaFromNeotoma(void)
{
   map<int,NTMTAXONMAP>::iterator itr;
   map<int,NTMTAXONMAP>::iterator begin;
   map<int,NTMTAXONMAP>::iterator end;
   map<int,TTreeNode*> ExistingNodes;

   if (dxTreeView1->Items->Count > 0) {
	 PleaseWaitGroupBox->Visible = false;
	 TAddAppendTaxaGroupQuery* Query = new TAddAppendTaxaGroupQuery(this);
	 int rv = Query->ShowModal();
	 delete Query;
	 switch (rv) {
	   case mrReplace:
		 loading_taxa = true;
		 dxTreeView1->Items->Clear();
		 TaxaMap.clear();
		 SynonymMap.clear();
		 TaxaNameIndex.clear();
		 TaxaCodeIndex.clear();
		 NewTaxonID = 0;
		 ClearTaxonIDPtrs();
		 break;
	   case mrAdd:
	     loading_taxa = true;
         if (dxTreeView1->Items->Count > 0) {
		   for (int i=0; i<dxTreeView1->Items->Count; i++) {
			 TTreeNode* Node = dxTreeView1->Items->Item[i];
			 int TaxonID = *((int*)Node->Data);
			 ExistingNodes[TaxonID] = Node;
			 }
		   }
		 break;
	   case mrCancel:
		 return;
	   }
	 PleaseWaitGroupBox->Visible = true;
	 }

   vector<WSPARAMETER> Params1;
   int ItemIndex = AdvMultiColumnDropDown1->ItemIndex;
   UnicodeString TaxaGroupID = AdvMultiColumnDropDown1->Items->Items[ItemIndex]->Text->Strings[0];

   // ShowMessage(TaxaGroupID);

   WSPARAMETER Param1(L"TAXAGROUPID", TaxaGroupID);
   Params1.push_back(Param1);

   NeotomaValidTaxaByTaxaGroupID TaxaByGroup(ipsJSONS1, TcpClient1);
   if (!GetTaxa(Params1, (NeotomaTaxaBase&)TaxaByGroup))
	 return;

   map<int,int> HigherIDs;
   // add any taxa with HigherID's outside the current list
   // first, get map of all HigherID's and which taxon first found with
   for (unsigned int i=0; i<TaxaByGroup.Size(); i++) {
	 int HigherID = VariantToInt(TaxaByGroup.Items[i].HigherTaxonID, -1);
	 if (HigherID == -1) {
	   BadHigherTaxonIDMsg(HigherID, TaxaByGroup.Items[i]);
	   return;
	   }
	 else if (HigherIDs.count(HigherID) == 0)
	   HigherIDs[HigherID] = i;
	 }

   // iterate through HigherID's, find any not in TaxaByGroup, and crawl to top of tree
   map<int,int>::iterator it;
   for (it = HigherIDs.begin(); it != HigherIDs.end(); it++) {
	 int HigherID = it->first;
	 if (TaxaByGroup.FindID(HigherID) == NULL) {
	   int TaxonID;
	   do {
		  vector<WSPARAMETER> Params2;
		  WSPARAMETER Param2(L"TAXONID", IntToStr(HigherID));
		  Params2.push_back(Param2);
		  NeotomaTaxonByID TaxaByID(ipsJSONS1, TcpClient1);
		  if (!GetTaxa(Params2, (NeotomaTaxaBase&)TaxaByID))
		   return;
		  if (TaxaByID.Size() == 0) {
			BadHigherTaxonIDMsg(HigherID, TaxaByGroup.Items[it->second]);
			return;
			}
		  TaxonID = VariantToInt(TaxaByID.Items[0].TaxonID, -1);
		  HigherID = VariantToInt(TaxaByID.Items[0].HigherTaxonID, -1);
		  if (HigherID == -1) {
			BadHigherTaxonIDMsg(HigherID, TaxaByGroup.Items[it->second]);
			return;
			}
		  } while (HigherID != TaxonID);
	   }
	 }

   dxTreeView1->Items->BeginUpdate();
   cxComboBox1->Properties->Items->BeginUpdate();
   cxComboBox1->Properties->Items->Clear();

   begin = TaxaMap.begin();
   end = TaxaMap.end();

   map<int, TTreeNode*> InTree;
   map<int, TTreeNode*> Level1;
   map<int, TTreeNode*> Level2;

   TTreeNode* Node = NULL;
   StatusBar1->SimpleText = L"Building Tree: Level 1";
   int n = 0;
   int inc = 10;
   int level = 1;
   for (itr = begin; itr != end; itr++) {
	 int TaxonID = itr->first;
	 int HigherTaxonID = VariantToInt(itr->second.HigherTaxonID, -1);
	 if (TaxonID == HigherTaxonID) {
	   map<int,TTreeNode*>::iterator it;
	   if ((it = ExistingNodes.find(itr->first)) != ExistingNodes.end()) {
		 InTree[TaxonID] = it->second;
		 Level1[TaxonID] = it->second;
		 }
	   else {
		 int *TaxonIDPtr = new int;
		 *TaxonIDPtr = TaxonID;
		 TaxonIDPtrs->Add(TaxonIDPtr);
		 Node = dxTreeView1->Items->AddObject(Node, itr->second.TaxonName, TaxonIDPtr);
		 cxComboBox1->Properties->Items->Add(itr->second.TaxonName);
		 UpdateBuildTreeStatus(level, n, inc);
		 InTree[TaxonID] = Node;
		 Level1[TaxonID] = Node;
		 }
	   }
	 }

   // build rest of levels
   map<int, TTreeNode*>::iterator itr1;
   while (InTree.size() < TaxaMap.size()) {
	 level++;
	 if (level == 100) {  // hit an infinite loop
	   map<int,NTMTAXONMAP>::iterator itr;
	   map<int,NTMTAXONMAP>::iterator begin = TaxaMap.begin();
	   map<int,NTMTAXONMAP>::iterator end = TaxaMap.end();
	   for (itr = begin; itr != end; itr++) {
		 if (InTree.find(itr->first) == InTree.end()) {
		   UnicodeString msg = L"Error in the Neotoma taxonomic hierarchy.";
		   msg += ("\nHigherTaxonID is invalid or nonexistent.\nTaxonID = " +
			 IntToStr(itr->first) + L", " + itr->second.TaxonName +
			 L".\nContact the database administrators.");
		   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   }
	     }
	   break;
	   }
	 for (itr = begin; itr != end; itr++) {
	   int TaxonID = itr->first;
	   map<int,TTreeNode*>::iterator it;
	   if ((it = ExistingNodes.find(itr->first)) != ExistingNodes.end()) {
		 InTree[TaxonID] = it->second;
		 Level2[TaxonID] = it->second;
		 }
	   else {
		 int HigherID = VariantToInt(itr->second.HigherTaxonID, -1);
		 if (InTree.find(TaxonID) == InTree.end()) {  // TaxonID not yet in tree
		   itr1 = Level1.find(HigherID);
		   if (itr1 != Level1.end()) {                // HigherID is in last level
			 int *TaxonIDPtr = new int;
			 *TaxonIDPtr = TaxonID;
			 TaxonIDPtrs->Add(TaxonIDPtr);
			 Node = dxTreeView1->Items->AddChildObject(itr1->second, itr->second.TaxonName, TaxonIDPtr);
			 cxComboBox1->Properties->Items->Add(itr->second.TaxonName);
			 UpdateBuildTreeStatus(level, n, inc);
			 InTree[TaxonID] = Node;
			 Level2[TaxonID] = Node;
			 }
		   }
		 }
	   }

	 Level1.clear();
	 Level1.insert(Level2.begin(), Level2.end());
	 Level2.clear();
	 }
   inc = 1;
   UpdateBuildTreeStatus(level, n, inc);
   dxTreeView1->AlphaSort();

   // get synonyms for lookup
   NeotomaLookupSynonym Synonyms(ipsJSONS1, TcpClient1);
   Synonyms.AddParam(L"TAXAGROUPLIST", TaxaGroupID);
   StatusBar1->SimpleText = Synonyms.WebServiceName();
   if (Synonyms.Execute()) {
	 if (Synonyms.Size() > 0) {
	   for (unsigned int i=0; i<Synonyms.Size(); i++) {
		 SynonymMap[Synonyms.Items[i].TaxonName] = Synonyms.Items[i].ValidTaxonID;
		 cxComboBox1->Properties->Items->Add(Synonyms.Items[i].TaxonName);
		 }
	   }
	 }

   cxComboBox1->Properties->Sorted = true;
   cxComboBox1->Properties->Items->EndUpdate();
   dxTreeView1->Items->EndUpdate();

   Panel3->Visible = true;

   // get EcolSetTypesTable
   NeotomaEcolSetTypesTable EcolSetTypesTable(ipsJSONS1, TcpClient1);
   StatusBar1->SimpleText = EcolSetTypesTable.WebServiceName();
   if (EcolSetTypesTable.Execute())
	 EcolSetTypes = EcolSetTypesTable.Items;

   NeotomaEcolGroupTypesTable EcolGroupTypesTable(ipsJSONS1, TcpClient1);
   StatusBar1->SimpleText = EcolGroupTypesTable.WebServiceName();
   if (EcolGroupTypesTable.Execute())
	 EcolGroupTypes = EcolGroupTypesTable.Items;

   StatusBar1->SimpleText = L"";
   loading_taxa = false;
   dxTreeView1->SelectedIndex = 0;

   FocusControl(dxTreeView1);
}
//---------------------------------------------------------------------------

void __fastcall TNewTaxonForm::cxComboBox1PropertiesChange(TObject *Sender)
{
   cxButton2->Enabled = !cxComboBox1->Text.IsEmpty();
}
//---------------------------------------------------------------------------

void __fastcall TNewTaxonForm::cxButton2Click(TObject *Sender)
{
   Search(cxComboBox1->Text);
}
//---------------------------------------------------------------------------

void __fastcall TNewTaxonForm::cxComboBox1KeyPress(TObject *Sender, wchar_t &Key)
{
   if (Key == VK_RETURN)
	 Search(cxComboBox1->Text);
}
//---------------------------------------------------------------------------

void TNewTaxonForm::Search(UnicodeString SearchStr)
{
   // check if name is a synonym; if so, replace with valid taxon name
   map<UnicodeString,int>::iterator itr = SynonymMap.find(SearchStr);
   if (itr != SynonymMap.end())
	 SearchStr = TaxaMap[itr->second].TaxonName;

   for (int i=0; i<dxTreeView1->Items->Count; i++) {
	 TTreeNode* Node = dxTreeView1->Items->Item[i];
	 if (SameText(Node->Text, SearchStr)) {
	   Node->MakeVisible();
	   Node->Selected = true;
	   Node->Focused = true;
	   FocusControl(dxTreeView1);
	   break;
	   }
	 }
}
//---------------------------------------------------------------------------

void __fastcall TNewTaxonForm::dxTreeView1Change(TObject *Sender, TTreeNode *Node)
{
   if (Node == NULL) return;
   int TaxonID = *((int*)Node->Data);
   CurrentNode = Node;
   if (!loading_taxa && TaxonID > 0)
	 ShowTaxonMetaData(TaxonID);
}
//---------------------------------------------------------------------------

void TNewTaxonForm::GetEcolSetsGroups(UnicodeString EcolSetID, UnicodeString EcolSetName)
{
   NeotomaEcolGroupsByEcolSetID EcolGroups(ipsJSONS1, TcpClient1);
   EcolGroups.AddParam(L"ECOLSETID", EcolSetID);
   StatusBar1->SimpleText = EcolGroups.WebServiceName();
   if (EcolGroups.Execute()) {
	 if (EcolGroups.Size() > 0) {
	   //UnicodeString EcolSetName = EcolSetCounts.Items[i].EcolSetName;
	   vector<CODENAME> EcolGroupNames;
	   map<UnicodeString,UnicodeString>::iterator itr;
	   map<UnicodeString,UnicodeString>::iterator begin = EcolGroups.Items.begin();
	   map<UnicodeString,UnicodeString>::iterator end = EcolGroups.Items.end();
	   for (itr = begin; itr != end; itr++) {
		 CODENAME CodeName;
		 CodeName.Code = itr->first;
		 CodeName.Name = itr->second;
		 EcolGroupNames.push_back(CodeName);
		 }
	   EcolSetsGroups[EcolSetName] = EcolGroupNames;
	   }
	 }
}
//---------------------------------------------------------------------------

void TNewTaxonForm::ShowTaxonMetaData(int TaxonID)
{
   NewTaxonMetaData = false;
   if (Login->IsTaxonomyExpert)
	 cxButton9->Visible = true;

   Screen->Cursor = crHourGlass;
   NTMTAXONMAP *Taxon = &TaxaMap.find(TaxonID)->second;
   try {
   try {
   EditNeotomaTaxa->Taxa[0].TaxonID = TaxonID;
   EditNeotomaTaxa->Taxa[0].TaxonCode = Taxon->TaxonCode;
   EditNeotomaTaxa->Taxa[0].TaxonName = Taxon->TaxonName;
   EditNeotomaTaxa->Taxa[0].Author = Taxon->Author;
   EditNeotomaTaxa->Taxa[0].HigherTaxonID = Taxon->HigherTaxonID;
   EditNeotomaTaxa->Taxa[0].Extinct = Taxon->Extinct;
   EditNeotomaTaxa->Taxa[0].TaxaGroupID = Taxon->TaxaGroupID;
   EditNeotomaTaxa->Taxa[0].PublicationID = Taxon->PublicationID;
   EditNeotomaTaxa->Taxa[0].Notes = Taxon->Notes;
   cxComboBox2->Clear();
   cxComboBox2->Properties->Items->Clear();
   cxComboBox2->ItemIndex = -1;

   EditNeotomaTaxa->Taxa[0].EcolSetsGroups.clear();
   if (EcolSetGroup != NULL)
	 delete EcolSetGroup;
   EcolSetGroup = new NeotomaEcolSetsGroups(ipsJSONS1, TcpClient1);
   EcolSetGroup->AddParam(L"TAXONID", TaxonID);
   StatusBar1->SimpleText = EcolSetGroup->WebServiceName();
   if (EcolSetGroup->Execute()) {
	 if (EcolSetGroup->Size() > 0) {
	   for (unsigned int i=0; i<EcolSetGroup->Size(); i++) {
		 UnicodeString SetName = EcolSetGroup->Items[i].EcolSetName;
		 UnicodeString GroupID = EcolSetGroup->Items[i].EcolGroupID;
		 EditNeotomaTaxa->Taxa[0].EcolSetsGroups[SetName] = GroupID;
		 }
	   Taxon->EcolSetsGroups = EditNeotomaTaxa->Taxa[0].EcolSetsGroups;
	   }
	 }

   if (Login->IsTaxonomyExpert) {
	 EditNeotomaTaxa->Taxa[0].ValidatorID = Taxon->ValidatorID;
	 EditNeotomaTaxa->Taxa[0].ValidateDate = Taxon->ValidateDate;
	 }

   // Get Synonyms
   NeotomaSynonyms.clear();
   EditNeotomaTaxa->Taxa[0].Synonyms.clear();
   SynonymDataSource->DataChanged();
   NeotomaSynonymsForValidTaxonID *Synonyms = new NeotomaSynonymsForValidTaxonID(ipsJSONS1, TcpClient1);
   Synonyms->AddParam(L"VALIDTAXONID", TaxonID);
   StatusBar1->SimpleText = Synonyms->WebServiceName();
   if (Synonyms->Execute()) {
	 if (Synonyms->Size() > 0) {
	   for (unsigned int i=0; i<Synonyms->Size(); i++) {
		 NTMSYNONYMREC Synonym;
		 Synonym.TaxonID = Synonyms->Items[i].TaxonID;
		 Synonym.SynonymTypeID = Synonyms->Items[i].SynonymTypeID;
		 Synonym.TaxonCode = VarToStr(Synonyms->Items[i].TaxonCode);
		 Synonym.TaxonName = VarToStr(Synonyms->Items[i].TaxonName);
		 Synonym.Author = VarToStr(Synonyms->Items[i].Author);
		 Synonym.Extinct = Synonyms->Items[i].Extinct;
		 Synonym.TaxaGroupID = VarToStr(Synonyms->Items[i].TaxaGroupID);
		 Synonym.PublicationID = Synonyms->Items[i].PublicationID;
		 Synonym.Notes = VarToStr(Synonyms->Items[i].Notes);
		 Synonym.ValidatorID = Synonyms->Items[i].ValidatorID;
		 Synonym.ValidateDate = Synonyms->Items[i].ValidateDate;
		 EditNeotomaTaxa->Taxa[0].Synonyms.push_back(Synonym);
		 NeotomaSynonyms.push_back(Synonym);  // before editing
		 }
	   }
	 }
   delete Synonyms;

   TaxaDataSource->DataChanged();
   StatusBar1->SimpleText = L"";
   } catch (...) {
   }
   }
   __finally
   {
   Panel4->Visible = true;
   Splitter2->Visible = true;
   Panel6->Visible = true;
   Panel8->Visible = from_ss;
   Panel9->Visible = true;
   Screen->Cursor = crDefault;
   }
}
//---------------------------------------------------------------------------

void __fastcall TNewTaxonForm::cxTextEdit3PropertiesChange(TObject *Sender)
{
   if (cxLabel1->Visible)
	 cxLabel1->Visible = false;
   cxButton12->Enabled = !cxTextEdit3->Text.IsEmpty();
}
//---------------------------------------------------------------------------

void __fastcall TNewTaxonForm::txnCodePropertiesInitPopup(TObject *Sender)
{
   TaxonGridLevel = 0;
   int idx = cxGrid1TableView1->Controller->FocusedRecordIndex;
   cxTextEdit3->Text = EditNeotomaTaxa->Taxa[idx].TaxonCode;
}
//---------------------------------------------------------------------------

void __fastcall TNewTaxonForm::syCodePropertiesInitPopup(TObject *Sender)
{
   TaxonGridLevel = 1;
   int idx1 = cxGrid1TableView1->Controller->FocusedRecordIndex;
   //int idx2 = SynonymView->Controller->FocusedRecordIndex;
   int idx2 = SynonymDataController(idx1)->FocusedRecordIndex;

   cxTextEdit3->Text = EditNeotomaTaxa->Taxa[idx1].Synonyms[idx2].TaxonCode;
}
//---------------------------------------------------------------------------

// Code Auto button
void __fastcall TNewTaxonForm::cxButton11Click(TObject *Sender)
{
   switch (TaxonGridLevel) {
	 case 0:
	   cxTextEdit3->Text = FormCode();
	   break;
	 case 1:
	   cxTextEdit3->Text = FormSynonymCode();
	   break;
	 }
}
//---------------------------------------------------------------------------

// Code Test button
void __fastcall TNewTaxonForm::cxButton12Click(TObject *Sender)
{
   TestCode(cxTextEdit3->Text, true);
}
//---------------------------------------------------------------------------

// Code Ok button
void __fastcall TNewTaxonForm::cxButton13Click(TObject *Sender)
{
   int idx1, idx2;
   int TaxonID;
   UnicodeString OldCode;

   UnicodeString NewCode = cxTextEdit3->Text.Trim();
   cxTextEdit3->Text = NewCode;
   if (TestCode(NewCode, false)) {
	 idx1 = cxGrid1TableView1->Controller->FocusedRecordIndex;
	 switch (TaxonGridLevel) {
	   case 0:
		 OldCode = EditNeotomaTaxa->Taxa[idx1].TaxonCode;
		 EditNeotomaTaxa->Taxa[idx1].TaxonCode = NewCode;
		 if (!EditNeotomaTaxa->Taxa[idx1].TaxonID.IsEmpty())
		   TaxonID = EditNeotomaTaxa->Taxa[idx1].TaxonID;
		 TaxaDataSource->DataChanged();
		 // ((TcxPopupEdit*)(cxGrid1TableView1->Controller->EditingController->Edit))->DroppedDown = false;
		 if (idx1 == 0)
		   CheckUpdateTaxon(NULL);
		 else if (idx1 == 1)
		   CheckNewTaxonComplete();
		 break;
	   case 1:
		 idx2 = SynonymDataController(idx1)->FocusedRecordIndex;
		 OldCode = EditNeotomaTaxa->Taxa[idx1].Synonyms[idx2].TaxonCode;
		 EditNeotomaTaxa->Taxa[idx1].Synonyms[idx2].TaxonCode = NewCode;
		 if (!EditNeotomaTaxa->Taxa[idx1].Synonyms[idx2].TaxonID.IsEmpty())
		   TaxonID = EditNeotomaTaxa->Taxa[idx1].Synonyms[idx2].TaxonID;
		 SynonymDataSource->DataChanged();
		 //((TcxPopupEdit*)(SynonymGridView(idx1)->Controller->EditingController->Edit))->DroppedDown = false;
		 CheckUpdateSynonym(NULL);
		 break;
	   }

	 pair<multimap<UnicodeString,int>::iterator, multimap<UnicodeString,int>::iterator> range;
	 range = TaxaNameIndex.equal_range(OldCode);
	 multimap<UnicodeString,int>::iterator itr;
	 for (itr=range.first; itr != range.second; itr++) {
	   if (TaxonID == itr->second) {
		 TaxaNameIndex.erase(itr);
		 ShowMessage(L"OldCode found. ID = " + IntToStr(TaxonID));
		 break;
		 }
	   }
	 TaxaCodeIndex.insert(pair<UnicodeString,int>(NewCode,TaxonID));
	 }
}
//---------------------------------------------------------------------------

// Code Cancel button
void __fastcall TNewTaxonForm::cxButton14Click(TObject *Sender)
{
   switch (TaxonGridLevel) {
	 case 0:
	   ((TcxPopupEdit*)(cxGrid1TableView1->Controller->EditingController->Edit))->DroppedDown = false;
	   break;
	 case 1:
	   ((TcxPopupEdit*)(SynonymGridView()->Controller->EditingController->Edit))->DroppedDown = false;
	   break;
	 }
}
//---------------------------------------------------------------------------

bool TNewTaxonForm::TestCode(UnicodeString Code, bool show)
{
   int idx1, idx2;
   UnicodeString TaxonName, TaxaGroupID;

   bool rv = true;
   idx1 = cxGrid1TableView1->Controller->FocusedRecordIndex;
   switch (TaxonGridLevel) {
	 case 0:
	   TaxonName = EditNeotomaTaxa->Taxa[idx1].TaxonName;
	   TaxaGroupID = EditNeotomaTaxa->Taxa[idx1].TaxaGroupID;
	   break;
	 case 1:
	   idx2 = SynonymDataController(idx1)->FocusedRecordIndex;
	   TaxonName = EditNeotomaTaxa->Taxa[idx1].Synonyms[idx2].TaxonName;
	   TaxaGroupID = EditNeotomaTaxa->Taxa[idx1].Synonyms[idx2].TaxaGroupID;
	   if (TaxaGroupID.IsEmpty())
		 TaxaGroupID = EditNeotomaTaxa->Taxa[idx1].TaxaGroupID;
	   break;
	 }

   if (TaxaCodeIndex.count(Code) > 0) {
	 // find all taxa with code Code
     Screen->Cursor = crHourGlass;
	 NeotomaTaxaByCodeAndTaxaGroupID Taxon(ipsJSONS1, TcpClient1);
	 Taxon.AddParam(L"TAXONCODE", Code);
	 Taxon.AddParam(L"TAXAGROUPID", TaxaGroupID);
	 StatusBar1->SimpleText = Taxon.WebServiceName();
	 if (Taxon.Execute()) {
	   if (Taxon.Size() > 0)
		 rv = SameText(TaxonName, Taxon.Items[0].TaxonName);
	   }
	 }

   if (rv && show) {
	 Screen->Cursor = crHourGlass;
	 cxLabel1->Caption = L"Code is unique!";
	 cxLabel1->Style->Font->Color = clGreen;
	 if (Code[1] == L'[' && *Code.LastChar() == L']') {
	   UnicodeString RootCode = Code.SubString(2,Code.Length()-2);
	   NeotomaTaxaByCodeAndTaxaGroupID ValidTaxon(ipsJSONS1, TcpClient1);
	   ValidTaxon.AddParam(L"TAXONCODE", RootCode);
	   ValidTaxon.AddParam(L"TAXAGROUPID", TaxaGroupID);
	   StatusBar1->SimpleText = ValidTaxon.WebServiceName();
	   if (ValidTaxon.Execute()) {
		 if (ValidTaxon.Size() > 0) {
		   Screen->Cursor = crDefault;
		   UnicodeString msg = L"Taxon code «" + Code + L"» is unique.\nHowever, the root code «" +
			   RootCode + L"» is assigned to taxon «" + ValidTaxon.Items[0].TaxonName + L"».";
		   MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
		   }
		 }
	   }
	 }
   else if (!rv) {
	 cxLabel1->Caption = L"Code is not unique!";
	 cxLabel1->Style->Font->Color = clRed;
	 }
   Screen->Cursor = crDefault;

   if (!rv || show)
	 cxLabel1->Visible = true;

   StatusBar1->SimpleText = L"";
   return rv;
}
//---------------------------------------------------------------------------

UnicodeString TNewTaxonForm::FormSynonymCode(void)
{
   return (L"[" + FormCode() + L"]");
}
//---------------------------------------------------------------------------

UnicodeString TNewTaxonForm::FormCode(void)
{
   UnicodeString Code, TempCode, Genus, species, sCode;
   int pos, pos1, pos2, len, recm, idx1, idx2;
   bool family = false;
   bool order = false;
   bool cflead = false;
   bool cfmid = false;
   bool aff = false;
   bool question = false;
   bool type = false;
   bool undiff = false;
   bool sp = false;
   bool subg = false;
   bool subf = false;
   bool tribe = false;
   bool subtribe = false;
   UnicodeString TaxonName, TaxaGroupID;

   idx1 = cxGrid1TableView1->Controller->FocusedRecordIndex;
   switch (TaxonGridLevel) {
	 case 0:
	   TaxonName = EditNeotomaTaxa->Taxa[idx1].TaxonName;
	   TaxaGroupID = EditNeotomaTaxa->Taxa[idx1].TaxaGroupID;
	   break;
	 case 1:
	   idx2 = SynonymDataController(idx1)->FocusedRecordIndex;
	   TaxonName = EditNeotomaTaxa->Taxa[idx1].Synonyms[idx2].TaxonName;
	   TaxaGroupID = EditNeotomaTaxa->Taxa[idx1].Synonyms[idx2].TaxaGroupID;
	   break;
	 }

   multimap<UnicodeString,int>::iterator itr;
   pair<multimap<UnicodeString,int>::iterator, multimap<UnicodeString,int>::iterator> range;

   // take care of subg., subf., tribe, cf., aff., ?, -type, undiff., sp.

   if ((pos = TaxonName.Pos(" subg. ")) > 0) {
	 subg = true;
	 TaxonName.Delete(pos,6);
	 }
   else if ((pos = TaxonName.Pos(" subgenus ")) > 0) {
	 subg = true;
	 TaxonName.Delete(pos,9);
	 }
   else if ((pos = TaxonName.Pos(" subf. ")) > 0) {
	 subf = true;
	 TaxonName.Delete(pos,6);
	 }
   else if ((pos = TaxonName.Pos(" subfamily ")) > 0) {
	 subf = true;
	 TaxonName.Delete(pos,10);
	 }
   else if ((pos = TaxonName.Pos(" tribe ")) > 0) {
	 tribe = true;
	 TaxonName.Delete(pos,6);
	 }
   else if ((pos = TaxonName.Pos(" subtribe ")) > 0) {
	 subtribe = true;
	 TaxonName.Delete(pos,9);
	 }

   if (TaxonName.Pos("cf. ") == 1) {
	 TaxonName.Delete(1,4);
	 cflead = true;
	 }
   else if ((pos = TaxonName.Pos(" cf. ")) > 0) {
	 if (TaxonName.SubString(pos+6,2) == ". ")
	   TaxonName.Delete(pos,7);
     else
	   TaxonName.Delete(pos,4);
     cfmid = true;
     }
   else if (TaxonName.Pos("aff. ") == 1) {
	 TaxonName.Delete(1,5);
	 aff = true;
	 }
   else if (TaxonName.Pos("?") == 1) {
	 TaxonName.Delete(1,1);
     question = true;
     }

   if ((pos = TaxonName.Pos("-type")) == TaxonName.Length()-4) {
	 TaxonName.Delete(pos,5);
     type = true;
     }
   if ((pos = TaxonName.Pos("undiff.")) == TaxonName.Length()-6) {
	 TaxonName.Delete(pos,7);
     undiff = true;
     }
   else if ((pos = TaxonName.Pos("sp.")) == TaxonName.Length()-2) {
	 TaxonName.Delete(pos,3);
	 sp = true;
	 }

   if ((pos = TaxonName.Pos(" ")) > 0) {
	 Genus = TaxonName.SubString(1, pos-1);
	 species = TaxonName.SubString(pos+1, TaxonName.Length()-pos);
     }
   else
     Genus = TaxonName;

   range = TaxaNameIndex.equal_range(Genus);
   Code = L"";
   for (itr=range.first; itr != range.second; itr++) {
	 NTMTAXONMAP Taxon = TaxaMap[itr->second];
	 if (Taxon.TaxaGroupID == TaxaGroupID) {
	   Code = Taxon.TaxonCode;
	   break;
	   }
	 }

   if (Code.IsEmpty()) {
     len = Genus.Length();
     if (len >= 7) {
       if (Genus.SubString(len-4, 5) == "aceae") {
         Genus.Delete(len-4, 5);
         family = true;
         }
       else if (Genus.SubString(len-3, 4) == "ales") {
         Genus.Delete(len-3, 4);
		 order = true;
         }
       }
     pos1 = 2;
     pos2 = 3;
     while (pos1 < len && pos2 <= len) {
	   Code = Genus.SubString(1,1) + Genus.SubString(pos1,1) + Genus.SubString(pos2,1);
	   if (TaxaCodeIndex.count(Code) == 0)
		 break;
	   else {
         Code.SetLength(0);
         pos2++;
         if (pos2 > len) {
           pos1++;
           pos2 = pos1 + 1;
           }
         }
       }
     }
   if (Code.IsEmpty())
     Code = Genus.SubString(1,1) + "xx";
   if (family)
     Code += "eae";
   else if (order)
     Code += "les";

   if (cflead)
     Code.Insert("cf.",1);
   else if (aff)
     Code.Insert("af.",1);
   else if (question)
     Code.Insert("?",1);

   if (!species.IsEmpty()) {
	 pos1 = 2;
	 len = species.Length();
	 while (pos1 <= len) {
	   sCode = species.SubString(1,1) + species.SubString(pos1,1);
       TempCode = Code + "." + sCode;
	   if (TaxaCodeIndex.count(TempCode) == 0)
		 break;
       else {
         sCode.SetLength(0);
         pos1++;
         }
       }
     if (sCode.IsEmpty())
	   sCode = "xx";
     if (cfmid)
	   Code += ".cf.";
	 else if (subg)
	   Code += L".sg.";
	 else if (subf)
	   Code += L".sf.";
	 else if (tribe)
	   Code += L".tr.";
	 else if (subtribe)
	   Code += L".sst.";
	 else
       Code += ".";
	 Code += sCode;
     }

   if (type)
     Code += "-t";
   if (undiff)
     Code += ".ud";
   else if (sp)
     Code += ".sp";

   if (Code == L"xx")
	 Code = L"";
   return Code;
}
//---------------------------------------------------------------------------

void __fastcall TNewTaxonForm::cxRadioButton1Click(TObject *Sender)
{
   cxButton1->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TNewTaxonForm::cxRadioButton2Click(TObject *Sender)
{
   cxButton1->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TNewTaxonForm::cxTextEdit2PropertiesChange(TObject *Sender)
{
   if (!cxTextEdit2->Text.IsEmpty()) {
	 cxRadioButton3->Enabled = true;
	 cxRadioButton4->Enabled = true;
	 cxButton4->Enabled = (cxRadioButton3->Checked || cxRadioButton4->Checked);
	 }
   else {
	 cxRadioButton3->Enabled = false;
	 cxRadioButton4->Enabled = false;
     cxButton4->Enabled = false;
	 }
}
//---------------------------------------------------------------------------


void __fastcall TNewTaxonForm::cxRadioButton3Click(TObject *Sender)
{
   cxButton4->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TNewTaxonForm::cxRadioButton4Click(TObject *Sender)
{
   cxButton4->Enabled = true;
}
//---------------------------------------------------------------------------

// insert new taxon
void __fastcall TNewTaxonForm::cxButton1Click(TObject *Sender)
{
   InsertNewTaxon(cxRadioButton1, cxRadioButton2, cxTextEdit1->Text, SSTaxonCode, SSAuthor);
}
//---------------------------------------------------------------------------

// insert higher taxon
void __fastcall TNewTaxonForm::cxButton4Click(TObject *Sender)
{
   UnicodeString NewName;
   if (check_cf(cxTextEdit2->Text, NewName))
	 cxTextEdit2->Text = NewName;
   else if (cxTextEdit2->Text != NewName) {
	 MessageDlg(L"Upload aborted!", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 return;
	 }
   InsertNewTaxon(cxRadioButton3, cxRadioButton4, cxTextEdit2->Text, L"", L"");
   cxTextEdit2->Text = L"";
   cxRadioButton3->Enabled = false;
   cxRadioButton4->Enabled = false;
   cxRadioButton3->Checked = false;
   cxRadioButton4->Checked = false;
   cxButton4->Enabled = false;
}
//---------------------------------------------------------------------------

void TNewTaxonForm::InsertNewTaxon(TcxRadioButton* cxRadioButton1,
	TcxRadioButton* cxRadioButton2, UnicodeString TaxonName, UnicodeString TaxonCode,
	UnicodeString Author)
{
   if (!EditingLocked)
	 ToggleLock();

   int HigherID;
   int *TaxonIDPtr = new int;
   *TaxonIDPtr = --NewTaxonID;
   TaxonIDPtrs->Add(TaxonIDPtr);
   TTreeNode *Node;
   if (cxRadioButton1->Checked) {  // as child
	 Node = dxTreeView1->Items->AddChildObject(dxTreeView1->Selected, TaxonName, TaxonIDPtr);
	 HigherID = *((int*)dxTreeView1->Selected->Data);
	 }
   else if (cxRadioButton2->Checked) {  // as sibling
	 Node = dxTreeView1->Items->AddObject(dxTreeView1->Selected, TaxonName, TaxonIDPtr);
	 if (dxTreeView1->Selected->Level == 0)
	   HigherID = -1;
	 else
	   HigherID = *((int*)dxTreeView1->Selected->Parent->Data);
	 }

   dxTreeView1->AlphaSort();
   if (Node->Level == 0 || dxTreeView1->Selected->Level == 0)
	 dxTreeView1->AlphaSort(false);
   else
	 dxTreeView1->Selected->Parent->AlphaSort(false);
   Node->Selected = true;
   Node->Focused = true;

   Panel9->Visible = false;
   Panel8->Visible = false;
   Panel6->Visible = false;
   Label1->Visible = false;
   cxComboBox1->Visible =  false;
   cxButton2->Visible = false;
   cxButton6->Enabled = true;   // undo button

   NTMTAXONMAP Taxon;
   Taxon.TaxonName = TaxonName;
   Taxon.HigherTaxonID = HigherID;
   if (Node->Level == 0)
	 Taxon.TaxaGroupID = AdvMultiColumnDropDown1->Items->Items[AdvMultiColumnDropDown1->ItemIndex]->Text->Strings[0];
   else {
	 int HigherTaxonID = *((int*)dxTreeView1->Selected->Parent->Data);
	 NTMTAXONMAP HigherTaxon = TaxaMap[HigherTaxonID];
	 Taxon.TaxaGroupID = HigherTaxon.TaxaGroupID;
	 }

   if (Login->IsTaxonomyExpert) {
	 Taxon.ValidatorID = Login->ContactID;
	 Taxon.ValidateDate = UTCDateTime();
	 }

   pair<map<int,NTMTAXONMAP>::iterator, bool> ret;
   ret = TaxaMap.insert(pair<int,NTMTAXONMAP>(NewTaxonID, Taxon)); // max efficiency inserting
   map<int,NTMTAXONMAP>::iterator itr = ret.first;
   NTMTAXONMAP *NewTaxon = &itr->second;
   if (EditNeotomaTaxa->Count() == 2) {
	 EditNeotomaTaxa->Taxa[1].Clear();
	 TaxaDataSource->DataChanged();
	 }
   else {
	 NTMTAXONREC Taxon;
	 EditNeotomaTaxa->Add(Taxon);
	 }

   EditNeotomaTaxa->Taxa[1].TaxonName = NewTaxon->TaxonName;
   if (!TaxonCode.IsEmpty()) {
	 NewTaxon->TaxonCode = TaxonCode;
	 EditNeotomaTaxa->Taxa[1].TaxonCode = TaxonCode;
	 }
   if (!Author.IsEmpty()) {
	 NewTaxon->Author = Author;
	 EditNeotomaTaxa->Taxa[1].Author = Author;
	 }
   EditNeotomaTaxa->Taxa[1].HigherTaxonID = NewTaxon->HigherTaxonID;
   NewTaxon->Extinct = false;
   EditNeotomaTaxa->Taxa[1].TaxaGroupID = NewTaxon->TaxaGroupID;

   NewTaxon->PublicationID.ChangeType(varEmpty);

   if (Login->IsTaxonomyExpert) {
	 EditNeotomaTaxa->Taxa[1].ValidatorID = NewTaxon->ValidatorID;
	 EditNeotomaTaxa->Taxa[1].ValidateDate = NewTaxon->ValidateDate;
	 }

   TaxaDataSource->DataChanged();
   NewNode = Node;
}
//---------------------------------------------------------------------------

// Undo
void __fastcall TNewTaxonForm::cxButton6Click(TObject *Sender)
{
   UnDo();
}
//---------------------------------------------------------------------------

void TNewTaxonForm::UnDo(void)
{
   if (NewNode != NULL) {
	 TTreeNode* PrevNode = NewNode->GetPrev();
	 int TaxonID = *((int*)NewNode->Data);
	 dxTreeView1->Items->Delete(NewNode);
	 NewNode = NULL;
	 while (!PrevNode->IsVisible)
	   PrevNode = PrevNode->GetPrev();
	 PrevNode->Focused = true;
	 dxTreeView1->Select(PrevNode);
	 TaxaMap.erase(TaxonID);
	 cxGrid1TableView1->NavigatorButtons->CustomButtons->Items[0]->Enabled = false;
	 FocusControl(dxTreeView1);
	 EditNeotomaTaxa->Delete(1);
	 TaxaDataSource->DataChanged();
	 cxButton6->Enabled = false;
	 Label1->Visible = true;
	 cxComboBox1->Visible = true;
     cxButton2->Visible = true;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TNewTaxonForm::dxTreeView1CustomDraw(TObject *Sender, TTreeNode *TreeNode,
		  TFont *AFont, TColor &AColor, TColor &ABkColor)
{
   int TaxonID;
   if (TreeNode->Data == NULL)
	 TaxonID = 0;
   else
	 TaxonID = *((int*)TreeNode->Data);

   if (TaxonID < 0)
	 AColor = clBlue;
   else if (NewIDs.count(TaxonID) > 0)
	 AColor = clRed;

   if (UnvalidatedTaxa.find(TaxonID) != UnvalidatedTaxa.end()) {
	 ABkColor = clSkyBlue;
	 AColor = clNavy;
	 }

   if (MarkedNode != NULL) {
	 if (TreeNode == MarkedNode)
	   ABkColor = (TColor)0x006EBBFF;
	 else {
	   TTreeNode* ParentNode = TreeNode->Parent;
	   while (ParentNode != NULL) {
		 if (ParentNode == MarkedNode) {
		   ABkColor = (TColor)0x006EBBFF;
		   break;
		   }
		 else
		   ParentNode = ParentNode->Parent;
		 }
	   }
	 }
   //if (TreeNode->Selected) {
   //	 ABkColor = clHighlight;
   //	 AColor = clHighlightText;
   //	 }
}
//---------------------------------------------------------------------------

void __fastcall TNewTaxonForm::txnPubIDPropertiesButtonClick(TObject *Sender, int AButtonIndex)
{
   int idx = cxGrid1TableView1->Controller->FocusedRecordIndex;
   if (EditNeotomaTaxa->Taxa[idx].PublicationID.IsEmpty())
	 FindPubForm = new TFindPubForm(NULL, this);
   else {
	 int PubID = VariantToInt(EditNeotomaTaxa->Taxa[idx].PublicationID, -1);
	 if (PubID != -1)
	   FindPubForm = new TFindPubForm(NULL, PubID, this);
	 else
	   FindPubForm = new TFindPubForm(NULL, this);
	 }

   if (FindPubForm->ShowModal() == mrOk) {
	 if (FindPubForm->PubID > -1) {
	   EditNeotomaTaxa->Taxa[idx].PublicationID = FindPubForm->PubID;
	   TaxaDataSource->DataChanged();
	   if (idx == 0)
		 CheckUpdateTaxon(NULL);
	   }
	 }
   delete FindPubForm;
}
//---------------------------------------------------------------------------

void __fastcall TNewTaxonForm::syPubIDPropertiesButtonClick(TObject *Sender, int AButtonIndex)
{
   int idx1 = cxGrid1TableView1->Controller->FocusedRecordIndex;
   int idx2 = SynonymDataController(idx1)->FocusedRecordIndex;

   if (EditNeotomaTaxa->Taxa[idx1].Synonyms[idx2].PublicationID.IsEmpty())
	 FindPubForm = new TFindPubForm(NULL, this);
   else {
	 int PubID = VariantToInt(EditNeotomaTaxa->Taxa[idx1].Synonyms[idx2].PublicationID, -1);
	 if (PubID != -1)
	   FindPubForm = new TFindPubForm(NULL, PubID, this);
	 else
	   FindPubForm = new TFindPubForm(NULL, this);
	 }

   if (FindPubForm->ShowModal() == mrOk) {
	 if (FindPubForm->PubID > -1) {
	   EditNeotomaTaxa->Taxa[idx1].Synonyms[idx2].PublicationID = FindPubForm->PubID;
	   SynonymDataSource->DataChanged();
	   CheckUpdateSynonym(NULL);
	   }
	 }
   delete FindPubForm;
}
//---------------------------------------------------------------------------

void __fastcall TNewTaxonForm::txnNamePropertiesValidate(TObject *Sender, Variant &DisplayValue,
		  TCaption &ErrorText, bool &Error)
{
   // check if name changed, and if so, check that name not used
   UnicodeString NewName = VarToStr(DisplayValue).Trim();
   DisplayValue = NewName;
   if (NewName.IsEmpty()) {
	 cxGrid1TableView1->NavigatorButtons->CustomButtons->Items[0]->Enabled = false;
	 return;
	 }
   int idx1 = cxGrid1TableView1->Controller->FocusedRecordIndex;
   if (idx1 == 0) {
	 int TaxonID = VariantToInt(EditNeotomaTaxa->Taxa[0].TaxonID, -1);
	 NTMTAXONMAP *Taxon = &TaxaMap.find(TaxonID)->second;
	 //if (NewName != EditNeotomaTaxa->Taxa[0].TaxonName) [
	 if (NewName != Taxon->TaxonName) {
	   UnicodeString msg = L"Only spelling corrections should be made to taxon name here!";
	   msg += L"\nSynonymizations should be made with the synonymization tool.";
	   msg += L"\nTo accept the name change, click Ok.";
	   if (MessageDlg(msg, mtWarning, TMsgDlgButtons() << mbOK << mbCancel, 0) == mrCancel)
		 //DisplayValue = EditNeotomaTaxa->Taxa[0].TaxonName;
		 DisplayValue = Taxon->TaxonName;
	   else {  // check that name does not already exist
		 bool name_exists = false;
		 //UnicodeString TaxaGroupID = EditNeotomaTaxa->Taxa[0].TaxaGroupID;
		 UnicodeString TaxaGroupID = Taxon->TaxaGroupID;
		 Screen->Cursor = crHourGlass;
		 TaxonByName NeotomaTaxon(ipsJSONS1, TcpClient1);
		 NeotomaTaxon.AddParam(L"TAXONNAME", NewName);
		 StatusBar1->SimpleText = NeotomaTaxon.WebServiceName();
		 if (NeotomaTaxon.Execute()) {
		   if (NeotomaTaxon.Size() > 0) {
			 for (unsigned int i=0; i<NeotomaTaxon.Size(); i++) {
			   if (SameText(TaxaGroupID, NeotomaTaxon.Items[i].TaxaGroupID)) {
				 name_exists = true;
				 break;
				 }
			   }
			 }
		   }
		 StatusBar1->SimpleText = L"";
		 Screen->Cursor = crDefault;
		 if (name_exists) {
		   UnicodeString msg = L"Taxon name «" + NewName + L"» alredy exists!";
		   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   //DisplayValue = EditNeotomaTaxa->Taxa[0].TaxonName;
		   DisplayValue = Taxon->TaxonName;
		   }
		 else
		   cxGrid1TableView1->NavigatorButtons->CustomButtons->Items[0]->Enabled = true;
		 }
	   }
	 else
	   CheckUpdateTaxon((void*)(&Taxon->TaxonName));
	 }
}
//---------------------------------------------------------------------------

void __fastcall TNewTaxonForm::txnAuthorPropertiesValidate(TObject *Sender, Variant &DisplayValue,
		  TCaption &ErrorText, bool &Error)
{
   UnicodeString NewAuthor = VarToStr(DisplayValue).Trim();
   ValidateAuthor(NewAuthor);
   DisplayValue = NewAuthor;

   int idx = cxGrid1TableView1->Controller->FocusedRecordIndex;
   if (idx == 0) {
	 int TaxonID = VariantToInt(EditNeotomaTaxa->Taxa[0].TaxonID, -1);
	 NTMTAXONMAP *Taxon = &TaxaMap.find(TaxonID)->second;
	 if (NewAuthor != Taxon->Author)
	   cxGrid1TableView1->NavigatorButtons->CustomButtons->Items[0]->Enabled = true;
	 else
	   CheckUpdateTaxon((void*)(&Taxon->Author));
	 }
}
//---------------------------------------------------------------------------
typedef struct { UnicodeString author; bool parens; } _TAXONAUTHOR;
void TNewTaxonForm::ValidateAuthor(UnicodeString& NewAuthor)
{
   // "Smith, 1839|Jones, 1912"
   // " and "
   int pos;

   while ((pos = NewAuthor.Pos(L"  ")) > 0)
	 NewAuthor.Delete(pos,1);
   //while ((pos = NewAuthor.Pos(L"| ")) > 0)
   //	 NewAuthor.Delete(pos+1,1);
   //while ((pos = NewAuthor.Pos(L" |")) > 0)
   //	 NewAuthor.Delete(pos,1);
   while ((pos = NewAuthor.Pos(L" and ")) > 0) {
	 NewAuthor.Delete(pos+1,3);
	 NewAuthor.Insert(L"&",pos+1);
	 }

   vector<_TAXONAUTHOR> Authors;
   while ((pos = NewAuthor.Pos(L"|")) > 0) {
	 _TAXONAUTHOR Author;
	 Author.author = NewAuthor.SubString(1,pos-1).Trim();
	 NewAuthor.Delete(1,pos);
	 NewAuthor = NewAuthor.Trim();
	 if (Author.author[1] == L'(' && *Author.author.LastChar() == L')') {
	   Author.author = Author.author.SubString(2,Author.author.Length()-2);
	   Author.parens = true;
	   }
	 else
	   Author.parens = false;
	 Authors.push_back(Author);
	 }
   _TAXONAUTHOR Author;
   Author.author = NewAuthor;
   if (Author.author[1] == L'(' && *Author.author.LastChar() == L')') {
	 Author.author = Author.author.SubString(2,Author.author.Length()-2);
	 Author.parens = true;
	 }
   else
	 Author.parens = false;
   Authors.push_back(Author);

   bool is_year;
   for (unsigned int i=0; i<Authors.size(); i++) {
	 int len = Authors[i].author.Length();  //Author.Length();
	 is_year = (len >= 4);
	 if (is_year) {
	   if (*Author.author.LastChar() == L']') {
		 if (Authors[i].author.SubString(len-6,2) == L" [") {   // Smith, 1914 [1913]
		   Authors[i].author.Delete(len-6,1);                   // Smith, 1914[1913]
		   len--;
		   }
		 if (IsYear(Authors[i].author.SubString(len-9,4))) {
		   //ShowMessage(is_year ? L"is_year = true" : L"is_year = false");
		   if (!IsYear(Authors[i].author.SubString(len-9,4)))
			 is_year = false;
		   }
		 else
		   is_year = false;
		 if (is_year)
		   CheckYearSeparator(Authors[i].author, len, len-9);
		 }
	   else {
		 is_year = IsYear(Authors[i].author.SubString(len-3,4));   // Smith, 1914
		 if (is_year)
		   CheckYearSeparator(Authors[i].author, len, len-3);
		 }
	   }
	 if (!is_year)
	   break;
	 }

   // reassemble multiple authors
   for (unsigned int i=0; i<Authors.size(); i++) {
	 if (Authors[i].parens) {
	   Authors[i].author.Insert(L"(",1);
	   Authors[i].author += L")";
	   }
	 if (i == 0)
	   NewAuthor = Authors[i].author;
	 else
	   NewAuthor += (L"|" + Authors[i].author);
	 }

   if (!is_year)
	 MessageDlg(L"No year entered for author.", mtWarning, TMsgDlgButtons() << mbOK, 0);
}
//---------------------------------------------------------------------------

void TNewTaxonForm::CheckYearSeparator(UnicodeString& NewAuthor, int& len, int start)
{
   if (start < 3)
     return;
   if (NewAuthor.SubString(start-2,2) != L", ") {
	 if (NewAuthor[start-1] == L' ') {
	   NewAuthor.Insert(L",",start-1);
	   len++;
	   }
	 else if (NewAuthor[start-1] == L',') {
	   NewAuthor.Insert(L" ",start);
	   len++;
	   }
	 else {
	   NewAuthor.Insert(L", ",start);
	   len += 2;
	   }
	 }
}
//---------------------------------------------------------------------------

bool TNewTaxonForm::IsYear(UnicodeString str)
{
   if (str.Length() < 4)
	 return false;
   for (int i=1; i<=4; i++) {
	 if (!IsDigit(str,i))
	   return false;
	 }
   return true;
}
//---------------------------------------------------------------------------

void __fastcall TNewTaxonForm::txnExtinctPropertiesChange(TObject *Sender)
{
   int idx = cxGrid1TableView1->Controller->FocusedRecordIndex;
   if (idx == 0)
	 CheckUpdateTaxon(NULL);
}
//---------------------------------------------------------------------------

void __fastcall TNewTaxonForm::txnNotesPropertiesValidate(TObject *Sender, Variant &DisplayValue,
		  TCaption &ErrorText, bool &Error)
{
   UnicodeString NewNotes = VarToStr(DisplayValue).Trim();
   DisplayValue = NewNotes;
   int idx = cxGrid1TableView1->Controller->FocusedRecordIndex;
   if (idx == 0) {
	 int TaxonID = VariantToInt(EditNeotomaTaxa->Taxa[0].TaxonID, -1);
	 NTMTAXONMAP *Taxon = &TaxaMap.find(TaxonID)->second;
	 if (NewNotes != Taxon->Notes)
	   cxGrid1TableView1->NavigatorButtons->CustomButtons->Items[0]->Enabled = true;
	 else
	   CheckUpdateTaxon((void*)(&Taxon->Notes));
	 }
}
//---------------------------------------------------------------------------

void __fastcall TNewTaxonForm::txnEcolGroupPropertiesCloseUp(TObject *Sender)
{
   int idx = cxGrid1TableView1->Controller->FocusedRecordIndex;
   if (idx == 0)
	 CheckUpdateTaxon(NULL);
   if (idx == 1)
	 CheckNewTaxonComplete();
}
//---------------------------------------------------------------------------

void __fastcall TNewTaxonForm::syNamePropertiesValidate(TObject *Sender, Variant &DisplayValue,
		  TCaption &ErrorText, bool &Error)
{
   UnicodeString NewName = VarToStr(DisplayValue).Trim();
   DisplayValue = NewName;
   if (NewName.IsEmpty()) {
	 SynonymGridView()->NavigatorButtons->CustomButtons->Items[0]->Enabled = false;
	 return;
	 }

   int idx1 = cxGrid1TableView1->Controller->FocusedRecordIndex;
   int idx2 = SynonymDataController()->FocusedRecordIndex;

   if (EditNeotomaTaxa->Taxa[idx1].Synonyms[idx2].TaxonID.IsEmpty())  // upload
	 CheckUpdateSynonym(NULL);
   else {	// update
	 if (NewName != NeotomaSynonyms[idx2].TaxonName) {
	   // check if name not already used
	   UnicodeString msg = L"Only spelling corrections should be made to synonym name here,";
	   msg += L"\nas this synonym name may have been used in an original data contribution.";
	   msg += L"\nTo accept the name change, click Ok.";
	   if (MessageDlg(msg, mtWarning, TMsgDlgButtons() << mbOK << mbCancel, 0) == mrCancel)
		 DisplayValue = NeotomaSynonyms[idx2].TaxonName;
	   else {  // check that name does not already exist
		 bool name_exists = false;
		 UnicodeString TaxaGroupID = NeotomaSynonyms[idx2].TaxaGroupID;
		 Screen->Cursor = crHourGlass;
		 TaxonByName NeotomaTaxon(ipsJSONS1, TcpClient1);
		 NeotomaTaxon.AddParam(L"TAXONNAME", NewName);
		 StatusBar1->SimpleText = NeotomaTaxon.WebServiceName();
		 if (NeotomaTaxon.Execute()) {
		   if (NeotomaTaxon.Size() > 0) {
			 for (unsigned int i=0; i<NeotomaTaxon.Size(); i++) {
			   if (SameText(TaxaGroupID, NeotomaTaxon.Items[i].TaxaGroupID)) {
				 name_exists = true;
				 break;
				 }
			   }
			 }
		   }
		 StatusBar1->SimpleText = L"";
		 Screen->Cursor = crDefault;
		 if (name_exists) {
		   UnicodeString msg = L"Taxon name «" + NewName + L"» alredy exists!";
		   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   DisplayValue = NeotomaSynonyms[idx2].TaxonName;
		   }
		 else
		   SynonymGridView()->NavigatorButtons->CustomButtons->Items[0]->Enabled = true;
		 }
	   }
	 else
	   CheckUpdateSynonym((void*)(&NeotomaSynonyms[idx2].TaxonName));
	 }
}
//---------------------------------------------------------------------------

void __fastcall TNewTaxonForm::syAuthorPropertiesValidate(TObject *Sender, Variant &DisplayValue,
		  TCaption &ErrorText, bool &Error)
{
   UnicodeString NewAuthor = VarToStr(DisplayValue).Trim();
   ValidateAuthor(NewAuthor);
   DisplayValue = NewAuthor;

   int idx1 = cxGrid1TableView1->Controller->FocusedRecordIndex;
   int idx2 = SynonymDataController()->FocusedRecordIndex;
   if (EditNeotomaTaxa->Taxa[idx1].Synonyms[idx2].TaxonID.IsEmpty())  // upload
	 CheckUpdateSynonym(NULL);
   else {   // update
	 if (NewAuthor != NeotomaSynonyms[idx2].Author)
	   SynonymGridView()->NavigatorButtons->CustomButtons->Items[0]->Enabled = true;
	 else
	   CheckUpdateSynonym((void*)(&NeotomaSynonyms[idx2].Author));
	 }
}
//---------------------------------------------------------------------------

void __fastcall TNewTaxonForm::syExtinctPropertiesChange(TObject *Sender)
{
   CheckUpdateSynonym(NULL);
}
//---------------------------------------------------------------------------

void __fastcall TNewTaxonForm::syNotesPropertiesValidate(TObject *Sender, Variant &DisplayValue,
		  TCaption &ErrorText, bool &Error)
{
   UnicodeString NewNotes = VarToStr(DisplayValue).Trim();
   DisplayValue = NewNotes;

   int idx1 = cxGrid1TableView1->Controller->FocusedRecordIndex;
   int idx2 = SynonymDataController()->FocusedRecordIndex;
   if (EditNeotomaTaxa->Taxa[idx1].Synonyms[idx2].TaxonID.IsEmpty())
	 CheckUpdateSynonym(NULL);
   else {
	 if (NewNotes != NeotomaSynonyms[idx2].Notes)
	   SynonymGridView()->NavigatorButtons->CustomButtons->Items[0]->Enabled = true;
	 else
	   CheckUpdateSynonym((void*)(&NeotomaSynonyms[idx2].Notes));
	 }
}
//---------------------------------------------------------------------------

void TNewTaxonForm::CheckUpdateSynonym(void* avoid)
{
   bool Enabled;

   int idx1 = cxGrid1TableView1->Controller->FocusedRecordIndex;
   int idx2 = SynonymDataController(idx1)->FocusedRecordIndex;

   // for both updates and uploads
   Enabled = true;
   if (EditNeotomaTaxa->Taxa[idx1].Synonyms[idx2].TaxonCode.IsEmpty())
	 Enabled = false;
   else if (EditNeotomaTaxa->Taxa[idx1].Synonyms[idx2].TaxonName.IsEmpty())
	 Enabled = false;
   else if (EditNeotomaTaxa->Taxa[idx1].Synonyms[idx2].SynonymTypeID.IsEmpty())
	 Enabled = false;

   // for updates
   if (!EditNeotomaTaxa->Taxa[idx1].Synonyms[idx2].TaxonID.IsEmpty())	{    // update
	 Enabled = false;
	 if (EditNeotomaTaxa->Taxa[idx1].Synonyms[idx2].TaxonCode != NeotomaSynonyms[idx2].TaxonCode)
	   Enabled = true;
	 else if ((void*)(&NeotomaSynonyms[idx2].TaxonName) != avoid &&
	   EditNeotomaTaxa->Taxa[idx1].Synonyms[idx2].TaxonName != NeotomaSynonyms[idx2].TaxonName)
		 Enabled = true;
	 else if ((void*)(&NeotomaSynonyms[idx2].Author) != avoid &&
	   EditNeotomaTaxa->Taxa[idx1].Synonyms[idx2].Author != NeotomaSynonyms[idx2].Author)
		 Enabled = true;
	 else if (EditNeotomaTaxa->Taxa[idx1].Synonyms[idx2].SynonymTypeID != NeotomaSynonyms[idx2].SynonymTypeID)
	   Enabled = true;
	 else if (EditNeotomaTaxa->Taxa[idx1].Synonyms[idx2].Extinct != NeotomaSynonyms[idx2].Extinct)
	   Enabled = true;
	 else if (EditNeotomaTaxa->Taxa[idx1].Synonyms[idx2].PublicationID != NeotomaSynonyms[idx2].PublicationID)
	   Enabled = true;
	 else if ((void*)(&NeotomaSynonyms[idx2].Notes) != avoid &&
	   EditNeotomaTaxa->Taxa[idx1].Synonyms[idx2].Notes != NeotomaSynonyms[idx2].Notes)
		 Enabled = true;
	 else if (EditNeotomaTaxa->Taxa[idx1].Synonyms[idx2].ValidatorID.IsEmpty() ||
	   EditNeotomaTaxa->Taxa[idx1].Synonyms[idx2].ValidatorID != NeotomaSynonyms[idx2].ValidatorID)
		 Enabled = true;
	 else if (EditNeotomaTaxa->Taxa[idx1].Synonyms[idx2].ValidateDate.IsEmpty() ||
	   EditNeotomaTaxa->Taxa[idx1].Synonyms[idx2].ValidateDate != NeotomaSynonyms[idx2].ValidateDate)
		 Enabled = true;
	 }

   SynonymGridView(idx1)->NavigatorButtons->CustomButtons->Items[0]->Enabled = Enabled;
}
//---------------------------------------------------------------------------

void TNewTaxonForm::CheckUpdateTaxon(void* avoid)
{
   bool Enabled = false;
   int TaxonID = VariantToInt(EditNeotomaTaxa->Taxa[0].TaxonID, -1);
   if (TaxonID == -1)
	 return;
   NTMTAXONMAP *Taxon = &TaxaMap.find(TaxonID)->second;

   if (EditNeotomaTaxa->Taxa[0].TaxonName.IsEmpty())
	 Enabled = false;
   else if (EditNeotomaTaxa->Taxa[0].TaxonCode.IsEmpty())
	 Enabled = false;
   else if (EditNeotomaTaxa->Taxa[0].EcolSetsGroups.size() == 0)
	 Enabled = false;
   else if (EditNeotomaTaxa->Taxa[0].TaxonCode != Taxon->TaxonCode)
	 Enabled = true;
   else if ((void*)(&Taxon->TaxonName) != avoid && EditNeotomaTaxa->Taxa[0].TaxonName != Taxon->TaxonName)
	 Enabled = true;
   else if ((void*)(&Taxon->Author) != avoid && EditNeotomaTaxa->Taxa[0].Author != Taxon->Author)
	 Enabled = true;
   else if (EditNeotomaTaxa->Taxa[0].Extinct != Taxon->Extinct)
	 Enabled = true;
   else if (EditNeotomaTaxa->Taxa[0].PublicationID != Taxon->PublicationID)
	 Enabled = true;
   else if ((void*)(&Taxon->Notes) != avoid && EditNeotomaTaxa->Taxa[0].Notes != Taxon->Notes)
	 Enabled = true;
   else if (EditNeotomaTaxa->Taxa[0].ValidatorID != Taxon->ValidatorID)
	 Enabled = true;
   else if (EditNeotomaTaxa->Taxa[0].ValidateDate != Taxon->ValidateDate)
	 Enabled = true;
   else if (!Enabled) {
	 if (EditNeotomaTaxa->Taxa[0].EcolSetsGroups.size() != Taxon->EcolSetsGroups.size())
	   Enabled = true;
	 else {
	   map<UnicodeString,UnicodeString>::iterator itr1, itr2;
	   map<UnicodeString,UnicodeString>::iterator begin1 = EditNeotomaTaxa->Taxa[0].EcolSetsGroups.begin();
	   map<UnicodeString,UnicodeString>::iterator begin2 = Taxon->EcolSetsGroups.begin();
	   map<UnicodeString,UnicodeString>::iterator end1 = EditNeotomaTaxa->Taxa[0].EcolSetsGroups.end();
	   map<UnicodeString,UnicodeString>::iterator end2 = Taxon->EcolSetsGroups.end();
	   for (itr1=begin1, itr2=begin2; itr1 != end1; itr1++, itr2++) {
		 if (itr1->first != itr2->first || itr1->second != itr2->second) {
		   Enabled = true;
		   break;
		   }
		 }
	   }
	 }
   cxGrid1TableView1->NavigatorButtons->CustomButtons->Items[0]->Enabled = Enabled;
}
//---------------------------------------------------------------------------

void TNewTaxonForm::CheckNewTaxonComplete(void)
{
   bool Enabled = true;
   if (EditNeotomaTaxa->Taxa[1].TaxonCode.IsEmpty())      // TaxonCode
	 Enabled = false;
   else if (EditNeotomaTaxa->Taxa[1].TaxonName.IsEmpty()) // TaxonName
	 Enabled = false;
   else if (EditNeotomaTaxa->Taxa[1].EcolSetsGroups.size() == 0) // EcolGroup
	 Enabled = false;
   cxGrid1TableView1->NavigatorButtons->CustomButtons->Items[0]->Enabled = Enabled;
}
//---------------------------------------------------------------------------

void __fastcall TNewTaxonForm::cxGrid1TableView1NavigatorButtonsButtonClick(TObject *Sender,
		  int AButtonIndex, bool &ADone)
{
   int idx1;

   switch (AButtonIndex) {
	 case NavigatorButtonCount:
	   switch (dbTaxonAction) {
		 case dbaUPLOAD:
		   UploadTaxon();
		   break;
		 case dbaUPDATE:
		   UpdateTaxon();
		   break;
		 }
	   break;
	 case NBDI_DELETE:
	   idx1 = cxGrid1TableView1->Controller->FocusedRecordIndex;
	   if (idx1 == 0) {
		 PleaseWaitStart(L"Please Wait. Checking Links.");
		 UnicodeString TaxonName = EditNeotomaTaxa->Taxa[idx1].TaxonName;
		 UnicodeString CannotDeleteMsg = L"Taxon «" + TaxonName + L"» is linked to other data and cannot be deleted.";
		 bool error = false;
		 bool can_delete = true;
		 Screen->Cursor = crHourGlass;
		 int TaxonID = VariantToInt(EditNeotomaTaxa->Taxa[idx1].TaxonID, -1);

		 // check if taxon has any children
		 int nChildren = TaxonChildCount(TaxonID);
		 if (nChildren == -1)
		   error = true;
		 else if (nChildren > 0) {
		   UnicodeString msg = L"\n\nTaxon «" + TaxonName + L"» has " + IntToStr(nChildren);
		   msg += (nChildren == 1) ? L" child" : L" children";
		   msg += L", which must be deleted before parent taxon can be deleted.";
		   CannotDeleteMsg += msg;
		   can_delete = false;
		   }

		 // check if taxon has any synonyms
		 if (!error) {
		   int nSynonyms = SynonymCount(TaxonID);
		   if (nSynonyms == -1)
			 error = true;
		   else if (nSynonyms > 0) {
			 UnicodeString msg = L"\nTaxon «" + TaxonName + L"» has " + IntToStr(nSynonyms);
			 msg += (nSynonyms == 1) ? L" synonym" : L" synonyms";
			 msg += L", which must be deleted before parent taxon can be deleted.";
			 if (can_delete)
			   CannotDeleteMsg += L"\n";
			 CannotDeleteMsg += msg;
			 can_delete = false;
			 }
		   }

		 // check if taxon has any entries in the Synonymy table
		 if (!error) {
		   NeotomaTaxonSynonymyCount SynonymyCount(ipsJSONS1, TcpClient1);
		   SynonymyCount.AddParam(L"TAXONID", TaxonID);
		   StatusBar1->SimpleText = SynonymyCount.WebServiceName();
		   if (SynonymyCount.Execute()) {
			 if (SynonymyCount.Size() == 1) {
			   if (SynonymyCount.Items[0] > 0) {
				 UnicodeString msg = L"\nTaxon «" + TaxonName + L"» has " + IntToStr(SynonymyCount.Items[0]);
				 msg += (SynonymyCount.Items[0] == 1) ? L" record" : L" records";
				 msg += L" in the Synonyms table.";
				 if (can_delete)
				   CannotDeleteMsg += L"\n";
				 CannotDeleteMsg += msg;
				 can_delete = false;
				 }
			   }
			 else
			   error = true;
			 }
		   else
			 error = true;
		   }

		 // check if any data exist for taxon
		 if (!error) {
		   NeotomaTaxonDataRecordsCount DataCount(ipsJSONS1, TcpClient1);
		   DataCount.AddParam(L"TAXONID", TaxonID);
		   StatusBar1->SimpleText = DataCount.WebServiceName();
		   if (DataCount.Execute()) {
			 if (DataCount.Size() == 1) {
			   if (DataCount.Items[0] > 0) {
				 UnicodeString msg = L"\nTaxon «" + TaxonName + L"» has " + IntToStr(DataCount.Items[0]);
				 msg += (DataCount.Items[0] == 1) ? L" record" : L" records";
				 msg += L" in the Data table.";
				 if (can_delete)
				   CannotDeleteMsg += L"\n";
				 CannotDeleteMsg += msg;
				 can_delete = false;
				 }
			   }
			 else
			   error = true;
			 }
		   else
			 error = true;
		   }

		 // check taxon has any specimen dates
		 if (!error) {
		   NeotomaTaxonSpecimenDatesCount DatesCount(ipsJSONS1, TcpClient1);
		   DatesCount.AddParam(L"TAXONID", TaxonID);
		   StatusBar1->SimpleText = DatesCount.WebServiceName();
		   if (DatesCount.Execute()) {
			 if (DatesCount.Size() == 1) {
			   if (DatesCount.Items[0] > 0) {
				 UnicodeString msg = L"\nTaxon «" + TaxonName + L"» has " + IntToStr(DatesCount.Items[0]);
				 msg += (DatesCount.Items[0] == 1) ? L" record" : L" records";
				 msg += L" in the SpecimenDates table.";
				 CannotDeleteMsg += msg;
				 if (can_delete)
				   CannotDeleteMsg += L"\n";
				 can_delete = false;
				 }
			   }
			 else
			   error = true;
			 }
		   else
			 error = true;
		   }

		 PleaseWaitEnd();
		 if (!error) {
		   if (can_delete) {
			UnicodeString msg = L"Taxon «" + TaxonName + L"» is not linked to any other data.";
			msg += L"\nDelete «" + TaxonName + L"» from the Neotoma Taxa table?";
			 if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes) {
			   TTreeNode* DeleteNode = NULL;
			   for (int i=0; i<dxTreeView1->Items->Count; i++) {
				 TTreeNode* Node = dxTreeView1->Items->Item[i];
				 int ID = *((int*)Node->Data);
				 if (ID == TaxonID) {
				   DeleteNode = Node;
				   break;
				   }
				 }
			   if (DeleteNode != NULL) {
				 TTreeNode* PrevNode = DeleteNode->GetPrev();
				 dxTreeView1->Items->Delete(DeleteNode);
				 //DeleteNode = NULL;
				 while (!PrevNode->IsVisible)
				   PrevNode = PrevNode->GetPrev();
				 PrevNode->Focused = true;
				 dxTreeView1->Select(PrevNode);
				 TaxaMap.erase(TaxonID);
				 TaxaDataSource->DataChanged();

				 UnicodeString ErrorMsg;
				 DeleteData DeleteTaxon(L"DeleteTaxon", 1, ipsHTTPS1, ipsJSONS1, TcpClient1);
				 StatusBar1->SimpleText = L"DeleteTaxon";
				 DeleteTaxon.Add(L"TAXONID", TaxonID);
				 if (DeleteTaxon.Post(ErrorMsg)) {
				   UnicodeString msg = L"Success! Taxon «" + TaxonName + L"» deleted from the Neotoma Taxa table.";
				   MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
				   }
				 else {
				   UnicodeString msg = L"Attempt to delete record failed:";
				   if (!ErrorMsg.IsEmpty())
					 msg += (L": " + ErrorMsg);
				   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
				   }
				 }
			   }
			 }
		   else
			 MessageDlg(CannotDeleteMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   }

		 ADone = true;
		 StatusBar1->SimpleText = L"";
		 Screen->Cursor = crDefault;
		 }
	   break;
	 }
}
//---------------------------------------------------------------------------

int TNewTaxonForm::TaxonChildCount(int TaxonID)
{
   int count;
   NeotomaChildTaxaCount ChildTaxaCount(ipsJSONS1, TcpClient1);
   ChildTaxaCount.AddParam(L"HIGHERTAXONID", TaxonID);
   StatusBar1->SimpleText = ChildTaxaCount.WebServiceName();
   if (ChildTaxaCount.Execute()) {
	 if (ChildTaxaCount.Size() == 1)
	   count = ChildTaxaCount.Items[0];
	 else
	   count = -1;
	 }
   else
	 count = -1;
   return count;
}
//---------------------------------------------------------------------------

int TNewTaxonForm::SynonymCount(int TaxonID)
{
   int count;
   NeotomaTaxonSynonymsCount SynonymsCount(ipsJSONS1, TcpClient1);
   SynonymsCount.AddParam(L"VALIDTAXONID", TaxonID);
   StatusBar1->SimpleText = SynonymsCount.WebServiceName();
   if (SynonymsCount.Execute()) {
	 if (SynonymsCount.Size() == 1)
	   count = SynonymsCount.Items[0];
	 else
	   count = -1;
	 }
   else
	 count = -1;
   return count;
}
//---------------------------------------------------------------------------

void __fastcall TNewTaxonForm::cxGrid1TableView2NavigatorButtonsButtonClick(TObject *Sender,
		  int AButtonIndex, bool &ADone)
{
   int idx1, idx2, TaxonID;
   Variant vTaxonID;
   UnicodeString TaxonName;
   UnicodeString CannotDeleteMsg;
   bool error = false;
   bool can_delete = true;

   switch (AButtonIndex) {
	 case NavigatorButtonCount:
	   idx1 = cxGrid1TableView1->Controller->FocusedRecordIndex;
	   idx2 = SynonymDataController(idx1)->FocusedRecordIndex;
	   vTaxonID = EditNeotomaTaxa->Taxa[idx1].Synonyms[idx2].TaxonID;
	   if (vTaxonID.IsEmpty())
		 UploadSynonym();
	   else
		 UpdateSynonym();
	   break;
	 case NBDI_APPEND:
	   SynonymGridView()->NavigatorButtons->Append->Enabled = false;
	   break;
	 case NBDI_DELETE:
	   idx1 = cxGrid1TableView1->Controller->FocusedRecordIndex;
	   idx2 = SynonymDataController(idx1)->FocusedRecordIndex;
	   PleaseWaitStart(L"Please Wait. Checking Links.");
	   TaxonName = EditNeotomaTaxa->Taxa[idx1].Synonyms[idx2].TaxonName;
	   CannotDeleteMsg = L"Taxon «" + TaxonName + L"» is linked to other data and cannot be deleted.";
	   Screen->Cursor = crHourGlass;
	   TaxonID = VariantToInt(EditNeotomaTaxa->Taxa[idx1].Synonyms[idx2].TaxonID, -1);

	   // check if taxon has any synonyms
	   NeotomaInvalidTaxonSynonymyCount SynonymyCount(ipsJSONS1, TcpClient1);
	   SynonymyCount.AddParam(L"REFTAXONID", TaxonID);
	   StatusBar1->SimpleText = SynonymyCount.WebServiceName();
	   if (SynonymyCount.Execute()) {
		 if (SynonymyCount.Size() == 1) {
		   if (SynonymyCount.Items[0] > 0) {
			 UnicodeString msg = L"\n\nTaxon «" + TaxonName + L"» has " + IntToStr(SynonymyCount.Items[0]);
			   msg += (SynonymyCount.Items[0] == 1) ? L" record" : L" records";
			   msg += L" in the Synonymy table.";
			 CannotDeleteMsg += msg;
			 can_delete = false;
			 }
		   }
		 else
		   error = true;
		 }
	   else
		 error = true;

	   PleaseWaitEnd();

	   if (!error) {
		 if (can_delete) {
		   UnicodeString msg = L"Taxon «" + TaxonName + L"» is not linked to any other data.";
		   msg += L"\nDelete «" + TaxonName + L"» from the Neotoma Taxa table?";
		   if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes) {
			 vector<NTMSYNONYMREC>::iterator begin = EditNeotomaTaxa->Taxa[idx1].Synonyms.begin();
			 EditNeotomaTaxa->Taxa[idx1].Synonyms.erase(begin+idx2);
			 SynonymDataSource->DataChanged();

			 UnicodeString ErrorMsg;
			 DeleteData DeleteTaxon(L"DeleteTaxon", 1, ipsHTTPS1, ipsJSONS1, TcpClient1);
			 StatusBar1->SimpleText = L"DeleteTaxon";
			 DeleteTaxon.Add(L"TAXONID", TaxonID);
			 if (DeleteTaxon.Post(ErrorMsg)) {
			   UnicodeString msg = L"Success! Taxon «" + TaxonName + L"» deleted from the Neotoma Taxa table.";
			   MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
			   }
			 else {
			   UnicodeString msg = L"Attempt to delete record failed:";
			   if (!ErrorMsg.IsEmpty())
				 msg += (L": " + ErrorMsg);
			   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			   }
			 }
		   }
		 else
		   MessageDlg(CannotDeleteMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 }

	   ADone = true;
	   StatusBar1->SimpleText = L"";
	   Screen->Cursor = crDefault;
	   break;
	 }
}
//---------------------------------------------------------------------------

void TNewTaxonForm::UploadTaxon(void)
{
   int iValue;
   int NewTaxonID = -1;
   UnicodeString msg;
   UnicodeString EmptyFields;
   Variant ValidateDate;
   ValidateDate.ChangeType(varEmpty);
   Variant ValidatorID;
   ValidatorID.ChangeType(varEmpty);

   // check for empty fields
   int nMissingFields = 0;
   if (EditNeotomaTaxa->Taxa[1].Author.IsEmpty()) {
	 EmptyFields = L"Author";
	 nMissingFields++;
	 }
   if (EditNeotomaTaxa->Taxa[1].PublicationID.IsEmpty()) {
	 EmptyFields += ((nMissingFields == 0) ? L"PubID" : L", PubID");
	 nMissingFields++;
	 }
   if (nMissingFields > 0) {
	 if (nMissingFields == 1)
	   msg = L"The following field is empty: ";
	 else
	   msg = L"The following fields are empty: ";
	 msg += EmptyFields;
	 msg += L"\nContinue with upload anyway?";
	 if (MessageDlg(msg, mtWarning, TMsgDlgButtons() << mbYes << mbNo, 0) == mrNo)
	   return;
	 }

   Screen->Cursor = crHourGlass;
   UnicodeString TaxonCode = EditNeotomaTaxa->Taxa[1].TaxonCode;
   UnicodeString TaxonName = EditNeotomaTaxa->Taxa[1].TaxonName;
   UnicodeString Author = EditNeotomaTaxa->Taxa[1].Author;
   int HigherTaxonID = VariantToInt(EditNeotomaTaxa->Taxa[1].HigherTaxonID, -1);
   bool Extinct = EditNeotomaTaxa->Taxa[1].Extinct;
   UnicodeString TaxaGroupID = EditNeotomaTaxa->Taxa[1].TaxaGroupID;
   int PublicationID = VariantToInt(EditNeotomaTaxa->Taxa[1].PublicationID, -1);
   UnicodeString Notes = EditNeotomaTaxa->Taxa[1].Notes;

   // validate that HigherTaxonID exists
   if (HigherTaxonID != -1) {
	 NeotomaTaxonByID ValidTaxon(ipsJSONS1, TcpClient1);
	 ValidTaxon.AddParam(L"TAXONID", HigherTaxonID);
	 StatusBar1->SimpleText = ValidTaxon.WebServiceName();
	 if (ValidTaxon.Execute()) {
	   if (ValidTaxon.Size() != 1) {
		 msg = L"HigherTaxonID " + IntToStr(HigherTaxonID) + L" is not valid!";
		 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 return;
		 }
	   }
	 else
	   return;
	 }

   // validate that PublicationID exists
   if (PublicationID != -1) {
	 NeotomaPublicationsByPubID Publication(ipsJSONS1, TcpClient1);
	 StatusBar1->SimpleText = Publication.WebServiceName();
	 Publication.AddParam(L"PUBLICATIONID", PublicationID);
	 if (Publication.Execute()) {
	   if (Publication.Size() != 1) {
		 msg = L"PubID " + IntToStr(PublicationID) + L" is not valid!";
		 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 return;
		 }
	   }
	 else
	   return;
	 }

   // upload taxon
   UnicodeString ErrorMsg;
   vector<int> newids;
   int nparams = (Login->IsTaxonomyExpert) ? 11 : 9;
   InsertData InsertTaxon(L"InsertTaxon", nparams, ipsHTTPS1, ipsJSONS1, TcpClient1);
   StatusBar1->SimpleText = L"InsertTaxon";

   InsertTaxon.Add(L"CODE", TaxonCode);
   InsertTaxon.Add(L"NAME", TaxonName);
   InsertTaxon.Add(L"AUTHOR", Author);
   InsertTaxon.Add(L"VALID", true);
   InsertTaxon.Add(L"HIGHERID", HigherTaxonID, -1);
   InsertTaxon.Add(L"EXTINCT", Extinct);
   InsertTaxon.Add(L"GROUPID", TaxaGroupID);
   InsertTaxon.Add(L"PUBID", PublicationID, -1);
   InsertTaxon.Add(L"NOTES", Notes);
   if (Login->IsTaxonomyExpert) {
	 ValidatorID = Login->ContactID;
	 int iValidatorID = Login->ContactID;
	 InsertTaxon.Add(L"VALIDATORID", iValidatorID, -1);
	 ValidateDate = UTCDateTime();
	 InsertTaxon.Add(L"VALIDATEDATE", UTCDateTime().FormatString(L"yyyy-mm-dd"));
	 }
   InsertTaxon.PostData();
   if (InsertTaxon.Post(newids, ErrorMsg)) {
	 if (newids.size() == 1) {
	   // upload EcolGroups
	   NewTaxonID = newids[0];
	   if (HigherTaxonID == -1)
	     HigherTaxonID = NewTaxonID;
	   bool error = false;
	   map<UnicodeString,UnicodeString>::iterator itr;
	   map<UnicodeString,UnicodeString>::iterator begin = EditNeotomaTaxa->Taxa[1].EcolSetsGroups.begin();
	   map<UnicodeString,UnicodeString>::iterator end = EditNeotomaTaxa->Taxa[1].EcolSetsGroups.end();
	   for (itr = begin; itr != end; itr++) {
		 int EcolSetID = GetEcolSetID(itr->first);
		 UnicodeString EcolGroupID = itr->second;
		 InsertData InsertEcolGroup(L"InsertEcolGroup", 3, ipsHTTPS1, ipsJSONS1, TcpClient1);
		 StatusBar1->SimpleText = L"InsertEcolGroup";
		 InsertEcolGroup.Add(L"TAXONID", NewTaxonID, -1);
		 InsertEcolGroup.Add(L"ECOLSETID", EcolSetID, -1);
		 InsertEcolGroup.Add(L"ECOLGROUPID", EcolGroupID);
		 InsertEcolGroup.PostData();
		 if (!InsertEcolGroup.Post(ErrorMsg)) {
		   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   error = true;
		   break;
		   }
		 }
	   StatusBar1->SimpleText = L"";
	   if (!error) {
		 msg = L"Success: New taxon «" + TaxonName +"» uploaded to Neotoma. TaxonID = " + IntToStr(NewTaxonID) + L".";
		 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
		 TTreeNode *Node = dxTreeView1->Selected;
		 // set TaxonID to new Neotoma TaxonID
		 int *TaxonID = (int*)Node->Data;
		 *TaxonID = NewTaxonID;

		 NTMTAXONMAP NewTaxon;
		 NewTaxon.TaxonCode = TaxonCode;
		 NewTaxon.TaxonName = TaxonName;
		 NewTaxon.Author = Author;
		 NewTaxon.HigherTaxonID = HigherTaxonID;
		 NewTaxon.Extinct = Extinct;
		 NewTaxon.TaxaGroupID = TaxaGroupID;
		 NewTaxon.PublicationID = PublicationID;
		 NewTaxon.Notes = Notes;
		 NewTaxon.ValidatorID = ValidatorID;
		 NewTaxon.ValidateDate = ValidateDate;
		 NewTaxon.EcolSetsGroups = EditNeotomaTaxa->Taxa[1].EcolSetsGroups;

		 TaxaMap[NewTaxonID] = NewTaxon;

		 NewIDs.insert(NewTaxonID);
		 TAXONIDNAME TaxonUploaded;
		 TaxonUploaded.ID = NewTaxonID;
		 TaxonUploaded.Name = TaxonName;
		 TaxonUploaded.IsSynonym = false;
		 TaxaUploaded.push_back(TaxonUploaded);
		 NewNode = NULL;
		 //--------------------
		 //int taxon_id = *((int*)Node->Data);
		 //ShowMessage(L"New TaxonID = " + IntToStr(taxon_id));
		 }
	   }
	 }
   else {
	 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 StatusBar1->SimpleText = L"";
	 Screen->Cursor = crDefault;
	 return;
	 }

   StatusBar1->SimpleText = L"";
   cxGrid1TableView1->NavigatorButtons->CustomButtons->Items[0]->Enabled = false;
   EditNeotomaTaxa->Delete(1);
   TaxaDataSource->DataChanged();
   if (NewTaxonID != -1) {
	 Search(TaxonName);
     ShowTaxonMetaData(NewTaxonID);
	 }
   dxTreeView1->Repaint();

   Panel9->Visible = true;
   Panel8->Visible = from_ss;
   Panel6->Visible = true;
   Label1->Visible = true;
   cxComboBox1->Visible = true;
   cxButton2->Visible = true;
   cxButton6->Enabled = false;   // undo button

   Screen->Cursor = crDefault;
}
//---------------------------------------------------------------------------

void TNewTaxonForm::UploadSynonym(void)
{
   UnicodeString msg;
   UnicodeString EmptyFields;
   Variant ValidateDate;
   ValidateDate.ChangeType(varEmpty);
   Variant ValidatorID;
   ValidatorID.ChangeType(varEmpty);

   int idx1 = cxGrid1TableView1->Controller->FocusedRecordIndex;
   int idx2 = SynonymDataController(idx1)->FocusedRecordIndex;

   // check for optional empty fields that are usually filled
   int nMissingFields = 0;
   if (EditNeotomaTaxa->Taxa[idx1].Synonyms[idx2].Author.IsEmpty()) {
	 EmptyFields = L"Author";
	 nMissingFields++;
	 }
   if (EditNeotomaTaxa->Taxa[idx1].Synonyms[idx2].PublicationID.IsEmpty()) {
	 EmptyFields += ((nMissingFields == 0) ? L"PubID" : L", PubID");
	 nMissingFields++;
	 }
   if (nMissingFields > 0) {
	 if (nMissingFields == 1)
	   msg = L"The following field is empty: ";
	 else
	   msg = L"The following fields are empty: ";
	 msg += EmptyFields;
	 msg += L"\nContinue with upload anyway?";
	 if (MessageDlg(msg, mtWarning, TMsgDlgButtons() << mbYes << mbNo, 0) == mrNo)
	   return;
	 }
   if (EditNeotomaTaxa->Taxa[idx1].Synonyms[idx2].Extinct != EditNeotomaTaxa->Taxa[idx1].Extinct) {
	 msg = L"Extinction status of synonym not the same as valid taxon!\nMake extinction status of the synonym the same as valid taxon?";
	 if (MessageDlg(msg, mtWarning, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes)
	   EditNeotomaTaxa->Taxa[idx1].Synonyms[idx2].Extinct = EditNeotomaTaxa->Taxa[idx1].Extinct;
	 }

   Screen->Cursor = crHourGlass;
   UnicodeString TaxonCode = EditNeotomaTaxa->Taxa[idx1].Synonyms[idx2].TaxonCode;
   UnicodeString TaxonName = EditNeotomaTaxa->Taxa[idx1].Synonyms[idx2].TaxonName;
   UnicodeString Author = EditNeotomaTaxa->Taxa[idx1].Synonyms[idx2].Author;
   int SynonymTypeID = VariantToInt(EditNeotomaTaxa->Taxa[idx1].Synonyms[idx2].SynonymTypeID, -1);
   bool Extinct = EditNeotomaTaxa->Taxa[idx1].Synonyms[idx2].Extinct;
   UnicodeString TaxaGroupID = EditNeotomaTaxa->Taxa[idx1].TaxaGroupID;
   int PublicationID = VariantToInt(EditNeotomaTaxa->Taxa[idx1].Synonyms[idx2].PublicationID, -1);
   UnicodeString Notes = EditNeotomaTaxa->Taxa[idx1].Synonyms[idx2].Notes;

   // validate that PublicationID exists
   if (PublicationID != -1) {
	 NeotomaPublicationsByPubID Publication(ipsJSONS1, TcpClient1);
	 StatusBar1->SimpleText = Publication.WebServiceName();
	 Publication.AddParam(L"PUBLICATIONID", PublicationID);
	 if (Publication.Execute()) {
	   if (Publication.Size() != 1) {
		 msg = L"PubID " + IntToStr(PublicationID) + L" is not valid!";
		 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 return;
		 }
	   }
	 else
	   return;
	 }

   // validate SynonymTypeID
   if (GetNeotomaSynonymTypes()) {
	 if (NeotomaSynonymTypes.count(SynonymTypeID) == 0) {
	   msg = L"SynonymTypeID " + IntToStr(SynonymTypeID) + L" is not valid!";
	   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return;
	   }
	 }
   else
	 return;

   // upload synonym
   UnicodeString ErrorMsg;
   vector<int> newids;
   int nparams = (Login->IsTaxonomyExpert) ? 10 : 8;
   InsertData InsertTaxon(L"InsertTaxon", nparams, ipsHTTPS1, ipsJSONS1, TcpClient1);
   StatusBar1->SimpleText = L"InsertTaxon";

   InsertTaxon.Add(L"CODE", TaxonCode);
   InsertTaxon.Add(L"NAME", TaxonName);
   InsertTaxon.Add(L"AUTHOR", Author);
   InsertTaxon.Add(L"VALID", false);
   InsertTaxon.Add(L"EXTINCT", Extinct);
   InsertTaxon.Add(L"GROUPID", TaxaGroupID);
   InsertTaxon.Add(L"PUBID", PublicationID, -1);
   InsertTaxon.Add(L"NOTES", Notes);
   if (Login->IsTaxonomyExpert) {
	 ValidatorID = Login->ContactID;
	 int iValidatorID = Login->ContactID;
	 InsertTaxon.Add(L"VALIDATORID", iValidatorID, -1);
	 ValidateDate = UTCDateTime();
	 InsertTaxon.Add(L"VALIDATEDATE", UTCDateTime().FormatString(L"yyyy-mm-dd"));
	 }
   InsertTaxon.PostData();
   if (InsertTaxon.Post(newids, ErrorMsg)) {
	 if (newids.size() == 1) {
	   int NewTaxonID = newids[0];
	   bool error = false;
	   // upload SynonymTypeID
	   newids.clear();
	   int ValidTaxonID = VariantToInt(EditNeotomaTaxa->Taxa[idx1].TaxonID, -1);
	   InsertData InsertSynonym(L"InsertSynonym", 3, ipsHTTPS1, ipsJSONS1, TcpClient1);
	   StatusBar1->SimpleText = L"InsertSynonym";
	   InsertSynonym.Add(L"INVALIDTAXONID", NewTaxonID, -1);
	   InsertSynonym.Add(L"VALIDTAXONID", ValidTaxonID, -1);
	   InsertSynonym.Add(L"SYNONYMTYPEID", SynonymTypeID, -1);
	   InsertSynonym.PostData();
	   if (InsertSynonym.Post(newids, ErrorMsg)) {
		 if (newids.size() != 1)
		   error = true;
		 }

	   StatusBar1->SimpleText = L"";
	   if (!error) {
		 UnicodeString ValidTaxonName = EditNeotomaTaxa->Taxa[idx1].TaxonName;
		 msg = L"Success: Synonym «" + TaxonName + "» of valid taxon «" +
			   ValidTaxonName + "» uploaded to Neotoma. TaxonID = " +
			   IntToStr(NewTaxonID) + L".";
		 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);

		 EditNeotomaTaxa->Taxa[idx1].Synonyms[idx2].TaxonID = NewTaxonID;
		 EditNeotomaTaxa->Taxa[idx1].Synonyms[idx2].TaxaGroupID = TaxaGroupID;
		 EditNeotomaTaxa->Taxa[idx1].Synonyms[idx2].ValidatorID = ValidatorID;
		 EditNeotomaTaxa->Taxa[idx1].Synonyms[idx2].ValidateDate = ValidateDate;

		 NTMSYNONYMREC NewSynonym;
		 NewSynonym.TaxonID = NewTaxonID;
		 NewSynonym.TaxonCode = TaxonCode;
		 NewSynonym.TaxonName = TaxonName;
		 NewSynonym.Author = Author;
		 NewSynonym.Valid = false;
		 NewSynonym.SynonymTypeID = SynonymTypeID;
		 NewSynonym.Extinct = Extinct;
		 NewSynonym.TaxaGroupID = TaxaGroupID;
		 NewSynonym.PublicationID = PublicationID;
		 NewSynonym.Notes = Notes;
		 NewSynonym.ValidatorID = ValidatorID;
		 NewSynonym.ValidateDate = ValidateDate;
		 NeotomaSynonyms.push_back(NewSynonym);

		 TAXONIDNAME TaxonUploaded;
		 TaxonUploaded.ID = NewTaxonID;
		 TaxonUploaded.Name = TaxonName;
		 TaxonUploaded.IsSynonym = true;
		 TaxaUploaded.push_back(TaxonUploaded);
		 }
	   }
	 }
   else
	 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);

   StatusBar1->SimpleText = L"";
   SynonymDataSource->DataChanged();
   SynonymGridView()->NavigatorButtons->Append->Enabled = true;
   SynonymGridView()->NavigatorButtons->CustomButtons->Items[0]->Enabled = false;
   SynonymGridView()->NavigatorButtons->CustomButtons->Items[0]->Hint = L"Update synonym";
   Screen->Cursor = crDefault;
}
//---------------------------------------------------------------------------

bool TNewTaxonForm::GetNeotomaSynonymTypes(void)
{
   if (NeotomaSynonymTypes.size() == 0) {
	 NeotomaSynonymTypesTable SynonymTypes(ipsJSONS1, TcpClient1);
	 StatusBar1->SimpleText = SynonymTypes.WebServiceName();
	 if (SynonymTypes.Execute())
	   NeotomaSynonymTypes = SynonymTypes.Items;
	 else
	   return false;
	 }
   return true;
}
//---------------------------------------------------------------------------

/*
@CODE nvarchar(64),
@NAME nvarchar(80),
@AUTHOR nvarchar(128) = null,
//@VALID bit = 1,
//@HIGHERID int = null,
@EXTINCT bit = 0,
//@GROUPID nvarchar(3),
@PUBID int = null,
@VALIDATORID int = null,
@VALIDATEDATE date = null,
@NOTES nvarchar(MAX) = null)
*/
void TNewTaxonForm::UpdateTaxon(void)
{
   bool error = false;
   bool Updated = false;
   UnicodeString ErrorMsg;

   Screen->Cursor = crHourGlass;
   // TaxonID
   int TaxonID = EditNeotomaTaxa->Taxa[0].TaxonID;
   NTMTAXONMAP *Taxon = &TaxaMap.find(TaxonID)->second;

   // TaxonCode
   UnicodeString NewTaxonCode = EditNeotomaTaxa->Taxa[0].TaxonCode;
   if (NewTaxonCode.IsEmpty()) {
	 MessageDlg(L"Error: Code cannot be blank!", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 error = true;
	 }
   if (!error) {
	 if (NewTaxonCode != Taxon->TaxonCode) {
	   UpdateData UpdateTaxonCode(L"UpdateTaxonCode", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
	   StatusBar1->SimpleText = L"UpdateTaxonCode";
	   UpdateTaxonCode.Add(L"TAXONID", TaxonID);
	   UpdateTaxonCode.Add(L"TAXONCODE", NewTaxonCode);
	   if (UpdateTaxonCode.Post(ErrorMsg)) {
		 Taxon->TaxonCode = NewTaxonCode;
		 Updated = true;
		 }
	   else
		 error = true;
	   }
	 }

   // TaxonName
   if (!error) {
	 UnicodeString NewTaxonName = EditNeotomaTaxa->Taxa[0].TaxonName;
	 if (NewTaxonName.IsEmpty()) {
	   MessageDlg(L"Error: Name cannot be blank!", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   error = true;
	   }
	 if (!error) {
	   if (NewTaxonName != Taxon->TaxonName) {
		 UpdateData UpdateTaxonName(L"UpdateTaxonName", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
		 StatusBar1->SimpleText = L"UpdateTaxonName";
		 UpdateTaxonName.Add(L"TAXONID", TaxonID);
		 UpdateTaxonName.Add(L"TAXONNAME", NewTaxonName);
		 if (UpdateTaxonName.Post(ErrorMsg)) {
		   Taxon->TaxonName = NewTaxonName;
		   CurrentNode->Text = NewTaxonName;
		   Updated = true;
		   }
		 else
		   error = true;
	     }
	   }
	 }

   // Author
   if (!error) {
	 UnicodeString NewAuthor = EditNeotomaTaxa->Taxa[0].Author;
	 if (NewAuthor != Taxon->Author) {
	   UpdateData UpdateTaxonAuthor(L"UpdateTaxonAuthor", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
	   StatusBar1->SimpleText = L"UpdateTaxonAuthor";
	   UpdateTaxonAuthor.Add(L"TAXONID", TaxonID);
	   UpdateTaxonAuthor.Add(L"AUTHOR", NewAuthor);
	   if (UpdateTaxonAuthor.Post(ErrorMsg)) {
		 Taxon->Author = NewAuthor;
		 Updated = true;
		 }
	   else
		 error = true;
	   }
	 }

   // Extinct
   if (!error) {
	 bool NewExtinct = EditNeotomaTaxa->Taxa[0].Extinct;
	 if (NewExtinct != Taxon->Extinct) {
	   UpdateData UpdateTaxonExtinct(L"UpdateTaxonExtinct", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
	   StatusBar1->SimpleText = L"UpdateTaxonExtinct";
	   UpdateTaxonExtinct.Add(L"TAXONID", TaxonID);
	   UpdateTaxonExtinct.Add(L"EXTINCT", NewExtinct);
	   if (UpdateTaxonExtinct.Post(ErrorMsg)) {
		 Taxon->Extinct = NewExtinct;
		 Updated = true;
		 }
	   else
		 error = true;
	   }
	 }

   // PublicationID
   if (!error) {
	 Variant NewPubID = EditNeotomaTaxa->Taxa[0].PublicationID;
	 if (NewPubID != Taxon->PublicationID) {
	   int pub_id = VariantToInt(NewPubID, -1);
	   UpdateData UpdateTaxonPubID(L"UpdateTaxonPublicationID", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
	   StatusBar1->SimpleText = L"UpdateTaxonPublicationID";
	   UpdateTaxonPubID.Add(L"TAXONID", TaxonID);
	   Variant VPubID = (pub_id == -1) ? Unassigned() : pub_id;
	   //if (pub_id == -1)
	   //	 UpdateTaxonPubID.Add(L"PUBLICATIONID", L"");
	   //else
	   //	 UpdateTaxonPubID.Add(L"PUBLICATIONID", pub_id);
	   UpdateTaxonPubID.AddInt(L"PUBLICATIONID", VPubID);
	   if (UpdateTaxonPubID.Post(ErrorMsg)) {
		 Taxon->PublicationID = pub_id;
		 Updated = true;
		 }
	   else
		 error = true;
	   }
	 }

   // Notes
   if (!error) {
	 UnicodeString NewNotes = EditNeotomaTaxa->Taxa[0].Notes;
	 if (NewNotes != Taxon->Notes) {
	   UpdateData UpdateTaxonNotes(L"UpdateTaxonNotes", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
	   StatusBar1->SimpleText = L"UpdateTaxonNotes";
	   UpdateTaxonNotes.Add(L"TAXONID", TaxonID);
	   UpdateTaxonNotes.Add(L"NOTES", NewNotes);
	   if (UpdateTaxonNotes.Post(ErrorMsg)) {
		 Taxon->Notes = NewNotes;
		 Updated = true;
		 }
	   else
		 error = true;
	   }
	 }

   // EcolGroups
   if (!error) {
	 map<UnicodeString,UnicodeString>::iterator itr;
	 map<UnicodeString,UnicodeString>::iterator begin = Taxon->EcolSetsGroups.begin();
	 map<UnicodeString,UnicodeString>::iterator end = Taxon->EcolSetsGroups.end();

	 for (itr = begin; itr != end; itr++) {
	   int EcolSetID = GetEcolSetID(itr->first);
	   DeleteData DeleteEcolGroup(L"DeleteEcolGroup", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
	   StatusBar1->SimpleText = L"DeleteEcolGroup";
	   DeleteEcolGroup.Add(L"TaxonID", TaxonID);
	   DeleteEcolGroup.Add(L"EcolSetID", EcolSetID);
	   if (!DeleteEcolGroup.Post(ErrorMsg)) {
		 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 error = true;
		 break;
		 }
	   }

	 if (!error) {
	   begin = EditNeotomaTaxa->Taxa[0].EcolSetsGroups.begin();
	   end = EditNeotomaTaxa->Taxa[0].EcolSetsGroups.end();
	   for (itr = begin; itr != end; itr++) {
		 int EcolSetID = GetEcolSetID(itr->first);
		 InsertData InsertEcolGroup(L"InsertEcolGroup", 3, ipsHTTPS1, ipsJSONS1, TcpClient1);
		 StatusBar1->SimpleText = L"InsertEcolGroup";
		 InsertEcolGroup.Add(L"TAXONID", TaxonID, -1);
		 InsertEcolGroup.Add(L"ECOLSETID", EcolSetID, -1);
		 InsertEcolGroup.Add(L"ECOLGROUPID", itr->second);
		 InsertEcolGroup.PostData();
		 if (!InsertEcolGroup.Post(ErrorMsg)) {
		   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   error = true;
		   break;
		   }
		 }
	   if (!error) {
		 Taxon->EcolSetsGroups = EditNeotomaTaxa->Taxa[0].EcolSetsGroups;
		 Updated = true;
		 }
	   }
	 }

   if (!error && Updated) {
	 if (Login->IsTaxonomyExpert) {
	   int ValidatorID = Login->ContactID;
	   TDateTime ValidateDate = UTCDateTime();
	   UnicodeString ValidateDateStr = ValidateDate.FormatString(L"yyyy-mm-dd");
	   UpdateData UpdateTaxonValidation(L"UpdateTaxonValidation", 3, ipsHTTPS1, ipsJSONS1, TcpClient1);
	   StatusBar1->SimpleText = L"UpdateTaxonValidation";
	   UpdateTaxonValidation.Add(L"TAXONID", TaxonID);
	   UpdateTaxonValidation.Add(L"VALIDATORID", ValidatorID);
	   UpdateTaxonValidation.Add(L"VALIDATEDATE", ValidateDateStr);
	   if (UpdateTaxonValidation.Post(ErrorMsg)) {
		 Taxon->ValidatorID = ValidatorID;
		 Taxon->ValidateDate = ValidateDate;
		 EditNeotomaTaxa->Taxa[0].ValidatorID = ValidatorID;
		 EditNeotomaTaxa->Taxa[0].ValidateDate = ValidateDate;
		 TaxaDataSource->DataChanged();
		 }
	   else
		 error = true;
	   }
	 }

   StatusBar1->SimpleText = L"";
   Screen->Cursor = crDefault;
   cxGrid1TableView1->NavigatorButtons->CustomButtons->Items[0]->Enabled = false;

   if (error)
	 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
   else {
	 UnicodeString msg = L"Success! Taxon " + IntToStr(TaxonID) + L" «" + Taxon->TaxonName + L"» updated.";
	 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
	 }
}
//---------------------------------------------------------------------------

void TNewTaxonForm::UpdateSynonym(void)
{
   bool error = false;
   bool Updated = false;
   UnicodeString ErrorMsg;

   int idx1 = cxGrid1TableView1->Controller->FocusedRecordIndex;
   int idx2 = SynonymDataController(idx1)->FocusedRecordIndex;

   Screen->Cursor = crHourGlass;
   // TaxonID
   int TaxonID = VariantToInt(EditNeotomaTaxa->Taxa[idx1].Synonyms[idx2].TaxonID, -1);

   // TaxonCode
   UnicodeString NewTaxonCode = EditNeotomaTaxa->Taxa[idx1].Synonyms[idx2].TaxonCode;
   if (NewTaxonCode.IsEmpty()) {
	 MessageDlg(L"Error: Code cannot be blank!", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 error = true;
	 }
   if (!error) {
	 if (NewTaxonCode != NeotomaSynonyms[idx2].TaxonCode) {
	   UpdateData UpdateTaxonCode(L"UpdateTaxonCode", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
	   StatusBar1->SimpleText = L"UpdateTaxonCode";
	   UpdateTaxonCode.Add(L"TAXONID", TaxonID);
	   UpdateTaxonCode.Add(L"TAXONCODE", NewTaxonCode);
	   if (UpdateTaxonCode.Post(ErrorMsg)) {
		 NeotomaSynonyms[idx2].TaxonCode = NewTaxonCode;
		 Updated = true;
		 }
	   else
		 error = true;
	   }
	 }

   // TaxonName
   if (!error) {
	 UnicodeString NewTaxonName = EditNeotomaTaxa->Taxa[idx1].Synonyms[idx2].TaxonName;
	 if (NewTaxonName.IsEmpty()) {
	   MessageDlg(L"Error: Name cannot be blank!", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   error = true;
	   }
	 if (!error) {
	   if (NewTaxonName != NeotomaSynonyms[idx2].TaxonName) {
		 UpdateData UpdateTaxonName(L"UpdateTaxonName", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
		 StatusBar1->SimpleText = L"UpdateTaxonName";
		 UpdateTaxonName.Add(L"TAXONID", TaxonID);
		 UpdateTaxonName.Add(L"TAXONNAME", NewTaxonName);
		 if (UpdateTaxonName.Post(ErrorMsg)) {
		   NeotomaSynonyms[idx2].TaxonName = NewTaxonName;
		   Updated = true;
		   }
		 else
		   error = true;
	     }
	   }
	 }

   // Author
   if (!error) {
	 UnicodeString NewAuthor = EditNeotomaTaxa->Taxa[idx1].Synonyms[idx2].Author;
	 if (NewAuthor != NeotomaSynonyms[idx2].Author) {
	   UpdateData UpdateTaxonAuthor(L"UpdateTaxonAuthor", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
	   StatusBar1->SimpleText = L"UpdateTaxonAuthor";
	   UpdateTaxonAuthor.Add(L"TAXONID", TaxonID);
	   UpdateTaxonAuthor.Add(L"AUTHOR", NewAuthor);
	   if (UpdateTaxonAuthor.Post(ErrorMsg)) {
		 NeotomaSynonyms[idx2].Author = NewAuthor;
		 Updated = true;
		 }
	   else
		 error = true;
	   }
	 }

   // Extinct
   if (!error) {
	 bool NewExtinct = EditNeotomaTaxa->Taxa[idx1].Synonyms[idx2].Extinct;
	 if (NewExtinct != NeotomaSynonyms[idx2].Extinct) {
	   UpdateData UpdateTaxonExtinct(L"UpdateTaxonExtinct", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
	   StatusBar1->SimpleText = L"UpdateTaxonExtinct";
	   UpdateTaxonExtinct.Add(L"TAXONID", TaxonID);
	   UpdateTaxonExtinct.Add(L"EXTINCT", NewExtinct);
	   if (UpdateTaxonExtinct.Post(ErrorMsg)) {
		 NeotomaSynonyms[idx2].Extinct = NewExtinct;
		 Updated = true;
		 }
	   else
		 error = true;
	   }
	 }

   if (!error) {
	 Variant NewSynTypeID = EditNeotomaTaxa->Taxa[idx1].Synonyms[idx2].SynonymTypeID;
	 if (NewSynTypeID != NeotomaSynonyms[idx2].SynonymTypeID) {
	   int syntype_id = VariantToInt(NewSynTypeID, -1);
	   // get SynonymID from Synonyms table
	   NeotomaSynonym Synonym(ipsJSONS1, TcpClient1);
	   Synonym.AddParam(L"INVALIDTAXONID", TaxonID);
	   StatusBar1->SimpleText = Synonym.WebServiceName();
	   if (Synonym.Execute()) {
		 if (Synonym.Size() > 0) {
		   int SynonymID = Synonym.Items[0].SynonymID;
		   UpdateData UpdateSynonymTypeID(L"UpdateSynonymTypeID", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
		   StatusBar1->SimpleText = L"UpdateSynonymTypeID";
		   UpdateSynonymTypeID.Add(L"SynonymID", SynonymID);
		   UpdateSynonymTypeID.Add(L"SynonymTypeID", syntype_id);
		   if (UpdateSynonymTypeID.Post(ErrorMsg)) {
			 NeotomaSynonyms[idx2].SynonymTypeID = syntype_id;
			 Updated = true;
			 }
		   else
			 error = true;
		   }
		 }
	   else
		 error = true;

	   StatusBar1->SimpleText = L"";
	   }
	 }

   // PublicationID
   if (!error) {
	 Variant NewPubID = EditNeotomaTaxa->Taxa[idx1].Synonyms[idx2].PublicationID;
	 if (NewPubID != NeotomaSynonyms[idx2].PublicationID) {
	   int pub_id = VariantToInt(NewPubID, -1);
	   UpdateData UpdateTaxonPubID(L"UpdateTaxonPublicationID", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
	   StatusBar1->SimpleText = L"UpdateTaxonPublicationID";
	   UpdateTaxonPubID.Add(L"TAXONID", TaxonID);
	   Variant VPubID = (pub_id == -1) ? Unassigned() : pub_id;
	   //if (pub_id == -1)
	   //	 UpdateTaxonPubID.Add(L"PUBLICATIONID", L"");
	   //else
	   //	 UpdateTaxonPubID.Add(L"PUBLICATIONID", pub_id);
	   UpdateTaxonPubID.AddInt(L"PUBLICATIONID", VPubID);
	   if (UpdateTaxonPubID.Post(ErrorMsg)) {
		 if (pub_id == -1)
		   NeotomaSynonyms[idx2].PublicationID.ChangeType(varEmpty);
		 else
		   NeotomaSynonyms[idx2].PublicationID = pub_id;
		 Updated = true;
		 }
	   else
		 error = true;
	   }
	 }

   // Notes
   if (!error) {
	 UnicodeString NewNotes = EditNeotomaTaxa->Taxa[idx1].Synonyms[idx2].Notes;
	 if (NewNotes != NeotomaSynonyms[idx2].Notes) {
	   UpdateData UpdateTaxonNotes(L"UpdateTaxonNotes", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
	   StatusBar1->SimpleText = L"UpdateTaxonNotes";
	   UpdateTaxonNotes.Add(L"TAXONID", TaxonID);
	   UpdateTaxonNotes.Add(L"NOTES", NewNotes);
	   if (UpdateTaxonNotes.Post(ErrorMsg)) {
		 NeotomaSynonyms[idx2].Notes = NewNotes;
		 Updated = true;
		 }
	   else
		 error = true;
	   }
	 }

   // Validator
   if (!error && !Updated) {
	 if (NeotomaSynonyms[idx2].ValidatorID.IsEmpty())
	   Updated = true;
	 else {
	   int ValidatorID = Login->ContactID;
	   int validator_id = VariantToInt(NeotomaSynonyms[idx2].ValidatorID, -1);
	   if (ValidatorID != validator_id)
		 Updated = true;
	   }
	 }

   // Validate date
   if (!error && !Updated) {
	 if (NeotomaSynonyms[idx2].ValidateDate.IsEmpty())
	   Updated = true;
	 else {
	   Variant ValidateDate = UTCDateTime();
	   if (ValidateDate != NeotomaSynonyms[idx2].ValidateDate)
		 Updated = true;
	   }
	 }

   if (!error && Updated) {
	 if (Login->IsTaxonomyExpert) {
	   int ValidatorID = Login->ContactID;
	   TDateTime ValidateDate = UTCDateTime();
	   UnicodeString ValidateDateStr = ValidateDate.FormatString(L"yyyy-mm-dd");
	   UpdateData UpdateTaxonValidation(L"UpdateTaxonValidation", 3, ipsHTTPS1, ipsJSONS1, TcpClient1);
	   StatusBar1->SimpleText = L"UpdateTaxonValidation";
	   UpdateTaxonValidation.Add(L"TAXONID", TaxonID);
	   UpdateTaxonValidation.Add(L"VALIDATORID", ValidatorID);
	   UpdateTaxonValidation.Add(L"VALIDATEDATE", ValidateDateStr);
	   if (UpdateTaxonValidation.Post(ErrorMsg)) {
		 NeotomaSynonyms[idx2].ValidatorID = ValidatorID;
		 NeotomaSynonyms[idx2].ValidateDate = ValidateDate;
		 EditNeotomaTaxa->Taxa[idx1].Synonyms[idx2].ValidatorID = ValidatorID;
		 EditNeotomaTaxa->Taxa[idx1].Synonyms[idx2].ValidateDate = ValidateDate;
		 SynonymDataSource->DataChanged();
		 }
	   else
		 error = true;
	   }
	 }

   StatusBar1->SimpleText = L"";
   Screen->Cursor = crDefault;
   SynonymGridView(idx1)->NavigatorButtons->CustomButtons->Items[0]->Enabled = false;

   if (error)
	 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
   else {
	 UnicodeString msg = L"Success! Synonym " + IntToStr(TaxonID) + L" «" +
	   EditNeotomaTaxa->Taxa[idx1].Synonyms[idx2].TaxonName + L"» updated.";
	 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
	 }
}
//---------------------------------------------------------------------------

// change EcolSet
void __fastcall TNewTaxonForm::cxComboBox2Click(TObject *Sender)
{
   if (cxComboBox2->DroppedDown) {
	 UnicodeString EcolSetName = cxComboBox2->Properties->Items->Strings[cxComboBox2->ItemIndex];
	 if (EcolSetsGroups.count(EcolSetName) == 0) {
	   int EcolSetID = GetEcolSetID(EcolSetName);
	   if (EcolSetID > -1) {
		 NeotomaEcolGroupsByEcolSetID EcolGroups(ipsJSONS1, TcpClient1);
		 EcolGroups.AddParam(L"ECOLSETID", EcolSetID);
		 StatusBar1->SimpleText = EcolGroups.WebServiceName();
		 if (EcolGroups.Execute()) {
		   if (EcolGroups.Size() > 0) {
			 vector<CODENAME> EcolGroupNames;
			 map<UnicodeString,UnicodeString>::iterator itr;
			 map<UnicodeString,UnicodeString>::iterator begin = EcolGroups.Items.begin();
			 map<UnicodeString,UnicodeString>::iterator end = EcolGroups.Items.end();
			 for (itr = begin; itr != end; itr++) {
			   CODENAME CodeName;
			   CodeName.Code = itr->first;
			   CodeName.Name = itr->second;
			   EcolGroupNames.push_back(CodeName);
			   }
			 EcolSetsGroups[EcolSetName] = EcolGroupNames;
			 }
		   }
		 StatusBar1->SimpleText = L"";
		 }
	   }

	 if (EcolSetsGroups.count(EcolSetName) > 0) {
	   for (unsigned int i=0; i<EcolSetsGroups[EcolSetName].size(); i++) {
		 int row = i+1;
		 AdvColumnGrid2->Cells[0][row] = EcolSetsGroups[EcolSetName][i].Code;
		 AdvColumnGrid2->Cells[1][row] = EcolSetsGroups[EcolSetName][i].Name;
		 }
	   AdvColumnGrid2->Row = 1;
	   cxPopupEdit1->Text = EcolSetsGroups[EcolSetName][0].Name;
	   }

	 cxButton19->Enabled = !SetGroupExists();
	 cxButton20->Enabled = SetGroupExists();
	 }
}
//---------------------------------------------------------------------------

int TNewTaxonForm::GetEcolSetID(UnicodeString EcolSetName)
{
   int EcolSetID = -1;
   map<int,UnicodeString>::iterator itr;
   map<int,UnicodeString>::iterator begin = EcolSetTypes.begin();
   map<int,UnicodeString>::iterator end = EcolSetTypes.end();
   for (itr = begin; itr != end; itr++) {
	 if (SameText(EcolSetName, itr->second)) {
	   EcolSetID = itr->first;
	   break;
	   }
	 }
   return EcolSetID;
}
//---------------------------------------------------------------------------

UnicodeString TNewTaxonForm::GetEcolGroupID(UnicodeString EcolGroupName)
{
   UnicodeString EcolGroupID;
   map<UnicodeString,UnicodeString>::iterator itr;
   map<UnicodeString,UnicodeString>::iterator begin = EcolGroupTypes.begin();
   map<UnicodeString,UnicodeString>::iterator end = EcolGroupTypes.end();
   for (itr = begin; itr != end; itr++) {
	 if (SameText(EcolGroupName, itr->second)) {
	   EcolGroupID = itr->first;
	   break;
	   }
	 }
   return EcolGroupID;
}
//---------------------------------------------------------------------------

void __fastcall TNewTaxonForm::cxPopupEdit1PropertiesChange(TObject *Sender)
{
   cxButton19->Enabled = !SetGroupExists();    // Add button
   cxButton20->Enabled = SetGroupExists();     // Delete button
}
//---------------------------------------------------------------------------

bool TNewTaxonForm::SetGroupExists(void)
{
   UnicodeString EcolSetName = cxComboBox2->Text;
   UnicodeString EcolGroupID = GetEcolGroupID(cxPopupEdit1->Text);
   int idx = cxGrid1TableView1->Controller->FocusedRecordIndex;
   bool exists = false;
   map<UnicodeString,UnicodeString>::iterator itr = EditNeotomaTaxa->Taxa[idx].EcolSetsGroups.find(EcolSetName);
   if (itr != EditNeotomaTaxa->Taxa[idx].EcolSetsGroups.end()) {    // set exists
	 if (SameText(EditNeotomaTaxa->Taxa[idx].EcolSetsGroups[EcolSetName], EcolGroupID))
	   exists = true;
	 }
   return exists;
}
//---------------------------------------------------------------------------

// EcolGroups Add button
void __fastcall TNewTaxonForm::cxButton19Click(TObject *Sender)
{
   UnicodeString EcolSetName = cxComboBox2->Text;
   UnicodeString EcolGroupID = GetEcolGroupID(cxPopupEdit1->Text);
   int idx = cxGrid1TableView1->Controller->FocusedRecordIndex;
   bool found = false;
   map<UnicodeString,UnicodeString>::iterator itr = EditNeotomaTaxa->Taxa[idx].EcolSetsGroups.find(EcolSetName);
   if (itr != EditNeotomaTaxa->Taxa[idx].EcolSetsGroups.end()) {    // set exists
	 if (SameText(EditNeotomaTaxa->Taxa[idx].EcolSetsGroups[EcolSetName], EcolGroupID))   // group already exists for set
	   found = true;
	 else
	   EditNeotomaTaxa->Taxa[idx].EcolSetsGroups.erase(itr);
	 }
   if (!found) {
	 EditNeotomaTaxa->Taxa[idx].EcolSetsGroups[EcolSetName] = EcolGroupID;
	 TaxaDataSource->DataChanged();
	 }
   cxButton19->Enabled = false;
   cxButton20->Enabled = true;
}
//---------------------------------------------------------------------------

// EcolGroups Delete button
void __fastcall TNewTaxonForm::cxButton20Click(TObject *Sender)
{
   UnicodeString EcolSetName = cxComboBox2->Text;
   UnicodeString EcolGroupName = cxPopupEdit1->Text;
   int idx = cxGrid1TableView1->Controller->FocusedRecordIndex;
   map<UnicodeString,UnicodeString>::iterator itr = EditNeotomaTaxa->Taxa[idx].EcolSetsGroups.find(EcolSetName);
   if (itr != EditNeotomaTaxa->Taxa[idx].EcolSetsGroups.end()) {
	 UnicodeString EcolGroupID = GetEcolGroupID(EcolGroupName);
	 if (SameText(EditNeotomaTaxa->Taxa[idx].EcolSetsGroups[EcolSetName], EcolGroupID)) {
	   EditNeotomaTaxa->Taxa[idx].EcolSetsGroups.erase(itr);
	   TaxaDataSource->DataChanged();
	   }
	 }
   cxButton19->Enabled = true;
   cxButton20->Enabled = false;
}
//---------------------------------------------------------------------------

// EcolGroups Close button
void __fastcall TNewTaxonForm::cxButton18Click(TObject *Sender)
{
   ((TcxPopupEdit*)(cxGrid1TableView1->Controller->EditingController->Edit))->DroppedDown = false;
}
//---------------------------------------------------------------------------

void __fastcall TNewTaxonForm::txnEcolGroupPropertiesInitPopup(TObject *Sender)
{
   UnicodeString EcolSetName, EcolGroupID;

   cxComboBox2->Clear();
   cxComboBox2->Properties->Items->Clear();
   AdvColumnGrid2->ClearNormalCells();

   int idx;
   idx = cxGrid1TableView1->Controller->FocusedRecordIndex;
   //UnicodeString EcolSetName;
   //if (EditNeotomaTaxa->Taxa[idx].EcolSetsGroups.size() > 0)
   //	 EcolSetName = EditNeotomaTaxa->Taxa[idx].EcolSetsGroups.begin()->first;
   //else
   //	 EcolSetName = EcolSetsGroups.begin()->first;

   //------------------------------------------------
   Screen->Cursor = crHourGlass;
   // for the TaxaGroupID (e.g. VPL), get the counts of the EcolSets (e.g. Default plant)
   NeotomaEcolSetCounts EcolSetCounts(ipsJSONS1, TcpClient1);
   EcolSetCounts.AddParam(L"TAXAGROUPID", EditNeotomaTaxa->Taxa[idx].TaxaGroupID);
   StatusBar1->SimpleText = EcolSetCounts.WebServiceName();
   if (EcolSetCounts.Execute()) {
	 if (EcolSetCounts.Size() > 0) {
	   int max_count_idx = 0;
	   int max_count = EcolSetCounts.Items[0].Count;
	   for (unsigned int i=0; i<EcolSetCounts.Size(); i++) {
		 cxComboBox2->Properties->Items->Add(EcolSetCounts.Items[i].EcolSetName);
		 if (EcolSetCounts.Items[i].Count > max_count) {
		   max_count = EcolSetCounts.Items[i].Count;
		   max_count_idx = i;
		   }
		 }
	   cxComboBox2->ItemIndex = max_count_idx;

	   // get the EcolGroups for each EcolSet
	   //map<UnicodeString, vector<CODENAME> > EcolSetsGroups;    // EcolSetName, EcolGroup vector
	   EcolSetsGroups.clear();
	   for (unsigned int i=0; i<EcolSetCounts.Size(); i++)
		 GetEcolSetsGroups(EcolSetCounts.Items[i].EcolSetID, EcolSetCounts.Items[i].EcolSetName);

	   EcolSetName = EcolSetCounts.Items[max_count_idx].EcolSetName;
	   if (EditNeotomaTaxa->Taxa[idx].EcolSetsGroups.count(EcolSetName) > 0)
		 EcolGroupID = EditNeotomaTaxa->Taxa[idx].EcolSetsGroups[EcolSetName];
	   int ActiveRow = -1;
	   AdvColumnGrid2->RowCount = EcolSetsGroups[EcolSetName].size() + 1;
	   for (unsigned int i=0; i<EcolSetsGroups[EcolSetName].size(); i++) {
		 int row = i+1;
		 AdvColumnGrid2->Cells[0][row] = EcolSetsGroups[EcolSetName][i].Code;
		 AdvColumnGrid2->Cells[1][row] = EcolSetsGroups[EcolSetName][i].Name;
		 if (ActiveRow == -1 && SameText(EcolSetsGroups[EcolSetName][i].Code, EcolGroupID))
		   ActiveRow = row;
		 }
	   if (ActiveRow == -1)
		 ActiveRow = 1;
	   AdvColumnGrid2->Row = ActiveRow;
	   cxPopupEdit1->Text = AdvColumnGrid2->Cells[1][ActiveRow];
	   }
	 }
   Screen->Cursor = crDefault;

   if (!EcolSetName.IsEmpty() && !EcolGroupID.IsEmpty()) {
	 if (EditNeotomaTaxa->Taxa[idx].EcolSetsGroups.count(EcolSetName) > 0) {
	   if (SameText(EditNeotomaTaxa->Taxa[idx].EcolSetsGroups[EcolSetName], EcolGroupID)) {
		 cxButton20->Enabled = true;  // delete button
		 cxButton19->Enabled = false; // add button
		 }
	   else {
		 cxButton20->Enabled = false; // delete button
		 cxButton19->Enabled = true;  // add button
		 }
	   }
	 else {
	   cxButton20->Enabled = false; // delete button
	   cxButton19->Enabled = true;  // add button
	   }
	 }
   else {
	 cxButton20->Enabled = false; // delete button
	 cxButton19->Enabled = false;  // add button
	 }
}
//---------------------------------------------------------------------------

void __fastcall TNewTaxonForm::AdvColumnGrid2ClickCell(TObject *Sender, int ARow,
          int ACol)
{
   if (ARow == 0) return;
   cxPopupEdit1->Text = AdvColumnGrid2->Cells[1][ARow];
   cxPopupEdit1->DroppedDown = false;
}
//---------------------------------------------------------------------------

// EcolGroups Cancel button
void __fastcall TNewTaxonForm::cxButton15Click(TObject *Sender)
{
   cxPopupEdit1->DroppedDown = false;
}
//---------------------------------------------------------------------------

// New EcolGroups
void __fastcall TNewTaxonForm::cxButton16Click(TObject *Sender)
{
   UnicodeString EcolGroupID = AdvColumnGrid2->Cells[0][AdvColumnGrid2->Row];
   NewEcolGroupForm = new TNewEcolGroupForm(this);
   NewEcolGroupForm->ShowModal();
   if (NewEcolGroupForm->NewEcolGroups.size() > 0) {
	 AdvColumnGrid2->BeginUpdate();
	 int row = AdvColumnGrid2->RowCount;
	 AdvColumnGrid2->RowCount += NewEcolGroupForm->NewEcolGroups.size();
	 map<UnicodeString,UnicodeString>::iterator itr;
	 map<UnicodeString,UnicodeString>::iterator begin = NewEcolGroupForm->NewEcolGroups.begin();
	 map<UnicodeString,UnicodeString>::iterator end = NewEcolGroupForm->NewEcolGroups.end();
	 for (itr = begin; itr != end; itr++) {
	   AdvColumnGrid2->Cells[0][row] = itr->first;
	   AdvColumnGrid2->Cells[1][row++] = itr->second;
	   }
	 AdvColumnGrid2->SortByColumn(0);
	 AdvColumnGrid2->EndUpdate();
	 for (int row=1; row<AdvColumnGrid2->RowCount; row++) {
	   if (SameText(AdvColumnGrid2->Cells[0][row], EcolGroupID)) {
		 AdvColumnGrid2->Row = row;
		 break;
		 }
	   }
	 }
   delete NewEcolGroupForm;
}
//---------------------------------------------------------------------------

// show all EcolSetTypes
void __fastcall TNewTaxonForm::cxButton7Click(TObject *Sender)
{
   cxComboBox2->Properties->Items->BeginUpdate();
   cxComboBox2->Properties->Items->Clear();
   map<int,UnicodeString>::iterator itr;
   map<int,UnicodeString>::iterator begin = EcolSetTypes.begin();
   map<int,UnicodeString>::iterator end = EcolSetTypes.end();
   for (itr = begin; itr != end; itr++)
	 cxComboBox2->Properties->Items->Add(itr->second);
   cxComboBox2->Properties->Items->EndUpdate();
   cxButton7->Enabled = false;
}
//---------------------------------------------------------------------------

// show all EcolGroupTypes
void __fastcall TNewTaxonForm::cxButton8Click(TObject *Sender)
{
   AdvColumnGrid2->ClearNormalCells();
   map<UnicodeString,UnicodeString>::iterator itr;
   map<UnicodeString,UnicodeString>::iterator begin = EcolGroupTypes.begin();
   map<UnicodeString,UnicodeString>::iterator end = EcolGroupTypes.end();
   AdvColumnGrid2->RowCount = EcolGroupTypes.size() + 1;
   int row = 1;
   for (itr = begin; itr != end; itr++) {
	 AdvColumnGrid2->Cells[0][row] = itr->first;;
	 AdvColumnGrid2->Cells[1][row++] = itr->second;
	 }
   cxButton8->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TNewTaxonForm::Timer1Timer(TObject *Sender)
{
   RatPos += 48;
   if (RatPos > RatEnd)
	 RatPos = RatStart;
   Image1->Left = RatPos;
}
//---------------------------------------------------------------------------

// lock button
void __fastcall TNewTaxonForm::cxButton9Click(TObject *Sender)
{
   ToggleLock();
}
//---------------------------------------------------------------------------

void TNewTaxonForm::ToggleLock(void)
{
   // format Row 1
   UnicodeString EcolSetName;
   if (EditingLocked) {
	 cxButton9->Caption = L"Unlocked";
	 cxButton9->OptionsImage->ImageIndex = 3;
	 cxButton9->Hint = L"Click to lock editing of existing taxon";
	 EditingLocked = false;
	 UploadButtonEnabled = cxGrid1TableView1->NavigatorButtons->CustomButtons->Items[0]->Enabled;
	 cxGrid1TableView1->NavigatorButtons->CustomButtons->Items[0]->Hint = L"Update taxon";
	 cxGrid1TableView1->NavigatorButtons->Delete->Enabled = true;
	 dbTaxonAction = dbaUPDATE;
	 cxGrid1TableView1->NavigatorButtons->CustomButtons->Items[0]->Enabled =
	   EditNeotomaTaxa->Taxa[0].ValidatorID.IsEmpty();  // if taxon has not been validated
	 if (cxGrid1TableView2->CloneCount > 0) {
	   for (int i=0; i<cxGrid1TableView2->CloneCount; i++) {
		 ((TcxGridTableView*)((TcxGridLevel*)cxGrid1TableView2->Clones[i]->Level)->GridView)->NavigatorButtons->Append->Enabled = true;
		 ((TcxGridTableView*)((TcxGridLevel*)cxGrid1TableView2->Clones[i]->Level)->GridView)->NavigatorButtons->Delete->Enabled = true;
		 }
	   }
	 }
   else {   // Editng unlocked
	 cxButton9->Caption = L"Locked";
	 cxButton9->OptionsImage->ImageIndex = 2;
	 cxButton9->Hint = L"Click to unlock editing of existing taxon";
	 EditingLocked = true;
	 cxGrid1TableView1->NavigatorButtons->CustomButtons->Items[0]->Enabled = UploadButtonEnabled;
	 cxGrid1TableView1->NavigatorButtons->CustomButtons->Items[0]->Hint = L"Upload new taxon";
	 cxGrid1TableView1->NavigatorButtons->Delete->Enabled = false;
	 dbTaxonAction = dbaUPLOAD;
	 if (cxGrid1TableView2->CloneCount > 0) {
	   for (int i=0; i<cxGrid1TableView2->CloneCount; i++) {
		 ((TcxGridTableView*)((TcxGridLevel*)cxGrid1TableView2->Clones[i]->Level)->GridView)->NavigatorButtons->Append->Enabled = false;
		 ((TcxGridTableView*)((TcxGridLevel*)cxGrid1TableView2->Clones[i]->Level)->GridView)->NavigatorButtons->Delete->Enabled = false;
		 }
	   }
	 }
   cxGrid1TableView1->LayoutChanged(false);
   cxGrid1TableView1->Controller->FocusedRecordIndex = 0;
   FocusControl(cxGrid1);
}
//---------------------------------------------------------------------------

void __fastcall TNewTaxonForm::ShowValidator1Click(TObject *Sender)
{
   int idx = cxGrid1TableView1->Controller->FocusedRecordIndex;
   if (EditNeotomaTaxa->Taxa[idx].ValidatorID.IsEmpty()) {
	 Beep();
	 return;
	 }
   int ValidatorID = VariantToInt(EditNeotomaTaxa->Taxa[idx].ValidatorID, -1);
   if (ValidatorID != -1) {
	 NeotomaContactByID Contact(ipsJSONS1, TcpClient1);
	 Contact.AddParam(L"CONTACTID", ValidatorID);
	 StatusBar1->SimpleText = Contact.WebServiceName();
	 UnicodeString ContactName;
	 if (Contact.Execute()) {
	   if (Contact.Size() > 0) {
		 ContactName = Contact.Items[0].GivenNames + L" " + Contact.Items[0].FamilyName;
		 if (!Contact.Items[0].Suffix.IsEmpty())
		   ContactName += (L" " + Contact.Items[0].Suffix);
		 }
	   }
	 StatusBar1->SimpleText = L"";
	 MessageDlg(ContactName, mtInformation, TMsgDlgButtons() << mbOK, 0);
	 }
}
//---------------------------------------------------------------------------

void __fastcall TNewTaxonForm::PopupMenuPubIDPopup(TObject *Sender)
{
   int idx = cxGrid1TableView1->Controller->FocusedRecordIndex;
   switch (idx) {
	 case 0:
	   ShowPublication1->Visible = true;
	   PubDelete1->Visible = !EditingLocked;
	   PubDitto1->Visible = false;
	   break;
	 case 1:
	   ShowPublication1->Visible = false;
	   PubDelete1->Visible = !EditNeotomaTaxa->Taxa[1].PublicationID.IsEmpty();
	   PubDitto1->Visible = true;
	   break;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TNewTaxonForm::ShowPublication1Click(TObject *Sender)
{
   int idx = cxGrid1TableView1->Controller->FocusedRecordIndex;
   if (idx == 0) {
	 UnicodeString text;
	 int PubID = EditNeotomaTaxa->Taxa[0].PublicationID;
	 NeotomaPublicationsByPubID Publication(ipsJSONS1, TcpClient1);
	 StatusBar1->SimpleText = Publication.WebServiceName();
	 Publication.AddParam(L"PUBLICATIONID", PubID);
	 if (Publication.Execute()) {
	   if (Publication.Size() > 0)
		 text = Publication.Items[0].Citation;
	   }
	 StatusBar1->SimpleText = L"";
	 if (!text.IsEmpty()) {
	   ShowMemoForm = new TShowMemoForm(L"Reference", text, this);
	   ShowMemoForm->ShowModal();
	   delete ShowMemoForm;
	   }
	 }
}
//---------------------------------------------------------------------------

void __fastcall TNewTaxonForm::cxGrid1TableView1FocusedItemChanged(TcxCustomGridTableView *Sender,
		  TcxCustomGridTableItem *APrevFocusedItem, TcxCustomGridTableItem *AFocusedItem)

{
   int idx = cxGrid1TableView1->Controller->FocusedRecordIndex;
   if (AFocusedItem == txnAuthor && idx == 1)
	 cxGrid1TableView1->PopupMenu = PopupMenuAuthor;
   else if (AFocusedItem == txnPubID)
	 cxGrid1TableView1->PopupMenu = PopupMenuPubID;
   else if (AFocusedItem == txnEcolGroup && idx == 1)
	 cxGrid1TableView1->PopupMenu = PopupMenuEcolGroup;
   else if (AFocusedItem == txnValidator)
	 cxGrid1TableView1->PopupMenu = PopupMenuValidator;
   else
	 cxGrid1TableView1->PopupMenu = NULL;
}
//---------------------------------------------------------------------------

void __fastcall TNewTaxonForm::cxGrid1TableView1FocusedRecordChanged(TcxCustomGridTableView *Sender,
		  TcxCustomGridRecord *APrevFocusedRecord, TcxCustomGridRecord *AFocusedRecord,
		  bool ANewItemRecordFocusingChanged)
{
   if (AFocusedRecord != NULL) {
	 if (Sender->Controller->FocusedItem == txnAuthor) {
	   switch (AFocusedRecord->Index) {
		 case 0:
		   cxGrid1TableView1->PopupMenu = NULL;
		   break;
		 case 1:
		   cxGrid1TableView1->PopupMenu = PopupMenuAuthor;
		   break;
		 }
	   }
	 else if (Sender->Controller->FocusedItem == txnEcolGroup) {
	   switch (AFocusedRecord->Index) {
		 case 0:
		   cxGrid1TableView1->PopupMenu = NULL;
		   break;
		 case 1:
		   cxGrid1TableView1->PopupMenu = PopupMenuEcolGroup;
		   break;
		 }
	   }

	 cxGrid1TableView1->OptionsView->ExpandButtonsForEmptyDetails = (AFocusedRecord->Index == 0);
	 switch (AFocusedRecord->Index) {
	   case 0:
		 CheckUpdateTaxon(NULL);
		 cxGrid1TableView1->NavigatorButtons->CustomButtons->Items[0]->Hint = L"Update taxon";
		 break;
	   case 1:
		 CheckNewTaxonComplete();
		 cxGrid1TableView1->NavigatorButtons->CustomButtons->Items[0]->Hint = L"Upload new taxon";
		 break;
	   }
	 }
   else
	 cxGrid1TableView1->OptionsView->ExpandButtonsForEmptyDetails = true;
}
//---------------------------------------------------------------------------

void __fastcall TNewTaxonForm::PubDitto1Click(TObject *Sender)
{
   EditNeotomaTaxa->Taxa[1].PublicationID = EditNeotomaTaxa->Taxa[0].PublicationID;
   TaxaDataSource->DataChanged();
}
//---------------------------------------------------------------------------

void __fastcall TNewTaxonForm::PubDelete1Click(TObject *Sender)
{
   int idx = cxGrid1TableView1->Controller->FocusedRecordIndex;
   EditNeotomaTaxa->Taxa[idx].PublicationID.ChangeType(varEmpty);
   TaxaDataSource->DataChanged();
}
//---------------------------------------------------------------------------

void __fastcall TNewTaxonForm::AuthorDitto1Click(TObject *Sender)
{
   int idx = cxGrid1TableView1->Controller->FocusedRecordIndex;
   if (idx == 1) {
	 EditNeotomaTaxa->Taxa[1].Author = EditNeotomaTaxa->Taxa[0].Author;
	 TaxaDataSource->DataChanged();
	 }
}
//---------------------------------------------------------------------------

void __fastcall TNewTaxonForm::EcolGroupDitto1Click(TObject *Sender)
{
   int idx = cxGrid1TableView1->Controller->FocusedRecordIndex;
   if (idx == 1) {
	 EditNeotomaTaxa->Taxa[1].EcolSetsGroups = EditNeotomaTaxa->Taxa[0].EcolSetsGroups;
	 TaxaDataSource->DataChanged();
	 }
}
//---------------------------------------------------------------------------

// close button
void __fastcall TNewTaxonForm::cxButton3Click(TObject *Sender)
{
   if (dxTreeView1->Items->Count > 0) {
	 AllowReactivate = true;
	 UnDo();
	 }
}
//---------------------------------------------------------------------------

void __fastcall TNewTaxonForm::FormClose(TObject *Sender, TCloseAction &Action)
{
   Activated = false;
}
//---------------------------------------------------------------------------

void __fastcall TNewTaxonForm::PopupMenu1Popup(TObject *Sender)
{
   if (MarkedNode == NULL) {
	 Mark1->Visible = true;
	 Unmark1->Visible = false;
	 InsertChild1->Visible = false;
	 InsertSibling1->Visible = false;
	 InsertSynonym1->Visible = false;
	 }
   else if (MarkedNode == dxTreeView1->Selected) {
	 Mark1->Visible = false;
	 Unmark1->Visible = true;
	 InsertChild1->Visible = false;
	 InsertSibling1->Visible = false;
	 InsertSynonym1->Visible = false;
	 }
   else {
	 Mark1->Visible = true;
	 Unmark1->Visible = false;
	 int MarkedTaxonID = *((int*)MarkedNode->Data);
	 InsertChild1->Caption = L"Insert «" + TaxaMap[MarkedTaxonID].TaxonName + L"» as child";
	 InsertChild1->Visible = true;
	 InsertSibling1->Caption = L"Insert «" + TaxaMap[MarkedTaxonID].TaxonName + L"» as sibling";
	 InsertSibling1->Visible = true;
	 InsertSynonym1->Caption = L"Insert «" + TaxaMap[MarkedTaxonID].TaxonName + L"» as synonym";
	 InsertSynonym1->Visible = true;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TNewTaxonForm::Mark1Click(TObject *Sender)
{
   //MarkedTaxonID = *((int*)dxTreeView1->Selected->Data);
   MarkedNode = dxTreeView1->Selected;
   dxTreeView1->Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TNewTaxonForm::Unmark1Click(TObject *Sender)
{
   //MarkedTaxonID = 0;
   MarkedNode = NULL;
   dxTreeView1->Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TNewTaxonForm::InsertChild1Click(TObject *Sender)
{
   ChangeHigherTaxonID(naAddChild);
}
//---------------------------------------------------------------------------

void __fastcall TNewTaxonForm::InsertSibling1Click(TObject *Sender)
{
   ChangeHigherTaxonID(naInsert);
}
//---------------------------------------------------------------------------

void TNewTaxonForm::ChangeHigherTaxonID(TNodeAttachMode Mode)
{
   if (!Login->IsTaxonomyExpert) {
	 Beep();
	 return;
	 }
   if (MarkedNode == dxTreeView1->Selected) {
	 Beep();
	 return;
	 }

   int TaxonID = *((int*)MarkedNode->Data);
   NTMTAXONMAP *Taxon = &TaxaMap.find(TaxonID)->second;
   int HigherTaxonID = VariantToInt(Taxon->HigherTaxonID, -1);
   int NewHigherTaxonID;
   switch (Mode) {
	 case naAddChild:
	   NewHigherTaxonID = *((int*)dxTreeView1->Selected->Data);
	   break;
	 case naInsert:
	   if (dxTreeView1->Selected->Parent == NULL)
		 NewHigherTaxonID = TaxonID;
	   else
		 NewHigherTaxonID = *((int*)dxTreeView1->Selected->Parent->Data);
	   break;
	 }

   if (HigherTaxonID == NewHigherTaxonID) {
	 Beep();
	 return;
	 }

   Screen->Cursor = crHourGlass;
   dxTreeView1->Items->BeginUpdate();
   MarkedNode->MoveTo(dxTreeView1->Selected, Mode);

   bool error = false;
   UnicodeString ErrorMsg;
   UpdateData UpdateHigherTaxonID(L"UpdateTaxonHigherTaxonID", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
   StatusBar1->SimpleText = L"UpdateTaxonHigherTaxonID";
   UpdateHigherTaxonID.Add(L"TAXONID", TaxonID);
   UpdateHigherTaxonID.Add(L"HIGHERTAXONID", NewHigherTaxonID);
   if (UpdateHigherTaxonID.Post(ErrorMsg)) {
     Taxon->HigherTaxonID = NewHigherTaxonID;
	 int ValidatorID = Login->ContactID;
	 TDateTime ValidateDate = UTCDateTime();
	 UnicodeString ValidateDateStr = ValidateDate.FormatString(L"yyyy-mm-dd");
	 UpdateData UpdateTaxonValidation(L"UpdateTaxonValidation", 3, ipsHTTPS1, ipsJSONS1, TcpClient1);
	 StatusBar1->SimpleText = L"UpdateTaxonValidation";
	 UpdateTaxonValidation.Add(L"TAXONID", TaxonID);
	 UpdateTaxonValidation.Add(L"VALIDATORID", ValidatorID);
	 UpdateTaxonValidation.Add(L"VALIDATEDATE", ValidateDateStr);
	 if (UpdateTaxonValidation.Post(ErrorMsg)) {
	   Taxon->ValidatorID = ValidatorID;
	   Taxon->ValidateDate = ValidateDate;
	   }
	 else
	   error = true;
	 }
   else
	 error = true;

   if (error)
	 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
   else {
     dxTreeView1->AlphaSort();
	 UnicodeString msg = L"Success! Higher taxon of «" + Taxon->TaxonName +
	   L"» updated to «" + TaxaMap[NewHigherTaxonID].TaxonName + L"»";
	 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
	 }
   dxTreeView1->Items->EndUpdate();
   StatusBar1->SimpleText = L"";
   Screen->Cursor = crDefault;
}
//---------------------------------------------------------------------------

void __fastcall TNewTaxonForm::InsertSynonym1Click(TObject *Sender)
{
   UnicodeString ErrorMsg;
   if (!InsertSynonym(ErrorMsg)) {
	 StatusBar1->SimpleText = L"";
	 Screen->Cursor = crDefault;
	 if (!ErrorMsg.IsEmpty())
	   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 }
}
//---------------------------------------------------------------------------

bool TNewTaxonForm::InsertSynonym(UnicodeString& ErrorMsg)
{
   vector<int> newids;
   int InvalidTaxonID;
   int ValidTaxonID;
   int SynonymID;
   int SynonymTypeID;
   UnicodeString InvalidTaxonName;
   UnicodeString ValidTaxonName;
   UnicodeString msg;
   vector<int> VariableIDs;

   if (!Login->IsTaxonomyExpert) {
	 Beep();
	 return false;
	 }
   if (MarkedNode == dxTreeView1->Selected) {
	 Beep();
	 return false;
	 }

   InvalidTaxonID = *((int*)MarkedNode->Data);
   ValidTaxonID = *((int*)dxTreeView1->Selected->Data);
   NTMTAXONMAP *InvalidTaxon = &TaxaMap.find(InvalidTaxonID)->second;
   NTMTAXONMAP *ValidTaxon = &TaxaMap.find(ValidTaxonID)->second;
   InvalidTaxonName = VarToStr(InvalidTaxon->TaxonName);
   ValidTaxonName = VarToStr(ValidTaxon->TaxonName);

   msg = L"Make «" + InvalidTaxonName + L"» a synonym of «" + ValidTaxonName + L"»?";
   if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrNo) {
	 return false;
	 }

   Screen->Cursor = crHourGlass;
   // check if taxon has any children
   int nChildren = TaxonChildCount(InvalidTaxonID);
   if (nChildren == -1) {
	 return false;
	 }
   else if (nChildren > 0) {
	 ErrorMsg = L"Taxon «" + InvalidTaxonName + L"» has " + IntToStr(nChildren);
	 ErrorMsg += (nChildren == 1) ? L" child" : L" children";
	 ErrorMsg += L", which must be synonymized first.";
	 return false;
	 }

   // check if taxon has any synonyms
   int nSynonyms = SynonymCount(InvalidTaxonID);
   if (nSynonyms == -1)
	 return false;
   else if (nSynonyms > 0) {
	 ErrorMsg = L"\nTaxon «" + InvalidTaxonName + L"» has " + IntToStr(nSynonyms);
	 ErrorMsg += (nSynonyms == 1) ? L" synonym" : L" synonyms";
	 ErrorMsg += L", which must be deleted first.";
	 return false;
	 }

   if (GetNeotomaSynonymTypes()) {
	 Screen->Cursor = crDefault;
	 SelectSynonymTypeForm = new TSelectSynonymTypeForm(NeotomaSynonymTypes, this);
	 int rv = SelectSynonymTypeForm->ShowModal();
	 SynonymTypeID = SelectSynonymTypeForm->SynonymTypeID;
	 delete SelectSynonymTypeForm;
	 if (rv == mrCancel) {
	   MessageDlg(L"Synonymization canceled!", mtInformation, TMsgDlgButtons() << mbOK, 0);
	   return false;
	   }
	 }
   else
	 return false;

   Screen->Cursor = crHourGlass;
   // add [] to invalid TaxonCode
   UnicodeString InvalidTaxonCode = L"[" + VarToStr(InvalidTaxon->TaxonCode) + L"]";
   UpdateData UpdateTaxonCode(L"UpdateTaxonCode", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
   StatusBar1->SimpleText = L"UpdateTaxonCode";
   UpdateTaxonCode.Add(L"TAXONID", InvalidTaxonID);
   UpdateTaxonCode.Add(L"TAXONCODE", InvalidTaxonCode);
   if (UpdateTaxonCode.Post(ErrorMsg))
	 InvalidTaxon->TaxonCode = InvalidTaxonCode;
   else
	 return false;

   // set invalid VALID = false
   UpdateData UpdateTaxonValidity(L"UpdateTaxonValidity", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
   StatusBar1->SimpleText = L"UpdateTaxonValidity";
   UpdateTaxonValidity.Add(L"TAXONID", InvalidTaxonID);
   UpdateTaxonValidity.Add(L"VALID", false);
   if (UpdateTaxonValidity.Post(ErrorMsg))
	 InvalidTaxon->Valid = false;
   else
	 return false;


   // set invalid HigherTaxonID = NULL
   UpdateData UpdateTaxonHigherIDToNull(L"UpdateTaxonHigherTaxonIDToNull", 1, ipsHTTPS1, ipsJSONS1, TcpClient1);
   StatusBar1->SimpleText = L"UpdateTaxonHigherIDToNull";
   UpdateTaxonHigherIDToNull.Add(L"TAXONID", InvalidTaxonID);
   if (UpdateTaxonHigherIDToNull.Post(ErrorMsg))
	 InvalidTaxon->HigherTaxonID.ChangeType(varEmpty);
   else
	 return false;


   // update validator and date
   if (Login->IsTaxonomyExpert) {
	 int ValidatorID = Login->ContactID;
	 //TDateTime ValidateDate = Today();
	 TDateTime ValidateDate = UTCDateTime();
	 UnicodeString ValidateDateStr = ValidateDate.FormatString(L"yyyy-mm-dd");
	 UpdateData UpdateTaxonValidation(L"UpdateTaxonValidation", 3, ipsHTTPS1, ipsJSONS1, TcpClient1);
	 StatusBar1->SimpleText = L"UpdateTaxonValidation";
	 UpdateTaxonValidation.Add(L"TAXONID", InvalidTaxonID);
	 UpdateTaxonValidation.Add(L"VALIDATORID", ValidatorID);
	 UpdateTaxonValidation.Add(L"VALIDATEDATE", ValidateDateStr);
	 if (UpdateTaxonValidation.Post(ErrorMsg)) {
	   InvalidTaxon->ValidatorID = ValidatorID;
	   InvalidTaxon->ValidateDate = ValidateDate;
	   }
	 else
	   return false;
	 }

   // insert new record in Synonyms table
   InsertData InsertSynonym(L"InsertSynonym", 3, ipsHTTPS1, ipsJSONS1, TcpClient1);
   StatusBar1->SimpleText = L"InsertSynonym";
   InsertSynonym.Add(L"INVALIDTAXONID", InvalidTaxonID, -1);
   InsertSynonym.Add(L"VALIDTAXONID", ValidTaxonID, -1);
   InsertSynonym.Add(L"SYNONYMTYPEID", SynonymTypeID, -1);
   InsertSynonym.PostData();
   if (InsertSynonym.Post(newids, ErrorMsg)) {
	 if (newids.size() == 1)
	   SynonymID = newids[0];
	 else
	   return false;
	 }
   else
	 return false;

   // change any TaxonIDs in SpecimenDates table
   NeotomaSpecimenDatesByTaxonID SpecimenDates(ipsJSONS1, TcpClient1);
   SpecimenDates.AddParam(L"TAXONID", InvalidTaxonID);
   StatusBar1->SimpleText = SpecimenDates.WebServiceName();
   if (SpecimenDates.Execute()) {
	 if (SpecimenDates.Size() > 0) {
	   UpdateData UpdateTaxonID(L"UpdateSpecimenDateTaxonID", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
	   StatusBar1->SimpleText = L"UpdateSpecimenDateTaxonID";
	   UpdateTaxonID.Add(L"OLDTAXONID", InvalidTaxonID);
	   UpdateTaxonID.Add(L"NEWTAXONID", ValidTaxonID);
	   if (!UpdateTaxonID.Post(ErrorMsg))
		 return false;
	   }
	 }

   // Get any variables with the InvalidTaxonID
   NeotomaVariablesByTaxonID InvalidVariables(ipsJSONS1, TcpClient1);
   InvalidVariables.AddParam(L"TAXONID", InvalidTaxonID);
   StatusBar1->SimpleText = InvalidVariables.WebServiceName();
   if (!InvalidVariables.Execute())
	 return false;
   if (InvalidVariables.Size() > 0) {
	 // get number of data records with InvalidTaxonID
	 NeotomaTaxonDataRecordsCount InvalidTaxonDataCount(ipsJSONS1, TcpClient1);

	 //InvalidTaxonDataCount.AddParam(L"TAXONID", InvalidTaxonID);
	 //StatusBar1->SimpleText = InvalidTaxonDataCount.WebServiceName();
	 //if (!InvalidTaxonDataCount.Execute())
	 //  return false;(ipsJSONS1, TcpClient1);

	 InvalidTaxonDataCount.AddParam(L"TAXONID", InvalidTaxonID);
	 StatusBar1->SimpleText = InvalidTaxonDataCount.WebServiceName();
	 if (!InvalidTaxonDataCount.Execute())
	   return false;

	 int nTaxonDataRecs;
	 if (InvalidTaxonDataCount.Size() == 1)
	   nTaxonDataRecs = InvalidTaxonDataCount.Items[0];
	 else
	   return false;
	 if (nTaxonDataRecs > 0) {
	   // get all datasets with InvalidTaxonID
	   NeotomaDatasetIDsByTaxonID Datasets(ipsJSONS1, TcpClient1);
	   Datasets.AddParam(L"TAXONID", InvalidTaxonID);
	   StatusBar1->SimpleText = Datasets.WebServiceName();
	   if (!Datasets.Execute())
		 return false;
	   // For variables with InvalidTaxonID, does an equivalent variable with ValidTaxonID exist?
	   for (unsigned int i=0; i<InvalidVariables.Size(); i++) {
		 // Does variable have data?
		 int InvalidVariableID = InvalidVariables.Items[i].VariableID;
		 NeotomaVariableDataRecordsCount InvalidVariableDataCount(ipsJSONS1, TcpClient1);
		 InvalidVariableDataCount.AddParam(L"VARIABLEID", InvalidVariableID);
		 StatusBar1->SimpleText = InvalidVariableDataCount.WebServiceName();
		 if (!InvalidVariableDataCount.Execute())
		   return false;
		 int nVarDataRecs;
		 if (InvalidVariableDataCount.Size() == 1)
		   nVarDataRecs = InvalidVariableDataCount.Items[0];
		 else
		   return false;
		 if (nVarDataRecs == 0) {  // variable has no data, so delete variable
		   DeleteData DeleteVariable(L"DeleteVariableByVariableID", 1, ipsHTTPS1, ipsJSONS1, TcpClient1);
		   StatusBar1->SimpleText = L"DeleteVariableByVariableID";
		   DeleteVariable.Add(L"VARIABLEID", InvalidVariableID);
		   if (!DeleteVariable.Post(ErrorMsg))
			 return false;
		   }
		 else {  // variable has data
		   // see if there is an equivalent variable with the ValidTaxonID
		   NeotomaVariableByComponents ValidVariable(ipsJSONS1, TcpClient1);
		   ValidVariable.AddParam(L"TAXONID", ValidTaxonID);
		   if (InvalidVariables.Items[i].VariableElementID != -1)
			 ValidVariable.AddParam(L"VARIABLEELEMENTID", InvalidVariables.Items[i].VariableElementID);
		   if (InvalidVariables.Items[i].VariableUnitsID != -1)
			 ValidVariable.AddParam(L"VARIABLEUNITSID", InvalidVariables.Items[i].VariableUnitsID);
		   if (InvalidVariables.Items[i].VariableContextID != -1)
			 ValidVariable.AddParam(L"VARIABLECONTEXTID", InvalidVariables.Items[i].VariableContextID);
		   StatusBar1->SimpleText = ValidVariable.WebServiceName();
		   if (!ValidVariable.Execute())
			 return false;
		   if (ValidVariable.Size() > 0) {  // a valid variable exists with same components
			 // Change data records to variable with ValidTaxonID.
			 UpdateData UpdateDataVariableID(L"UpdateDataVariableID", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
			 StatusBar1->SimpleText = L"UpdateDataVariableID";
			 UpdateDataVariableID.Add(L"OLDVARIABLEID", InvalidVariableID);
			 UpdateDataVariableID.Add(L"NEWVARIABLEID", ValidVariable.Items[0].VariableID);
			 if (!UpdateDataVariableID.Post(ErrorMsg))
			   return false;
			 // Delete variable with InvalidTaxonID
			 DeleteData DeleteVariable(L"DeleteVariableByVariableID", 1, ipsHTTPS1, ipsJSONS1, TcpClient1);
			 StatusBar1->SimpleText = L"DeleteVariableByVariableID";
			 DeleteVariable.Add(L"VARIABLEID", InvalidVariableID);
			 if (!DeleteVariable.Post(ErrorMsg))
			   return false;
			 }
		   else {  // a valid variable does not exist with same components
			 // Change variable InvalidTaxonID to the ValidTaxonID
			 UpdateData UpdateVariableTaxonID(L"UpdateVariableTaxonID", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
			 StatusBar1->SimpleText = L"UpdateVariableTaxonID";
			 UpdateVariableTaxonID.Add(L"VARIABLEID", InvalidVariableID);
			 UpdateVariableTaxonID.Add(L"NEWTAXONID", ValidTaxonID);
			 if (!UpdateVariableTaxonID.Post(ErrorMsg))
			   return false;
			 }
		   }
		 }
	   // For each DatasetID with InvalidTaxonID, add record to Synonymy table
	   InsertData InsertSynonymy(L"InsertSynonymy", 5, ipsHTTPS1, ipsJSONS1, TcpClient1);
	   UnicodeString DateStr = UTCDateTime().FormatString(L"yyyy-mm-dd");
	   for (unsigned int i=0; i<Datasets.Size(); i++) {
		 InsertSynonymy.Add(L"DATASETID", Datasets.Items[i], -1);
		 InsertSynonymy.Add(L"TAXONID", ValidTaxonID, -1);
		 InsertSynonymy.Add(L"REFTAXONID", InvalidTaxonID, -1);
		 InsertSynonymy.Add(L"CONTACTID", Login->ContactID, -1);
		 InsertSynonymy.Add(L"DATESYNONYMIZED", DateStr);
		 }
	   InsertSynonymy.PostData();
	   if (InsertSynonymy.Post(newids, ErrorMsg)) {
		 if (newids.size() != Datasets.Size()) {
		   ErrorMsg = L"Error uploading records to Synonymy table.";
		   ErrorMsg = L"\nNumber of Datasets = " + IntToStr((int)Datasets.Size());
		   ErrorMsg = L"\nSynonymy records uploaded = " + IntToStr((int)newids.size());
		   return false;
		   }
		 }
	   else
		 return false;
	   }
	 else {  // nTaxonDataRecs == 0, Delete any variables with InvalidTaxonID
	   DeleteData DeleteVariables(L"DeleteVariablesByTaxonID", 1, ipsHTTPS1, ipsJSONS1, TcpClient1);
	   StatusBar1->SimpleText = L"DeleteVariablesByTaxonID";
	   DeleteVariables.Add(L"TAXONID", InvalidTaxonID);
	   if (!DeleteVariables.Post(ErrorMsg))
		 return false;
	   }
	 }

   // delete node in tree
   for (int i=0; i<dxTreeView1->Items->Count; i++) {
	 TTreeNode* Node = dxTreeView1->Items->Item[i];
	 int ID = *((int*)Node->Data);
	 if (ID == InvalidTaxonID) {
	   dxTreeView1->Items->Delete(Node);
	   TaxaMap.erase(InvalidTaxonID);
	   break;
	   }
	 }

   ShowTaxonMetaData(ValidTaxonID);
   StatusBar1->SimpleText = L"";
   Screen->Cursor = crDefault;
   msg = L"Success! Taxon «" + InvalidTaxonName + L"» made synynom of «" + ValidTaxonName +
		 L"». SynonymID = " + IntToStr(SynonymID) + L".";
   MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
   return true;
}
//---------------------------------------------------------------------------

void __fastcall TNewTaxonForm::sySynTypeIDPropertiesInitPopup(TObject *Sender)
{
   bool success = true;
   if (AdvColumnGrid1->RowCount <= 2) {
	 Screen->Cursor = crHourGlass;
	 if (GetNeotomaSynonymTypes()) {
	   AdvColumnGrid1->RowCount = NeotomaSynonymTypes.size() + 1;
	   map<int,UnicodeString>::iterator itr;
	   map<int,UnicodeString>::iterator begin = NeotomaSynonymTypes.begin();
	   map<int,UnicodeString>::iterator end = NeotomaSynonymTypes.end();
	   int row = 1;
	   for (itr = begin; itr != end; itr++) {
		 AdvColumnGrid1->Cells[0][row] = itr->first;
		 AdvColumnGrid1->Cells[1][row++] = itr->second;
		 }
	   }
	 else
	   success = false;
     StatusBar1->SimpleText = L"";
	 Screen->Cursor = crDefault;
	 if (!success)
	   return;
	 }

   int idx1 = cxGrid1TableView1->Controller->FocusedRecordIndex;
   int idx2 = SynonymDataController(idx1)->FocusedRecordIndex;
   if (EditNeotomaTaxa->Taxa[idx1].Synonyms[idx2].SynonymTypeID.IsEmpty())
	 AdvColumnGrid1->Row = 1;
   else {
	 int SynonymID = VariantToInt(EditNeotomaTaxa->Taxa[idx1].Synonyms[idx2].SynonymTypeID, -1);
	 for (int row=1; row<AdvColumnGrid1->RowCount; row++) {
	   if (SynonymID == AdvColumnGrid1->Cells[0][row].ToInt()) {
		 AdvColumnGrid1->Row = row;
		 break;
		 }
	   }
	 }
}
//---------------------------------------------------------------------------

// SynonymTypes grid
void __fastcall TNewTaxonForm::AdvColumnGrid1ClickCell(TObject *Sender, int ARow,
		  int ACol)
{
   if (ARow == 0) return;
   int idx1 = cxGrid1TableView1->Controller->FocusedRecordIndex;
   int idx2 = SynonymDataController(idx1)->FocusedRecordIndex;
   EditNeotomaTaxa->Taxa[idx1].Synonyms[idx2].SynonymTypeID = AdvColumnGrid1->Cells[0][ARow].ToInt();
   SynonymDataSource->DataChanged();
   ((TcxPopupEdit*)(SynonymGridView(idx1)->Controller->EditingController->Edit))->DroppedDown = false;
   CheckUpdateSynonym(NULL);
}
//---------------------------------------------------------------------------

void __fastcall TNewTaxonForm::cxGrid1FocusedViewChanged(TcxCustomGrid *Sender, TcxCustomGridView *APrevFocusedView,
		  TcxCustomGridView *AFocusedView)
{
   if (AFocusedView->IsDetail)
	 SynonymGridView()->NavigatorButtons->Append->Enabled = !EditingLocked;
}
//---------------------------------------------------------------------------

// Cancel SynonymType
void __fastcall TNewTaxonForm::cxButton5Click(TObject *Sender)
{
   ((TcxPopupEdit*)(SynonymGridView()->Controller->EditingController->Edit))->DroppedDown = false;
}
//---------------------------------------------------------------------------

// add new SynonymType to Neotoma
void __fastcall TNewTaxonForm::cxButton10Click(TObject *Sender)
{
   NewSynTypeForm = new TNewSynTypeForm(AdvColumnGrid1, this);
   NewSynTypeForm->ShowModal();
   delete NewSynTypeForm;
}
//---------------------------------------------------------------------------

void __fastcall TNewTaxonForm::cxGrid1TableView2FocusedRecordChanged(TcxCustomGridTableView *Sender,
		  TcxCustomGridRecord *APrevFocusedRecord, TcxCustomGridRecord *AFocusedRecord,
		  bool ANewItemRecordFocusingChanged)
{
   if (AFocusedRecord == NULL)
	 return;

   int idx1 = cxGrid1TableView1->Controller->FocusedRecordIndex;
   NTMSYNONYMREC& LastSyn = EditNeotomaTaxa->Taxa[idx1].Synonyms.back();
   if (LastSyn.TaxonID.IsEmpty())
	 SynonymGridView()->NavigatorButtons->CustomButtons->Items[0]->Hint = L"Upload synonym";
   else
	 SynonymGridView()->NavigatorButtons->CustomButtons->Items[0]->Hint = L"Update synonym";

   if (!EditingLocked) {
	 CheckUpdateSynonym(NULL);
	 bool empty = true;
	 if (!LastSyn.TaxonCode.IsEmpty())
	   empty = false;
	 else if (!LastSyn.TaxonName.IsEmpty())
	   empty = false;
	 else if (!LastSyn.Author.IsEmpty())
	   empty = false;
	 else if (!LastSyn.SynonymTypeID.IsEmpty())
	   empty = false;
	 else if (!LastSyn.PublicationID.IsEmpty())
	   empty = false;
	 else if (!LastSyn.Notes.IsEmpty())
	   empty = false;
	 SynonymGridView()->NavigatorButtons->Append->Enabled = !empty;
	 }
   else
	 SynonymGridView()->NavigatorButtons->Append->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TNewTaxonForm::cxGrid1TableView2DataControllerAfterPost(TcxCustomDataController *ADataController)
{
   SynonymGridView()->NavigatorButtons->Append->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TNewTaxonForm::cxGrid1TableView1DataControllerDetailExpanding(TcxCustomDataController *ADataController,
		  int ARecordIndex, bool &AAllow)
{
   if (ARecordIndex == 1) {     // don't allow new taxon record synonyms to be expanded
	 Beep();
	 AAllow = false;
	 }
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

__fastcall TNeotomaEditTaxaForm::TNeotomaEditTaxaForm(TComponent* Owner)
	: TNewTaxonForm(Owner)
{
   from_ss = false;
   Panel7->Visible = false;
   Panel8->Visible = false;
   Label3->Caption = L"New Taxon Name";
   if (!Login->IsTaxonomyExpert) {
	 MessageDlg(L"Steward must have «Taxonomy Expert» status to edit Taxa table.\nTable will be read only.",
	   mtInformation, TMsgDlgButtons() << mbOK, 0);
	 Panel9->Visible = false;
	 cxButton9->Visible = false;
	 dxTreeView1->ReadOnly = true;
	 }
}
//---------------------------------------------------------------------------

// close button
void __fastcall TNeotomaEditTaxaForm::cxButton3Click(TObject *Sender)
{
   AllowReactivate = false;
}
//---------------------------------------------------------------------------

// validate
void __fastcall TNewTaxonForm::cxButton17Click(TObject *Sender)
{
   if (SameText(cxButton17->Hint, L"Show unvalidated taxa")) {
	 Screen->Cursor = crHourGlass;
	 for (int i=0; i<dxTreeView1->Items->Count; i++) {
	   TTreeNode* Node = dxTreeView1->Items->Item[i];
	   int TaxonID = *((int*)Node->Data);
	   if (TaxaMap[TaxonID].ValidatorID.IsEmpty()) {
		 UnvalidatedTaxa.insert(TaxonID);
		 TTreeNode* Parent = Node->Parent;
		 while (Parent != NULL) {
		   Parent->Expand(false);
		   Parent = Parent->Parent;
		   }
		 }
	   }
	 Screen->Cursor = crDefault;
	 dxTreeView1->SelectedIndex = 0;
     dxTreeView1->Selected->MakeVisible();
	 cxButton17->Hint = L"Hide unvalidated taxa";
	 }
   else {
	 UnvalidatedTaxa.clear();
	 cxButton17->Hint = L"Show unvalidated taxa";
	 }
   dxTreeView1->Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TNewTaxonForm::ipsHTTPS1SSLServerAuthentication(TObject *Sender, TipsHTTPSSSLServerAuthenticationEventParams *e)

{
   /*
   ShowMessage(L"ipsHTTPS1SSLServerAuthentication");
   ShowMemoForm = new TShowMemoForm(L"CertEncoded", e->CertEncoded, NULL);
   ShowMemoForm->ShowModal();
   delete ShowMemoForm;
   ShowMemoForm = new TShowMemoForm(L"CertSubject", e->CertSubject, NULL);
   ShowMemoForm->ShowModal();
   delete ShowMemoForm;
   ShowMemoForm = new TShowMemoForm(L"CertIssuer", e->CertIssuer, NULL);
   ShowMemoForm->ShowModal();
   delete ShowMemoForm;
   ShowMemoForm = new TShowMemoForm(L"Status", e->Status, NULL);
   ShowMemoForm->ShowModal();
   delete ShowMemoForm;
   if (e->Accept)
	 ShowMessage(L"e->Accept = true");
   else
	 ShowMessage(L"e->Accept = false");
   */
}
//---------------------------------------------------------------------------

void __fastcall TNewTaxonForm::ipsJSONS1SSLServerAuthentication(TObject *Sender, TipsJSONSSSLServerAuthenticationEventParams *e)
{
   e->Accept = true;
}
//---------------------------------------------------------------------------

