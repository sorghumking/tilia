//---------------------------------------------------------------------------

#include <vcl.h>
#include "pch.h"
#pragma hdrstop

#ifndef TGYaxFrmH
#include "TGYaxFrm.h"
#endif
#ifndef TGYaxisH
#include "TGYaxis.h"
#endif
#include "TGHelp.h"
#ifndef TGUtilsH
#include "TGUtils.h"
#endif
#ifndef TGFntDlgH
#include "TGFntDlg.h"
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
#pragma link "cxPC"
#pragma link "cxButtons"
#pragma link "cxPCdxBarPopupMenu"
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
#pragma link "dxBarBuiltInMenu"
#pragma link "dxSkinOffice2016Colorful"
#pragma link "dxSkinOffice2016Dark"
#pragma link "dxSkinVisualStudio2013Blue"
#pragma link "dxSkinVisualStudio2013Dark"
#pragma link "dxSkinVisualStudio2013Light"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------

TYaxesForm *YaxesForm;

//---------------------------------------------------------------------------
void TYaxesList::ReleaseAllYaxes()
{
  for (int i = 0; i < Count; i++)
    ReleaseYaxis(i);
}
//---------------------------------------------------------------------------

void TYaxesList::ReleaseYaxis(int AIndex)
{
  delete (NEWYAXIS*)Items[AIndex];
}
//---------------------------------------------------------------------------

NEWYAXIS* TYaxesList::GetYaxis(int AIndex)
{
  return (NEWYAXIS*)Items[AIndex];
}
//---------------------------------------------------------------------------

void __fastcall TYaxesList::Notify(void * Ptr, TListNotification Action)
{
  if (FOnNotify != NULL)
    FOnNotify(Ptr, Action);
}
//---------------------------------------------------------------------------

void __fastcall TYaxesList::Clear(void)
{
  ReleaseAllYaxes();
}
//---------------------------------------------------------------------------

__fastcall TYaxisDataSource::TYaxisDataSource(TYaxesList* AYaxesList)
{
  FYaxes = AYaxesList;
  FYaxes->OnNotify = Notify;
}
//---------------------------------------------------------------------------

int __fastcall TYaxisDataSource::GetRecordCount(void)
{
  return(FYaxes->Count);
}
//---------------------------------------------------------------------------

Variant __fastcall TYaxisDataSource::GetValue(void * ARecordHandle, void * AItemHandle)
{
  // displays value in grid based on stored data
  int AColumnId = GetDefaultItemID((int)AItemHandle);
  NEWYAXIS* Yaxis = FYaxes->Yaxes[(int)ARecordHandle];
  Variant Result;
  switch (AColumnId) {
    case IndexOfyaCode:
      Result = Yaxis->AxisCode;
      break;
    case IndexOfyaName:
      Result = Yaxis->AxisLabel;
      break;
    case IndexOfyaPlot:
      Result = Yaxis->Plot;
      break;
  }
  return (Result);
}
//---------------------------------------------------------------------------

void __fastcall TYaxisDataSource::Notify(void * Ptr, TListNotification Action)
{
  DataChanged();
}
//---------------------------------------------------------------------------

void __fastcall TYaxisDataSource::SetValue(void * ARecordHandle, void * AItemHandle, const Variant &AValue)
{
  // gets values from grid and stores them
  UnicodeString Name;
  int AColumnId = GetDefaultItemID((int)AItemHandle);
  NEWYAXIS* Yaxis = FYaxes->Yaxes[(int)ARecordHandle];
  switch (AColumnId) {
    case IndexOfyaCode:
      Yaxis->AxisCode = AValue;
      break;
    case IndexOfyaName:
	  Name = VarToStr(AValue);
      Yaxis->AxisLabel = CheckEntityRefs(Name);
	  break;
    case IndexOfyaPlot:
      Yaxis->Plot = AValue;
      break;
  }
}

//---------------------------------------------------------------------------
__fastcall TYaxesForm::TYaxesForm(TComponent* Owner)
        : TForm(Owner)
{
   Diag = (TTGDiagram*)Owner;
}
//---------------------------------------------------------------------------

