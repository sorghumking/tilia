//---------------------------------------------------------------------------
#ifndef TGH
#define TGH
#include <iostream.h>
#include <math.hpp>
#include "ipwxmlp.h"
#include "cxEdit.hpp"

#ifndef TGDOS
#include "TGDOS.h"
#endif
#ifndef TGraphicH
#include "TGraphic.h"
#endif
#ifndef TGTextH
#include "TGText.h"
#endif
#ifndef TIXMLH
#include "TIXML.h"
#endif
//#ifndef _RWSTD_NO_NAMESPACE
//  using namespace std;

void trap_allocation_failures();
#define EXAGGERATE 1
#define TRUNCATE   2
#define SPACE 32
#define PI 3.141592654
#define RPD 0.01745329
#define BACKSLASH 92

enum STATUS { NORMAL, BASE, OVERLAY, STACKED, SKIP, ERRORBAR, NOGRAPH };
enum GRAPHTYPES { SILHOUETTE=1, HISTOGRAM=2, LINEGRAPH=3, NUMBERS=4, PRESENCE=5 };
enum AXISTYPES { STANDARD_AXIS=1, COLUMN_AXIS=2, NAMES_AXIS=3 };
enum YAXISUNITS { DEFAULT_UNITS, DEPTH_UNITS, AGE_UNITS };
enum ZONEPRIORITY { ZONETOBACK, ZONETOFRONT };
enum ZONESTYLE { LINEZONE=1, PATTERNZONE=2 };
enum TICLABELS { NOTICLABEL, TICLABEL };
enum TRUNCATEWHERE { END_OF_GRAPH=1, END_OF_AXIS=2 };
enum LABELPOSITION { SIDE=1, TOP=2, USERDEFINED=-1 };
enum GROUPPOSITION { INLINE, ABOVELINE };
enum AXISPRIORITY { PRIMARY_AXIS=1, SECONDARY_AXIS=2, TERTIARY_AXIS=3 };
enum GRIDLINES { NOGRIDLINES, ONMINORTICS, ONMAJORTICS };
enum RARESYMBOLS { RAREPLUS=1, RARECIRCLE=2 };
enum DIAGRAMPOSITION { LEFT, RIGHT };
enum FONTSTYLES { BOLD, ITALIC, SUPERSCRIPT, SUBSCRIPT };

typedef struct
{
  bool null;
  bool rare;
  double x;
} DATA;

class LINEPARAMS
{
public:
  TColor Color;
  double LineWidth;
};

class RARESPECIES
{
public:
  short Symbol;
  double Size;
  double LineWidth;

public:
  RARESPECIES();
  void XMLOUT(WriteXML*);
  void EvaluateXML(UnicodeString&, TGXXML&);
  void ToggleSAXElement(UnicodeString&, TGXXML&, bool);
};

class FRAME
{
public:
  bool Plot;
  double Bottom;
  double Top;
  double Left;
  double Right;
  double FrameMargin;
  double LineWidth;
  TColor Color;

public:
  FRAME();
  void XMLOUT(WriteXML*);
  void EvaluateXML(UnicodeString&, TGXXML&);
  void ToggleSAXElement(UnicodeString&, TGXXML&, bool);
};

