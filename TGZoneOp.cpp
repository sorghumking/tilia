//---------------------------------------------------------------------------

#include <vcl.h>
#include "pch.h"
#pragma hdrstop

#include "TGZoneOp.h"
#ifndef TGParentH
#include "TGParent.h"
#endif
#ifndef TGDiagrmH
#include "TGDiagrm.h"
#endif
#ifndef TGZoneLiH
#include "TGZoneLi.h"
#endif
#ifndef TGZoneScH
#include "TGZoneSc.h"
#endif
#ifndef TGUtilsH
#include "TGUtils.h"
#endif
#ifndef TGFntDlgH
#include "TGFntDlg.h"
#endif
#ifndef TGHelpH
#include "TGHelp.h"
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
#pragma link "cxContainer"
#pragma link "cxTextEdit"
#pragma link "cxImage"
#pragma link "cxButtonEdit"
#pragma link "cxCheckBox"
#pragma link "cxDataStorage"
#pragma link "cxDropDownEdit"
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
TZoneForm *ZoneForm;

//---------------------------------------------------------------------------
void TZoneList::ReleaseAllZones()
{
  for (int i = 0; i < Count; i++)
    ReleaseZone(i);
}
//---------------------------------------------------------------------------

void TZoneList::ReleaseZone(int AIndex)
{
  delete (ZONE*)Items[AIndex];
}
//---------------------------------------------------------------------------

ZONE* TZoneList::GetZone(int AIndex)
{
  return (ZONE*)Items[AIndex];
}
//---------------------------------------------------------------------------

void __fastcall TZoneList::Notify(void * Ptr, TListNotification Action)
{
  if (FOnNotify != NULL)
    FOnNotify(Ptr, Action);
}
//---------------------------------------------------------------------------

void __fastcall TZoneList::Clear(void)
{
  ReleaseAllZones();
}
//---------------------------------------------------------------------------

void TZoneList::Add(ZONE* Zone)
{
  TList::Add(Zone);
}
//---------------------------------------------------------------------------

void TZoneList::Delete(int AIndex)
{
  ReleaseZone(AIndex);
  TList::Delete(AIndex);
}
//---------------------------------------------------------------------------

void TZoneList::Insert(int AIndex, ZONE* Zone)
{
  TList::Insert(AIndex, Zone);
}
//---------------------------------------------------------------------------

__fastcall TZoneDataSource::TZoneDataSource(TZoneList* AZoneList, ZONE& DFZ, ZONE* NFZ)
{
  FZones = AZoneList;
  DefaultZone = DFZ;
  NewZone = NFZ;
  FZones->OnNotify = Notify;
}
//---------------------------------------------------------------------------

void __fastcall TZoneDataSource::DeleteRecord(void * ARecordHandle)
{
  FZones->Delete((int)ARecordHandle);
}
//---------------------------------------------------------------------------

int __fastcall TZoneDataSource::GetRecordCount(void)
{
  return(FZones->Count);
}
//---------------------------------------------------------------------------

Variant __fastcall TZoneDataSource::GetValue(void * ARecordHandle, void * AItemHandle)
{
  int AColumnId = GetDefaultItemID((int)AItemHandle);
  ZONE* Zone = FZones->Zones[(int)ARecordHandle];
  Variant Result;
  switch (AColumnId) {                  
    case IndexOfLevel:
      if (IsNan(Zone->depth))
        Result.ChangeType(varEmpty);
      else
        Result = Zone->depth;
      break;
    case IndexOfStyle:
      Result = (Zone->ZoneStyle == LINEZONE) ? "Line" : "Screen";
      break;
    case IndexOfOrder:
      Result = (Zone->Priority == ZONETOBACK) ? "To Back" : "To Front";
      break;
    case IndexOfLabCol:
      Result = Zone->ThruLabelCol;
      break;
  }
  return (Result);
}
//---------------------------------------------------------------------------

void __fastcall TZoneDataSource::Notify(void * Ptr, TListNotification Action)
{
  DataChanged();
}
//---------------------------------------------------------------------------

