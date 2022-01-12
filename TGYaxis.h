//---------------------------------------------------------------------------
#ifndef TGYaxisH
#define TGYaxisH
//---------------------------------------------------------------------------
#include "ipwxmlp.h"
#ifndef TGDiagrmH
#include "TGDiagrm.h"
#endif
#ifndef TGTextH
#include "TGText.h"
#endif
#ifndef TIXMLH
#include "TIXML.h"
#endif

class NEWYAXIS
{
private:
  bool AutoScale;
  int NumberOfLevels;
  double AutoStepMultiplier;
  double LabelYOffset;
  double *depths;
  TTGDiagram *Diag;

public:
  bool AutoTic;
  bool Plot;
  bool ScaleAutoMin;
  bool ScaleAutoMax;
  bool AxisAutoMin;
  bool AxisAutoMax;
  bool DataAutoMin;  // new
  bool DataAutoMax;  // new
  int AxisType;
  int AxisStyle;
  int Units;
  int TicDecPts;
  int LabelPosition;
  TColor Color;
  double LineWidth;
  double SpaceRight;
  double yfac;
  double xbase;
  double yname_max;
  double xbasec;
  double AxisLength;
  double XaxisDistance;
  double ScaleMin;
  double ScaleMax;
  double AxisMin;
  double AxisMax;
  double DataMin;  // new
  double DataMax;  // new
  double MinorTics;
  double MajorTics;
  double MajorTicLength;
  double MinorTicLength;
  double LabelToTicDistance;
  double TicLabelDivideBy;
  double ytop;
  double ybot;
  double xlab;
  double ylab;
  double LabelAngle;
  UnicodeString AxisCode;
  UnicodeString AxisLabel;
  MYFONT TicFont;
  MYFONT LabelFont;

public:
  NEWYAXIS(int, YAXIS&, double, TTGDiagram*, int);
  NEWYAXIS(UnicodeString&, UnicodeString&, YAXIS&, double, TTGDiagram*);
  NEWYAXIS(TTGDiagram*);
  NEWYAXIS(TTGDiagram*, int);
  NEWYAXIS(NEWYAXIS *);
  NEWYAXIS(UnicodeString&, UnicodeString&, TTGDiagram*);
  ~NEWYAXIS();
  void PlotAxis(void);
  void plot_sample_names(void);
  double get_depths1(double, NEWYAXIS *);
  double Depth(int i) { return depths[i]; }
  void PutDepth(int i, double x) { depths[i] = x; };
  double ywc(double);
  void Calc_yfac(void);
  void AutoAxisMinMax(void);
  void XMLOUT(WriteXML*, TList*);
  void EvaluateXML(UnicodeString&, TGXXML&, TList*);
  void ToggleSAXElement(UnicodeString&, TGXXML&, bool);
  double Length(void) { return (AxisLength+2.0*XaxisDistance); };
  int NumLevels(void) { return NumberOfLevels; }

private:
  void tic_label(int, double, double, UnicodeString&);
};


#endif

