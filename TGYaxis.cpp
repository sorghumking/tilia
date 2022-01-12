//---------------------------------------------------------------------------
#include <iostream.h>
#include <vcl.h>
#include "pch.h"
#pragma hdrstop

#ifndef TGDiagrmH
#include "TGDiagrm.h"
#endif
#ifndef TGYaxisH
#include "TGYaxis.h"
#endif
#ifndef TGH
#include "tg.h"
#endif
#ifndef TGDOS
#include "TGDOS.h"
#endif
#ifndef TGUtilsH
#include "TGUtils.h"
#endif
#ifndef TGraphicH
#include "TGraphic.h"
#endif
#ifndef TGTextH
#include "TGText.h"
#endif
//---------------------------------------------------------------------------
#pragma package(smart_init)

// this constructor only for DOS .tgf files
NEWYAXIS::NEWYAXIS(int yk, YAXIS& yax, double as, TTGDiagram *diag, int nl)
{
  AxisType = yk;
  AutoStepMultiplier = as;
  Diag = diag;
  NumberOfLevels = nl;
  LabelYOffset = Diag->Default.Xaxis.GraphNameYOffset;
  AxisStyle = yax.style;    // all
  //axisNo = yax.axisNo;  // only applies to second axis
  SpaceRight = yax.space;
  XaxisDistance = yax.xdist;    // all
  AxisLength = yax.len-(2.0*XaxisDistance);        // all
  AxisMin = yax.min;        // all
  AxisMax = yax.max;
  TicFont = yax.TicFont;      // all
  LabelFont = yax.LabelFont;  // all
  MajorTicLength = yax.MajorTicLength;  // all
  MinorTicLength = yax.MinorTicLength;  // all
  LabelToTicDistance = yax.LabelToTicDistance;    // all
  yname_max = 0.0;
  xbase = 0.0;
  xbasec = 0.0;
  AutoScale = true;
  Color = yax.color;
  LineWidth = yax.LineWidth;

  switch (AxisType)
  {
  case PRIMARY_AXIS:
    Plot = yax.plot_primary;
    Units = yax.primary;
    AxisAutoMin = yax.automin;     // here
    AxisAutoMax = yax.automax;
    DataAutoMin = true;
    DataAutoMax = true;
    //AxisMin = yax.min;             // axis 1
    //AxisMax = yax.max;             // axis 1
    ScaleAutoMin = yax.automin1;   // axis 1
    ScaleAutoMax = yax.automax1;   // axis 1
    AutoTic = yax.autotic1;        // axis 1
    ScaleMin = yax.min1;           // axis 1
    ScaleMax = yax.max1;           // axis 1
    MinorTics = yax.minor_tics1;  // axis 1
    MajorTics = yax.major_tics1;  // axis 1
    TicDecPts = yax.ticdec1;          // axis 1
    TicLabelDivideBy = yax.ticfac1;          // axis 1
    LabelPosition = yax.label_position1;  // axis 1
    xlab = yax.xlab1;              // axis 1
    ylab = yax.ylab1;              // axis 1
    LabelAngle = yax.angle1;            // axis 1
    AxisLabel = yax.label1;            // axis 1
    break;
  case SECONDARY_AXIS:
    Plot = yax.plot_secondary;
    Units = yax.secondary;
    /* if (yax.axisNo > 1)
      units = DEFAULT_UNITS;
    else
      units = yax.secondary; */
    AxisAutoMin = true;
    AxisAutoMax = true;
    DataAutoMin = true;
    DataAutoMax = true;
    //AxisMin = 0;
    //AxisMax = 0;
    ScaleAutoMin = yax.automin2;
    ScaleAutoMax = yax.automax2;
    AutoTic = yax.autotic2;
    ScaleMin = yax.min2;
    ScaleMax = yax.max2;
    MinorTics = yax.minor_tics2;
    MajorTics = yax.major_tics2;
    TicDecPts = yax.ticdec2;
    TicLabelDivideBy = yax.ticfac2;
    LabelPosition = yax.label_position2;
    xlab = yax.xlab2;
    ylab = yax.ylab2;
    LabelAngle = yax.angle2;
    AxisLabel = yax.label2;
    break;
  }

  switch (Units) {
    case DEFAULT_UNITS:
      AxisCode = "Default";
      break;
    case DEPTH_UNITS:
      AxisCode = "Depth" + IntToStr(yax.axisNo);
      break;
    case AGE_UNITS:
      AxisCode = "Chron" + IntToStr(yax.axisNo);
      break;
    }

  //yfac =  (AxisLength-(2.0*XaxisDistance))/(AxisMax-AxisMin);
  if (AxisMax == AxisMin) {
    AxisMax += 1.0;
    AxisMin -= 1.0;
    }
  yfac =  AxisLength/(AxisMax-AxisMin);
  depths = new double [NumberOfLevels];
}

// Tertiary axis from DOS .tgf
NEWYAXIS::NEWYAXIS(UnicodeString& code, UnicodeString& name, YAXIS& yax, double as, TTGDiagram *diag)
{
  AxisCode = code;
  AutoStepMultiplier = as;
  Diag = diag;
  NumberOfLevels = Diag->Levs->Count;
  LabelYOffset = Diag->Default.Xaxis.GraphNameYOffset;
  AxisStyle = yax.style;    // all
  //axisNo = yax.axisNo;  // only applies to second axis
  SpaceRight = yax.space;
  XaxisDistance = yax.xdist;    // all
  AxisLength = yax.len-(2.0*XaxisDistance);        // all
  AxisMin = yax.min;        // all
  AxisMax = yax.max;
  TicFont = yax.TicFont;      // all
  LabelFont = yax.LabelFont;  // all
  MajorTicLength = yax.MajorTicLength;  // all
  MinorTicLength = yax.MinorTicLength;  // all
  LabelToTicDistance = yax.LabelToTicDistance;    // all
  yname_max = 0.0;
  xbase = 0.0;
  xbasec = 0.0;
  AutoScale = true;
  Color = yax.color;
  LineWidth = yax.LineWidth;

  AxisType = SECONDARY_AXIS;
  Plot = false;    // don't plot axis
  Units = DEPTH_UNITS;   // depth or age units
  AxisAutoMin = true;
  AxisAutoMax = true;
  DataAutoMin = true;
  DataAutoMax = true;
  //AxisMin = 0;
  //AxisMax = 0;
  ScaleAutoMin = true;
  ScaleAutoMax = true;
  AutoTic = true;
  ScaleMin = 0.0;
  ScaleMax = 0.0;
  TicDecPts = 0;
  TicLabelDivideBy = 1.0;
  LabelPosition = SIDE;
  xlab = 1000.0;
  ylab = 1000.0;
  LabelAngle = 45.0;
  AxisLabel = name;

  //yfac =  (AxisLength-(2.0*XaxisDistance))/(AxisMax-AxisMin);
  yfac =  AxisLength/(AxisMax-AxisMin);
  depths = new double [NumberOfLevels];
}

