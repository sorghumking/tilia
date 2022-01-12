//---------------------------------------------------------------------------
#ifndef TGPLithH
#define TGPLithH
//---------------------------------------------------------------------------
//#endif
#ifndef TGH
#include "tg.h"
#endif

#define TSAREA   1
#define TSLINE   2
#define TSSOLIDCIRCLE  3
#define TSHOLLOWCIRCLE 4

class LithPatt
{
private:
  LITHCOMPONENT *Component;
  int n, ns;
  vector<double> xr;
  vector<double> yr;
  double *x, *y;
  double *xoff, *yoff;
  double left, right, top, bot;
  double rightadjust;
  double topadjust;
  double xshiftadjust;
  double yshiftadjust;
  double line_width;
  int default_line_width;
  MyGraphics *Picture;

public:
  LithPatt(LITHCOMPONENT *L, vector<double>& X, vector<double>& Y, double lw, MyGraphics *pic);
  void PlotPattern(void);

private:
  void SetHumoLineWidth(void);
  void xoffsets(int count, ...);
  void yoffsets(int count, ...);
  void xset(int count, ...);
  void yset(int count, ...);
  void cleanup(void);
  void Troels_Smith(int, double, double);
  void TSSh1(void);
  void TSSh2(void);
  void TSSh3(void);
  void TSSh4(void);
  void TSTb1(void);
  void TSTb2(void);
  void TSTb3(void);
  void TSTb4(void);
  void TSTbS1(void);
  void TSTbS2(void);
  void TSTbS3(void);
  void TSTbS4(void);
  void TSTbSc1(void);
  void TSTbSc2(void);
  void TSTbSc3(void);
  void TSTbSc4(void);
  void TSTl1(void);
  void TSTl2(void);
  void TSTl3(void);
  void TSTl4(void);
  void TSTh1(void);
  void TSTh2(void);
  void TSTh3(void);
  void TSTh4(void);
  void TSTh41(void);
  void TSTh42(void);
  void TSTh43(void);
  void TSTh44(void);
  void TSDl1(void);
  void TSDl2(void);
  void TSDl3(void);
  void TSDl4(void);
  void TSDh1(void);
  void TSDh2(void);
  void TSDh3(void);
  void TSDh4(void);
  void TSDg1(void);
  void TSDg2(void);
  void TSDg3(void);
  void TSDg4(void);
  void TSLd1(void);
  void TSLd2(void);
  void TSLd3(void);
  void TSLd4(void);
  void TSLso1(void);
  void TSLso2(void);
  void TSLso3(void);
  void TSLso4(void);
  void TSLc1(void);
  void TSLc2(void);
  void TSLc3(void);
  void TSLc4(void);
  void TSLf1(void);
  void TSLf2(void);
  void TSLf3(void);
  void TSLf4(void);
  void TSAs1(void);
  void TSAs2(void);
  void TSAs3(void);
  void TSAs4(void);
  void TSAg1(void);
  void TSAg2(void);
  void TSAg3(void);
  void TSAg4(void);
  void TSGa1(void);
  void TSGa2(void);
  void TSGa3(void);
  void TSGa4(void);
  void TSGs1(void);
  void TSGs2(void);
  void TSGs3(void);
  void TSGs4(void);
  void TSGg_min1(void);
  void TSGg_min2(void);
  void TSGg_min3(void);
  void TSGg_min4(void);
  void TSGg_maj1(void);
  void TSGg_maj2(void);
  void TSGg_maj3(void);
  void TSGg_maj4(void);
  void TStest1(void);
  void TStest2(void);
  void TStest3(void);
  void TStest4(void);
  void TSptest1(void);
  void TSptest2(void);
  void TSptest3(void);
  void TSptest4(void);
  void TSCortSec1(void);
  void TSCortSec2(void);
  void TSCortSec3(void);
  void TSCortSec4(void);
  void TSCort1(void);
  void TSCort2(void);
  void TSCort3(void);
  void TSCort4(void);
};

//---------------------------------------------------------------------------
#endif