class GRAPHS		    // graph styles
{
public:
  bool     VerticalAxis;      // vertical axis on or off
  bool     SymbolName;	   // symbol name on/off switch
  bool     ZeroSymbol;     // TRUE if symbol plotted for zero values
  bool     AutoMarkerTop;  // auto placement of symbol label at top of graph
  bool     AutoMarkerBottom;  // auto placement of symbol label at bottom of graph
  bool     PresenceSymbol;    // TRUE if symbol plotted in label
  bool     DepthBars;	   // TRUE if depth bars plotted across graphs
  bool     DottedBaseLine; // TRUE if dotted baselines
  bool     PlotZeroNumbers; // TRUE if zeros plotted in numbers graph
  bool     UseThickVar;     // True if Thickness var is used for histogram graphs
  short    GraphType;	   // type of graph
  short    SilhouetteFill;  // fill area interior style for silhouette graphs
  short    SilhouettePattern; // fill area style index
  short    Exag;	   // exaggeration of silhouette graph
  short    ExagFill;       // fill area interior style for exaggeration
  short    ExagPattern;	   // pattern for exaggeration
  short    ExagGrid;	   // grid lines: 0-none, 1-minor, 2-major
  short    BarFill;        // interior style for histogram bar
  short    BarPattern;	   // pattern for bar
  short    DecimalPoints;  // number of decimal points for numbers graph
  short    MarkerType;	   // marker type
  TColor   GraphColor;	   // graph color index
  TColor   ExagColor;	   // exaggeration color index
  TColor   GraphOutlineColor;   // outline color index (new)
  TColor   ExagOutlineColor;    // exaggeration outline color index (new)
  TColor   DepthBarsColor;       // depth bars color (new)
  double   SilhouetteLineWidth;   // silhouette line thickness
  double   HistogramLineWidth;    // histogram line thickness
  double   LineGraphLineWidth;    // line graph line thickness
  double   MarkerLineWidth;       // line width for markers
  double   BarWidth;	   // thickness of histogram bar
  double   MarkerSize;	   // marker size
  double   XMarkerLabel;   // x-coordinate of symbol label
  double   YMarkerLabel;   // y-coordinate of symbol label
  double   AngleMarkerLabel;  // angle of symbol label
  double   XPresence;	   // x-axis position for presence marker
  MYFONT   NumberFont;

private:
  void WriteFillStyle(WriteXML*, short, UnicodeString);
  short ParseFillStyle(UnicodeString&);

public:
  GRAPHS();
  GRAPHS(GRAPHS *);
  void XMLOUT(WriteXML*, short, TList*);
  void EvaluateXML(UnicodeString&, TGXXML&, TList*);
  void ToggleSAXElement(UnicodeString&, TGXXML&, bool);
  bool operator == (const GRAPHS& compare );
};

class XAXIS
{
public:
  bool AutoTic;             // TRUE if tics automatically calculated
  bool AutoScaleFactor;	    // TRUE if xfac automatically calculated
  bool AutoMin;	            // TRUE if mim automatically calculated
  bool AutoMax;	            // TRUE if max automatically calculated
  bool LabelOriginTic;      // TRUE if tic mark labeled at origin
  bool Truncate;	    // TRUE if graph truncated
  bool PlotGraphName;       // true if graph name is plotted (new)
  short TicDecPts; 	    // decimal points in tic labels
  short GridLines;          // grid lines: 0-none, 1-minor, 2-major
  bool PrintTruncatedValues; // true if truncated values printed
  bool ScaleTruncatedValues; // true if printed truncated value scaled by ticfac
  short TruncateWhere;       // where graph is truncated (end of axis or graph)
  short TruncateDecPts;      // number of decimal points in truncated label (default = 0)
  TColor Color;              // axis color (new)
  double GraphWidth;        // width of graph, = -1.0 if calc with xfac
  double ScaleFactor;       // scale factor for x-axis
  double MinorTics;        // graph distance between x-axis minor tics
  double MajorTics;        // graph distance between x-axis xmajor tics
  double LabeledTics;      // graph distance between x-axis labelled tics
  double TicLabelDivideBy;  // factor tic labels divided by
  double LabelToTicDistance; // distance label is plotted from tic mark
  double MajorTicLength;     // length major x-axis tic mark
  double MinorTicLength;     // length minor x-axis tic mark
  double TopTicLength;       // length of top x-axis tic marks
  double GraphNameAngle;    // angle of graph label
  double GraphNameXOffset;  // x offset for graph name
  double GraphNameYOffset;  // y offset for graph name
  double DistanceToNextGraph; // distance between graphs
  double XaxisMin;          // minimum value for x-axis
  double XaxisMax;	    // maximum value for x-axis
  double AxisLineWidth;    // line width (new)
  double GridLineWidth;     // line width of grid lines (new)
  UnicodeString AxisLabel;    // axis name
  MYFONT TicFont;
  MYFONT AxisLabelFont;
  MYFONT GraphNameFont;
  MYFONT TruncFont;

public:
  XAXIS();
  XAXIS(XAXIS *);
  void XMLOUT(WriteXML*, short, TList*);
  void EvaluateXML(UnicodeString&, TGXXML&, TList*);
  void ToggleSAXElement(UnicodeString&, TGXXML&, bool);
  bool operator == (const XAXIS& compare );
};