NEWYAXIS::NEWYAXIS(NEWYAXIS *Axis)
{
  int i;
  AutoScale = Axis->AutoScale;
  NumberOfLevels = Axis->NumberOfLevels;
  xlab = Axis->xlab;
  ylab = Axis->ylab;
  LabelAngle = Axis->LabelAngle;
  AutoStepMultiplier = Axis->AutoStepMultiplier;
  LabelYOffset = Axis->LabelYOffset;
  Diag = Axis->Diag;

  depths = new double [NumberOfLevels];
  for (i=0; i<NumberOfLevels; i++)
    depths[i] = Axis->depths[i];

  AutoTic = Axis->AutoTic;
  Plot = Axis->Plot;
  ScaleAutoMin = Axis->ScaleAutoMin;
  ScaleAutoMax = Axis->ScaleAutoMax;
  AxisAutoMin = Axis->AxisAutoMin;
  AxisAutoMax = Axis->AxisAutoMax;
  DataAutoMin = Axis->DataAutoMin;
  DataAutoMax = Axis->DataAutoMax;
  AxisType = Axis->AxisType;
  AxisStyle = Axis->AxisStyle;
  Units = Axis->Units;
  TicDecPts = Axis->TicDecPts;
  LabelPosition = Axis->LabelPosition;
  SpaceRight = Axis->SpaceRight;
  yfac = Axis->yfac;
  xbase = Axis->xbase;
  yname_max = Axis->yname_max;
  xbasec = Axis->xbasec;
  Color = Axis->Color;
  LineWidth = Axis->LineWidth;
  AxisLength = Axis->AxisLength;
  XaxisDistance = Axis->XaxisDistance;
  ScaleMin = Axis->ScaleMin;
  ScaleMax = Axis->ScaleMax;
  AxisMin = Axis->AxisMin;
  AxisMax = Axis->AxisMax;
  DataMin = Axis->DataMin;
  DataMax = Axis->DataMax;
  MinorTics = Axis->MinorTics;
  MajorTics = Axis->MajorTics;
  MajorTicLength = Axis->MajorTicLength;
  MinorTicLength = Axis->MinorTicLength;
  LabelToTicDistance = Axis->LabelToTicDistance;
  TicLabelDivideBy = Axis->TicLabelDivideBy;
  ytop = Axis->ytop;
  ybot = Axis->ybot;
  AxisCode = Axis->AxisCode;
  AxisLabel = Axis->AxisLabel;
  TicFont = Axis->TicFont;
  LabelFont = Axis->LabelFont;
}

NEWYAXIS::NEWYAXIS(TTGDiagram *diag)
{
  depths = NULL;
  Diag = diag;

  ScaleAutoMin = true;
  ScaleAutoMax = true;
  AxisAutoMin = true;
  AxisAutoMax = true;
  DataAutoMin = true;
  DataAutoMax = true;
  AutoScale = true;
  AutoTic = true;
  //plot = true; // true for primary axis, false for secondary
  NumberOfLevels = 0;
  //AxisType = PRIMARY_AXIS; // SECONDARY_AXIS for secondary
  AxisStyle = STANDARD_AXIS;   // for SECONDARY, set to whatever PRIMARY is
  //units = DEFAULT_UNITS, DEPTH_UNITS, or AGE_UNITS
  LabelPosition = SIDE;  // for SECONDARY, set to whatever PRIMARY is
  TicDecPts = 0;
  MajorTicLength = 0.1;
  MinorTicLength = 0.06;
  LabelToTicDistance = 0.05;
  MinorTics = 0.0;
  MajorTics = 0.0;
  TicLabelDivideBy = 1.0;
  LabelAngle = 45.0;
  //AutoStepMultiplier = 1;   // = 1 for first axis, 2 for second -- used only if AutoTic = true
  LabelYOffset = -0.05;
  SpaceRight = 0.2;
  AxisLength = 10.0;
  XaxisDistance = 0.3;
  ScaleMin = 0.0;  // program calculates if necessary
  ScaleMax = 0.0;
  AxisMin = 0.0;   // calculated if automin = true with AutoAxisMinMax()
                   // only used for primary axis (I think)
  AxisMax = 0.0;
  DataMin = 0.0;
  DataMax = 0.0;
  LineWidth = 0.25;
  Color = clBlack;
  //label  depends on axis
  //AxisCode
  TicFont.Height = 0.35;
  LabelFont.Height = 0.40;
  // yfac =  AxisLength/(AxisMax-AxisMin);  // calculate after getting values for
                                     // AxisMax and AxisMin
                                     // calculate with Calc_yfac()
}

