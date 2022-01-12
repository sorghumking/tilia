//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TISums.h"
#ifndef TICommonH
#include "TICommon.h"
#endif

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxCheckBox"
#pragma link "cxClasses"
#pragma link "cxControls"
#pragma link "cxCustomData"
#pragma link "cxData"
#pragma link "cxDataStorage"
#pragma link "cxDropDownEdit"
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
#pragma link "cxCheckComboBox"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxCheckBox"
#pragma link "cxCheckComboBox"
#pragma link "cxClasses"
#pragma link "cxControls"
#pragma link "cxCustomData"
#pragma link "cxData"
#pragma link "cxDataStorage"
#pragma link "cxDropDownEdit"
#pragma link "cxEdit"
#pragma link "cxFilter"
#pragma link "cxGraphics"
#pragma link "cxGrid"
#pragma link "cxGridCustomTableView"
#pragma link "cxGridCustomView"
#pragma link "cxGridLevel"
#pragma link "cxGridTableView"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxStyles"
#pragma link "cxTextEdit"
#pragma link "cxNavigator"
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
TSumsForm *SumsForm;
//---------------------------------------------------------------------------

__fastcall TSumDataSource::TSumDataSource(TSumList* ASumList)
{
  FSums = ASumList;
  FSums->OnNotify = Notify;
}
//---------------------------------------------------------------------------

void __fastcall TSumDataSource::DeleteRecord(void * ARecordHandle)
{
  FSums->Delete((int)ARecordHandle);
}
//---------------------------------------------------------------------------

int __fastcall TSumDataSource::GetRecordCount(void)
{
  return(FSums->Count);
}
//---------------------------------------------------------------------------

Variant __fastcall TSumDataSource::GetValue(void * ARecordHandle, void * AItemHandle)
{
  int AColumnId = GetDefaultItemID((int)AItemHandle);
  FSUM* Sum = FSums->Sums[(int)ARecordHandle];
  Variant Result;
  switch (AColumnId) {
    case IndexOfSumCode:
      Result = Sum->Code;
      break;
    case IndexOfSumName:
      Result = Sum->Name;
      break;
    case IndexOfBase:
      Result = Sum->Base;
      break;
    case IndexOfPercent:
      Result = Sum->Percent;
      break;
    case IndexOfSkip:
      Result = Sum->Skip;
      break;
  }
  return (Result);
}
//---------------------------------------------------------------------------

void __fastcall TSumDataSource::Notify(void * Ptr, TListNotification Action)
{
  DataChanged();
}
//---------------------------------------------------------------------------

void * __fastcall TSumDataSource::InsertRecord(void * ARecordHandle)
{
  FSUM* Sum = new FSUM;
  FSums->Insert((int)ARecordHandle, Sum);
  TcxDataRecordHandle* Result = (TcxDataRecordHandle*)ARecordHandle;
  return (Result);
}
//---------------------------------------------------------------------------

void * __fastcall TSumDataSource::AppendRecord(void)
{
  TcxDataRecordHandle* Result = (TcxDataRecordHandle*)FSums->Count;
  FSUM* Sum = new FSUM;
  FSums->Add(Sum);
  return (Result);
}
//---------------------------------------------------------------------------

void __fastcall TSumDataSource::SetValue(void * ARecordHandle, void * AItemHandle, const Variant &AValue)
{
  int AColumnId = GetDefaultItemID((int)AItemHandle);
  FSUM* Sum = FSums->Sums[(int)ARecordHandle];
  switch (AColumnId) {
    case IndexOfSumCode:
	  Sum->Code = VarToStr(AValue);
      break;
	case IndexOfSumName:
	  Sum->Name = VarToStr(AValue);
	  break;
    case IndexOfBase:
	  Sum->Base = VarToStr(AValue);
	  break;
    case IndexOfPercent:
	  Sum->Percent = (AValue.IsNull()) ? false : AValue;
      break;
    case IndexOfSkip:
	  Sum->Skip = (AValue.IsNull()) ? false : AValue;
	  break;
  }
}
//---------------------------------------------------------------------------

