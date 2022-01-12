//---------------------------------------------------------------------------
#include <ComCtrls.hpp>
#ifndef TGraphicH
#define TGraphicH
#include <vector>
//#ifndef TGTextH
//#include "TGText.h"
//#endif
#ifndef TIXMLH
#include "TIXML.h"
#endif
//---------------------------------------------------------------------------
class TTGDiagram;


enum TEXTHORIZONTAL { TEXT_NORMAL, TEXT_LEFT, TEXT_CENTER, TEXT_RIGHT };
enum TEXTVERTICAL { TEXT_TOP=1, TEXT_CAP=2, TEXT_HALF=3, TEXT_BASE=4, TEXT_BOTTOM=5};
enum FILLPATTERNS { NO_FILL=-1, HOLLOW_FILL=0, SOLID_FILL=1, PATTERN_FILL=2, BAR_FILL=4, GRID_FILL=5 };
enum GRAPHICSOBJECT {LINE_OBJECT, RECT_OBJECT, POLYGON_OBJECT, ELLIPSE_OBJECT,
                     TEXT_OBJECT};
enum LINESTYLES { DOTTED_LINE=3, SOLID_LINE=1, USER_DEFINED_LINE=4,
                  LONG_DASHED_LINE=2, SHORT_DASHED_LINE=-1 };
enum PRIORITY { TOBACK, TOFRONT };
enum DASHEDLINEUNITS { DPIXELS, DPOINTS };
enum DEVICE { DISPLAY, PRINTER, METAFILE };
enum SHAPE { ELLIPSE=1, PIE=2 };

class DblPoint
{
public:
  double x;
  double y;
public:
  DblPoint(double xx, double yy) { x = xx; y = yy; }
  DblPoint() { x = 0.0; y = 0.0; }
  void SetPoints(double xx, double yy) { x = xx; y = yy; }
  //void SetPoints(double, double);
};

class DblRect
{
public:
  double xmin;
  double xmax;
  double ymin;
  double ymax;

public:
  DblRect() { xmin = NaN; }
  DblRect(double, double, double, double);
  //DblRect(DblRect*);
  void operator = (const DblRect& copy);
  void SetParameters(TRect *);
  void SetParameters(double, double, double, double);
  double xlen(void) { return (xmax-xmin); }
  double ylen(void) { return (ymax-ymin); }
  void Rect(TRect *);
  void Zoom(double);
};

typedef struct
{
  double x;
  double y;
} DBLPOINT;

typedef struct
{
  int begin;
  int end;
} BEGINEND;

class SEGLIMITS
{
public:
  double xmin;
  double xmax;
  double ymin;
  double ymax;
  TRect rect;
  UnicodeString name;
  BEGINEND text;
  BEGINEND GraphicObjects;

public:
  SEGLIMITS() { }
  SEGLIMITS(double x1, double x2, double y1, double y2, UnicodeString s);
  void operator = (const SEGLIMITS& copy);
};

typedef struct
{
  bool italic;
  bool bold;
  bool greek;
  bool subscript;
  bool superscript;
  bool underline;
  bool strikeout;
  TFontCharset charset;
} FONTSTYLE;

class MYFONT
{
private:
  UnicodeString Element;

public:
  UnicodeString FontName;
  double Height;
  TColor Color;
  FONTSTYLE Style;
  bool StyleCompare;
  void operator = (const MYFONT& copy);
  bool operator == (const MYFONT& compare );
  bool operator != (const MYFONT& compare );

public:
  MYFONT();
  void XMLOUT(WriteXML*);
  void EvaluateXML(UnicodeString&, TGXXML&);
  void ToggleSAXElement(UnicodeString&, TGXXML&, bool);
  void Compare(const MYFONT& compare);
};

class TextObject
{
public:
  UnicodeString Text;
  double x;
  double y;
  double angle;
  UINT HorzTextAlign;
  UINT VertTextAlign;
  MYFONT Font;
  int bkcolor;

public:
  TextObject(double, double, double, UINT, UINT, int, MYFONT&, UnicodeString);
};

