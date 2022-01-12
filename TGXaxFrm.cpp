//---------------------------------------------------------------------------

#include <vcl.h>
#include "pch.h"
#pragma hdrstop

#include "TGXaxFrm.h"
#ifndef TGSelVarH
#include "TGSelVar.h"
#endif
#ifndef TGStyleH
#include "TGStyle.h"
#endif
#ifndef TGParentH
#include "TGParent.h"
#endif
#ifndef TGUtilsH
#include "TGUtils.h"
#endif
#ifndef TGFntDlgH
#include "TGFntDlg.h"
#endif
#include "TGHelp.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TXaxesForm *XaxesForm;
//---------------------------------------------------------------------------
__fastcall TXaxesForm::TXaxesForm(TComponent* Owner)
        : TForm(Owner)
{
   Diag = (TTGDiagram*)Owner;
}

//---------------------------------------------------------------------------

void __fastcall TXaxesForm::FormCreate(TObject *Sender)
{
   Spawned = false;
   VarCount = 0;

   LabeledEdit4->EditLabel->Height = 26;
   LabeledEdit4->EditLabel->Width = 111;
   LabeledEdit4->EditLabel->WordWrap = true;

   PageControl1->ActivePage = TabSheet1;
   AxisLineWidthComboBox = new LineWidthComboBox(LineWidthComboBox1);
   GridLineWidthComboBox = new LineWidthComboBox(LineWidthComboBox2);
}
//---------------------------------------------------------------------------

void __fastcall TXaxesForm::FormDestroy(TObject *Sender)
{
   delete AxisLineWidthComboBox;
   delete GridLineWidthComboBox;
}
//---------------------------------------------------------------------------

void __fastcall TXaxesForm::FormActivate(TObject *Sender)
{
   Activated = false;
   if (Spawned)
     InitializeForm();
   else if (!InitialVar.IsEmpty()) {
     int i, index;
     UnicodeString VarName;

     MakeVarList();

     for (i=0; i<Diag->grf->Count; i++) {
       GRAPH *g = (GRAPH*)Diag->grf->Items[i];
       if (g->code == InitialVar) {
          VarName = g->name;
          break;
          }
        }

     // remove italics toggle
     while ( (index = VarName.Pos("\\i")) != 0)
        VarName.Delete(index, 2);

     for (i=0; i<VarCount; i++)
       if (VarName == VarList[i].VarName) {
         VarList[i].Checked = true;
         break;
         }

     InitializeForm();
     }
   else if (VarCount == 0)
     MakeVarList();

   Cancel = false;
   Activated = true;
}
//---------------------------------------------------------------------------

void TXaxesForm::MakeVarList(void)
{
   int index;
   int k = 0;

   StaticText1->Caption = "No variables selected";

   VarList = new FORMVARLIST [Diag->grf->Count];
   for (int i=0; i<Diag->grf->Count; i++) {

     GRAPH *g = (GRAPH*)Diag->grf->Items[i];
     if (! Diag->PlottedGraph(g)) continue;

     UnicodeString VarName = g->name;
     // remove italics toggle
     while ( (index = VarName.Pos("\\i")) != 0)
       VarName.Delete(index, 2);

     // Replace Sigma with SUM
     if (VarName.SubString(1,5) == "\\g\xD3\\g") {
       VarName.Delete(1, 5);
       VarName.Insert("SUM ", 1);
       }

     VarList[k].Checked = false;
     VarList[k].VarName = VarName;
     VarList[k++].VarNum = i;
     }
   VarCount = k;
   VarsChecked = 0;
}

//---------------------------------------------------------------------------
// Select Variables button
void __fastcall TXaxesForm::Button2Click(TObject *Sender)
{
  int i;

  NoChange = true;
  SelectVariableForm = new TSelectVariableForm(this);

  for (i=0; i<VarCount; i++)
    SelectVariableForm->CheckListBox1->Items->Add(VarList[i].VarName);

  for (i=0; i<VarCount; i++)
    SelectVariableForm->CheckListBox1->Checked[i] = VarList[i].Checked;

  if (SelectVariableForm->ShowModal() == mrOk) {
    for (i=0; i<SelectVariableForm->CheckListBox1->Items->Count; i++)
      VarList[i].Checked = SelectVariableForm->CheckListBox1->Checked[i];
    }

  delete SelectVariableForm;

  InitializeForm();
}

//---------------------------------------------------------------------------
void TXaxesForm::Spawn(FORMVARLIST *vl, int vc, TStyleForm *SForm)
{
   VarList = vl;
   VarCount = vc;
   Button2->Enabled = false;
   StyleForm = SForm;
   Spawned = true;
}
//---------------------------------------------------------------------------

void TXaxesForm::SetInitialVar(UnicodeString& Code)
{
   InitialVar = Code;
}
//---------------------------------------------------------------------------

