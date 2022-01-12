//---------------------------------------------------------------------------

#include <vcl.h>
#include "pch.h"
#pragma hdrstop

#include "TGDatFrm.h"
#ifndef TGParentH
#include "TGParent.h"
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
#pragma link "cxDataStorage"
#pragma link "cxTextEdit"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxButtons"
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
TDatesForm *DatesForm;

//---------------------------------------------------------------------------
void TDateList::ReleaseAllDates()
{
  for (int i = 0; i < Count; i++)
    ReleaseDate(i);
}
//---------------------------------------------------------------------------

void TDateList::ReleaseDate(int AIndex)
{
  delete (DATES*)Items[AIndex];
}
//---------------------------------------------------------------------------

DATES* TDateList::GetDate(int AIndex)
{
  return (DATES*)Items[AIndex];
}
//---------------------------------------------------------------------------

void __fastcall TDateList::Notify(void * Ptr, TListNotification Action)
{
  if (FOnNotify != NULL)
    FOnNotify(Ptr, Action);
}
//---------------------------------------------------------------------------

void __fastcall TDateList::Clear(void)
{
  ReleaseAllDates();
}
//---------------------------------------------------------------------------

void TDateList::Add(DATES* Date)
{
  TList::Add(Date);
}
//---------------------------------------------------------------------------

void TDateList::Delete(int AIndex)
{
  ReleaseDate(AIndex);
  TList::Delete(AIndex);
}
//---------------------------------------------------------------------------

void TDateList::Insert(int AIndex, DATES* Date)
{
  TList::Insert(AIndex, Date);
}
//---------------------------------------------------------------------------

__fastcall TDateDataSource::TDateDataSource(TDateList* ADateList)
{
  FDates = ADateList;
  //grf = g;
  FDates->OnNotify = Notify;
}
//---------------------------------------------------------------------------

void __fastcall TDateDataSource::DeleteRecord(void * ARecordHandle)
{
  FDates->Delete((int)ARecordHandle);
}
//---------------------------------------------------------------------------

int __fastcall TDateDataSource::GetRecordCount(void)
{
  return(FDates->Count);
}
//---------------------------------------------------------------------------

Variant __fastcall TDateDataSource::GetValue(void * ARecordHandle, void * AItemHandle)
{
  // displays value in grid based on stored data
  int AColumnId = GetDefaultItemID((int)AItemHandle);
  DATES* Date = FDates->Dates[(int)ARecordHandle];
  Variant Result;
  switch (AColumnId) {
    case IndexOfdaTopDepth:
      if (IsNan(Date->top))
		Result.ChangeType(varEmpty);
      else
        Result = Date->top;
      break;
    case IndexOfdaBottomDepth:
      if (IsNan(Date->bot))
		Result.ChangeType(varEmpty);
      else
        Result = Date->bot;
      break;
    case IndexOfdaDate:
      Result = Date->date;
      break;
    case IndexOfdaOffset:
      Result = Date->voff;
      break;
  }
  return (Result);
}
//---------------------------------------------------------------------------

void __fastcall TDateDataSource::Notify(void * Ptr, TListNotification Action)
{
  DataChanged();
}
//---------------------------------------------------------------------------

void * __fastcall TDateDataSource::InsertRecord(void * ARecordHandle)
{
  DATES* Date = new DATES;
  Date->top = NaN;
  Date->bot = NaN;
  FDates->Insert((int)ARecordHandle, Date);
  TcxDataRecordHandle* Result = (TcxDataRecordHandle*)ARecordHandle;
  return (Result);
}
//---------------------------------------------------------------------------

void * __fastcall TDateDataSource::AppendRecord(void)
{
  TcxDataRecordHandle* Result = (TcxDataRecordHandle*)FDates->Count;
  DATES* Date = new DATES;
  Date->top = NaN;
  Date->bot = NaN;
  FDates->Add(Date);
  return (Result);
}
//---------------------------------------------------------------------------

