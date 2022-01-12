//---------------------------------------------------------------------------

#include <vcl.h>
#include "pch.h"
#pragma hdrstop

#include "TGTxtFrm.h"
#include "TGGreek.h"
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
#pragma link "cxButtonEdit"
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
TTextForm *TextForm;

//---------------------------------------------------------------------------
void TTextLineList::ReleaseAllTextLines()
{
  for (int i = 0; i < Count; i++)
    ReleaseTextLine(i);
}
//---------------------------------------------------------------------------

void TTextLineList::ReleaseTextLine(int AIndex)
{
  delete (TEXTLINE*)Items[AIndex];
}
//---------------------------------------------------------------------------

TEXTLINE* TTextLineList::GetTextLine(int AIndex)
{
  return (TEXTLINE*)Items[AIndex];
}
//---------------------------------------------------------------------------

void __fastcall TTextLineList::Notify(void * Ptr, TListNotification Action)
{
  if (FOnNotify != NULL)
    FOnNotify(Ptr, Action);
}
//---------------------------------------------------------------------------

void __fastcall TTextLineList::Clear(void)
{
  ReleaseAllTextLines();
}
//---------------------------------------------------------------------------

void TTextLineList::Add(TEXTLINE* TextLine)
{
  TList::Add(TextLine);
}
//---------------------------------------------------------------------------

void TTextLineList::Delete(int AIndex)
{
  ReleaseTextLine(AIndex);
  TList::Delete(AIndex);
}
//---------------------------------------------------------------------------

void TTextLineList::Insert(int AIndex, TEXTLINE* TextLine)
{
  TList::Insert(AIndex, TextLine);
}
//---------------------------------------------------------------------------

__fastcall TTextLineDataSource::TTextLineDataSource(TTextLineList* ATextLineList)
{
  FTextLines = ATextLineList;
  FTextLines->OnNotify = Notify;
  TempTextLine = NULL;
}
//---------------------------------------------------------------------------

void __fastcall TTextLineDataSource::DeleteRecord(void * ARecordHandle)
{
  FTextLines->Delete((int)ARecordHandle);
}
//---------------------------------------------------------------------------

int __fastcall TTextLineDataSource::GetRecordCount(void)
{
  return(FTextLines->Count);
}
//---------------------------------------------------------------------------

Variant __fastcall TTextLineDataSource::GetValue(void * ARecordHandle, void * AItemHandle)
{
  // displays value in grid based on stored data
  int AColumnId = GetDefaultItemID((int)AItemHandle);
  TEXTLINE* TextLine = FTextLines->TextLines[(int)ARecordHandle];
  Variant Result;
  switch (AColumnId) {
    case IndexOftlText:
      Result = TextLine->Text;
      break;
    case IndexOftlXCoord:
      if (IsNan(TextLine->x))
		Result.ChangeType(varEmpty);
      else
        Result = TextLine->x;
      break;
    case IndexOftlYCoord:
      if (IsNan(TextLine->y))
        Result.ChangeType(varEmpty);
      else
        Result = TextLine->y;
      break;
    case IndexOftlAngle:
      Result = TextLine->angle;
      break;
  }
  return (Result);
}
//---------------------------------------------------------------------------

void __fastcall TTextLineDataSource::Notify(void * Ptr, TListNotification Action)
{
  DataChanged();
}
//---------------------------------------------------------------------------

void * __fastcall TTextLineDataSource::InsertRecord(void * ARecordHandle)
{
  TEXTLINE* TextLine;

  if (TempTextLine) {
    TextLine = new TEXTLINE(TempTextLine);
    delete TempTextLine;
    TempTextLine = NULL;
    }
  else
    TextLine = new TEXTLINE();

  FTextLines->Insert((int)ARecordHandle, TextLine);
  TcxDataRecordHandle* Result = (TcxDataRecordHandle*)ARecordHandle;
  return (Result);
}
//---------------------------------------------------------------------------

void * __fastcall TTextLineDataSource::AppendRecord(void)
{
  TEXTLINE* TextLine;

  TcxDataRecordHandle* Result = (TcxDataRecordHandle*)FTextLines->Count;
  if (TempTextLine) {
    TextLine = new TEXTLINE(TempTextLine);
    delete TempTextLine;
    TempTextLine = NULL;
    }
  else
    TextLine = new TEXTLINE();
  FTextLines->Add(TextLine);
  return (Result);
}
//---------------------------------------------------------------------------

