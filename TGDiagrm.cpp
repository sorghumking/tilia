//---------------------------------------------------------------------------
#include <FileCtrl.hpp>
#define VCL_IOSTREAM
#include <vcl.h>
#include "pch.h"
#include <GIFimg.hpp>
#pragma hdrstop

#ifndef TGH
#include "tg.h"
#endif
#ifndef TIGlobalsH
#include "TIGlobals.h"
#endif
#ifndef StrngOpsH
#include "StrngOps.h"
#endif
#ifndef TGZoneOpH
#include "TGZoneOp.h"
#endif
#ifndef TGGrpFrmH
#include "TGGrpFrm.h"
#endif
#ifndef TGDatFrmH
#include "TGDatFrm.h"
#endif
#ifndef TGDiagrmH
#include "TGDiagrm.h"
#endif
#ifndef TGTextH
#include "TGText.h"
#endif
#ifndef TGZoneOpH
#include "TGZoneOp.h"
#endif
#ifndef TGLthFrmH
#include "TGLthFrm.h"
#endif
#ifndef TGDgrFrmH
#include "TGDgrFrm.h"
#endif
#ifndef TGDiagrmH
#include "TGDiagrm.h"
#endif
#ifndef TGParentH
#include "TGParent.h"
#endif
//#ifndef GraphicsH
//#include "Graphics.h"
//#endif
#ifndef TGraphicH
#include "TGraphic.h"
#endif
#ifndef TGtgfioH
#include "Tgtgfio.h"
#endif
//#ifndef TGtgwioH
//#include "TGtgwio.h"
//#endif
#ifndef TGStyleH
#include "TGStyle.h"
#endif
#ifndef TGXaxFrmH
#include "TGXaxFrm.h"
#endif
#ifndef TGNewTxtH
#include "TGNewTxt.h"
#endif
#ifndef TGYaxisH
#include "TGYaxis.h"
#endif
#ifndef TGUtilsH
#include "TGUtils.h"
#endif
#ifndef TGColorsH
#include "TGColors.h"
#endif
#ifndef TGPrintH
#include "TGPrint.h"
#endif
#ifndef TGLinWidH
#include "TGLinWid.h"
#endif
#ifndef TGFntDlgH
#include "TGFntDlg.h"
#endif
#ifndef TGYaxFrmH
#include "TGYaxFrm.h"
#endif
#ifndef TGXaxFrmH
#include "TGXaxFrm.h"
#endif
#ifndef TGStyleH
#include "TGStyle.h"
#endif
#ifndef TGOrderH
#include "TGOrder.h"
#endif
#ifndef TGZoneOpH
#include "TGZoneOp.h"
#endif
#ifndef TGGrpFrmH
#include "TGGrpFrm.h"
#endif
#ifndef TGDateFrmH
#include "TGDatFrm.h"
#endif
#ifndef TGLthFrmH
#include "TGLthFrm.h"
#endif
#ifndef TGTxtFrmH
#include "TGTxtFrm.h"
#endif
#ifndef TGDgrFrmH
#include "TGDgrFrm.h"
#endif
#ifndef TGFrameH
#include "TGFrame.h"
#endif
#ifndef TGRareH
#include "TGRare.h"
#endif
#ifndef TGtgxioH
#include "TGtgxio.h"
#endif
#ifndef TIXMLH
#include "TIXML.h"
#endif


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "ipwCore"
#pragma link "ipwxmlp"
#pragma link "ipworks"
#pragma link "cxGraphics"
#pragma resource "*.dfm"


//---------------------------------------------------------------------------
__fastcall TTGDiagram::TTGDiagram(TComponent* Owner)
    : TForm(Owner)
{
}

//---------------------------------------------------------------------------
void __fastcall TTGDiagram::FormCreate(TObject *Sender)
{
   MouseDown = false;
   Dragging = false;
   AddText = false;
   FormClicked = false;
   ParentElement = -1;
   CurrentElement = -1;
   ClientHeight = (int)(0.7*(double)tiGlobals->ClientHeight);
   ClientWidth = (int)(0.8*(double)tiGlobals->ClientWidth);
   if (ParentForm->MDIChildCount == 1) {
     Left = 0;
     Top = 0;
     }
   else {
     Left = 22 + ParentForm->CurrentChildPos.x;
     Top = 22 + ParentForm->CurrentChildPos.y;
	 }
   ipwXMLp1->Config("CodePage=65001");
}

//---------------------------------------------------------------------------

void __fastcall TTGDiagram::FormActivate(TObject *Sender)
{
  Modified = false;
  UnicodeString ztext;

  vector<TToolBar*> ToolBars;
  ToolBars.push_back(ParentForm->ToolBarFile);
  ToolBars.push_back(ParentForm->ToolBarHelp);
  ToolBars.push_back(ParentForm->ToolBarZoomText);
  ToolBars.push_back(ParentForm->ToolBarZoomPlusMinus);
  ToolBars.push_back(ParentForm->ToolBarGraphics);
  ParentForm->SetToolBars(ToolBars);

  ParentForm->StatusBar1->Panels->Items[0]->Text =
     MinimizeName(TGFileName, ParentForm->StatusBar1->Canvas,
        ParentForm->StatusBar1->Panels->Items[0]->Width);

  ParentForm->ActivateDiagramMenu(true);
  Caption = TGFileName;

  if (Picture != NULL) {
    double ZoomFactor = Picture->CurrentZoom();
	ztext.sprintf(L"%d\%", (int)(100.0*ZoomFactor));
    ParentForm->ZoomComboBox->Text = ztext;
    }

  // remove the toolbar from previously active form
  ParentForm->RemoveTGEditToolBar(this);

  TGBoxes1->Checked = Boxes;
}
//---------------------------------------------------------------------------

void __fastcall TTGDiagram::FormDeactivate(TObject *Sender)
{
   FormClicked = false;
}
//---------------------------------------------------------------------------

bool TTGDiagram::InitializeDiagram(DiagramParams& Params)
{
  UnicodeString FileName = Params.FileName;
  bool ReturnValue = true;
  BackgroundColor = clWhite;
  file_loaded = false;
  diagram_made = false;
  zone_col_width = 0.0;
  Picture = NULL;
  thick = NULL;
  CustomColors.assign(tiGlobals->CustomColors.begin(),tiGlobals->CustomColors.end());
  Default.Font.FontName = "Arial";
  Default.Font.Height = 0.0;
  Default.Font.Color = clBlack;
  Default.Font.Style.italic = false;
  Default.Font.Style.bold = false;
  Default.Font.Style.greek = false;
  Default.Font.Style.subscript = false;
  Default.Font.Style.superscript = false;
  Default.Font.Style.underline = false;
  Default.Font.Style.strikeout = false;
  Default.Font.Style.charset = DEFAULT_CHARSET;

  if (!Params.Heading.IsEmpty()) {
	heading[0].Text = Params.Heading;
	heading[0].Font.Height = 0.6;
	}

  end_graphs = 0.0;
  max_ytaxa = 0.0;

  grf = new TList;
  grf->Capacity = 1000;

  Levs = new TList;
  Levs->Capacity = 1000;

  YAxes = new TList;
  YAxes->Capacity = 10;

  Zones = new TList;
  Zones->Capacity = 100;

  ZoneLabels = new TList;
  ZoneLabels->Capacity = 100;

  Groups = new TList;
  Groups->Capacity = 10;

  Dates = new TList;
  Dates->Capacity = 100;

  Dgr = new TList;
  Dgr->Capacity = 1000;

  DgrOrder.reserve(100);

  Lithology = new TList;
  Lithology->Capacity = 100;

  LithKeys = new TList;
  LithKeys->Capacity = 100;

  RandomText = new TList;
  RandomText->Capacity = 100;

  InHead = 0;

  Screen->Cursor = crHourGlass;

  UnicodeString FileExt = ExtractFileExt(FileName);
  if (FileExt.CompareIC(".tgf") == 0) {
	ReadTGF *r = new ReadTGF(FileName, this);   // read .tgf file
	if (r->ReadFile()) {
	  Picture = new MyGraphics(-20.0, 200.0, 200.0, -20.0, BackgroundColor, this);
	  TGFileName = FileName;
	  tiGlobals->OpenFileExt = TGF;
	  }
	else
	  ReturnValue = false;
	delete r;
    }
  else if (FileExt.CompareIC(".$$$") == 0) {
	Picture = new MyGraphics(-20.0, 200.0, 200.0, -20.0, BackgroundColor, this);
	LoadSSData(Params);
	}
  else if (FileExt.CompareIC(".tgx") == 0) {
	FontList = new TList;
	ipwXMLp1->ParseFile(FileName);
	DeleteList(FontList);

	file_loaded = true;
	ParentForm->StatusBar1->Panels->Items[0]->Text =
	  MinimizeName(FileName, ParentForm->StatusBar1->Canvas,
		ParentForm->StatusBar1->Panels->Items[0]->Width);

	TTGDiagram* TGDiagram = (TTGDiagram *)ParentForm->ActiveMDIChild;
	TGDiagram->Caption = MinimizeName(FileName, TGDiagram->Canvas, TGDiagram->Width);

	Picture = new MyGraphics(-20.0, 200.0, 200.0, -20.0, BackgroundColor, this);
	TGFileName = FileName;
	tiGlobals->OpenFileExt = TGX;
	}
  return ReturnValue;
}
//---------------------------------------------------------------------------

