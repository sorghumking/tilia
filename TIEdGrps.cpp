//---------------------------------------------------------------------------
#include <vcl.h>
#include "pch.h"
#pragma hdrstop

#include "TIEdGrps.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxClasses"
#pragma link "cxControls"
#pragma link "cxCustomData"
#pragma link "cxData"
#pragma link "cxDataStorage"
#pragma link "cxEdit"
#pragma link "cxFilter"
#pragma link "cxGraphics"
#pragma link "cxGrid"
#pragma link "cxGridCustomTableView"
#pragma link "cxGridCustomView"
#pragma link "cxGridLevel"
#pragma link "cxGridTableView"
#pragma link "cxStyles"
#pragma link "cxTextEdit"
#pragma link "cxMaskEdit"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxNavigator"
#pragma link "cxContainer"
#pragma link "cxDropDownEdit"
#pragma link "cxLabel"
#pragma link "cxButtons"
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
#pragma link "dxSkinOffice2016Colorful"
#pragma link "dxSkinOffice2016Dark"
#pragma link "dxSkinVisualStudio2013Blue"
#pragma link "dxSkinVisualStudio2013Dark"
#pragma link "dxSkinVisualStudio2013Light"
#pragma resource "*.dfm"

TEditGroupsForm *EditGroupsForm;
//---------------------------------------------------------------------------

TTaxaEcolGroups::TTaxaEcolGroups(vector<TAXAECOLGROUPS>* TaxaEcolGroups)
{
   Items = *TaxaEcolGroups;
}
//---------------------------------------------------------------------------

vector<TAXAECOLGROUPS>::pointer TTaxaEcolGroups::GetTaxaEcolGroup(int AIndex)
{
  return &Items[AIndex];
}
//---------------------------------------------------------------------------

void __fastcall TTaxaEcolGroups::Clear(void)
{
  Items.clear();
}
//---------------------------------------------------------------------------

void __fastcall TTaxaEcolGroups::Add(TAXAECOLGROUPS& TaxaEcolGroup)
{
   Items.push_back(TaxaEcolGroup);
}
//---------------------------------------------------------------------------

void TTaxaEcolGroups::Delete(int AIndex)
{
   vector<TAXAECOLGROUPS>::iterator itr = Items.begin() + AIndex;
   Items.erase(itr);
}
//---------------------------------------------------------------------------

void TTaxaEcolGroups::Insert(int AIndex, TAXAECOLGROUPS& TaxaEcolGroup)
{
   vector<TAXAECOLGROUPS>::iterator itr = Items.begin() + AIndex;
   Items.insert(itr, TaxaEcolGroup);
}
//---------------------------------------------------------------------------

__fastcall TTaxaGroupDataSource::TTaxaGroupDataSource(TTaxaEcolGroups* ACategoryList)
{
  FTaxaEcolGroups = ACategoryList;
}
//---------------------------------------------------------------------------

int __fastcall TTaxaGroupDataSource::GetRecordCount(void)
{
  return(FTaxaEcolGroups->Count());
}
//---------------------------------------------------------------------------

Variant __fastcall TTaxaGroupDataSource::GetValue(void * ARecordHandle, void * AItemHandle)
{
  /*
  int AColumnId = GetDefaultItemID(int(AItemHandle));
  GROUPCATEGORY *Category = (GROUPCATEGORY*)MasterDataSource->GroupCategoryList->Categories[GetMasterRecordIndex()];
  //ECOLGROUP *EcolGroup = (ECOLGROUP*)Category->EcolGroups->Items[(int)ARecordHandle];
  vector<ECOLGROUP>::pointer EcolGroup = &Category->EcolGroups[(int)ARecordHandle];
  */

  int AColumnId = GetDefaultItemID((int)AItemHandle);
  vector<TAXAECOLGROUPS>::pointer TaxaEcolGroupPtr = FTaxaEcolGroups->TaxaEcolGroup[(int)ARecordHandle];
  Variant Result;
  switch (AColumnId) {
    case IndexOfcaCategoryCode:
	  Result = TaxaEcolGroupPtr->TaxaGroup.Code; break;
    case IndexOfcaCategoryName:
      Result = TaxaEcolGroupPtr->TaxaGroup.Name; break;
  }
  return (Result);
}
//---------------------------------------------------------------------------