void __fastcall TTextLineDataSource::SetValue(void * ARecordHandle, void * AItemHandle, const Variant &AValue)
{
  // gets values from grid and stores them
  int AColumnId = GetDefaultItemID((int)AItemHandle);
  TEXTLINE* TextLine = FTextLines->TextLines[(int)ARecordHandle];
  switch (AColumnId) {
	case IndexOftlText:
	  TextLine->Text = VarToStr(AValue);
	  break;
    case IndexOftlXCoord:
	  if (AValue.IsNull())
		TextLine->x = NaN;
      else
        TextLine->x = AValue;
      break;
	case IndexOftlYCoord:
	  if (AValue.IsNull())
        TextLine->y = NaN;
      else
        TextLine->y = AValue;
      break;
    case IndexOftlAngle:
	  if (AValue.IsNull())
        TextLine->angle = 0;
      else
        TextLine->angle = AValue;
      break;
  }
}

//---------------------------------------------------------------------------
__fastcall TTextForm::TTextForm(TComponent* Owner)
        : TForm(Owner)
{
   Diag = (TTGDiagram*)Owner;
}
//---------------------------------------------------------------------------

void __fastcall TTextForm::FormCreate(TObject *Sender)
{
   InitialItem = -1; // nothing selected interactively
}
//---------------------------------------------------------------------------
   
void __fastcall TTextForm::FormActivate(TObject *Sender)
{
   PageControl1->ActivePage = TabSheet1;

   for (int i=0; i<4; i++)
     HeadActive[i] = false;
   FootActive = false;

   for (int i=0; i<4; i++)
     HFont[i] = Diag->heading[i].Font;
   FFont = Diag->footer.Font;

   Edit1->Text = Diag->heading[0].Text;
   Edit1->Font->Name = Diag->heading[0].Font.FontName;
   Edit1->Font->Color = (TColor)Diag->heading[0].Font.Color;
   Edit2->Text = Diag->heading[1].Text;
   Edit2->Font->Name = Diag->heading[1].Font.FontName;
   Edit2->Font->Color = (TColor)Diag->heading[1].Font.Color;
   Edit3->Text = Diag->heading[2].Text;
   Edit3->Font->Name = Diag->heading[2].Font.FontName;
   Edit3->Font->Color = (TColor)Diag->heading[2].Font.Color;
   Edit4->Text = Diag->heading[3].Text;
   Edit4->Font->Name = Diag->heading[3].Font.FontName;
   Edit4->Font->Color = (TColor)Diag->heading[3].Font.Color;

   if (Diag->heading[0].AutoX) {
     CheckBox1->Checked = true;
     Edit7->Color = clBtnFace;
     Edit7->Enabled = false;
     }
   else {
     CheckBox1->Checked = false;
     Edit7->Color = clWindow;
     Edit7->Text = FormatFloat("0.0#", Diag->heading[0].x);
     }
   if (Diag->heading[0].AutoY) {
     CheckBox2->Checked = true;
     Edit8->Color = clBtnFace;
     Edit8->Enabled = false;
     }
   else {
     CheckBox2->Checked = false;
     Edit8->Color = clWindow;
     Edit8->Text = FormatFloat("0.0#", Diag->heading[0].y);
     }

   Edit5->Text = Diag->footer.Text;
   if (Diag->footer.AutoX) {
     CheckBox3->Checked = true;
     Edit9->Color = clBtnFace;
     Edit9->Enabled = false;
     }
   else {
     CheckBox3->Checked = false;
     Edit9->Color = clWindow;
     Edit9->Text = FormatFloat("0.0#", Diag->footer.x);
     }
   if (Diag->footer.AutoY) {
     CheckBox4->Checked = true;
     Edit10->Color = clBtnFace;
     Edit10->Enabled = false;
     }
   else {
     CheckBox4->Checked = false;
     Edit10->Color = clWindow;
     Edit10->Text = FormatFloat("0.0#", Diag->footer.y);
     }

   StaticText1->Caption =
      "Left = "     + FormatFloat("0.0#", Diag->Picture->MinExtentX()) +
      ", Right = "   + FormatFloat("0.0#", Diag->Picture->MaxExtentX()) +
      ",   Bottom = " + FormatFloat("0.0#", Diag->Picture->MinExtentY()) +
      ", Top = "   + FormatFloat("0.0#", Diag->Picture->MaxExtentY());

    // Tabsheet 2

    TextLineList = new TTextLineList();
    TextLineDataSource = new TTextLineDataSource(TextLineList);
    GenerateTextLineColumns();
    LoadTextLineData();

    if (InitialItem < 1) {
      PageControl1->ActivePageIndex = 0;
      if (InitialItem == -1)
        FocusControl(Edit1);
      else
        FocusControl(Edit5);
      }
    else {
      PageControl1->ActivePageIndex = 1;
      FocusControl(RandTextGrid);
      RandTextGridTableView->Controller->FocusedRecordIndex = InitialItem-1;
      }

    curpos = 0;
    Screen->Cursor = crDefault;
}
//---------------------------------------------------------------------------