void TTGDiagram::LoadSSData(DiagramParams& Params)
{
   int RowCount = TTilSpreadSheetForm::AbsContentRowCount(Params.ProfGrid);
   int ColCount = TTilSpreadSheetForm::AbsContentColCount(Params.ProfGrid);

   if (!RowCount || !ColCount)
     return;

   TList* Vars = new TList;
   Vars->Capacity = 1000;
   vector<int> Rows;
   vector<int> Cols;
   int CodeNum = 1;

   int StartRow = Params.ProfGrid->FixedRows;
   for (int i=StartRow, j=0; i<=RowCount; i++, j++) {
	 UnicodeString VarCode = Params.ProfGrid->AbsoluteCells[1][i]->Text;
     if (!VarCode.Length())  // assign arbitrary VarCode if blank
       VarCode = "$" + IntToStr(CodeNum++) + "$";
	 if (VarCode.SubString(1,1) == "#") {
	   if (SameText(VarCode.SubString(1,6), L"#Chron") && !ContainsText(VarCode, L"Old") && !ContainsText(VarCode, L"Young"))
		 VarCode.Delete(1,1);
	   else if (SameText(VarCode.SubString(1,6), L"#Depth"))
		 VarCode.Delete(1,1);
	   else if (SameText(VarCode.SubString(1,6), L"#Thick"))
		 VarCode = L"Thick";
	   else if (SameText(VarCode.SubString(1,11), L"#Anal.Thick"))
		 VarCode = L"Thick";
	   else if (SameText(VarCode.SubString(1,6), L"#Error"))
		 VarCode = L"Error";
	   else
		 continue;
	   }
	 TGVARS *Var = new TGVARS();
	 Var->code = VarCode;
	 Var->sum = Params.ProfGrid->AbsoluteCells[7][i]->Text;
	 Var->name = Params.VarNames[j].first;

	 if (SameText(VarCode.SubString(1,5), L"Chron") || SameText(VarCode.SubString(1,5), L"Depth") || SameText(VarCode, L"Thick"))
	   Var->status = NOGRAPH;
	 else if (SameText(VarCode, L"Error"))
	   Var->status = ERRORBAR;
	 else if (!Params.VarNames[j].second)
	   Var->status = SKIP;
	 else
	   Var->status = NORMAL;
	 Vars->Add(Var);
	 Rows.push_back(i);
	 }

   int StartCol = Params.ProfGrid->FixedCols + Params.ProfGrid->HiddenColCount;

   double num;
   Variant Value;
   for (int j=StartCol; j<=ColCount; j++) {
	 Value = Params.ProfGrid->AbsoluteCells[j][1]->Value;
     if (Value.Type() == varDouble)
       num = (double)Value;
     else {
       num = 0;
       // error message
       }
     LEVELS *Lev = new LEVELS();
     Lev->num = num;
	 Lev->name = Params.ProfGrid->AbsoluteCells[j][2]->Text;
     Levs->Add(Lev);
     Cols.push_back(j);
     }

   GRAPHS *graf;
   XAXIS *xax;
   DATA *dat;
   TColor RareColor = tiGlobals->RareColor;
   for (unsigned int i=0; i<Rows.size(); i++) {
     graf = new GRAPHS;
     xax = new XAXIS;
     dat = new DATA [Cols.size()];
     for (unsigned int j=0; j<Cols.size(); j++) {
       dat[j].rare = false;
	   Value = Params.ProfGrid->AbsoluteCells[Cols[j]][Rows[i]]->Value;
       if (Value.IsNull() || Value.IsEmpty())
         dat[j].null = true;
       else if (Value.Type() == varDouble) {
         dat[j].x = (double)Value;
         dat[j].null = false;
		 if (Params.ProfGrid->AbsoluteCells[Cols[j]][Rows[i]]->Font->Color == RareColor)
           dat[j].rare = true;
         }
       else
		 dat[j].null = true;
       }
	 TGVARS *Var = (TGVARS*)Vars->Items[i];
	 grf->Add(new GRAPH (Cols.size(), graf, xax, dat, Var));
     }

   // instantiate Axis 1
   NEWYAXIS *Axis = new NEWYAXIS(this, Cols.size());
   Axis->AutoAxisMinMax();  // here is the problem
   Axis->Calc_yfac();
   Axis->AxisLabel = "Depth";
   YAxes->Add(Axis);

   for (unsigned int i=0; i<Rows.size(); i++) {
     TGVARS *Var = (TGVARS*)Vars->Items[i];
	 UnicodeString code = Var->code;
	 if (SameText(code.SubString(1,5), L"Chron") || SameText(code.SubString(1,5), L"Depth")) {
	   bool ascending = true;
       unsigned int j = 1;
       while (ascending && j < Cols.size()) {
         double x1 = ((GRAPH*)grf->Items[i])->data[j-1].x;
         double x2 = ((GRAPH*)grf->Items[i])->data[j].x;
         if (x2 < x1) ascending = false;
         j++;
         }
       if (ascending) {
         Axis = new NEWYAXIS(Var->code, Var->name, this);
         Axis->AutoAxisMinMax();
         if (Axis->AxisMax > Axis->AxisMin) {
           Axis->Calc_yfac();
           YAxes->Add(Axis);
           }
         else
           delete Axis;
         }
       else {
         UnicodeString msg = Var->code + " not in ascending order.\nSecondary scale will not be created.";
         MessageDlg(msg, mtWarning, TMsgDlgButtons() << mbOK, 0);
         }
       }
     }

   // clean up
   if (Vars) {
     for (int i=0; i<Vars->Count; i++) {
       TGVARS* Var = (TGVARS*)Vars->Items[i];
       delete Var;
       Vars->Items[i] = 0;
       }
     Vars->Clear();
     delete Vars;
     }
}
//---------------------------------------------------------------------------

void __fastcall TTGDiagram::FormPaint(TObject *Sender)
{
  if (Picture != NULL) {
    Color = TColor(Picture->BackgroundColor);
    Picture->OutputGraphicObjects(DISPLAY, this);
    }
}
//---------------------------------------------------------------------------

void __fastcall TTGDiagram::FormResize(TObject *Sender)
{
    if (Picture != NULL)
      Picture->OutputGraphicObjects(DISPLAY, this);
}
//---------------------------------------------------------------------------