void __fastcall TYaxesForm::FormCreate(TObject *Sender)
{
   LabeledEdit13->EditLabel->Height = 26;
   LabeledEdit13->EditLabel->Width = 129;     
   LabeledEdit13->EditLabel->WordWrap = true;
   LabeledEdit14->EditLabel->Height = 26;
   LabeledEdit14->EditLabel->Width = 127;
   LabeledEdit14->EditLabel->WordWrap = true;
   cxPageControl1->ActivePage = cxTabSheet1;
   AxisLineWidthComboBox = new LineWidthComboBox(LineWidthComboBox1);
}
//---------------------------------------------------------------------------

void __fastcall TYaxesForm::FormDestroy(TObject *Sender)
{
   delete AxisLineWidthComboBox;
}
//---------------------------------------------------------------------------

void __fastcall TYaxesForm::FormActivate(TObject *Sender)
{
  int i, k;

  YaxesList = new TYaxesList();
  YaxisDataSource = new TYaxisDataSource(YaxesList);
  GenerateYaxesColumns();
  LoadYaxesData();

  Activated = false;

  // individual axis options
  NEWYAXIS *Axis1 = (NEWYAXIS*)YaxesList->Yaxes[InitialAxisNo-1];

  // global options
  switch (Axis1->AxisStyle){
   case STANDARD_AXIS: RadioGroup2->ItemIndex = 0; break;
   case COLUMN_AXIS:   RadioGroup2->ItemIndex = 1; break;
   case NAMES_AXIS:    RadioGroup2->ItemIndex = 2; break;
   };
  LabeledEdit1->Text = Axis1->AxisLength;
  LabeledEdit13->Text = Axis1->XaxisDistance;
  LabeledEdit14->Text = Axis1->SpaceRight;

  YaxisGrid->Height = 2 +
      YaxisGridTableView->ViewInfo->HeaderViewInfo->ItemHeight +
      min(4,YaxesList->Count)*YaxisGridTableView->ViewInfo->RecordsViewInfo->RowHeight;
  if (YaxesList->Count < 2) {
	cxButton1->Visible = false;
	cxButton2->Visible = false;
	//Panel1->Left -= cxButton1->Width;
	//Button1->Left -= cxButton1->Width;
	//Button2->Left -= cxButton1->Width;
	//Button3->Left -= cxButton1->Width;
	//YaxesForm->ClientWidth -= cxButton1->Width;
	}
  //PageControl1->Top = YaxisGrid->Top + YaxisGrid->Height;
  //Bevel1->Height = max(330, 16 + YaxisGrid->Height + PageControl1->Height);
  //Button1->Top = max(320, Bevel1->Top + Bevel1->Height - Button1->Height);
  //Button2->Top = Button1->Top;
  //Button3->Top = Button1->Top;
  //YaxesForm->ClientHeight = 12 + Button1->Top + Button1->Height;
  FocusControl(YaxisGrid);
  YaxisGridTableView->Controller->FocusedRecordIndex = InitialAxisNo-1;

  AxisLineWidthComboBox->SetLineWidth(Axis1->LineWidth);
  Activated = true;
  Screen->Cursor = crDefault;
}
//---------------------------------------------------------------------------

void __fastcall TYaxesForm::GenerateYaxesColumns()
{
   yaCode->DataBinding->Data = (TObject*)IndexOfyaCode;
   yaName->DataBinding->Data = (TObject*)IndexOfyaName;
   yaPlot->DataBinding->Data = (TObject *)IndexOfyaPlot;
   // this line is critical
   YaxisGridTableView->DataController->CustomDataSource = YaxisDataSource;
}
//---------------------------------------------------------------------------

void __fastcall TYaxesForm::LoadYaxesData()
{
  for (int i=0; i<Diag->YAxes->Count; i++) {
	NEWYAXIS* YAxis = (NEWYAXIS*)Diag->YAxes->Items[i];
	NEWYAXIS *Yaxis = new NEWYAXIS(YAxis);
	// NEWYAXIS *Yaxis = new NEWYAXIS((NEWYAXIS*)Diag->YAxes->Items[i]);
    YaxesList->Add(Yaxis);
    }
  YaxisGridTableView->DataController->GotoFirst();
}
//---------------------------------------------------------------------------

