//---------------------------------------------------------------------------
#include <vcl.h>
#include "pch.h"
#pragma hdrstop
#include "TIContac.h"
#ifndef TIUtilsH
#include "TIUtils.h"
#endif
//---------------------------------------------------------------------------

#pragma package(smart_init)

//---------------------------------------------------------------------------
CONTACT::CONTACT(NTMCONTACT& contact, map<int, UnicodeString>& ContactStatuses)
{
   NeotomaContactID = contact.ContactID;
   NeotomaAliasID = contact.AliasID;
   FullContactName = contact.ContactName;
   FamilyName = contact.FamilyName;
   GivenNames = contact.GivenNames;
   LeadingInitials = contact.LeadingInitials;
   Suffix = contact.Suffix;
   Telephone = contact.Phone;
   Fax = contact.Fax;
   Email = contact.Email;
   Address = contact.Address;
   Title = contact.Title;
   int StatusID = contact.ContactStatusID;
   if (StatusID > -1) {
	 if (ContactStatuses.find(StatusID) != ContactStatuses.end())
	   Status = ContactStatuses[StatusID];
	 }
   URL = contact.URL;
   Notes = contact.Notes;
   FormatContactName();
}
//---------------------------------------------------------------------------

CONTACT::CONTACT(CONTACT* Source)
{
   NeotomaContactID = Source->NeotomaContactID;
   NeotomaAliasID = Source->NeotomaAliasID;
   FullContactName = Source->FullContactName;
   ShortContactName = Source->ShortContactName;
   FamilyName = Source->FamilyName;
   GivenNames = Source->GivenNames;
   LeadingInitials = Source->LeadingInitials;
   Suffix = Source->Suffix;
   Telephone = Source->Telephone;
   Fax = Source->Fax;
   Email = Source->Email;
   Address = Source->Address;
   Title = Source->Title;
   Status = Source->Status;
   URL = Source->URL;
   Notes = Source->Notes;
}
//---------------------------------------------------------------------------

CONTACT::CONTACT(vector<AUTHOR>::pointer Author)
{
   NeotomaContactID = Author->NeotomaContactID;
   FamilyName = Author->LastName;
   LeadingInitials = Author->Initials;
   Suffix = Author->Suffix;
   FormatContactName();
}
//---------------------------------------------------------------------------

bool CONTACT::operator == (const CONTACT& compare )
{
   // return false if any of the variables are not equal
   if (this == &compare) return true;

   //if (FullContactName != compare.FullContactName) return false;
   //if (ShortContactName != compare.ShortContactName) return false;
   if (FamilyName != compare.FamilyName) return false;
   if (GivenNames != compare.GivenNames) return false;
   if (LeadingInitials != compare.LeadingInitials) return false;
   if (Suffix != compare.Suffix) return false;
   if (Telephone != compare.Telephone) return false;
   if (Fax != compare.Fax) return false;
   if (Email != compare.Email) return false;
   if (Address != compare.Address) return false;
   if (Title != compare.Title) return false;
   if (Status != compare.Status) return false;
   if (URL != compare.URL) return false;
   if (Notes != compare.Notes) return false;

   return true;
}
//---------------------------------------------------------------------------

void CONTACT::Copy(CONTACT* Source)
{
   NeotomaContactID = Source->NeotomaContactID;
   NeotomaAliasID = Source->NeotomaAliasID;
   FullContactName = Source->FullContactName;
   ShortContactName = Source->ShortContactName;
   FamilyName = Source->FamilyName;
   GivenNames = Source->GivenNames;
   LeadingInitials = Source->LeadingInitials;
   Suffix = Source->Suffix;
   Telephone = Source->Telephone;
   Fax = Source->Fax;
   Email = Source->Email;
   Address = Source->Address;
   Title = Source->Title;
   Status = Source->Status;
   URL = Source->URL;
   Notes = Source->Notes;
}
//---------------------------------------------------------------------------

