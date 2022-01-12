#ifndef TGDOS
#define TGDOS
//---------------------------------------------------------------------------
#ifndef TGTextH
#include "TGText.h"
#endif
//---------------------------------------------------------------------------
class TGVARS
{
public:
  char status;
  UnicodeString sum;
  UnicodeString code;
  UnicodeString name;
public:
  bool read(ifstream *);
  bool write(ofstream *);
};

typedef struct
  {
  double x;
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
  } DOSDATA;


typedef struct	   // YAXIS used for DOS .tgf files only
{
  bool plot_primary;	    // TRUE if primary axis plotted
  bool plot_secondary;      // TRUE if secondary axis plotted
  bool automin;	            // TRUE if min automatically calculated
  bool automax;	            // TRUE if max automatically calculated
  bool automin1;	    // TRUE if min scale1 automatically calculated
  bool automax1;	    // TRUE if max scale1 automatically calculated
  bool automin2;	    // TRUE if min scale2 automatically calculated
  bool automax2;	    // TRUE if max scale2 automatically calculated
  bool autotic1;	    // TRUE if tic marks automatically calculated
  bool autotic2;            // TRUE if tic marks automatically calculated
  short style;	            // standard, column, or sample names
  short primary;	    // 0 if default, 1 if depth, 2 if age
  short secondary;	    // 0 if default, 1 if depth, 2 if age
  short axisNo;             // Chron or Depth number
  short ticdec1;	    // decimal points in tic labels scale 1
  short ticdec2;	    // decimal points in tic labels scale 2
  short label_position1;    // position of label 1
  short label_position2;    // position of label 2
  TColor color;                                          // new
  double LineWidth;                                      // new
  double space;             // space between y-axis and first graph
  double len;               // length of the y-axis
  double xdist;             // distance of x-axis from axis limits
  double min;               // minimim value on y-axis
  double max;               // maximum value on y-axis
  double min1;              // minimim value on scale 1
  double max1;              // maximum value on scale 1
  double min2;              // minimim value on scale 2
  double max2;              // maximum value on scale 2
  double minor_tics1;       // distance between minor tics scale 1
  double major_tics1;       // distance between minor tics scale 1
  double minor_tics2;       // distance between minor tics scale 2
  double major_tics2;       // distance between minor tics scale 2
  double ticfac1;           // factor tic labels divided by for scale 1
  double ticfac2;           // factor tic labels divided by for scale 2
  double LabelToTicDistance;  // distance label is plotted from tic mark
  double MajorTicLength;     // length major x-axis tic mark
  double MinorTicLength;     // length minor x-axis tic mark
  double xlab1;             // x-coordinate of label 1
  double ylab1;             // y-coordinate of label 1
  double xlab2;             // x-coordinate of label 2
  double ylab2;             // y-coordinate of label 2
  double angle1;            // angle of label 1
  double angle2;            // angle of label 2
  UnicodeString label1;        // y-axis label 1
  UnicodeString label2;        // y-axis label 2
  MYFONT TicFont;
  MYFONT LabelFont;
} YAXIS;


//---------------------------------------------------------------------------
#endif
 