void __fastcall TTextForm::GenerateTextLineColumns()
{
   tlText->DataBinding->Data = (TObject*)IndexOftlText;
   tlXCoord->DataBinding->Data = (TObject*)IndexOftlXCoord;
   tlYCoord->DataBinding->Data = (TObject *)IndexOftlYCoord;
   tlAngle->DataBinding->Data = (TObject*)IndexOftlAngle;
   // this line is critical
   RandTextGridTableView->DataController->CustomDataSource = TextLineDataSource;
}
//---------------------------------------------------------------------------

void __fastcall TTextForm::LoadTextLineData()
{
  for (int i=0; i<Diag->RandomText->Count; i++) {
    TEXTLINE *TextLine = new TEXTLINE((TEXTLINE*)Diag->RandomText->Items[i]);
    TextLineList->Add(TextLine);
    }
  RandTextGridTableView->DataController->GotoFirst();
}
//---------------------------------------------------------------------------

void __fastcall TTextForm::FormDeactivate(TObject *Sender)
{
  delete TextLineList;
  delete TextLineDataSource;
}
//---------------------------------------------------------------------------

// Ok button
void __fastcall TTextForm::Button11Click(TObject *Sender)
{
   Diag->Modified = true;
   for (int i=0; i<4; i++)
     Diag->heading[i].Font = HFont[i];
   Diag->footer.Font = FFont;

   Diag->heading[0].Text = Edit1->Text;
   Diag->heading[1].Text = Edit2->Text;
   Diag->heading[2].Text = Edit3->Text;
   Diag->heading[3].Text = Edit4->Text;

   Diag->heading[0].AutoX = CheckBox1->Checked;
   if (!CheckBox1->Checked) {
     try {
       Diag->heading[0].x = Edit7->Text.ToDouble(); }
     catch (...) {
       Diag->heading[0].AutoX = true; }
     }

   Diag->heading[0].AutoY = CheckBox2->Checked;
   if (!CheckBox2->Checked) {
     try {
       Diag->heading[0].y = Edit8->Text.ToDouble(); }
     catch (...) {
       Diag->heading[0].AutoY = true; }
     }

   Diag->footer.AutoX = CheckBox3->Checked;
   if (!CheckBox3->Checked) {
     try {
       Diag->footer.x = Edit9->Text.ToDouble(); }
     catch (...) {
       Diag->footer.AutoX = true; }
     }

   Diag->footer.AutoY = CheckBox4->Checked;
   if (!CheckBox4->Checked) {
     try {
       Diag->footer.y = Edit10->Text.ToDouble(); }
     catch (...) {
       Diag->footer.AutoY = true; }
     }

   Diag->footer.Text = Edit5->Text;

   // delete old random text
   if (Diag->RandomText->Count > 0) {
     for (int i=0; i<Diag->RandomText->Count; i++) {
       TEXTLINE *TextLine = (TEXTLINE*)Diag->RandomText->Items[i];
       delete TextLine;
       Diag->RandomText->Items[i] = 0;
       }
     Diag->RandomText->Clear();
     Diag->RandomText->Capacity = 100;
     }

   // new random text
   if (TextLineList->Count > 0) {
     for (int i=0; i<TextLineList->Count; i++) {
       TEXTLINE* TextLine = (TEXTLINE*)TextLineList->TextLines[i];
       if (!TextLine->Text.IsEmpty() && !IsNan(TextLine->x) && !IsNan(TextLine->y)) {
         TextLine = new TEXTLINE(TextLineList->TextLines[i]);
         Diag->RandomText->Add(TextLine);
         }
       }
     }
}
//---------------------------------------------------------------------------

