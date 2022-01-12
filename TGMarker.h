//---------------------------------------------------------------------------
#ifndef TGMarkerH
#define TGMarkerH
//---------------------------------------------------------------------------
#ifndef TGraphicH
#include "TGraphic.h"
#endif

#define SQRT2 1.4142135
#define SQRT3 1.7320508



class MarkerBase
{
private:
  double size;
  bool ZeroSymbol;
  int npnts;
  double *x;
  double *y;

public:
  int color_index;
  double LineWidth;
  MyGraphics *Picture;

public:
  MarkerBase(double s, bool z, int c, int n, double l, double *xx, double *yy,
             MyGraphics *pic);
  virtual void DrawMarker(double, double, double) = 0;
  void PlotMarkers(void);
};

class Marker1: public MarkerBase    // X marker
{
public:
  Marker1(double s, bool z, int c, int n, double l, double *xx, double *yy,
      MyGraphics *pic) : MarkerBase(s, z, c, n, l, xx, yy, pic) { }
  void DrawMarker(double, double, double);
};

class Marker2: public MarkerBase  // star marker
{
public:
  Marker2(double s, bool z, int c, int n, double l, double *xx, double *yy,
      MyGraphics *pic) : MarkerBase(s, z, c, n, l, xx, yy, pic) { }
  void DrawMarker(double, double, double);
};

class Marker3: public MarkerBase  // hollow square
{
public:
  Marker3(double s, bool z, int c, int n, double l, double *xx, double *yy,
      MyGraphics *pic) : MarkerBase(s, z, c, n, l, xx, yy, pic) { }
  void DrawMarker(double, double, double);
};

class Marker4: public MarkerBase  // solid square
{
public:
  Marker4(double s, bool z, int c, int n, double l, double *xx, double *yy,
      MyGraphics *pic) : MarkerBase(s, z, c, n, l, xx, yy, pic) { }
  void DrawMarker(double, double, double);
};

class Marker5: public MarkerBase  // square with X inside
{
public:
  Marker5(double s, bool z, int c, int n, double l, double *xx, double *yy,
      MyGraphics *pic) : MarkerBase(s, z, c, n, l, xx, yy, pic) { }
  void DrawMarker(double, double, double);
};

class Marker6: public MarkerBase  // square with horizontal line
{
public:
  Marker6(double s, bool z, int c, int n, double l, double *xx, double *yy,
      MyGraphics *pic) : MarkerBase(s, z, c, n, l, xx, yy, pic) { }
  void DrawMarker(double, double, double);
};

class Marker7: public MarkerBase  // hollow circle
{
public:
  Marker7(double s, bool z, int c, int n, double l, double *xx, double *yy,
      MyGraphics *pic) : MarkerBase(s, z, c, n, l, xx, yy, pic) { }
  void DrawMarker(double, double, double);
};

class Marker8: public MarkerBase  // solid circle
{
public:
  Marker8(double s, bool z, int c, int n, double l, double *xx, double *yy,
      MyGraphics *pic) : MarkerBase(s, z, c, n, l, xx, yy, pic) { }
  void DrawMarker(double, double, double);
};

class Marker9: public MarkerBase  // top half circle
{
public:
  Marker9(double s, bool z, int c, int n, double l, double *xx, double *yy,
      MyGraphics *pic) : MarkerBase(s, z, c, n, l, xx, yy, pic) { }
  void DrawMarker(double, double, double);
};

class Marker10: public MarkerBase  // bottom half circle
{
public:
  Marker10(double s, bool z, int c, int n, double l, double *xx, double *yy,
      MyGraphics *pic) : MarkerBase(s, z, c, n, l, xx, yy, pic) { }
  void DrawMarker(double, double, double);
};

class Marker11: public MarkerBase  // left half circle
{
public:
  Marker11(double s, bool z, int c, int n, double l, double *xx, double *yy,
      MyGraphics *pic) : MarkerBase(s, z, c, n, l, xx, yy, pic) { }
  void DrawMarker(double, double, double);
};

class Marker12: public MarkerBase  // right half circle
{
public:
  Marker12(double s, bool z, int c, int n, double l, double *xx, double *yy,
      MyGraphics *pic) : MarkerBase(s, z, c, n, l, xx, yy, pic) { }
  void DrawMarker(double, double, double);
};

class Marker13: public MarkerBase  // lower left half circle
{
public:
  Marker13(double s, bool z, int c, int n, double l, double *xx, double *yy,
      MyGraphics *pic) : MarkerBase(s, z, c, n, l, xx, yy, pic) { }
  void DrawMarker(double, double, double);
};

class Marker14: public MarkerBase  // double pie marker
{
public:
  Marker14(double s, bool z, int c, int n, double l, double *xx, double *yy,
      MyGraphics *pic) : MarkerBase(s, z, c, n, l, xx, yy, pic) { }
  void DrawMarker(double, double, double);
};

class Marker15: public MarkerBase  // circle with plus sign inside
{
public:
  Marker15(double s, bool z, int c, int n, double l, double *xx, double *yy,
      MyGraphics *pic) : MarkerBase(s, z, c, n, l, xx, yy, pic) { }
  void DrawMarker(double, double, double);
};

