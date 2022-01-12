//---------------------------------------------------------------------------

#ifndef TUpUtilsH
#define TUpUtilsH
#include <Classes.hpp>
#include "pch.h"
#include <set>

//---------------------------------------------------------------------------

class SSELEMENT
{
public:
  UnicodeString Element;
  set<UnicodeString> parts;
  int VariableElementID;
  int ElementTypeID;
  int SymmetryID;
  int PortionID;
  int MaturityID;
public:
  SSELEMENT() { VariableElementID = -1; ElementTypeID = -1; SymmetryID = -1;
	PortionID = -1; MaturityID = -1; }
  SSELEMENT(UnicodeString elem) { Element = elem; VariableElementID = -1;
	ElementTypeID = -1; SymmetryID = -1; PortionID = -1; MaturityID = -1; }
  void ParseParts(UnicodeString Parts);
  bool operator == (const SSELEMENT& compare);
};
//---------------------------------------------------------------------------

void CheckElementFormat(UnicodeString& Element);

#endif