void __fastcall TDateDataSource::SetValue(void * ARecordHandle, void * AItemHandle, const Variant &AValue)
{
  // gets values from grid and stores them
  int AColumnId = GetDefaultItemID((int)AItemHandle);
  DATES* Date = FDates->Dates[(int)ARecordHandle];
  switch (AColumnId) {
    case IndexOfdaTopDepth:
	  if (AValue.IsNull())
        Date->top = NaN;
      else
        Date->top = AValue;
      break;
    case IndexOfdaBottomDepth:
	  if (AValue.IsNull())
        Date->bot = NaN;
      else
        Date->bot = AValue;
	  break;
	case IndexOfdaDate:
	  Date->date = VarToStr(AValue);
	  break;
    case IndexOfdaOffset:
      if (AValue.IsNull())
        Date->voff = 0;
      else
        Date->voff = AValue;
      break;
  }
}
//---------------------------------------------------------------------------

__fastcall TDatesForm::TDatesForm(TComponent* Owner)
        : TForm(Owner)
{
  Diag = (TTGDiagram*)Owner;
  DoubleBuffered = true;
}
//---------------------------------------------------------------------------

void __fastcall TDatesForm::FormCreate(TObject *Sender)
{
  DateList = new TDateList();
  DateDataSource = new TDateDataSource(DateList);
  GenerateDateColumns();
}
//---------------------------------------------------------------------------

void __fastcall TDatesForm::FormActivate(TObject *Sender)
{
  LoadDateData();
  FocusControl(DatesGrid);
  RadioGroup1->ItemIndex = (Diag->dopt.DatesPosition == LEFT) ? 0 : 1;

  ColorBox1->Selected = (TColor)Diag->dopt.Color;
  if (ColorBox1->Selected == clBlack)
    ColorBox1->ItemIndex = 1;

  // temporary fonts
  DateFont = Diag->dopt.DateFont;
  LabelFont = Diag->dopt.DateTitleFont;

  Edit1->Text = Diag->dopt.DateTitle;

  switch (Diag->dopt.DatesTitlePosition) {
    case SIDE:
      RadioGroup2->ItemIndex = 0;
      LabeledEdit2->Color = clBtnFace;
      LabeledEdit3->Color = clBtnFace;
      LabeledEdit1->Color = clBtnFace;
      LabeledEdit2->Enabled = false;
      LabeledEdit3->Enabled = false;
      LabeledEdit1->Enabled = false;
      break;
    case TOP:
      RadioGroup2->ItemIndex = 1;
      LabeledEdit2->Color = clBtnFace;
      LabeledEdit3->Color = clBtnFace;
      LabeledEdit1->Color = clBtnFace;
      LabeledEdit2->Enabled = false;
      LabeledEdit3->Enabled = false;
      LabeledEdit1->Enabled = false;
      break;
    default:  // user defined
      RadioGroup2->ItemIndex = 2;
      LabeledEdit2->Color = clWindow;
      LabeledEdit3->Color = clWindow;
      LabeledEdit1->Color = clWindow;
      LabeledEdit2->Text = Diag->dopt.X_Title;
      LabeledEdit3->Text = Diag->dopt.Y_Title;
      LabeledEdit1->Text = Diag->dopt.Angle;
      LabeledEdit2->Enabled = true;
      LabeledEdit3->Enabled = true;
      LabeledEdit1->Enabled = true;
      break;
    };

  curpos = 0;
  Screen->Cursor = crDefault;
}
//---------------------------------------------------------------------------

void __fastcall TDatesForm::GenerateDateColumns()
{
   daTopDepth->DataBinding->Data = (void*)IndexOfdaTopDepth;
   daBottomDepth->DataBinding->Data = (TObject*)IndexOfdaBottomDepth;
   daDate->DataBinding->Data = (TObject*)IndexOfdaDate;
   daOffset->DataBinding->Data = (TObject*)IndexOfdaOffset;
   // this line is critical
   DatesGridTableView->DataController->CustomDataSource = DateDataSource;
}
//---------------------------------------------------------------------------