/*
typedef struct
{
  unsigned char italic      : 1;
  unsigned char bold        : 1;
  unsigned char greek       : 1;
  unsigned char subscript   : 1;
  unsigned char superscript : 1;
} FONTSTYLE;
*/

typedef struct
{
  int dash;
  int space;
} LINEDEF;

class LineObject
{
public:
	//DBLPOINT *points;
	vector<DBLPOINT> points;
	int n;
	int color;
	double width;
	int style;
	double dash;
	double space;
	DblRect ClipBox;

public:
	LineObject() { }
  /*
  LineObject(DBLPOINT *pts, int N, int co, double wi)
	{ points = pts; n = N; color = co; width = wi; style = SOLID_LINE;
	  ClipBox = NULL; }
  LineObject(DBLPOINT *pts, int N, int co, double wi, DblRect *r)
	{ points = pts; n = N; color = co; width = wi; style = SOLID_LINE;
	  ClipBox = new DblRect(r); }
  LineObject(DBLPOINT *pts, int N, int co, double wi, int st)
	{ points = pts; n = N; color = co; width = wi; style = st;
	  ClipBox = NULL; }
  LineObject(DBLPOINT *pts, int N, int co, double wi, LINEDEF *u)
	{ points = pts; n = N; color = co; width = wi; style = USER_DEFINED_LINE;
	  dash = u->dash; space = u->space; ClipBox = NULL; }
  ~LineObject()
	{ delete[] points;
	  if (ClipBox != NULL)
		delete ClipBox;
	}
  */

	void assign(vector<DBLPOINT>& pts, int co, double wi)
	  { points.assign(pts.begin(), pts.end()); n = pts.size(); color = co; width = wi;
		style = SOLID_LINE; }
	void assign(vector<DBLPOINT>& pts, int co, double wi, DblRect& clipbox)
	  { points.assign(pts.begin(), pts.end()); n = pts.size(); color = co; width = wi;
		style = SOLID_LINE; ClipBox = clipbox; }
	void assign(vector<DBLPOINT>& pts, int co, double wi, int st)
	  { points.assign(pts.begin(), pts.end()); n = pts.size(); color = co; width = wi;
		style = st; }
	void assign(vector<DBLPOINT>& pts, int co, double wi, LINEDEF& u)
	  { points.assign(pts.begin(), pts.end()); n = pts.size(); color = co; width = wi;
		style = USER_DEFINED_LINE; dash = u.dash, space = u.space; }
};

class PolygonObject
{
public:
	//DBLPOINT *points;
	vector<DBLPOINT> points;
	int n;
	int outline_color;
	int fill_color;
	int fill_style;
	int pattern;
	double width;
	DblRect ClipBox;

public:
  PolygonObject() { }
  /*
  //PolygonObject(DBLPOINT *pts, int N, double w, int oco, int fco, int st)
  //	{ points = pts; n = N; width = w; outline_color = oco; fill_color = fco;
  //	  fill_style = st; pattern = 0; ClipBox = NULL; }
  //PolygonObject(DBLPOINT *pts, int N, double w, int oco, int fco, int st, DblRect *r)
  //	{ points = pts; n = N; width = w; outline_color = oco; fill_color = fco;
  //	  fill_style = st; pattern = 0;
  //	  ClipBox = new DblRect(r); }
  //PolygonObject(DBLPOINT *pts, int N, double w, int oco, int fco, int st, int pat)
  //	{ points = pts; n = N; width = w; outline_color = oco; fill_color = fco;
  //	  fill_style = st; pattern = pat; ClipBox = NULL; }
  ~PolygonObject()
	{ delete[] points;
	  if (ClipBox != NULL)
		delete ClipBox;
	}
  */

