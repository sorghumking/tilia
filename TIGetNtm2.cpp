//---------------------------------------------------------------------------


#pragma hdrstop

#include "TIGetNtm2.h"
#ifndef TISpreadH
#include "TISpread.h"
#endif
#ifndef TGParentH
#include "TGParent.h"
#endif
#ifndef TIJSONH
#include "TIJSON.h"
#endif
#ifndef TINtmLOIH
#include "TINtmLOI.h"
#endif

//---------------------------------------------------------------------------

#pragma package(smart_init)

CONTACT* TTilSpreadSheetForm::GetNeotomaContact(NTMCONTACT& ntm_contact)
{
   CONTACT* Contact = NULL;

   // return Contact if it already exists in ContactList
   if (ContactList->Count > 0) {
	 for (int i=0; i<ContactList->Count; i++) {
	   if (ntm_contact.ContactID == ContactList->Contacts[i]->NeotomaContactID) {
		 return ContactList->Contacts[i];
		 }
	   }
	 }

   // get ContactStatuses table if necessary
   if (NeotomaContactStatuses.size() == 0) {
	 //NeotomaContactStatusesTable ContactStatuses(ipwJSON1, TcpClient1);
	 NeotomaContactStatusesTable ContactStatuses(ipsJSONS1, TcpClient1);
	 ParentForm->StatusBar1->Panels->Items[0]->Text = ContactStatuses.WebServiceName();
	 if (ContactStatuses.Execute()) {
	   for (unsigned int i=0; i < ContactStatuses.Size(); i++)
		 NeotomaContactStatuses[ContactStatuses.Items[i].ContactStatusID] =
		   ContactStatuses.Items[i].ContactStatus;
	   }
	 else
	   return Contact;
	 }

   Contact = new CONTACT;
   Contact->NeotomaContactID = ntm_contact.ContactID;
   Contact->NeotomaAliasID = ntm_contact.AliasID;
   int ContactStatusID = ntm_contact.ContactStatusID;
   if (NeotomaContactStatuses.count(ContactStatusID) == 1)
	 Contact->Status = NeotomaContactStatuses[ContactStatusID];
   Contact->FamilyName = ntm_contact.FamilyName;
   Contact->GivenNames = ntm_contact.GivenNames;
   Contact->LeadingInitials = ntm_contact.LeadingInitials;
   Contact->Suffix = ntm_contact.Suffix;
   Contact->Title = ntm_contact.Title;
   Contact->Email = ntm_contact.Email;
   Contact->Telephone = ntm_contact.Phone;
   Contact->Fax = ntm_contact.Fax;
   Contact->URL = ntm_contact.URL;
   Contact->Notes = ntm_contact.Notes;
   Contact->Address = ntm_contact.Address;
   Contact->FormatContactName();
   ContactList->Add(Contact);
   return Contact;
}
//---------------------------------------------------------------------------

