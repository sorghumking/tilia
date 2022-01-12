//---------------------------------------------------------------------------
#include <vcl.h>
#include "pch.h"
#pragma hdrstop

#ifndef TGParentH
#include "TGParent.h"
#endif
#include "TGStyle.h"
#ifndef TGSelVarH
#include "TGSelVar.h"
#endif
#ifndef TGPattH
#include "TGPatt.h"
#endif
#ifndef TGXaxFrmH
#include "TGXaxFrm.h"
#endif
#include "TGHelp.h"
#ifndef TGUtilsH
#include "TGUtils.h"
#endif
#ifndef TGFntDlgH
#include "TGFntDlg.h"
#endif

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxMaskEdit"
#pragma link "cxSpinEdit"
#pragma link "cxTextEdit"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
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
#pragma link "cxColorComboBox"
#pragma link "cxDropDownEdit"
#pragma resource "*.dfm"
TStyleForm *StyleForm;

//---------------------------------------------------------------------------
__fastcall TStyleForm::TStyleForm(TComponent* Owner)
        : TForm(Owner)
{
   Diag = (TTGDiagram*)Owner;
}
//---------------------------------------------------------------------------

void __fastcall TStyleForm::FormCreate(TObject *Sender)
{
   Spawned = false;
   VarCount = 0;

   SilhLineWidthComboBox = new LineWidthComboBox(LineWidthComboBox1);
   LiGrLineWidthComboBox = new LineWidthComboBox(LineWidthComboBox2);
   HistLineWidthComboBox = new LineWidthComboBox(LineWidthComboBox3);
   SilOpt.SilhouettePattern = -1;
   SilOpt.ExagPattern = -1;
}
//---------------------------------------------------------------------------

void __fastcall TStyleForm::FormDestroy(TObject *Sender)
{
   delete SilhLineWidthComboBox;
   delete LiGrLineWidthComboBox;
   delete HistLineWidthComboBox;
}
//---------------------------------------------------------------------------

void __fastcall TStyleForm::FormActivate(TObject *Sender)
{
   SelectTabSheet(Diag->Default.Graph.GraphType);

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
}
//---------------------------------------------------------------------------

void TStyleForm::MakeVarList(void)
{
   int index;
   int k = 0;

   StaticText2->Caption = "No variables selected";

   VarList = new FORMVARLIST [Diag->grf->Count];
   for (int i=0; i<Diag->grf->Count; i++) {
     GRAPH *g = (GRAPH*)Diag->grf->Items[i];
     if (g->status == SKIP) continue;

	 UnicodeString TempStr = g->code.SubString(1, 5);
     if (TempStr == "Chron")
       continue;
     if (TempStr == "Depth")
       continue;
     if (TempStr == "Thick")
       continue;
     if (TempStr == "Error")
       continue;

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

void TStyleForm::SelectTabSheet(short GraphType)
{
   switch (GraphType)
   {
   case SILHOUETTE: PageControl1->ActivePage = TabSheet1; break;
   case HISTOGRAM:  PageControl1->ActivePage = TabSheet2; break;
   case LINEGRAPH:  PageControl1->ActivePage = TabSheet3; break;
   case NUMBERS:    PageControl1->ActivePage = TabSheet4; break;
   case PRESENCE:   PageControl1->ActivePage = TabSheet5; break;
   }
}
//---------------------------------------------------------------------------

// Select Graphs button
void __fastcall TStyleForm::Button4Click(TObject *Sender)
{
  int i;

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

void TStyleForm::Spawn(FORMVARLIST *vl, int vc, TXaxesForm *XForm)
{
   VarList = vl;
   VarCount = vc;
   Button4->Enabled = false;
   XaxesForm = XForm;
   Spawned = true;
}
//---------------------------------------------------------------------------

void TStyleForm::SetInitialVar(UnicodeString& Code)
{
   InitialVar = Code;
}

//---------------------------------------------------------------------------
void TStyleForm::InitializeForm(void)
{
  int i;
  GRAPH* g;
  short GraphType;

  SilOpt.TabSheetInitialized = false;
  SilOpt.Exag.show = true;
  SilOpt.SilhouetteLineWidth.show = true;
  SilOpt.GraphColor.show = false;
  SilOpt.GraphOutlineColor.show = false;
  SilOpt.ExagColor.show = false;
  SilOpt.ExagOutlineColor.show = false;
  SilOpt.DepthBarsColor.show = false;

  RadioGroup2->ItemIndex = -1;
  cxSpinEdit1->Value = 0;
  RadioGroup3->ItemIndex = -1;
  RadioGroup1->ItemIndex = -1;
  CheckBox1->Checked = false;
  CheckBox2->Checked = false;
  Shape1->Brush->Bitmap = NULL;
  Shape1->Visible = false;
  Shape2->Brush->Bitmap = NULL;
  Shape2->Visible = false;       
  LineWidthComboBox1->Text = "";

  // Histogram options
  HistOpt.TabSheetInitialized = false;
  RadioGroup6->ItemIndex = 0;
  HistOpt.HistogramLineWidth.show = true;
  LineWidthComboBox3->Text = "";
  HistOpt.BarWidth.show = true;
  HistOpt.GraphColor.show = false;
  cxSpinEdit2->Value = 0.02;
  RadioGroup4->ItemIndex = -1;
  CheckBox3->Checked = false;

  // Line Graph options
  LineOpt.TabSheetInitialized = false;
  LineOpt.LineGraphLineWidth.show = true;
  LineOpt.MarkerSize.show = true;
  LineOpt.XMarkerLabel.show = true;
  LineOpt.YMarkerLabel.show = true;
  LineOpt.AngleMarkerLabel.show = true;
  LineOpt.GraphColor.show = false;
  LineWidthComboBox2->Text = "";

  LabeledEdit3->Text = "";
  LabeledEdit4->Text = "";
  LabeledEdit5->Text = "";
  LabeledEdit9->Text = "";
  CheckBox4->Checked = false;
  CheckBox5->Checked = false;
  CheckBox7->Checked = false;

  // Number Graph options
  CheckBox8->Checked = false;
  NumOpt.TabSheetInitialized = false;
  NumOpt.DecimalPoints.show = true;
  cxSpinEdit3->Value = 0;

  // Presence Graph options
  PresOpt.TabSheetInitialized = false;
  PresOpt.MarkerSize.show = true;
  PresOpt.XPresence.show = true;
  PresOpt.GraphColor.show = false;
  LabeledEdit7->Text = "";
  LabeledEdit8->Text = "";
  CheckBox6->Checked = false;

  //--------------------

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
    StaticText2->Caption = "No variables selected";
    InitSilhouetteOptions(&Diag->Default.Graph);
    InitHistogramOptions(&Diag->Default.Graph);
    InitLineGraphOptions(&Diag->Default.Graph, &Diag->Default.Xaxis);
    InitNumberOptions(&Diag->Default.Graph);
    InitPresenceOptions(&Diag->Default.Graph);
    GraphType = Diag->Default.Graph.GraphType;
    }
  else if (VarsChecked == VarCount) {
    StaticText2->Caption = "All variables selected";
    MultipleSilhouetteOptions();
    MultipleHistogramOptions();
    MultipleLineGraphOptions();
    MultipleNumberOptions();
    MultiplePresenceOptions();
    g = (GRAPH*)Diag->grf->Items[VarList[FirstVar].VarNum];
    GraphType = g->graph->GraphType;
    }
  else if (VarsChecked == 1) {
    StaticText2->Caption = VarList[CheckedVar].VarName;
    g = (GRAPH*)Diag->grf->Items[VarList[CheckedVar].VarNum];
    InitSilhouetteOptions(g->graph);
    InitHistogramOptions(g->graph);
    InitLineGraphOptions(g->graph, g->xax);
    InitNumberOptions(g->graph);
    InitPresenceOptions(g->graph);
    GraphType = g->graph->GraphType;
    }
  else {
    StaticText2->Caption = IntToStr(VarsChecked) + " variables selected";
    MultipleSilhouetteOptions();
    MultipleHistogramOptions();
    MultipleLineGraphOptions();
    MultipleNumberOptions();
    MultiplePresenceOptions();
    g = (GRAPH*)Diag->grf->Items[VarList[FirstVar].VarNum];
    GraphType = g->graph->GraphType;
    }

  if (VarsChecked > 0) {
     InitSilhouetteTabSheet();
     RadioGroup2->Enabled = true;
     cxSpinEdit1->Enabled = true;
     RadioGroup3->Enabled = true;
     CheckBox1->Enabled = true;
	 CheckBox2->Enabled = true;
	 cxColorComboBox1->Enabled = true;
	 cxColorComboBox2->Enabled = true;
	 cxColorComboBox3->Enabled = true;
	 cxColorComboBox4->Enabled = true;
	 cxColorComboBox5->Enabled = true;
     LineWidthComboBox1->Enabled = true;

     InitHistogramTabSheet();
     RadioGroup6->Enabled = true;
	 cxColorComboBox6->Enabled = true;
     CheckBox3->Enabled = true;

     InitLineGraphTabSheet();
     LineGraphToolBar->Enabled = true;

     for (int i=0; i<LineGraphToolBar->ButtonCount; i++)
       LineGraphToolBar->Buttons[i]->Enabled = true;
     Label10->Enabled = true;
     LineWidthComboBox2->Enabled = true;
     LabeledEdit3->Enabled = true;
     CheckBox5->Enabled = true;
     Label3->Enabled = true;
	 cxColorComboBox7->Enabled = true;

     InitNumberTabSheet();
     BitBtn2->Enabled = true;
     cxSpinEdit3->Enabled = true;
     CheckBox8->Enabled = true;

     InitPresenceTabSheet();
     LabeledEdit7->Enabled = true;
     LabeledEdit8->Enabled = true;
     CheckBox6->Enabled = true;
	 cxColorComboBox8->Enabled = true;

     Button18->Enabled = true;
     BitBtn1->Enabled = true;
     }
  else {
    RadioGroup2->Enabled = false;
    cxSpinEdit1->Enabled = false;
    Button6->Enabled = false;
    RadioGroup3->Enabled = false;
    RadioGroup1->Enabled = false;
    Button5->Enabled = false;
    CheckBox1->Enabled = false;
    CheckBox2->Enabled = false;
	cxColorComboBox1->Enabled = false;
	cxColorComboBox2->Enabled = false;
	cxColorComboBox3->Enabled = false;
	cxColorComboBox4->Enabled = false;
	cxColorComboBox5->Enabled = false;
    LineWidthComboBox1->Enabled = false;

    RadioGroup6->Enabled = false;
    LineWidthComboBox3->Enabled = false;
    cxSpinEdit2->Enabled = false;
    RadioGroup4->Enabled = false;
	Button11->Enabled = false;
	cxColorComboBox6->Enabled = false;
    CheckBox3->Enabled = false;

    LineGraphToolBar->Enabled = false;
    Label10->Enabled = false;
    LineWidthComboBox2->Enabled = false;
    LabeledEdit3->Enabled = false;
    CheckBox4->Enabled = false;
    CheckBox7->Enabled = false;
    RadioGroup5->Enabled = false;
    LabeledEdit4->Enabled = false;
    LabeledEdit5->Enabled = false;
    LabeledEdit9->Enabled = false;
    LabeledEdit4->Color = clBtnFace;
    LabeledEdit5->Color = clBtnFace;
    LabeledEdit9->Color = clBtnFace;
    CheckBox5->Enabled = false;
    Label3->Enabled = false;
	cxColorComboBox7->Enabled = false;

    BitBtn2->Enabled = false;
    cxSpinEdit3->Enabled = false;
    CheckBox8->Enabled = false;

    LabeledEdit7->Enabled = false;
    LabeledEdit8->Enabled = false;
    CheckBox6->Enabled = false;
	cxColorComboBox8->Enabled = false;
    Button18->Enabled = false;
    }
  SelectTabSheet(GraphType);
}

//---------------------------------------------------------------------------
// initialize options for default or selected silhouette graph
void TStyleForm::InitSilhouetteOptions(GRAPHS *graph)
{
  SilOpt.DepthBars     = graph->DepthBars;
  SilOpt.DottedBaseLine = graph->DottedBaseLine;
  SilOpt.SilhouetteFill = graph->SilhouetteFill;
  SilOpt.SilhouettePattern = graph->SilhouettePattern;
  SilOpt.Exag.i         = graph->Exag;
  SilOpt.ExagFill       = graph->ExagFill;
  SilOpt.ExagPattern    = graph->ExagPattern;
  SilOpt.ExagGrid       = graph->ExagGrid;
  SilOpt.GraphColor.value  = graph->GraphColor;
  SilOpt.GraphOutlineColor.value = graph->GraphOutlineColor;
  SilOpt.ExagColor.value  = graph->ExagColor;
  SilOpt.ExagOutlineColor.value = graph->ExagOutlineColor;
  SilOpt.DepthBarsColor.value = graph->DepthBarsColor;
  SilOpt.SilhouetteLineWidth.x = graph->SilhouetteLineWidth;
  SilOpt.GraphColor.show = true;
  SilOpt.GraphOutlineColor.show = true;
  SilOpt.ExagColor.show = true;
  SilOpt.ExagOutlineColor.show = true;
  SilOpt.DepthBarsColor.show = true;
}
//---------------------------------------------------------------------------

// initialize options for default or selected histogram graph
void TStyleForm::InitHistogramOptions(GRAPHS *graph)
{
  HistOpt.HistogramLineWidth.x = graph->HistogramLineWidth;
  HistOpt.BarWidth.x = graph->BarWidth;
  HistOpt.BarFill = graph->BarFill;
  HistOpt.BarPattern = graph->BarPattern;
  HistOpt.GraphColor.value  = graph->GraphColor;
  HistOpt.VerticalAxis = graph->VerticalAxis;
  HistOpt.UseThickVar = graph->UseThickVar;
  HistOpt.GraphColor.show = true;
}
//---------------------------------------------------------------------------

// initialize options for default or selected line graph
void TStyleForm::InitLineGraphOptions(GRAPHS *graph, XAXIS *xax)
{
  LineOpt.MarkerType = graph->MarkerType;
  LineOpt.MarkerSize.x = graph->MarkerSize;
  LineOpt.SymbolName = graph->SymbolName;
  LineOpt.AutoMarkerTop = graph->AutoMarkerTop;
  LineOpt.AutoMarkerBottom = graph->AutoMarkerBottom;
  LineOpt.XMarkerLabel.x = graph->XMarkerLabel;
  LineOpt.YMarkerLabel.x = graph->YMarkerLabel;
  LineOpt.AngleMarkerLabel.x = graph->AngleMarkerLabel;
  LineOpt.ZeroSymbol = graph->ZeroSymbol;
  LineOpt.GraphColor.value  = graph->GraphColor;
  LineOpt.PlotGraphName = xax->PlotGraphName;
  LineOpt.marker_type_clicked = false;
  LineOpt.GraphColor.show = true;
  LineOpt.LineGraphLineWidth.x = graph->LineGraphLineWidth;
}
//---------------------------------------------------------------------------

// initialize options for default or selected number graph
void TStyleForm::InitNumberOptions(GRAPHS *graph)
{
  NumOpt.PlotZeroNumbers = graph->PlotZeroNumbers;
  NumOpt.NumberFont = graph->NumberFont;
  NumOpt.DecimalPoints.i = graph->DecimalPoints;
}
//---------------------------------------------------------------------------

// initialize options for default or selected presence graph
void TStyleForm::InitPresenceOptions(GRAPHS *graph)
{
  PresOpt.PresenceSymbol = graph->PresenceSymbol;
  PresOpt.MarkerSize.x = graph->MarkerSize;
  PresOpt.XPresence.x = graph->XPresence;
  PresOpt.GraphColor.value  = graph->GraphColor;
  PresOpt.GraphColor.show = true;
}
//---------------------------------------------------------------------------

// initialize options for multiple graphs
void TStyleForm::MultipleSilhouetteOptions(void)
{
    int i;
    GRAPH *g;

    for (i=0; i<VarCount; i++)
      if (VarList[i].Checked) {
         GRAPH* g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];
         InitSilhouetteOptions(g->graph);
         break;
         }

    int start = i+1;
    for (i=start; i<VarCount; i++) {
      if (VarList[i].Checked) {
        g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];
        if (SilOpt.SilhouetteFill != g->graph->SilhouetteFill) {
           SilOpt.SilhouetteFill = NO_FILL;
           break; }
        }
      }

    for (i=start; i<VarCount; i++) {
      if (VarList[i].Checked) {
        g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];
        if (SilOpt.SilhouettePattern != g->graph->SilhouettePattern) {
           SilOpt.SilhouettePattern = -1;
           break; }
        }
      }

    for (i=start; i<VarCount; i++) {
      if (VarList[i].Checked) {
        g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];
        if (SilOpt.ExagFill != g->graph->ExagFill) {
           SilOpt.ExagFill = NO_FILL;
           break; }
        }
      }

    for (i=start; i<VarCount; i++) {
      if (VarList[i].Checked) {
        g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];
        if (SilOpt.ExagPattern != g->graph->ExagPattern) {
           SilOpt.ExagPattern = -1;
           break; }
        }
      }

    for (i=start; i<VarCount; i++) {
      if (VarList[i].Checked) {
        g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];
        if (SilOpt.ExagGrid != g->graph->ExagGrid) {
           SilOpt.ExagGrid = -1;
           break; }
        }
      }
    for (i=start; i<VarCount; i++) {
      if (VarList[i].Checked) {
        g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];
        if (SilOpt.Exag.i != g->graph->Exag) {
           SilOpt.Exag.show = false;
           break; }
        }
      }
    for (i=start; i<VarCount; i++) {
      if (VarList[i].Checked) {
        g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];
        if (SilOpt.DepthBars != g->graph->DepthBars) {
           SilOpt.DepthBars = false;
           CheckBox1->AllowGrayed = true;
           break; }
        }
      }

    for (i=start; i<VarCount; i++) {
      if (VarList[i].Checked) {
        g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];
        if (SilOpt.DottedBaseLine != g->graph->DottedBaseLine) {
           SilOpt.DottedBaseLine = false;
           CheckBox2->AllowGrayed = true;
           break; }
        }
      }

    for (i=start; i<VarCount; i++) {
      if (VarList[i].Checked) {
        g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];
        if (SilOpt.GraphColor.value != g->graph->GraphColor) {
           SilOpt.GraphColor.show = false;
           break; }
        }
      }

    for (i=start; i<VarCount; i++) {
      if (VarList[i].Checked) {
        g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];
        if (SilOpt.GraphOutlineColor.value != g->graph->GraphOutlineColor) {
           SilOpt.GraphOutlineColor.show = false;
           break; }
        }
      }
    for (i=start; i<VarCount; i++) {
      if (VarList[i].Checked) {
        g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];
        if (SilOpt.ExagColor.value != g->graph->ExagColor) {
           SilOpt.ExagColor.show = false;
           break; }
        }
      }
    for (i=start; i<VarCount; i++) {
      if (VarList[i].Checked) {
        g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];
        if (SilOpt.ExagOutlineColor.value != g->graph->ExagOutlineColor) {
           SilOpt.ExagOutlineColor.show = false;
           break; }
        }
      }

   for (i=start; i<VarCount; i++) {
      if (VarList[i].Checked) {
        g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];
        if (SilOpt.DepthBarsColor.value != g->graph->DepthBarsColor) {
           SilOpt.DepthBarsColor.show = false;
           break; }
        }
      }

   for (i=start; i<VarCount; i++) {
      if (VarList[i].Checked) {
        g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];
        if (SilOpt.SilhouetteLineWidth.x != g->graph->SilhouetteLineWidth) {
           SilOpt.SilhouetteLineWidth.show = false;
           break; }
        }
      }
}
//---------------------------------------------------------------------------