class GRAPH
{
private:
  short nin;

public:
  short status;
  UnicodeString sum;
  UnicodeString code;
  UnicodeString name;
  short nlevs;
  GRAPHS *graph;
  XAXIS *xax;
  DATA *data;
public:
  GRAPH() : nlevs(0), graph(0), xax(0), data(0) { }
  GRAPH(short n, GRAPHS *g, XAXIS *x, DATA *d, TGVARS *v) :
    nlevs(n), graph(g), xax(x), data(d),
    status(v->status), sum(v->sum), code(v->code), name(v->name) { }
  GRAPH(GRAPHS *g, XAXIS *x) : graph(g), xax(x), nin(0) { }
  ~GRAPH();
  void XMLOUT(WriteXML*, int, int);
  void EvaluateXML(UnicodeString&, TGXXML&);
  void EvaluateXMLValue(UnicodeString&, UnicodeString&, UnicodeString&);
  void ToggleSAXElement(UnicodeString&, TGXXML&, bool);
};


class LEVELS
{
public:
  double num;
  UnicodeString name;
public:
  void XMLOUT(WriteXML*);
  void EvaluateXML(UnicodeString&, TGXXML&);
};

class GROUP_ATTRIBUTES
{
public:
  short Position;
  TColor Color;
  double LineWidth;
  MYFONT Font;
public:
  GROUP_ATTRIBUTES();
  void BasicXMLOUT(WriteXML*, TList*);
  void XMLOUT(WriteXML*, TList*);
  void BasicEvaluateXML(UnicodeString&, TGXXML&, TList*);
  void EvaluateXML(UnicodeString&, TGXXML&, TList*);
  void BasicToggleSAXElement(UnicodeString&, TGXXML&, bool);
  void ToggleSAXElement(UnicodeString&, TGXXML&, bool);
  void operator = (const GROUP_ATTRIBUTES& copy);
};

class GROUPS : public GROUP_ATTRIBUTES
{
public:
  UnicodeString code1;
  UnicodeString code2;
  UnicodeString name;

public:
  GROUPS() { }
  GROUPS(GROUPS *g) {Position = g->Position; Color = g->Color; LineWidth = g->LineWidth;
				   code1 = g->code1; code2 = g->code2; name = g->name;
				   Font = g->Font; }
  void XMLOUT(WriteXML*, TList*);
  void EvaluateXML(UnicodeString&, TGXXML&, TList*);
  void ToggleSAXElement(UnicodeString&, TGXXML&, bool);
  void operator = (const GROUP_ATTRIBUTES& copy);
  void operator = (const GROUPS& copy);
};


class ZONE_ATTRIBUTES
{
public:
  bool ThruLabelCol;
  short ZoneStyle;
  short LineStyle;
  short Pattern;
  bool Border;
  short Priority;
  TColor ZoneColor;
  TColor BorderColor;
  double ZoneWidth;
  double LineWidth;
  LINEDEF user;
  void operator = (const ZONE_ATTRIBUTES& copy);

public:
  ZONE_ATTRIBUTES();
  void BasicXMLOUT(WriteXML*);
  void XMLOUT(WriteXML*);
  void BasicEvaluateXML(UnicodeString&, TGXXML&);
  void EvaluateXML(UnicodeString&, TGXXML&);
  void BasicToggleSAXElement(UnicodeString&, TGXXML&, bool);
  void ToggleSAXElement(UnicodeString&, TGXXML&, bool);
};

class ZONE : public ZONE_ATTRIBUTES
{
public:
  double depth;

public:
  ZONE() { depth=NaN; }
  ZONE(ZONE*);
  void XMLOUT(WriteXML*);
  void EvaluateXML(UnicodeString& ustr, TGXXML& tgx);
  void ToggleSAXElement(UnicodeString&, TGXXML&, bool);
  void operator = (const ZONE_ATTRIBUTES& copy);
  void operator = (const ZONE& copy);
};

