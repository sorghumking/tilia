#ifndef TIPubH
#define TIPubH
#include <vector>
#include <map>
#ifndef TIJSONH
#include "TIJSON.h"
#endif
#ifndef TIContacH
#include "TIContac.h"
#endif

// values >=100 are obsolete (version <2.0.3)
enum PUBTYPES { NOTSELECTED=-1, LEGACY=0, JOURNAL_ARTICLE=1, BOOK_CHAPTER=2,
				AUTHORED_BOOK=3, EDITED_BOOK=4, MASTERS_THESIS=5, DOCTORAL_THESIS=6,
				AUTHORED_REPORT=7, EDITED_REPORT=8, OTHER_AUTHORED=9, OTHER_EDITED=10,
				WEBSITE=11, UNDERGRAD_THESIS=12, JOURNAL=100, BOOKCHAPTER=101,
				BOOK=102, EDITEDBOOK=103, THESIS=104, REPORT=105, OTHER=106 };

//---------------------------------------------------------------------------
class PUBTYPEDEFS
{
public:
  map<int, UnicodeString> Def;
public:
  PUBTYPEDEFS() { Def[NOTSELECTED]      = L"not selected";
				  Def[LEGACY]           = L"legacy";
				  Def[JOURNAL_ARTICLE]  = L"journal article";
				  Def[BOOK_CHAPTER]     = L"book chapter";
				  Def[AUTHORED_BOOK]    = L"authored book";
				  Def[EDITED_BOOK]      = L"edited book";
				  Def[MASTERS_THESIS]   = L"master's thesis";
				  Def[DOCTORAL_THESIS]  = L"doctoral thesis";
				  Def[AUTHORED_REPORT]  = L"authored report";
				  Def[EDITED_REPORT]    = L"edited report";
				  Def[OTHER_AUTHORED]   = L"other authored";
				  Def[OTHER_EDITED]     = L"other edited";
				  Def[WEBSITE]          = L"website";
				  Def[UNDERGRAD_THESIS] = L"undergraduate thesis";
				  Def[JOURNAL]          = L"Journal";
				  Def[BOOKCHAPTER]      = L"Book chapter";
				  Def[BOOK]             = L"Book";
				  Def[EDITEDBOOK]       = L"Edited book";
				  Def[THESIS]           = L"Thesis";
				  Def[REPORT]           = L"Report";
				  Def[OTHER]            = L"Other";
				}
};
//---------------------------------------------------------------------------

class PUBAUTHOR
{
public:
  int ContactID;
  UnicodeString FamilyName;
  UnicodeString Initials;
  UnicodeString Suffix;
public:
  PUBAUTHOR() { ContactID = -1; };
  PUBAUTHOR(NTMAUTHOR& au) { ContactID = au.ContactID; FamilyName = au.FamilyName;
	Initials = au.Initials; Suffix = au.Suffix; }
  UnicodeString FormatAuthor(void)
	{
	  UnicodeString Citation = FamilyName + L", " + Initials;
	  if (!Suffix.IsEmpty())
		Citation += (L", " + Suffix);
	  return Citation;
	}
};
//---------------------------------------------------------------------------

class CONTACT;

class AUTHOR
{
public:
  CONTACT* contact;
  int NeotomaContactID;
  UnicodeString LastName;
  UnicodeString Initials;
  UnicodeString GivenNames;
  UnicodeString Suffix;
public:
  AUTHOR() { contact = NULL; NeotomaContactID = -1; };
  AUTHOR(PUBAUTHOR& pa)
	{ contact = NULL; NeotomaContactID = pa.ContactID; LastName = pa.FamilyName;
	  Initials = pa.Initials; Suffix = pa.Suffix; }
  UnicodeString CitationName(void);
  UnicodeString FormAuthor(void);
  void operator = (const AUTHOR& copy);
  bool operator == (const AUTHOR& compare );
};
//---------------------------------------------------------------------------

class EDITOR
{
public:
  UnicodeString LastName;
  UnicodeString Initials;
  UnicodeString Suffix;
public:
  EDITOR(UnicodeString);
  EDITOR() { };
  EDITOR(NTMEDITOR& ed) { LastName = ed.FamilyName; Initials = ed.Initials; Suffix = ed.Suffix; }
  EDITOR(NTMTRANSLATOR& trans) { LastName = trans.FamilyName; Initials = trans.Initials; Suffix = trans.Suffix; }
  UnicodeString FormatEditor(void);
  void operator = (const EDITOR& copy);
  bool operator == (const EDITOR& compare );
};
//---------------------------------------------------------------------------

class PUBLICATION
{
public:
  int pub_type;
  int NeotomaID;
  bool Primary;
  vector<AUTHOR> AuthorList;
  vector<EDITOR> EditorList;
  vector<EDITOR> TranslatorList;
  UnicodeString PublicationYear;
  UnicodeString Title;
  UnicodeString Journal;
  UnicodeString Volume;
  UnicodeString Issue;
  UnicodeString BookTitle;
  UnicodeString Edition;
  UnicodeString NumVolumes;
  UnicodeString VolumeTitle;
  UnicodeString SeriesTitle;
  UnicodeString SeriesNumber;
  UnicodeString OrigLang;
  UnicodeString Pages;
  UnicodeString DOI;
  UnicodeString CitationNumber;
  UnicodeString Publisher;
  UnicodeString URL;
  UnicodeString University;
  UnicodeString City;
  UnicodeString State;
  UnicodeString Country;
  UnicodeString Citation;
  UnicodeString Notes;
public:
  PUBLICATION(int);
  PUBLICATION() { NeotomaID = -1; Primary = false; };
  void operator = (const PUBLICATION& copy);
  UnicodeString GetShortCitation(bool parens);
  void DecodeThesisType(UnicodeString);
  void SetPublication(NTMPUBLICATION*, vector<PUBAUTHOR>&, vector<EDITOR>&, vector<EDITOR>&);
};
//---------------------------------------------------------------------------
#endif