void TYaxesForm::ShowAxisOptions(NEWYAXIS *Axis)
{
  //TabSheet1
  ShowAxisLimits(Axis);
  if (Axis->ScaleAutoMin) {
    CheckBox3->State = cbChecked;
    Edit3->Clear();
    Edit3->Color = clBtnFace;
    Edit3->Enabled = false;
    }
  else {
    CheckBox3->State = cbUnchecked;
    Edit3->Color = clWindow;
    Edit3->Text = Axis->ScaleMin;
    Edit3->Enabled = true;
    }

  if (Axis->ScaleAutoMax) {
    CheckBox4->State = cbChecked;
    Edit4->Clear();
    Edit4->Color = clBtnFace;
    Edit4->Enabled = false;
    }
  else {
    CheckBox4->State = cbUnchecked;
    Edit4->Color = clWindow;
    Edit4->Text = Axis->ScaleMax;
    Edit4->Enabled = true;
    }

  //TabSheet2
  if (Axis->AutoTic) {
    CheckBox5->State = cbChecked;
    LabeledEdit5->Clear();
    LabeledEdit5->Color = clBtnFace;
    LabeledEdit5->Enabled = false;
    LabeledEdit6->Clear();
    LabeledEdit6->Color = clBtnFace;
    LabeledEdit6->Enabled = false;
    }
  else {
    CheckBox5->State = cbUnchecked;
    LabeledEdit5->Color = clWindow;
    LabeledEdit5->Text = Axis->MinorTics;
    LabeledEdit5->Enabled = true;
    LabeledEdit6->Color = clWindow;
    LabeledEdit6->Text = Axis->MajorTics;
    LabeledEdit6->Enabled = true;
    }

  LabeledEdit2->Text = Axis->LabelToTicDistance;
  LabeledEdit3->Text = 1.0/Axis->TicLabelDivideBy;
  LabeledEdit4->Text = Axis->TicDecPts;

  LabeledEdit7->Text = Axis->MinorTicLength;
  LabeledEdit8->Text = Axis->MajorTicLength;

  //TabSheet3
  switch (Axis->LabelPosition)
   {
   case SIDE:
     RadioGroup1->ItemIndex = 0;
     LabeledEdit10->Clear();
     LabeledEdit10->Color = clBtnFace;
     LabeledEdit10->Enabled = false;
     LabeledEdit11->Clear();
     LabeledEdit11->Color = clBtnFace;
     LabeledEdit11->Enabled = false;
     LabeledEdit12->Clear();
     LabeledEdit12->Color = clBtnFace;
     LabeledEdit12->Enabled = false;
     break;
   case TOP:
     RadioGroup1->ItemIndex = 1;
     LabeledEdit10->Clear();
     LabeledEdit10->Color = clBtnFace;
     LabeledEdit10->Enabled = false;
     LabeledEdit11->Clear();
     LabeledEdit11->Color = clBtnFace;
     LabeledEdit11->Enabled = false;
     LabeledEdit12->Color = clWindow;
     LabeledEdit12->Text = Axis->LabelAngle;
     LabeledEdit12->Enabled = true;
     break;
   default:   // negative
     RadioGroup1->ItemIndex = 2;
     LabeledEdit10->Color = clWindow;
     LabeledEdit10->Text = Axis->xlab;
     LabeledEdit10->Enabled = true;
     LabeledEdit11->Color = clWindow;
     LabeledEdit11->Text = Axis->ylab;
     LabeledEdit11->Enabled = true;
     LabeledEdit12->Color = clWindow;
     LabeledEdit12->Text = Axis->LabelAngle;
     LabeledEdit12->Enabled = true;
     break;
   };

  //TabSheet4
  ColorBox3->Selected = (TColor)Axis->Color;
  if (ColorBox3->Selected == clBlack)
    ColorBox3->ItemIndex = 1;

  AxisLineWidthComboBox->SetLineWidth(Axis->LineWidth);
}
//---------------------------------------------------------------------------

