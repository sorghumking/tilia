//---------------------------------------------------------------------------

#include <vcl.h>
#include "pch.h"
#pragma hdrstop

#include "TGraphic.h"
#ifndef TGTextH
#include "TGText.h"
#endif
#include "TGParent.h"
#ifndef TGDiagrmH
#include "TGDiagrm.h"
#endif
#ifndef TGUtilsH
#include "TGUtils.h"
#endif
#ifndef TGYaxisH
#include "TGYaxis.h"
#endif

//---------------------------------------------------------------------------

#pragma package(smart_init)


DblRect::DblRect(double xl, double xr, double yb, double yt)
{
  xmin = xl;
  xmax = xr;
  ymin = yb;
  ymax = yt;
}
//---------------------------------------------------------------------------

/*
DblRect::DblRect(DblRect *r)
{
  xmin = r->xmin;
  xmax = r->xmax;
  ymin = r->ymin;
  ymax = r->ymax;
}
//---------------------------------------------------------------------------
*/

void DblRect::operator = (const DblRect& copy)
{
   if (this == &copy) return;
   xmin = copy.xmin;
   xmax = copy.xmax;
   ymin = copy.ymin;
   ymax = copy.ymax;
}
//---------------------------------------------------------------------------

void DblRect::SetParameters(TRect *rect)
{
  ymin = (double)rect->Top;
  ymax = (double)rect->Bottom;
  xmin = (double)rect->Left;
  xmax = (double)rect->Right;
}
//---------------------------------------------------------------------------

void DblRect::SetParameters(double Top, double Bottom, double Left, double Right)
{
  ymin = Top;
  ymax = Bottom;
  xmin = Left;
  xmax = Right;
}
//---------------------------------------------------------------------------

void DblRect::Zoom(double z)
{
  ymin *= z;
  ymax *= z;
  xmin *= z;
  xmax *= z;
}
//---------------------------------------------------------------------------

void DblRect::Rect(TRect *rect)
{
  rect->Top    = nint(ymin);
  rect->Bottom = nint(ymax);
  rect->Left   = nint(xmin);
  rect->Right  = nint(xmax);
}
//---------------------------------------------------------------------------

SEGLIMITS::SEGLIMITS(double x1, double x2, double y1, double y2, UnicodeString s)
{
  xmin = x1;
  xmax = x2;
  ymin = y1;
  ymax = y2;
  name = s;
}
//---------------------------------------------------------------------------

void SEGLIMITS::operator = (const SEGLIMITS& copy)
{
   if (this == &copy) return;
   xmin = copy.xmin;
   xmax = copy.xmax;
   ymin = copy.ymin;
   ymax = copy.ymax;
   rect = copy.rect;
   name = copy.name;
   text = copy.text;
   GraphicObjects = copy.GraphicObjects;
}
//---------------------------------------------------------------------------

/*
GraphicObject::~GraphicObject()
{
  switch (type)
  {
  case LINE_OBJECT:
	delete (LineObject*)item;
	break;
  case POLYGON_OBJECT:
	delete (PolygonObject*)item;
	break;
  case ELLIPSE_OBJECT:
	delete (EllipseObject*)item;
	break;
  case RECT_OBJECT:
	delete (RectObject*)item;
	break;
  }
}
//---------------------------------------------------------------------------
*/

MyGraphics::MyGraphics(double left, double right, double top, double bottom,
    TColor background_color, TForm *form)
{
  BackgroundColor = background_color;
  SetSelectionColor();

  GraphicMade = false;    // may not need anymore
  DirectToPrinter = false;
  DirectToMetafile = false;
  GraphicForm = form;
  //InitDisplayRect = NULL;    // initial display rectangle
  //DisplayRect100 = NULL;     // 100% display rectangle
  //DisplayRect = NULL;        // current display rectangle
  wc = NULL;
  wcmax = NULL;
  //GraphicObjects = NULL;

  ZoomFactor = 1.0;
  ZoomIndex = 0;
  XOffset = 0.0;
  YOffset = 0.0;
  Margin = 0.5;
  PrintMargin = 0.2;
  DiagramMade = false;
  Repeat = false;
  HorzPosition = -1;
  VertPosition = -1;
  fac = 1.0;
  xoffset = 0.0;
  yoffset = 0.0;

  //TODO: this stuff should go in .tgw file
  PrintOptions.Option = 0;
  PrintOptions.DiagramHeight = 0.0;
  PrintOptions.YaxisHeight = 0.0;
  PrintOptions.Units = 0;
  PrintOptions.Inches = 0.0;
  PrintOptions.Overlap = 0.0;
  PrintOptions.Orientation = -1;

  DisplayBmp = new Graphics::TBitmap;
  WriteToBitmap = false;

  PrinterCanvas = Printer()->Canvas;
  BitmapCanvas = DisplayBmp->Canvas;
  GraphicFormCanvas = GraphicForm->Canvas;

  //TextStrings = new TList;
  //TextStrings->Capacity = 1000;
  TextStrings.reserve(1000);

  //GraphicObjects = new TList;
  //GraphicObjects.capacity = 2000;
  GraphicObjects.reserve(2000);
  //sl = new TList;
  //sl->Capacity = 1000;
  sl.reserve(1000);

  initClientHeight = GraphicForm->ClientHeight;
  initClientWidth = GraphicForm->ClientWidth;

  // min and max possible world coordinates for diagram
  wcmax = new DblRect(left, right, bottom, top);

  // initial world coordinates of diagram
  wc = new DblRect(wcmax->xmax, wcmax->xmin, wcmax->ymax, wcmax->ymin);

  //ClearScreen();
  GraphicMade = true;    //TODO: maybe not needed anymore
}
//---------------------------------------------------------------------------

MyGraphics::~MyGraphics()
{
  int i;
  GraphicForm->HorzScrollBar->Position = 0;
  GraphicForm->HorzScrollBar->Margin = 0;
  GraphicForm->VertScrollBar->Position = 0;
  GraphicForm->VertScrollBar->Margin = 0;

  if (wc != NULL) delete wc;
  if (wcmax != NULL) delete wcmax;
  delete DisplayBmp;
}
//---------------------------------------------------------------------------

