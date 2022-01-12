//---------------------------------------------------------------------------

#ifndef TIChronH
#define TIChronH
#include <Forms.hpp>
#include <Buttons.hpp>
#include <Chart.hpp>
#include <Classes.hpp>
#include <Controls.hpp>
#include <ExtCtrls.hpp>
#include <Series.hpp>
#include <StdCtrls.hpp>
#include <TeEngine.hpp>
#include <TeeProcs.hpp>
//---------------------------------------------------------------------------
#include <iostream.h>
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxEdit.hpp"
#include "cxMaskEdit.hpp"
#include "cxSpinEdit.hpp"
#include "cxTextEdit.hpp"
#include "ProfGrid.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include "cxButtons.hpp"
#include <Menus.hpp>
#include "dxSkinBlack.hpp"
#include "dxSkinBlue.hpp"
#include "dxSkinBlueprint.hpp"
#include "dxSkinCaramel.hpp"
#include "dxSkinCoffee.hpp"
#include "dxSkinDarkRoom.hpp"
#include "dxSkinDarkSide.hpp"
#include "dxSkinDevExpressDarkStyle.hpp"
#include "dxSkinDevExpressStyle.hpp"
#include "dxSkinFoggy.hpp"
#include "dxSkinGlassOceans.hpp"
#include "dxSkinHighContrast.hpp"
#include "dxSkiniMaginary.hpp"
#include "dxSkinLilian.hpp"
#include "dxSkinLiquidSky.hpp"
#include "dxSkinLondonLiquidSky.hpp"
#include "dxSkinMcSkin.hpp"
#include "dxSkinMetropolis.hpp"
#include "dxSkinMetropolisDark.hpp"
#include "dxSkinMoneyTwins.hpp"
#include "dxSkinOffice2007Black.hpp"
#include "dxSkinOffice2007Blue.hpp"
#include "dxSkinOffice2007Green.hpp"
#include "dxSkinOffice2007Pink.hpp"
#include "dxSkinOffice2007Silver.hpp"
#include "dxSkinOffice2010Black.hpp"
#include "dxSkinOffice2010Blue.hpp"
#include "dxSkinOffice2010Silver.hpp"
#include "dxSkinOffice2013DarkGray.hpp"
#include "dxSkinOffice2013LightGray.hpp"
#include "dxSkinOffice2013White.hpp"
#include "dxSkinOffice2016Colorful.hpp"
#include "dxSkinOffice2016Dark.hpp"
#include "dxSkinPumpkin.hpp"
#include "dxSkinsCore.hpp"
#include "dxSkinsDefaultPainters.hpp"
#include "dxSkinSeven.hpp"
#include "dxSkinSevenClassic.hpp"
#include "dxSkinSharp.hpp"
#include "dxSkinSharpPlus.hpp"
#include "dxSkinSilver.hpp"
#include "dxSkinSpringTime.hpp"
#include "dxSkinStardust.hpp"
#include "dxSkinSummer2008.hpp"
#include "dxSkinTheAsphaltWorld.hpp"
#include "dxSkinValentine.hpp"
#include "dxSkinVisualStudio2013Blue.hpp"
#include "dxSkinVisualStudio2013Dark.hpp"
#include "dxSkinVisualStudio2013Light.hpp"
#include "dxSkinVS2010.hpp"
#include "dxSkinWhiteprint.hpp"
#include "dxSkinXmas2008Blue.hpp"
#include <vector>

#ifndef TIAgeModH
#include "TIAgeMod.h"
#endif
#ifndef TISpreadH
#include "TISpread.h"
#endif

//---------------------------------------------------------------------------
enum LOWESS_SMOOTH_TYPE { LWS_PROP=0, LWS_XWIN=1, LWS_YWIN=2 };

//---------------------------------------------------------------------------
typedef struct
{
  double Depth;
  double Age;
} AGEDEPTH;

//---------------------------------------------------------------------------

bool operator<(const AGEDEPTH&, const AGEDEPTH&);
//bool operator<(const double&, const double&);
//---------------------------------------------------------------------------

typedef struct
{
  double Age;
  double AgeYounger;
  double AgeOlder;
} SAMPLEAGES;

//---------------------------------------------------------------------------

class CHRONDATA
{
public:
  int ChronNumber;
  UnicodeString ChronName;
  UnicodeString AgeUnits;
  int Row;
  bool NewAges;
  vector<SAMPLEAGES> SampleAges;
  vector<AGEDEPTH> Function;

public:
  CHRONDATA(int, UnicodeString, UnicodeString);
  void alloc(int);
};
//---------------------------------------------------------------------------

class AGEMODELGRAPH : public AGEMODEL
{
public:
  bool HasPoints;
  bool HasLimits;
  void GetDepthMinMax(double&, double&);
  void GetAgeMinMax(double&, double&);
};
//---------------------------------------------------------------------------

class CUBICSPLINE
{
private:
  int n;
  vector<double> *x;
  vector<double> *y;
  vector<double> y2;
public:
  CUBICSPLINE(int, vector<double>*, vector<double>*);
  void run(void);
  double splint(double);
};
//---------------------------------------------------------------------------

class BSPLINE
{
private:
  int n;
  vector<double> *x;
  vector<double> *y;
public:
  BSPLINE(int, vector<double>*, vector<double>*);
  double Interp(double xval);
  void Bracket(double, int*, int*);
};
//---------------------------------------------------------------------------