void TXaxesForm::InitializeForm(void)
{
  int i;
  GRAPH* g;

  VarsChecked = 0;
  int CheckedVar;
  int FirstVar = -1;
  for (i=0; i<VarCount; i++)
    if (VarList[i].Checked) {
      if (FirstVar < 0) FirstVar = i;
      CheckedVar = i;
      VarsChecked++;
      }

  if (VarsChecked == 0) {
    StaticText1->Caption = "No variables selected";
    InitOptions(&Diag->Default.Xaxis);
    }
  else if (VarsChecked == VarCount) {
    StaticText1->Caption = "All variables selected";
    MultipleOptions();
    }
  else if (VarsChecked == 1) {
    StaticText1->Caption = VarList[CheckedVar].VarName;
    g = (GRAPH*)Diag->grf->Items[VarList[CheckedVar].VarNum];
    InitOptions(g->xax);
    }
  else {
    StaticText1->Caption = IntToStr(VarsChecked) + " variables selected";
    MultipleOptions();
    }

  if (VarsChecked > 0) {
    RadioGroup1->Enabled = true;
    NoChange = true;
    if (X.ShowGraphWidth && X.xax.GraphWidth > 0.0)
      Edit1->Text = FloatToStr(X.xax.GraphWidth);
    else
      Edit1->Text = "";

    if (X.ShowXfac && X.xax.ScaleFactor > 0.0)
      Edit2->Text = FloatToStr(X.xax.ScaleFactor);
    else
      Edit2->Text = "";

    if (!X.ShowAxisLength) {
      RadioGroup1->ItemIndex = -1;
      Edit1->Color = clBtnFace;
      Edit2->Color = clBtnFace;
      }
    else if (X.xax.AutoScaleFactor) {
      RadioGroup1->ItemIndex = 0;
      Edit1->Color = clBtnFace;
      Edit2->Color = clBtnFace;
      }
    else if (X.xax.GraphWidth >= 0) {
      RadioGroup1->ItemIndex = 1;
      Edit1->Enabled = true;
      Edit1->Color = clWindow;
      Edit2->Color = clBtnFace;
      }
    else {
      RadioGroup1->ItemIndex = 2;
      Edit2->Enabled = true;
      Edit1->Color = clBtnFace;
      Edit2->Color = clWindow;
      }

    CheckBox1->Enabled = true;
    if (CheckBox1->AllowGrayed)
      CheckBox1->State = cbGrayed;
    else
      CheckBox1->Checked = X.xax.AutoMin;
    if (X.xax.AutoMin || CheckBox1->AllowGrayed) {
      Edit3->Enabled = false;
      Edit3->Color = clBtnFace;
      }
    else {
      Edit3->Enabled = true;
      Edit3->Color = clWindow;
      }

    CheckBox2->Enabled = true;
    if (CheckBox2->AllowGrayed)
      CheckBox2->State = cbGrayed;
    else
      CheckBox2->Checked = X.xax.AutoMax;
    if (X.xax.AutoMax || CheckBox2->AllowGrayed) {
      Edit4->Enabled = false;
      Edit4->Color = clBtnFace;
      }
    else {
      Edit4->Enabled = true;
      Edit4->Color = clWindow;
      }

    if (!X.xax.AutoMin && X.ShowAutoMin)
      Edit3->Text = FloatToStr(X.xax.XaxisMin);
    else
      Edit3->Clear();
    if (!X.xax.AutoMax && X.ShowAutoMax)
      Edit4->Text = FloatToStr(X.xax.XaxisMax);
    else
      Edit4->Clear();

    Edit5->Enabled = true;
    if (X.ShowAxisLabel)
      Edit5->Text = X.xax.AxisLabel;
    else
      Edit5->Clear();

    BitBtn2->Enabled = true;

    LineWidthComboBox1->Enabled = true;

    if (!X.ShowLineWidth)
      LineWidthComboBox1->Text = "";
    else 
      AxisLineWidthComboBox->SetLineWidth(X.xax.AxisLineWidth);

    ColorBox2->Enabled = true;
    if (X.ShowAxisColor) {
      ColorBox2->Selected = (TColor)X.xax.Color;
      if (ColorBox2->Selected == clBlack)
        ColorBox2->ItemIndex = 1;
      }

    LabeledEdit4->Enabled = true;
    if (X.ShowBetweenGrf)
      LabeledEdit4->Text = FloatToStr(X.xax.DistanceToNextGraph);
    else
      LabeledEdit4->Clear();

    CheckBox3->Enabled = true;
    if (CheckBox3->AllowGrayed)
      CheckBox3->State = cbGrayed;
    else
      CheckBox3->Checked = X.xax.AutoTic;

    LabeledEdit1->Clear();
    LabeledEdit2->Clear();
    LabeledEdit3->Clear();
    if (!CheckBox3->Checked && CheckBox3->State != cbGrayed) {
      LabeledEdit1->Enabled = true;
      LabeledEdit2->Enabled = true;
      LabeledEdit3->Enabled = true;
      LabeledEdit1->Color = clWindow;
      LabeledEdit2->Color = clWindow;
      LabeledEdit3->Color = clWindow;
      if (X.ShowMinorTics)
        LabeledEdit1->Text = FloatToStr(X.xax.MinorTics);
      if (X.ShowMajorTics)
        LabeledEdit2->Text = FloatToStr(X.xax.MajorTics);
      if (X.ShowLabelledTics)
        LabeledEdit3->Text = FloatToStr(X.xax.LabeledTics);
      }
    
    LabeledEdit5->Clear();
    LabeledEdit6->Clear();
    LabeledEdit7->Clear();
    LabeledEdit5->Enabled = true;
    if (X.ShowLenMinorTic)
      LabeledEdit5->Text = FloatToStr(X.xax.MinorTicLength);
    LabeledEdit6->Enabled = true;
    if (X.ShowLenMajorTic)
      LabeledEdit6->Text = FloatToStr(X.xax.MajorTicLength);
    LabeledEdit7->Enabled = true;
    if (X.ShowLenTopTic)
      LabeledEdit7->Text = FloatToStr(X.xax.TopTicLength);

    LabeledEdit8->Clear();
    LabeledEdit9->Clear();
    LabeledEdit10->Clear();
    LabeledEdit8->Enabled = true;
    if (X.ShowTicLabDist)
      LabeledEdit8->Text = FloatToStr(X.xax.LabelToTicDistance);
    LabeledEdit9->Enabled = true;
    if (X.ShowTicFac)
      LabeledEdit9->Text = FloatToStr(1.0/X.xax.TicLabelDivideBy);
    LabeledEdit10->Enabled = true;
    if (X.ShowTicDec)
      LabeledEdit10->Text = IntToStr(X.xax.TicDecPts);

    CheckBox4->Enabled = true;
    if (CheckBox4->AllowGrayed)
      CheckBox4->State = cbGrayed;
    else
      CheckBox4->Checked = X.xax.LabelOriginTic;

    BitBtn3->Enabled = true;

    RadioGroup3->Enabled = true;
    if (!X.ShowGridLines) {
      RadioGroup3->ItemIndex = -1;
      LineWidthComboBox2->Enabled = false;
      LineWidthComboBox2->Text = "";
      }
    else {
      RadioGroup3->ItemIndex = X.xax.GridLines;
      if (RadioGroup3->ItemIndex == 0)
        LineWidthComboBox2->Enabled = false;
      else {
        LineWidthComboBox2->Enabled = true;
        if (!X.ShowGridLineWidth)
          LineWidthComboBox2->Text = "";
        else
          GridLineWidthComboBox->SetLineWidth(X.xax.GridLineWidth);
        }
      }

    LabeledEdit11->Clear();
    LabeledEdit11->Enabled = true;
    if (X.ShowAngle)
      LabeledEdit11->Text = FloatToStr(X.xax.GraphNameAngle);

    BitBtn4->Enabled = true;

    LabeledEdit12->Clear();
    LabeledEdit13->Clear();
    LabeledEdit12->Enabled = true;
    LabeledEdit13->Enabled = true;
    CheckBox6->Enabled = true;

    if (CheckBox6->AllowGrayed)
      CheckBox6->State = cbGrayed;
    else if (X.ShowXOffSet) {
      if (X.xax.GraphNameXOffset < 0.0)
        CheckBox6->Checked = true;
      else if (X.ShowXOffSet) {
        CheckBox6->Checked = false;
        LabeledEdit12->Text = FloatToStr(X.xax.GraphNameXOffset);
        }
      }

    if (X.ShowYOffSet)
      LabeledEdit13->Text = FloatToStr(X.xax.GraphNameYOffset);

    CheckBox7->Enabled = true;
    if (CheckBox7->AllowGrayed)
      CheckBox7->State = cbGrayed;
    else
      CheckBox7->Checked = X.xax.Truncate;

    if (X.ShowTruncate && X.xax.Truncate) {
      RadioGroup2->Enabled = true;
      if (X.ShowTruncWhere)
        RadioGroup2->ItemIndex = X.xax.TruncateWhere - 1;
      else
        RadioGroup2->ItemIndex = -1;
      PrintTruncValuesMenu();
      }

    NoChange = false;

    Button6->Enabled = true;
    BitBtn1->Enabled = true;
    }
  else {
    RadioGroup1->Enabled = false;
    Edit1->Enabled = false;
    Edit2->Enabled = false;
    Edit1->Clear();
    Edit2->Clear();
    Edit1->Color = clBtnFace;
    Edit2->Color = clBtnFace;
    CheckBox1->Enabled = false;
    CheckBox2->Enabled = false;
    Edit3->Enabled = false;
    Edit4->Enabled = false;
    Edit3->Color = clBtnFace;
    Edit4->Color = clBtnFace;
    Edit3->Clear();
    Edit4->Clear();
    Edit5->Enabled = false;
    BitBtn2->Enabled = false;
    LineWidthComboBox1->Enabled = false;
    ColorBox2->Enabled = false;
    LabeledEdit4->Enabled = false;
    CheckBox3->Enabled = false;
    LabeledEdit1->Enabled = false;
    LabeledEdit2->Enabled = false;
    LabeledEdit3->Enabled = false;
    LabeledEdit1->Color = clBtnFace;
    LabeledEdit2->Color = clBtnFace;
    LabeledEdit3->Color = clBtnFace;
    LabeledEdit8->Enabled = false;
    CheckBox3->Enabled = false;
    LabeledEdit9->Enabled = false;
    LabeledEdit10->Enabled = false;
    LabeledEdit5->Enabled = false;
    LabeledEdit6->Enabled = false;
    LabeledEdit7->Enabled = false;
    BitBtn3->Enabled = false;
    RadioGroup3->Enabled = false;
    LineWidthComboBox2->Enabled = false;
    LabeledEdit11->Enabled = false;
    BitBtn4->Enabled = false;
    LabeledEdit12->Enabled = false;
    LabeledEdit13->Enabled = false;
    CheckBox6->Enabled = false;
    RadioGroup2->Enabled = false;
    CheckBox8->Enabled = false;
    CheckBox9->Enabled = false;
    LabeledEdit14->Enabled = false;
    LabeledEdit14->Color = clBtnFace;
    BitBtn5->Enabled = false;
    Button6->Enabled = false;
    BitBtn1->Enabled = false;
    }
}
//---------------------------------------------------------------------------

void TXaxesForm::PrintTruncValuesMenu(void)
{
   CheckBox8->Enabled = true;
   if (CheckBox8->AllowGrayed) {
     CheckBox8->State = cbGrayed;

     CheckBox9->Enabled = true;
     if (CheckBox9->AllowGrayed)
       CheckBox9->State = cbGrayed;
     else
       CheckBox9->Checked = X.xax.ScaleTruncatedValues;

     LabeledEdit14->Enabled = true;
     LabeledEdit14->Color = clWindow;
     if (X.ShowTruncNdec)
       LabeledEdit14->Text = X.xax.TruncateDecPts;
     else
       LabeledEdit14->Clear();

     BitBtn5->Enabled = true;
     }
   else {
     X.ShowTruncPrinted = true;
     CheckBox8->Checked = X.xax.PrintTruncatedValues;

     if (CheckBox8->Checked) {
       CheckBox9->Enabled = true;
       LabeledEdit14->Enabled = true;
       LabeledEdit14->Color = clWindow;
       BitBtn5->Enabled = true;

       if (CheckBox9->AllowGrayed)
         CheckBox9->State = cbGrayed;
       else
         CheckBox9->Checked = X.xax.ScaleTruncatedValues;

       if (X.ShowTruncNdec)
         LabeledEdit14->Text = X.xax.TruncateDecPts;
       }
     else {
       CheckBox9->Enabled = false;
       LabeledEdit14->Enabled = false;
       LabeledEdit14->Color = clBtnFace;
       LabeledEdit14->Clear();
       BitBtn5->Enabled = false;
       }
     }
}
//---------------------------------------------------------------------------