void __fastcall TTextForm::CheckBox1Click(TObject *Sender)
{
   DeactivateText();
   if (CheckBox1->Checked) {
     Edit7->Clear();
     Edit7->Color = clBtnFace;
     Edit7->Enabled = false;
     }
   else {
     Edit7->Color = clWindow;
     if (Diag->heading[0].x > -1000000.0)
       Edit7->Text = FormatFloat("0.0#", Diag->heading[0].x);
     Edit7->Enabled = true;
     }
}
//---------------------------------------------------------------------------

void __fastcall TTextForm::CheckBox2Click(TObject *Sender)
{
   DeactivateText();
   if (CheckBox2->Checked) {
     Edit8->Clear();
     Edit8->Color = clBtnFace;
     Edit8->Enabled = false;
     }
   else {
     Edit8->Color = clWindow;
     if (Diag->heading[0].y > -1000000.0)
       Edit8->Text = FormatFloat("0.0#", Diag->heading[0].y);
     Edit8->Enabled = true;
     }
}
//---------------------------------------------------------------------------

void __fastcall TTextForm::CheckBox3Click(TObject *Sender)
{
    DeactivateText();
    if (CheckBox3->Checked) {
     Edit9->Clear();
     Edit9->Color = clBtnFace;
     Edit9->Enabled = false;
     }
   else {
     Edit9->Color = clWindow;
     if (Diag->footer.x > -1000000.0)
       Edit9->Text = FormatFloat("0.0#", Diag->footer.x);
     Edit9->Enabled = true;
     }
}
//---------------------------------------------------------------------------

void __fastcall TTextForm::CheckBox4Click(TObject *Sender)
{
    DeactivateText();
    if (CheckBox4->Checked) {
     Edit10->Clear();
     Edit10->Color = clBtnFace;
     Edit10->Enabled = false;
     }
   else {
     Edit10->Color = clWindow;
     if (Diag->footer.x > -1000000.0)
       Edit10->Text = FormatFloat("0.0#", Diag->footer.y);
     Edit10->Enabled = true;
     }
}

//---------------------------------------------------------------------------

void __fastcall TTextForm::BitBtn3Click(TObject *Sender)
{
   DeactivateText();
   TFontDialogBox* FontForm = new TFontDialogBox(this);
   FontForm->SetFont(HFont[0]);
   if (FontForm->ShowModal() == mrOk) {
	 FontForm->GetFont(HFont[0]);
	 Edit1->Font->Name = HFont[0].FontName;
     Edit1->Font->Color = (TColor)HFont[0].Color;
     }
   delete FontForm;
}
//---------------------------------------------------------------------------

void __fastcall TTextForm::BitBtn9Click(TObject *Sender)
{
   DeactivateText();
   TFontDialogBox* FontForm = new TFontDialogBox(this);
   FontForm->SetFont(HFont[1]);
   if (FontForm->ShowModal() == mrOk) {
     FontForm->GetFont(HFont[1]);
	 Edit2->Font->Name = HFont[1].FontName;
     Edit2->Font->Color = (TColor)HFont[1].Color;
     }
   delete FontForm;
}
//---------------------------------------------------------------------------

void __fastcall TTextForm::BitBtn10Click(TObject *Sender)
{
   DeactivateText();
   TFontDialogBox* FontForm = new TFontDialogBox(this);
   FontForm->SetFont(HFont[2]);
   if (FontForm->ShowModal() == mrOk) {
     FontForm->GetFont(HFont[2]);
	 Edit3->Font->Name = HFont[2].FontName;
     Edit3->Font->Color = (TColor)HFont[2].Color;
     }
   delete FontForm;
}
//---------------------------------------------------------------------------

void __fastcall TTextForm::BitBtn11Click(TObject *Sender)
{
   DeactivateText();
   TFontDialogBox* FontForm = new TFontDialogBox(this);
   FontForm->SetFont(HFont[3]);
   if (FontForm->ShowModal() == mrOk) {
     FontForm->GetFont(HFont[3]);
	 Edit4->Font->Name = HFont[3].FontName;
     Edit4->Font->Color = (TColor)HFont[3].Color;
     }
   delete FontForm;
}
//---------------------------------------------------------------------------

