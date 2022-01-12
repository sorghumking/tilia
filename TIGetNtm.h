//---------------------------------------------------------------------------

#ifndef TIGetNtmH
#define TIGetNtmH

#include <vcl.h>
#include "pch.h"
//#include <iostream.h>
#include <set>

//---------------------------------------------------------------------------

class AGEROWS
{
public:
  int Row;
  int YoungerRow;
  int OlderRow;
public:
  AGEROWS() { Row = 0; YoungerRow = 0; OlderRow = 0; }
};
//---------------------------------------------------------------------------

typedef struct
{
  int SampleID;
  int VariableID;
  double Value;
  set<int> TaphTypeIDs;
} TILIADATA;
//---------------------------------------------------------------------------

class VARTAPH
{
public:
  int VariableID;
  set<int> TaphIDs;
public:
  VARTAPH(int var_id, set<int> taph_ids) { VariableID = var_id; TaphIDs = taph_ids; }
  bool operator == (const VARTAPH& compare);
};
//---------------------------------------------------------------------------

#endif
