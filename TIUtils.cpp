//---------------------------------------------------------------------------
#define VCL_IOSTREAM
#include <vcl.h>
#include <io.h>
#include <Dialogs.hpp>
#pragma hdrstop

#include <algorithm>
#include <DateUtils.hpp>
#include <iostream.h>
#include <fstream.h>
#include <strsafe.h>
#include "TIUtils.h"
#ifndef TIXMLH
#include "TIXML.h"
#endif

//---------------------------------------------------------------------------

#pragma package(smart_init)
//---------------------------------------------------------------------------

TAXON::TAXON(TAXON* tx)
{
   ID = tx->ID;
   HigherID = tx->HigherID;
   Code = tx->Code;
   Name = tx->Name;
   Author = tx->Author;
   TaxaGroup = tx->TaxaGroup;
   EcolGroup = tx->EcolGroup;
   Elements.assign(tx->Elements.begin(), tx->Elements.end());
}
//---------------------------------------------------------------------------

void TTaxaVector::operator = (const TTaxaVector& copy)
{
   if (this == &copy) return;
   Taxa = copy.Taxa;
   IdxName = copy.IdxName;
   IdxID = copy.IdxID;
   IdxSorted = copy.IdxSorted;
}
//---------------------------------------------------------------------------

void TTaxaVector::Index(void)
{
   for (unsigned int i=0; i<Taxa.size(); i++) {
	 IdxName.insert(pair<UnicodeString,unsigned int>(Taxa[i].Name, i));
	 IdxID[Taxa[i].ID] = i;
	 }
   IdxSorted.reserve(IdxName.size());
   multimap<UnicodeString, unsigned int>::iterator itr;
   multimap<UnicodeString, unsigned int>::iterator begin = IdxName.begin();
   multimap<UnicodeString, unsigned int>::iterator end = IdxName.end();
   for (itr = begin; itr != end; itr++)
	 IdxSorted.push_back(itr->second);
}
//---------------------------------------------------------------------------

unsigned int TTaxaVector::FindName(UnicodeString Name, vector<TAXON>& TaxaFound)
{
   TaxaFound.clear();
   multimap<UnicodeString, unsigned int>::iterator itr;
   pair<multimap<UnicodeString, unsigned int>::iterator, multimap<UnicodeString, unsigned int>::iterator> range;
   range = IdxName.equal_range(Name);
   if (range.first != IdxName.end()) {
	 for (itr=range.first; itr!=range.second; itr++) {
	   unsigned int idx = itr->second;
	   TaxaFound.push_back(Taxa[idx]);
	   }
	 }
   return TaxaFound.size();
}
//---------------------------------------------------------------------------

bool TTaxaVector::FindID(int ID, vector<TAXON>::pointer *TaxonPtr)
{
   if (IdxID.find(ID) != IdxID.end()) {
	 *TaxonPtr = &Taxa[IdxID[ID]];
	 return true;
	 }
   else {
	 *TaxonPtr = NULL;   // this used to be TaxonPtr = NULL;
	 return false;
	 }
}
//---------------------------------------------------------------------------

UnicodeString  __fastcall TranslateEntityRefs(UnicodeString& Entity)
{
   int pos;
   while ((pos = Entity.Pos(L"&amp;")) > 0)
	 Entity.Delete(pos+1,4);
   while ((pos = Entity.Pos(L"&lt;")) > 0) {
	 Entity.Delete(pos,4);
	 Entity.Insert(L"<", pos);
	 }
   while ((pos = Entity.Pos(L"&gt;")) > 0) {
	 Entity.Delete(pos,4);
	 Entity.Insert(L">", pos);
	 }
   while ((pos = Entity.Pos(L"&quot;")) > 0) {
	 Entity.Delete(pos,6);
	 Entity.Insert(L"\"", pos);
	 }
   while ((pos = Entity.Pos(L"&apos;")) > 0) {
	 Entity.Delete(pos,6);
	 Entity.Insert(L"'", pos);
	 }
  return Entity;
}
//---------------------------------------------------------------------------

int VariantToInt(const Variant& var, int default_val)
{
   int ival;
   try {
	   if (var.IsNull() || var.IsEmpty())
		 ival = default_val;
	   else
		 ival = var;
	   }
   catch (...)
	   {
	   ival = default_val;
	   }
   return ival;
}
//---------------------------------------------------------------------------

