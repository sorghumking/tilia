//---------------------------------------------------------------------------
#include <vcl.h>
#include "pch.h"
#pragma hdrstop

#ifndef TGDiagrmH
#include "TGDiagrm.h"
#endif
#include "TGPLith.h"
#ifndef TGraphicH
#include "TGraphic.h"
#endif
#ifndef TGTextH
#include "TGText.h"
#endif
#ifndef TGYaxisH
#include "TGYaxis.h"
#endif
#ifndef TGUtilsH
#include "TGUtils.h"
#endif

//---------------------------------------------------------------------------
#pragma package(smart_init)


// void function plot_lith_boxes(void)
// plots lith boxes on bottom of diagram
void TTGDiagram::plot_lith_boxes(void)
{
  int i, pos;
  bool startleft;
  vector<double> x(5, 0.0);
  vector<double> y(5, 0.0);
  double bottom, xtxt, ytxt, lentxt, end, begin, begin0, top;
  UnicodeString Buffer1;
  UnicodeString Buffer2;
  LITHCOMPONENT tlith;
  MyText *Text;
  LithPatt *lpat;

  tlith.XShift = 0.0;
  tlith.YShift = 0.0;

  end = 0.0;
  if (LithKeys->Count > 0)
    {
      Picture->NewSegment("LithBoxes");

      startleft = true;
      begin0 = 0.0;
      top = Picture->MinExtentY() - 0.2;
      bottom = top - 0.666667*lopt.BoxWidth - 0.2 - 1.5*lopt.KeyFont.Height;

      for (i=0; i<LithKeys->Count; i++)
        {
          LITHKEY* LithKey = (LITHKEY*)LithKeys->Items[i];
          if (! LithKey->Plot) continue;
          Text = new MyText(lopt.KeyFont, LithKey->LithLabel, Picture);
          lentxt = Text->Length();
          delete Text;

          if (i > 0 && end > Picture->MaxExtentX() && LithKey->AutoX) {
            top = bottom - 0.5;
            bottom = top - 0.666667*lopt.BoxWidth - 0.2 - 1.5*lopt.KeyFont.Height;
            startleft = true;
            }

          if (! LithKey->AutoX)
            x[0] = x[3] = x[4] = LithKey->x;
          else  {
            if (startleft) {
              x[0] = x[3] = x[4] = 0.0;
              startleft = false;
              }
            else {
              begin = min(x[1]+lopt.BoxWidth, x[1]+1.5*lopt.BoxWidth-0.5*lentxt);
              if (begin < end+0.5) {
                begin = end+0.5;
                if (lentxt > lopt.BoxWidth)
                  begin += (0.5*lentxt - 0.5*lopt.BoxWidth);
                }
              x[0] = x[3] = x[4] = begin;
              }
            }
          x[1] = x[2] = x[0]+ lopt.BoxWidth;

          if (startleft) {
            begin0 = min(begin0, begin0+0.5*lopt.BoxWidth-0.5*lentxt);
            startleft = false;
            }

          if (LithKey->AutoY)
            y[0] = y[1] = y[4] = top;
          else
            y[0] = y[1] = y[4] = LithKey->y;
          y[2] = y[3] = y[0] - 0.666667*lopt.BoxWidth;

          // truncate to 2 decimal places
          LithKey->x = (double)nint(100.0*x[0])/100.0;
          LithKey->y = (double)nint(100.0*y[0])/100.0;

          LithKey->AutoX = false;
          LithKey->AutoY = false;

          tlith.LithCode = LithKey->GetLithCode();
          tlith.Humo = LithKey->GetHumo();
          tlith.Color = LithKey->Color;

          lpat = new LithPatt(&tlith, x, y, lopt.LithLineWidth, Picture);
          lpat->PlotPattern();
          delete lpat;

		  Picture->Polyline(5, x.begin(), y.begin(), LithKey->Color, lopt.KeyLineWidth);

          xtxt = x[0] + 0.5*lopt.BoxWidth;
          ytxt = y[2] - 0.2;

		  if (LithKey->LithLabel.Pos("\\") == 0) {
            MyText *Text = new MyText(xtxt, ytxt, lopt.KeyFont, 0.0,
                            TEXT_CENTER, TEXT_CAP, LithKey->LithLabel, Picture);
            Text->TextOut();
            delete Text;
            }
          else {
            Buffer1 = LithKey->LithLabel;
            while (! Buffer1.IsEmpty()) {
              if ((pos = Buffer1.Pos("\\")) > 0) {
                Buffer2 = Buffer1.SubString(1, pos-1);
                Buffer1.Delete(1, pos);
                }
              else {
                Buffer2 = Buffer1;
                Buffer1.SetLength(0);
                }

              MyText *Text = new MyText(xtxt, ytxt, lopt.KeyFont, 0.0,
                         TEXT_CENTER, TEXT_CAP, Buffer2, Picture);
              Text->TextOut();
              delete Text;

              ytxt -= 1.3*lopt.KeyFont.Height;
              }
            }

          end = max(x[1], x[0] + 0.5*lopt.BoxWidth + 0.5*lentxt);
        }

      Picture->CloseSegment();

      //TODO: write_options();  deal with this in TG for Windows
    }

}


// void function plot_lith(double)
// plots lithology column
void TTGDiagram::plot_lith(double yfac)
{
  int i;
  int horz_align, vert_align;
  vector<double> x(5, 0.0);
  vector<double> y(5, 0.0);
  double xtxt, ytxt, left;
  LithPatt *lpat;

  NEWYAXIS *Axis1 = (NEWYAXIS*)YAxes->Items[0];

  Picture->NewSegment("Lithology");

  left = -1.4;
  xtxt = -0.8;

  // plot lithology patterns
  if (Lithology->Count > 0)
    {
      x[0] = x[3] = x[4] = left;
      x[1] = x[2] = -0.2;
      for (i=0; i<Lithology->Count; i++) {
        LITHUNIT* Lith = (LITHUNIT*)Lithology->Items[i];
        for (int j=0; j<Lith->Components->Count; j++) {
          LITHCOMPONENT *Component = (LITHCOMPONENT *)Lith->Components->Items[j];
          if (Component->LithCode > 0) {
            y[0] = y[1] = y[4] = Axis1->Length() - 0.3 - yfac*(Lith->Top-Axis1->AxisMin);
            y[2] = y[3] = Axis1->Length() - 0.3 - yfac*(Lith->Bot-Axis1->AxisMin);
			lpat = new LithPatt(Component, x, y, lopt.LithLineWidth, Picture);
            lpat->PlotPattern();
            delete lpat;
            }
          }
        }
    }

  // plot vertical border lines

  if (Axis1->AxisStyle == COLUMN_AXIS) {
    y[0] = Axis1->Length();
    y[1] = 0.0;
    }
  else {
    y[0] = (lopt.AutoTopDepth) ? (Axis1->Length()-0.3) :
           (Axis1->Length()-0.3-yfac*(lopt.TopDepth-Axis1->AxisMin));
    y[1] = (lopt.AutoBotDepth) ? 0.3 :
           (Axis1->Length()-0.3-yfac*(lopt.BotDepth-Axis1->AxisMin));
    }
  double yColTop = y[0];  // save for column label

  x[0] = x[1] = -0.2;
  Picture->Polyline(2, x.begin(), y.begin(), lopt.DefaultColor, lopt.ColumnLineWidth);
  x[0] = x[1] = left;
  Picture->Polyline(2, x.begin(), y.begin(), lopt.DefaultColor, lopt.ColumnLineWidth);

  // plot zone boundaries

  if (Lithology->Count > 0) {
    x[0] = left;
    x[1] = -0.2;
    for (i=0; i<Lithology->Count; i++) {
      LITHUNIT* Lith = (LITHUNIT*)Lithology->Items[i];
      if (Lith->LoBound) {
        y[0] = y[1] = Axis1->Length() - 0.3 - yfac*(Lith->Bot-Axis1->AxisMin);
		Picture->Polyline(2, x.begin(), y.begin(), Lith->LoBoundColor, lopt.BoundaryLineWidth);
        }
      }
    }

  bool TextBottom = false;
  if (Axis1->Length()-yColTop < 0.3) {
    ytxt = yColTop + 0.1;
    TextBottom = true;
    }
  else
    ytxt = Axis1->Length() + ((Axis1->AxisStyle == COLUMN_AXIS) ? 0.0 : Default.Xaxis.GraphNameYOffset);

  if (lopt.Angle == 0.0) {
    horz_align = TEXT_CENTER;
    vert_align = (TextBottom) ? TEXT_BOTTOM : TEXT_BASE;
    }
  else if (lopt.Angle == 90.0) {
    horz_align = TEXT_LEFT;
    vert_align = TEXT_HALF;
    }
  else {
    horz_align = TEXT_LEFT;
    vert_align = TEXT_BASE;
    }
  MyText *Text = new MyText(xtxt, ytxt, lopt.LithTitleFont, lopt.Angle,
                            horz_align, vert_align, lopt.LithTitle, Picture);
  Text->TextOut();
  delete Text;

  Picture->CloseSegment();
}


//LithPatt::LithPatt(LITHCOMPONENT *L, double *X, double *Y, double lw, MyGraphics *pic)
LithPatt::LithPatt(LITHCOMPONENT *L, vector<double>& X, vector<double>& Y, double lw, MyGraphics *pic)
{
  Component = L;
  //xr = X;
  xr.assign(X.begin(), X.end());
  //yr = Y;
  yr.assign(Y.begin(), Y.end());
  left = X[0];
  right = X[1];
  top = Y[0];
  bot = Y[2];
  line_width = lw;
  default_line_width = lw;
  Picture = pic;
  rightadjust = 0.0;
  topadjust = 0.0;
  xshiftadjust = 0.0;
  yshiftadjust = 0.0;
}