void __fastcall TTGDiagram::FormClose(TObject *Sender, TCloseAction &Action)
{
   int i;

   if (Modified) {
     if (MessageDlg("The diagram has been changed.\nDo you want to save it?",
         mtWarning, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes)
       Save();
     }

   if (thick != NULL) delete[] thick;

   DeleteList(Levs);

   for (i=0; i<grf->Count; i++) {
     GRAPH* g = (GRAPH*)grf->Items[i];
     delete g;
     grf->Items[i] = 0;
     }
   grf->Clear();
   delete grf;

   for (i=0; i<YAxes->Count; i++) {
     NEWYAXIS* yaxis = (NEWYAXIS*)YAxes->Items[i];
     delete yaxis;
     YAxes->Items[i] = 0;
     }
   YAxes->Clear();
   delete YAxes;

   DeleteList(Zones);
   DeleteList(ZoneLabels);
   DeleteList(Groups);
   DeleteList(Dates);
   DeleteList(Dgr);
   DgrOrder.clear();
   for (i=0; i<Lithology->Count; i++) {
     LITHUNIT* Lith = (LITHUNIT*)Lithology->Items[i];
     DeleteList(Lith->Components);
     }
   DeleteList(Lithology);
   DeleteList(LithKeys);
   DeleteList(RandomText);

   if (Picture != NULL) {
     delete Picture;
     Picture = NULL;
     }

   // end of former Diagram destructor

   Release();
   Action = caFree;

   ParentForm->StatusBar1->Panels->Items[0]->Text = "";
   ParentForm->StatusBar1->Panels->Items[1]->Text = "";
   ParentForm->StatusBar1->Panels->Items[2]->Text = "";

// TODO: check if last TGDiagram rather than simply last window
//       but need to separate out global vs. diagram commands
   if (ParentForm->MDIChildCount == 1) {
	 ParentForm->ActivateDiagramMenu(false);
	 ParentForm->ZoomComboBox->Text = "Fit";
	 vector<TToolBar*> ToolBars;
	 ToolBars.push_back(ParentForm->ToolBarFile);
	 ToolBars.push_back(ParentForm->ToolBarHelp);
	 ToolBars.push_back(ParentForm->ToolBarNeotoma);
	 ParentForm->SetToolBars(ToolBars);
	 }

   // tiGlobals->CustomColors = CustomColors;
   tiGlobals->CustomColors.clear();
   tiGlobals->CustomColors.assign(CustomColors.begin(),CustomColors.end());
}
//---------------------------------------------------------------------------

void TTGDiagram::Save(void)
{
   UnicodeString PathName;
   UnicodeString FileName = ExtractFileName(TGFileName);
   UnicodeString FileExt = ExtractFileExt(TGFileName);
   UnicodeString FilePath = ExtractFilePath(TGFileName);

   // if file is already .tgx file, then save without asking
   bool SaveFile = true;
   if (SameText(FileExt, L".tgx"))
	 PathName = TGFileName;
   else {
	 int pos;
	 if ((pos = FileName.Pos(".")) > 0)
	   FileName.SetLength(pos-1);
	 SaveDialog1->FileName = FileName + ".tgx";
	 SaveDialog1->Title = "Save As";

	 SaveDialog1->Filter = "Tilia diagram (*.tgx)|*.tgx";
	 SaveDialog1->DefaultExt = "tgx";
	 SaveDialog1->FilterIndex = 1;
	 SaveDialog1->InitialDir = FilePath;

	 if (SaveDialog1->Execute())
	   PathName = SaveDialog1->FileName;
	 else
	   SaveFile = false;
	 }

   if (SaveFile) {
	 WriteTGX *w = new WriteTGX(PathName, this);
	 w->WriteFile();
	 delete w;

	 ParentForm->StatusBar1->Panels->Items[0]->Text =
	   MinimizeName(PathName, ParentForm->StatusBar1->Canvas,
	   ParentForm->StatusBar1->Panels->Items[0]->Width);

	 Caption = PathName;
	 TGFileName = PathName;
	 Modified = false;
	 }
}
//---------------------------------------------------------------------------

void TTGDiagram::SaveAs(void)
{
   UnicodeString FileName = ExtractFileName(TGFileName);
   UnicodeString FilePath = ExtractFilePath(TGFileName);
   int pos;
   if ((pos = FileName.Pos(".")) > 0)
	 FileName.SetLength(pos-1);
   SaveDialog1->FileName = FileName + ".tgx";
   SaveDialog1->Title = "Save As";

   SaveDialog1->Filter = "Tilia diagram (*.tgx)|*.tgx";
   SaveDialog1->DefaultExt = "tgx";
   SaveDialog1->FilterIndex = 1;
   SaveDialog1->InitialDir = FilePath;

   if (SaveDialog1->Execute()) {
	  UnicodeString FileExt = ExtractFileExt(SaveDialog1->FileName);
	  if (FileExt.CompareIC(".tgx") == 0) {
		WriteTGX *w = new WriteTGX(SaveDialog1->FileName, this);
		w->WriteFile();
		delete w;
		Caption = SaveDialog1->FileName;
		TGFileName = SaveDialog1->FileName;
		Modified = false;
		}
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTGDiagram::FormClick(TObject *Sender)
{
  //TODO: PROBLEM HERE.
  if (ParentForm->ZoomComboBox->Focused()) {
     //ParentForm->ActiveControl = ParentForm->ToolBar1;
    ParentForm->SetZoom();
    //Beep();
    }

  if (AddText) return;
  FormClicked = true;

  if (MouseDown && !Dragging) {
    if (MouseButton == mbLeft) {
      Picture->EditSegment(XMouse, YMouse, ActiveSegment);
      ParentForm->HideButton1->Enabled = true;
      if (ActiveSegment.SubString(1,5) == "Graph") {
        int left = ParentForm->Left + Left + 24;
        int top = ParentForm->Top + Top + 100;
        int right = left + ToolBar1->Width;
        int bottom = top + ToolBar1->Height;
        ToolBar1->ManualFloat(TRect(left, top, right, bottom));
        }
      else if (ToolBar1->Visible)
        ToolBar1->Hide();
      }
    }
}
//---------------------------------------------------------------------------

void __fastcall TTGDiagram::FormMouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
    MouseDown = true;
    MouseButton = Button;
    XMouse = X;
    YMouse = Y;

    if (AddText) return;

    GraphRect = Picture->EditSegmentRect;
    if (Shift.Contains(ssCtrl) && Button == mbLeft &&
        ActiveSegment.SubString(1,5) == "Graph") {
          if (InsideGraphRect(X, Y)) {
            Dragging = true;
            dx = X - GraphRect.Left;
            XGraphLeft = 1000000;
            XGraphRight = -1000000;
            // find left and right margins of all graphs
			for (unsigned int i=0; i<Picture->sl.size(); i++) {
			  SEGLIMITS& s = Picture->sl[i];
			  if (s.name.SubString(1,5) == "Graph") {
				if (s.rect.Left < XGraphLeft)
				  XGraphLeft = s.rect.Left;
				if (s.rect.Right > XGraphRight)
                  XGraphRight = s.rect.Right;
                }
              }
            }
        }
}

//---------------------------------------------------------------------------

void __fastcall TTGDiagram::FormMouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
   double x, y;
   UnicodeString coord;

   x = Picture->GetXoffset() + (double)X/Picture->GetFac();
   y = Picture->GetYoffset() +
       (double)(ClientHeight - Y)/Picture->GetFac();
   coord = FormatFloat("0.0#", x) + ", " + FormatFloat("0.0#", y);
   ParentForm->StatusBar1->Panels->Items[2]->Text = coord;

   if (Dragging) {
     // erase current selection rectangle
     Picture->Canvas()->DrawFocusRect(GraphRect);
     int d = GraphRect.Right - GraphRect.Left;
     GraphRect.Left = X - dx;
     GraphRect.Right = X + d - dx;
     if (GraphRect.Left < XGraphLeft) {
        GraphRect.Left = XGraphLeft;
        GraphRect.Right = XGraphLeft + d;
        }
     if (GraphRect.Left > XGraphRight) {
        GraphRect.Left = XGraphRight;
        GraphRect.Right = XGraphRight + d;
        }
     // draw new selection rectangle
     Picture->Canvas()->DrawFocusRect(GraphRect);
     }
}
//---------------------------------------------------------------------------

void __fastcall TTGDiagram::FormMouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
   int i, i1, i2;
   int CurIndex, NewIndex;
   SEGLIMITS* s;
   UnicodeString VarCode;
   GRAPH *g;

   if (AddText) {
      Screen->Cursor = crDefault;
      double xtxt = Picture->GetXoffset() + (double)X/Picture->GetFac();
      double ytxt = Picture->GetYoffset() +
                   (double)(ClientHeight - Y)/Picture->GetFac();

      TEXTLINE *Text = new TEXTLINE();
      Text->x = xtxt;
      Text->y = ytxt;
      Text->angle = 0.0;
      Text->Text = "";
      Text->Font = Default.Font;
      Text->Font.Height = 0.5;

      Screen->Cursor = crHourGlass;
      NewTextForm = new TNewTextForm(this);
      NewTextForm->Text = Text;

      if (NewTextForm->ShowModal() == mrOk && Text->Text.Length() > 0) {
        RandomText->Add(Text);
        Modified = true;
        make_diagram();
        Picture->OutputGraphicObjects(DISPLAY, this);
        }
      else
        delete Text;

      delete NewTextForm;

      AddText = false;
      return;
      }

   MouseDown = false;
   if (Dragging) {
     Dragging = false;
     Picture->Canvas()->DrawFocusRect(GraphRect); // remove Focus Rect

     VarCode = ActiveSegment.SubString(8, ActiveSegment.Length()-7);

     // find var
     //TODO: put this in separate function
     i1 = i2 = 0;
     for (i=0; i<grf->Count; i++) {
       g = (GRAPH*)grf->Items[i];
       if (VarCode == g->code) {
         CurIndex = i;
         if (g->status == BASE) {
           i1 = CurIndex+1;
           i2 = CurIndex;
           g = (GRAPH*)grf->Items[i2+1];
           while (i2 < grf->Count &&
             (g->status == STACKED || g->status == OVERLAY)) {
               i2++;
               if (i2+1 < grf->Count)
                 g = (GRAPH*)grf->Items[i2+1];
               else
                 break;
               }
           }
         break; }
       }

     // find new position for graph
     bool End = false;
     if (GraphRect.Left == XGraphRight) {
       NewIndex = grf->Count - 1;
       End = true;
       }
     else {
       // default first graph
       for (int i=0; i<grf->Count; i++) {
         g = (GRAPH*)grf->Items[i];
         UnicodeString TempStr = g->code.SubString(1, 5);
         if (TempStr == "Chron")
           continue;
         if (TempStr == "Depth")
           continue;
         if (TempStr == "Thick")
           continue;
         if (TempStr == "Error")
           continue;
         NewIndex = i;
         break;
         }

	   for (unsigned int i=0; i<Picture->sl.size(); i++) {
		 //s = (SEGLIMITS*)Picture->sl->Items[i];
		 SEGLIMITS& s = Picture->sl[i];
		 if (s.name.SubString(1,5) == "Graph") {
		   if (GraphRect.Left > s.rect.Left && GraphRect.Left <= s.rect.Right) {
			 VarCode = s.name.SubString(8, s.name.Length()-7);
             for (int k=0; k<grf->Count; k++) {
               g = (GRAPH*)grf->Items[k];
               if (VarCode == g->code) {
                 NewIndex = k+1;
                 break; }
               }
             if (s.rect.Left > GraphRect.Right) break;
             }
           }
         }
       }

     if (NewIndex < CurIndex) {
       grf->Move(CurIndex, NewIndex);
       // move stacked and overlaid graphs
       if (i1 > 0) {
         NewIndex++;
         for (i=i1; i<=i2; i++)
           grf->Move(i, NewIndex++);
         }
       }
     else if (NewIndex > CurIndex) {
       if (!End) NewIndex--;
       g = (GRAPH*)grf->Items[NewIndex];
       if (g->status == BASE) {
         NewIndex++;
         g = (GRAPH*)grf->Items[NewIndex+1];
         while (NewIndex+1 < grf->Count &&
           (g->status == STACKED || g->status == OVERLAY)) {
             NewIndex++;
             g = (GRAPH*)grf->Items[NewIndex+1];
             }
         }
       grf->Move(CurIndex, NewIndex);
       // move stacked and overlaid graphs
       if (i1 > 0) {
         for (i=i1; i<=i2; i++)
           grf->Move(CurIndex, NewIndex);
         }
       }
     make_diagram();
     Picture->OutputGraphicObjects(DISPLAY, this);
     }
   else if (MouseButton == mbRight) {     // normal right-click editing
     if (ActiveSegment.SubString(1,5) == "Graph")
       EditGraph();
     else if (ActiveSegment.SubString(1,5) == "Zones") {
       Screen->Cursor = crHourGlass;
       ZoneForm = new TZoneForm(this);
       ZoneForm->Diag = this;
       if (ZoneForm->ShowModal() == mrOk) {
         make_diagram();
         Picture->OutputGraphicObjects(DISPLAY, this);
         }
       delete ZoneForm;
       Picture->ResetEditSegment();
       ActiveSegment = "";
       }
     else if (ActiveSegment.SubString(1,10) == "ZoneLabels") {
       Screen->Cursor = crHourGlass;
       ZoneForm = new TZoneForm(this);
       ZoneForm->Diag = this;
       ZoneForm->OpeningTabSheet = LABELS_TABSHEET;
       if (ZoneForm->ShowModal() == mrOk) {
         make_diagram();
         Picture->OutputGraphicObjects(DISPLAY, this);
         }
       delete ZoneForm;
       Picture->ResetEditSegment();
       ActiveSegment = "";
       }
     else if (ActiveSegment.SubString(1,6) == "Y-Axis") {
       if (InsideGraphRect(X, Y)) {
         int AxisNo = StrToInt(ActiveSegment.SubString(8, ActiveSegment.Length()));
         YaxisOptions(AxisNo);
         Picture->ResetEditSegment();
         ActiveSegment = "";
         }
       }
     else if (ActiveSegment.SubString(1,7) == "Heading") {
       Text(-1);
       Picture->ResetEditSegment();
       ActiveSegment = "";
       }
     else if (ActiveSegment.SubString(1,6) == "Footer") {
       Text(-2);
       Picture->ResetEditSegment();
       ActiveSegment = "";
       }
     else if (ActiveSegment.SubString(1,4) == "Text") {
       int item = StrToInt(ActiveSegment.SubString(6, ActiveSegment.Length()));
       Text(item);
       Picture->ResetEditSegment();
       ActiveSegment = "";
       }
     else if (ActiveSegment.SubString(1,5) == "Group") {
       int GroupNo = StrToInt(ActiveSegment.SubString(6, ActiveSegment.Length()));
       Screen->Cursor = crHourGlass;
       GroupForm = new TGroupForm(this);
       GroupForm->Diag = this;
       GroupForm->InitialRow = GroupNo-1;
       if (GroupForm->ShowModal() == mrOk) {
         make_diagram();
         Picture->OutputGraphicObjects(DISPLAY, this);
         }
       delete GroupForm;
       Picture->ResetEditSegment();
       ActiveSegment = "";
       }
     else if (ActiveSegment.SubString(1,5) == "Dates") {
       Screen->Cursor = crHourGlass;
       DatesForm = new TDatesForm(this);
       DatesForm->Diag = this;
       if (DatesForm->ShowModal() == mrOk) {
         make_diagram();
         Picture->OutputGraphicObjects(DISPLAY, this);
         }
       delete DatesForm;
       Picture->ResetEditSegment();
       ActiveSegment = "";
       }
     else if (ActiveSegment.SubString(1,9) == "Lithology" ||
              ActiveSegment.SubString(1,9) == "LithBoxes") {
       Screen->Cursor = crHourGlass;
       LithForm = new TLithForm(this);
	   if (ActiveSegment.SubString(1,9) == "LithBoxes")
         LithForm->InitialTabSheet = 2;
       if (LithForm->ShowModal() == mrOk) {
         make_diagram();
         Picture->OutputGraphicObjects(DISPLAY, this);
         }
       delete LithForm;
       Picture->ResetEditSegment();
       ActiveSegment = "";
       }
     else if (ActiveSegment.SubString(1,10) == "Dendrogram") {
       Screen->Cursor = crHourGlass;
       DendrogramForm = new TDendrogramForm(this);
	   if (DendrogramForm->ShowModal() == mrOk) {
         make_diagram();
         Picture->OutputGraphicObjects(DISPLAY, this);
         }
       delete DendrogramForm;
       Picture->ResetEditSegment();
       ActiveSegment = "";
       }
     }
}
//---------------------------------------------------------------------------

