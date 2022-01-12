//---------------------------------------------------------------------------
#define VCL_IOSTREAM
#include <vcl.h>
#include "pch.h"
#pragma hdrstop

#include <iostream.h>
#include <fstream.h>
#include <math.hpp>
#include <IOUtils.hpp>
#include "ipwxmlp.h"
#ifndef TGUtilsH
#include "TGUtils.h"
#endif
#include "TIXML.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
//---------------------------------------------------------------------------

UnicodeString  __fastcall InsertEntityRefs(UnicodeString& Entity)
{
   UnicodeString NewEnt = Entity;
   int pos;

   int i = 1;
   int end = NewEnt.Length();
   while (i <= end) {
     if (NewEnt.SubString(i, 1) == "&") {
       NewEnt.Insert("amp;", i+1);
       i += 5;
       end += 4;
       }
     else
       i++;
     }
   while ((pos = NewEnt.Pos("<")) > 0) {
     NewEnt.Delete(pos, 1);
     NewEnt.Insert("&lt;", pos);
     }
   while ((pos = NewEnt.Pos(">")) > 0) {
     NewEnt.Delete(pos, 1);
     NewEnt.Insert("&gt;", pos);
     }
   while ((pos = NewEnt.Pos("\"")) > 0) {
     NewEnt.Delete(pos, 1);
     NewEnt.Insert("&quot;", pos);
     }
   while ((pos = NewEnt.Pos("'")) > 0) {
     NewEnt.Delete(pos, 1);
     NewEnt.Insert("&apos;", pos);
     }

   return NewEnt;
}
//---------------------------------------------------------------------------

WideString  __fastcall WInsertEntityRefs(WideString& Entity)
{
   WideString NewEnt = Entity;
   int pos;
   WideString AMP = "&";

   int i = 1;
   int end = NewEnt.Length();
   while (i <= end) {
     if (NewEnt.SubString(i, 1) == AMP) {
       NewEnt.Insert("amp;", i+1);
       i += 5;
       end += 4;
       }
     else
       i++;
     }
   while ((pos = NewEnt.Pos("<")) > 0) {
     NewEnt.Delete(pos, 1);
     NewEnt.Insert("&lt;", pos);
     }
   while ((pos = NewEnt.Pos(">")) > 0) {
     NewEnt.Delete(pos, 1);
     NewEnt.Insert("&gt;", pos);
     }
   while ((pos = NewEnt.Pos("\"")) > 0) {
     NewEnt.Delete(pos, 1);
     NewEnt.Insert("&quot;", pos);
	 }
   while ((pos = NewEnt.Pos("'")) > 0) {
     NewEnt.Delete(pos, 1);
     NewEnt.Insert("&apos;", pos);
     }
   while ((pos = NewEnt.Pos("\r\n")) > 0) {
     NewEnt.Delete(pos, 2);
     NewEnt.Insert(" ", pos);
     }

   return NewEnt;
}
//---------------------------------------------------------------------------

WideString  __fastcall WTranslateEntityRefs(WideString& Entity)
{
   int pos;

   while ((pos = Entity.Pos("&amp;")))
     Entity.Delete(pos+1,4);
   while ((pos = Entity.Pos("&lt;"))) {
     Entity.Delete(pos,4);
     Entity.Insert("<", pos);
     }
   while ((pos = Entity.Pos("&gt;"))) {
     Entity.Delete(pos,4);
     Entity.Insert(">", pos);
     }
   while ((pos = Entity.Pos("&quot;"))) {
     Entity.Delete(pos,6);
     Entity.Insert("\"", pos);
     }
   while ((pos = Entity.Pos("&apos;"))) {
     Entity.Delete(pos,6);
     Entity.Insert("'", pos);
     }
   return Entity;
}
//---------------------------------------------------------------------------

UnicodeString __fastcall USFloatToStr(double value)
{
  UnicodeString sValue = FloatToStr(value);
  if (FormatSettings.DecimalSeparator == COMMA) {
	int Pos = sValue.Pos(",");
	if (Pos > 0) {
	  sValue.Delete(Pos, 1);
	  sValue.Insert(".", Pos);
	  }
	}
  return sValue;
}
//---------------------------------------------------------------------------