void * __fastcall TZoneDataSource::InsertRecord(void * ARecordHandle)
{
  ZONE* Zone = new ZONE;
  *Zone = DefaultZone;
  Zone->depth = NaN;
  FZones->Insert((int)ARecordHandle, Zone);
  TcxDataRecordHandle* Result = (TcxDataRecordHandle*)ARecordHandle;
  return (Result);
}
//---------------------------------------------------------------------------

void * __fastcall TZoneDataSource::AppendRecord(void)
{
  TcxDataRecordHandle* Result = (TcxDataRecordHandle*)FZones->Count;
  ZONE* Zone = new ZONE;
  *Zone = NewZone;   // 2-3-06
  *Zone = DefaultZone;
  Zone->depth = NaN;
  FZones->Add(Zone);
  return (Result);
}
//---------------------------------------------------------------------------

void __fastcall TZoneDataSource::SetValue(void * ARecordHandle, void * AItemHandle, const Variant &AValue)
{
  UnicodeString temp;

  int AColumnId = GetDefaultItemID((int)AItemHandle);
  ZONE* Zone = FZones->Zones[(int)ARecordHandle];
  switch (AColumnId) {
    case IndexOfLevel:
	  if (AValue.IsNull())
        Zone->depth = NaN;
      else
        Zone->depth = AValue;
      break;
    case IndexOfStyle:
      temp = AValue;
      if (temp == "Line")
        Zone->ZoneStyle = LINEZONE;
      else if (temp == "Screen")
        Zone->ZoneStyle = PATTERNZONE;
      break;
    case IndexOfOrder:
      temp = AValue;
      if (temp == "To Back")
        Zone->Priority = ZONETOBACK;
      else if (temp == "To Front")
        Zone->Priority = ZONETOFRONT;
      break;
    case IndexOfLabCol:
	  Zone->ThruLabelCol = AValue;
	  break;
  }
}
//---------------------------------------------------------------------------

void TZoneLabelList::ReleaseAllZoneLabels()
{
  for (int i = 0; i < Count; i++)
    ReleaseZoneLabel(i);
}
//---------------------------------------------------------------------------

void TZoneLabelList::ReleaseZoneLabel(int AIndex)
{
  delete (ZONELABELS*)Items[AIndex];
}
//---------------------------------------------------------------------------

ZONELABELS* TZoneLabelList::GetZoneLabel(int AIndex)
{
  return (ZONELABELS*)Items[AIndex];
}
//---------------------------------------------------------------------------

void __fastcall TZoneLabelList::Notify(void * Ptr, TListNotification Action)
{
  if (FOnNotify != NULL)
    FOnNotify(Ptr, Action);
}

//---------------------------------------------------------------------------

void __fastcall TZoneLabelList::Clear(void)
{
  ReleaseAllZoneLabels();
}
//---------------------------------------------------------------------------

void TZoneLabelList::Add(ZONELABELS* ZoneLabel)
{
  TList::Add(ZoneLabel);
}
//---------------------------------------------------------------------------

void TZoneLabelList::Delete(int AIndex)
{
  ReleaseZoneLabel(AIndex);
  TList::Delete(AIndex);
}
//---------------------------------------------------------------------------

void TZoneLabelList::Insert(int AIndex, ZONELABELS* ZoneLabel)
{
  TList::Insert(AIndex, ZoneLabel);
}
//---------------------------------------------------------------------------

__fastcall TZoneLabelDataSource::TZoneLabelDataSource(TZoneLabelList* AZoneLabelList)
{
  FZoneLabels = AZoneLabelList;
  FZoneLabels->OnNotify = Notify;
}
//---------------------------------------------------------------------------

void __fastcall TZoneLabelDataSource::DeleteRecord(void * ARecordHandle)
{
  FZoneLabels->Delete((int)ARecordHandle);
}
//---------------------------------------------------------------------------

int __fastcall TZoneLabelDataSource::GetRecordCount(void)
{
  return(FZoneLabels->Count);
}
//---------------------------------------------------------------------------