__fastcall TSumsForm::TSumsForm(TComponent* Owner)
        : TForm(Owner)
{
   TilSpreadSheetForm = (TTilSpreadSheetForm*)Owner;
}
//---------------------------------------------------------------------------

__fastcall TSuperSumDataSource::TSuperSumDataSource(TSuperSumList* ASuperSumList)
{
  FSuperSums = ASuperSumList;
  FSuperSums->OnNotify = Notify;
}
//---------------------------------------------------------------------------

void __fastcall TSuperSumDataSource::DeleteRecord(void * ARecordHandle)
{
  FSuperSums->Delete((int)ARecordHandle);
}
//---------------------------------------------------------------------------

int __fastcall TSuperSumDataSource::GetRecordCount(void)
{
  return(FSuperSums->Count);
}
//---------------------------------------------------------------------------

Variant __fastcall TSuperSumDataSource::GetValue(void * ARecordHandle, void * AItemHandle)
{
  int AColumnId = GetDefaultItemID((int)AItemHandle);
  SUPERSUM* SuperSum = FSuperSums->SuperSums[(int)ARecordHandle];
  Variant Result;
  switch (AColumnId) {
    case IndexOfSuperSumCode:
      Result = SuperSum->Code;
      break;
    case IndexOfSuperSumName:
      Result = SuperSum->Name;
      break;
    case IndexOfIncludeSums:
      Result = SuperSum->Sums;
      break;
  }
  return (Result);
}
//---------------------------------------------------------------------------

void __fastcall TSuperSumDataSource::Notify(void * Ptr, TListNotification Action)
{
  DataChanged();
}
//---------------------------------------------------------------------------

void * __fastcall TSuperSumDataSource::InsertRecord(void * ARecordHandle)
{
  SUPERSUM* SuperSum = new SUPERSUM;
  FSuperSums->Insert((int)ARecordHandle, SuperSum);
  TcxDataRecordHandle* Result = (TcxDataRecordHandle*)ARecordHandle;
  return (Result);
}
//---------------------------------------------------------------------------

void * __fastcall TSuperSumDataSource::AppendRecord(void)
{
  TcxDataRecordHandle* Result = (TcxDataRecordHandle*)FSuperSums->Count;
  SUPERSUM* SuperSum = new SUPERSUM;
  FSuperSums->Add(SuperSum);
  return (Result);
}
//---------------------------------------------------------------------------

void __fastcall TSuperSumDataSource::SetValue(void * ARecordHandle, void * AItemHandle, const Variant &AValue)
{
  int AColumnId = GetDefaultItemID((int)AItemHandle);
  SUPERSUM* SuperSum = FSuperSums->SuperSums[(int)ARecordHandle];
  switch (AColumnId) {
    case IndexOfSuperSumCode:
	  SuperSum->Code = VarToStr(AValue);
	  break;
	case IndexOfSuperSumName:
	  SuperSum->Name = VarToStr(AValue);
	  break;
	case IndexOfIncludeSums:
	  SuperSum->Sums = VarToStr(AValue);
	  break;
  }
}
//---------------------------------------------------------------------------

void __fastcall TSumsForm::FormActivate(TObject *Sender)
{
   Screen->Cursor = crHourGlass;

   SumList = new TSumList();
   SuperSumList = new TSuperSumList();

   SumDataSource = new TSumDataSource(SumList);
   GenerateSumColumns();
   TilSpreadSheetForm->LoadSumData(SumList);
   SumsGridTableView->DataController->GotoFirst();

   SuperSumDataSource = new TSuperSumDataSource(SuperSumList);
   GenerateSuperSumColumns();

   // add sums (groups) to SuperSums checkcombobox
   TcxCheckComboBoxProperties* pr = (TcxCheckComboBoxProperties*)(ssInclude->Properties);
   for (int i=0; i<SumList->Count; i++) {
     FSUM* Sum = (FSUM*)SumList->Items[i];
     pr->Items->AddCheckItem(Sum->Code, Sum->Code);
     }

   FocusControl(SumsGrid);
   SumsGridTableView->Controller->FocusedRecordIndex = 0;
   SumsGridTableView->Controller->FocusedColumnIndex = 1;
   Screen->Cursor = crDefault;
}
//---------------------------------------------------------------------------

