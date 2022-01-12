//---------------------------------------------------------------------------
#ifndef TGtgxioH
#define TGtgxioH
#include <iostream.h>
#include <fstream.h>
#ifndef TGDiagrmH
#include "TGDiagrm.h"
#endif
#ifndef TIXMLH
#include "TIXML.h"
#endif

//---------------------------------------------------------------------------

class WriteTGX
{
private:
  TTGDiagram *d;
  UnicodeString FileName;
  WriteXML* xmlout;
  TProgressBar *PBar;
  void FontList(TList*, MYFONT&);
  void StyleList(int, TList*, int*, TList*);
  void XaxisList(int, TList*, int*, TList*);

public:
  WriteTGX(UnicodeString, TTGDiagram *);
  ~WriteTGX();
  bool WriteFile(void);
};
#endif
