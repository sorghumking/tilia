//---------------------------------------------------------------------------

#include <vcl.h>
#include "pch.h"
#pragma hdrstop

#include <Math.h>
#ifndef TGParentH
#include "TGParent.h"
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
#include "TGLthFrm.h"
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
#pragma link "cxButtonEdit"
#pragma link "cxColorComboBox"
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
TLithForm *LithForm;

//---------------------------------------------------------------------------
LITHUNIT::LITHUNIT(TColor DefaultColor)
{
  LoBound=false;
  Top=NaN;
  Bot=NaN;
  LoBoundColor = DefaultColor;
  Components = new TList;
}
//---------------------------------------------------------------------------

LITHUNIT::LITHUNIT(LITHUNIT *l)
{
  LoBound=l->LoBound;
  Top=l->Top;
  Bot=l->Bot;
  LoBoundColor=l->LoBoundColor;
  Components = new TList;
}
//---------------------------------------------------------------------------

LITHUNIT::~LITHUNIT()
{
  DeleteList(Components);
}
//---------------------------------------------------------------------------

LITH1::LITH1(TColor DefaultColor)
{
   DepthsSet = false;
   TopSet = false;
   BotSet = false;
   Top = NaN;
   Bot = NaN;
   LoBound = false;
   LoBoundColor = DefaultColor;
   Components = new TList;
}
//---------------------------------------------------------------------------

LITH1::LITH1(LITHUNIT *lith)
{
   DepthsSet = true;
   TopSet = true;
   BotSet = true;
   Top = lith->Top;
   Bot = lith->Bot;
   LoBound = lith->LoBound;
   LoBoundColor = lith->LoBoundColor;
   Components = new TList;
}
//---------------------------------------------------------------------------

LITH1::LITH1(LITH1 *lith1)
{
   DepthsSet = lith1->DepthsSet;
   TopSet = lith1->TopSet;
   BotSet = lith1->BotSet;
   Top = lith1->Top;
   Bot = lith1->Bot;
   LoBound = lith1->LoBound;
   LoBoundColor = lith1->LoBoundColor;
   Components = new TList;
   for (int i=0; i<lith1->Components->Count; i++) {
     LITH2* NewLith2 = new LITH2;
     LITH2* Lith2 = (LITH2*)lith1->Components->Items[i];
     *NewLith2 = *Lith2;
     Components->Add(NewLith2);
     }
}
//---------------------------------------------------------------------------

LITH1::~LITH1()
{
   DeleteList(Components);
}
//---------------------------------------------------------------------------

LITH2::LITH2(LITHCOMPONENT *Component, TStringList *TroelsSmithCodes)
{
  if (Component->LithCode < 34)
    LithCode = "Bitmap" + IntToStr(Component->LithCode);
  // ADD HERE WHEN ADDING NEW TS PATTERNS
  else if (Component->LithCode > 129)
    LithCode = "Code " + IntToStr(Component->LithCode);
  else
    LithCode = TroelsSmithCodes->Strings[Component->LithCode-34];
  Humo=Component->Humo;
  XShift=Component->XShift;
  YShift=Component->YShift;
  Color=Component->Color;
}
//---------------------------------------------------------------------------

void TLithList::ReleaseAllLiths()
{
  for (int i = 0; i < Count; i++)
    ReleaseLith(i);
}
//---------------------------------------------------------------------------

void TLithList::ReleaseLith(int AIndex)
{
  delete (LITH1*)Items[AIndex];
}
//---------------------------------------------------------------------------

LITH1* TLithList::GetLith(int AIndex)
{
  return (LITH1*)Items[AIndex];
}
//---------------------------------------------------------------------------

void __fastcall TLithList::Notify(void * Ptr, TListNotification Action)
{
  if (FOnNotify != NULL)
    FOnNotify(Ptr, Action);
}                               
//---------------------------------------------------------------------------

void __fastcall TLithList::Clear(void)
{
  ReleaseAllLiths();
}
//---------------------------------------------------------------------------

void TLithList::Add(LITH1* Lith1)
{
  TList::Add(Lith1);
}
//---------------------------------------------------------------------------

void TLithList::Delete(int AIndex)
{
  ReleaseLith(AIndex);
  TList::Delete(AIndex);
}
//---------------------------------------------------------------------------

void TLithList::Insert(int AIndex, LITH1* Lith1)
{
  TList::Insert(AIndex, Lith1);
}
//---------------------------------------------------------------------------

__fastcall TLithDataSource::TLithDataSource(TLithList* ALithList, TColor dcolor)
{
  FLiths = ALithList;
  FLiths->OnNotify = Notify;
  TempLith1 = NULL;
  DefaultColor = dcolor;
}
//---------------------------------------------------------------------------

void __fastcall TLithDataSource::DeleteRecord(void * ARecordHandle)
{
  FLiths->Delete((int)ARecordHandle);
}
//---------------------------------------------------------------------------

int __fastcall TLithDataSource::GetRecordCount(void)
{
  return(FLiths->Count);
}
//---------------------------------------------------------------------------

void __fastcall TLithDataSource::Notify(void * Ptr, TListNotification Action)
{
  DataChanged();
}

//---------------------------------------------------------------------------

void * __fastcall TLithDataSource::InsertRecord(void * ARecordHandle)
{
  LITH1* Lith1;

  if (TempLith1) {
    Lith1 = new LITH1(TempLith1);
    delete TempLith1;
    TempLith1 = NULL;
    }
  else
    Lith1 = new LITH1(DefaultColor);

  FLiths->Insert((int)ARecordHandle, Lith1);
  TcxDataRecordHandle* Result = (TcxDataRecordHandle*)ARecordHandle;
  return (Result);
}
//---------------------------------------------------------------------------

void * __fastcall TLithDataSource::AppendRecord(void)
{
  LITH1* Lith1;

  TcxDataRecordHandle* Result = (TcxDataRecordHandle*)FLiths->Count;

  if (TempLith1) {
    Lith1 = new LITH1(TempLith1);
    delete TempLith1;
    TempLith1 = NULL;
    }
  else
    Lith1 = new LITH1(DefaultColor);

  FLiths->Add(Lith1);
  return (Result);
}
//---------------------------------------------------------------------------

Variant __fastcall TLithDataSource::GetValue(void * ARecordHandle, void * AItemHandle)
{
  int AColumnId = GetDefaultItemID((int)AItemHandle);
  LITH1* Lith1 = FLiths->Liths[(int)ARecordHandle];
  Variant Result;
  switch (AColumnId) {
    case IndexOfTopDepth:
      if (IsNan(Lith1->Top))
		Result.ChangeType(varEmpty);
      else
		Result = Lith1->Top;
      break;
    case IndexOfBottomDepth:
      if (IsNan(Lith1->Bot))
        Result.ChangeType(varEmpty);
      else
        Result = Lith1->Bot;
      break;
    case IndexOfLoBound:
      Result = Lith1->LoBound;
      break;
    }
  return (Result);
}
//---------------------------------------------------------------------------

void __fastcall TLithDataSource::SetValue(void * ARecordHandle, void * AItemHandle, const Variant &AValue)
{
  int AColumnId = GetDefaultItemID((int)AItemHandle);
  LITH1* Lith1 = FLiths->Liths[(int)ARecordHandle];
  switch (AColumnId) {
    case IndexOfTopDepth:
	  if (AValue.IsNull())
        Lith1->Top = NaN;
      else
        try {
          Lith1->Top = AValue;
          Lith1->TopSet = true;
          if (Lith1->BotSet)
            Lith1->DepthsSet = true;
          }
        catch (...) { Beep(); Lith1->Top = NaN; }
      break;
    case IndexOfBottomDepth:
	  if (AValue.IsNull())
        Lith1->Bot = NaN;
      else
        try {
          Lith1->Bot = AValue;
          Lith1->BotSet = true;
          if (Lith1->TopSet)
            Lith1->DepthsSet = true;
          }
        catch (...) { Beep(); Lith1->Bot = NaN;  /*Lith1->Bot = 0;*/ }
      break;
    case IndexOfLoBound:
      Lith1->LoBound = (AValue.IsNull()) ? false : AValue;
      if (Lith1->TopSet && Lith1->BotSet)
        Lith1->DepthsSet = true;
      break;
    }
}

//---------------------------------------------------------------------------
// ----------Start component source here

int __fastcall TLithComponentSource::GetRecordCount(void)
{
  int Result = 0;
  if (GetMasterRecordIndex() >= 0) {
    LITH1 *Lith1 = (LITH1*)MasterDataSource->LithList->Liths[GetMasterRecordIndex()];
    Result = Lith1->Components->Count;
    }
  return (Result);
}
//---------------------------------------------------------------------------

Variant __fastcall TLithComponentSource::GetValue(void * ARecordHandle, void * AItemHandle)
{
  int AColumnId = GetDefaultItemID(int(AItemHandle));

  LITH1 *Lith1 = (LITH1*)MasterDataSource->LithList->Liths[GetMasterRecordIndex()];
  LITH2 *Lith2 = (LITH2*)Lith1->Components->Items[(int)ARecordHandle];

  Variant Result;
  switch (AColumnId) {
	case IndexOfLithCode:
      Result = Lith2->LithCode;
      break;
	case IndexOfHumo:
      Result = Lith2->Humo;
      break;
    case IndexOfXShift:
      if (IsNan(Lith2->XShift))
		Result.ChangeType(varEmpty);
      else
        Result = Lith2->XShift;
      break;
    case IndexOfYShift:
      if (IsNan(Lith2->YShift))
        Result.ChangeType(varEmpty);
      else
        Result = Lith2->YShift;
      break;
    }
  return (Result);
}
//---------------------------------------------------------------------------

void __fastcall TLithComponentSource::SetValue(void * ARecordHandle, void * AItemHandle, const Variant &AValue)
{
  int AColumnId = GetDefaultItemID((int)AItemHandle);

  LITH1 *Lith1 = (LITH1*)MasterDataSource->LithList->Liths[GetMasterRecordIndex()];
  LITH2 *Lith2 = (LITH2*)Lith1->Components->Items[(int)ARecordHandle];

  switch (AColumnId) {
    case IndexOfLithCode:
	  if (AValue.IsNull())
        Lith2->LithCode = 0;
      else
		Lith2->LithCode = AValue;
      break;
    case IndexOfHumo:
	  if (AValue.IsNull())
        Lith2->Humo = 0;
      else
        Lith2->Humo = AValue;
      break;
    case IndexOfXShift:
	  if (AValue.IsNull())
        Lith2->XShift = NaN;
      else
        Lith2->XShift = AValue;
      break;
    case IndexOfYShift:
	  if (AValue.IsNull())
        Lith2->YShift = NaN;
      else
        Lith2->YShift = AValue;
      break;
    }

  // IS THIS NEEDED???
  // MasterDataSource->LithList->Modified = true;
  DataChanged();
}

//---------------------------------------------------------------------------

void * __fastcall TLithComponentSource::AppendRecord(void)
{
  LITH1 *Lith1 = (LITH1*)MasterDataSource->LithList->Liths[GetMasterRecordIndex()];
  LITH2* Lith2 = new LITH2;
  void* Result = (TcxDataRecordHandle*)Lith1->Components->Add(Lith2);
  DataChanged();
  return (Result);
}
//---------------------------------------------------------------------------

void __fastcall TLithComponentSource::Notify(void * Ptr, TListNotification Action)
{
  DataChanged();
}

//---------------------------------------------------------------------------

void __fastcall TLithComponentSource::DeleteRecord(void * ARecordHandle)
{
  LITH1 *Lith1 = (LITH1*)MasterDataSource->LithList->Liths[GetMasterRecordIndex()];
  LITH2 *Lith2 = (LITH2*)Lith1->Components->Items[(int)ARecordHandle];
  Lith1->Components->Delete((int)ARecordHandle);
  delete Lith2;
  DataChanged();
}
//---------------------------------------------------------------------------

int TLithComponentSource::GetMasterRecordIndex()
{
  return (DataController->GetMasterRecordIndex());
}
//---------------------------------------------------------------------------