// plots lith pattern
void LithPatt::PlotPattern(void)
{
  switch (Component->LithCode)
    {
      case 34: TSSh1(); break;
      case 35: TSSh2(); break;
      case 36: TSSh3(); break;
      case 37: TSSh4(); break;
      case 38: TSTb1(); break;
      case 39: TSTb2(); break;
      case 40: TSTb3(); break;
      case 41: TSTb4(); break;
      case 42: TSTbS1(); break;
      case 43: TSTbS2(); break;
      case 44: TSTbS3(); break;
      case 45: TSTbS4(); break;
      case 46: TSTbSc1(); break;
      case 47: TSTbSc2(); break;
      case 48: TSTbSc3(); break;
      case 49: TSTbSc4(); break;
      case 50: TSTl1(); break;
      case 51: TSTl2(); break;
      case 52: TSTl3(); break;
      case 53: TSTl4(); break;
      case 54: TSTh1(); break;
      case 55: TSTh2(); break;
      case 56: TSTh3(); break;
      case 57: TSTh4(); break;
      case 58: TSTh41(); break;
      case 59: TSTh42(); break;
      case 60: TSTh43(); break;
      case 61: TSTh44(); break;
      case 62: TSDl1(); break;
      case 63: TSDl2(); break;
      case 64: TSDl3(); break;
      case 65: TSDl4(); break;
      case 66: TSDh1(); break;
      case 67: TSDh2(); break;
      case 68: TSDh3(); break;
      case 69: TSDh4(); break;
      case 70: TSDg1(); break;
      case 71: TSDg2(); break;
      case 72: TSDg3(); break;
      case 73: TSDg4(); break;
      case 74: TSLd1(); break;
      case 75: TSLd2(); break;
      case 76: TSLd3(); break;
      case 77: TSLd4(); break;
      case 78: TSLso1(); break;
      case 79: TSLso2(); break;
      case 80: TSLso3(); break;
      case 81: TSLso4(); break;
      case 82: TSLc1(); break;
      case 83: TSLc2(); break;
      case 84: TSLc3(); break;
      case 85: TSLc4(); break;
      case 86: TSLf1(); break;
      case 87: TSLf2(); break;
      case 88: TSLf3(); break;
      case 89: TSLf4(); break;
      case 90: TSAs1(); break;
      case 91: TSAs2(); break;
      case 92: TSAs3(); break;
      case 93: TSAs4(); break;
      case 94: TSAg1(); break;
      case 95: TSAg2(); break;
      case 96: TSAg3(); break;
      case 97: TSAg4(); break;
      case 98: TSGa1(); break;
      case 99: TSGa2(); break;
      case 100: TSGa3(); break;
      case 101: TSGa4(); break;
      case 102: TSGs1(); break;
      case 103: TSGs2(); break;
      case 104: TSGs3(); break;
      case 105: TSGs4(); break;
      case 106: TSGg_min1(); break;
      case 107: TSGg_min2(); break;
      case 108: TSGg_min3(); break;
      case 109: TSGg_min4(); break;
      case 110: TSGg_maj1(); break;
      case 111: TSGg_maj2(); break;
      case 112: TSGg_maj3(); break;
      case 113: TSGg_maj4(); break;
      case 114: TStest1(); break;
      case 115: TStest2(); break;
      case 116: TStest3(); break;
      case 117: TStest4(); break;
      case 118: TSptest1(); break;
      case 119: TSptest2(); break;
      case 120: TSptest3(); break;
      case 121: TSptest4(); break;
      case 122: TSCortSec1(); break;
      case 123: TSCortSec2(); break;
      case 124: TSCortSec3(); break;
      case 125: TSCortSec4(); break;
      case 126: TSCort1(); break;
      case 127: TSCort2(); break;
      case 128: TSCort3(); break;
      case 129: TSCort4(); break;
      default:
		Picture->Polygon(5, xr, yr, 0, -1, Component->Color, PATTERN_FILL,
                         Component->LithCode);
        break;
	}
}

void LithPatt::SetHumoLineWidth(void)
{
  //line_width = 0.25 + 0.25*Component->Humo;
  line_width += 0.25*Component->Humo;
}

void LithPatt::xoffsets(int count, ...)
{
   ns = count;
   xoff = new double [count];
   va_list offsets;
   va_start(offsets, count);
   for (int i=0; i<count; i++)
     xoff[i] = va_arg(offsets, double);
   va_end(offsets);
}

void LithPatt::yoffsets(int count, ...)
{
   yoff = new double [count];
   va_list offsets;
   va_start(offsets, count);
   for (int i=0; i<count; i++)
     yoff[i] = va_arg(offsets, double);
   va_end(offsets);
}

void LithPatt::xset(int count, ...)
{
   n = count;
   x = new double [count];
   va_list vals;
   va_start(vals, count);
   for (int i=0; i<count; i++)
     x[i] = va_arg(vals, double);
   va_end(offsets);
}

void LithPatt::yset(int count, ...)
{
   y = new double [count];
   va_list vals;
   va_start(vals, count);
   for (int i=0; i<count; i++)
     y[i] = va_arg(vals, double);
   va_end(offsets);
}

void LithPatt::cleanup(void)
{
  delete[] xoff;
  delete[] yoff;
  delete[] x;
  delete[] y;
}

//---------------------------------------------------------------------------
// Substantia humosa 1
void LithPatt::TSSh1(void)
{
  xoffsets(2, 0.00, 0.08);      // no of symbols, and x origins
  yoffsets(2, 0.00, -0.12);     // no of symbols, and y origins
  xset(2, 0.00, 0.08);          // x coordinates of symbol
  yset(2, 0.00, 0.00);          // y coordinates of symbol
  Troels_Smith(TSLINE, 0.16, 0.24);
}
//---------------------------------------------------------------------------

// Substantia humosa 2
void LithPatt::TSSh2(void)
{
  xoffsets(2, 0.00, 0.08);
  yoffsets(2, 0.00, -0.08);
  xset(2, 0.00, 0.08);
  yset(2, 0.00, 0.00);
  Troels_Smith(TSLINE, 0.16, 0.16);
}
//---------------------------------------------------------------------------

// Substantia humosa 3
void LithPatt::TSSh3(void)
{
  xoffsets(2, 0.00, 0.08);
  yoffsets(2, 0.0, -0.04);
  xset(2, 0.00, 0.08);
  yset(2, 0.00, 0.00);
  Troels_Smith(TSLINE, 0.16, 0.08);
}
//---------------------------------------------------------------------------

// Substantia humosa 4
void LithPatt::TSSh4(void)
{
  xoffsets(2, 0.00, -0.06);
  yoffsets(2, 0.00, -0.04);
  xset(2, 0.00, 0.08);
  yset(2, 0.00, 0.00);
  rightadjust = 0.08;                  // for clipping
  Troels_Smith(TSLINE, 0.12, 0.08);
}
//---------------------------------------------------------------------------

// Turfa bryophytica 1
void LithPatt::TSTb1(void)
{
  xoffsets(9, 0.02, 0.34, 0.66, 0.98, -0.16, 0.18, 0.50, 0.82, 1.14 );
  yoffsets(9, 0.00, 0.00, 0.00, 0.00, -0.24, -0.24, -0.24, -0.24, -0.24 );
  xset(14, 0.000, 0.001, 0.005, 0.010, 0.020, 0.030, 0.040, 0.160, 0.170, 0.180,
           0.190, 0.195, 0.199, 0.200 );
  yset(14, 0.000, -0.010, -0.020, -0.027, -0.035, -0.039, -0.040, -0.040,
          -0.041, -0.045, -0.053, -0.060, -0.070, -0.080);
  SetHumoLineWidth();
  Troels_Smith(TSLINE, 1.20, 0.48);
}
//---------------------------------------------------------------------------

// Turfa bryophytica 2
void LithPatt::TSTb2(void)
{
  xoffsets(9, 0.02, 0.34, 0.66, 0.98, -0.16, 0.18, 0.50, 0.82, 1.14);
  yoffsets(9, 0.00, 0.00, 0.00, 0.00, -0.16, -0.16, -0.16, -0.16, -0.16);
  xset(14, 0.000, 0.001, 0.005, 0.010, 0.020, 0.030, 0.040, 0.160, 0.170, 0.180,
           0.190, 0.195, 0.199, 0.200 );
  yset(14, 0.000, -0.010, -0.020, -0.027, -0.035, -0.039, -0.040, -0.040,
          -0.041, -0.045, -0.053, -0.060, -0.070, -0.080);
  SetHumoLineWidth();
  Troels_Smith(TSLINE, 1.20, 0.32);
  // The reason this is 1.20 rather than 0.32 is that there are 9 complete
  // symbols plotted. Otherwise there would have to be 3 different ones.
}
//---------------------------------------------------------------------------

// Turfa bryophytica 3
void LithPatt::TSTb3(void)
{
  xoffsets(9, 0.02, 0.34, 0.66, 0.98, -0.16, 0.18, 0.50, 0.82, 1.14);
  yoffsets(9, 0.00, 0.00, 0.00, 0.00, -0.08, -0.08, -0.08, -0.08, -0.08);
  xset(14, 0.000, 0.001, 0.005, 0.010, 0.020, 0.030, 0.040, 0.160, 0.170, 0.180,
           0.190, 0.195, 0.199, 0.200 );
  yset(14, 0.000, -0.010, -0.020, -0.027, -0.035, -0.039, -0.040, -0.040,
          -0.041, -0.045, -0.053, -0.060, -0.070, -0.080);
  SetHumoLineWidth();
  Troels_Smith(TSLINE, 1.20, 0.16);
}
//---------------------------------------------------------------------------

// Turfa bryophytica 4
void LithPatt::TSTb4(void)
{
  xoffsets(11, 0.02, 0.26, 0.50, 0.74, 0.98, -0.10,  0.14,  0.38,  0.62,  0.86,  1.10);
  yoffsets(11, 0.00, 0.00, 0.00, 0.00, 0.00, -0.08, -0.08, -0.08, -0.08, -0.08, -0.08);
  xset(14, 0.000, 0.001, 0.005, 0.010, 0.020, 0.030, 0.040, 0.160, 0.170, 0.180,
           0.190, 0.195, 0.199, 0.200 );
  yset(14, 0.000, -0.010, -0.020, -0.027, -0.035, -0.039, -0.040, -0.040,
          -0.041, -0.045, -0.053, -0.060, -0.070, -0.080);
  SetHumoLineWidth();
  Troels_Smith(TSLINE, 1.20, 0.16);
}
//---------------------------------------------------------------------------