void __fastcall TSumsForm::FormDeactivate(TObject *Sender)
{
   delete SumList;
   delete SumDataSource;
   delete SuperSumList;
   delete SuperSumDataSource;
}
//---------------------------------------------------------------------------

void __fastcall TSumsForm::GenerateSumColumns()
{
   suCode->DataBinding->Data = (TObject*)IndexOfSumCode;
   suName->DataBinding->Data = (TObject*)IndexOfSumName;
   suBase->DataBinding->Data = (TObject*)IndexOfBase;
   suPercent->DataBinding->Data = (TObject *)IndexOfPercent;
   suSkip->DataBinding->Data = (TObject *)IndexOfSkip;
   // this line is critical
   SumsGridTableView->DataController->CustomDataSource = SumDataSource;
}
//---------------------------------------------------------------------------

void __fastcall TSumsForm::GenerateSuperSumColumns()
{
   ssCode->DataBinding->Data = (TObject*)IndexOfSumCode;
   ssName->DataBinding->Data = (TObject*)IndexOfSumName;
   ssInclude->DataBinding->Data = (TObject*)IndexOfBase;
   // this line is critical
   SuperSumsGridTableView->DataController->CustomDataSource = SuperSumDataSource;
}
//---------------------------------------------------------------------------

// Ok button
void __fastcall TSumsForm::Button1Click(TObject *Sender)
{
  UnicodeString SumCode;
  UnicodeString Groups;

  int Row;

  TilSpreadSheetForm->MakeSumVars(Row, SumList);

  TProfGrid* ProfGrid1 = TilSpreadSheetForm->ProfGrid1;

  FocusControl(SuperSumsGrid);
  for (int i=0; i<SuperSumList->Count; i++) {
	SUPERSUM* SuperSum = (SUPERSUM*)SuperSumList->Items[i];
	if (!SuperSum->Code.IsEmpty() && SuperSum->Sums != L"None selected") {
	  SumCode = L"SSUM(" + SuperSum->Code + L")";
	  ProfGrid1->AbsoluteCells[1][Row]->Value = WideString(SumCode);
      ProfGrid1->AbsoluteCells[2][Row]->Value = WideString(SuperSum->Name);

      SuperSumsGridTableView->Controller->FocusedRecordIndex = i;
      TcxGridEditingController* AEdController =
        SuperSumsGridTableView->Controller->EditingController;      AEdController->EditingItem = ssInclude;      AEdController->ShowEdit(0);	  Groups.SetLength(0);      if (AEdController->IsEditing) {        Groups = ((TcxCheckComboBox*)AEdController->Edit)->EditingText;
        ProfGrid1->AbsoluteCells[7][Row]->Value = Groups;
        }
      TilSpreadSheetForm->AddSSum(SuperSum->Code, Groups, Row++);
      }
    }
}
//---------------------------------------------------------------------------

void __fastcall TSumsForm::ssCodePropertiesEditValueChanged(TObject *Sender)
{
   // add Super Sum to Base combobox
   TcxComboBoxProperties* pr = (TcxComboBoxProperties*)(suBase->Properties);
   pr->Items->Add(((TcxTextEdit*)Sender)->Text);
}
//---------------------------------------------------------------------------

void __fastcall TSumsForm::Button4Click(TObject *Sender)
{
   Button5->Visible = true;
   Panel1->Visible = true;     
}
//---------------------------------------------------------------------------