void TXaxesForm::InitOptions(XAXIS *xax)
{
  X.ShowAxisLength = true;
  X.ShowGraphWidth = true;
  X.ShowXfac = true;
  X.AutoMinChanged = false;
  X.AutoMaxChanged = false;
  X.ShowAutoMin = true;
  X.ShowAutoMax = true;
  X.ShowAxisLabel = true;
  X.ShowLineWidth = true;
  X.ShowAxisColor = true;
  X.ShowBetweenGrf = true;
  X.ShowAutoTic = true;
  X.ShowMinorTics = true;
  X.ShowMajorTics = true;
  X.ShowLabelledTics = true;
  X.ShowLenMajorTic = true;
  X.ShowLenMinorTic = true;
  X.ShowLenTopTic = true;
  X.ShowTicLabDist = true;
  X.ShowTicFac = true;
  X.ShowTicDec = true;
  X.ShowLabelOrigin = true;
  X.ShowGridLines = true;
  X.ShowGridLineWidth = true;
  X.ShowAngle = true;
  X.ShowXOffSet = true;
  X.ShowYOffSet = true;
  X.ShowTruncate = true;
  X.ShowTruncWhere = true;
  X.ShowTruncPrinted = true;
  X.ShowTruncScaled = true;
  X.ShowTruncNdec = true;
  X.xax.AutoScaleFactor = xax->AutoScaleFactor;
  X.xax.GraphWidth = xax->GraphWidth;
  X.xax.ScaleFactor = xax->ScaleFactor;
  X.xax.AutoMin = xax->AutoMin;
  X.xax.AutoMax = xax->AutoMax;
  X.xax.XaxisMin = xax->XaxisMin;
  X.xax.XaxisMax = xax->XaxisMax;
  X.xax.AxisLabel = xax->AxisLabel;
  X.xax.AxisLabelFont = xax->AxisLabelFont;
  X.xax.AxisLineWidth = xax->AxisLineWidth;
  AxisLineWidthComboBox->SetLineWidth(X.xax.AxisLineWidth);
  X.xax.Color = xax->Color;
  X.xax.DistanceToNextGraph = xax->DistanceToNextGraph;
  X.xax.AutoTic = xax->AutoTic;
  X.xax.MinorTics = xax->MinorTics;
  X.xax.MajorTics = xax->MajorTics;
  X.xax.LabeledTics = xax->LabeledTics;
  X.xax.MinorTicLength = xax->MinorTicLength;
  X.xax.MajorTicLength = xax->MajorTicLength;
  X.xax.TopTicLength = xax->TopTicLength;
  X.xax.LabelToTicDistance = xax->LabelToTicDistance;
  X.xax.TicLabelDivideBy = xax->TicLabelDivideBy;
  X.xax.TicDecPts = xax->TicDecPts;
  X.xax.TicFont = xax->TicFont;
  X.xax.LabelOriginTic = xax->LabelOriginTic;
  X.xax.GridLines = xax->GridLines;
  X.xax.GridLineWidth = xax->GridLineWidth;
  GridLineWidthComboBox->SetLineWidth(X.xax.GridLineWidth);
  X.xax.GraphNameAngle = xax->GraphNameAngle;
  X.xax.GraphNameFont = xax->GraphNameFont;
  X.xax.GraphNameXOffset = xax->GraphNameXOffset;
  X.xax.GraphNameYOffset = xax->GraphNameYOffset;
  X.xax.Truncate = xax->Truncate;
  X.xax.TruncateWhere = xax->TruncateWhere;
  X.xax.PrintTruncatedValues = xax->PrintTruncatedValues;
  X.xax.ScaleTruncatedValues = xax->ScaleTruncatedValues;
  X.xax.TruncateDecPts = xax->TruncateDecPts;
  X.xax.TruncFont = xax->TruncFont;
}
//---------------------------------------------------------------------------

