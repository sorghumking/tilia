//---------------------------------------------------------------------------
#ifndef TItlxoutH
#define TItlxoutH
#include <ComCtrls.hpp>
#include <vector>
#ifndef TISpreadH
#include "TISpread.h"
#endif
#ifndef TIPubH
#include "TIPub.h"
#endif
#ifndef TIXMLH
#include "TIXML.h"
#endif
#include <iostream.h>
#include <fstream.h>

//---------------------------------------------------------------------------
//bool operator<(const GEOCHRON&, const GEOCHRON&);
//---------------------------------------------------------------------------

class WriteTLX
{
private:
  TTilSpreadSheetForm *TSSForm;
  UnicodeString FileName;
  TStringList* cList;
  TProgressBar *PBar;
  void WriteCommonPubFields(UnicodeString, PUBLICATION*);
  void WriteAuthors(vector<AUTHOR>&);
  void WriteEditors(UnicodeString&);
  void WriteEditors(vector<EDITOR>&);
  void WriteTranslators(vector<EDITOR>&);
  int getAuthorContactId(CONTACT*);
  WriteXML* xmlout;
  void WriteIsotopeSample(int row, bool IsSeries);
  void WriteIsotopeMetadata(short isotope, ISOMETADATA& IsoMetadata);
  void WriteIsotopeData(int col, int row, short isotope);
public:
  WriteTLX(UnicodeString&, TTilSpreadSheetForm *);
  bool WriteFile(void);
};
//---------------------------------------------------------------------------

class EtlxWriteError : public Exception
{
public:
  __fastcall EtlxWriteError(const UnicodeString Msg) : Exception(Msg){}
};

#endif