// Turfa bryophytica (Sphagni) 1
void LithPatt::TSTbS1(void)
{
  SetHumoLineWidth();
  xoffsets(2, 0.0, 0.6);
  yoffsets(2, 0.0, 0.0);
  xset(27, 0.04, 0.06, 0.08, 0.10, 0.12, 0.14, 0.16, 0.18, 0.20, 0.22, 0.24,
           0.26, 0.28, 0.30, 0.32, 0.34, 0.36, 0.38, 0.40, 0.42, 0.44, 0.46,
           0.48, 0.50, 0.52, 0.54, 0.56);
  yset(27, -0.003, -0.008, -0.013, -0.020, -0.028, -0.036, -0.044, -0.052,
           -0.060, -0.067, -0.072, -0.077, -0.079, -0.080, -0.079, -0.077,
           -0.072, -0.067, -0.060, -0.052, -0.044, -0.036, -0.028, -0.020,
           -0.013, -0.008, -0.003);
  Troels_Smith(TSLINE, 0.6, 0.64);

  xoffsets(2, 0.0, 0.6);
  yoffsets(2, -0.32, -0.32);
  xset(14, 0.00, 0.02, 0.04, 0.06, 0.08, 0.10, 0.12, 0.14, 0.16, 0.18, 0.20,
           0.22, 0.24, 0.26);
  yset(14, -0.000, -0.001, -0.003, -0.008, -0.013, -0.020, -0.028, -0.036,
           -0.044, -0.052, -0.060, -0.067, -0.072, -0.077);
  Troels_Smith(TSLINE, 0.6, 0.64);

  xoffsets(2, 0.0, 0.6);
  yoffsets(2, -0.32, -0.32);
  xset(14, 0.34, 0.36, 0.38, 0.40, 0.42, 0.44, 0.46, 0.48, 0.50, 0.52, 0.54,
           0.56, 0.58, 0.60);
  yset(14, -0.077, -0.072, -0.067, -0.060, -0.052, -0.044, -0.036, -0.028,
           -0.020, -0.013, -0.008, -0.003, -0.001, -0.000);
  Troels_Smith(TSLINE, 0.6, 0.64);
}
//---------------------------------------------------------------------------

// Turfa bryophytica (Sphagni) 2
void LithPatt::TSTbS2(void)
{
  SetHumoLineWidth();

  xoffsets(2, 0.0, 0.6);
  yoffsets(2, 0.0, 0.0);
  xset(27, 0.04, 0.06, 0.08, 0.10, 0.12, 0.14, 0.16, 0.18, 0.20, 0.22, 0.24,
           0.26, 0.28, 0.30, 0.32, 0.34, 0.36, 0.38, 0.40, 0.42, 0.44, 0.46,
           0.48, 0.50, 0.52, 0.54, 0.56);
  yset(27, -0.003, -0.008, -0.013, -0.020, -0.028, -0.036, -0.044, -0.052,
           -0.060, -0.067, -0.072, -0.077, -0.079, -0.080, -0.079, -0.077,
           -0.072, -0.067, -0.060, -0.052, -0.044, -0.036, -0.028, -0.020,
           -0.013, -0.008, -0.003);
  Troels_Smith(TSLINE, 0.6, 0.32);

  xoffsets(2, 0.0, 0.6);
  yoffsets(2, -0.16, -0.16);
  xset(14, 0.00, 0.02, 0.04, 0.06, 0.08, 0.10, 0.12, 0.14, 0.16, 0.18, 0.20,
           0.22, 0.24, 0.26);
  yset(14, -0.000, -0.001, -0.003, -0.008, -0.013, -0.020, -0.028, -0.036,
           -0.044, -0.052, -0.060, -0.067, -0.072, -0.077);
  Troels_Smith(TSLINE, 0.6, 0.32);

  xoffsets(2, 0.0, 0.6);
  yoffsets(2, -0.16, -0.16);
  xset(14, 0.34, 0.36, 0.38, 0.40, 0.42, 0.44, 0.46, 0.48, 0.50, 0.52, 0.54,
           0.56, 0.58, 0.60);
  yset(14, -0.077, -0.072, -0.067, -0.060, -0.052, -0.044, -0.036, -0.028,
           -0.020, -0.013, -0.008, -0.003, -0.001, -0.000);
  Troels_Smith(TSLINE, 0.6, 0.32);
}
//---------------------------------------------------------------------------

// Turfa bryophytica (Sphagni) 3
void LithPatt::TSTbS3(void)
{
  SetHumoLineWidth();

  xoffsets(2, 0.0, 0.6);
  yoffsets(2, 0.0, 0.0);
  xset(27, 0.04, 0.06, 0.08, 0.10, 0.12, 0.14, 0.16, 0.18, 0.20, 0.22, 0.24,
           0.26, 0.28, 0.30, 0.32, 0.34, 0.36, 0.38, 0.40, 0.42, 0.44, 0.46,
           0.48, 0.50, 0.52, 0.54, 0.56);
  yset(27, -0.003, -0.008, -0.013, -0.020, -0.028, -0.036, -0.044, -0.052,
           -0.060, -0.067, -0.072, -0.077, -0.079, -0.080, -0.079, -0.077,
           -0.072, -0.067, -0.060, -0.052, -0.044, -0.036, -0.028, -0.020,
           -0.013, -0.008, -0.003);
  Troels_Smith(TSLINE, 0.6, 0.16);

  xoffsets(2, 0.0, 0.6);
  yoffsets(2, -0.08, -0.08);
  xset(14, 0.00, 0.02, 0.04, 0.06, 0.08, 0.10, 0.12, 0.14, 0.16, 0.18, 0.20,
           0.22, 0.24, 0.26);
  yset(14, -0.000, -0.001, -0.003, -0.008, -0.013, -0.020, -0.028, -0.036,
           -0.044, -0.052, -0.060, -0.067, -0.072, -0.077);
  Troels_Smith(TSLINE, 0.6, 0.16);

  xoffsets(2, 0.0, 0.6);
  yoffsets(2, -0.08, -0.08);
  xset(14, 0.34, 0.36, 0.38, 0.40, 0.42, 0.44, 0.46, 0.48, 0.50, 0.52, 0.54,
           0.56, 0.58, 0.60);
  yset(14, -0.077, -0.072, -0.067, -0.060, -0.052, -0.044, -0.036, -0.028,
           -0.020, -0.013, -0.008, -0.003, -0.001, -0.000);
  Troels_Smith(TSLINE, 0.6, 0.16);
}
//---------------------------------------------------------------------------

// Turfa bryophytica (Sphagni) 4
void LithPatt::TSTbS4(void)
{
  SetHumoLineWidth();
  yshiftadjust = 0.04;

  xoffsets(2, 0.0, 0.6);
  yoffsets(2, 0.0, 0.0);
  xset(27, 0.04, 0.06, 0.08, 0.10, 0.12, 0.14, 0.16, 0.18, 0.20, 0.22, 0.24,
           0.26, 0.28, 0.30, 0.32, 0.34, 0.36, 0.38, 0.40, 0.42, 0.44, 0.46,
           0.48, 0.50, 0.52, 0.54, 0.56);
  yset(27, -0.003, -0.008, -0.013, -0.020, -0.028, -0.036, -0.044, -0.052,
           -0.060, -0.067, -0.072, -0.077, -0.079, -0.080, -0.079, -0.077,
           -0.072, -0.067, -0.060, -0.052, -0.044, -0.036, -0.028, -0.020,
           -0.013, -0.008, -0.003);
  Troels_Smith(TSLINE, 0.6, 0.08);

  xoffsets(2, 0.0, 0.6);
  yoffsets(2, -0.04, -0.04);
  xset(14, 0.00, 0.02, 0.04, 0.06, 0.08, 0.10, 0.12, 0.14, 0.16, 0.18, 0.20,
           0.22, 0.24, 0.26);
  yset(14, -0.000, -0.001, -0.003, -0.008, -0.013, -0.020, -0.028, -0.036,
           -0.044, -0.052, -0.060, -0.067, -0.072, -0.077);
  Troels_Smith(TSLINE, 0.6, 0.08);

  xoffsets(2, 0.0, 0.6);
  yoffsets(2, -0.04, -0.04);
  xset(14, 0.34, 0.36, 0.38, 0.40, 0.42, 0.44, 0.46, 0.48, 0.50, 0.52, 0.54,
           0.56, 0.58, 0.60);
  yset(14, -0.077, -0.072, -0.067, -0.060, -0.052, -0.044, -0.036, -0.028,
           -0.020, -0.013, -0.008, -0.003, -0.001, -0.000);
  Troels_Smith(TSLINE, 0.6, 0.08);
}
//---------------------------------------------------------------------------

// Turfa bryophytica (Sphagni cuspidati) 1
void LithPatt::TSTbSc1(void)
{
  xoffsets(2, 0.0, 0.6);
  yoffsets(2, 0.0, 0.0);
  xset(31, 0.00, 0.02, 0.04, 0.06, 0.08, 0.10, 0.12, 0.14, 0.16, 0.18, 0.20,
           0.22, 0.24, 0.26, 0.28, 0.30, 0.32, 0.34, 0.36, 0.38, 0.40, 0.42,
           0.44, 0.46, 0.48, 0.50, 0.52, 0.54, 0.56, 0.58, 0.60);
  yset(31, -0.000, -0.001, -0.003, -0.008, -0.013, -0.020, -0.028, -0.036,
           -0.044, -0.052, -0.060, -0.067, -0.072, -0.077, -0.079, -0.080,
           -0.079, -0.077, -0.072, -0.067, -0.060, -0.052, -0.044, -0.036,
           -0.028, -0.020, -0.013, -0.008, -0.003, -0.001, -0.000);
  SetHumoLineWidth();
  Troels_Smith(TSLINE, 0.6, 0.32);
}
//---------------------------------------------------------------------------

// Turfa bryophytica (Sphagni cuspidati) 2
void LithPatt::TSTbSc2(void)
{
  xoffsets(2, 0.0, 0.6);
  yoffsets(2, 0.0, 0.0);
  xset(31, 0.00, 0.02, 0.04, 0.06, 0.08, 0.10, 0.12, 0.14, 0.16, 0.18, 0.20,
           0.22, 0.24, 0.26, 0.28, 0.30, 0.32, 0.34, 0.36, 0.38, 0.40, 0.42,
           0.44, 0.46, 0.48, 0.50, 0.52, 0.54, 0.56, 0.58, 0.60);
  yset(31, -0.000, -0.001, -0.003, -0.008, -0.013, -0.020, -0.028, -0.036,
           -0.044, -0.052, -0.060, -0.067, -0.072, -0.077, -0.079, -0.080,
           -0.079, -0.077, -0.072, -0.067, -0.060, -0.052, -0.044, -0.036,
           -0.028, -0.020, -0.013, -0.008, -0.003, -0.001, -0.000);
  SetHumoLineWidth();
  Troels_Smith(TSLINE, 0.6, 0.16);
}
//---------------------------------------------------------------------------