class LOWESS
{
private:
  int n;
  int iter;
  int SmoothType;
  double xwind;
  double ywind;
  vector<double> *x;
  vector<double> *y;
  vector<double> Left;
  vector<double> Right;
public:
  vector<double> ys;
  vector<double> resw;
  vector<double> res;
public:
  LOWESS(vector<double>*, vector<double>*, int, double, double);
  bool run(double, int, double);
  bool lowest(double, double&, int, int, bool, vector<double>&, vector<double>&);
  void interp(vector<double>&, vector<double>&);
};
//---------------------------------------------------------------------------

class POLYNOMIAL
{
private:
  vector<AGEDEPTH>* ChronControls;
  double correl;
  vector<double> ycalc;
  vector<double> resid;
  vector<long double> a;
  vector<long double> xmatr;
  vector<long double> sig;
  unsigned long maxr;
  unsigned long maxc;
  int ndates;
  int ncol;
  int degree;

public:
  double zero_adjust;
  vector<long double> coef;

public:
  POLYNOMIAL(vector<AGEDEPTH>*);
  bool run(int, bool, double);
  void square(void);
  bool gaussj(void);
  void swap(vector<long double>&, int, int);
  double calc_y(double);
};
//---------------------------------------------------------------------------

class TChronForm : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TLabel *Label1;
        TRadioGroup *RadioGroup1;
        TChart *Chart1;
        TComboBox *ComboBox1;
        TLineSeries *Series2;
        TRadioGroup *RadioGroup2;
        TLabeledEdit *LabeledEdit1;
        TLabeledEdit *LabeledEdit2;
        TPointSeries *Series3;
        TPointSeries *Series4;
        TPointSeries *Series1;
        TRadioGroup *RadioGroup3;
        TCheckBox *CheckBox1;
        TcxSpinEdit *cxSpinEdit1;
        TGroupBox *GroupBox1;
        TCheckBox *CheckBox2;
        TCheckBox *CheckBox3;
        TGroupBox *GroupBox2;
        TLabeledEdit *LabeledEdit3;
        TLabeledEdit *LabeledEdit4;
        TGroupBox *GroupBox3;
        TCheckBox *CheckBox4;
	TcxButton *cxButton1;
	TcxButton *cxButton2;
	TcxButton *cxButton3;
	TcxButton *cxButton4;
	TcxButton *cxButton5;
	TcxButton *cxButton6;
	TcxButton *cxButton7;
        void __fastcall FormActivate(TObject *Sender);
        void __fastcall ComboBox1Change(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormDestroy(TObject *Sender);
        void __fastcall RadioGroup2Click(TObject *Sender);
        void __fastcall RadioGroup1Click(TObject *Sender);
        void __fastcall RadioGroup3Click(TObject *Sender);
        void __fastcall Chart1Scroll(TObject *Sender);
        void __fastcall Chart1MouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
        void __fastcall Chart1MouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall Chart1Zoom(TObject *Sender);
        void __fastcall CheckBox2Click(TObject *Sender);
        void __fastcall CheckBox3Click(TObject *Sender);
        void __fastcall LabeledEdit3Change(TObject *Sender);
        void __fastcall LabeledEdit4Change(TObject *Sender);
        void __fastcall LabeledEdit3Exit(TObject *Sender);
        void __fastcall LabeledEdit4Exit(TObject *Sender);
	void __fastcall cxButton1Click(TObject *Sender);
	void __fastcall cxButton3Click(TObject *Sender);
	void __fastcall cxButton4Click(TObject *Sender);
	void __fastcall cxButton5Click(TObject *Sender);
	void __fastcall cxButton6Click(TObject *Sender);
private:	// User declarations
        TList* AgeModelList;
        short AgeModelMethod;
        bool Plot;
        bool CheckBoxChange;
        bool EditChange;
        bool ExtrapYounger;
        bool ExtrapOlder;
        double MinDepthLimit;
        double MaxDepthLimit;
        unsigned int fpoints;
        double lsmooth;
        int lsteps;
        int lSmoothType;
        double lDepthWindow;
        double lAgeWindow;
        int pDegree;
        bool pFixYIntercept;
        vector<long double> Coefs;
        double zero_adjust;
        double pFixedY;
        bool pFitWithinLimits;
        TTilSpreadSheetForm* SSForm;
        void EnableEditing(void);
        void DisableEditing(void);
        void PlotSampleAges(CHRONDATA*);
        void PlotFunction(CHRONDATA*);
        void PlotLinearInterp(AGEMODELGRAPH*);
        bool LinearInterp(vector<AGEDEPTH>&, CHRONDATA*);
        bool CubicSplineInterp(vector<AGEDEPTH>&, CHRONDATA*);
        void spline(int, double*, double*, double*);
        double splint(double*, double*, double*, int, double);
        bool BSpline(vector<AGEDEPTH>&, CHRONDATA*);
        double BsplineValue(int, double*, double*, double);
        void Bracket(int, double*, double, int*, int*);
        bool LowessInterp(vector<AGEDEPTH>&, CHRONDATA*);
        bool PolynomialInterp(vector<AGEDEPTH>&, CHRONDATA*);
        void TestMonotonicity(CHRONDATA*);
        void GetLimits(vector<AGEDEPTH>&, double&, double&);
        void NewAgeModel(CHRONDATA*);
        void SaveToWorksheet(TProfGrid*, CHRONDATA*);
public:		// User declarations
        __fastcall TChronForm(TComponent* Owner);
        TList* Chrons;
        void SetAgeModelList(TAgeModelList*);
        vector<double> Depths;
        //TProfGrid* ProfGrid;
        bool Saved;
};
//---------------------------------------------------------------------------
extern PACKAGE TChronForm *ChronForm;
//---------------------------------------------------------------------------
#endif
