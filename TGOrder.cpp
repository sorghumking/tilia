#include <vcl.h>
#include "pch.h"
#pragma hdrstop

#include <Clipbrd.hpp>
#ifndef TGOrderH
#include "TGOrder.h"
#endif
#ifndef TGHelpH
#include "TGHelp.h"
#endif
#ifndef TGUtilsH
#include "TGUtils.h"
#endif
#ifndef TGItalicH
#include "TGItalic.h"
#endif
#ifndef TGGreekH
#include "TGGreek.h"
#endif
#ifndef TGParentH
#include "TGParent.h"
#endif

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxClasses"
#pragma link "cxControls"
#pragma link "cxCustomData"
#pragma link "cxData"
#pragma link "cxEdit"
#pragma link "cxFilter"
#pragma link "cxGraphics"
#pragma link "cxGrid"
#pragma link "cxGridCustomTableView"
#pragma link "cxGridCustomView"
#pragma link "cxGridLevel"
#pragma link "cxGridTableView"
#pragma link "cxStyles"
#pragma link "cxCheckBox"
#pragma link "cxDataStorage"
#pragma link "cxTextEdit"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
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

TOrderForm *OrderForm;

//---------------------------------------------------------------------------
void TVarList::ReleaseAllVars()
{
  for (int i = 0; i < Count; i++)
    ReleaseVar(i);
}
//---------------------------------------------------------------------------

void TVarList::ReleaseVar(int AIndex)
{
  delete (VAR*)Items[AIndex];
}
//---------------------------------------------------------------------------

VAR* TVarList::GetVar(int AIndex)
{
  return (VAR*)Items[AIndex];
}
//---------------------------------------------------------------------------

void __fastcall TVarList::Notify(void * Ptr, TListNotification Action)
{
  if (FOnNotify != NULL)
    FOnNotify(Ptr, Action);
}
//---------------------------------------------------------------------------

void __fastcall TVarList::Clear(void)
{
  ReleaseAllVars();
}
//---------------------------------------------------------------------------

__fastcall TVarDataSource::TVarDataSource(TVarList* AVarList)
{
  FVars = AVarList;
  FVars->OnNotify = Notify;
}
//---------------------------------------------------------------------------

int __fastcall TVarDataSource::GetRecordCount(void)
{
  return(FVars->Count);
}
//---------------------------------------------------------------------------

Variant __fastcall TVarDataSource::GetValue(void * ARecordHandle, void * AItemHandle)
{
  // displays value in grid based on stored data
  int AColumnId = GetDefaultItemID((int)AItemHandle);
  VAR* Var = FVars->Vars[(int)ARecordHandle];
  Variant Result;
  switch (AColumnId) {
    case IndexOforVarName:
      Result = Var->VarName;
      break;
    case IndexOforBase:
      Result = Var->Base;
      break;
    case IndexOforOverlay:
      Result = Var->Overlay;
      break;
    case IndexOforStack:
      Result = Var->Stack;
      break;
    case IndexOforSkip:
      Result = Var->Skip;
      break;
    case IndexOforMark:
      Result = Var->Mark;
      break;
  }
  return (Result);
}
//---------------------------------------------------------------------------

void __fastcall TVarDataSource::Notify(void * Ptr, TListNotification Action)
{
  DataChanged();
}
//---------------------------------------------------------------------------

void __fastcall TVarDataSource::SetValue(void * ARecordHandle, void * AItemHandle, const Variant &AValue)
{
  // gets values from grid and stores them
  int AColumnId = GetDefaultItemID((int)AItemHandle);
  VAR* Var = FVars->Vars[(int)ARecordHandle];
  switch (AColumnId) {
    case IndexOforVarName:
	  Var->VarName = VarToStr(AValue);
	  break;
    case IndexOforBase:
      Var->Base = AValue;
      break;
    case IndexOforOverlay:
      Var->Overlay = AValue;
      break;
    case IndexOforStack:
      Var->Stack = AValue;
	  break;
    case IndexOforSkip:
      Var->Skip = AValue;
      break;
    case IndexOforMark:
      Var->Mark = AValue;
      break;
  }
}

//---------------------------------------------------------------------------
__fastcall TOrderForm::TOrderForm(TComponent* Owner)
        : TForm(Owner)
{
   DoubleBuffered = true;
   Diag = (TTGDiagram*)Owner;
}
//---------------------------------------------------------------------------

void __fastcall TOrderForm::FormActivate(TObject *Sender)
{
   Screen->Cursor = crHourGlass;

   VarList = new TVarList();
   VarDataSource = new TVarDataSource(VarList);
   GenerateVarColumns();
   LoadVarData();

   CurPos = 0;

   FocusControl(OrderGrid);
   Screen->Cursor = crDefault;
}
//---------------------------------------------------------------------------