NEWYAXIS::NEWYAXIS(TTGDiagram *diag, int nlevs)
{
  depths = NULL;
  Diag = diag;

  ScaleAutoMin = true;
  ScaleAutoMax = true;
  AxisAutoMin = true;
  AxisAutoMax = true;
  DataAutoMin = true;
  DataAutoMax = true;
  AutoScale = true;
  AutoTic = true;
  Plot = true;  // true for primary axis, false for secondary
  NumberOfLevels = nlevs;
  AxisType = PRIMARY_AXIS; // SECONDARY_AXIS for secondary
  AxisStyle = STANDARD_AXIS;   // for SECONDARY, set to whatever PRIMARY is
  Units = DEFAULT_UNITS;
  LabelPosition = SIDE;  // for SECONDARY, set to whatever PRIMARY is
  TicDecPts = 0;
  MajorTicLength = 0.1;
  MinorTicLength = 0.06;
  LabelToTicDistance = 0.05;
  MinorTics = 0.0;
  MajorTics = 0.0;
  TicLabelDivideBy = 1.0;
  LabelAngle = 45.0;
  AutoStepMultiplier = 1;   // = 1 for first axis, 2 for second -- used only if AutoTic = true
  LabelYOffset = -0.05;
  SpaceRight = 0.2;
  AxisLength = 10.0;
  XaxisDistance = 0.3;
  ScaleMin = 0.0;  // program calculates if necessary
  ScaleMax = 0.0;
  AxisMin = 0.0;   // calculated if automin = true with AutoAxisMinMax()
                   // only used for primary axis (I think)
  AxisMax = 0.0;
  DataMin = 0.0;
  DataMax = 0.0;
  LineWidth = 0.25;
  Color = clBlack;
  AxisCode = "Default";
  TicFont.Height = 0.35;
  LabelFont.Height = 0.40;
  // yfac =  AxisLength/(AxisMax-AxisMin);  // calculate after getting values for
                                     // AxisMax and AxisMin
                                     // calculate with Calc_yfac()
  //yfac =  AxisLength/(AxisMax-AxisMin);
  depths = new double [NumberOfLevels];
}

// this constructor for secondary axes from .til files
NEWYAXIS::NEWYAXIS(UnicodeString& code, UnicodeString& name, TTGDiagram *diag)
{
  AxisCode = code;
  AxisLabel = name;
  AutoStepMultiplier = 2;
  Diag = diag;
  NumberOfLevels = Diag->Levs->Count;
  LabelYOffset = -0.05;
  AxisStyle = STANDARD_AXIS;
  ScaleAutoMin = true;
  ScaleAutoMax = true;
  AxisAutoMin = true;
  AxisAutoMax = true;
  DataAutoMin = true;
  DataAutoMax = true;
  AutoScale = true;
  AutoTic = true;
  Plot = false;
  AxisType = SECONDARY_AXIS;
  Units = (AxisCode.SubString(1,5) == "Chron") ? AGE_UNITS : DEPTH_UNITS;
  LabelPosition = SIDE;
  TicDecPts = 0;
  MajorTicLength = 0.1;
  MinorTicLength = 0.06;
  LabelToTicDistance = 0.05;
  MinorTics = 0.0;
  MajorTics = 0.0;
  TicLabelDivideBy = 1.0;
  LabelAngle = 45.0;

  SpaceRight = 0.2;
  AxisLength = 10.0;
  XaxisDistance = 0.3;
  ScaleMin = 0.0;  // program calculates if necessary
  ScaleMax = 0.0;
  AxisMin = 0.0;   // calculated if automin = true with AutoAxisMinMax()
                   // only used for primary axis (I think)
  AxisMax = 0.0;
  DataMin = 0.0;
  DataMax = 0.0;
  LineWidth = 0.25;
  Color = clBlack;
  TicFont.Height = 0.35;
  LabelFont.Height = 0.40;

  yname_max = 0.0;
  xbase = 0.0;
  xbasec = 0.0;
  xlab = 1000.0;
  ylab = 1000.0;

  depths = new double [NumberOfLevels];
}


NEWYAXIS::~NEWYAXIS()
{
  if (depths != NULL) delete[] depths;
}


void NEWYAXIS::Calc_yfac(void)
{
  //yfac = (AxisLength-(2.0*XaxisDistance))/(AxisMax-AxisMin);
  yfac = AxisLength/(AxisMax-AxisMin);
}


void NEWYAXIS::AutoAxisMinMax(void)
{
  if (Units == DEFAULT_UNITS) {
    if (AxisAutoMin) {
      LEVELS *Lev = (LEVELS*)Diag->Levs->Items[0];
      AxisMin = Lev->num;
      }
    if (AxisAutoMax) {
      LEVELS *Lev = (LEVELS*)Diag->Levs->Items[NumberOfLevels-1];
      AxisMax = Lev->num;
      }
    }
  else {
	for (int i=0; i<Diag->grf->Count; i++) {
	  GRAPH *g = (GRAPH*)Diag->grf->Items[i];
	  if (g->code == AxisCode) {
		if (AxisAutoMin)
		  AxisMin = ((GRAPH*)Diag->grf->Items[i])->data[0].x;
		if (AxisAutoMax)
		  AxisMax = ((GRAPH*)Diag->grf->Items[i])->data[NumberOfLevels-1].x;
		break;
		}
	  }
	}
}
//---------------------------------------------------------------------------