// Turfa bryophytica (Sphagni cuspidati) 3
void LithPatt::TSTbSc3(void)
{
  xoffsets(2, 0.0, 0.6);
  yoffsets(2, 0.0, 0.0);
  xset(31, 0.00, 0.02, 0.04, 0.06, 0.08, 0.10, 0.12, 0.14, 0.16, 0.18, 0.20,
           0.22, 0.24, 0.26, 0.28, 0.30, 0.32, 0.34, 0.36, 0.38, 0.40, 0.42,
           0.44, 0.46, 0.48, 0.50, 0.52, 0.54, 0.56, 0.58, 0.60);
  yset(31, -0.000, -0.001, -0.003, -0.008, -0.013, -0.020, -0.028, -0.036,
           -0.044, -0.052, -0.060, -0.067, -0.072, -0.077, -0.079, -0.080,
           -0.079, -0.077, -0.072, -0.067, -0.060, -0.052, -0.044, -0.036,
           -0.028, -0.020, -0.013, -0.008, -0.003, -0.001, -0.000);
  SetHumoLineWidth();
  Troels_Smith(TSLINE, 0.6, 0.08);
}
//---------------------------------------------------------------------------

// Turfa bryophytica (Sphagni cuspidati) 4
void LithPatt::TSTbSc4(void)
{
  xoffsets(2, 0.0, 0.6);
  yoffsets(2, 0.0, 0.0);
  xset(31, 0.00, 0.02, 0.04, 0.06, 0.08, 0.10, 0.12, 0.14, 0.16, 0.18, 0.20,
           0.22, 0.24, 0.26, 0.28, 0.30, 0.32, 0.34, 0.36, 0.38, 0.40, 0.42,
           0.44, 0.46, 0.48, 0.50, 0.52, 0.54, 0.56, 0.58, 0.60);
  yset(31, -0.000, -0.001, -0.003, -0.008, -0.013, -0.020, -0.028, -0.036,
           -0.044, -0.052, -0.060, -0.067, -0.072, -0.077, -0.079, -0.080,
           -0.079, -0.077, -0.072, -0.067, -0.060, -0.052, -0.044, -0.036,
           -0.028, -0.020, -0.013, -0.008, -0.003, -0.001, -0.000);
  SetHumoLineWidth();
  //yshiftadjust = 0.04;
  yshiftadjust = 0.02;
  topadjust = 0.02;
  Troels_Smith(TSLINE, 0.6, 0.04);
}
//---------------------------------------------------------------------------

// Turfa lignosa 1
void LithPatt::TSTl1(void)
{
  xoffsets(2, 0.08, 0.32);
  yoffsets(2, -0.00, -0.24);
  xset(3, 0.0, 0.045, 0.09);
  yset(3, 0.0, -0.09, 0.0);
  SetHumoLineWidth();
  Troels_Smith(TSLINE, 0.48, 0.48);
}
//---------------------------------------------------------------------------

// Turfa lignosa 2
void LithPatt::TSTl2(void)
{
  xoffsets(2, 0.06, 0.26);
  yoffsets(2, -0.0, -0.2);
  xset(3, 0.0, 0.045, 0.09);
  yset(3, 0.0, -0.09, 0.0);
  SetHumoLineWidth();
  Troels_Smith(TSLINE, 0.4, 0.4);
}
//---------------------------------------------------------------------------

// Turfa lignosa 3
void LithPatt::TSTl3(void)
{
  xoffsets(2, 0.08, 0.24);
  yoffsets(2, -0.0, -0.16);
  xset(3, 0.0, 0.045, 0.09);
  yset(3, 0.0, -0.09, 0.0);
  SetHumoLineWidth();
  Troels_Smith(TSLINE, 0.33, 0.32);
}
//---------------------------------------------------------------------------

// Turfa lignosa 4
void LithPatt::TSTl4(void)
{
  xoffsets(2, -0.08, 0.01);
  yoffsets(2, -0.0, -0.16);
  xset(3, 0.0, 0.045, 0.09);
  yset(3, 0.0, -0.09, 0.0);
  SetHumoLineWidth();
  Troels_Smith(TSLINE, 0.18, 0.32);
}
//---------------------------------------------------------------------------

// Turfa herbacea 1
void LithPatt::TSTh1(void)
{
  xoffsets(2, 0.00, 0.12);
  yoffsets(2, 0.00, -0.08);
  xset(2, 0.0, 0.0);
  yset(2, 0.0, -0.08);
  SetHumoLineWidth();
  Troels_Smith(TSLINE, 0.24, 0.16);
}
//---------------------------------------------------------------------------

// Turfa herbacea 2
void LithPatt::TSTh2(void)
{
  xoffsets(2, 0.00, 0.08);
  yoffsets(2, 0.00, -0.08);
  xset(2, 0.0, 0.0);
  yset(2, 0.0, -0.08);
  SetHumoLineWidth();
  Troels_Smith(TSLINE, 0.16, 0.16);
}
//---------------------------------------------------------------------------

// Turfa herbacea 3
void LithPatt::TSTh3(void)
{
  //xoffsets(2, 0.00, 0.08);
  xoffsets(2, 0.00, 0.04);
  yoffsets(2, 0.00, -0.08);
  xset(2, 0.0, 0.0);
  yset(2, 0.0, -0.08);
  SetHumoLineWidth();
  Troels_Smith(TSLINE, 0.08, 0.16);
}
//---------------------------------------------------------------------------

// Turfa herbacea 4
void LithPatt::TSTh4(void)
{
  xoffsets(2, 0.00, 0.04);
  yoffsets(2, 0.02, -0.04);
  xset(2, 0.0, 0.0);
  yset(2, 0.0, -0.08);
  SetHumoLineWidth();
  Troels_Smith(TSLINE, 0.08, 0.12);
}
//---------------------------------------------------------------------------

// Turfa herbacea 4-1
void LithPatt::TSTh41(void)
{
  xoffsets(1, 0.0);
  yoffsets(1, 0.0);
  xset(2, 0.0, 0.0);
  yset(2, 0.0, -0.4);
  SetHumoLineWidth();
  Troels_Smith(TSLINE, 0.12, 0.40);
}
//---------------------------------------------------------------------------

// Turfa herbacea 4-2
void LithPatt::TSTh42(void)
{
  xoffsets(1, 0.0);
  yoffsets(1, 0.0);
  xset(2, 0.0, 0.0);
  yset(2, 0.0, -0.4);
  SetHumoLineWidth();
  Troels_Smith(TSLINE, 0.08, 0.40);
}
//---------------------------------------------------------------------------

// Turfa herbacea 4-3
void LithPatt::TSTh43(void)
{
  xoffsets(1, 0.0);
  yoffsets(1, 0.0);
  xset(2, 0.0, 0.0);
  yset(2, 0.0, -0.4);
  SetHumoLineWidth();
  Troels_Smith(TSLINE, 0.06, 0.40);
}
//---------------------------------------------------------------------------

// Turfa herbacea 4-4
void LithPatt::TSTh44(void)
{
  xoffsets(1, 0.0);
  yoffsets(1, 0.0);
  xset(2, 0.0, 0.0);
  yset(2, 0.0, -0.4);
  SetHumoLineWidth();
  Troels_Smith(TSLINE, 0.04, 0.40);
}
//---------------------------------------------------------------------------

// Detritus lignosus 1
void LithPatt::TSDl1(void)
{
  xoffsets(1, 0.04);
  yoffsets(1, 0.00);
  xset(7, 0.000,  0.006,  0.110,  0.120,  0.114, 0.010, 0.000);
  yset(7, -0.008, -0.020, -0.056, -0.048, -0.036, 0.000, -0.008);
  Troels_Smith(TSAREA, 0.5, 0.48);

  xoffsets(1, 0.29);
  yoffsets(1, -0.24);
  xset(7, 0.000, 0.010, 0.114, 0.120, 0.110, 0.006, 0.000);
  yset(7, -0.048, -0.056, -0.020, -0.008, 0.000, -0.036, -0.048);
  Troels_Smith(TSAREA, 0.5, 0.48);
}
//---------------------------------------------------------------------------

// Detritus lignosus 2
void LithPatt::TSDl2(void)
{
  xoffsets(1, 0.08);
  yoffsets(1, 0.00);
  xset(7, 0.000, 0.006, 0.114, 0.120, 0.114, 0.006, 0.000);
  yset(7, 0.000, -0.008, -0.044, -0.040, -0.032, 0.004, 0.000);
  Troels_Smith(TSAREA, 0.32, 0.32);

  xoffsets(1, -0.08);
  yoffsets(1, -0.16);
  xset(7, 0.000, 0.006, 0.114, 0.120, 0.114, 0.006, 0.000);
  yset(7, -0.040, -0.044, -0.008, 0.000, 0.004, -0.032, -0.040);
  Troels_Smith(TSAREA, 0.32, 0.32);
}
//---------------------------------------------------------------------------

// Detritus lignosus 3
void LithPatt::TSDl3(void)
{
  xoffsets(1, 0.12);
  yoffsets(1, 0.00);
  xset(7, 0.000, 0.006, 0.114, 0.120, 0.114, 0.006, 0.000);
  yset(7, 0.000, -0.008, -0.044, -0.040, -0.032, 0.004, 0.000);
  Troels_Smith(TSAREA, 0.24, 0.24);

  xoffsets(1, 0.00);
  yoffsets(1, -0.12);
  xset(7, 0.000, 0.006, 0.114, 0.120, 0.114, 0.006, 0.000);
  yset(7, -0.040, -0.044, -0.008, 0.000, 0.004, -0.032, -0.040);
  Troels_Smith(TSAREA, 0.24, 0.24);
}
//---------------------------------------------------------------------------

// Detritus lignosus 4
void LithPatt::TSDl4(void)
{
  xoffsets(1, -0.04);
  yoffsets(1, 0.00);
  xset(7, 0.000, 0.006, 0.114, 0.120, 0.114, 0.006, 0.000);
  yset(7, 0.000, -0.008, -0.044, -0.040, -0.032, 0.004, 0.000);
  Troels_Smith(TSAREA, 0.16, 0.16);

  xoffsets(1, 0.04);
  yoffsets(1, -0.08);
  xset(7, 0.000, 0.006, 0.114, 0.120, 0.114, 0.006, 0.000);
  yset(7, -0.040, -0.044, -0.008, 0.000, 0.004, -0.032, -0.040);
  Troels_Smith(TSAREA, 0.16, 0.16);
}
//---------------------------------------------------------------------------

