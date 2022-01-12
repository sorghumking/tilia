//---------------------------------------------------------------------------
#include <vcl.h>
#include <Character.hpp>
#pragma hdrstop
#include "TNUtils.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
//---------------------------------------------------------------------------

bool check_cf(UnicodeString Name, UnicodeString& NewName)
{
   // if return is true, a change is necessary and should be made
   // if return is false and Name == NewName, a change was not necessary
   // if return is false and Name != NewName, a change is necessary, but should not be made
   int pos;
   UnicodeString msg;
   bool change = false;
   NewName = Name;

   if ((pos = Name.Pos(L" cf. ")) > 0) {
	 bool correct = false;
	 if (Name.Length() > pos+7) {
	   if (Name[pos+4] == L' ' &&
		 IsLetter(Name[pos+5]) &&
		 Name[pos+6] == L'.'   &&
		 Name[pos+7] == L' '   &&
		 IsLetter(Name[pos+8]))
			   correct = true;
	   }
	 if (!correct) {
	   if (Name.Length() > pos+4) {
		 if (Name[pos+4] == L' ' && IsLetter(Name[pos+5])) {
		   msg = L"Is the name «" + Name.SubString(1,pos-1) + L"» in «" + Name + L"» a genus name?";
		   if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes) {
			 NewName = Name.SubString(1,pos-1);
			 UnicodeString species = Name.SubString(pos+5,Name.Length()-pos-4);
			 NewName += (L" cf. " + NewName.SubString(1,1) + L". " + species);
			 msg = L"The Neotoma form for cf. species is «Genus cf. G. species», e.g «Acer cf. A. negundo»";
			 msg += (L"\nChange «" + Name + L"» to «" + NewName + L"»?");
			 if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes)
			   change = true;
			 }
		   }
		 }
	   }
	 }
   return change;
}
//---------------------------------------------------------------------------

TDateTime UTCDateTime(void)
{
   SYSTEMTIME st;
   GetSystemTime(&st);
   return SystemTimeToDateTime(st);
}
//---------------------------------------------------------------------------