void MyGraphics::SetSelectionColor(void)
{
  int blue = GetBValue(BackgroundColor);
  int green = GetGValue(BackgroundColor);
  int red = GetRValue(BackgroundColor);
  if (blue > 128 && green > 128)
	{ blue = 0; green = 0; red = 255; }
  else if (blue > 128 && red > 128)
    { blue = 0; red = 0; green = 255; }
  else if (green > 128 && red > 128 )
    { green = 0; red = 0; blue = 255; }
  else
    { blue = 0; green = 0; red = 255; }
  SelectionColor = (TColor)RGB(red, green, blue);
}
//---------------------------------------------------------------------------

void MyGraphics::Reset(void)
{
  int i;

  TextStrings.clear();
  GraphicObjects.clear();
  sl.clear();

  wc->SetParameters(wcmax->ymax, wcmax->ymin, wcmax->xmax, wcmax->xmin);
}
//---------------------------------------------------------------------------

void MyGraphics::NewSegment(UnicodeString Name)
{
  const double limit = 1000000;
  XOffset = 0.0;
  YOffset = 0.0;
  //SEGLIMITS *s = new SEGLIMITS(limit, -limit, limit, -limit, Name);
  SEGLIMITS s(limit, -limit, limit, -limit, Name);
  s.text.begin = TextStrings.size();
  //s->GraphicObjects.begin = GraphicObjects->Count;
  s.GraphicObjects.begin = GraphicObjects.size();
  //sl->Add(s);
  sl.push_back(s);
}
//---------------------------------------------------------------------------

void MyGraphics::NewSegment(UnicodeString Name, double xoff, double yoff)
{
  const double limit = 1000000;
  XOffset = xoff;
  YOffset = yoff;
  //SEGLIMITS *s = new SEGLIMITS(limit, -limit, limit, -limit, Name);
  SEGLIMITS s(limit, -limit, limit, -limit, Name);
  s.text.begin = TextStrings.size();
  s.GraphicObjects.begin = GraphicObjects.size();
  //sl->Add(s);
  sl.push_back(s);
}
//---------------------------------------------------------------------------

void MyGraphics::CloseSegment(void)
{
  //SEGLIMITS* s = (SEGLIMITS*)sl->Last();
  SEGLIMITS& s = sl.back();
  s.text.end = TextStrings.size() - 1;
  //s->GraphicObjects.end = GraphicObjects->Count - 1;
  s.GraphicObjects.end = GraphicObjects.size() - 1;
}
//---------------------------------------------------------------------------

void MyGraphics::EditSegment(int X, int Y, UnicodeString& SegName)
{
  unsigned int i;
  //SEGLIMITS* s;
  //TList *Segs;

  //Segs = new TList;
  //Segs->Capacity = 10;
  vector<SEGLIMITS> Segs;
  SEGLIMITS s;

  for (i=0; i<sl.size(); i++) {
	//s = (SEGLIMITS*)sl->Items[i];
	s = sl[i];
	if (X >= s.rect.Left && X <= s.rect.Right && Y <= s.rect.Bottom && Y >= s.rect.Top)
	   //Segs->Add(s);
	   Segs.push_back(s);
	}

  if (Segs.size() == 0) {
	//  delete Segs;
	return;
	}

  for (i=0; i<Segs.size(); i++) {
	//s = (SEGLIMITS*)Segs->Items[i];
	if (Segs[i].name == LastSegmentEdited)
      break;
    }

  //vector<SEGLIMITS>::pointer sptr;
  if (i >= Segs.size()-1)
	//s = (SEGLIMITS*)Segs->Items[0];
	s = Segs[0];
  else
	//s = (SEGLIMITS*)Segs->Items[i+1];
	s = Segs[i+1];

  if (!LastSegmentEdited.IsEmpty())
	Canvas()->DrawFocusRect(EditSegmentRect);
  EditSegmentRect = s.rect;
  Canvas()->DrawFocusRect(EditSegmentRect);

  LastSegmentEdited = s.name;

  ParentForm->StatusBar1->Panels->Items[1]->Text = s.name;
  SegName = s.name;

  //Segs->Clear();
  //delete Segs;
}
//---------------------------------------------------------------------------

void MyGraphics::ResetEditSegment(void)
{
  if (!LastSegmentEdited.IsEmpty()) {
    Canvas()->DrawFocusRect(EditSegmentRect);
    LastSegmentEdited = "";
    ParentForm->StatusBar1->Panels->Items[1]->Text = "";
    }
}
//---------------------------------------------------------------------------

TCanvas* MyGraphics::Canvas(void)
{
  if (DirectToPrinter)
	//return Printer()->Canvas;
	return PrinterCanvas;
  else if (DirectToMetafile)
	return MetafileCanvas;
  else if (WriteToBitmap)
	//return DisplayBmp->Canvas;
	return BitmapCanvas;
  else
	//return GraphicForm->Canvas;
	return GraphicFormCanvas;
}
//---------------------------------------------------------------------------

void MyGraphics::Polyline(int n, vector<double>::iterator xitr, vector<double>::iterator yitr, int color,
   double width)
{
  //DBLPOINT *points = new DBLPOINT [n];
  vector<DBLPOINT> points;
  points.reserve(n);
  for (int i=0; i<n; i++) {
	//points[i].x = x[i] + XOffset;
	double x = *(xitr+i);
	double y = *(yitr+i);
	//points[i].x = x + XOffset;
	//points[i].y = y + YOffset;
	DBLPOINT point;
	point.x = x + XOffset;
	point.y = y + YOffset;
	points.push_back(point);
	//Extent(x[i]+XOffset, y[i]+YOffset);
	Extent(point.x, point.y);
	}

  //LineObject *lp = new LineObject(points, n, color, width);
  //GraphicObjects->Add(new GraphicObject(LINE_OBJECT, lp));
  GraphicObjects.push_back(GraphicObject(points, color, width));
  DiagramMade = true;
}
//---------------------------------------------------------------------------


