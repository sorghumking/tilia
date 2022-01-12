//---------------------------------------------------------------------------
//#include <vcl.h>
//#include "pch.h"
#pragma hdrstop

#include <iostream.h>
#include <fstream.h>
#include "math.hpp"
#ifndef TGUtilsH
#include "TGUtils.h"
#endif
#ifndef TGTextH
#include "TGText.h"
#endif
#ifndef TGH
#include "tg.h"
#endif
#ifndef TIXMLH
#include "TIXML.h"
#endif


//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
double pi(void)
{
  return(3.14159265358979);
}

//---------------------------------------------------------------------------
int nint(double x)
{
  double ax = x;
  if (ax < 0.0) ax = -ax;
  int i = (int)ax;
  if ((ax - floor(ax)) >= 0.5) i++;
  if (x < 0.0) i = -i;
  return i;
}
//---------------------------------------------------------------------------

// finds max value in float array
double maxdouble(double x[], int na)
{
  int i;
  double max;
  max = x[0];
  for (i=1; i<na; i++)
	if (x[i] > max) max = x[i];
  return(max);
}
//---------------------------------------------------------------------------

double maxdouble(vector<double>& x, int na)
{
  int i;
  double max;
  max = x[0];
  for (i=1; i<na; i++)
	if (x[i] > max) max = x[i];
  return(max);
}
//---------------------------------------------------------------------------

// finds min value in float array
double mindouble(double x[], int na)
{
  int i;
  double min;
  min = x[0];
  for (i=1; i<na; i++)
    if (x[i] < min) min = x[i];
  return(min);
}
//---------------------------------------------------------------------------

double mindouble(vector<double>& x, int na)
{
  int i;
  double min;
  min = x[0];
  for (i=1; i<na; i++)
	if (x[i] < min) min = x[i];
  return(min);
}
//---------------------------------------------------------------------------

// calculates y value for given x between 2 points x1,y1 and x2,y2
double yinterp(double x1, double y1, double x2, double y2, double x0)
{
  double y0;
  y0 = y1 + (x0-x1)*(y2-y1)/(x2-x1);
  return(y0);
}

//---------------------------------------------------------------------------
double radians(double degrees)
{
  return(0.01745329*degrees);
}

//---------------------------------------------------------------------------
double auto_step(double dmin, double dmax)
{
  double dlen, ytic_pow, step;

  dlen = dmax-dmin;
  ytic_pow = log10(dlen/10.0);
  if (ytic_pow-floor(ytic_pow) >= 0.5)
    ytic_pow = ceil(ytic_pow);
  else
    ytic_pow = floor(ytic_pow);
  step = pow(10.0, ytic_pow)/2.0;
  return(step);
}

//---------------------------------------------------------------------------
double auto_min(double dmin, double tic)
{
  double tic_min;
  tic_min = 0.0;
  if (dmin >= 0.0)
    {
      while (tic_min < dmin)
	tic_min += tic;
      if (tic_min-dmin >= tic/2.0)
	tic_min -= tic;
    }
  else
    {
      while (tic_min > dmin)
	tic_min -= tic;
      if (dmin-tic_min > tic/2.0)
	tic_min += tic;
    }
  return(tic_min);
}

//---------------------------------------------------------------------------
// calculates automatic axis maximum
double auto_max(double dmax, double tic_min, double tic)
{
  double tic_max;
  tic_max = tic_min;
  while (tic_max < dmax)
    tic_max += tic;
  if (dmax-tic_max > tic/2.0)
    tic_max -= tic;
  return(tic_max);
}

//---------------------------------------------------------------------------
bool eventic(double sum_tic, double major_tic, double minor_tic)
{
  double r;
  r = sum_tic/major_tic;
  if (fabs(r-nint(r)) < (minor_tic/major_tic)/2.0)
    return(true);
  else
    return(false);
}

//---------------------------------------------------------------------------
UnicodeString FloatFormat(int FieldWidth, int DecPnts)
{
  UnicodeString FieldWidthStr(FieldWidth);
  UnicodeString DecPntsStr(DecPnts);
  return ("%" + FieldWidthStr + "." + DecPntsStr + "f");
}