void TXaxesForm::MultipleOptions(void)
{
    int i;
    GRAPH *g;

    for (i=0; i<VarCount; i++)
      if (VarList[i].Checked) {
         GRAPH* g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];
         InitOptions(g->xax);
         break;
         }

    int start = i+1;
    X.ShowAxisLength = true;
    for (i=start; i<VarCount; i++) {
      if (VarList[i].Checked) {
        g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];
        if (X.xax.AutoScaleFactor != g->xax->AutoScaleFactor) {
           X.ShowAxisLength = false;
           break; }
        }
      }

    for (i=start; i<VarCount; i++) {
      if (VarList[i].Checked) {
        g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];
        if (X.xax.GraphWidth != g->xax->GraphWidth) {
           X.ShowAxisLength = false;
           X.ShowGraphWidth = false;
           break; }
        }
      }

    for (i=start; i<VarCount; i++) {
      if (VarList[i].Checked) {
        g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];
        if (X.xax.ScaleFactor != g->xax->ScaleFactor) {
           X.ShowAxisLength = false;
           X.ShowXfac = false;
           break; }
        }
      }

    for (i=start; i<VarCount; i++) {
      if (VarList[i].Checked) {
        g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];
        if (X.xax.AutoMin != g->xax->AutoMin) {
           X.xax.AutoMin = false;
           X.ShowAutoMin = false;
           NoChange = true;
           CheckBox1->AllowGrayed = true;
           NoChange = false;
           break; }
        }
      }

    if (!X.xax.AutoMin) {
      for (i=start; i<VarCount; i++) {
        if (VarList[i].Checked) {
          g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];
          if (X.xax.XaxisMin != g->xax->XaxisMin) {
             X.ShowAutoMin = false;
             break; }
          }
        }
      }

    for (i=start; i<VarCount; i++) {
      if (VarList[i].Checked) {
        g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];
        if (X.xax.AutoMax != g->xax->AutoMax) {
           X.xax.AutoMax = false;
           X.ShowAutoMax = false;
           NoChange = true;
           CheckBox2->AllowGrayed = true;
           NoChange = false;
           break; }
        }
      }

    if (!X.xax.AutoMax) {
      for (i=start; i<VarCount; i++) {
        if (VarList[i].Checked) {
          g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];
          if (X.xax.XaxisMax != g->xax->XaxisMax) {
             X.ShowAutoMax = false;
             break; }
          }
        }
      }

    for (i=start; i<VarCount; i++) {
      if (VarList[i].Checked) {
        g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];
        if (X.xax.AxisLabel != g->xax->AxisLabel) {
           X.xax.AxisLabel = "";
           X.ShowAxisLabel = false;
           break; }
        }
      }

    for (i=start; i<VarCount; i++) {
      if (VarList[i].Checked) {
        g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];
        X.xax.AxisLabelFont.Compare(g->xax->AxisLabelFont);
        }
      }

    for (i=start; i<VarCount; i++) {
      if (VarList[i].Checked) {
        g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];
        if (X.xax.AxisLineWidth != g->xax->AxisLineWidth) {
            X.ShowLineWidth = false;
            break; }
        }
      }

    for (i=start; i<VarCount; i++) {
      if (VarList[i].Checked) {
        g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];
        if (X.xax.GridLineWidth != g->xax->GridLineWidth) {
            X.ShowGridLineWidth = false;
            break; }
        }
      }

    for (i=start; i<VarCount; i++) {
      if (VarList[i].Checked) {
        g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];
        if (X.xax.Color != g->xax->Color) {
            X.ShowAxisColor = false;
            break; }
        }
      }

    for (i=start; i<VarCount; i++) {
      if (VarList[i].Checked) {
        g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];
        if (X.xax.DistanceToNextGraph != g->xax->DistanceToNextGraph) {
           X.ShowBetweenGrf = false;
           break; }
        }
      }

    for (i=start; i<VarCount; i++) {
      if (VarList[i].Checked) {
        g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];
        if (X.xax.AutoTic != g->xax->AutoTic) {
           X.ShowAutoTic = false;
           CheckBox3->AllowGrayed = true;
           break; }
        }
      }

    for (i=start; i<VarCount; i++) {
      if (VarList[i].Checked) {
        g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];
        if (X.xax.MinorTics != g->xax->MinorTics) {
           X.ShowMinorTics = false;
           break; }
        }
      }

    for (i=start; i<VarCount; i++) {
      if (VarList[i].Checked) {
        g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];
        if (X.xax.MajorTics != g->xax->MajorTics) {
           X.ShowMajorTics = false;
           break; }
        }
      }

    for (i=start; i<VarCount; i++) {
      if (VarList[i].Checked) {
        g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];
        if (X.xax.LabeledTics != g->xax->LabeledTics) {
           X.ShowLabelledTics = false;
           break; }
        }
      }

    for (i=start; i<VarCount; i++) {
      if (VarList[i].Checked) {
        g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];
        if (X.xax.MinorTicLength != g->xax->MinorTicLength) {
           X.ShowLenMinorTic = false;
           break; }
        }
      }

    for (i=start; i<VarCount; i++) {
      if (VarList[i].Checked) {
        g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];
        if (X.xax.MajorTicLength != g->xax->MajorTicLength) {
           X.ShowLenMajorTic = false;
           break; }
        }
      }

    for (i=start; i<VarCount; i++) {
      if (VarList[i].Checked) {
        g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];
        if (X.xax.TopTicLength != g->xax->TopTicLength) {
           X.ShowLenTopTic = false;
           break; }
        }
      }

    for (i=start; i<VarCount; i++) {
      if (VarList[i].Checked) {
        g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];
        if (X.xax.LabelToTicDistance != g->xax->LabelToTicDistance) {
           X.ShowTicLabDist = false;
           break; }
        }
      }

    for (i=start; i<VarCount; i++) {
      if (VarList[i].Checked) {
        g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];
        if (X.xax.TicLabelDivideBy != g->xax->TicLabelDivideBy) {
           X.ShowTicFac = false;
           break; }
        }
      }

    for (i=start; i<VarCount; i++) {
      if (VarList[i].Checked) {
        g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];
        if (X.xax.TicDecPts != g->xax->TicDecPts) {
           X.ShowTicDec = false;
           break; }
        }
      }

    for (i=start; i<VarCount; i++) {
      if (VarList[i].Checked) {
        g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];
        X.xax.TicFont.Compare(g->xax->TicFont);
        }
      }

    for (i=start; i<VarCount; i++) {
      if (VarList[i].Checked) {
        g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];
        if (X.xax.LabelOriginTic != g->xax->LabelOriginTic) {
           X.ShowLabelOrigin = false;
           CheckBox4->AllowGrayed = true;
           break; }
        }
      }

    for (i=start; i<VarCount; i++) {
      if (VarList[i].Checked) {
        g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];
        if (X.xax.GridLines != g->xax->GridLines) {
           X.ShowGridLines = false;
           break; }
        }
      }

    for (i=start; i<VarCount; i++) {
      if (VarList[i].Checked) {
        g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];
        if (X.xax.GraphNameAngle != g->xax->GraphNameAngle) {
           X.ShowAngle = false;
           break; }
        }
      }

    for (i=start; i<VarCount; i++) {
      if (VarList[i].Checked) {
        g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];
        X.xax.GraphNameFont.Compare(g->xax->GraphNameFont);
        }
      }

    bool center = false;
    for (i=0; i<VarCount; i++) {
      if (VarList[i].Checked) {
        g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];
        if (g->xax->GraphNameXOffset < 0.0) {
           center = true;
           break; }
        }
      }
    if (center) {
      for (i=0; i<VarCount; i++) {
        if (VarList[i].Checked) {
          g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];
          if (g->xax->GraphNameXOffset >= 0.0) {
             NoChange = true;
             CheckBox6->AllowGrayed = true;
             NoChange = false;
             X.ShowXOffSet = false;
             break; }
          }
        }
      }
    else {
      for (i=start; i<VarCount; i++) {
        if (VarList[i].Checked) {
          g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];
          if (X.xax.GraphNameXOffset != g->xax->GraphNameXOffset) {
             X.ShowXOffSet = false;
             break; }
          }
        }
      }

    for (i=start; i<VarCount; i++) {
      if (VarList[i].Checked) {
        g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];
        if (X.xax.GraphNameYOffset != g->xax->GraphNameYOffset) {
           X.ShowYOffSet = false;
           break; }
        }
      }

    for (i=start; i<VarCount; i++) {
      if (VarList[i].Checked) {
        g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];
        if (X.xax.Truncate != g->xax->Truncate) {
           NoChange = true;
           CheckBox7->AllowGrayed = true;
           NoChange = false;
           X.xax.Truncate = false;
           X.ShowTruncate = false;
           break; }
        }
      }

    for (i=start; i<VarCount; i++) {
      if (VarList[i].Checked) {
        g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];
        if (X.xax.TruncateWhere != g->xax->TruncateWhere) {
           X.ShowTruncWhere = false;
           NoChange = true;
           RadioGroup2->ItemIndex = -1;
           NoChange = false;
           break; }
        }
      }

    for (i=start; i<VarCount; i++) {
      if (VarList[i].Checked) {
        g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];
        if (X.xax.PrintTruncatedValues != g->xax->PrintTruncatedValues) {
           NoChange = true;
           CheckBox8->AllowGrayed = true;
           NoChange = false;
           X.ShowTruncPrinted = false;
           break; }
        }
      }

    for (i=start; i<VarCount; i++) {
      if (VarList[i].Checked) {
        g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];
        if (X.xax.ScaleTruncatedValues != g->xax->ScaleTruncatedValues) {
           NoChange = true;
           CheckBox9->AllowGrayed = true;
           NoChange = false;
           X.ShowTruncScaled = false;
           break; }
        }
      }

    for (i=start; i<VarCount; i++) {
      if (VarList[i].Checked) {
        g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];
        if (X.xax.TruncateDecPts != g->xax->TruncateDecPts) {
           X.ShowTruncNdec = false;
           break; }
        }
      }

    for (i=start; i<VarCount; i++) {
      if (VarList[i].Checked) {
        g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];
        X.xax.TruncFont.Compare(g->xax->TruncFont);
        }
      }

    for (i=start; i<VarCount; i++) {
      if (VarList[i].Checked) {
        g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];
        if (X.xax.TruncateDecPts != g->xax->TruncateDecPts) {
           X.ShowTruncNdec = false;
           break; }
        }
      }
}
//---------------------------------------------------------------------------

// Ok button
void __fastcall TXaxesForm::Button3Click(TObject *Sender)
{
   Diag->Modified = true;
   ApplyOptions();

   if (Spawned) {
    Diag->make_diagram();
    Diag->Picture->OutputGraphicObjects(DISPLAY, (TTGDiagram*)ParentForm->ActiveMDIChild);
    }
}
//---------------------------------------------------------------------------

// Apply button
void __fastcall TXaxesForm::Button6Click(TObject *Sender)
{
   Diag->Modified = true;
   ApplyOptions();
   Diag->make_diagram();
   Diag->Picture->OutputGraphicObjects(DISPLAY, (TTGDiagram*)ParentForm->ActiveMDIChild);

   X.ShowXfac = false;
   int n = 0;
   double ScaleFactor;
   for (int i=0; i<VarCount; i++)
     if (VarList[i].Checked) {
       n++;
       GRAPH* g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];

       if (n == 1) {
         ScaleFactor = g->xax->ScaleFactor;
         X.ShowXfac = true;
         if (g->xax->AutoScaleFactor)
           Edit1->Clear();
         }
       else if (ScaleFactor != g->xax->ScaleFactor) {
         X.ShowXfac = false;
         break;
         }
       }
   if (X.ShowXfac)
     Edit2->Text = FloatToStr(ScaleFactor);
   else
     Edit2->Clear();

   if (X.ShowAxisColor) {
      ColorBox2->Selected = (TColor)X.xax.Color;
      if (ColorBox2->Selected == clBlack)
        ColorBox2->ItemIndex = 1;
      }
}
//---------------------------------------------------------------------------

