//---------------------------------------------------------------------------


#pragma hdrstop

#include "TUpUtils.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

void SSELEMENT::ParseParts(UnicodeString Parts)
{
   Parts = Parts.Trim();
   if (Parts.IsEmpty())
	 return;

   UnicodeString Separator = L";";
   //UnicodeString Separator = (Parts.Pos(L";") > 0) ? L";" : L",";
   int pos = Parts.Pos(Separator);
   while (pos > 0) {
	 parts.insert(Parts.SubString(1,pos-1));
	 Parts.Delete(1,pos);
	 Parts = Parts.TrimLeft();
	 pos = Parts.Pos(Separator);
	 }
   parts.insert(Parts);
}
//---------------------------------------------------------------------------

bool SSELEMENT::operator == (const SSELEMENT& compare )
{
   if (this == &compare) return true;
   return SameText(Element, compare.Element);
}
//---------------------------------------------------------------------------

void CheckElementFormat(UnicodeString& Element)
{
   Element = Element.Trim();
   int pos;
   do { pos = Element.Pos(L"  ");
		if (pos > 0)
		  Element.Delete(pos,1);
	  } while (pos > 0);
   int idx = Element.Length()-1;
   while (idx > 0) {
	 if (Element[idx] == L',' || Element[idx] == L';') {
	   if (Element[idx+1] != L' ')
		 Element.Insert(L" ",idx+1);
	   }
	 idx--;
	 }
}
//---------------------------------------------------------------------------