//---------------------------------------------------------------------------
UnicodeString FloatFormat(int DecPnts)
{
  UnicodeString Fmt = "0.";
  for (int i=1; i<=DecPnts; i++)
    Fmt += "0";
  return Fmt;  
}
//---------------------------------------------------------------------------

/*
void InitializeArray(double *array, int n, double initializer)
{
  for (int i=0; i<n; i++)
	array[i] = initializer;
}
//---------------------------------------------------------------------------

void InitializeArray(vector<double>& array, int n, double initializer)
{
  array.assign(n, initializer);
}
//---------------------------------------------------------------------------

void InitializeArray(int *array, int n, int initializer)
{
  for (int i=0; i<n; i++)
	array[i] = initializer;
}

//---------------------------------------------------------------------------
*/

void SetStaticText(TStaticText* StaticText, MYFONT& Font)
{
  StaticText->Font->Name = Font.FontName;
  StaticText->Caption = Font.FontName;
  StaticText->Font->Color = (TColor)Font.Color;
  if (Font.Style.bold)
    StaticText->Font->Style = StaticText->Font->Style << fsBold;
  else
    StaticText->Font->Style = StaticText->Font->Style >> fsBold;
  if (Font.Style.italic)
    StaticText->Font->Style = StaticText->Font->Style << fsItalic;
  else
    StaticText->Font->Style = StaticText->Font->Style >> fsItalic;
}
//---------------------------------------------------------------------------

UnicodeString PlainText(UnicodeString& InText)
{
   int idx;
   UnicodeString Text = InText;
   while ((idx = Text.Pos("\\")) > 0)
     Text.Delete(idx, 2);
   return Text;
}
//---------------------------------------------------------------------------

void FormatString(UnicodeString& str, int Style, int curpos, int SelLen,
                  int *Advance)
{
   int pos1, pos2;
   UnicodeString StartTag, EndTag;

   switch (Style) {
     case BOLD:
       StartTag = "<b>";
       EndTag = "</b>";
       break;
     case ITALIC:
       StartTag = "<i>";
       EndTag = "</i>";
       break;
     case SUPERSCRIPT:
       StartTag = "<sup>";
       EndTag = "</sup>";
       break;
     case SUBSCRIPT:
       StartTag = "<sub>";
       EndTag = "</sub>";
       break;
     }

   bool done = false;

   // remove formatting if already present
   if (str.Length() == SelLen) {
	 if (str.Pos(StartTag) || str.Pos(EndTag)) {
	   while (pos1=str.Pos(StartTag))
		  str.Delete(pos1, StartTag.Length());
       while (pos2=str.Pos(EndTag))
          str.Delete(pos2, EndTag.Length());
       done = true;
       }
     }

   if (!done) {
     UnicodeString Selected = str.SubString(curpos+1, SelLen);
     pos2 = Selected.Length()-EndTag.Length()+1;
     if (Selected.SubString(1,StartTag.Length()) == StartTag &&
         Selected.SubString(pos2,EndTag.Length()) == EndTag) {
           str.Delete(pos2, EndTag.Length());
           str.Delete(1, StartTag.Length());
           *Advance = SelLen - StartTag.Length() - EndTag.Length();
           done = true;
         }
     }

   if (!done) {
     pos1 = curpos - StartTag.Length() + 1;
     pos2 = curpos + SelLen + 1;
     if (pos1 >= 0) {
       if (str.SubString(pos1,StartTag.Length()) == StartTag &&
           str.SubString(pos2,EndTag.Length()) == EndTag) {
             str.Delete(pos2, EndTag.Length());
             str.Delete(pos1, StartTag.Length());
             *Advance = SelLen - StartTag.Length();
             done = true;
           }
       }
     }

   // otherwise insert formatting tags
   if (!done) {
     str.Insert(EndTag, curpos+SelLen+1);
     str.Insert(StartTag, curpos+1);
     *Advance = StartTag.Length() + EndTag.Length() + SelLen;
     }
}
//---------------------------------------------------------------------------

UnicodeString LeadingTabs(short n)
{
  UnicodeString tabs;
  for (short i=0; i<n; i++)
    tabs += "\t";
  return tabs;
}
//---------------------------------------------------------------------------

