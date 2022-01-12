//---------------------------------------------------------------------------

#include <vcl.h>
#include "pch.h"
#pragma hdrstop

#include <SysUtils.hpp>
#include "TItlxin.h"
#ifndef TGParentH
#include "TGParent.h"
#endif
#ifndef TIGlobalsH
#include "TIGlobals.h"
#endif
#ifndef TISpreadH
#include "TISpread.h"
#endif
#ifndef TIPubH
#include "TIPub.h"
#endif
#ifndef TICommonH
#include "TICommon.h"
#endif
#include <list>

//---------------------------------------------------------------------------

#pragma package(smart_init)

void TTilSpreadSheetForm::XMLParsingStatus(UnicodeString Status)
{
   ParentForm->StatusBar1->Panels->Items[0]->Text = Status;
   ParentForm->StatusBar1->Repaint();
}
//---------------------------------------------------------------------------

bool TTilSpreadSheetForm::ParseTLXFile(UnicodeString& FileName)
{
   bool rv = true;
   xmlin = new ParseXMLUnicode(ipwXMLp2);
   try {
	 try {
		 if (xmlin->RootElement() != "TiliaFile") 
		   throw(Exception(FileName + " is not a valid .tlx file."));  
		 if (!ParseTLXSSOptions()) 
		   throw(Exception("Error parsing " + FileName));    
		 if (!ParseTLXContacts())
		   throw(Exception("Error parsing " + FileName)); 
		 if (!ParseTLXPublications())
		   throw(Exception("Error parsing " + FileName));
		 if (!ParseTLXSpecimens())
		   throw(Exception("Error parsing " + FileName));
		 if (!ParseTLXSite())
		   throw(Exception("Error parsing " + FileName));
		 //if (xml_Version < VERSION(2,0,4)) {
		   if (!ParseTLXCollectionUnit())
			 throw(Exception("Error parsing " + FileName));
		 //  }
		 if (!ParseTLXDataset())
		   throw(Exception("Error parsing " + FileName));
		 if (!ParseTLXGeochronology())
		   throw(Exception("Error parsing " + FileName));
		 if (!ParseTLXAgeModels())
		   throw(Exception("Error parsing " + FileName));
		 if (!ParseTLXLithology())
		   throw(Exception("Error parsing " + FileName));
		 if (!ParseTLXLOI())
		   throw(Exception("Error parsing " + FileName));
		 if (xml_Version >= VERSION(2,0,42)) {
		   if (!ParseTLXIsotopes())
			 throw(Exception("Error parsing " + FileName));
		   }

		 BuildTaphonomy();
		 ProcessSSPubs();

         // ShowMessage(L"UserSpecID = " + GeochronList->Dates[0].TaxaDated[0].UserSpecID);

		 }
	 catch (Exception &e) {
		 MessageDlg(e.Message, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 rv = false;
		 }
	   }
   __finally
	   {
	   XMLParsingStatus(EmptyStr);
	   delete xmlin;
	   }
   return rv;
}
//---------------------------------------------------------------------------

// check that all datasets in spreadsheet are specified as datasets
void TTilSpreadSheetForm::CheckTLXDatasets(void)
{
   int RowCount = AbsContentRowCount(ProfGrid1);
   int HeaderRows = AbsHeaderRowCount(ProfGrid1);
   for (int row=HeaderRows; row<=RowCount; row++) {
	 UnicodeString VarCode = ProfGrid1->AbsoluteCells[1][row]->Text;
	 if (SameText(VarCode, L"#Data.Type")) {
	   UnicodeString DatasetType = ProfGrid1->AbsoluteCells[2][row]->Text;
	   if (!DatasetType.IsEmpty()) {
		 bool found = false;
		 for (unsigned int i=0; i<Datasets.size(); i++) {
		   if (SameText(DatasetType, Datasets[i].DatasetType)) {
			 found = true;
			 break;
			 }
		   }
		 if (!found) {
		   DATASET dataset;
		   dataset.DatasetType = DatasetType;
		   Datasets.push_back(dataset);
		   }
		 }
	   }
	 }
}
//---------------------------------------------------------------------------

bool TTilSpreadSheetForm::ParseTLXSSOptions(void)
{
   UTF8String XPath;
   bool bVal;
   int iVal;
   int count;
   UnicodeString utext;

   try
   {
   if (xml_Version == VERSION(1,1,2))
	 XPath = "/TiliaFile/SpreadSheetBook/SpreadSheet/";
   else if (xml_Version > VERSION(1,1,2))
	 XPath = "/TiliaFile/SpreadSheetBook/";
   else
	 return true;

   if (xmlin->ValidChild(XPath, "SpreadSheetOptions")) {
	 XPath += "SpreadSheetOptions/";
	 XMLParsingStatus("Parsing spreadsheet options");

	 if (xml_Version >= VERSION(1,8,17)) {
	   if (xmlin->GetIntValue(XPath, "HeaderRow", iVal))
		 HeaderRow2 = iVal;
	   }
	 if (xmlin->GetTextValue(XPath, "FontName", utext))
	   tiGlobals->SSFontName = utext;
	 if (xmlin->GetIntValue(XPath, "FontSize", iVal))
	   tiGlobals->SSFontSize = iVal;
	 if (xmlin->GetIntValue(XPath, "DefaultColWidth", iVal))
	   tiGlobals->SSDefaultColWidth = iVal;
	 if (xmlin->GetIntValue(XPath, "DefaultRowHeight", iVal))
	   tiGlobals->SSDefaultRowHeight = iVal;
	 if (xmlin->GetIntValue(XPath, "PercentDecimalPlaces", iVal))
	   tiGlobals->PercentDecimalPlaces = iVal;
	 if (xml_Version >= VERSION(1,6,13)) {
	   if (xmlin->GetBoolValue(XPath, "CheckDupCodes", bVal))
		 tiGlobals->CodeOptionDups = bVal;
	   if (xmlin->GetBoolValue(XPath, "CaseSensitiveCodes", bVal))
		 tiGlobals->CodeOptionCase = bVal;
	   }
	 if (xmlin->GetBoolValue(XPath, "CodesVisible", bVal))
	   tiGlobals->SSHideCodes = bVal;
	 if (xmlin->GetBoolValue(XPath, "ElementsVisible", bVal))
	   tiGlobals->SSHideElements = bVal;
	 if (xmlin->GetBoolValue(XPath, "UnitsVisible", bVal))
	   tiGlobals->SSHideUnits = bVal;
	 if (xmlin->GetBoolValue(XPath, "ContextsVisible", bVal))
	   tiGlobals->SSHideContext = bVal;
	 if (xml_Version < VERSION(1,4,9)) {
	   if (xmlin->GetBoolValue(XPath, "ModifsVisible", bVal))
		 tiGlobals->SSHideTaphonomy = bVal;
	   }
	 else if (xmlin->GetBoolValue(XPath, "TaphonomyVisible", bVal))
	   tiGlobals->SSHideTaphonomy = bVal;
	 if (xmlin->GetBoolValue(XPath, "GroupsVisible", bVal))
	   tiGlobals->SSHideGroups = bVal;
	 set<UnicodeString> TaxaGroups;
	 if (xmlin->ValidChild(XPath, "GroupCategories", count)) {
	   for (int i=0; i<count; i++) {
		 if (xmlin->GetChildText(i, utext))
		   TaxaGroups.insert(utext.LowerCase());
		 }
	   tiGlobals->TaxaGroups = TaxaGroups;
	   }
	 }
   }
   catch(Exception &e)
   {
	 MessageDlg("Error reading spreadsheet options. Class " + e.ClassName() + ". " + e.Message,
				mtWarning, TMsgDlgButtons() << mbOK, 0);
	 return false;
   }
   return true;
}
//---------------------------------------------------------------------------

bool TTilSpreadSheetForm::ParseTLXContacts(void)
{
   UTF8String XPath;
   int count, alines;
   UnicodeString utext;

   try {
	   XPath = "/TiliaFile/";
	   if (xmlin->ValidChild(XPath, "Contacts", count)) {
		 if (count == 0) return true;
		 XMLParsingStatus("Parsing Contacts");
		 XMLSubElement Contact("/TiliaFile/Contacts/Contact");
		 for (int i=1; i<=count; i++) {
		   xml_contact = new CONTACT;
		   XPath = Contact.XPath(i);
		   if (xml_Version >= VERSION(2,0,5)) {
			 int ID;
			 if (xmlin->GetIntValue(XPath, "NeotomaContactID", ID))
			   xml_contact->NeotomaContactID = ID;
			 if (xmlin->GetIntValue(XPath, "NeotomaAliasID", ID))
			   xml_contact->NeotomaAliasID = ID;
			 }
		   xmlin->GetTextValue(XPath, "FullContactName", xml_contact->FullContactName);
		   xmlin->GetTextValue(XPath, "ShortContactName", xml_contact->ShortContactName);
		   xmlin->GetTextValue(XPath, "FamilyName", xml_contact->FamilyName);
		   xmlin->GetTextValue(XPath, "GivenNames", xml_contact->GivenNames);
		   xmlin->GetTextValue(XPath, "LeadingInitials", xml_contact->LeadingInitials);
		   xmlin->GetTextValue(XPath, "Suffix", xml_contact->Suffix);
		   xmlin->GetTextValue(XPath, "Title", xml_contact->Title);
		   xmlin->GetTextValue(XPath, "Status", xml_contact->Status);
		   xmlin->GetTextValue(XPath, "Telephone", xml_contact->Telephone);
		   xmlin->GetTextValue(XPath, "Fax", xml_contact->Fax);
		   UnicodeString Country;
		   xmlin->GetTextValue(XPath, "Country", Country);
		   xmlin->GetTextValue(XPath, "Email", xml_contact->Email);
		   xmlin->GetTextValue(XPath, "URL", xml_contact->URL);
		   xmlin->GetTextValue(XPath, "Notes", xml_contact->Notes);
		   if (xmlin->ValidChild(XPath, "Address", alines)) {
			 for (int k=0; k<alines; k++) {
			   if (xmlin->GetChildText(k, utext)) {
				 if (!xml_contact->Address.IsEmpty())
				   xml_contact->Address += L"\r\n";
				 xml_contact->Address += utext;
				 }
			   }
			 }
		   if (xml_contact->Address.IsEmpty())
			 xml_contact->Address = Country;
		   else
			 xml_contact->Address += (L"\r\n" + Country);

		   ContactList->Add(xml_contact);
		   }
		 }
	   }
   catch(Exception &e)
	   {
	   MessageDlg("Error Contact data. Class " + e.ClassName() + ". " + e.Message,
				  mtWarning, TMsgDlgButtons() << mbOK, 0);
	   return false;
	   }

   // this is done because contacts are not yet read when spreadsheet data are parsed
   // Contacts can be collectors or analysts
   if (SSContacts.size() > 0 && ContactList->Count > 0) {  // add collector pointers
	 for (unsigned int i=0; i<SSContacts.size(); i++) {
	   TProfGridCell *ACell = ProfGrid1->Cells[SSContacts[i].col][SSContacts[i].row];
	   CELLOBJECT* CellObject;
	   if (ACell->CellObject != NULL)
		 CellObject = (CELLOBJECT*)ACell->CellObject;
	   else {
		 CellObject = new CELLOBJECT(CELLCONTACTS);
		 AddCellObject(ACell, CellObject);
		 }
	   TList* Contacts = (TList*)CellObject->Object;
	   CONTACT* Contact = ContactList->Contacts[SSContacts[i].id];
	   Contacts->Add(Contact);
	   }
	 SSContacts.clear();
	 }

   // check for analysts entered by name but with no contact pointer
   int row = FindRowCodeIC("#SAMP.ANALYST", ProfGrid1);
   if (row == 0) {
	 row = FindRowCodeIC("#ANALYST", ProfGrid1); // old format
	 if (row > 0)
	   ProfGrid1->AbsoluteCells[1][row]->Value = WideString(L"#Samp.Analyst");
	 }
   if (row > 0) {
	 int StartCol = AbsHeaderColCount(ProfGrid1);
	 int EndCol = AbsContentColCount(ProfGrid1);
	 for (int col=StartCol; col<=EndCol; col++) {
	   TProfGridCell* ACell = ProfGrid1->AbsoluteCells[col][row];
	   if (!ACell->IsEmpty() && ACell->CellObject == NULL) {
		 UnicodeString Analyst = VarToStr(ACell->Value);
		 for (int j=0; j<ContactList->Count; j++) {
		   CONTACT *Contact = ContactList->Contacts[j];
		   UnicodeString ShortName = Contact->FamilyName;
		   if (!Contact->LeadingInitials.IsEmpty())
			 ShortName += (L", " + Contact->LeadingInitials);
		   if (SameText(Analyst, ShortName) || SameText(Analyst, Contact->ShortContactName)) {
			 if (Analyst != Contact->ShortContactName)
			   ACell->Value = Contact->ShortContactName;
			 TList* CellContacts = InitCellContactsList(ACell);
			 CellContacts->Add(Contact);
			 break;
			 }
		   }
		 }
	   }
	 }

   return true;
}
//---------------------------------------------------------------------------

bool TTilSpreadSheetForm::ParseTLXPublications(void)
{
   UTF8String XPath, XPath2;
   UnicodeString utext;
   int PubCount, count, ID;
   TList* DatasetPubs;
   PUBTYPEDEFS PubTypeDefs;

   try
   {
   XPath = "/TiliaFile/";
   if (xmlin->ValidChild(XPath, "Publications", PubCount)) {
	 if (PubCount == 0) return true;
	 XMLParsingStatus("Parsing Publications");

	 XMLSubElement Publication("/TiliaFile/Publications/Publication");
	 for (int i=1; i<=PubCount; i++) {
	   xml_pub = new PUBLICATION();
	   XPath = Publication.XPath(i);
	   if (xml_Version >= VERSION(2,0,12)) {
		 UnicodeString primary;
		 if (xmlin->GetAttrStr(XPath, "Primary", primary))
		   xml_pub->Primary = SameText(primary, L"true");
		 }
	   xmlin->GetTextValue(XPath, "PublicationType", utext);
	   if (SameText(utext, L"Other"))
		 utext = L"Legacy";
	   map<int, UnicodeString>::iterator itr;
	   for (itr = PubTypeDefs.Def.begin(); itr != PubTypeDefs.Def.end(); itr++) {
		 if (SameText(utext, itr->second)) {
		   xml_pub->pub_type = itr->first;
		   break;
		   }
		 }
	   if (xml_Version >= VERSION(2,0,3)) {
		 if (xmlin->GetIntValue(XPath, "NeotomaID", ID))
		   xml_pub->NeotomaID = ID;
		 xmlin->GetTextValue(XPath, "Notes", xml_pub->Notes);
		 }
	   xmlin->GetTextValue(XPath, "DOI", xml_pub->DOI);
	   xmlin->GetTextValue(XPath, "PublicationYear", xml_pub->PublicationYear);
	   xmlin->GetTextValue(XPath, "Citation", xml_pub->Citation);

	   if (xmlin->ValidChild(XPath, "Authors", count)) {
		 XMLSubElement Author(XPath + "/Authors/Author");
		 for (int k=1; k<=count; k++) {
		   AUTHOR xml_author;
		   XPath2 = Author.XPath(k);
		   if (xmlin->ValidChild(XPath2, "Contact")) {
			 if (xmlin->GetAttrInt("ID", ID))
			   xml_author.contact = ContactList->Contacts[ID-1];
			 }
		   xmlin->GetTextValue(XPath2, "LastName", xml_author.LastName);
		   xmlin->GetTextValue(XPath2, "Initials", xml_author.Initials);
		   xmlin->GetTextValue(XPath2, "GivenNames", xml_author.GivenNames);
		   xmlin->GetTextValue(XPath2, "Suffix", xml_author.Suffix);
		   xml_pub->AuthorList.push_back(xml_author);
		   }
		 }

	   switch (xml_pub->pub_type) {
		 case JOURNAL:      // legacy < version 2.0.3
		   xml_pub->pub_type = JOURNAL_ARTICLE;
		 case JOURNAL_ARTICLE:
		   xmlin->GetTextValue(XPath, "Title", xml_pub->Title);
		   xmlin->GetTextValue(XPath, "Journal", xml_pub->Journal);
		   xmlin->GetTextValue(XPath, "Volume", xml_pub->Volume);
		   xmlin->GetTextValue(XPath, "Issue", xml_pub->Issue);
		   xmlin->GetTextValue(XPath, "Pages", xml_pub->Pages);
		   xmlin->GetTextValue(XPath, "CitationNumber", xml_pub->CitationNumber);
		   xmlin->GetTextValue(XPath, "URL", xml_pub->URL);
		   break;
		 case BOOKCHAPTER:  // legacy < version 2.0.3
		   xml_pub->pub_type = BOOK_CHAPTER;
		 case BOOK_CHAPTER:
		   xmlin->GetTextValue(XPath, "Title", xml_pub->Title);
		   xmlin->GetTextValue(XPath, "BookTitle", xml_pub->BookTitle);
		   if (xml_Version >= VERSION(2,0,3)) {
			 xmlin->GetTextValue(XPath, "Edition", xml_pub->Edition);
			 xmlin->GetTextValue(XPath, "NumVolumes", xml_pub->NumVolumes);
			 }
		   xmlin->GetTextValue(XPath, "Volume", xml_pub->Volume);
		   xmlin->GetTextValue(XPath, "VolumeTitle", xml_pub->VolumeTitle);
		   xmlin->GetTextValue(XPath, "SeriesTitle", xml_pub->SeriesTitle);
		   xmlin->GetTextValue(XPath, "SeriesNumber", xml_pub->SeriesNumber);
		   xmlin->GetTextValue(XPath, "Publisher", xml_pub->Publisher);
		   xmlin->GetTextValue(XPath, "Pages", xml_pub->Pages);
		   xmlin->GetTextValue(XPath, "City", xml_pub->City);
		   xmlin->GetTextValue(XPath, "State", xml_pub->State);
		   xmlin->GetTextValue(XPath, "Country", xml_pub->Country);
		   xmlin->GetTextValue(XPath, "OrigLang", xml_pub->OrigLang);

		   if (xmlin->ValidChild(XPath, "Editors", count)) {
			 if (xml_Version < VERSION(2,0,3)) {
			   for (int j=0; j<count; j++) {
				 if (xmlin->GetChildText(j, utext)) {
				   EDITOR xml_editor(utext);
				   xml_pub->EditorList.push_back(xml_editor);
				   }
				 }
			   }
			 else {
			   XMLSubElement Editor(XPath + "/Editors/Editor");
			   for (int j=1; j<=count; j++) {
				 EDITOR xml_editor;
				 XPath2 = Editor.XPath(j);
				 xmlin->GetTextValue(XPath2, "LastName", xml_editor.LastName);
				 xmlin->GetTextValue(XPath2, "Initials", xml_editor.Initials);
				 xmlin->GetTextValue(XPath2, "Suffix", xml_editor.Suffix);
				 xml_pub->EditorList.push_back(xml_editor);
				 }
			   }
			 }

		   if (xmlin->ValidChild(XPath, "Translators", count)) {
			 if (xml_Version < VERSION(2,0,3)) {
			   for (int j=0; j<count; j++) {
				 if (xmlin->GetChildText(j, utext)) {
				   EDITOR xml_editor(utext);
				   xml_pub->TranslatorList.push_back(xml_editor);
				   }
				 }
			   }
			 else {
			   XMLSubElement Translator(XPath + "/Translators/Translator");
			   for (int j=1; j<=count; j++) {
				 EDITOR xml_translator;
				 XPath2 = Translator.XPath(j);
				 xmlin->GetTextValue(XPath2, "LastName", xml_translator.LastName);
				 xmlin->GetTextValue(XPath2, "Initials", xml_translator.Initials);
				 xmlin->GetTextValue(XPath2, "Suffix", xml_translator.Suffix);
				 xml_pub->TranslatorList.push_back(xml_translator);
				 }
			   }
			 }
		   break;
		 case BOOK:        // legacy < version 2.0.3
		 case EDITEDBOOK:  // legacy < version 2.0.3
		 case AUTHORED_BOOK:
		 case EDITED_BOOK:
		   if (xml_pub->pub_type == BOOK)
			 xml_pub->pub_type = AUTHORED_BOOK;
		   else if (xml_pub->pub_type == EDITEDBOOK)
			 xml_pub->pub_type = EDITED_BOOK;
		   xmlin->GetTextValue(XPath, "BookTitle", xml_pub->BookTitle);
		   if (xml_Version >= VERSION(2,0,3)) {
			 xmlin->GetTextValue(XPath, "Edition", xml_pub->Edition);
			 xmlin->GetTextValue(XPath, "NumVolumes", xml_pub->NumVolumes);
			 }
		   xmlin->GetTextValue(XPath, "Volume", xml_pub->Volume);
		   xmlin->GetTextValue(XPath, "VolumeTitle", xml_pub->VolumeTitle);
		   xmlin->GetTextValue(XPath, "SeriesTitle", xml_pub->SeriesTitle);
		   xmlin->GetTextValue(XPath, "SeriesNumber", xml_pub->SeriesNumber);
		   xmlin->GetTextValue(XPath, "Publisher", xml_pub->Publisher);
		   xmlin->GetTextValue(XPath, "City", xml_pub->City);
		   xmlin->GetTextValue(XPath, "State", xml_pub->State);
		   xmlin->GetTextValue(XPath, "Country", xml_pub->Country);
		   xmlin->GetTextValue(XPath, "OrigLang", xml_pub->OrigLang);

		   if (xmlin->ValidChild(XPath, "Translators", count)) {
			 if (xml_Version < VERSION(2,0,3)) {
			   for (int j=0; j<count; j++) {
				 if (xmlin->GetChildText(j, utext)) {
				   EDITOR xml_editor(utext);
				   xml_pub->TranslatorList.push_back(xml_editor);
				   }
				 }
			   }
			 else {
			   XMLSubElement Translator(XPath + "/Translators/Translator");
			   for (int j=1; j<=count; j++) {
				 EDITOR xml_translator;
				 XPath2 = Translator.XPath(j);
				 xmlin->GetTextValue(XPath2, "LastName", xml_translator.LastName);
				 xmlin->GetTextValue(XPath2, "Initials", xml_translator.Initials);
				 xmlin->GetTextValue(XPath2, "Suffix", xml_translator.Suffix);
				 xml_pub->TranslatorList.push_back(xml_translator);
				 }
			   }
			 }
		   break;
		 case THESIS:      // legacy < version 2.0.3
		   xmlin->GetTextValue(XPath, "ThesisType", utext);
		   xml_pub->DecodeThesisType(utext);
		 case DOCTORAL_THESIS:
		 case MASTERS_THESIS:
		 case UNDERGRAD_THESIS:
		   xmlin->GetTextValue(XPath, "Title", xml_pub->Title);
		   xmlin->GetTextValue(XPath, "University", xml_pub->University);
		   xmlin->GetTextValue(XPath, "City", xml_pub->City);
		   xmlin->GetTextValue(XPath, "State", xml_pub->State);
		   xmlin->GetTextValue(XPath, "Country", xml_pub->Country);
		   break;
		 case REPORT:            // legacy < version 2.0.3
		 case AUTHORED_REPORT:
		 case EDITED_REPORT:
		   xmlin->GetTextValue(XPath, "Title", xml_pub->Title);
		   xmlin->GetTextValue(XPath, "SeriesTitle", xml_pub->SeriesTitle);
		   xmlin->GetTextValue(XPath, "SeriesNumber", xml_pub->SeriesNumber);
		   xmlin->GetTextValue(XPath, "Publisher", xml_pub->Publisher);
		   xmlin->GetTextValue(XPath, "City", xml_pub->City);
		   xmlin->GetTextValue(XPath, "State", xml_pub->State);
		   xmlin->GetTextValue(XPath, "Country", xml_pub->Country);
		   break;
		 case OTHER_AUTHORED:
		 case OTHER_EDITED:
		 case LEGACY:
           xmlin->GetTextValue(XPath, "Title", xml_pub->Title);
		   break;
		 case WEBSITE:
		   xmlin->GetTextValue(XPath, "Title", xml_pub->Title);
		   xmlin->GetTextValue(XPath, "URL", xml_pub->URL);
		   break;
		 }
		 Publications->Add(xml_pub);
	   }
	 }
   }
   catch(Exception &e)
   {
	 MessageDlg("Error Publications data. Class " + e.ClassName() + ". " + e.Message,
				mtWarning, TMsgDlgButtons() << mbOK, 0);
	 return false;
   }

   // this is done because publications are not yet read when spreadhseet is parsed
   if (SSPubs.size() && Publications->Count > 0) {  // add publication pointers
	 for (unsigned int i=0; i<SSPubs.size(); i++) {
	   TProfGridCell *ACell = ProfGrid1->Cells[SSPubs[i].col][SSPubs[i].row];
	   CELLOBJECT* CellObject;
	   if (ACell->CellObject != NULL) {
		 CellObject = (CELLOBJECT*)ACell->CellObject;
		 }
	   else {
		 CellObject = new CELLOBJECT(CELLPUBLICATIONS);
		 AddCellObject(ACell, CellObject);
		 }
	   DatasetPubs = (TList*)CellObject->Object;
	   PUBLICATION* pub = (PUBLICATION*)Publications->Items[SSPubs[i].id];
	   DatasetPubs->Add(pub);
	   }
	 SSPubs.clear();
	 }

   return true;
}
//---------------------------------------------------------------------------

bool TTilSpreadSheetForm::ParseTLXSpecimens(void)
{
   UTF8String XPath, XPath1, XPath2;
   UnicodeString element, utext;
   int SpecCount, count, ID;
   double dValue;
   SPECIMEN* xmlSpecimen;

   if (xml_Version < VERSION(2,0,43))
	 return true;

   map<int,SPECIMEN*> xmlSpecimens;
   try
   {
   XPath = "/TiliaFile/";
   if (xmlin->ValidChild(XPath, "Specimens", SpecCount)) {
	 if (SpecCount == 0) return true;

	 XMLParsingStatus("Parsing Specimens");

	 XMLSubElement Specimen("/TiliaFile/Specimens/Specimen");
	 for (int i=1; i<=SpecCount; i++) {
	   xmlSpecimen = new SPECIMEN();
	   XPath = Specimen.XPath(i);
	   if (xmlin->GetAttrInt(XPath, "ID", ID)) {
		 xmlSpecimen->SpecimenID = ID;
		 SpecimenIDs.insert(ID);
		 }
	   xmlin->SetXPath(XPath);
	   count = xmlin->XChildrenCount();
	   for (int j=0; j<count; j++) {
		 element = xmlin->GetChildName(j);
		 if (SameText(element, "UserSpecID")) {
		   if (xmlin->GetChildText(j,utext))
			 xmlSpecimen->UserSpecimenID = utext;
		   }
		 else if (SameText(element, "Taxon")) {
		   if (xmlin->GetChildText(j,utext))
			 xmlSpecimen->Taxon = utext;
		   }
		 else if (SameText(element, "TaxaGroup")) {
		   if (xmlin->GetChildText(j,utext))
			 xmlSpecimen->TaxaGroup = utext;
		   }
		 else if (SameText(element, "Element")) {
		   if (xmlin->GetChildText(j,utext))
			 xmlSpecimen->Element = utext;
		   }
		 else if (SameText(element, "Symmetry")) {
		   if (xmlin->GetChildText(j,utext))
			 xmlSpecimen->Symmetry = utext;
		   }
		 else if (SameText(element, "Portion")) {
		   if (xmlin->GetChildText(j,utext))
			 xmlSpecimen->Portion = utext;
		   }
		 else if (SameText(element, "Maturity")) {
		   if (xmlin->GetChildText(j,utext))
			 xmlSpecimen->Maturity = utext;
		   }
		 else if (SameText(element, "Sex")) {
		   if (xmlin->GetChildText(j,utext))
			 xmlSpecimen->Sex = utext;
		   }
		 else if (SameText(element, "DomesticStatus")) {
		   if (xmlin->GetChildText(j,utext))
			 xmlSpecimen->DomesticStatus = utext;
		   }
		 else if (SameText(element, "Preservative")) {
		   if (xmlin->GetChildText(j,utext))
			 xmlSpecimen->Preservative = utext;
		   }
		 else if (SameText(element, "NISP")) {
		   if (xmlin->GetChildText(j,utext)) {
			 if (TryStrToFloat(utext,dValue))
			   xmlSpecimen->NISP = dValue;
			 }
		   }
		 else if (SameText(element, "Repository")) {
		   if (xmlin->GetChildText(j,utext))
			 xmlSpecimen->Repository = utext;
		   }
		 else if (SameText(element, "SpecNr")) {
		   if (xmlin->GetChildText(j,utext))
			 xmlSpecimen->SpecNr = utext;
		   }
		 else if (SameText(element, "FieldNr")) {
		   if (xmlin->GetChildText(j,utext))
			 xmlSpecimen->FieldNr = utext;
		   }
		 else if (SameText(element, "ArctosNr")) {
		   if (xmlin->GetChildText(j,utext))
			 xmlSpecimen->ArctosNr = utext;
		   }
		 else if (SameText(element, "GenBankNr")) {
		   if (xmlin->GetChildText(j,utext))
			 xmlSpecimen->GenBankNrs.insert(utext);
		   }
		 else if (SameText(element, "Notes")) {
		   if (xmlin->GetChildText(j,utext))
			 xmlSpecimen->Notes = utext;
		   }
		 else if (SameText(element, "Taphonomy")) {
		   int scount;
		   if (xmlin->ValidChild(XPath, "Taphonomy", scount)) {
			 XMLSubElement Systems(XPath + L"/Taphonomy/System");
			 for (int j = 1; j <= scount; j++) {
			   XPath1 = Systems.XPath(j);
			   UnicodeString System;
			   if (xmlin->GetAttrStr(XPath1, "Name", System)) {
				 int tcount = xmlin->XChildrenCount();
				 for (int k = 0; k < tcount; k++) {
				   xmlin->GetChildText(k,utext);
				   xmlSpecimen->Taphonomy[System].insert(utext);
				   }
				 }
			   }
			 }
		   }
		 }
	   xmlSpecimens[ID] = xmlSpecimen;
	   }
	 }
   }
   catch(Exception &e)
   {
	 if (xmlSpecimens.size() > 0) {
	   for (unsigned int i=0; i<xmlSpecimens.size(); i++)
		 delete xmlSpecimens[i];
	   xmlSpecimens.clear();
	   }
	 MessageDlg("Error Specimens data. Class " + e.ClassName() + ". " + e.Message,
				mtWarning, TMsgDlgButtons() << mbOK, 0);
	 return false;
   }

   // set a default SpecimenTaxaGroup
   if (xmlSpecimens.size() > 0)
	 SpecimenTaxaGroup = xmlSpecimens.begin()->second->TaxaGroup;

   // this is done because specimens are not yet read when spreadhseet is parsed
   if (SSSpecimens.size() > 0 && xmlSpecimens.size() > 0) {  // add specimen pointers
	 for (unsigned int i=0; i<SSSpecimens.size(); i++) {
	   // get or create the cell object
	   TProfGridCell *ACell = ProfGrid1->Cells[SSSpecimens[i].col][SSSpecimens[i].row];
	   CELLOBJECT* CellObject;
	   if (ACell->CellObject != NULL) {
		 CellObject = (CELLOBJECT*)ACell->CellObject;
		 }
	   else {
		 CellObject = new CELLOBJECT(CELLSPECIMENS);
		 AddCellObject(ACell, CellObject);
		 }
	   TList* Specimens = (TList*)CellObject->Object;

	   // assign the specimen to it
	   if (xmlSpecimens.count(SSSpecimens[i].id) == 1) {
		 Specimens->Add(xmlSpecimens[SSSpecimens[i].id]);
		 xmlSpecimens.erase(SSSpecimens[i].id);
		 }
	   }
	 SSSpecimens.clear();
	 // clean up any extraneous specimens. This should never happen, but...
	 if (xmlSpecimens.size() > 0) {
	   map<int,SPECIMEN*>::iterator itr;
	   for (itr = xmlSpecimens.begin(); itr != xmlSpecimens.end(); itr++)
		 delete itr->second;
	   xmlSpecimens.clear();
	   }
	 }

   return true;
}
//---------------------------------------------------------------------------

bool TTilSpreadSheetForm::ParseTLXSite(void)
{
   int count;
   double dValue;
   UnicodeString uValue;
   UTF8String XPath;

   try
   {
   XPath = "/TiliaFile/";
   if (xmlin->ValidChild(XPath, "Site", count)) {
	 if (count == 0) return true;
	 XPath += "Site/";
	 SITE* SitePtr = (SITE*)Sites->Items[0];
	 XMLParsingStatus("Parsing Site metadata");
	 xmlin->GetTextValue(XPath, "SiteName", SitePtr->SiteName);
	 xmlin->GetIntValue(XPath, "EPDSiteID", EPD.SiteID);
	 xmlin->GetTextValue(XPath, "SiteDescription", SitePtr->SiteDescription);
	 if (xmlin->GetDoubleValue(XPath, "LongEast", dValue))
	   SitePtr->LongEast = dValue;
	 if (xmlin->GetDoubleValue(XPath, "LongWest", dValue))
	   SitePtr->LongWest = dValue;
	 if (xmlin->GetDoubleValue(XPath, "LatNorth", dValue))
	   SitePtr->LatNorth = dValue;
	 if (xmlin->GetDoubleValue(XPath, "LatSouth", dValue))
	   SitePtr->LatSouth = dValue;
	 if (xmlin->GetDoubleValue(XPath, "Altitude", dValue))
	   SitePtr->Altitude = dValue;
	 if (xmlin->GetDoubleValue(XPath, "WaterDepth", dValue))  // older files
	   SitePtr->CollUnits[0].WaterDepth = dValue;
	 if (xmlin->GetDoubleValue(XPath, "Area", dValue))
	   SitePtr->Area = dValue;
	 xmlin->GetTextValue(XPath, "Country", SitePtr->Country);
	 xmlin->GetTextValue(XPath, "State", SitePtr->State);
	 xmlin->GetTextValue(XPath, "County", SitePtr->County);
	 xmlin->GetTextValue(XPath, "AdminUnit", SitePtr->AdminUnit);
	 xmlin->GetTextValue(XPath, "Notes", SitePtr->Notes);

	 if (xml_Version >= VERSION(1,8,17)) {
	   UTF8String XPath1;
	   if (xmlin->ValidChild(XPath, "LakeParameters", count)) {
		 XPath += "LakeParameters/";
		 bool newParam = false;
		 XMLSubElement LakeParameter(XPath + "LakeParameter");
		 for (int i=1; i<=count; i++) {
		   XPath1 = LakeParameter.XPath(i);
		   WideString Param;
		   if (xmlin->GetTextValue(XPath1, "Parameter", uValue))
			 Param = uValue;
		   xmlin->GetDoubleValue(XPath1, "Value", dValue);

		   LAKEPARAM LakeParam;
		   LakeParam.Name = Param;
		   LakeParam.Value = dValue;
		   SitePtr->LakeParams.push_back(LakeParam);

		   bool found = false;
		   int rows = AdvStringGridLake->RowCount;
		   for (int k=1; k<rows; k++) {
			 if (SameText(Param, AdvStringGridLake->Cells[0][k])) {
			   found = true;
			   break;
			   }
			 }
		   if (!found) {
			 newParam = true;
			 AdvStringGridLake->RowCount++;
			 AdvStringGridLake->Cells[0][AdvStringGridLake->RowCount - 1] = Param;
			 }
		   }
		 if (newParam) {
		   AdvStringGridLake->QSort();
		   }
		 }
	   }
	 }
   }
   catch(Exception &e)
   {
     MessageDlg("Error reading Site data. Class " + e.ClassName() + ". " + e.Message,
                mtWarning, TMsgDlgButtons() << mbOK, 0);
     return false;
   }
   return true;
}
//---------------------------------------------------------------------------

bool TTilSpreadSheetForm::ParseTLXCollectionUnit(void)
{
   UTF8String XPath, XPath1;
   double dValue;
   int count, ID;

   try
   {
   bool CollectionUnit = false;
   XPath = "/TiliaFile/";
   if (xml_Version == VERSION(1,0,1)) {
	 if (xmlin->ValidChild(XPath, "Collection", count)) {
	   XPath += "Collection/";
	   CollectionUnit = true;
	   }
	 }
   else {
	 if (xmlin->ValidChild(XPath, "CollectionUnit", count)) {
	   XPath += "CollectionUnit/";
	   CollectionUnit = true;
	   }
	 }

   if (CollectionUnit) {
	 if (count == 0) return true;
	 XMLParsingStatus("Parsing Collection Unit metadata");
	 SITE* site_ptr = (SITE*)Sites->Items[0];
	 vector<COLLECTION>::pointer coll_ptr = &site_ptr->CollUnits[0];
	 xmlin->GetTextValue(XPath, "Handle", coll_ptr->Handle);
	 xmlin->GetIntValue(XPath, "EPDCollUnitID", EPD.CollectionUnitID);
	 //xmlin->GetIntValue(XPath, "WhitmoreID1", coll_ptr->WhitmoreID1);
	 xmlin->GetTextValue(XPath, "CollectionName", coll_ptr->CollectionName);
	 xmlin->GetTextValue(XPath, "CollectionType", coll_ptr->CollectionType);
	 if (coll_ptr->CollectionType.CompareIC("Midden") == 0)
	   coll_ptr->CollectionType = "Animal midden";
	 xmlin->GetTextValue(XPath, "CollectionDevice", coll_ptr->CollectionDevice);

	 if (xmlin->ValidChild(XPath, "Collectors", count)) {
	   XMLSubElement Collector(XPath + "Collectors/Contact");
	   for (int i=1; i<=count; i++) {
		 if (xmlin->GetAttrInt(Collector.XPath(i), "ID", ID))
		   coll_ptr->Collectors.push_back(ContactList->Contacts[ID-1]);
		 }
	   }

	 if (xmlin->GetDoubleValue(XPath, "CollectionDate", dValue)) {
	   if (dValue > 0)
		 dValue = floor(dValue);
	   else if (dValue < 0)
		 dValue = ceil(dValue);
	   else if (xml_Version < VERSION(1,1,4))
		 dValue = NaN;
	   if (!IsNan(dValue)) {
		 //coll_ptr->CollDate = dValue;
		 //coll_ptr->CollDate.ChangeType(varDate);
		 TDateTime AResult;
		 if(TryFloatToDateTime(dValue, AResult))
           coll_ptr->CollDate = AResult;
		 }
	   }
	 xmlin->GetTextValue(XPath, "Location", coll_ptr->Location);
	 if (xmlin->GetDoubleValue(XPath, "GPSLat", dValue))
	   coll_ptr->GPSLat = dValue;
	 if (xmlin->GetDoubleValue(XPath, "GPSLong", dValue))
	   coll_ptr->GPSLong = dValue;
	 if (xmlin->GetDoubleValue(XPath, "GPSError", dValue))
	   coll_ptr->GPSError = dValue;
	 if (xmlin->GetDoubleValue(XPath, "GPSAltitude", dValue))
	   coll_ptr->GPSAltitude = dValue;
	 xmlin->GetTextValue(XPath, "DepositionalEnvironment", coll_ptr->DepEnv);
	 if (coll_ptr->DepEnv.IsEmpty())
	   xmlin->GetTextValue(XPath, "DepositionalContext", coll_ptr->DepEnv);
	 if (xml_Version >= VERSION(1,8,17)) {
	   xmlin->GetTextValue(XPath, "Substrate", coll_ptr->Substrate);
	   xmlin->GetIntValue(XPath, "SlopeAngle", coll_ptr->SlopeAngle);
	   if (coll_ptr->SlopeAngle < 0)
		 coll_ptr->SlopeAngle = Unassigned();
	   xmlin->GetIntValue(XPath, "SlopeAspect", coll_ptr->SlopeAspect);
	   if (coll_ptr->SlopeAspect < 0)
		 coll_ptr->SlopeAspect = Unassigned();
	   }
	 if (xmlin->GetDoubleValue(XPath, "WaterDepth", dValue))
	   coll_ptr->WaterDepth = dValue;
	 xmlin->GetTextValue(XPath, "Notes", coll_ptr->Notes);
	 }
   }
   catch(Exception &e)
   {
	 MessageDlg("Error reading CollectionUnit data. Class " + e.ClassName() + ". " + e.Message,
				mtWarning, TMsgDlgButtons() << mbOK, 0);
	 return false;
   }
   return true;
}
//---------------------------------------------------------------------------

bool TTilSpreadSheetForm::ParseTLXDataset(void)
{
   UTF8String XPath, XPath1, XPath2;
   double dValue;
   int dcount, count, ID;

   try
   {
   XPath = "/TiliaFile/";
   if (xml_Version >= VERSION(2,0,3)) {
	 if (!xmlin->ValidChild(XPath, "Datasets", dcount))
	   return true;
	 XPath = "/TiliaFile/Datasets/";
	 }
   else
	 dcount = 1;

   if (xmlin->ValidChild(XPath, "Dataset")) {
	 XMLParsingStatus("Parsing Dataset metadata");
	 XMLSubElement XDataset(XPath + "Dataset");

	 for (int k=0; k<dcount; k++) {
	   if (xml_Version >= VERSION(2,0,3))
		 XPath = XDataset.XPath(k+1);
	   else
		 XPath += "Dataset";

	   if (k > 0) {
		 DATASET dataset;
		 Datasets.push_back(dataset);
		 }

	   if (xmlin->GetTextValue(XPath, "DatasetType", Datasets[k].DatasetType))
		 ProfGrid1->Cells[1][1]->Value = Datasets[k].DatasetType;
	   int EPDDatasetID;
	   if (xmlin->GetIntValue(XPath, "EPDDatasetID", EPDDatasetID))
		 EPD.Datasets[3] = EPDDatasetID;
	   xmlin->GetTextValue(XPath, "Name", Datasets[k].Name);
	   xmlin->GetBoolValue(XPath, "IsSSamp", Datasets[k].IsSSamp);
	   xmlin->GetBoolValue(XPath, "WhitmoreData", Datasets[k].WhitmoreData);
	   xmlin->GetBoolValue(XPath, "IsAggregate", Datasets[k].IsAggregate);
	   xmlin->GetTextValue(XPath, "AggregateOrder", Datasets[k].AggregateOrder);
	   xmlin->GetTextValue(XPath, "Notes", Datasets[k].Notes);

	   if (xmlin->ValidChild(XPath, "Investigators", count)) {
		 XMLSubElement Investigator(XPath + "/Investigators/Contact");
		 for (int i=1; i<=count; i++) {
		   if (xmlin->GetAttrInt(Investigator.XPath(i), "ID", ID))
			 Datasets[k].Investigators.push_back(ContactList->Contacts[ID-1]);
		   }
		 }

	   if (xmlin->ValidChild(XPath, "Processors", count)) {
		 XMLSubElement Processor(XPath + "/Processors/Contact");
		 for (int i=1; i<=count; i++) {
		   if (xmlin->GetAttrInt(Processor.XPath(i), "ID", ID))
			 Datasets[k].Processors.push_back(ContactList->Contacts[ID-1]);
		   }
		 }

	   // ShowMessage(L"Breakpoint D");

	   if (xmlin->ValidChild(XPath, "Publications", count)) {
		 XMLSubElement Publication(XPath + "/Publications/Publication");
		 for (int i=1; i<=count; i++) {
		   if (xmlin->GetAttrInt(Publication.XPath(i), "ID", ID))
			 Datasets[k].Publications.push_back((PUBLICATION*)Publications->Items[ID-1]);
		   }
		 }

	   if (xml_Version >= VERSION(1,8,17)) {
		 if (xmlin->ValidChild(XPath, "Repositories", count)) {
		   REPOSITORY rep;
		   XMLSubElement RepositoryPath(XPath + "/Repositories/Repository");
		   for (int i=1; i<=count; i++) {
			 XPath1 = RepositoryPath.XPath(i);
			 xmlin->GetTextValue(XPath1, "Acronym", rep.Acronym);
			 xmlin->GetTextValue(XPath1, "Repository", rep.Repository);
			 xmlin->GetTextValue(XPath1, "Notes", rep.Notes);
			 if (xml_Version >= VERSION(2,0,57))
			   xmlin->GetTextValue(XPath1, "SpecimenNotes", rep.SpecimenNotes);
			 bool found = false;
			 // add any new repositories in tlx file to those from lookup file
			 for (int row=1; row<AdvColumnGrid2->RowCount; row++) {
			   if (SameText(rep.Acronym, AdvColumnGrid2->Cells[1][row])) {
				 rep.Repository = AdvColumnGrid2->Cells[2][row];
				 // rep.Notes = AdvColumnGrid2->Cells[3][row];
				 if (RepositoryNotes.count(rep.Acronym) > 0)
				   rep.Notes = RepositoryNotes[rep.Acronym];
				 rep.SpecimenNotes = AdvColumnGrid2->Cells[3][row];
				 found = true;
				 break;
				 }
			   }
			 Datasets[k].Repositories.push_back(rep);
			 if (!found) {
			   AdvColumnGrid2->RowCount++;
			   int row = AdvColumnGrid2->RowCount - 1;
			   AdvColumnGrid2->Cells[1][row] = rep.Acronym;
			   AdvColumnGrid2->Cells[2][row] = rep.Repository;
			   if (xml_Version >= VERSION(2,0,57)) {
				 if (!rep.Notes.IsEmpty())
				   RepositoryNotes[rep.Acronym] = rep.Notes;
				 AdvColumnGrid2->Cells[3][row] = rep.SpecimenNotes;
				 }
			   }
			 }
		   AdvColumnGrid2->AddCheckBoxColumn(0, false, false);
		   AdvColumnGrid2->QSort();
		   cxPopupEdit12->Text = Datasets[k].RepositoryText();
		   }
		 }

	   if (xmlin->ValidChild(XPath, "Submissions", count)) {
		 XMLSubElement Submission(XPath + "/Submissions/Submission");
		 for (int i=1; i<=count; i++) {
		   SUBMISSION submission;
		   XPath1 = Submission.XPath(i);
		   xmlin->GetBoolValue(XPath1, "Archived", submission.Archived);
		   xmlin->GetTextValue(XPath1, "SubmittedForm", submission.SubmittedForm);
		   xmlin->GetTextValue(XPath1, "SubmissionType", submission.SubmissionType);
		   if (xmlin->GetDoubleValue(XPath1, "SubmissionDate", dValue)) {
			 if (dValue > 0)
			   dValue = floor(dValue);
			 else if (dValue < 0)
			   dValue = ceil(dValue);
			 else if (xml_Version < VERSION(1,1,4))
			   dValue = NaN;
			 if (!IsNan(dValue))
			   submission.SubmissionDate = dValue;
			 }
		   xmlin->GetTextValue(XPath1, "SubmittersText", submission.SubmittersComboBoxText);
		   xmlin->GetTextValue(XPath1, "Notes", submission.Notes);
		   int SubCount;
		   if (xmlin->ValidChild(XPath1, "Submitters", SubCount)) {
			 XMLSubElement Submitter(XPath1 + "/Submitters/Contact");
			 for (int i=1; i<=SubCount; i++) {
			   if (xmlin->GetAttrInt(Submitter.XPath(i), "ID", ID))
				 submission.Submitters.push_back(ContactList->Contacts[ID-1]);
			   }
			 }
		   Datasets[k].Submissions.push_back(submission);
		   }
		 }
	   }
	 }
   }
   catch(Exception &e)
   {
	 MessageDlg("Error reading Dataset data. Class " + e.ClassName() + ". " + e.Message,
				mtWarning, TMsgDlgButtons() << mbOK, 0);
	 return false;
   }
   return true;
}
//---------------------------------------------------------------------------

bool TTilSpreadSheetForm::ParseTLXGeochronology(void)
{
   UTF8String XPath, XPath1, XPath2, XPath3;
   UnicodeString Notes;
   UnicodeString AnalysisUnitIDType;
   double dValue;
   int iValue, idx, ID, count, count1;
   short GeochronID;

   try
   {
   XPath = "/TiliaFile/";
   if (!xmlin->ValidChild(XPath, "GeochronDataset"))
	 return true;
   XMLParsingStatus("Parsing Geochronology metadata");

   if (xml_Version >= VERSION(1,2,7)) {
	 XPath += "GeochronDataset/";
	 xmlin->GetTextValue(XPath, "Notes", Notes);
	 cxBlobEdit1->Text = Notes;
	 GeochronDataset.Notes = Notes;
	 if (xml_Version >= VERSION(2,0,26)) {
	   int EPDDatasetID;
	   if (xmlin->GetIntValue(XPath, "EPDDatasetID", EPDDatasetID))
		 EPD.Datasets[1] = EPDDatasetID;
	   if (xmlin->ValidChild(XPath, "Investigators", count)) {
		 XMLSubElement Investigator(XPath + "/Investigators/Contact");
		 for (int i=1; i<=count; i++) {
		   if (xmlin->GetAttrInt(Investigator.XPath(i), "ID", ID))
			 GeochronDataset.Investigators.push_back(ContactList->Contacts[ID-1]);
		   }
		 }
	   }
	 }

   if (xmlin->ValidChild(XPath, "Geochronology", count)) {
	 if (count == 0) return true;
	 XPath += "Geochronology/";
	 XMLSubElement GeochronSample(XPath + "GeochronSample");
	 for (int i=1; i<=count; i++) {
	   GEOCHRON xml_date;
	   XPath1 = GeochronSample.XPath(i);

	   if (xml_Version >= VERSION(1,5,11)) {
		 if (xmlin->GetAttrInt(XPath1, "ID", ID))
		   xml_date.SetID(ID);
		 }

	   if (xml_Version >= VERSION(2,0,8)) {
		 xmlin->GetTextValue(XPath1, "Method", xml_date.Method);
		 }
	   else {
		 UnicodeString Method;   // xml_date.Method
		 xmlin->GetTextValue(XPath1, "Method", Method);
		 if (ContainsText(Method, L"Carbon-14")) {
		   xml_date.Method = L"Carbon-14";
		   if (ContainsText(Method, L"accelerator"))
			 xml_date.Parameters[L"Method"] = RadiocarbonParams[0].Categories[1];
		   else if (ContainsText(Method, L"gas"))
			 xml_date.Parameters[L"Method"] = RadiocarbonParams[0].Categories[3];
		   else if (ContainsText(Method, L"liquid"))
			 xml_date.Parameters[L"Method"] = RadiocarbonParams[0].Categories[4];
		   else if (ContainsText(Method, L"conventional"))
			 xml_date.Parameters[L"Method"] = RadiocarbonParams[0].Categories[2];
		   }
		 }

	   xmlin->GetTextValue(XPath1, "AgeUnits", xml_date.AgeUnits);
	   if ((idx = xml_date.AgeUnits.Pos("B.P.")) > 0) {
		 xml_date.AgeUnits.Delete(idx,4);
		 xml_date.AgeUnits.Insert("BP",idx);
		 }

	   //if (GeochronID == GEOCHRONDEPTH) {
		 if (xmlin->GetDoubleValue(XPath1, "Depth", dValue))
		   xml_date.Depth = dValue;
		 if (xmlin->GetDoubleValue(XPath1, "Thickness", dValue))
		   xml_date.Thickness = dValue;
	   //	 }
	   //else {
		 xmlin->GetTextValue(XPath1, "AnalysisUnit", xml_date.AnalUnit);
	   //	 }

	   xmlin->GetTextValue(XPath1, "LabNumber", xml_date.LabNumber);
	   if (xmlin->GetDoubleValue(XPath1, "Age", dValue))
		 xml_date.Age = dValue;
	   if (xmlin->GetDoubleValue(XPath1, "ErrorOlder", dValue))
		 xml_date.ErrorOlder = dValue;
	   if (xmlin->GetDoubleValue(XPath1, "ErrorYounger", dValue))
		 xml_date.ErrorYounger = dValue;
	   if (xmlin->GetIntValue(XPath1, "Sigma", iValue))
		 xml_date.Sigma = iValue;
	   if (xmlin->GetDoubleValue(XPath1, "StdDev", dValue))
		 xml_date.StdDev = dValue;
	   xmlin->GetBoolValue(XPath1, "GreaterThan", xml_date.GreaterThan);

	   if (xml_Version >= VERSION(2,0,8)) {
		 if (xmlin->ValidChild(XPath1, "Parameters", count1)) {
		   XMLSubElement Parameter(XPath1 + "/Parameters/Parameter");
		   UnicodeString Name;
		   UnicodeString Value;
		   for (int k=1; k<=count1; k++) {
			 xmlin->GetTextValue(Parameter.XPath(k), "Name", Name);
			 xmlin->GetTextValue(Parameter.XPath(k), "Value", Value);
			 if (SameText(xml_date.Method, L"Carbon-14") && SameText(Name, L"Method"))
			   xml_date.Parameters[Name] = Value;
			 else {
			   int len = Value.Length();
			   int idx = 1;
			   while (idx <= len) {
				 if (Value[idx] == L',')
				   Value[idx] = L'.';
				 idx++;
				 }
			   xml_date.Parameters[Name] = GetDoubleFromText(Value, 0);
			   }
			 }
		   }
		 }
	   else {
		 if (xmlin->GetDoubleValue(XPath1, "Delta13C", dValue))
		 xml_date.Parameters[L"δ13C"] = dValue;
		 }

	   xmlin->GetTextValue(XPath1, "MaterialDated", xml_date.MaterialDated);
	   xmlin->GetTextValue(XPath1, "Notes", xml_date.Notes);
	   xmlin->GetTextValue(XPath1, "PublicationsText", xml_date.PubComboBoxText);

	   if (xmlin->ValidChild(XPath1, "Publications", count1)) {
		 XMLSubElement Publication(XPath1 + "/Publications/Publication");
		 for (int k=1; k<=count1; k++) {
		   if (xmlin->GetAttrInt(Publication.XPath(k), "ID", ID))
			 xml_date.publications.push_back((PUBLICATION*)Publications->Items[ID-1]);
		   }
		 }

	   if (xml_Version >= VERSION(1,8,17)) {
		 if (xmlin->ValidChild(XPath1, "TaxaDated", count1)) {
		   XMLSubElement TaxaDated(XPath1 + "/TaxaDated/");
		   for (int k=1; k<=count1; k++) {
			 XPath2 = TaxaDated.XPath(k);
			 // TAXONDATED xml_TaxonDated(-1);
			 TAXONDATED xml_TaxonDated;

			 if (xml_Version >= VERSION(2,0,42)) {
			   int SpecimenID;
			   xmlin->GetIntValue(XPath2, "SpecimenID", SpecimenID);
			   xml_TaxonDated.Specimen = NULL;
			   if (SpecimenID != -1) {
				 xml_TaxonDated.Specimen = GetSpecimen(SpecimenID);
				 }
			   xmlin->GetTextValue(XPath2, "SpecNr", xml_TaxonDated.UserSpecID);
			   }

			 xmlin->GetTextValue(XPath2, "Taxon", xml_TaxonDated.Taxon);
			 xmlin->GetTextValue(XPath2, "Element", xml_TaxonDated.Element);
			 xmlin->GetTextValue(XPath2, "Fraction", xml_TaxonDated.Fraction);
			 if (xml_Version >= VERSION(2,0,7)) {
			   if (xmlin->GetDoubleValue(XPath2, "CalAgeMedian", dValue))
				 xml_TaxonDated.CalAgeMedian = dValue;
			   if (xmlin->GetDoubleValue(XPath2, "CalAgeOlder", dValue))
				 xml_TaxonDated.CalAgeOlder = dValue;
			   if (xmlin->GetDoubleValue(XPath2, "CalAgeYounger", dValue))
				 xml_TaxonDated.CalAgeYounger = dValue;
			   xmlin->GetTextValue(XPath2, "CalibCurve", xml_TaxonDated.CalibCurve);
			   if (xmlin->ValidChild(XPath2, "CalibProgram")) {
				 XPath3 = XPath2 + "/CalibProgram/";
				 xmlin->GetTextValue(XPath3, "Program", xml_TaxonDated.Calib.Program);
				 xmlin->GetTextValue(XPath3, "Version", xml_TaxonDated.Calib.Version);
				 // add calibration program to lookup list if not in Lookup.xml
				 if (!xml_TaxonDated.Calib.Program.IsEmpty())
				   AddCalibProgram(xml_TaxonDated.Calib);
				 }
			   }
			 xmlin->GetTextValue(XPath2, "Notes", xml_TaxonDated.Notes);
			 xml_date.TaxaDated.push_back(xml_TaxonDated);
			 }
		   }
		 }
	   GeochronList->Add(xml_date);
	   }
	 GeochronDataSource->DataChanged();
	 bool hasdepths = false;
	 bool hasanalunits = false;
	 for (int i=0; i<GeochronList->Count(); i++) {
	   GEOCHRON& Date = GeochronList->Dates[i];
	   if (!Date.Depth.IsEmpty())
		 hasdepths = true;
	   if (!Date.AnalUnit.IsEmpty())
		 hasanalunits = true;
	   if (hasdepths && hasanalunits)
		 break;
	   }
	 cxCheckBox3->Checked = hasanalunits;
     cxCheckBox2->Checked = (hasdepths || (!hasdepths && !hasanalunits));
	 }
   }
   catch(Exception &e)
   {
	 MessageDlg("Error reading Geochronology data. Class " + e.ClassName() + ". " + e.Message,
				mtWarning, TMsgDlgButtons() << mbOK, 0);
	 return false;
   }
   return true;
}
//---------------------------------------------------------------------------

SPECIMEN* TTilSpreadSheetForm::GetSpecimen(int SpecimenID)
{
   SPECIMEN* Specimen;

   list<CELLOBJECT*>::iterator itr = CellObjects.begin();
   while (itr != CellObjects.end()) {
	 if ((*itr)->ObjectType == CELLSPECIMENS) {
	   TList* Specimens = (TList*)(*itr)->Object;
	   for (int i=0; i<Specimens->Count; i++) {
		 Specimen = (SPECIMEN*)Specimens->Items[i];
		 if (SpecimenID == Specimen->SpecimenID)
		   return Specimen;
		 }
	   }
	 itr++;
	 }
   return NULL;
}
//---------------------------------------------------------------------------

bool TTilSpreadSheetForm::ParseTLXAgeModels(void)
{
   UTF8String XPath, XPath1, XPath2, XPath3;
   UnicodeString AnalysisUnitIDType;
   double dValue;
   int index, count, count1, count2, ID;
   short ChronControlID;

   try
   {
   XPath = "/TiliaFile/";
   if (xmlin->ValidChild(XPath, "AgeModels", count)) {
	 if (count == 0) return true;
	 XMLParsingStatus("Parsing Age Model metadata");
	 xml_chron_number = 1;

	 XMLSubElement AgeModel(XPath + "AgeModels/AgeModel");
	 for (int i=1; i<=count; i++) {
	   xml_agemodel = new AGEMODEL();
	   XPath1 = AgeModel.XPath(i);
	   if (!xmlin->GetIntValue(XPath1, "ChronNumber", xml_agemodel->ChronNumber))
		 xml_agemodel->ChronNumber = xml_chron_number++;
	   xmlin->GetTextValue(XPath1, "ChronologyName", xml_agemodel->ChronologyName);
	   xmlin->GetTextValue(XPath1, "AgeUnits", xml_agemodel->AgeUnits);
	   if ((index = xml_agemodel->AgeUnits.Pos("B.P.")) > 0) {
		 xml_agemodel->AgeUnits.Delete(index, 4);
		 xml_agemodel->AgeUnits.Insert("BP", index);
		 }
	   xmlin->GetBoolValue(XPath1, "Default", xml_agemodel->Default);

	   if (xmlin->GetDoubleValue(XPath1, "DatePrepared", dValue)) {
		 if (dValue > 0)
		   dValue = floor(dValue);
		 else if (dValue < 0)
		   dValue = ceil(dValue);
		 else if (xml_Version < VERSION(1,1,4))
		   dValue = NaN;
		 if (!IsNan(dValue)) {
		   xml_agemodel->DatePrepared = dValue;
		   xml_agemodel->DatePrepared.ChangeType(varDate);
		   }
		 }

	   xmlin->GetTextValue(XPath1, "Model", xml_agemodel->AgeModel);
	   if (xmlin->GetDoubleValue(XPath1, "AgeBoundOlder", dValue))
		 xml_agemodel->AgeBoundOlder = dValue;
	   if (xmlin->GetDoubleValue(XPath1, "AgeBoundYounger", dValue))
		 xml_agemodel->AgeBoundYounger = dValue;
	   xmlin->GetTextValue(XPath1, "Notes", xml_agemodel->Notes);
	   xmlin->GetTextValue(XPath1, "PreparersText", xml_agemodel->PreparersComboBoxText);

	   if (xmlin->ValidChild(XPath1, "Preparers", count1)) {
		 XMLSubElement Preparer(XPath1 + "/Preparers/Contact");
		 for (int i=1; i<=count1; i++) {
		   if (xmlin->GetAttrInt(Preparer.XPath(i), "ID", ID))
			 xml_agemodel->Preparers.push_back(ContactList->Contacts[ID-1]);
		   }
		 }

	   if (xmlin->ValidChild(XPath1, "ChronControls", count1)) {
		 if (count1 == 0) {
		   AgeModelList->Add(xml_agemodel);
		   continue;
		   }
		 XMLSubElement ChronControl(XPath1 + "/ChronControls/ChronControl");
		 for (int k=1; k<=count1; k++) {
		   xml_chron_control = new CHRON();
		   XPath2 = ChronControl.XPath(k);
		   xmlin->GetTextValue(XPath2, "ControlType", xml_chron_control->ControlType);

		   if (xml_Version < VERSION(1,1,5)) {
			 if (xml_chron_control->ControlType == "C14")
			   xml_chron_control->ControlType = "Radiocarbon";
			 else if (xml_chron_control->ControlType == "Averaged C14")
			   xml_chron_control->ControlType = "Radiocarbon, average of two or more dates";
			 else if (xml_chron_control->ControlType == "Pollen stratigraphic")
			   xml_chron_control->ControlType = "Biostratigraphic, pollen";
			 else if (xml_chron_control->ControlType == "Pb210")
			   xml_chron_control->ControlType = "Lead-210";
			 else if (xml_chron_control->ControlType == "C14 with reservoir correction")
			   xml_chron_control->ControlType = "Radiocarbon, reservoir correction";
			 else if (xml_chron_control->ControlType == "Calibrated C14")
			   xml_chron_control->ControlType = "Radiocarbon, calibrated";
			 else if (xml_chron_control->ControlType == "Interpolated and corrected for compaction")
			   xml_chron_control->ControlType = "Interpolated, corrected for compaction";
			 else if (xml_chron_control->ControlType == "C14 calibrated from calendar years")
			   xml_chron_control->ControlType = "Radiocarbon, calibrated from calendar years";
			 else if (xml_chron_control->ControlType == "TL")
			   xml_chron_control->ControlType = "Thermoluminescence";
			 else if (xml_chron_control->ControlType == "U-series")
			   xml_chron_control->ControlType = "Uranium-series";
			 else if (xml_chron_control->ControlType == "Ar-Ar")
			   xml_chron_control->ControlType = "Argon-argon";
			 else if (xml_chron_control->ControlType == "K-Ar")
			   xml_chron_control->ControlType = "Potassium-argon";
			 else if (xml_chron_control->ControlType == "Laarcher See tephra")
			   xml_chron_control->ControlType = "Laarcher See";
			 else if (xml_chron_control->ControlType == "Mazama tephra")
			   xml_chron_control->ControlType = "Mazama";
			 }

		   if (xml_Version >= VERSION(2,0,3)) {
			 //if (ChronControlID == GEOCHRONDEPTH) {
			   if (xmlin->GetDoubleValue(XPath2, "Depth", dValue))
				 xml_chron_control->Depth = dValue;
			   if (xmlin->GetDoubleValue(XPath2, "Thickness", dValue))
				 xml_chron_control->Thickness = dValue;
			 //  }
			 //else {
			   xmlin->GetTextValue(XPath2, "AnalysisUnit", xml_chron_control->AnalUnit);
			 //  }
			 }
		   else {
             if (xmlin->GetDoubleValue(XPath2, "Depth", dValue))
			   xml_chron_control->Depth = dValue;
			 if (xmlin->GetDoubleValue(XPath2, "Thickness", dValue))
			   xml_chron_control->Thickness = dValue;
			 }
		   xmlin->GetTextValue(XPath2, "AgeUnits", xml_chron_control->AgeUnits);
		   if (xmlin->GetDoubleValue(XPath2, "Age", dValue))
			 xml_chron_control->AgeValue = dValue;
		   if (xmlin->GetDoubleValue(XPath2, "AgeLimitOlder", dValue))
			 xml_chron_control->AgeLimitOlder = dValue;
		   if (xmlin->GetDoubleValue(XPath2, "AgeLimitYounger", dValue))
			 xml_chron_control->AgeLimitYounger = dValue;
		   if (xml_Version >= VERSION(1,8,17)) {
			 xmlin->GetTextValue(XPath2, "CalibCurve", xml_chron_control->CalibCurve);
			 if (xmlin->ValidChild(XPath2, "CalibProgram")) {
			   XPath3 = XPath2 + "/CalibProgram/";
			   xmlin->GetTextValue(XPath3, "Program", xml_chron_control->Calib.Program);
			   xmlin->GetTextValue(XPath3, "Version", xml_chron_control->Calib.Version);
			   // add calibration program to lookup list if not in Lookup.xml
			   if (!xml_chron_control->Calib.Program.IsEmpty())
				 AddCalibProgram(xml_chron_control->Calib);
			   }
			 }
		   if (xml_Version >= VERSION(1,5,11)) {
			 if (xmlin->ValidChild(XPath2, "GeochronLinks", count2)) {
			   XMLSubElement GeochronLink(XPath2 + "/GeochronLinks/GeochronLink");
			   for (int j=1; j<=count2; j++) {
				 if (xmlin->GetAttrInt(GeochronLink.XPath(j), "ID", ID))
				   xml_chron_control->GeochronIDs.push_back(ID);
				 }
			   }
			 }
		   if (xml_Version >= VERSION(2,0,12)) {
			 xmlin->GetTextValue(XPath2, "Notes", xml_chron_control->Notes);
			 }
		   xml_agemodel->ChronControls->Add(xml_chron_control);
		   }
		 }
	   AgeModelList->Add(xml_agemodel);
	   }
	 bool hasdepths = false;
	 bool hasanalunits = false;
	 TList* controls = AgeModelList->AgeModels[0]->ChronControls;
	 for (int i=0; i<controls->Count; i++) {
	   CHRON* control = (CHRON*)controls->Items[i];
	   if (!control->Depth.IsEmpty())
		 hasdepths = true;
	   if (!control->AnalUnit.IsEmpty())
		 hasanalunits = true;
	   if (hasdepths && hasanalunits)
		 break;
	   }
	 if (hasanalunits)
	   CheckBox3->Checked = true;
	 if (hasdepths || (!hasdepths && !hasanalunits))
	   CheckBox1->Checked = true;
	 }
   }
   catch(Exception &e)
   {
	 MessageDlg("Error reading Age Models. Class " + e.ClassName() + ". " + e.Message,
				mtWarning, TMsgDlgButtons() << mbOK, 0);
	 return false;
   }
   return true;
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::AddCalibProgram(CALIBRATION& Calib)
{
   if (!Calib.Program.IsEmpty()) {
	 bool found = false;
	 for (int row=1; row<AdvColumnGrid9->RowCount; row++) {
	   if (Calib.Program == AdvColumnGrid9->Cells[0][row] &&
		   Calib.Version == AdvColumnGrid9->Cells[1][row]) {
		 found = true;
		 break;
		 }
	   }
	 if (!found) {
	   AdvColumnGrid9->RowCount++;
	   int row = AdvColumnGrid9->RowCount - 1;
	   AdvColumnGrid9->Cells[0][row] = Calib.Program;
	   AdvColumnGrid9->Cells[1][row] = Calib.Version;
	   AdvColumnGrid9->SortByColumn(1);
	   AdvColumnGrid9->SortByColumn(0);
	   }
	 }
}
//---------------------------------------------------------------------------

bool TTilSpreadSheetForm::ParseTLXLithology(void)
{
   UTF8String XPath;
   double dValue;
   int count;

   try
   {
   XPath = "/TiliaFile/";
   if (xmlin->ValidChild(XPath, "Lithology", count)) {
	 if (count == 0) return true;
	 XMLParsingStatus("Parsing Lithology metadata");
	 XMLSubElement LithologyUnit(XPath + "Lithology/LithologyUnit");
	 for (int i=1; i<=count; i++) {
	   xml_lithunit = new LITHOLOGYUNIT();
	   XPath = LithologyUnit.XPath(i);
	   if (xmlin->GetDoubleValue(XPath, "DepthTop", dValue))
		 xml_lithunit->DepthTop = dValue;
	   if (xmlin->GetDoubleValue(XPath, "DepthBottom", dValue))
		 xml_lithunit->DepthBottom = dValue;
	   xmlin->GetTextValue(XPath, "Description", xml_lithunit->UnitDescription);
	   xmlin->GetTextValue(XPath, "LowerBoundary", xml_lithunit->LowerBoundary);
	   LithologyUnitList->Add(xml_lithunit);
	   }
	 }
   }
   catch(Exception &e)
   {
	 MessageDlg("Error reading Lithology data. Class " + e.ClassName() + ". " + e.Message,
				mtWarning, TMsgDlgButtons() << mbOK, 0);
	 return false;
   }
   return true;
}
//---------------------------------------------------------------------------

bool TTilSpreadSheetForm::ParseTLXLOI(void)
{
   UTF8String XPath, XPath1, XPath2;
   UnicodeString Value;
   double dValue;
   int iValue, count, count1, ID;

   try
   {
   XPath = "/TiliaFile/";
   if (xmlin->ValidChild(XPath, "Loss-on-ignition", count)) {
	 if (count == 0) return true;
	 XMLParsingStatus("Parsing Loss-on-ignition data");
	 XPath += "Loss-on-ignition/";
	 xmlin->GetTextValue(XPath, "OrganicLOITemp", Value);
	 ComboBox7->Text = Value;
	 ExitLOITemp(ComboBox7, 3);
	 xmlin->GetTextValue(XPath, "CarbonateLOITemp", Value);
	 ComboBox8->Text = Value;
	 ExitLOITemp(ComboBox8, 5);

	 if (xmlin->ValidChild(XPath, "Investigators", count)) {
	   XMLSubElement Investigator(XPath + "Investigators/Contact");
	   for (int i=1; i<=count; i++) {
		 if (xmlin->GetAttrInt(Investigator.XPath(i), "ID", ID))
		   loi.Investigators.push_back(ContactList->Contacts[ID-1]);
		 }
	   }

	 if (xmlin->ValidChild(XPath, "Publications", count)) {
	   XMLSubElement Publication(XPath + "Publications/Publication");
	   for (int i=1; i<=count; i++) {
		 if (xmlin->GetAttrInt(Publication.XPath(i), "ID", ID))
		   loi.Publications.push_back((PUBLICATION*)Publications->Items[ID-1]);
		 }
	   }

	 if (xmlin->ValidChild(XPath, "Submissions", count)) {
	   XMLSubElement Submission(XPath + "Submissions/Submission");
	   for (int i=1; i<=count; i++) {
		 SUBMISSION submission;
		 XPath1 = Submission.XPath(i);
		 xmlin->GetBoolValue(XPath1, "Archived", submission.Archived);
		 xmlin->GetTextValue(XPath1, "SubmittedForm", submission.SubmittedForm);
		 xmlin->GetTextValue(XPath1, "SubmissionType", submission.SubmissionType);
		 if (xmlin->GetDoubleValue(XPath1, "SubmissionDate", dValue)) {
		   if (dValue > 0)
			 dValue = floor(dValue);
		   else if (dValue < 0)
			 dValue = ceil(dValue);
		   else if (xml_Version < VERSION(1,1,4))
			 dValue = NaN;
		   if (!IsNan(dValue))
			 submission.SubmissionDate = dValue;
		   }
		 xmlin->GetTextValue(XPath1, "SubmittersText", submission.SubmittersComboBoxText);
		 xmlin->GetTextValue(XPath1, "Notes", submission.Notes);

		 if (xmlin->ValidChild(XPath1, "Submitters", count1)) {
		   XMLSubElement Submitter(XPath1 + "/Submitters/Contact");
		   for (int i=1; i<=count1; i++) {
			 if (xmlin->GetAttrInt(Submitter.XPath(i), "ID", ID))
			   submission.Submitters.push_back(ContactList->Contacts[ID-1]);
			 }
		   }
		 loi.Submissions.push_back(submission);
		 }
	   }

	 if (xmlin->ValidChild(XPath, "LOISamples", count)) {
	   XMLSubElement LOISample(XPath + "LOISamples/LOISample");
	   for (int i=1; i<=count; i++) {
		 int TempOrg = -1;
		 int TempCarb = -1;
		 XPath1 = LOISample.XPath(i);
		 if (xmlin->GetDoubleValue(XPath1, "Depth", dValue)) {
		   AdvColumnGrid5->AllCells[1][i] = dValue;
		   }
		 if (xmlin->GetDoubleValue(XPath1, "Thickness", dValue)) {
		   AdvColumnGrid5->AllCells[2][i] = dValue;
		   }
		 if (xmlin->GetIntValue(XPath1, "TempOrganic", iValue)) {
		   TempOrg = iValue;
		   }
		 if (xmlin->GetDoubleValue(XPath1, "LOIOrganic", dValue)) {
		   if (TempOrg != -1)
			 AdvColumnGrid5->AllCells[3][i] = TempOrg;
		   AdvColumnGrid5->AllCells[4][i] = dValue;
		   }
		 if (xmlin->GetIntValue(XPath1, "TempCarbonate", iValue)) {
		   TempCarb = iValue;
		   }
		 if (xmlin->GetDoubleValue(XPath1, "LOICarbonate", dValue)) {
		   if (TempCarb != -1)
			 AdvColumnGrid5->AllCells[5][i] = TempCarb;
		   AdvColumnGrid5->AllCells[6][i] = dValue;
		   }
		 if (xmlin->GetDoubleValue(XPath1, "BulkDensity", dValue)) {
		   AdvColumnGrid5->AllCells[7][i] = dValue;
		   }
		 if (xmlin->GetDoubleValue(XPath1, "DateDnalyzed", dValue)) {
		   if (dValue > 0)
			 dValue = floor(dValue);
		   else if (dValue < 0)
			 dValue = ceil(dValue);
		   else if (xml_Version < VERSION(1,1,4))
			 dValue = NaN;
		   if (!IsNan(dValue)) {
			 TDateTime date = dValue;
			 AdvColumnGrid5->Dates[8][i] = date;
			 }
		   }
		 if (xml_Version >= VERSION(2,0,37)) {
		   if (xmlin->ValidChild(XPath1, "Analyst")) {
			 if (xmlin->GetAttrInt(XPath1+L"/Analyst", "ID", ID)) {
			   AdvColumnGrid5->AllObjects[9][i] = (TObject*)ContactList->Contacts[ID-1];
			   AdvColumnGrid5->AllCells[9][i] = ContactList->Contacts[ID-1]->ShortContactName;
			   }
			 }
		   }
		 }
	   }
	 }
   }
   catch(Exception &e)
   {
	 MessageDlg("Error reading Loss-on-ignition data. Class " + e.ClassName() + ". " + e.Message,
				mtWarning, TMsgDlgButtons() << mbOK, 0);
	 return false;
   }
   return true;
}
//---------------------------------------------------------------------------

bool TTilSpreadSheetForm::ParseTLXIsotopes(void)
{
   UTF8String XPath, XPath1, XPath2, XPath3;
   UnicodeString utext, guid;
   double dValue;
   int iValue, count, count1, row, srow, ID;

   try
   {
   XPath = "/TiliaFile/";
   if (xmlin->ValidChild(XPath, "IsotopeDataset")) {
	 XMLParsingStatus("Parsing isotope data");
	 XPath += L"IsotopeDataset/";
	 if (xmlin->ValidChild(XPath, "IsotopeMetadata", count)) {
	   XMLSubElement isoMetadata(XPath + L"IsotopeMetadata/Isotope");
	   for (int i=1; i<=count; i++) {
		 UnicodeString Element;
		 if (xmlin->GetAttrStr(isoMetadata.XPath(i), "type", Element)) {
		   ISOMETADATA Metadata;
		   XPath1 = isoMetadata.XPath(i);
		   if (xmlin->GetDoubleValue(XPath1, "TechError", dValue))
			 Metadata.TechError = dValue;
		   if (xmlin->GetDoubleValue(XPath1, "TechErrorSD", dValue))
			 Metadata.TechErrorSD = dValue;
		   if (xmlin->GetDoubleValue(XPath1, "LongTermError", dValue))
			 Metadata.LongTermError = dValue;
		   xmlin->GetTextValue(XPath1, "Instrument", Metadata.Instrument);
		   xmlin->GetTextValue(XPath1, "IntroSystem", Metadata.IntroSystem);
		   if (SameText(Element, L"Strontium")) {
			 if (xmlin->GetDoubleValue(XPath1, "SrLocalValue", dValue))
			   Metadata.SrLocalValue = dValue;
			 if (xmlin->GetDoubleValue(XPath1, "SrLocalValueSD", dValue))
			   Metadata.SrLocalValueSD = dValue;
			 xmlin->GetTextValue(XPath1, "SrLocalGeolContext", Metadata.SrLocalGeolContext);
			 }
		   xmlin->GetTextValue(XPath1, "Notes", Metadata.Notes);
		   if (xmlin->ValidChild(XPath1, "Standards", count1)) {
			 XMLSubElement isoStandards(XPath1 + L"/Standards/Standard");
			 for (int j=1; j<=count1; j++) {
			   XPath2 = isoStandards.XPath(j);
			   pair<UnicodeString,Variant> Standard(L"",Unassigned());
			   xmlin->GetTextValue(XPath2, "Name", Standard.first);
			   if (xmlin->GetDoubleValue(XPath2, "Value", dValue))
				 Standard.second = dValue;
			   Metadata.Standards.push_back(Standard);
			   }
			 }
		   if (!Metadata.IsEmpty()) {
			 short isotope;
			 if (SameText(Element, L"Carbon")) {
			   isotope = isoCarbon;
			   HTMLCheckBox1->Checked = true;
			   ToolButton17->Enabled = true;
			   ToolButton17->ImageIndex = 69;
			   }
			 else if (SameText(Element, L"Nitrogen")) {
			   isotope = isoNitrogen;
			   HTMLCheckBox2->Checked = true;
			   ToolButton19->Enabled = true;
			   ToolButton19->ImageIndex = 69;
			   }
			 else if (SameText(Element, L"Oxygen")) {
			   isotope = isoOxygen;
			   HTMLCheckBox3->Checked = true;
			   ToolButton21->Enabled = true;
			   ToolButton21->ImageIndex = 69;
			   }
			 else if (SameText(Element, L"Hydrogen")) {
			   isotope = isoHydrogen;
			   HTMLCheckBox5->Checked = true;
			   ToolButton25->Enabled = true;
			   ToolButton25->ImageIndex = 69;
			   }
			 else if (SameText(Element, L"Sulfur")) {
			   isotope = isoSulfur;
			   HTMLCheckBox4->Checked = true;
			   ToolButton23->Enabled = true;
			   ToolButton23->ImageIndex = 69;
			   }
			 else if (SameText(Element, L"Strontium")) {
			   isotope = isoStrontium;
			   HTMLCheckBox6->Checked = true;
			   ToolButton27->Enabled = true;
			   ToolButton27->ImageIndex = 69;
			   }
			 IsoMetadata[isotope] = Metadata;
			 AdvIsotopeStringGrid->UnHideColumns(IsoCols[isotope].first, IsoCols[isotope].second);
			 if (isotope == isoCarbon || isotope == isoNitrogen)
			   AdvIsotopeStringGrid->UnHideColumns(IsoCols[isoCNratio].first, IsoCols[isoCNratio].second);
			 if (isotope == isoOxygen || isotope == isoHydrogen)
			   AdvIsotopeStringGrid->UnHideColumns(IsoCols[isoOHratio].first, IsoCols[isoOHratio].second);
			 }
		   }
		 }
	   }

	 if (xmlin->ValidChild(XPath, "Specimens", count)) {
	   AdvIsotopeStringGrid->RowCount = count + 2;
	   XMLSubElement isoSpecimen(XPath + L"Specimens/Specimen");
	   for (int i=1; i<=count; i++) {
		 if (!xmlin->GetAttrInt(isoSpecimen.XPath(i), "row", row))
		   continue;
		 if (!xmlin->GetAttrInt(isoSpecimen.XPath(i), "ID", ID))
		   continue;
		 SPECIMEN* Specimen = GetSpecimen(ID);
		 if (Specimen != NULL)
		   AdvIsotopeStringGrid->Objects[0][row] = (TObject*)Specimen;
		 else
		   continue;
		 XPath1 = isoSpecimen.XPath(i);
		 xmlin->GetTextValue(XPath1, "AnalUnitDepth", utext);
		 AdvIsotopeStringGrid->Cells[1][row] = utext;
		 xmlin->GetTextValue(XPath1, "AnalUnitName", utext);
		 AdvIsotopeStringGrid->Cells[2][row] = utext;
		 xmlin->GetTextValue(XPath1, "Taxon", utext);
		 AdvIsotopeStringGrid->Cells[3][row] = utext;
		 xmlin->GetTextValue(XPath1, "Element", utext);
		 AdvIsotopeStringGrid->Cells[4][row] = utext;
		 xmlin->GetTextValue(XPath1, "SpecID", utext);
		 AdvIsotopeStringGrid->Cells[5][row] = utext;
		 xmlin->GetTextValue(XPath1, "SampleType", utext);
		 AdvIsotopeStringGrid->Cells[6][row] = utext;

		 if (SameText(utext, L"serial")) {
		   if (AdvIsotopeStringGrid->IsHiddenColumn(7)) {   // serial columns currently hidden
			 AdvIsotopeStringGrid->UnHideColumns(7,10);
			 AdvIsotopeStringGrid->MergeCells(6,0,5,1);     // merge fixed sample column header
			 }
		   if (xmlin->ValidChild(XPath1, "IsotopeSeries")) {
			 if (xmlin->GetAttrStr(XPath1+L"/IsotopeSeries", "ID", guid)) {
			   XPath2 = XPath1 + L"/IsotopeSeries/";
			   ISOTOPESERIES* IsoSer = new ISOTOPESERIES();
			   IsotopeSeries.push_back(IsoSer);
			   AdvIsotopeStringGrid->AllObjects[6][row] = (TObject*)IsoSer;
			   if (xmlin->GetIntValue(XPath2, L"Count", iValue)) {
				 IsoSer->NumberOfSamples = iValue;
				 AdvIsotopeStringGrid->RowCount += (iValue-1);
				 }
			   xmlin->GetTextValue(XPath2, L"Origin", utext);
			   IsoSer->SamplingOrigin = utext;
			   xmlin->GetTextValue(XPath2, L"Units", utext);
			   IsoSer->SampleDistUnits = utext;
			   if (xmlin->GetDoubleValue(XPath2, L"Interval", dValue))
				 IsoSer->SampleInterval = dValue;
			   if (xmlin->GetDoubleValue(XPath2, L"TransectWidth", dValue))
				 IsoSer->TransectWidth = dValue;
			   if (xmlin->GetDoubleValue(XPath2, L"DrillBitSize", dValue))
				 IsoSer->DrillBitSize = dValue;
			   xmlin->GetTextValue(XPath2, L"BiolMarker", utext);
			   IsoSer->SampledBiolMarker = utext;
			   if (xmlin->ValidChild(XPath2, L"IsotopeSeriesData", count1)) {
				 XMLSubElement isoSeries(XPath2 + L"IsotopeSeriesData/IsotopeSeriesAnalysisUnit");
				 for (int j=1; j<=count1; j++) {
				   XPath3 = isoSeries.XPath(j);
				   if (!xmlin->GetAttrInt(XPath3, "row", srow))
					 continue;
				   AdvIsotopeStringGrid->AllCells[7][srow] = guid;
				   if (xmlin->GetDoubleValue(XPath3, L"Distance", dValue))
					 AdvIsotopeStringGrid->AllCells[8][srow] = FloatToStr(dValue);
				   if (xmlin->GetDoubleValue(XPath3, L"Depth", dValue))
					 AdvIsotopeStringGrid->AllCells[9][srow] = FloatToStr(dValue);
				   xmlin->GetTextValue(XPath3, L"Band", utext);
				   AdvIsotopeStringGrid->AllCells[10][srow] = utext;
				   ParseTLXIsotopeData1(srow, XPath3);
				   }
				 }
			   for (int col=1; col<=6; col++)
				 AdvIsotopeStringGrid->MergeCells(col, row, 1, IsoSer->NumberOfSamples);
			   }
			 }
		   }
		 else
		   ParseTLXIsotopeData1(row, XPath1);
		 }
	   }
	 SetIsotopeHeaders();
	 }
   }
   catch(Exception &e)
   {
	 MessageDlg("Error reading isotope data. Class " + e.ClassName() + ". " + e.Message,
				mtWarning, TMsgDlgButtons() << mbOK, 0);
	 return false;
   }
   return true;
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::ParseTLXIsotopeData1(int row, UTF8String XPath)
{
   UTF8String XPath1;
   int count;
   UnicodeString Type;
   double dValue;

   if (xmlin->ValidChild(XPath, "IsotopeData", count)) {
	 XMLSubElement isoData(XPath + L"/IsotopeData/IsotopeMeasurement");
	 for (int j=1; j<=count; j++) {
	   if (!xmlin->GetAttrStr(isoData.XPath(j), "type", Type))
		 continue;
	   XPath1 = isoData.XPath(j);
	   if (SameText(Type, L"Carbon"))
		 ParseTLXIsotopeData2(row, isoCarbon, XPath1);
	   else if (SameText(Type, L"C:N")) {
		 if (xmlin->GetDoubleValue(XPath1, "Value", dValue))
		   AdvIsotopeStringGrid->AllCells[IsoCols[isoCNratio].first][row] = FloatToStr(dValue);
		 }
	   else if (SameText(Type, L"Nitrogen"))
		 ParseTLXIsotopeData2(row, isoNitrogen, XPath1);
	   else if (SameText(Type, L"Oxygen"))
		 ParseTLXIsotopeData2(row, isoOxygen, XPath1);
	   else if (SameText(Type, L"O:H")) {
		 if (xmlin->GetDoubleValue(XPath1, "Value", dValue))
		   AdvIsotopeStringGrid->AllCells[IsoCols[isoOHratio].first][row] = FloatToStr(dValue);
		 }
	   else if (SameText(Type, L"Hydrogen"))
		 ParseTLXIsotopeData2(row, isoHydrogen, XPath1);
	   else if (SameText(Type, L"Sulfur"))
		 ParseTLXIsotopeData2(row, isoSulfur, XPath1);
	   else if (SameText(Type, L"Strontium"))
		 ParseTLXIsotopeData2(row, isoStrontium, XPath1);
	   }
	 }
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::ParseTLXIsotopeData2(int row, short isotope, UTF8String XPath)
{
   UnicodeString utext, DisplayText;
   int count, iValue, ID;
   double dValue;
   UTF8String XPath1;

   int col = IsoCols[isotope].first;
   xmlin->GetTextValue(XPath, "MaterialAnalyzed", utext);
   AdvIsotopeStringGrid->AllCells[col++][row] = utext;
   xmlin->GetTextValue(XPath, "Substrate", utext);
   AdvIsotopeStringGrid->AllCells[col][row] = utext;
   col += 2;
   if (xmlin->ValidChild(XPath, "Analyst")) {
	 if (xmlin->GetAttrInt(XPath+L"/Analyst", "ID", ID)) {
	   AdvIsotopeStringGrid->AllObjects[col][row] = (TObject*)ContactList->Contacts[ID-1];
	   AdvIsotopeStringGrid->AllCells[col][row] = ContactList->Contacts[ID-1]->ShortContactName;
	   }
	 }
   col++;
   xmlin->GetTextValue(XPath, "Lab", utext);
   AdvIsotopeStringGrid->AllCells[col++][row] = utext;
   xmlin->GetTextValue(XPath, "LabNr", utext);
   AdvIsotopeStringGrid->AllCells[col++][row] = utext;
   if (xmlin->GetDoubleValue(XPath, "Mass", dValue))
	 AdvIsotopeStringGrid->AllCells[col][row] = FloatToStr(dValue);
   col++;
   if (xmlin->GetDoubleValue(XPath, "WeightPercent", dValue))
	 AdvIsotopeStringGrid->AllCells[col][row] = FloatToStr(dValue);
   col++;
   if (xmlin->GetDoubleValue(XPath, "AtomicPercent", dValue))
	 AdvIsotopeStringGrid->AllCells[col][row] = FloatToStr(dValue);
   col++;
   if (isotope == isoStrontium) {
	 if (xmlin->GetDoubleValue(XPath, "TotalSr", dValue))
	   AdvIsotopeStringGrid->AllCells[col][row] = FloatToStr(dValue);
	 col++;
	 }
   switch (isotope) {
	 case isoCarbon:
	   if (xmlin->GetDoubleValue(XPath, "del13C", dValue))
		 AdvIsotopeStringGrid->AllCells[col][row] = FloatToStr(dValue);
	   col++;
	   break;
	 case isoNitrogen:
	   if (xmlin->GetDoubleValue(XPath, "del15N", dValue))
		 AdvIsotopeStringGrid->AllCells[col][row] = FloatToStr(dValue);
	   col++;
	   break;
	 case isoOxygen:
	   if (xmlin->GetDoubleValue(XPath, "del18O", dValue))
		 AdvIsotopeStringGrid->AllCells[col][row] = FloatToStr(dValue);
	   col++;
	   break;
	 case isoHydrogen:
	   if (xmlin->GetDoubleValue(XPath, "delD", dValue))
		 AdvIsotopeStringGrid->AllCells[col][row] = FloatToStr(dValue);
	   col++;
	   break;
	 case isoSulfur:
	   if (xmlin->GetDoubleValue(XPath, "del34S", dValue))
		 AdvIsotopeStringGrid->AllCells[col][row] = FloatToStr(dValue);
	   col++;
	   break;
	 case isoStrontium:
	   if (xmlin->GetDoubleValue(XPath, "Sr87Sr86", dValue))
		 AdvIsotopeStringGrid->AllCells[col][row] = FloatToStr(dValue);
	   col++;
	   break;
	 }
   if (xmlin->GetDoubleValue(XPath, "SD", dValue))
	 AdvIsotopeStringGrid->AllCells[col][row] = FloatToStr(dValue);
   col++;
   if (isotope != isoStrontium) {
	 xmlin->GetTextValue(XPath, "Scale", utext);
	 AdvIsotopeStringGrid->AllCells[col++][row] = utext;
	 }
   if (xmlin->GetIntValue(XPath, "Reps", iValue))
	 AdvIsotopeStringGrid->AllCells[col][row] = IntToStr(iValue);
   if (xmlin->ValidChild(XPath, "Pretreatments", count)) {
	 XMLSubElement isoPretreatments(XPath + L"/Pretreatments/Pretreatment");
	 for (int i=1; i<=count; i++) {
	   XPath1 = isoPretreatments.XPath(i);
	   if (i > 1) DisplayText += L";";
	   if (xmlin->GetIntValue(XPath1, "Order", iValue))
		 DisplayText += IntToStr(iValue);
	   xmlin->GetTextValue(XPath1, "Treatment", utext);
	   DisplayText += (L",\"" + utext + "\"");
	   xmlin->GetTextValue(XPath1, "Qualifier", utext);
	   DisplayText += (L",\"" + utext + "\"");
	   if (xmlin->GetDoubleValue(XPath1, "Value", dValue))
		 DisplayText += (L"," + FloatToStr(dValue));
	   }
	 AdvIsotopeStringGrid->AllCells[IsoCols[isotope].first+2][row] = DisplayText;
	 }
}
//---------------------------------------------------------------------------

// parse .tlx file
void __fastcall TTilSpreadSheetForm::ipwXMLp2StartElement(TObject *Sender,
	  TipwXMLpStartElementEventParams *e)
{
   UnicodeString Element = e->Element;
   UnicodeString AttrValue;
   int id;
   SSMETADATAID ssContact;
   SSMETADATAID ssPub;
   SSMETADATAID ssSpecimen;

   ipwXMLp2->Config("CodePage=65001");
   tlx->XText.SetLength(0);

   //if (SameText(Element, L"TiliaFile"))  // root element, set CodePage to UTF-8
   //	 ipwXMLp2->Config("CodePage=65001");
   if (SameText(Element, L"Version"))
	 tlx->Version = true;
   else if (tlx->Version) {
	 if (SameText(Element, L"MajorVersion"))
	   tlx->MajorVersion = true;
	 else if (SameText(Element, L"MinorVersion"))
	   tlx->MinorVersion = true;
	 else if (SameText(Element, L"Release"))
	   tlx->Release = true;
	 }
   else if (xml_Version > VERSION(1,0,1)) {
	 if (SameText(Element, L"SpreadSheet")) {
	   int page = ipwXMLp2->Attr("page").ToInt();
	   if (xml_Version < VERSION(1,3,8)) {
		 switch (page) {
		   case 0:
			 xml_ProfGrid = ProfGrid1;
			 break;
		   case 1:
			 InsertPercentsSheet(false);
			 xml_ProfGrid = ProfGrid2;
			 break;
		   }
		 }
	   else {      // version >= 1.3.8
		 UnicodeString name = ipwXMLp2->Attr("name");
		 if (SameText(name, L"Data"))
		   xml_ProfGrid = ProfGrid1;
		 else if (SameText(name, L"Percents")) {
		   InsertPercentsSheet(false);
		   xml_ProfGrid = ProfGrid2;
		   }
		 else {
		   xml_ProfGrid = InsertNewWorksheet(name, 0, false);
		   if (SameText(name, L"CONISS"))
			 SS_InsertCONISSWorksheet->Enabled = false;
		   else if (SameText(name, L"Concentrations"))
			 ConcGrid = xml_ProfGrid;
		   else if (SameText(name, L"Influx"))
			 InfluxGrid = xml_ProfGrid;
		   }
		 CurrentRowHeight = xml_ProfGrid->DefaultRowHeight;
		 }
	   xml_ProfGrid->DisableControls();
	   xml_ProfGrid->SpreadsheetEnabled = false;
	   tlx->SpreadSheet = true;
	   }
	 else if (tlx->SpreadSheet) {
	   if (SameText(Element, L"Col")) {
		 ssc.col = ipwXMLp2->Attr("ID").ToInt();
		 XMLParsingStatus("Parsing Col: " + ColumnNameByIndex(ssc.col));
		 if (ssc.col >= xml_ProfGrid->ColCount)
		   xml_ProfGrid->ColCount += 256;
		 AttrValue = ipwXMLp2->Attr("Width");
		 if (!AttrValue.IsEmpty())
		   xml_ProfGrid->AbsoluteCols[ssc.col]->Width = AttrValue.ToInt();
		 tlx->Col = true;
		 }
	   else if (tlx->Col) {
		 if (SameText(Element, L"cell")) {
		   tlx->cell = true;
		   ssc.row = ipwXMLp2->Attr("row").ToInt();
		   if (xml_Version < VERSION(1,0,3)) {
			 if (ssc.row > 2)
			   ssc.row++;
			 }
		   if (xml_Version < VERSION(1,1,6)) {
			 if (ssc.row == 2)
			   tlxRow2 = true;
			 else if (ssc.row == 3)
			   tlxRow3 = true;
			 }
		   if (ssc.row >= xml_ProfGrid->RowCount)
			 xml_ProfGrid->RowCount += 1024;
		   if (ipwXMLp2->AttrCount > 1) {
			 AttrValue = ipwXMLp2->Attr("format");
			 if (!AttrValue.IsEmpty())
			   xml_ProfGrid->AbsoluteCells[ssc.col][ssc.row]->Format = AttrValue;
			 if (SameText(ipwXMLp2->Attr("rare"), "True"))
			   xml_ProfGrid->AbsoluteCells[ssc.col][ssc.row]->Font->Color = tiGlobals->RareColor;
			 }
		   }
		 else if (tlx->cell) {
		   tlx->TaxonNotesIcon = false;
		   if (tlx->Synonym) {
			 if (SameText(Element, L"TaxonName"))
			   tlx->TaxonName = true;
			 else if (SameText(Element, L"ContribName"))
			   tlx->ContribName = true;
			 else if (SameText(Element, L"publication")) {
			   if (TryStrToInt(ipwXMLp2->Attr("ID"), id)) {
				 //if (--id < Publications->Count)
				 //  tlx->Synonymy.Pub = (PUBLICATION*)Publications->Items[id];
				 tlx->Synonymy.PubID = id - 1;
				 }
			   }
			 else if (SameText(Element, L"SynonymNotes"))
			   tlx->SynonymNotes = true;
			 }
		   else if (tlx->Specimens && xml_Version == VERSION(2,0,42)) {
			 if (SameText(Element, L"Specimen")) {
			   tlx->Specimen = true;
			   xml_Specimen = new SPECIMEN();
			   xml_Specimen->Taxon = xml_ProfGrid->AbsoluteCells[2][ssc.row]->Text;
			   xml_Specimen->TaxaGroup = SpecimenTaxaGroup;
			   xml_Specimens->Add(xml_Specimen);
			   }
			 }
		   else if (SameText(Element, L"text"))
			 tlx->text = true;
		   else if (SameText(Element, L"value"))
			 tlx->value = true;
		   else if (SameText(Element, L"date"))
			 tlx->date = true;
		   else if (SameText(Element, L"formula"))
			 tlx->formula = true;
		   else if (SameText(Element, L"bool"))
			 tlx->boolval = true;
		   else if (SameText(Element, L"TaxonNotes"))
			 tlx->TaxonNotes = true;
		   else if (SameText(Element, L"originalID")) {  // depreciated
			 tlx->originalID = true;
			 tlx->Synonymy.Clear();
			 }
		   else if (SameText(Element, L"Synonym")) {
			 tlx->Synonym = true;
			 tlx->Synonymy.Clear();
			 }
		   else if (SameText(Element, L"Specimens") && xml_Version == VERSION(2,0,42)) {
			 tlx->Specimens = true;
			 SpecimenTaxaGroup = ipwXMLp2->Attr(L"TaxaGroup");
			 TProfGridCell* ACell = xml_ProfGrid->AbsoluteCells[ssc.col][ssc.row];
			 CELLOBJECT* CellObject;
			 if (ACell->CellObject == NULL) {
			   CellObject = new CELLOBJECT(CELLSPECIMENS);
			   AddCellObject(ACell, CellObject);
			   }
			 else {
			   CellObject = (CELLOBJECT*)ACell->CellObject;
			   }
			 xml_Specimens = (TList*)CellObject->Object;
			 }
		   else if (SameText(Element, L"Taphonomy")) {
			 if (xml_Version >= VERSION(2,0,9)) {
			   tlx->Taphonomy = true;
			   TProfGridCell* ACell = xml_ProfGrid->AbsoluteCells[ssc.col][ssc.row];
			   CELLOBJECT* CellObject;
			   if (ACell->CellObject == NULL) {
				 CellObject = new CELLOBJECT(CELLTAPHONOMY);
				 AddCellObject(ACell, CellObject);
				 xml_TaphSystems = (TAPHSYSTEMS*)CellObject->Object;
				 xml_TaphSystems->DatasetType = ipwXMLp2->Attr("DatasetType");
				 }
			   else {
				 CELLOBJECT* CellObject = (CELLOBJECT*)ACell->CellObject;
				 xml_TaphSystems = (TAPHSYSTEMS*)CellObject->Object;
				 }
			   TAPHSYSTEM TaphSystem;
			   TaphSystem.Name = ipwXMLp2->Attr("System");
			   xml_TaphSystems->Systems.push_back(TaphSystem);
			   if (TaphonomyLookup == NULL) {
				 TaphonomyLookup = new TAPHONOMYLOOKUP;
				 VarLookup->SetTaphonomyLookup(TaphonomyLookup);
				 }
			   }
			 else {
			   tlx->Taphonomy = true;
			   CELLOBJECT* CellObject = new CELLOBJECT(CELLTAPHONOMY);
			   xml_TaphSystems = (TAPHSYSTEMS*)CellObject->Object;
			   xml_TaphSystems->DatasetType = ipwXMLp2->Attr("DatasetType");
			   TAPHSYSTEM TaphSystem;
			   TaphSystem.Name = ipwXMLp2->Attr("System");
			   xml_TaphSystems->Systems.push_back(TaphSystem);
			   TProfGridCell* ACell = xml_ProfGrid->AbsoluteCells[ssc.col][ssc.row];
			   AddCellObject(ACell, CellObject);
			   if (TaphonomyLookup == NULL) {
				 TaphonomyLookup = new TAPHONOMYLOOKUP;
				 VarLookup->SetTaphonomyLookup(TaphonomyLookup);
				 }
			   }
			 }
		   else if (tlx->Taphonomy && SameText(Element, L"Type"))
			 tlx->TaphType = true;
		   else if (SameText(Element, L"contact")) {
			 if (TryStrToInt(ipwXMLp2->Attr("ID"), id)) {
			   id--;
			   ssContact.col = ssc.col;
			   ssContact.row = ssc.row;
			   ssContact.id = id;
			   SSContacts.push_back(ssContact);
			   }
			 }
		   else if (SameText(Element, L"publication")) {
			 if (TryStrToInt(ipwXMLp2->Attr("ID"), id)) {
			   id--;
			   ssPub.col = ssc.col;
			   ssPub.row = ssc.row;
			   ssPub.id = id;
			   SSPubs.push_back(ssPub);
			   }
			 }
		   else if (SameText(Element, L"specimen") && xml_Version >= VERSION(2,0,43)) {
			 if (TryStrToInt(ipwXMLp2->Attr("ID"), id)) {
			   ssSpecimen.col = ssc.col;
			   ssSpecimen.row = ssc.row;
			   ssSpecimen.id = id;
			   SSSpecimens.push_back(ssSpecimen);
			   }
			 }
		   }
		 }
	   }
	 }
   else if (xml_Version == VERSION(1,0,1)) {
	 if (SameText(Element, L"SpreadSheet")) {
	   xml_ProfGrid = ProfGrid1;
	   xml_ProfGrid->DisableControls();
	   xml_ProfGrid->SpreadsheetEnabled = false;
	   tlx->SpreadSheet = true;
	   }
	 else if (tlx->SpreadSheet) {
	   if (SameText(Element, L"cell")) {
		 tlx->cell = true;
		 int oldcol = ssc.col;
		 ssc.col = ipwXMLp2->AttrValue[0].ToInt();
		 ssc.row = ipwXMLp2->AttrValue[1].ToInt();
		 ssc.col = (ssc.col < 2) ? ssc.col+1 : ssc.col+5;
		 ssc.row++;
		 if (ssc.row > 2)
		   ssc.row++;
		 if (ssc.row >= xml_ProfGrid->RowCount)
		   xml_ProfGrid->RowCount += 1024;
		 if (ssc.col >= xml_ProfGrid->ColCount)
		   xml_ProfGrid->ColCount += 256;
		 if (ssc.col != oldcol)
		   XMLParsingStatus("Parsing Col: " + ColumnNameByIndex(ssc.col));
		 }
	   else if (tlx->cell) {
		 if (SameText(Element, L"text"))
		   tlx->text = true;
		 else if (SameText(Element, L"value"))
		   tlx->value = true;
		 else if (SameText(Element, L"date"))
		   tlx->date = true;
		 }
	   }
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::ipwXMLp2Characters(TObject *Sender,
	  TipwXMLpCharactersEventParams *e)
{
   UnicodeString ustr = e->Text.w_str();
   tlx->XText += ustr;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::ipwXMLp2EndElement(TObject *Sender,
	  TipwXMLpEndElementEventParams *e)
{
   UnicodeString Element = e->Element;

   WideString wstr;
   Variant Value;
   TAXON_NOTES *TaxonNotes;
   TAPHSYSTEMS* TaphSystems;
   TProfGridCell *ACell;
   bool taxon_notes_icon = false;

   if (SameText(Element, L"Version")) {
	 tlx->Version = false;
	 xml_Version.SetVersion(temp_Version.MajorVersion(),
							temp_Version.MinorVersion(),
							temp_Version.ReleaseNo());
	 CURRENTVERSION CurrentVersion;
	 if (xml_Version > CurrentVersion) {
	   UnicodeString msg = L"Input file version " + xml_Version.Version() +
		 L" is greater than current program version " + CurrentVersion.Version() +
		 L".\nFile may not read correctly, or some later features may be ignored." +
		 L"\nUpdate program to ensure correct reading of file.";
	   MessageDlg(msg , mtWarning, TMsgDlgButtons() << mbOK, 0);
	   }
	 }
   else if (tlx->Version) {
	 if (tlx->MajorVersion) {
	   tlx->MajorVersion = false;
	   int major = tlx->XText.ToInt();
	   temp_Version.SetMajor(major);
	   }
	 else if (tlx->MinorVersion) {
	   tlx->MinorVersion = false;
	   int minor = tlx->XText.ToInt();
	   temp_Version.SetMinor(minor);
	   }
	 else if (tlx->Release) {
	   tlx->Release = false;
	   int release = tlx->XText.ToInt();
	   temp_Version.SetRelease(release);
	   }
	 }
   else if (xml_Version > VERSION(1,0,1)) {
	 if (SameText(Element, L"SpreadSheet")) {
	   tlx->SpreadSheet = false;
	   xml_ProfGrid->SpreadsheetEnabled = true;
	   xml_ProfGrid->EnableControls();
	   }
	 else if (tlx->SpreadSheet) {
	   if (SameText(Element, L"Col")) {
		 tlx->Col = false;
		 tlx->TaxonNotesIcon = false;
		 }
	   else if (tlx->Col) {
		 if (SameText(Element, L"cell"))
		   tlx->cell = false;
		 else if (tlx->cell) {
		   ACell = xml_ProfGrid->AbsoluteCells[ssc.col][ssc.row];
		   if (tlx->text) {
			 tlx->text = false;
			 wstr = TranslateEntityRefs(tlx->XText);
			 if (ssc.col == 2) {
			   if (ssc.row == SampModernRow)
				 wstr = WideString("Sample Keywords");
			   else {
				 int bapos, eapos;
				 if ((bapos = wstr.Pos(L"{")) > 0) {
				   if ((eapos = wstr.Pos(L"}")) > 0) {
					 WideString author = wstr.SubString(bapos+1, eapos-bapos-1);
					 WideString name = wstr.SubString(1,bapos-1).TrimRight();
					 wstr = name + L" | " + author;
					 }
				   }
				 }
			   }
			 else if (ssc.col == 1 && xml_Version < VERSION(2,0,6)) {
			   UnicodeString Code = wstr;
			   if (SameText(Code, L"#Samp.Modern")) {
				 SampModernRow = ssc.row;
				 wstr = WideString("#Samp.Keywords");
				 }
			   }
			 ACell->Value = wstr;
			 }
		   else if (tlx->value) {
			 tlx->value = false;
			 ACell->Value = IntlStrToDouble::GetDouble(tlx->XText);
			 }
		   else if (tlx->date) {
			 tlx->date = false;
			 Value = IntlStrToDouble::GetDouble(tlx->XText);
			 ACell->Value = Value.AsType(varDate);
			 }
		   else if (tlx->formula) {
			 tlx->formula = false;
			 ACell->Formula = tlx->XText;
			 }
		   else if (tlx->boolval) {
			 tlx->boolval = false;
			 if (ssc.row == SampModernRow) {
			   if (tlx->XText == "1")
				 ACell->Value = WideString("modern");
			   }
			 else {
			   ACell->CheckBox = true;
			   ACell->CheckBoxChecked = (tlx->XText == "1");
			   }
			 }
		   else if (tlx->Specimen && xml_Version == VERSION(2,0,42)) {
			 if (SameText(Element, L"SpecimenID")) {
			   xml_Specimen->SpecimenID = tlx->XText.ToInt();
			   SpecimenIDs.insert(xml_Specimen->SpecimenID);
			   }
			 else if (SameText(Element, L"Element"))
			   xml_Specimen->Element = tlx->XText;
			 else if (SameText(Element, L"Symmetry"))
			   xml_Specimen->Symmetry = tlx->XText;
			 else if (SameText(Element, L"Portion"))
			   xml_Specimen->Portion = tlx->XText;
			 else if (SameText(Element, L"Maturity"))
			   xml_Specimen->Maturity = tlx->XText;
			 else if (SameText(Element, L"Sex"))
			   xml_Specimen->Sex = tlx->XText;
			 else if (SameText(Element, L"DomesticStatus"))
			   xml_Specimen->Sex = tlx->XText;
			 else if (SameText(Element, L"Preservative"))
			   xml_Specimen->Preservative = tlx->XText;
			 else if (SameText(Element, L"NISP"))
			   xml_Specimen->NISP = IntlStrToDouble::GetDouble(tlx->XText);
			 else if (SameText(Element, L"Repository"))
			   xml_Specimen->Repository = tlx->XText;
			 else if (SameText(Element, L"SpecNr"))
			   xml_Specimen->SpecNr = tlx->XText;
			 else if (SameText(Element, L"FieldNr"))
			   xml_Specimen->FieldNr = tlx->XText;
			 else if (SameText(Element, L"ArctosNr"))
			   xml_Specimen->ArctosNr = tlx->XText;
			 else if (SameText(Element, L"GenBankNr"))
			   xml_Specimen->GenBankNrs.insert(tlx->XText);
			 else if (SameText(Element, L"Notes"))
			   xml_Specimen->Notes = TranslateEntityRefs(tlx->XText);
			 else
			   tlx->Specimen = false;
			 }
		   else if (tlx->Specimens && xml_Version == VERSION(2,0,42)) {
			 tlx->Specimens = false;
			 ACell->Color = (TColor)RGB(255, 204, 204);
			 }
		   else if (tlx->TaphType) {
			 if (xml_Version >= VERSION(2,0,9)) {
			   tlx->TaphType = false;
			   UnicodeString Type = TranslateEntityRefs(tlx->XText);
			   vector<TAPHSYSTEM>::reverse_iterator ritr = xml_TaphSystems->Systems.rbegin();
			   ritr->Types.insert(Type);
			   TaphonomyLookup->Add(xml_TaphSystems->DatasetType, ritr->Name, Type);
			   }
			 else {
			   tlx->TaphType = false;
			   UnicodeString Type = TranslateEntityRefs(tlx->XText);
			   xml_TaphSystems->Systems[0].Types.insert(Type);
			   TaphonomyLookup->Add(TaphSystems->DatasetType, TaphSystems->Systems[0].Name, Type);
			   }
			 }
		   else if (tlx->Taphonomy)
			 tlx->Taphonomy = false;
		   else if (tlx->originalID) {
			 tlx->originalID = false;
			 wstr = TranslateEntityRefs(tlx->XText);
			 if (ssc.col == 2) {      // Taxa column
			   CELLOBJECT* CellObject;
			   if (ACell->CellObject)
				 //TaxonNotes = (TAXON_NOTES*)ACell->CellObject;
				 CellObject = (CELLOBJECT*)ACell->CellObject;
			   else {
				 //TaxonNotes = new TAXON_NOTES;
				 //CellObjects[(TObject*)TaxonNotes] = CELLTAXONNOTES;
				 //ACell->CellObject = (TObject*)TaxonNotes;
				 CellObject = new CELLOBJECT(CELLTAXONNOTES);
				 //CellObjects.push_back(CellObject);
				 //ACell->CellObject = (TObject*)CellObject;
                 AddCellObject(ACell, CellObject);
				 }
			   TaxonNotes = (TAXON_NOTES*)CellObject->Object;
			   tlx->Synonymy.TaxonName = wstr;
			   TaxonNotes->Synonymy.push_back(tlx->Synonymy);
			   taxon_notes_icon = true;
			   }
			 }
		   else if (tlx->Synonym) {
			 if (SameText(Element, L"Synonym")) {
			   tlx->Synonym = false;
			   if (ssc.col == 2) {      // Taxa column
				 CELLOBJECT* CellObject;
				 if (ACell->CellObject)
				   //TaxonNotes = (TAXON_NOTES*)ACell->CellObject;
				   CellObject = (CELLOBJECT*)ACell->CellObject;
				 else {
				   //TaxonNotes = new TAXON_NOTES;
				   //CellObjects[(TObject*)TaxonNotes] = CELLTAXONNOTES;
				   //ACell->CellObject = (TObject*)TaxonNotes;
				   CellObject = new CELLOBJECT(CELLTAXONNOTES);
				   //CellObjects.push_back(CellObject);
				   //ACell->CellObject = (TObject*)CellObject;
                   AddCellObject(ACell, CellObject);
				   }
				 TaxonNotes = (TAXON_NOTES*)CellObject->Object;
				 TaxonNotes->Synonymy.push_back(tlx->Synonymy);
				 taxon_notes_icon = true;
				 }
			   }
			 else if (tlx->TaxonName) {
			   tlx->TaxonName = false;
			   tlx->Synonymy.TaxonName = TranslateEntityRefs(tlx->XText);
			   }
			 else if (tlx->ContribName) {
			   tlx->ContribName = false;
			   tlx->Synonymy.Contrib = SameText(tlx->XText, L"True");
			   }
			 else if (tlx->SynonymNotes) {
			   tlx->SynonymNotes = false;
			   tlx->Synonymy.Notes = TranslateEntityRefs(tlx->XText);
			   }
			 }
		   else if (tlx->TaxonNotes) {
			 tlx->TaxonNotes = false;
			 wstr = TranslateEntityRefs(tlx->XText);
			 if (ssc.col == 2) {      // Taxa column
			   CELLOBJECT* CellObject;
			   if (ACell->CellObject)
				 //TaxonNotes = (TAXON_NOTES*)ACell->CellObject;
				 CellObject = (CELLOBJECT*)ACell->CellObject;
			   else {
				 //TaxonNotes = new TAXON_NOTES;
				 //CellObjects[(TObject*)TaxonNotes] = CELLTAXONNOTES;
				 //ACell->CellObject = (TObject*)TaxonNotes;
				 CellObject = new CELLOBJECT(CELLTAXONNOTES);
				 //CellObjects.push_back(CellObject);
				 //ACell->CellObject = (TObject*)CellObject;
                 AddCellObject(ACell, CellObject);
				 }
               TaxonNotes = (TAXON_NOTES*)CellObject->Object;
			   TaxonNotes->Notes = wstr;
			   taxon_notes_icon = true;
			   }
			 }
		   if (taxon_notes_icon && !tlx->TaxonNotesIcon) {
			 //AddTaxonNotesIcon(ssc.row);
			 AddTaxonNotesIcon(ACell);
			 tlx->TaxonNotesIcon = true;
			 }
		   }
		 }
	   }
	 }
   else if (xml_Version == VERSION(1,0,1)) {
     if (SameText(Element, L"SpreadSheet")) {
	   tlx->SpreadSheet = false;
	   xml_ProfGrid->SpreadsheetEnabled = true;
	   xml_ProfGrid->EnableControls();
	   }
	 else if (tlx->SpreadSheet) {
	   if (SameText(Element, L"cell"))
		 tlx->cell = false;
	   else if (tlx->cell) {
	     ACell = xml_ProfGrid->AbsoluteCells[ssc.col][ssc.row];
		 if (tlx->text) {
		   tlx->text = false;
		   wstr = TranslateEntityRefs(tlx->XText);
		   ACell->Value = wstr;
		   }
		 else if (tlx->value) {
		   tlx->value = false;
		   ACell->Value = IntlStrToDouble::GetDouble(tlx->XText);
		   }
		 else if (tlx->date) {
		   tlx->date = false;
		   Value = IntlStrToDouble::GetDouble(tlx->XText);
		   ACell->Value = Value.AsType(varDate);
		   }
		 }
	   }
	 }
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::BuildTaphonomy(void)
{
   UnicodeString DatasetType = LowerCase(Datasets[0].DatasetType);
   int RowCount = ContentRowCount(ProfGrid1);
   for (int row=3; row<=RowCount; row++) {
	 UnicodeString Code = ProfGrid1->AbsoluteCells[1][row]->Text;
	 if (SameText(Code, L"#Data.Type")) {
	   DatasetType = ProfGrid1->AbsoluteCells[2][row]->Text;
	   DatasetType = LowerCase(DatasetType);
	   }
	 else {
	   TProfGridCell* ACell = ProfGrid1->AbsoluteCells[6][row];
	   UnicodeString Text = VarToStr(ACell->Value);
	   if (!Text.IsEmpty()) {
		 if (ACell->CellObject == NULL) {  // data originally entered with no system
		   CELLOBJECT* CellObject = new CELLOBJECT(CELLTAPHONOMY);
		   TAPHSYSTEMS* TaphSystems = (TAPHSYSTEMS*)CellObject->Object;
		   TaphSystems->DatasetType = DatasetType;
		   TAPHSYSTEM TaphSystem;
		   TaphSystem.Name = L"none";
		   vector<UnicodeString> parts;
		   ParseParts(Text, L";", parts);
		   for (unsigned int i=0; i<parts.size(); i++)
			 TaphSystem.Types.insert(parts[i]);
		   TaphSystems->Systems.push_back(TaphSystem);
		   AddCellObject(ACell, CellObject);
		   }
		 if (TaphonomyLookup == NULL) {
		   TaphonomyLookup = new TAPHONOMYLOOKUP;
		   VarLookup->SetTaphonomyLookup(TaphonomyLookup);
		   }
		 CELLOBJECT* CellObject = (CELLOBJECT*)ACell->CellObject;
		 TAPHSYSTEMS* TaphSystems = (TAPHSYSTEMS*)CellObject->Object;
		 set<UnicodeString>::iterator itr;
		 for (unsigned int i=0; i<TaphSystems->Systems.size(); i++) {
		   for (itr = TaphSystems->Systems[i].Types.begin(); itr != TaphSystems->Systems[i].Types.end(); itr++)
			 TaphonomyLookup->Add(DatasetType, TaphSystems->Systems[i].Name, *itr);
		   }
         ACell->Value = TaphSystems->Text();
		 }
	   }
	 }
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::ProcessSSPubs(void)
{
   list<CELLOBJECT*>::iterator itr;
   for (itr=CellObjects.begin(); itr != CellObjects.end(); itr++ ) {
	 if ((*itr)->ObjectType == CELLTAXONNOTES) {
	   TAXON_NOTES* TaxonNotes = (TAXON_NOTES*)(*itr)->Object;
	   for (unsigned int i=0; i<TaxonNotes->Synonymy.size(); i++) {
		 if (TaxonNotes->Synonymy[i].PubID > -1)
		   TaxonNotes->Synonymy[i].Pub = (PUBLICATION*)Publications->Items[i];
		 }
	   }
	 }
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::SingleSiteCheck(void)
{
   if (Sites->Count == 2) {
	 SITE* SitePtr = (SITE*)Sites->Items[0];
	 if (SitePtr->SiteName.IsEmpty() &&
		 SitePtr->SiteDescription.IsEmpty() &&
		 SitePtr->LongEast.IsEmpty() &&
		 SitePtr->LongWest.IsEmpty() &&
		 SitePtr->LatNorth.IsEmpty() &&
		 SitePtr->LatSouth.IsEmpty() &&
		 SitePtr->Altitude.IsEmpty() &&
		 SitePtr->Area.IsEmpty() &&
		 SitePtr->Country.IsEmpty() &&
		 SitePtr->State.IsEmpty() &&
		 SitePtr->County.IsEmpty() &&
		 SitePtr->AdminUnit.IsEmpty() &&
		 SitePtr->Notes.IsEmpty())
	   {
		 Sites->Delete(0);
		 delete SitePtr;
		 int RowCount = AbsContentRowCount(ProfGrid1);
		 for (int row=RowCount; row>=3; row--) {
		   UnicodeString VarCode = ProfGrid1->AbsoluteCells[1][row]->Value;
		   if (SameText(VarCode.SubString(1,6), L"#Site."))
			 ProfGrid1->DeleteRow(row);
		   }
	   }
	 }
}
//---------------------------------------------------------------------------