void __fastcall TTaxaGroupDataSource::DeleteRecord(void * ARecordHandle)
{
  FTaxaEcolGroups->Delete((int)ARecordHandle);
  DataChanged();
}
//---------------------------------------------------------------------------

void * __fastcall TTaxaGroupDataSource::InsertRecord(void * ARecordHandle)
{
  TAXAECOLGROUPS TaxaEcolGroup;
  FTaxaEcolGroups->Insert((int)ARecordHandle, TaxaEcolGroup);
  TcxDataRecordHandle* Result = (TcxDataRecordHandle*)ARecordHandle;
  DataChanged();
  return (Result);
}
//---------------------------------------------------------------------------

void * __fastcall TTaxaGroupDataSource::AppendRecord(void)
{
/*
  GROUPCATEGORY *Category = (GROUPCATEGORY*)MasterDataSource->GroupCategoryList->Categories[GetMasterRecordIndex()];
  ECOLGROUP EcolGroup;
  EcolGroup.Code = DataController->GetDisplayText(-1,0);
  EcolGroup.Name = DataController->GetDisplayText(-1,1);

  Category->EcolGroups.push_back(EcolGroup);
  void* Result = (TcxDataRecordHandle*)&Category->EcolGroups.back();

  DataChanged();
  return (Result);
*/
  TcxDataRecordHandle* Result = (TcxDataRecordHandle*)FTaxaEcolGroups->Count();
  TAXAECOLGROUPS TaxaEcolGroup;
  FTaxaEcolGroups->Add(TaxaEcolGroup);
  DataChanged();

  //Controller->FocusedColumnIndex = 0;

  return (Result);

  /*
  TcxDataRecordHandle* Result = (TcxDataRecordHandle*)FTaxa->Count;
  TAXON* Taxon = new TAXON;
  FTaxa->Add(Taxon);
  return (Result);
  */
}
//---------------------------------------------------------------------------

void __fastcall TTaxaGroupDataSource::SetValue(void * ARecordHandle, void * AItemHandle, const Variant &AValue)
{
  Variant Blank;
  int AColumnId = GetDefaultItemID((int)AItemHandle);
  TAXAECOLGROUPS* TaxaEcolGroupPtr = FTaxaEcolGroups->TaxaEcolGroup[(int)ARecordHandle];
  switch (AColumnId) {
	case IndexOfcaCategoryCode:
	  TaxaEcolGroupPtr->TaxaGroup.Code = VarToStr(AValue);
	  break;
	case IndexOfcaCategoryName:
	  TaxaEcolGroupPtr->TaxaGroup.Name = VarToStr(AValue);
	  break;
	}
}
//---------------------------------------------------------------------------

int __fastcall TEcolGroupDataSource::GetRecordCount(void)
{
  int Result = 0;
  if (GetMasterRecordIndex() >= 0) {
	TAXAECOLGROUPS *TaxaEcolGroupPtr = (TAXAECOLGROUPS*)MasterDataSource->TaxaEcolGroups->TaxaEcolGroup[GetMasterRecordIndex()];
	//Result = Category->EcolGroups->Count;
	Result = TaxaEcolGroupPtr->EcolGroups.size();
    }
  return (Result);
}
//---------------------------------------------------------------------------

Variant __fastcall TEcolGroupDataSource::GetValue(void * ARecordHandle, void * AItemHandle)
{
  int AColumnId = GetDefaultItemID(int(AItemHandle));
  TAXAECOLGROUPS *TaxaEcolGroupPtr = (TAXAECOLGROUPS*)MasterDataSource->TaxaEcolGroups->TaxaEcolGroup[GetMasterRecordIndex()];
  //ECOLGROUP *EcolGroup = (ECOLGROUP*)Category->EcolGroups->Items[(int)ARecordHandle];
  vector<CODENAME>::pointer EcolGroup = &TaxaEcolGroupPtr->EcolGroups[(int)ARecordHandle];
  Variant Result;
  if (AColumnId == IndexOfegEcolGroupCode)
	Result = EcolGroup->Code;
	//Result = EcolGroup.Code;
  else if (AColumnId == IndexOfegEcolGroupName)
	Result = EcolGroup->Name;
	//Result = EcolGroup.Name;
  return (Result);
}
//---------------------------------------------------------------------------