// Detritus herbosus 1        
void LithPatt::TSDh1(void)
{
  xoffsets(1, 0.04);
  yoffsets(1, 0.00);
  xset(4, 0.00, 0.12, 0.12, 0.00);
  yset(4, 0.00, -0.08, -0.04, 0.00);
  Troels_Smith(TSAREA, 0.5, 0.48);

  xoffsets(1, 0.29);
  yoffsets(1, -0.24);
  xset(4, 0.00, 0.12, 0.12, 0.00);
  yset(4, -0.08, -0.04, 0.00, -0.08);
  Troels_Smith(TSAREA, 0.5, 0.48);
}
//---------------------------------------------------------------------------

// Detritus herbosus 2
void LithPatt::TSDh2(void)
{
  xoffsets(1, 0.08);
  yoffsets(1, 0.00);
  xset(4, 0.00, 0.12, 0.12, 0.00);
  yset(4, 0.00, -0.08, -0.04, 0.00);
  Troels_Smith(TSAREA, 0.32, 0.32);

  xoffsets(1, -0.08);
  yoffsets(1, -0.16);
  xset(4, 0.00, 0.12, 0.12, 0.00);
  yset(4, -0.08, -0.04, 0.00, -0.08);
  Troels_Smith(TSAREA, 0.32, 0.32);
}
//---------------------------------------------------------------------------

// Detritus herbosus 3
void LithPatt::TSDh3(void)
{
  xoffsets(1, 0.12);
  yoffsets(1, 0.00);
  xset(4, 0.00, 0.12, 0.12, 0.00);
  yset(4, 0.00, -0.08, -0.04, 0.00);
  Troels_Smith(TSAREA, 0.24, 0.24);

  xoffsets(1, 0.00);
  yoffsets(1, -0.12);
  xset(4, 0.00, 0.12, 0.12, 0.00);
  yset(4, -0.08, -0.04, 0.00, -0.08);
  Troels_Smith(TSAREA, 0.24, 0.24);
}
//---------------------------------------------------------------------------

// Detritus herbosus 4
void LithPatt::TSDh4(void)
{
  xoffsets(1, -0.04);
  yoffsets(1, 0.00);
  xset(4, 0.00, 0.12, 0.12, 0.00);
  yset(4, 0.00, -0.08, -0.04, 0.00);
  Troels_Smith(TSAREA, 0.16, 0.16);

  xoffsets(1, 0.04);
  yoffsets(1, -0.08);
  xset(4, 0.00, 0.12, 0.12, 0.00);
  yset(4, -0.08, -0.04, 0.00, -0.08);
  Troels_Smith(TSAREA, 0.16, 0.16);
}
//---------------------------------------------------------------------------

// Detritus granosus 1
void LithPatt::TSDg1(void)
{
  xoffsets(1, 0.04);
  yoffsets(1, 0.00);
  xset(2, 0.00, 0.12);
  yset(2, 0.00, -0.08);
  Troels_Smith(TSLINE, 0.5, 0.48);

  xoffsets(1, 0.29);
  yoffsets(1, -0.24);
  xset(2, 0.00, 0.12);
  yset(2, -0.08, 0.00);
  Troels_Smith(TSLINE, 0.5, 0.48);
}
//---------------------------------------------------------------------------

// Detritus granosus 2
void LithPatt::TSDg2(void)
{
  xoffsets(1, 0.08);
  yoffsets(1, 0.00);
  xset(2, 0.00, 0.12);
  yset(2, 0.00, -0.08);
  Troels_Smith(TSLINE, 0.32, 0.32);

  xoffsets(1, -0.08);
  yoffsets(1, -0.16);
  xset(2, 0.00, 0.12);
  yset(2, -0.08, 0.00);
  Troels_Smith(TSLINE, 0.32, 0.32);
}
//---------------------------------------------------------------------------

// Detritus granosus 3
void LithPatt::TSDg3(void)
{
  xoffsets(1, 0.12);
  yoffsets(1, 0.00);
  xset(2, 0.00, 0.12);
  yset(2, 0.00, -0.08);
  Troels_Smith(TSLINE, 0.24, 0.24);

  xoffsets(1, 0.00);
  yoffsets(1, -0.12);
  xset(2, 0.00, 0.12);
  yset(2, -0.08, 0.00);
  Troels_Smith(TSLINE, 0.24, 0.24);
}
//---------------------------------------------------------------------------

// Detritus granosus 4
void LithPatt::TSDg4(void)
{
  xoffsets(1, -0.04);
  yoffsets(1, 0.00);
  xset(2, 0.00, 0.12);
  yset(2, 0.00, -0.08);
  Troels_Smith(TSLINE, 0.16, 0.16);

  xoffsets(1, 0.04);
  yoffsets(1, -0.08);
  xset(2, 0.00, 0.12);
  yset(2, -0.08, 0.00);
  Troels_Smith(TSLINE, 0.16, 0.16);
}
//---------------------------------------------------------------------------

// Limus 1
void LithPatt::TSLd1(void)
{
  SetHumoLineWidth();

  xoffsets(1, 0.0);
  yoffsets(1, 0.0);
  xset(2, 0.00, 0.48);
  yset(2, 0.00, -0.48);
  Troels_Smith(TSLINE, 0.48, 0.48);

  xoffsets(1, 0.0);
  yoffsets(1, 0.0);
  xset(2, 0.00, 0.48);
  yset(2, -0.48, 0.00);
  Troels_Smith(TSLINE, 0.48, 0.48);
}
//---------------------------------------------------------------------------

// Limus 2
void LithPatt::TSLd2(void)
{
  SetHumoLineWidth();

  xoffsets(1, 0.0);
  yoffsets(1, 0.0);
  xset(2, 0.00, 0.32);
  yset(2, 0.00, -0.32);
  Troels_Smith(TSLINE, 0.32, 0.32);

  xoffsets(1, 0.0);
  yoffsets(1, 0.0);
  xset(2, 0.00, 0.32);
  yset(2, -0.32, 0.00);
  Troels_Smith(TSLINE, 0.32, 0.32);
}
//---------------------------------------------------------------------------

// Limus 3
void LithPatt::TSLd3(void)
{
  SetHumoLineWidth();

  xoffsets(1, 0.0);
  yoffsets(1, 0.0);
  xset(2, 0.00, 0.20);
  yset(2, 0.00, -0.20);
  Troels_Smith(TSLINE, 0.20, 0.20);

  xoffsets(1, 0.0);
  yoffsets(1, 0.0);
  xset(2, 0.00, 0.20);
  yset(2, -0.20, 0.00);
  Troels_Smith(TSLINE, 0.20, 0.20);
}
//---------------------------------------------------------------------------

// Limus 4
void LithPatt::TSLd4(void)
{
  SetHumoLineWidth();

  xoffsets(1, 0.0);
  yoffsets(1, 0.0);
  xset(2, 0.00, 0.12);
  yset(2, 0.00, -0.12);
  Troels_Smith(TSLINE, 0.12, 0.12);

  xoffsets(1, 0.0);
  yoffsets(1, 0.0);
  xset(2, 0.00, 0.12);
  yset(2, -0.12, 0.00);
  Troels_Smith(TSLINE, 0.12, 0.12);
}
//---------------------------------------------------------------------------

// Limus siliceus organogenes 1
void LithPatt::TSLso1(void)
{
  xoffsets(1, 0.0);
  yoffsets(1, 0.0);
  xset(2, 0.0,  0.6);
  yset(2, -0.3, -0.3);
  Troels_Smith(TSLINE, 0.6, 0.6);

  xoffsets(1, 0.0);
  yoffsets(1, 0.0);
  xset(2, 0.3,  0.3);
  yset(2, 0.0, -0.6);
  Troels_Smith(TSLINE, 0.6, 0.6);
}
//---------------------------------------------------------------------------

// Limus siliceus organogenes 2
void LithPatt::TSLso2(void)
{
  //xshiftadjust = -0.04;

  xoffsets(1, 0.0);
  yoffsets(1, 0.0);
  xset(2, 0.00,  0.16);
  yset(2, 0.0, 0.0);
  Troels_Smith(TSLINE, 0.16, 0.16);

  xoffsets(1, 0.0);
  yoffsets(1, 0.0);
  xset(2, 0.12,  0.12);
  yset(2, 0.00, -0.16);
  Troels_Smith(TSLINE, 0.16, 0.16);
}
//---------------------------------------------------------------------------

// Limus siliceus organogenes 3
void LithPatt::TSLso3(void)
{
  xoffsets(1, 0.0);
  yoffsets(1, 0.0);
  xset(2, 0.00,  0.12);
  yset(2, 0.0, 0.0);
  Troels_Smith(TSLINE, 0.12, 0.12);

  xoffsets(1, 0.0);
  yoffsets(1, 0.0);
  xset(2, 0.00,  0.00);
  yset(2, 0.00, -0.12);
  Troels_Smith(TSLINE, 0.12, 0.12);
}
//---------------------------------------------------------------------------

// Limus siliceus organogenes 4
void LithPatt::TSLso4(void)
{
  xoffsets(1, 0.0);
  yoffsets(1, 0.0);
  xset(2, 0.00,  0.08);
  yset(2, 0.0, 0.0);
  Troels_Smith(TSLINE, 0.08, 0.08);

  xoffsets(1, 0.0);
  yoffsets(1, 0.0);
  xset(2, 0.00,  0.00);
  yset(2, 0.00, -0.08);
  Troels_Smith(TSLINE, 0.08, 0.08);
}
//---------------------------------------------------------------------------

// Limus calcareus 1
void LithPatt::TSLc1(void)
{
  xoffsets(2, 0.06, 0.26);
  yoffsets(2, 0.00, 0.20);
  xset(27, 0.000, 0.000, 0.001, 0.005, 0.013, 0.022, 0.030, 0.040, 0.050, 0.058,
           0.067, 0.075, 0.079, 0.080, 0.080, 0.060, 0.060, 0.058, 0.054, 0.048,
           0.040, 0.032, 0.026, 0.022, 0.020, 0.020, 0.000);
  yset(27, 0.000, -0.040, -0.050, -0.060, -0.070, -0.076, -0.079, -0.080,
          -0.079, -0.076, -0.070, -0.060, -0.050, -0.040,  0.000,  0.000,
          -0.040, -0.050, -0.055, -0.059, -0.060, -0.059, -0.055, -0.050,
          -0.040,  0.000,  0.000);
  Troels_Smith(TSAREA, 0.4, 0.4);
}
//---------------------------------------------------------------------------

