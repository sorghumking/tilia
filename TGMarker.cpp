//---------------------------------------------------------------------------
#include <vcl.h>
#include "pch.h"
#pragma hdrstop

#ifndef TGH
#include "tg.h"
#endif
#ifndef TGraphicH
#include "TGraphic.h"
#endif
#ifndef TGParentH
#include "TGParent.h"
#endif
#ifndef TGDiagrmH
#include "TGDiagrm.h"
#endif
#include "TGMarker.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)


MarkerBase::MarkerBase(double s, bool z, int c, int n, double l,
   double *xx, double *yy, MyGraphics *pic)
{
  size = s,
  ZeroSymbol = z,
  color_index = c,
  npnts = n;
  LineWidth = l;
  x = xx;
  y = yy;
  Picture = pic;
}

void MarkerBase::PlotMarkers(void)
{
  for (int i=0; i<npnts; i++) {
    if (x[i] > 0.0 || ZeroSymbol)
      DrawMarker(x[i], y[i], size);
    }
}

// plots an X marker
void Marker1::DrawMarker(double xc, double yc, double size)
{
  double x[2], y[2], r;
  r = 0.5*size;
  x[0] = xc+r;
  x[1] = xc-r;
  y[0] = yc+r;
  y[1] = yc-r;
  Picture->Polyline(2, x, y, color_index, LineWidth);
  x[0] = xc-r;
  x[1] = xc+r;
  Picture->Polyline(2, x, y, color_index, LineWidth);
};

// plots a star marker
void Marker2::DrawMarker(double xc, double yc, double size)
{
  double x[2], y[2], dx, dy;
  dx = 0.5*size;
  x[0] = xc-dx;
  x[1] = xc+dx;
  y[0] = y[1] = yc;
  Picture->Polyline(2, x, y, color_index, LineWidth);
  dx = 0.25*size;
  dy = 0.25*SQRT3*size;
  x[0] = xc+dx;
  x[1] = xc-dx;
  y[0] = yc+dy;
  y[1] = yc-dy;
  Picture->Polyline(2, x, y, color_index, LineWidth);
  x[0] = xc-dx;
  x[1] = xc+dx;
  Picture->Polyline(2, x, y, color_index, LineWidth);
}

// plots a hollow square marker
void Marker3::DrawMarker(double xc, double yc, double size)
{
  double dx = size/2.0;
  DblRect rect(xc-dx, xc+dx, yc-dx, yc+dx);
  Picture->FillRect(rect, color_index, HOLLOW_FILL);
}

// plots a solid square marker
void Marker4::DrawMarker(double xc, double yc, double size)
{
  double dx = size/2.0;
  DblRect rect(xc-dx, xc+dx, yc-dx, yc+dx);
  Picture->FillRect(rect, color_index, SOLID_FILL);
}

// plots a square marker with X
void Marker5::DrawMarker(double xc, double yc, double size)
{
  double x[2], y[2];
  double dx = size/2.0;
  DblRect rect(xc-dx, xc+dx, yc-dx, yc+dx);
  Picture->FillRect(rect, color_index, HOLLOW_FILL);
  x[0] = xc+dx;
  x[1] = xc-dx;
  y[0] = yc+dx;
  y[1] = yc-dx;
  Picture->Polyline(2, x, y, color_index, LineWidth);
  x[0] = xc-dx;
  x[1] = xc+dx;
  Picture->Polyline(2, x, y, color_index, LineWidth);
}

// plots a square marker with line across middle
void Marker6::DrawMarker(double xc, double yc, double size)
{
  double x[2], y[2];
  double dx = size/2.0;
  DblRect rect(xc-dx, xc+dx, yc-dx, yc+dx);
  Picture->FillRect(rect, color_index, HOLLOW_FILL);
  x[0] = xc - dx;
  x[1] = xc + dx;
  y[0] = y[1] = yc;
  Picture->Polyline(2, x, y, color_index, LineWidth);
}