void TYaxesForm::ShowAxisLimits(NEWYAXIS *Axis)
{
  TcxCustomGridRecord *AFocusedRecord =
       YaxisGridTableView->Controller->FocusedRecord;

  if (AFocusedRecord->RecordIndex == 0) {
    CheckBox1->Enabled = true;
    if (Axis->AxisAutoMin) {
      CheckBox1->State = cbChecked;
      Edit1->Clear();
      Edit1->Color = clBtnFace;
      Edit1->Enabled = false;
      }
    else {
      CheckBox1->State = cbUnchecked;
      Edit1->Color = clWindow;
      Edit1->Text = Axis->AxisMin;
      Edit1->Enabled = true;
      }

    CheckBox2->Enabled = true;
    if (Axis->AxisAutoMax) {
      CheckBox2->State = cbChecked;
      Edit2->Clear();
      Edit2->Color = clBtnFace;
      Edit2->Enabled = false;
      }
    else {
      CheckBox2->State = cbUnchecked;
      Edit2->Color = clWindow;
      Edit2->Text = Axis->AxisMax;
      Edit2->Enabled = true;
      }

    CheckBox7->Enabled = true;
    if (Axis->DataAutoMin) {
      CheckBox7->State = cbChecked;
      Edit5->Clear();
      Edit5->Color = clBtnFace;
      Edit5->Enabled = false;
      }
    else {
      CheckBox7->State = cbUnchecked;
      Edit5->Color = clWindow;
      Edit5->Text = Axis->DataMin;
      Edit5->Enabled = true;
      }

    CheckBox8->Enabled = true;
    if (Axis->DataAutoMax) {
      CheckBox8->State = cbChecked;
      Edit6->Clear();
      Edit6->Color = clBtnFace;
      Edit6->Enabled = false;
      }
    else {
      CheckBox2->State = cbUnchecked;
      Edit6->Color = clWindow;
      Edit6->Text = Axis->DataMax;
      Edit6->Enabled = true;
      }
    }
  else {
    CheckBox1->Enabled = false;
    CheckBox2->Enabled = false;
    CheckBox1->State = cbGrayed;
    CheckBox2->State = cbGrayed;
    Edit1->Clear();
    Edit1->Color = clBtnFace;
    Edit2->Clear();
    Edit2->Color = clBtnFace;
    Edit1->Enabled = false;
    Edit2->Enabled = false;

    CheckBox7->Enabled = false;
    CheckBox8->Enabled = false;
    CheckBox7->State = cbGrayed;
    CheckBox8->State = cbGrayed;
    Edit5->Clear();
    Edit5->Color = clBtnFace;
    Edit6->Clear();
    Edit6->Color = clBtnFace;
    Edit5->Enabled = false;
    Edit6->Enabled = false;
    }
}
//---------------------------------------------------------------------------