void MyGraphics::Polyline(int n, vector<double>::iterator xitr, vector<double>::iterator yitr, int color,
   double width, DblRect& ClipBox)
{
  //DBLPOINT *points = new DBLPOINT [n];
  vector<DBLPOINT> points;
  points.reserve(n);
  for (int i=0; i<n; i++) {
	double x = *(xitr+i);
	double y = *(yitr+i);
	DBLPOINT point;
	point.x = x + XOffset;
	point.y = y + YOffset;
	points.push_back(point);
	Extent(point.x, point.y);
	}

  //LineObject *lp = new LineObject(points, n, color, width, ClipBox);
  //GraphicObjects->Add(new GraphicObject(LINE_OBJECT, lp));
  GraphicObjects.push_back(GraphicObject(points, color, width, ClipBox));
  DiagramMade = true;
}
//---------------------------------------------------------------------------

void MyGraphics::Polyline(int n, vector<double>::iterator xitr, vector<double>::iterator yitr, int color,
   double width, int style)
{
  //DBLPOINT *points = new DBLPOINT [n];
  vector<DBLPOINT> points;
  points.reserve(n);
  for (int i=0; i<n; i++) {
	double x = *(xitr+i);
	double y = *(yitr+i);
	DBLPOINT point;
	point.x = x + XOffset;
	point.y = y + YOffset;
	points.push_back(point);
	Extent(point.x, point.y);
    }

  //LineObject *lp = new LineObject(points, n, color, width, style);
  //GraphicObjects->Add(new GraphicObject(LINE_OBJECT, lp));
  GraphicObjects.push_back(GraphicObject(points, color, width, style));
  DiagramMade = true;
}
//---------------------------------------------------------------------------

void MyGraphics::Polyline(int n, vector<double>::iterator xitr, vector<double>::iterator yitr, int color,
   double width, int style, int priority)
{
  //DBLPOINT *points = new DBLPOINT [n];
  vector<DBLPOINT> points;
  points.reserve(n);
  for (int i=0; i<n; i++) {
    double x = *(xitr+i);
	double y = *(yitr+i);
	DBLPOINT point;
	point.x = x + XOffset;
	point.y = y + YOffset;
	points.push_back(point);
	Extent(point.x, point.y);
	}

  //LineObject *lp = new LineObject(points, n, color, width, style);
  //GraphicObjects->Add(new GraphicObject(LINE_OBJECT, lp, priority));
  GraphicObjects.push_back(GraphicObject(points, color, width, style, priority));
  DiagramMade = true;
}
//---------------------------------------------------------------------------


// version for user defined line. dash and space lengths in points.
/*
void MyGraphics::Polyline(int n, double x[], double y[], int color,
   double width, LINEDEF *user, int priority)
{
  DBLPOINT *points = new DBLPOINT [n];
  for (int i=0; i<n; i++) {
	points[i].x = x[i] + XOffset;
	points[i].y = y[i] + YOffset;
	Extent(x[i]+XOffset, y[i]+YOffset);
	}

  LineObject *lp = new LineObject(points, n, color, width, user);
  GraphicObjects->Add(new GraphicObject(LINE_OBJECT, lp, priority));
  DiagramMade = true;
}
//---------------------------------------------------------------------------
*/

void MyGraphics::Polyline(int n, vector<double>::iterator xitr, vector<double>::iterator yitr,
   int color, double width, LINEDEF& user, int priority)
{
  //DBLPOINT *points = new DBLPOINT [n];
  vector<DBLPOINT> points;
  points.reserve(n);
  for (int i=0; i<n; i++) {
    double x = *(xitr+i);
	double y = *(yitr+i);
	DBLPOINT point;
	point.x = x + XOffset;
	point.y = y + YOffset;
	points.push_back(point);
	Extent(point.x, point.y);
	}

  //LineObject *lp = new LineObject(points, n, color, width, user);
  //GraphicObjects->Add(new GraphicObject(LINE_OBJECT, lp, priority));
  GraphicObjects.push_back(GraphicObject(points, color, width, user, priority));
  DiagramMade = true;
}
//---------------------------------------------------------------------------


void MyGraphics::Polygon(int n, vector<double>& x, vector<double>& y, double width,
      int outline_color, int fill_color, int fill_style)
{
  //DBLPOINT *points = new DBLPOINT [n];
  vector<DBLPOINT> points;
  points.reserve(n);
  for (int i=0; i<n; i++) {
	DBLPOINT point;
	point.x = x[i] + XOffset;
	point.y = y[i] + YOffset;
	points.push_back(point);
	Extent(point.x, point.y);
	}

  //PolygonObject *pp = new PolygonObject(points, n, width, outline_color,
  //                           fill_color, fill_style);
  //GraphicObjects->Add(new GraphicObject(POLYGON_OBJECT, pp));
  GraphicObjects.push_back(GraphicObject(points, width, outline_color, fill_color, fill_style));
  DiagramMade = true;
}
//---------------------------------------------------------------------------

/*
void MyGraphics::Polygon(int n, double x[], double y[], double width,
	  int outline_color, int fill_color, int fill_style, DblRect *ClipBox)
{
  DBLPOINT *points = new DBLPOINT [n];
  for (int i=0; i<n; i++) {
	points[i].x = x[i] + XOffset;
	points[i].y = y[i] + YOffset;
	Extent(x[i]+XOffset, y[i]+YOffset);
	}

  PolygonObject *pp = new PolygonObject(points, n, width, outline_color, fill_color,
										fill_style, ClipBox);
  GraphicObjects->Add(new GraphicObject(POLYGON_OBJECT, pp));
  DiagramMade = true;
}
//---------------------------------------------------------------------------
*/

void MyGraphics::Polygon(int n, vector<double>& x, vector<double>& y, double width,
	  int outline_color, int fill_color, int fill_style, DblRect& ClipBox)
{
  //DBLPOINT *points = new DBLPOINT [n];
  vector<DBLPOINT> points;
  points.reserve(n);
  for (int i=0; i<n; i++) {
	DBLPOINT point;
	point.x = x[i] + XOffset;
	point.y = y[i] + YOffset;
	points.push_back(point);
	Extent(point.x, point.y);
	}

  //PolygonObject *pp = new PolygonObject(points, n, width, outline_color, fill_color,
  //										fill_style, ClipBox);
  //GraphicObjects->Add(new GraphicObject(POLYGON_OBJECT, pp));
  GraphicObjects.push_back(GraphicObject(points, width, outline_color, fill_color, fill_style, ClipBox));
  DiagramMade = true;
}
//---------------------------------------------------------------------------