void TXaxesForm::ApplyOptions(void)
{
   int i, iValue;
   GRAPH* g;
   double temp, Value;

   if (VarsChecked == 0) return;
   switch (RadioGroup1->ItemIndex)
    {
     case 0:
       X.xax.AutoScaleFactor = true;
       X.xax.GraphWidth = -1.0;
       break;
     case 1:
       X.xax.AutoScaleFactor = false;
       if (TryStrToFloat(Edit1->Text, Value))
         X.xax.GraphWidth = Value;
       else {
         X.xax.AutoScaleFactor = true;
         X.xax.GraphWidth = -1.0;
         }
       if (X.xax.GraphWidth <= 0) {
         X.xax.AutoScaleFactor = true;
         X.xax.GraphWidth = -1.0;
         }
       break;
     case 2:
       X.xax.AutoScaleFactor = false;
       X.xax.GraphWidth = -1.0;
       temp = X.xax.ScaleFactor;
       if (TryStrToFloat(Edit2->Text, Value))
         X.xax.ScaleFactor = Value;
       else {
         X.xax.AutoScaleFactor = true;
         X.xax.ScaleFactor = temp;
         }
       if (X.xax.ScaleFactor <= 0) {
         X.xax.AutoScaleFactor = true;
         X.xax.ScaleFactor = temp;
         }
       break;
    }

   if (X.AutoMinChanged) {
     X.xax.AutoMin = CheckBox1->Checked;
     if (!X.xax.AutoMin) {
       if (TryStrToFloat(Edit3->Text, Value))
         X.xax.XaxisMin = Value;
       else
         X.xax.AutoMin = true;
       }
     }

   if (X.AutoMaxChanged) {
     X.xax.AutoMax = CheckBox2->Checked;
     if (!X.xax.AutoMax) {
       if (TryStrToFloat(Edit4->Text, Value))
         X.xax.XaxisMax = Value;
       else
         X.xax.AutoMax = true;
       }
     }

   if (X.ShowAxisLabel)
     X.xax.AxisLabel = Edit5->Text;

   if (LineWidthComboBox1->Text.IsEmpty())
     X.ShowLineWidth = false;
   else
     X.xax.AxisLineWidth = AxisLineWidthComboBox->GetLineWidth();

   if (LineWidthComboBox2->Text.IsEmpty() || RadioGroup3->ItemIndex == 0)
     X.ShowGridLineWidth = false;
   else
     X.xax.GridLineWidth = GridLineWidthComboBox->GetLineWidth();

   if (X.ShowBetweenGrf) {
     if (LabeledEdit4->Text.IsEmpty())
       X.xax.DistanceToNextGraph = 0.0;
     else
       X.xax.DistanceToNextGraph =
         IntlStrToDouble::GetDouble(&(LabeledEdit4->Text), X.xax.DistanceToNextGraph);
     }

   if (X.ShowAngle) {
     if (LabeledEdit11->Text.IsEmpty())
       X.xax.GraphNameAngle = 0.0;
     else 
       X.xax.GraphNameAngle =
         IntlStrToDouble::GetDouble(&(LabeledEdit11->Text), X.xax.GraphNameAngle);
     }

   if (X.ShowXOffSet) {
     if (CheckBox6->Checked)
       X.xax.GraphNameXOffset = -1.0;
     else {
       if (LabeledEdit12->Text.IsEmpty())
         X.xax.GraphNameXOffset = 0.0;
       else
         X.xax.GraphNameXOffset =
           IntlStrToDouble::GetDouble(&(LabeledEdit12->Text), X.xax.GraphNameXOffset);
       }
     }

   if (X.ShowYOffSet) {
     if (LabeledEdit13->Text.IsEmpty())
       X.xax.GraphNameYOffset = 0.0;
     else
       X.xax.GraphNameYOffset =
         IntlStrToDouble::GetDouble(&(LabeledEdit13->Text), X.xax.GraphNameYOffset);
     }

   if (X.ShowTruncate) {
     X.xax.Truncate = CheckBox7->Checked;
     if (X.ShowTruncWhere)
       X.xax.TruncateWhere = RadioGroup2->ItemIndex + 1;
     }

   if (X.ShowTruncPrinted)
     X.xax.PrintTruncatedValues = CheckBox8->Checked;

   if (X.ShowTruncScaled && CheckBox9->Enabled)
     X.xax.ScaleTruncatedValues = CheckBox9->Checked;

   if (X.ShowTruncNdec && LabeledEdit14->Enabled) {
     if (LabeledEdit14->Text.IsEmpty())
       X.xax.TruncateDecPts = 0;
     else {
       i = X.xax.TruncateDecPts;
       if (TryStrToInt(LabeledEdit14->Text, iValue))
         X.xax.TruncateDecPts = iValue;
       else {
         X.ShowTruncNdec = false;
         X.xax.TruncateDecPts = i;
         }
       }
     }

   for (i=0; i<VarCount; i++) {
     if (VarList[i].Checked) {
       g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];
       ExecuteOptions(g->xax, g->graph);
       }
     }
   if (VarsChecked == VarCount)
     ExecuteOptions(&Diag->Default.Xaxis, &Diag->Default.Graph);
}
//---------------------------------------------------------------------------

void TXaxesForm::ExecuteOptions(XAXIS *xax, GRAPHS* graph)
{
  if (X.ShowAxisLength) {
    xax->AutoScaleFactor = X.xax.AutoScaleFactor;
    xax->GraphWidth = X.xax.GraphWidth;
    xax->ScaleFactor = X.xax.ScaleFactor;
    }

  if (X.AutoMinChanged) {
    xax->AutoMin = X.xax.AutoMin;
    if (!X.xax.AutoMin) xax->XaxisMin = X.xax.XaxisMin;
    }

  if (X.AutoMaxChanged) {
    xax->AutoMax = X.xax.AutoMax;
    if (!X.xax.AutoMax) xax->XaxisMax = X.xax.XaxisMax;
    }

  if (X.ShowAxisLabel)
    xax->AxisLabel = X.xax.AxisLabel;

  xax->AxisLabelFont = X.xax.AxisLabelFont;

  if (X.ShowLineWidth)
    xax->AxisLineWidth = X.xax.AxisLineWidth;

  if (X.ShowAxisColor)
    xax->Color = X.xax.Color;

  if (X.ShowBetweenGrf)
    xax->DistanceToNextGraph = X.xax.DistanceToNextGraph;

  if (X.ShowAutoTic) {
    xax->AutoTic = X.xax.AutoTic;
    if (!X.xax.AutoTic) {
      if (X.ShowMinorTics) {
        xax->MinorTics = X.xax.MinorTics;
        graph->XPresence = xax->MinorTics;
        if (Spawned)
          StyleForm->PresOpt.XPresence.x = graph->XPresence;
        }
      if (X.ShowMajorTics)
        xax->MajorTics = X.xax.MajorTics;
      if (X.ShowLabelledTics)
        xax->LabeledTics = X.xax.LabeledTics;
      }
    }

  if (X.ShowLenMinorTic)
    xax->MinorTicLength = X.xax.MinorTicLength;
  if (X.ShowLenMajorTic)
    xax->MajorTicLength = X.xax.MajorTicLength;
  if (X.ShowLenTopTic)
    xax->TopTicLength = X.xax.TopTicLength;

  if (X.ShowTicLabDist)
    xax->LabelToTicDistance = X.xax.LabelToTicDistance;
  if (X.ShowTicFac)
    xax->TicLabelDivideBy = 1.0/X.xax.TicLabelDivideBy;
  if (X.ShowTicDec)
    xax->TicDecPts = X.xax.TicDecPts;

  if (X.ShowLabelOrigin)
    xax->LabelOriginTic = X.xax.LabelOriginTic;

  xax->TicFont = X.xax.TicFont;

  if (X.ShowGridLines) {
    xax->GridLines = RadioGroup3->ItemIndex;
    if (X.ShowGridLineWidth)
      xax->GridLineWidth = X.xax.GridLineWidth;
    }

  if (X.ShowAngle)
    xax->GraphNameAngle = X.xax.GraphNameAngle;

  xax->GraphNameFont = X.xax.GraphNameFont;

  if (X.ShowXOffSet)
    xax->GraphNameXOffset = X.xax.GraphNameXOffset;

  if (X.ShowYOffSet)
    xax->GraphNameYOffset = X.xax.GraphNameYOffset;

  if (X.ShowTruncate) {
    xax->Truncate = X.xax.Truncate;
    if (X.xax.Truncate) {
      xax->TruncateWhere = X.xax.TruncateWhere;
      }
    }

  if (X.ShowTruncPrinted)
    xax->PrintTruncatedValues = X.xax.PrintTruncatedValues;

  if (X.ShowTruncScaled && CheckBox9->Enabled)
    xax->ScaleTruncatedValues = X.xax.ScaleTruncatedValues;

  xax->TruncFont = X.xax.TruncFont;

  if (X.ShowTruncNdec && LabeledEdit14->Enabled)
    xax->TruncateDecPts = X.xax.TruncateDecPts;  
}
//---------------------------------------------------------------------------

void __fastcall TXaxesForm::RadioGroup1Click(TObject *Sender)
{
  X.ShowAxisLength = true;
  if (RadioGroup1->ItemIndex == 0) {
    Edit1->Enabled = false;
    Edit2->Enabled = false;
    Edit1->Color = clBtnFace;
    Edit2->Color = clBtnFace;
    Edit1->Clear();
    if (X.ShowXfac && X.xax.ScaleFactor > 0.0)
      Edit2->Text = FloatToStr(X.xax.ScaleFactor);
    }
  else if (RadioGroup1->ItemIndex == 1) {
    Edit1->Enabled = true;
    Edit2->Enabled = false;
    Edit1->Color = clWindow;
    Edit2->Color = clBtnFace;
    Edit2->Clear();
    }
  if (RadioGroup1->ItemIndex == 2) {
    Edit2->Enabled = true;
    Edit1->Enabled = false;
    Edit1->Color = clBtnFace;
    Edit2->Color = clWindow;
    Edit1->Clear();
    if (X.ShowXfac && X.xax.ScaleFactor > 0.0)
      Edit2->Text = FloatToStr(X.xax.ScaleFactor);
    }
}
//---------------------------------------------------------------------------