	void assign(vector<DBLPOINT>& pts, double wi, int oco, int fco, int st)
	  { points.assign(pts.begin(), pts.end()); n = pts.size(); width = wi;
		outline_color = oco; fill_color = fco; fill_style = st; pattern = 0; }
	void assign(vector<DBLPOINT>& pts, double wi, int oco, int fco, int st, DblRect& clipbox)
	  { points.assign(pts.begin(), pts.end()); n = pts.size(); width = wi;
		outline_color = oco; fill_color = fco; fill_style = st; pattern = 0; ClipBox = clipbox; }
	void assign(vector<DBLPOINT>& pts, double wi, int oco, int fco, int st, int pat)
	  { points.assign(pts.begin(), pts.end()); n = pts.size(); width = wi;
		outline_color = oco; fill_color = fco; fill_style = st; pattern = pat; }
};

class RectObject
{
public:
	double xmin;
	double xmax;
	double ymin;
	double ymax;
	int color;
	int fill_style;

public:
	RectObject() { }
  //RectObject(DblRect *dr, int co, int st)
  //  { xmin = dr->xmin; xmax = dr->xmax; ymin = dr->ymin; ymax = dr->ymax;
  //    color = co; fill_style = st; }
	void assign(DblRect& dr, int co, int st)
		{ xmin = dr.xmin; xmax = dr.xmax; ymin = dr.ymin; ymax = dr.ymax;
		  color = co; fill_style = st; }
};


class EllipseObject
{
public:
	double xmin;
	double xmax;
	double ymin;
	double ymax;
	double X3, Y3, X4, Y4;
	int color;
	int fill_style;
	short object;
	DblRect ClipBox;

public:
	EllipseObject() { }
  /*
  EllipseObject(DblRect *dr, int co, int st)
	{ xmin = dr->xmin; xmax = dr->xmax; ymin = dr->ymin; ymax = dr->ymax;
	  color = co;
	  fill_style = st;
	  object = ELLIPSE;
	  ClipBox = NULL;
	}
  EllipseObject(DblRect *dr, int co, int st, DblRect *r)
	{ xmin = dr->xmin; xmax = dr->xmax; ymin = dr->ymin; ymax = dr->ymax;
	  color = co;
	  fill_style = st;
	  object = ELLIPSE;
	  ClipBox = new DblRect(r);
	}
  EllipseObject(DblRect *dr, double x3, double y3, double x4, double y4, int co, int st)
	{ xmin = dr->xmin; xmax = dr->xmax; ymin = dr->ymin; ymax = dr->ymax;
	  X3 = x3; Y3= y3; X4 = x4; Y4 = y4;
	  color = co;
	  fill_style = st;
	  object = PIE;
	  ClipBox = NULL;
	}
  ~EllipseObject()
	{ if (ClipBox != NULL)
		delete ClipBox;
	}
  */
	void assign(DblRect& dr, int co, int st)
	  { xmin = dr.xmin; xmax = dr.xmax; ymin = dr.ymin; ymax = dr.ymax;
		color = co; fill_style = st; object = ELLIPSE; }
	void assign(DblRect& dr, int co, int st, DblRect& clipbox)
	  { xmin = dr.xmin; xmax = dr.xmax; ymin = dr.ymin; ymax = dr.ymax;
		color = co; fill_style = st; object = ELLIPSE; ClipBox = clipbox; }
	void assign(DblRect& dr, double x3, double y3, double x4, double y4, int co, int st)
	  { xmin = dr.xmin; xmax = dr.xmax; ymin = dr.ymin; ymax = dr.ymax;
		X3 = x3; Y3 = y3; X4 = x4; Y4 = y4; color = co; fill_style = st;
		object = PIE; }
};

class GraphicObject
{
public:
  int type;
  int priority;
  //void *item;
  LineObject line;
  PolygonObject polygon;
  RectObject rect;
  EllipseObject ellipse;

public:
  //GraphicObject(int t, void *it)
  //	{ type = t; item = it; priority = TOFRONT; };
  //GraphicObject(int t, void *it, int p)
  //	{ type = t; item = it; priority = p; };

  //GraphicObject(LineObject lp)
  //	{ type = t; item = it; priority = TOFRONT; };