//void MyGraphics::g_fillarea(int n, double x[], double y[], int color, int style, int pat)
void MyGraphics::Polygon(int n, vector<double>& x, vector<double>& y, double width,
	  int outline_color, int fill_color, int fill_style, int pat)
{
  //DBLPOINT *points = new DBLPOINT [n];
  vector<DBLPOINT> points;
  points.reserve(n);
  for (int i=0; i<n; i++) {
	DBLPOINT point;
	point.x = x[i] + XOffset;
	point.y = y[i] + YOffset;
	points.push_back(point);
	Extent(point.x, point.y);
    }

  //PolygonObject *pp = new PolygonObject(points, n, width, outline_color,
  //                           fill_color, fill_style, pat);
  //GraphicObjects->Add(new GraphicObject(POLYGON_OBJECT, pp));
  GraphicObjects.push_back(GraphicObject(points, width, outline_color, fill_color, fill_style, pat));
  DiagramMade = true;
}
//---------------------------------------------------------------------------

void MyGraphics::Polygon(int n, vector<double>& x, vector<double>& y, double width,
	  int outline_color, int fill_color, int fill_style, int pat, int priority)
{
  //DBLPOINT *points = new DBLPOINT [n];
  vector<DBLPOINT> points;
  points.reserve(n);
  for (int i=0; i<n; i++) {
	DBLPOINT point;
	point.x = x[i] + XOffset;
	point.y = y[i] + YOffset;
	points.push_back(point);
	Extent(point.x, point.y);
	}

  //PolygonObject *pp = new PolygonObject(points, n, width, outline_color,
  //							 fill_color, fill_style, pat);
  //GraphicObjects->Add(new GraphicObject(POLYGON_OBJECT, pp, priority));
  GraphicObjects.push_back(GraphicObject(points, width, outline_color, fill_color, fill_style, pat, priority));
  DiagramMade = true;
}
//---------------------------------------------------------------------------

void MyGraphics::FillRect(DblRect& drect, int fill_color, int fill_style)
{
   drect.xmin += XOffset;
   drect.xmax += XOffset;
   drect.ymin += YOffset;
   drect.ymax += YOffset;

   //RectObject *rp = new RectObject(drect, fill_color, fill_style);
   //GraphicObjects->Add(new GraphicObject(RECT_OBJECT, rp));
   GraphicObjects.push_back(GraphicObject(fill_color, fill_style, drect));

   Extent(drect.xmin, drect.ymin);
   Extent(drect.xmax, drect.ymax);
}
//---------------------------------------------------------------------------

void MyGraphics::Ellipse(DblRect& drect, int color, int fill_style)
{
   drect.xmin += XOffset;
   drect.xmax += XOffset;
   drect.ymin += YOffset;
   drect.ymax += YOffset;

   //EllipseObject *ep = new EllipseObject(drect, color, fill_style);
   //GraphicObjects->Add(new GraphicObject(ELLIPSE_OBJECT, ep));
   GraphicObjects.push_back(GraphicObject(drect, color, fill_style));
   Extent(drect.xmin, drect.ymin);
   Extent(drect.xmax, drect.ymax);
}
//---------------------------------------------------------------------------

void MyGraphics::Ellipse(DblRect& drect, int color, int fill_style,
	  DblRect& ClipBox)
{
   drect.xmin += XOffset;
   drect.xmax += XOffset;
   drect.ymin += YOffset;
   drect.ymax += YOffset;

   //EllipseObject *ep = new EllipseObject(drect, color, fill_style, ClipBox);
   //GraphicObjects->Add(new GraphicObject(ELLIPSE_OBJECT, ep));
   GraphicObjects.push_back(GraphicObject(drect, color, fill_style, ClipBox));

   Extent(drect.xmin, drect.ymin);
   Extent(drect.xmax, drect.ymax);
}
//---------------------------------------------------------------------------

void MyGraphics::Ellipse(DblRect& drect, double x3, double y3, double x4,
			  double y4, int color, int fill_style)
{
   drect.xmin += XOffset;
   drect.xmax += XOffset;
   drect.ymin += YOffset;
   drect.ymax += YOffset;
   x3 += XOffset;
   y3 += YOffset;
   x4 += XOffset;
   y4 += YOffset;

   //EllipseObject *ep = new EllipseObject(drect, x3, y3, x4, y4, color, fill_style);
   //GraphicObjects->Add(new GraphicObject(ELLIPSE_OBJECT, ep));
   GraphicObjects.push_back(GraphicObject(drect, x3, y3, x4, y4, color, fill_style));

   Extent(drect.xmin, drect.ymin);
   Extent(drect.xmax, drect.ymax);
}
//---------------------------------------------------------------------------

double MyGraphics::GetToHeightZoom(void)
{
    double xlen, ylen;
    double ToHeightZoom;
    double DiagramAspectRatio;
    double WindowAspectRatio;
    int ClientWidth, ClientHeight;

    TTGDiagram* TGDiagram = (TTGDiagram *)ParentForm->ActiveMDIChild;

    xlen = MaxExtentX() - MinExtentX() + 2.0*GetMargin();
    ylen = MaxExtentY() - MinExtentY() + 2.0*GetMargin();
    ClientHeight = TGDiagram->ClientHeight;
    ClientWidth = TGDiagram->ClientWidth;

    if (TGDiagram->HorzScrollBar->Range == 0)
      ClientHeight -= TGDiagram->HorzScrollBar->Size;
    if (TGDiagram->VertScrollBar->Range > 0)
      ClientWidth += TGDiagram->VertScrollBar->Size;

    DiagramAspectRatio = ylen/xlen;
    WindowAspectRatio = (double)ClientHeight/(double)ClientWidth;

    if (DiagramAspectRatio < WindowAspectRatio) {
      Double z = (xlen*(double)ClientHeight)/(ylen*(double)ClientWidth);
      ToHeightZoom = floor(100.0*z)/100.0;
      if (ToHeightZoom == z)
        ToHeightZoom -= 0.01;
      ToHeightZoom = (10.0*floor(100.0*ToHeightZoom/10.0))/100.0;
      }
    else
      ToHeightZoom = 1.0;

    return ToHeightZoom;
}
//---------------------------------------------------------------------------