void TYaxesForm::SetAxisOptions(NEWYAXIS *Axis)
{
  double xtemp;
  int itemp;

  // TabSheet1
  if (CheckBox1->State == cbChecked)
    Axis->AxisAutoMin = true;
  else if (CheckBox1->State == cbUnchecked) {
    Axis->AxisAutoMin = false;
    if (TryStrToFloat(Edit1->Text, xtemp))
      Axis->AxisMin = xtemp;
    else
      Axis->AxisAutoMin = true;
    }

  if (CheckBox2->State == cbChecked)
    Axis->AxisAutoMax = true;
  else if (CheckBox2->State == cbUnchecked) {
    Axis->AxisAutoMax = false;
    if (TryStrToFloat(Edit2->Text, xtemp))
      Axis->AxisMax = xtemp;
    else
      Axis->AxisAutoMax = true;
    }

  if (CheckBox7->State == cbChecked)
    Axis->DataAutoMin = true;
  else if (CheckBox7->State == cbUnchecked) {
    Axis->DataAutoMin = false;
    if (TryStrToFloat(Edit5->Text, xtemp))
      Axis->DataMin = xtemp;
    else
      Axis->DataAutoMin = true;
    }

  if (CheckBox8->State == cbChecked)
    Axis->DataAutoMax = true;
  else if (CheckBox8->State == cbUnchecked) {
    Axis->DataAutoMax = false;
    if (TryStrToFloat(Edit6->Text, xtemp))
      Axis->DataMax = xtemp;
    else
      Axis->DataAutoMax = true;
    }

  if (CheckBox3->State == cbChecked)
    Axis->ScaleAutoMin = true;
  else if (CheckBox3->State == cbUnchecked) {
    Axis->ScaleAutoMin = false;
    if (TryStrToFloat(Edit3->Text, xtemp))
      Axis->ScaleMin = xtemp;
    else
      Axis->ScaleAutoMin = true;
    }

  if (CheckBox4->State == cbChecked)
    Axis->ScaleAutoMax = true;
  else if (CheckBox4->State == cbUnchecked) {
    Axis->ScaleAutoMax = false;
    if (TryStrToFloat(Edit4->Text, xtemp))
      Axis->ScaleMax = xtemp;
    else
      Axis->ScaleAutoMax = true;
    }

  // TabSheet2
  if (CheckBox5->State == cbChecked)
    Axis->AutoTic = true;
  else if (CheckBox5->State == cbUnchecked) {
    Axis->AutoTic = false;
    try {
      Axis->MinorTics = LabeledEdit5->Text.ToDouble();
      Axis->MajorTics = LabeledEdit6->Text.ToDouble(); }
    catch (...) {
      Axis->AutoTic = true; }
    }

  Axis->LabelToTicDistance =
    IntlStrToDouble::GetDouble(&(LabeledEdit2->Text), Axis->LabelToTicDistance);

  Axis->TicLabelDivideBy =
    1.0/IntlStrToDouble::GetDouble(&(LabeledEdit3->Text), Axis->TicLabelDivideBy);


  itemp = Axis->TicDecPts;
  try {
    Axis->TicDecPts = StrToInt(LabeledEdit4->Text); }
  catch (...) {
    Axis->TicDecPts = itemp; }

  Axis->MinorTicLength =
    IntlStrToDouble::GetDouble(&(LabeledEdit7->Text), Axis->MinorTicLength);

  Axis->MajorTicLength =
    IntlStrToDouble::GetDouble(&(LabeledEdit8->Text), Axis->MajorTicLength);

  //TabSheet3
  switch (RadioGroup1->ItemIndex)
   {
   case 0:
     Axis->LabelPosition = SIDE;
     Axis->LabelAngle = 90.0;
     break;
   case 1:
     Axis->LabelPosition = TOP;
     Axis->LabelAngle = IntlStrToDouble::GetDouble(&(LabeledEdit12->Text), 45.0);
     break;
   case 2:       // user defined
     Axis->LabelPosition = -1*abs(Axis->LabelPosition);
     try {
       Axis->xlab = LabeledEdit10->Text.ToDouble();
       Axis->ylab = LabeledEdit11->Text.ToDouble(); }
     catch (...) {
       Axis->LabelPosition = abs(Axis->LabelPosition); }
     Axis->LabelAngle = IntlStrToDouble::GetDouble(&(LabeledEdit12->Text), 45.0);
     break;
   };

  //TabSheet4
  double LineWidth;
  LineWidth = AxisLineWidthComboBox->GetLineWidth();

  // Apply to all axes
  if (CheckBox6->Checked) {
    NEWYAXIS *Axis1;
    for (int i=0; i<YaxesList->Count; i++) {
      Axis1 = (NEWYAXIS*)YaxesList->Yaxes[i];
      Axis1->Color = ColorBox3->Selected;
      Axis1->LineWidth = LineWidth;
      }
    }
  else {
    Axis->Color = ColorBox3->Selected;
    Axis->LineWidth = LineWidth;
    }
}