// plots a hollow circle
void Marker7::DrawMarker(double xc, double yc, double size)
{
  double dx = size/2.0;
  DblRect rect(xc-dx, xc+dx, yc-dx, yc+dx);
  Picture->Ellipse(rect, color_index, HOLLOW_FILL);
  //delete rect;
}

// plots a solid circle
void Marker8::DrawMarker(double xc, double yc, double size)
{
  double dx = size/2.0;
  DblRect rect(xc-dx, xc+dx, yc-dx, yc+dx);
  Picture->Ellipse(rect, color_index, SOLID_FILL);
  //delete rect;
}

// plots a top half cirlce
void Marker9::DrawMarker(double xc, double yc, double size)
{
  double dx = size/2.0;
  double dx4 = size/4.0;
  DblRect rect(xc-dx, xc+dx, yc-dx-dx4, yc+dx4);
  double X3 = xc + dx;
  double X4 = xc - dx;
  yc -= dx4;
  Picture->Ellipse(rect, X3, yc, X4, yc, color_index, HOLLOW_FILL);
  //delete rect;
}

// plots a bottom half cirlce
void Marker10::DrawMarker(double xc, double yc, double size)
{
  double dx = size/2.0;
  double dx4 = size/4.0;
  DblRect rect(xc-dx, xc+dx, yc-dx4, yc+dx+dx4);
  double X3 = xc - dx;
  double X4 = xc + dx;
  yc += dx4;
  Picture->Ellipse(rect, X3, yc, X4, yc, color_index, SOLID_FILL);
  //delete rect;
}

// plots a left half cirlce
void Marker11::DrawMarker(double xc, double yc, double size)
{
  double dx = size/2.0;
  double dx4 = size/4.0;
  DblRect rect(xc-dx4, xc+dx+dx4, yc-dx, yc+dx);
  double Y3 = yc + dx;
  double Y4 = yc - dx;
  double x = xc + dx4;
  Picture->Ellipse(rect, x, Y3, x, Y4, color_index, SOLID_FILL);
  //delete rect;
}

// plots a right half cirlce
void Marker12::DrawMarker(double xc, double yc, double size)
{
  double dx = size/2.0;
  double dx4 = size/4.0;
  DblRect rect(xc-dx-dx4, xc+dx4, yc-dx, yc+dx);
  double Y3 = yc - dx;
  double Y4 = yc + dx;
  double x = xc - dx4;
  Picture->Ellipse(rect, x, Y3, x, Y4, color_index, SOLID_FILL);
  //delete rect;
}

// plots lazy half circle marker
void Marker13::DrawMarker(double xc, double yc, double size)
{
  double dx = size/2.0;
  double d = dx/(2.0*SQRT2);
  DblRect rect(xc-dx+d, xc+dx+d, yc-dx+d, yc+dx+d);
  Picture->Ellipse(rect, xc-dx+d, yc+dx+d, xc+dx+d, yc-dx+d, color_index, SOLID_FILL);
  //delete rect;
}

// plots double pie marker
void Marker14::DrawMarker(double xc, double yc, double size)
{
  double dx = size/2.0;
  DblRect rect1(xc-dx, xc+dx, yc-dx, yc+dx);
  DblRect rect2(xc-dx, xc+dx, yc-dx, yc+dx);
  Picture->Ellipse(rect1, xc-dx, yc-dx, xc+dx, yc-dx, color_index, SOLID_FILL);
  Picture->Ellipse(rect2, xc+dx, yc+dx, xc-dx, yc+dx, color_index, SOLID_FILL);
  //delete rect1;
  //delete rect2;
}

// plots circle with plus sign inside
void Marker15::DrawMarker(double xc, double yc, double size)
{
  double x[2], y[2];
  double dx = size/2.0;
  DblRect rect(xc-dx, xc+dx, yc-dx, yc+dx);
  Picture->Ellipse(rect, color_index, HOLLOW_FILL);
  //delete rect;
  x[0] = x[1] = xc;
  y[0] = yc-dx;
  y[1] = yc+dx;
  Picture->Polyline(2, x, y, color_index, LineWidth);
  y[0] = y[1] = yc;
  x[0] = xc-dx;
  x[1] = xc+dx;
  Picture->Polyline(2, x, y, color_index, LineWidth);
}

