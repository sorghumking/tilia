//---------------------------------------------------------------------------
#define VCL_IOSTREAM
#include <vcl.h>
#include "pch.h"
#pragma hdrstop

#include "TGtgxio.h"
#ifndef TGParentH
#include "TGParent.h"
#endif
#ifndef TGH
#include "tg.h"
#endif
#ifndef TGYaxisH
#include "TGYaxis.h"
#endif
#ifndef TGUtilsH
#include "TGUtils.h"
#endif
#ifndef TIVersionH
#include "TIVersion.h"
#endif


//---------------------------------------------------------------------------
#pragma package(smart_init)


WriteTGX::WriteTGX(UnicodeString fName, TTGDiagram *diag)
{
  FileName = fName;
  d = diag;
  PBar = NULL;
}
//---------------------------------------------------------------------------

WriteTGX::~WriteTGX()
{
  if (PBar != NULL) delete PBar;
}
//---------------------------------------------------------------------------

void WriteTGX::FontList(TList* Fonts, MYFONT& NewFont)
{
  MYFONT* Font;
  bool found = false;
  for (int i=0; i<Fonts->Count; i++) {
    Font = (MYFONT*)Fonts->Items[i];
    if (*Font == NewFont) {
      found = true;
      break;
      }
    }
  if (!found)
    Fonts->Add(&NewFont);
}
//---------------------------------------------------------------------------

void WriteTGX::StyleList(int i, TList* GraphStyles, int* ng, TList* Fonts)
{
  GRAPH *g = (GRAPH*)d->grf->Items[i];
  if (g->status == ERRORBAR || g->status == NOGRAPH) {
    ng[i] = 0;
    return;
    }
  bool found = false;
  for (int j=0; j<GraphStyles->Count; j++) {
	GRAPHS *gs = (GRAPHS*)GraphStyles->Items[j];
    if (*(g->graph) == *gs) {
	  found = true;
      ng[i] = j+1;
      break;
      }
    }
  if (!found) {
    FontList(Fonts, g->graph->NumberFont);
    GraphStyles->Add(g->graph);
    ng[i] = GraphStyles->Count;
    }
}
//---------------------------------------------------------------------------

void WriteTGX::XaxisList(int i, TList* XaxisStyles, int* nx, TList* Fonts)
{
    GRAPH *g = (GRAPH*)d->grf->Items[i];
    if (g->status != NORMAL && g->status != BASE && g->status != OVERLAY &&
        g->status != STACKED && g->status != SKIP) {
      nx[i] = 0;
      return;
      }

    bool found = false;
    for (int j=0; j<XaxisStyles->Count; j++) {
      XAXIS *xs = (XAXIS*)XaxisStyles->Items[j];
      if (*(g->xax) == *xs) {
        found = true;
        nx[i] = j+1;
        break;
        }
      }
    if (!found) {
      FontList(Fonts, g->xax->TicFont);
      FontList(Fonts, g->xax->AxisLabelFont);
      FontList(Fonts, g->xax->GraphNameFont);
      FontList(Fonts, g->xax->TruncFont);
      XaxisStyles->Add(g->xax);
      nx[i] = XaxisStyles->Count;
      }
}
//---------------------------------------------------------------------------

bool WriteTGX::WriteFile(void)
{
  int i, j, n;
  GRAPH *g;
  UnicodeString Title;
  UnicodeString ustr;
  CURRENTVERSION CurrentVersion;
  MYFONT *Font;
  TList *Fonts;
  TList *GraphStyles;
  TList *XaxisStyles;
  int *ng;
  int *nx;

  xmlout = new WriteXML(FileName);
  xmlout->SetBoolStyle(ONE_ZERO);
  Screen->Cursor = crHourGlass;

  try {
  try {
  Fonts = new TList;
  Fonts->Capacity = 100;
  GraphStyles = new TList;
  GraphStyles->Capacity = 100;
  XaxisStyles = new TList;
  XaxisStyles->Capacity = 100;
  ng = new int [d->grf->Count];
  nx = new int [d->grf->Count];

  // Get fonts
  FontList(Fonts, d->Default.Font);
  FontList(Fonts, d->Default.Graph.NumberFont);
  FontList(Fonts, d->Default.Xaxis.TicFont);
  FontList(Fonts, d->Default.Xaxis.AxisLabelFont);
  FontList(Fonts, d->Default.Xaxis.GraphNameFont);
  FontList(Fonts, d->Default.Xaxis.TruncFont);
  FontList(Fonts, d->Default.GroupAttr.Font);
  for (i=0; i<d->grf->Count; i++)
    StyleList(i, GraphStyles, ng, Fonts);
  for (i=0; i<d->grf->Count; i++)
    XaxisList(i, XaxisStyles, nx, Fonts);
  for (i=0; i<d->YAxes->Count; i++) {
    NEWYAXIS *Axis = (NEWYAXIS*)d->YAxes->Items[i];
    FontList(Fonts, Axis->TicFont);
    FontList(Fonts, Axis->LabelFont);
    }
  if (d->heading[0].Text.Length() > 0) {
    i = 0;
    while (i < 4 && d->heading[i].Text.Length() > 0) {
      FontList(Fonts, d->heading[i].Font);
      i++;
	  }
	}
  FontList(Fonts, d->footer.Font);
  for (i=0; i<d->RandomText->Count; i++) {
    TEXTLINE *TextLine = (TEXTLINE*)d->RandomText->Items[i];
    FontList(Fonts, TextLine->Font);
    }
  FontList(Fonts, d->zopt.ZoneFont);
  FontList(Fonts, d->zopt.ZoneTitleFont);
  FontList(Fonts, d->dopt.DateFont);
  FontList(Fonts, d->dopt.DateTitleFont);
  FontList(Fonts, d->dgo.AxisLabelFont);
  FontList(Fonts, d->dgo.DendTitleFont);
  FontList(Fonts, d->dgo.TicFont);
  FontList(Fonts, d->lopt.LithTitleFont);
  FontList(Fonts, d->lopt.KeyFont);

  // calculate number of items to write
  n = 22;
  n += Fonts->Count;
  n += d->Levs->Count;
  n += GraphStyles->Count;
  n += XaxisStyles->Count;
  n += d->grf->Count;
  n += d->YAxes->Count;
  n += d->RandomText->Count;
  n += d->Groups->Count;
  n += d->Zones->Count;
  n += d->ZoneLabels->Count;
  n += d->Dates->Count;
  if (d->dgo.Loaded) {
    n += (d->Levs->Count-1);
    n += (int)d->DgrOrder.size();
    }
  n += d->Lithology->Count;
  n += d->LithKeys->Count;

  PBar = new TProgressBar(d);
  PBar->Top = 3;
  PBar->Left = ParentForm->StatusBar1->Panels->Items[0]->Width +
               ParentForm->StatusBar1->Panels->Items[1]->Width + 2;
  PBar->Height = 16;
  PBar->Width = ParentForm->StatusBar1->Panels->Items[2]->Width - 2;
  PBar->Max = n;
  PBar->Smooth = true;
  ParentForm->StatusBar1->InsertControl(PBar);

  xmlout->Declaration("1.0", "UTF-8", "yes");
  xmlout->DateTime();
  xmlout->BeginTag("TiliaGraph");

  UnicodeString FileName = ExtractFileName(Application->ExeName);
  int pos;
  if ((pos = FileName.Pos(".")) > 0)  // get rid of extension
	FileName.SetLength(pos-1);
  xmlout->BeginTag("Version");
  xmlout->Element("Application", FileName);
  xmlout->Element("MajorVersion", CurrentVersion.MajorVersion());
  xmlout->Element("MinorVersion", CurrentVersion.MinorVersion());
  xmlout->Element("Release", CurrentVersion.ReleaseNo());
  xmlout->EndTag("Version");
  xmlout->Element("BackgroundColor", ustr.sprintf(L"%08x", d->BackgroundColor));
  xmlout->Element("BoxStyle", d->Boxes);
  PBar->Position += 8;

  // write fonts
  for (i=0; i<Fonts->Count; i++) {
	Font = (MYFONT*)Fonts->Items[i];
	Font->XMLOUT(xmlout);
	}
  PBar->Position += Fonts->Count;

  d->Default.XMLOUT(xmlout, Fonts);
  PBar->Position += 6;

  for (i=0; i<d->Levs->Count; i++) {
	 LEVELS *Lev = (LEVELS*)d->Levs->Items[i];
	 Lev->XMLOUT(xmlout);
	 }
  PBar->Position += d->Levs->Count;

  xmlout->BeginTag("Graphs");
  xmlout->BeginTag("Styles");
  for (i=0; i<GraphStyles->Count; i++) {
	GRAPHS *gs = (GRAPHS*)GraphStyles->Items[i];
	gs->XMLOUT(xmlout, i+1, Fonts);
	}
  PBar->Position += GraphStyles->Count;
  delete GraphStyles;
  GraphStyles = NULL;
  xmlout->EndTag("Styles");
  xmlout->BeginTag("Xaxes");
  for (i=0; i<XaxisStyles->Count; i++) {
	XAXIS *xs = (XAXIS*)XaxisStyles->Items[i];
	xs->XMLOUT(xmlout, i+1, Fonts);
	}
  PBar->Position += XaxisStyles->Count;
  delete XaxisStyles;
  XaxisStyles = NULL;
  xmlout->EndTag("Xaxes");
  for (i=0; i<d->grf->Count; i++) {
	GRAPH *g = (GRAPH*)d->grf->Items[i];
	g->XMLOUT(xmlout, ng[i], nx[i]);    // includes graph, xax
	}
  PBar->Position += d->grf->Count;
  delete[] ng;
  ng = NULL;
  delete[] nx;
  nx = NULL;
  xmlout->EndTag("Graphs");

  for (i=0; i<d->YAxes->Count; i++) {
	NEWYAXIS *Axis = (NEWYAXIS*)d->YAxes->Items[i];
    Axis->XMLOUT(xmlout, Fonts);
	}
  PBar->Position += d->YAxes->Count;

  d->Frame.XMLOUT(xmlout);
  PBar->Position++;
  d->Rare.XMLOUT(xmlout);
  PBar->Position++;

  if (d->heading[0].Text.Length() > 0) {
	Title = "Header";
	i = 0;
	while (i < 4 && d->heading[i].Text.Length() > 0) {
	  d->heading[i].XMLOUT(xmlout, Title, Fonts);
	  i++;
	  }
	}
  PBar->Position++;
  if (d->footer.Text.Length() > 0) {
	Title = "Footer";
	d->footer.XMLOUT(xmlout, Title, Fonts);
	}
  PBar->Position++;

  if (d->RandomText->Count > 0) {
	for (i=0; i<d->RandomText->Count; i++) {
	  TEXTLINE *TextLine = (TEXTLINE*)d->RandomText->Items[i];
	  TextLine->XMLOUT(xmlout, Fonts);
	  }
	PBar->Position += d->RandomText->Count;
	}

  if (d->Groups->Count > 0) {
	for (i=0; i<d->Groups->Count; i++) {
	  GROUPS *Group = (GROUPS*)d->Groups->Items[i];
	  Group->XMLOUT(xmlout, Fonts);
	  }
	PBar->Position += d->Groups->Count;
	}

  if (d->Zones->Count > 0) {
	for (i=0; i<d->Zones->Count; i++) {
	  ZONE *Zone = (ZONE*)d->Zones->Items[i];
	  Zone->XMLOUT(xmlout);
	  }
	PBar->Position += d->Zones->Count;
	}

  d->zopt.XMLOUT(xmlout, Fonts);
  PBar->Position++;
  if (d->ZoneLabels->Count > 0) {
	for (i=0; i<d->ZoneLabels->Count; i++) {
	  ZONELABELS *ZoneLabel = (ZONELABELS*)d->ZoneLabels->Items[i];
	  ZoneLabel->XMLOUT(xmlout);
	  }
	PBar->Position += d->ZoneLabels->Count;
	}

  d->dopt.XMLOUT(xmlout, Fonts);
  PBar->Position++;
  if (d->Dates->Count > 0) {
	for (i=0; i<d->Dates->Count; i++) {
	  DATES* Date = (DATES*)d->Dates->Items[i];
	  Date->XMLOUT(xmlout);
	  }
	PBar->Position += d->Dates->Count;
	}

  d->dgo.XMLOUT(xmlout, Fonts);
  PBar->Position++;
  if (d->dgo.Loaded) {
	xmlout->BeginTag("Dendrogram");
	for (i=0; i<d->Levs->Count-1; i++) {
	  DENDROGRAM *Cluster = (DENDROGRAM*)d->Dgr->Items[i];
	  Cluster->XMLOUT(xmlout);
	  }
	PBar->Position += (d->Levs->Count-1);
	xmlout->EndTag("Dendrogram");
	xmlout->BeginTag("DendrogramOrder");
	for (i=0; i<(int)d->DgrOrder.size(); i++)
	  xmlout->Element("DO", d->DgrOrder[i]);
	xmlout->EndTag("DendrogramOrder");
	PBar->Position += (int)d->DgrOrder.size();
	}

  d->lopt.XMLOUT(xmlout, Fonts);
  PBar->Position++;
  if (d->Lithology->Count > 0) {
	for (i=0; i<d->Lithology->Count; i++) {
	  LITHUNIT* Lith = (LITHUNIT*)d->Lithology->Items[i];
	  Lith->XMLOUT(xmlout);
	  }
	PBar->Position += d->Lithology->Count;
	for (i=0; i<d->LithKeys->Count; i++) {
	  LITHKEY* LithKey = (LITHKEY*)d->LithKeys->Items[i];
	  LithKey->XMLOUT(xmlout);
	  }
	PBar->Position += d->LithKeys->Count;
	}

  xmlout->EndTag("TiliaGraph");
  xmlout->Finish();
  }
  catch (...) {
  }
  }
  __finally {

  // fonts are not deleted because they belong to other classes
  delete Fonts;
  if (GraphStyles)
	delete GraphStyles;
  if (XaxisStyles)
	delete XaxisStyles;
  if (ng)
	delete[] ng;
  if (nx)
	delete[] nx;

  delete PBar;
  PBar = NULL;
  delete xmlout;
  Screen->Cursor = crDefault;
  }
  return true;
}
//---------------------------------------------------------------------------