void MyGraphics::OutputGraphicObjects(int device, TTGDiagram *TGDiagram)
{
   double zoom;
   double xmin, xlen, ymin, ylen;
   double ToHeightZoom;
   int ClientWidth, ClientHeight;
   int yPixelsPerInch;
   double NewDiagHeightPixels;
   double DiagHeightPixels;
   double len;
   SEGLIMITS* s;
   NEWYAXIS *Axis1;

   if (Repeat) return;
   if (device == DISPLAY && DirectToPrinter) return;

   if (!TGDiagram) return;

   Screen->Cursor = crHourGlass;
   if (device == DISPLAY)
     {
       ClientWidth = TGDiagram->ClientWidth;
       ClientHeight = TGDiagram->ClientHeight;

       zoom = ZoomFactor;

       if (zoom <= 1.0) {
         Repeat = true;
         GraphicForm->HorzScrollBar->Position = 0;
         GraphicForm->VertScrollBar->Position = 0;
         GraphicForm->HorzScrollBar->Range = 0;
         GraphicForm->VertScrollBar->Range = 0;
         Repeat = false;
         ClientWidth = TGDiagram->ClientWidth;
         ClientHeight = TGDiagram->ClientHeight;
         }
       HorzPosition = GraphicForm->HorzScrollBar->Position;
       VertPosition = GraphicForm->VertScrollBar->Position;
       xmin = wc->xmin - GetMargin();
       xlen = wc->xmax + GetMargin() - xmin;
       ymin = wc->ymin - GetMargin();
       ylen = wc->ymax + GetMargin() - ymin;
       yoffset = ymin;
       xoffset = xmin;

       // this fixes first problem
       if (GraphicForm->VertScrollBar->Visible)
         ToHeightZoom =
           (xlen*(double)ClientHeight)/(ylen*(double)ClientWidth);
       else
         ToHeightZoom =
           (xlen*(double)(ClientHeight - TGDiagram->HorzScrollBar->Size))/
           (ylen*(double)ClientWidth);
     }
   else if (device == PRINTER) {
     ClientWidth = Printer()->PageWidth;
     ClientHeight = Printer()->PageHeight;
     xmin = wc->xmin - GetPrintMargin();
     xlen = wc->xmax + GetPrintMargin() - xmin;
     ymin = wc->ymin - GetPrintMargin();
     ylen = wc->ymax + GetPrintMargin() - ymin;
     yoffset = ymin;
     xoffset = xmin;
     }
   else { // device = METAFILE
     xmin = wc->xmin;
     xlen = wc->xmax - xmin;
     ymin = wc->ymin;
     ylen = wc->ymax - ymin;
     MyMetafile->MMWidth = Screen->Width;
     MyMetafile->MMHeight = Screen->Height;
     ClientWidth = MyMetafile->MMWidth;
     ClientHeight = MyMetafile->MMHeight;
     xoffset = wc->xmin;
     yoffset = wc->ymin;
     zoom = 1.0;
     }

   double DiagramAspectRatio = ylen/xlen;
   double WindowAspectRatio = (double)ClientHeight/(double)ClientWidth;

   if (DiagramAspectRatio > WindowAspectRatio)
     fac = (double)ClientHeight/ylen;
   else
     fac = (double)ClientWidth/xlen;

   if (device == PRINTER)
     {
       switch (PrintOptions.Option)
       {
       case 0:   // fits to page
         zoom = 1.0;
         break;
       case 1:   // Fits to height
         zoom = (xlen*(double)ClientHeight)/(ylen*(double)ClientWidth);
         break;
       case 2:   // Specify diagram height
         yPixelsPerInch = GetDeviceCaps(Printer()->Handle, LOGPIXELSY);
         NewDiagHeightPixels = (PrintOptions.Inches*ylen/(ylen-2.0*GetPrintMargin()))*yPixelsPerInch;
         DiagHeightPixels = fac*ylen;
         zoom = NewDiagHeightPixels/DiagHeightPixels;
         break;
       case 3:   // Specify y-axis height
         TGDiagram = (TTGDiagram *)ParentForm->ActiveMDIChild;
         Axis1 = (NEWYAXIS*)TGDiagram->YAxes->Items[0];
         len = Axis1->AxisLength;
         yPixelsPerInch = GetDeviceCaps(Printer()->Handle, LOGPIXELSY);
         NewDiagHeightPixels = (PrintOptions.Inches*ylen/len)*yPixelsPerInch;
         DiagHeightPixels = fac*ylen;
         zoom = NewDiagHeightPixels/DiagHeightPixels;
         break;
       }
     }

   //if (zoom > 1.0)
   fac *= zoom;

   if (device == DISPLAY)
     {
      if (zoom > 1.0)
       {
        Repeat = true;
        int DiagWidth = (int)(ceil(fac * xlen));
        //int DiagWidth = (int)(floor(fac * xlen));
        if (ClientWidth < DiagWidth)
          GraphicForm->HorzScrollBar->Range = DiagWidth;
        if (zoom > ToHeightZoom)
          GraphicForm->VertScrollBar->Range = (int)(ceil(fac * ylen));
        else
          GraphicForm->VertScrollBar->Range = 0;
        Repeat = false;
        ClientWidth = TGDiagram->ClientWidth;
        ClientHeight = TGDiagram->ClientHeight;

        //if (ylen > xlen)         // recalculate fac with scroll bars
        if (DiagramAspectRatio > WindowAspectRatio)
          fac = zoom * (double)ClientHeight/ylen;
        else
          fac = zoom * (double)ClientWidth/xlen;
        //Repeat = false;
       }

      if (zoom == 1.0)
       {
         xoffset += (double)GraphicForm->HorzScrollBar->Position;
         yoffset -= (double)GraphicForm->VertScrollBar->Position;
       }
      else
       {
         yoffset += (ylen - (double)ClientHeight/fac);
         xoffset += (double)GraphicForm->HorzScrollBar->Position/fac;
         yoffset -= (double)GraphicForm->VertScrollBar->Position/fac;
       }
     }

   if (device == DISPLAY) {
	 //ClearScreen();
     DisplayBmp->Height = ClientHeight;
     DisplayBmp->Width = ClientWidth;
     WriteToBitmap = true;
	 Canvas()->Brush->Style = bsSolid;
     Canvas()->Brush->Color = TColor(BackgroundColor);
	 Canvas()->FillRect(Canvas()->ClipRect);
     Output(xoffset, yoffset, fac, ClientHeight);
	 WriteToBitmap = false;

	 if (!LastSegmentEdited.IsEmpty())
	   Canvas()->DrawFocusRect(EditSegmentRect);
	 Canvas()->Draw(0, 0, DisplayBmp);

	 for (unsigned int i=0; i<sl.size(); i++) {
	   //s = (SEGLIMITS*)sl->Items[i];
	   vector<SEGLIMITS>::pointer s = &sl[i];
	   s->rect.Left = nint((s->xmin - xoffset)*fac);
	   s->rect.Right = nint((s->xmax - xoffset)*fac);
	   s->rect.Top = nint((double)ClientHeight - (s->ymax - yoffset)*fac);
	   s->rect.Bottom = nint((double)ClientHeight - (s->ymin - yoffset)*fac);
	   }

	 if (!LastSegmentEdited.IsEmpty()) {
	   for (unsigned int i=0; i<sl.size(); i++) {
		 //s = (SEGLIMITS*)sl->Items[i];
		 vector<SEGLIMITS>::pointer s = &sl[i];
		 if (LastSegmentEdited == s->name) {
		   EditSegmentRect = s->rect;
		   Canvas()->DrawFocusRect(EditSegmentRect);
		   break;
		   }
		 }
	   }
	 //WriteToBitmap = false; // new
	 }
   else if (device == PRINTER) {
     double ViewWidth = (1.0 - PrintOptions.Overlap/100.0)*(double)ClientWidth/fac;
     double ViewWidth0 = (double)ClientWidth/fac;
     double begin = xmin;
     double end = xmin + xlen;
     do {
          Printer()->BeginDoc();

          if (BackgroundColor != clWhite) {
            Printer()->Canvas->Brush->Color = TColor(BackgroundColor);
            Printer()->Canvas->Brush->Style = bsSolid;
			Printer()->Canvas->FillRect(Rect(0,0,Printer()->PageWidth,Printer()->PageHeight));
            }

          Output(xoffset, yoffset, fac, ClientHeight);
          Printer()->EndDoc();
          if (begin + ViewWidth0 < end) {
            begin += ViewWidth;
            xoffset += ViewWidth;
          }
          else
            begin = end;
        } while (begin < end);
     }
   else   // METAFILE
	 Output(xoffset, yoffset, fac, ClientHeight);
   //Canvas()->Unlock();
   Screen->Cursor = crDefault;
}
//---------------------------------------------------------------------------

