// Coniss.h
#include "TIConFrm.h"
#include "TIConOut.h"

typedef struct
{
long double Increase;
long double Total;
long double Within;
long double MeanWithin;
} DISPERSION;

class CONISS
{
private:
  FILE *out1;
  TTilSpreadSheetForm* TSSForm;
  int nvars, nlevs;
  bool OutputFileOpen;
  bool counts, perc, prop;
  bool srt, stand, norm, con;
  long double dshort;
  unsigned long p, q;
  int np, nq;
  vector<double> data_array;
  vector<long double> dist_array;
  vector<int> name;
  vector<int> namep;
  vector<int> nameq;
  vector<int> nclus;
  vector<double> levels;
  vector<DISPERSION> es;
  vector<long double> ess;

private:
  void constrained_cluster_analysis(void);
  void unconstrained_cluster_analysis(void);
  void dendrogram_order(void);
  long double update(unsigned long);
  long double d2(unsigned long, unsigned long);
  void output_results(void);
  bool write_dgx_file(void);
  TConissForm *ConissForm;
  TCONISSOutput *ConissOutput;
  TProfGrid* ProfGrid;

public:
  UnicodeString OutputFileName;
  UnicodeString DGXFile;
  bool OutputFileOpenError;
  vector<int> nord;

public:
  CONISS(TTilSpreadSheetForm*, UnicodeString, UnicodeString, int, bool, int, int, TConissForm *);
  bool ReadData(void);
  void run(void);
};