void NEWYAXIS::XMLOUT(WriteXML* xmlout, TList* Fonts)
{
  UnicodeString ustr;
  xmlout->BeginTag("Yaxis");
  xmlout->Element("ScaleAutoMin", ScaleAutoMin);
  xmlout->Element("ScaleAutoMax", ScaleAutoMax);
  xmlout->Element("AxisAutoMin", AxisAutoMin);
  xmlout->Element("AxisAutoMax", AxisAutoMax);
  xmlout->Element("DataAutoMin", DataAutoMin);
  xmlout->Element("DataAutoMax", DataAutoMax);
  xmlout->Element("AutoScale", AutoScale);
  xmlout->Element("AutoTic", AutoTic);
  xmlout->Element("Plot", Plot);
  xmlout->Element("NumberOfLevels", NumberOfLevels);
  switch (AxisType) {
	case PRIMARY_AXIS:   ustr = "PRIMARY";   break;
	case SECONDARY_AXIS: ustr = "SECONDARY"; break;
	}
  xmlout->Element("AxisType", ustr);
  switch (AxisStyle) {
	case STANDARD_AXIS: ustr = "STANDARD"; break;
	case COLUMN_AXIS:   ustr = "COLUMN";   break;
	case NAMES_AXIS:    ustr = "NAMES";    break;
	}
  xmlout->Element("AxisStyle", ustr);
  switch (Units) {
	case DEFAULT_UNITS: ustr = "DEFAULT"; break;
	case DEPTH_UNITS:   ustr = "DEPTH";   break;
	case AGE_UNITS:     ustr = "AGE";     break;
	}
  xmlout->Element("Units", ustr);
  switch (LabelPosition) {
	case SIDE:        ustr = "SIDE";        break;
	case TOP:         ustr = "TOP";         break;
	case USERDEFINED: ustr = "USERDEFINED"; break;
	}
  xmlout->Element("LabelPosition", ustr);
  xmlout->Element("TicDecPts", TicDecPts);
  xmlout->Element("MajorTicLength", MajorTicLength);
  xmlout->Element("MinorTicLength", MinorTicLength);
  xmlout->Element("LabelToTicDistance", LabelToTicDistance);
  xmlout->Element("MinorTics", MinorTics);
  xmlout->Element("MajorTics", MajorTics);
  xmlout->Element("TicLabelDivideBy", TicLabelDivideBy);
  xmlout->Element("LabelAngle", LabelAngle);
  xmlout->Element("AutoStepMultiplier", AutoStepMultiplier);
  xmlout->Element("LabelYOffset", LabelYOffset);
  xmlout->Element("SpaceRight", SpaceRight);
  xmlout->Element("ScaleFactor", yfac);
  xmlout->Element("AxisLength", AxisLength);
  xmlout->Element("XaxisDistance", XaxisDistance);
  xmlout->Element("ScaleMin", ScaleMin);
  xmlout->Element("ScaleMax", ScaleMax);
  xmlout->Element("AxisMin", AxisMin);
  xmlout->Element("AxisMax", AxisMax);
  xmlout->Element("DataMin", DataMin);
  xmlout->Element("DataMax", DataMax);
  xmlout->Element("LineWidth", LineWidth);
  xmlout->Element("Color", ustr.sprintf(L"%08x", Color));
  xmlout->CDATA("YAxisLabel", AxisLabel);
  xmlout->CDATA("YAxisCode", AxisCode);
  xmlout->Element("TicFont", GetFontNumber(Fonts, TicFont));
  xmlout->Element("LabelFont", GetFontNumber(Fonts, LabelFont));
  xmlout->EndTag("Yaxis");
}
//---------------------------------------------------------------------------

void NEWYAXIS::ToggleSAXElement(UnicodeString& Element, TGXXML& tgx, bool toggle)
{
   if (Element == "ScaleAutoMin")
	 tgx.ScaleAutoMin = toggle;
   else if (Element == "ScaleAutoMax")
	 tgx.ScaleAutoMax = toggle;
   else if (Element == "AxisAutoMin")
	 tgx.AxisAutoMin = toggle;
   else if (Element == "AxisAutoMax")
	 tgx.AxisAutoMax = toggle;
   else if (Element == "DataAutoMin")
	 tgx.DataAutoMin = toggle;
   else if (Element == "DataAutoMax")
	 tgx.DataAutoMax = toggle;
   else if (Element == "AutoScale")
	 tgx.AutoScale = toggle;
   else if (Element == "AutoTic")
	 tgx.AutoTic = toggle;
   else if (Element == "Plot")
	 tgx.Plot = toggle;
   else if (Element == "NumberOfLevels")
	 tgx.NumberOfLevels = toggle;
   else if (Element == "AxisType")
	 tgx.AxisType = toggle;
   else if (Element == "AxisStyle")
	 tgx.AxisStyle = toggle;
   else if (Element == "Units")
	 tgx.Units = toggle;
   else if (Element == "LabelPosition")
	 tgx.LabelPosition = toggle;
   else if (Element == "TicDecPts")
	 tgx.TicDecPts = toggle;
   else if (Element == "MajorTicLength")
	 tgx.MajorTicLength = toggle;
   else if (Element == "MinorTicLength")
	 tgx.MinorTicLength = toggle;
   else if (Element == "LabelToTicDistance")
	 tgx.LabelToTicDistance = toggle;
   else if (Element == "MinorTics")
	 tgx.MinorTics = toggle;
   else if (Element == "MajorTics")
	 tgx.MajorTics = toggle;
   else if (Element == "TicLabelDivideBy")
	 tgx.TicLabelDivideBy = toggle;
   else if (Element == "LabelAngle")
	 tgx.LabelAngle = toggle;
   else if (Element == "AutoStepMultiplier")
	 tgx.AutoStepMultiplier = toggle;
   else if (Element == "LabelYOffset")
	 tgx.LabelYOffset = toggle;
   else if (Element == "SpaceRight")
	 tgx.SpaceRight = toggle;
   else if (Element == "ScaleFactor")
	 tgx.ScaleFactor = toggle;
   else if (Element == "AxisLength")
	 tgx.AxisLength = toggle;
   else if (Element == "XaxisDistance")
	 tgx.XaxisDistance = toggle;
   else if (Element == "ScaleMin")
	 tgx.ScaleMin = toggle;
   else if (Element == "ScaleMax")
	 tgx.ScaleMax = toggle;
   else if (Element == "AxisMin")
	 tgx.AxisMin = toggle;
   else if (Element == "AxisMax")
	 tgx.AxisMax = toggle;
   else if (Element == "DataMin")
	 tgx.DataMin = toggle;
   else if (Element == "DataMax")
	 tgx.DataMax = toggle;
   else if (Element == "LineWidth")
	 tgx.LineWidth = toggle;
   else if (Element == "Color")
	 tgx.Color = toggle;
   else if (Element == "YAxisLabel")
	 tgx.YAxisLabel = toggle;
   else if (Element == "YAxisCode")
	 tgx.YAxisCode = toggle;
   else if (Element == "TicFont")
	 tgx.TicFont = toggle;
   else if (Element == "LabelFont")
	 tgx.LabelFont = toggle;
}
//---------------------------------------------------------------------------