class ZONEOPTIONS
{
public:
  bool Center;
  double ZoneTitleAngle;
  double ZoneTitleXOffset;
  double ZoneTitleYOffset;
  UnicodeString ZoneTitle;
  MYFONT ZoneTitleFont;
  MYFONT ZoneFont;

public:
  ZONEOPTIONS();
  void XMLOUT(WriteXML*, TList*);
  void EvaluateXML(UnicodeString&, TGXXML&, TList*);
  void ToggleSAXElement(UnicodeString&, TGXXML&, bool);
};

class ZONELABELS
{
public:
  double top;
  double bottom;
  UnicodeString label;
public:
  ZONELABELS() { top=NaN; bottom=NaN; }
  ZONELABELS(ZONELABELS* zl) { top=zl->top; bottom=zl->bottom; label=zl->label; } 
  void XMLOUT(WriteXML*);
  void EvaluateXML(UnicodeString&, TGXXML&);
  void ToggleSAXElement(UnicodeString&, TGXXML&, bool);
};

class DATEOPTIONS
{
public:
  short DatesPosition;
  short DatesTitlePosition;
  TColor Color;            
  double DatesTitleTopYOffset;
  double X_Title;
  double Y_Title;
  double Angle;
  MYFONT DateTitleFont;
  MYFONT DateFont;
  UnicodeString DateTitle;

public:
  DATEOPTIONS();
  void XMLOUT(WriteXML*, TList*);
  void EvaluateXML(UnicodeString&, TGXXML&, TList*);
  void ToggleSAXElement(UnicodeString&, TGXXML&, bool);
};

class DATES
{
public:
  double top;
  double bot;
  double voff;
  UnicodeString date;

public:
  DATES() { top=NaN; bot=NaN; voff=0; }
  DATES(DATES *d) { top=d->top; bot=d->bot; voff=d->voff; date=d->date; }
  void XMLOUT(WriteXML*);
  void EvaluateXML(UnicodeString&, TGXXML&);
  void ToggleSAXElement(UnicodeString&, TGXXML&, bool);
};

class LITHOPTIONS
{
public:
  bool On;
  bool KeyOn;
  bool AutoTopDepth;
  bool AutoBotDepth;
  TColor DefaultColor;
  double TopDepth;
  double BotDepth;
  double Angle;
  double BoxWidth;
  double LithLineWidth;     // lith pattern
  double KeyLineWidth;      // lith key boxes
  double ColumnLineWidth;   // vertical lines on lithology column
  double BoundaryLineWidth; // horizontal lines between lith types
  UnicodeString LithTitle;
  MYFONT LithTitleFont;
  MYFONT KeyFont;

public:
  LITHOPTIONS();
  void XMLOUT(WriteXML*, TList*);
  void EvaluateXML(UnicodeString&, TGXXML&, TList*);
  void ToggleSAXElement(UnicodeString&, TGXXML&, bool);
};

class LITHCOMPONENT
{
public:
  short LithCode;
  short Humo;
  double XShift;
  double YShift;
  TColor Color;

public:
  LITHCOMPONENT() { LithCode=0; Humo=0; XShift=0; YShift=0; Color=clBlack; }
  LITHCOMPONENT(LITHCOMPONENT *l) { LithCode=l->LithCode; Humo=l->Humo;
                    XShift=l->XShift; YShift=l->YShift; Color=l->Color; }
  void XMLOUT(WriteXML*);
  void EvaluateXML(UnicodeString&, TGXXML&);
  void ToggleSAXElement(UnicodeString&, TGXXML&, bool);
};

class LITHUNIT
{
public:
  double Top;
  double Bot;
  bool LoBound;
  TColor LoBoundColor;
  TList *Components;

public:
  LITHUNIT(TColor);
  LITHUNIT(LITHUNIT*);
  ~LITHUNIT();                        
  void XMLOUT(WriteXML*);
  void EvaluateXML(UnicodeString&, TGXXML&);
  void ToggleSAXElement(UnicodeString&, TGXXML&, bool);
};

