// Utility functions
//---------------------------------------------------------------------------
#ifndef TGUtilsH
#define TGUtilsH
#include <vcl.h>
#include "pch.h"
#include <vector>
#include <list>
#include <set>
#include <iterator>
#include <iostream.h>
#include <fstream.h>
#include "cxColorComboBox.hpp"
#include "System.hpp"

enum SIGN { MINUS=0, PLUS=1 };
enum LATORLONG { LATITUDE=0, LONGITUDE=1 };
enum DMS { DEG=0, DEGMIN=1, DEGMINSEC=2 };

class MYFONT;

//---------------------------------------------------------------------------
typedef struct
{
  UnicodeString Code;
  UnicodeString Name;
} CODENAME;
//---------------------------------------------------------------------------

double pi(void);
int nint(double);
double maxdouble(double *, int);
double maxdouble(vector<double>&, int);
double mindouble(double *, int);
double mindouble(vector<double>&, int);
double yinterp(double, double, double, double, double);
double radians(double);
double auto_step(double, double);
double auto_min(double, double);
double auto_max(double, double, double);
bool eventic(double, double, double);
UnicodeString FloatFormat(int, int);
UnicodeString FloatFormat(int);
void SetStaticText(TStaticText*, MYFONT&);
UnicodeString PlainText(UnicodeString&);
void FormatString(UnicodeString&, int, int, int, int*);
UnicodeString LeadingTabs(short);  //??
void DeleteList(TList*);
int GetFontNumber(TList*, MYFONT&);
UnicodeString CheckEntityRefs(UnicodeString&); // should eventually be defunct
WideString CheckEntityRefs(WideString&);
void CheckEntityRefs(TEdit*);
double GetDoubleFromText(UnicodeString, double);
UnicodeString ColumnNameByIndex(int);
AnsiString ToISO_8859_1(AnsiString);
UnicodeString RemoveNewLines(UnicodeString& Text);
UnicodeString RemoveCR(UnicodeString& Text);
double __fastcall ValidateNumericalDisplayValue(Variant&, TCaption&, bool&);
int __fastcall NeotomaCompare(TStringList*, int, int);
UnicodeString __fastcall Capitalize(UnicodeString&);
void ParseDelimitedList(UnicodeString, vector<UnicodeString>&, UnicodeString);
void TI_TryStrToFloat(UnicodeString, double&);
void ParseParts(UnicodeString Element, UnicodeString Separator, vector<UnicodeString>& parts);
void ParsePartsIC(UnicodeString Element, UnicodeString Separator, vector<UnicodeString>& parts);
void ParsePartsIC(UnicodeString Element, UnicodeString Separator, set<UnicodeString>& parts);
bool sets_equal(set<int>& set1, set<int>& set2);
bool sets_equal(set<int>& set1, const set<int>& set2);
//---------------------------------------------------------------------------

class LineWidthComboBox
{
private:
  TComboBox* lwComboBox;
public:
  LineWidthComboBox(TComboBox*);
  void SetLineWidth(double);
  double GetLineWidth(void);
};
//---------------------------------------------------------------------------

class Encryption
{
private:
	UTF8String key;
	void Crypt(TBytes& input);
public:
	Encryption(UTF8String k) { key = k; }
	void Encrypt(UTF8String& guid);
	bool Decrypt(UTF8String& input);
	void Encrypt(UnicodeString& guid);
	bool Decrypt(UnicodeString& input);
};
//---------------------------------------------------------------------------

class EntityRefs
{
private:
  UnicodeString Copy;
public:
  UnicodeString Text;
public:
  EntityRefs(UnicodeString txt) { Text = txt; Copy = txt; }
  void Tag(UnicodeString);
  void SubRefs(void);
  UnicodeString GetText(void) { return Text; }
};
//---------------------------------------------------------------------------

class wEntityRefs
{
private:
  WideString Copy;
public:
  WideString Text;
public:
  wEntityRefs(WideString& txt) { Text = txt; Copy = txt; }
  void Tag(WideString);
  void SubRefs(void);
  WideString GetText(void) { return Text; }
};
//---------------------------------------------------------------------------

class intdbl
{
public:
  int i;
  double x;
public:
  intdbl(double xx) { x = xx; i = nint(xx); }
  intdbl(int ii) { i = ii; x = (double)ii; }
};
//---------------------------------------------------------------------------

class LATLONG
{
private:
  double decdeg;
  bool set;
public:
  LATLONG() { set = false; }
  LATLONG(double deg) { decdeg = deg; set = true; }
  void set_dd(double deg) { decdeg = deg; set = true; }
  void set_dd(double deg, double min, double sec, UnicodeString&);
  bool set_dd(UnicodeString&, UnicodeString&, UnicodeString&, bool, int);
  double dd(void) { return decdeg; }
  int deg(void);
  double dmin(void);
  int min(void);
  double dsec(void);
  void set_sign(int);
  bool is_set(void) { return set; }
  void reset(void) { set = false; }
};
//---------------------------------------------------------------------------

class EReadBinaryFileError : public Exception
{
public:
  __fastcall EReadBinaryFileError(const UnicodeString Msg) : Exception(Msg){}
};

#endif