  // line objects
  GraphicObject(vector<DBLPOINT>& pts, int co, double wi)
	 { type = LINE_OBJECT; priority = TOFRONT; line.assign(pts, co, wi); }
  GraphicObject(vector<DBLPOINT>& pts, int co, double wi, DblRect& clipbox)
	 { type = LINE_OBJECT; priority = TOFRONT; line.assign(pts, co, wi, clipbox); }
  GraphicObject(vector<DBLPOINT>& pts, int co, double wi, int style)
	 { type = LINE_OBJECT; priority = TOFRONT; line.assign(pts, co, wi, style); }
  GraphicObject(vector<DBLPOINT>& pts, int co, double wi, int style, int prior)
	 { type = LINE_OBJECT; priority = prior; line.assign(pts, co, wi, style); }
  GraphicObject(vector<DBLPOINT>& pts, int co, double wi, LINEDEF& user, int prior)
	 { type = LINE_OBJECT; priority = prior; line.assign(pts, co, wi, user); }

  // polygon objects
  GraphicObject(vector<DBLPOINT>& pts, double wi, int oco, int fco, int st)
	 { type = POLYGON_OBJECT; priority = TOFRONT; polygon.assign(pts, wi, oco, fco, st); }
  GraphicObject(vector<DBLPOINT>& pts, double wi, int oco, int fco, int st, DblRect& clipbox)
	 { type = POLYGON_OBJECT; priority = TOFRONT; polygon.assign(pts, wi, oco, fco, st, clipbox); }
  GraphicObject(vector<DBLPOINT>& pts, double wi, int oco, int fco, int st, int pat)
	 { type = POLYGON_OBJECT; priority = TOFRONT; polygon.assign(pts, wi, oco, fco, st, pat); };
  GraphicObject(vector<DBLPOINT>& pts, double wi, int oco, int fco, int st, int pat, int prior)
	 { type = POLYGON_OBJECT; priority = prior; polygon.assign(pts, wi, oco, fco, st, pat); };

  // ellipse objectes
  GraphicObject(DblRect& drect, int co, int style)
	 { type = ELLIPSE_OBJECT; priority = TOFRONT; ellipse.assign(drect, co, style); }
  GraphicObject(DblRect& drect, int co, int style, DblRect& clipbox)
	 { type = ELLIPSE_OBJECT; priority = TOFRONT; ellipse.assign(drect, co, style, clipbox); }
  GraphicObject(DblRect& drect, double x3, double y3, double x4, double y4, int co, int style)
	 { type = ELLIPSE_OBJECT; priority = TOFRONT; ellipse.assign(drect, x3, y3, x4, y4, co, style); }

  // rect object
  GraphicObject(int co, int style, DblRect& drect)
	 { type = RECT_OBJECT, priority = TOFRONT; rect.assign(drect, co, style); }

  //~GraphicObject();
};

typedef struct
{
int Option;
int Units;
int Orientation;
double YaxisHeight;
double DiagramHeight;
double Inches;
double Overlap;
} PRINTOPTIONS;


class SetClipRect
{
private:
  HRGN MyRgn;
  TCanvas *Canvas;

public:
  SetClipRect(double, double, double, int, DblRect&, TCanvas *);
  ~SetClipRect();
};

class MyGraphics
{
private:
  double ZoomFactor;
  int ZoomIndex;
  int initClientHeight;
  int initClientWidth;
  TForm *GraphicForm;