DEFAULT::DEFAULT()
{
  LineWidth = 0.25;
}
//---------------------------------------------------------------------------

void DEFAULT::XMLOUT(WriteXML* xmlout, TList* Fonts)
{
  xmlout->BeginTag("DefaultSettings");
  xmlout->Element("LineWidth", LineWidth);
  xmlout->Element("DefaultFont", GetFontNumber(Fonts, Font));
  Graph.XMLOUT(xmlout, 0, Fonts);
  Xaxis.XMLOUT(xmlout, 0, Fonts);
  ZoneAttr.XMLOUT(xmlout);
  GroupAttr.XMLOUT(xmlout, Fonts);
  xmlout->EndTag("DefaultSettings");
}
//---------------------------------------------------------------------------

void DEFAULT::EvaluateXML(UnicodeString& ustr, TGXXML& tgx, TList* Fonts)
{
  if (tgx.LineWidth)
	LineWidth = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.DefaultFont)
	Font = *(MYFONT*)Fonts->Items[ustr.ToInt()];
  else if (tgx.GraphStyle)
	Graph.EvaluateXML(ustr, tgx, Fonts);
  else if (tgx.XaxisStyle)
	Xaxis.EvaluateXML(ustr, tgx, Fonts);
  else if (tgx.ZoneAttr)
	ZoneAttr.EvaluateXML(ustr, tgx);
  else if (tgx.GroupAttr)
	GroupAttr.EvaluateXML(ustr, tgx, Fonts);
}
//---------------------------------------------------------------------------

void LEVELS::XMLOUT(WriteXML* xmlout)
{
  xmlout->BeginTag("Level");
  xmlout->Element("Num", num);
  if (name.Length() > 0)
	xmlout->CDATA("Name", name);
  else
	xmlout->EmptyElement("Name");
  xmlout->EndTag("Level");
}
//---------------------------------------------------------------------------

void LEVELS::EvaluateXML(UnicodeString& ustr, TGXXML& tgx)
{
  if (tgx.Num)
	num = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.Name)
	name = ustr;
}
//---------------------------------------------------------------------------

GRAPHS::GRAPHS()
{
  VerticalAxis = true;
  SymbolName = false;
  ZeroSymbol = true;
  AutoMarkerTop = false;
  AutoMarkerBottom = true;
  PresenceSymbol = false;
  DepthBars = false;
  DottedBaseLine = false;
  PlotZeroNumbers = true;
  UseThickVar = false;
  GraphType = SILHOUETTE;
  SilhouetteFill = SOLID_FILL;
  SilhouettePattern = 6;
  Exag = 0;
  ExagFill = PATTERN_FILL;
  ExagPattern = 18;
  ExagGrid = ONMAJORTICS;
  BarFill = SOLID_FILL;
  BarPattern = 6;
  DecimalPoints = 0;
  MarkerType = 0;
  GraphColor = clBlack;
  ExagColor = clBlack;
  GraphOutlineColor = clBlack;
  ExagOutlineColor = clBlack;
  DepthBarsColor = clBlack;
  SilhouetteLineWidth = 0.25;
  HistogramLineWidth = 0.25;
  LineGraphLineWidth = 0.25;
  MarkerLineWidth = 0.25;
  BarWidth = 0.0;
  MarkerSize = 0.15;
  XMarkerLabel = 0.0;
  YMarkerLabel = 0.0;
  AngleMarkerLabel = 0.0;
  XPresence = 5.0;
  NumberFont.Height = 0.1;
}
//---------------------------------------------------------------------------

GRAPHS::GRAPHS(GRAPHS *g)
{
  VerticalAxis = g->VerticalAxis;
  SymbolName = g->SymbolName;
  ZeroSymbol = g->ZeroSymbol;
  AutoMarkerTop = g->AutoMarkerTop;
  AutoMarkerBottom = g->AutoMarkerBottom;
  PresenceSymbol = g->PresenceSymbol;
  DepthBars = g->DepthBars;
  DottedBaseLine = g->DottedBaseLine;
  PlotZeroNumbers = g->PlotZeroNumbers;
  UseThickVar = g->UseThickVar;
  GraphType = g->GraphType;
  SilhouetteFill = g->SilhouetteFill;
  SilhouettePattern = g->SilhouettePattern;
  Exag = g->Exag;
  ExagFill = g->ExagFill;
  ExagPattern = g->ExagPattern;
  ExagGrid = g->ExagGrid;
  BarFill = g->BarFill;
  BarPattern = g->BarPattern;
  DecimalPoints = g->DecimalPoints;
  MarkerType = g->MarkerType;
  GraphColor = g->GraphColor;
  ExagColor = g->ExagColor;
  GraphOutlineColor = g->GraphOutlineColor;
  ExagOutlineColor = g->ExagOutlineColor;
  DepthBarsColor = g->DepthBarsColor;
  SilhouetteLineWidth = g->SilhouetteLineWidth;
  HistogramLineWidth = g->HistogramLineWidth;
  LineGraphLineWidth = g->LineGraphLineWidth;
  MarkerLineWidth = g->MarkerLineWidth;
  BarWidth = g->BarWidth;
  MarkerSize = g->MarkerSize;
  XMarkerLabel = g->XMarkerLabel;
  YMarkerLabel = g->YMarkerLabel;
  AngleMarkerLabel = g->AngleMarkerLabel;
  XPresence = g->XPresence;
  NumberFont = g->NumberFont;
}
//---------------------------------------------------------------------------

bool GRAPHS::operator == (const GRAPHS& compare )
{
   // return false if any of the variables are not equal
   if (this == &compare) return true;

   if (VerticalAxis != compare.VerticalAxis) return false;
   if (SymbolName != compare.SymbolName) return false;
   if (ZeroSymbol != compare.ZeroSymbol) return false;
   if (AutoMarkerTop != compare.AutoMarkerTop) return false;
   if (AutoMarkerBottom != compare.AutoMarkerBottom) return false;
   if (PresenceSymbol != compare.PresenceSymbol) return false;
   if (DepthBars != compare.DepthBars) return false;
   if (DottedBaseLine != compare.DottedBaseLine) return false;
   if (PlotZeroNumbers != compare.PlotZeroNumbers) return false;
   if (UseThickVar != compare.UseThickVar) return false;
   if (GraphType != compare.GraphType) return false;
   if (SilhouetteFill != compare.SilhouetteFill) return false;
   if (SilhouettePattern != compare.SilhouettePattern) return false;
   if (Exag != compare.Exag) return false;
   if (ExagFill != compare.ExagFill) return false;
   if (ExagPattern != compare.ExagPattern) return false;
   if (ExagGrid != compare.ExagGrid) return false;
   if (BarFill != compare.BarFill) return false;
   if (BarPattern != compare.BarPattern) return false;
   if (DecimalPoints != compare.DecimalPoints) return false;
   if (MarkerType != compare.MarkerType) return false;
   if (GraphColor != compare.GraphColor) return false;
   if (ExagColor != compare.ExagColor) return false;
   if (GraphOutlineColor != compare.GraphOutlineColor) return false;
   if (ExagOutlineColor != compare.ExagOutlineColor) return false;
   if (DepthBarsColor != compare.DepthBarsColor) return false;
   if (SilhouetteLineWidth != compare.SilhouetteLineWidth) return false;
   if (HistogramLineWidth != compare.HistogramLineWidth) return false;
   if (LineGraphLineWidth != compare.LineGraphLineWidth) return false;
   if (MarkerLineWidth != compare.MarkerLineWidth) return false;
   if (BarWidth != compare.BarWidth) return false;
   if (MarkerSize != compare.MarkerSize) return false;
   if (XMarkerLabel != compare.XMarkerLabel) return false;
   if (YMarkerLabel != compare.YMarkerLabel) return false;
   if (AngleMarkerLabel != compare.AngleMarkerLabel) return false;
   if (XPresence != compare.XPresence) return false;
   if (NumberFont != compare.NumberFont) return false;

   return true;
}
//---------------------------------------------------------------------------

void GRAPHS::XMLOUT(WriteXML* xmlout, short id, TList* Fonts)
{
  UnicodeString ustr;

  ustr = "GS" + IntToStr(id);
  xmlout->BeginTag("GraphStyle", "ID", ustr);
  switch (GraphType) {
	case SILHOUETTE: ustr = "SILHOUETTE"; break;
	case HISTOGRAM:  ustr = "HISTOGRAM";  break;
	case LINEGRAPH:  ustr = "LINEGRAPH";  break;
	case NUMBERS:    ustr = "NUMBERS";    break;
	case PRESENCE:   ustr = "PRESENCE";   break;
	}
  xmlout->Element("GraphType", ustr);
  WriteFillStyle(xmlout, SilhouetteFill, "SilhouetteFill");
  xmlout->Element("SilhouettePattern", SilhouettePattern);
  xmlout->Element("Exag", Exag);
  WriteFillStyle(xmlout, ExagFill, "ExagFill");
  xmlout->Element("ExagPattern", ExagPattern);
  switch (ExagGrid) {
	case NOGRIDLINES: ustr = "NOGRIDLINES"; break;
	case ONMINORTICS: ustr = "ONMINORTICS"; break;
	case ONMAJORTICS: ustr = "ONMAJORTICS"; break;
	}
  xmlout->Element("ExagGrid", ustr);
  WriteFillStyle(xmlout, BarFill, "BarFill");
  xmlout->Element("BarWidth", BarWidth);
  xmlout->Element("BarPattern", BarPattern);
  xmlout->Element("MarkerType", MarkerType);
  xmlout->Element("MarkerSize", MarkerSize);
  xmlout->Element("XMarkerLabel", XMarkerLabel);
  xmlout->Element("YMarkerLabel", YMarkerLabel);
  xmlout->Element("AngleMarkerLabel", AngleMarkerLabel);
  xmlout->Element("DecimalPoints", DecimalPoints);
  xmlout->Element("NumberFont", GetFontNumber(Fonts, NumberFont));
  xmlout->Element("XPresence", XPresence);
  xmlout->Element("GraphColor", ustr.sprintf(L"%08x", GraphColor));
  xmlout->Element("ExagColor", ustr.sprintf(L"%08x", ExagColor));
  xmlout->Element("GraphOutlineColor", ustr.sprintf(L"%08x", GraphOutlineColor));
  xmlout->Element("ExagOutlineColor", ustr.sprintf(L"%08x", ExagOutlineColor));
  xmlout->Element("DepthBarsColor", ustr.sprintf(L"%08x", DepthBarsColor));
  xmlout->Element("SilhouetteLineWidth", SilhouetteLineWidth);
  xmlout->Element("HistogramLineWidth", HistogramLineWidth);
  xmlout->Element("LineGraphLineWidth", LineGraphLineWidth);
  xmlout->Element("MarkerLineWidth", MarkerLineWidth);
  xmlout->Element("VerticalAxis", VerticalAxis);
  xmlout->Element("SymbolName", SymbolName);
  xmlout->Element("ZeroSymbol", ZeroSymbol);
  xmlout->Element("AutoMarkerTop", AutoMarkerTop);
  xmlout->Element("AutoMarkerBottom", AutoMarkerBottom);
  xmlout->Element("PresenceSymbol", PresenceSymbol);
  xmlout->Element("DepthBars", DepthBars);
  xmlout->Element("DottedBaseLine", DottedBaseLine);
  xmlout->Element("PlotZeroNumbers", PlotZeroNumbers);
  xmlout->Element("UseThickVar", UseThickVar);
  xmlout->EndTag("GraphStyle");
}
//---------------------------------------------------------------------------

void GRAPHS::WriteFillStyle(WriteXML* xmlout, short Style, UnicodeString Element)
{
  UnicodeString ustr;
  switch (Style) {
	case NO_FILL:      ustr = "NO_FILL";      break;
	case HOLLOW_FILL:  ustr = "HOLLOW_FILL";  break;
	case SOLID_FILL:   ustr = "SOLID_FILL";   break;
	case PATTERN_FILL: ustr = "PATTERN_FILL"; break;
	case BAR_FILL:     ustr = "BAR_FILL";     break;
	case GRID_FILL:    ustr = "GRID_FILL";    break;
	}
  xmlout->Element(Element, ustr);
}
//---------------------------------------------------------------------------