void TStyleForm::MultipleHistogramOptions(void)
{
    int i;
    GRAPH *g;

    for (i=0; i<VarCount; i++)
      if (VarList[i].Checked) {
         GRAPH* g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];
         InitHistogramOptions(g->graph);
         break;
         }

    int start = i+1;

    bool lines = false;
    bool bars = false;
    for (i=start-1; i<VarCount; i++) {
      if (VarList[i].Checked) {
        g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];
        if (g->graph->BarWidth < 0.02)
          lines = true;
        else
          bars = true;
        if (lines && bars) {
          RadioGroup6->ItemIndex = -1;
          break;
          }
        }
      }

    for (i=start; i<VarCount; i++) {
      if (VarList[i].Checked) {
        g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];
        if (HistOpt.HistogramLineWidth.x != g->graph->HistogramLineWidth) {
           HistOpt.HistogramLineWidth.show = false;
           break; }
        }
      }

    for (i=start; i<VarCount; i++) {
      if (VarList[i].Checked) {
        g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];
        if (HistOpt.BarWidth.x != g->graph->BarWidth) {
           HistOpt.BarWidth.show = false;
           break; }
        }
      }

    for (i=start; i<VarCount; i++) {
      if (VarList[i].Checked) {
        g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];
        if (HistOpt.BarFill != g->graph->BarFill) {
           HistOpt.BarFill = NO_FILL;
           break; }
        }
      }

    for (i=start; i<VarCount; i++) {
      if (VarList[i].Checked) {
        g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];
        if (HistOpt.BarPattern != g->graph->BarPattern) {
           HistOpt.BarPattern = -1;
           break; }
        }
      }

    for (i=start; i<VarCount; i++) {
      if (VarList[i].Checked) {
        g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];
        if (HistOpt.GraphColor.value != g->graph->GraphColor) {
           HistOpt.GraphColor.show = false;
           break; }
        }
      }

    for (i=start; i<VarCount; i++) {
      if (VarList[i].Checked) {
        g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];
        if (HistOpt.VerticalAxis != g->graph->VerticalAxis) {
           HistOpt.VerticalAxis = false;
           CheckBox3->AllowGrayed = true;
           break; }
        }
      }

    for (i=start; i<VarCount; i++) {
      if (VarList[i].Checked) {
        g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];
        if (HistOpt.UseThickVar != g->graph->UseThickVar) {
           HistOpt.UseThickVar = false;
           CheckBox9->AllowGrayed = true;
           break; }
        }
      }
}
//---------------------------------------------------------------------------