PUBLICATION* TTilSpreadSheetForm::GetNeotomaPub(int DatasetID, TList* Publications, NTMPUBLICATION& ntm_pub)
{
   PUBLICATION* pub = NULL;

   // return publication if it already exists in Publications list
   if (Publications->Count > 0) {
	 for (int i=0; i<Publications->Count; i++) {
	   PUBLICATION* pub = (PUBLICATION*)Publications->Items[i];
	   if (ntm_pub.PublicationID == pub->NeotomaID)
		 return pub;
	   }
	 }

   pub = new PUBLICATION();
   map<int,PUBAUTHOR> AuthorMap;
   vector<PUBAUTHOR> PubAuthors;
   map<int,EDITOR> EditorMap;
   vector<EDITOR> PubEditors;
   map<int,EDITOR> TranslatorMap;
   vector<EDITOR> PubTranslators;

   // get authors
   NeotomaPublicationAuthors Authors(ipsJSONS1, TcpClient1);
   Authors.AddParam(L"PUBLICATIONID", ntm_pub.PublicationID);
   ParentForm->StatusBar1->Panels->Items[0]->Text = Authors.WebServiceName();
   if (Authors.Execute()) {
	 if (Authors.Size() > 0) {
	   for (unsigned int i=0; i<Authors.Size(); i++)
		 AuthorMap[Authors.Items[i].AuthorOrder] = PUBAUTHOR(Authors.Items[i]);
	   }
	 }
   else
	 return NULL;

   for (map<int,PUBAUTHOR>::iterator itr = AuthorMap.begin(); itr != AuthorMap.end(); itr++)
	 PubAuthors.push_back(itr->second);

   // get editors
   switch (ntm_pub.PubTypeID) {
	 case BOOK_CHAPTER:
	 case BOOKCHAPTER:
	   NeotomaPublicationEditors Editors(ipsJSONS1, TcpClient1);
	   Editors.AddParam(L"PUBLICATIONID", ntm_pub.PublicationID);
	   ParentForm->StatusBar1->Panels->Items[0]->Text = Editors.WebServiceName();
	   if (Editors.Execute()) {
		 if (Editors.Size() > 0) {
		   for (unsigned int i=0; i<Editors.Size(); i++)
			 EditorMap[Editors.Items[i].EditorOrder] = EDITOR(Editors.Items[i]);
		   }
		 }
	   else
		 return NULL;
	   for (map<int,EDITOR>::iterator itr = EditorMap.begin(); itr != EditorMap.end(); itr++)
		 PubEditors.push_back(itr->second);
	   break;
	 }

   // get translators
   switch (ntm_pub.PubTypeID) {
	 case BOOK_CHAPTER:
	 case AUTHORED_BOOK:
	 case EDITED_BOOK:
	 case BOOKCHAPTER:
	 case BOOK:
	 case EDITEDBOOK:
	   NeotomaPublicationTranslators Translators(ipsJSONS1, TcpClient1);
	   Translators.AddParam(L"PUBLICATIONID", ntm_pub.PublicationID);
	   ParentForm->StatusBar1->Panels->Items[0]->Text = Translators.WebServiceName();
	   if (Translators.Execute()) {
		 if (Translators.Size() > 0) {
		   for (unsigned int i=0; i<Translators.Size(); i++)
			 TranslatorMap[Translators.Items[i].TranslatorOrder] = EDITOR(Translators.Items[i]);
		   }
		 }
	   else
		 return NULL;
	   for (map<int,EDITOR>::iterator itr = TranslatorMap.begin(); itr != TranslatorMap.end(); itr++)
		 PubTranslators.push_back(itr->second);
	   break;
	   }

   pub->SetPublication(&ntm_pub, PubAuthors, PubEditors, PubTranslators);

   for (unsigned int i=0; i<pub->AuthorList.size(); i++) {
	 if (ContactList->Count > 0) {
	   for (int j=0; j<ContactList->Count; j++) {
		 if (pub->AuthorList[i].NeotomaContactID == ContactList->Contacts[j]->NeotomaContactID) {
		   pub->AuthorList[i].contact = ContactList->Contacts[j];
		   break;
		   }
		 }
	   }
	 if (pub->AuthorList[i].contact == NULL) {
	   NeotomaContactByID AuthorContact(ipsJSONS1, TcpClient1);
	   AuthorContact.AddParam(L"CONTACTID", pub->AuthorList[i].NeotomaContactID);
	   ParentForm->StatusBar1->Panels->Items[0]->Text = AuthorContact.WebServiceName();
	   if (AuthorContact.Execute()) {
		 if (AuthorContact.Size() > 0) {
		   CONTACT* Contact = GetNeotomaContact(AuthorContact.Items[0]);
		   if (Contact != NULL)
			 pub->AuthorList[i].contact = Contact;
		   }
		 }
	   else
		 return NULL;
	   }
	 }

   // get publication primary status
   NeotomaGetDatasetPublicationStatus PubStatus(ipsJSONS1, TcpClient1);
   PubStatus.AddParam(L"DATASETID", DatasetID);
   PubStatus.AddParam(L"PUBLICATIONID", pub->NeotomaID);
   ParentForm->StatusBar1->Panels->Items[0]->Text = PubStatus.WebServiceName();
   if (PubStatus.Execute()) {
	 if (PubStatus.Size() == 1)
	   pub->Primary = PubStatus.Items[0];
	 }
   else
	 return NULL;

   Publications->Add(pub);
   return pub;
}
//---------------------------------------------------------------------------
