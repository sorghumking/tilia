/* ta_struc.h */
/* data structures used in tilia programs */

#define NULLDATA 0x01
#define NUMDATA  0x02
#define RARETYPE 0x04
#define STRGDATA 0x07

#define SMOOTHED     1
#define EQUALSAMPLES 2
#define RATEOFCHANGE 3

typedef struct
  {
    unsigned long maxtypes;
    unsigned long maxlevs;
    int field_width;
    int nfields;
    int ndec;
    int bgr[20];
    int fgr[20];
    int tl_bold;
    int bold;
    int bold1;
    int color;
    int adapter;
    int showVarNums;
    int xms;
    char tilia_path[80];
    char working_dir[80];
    char form_path[80];
    unsigned char AgeVarCode[9];
    unsigned char DepthVarCode[9];
    unsigned char ConcName[61];
    unsigned char ConcVarCode[9];
    unsigned char QuantSampleVarCode[9];
    unsigned char QuantSpikeVarCode[9];
    unsigned char ConcSpikeVarCode[9];
    unsigned char SpikeVarCode[9];
    unsigned char SpikeAddedVarCode[9];
    unsigned char QuantExamVarCode[9];
    unsigned char DepTimeVarCode[9];
    unsigned char DepTimeName[61];
    unsigned char AccRateVarCode[9];
    unsigned char AccRateName[61];
    unsigned char nMovAvgVarCode[9];
    unsigned char nMovAvgName[61];
    unsigned char ROCVarCode[9];
    unsigned char ROCName[61];
  } CFG;
/*
typedef struct
  {
  int vars;
  int levs;
  int showVarNums;
  int dummy1;
  int dummy8;
  int data_smoothed;
  int sums_calculated;
  int conc_calculated;
  int sample_toggle;
  int dates;
  int sums;
  int maxdates;
  int dummy2;
  int dummy3;
  int dummy4;
  int dummy5;
  int dummy6;
  int dummy7;
  } N;
*/

typedef struct
  {
  short vars;
  short levs;
  short showVarNums;
  short dummy1;
  short dummy8;
  short data_smoothed;
  short sums_calculated;
  short conc_calculated;
  short sample_toggle;
  short dates;
  short sums;
  short maxdates;
  short dummy2;
  short dummy3;
  short dummy4;
  short dummy5;
  short dummy6;
  short dummy7;
  } N;


typedef struct
  {
  float x;
  union
    {
    unsigned char byte;
    struct
      {
      unsigned char null   : 1;
      unsigned char num    : 1;
      unsigned char rare   : 1;
      unsigned char string : 1;
      unsigned char unused : 4;
      } attr;
    } flag;
  } DATA;

typedef struct
  {
  char null;
  int n;
  } NULLINT;

typedef struct
  {
  NULLINT VarNum;
  unsigned char sum;
  unsigned char name[61];
  unsigned char VarCode[9];
  } VARS;

typedef struct
  {
  float num;
  unsigned char name[11];
  } SAMPLES;