// Limus calcareus 2
void LithPatt::TSLc2(void)
{
  xoffsets(2, 0.00, 0.16);
  yoffsets(2, 0.00, -0.16);
  xset(27, 0.000, 0.000, 0.001, 0.005, 0.013, 0.022, 0.030, 0.040, 0.050, 0.058,
           0.067, 0.075, 0.079, 0.080, 0.080, 0.060, 0.060, 0.058, 0.054, 0.048,
           0.040, 0.032, 0.026, 0.022, 0.020, 0.020, 0.000);
  yset(27, 0.000, -0.040, -0.050, -0.060, -0.070, -0.076, -0.079, -0.080,
          -0.079, -0.076, -0.070, -0.060, -0.050, -0.040,  0.000,  0.000,
          -0.040, -0.050, -0.055, -0.059, -0.060, -0.059, -0.055, -0.050,
          -0.040,  0.000,  0.000);
  Troels_Smith(TSAREA, 0.32, 0.32);
}
//---------------------------------------------------------------------------

// Limus calcareus 3
void LithPatt::TSLc3(void)
{
  xoffsets(2, 0.00, 0.08);
  yoffsets(2, 0.00, -0.16);
  xset(27, 0.000, 0.000, 0.001, 0.005, 0.013, 0.022, 0.030, 0.040, 0.050, 0.058,
           0.067, 0.075, 0.079, 0.080, 0.080, 0.060, 0.060, 0.058, 0.054, 0.048,
           0.040, 0.032, 0.026, 0.022, 0.020, 0.020, 0.000);
  yset(27, 0.000, -0.040, -0.050, -0.060, -0.070, -0.076, -0.079, -0.080,
          -0.079, -0.076, -0.070, -0.060, -0.050, -0.040,  0.000,  0.000,
          -0.040, -0.050, -0.055, -0.059, -0.060, -0.059, -0.055, -0.050,
          -0.040,  0.000,  0.000);
  Troels_Smith(TSAREA, 0.16, 0.32);
}
//---------------------------------------------------------------------------

// Limus calcareus 4
void LithPatt::TSLc4(void)
{
  xoffsets(2, 0.01, 0.11);
  yoffsets(2, 0.00, -0.08);
  xset(27, 0.000, 0.000, 0.001, 0.005, 0.013, 0.022, 0.030, 0.040, 0.050, 0.058,
           0.067, 0.075, 0.079, 0.080, 0.080, 0.060, 0.060, 0.058, 0.054, 0.048,
           0.040, 0.032, 0.026, 0.022, 0.020, 0.020, 0.000);
  yset(27, 0.000, -0.040, -0.050, -0.060, -0.070, -0.076, -0.079, -0.080,
          -0.079, -0.076, -0.070, -0.060, -0.050, -0.040,  0.000,  0.000,
          -0.040, -0.050, -0.055, -0.059, -0.060, -0.059, -0.055, -0.050,
          -0.040,  0.000,  0.000);
  Troels_Smith(TSAREA, 0.20, 0.16);
}
//---------------------------------------------------------------------------

// Limus ferrugineus 1
void LithPatt::TSLf1(void)
{
  xoffsets(2,  0.06,  0.26);
  yoffsets(2,  0.00, -0.20);
  xset(2,  0.0000,  0.0900);
  yset(2, -0.0450, -0.0450);
  Troels_Smith(TSLINE, 0.4, 0.4);

  xoffsets(2, 0.06,  0.26);
  yoffsets(2, 0.00, -0.20);
  xset(2, 0.0450,  0.0450);
  yset(2, 0.0000, -0.0900);
  Troels_Smith(TSLINE, 0.4, 0.4);

  xoffsets(2, 0.06,  0.26);
  yoffsets(2, 0.00, -0.20);
  xset(2,  0.0132,  0.0768);
  yset(2, -0.0768, -0.0132);
  Troels_Smith(TSLINE, 0.4, 0.4);

  xoffsets(2, 0.06,  0.26);
  yoffsets(2, 0.00, -0.20);
  xset(2,  0.0132,  0.0768);
  yset(2, -0.0132, -0.0768);
  Troels_Smith(TSLINE, 0.4, 0.4);
}
//---------------------------------------------------------------------------

// Limus ferrugineus 2
void LithPatt::TSLf2(void)
{
  xoffsets(2, 0.00,  0.16);
  yoffsets(2, 0.00, -0.16);
  xset(2,  0.0000,  0.0900);
  yset(2, -0.0450, -0.0450);
  Troels_Smith(TSLINE, 0.32, 0.32);

  xoffsets(2, 0.00,  0.16);
  yoffsets(2, 0.00, -0.16);
  xset(2, 0.0450,  0.0450);
  yset(2, 0.0000, -0.0900);
  Troels_Smith(TSLINE, 0.32, 0.32);

  xoffsets(2, 0.00,  0.16);
  yoffsets(2, 0.00, -0.16);
  xset(2,  0.0132,  0.0768);
  yset(2, -0.0768, -0.0132);
  Troels_Smith(TSLINE, 0.32, 0.32);

  xoffsets(2, 0.00,  0.16);
  yoffsets(2, 0.00, -0.16);
  xset(2,  0.0132,  0.0768);
  yset(2, -0.0132, -0.0768);
  Troels_Smith(TSLINE, 0.32, 0.32);
}
//---------------------------------------------------------------------------

// Limus ferrugineus 3
void LithPatt::TSLf3(void)
{
  xoffsets(2, 0.02,  0.14);
  yoffsets(2, 0.00, -0.12);
  xset(2,  0.0000,  0.0900);
  yset(2, -0.0450, -0.0450);
  Troels_Smith(TSLINE, 0.24, 0.24);

  xoffsets(2, 0.02,  0.14);
  yoffsets(2, 0.00, -0.12);
  xset(2, 0.0450,  0.0450);
  yset(2, 0.0000, -0.0900);
  Troels_Smith(TSLINE, 0.24, 0.24);

  xoffsets(2, 0.02,  0.14);
  yoffsets(2, 0.00, -0.12);
  xset(2,  0.0132,  0.0768);
  yset(2, -0.0768, -0.0132);
  Troels_Smith(TSLINE, 0.24, 0.24);

  xoffsets(2, 0.02,  0.14);
  yoffsets(2, 0.00, -0.12);
  xset(2,  0.0132,  0.0768);
  yset(2, -0.0132, -0.0768);
  Troels_Smith(TSLINE, 0.24, 0.24);
}
//---------------------------------------------------------------------------

// Limus ferrugineus 4
void LithPatt::TSLf4(void)
{
  xoffsets(2, -0.01, 0.07);
  yoffsets(2,  0.00, 0.08);
  xset(2,  0.0000,  0.0900);
  yset(2, -0.0450, -0.0450);
  Troels_Smith(TSLINE, 0.16, 0.16);

  xoffsets(2, -0.01, 0.07);
  yoffsets(2,  0.00, 0.08);
  xset(2, 0.0450,  0.0450);
  yset(2, 0.0000, -0.0900);
  Troels_Smith(TSLINE, 0.16, 0.16);

  xoffsets(2, -0.01, 0.07);
  yoffsets(2,  0.00, 0.08);
  xset(2,  0.0132,  0.0768);
  yset(2, -0.0768, -0.0132);
  Troels_Smith(TSLINE, 0.16, 0.16);

  xoffsets(2, -0.01, 0.07);
  yoffsets(2,  0.00, 0.08);
  xset(2,  0.0132,  0.0768);
  yset(2, -0.0132, -0.0768);
  Troels_Smith(TSLINE, 0.16, 0.16);
}
//---------------------------------------------------------------------------

// Argilla steatodes 1
void LithPatt::TSAs1(void)
{
  xoffsets(2, 0.06, 0.26);
  yoffsets(2, 0.00, -0.20);
  xset(7, 0.00,  0.00,  0.08,  0.08,  0.02,  0.02,  0.00);
  yset(7, 0.00, -0.12, -0.12, -0.10, -0.10,  0.00,  0.00);
  Troels_Smith(TSAREA, 0.4, 0.4);
}
//---------------------------------------------------------------------------

// Argilla steatodes 2
void LithPatt::TSAs2(void)
{
  xoffsets(2, 0.08, 0.24);
  yoffsets(2, 0.00, -0.16);
  xset(7, 0.00,  0.00,  0.08,  0.08,  0.02,  0.02,  0.00);
  yset(7, 0.00, -0.12, -0.12, -0.10, -0.10,  0.00,  0.00);
  Troels_Smith(TSAREA, 0.32, 0.32);
}
//---------------------------------------------------------------------------

// Argilla steatodes 3
void LithPatt::TSAs3(void)
{
  xoffsets(2, 0.08, 0.00);
  yoffsets(2, 0.00, -0.16);
  xset(7, 0.00,  0.00,  0.08,  0.08,  0.02,  0.02,  0.00);
  yset(7, 0.00, -0.12, -0.12, -0.10, -0.10,  0.00,  0.00);
  Troels_Smith(TSAREA, 0.16, 0.32);
}
//---------------------------------------------------------------------------

// Argilla steatodes 4
void LithPatt::TSAs4(void)
{
  rightadjust = 0.04;
  xoffsets(5, 0.00,  0.08, -0.04,  0.04,  0.12);
  yoffsets(5, 0.00,  0.08, -0.24, -0.16, -0.08);
  xset(7, 0.00,  0.00,  0.08,  0.08,  0.02,  0.02,  0.00);
  yset(7, 0.00, -0.12, -0.12, -0.10, -0.10,  0.00,  0.00);
  Troels_Smith(TSAREA, 0.20, 0.40);
}
//---------------------------------------------------------------------------

// Argilla granosa 1
void LithPatt::TSAg1(void)
{
  xoffsets(2, 0.06,  0.26);
  yoffsets(2, 0.00, -0.20);
  xset(3, 0.00,  0.00,  0.08);
  yset(3, 0.00, -0.12, -0.12);
  Troels_Smith(TSLINE, 0.4, 0.4);
}
//---------------------------------------------------------------------------

// Argilla granosa 2
void LithPatt::TSAg2(void)
{
  xoffsets(2, 0.08,  0.24);
  yoffsets(2, 0.00, -0.16);
  xset(3, 0.00,  0.00,  0.08);
  yset(3, 0.00, -0.12, -0.12);
  Troels_Smith(TSLINE, 0.32, 0.32);
}
//---------------------------------------------------------------------------