void __fastcall TSumsForm::Button5Click(TObject *Sender)
{
   if (Panel1->Visible) {
     Panel1->Visible = false;
     Panel10->Visible = true;
     Button6->Visible = true;
     }
   else if (Panel10->Visible) {
     Panel10->Visible = false;
     Panel2->Visible = true;
     }
   else if (Panel2->Visible) {
     Panel2->Visible = false;
     Panel3->Visible = true;
     }
   else if (Panel3->Visible) {
     Panel3->Visible = false;
     Panel4->Visible = true;
     }
   else if (Panel4->Visible) {
     Panel4->Visible = false;
     Panel5->Visible = true;
     }
   else if (Panel5->Visible) {
     Panel5->Visible = false;
     Panel6->Visible = true;
     }
   else if (Panel6->Visible) {
     Panel6->Visible = false;
     Panel7->Visible = true;
     }
   else if (Panel7->Visible) {
     Panel7->Visible = false;
     Panel8->Visible = true;
     }
   else if (Panel8->Visible) {
     Panel8->Visible = false;
     Button4->Visible = false;
     Button5->Visible = false;
     Button6->Visible = false;
     Panel9->Visible = true;
     }
}
//---------------------------------------------------------------------------

void __fastcall TSumsForm::Button6Click(TObject *Sender)
{
   if (Panel10->Visible) {
     Panel10->Visible = false;
     Panel1->Visible = true;
     Button6->Visible = false;
     }
   else if (Panel2->Visible) {
     Panel2->Visible = false;
     Panel10->Visible = true;
     }
   else if (Panel3->Visible) {
     Panel3->Visible = false;
     Panel2->Visible = true;
     }
   else if (Panel4->Visible) {
     Panel4->Visible = false;
     Panel3->Visible = true;
     }
   else if (Panel5->Visible) {
     Panel5->Visible = false;
     Panel4->Visible = true;
     }
   else if (Panel6->Visible) {
     Panel6->Visible = false;
     Panel5->Visible = true;
     }
   else if (Panel7->Visible) {
     Panel7->Visible = false;
     Panel6->Visible = true;
     }
   else if (Panel8->Visible) {
     Panel8->Visible = false;
     Panel7->Visible = true;
     }
   else if (Panel9->Visible) {
     Panel9->Visible = false;
     Panel8->Visible = true;
     }
}
//---------------------------------------------------------------------------

void __fastcall TSumsForm::SuperSumsGridTableViewNavigatorButtonsButtonClick(
      TObject *Sender, int AButtonIndex, bool &ADone)
{
   if (AButtonIndex == 10) {
     if (Panel5->Visible) {
       Panel5->Visible = false;
       Panel6->Visible = true;
       }
     }
}
//---------------------------------------------------------------------------