short GRAPHS::ParseFillStyle(UnicodeString& Value)
{
   short fill=NO_FILL;
   if (Value == "NO_FILL")
     fill = NO_FILL;
   else if (Value == "HOLLOW_FILL")
	 fill = HOLLOW_FILL;
   else if (Value == "SOLID_FILL")
	 fill = SOLID_FILL;
   else if (Value == "PATTERN_FILL")
	 fill = PATTERN_FILL;
   else if (Value == "BAR_FILL")
	 fill = BAR_FILL;
   else if (Value == "GRID_FILL")
	 fill = GRID_FILL;
   return fill;
}
//---------------------------------------------------------------------------

void GRAPHS::ToggleSAXElement(UnicodeString& Element, TGXXML& tgx, bool toggle)
{
   if (Element == "GraphType")
	  tgx.GraphType = toggle;
	else if (Element == "SilhouetteFill")
	  tgx.SilhouetteFill = toggle;
	else if (Element == "SilhouettePattern")
	  tgx.SilhouettePattern = toggle;
	else if (Element == "Exag")
	  tgx.Exag = toggle;
	else if (Element == "ExagFill")
	  tgx.ExagFill = toggle;
	else if (Element == "ExagPattern")
	  tgx.ExagPattern = toggle;
	else if (Element == "ExagGrid")
	  tgx.ExagGrid = toggle;
	else if (Element == "BarFill")
	  tgx.BarFill = toggle;
	else if (Element == "BarWidth")
	  tgx.BarWidth = toggle;
	else if (Element == "BarPattern")
	  tgx.BarPattern = toggle;
	else if (Element == "MarkerType")
	  tgx.MarkerType = toggle;
	else if (Element == "MarkerSize")
	  tgx.MarkerSize = toggle;
	else if (Element == "XMarkerLabel")
	  tgx.XMarkerLabel = toggle;
	else if (Element == "YMarkerLabel")
	  tgx.YMarkerLabel = toggle;
	else if (Element == "AngleMarkerLabel")
	  tgx.AngleMarkerLabel = toggle;
	else if (Element == "DecimalPoints")
	  tgx.DecimalPoints = toggle;
	else if (Element == "NumberFont")
	  tgx.NumberFont = toggle;
	else if (Element == "XPresence")
	  tgx.XPresence = toggle;
	else if (Element == "GraphColor")
	  tgx.GraphColor = toggle;
	else if (Element == "ExagColor")
	  tgx.ExagColor = toggle;
	else if (Element == "GraphOutlineColor")
	  tgx.GraphOutlineColor = toggle;
	else if (Element == "ExagOutlineColor")
	  tgx.ExagOutlineColor = toggle;
	else if (Element == "DepthBarsColor")
	  tgx.DepthBarsColor = toggle;
	else if (Element == "SilhouetteLineWidth")
	  tgx.SilhouetteLineWidth = toggle;
	else if (Element == "HistogramLineWidth")
	  tgx.HistogramLineWidth = toggle;
	else if (Element == "LineGraphLineWidth")
	  tgx.LineGraphLineWidth = toggle;
	else if (Element == "MarkerLineWidth")
	  tgx.MarkerLineWidth = toggle;
	else if (Element == "VerticalAxis")
	  tgx.VerticalAxis = toggle;
	else if (Element == "SymbolName")
	  tgx.SymbolName = toggle;
	else if (Element == "ZeroSymbol")
	  tgx.ZeroSymbol = toggle;
	else if (Element == "AutoMarkerTop")
	  tgx.AutoMarkerTop = toggle;
	else if (Element == "AutoMarkerBottom")
	  tgx.AutoMarkerBottom = toggle;
	else if (Element == "PresenceSymbol")
	  tgx.PresenceSymbol = toggle;
	else if (Element == "DepthBars")
	  tgx.DepthBars = toggle;
	else if (Element == "DottedBaseLine")
	  tgx.DottedBaseLine = toggle;
	else if (Element == "PlotZeroNumbers")
	  tgx.PlotZeroNumbers = toggle;
	else if (Element == "UseThickVar")
	  tgx.UseThickVar = toggle;
}
//---------------------------------------------------------------------------

void GRAPHS::EvaluateXML(UnicodeString& ustr, TGXXML& tgx, TList* Fonts)
{
  if (tgx.GraphType) {
	if (ustr == "SILHOUETTE")
	  GraphType = SILHOUETTE;
	else if (ustr == "HISTOGRAM")
	  GraphType = HISTOGRAM;
	else if (ustr == "LINEGRAPH")
	  GraphType = LINEGRAPH;
	else if (ustr == "NUMBERS")
	  GraphType = NUMBERS;
	else if (ustr == "PRESENCE")
	  GraphType = PRESENCE;
	}
  else if (tgx.SilhouetteFill)
	SilhouetteFill = ParseFillStyle(ustr);
  else if (tgx.SilhouettePattern)
	SilhouettePattern = (short)ustr.ToInt();
  else if (tgx.Exag)
	Exag = (short)ustr.ToInt();
  else if (tgx.ExagFill)
	ExagFill = ParseFillStyle(ustr);
  else if (tgx.ExagPattern)
	ExagPattern = (short)ustr.ToInt();
  else if (tgx.ExagGrid) {
	if (ustr == "NOGRIDLINES")
	  ExagGrid = NOGRIDLINES;
	else if (ustr == "ONMINORTICS")
	  ExagGrid = ONMINORTICS;
	else if (ustr == "ONMAJORTICS")
	  ExagGrid = ONMAJORTICS;
	}
  else if (tgx.BarFill)
	BarFill = ParseFillStyle(ustr);
  else if (tgx.BarWidth)
	BarWidth = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.BarPattern)
	BarPattern = (short)ustr.ToInt();
  else if (tgx.MarkerType)
	MarkerType = (short)ustr.ToInt();
  else if (tgx.MarkerSize)
	MarkerSize = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.XMarkerLabel)
	XMarkerLabel = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.YMarkerLabel)
	YMarkerLabel = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.AngleMarkerLabel)
	AngleMarkerLabel = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.DecimalPoints)
	DecimalPoints = (short)ustr.ToInt();
  else if (tgx.NumberFont)
	NumberFont = *(MYFONT*)Fonts->Items[ustr.ToInt()];
  else if (tgx.XPresence)
	XPresence = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.GraphColor) {
	UnicodeString Hex = "0x" + ustr;
	GraphColor = (TColor)Hex.ToInt();
	}
  else if (tgx.ExagColor) {
	UnicodeString Hex = "0x" + ustr;
	ExagColor = (TColor)Hex.ToInt();
	}
  else if (tgx.GraphOutlineColor) {
	UnicodeString Hex = "0x" + ustr;
	GraphOutlineColor = (TColor)Hex.ToInt();
	}
  else if (tgx.ExagOutlineColor) {
	UnicodeString Hex = "0x" + ustr;
	ExagOutlineColor = (TColor)Hex.ToInt();
	}
  else if (tgx.DepthBarsColor) {
	UnicodeString Hex = "0x" + ustr;
	DepthBarsColor = (TColor)Hex.ToInt();
	}
  else if (tgx.SilhouetteLineWidth)
	SilhouetteLineWidth = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.HistogramLineWidth)
	HistogramLineWidth = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.LineGraphLineWidth)
	LineGraphLineWidth = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.MarkerLineWidth)
	MarkerLineWidth = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.VerticalAxis)
	VerticalAxis = (bool)ustr.ToInt();
  else if (tgx.SymbolName)
	SymbolName = (bool)ustr.ToInt();
  else if (tgx.ZeroSymbol)
	ZeroSymbol = (bool)ustr.ToInt();
  else if (tgx.AutoMarkerTop)
	AutoMarkerTop = (bool)ustr.ToInt();
  else if (tgx.AutoMarkerBottom)
	AutoMarkerBottom = (bool)ustr.ToInt();
  else if (tgx.PresenceSymbol)
	PresenceSymbol = (bool)ustr.ToInt();
  else if (tgx.DepthBars)
	DepthBars = (bool)ustr.ToInt();
  else if (tgx.DottedBaseLine)
	DottedBaseLine = (bool)ustr.ToInt();
  else if (tgx.PlotZeroNumbers)
	PlotZeroNumbers = (bool)ustr.ToInt();
  else if (tgx.UseThickVar)
	UseThickVar = (bool)ustr.ToInt();
}
//---------------------------------------------------------------------------

XAXIS::XAXIS()
{
  AutoTic = true;
  AutoScaleFactor = true;
  AutoMin = true;
  AutoMax = true;
  LabelOriginTic = false;
  Truncate = false;
  PlotGraphName = true;
  TicDecPts = 0;
  GridLines = NOGRIDLINES;
  PrintTruncatedValues = false;
  ScaleTruncatedValues = true;
  TruncateWhere = END_OF_GRAPH;
  TruncateDecPts = 0;
  Color = clBlack;
  GraphWidth = -1.0;
  ScaleFactor = 0.0;       // calculated
  MinorTics = 0.0;        // calculated
  MajorTics = 0.0;        // calculated
  LabeledTics = 0.0;     // calculated
  TicLabelDivideBy = 1.0;
  LabelToTicDistance = 0.05;
  MajorTicLength = 0.1;
  MinorTicLength = 0.06;
  TopTicLength = 0.05;
  GraphNameAngle = 45.0;
  GraphNameXOffset = 0.2;
  GraphNameYOffset = -0.05;
  DistanceToNextGraph = 0.2;
  XaxisMin = 0.0;               // calculated
  XaxisMax = 0.0;               // calculated
  AxisLineWidth = 0.25;
  GridLineWidth = 0.25;
  TicFont.Height = 0.35;
  AxisLabelFont.Height = 0.35;
  GraphNameFont.Height = 0.35;
  TruncFont.Height = 0.25;
}
//---------------------------------------------------------------------------

XAXIS::XAXIS(XAXIS *a)
{
  AutoTic = a->AutoTic;
  AutoScaleFactor = a->AutoScaleFactor;
  AutoMin = a->AutoMin;
  AutoMax = a->AutoMax;
  LabelOriginTic = a->LabelOriginTic;
  Truncate = a->Truncate;
  PlotGraphName = a->PlotGraphName;
  TicDecPts = a->TicDecPts;
  GridLines = a->GridLines;
  PrintTruncatedValues = a->PrintTruncatedValues;
  ScaleTruncatedValues = a->ScaleTruncatedValues;
  TruncateWhere = a->TruncateWhere;
  TruncateDecPts = a->TruncateDecPts;
  Color = a->Color;
  GraphWidth = a->GraphWidth;
  ScaleFactor = a->ScaleFactor;
  MinorTics = a->MinorTics;
  MajorTics = a->MajorTics;
  LabeledTics = a->LabeledTics;
  TicLabelDivideBy = a->TicLabelDivideBy;
  LabelToTicDistance = a->LabelToTicDistance;
  MajorTicLength = a->MajorTicLength;
  MinorTicLength = a->MinorTicLength;
  TopTicLength = a->TopTicLength;
  GraphNameAngle = a->GraphNameAngle;
  GraphNameXOffset = a->GraphNameXOffset;
  GraphNameYOffset = a->GraphNameYOffset;
  DistanceToNextGraph = a->DistanceToNextGraph;
  XaxisMin = a->XaxisMin;
  XaxisMax = a->XaxisMax;
  AxisLineWidth = a->AxisLineWidth;
  GridLineWidth = a->GridLineWidth;
  AxisLabel = a->AxisLabel;
  TicFont = a->TicFont;
  AxisLabelFont = a->AxisLabelFont;
  GraphNameFont = a->GraphNameFont;
  TruncFont = a->TruncFont;
}
//---------------------------------------------------------------------------

bool XAXIS::operator == (const XAXIS& compare )
{
   // return true if any of the variables are not equal
   if (this == &compare) return true;   // already changed

   if (AutoTic != compare.AutoTic) return false;
   if (AutoScaleFactor != compare.AutoScaleFactor) return false;
   if (AutoMin != compare.AutoMin) return false;
   if (AutoMax != compare.AutoMax) return false;
   if (LabelOriginTic != compare.LabelOriginTic) return false;
   if (Truncate != compare.Truncate) return false;
   if (PlotGraphName != compare.PlotGraphName) return false;
   if (TicDecPts != compare.TicDecPts) return false;
   if (GridLines != compare.GridLines) return false;
   if (PrintTruncatedValues != compare.PrintTruncatedValues) return false;
   if (ScaleTruncatedValues != compare.ScaleTruncatedValues) return false;
   if (TruncateWhere != compare.TruncateWhere) return false;
   if (TruncateDecPts != compare.TruncateDecPts) return false;
   if (Color != compare.Color) return false;
   if (GraphWidth != compare.GraphWidth) return false;
   if (ScaleFactor != compare.ScaleFactor) return false;
   if (MinorTics != compare.MinorTics) return false;
   if (MajorTics != compare.MajorTics) return false;
   if (LabeledTics != compare.LabeledTics) return false;
   if (TicLabelDivideBy != compare.TicLabelDivideBy) return false;
   if (LabelToTicDistance != compare.LabelToTicDistance) return false;
   if (MajorTicLength != compare.MajorTicLength) return false;
   if (MinorTicLength != compare.MinorTicLength) return false;
   if (TopTicLength != compare.TopTicLength) return false;
   if (GraphNameAngle != compare.GraphNameAngle) return false;
   if (GraphNameXOffset != compare.GraphNameXOffset) return false;
   if (GraphNameYOffset != compare.GraphNameYOffset) return false;
   if (DistanceToNextGraph != compare.DistanceToNextGraph) return false;
   if (XaxisMin != compare.XaxisMin) return false;
   if (XaxisMax != compare.XaxisMax) return false;
   if (AxisLineWidth != compare.AxisLineWidth) return false;
   if (GridLineWidth != compare.GridLineWidth) return false;
   if (AxisLabel != compare.AxisLabel) return false;
   if (TicFont != compare.TicFont) return false;
   if (AxisLabelFont != compare.AxisLabelFont) return false;
   if (GraphNameFont != compare.GraphNameFont) return false;
   if (TruncFont != compare.TruncFont) return false;

   return true;
}
//---------------------------------------------------------------------------