//---------------------------------------------------------------------------
// Ok button
void __fastcall TYaxesForm::Button1Click(TObject *Sender)
{
  int i;
  NEWYAXIS *Axis;
  bool Secondary;
  double xtemp;

  Diag->Modified = true;
  Axis = FocusedAxis();
  SetAxisOptions(Axis);

  // set global options

  for (i=0; i<YaxesList->Count; i++) {
    Axis = (NEWYAXIS*)YaxesList->Yaxes[i];
    switch (RadioGroup2->ItemIndex){
      case 0: Axis->AxisStyle = STANDARD_AXIS; break;
      case 1: Axis->AxisStyle = COLUMN_AXIS; break;
      case 2: Axis->AxisStyle = NAMES_AXIS; break;
      };

    Axis->AxisLength =
      IntlStrToDouble::GetDouble(&(LabeledEdit1->Text), Axis->AxisLength);
    Axis->XaxisDistance =
      IntlStrToDouble::GetDouble(&(LabeledEdit13->Text), Axis->XaxisDistance);
    Axis->SpaceRight =
       IntlStrToDouble::GetDouble(&(LabeledEdit14->Text), Axis->SpaceRight);
    }

  if (Diag->YAxes->Count > 0) {
     for (int i=0; i<Diag->YAxes->Count; i++) {
       NEWYAXIS *Yaxis = (NEWYAXIS*)Diag->YAxes->Items[i];
       delete Yaxis;
       Diag->YAxes->Items[i] = 0;
       }
     Diag->YAxes->Clear();
     }

  if (YaxesList->Count > 0) {
    for (int i=0; i<YaxesList->Count; i++) {
      NEWYAXIS *Yaxis = new NEWYAXIS(YaxesList->Yaxes[i]);
      Diag->YAxes->Add(Yaxis);
      }
    }

  //------------------

  NEWYAXIS *Axis1 = (NEWYAXIS*)Diag->YAxes->Items[0];
  // make axis 1 the primary axis
  Axis1->AxisType = PRIMARY_AXIS;
  Axis1->AutoAxisMinMax();  // here is the problem
  Axis1->Calc_yfac();

  Secondary = false;
  for (int i=1; i<Diag->YAxes->Count; i++) {
    Axis = (NEWYAXIS*)Diag->YAxes->Items[i];
    Axis->AxisType = SECONDARY_AXIS;
    Axis->AxisMin = Axis1->AxisMin;
    Axis->AxisMax = Axis1->AxisMax;
    Axis->DataMin = Axis1->DataMin;
    Axis->DataMax = Axis1->DataMax;
    if (Axis->Plot) Secondary = true;
    Axis->Calc_yfac();
    }

  // if there are secondary axes, make sure axis 1 is on
  if (Secondary) Axis1->Plot = true;

}
//---------------------------------------------------------------------------

// up arrow button
void __fastcall TYaxesForm::cxButton1Click(TObject *Sender)
{
   int row;
   TcxCustomGridRecord *AFocusedRecord =
	  YaxisGridTableView->Controller->FocusedRecord;
   row = AFocusedRecord->RecordIndex;
   if (row > 0) {
	 YaxesList->Exchange(row, row-1);
	 YaxisGridTableView->Controller->FocusedRecordIndex = row-1;
	 FocusControl(YaxisGrid);
	 }
   else
     Beep();
}
//---------------------------------------------------------------------------

// down arrow button
void __fastcall TYaxesForm::cxButton2Click(TObject *Sender)
{
   int row;
   TcxCustomGridRecord *AFocusedRecord =
	  YaxisGridTableView->Controller->FocusedRecord;
   row = AFocusedRecord->RecordIndex;
   if (row < YaxesList->Count-1) {
	 YaxesList->Exchange(row, row+1);
	 YaxisGridTableView->Controller->FocusedRecordIndex = row+1;
	 FocusControl(YaxisGrid);
	 }
   else
     Beep();
}
//---------------------------------------------------------------------------

void __fastcall TYaxesForm::FormDeactivate(TObject *Sender)
{
  delete YaxesList;
  delete YaxisDataSource;
}
//---------------------------------------------------------------------------

void __fastcall TYaxesForm::YaxisGridTableViewFocusedRecordChanged(
      TcxCustomGridTableView *Sender,
      TcxCustomGridRecord *APrevFocusedRecord,
      TcxCustomGridRecord *AFocusedRecord,
      bool ANewItemRecordFocusingChanged)
{
    if (APrevFocusedRecord) {
      NEWYAXIS *Axis = YaxesList->Yaxes[APrevFocusedRecord->RecordIndex];
      SetAxisOptions(Axis);
      }
    if (AFocusedRecord) {
      NEWYAXIS *Yaxis = YaxesList->Yaxes[AFocusedRecord->RecordIndex];
      ShowAxisOptions(Yaxis);
	  cxPageControl1->Enabled = Yaxis->Plot;
      cxPageControl1->Visible = Yaxis->Plot;
      }
}
//---------------------------------------------------------------------------