void __fastcall TEcolGroupDataSource::SetValue(void * ARecordHandle, void * AItemHandle, const Variant &AValue)
{
  Variant Blank;
  int AColumnId = GetDefaultItemID((int)AItemHandle);
  TAXAECOLGROUPS *TaxaEcolGroupPtr = (TAXAECOLGROUPS*)MasterDataSource->TaxaEcolGroups->TaxaEcolGroup[GetMasterRecordIndex()];

  vector<CODENAME>::pointer EcolGroup = &TaxaEcolGroupPtr->EcolGroups[(int)ARecordHandle];
  switch (AColumnId) {
    case IndexOfcaCategoryCode:
	  EcolGroup->Code = (AValue.IsNull()) ? Blank : AValue;
	  break;
	case IndexOfcaCategoryName:
	  EcolGroup->Name = (AValue.IsNull()) ? Blank : AValue;
	  break;
	}
}
//---------------------------------------------------------------------------

void * __fastcall TEcolGroupDataSource::AppendRecord(void)
{
  TAXAECOLGROUPS *TaxaEcolGroupPtr = (TAXAECOLGROUPS*)MasterDataSource->TaxaEcolGroups->TaxaEcolGroup[GetMasterRecordIndex()];
  CODENAME EcolGroup;
  EcolGroup.Code = DataController->GetDisplayText(-1,0);
  EcolGroup.Name = DataController->GetDisplayText(-1,1);

  TaxaEcolGroupPtr->EcolGroups.push_back(EcolGroup);
  void* Result = (TcxDataRecordHandle*)&TaxaEcolGroupPtr->EcolGroups.back();

  DataChanged();
  return (Result);
}
//---------------------------------------------------------------------------

/*
void __fastcall TEcolGroupDataSource::Notify(void * Ptr, TListNotification Action)
{
  DataChanged();
}
//---------------------------------------------------------------------------
*/

void * __fastcall TEcolGroupDataSource::InsertRecord(void * ARecordHandle)
{
  TAXAECOLGROUPS *TaxaEcolGroupPtr = (TAXAECOLGROUPS*)MasterDataSource->TaxaEcolGroups->TaxaEcolGroup[GetMasterRecordIndex()];
  //ECOLGROUP* EcolGroup = new ECOLGROUP();
  CODENAME EcolGroup;
  //Category->EcolGroups->Insert((int)ARecordHandle, EcolGroup);
  vector<CODENAME>::iterator itr = TaxaEcolGroupPtr->EcolGroups.begin() + (int)ARecordHandle;
  TaxaEcolGroupPtr->EcolGroups.insert(itr, EcolGroup);
  void * Result = ARecordHandle;
  DataChanged();
  return (Result);
}
//---------------------------------------------------------------------------

void __fastcall TEcolGroupDataSource::DeleteRecord(void * ARecordHandle)
{
  TAXAECOLGROUPS *TaxaEcolGroupPtr = (TAXAECOLGROUPS*)MasterDataSource->TaxaEcolGroups->TaxaEcolGroup[GetMasterRecordIndex()];
  //Category->EcolGroups->Delete((int)ARecordHandle);
  vector<CODENAME>::iterator itr = TaxaEcolGroupPtr->EcolGroups.begin() + (int)ARecordHandle;
  //Category->EcolGroups->Delete((int)ARecordHandle);
  TaxaEcolGroupPtr->EcolGroups.erase(itr);
  DataChanged();
}
//---------------------------------------------------------------------------

int TEcolGroupDataSource::GetMasterRecordIndex()
{
  return (DataController->GetMasterRecordIndex());
}
//---------------------------------------------------------------------------

__fastcall TEditGroupsForm::TEditGroupsForm(vector<TAXAECOLGROUPS>* TaxaEcolGroupsPtr, TComponent* Owner)
		: TForm(Owner)
{
   //OriginalGroupCategoryList = group_category_list;
   OriginalTaxaEcolGroupsPtr = TaxaEcolGroupsPtr;
   TaxaEcolGroupList = new TTaxaEcolGroups(TaxaEcolGroupsPtr);
   TaxaGroupDataSource = new TTaxaGroupDataSource(TaxaEcolGroupList);
   EcolGroupDataSource = new TEcolGroupDataSource(TaxaGroupDataSource);
   GenerateGroupCategoryColumns();
}
//---------------------------------------------------------------------------