UnicodeString CONTACT::GetLeadingInitials(void)
{
   int pos, spacepos, hyphenpos;
   UnicodeString Initials;
   UnicodeString GivenNames = GivenNames.Trim();
   if (GivenNames.Length() > 0) {
     Initials = GivenNames.SubString(1,1);
     Initials += ".";
     do {
		spacepos = GivenNames.Pos(" ");
        hyphenpos = GivenNames.Pos("-");
        if (spacepos & hyphenpos) {
          if (spacepos < hyphenpos) {
            pos = spacepos;
            hyphenpos = 0;
            }
          else
            pos = hyphenpos;
          }
        else if (spacepos)
          pos = spacepos;
        else if (hyphenpos)
          pos = hyphenpos;
        else
          pos = 0;
        if (pos) {
          if (GivenNames.Length()-pos) {
            GivenNames = GivenNames.SubString(pos+1, GivenNames.Length()-pos);
            GivenNames = GivenNames.TrimLeft();
            if (hyphenpos) Initials += "-";
            Initials += GivenNames.SubString(1,1);
            Initials += ".";
            }
          else
            pos = 0;
          }
        } while (pos);
     }
   return Initials;
}
//---------------------------------------------------------------------------

void CONTACT::FormatContactName(void)
{
   FullContactName = FamilyName;
   ShortContactName = FamilyName;

   // remove spaces from LeadingInitials
   int pos;
   while ((pos = LeadingInitials.Pos(" ")) > 0)
     LeadingInitials.Delete(pos,1);

   if (!GivenNames.Length() && LeadingInitials.Length())
     GivenNames = LeadingInitials;
   if (GivenNames.Length())
     FullContactName += (", " + GivenNames);
   else if (LeadingInitials.Length())
     FullContactName += (", " + LeadingInitials);
   if (LeadingInitials.Length())
     ShortContactName += (", " + LeadingInitials);
   if (Suffix.Length()) {
     FullContactName += (", " + Suffix);
     ShortContactName += (", " + Suffix);
     }
}
//---------------------------------------------------------------------------

void TContactList::ReleaseAllContacts()
{
  for (int i = 0; i < Count; i++)
    ReleaseContact(i);
}
//---------------------------------------------------------------------------

void TContactList::ReleaseContact(int AIndex)
{
  delete (CONTACT*)Items[AIndex];
}
//---------------------------------------------------------------------------

CONTACT* TContactList::GetContact(int AIndex)
{
  return (CONTACT*)Items[AIndex];
}
//---------------------------------------------------------------------------

void __fastcall TContactList::Notify(void * Ptr, TListNotification Action)
{
  if (FOnNotify != NULL)
    FOnNotify(Ptr, Action);
}
//---------------------------------------------------------------------------

void __fastcall TContactList::Clear(void)
{
  ReleaseAllContacts();
}
//---------------------------------------------------------------------------

void TContactList::Add(CONTACT* Contact)
{
  TList::Add(Contact);
}
//---------------------------------------------------------------------------

void TContactList::Delete(int AIndex)
{
  ReleaseContact(AIndex);
  TList::Delete(AIndex);
}
//---------------------------------------------------------------------------

void TContactList::Insert(int AIndex, CONTACT* Contact)
{
  TList::Insert(AIndex, Contact);
}
//---------------------------------------------------------------------------

/*
void TContactList::SortAscending(void)
{
   Sort(ContactCompare);
}
//---------------------------------------------------------------------------


int __fastcall TContactList::ContactCompare(void * Item1, void * Item2)
{
   CONTACT* contact1 = (CONTACT*)Item1;
   CONTACT* contact2 = (CONTACT*)Item2;

   UnicodeString str1, str2;
   if (!contact1->FullContactName.IsEmpty() && !contact2->FullContactName.IsEmpty()) {
	 str1 = contact1->FullContactName;
	 str2 = contact2->FullContactName;
	 }
   else {
	 str1 = contact1->ShortContactName;
	 str2 = contact2->ShortContactName;
	 }

   return CompareText(str1, str2);
}
//---------------------------------------------------------------------------
*/

__fastcall TContactDataSource::TContactDataSource(TContactList* AContactList)
{
  FContacts = AContactList;
  FContacts->OnNotify = Notify;
}
//---------------------------------------------------------------------------

void __fastcall TContactDataSource::DeleteRecord(void * ARecordHandle)
{
  FContacts->Delete((int)ARecordHandle);
}
//---------------------------------------------------------------------------