void TStyleForm::MultipleLineGraphOptions(void)
{
    int i;
    GRAPH *g;

    // set initial options
    for (i=0; i<VarCount; i++)
      if (VarList[i].Checked) {
         GRAPH* g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];
         InitLineGraphOptions(g->graph, g->xax);
         break;
         }

    int start = i+1;
    for (i=start; i<VarCount; i++) {
      if (VarList[i].Checked) {
        g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];
        if (LineOpt.MarkerType != g->graph->MarkerType) {
           LineOpt.MarkerType = -1;
           break; }
        }
      }

    for (i=start; i<VarCount; i++) {
      if (VarList[i].Checked) {
        g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];
        if (LineOpt.MarkerSize.x != g->graph->MarkerSize) {
           LineOpt.MarkerSize.show = false;
           break; }
        }
      }

    for (i=start; i<VarCount; i++) {
      if (VarList[i].Checked) {
        g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];
        if (LineOpt.SymbolName != g->graph->SymbolName) {
           LineOpt.SymbolName = true;
           CheckBox4->AllowGrayed = true;
           break; }
        }
      }

    for (i=start; i<VarCount; i++) {
      if (VarList[i].Checked) {
        g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];
        if (LineOpt.PlotGraphName != g->xax->PlotGraphName) {
           LineOpt.PlotGraphName = true;
           CheckBox7->AllowGrayed = true;
           break; }
        }
      }

    for (i=start; i<VarCount; i++) {
      if (VarList[i].Checked) {
        g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];
        if (LineOpt.AutoMarkerTop != g->graph->AutoMarkerTop ||
            LineOpt.AutoMarkerBottom != g->graph->AutoMarkerBottom ) {
           LineOpt.AutoMarkerTop = Diag->Default.Graph.AutoMarkerTop;
           LineOpt.AutoMarkerBottom = Diag->Default.Graph.AutoMarkerBottom;
           break; }
        }
      }

    for (i=start; i<VarCount; i++) {
      if (VarList[i].Checked) {
        g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];
        if (LineOpt.XMarkerLabel.x != g->graph->XMarkerLabel) {
           LineOpt.XMarkerLabel.x = Diag->Default.Graph.XMarkerLabel;
           LineOpt.XMarkerLabel.show = false;
           break; }
        }
      }

    for (i=start; i<VarCount; i++) {
      if (VarList[i].Checked) {
        g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];
        if (LineOpt.YMarkerLabel.x != g->graph->YMarkerLabel) {
           LineOpt.YMarkerLabel.x = Diag->Default.Graph.YMarkerLabel;
           LineOpt.YMarkerLabel.show = false;
           break; }
        }
      }

    for (i=start; i<VarCount; i++) {
      if (VarList[i].Checked) {
        g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];
        if (LineOpt.AngleMarkerLabel.x != g->graph->AngleMarkerLabel) {
           LineOpt.AngleMarkerLabel.x = Diag->Default.Graph.AngleMarkerLabel;
           LineOpt.AngleMarkerLabel.show = false;
           break; }
        }
      }

    for (i=start; i<VarCount; i++) {
      if (VarList[i].Checked) {
        g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];
        if (LineOpt.ZeroSymbol != g->graph->ZeroSymbol) {
           LineOpt.ZeroSymbol = false;
           CheckBox5->AllowGrayed = true;
           break; }
        }
      }

    for (i=start; i<VarCount; i++) {
      if (VarList[i].Checked) {
        g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];
        if (LineOpt.GraphColor.value != g->graph->GraphColor) {
           LineOpt.GraphColor.show = false;
           break; }
        }
      }

    for (i=start; i<VarCount; i++) {
      if (VarList[i].Checked) {
        g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];
        if (LineOpt.LineGraphLineWidth.x != g->graph->LineGraphLineWidth) {
           LineOpt.LineGraphLineWidth.show = false;
           break; }
        }
      }
}

//---------------------------------------------------------------------------
void TStyleForm::MultipleNumberOptions(void)
{
    int i;
    GRAPH *g;

    // set initial options
    for (i=0; i<VarCount; i++)
      if (VarList[i].Checked) {
         GRAPH* g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];
         InitNumberOptions(g->graph);
         break;
         }

    int start = i+1;

    for (i=start; i<VarCount; i++) {
      if (VarList[i].Checked) {
        g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];
        if (NumOpt.PlotZeroNumbers != g->graph->PlotZeroNumbers) {
           NumOpt.PlotZeroNumbers = false;
           CheckBox8->AllowGrayed = true;
           break; }
        }
      }

    for (i=start; i<VarCount; i++) {
      if (VarList[i].Checked) {
        g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];
        NumOpt.NumberFont.Compare(g->graph->NumberFont);
        }
      }

    for (i=start; i<VarCount; i++) {
      if (VarList[i].Checked) {
        g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];
        if (NumOpt.DecimalPoints.i != g->graph->DecimalPoints) {
           NumOpt.DecimalPoints.show = false;
           break; }
        }
      }

}

//---------------------------------------------------------------------------
void TStyleForm::MultiplePresenceOptions(void)
{
    int i;
    GRAPH *g;

    // set initial options
    for (i=0; i<VarCount; i++)
      if (VarList[i].Checked) {
         GRAPH* g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];
         InitPresenceOptions(g->graph);
         break;
         }

    int start = i+1;

    for (i=start; i<VarCount; i++) {
      if (VarList[i].Checked) {
        g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];
        if (PresOpt.PresenceSymbol != g->graph->PresenceSymbol) {
           PresOpt.PresenceSymbol = false;
           CheckBox6->AllowGrayed = true;
           break; }
        }
      }

    for (i=start; i<VarCount; i++) {
      if (VarList[i].Checked) {
        g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];
        if (PresOpt.MarkerSize.x != g->graph->MarkerSize) {
           PresOpt.MarkerSize.show = false;
           break; }
        }
      }

    for (i=start; i<VarCount; i++) {
      if (VarList[i].Checked) {
        g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];
        if (PresOpt.XPresence.x != g->graph->XPresence) {
           PresOpt.XPresence.show = false;
           break; }
        }
      }

    for (i=start; i<VarCount; i++) {
      if (VarList[i].Checked) {
        g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];
        if (PresOpt.GraphColor.value != g->graph->GraphColor) {
           PresOpt.GraphColor.show = false;
           break; }
        }
      }
}
//---------------------------------------------------------------------------

void TStyleForm::InitSilhouetteTabSheet(void)
{
   Button6->Enabled = false;
   Shape1->Brush->Bitmap = NULL;
   Shape1->Visible = false;
   switch (SilOpt.SilhouetteFill) {
	 case NO_FILL:      RadioGroup2->ItemIndex = -1; break;
	 case SOLID_FILL:   RadioGroup2->ItemIndex = 0; break;
	 case HOLLOW_FILL:  RadioGroup2->ItemIndex = 1; break;
	 case PATTERN_FILL:
	   RadioGroup2->ItemIndex = 2;
	   Button6->Enabled = true;
	   Shape1->Visible = true;
	   if (SilOpt.SilhouettePattern > 0) {
		 //Shape1->Brush->Bitmap =
		 //  (Graphics::TBitmap *)ParentForm->GKSBitmaps->Items[SilOpt.SilhouettePattern-1];
		 Shape1->Brush->Bitmap = ParentForm->GKSBitmaps[SilOpt.SilhouettePattern-1];
		 Shape1->Pen->Style = psSolid;
         }
       else {
         Shape1->Brush->Bitmap = NULL;
         Shape1->Pen->Style = psDot;
		 Shape1->Brush->Style = bsClear;
         }
       break;
	 case BAR_FILL:
	   RadioGroup2->ItemIndex = 3;
	   break;
     }

   if (!SilOpt.Exag.show)
     cxSpinEdit1->Value = 0;
   else
     cxSpinEdit1->Value = (int)SilOpt.Exag.i;

   Button5->Enabled = false;
   Shape2->Brush->Bitmap = NULL;
   Shape2->Visible = false;
   switch (SilOpt.ExagFill) {
     case NO_FILL:      RadioGroup3->ItemIndex = -1; break;
     case SOLID_FILL:   RadioGroup3->ItemIndex = 0; break;
     case HOLLOW_FILL:  RadioGroup3->ItemIndex = 1; break;
     case PATTERN_FILL:
       RadioGroup3->ItemIndex = 2;
       Button5->Enabled = true;
	   if (SilOpt.ExagPattern > 0) {
		 //Shape2->Brush->Bitmap =
		 //  (Graphics::TBitmap *)ParentForm->GKSBitmaps->Items[SilOpt.ExagPattern-1];
         Shape2->Brush->Bitmap = ParentForm->GKSBitmaps[SilOpt.ExagPattern-1];
		 Shape2->Pen->Style = psSolid;
         }
       else {
         Shape2->Brush->Bitmap = NULL;
         Shape2->Pen->Style = psDot;
         Shape2->Brush->Style = bsClear;
         }
       break;
     case BAR_FILL:     RadioGroup3->ItemIndex = 3; break;
     case GRID_FILL:    RadioGroup3->ItemIndex = 4; break;
     }

   switch (SilOpt.ExagGrid) {
     case 0: RadioGroup1->ItemIndex = -1; break;
     case 1: RadioGroup1->ItemIndex = 1; break;
     case 2: RadioGroup1->ItemIndex = 0; break;
     }

   CheckBox1->Checked = SilOpt.DepthBars;
   if (CheckBox1->AllowGrayed)
     CheckBox1->State = cbGrayed;

   CheckBox2->Checked = SilOpt.DottedBaseLine;
   if (CheckBox2->AllowGrayed)
     CheckBox2->State = cbGrayed;
   
   if (SilOpt.GraphColor.show)
	 Diag->SetColorComboBox(cxColorComboBox1, (TColor)SilOpt.GraphColor.value);

   if (SilOpt.GraphOutlineColor.show)
	 Diag->SetColorComboBox(cxColorComboBox2, (TColor)SilOpt.GraphOutlineColor.value);

   if (SilOpt.ExagColor.show)
	 Diag->SetColorComboBox(cxColorComboBox3, (TColor)SilOpt.ExagColor.value);

   if (SilOpt.ExagOutlineColor.show)
	 Diag->SetColorComboBox(cxColorComboBox4, (TColor)SilOpt.ExagOutlineColor.value);

   if (SilOpt.DepthBarsColor.show)
	 Diag->SetColorComboBox(cxColorComboBox5, (TColor)SilOpt.DepthBarsColor.value);

   if (!SilOpt.SilhouetteLineWidth.show)
     LineWidthComboBox1->Text = "";
   else
     SilhLineWidthComboBox->SetLineWidth(SilOpt.SilhouetteLineWidth.x);

   SilOpt.TabSheetInitialized = true;
}

//---------------------------------------------------------------------------

void __fastcall TStyleForm::RadioGroup6Click(TObject *Sender)
{
  if (RadioGroup6->ItemIndex == 0)
    InitHistogramLines();
  else
    InitHistogramBars();
}