void XAXIS::XMLOUT(WriteXML* xmlout, short id, TList* Fonts)
{
  UnicodeString ustr;

  ustr = "XS" + IntToStr(id);
  xmlout->BeginTag("XaxisStyle", "ID", ustr);
  xmlout->Element("AutoTic", AutoTic);
  xmlout->Element("AutoScaleFactor", AutoScaleFactor);
  xmlout->Element("AutoMin", AutoMin);
  xmlout->Element("AutoMax", AutoMax);
  xmlout->Element("LabelOriginTic", LabelOriginTic);
  xmlout->Element("Truncate", Truncate);
  xmlout->Element("PrintTruncatedValues", PrintTruncatedValues);
  xmlout->Element("ScaleTruncatedValues", ScaleTruncatedValues);
  switch (TruncateWhere) {
	case END_OF_GRAPH: ustr = "END_OF_GRAPH"; break;
	case END_OF_AXIS:  ustr = "END_OF_AXIS";  break;
	}
  xmlout->Element("TruncateWhere", ustr);
  xmlout->Element("TruncateDecPts", TruncateDecPts);
  xmlout->Element("PlotGraphName", PlotGraphName);
  xmlout->Element("TicDecPts", TicDecPts);
  switch (GridLines) {
	case NOGRIDLINES: ustr = "NOGRIDLINES"; break;
	case ONMINORTICS: ustr = "ONMINORTICS"; break;
	case ONMAJORTICS: ustr = "ONMAJORTICS"; break;
	}
  xmlout->Element("GridLines", ustr);
  xmlout->Element("Color", ustr.sprintf(L"%08x", Color));
  xmlout->Element("GraphWidth", GraphWidth);
  xmlout->Element("ScaleFactor", ScaleFactor);
  xmlout->Element("MinorTics", MinorTics);
  xmlout->Element("MajorTics", MajorTics);
  xmlout->Element("LabeledTics", LabeledTics);
  xmlout->Element("TicLabelDivideBy", TicLabelDivideBy);
  xmlout->Element("LabelToTicDistance", LabelToTicDistance);
  xmlout->Element("MajorTicLength", MajorTicLength);
  xmlout->Element("MinorTicLength", MinorTicLength);
  xmlout->Element("TopTicLength", TopTicLength);
  xmlout->Element("GraphNameAngle", GraphNameAngle);
  xmlout->Element("GraphNameXOffset", GraphNameXOffset);
  xmlout->Element("GraphNameYOffset", GraphNameYOffset);
  xmlout->Element("DistanceToNextGraph", DistanceToNextGraph);
  xmlout->Element("XaxisMin", XaxisMin);
  xmlout->Element("XaxisMax", XaxisMax);
  xmlout->Element("AxisLineWidth", AxisLineWidth);
  xmlout->Element("GridLineWidth", GridLineWidth);
  xmlout->Element("TicFont", GetFontNumber(Fonts, TicFont));
  xmlout->Element("AxisLabelFont", GetFontNumber(Fonts, AxisLabelFont));
  xmlout->Element("GraphNameFont", GetFontNumber(Fonts, GraphNameFont));
  xmlout->Element("TruncateFont", GetFontNumber(Fonts, TruncFont));
  xmlout->CDATA("XAxisLabel", AxisLabel);
  xmlout->EndTag("XaxisStyle");
}
//---------------------------------------------------------------------------

void XAXIS::ToggleSAXElement(UnicodeString& Element, TGXXML& tgx, bool toggle)
{
   if (Element == "AutoTic")
	  tgx.AutoTic = toggle;
	else if (Element == "AutoScaleFactor")
	  tgx.AutoScaleFactor = toggle;
	else if (Element == "AutoMin")
	  tgx.AutoMin = toggle;
	else if (Element == "AutoMax")
	  tgx.AutoMax = toggle;
	else if (Element == "LabelOriginTic")
	  tgx.LabelOriginTic = toggle;
	 else if (Element == "Truncate")
	  tgx.Truncate = toggle;
	else if (Element == "PrintTruncatedValues")
	  tgx.PrintTruncatedValues = toggle;
	else if (Element == "ScaleTruncatedValues")
	  tgx.ScaleTruncatedValues = toggle;
	else if (Element == "TruncateWhere")
	  tgx.TruncateWhere = toggle;
	else if (Element == "TruncateDecPts")
	  tgx.TruncateDecPts = toggle;
	else if (Element == "PlotGraphName")
	  tgx.PlotGraphName = toggle;
	else if (Element == "TicDecPts")
	  tgx.TicDecPts = toggle;
	else if (Element == "GridLines")
	  tgx.GridLines = toggle;
	else if (Element == "Color")
	  tgx.Color = toggle;
	else if (Element == "GraphWidth")
	  tgx.GraphWidth = toggle;
	else if (Element == "ScaleFactor")
	  tgx.ScaleFactor = toggle;
	else if (Element == "MinorTics")
	  tgx.MinorTics = toggle;
	else if (Element == "MajorTics")
	  tgx.MajorTics = toggle;
	else if (Element == "LabeledTics")
	  tgx.LabeledTics = toggle;
	else if (Element == "TicLabelDivideBy")
	  tgx.TicLabelDivideBy = toggle;
	else if (Element == "LabelToTicDistance")
	  tgx.LabelToTicDistance = toggle;
	else if (Element == "MajorTicLength")
	  tgx.MajorTicLength = toggle;
	else if (Element == "MinorTicLength")
	  tgx.MinorTicLength = toggle;
	else if (Element == "TopTicLength")
	  tgx.TopTicLength = toggle;
	else if (Element == "GraphNameAngle")
	  tgx.GraphNameAngle = toggle;
	else if (Element == "GraphNameXOffset")
	  tgx.GraphNameXOffset = toggle;
	else if (Element == "GraphNameYOffset")
	  tgx.GraphNameYOffset = toggle;
	else if (Element == "DistanceToNextGraph")
	  tgx.DistanceToNextGraph = toggle;
	else if (Element == "XaxisMin")
	  tgx.XaxisMin = toggle;
	else if (Element == "XaxisMax")
	  tgx.XaxisMax = toggle;
	else if (Element == "AxisLineWidth")
	  tgx.AxisLineWidth = toggle;
	else if (Element == "GridLineWidth")
	  tgx.GridLineWidth = toggle;
	else if (Element == "TicFont")
	  tgx.TicFont = toggle;
	else if (Element == "AxisLabelFont")
	  tgx.AxisLabelFont = toggle;
	else if (Element == "GraphNameFont")
	  tgx.GraphNameFont = toggle;
	else if (Element == "TruncateFont")
	  tgx.TruncateFont = toggle;
	else if (Element == "XAxisLabel")
	  tgx.XAxisLabel = toggle;
}
//---------------------------------------------------------------------------

void XAXIS::EvaluateXML(UnicodeString& ustr, TGXXML& tgx, TList* Fonts)
{
  if (tgx.AutoTic)
	AutoTic = (bool)ustr.ToInt();
  else if (tgx.AutoScaleFactor)
	AutoScaleFactor = (bool)ustr.ToInt();
  else if (tgx.AutoMin)
	AutoMin = (bool)ustr.ToInt();
  else if (tgx.AutoMax)
	AutoMax = (bool)ustr.ToInt();
  else if (tgx.LabelOriginTic)
	LabelOriginTic = (bool)ustr.ToInt();
  else if (tgx.Truncate)
	Truncate = (bool)ustr.ToInt();
  else if (tgx.PrintTruncatedValues)
	PrintTruncatedValues = (bool)ustr.ToInt();
  else if (tgx.ScaleTruncatedValues)
	ScaleTruncatedValues = (bool)ustr.ToInt();
  else if (tgx.TruncateWhere) {
	if (ustr == "END_OF_GRAPH")
	   TruncateWhere = END_OF_GRAPH;
	else if (ustr == "END_OF_AXIS")
	   TruncateWhere = END_OF_AXIS;
	}
  else if (tgx.TruncateDecPts)
	TruncateDecPts = (short)ustr.ToInt();
  else if (tgx.PlotGraphName)
	PlotGraphName = (bool)ustr.ToInt();
  else if (tgx.TicDecPts)
	TicDecPts = (short)ustr.ToInt();
  else if (tgx.GridLines) {
	if (ustr == "NOGRIDLINES")
	  GridLines = NOGRIDLINES;
	else if (ustr == "ONMINORTICS")
	  GridLines = ONMINORTICS;
	else if (ustr == "ONMAJORTICS")
	  GridLines = ONMAJORTICS;
	}
  else if (tgx.Color) {
	UnicodeString Hex = "0x" + ustr;
	Color = (TColor)Hex.ToInt();
	}
  else if (tgx.GraphWidth)
	GraphWidth = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.ScaleFactor)
	ScaleFactor = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.MinorTics)
	MinorTics = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.MajorTics)
	MajorTics = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.LabeledTics)
	LabeledTics = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.TicLabelDivideBy)
	TicLabelDivideBy = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.LabelToTicDistance)
	LabelToTicDistance = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.MajorTicLength)
	MajorTicLength = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.MinorTicLength)
	MinorTicLength = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.TopTicLength)
	TopTicLength = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.GraphNameAngle)
	GraphNameAngle = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.GraphNameXOffset)
	GraphNameXOffset = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.GraphNameYOffset)
	GraphNameYOffset = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.DistanceToNextGraph)
	DistanceToNextGraph = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.XaxisMin)
	XaxisMin = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.XaxisMax)
	XaxisMax = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.AxisLineWidth)
	AxisLineWidth = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.GridLineWidth)
	GridLineWidth = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.TicFont)
	TicFont = *(MYFONT*)Fonts->Items[ustr.ToInt()];
  else if (tgx.AxisLabelFont)
	AxisLabelFont = *(MYFONT*)Fonts->Items[ustr.ToInt()];
  else if (tgx.GraphNameFont)
	GraphNameFont = *(MYFONT*)Fonts->Items[ustr.ToInt()];
  else if (tgx.TruncateFont)
	TruncFont = *(MYFONT*)Fonts->Items[ustr.ToInt()];
  else if (tgx.XAxisLabel)
	AxisLabel = ustr;
}
//---------------------------------------------------------------------------

RARESPECIES::RARESPECIES()
{
  Symbol = RAREPLUS;
  Size = 0.075;
  LineWidth = 0.25;
}
//---------------------------------------------------------------------------

void RARESPECIES::XMLOUT(WriteXML* xmlout)
{
  UnicodeString ustr;
  xmlout->BeginTag("RareSpecies");
  switch (Symbol) {
	case RAREPLUS:   ustr = "PLUS";   break;
	case RARECIRCLE: ustr = "CIRCLE"; break;
	}
  xmlout->Element("Symbol", ustr);
  xmlout->Element("Size", Size);
  xmlout->Element("LineWidth", LineWidth);
  xmlout->EndTag("RareSpecies");
}
//---------------------------------------------------------------------------

void RARESPECIES::ToggleSAXElement(UnicodeString& Element, TGXXML& tgx, bool toggle)
{
   if (Element == "Symbol")
	 tgx.Symbol = toggle;
   else if (Element == "Size")
	 tgx.Size = toggle;
   else if (Element == "LineWidth")
	 tgx.LineWidth = toggle;
}
//---------------------------------------------------------------------------

void RARESPECIES::EvaluateXML(UnicodeString& ustr, TGXXML& tgx)
{
  if (tgx.Symbol) {
	if (ustr == "PLUS")
	  Symbol = RAREPLUS;
	else if (ustr == "CIRCLE")
	  Symbol = RARECIRCLE;
	}
  else if (tgx.Size)
	Size = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.LineWidth)
	LineWidth = IntlStrToDouble::GetDouble(ustr);
}
//---------------------------------------------------------------------------

FRAME::FRAME()
{
   Plot = false;
   Bottom = 0.0;
   Top = 0.0;
   Left = 0.0;
   Right = 0.0;
   LineWidth = 0.25;
   Color = clBlack;
   FrameMargin = 0.1;
}
//---------------------------------------------------------------------------