void NEWYAXIS::EvaluateXML(UnicodeString& ustr, TGXXML& tgx, TList* Fonts)
{
  if (tgx.ScaleAutoMin)
	ScaleAutoMin = (bool)ustr.ToInt();
  else if (tgx.ScaleAutoMax)
	ScaleAutoMax = (bool)ustr.ToInt();
  else if (tgx.AxisAutoMin)
	AxisAutoMin = (bool)ustr.ToInt();
  else if (tgx.AxisAutoMax)
	AxisAutoMax = (bool)ustr.ToInt();
  else if (tgx.DataAutoMin)
	DataAutoMin = (bool)ustr.ToInt();
  else if (tgx.DataAutoMax)
	DataAutoMax = (bool)ustr.ToInt();
  else if (tgx.AutoScale)
	AutoScale = (bool)ustr.ToInt();
  else if (tgx.AutoTic)
	AutoTic = (bool)ustr.ToInt();
  else if (tgx.Plot)
	Plot = (bool)ustr.ToInt();
  else if (tgx.NumberOfLevels) {
	NumberOfLevels = ustr.ToInt();
	depths = new double [NumberOfLevels];
	}
  else if (tgx.AxisType) {
	if (ustr == "PRIMARY")
	  AxisType = PRIMARY_AXIS;
	else if (ustr == "SECONDARY")
	  AxisType = SECONDARY_AXIS;
	}
  else if (tgx.AxisStyle) {
	if (ustr == "STANDARD")
	  AxisStyle = STANDARD_AXIS;
	else if (ustr == "COLUMN")
	  AxisStyle = COLUMN_AXIS;
	else if (ustr == "NAMES")
	  AxisStyle = NAMES_AXIS;
	}
  else if (tgx.Units) {
	if (ustr == "DEFAULT")
	  Units = DEFAULT_UNITS;
	else if (ustr == "DEPTH")
	  Units = DEPTH_UNITS;
	else if (ustr == "AGE")
	  Units = AGE_UNITS;
	}
  else if (tgx.LabelPosition) {
	if (ustr == "SIDE")
	  LabelPosition = SIDE;
	else if (ustr == "TOP")
	  LabelPosition = TOP;
	else if (ustr == "USERDEFINED")
	  LabelPosition = USERDEFINED;
	}
  else if (tgx.TicDecPts)
	TicDecPts = ustr.ToInt();
  else if (tgx.MajorTicLength)
	MajorTicLength = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.MinorTicLength)
	MinorTicLength = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.LabelToTicDistance)
	LabelToTicDistance = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.MinorTics)
	MinorTics = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.MajorTics)
	MajorTics = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.TicLabelDivideBy)
	TicLabelDivideBy = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.LabelAngle)
	LabelAngle = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.AutoStepMultiplier)
	AutoStepMultiplier = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.LabelYOffset)
	LabelYOffset = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.SpaceRight)
	SpaceRight = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.ScaleFactor)
	yfac = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.AxisLength)
	AxisLength = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.XaxisDistance)
	XaxisDistance = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.ScaleMin)
	ScaleMin = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.ScaleMax)
	ScaleMax = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.AxisMin)
	AxisMin = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.AxisMax)
	AxisMax = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.DataMin)
	DataMin = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.DataMax)
	DataMax = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.LineWidth)
	LineWidth = IntlStrToDouble::GetDouble(ustr);
  else if (tgx.Color) {
	UnicodeString Hex = "0x" + ustr;
	Color = (TColor)Hex.ToInt();
	}
  else if (tgx.YAxisLabel)
	AxisLabel = ustr;
  else if (tgx.YAxisCode)
	AxisCode = ustr;
  else if (tgx.TicFont)
	TicFont = *(MYFONT*)Fonts->Items[ustr.ToInt()];
  else if (tgx.LabelFont)
	LabelFont = *(MYFONT*)Fonts->Items[ustr.ToInt()];
}
//---------------------------------------------------------------------------