//---------------------------------------------------------------------------
void TStyleForm::InitHistogramLines(void)
{
  HistOpt.BarWidth.x = 0.0;
  GroupBox5->Enabled = true;
  GroupBox4->Enabled = false;

  LineWidthComboBox3->Enabled = true;
  cxSpinEdit2->Enabled = false;
  RadioGroup4->Enabled = false;
  Button11->Enabled = false;
  CheckBox9->Enabled = false;

  if (!HistOpt.HistogramLineWidth.show)
    LineWidthComboBox3->Text = "";
  else
    HistLineWidthComboBox->SetLineWidth(HistOpt.HistogramLineWidth.x);
}
//---------------------------------------------------------------------------

void TStyleForm::InitHistogramBars(void)
{
  GroupBox5->Enabled = false;
  GroupBox4->Enabled = true;
  CheckBox9->Enabled = true;

  LineWidthComboBox3->Enabled = false;
  if (HistOpt.UseThickVar) {
    cxSpinEdit2->Enabled = false;
    cxSpinEdit2->Style->Color = clBtnFace;
    }
  else {
    cxSpinEdit2->Enabled = true;
    cxSpinEdit2->Style->Color = clWindow;
    }
  RadioGroup4->Enabled = true;

  if (!HistOpt.BarWidth.show)
    cxSpinEdit2->Value = 0.02;
  else
    cxSpinEdit2->Value = max(0.02, HistOpt.BarWidth.x);

  if (HistOpt.BarWidth.show)
    RadioGroup4->Enabled = true;

  Button11->Enabled = false;
  Shape7->Brush->Bitmap = NULL;
  Shape7->Brush->Style = bsClear;
  Shape7->Pen->Style = psClear;

  switch (HistOpt.BarFill) {
    case NO_FILL:      RadioGroup4->ItemIndex = -1; break;
    case SOLID_FILL:   RadioGroup4->ItemIndex = 0; break;
    case HOLLOW_FILL:  RadioGroup4->ItemIndex = 1; break;
    case PATTERN_FILL:
      RadioGroup4->ItemIndex = 2;
      Button11->Enabled = true;
      if (HistOpt.BarPattern > 0) {
		//Shape7->Brush->Bitmap =
		//  (Graphics::TBitmap *)ParentForm->GKSBitmaps->Items[HistOpt.BarPattern-1];
        Shape7->Brush->Bitmap = ParentForm->GKSBitmaps[HistOpt.BarPattern-1];
		Shape7->Pen->Style = psSolid;
        }
	  break;
	}
}
//---------------------------------------------------------------------------

void TStyleForm::InitHistogramTabSheet(void)
{
  if (RadioGroup6->ItemIndex < 0) {
    GroupBox5->Enabled = false;
    GroupBox4->Enabled = false;
    LineWidthComboBox3->Enabled = false;
    cxSpinEdit2->Enabled = false;
    RadioGroup4->Enabled = false;
    Button11->Enabled = false;
    }
  else {
    if (HistOpt.BarWidth.x < 0.02) {
      RadioGroup6->ItemIndex = 0;
      InitHistogramLines();
      }
    else {
      RadioGroup6->ItemIndex = 1;
      InitHistogramBars();
      }
    }

  if (HistOpt.GraphColor.show)
	Diag->SetColorComboBox(cxColorComboBox6, (TColor)HistOpt.GraphColor.value);

  CheckBox3->Checked = HistOpt.VerticalAxis;
  if (CheckBox3->AllowGrayed)
	CheckBox3->State = cbGrayed;

  CheckBox9->Checked = HistOpt.UseThickVar;
  if (CheckBox9->AllowGrayed)
	CheckBox9->State = cbGrayed;

  HistOpt.TabSheetInitialized = true;
}
//---------------------------------------------------------------------------

void TStyleForm::InitLineGraphTabSheet(void)
{
   for (int i=0; i<LineGraphToolBar->ButtonCount; i++)
     LineGraphToolBar->Buttons[i]->Down = false;

   if (LineOpt.MarkerType >= 0)
     LineGraphToolBar->Buttons[LineOpt.MarkerType]->Down = true;

   if (LineOpt.MarkerSize.show)
     LabeledEdit3->Text = FloatToStr(LineOpt.MarkerSize.x);
   else
     LabeledEdit3->Text = "";

   CheckBox4->Checked = LineOpt.SymbolName;
   if (CheckBox4->AllowGrayed)
     CheckBox4->State = cbGrayed;
   CheckBox4->Enabled = (ToolButton1->Down) ? false : true;

   RadioGroup5->Enabled = (!ToolButton1->Down && CheckBox4->Checked && CheckBox4->State != cbGrayed) ? true : false;
   LabeledEdit4->Enabled = false;
   LabeledEdit5->Enabled = false;
   LabeledEdit9->Enabled = false;
   LabeledEdit4->Color = clBtnFace;
   LabeledEdit5->Color = clBtnFace;
   LabeledEdit9->Color = clBtnFace;

   CheckBox7->Checked = LineOpt.PlotGraphName;
   CheckBox7->Enabled = false;

   if (LineOpt.AutoMarkerTop) {
     RadioGroup5->ItemIndex = 0;
     LineOpt.PlotGraphName = false;
     CheckBox7->Checked = false;
     CheckBox7->Enabled = false;
     }
   else if (LineOpt.AutoMarkerBottom) {
     RadioGroup5->ItemIndex = 1;
     if (CheckBox4->State != cbGrayed)
       CheckBox7->Enabled = CheckBox4->Checked;
     else
       CheckBox7->Enabled = false;
     }
   else {
     RadioGroup5->ItemIndex = 2;
     if (CheckBox4->State != cbGrayed)
       CheckBox7->Enabled = CheckBox4->Checked;
     else
       CheckBox7->Enabled = false;
     if (!ToolButton1->Down && CheckBox4->Checked && CheckBox4->State != cbGrayed) {
       LabeledEdit4->Enabled = true;
       LabeledEdit5->Enabled = true;
       LabeledEdit9->Enabled = true;
       LabeledEdit4->Color = clWindow;
       LabeledEdit5->Color = clWindow;
       LabeledEdit9->Color = clWindow; }
     }

   if (LineOpt.XMarkerLabel.show)
     LabeledEdit4->Text = FloatToStr(LineOpt.XMarkerLabel.x);
   else
     LabeledEdit4->Clear();

   if (LineOpt.YMarkerLabel.show)
     LabeledEdit5->Text = FloatToStr(LineOpt.YMarkerLabel.x);
   else
     LabeledEdit5->Clear();

   if (LineOpt.AngleMarkerLabel.show)
     LabeledEdit9->Text = FloatToStr(LineOpt.AngleMarkerLabel.x);
   else
     LabeledEdit9->Clear();

   if (LineOpt.AngleMarkerLabel.show)
     LabeledEdit9->Text = FloatToStr(LineOpt.AngleMarkerLabel.x);
   else
     LabeledEdit9->Clear();

   CheckBox5->Checked = LineOpt.ZeroSymbol;
   if (CheckBox5->AllowGrayed)
     CheckBox5->State = cbGrayed;

   if (LineOpt.GraphColor.show)
	 Diag->SetColorComboBox(cxColorComboBox7, (TColor)LineOpt.GraphColor.value);

   if (!LineOpt.LineGraphLineWidth.show)
     LineWidthComboBox2->Text = "";
   else
     LiGrLineWidthComboBox->SetLineWidth(LineOpt.LineGraphLineWidth.x);

   LineOpt.TabSheetInitialized = true;
}
//---------------------------------------------------------------------------

void TStyleForm::InitNumberTabSheet(void)
{
  CheckBox8->Checked = NumOpt.PlotZeroNumbers;
  if (CheckBox8->AllowGrayed)
    CheckBox8->State = cbGrayed;

  if (!NumOpt.DecimalPoints.show)
    cxSpinEdit3->Value = 0;
  else
    cxSpinEdit3->Value = (int)NumOpt.DecimalPoints.i;

  NumOpt.TabSheetInitialized = true;
}
//---------------------------------------------------------------------------

// initialize presence tab sheet
void TStyleForm::InitPresenceTabSheet(void)
{

  if (!PresOpt.MarkerSize.show)
    LabeledEdit7->Text = "";
  else
    LabeledEdit7->Text = FloatToStr(PresOpt.MarkerSize.x);

  if (!PresOpt.XPresence.show)
    LabeledEdit8->Text = "";
  else
    LabeledEdit8->Text = FloatToStr(PresOpt.XPresence.x);

  CheckBox6->Checked = PresOpt.PresenceSymbol;
  if (CheckBox6->AllowGrayed)
    CheckBox6->State = cbGrayed;

  if (PresOpt.GraphColor.show)
	Diag->SetColorComboBox(cxColorComboBox8, (TColor)PresOpt.GraphColor.value);

  PresOpt.TabSheetInitialized = true;
}
//---------------------------------------------------------------------------

// Ok button
void __fastcall TStyleForm::Button1Click(TObject *Sender)
{
  Diag->Modified = true;
  ApplyOptions();

  if (Spawned) {
    Diag->make_diagram();
    Diag->Picture->OutputGraphicObjects(DISPLAY, (TTGDiagram*)ParentForm->ActiveMDIChild);
    }
}
//---------------------------------------------------------------------------

// apply options to diagram
void TStyleForm::ApplyOptions(void)
{
   int i;
   GRAPH* g;

   switch (PageControl1->ActivePage->PageIndex)
   {
   case 0:  // Silhouette
     if (VarsChecked > 0)
       {
         SetSilhouetteOptions();
         for (i=0; i<VarCount; i++) {
           if (VarList[i].Checked) {
             g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];
             ApplySilhouetteOptions(g->graph);
             }
           }
         if (VarsChecked == VarCount)
           ApplySilhouetteOptions(&Diag->Default.Graph);
       }
     break;
   case 1:  // Histogram
     if (VarsChecked > 0)
       {
         SetHistogramOptions();
         for (i=0; i<VarCount; i++) {
           if (VarList[i].Checked) {
             g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];
             ApplyHistogramOptions(g->graph);
             }
           }
         if (VarsChecked == VarCount)
           ApplyHistogramOptions(&Diag->Default.Graph);
       }
     break;
   case 2:  // Line graph
     if (VarsChecked > 0)
       {
         SetLineGraphOptions();
         for (i=0; i<VarCount; i++) {
           if (VarList[i].Checked) {
             g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];
             ApplyLineGraphOptions(g->graph, g->xax);
             }
           }
         if (VarsChecked == VarCount)
           ApplyLineGraphOptions(&Diag->Default.Graph, &Diag->Default.Xaxis);
       }
     break;
   case 3:
     if (VarsChecked > 0)
       {
         SetNumberOptions();
         for (i=0; i<VarCount; i++) {
           if (VarList[i].Checked) {
             g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];
             ApplyNumberOptions(g->graph);
             }
           }
         if (VarsChecked == VarCount)
           ApplyNumberOptions(&Diag->Default.Graph);
       }
     break;
   case 4:
     if (VarsChecked > 0)
       {
         SetPresenceOptions();
         for (i=0; i<VarCount; i++) {
           if (VarList[i].Checked) {
             g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];
             ApplyPresenceOptions(g->graph, g->xax);
             }
           }
         if (VarsChecked == VarCount)
           ApplyPresenceOptions(&Diag->Default.Graph, &Diag->Default.Xaxis);
       }
     break;
   }
}