void DeleteList(TList* List)
{
  for (int i=0; i<List->Count; i++) {
    void* Item = (void*)List->Items[i];
    delete Item;
    List->Items[i] = 0;
    }
  List->Clear();
  delete List;
}
//---------------------------------------------------------------------------

int GetFontNumber(TList* Fonts, MYFONT& Font)
{
  for (int i=0; i<Fonts->Count; i++)
    if (Font == *(MYFONT*)Fonts->Items[i]) return i;
  return 0;
}
//---------------------------------------------------------------------------

UnicodeString CheckEntityRefs(UnicodeString& Text)
{
   // & < >
   // <i>Ambrosia</i>-type
   EntityRefs er(Text);
   er.Tag("&lt;");
   er.Tag("&gt;");
   er.Tag("&amp;");
   er.Tag("<i>");
   er.Tag("</i>");
   er.Tag("<b>");
   er.Tag("</b>");
   er.Tag("<g>");
   er.Tag("</g>");
   er.Tag("<sup>");
   er.Tag("</sup>");
   er.Tag("<sub>");
   er.Tag("</sub>");
   er.SubRefs();
   Text = er.GetText();
   return Text;
}
//---------------------------------------------------------------------------

WideString CheckEntityRefs(WideString& Text)
{
   // & < >
   // <i>Ambrosia</i>-type
   wEntityRefs er(Text);
   er.Tag(L"&lt;");
   er.Tag(L"&gt;");
   er.Tag(L"&amp;");
   er.Tag(L"<i>");
   er.Tag("</i>");
   er.Tag("<b>");
   er.Tag("</b>");
   er.Tag("<g>");
   er.Tag("</g>");
   er.Tag("<sup>");
   er.Tag("</sup>");
   er.Tag("<sub>");
   er.Tag("</sub>");
   er.SubRefs();
   Text = er.GetText();
   return Text;
}
//---------------------------------------------------------------------------

void CheckEntityRefs(TEdit* Edit)
{
   // & < >
   // <i>Ambrosia</i>-type
   UnicodeString Text = Edit->Text;
   EntityRefs er(Text);
   er.Tag("&lt;");
   er.Tag("&gt;");
   er.Tag("&amp;");
   er.Tag("<i>");
   er.Tag("</i>");
   er.Tag("<b>");
   er.Tag("</b>");
   er.Tag("<g>");
   er.Tag("</g>");
   er.Tag("<sup>");
   er.Tag("</sup>");
   er.Tag("<sub>");
   er.Tag("</sub>");
   er.SubRefs();
   Edit->Text = er.GetText();
}
//---------------------------------------------------------------------------

void EntityRefs::Tag(UnicodeString tag)
{
   int pos = Copy.Pos(tag);
   while (pos > 0) {
     Copy.Delete(pos, tag.Length());
     UnicodeString filler = UnicodeString::StringOfChar('#', tag.Length());
     Copy.Insert(filler, pos);
     pos = Copy.Pos(tag);
     }
}
//---------------------------------------------------------------------------

void wEntityRefs::Tag(WideString tag)
{
   int pos = Copy.Pos(tag);
   while (pos > 0) {
	 Copy.Delete(pos, tag.Length());
	 WideString filler = WideString::StringOfChar(L'#', tag.Length());
	 Copy.Insert(filler, pos);
	 pos = Copy.Pos(tag);
	 }
}
//---------------------------------------------------------------------------

void EntityRefs::SubRefs(void)
{
   int pos = Copy.Pos("&");
   while (pos > 0) {
	 Copy.Delete(pos, 1);
	 Text.Delete(pos, 1);
	 Copy.Insert("#####", pos);
	 Text.Insert("&amp;", pos);
	 pos = Copy.Pos("&");
	 }
   pos = Copy.Pos("<");
   while (pos > 0) {
	 Copy.Delete(pos, 1);
	 Text.Delete(pos, 1);
	 Copy.Insert("&lt;", pos);
	 Text.Insert("&lt;", pos);
	 pos = Copy.Pos("<");
	 }
   pos = Copy.Pos(">");
   while (pos > 0) {
	 Copy.Delete(pos, 1);
	 Text.Delete(pos, 1);
	 Copy.Insert("&gt;", pos);
	 Text.Insert("&gt;", pos);
	 pos = Copy.Pos(">");
	 }
}
//---------------------------------------------------------------------------

