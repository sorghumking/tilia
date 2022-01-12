//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TNNewEcGr.h"
#ifndef TIJSONH
#include "TIJSON.h"
#endif
#ifndef TINeotomaH
#include "TINeotoma.h"
#endif
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxGroupBox"
#pragma link "cxLabel"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxTextEdit"
#pragma link "AdvCGrid"
#pragma link "AdvGrid"
#pragma link "AdvObj"
#pragma link "BaseGrid"
#pragma link "cxButtons"
#pragma link "ipwjson"
#pragma link "ipshttps"
#pragma link "AdvCGrid"
#pragma link "AdvGrid"
#pragma link "AdvObj"
#pragma link "BaseGrid"
#pragma link "cxButtons"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxGroupBox"
#pragma link "cxLabel"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "ipshttps"
#pragma link "ipwjson"
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
#pragma link "cxTextEdit"
#pragma link "cxTimeEdit"
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
#pragma link "ipsjsons"
#pragma resource "*.dfm"
TNewEcolGroupForm *NewEcolGroupForm;

TEcolGroup::TEcolGroup(vector<ECOLGROUP>& EcolGroups)
{
   Items = EcolGroups;
}
//---------------------------------------------------------------------------

vector<ECOLGROUP>::pointer TEcolGroup::GetEcolGroup(int AIndex)
{
  return &Items[AIndex];
}
//---------------------------------------------------------------------------

void __fastcall TEcolGroup::Clear(void)
{
  Items.clear();
}
//---------------------------------------------------------------------------

void __fastcall TEcolGroup::Add(ECOLGROUP& EcolGroup)
{
   Items.push_back(EcolGroup);
}
//---------------------------------------------------------------------------

/*
void TEcolGroup::Delete(int AIndex)
{
   vector<ECOLGROUP>::iterator itr = Items.begin() + AIndex;
   Items.erase(itr);
}
//---------------------------------------------------------------------------
*/

void TEcolGroup::Insert(int AIndex, ECOLGROUP& EcolGroup)
{
   vector<ECOLGROUP>::iterator itr = Items.begin() + AIndex;
   Items.insert(itr, EcolGroup);
}
//---------------------------------------------------------------------------

__fastcall TNeotomaEcolGroupDataSource::TNeotomaEcolGroupDataSource(TEcolGroup* AEcolGroup)
{
   FEcolGroup = AEcolGroup;
}
//---------------------------------------------------------------------------

int __fastcall TNeotomaEcolGroupDataSource::GetRecordCount(void)
{
  return(FEcolGroup->Count());
}
//---------------------------------------------------------------------------

void * __fastcall TNeotomaEcolGroupDataSource::InsertRecord(void * ARecordHandle)
{
  ECOLGROUP EcolGroup;
  FEcolGroup->Insert((int)ARecordHandle, EcolGroup);
  TcxDataRecordHandle* Result = (TcxDataRecordHandle*)ARecordHandle;
  DataChanged();
  return (Result);
}
//---------------------------------------------------------------------------

void * __fastcall TNeotomaEcolGroupDataSource::AppendRecord(void)
{
  TcxDataRecordHandle* Result = (TcxDataRecordHandle*)FEcolGroup->Count();
  ECOLGROUP EcolGroup;
  FEcolGroup->Add(EcolGroup);
  DataChanged();
  return (Result);
}
//---------------------------------------------------------------------------