void __fastcall TOrderForm::FormDeactivate(TObject *Sender)
{
   Application->OnIdle = NULL;
   delete VarList;
   delete VarDataSource;
}
//---------------------------------------------------------------------------

void __fastcall TOrderForm::GenerateVarColumns()
{
   orVarName->DataBinding->Data = (void*)IndexOforVarName;
   orBase->DataBinding->Data = (TObject *)IndexOforBase;
   orOverlay->DataBinding->Data = (TObject *)IndexOforOverlay;
   orStack->DataBinding->Data = (TObject *)IndexOforStack;
   orSkip->DataBinding->Data = (TObject *)IndexOforSkip;
   orMark->DataBinding->Data = (TObject *)IndexOforMark;
   // this line is critical
   OrderGridTableView->DataController->CustomDataSource = VarDataSource;
}
//---------------------------------------------------------------------------

void __fastcall TOrderForm::LoadVarData()
{
  for (int i=0; i<Diag->grf->Count; i++) {
    GRAPH *g = (GRAPH*)Diag->grf->Items[i];
    UnicodeString TempStr = g->code.SubString(1, 5);
     if (TempStr == "Chron")
       continue;
     if (TempStr == "Depth")
       continue;
     if (TempStr == "Thick")
       continue;
     if (TempStr == "Error")
       continue;

    VAR *v = new VAR;
    v->VarName = g->name.TrimRight();
    v->VarCode = g->code.TrimRight();
    if (g->status == BASE)
      v->Base = true;
    else if (g->status == OVERLAY)
      v->Overlay = true;
    else if (g->status == STACKED)
      v->Stack = true;
    else if (g->status == SKIP)
      v->Skip = true;
    v->Mark = false;
    VarList->Add(v);
    }
  OrderGridTableView->DataController->GotoFirst();
}
//---------------------------------------------------------------------------

// Up Arrow
void __fastcall TOrderForm::BitBtn1Click(TObject *Sender)
{
   TcxCustomGridRecord *ARecord;

   int cnt = OrderGridTableView->Controller->SelectedRecordCount;
   if (cnt < 1) return;   // no selected records

   ARecord = OrderGridTableView->Controller->SelectedRecords[0];
   if (ARecord->Index < 1) {   // already at top
      FocusControl(OrderGrid);
      return;
      }

   int *SelectedRecords = new int [cnt];

   ARecord = OrderGridTableView->Controller->FocusedRecord;
   int FocusedRecordIndex = ARecord->Index;

   for (int i=0; i<cnt; i++) {
     ARecord = OrderGridTableView->Controller->SelectedRecords[i];
     SelectedRecords[i] = ARecord->Index;
     }

   for (int i=0; i<cnt; i++) {
     ARecord = OrderGridTableView->ViewData->Records[SelectedRecords[i]];
     VarList->Exchange(ARecord->Index, ARecord->Index-1);
     }

   for (int i=0; i<cnt; i++) {
     ARecord = OrderGridTableView->ViewData->Records[SelectedRecords[i]];
     ARecord->Selected = false;
     }

   for (int i=0; i<cnt; i++) {
     ARecord = OrderGridTableView->ViewData->Records[SelectedRecords[i]-1];
     ARecord->Selected = true;
     }
   OrderGridTableView->Controller->FocusedRecordIndex = FocusedRecordIndex-1;

   delete[] SelectedRecords;
   FocusControl(OrderGrid);
}

//---------------------------------------------------------------------------
// Down Arrow
void __fastcall TOrderForm::BitBtn2Click(TObject *Sender)
{
   TcxCustomGridRecord *ARecord;

   int cnt = OrderGridTableView->Controller->SelectedRecordCount;
   if (cnt < 1) return;  // no selected records

   ARecord = OrderGridTableView->Controller->SelectedRecords[cnt-1];
   if (ARecord->Index >= VarList->Count-1) {   // already at bottom
      FocusControl(OrderGrid);
      return;
      }

   int *SelectedRecords = new int [cnt];

   ARecord = OrderGridTableView->Controller->FocusedRecord;
   int FocusedRecordIndex = ARecord->Index;

   for (int i=0; i<cnt; i++) {
     ARecord = OrderGridTableView->Controller->SelectedRecords[i];
     SelectedRecords[i] = ARecord->Index;
     }

   for (int i=cnt-1; i>=0; i--) {
     ARecord = OrderGridTableView->ViewData->Records[SelectedRecords[i]];
     VarList->Exchange(ARecord->Index, ARecord->Index+1);
     }

   for (int i=0; i<cnt; i++) {
     ARecord = OrderGridTableView->ViewData->Records[SelectedRecords[i]];
     ARecord->Selected = false;
     }

   for (int i=cnt-1; i>=0; i--) {
     ARecord = OrderGridTableView->ViewData->Records[SelectedRecords[i]+1];
     ARecord->Selected = true;
     }
   OrderGridTableView->Controller->FocusedRecordIndex = FocusedRecordIndex+1;

   delete[] SelectedRecords;
   FocusControl(OrderGrid);
}
//---------------------------------------------------------------------------