void __fastcall TEditGroupsForm::FormDestroy(TObject *Sender)
{
   delete TaxaEcolGroupList;
   delete TaxaGroupDataSource;
   delete EcolGroupDataSource;
}
//---------------------------------------------------------------------------

void __fastcall TEditGroupsForm::GenerateGroupCategoryColumns()
{
   caCategoryCode->DataBinding->Data = (TObject *)IndexOfcaCategoryCode;
   caCategoryName->DataBinding->Data = (TObject *)IndexOfcaCategoryName;

   // this line is critical
   GroupsGridTableView1->DataController->CustomDataSource = TaxaGroupDataSource;

   egEcolGroupCode->DataBinding->Data = (TObject*)IndexOfegEcolGroupCode;
   egEcolGroupName->DataBinding->Data = (TObject*)IndexOfegEcolGroupName;

   // this line is critical
   GroupsGridTableView2->DataController->CustomDataSource = EcolGroupDataSource;
}
//---------------------------------------------------------------------------

// save button
void __fastcall TEditGroupsForm::cxButton3Click(TObject *Sender)
{
   Screen->Cursor = crHourGlass;
   //SAVETAXALOOKUP* SaveTaxaLookup = new SAVETAXALOOKUP(TaxaFile, TaxaTitle,
   //	 &GroupCategoryList, TaxaList, this);
   /*
   vector<TAXAECOLGROUPS> TaxaEcolGroups;
   for (int i=0; i<TaxaEcolGroupList->Count(); i++) {
	 TAXAECOLGROUPS TaxaEcolGroup;
	 TaxaEcolGroup.TaxaGroup.Code = TaxaEcolGroupList->TaxaEcolGroup[i]->TaxaGroup.Code;
	 TaxaEcolGroup.TaxaGroup.Name = TaxaEcolGroupList->TaxaEcolGroup[i]->TaxaGroup.Name;
	 TaxaEcolGroup.EcolGroups = TaxaEcolGroupList->TaxaEcolGroup[i]->EcolGroups;
	 TaxaEcolGroups.push_back(TaxaEcolGroup);
	 }
   */

   SAVETAXALOOKUP* SaveTaxaLookup = new SAVETAXALOOKUP(TaxaFile, TaxaTitle,
	 &(TaxaEcolGroupList->TaxaEcolGroups), TaxaList, this);
   SaveTaxaLookup->Save();
   delete SaveTaxaLookup;
   FocusControl(GroupsGrid);
   Screen->Cursor = crDefault;
}
//---------------------------------------------------------------------------

// ok button
void __fastcall TEditGroupsForm::cxButton1Click(TObject *Sender)
{
   OriginalTaxaEcolGroupsPtr->clear();
   *OriginalTaxaEcolGroupsPtr = TaxaEcolGroupList->TaxaEcolGroups;
   /*
   for (int i=0; i<GroupCategoryList->Count(); i++) {
	 TAXAECOLGROUPS TaxaEcolGroup;
	 TaxaEcolGroup.TaxaGroup.Code = GroupCategoryList->Categories[i]->TaxaGroup.Code;
	 TaxaEcolGroup.TaxaGroup.Name = GroupCategoryList->Categories[i]->TaxaGroup.Name;
	 TaxaEcolGroup.EcolGroups = GroupCategoryList->Categories[i]->EcolGroups;
	 OriginalTaxaEcolGroupsPtr->push_back(TaxaEcolGroup);
	 }
   */
}
//---------------------------------------------------------------------------

void __fastcall TEditGroupsForm::GroupsGridTableView1DataControllerAfterPost(TcxCustomDataController *ADataController)
{
   GroupsGridTableView1->Controller->FocusedColumnIndex = 0;
}
//---------------------------------------------------------------------------

void __fastcall TEditGroupsForm::GroupsGridTableView2DataControllerAfterPost(TcxCustomDataController *ADataController)
{
   TcxGridTableView* GridTableView = (TcxGridTableView*)ADataController->GetOwner();
   GridTableView->Controller->FocusedColumnIndex = 0;
}
//---------------------------------------------------------------------------