//---------------------------------------------------------------------------
void TStyleForm::SetSilhouetteOptions(void)
{
  switch (RadioGroup2->ItemIndex)
  {
   case -1: SilOpt.SilhouetteFill = NO_FILL; break;
   case 0:  SilOpt.SilhouetteFill = SOLID_FILL; break;
   case 1:  SilOpt.SilhouetteFill = HOLLOW_FILL; break;
   case 2:  SilOpt.SilhouetteFill = PATTERN_FILL; break;
   case 3:  SilOpt.SilhouetteFill = BAR_FILL; break;
  }

  if (SilOpt.Exag.show)
    SilOpt.Exag.i = cxSpinEdit1->EditValue;

  switch (RadioGroup3->ItemIndex)
  {
   case -1: SilOpt.ExagFill = NO_FILL; break;
   case 0:  SilOpt.ExagFill = SOLID_FILL; break;
   case 1:  SilOpt.ExagFill = HOLLOW_FILL; break;
   case 2:  SilOpt.ExagFill = PATTERN_FILL; break;
   case 3:  SilOpt.ExagFill = BAR_FILL; break;
   case 4:  SilOpt.ExagFill = GRID_FILL; break;
  }

  switch (RadioGroup1->ItemIndex)
  {
   case -1: SilOpt.ExagGrid = -1; break;
   case 0:  SilOpt.ExagGrid = ONMAJORTICS; break;
   case 1:  SilOpt.ExagGrid = ONMINORTICS; break;
  }

  if (LineWidthComboBox1->Text.IsEmpty())
    SilOpt.SilhouetteLineWidth.show = false;
  else
    SilOpt.SilhouetteLineWidth.x = SilhLineWidthComboBox->GetLineWidth();
}

//---------------------------------------------------------------------------
void TStyleForm::SetHistogramOptions(void)
{
  if (RadioGroup6->ItemIndex < 0) {
    HistOpt.BarWidth.show = false;
    HistOpt.HistogramLineWidth.show = false;
    }
  else if (RadioGroup6->ItemIndex == 0) {  // lines
    if (LineWidthComboBox3->Text.IsEmpty()) {
      HistOpt.HistogramLineWidth.show = false;
      HistOpt.BarWidth.show = false;
      }
    else {
      HistOpt.HistogramLineWidth.x = HistLineWidthComboBox->GetLineWidth();
      HistOpt.BarWidth.x = 0.0;
      HistOpt.BarWidth.show = HistOpt.HistogramLineWidth.show;
      }
    }
  else {   // bars
    if (HistOpt.BarWidth.show)
       HistOpt.BarWidth.x = cxSpinEdit2->EditValue;

    if (HistOpt.UseThickVar) {
      cxSpinEdit2->Style->Color = clBtnFace;
      cxSpinEdit2->Enabled = false;
      }

    switch (RadioGroup4->ItemIndex) {
      case -1: HistOpt.BarFill = NO_FILL; break;
      case 0:  HistOpt.BarFill = SOLID_FILL; break;
      case 1:  HistOpt.BarFill = HOLLOW_FILL; break;
      case 2:  HistOpt.BarFill = PATTERN_FILL; break;
      }
    }
}

//---------------------------------------------------------------------------
void TStyleForm::SetLineGraphOptions(void)
{
  if (LabeledEdit3->Text.IsEmpty())
    LineOpt.MarkerSize.show = false;
  else {
    try {
      LineOpt.MarkerSize.x = StrToFloat(LabeledEdit3->Text); }
    catch (...) {
      LineOpt.MarkerSize.show = false; }
    }

  switch (RadioGroup5->ItemIndex)
  {
   case 0:
     LineOpt.AutoMarkerTop = true;
     LineOpt.AutoMarkerBottom = false;
     break;
   case 1:
     LineOpt.AutoMarkerTop = false;
     LineOpt.AutoMarkerBottom = true;
     break;
   case 2:
     LineOpt.AutoMarkerTop = false;
     LineOpt.AutoMarkerBottom = false;
     break;
  }

  if (LabeledEdit4->Text.IsEmpty())
    LineOpt.XMarkerLabel.show = false;
  else {
    try {
      LineOpt.XMarkerLabel.x = StrToFloat(LabeledEdit4->Text); }
    catch (...) {
      LineOpt.XMarkerLabel.show = false; }
    }

  if (LabeledEdit5->Text.IsEmpty())
    LineOpt.YMarkerLabel.show = false;
  else {
    try {
      LineOpt.YMarkerLabel.x = StrToFloat(LabeledEdit5->Text); }
    catch (...) {
      LineOpt.YMarkerLabel.show = false; }
    }

  if (LabeledEdit9->Text.IsEmpty())
    LineOpt.AngleMarkerLabel.show = false;
  else {
    try {
      LineOpt.AngleMarkerLabel.x = StrToFloat(LabeledEdit9->Text); }
    catch (...) {
      LineOpt.AngleMarkerLabel.show = false; }
    }

  if (LineWidthComboBox2->Text.IsEmpty())
    LineOpt.LineGraphLineWidth.show = false;
  else
    LineOpt.LineGraphLineWidth.x = LiGrLineWidthComboBox->GetLineWidth();
}
//---------------------------------------------------------------------------

void TStyleForm::SetNumberOptions(void)
{
   if (NumOpt.DecimalPoints.show)
     NumOpt.DecimalPoints.i = cxSpinEdit3->EditValue;
}
//---------------------------------------------------------------------------

void TStyleForm::SetPresenceOptions(void)
{
  if (LabeledEdit7->Text.IsEmpty())
    PresOpt.MarkerSize.show = false;
  else {
    try {
      PresOpt.MarkerSize.x = StrToFloat(LabeledEdit7->Text); }
    catch (...) {
      PresOpt.MarkerSize.show = false; }
    }

  if (LabeledEdit8->Text.IsEmpty())
    PresOpt.XPresence.show = false;
  else {
    try {
      PresOpt.XPresence.x = StrToFloat(LabeledEdit8->Text);  }
    catch (...) {
      PresOpt.XPresence.show = false; } }
}
//---------------------------------------------------------------------------

void TStyleForm::ApplySilhouetteOptions(GRAPHS* graph)
{
   graph->GraphType = SILHOUETTE;

   if (SilOpt.SilhouetteFill != NO_FILL) {
     graph->SilhouetteFill = SilOpt.SilhouetteFill;
     if (SilOpt.SilhouettePattern != -1)
       graph->SilhouettePattern = SilOpt.SilhouettePattern;
     }

   if (SilOpt.Exag.show)
     graph->Exag = SilOpt.Exag.i;

   if (SilOpt.ExagFill != NO_FILL) {
     graph->ExagFill = SilOpt.ExagFill;
     if (SilOpt.ExagPattern != -1)
       graph->ExagPattern = SilOpt.ExagPattern;
     }

   if (SilOpt.ExagGrid != -1)
     graph->ExagGrid = SilOpt.ExagGrid;

   if (CheckBox1->State != cbGrayed)
     graph->DepthBars = CheckBox1->Checked;

   if (CheckBox2->State != cbGrayed)
     graph->DottedBaseLine = CheckBox2->Checked;

   if (SilOpt.GraphColor.show)
     graph->GraphColor = SilOpt.GraphColor.value;
   if (SilOpt.GraphOutlineColor.show)
     graph->GraphOutlineColor = SilOpt.GraphOutlineColor.value;
   if (SilOpt.ExagColor.show)
     graph->ExagColor = SilOpt.ExagColor.value;
   if (SilOpt.ExagOutlineColor.show)
     graph->ExagOutlineColor = SilOpt.ExagOutlineColor.value;
   if (SilOpt.DepthBarsColor.show)
     graph->DepthBarsColor = SilOpt.DepthBarsColor.value;

   if (SilOpt.SilhouetteLineWidth.show)
     graph->SilhouetteLineWidth = SilOpt.SilhouetteLineWidth.x;
}
//---------------------------------------------------------------------------

void TStyleForm::ApplyHistogramOptions(GRAPHS* graph)
{
  graph->GraphType = HISTOGRAM;

  if (HistOpt.HistogramLineWidth.show)
    graph->HistogramLineWidth = HistOpt.HistogramLineWidth.x;

  if (HistOpt.BarWidth.show)
    graph->BarWidth = HistOpt.BarWidth.x;

  if (HistOpt.BarFill != NO_FILL) {
     graph->BarFill = HistOpt.BarFill;
     if (HistOpt.BarPattern != -1)
       graph->BarPattern = HistOpt.BarPattern;
     }

  if (HistOpt.GraphColor.show)
     graph->GraphColor = HistOpt.GraphColor.value;

  if (CheckBox3->State != cbGrayed)
     graph->VerticalAxis = CheckBox3->Checked;

  if (CheckBox9->State != cbGrayed) {
    if (HistOpt.BarWidth.x < 0.02)
      graph->UseThickVar = false;
    else
      graph->UseThickVar = HistOpt.UseThickVar;
    }
}
//---------------------------------------------------------------------------

void TStyleForm::ApplyLineGraphOptions(GRAPHS* graph, XAXIS* xax)
{
  graph->GraphType = LINEGRAPH;

  if (LineOpt.marker_type_clicked)
    graph->MarkerType = LineOpt.MarkerType;

  if (LineOpt.MarkerSize.show)
    graph->MarkerSize = LineOpt.MarkerSize.x;

  if (CheckBox4->State != cbGrayed) {
     graph->SymbolName = CheckBox4->Checked;

     graph->AutoMarkerTop = LineOpt.AutoMarkerTop;
     graph->AutoMarkerBottom = LineOpt.AutoMarkerBottom;
     if (LineOpt.XMarkerLabel.show)
       graph->XMarkerLabel = LineOpt.XMarkerLabel.x;
     if (LineOpt.YMarkerLabel.show)
       graph->YMarkerLabel = LineOpt.YMarkerLabel.x;
     if (LineOpt.AngleMarkerLabel.show)
       graph->AngleMarkerLabel = LineOpt.AngleMarkerLabel.x;
     if (CheckBox7->State != cbGrayed) {
       if (graph->SymbolName && LineOpt.AutoMarkerTop)
         xax->PlotGraphName = false;
       else
         xax->PlotGraphName = CheckBox7->Checked;
       }
     }

  if (CheckBox5->State != cbGrayed)
     graph->ZeroSymbol = CheckBox5->Checked;

  if (LineOpt.GraphColor.show)
     graph->GraphColor = LineOpt.GraphColor.value;

  if (LineOpt.LineGraphLineWidth.show)
     graph->LineGraphLineWidth = LineOpt.LineGraphLineWidth.x;
}
//---------------------------------------------------------------------------

void TStyleForm::ApplyNumberOptions(GRAPHS* graph)
{
  graph->GraphType = NUMBERS;

  graph->NumberFont = NumOpt.NumberFont;
  graph->GraphColor = graph->NumberFont.Color;

  if (NumOpt.DecimalPoints.show)
    graph->DecimalPoints = NumOpt.DecimalPoints.i;

  if (CheckBox8->State != cbGrayed)
    graph->PlotZeroNumbers = CheckBox8->Checked;
}
//---------------------------------------------------------------------------