void FRAME::XMLOUT(WriteXML* xmlout)
{
   UnicodeString ustr;
   xmlout->BeginTag("Frame");
   xmlout->Element("Plot", Plot);
   xmlout->Element("Top", Top);
   xmlout->Element("Bottom", Bottom);
   xmlout->Element("Left", Left);
   xmlout->Element("Right", Right);
   xmlout->Element("LineWidth", LineWidth);
   xmlout->Element("Color", ustr.sprintf(L"%08x", Color));
   xmlout->Element("FrameMargin", FrameMargin);
   xmlout->EndTag("Frame");
}
//---------------------------------------------------------------------------

void FRAME::ToggleSAXElement(UnicodeString& Element, TGXXML& tgx, bool toggle)
{
   if (Element == "Plot")
	 tgx.Plot = toggle;
   else if (Element == "Top")
	 tgx.Top = toggle;
   else if (Element == "Bottom")
	 tgx.Bottom = toggle;
   else if (Element == "Left")
	 tgx.Left = toggle;
   else if (Element == "Right")
	 tgx.Right = toggle;
   else if (Element == "LineWidth")
	 tgx.LineWidth = toggle;
   else if (Element == "Color")
	 tgx.Color = toggle;
   else if (Element == "FrameMargin")
	 tgx.FrameMargin = toggle;
}
//---------------------------------------------------------------------------

void FRAME::EvaluateXML(UnicodeString& ustr, TGXXML& tgx)
{
  if (tgx.Plot)
	Plot = (bool)ustr.ToInt();
  else if (tgx.Top)
	Top = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.Bottom)
	Bottom = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.Left)
	Left = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.Right)
	Right = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.LineWidth)
	LineWidth = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.Color) {
	UnicodeString Hex = "0x" + ustr;
	Color = (TColor)Hex.ToInt();
	}
  else if (tgx.FrameMargin)
	FrameMargin = IntlStrToDouble::GetDouble(ustr);
}
//---------------------------------------------------------------------------

GROUP_ATTRIBUTES::GROUP_ATTRIBUTES()
{
  Position = INLINE;
  Color =  clBlack;
  LineWidth = 0.25;
  Font.Height = 0.25;
}
//---------------------------------------------------------------------------

void GROUP_ATTRIBUTES::BasicXMLOUT(WriteXML* xmlout, TList* Fonts)
{
  UnicodeString ustr;

  switch (Position) {
	case INLINE:    ustr = "INLINE";    break;
	case ABOVELINE: ustr = "ABOVELINE"; break;
	}
  xmlout->Element("GroupNamePosition", ustr);
  xmlout->Element("Color", ustr.sprintf(L"%08x", Color));
  xmlout->Element("LineWidth", LineWidth);
  xmlout->Element("GroupFont", GetFontNumber(Fonts, Font));
}
//---------------------------------------------------------------------------

void GROUP_ATTRIBUTES::XMLOUT(WriteXML* xmlout, TList* Fonts)
{
  xmlout->BeginTag("GroupAttr");
  BasicXMLOUT(xmlout, Fonts);
  xmlout->EndTag("GroupAttr");
}
//---------------------------------------------------------------------------

void GROUP_ATTRIBUTES::BasicToggleSAXElement(UnicodeString& Element, TGXXML& tgx, bool toggle)
{
   if (Element == "GroupNamePosition")
	 tgx.GroupNamePosition = toggle;
   else if (Element == "Color")
	 tgx.Color = toggle;
   else if (Element == "LineWidth")
	 tgx.LineWidth = toggle;
   else if (Element == "GroupFont")
	 tgx.GroupFont = toggle;
}
//---------------------------------------------------------------------------

void GROUP_ATTRIBUTES::ToggleSAXElement(UnicodeString& Element, TGXXML& tgx, bool toggle)
{
   BasicToggleSAXElement(Element, tgx, toggle);
}
//---------------------------------------------------------------------------

void GROUP_ATTRIBUTES::BasicEvaluateXML(UnicodeString& ustr, TGXXML& tgx, TList* Fonts)
{
  if (tgx.GroupNamePosition) {
	if (ustr == "INLINE")
	  Position = INLINE;
	else if (ustr == "ABOVELINE")
	  Position = ABOVELINE;
	}
  else if (tgx.Color) {
	UnicodeString Hex = "0x" + ustr;
	Color = (TColor)Hex.ToInt();
	}
  else if (tgx.LineWidth)
	LineWidth = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.GroupFont)
	Font = *(MYFONT*)Fonts->Items[ustr.ToInt()];
}
//---------------------------------------------------------------------------

void GROUP_ATTRIBUTES::EvaluateXML(UnicodeString& ustr, TGXXML& tgx, TList* Fonts)
{
  BasicEvaluateXML(ustr, tgx, Fonts);
}
//---------------------------------------------------------------------------

void GROUP_ATTRIBUTES::operator = (const GROUP_ATTRIBUTES& copy)
{
   if (this == &copy) return;
   Position = copy.Position;
   Color = copy.Color;
   LineWidth = copy.LineWidth;
   Font = copy.Font;
}
//---------------------------------------------------------------------------

void GROUPS::XMLOUT(WriteXML* xmlout, TList* Fonts)
{
  xmlout->BeginTag("Group");
  BasicXMLOUT(xmlout, Fonts);
  xmlout->CDATA("GroupCode1", code1);
  xmlout->CDATA("GroupCode2", code2);
  xmlout->CDATA("GroupName", name);
  xmlout->EndTag("Group");
}
//---------------------------------------------------------------------------

void GROUPS::ToggleSAXElement(UnicodeString& Element, TGXXML& tgx, bool toggle)
{
   if (Element == "GroupCode1")
	 tgx.GroupCode1 = toggle;
   else if (Element == "GroupCode2")
	 tgx.GroupCode2 = toggle;
   else if (Element == "GroupName")
	 tgx.GroupName = toggle;
   else
	 BasicToggleSAXElement(Element, tgx, toggle);
}
//---------------------------------------------------------------------------

void GROUPS::EvaluateXML(UnicodeString& ustr, TGXXML& tgx, TList* Fonts)
{
  if (tgx.GroupCode1)
	code1 = ustr;
  else if (tgx.GroupCode2)
	code2 = ustr;
  else if (tgx.GroupName)
	name = ustr;
  else
	BasicEvaluateXML(ustr, tgx, Fonts);
}
//---------------------------------------------------------------------------

void GROUPS::operator = (const GROUPS& copy)
{
   if (this == &copy) return;
   code1 = copy.code1;
   code2 = copy.code2;
   name = copy.name;
   Position = copy.Position;
   Color = copy.Color;
   LineWidth = copy.LineWidth;
   Font = copy.Font;
}
//---------------------------------------------------------------------------

void GROUPS::operator = (const GROUP_ATTRIBUTES& copy)
{
   if (this == &copy) return;
   Position = copy.Position;
   Color = copy.Color;
   LineWidth = copy.LineWidth;
   Font = copy.Font;
}
//---------------------------------------------------------------------------

ZONE_ATTRIBUTES::ZONE_ATTRIBUTES()
{
  ThruLabelCol = true;
  ZoneStyle = LINEZONE;
  LineStyle = SOLID_LINE;
  Pattern = 2;
  Border = false;
  Priority = ZONETOBACK;
  ZoneColor = clBlack;
  BorderColor = clBlack;
  ZoneWidth = 0.1;
  LineWidth = 0.25;
  user.dash = 0;
  user.space = 0;
}
//---------------------------------------------------------------------------

void ZONE_ATTRIBUTES::BasicXMLOUT(WriteXML* xmlout)
{
  UnicodeString ustr;

  switch (ZoneStyle) {
	case LINEZONE:    ustr = "LINE";    break;
	case PATTERNZONE: ustr = "PATTERN"; break;
	}
  xmlout->Element("ZoneStyle", ustr);
  switch (LineStyle) {
	case DOTTED_LINE:       ustr = "DOTTED_LINE";       break;
	case SOLID_LINE:        ustr = "SOLID_LINE";        break;
	case USER_DEFINED_LINE: ustr = "USER_DEFINED_LINE"; break;
	case LONG_DASHED_LINE:  ustr = "LONG_DASHED_LINE";  break;
	case SHORT_DASHED_LINE: ustr = "SHORT_DASHED_LINE"; break;
	}
  xmlout->Element("LineStyle", ustr);
  xmlout->Element("Pattern", Pattern);
  xmlout->Element("LineWidth", LineWidth);
  xmlout->Element("ZoneWidth", ZoneWidth);
  xmlout->Element("UserDefinedDash", user.dash);
  xmlout->Element("UserDefinedSpace", user.space);
  xmlout->Element("Border", Border);
  switch (Priority) {
	case ZONETOBACK:  ustr = "ZONETOBACK";  break;
	case ZONETOFRONT: ustr = "ZONETOFRONT"; break;
	}
  xmlout->Element("Priority", ustr);
  xmlout->Element("ThruLabelCol", ThruLabelCol);
  xmlout->Element("ZoneColor", ustr.sprintf(L"%08x", ZoneColor));
  xmlout->Element("BorderColor", ustr.sprintf(L"%08x", BorderColor));
}
//---------------------------------------------------------------------------

void ZONE_ATTRIBUTES::XMLOUT(WriteXML* xmlout)
{
   xmlout->BeginTag("ZoneAttr");
   BasicXMLOUT(xmlout);
   xmlout->EndTag("ZoneAttr");
}
//---------------------------------------------------------------------------

void ZONE_ATTRIBUTES::BasicToggleSAXElement(UnicodeString& Element, TGXXML& tgx, bool toggle)
{
   if (Element == "ZoneStyle")
	 tgx.ZoneStyle = toggle;
   else if (Element == "LineStyle")
	 tgx.LineStyle = toggle;
   else if (Element == "Pattern")
	 tgx.Pattern = toggle;
   else if (Element == "LineWidth")
	 tgx.LineWidth = toggle;
   else if (Element == "ZoneWidth")
	 tgx.ZoneWidth = toggle;
   else if (Element == "UserDefinedDash")
	 tgx.UserDefinedDash = toggle;
   else if (Element == "UserDefinedSpace")
	 tgx.UserDefinedSpace = toggle;
   else if (Element == "Border")
	 tgx.Border = toggle;
   else if (Element == "Priority")
	 tgx.Priority = toggle;
   else if (Element == "ThruLabelCol")
	 tgx.ThruLabelCol = toggle;
   else if (Element == "ZoneColor")
	 tgx.ZoneColor = toggle;
   else if (Element == "BorderColor")
	 tgx.BorderColor = toggle;
}
//---------------------------------------------------------------------------

void ZONE_ATTRIBUTES::ToggleSAXElement(UnicodeString& Element, TGXXML& tgx, bool toggle)
{
   BasicToggleSAXElement(Element, tgx, toggle);
}
//---------------------------------------------------------------------------

void ZONE_ATTRIBUTES::BasicEvaluateXML(UnicodeString& ustr, TGXXML& tgx)
{
  if (tgx.ZoneStyle) {
	if (ustr == "LINE")
	  ZoneStyle = LINEZONE;
	else if (ustr == "PATTERN")
	  ZoneStyle = PATTERNZONE;
	}
  else if (tgx.LineStyle) {
	if (ustr == "DOTTED_LINE")
	  LineStyle = DOTTED_LINE;
	else if (ustr == "SOLID_LINE")
	  LineStyle = SOLID_LINE;
	else if (ustr == "USER_DEFINED_LINE")
	  LineStyle = USER_DEFINED_LINE;
	else if (ustr == "LONG_DASHED_LINE")
	  LineStyle = LONG_DASHED_LINE;
	else if (ustr == "SHORT_DASHED_LINE")
	  LineStyle = SHORT_DASHED_LINE;
	}
  else if (tgx.Pattern)
	Pattern = (short)ustr.ToInt();
  else if (tgx.LineWidth)
	LineWidth = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.ZoneWidth)
	ZoneWidth = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.UserDefinedDash)
	user.dash = ustr.ToInt();
  else if (tgx.UserDefinedSpace)
	user.space = ustr.ToInt();
  else if (tgx.Border)
	Border = (bool)ustr.ToInt();
  else if (tgx.Priority) {
	if (ustr == "ZONETOBACK")
	  Priority = ZONETOBACK;
	else if (ustr == "ZONETOFRONT")
	  Priority = ZONETOFRONT;
	}
  else if (tgx.ThruLabelCol)
	ThruLabelCol = (bool)ustr.ToInt();
  else if (tgx.ZoneColor) {
	UnicodeString Hex = "0x" + ustr;
	ZoneColor = (TColor)Hex.ToInt();
	}
  else if (tgx.BorderColor) {
	UnicodeString Hex = "0x" + ustr;
	BorderColor = (TColor)Hex.ToInt();
	}
}
//---------------------------------------------------------------------------

void ZONE_ATTRIBUTES::EvaluateXML(UnicodeString& ustr, TGXXML& tgx)
{
  BasicEvaluateXML(ustr, tgx);
}
//---------------------------------------------------------------------------

void ZONE::XMLOUT(WriteXML* xmlout)
{
  xmlout->BeginTag("Zone");
  BasicXMLOUT(xmlout);
  xmlout->Element("Depth", depth);
  xmlout->EndTag("Zone");
}
//---------------------------------------------------------------------------