// Argilla granosa 3
void LithPatt::TSAg3(void)
{
  xoffsets(2, 0.08,  0.00);
  yoffsets(2, 0.00, -0.16);
  xset(3, 0.00,  0.00,  0.08);
  yset(3, 0.00, -0.12, -0.12);
  Troels_Smith(TSLINE, 0.16, 0.32);
}
//---------------------------------------------------------------------------
// Argilla granosa 4
void LithPatt::TSAg4(void)
{
  rightadjust = 0.04;
  //xoffsets(5, 0.00,  0.08, -0.04,  0.04,  0.12);
  xoffsets(5, 0.00,  0.08, -0.04,  0.04,  0.12);
  yoffsets(5, 0.00,  0.08, -0.24, -0.16, -0.08);
  xset(3, 0.00,  0.00,  0.08);
  yset(3, 0.00, -0.12, -0.12);
  Troels_Smith(TSLINE, 0.20, 0.40);
}
//---------------------------------------------------------------------------

// Grana arenosa 1
void LithPatt::TSGa1(void)
{
  xoffsets(2, -0.015,  0.085);
  yoffsets(2,  0.000, -0.100);
  xset(2,  0.00, 0.03);
  yset(2, -0.03, 0.00);
  rightadjust = 0.03;
  Troels_Smith(TSSOLIDCIRCLE, 0.2, 0.2);
}
//---------------------------------------------------------------------------
// Grana arenosa 2
void LithPatt::TSGa2(void)
{
  xoffsets(2,  0.065, -0.015);
  yoffsets(2, 0.00, -0.08);
  xset(2,  0.00, 0.03);
  yset(2, -0.03, 0.00);
  rightadjust = 0.03;
  Troels_Smith(TSSOLIDCIRCLE, 0.16, 0.16);
}
//---------------------------------------------------------------------------
// Grana arenosa 3
void LithPatt::TSGa3(void)
{
  xoffsets(2,  0.045, -0.015);
  yoffsets(2, 0.00, -0.06);
  xset(2,  0.00, 0.03);
  yset(2, -0.03, 0.00);
  rightadjust = 0.03;
  Troels_Smith(TSSOLIDCIRCLE, 0.12, 0.12);
}
//---------------------------------------------------------------------------
// Grana arenosa 4
void LithPatt::TSGa4(void)
{
  xoffsets(2,  0.025, -0.015);
  yoffsets(2, 0.00, -0.04);
  xset(2,  0.00, 0.03);
  yset(2, -0.03, 0.00);
  rightadjust = 0.03;
  Troels_Smith(TSSOLIDCIRCLE, 0.08, 0.08);
}
//---------------------------------------------------------------------------
// Grana saburralia 1
void LithPatt::TSGs1(void)
{
  xoffsets(2,  0.075,  0.275);
  yoffsets(2, -0.00, -0.20);
  xset(2,  0.00, 0.05);
  yset(2, -0.05, 0.00);
  rightadjust = 0.05;
  Troels_Smith(TSSOLIDCIRCLE, 0.4, 0.4);
}
//---------------------------------------------------------------------------
// Grana saburralia 2
void LithPatt::TSGs2(void)
{
  xoffsets(2,  0.095,  0.255);
  yoffsets(2, -0.00, -0.16);
  xset(2,  0.00, 0.05);
  yset(2, -0.05, 0.00);
  rightadjust = 0.05;
  Troels_Smith(TSSOLIDCIRCLE, 0.32, 0.32);
}
//---------------------------------------------------------------------------
// Grana saburralia 3
void LithPatt::TSGs3(void)
{
  xoffsets(2,  0.095, -0.025);
  yoffsets(2, -0.00, -0.12);
  xset(2,  0.00, 0.05);
  yset(2, -0.05, 0.00);
  rightadjust = 0.05;
  Troels_Smith(TSSOLIDCIRCLE, 0.24, 0.24);
}
//---------------------------------------------------------------------------
// Grana saburralia 4
void LithPatt::TSGs4(void)
{
  xoffsets(2,  0.015,  0.095);
  yoffsets(2, -0.00, -0.08);
  xset(2,  0.00, 0.05);
  yset(2, -0.05, 0.00);
  rightadjust = 0.05;
  Troels_Smith(TSSOLIDCIRCLE, 0.16, 0.16);
}
//---------------------------------------------------------------------------
// Grana glareosa (minora) 1
void LithPatt::TSGg_min1(void)
{
  xoffsets(2,  0.06,  0.26);
  yoffsets(2, -0.00, -0.20);
  xset(2,  0.00, 0.08);
  yset(2, -0.08, 0.00);
  rightadjust = 0.08;
  Troels_Smith(TSHOLLOWCIRCLE, 0.4, 0.4);
}
//---------------------------------------------------------------------------
// Grana glareosa (minora) 2
void LithPatt::TSGg_min2(void)
{
  xoffsets(2,  0.08,  0.24);
  yoffsets(2, -0.00, -0.16);
  xset(2,  0.00, 0.08);
  yset(2, -0.08, 0.00);
  rightadjust = 0.08;
  Troels_Smith(TSHOLLOWCIRCLE, 0.32, 0.32);
}
//---------------------------------------------------------------------------
// Grana glareosa (minora) 3
void LithPatt::TSGg_min3(void)
{
  xoffsets(2,  0.08, -0.04);
  yoffsets(2, -0.00, -0.12);
  xset(2,  0.00, 0.08);
  yset(2, -0.08, 0.00);
  rightadjust = 0.08;
  Troels_Smith(TSHOLLOWCIRCLE, 0.24, 0.24);
}
//---------------------------------------------------------------------------
// Grana glareosa (minora) 4
void LithPatt::TSGg_min4(void)
{
  xoffsets(2, 0.00,  0.08);
  yoffsets(2, 0.00, -0.08);
  xset(2,  0.00, 0.08);
  yset(2, -0.08, 0.00);
  rightadjust = 0.08;
  Troels_Smith(TSHOLLOWCIRCLE, 0.16, 0.16);
}
//---------------------------------------------------------------------------
// Grana glareosa (majora) 1
void LithPatt::TSGg_maj1(void)
{
  xoffsets(2,  0.52,  0.12);
  yoffsets(2, 0.00, -0.40);
  xset(2,  0.00, 0.16);
  yset(2, -0.16, 0.00);
  rightadjust = 0.16;
  Troels_Smith(TSHOLLOWCIRCLE, 0.8, 0.8);
}
//---------------------------------------------------------------------------
// Grana glareosa (majora) 2
void LithPatt::TSGg_maj2(void)
{
  xoffsets(2,  0.04,  0.36);
  yoffsets(2,  0.00, -0.32);
  xset(2,  0.00, 0.16);
  yset(2, -0.16, 0.00);
  rightadjust = 0.16;
  Troels_Smith(TSHOLLOWCIRCLE, 0.64, 0.64);
}
//---------------------------------------------------------------------------
// Grana glareosa (majora) 3
void LithPatt::TSGg_maj3(void)
{
  xoffsets(2,  0.04,  0.28);
  yoffsets(2,  0.00, -0.24);
  xset(2,  0.00, 0.16);
  yset(2, -0.16, 0.00);
  rightadjust = 0.16;
  Troels_Smith(TSHOLLOWCIRCLE, 0.48, 0.48);
}
//---------------------------------------------------------------------------
// Grana glareosa (majora) 4
void LithPatt::TSGg_maj4(void)
{
  xoffsets(2, 0.04, -0.12);
  yoffsets(2, 0.00, -0.16);
  xset(2,  0.00, 0.16);
  yset(2, -0.16, 0.00);
  rightadjust = 0.16;
  Troels_Smith(TSHOLLOWCIRCLE, 0.32, 0.32);
}
//---------------------------------------------------------------------------
// testae (molluscorum) 1
void LithPatt::TStest1(void)
{
  xoffsets(2, 0.06,  0.26);
  yoffsets(2, 0.00, -0.20);
  xset(19, 0.008, 0.002, 0.000, 0.002, 0.008, 0.016, 0.028, 0.040, 0.052, 0.064,
           0.072, 0.078, 0.080, 0.078, 0.072, 0.060, 0.048, 0.040, 0.040);
  yset(19, 0.000, -0.008, -0.020, -0.032, -0.044, -0.052, -0.058, -0.060,
          -0.058, -0.052, -0.044, -0.032, -0.020, -0.012, -0.002,  0.000,
          -0.002, -0.012, -0.024);
  rightadjust = 0.08;
  Troels_Smith(TSLINE, 0.4, 0.4);
}
//---------------------------------------------------------------------------
// testae (molluscorum) 2
void LithPatt::TStest2(void)
{
  xoffsets(2, 0.00,  0.16);
  yoffsets(2, 0.00, -0.16);
  xset(19, 0.008, 0.002, 0.000, 0.002, 0.008, 0.016, 0.028, 0.040, 0.052, 0.064,
           0.072, 0.078, 0.080, 0.078, 0.072, 0.060, 0.048, 0.040, 0.040);
  yset(19, 0.000, -0.008, -0.020, -0.032, -0.044, -0.052, -0.058, -0.060,
          -0.058, -0.052, -0.044, -0.032, -0.020, -0.012, -0.002,  0.000,
          -0.002, -0.012, -0.024);
  rightadjust = 0.08;
  Troels_Smith(TSLINE, 0.32, 0.32);
}
//---------------------------------------------------------------------------
// testae (molluscorum) 3
void LithPatt::TStest3(void)
{
  xoffsets(2, 0.02,  0.14);
  yoffsets(2, 0.00, -0.12);
  xset(19, 0.008, 0.002, 0.000, 0.002, 0.008, 0.016, 0.028, 0.040, 0.052, 0.064,
           0.072, 0.078, 0.080, 0.078, 0.072, 0.060, 0.048, 0.040, 0.040);
  yset(19, 0.000, -0.008, -0.020, -0.032, -0.044, -0.052, -0.058, -0.060,
          -0.058, -0.052, -0.044, -0.032, -0.020, -0.012, -0.002,  0.000,
          -0.002, -0.012, -0.024);
  rightadjust = 0.08;
  Troels_Smith(TSLINE, 0.24, 0.24);
}
//---------------------------------------------------------------------------
// testae (molluscorum) 4
void LithPatt::TStest4(void)
{
  xoffsets(2, 0.00,  0.08);
  yoffsets(2, 0.00, -0.08);
  xset(19, 0.008, 0.002, 0.000, 0.002, 0.008, 0.016, 0.028, 0.040, 0.052, 0.064,
           0.072, 0.078, 0.080, 0.078, 0.072, 0.060, 0.048, 0.040, 0.040);
  yset(19, 0.000, -0.008, -0.020, -0.032, -0.044, -0.052, -0.058, -0.060,
          -0.058, -0.052, -0.044, -0.032, -0.020, -0.012, -0.002,  0.000,
          -0.002, -0.012, -0.024);
  rightadjust = 0.08;
  Troels_Smith(TSLINE, 0.16, 0.16);
}
//---------------------------------------------------------------------------
// particulae testarum (molluscorum) 1
void LithPatt::TSptest1(void)
{
  xoffsets(2, 0.08,  0.28);
  yoffsets(2, 0.00, -0.20);
  xset(17, 0.000, 0.001, 0.004, 0.008, 0.014, 0.020, 0.026, 0.032, 0.036, 0.039,
           0.040, 0.038, 0.033, 0.027, 0.020, 0.011, 0.000);
  yset(17, -0.020, -0.014, -0.008, -0.004, -0.001,  0.000, -0.001, -0.004,
           -0.008, -0.014, -0.020, -0.030, -0.040, -0.050, -0.060, -0.070,
           -0.080 );
  rightadjust = 0.08;
  Troels_Smith(TSLINE, 0.4, 0.4);
}
//---------------------------------------------------------------------------
// particulae testarum (molluscorum) 2
void LithPatt::TSptest2(void)
{
  xoffsets(2, 0.02,  0.18);
  yoffsets(2, 0.00, -0.16);
  xset(17, 0.000, 0.001, 0.004, 0.008, 0.014, 0.020, 0.026, 0.032, 0.036, 0.039,
           0.040, 0.038, 0.033, 0.027, 0.020, 0.011, 0.000);
  yset(17, -0.020, -0.014, -0.008, -0.004, -0.001,  0.000, -0.001, -0.004,
           -0.008, -0.014, -0.020, -0.030, -0.040, -0.050, -0.060, -0.070,
           -0.080 );
  rightadjust = 0.08;
  Troels_Smith(TSLINE, 0.32, 0.32);
}
//---------------------------------------------------------------------------
// particulae testarum (molluscorum) 3
void LithPatt::TSptest3(void)
{
  xoffsets(2, 0.04,  0.16);
  yoffsets(2, 0.00, -0.12);
  xset(17, 0.000, 0.001, 0.004, 0.008, 0.014, 0.020, 0.026, 0.032, 0.036, 0.039,
           0.040, 0.038, 0.033, 0.027, 0.020, 0.011, 0.000);
  yset(17, -0.020, -0.014, -0.008, -0.004, -0.001,  0.000, -0.001, -0.004,
           -0.008, -0.014, -0.020, -0.030, -0.040, -0.050, -0.060, -0.070,
           -0.080 );
  rightadjust = 0.08;
  Troels_Smith(TSLINE, 0.24, 0.24);
}
//---------------------------------------------------------------------------
// particulae testarum (molluscorum) 4
void LithPatt::TSptest4(void)
{
  xoffsets(2, 0.02,  0.10);
  yoffsets(2, 0.00, -0.08);
  xset(17, 0.000, 0.001, 0.004, 0.008, 0.014, 0.020, 0.026, 0.032, 0.036, 0.039,
           0.040, 0.038, 0.033, 0.027, 0.020, 0.011, 0.000);
  yset(17, -0.020, -0.014, -0.008, -0.004, -0.001,  0.000, -0.001, -0.004,
           -0.008, -0.014, -0.020, -0.030, -0.040, -0.050, -0.060, -0.070,
           -0.080 );
  rightadjust = 0.08;
  Troels_Smith(TSLINE, 0.16, 0.16);
}
//---------------------------------------------------------------------------
// fragmenta corticis. sectio 1
void LithPatt::TSCortSec1(void)
{
  xoffsets(2, -0.12,  0.18);
  yoffsets(2,  0.00, -0.30);
  xset(5, 0.00, 0.24,  0.24,  0.00, 0.00);
  yset(5, 0.00, 0.00, -0.04, -0.04, 0.00 );
  rightadjust = 0.24;
  Troels_Smith(TSAREA, 0.60, 0.60);
}
//---------------------------------------------------------------------------
// fragmenta corticis. sectio 2
void LithPatt::TSCortSec2(void)
{
  xoffsets(2, -0.12,  0.08);
  yoffsets(2,  0.00, -0.20);
  xset(5, 0.00, 0.24,  0.24,  0.00, 0.00);
  yset(5, 0.00, 0.00, -0.04, -0.04, 0.00 );
  rightadjust = 0.24;
  Troels_Smith(TSAREA, 0.40, 0.40);
}
//---------------------------------------------------------------------------
// fragmenta corticis. sectio 3
void LithPatt::TSCortSec3(void)
{
  xoffsets(2, 0.00, -0.16);
  yoffsets(2, 0.00, -0.12);
  xset(5, 0.00, 0.24,  0.24,  0.00, 0.00);
  yset(5, 0.00, 0.00, -0.04, -0.04, 0.00 );
  rightadjust = 0.24;
  Troels_Smith(TSAREA, 0.32, 0.24);
}
//---------------------------------------------------------------------------
// fragmenta corticis. sectio 4
void LithPatt::TSCortSec4(void)
{
  xoffsets(2, -0.00, -0.16);
  yoffsets(2, -0.00, -0.08);
  xset(5, 0.00, 0.24,  0.24,  0.00, 0.00);
  yset(5, 0.00, 0.00, -0.04, -0.04, 0.00 );
  rightadjust = 0.24;
  Troels_Smith(TSAREA, 0.32, 0.16);
}
//---------------------------------------------------------------------------
// cortex 1
void LithPatt::TSCort1(void)
{
  xoffsets(2, -0.12,  0.18);
  yoffsets(2,  0.00, -0.30);
  xset(7,  0.00, 0.03, 0.21,  0.24,  0.21,  0.03,  0.00);
  yset(7, -0.02, 0.00, 0.00, -0.02, -0.04, -0.04, -0.02 );
  rightadjust = 0.24;
  Troels_Smith(TSLINE, 0.60, 0.60);
}
//---------------------------------------------------------------------------
// cortex 2
void LithPatt::TSCort2(void)
{
  xoffsets(2, -0.12,  0.08);
  yoffsets(2,  0.00, -0.20);
  xset(7,  0.00, 0.03, 0.21,  0.24,  0.21,  0.03,  0.00);
  yset(7, -0.02, 0.00, 0.00, -0.02, -0.04, -0.04, -0.02 );
  rightadjust = 0.24;
  Troels_Smith(TSLINE, 0.40, 0.40);
}
//---------------------------------------------------------------------------
// cortex 3
void LithPatt::TSCort3(void)
{
  xoffsets(2, 0.00, -0.16);
  yoffsets(2, 0.00, -0.12);
  xset(7,  0.00, 0.03, 0.21,  0.24,  0.21,  0.03,  0.00);
  yset(7, -0.02, 0.00, 0.00, -0.02, -0.04, -0.04, -0.02 );
  rightadjust = 0.24;
  Troels_Smith(TSLINE, 0.32, 0.24);
}
//---------------------------------------------------------------------------
// cortex 4
void LithPatt::TSCort4(void)
{
  xoffsets(2, -0.00, -0.16);
  yoffsets(2, -0.00, -0.08);
  xset(7,  0.00, 0.03, 0.21,  0.24,  0.21,  0.03,  0.00);
  yset(7, -0.02, 0.00, 0.00, -0.02, -0.04, -0.04, -0.02 );
  rightadjust = 0.24;
  Troels_Smith(TSLINE, 0.32, 0.16);
}
//---------------------------------------------------------------------------