Variant __fastcall TZoneLabelDataSource::GetValue(void * ARecordHandle, void * AItemHandle)
{
  int AColumnId = GetDefaultItemID((int)AItemHandle);
  ZONELABELS* ZoneLabel = FZoneLabels->ZoneLabels[(int)ARecordHandle];
  Variant Result;
  switch (AColumnId) {
    case IndexOfTop:
      if (IsNan(ZoneLabel->top))
		Result.ChangeType(varEmpty);
      else
        Result = ZoneLabel->top;
      break;
    case IndexOfBottom:
      if (IsNan(ZoneLabel->bottom))
        Result.ChangeType(varEmpty);
      else
        Result = ZoneLabel->bottom;
      break;
    case IndexOfLabel:
      Result = ZoneLabel->label;
      break;
  }
  return (Result);
}
//---------------------------------------------------------------------------

void __fastcall TZoneLabelDataSource::Notify(void * Ptr, TListNotification Action)
{
  DataChanged();
}

//---------------------------------------------------------------------------

void * __fastcall TZoneLabelDataSource::InsertRecord(void * ARecordHandle)
{
  ZONELABELS* ZoneLabel = new ZONELABELS;
  ZoneLabel->top = NaN;
  ZoneLabel->bottom = NaN;
  FZoneLabels->Insert((int)ARecordHandle, ZoneLabel);
  TcxDataRecordHandle* Result = (TcxDataRecordHandle*)ARecordHandle;
  return (Result);
}
//---------------------------------------------------------------------------

void * __fastcall TZoneLabelDataSource::AppendRecord(void)
{
  TcxDataRecordHandle* Result = (TcxDataRecordHandle*)FZoneLabels->Count;
  ZONELABELS* ZoneLabel = new ZONELABELS;
  ZoneLabel->top = NaN;
  ZoneLabel->bottom = NaN;
  FZoneLabels->Add(ZoneLabel);
  return (Result);
}
//---------------------------------------------------------------------------

void __fastcall TZoneLabelDataSource::SetValue(void * ARecordHandle, void * AItemHandle, const Variant &AValue)
{
  int AColumnId = GetDefaultItemID((int)AItemHandle);
  ZONELABELS* ZoneLabel = FZoneLabels->ZoneLabels[(int)ARecordHandle];
  switch (AColumnId) {
    case IndexOfTop:
	  if (AValue.IsNull())
		ZoneLabel->top = NaN;
      else
        ZoneLabel->top = AValue;
      break;
    case IndexOfBottom:
	  if (AValue.IsNull())
        ZoneLabel->bottom = NaN;
      else
        ZoneLabel->bottom = AValue;
      break;
    case IndexOfLabel:
	  ZoneLabel->label = VarToStr(AValue);
      break;
  }
}
//---------------------------------------------------------------------------

__fastcall TZoneForm::TZoneForm(TComponent* Owner)
        : TForm(Owner)
{
   Diag = (TTGDiagram*)Owner;
}
//---------------------------------------------------------------------------

void __fastcall TZoneForm::FormCreate(TObject *Sender)
{
   PageControl1->ActivePage = Levels;
   OpeningTabSheet = LEVELS_TABSHEET;
}

//---------------------------------------------------------------------------
void __fastcall TZoneForm::FormActivate(TObject *Sender)
{
  int i;

  Change = true;
  InsertRow = false;

  if (OpeningTabSheet == LEVELS_TABSHEET) {
    PageControl1->ActivePage = Levels;
    FocusControl(LevelsGrid); }
  else {
    PageControl1->ActivePage = Labels;
    FocusControl(LabelsGrid); }

  DefaultZone = Diag->Default.ZoneAttr;
  ZoneList = new TZoneList();
  ZoneDataSource = new TZoneDataSource(ZoneList, DefaultZone, &NewZone);
  GenerateLevelColumns();
  LoadLevelData();

  ZoneLabelList = new TZoneLabelList();
  ZoneLabelDataSource = new TZoneLabelDataSource(ZoneLabelList);
  GenerateLabelColumns();
  LoadLabelData();
  
  ZoneLineForm = new TZoneLineForm(this);
  ZoneScreenForm = new TZoneScreenForm(this);

  // Text TabSheet
  LabeledEdit1->Text = Diag->zopt.ZoneTitle;
  LabeledEdit2->Text = Diag->zopt.ZoneTitleAngle;
  Change = false;
  if (Diag->zopt.Center) {
    CheckBox1->Checked = true;
    }
  else {
    CheckBox1->Checked = false;
    LabeledEdit3->Text = Diag->zopt.ZoneTitleXOffset;
    }
  Change = true;
  LabeledEdit4->Text = Diag->zopt.ZoneTitleYOffset;
  ZoneTitleFont = Diag->zopt.ZoneTitleFont;
  ZoneFont = Diag->zopt.ZoneFont;
  Screen->Cursor = crDefault;
}
//---------------------------------------------------------------------------