void ZONE::ToggleSAXElement(UnicodeString& Element, TGXXML& tgx, bool toggle)
{
  if (Element == "Depth")
	tgx.Depth = toggle;
  else
	BasicToggleSAXElement(Element, tgx, toggle);
}
//---------------------------------------------------------------------------

void ZONE::EvaluateXML(UnicodeString& ustr, TGXXML& tgx)
{
  if (tgx.Depth)
	depth = IntlStrToDouble::GetDouble(ustr);
  else
	BasicEvaluateXML(ustr, tgx);
}
//---------------------------------------------------------------------------

TEXT_BLOCK::TEXT_BLOCK()
{
  AutoX = true;
  AutoY = true;
  x = -1000000.0;
  y = -1000000.0;
}
//---------------------------------------------------------------------------

void TEXT_BLOCK::XMLOUT(WriteXML* xmlout, UnicodeString& Title, TList* Fonts)
{
  xmlout->BeginTag(Title);
  xmlout->Element("AutoX", AutoX);
  xmlout->Element("AutoY", AutoY);
  xmlout->Element("X", x);
  xmlout->Element("Y", y);
  xmlout->Element("TextFont", GetFontNumber(Fonts, Font));
  xmlout->CDATA("Text", Text);
  xmlout->EndTag(Title);
}
//---------------------------------------------------------------------------

void TEXT_BLOCK::ToggleSAXElement(UnicodeString& Element, TGXXML& tgx, bool toggle)
{
   if (Element == "AutoX")
	 tgx.AutoX = toggle;
   else if (Element == "AutoY")
	 tgx.AutoY = toggle;
   else if (Element == "X")
	 tgx.X = toggle;
   else if (Element == "Y")
	 tgx.Y = toggle;
   else if (Element == "TextFont")
	 tgx.TextFont = toggle;
   else if (Element == "Text")
	 tgx.Text = toggle;
}
//---------------------------------------------------------------------------

void TEXT_BLOCK::EvaluateXML(UnicodeString& ustr, TGXXML& tgx, TList* Fonts)
{
  if (tgx.AutoX)
	AutoX = (bool)ustr.ToInt();
  else if (tgx.AutoY)
	AutoY = (bool)ustr.ToInt();
  else if (tgx.X)
	x = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.Y)
	y = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.TextFont)
	Font = *(MYFONT*)Fonts->Items[ustr.ToInt()];
  else if (tgx.Text)
	Text = ustr;
}
//---------------------------------------------------------------------------

void TEXTLINE::XMLOUT(WriteXML* xmlout, TList* Fonts)
{
  xmlout->BeginTag("RandomText");
  xmlout->Element("X", x);
  xmlout->Element("Y", y);
  xmlout->Element("Angle", angle);
  xmlout->Element("TextFont", GetFontNumber(Fonts, Font));
  xmlout->CDATA("Text", Text);
  xmlout->EndTag("RandomText");
}
//---------------------------------------------------------------------------

void TEXTLINE::ToggleSAXElement(UnicodeString& Element, TGXXML& tgx, bool toggle)
{
   if (Element == "X")
	 tgx.X = toggle;
   else if (Element == "Y")
	 tgx.Y = toggle;
   else if (Element == "Angle")
	 tgx.Angle = toggle;
   else if (Element == "TextFont")
	 tgx.TextFont = toggle;
   else if (Element == "Text")
	 tgx.Text = toggle;
}
//---------------------------------------------------------------------------

void TEXTLINE::EvaluateXML(UnicodeString& ustr, TGXXML& tgx, TList* Fonts)
{
   if (tgx.X)
	 x = IntlStrToDouble::GetDouble(ustr);
   else if (tgx.Y)
	 y = IntlStrToDouble::GetDouble(ustr);
   else if (tgx.Angle)
	 angle = IntlStrToDouble::GetDouble(ustr);
   else if (tgx.TextFont)
	 Font = *(MYFONT*)Fonts->Items[ustr.ToInt()];
   else if (tgx.Text)
     Text = ustr;
}
//---------------------------------------------------------------------------

DGROPTIONS::DGROPTIONS()
{
  Loaded = false;
  On = false;
  AutoTic = true;
  AutoTicDecPts = true;
  ScaleType = 2;
  TicDecPts = 0;
  AxisColor =  clBlack;
  DendColor =  clBlack;
  AxisLineWidth = 0.25;
  DendLineWidth = 0.25;
  DendWidth = 4.0;
  MajorTics = 0.0;
  MinorTics = 0.0;
  TopTicLength  = 0.05;
  MajorTicLength = 0.1;
  MinorTicLength = 0.06;
  LabelToTicDistance = 0.05;
  GraphNameYOffset = -0.05;
  DendTitle =  "CONISS";
  DendAxisLabels[0] = "Increase in sum of squares";
  DendAxisLabels[1] = "Total sum of squares";
  DendAxisLabels[2] = "Within-cluster sum of squares";
  DendAxisLabels[3] = "Mean within-cluster sum of squares";
  AxisLabelFont.Height = 0.25;
  DendTitleFont.Height = 0.25;
  TicFont.Height = 0.20;
}
//---------------------------------------------------------------------------

void DGROPTIONS::XMLOUT(WriteXML* xmlout, TList* Fonts)
{
  UnicodeString ustr;
  xmlout->BeginTag("DendAttr");
  xmlout->Element("Loaded", Loaded);
  xmlout->Element("On", On);
  xmlout->Element("AutoTic", AutoTic);
  xmlout->Element("AutoTicDecPts", AutoTicDecPts);
  xmlout->Element("ScaleType", ScaleType);
  xmlout->Element("TicDecPts", TicDecPts);
  xmlout->Element("AxisColor", ustr.sprintf(L"%08x", AxisColor));
  xmlout->Element("DendColor", ustr.sprintf(L"%08x", DendColor));
  xmlout->Element("AxisLineWidth", AxisLineWidth);
  xmlout->Element("DendLineWidth", DendLineWidth);
  xmlout->Element("DendWidth", DendWidth);
  xmlout->Element("MajorTics", MajorTics);
  xmlout->Element("MinorTics", MinorTics);
  xmlout->Element("TopTicLength", TopTicLength);
  xmlout->Element("MajorTicLength", MajorTicLength);
  xmlout->Element("MinorTicLength", MinorTicLength);
  xmlout->Element("LabelToTicDistance", LabelToTicDistance);
  xmlout->Element("GraphNameYOffset", GraphNameYOffset);
  xmlout->Element("DendTitleFont", GetFontNumber(Fonts, DendTitleFont));
  xmlout->Element("AxisLabelFont", GetFontNumber(Fonts, AxisLabelFont));
  xmlout->Element("TicFont", GetFontNumber(Fonts, TicFont));
  xmlout->CDATA("DendTitle", DendTitle);
  xmlout->CDATA("DendAxisLabel1", DendAxisLabels[0]);
  xmlout->CDATA("DendAxisLabel2", DendAxisLabels[1]);
  xmlout->CDATA("DendAxisLabel3", DendAxisLabels[2]);
  xmlout->CDATA("DendAxisLabel4", DendAxisLabels[3]);
  xmlout->EndTag("DendAttr");
}
//---------------------------------------------------------------------------

void DGROPTIONS::ToggleSAXElement(UnicodeString& Element, TGXXML& tgx, bool toggle)
{
   if (Element == "Loaded")
	 tgx.Loaded = toggle;
   else if (Element == "On")
	 tgx.On = toggle;
   else if (Element == "AutoTic")
	 tgx.AutoTic = toggle;
   else if (Element == "AutoTicDecPts")
	 tgx.AutoTicDecPts = toggle;
   else if (Element == "ScaleType")
	 tgx.ScaleType = toggle;
   else if (Element == "TicDecPts")
	 tgx.TicDecPts = toggle;
   else if (Element == "AxisColor")
	 tgx.AxisColor = toggle;
   else if (Element == "DendColor")
	 tgx.DendColor = toggle;
   else if (Element == "AxisLineWidth")
	 tgx.AxisLineWidth = toggle;
   else if (Element == "DendLineWidth")
	 tgx.DendLineWidth = toggle;
   else if (Element == "DendWidth")
	 tgx.DendWidth = toggle;
   else if (Element == "MajorTics")
	 tgx.MajorTics = toggle;
   else if (Element == "MinorTics")
	 tgx.MinorTics = toggle;
   else if (Element == "TopTicLength")
	 tgx.TopTicLength = toggle;
   else if (Element == "MajorTicLength")
	 tgx.MajorTicLength = toggle;
   else if (Element == "MinorTicLength")
	 tgx.MinorTicLength = toggle;
   else if (Element == "LabelToTicDistance")
	 tgx.LabelToTicDistance = toggle;
   else if (Element == "GraphNameYOffset")
	 tgx.GraphNameYOffset = toggle;
   else if (Element == "DendTitleFont")
	 tgx.DendTitleFont = toggle;
   else if (Element == "AxisLabelFont")
	 tgx.AxisLabelFont = toggle;
   else if (Element == "TicFont")
	 tgx.TicFont = toggle;
   else if (Element == "DendTitle")
	 tgx.DendTitle = toggle;
   else if (Element == "DendAxisLabel1")
	 tgx.DendAxisLabel1 = toggle;
   else if (Element == "DendAxisLabel2")
	 tgx.DendAxisLabel2 = toggle;
   else if (Element == "DendAxisLabel3")
	 tgx.DendAxisLabel3 = toggle;
   else if (Element == "DendAxisLabel4")
	 tgx.DendAxisLabel4 = toggle;
}
//---------------------------------------------------------------------------

void DGROPTIONS::EvaluateXML(UnicodeString& ustr, TGXXML& tgx, TList* Fonts)
{
  if (tgx.Loaded)
	Loaded = (bool)ustr.ToInt();
  else if (tgx.On)
	On = (bool)ustr.ToInt();
  else if (tgx.AutoTic)
	AutoTic = (bool)ustr.ToInt();
  else if (tgx.AutoTicDecPts)
	AutoTicDecPts = (bool)ustr.ToInt();
  else if (tgx.ScaleType)
	ScaleType = (short)ustr.ToInt();
  else if (tgx.TicDecPts)
	TicDecPts = (short)ustr.ToInt();
  else if (tgx.AxisColor) {
	UnicodeString Hex = "0x" + ustr;
	AxisColor = (TColor)Hex.ToInt();
	}
  else if (tgx.DendColor) {
	UnicodeString Hex = "0x" + ustr;
	DendColor = (TColor)Hex.ToInt();
	}
  else if (tgx.AxisLineWidth)
	AxisLineWidth = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.DendLineWidth)
	DendLineWidth = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.DendWidth)
	DendWidth = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.MajorTics)
	MajorTics = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.MinorTics)
	MinorTics = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.TopTicLength)
	TopTicLength = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.MajorTicLength)
	MajorTicLength = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.MinorTicLength)
	MinorTicLength = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.LabelToTicDistance)
	LabelToTicDistance = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.GraphNameYOffset)
	GraphNameYOffset = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.DendTitleFont)
	DendTitleFont = *(MYFONT*)Fonts->Items[ustr.ToInt()];
  else if (tgx.AxisLabelFont)
	AxisLabelFont = *(MYFONT*)Fonts->Items[ustr.ToInt()];
  else if (tgx.TicFont)
	TicFont = *(MYFONT*)Fonts->Items[ustr.ToInt()];
  else if (tgx.DendTitle)
	DendTitle = ustr;
  else if (tgx.DendAxisLabel1)
	DendAxisLabels[0] = ustr;
  else if (tgx.DendAxisLabel2)
	DendAxisLabels[1] = ustr;
  else if (tgx.DendAxisLabel3)
	DendAxisLabels[2] = ustr;
  else if (tgx.DendAxisLabel4)
	DendAxisLabels[3] = ustr;
}
//---------------------------------------------------------------------------

void DENDROGRAM::XMLOUT(WriteXML* xmlout)
{
  xmlout->BeginTag("Cluster");
  xmlout->Element("Cluster1", clus1);
  xmlout->Element("Cluster2", clus2);
  xmlout->Element("ISS", inc);
  xmlout->Element("TSS", tot);
  xmlout->Element("WSS", wcd);
  xmlout->Element("MSS", mwcd);
  xmlout->EndTag("Cluster");
}
//---------------------------------------------------------------------------

void DENDROGRAM::ToggleSAXElement(UnicodeString& Element, TGXXML& tgx, bool toggle)
{
   if (Element == "Cluster1")
	 tgx.Cluster1 = toggle;
   else if (Element == "Cluster2")
	 tgx.Cluster2 = toggle;
   else if (Element == "ISS")
	 tgx.ISS = toggle;
   else if (Element == "TSS")
	 tgx.TSS = toggle;
   else if (Element == "WSS")
	 tgx.WSS = toggle;
   else if (Element == "MSS")
	 tgx.MSS = toggle;
}
//---------------------------------------------------------------------------

void DENDROGRAM::ToggleSAXElement(UnicodeString& Element, DGXXML& dgx, bool toggle)
{
   if (Element == "Cluster1")
	 dgx.Cluster1 = toggle;
   else if (Element == "Cluster2")
	 dgx.Cluster2 = toggle;
   else if (Element == "ISS")
	 dgx.ISS = toggle;
   else if (Element == "TSS")
	 dgx.TSS = toggle;
   else if (Element == "WSS")
	 dgx.WSS = toggle;
   else if (Element == "MSS")
	 dgx.MSS = toggle;
}
//---------------------------------------------------------------------------