// Mark button
void __fastcall TOrderForm::BitBtn3Click(TObject *Sender)
{
   int cnt = OrderGridTableView->Controller->SelectedRecordCount;
   if (cnt < 1) return;  // no selected records

   TcxCustomGridRecord *ARecord;
   VAR *Var;

   for (int i=0; i<cnt; i++) {
     ARecord = OrderGridTableView->Controller->SelectedRecords[i];
     Var = VarList->Vars[ARecord->Index];
     Var->Mark = !Var->Mark;
     }

   CheckForMarkedRecords(false);
   FocusControl(OrderGrid);
   // forces Mark to be posted
   orVarName->Focused = true;
}
//---------------------------------------------------------------------------

void __fastcall TOrderForm::orMarkPropertiesEditValueChanged(
      TObject *Sender)
{
  CheckForMarkedRecords(true);
}
//---------------------------------------------------------------------------

void TOrderForm::CheckForMarkedRecords(bool Reverse)
{
   bool Marked = false;
   TcxCustomGridRecord *ARecord;

   for (int i=0; i<OrderGridTableView->ViewData->RecordCount; i++) {
     ARecord = OrderGridTableView->ViewData->Records[i];
     bool Mark = ARecord->Values[5];
     if (Reverse && ARecord->Focused)
       Mark = !Mark;
     if (Mark) {
       Marked = true;
       break;
       }
     }

   if (Marked) {
     BitBtn4->Enabled = true;
     BitBtn5->Enabled = true;
     }
   else {
     BitBtn4->Enabled = false;
     BitBtn5->Enabled = false;
     }
}
//---------------------------------------------------------------------------

// Insert above button
void __fastcall TOrderForm::BitBtn4Click(TObject *Sender)
{
   TcxCustomGridRecord *ARecord;
   VAR *Var;

   ARecord = OrderGridTableView->Controller->FocusedRecord;
   int FocusedRecordIndex = ARecord->Index;

   vector<int> MarkedRecords;

   // get list of marked records
   for (int i=0; i<OrderGridTableView->ViewData->RecordCount; i++) {
     ARecord = OrderGridTableView->ViewData->Records[i];
     bool Mark = ARecord->Values[5];
     if (Mark)
       MarkedRecords.push_back(ARecord->Index);  //**
     }

   // move all records originally above the focused record
   int k = 1;
   for (int i=MarkedRecords.size()-1; i>=0; i--) {
     ARecord = OrderGridTableView->ViewData->Records[MarkedRecords[i]];
     if (ARecord->Index < FocusedRecordIndex)
       VarList->Move(ARecord->Index, FocusedRecordIndex-k++);  //**
     }

   // move all records originally below the focused record
   int FocusedRecordIndex1 = FocusedRecordIndex;
   int FocusedRecordIndex2 = FocusedRecordIndex;
   for (unsigned int i=0; i<MarkedRecords.size(); i++) {
     ARecord = OrderGridTableView->ViewData->Records[MarkedRecords[i]];
     if (ARecord->Index > FocusedRecordIndex1) {
       VarList->Move(ARecord->Index, FocusedRecordIndex2++); //**
       ARecord = OrderGridTableView->Controller->FocusedRecord;
       ARecord->Selected = false;
       OrderGridTableView->Controller->FocusedRecordIndex++;
       }
     }

   OrderGridTableView->LayoutChanged(true);
   FocusControl(OrderGrid);
}
//---------------------------------------------------------------------------

// Insert below button
void __fastcall TOrderForm::BitBtn5Click(TObject *Sender)
{
   TcxCustomGridRecord *ARecord;
   VAR *Var;

   ARecord = OrderGridTableView->Controller->FocusedRecord;
   int FocusedRecordIndex = ARecord->Index;

   vector<int> MarkedRecords;

   // get list of marked records
   for (int i=0; i<OrderGridTableView->ViewData->RecordCount; i++) {
     ARecord = OrderGridTableView->ViewData->Records[i];
     bool Mark = ARecord->Values[5];
     if (Mark)
       MarkedRecords.push_back(ARecord->Index);  //**
     }

   // move all records originally below the focused record
   int k = 1;
   for (unsigned int i=0; i<MarkedRecords.size(); i++) {
     ARecord = OrderGridTableView->ViewData->Records[MarkedRecords[i]];
     if (ARecord->Index > FocusedRecordIndex)
       VarList->Move(ARecord->Index, FocusedRecordIndex+k++);  //**
     }

   // move all records originally above the focused record
   //int InsertPostion = FocusedRecordIndex + 1;
   int FocusedRecordIndex1 = FocusedRecordIndex;
   int FocusedRecordIndex2 = FocusedRecordIndex;
   for (int i=MarkedRecords.size()-1; i>=0; i--) {
     ARecord = OrderGridTableView->ViewData->Records[MarkedRecords[i]];
     if (ARecord->Index < FocusedRecordIndex1) {
       VarList->Move(ARecord->Index, FocusedRecordIndex2--);  //**
       ARecord = OrderGridTableView->Controller->FocusedRecord;
       ARecord->Selected = false;
       OrderGridTableView->Controller->FocusedRecordIndex--;
       }
     }

   OrderGridTableView->LayoutChanged(true);
   FocusControl(OrderGrid);
}
//---------------------------------------------------------------------------

