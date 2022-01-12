//---------------------------------------------------------------------------

#ifndef TIChkVarUtilsH
#define TIChkVarUtilsH
#include "pch.h"
#include <vector>

//---------------------------------------------------------------------------

typedef struct
{
  UnicodeString name;
  UnicodeString author;
  int row;
  vector<UnicodeString> parents;
} SSVAR;
//---------------------------------------------------------------------------

#endif