void wEntityRefs::SubRefs(void)
{
   int pos = Copy.Pos("&");
   while (pos > 0) {
	 Copy.Delete(pos, 1);
	 Text.Delete(pos, 1);
	 Copy.Insert("#####", pos);
	 Text.Insert("&amp;", pos);
	 pos = Copy.Pos("&");
	 }
   pos = Copy.Pos("<");
   while (pos > 0) {
	 Copy.Delete(pos, 1);
	 Text.Delete(pos, 1);
	 Copy.Insert("&lt;", pos);
	 Text.Insert("&lt;", pos);
	 pos = Copy.Pos("<");
	 }
   pos = Copy.Pos(">");
   while (pos > 0) {
	 Copy.Delete(pos, 1);
	 Text.Delete(pos, 1);
	 Copy.Insert("&gt;", pos);
	 Text.Insert("&gt;", pos);
	 pos = Copy.Pos(">");
	 }
}
//---------------------------------------------------------------------------

double GetDoubleFromText(UnicodeString Text, double DefaultValue)
{
    double Value;
    if (Text.IsEmpty())
      Value = DefaultValue;
    else 
      Value = IntlStrToDouble::GetDouble(Text, DefaultValue);
    return Value;
}
//---------------------------------------------------------------------------

LineWidthComboBox::LineWidthComboBox(TComboBox* lwCB)
{
   lwComboBox = lwCB;
   lwComboBox->Items->Add("Hairline");
   lwComboBox->Items->Add(FloatToStr(0.5));
   lwComboBox->Items->Add(FloatToStr(0.75));
   lwComboBox->Items->Add(FloatToStr(1.0));
   lwComboBox->Items->Add(FloatToStr(1.5));
   lwComboBox->Items->Add(FloatToStr(2.0));
   lwComboBox->Items->Add(FloatToStr(2.5));
   lwComboBox->Items->Add(FloatToStr(3.0));
   lwComboBox->Items->Add(FloatToStr(4.0));
   lwComboBox->ItemIndex = 0;
}
//---------------------------------------------------------------------------

void LineWidthComboBox::SetLineWidth(double lw)
{
   if (lw <= 0.25) {
     lwComboBox->ItemIndex = 0;
     lwComboBox->Text = "Hairline";
     }
   else
     lwComboBox->Text = FormatFloat("0.0######", lw);
}
//---------------------------------------------------------------------------

double LineWidthComboBox::GetLineWidth(void)
{
   double LineWidth;
   UnicodeString Text = lwComboBox->Text.LowerCase();
   if (Text == "hairline")
     LineWidth = 0.25;
   else
     LineWidth = IntlStrToDouble::GetDouble(Text, 0.25);
   if (LineWidth < 0.25) LineWidth = 0.25;
   return LineWidth;
}
//---------------------------------------------------------------------------

void Encryption::Encrypt(UnicodeString& guid)
{
   UTF8String UTF8guid = guid;
   Encrypt(UTF8guid);
   guid = UTF8guid;
}
//---------------------------------------------------------------------------

// Idea from http://www.codeproject.com/cpp/crypt_routine.asp
void Encryption::Encrypt(UTF8String& guid)
{
   TBytes bytes = guid.BytesOf();
   int Length = bytes.Length;

   Crypt(bytes);
   // now we have the original guid encyrpted and held in Data

   // now transform encyrpted guid to hex representation
   guid.SetLength(0);
   for (int i=0; i<Length; i++) {
	 int value = bytes[i];
	 guid += IntToHex((int)value, 2);
	 }

	/*
	//AnsiString temp = guid;
    int Length = guid.Length();
    unsigned char *temp = new unsigned char [Length];
    for (int i=0; i<Length; i++)
      temp[i] = guid[i+1];

    Crypt(temp, Length);
    // now we have the original guid encyrpted and held in Data

    // now transform encyrpted guid to hex representation
    UnicodeString Hex;

    guid.SetLength(0);
    for (int i=0; i<Length; i++) {
      int value = temp[i];
      guid += IntToHex((int)value, 2);
      }
	delete[] temp;
	*/
}
//---------------------------------------------------------------------------