// Xaxes
void __fastcall TTGDiagram::ToolButton1Click(TObject *Sender)
{
   XaxesForm = new TXaxesForm(this);
   XaxesForm->Diag = this;

   UnicodeString Code = ActiveSegment.SubString(8, ActiveSegment.Length()-7);
   XaxesForm->SetInitialVar(Code);
   if (XaxesForm->ShowModal() == mrOk) {
     Picture->ResetEditSegment();
     ActiveSegment = "";
     make_diagram();
     Picture->OutputGraphicObjects(DISPLAY, this);
     }
   else {
     Picture->ResetEditSegment();
     ActiveSegment = "";
     }
   ToolBar1->Hide();
   ParentForm->HideButton1->Enabled = false;
   delete XaxesForm;
}
//---------------------------------------------------------------------------

void __fastcall TTGDiagram::ToolButton2Click(TObject *Sender)
{
   EditGraph();
}
//---------------------------------------------------------------------------

void TTGDiagram::EditGraph(void)
{
   StyleForm = new TStyleForm(this);
   StyleForm->Diag = this;

   UnicodeString Code = ActiveSegment.SubString(8, ActiveSegment.Length()-7);
   StyleForm->SetInitialVar(Code);
   if (StyleForm->ShowModal() == mrOk) {
     Picture->ResetEditSegment();
     ActiveSegment = "";
     make_diagram();
     Picture->OutputGraphicObjects(DISPLAY, this);
     }
   else {
     Picture->ResetEditSegment();
     ActiveSegment = "";
     }
   ToolBar1->Hide();
   ParentForm->HideButton1->Enabled = false;
   delete StyleForm;
}

//---------------------------------------------------------------------------

// left arrow
void __fastcall TTGDiagram::ToolButton3Click(TObject *Sender)
{
   MoveGraphLeft();
}
//---------------------------------------------------------------------------

// right arrow
void __fastcall TTGDiagram::ToolButton4Click(TObject *Sender)
{
   MoveGraphRight();
}
//---------------------------------------------------------------------------

void __fastcall TTGDiagram::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
   if (ActiveSegment.SubString(1,6) != "Graph:") return;
   if (Key == VK_LEFT)
     MoveGraphLeft();
   else if (Key == VK_RIGHT)
     MoveGraphRight();
}
//---------------------------------------------------------------------------

void TTGDiagram::MoveGraphLeft(void)
{
   int i, FirstGraph;
   int i1, i2;
   int CurIndex, NewIndex;
   GRAPH *g;

   Screen->Cursor = crHourGlass;
   UnicodeString VarCode = ActiveSegment.SubString(8, ActiveSegment.Length()-7);

   // find first graph
   for (i=0; i<grf->Count; i++) {
     g = (GRAPH*)grf->Items[i];
     if (g->status == NORMAL || g->status == BASE) {
       FirstGraph = i;
       break;
       }
     }

   // find var
   i1 = i2 = 0;
   for (i=0; i<grf->Count; i++) {
     g = (GRAPH*)grf->Items[i];
     if (VarCode == g->code) {
       CurIndex = i;
       if (g->status == BASE) {
         i1 = CurIndex+1;
         i2 = CurIndex;
         g = (GRAPH*)grf->Items[i2+1];
         while (i2 < grf->Count &&
           (g->status == STACKED || g->status == OVERLAY)) {
             i2++;
             g = (GRAPH*)grf->Items[i2+1];
             }
         }
       break; }
     }

   // move var
   if (CurIndex > FirstGraph) {
     for (i=CurIndex-1; i>=0; i--) {
       g = (GRAPH*)grf->Items[i];
       if (g->status == NORMAL || g->status == BASE) {
         NewIndex = i;
         break;
         }
       }
     grf->Move(CurIndex, NewIndex);
     // move stacked and overlaid graphs
     if (i1 > 0) {
       NewIndex++;
       for (i=i1; i<=i2; i++)
         grf->Move(i, NewIndex++);
       }
     make_diagram();
     Picture->OutputGraphicObjects(DISPLAY, this);
     }
   Screen->Cursor = crDefault;
}
//---------------------------------------------------------------------------

void TTGDiagram::MoveGraphRight(void)
{
   int i;
   int LastGraph;
   int i1, i2;
   int CurIndex, NewIndex;
   GRAPH *g;

   Screen->Cursor = crHourGlass;
   UnicodeString VarCode = ActiveSegment.SubString(8, ActiveSegment.Length()-7);

   // find last graph
   for (i=grf->Count-1; i>=0; i--) {
     g = (GRAPH*)grf->Items[i];
     if (g->status == NORMAL || g->status == BASE) {
       LastGraph = i;
       break;
       }
     }

   // find var
   i1 = i2 = 0;
   for (i=0; i<grf->Count; i++) {
     g = (GRAPH*)grf->Items[i];
     if (VarCode == g->code) {
       CurIndex = i;
       if (g->status == BASE) {
         i1 = CurIndex+1;
         i2 = CurIndex;
         g = (GRAPH*)grf->Items[i2+1];
         while (i2 < grf->Count &&
           (g->status == STACKED || g->status == OVERLAY)) {
             i2++;
             if (i2+1 < grf->Count)
               g = (GRAPH*)grf->Items[i2+1];
             else
               break;
             }
         }
       break; }
     }

   // move var
   if (CurIndex < LastGraph) {
     for (i=CurIndex+1; i<grf->Count; i++) {
       g = (GRAPH*)grf->Items[i];
       if (g->status == NORMAL || g->status == BASE) {
         NewIndex = i;
         break;
         }
       }
     if (g->status == BASE) {
       NewIndex++;
       g = (GRAPH*)grf->Items[NewIndex+1];
       while (NewIndex+1 < grf->Count &&
         (g->status == STACKED || g->status == OVERLAY)) {
           NewIndex++;
           g = (GRAPH*)grf->Items[NewIndex+1];
           }
       }

     grf->Move(CurIndex, NewIndex);
     // move stacked and overlaid graphs
     if (i1 > 0) {
       for (i=i1; i<=i2; i++)
         grf->Move(CurIndex, NewIndex);
       }

     make_diagram();
     Picture->OutputGraphicObjects(DISPLAY, this);
     }

   Screen->Cursor = crDefault;
}
//---------------------------------------------------------------------------