class Marker16: public MarkerBase  // circle with X inside
{
public:
  Marker16(double s, bool z, int c, int n, double l, double *xx, double *yy,
      MyGraphics *pic) : MarkerBase(s, z, c, n, l, xx, yy, pic) { }
  void DrawMarker(double, double, double);
};

class Marker17: public MarkerBase  // circle with star inside
{
public:
  Marker17(double s, bool z, int c, int n, double l, double *xx, double *yy,
      MyGraphics *pic) : MarkerBase(s, z, c, n, l, xx, yy, pic) { }
  void DrawMarker(double, double, double);
};

class Marker18: public MarkerBase  // circle sith mercedes inside
{
public:
  Marker18(double s, bool z, int c, int n, double l, double *xx, double *yy,
      MyGraphics *pic) : MarkerBase(s, z, c, n, l, xx, yy, pic) { }
  void DrawMarker(double, double, double);
};

class Marker19: public MarkerBase  // solid circle with mercedes inside
{
public:
  Marker19(double s, bool z, int c, int n, double l, double *xx, double *yy,
      MyGraphics *pic) : MarkerBase(s, z, c, n, l, xx, yy, pic) { }
  void DrawMarker(double, double, double);
};

class Marker20: public MarkerBase  // circle with smaller circle inside
{
public:
  Marker20(double s, bool z, int c, int n, double l, double *xx, double *yy,
      MyGraphics *pic) : MarkerBase(s, z, c, n, l, xx, yy, pic) { }
  void DrawMarker(double, double, double);
};

class Marker21: public MarkerBase  // circle with smaller solid circle inside
{
public:
  Marker21(double s, bool z, int c, int n, double l, double *xx, double *yy,
      MyGraphics *pic) : MarkerBase(s, z, c, n, l, xx, yy, pic) { }
  void DrawMarker(double, double, double);
};

class Marker22: public MarkerBase  // hollow diamond
{
public:
  Marker22(double s, bool z, int c, int n, double l, double *xx, double *yy,
      MyGraphics *pic) : MarkerBase(s, z, c, n, l, xx, yy, pic) { }
  void DrawMarker(double, double, double);
};

class Marker23: public MarkerBase  // hollow diamond
{
public:
  Marker23(double s, bool z, int c, int n, double l, double *xx, double *yy,
      MyGraphics *pic) : MarkerBase(s, z, c, n, l, xx, yy, pic) { }
  void DrawMarker(double, double, double);
};

class Marker24: public MarkerBase  // narrow vertical diamond
{
public:
  Marker24(double s, bool z, int c, int n, double l, double *xx, double *yy,
      MyGraphics *pic) : MarkerBase(s, z, c, n, l, xx, yy, pic) { }
  void DrawMarker(double, double, double);
};

class Marker25: public MarkerBase  // narrow vertical diamond
{
public:
  Marker25(double s, bool z, int c, int n, double l, double *xx, double *yy,
      MyGraphics *pic) : MarkerBase(s, z, c, n, l, xx, yy, pic) { }
  void DrawMarker(double, double, double);
};

class Marker26: public MarkerBase  // narrow vertical diamond
{
public:
  Marker26(double s, bool z, int c, int n, double l, double *xx, double *yy,
      MyGraphics *pic) : MarkerBase(s, z, c, n, l, xx, yy, pic) { }
  void DrawMarker(double, double, double);
};

class Marker27: public MarkerBase  // narrow vertical diamond
{
public:
  Marker27(double s, bool z, int c, int n, double l, double *xx, double *yy,
      MyGraphics *pic) : MarkerBase(s, z, c, n, l, xx, yy, pic) { }
  void DrawMarker(double, double, double);
};

class Marker28: public MarkerBase  // narrow vertical diamond
{
public:
  Marker28(double s, bool z, int c, int n, double l, double *xx, double *yy,
      MyGraphics *pic) : MarkerBase(s, z, c, n, l, xx, yy, pic) { }
  void DrawMarker(double, double, double);
};

class Marker29: public MarkerBase  // narrow vertical diamond
{
public:
  Marker29(double s, bool z, int c, int n, double l, double *xx, double *yy,
      MyGraphics *pic) : MarkerBase(s, z, c, n, l, xx, yy, pic) { }
  void DrawMarker(double, double, double);
};

class Marker30: public MarkerBase  // narrow vertical diamond
{
public:
  Marker30(double s, bool z, int c, int n, double l, double *xx, double *yy,
      MyGraphics *pic) : MarkerBase(s, z, c, n, l, xx, yy, pic) { }
  void DrawMarker(double, double, double);
};

class Marker31: public MarkerBase  // narrow vertical diamond
{
public:
  Marker31(double s, bool z, int c, int n, double l, double *xx, double *yy,
      MyGraphics *pic) : MarkerBase(s, z, c, n, l, xx, yy, pic) { }
  void DrawMarker(double, double, double);
};

class Marker32: public MarkerBase  // narrow vertical diamond
{
public:
  Marker32(double s, bool z, int c, int n, double l, double *xx, double *yy,
      MyGraphics *pic) : MarkerBase(s, z, c, n, l, xx, yy, pic) { }
  void DrawMarker(double, double, double);
};

//---------------------------------------------------------------------------
#endif