void __fastcall TDatesForm::LoadDateData()
{
  for (int i=0; i<Diag->Dates->Count; i++) {
    DATES *Date = new DATES((DATES*)Diag->Dates->Items[i]);
    DateList->Add(Date);
    }
  DatesGridTableView->DataController->GotoFirst();
}
//---------------------------------------------------------------------------

void __fastcall TDatesForm::FormDeactivate(TObject *Sender)
{
   delete DateList;
   delete DateDataSource;
}
//---------------------------------------------------------------------------

// Ok button
void __fastcall TDatesForm::cxButton1Click(TObject *Sender)
{
   double x;

   Diag->Modified = true;
   // delete old dates
   if (Diag->Dates->Count > 0) {
     for (int i=0; i<Diag->Dates->Count; i++) {
       DATES* Date = (DATES*)Diag->Dates->Items[i];
       delete Date;
       Diag->Dates->Items[i] = 0;
       }
     Diag->Dates->Clear();
     Diag->Dates->Capacity = 100;
     }

   if (DateList->Count > 0) {
     for (int i=0; i<DateList->Count; i++) {
       DATES* Date = (DATES*)DateList->Dates[i];
       if (!Date->date.IsEmpty() && !IsNan(Date->top) && !IsNan(Date->bot)) {
         Date = new DATES(DateList->Dates[i]);
         Diag->Dates->Add(Date);
         }
       }
     }

   Diag->dopt.DatesPosition = (RadioGroup1->ItemIndex == 0) ? LEFT : RIGHT;
   Diag->dopt.Color = ColorBox1->Selected;
   Diag->dopt.DateFont = DateFont;
   Diag->dopt.DateTitleFont = LabelFont;

   Diag->dopt.DateTitle = Edit1->Text;

   switch (RadioGroup2->ItemIndex) {
     case 0:
       Diag->dopt.DatesTitlePosition = SIDE;
       Diag->dopt.Angle = 90.0;
       break;
     case 1:
       Diag->dopt.DatesTitlePosition = TOP;
       Diag->dopt.Angle = 45.0;
       break;
     case 2:
       Diag->dopt.DatesTitlePosition = USERDEFINED;
       try {
         x = StrToFloat(LabeledEdit2->Text); }
       catch (...) {
         x = 0.0; }
       Diag->dopt.X_Title = x;
       try {
         x = StrToFloat(LabeledEdit3->Text); }
       catch (...) {
         x = 0.0; }
       Diag->dopt.Y_Title = x;
       try {
         x = StrToFloat(LabeledEdit1->Text); }
       catch (...) {
         x = 90.0; }
       Diag->dopt.Angle = x;
       break;
	 };
}
//---------------------------------------------------------------------------

void __fastcall TDatesForm::cxButton5Click(TObject *Sender)
{
   TFontDialogBox* FontForm = new TFontDialogBox(this);
   FontForm->SetFont(DateFont);
   if (FontForm->ShowModal() == mrOk)
	 FontForm->GetFont(DateFont);
   delete FontForm;
}
//---------------------------------------------------------------------------

void __fastcall TDatesForm::cxButton6Click(TObject *Sender)
{
   TFontDialogBox* FontForm = new TFontDialogBox(this);
   FontForm->SetFont(LabelFont);
   if (FontForm->ShowModal() == mrOk)
	 FontForm->GetFont(LabelFont);
   delete FontForm;
}
//---------------------------------------------------------------------------