int MyGraphics::LineWidth(double points)
{
  int lw;
  if (DirectToPrinter) {
    lw = nint(points*GetDeviceCaps(Printer()->Handle, LOGPIXELSX)/72.0);
    }
  else {
    //lw = nint(ZoomFactor*points*Screen->PixelsPerInch/72.0);
    lw = nint(points*Screen->PixelsPerInch/72.0);
    }

  if (lw < 1) lw = 1;
  return lw;
}
//---------------------------------------------------------------------------

void MyGraphics::Output(double xoffset, double yoffset, double fac,
     int ClientHeight)
{
  if (DirectToPrinter || DirectToMetafile) {
    PBar = new TProgressBar(GraphicForm);
    PBar->Top = 3;
    PBar->Left = ParentForm->StatusBar1->Panels->Items[0]->Width +
                 ParentForm->StatusBar1->Panels->Items[1]->Width + 2;
    PBar->Height = 16;
    PBar->Width = ParentForm->StatusBar1->Panels->Items[2]->Width - 2;
    PBar->Max = GraphicObjects.size();
    PBar->Smooth = true;
    ParentForm->StatusBar1->InsertControl(PBar);
    }
  Output1(xoffset, yoffset, fac, ClientHeight, TOBACK);
  Output1(xoffset, yoffset, fac, ClientHeight, TOFRONT);
  if (DirectToPrinter || DirectToMetafile)
    delete PBar;
}
//---------------------------------------------------------------------------

SetClipRect::SetClipRect(double xoffset, double yoffset, double fac,
	  int ClientHeight, DblRect& ClipBox, TCanvas *can)
{
   Canvas = can;
   int Left = nint((ClipBox.xmin - xoffset)*fac);
   int Right = nint((ClipBox.xmax - xoffset)*fac);
   int Top = nint((double)ClientHeight - (ClipBox.ymin - yoffset)*fac);
   int Bottom = nint((double)ClientHeight - (ClipBox.ymax - yoffset)*fac);
   MyRgn = CreateRectRgn(Left, Top, Right, Bottom);
   SelectClipRgn(Canvas->Handle, MyRgn);
}
//---------------------------------------------------------------------------

SetClipRect::~SetClipRect()
{
   SelectClipRgn(Canvas->Handle, 0);
   DeleteObject(MyRgn);
}
//---------------------------------------------------------------------------