// ---------End component source here
//---------------------------------------------------------------------------
__fastcall TLithForm::TLithForm(TComponent* Owner)
        : TForm(Owner)
{
   Diag = (TTGDiagram*)Owner;
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::FormCreate(TObject *Sender)
{
   MaxXShift.push_back(16);
   MaxXShift.push_back(16);
   MaxXShift.push_back(16);
   MaxXShift.push_back(12);
   MaxXShift.push_back(32);
   MaxXShift.push_back(32);
   MaxXShift.push_back(32);
   MaxXShift.push_back(24);
   MaxXShift.push_back(60);
   MaxXShift.push_back(60);
   MaxXShift.push_back(60);
   MaxXShift.push_back(60);
   MaxXShift.push_back(60);
   MaxXShift.push_back(60);
   MaxXShift.push_back(60);
   MaxXShift.push_back(60);
   MaxXShift.push_back(48);
   MaxXShift.push_back(40);
   MaxXShift.push_back(33);
   MaxXShift.push_back(18);
   MaxXShift.push_back(24);
   MaxXShift.push_back(16);
   MaxXShift.push_back(8);
   MaxXShift.push_back(8);
   MaxXShift.push_back(12);
   MaxXShift.push_back(8);
   MaxXShift.push_back(6);
   MaxXShift.push_back(4);
   MaxXShift.push_back(50);
   MaxXShift.push_back(32);
   MaxXShift.push_back(24);
   MaxXShift.push_back(16);
   MaxXShift.push_back(50);
   MaxXShift.push_back(32);
   MaxXShift.push_back(24);
   MaxXShift.push_back(16);
   MaxXShift.push_back(50);
   MaxXShift.push_back(32);
   MaxXShift.push_back(24);
   MaxXShift.push_back(16);
   MaxXShift.push_back(48);
   MaxXShift.push_back(32);
   MaxXShift.push_back(20);
   MaxXShift.push_back(12);
   MaxXShift.push_back(60);
   MaxXShift.push_back(16);
   MaxXShift.push_back(12);
   MaxXShift.push_back(8);
   MaxXShift.push_back(40);
   MaxXShift.push_back(32);
   MaxXShift.push_back(16);
   MaxXShift.push_back(20);
   MaxXShift.push_back(40);
   MaxXShift.push_back(32);
   MaxXShift.push_back(24);
   MaxXShift.push_back(16);
   MaxXShift.push_back(40);
   MaxXShift.push_back(32);
   MaxXShift.push_back(16);
   MaxXShift.push_back(20);
   MaxXShift.push_back(40);
   MaxXShift.push_back(32);
   MaxXShift.push_back(16);
   MaxXShift.push_back(20);
   MaxXShift.push_back(20);
   MaxXShift.push_back(16);
   MaxXShift.push_back(12);
   MaxXShift.push_back(8);
   MaxXShift.push_back(40);
   MaxXShift.push_back(32);
   MaxXShift.push_back(24);
   MaxXShift.push_back(16);
   MaxXShift.push_back(40);
   MaxXShift.push_back(32);
   MaxXShift.push_back(24);
   MaxXShift.push_back(16);
   MaxXShift.push_back(80);
   MaxXShift.push_back(64);
   MaxXShift.push_back(48);
   MaxXShift.push_back(32);
   MaxXShift.push_back(40);
   MaxXShift.push_back(32);
   MaxXShift.push_back(24);
   MaxXShift.push_back(16);
   MaxXShift.push_back(40);
   MaxXShift.push_back(32);
   MaxXShift.push_back(24);
   MaxXShift.push_back(16);
   MaxXShift.push_back(60);
   MaxXShift.push_back(40);
   MaxXShift.push_back(32);
   MaxXShift.push_back(32);
   MaxXShift.push_back(60);
   MaxXShift.push_back(40);
   MaxXShift.push_back(32);
   MaxXShift.push_back(32);

   MaxYShift.push_back(24);
   MaxYShift.push_back(16);
   MaxYShift.push_back(8);
   MaxYShift.push_back(8);
   MaxYShift.push_back(48);
   MaxYShift.push_back(32);
   MaxYShift.push_back(16);
   MaxYShift.push_back(16);
   MaxYShift.push_back(64);
   MaxYShift.push_back(32);
   MaxYShift.push_back(16);
   MaxYShift.push_back(8);
   MaxYShift.push_back(32);
   MaxYShift.push_back(16);
   MaxYShift.push_back(8);
   MaxYShift.push_back(4);
   MaxYShift.push_back(48);
   MaxYShift.push_back(40);
   MaxYShift.push_back(32);
   MaxYShift.push_back(32);
   MaxYShift.push_back(16);
   MaxYShift.push_back(16);
   MaxYShift.push_back(16);
   MaxYShift.push_back(12);
   MaxYShift.push_back(40);
   MaxYShift.push_back(40);
   MaxYShift.push_back(40);
   MaxYShift.push_back(40);
   MaxYShift.push_back(48);
   MaxYShift.push_back(32);
   MaxYShift.push_back(24);
   MaxYShift.push_back(16);
   MaxYShift.push_back(48);
   MaxYShift.push_back(32);
   MaxYShift.push_back(24);
   MaxYShift.push_back(16);
   MaxYShift.push_back(48);
   MaxYShift.push_back(32);
   MaxYShift.push_back(24);
   MaxYShift.push_back(16);
   MaxYShift.push_back(48);
   MaxYShift.push_back(32);
   MaxYShift.push_back(20);
   MaxYShift.push_back(12);
   MaxYShift.push_back(60);
   MaxYShift.push_back(16);
   MaxYShift.push_back(12);
   MaxYShift.push_back(8);
   MaxYShift.push_back(40);
   MaxYShift.push_back(32);
   MaxYShift.push_back(32);
   MaxYShift.push_back(16);
   MaxYShift.push_back(40);
   MaxYShift.push_back(32);
   MaxYShift.push_back(24);
   MaxYShift.push_back(16);
   MaxYShift.push_back(40);
   MaxYShift.push_back(32);
   MaxYShift.push_back(32);
   MaxYShift.push_back(40);
   MaxYShift.push_back(40);
   MaxYShift.push_back(32);
   MaxYShift.push_back(32);
   MaxYShift.push_back(40);
   MaxYShift.push_back(20);
   MaxYShift.push_back(16);
   MaxYShift.push_back(12);
   MaxYShift.push_back(8);
   MaxYShift.push_back(40);
   MaxYShift.push_back(32);
   MaxYShift.push_back(24);
   MaxYShift.push_back(16);
   MaxYShift.push_back(40);
   MaxYShift.push_back(32);
   MaxYShift.push_back(24);
   MaxYShift.push_back(16);
   MaxYShift.push_back(80);
   MaxYShift.push_back(64);
   MaxYShift.push_back(48);
   MaxYShift.push_back(32);
   MaxYShift.push_back(40);
   MaxYShift.push_back(32);
   MaxYShift.push_back(24);
   MaxYShift.push_back(16);
   MaxYShift.push_back(40);
   MaxYShift.push_back(32);
   MaxYShift.push_back(24);
   MaxYShift.push_back(16);
   MaxYShift.push_back(60);
   MaxYShift.push_back(40);
   MaxYShift.push_back(24);
   MaxYShift.push_back(16);
   MaxYShift.push_back(60);
   MaxYShift.push_back(40);
   MaxYShift.push_back(24);
   MaxYShift.push_back(16);
   // ADD HERE

   TroelsSmithCodes = new TStringList();
   TroelsSmithCodes->Capacity = 200;
   TroelsSmithCodes->Add("Sh1");
   TroelsSmithCodes->Add("Sh2");
   TroelsSmithCodes->Add("Sh3");
   TroelsSmithCodes->Add("Sh4");
   TroelsSmithCodes->Add("Tb1");
   TroelsSmithCodes->Add("Tb2");
   TroelsSmithCodes->Add("Tb3");
   TroelsSmithCodes->Add("Tb4");
   TroelsSmithCodes->Add("TbS1");
   TroelsSmithCodes->Add("TbS2");
   TroelsSmithCodes->Add("TbS3");
   TroelsSmithCodes->Add("TbS4");
   TroelsSmithCodes->Add("TbSc1");
   TroelsSmithCodes->Add("TbSc2");
   TroelsSmithCodes->Add("TbSc3");
   TroelsSmithCodes->Add("TbSc4");
   TroelsSmithCodes->Add("Tl1");
   TroelsSmithCodes->Add("Tl2");
   TroelsSmithCodes->Add("Tl3");
   TroelsSmithCodes->Add("Tl4");
   TroelsSmithCodes->Add("Th1");
   TroelsSmithCodes->Add("Th2");
   TroelsSmithCodes->Add("Th3");
   TroelsSmithCodes->Add("Th4");
   TroelsSmithCodes->Add("Thh1");
   TroelsSmithCodes->Add("Thh2");
   TroelsSmithCodes->Add("Thh3");
   TroelsSmithCodes->Add("Thh4");
   TroelsSmithCodes->Add("Dl1");
   TroelsSmithCodes->Add("Dl2");
   TroelsSmithCodes->Add("Dl3");
   TroelsSmithCodes->Add("Dl4");
   TroelsSmithCodes->Add("Dh1");
   TroelsSmithCodes->Add("Dh2");
   TroelsSmithCodes->Add("Dh3");
   TroelsSmithCodes->Add("Dh4");
   TroelsSmithCodes->Add("Dg1");
   TroelsSmithCodes->Add("Dg2");
   TroelsSmithCodes->Add("Dg3");
   TroelsSmithCodes->Add("Dg4");
   TroelsSmithCodes->Add("Ld1");
   TroelsSmithCodes->Add("Ld2");
   TroelsSmithCodes->Add("Ld3");
   TroelsSmithCodes->Add("Ld4");
   TroelsSmithCodes->Add("Lso1");
   TroelsSmithCodes->Add("Lso2");
   TroelsSmithCodes->Add("Lso3");
   TroelsSmithCodes->Add("Lso4");
   TroelsSmithCodes->Add("Lc1");
   TroelsSmithCodes->Add("Lc2");
   TroelsSmithCodes->Add("Lc3");
   TroelsSmithCodes->Add("Lc4");
   TroelsSmithCodes->Add("Lf1");
   TroelsSmithCodes->Add("Lf2");
   TroelsSmithCodes->Add("Lf3");
   TroelsSmithCodes->Add("Lf4");
   TroelsSmithCodes->Add("As1");
   TroelsSmithCodes->Add("As2");
   TroelsSmithCodes->Add("As3");
   TroelsSmithCodes->Add("As4");
   TroelsSmithCodes->Add("Ag1");
   TroelsSmithCodes->Add("Ag2");
   TroelsSmithCodes->Add("Ag3");
   TroelsSmithCodes->Add("Ag4");
   TroelsSmithCodes->Add("Ga1");
   TroelsSmithCodes->Add("Ga2");
   TroelsSmithCodes->Add("Ga3");
   TroelsSmithCodes->Add("Ga4");
   TroelsSmithCodes->Add("Gs1");
   TroelsSmithCodes->Add("Gs2");
   TroelsSmithCodes->Add("Gs3");
   TroelsSmithCodes->Add("Gs4");
   TroelsSmithCodes->Add("Gg(min)1");
   TroelsSmithCodes->Add("Gg(min)2");
   TroelsSmithCodes->Add("Gg(min)3");
   TroelsSmithCodes->Add("Gg(min)4");
   TroelsSmithCodes->Add("Gg(maj)1");
   TroelsSmithCodes->Add("Gg(maj)2");
   TroelsSmithCodes->Add("Gg(maj)3");
   TroelsSmithCodes->Add("Gg(maj)4");
   TroelsSmithCodes->Add("Test1");
   TroelsSmithCodes->Add("Test2");
   TroelsSmithCodes->Add("Test3");
   TroelsSmithCodes->Add("Test4");
   TroelsSmithCodes->Add("PartTest1");
   TroelsSmithCodes->Add("PartTest2");
   TroelsSmithCodes->Add("PartTest3");
   TroelsSmithCodes->Add("PartTest4");
   TroelsSmithCodes->Add("CortSec1");
   TroelsSmithCodes->Add("CortSec2");
   TroelsSmithCodes->Add("CortSec3");
   TroelsSmithCodes->Add("CortSec4");
   TroelsSmithCodes->Add("Cort1");
   TroelsSmithCodes->Add("Cort2");
   TroelsSmithCodes->Add("Cort3");
   TroelsSmithCodes->Add("Cort4");
   // ADD HERE

   PatLineWidthComboBox = new LineWidthComboBox(LineWidthComboBox1);
   ColLineWidthComboBox = new LineWidthComboBox(LineWidthComboBox2);
   BndLineWidthComboBox = new LineWidthComboBox(LineWidthComboBox3);
   KeyLineWidthComboBox = new LineWidthComboBox(LineWidthComboBox4);

   InitialTabSheet = 1;
   PageControl2->ActivePage = DesignTabSheet;
}

//---------------------------------------------------------------------------

void __fastcall TLithForm::FormDestroy(TObject *Sender)
{
   delete TroelsSmithCodes;
   delete LithList;
   delete LithDataSource;
   delete LithComponentSource;
   delete LithKeyList;
   delete PatLineWidthComboBox;
   delete ColLineWidthComboBox;
   delete BndLineWidthComboBox;
   delete KeyLineWidthComboBox;
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::FormActivate(TObject *Sender)
{
   Screen->Cursor = crHourGlass;
   for (int i=0; i<4; i++) {
	 Graphics::TBitmap *bmp = new Graphics::TBitmap;
	 bmp->Width = 120;
	 bmp->Height = 160;
	 bmp->PixelFormat = pf24bit;
	 LTHBitmaps.push_back(bmp);
	 }

   for (int i=0; i<4; i++) {
	 Graphics::TBitmap *bmp = new Graphics::TBitmap;
	 bmp->Width = 120;
	 bmp->Height = 160;
	 bmp->PixelFormat = pf24bit;
	 Image1Bitmaps.push_back(bmp);
	 }

   pBitmap = new Graphics::TBitmap();
   pBitmap->Width = 120;
   pBitmap->Height = 160;
   pBitmap->PixelFormat = pf24bit;

   LithList = new TLithList();
   LithDataSource = new TLithDataSource(LithList, (TColor)Diag->lopt.DefaultColor);
   LithComponentSource = new TLithComponentSource(LithDataSource);
   GenerateLithColumns();
   LoadLithData();

   LithKeyList = new TLithKeyList();
   LithKeyDataSource = new TLithKeyDataSource(LithKeyList, TroelsSmithCodes);
   GenerateLithKeyColumns();
   LoadLithKeyData();

   ButtonsEnabled = true; // so DisableButtons will work
   DisableButtons();
   NewPost = false;

   if (LithDataSource->LithList->Count == 0) 
     InitialZero = true;
   else
     InitialZero = false;

   SetTroelsSmithButtonBitmap(34, SpeedButton34);
   SetTroelsSmithButtonBitmap(35, SpeedButton35);
   SetTroelsSmithButtonBitmap(36, SpeedButton36);
   SetTroelsSmithButtonBitmap(37, SpeedButton37);
   SetTroelsSmithButtonBitmap(38, SpeedButton38);
   SetTroelsSmithButtonBitmap(39, SpeedButton39);
   SetTroelsSmithButtonBitmap(40, SpeedButton40);
   SetTroelsSmithButtonBitmap(41, SpeedButton41);
   SetTroelsSmithButtonBitmap(42, SpeedButton42);
   SetTroelsSmithButtonBitmap(43, SpeedButton43);
   SetTroelsSmithButtonBitmap(44, SpeedButton44);
   SetTroelsSmithButtonBitmap(45, SpeedButton45);
   SetTroelsSmithButtonBitmap(46, SpeedButton46);
   SetTroelsSmithButtonBitmap(47, SpeedButton47);
   SetTroelsSmithButtonBitmap(48, SpeedButton48);
   SetTroelsSmithButtonBitmap(49, SpeedButton49);
   SetTroelsSmithButtonBitmap(50, SpeedButton50);
   SetTroelsSmithButtonBitmap(51, SpeedButton51);
   SetTroelsSmithButtonBitmap(52, SpeedButton52);
   SetTroelsSmithButtonBitmap(53, SpeedButton53);
   SetTroelsSmithButtonBitmap(54, SpeedButton54);
   SetTroelsSmithButtonBitmap(55, SpeedButton55);
   SetTroelsSmithButtonBitmap(56, SpeedButton56);
   SetTroelsSmithButtonBitmap(57, SpeedButton57);
   SetTroelsSmithButtonBitmap(58, SpeedButton58);
   SetTroelsSmithButtonBitmap(59, SpeedButton59);
   SetTroelsSmithButtonBitmap(60, SpeedButton60);
   SetTroelsSmithButtonBitmap(61, SpeedButton61);
   SetTroelsSmithButtonBitmap(62, SpeedButton62);
   SetTroelsSmithButtonBitmap(63, SpeedButton63);
   SetTroelsSmithButtonBitmap(64, SpeedButton64);
   SetTroelsSmithButtonBitmap(65, SpeedButton65);
   SetTroelsSmithButtonBitmap(66, SpeedButton66);
   SetTroelsSmithButtonBitmap(67, SpeedButton67);
   SetTroelsSmithButtonBitmap(68, SpeedButton68);
   SetTroelsSmithButtonBitmap(69, SpeedButton69);
   SetTroelsSmithButtonBitmap(70, SpeedButton70);
   SetTroelsSmithButtonBitmap(71, SpeedButton71);
   SetTroelsSmithButtonBitmap(72, SpeedButton72);
   SetTroelsSmithButtonBitmap(73, SpeedButton73);
   SetTroelsSmithButtonBitmap(74, SpeedButton74);
   SetTroelsSmithButtonBitmap(75, SpeedButton75);
   SetTroelsSmithButtonBitmap(76, SpeedButton76);
   SetTroelsSmithButtonBitmap(77, SpeedButton77);
   SetTroelsSmithButtonBitmap(78, SpeedButton78);
   SetTroelsSmithButtonBitmap(79, SpeedButton79);
   SetTroelsSmithButtonBitmap(80, SpeedButton80);
   SetTroelsSmithButtonBitmap(81, SpeedButton81);
   SetTroelsSmithButtonBitmap(82, SpeedButton82);
   SetTroelsSmithButtonBitmap(83, SpeedButton83);
   SetTroelsSmithButtonBitmap(84, SpeedButton84);
   SetTroelsSmithButtonBitmap(85, SpeedButton85);
   SetTroelsSmithButtonBitmap(86, SpeedButton86);
   SetTroelsSmithButtonBitmap(87, SpeedButton87);
   SetTroelsSmithButtonBitmap(88, SpeedButton88);
   SetTroelsSmithButtonBitmap(89, SpeedButton89);
   SetTroelsSmithButtonBitmap(90, SpeedButton90);
   SetTroelsSmithButtonBitmap(91, SpeedButton91);
   SetTroelsSmithButtonBitmap(92, SpeedButton92);
   SetTroelsSmithButtonBitmap(93, SpeedButton93);
   SetTroelsSmithButtonBitmap(94, SpeedButton94);
   SetTroelsSmithButtonBitmap(95, SpeedButton95);
   SetTroelsSmithButtonBitmap(96, SpeedButton96);
   SetTroelsSmithButtonBitmap(97, SpeedButton97);
   SetTroelsSmithButtonBitmap(98, SpeedButton98);
   SetTroelsSmithButtonBitmap(99, SpeedButton99);
   SetTroelsSmithButtonBitmap(100, SpeedButton100);
   SetTroelsSmithButtonBitmap(101, SpeedButton101);
   SetTroelsSmithButtonBitmap(102, SpeedButton102);
   SetTroelsSmithButtonBitmap(103, SpeedButton103);
   SetTroelsSmithButtonBitmap(104, SpeedButton104);
   SetTroelsSmithButtonBitmap(105, SpeedButton105);
   SetTroelsSmithButtonBitmap(106, SpeedButton106);
   SetTroelsSmithButtonBitmap(107, SpeedButton107);
   SetTroelsSmithButtonBitmap(108, SpeedButton108);
   SetTroelsSmithButtonBitmap(109, SpeedButton109);
   SetTroelsSmithButtonBitmap(110, SpeedButton110);
   SetTroelsSmithButtonBitmap(111, SpeedButton111);
   SetTroelsSmithButtonBitmap(112, SpeedButton112);
   SetTroelsSmithButtonBitmap(113, SpeedButton113);
   SetTroelsSmithButtonBitmap(114, SpeedButton114);
   SetTroelsSmithButtonBitmap(115, SpeedButton115);
   SetTroelsSmithButtonBitmap(116, SpeedButton116);
   SetTroelsSmithButtonBitmap(117, SpeedButton117);
   SetTroelsSmithButtonBitmap(118, SpeedButton118);
   SetTroelsSmithButtonBitmap(119, SpeedButton119);
   SetTroelsSmithButtonBitmap(120, SpeedButton120);
   SetTroelsSmithButtonBitmap(121, SpeedButton121);
   SetTroelsSmithButtonBitmap(122, SpeedButton122);
   SetTroelsSmithButtonBitmap(123, SpeedButton123);
   SetTroelsSmithButtonBitmap(124, SpeedButton124);
   SetTroelsSmithButtonBitmap(125, SpeedButton125);
   SetTroelsSmithButtonBitmap(126, SpeedButton126);
   SetTroelsSmithButtonBitmap(127, SpeedButton127);
   SetTroelsSmithButtonBitmap(128, SpeedButton128);
   SetTroelsSmithButtonBitmap(129, SpeedButton129);
   // ADD HERE

   CheckBox1->Checked = Diag->lopt.On;
   CheckBox2->Checked = Diag->lopt.KeyOn;
   if (Diag->lopt.AutoTopDepth)
     LabeledEdit1->Text = "Auto";
   else
     LabeledEdit1->Text = Diag->lopt.TopDepth;
   if (Diag->lopt.AutoBotDepth)
     LabeledEdit2->Text = "Auto";
   else
     LabeledEdit2->Text = Diag->lopt.BotDepth;
   LabeledEdit3->Text = Diag->lopt.LithTitle;
   LabeledEdit4->Text = Diag->lopt.Angle;
   LabeledEdit5->Text = Diag->lopt.BoxWidth;

   PatLineWidthComboBox->SetLineWidth(Diag->lopt.LithLineWidth);
   ColLineWidthComboBox->SetLineWidth(Diag->lopt.ColumnLineWidth);
   BndLineWidthComboBox->SetLineWidth(Diag->lopt.BoundaryLineWidth);
   KeyLineWidthComboBox->SetLineWidth(Diag->lopt.KeyLineWidth);

   Diag->SetColorBox(ColorBox3, (TColor)Diag->lopt.DefaultColor);
   LithTitleFont = Diag->lopt.LithTitleFont;
   KeyFont = Diag->lopt.KeyFont;

   FocusControl(LithGrid);

   if (LithList->Count) {
     LITH1* Lith1 = (LITH1*)LithList->Liths[0];
     if (Lith1->Components->Count) {
       LITH2 *Lith2 = (LITH2*)Lith1->Components->Items[0];
       if (Lith2->LithCode.SubString(1,6) == "Bitmap")
         DepressBitmapButton(Lith2);
       else
         DepressTroelsSmithButtons(0, Lith1);
       ColorBox1->Enabled = true;
       ColorBox1->Selected = Lith2->Color;
       }
     else
	   PageControl1->ActivePage = BitmapTabSheet;
	 EnableButtons();
     }
   else
     PageControl1->ActivePage = BitmapTabSheet;

   if (InitialTabSheet == 2)
	 PageControl2->ActivePage = OptionsTabSheet;

   Screen->Cursor = crDefault;
}
//---------------------------------------------------------------------------

bool TLithForm::SetTroelsSmithButtonBitmap(int code, TSpeedButton* SpeedButton)
{
   try {
	 SpeedButton->Glyph->PixelFormat = pf24bit;
	 Graphics::TBitmap *image = new Graphics::TBitmap();
	 cxImageList1->GetBitmap(code-34, image);
	 SpeedButton->Glyph->Assign(image);
	 delete image;
	 SpeedButton->Glyph->Height = 80;
	 SpeedButton->Glyph->TransparentColor = clWhite;
     }
   catch (...) {
     return false;
     }
     
   SpeedButton->Glyph->Canvas->Brush->Color = clBlack;
   SpeedButton->Glyph->Canvas->FrameRect(Rect(0,0,120,80));

   return true;
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::GenerateLithColumns()
{
   lgTopDepth->DataBinding->Data = (TObject*)IndexOfTopDepth;
   lgBottomDepth->DataBinding->Data = (TObject*)IndexOfBottomDepth;
   lgLoBound->DataBinding->Data = (TObject *)IndexOfLoBound;

   // this line is critical
   LithGridTableView1->DataController->CustomDataSource = LithDataSource;

   lgLithCode->DataBinding->Data = (TObject *)IndexOfLithCode;
   lgHumo->DataBinding->Data = (TObject*)IndexOfHumo;
   lgXShift->DataBinding->Data = (TObject*)IndexOfXShift;
   lgYShift->DataBinding->Data = (TObject*)IndexOfYShift;

   // this line is critical
   LithGridTableView2->DataController->CustomDataSource = LithComponentSource;
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::LoadLithData()
{
  LITH1 *Lith1;
  LITH2 *Lith2;

  if (Diag->Lithology->Count > 0) {
    for (int i=0; i<Diag->Lithology->Count; i++) {
      LITHUNIT *LithUnit = (LITHUNIT*)Diag->Lithology->Items[i];
      Lith1 = new LITH1(LithUnit);
      for (int j=0; j<LithUnit->Components->Count; j++) {
        LITHCOMPONENT *Component = (LITHCOMPONENT*)LithUnit->Components->Items[j];
        Lith2 = new LITH2(Component, TroelsSmithCodes);
        if (Lith2->LithCode.SubString(1,6) == "Bitmap")
          Lith2->TabSheet = BitmapTabSheet;
        else
          SetTroelsSmithTabSheet(Lith2);
        Lith1->Components->Add(Lith2);
        }
      LithList->Add(Lith1);
      }
      LithGridTableView1->DataController->GotoFirst();
	  EnableButtons();

      LithGridTableView1->BeginUpdate();
      LithGridTableView1->DataController->ClearSorting(true);
      lgTopDepth->SortOrder = soAscending;
      LithGridTableView1->EndUpdate();
    }
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::FormDeactivate(TObject *Sender)
{
   delete pBitmap;
   for (unsigned int i=0; i<LTHBitmaps.size(); i++)
	 delete LTHBitmaps[i];
   for (unsigned int i=0; i<Image1Bitmaps.size(); i++)
	 delete Image1Bitmaps[i];
}
//---------------------------------------------------------------------------

void TLithForm::EnableButtons(void)
{
   if (!ButtonsEnabled) {
	 SpeedButton1->Enabled = true;
     SpeedButton2->Enabled = true;
     SpeedButton3->Enabled = true;
     SpeedButton4->Enabled = true;
	 SpeedButton5->Enabled = true;
     SpeedButton6->Enabled = true;
     SpeedButton7->Enabled = true;
     SpeedButton8->Enabled = true;
     SpeedButton9->Enabled = true;
     SpeedButton10->Enabled = true;
     SpeedButton11->Enabled = true;
     SpeedButton12->Enabled = true;
     SpeedButton13->Enabled = true;
     SpeedButton14->Enabled = true;
     SpeedButton15->Enabled = true;
     SpeedButton16->Enabled = true;
     SpeedButton17->Enabled = true;
     SpeedButton18->Enabled = true;
     SpeedButton19->Enabled = true;
     SpeedButton20->Enabled = true;
     SpeedButton21->Enabled = true;
     SpeedButton22->Enabled = true;
     SpeedButton23->Enabled = true;
     SpeedButton24->Enabled = true;
     SpeedButton25->Enabled = true;
     SpeedButton26->Enabled = true;
     SpeedButton27->Enabled = true;
     SpeedButton28->Enabled = true;
     SpeedButton29->Enabled = true;
     SpeedButton30->Enabled = true;
     SpeedButton31->Enabled = true;
     SpeedButton32->Enabled = true;
     SpeedButton33->Enabled = true;
	 SpeedButton34->Enabled = true;
     SpeedButton35->Enabled = true;
     SpeedButton36->Enabled = true;
     SpeedButton37->Enabled = true;
     SpeedButton38->Enabled = true;
     SpeedButton39->Enabled = true;
     SpeedButton40->Enabled = true;
     SpeedButton41->Enabled = true;
     SpeedButton42->Enabled = true;
     SpeedButton43->Enabled = true;
     SpeedButton44->Enabled = true;
     SpeedButton45->Enabled = true;
     SpeedButton46->Enabled = true;
     SpeedButton47->Enabled = true;
     SpeedButton48->Enabled = true;
     SpeedButton49->Enabled = true;
     SpeedButton50->Enabled = true;
     SpeedButton51->Enabled = true;
     SpeedButton52->Enabled = true;
     SpeedButton53->Enabled = true;
     SpeedButton54->Enabled = true;
     SpeedButton55->Enabled = true;
     SpeedButton56->Enabled = true;
     SpeedButton57->Enabled = true;
     SpeedButton58->Enabled = true;
     SpeedButton59->Enabled = true;
     SpeedButton60->Enabled = true;
     SpeedButton61->Enabled = true;
     SpeedButton62->Enabled = true;
     SpeedButton63->Enabled = true;
     SpeedButton64->Enabled = true;
     SpeedButton65->Enabled = true;
     SpeedButton66->Enabled = true;
     SpeedButton67->Enabled = true;
     SpeedButton68->Enabled = true;
     SpeedButton69->Enabled = true;
     SpeedButton70->Enabled = true;
     SpeedButton71->Enabled = true;
     SpeedButton72->Enabled = true;
     SpeedButton73->Enabled = true;
     SpeedButton74->Enabled = true;
     SpeedButton75->Enabled = true;
     SpeedButton76->Enabled = true;
     SpeedButton77->Enabled = true;
     SpeedButton78->Enabled = true;
     SpeedButton79->Enabled = true;
     SpeedButton80->Enabled = true;
     SpeedButton81->Enabled = true;
     SpeedButton82->Enabled = true;
     SpeedButton83->Enabled = true;
     SpeedButton84->Enabled = true;
     SpeedButton85->Enabled = true;
     SpeedButton86->Enabled = true;
     SpeedButton87->Enabled = true;
     SpeedButton88->Enabled = true;
     SpeedButton89->Enabled = true;
     SpeedButton90->Enabled = true;
     SpeedButton91->Enabled = true;
     SpeedButton92->Enabled = true;
     SpeedButton93->Enabled = true;
     SpeedButton94->Enabled = true;
     SpeedButton95->Enabled = true;
     SpeedButton96->Enabled = true;
     SpeedButton97->Enabled = true;
     SpeedButton98->Enabled = true;
     SpeedButton99->Enabled = true;
     SpeedButton100->Enabled = true;
     SpeedButton101->Enabled = true;
     SpeedButton102->Enabled = true;
     SpeedButton103->Enabled = true;
     SpeedButton104->Enabled = true;
     SpeedButton105->Enabled = true;
     SpeedButton106->Enabled = true;
     SpeedButton107->Enabled = true;
     SpeedButton108->Enabled = true;
     SpeedButton109->Enabled = true;
     SpeedButton110->Enabled = true;
     SpeedButton111->Enabled = true;
     SpeedButton112->Enabled = true;
     SpeedButton113->Enabled = true;
     SpeedButton114->Enabled = true;
     SpeedButton115->Enabled = true;
     SpeedButton116->Enabled = true;
     SpeedButton117->Enabled = true;
     SpeedButton118->Enabled = true;
     SpeedButton119->Enabled = true;
     SpeedButton120->Enabled = true;
     SpeedButton121->Enabled = true;
     SpeedButton122->Enabled = true;
     SpeedButton123->Enabled = true;
     SpeedButton124->Enabled = true;
     SpeedButton125->Enabled = true;
     SpeedButton126->Enabled = true;
     SpeedButton127->Enabled = true;
     SpeedButton128->Enabled = true;
     SpeedButton129->Enabled = true;
     ButtonsEnabled = true;
     }

// ADD HERE
}
//---------------------------------------------------------------------------

void TLithForm::DisableButtons(void)
{
   if (ButtonsEnabled) {
	 SpeedButton1->Enabled = false;
     SpeedButton2->Enabled = false;
     SpeedButton3->Enabled = false;
     SpeedButton4->Enabled = false;
     SpeedButton5->Enabled = false;
     SpeedButton6->Enabled = false;
     SpeedButton7->Enabled = false;
     SpeedButton8->Enabled = false;
     SpeedButton9->Enabled = false;
     SpeedButton10->Enabled = false;
     SpeedButton11->Enabled = false;
     SpeedButton12->Enabled = false;
     SpeedButton13->Enabled = false;
     SpeedButton14->Enabled = false;
     SpeedButton15->Enabled = false;
     SpeedButton16->Enabled = false;
     SpeedButton17->Enabled = false;
     SpeedButton18->Enabled = false;
     SpeedButton19->Enabled = false;
     SpeedButton20->Enabled = false;
     SpeedButton21->Enabled = false;
     SpeedButton22->Enabled = false;
     SpeedButton23->Enabled = false;
     SpeedButton24->Enabled = false;
     SpeedButton25->Enabled = false;
     SpeedButton26->Enabled = false;
     SpeedButton27->Enabled = false;
     SpeedButton28->Enabled = false;
     SpeedButton29->Enabled = false;
     SpeedButton30->Enabled = false;
     SpeedButton31->Enabled = false;
     SpeedButton32->Enabled = false;
     SpeedButton33->Enabled = false;
     SpeedButton34->Enabled = false;
     SpeedButton35->Enabled = false;
     SpeedButton36->Enabled = false;
     SpeedButton37->Enabled = false;
     SpeedButton38->Enabled = false;
     SpeedButton39->Enabled = false;
     SpeedButton40->Enabled = false;
     SpeedButton41->Enabled = false;
     SpeedButton42->Enabled = false;
     SpeedButton43->Enabled = false;
     SpeedButton44->Enabled = false;
     SpeedButton45->Enabled = false;
     SpeedButton46->Enabled = false;
     SpeedButton47->Enabled = false;
     SpeedButton48->Enabled = false;
     SpeedButton49->Enabled = false;
     SpeedButton50->Enabled = false;
     SpeedButton51->Enabled = false;
     SpeedButton52->Enabled = false;
     SpeedButton53->Enabled = false;
     SpeedButton54->Enabled = false;
     SpeedButton55->Enabled = false;
     SpeedButton56->Enabled = false;
     SpeedButton57->Enabled = false;
     SpeedButton58->Enabled = false;
     SpeedButton59->Enabled = false;
     SpeedButton60->Enabled = false;
     SpeedButton61->Enabled = false;
     SpeedButton62->Enabled = false;
     SpeedButton63->Enabled = false;
     SpeedButton64->Enabled = false;
     SpeedButton65->Enabled = false;
     SpeedButton66->Enabled = false;
     SpeedButton67->Enabled = false;
     SpeedButton68->Enabled = false;
     SpeedButton69->Enabled = false;
     SpeedButton70->Enabled = false;
     SpeedButton71->Enabled = false;
     SpeedButton72->Enabled = false;
     SpeedButton73->Enabled = false;
     SpeedButton74->Enabled = false;
     SpeedButton75->Enabled = false;
     SpeedButton76->Enabled = false;
     SpeedButton77->Enabled = false;
     SpeedButton78->Enabled = false;
     SpeedButton79->Enabled = false;
     SpeedButton80->Enabled = false;
     SpeedButton81->Enabled = false;
     SpeedButton82->Enabled = false;
     SpeedButton83->Enabled = false;
     SpeedButton84->Enabled = false;
     SpeedButton85->Enabled = false;
     SpeedButton86->Enabled = false;
     SpeedButton87->Enabled = false;
     SpeedButton88->Enabled = false;
     SpeedButton89->Enabled = false;
     SpeedButton90->Enabled = false;
     SpeedButton91->Enabled = false;
     SpeedButton92->Enabled = false;
     SpeedButton93->Enabled = false;
     SpeedButton94->Enabled = false;
     SpeedButton95->Enabled = false;
     SpeedButton96->Enabled = false;
     SpeedButton97->Enabled = false;
     SpeedButton98->Enabled = false;
     SpeedButton99->Enabled = false;
     SpeedButton100->Enabled = false;
     SpeedButton101->Enabled = false;
     SpeedButton102->Enabled = false;
     SpeedButton103->Enabled = false;
     SpeedButton104->Enabled = false;
     SpeedButton105->Enabled = false;
     SpeedButton106->Enabled = false;
     SpeedButton107->Enabled = false;
     SpeedButton108->Enabled = false;
     SpeedButton109->Enabled = false;
     SpeedButton110->Enabled = false;
     SpeedButton111->Enabled = false;
     SpeedButton112->Enabled = false;
     SpeedButton113->Enabled = false;
     SpeedButton114->Enabled = false;
     SpeedButton115->Enabled = false;
     SpeedButton116->Enabled = false;
     SpeedButton117->Enabled = false;
     SpeedButton118->Enabled = false;
     SpeedButton119->Enabled = false;
     SpeedButton120->Enabled = false;
     SpeedButton121->Enabled = false;
     SpeedButton122->Enabled = false;
     SpeedButton123->Enabled = false;
     SpeedButton124->Enabled = false;
     SpeedButton125->Enabled = false;
     SpeedButton126->Enabled = false;
     SpeedButton127->Enabled = false;
     SpeedButton128->Enabled = false;
     SpeedButton129->Enabled = false;

     // ADD HERE WHEN ADDING NEW TS PATTERNS
     ButtonsEnabled = false;
     }
}
//---------------------------------------------------------------------------

void TLithForm::RaiseBitmapButtons(void)
{
   SpeedButton1->Down = true;
   SpeedButton1->Down = false;
}
//---------------------------------------------------------------------------

void TLithForm::RaiseTroelsSmithButtons(void)
{
   SpeedButton34->Down = false;
   SpeedButton35->Down = false;
   SpeedButton36->Down = false;
   SpeedButton37->Down = false;
   SpeedButton38->Down = false;
   SpeedButton39->Down = false;
   SpeedButton40->Down = false;
   SpeedButton41->Down = false;
   SpeedButton42->Down = false;
   SpeedButton43->Down = false;
   SpeedButton44->Down = false;
   SpeedButton45->Down = false;
   SpeedButton46->Down = false;
   SpeedButton47->Down = false;
   SpeedButton48->Down = false;
   SpeedButton49->Down = false;
   SpeedButton50->Down = false;
   SpeedButton51->Down = false;
   SpeedButton52->Down = false;
   SpeedButton53->Down = false;
   SpeedButton54->Down = false;
   SpeedButton55->Down = false;
   SpeedButton56->Down = false;
   SpeedButton57->Down = false;
   SpeedButton58->Down = false;
   SpeedButton59->Down = false;
   SpeedButton60->Down = false;
   SpeedButton61->Down = false;
   SpeedButton62->Down = false;
   SpeedButton63->Down = false;
   SpeedButton64->Down = false;
   SpeedButton65->Down = false;
   SpeedButton66->Down = false;
   SpeedButton67->Down = false;
   SpeedButton68->Down = false;
   SpeedButton69->Down = false;
   SpeedButton70->Down = false;
   SpeedButton71->Down = false;
   SpeedButton72->Down = false;
   SpeedButton73->Down = false;
   SpeedButton74->Down = false;
   SpeedButton75->Down = false;
   SpeedButton76->Down = false;
   SpeedButton77->Down = false;
   SpeedButton78->Down = false;
   SpeedButton79->Down = false;
   SpeedButton80->Down = false;
   SpeedButton81->Down = false;
   SpeedButton82->Down = false;
   SpeedButton83->Down = false;
   SpeedButton84->Down = false;
   SpeedButton85->Down = false;
   SpeedButton86->Down = false;
   SpeedButton87->Down = false;
   SpeedButton88->Down = false;
   SpeedButton89->Down = false;
   SpeedButton90->Down = false;
   SpeedButton91->Down = false;
   SpeedButton92->Down = false;
   SpeedButton93->Down = false;
   SpeedButton94->Down = false;
   SpeedButton95->Down = false;
   SpeedButton96->Down = false;
   SpeedButton97->Down = false;
   SpeedButton98->Down = false;
   SpeedButton99->Down = false;
   SpeedButton100->Down = false;
   SpeedButton101->Down = false;
   SpeedButton102->Down = false;
   SpeedButton103->Down = false;
   SpeedButton104->Down = false;
   SpeedButton105->Down = false;
   SpeedButton106->Down = false;
   SpeedButton107->Down = false;
   SpeedButton108->Down = false;
   SpeedButton109->Down = false;
   SpeedButton110->Down = false;
   SpeedButton111->Down = false;
   SpeedButton112->Down = false;
   SpeedButton113->Down = false;
   SpeedButton114->Down = false;
   SpeedButton115->Down = false;
   SpeedButton116->Down = false;
   SpeedButton117->Down = false;
   SpeedButton118->Down = false;
   SpeedButton119->Down = false;
   SpeedButton120->Down = false;
   SpeedButton121->Down = false;
   SpeedButton122->Down = false;
   SpeedButton123->Down = false;
   SpeedButton124->Down = false;
   SpeedButton125->Down = false;
   SpeedButton126->Down = false;
   SpeedButton127->Down = false;
   SpeedButton128->Down = false;
   SpeedButton129->Down = false;
   // ADD HERE WHEN ADDING NEW TS PATTERNS
}
//---------------------------------------------------------------------------

void TLithForm::EnableShiftButtons(void)
{
   BitBtn1->Enabled = true;
   BitBtn2->Enabled = true;
   BitBtn3->Enabled = true;
   BitBtn4->Enabled = true;
   BitBtn5->Enabled = true;
}
//---------------------------------------------------------------------------

void TLithForm::SetComponentColorBox(void)
{
   LITH1 *Lith1;

   TcxCustomGridRecord *AFocusedRecord =
      LithGridTableView1->Controller->FocusedRecord;

   if (!AFocusedRecord)
     return;

   if (AFocusedRecord->RecordIndex == -1) {
     if (LithDataSource->TempLith1)
       Lith1 = LithDataSource->TempLith1;
     else
       return;  
     }
   else
     Lith1 = (LITH1*)LithDataSource->LithList->Liths[AFocusedRecord->RecordIndex];

   if (Lith1->Components->Count) {
     LITH2* Lith2 = GetCurrentLith2(Lith1);
     if (Lith2) {
       ColorBox1->Enabled = true;
       ColorBox1->Selected = Lith2->Color;
       }
     }
}
//---------------------------------------------------------------------------

void TLithForm::DisableShiftButtons(void)
{
   BitBtn1->Enabled = false;
   BitBtn2->Enabled = false;
   BitBtn3->Enabled = false;
   BitBtn4->Enabled = false;
   BitBtn5->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::PageControl1Change(TObject *Sender)
{
   if (PageControl1->ActivePage == BitmapTabSheet) {
     DisableShiftButtons();
     SetComponentColorBox();
     }
   else if (PageControl1->ActivePage == ShTabSheet) {
	 if (SpeedButton34->Down || SpeedButton35->Down ||
         SpeedButton36->Down || SpeedButton37->Down) {
       EnableShiftButtons();
       SetComponentColorBox(); }
     else {
       DisableShiftButtons();
       ColorBox1->Enabled = false; }
     }
   else if (PageControl1->ActivePage == TbTabSheet) {
     if (SpeedButton38->Down || SpeedButton39->Down ||
         SpeedButton40->Down || SpeedButton41->Down) {
       EnableShiftButtons();
       SetComponentColorBox(); }
     else {
       DisableShiftButtons();
       ColorBox1->Enabled = false; }
     }
   else if (PageControl1->ActivePage == TbSTabSheet) {
     if (SpeedButton42->Down || SpeedButton43->Down ||
         SpeedButton44->Down || SpeedButton45->Down) {
       EnableShiftButtons();
       SetComponentColorBox(); }
     else {
       DisableShiftButtons();
       ColorBox1->Enabled = false; }
     }
   else if (PageControl1->ActivePage == TbScTabSheet) {
     if (SpeedButton46->Down || SpeedButton47->Down ||
         SpeedButton48->Down || SpeedButton49->Down) {
       EnableShiftButtons();
       SetComponentColorBox(); }
     else {
       DisableShiftButtons();
       ColorBox1->Enabled = false; }
     }
   else if (PageControl1->ActivePage == TlTabSheet) {
     if (SpeedButton50->Down || SpeedButton51->Down ||
         SpeedButton52->Down || SpeedButton53->Down) {
       EnableShiftButtons();
       SetComponentColorBox(); }
     else {
       DisableShiftButtons();
       ColorBox1->Enabled = false; }
     }
   else if (PageControl1->ActivePage == ThTabSheet) {
     if (SpeedButton54->Down || SpeedButton55->Down ||
         SpeedButton56->Down || SpeedButton57->Down) {
       EnableShiftButtons();
       SetComponentColorBox(); }
     else {
       DisableShiftButtons();
       ColorBox1->Enabled = false; }
     }
   else if (PageControl1->ActivePage == ThhTabSheet) {
     if (SpeedButton58->Down || SpeedButton59->Down ||
         SpeedButton60->Down || SpeedButton61->Down) {
       EnableShiftButtons();
       SetComponentColorBox(); }
     else {
       DisableShiftButtons();
       ColorBox1->Enabled = false; }
     }
   else if (PageControl1->ActivePage == DlTabSheet) {
     if (SpeedButton62->Down || SpeedButton63->Down ||
         SpeedButton64->Down || SpeedButton65->Down) {
       EnableShiftButtons();
       SetComponentColorBox(); }
     else {
       DisableShiftButtons();
       ColorBox1->Enabled = false; }
     }
   else if (PageControl1->ActivePage == DhTabSheet) {
     if (SpeedButton66->Down || SpeedButton67->Down ||
         SpeedButton68->Down || SpeedButton69->Down) {
       EnableShiftButtons();
       SetComponentColorBox(); }
     else {
       DisableShiftButtons();
       ColorBox1->Enabled = false; }
     }
   else if (PageControl1->ActivePage == DgTabSheet) {
     if (SpeedButton70->Down || SpeedButton71->Down ||
         SpeedButton72->Down || SpeedButton73->Down) {
       EnableShiftButtons();
       SetComponentColorBox(); }
     else {
       DisableShiftButtons();
       ColorBox1->Enabled = false; }
     }
   else if (PageControl1->ActivePage == LdTabSheet) {
     if (SpeedButton74->Down || SpeedButton75->Down ||
         SpeedButton76->Down || SpeedButton77->Down) {
       EnableShiftButtons();
       SetComponentColorBox(); }
     else {
       DisableShiftButtons();
       ColorBox1->Enabled = false; }
     }
   else if (PageControl1->ActivePage == LsoTabSheet) {
     if (SpeedButton78->Down || SpeedButton79->Down ||
         SpeedButton80->Down || SpeedButton81->Down) {
       EnableShiftButtons();
       SetComponentColorBox(); }
     else {
       DisableShiftButtons();
       ColorBox1->Enabled = false; }
     }
   else if (PageControl1->ActivePage == LcTabSheet) {
     if (SpeedButton82->Down || SpeedButton83->Down ||
         SpeedButton84->Down || SpeedButton85->Down) {
       EnableShiftButtons();
       SetComponentColorBox(); }
     else {
       DisableShiftButtons();
       ColorBox1->Enabled = false; }
     }
   else if (PageControl1->ActivePage == LfTabSheet) {
     if (SpeedButton86->Down || SpeedButton87->Down ||
         SpeedButton88->Down || SpeedButton89->Down) {
       EnableShiftButtons();
       SetComponentColorBox(); }
     else {
       DisableShiftButtons();
       ColorBox1->Enabled = false; }
     }
   else if (PageControl1->ActivePage == AsTabSheet) {
     if (SpeedButton90->Down || SpeedButton91->Down ||
         SpeedButton92->Down || SpeedButton93->Down) {
       EnableShiftButtons();
       SetComponentColorBox(); }
     else {
       DisableShiftButtons();
       ColorBox1->Enabled = false; }
     }
   else if (PageControl1->ActivePage == AsTabSheet) {
     if (SpeedButton94->Down || SpeedButton95->Down ||
         SpeedButton96->Down || SpeedButton97->Down) {
       EnableShiftButtons();
       SetComponentColorBox(); }
     else {
       DisableShiftButtons();
       ColorBox1->Enabled = false; }
     }
   else if (PageControl1->ActivePage == GaTabSheet) {
     if (SpeedButton98->Down || SpeedButton99->Down ||
         SpeedButton100->Down || SpeedButton101->Down) {
       EnableShiftButtons();
       SetComponentColorBox(); }
     else {
       DisableShiftButtons();
       ColorBox1->Enabled = false; }
     }
   else if (PageControl1->ActivePage == GsTabSheet) {
     if (SpeedButton102->Down || SpeedButton103->Down ||
         SpeedButton104->Down || SpeedButton105->Down) {
       EnableShiftButtons();
       SetComponentColorBox(); }
     else {
       DisableShiftButtons();
       ColorBox1->Enabled = false; }
     }
   else if (PageControl1->ActivePage == GgminTabSheet) {
     if (SpeedButton106->Down || SpeedButton107->Down ||
         SpeedButton108->Down || SpeedButton109->Down) {
       EnableShiftButtons();
       SetComponentColorBox(); }
     else {
       DisableShiftButtons();
       ColorBox1->Enabled = false; }
     }
   else if (PageControl1->ActivePage == GgmajTabSheet) {
     if (SpeedButton110->Down || SpeedButton111->Down ||
         SpeedButton112->Down || SpeedButton113->Down) {
       EnableShiftButtons();
       SetComponentColorBox(); }
     else {
       DisableShiftButtons();
       ColorBox1->Enabled = false; }
     }
   else if (PageControl1->ActivePage == TestTabSheet) {
     if (SpeedButton114->Down || SpeedButton115->Down ||
         SpeedButton116->Down || SpeedButton117->Down) {
       EnableShiftButtons();
	   SetComponentColorBox(); }
     else {
       DisableShiftButtons();
       ColorBox1->Enabled = false; }
     }
   else if (PageControl1->ActivePage == PartTestTabSheet) {
     if (SpeedButton118->Down || SpeedButton119->Down ||
         SpeedButton120->Down || SpeedButton121->Down) {
       EnableShiftButtons();
       SetComponentColorBox(); }
     else {
       DisableShiftButtons();
       ColorBox1->Enabled = false; }
     }
   else if (PageControl1->ActivePage == CortSecTabSheet) {
     if (SpeedButton122->Down || SpeedButton123->Down ||
         SpeedButton124->Down || SpeedButton125->Down) {
       EnableShiftButtons();
       SetComponentColorBox(); }
     else {
       DisableShiftButtons();
       ColorBox1->Enabled = false; }
     }
   else if (PageControl1->ActivePage == CortTabSheet) {
     if (SpeedButton126->Down || SpeedButton127->Down ||
         SpeedButton128->Down || SpeedButton129->Down) {
       EnableShiftButtons();
       SetComponentColorBox(); }
     else {
       DisableShiftButtons();
       ColorBox1->Enabled = false; }
     }

   // ADD HERE WHEN ADDING NEW TS PATTERNS
}
//---------------------------------------------------------------------------

void TLithForm::DepressBitmapButton(LITH2* Lith2)
{
   PageControl1->ActivePage = BitmapTabSheet;
   int code = (Lith2->LithCode.SubString(7,2)).ToInt();
   Lith2->SpeedButton = NULL;

   switch (code) {
     case 1:  SpeedButton1->Down = true;  break;
     case 2:  SpeedButton2->Down = true;  break;
     case 3:  SpeedButton3->Down = true;  break;
     case 4:  SpeedButton4->Down = true;  break;
     case 5:  SpeedButton5->Down = true;  break;
     case 6:  SpeedButton6->Down = true;  break;
     case 7:  SpeedButton7->Down = true;  break;
     case 8:  SpeedButton8->Down = true;  break;
     case 9:  SpeedButton9->Down = true;  break;
     case 10: SpeedButton10->Down = true; break;
     case 11: SpeedButton11->Down = true; break;
     case 12: SpeedButton12->Down = true; break;
     case 13: SpeedButton13->Down = true; break;
     case 14: SpeedButton14->Down = true; break;
     case 15: SpeedButton15->Down = true; break;
     case 16: SpeedButton16->Down = true; break;
     case 17: SpeedButton17->Down = true; break;
     case 18: SpeedButton18->Down = true; break;
     case 19: SpeedButton19->Down = true; break;
     case 20: SpeedButton20->Down = true; break;
     case 21: SpeedButton21->Down = true; break;
     case 22: SpeedButton22->Down = true; break;
     case 23: SpeedButton23->Down = true; break;
     case 24: SpeedButton24->Down = true; break;
     case 25: SpeedButton25->Down = true; break;
     case 26: SpeedButton26->Down = true; break;
     case 27: SpeedButton27->Down = true; break;
     case 28: SpeedButton28->Down = true; break;
     case 29: SpeedButton29->Down = true; break;
     case 30: SpeedButton30->Down = true; break;
     case 31: SpeedButton31->Down = true; break;
     case 32: SpeedButton32->Down = true; break;
     case 33: SpeedButton33->Down = true; break;
     }
}
//---------------------------------------------------------------------------

void TLithForm::SetBitmap(int code, TSpeedButton* SpeedButton)
{
   LITH1 *Lith1;
   LITH2 *Lith2;
   UnicodeString Msg;

   TcxCustomGridRecord *AFocusedRecord =
      LithGridTableView1->Controller->FocusedRecord;

   if (AFocusedRecord->RecordIndex == -1) 
     Lith1 = LithDataSource->TempLith1;
   else
     Lith1 = (LITH1*)LithDataSource->LithList->Liths[AFocusedRecord->RecordIndex];

   if (SpeedButton->Down) {
     // is there a lith component already?
     if (Lith1->Components->Count > 0) {
	   Lith2 = (LITH2*)Lith1->Components->Items[0];
	   if (Lith2->LithCode.SubString(1,6) == "Bitmap") {
		 Lith2->LithCode = "Bitmap" + IntToStr(code);
		 Lith2->SpeedButton = NULL;
		 DrawBitmap(code, Lith2->Color);
		 }
       else { // existing component is TS
         Msg = "Replace Troels-Smith pattern";
         if (Lith1->Components->Count == 1)
           Msg += (" " + Lith2->LithCode);
         else if (Lith1->Components->Count == 2) {
           Msg += ("s " + Lith2->LithCode + " and ");
           Lith2 = (LITH2*)Lith1->Components->Items[1];
           Msg += Lith2->LithCode;
           }
         else if (Lith1->Components->Count == 3) {
           Msg += ("s " + Lith2->LithCode + ", ");
           Lith2 = (LITH2*)Lith1->Components->Items[1];
           Msg += (Lith2->LithCode + ", and ");
           Lith2 = (LITH2*)Lith1->Components->Items[2];
           Msg += Lith2->LithCode;
           }
         else if (Lith1->Components->Count == 3) {
           Msg += ("s " + Lith2->LithCode + ", ");
           Lith2 = (LITH2*)Lith1->Components->Items[1];
           Msg += (Lith2->LithCode + ", ");
           Lith2 = (LITH2*)Lith1->Components->Items[2];
           Msg += (Lith2->LithCode + ", and ");
           Lith2 = (LITH2*)Lith1->Components->Items[3];
           Msg += Lith2->LithCode;
           }
         Msg += (" with Bitmap" + IntToStr(code) + "?");
         if (MessageDlg(Msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes) {
           int count = Lith1->Components->Count;
           for (int i=count-1; i>0; i--) {
             Lith2 = (LITH2*)Lith1->Components->Items[i];
             Lith1->Components->Delete(i);
             delete Lith2;
             LithComponentSource->DataChanged();
             }
           Lith2 = (LITH2*)Lith1->Components->Items[0];
           Lith2->LithCode = "Bitmap" + IntToStr(code);
           Lith2->Humo = 0;
           Lith2->XShift = 0;
           Lith2->YShift = 0;
           Lith2->Color = clBlack;
           Lith2->TabSheet = BitmapTabSheet;
           Lith2->SpeedButton = NULL;
           DrawBitmap(code, Lith2->Color);
           ColorBox1->Enabled = true;
           ColorBox1->Selected = Lith2->Color;
           }
         }
       }
     else {
       DrawBitmap(code, clBlack);
       LithGridTableView2->OptionsData->Inserting = true;
       Lith2 = new LITH2;
       Lith2->LithCode = "Bitmap" + IntToStr(code);
       Lith2->TabSheet = BitmapTabSheet;
       Lith1->Components->Add(Lith2);
       LithGridTableView2->DataController->Post();
       LithComponentSource->DataChanged();
       LithGridTableView2->OptionsData->Inserting = false;
       ColorBox1->Enabled = true;
       ColorBox1->Selected = Lith2->Color;
       }
     }
   else {  // speedbutton is up
     if (Lith1->Components->Count > 0) {
       Lith2 = (LITH2*)Lith1->Components->Items[0];
       Lith1->Components->Delete(0);
       delete Lith2;
       ClearBitmap();
       ColorBox1->Enabled = false;
       ColorBox1->Selected = Diag->lopt.DefaultColor;
	   }
     }
   LithComponentSource->DataChanged();
   LithGridTableView2->DataController->Post();
}
//---------------------------------------------------------------------------

void TLithForm::DrawBitmap(int code, TColor Color)
{
   // use first LTHBitmap for bitmapped pattern
   LithBmp = LTHBitmaps[0];
   //LithBmp->Canvas->Brush->Bitmap = (Graphics::TBitmap *)ParentForm->GKSBitmaps->Items[code-1];
   LithBmp->Canvas->Brush->Bitmap = ParentForm->GKSBitmaps[code-1];

   SetTextColor(LithBmp->Canvas->Handle, Color);
   SetBkColor(LithBmp->Canvas->Handle, TColor(Diag->Picture->BackgroundColor));
   LithBmp->Canvas->FillRect(Rect(0,0,120,160));
   Image1->Picture->Bitmap->Assign(LithBmp);
   SetTextColor(LithBmp->Canvas->Handle, clBlack);

   DrawLowerBound();
   DisableShiftButtons();
   RaiseTroelsSmithButtons();
}
//---------------------------------------------------------------------------

void TLithForm::ClearBitmap(void)
{
   Image1->Canvas->Brush->Style = bsSolid;
   Image1->Canvas->Brush->Color = (TColor)Diag->Picture->BackgroundColor;
   Image1->Canvas->FillRect(Rect(0,0,120,160));
   SpeedButton1->Down = true;
   SpeedButton1->Down = false;
   DisableShiftButtons();
   ColorBox1->Enabled = false;
   RaiseTroelsSmithButtons();
}
//---------------------------------------------------------------------------

void TLithForm::DepressTroelsSmithButtons(LITH1 *pLith1, LITH1 *Lith1)
{
   LITH2 *Lith2;

   // raise previous speedbutton
   if (pLith1) {
     for (int i=0; i<pLith1->Components->Count; i++) {
       Lith2 = (LITH2*)pLith1->Components->Items[i];
       if (Lith2) {
         if (Lith2->SpeedButton) {
           Lith2->SpeedButton->Down = false;
           if (Lith2->H1SpeedButton)
             Lith2->H1SpeedButton->Down = false;
           if (Lith2->H2SpeedButton)
             Lith2->H2SpeedButton->Down = false;
           if (Lith2->H3SpeedButton)
             Lith2->H3SpeedButton->Down = false;
           if (Lith2->H4SpeedButton)
             Lith2->H4SpeedButton->Down = false;
           }
         }
       }
     }
     
   // depress speedbuttons
   for (int i=0; i<Lith1->Components->Count; i++) {
     Lith2 = (LITH2*)Lith1->Components->Items[i];
     if (Lith2) {
       if (Lith2->SpeedButton) {
         Lith2->SpeedButton->Down = true;
         switch (Lith2->Humo) {
           case 1: Lith2->H1SpeedButton->Down = true; break;
           case 2: Lith2->H2SpeedButton->Down = true; break;
           case 3: Lith2->H3SpeedButton->Down = true; break;
           case 4: Lith2->H4SpeedButton->Down = true; break;
           }
         }
       }
     }

   // show tabsheet for first pattern
   Lith2 = (LITH2*)Lith1->Components->Items[0];
   if (Lith2->TabSheet)
     PageControl1->ActivePage = Lith2->TabSheet;
}
//---------------------------------------------------------------------------

void TLithForm::DrawTroelsSmith(LITH1 *Lith1)
{
   LITH2 *Lith2;
   int nPix;
   RGBTRIPLE *pixels[4];
   RGBTRIPLE *pix;
   Graphics::TBitmap *Bitmap1;
   Graphics::TBitmap *Bitmap2;
   int j;

   delete pBitmap;
   pBitmap = new Graphics::TBitmap();
   pBitmap->Width = 120;
   pBitmap->Height = 160;
   pBitmap->PixelFormat = pf24bit;
   Image1->Picture->Bitmap->Assign(pBitmap);

   Graphics::TBitmap *bmp = LTHBitmaps[0];
   delete bmp;
   bmp = new Graphics::TBitmap;
   bmp->Width = 120;
   bmp->Height = 160;
   bmp->PixelFormat = pf24bit;

   for (int i=0; i<4; i++)
	 Image1Bitmaps[i]->Assign(LTHBitmaps[0]);

   for (int i=0; i<Lith1->Components->Count; i++) {
	 if (i > 3) break;
	 Lith2 = (LITH2*)Lith1->Components->Items[i];
	 int index = TroelsSmithCodes->IndexOf(Lith2->LithCode);
	 if (index < 0) continue;
	 Bitmap1 = Image1Bitmaps[i];
	 cxImageList1->GetBitmap(index, Bitmap1);

	 // set color
     for (int y=0; y<160; y++) {
       pix = (RGBTRIPLE*)Bitmap1->ScanLine[y];
       for (int x=0; x<160; x++) {
         if ((int)pix[x].rgbtRed == 0)
           Bitmap1->Canvas->Pixels[x][y] = Lith2->Color;
         else
		   Bitmap1->Canvas->Pixels[x][y] = (TColor)Diag->Picture->BackgroundColor;
         }
       }        

     if (Lith2->XShift > 0) {
       Bitmap2 = new Graphics::TBitmap();
       Bitmap2->PixelFormat = pf24bit;
	   Bitmap2->Assign(Bitmap1);
       nPix = nint(100.0*Lith2->XShift);
       int index = TroelsSmithCodes->IndexOf(Lith2->LithCode);
       for (int y=0; y<160; y++) {
         pix = (RGBTRIPLE*)Bitmap2->ScanLine[y];
         int start = MaxXShift[index] - nPix;
         for (int x=0, j=start; x<nPix; x++, j++)
           Bitmap1->Canvas->Pixels[x][y] =
             TColor(RGB(pix[j].rgbtRed, pix[j].rgbtGreen, pix[j].rgbtBlue));
         for (int x=nPix, j=0; x<120; x++, j++)
           Bitmap1->Canvas->Pixels[x][y] =
             TColor(RGB(pix[j].rgbtRed, pix[j].rgbtGreen, pix[j].rgbtBlue));
         }
       delete Bitmap2;
       }
     else if (Lith2->XShift < 0) {
       Bitmap2 = new Graphics::TBitmap();
       Bitmap2->PixelFormat = pf24bit;
       Bitmap2->Assign(Bitmap1);
       nPix = -nint(100.0*Lith2->XShift);
       int index = TroelsSmithCodes->IndexOf(Lith2->LithCode);
       for (int y=0; y<160; y++) {
         pix = (RGBTRIPLE*)Bitmap2->ScanLine[y];
         for (int x=0, j=nPix; x<120-nPix; x++, j++)
           Bitmap1->Canvas->Pixels[x][y] =
             TColor(RGB(pix[j].rgbtRed, pix[j].rgbtGreen, pix[j].rgbtBlue));
         int start = 120 - MaxXShift[index];
         for (int x=120-nPix, j=start; x<120; x++, j++)
           Bitmap1->Canvas->Pixels[x][y] =
             TColor(RGB(pix[j].rgbtRed, pix[j].rgbtGreen, pix[j].rgbtBlue));
         }
       delete Bitmap2;
       }

     if (Lith2->YShift < 0) {
       Bitmap2 = new Graphics::TBitmap();
       Bitmap2->PixelFormat = pf24bit;
       Bitmap2->Assign(Bitmap1);
       nPix = -nint(100.0*Lith2->YShift);
       int index = TroelsSmithCodes->IndexOf(Lith2->LithCode);
       int start = MaxYShift[index] - nPix;
       for (int y=0, j=start; y<nPix; y++, j++) {
         pix = (RGBTRIPLE*)Bitmap2->ScanLine[j];
		 for (int x=0; x<120; x++)
           Bitmap1->Canvas->Pixels[x][y] =
             TColor(RGB(pix[x].rgbtRed, pix[x].rgbtGreen, pix[x].rgbtBlue));
         }
       for (int y=nPix, j=0; y<160; y++, j++) {
         pix = (RGBTRIPLE*)Bitmap2->ScanLine[j];
         for (int x=0; x<120; x++)
           Bitmap1->Canvas->Pixels[x][y] =
             TColor(RGB(pix[x].rgbtRed, pix[x].rgbtGreen, pix[x].rgbtBlue));
         }
       delete Bitmap2;
       }
     else if (Lith2->YShift > 0) {
       Bitmap2 = new Graphics::TBitmap();
       Bitmap2->PixelFormat = pf24bit;
       Bitmap2->Assign(Bitmap1);
       nPix = nint(100.0*Lith2->YShift);
       int index = TroelsSmithCodes->IndexOf(Lith2->LithCode);

       for (int y=0, j=nPix; y<160-nPix; y++, j++) {
         pix = (RGBTRIPLE*)Bitmap2->ScanLine[j];
         for (int x=0; x<120; x++)
           Bitmap1->Canvas->Pixels[x][y] =
             TColor(RGB(pix[x].rgbtRed, pix[x].rgbtGreen, pix[x].rgbtBlue));
         }
       int start = 160 - MaxYShift[index];
       for (int y=160-nPix, j=start; y<160; y++, j++) {
         pix = (RGBTRIPLE*)Bitmap2->ScanLine[j];
         for (int x=0; x<120; x++)
		   Bitmap1->Canvas->Pixels[x][y] =
             TColor(RGB(pix[x].rgbtRed, pix[x].rgbtGreen, pix[x].rgbtBlue));
         }
       delete Bitmap2;
       }
	 }

   for (int y=0; y<160; y++) {
	 for (int i=0; i<Lith1->Components->Count; i++)
	   pixels[i] = (RGBTRIPLE*)(Image1Bitmaps[i]->ScanLine[y]);
	 for (int x=0; x<120; x++) {
       pBitmap->Canvas->Pixels[x][y] =
         TColor(RGB(pixels[0][x].rgbtRed, pixels[0][x].rgbtGreen, pixels[0][x].rgbtBlue));
       for (int i=1; i<Lith1->Components->Count; i++) {
         if (pixels[i][x].rgbtRed < 255 || pixels[i][x].rgbtGreen < 255 || pixels[i][x].rgbtBlue < 255)
           pBitmap->Canvas->Pixels[x][y] =
             TColor(RGB(pixels[i][x].rgbtRed, pixels[i][x].rgbtGreen, pixels[i][x].rgbtBlue));
		 }
       }
     }

   Image1->Picture->Bitmap->Assign(pBitmap);

   // draw left and right lines
   // TODO: change DefaultColor to ColumnLineColor
   Image1->Canvas->Pen->Color = Diag->lopt.DefaultColor;
   Image1->Canvas->Pen->Style = psSolid;
   Image1->Canvas->MoveTo(0,0);
   Image1->Canvas->LineTo(0,159);
   Image1->Canvas->MoveTo(119,0);
   Image1->Canvas->LineTo(119,159);

   DrawLowerBound();
   EnableShiftButtons();
   RaiseBitmapButtons();
}

//---------------------------------------------------------------------------
void TLithForm::DrawLowerBound(void)
{
   LITH1 *Lith1;
   LITH1 *Lith1A;

   TcxCustomGridRecord *AFocusedRecord =
      LithGridTableView1->Controller->FocusedRecord;

   if (AFocusedRecord->RecordIndex == -1)
     Lith1 = LithDataSource->TempLith1;
   else
     Lith1 = (LITH1*)LithList->Liths[AFocusedRecord->RecordIndex];

   if (Lith1) {
     if (Lith1->LoBound) {
       Image1->Canvas->Brush->Color = Lith1->LoBoundColor;
       Image1->Canvas->Brush->Style = bsSolid;
       Image1->Canvas->FillRect(Rect(0,158,120,160));
       }
     }
}

//---------------------------------------------------------------------------

void TLithForm::SetTroelsSmithTabSheet(LITH2 *Lith2)
{
   Lith2->H1SpeedButton = NULL;
   Lith2->H2SpeedButton = NULL;
   Lith2->H3SpeedButton = NULL;
   Lith2->H4SpeedButton = NULL;
   int index = TroelsSmithCodes->IndexOf(Lith2->LithCode);
   switch (index) {
     case 0:
       Lith2->TabSheet = ShTabSheet;
       Lith2->SpeedButton = SpeedButton34;
       break;
     case 1:
       Lith2->TabSheet = ShTabSheet;
       Lith2->SpeedButton = SpeedButton35;
       break;
     case 2:
       Lith2->TabSheet = ShTabSheet;
       Lith2->SpeedButton = SpeedButton36;
       break;
     case 3:
       Lith2->TabSheet = ShTabSheet;
       Lith2->SpeedButton = SpeedButton37;
       break;
     case 4:
       Lith2->TabSheet = TbTabSheet;
       Lith2->SpeedButton = SpeedButton38;
       Lith2->H1SpeedButton = TbH1SpeedButton;
       Lith2->H2SpeedButton = TbH2SpeedButton;
       Lith2->H3SpeedButton = TbH3SpeedButton;
       Lith2->H4SpeedButton = TbH4SpeedButton;
       break;
     case 5:
       Lith2->TabSheet = TbTabSheet;
       Lith2->SpeedButton = SpeedButton39;
       Lith2->H1SpeedButton = TbH1SpeedButton;
       Lith2->H2SpeedButton = TbH2SpeedButton;
       Lith2->H3SpeedButton = TbH3SpeedButton;
       Lith2->H4SpeedButton = TbH4SpeedButton;
       break;
     case 6:
       Lith2->TabSheet = TbTabSheet;
       Lith2->SpeedButton = SpeedButton40;
       Lith2->H1SpeedButton = TbH1SpeedButton;
       Lith2->H2SpeedButton = TbH2SpeedButton;
       Lith2->H3SpeedButton = TbH3SpeedButton;
       Lith2->H4SpeedButton = TbH4SpeedButton;
       break;
     case 7:
       Lith2->TabSheet = TbTabSheet;
       Lith2->SpeedButton = SpeedButton41;
       Lith2->H1SpeedButton = TbH1SpeedButton;
       Lith2->H2SpeedButton = TbH2SpeedButton;
       Lith2->H3SpeedButton = TbH3SpeedButton;
       Lith2->H4SpeedButton = TbH4SpeedButton;
       break;
     case 8:
       Lith2->TabSheet = TbSTabSheet;
       Lith2->SpeedButton = SpeedButton42;
       Lith2->H1SpeedButton = TbSH1SpeedButton;
       Lith2->H2SpeedButton = TbSH2SpeedButton;
       Lith2->H3SpeedButton = TbSH3SpeedButton;
       Lith2->H4SpeedButton = TbSH4SpeedButton;
       break;
     case 9:
       Lith2->TabSheet = TbSTabSheet;
       Lith2->SpeedButton = SpeedButton43;
       Lith2->H1SpeedButton = TbSH1SpeedButton;
       Lith2->H2SpeedButton = TbSH2SpeedButton;
       Lith2->H3SpeedButton = TbSH3SpeedButton;
       Lith2->H4SpeedButton = TbSH4SpeedButton;
       break;
     case 10:
       Lith2->TabSheet = TbSTabSheet;
       Lith2->SpeedButton = SpeedButton44;
       Lith2->H1SpeedButton = TbSH1SpeedButton;
       Lith2->H2SpeedButton = TbSH2SpeedButton;
       Lith2->H3SpeedButton = TbSH3SpeedButton;
       Lith2->H4SpeedButton = TbSH4SpeedButton;
       break;
     case 11:
       Lith2->TabSheet = TbSTabSheet;
       Lith2->SpeedButton = SpeedButton45;
       Lith2->H1SpeedButton = TbSH1SpeedButton;
       Lith2->H2SpeedButton = TbSH2SpeedButton;
       Lith2->H3SpeedButton = TbSH3SpeedButton;
       Lith2->H4SpeedButton = TbSH4SpeedButton;
       break;
     case 12:
       Lith2->TabSheet = TbScTabSheet;
       Lith2->SpeedButton = SpeedButton46;
       Lith2->H1SpeedButton = TbScH1SpeedButton;
       Lith2->H2SpeedButton = TbScH2SpeedButton;
       Lith2->H3SpeedButton = TbScH3SpeedButton;
       Lith2->H4SpeedButton = TbScH4SpeedButton;
       break;
     case 13:
       Lith2->TabSheet = TbScTabSheet;
       Lith2->SpeedButton = SpeedButton47;
       Lith2->H1SpeedButton = TbScH1SpeedButton;
       Lith2->H2SpeedButton = TbScH2SpeedButton;
       Lith2->H3SpeedButton = TbScH3SpeedButton;
       Lith2->H4SpeedButton = TbScH4SpeedButton;
       break;
     case 14:
       Lith2->TabSheet = TbScTabSheet;
       Lith2->SpeedButton = SpeedButton48;
       Lith2->H1SpeedButton = TbScH1SpeedButton;
       Lith2->H2SpeedButton = TbScH2SpeedButton;
       Lith2->H3SpeedButton = TbScH3SpeedButton;
       Lith2->H4SpeedButton = TbScH4SpeedButton;
       break;
     case 15:
       Lith2->TabSheet = TbScTabSheet;
       Lith2->SpeedButton = SpeedButton49;
       Lith2->H1SpeedButton = TbScH1SpeedButton;
       Lith2->H2SpeedButton = TbScH2SpeedButton;
       Lith2->H3SpeedButton = TbScH3SpeedButton;
       Lith2->H4SpeedButton = TbScH4SpeedButton;
       break;
     case 16:
       Lith2->TabSheet = TlTabSheet;
       Lith2->SpeedButton = SpeedButton50;
       Lith2->H1SpeedButton = TlH1SpeedButton;
       Lith2->H2SpeedButton = TlH2SpeedButton;
       Lith2->H3SpeedButton = TlH3SpeedButton;
       Lith2->H4SpeedButton = TlH4SpeedButton;
       break;
     case 17:
       Lith2->TabSheet = TlTabSheet;
       Lith2->SpeedButton = SpeedButton51;
       Lith2->H1SpeedButton = TlH1SpeedButton;
       Lith2->H2SpeedButton = TlH2SpeedButton;
       Lith2->H3SpeedButton = TlH3SpeedButton;
       Lith2->H4SpeedButton = TlH4SpeedButton;
       break;
     case 18:
       Lith2->TabSheet = TlTabSheet;
       Lith2->SpeedButton = SpeedButton52;
       Lith2->H1SpeedButton = TlH1SpeedButton;
       Lith2->H2SpeedButton = TlH2SpeedButton;
       Lith2->H3SpeedButton = TlH3SpeedButton;
       Lith2->H4SpeedButton = TlH4SpeedButton;
       break;
     case 19:
       Lith2->TabSheet = TlTabSheet;
       Lith2->SpeedButton = SpeedButton53;
       Lith2->H1SpeedButton = TlH1SpeedButton;
       Lith2->H2SpeedButton = TlH2SpeedButton;
       Lith2->H3SpeedButton = TlH3SpeedButton;
       Lith2->H4SpeedButton = TlH4SpeedButton;
       break;
     case 20:
       Lith2->TabSheet = ThTabSheet;
       Lith2->SpeedButton = SpeedButton54;
       Lith2->H1SpeedButton = ThH1SpeedButton;
       Lith2->H2SpeedButton = ThH2SpeedButton;
       Lith2->H3SpeedButton = ThH3SpeedButton;
       break;
     case 21:
       Lith2->TabSheet = ThTabSheet;
       Lith2->SpeedButton = SpeedButton55;
       Lith2->H1SpeedButton = ThH1SpeedButton;
       Lith2->H2SpeedButton = ThH2SpeedButton;
       Lith2->H3SpeedButton = ThH3SpeedButton;
       break;
     case 22:
       Lith2->TabSheet = ThTabSheet;
       Lith2->SpeedButton = SpeedButton56;
       Lith2->H1SpeedButton = ThH1SpeedButton;
       Lith2->H2SpeedButton = ThH2SpeedButton;
       Lith2->H3SpeedButton = ThH3SpeedButton;
       break;
     case 23:
       Lith2->TabSheet = ThTabSheet;
       Lith2->SpeedButton = SpeedButton57;
       Lith2->H1SpeedButton = ThH1SpeedButton;
       Lith2->H2SpeedButton = ThH2SpeedButton;
       Lith2->H3SpeedButton = ThH3SpeedButton;
       break;
     case 24:
       Lith2->TabSheet = ThhTabSheet;
       Lith2->SpeedButton = SpeedButton58;
       break;
     case 25:
       Lith2->TabSheet = ThhTabSheet;
       Lith2->SpeedButton = SpeedButton59;
       break;
     case 26:
       Lith2->TabSheet = ThhTabSheet;
       Lith2->SpeedButton = SpeedButton60;
       break;
     case 27:
       Lith2->TabSheet = ThhTabSheet;
       Lith2->SpeedButton = SpeedButton61;
       break;
     case 28:
       Lith2->TabSheet = DlTabSheet;
       Lith2->SpeedButton = SpeedButton62;
       break;
     case 29:
       Lith2->TabSheet = DlTabSheet;
       Lith2->SpeedButton = SpeedButton63;
       break;
     case 30:
       Lith2->TabSheet = DlTabSheet;
       Lith2->SpeedButton = SpeedButton64;
       break;
     case 31:
       Lith2->TabSheet = DlTabSheet;
       Lith2->SpeedButton = SpeedButton65;
       break;
     case 32:
       Lith2->TabSheet = DhTabSheet;
       Lith2->SpeedButton = SpeedButton66;
       break;
     case 33:
       Lith2->TabSheet = DhTabSheet;
       Lith2->SpeedButton = SpeedButton67;
       break;
     case 34:
       Lith2->TabSheet = DhTabSheet;
       Lith2->SpeedButton = SpeedButton68;
       break;
     case 35:
       Lith2->TabSheet = DhTabSheet;
       Lith2->SpeedButton = SpeedButton69;
       break;
     case 36:
       Lith2->TabSheet = DgTabSheet;
       Lith2->SpeedButton = SpeedButton70;
       break;
     case 37:
       Lith2->TabSheet = DgTabSheet;
       Lith2->SpeedButton = SpeedButton71;
       break;
     case 38:
       Lith2->TabSheet = DgTabSheet;
       Lith2->SpeedButton = SpeedButton72;
       break;
     case 39:
       Lith2->TabSheet = DgTabSheet;
       Lith2->SpeedButton = SpeedButton73;
       break;
     case 40:
       Lith2->TabSheet = LdTabSheet;
       Lith2->SpeedButton = SpeedButton74;
       Lith2->H1SpeedButton = LdH1SpeedButton;
       Lith2->H2SpeedButton = LdH2SpeedButton;
       Lith2->H3SpeedButton = LdH3SpeedButton;
       Lith2->H4SpeedButton = LdH4SpeedButton;
       break;
     case 41:
       Lith2->TabSheet = LdTabSheet;
       Lith2->SpeedButton = SpeedButton75;
       Lith2->H1SpeedButton = LdH1SpeedButton;
       Lith2->H2SpeedButton = LdH2SpeedButton;
       Lith2->H3SpeedButton = LdH3SpeedButton;
       Lith2->H4SpeedButton = LdH4SpeedButton;
       break;
     case 42:
       Lith2->TabSheet = LdTabSheet;
       Lith2->SpeedButton = SpeedButton76;
       Lith2->H1SpeedButton = LdH1SpeedButton;
       Lith2->H2SpeedButton = LdH2SpeedButton;
       Lith2->H3SpeedButton = LdH3SpeedButton;
       Lith2->H4SpeedButton = LdH4SpeedButton;
       break;
     case 43:
       Lith2->TabSheet = LdTabSheet;
       Lith2->SpeedButton = SpeedButton77;
       Lith2->H1SpeedButton = LdH1SpeedButton;
       Lith2->H2SpeedButton = LdH2SpeedButton;
       Lith2->H3SpeedButton = LdH3SpeedButton;
       Lith2->H4SpeedButton = LdH4SpeedButton;
       break;
     case 44:
       Lith2->TabSheet = LsoTabSheet;
       Lith2->SpeedButton = SpeedButton78;
       break;
     case 45:
       Lith2->TabSheet = LsoTabSheet;
       Lith2->SpeedButton = SpeedButton79;
       break;
     case 46:
       Lith2->TabSheet = LsoTabSheet;
       Lith2->SpeedButton = SpeedButton80;
       break;
     case 47:
       Lith2->TabSheet = LsoTabSheet;
       Lith2->SpeedButton = SpeedButton81;
       break;
     case 48:
       Lith2->TabSheet = LcTabSheet;
       Lith2->SpeedButton = SpeedButton82;
       break;
     case 49:
       Lith2->TabSheet = LcTabSheet;
       Lith2->SpeedButton = SpeedButton83;
       break;
     case 50:
       Lith2->TabSheet = LcTabSheet;
       Lith2->SpeedButton = SpeedButton84;
       break;
     case 51:
       Lith2->TabSheet = LcTabSheet;
       Lith2->SpeedButton = SpeedButton85;
       break;
     case 52:
       Lith2->TabSheet = LfTabSheet;
       Lith2->SpeedButton = SpeedButton86;
       break;
     case 53:
       Lith2->TabSheet = LfTabSheet;
       Lith2->SpeedButton = SpeedButton87;
       break;
     case 54:
       Lith2->TabSheet = LfTabSheet;
       Lith2->SpeedButton = SpeedButton88;
       break;
     case 55:
       Lith2->TabSheet = LfTabSheet;
       Lith2->SpeedButton = SpeedButton89;
       break;
     case 56:
       Lith2->TabSheet = AsTabSheet;
       Lith2->SpeedButton = SpeedButton90;
       break;
     case 57:
       Lith2->TabSheet = AsTabSheet;
       Lith2->SpeedButton = SpeedButton91;
       break;
     case 58:
       Lith2->TabSheet = AsTabSheet;
       Lith2->SpeedButton = SpeedButton92;
       break;
     case 59:
       Lith2->TabSheet = AsTabSheet;
       Lith2->SpeedButton = SpeedButton93;
       break;
     case 60:
       Lith2->TabSheet = AgTabSheet;
       Lith2->SpeedButton = SpeedButton94;
       break;
     case 61:
       Lith2->TabSheet = AgTabSheet;
       Lith2->SpeedButton = SpeedButton95;
       break;
     case 62:
       Lith2->TabSheet = AgTabSheet;
       Lith2->SpeedButton = SpeedButton96;
       break;
     case 63:
       Lith2->TabSheet = AgTabSheet;
       Lith2->SpeedButton = SpeedButton97;
       break;
     case 64:
       Lith2->TabSheet = GaTabSheet;
       Lith2->SpeedButton = SpeedButton98;
       break;
     case 65:
       Lith2->TabSheet = GaTabSheet;
       Lith2->SpeedButton = SpeedButton99;
       break;
     case 66:
       Lith2->TabSheet = GaTabSheet;
       Lith2->SpeedButton = SpeedButton100;
       break;
     case 67:
       Lith2->TabSheet = GaTabSheet;
       Lith2->SpeedButton = SpeedButton101;
       break;
     case 68:
       Lith2->TabSheet = GsTabSheet;
       Lith2->SpeedButton = SpeedButton102;
       break;
     case 69:
       Lith2->TabSheet = GsTabSheet;
       Lith2->SpeedButton = SpeedButton103;
       break;
     case 70:
       Lith2->TabSheet = GsTabSheet;
       Lith2->SpeedButton = SpeedButton104;
       break;
     case 71:
       Lith2->TabSheet = GsTabSheet;
       Lith2->SpeedButton = SpeedButton105;
       break;
     case 72:
       Lith2->TabSheet = GgminTabSheet;
       Lith2->SpeedButton = SpeedButton106;
       break;
     case 73:
       Lith2->TabSheet = GgminTabSheet;
       Lith2->SpeedButton = SpeedButton107;
       break;
     case 74:
       Lith2->TabSheet = GgminTabSheet;
       Lith2->SpeedButton = SpeedButton108;
       break;
     case 75:
       Lith2->TabSheet = GgminTabSheet;
       Lith2->SpeedButton = SpeedButton109;
       break;
     case 76:
       Lith2->TabSheet = GgmajTabSheet;
       Lith2->SpeedButton = SpeedButton110;
       break;
     case 77:
       Lith2->TabSheet = GgmajTabSheet;
       Lith2->SpeedButton = SpeedButton111;
       break;
     case 78:
       Lith2->TabSheet = GgmajTabSheet;
       Lith2->SpeedButton = SpeedButton112;
       break;
     case 79:
       Lith2->TabSheet = GgmajTabSheet;
       Lith2->SpeedButton = SpeedButton113;
       break;
     case 80:
       Lith2->TabSheet = TestTabSheet;
       Lith2->SpeedButton = SpeedButton114;
       break;
     case 81:
       Lith2->TabSheet = TestTabSheet;
       Lith2->SpeedButton = SpeedButton115;
       break;
     case 82:
       Lith2->TabSheet = TestTabSheet;
       Lith2->SpeedButton = SpeedButton116;
       break;
     case 83:
       Lith2->TabSheet = TestTabSheet;
       Lith2->SpeedButton = SpeedButton117;
       break;
     case 84:
       Lith2->TabSheet = PartTestTabSheet;
       Lith2->SpeedButton = SpeedButton118;
       break;
     case 85:
       Lith2->TabSheet = PartTestTabSheet;
       Lith2->SpeedButton = SpeedButton119;
       break;
     case 86:
       Lith2->TabSheet = PartTestTabSheet;
       Lith2->SpeedButton = SpeedButton120;
       break;
     case 87:
       Lith2->TabSheet = PartTestTabSheet;
       Lith2->SpeedButton = SpeedButton121;
       break;
     case 88:
       Lith2->TabSheet = CortSecTabSheet;
       Lith2->SpeedButton = SpeedButton122;
       break;
     case 89:
       Lith2->TabSheet = CortSecTabSheet;
       Lith2->SpeedButton = SpeedButton123;
       break;
     case 90:
       Lith2->TabSheet = CortSecTabSheet;
       Lith2->SpeedButton = SpeedButton124;
       break;
     case 91:
       Lith2->TabSheet = CortSecTabSheet;
       Lith2->SpeedButton = SpeedButton125;
       break;
     case 92:
       Lith2->TabSheet = CortTabSheet;
       Lith2->SpeedButton = SpeedButton126;
       break;
     case 93:
       Lith2->TabSheet = CortTabSheet;
       Lith2->SpeedButton = SpeedButton127;
       break;
     case 94:
       Lith2->TabSheet = CortTabSheet;
       Lith2->SpeedButton = SpeedButton128;
       break;
     case 95:
       Lith2->TabSheet = CortTabSheet;
       Lith2->SpeedButton = SpeedButton129;
       break;
     default:
       Lith2->TabSheet = NULL;
       Lith2->SpeedButton = NULL;
       break;
     }

  // ADD HERE
}
//---------------------------------------------------------------------------

// this function called when a Troels-Smith speedbutton is pressed
void TLithForm::SetTroelsSmith(int code, UnicodeString Group,
    TSpeedButton* SpeedButton, TSpeedButton* HumoSpeedButton)
{
   LITH1 *Lith1;

   TcxCustomGridRecord *AFocusedRecord =
      LithGridTableView1->Controller->FocusedRecord;

   if (AFocusedRecord->RecordIndex == -1)
     Lith1 = LithDataSource->TempLith1;
   else
     Lith1 = (LITH1*)LithList->Liths[AFocusedRecord->RecordIndex];

   UnicodeString LithCode = TroelsSmithCodes->Strings[code-34];
   LITH2 *Lith2;

   // check if member of Group already occurs
   int LithNo = -1;
   for (int i=0; i<Lith1->Components->Count; i++) {
     Lith2 = (LITH2*)Lith1->Components->Items[i];
     if (Group.Length() == Lith2->LithCode.Length()-1) {
       if (Group == Lith2->LithCode.SubString(1, Group.Length())) {
         LithNo = i;
         break; }
       }
     }

   // first check if button is being deselected, if so delete selection
   if (SpeedButton->Down == false) {
     if (LithNo > -1) {
       Lith1->Components->Delete(LithNo);
       delete Lith2;
       LithComponentSource->DataChanged();
       LithGridTableView2->DataController->Post();
       if (Lith1->Components->Count > 0)
		 DrawTroelsSmith(Lith1);
       else
         ClearBitmap();
       if (HumoSpeedButton) {
         HumoSpeedButton->Down = true;
         HumoSpeedButton->Down = false;
         }
       ColorBox1->Enabled = false;
       ColorBox1->Selected = Diag->lopt.DefaultColor;
       return;
       }
     }

   // next check if a Bitmap selection has been made
   if (Lith1->Components->Count == 1) {
     Lith2 = (LITH2*)Lith1->Components->Items[0];
     if (Lith2->LithCode.SubString(1,6) == "Bitmap") {
       UnicodeString Msg = "Replace " + Lith2->LithCode +
                        " with Troels-Smith pattern " + LithCode + "?";
	   if (MessageDlg(Msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes) {
		 Graphics::TBitmap *bmp = LTHBitmaps[0];
		 delete bmp;
		 bmp = new Graphics::TBitmap;
		 bmp->Width = 120;
		 bmp->Height = 160;
		 bmp->PixelFormat = pf24bit;

		 Lith2->LithCode = LithCode;
         //Lith2->SpeedButton = SpeedButton;
         SetTroelsSmithTabSheet(Lith2);
         LithComponentSource->DataChanged();
         LithGridTableView2->DataController->Post();
         DrawTroelsSmith(Lith1);
         ColorBox1->Selected = Lith2->Color;
         ColorBox1->Enabled = true;
         }
       else
         SpeedButton->Down = false;
       return;
       }
     }

   // next check if member of group already occurs, if so replace
   if (LithNo > -1) {
     Lith2->LithCode = LithCode;
     Lith2->Humo = 0;
     Lith2->XShift = 0;
     Lith2->YShift = 0;
     Lith2->SpeedButton = SpeedButton;
     if (HumoSpeedButton) {
       HumoSpeedButton->Down = true;
       HumoSpeedButton->Down = false;
       }
     SetTroelsSmithTabSheet(Lith2);
     LithComponentSource->DataChanged();
     LithGridTableView2->DataController->Post();
     DrawTroelsSmith(Lith1);
     return;
     }

   // next check if 4 selections already exist, if so give warning message
   if (Lith1->Components->Count == 4) {
	 MessageDlg("A maximum of four patterns already selected.", Dialogs::mtError,
                TMsgDlgButtons() << mbOK, 0);
     SpeedButton->Down = false;
     return;
	 }

   // finally add new selection to list
   LithGridTableView2->OptionsData->Inserting = true;
   Lith2 = new LITH2;
   Lith2->LithCode = LithCode;
   SetTroelsSmithTabSheet(Lith2);
   Lith2->SpeedButton = SpeedButton;
   Lith1->Components->Add(Lith2);
   LithComponentSource->DataChanged();
   LithGridTableView2->DataController->Post();
   LithGridTableView2->OptionsData->Inserting = false;
   DrawTroelsSmith(Lith1);
   ColorBox1->Selected = Lith2->Color;
   ColorBox1->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::LithGridTableView1FocusedRecordChanged(
      TcxCustomGridTableView *Sender,
      TcxCustomGridRecord *APrevFocusedRecord,
      TcxCustomGridRecord *AFocusedRecord,
      bool ANewItemRecordFocusingChanged)
{
   LITH1 *Lith1;

   // ClearBitmap();

   if (!AFocusedRecord) {
     ClearBitmap();
     DisableButtons();
     ColorBox1->Enabled = false;
     ColorBox1->Selected = Diag->lopt.DefaultColor;
     ColorBox2->Enabled = false;
     ColorBox2->Selected = Diag->lopt.DefaultColor;
     }
   else if (AFocusedRecord->Index > -1) {
	 EnableButtons();
	 ColorBox1->Enabled = true;
     ColorBox2->Enabled = true;
     }
   else
     ClearBitmap();


   if (!APrevFocusedRecord) {
     if (AFocusedRecord) {

       if (AFocusedRecord->RecordIndex == -1)
         Lith1 = LithDataSource->TempLith1;
       else
         Lith1 = (LITH1*)LithList->Liths[AFocusedRecord->RecordIndex];

       ColorBox2->Enabled = true;
       ColorBox2->Selected = Lith1->LoBoundColor;
       if (Lith1->Components->Count > 0) {
         LITH2 *Lith2 = (LITH2*)Lith1->Components->Items[0];
         if (Lith2->LithCode.SubString(1,6) == "Bitmap")
           DepressBitmapButton(Lith2);
         else
           DepressTroelsSmithButtons(0, Lith1);
         ColorBox1->Enabled = true;
         ColorBox1->Selected = Lith2->Color;
         }
       }
     }
   else if (AFocusedRecord) {
     if (AFocusedRecord->RecordIndex == -1)
       Lith1 = LithDataSource->TempLith1;
     else
       Lith1 = (LITH1*)LithList->Liths[AFocusedRecord->RecordIndex];

     ColorBox2->Enabled = true;
     ColorBox2->Selected = Lith1->LoBoundColor;
     if (APrevFocusedRecord->RecordIndex != AFocusedRecord->RecordIndex) {
       // new record
       if (Lith1->Components->Count == 0) {
         ClearBitmap();
         ColorBox1->Enabled = false;
         ColorBox1->Selected = Diag->lopt.DefaultColor;
         }
       else {  // a lith component has been selected
         LITH2 *Lith2 = (LITH2*)Lith1->Components->Items[0];
         if (Lith2->LithCode.SubString(1,6) == "Bitmap")
           DepressBitmapButton(Lith2);
         else {
           LITH1* pLith1 = (LITH1*)LithDataSource->LithList->Liths[APrevFocusedRecord->RecordIndex];
           DepressTroelsSmithButtons(pLith1, Lith1);
           }
         ColorBox1->Enabled = true;
         ColorBox1->Selected = Lith2->Color;
         }
       }
     }
   else {
     ColorBox2->Enabled = false;
     ColorBox2->Selected = Diag->lopt.DefaultColor;
     }
   RedrawExample();
}
//---------------------------------------------------------------------------

LITH2* TLithForm::GetCurrentLith2(LITH1* Lith1)
{
   LITH2* L2;
   LITH2* Lith2 = NULL;
   for (int i=0; i<Lith1->Components->Count; i++) {
     L2 = (LITH2*)Lith1->Components->Items[i];
     if (L2->TabSheet == PageControl1->ActivePage) {
       Lith2 = L2;
       break;
       }
     }
   return Lith2;
}
//---------------------------------------------------------------------------

// Y-shift up
void __fastcall TLithForm::BitBtn1Click(TObject *Sender)
{
   TcxCustomGridRecord *AFocusedRecord =
      LithGridTableView1->Controller->FocusedRecord;

   LITH1 *Lith1;
   if (AFocusedRecord->RecordIndex == -1)
     Lith1 = LithDataSource->TempLith1;
   else
     Lith1 = (LITH1*)LithList->Liths[AFocusedRecord->RecordIndex];

   if (Lith1->Components->Count == 0) {
     MessageBeep(MB_ICONEXCLAMATION);
     return;
     }

   LITH2* Lith2 = GetCurrentLith2(Lith1);
   if (Lith2) {
     int index = TroelsSmithCodes->IndexOf(Lith2->LithCode);
     Lith2->YShift += 0.01;
     if (fabs(Lith2->YShift) < 0.001)
       Lith2->YShift = 0.0;
     if (nint(100.0*Lith2->YShift) >= MaxYShift[index])
       Lith2->YShift = 0.0;
     LithComponentSource->DataChanged();
     LithGridTableView2->DataController->Post();
     DrawTroelsSmith(Lith1);
     }
}
//---------------------------------------------------------------------------

// Y-shift down
void __fastcall TLithForm::BitBtn2Click(TObject *Sender)
{
   TcxCustomGridRecord *AFocusedRecord =
      LithGridTableView1->Controller->FocusedRecord;

   LITH1 *Lith1;
   if (AFocusedRecord->RecordIndex == -1)
     Lith1 = LithDataSource->TempLith1;
   else
     Lith1 = (LITH1*)LithList->Liths[AFocusedRecord->RecordIndex];

   if (Lith1->Components->Count == 0) {
     MessageBeep(MB_ICONEXCLAMATION);
     return;
     }

   LITH2* Lith2 = GetCurrentLith2(Lith1);
   if (Lith2) {
     int index = TroelsSmithCodes->IndexOf(Lith2->LithCode);
     Lith2->YShift -= 0.01;
     if (fabs(Lith2->YShift) < 0.001)
       Lith2->YShift = 0.0;
     if (nint(100.0*Lith2->YShift) <= -MaxYShift[index])
       Lith2->YShift = 0.0;
     LithComponentSource->DataChanged();
     LithGridTableView2->DataController->Post();
     DrawTroelsSmith(Lith1);
     }
}
//---------------------------------------------------------------------------

// X-shift left
void __fastcall TLithForm::BitBtn3Click(TObject *Sender)
{
   TcxCustomGridRecord *AFocusedRecord =
      LithGridTableView1->Controller->FocusedRecord;

   LITH1 *Lith1;
   if (AFocusedRecord->RecordIndex == -1)
     Lith1 = LithDataSource->TempLith1;
   else
     Lith1 = (LITH1*)LithList->Liths[AFocusedRecord->RecordIndex];

   if (Lith1->Components->Count == 0) {
     MessageBeep(MB_ICONEXCLAMATION);
     return;
     }

   LITH2* Lith2 = GetCurrentLith2(Lith1);
   if (Lith2) {
     int index = TroelsSmithCodes->IndexOf(Lith2->LithCode);
     Lith2->XShift -= 0.01;
     if (fabs(Lith2->XShift) < 0.001)
       Lith2->XShift = 0.0;
     if (nint(100.0*Lith2->XShift) <= -MaxXShift[index])
       Lith2->XShift = 0.0;
     LithComponentSource->DataChanged();
     LithGridTableView2->DataController->Post();
     DrawTroelsSmith(Lith1);
     }
}
//---------------------------------------------------------------------------

// X-shift right
void __fastcall TLithForm::BitBtn4Click(TObject *Sender)
{
   TcxCustomGridRecord *AFocusedRecord =
      LithGridTableView1->Controller->FocusedRecord;

   LITH1 *Lith1;
   if (AFocusedRecord->RecordIndex == -1)
     Lith1 = LithDataSource->TempLith1;
   else
     Lith1 = (LITH1*)LithList->Liths[AFocusedRecord->RecordIndex];

   if (Lith1->Components->Count == 0) {
     MessageBeep(MB_ICONEXCLAMATION);
     return;
     }

   LITH2* Lith2 = GetCurrentLith2(Lith1);
   if (Lith2) {
     int index = TroelsSmithCodes->IndexOf(Lith2->LithCode);
     Lith2->XShift += 0.01;
     if (fabs(Lith2->XShift) < 0.001)
       Lith2->XShift = 0.0;
     if (nint(100.0*Lith2->XShift) >= MaxXShift[index])
       Lith2->XShift = 0.0;
     LithComponentSource->DataChanged();
     LithGridTableView2->DataController->Post();
     DrawTroelsSmith(Lith1);
     }
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::BitBtn5Click(TObject *Sender)
{
   TcxCustomGridRecord *AFocusedRecord =
      LithGridTableView1->Controller->FocusedRecord;

   LITH1 *Lith1;
   if (AFocusedRecord->RecordIndex == -1)
     Lith1 = LithDataSource->TempLith1;
   else
     Lith1 = (LITH1*)LithList->Liths[AFocusedRecord->RecordIndex];

   if (Lith1->Components->Count == 0) {
     MessageBeep(MB_ICONEXCLAMATION);
     return;
     }

   LITH2* Lith2 = GetCurrentLith2(Lith1);
   if (Lith2) {
     Lith2->XShift = 0.0;
     Lith2->YShift = 0.0;
     LithComponentSource->DataChanged();
     LithGridTableView2->DataController->Post();
     DrawTroelsSmith(Lith1);
     }
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::LithGridTableView2KeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
   if (Key == VK_DOWN) {
     TcxCustomGridRecord *AFocusedRecord =
       LithGridTableView1->Controller->FocusedRecord;
     if (LithDataSource->LithList->Count == (AFocusedRecord->RecordIndex + 1))
       {
         Key = 0;
         MessageBeep(MB_ICONASTERISK);
       }
     }
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::ColorBox1Change(TObject *Sender)
{
   TcxCustomGridRecord *AFocusedRecord =
      LithGridTableView1->Controller->FocusedRecord;

   LITH1 *Lith1;
   if (AFocusedRecord->RecordIndex == -1){
     if (LithDataSource->TempLith1)
       Lith1 = LithDataSource->TempLith1;
     else
       return;
     }
   else
     Lith1 = (LITH1*)LithList->Liths[AFocusedRecord->RecordIndex];

   if (Lith1->Components->Count) {
     LITH2* Lith2 = GetCurrentLith2(Lith1);
     if (Lith2) {
       Lith2->Color = ColorBox1->Selected;
       if (Lith2->LithCode.SubString(1,6) == "Bitmap") {
         int code = (Lith2->LithCode.SubString(7,2)).ToInt();
         DrawBitmap(code, Lith2->Color);
         }
       else
         DrawTroelsSmith(Lith1);
       if (Lith2->TabSheet)
         PageControl1->ActivePage = Lith2->TabSheet;
       }
     }
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::ColorBox2Change(TObject *Sender)
{
   TcxCustomGridRecord *AFocusedRecord =
      LithGridTableView1->Controller->FocusedRecord;

   LITH1 *Lith1;
   if (AFocusedRecord->RecordIndex == -1) {
     if (LithDataSource->TempLith1)
       Lith1 = LithDataSource->TempLith1;
     else
       return;  
     }
   else
     Lith1 = (LITH1*)LithList->Liths[AFocusedRecord->RecordIndex];

   Lith1->LoBoundColor = ColorBox2->Selected;
   if (Lith1->LoBound) {
     if (Lith1->Components->Count) {
       LITH2* Lith2 = (LITH2*)Lith1->Components->Items[0];
       if (Lith2->LithCode.SubString(1,6) == "Bitmap") {
         int code = (Lith2->LithCode.SubString(7,2)).ToInt();
         DrawBitmap(code, Lith2->Color);
         }
       else
         DrawTroelsSmith(Lith1);
       }
     else {
       ClearBitmap();
       if (Lith1->LoBound)
         DrawLowerBound();
       }
     }
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::lgLoBoundPropertiesEditValueChanged(
      TObject *Sender)
{
   if (LithGridTableView1->Controller->FocusedRecord->RecordIndex != -1) {
     LithGridTableView1->DataController->Post();
     LithDataSource->DataChanged();
     }
   else
     LithDataSource->TempLith1->LoBound = ((TcxCheckBox*)Sender)->Checked;
   RedrawExample();
}
//---------------------------------------------------------------------------

// OK button
void __fastcall TLithForm::Button1Click(TObject *Sender)
{
   int code;

   Diag->Modified = true;
   // delete old lithology
   if (Diag->Lithology->Count > 0) {
     for (int i=0; i<Diag->Lithology->Count; i++) {
       LITHUNIT* LithUnit = (LITHUNIT*)Diag->Lithology->Items[i];
       delete LithUnit;
       Diag->Lithology->Items[i] = 0;
       }
     Diag->Lithology->Clear();
     Diag->Lithology->Capacity = 100;
     }

   // lithology options
   Diag->lopt.On = CheckBox1->Checked;
   Diag->lopt.KeyOn = CheckBox2->Checked;

   // add new lithunits
   if (LithList->Count) {
     for (int i=0; i<LithList->Count; i++) {
       LITH1* Lith1 = (LITH1*)LithList->Liths[i];
       if (IsNan(Lith1->Top) || IsNan(Lith1->Bot)) continue;
       LITHUNIT* LithUnit = new LITHUNIT((TColor)Diag->lopt.DefaultColor);
       LithUnit->Top = Lith1->Top;
       LithUnit->Bot = Lith1->Bot;
       LithUnit->LoBound = Lith1->LoBound;
       LithUnit->LoBoundColor = Lith1->LoBoundColor;
       for (int j=0; j<Lith1->Components->Count; j++) {
         LITH2* Lith2 = (LITH2*)Lith1->Components->Items[j];
         LITHCOMPONENT* Component = new LITHCOMPONENT;
         if (Lith2->LithCode.SubString(1,6) == "Bitmap")
           code = (Lith2->LithCode.SubString(7,2)).ToInt();
         else
           code = TroelsSmithCodes->IndexOf(Lith2->LithCode) + 34;
         Component->LithCode = (short)code;
         Component->Humo = Lith2->Humo;
         Component->XShift = Lith2->XShift;
         Component->YShift = Lith2->YShift;
         Component->Color = Lith2->Color;
         LithUnit->Components->Add(Component);
         }
       Diag->Lithology->Add(LithUnit);
       }
     Diag->lopt.On = true;
     }
   else {
     Diag->lopt.On = false;
     Diag->lopt.KeyOn = false;
     }

   // Delete old lithkeys
   if (Diag->LithKeys->Count > 0) {
     for (int i=0; i<Diag->LithKeys->Count; i++) {
       LITHKEY* LithKey = (LITHKEY*)Diag->LithKeys->Items[i];
       delete LithKey;
       Diag->LithKeys->Items[i] = 0;
       }
     Diag->LithKeys->Clear();
     Diag->LithKeys->Capacity = 100;
     }

   for (int i=0; i<LithKeyList->Count; i++) {
     LITHKEY *lk = LithKeyList->LithKeys[i];
     LITHKEY *LithKey = new LITHKEY(lk);
     Diag->LithKeys->Add(LithKey);
     }

   // lithology options
   UnicodeString Text = LabeledEdit1->Text.UpperCase();
   if (Text == "AUTO")
     Diag->lopt.AutoTopDepth = true;
   else {
     try {
       Diag->lopt.TopDepth = StrToFloat(LabeledEdit1->Text);
       Diag->lopt.AutoTopDepth = false;  }
     catch(Exception &e) {
	   MessageDlg("Error in Top Column Depth: " + e.Message, Dialogs::mtError,
                  TMsgDlgButtons() << mbOK, 0);
       Diag->lopt.AutoTopDepth = true;
       }
     }

   Text = LabeledEdit2->Text.UpperCase();
   if (Text == "AUTO")
     Diag->lopt.AutoBotDepth = true;
   else {
     try {
       Diag->lopt.BotDepth = StrToFloat(LabeledEdit2->Text);
       Diag->lopt.AutoBotDepth = false;  }
     catch(Exception &e) {
	   MessageDlg("Error in Bottom Column Depth: " + e.Message, Dialogs::mtError,
                  TMsgDlgButtons() << mbOK, 0);
       Diag->lopt.AutoBotDepth = true;
       }
     }

   Diag->lopt.LithTitle = LabeledEdit3->Text;
   Diag->lopt.LithTitleFont = LithTitleFont;

   Diag->lopt.Angle = StrToFloatDef(LabeledEdit4->Text, 0.0);

   Diag->lopt.LithLineWidth = PatLineWidthComboBox->GetLineWidth();
   Diag->lopt.ColumnLineWidth = ColLineWidthComboBox->GetLineWidth();
   Diag->lopt.BoundaryLineWidth = BndLineWidthComboBox->GetLineWidth();
   Diag->lopt.KeyLineWidth = KeyLineWidthComboBox->GetLineWidth();

   Diag->lopt.BoxWidth = StrToFloatDef(LabeledEdit5->Text, 1.2);
   Diag->lopt.KeyFont = KeyFont;

   Diag->lopt.DefaultColor = ColorBox3->Selected;
}
//---------------------------------------------------------------------------

void TLithForm::RedrawExample(void)
{
   TcxCustomGridRecord *AFocusedRecord =
        LithGridTableView1->Controller->FocusedRecord;

   LITH1 *Lith1;

   if (AFocusedRecord) {
     if (AFocusedRecord->RecordIndex == -1) {
       if (!LithDataSource->TempLith1)
         return;
       else
         Lith1 = LithDataSource->TempLith1;
       }
     else
       Lith1 = (LITH1*)LithList->Liths[AFocusedRecord->RecordIndex];

     if (Lith1->Components->Count) {
       LITH2* Lith2 = (LITH2*)Lith1->Components->Items[0];
       if (Lith2->LithCode.SubString(1,6) == "Bitmap") {
         int code = (Lith2->LithCode.SubString(7,2)).ToInt();
         DrawBitmap(code, Lith2->Color);
         }
       else
         DrawTroelsSmith(Lith1);
       if (Lith1->LoBound)
         DrawLowerBound();
       if (Lith2->TabSheet)
         PageControl1->ActivePage = Lith2->TabSheet;
       }
     else {
       ClearBitmap();
       if (Lith1->LoBound)
         DrawLowerBound();
       }
     }
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton1Click(TObject *Sender)
{
   SetBitmap(1, (TSpeedButton*)Sender);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton2Click(TObject *Sender)
{
   SetBitmap(2, (TSpeedButton*)Sender);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton3Click(TObject *Sender)
{
   SetBitmap(3, (TSpeedButton*)Sender);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton4Click(TObject *Sender)
{
   SetBitmap(4, (TSpeedButton*)Sender);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton5Click(TObject *Sender)
{
   SetBitmap(5, (TSpeedButton*)Sender);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton6Click(TObject *Sender)
{
   SetBitmap(6, (TSpeedButton*)Sender);     
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton7Click(TObject *Sender)
{
   SetBitmap(7, (TSpeedButton*)Sender);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton8Click(TObject *Sender)
{
   SetBitmap(8, (TSpeedButton*)Sender);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton9Click(TObject *Sender)
{
   SetBitmap(9, (TSpeedButton*)Sender);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton10Click(TObject *Sender)
{
   SetBitmap(10, (TSpeedButton*)Sender);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton11Click(TObject *Sender)
{
   SetBitmap(11, (TSpeedButton*)Sender);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton12Click(TObject *Sender)
{
   SetBitmap(12, (TSpeedButton*)Sender);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton13Click(TObject *Sender)
{
   SetBitmap(13, (TSpeedButton*)Sender);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton14Click(TObject *Sender)
{
   SetBitmap(14, (TSpeedButton*)Sender);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton15Click(TObject *Sender)
{
   SetBitmap(15, (TSpeedButton*)Sender);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton16Click(TObject *Sender)
{
   SetBitmap(16, (TSpeedButton*)Sender);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton17Click(TObject *Sender)
{
   SetBitmap(17, (TSpeedButton*)Sender);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton18Click(TObject *Sender)
{
   SetBitmap(18, (TSpeedButton*)Sender);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton19Click(TObject *Sender)
{
   SetBitmap(19, (TSpeedButton*)Sender);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton20Click(TObject *Sender)
{
   SetBitmap(20, (TSpeedButton*)Sender);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton21Click(TObject *Sender)
{
   SetBitmap(21, (TSpeedButton*)Sender);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton22Click(TObject *Sender)
{
   SetBitmap(22, (TSpeedButton*)Sender);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton23Click(TObject *Sender)
{
   SetBitmap(23, (TSpeedButton*)Sender);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton24Click(TObject *Sender)
{
   SetBitmap(24, (TSpeedButton*)Sender);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton25Click(TObject *Sender)
{
   SetBitmap(25, (TSpeedButton*)Sender);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton26Click(TObject *Sender)
{
   SetBitmap(26, (TSpeedButton*)Sender);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton27Click(TObject *Sender)
{
   SetBitmap(27, (TSpeedButton*)Sender);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton28Click(TObject *Sender)
{
   SetBitmap(28, (TSpeedButton*)Sender);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton29Click(TObject *Sender)
{
   SetBitmap(29, (TSpeedButton*)Sender);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton30Click(TObject *Sender)
{
   SetBitmap(30, (TSpeedButton*)Sender);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton31Click(TObject *Sender)
{
   SetBitmap(31, (TSpeedButton*)Sender);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton32Click(TObject *Sender)
{
   SetBitmap(32, (TSpeedButton*)Sender);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton33Click(TObject *Sender)
{
   SetBitmap(33, (TSpeedButton*)Sender);
}
//---------------------------------------------------------------------------

void TLithForm::SetHumoSpeedButton(short Humo, UnicodeString Group, TSpeedButton* HumoSpeedButton)
{
   TcxCustomGridRecord *AFocusedRecord =
      LithGridTableView1->Controller->FocusedRecord;

   LITH1 *Lith1;
   if (AFocusedRecord->RecordIndex == -1)
     Lith1 = LithDataSource->TempLith1;
   else
     Lith1 = (LITH1*)LithList->Liths[AFocusedRecord->RecordIndex];

   LITH2 *Lith2;

   int LithNo = -1;
   for (int i=0; i<Lith1->Components->Count; i++) {
     Lith2 = (LITH2*)Lith1->Components->Items[i];
     if (Group.Length() == Lith2->LithCode.Length()-1) {
       if (Group == Lith2->LithCode.SubString(1, Group.Length())) {
         LithNo = i;
         break; }
       }
     }

   if (LithNo < 0)
     HumoSpeedButton->Down = false;
   else if (HumoSpeedButton->Down) {
     Lith2->Humo = Humo;
     LithComponentSource->DataChanged();
     LithGridTableView2->DataController->Post();
     }
   else {
     Lith2->Humo = 0;
     LithComponentSource->DataChanged();
     LithGridTableView2->DataController->Post();
     }
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton34Click(TObject *Sender)
{
   SetTroelsSmith(34, "Sh", (TSpeedButton*)Sender, 0);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton35Click(TObject *Sender)
{
   SetTroelsSmith(35, "Sh", (TSpeedButton*)Sender, 0);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton36Click(TObject *Sender)
{
   SetTroelsSmith(36, "Sh", (TSpeedButton*)Sender, 0);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton37Click(TObject *Sender)
{
   SetTroelsSmith(37, "Sh", (TSpeedButton*)Sender, 0);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton38Click(TObject *Sender)
{
   SetTroelsSmith(38, "Tb", (TSpeedButton*)Sender, TbH1SpeedButton);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton39Click(TObject *Sender)
{
   SetTroelsSmith(39, "Tb", (TSpeedButton*)Sender, TbH1SpeedButton);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton40Click(TObject *Sender)
{
   SetTroelsSmith(40, "Tb", (TSpeedButton*)Sender, TbH1SpeedButton);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton41Click(TObject *Sender)
{
   SetTroelsSmith(41, "Tb", (TSpeedButton*)Sender, TbH1SpeedButton);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::TbH1SpeedButtonClick(TObject *Sender)
{
   SetHumoSpeedButton(1, "Tb", (TSpeedButton*)Sender);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::TbH2SpeedButtonClick(TObject *Sender)
{
   SetHumoSpeedButton(2, "Tb", (TSpeedButton*)Sender);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::TbH3SpeedButtonClick(TObject *Sender)
{
   SetHumoSpeedButton(3, "Tb", (TSpeedButton*)Sender);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::TbH4SpeedButtonClick(TObject *Sender)
{
   SetHumoSpeedButton(4, "Tb", (TSpeedButton*)Sender);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton42Click(TObject *Sender)
{
   SetTroelsSmith(42, "TbS", (TSpeedButton*)Sender, TbSH1SpeedButton);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton43Click(TObject *Sender)
{
   SetTroelsSmith(43, "TbS", (TSpeedButton*)Sender, TbSH1SpeedButton);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton44Click(TObject *Sender)
{
   SetTroelsSmith(44, "TbS", (TSpeedButton*)Sender, TbSH1SpeedButton);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton45Click(TObject *Sender)
{
   SetTroelsSmith(45, "TbS", (TSpeedButton*)Sender, TbSH1SpeedButton);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::TbSH1SpeedButtonClick(TObject *Sender)
{
   SetHumoSpeedButton(1, "TbS", (TSpeedButton*)Sender);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::TbSH2SpeedButtonClick(TObject *Sender)
{
   SetHumoSpeedButton(2, "TbS", (TSpeedButton*)Sender);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::TbSH3SpeedButtonClick(TObject *Sender)
{
   SetHumoSpeedButton(3, "TbS", (TSpeedButton*)Sender);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::TbSH4SpeedButtonClick(TObject *Sender)
{
   SetHumoSpeedButton(4, "TbS", (TSpeedButton*)Sender);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton46Click(TObject *Sender)
{
   SetTroelsSmith(46, "TbSc", (TSpeedButton*)Sender, TbScH1SpeedButton);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton47Click(TObject *Sender)
{
   SetTroelsSmith(47, "TbSc", (TSpeedButton*)Sender, TbScH1SpeedButton);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton48Click(TObject *Sender)
{
   SetTroelsSmith(48, "TbSc", (TSpeedButton*)Sender, TbScH1SpeedButton);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton49Click(TObject *Sender)
{
   SetTroelsSmith(49, "TbSc", (TSpeedButton*)Sender, TbScH1SpeedButton);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::TbScH1SpeedButtonClick(TObject *Sender)
{
   SetHumoSpeedButton(1, "TbSc", (TSpeedButton*)Sender);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::TbScH2SpeedButtonClick(TObject *Sender)
{
   SetHumoSpeedButton(2, "TbSc", (TSpeedButton*)Sender);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::TbScH3SpeedButtonClick(TObject *Sender)
{
   SetHumoSpeedButton(3, "TbSc", (TSpeedButton*)Sender);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::TbScH4SpeedButtonClick(TObject *Sender)
{
   SetHumoSpeedButton(4, "TbSc", (TSpeedButton*)Sender);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton50Click(TObject *Sender)
{
   SetTroelsSmith(50, "Tl", (TSpeedButton*)Sender, TlH1SpeedButton);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton51Click(TObject *Sender)
{
   SetTroelsSmith(51, "Tl", (TSpeedButton*)Sender, TlH1SpeedButton);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton52Click(TObject *Sender)
{
   SetTroelsSmith(52, "Tl", (TSpeedButton*)Sender, TlH1SpeedButton);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton53Click(TObject *Sender)
{
   SetTroelsSmith(53, "Tl", (TSpeedButton*)Sender, TlH1SpeedButton);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::TlH1SpeedButtonClick(TObject *Sender)
{
   SetHumoSpeedButton(1, "Tl", (TSpeedButton*)Sender);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::TlH2SpeedButtonClick(TObject *Sender)
{
   SetHumoSpeedButton(2, "Tl", (TSpeedButton*)Sender);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::TlH3SpeedButtonClick(TObject *Sender)
{
   SetHumoSpeedButton(3, "Tl", (TSpeedButton*)Sender);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::TlH4SpeedButtonClick(TObject *Sender)
{
   SetHumoSpeedButton(4, "Tl", (TSpeedButton*)Sender);
}
//---------------------------------------------------------------------------
   
void __fastcall TLithForm::SpeedButton54Click(TObject *Sender)
{
   SetTroelsSmith(54, "Th", (TSpeedButton*)Sender, ThH1SpeedButton);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton55Click(TObject *Sender)
{
   SetTroelsSmith(55, "Th", (TSpeedButton*)Sender, ThH1SpeedButton);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton56Click(TObject *Sender)
{
   SetTroelsSmith(56, "Th", (TSpeedButton*)Sender, ThH1SpeedButton);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton57Click(TObject *Sender)
{
   SetTroelsSmith(57, "Th", (TSpeedButton*)Sender, ThH1SpeedButton);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::ThH1SpeedButtonClick(TObject *Sender)
{
   SetHumoSpeedButton(1, "Th", (TSpeedButton*)Sender);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::ThH2SpeedButtonClick(TObject *Sender)
{
   SetHumoSpeedButton(2, "Th", (TSpeedButton*)Sender);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::ThH3SpeedButtonClick(TObject *Sender)
{
   SetHumoSpeedButton(3, "Th", (TSpeedButton*)Sender);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton58Click(TObject *Sender)
{
   SetTroelsSmith(58, "Thh", (TSpeedButton*)Sender, 0);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton59Click(TObject *Sender)
{
   SetTroelsSmith(59, "Thh", (TSpeedButton*)Sender, 0);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton60Click(TObject *Sender)
{
   SetTroelsSmith(60, "Thh", (TSpeedButton*)Sender, 0);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton61Click(TObject *Sender)
{
   SetTroelsSmith(61, "Thh", (TSpeedButton*)Sender, 0);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton62Click(TObject *Sender)
{
   SetTroelsSmith(62, "Dl", (TSpeedButton*)Sender, 0);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton63Click(TObject *Sender)
{
   SetTroelsSmith(63, "Dl", (TSpeedButton*)Sender, 0);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton64Click(TObject *Sender)
{
   SetTroelsSmith(64, "Dl", (TSpeedButton*)Sender, 0);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton65Click(TObject *Sender)
{
   SetTroelsSmith(65, "Dl", (TSpeedButton*)Sender, 0);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton66Click(TObject *Sender)
{
   SetTroelsSmith(66, "Dh", (TSpeedButton*)Sender, 0);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton67Click(TObject *Sender)
{
   SetTroelsSmith(67, "Dh", (TSpeedButton*)Sender, 0);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton68Click(TObject *Sender)
{
   SetTroelsSmith(68, "Dh", (TSpeedButton*)Sender, 0);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton69Click(TObject *Sender)
{
   SetTroelsSmith(69, "Dh", (TSpeedButton*)Sender, 0);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton70Click(TObject *Sender)
{
   SetTroelsSmith(70, "Dg", (TSpeedButton*)Sender, 0);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton71Click(TObject *Sender)
{
   SetTroelsSmith(71, "Dg", (TSpeedButton*)Sender, 0);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton72Click(TObject *Sender)
{
   SetTroelsSmith(72, "Dg", (TSpeedButton*)Sender, 0);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton73Click(TObject *Sender)
{
   SetTroelsSmith(73, "Dg", (TSpeedButton*)Sender, 0);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton74Click(TObject *Sender)
{
   SetTroelsSmith(74, "Ld", (TSpeedButton*)Sender, LdH1SpeedButton);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton75Click(TObject *Sender)
{
   SetTroelsSmith(75, "Ld", (TSpeedButton*)Sender, LdH1SpeedButton);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton76Click(TObject *Sender)
{
   SetTroelsSmith(76, "Ld", (TSpeedButton*)Sender, LdH1SpeedButton);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton77Click(TObject *Sender)
{
   SetTroelsSmith(77, "Ld", (TSpeedButton*)Sender, LdH1SpeedButton);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::LdH1SpeedButtonClick(TObject *Sender)
{
   SetHumoSpeedButton(1, "Ld", (TSpeedButton*)Sender);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::LdH2SpeedButtonClick(TObject *Sender)
{
   SetHumoSpeedButton(2, "Ld", (TSpeedButton*)Sender);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::LdH3SpeedButtonClick(TObject *Sender)
{
   SetHumoSpeedButton(3, "Ld", (TSpeedButton*)Sender);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::LdH4SpeedButtonClick(TObject *Sender)
{
   SetHumoSpeedButton(4, "Ld", (TSpeedButton*)Sender);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton78Click(TObject *Sender)
{
   SetTroelsSmith(78, "Lso", (TSpeedButton*)Sender, 0);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton79Click(TObject *Sender)
{
   SetTroelsSmith(79, "Lso", (TSpeedButton*)Sender, 0);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton80Click(TObject *Sender)
{
   SetTroelsSmith(80, "Lso", (TSpeedButton*)Sender, 0);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton81Click(TObject *Sender)
{
   SetTroelsSmith(81, "Lso", (TSpeedButton*)Sender, 0);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton82Click(TObject *Sender)
{
   SetTroelsSmith(82, "Lc", (TSpeedButton*)Sender, 0);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton83Click(TObject *Sender)
{
   SetTroelsSmith(83, "Lc", (TSpeedButton*)Sender, 0);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton84Click(TObject *Sender)
{
   SetTroelsSmith(84, "Lc", (TSpeedButton*)Sender, 0);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton85Click(TObject *Sender)
{
   SetTroelsSmith(85, "Lc", (TSpeedButton*)Sender, 0);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton86Click(TObject *Sender)
{
   SetTroelsSmith(86, "Lf", (TSpeedButton*)Sender, 0);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton87Click(TObject *Sender)
{
   SetTroelsSmith(87, "Lf", (TSpeedButton*)Sender, 0);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton88Click(TObject *Sender)
{
   SetTroelsSmith(88, "Lf", (TSpeedButton*)Sender, 0);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton89Click(TObject *Sender)
{
   SetTroelsSmith(89, "Lf", (TSpeedButton*)Sender, 0);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton90Click(TObject *Sender)
{
   SetTroelsSmith(90, "As", (TSpeedButton*)Sender, 0);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton91Click(TObject *Sender)
{
   SetTroelsSmith(91, "As", (TSpeedButton*)Sender, 0);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton92Click(TObject *Sender)
{
   SetTroelsSmith(92, "As", (TSpeedButton*)Sender, 0);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton93Click(TObject *Sender)
{
   SetTroelsSmith(93, "As", (TSpeedButton*)Sender, 0);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton94Click(TObject *Sender)
{
   SetTroelsSmith(94, "Ag", (TSpeedButton*)Sender, 0);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton95Click(TObject *Sender)
{
   SetTroelsSmith(95, "Ag", (TSpeedButton*)Sender, 0);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton96Click(TObject *Sender)
{
   SetTroelsSmith(96, "Ag", (TSpeedButton*)Sender, 0);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton97Click(TObject *Sender)
{
   SetTroelsSmith(97, "Ag", (TSpeedButton*)Sender, 0);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton98Click(TObject *Sender)
{
   SetTroelsSmith(98, "Ga", (TSpeedButton*)Sender, 0);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton99Click(TObject *Sender)
{
   SetTroelsSmith(99, "Ga", (TSpeedButton*)Sender, 0);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton100Click(TObject *Sender)
{
   SetTroelsSmith(100, "Ga", (TSpeedButton*)Sender, 0);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton101Click(TObject *Sender)
{
   SetTroelsSmith(101, "Ga", (TSpeedButton*)Sender, 0);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton102Click(TObject *Sender)
{
   SetTroelsSmith(102, "Gs", (TSpeedButton*)Sender, 0);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton103Click(TObject *Sender)
{
   SetTroelsSmith(103, "Gs", (TSpeedButton*)Sender, 0);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton104Click(TObject *Sender)
{
   SetTroelsSmith(104, "Gs", (TSpeedButton*)Sender, 0);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton105Click(TObject *Sender)
{
   SetTroelsSmith(105, "Gs", (TSpeedButton*)Sender, 0);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton106Click(TObject *Sender)
{
   SetTroelsSmith(106, "Gg(min)", (TSpeedButton*)Sender, 0);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton107Click(TObject *Sender)
{
   SetTroelsSmith(107, "Gg(min)", (TSpeedButton*)Sender, 0);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton108Click(TObject *Sender)
{
   SetTroelsSmith(108, "Gg(min)", (TSpeedButton*)Sender, 0);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton109Click(TObject *Sender)
{
   SetTroelsSmith(109, "Gg(min)", (TSpeedButton*)Sender, 0);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton110Click(TObject *Sender)
{
   SetTroelsSmith(110, "Gg(maj)", (TSpeedButton*)Sender, 0);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton111Click(TObject *Sender)
{
   SetTroelsSmith(111, "Gg(maj)", (TSpeedButton*)Sender, 0);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton112Click(TObject *Sender)
{
   SetTroelsSmith(112, "Gg(maj)", (TSpeedButton*)Sender, 0);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton113Click(TObject *Sender)
{
   SetTroelsSmith(113, "Gg(maj)", (TSpeedButton*)Sender, 0);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton114Click(TObject *Sender)
{
   SetTroelsSmith(114, "Test", (TSpeedButton*)Sender, 0);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton115Click(TObject *Sender)
{
   SetTroelsSmith(115, "Test", (TSpeedButton*)Sender, 0);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton116Click(TObject *Sender)
{
   SetTroelsSmith(116, "Test", (TSpeedButton*)Sender, 0);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton117Click(TObject *Sender)
{
   SetTroelsSmith(117, "Test", (TSpeedButton*)Sender, 0);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton118Click(TObject *Sender)
{
   SetTroelsSmith(118, "PartTest", (TSpeedButton*)Sender, 0);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton119Click(TObject *Sender)
{
   SetTroelsSmith(119, "PartTest", (TSpeedButton*)Sender, 0);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton120Click(TObject *Sender)
{
   SetTroelsSmith(120, "PartTest", (TSpeedButton*)Sender, 0);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton121Click(TObject *Sender)
{
   SetTroelsSmith(121, "PartTest", (TSpeedButton*)Sender, 0);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton122Click(TObject *Sender)
{
   SetTroelsSmith(122, "CortSec", (TSpeedButton*)Sender, 0);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton123Click(TObject *Sender)
{
   SetTroelsSmith(123, "CortSec", (TSpeedButton*)Sender, 0);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton124Click(TObject *Sender)
{
   SetTroelsSmith(124, "CortSec", (TSpeedButton*)Sender, 0);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton125Click(TObject *Sender)
{
   SetTroelsSmith(125, "CortSec", (TSpeedButton*)Sender, 0);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton126Click(TObject *Sender)
{
   SetTroelsSmith(126, "Cort", (TSpeedButton*)Sender, 0);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton127Click(TObject *Sender)
{
   SetTroelsSmith(127, "Cort", (TSpeedButton*)Sender, 0);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton128Click(TObject *Sender)
{
   SetTroelsSmith(128, "Cort", (TSpeedButton*)Sender, 0);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::SpeedButton129Click(TObject *Sender)
{
   SetTroelsSmith(129, "Cort", (TSpeedButton*)Sender, 0);
}
//---------------------------------------------------------------------------

// START LITHKEY TAB SHEET

void TLithKeyList::ReleaseAllLithKeys()
{
  for (int i = 0; i < Count; i++)
    ReleaseLithKey(i);
}
//---------------------------------------------------------------------------

void TLithKeyList::ReleaseLithKey(int AIndex)
{
  delete (LITHKEY*)Items[AIndex];
}
//---------------------------------------------------------------------------

LITHKEY* TLithKeyList::GetLithKey(int AIndex)
{
  return (LITHKEY*)Items[AIndex];
}
//---------------------------------------------------------------------------

void __fastcall TLithKeyList::Notify(void * Ptr, TListNotification Action)
{
  if (FOnNotify != NULL)
    FOnNotify(Ptr, Action);
}

//---------------------------------------------------------------------------

void __fastcall TLithKeyList::Clear(void)
{
  ReleaseAllLithKeys();
}
//---------------------------------------------------------------------------

void TLithKeyList::Add(LITHKEY* LithKey)
{
  TList::Add(LithKey);
}
//---------------------------------------------------------------------------

void TLithKeyList::Delete(int AIndex)
{
  ReleaseLithKey(AIndex);
  TList::Delete(AIndex);
}
//---------------------------------------------------------------------------

void TLithKeyList::Insert(int AIndex, LITHKEY* LithKey)
{
  TList::Insert(AIndex, LithKey);
}
//---------------------------------------------------------------------------

__fastcall TLithKeyDataSource::TLithKeyDataSource(TLithKeyList* ALithKeyList,
           TStringList* TSCodes)
{
  TroelsSmithCodes = TSCodes;
  FLithKeys = ALithKeyList;
  FLithKeys->OnNotify = Notify;
}
//---------------------------------------------------------------------------

void __fastcall TLithKeyDataSource::DeleteRecord(void * ARecordHandle)
{
  FLithKeys->Delete((int)ARecordHandle);
}
//---------------------------------------------------------------------------

int __fastcall TLithKeyDataSource::GetRecordCount(void)
{
  return(FLithKeys->Count);
}
//---------------------------------------------------------------------------

Variant __fastcall TLithKeyDataSource::GetValue(void * ARecordHandle, void * AItemHandle)
{
  Variant Result;
  int AColumnId = GetDefaultItemID((int)AItemHandle);
  if (FLithKeys == NULL) return 0;
  LITHKEY* LithKey = FLithKeys->LithKeys[(int)ARecordHandle];

  switch (AColumnId) {
    case IndexOfUnit:
      Result = LithKey->GetLithUnit();
      break;
    case IndexOfX:
      if (IsNan(LithKey->x))
		Result.ChangeType(varEmpty);
      else
        Result = LithKey->x;
      break;
    case IndexOfY:
      if (LithKey->AutoY)
        Result.ChangeType(varEmpty);
      else
        Result = LithKey->y;
      break;
    case IndexOfLithLabel:
      Result = LithKey->LithLabel; break;
    case IndexOfColor:
      Result = LithKey->Color; break;
    case IndexOfPlot:
      Result = LithKey->Plot; break;
  }
  return (Result);
}
//---------------------------------------------------------------------------

void __fastcall TLithKeyDataSource::Notify(void * Ptr, TListNotification Action)
{
  DataChanged();
}

//---------------------------------------------------------------------------

void * __fastcall TLithKeyDataSource::InsertRecord(void * ARecordHandle)
{
  LITHKEY* LithKey = new LITHKEY;
  LithKey->TroelsSmithCodes = TroelsSmithCodes;
  FLithKeys->Insert((int)ARecordHandle, LithKey);
  TcxDataRecordHandle* Result = (TcxDataRecordHandle*)ARecordHandle;
  return (Result);
}
//---------------------------------------------------------------------------

void * __fastcall TLithKeyDataSource::AppendRecord(void)
{
  TcxDataRecordHandle* Result = (TcxDataRecordHandle*)FLithKeys->Count;
  LITHKEY* LithKey = new LITHKEY;
  LithKey->TroelsSmithCodes = TroelsSmithCodes;
  FLithKeys->Add(LithKey);
  return (Result);
}
//---------------------------------------------------------------------------

void __fastcall TLithKeyDataSource::SetValue(void * ARecordHandle, void * AItemHandle, const Variant &AValue)
{
  int AColumnId = GetDefaultItemID((int)AItemHandle);
  LITHKEY* LithKey = FLithKeys->LithKeys[(int)ARecordHandle];
  switch (AColumnId) {
    case IndexOfUnit:
	  if (AValue.IsNull()) {
        LithKey->SetLithCode(0);
        LithKey->SetHumo(0);
        }
      else
        LithKey->SetLithCode(AValue);
      break;
    case IndexOfX:
	  if (AValue.IsNull()) {
        LithKey->x = NaN;
        LithKey->AutoX = true;
        }
      else
        LithKey->Set_x(AValue);
      break;
    case IndexOfY:
	  if (AValue.IsNull()) {
        LithKey->y = NaN;
        LithKey->AutoY = true;
        }
      else
        LithKey->Set_y(AValue);
      break;
    case IndexOfLithLabel:
	  if (AValue.IsNull())
        LithKey->LithLabel.SetLength(0);
      else
        LithKey->LithLabel = AValue;
      break;
    case IndexOfColor:
      LithKey->Color = (TColor)((int)AValue);
      break;
    case IndexOfPlot:
      LithKey->Plot = AValue;
      break;
  }
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::GenerateLithKeyColumns()
{
   lkUnit->DataBinding->Data = (TObject*)IndexOfUnit;
   lkX->DataBinding->Data = (TObject*)IndexOfX;
   lkY->DataBinding->Data = (TObject*)IndexOfY;
   lkLithLabel->DataBinding->Data = (TObject *)IndexOfLithLabel;
   lkColor->DataBinding->Data = (TObject *)IndexOfColor;
   lkPlot->DataBinding->Data = (TObject*)IndexOfPlot;

   // this line is critical
   LithKeyGridTableView->DataController->CustomDataSource = LithKeyDataSource;
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::LoadLithKeyData()
{
  for (int i=0; i<Diag->LithKeys->Count; i++) {
    LITHKEY *LithKey = new LITHKEY((LITHKEY*)Diag->LithKeys->Items[i]);
    LithKey->TroelsSmithCodes = TroelsSmithCodes;
    LithKeyList->Add(LithKey);
    }
  LithKeyGridTableView->DataController->GotoFirst();
}
//---------------------------------------------------------------------------

// import lithologic units
void __fastcall TLithForm::BitBtn8Click(TObject *Sender)
{
   if (LithList->Count == 0) {
	 MessageDlg("No lithologic units entered", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
     return;
     }

   if (LithKeyList->Count > 0) {
     LithKeyGridTableView->DataController->MultiSelect = true;
     LithKeyGridTableView->DataController->SelectAll();
     try {
       LithKeyGridTableView->DataController->DeleteSelection(); }
     catch(Exception &e) {
	   MessageDlg("Cannot delete records due to the exception: " + e.Message, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
       return;
       }
     LithKeyGridTableView->DataController->MultiSelect = false;
     }

  for (int i=0; i<LithList->Count; i++) {
    LITH1* Lith1 = (LITH1*)LithList->Liths[i];
    for (int j=0; j<Lith1->Components->Count; j++) {
      LITH2 *Lith2 = (LITH2*)Lith1->Components->Items[j];
      LITHKEY *LithKey = new LITHKEY;
      LithKey->TroelsSmithCodes = TroelsSmithCodes;
      LithKey->SetLithCode(Lith2->LithCode);
      LithKey->SetHumo(Lith2->Humo);
      LithKey->Color = Lith2->Color;
      LithKey->Plot = true;
      bool found = false;
      // find duplicates
      for (int k=0; k<LithKeyList->Count; k++) {
        LITHKEY *lk = LithKeyList->LithKeys[k];
        if (LithKey->GetLithCode() == lk->GetLithCode() &&
            LithKey->GetHumo() == lk->GetHumo() &&
            LithKey->Color == lk->Color)
          { found = true; break; }
        }
      if (found)
        delete LithKey;
      else
        LithKeyList->Add(LithKey);
      }
    }

  LithKeyGridTableView->DataController->GotoFirst();
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::BitBtn9Click(TObject *Sender)
{
   TFontDialogBox* FontForm = new TFontDialogBox(this);
   FontForm->SetFont(LithTitleFont);
   if (FontForm->ShowModal() == mrOk)
     FontForm->GetFont(LithTitleFont);
   delete FontForm;
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::BitBtn10Click(TObject *Sender)
{
   TFontDialogBox* FontForm = new TFontDialogBox(this);
   FontForm->SetFont(KeyFont);
   if (FontForm->ShowModal() == mrOk)
     FontForm->GetFont(KeyFont);
   delete FontForm;
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::Button4Click(TObject *Sender)
{
   LabeledEdit1->Text = "Auto";
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::Button5Click(TObject *Sender)
{
   LabeledEdit2->Text = "Auto";      
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::OptionsTabSheetEnter(TObject *Sender)
{
   if (LithDataSource->LithList->Count > 0 && InitialZero) {
     CheckBox1->Checked = true;
     Diag->lopt.On = true;
     InitialZero = false;
     }
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::Button3Click(TObject *Sender)
{
   Application->HelpContext(IDH_Lithology_Dialog_Box);
}
//---------------------------------------------------------------------------

bool __fastcall TLithForm::FormHelp(WORD Command, int Data, bool &CallHelp)
{
   return true;
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::LithGridTableView1DataControllerNewRecord(
      TcxCustomDataController *ADataController, int ARecordIndex)
{
   LithDataSource->TempLith1 = new LITH1((TColor)Diag->lopt.DefaultColor);
   EnableButtons();
   ColorBox1->Enabled = true;
   ColorBox2->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::LithGridTableView1DataControllerAfterPost(
      TcxCustomDataController *ADataController)
{
   if (ADataController->FocusedRecordIndex == -1) {
     DisableButtons();
     ClearBitmap();
     }
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::lgTopDepthPropertiesValidate(TObject *Sender,
      Variant &DisplayValue, TCaption &ErrorText, bool &Error)
{
   ValidateNumericalDisplayValue(DisplayValue, ErrorText, Error);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::lgBottomDepthPropertiesValidate(TObject *Sender,
      Variant &DisplayValue, TCaption &ErrorText, bool &Error)
{
   ValidateNumericalDisplayValue(DisplayValue, ErrorText, Error);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::lgLoBoundPropertiesValidate(TObject *Sender,
      Variant &DisplayValue, TCaption &ErrorText, bool &Error)
{
   ValidateNumericalDisplayValue(DisplayValue, ErrorText, Error);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::lkXPropertiesValidate(TObject *Sender,
      Variant &DisplayValue, TCaption &ErrorText, bool &Error)
{
   ValidateNumericalDisplayValue(DisplayValue, ErrorText, Error);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::lkYPropertiesValidate(TObject *Sender,
      Variant &DisplayValue, TCaption &ErrorText, bool &Error)
{
   ValidateNumericalDisplayValue(DisplayValue, ErrorText, Error);
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::lkXGetCellHint(TcxCustomGridTableItem *Sender,
      TcxCustomGridRecord *ARecord,
      TcxGridTableDataCellViewInfo *ACellViewInfo, const TPoint &AMousePos,
      TCaption &AHintText, bool &AIsHintMultiLine, TRect &AHintTextRect)
{
   AHintText = "Leave blank for automatic placement";
}
//---------------------------------------------------------------------------

void __fastcall TLithForm::lkYGetCellHint(TcxCustomGridTableItem *Sender,
      TcxCustomGridRecord *ARecord,
      TcxGridTableDataCellViewInfo *ACellViewInfo, const TPoint &AMousePos,
      TCaption &AHintText, bool &AIsHintMultiLine, TRect &AHintTextRect)
{
   AHintText = "Leave blank for automatic placement";
}
//---------------------------------------------------------------------------