void __fastcall TOrderForm::orOverlayPropertiesChange(TObject *Sender)
{
   TcxCustomGridRecord *ARecord = OrderGridTableView->Controller->FocusedRecord;
   if (ARecord) {
     VAR *Var = VarList->Vars[ARecord->Index];
     if (ARecord->Index == 0 || Var->Base) {
       ((TcxCheckBox*)Sender)->Checked = false;  // return if top row
       }
     else {
       bool Overlay = ((TcxCheckBox*)Sender)->Checked;
       if (Overlay) {
         VAR *VarAbove = VarList->Vars[ARecord->Index-1];
         if (VarAbove->Stack || VarAbove->Skip) {
           ((TcxCheckBox*)Sender)->Checked = false;
           }
         else {
           if (!VarAbove->Overlay && !VarAbove->Base)  // turn base on if necessary
             VarAbove->Base = true;
           Var->Stack = false;   // turn Stack off
           Var->Base = false;    // turn Base off
           }
         }
       }
     }
}
//---------------------------------------------------------------------------

void __fastcall TOrderForm::orStackPropertiesChange(TObject *Sender)
{
   TcxCustomGridRecord *ARecord = OrderGridTableView->Controller->FocusedRecord;
   if (ARecord) {
     VAR *Var = VarList->Vars[ARecord->Index];
     if (ARecord->Index == 0 || Var->Base) {
       ((TcxCheckBox*)Sender)->Checked = false;  // return if top row
       }
     else {
       bool Stack = ((TcxCheckBox*)Sender)->Checked;
       if (Stack) {
         VAR *VarAbove = VarList->Vars[ARecord->Index-1];
         if (VarAbove->Overlay || VarAbove->Skip) {
           ((TcxCheckBox*)Sender)->Checked = false;
           }
         else {
           if (!VarAbove->Stack && !VarAbove->Base)  // turn base on if necessary
             VarAbove->Base = true;
           Var->Overlay = false;   // turn Overlay off
           Var->Base = false;      // turn Base off
           }
         }
       }
     }
}
//---------------------------------------------------------------------------

void __fastcall TOrderForm::orSkipPropertiesChange(TObject *Sender)
{
   TcxCustomGridRecord *ARecord = OrderGridTableView->Controller->FocusedRecord;
   if (ARecord) {
     VAR *Var = VarList->Vars[ARecord->Index];
     // if Skip, then turn Base, Overlay, and Stack off
     bool Skip = ((TcxCheckBox*)Sender)->Checked;
     if (Skip) {
       Var->Base = false;
       Var->Overlay = false;
       Var->Stack = false;
       if (ARecord->Index > 0) {
         VAR *VarAbove = VarList->Vars[ARecord->Index-1];
         VarAbove->Base = false;
         }
       if (ARecord->Index < VarList->Count-1) {
         for (int i=ARecord->Index+1; i<VarList->Count; i++) {
           VAR *VarBelow = VarList->Vars[i];
           if (VarBelow->Overlay)
             VarBelow->Overlay = false;
           else if (VarBelow->Stack)
             VarBelow->Stack = false;
           else
             break;
           }
         }
       }
     }
}
//---------------------------------------------------------------------------

void __fastcall TOrderForm::orBasePropertiesChange(TObject *Sender)
{
   TcxCustomGridRecord *ARecord = OrderGridTableView->Controller->FocusedRecord;
   if (ARecord) {
     VAR *Var = VarList->Vars[ARecord->Index];
     if (ARecord->Index == VarList->Count-1 || Var->Overlay || Var->Stack || Var->Skip) {
       ((TcxCheckBox*)Sender)->Checked = false;
       }
     else {
       bool Base = ((TcxCheckBox*)Sender)->Checked;
       if (Base) {
         if (ARecord->Index > 0) {
           VAR *VarAbove = VarList->Vars[ARecord->Index-1];
           if (VarAbove->Base) {
             ((TcxCheckBox*)Sender)->Checked = false;
             return;
             }
           }
         if (ARecord->Index < VarList->Count-1) {
           VAR *VarBelow = VarList->Vars[ARecord->Index+1];
           if (VarBelow->Base) {
             ((TcxCheckBox*)Sender)->Checked = false;
             return;
             }
           }
         }
       else {
         for (int i=ARecord->Index+1; i<VarList->Count; i++) {
           VAR *VarBelow = VarList->Vars[i];
           if (VarBelow->Overlay)
             VarBelow->Overlay = false;
           else if (VarBelow->Stack)
             VarBelow->Stack = false;
           else
             break; 
           }
         }
       }
     }
}
//---------------------------------------------------------------------------

