//---------------------------------------------------------------------------
#include <fstream>
#ifndef TgtgfioH
#define TgtgfioH
#include <vector>
#ifndef TGDOS
#include "TGDOS.h"
#endif
#ifndef TISpreadH
#include "TISpread.h"
#endif
#ifndef TILithH
#include "TILith.h"
#endif
#ifndef TIGeochrH
#include "TIGeochr.h"
#endif
#ifndef TIAgeModH
#include "TIAgeMod.h"
#endif
#ifndef TIloiH
#include "TIloi.h"
#endif

//---------------------------------------------------------------------------

enum FORMVARTYPE { CHARVAR=1, FLOATVAR, INTVAR, YNVAR, TFVAR, HIDDENCHAR,
                   HIDDENFLOAT, DATEVAR, BLOBVAR };
                   

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
  char null;
  short n;
  } NULLINT;

typedef struct
  {
  NULLINT VarNum;
  unsigned char sum;
  UnicodeString VarName;
  UnicodeString VarCode;
  } VARS;

typedef struct
  {
  short vars;
  short levs;
  short groups;
  short zones;
  short zlabels;
  short dates;
  short text;       // number of text blocks
  short boxes;
  short lith;       // number of lithology units
  short lithboxes;  // number of lith boxes
  bool dend;
  } TGN;

typedef struct
  {
  double red;
  double green;
  double blue;
  } COLOR;

typedef struct
  {
  short g;
  short e;
  } GROUPCOLOR;  

typedef struct
  {
  short a_color_index;  	// axes
  short d_color_index;	        // dendrogram
  short f_color_index;    	// default foreground color
  short g_color_index;	        // default graph color
  short e_color_index;	        // default exaggeration color
  short o_color_index;          // exaggeration outline color
  short t_color_index;	        // default text color
  short h_color_index;  	// header color
  short z_color_index;	        // default zone color
  short r_color_index;	        // frame color
  bool shades_of_gray;          // shades of gray
  GROUPCOLOR group_index[26];	// group graph colors
  COLOR d_color[16];		// available colors
  COLOR s_color[24];		// pre-set colors
  } COLORS;

typedef struct
  {
  UnicodeString ext;
  int seqnum;
  int formtype;
  int nfields;
  int ntext;
  int fleft;
  int fright;
  int ftop;
  int fbottom;
  int clrscr;
  int maxrecords;
  int nrecords;
  } HEADER;

typedef struct
  {
  double Depth;
  double thickness;
  UnicodeString analyst;
  UnicodeString Notes;
  TDateTime date;
  } SAMPLEMETADATA;

class ReadDOSFile
{
protected:
  double version;
  ifstream infile;
  bool InputFileOpen;
  char buffer[1024];
  short getshort(char *);
  unsigned short getushort(char *);
  double getdouble(char *);
  double getdoubleNan(char *);
  double getfloat(char *);
  UnicodeString getUnicodeString1(UnicodeString&, char *);
  UnicodeString getUnicodeString2(UnicodeString&, char *);
  void ConvertToggles(WideString&);
  TColor DOSColorToRGB(COLOR *, Byte);
  void SpecialVarCodes(UnicodeString&);
};

class ReadTIL : public ReadDOSFile
{
private:
   TTilSpreadSheetForm *TSSForm;
   AnsiString TilFileName;
   HEADER hdr;
   TipwXMLp *LookUp;
   int CurrentSampleCol;
   TPoint rcmax;
private:
   void ReadHeader(void);
   bool strvar (int f) {
     return (f==CHARVAR || f==YNVAR || f==TFVAR || f==BLOBVAR || f==HIDDENCHAR);
     }
   void openFormFile(UnicodeString&);
   bool readFormVar(double*, UnicodeString&, UnicodeString&);
   bool OpenLookupFile(void);
   UnicodeString TranslateRCode(UnicodeString&);
   void SetPreparer(UnicodeString&, AGEMODEL*, TContactList*);
   int GetSampleCol(double);
   UnicodeString FormAnalystCode(CONTACT*);
   void SetTempComboBox(TComboBox*, int);
public:
   ReadTIL(UnicodeString&, TTilSpreadSheetForm*);
   ~ReadTIL();
   void ReadTiliaFile(void);
   bool ReadSITForm(SITE*, COLLECTION&, DATASET*, TContactList*);
   void ReadPUBForm(TList*);
   void ReadLTHForm(TLithologyUnitList*);
   void ReadPB2Form(TGeochronList*);
   void ReadC14Form(TGeochronList*);
   void ReadAGEForm(TAgeModelList*, TContactList*);
   void ReadSMPForm(TContactList*);
   void ReadLOIForm(void);
};

class ReadTGF : public ReadDOSFile
{
private:
  double AxisLineWidth;
  TTGDiagram *d;
  UnicodeString TGFileName;
  COLORS co;
  MYFONT DefaultFont;
  UnicodeString Message;
  YAXIS yax;
  TGN n;
  TList *Vars;
  int *vdx;

private:
  int ReadTGFFile(void);
  void TranslateColors(TTGDiagram *);
  double FontHeight(double);
  void DecodeTGN126(char *);
  void DecodeTGN123(char *);
  void DecodeTGN119(char *);
  void DecodeColors126(char *);
  void DecodeColors111(char *);
  void DecodeLineWidths126(char *);
  void DecodeRareSpecies126(char *);
  void DecodeLimits126(char *);
  void DecodeLithOptions126(char *);
  void DecodeLithOptions120(char *);
  void DecodeGRAPHS126(char *, GRAPHS *);
  void DecodeGRAPHS125(char *, GRAPHS *);
  void DecodeXAXIS126(char *, XAXIS *);
  void DecodeXAXIS117(char *, XAXIS *);
  void DecodeXAXIS116(char *, XAXIS *);
  void DecodeYAXIS126(char *);
  void DecodeYAXIS118(char *);
  void DecodeYAXIS117(char *);
  void DecodeYAXIS110(char *);
  void DecodeVarNames126(int, char *);
  void DecodeVarNames118(int, char *);
  void DecodeDendOptions126(char *);
  void DecodeDendrogram126(char *, DENDROGRAM *);
  void DecodeGroups126(char *);
  void DecodeGroups118(char *);
  void DecodeZoneDefault126(char *);
  void DecodeZoneDefault115(char *);
  void DecodeZones126(char *);
  void DecodeZones115(char *);
  void DecodeZoneOptions126(char *);
  void DecodeZoneLabels126(char *);
  void DecodeDateOptions126(char *);
  void DecodeDates126(char *);
  void DecodeLith126(int, char *);
  void DecodeLith122(int, char *);
  void DecodeLith121(int, char *);
  void ProcessLith(LITHUNIT*, LITHCOMPONENT*);
  void DecodeLithKey126(int, char *);
  void DecodeLithKey124(int, char *);
  void DecodeLithKey123(int, char *);
  void DecodeText126(char *);
  void ReOrderVars(void);

public:
  ReadTGF(UnicodeString&, TTGDiagram*);
  ~ReadTGF();
  int ReadFile(void);
};

#endif