void __fastcall TTextForm::BitBtn12Click(TObject *Sender)
{
   DeactivateText();
   TFontDialogBox* FontForm = new TFontDialogBox(this);
   FontForm->SetFont(FFont);
   if (FontForm->ShowModal() == mrOk) {
     FontForm->GetFont(FFont);
     Edit5->Font->Name = FFont.FontName;
     Edit5->Font->Color = (TColor)FFont.Color;
     }
   delete FontForm;
}
//---------------------------------------------------------------------------

void TTextForm::DeactivateText(void)
{
   for (int i=0; i<4; i++)
     HeadActive[i] = false;
   FootActive = false;
}
//---------------------------------------------------------------------------

void __fastcall TTextForm::Edit1Enter(TObject *Sender)
{
   DeactivateText();
   HeadActive[0] = true;
}
//---------------------------------------------------------------------------

void __fastcall TTextForm::Edit2Enter(TObject *Sender)
{
   DeactivateText();
   HeadActive[1] = true;
}
//---------------------------------------------------------------------------

void __fastcall TTextForm::Edit3Enter(TObject *Sender)
{
   DeactivateText();
   HeadActive[2] = true;
}
//---------------------------------------------------------------------------

void __fastcall TTextForm::Edit4Enter(TObject *Sender)
{
   DeactivateText();
   HeadActive[3] = true;
}
//---------------------------------------------------------------------------


void __fastcall TTextForm::Edit5Enter(TObject *Sender)
{
   DeactivateText();
   FootActive = true;
}
//---------------------------------------------------------------------------

void __fastcall TTextForm::Edit7Enter(TObject *Sender)
{
   DeactivateText();
}
//---------------------------------------------------------------------------

void __fastcall TTextForm::Edit8Enter(TObject *Sender)
{
   DeactivateText();
}
//---------------------------------------------------------------------------

void __fastcall TTextForm::Edit9Enter(TObject *Sender)
{
   DeactivateText();
}
//---------------------------------------------------------------------------

void __fastcall TTextForm::Edit10Enter(TObject *Sender)
{
   DeactivateText();
}
//---------------------------------------------------------------------------

// this for TabSheet1
void TTextForm::ToggleStyle(int Style)
{
  UnicodeString Text;
  TEdit *Edit;

  if (HeadActive[0])
    Edit = Edit1;
  else if (HeadActive[1])
    Edit = Edit2;
  else if (HeadActive[2])
    Edit = Edit3;
  else if (HeadActive[3])
    Edit = Edit4;
  else if (FootActive)
    Edit = Edit5;
  else
    return;

  if (Edit->SelLength < 1) {
	MessageDlg("Must highlight at least one charcter.", Dialogs::mtError,
         TMsgDlgButtons() << mbOK, 0);
    return;
    }

  Text = Edit->Text;

  int curpos = Edit->SelStart;
  int Advance = 0;
  FormatString(Text, Style, curpos, Edit->SelLength, &Advance);

  Edit->Text = Text;
  FocusControl(Edit);
  Edit->SelLength = 0;
  Edit->SelStart = curpos+Advance;
}
//---------------------------------------------------------------------------

void __fastcall TTextForm::HbtnBoldClick(TObject *Sender)
{
   ToggleStyle(BOLD);
}
//---------------------------------------------------------------------------

void __fastcall TTextForm::HBtnItalicClick(TObject *Sender)
{
   ToggleStyle(ITALIC);
}
//---------------------------------------------------------------------------

void __fastcall TTextForm::HBtnSuperClick(TObject *Sender)
{
   ToggleStyle(SUPERSCRIPT);
}
//---------------------------------------------------------------------------


void __fastcall TTextForm::HBtnSubClick(TObject *Sender)
{
   ToggleStyle(SUBSCRIPT);     
}
//---------------------------------------------------------------------------