NEWYAXIS* TYaxesForm::FocusedAxis()
{
   TcxCustomGridRecord *AFocusedRecord =
      YaxisGridTableView->Controller->FocusedRecord;
   return((NEWYAXIS*)YaxesList->Yaxes[AFocusedRecord->RecordIndex]);
}
//---------------------------------------------------------------------------

// Axis Limits: Automatic Minimum
void __fastcall TYaxesForm::CheckBox1Click(TObject *Sender)
{
  if (!Activated) return;

  if (CheckBox1->State == cbChecked) {
    Edit1->Color = clBtnFace;
    Edit1->Clear();
    Edit1->Enabled = false;
    }
  else if (CheckBox1->State == cbUnchecked) {
    Edit1->Color = clWindow;
    Edit1->Text = FocusedAxis()->AxisMin;
    Edit1->Enabled = true;
    }
}
//---------------------------------------------------------------------------

void __fastcall TYaxesForm::CheckBox7Click(TObject *Sender)
{
  if (!Activated) return;

  if (CheckBox7->State == cbChecked) {
    Edit5->Color = clBtnFace;
    Edit5->Clear();
    Edit5->Enabled = false;
    }
  else if (CheckBox7->State == cbUnchecked) {
    Edit5->Color = clWindow;
    Edit5->Text = FocusedAxis()->AxisMin;
    Edit5->Enabled = true;
    }
}
//---------------------------------------------------------------------------

// Axis Limits: Automatic Maximum
void __fastcall TYaxesForm::CheckBox2Click(TObject *Sender)
{
  if (!Activated) return;

  if (CheckBox2->State == cbChecked) {
    Edit2->Color = clBtnFace;
    Edit2->Clear();
    Edit2->Enabled = false;
    }
  else if (CheckBox2->State == cbUnchecked) {
    Edit2->Color = clWindow;
    Edit2->Text = FocusedAxis()->AxisMax;
    Edit2->Enabled = true;
    }
}
//---------------------------------------------------------------------------

void __fastcall TYaxesForm::CheckBox8Click(TObject *Sender)
{
  if (!Activated) return;

  if (CheckBox8->State == cbChecked) {
    Edit6->Color = clBtnFace;
    Edit6->Clear();
    Edit6->Enabled = false;
    }
  else if (CheckBox8->State == cbUnchecked) {
    Edit6->Color = clWindow;
    Edit6->Text = FocusedAxis()->AxisMax;
    Edit6->Enabled = true;
    }
}
//---------------------------------------------------------------------------

// Scale Limits: Automatic Minimum
void __fastcall TYaxesForm::CheckBox3Click(TObject *Sender)
{
  if (!Activated) return;
  if (CheckBox3->State == cbChecked) {
    Edit3->Color = clBtnFace;
    Edit3->Clear();
    Edit3->Enabled = false;
    }
  else if (CheckBox3->State == cbUnchecked) {
    Edit3->Color = clWindow;
    Edit3->Text = FocusedAxis()->ScaleMin;
    Edit3->Enabled = true;
    }
}
//---------------------------------------------------------------------------

// Scale Limits: Automatic Maximum
void __fastcall TYaxesForm::CheckBox4Click(TObject *Sender)
{
  if (!Activated) return;
  if (CheckBox4->State == cbChecked) {
    Edit4->Color = clBtnFace;
    Edit4->Clear();
    Edit4->Enabled = false;
    }
  else if (CheckBox4->State == cbUnchecked) {
    Edit4->Color = clWindow;
    Edit4->Text = FocusedAxis()->ScaleMax;
    Edit4->Enabled = true;
    }
}
//---------------------------------------------------------------------------