void MyGraphics::Output1(double xoffset, double yoffset, double fac,
     int ClientHeight, int priority)
{
  int i;
  LineObject* lp;
  TextObject* tp;
  RectObject* rp;
  EllipseObject *ep;
  PolygonObject* pp;
  //GraphicObject* gp;
  MyText *Text;
  TRect rect;
  SetClipRect *ClipRect;
  TPoint *points;
  int X1, Y1, X2, Y2, X3, Y3, X4, Y4;


  for (unsigned int k=0; k<GraphicObjects.size(); k++)
	{
	  //gp = (GraphicObject*)GraphicObjects->Items[k];
	  vector<GraphicObject>::pointer gp = &GraphicObjects[k];
	  if (gp->priority != priority) continue;

	  if (DirectToPrinter || DirectToMetafile) PBar->Position++;

	  switch (gp->type)
	  {
	  case LINE_OBJECT:
		//lp = (LineObject*)gp->item;
		lp = &gp->line;
		//if (lp->n == 0)
		//  continue;

		//if (lp->ClipBox != NULL)
		if (!IsNan(lp->ClipBox.xmin))
		  ClipRect = new SetClipRect (xoffset, yoffset, fac, ClientHeight,
			 lp->ClipBox, Canvas());
		points = new TPoint[lp->n];
		for (int i=0; i<lp->n; i++)
		  points[i] = Point(nint((lp->points[i].x - xoffset)*fac),
            nint((double)ClientHeight - (lp->points[i].y - yoffset)*fac));
        Canvas()->Pen->Color = TColor(lp->color);
        Canvas()->Pen->Width = LineWidth(lp->width);
        Canvas()->Brush->Color = TColor(BackgroundColor);
        Canvas()->Pen->Style = psSolid;
        switch (lp->style)
		{
         case SOLID_LINE:
           Canvas()->Polyline(points, lp->n-1); // this is right!
           break;
         case DOTTED_LINE:
           DashedLine(DPIXELS, 2, 4, points, fac);    // dotted line
           break;
         case SHORT_DASHED_LINE:
           DashedLine(DPIXELS, 12, 6, points, fac);   // short dashed line
           break;
         case LONG_DASHED_LINE:
           DashedLine(DPIXELS, 24, 12, points, fac);  // long dashed line
           break;
         case USER_DEFINED_LINE:
           DashedLine(DPOINTS, lp->dash, lp->space, points, fac);
        }

		if (!IsNan(lp->ClipBox.xmin)) delete ClipRect;
        delete[] points;
		break;
      case POLYGON_OBJECT:
		//pp = (PolygonObject*)gp->item;
		pp = &gp->polygon;
		if (!IsNan(pp->ClipBox.xmin))
		  ClipRect = new SetClipRect (xoffset, yoffset, fac, ClientHeight,
             pp->ClipBox, Canvas());

        points = new TPoint [pp->n];

        for (i=0; i<pp->n; i++)
          points[i] = Point(nint((pp->points[i].x - xoffset)*fac),
            nint((double)ClientHeight - (pp->points[i].y - yoffset)*fac));

        // set outline pen
        if (pp->outline_color < 0)
          Canvas()->Pen->Style = psClear;
        else {
          Canvas()->Pen->Style = psSolid;
          Canvas()->Pen->Color = TColor(pp->outline_color);
          }

        Canvas()->Pen->Width = LineWidth(pp->width);

        switch (pp->fill_style)
        {
        case SOLID_FILL:
          Canvas()->Brush->Color = TColor(pp->fill_color);
          Canvas()->Brush->Style = bsSolid;
          Canvas()->Polygon(points, pp->n-1);
          break;
        case HOLLOW_FILL:
          Canvas()->Brush->Color = TColor(BackgroundColor);
          Canvas()->Brush->Style = bsSolid;
          Canvas()->Polygon(points, pp->n-1);
          break;
        case PATTERN_FILL:
		  if (pp->pattern > 0) {
			//BrushBmp = (Graphics::TBitmap *)ParentForm->GKSBitmaps->Items[pp->pattern-1];
			BrushBmp = ParentForm->GKSBitmaps[pp->pattern-1];
			if (!BrushBmp->Empty) {
			  Canvas()->Brush->Bitmap = BrushBmp;
			  SetTextColor(Canvas()->Handle, TColor(pp->fill_color));
			  SetBkColor(Canvas()->Handle, TColor(BackgroundColor));
			  Canvas()->Polygon(points, pp->n-1);
			  Canvas()->Brush->Bitmap = NULL;
			  SetTextColor(Canvas()->Handle, clBlack);
			  }
			}
          break;
		}
		if (!IsNan(pp->ClipBox.xmin)) delete ClipRect;
		delete[] points;
        break;
      case ELLIPSE_OBJECT:
		ep = &gp->ellipse;

		if (!IsNan(ep->ClipBox.xmin))
          ClipRect = new SetClipRect (xoffset, yoffset, fac, ClientHeight,
                         ep->ClipBox, Canvas());

        X1 = nint((ep->xmin - xoffset)*fac);
        X2 = nint((ep->xmax - xoffset)*fac);
        Y1 = nint((double)ClientHeight - (ep->ymax - yoffset)*fac);
        Y2 = nint((double)ClientHeight - (ep->ymin - yoffset)*fac);

        Canvas()->Pen->Style = psSolid;
        switch (ep->fill_style)
        {
        case SOLID_FILL:
          Canvas()->Brush->Color = TColor(ep->color);
          Canvas()->Pen->Color = TColor(ep->color);
          Canvas()->Brush->Style = bsSolid;
          break;
        case HOLLOW_FILL:
          Canvas()->Brush->Style = bsClear;
          Canvas()->Pen->Color = TColor(ep->color);;
          break;
        }

        if (ep->object == ELLIPSE)
          Canvas()->Ellipse(X1, Y1, X2, Y2);
        else {   // PIE
          X3 = nint((ep->X3 - xoffset)*fac);
          Y3 = nint((double)ClientHeight - (ep->Y3 - yoffset)*fac);
          X4 = nint((ep->X4 - xoffset)*fac);
          Y4 = nint((double)ClientHeight - (ep->Y4 - yoffset)*fac);
          Canvas()->Pie(X1, Y1, X2, Y2, X3, Y3, X4, Y4);
          }

		if (!IsNan(ep->ClipBox.xmin)) delete ClipRect;
        break;
      case RECT_OBJECT:
		//rp = (RectObject*)gp->item;
		rp = &gp->rect;

        rect.Left = nint((rp->xmin - xoffset)*fac);
        rect.Right = nint((rp->xmax - xoffset)*fac);
        rect.Top = nint((double)ClientHeight - (rp->ymax - yoffset)*fac);
        rect.Bottom = nint((double)ClientHeight - (rp->ymin - yoffset)*fac);

        switch (rp->fill_style)
        {
        case SOLID_FILL:
          Canvas()->Brush->Color = TColor(rp->color);
          Canvas()->Pen->Color = TColor(rp->color);
          Canvas()->Brush->Style = bsSolid;
          Canvas()->FillRect(rect);
          Canvas()->FrameRect(rect);
          break;
        case HOLLOW_FILL:
          Canvas()->Brush->Style = bsClear;
          Canvas()->FillRect(rect);
          Canvas()->Brush->Color = TColor(rp->color);;
          Canvas()->FrameRect(rect);
          break;
        }
        break;
      }
    }

    if (priority == TOFRONT) {
	  for (unsigned int i=0; i<TextStrings.size(); i++) {
		//tp = (TextObject*)TextStrings->Items[i];
		//Text = new MyText(tp, this);
		MyText Text(TextStrings[i], this);
		Text.DisplayText(ClientHeight, fac, xoffset, yoffset);
		//delete Text;
		}
    }
}
//---------------------------------------------------------------------------