// plots circle with X inside
void Marker16::DrawMarker(double xc, double yc, double size)
{
  double x[2], y[2], r;
  double dx = size/2.0;
  DblRect rect(xc-dx, xc+dx, yc-dx, yc+dx);
  Picture->Ellipse(rect, color_index, HOLLOW_FILL);
  //delete rect;
  r = 0.5*size/SQRT2;
  x[0] = xc+r;
  x[1] = xc-r;
  y[0] = yc+r;
  y[1] = yc-r;
  Picture->Polyline(2, x, y, color_index, LineWidth);
  x[0] = xc-r;
  x[1] = xc+r;
  Picture->Polyline(2, x, y, color_index, LineWidth);
};

// plots circle with star inside
void Marker17::DrawMarker(double xc, double yc, double size)
{
  double x[2], y[2], r;
  double dx = size/2.0;
  DblRect rect(xc-dx, xc+dx, yc-dx, yc+dx);
  Picture->Ellipse(rect, color_index, HOLLOW_FILL);
  //delete rect;
  r = 0.5*size/SQRT2;
  x[0] = xc+r;
  x[1] = xc-r;
  y[0] = yc+r;
  y[1] = yc-r;
  Picture->Polyline(2, x, y, color_index, LineWidth);
  x[0] = xc-r;
  x[1] = xc+r;
  Picture->Polyline(2, x, y, color_index, LineWidth);
  x[0] = xc-dx;
  x[1] = xc+dx;
  y[0] = y[1] = yc;
  Picture->Polyline(2, x, y, color_index, LineWidth);
};

// plots circle with mercedes inside
void Marker18::DrawMarker(double xc, double yc, double size)
{
  double x[3], y[3], r, dx, dy;
  dx = size/2.0;
  DblRect rect(xc-dx, xc+dx, yc-dx, yc+dx);
  Picture->Ellipse(rect, color_index, HOLLOW_FILL);
  //delete rect;
  r = (double)0.5*size;
  dx = r*0.5*SQRT3;
  dy = 0.5*r;
  x[0] = x[1] = xc;
  x[2] = xc-dx;
  y[0] = yc+r;
  y[1] = yc;
  y[2] = yc-dy;
  Picture->Polyline(3, x, y, color_index, LineWidth);
  x[0] = xc+dx;
  y[0] = yc-dy;
  Picture->Polyline(2, x, y, color_index, LineWidth);
}

// plots solid circle with mercedes inside
void Marker19::DrawMarker(double xc, double yc, double size)
{
  double x[3], y[3], r, dx, dy;
  dx = size/2.0;
  DblRect rect(xc-dx, xc+dx, yc-dx, yc+dx);
  Picture->Ellipse(rect, color_index, SOLID_FILL);
  //delete rect;

  TTGDiagram* TGDiagram = (TTGDiagram *)ParentForm->ActiveMDIChild;
  int Color = TColor(TGDiagram->Picture->BackgroundColor);

  r = (double)0.5*size;
  dx = r*0.5*SQRT3;
  dy = 0.5*r;
  x[0] = x[1] = xc;
  x[2] = xc-dx;
  y[0] = yc+r;
  y[1] = yc;
  y[2] = yc-dy;
  Picture->Polyline(3, x, y, Color, LineWidth);
  x[0] = xc+dx;
  y[0] = yc-dy;
  Picture->Polyline(2, x, y, Color, LineWidth);
}