bool TTGDiagram::plot_yaxes(void)
{
  if (YAxes->Count == 0) return false;

  NEWYAXIS *Axis1 = (NEWYAXIS*)YAxes->Items[0];
  if (Axis1->Units == DEFAULT_UNITS) {
	for (int i=0; i<Levs->Count; i++) {
	  LEVELS *Lev = (LEVELS*)Levs->Items[i];
	  Axis1->PutDepth(i, Lev->num);
	  }
	}
  else {
	for (int i=0; i<grf->Count; i++) {
	  GRAPH *g = (GRAPH*)grf->Items[i];
	  if (g->code == Axis1->AxisCode) {
		for (int j=0; j<Levs->Count; j++)		      // read data
		  Axis1->PutDepth(j, ((GRAPH*)grf->Items[i])->data[j].x);
		break;
		}
	  }
	}
  for (int i=1; i<Levs->Count; i++) {
	if (Axis1->Depth(i) < Axis1->Depth(i-1)) {
	  MessageDlg("Axis " + Axis1->AxisCode + ":" + Axis1->AxisLabel +
		" not in ascending order. Diagram may be corrupted.", mtWarning, TMsgDlgButtons() << mbOK, 0);
	  }
	}

  if (lopt.On)
    Axis1->xbase = -1.4 - ((Axis1->AxisStyle == STANDARD_AXIS) ? Axis1->SpaceRight : 0.0);
  else
    Axis1->xbase = -Axis1->SpaceRight;

  if (Axis1->AxisStyle == NAMES_AXIS) {
    Axis1->plot_sample_names();
    return true;
    }
  else if (Axis1->Plot)
    Axis1->PlotAxis();
  else
    return false;

  int k = 1;
  while (k < YAxes->Count)   // plot secondary axes
    {
      NEWYAXIS *Axis2 = (NEWYAXIS*)YAxes->Items[k];
      if (!Axis2->Plot) { k++; continue; }

      bool AxisFound = false;

      if (Axis2->Units == DEFAULT_UNITS) {
        for (int i=0; i<Levs->Count; i++) {
          LEVELS *Lev = (LEVELS*)Levs->Items[i];
          Axis2->PutDepth(i, Lev->num);
          }
        AxisFound = true;
        }
      else {
        int i;
        if ((i = getVarNum(Axis2->AxisCode)) > -1)
          AxisFound = true;
        else {
          UnicodeString PoundAxisCode = "#" + Axis2->AxisCode;
          if ((i = getVarNum(PoundAxisCode)) > -1)
            AxisFound = true;
          }
        if (AxisFound) {
          for (int j=0; j<Levs->Count; j++)
            Axis2->PutDepth(j, ((GRAPH*)grf->Items[i])->data[j].x);
          }
        }
      for (int i=1; i<Levs->Count; i++) {
        if (Axis2->Depth(i) < Axis2->Depth(i-1)) {
          MessageDlg("Secondary axis " + Axis2->AxisCode + ":" + Axis2->AxisLabel +
            " not in ascending order. Diagram may be corrupted.", mtWarning, TMsgDlgButtons() << mbOK, 0);
          }
        }

      if (AxisFound) {
        if (Axis2->AxisStyle == STANDARD_AXIS)
		  //Axis2->xbase = ((SEGLIMITS*)Picture->sl->Last())->xmin - 0.2;
		  Axis2->xbase = Picture->sl.back().xmin - 0.2;
		else
		  //Axis2->xbase = ((SEGLIMITS*)Picture->sl->Last())->xmin - ((Axis2->LabelPosition == SIDE) ? 0.2 : 0.0);
		  Axis2->xbase = Picture->sl.back().xmin - ((Axis2->LabelPosition == SIDE) ? 0.2 : 0.0);
        Axis2->PlotAxis();
        }
      k++;
    }
  return true;
}
//---------------------------------------------------------------------------