UnicodeString __fastcall USFloatToStrF(double Value, TFloatFormat Format, int Precision, int Digits)
{
  double val = (Value < 0) ? -1.0*Value : Value;
  if (val == floor(val))
	Digits = 0;

  UnicodeString sValue = FloatToStrF(Value, Format, Precision, Digits);
  if (FormatSettings.DecimalSeparator == COMMA) {
	int Pos = sValue.Pos(",");
	if (Pos > 0) {
	  sValue.Delete(Pos, 1);
	  sValue.Insert(".", Pos);
	  }
	}
  return sValue;
}
//---------------------------------------------------------------------------

void IntlStrToDouble::SetDecimalSeparator(void)
{
   UnicodeString DecSep;
   OSVERSIONINFO VersionInformation;
   VersionInformation.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
   GetVersionEx(&VersionInformation);
   if (VersionInformation.dwPlatformId == 1) {
	 wchar_t lpBuffer[MAX_PATH];
	 GetWindowsDirectory(lpBuffer, MAX_PATH);
	 UnicodeString WinIni(lpBuffer);
	 WinIni += "\\WIN.INI";
	 TIniFile *ini;
	 ini = new TIniFile(WinIni);
	 DecSep =  ini->ReadString( "intl", "sDecimal", "." );
	 if (DecSep[1] == '.')
	   DecimalSeparator = PERIOD;
	 else if (DecSep[1] == ',')
	   DecimalSeparator = COMMA;
	 delete ini;
     }
   else if (VersionInformation.dwPlatformId == 2) {
     TRegistry& regKey = *new TRegistry();
     regKey.Access = KEY_READ;
     regKey.RootKey = HKEY_CURRENT_USER;
     bool keyGood = regKey.OpenKey("Control Panel\\International", false);
     DecimalSeparator = PERIOD;
     if (keyGood) {
       if (regKey.ValueExists("sDecimal")) {
         DecSep = regKey.ReadString("sDecimal");
         if (DecSep[1] == '.')
           DecimalSeparator = PERIOD;
         else if (DecSep[1] == ',')
           DecimalSeparator = COMMA;
         }
       }
     delete &regKey;
     }
   else
     DecimalSeparator = PERIOD;
}
//---------------------------------------------------------------------------

double IntlStrToDouble::GetDouble(UnicodeString& StrValue)
{
   if (DecimalSeparator == COMMA) {
	 int Pos = StrValue.Pos(".");
	 if (Pos > 0) {
	   StrValue.Delete(Pos, 1);
	   StrValue.Insert(",", Pos);
	   }
	 }
   if (StrValue == "nan" || StrValue == "-nan")
     return 0;
   else
	 return StrToFloatDef(StrValue, 0.0);
}

//---------------------------------------------------------------------------

double IntlStrToDouble::GetDouble(UnicodeString *StrValue)
{
   if (DecimalSeparator == COMMA) {
	 int Pos = StrValue->Pos(".");
	 if (Pos > 0) {
	   StrValue->Delete(Pos, 1);
	   StrValue->Insert(",", Pos);
	   }
	 }
   if (*StrValue == "nan" || *StrValue == "-nan")
     return 0;
   else
     //return StrValue->ToDouble();
     return StrToFloatDef(*StrValue, 0.0);
}
//---------------------------------------------------------------------------

double IntlStrToDouble::GetDouble(UnicodeString& StrValue, double def)
{
   if (DecimalSeparator == COMMA) {
	 int Pos = StrValue.Pos(".");
	 if (Pos > 0) {
	   StrValue.Delete(Pos, 1);
	   StrValue.Insert(",", Pos);
	   }
     }
   return StrToFloatDef(StrValue, def);
}
//---------------------------------------------------------------------------

double IntlStrToDouble::GetDouble(UnicodeString* StrValue, double def)
{
   if (DecimalSeparator == COMMA) {
	 int Pos = StrValue->Pos(".");
     if (Pos > 0) {
       StrValue->Delete(Pos, 1);
       StrValue->Insert(",", Pos);
       }
     }
   return StrToFloatDef(*StrValue, def);
}
//---------------------------------------------------------------------------

UnicodeString IntlStrToDouble::XMLDouble(UnicodeString StrValue)
{
   if (DecimalSeparator == COMMA) {
	 int Pos = StrValue.Pos(".");
	 if (Pos > 0) {
	   StrValue.Delete(Pos, 1);
	   StrValue.Insert(",", Pos);
	   }
	 }
   return StrValue;
}
//---------------------------------------------------------------------------