bool VariantToBool(Variant& var, bool default_val)
{
   bool bval;
   try {
	   if (var.IsNull() || var.IsEmpty())
		 bval = default_val;
	   else
		 bval = var;
	   }
   catch (...)
	   {
	   bval = default_val;
	   }
   return bval;
}
//---------------------------------------------------------------------------

double VariantToDouble(Variant& var, double default_val)
{
   double val;
   try {
	   if (var.IsNull() || var.IsEmpty())
		 val = default_val;
	   else
		 val = var;
	   }
   catch (...)
	   {
	   val = default_val;
	   }
   return val;
}
//---------------------------------------------------------------------------

bool TryVariantToDouble(Variant& var, double& value)
{
   bool rv = true;
   try {
	   if (var.Type() == varDouble || var.Type() == varInteger)
		 value = (double)var;
	   else {
		 UnicodeString text = VarToStr(var);
		 double dVal;
		 if (TryStrToFloat(text,dVal))
		   value = dVal;
		 else
		   rv = false;
		 }
	   }
   catch (...)
	   {
	   rv = false;
	   }
   return rv;
}
//---------------------------------------------------------------------------

UnicodeString PARSEXMLSAX::GetElement(UnicodeString& Value)
{
   return TranslateEntityRefs(Value);
}
//---------------------------------------------------------------------------

void __fastcall PARSEXMLSAX::SetElement(UnicodeString& Value, int ElemNo)
{
   CurrentElementValue += TranslateEntityRefs(Value);
   CurrentElement = ElemNo;
}
//---------------------------------------------------------------------------

void __fastcall PARSEXMLSAX::SetElement(UnicodeString& Value, int GroupNo, int ElemNo)
{
   CurrentElementValue += TranslateEntityRefs(Value);
   CurrentGroup = GroupNo;
   CurrentElement = ElemNo;
}
//---------------------------------------------------------------------------

PARSETAXA::PARSETAXA(TipwXMLp* ipwXMLp, TForm* Owner)
{
   OwnerForm = Owner;
   ipwXMLp6 = ipwXMLp;
}
//---------------------------------------------------------------------------

bool PARSETAXA::Parse(UnicodeString fname)
{
   FileName = fname;
   TrainForm = new TTrainForm(OwnerForm);
   bool rv = ParseTaxaList();
   delete TrainForm;
   return rv;
}
//---------------------------------------------------------------------------

bool PARSETAXA::Parse(UnicodeString fname, TTrainForm* trform)
{
   FileName = fname;
   TrainForm = trform;
   bool rv = ParseTaxaList();
   TrainForm->Hide();
   return rv;
}
//---------------------------------------------------------------------------