void TStyleForm::ApplyPresenceOptions(GRAPHS* graph, XAXIS* xax)
{
  graph->GraphType = PRESENCE;

  if (CheckBox6->State != cbGrayed)
    graph->PresenceSymbol = CheckBox6->Checked;

  if (PresOpt.MarkerSize.show)
    graph->MarkerSize = PresOpt.MarkerSize.x;

  if (PresOpt.XPresence.show) {
    graph->XPresence = PresOpt.XPresence.x;
    xax->AutoTic = false;
    xax->MinorTics = graph->XPresence;
    xax->MajorTics = 2.0*xax->MinorTics;
    xax->LabeledTics = 2.0*xax->MajorTics;
    xax->MinorTicLength = 0.0;
    xax->TopTicLength = 0.0;

    if (Spawned) {
      XaxesForm->X.xax.AutoTic = false;
      XaxesForm->X.xax.MinorTics = xax->MinorTics;
      XaxesForm->X.xax.MajorTics = xax->MajorTics;
      XaxesForm->X.xax.LabeledTics = xax->LabeledTics;
      XaxesForm->X.xax.MinorTicLength = 0.0;
      XaxesForm->X.xax.TopTicLength = 0.0;
      }
    }

  if (PresOpt.GraphColor.show)
     graph->GraphColor = PresOpt.GraphColor.value;
}
//---------------------------------------------------------------------------

void __fastcall TStyleForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  if (! Spawned) {
    if (VarList != NULL) delete[] VarList;
    VarList = NULL;
    }
}
//---------------------------------------------------------------------------


void __fastcall TStyleForm::RadioGroup2Click(TObject *Sender)
{
  if (RadioGroup2->ItemIndex == 2) {
    Button6->Enabled = true;
	Shape1->Visible = true;
	if (SilOpt.SilhouettePattern > 0) {
	  //Shape1->Brush->Bitmap =
	  //	(Graphics::TBitmap *)ParentForm->GKSBitmaps->Items[SilOpt.SilhouettePattern-1];
      Shape1->Brush->Bitmap = ParentForm->GKSBitmaps[SilOpt.SilhouettePattern-1];
	  Shape1->Pen->Style = psSolid;
      }
    else {
      Shape1->Brush->Bitmap = NULL;
      Shape1->Brush->Style = bsClear;
      Shape1->Pen->Style = psDot;
      }
    }
  else {
    Button6->Enabled = false;
    Shape1->Brush->Bitmap = NULL;
    Shape1->Visible = false;
    }
}
//---------------------------------------------------------------------------

void __fastcall TStyleForm::RadioGroup3Click(TObject *Sender)
{
  if (RadioGroup3->ItemIndex == 2) {
    Button5->Enabled = true;
    Shape2->Visible = true;
    if (SilOpt.ExagPattern > 0) {
	  //Shape2->Brush->Bitmap =
	  //	(Graphics::TBitmap *)ParentForm->GKSBitmaps->Items[SilOpt.ExagPattern-1];
	  Shape2->Brush->Bitmap = ParentForm->GKSBitmaps[SilOpt.ExagPattern-1];
	  Shape2->Pen->Style = psSolid;
      }
    else {
      Shape2->Brush->Bitmap = NULL;
      Shape2->Pen->Style = psDot;
      Shape2->Brush->Style = bsClear;
      }
    }
  else {
    Button5->Enabled = false;
    Shape2->Brush->Bitmap = NULL;
    Shape2->Visible = false;
    }

  RadioGroup1->Enabled = (RadioGroup3->ItemIndex == 4) ? true : false;
}
//---------------------------------------------------------------------------

// exaggerated curve pattern
void __fastcall TStyleForm::Button5Click(TObject *Sender)
{
  PatternForm = new TPatternForm(this);
  PatternForm->Initialize(SilOpt.ExagPattern);
  if (PatternForm->ShowModal() == mrOk) {
    SilOpt.ExagPattern = PatternForm->PatternIndex;
	if (SilOpt.ExagPattern > 0) {
	  Shape2->Brush->Bitmap = ParentForm->GKSBitmaps[SilOpt.ExagPattern-1];
	  Shape2->Pen->Style = psSolid;
	  Shape2->Visible = true;
	  }
	}
  delete PatternForm;
}
//---------------------------------------------------------------------------

// main curve pattern
void __fastcall TStyleForm::Button6Click(TObject *Sender)
{
  PatternForm = new TPatternForm(this);
  PatternForm->Initialize(SilOpt.SilhouettePattern);
  if (PatternForm->ShowModal() == mrOk) {
	SilOpt.SilhouettePattern = PatternForm->PatternIndex;
	if (SilOpt.SilhouettePattern > 0) {
	  Shape1->Brush->Bitmap = ParentForm->GKSBitmaps[SilOpt.SilhouettePattern-1];
	  Shape1->Pen->Style = psSolid;
      Shape1->Visible = true;
      }
    }
  delete PatternForm;
}
//---------------------------------------------------------------------------

void __fastcall TStyleForm::cxColorComboBox1PropertiesInitPopup(TObject *Sender)
{
   Diag->InitColorComboBoxPopup(cxColorComboBox1);
}
//---------------------------------------------------------------------------

void __fastcall TStyleForm::cxColorComboBox2PropertiesInitPopup(TObject *Sender)
{
   Diag->InitColorComboBoxPopup(cxColorComboBox2);
}
//---------------------------------------------------------------------------

void __fastcall TStyleForm::cxColorComboBox3PropertiesInitPopup(TObject *Sender)
{
   Diag->InitColorComboBoxPopup(cxColorComboBox3);
}
//---------------------------------------------------------------------------

void __fastcall TStyleForm::cxColorComboBox4PropertiesInitPopup(TObject *Sender)
{
   Diag->InitColorComboBoxPopup(cxColorComboBox4);
}
//---------------------------------------------------------------------------

void __fastcall TStyleForm::cxColorComboBox5PropertiesInitPopup(TObject *Sender)
{
   Diag->InitColorComboBoxPopup(cxColorComboBox5);
}
//---------------------------------------------------------------------------

void __fastcall TStyleForm::cxColorComboBox6PropertiesInitPopup(TObject *Sender)
{
   Diag->InitColorComboBoxPopup(cxColorComboBox6);
}
//---------------------------------------------------------------------------

void __fastcall TStyleForm::cxColorComboBox7PropertiesInitPopup(TObject *Sender)
{
   Diag->InitColorComboBoxPopup(cxColorComboBox7);
}
//---------------------------------------------------------------------------

void __fastcall TStyleForm::cxColorComboBox8PropertiesInitPopup(TObject *Sender)
{
   Diag->InitColorComboBoxPopup(cxColorComboBox8);
}
//---------------------------------------------------------------------------

void __fastcall TStyleForm::cxColorComboBox1PropertiesSelectCustomColor(TObject *Sender,
		  TColor &AColor, UnicodeString &AColorDescription, bool &AddToList)
{
   Diag->SetCustomColor(AColor, AColorDescription);
}
//---------------------------------------------------------------------------

void __fastcall TStyleForm::cxColorComboBox2PropertiesSelectCustomColor(TObject *Sender,
		  TColor &AColor, UnicodeString &AColorDescription, bool &AddToList)
{
   Diag->SetCustomColor(AColor, AColorDescription);
}
//---------------------------------------------------------------------------

void __fastcall TStyleForm::cxColorComboBox3PropertiesSelectCustomColor(TObject *Sender,
		  TColor &AColor, UnicodeString &AColorDescription, bool &AddToList)
{
   Diag->SetCustomColor(AColor, AColorDescription);
}
//---------------------------------------------------------------------------

void __fastcall TStyleForm::cxColorComboBox4PropertiesSelectCustomColor(TObject *Sender,
		  TColor &AColor, UnicodeString &AColorDescription, bool &AddToList)
{
   Diag->SetCustomColor(AColor, AColorDescription);
}
//---------------------------------------------------------------------------

void __fastcall TStyleForm::cxColorComboBox5PropertiesSelectCustomColor(TObject *Sender,
		  TColor &AColor, UnicodeString &AColorDescription, bool &AddToList)
{
   Diag->SetCustomColor(AColor, AColorDescription);
}
//---------------------------------------------------------------------------

void __fastcall TStyleForm::cxColorComboBox6PropertiesSelectCustomColor(TObject *Sender,
		  TColor &AColor, UnicodeString &AColorDescription, bool &AddToList)
{
   Diag->SetCustomColor(AColor, AColorDescription);
}
//---------------------------------------------------------------------------

void __fastcall TStyleForm::cxColorComboBox7PropertiesSelectCustomColor(TObject *Sender,
		  TColor &AColor, UnicodeString &AColorDescription, bool &AddToList)
{
   Diag->SetCustomColor(AColor, AColorDescription);
}
//---------------------------------------------------------------------------

void __fastcall TStyleForm::cxColorComboBox8PropertiesSelectCustomColor(TObject *Sender,
		  TColor &AColor, UnicodeString &AColorDescription, bool &AddToList)
{
   Diag->SetCustomColor(AColor, AColorDescription);
}
//---------------------------------------------------------------------------

void TStyleForm::SetGraphColors(TColor Color)
{
   Diag->SetColorComboBox(cxColorComboBox1, Color);
   SilOpt.GraphColor.value = Color;
   Diag->SetColorComboBox(cxColorComboBox6, Color);
   HistOpt.GraphColor.value = Color;
   Diag->SetColorComboBox(cxColorComboBox7, Color);
   LineOpt.GraphColor.value = Color;
   NumOpt.NumberFont.Color = Color;
   Diag->SetColorComboBox(cxColorComboBox8, Color);
   PresOpt.GraphColor.value = Color;
}
//---------------------------------------------------------------------------

void __fastcall TStyleForm::cxColorComboBox1PropertiesChange(TObject *Sender)
{
   int idx = cxColorComboBox1->ItemIndex;
   SilOpt.GraphColor.value = cxColorComboBox1->Properties->Items->GetColorByIndex(idx,clBlack);
   SilOpt.GraphColor.show = true;
   SetGraphColors(SilOpt.GraphColor.value);
}
//---------------------------------------------------------------------------

void __fastcall TStyleForm::cxColorComboBox2PropertiesChange(TObject *Sender)
{
   int idx = cxColorComboBox2->ItemIndex;
   SilOpt.GraphOutlineColor.value = cxColorComboBox2->Properties->Items->GetColorByIndex(idx,clBlack);
   SilOpt.GraphOutlineColor.show = true;
}
//---------------------------------------------------------------------------

void __fastcall TStyleForm::cxColorComboBox3PropertiesChange(TObject *Sender)
{
   int idx = cxColorComboBox3->ItemIndex;
   SilOpt.ExagColor.value = cxColorComboBox3->Properties->Items->GetColorByIndex(idx,clBlack);
   SilOpt.ExagColor.show = true;
}
//---------------------------------------------------------------------------

void __fastcall TStyleForm::cxColorComboBox4PropertiesChange(TObject *Sender)
{
   int idx = cxColorComboBox4->ItemIndex;
   SilOpt.ExagOutlineColor.value = cxColorComboBox4->Properties->Items->GetColorByIndex(idx,clBlack);
   SilOpt.ExagOutlineColor.show = true;
}
//---------------------------------------------------------------------------