int __fastcall TContactDataSource::GetRecordCount(void)
{
  return(FContacts->Count);
}
//---------------------------------------------------------------------------

Variant __fastcall TContactDataSource::GetValue(void * ARecordHandle, void * AItemHandle)
{
  // displays value in grid based on stored data
  int AColumnId = GetDefaultItemID((int)AItemHandle);
  CONTACT* Contact = FContacts->Contacts[(int)ARecordHandle];
  Variant Result;
  switch (AColumnId) {
    case IndexOf_co_family_name:
      Result = Contact->FamilyName;
      break;
    case IndexOf_co_given_names:
      Result = Contact->GivenNames;
      break;
    case IndexOf_co_leading_initials:
      Result = Contact->LeadingInitials;
      break;
    case IndexOf_co_suffix:
      Result = Contact->Suffix;
      break;
    case IndexOf_co_title:
      Result = Contact->Title;
      break;
    case IndexOf_co_status:
      Result = Contact->Status;
      break;
    case IndexOf_co_telephone:
      Result = Contact->Telephone;
      break;
    case IndexOf_co_fax:
      Result = Contact->Fax;
      break;
    case IndexOf_co_email:
      Result = Contact->Email;
      break;
    case IndexOf_co_url:
      Result = Contact->URL;
      break;
    case IndexOf_co_address:
      Result = Contact->Address;
      break;
    case IndexOf_co_notes:
      Result = Contact->Notes;
      break;
  }
  return (Result);
}
//---------------------------------------------------------------------------

void __fastcall TContactDataSource::Notify(void * Ptr, TListNotification Action)
{
  DataChanged();
}
//---------------------------------------------------------------------------

void * __fastcall TContactDataSource::InsertRecord(void * ARecordHandle)
{
  CONTACT* Contact = new CONTACT;
  FContacts->Insert((int)ARecordHandle, Contact);
  TcxDataRecordHandle* Result = (TcxDataRecordHandle*)ARecordHandle;
  return (Result);
}
//---------------------------------------------------------------------------

void * __fastcall TContactDataSource::AppendRecord(void)
{
  TcxDataRecordHandle* Result = (TcxDataRecordHandle*)FContacts->Count;
  CONTACT* Contact = new CONTACT;
  FContacts->Add(Contact);
  return (Result);
}
//---------------------------------------------------------------------------

void __fastcall TContactDataSource::SetValue(void * ARecordHandle, void * AItemHandle, const Variant &AValue)
{
  // gets values from grid and stores them
  int AColumnId = GetDefaultItemID((int)AItemHandle);
  CONTACT* Contact = FContacts->Contacts[(int)ARecordHandle];
  switch (AColumnId) {
    case IndexOf_co_family_name:
	  Contact->FamilyName = VarToStr(AValue);
	  Contact->FormatContactName();
      break;
    case IndexOf_co_given_names:
	  Contact->GivenNames = VarToStr(AValue);
	  Contact->FormatContactName();
      break;
	case IndexOf_co_leading_initials:
	  Contact->LeadingInitials = VarToStr(AValue);
	  Contact->FormatContactName();
	  break;
    case IndexOf_co_suffix:
	  Contact->Suffix = VarToStr(AValue);
	  Contact->FormatContactName();
      break;
    case IndexOf_co_title:
	  Contact->Title = VarToStr(AValue);
      break;
    case IndexOf_co_status:
	  Contact->Status = VarToStr(AValue);
      break;
    case IndexOf_co_telephone:
	  Contact->Telephone = VarToStr(AValue);
	  break;
    case IndexOf_co_fax:
	  Contact->Fax = VarToStr(AValue);
      break;
    case IndexOf_co_email:
	  Contact->Email = VarToStr(AValue);
	  break;
    case IndexOf_co_url:
	  Contact->URL = VarToStr(AValue);
      break;
    case IndexOf_co_address:
	  Contact->Address = VarToStr(AValue);
	  break;
	case IndexOf_co_notes:
	  Contact->Notes = VarToStr(AValue);
      break;
  }
}
//---------------------------------------------------------------------------