void DENDROGRAM::EvaluateXML(UnicodeString& ustr, TGXXML& tgx)
{
  if (tgx.Cluster1)
	clus1 = (short)ustr.ToInt();
  else if (tgx.Cluster2)
	clus2 = (short)ustr.ToInt();
  else if (tgx.ISS)
	inc = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.TSS)
	tot = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.WSS)
	wcd = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.MSS)
	mwcd = IntlStrToDouble::GetDouble(ustr);
}
//---------------------------------------------------------------------------

//void DENDROGRAM::EvaluateXML(UnicodeString& ustr, DGXXML& dgx)
void DENDROGRAM::EvaluateXML(DGXXML& dgx)
{
  if (dgx.Cluster1)
	clus1 = (short)dgx.XText.ToInt();
  else if (dgx.Cluster2)
	clus2 = (short)dgx.XText.ToInt();
  else if (dgx.ISS)
	inc = IntlStrToDouble::GetDouble(dgx.XText);
  else if (dgx.TSS)
	tot = IntlStrToDouble::GetDouble(dgx.XText);
  else if (dgx.WSS)
	wcd = IntlStrToDouble::GetDouble(dgx.XText);
  else if (dgx.MSS)
	mwcd = IntlStrToDouble::GetDouble(dgx.XText);
}
//---------------------------------------------------------------------------

ZONEOPTIONS::ZONEOPTIONS()
{
  Center = true;
  ZoneTitleAngle = 0.0;
  ZoneTitleXOffset = 0.2;
  ZoneTitleYOffset = -0.05;
  ZoneTitle = "Zone";
  ZoneTitleFont.Height = 0.25;
  ZoneFont.Height = 0.25;
}
//---------------------------------------------------------------------------

void ZONEOPTIONS::XMLOUT(WriteXML* xmlout, TList* Fonts)
{
  xmlout->BeginTag("ZoneLabelAttr");
  xmlout->Element("Center", Center);
  xmlout->Element("ZoneTitleAngle", ZoneTitleAngle);
  xmlout->Element("ZoneTitleXOffset", ZoneTitleXOffset);
  xmlout->Element("ZoneTitleYOffset", ZoneTitleYOffset);
  xmlout->Element("ZoneFont", GetFontNumber(Fonts, ZoneFont));
  xmlout->Element("ZoneTitleFont", GetFontNumber(Fonts, ZoneTitleFont));
  xmlout->CDATA("ZoneTitle", ZoneTitle);
  xmlout->EndTag("ZoneLabelAttr");
}
//---------------------------------------------------------------------------

void ZONEOPTIONS::ToggleSAXElement(UnicodeString& Element, TGXXML& tgx, bool toggle)
{
   if (Element == "Center")
	 tgx.Center = toggle;
   else if (Element == "ZoneTitleAngle")
	 tgx.ZoneTitleAngle = toggle;
   else if (Element == "ZoneTitleXOffset")
	 tgx.ZoneTitleXOffset = toggle;
   else if (Element == "ZoneTitleYOffset")
	 tgx.ZoneTitleYOffset = toggle;
   else if (Element == "ZoneFont")
	 tgx.ZoneFont = toggle;
   else if (Element == "ZoneTitleFont")
	 tgx.ZoneTitleFont = toggle;
   else if (Element == "ZoneTitle")
	 tgx.ZoneTitle = toggle;
}
//---------------------------------------------------------------------------

void ZONEOPTIONS::EvaluateXML(UnicodeString& ustr, TGXXML& tgx, TList* Fonts)
{
  if (tgx.Center)
	Center = (bool)ustr.ToInt();
  else if (tgx.ZoneTitleAngle)
	ZoneTitleAngle = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.ZoneTitleXOffset)
	ZoneTitleXOffset = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.ZoneTitleYOffset)
	ZoneTitleYOffset = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.ZoneFont)
	ZoneFont = *(MYFONT*)Fonts->Items[ustr.ToInt()];
  else if (tgx.ZoneTitleFont)
	ZoneTitleFont = *(MYFONT*)Fonts->Items[ustr.ToInt()];
  else if (tgx.ZoneTitle)
	ZoneTitle = ustr;
}
//---------------------------------------------------------------------------

void ZONELABELS::XMLOUT(WriteXML* xmlout)
{
  xmlout->BeginTag("ZoneLabel");
  xmlout->Element("ZoneTop", top);
  xmlout->Element("ZoneBottom", bottom);
  xmlout->CDATA("ZoneName", label);
  xmlout->EndTag("ZoneLabel");
}
//---------------------------------------------------------------------------

void ZONELABELS::ToggleSAXElement(UnicodeString& Element, TGXXML& tgx, bool toggle)
{
   if (Element == "ZoneTop")
	 tgx.ZoneTop = toggle;
   else if (Element == "ZoneBottom")
	 tgx.ZoneBottom = toggle;
   else if (Element == "ZoneName")
	 tgx.ZoneName = toggle;
}
//---------------------------------------------------------------------------

void ZONELABELS::EvaluateXML(UnicodeString& ustr, TGXXML& tgx)
{
  if (tgx.ZoneTop)
	top = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.ZoneBottom)
	bottom = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.ZoneName)
	label = ustr;
}
//---------------------------------------------------------------------------

DATEOPTIONS::DATEOPTIONS()
{
  DatesPosition = LEFT;
  DatesTitlePosition = SIDE;
  Color = clBlack;
  DatesTitleTopYOffset = -0.05;
  X_Title = 0.0;
  Y_Title = 0.0;
  Angle = 90.0;
  DateTitleFont.Height = 0.25;
  DateFont.Height = 0.20;
  DateTitle = "Dates";
}
//---------------------------------------------------------------------------

void DATEOPTIONS::XMLOUT(WriteXML* xmlout, TList* Fonts)
{
  UnicodeString ustr;
  xmlout->BeginTag("DateAttr");
  switch (DatesPosition) {
	case LEFT:  ustr = "LEFT";  break;
	case RIGHT: ustr = "RIGHT"; break;
	}
  xmlout->Element("DatesPosition", ustr);
  switch (DatesTitlePosition) {
	case SIDE:        ustr = "SIDE";        break;
	case TOP:         ustr = "TOP";         break;
	case USERDEFINED: ustr = "USERDEFINED"; break;
	}
  xmlout->Element("DatesTitlePosition", ustr);
  xmlout->Element("Color", ustr.sprintf(L"%08x", Color));
  xmlout->Element("DatesTitleTopYOffset", DatesTitleTopYOffset);
  xmlout->Element("X_Title", X_Title);
  xmlout->Element("Y_Title", Y_Title);
  xmlout->Element("Angle", Angle);
  xmlout->Element("DateFont", GetFontNumber(Fonts, DateFont));
  xmlout->Element("DateTitleFont", GetFontNumber(Fonts, DateTitleFont));
  xmlout->CDATA("DateTitle", DateTitle);
  xmlout->EndTag("DateAttr");
}
//---------------------------------------------------------------------------

void DATEOPTIONS::ToggleSAXElement(UnicodeString& Element, TGXXML& tgx, bool toggle)
{
   if (Element == "DatesPosition")
	 tgx.DatesPosition = toggle;
   else if (Element == "DatesTitlePosition")
	 tgx.DatesTitlePosition = toggle;
   else if (Element == "Color")
	 tgx.Color = toggle;
   else if (Element == "DatesTitleTopYOffset")
	 tgx.DatesTitleTopYOffset = toggle;
   else if (Element == "X_Title")
	 tgx.X_Title = toggle;
   else if (Element == "Y_Title")
	 tgx.Y_Title = toggle;
   else if (Element == "Angle")
	 tgx.Angle = toggle;
   else if (Element == "DateFont")
	 tgx.DateFont = toggle;
   else if (Element == "DateTitleFont")
	 tgx.DateTitleFont = toggle;
   else if (Element == "DateTitle")
	 tgx.DateTitle = toggle;
}
//---------------------------------------------------------------------------

void DATEOPTIONS::EvaluateXML(UnicodeString& ustr, TGXXML& tgx, TList* Fonts)
{
  if (tgx.DatesPosition) {
	if (ustr == "LEFT")
	  DatesPosition = LEFT;
	else if (ustr == "RIGHT")
	  DatesPosition = RIGHT;
	}
  else if (tgx.DatesTitlePosition) {
	if (ustr == "SIDE")
	  DatesTitlePosition = SIDE;
	else if (ustr == "TOP")
	  DatesTitlePosition = TOP;
	else if (ustr == "USERDEFINED")
	  DatesTitlePosition = USERDEFINED;
	}
  else if (tgx.Color) {
	UnicodeString Hex = "0x" + ustr;
	Color = (TColor)Hex.ToInt();
	}
  else if (tgx.DatesTitleTopYOffset)
	DatesTitleTopYOffset = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.X_Title)
	X_Title = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.Y_Title)
	Y_Title = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.Angle)
	Angle = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.DateFont)
	DateFont = *(MYFONT*)Fonts->Items[ustr.ToInt()];
  else if (tgx.DateTitleFont)
	DateTitleFont = *(MYFONT*)Fonts->Items[ustr.ToInt()];
  else if (tgx.DateTitle)
	DateTitle = ustr;
}
//---------------------------------------------------------------------------

void DATES::XMLOUT(WriteXML* xmlout)
{
  xmlout->BeginTag("Date");
  xmlout->Element("DateTop", top);
  xmlout->Element("DateBottom", bot);
  xmlout->Element("DateVerticalOffset", voff);
  xmlout->CDATA("DateLabel", date);
  xmlout->EndTag("Date");
}
//---------------------------------------------------------------------------

void DATES::ToggleSAXElement(UnicodeString& Element, TGXXML& tgx, bool toggle)
{
   if (Element == "DateTop")
	 tgx.DateTop = toggle;
   else if (Element == "DateBottom")
	 tgx.DateBottom = toggle;
   else if (Element == "DateVerticalOffset")
	 tgx.DateVerticalOffset = toggle;
   else if (Element == "DateLabel")
	 tgx.DateLabel = toggle;
}
//---------------------------------------------------------------------------

void DATES::EvaluateXML(UnicodeString& ustr, TGXXML& tgx)
{
  if (tgx.DateTop)
	top = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.DateBottom)
	bot = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.DateVerticalOffset)
	voff = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.DateLabel)
	date = ustr;
}
//---------------------------------------------------------------------------

LITHOPTIONS::LITHOPTIONS()
{
  On = false;
  KeyOn = false;
  AutoTopDepth = true;
  AutoBotDepth = true;
  DefaultColor = clBlack;
  TopDepth = 0.0;
  BotDepth = 0.0;
  Angle = 0.0;
  BoxWidth = 1.2;
  LithLineWidth = 0.25;
  KeyLineWidth = 0.25;
  ColumnLineWidth = 0.25;
  BoundaryLineWidth = 0.25;
  LithTitle = "Lithology";
  LithTitleFont.Height = 0.25;
  KeyFont.Height = 0.25;
}
//---------------------------------------------------------------------------

void LITHOPTIONS::XMLOUT(WriteXML* xmlout, TList* Fonts)
{
  UnicodeString ustr;
  xmlout->BeginTag("LithAttr");
  xmlout->Element("On", On);
  xmlout->Element("KeyOn", KeyOn);
  xmlout->Element("AutoTopDepth", AutoTopDepth);
  xmlout->Element("AutoBotDepth", AutoBotDepth);
  xmlout->Element("DefaultColor", ustr.sprintf(L"%08x", DefaultColor));
  xmlout->Element("TopDepth", TopDepth);
  xmlout->Element("BotDepth", BotDepth);
  xmlout->Element("Angle", Angle);
  xmlout->Element("BoxWidth", BoxWidth);
  xmlout->Element("LithLineWidth", LithLineWidth);
  xmlout->Element("KeyLineWidth", KeyLineWidth);
  xmlout->Element("ColumnLineWidth", ColumnLineWidth);
  xmlout->Element("BoundaryLineWidth", BoundaryLineWidth);
  xmlout->Element("KeyFont", GetFontNumber(Fonts, KeyFont));
  xmlout->Element("LithTitleFont", GetFontNumber(Fonts, LithTitleFont));
  xmlout->CDATA("LithTitle", LithTitle);
  xmlout->EndTag("LithAttr");
}
//---------------------------------------------------------------------------