void __fastcall TSumsForm::RadioGroup1Click(TObject *Sender)
{
   UnicodeString SumCode, LastSumCode;

   if (RadioGroup1->ItemIndex == 1) {
     TStringList *SumCodes = new TStringList;
     SumCodes->Sorted = false;
     int RowCount = TilSpreadSheetForm->AbsContentRowCount(TilSpreadSheetForm->ProfGrid1);
     LastSumCode = TilSpreadSheetForm->ProfGrid1->AbsoluteCells[7][3]->Text;
     SumCodes->Add(LastSumCode);
     for (int i=4; i<=RowCount; i++) {
	   SumCode = TilSpreadSheetForm->ProfGrid1->AbsoluteCells[7][i]->Text;
       if (SumCode != LastSumCode) {
         if (SumCodes->IndexOf(SumCode) == -1) {  // not found
           SumCodes->Add(SumCode);
           LastSumCode = SumCode;
           }
         else {
		   MessageDlg("Groups must be sorted to enter sums as formulas.", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
           RadioGroup1->ItemIndex = 0;
           break;
           }
         }
       }
     delete SumCodes;
     }
}
//---------------------------------------------------------------------------

// calculate default sums
void __fastcall TSumsForm::Button7Click(TObject *Sender)
{
   set<UnicodeString> ValidElements;
   map<int,pair<UnicodeString,UnicodeString> > ElementGroupCodes;
   UnicodeString InvalidGroup;

   Screen->Cursor = crHourGlass;
   TilSpreadSheetForm->GetValidElements(ValidElements, ElementGroupCodes, InvalidGroup);
   SUMS Sums(SumList, ValidElements, ElementGroupCodes, InvalidGroup);
   if (!Sums.ValidCodes) {
	 MessageDlg("Unrecognized Group code. Cannot calculate default sums.",
				Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 return;
	 }
   TilSpreadSheetForm->ReplaceDefaultElementGroups(ElementGroupCodes);

   FocusControl(SuperSumsGrid);

   vector<UnicodeString>::iterator itr;
   vector<SUPERSUMVARIABLE>::iterator start = Sums.SSVar.begin();
   vector<SUPERSUMVARIABLE>::iterator stop = Sums.SSVar.end();
   vector<SUPERSUMVARIABLE>::iterator ssitr;

   for (ssitr=start; ssitr != stop; ssitr++) {
	 itr = find(Sums.UsedBases.begin(), Sums.UsedBases.end(), (*ssitr).Code);
	 if (itr != Sums.UsedBases.end()) {
	   SUPERSUM* SuperSum = new SUPERSUM;
	   SuperSum->Code = (*ssitr).Code;
	   SuperSum->Name = (*ssitr).Name;
	   SuperSumList->Add(SuperSum);
	   }
	 }

   for (ssitr=start; ssitr != stop; ssitr++) {
	 itr = find(Sums.UsedBases.begin(), Sums.UsedBases.end(), (*ssitr).Code);
	 if (itr != Sums.UsedBases.end()) {
	   TcxComboBoxProperties* cbpr = (TcxComboBoxProperties*)(suBase->Properties);
	   cbpr->Items->Add((*ssitr).Code);
	   }
	 }

   int nss = 0;
   for (ssitr=start; ssitr != stop; ssitr++) {
	 itr = find(Sums.UsedBases.begin(), Sums.UsedBases.end(), (*ssitr).Code);
	 if (itr != Sums.UsedBases.end())
	   SetDefaultSuperSums(nss++, Sums.SVar, (*ssitr).Base);
	 }

   SuperSumsGridTableView->Controller->FocusedRecordIndex = 0;

   FocusControl(SumsGrid);

   for (int i=0; i<SumList->Count; i++) {
	 SumsGridTableView->Controller->FocusedRecordIndex = i;
	 TcxGridEditingController * AEdController =
	   SumsGridTableView->Controller->EditingController;	 AEdController->EditingItem = suBase;	 AEdController->ShowEdit(0);	 if (AEdController->IsEditing) {
	   TcxComboBox* cb = (TcxComboBox*)AEdController->Edit;
	   cb->EditingText = Sums.UsedBases[i];
	   }
	 }
   SumsGridTableView->Controller->FocusedRecordIndex = 0;
   SumsGridTableView->Controller->FocusedColumnIndex = 1;

   Screen->Cursor = crDefault;
}
//---------------------------------------------------------------------------

void TSumsForm::SetDefaultSuperSums(int nss, map<UnicodeString, SUMVARIABLE>& SVar,
	 vector<UnicodeString>& Groups)
{
   UnicodeString SumCode;
   vector<UnicodeString>::iterator itr;

   FocusControl(SuperSumsGrid);
   SuperSumsGridTableView->Controller->FocusedRecordIndex = nss;
   TcxGridEditingController * AEdController =
	 SuperSumsGridTableView->Controller->EditingController;   AEdController->EditingItem = ssInclude;   AEdController->ShowEdit(0);   if (AEdController->IsEditing) {
	 TcxCheckComboBox* ccb = (TcxCheckComboBox*)AEdController->Edit;
	 for (int i=0; i<SumList->Count; i++) {
	   FSUM* fsum = SumList->Sums[i];
	   UnicodeString Base = SVar[fsum->Code].Base;
	   itr = find(Groups.begin(), Groups.end(), Base);
	   if (itr != Groups.end()) {
		 ccb->SetItemState(i, cbsChecked);
		 if (SumCode.Length() == 0)
		   SumCode = fsum->Code;
		 else {
		   SumCode += ";";
		   SumCode += fsum->Code;
		   }
		 }
	   }
	 ccb->EditingText = SumCode;
	 }
}
//---------------------------------------------------------------------------