void __fastcall TTextForm::HBtnGreekClick(TObject *Sender)
{
  if (HeadActive[0])
    InsertGreek(Edit1);
  else if (HeadActive[1])
    InsertGreek(Edit2);
  else if (HeadActive[2])
    InsertGreek(Edit3);
  else if (HeadActive[3])
    InsertGreek(Edit4);
  else if (FootActive)
    InsertGreek(Edit5);
}
//---------------------------------------------------------------------------

void TTextForm::InsertGreek(TEdit* Edit)
{
  int SelStart = Edit->SelStart;
  GreekForm = new TGreekForm(this);
  if (GreekForm->ShowModal() == mrOk) {
    if (GreekForm->StaticText1->Caption.Length() > 0) {
       UnicodeString Buff = Edit->Text;
       Buff.Insert(GreekForm->StaticText1->Caption, Edit->SelStart+1);
       Edit->Text = Buff;
       FocusControl(Edit);
	   Edit->SelLength = 0;
       Edit->SelStart = SelStart+GreekForm->StaticText1->Caption.Length();
       }
    }
  delete GreekForm;
}
//---------------------------------------------------------------------------

// this for TabSheet2, Greek style
void TTextForm::ToggleStyle2(UnicodeString Style)
{
  FocusControl(RandTextGrid);
  tlText->Editing = true;
  if (RandTextGridTableView->Controller->EditingController->Edit) {
	UnicodeString Text = ((TcxTextEdit*)RandTextGridTableView->Controller->EditingController->Edit)->EditingText;
	Text.Insert(Style, curpos+1);
	((TcxTextEdit*)RandTextGridTableView->Controller->EditingController->Edit)->EditingText = Text;
    FocusControl(RandTextGrid);
    }
}
//---------------------------------------------------------------------------

void TTextForm::ToggleStyle2(int Style)
{
  int HoldCurPos = curpos;
  FocusControl(RandTextGrid);
  tlText->Editing = true;
  curpos = HoldCurPos;
  if (RandTextGridTableView->Controller->EditingController->Edit) {
    if (curpos < 0) {
      curpos = ((TcxTextEdit*)RandTextGridTableView->Controller->EditingController->Edit)->SelStart;
      SelLen = ((TcxTextEdit*)RandTextGridTableView->Controller->EditingController->Edit)->SelLength;
      }

    if (SelLen == 0) {
	  MessageDlg("Must highlight at least one charcter.", Dialogs::mtError,
         TMsgDlgButtons() << mbOK, 0);
      return;
      }

    UnicodeString Text = ((TcxTextEdit*)RandTextGridTableView->Controller->EditingController->Edit)->EditingText;

    int Advance = 0;
    FormatString(Text, Style, curpos, SelLen, &Advance);

    int HoldCurPos = curpos;
    ((TcxTextEdit*)RandTextGridTableView->Controller->EditingController->Edit)->EditingText = Text;
    RandTextGridTableView->DataController->Post();
    curpos = -1;

    FocusControl(RandTextGrid);

    tlText->Editing = false;
    tlText->Editing = true;
    if (HoldCurPos > -1)
      ((TcxTextEdit*)RandTextGridTableView->Controller->EditingController->Edit)->SelStart =
        HoldCurPos + Advance;
    }
}
//---------------------------------------------------------------------------

void __fastcall TTextForm::BitBtn4Click(TObject *Sender)
{
   ToggleStyle2(BOLD);
}
//---------------------------------------------------------------------------

void __fastcall TTextForm::BitBtn5Click(TObject *Sender)
{
   ToggleStyle2(ITALIC);
}
//---------------------------------------------------------------------------

void __fastcall TTextForm::BitBtn6Click(TObject *Sender)
{
   ToggleStyle2(SUPERSCRIPT);
}
//---------------------------------------------------------------------------

void __fastcall TTextForm::BitBtn7Click(TObject *Sender)
{
   ToggleStyle2(SUBSCRIPT);
}
//---------------------------------------------------------------------------

void __fastcall TTextForm::BitBtn8Click(TObject *Sender)
{
   GreekForm = new TGreekForm(this);
   if (GreekForm->ShowModal() == mrOk) {
     if (GreekForm->StaticText1->Caption.Length() > 0) {
       ToggleStyle2(GreekForm->StaticText1->Caption);
       }
     }
   delete GreekForm;
}
//---------------------------------------------------------------------------

void __fastcall TTextForm::TabSheet2Enter(TObject *Sender)
{
   FocusControl(RandTextGrid);
}
//---------------------------------------------------------------------------