void __fastcall TDatesForm::RadioGroup2Click(TObject *Sender)
{
   switch (RadioGroup2->ItemIndex) {
     case 0:
     case 1:
       LabeledEdit2->Clear();
       LabeledEdit3->Clear();
       LabeledEdit1->Clear();
       LabeledEdit2->Color = clBtnFace;
       LabeledEdit3->Color = clBtnFace;
       LabeledEdit1->Color = clBtnFace;
       LabeledEdit2->Enabled = false;
       LabeledEdit3->Enabled = false;
       LabeledEdit1->Enabled = false;
       break;
     case 2:
       LabeledEdit2->Color = clWindow;
       LabeledEdit3->Color = clWindow;
       LabeledEdit1->Color = clWindow;
       LabeledEdit2->Text = Diag->dopt.X_Title;
       LabeledEdit3->Text = Diag->dopt.Y_Title;
       LabeledEdit1->Text = Diag->dopt.Angle;
       LabeledEdit2->Enabled = true;
       LabeledEdit3->Enabled = true;
       LabeledEdit1->Enabled = true;
       break;
     };
}
//---------------------------------------------------------------------------

// plus or minus button
void __fastcall TDatesForm::cxButton4Click(TObject *Sender)
{
  FocusControl(DatesGrid);
  daDate->Editing = true;
  if (DatesGridTableView->Controller->EditingController->Edit) {
	UnicodeString Text = ((TcxTextEdit*)DatesGridTableView->Controller->EditingController->Edit)->EditingText;
	Text.Insert(L"\xB1", curpos+1);
	((TcxTextEdit*)DatesGridTableView->Controller->EditingController->Edit)->EditingText = Text;
	FocusControl(DatesGrid);
	}
}
//---------------------------------------------------------------------------

// enable plus-or-minus button if date column focused
void __fastcall TDatesForm::DatesGridTableViewFocusedItemChanged(
      TcxCustomGridTableView *Sender,
      TcxCustomGridTableItem *APrevFocusedItem,
      TcxCustomGridTableItem *AFocusedItem)
{
	cxButton4->Enabled = (AFocusedItem->Index == 2);
}
//---------------------------------------------------------------------------

void __fastcall TDatesForm::cxButton3Click(TObject *Sender)
{
   Application->HelpContext(IDH_Dates_Dialog_Box);
}
//---------------------------------------------------------------------------

bool __fastcall TDatesForm::FormHelp(WORD Command, int Data, bool &CallHelp)
{
   return true;
}
//---------------------------------------------------------------------------

void __fastcall TDatesForm::DatesGridTableViewEditKeyUp(
      TcxCustomGridTableView *Sender, TcxCustomGridTableItem *AItem,
      TcxCustomEdit *AEdit, WORD &Key, TShiftState Shift)
{
   if (AItem->Index == 2)
     curpos = ((TcxTextEdit*)DatesGridTableView->Controller->EditingController->Edit)->CursorPos;
}
//---------------------------------------------------------------------------

void __fastcall TDatesForm::daDateGetDisplayText(
      TcxCustomGridTableItem *Sender, TcxCustomGridRecord *ARecord,
	  UnicodeString &AText)
{
   if (DatesGridTableView->Controller->EditingController->Edit) {
     if (DatesGridTableView->Controller->EditingController->Edit->IsFocused) {
       if (DatesGridTableView->Controller->EditingController->EditingItem->Index == 2) {
         curpos = ((TcxTextEdit*)DatesGridTableView->Controller->EditingController->Edit)->CursorPos;
         }
       }
     }
}
//---------------------------------------------------------------------------

void __fastcall TDatesForm::daTopDepthPropertiesValidate(TObject *Sender,
      Variant &DisplayValue, TCaption &ErrorText, bool &Error)
{
   ValidateNumericalDisplayValue(DisplayValue, ErrorText, Error);
}
//---------------------------------------------------------------------------

void __fastcall TDatesForm::daBottomDepthPropertiesValidate(
      TObject *Sender, Variant &DisplayValue, TCaption &ErrorText,
      bool &Error)
{
   ValidateNumericalDisplayValue(DisplayValue, ErrorText, Error);
}
//---------------------------------------------------------------------------

void __fastcall TDatesForm::daOffsetPropertiesValidate(TObject *Sender,
      Variant &DisplayValue, TCaption &ErrorText, bool &Error)
{
   ValidateNumericalDisplayValue(DisplayValue, ErrorText, Error);
}
//---------------------------------------------------------------------------

