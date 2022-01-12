//---------------------------------------------------------------------------

#ifndef TIContacH
#define TIContacH
#include "cxGridTableView.hpp"
#ifndef TIPubH
#include "TIPub.h"
#endif
#ifndef TIJSONH
#include "TIJSON.h"
#endif

//---------------------------------------------------------------------------
class AUTHOR;
//---------------------------------------------------------------------------
class CONTACT
{
public:
  int NeotomaContactID;
  int NeotomaAliasID;
  UnicodeString FullContactName;
  UnicodeString ShortContactName;
  UnicodeString FamilyName;
  UnicodeString GivenNames;
  UnicodeString LeadingInitials;
  UnicodeString Suffix;
  UnicodeString Telephone;
  UnicodeString Fax;
  UnicodeString Email;
  UnicodeString Address;
  UnicodeString Title;
  UnicodeString Status;
  UnicodeString URL;
  UnicodeString Notes;
public:
  CONTACT() { NeotomaContactID = -1; NeotomaAliasID = -1; }
  CONTACT(CONTACT*);
  CONTACT(NTMCONTACT& contact, map<int, UnicodeString>& ContactStatuses);
  CONTACT(vector<AUTHOR>::pointer Author);
  bool operator == (const CONTACT& compare);
  UnicodeString GetLeadingInitials(void);
  void FormatContactName(void);
  void Copy(CONTACT* Source);
};
//---------------------------------------------------------------------------

typedef void __fastcall (__closure *TcxNotifyEvent)(void * Ptr, TListNotification Action);

class TContactList : public TList
{
private:
	::TcxNotifyEvent FOnNotify;
	void ReleaseAllContacts();
	void ReleaseContact(int AIndex);
	CONTACT* GetContact(int AIndex);
protected:
	void __fastcall Notify(void * Ptr, TListNotification Action);
	__property Items;
public:
	TContactList() {}
	__fastcall ~TContactList() {}
	void __fastcall Clear(void);
	void Add(CONTACT* Contact);
	void Delete(int AIndex);
	void Insert(int AIndex, CONTACT* Contact);
	__property CONTACT* Contacts[int Index] = {read = GetContact};
    __property ::TcxNotifyEvent OnNotify = {read=FOnNotify, write=FOnNotify};
	//void SortAscending(void);
    //static int __fastcall ContactCompare(void*, void*);
};

//---------------------------------------------------------------------------
class TContactDataSource : public TcxCustomDataSource
{
private:
    TContactList* FContacts;
protected:
    void * __fastcall InsertRecord(void * ARecordHandle);
    void * __fastcall AppendRecord(void);
    void __fastcall DeleteRecord(void * ARecordHandle);
    int __fastcall GetRecordCount(void);
    Variant __fastcall GetValue(void * ARecordHandle, void * AItemHandle);
    void __fastcall Notify(void * Ptr, TListNotification Action);
    void __fastcall SetValue(void * ARecordHandle, void * AItemHandle, const Variant &AValue);
public:
    __fastcall TContactDataSource(TContactList* AContactList);
    __fastcall ~TContactDataSource() { }
};

//---------------------------------------------------------------------------
const int IndexOf_co_family_name      = 0;
const int IndexOf_co_given_names      = 1;
const int IndexOf_co_leading_initials = 2;
const int IndexOf_co_suffix           = 3;
const int IndexOf_co_title            = 4;
const int IndexOf_co_status           = 5;
const int IndexOf_co_telephone        = 6;
const int IndexOf_co_fax              = 7;
const int IndexOf_co_email            = 8;
const int IndexOf_co_url              = 9;
const int IndexOf_co_address          = 10;
const int IndexOf_co_notes            = 11;
//---------------------------------------------------------------------------

#endif