// overlay column
void __fastcall TOrderForm::Button1Click(TObject *Sender)
{
   TcxCustomGridRecord *ARecord;
   VAR* Var;

   ARecord = OrderGridTableView->Controller->SelectedRecords[0];
   Var = VarList->Vars[ARecord->Index];
   if (ARecord->Index > 0) {
     VAR* VarAbove = VarList->Vars[ARecord->Index-1];
     if (VarAbove->Base) {
       OrderGridTableView->LayoutChanged(true);
       FocusControl(OrderGrid);
       return;
       }
     }
   Var->Base = true;
   Var->Overlay = false;
   Var->Stack = false;
   Var->Skip = false;

   for (int i=1; i<OrderGridTableView->Controller->SelectedRecordCount; i++) {
     ARecord = OrderGridTableView->Controller->SelectedRecords[i];
     Var = VarList->Vars[ARecord->Index];
     Var->Overlay = true;
     Var->Base = false;
     Var->Stack = false;
     Var->Skip = false;
     }

   if (ARecord->Index < VarList->Count-1) {
     for (int i=ARecord->Index+1; i<VarList->Count; i++) {
       VAR *VarBelow = VarList->Vars[i];
       if (VarBelow->Overlay)
         VarBelow->Overlay = false;
       else if (VarBelow->Stack)
         VarBelow->Stack = false;
       else
         break;
       }
     }

   OrderGridTableView->LayoutChanged(true);
   FocusControl(OrderGrid);
}

//---------------------------------------------------------------------------
// stack column
void __fastcall TOrderForm::Button2Click(TObject *Sender)
{
   TcxCustomGridRecord *ARecord;
   VAR* Var;

   ARecord = OrderGridTableView->Controller->SelectedRecords[0];
   Var = VarList->Vars[ARecord->Index];
   if (ARecord->Index > 0) {
     VAR* VarAbove = VarList->Vars[ARecord->Index-1];
     if (VarAbove->Base) {
       OrderGridTableView->LayoutChanged(true);
       FocusControl(OrderGrid);
       return;
       }
     }
   Var->Base = true;
   Var->Overlay = false;
   Var->Stack = false;
   Var->Skip = false;

   for (int i=1; i<OrderGridTableView->Controller->SelectedRecordCount; i++) {
     ARecord = OrderGridTableView->Controller->SelectedRecords[i];
     Var = VarList->Vars[ARecord->Index];
     Var->Base = false;
     Var->Overlay = false;
     Var->Stack = true;
     Var->Skip = false;
     }

   if (ARecord->Index < VarList->Count-1) {
     for (int i=ARecord->Index+1; i<VarList->Count; i++) {
       VAR *VarBelow = VarList->Vars[i];
       if (VarBelow->Overlay)
         VarBelow->Overlay = false;
       else if (VarBelow->Stack)
         VarBelow->Stack = false;
       else
         break;
       }
     }

   OrderGridTableView->LayoutChanged(true);
   FocusControl(OrderGrid);
}

//---------------------------------------------------------------------------
// skip column
void __fastcall TOrderForm::Button3Click(TObject *Sender)
{
   TcxCustomGridRecord *ARecord;
   VAR* Var;

   ARecord = OrderGridTableView->Controller->SelectedRecords[0];
   // Var = VarList->Vars[ARecord->Index];
   if (ARecord->Index > 0) {
     VAR* VarAbove = VarList->Vars[ARecord->Index-1];
     VarAbove->Base = false;
     }

   for (int i=0; i<OrderGridTableView->Controller->SelectedRecordCount; i++) {
     ARecord = OrderGridTableView->Controller->SelectedRecords[i];
     Var = VarList->Vars[ARecord->Index];
     Var->Base = false;
     Var->Overlay = false;
     Var->Stack = false;
     Var->Skip = true;
     }

   if (ARecord->Index < VarList->Count-1) {
     for (int i=ARecord->Index+1; i<VarList->Count; i++) {
       VAR *VarBelow = VarList->Vars[i];
       if (VarBelow->Overlay)
         VarBelow->Overlay = false;
       else if (VarBelow->Stack)
         VarBelow->Stack = false;
       else
         break;
       }
     }

   OrderGridTableView->LayoutChanged(true);
   FocusControl(OrderGrid);
}
//---------------------------------------------------------------------------