// skip graph
void __fastcall TTGDiagram::ToolButton5Click(TObject *Sender)
{
  int i;

  UnicodeString VarCode = ActiveSegment.SubString(8, ActiveSegment.Length()-7);
  for (i=0; i<grf->Count; i++) {
   GRAPH *g = (GRAPH*)grf->Items[i];
   if (VarCode == g->code) {
     ToolBar1->Hide();
     Picture->ResetEditSegment();
     ActiveSegment = "";
     ParentForm->HideButton1->Enabled = false;
     g->status = SKIP;
     break; }
    }

  for (int k=i+1; k<grf->Count; k++) {
    GRAPH *g = (GRAPH*)grf->Items[k];
    short status = g->status;
    if (status == OVERLAY || status == STACKED)
      g->status = SKIP;
    else
      break;
	}
  make_diagram();
  Picture->OutputGraphicObjects(DISPLAY, this);
}
//---------------------------------------------------------------------------

void TTGDiagram::WriteMetafile(UnicodeString FileName)
{
  Picture->MyMetafile = new TMetafile;
  Picture->MetafileCanvas = new TMetafileCanvas(Picture->MyMetafile, 0);
  Picture->DirectToMetafile = true;
  Picture->OutputGraphicObjects(METAFILE, (TTGDiagram *)ParentForm->ActiveMDIChild);

  TRect rect;  // force size to total metafile
  rect.Left = 0;
  rect.Right = Screen->Width;
  rect.Top = 0;
  rect.Bottom = Screen->Height;
  Picture->Canvas()->FrameRect(rect);

  delete Picture->MetafileCanvas;
  Picture->MyMetafile->SaveToFile(FileName);
  delete Picture->MyMetafile;
  Picture->DirectToMetafile = false;
}
//---------------------------------------------------------------------------

void __fastcall TTGDiagram::ipwXMLp1StartElement(TObject *Sender,
	  TipwXMLpStartElementEventParams *e)
{
  UnicodeString Element = e->Element.w_str();
  tgx.XText.SetLength(0);

  if (Element == "BackgroundColor")
	tgx.BackgroundColor = true;
  else if (Element == "BoxStyle")
	tgx.BoxStyle = true;
  else if (Element == "Font") {
	tgx.Font = true;
	InFont = new MYFONT();
	}
  else if (tgx.Font)
	InFont->ToggleSAXElement(Element, tgx, true);
  else if (Element == "DefaultSettings")
	tgx.DefaultSettings = true;
  else if (tgx.DefaultSettings) {
	if (Element == "LineWidth")
	  tgx.LineWidth = true;
	else if (Element == "DefaultFont")
	  tgx.DefaultFont = true;
	else if (Element == "GraphStyle")
	  tgx.GraphStyle = true;
	else if (tgx.GraphStyle)
	  Default.Graph.ToggleSAXElement(Element, tgx, true);
	else if (Element == "XaxisStyle")
	  tgx.XaxisStyle = true;
	else if (tgx.XaxisStyle)
	  Default.Xaxis.ToggleSAXElement(Element, tgx, true);
	else if (Element == "ZoneAttr")
	  tgx.ZoneAttr = true;
	else if (tgx.ZoneAttr)
	  Default.ZoneAttr.ToggleSAXElement(Element, tgx, true);
	else if (Element == "GroupAttr")
	  tgx.GroupAttr = true;
	else if (tgx.GroupAttr)
	  Default.GroupAttr.ToggleSAXElement(Element, tgx, true);
	}
  else if (Element == "Level") {
	tgx.Level = true;
	InLev = new LEVELS();
	}
  else if (tgx.Level) {
	if (Element == "Num")
	  tgx.Num = true;
	else if (Element == "Name")
	  tgx.Name = true;
	}
  else if (Element == "Graphs")
	tgx.Graphs = true;
  else if (tgx.Graphs) {
	if (Element == "Styles") {
	  tgx.Styles = true;
	  GraphStyles = new TList;
	  }
	else if (tgx.Styles) {
	  if (Element == "GraphStyle") {
		tgx.GraphStyle = true;
		InGraph = new GRAPHS();
		}
	  else if (tgx.GraphStyle)
		InGraph->ToggleSAXElement(Element, tgx, true);
	  }
	else if (Element == "Xaxes") {
	  tgx.Xaxes = true;
	  XaxisStyles = new TList;
	  }
	else if (tgx.Xaxes) {
	  if (Element == "XaxisStyle") {
		tgx.XaxisStyle = true;
		InXax = new XAXIS();
		}
	  else if (tgx.XaxisStyle)
		InXax->ToggleSAXElement(Element, tgx, true);
	  }
	else if (Element == "Graph") {
	  tgx.Graph = true;
	  int gs = ipwXMLp1->Attr("GS").ToInt();
	  if (gs > 0)                                // TODO: check on this
		InGraph = new GRAPHS((GRAPHS*)GraphStyles->Items[gs-1]);
	  else
		InGraph = new GRAPHS();    // sample ages/depths
	  int xs = ipwXMLp1->Attr("XS").ToInt();
	  if (xs > 0)
		InXax = new XAXIS((XAXIS*)XaxisStyles->Items[xs-1]);
	  else
		InXax = new XAXIS();       // sample ages/depths
	  InGrf = new GRAPH(InGraph, InXax);
	  }
	else if (tgx.Graph) {
	  if (tgx.Data) {
		if (Element == "Value") {
		  //tgx.Value = true;
		  AttrValue1 = ipwXMLp1->Attr("Null");
		  AttrValue2 = ipwXMLp1->Attr("Rare");
		  }
		}
	  //else
	  InGrf->ToggleSAXElement(Element, tgx, true);
	  }
	}
  else if (Element == "Yaxis") {
	tgx.Yaxis = true;
	InYaxis = new NEWYAXIS(this);
	}
  else if (tgx.Yaxis)
	InYaxis->ToggleSAXElement(Element, tgx, true);
  else if (Element == "Frame")
	tgx.Frame = true;
  else if (tgx.Frame)
	Frame.ToggleSAXElement(Element, tgx, true);
  else if (Element == "RareSpecies")
	tgx.RareSpecies = true;
  else if (tgx.RareSpecies)
	Rare.ToggleSAXElement(Element, tgx, true);
  else if (Element == "Header")
	tgx.Header = true;
  else if (tgx.Header)
	heading[InHead].ToggleSAXElement(Element, tgx, true);
  else if (Element == "Footer")
	tgx.Footer = true;
  else if (tgx.Footer)
	footer.ToggleSAXElement(Element, tgx, true);
  else if (Element == "RandomText") {
	tgx.RandomText = true;
	InRandomText = new TEXTLINE();
	}
  else if (tgx.RandomText) 
	InRandomText->ToggleSAXElement(Element, tgx, true);	   
  else if (Element == "Group") {
	tgx.Group = true;
	InGroup = new GROUPS();
	}
  else if (tgx.Group)
	InGroup->ToggleSAXElement(Element, tgx, true);
  else if (Element == "Zone") {
	tgx.Zone = true;
	InZone = new ZONE();
	}
  else if (tgx.Zone)
	InZone->ToggleSAXElement(Element, tgx, true);
  else if (Element == "ZoneLabelAttr")
	tgx.ZoneLabelAttr = true;
  else if (tgx.ZoneLabelAttr)
	zopt.ToggleSAXElement(Element, tgx, true);
  else if (Element == "ZoneLabel") {
	tgx.ZoneLabel = true;
	InZoneLabel = new ZONELABELS();
	}
  else if (tgx.ZoneLabel)
	InZoneLabel->ToggleSAXElement(Element, tgx, true);
  else if (Element == "DateAttr")
	tgx.DateAttr = true;
  else if (tgx.DateAttr)
	dopt.ToggleSAXElement(Element, tgx, true);
  else if (Element == "Date") {
	tgx.Date = true;
	InDate = new DATES();
	}
  else if (tgx.Date)
	InDate->ToggleSAXElement(Element, tgx, true);
  else if (Element == "DendAttr")
	tgx.DendAttr = true;
  else if (tgx.DendAttr)
	dgo.ToggleSAXElement(Element, tgx, true);
  else if (Element == "Dendrogram")
	tgx.Dendrogram = true;
  else if (tgx.Dendrogram) {
	if (Element == "Cluster") {
	  tgx.Cluster = true;
	  InDgr = new DENDROGRAM();
	  }
	else if (tgx.Cluster)
	  InDgr->ToggleSAXElement(Element, tgx, true);
	}
  else if (Element == "DendrogramOrder")
	tgx.DendrogramOrder = true;
  else if (tgx.DendrogramOrder && Element == "DO")
	tgx.DO = true;
  else if (Element == "LithAttr")
	tgx.LithAttr = true;
  else if (tgx.LithAttr)
	lopt.ToggleSAXElement(Element, tgx, true);
  else if (Element == "LithUnit") {
	tgx.LithUnit = true;
	InLith = new LITHUNIT((TColor)lopt.DefaultColor);
	}
  else if (tgx.LithUnit) {
	if (Element == "Component") {
	  tgx.Component = true;
	  InLithComponent = new LITHCOMPONENT;
	  InLith->Components->Add(InLithComponent);
	  }
	else if (tgx.Component)
	  InLithComponent->ToggleSAXElement(Element, tgx, true);
	else
	  InLith->ToggleSAXElement(Element, tgx, true);
	}

  else if (Element == "LithKey") {
	tgx.LithKey = true;
	InLithKey = new LITHKEY();
	}
  else if (tgx.LithKey)
	InLithKey->ToggleSAXElement(Element, tgx, true);
}
//---------------------------------------------------------------------------