class LITHKEY
{
private:
  short LithCode;
  short Humo;

public:
  bool Plot;
  bool AutoX;
  bool AutoY;
  double x;
  double y;
  UnicodeString LithLabel;
  TColor Color;
  TStringList* TroelsSmithCodes;

public:
  LITHKEY(){ Plot=false; AutoX=true; AutoY=true; LithCode=0; Humo=0; x=NaN;
             y=NaN; Color=clBlack; TroelsSmithCodes=NULL; }
  LITHKEY(LITHKEY* lk) { Plot=lk->Plot; AutoX=lk->AutoX; AutoY=lk->AutoY;
      LithCode=lk->LithCode; Humo=lk->Humo; x=lk->x; y=lk->y;
      LithLabel=lk->LithLabel; Color=lk->Color; TroelsSmithCodes=NULL; }
  short GetLithCode(void) { return LithCode; }
  short GetHumo(void) { return Humo; }
  void SetLithCode(short);
  void SetLithCode(UnicodeString&);
  void SetHumo(short);
  UnicodeString GetLithUnit(void);
  void Set_x(UnicodeString);
  void Set_y(UnicodeString);
  void XMLOUT(WriteXML*);
  void EvaluateXML(UnicodeString&, TGXXML&);
  void ToggleSAXElement(UnicodeString&, TGXXML&, bool);
};

class TEXTLINE
{
public:
  double x;
  double y;
  double angle;
  UnicodeString Text;
  MYFONT Font;

public:
  TEXTLINE() { x=NaN; y=NaN; angle=0; }
  TEXTLINE(TEXTLINE *t)
    { x=t->x; y=t->y; angle=t->angle; Text=t->Text; Font=t->Font; }
  void XMLOUT(WriteXML*, TList*);
  void EvaluateXML(UnicodeString&, TGXXML&, TList*);
  void ToggleSAXElement(UnicodeString&, TGXXML&, bool);
};

class TEXT_BLOCK
{
public:
  bool AutoX;
  bool AutoY;
  double x;
  double y;
  UnicodeString Text;
  MYFONT Font;

public:
  TEXT_BLOCK();
  void XMLOUT(WriteXML*, UnicodeString&, TList*);
  void EvaluateXML(UnicodeString&, TGXXML&, TList*);
  void ToggleSAXElement(UnicodeString&, TGXXML&, bool);
};

class DGROPTIONS
{
public:
  bool Loaded;  // new
  bool On;
  bool AutoTic;
  bool AutoTicDecPts;
  short ScaleType;
  short TicDecPts;
  TColor AxisColor;       // new
  TColor DendColor; // new
  double AxisLineWidth;
  double DendLineWidth;    // new
  double DendWidth;
  double MajorTics;
  double MinorTics;
  double TopTicLength;      // new: length of top tic marks
  double MajorTicLength;    // new: length major x-axis tic mark
  double MinorTicLength;    // new: length minor x-axis tic mark
  double LabelToTicDistance; // new: distance label is plotted from tic mark
  double GraphNameYOffset;   // new: y offset for graph name
  UnicodeString DendTitle;
  UnicodeString DendAxisLabels[4];
  MYFONT AxisLabelFont;
  MYFONT DendTitleFont;
  MYFONT TicFont;

public:
  DGROPTIONS();
  void XMLOUT(WriteXML*, TList*);
  void EvaluateXML(UnicodeString&, TGXXML&, TList*);
  void ToggleSAXElement(UnicodeString&, TGXXML&, bool);
};

class DENDROGRAM
{
public:
  short clus1;
  short clus2;
  double inc;
  double tot;
  double wcd;
  double mwcd;

public:
  void XMLOUT(WriteXML*);
  void EvaluateXML(UnicodeString&, TGXXML&);
  void ToggleSAXElement(UnicodeString&, TGXXML&, bool);
  //void EvaluateXML(UnicodeString&, DGXXML&);
  void EvaluateXML(DGXXML&);
  void ToggleSAXElement(UnicodeString&, DGXXML&, bool);
};

class DEFAULT
{
public:
  double LineWidth;
  MYFONT Font;
  GRAPHS Graph;
  XAXIS Xaxis;
  GROUP_ATTRIBUTES GroupAttr;
  ZONE_ATTRIBUTES ZoneAttr;

public:
  DEFAULT();
  //void WriteXML(ofstream&, TList*);
  void XMLOUT(WriteXML*, TList*);
  void EvaluateXML(UnicodeString&, TGXXML&, TList*);
};

class TcxCustomEditAccess : public TcxCustomEdit
{
public:
        __property OnKeyUp;
        __property OnKeyDown;
        __property OnMouseUp;
        __property OnMouseDown;
};
  
#endif