void __fastcall TZoneForm::GenerateLevelColumns()
{
   lvLevel->DataBinding->Data = (TObject*)IndexOfLevel;
   lvStyle->DataBinding->Data = (TObject *)IndexOfStyle;
   lvOrder->DataBinding->Data = (TObject *)IndexOfOrder;
   lvLabelColumn->DataBinding->Data = (TObject *)IndexOfLabCol;
   // this line is critical
   LevelsGridTableView->DataController->CustomDataSource = ZoneDataSource;
}
//---------------------------------------------------------------------------

void __fastcall TZoneForm::GenerateLabelColumns()
{
   lbTopDepth->DataBinding->Data = (TObject*)IndexOfTop;
   lbBottomDepth->DataBinding->Data = (TObject*)IndexOfBottom;
   lbLabel->DataBinding->Data = (TObject *)IndexOfLabel;
   // this line is critical
   LabelsGridTableView->DataController->CustomDataSource = ZoneLabelDataSource;
}

//---------------------------------------------------------------------------
void __fastcall TZoneForm::LoadLevelData()
{
  for (int i=0; i<Diag->Zones->Count; i++) {
    ZONE *Zone = new ZONE((ZONE*)Diag->Zones->Items[i]);
    ZoneList->Add(Zone);
    }
  LevelsGridTableView->DataController->GotoFirst();
}
//---------------------------------------------------------------------------

void __fastcall TZoneForm::LoadLabelData()
{
  for (int i=0; i<Diag->ZoneLabels->Count; i++) {
    ZONELABELS *ZoneLabel = new ZONELABELS((ZONELABELS*)Diag->ZoneLabels->Items[i]);
    ZoneLabelList->Add(ZoneLabel);
    }
  LabelsGridTableView->DataController->GotoFirst();
}
//---------------------------------------------------------------------------

void TZoneForm::SetLineZoneOptions(ZONE *SourceZone, ZONE *DestZone)
{
   DestZone->LineStyle = SourceZone->LineStyle;
   if (SourceZone->LineStyle == USER_DEFINED_LINE)
     DestZone->user = SourceZone->user;
   DestZone->LineWidth = SourceZone->LineWidth;
   DestZone->ZoneColor = SourceZone->ZoneColor;
}
//---------------------------------------------------------------------------

void TZoneForm::SetScreenZoneOptions(ZONE *SourceZone, ZONE *DestZone)
{
   DestZone->Pattern = SourceZone->Pattern;
   if (SourceZone->Pattern == 35)
     DestZone->user = SourceZone->user;
   DestZone->ZoneColor = SourceZone->ZoneColor;
   DestZone->BorderColor = SourceZone->BorderColor;
   DestZone->ZoneWidth = SourceZone->ZoneWidth;
   DestZone->Border = SourceZone->Border;
   DestZone->LineWidth = SourceZone->LineWidth;
}

//---------------------------------------------------------------------------
void __fastcall TZoneForm::FormDeactivate(TObject *Sender)
{
   delete ZoneLineForm;
   delete ZoneScreenForm;
   delete ZoneList;
   delete ZoneDataSource;
   delete ZoneLabelList;
   delete ZoneLabelDataSource;
}
//---------------------------------------------------------------------------

// Ok button
void __fastcall TZoneForm::Button1Click(TObject *Sender)
{
   Diag->Modified = true;
   ApplyOptions();
}
//---------------------------------------------------------------------------