// Ok button
void __fastcall TOrderForm::Button4Click(TObject *Sender)
{
  VAR *Var;

  Screen->Cursor = crHourGlass;
  Diag->Modified = true;
  CheckCheckBoxes();

  int k = 0;

  for (int i=0; i<Diag->grf->Count; i++) {
    GRAPH *g = (GRAPH*)Diag->grf->Items[i];
    UnicodeString Code = g->code.SubString(1, 5);
    if (Code == "Chron" || Code == "Depth" || Code == "Thick" || Code == "Error")
      continue;
    Var = VarList->Vars[k++];
    if (g->code != Var->VarCode) {
      for (int j=i+1; j<Diag->grf->Count; j++) {
        GRAPH *gj = (GRAPH*)Diag->grf->Items[j];
        if (gj->code == Var->VarCode) {
          gj->name = Var->VarName;
          if (Var->Base)
            gj->status = BASE;
          else if (Var->Overlay)
            gj->status = OVERLAY;
          else if (Var->Stack)
            gj->status = STACKED;
          else if (Var->Skip)
            gj->status = SKIP;
          else
            gj->status = NORMAL;
          Diag->grf->Move(j,i);
          break;
          }
        }
      }
    else {
      g->name = Var->VarName;
      if (Var->Base)
        g->status = BASE;
      else if (Var->Overlay)
        g->status = OVERLAY;
      else if (Var->Stack)
        g->status = STACKED;
      else if (Var->Skip)
        g->status = SKIP;
      else
        g->status = NORMAL;
      }
    }
  Screen->Cursor = crHourGlass;
}
//---------------------------------------------------------------------------

void TOrderForm::CheckCheckBoxes(void)
{
  int i, k;
  bool BaseSet;

  VAR *Var;

  Screen->Cursor = crHourGlass;

  // check that base, overlay, and stack are unckecked for skipped graphs
  for (i=0; i<VarList->Count; i++) {
    Var = VarList->Vars[i];
    if (Var->Skip) {
      Var->Base = false;
      Var->Overlay = false;
      Var->Stack = false;
      }
    }

  // check that first non-skipped graph is not stack or overlay
  for (i=0; i<VarList->Count; i++) {
    Var = VarList->Vars[i];
    if (!Var->Skip) {
      Var->Overlay = false;
      Var->Stack = false;
      break;
      }
    }

  // check that overlay and stack graphs are not base
  for (i=0; i<VarList->Count; i++) {
    Var = VarList->Vars[i];
    if (Var->Base && (Var->Overlay || Var->Stack))
      Var->Base = false;
    }

  // check that every base graph has an overlay or stack after it
  // before next base graph
  for (i=0; i<VarList->Count; i++) {
    Var = VarList->Vars[i];
    if (Var->Skip) continue;
    if (Var->Base) {
      for (k=i+1; k<VarList->Count; k++) {
        VAR *Var1 = VarList->Vars[k];
        if (Var1->Skip) continue;
        if (Var1->Base || (!Var1->Overlay && !Var1->Stack)) {
          Var->Base = false;
          break;
          }
        else if (Var1->Overlay || Var1->Stack)
          break;
        }
      if (k == VarList->Count)
        Var->Base = false;
      }
    }

  // check that all overlay and stack graphs have a base graph
  BaseSet = false;
  for (i=0; i<VarList->Count; i++) {
    Var = VarList->Vars[i];
    if (Var->Base) {
      BaseSet = true;
      continue;
      }
    if (!Var->Overlay && !Var->Stack && !Var->Skip) {
      BaseSet = false;
      continue;
      }
    if (!BaseSet && Var->Overlay)
      Var->Overlay = false;
    if (!BaseSet && Var->Stack)
      Var->Stack = false;
    }
  Screen->Cursor = crDefault;
}
//---------------------------------------------------------------------------
    
void TOrderForm::AutoItalics(UnicodeString& Name, UnicodeString& Code)
{
  int pos;
  if (Name.Pos("aceae") > 0) return;   // family name
  if (Name.Pos("ales") > 0) return;    // order name
  if (Name.Pos("oideae") > 0) return;  // subfamily name
  if (Name.Pos("<g>") > 0) return;     // Greek letters
  if (Code.SubString(1,3) == "SUM") return;

  if ((pos = Name.Pos("-type")) > 0)
	Name.Insert("</i>", pos);
  else if  ((pos = Name.Pos(" undiff")) > 0)
	Name.Insert("</i>", pos);
  else
	Name.Insert("</i>", Name.Length()+1);

  if ((pos = Name.Pos(" subg. ")) > 0) {
	Name.Insert("<i>", pos+7);       // Pinus subg. Pinus
	Name.Insert("</i>", pos);
	}
  if ((pos = Name.Pos(" subgen. ")) > 0) {
    Name.Insert("<i>", pos+9);
    Name.Insert("</i>", pos);
    }

  if (Name.Pos("cf. ") == 1)
    Name.Insert("<i>", 5);
  else
    Name.Insert("<i>", 1);
}