void __fastcall TXaxesForm::RadioGroup1Exit(TObject *Sender)
{
  if (ActiveControl == CancelButton) return;
  if (ActiveControl == Edit1) return;
  if (ActiveControl == Edit2) return;

  if (RadioGroup1->ItemIndex == 1) {
    if (!CheckFixedWidth())
      FocusControl(RadioGroup1);
    }
  else if (RadioGroup1->ItemIndex == 2) {
    if (!CheckScaleFactor())
      FocusControl(RadioGroup1);
    }
}
//---------------------------------------------------------------------------

void __fastcall TXaxesForm::Edit1Exit(TObject *Sender)
{
  if (ActiveControl == CancelButton) return;
  if (ActiveControl == RadioGroup1) return;
  if (ActiveControl == Edit2) return;

  if (!CheckFixedWidth())
    FocusControl(RadioGroup1);
}
//---------------------------------------------------------------------------

bool TXaxesForm::CheckFixedWidth(void)
{
    if (Edit1->Text.IsEmpty()) {
	  MessageDlg("No value entered for Fixed Width", Dialogs::mtError,
                 TMsgDlgButtons() << mbOK, 0);
      return false;
      }
    double Value;
    if (TryStrToFloat(Edit1->Text, Value))
      X.xax.GraphWidth = Value;
    else {
	  MessageDlg("Error in Fixed Width", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
      return false;
      }
    if (X.xax.GraphWidth <= 0.0) {
      MessageDlg("Fixed Width must be >= 0", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
      return false;
      }
    return true;
}
//---------------------------------------------------------------------------

void __fastcall TXaxesForm::Edit2Exit(TObject *Sender)
{
  if (ActiveControl == CancelButton) return;
  if (ActiveControl == RadioGroup1) return;
  if (ActiveControl == Edit1) return;

  if (!CheckScaleFactor())
    FocusControl(RadioGroup1);
}
//---------------------------------------------------------------------------

bool TXaxesForm::CheckScaleFactor(void)
{
    if (Edit2->Text.IsEmpty()) {
	  MessageDlg("No value entered for Scale Factor", Dialogs::mtError,
                 TMsgDlgButtons() << mbOK, 0);
      return false;
      }
    double Value;
    if (TryStrToFloat(Edit2->Text, Value))
      X.xax.ScaleFactor = Value;
    else {
	  MessageDlg("Error in Scale Factor", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
      return false;
      }
    if (X.xax.ScaleFactor <= 0.0) {
      MessageDlg("Scale Factor must be >= 0", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
      return false;
      }
    return true;
}
//---------------------------------------------------------------------------

void __fastcall TXaxesForm::CheckBox1Click(TObject *Sender)
{
  if (NoChange) return;
  NoChange = true;
  CheckBox1->AllowGrayed = false;
  X.AutoMinChanged = true;
  if (CheckBox1->Checked) {
    Edit3->Clear();
    Edit3->Color = clBtnFace;
    Edit3->Enabled = false;
    }
  else {
    Edit3->Color = clWindow;
    Edit3->Text = FloatToStr(X.xax.XaxisMin);
    Edit3->Enabled = true;
    }
  NoChange = false;
}
//---------------------------------------------------------------------------

void __fastcall TXaxesForm::Edit3Change(TObject *Sender)
{
  if (NoChange) return;
  CheckBox1->AllowGrayed = false;
  X.AutoMinChanged = true;
}
//---------------------------------------------------------------------------

void __fastcall TXaxesForm::CheckBox2Click(TObject *Sender)
{
  if (NoChange) return;
  NoChange = true;
  CheckBox2->AllowGrayed = false;
  X.AutoMaxChanged = true;
  if (CheckBox2->Checked) {
    Edit4->Clear();
    Edit4->Color = clBtnFace;
    Edit4->Enabled = false;
    }
  else {
    Edit4->Text = FloatToStr(X.xax.XaxisMax);
    Edit4->Color = clWindow;
    Edit4->Enabled = true;
    }
  NoChange = false;
}
//---------------------------------------------------------------------------

void __fastcall TXaxesForm::Edit4Change(TObject *Sender)
{
  if (NoChange) return;
  CheckBox2->AllowGrayed = false;
  X.AutoMaxChanged = true;
}
//---------------------------------------------------------------------------

void __fastcall TXaxesForm::BitBtn2Click(TObject *Sender)
{
   TFontDialogBox* FontForm = new TFontDialogBox(this);
   FontForm->SetFont(X.xax.AxisLabelFont);
   if (FontForm->ShowModal() == mrOk)
     FontForm->GetFont(X.xax.AxisLabelFont);
   delete FontForm;
}
//---------------------------------------------------------------------------

void __fastcall TXaxesForm::LineWidthComboBox1Change(TObject *Sender)
{
   X.ShowLineWidth = true;
}
//---------------------------------------------------------------------------

// axis color
void __fastcall TXaxesForm::ColorBox2Change(TObject *Sender)
{
   X.xax.Color = ColorBox2->Selected;
   X.ShowAxisColor = true;
}
//---------------------------------------------------------------------------

void __fastcall TXaxesForm::Edit5Change(TObject *Sender)
{
   if (!NoChange) 
     X.ShowAxisLabel = true;
}
//---------------------------------------------------------------------------

void __fastcall TXaxesForm::LabeledEdit4Change(TObject *Sender)
{
  if (!NoChange)
    X.ShowBetweenGrf = true;
}
//---------------------------------------------------------------------------

void __fastcall TXaxesForm::CheckBox3Click(TObject *Sender)
{
  CheckBox3->AllowGrayed = false;
  X.ShowAutoTic = true;
  bool nchange = NoChange;

  if (CheckBox3->Checked || CheckBox3->State == cbGrayed) {
    NoChange = true;
    LabeledEdit1->Clear();
    LabeledEdit2->Clear();
    LabeledEdit3->Clear();
    NoChange = nchange;
    LabeledEdit1->Enabled = false;
    LabeledEdit2->Enabled = false;
    LabeledEdit3->Enabled = false;
    LabeledEdit1->Color = clBtnFace;
    LabeledEdit2->Color = clBtnFace;
    LabeledEdit3->Color = clBtnFace;
    }
  else {
    LabeledEdit1->Enabled = true;
    LabeledEdit2->Enabled = true;
    LabeledEdit3->Enabled = true;
    LabeledEdit1->Color = clWindow;
    LabeledEdit2->Color = clWindow;
    LabeledEdit3->Color = clWindow;
    if (X.ShowMinorTics)
      LabeledEdit1->Text = FloatToStr(X.xax.MinorTics);
    if (X.ShowMajorTics)
      LabeledEdit2->Text = FloatToStr(X.xax.MajorTics);
    if (X.ShowLabelledTics)
      LabeledEdit3->Text = FloatToStr(X.xax.LabeledTics);
    }
}
//---------------------------------------------------------------------------

void __fastcall TXaxesForm::GroupBox4Exit(TObject *Sender)
{
   double Value;

   if (ActiveControl == CancelButton) return;
   if (X.ShowAutoTic) {
     X.xax.AutoTic = CheckBox3->Checked;
     if (!X.xax.AutoTic) {
       if (X.ShowMinorTics) {
         if (LabeledEdit1->Text.IsEmpty()) {
		   MessageDlg("Minor Tic Marks missing", Dialogs::mtError,
                      TMsgDlgButtons() << mbOK, 0);
           FocusControl(LabeledEdit1);
           return;
           }
         if (TryStrToFloat(LabeledEdit1->Text, Value))
           X.xax.MinorTics = Value;
         else {
		   MessageDlg("Error in Minor Tic Marks", Dialogs::mtError,
                      TMsgDlgButtons() << mbOK, 0);
           FocusControl(LabeledEdit1);
           return;
           }
         if (X.xax.MinorTics <= 0.0) {
           MessageDlg("Minor Tic Marks must be >0", Dialogs::mtError,
                      TMsgDlgButtons() << mbOK, 0);
           FocusControl(LabeledEdit1);
           return;
           }
         }

       if (X.ShowMajorTics) {
         if (LabeledEdit2->Text.IsEmpty()) {
		   MessageDlg("Major Tic Marks missing", Dialogs::mtError,
                      TMsgDlgButtons() << mbOK, 0);
           FocusControl(LabeledEdit2);
           return;
           }
         if (TryStrToFloat(LabeledEdit2->Text, Value))
           X.xax.MajorTics = Value;
         else {
		   MessageDlg("Error in Major Tic Marks", Dialogs::mtError,
                      TMsgDlgButtons() << mbOK, 0);
           FocusControl(LabeledEdit2);
           return;
           }
         if (X.xax.MajorTics <= 0.0) {
           MessageDlg("Major Tic Marks must be >0", Dialogs::mtError,
                      TMsgDlgButtons() << mbOK, 0);
           FocusControl(LabeledEdit2);
           return;
           }
         }

       if (X.ShowLabelledTics) {
         if (LabeledEdit3->Text.IsEmpty()) {
		   MessageDlg("Labelled Tic Marks missing", Dialogs::mtError,
                      TMsgDlgButtons() << mbOK, 0);
           FocusControl(LabeledEdit3);
           return;
           }
         if (TryStrToFloat(LabeledEdit3->Text, Value))
           X.xax.LabeledTics = Value;
         else {
		   MessageDlg("Error in Labelled Tic Marks", Dialogs::mtError,
                      TMsgDlgButtons() << mbOK, 0);
           FocusControl(LabeledEdit3);
           return;
           }
         if (X.xax.LabeledTics <= 0.0) {
           MessageDlg("Labelled Tic Marks must be >0", Dialogs::mtError,
                      TMsgDlgButtons() << mbOK, 0);
           FocusControl(LabeledEdit3);
           return;
           }
         }
       if (X.xax.MajorTics < X.xax.MinorTics) {
		 MessageDlg("Minor Tic Marks must be <= Major Tic Marks", Dialogs::mtError,
                     TMsgDlgButtons() << mbOK, 0);
         FocusControl(LabeledEdit1);
         return;
         }
       if (X.xax.LabeledTics < X.xax.MajorTics) {
         MessageDlg("Labelled Tic Marks must be >= Major Tic Marks", Dialogs::mtError,
                     TMsgDlgButtons() << mbOK, 0);
         FocusControl(LabeledEdit3);
         return;
         }

       }
     }
}
//---------------------------------------------------------------------------

void __fastcall TXaxesForm::LabeledEdit1Change(TObject *Sender)
{
   if (!NoChange)
     X.ShowMinorTics = true;
}
//---------------------------------------------------------------------------

void __fastcall TXaxesForm::LabeledEdit2Change(TObject *Sender)
{
   if (!NoChange)
     X.ShowMajorTics = true;
}
//---------------------------------------------------------------------------

void __fastcall TXaxesForm::LabeledEdit3Change(TObject *Sender)
{
   if (!NoChange)
     X.ShowLabelledTics = true;
}
//---------------------------------------------------------------------------
    
void __fastcall TXaxesForm::GroupBox6Exit(TObject *Sender)
{
   double Value;

   if (ActiveControl == CancelButton) return;
   if (X.ShowLenMinorTic) {
     if (TryStrToFloat(LabeledEdit5->Text, Value))
       X.xax.MinorTicLength = Value;
	 else {
	   MessageDlg("Error in Minor Tic Mark Length", Dialogs::mtError,
         TMsgDlgButtons() << mbOK, 0);
       FocusControl(LabeledEdit5);
       }
     }

   if (X.ShowLenMajorTic) {
     if (TryStrToFloat(LabeledEdit6->Text, Value))
       X.xax.MajorTicLength = Value;
     else {
	   MessageDlg("Error in Major Tic Mark Length", Dialogs::mtError,
         TMsgDlgButtons() << mbOK, 0);
       FocusControl(LabeledEdit6);
       }
     }

   if (X.ShowLenTopTic) {
     if (TryStrToFloat(LabeledEdit7->Text, Value))
       X.xax.TopTicLength = Value;
     else {
       MessageDlg("Error in Top Tic Mark Length", Dialogs::mtError,
         TMsgDlgButtons() << mbOK, 0);
       FocusControl(LabeledEdit7);
       }
     }
}
//---------------------------------------------------------------------------

void __fastcall TXaxesForm::LabeledEdit5Change(TObject *Sender)
{
  if (!NoChange)
    X.ShowLenMinorTic = true;
}
//---------------------------------------------------------------------------

void __fastcall TXaxesForm::LabeledEdit6Change(TObject *Sender)
{
  if (!NoChange)
    X.ShowLenMajorTic = true;
}
//---------------------------------------------------------------------------

void __fastcall TXaxesForm::LabeledEdit7Change(TObject *Sender)
{
  if (!NoChange)
    X.ShowLenTopTic = true;
}
//---------------------------------------------------------------------------

void __fastcall TXaxesForm::GroupBox5Exit(TObject *Sender)
{
   double Value;

   if (ActiveControl == CancelButton) return;

   X.xax.LabelOriginTic = CheckBox4->Checked;
   if (X.ShowTicLabDist) {
     if (TryStrToFloat(LabeledEdit8->Text, Value))
       X.xax.LabelToTicDistance = Value;
     else {
	   MessageDlg("Error in Distance From Tic Mark", Dialogs::mtError,
         TMsgDlgButtons() << mbOK, 0);
       FocusControl(LabeledEdit8);
       }
     }

   if (X.ShowTicFac) {
     if (LabeledEdit9->Text.IsEmpty())
       X.xax.TicLabelDivideBy = 1.0;
     else {
       if (TryStrToFloat(LabeledEdit9->Text, Value))
         X.xax.TicLabelDivideBy = Value;
       else {
		 MessageDlg("Error in Divide by", Dialogs::mtError,
		   TMsgDlgButtons() << mbOK, 0);
         FocusControl(LabeledEdit9);
         }
       }
     if (X.xax.TicLabelDivideBy == 0) X.xax.TicLabelDivideBy = 1.0;
     }

   if (X.ShowTicDec) {
     int iValue;
     if (TryStrToInt(LabeledEdit10->Text, iValue))
       X.xax.TicDecPts = iValue;
     else {
       MessageDlg("Error in Number of Decimal Points", Dialogs::mtError,
         TMsgDlgButtons() << mbOK, 0);
       FocusControl(LabeledEdit10);
       }
     if (X.xax.TicDecPts < 0) X.xax.TicDecPts = 0;
     }
}
//---------------------------------------------------------------------------

void __fastcall TXaxesForm::LabeledEdit8Change(TObject *Sender)
{
  if (!NoChange)
    X.ShowTicLabDist = true;
}
//---------------------------------------------------------------------------

void __fastcall TXaxesForm::LabeledEdit9Change(TObject *Sender)
{
  if (!NoChange)
    X.ShowTicFac = true;
}
//---------------------------------------------------------------------------

void __fastcall TXaxesForm::LabeledEdit10Change(TObject *Sender)
{
  if (!NoChange)
    X.ShowTicDec = true;
}
//---------------------------------------------------------------------------

void __fastcall TXaxesForm::BitBtn3Click(TObject *Sender)
{
   TFontDialogBox* FontForm = new TFontDialogBox(this);
   FontForm->SetFont(X.xax.TicFont);
   if (FontForm->ShowModal() == mrOk)
     FontForm->GetFont(X.xax.TicFont);
   delete FontForm;
}
//---------------------------------------------------------------------------

void __fastcall TXaxesForm::CheckBox4Click(TObject *Sender)
{
  CheckBox4->AllowGrayed = false;
  X.ShowLabelOrigin = true;
}
//---------------------------------------------------------------------------

void __fastcall TXaxesForm::RadioGroup3Click(TObject *Sender)
{
  if (!Activated) return;
  X.ShowGridLines = true;
  LineWidthComboBox2->Enabled = (RadioGroup3->ItemIndex) ? true : false;
  if (!X.ShowGridLineWidth)
    LineWidthComboBox2->Text = "";
  else 
    X.xax.GridLineWidth = GridLineWidthComboBox->GetLineWidth();
}
//---------------------------------------------------------------------------

void __fastcall TXaxesForm::GroupBox1Exit(TObject *Sender)
{
  if (ActiveControl == CancelButton) return;
  if (X.AutoMinChanged) {
    if (!CheckBox1->Checked) {
      double Value;
      if (TryStrToFloat(Edit3->Text, Value))
        X.xax.XaxisMin = Value;
      else {
		MessageDlg("Error in Minimum Axis Limit", Dialogs::mtError,
		  TMsgDlgButtons() << mbOK, 0);
        FocusControl(Edit3);
        }
      }
    }
}
//---------------------------------------------------------------------------

void __fastcall TXaxesForm::GroupBox3Exit(TObject *Sender)
{
   if (ActiveControl == CancelButton) return;
   if (X.AutoMaxChanged) {
     if (!CheckBox2->Checked) {
       double Value;
       if (TryStrToFloat(Edit4->Text, Value))
         X.xax.XaxisMax = Value;
       else {
         MessageDlg("Error in Maximum Axis Limit", Dialogs::mtError,
           TMsgDlgButtons() << mbOK, 0);
         FocusControl(Edit4);
         }
       }
     }
}
//---------------------------------------------------------------------------
  
void __fastcall TXaxesForm::LabeledEdit4Exit(TObject *Sender)
{
  if (ActiveControl == CancelButton) return;
  if (X.ShowBetweenGrf) {
    if (LabeledEdit4->Text.IsEmpty())
      X.xax.DistanceToNextGraph = 0.0;
    else {
      double Value;
      if (TryStrToFloat(LabeledEdit4->Text, Value))
        X.xax.DistanceToNextGraph = Value;
      else {
		MessageDlg("Error in End Space", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
        FocusControl(LabeledEdit4);
        return;
        }
      if (X.xax.DistanceToNextGraph < 0.0) {
        MessageDlg("End Space must be >= 0", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
        FocusControl(LabeledEdit4);
        return;
        }
      }
    }
}
//---------------------------------------------------------------------------

void __fastcall TXaxesForm::BitBtn4Click(TObject *Sender)
{
   TFontDialogBox* FontForm = new TFontDialogBox(this);
   FontForm->SetFont(X.xax.GraphNameFont);
   if (FontForm->ShowModal() == mrOk)
     FontForm->GetFont(X.xax.GraphNameFont);
   delete FontForm;
}
//---------------------------------------------------------------------------

void __fastcall TXaxesForm::GroupBox8Exit(TObject *Sender)
{
   if (ActiveControl == CancelButton) return;

   if (X.ShowAngle) {
     if (LabeledEdit11->Text.IsEmpty())
       X.xax.GraphNameAngle = 0.0;
     else {
       double Value;
       if (TryStrToFloat(LabeledEdit11->Text, Value))
         X.xax.GraphNameAngle = Value;
       else {
		 MessageDlg("Error in Angle", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
         FocusControl(LabeledEdit11);
         return;
         }
       }
     if (X.xax.GraphNameAngle > 90.0 || X.xax.GraphNameAngle < 0.0) {
       MessageDlg("Angle must be between 0 and 90", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
       FocusControl(LabeledEdit11);
       return;
       }
     }
}
//---------------------------------------------------------------------------

void __fastcall TXaxesForm::LabeledEdit11Change(TObject *Sender)
{
  if (!NoChange)
    X.ShowAngle = true;
}
//---------------------------------------------------------------------------
 
void __fastcall TXaxesForm::CheckBox6Click(TObject *Sender)
{
  if (NoChange) return;
  NoChange = true;
  CheckBox6->AllowGrayed = false;
  X.ShowXOffSet = true;
  if (CheckBox6->Checked)
    LabeledEdit12->Clear();
  else
    LabeledEdit12->Text = FloatToStr(Diag->Default.Xaxis.GraphNameXOffset);
  NoChange = false;
}
//---------------------------------------------------------------------------

void __fastcall TXaxesForm::LabeledEdit12Change(TObject *Sender)
{
  if (NoChange) return;
  CheckBox6->AllowGrayed = false;
  X.ShowXOffSet = true;
  NoChange = true;
  CheckBox6->Checked = false;
  NoChange = false;
}
//---------------------------------------------------------------------------

void __fastcall TXaxesForm::LabeledEdit13Change(TObject *Sender)
{
  if (!NoChange)
    X.ShowYOffSet = true;
}
//---------------------------------------------------------------------------

void __fastcall TXaxesForm::GroupBox7Exit(TObject *Sender)
{
   double Value;

   if (ActiveControl == CancelButton) return;

   if (X.ShowXOffSet && !CheckBox6->Checked) {
     if (LabeledEdit12->Text.IsEmpty())
       X.xax.GraphNameXOffset = 0.0;
     else {
       if (TryStrToFloat(LabeledEdit12->Text, Value))
         X.xax.GraphNameXOffset = Value;
       else {
		 MessageDlg("Error in X Offset", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
         FocusControl(LabeledEdit12);
         return;
         }
       }
     if (X.xax.GraphNameXOffset < 0.0) {
	   MessageDlg("X Offset must be >= 0", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
       FocusControl(LabeledEdit12);
       return;
       }
     }

   if (LabeledEdit13->Text.IsEmpty())
     X.xax.GraphNameYOffset = 0.0;
   else {
     if (TryStrToFloat(LabeledEdit13->Text, Value))
       X.xax.GraphNameYOffset = Value;
     else {
	   MessageDlg("Error in Y Offset", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
       FocusControl(LabeledEdit13);
       return;
       }
     }
}
//---------------------------------------------------------------------------

void __fastcall TXaxesForm::CheckBox7Click(TObject *Sender)
{
  if (NoChange) return;
  NoChange = true;
  CheckBox7->AllowGrayed = false;

  X.ShowTruncate = true;
  X.ShowTruncWhere = true;

  if (CheckBox7->Checked) {
    RadioGroup2->Enabled = true;
    if (X.ShowTruncWhere)
      RadioGroup2->ItemIndex = X.xax.TruncateWhere - 1;
    PrintTruncValuesMenu();
    }
  else {
    RadioGroup2->Enabled = false;
    CheckBox8->Enabled = false;
    CheckBox9->Enabled = false;
    LabeledEdit14->Enabled = false;
    LabeledEdit14->Color = clBtnFace;
    BitBtn5->Enabled = false;
    LabeledEdit14->Clear();
    }
  NoChange = false;
}
//---------------------------------------------------------------------------

void __fastcall TXaxesForm::CheckBox8Click(TObject *Sender)
{
  if (NoChange) return;
  NoChange = true;
  CheckBox8->AllowGrayed = false;
  X.xax.PrintTruncatedValues = CheckBox8->Checked;
  PrintTruncValuesMenu();
  NoChange = false;
}
//---------------------------------------------------------------------------

void __fastcall TXaxesForm::CheckBox9Click(TObject *Sender)
{
  if (NoChange) return;
  NoChange = true;
  CheckBox9->AllowGrayed = false;
  X.ShowTruncScaled = true;
  X.xax.ScaleTruncatedValues = CheckBox9->Checked;
  NoChange = false;
}
//---------------------------------------------------------------------------

void __fastcall TXaxesForm::BitBtn5Click(TObject *Sender)
{
   TFontDialogBox* FontForm = new TFontDialogBox(this);
   FontForm->SetFont(X.xax.TruncFont);
   if (FontForm->ShowModal() == mrOk)
     FontForm->GetFont(X.xax.TruncFont);
   delete FontForm;
}
//---------------------------------------------------------------------------

void __fastcall TXaxesForm::BitBtn1Click(TObject *Sender)
{
  if (Spawned) {
    ApplyOptions();
    Diag->make_diagram();
    Diag->Picture->OutputGraphicObjects(DISPLAY, (TTGDiagram*)ParentForm->ActiveMDIChild);
    Close();
    }
  else {
    StyleForm = new TStyleForm(this);
    StyleForm->Diag = Diag;
    StyleForm->Spawn(VarList, VarCount, this);
    StyleForm->ShowModal();
    delete StyleForm;
    }
  if (X.ShowMinorTics)
    LabeledEdit1->Text = FloatToStr(X.xax.MinorTics);
  if (X.ShowMajorTics)
    LabeledEdit2->Text = FloatToStr(X.xax.MajorTics);
  if (X.ShowLabelledTics)
    LabeledEdit3->Text = FloatToStr(X.xax.LabeledTics);
}
//---------------------------------------------------------------------------

void __fastcall TXaxesForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  if (! Spawned) {
    if (VarList != NULL) delete[] VarList;
    VarList = NULL;
    }
}
//---------------------------------------------------------------------------

void __fastcall TXaxesForm::LabeledEdit14Change(TObject *Sender)
{
   if (!NoChange)
     X.ShowTruncNdec = true;
}
//---------------------------------------------------------------------------

void __fastcall TXaxesForm::RadioGroup2Click(TObject *Sender)
{
   if (!NoChange)
     X.ShowTruncWhere = true;
}
//---------------------------------------------------------------------------

void __fastcall TXaxesForm::LineWidthComboBox2Change(TObject *Sender)
{
   X.ShowGridLineWidth = true;
}
//---------------------------------------------------------------------------

void __fastcall TXaxesForm::Edit5Exit(TObject *Sender)
{
   CheckEntityRefs(Edit5);
}
//---------------------------------------------------------------------------

void __fastcall TXaxesForm::Button5Click(TObject *Sender)
{
   Application->HelpContext(IDH_Xaxes_Dialog_Box);
}
//---------------------------------------------------------------------------

bool __fastcall TXaxesForm::FormHelp(WORD Command, int Data, bool &CallHelp)
{
   return true;
}
//---------------------------------------------------------------------------