// plots a circle with smaller circle inside
void Marker20::DrawMarker(double xc, double yc, double size)
{
  //DblRect *rect;
  double dx = size/2.0;
  DblRect rect1(xc-dx, xc+dx, yc-dx, yc+dx);
  Picture->Ellipse(rect1, color_index, HOLLOW_FILL);
  //delete rect;
  dx *= 0.5;
  DblRect rect2(xc-dx, xc+dx, yc-dx, yc+dx);
  Picture->Ellipse(rect2, color_index, HOLLOW_FILL);
  //delete rect;
}

// plots a circle with smaller solid circle inside
void Marker21::DrawMarker(double xc, double yc, double size)
{
  //DblRect *rect;
  double dx = size/2.0;
  DblRect rect1(xc-dx, xc+dx, yc-dx, yc+dx);
  Picture->Ellipse(rect1, color_index, HOLLOW_FILL);
  //delete rect;
  dx *= 0.5;
  DblRect rect2(xc-dx, xc+dx, yc-dx, yc+dx);
  Picture->Ellipse(rect2, color_index, SOLID_FILL);
  //delete rect;
}

// plots a hollow diamond
void Marker22::DrawMarker(double xc, double yc, double size)
{
  double dx;
  vector<double> x(5, 0.0);
  vector<double> y(5, 0.0);
  dx = size/SQRT2;
  x[0] = x[2] = x[4] = xc;
  x[1] = xc+dx;
  x[3] = xc-dx;
  y[0] = y[4] = yc+dx;
  y[1] = y[3] = yc;
  y[2] = yc-dx;
  Picture->Polygon(5, x, y, 0, color_index, 0, HOLLOW_FILL);
}

// plots a solid diamond
void Marker23::DrawMarker(double xc, double yc, double size)
{
  double dx;
  vector<double> x(5, 0.0);
  vector<double> y(5, 0.0);
  dx = size/SQRT2;
  x[0] = x[2] = x[4] = xc;
  x[1] = xc+dx;
  x[3] = xc-dx;
  y[0] = y[4] = yc+dx;
  y[1] = y[3] = yc;
  y[2] = yc-dx;
  Picture->Polygon(5, x, y, 0, color_index, color_index, SOLID_FILL);
}

// plots a narrow vertical diamond
void Marker24::DrawMarker(double xc, double yc, double size)
{
  double a, b;
  vector<double> x(5, 0.0);
  vector<double> y(5, 0.0);
  b = 0.5*size;
  a = b/SQRT3;
  x[0] = x[2] = x[4] = xc;
  x[1] = xc+a;
  x[3] = xc-a;
  y[0] = y[4] = yc+b;
  y[1] = y[3] = yc;
  y[2] = yc-b;
  Picture->Polygon(5, x, y, 0, color_index, 0, HOLLOW_FILL);
}

// plots a narrow horizontal diamond
void Marker25::DrawMarker(double xc, double yc, double size)
{
  double a, b;
  vector<double> x(5, 0.0);
  vector<double> y(5, 0.0);
  b = 0.5*size;
  a = b/SQRT3;
  x[0] = x[2] = x[4] = xc;
  x[1] = xc+b;
  x[3] = xc-b;
  y[0] = y[4] = yc+a;
  y[1] = y[3] = yc;
  y[2] = yc-a;
  Picture->Polygon(5, x, y, 0, color_index, 0, HOLLOW_FILL);
}

// plots a hollow triangle
void Marker26::DrawMarker(double xc, double yc, double size)
{
  vector<double> x(4, 0.0);
  vector<double> y(4, 0.0);
  x[0] = x[3] = xc;
  x[1] = xc+size/SQRT3;
  x[2] = xc-size/SQRT3;
  y[0] = y[3] = yc+0.6666667*size;
  y[1] = y[2] = yc-0.3333333*size;
  Picture->Polygon(4, x, y, 0, color_index, 0, HOLLOW_FILL);
}