void NEWYAXIS::PlotAxis(void)
{
  double x[5], y[5];
  double tic_inc, ymax, tic_val, d2;
  double dmin, dmax;
  double max_ll, lentxt;
  double a, b, val1, val2;
  double xtxt;
  UnicodeString TicLabel;
  MyText *Text;
  NEWYAXIS* yaxis1;

  if (AxisType == SECONDARY_AXIS)
    yaxis1 = (NEWYAXIS*)Diag->YAxes->Items[0];

  int idx = Diag->YAxes->IndexOf((NEWYAXIS*)this) + 1;
  UnicodeString AxisName = "Y-Axis " + IntToStr(idx);
  Diag->Picture->NewSegment(AxisName);

  dmin = depths[0];
  dmax = depths[NumberOfLevels-1];

  if (ScaleMax <= ScaleMin) {
    ScaleAutoMin = true;
    ScaleAutoMax = true;
    }

  if (MinorTics == 0.0 || MajorTics == 0.0)
    AutoTic = true;

  if (AutoTic) {        // calculate y-axis step size
    MinorTics = AutoStepMultiplier*auto_step(dmin, dmax);
    MajorTics = MinorTics;
    }

  if (AxisStyle == STANDARD_AXIS)
    {
      if (ScaleAutoMin)	// calculate default y-axis tic-mark minimum
    	{
          switch (AxisType)
          {
          case PRIMARY_AXIS:
       	    ScaleMin = auto_min(dmin, MajorTics);
       	    break;
          case SECONDARY_AXIS:
            ScaleMin = auto_min(dmin, MajorTics);
            while (yaxis1->get_depths1(ScaleMin, this) < yaxis1->ScaleMin)
              ScaleMin += MajorTics;
            break;
          }
        }

      if (ScaleAutoMax)	// calculate default y-axis tic-mark maximum
        {
          switch (AxisType)
          {
          case PRIMARY_AXIS:	// primary axis
            ScaleMax = auto_max(dmax, ScaleMin, MajorTics);
            break;
          case SECONDARY_AXIS:	// secondary axis
            ScaleMax = auto_max(dmax, ScaleMin, MajorTics);
            while (yaxis1->get_depths1(ScaleMax, this) > yaxis1->ScaleMax)
              ScaleMax -= MajorTics;
            break;
          }
        }

      switch (AxisType)
        {
        case PRIMARY_AXIS:		// primary axis
          ytop = Length() - XaxisDistance + yfac*(AxisMin - ScaleMin);
          ybot = ytop - yfac*(ScaleMax - ScaleMin);
          break;
        case SECONDARY_AXIS:		// secondary axis
          if (ScaleAutoMax)
            ybot = yaxis1->ybot;
          else {
            d2 = yaxis1->get_depths1(ScaleMax, this);
            ybot = ywc(d2);
            }
          if (ScaleAutoMin)
            ytop = yaxis1->ytop;
          else {
            d2 = yaxis1->get_depths1(ScaleMin, this);
            ytop = ywc(d2);
            }
          break;
        }
    }
  else		// column axis
    {
      ytop = Length();
      ybot = 0.0;

      switch (AxisType)
      {
      case PRIMARY_AXIS:     // primary axis
        if (ScaleAutoMin)
          {
            ScaleMin = 0.0;
            if (ywc(0.0) > ytop-XaxisDistance)
              while (ywc(ScaleMin) > ytop-XaxisDistance)
                ScaleMin += MinorTics;
            else
	      while (ywc(ScaleMin) < ytop-XaxisDistance)
	        ScaleMin -= MinorTics;
          }
        if (ScaleAutoMax)
	  {
            ScaleMax = ScaleMin + MinorTics;
	    while (ywc(ScaleMax) > ybot)
	      ScaleMax += MinorTics;
	    ScaleMax -= MinorTics;
          }
        break;
      case SECONDARY_AXIS:     // secondary axis
        if (ScaleAutoMin)
          {
            ScaleMin = 0.0;
            if (ywc(0.0) > ytop-XaxisDistance)
              while (ywc(yaxis1->get_depths1(ScaleMin, this)) > ytop-XaxisDistance)
                ScaleMin += MinorTics;
            else
	      while (ywc(yaxis1->get_depths1(ScaleMin, this)) < ytop-XaxisDistance)
                ScaleMin -= MinorTics;
          }
        if (ScaleAutoMax)
	  {
	    ScaleMax = ScaleMin + MinorTics;
            while (ywc(yaxis1->get_depths1(ScaleMax, this)) > ybot)
	      ScaleMax += MinorTics;
	    ScaleMax -= MinorTics;
          }
        break;
      }
    }

  max_ll = 0.0;
  tic_val = ScaleMin;
  tic_inc = MajorTics;	 // tic increment
  ymax = ScaleMax + 0.5*(MinorTics);
  while (tic_val < ymax)     // get max tic label length
    {
      if (eventic(tic_inc, MajorTics, MinorTics))	// label tic
        {
          tic_label(TicDecPts, tic_val, TicLabelDivideBy, TicLabel);
          Text = new MyText(TicFont, TicLabel, Diag->Picture);
          lentxt = Text->Length();
          delete Text;
          if (lentxt > max_ll) max_ll = lentxt;
        }
      tic_val += MinorTics;
      tic_inc += MinorTics;
    }

  // draw scale base line
  y[0] = ytop;
  y[1] = ybot;
  x[0] = x[1] = xbase;
  Diag->Picture->Polyline(2, x, y, Color, LineWidth); 
  if (AxisStyle == COLUMN_AXIS)  {
    xbasec = xbase - max_ll - 2.0*MajorTicLength - 0.2;
    x[0] = x[1] = xbasec;
    Diag->Picture->Polyline(2, x, y, Color, LineWidth);
    }
  else
    xbasec = xbase - MajorTicLength - LabelToTicDistance - max_ll;

  // draw tic marks
  tic_val = ScaleMin;                // tic value in graph units
  tic_inc = MajorTics;           // tic increment

  x[0] = xbase;
  xtxt = (AxisStyle == STANDARD_AXIS) ? xbase-MajorTicLength-LabelToTicDistance :
	 (xbase+xbasec)/2.0;


  while (tic_val < ymax)
    {
      switch (AxisType)
      {
      case PRIMARY_AXIS:
        y[0] = ywc(tic_val);
        break;
      case SECONDARY_AXIS:
        d2 = yaxis1->get_depths1(tic_val, this);
        y[0] = ywc(d2);
        break;
      }
      y[1] = y[0];

      if (eventic(tic_inc, MajorTics, MinorTics))	 // major tic
        {
          x[1] = x[0] - MajorTicLength;
          if (AxisStyle == COLUMN_AXIS)
            {
              x[2] = xbasec;
              x[3] = x[2]+MajorTicLength;
              Diag->Picture->Polyline(2, &x[2], y, Color, LineWidth);
            }
          Diag->Picture->Polyline(2, x, y, Color, LineWidth);
        }
      else	      // minor tic
        {
          x[1] = x[0]-MinorTicLength;
          if (AxisStyle == COLUMN_AXIS)
            {
              x[2] = xbasec;
              x[3] = x[2]+MinorTicLength;
              Diag->Picture->Polyline(2, &x[2], y, Color, LineWidth);
            }
          Diag->Picture->Polyline(2, x, y, Color, LineWidth);
        }

      if (eventic(tic_inc, MajorTics, MinorTics))	// label tic
        {
          tic_label(TicDecPts, tic_val, TicLabelDivideBy, TicLabel);
          if (AxisStyle == COLUMN_AXIS)
            Text = new MyText(xtxt, y[0], TicFont, 0.0, TEXT_CENTER,
                              TEXT_HALF, TicLabel, Diag->Picture);
          else
            Text = new MyText(xtxt, y[0], TicFont, 0.0, TEXT_RIGHT,
                              TEXT_HALF, TicLabel, Diag->Picture);
          Text->TextOut();
          delete Text;
        }
      tic_val += MinorTics;
      tic_inc += MinorTics;
    }

  // plot y-axis label
  double yl;
  switch (abs(LabelPosition))
    {
      case SIDE:
	if (LabelPosition > 0) {
	  xlab = xbasec - 0.2;
          if (AxisType == PRIMARY_AXIS)
            ylab = ((ytop+ybot)/2.0);
          else
            ylab = ((yaxis1->ytop+yaxis1->ybot)/2.0);
	  }


        Text = new MyText(LabelFont, AxisLabel, Diag->Picture);
        lentxt = Text->Length();
        delete Text;

        //ylab -= 0.5*lentxt;
        yl = ylab - 0.5*lentxt;

        Text = new MyText(xlab, yl, LabelFont, 90.0, TEXT_LEFT,
                          TEXT_BOTTOM, AxisLabel, Diag->Picture);
        Text->TextOut();
        delete Text;
        break;
      case TOP:
        if (LabelPosition > 0)
          {
            if (AxisStyle == COLUMN_AXIS)
              //ylab = len;
              ylab = Length();
            else {      // maybe generalize this Default.Xaxis value
       	      //val1 = len + LabelYOffset;
              val1 = Length() + LabelYOffset;
       	      val2 = ytop+0.5*(TicFont.Height + LabelFont.Height);
              ylab = max(val1, val2);
              }
          }
        if (LabelAngle == 0.0)
	  {
	    if (LabelPosition > 0)
	      xlab = xbase;

            Text = new MyText(xlab, ylab, LabelFont, 0.0,
                              TEXT_RIGHT, TEXT_BASE, AxisLabel, Diag->Picture);
            val1 = xbase - MajorTicLength - LabelToTicDistance - max_ll;
            val2 = xlab - Text->Length();
            yname_max = ylab + LabelFont.Height;
          }
        else if (LabelAngle == 90.0)
	  {
	    if (LabelPosition > 0)
	      xlab = (xbase+xbasec)/2.0;

            Text = new MyText(xlab, ylab, LabelFont, 90.0, TEXT_LEFT,
                              TEXT_HALF, AxisLabel, Diag->Picture);
            b = ylab + Text->Length();
            yname_max = b;
	  }
		else
	  {
	    if (LabelPosition > 0)
			  xlab = xbase - MajorTicLength - LabelToTicDistance - 0.8*TicFont.Height;

            Text = new MyText(xlab, ylab, LabelFont, LabelAngle, TEXT_LEFT,
                              TEXT_BASE, AxisLabel, Diag->Picture);
            Text->MaxXY(&a, &b);
            yname_max = b;
          }
        Text->TextOut();
        delete Text;
        break;
    }
  Diag->Picture->CloseSegment();
}


