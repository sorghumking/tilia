//---------------------------------------------------------------------------

#ifndef TIConcH
#define TIConcH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include "cxCheckListBox.hpp"

#include <vector>
#ifndef TISpreadH
#include "TISpread.h"
#endif
#ifndef TIConcFmH
#include "TIConcFm.h"
#endif
#ifndef TIFluxFmH
#include "TIFluxFm.h"
#endif


enum TREATNULLS { SKIPNULL, ZERONULL };
//---------------------------------------------------------------------------

class CalculateConc
{
private:
  TTilSpreadSheetForm* TSSForm;
  TConcForm* ConcForm;
  vector<int> ToConc;
  TStringList* VarCodes;
  TStringList* Groups;
  int HeaderCols;
  int ColCount;
  int TreatNulls;

private:
  void CalcConc(int);
  void GetConcVarRows(TcxCheckListBox*, vector<int>&);
  double GetConcValue(int, vector<int>&);

public:
  CalculateConc(TTilSpreadSheetForm* tss) { TSSForm = tss; }
  bool Run(void);
};
//---------------------------------------------------------------------------

class CalculateInflux
{
private:
  TTilSpreadSheetForm* TSSForm;
  int TreatNulls;

private:
  void CalcInflux(void);
  int Evaluate(Variant&, int, int, double&);

public:
  CalculateInflux(TTilSpreadSheetForm* tss) { TSSForm = tss; }
  void Run(void);
};

#endif