void __fastcall TTextForm::tlFontPropertiesButtonClick(TObject *Sender,
      int AButtonIndex)
{
   TEXTLINE* TextLine;

   TcxCustomGridRecord *AFocusedRecord =
       RandTextGridTableView->Controller->FocusedRecord;

   if (AFocusedRecord->RecordIndex == -1) {
     TextLineDataSource->TempTextLine = new TEXTLINE();
     TextLine = TextLineDataSource->TempTextLine;
     }
   else
     TextLine = TextLineList->TextLines[AFocusedRecord->RecordIndex];

   TFontDialogBox* FontForm = new TFontDialogBox(this);
   FontForm->SetFont(TextLine->Font);
   if (FontForm->ShowModal() == mrOk) 
     FontForm->GetFont(TextLine->Font);
   delete FontForm;
}
//---------------------------------------------------------------------------

void __fastcall TTextForm::RandTextGridTableViewFocusedItemChanged(
      TcxCustomGridTableView *Sender,
      TcxCustomGridTableItem *APrevFocusedItem,
      TcxCustomGridTableItem *AFocusedItem)
{
   if (AFocusedItem->Index == 0) {
     BitBtn4->Enabled = true;
     BitBtn5->Enabled = true;
     BitBtn6->Enabled = true;
     BitBtn7->Enabled = true;
     BitBtn8->Enabled = true;
     }
   else {
     BitBtn4->Enabled = false;
     BitBtn5->Enabled = false;
     BitBtn6->Enabled = false;
     BitBtn7->Enabled = false;
     BitBtn8->Enabled = false;
     }
}
//---------------------------------------------------------------------------

void __fastcall TTextForm::Button13Click(TObject *Sender)
{
   Application->HelpContext(IDH_Text_Dialog_Box);
}
//---------------------------------------------------------------------------

bool __fastcall TTextForm::FormHelp(WORD Command, int Data, bool &CallHelp)
{
   return true;
}
//---------------------------------------------------------------------------

void __fastcall TTextForm::tlTextGetDisplayText(
      TcxCustomGridTableItem *Sender, TcxCustomGridRecord *ARecord,
	  UnicodeString &AText)
{
   if (RandTextGridTableView->Controller->EditingController->Edit) {
     if (RandTextGridTableView->Controller->EditingController->Edit->IsFocused) {
       if (RandTextGridTableView->Controller->EditingController->EditingItem->Index == 0) {
         curpos = ((TcxTextEdit*)RandTextGridTableView->Controller->EditingController->Edit)->CursorPos;
         SelLen = ((TcxTextEdit*)RandTextGridTableView->Controller->EditingController->Edit)->SelLength;
         }
       }
     }
}
//---------------------------------------------------------------------------

void __fastcall TTextForm::RandTextGridTableViewEditKeyUp(
      TcxCustomGridTableView *Sender, TcxCustomGridTableItem *AItem,
      TcxCustomEdit *AEdit, WORD &Key, TShiftState Shift)
{
   if (AItem->Index == 0) {
     curpos = ((TcxTextEdit*)RandTextGridTableView->Controller->EditingController->Edit)->CursorPos;
     SelLen = ((TcxTextEdit*)RandTextGridTableView->Controller->EditingController->Edit)->SelLength;
     }
}
//---------------------------------------------------------------------------

void __fastcall TTextForm::tlXCoordPropertiesValidate(TObject *Sender,
      Variant &DisplayValue, TCaption &ErrorText, bool &Error)
{
   ValidateNumericalDisplayValue(DisplayValue, ErrorText, Error);
}
//---------------------------------------------------------------------------

void __fastcall TTextForm::tlYCoordPropertiesValidate(TObject *Sender,
      Variant &DisplayValue, TCaption &ErrorText, bool &Error)
{
   ValidateNumericalDisplayValue(DisplayValue, ErrorText, Error);
}
//---------------------------------------------------------------------------

void __fastcall TTextForm::tlAnglePropertiesValidate(TObject *Sender,
      Variant &DisplayValue, TCaption &ErrorText, bool &Error)
{
   ValidateNumericalDisplayValue(DisplayValue, ErrorText, Error);
}
//---------------------------------------------------------------------------