bool Encryption::Decrypt(UnicodeString& input)
{
   UTF8String UTF8input = input;
   if (Decrypt(UTF8input)) {
	 input = UTF8input;
	 return true;
	 }
   else
     return false;
}
//---------------------------------------------------------------------------

bool Encryption::Decrypt(UTF8String& input)
{
   // first translate from hex representation
   int Length = input.Length();
   TBytes bytes;
   bytes.Length = Length/2;

   AnsiString HexValue;
   unsigned char ch[2];
   ch[1] = '\0';
   char c;
   for (int i=1, k=0; i<Length; i+=2, k++) {
	 HexValue = "0x" + input.SubString(i,2);
	 // char c = HexValue.ToInt();
	 try {
	   c = HexValue.ToInt();
	   }
	 catch (...) {
	   MessageDlg("Invalid Product Key.", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return false;
	   }
	 bytes[k] = (unsigned char)c;
	 }

   // decrypt the original encrypted string
   Crypt(bytes);
   input = TEncoding::UTF8->GetString(bytes);
   return true;

   /*
   // first translate from hex representation
   int Length = input.Length();
   int lentemp = Length/2;
   unsigned char *temp = new unsigned char [lentemp];
   AnsiString HexValue;
   char ch[2];
   ch[1] = '\0';
   char c;
   for (int i=1, k=0; i<Length; i+=2, k++) {
     HexValue = "0x" + input.SubString(i,2);
	 try
	   {
	   c = HexValue.ToInt();
	   }
	 catch (...)
	   {
	   MessageDlg("Invalid Product Key.", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   delete[] temp;
	   return false;
	   }
     temp[k] = (unsigned char)c;
     }

   // decrypt the original encrypted string
   Crypt(temp, lentemp);
   input.SetLength(0);
   for (int i=0; i<lentemp; i++) {
     ch[0] = temp[i];
     AnsiString chr = ch;
     input += chr;
     }

   delete[] temp;
   return true;
   */
}
//---------------------------------------------------------------------------

// void Encryption::Crypt(unsigned char *input, int Length)
void Encryption::Crypt(TBytes& input)
{
   TBytes box;
   box.Length = input.Length;

   TBytes bkey = key.BytesOf();
   int i = 0;
   int j = 0;
   while (i < input.Length) {
	 box[i++] = bkey[j++];
	 if (j == bkey.Length)
	   j = 0;
	 }

   // the problem when decrypting is differentiating '\0' from '0'
   for (int i=0; i<input.Length; i++) {
	 unsigned char a = input[i];
	 unsigned char b = box[i];
	 a = a ^ b;
	 input[i] = a;
	 }
/*
   AnsiString box;
   while (box.Length() < Length)
	 box += key;

   // the problem when decrypting is differentiating '\0' from '0'
   for (int i=0; i<Length; i++) {
	 unsigned char a = input[i];
	 unsigned char b = box[i+1];
	 a = a ^ b;
	 input[i] = a;
	 }
*/
}
//---------------------------------------------------------------------------

UnicodeString ColumnNameByIndex(int ACol)
{
  UnicodeString Letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  UnicodeString Letter = " ";
  UnicodeString Result;

  if (ACol > 26)
    Result = Result + ColumnNameByIndex((ACol-1)/26);
  int k = ACol%26;
  if (k == 0) k = 26;
  Letter[1] = Letters[k];
  Result = Result + Letter;

  return Result;
}
//---------------------------------------------------------------------------

AnsiString ToISO_8859_1(AnsiString Entity)
{
   AnsiString NewEnt = Entity;

   for (int i=NewEnt.Length(); i>0; i--) {
     unsigned char ch = NewEnt[i];
     if (ch < 32 || (ch > 126 && ch < 160)) {
       AnsiString CharRef = "&#" + IntToStr((int)ch) + ";";
       NewEnt.Delete(i, 1);
       NewEnt.Insert(CharRef, i);
       }
     }
   return NewEnt;
}
//---------------------------------------------------------------------------

UnicodeString RemoveNewLines(UnicodeString& Text)
{
   UnicodeString NewText = Text.Trim();
   int pos;
   while ((pos = NewText.Pos(L"\r\n")) > 0) {
	 NewText.Delete(pos, 2);
	 NewText.Insert(" ", pos);
	 }
   return NewText;
}
//---------------------------------------------------------------------------

UnicodeString RemoveCR(UnicodeString& Text)
{
   UnicodeString NewText = Text.Trim();
   UnicodeString FinalText;
   int pos = NewText.Pos(L"\\r\\n");
   while (pos > 0) {
	 if (!FinalText.IsEmpty())
	   FinalText += L"\n";
	 FinalText += NewText.SubString(1,pos-1);
	 NewText.Delete(1,pos+3);
	 pos = NewText.Pos(L"\\r\\n");
	 }
   if (!FinalText.IsEmpty())
	 FinalText += L"\n";
   FinalText += NewText;
   return FinalText;
}
//---------------------------------------------------------------------------

double __fastcall ValidateNumericalDisplayValue(Variant &DisplayValue,
    TCaption &ErrorText, bool &Error)
{
   double Value = NaN;
   UnicodeString ValueStr = DisplayValue;
   if (!ValueStr.IsEmpty()) {
     if (!TryStrToFloat(ValueStr, Value)) {
       Error = true;
       ErrorText = "Invalid input value. Must be numerical value.\nUse escape key to abandon changes.";
       }
     }
   return Value;
}
//---------------------------------------------------------------------------

void LATLONG::set_dd(double deg, double min, double sec, UnicodeString& hemi)
{
  decdeg = deg + (min + sec/60.0)/60.0;
  UnicodeString hemisphere = hemi.UpperCase();
  if (hemisphere == "S" || hemisphere == "W")
    decdeg *= -1.0;
  set = true;
}
//---------------------------------------------------------------------------

bool LATLONG::set_dd(UnicodeString& DegStr, UnicodeString& MinStr, UnicodeString& SecStr,
                     bool minus, int LatLong)
{
  double d, m, s;
  set = false;

  try {
      if (DegStr.Length())
		d = DegStr.ToDouble();
      else
        d = 0.0;
      if (MinStr.Length())
        m = MinStr.ToDouble();
      else
        m = 0.0;
      if (SecStr.Length())
        s = SecStr.ToDouble();
      else
        s = 0.0;
      }
  catch(Exception &e) {
	  MessageDlg(e.Message, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	  return false;
      }
  if (LatLong == LATITUDE && (d < 0.0 || d > 90.0))
	MessageDlg("Degrees latitude must be >= 0 and <= 90", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
  else if (LatLong == LONGITUDE && (d < 0.0 || d > 180.0))
	MessageDlg("Degrees longitude must be >= 0 and <= 180", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
  else if (m < 0.0 || m >= 60.0)
	MessageDlg("Minutes must be >= 0 and < 60", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
  else if (s < 0.0 || s >= 60.0)
    MessageDlg("Seconds must be >= 0 and < 60", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
  else {
    decdeg = d + (m + s/60.0)/60.0;
    if (minus)
      decdeg *= -1.0;
    set = true;
    }
  return set;
}
//---------------------------------------------------------------------------

int LATLONG::deg(void)
{
  return (int)floor(fabs(decdeg));
}
//---------------------------------------------------------------------------

double LATLONG::dmin(void)
{
  double d = fabs(decdeg);
  double dm = 60.0*(d - floor(d));
  if (fabs(dm-RoundTo(dm, -5)) < 0.0000001)
    dm = RoundTo(dm, -5);
  return dm;
}
//---------------------------------------------------------------------------

int LATLONG::min(void)
{
  return (int)floor(dmin());
}
//---------------------------------------------------------------------------

double LATLONG::dsec(void)
{
  double dm = dmin();
  double ds = 60.0*(dm - floor(dm));
  if (fabs(ds-RoundTo(ds, -5)) < 0.0000001)
    ds = RoundTo(ds, -5);
  return ds;
}
//---------------------------------------------------------------------------

void LATLONG::set_sign(int sign)
{
  switch (sign)
  {
  case PLUS:
    if (decdeg < 0.0) decdeg *= -1.0;
    break;
  case MINUS:
    if (decdeg > 0.0) decdeg *= -1.0;
    break;
  };
}
//---------------------------------------------------------------------------

int __fastcall NeotomaCompare(TStringList* List, int Index1, int Index2)
{
  UnicodeString str1 = List->Strings[Index1];
  UnicodeString str2 = List->Strings[Index2];
  return AnsiCompareText(str1, str2);
}
//---------------------------------------------------------------------------

UnicodeString __fastcall Capitalize(UnicodeString& str)
{
   UnicodeString Text = str;
   Text.Insert(Text.SubString(1,1).UpperCase(), 1);
   Text.Delete(2,1);
   return Text;
}
//---------------------------------------------------------------------------

void TI_TryStrToFloat(UnicodeString Text, double &Value)
{
   if (Text.IsEmpty())
     Value = NaN;
   else {
     try {
         Value = Text.ToDouble();
         }
     catch(Exception &e) {
		 MessageDlg(e.Message, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
         }
     }
}
//---------------------------------------------------------------------------

void ParseDelimitedList(UnicodeString Text, vector<UnicodeString>& parsed_list, UnicodeString Delimiter)
{
   int idx, len;
   UnicodeString element;
   parsed_list.clear();
   while ((idx = Text.Pos(Delimiter)) > 0) {
	 element = Text.SubString(1,idx-1).Trim();
	 if (element.Length() > 1) {
	   if (element[1] == L'\"')
		 element.Delete(1,1);
	   len = element.Length();
	   if (len > 0 && element[len] == L'\"')
		 element.Delete(len,1);
	   }
	 parsed_list.push_back(element);
	 Text.Delete(1,idx);
	 }
   if (!Text.IsEmpty())
	 parsed_list.push_back(Text);
}
//---------------------------------------------------------------------------

void ParseParts(UnicodeString Element, UnicodeString Separator, vector<UnicodeString>& parts)
{
   parts.clear();
   if (Element.IsEmpty()) return;
   int pos = Element.Pos(Separator);
   while (pos > 0) {     // get vector of delimited parts
	 parts.push_back(Element.SubString(1,pos-1).Trim().LowerCase());
	 Element.Delete(1,pos);
	 pos = Element.Pos(Separator);
	 }
   parts.push_back(Element.Trim().LowerCase());
}
//---------------------------------------------------------------------------

void ParsePartsIC(UnicodeString Element, UnicodeString Separator, vector<UnicodeString>& parts)
{
   parts.clear();
   if (Element.IsEmpty()) return;
   int pos = Element.Pos(Separator);
   while (pos > 0) {     // get vector of delimited parts
	 parts.push_back(Element.SubString(1,pos-1).Trim());
	 Element.Delete(1,pos);
	 pos = Element.Pos(Separator);
	 }
   parts.push_back(Element.Trim());
}
//---------------------------------------------------------------------------

void ParsePartsIC(UnicodeString Element, UnicodeString Separator, set<UnicodeString>& parts)
{
   parts.clear();
   if (Element.IsEmpty()) return;
   int pos = Element.Pos(Separator);
   while (pos > 0) {     // get vector of delimited parts
	 parts.insert(Element.SubString(1,pos-1).Trim());
	 Element.Delete(1,pos);
	 pos = Element.Pos(Separator);
	 }
   parts.insert(Element.Trim());
}
//---------------------------------------------------------------------------

bool sets_equal(set<int>& set1, set<int>& set2)
{
   if (set1.size() == 0 && set2.size() == 0)
	 return true;
   else if (set1.size() != set2.size())
	 return false;
   else {
	 set<int>::iterator it1;
	 set<int>::iterator it2;
	 for (it1=set1.begin(),it2=set2.begin(); it1 != set1.end(); it1++,it2++) {
	   if (*it1 != *it2)
		 return false;
	   }
	 }
   return true;
}
//---------------------------------------------------------------------------

bool sets_equal(set<int>& set1, const set<int>& set2)
{
   if (set1.size() == 0 && set2.size() == 0)
	 return true;
   else if (set1.size() != set2.size())
	 return false;
   else {
	 set<int>::iterator it1;
	 set<int>::const_iterator it2;
	 for (it1=set1.begin(),it2=set2.begin(); it1 != set1.end(); it1++,it2++) {
	   if (*it1 != *it2)
		 return false;
	   }
	 }
   return true;
}
//---------------------------------------------------------------------------