bool PARSETAXA::ParseTaxaList(void)
{
   TrainForm->Caption = "Parsing Taxa File";
   TrainForm->SetFreeChug();
   TrainForm->Show();
   TrainForm->Repaint();

   bool success = true;
   try {
	   ipwXMLp6->ParseFile(FileName);
	   TaxaList.Index();
	   }
   catch(...) {
       MessageDlg("Cannot parse " + FileName, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
       success = false;
       }
   return success;
}
//---------------------------------------------------------------------------

//CompareText compares S1 and S2 and returns 0 if they are equal.
//If S1 is greater than S2, CompareText returns an integer greater than 0.
//If S1 is less than S2, CompareText returns an integer less than 0.

bool __fastcall PARSETAXA::CompareName1(TAXON Taxon1, TAXON Taxon2)
{
   return (CompareText(Taxon1.Name, Taxon2.Name) < 0);
}

/*
Binary function that accepts two arguments (the first of the type pointed by ForwardIterator,
and the second, always val), and returns a value convertible to bool. The value returned
indicates whether the first argument is considered to go before the second.
The function shall not modify any of its arguments.
This can either be a function pointer or a function object.
*/

bool __fastcall PARSETAXA::CompareName2(TAXON& Taxon, UnicodeString Name)
{
   return (CompareText(Taxon.Name, Name) < 0);
}

bool PARSETAXA::FindName(UnicodeString Name, vector<TAXON>& TaxaFound)
{
   // TODO: this accommodates only single unique taxa names; however, the
   //       the TaxaList.FindName function will return multiple names.
   //vector<TAXON> TaxaFound;
   TaxaList.FindName(Name, TaxaFound);
   return (TaxaFound.size() > 0);
}
//---------------------------------------------------------------------------

SAVETAXALOOKUP::SAVETAXALOOKUP(UnicodeString tf, UnicodeString tt, vector<TAXAECOLGROUPS>* teg,
   TTaxaVector* tl, TComponent* ow)
{
   TaxaFile = tf;
   TaxaTitle = tt;
   TaxaEcolGroupsPtr = teg;
   TaxaList = tl;
   Owner = ow;

   SaveDialog1 = new TSaveDialog(Owner);
   SaveDialog1->DefaultExt = "xml";
   SaveDialog1->Filter = "XML Lookup File (*.xml)|*.xml";
   SaveDialog1->FilterIndex = 1;
   SaveDialog1->Options << ofOverwritePrompt << ofHideReadOnly << ofEnableSizing;
   SaveDialog1->InitialDir = ExtractFilePath(TaxaFile);
   SaveDialog1->FileName = TaxaFile;
}
//---------------------------------------------------------------------------

SAVETAXALOOKUP::~SAVETAXALOOKUP()
{
   delete SaveDialog1;
}
//---------------------------------------------------------------------------

void SAVETAXALOOKUP::Save(void)
{
   UnicodeString FileName;

   if (SaveDialog1->Execute()) {
	 FileName = SaveDialog1->FileName;
	 UnicodeString FileExt = ExtractFileExt(FileName);
	 if (FileExt.CompareIC(".xml") != 0) {
	   MessageDlg("Taxa file must be *.xml", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return;
	   }

	 WriteXML* xmlout = new WriteXML(FileName);

	 try
	   {
	   try
		 {
		 xmlout->Declaration("1.0", "UTF-8", "yes");
		 xmlout->DateTime();
		 xmlout->BeginTag("TiliaTaxa", "version", "2.0");
		 if (TaxaTitle.IsEmpty())
		   xmlout->EmptyElement("Title");
		 else
		   xmlout->Element("Title", TaxaTitle);

		 if (TaxaEcolGroupsPtr->size() > 0) {
		   xmlout->BeginTag("EcologicalGroups");
		   for (unsigned int i=0; i<TaxaEcolGroupsPtr->size(); i++) {
			 xmlout->BeginTag("TaxaGroup", "Code", InsertEntityRefs(TaxaEcolGroupsPtr->at(i).TaxaGroup.Code),
							  "Name", InsertEntityRefs(TaxaEcolGroupsPtr->at(i).TaxaGroup.Name));
			 for (unsigned int j=0; j<TaxaEcolGroupsPtr->at(i).EcolGroups.size(); j++) {
			   xmlout->BeginTag("EcologicalGroup");
			   xmlout->Element("Code", TaxaEcolGroupsPtr->at(i).EcolGroups[j].Code);
			   xmlout->Element("Title", TaxaEcolGroupsPtr->at(i).EcolGroups[j].Name);
			   xmlout->EndTag("EcologicalGroup");
			   }
			 xmlout->EndTag("TaxaGroup");
			 }
		   xmlout->EndTag("EcologicalGroups");
		   }
		 else
		   xmlout->EmptyElement("EcologicalGroups");

		 xmlout->BeginTag("Taxa");

		 map<int, vector<TAXON>::pointer> Taxa;
		 for (unsigned int i=0; i<TaxaList->size(); i++)
		   Taxa[TaxaList->at(i).ID] = &TaxaList->at(i);

		 map<int, vector<TAXON>::pointer>::iterator start = Taxa.begin();
		 map<int, vector<TAXON>::pointer>::iterator stop = Taxa.end();
		 map<int, vector<TAXON>::pointer>::iterator itr;

		 for (itr=start; itr != stop; itr++) {
		   TAXON* Taxon = itr->second;
		   xmlout->BeginTag("Taxon", "ID", Taxon->ID);
		   xmlout->Element("Name", Taxon->Name);
		   xmlout->Element("Author", Taxon->Author);
		   xmlout->Element("Code", Taxon->Code);
		   xmlout->Element("TaxaGroup", Taxon->TaxaGroup);
		   xmlout->Element("EcolGroup", Taxon->EcolGroup);
		   xmlout->Element("HigherID", Taxon->HigherID);
		   for (unsigned int j=0; j<Taxon->Elements.size(); j++) {
			 UnicodeString Element = Taxon->Elements[j].Name;
			 int nunits = Taxon->Elements[j].Units.size();
			 if (nunits > 0) {
			   xmlout->BeginTag("Element", "Type", Element);
			   for (int k=0; k<nunits; k++) {
				 UnicodeString Units = Taxon->Elements[j].Units[k];
				 xmlout->Element("Units", Units);
				 }
			   xmlout->EndTag("Element");
			   }
			 else
			   xmlout->EmptyElement("Element", "Type", Element);
			 }
		   xmlout->EndTag("Taxon");
		   }
		 xmlout->EndTag("Taxa");
		 xmlout->EndTag("TiliaTaxa");
		 xmlout->Finish();
		 }
	   catch(Exception &e) {
		 MessageDlg(e.Message, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 }
	   }
	 __finally
	   {
	   delete xmlout;
	   }
     }
}
//---------------------------------------------------------------------------

bool GetAuthorContact(vector<AUTHOR>::pointer Author, TContactList* ContactList)
{
   UnicodeString msg;
   CONTACT* Contact;
   bool query;
   bool author_found = false;

   if (ContactList == NULL) return false;

   for (int k=0; k<ContactList->Count; k++) {
	 Contact = ContactList->Contacts[k];
	 if (SameText(Author->LastName, Contact->FamilyName)) {
	   query = false;
	   if (SameText(Author->Initials, Contact->LeadingInitials) && SameText(Author->Suffix, Contact->Suffix))
		 author_found = true;
	   else if (SameText(Author->Initials, Contact->LeadingInitials))
		 query = true;
	   else if (!Contact->GivenNames.IsEmpty()) {
		 if (SameText(Author->Initials, Contact->GetLeadingInitials()))
		   query = true;
		 }

	   if (!author_found && !query) {
		 if (Contact->LeadingInitials.Length() > Author->Initials.Length()) {
		   if (Author->Initials.Length() == 1 || (Author->Initials.Length() == 2 && Author->Initials[2] == L'.')){
			 if (Author->Initials[1] == Contact->LeadingInitials[1])
			   query = true;
			 }
		   }
		 }

	   if (query) {
		 msg = "Is author <" + Author->Initials + " " + Author->LastName;
		 if (Author->Suffix.Length() > 0)
		   msg += (" " + Author->Suffix);
		 msg += "> the same person as contact <";
		 if (Contact->GivenNames.Length() > 0)
		   msg += (Contact->GivenNames + " ");
		 else if (Contact->LeadingInitials.Length() > 0)
		   msg += (Contact->LeadingInitials + " ");
		 msg += Contact->FamilyName;
		 if (Contact->Suffix.Length() > 0)
		   msg += (" " + Contact->Suffix);
		 msg += ">?";
		 if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes)
		   author_found = true;
		 }
	   }

	 if (author_found) {
	   Author->contact = Contact;
	   Contact->NeotomaContactID = Author->NeotomaContactID;
	   return true;
	   }
	 }
   return false;
}
//---------------------------------------------------------------------------

UnicodeString StripTextQuotes(UnicodeString Text)
{
  if (Text[1] == L'\"') {
	Text.Delete(1,1);
	if (*Text.LastChar() == L'\"')
	  Text.SetLength(Text.Length()-1);
	}
  return Text;
}
//---------------------------------------------------------------------------

UnicodeString DateStr(Variant vDate)
{
   UnicodeString date_str;
   if (vDate.Type() == varDate) {
	 TDateTime Date = vDate;
	 date_str = Date.FormatString(L"yyyy-mm-dd");
	 }
   return date_str;
}
//---------------------------------------------------------------------------

UnicodeString DateStr(TDateTime Date)
{
   return(Date.FormatString(L"yyyy-mm-dd"));
}
//---------------------------------------------------------------------------

UnicodeString DateTimeStr(TDateTime Date)
{
   return(Date.FormatString(L"yyyy-mm-dd hh:nn:ss"));
}
//---------------------------------------------------------------------------

Variant GeochronParam(map<UnicodeString,double>& Params, UnicodeString ParamName)
{
   map<UnicodeString,double>::iterator itr = Params.find(ParamName);
   Variant Value;
   if (itr == Params.end())
	 Value = Unassigned();
   else
	 Value = itr->second;

   return Value;
}
//---------------------------------------------------------------------------