/*
UnicodeString __fastcall GetAttr(TipwXMLp* ipwXMLp, UnicodeString AttrName)
{
   UnicodeString AttrValue;
   for (int i=0; i<ipwXMLp->AttrCount; i++) {
	 if (ipwXMLp->AttrName[i] == AttrName) {
	   AttrValue = ipwXMLp->AttrValue[i];
	   break;
	   }
	 }
   return AttrValue;
}
//---------------------------------------------------------------------------
*/

WriteXML::WriteXML(UnicodeString fname)
{
   BoolStyle = TRUE_FALSE;
   FileName = fname;
   UnicodeString tname = TPath::GetGUIDFileName(false);
   TempFileName = ExtractFilePath(FileName) + tname + ExtractFileExt(FileName);
   TempFileStream = new TFileStream(TempFileName, fmCreate);
   writer = new TStreamWriter(TempFileStream, TEncoding::UTF8, 1024);
}
//---------------------------------------------------------------------------

WriteXML::~WriteXML()
{
   if (TempFileStream) {
	 writer->Flush();
	 writer->Close();
	 delete writer;
	 }
   if (TempFileStream)
	 delete TempFileStream;
}
//---------------------------------------------------------------------------

void WriteXML::Finish(void)
{
   bool success = true;

   writer->Flush();
   writer->Close();
   delete writer;
   writer = NULL;
   delete TempFileStream;
   TempFileStream = NULL;
   if (FileExists(FileName))
	 success = DeleteFile(FileName);
   if (success) {
	 success = RenameFile(TempFileName, FileName);
	 if (!success)
	 MessageDlg("Temporary file " + TempFileName + "\ncould not be renamed to " +
	   FileName, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 }
   else
	 MessageDlg("Original file " + FileName + "\ncould not be deleted.",
	   Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
}
//---------------------------------------------------------------------------

// <?xml version="1.0" encoding="UTF-8" standalone="yes"?>
void WriteXML::Declaration(UnicodeString version, UnicodeString encoding,
	 UnicodeString standalone)
{
   writer->Write(UnicodeString("<?xml version=\""));
   writer->Write(version);
   writer->Write(UnicodeString("\" encoding=\""));
   writer->Write(encoding);
   writer->Write(UnicodeString("\" standalone=\""));
   writer->Write(standalone);
   writer->Write(UnicodeString("\"?>"));
   writer->WriteLine();
}
//---------------------------------------------------------------------------

 void WriteXML::BeginTag(UnicodeString Tag)
{
   writer->Write(UnicodeString("<"));
   writer->Write(Tag);
   writer->Write(UnicodeString(">"));
   writer->WriteLine();
}
//---------------------------------------------------------------------------

void WriteXML::BeginTag(UnicodeString Tag, UnicodeString AttrName, int AttrValue)
{
   writer->Write(UnicodeString("<"));
   writer->Write(Tag);
   writer->Write(UnicodeString(" "));
   writer->Write(AttrName);
   writer->Write(UnicodeString("=\""));
   writer->Write(AttrValue);
   writer->Write(UnicodeString("\">"));
   writer->WriteLine();
}
//---------------------------------------------------------------------------

void WriteXML::BeginTag(UnicodeString Tag, UnicodeString AttrName, UnicodeString AttrValue)
{
   AttrValue = InsertEntityRefs(AttrValue);
   writer->Write(UnicodeString("<"));
   writer->Write(Tag);
   writer->Write(UnicodeString(" "));
   writer->Write(AttrName);
   writer->Write(UnicodeString("=\""));
   writer->Write(AttrValue);
   writer->Write(UnicodeString("\">"));
   writer->WriteLine();
}
//---------------------------------------------------------------------------

void WriteXML::BeginTag(UnicodeString Tag, UnicodeString AttrName1,
	 UnicodeString AttrValue1, UnicodeString AttrName2, UnicodeString AttrValue2)
{
   AttrValue1 = InsertEntityRefs(AttrValue1);
   AttrValue2 = InsertEntityRefs(AttrValue2);
   writer->Write(UnicodeString("<"));
   writer->Write(Tag);
   writer->Write(UnicodeString(" "));
   writer->Write(AttrName1);
   writer->Write(UnicodeString("=\""));
   writer->Write(AttrValue1);
   writer->Write(UnicodeString("\" "));
   writer->Write(AttrName2);
   writer->Write(UnicodeString("=\""));
   writer->Write(AttrValue2);
   writer->Write(UnicodeString("\">"));
   writer->WriteLine();
}
//---------------------------------------------------------------------------

void WriteXML::BeginTag(UnicodeString Tag, UnicodeString AttrName1, int AttrValue1,
	 UnicodeString AttrName2, UnicodeString AttrValue2)
{
   AttrValue2 = InsertEntityRefs(AttrValue2);
   writer->Write(UnicodeString("<"));
   writer->Write(Tag);
   writer->Write(UnicodeString(" "));
   writer->Write(AttrName1);
   writer->Write(UnicodeString("=\""));
   writer->Write(AttrValue1);
   writer->Write(UnicodeString("\" "));
   writer->Write(AttrName2);
   writer->Write(UnicodeString("=\""));
   writer->Write(AttrValue2);
   writer->Write(UnicodeString("\">"));
   writer->WriteLine();
}
//---------------------------------------------------------------------------

// <Parameter Name="Method" Categorical="1">
void WriteXML::BeginTag(UnicodeString Tag, UnicodeString AttrName1,
	 UnicodeString AttrValue1, UnicodeString AttrName2, int AttrValue2)
{
   AttrValue1 = InsertEntityRefs(AttrValue1);
   writer->Write(UnicodeString("<"));
   writer->Write(Tag);
   writer->Write(UnicodeString(" "));
   writer->Write(AttrName1);
   writer->Write(UnicodeString("=\""));
   writer->Write(AttrValue1);
   writer->Write(UnicodeString("\" "));
   writer->Write(AttrName2);
   writer->Write(UnicodeString("=\""));
   writer->Write(AttrValue2);
   writer->Write(UnicodeString("\">"));
   writer->WriteLine();
}
//---------------------------------------------------------------------------

void WriteXML::BeginTag(UnicodeString Tag, UnicodeString AttrName1, int AttrValue1,
	 UnicodeString AttrName2, int AttrValue2)
{
   writer->Write(UnicodeString("<"));
   writer->Write(Tag);
   writer->Write(UnicodeString(" "));
   writer->Write(AttrName1);
   writer->Write(UnicodeString("=\""));
   writer->Write(AttrValue1);
   writer->Write(UnicodeString("\" "));
   writer->Write(AttrName2);
   writer->Write(UnicodeString("=\""));
   writer->Write(AttrValue2);
   writer->Write(UnicodeString("\">"));
   writer->WriteLine();
}
//---------------------------------------------------------------------------

void WriteXML::BeginTag(UnicodeString Tag, list<XMLATTR>& Attr)
{
   writer->Write(UnicodeString("<"));
   writer->Write(Tag);
   list<XMLATTR>::iterator itr = Attr.begin();
   while (itr != Attr.end()) {
	 writer->Write(UnicodeString(" "));
	 writer->Write((*itr).Name);
	 writer->Write(UnicodeString("=\""));
	 writer->Write((*itr).Value);
	 writer->Write(UnicodeString("\""));
	 itr++;
	 }
   writer->Write(UnicodeString(">"));
   writer->WriteLine();
}
//---------------------------------------------------------------------------

void WriteXML::EndTag(UnicodeString Tag)
{
   writer->Write(UnicodeString("</"));
   writer->Write(Tag);
   writer->Write(UnicodeString(">"));
   writer->WriteLine();
}
//---------------------------------------------------------------------------

void WriteXML::Element(UnicodeString Tag, Variant elem)
{
   Variant dVal;
   switch (elem.Type()) {
	 case varInteger:
	   Element(Tag, (int)elem);
	   break;
	 case varDouble:
	   Element(Tag, (double)elem);
	   break;
	 case varDate:
	   dVal = elem.AsType(varDouble);
	   Element(Tag, dVal);
	   break;
	 default:     // this needed because 0 and negative values were being treated as strings
	   if (!elem.IsEmpty() && !elem.IsNull()) {
		 if (!IsNan(VariantToDouble(elem, NaN)))
		   Element(Tag, (double)elem);
		 }
	   break;
	 }
}
//---------------------------------------------------------------------------

void WriteXML::Element(UnicodeString Tag, UnicodeString Element)
{
   if (!Element.IsEmpty()) {
	 Element = InsertEntityRefs(Element);
	 writer->Write(UnicodeString("<"));
	 writer->Write(Tag);
	 writer->Write(UnicodeString(">"));
	 writer->Write(Element);
	 writer->Write(UnicodeString("</"));
	 writer->Write(Tag);
	 writer->Write(UnicodeString(">"));
	 writer->WriteLine();
	 }
}
//---------------------------------------------------------------------------

void WriteXML::Element(UnicodeString Tag, WideString Element)
{
   if (!Element.IsEmpty()) {
	 Element = WInsertEntityRefs(Element);
	 writer->Write(UnicodeString("<"));
	 writer->Write(Tag);
	 writer->Write(UnicodeString(">"));
	 writer->Write(Element);
	 writer->Write(UnicodeString("</"));
	 writer->Write(Tag);
	 writer->Write(UnicodeString(">"));
	 writer->WriteLine();
	 }
}
//---------------------------------------------------------------------------

void WriteXML::Element(UnicodeString Tag, int Element)
{
   writer->Write(UnicodeString("<"));
   writer->Write(Tag);
   writer->Write(UnicodeString(">"));
   writer->Write(Element);
   writer->Write(UnicodeString("</"));
   writer->Write(Tag);
   writer->Write(UnicodeString(">"));
   writer->WriteLine();
}
//---------------------------------------------------------------------------

void WriteXML::Element(UnicodeString Tag, unsigned int Element)
{
   writer->Write(UnicodeString("<"));
   writer->Write(Tag);
   writer->Write(UnicodeString(">"));
   writer->Write(Element);
   writer->Write(UnicodeString("</"));
   writer->Write(Tag);
   writer->Write(UnicodeString(">"));
   writer->WriteLine();
}
//---------------------------------------------------------------------------

void WriteXML::Element(UnicodeString Tag, double Element)
{
   if (!IsNan(Element)) {
	 writer->Write(UnicodeString("<"));
	 writer->Write(Tag);
	 writer->Write(UnicodeString(">"));
	 writer->Write(USFloatToStr(Element));
	 writer->Write(UnicodeString("</"));
	 writer->Write(Tag);
	 writer->Write(UnicodeString(">"));
	 writer->WriteLine();
	 }
}
//---------------------------------------------------------------------------

void WriteXML::Element(UnicodeString Tag, long double Element)
{
   if (!IsNan(Element)) {
	 writer->Write(UnicodeString("<"));
	 writer->Write(Tag);
	 writer->Write(UnicodeString(">"));
	 writer->Write(USFloatToStr(Element));
	 writer->Write(UnicodeString("</"));
	 writer->Write(Tag);
	 writer->Write(UnicodeString(">"));
	 writer->WriteLine();
	 }
}
//---------------------------------------------------------------------------

void WriteXML::Element(UnicodeString Tag, bool Element)
{
   writer->Write(UnicodeString("<"));
   writer->Write(Tag);
   writer->Write(UnicodeString(">"));
   switch (BoolStyle) {
	 case TRUE_FALSE:
	   writer->Write((Element) ? UnicodeString("True") : UnicodeString("False"));
	   break;
	 case ONE_ZERO:
	   writer->Write((Element) ? UnicodeString("1") : UnicodeString("0"));
	   break;
	 }
   writer->Write(UnicodeString("</"));
   writer->Write(Tag);
   writer->Write(UnicodeString(">"));
   writer->WriteLine();
}
//---------------------------------------------------------------------------

// <Category Value="1">AMS</Category>
void WriteXML::Element(UnicodeString Tag, UnicodeString AttrName, int AttrValue,
	UnicodeString Element)
{
   if (!Element.IsEmpty()) {
	 Element = InsertEntityRefs(Element);
	 writer->Write(UnicodeString("<"));
	 writer->Write(Tag);
	 writer->Write(UnicodeString(" "));
	 writer->Write(AttrName);
	 writer->Write(UnicodeString("=\""));
	 writer->Write(AttrValue);
	 writer->Write(UnicodeString("\">"));
	 writer->Write(Element);
	 writer->Write(UnicodeString("</"));
	 writer->Write(Tag);
	 writer->Write(UnicodeString(">"));
	 writer->WriteLine();
	 }
}
//---------------------------------------------------------------------------

//<Value Null="0" Rare="0">-24</Value>
void WriteXML::ElementAttr(UnicodeString Tag, double Element,
	 UnicodeString AttrName1, bool AttrValue1,
	 UnicodeString AttrName2, bool AttrValue2)
{
   if (IsNan(Element)) return;

   UnicodeString AttrVal1, AttrVal2;

   switch (BoolStyle) {
	 case TRUE_FALSE:
	   AttrVal1 = (AttrValue1) ? "True" : "False";
	   AttrVal2 = (AttrValue2) ? "True" : "False";
	   break;
	 case ONE_ZERO:
	   AttrVal1 = (AttrValue1) ? "1" : "0";
	   AttrVal2 = (AttrValue2) ? "1" : "0";
	   break;
	 }
   writer->Write(UnicodeString("<"));
   writer->Write(Tag);
   writer->Write(UnicodeString(" "));
   writer->Write(AttrName1);
   writer->Write(UnicodeString("=\""));
   writer->Write(AttrVal1);
   writer->Write(UnicodeString("\" "));
   writer->Write(AttrName2);
   writer->Write(UnicodeString("=\""));
   writer->Write(AttrVal2);
   writer->Write(UnicodeString("\">"));
   writer->Write(USFloatToStr(Element));
   writer->Write(UnicodeString("</"));
   writer->Write(Tag);
   writer->Write(UnicodeString(">"));
   writer->WriteLine();
}
//---------------------------------------------------------------------------

void WriteXML::EmptyElement(UnicodeString Tag)
{
   writer->Write(UnicodeString("<"));
   writer->Write(Tag);
   writer->Write(UnicodeString("/>"));
   writer->WriteLine();
}
//---------------------------------------------------------------------------

void WriteXML::EmptyElement(UnicodeString Tag, UnicodeString AttrName, int AttrValue)
{
   writer->Write(UnicodeString("<"));
   writer->Write(Tag);
   writer->Write(UnicodeString(" "));
   writer->Write(AttrName);
   writer->Write(UnicodeString("=\""));
   writer->Write(AttrValue);
   writer->Write(UnicodeString("\"/>"));
   writer->WriteLine();
}
//---------------------------------------------------------------------------

void WriteXML::EmptyElement(UnicodeString Tag, UnicodeString AttrName, UnicodeString AttrValue)
{
   AttrValue = InsertEntityRefs(AttrValue);
   writer->Write(UnicodeString("<"));
   writer->Write(Tag);
   writer->Write(UnicodeString(" "));
   writer->Write(AttrName);
   writer->Write(UnicodeString("=\""));
   writer->Write(AttrValue);
   writer->Write(UnicodeString("\"/>"));
   writer->WriteLine();
}
//---------------------------------------------------------------------------

// <Parameter Name="C/N" Categorical="0"/>
void WriteXML::EmptyElement(UnicodeString Tag, UnicodeString AttrName1,
	UnicodeString AttrValue1, UnicodeString AttrName2, int AttrValue2)
{
   AttrValue1 = InsertEntityRefs(AttrValue1);
   writer->Write(UnicodeString("<"));
   writer->Write(Tag);
   writer->Write(UnicodeString(" "));
   writer->Write(AttrName1);
   writer->Write(UnicodeString("=\""));
   writer->Write(AttrValue1);
   writer->Write(UnicodeString("\" "));
   writer->Write(AttrName2);
   writer->Write(UnicodeString("=\""));
   writer->Write(AttrValue2);
   writer->Write(UnicodeString("\"/>"));
   writer->WriteLine();
}
//---------------------------------------------------------------------------

void WriteXML::CDATA(UnicodeString Tag, UnicodeString Text)
{
   writer->Write(UnicodeString("<"));
   writer->Write(Tag);
   writer->Write(UnicodeString("><![CDATA["));
   writer->Write(Text);
   writer->Write(UnicodeString("]]></"));
   writer->Write(Tag);
   writer->Write(UnicodeString(">"));
   writer->WriteLine();
}
//---------------------------------------------------------------------------

void WriteXML::Comment(UnicodeString comment)
{
   //<!--comment-->
   comment = InsertEntityRefs(comment);
   writer->Write(UnicodeString("<!--"));
   writer->Write(comment);
   writer->Write(UnicodeString("-->"));
   writer->WriteLine();
}
//---------------------------------------------------------------------------

void WriteXML::DateTime(void)
{
   UnicodeString datestr;
   DateTimeToString(datestr, "dd-mmm-yyyy", Date());
   Comment("written " + datestr + " " + Time());
}
//---------------------------------------------------------------------------

ParseXMLUnicode::ParseXMLUnicode(TipwXMLp* ipwxmlp)
{
   ipwXMLp = ipwxmlp;
   ipwXMLp->Config("CodePage=65001");   // UTF-8 CodePage
}
//---------------------------------------------------------------------------

UnicodeString ParseXMLUnicode::RootElement(void)
{
   ipwXMLp->XPath = "/";
   return ipwXMLp->XElement;
}
//---------------------------------------------------------------------------

bool __fastcall ParseXMLUnicode::ValidChild(UTF8String XPath, UTF8String ChildName)
{
   ipwXMLp->XPath = XPath;
   int nc = ipwXMLp->XChildrenCount;
   for (int i=0; i<nc; i++) {
	 if (ipwXMLp->XChildName[i] == ChildName) {
	   if (XPath.SubString(XPath.Length(),1) != "/")
		 XPath += "/";
	   XPath += ChildName;
	   ipwXMLp->XPath = XPath;
	   return true;
	   }
	 }
   return false;
}
//---------------------------------------------------------------------------

bool __fastcall ParseXMLUnicode::ValidChild(UTF8String XPath, UTF8String ChildName, int& count)
{
   ipwXMLp->XPath = XPath;
   int nc = ipwXMLp->XChildrenCount;
   for (int i=0; i<nc; i++) {
	 if (ipwXMLp->XChildName[i] == ChildName) {
	   if (XPath.SubString(XPath.Length(),1) != "/")
		 XPath += "/";
	   XPath += ChildName;
	   ipwXMLp->XPath = XPath;
	   count = ipwXMLp->XChildrenCount;
	   return true;
	   }
	 }
   return false;
}
//---------------------------------------------------------------------------

int __fastcall ParseXMLUnicode::XChildrenCount(void)
{
   return ipwXMLp->XChildrenCount;
}
//---------------------------------------------------------------------------

bool __fastcall ParseXMLUnicode::GetTextValue(UTF8String XPath, UnicodeString& Value)
{
   Value.SetLength(0);
   try {
	   ipwXMLp->XPath = XPath;
	   Value = ipwXMLp->XText;
	   }
   catch(Exception &e)
	   {
	   MessageDlg("Error parsing file. Class " + e.ClassName() + ". " + e.Message,
				  mtWarning, TMsgDlgButtons() << mbOK, 0);
	   return false;
	   }
   return true;
}
//---------------------------------------------------------------------------

bool __fastcall ParseXMLUnicode::GetTextValue(UTF8String XPath,
	UTF8String Element, UnicodeString& Value)
{
   Value.SetLength(0);
   try {
	   if (ValidChild(XPath, Element)) {
		 Value = ipwXMLp->XText;
		 return true;
		 }
	   else
		 return false;
	   }
   catch(Exception &e)
	   {
	   MessageDlg("Error parsing file. Class " + e.ClassName() + ". " + e.Message,
				  mtWarning, TMsgDlgButtons() << mbOK, 0);
	   return false;
	   }
}
//---------------------------------------------------------------------------

bool __fastcall ParseXMLUnicode::GetChildText(int XChildIndex, UnicodeString& utext)
{
   try {
	   utext = ipwXMLp->XChildXText[XChildIndex];
	   return true;
	   }
   catch (Exception &e) {
	   MessageDlg("Error parsing file. Class " + e.ClassName() + ". " + e.Message,
				  mtWarning, TMsgDlgButtons() << mbOK, 0);
	   return false;
	   }
}
//---------------------------------------------------------------------------

bool __fastcall ParseXMLUnicode::SetXPath(UTF8String XPath)
{
   try {
	   ipwXMLp->XPath = XPath;
	   return true;
	   }
   catch (Exception &e) {
	   MessageDlg("Error parsing file. Class " + e.ClassName() + ". " + e.Message,
				  mtWarning, TMsgDlgButtons() << mbOK, 0);
	   return false;
	   }
}
//---------------------------------------------------------------------------

UnicodeString __fastcall ParseXMLUnicode::GetChildName(int XChildIndex)
{
   return ipwXMLp->XChildName[XChildIndex];
}
//---------------------------------------------------------------------------

bool __fastcall ParseXMLUnicode::GetBoolValue(UTF8String XPath,
	UTF8String Element, bool& Value)
{
   try {
	   if (ValidChild(XPath, Element)) {
		 UTF8String BoolVal =  ipwXMLp->XText.LowerCase();
		 if (BoolVal == "true")
		   Value = true;
		 else if (BoolVal == "false")
		   Value = false;
		 else
		   return false;
		 return true;
		 }
	   else
		 return false;
	   }
   catch(Exception &e)
	   {
	   MessageDlg("Error parsing file. Class " + e.ClassName() + ". " + e.Message,
				  mtWarning, TMsgDlgButtons() << mbOK, 0);
	   return false;
	   }
}
//---------------------------------------------------------------------------

bool __fastcall ParseXMLUnicode::GetDoubleValue(UTF8String XPath,
	UTF8String Element, double& Value)
{
   Value = NaN;
   try {
	   if (ValidChild(XPath, Element)) {
		 Value = GetDoubleFromText(ipwXMLp->XText, NaN);
		 if (IsNan(Value))
		   return false;
		 else if (fabs(Value) > 3.3E221) {
		   Value = NaN;
		   return false;
		   }
		 else
		   return true;
		 }
	   else
		 return false;
	   }
   catch(Exception &e)
	   {
	   MessageDlg("Error parsing file. Class " + e.ClassName() + ". " + e.Message,
				  mtWarning, TMsgDlgButtons() << mbOK, 0);
	   return false;
	   }
}
//---------------------------------------------------------------------------

bool __fastcall ParseXMLUnicode::GetIntValue(UTF8String XPath, UTF8String Element, int& iValue)
{
   // iValue = MaxInt;
   try {
	   if (ValidChild(XPath, Element)) {
		 iValue = ipwXMLp->XText.ToInt();
		 return (iValue < MaxInt);
		 }
	   else
		 return false;
	   }
   catch(Exception &e)
	   {
	   MessageDlg("Error parsing file. Class " + e.ClassName() + ". " + e.Message,
				  mtWarning, TMsgDlgButtons() << mbOK, 0);
	   return false;
	   }
}
//---------------------------------------------------------------------------

bool __fastcall ParseXMLUnicode::GetIntValue(UTF8String XPath, UTF8String Element, Variant& Value)
{
   int iValue;
   if (ValidChild(XPath, Element)) {
	 if (TryStrToInt(ipwXMLp->XText, iValue)) {
	   Value = iValue;
	   return true;
	   }
	 else {
	   MessageDlg("Error parsing file.", mtWarning, TMsgDlgButtons() << mbOK, 0);
	   return false;
	   }
	 }
   else
	 return false;
}
//---------------------------------------------------------------------------

// in this version, XPath is already set
bool __fastcall ParseXMLUnicode::GetAttrInt(UTF8String AttrName, int& AttrValue)
{
   AttrValue = MaxInt;
   try {
	   AttrValue = ipwXMLp->Attr(AttrName).ToInt();
	   return (AttrValue < MaxInt);
	   }
   catch(Exception &e)
	   {
	   MessageDlg("Error parsing file. Class " + e.ClassName() + ". " + e.Message,
				  mtWarning, TMsgDlgButtons() << mbOK, 0);
	   return false;
	   }
}
//---------------------------------------------------------------------------

// this version sets XPath
bool __fastcall ParseXMLUnicode::GetAttrInt(UTF8String XPath, UTF8String AttrName,
	int& AttrValue)
{
   AttrValue = MaxInt;
   try {
	   ipwXMLp->XPath = XPath;
	   AttrValue = ipwXMLp->Attr(AttrName).ToInt();
	   return (AttrValue < MaxInt);
	   }
   catch(Exception &e)
	   {
	   MessageDlg("Error parsing file. Class " + e.ClassName() + ". " + e.Message,
				  mtWarning, TMsgDlgButtons() << mbOK, 0);
	   return false;
	   }
}
//---------------------------------------------------------------------------

// this version sets XPath
bool __fastcall ParseXMLUnicode::GetAttrStr(UTF8String XPath, UTF8String AttrName,
	UnicodeString& AttrValue)
{
   try {
	   ipwXMLp->XPath = XPath;
	   AttrValue = ipwXMLp->Attr(AttrName);
	   return !AttrValue.IsEmpty();
	   }
   catch(Exception &e)
	   {
	   MessageDlg("Error parsing file. Class " + e.ClassName() + ". " + e.Message,
				  mtWarning, TMsgDlgButtons() << mbOK, 0);
	   return false;
	   }
}
//---------------------------------------------------------------------------

UnicodeString __fastcall ParseXMLUnicode::GetElementName(UTF8String XPath)
{
   ipwXMLp->XPath = XPath;
   return ipwXMLp->XElement;
}
//---------------------------------------------------------------------------

UTF8String __fastcall XMLSubElement::XPath(int i)
{
   UTF8String SubElementXPath = ElementPath + "[" + IntToStr(i) + "]";
   return SubElementXPath;
}
//---------------------------------------------------------------------------