// Step size
void __fastcall TYaxesForm::CheckBox5Click(TObject *Sender)
{
  if (!Activated) return;
  if (CheckBox5->State == cbChecked) {
    LabeledEdit5->Color = clBtnFace;
    LabeledEdit5->Clear();
    LabeledEdit5->Enabled = false;
    LabeledEdit6->Color = clBtnFace;
    LabeledEdit6->Clear();
    LabeledEdit6->Enabled = false;
    }
  else if (CheckBox5->State == cbUnchecked) {
    LabeledEdit5->Color = clWindow;
    LabeledEdit5->Text = FocusedAxis()->MinorTics;
    LabeledEdit5->Enabled = true;
    LabeledEdit6->Color = clWindow;
    LabeledEdit6->Text = FocusedAxis()->MajorTics;
    LabeledEdit6->Enabled = true;
    }
}
//---------------------------------------------------------------------------

// tic mark label font
void __fastcall TYaxesForm::cxButton3Click(TObject *Sender)
{
   TFontDialogBox* FontForm = new TFontDialogBox(this);
   FontForm->SetFont(FocusedAxis()->TicFont);
   if (FontForm->ShowModal() == mrOk)
	 FontForm->GetFont(FocusedAxis()->TicFont);
   delete FontForm;
}
//---------------------------------------------------------------------------

// axis label position
void __fastcall TYaxesForm::RadioGroup1Click(TObject *Sender)
{
  if (RadioGroup1->ItemIndex == 0) {
    LabeledEdit10->Clear();
    LabeledEdit10->Color = clBtnFace;
    LabeledEdit10->Enabled = false;
    LabeledEdit11->Clear();
    LabeledEdit11->Color = clBtnFace;
    LabeledEdit11->Enabled = false;
    LabeledEdit12->Clear();
    LabeledEdit12->Color = clBtnFace;
    LabeledEdit12->Enabled = false;
    }
  if (RadioGroup1->ItemIndex == 1) {
    LabeledEdit10->Clear();
    LabeledEdit10->Color = clBtnFace;
    LabeledEdit10->Enabled = false;
    LabeledEdit11->Clear();
    LabeledEdit11->Color = clBtnFace;
    LabeledEdit11->Enabled = false;
    LabeledEdit12->Color = clWindow;
    LabeledEdit12->Text = FocusedAxis()->LabelAngle;
    LabeledEdit12->Enabled = true;
    }
  else if (RadioGroup1->ItemIndex == 2) {
    LabeledEdit10->Text = FocusedAxis()->xlab;
    LabeledEdit10->Color = clWindow;
    LabeledEdit10->Enabled = true;
    LabeledEdit11->Text = FocusedAxis()->ylab;
    LabeledEdit11->Color = clWindow;
    LabeledEdit11->Enabled = true;
    LabeledEdit12->Color = clWindow;
    LabeledEdit12->Text = FocusedAxis()->LabelAngle;
    LabeledEdit12->Enabled = true;
    }
}
//---------------------------------------------------------------------------

// axis color
void __fastcall TYaxesForm::ColorBox3Change(TObject *Sender)
{
   FocusedAxis()->Color = ColorBox3->Selected;
}
//---------------------------------------------------------------------------

void __fastcall TYaxesForm::yaPlotPropertiesChange(TObject *Sender)
{
   cxPageControl1->Visible = ((TcxCheckBox*)Sender)->Checked;
   cxPageControl1->Enabled = ((TcxCheckBox*)Sender)->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TYaxesForm::cxButton4Click(TObject *Sender)
{
   TFontDialogBox* FontForm = new TFontDialogBox(this);
   FontForm->SetFont(FocusedAxis()->LabelFont);
   if (FontForm->ShowModal() == mrOk)
	 FontForm->GetFont(FocusedAxis()->LabelFont);
   delete FontForm;
}
//---------------------------------------------------------------------------

void __fastcall TYaxesForm::Button3Click(TObject *Sender)
{
   Application->HelpContext(IDH_Yaxis_Dialog_Box);
}
//---------------------------------------------------------------------------

bool __fastcall TYaxesForm::FormHelp(WORD Command, int Data, bool &CallHelp)
{
   return true;
}
//---------------------------------------------------------------------------