void __fastcall TStyleForm::cxColorComboBox5PropertiesChange(TObject *Sender)
{
   int idx = cxColorComboBox5->ItemIndex;
   SilOpt.DepthBarsColor.value = cxColorComboBox5->Properties->Items->GetColorByIndex(idx,clBlack);
   SilOpt.DepthBarsColor.show = true;
}
//---------------------------------------------------------------------------

void __fastcall TStyleForm::RadioGroup4Click(TObject *Sender)
{
  if (RadioGroup4->ItemIndex == 2 && HistOpt.BarWidth.show) {
    Button11->Enabled = true;
    if (HistOpt.BarPattern > 0) {
	  Shape7->Brush->Bitmap = ParentForm->GKSBitmaps[HistOpt.BarPattern-1];
	  Shape7->Pen->Style = psSolid;
	  }
    else {
      Shape7->Brush->Bitmap = NULL;
      Shape7->Brush->Style = bsClear;
      Shape7->Pen->Style = psClear;
      }
    }
  else {
    Button11->Enabled = false;
    Shape7->Brush->Bitmap = NULL;
    Shape7->Brush->Style = bsClear;
    Shape7->Pen->Style = psClear;
    }
}
//---------------------------------------------------------------------------

void __fastcall TStyleForm::Button11Click(TObject *Sender)
{
  PatternForm = new TPatternForm(this);
  PatternForm->Initialize(HistOpt.BarPattern);
  if (PatternForm->ShowModal() == mrOk) {
    HistOpt.BarPattern = PatternForm->PatternIndex;
	if (HistOpt.BarPattern > 0) {
	  //Shape7->Brush->Bitmap =
	  //	(Graphics::TBitmap *)ParentForm->GKSBitmaps->Items[HistOpt.BarPattern-1];
	  Shape7->Brush->Bitmap = ParentForm->GKSBitmaps[HistOpt.BarPattern-1];
	  Shape7->Pen->Style = psSolid;
      }
    }
  delete PatternForm;
}
//---------------------------------------------------------------------------

void __fastcall TStyleForm::cxColorComboBox6PropertiesChange(TObject *Sender)
{
   int idx = cxColorComboBox6->ItemIndex;
   HistOpt.GraphColor.value = cxColorComboBox6->Properties->Items->GetColorByIndex(idx,clBlack);
   HistOpt.GraphColor.show = true;
   SetGraphColors(HistOpt.GraphColor.value);
}
//---------------------------------------------------------------------------

void __fastcall TStyleForm::CheckBox4Click(TObject *Sender)
{
   CheckBox4->AllowGrayed = false;

   if (CheckBox4->Checked && CheckBox4->State != cbGrayed) {
     RadioGroup5->Enabled = true;
     switch (RadioGroup5->ItemIndex)
      {
      case 0:
        LabeledEdit4->Enabled = false;
        LabeledEdit5->Enabled = false;
        LabeledEdit9->Enabled = false;
        LabeledEdit4->Color = clBtnFace;
        LabeledEdit5->Color = clBtnFace;
        LabeledEdit9->Color = clBtnFace;
        CheckBox7->Enabled = false;
        CheckBox7->Checked = false;
        break;
      case 1:
        LabeledEdit4->Enabled = false;
        LabeledEdit5->Enabled = false;
        LabeledEdit9->Enabled = false;
        LabeledEdit4->Color = clBtnFace;
        LabeledEdit5->Color = clBtnFace;
        LabeledEdit9->Color = clBtnFace;
        CheckBox7->Enabled = true;
        break;
      case 2:
        LabeledEdit4->Enabled = true;
        LabeledEdit5->Enabled = true;
        LabeledEdit9->Enabled = true;
        LabeledEdit4->Color = clWindow;
        LabeledEdit5->Color = clWindow;
        LabeledEdit9->Color = clWindow;
        CheckBox7->Enabled = true;
        break;
      }
     }
   else {
     RadioGroup5->Enabled = false;
     LabeledEdit4->Enabled = false;
     LabeledEdit5->Enabled = false;
     LabeledEdit9->Enabled = false;
     LabeledEdit4->Color = clBtnFace;
     LabeledEdit5->Color = clBtnFace;
     LabeledEdit9->Color = clBtnFace;
     CheckBox7->Enabled = false;
     CheckBox7->Checked = true;
     }

}
//---------------------------------------------------------------------------

void __fastcall TStyleForm::RadioGroup5Click(TObject *Sender)
{
  switch (RadioGroup5->ItemIndex)
   {
    case 0:
      LabeledEdit4->Enabled = false;
      LabeledEdit5->Enabled = false;
      LabeledEdit9->Enabled = false;
      LabeledEdit4->Color = clBtnFace;
      LabeledEdit5->Color = clBtnFace;
      LabeledEdit9->Color = clBtnFace;
      CheckBox7->Enabled = false;
      CheckBox7->Checked = false;
      break;
    case 1:
      LabeledEdit4->Enabled = false;
      LabeledEdit5->Enabled = false;
      LabeledEdit9->Enabled = false;
      LabeledEdit4->Color = clBtnFace;
      LabeledEdit5->Color = clBtnFace;
      LabeledEdit9->Color = clBtnFace;
      CheckBox7->Enabled = CheckBox4->Checked;
      break;
    case 2:
      LabeledEdit4->Enabled = true;
      LabeledEdit5->Enabled = true;
      LabeledEdit9->Enabled = true;
      LabeledEdit4->Color = clWindow;
      LabeledEdit5->Color = clWindow;
      LabeledEdit9->Color = clWindow;
      CheckBox7->Enabled = CheckBox4->Checked;
      break;
   }
}
//---------------------------------------------------------------------------

void __fastcall TStyleForm::ToolButton1Click(TObject *Sender)
{
  LineOpt.MarkerType = 0;
  CheckBox4->Enabled = false;
  CheckBox7->Enabled = false;
  RadioGroup5->Enabled = false;
  LabeledEdit4->Enabled = false;
  LabeledEdit5->Enabled = false;
  LabeledEdit9->Enabled = false;
  LabeledEdit4->Color = clBtnFace;
  LabeledEdit5->Color = clBtnFace;
  LabeledEdit9->Color = clBtnFace;
  LineOpt.marker_type_clicked = true;
}
//---------------------------------------------------------------------------

void TStyleForm::EnableLabels(void)
{
  CheckBox4->Enabled = true;
  if (CheckBox4->Checked && CheckBox4->State != cbGrayed) {
    RadioGroup5->Enabled = true;

    switch (RadioGroup5->ItemIndex)
      {
      case 0:
        LabeledEdit4->Enabled = false;
        LabeledEdit5->Enabled = false;
        LabeledEdit9->Enabled = false;
        LabeledEdit4->Color = clBtnFace;
        LabeledEdit5->Color = clBtnFace;
        LabeledEdit9->Color = clBtnFace;
        CheckBox7->Enabled = false;
        CheckBox7->Checked = false;
        break;
      case 1:
        LabeledEdit4->Enabled = false;
        LabeledEdit5->Enabled = false;
        LabeledEdit9->Enabled = false;
        LabeledEdit4->Color = clBtnFace;
        LabeledEdit5->Color = clBtnFace;
        LabeledEdit9->Color = clBtnFace;
        CheckBox7->Enabled = true;
        break;
      case 2:
        LabeledEdit4->Enabled = true;
        LabeledEdit5->Enabled = true;
        LabeledEdit9->Enabled = true;
        LabeledEdit4->Color = clWindow;
        LabeledEdit5->Color = clWindow;
        LabeledEdit9->Color = clWindow;
        CheckBox7->Enabled = true;
        break;
      }
    }
    LineOpt.marker_type_clicked = true;
}
//---------------------------------------------------------------------------

void __fastcall TStyleForm::ToolButton2Click(TObject *Sender)
{
  LineOpt.MarkerType = 1;
  EnableLabels();
}
//---------------------------------------------------------------------------

void __fastcall TStyleForm::ToolButton3Click(TObject *Sender)
{
  LineOpt.MarkerType = 2;
  EnableLabels();
}
//---------------------------------------------------------------------------

void __fastcall TStyleForm::ToolButton4Click(TObject *Sender)
{
  LineOpt.MarkerType = 3;
  EnableLabels();
}
//---------------------------------------------------------------------------

void __fastcall TStyleForm::ToolButton5Click(TObject *Sender)
{
  LineOpt.MarkerType = 4;
  EnableLabels();
}
//---------------------------------------------------------------------------

void __fastcall TStyleForm::ToolButton6Click(TObject *Sender)
{
  LineOpt.MarkerType = 5;
  EnableLabels();
}
//---------------------------------------------------------------------------

void __fastcall TStyleForm::ToolButton7Click(TObject *Sender)
{
  LineOpt.MarkerType = 6;
  EnableLabels();
}
//---------------------------------------------------------------------------

void __fastcall TStyleForm::ToolButton8Click(TObject *Sender)
{
  LineOpt.MarkerType = 7;
  EnableLabels();
}
//---------------------------------------------------------------------------

void __fastcall TStyleForm::ToolButton9Click(TObject *Sender)
{
  LineOpt.MarkerType = 8;
  EnableLabels();
}
//---------------------------------------------------------------------------

void __fastcall TStyleForm::ToolButton10Click(TObject *Sender)
{
  LineOpt.MarkerType = 9;
  EnableLabels();
}
//---------------------------------------------------------------------------

void __fastcall TStyleForm::ToolButton11Click(TObject *Sender)
{
  LineOpt.MarkerType = 10;
  EnableLabels();
}
//---------------------------------------------------------------------------

void __fastcall TStyleForm::ToolButton12Click(TObject *Sender)
{
  LineOpt.MarkerType = 11;
  EnableLabels();
}
//---------------------------------------------------------------------------

void __fastcall TStyleForm::ToolButton13Click(TObject *Sender)
{
  LineOpt.MarkerType = 12;
  EnableLabels();
}
//---------------------------------------------------------------------------

void __fastcall TStyleForm::ToolButton14Click(TObject *Sender)
{
  LineOpt.MarkerType = 13;
  EnableLabels();
}
//---------------------------------------------------------------------------

void __fastcall TStyleForm::ToolButton15Click(TObject *Sender)
{
  LineOpt.MarkerType = 14;
  EnableLabels();
}
//---------------------------------------------------------------------------

void __fastcall TStyleForm::ToolButton16Click(TObject *Sender)
{
  LineOpt.MarkerType = 15;
  EnableLabels();
}
//---------------------------------------------------------------------------

void __fastcall TStyleForm::ToolButton17Click(TObject *Sender)
{
  LineOpt.MarkerType = 16;
  EnableLabels();
}
//---------------------------------------------------------------------------

void __fastcall TStyleForm::ToolButton18Click(TObject *Sender)
{
  LineOpt.MarkerType = 17;
  EnableLabels();
}
//---------------------------------------------------------------------------

void __fastcall TStyleForm::ToolButton19Click(TObject *Sender)
{
  LineOpt.MarkerType = 18;
  EnableLabels();
}
//---------------------------------------------------------------------------

void __fastcall TStyleForm::ToolButton20Click(TObject *Sender)
{
  LineOpt.MarkerType = 19;
  EnableLabels();
}
//---------------------------------------------------------------------------