void LithPatt::Troels_Smith(int type, double xbox, double ybox)
{
  int i, k;
  double boxtop, boxleft, left0;
  //double *xc, *yc;
  double xshift, yshift;
  DblRect *rect;
  //DblRect *ClipBox;
  //ClipBox = new DblRect(left, right, bot, top);
  DblRect ClipBox(left, right, bot, top);

  right += rightadjust;
  top += topadjust;
  yshift = Component->YShift + yshiftadjust;
  xshift = Component->XShift + xshiftadjust;

  //xc = new double [n];
  //yc = new double [n];
  vector<double> xc(n, 0.0);
  vector<double> yc(n, 0.0);

  if (xshift > 0.0) {
    left0 = left + xshift;
    while (left0 > left) left0 -= xbox;
    }
  else if (xshift < 0.0) {
    left0 = left + xshift;
    while (left0 < left-xbox) left0 += xbox;
    }
  else
    left0 = left;

  if (yshift > 0.0) {
    boxtop = top + yshift;
    while (boxtop > top+ybox) boxtop -= ybox;
    }
  else if (yshift < 0.0) {
    boxtop = top + yshift;
    while (boxtop < top) boxtop += ybox;
    }
  else
    boxtop = top;

  while (boxtop > bot)
    {
      boxleft = left0;
      while (boxleft < right)
        {
          for (i=0; i<ns; i++)
            {
              for (k=0; k<n; k++) {
                xc[k] = boxleft + xoff[i] + x[k];
                yc[k] = boxtop  + yoff[i] + y[k];
                }
              if (type == TSAREA)
				Picture->Polygon(n, xc, yc, 0, -1, Component->Color, SOLID_FILL, ClipBox);
			  else if (type == TSLINE)
				Picture->Polyline(n, xc.begin(), yc.begin(), Component->Color, line_width, ClipBox);
			  else if (type == TSSOLIDCIRCLE) {
				DblRect rect(xc[0], xc[1], yc[0], yc[1]);
				Picture->Ellipse(rect, Component->Color, SOLID_FILL, ClipBox);
				//delete rect;
				}
			  else if (type == TSHOLLOWCIRCLE) {
				DblRect rect(xc[0], xc[1], yc[0], yc[1]);
				Picture->Ellipse(rect, Component->Color, HOLLOW_FILL, ClipBox);
                //delete rect;
                }
            }

          boxleft += xbox;
        }
      boxtop -= ybox;
    }

  //delete ClipBox;
  //delete[] xc;
  //delete[] yc;
  cleanup();
}