void __fastcall TTGDiagram::ipwXMLp1Characters(TObject *Sender,
	  TipwXMLpCharactersEventParams *e)
{
  UnicodeString ustr = e->Text.w_str();
  tgx.XText += ustr;
}
//---------------------------------------------------------------------------

void __fastcall TTGDiagram::ipwXMLp1EndElement(TObject *Sender,
	  TipwXMLpEndElementEventParams *e)
{
  UnicodeString Element = e->Element.w_str();

  if (Element == "BackgroundColor") {
	tgx.BackgroundColor = false;
	UnicodeString Hex = "0x" + tgx.XText;
	BackgroundColor = (TColor)Hex.ToInt();
	}
  else if (Element == "BoxStyle") {
	tgx.BoxStyle = false;
	Boxes = (bool)tgx.XText.ToInt();
	}
  else if (tgx.Font) {
	if (Element == "Font") {
	  FontList->Add(InFont);
	  tgx.Font = false;
	  }
	else {
	  InFont->EvaluateXML(tgx.XText, tgx);
	  InFont->ToggleSAXElement(Element, tgx, false);
	  }
	}
  else if (tgx.DefaultSettings) {
	if (Element == "DefaultSettings")
	  tgx.DefaultSettings = false;
	else {
	  Default.EvaluateXML(tgx.XText, tgx, FontList);
	  if (Element == "LineWidth")
		tgx.LineWidth = false;
	  else if (Element == "DefaultFont")
		tgx.DefaultFont = false;
	  else if (Element == "GraphStyle")
		tgx.GraphStyle = false;
	  else if (tgx.GraphStyle)
		Default.Graph.ToggleSAXElement(Element, tgx, false);
	  else if (Element == "XaxisStyle")
		tgx.XaxisStyle = false;
	  else if (tgx.XaxisStyle)
		Default.Xaxis.ToggleSAXElement(Element, tgx, false);
	  else if (Element == "ZoneAttr")
		tgx.ZoneAttr = false;
	  else if (tgx.ZoneAttr)
		Default.ZoneAttr.ToggleSAXElement(Element, tgx, false);
	  else if (Element == "GroupAttr")
		tgx.GroupAttr = false;
	  else if (tgx.GroupAttr)
		Default.GroupAttr.ToggleSAXElement(Element, tgx, false);
	  }
	}
  else if (tgx.Level) {
	if (Element == "Level") {
	  tgx.Level = false;
	  Levs->Add(InLev);
	  }
	else {
	  InLev->EvaluateXML(tgx.XText, tgx);
	  if (Element == "Num")
		tgx.Num = false;
	  else if (Element == "Name")
		tgx.Name = false;
	  }
	}
  else if (tgx.Graphs) {
	if (Element == "Graphs") {
	  tgx.Graphs = false;
	  int Count = GraphStyles->Count;
	  for (int i=0; i<Count; i++) {
		GRAPHS* gs = (GRAPHS*)GraphStyles->Items[i];
		delete gs;
		GraphStyles->Items[i] = 0;
		}
	  GraphStyles->Clear();
	  delete GraphStyles;

	  Count = XaxisStyles->Count;
	  for (int i=0; i<Count; i++) {
		XAXIS* xs = (XAXIS*)XaxisStyles->Items[i];
		delete xs;
		XaxisStyles->Items[i] = 0;
		}
	  XaxisStyles->Clear();
	  delete XaxisStyles;
	  }
	else if (tgx.Styles) {
	  if (Element == "Styles")
		tgx.Styles = false;
	  else if (tgx.Styles) {
		if (Element == "GraphStyle") {
		  tgx.GraphStyle = false;
		  GraphStyles->Add(InGraph);
		  }
		else if (tgx.GraphStyle) {
		  InGraph->EvaluateXML(tgx.XText, tgx, FontList);
		  InGraph->ToggleSAXElement(Element, tgx, false);
		  }
		}
	  }
	else if (tgx.Xaxes) {
	  if (Element == "Xaxes")
		tgx.Xaxes = false;
	  else if (tgx.Xaxes) {
		if (Element == "XaxisStyle") {
		  tgx.XaxisStyle = false;
		  XaxisStyles->Add(InXax);
		  }
		else if (tgx.XaxisStyle) {
		  InXax->EvaluateXML(tgx.XText, tgx, FontList);
		  InXax->ToggleSAXElement(Element, tgx, false);
		  }
		}
	  }
	else if (tgx.Graph) {
	  if (Element == "Graph") {
		tgx.Graph = false;
		grf->Add(InGrf);
		}
	  else if (tgx.Data) {
		if (tgx.Value) {
		  InGrf->EvaluateXMLValue(tgx.XText, AttrValue1, AttrValue2);
		  }
		}
	  else {
		InGrf->EvaluateXML(tgx.XText, tgx);
		}
	  InGrf->ToggleSAXElement(Element, tgx, false);
	  }
	}
  else if (tgx.Yaxis) {
	if (Element == "Yaxis") {
	  tgx.Yaxis = false;
	  YAxes->Add(InYaxis);
	  }
	else {
	  InYaxis->EvaluateXML(tgx.XText, tgx, FontList);
	  InYaxis->ToggleSAXElement(Element, tgx, false);
	  }
	}
  else if (tgx.Frame) {
	if (Element == "Frame")
	  tgx.Frame = false;
	else {
	  Frame.EvaluateXML(tgx.XText, tgx);
	  Frame.ToggleSAXElement(Element, tgx, false);
	  }
	}
  else if (tgx.RareSpecies) {
	if (Element == "RareSpecies")
	  tgx.RareSpecies = false;
	else {
	  Rare.EvaluateXML(tgx.XText, tgx);
	  Rare.ToggleSAXElement(Element, tgx, false);
	  }
	}
  else if (tgx.Header) {
	if (Element == "Header") {
	  tgx.Header = false;
	  InHead++;
	  }
	else {
	  heading[InHead].EvaluateXML(tgx.XText, tgx, FontList);
	  heading[InHead].ToggleSAXElement(Element, tgx, false);
	  }
	}
  else if (tgx.Footer) {
	if (Element == "Footer")
	  tgx.Footer = false;
	else {
	  footer.EvaluateXML(tgx.XText, tgx, FontList);
	  footer.ToggleSAXElement(Element, tgx, false);
	  }
	}
  else if (tgx.RandomText) {
	if (Element == "RandomText") {
	  tgx.RandomText = false;
	  RandomText->Add(InRandomText);
	  }
	else {
	  InRandomText->EvaluateXML(tgx.XText, tgx, FontList);
	  InRandomText->ToggleSAXElement(Element, tgx, false);
	  }
	}
  else if (tgx.Group) {
	if (Element == "Group") {
	  tgx.Group = false;
	  Groups->Add(InGroup);
	  }
	else {
	  InGroup->EvaluateXML(tgx.XText, tgx, FontList);
	  InGroup->ToggleSAXElement(Element, tgx, false);
	  }
	}
  else if (tgx.Zone) {
	if (Element == "Zone") {
	  tgx.Zone = false;
	  Zones->Add(InZone);
	  }
	else {
	  InZone->EvaluateXML(tgx.XText, tgx);
	  InZone->ToggleSAXElement(Element, tgx, false);
	  }
	}
  else if (tgx.ZoneLabelAttr) {
	if (Element == "ZoneLabelAttr")
	  tgx.ZoneLabelAttr = false;
	else {
	  zopt.EvaluateXML(tgx.XText, tgx, FontList);
	  zopt.ToggleSAXElement(Element, tgx, false);
	  }
	}
  else if (tgx.ZoneLabel) {
	if (Element == "ZoneLabel") {
	  tgx.ZoneLabel = false;
	  ZoneLabels->Add(InZoneLabel);
	  }
	else {
	  InZoneLabel->EvaluateXML(tgx.XText, tgx);
	  InZoneLabel->ToggleSAXElement(Element, tgx, false);
	  }
	}
  else if (tgx.DateAttr) {
	if (Element == "DateAttr")
	  tgx.DateAttr = false;
	else {
	  dopt.EvaluateXML(tgx.XText, tgx, FontList);
	  dopt.ToggleSAXElement(Element, tgx, false);
	  }
	}
  else if (tgx.Date) {
	if (Element == "Date") {
	  tgx.Date = false;
	  Dates->Add(InDate);
	  }
	else {
	  InDate->EvaluateXML(tgx.XText, tgx);
	  InDate->ToggleSAXElement(Element, tgx, false);
	  }
	}
  else if (tgx.DendAttr) {
	if (Element == "DendAttr")
	  tgx.DendAttr = false;
	else {
	  dgo.EvaluateXML(tgx.XText, tgx, FontList);
	  dgo.ToggleSAXElement(Element, tgx, false);
	  }
	}
  else if (tgx.Dendrogram) {
	if (tgx.Cluster) {
	  if (Element == "Cluster") {
		tgx.Cluster = false;
		Dgr->Add(InDgr);
		}
	  else {
		InDgr->EvaluateXML(tgx.XText, tgx);
		InDgr->ToggleSAXElement(Element, tgx, false);
		}
	  }
	else if (Element == "Dendrogram")
	  tgx.Dendrogram = false;
	}
  else if (tgx.DendrogramOrder) {
	if (Element == "DO") {
	  DgrOrder.push_back(tgx.XText.ToInt());
	  tgx.DO = false;
	  }
	else if (Element == "DendrogramOrder")
	  tgx.DendrogramOrder = false;
	}
  else if (tgx.LithAttr) {
	if (Element == "LithAttr")
	  tgx.LithAttr = false;
	else {
	  lopt.EvaluateXML(tgx.XText, tgx, FontList);
	  lopt.ToggleSAXElement(Element, tgx, false);
	  }
	}
  else if (tgx.LithUnit) {
	if (tgx.Component) {
	  if (Element == "Component")
		tgx.Component = false;
	  else {
		InLithComponent->EvaluateXML(tgx.XText, tgx);
		InLithComponent->ToggleSAXElement(Element, tgx, false);
		}
	  }
	else if (Element == "LithUnit") {
	  tgx.LithUnit = false;
	  Lithology->Add(InLith);
	  }
	else {
	  InLith->EvaluateXML(tgx.XText, tgx);
	  InLith->ToggleSAXElement(Element, tgx, false);
	  }
	}
  else if (tgx.LithKey) {
	if (Element == "LithKey") {
	  tgx.LithKey = false;
	  LithKeys->Add(InLithKey);
	  }
	else {
	  InLithKey->EvaluateXML(tgx.XText, tgx);
	  InLithKey->ToggleSAXElement(Element, tgx, false);
	  }
	}
}
//---------------------------------------------------------------------------