//---------------------------------------------------------------------------

void TOrderForm::ToggleStyle(UnicodeString Style)
{
  FocusControl(OrderGrid);
  orVarName->Editing = true;

  if (OrderGridTableView->Controller->EditingController->Edit) {

    UnicodeString Text = ((TcxTextEdit*)OrderGridTableView->Controller->EditingController->Edit)->EditingText;
    if (SelLen > 0)
      Text.Insert(Style, CurPos+SelLen+1);
    Text.Insert(Style, CurPos+1);
    ((TcxTextEdit*)OrderGridTableView->Controller->EditingController->Edit)->EditingText = Text;
    OrderGridTableView->DataController->Post();
    FocusControl(OrderGrid);
    }
}
//---------------------------------------------------------------------------

void TOrderForm::ToggleStyle(int Style)
{
    FocusControl(OrderGrid);
    orVarName->Editing = true;

    if (OrderGridTableView->Controller->EditingController->Edit) {

      if (SelLen == 0) {
		MessageDlg("Must highlight at least one charcter.", Dialogs::mtError,
           TMsgDlgButtons() << mbOK, 0);
        return;
        }

      UnicodeString Text = ((TcxTextEdit*)OrderGridTableView->Controller->EditingController->Edit)->EditingText;

      int Advance = 0;
      FormatString(Text, Style, CurPos, SelLen, &Advance);

      ((TcxTextEdit*)OrderGridTableView->Controller->EditingController->Edit)->EditingText = Text;
      OrderGridTableView->DataController->Post();
      FocusControl(OrderGrid);
    }
}
//---------------------------------------------------------------------------

// Italic button
void __fastcall TOrderForm::BitBtn6Click(TObject *Sender)
{
   TcxCustomGridRecord *ARecord;
   VAR *Var;
   int pos;

   int cnt = OrderGridTableView->Controller->SelectedRecordCount;
   if (cnt > 1) {
     ItalicsForm = new TItalicsForm(this);
     if (ItalicsForm->ShowModal() == mrOk) {
        // remove italics
        for (int i=0; i<cnt; i++) {
          ARecord = OrderGridTableView->Controller->SelectedRecords[i];
          Var = VarList->Vars[ARecord->Index];

		  if ((pos = Var->VarName.Pos("<i>")) > 0) {   // remove italics
            do { Var->VarName.Delete(pos, 3);
			   } while ((pos = Var->VarName.Pos("<i>")) > 0);
			}
		  if ((pos = Var->VarName.Pos("</i>")) > 0) {   // remove italics
			do { Var->VarName.Delete(pos, 4);
               } while ((pos = Var->VarName.Pos("</i>")) > 0);
            }
          if (ItalicsForm->Action == ITALICIZE) {
            Var->VarName.Insert("<i>", 1);
            Var->VarName.Insert("</i>", Var->VarName.Length()+1);
            }
          else if (ItalicsForm->Action == AUTOITALICS)
            AutoItalics(Var->VarName, Var->VarCode);
          }
        }
     delete ItalicsForm;
     FocusControl(OrderGrid);
     orVarName->Editing = false;
     orVarName->Editing = true;
     }
   else
     ToggleStyle(ITALIC);
}
//---------------------------------------------------------------------------

// Bold button
void __fastcall TOrderForm::BitBtn7Click(TObject *Sender)
{
   TcxCustomGridRecord *ARecord;
   VAR *Var;
   int cnt = OrderGridTableView->Controller->SelectedRecordCount;
   if (cnt > 1) {
     for (int i=0; i<cnt; i++) {
       ARecord = OrderGridTableView->Controller->SelectedRecords[i];
       Var = VarList->Vars[ARecord->Index];
       Var->VarName.Insert("<b>", 1);
       Var->VarName.Insert("</b>", Var->VarName.Length()+1);
       }
     FocusControl(OrderGrid);
     orVarName->Editing = false;
     orVarName->Editing = true;
     }
   else
     ToggleStyle(BOLD);
}
//---------------------------------------------------------------------------

// insert Greek letters
void __fastcall TOrderForm::BitBtn8Click(TObject *Sender)
{
  GreekForm = new TGreekForm(this);
   if (GreekForm->ShowModal() == mrOk) {
     if (GreekForm->StaticText1->Caption.Length() > 0) {
       ToggleStyle(GreekForm->StaticText1->Caption);
       }
     }
   delete GreekForm;
}
//---------------------------------------------------------------------------

void __fastcall TOrderForm::BitBtn9Click(TObject *Sender)
{
  ToggleStyle(SUPERSCRIPT);
}
//---------------------------------------------------------------------------

void __fastcall TOrderForm::BitBtn10Click(TObject *Sender)
{
  ToggleStyle(SUBSCRIPT);
}
//---------------------------------------------------------------------------