void MyGraphics::DashedLine(int units, int dl, int space, TPoint *points, double fac)
{
  int X1, Y1, X2, Y2;
  int width, ystart, yend, xstart, xend;
  int PixelsPerInch;
  double ddl, dspace;

  if (DirectToPrinter) {
    if (units == DPOINTS) {
      ddl = ((double)dl/72.0)*fac;
      dspace = ((double)space/72.0)*fac;
      }
    else {
      ddl = (double)dl;
      dspace = (double)space;
      }
    PixelsPerInch = GetDeviceCaps(Printer()->Handle, LOGPIXELSX);
    if (PixelsPerInch != 300) {
      ddl = ddl*(double)PixelsPerInch/300.0;
      dspace = dspace*(double)PixelsPerInch/300.0;
      }
    dl = nint(ddl);
    space = nint(dspace);
    if (dl < 2) dl = 2;
    if (space < 2) space = 2;
    }
  else {
    if (units == DPOINTS) {
      dl = nint(((double)dl/72.0)*fac);
      if (dl < 2) dl = 2;
      space = nint(((double)space/72.0)*fac);
      if (space < 2) space = 2;
      }
    else {
      dl = nint(ZoomFactor*(double)dl*(double)Screen->PixelsPerInch/300.0);
      if (dl < 2) dl = 2;
      space = nint(ZoomFactor*(double)space*(double)Screen->PixelsPerInch/300.0);
      if (space < 2) space = 2;
      }
    }

  space += dl;
  width = Canvas()->Pen->Width;

  if (points[0].x == points[1].x)    // vertical line
    {
      X1 = points[0].x;
      if (points[0].y < points[1].y) {
        Y1 = points[0].y;
        Y2 = points[1].y;
        }
      else {
        Y1 = points[1].y;
        Y2 = points[0].y;
        }

      yend = (DirectToPrinter) ? dl : dl - VertPosition;
      while (yend < Y1)
        yend += (space+width);

      ystart = yend - dl + 1;
      if (ystart < Y1) {
        Canvas()->MoveTo(X1, Y1);
        yend = min(ystart+dl-1, Y2);  // new
        Canvas()->LineTo(X1, yend);
        ystart += (space+width);
        }

      while (ystart < Y2) {
        Canvas()->MoveTo(X1, ystart);
        yend = min(ystart+dl-1, Y2);
        Canvas()->LineTo(X1, yend);
        ystart += (space+width);
        }
    }
  else if (points[0].y == points[1].y)   // horizontal line
    {
      Y1 = points[0].y;
      if (points[0].x < points[1].x) {
        X1 = points[0].x;
        X2 = points[1].x;
        }
      else {
        X1 = points[1].x;
        X2 = points[0].x;
        }

      xend = (DirectToPrinter) ? dl : dl - HorzPosition;
      while (xend < X1)
        xend += (space+width);

      xstart = xend - dl + 1;
      if (xstart < X1) {
        Canvas()->MoveTo(X1, Y1);
        xend = min(xstart+dl-1, X2);  // new
        Canvas()->LineTo(xend, Y1);
        xstart += (space+width);
        }

      while (xstart < X2) {
        Canvas()->MoveTo(xstart, Y1);
        xend = min(xstart+dl-1, X2);
        Canvas()->LineTo(xend, Y1);
        xstart += (space+width);
        }
    }
}
//---------------------------------------------------------------------------

void MyGraphics::FontSize(double size)
{
  Canvas()->Font->Size = size;
}
//---------------------------------------------------------------------------

void MyGraphics::FontName(UnicodeString name)
{
  Canvas()->Font->Name = name;
}
//---------------------------------------------------------------------------

void MyGraphics::Extent(double x, double y)
{
  if (x > wc->xmax)
    wc->xmax = x;
  if (x < wc->xmin)
    wc->xmin = x;
  if (y > wc->ymax)
    wc->ymax = y;
  if (y < wc->ymin)
    wc->ymin = y;

  //SEGLIMITS* s = (SEGLIMITS*)sl->Last();
  SEGLIMITS& s = sl.back();
  if (x > s.xmax)
	s.xmax = x;
  if (x < s.xmin)
	s.xmin = x;
  if (y > s.ymax)
	s.ymax = y;
  if (y < s.ymin)
    s.ymin = y;
}
//---------------------------------------------------------------------------

void MyGraphics::ExtentX(double x)
{
  if (x > wc->xmax)
    wc->xmax = x;
  if (x < wc->xmin)
    wc->xmin = x;
}
//---------------------------------------------------------------------------

void MyGraphics::ExtentY(double y)
{
  if (y > wc->ymax)
    wc->ymax = y;
  if (y < wc->ymin)
    wc->ymin = y;
}
//---------------------------------------------------------------------------

void MyGraphics::PrintOut(void)
{
  if (PrintOptions.Orientation == 0)
    Printer()->Orientation = poLandscape;
  else if (PrintOptions.Orientation == 1)
    Printer()->Orientation = poPortrait;
  DirectToPrinter = true;
  OutputGraphicObjects(PRINTER, (TTGDiagram *)ParentForm->ActiveMDIChild);
  DirectToPrinter = false;
}
//---------------------------------------------------------------------------