Variant __fastcall TNeotomaEcolGroupDataSource::GetValue(void * ARecordHandle, void * AItemHandle)
{
  int AColumnId = GetDefaultItemID((int)AItemHandle);
  vector<ECOLGROUP>::pointer EcolGroupPtr = FEcolGroup->EcolGroup[(int)ARecordHandle];
  Variant Result;
  switch (AColumnId) {
	case IndexOfEcolGroupID:
	  Result = EcolGroupPtr->EcolGroupID;
	  break;
	case IndexOfEcolGroup:
	  Result = EcolGroupPtr->EcolGroup;
	  break;
  }
  return (Result);
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaEcolGroupDataSource::SetValue(void * ARecordHandle, void * AItemHandle, const Variant &AValue)
{
  int AColumnId = GetDefaultItemID((int)AItemHandle);
  ECOLGROUP* EcolGroupPtr = FEcolGroup->EcolGroup[(int)ARecordHandle];
  UnicodeString blank = L"";
  switch (AColumnId) {
	case IndexOfEcolGroupID:
	  EcolGroupPtr->EcolGroupID = (AValue.IsNull()) ? blank : VarToStr(AValue).UpperCase();
	  break;
	case IndexOfEcolGroup:
	  EcolGroupPtr->EcolGroup = (AValue.IsNull()) ? blank : VarToStr(AValue);
	  break;
	}
}
//---------------------------------------------------------------------------

__fastcall TNewEcolGroupForm::TNewEcolGroupForm(TComponent* Owner)
	: TForm(Owner)
{
	Activated = false;
	CodeGood = false;
	NameGood = false;

	EcolGroupsList = new TEcolGroup();
	NeotomaEcolGroupDataSource = new TNeotomaEcolGroupDataSource(EcolGroupsList);
	GenerateEcolGroupColumns();
}
//---------------------------------------------------------------------------

void __fastcall TNewEcolGroupForm::GenerateEcolGroupColumns()
{
   egID->DataBinding->Data = (TObject*)IndexOfEcolGroupID;
   egName->DataBinding->Data = (TObject*)IndexOfEcolGroup;

   // this line is critical
   cxGrid1TableView1->DataController->CustomDataSource = NeotomaEcolGroupDataSource;
}
//---------------------------------------------------------------------------

void __fastcall TNewEcolGroupForm::FormActivate(TObject *Sender)
{
   if (!Activated) {
	 GetEcolGroupTypes();
	 Activated = true;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TNewEcolGroupForm::FormDestroy(TObject *Sender)
{
   if (EcolGroupsList != NULL)
	 delete EcolGroupsList;
   if (NeotomaEcolGroupDataSource != NULL)
	 delete NeotomaEcolGroupDataSource;
}
//---------------------------------------------------------------------------

void TNewEcolGroupForm::GetEcolGroupTypes(void)
{
   Screen->Cursor = crHourGlass;
   NeotomaEcolGroupTypesTable EcolGroupTypesTable(ipsJSONS1, TcpClient1);
   StatusBar1->Caption = EcolGroupTypesTable.WebServiceName();
   if (EcolGroupTypesTable.Execute()) {
	 FillEcolGroupTypesGrid(EcolGroupTypesTable.Items);
	 }
   StatusBar1->Caption = L"";
   Screen->Cursor = crDefault;
}
//---------------------------------------------------------------------------

void TNewEcolGroupForm::FillEcolGroupTypesGrid(map<UnicodeString, UnicodeString>& EcolGroups)
{
   map<UnicodeString,UnicodeString>::iterator itr;
   map<UnicodeString,UnicodeString>::iterator begin = EcolGroups.begin();
   map<UnicodeString,UnicodeString>::iterator end = EcolGroups.end();
   for (itr = begin; itr != end; itr++) {
	 ECOLGROUP EcolGroup(itr->first, itr->second);
	 EcolGroupsList->Add(EcolGroup);
	 }
   NeotomaEcolGroupDataSource->DataChanged();
}
//---------------------------------------------------------------------------

int TNewEcolGroupForm::Upload(void)
{
   UnicodeString msg;
   bool Valid;
   int rv = mrOk;

   UnicodeString EcolGroupID = VarToStr(cxGrid1TableView1->DataController->GetValue(-1,0));
   UnicodeString EcolGroup = VarToStr(cxGrid1TableView1->DataController->GetValue(-1,1));
   msg = L"Post new Ecological Group «" + EcolGroupID + L" : " + EcolGroup + L"» to Neotoma?";
   if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrNo)
	 return mrAbort;

   // make sure Code and/or Name not added in the interim
   Screen->Cursor = crHourGlass;
   NeotomaEcolGroupTypesTable EcolGroupTypesTable(ipsJSONS1, TcpClient1);
   StatusBar1->Caption = EcolGroupTypesTable.WebServiceName();
   bool success = true;
   if (EcolGroupTypesTable.Execute()) {
	 map<UnicodeString,UnicodeString>::iterator itr;
	 map<UnicodeString,UnicodeString>::iterator begin = EcolGroupTypesTable.Items.begin();
	 map<UnicodeString,UnicodeString>::iterator end = EcolGroupTypesTable.Items.end();
	 for (itr = begin; itr != end; itr++) {
	   if (SameText(EcolGroupID, itr->first)) {
		 msg = L"ID has already been added to EcolGroupTypes table for EcolGroup «" + itr->second + "»!";
		 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 success = false;
		 break;
		 }
	   if (SameText(EcolGroup, itr->second)) {
		 msg = L"EcolGroup has already been added to EcolGroupTypes table for ID «" + itr->first + "»!";
		 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 success = false;
		 break;
		 }
	   }
	 if (!success)
	   FillEcolGroupTypesGrid(EcolGroupTypesTable.Items);
	 }
   else
	 success = false;

   if (!success)
	 return mrNone;

   // everything ok
   UnicodeString ErrorMsg;
   InsertData InsertEcolGroup(L"InsertEcolGroupType", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
   StatusBar1->Caption = L"InsertEcolGroupType";
   InsertEcolGroup.Add(L"ECOLGROUPID", EcolGroupID);
   InsertEcolGroup.Add(L"ECOLGROUP", EcolGroup);
   InsertEcolGroup.PostData();
   if (InsertEcolGroup.Post(ErrorMsg)) {
	 EcolGroupTypesTable.Items.clear();
	 StatusBar1->Caption = EcolGroupTypesTable.WebServiceName();
	 if (EcolGroupTypesTable.Execute()) {
	   if (EcolGroupTypesTable.Items.count(EcolGroupID) == 1) {
		 msg = L"Success: Ecological Group «" + EcolGroupID + L" : " + EcolGroup + L"» uploaded to Neotoma!";
		 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
		 ECOLGROUP NewEcolGroup(EcolGroupID, EcolGroup);
		 NewEcolGroups[EcolGroupID] = EcolGroup;    // used by calling function
		 rv = mrOk;
		 }
	   }
	 }
   else
	 {
	 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 rv = mrAbort;
	 }

   StatusBar1->Caption = L"";
   return rv;
}
//---------------------------------------------------------------------------

void __fastcall TNewEcolGroupForm::cxGrid1TableView1FocusedRecordChanged(TcxCustomGridTableView *Sender,
		  TcxCustomGridRecord *APrevFocusedRecord, TcxCustomGridRecord *AFocusedRecord,
		  bool ANewItemRecordFocusingChanged)
{
   Sender->OptionsSelection->CellSelect = true;
}
//---------------------------------------------------------------------------

void __fastcall TNewEcolGroupForm::cxGrid1TableView1Editing(TcxCustomGridTableView *Sender,
          TcxCustomGridTableItem *AItem, bool &AAllow)
{
   Sender->OptionsSelection->CellSelect = (Sender->Controller->FocusedRecordIndex == -1);
   AAllow = (Sender->Controller->FocusedRecordIndex == -1);
}
//---------------------------------------------------------------------------

void __fastcall TNewEcolGroupForm::cxGrid1TableView1DataControllerBeforePost(TcxCustomDataController *ADataController)
{
   if (CodeGood && NameGood) {
	 if (Upload() == mrAbort) {
	   Abort();
	   cxGrid1->Repaint();
	   }
	 else {
	   CodeGood = false;
	   NameGood = false;
	   }
	 Screen->Cursor = crDefault;
	 }
   else
	 Abort();
}
//---------------------------------------------------------------------------

bool TNewEcolGroupForm::CheckCode(Variant &Value, TCaption &ErrorText)
{
   UnicodeString EcolGroupID = VarToStr(Value).UpperCase();
   if (EcolGroupID.IsEmpty())
	 return true;
   if (EcolGroupID.Length() != 4) {
	 ErrorText = L"Code must be 4 letters!";
	 return false;
	 }
   for (int i=1; i<=4; i++) {
	 if (!TCharacter::IsLetter(EcolGroupID,i)) {
	   ErrorText = L"All characters must be Latin letters!";
	   return false;
	   }
	 }
   for (unsigned int i=0; i<EcolGroupsList->EcolGroups.size(); i++) {
	 if (SameText(EcolGroupID, EcolGroupsList->EcolGroups[i].EcolGroupID)) {
	   ErrorText = L"ID already used for Name «" + EcolGroupsList->EcolGroups[i].EcolGroup + L"»!";
	   return false;
	   }
	 }
   Value = EcolGroupID;
   return true;
}
//---------------------------------------------------------------------------

bool TNewEcolGroupForm::CheckName(Variant &Value, TCaption &ErrorText)
{
   UnicodeString EcolGroup = VarToStr(Value);
   if (EcolGroup.IsEmpty())
	 return true;
   for (unsigned int i=0; i<EcolGroupsList->EcolGroups.size(); i++) {
	 if (SameText(EcolGroup, EcolGroupsList->EcolGroups[i].EcolGroup)) {
	   ErrorText = L"Name already used for ID «" + EcolGroupsList->EcolGroups[i].EcolGroupID + L"»!";
	   return false;
	   }
	 }
   return true;
}
//---------------------------------------------------------------------------

void __fastcall TNewEcolGroupForm::egIDPropertiesValidate(TObject *Sender, Variant &DisplayValue,
		  TCaption &ErrorText, bool &Error)
{
   Error = !CheckCode(DisplayValue, ErrorText);
   UnicodeString EcolGroupID = VarToStr(DisplayValue);
   CodeGood = (!EcolGroupID.IsEmpty() && !Error);
   cxGrid1TableView1->NavigatorButtons->Post->Enabled = (CodeGood && NameGood);
}
//---------------------------------------------------------------------------

void __fastcall TNewEcolGroupForm::egNamePropertiesValidate(TObject *Sender, Variant &DisplayValue,
		  TCaption &ErrorText, bool &Error)
{
   Error = !CheckName(DisplayValue, ErrorText);
   UnicodeString EcolGroup = VarToStr(DisplayValue);
   NameGood = (!EcolGroup.IsEmpty() && !Error);
   cxGrid1TableView1->NavigatorButtons->Post->Enabled = (CodeGood && NameGood);
}
//---------------------------------------------------------------------------


void __fastcall TNewEcolGroupForm::ipsJSONS1SSLServerAuthentication(TObject *Sender,
          TipsJSONSSSLServerAuthenticationEventParams *e)
{
   e->Accept = true;
}
//---------------------------------------------------------------------------