double NEWYAXIS::ywc(double y)
{
  //return(len - XaxisDistance - yfac*(y-AxisMin));
  return(AxisLength + XaxisDistance - yfac*(y-AxisMin));
}

// given Axis1 depths and Axis2 depths, get an Axis1 depth for an Axis2 depth
double NEWYAXIS::get_depths1(double depth2, NEWYAXIS *Axis2)
{
  int i;
  double d2;

  if (depth2 < Axis2->Depth(0))
    d2 = yinterp(Axis2->Depth(0), depths[0], Axis2->Depth(1), depths[1], depth2);
  else if (depth2 == Axis2->Depth(0))
    d2 = depths[0];
  else
    {
      for (i=1; i<NumberOfLevels; i++)
	if (Axis2->Depth(i) > depth2)
	  break;

      if (i < NumberOfLevels)
	d2 = yinterp(Axis2->Depth(i-1), depths[i-1], Axis2->Depth(i), depths[i], depth2);
      else
	d2 = yinterp(Axis2->Depth(NumberOfLevels-2), depths[NumberOfLevels-2],
		     Axis2->Depth(NumberOfLevels-1), depths[NumberOfLevels-1], depth2);
    }
  return(d2);
}

// write tic label to buffer
void NEWYAXIS::tic_label(int TicDecPts, double value, double factor, UnicodeString& AxisLabel)
{
  double tic;

  tic = value*factor;
  if (TicDecPts == 0)
    AxisLabel = IntToStr((int)tic);
  else
    AxisLabel = FormatFloat(FloatFormat(TicDecPts), tic);
}

// void function plot_sample_names(double, double *, double *)
// plots sample names
void NEWYAXIS::plot_sample_names(void)
{
  int i;
  double lentxt, maxlentxt, xtxt, ytxt;
  MyText *Text;

  int idx = Diag->YAxes->IndexOf((NEWYAXIS*)this) + 1;
  UnicodeString AxisName = "Y-Axis " + IntToStr(idx);
  Diag->Picture->NewSegment(AxisName);

  maxlentxt = 0.0;
  for (i=0; i<NumberOfLevels; i++) {
    LEVELS *Lev = (LEVELS*)Diag->Levs->Items[i];
    Text = new MyText(TicFont, Lev->name, Diag->Picture);
    if ((lentxt = Text->Length()) > maxlentxt)
      maxlentxt = lentxt;
    delete Text;
    }

  xtxt = -0.2;
  if (Diag->lopt.On)
    xtxt -= 1.4;

  for (i=0; i<NumberOfLevels; i++)  {   // plot sample names
    // convert depth to world coordinates
    ytxt = AxisLength + XaxisDistance - yfac*(depths[i]-AxisMin);
    LEVELS *Lev = (LEVELS*)Diag->Levs->Items[i];
    Text = new MyText(xtxt, ytxt, TicFont, 0.0, TEXT_RIGHT,
                      TEXT_HALF, Lev->name, Diag->Picture);
    Text->TextOut();
    delete Text;
    }

  // plot y-axis label
  switch (abs(LabelPosition))
    {
      case SIDE:
	if (LabelPosition > 0) {
	  xlab = -0.4 - maxlentxt;
          ylab = AxisLength + XaxisDistance - yfac*((0.5*(depths[0]+depths[NumberOfLevels-1]))-AxisMin);
	  }
        Text = new MyText(xlab, ylab, LabelFont, 90.0, TEXT_CENTER,
                          TEXT_BOTTOM, AxisLabel, Diag->Picture);
        Text->TextOut();
        delete Text;
     	break;
      case TOP:
    	if (LabelPosition > 0) {
	  xlab = -0.2 - 0.5*maxlentxt;
          if (Diag->lopt.On)
            xlab -= 1.4;
          ylab = Length() + LabelYOffset;
          ytxt = AxisLength + XaxisDistance - yfac*(depths[0]-AxisMin) + 0.5*TicFont.Height;
	  if (ylab-ytxt < 0.2) ylab = ytxt+0.2;
	  }
     	if (LabelAngle == 0.0) {
          Text = new MyText(xlab, ylab, LabelFont, 0.0, TEXT_CENTER, TEXT_BASE,
                            AxisLabel, Diag->Picture);
          if (xlab+0.5*Text->Length() > -0.1) {
	    xlab = -0.1-0.5*Text->Length();
            Text->SetXY(xlab, ylab);
            }
          }
    	else if (LabelAngle == 90.0)
          Text = new MyText(xlab, ylab, LabelFont, 90.0, TEXT_LEFT, TEXT_HALF,
                            AxisLabel, Diag->Picture);
    	else
          Text = new MyText(xlab, ylab, LabelFont, LabelAngle, TEXT_LEFT, TEXT_BASE,
                            AxisLabel, Diag->Picture);
        Text->TextOut();
        delete Text;
    	break;
    }
  Diag->Picture->CloseSegment();
}