void __fastcall TStyleForm::ToolButton21Click(TObject *Sender)
{
  LineOpt.MarkerType = 20;
  EnableLabels();
}
//---------------------------------------------------------------------------

void __fastcall TStyleForm::ToolButton22Click(TObject *Sender)
{
  LineOpt.MarkerType = 21;
  EnableLabels();
}
//---------------------------------------------------------------------------

void __fastcall TStyleForm::ToolButton23Click(TObject *Sender)
{
  LineOpt.MarkerType = 22;
  EnableLabels();
}
//---------------------------------------------------------------------------

void __fastcall TStyleForm::ToolButton24Click(TObject *Sender)
{
  LineOpt.MarkerType = 23;
  EnableLabels();
}
//---------------------------------------------------------------------------

void __fastcall TStyleForm::ToolButton25Click(TObject *Sender)
{
  LineOpt.MarkerType = 24;
  EnableLabels();
}
//---------------------------------------------------------------------------

void __fastcall TStyleForm::ToolButton26Click(TObject *Sender)
{
  LineOpt.MarkerType = 25;
  EnableLabels();
}
//---------------------------------------------------------------------------

void __fastcall TStyleForm::ToolButton27Click(TObject *Sender)
{
  LineOpt.MarkerType = 26;
  EnableLabels();
}
//---------------------------------------------------------------------------

void __fastcall TStyleForm::ToolButton28Click(TObject *Sender)
{
  LineOpt.MarkerType = 27;
  EnableLabels();
}
//---------------------------------------------------------------------------

void __fastcall TStyleForm::ToolButton29Click(TObject *Sender)
{
  LineOpt.MarkerType = 28;
  EnableLabels();
}
//---------------------------------------------------------------------------

void __fastcall TStyleForm::ToolButton30Click(TObject *Sender)
{
  LineOpt.MarkerType = 29;
  EnableLabels();
}
//---------------------------------------------------------------------------

void __fastcall TStyleForm::ToolButton31Click(TObject *Sender)
{
  LineOpt.MarkerType = 30;
  EnableLabels();
}
//---------------------------------------------------------------------------

void __fastcall TStyleForm::ToolButton32Click(TObject *Sender)
{
  LineOpt.MarkerType = 31;
  EnableLabels();
}
//---------------------------------------------------------------------------

void __fastcall TStyleForm::ToolButton33Click(TObject *Sender)
{
  LineOpt.MarkerType = 32;
  EnableLabels();
}
//---------------------------------------------------------------------------

void __fastcall TStyleForm::cxColorComboBox7PropertiesChange(TObject *Sender)
{
   int idx = cxColorComboBox7->ItemIndex;
   LineOpt.GraphColor.value = cxColorComboBox7->Properties->Items->GetColorByIndex(idx,clBlack);
   LineOpt.GraphColor.show = true;
   SetGraphColors(LineOpt.GraphColor.value);
}
//---------------------------------------------------------------------------

void __fastcall TStyleForm::BitBtn2Click(TObject *Sender)
{
   TFontDialogBox* FontForm = new TFontDialogBox(this);
   FontForm->SetFont(NumOpt.NumberFont);
   if (FontForm->ShowModal() == mrOk) {
     FontForm->GetFont(NumOpt.NumberFont);
	 SetGraphColors((TColor)NumOpt.NumberFont.Color);
	 }
   delete FontForm;
}
//---------------------------------------------------------------------------

void __fastcall TStyleForm::cxColorComboBox8PropertiesChange(TObject *Sender)
{
   int idx = cxColorComboBox8->ItemIndex;
   PresOpt.GraphColor.value = cxColorComboBox8->Properties->Items->GetColorByIndex(idx,clBlack);
   PresOpt.GraphColor.show = true;
   SetGraphColors(PresOpt.GraphColor.value);
}
//---------------------------------------------------------------------------

void __fastcall TStyleForm::cxSpinEdit1PropertiesChange(TObject *Sender)
{
  if (SilOpt.TabSheetInitialized)
    SilOpt.Exag.show = true;
}
//---------------------------------------------------------------------------

void __fastcall TStyleForm::cxSpinEdit1PropertiesValidate(TObject *Sender,
      Variant &DisplayValue, TCaption &ErrorText, bool &Error)
{
   if (Error && ErrorText == "Value out of bounds") {
     DisplayValue = 0;
     Error = false;
     ErrorText = "";
     }
}
//---------------------------------------------------------------------------

void __fastcall TStyleForm::cxSpinEdit2PropertiesChange(TObject *Sender)
{
   if (HistOpt.TabSheetInitialized)
     HistOpt.BarWidth.show = true;
}
//---------------------------------------------------------------------------

void __fastcall TStyleForm::cxSpinEdit2PropertiesValidate(TObject *Sender,
      Variant &DisplayValue, TCaption &ErrorText, bool &Error)
{
   if (Error && ErrorText == "Value out of bounds") {
     DisplayValue = 0.02;
     Error = false;
     ErrorText = "";
     }
}
//---------------------------------------------------------------------------

void __fastcall TStyleForm::cxSpinEdit3PropertiesChange(TObject *Sender)
{
   if (NumOpt.TabSheetInitialized)
     NumOpt.DecimalPoints.show = true;
}
//---------------------------------------------------------------------------

void __fastcall TStyleForm::cxSpinEdit3PropertiesValidate(TObject *Sender,
      Variant &DisplayValue, TCaption &ErrorText, bool &Error)
{
   if (Error && ErrorText == "Value out of bounds") {
     DisplayValue = 0;
     Error = false;
     ErrorText = "";
     }
}
//---------------------------------------------------------------------------

void __fastcall TStyleForm::LineWidthComboBox1Change(TObject *Sender)
{
  SilOpt.SilhouetteLineWidth.show = true;
}
//---------------------------------------------------------------------------

void __fastcall TStyleForm::LabeledEdit3Change(TObject *Sender)
{
  if (LineOpt.TabSheetInitialized) {
    LineOpt.MarkerSize.show = true;
    }
}
//---------------------------------------------------------------------------

void __fastcall TStyleForm::LabeledEdit4Change(TObject *Sender)
{
  if (LineOpt.TabSheetInitialized)
    LineOpt.XMarkerLabel.show = true;
}
//---------------------------------------------------------------------------

void __fastcall TStyleForm::LabeledEdit5Change(TObject *Sender)
{
  if (LineOpt.TabSheetInitialized)
    LineOpt.YMarkerLabel.show = true;
}
//---------------------------------------------------------------------------

void __fastcall TStyleForm::LabeledEdit9Change(TObject *Sender)
{
  if (LineOpt.TabSheetInitialized)
    LineOpt.AngleMarkerLabel.show = true;
}
//---------------------------------------------------------------------------

void __fastcall TStyleForm::LabeledEdit7Change(TObject *Sender)
{
  if (PresOpt.TabSheetInitialized) {
    PresOpt.MarkerSize.show = true;
    }
}
//---------------------------------------------------------------------------

void __fastcall TStyleForm::LabeledEdit8Change(TObject *Sender)
{
  if (PresOpt.TabSheetInitialized) {
    PresOpt.XPresence.show = true;
    }
}
//---------------------------------------------------------------------------

// Apply button
void __fastcall TStyleForm::Button18Click(TObject *Sender)
{
   Diag->Modified = true;
   ApplyOptions();
   Diag->make_diagram();
   Diag->Picture->OutputGraphicObjects(DISPLAY, (TTGDiagram*)ParentForm->ActiveMDIChild);

   // user defined coordinates for line graphs

   for (int i=0; i<VarCount; i++)
     if (VarList[i].Checked) {
        GRAPH* g = (GRAPH*)Diag->grf->Items[VarList[i].VarNum];
        InitLineGraphOptions(g->graph, g->xax);
        break;
        }

   LineOpt.XMarkerLabel.show = true;
   LineOpt.YMarkerLabel.show = true;
   LineOpt.AngleMarkerLabel.show = true;
   LabeledEdit4->Text = FloatToStr(LineOpt.XMarkerLabel.x);
   LabeledEdit5->Text = FloatToStr(LineOpt.YMarkerLabel.x);
   LabeledEdit9->Text = FloatToStr(LineOpt.AngleMarkerLabel.x);
}
//---------------------------------------------------------------------------

void __fastcall TStyleForm::CheckBox2Click(TObject *Sender)
{
  CheckBox2->AllowGrayed = false;
}
//---------------------------------------------------------------------------

void __fastcall TStyleForm::CheckBox1Click(TObject *Sender)
{
  CheckBox1->AllowGrayed = false;
}
//---------------------------------------------------------------------------

void __fastcall TStyleForm::CheckBox3Click(TObject *Sender)
{
  CheckBox3->AllowGrayed = false;      
}
//---------------------------------------------------------------------------

void __fastcall TStyleForm::CheckBox7Click(TObject *Sender)
{
  CheckBox7->AllowGrayed = false;      
}
//---------------------------------------------------------------------------

void __fastcall TStyleForm::CheckBox5Click(TObject *Sender)
{
  CheckBox5->AllowGrayed = false;
}
//---------------------------------------------------------------------------

void __fastcall TStyleForm::CheckBox8Click(TObject *Sender)
{
  CheckBox8->AllowGrayed = false;
}
//---------------------------------------------------------------------------

void __fastcall TStyleForm::CheckBox6Click(TObject *Sender)
{
  CheckBox6->AllowGrayed = false;
}
//---------------------------------------------------------------------------

void __fastcall TStyleForm::BitBtn1Click(TObject *Sender)
{
  if (Spawned) {
    ApplyOptions();
    Diag->make_diagram();
	Diag->Picture->OutputGraphicObjects(DISPLAY, (TTGDiagram*)ParentForm->ActiveMDIChild);
    Close();
    }
  else {
    XaxesForm = new TXaxesForm(this);
    XaxesForm->Diag = Diag;
    XaxesForm->Spawn(VarList, VarCount, this);
    XaxesForm->ShowModal();
    delete XaxesForm;
    }

  if (PresOpt.XPresence.show)
    LabeledEdit8->Text = FloatToStr(PresOpt.XPresence.x);
}
//---------------------------------------------------------------------------

void __fastcall TStyleForm::LineWidthComboBox2Change(TObject *Sender)
{
  LineOpt.LineGraphLineWidth.show = true;
}
//---------------------------------------------------------------------------

// Help button
void __fastcall TStyleForm::Button3Click(TObject *Sender)
{
   Application->HelpContext(IDH_Graph_Style_Dialog_Box);
}
//---------------------------------------------------------------------------

bool __fastcall TStyleForm::FormHelp(WORD Command, int Data, bool &CallHelp)
{
   return true;
}
//---------------------------------------------------------------------------

void __fastcall TStyleForm::CheckBox9Click(TObject *Sender)
{
   if (CheckBox9->Checked) {
     cxSpinEdit2->Style->Color = clBtnFace;
     cxSpinEdit2->Enabled = false;
     HistOpt.UseThickVar = true;
     }
   else {
     cxSpinEdit2->Style->Color = clWindow;
     cxSpinEdit2->Enabled = true;
     HistOpt.UseThickVar = false;
     }
}
//---------------------------------------------------------------------------