void __fastcall TTGDiagram::ipwXMLp1SpecialSection(TObject *Sender,
	  TipwXMLpSpecialSectionEventParams *e)
{
   if (e->SectionId == "CDATA") {
	 UnicodeString ustr = e->Text.w_str();
	 tgx.XText += ustr;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTGDiagram::ipwXMLp1Error(TObject *Sender,
      TipwXMLpErrorEventParams *e)
{
   UnicodeString Message = "Error reading XML file: ErrorCode = " +
                        IntToStr(e->ErrorCode) + "\n" + e->Description;
   MessageDlg(Message, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
   exit(0);
}
//---------------------------------------------------------------------------

void __fastcall TTGDiagram::ColorsAction1Execute(TObject *Sender)
{
   ColorsForm = new TColorsForm(this);
   if (ColorsForm->ShowModal() == mrOk) {
     if (ColorsForm->color_changed) {
       make_diagram();
       Picture->OutputGraphicObjects(DISPLAY, this);
       }
     }
   delete ColorsForm;
}
//---------------------------------------------------------------------------

void __fastcall TTGDiagram::LineWidthsAction1Execute(TObject *Sender)
{
   LineWidthForm = new TLineWidthForm(this);
   if (LineWidthForm->ShowModal()) {
     make_diagram();
     Repaint();
     }
   delete LineWidthForm;
}
//---------------------------------------------------------------------------

void __fastcall TTGDiagram::FontAction1Execute(TObject *Sender)
{
   GRAPH* g;
   NEWYAXIS *Axis;

   MYFONT Font;
   Font = Default.Font;
   Font.Compare(dopt.DateTitleFont);
   Font.Compare(dopt.DateFont);
   Font.Compare(lopt.LithTitleFont);
   Font.Compare(lopt.KeyFont);
   Font.Compare(zopt.ZoneTitleFont);
   Font.Compare(zopt.ZoneFont);
   Font.Compare(dgo.AxisLabelFont);
   Font.Compare(dgo.DendTitleFont);
   Font.Compare(dgo.TicFont);
   Font.Compare(Default.Graph.NumberFont);
   Font.Compare(Default.Xaxis.TicFont);
   Font.Compare(Default.Xaxis.AxisLabelFont);
   Font.Compare(Default.Xaxis.GraphNameFont);
   Font.Compare(Default.Xaxis.TruncFont);
   for (int i=0; i<YAxes->Count; i++) {
     Axis = (NEWYAXIS*)YAxes->Items[i];
     Font.Compare(Axis->TicFont);
     Font.Compare(Axis->LabelFont);
     }
   for (int i=0; i<Groups->Count; i++) {
     GROUPS *Group = (GROUPS*)Groups->Items[i];
     Font.Compare(Group->Font);
     }
   for (int i=0; i<RandomText->Count; i++) {
     TEXTLINE *TextLine = (TEXTLINE*)RandomText->Items[i];
     Font.Compare(TextLine->Font);
     }
   for (int i=0; i<4; i++)
     Font.Compare(heading[i].Font);
   Font.Compare(footer.Font);
   for (int i=0; i<grf->Count; i++) {
     g = (GRAPH*)grf->Items[i];
     Font.Compare(g->graph->NumberFont);
     Font.Compare(g->xax->TicFont);
     Font.Compare(g->xax->AxisLabelFont);
     Font.Compare(g->xax->GraphNameFont);
     Font.Compare(g->xax->TruncFont);
     }

   TFontDialogBox* FontForm = new TFontDialogBox(this);
   FontForm->SetFont(Font);

   if (FontForm->ShowModal() == mrOk) {
     Modified = true;
     FontForm->GetFont(Default.Font);

     FontForm->GetFont(dopt.DateTitleFont);
     FontForm->GetFont(dopt.DateFont);

     FontForm->GetFont(lopt.LithTitleFont);
     FontForm->GetFont(lopt.KeyFont);

     FontForm->GetFont(zopt.ZoneTitleFont);
     FontForm->GetFont(zopt.ZoneFont);

     FontForm->GetFont(dgo.AxisLabelFont);
     FontForm->GetFont(dgo.DendTitleFont);
     FontForm->GetFont(dgo.TicFont);

     FontForm->GetFont(Default.Graph.NumberFont);

     FontForm->GetFont(Default.Xaxis.TicFont);
     FontForm->GetFont(Default.Xaxis.AxisLabelFont);
     FontForm->GetFont(Default.Xaxis.GraphNameFont);
     FontForm->GetFont(Default.Xaxis.TruncFont);

     for (int i=0; i<YAxes->Count; i++) {
       Axis = (NEWYAXIS*)YAxes->Items[i];
       FontForm->GetFont(Axis->TicFont);
       FontForm->GetFont(Axis->LabelFont);
       }

     for (int i=0; i<Groups->Count; i++) {
       GROUPS *Group = (GROUPS*)Groups->Items[i];
       FontForm->GetFont(Group->Font);
       }

     for (int i=0; i<RandomText->Count; i++) {
       TEXTLINE *TextLine = (TEXTLINE*)RandomText->Items[i];
       FontForm->GetFont(TextLine->Font);
       }

     for (int i=0; i<4; i++)
       FontForm->GetFont(heading[i].Font);

     FontForm->GetFont(footer.Font);

     for (int i=0; i<grf->Count; i++) {
       g = (GRAPH*)grf->Items[i];
       FontForm->GetFont(g->graph->NumberFont);
       FontForm->GetFont(g->xax->TicFont);
       FontForm->GetFont(g->xax->AxisLabelFont);
       FontForm->GetFont(g->xax->GraphNameFont);
       FontForm->GetFont(g->xax->TruncFont);
       }

     make_diagram();
     Picture->OutputGraphicObjects(DISPLAY, this);
     }
   delete FontForm;
}
//---------------------------------------------------------------------------

void __fastcall TTGDiagram::YaxesAction1Execute(TObject *Sender)
{
   Screen->Cursor = crHourGlass;
   YaxesForm = new TYaxesForm(this);
   YaxesForm->InitialAxisNo = 1;
   if (YaxesForm->ShowModal() == mrOk) {
     make_diagram();
     Picture->OutputGraphicObjects(DISPLAY, this);
     }
   delete YaxesForm;
   Screen->Cursor = crDefault;
}
//---------------------------------------------------------------------------

void TTGDiagram::YaxisOptions(int AxisNo)
{
  Screen->Cursor = crHourGlass;
  YaxesForm = new TYaxesForm(this);
  YaxesForm->InitialAxisNo = AxisNo;
  if (YaxesForm->ShowModal() == mrOk) {
    make_diagram();
    Picture->OutputGraphicObjects(DISPLAY, this);
    }
  delete YaxesForm;
  Screen->Cursor = crDefault;
}
//---------------------------------------------------------------------------

void __fastcall TTGDiagram::XaxesAction1Execute(TObject *Sender)
{
   XaxesForm = new TXaxesForm(this);
   if (ActiveSegment.SubString(1,5) == "Graph") {
	 UnicodeString Code = ActiveSegment.SubString(8, ActiveSegment.Length()-7);
     XaxesForm->SetInitialVar(Code);
     if (XaxesForm->ShowModal() == mrOk) {
       Picture->ResetEditSegment();
       ActiveSegment = "";
       make_diagram();
       Picture->OutputGraphicObjects(DISPLAY, this);
       }
     else {
       Picture->ResetEditSegment();
       ActiveSegment = "";
       }
     ToolBar1->Hide();
     ParentForm->HideButton1->Enabled = false;
     }
   else {
     if (XaxesForm->ShowModal() == mrOk) {
       make_diagram();
       Picture->OutputGraphicObjects(DISPLAY, this);
       }
     }

   delete XaxesForm;
}
//---------------------------------------------------------------------------

void __fastcall TTGDiagram::GraphStyleAction1Execute(TObject *Sender)
{
   StyleForm = new TStyleForm(this);

   if (ActiveSegment.SubString(1,5) == "Graph") {
     UnicodeString Code = ActiveSegment.SubString(8, ActiveSegment.Length()-7);
     StyleForm->SetInitialVar(Code);
     if (StyleForm->ShowModal() == mrOk) {
       Picture->ResetEditSegment();
       ActiveSegment = "";
       make_diagram();
       Picture->OutputGraphicObjects(DISPLAY, this);
       }
     else {
       Picture->ResetEditSegment();
       ActiveSegment = "";
       }
	 ToolBar1->Hide();
     ParentForm->HideButton1->Enabled = false;
     }
   else {
     if (StyleForm->ShowModal() == mrOk) {
       make_diagram();
       Picture->OutputGraphicObjects(DISPLAY, this);
       }
     }

   delete StyleForm;
}
//---------------------------------------------------------------------------

void __fastcall TTGDiagram::VariablesAction1Execute(TObject *Sender)
{
   OrderForm = new TOrderForm(this);
   OrderForm->ShowModal();
   delete OrderForm;
   make_diagram();
   Picture->OutputGraphicObjects(DISPLAY, this);
}
//---------------------------------------------------------------------------

void __fastcall TTGDiagram::ZonesAction1Execute(TObject *Sender)
{
   Screen->Cursor = crHourGlass;
   ZoneForm = new TZoneForm(this);
   if (ZoneForm->ShowModal() == mrOk) {
     make_diagram();
     Picture->OutputGraphicObjects(DISPLAY, this);
     }
   delete ZoneForm;
}
//---------------------------------------------------------------------------

void __fastcall TTGDiagram::GroupsAction1Execute(TObject *Sender)
{
   Screen->Cursor = crHourGlass;
   GroupForm = new TGroupForm(this);
   if (GroupForm->ShowModal() == mrOk) {
     make_diagram();
     Picture->OutputGraphicObjects(DISPLAY, this);
     }
   delete GroupForm;
}
//---------------------------------------------------------------------------

void __fastcall TTGDiagram::DatesAction1Execute(TObject *Sender)
{
   Screen->Cursor = crHourGlass;
   DatesForm = new TDatesForm(this);
   if (DatesForm->ShowModal() == mrOk) {
     make_diagram();
     Picture->OutputGraphicObjects(DISPLAY, this);
     }
   delete DatesForm;
}
//---------------------------------------------------------------------------

void __fastcall TTGDiagram::LithologyAction1Execute(TObject *Sender)
{
   LithForm = new TLithForm(this);
   if (LithForm->ShowModal() == mrOk) {
     make_diagram();
     Picture->OutputGraphicObjects(DISPLAY, this);
     }
   delete LithForm;
}
//---------------------------------------------------------------------------

void __fastcall TTGDiagram::TextAction1Execute(TObject *Sender)
{
   Screen->Cursor = crHourGlass;
   TextForm = new TTextForm(this);
   TextForm->InitialItem = -1;
   if (TextForm->ShowModal() == mrOk) {
     make_diagram();
     Picture->OutputGraphicObjects(DISPLAY, this);
     }
   delete TextForm;
}
//---------------------------------------------------------------------------

void TTGDiagram::Text(int item)
{
  Screen->Cursor = crHourGlass;
  TextForm = new TTextForm(this);
  TextForm->InitialItem = item;
  if (TextForm->ShowModal() == mrOk) {
    make_diagram();
    Picture->OutputGraphicObjects(DISPLAY, this);
    }
  delete TextForm;
}
//---------------------------------------------------------------------------

void TTGDiagram::InteractiveText(void)
{
   if (AddText) {
     Screen->Cursor = crDefault;
     AddText = false;
     }
   else {
     Screen->Cursor = crCross;
     AddText = true;
     }
}
//---------------------------------------------------------------------------

void __fastcall TTGDiagram::ClusterAnalysisAction1Execute(TObject *Sender)
{
   DendrogramForm = new TDendrogramForm(this);
   if (DendrogramForm->ShowModal() == mrOk) {
     make_diagram();
     Picture->OutputGraphicObjects(DISPLAY, this);
     }
   delete DendrogramForm;
}
//---------------------------------------------------------------------------

void __fastcall TTGDiagram::FrameAction1Execute(TObject *Sender)
{
   FrameForm = new TFrameForm(this);
   if (FrameForm->ShowModal() == mrOk) {
     make_diagram();
     Picture->OutputGraphicObjects(DISPLAY, this);
     }
   delete FrameForm;
}
//---------------------------------------------------------------------------

void __fastcall TTGDiagram::RareAction1Execute(TObject *Sender)
{
   RareForm = new TRareForm(this);
   if (RareForm->ShowModal() == mrOk) {
     make_diagram();
     Picture->OutputGraphicObjects(DISPLAY, this);
     }
   delete RareForm;
}
//---------------------------------------------------------------------------

void __fastcall TTGDiagram::BoxesAction1Execute(TObject *Sender)
{
   TGBoxes1->Checked = (TGBoxes1->Checked) ? false : true;
   Boxes = TGBoxes1->Checked;
   Modified = true;
   make_diagram();
   Picture->OutputGraphicObjects(DISPLAY, this);
}
//---------------------------------------------------------------------------

void __fastcall TTGDiagram::FileCloseAction1Execute(TObject *Sender)
{
   Close();
}
//---------------------------------------------------------------------------

void __fastcall TTGDiagram::FileSaveAction1Execute(TObject *Sender)
{
   Save();
}
//---------------------------------------------------------------------------

void __fastcall TTGDiagram::FileSaveAsAction1Execute(TObject *Sender)
{
   SaveAs();
}
//---------------------------------------------------------------------------

void __fastcall TTGDiagram::FileExportAction1Execute(TObject *Sender)
{
   UnicodeString FileName = ExtractFileName(TGFileName);
   UnicodeString FilePath = ExtractFilePath(TGFileName);
   int pos;
   if ((pos = FileName.Pos(".")) > 0)
     FileName.SetLength(pos-1);
   SaveDialog1->FileName = FileName + ".emf";
   SaveDialog1->Title = "Export";

   SaveDialog1->Filter = "Enhanced Windows Metafiles (*.emf)|*.emf";
   SaveDialog1->DefaultExt = "emf";
   SaveDialog1->FilterIndex = 1;
   SaveDialog1->InitialDir = FilePath;

   if (SaveDialog1->Execute()) {
	 UnicodeString FileExt = ExtractFileExt(SaveDialog1->FileName);
     if (FileExt.CompareIC(".emf") == 0)
       WriteMetafile(SaveDialog1->FileName);
     }
}
//---------------------------------------------------------------------------

void __fastcall TTGDiagram::PrintAction1Execute(TObject *Sender)
{
   if (PrintDialog1->Execute())
     Picture->PrintOut();
   Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TTGDiagram::PrintOptionsAction1Execute(TObject *Sender)
{
   PrintForm = new TPrintForm(this);

   int result = PrintForm->ShowModal();
   if (result == mrOk) {
      PRINTOPTIONS *PrintOptions = &Picture->PrintOptions;
      PrintOptions->Option = PrintForm->RadioGroup1->ItemIndex;
      PrintOptions->DiagramHeight = PrintForm->getDiagramHeight();
      PrintOptions->YaxisHeight = PrintForm->getYaxisHeight();
      PrintOptions->Units = PrintForm->RadioGroup2->ItemIndex;
      PrintOptions->Overlap = (double)PrintForm->getOverlap();
      PrintOptions->Orientation = PrintForm->RadioGroup3->ItemIndex;

      if (PrintOptions->Option == 2) {
        PrintOptions->Inches = PrintOptions->DiagramHeight;
        if (PrintOptions->Units == 1) PrintOptions->Inches /= 2.54;
        if (PrintOptions->DiagramHeight == 0)
          PrintOptions->Option = 0;
        }
      else if (PrintOptions->Option == 3) {
        PrintOptions->Inches = PrintOptions->YaxisHeight;
        if (PrintOptions->Units == 1) PrintOptions->Inches /= 2.54;
        if (PrintOptions->YaxisHeight == 0)
          PrintOptions->Option = 0;
        }

      if (PrintForm->PrintButtonClicked) {
        if (PrintDialog1->Execute()) {
          Picture->PrintOut();
          Picture->OutputGraphicObjects(DISPLAY, this);
          }
        }
   }
   delete PrintForm;
}
//---------------------------------------------------------------------------

void TTGDiagram::SetColorBox(TColorBox* ColorBox, TColor Color)
{
   ColorBox->Selected = Color;
   if (ColorBox->Selected == clBlack)
     ColorBox->ItemIndex = 1;
}
//---------------------------------------------------------------------------

void TTGDiagram::SetCustomColor(TColor AColor, UnicodeString AColorDescription)
{
   if (count(CustomColors.begin(),CustomColors.end(),pair<TColor,UnicodeString>(AColor,AColorDescription)) == 0) {
	 CustomColors.push_front(pair<TColor,UnicodeString>(AColor,AColorDescription));
	 if (CustomColors.size() == 17)
	   CustomColors.pop_back();
	 }
}
//---------------------------------------------------------------------------

void TTGDiagram::SetColorComboBox(TcxColorComboBox* ColorComboBox, TColor AColor)
{
   int idx = ColorComboBox->Properties->Items->GetIndexByColor(AColor);
   if (idx == -1) {
	 int blue = GetBValue(AColor);
	 int green = GetGValue(AColor);
	 int red = GetRValue(AColor);
	 UnicodeString AColorDescription = IntToStr(red) + L"." + IntToStr(green) + L"." + IntToStr(blue);
	 SetCustomColor(AColor, AColorDescription);
	 ColorComboBox->Properties->Items->InsertColor(0,AColor,AColorDescription);
	 idx = 0;
	 }
   ColorComboBox->ItemIndex = idx;
}
//---------------------------------------------------------------------------

void TTGDiagram::InitColorComboBoxPopup(TcxColorComboBox* cxColorComboBox)
{
   cxColorComboBox->Properties->Items->ClearCustom();
   list<pair<TColor,UnicodeString> >::reverse_iterator itr;
   for (itr = CustomColors.rbegin(); itr != CustomColors.rend(); itr++)
	 cxColorComboBox->Properties->Items->InsertColor(0,itr->first,itr->second);
}
//---------------------------------------------------------------------------