void LITHOPTIONS::ToggleSAXElement(UnicodeString& Element, TGXXML& tgx, bool toggle)
{
   if (Element == "On")
	 tgx.On = toggle;
   else if (Element == "KeyOn")
	 tgx.KeyOn = toggle;
   else if (Element == "AutoTopDepth")
	 tgx.AutoTopDepth = toggle;
   else if (Element == "AutoBotDepth")
	 tgx.AutoBotDepth = toggle;
   else if (Element == "DefaultColor")
	 tgx.DefaultColor = toggle;
   else if (Element == "Color")   // tgx.Color obsolete
	 tgx.DefaultColor = toggle;
   else if (Element == "TopDepth")
	 tgx.TopDepth = toggle;
   else if (Element == "BotDepth")
	 tgx.BotDepth = toggle;
   else if (Element == "Angle")
	 tgx.Angle = toggle;
   else if (Element == "BoxWidth")
	 tgx.BoxWidth = toggle;
   else if (Element == "LithLineWidth")
	 tgx.LithLineWidth = toggle;
   else if (Element == "KeyLineWidth")
	 tgx.KeyLineWidth = toggle;
   else if (Element == "ColumnLineWidth")
	 tgx.ColumnLineWidth = toggle;
   else if (Element == "BoundaryLineWidth")
	 tgx.BoundaryLineWidth = toggle;
   else if (Element == "KeyFont")
	 tgx.KeyFont = toggle;
   else if (Element == "LithTitleFont")
	 tgx.LithTitleFont = toggle;
   else if (Element == "LithTitle")
	 tgx.LithTitle = toggle;
}
//---------------------------------------------------------------------------

void LITHOPTIONS::EvaluateXML(UnicodeString& ustr, TGXXML& tgx, TList* Fonts)
{
  if (tgx.On)
	On = (bool)ustr.ToInt();
  else if (tgx.KeyOn)
	KeyOn = (bool)ustr.ToInt();
  else if (tgx.AutoTopDepth)
	AutoTopDepth = (bool)ustr.ToInt();
  else if (tgx.AutoBotDepth)
	AutoBotDepth = (bool)ustr.ToInt();
  else if (tgx.DefaultColor) {
	UnicodeString Hex = "0x" + ustr;
	DefaultColor = (TColor)Hex.ToInt();
	}
  else if (tgx.TopDepth)
	TopDepth = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.BotDepth)
	BotDepth = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.Angle)
	Angle = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.BoxWidth)
	BoxWidth = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.LithLineWidth)
	LithLineWidth = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.KeyLineWidth)
	KeyLineWidth = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.ColumnLineWidth)
	ColumnLineWidth = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.BoundaryLineWidth)
	BoundaryLineWidth = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.KeyFont)
	KeyFont = *(MYFONT*)Fonts->Items[ustr.ToInt()];
  else if (tgx.LithTitleFont)
	LithTitleFont = *(MYFONT*)Fonts->Items[ustr.ToInt()];
  else if (tgx.LithTitle)
	LithTitle = ustr;
}
//---------------------------------------------------------------------------

void LITHUNIT::XMLOUT(WriteXML* xmlout)
{
  UnicodeString ustr;
  LITHCOMPONENT *Component;

  xmlout->BeginTag("LithUnit");
  xmlout->Element("Top", Top);
  xmlout->Element("Bot", Bot);
  xmlout->Element("LoBound", LoBound);
  xmlout->Element("LoBoundColor", ustr.sprintf(L"%08x", LoBoundColor));
  for (int i=0; i<Components->Count; i++) {
	Component = (LITHCOMPONENT *)Components->Items[i];
	Component->XMLOUT(xmlout);
	}
  xmlout->EndTag("LithUnit");
}
//---------------------------------------------------------------------------

void LITHUNIT::ToggleSAXElement(UnicodeString& Element, TGXXML& tgx, bool toggle)
{
   if (Element == "Top")
	 tgx.Top = toggle;
   else if (Element == "Bot")
	 tgx.Bot = toggle;
   else if (Element == "LoBound")
	 tgx.LoBound = toggle;
   else if (Element == "LoBoundColor")
	 tgx.LoBoundColor = toggle;
   else if (Element == "Component")
	 tgx.Component = toggle;
}
//---------------------------------------------------------------------------

void LITHUNIT::EvaluateXML(UnicodeString& ustr, TGXXML& tgx)
{
  if (tgx.Top)
	Top = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.Bot)
	Bot = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.LoBound)
	LoBound = (bool)ustr.ToInt();
  else if (tgx.LoBoundColor) {
	UnicodeString Hex = "0x" + ustr;
	LoBoundColor = (TColor)Hex.ToInt();
	}
}
//---------------------------------------------------------------------------

void LITHCOMPONENT::ToggleSAXElement(UnicodeString& Element, TGXXML& tgx, bool toggle)
{
   if (Element == "LithCode")
	 tgx.LithCode = toggle;
   else if (Element == "Humo")
	 tgx.Humo = toggle;
   else if (Element == "XShift")
	 tgx.XShift = toggle;
   else if (Element == "YShift")
	 tgx.YShift = toggle;
   else if (Element == "Color")
	 tgx.Color = toggle;
}
//---------------------------------------------------------------------------

void LITHCOMPONENT::XMLOUT(WriteXML* xmlout)
{
   UnicodeString ustr;
   xmlout->BeginTag("Component");
   xmlout->Element("LithCode", LithCode);
   xmlout->Element("Humo", Humo);
   xmlout->Element("XShift", XShift);
   xmlout->Element("YShift", YShift);
   xmlout->Element("Color", ustr.sprintf(L"%08x", Color));
   xmlout->EndTag("Component");
}
//---------------------------------------------------------------------------

void LITHCOMPONENT::EvaluateXML(UnicodeString& ustr, TGXXML& tgx)
{
   if (tgx.LithCode)
	 LithCode = (short)ustr.ToInt();
   else if (tgx.Humo)
	 Humo = (short)ustr.ToInt();
   else if (tgx.XShift)
	 XShift = IntlStrToDouble::GetDouble(ustr);
   else if (tgx.YShift)
	 YShift = IntlStrToDouble::GetDouble(ustr);
   else if (tgx.Color) {
	 UnicodeString Hex = "0x" + ustr;
	 Color = (TColor)Hex.ToInt();
	 }
}
//---------------------------------------------------------------------------

void LITHKEY::SetLithCode(short lc)
{
   LithCode = lc;
}
//---------------------------------------------------------------------------

void LITHKEY::SetLithCode(UnicodeString& Unit)
{
   if (TroelsSmithCodes) {
     if (Unit.SubString(1,6) == "Bitmap")
        LithCode = (Unit.SubString(7,2)).ToInt();
     else {
        int Pos = Unit.Pos("/");
        if (Pos == 0) {
          LithCode = TroelsSmithCodes->IndexOf(Unit) + 34;
          Humo = 0;
          }
        else {
          LithCode = TroelsSmithCodes->IndexOf(Unit.SubString(1,Pos-1)) + 34;
          Humo = StrToInt(Unit.SubString(Pos+1,1));
          }
        }
     }
}
//---------------------------------------------------------------------------

void LITHKEY::Set_x(UnicodeString str)
{
   if (str == "Auto") {
      x = 0.0;
      AutoX = true;
      }
   else {
     AutoX = false;
     try {
       x = StrToFloat(str);  }
     catch (...) {
       x = 0.0;
       AutoX = true; }
     }
}
//---------------------------------------------------------------------------

void LITHKEY::Set_y(UnicodeString str)
{
   if (str == "Auto") {
      y = 0.0;
      AutoY = true;
      }
   else {
     AutoY = false;
     try {
       y = StrToFloat(str);  }
     catch (...) {
       y = 0.0;
       AutoY = true; }
     }
}
//---------------------------------------------------------------------------

void LITHKEY::SetHumo(short h)
{
   Humo = h;
}
//---------------------------------------------------------------------------

UnicodeString LITHKEY::GetLithUnit(void)
{
   UnicodeString Unit;
   if (TroelsSmithCodes) {
     if (LithCode < 34)
        Unit = "Bitmap" + IntToStr(LithCode);
     else {
        Unit = TroelsSmithCodes->Strings[LithCode-34];
        if (Unit.SubString(1,2) == "Tb" ||
            Unit.SubString(1,2) == "Tl" ||
            Unit.SubString(1,2) == "Th" ||
            Unit.SubString(1,2) == "Ld" )
          Unit += ("/" + IntToStr(Humo));
        }
     }
   return Unit;  
}
//---------------------------------------------------------------------------

void LITHKEY::XMLOUT(WriteXML* xmlout)
{
  xmlout->BeginTag("LithKey");
  xmlout->Element("Plot", Plot);
  xmlout->Element("AutoX", AutoX);
  xmlout->Element("AutoY", AutoY);
  xmlout->Element("LithCode", LithCode);
  xmlout->Element("Humo", Humo);
  xmlout->Element("X", x);
  xmlout->Element("Y", y);
  xmlout->CDATA("LithLabel", LithLabel);
  xmlout->EndTag("LithKey");
}
//---------------------------------------------------------------------------

void LITHKEY::ToggleSAXElement(UnicodeString& Element, TGXXML& tgx, bool toggle)
{
   if (Element == "Plot")
	 tgx.Plot = toggle;
   else if (Element == "AutoX")
	 tgx.AutoX = toggle;
   else if (Element == "AutoY")
	 tgx.AutoY = toggle;
   else if (Element == "LithCode")
	 tgx.LithCode = toggle;
   else if (Element == "Humo")
	 tgx.Humo = toggle;
   else if (Element == "X")
	 tgx.X = toggle;
   else if (Element == "Y")
	 tgx.Y = toggle;
   else if (Element == "LithLabel")
	 tgx.LithLabel = toggle;
}
//---------------------------------------------------------------------------

void LITHKEY::EvaluateXML(UnicodeString& ustr, TGXXML& tgx)
{
  if (tgx.Plot)
	Plot = (bool)ustr.ToInt();
  else if (tgx.AutoX)
	AutoX = (bool)ustr.ToInt();
  else if (tgx.AutoY)
	AutoY = (bool)ustr.ToInt();
  else if (tgx.LithCode)
	LithCode = (short)ustr.ToInt();
  else if (tgx.Humo)
	Humo = (short)ustr.ToInt();
  else if (tgx.X)
	x = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.Y)
	y = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.LithLabel)
    LithLabel = ustr;
}
//---------------------------------------------------------------------------

GRAPH::~GRAPH()
{
  delete graph;
  delete xax;
  delete[] data;
}
//---------------------------------------------------------------------------

void GRAPH::XMLOUT(WriteXML* xmlout, int gs, int xs)
{
  UnicodeString ustr;

  xmlout->BeginTag("Graph", "GS", gs, "XS", xs);
  xmlout->CDATA("VarName", name);
  xmlout->CDATA("VarCode", code);
  xmlout->CDATA("GroupCode", sum);
  switch (status) {
	case NORMAL:   ustr = "NORMAL";   break;
	case SKIP:     ustr = "SKIP";     break;
	case BASE:     ustr = "BASE";     break;
	case OVERLAY:  ustr = "OVERLAY";  break;
	case STACKED:  ustr = "STACKED";  break;
	case ERRORBAR: ustr = "ERRORBAR"; break;
	case NOGRAPH:  ustr = "NOGRAPH";  break;
	}
  xmlout->Element("Status", ustr);
  xmlout->Element("NumberOfLevels", nlevs);
  xmlout->BeginTag("Data");
  for (short i=0; i<nlevs; i++) {
	double dval = (IsNan(data[i].x)) ? 0.0 : data[i].x;
	xmlout->ElementAttr("Value", dval, "Null", data[i].null, "Rare", data[i].rare);
	}
  xmlout->EndTag("Data");
  xmlout->EndTag("Graph");
}
//---------------------------------------------------------------------------

void GRAPH::ToggleSAXElement(UnicodeString& Element, TGXXML& tgx, bool toggle)
{
   if (Element == "VarName")
	 tgx.VarName = toggle;
   else if (Element == "VarCode")
	 tgx.VarCode = toggle;
   else if (Element == "GroupCode")
	 tgx.GroupCode = toggle;
   else if (Element == "Status")
	 tgx.Status = toggle;
   else if (Element == "NumberOfLevels")
	 tgx.NumberOfLevels = toggle;
   else if (Element == "Data")
	 tgx.Data = toggle;
   else if (Element == "Value")
	 tgx.Value = toggle;
}
//---------------------------------------------------------------------------

void GRAPH::EvaluateXML(UnicodeString& ustr, TGXXML& tgx)
{
   if (tgx.VarName)
	 name = ustr;
   else if (tgx.VarCode)
	 code = ustr;
   else if (tgx.GroupCode)
	 sum = ustr;
   else if (tgx.Status) {
	 if (ustr == "NORMAL")
	   status = NORMAL;
	 else if (ustr == "SKIP")
	   status = SKIP;
	 else if (ustr == "BASE")
	   status = BASE;
	 else if (ustr == "OVERLAY")
	   status = OVERLAY;
	 else if (ustr == "STACKED")
	   status = STACKED;
	 else if (ustr == "ERRORBAR")
	   status = ERRORBAR;
	 else if (ustr == "NOGRAPH")
	   status = NOGRAPH;
	 }
   else if (tgx.NumberOfLevels) {
	 nlevs = (short)ustr.ToInt();
	 data = new DATA [nlevs];
	 }
}
//---------------------------------------------------------------------------

void GRAPH::EvaluateXMLValue(UnicodeString& ustr, UnicodeString& Null,
	 UnicodeString& Rare)
{
   data[nin].null = (bool)Null.ToInt();
   data[nin].rare = (bool)Rare.ToInt();
   data[nin].x = IntlStrToDouble::GetDouble(ustr);
   nin++;
}
//---------------------------------------------------------------------------