// plots a solid triangle
void Marker27::DrawMarker(double xc, double yc, double size)
{
  vector<double> x(4, 0.0);
  vector<double> y(4, 0.0);
  x[0] = x[3] = xc;
  x[1] = xc+size/SQRT3;
  x[2] = xc-size/SQRT3;
  y[0] = y[3] = yc+0.6666667*size;
  y[1] = y[2] = yc-0.3333333*size;
  Picture->Polygon(4, x, y, 0, color_index, color_index, SOLID_FILL);
}

// plots a mercedes triangle
void Marker28::DrawMarker(double xc, double yc, double size)
{
  vector<double> x(4, 0.0);
  vector<double> y(4, 0.0);
  x[0] = x[3] = xc;
  x[1] = xc+size/SQRT3;
  x[2] = xc-size/SQRT3;
  y[0] = y[3] = yc+0.6666667*size;
  y[1] = y[2] = yc-0.3333333*size;
  Picture->Polygon(4, x, y, 0, color_index, 0, HOLLOW_FILL);

  x[0] = x[1] = xc;
  x[2] = xc+size/SQRT3;
  y[0] = yc+0.6666667*size;
  y[1] = yc;
  y[2] = yc-0.3333333*size;
  Picture->Polyline(3, x.begin(), y.begin(), color_index, LineWidth);
  x[0] = xc-size/SQRT3;
  y[0] = yc-0.3333333*size;
  Picture->Polyline(2, x.begin(), y.begin(), color_index, LineWidth);
}

// plots a triangle cut in half vertically
void Marker29::DrawMarker(double xc, double yc, double size)
{
  vector<double> x(4, 0.0);
  vector<double> y(4, 0.0);
  x[0] = x[3] = xc;
  x[1] = xc+size/SQRT3;
  x[2] = xc-size/SQRT3;
  y[0] = y[3] = yc+0.6666667*size;
  y[1] = y[2] = yc-0.3333333*size;
  Picture->Polygon(4, x, y, 0, color_index, 0, HOLLOW_FILL);

  x[0] = x[1] = xc;
  y[0] = yc+0.6666667*size;
  y[1] = yc-0.3333333*size;
  Picture->Polyline(2, x.begin(), y.begin(), color_index, LineWidth);
}

// plots a hollow upside down triangle
void Marker30::DrawMarker(double xc, double yc, double size)
{
  vector<double> x(4, 0.0);
  vector<double> y(4, 0.0);
  x[0] = x[3] = xc-size/SQRT3;
  x[1] = xc+size/SQRT3;
  x[2] = xc;
  y[0] = y[1] = y[3] = yc+0.3333333*size;
  y[2] = yc-0.6666667*size;
  Picture->Polygon(4, x, y, 0, color_index, 0, HOLLOW_FILL);
}

// plots a solid upside down triangle
void Marker31::DrawMarker(double xc, double yc, double size)
{
  vector<double> x(4, 0.0);
  vector<double> y(4, 0.0);
  x[0] = x[3] = xc-size/SQRT3;
  x[1] = xc+size/SQRT3;
  x[2] = xc;
  y[0] = y[1] = y[3] = yc+0.3333333*size;
  y[2] = yc-0.6666667*size;
  Picture->Polygon(4, x, y, 0, color_index, color_index, SOLID_FILL);
}

// plots a triangle cut in half horizontally
void Marker32::DrawMarker(double xc, double yc, double size)
{
  vector<double> x(5, 0.0);
  vector<double> y(5, 0.0);
  x[0] = x[3] = xc;
  x[1] = xc+0.6666667*size/SQRT3;
  x[2] = xc-0.6666667*size/SQRT3;
  y[0] = y[3] = yc+0.6666667*size;
  y[1] = y[2] = yc;
  Picture->Polygon(4, x, y, 0, color_index, 0, HOLLOW_FILL);
  x[0] = x[4] = x[2];
  x[2] = xc+size/SQRT3;
  x[3] = xc-size/SQRT3;
  y[0] = y[1] = y[4] = yc;
  y[2] = y[3] = yc-0.3333333*size;
  Picture->Polygon(5, x, y, 0, color_index, color_index, SOLID_FILL);
}