void TZoneForm::ApplyOptions(void)
{
   int i;
   //long ThruLabelCol;
   UnicodeString buff;
   double Temp;
   ZONE *Zone;
   ZONELABELS *ZoneLabel;

   // delete old Zones
   if (Diag->Zones->Count > 0) {
     for (i=0; i<Diag->Zones->Count; i++) {
       Zone = (ZONE*)Diag->Zones->Items[i];
       delete Zone;
       Diag->Zones->Items[i] = 0;
       }
     Diag->Zones->Clear();
     Diag->Zones->Capacity = 100;
     }

   // add new Zones;
   if (ZoneList->Count > 0) {
     for (i=0; i<ZoneList->Count; i++) {
       Zone = ZoneList->Zones[i];
       if (!IsNan(Zone->depth)) {
         Zone = new ZONE(ZoneList->Zones[i]);
         Diag->Zones->Add(Zone);
         }
       }
     }
   Diag->Zones->Sort(ZoneSortCompare);

   Diag->Default.ZoneAttr = DefaultZone;
   // Check if all zone colors are the same. If so, set default zone color
   if (Diag->Zones->Count == 1) {
     Zone = (ZONE*)Diag->Zones->Items[0];
	 Diag->Default.ZoneAttr.ZoneColor = Zone->ZoneColor;
     }
   else if (Diag->Zones->Count > 1) {
     Zone = (ZONE*)Diag->Zones->Items[0];
     int color = Zone->ZoneColor;
     bool SameColor = true;
     for (i=1; i<Diag->Zones->Count; i++) {
       Zone = (ZONE*)Diag->Zones->Items[i];
       if (Zone->ZoneColor != color) {
         SameColor = false;
         break;
         }
       }
     if (SameColor)
	   Diag->Default.ZoneAttr.ZoneColor = Zone->ZoneColor;
     }

   // Labels tab sheet
   // delete old zone labels
   if (Diag->ZoneLabels->Count > 0) {
     for (i=0; i<Diag->ZoneLabels->Count; i++) {
       ZoneLabel = (ZONELABELS*)Diag->ZoneLabels->Items[i];
       delete ZoneLabel;
       Diag->ZoneLabels->Items[i] = 0;
       }
     Diag->ZoneLabels->Clear();
     Diag->ZoneLabels->Capacity = 100;
     }

   // add new zones labels;
   if (ZoneLabelList->Count > 0) {
     for (i=0; i<ZoneLabelList->Count; i++) {
       ZoneLabel = ZoneLabelList->ZoneLabels[i];
       if (!(IsNan(ZoneLabel->top) || IsNan(ZoneLabel->bottom))) {
         ZoneLabel = new ZONELABELS(ZoneLabelList->ZoneLabels[i]);
         Diag->ZoneLabels->Add(ZoneLabel);
         }
       }
     }
   // TODO: SORT ZONE LABELS?


   // Text tab sheet
   Diag->zopt.ZoneTitle = LabeledEdit1->Text;

   try {
     Temp = StrToFloat(LabeledEdit2->Text);  }
   catch (...) {
     Temp = Diag->zopt.ZoneTitleAngle; }
   Diag->zopt.ZoneTitleAngle = Temp;

   Diag->zopt.ZoneTitleFont = ZoneTitleFont;

   if (CheckBox1->Checked)
     Diag->zopt.Center = true;
   else {
     Diag->zopt.Center = false;
     if (LabeledEdit3->Text.IsEmpty())
       Diag->zopt.ZoneTitleXOffset = 0.0;
     else
       Diag->zopt.ZoneTitleXOffset = StrToFloatDef(LabeledEdit3->Text, Diag->zopt.ZoneTitleXOffset);
     }

   Diag->zopt.ZoneTitleYOffset = StrToFloatDef(LabeledEdit4->Text, Diag->zopt.ZoneTitleYOffset);

   Diag->zopt.ZoneFont = ZoneFont;
}
//---------------------------------------------------------------------------

int __fastcall TZoneForm::ZoneSortCompare(void * Item1, void * Item2)
{
   ZONE* Zone1 = (ZONE*)Item1;
   ZONE* Zone2 = (ZONE*)Item2;

   if (Zone1->depth < Zone2->depth)
     return -1;
   else if (Zone1->depth > Zone2->depth)
     return 1;
   else
     return 0;
}
//---------------------------------------------------------------------------