void __fastcall TOrderForm::OrderGridTableViewMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
   EnableButtons();
}
//---------------------------------------------------------------------------

void __fastcall TOrderForm::OrderGridTableViewInitEdit(
      TcxCustomGridTableView *Sender, TcxCustomGridTableItem *AItem,
      TcxCustomEdit *AEdit)
{
  ((TcxCustomEditAccess*)AEdit)->OnKeyUp = EditKeyUp;
  ((TcxCustomEditAccess*)AEdit)->OnKeyDown = EditKeyDown;
  ((TcxCustomEditAccess*)AEdit)->OnMouseUp = EditMouseUp;
  ((TcxCustomEditAccess*)AEdit)->OnMouseDown = EditMouseDown;
}
//---------------------------------------------------------------------------

void __fastcall TOrderForm::EditKeyUp(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
   EnableButtons();
}
//---------------------------------------------------------------------------

void __fastcall TOrderForm::EditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
   SelLen = 0;
   // for some reason the ENTER key doesn't move to the next cell when this
   // event handler replaces the normal OnKeyDown event. This fixes it.
   if (Key == VK_RETURN)
     Key = VK_RIGHT;
}
//---------------------------------------------------------------------------


void __fastcall TOrderForm::EditMouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
   EnableButtons();
}
//---------------------------------------------------------------------------

void __fastcall TOrderForm::EditMouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
   OrderGridTableView->DataController->Post();
   CurPos = 0;
}
//---------------------------------------------------------------------------

void TOrderForm::EnableButtons(void)
{
  TcxCustomGridRecord *ARecord;
  int cnt = OrderGridTableView->Controller->SelectedRecordCount;
  bool Enable;
  if (cnt > 1) {
    ARecord = OrderGridTableView->Controller->SelectedRecords[0];
    int idx = ARecord->Index;
    Enable = true;
    for (int i=1; i<cnt; i++) {
      ARecord = OrderGridTableView->Controller->SelectedRecords[i];
      if (ARecord->Index == idx+1)
        idx++;
      else {
        Enable = false;
        break;
        }
      }
    }
  else
    Enable = false;

  if (Enable) {
    Button1->Enabled = true;  // overlay button
    Button2->Enabled = true;  // stack button
    }
  else {
    Button1->Enabled = false;  // overlay button
    Button2->Enabled = false;  // stack button
    }
}
//---------------------------------------------------------------------------

void __fastcall TOrderForm::OrderGridTableViewFocusedItemChanged(
      TcxCustomGridTableView *Sender,
      TcxCustomGridTableItem *APrevFocusedItem,
      TcxCustomGridTableItem *AFocusedItem)
{
   if (AFocusedItem->Index == 0) {
     BitBtn6->Enabled = true;
     BitBtn7->Enabled = true;
     BitBtn8->Enabled = true;
     BitBtn9->Enabled = true;
     BitBtn10->Enabled = true;
     }
   else if (APrevFocusedItem->Index == 0) {
     BitBtn6->Enabled = false;
     BitBtn7->Enabled = false;
     BitBtn8->Enabled = false;
     BitBtn9->Enabled = false;
     BitBtn10->Enabled = false;
     }
}
//---------------------------------------------------------------------------

void __fastcall TOrderForm::Button6Click(TObject *Sender)
{
   Application->HelpContext(IDH_Variables_Dialog_Box);
}
//---------------------------------------------------------------------------

bool __fastcall TOrderForm::FormHelp(WORD Command, int Data, bool &CallHelp)
{
   return true;
}
//---------------------------------------------------------------------------

void __fastcall TOrderForm::OrderGridTableViewEditKeyUp(
      TcxCustomGridTableView *Sender, TcxCustomGridTableItem *AItem,
      TcxCustomEdit *AEdit, WORD &Key, TShiftState Shift)
{
   if (AItem->Index == 0) {
     CurPos = ((TcxTextEdit*)OrderGridTableView->Controller->EditingController->Edit)->CursorPos;
     SelLen = ((TcxTextEdit*)OrderGridTableView->Controller->EditingController->Edit)->SelLength;
     }
}
//---------------------------------------------------------------------------

void __fastcall TOrderForm::orVarNameGetDisplayText(
      TcxCustomGridTableItem *Sender, TcxCustomGridRecord *ARecord,
	  UnicodeString &AText)
{
   if (OrderGridTableView->Controller->EditingController->Edit) {
     if (OrderGridTableView->Controller->EditingController->Edit->IsFocused) {
       if (OrderGridTableView->Controller->EditingController->EditingItem->Index == 0) {
         CurPos = ((TcxTextEdit*)OrderGridTableView->Controller->EditingController->Edit)->CursorPos;
         SelLen = ((TcxTextEdit*)OrderGridTableView->Controller->EditingController->Edit)->SelLength;
         }
       }
     }
}
//---------------------------------------------------------------------------