  //DblRect *wc;      // maximum size of diagram in world coordinates
                    // replaces limits (I think)
  double fac, xoffset, yoffset;
  double XOffset;
  double YOffset;
  double Margin;
  double PrintMargin;
  bool DiagramMade;
  bool Repeat;
  int HorzPosition;
  int VertPosition;
  UnicodeString LastSegmentEdited;
  Graphics::TBitmap *BrushBmp;
  Graphics::TBitmap *DisplayBmp;
  bool WriteToBitmap;
  TProgressBar *PBar;

//private:   // new stuff
public:
  //TList *GraphicObjects;
  vector<GraphicObject> GraphicObjects;

public:
  //TList *TextStrings;
  vector<TextObject> TextStrings;
  //TList *sl;
  vector<SEGLIMITS> sl;
  HFONT hFont;
  bool DirectToPrinter;
  bool DirectToMetafile;
  TMetafile *MyMetafile;
  TMetafileCanvas *MetafileCanvas;
  TCanvas* PrinterCanvas;
  TCanvas* BitmapCanvas;
  TCanvas* GraphicFormCanvas;
  //DblRect *InitDisplayRect;
  //DblRect *DisplayRect100;
  //DblRect *DisplayRect;
  bool GraphicMade;
  DblRect *wcmax;   // maximum world coordinates
  int BackgroundColor;
  int SelectionColor;
  PRINTOPTIONS PrintOptions;
  TRect EditSegmentRect;
  DblRect *wc;      // maximum size of diagram in world coordinates
                    // replaces limits (I think)
  //TODO: put wc back in private

public:
  MyGraphics(double, double, double, double, TColor, TForm *);
  ~MyGraphics();
  void Reset(void);
  void Polyline(int, vector<double>::iterator, vector<double>::iterator, int, double);
  void Polyline(int, vector<double>::iterator, vector<double>::iterator, int, double, DblRect&);
  void Polyline(int, vector<double>::iterator, vector<double>::iterator, int, double, int);
  void Polyline(int, vector<double>::iterator, vector<double>::iterator, int, double, int, int);
  void Polyline(int, vector<double>::iterator, vector<double>::iterator, int, double, LINEDEF&, int);

  //void Polyline(int, double *, double *, int, double, LINEDEF*, int);
  void Polygon(int, vector<double>&, vector<double>&, double, int, int, int);
  void Polygon(int, vector<double>&, vector<double>&, double, int, int, int, DblRect&);
  void Polygon(int, vector<double>&, vector<double>&, double, int, int, int, int);
  void Polygon(int, vector<double>&, vector<double>&, double, int, int, int, int, int);
  void FillRect(DblRect&, int, int);
  void Ellipse(DblRect&, int, int);
  void Ellipse(DblRect&, int, int, DblRect&);
  void Ellipse(DblRect&, double, double, double, double, int, int);
  void FontSize(double);
  void FontName(UnicodeString);
  void Zoom(double z, int idx) { ZoomFactor = z; ZoomIndex = idx; }
  void Zoom(double z) { ZoomFactor = z; }
  double GetToHeightZoom(void);
  double CurrentZoom(void) { return ZoomFactor; }
  int GetZoomIndex(void) { return ZoomIndex; }
  void PrintOut(void);
  TCanvas *Canvas(void);
  void Extent(double, double);
  void ExtentX(double);
  void ExtentY(double);
  double MinExtentX(void) { return wc->xmin; }  // replaces limits.minx;
  double MaxExtentX(void) { return wc->xmax; }
  double MinExtentY(void) { return wc->ymin; }
  double MaxExtentY(void) { return wc->ymax; }
  double LenExtentX(void) { return wc->xlen(); }
  double LenExtentY(void) { return wc->ylen(); }
  void OutputGraphicObjects(int, TTGDiagram*);
  void Output(double, double, double, int);
  void Output1(double, double, double, int, int);
  void NewSegment(UnicodeString);
  void NewSegment(UnicodeString, double, double);
  void CloseSegment(void);
  void EditSegment(int, int, UnicodeString&);
  double getXOffset(void) { return XOffset; }
  double getYOffset(void) { return YOffset; }
  double GetMargin(void) { return Margin; }
  double GetPrintMargin(void) { return PrintMargin; }
  void ResetEditSegment(void);
  double GetXoffset(void) { return xoffset; }
  double GetYoffset(void) { return yoffset; }
  double GetFac(void) { return fac; }

private:
  int LineWidth(double);
  void DashedLine(int, int, int, TPoint *, double fac);
  void SetSelectionColor(void);
};

#endif