// import levels
void __fastcall TZoneForm::BitBtn7Click(TObject *Sender)
{
   int Row;
   LEVELS *Lev;
   ZONE *Zone;

   if (ZoneList->Count == 0) {
	 MessageDlg("No levels entered", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
     return;
     }

   if (ZoneLabelList->Count > 0) {
	 LabelsGridTableView->DataController->MultiSelect = true;
     LabelsGridTableView->DataController->SelectAll();
     try {
       LabelsGridTableView->DataController->DeleteSelection(); }
     catch(Exception &e) {
	   MessageDlg("Cannot delete records due to the exception: " + e.Message, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
       return;
       }
     LabelsGridTableView->DataController->MultiSelect = false;
     }

   Zone = ZoneList->Zones[0];
   Lev = (LEVELS*)Diag->Levs->Items[0];
   if (Lev->num < Zone->depth) {
     ZONELABELS* ZoneLabel = new ZONELABELS;
     ZoneLabel->top = Lev->num;
     ZoneLabel->bottom = Zone->depth;
     ZoneLabelList->Add(ZoneLabel);
     }

   for (int i=0; i<ZoneList->Count-1; i++) {
     ZONELABELS* ZoneLabel = new ZONELABELS;
     Zone = ZoneList->Zones[i];
     ZoneLabel->top = Zone->depth;
     Zone = ZoneList->Zones[i+1];
     ZoneLabel->bottom = Zone->depth;
     ZoneLabelList->Add(ZoneLabel);
     }

   Lev = (LEVELS*)Diag->Levs->Items[Diag->Levs->Count-1];
   if (Zone->depth < Lev->num) {
     ZONELABELS* ZoneLabel = new ZONELABELS;
     ZoneLabel->top = Zone->depth;
     ZoneLabel->bottom = Lev->num;
     ZoneLabelList->Add(ZoneLabel);
     }
}
//---------------------------------------------------------------------------
 
void __fastcall TZoneForm::BitBtn1Click(TObject *Sender)
{
   TFontDialogBox* FontForm = new TFontDialogBox(this);
   FontForm->SetFont(ZoneTitleFont);
   if (FontForm->ShowModal() == mrOk)
     FontForm->GetFont(ZoneTitleFont);
   delete FontForm;
}
//---------------------------------------------------------------------------

void __fastcall TZoneForm::LabeledEdit3Change(TObject *Sender)
{
  if (Change)
    CheckBox1->Checked = false;
}
//---------------------------------------------------------------------------

void __fastcall TZoneForm::CheckBox1Click(TObject *Sender)
{
  if (!Change) return;
  Change = false;
  if (CheckBox1->Checked)
    LabeledEdit3->Clear();
  Change = true;
}
//---------------------------------------------------------------------------

void __fastcall TZoneForm::BitBtn3Click(TObject *Sender)
{
   TFontDialogBox* FontForm = new TFontDialogBox(this);
   FontForm->SetFont(ZoneFont);
   if (FontForm->ShowModal() == mrOk)
     FontForm->GetFont(ZoneFont);
   delete FontForm;
}
//---------------------------------------------------------------------------

// Apply button
void __fastcall TZoneForm::Button8Click(TObject *Sender)
{
   Diag->Modified = true;
   ApplyOptions();
   Diag->make_diagram();
   Diag->Picture->OutputGraphicObjects(DISPLAY, (TTGDiagram*)ParentForm->ActiveMDIChild);
   if (PageControl1->ActivePage == Levels)
     FocusControl(LevelsGrid);
   else if (PageControl1->ActivePage == Labels)
     FocusControl(LabelsGrid);
   else if (PageControl1->ActivePage == Text)
     FocusControl(LabeledEdit1);
}
//---------------------------------------------------------------------------

void __fastcall TZoneForm::lvOptionsPropertiesButtonClick(TObject *Sender,
      int AButtonIndex)
{
   UnicodeString Style;

   TcxCustomGridRecord *AFocusedRecord =
       LevelsGridTableView->Controller->FocusedRecord;

   // 2-3-06
   ZONE *Zone;
   if (AFocusedRecord->RecordIndex == -1) {
     Style = (NewZone.ZoneStyle == LINEZONE) ? "Line" : "Screen";
     Zone = &NewZone;
     }
   else  {
     Style = LevelsGridTableView->DataController->Values[AFocusedRecord->RecordIndex][1];
     Zone = ZoneList->Zones[AFocusedRecord->RecordIndex];
     }

   if (Style == "Line") {
     ZoneLineForm->LabeledEdit1->Color = clBtnFace;
     ZoneLineForm->LabeledEdit2->Color = clBtnFace;
     switch (Zone->LineStyle) {
       case SOLID_LINE:
         ZoneLineForm->ToolButton1->Down = true;
         ZoneLineForm->DrawZoneLine(1, 0);
         break;
       case DOTTED_LINE:
         ZoneLineForm->ToolButton2->Down = true;
         ZoneLineForm->DrawZoneLine(2, 4);
         break;
       case SHORT_DASHED_LINE:
         ZoneLineForm->ToolButton3->Down = true;
         ZoneLineForm->DrawZoneLine(12, 6);
         break;
       case LONG_DASHED_LINE:
         ZoneLineForm->ToolButton4->Down = true;
         ZoneLineForm->DrawZoneLine(24, 12);
         break;
       case USER_DEFINED_LINE:
         ZoneLineForm->ToolButton5->Down = true;
         ZoneLineForm->LabeledEdit1->Color = clWindow;
         ZoneLineForm->LabeledEdit2->Color = clWindow;
         if (Zone->user.dash == 0 || Zone->user.space == 0) {
           Zone->user.dash = 24;
           Zone->user.space = 12;
           }
         ZoneLineForm->LabeledEdit1->Text = Zone->user.dash;
         ZoneLineForm->LabeledEdit2->Text = Zone->user.space;
         ZoneLineForm->DrawZoneLine(Zone->user.dash, Zone->user.space);
         break;
       }

     if (Zone->LineWidth <= 0.25) {
       ZoneLineForm->LineWidthComboBox1->ItemIndex = 0;
       ZoneLineForm->LineWidthComboBox1->Text = "Hairline";
       }
     else
       ZoneLineForm->LineWidthComboBox1->Text = FormatFloat("0.0######", Zone->LineWidth);

	 ZoneLineForm->CheckBox1->Checked = false;
     ZoneLineForm->Zone = Zone;

     // show form and get data
     ZoneLineForm->DefaultZone = &DefaultZone;
     if (ZoneLineForm->ShowModal() == mrOk) {
       if (ZoneLineForm->CheckBox1->Checked) {
         DefaultZone.LineStyle = Zone->LineStyle;
         DefaultZone.LineWidth = Zone->LineWidth;
         DefaultZone.ZoneColor = Zone->ZoneColor;
         DefaultZone.user = Zone->user;
         for (int i=0; i<ZoneList->Count; i++) {
           if (i != AFocusedRecord->RecordIndex) {
             ZONE *Z = ZoneList->Zones[i];
             if (Z->ZoneStyle == LINEZONE)
               SetLineZoneOptions(Zone, Z);
             }
           }
         }
       }
     }
   else if (Style == "Screen") {
     ZoneScreenForm->Zone = Zone;
     if (ZoneScreenForm->ShowModal() == mrOk) {
       if (ZoneScreenForm->CheckBox2->Checked) {
         for (int i=0; i<ZoneList->Count; i++) {
           if (i != AFocusedRecord->RecordIndex) {
             ZONE *Z = ZoneList->Zones[i];
             if (Z->ZoneStyle == PATTERNZONE)
               SetScreenZoneOptions(Zone, Z);
             }
           }
         }
       }
     }

   ((TcxButtonEdit*)Sender)->Properties->Buttons->Items[0]->Glyph = NULL;

   ImageList1->GetBitmap(GetZoneImageIndex(AFocusedRecord->RecordIndex),
      ((TcxButtonEdit*)Sender)->Properties->Buttons->Items[0]->Glyph);

   // forces a redraw of all buttons
   LevelsGridTableView->LayoutChanged(true);
}
//---------------------------------------------------------------------------

void __fastcall TZoneForm::lvOptionsCustomDrawCell(
      TcxCustomGridTableView *Sender, TcxCanvas *ACanvas,
      TcxGridTableDataCellViewInfo *AViewInfo, bool &ADone)
{
   if (AViewInfo->Item->Index != 2) return;
   if (AViewInfo->GridRecord->RecordIndex >= ZoneList->Count) return;

   TRect ARec = AViewInfo->Bounds;
   ACanvas->Canvas->Brush->Style = bsSolid;
   ACanvas->Canvas->Brush->Color = (TColor)GetSysColor(COLOR_BTNFACE);

   ACanvas->Canvas->FillRect(ARec);

   ARec.Left+=3;
   ARec.Top+=2;
   ARec.Right-=3;
   ARec.Bottom-=3;

   ImageList1->Draw(ACanvas->Canvas,ARec.Left,ARec.Top,
       GetZoneImageIndex(AViewInfo->GridRecord->RecordIndex), true);
   ADone = true;
}
//---------------------------------------------------------------------------

int TZoneForm::GetZoneImageIndex(int RecordIndex)
{
   //if (RecordIndex < 0) return 0;  // 2-3-06
   ZONE *Zone;
   if (RecordIndex == -1)
     Zone = &NewZone;
   else
     Zone = ZoneList->Zones[RecordIndex];
   int idx;
   if (Zone->ZoneStyle == LINEZONE) {
     switch (Zone->LineStyle) {
       case SOLID_LINE:        idx = 33; break;
       case DOTTED_LINE:       idx = 34; break;
       case SHORT_DASHED_LINE: idx = 35; break;
       case LONG_DASHED_LINE:  idx = 36; break;
       case USER_DEFINED_LINE: idx = 37; break;
       }
     }
   else {
     if (Zone->Pattern <= 33)
       idx = Zone->Pattern - 1;
     else
       idx = Zone->Pattern + 4;
     }
   return idx;
}
//---------------------------------------------------------------------------

void __fastcall TZoneForm::lvStylePropertiesChange(TObject *Sender)
{
   // this forces the options button to be repainted
   TcxCustomGridRecord *AFocusedRecord =
       LevelsGridTableView->Controller->FocusedRecord;
   if (AFocusedRecord)
     LevelsGridTableView->DataController->Values[AFocusedRecord->RecordIndex][1] =
       ((TcxComboBox*)Sender)->Text;
}
//---------------------------------------------------------------------------

void __fastcall TZoneForm::LevelsEnter(TObject *Sender)
{
   LevelsGridTableView->DataController->GotoFirst();
}
//---------------------------------------------------------------------------

void __fastcall TZoneForm::LabelsEnter(TObject *Sender)
{
   LabelsGridTableView->DataController->GotoFirst();
}
//---------------------------------------------------------------------------

void __fastcall TZoneForm::Button3Click(TObject *Sender)
{
   Application->HelpContext(IDH_Zones_Dialog_Box);
}
//---------------------------------------------------------------------------

bool __fastcall TZoneForm::FormHelp(WORD Command, int Data, bool &CallHelp)
{
   return true;
}
//---------------------------------------------------------------------------

void __fastcall TZoneForm::lvLevelPropertiesValidate(TObject *Sender,
      Variant &DisplayValue, TCaption &ErrorText, bool &Error)
{
   ValidateNumericalDisplayValue(DisplayValue, ErrorText, Error);
}
//---------------------------------------------------------------------------

void __fastcall TZoneForm::lbTopDepthPropertiesValidate(TObject *Sender,
      Variant &DisplayValue, TCaption &ErrorText, bool &Error)
{
   ValidateNumericalDisplayValue(DisplayValue, ErrorText, Error);
}
//---------------------------------------------------------------------------

void __fastcall TZoneForm::lbBottomDepthPropertiesValidate(TObject *Sender,
      Variant &DisplayValue, TCaption &ErrorText, bool &Error)
{
   ValidateNumericalDisplayValue(DisplayValue, ErrorText, Error);
}
//---------------------------------------------------------------------------

void __fastcall TZoneForm::LevelsGridTableViewDataControllerNewRecord(
      TcxCustomDataController *ADataController, int ARecordIndex)
{
   if (ARecordIndex == -1) {
     NewZone = DefaultZone;
     LevelsGridTableView->ViewData->NewItemRecord->Values[1] =
       (NewZone.ZoneStyle == LINEZONE) ? "Line" : "Screen";
     LevelsGridTableView->ViewData->NewItemRecord->Values[3] =
       (NewZone.Priority == ZONETOBACK) ? "To Back" : "To Front";
     LevelsGridTableView->ViewData->NewItemRecord->Values[4] = NewZone.ThruLabelCol;
     }
}
//---------------------------------------------------------------------------

