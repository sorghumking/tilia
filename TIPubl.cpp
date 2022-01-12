//---------------------------------------------------------------------------
#include "pch.h"
#include <vcl.h>
#include <set>
#pragma hdrstop

#include "TIPubl.h"
#ifndef TIUtilsH
#include "TIUtils.h"
#endif
#ifndef TIFndPubH
#include "TIFndPub.h"
#endif
#ifndef TIUpContactH
#include "TIUpContact.h"
#endif
#ifndef TNLoginH
#include "TNLogin.h"
#endif

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvGrid"
#pragma link "AdvObj"
#pragma link "BaseGrid"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxTextEdit"
#pragma link "cxMemo"
#pragma link "cxButtons"
#pragma link "cxGroupBox"
#pragma link "AdvGrid"
#pragma link "AdvObj"
#pragma link "BaseGrid"
#pragma link "cxButtons"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxGroupBox"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxMemo"
#pragma link "cxTextEdit"
#pragma link "AdvGrid"
#pragma link "AdvObj"
#pragma link "BaseGrid"
#pragma link "cxButtons"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxGroupBox"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxMemo"
#pragma link "cxTextEdit"
#pragma link "ipwjson"
#pragma link "ipshttps"
#pragma link "AdvDropDown"
#pragma link "AdvMultiColumnDropDown"
#pragma link "AdvCGrid"
#pragma link "frmctrllink"
#pragma link "dxSkinBlack"
#pragma link "dxSkinBlue"
#pragma link "dxSkinBlueprint"
#pragma link "dxSkinCaramel"
#pragma link "dxSkinCoffee"
#pragma link "dxSkinDarkRoom"
#pragma link "dxSkinDarkSide"
#pragma link "dxSkinDevExpressDarkStyle"
#pragma link "dxSkinDevExpressStyle"
#pragma link "dxSkinFoggy"
#pragma link "dxSkinGlassOceans"
#pragma link "dxSkinHighContrast"
#pragma link "dxSkiniMaginary"
#pragma link "dxSkinLilian"
#pragma link "dxSkinLiquidSky"
#pragma link "dxSkinLondonLiquidSky"
#pragma link "dxSkinMcSkin"
#pragma link "dxSkinMetropolis"
#pragma link "dxSkinMetropolisDark"
#pragma link "dxSkinMoneyTwins"
#pragma link "dxSkinOffice2007Black"
#pragma link "dxSkinOffice2007Blue"
#pragma link "dxSkinOffice2007Green"
#pragma link "dxSkinOffice2007Pink"
#pragma link "dxSkinOffice2007Silver"
#pragma link "dxSkinOffice2010Black"
#pragma link "dxSkinOffice2010Blue"
#pragma link "dxSkinOffice2010Silver"
#pragma link "dxSkinOffice2013DarkGray"
#pragma link "dxSkinOffice2013LightGray"
#pragma link "dxSkinOffice2013White"
#pragma link "dxSkinPumpkin"
#pragma link "dxSkinsCore"
#pragma link "dxSkinsDefaultPainters"
#pragma link "dxSkinSeven"
#pragma link "dxSkinSevenClassic"
#pragma link "dxSkinSharp"
#pragma link "dxSkinSharpPlus"
#pragma link "dxSkinSilver"
#pragma link "dxSkinSpringTime"
#pragma link "dxSkinStardust"
#pragma link "dxSkinSummer2008"
#pragma link "dxSkinTheAsphaltWorld"
#pragma link "dxSkinValentine"
#pragma link "dxSkinVS2010"
#pragma link "dxSkinWhiteprint"
#pragma link "dxSkinXmas2008Blue"
#pragma link "AdvUtil"
#pragma link "dxSkinOffice2016Colorful"
#pragma link "dxSkinOffice2016Dark"
#pragma link "dxSkinVisualStudio2013Blue"
#pragma link "dxSkinVisualStudio2013Dark"
#pragma link "dxSkinVisualStudio2013Light"
#pragma link "ipsjsons"
#pragma resource "*.dfm"
TPubForm *PubForm;
//---------------------------------------------------------------------------

UnicodeString AUTHOR::CitationName(void)
{
   UnicodeString Author = LastName;
   if (!Initials.IsEmpty())
     Author += (", " + Initials);
   if (!Suffix.IsEmpty())
     Author += (", " + Suffix);
   return Author;
}
//---------------------------------------------------------------------------

UnicodeString AUTHOR::FormAuthor(void)
{
   UnicodeString Author = LastName;
   if (!Initials.IsEmpty())
	 Author += (", " + Initials);
   if (!Suffix.IsEmpty())
	 Author += (", " + Suffix);
   return Author;
}
//---------------------------------------------------------------------------

void AUTHOR::operator = (const AUTHOR& copy)
{
   contact = copy.contact;
   NeotomaContactID = copy.NeotomaContactID;
   LastName = copy.LastName;
   Initials = copy.Initials;
   GivenNames = copy.GivenNames;
   Suffix = copy.Suffix;
}
//---------------------------------------------------------------------------

bool AUTHOR::operator == (const AUTHOR& compare)
{
   // return false if any of the variables are not equal
   if (this == &compare) return true;
   if (LastName != compare.LastName) return false;
   if (Initials != compare.Initials) return false;
   if (GivenNames != compare.GivenNames) return false;
   if (Suffix != compare.Suffix) return false;
   return true;
}
//---------------------------------------------------------------------------

EDITOR::EDITOR(UnicodeString Editor)
{
   int pos;

   if ((pos = Editor.Pos(",")) > 0) {
	 LastName = Editor.SubString(1, pos-1);
	 Editor.Delete(1, pos);
	 }
   else {
	 LastName = Editor;
	 Editor.SetLength(0);
	 }
   if ((pos = Editor.Pos(",")) > 0) {   // suffix exists
	 Initials = Editor.SubString(1, pos-1);
	 Editor.Delete(1, pos);
	 Suffix = Editor;
	 Suffix = Suffix.Trim();
	 }
   else
	 Initials = Editor;
   Initials = Initials.Trim();
}
//---------------------------------------------------------------------------

UnicodeString EDITOR::FormatEditor(void)
{
   UnicodeString Editor = LastName;
   if (!Initials.IsEmpty())
	 Editor += (", " + Initials);
   if (!Suffix.IsEmpty())
	 Editor += (", " + Suffix);
   return Editor;
}
//---------------------------------------------------------------------------

void EDITOR::operator = (const EDITOR& copy)
{
   LastName = copy.LastName;
   Initials = copy.Initials;
   Suffix = copy.Suffix;
}
//---------------------------------------------------------------------------

bool EDITOR::operator == (const EDITOR& compare)
{
   // return false if any of the variables are not equal
   if (this == &compare) return true;
   if (LastName != compare.LastName) return false;
   if (Initials != compare.Initials) return false;
   if (Suffix != compare.Suffix) return false;
   return true;
}
//---------------------------------------------------------------------------

PUBLICATION::PUBLICATION(int pt)
{
   pub_type = pt;
   NeotomaID = -1;
}
//---------------------------------------------------------------------------

void PUBLICATION::operator = (const PUBLICATION& copy)
{
   if (this == &copy) return;
   pub_type = copy.pub_type;

   AuthorList.clear();
   EditorList.clear();
   TranslatorList.clear();

   AuthorList.assign(copy.AuthorList.begin(), copy.AuthorList.end());
   EditorList.assign(copy.EditorList.begin(), copy.EditorList.end());
   TranslatorList.assign(copy.TranslatorList.begin(), copy.TranslatorList.end());

   NeotomaID = copy.NeotomaID;
   PublicationYear = copy.PublicationYear;
   Title = copy.Title;
   Journal = copy.Journal;
   Volume = copy.Volume;
   Issue = copy.Issue;
   BookTitle = copy.BookTitle;
   Edition = copy.Edition;
   NumVolumes = copy.NumVolumes;
   VolumeTitle = copy.VolumeTitle;
   SeriesTitle = copy.SeriesTitle;
   SeriesNumber = copy.SeriesNumber;
   OrigLang = copy.OrigLang;
   Pages = copy.Pages;
   DOI = copy.DOI;
   CitationNumber = copy.CitationNumber;
   Publisher = copy.Publisher;
   University = copy.University;
   URL = copy.URL;
   City = copy.City;
   State = copy.State;
   Country = copy.Country;
   Citation = copy.Citation;
   Notes = copy.Notes;
}
//---------------------------------------------------------------------------

void PUBLICATION::SetPublication(NTMPUBLICATION* ntm_pub, vector<PUBAUTHOR>& Authors,
	 vector<EDITOR>& Editors, vector<EDITOR>& Translators)
{
   //pub_type = VariantToInt(ntm_pub->PubTypeID, 106);
   NeotomaID = ntm_pub->PublicationID;
   pub_type = ntm_pub->PubTypeID;
   AuthorList.clear();
   for (unsigned int i=0; i<Authors.size(); i++) {
	 AUTHOR Author(Authors[i]);
	 AuthorList.push_back(Author);
	 }
   EditorList.clear();
   for (unsigned int i=0; i<Editors.size(); i++) {
	 EDITOR Editor(Editors[i]);
	 EditorList.push_back(Editor);
	 }
   TranslatorList.clear();
   for (unsigned int i=0; i<Translators.size(); i++) {
	 EDITOR Translator(Translators[i]);
	 TranslatorList.push_back(Translator);
	 }
   PublicationYear = ntm_pub->Year;
   Title = ntm_pub->ArticleTitle;
   Journal = ntm_pub->Journal;
   Volume = ntm_pub->Volume;
   Issue = ntm_pub->Issue;
   Pages = ntm_pub->Pages;
   CitationNumber = ntm_pub->CitationNumber;
   DOI = ntm_pub->DOI;
   BookTitle = ntm_pub->BookTitle;
   Edition = ntm_pub->Edition;
   NumVolumes = ntm_pub->NumVolumes;
   VolumeTitle = ntm_pub->VolumeTitle;
   SeriesTitle = ntm_pub->SeriesTitle;
   SeriesNumber = ntm_pub->SeriesVolume;
   switch (pub_type) {
	 case DOCTORAL_THESIS:
	 case MASTERS_THESIS:
	 case UNDERGRAD_THESIS:
	   University = ntm_pub->Publisher;
	   break;
	 default:
	   Publisher = ntm_pub->Publisher;
	   break;
	 }
   URL = ntm_pub->URL;
   City = ntm_pub->City;
   State = ntm_pub->State;
   Country = ntm_pub->Country;
   Citation = ntm_pub->Citation;
   OrigLang = ntm_pub->OriginalLanguage;
   Notes = ntm_pub->Notes;
}
//---------------------------------------------------------------------------

UnicodeString PUBLICATION::GetShortCitation(bool parens)
{
   AUTHOR *Author;
   UnicodeString short_citation;

   if (AuthorList.size() == 1)
	 short_citation = AuthorList[0].LastName;
   else if (AuthorList.size() == 2)
	 short_citation = AuthorList[0].LastName + L" and " + AuthorList[1].LastName;
   else if (AuthorList.size() > 2)
	 short_citation = AuthorList[0].LastName + L" et al.";

   if (!short_citation.IsEmpty()) {
	 if (parens)
	   short_citation += (L" (" + PublicationYear + L")");
	 else
	   short_citation += (L" " + PublicationYear);
	 }
   return short_citation;
}
//---------------------------------------------------------------------------

void PUBLICATION::DecodeThesisType(UnicodeString utext)
{
   utext = utext.LowerCase();
   if (utext.Pos(L"dissertation") > 0)
	 pub_type = DOCTORAL_THESIS;
   else if (utext.Pos(L"phd") > 0)
	 pub_type = DOCTORAL_THESIS;
   else if (utext.Pos(L"ph.d") > 0)
	 pub_type = DOCTORAL_THESIS;
   else if (utext.Pos(L"doctor") > 0)
	 pub_type = DOCTORAL_THESIS;
   else if (utext.Pos(L"master") > 0)
	 pub_type = MASTERS_THESIS;
   else if (utext.Pos(L"ms") > 0)
	 pub_type = MASTERS_THESIS;
   else if (utext.Pos(L"m.s") > 0)
	 pub_type = MASTERS_THESIS;
   else if (utext.Pos(L"ma") > 0)
	 pub_type = MASTERS_THESIS;
   else if (utext.Pos(L"m.a") > 0)
	 pub_type = MASTERS_THESIS;
   else if (utext.Pos(L"undergrad") > 0)
	 pub_type = UNDERGRAD_THESIS;
   else if (utext.Pos(L"senior thesis") > 0)
	 pub_type = UNDERGRAD_THESIS;
   else
     pub_type = DOCTORAL_THESIS;
}
//---------------------------------------------------------------------------

__fastcall TPubForm::TPubForm(PUBLICATION *p, TComponent* Owner)
		: TForm(Owner)
{
   pub = p;
   Activated = false;
   PubChanged = false;
   NeotomaPubSearched = false;
   AlwaysShowPubID = false;
   SetFlowPanel1Position();
}
//---------------------------------------------------------------------------

void __fastcall TPubForm::FormActivate(TObject *Sender)
{
   if (!Activated) {
	 FormatInputForm();
	 PopulateInputForm();
	 Activated = true;
	 }
}
//---------------------------------------------------------------------------

void TPubForm::SetFlowPanel1Position(void)
{
   int FlowPanelWidth = 2 + ((cxButton9->Visible) ? cxButton9->Width : 0)
						  + ((cxButton1->Visible) ? cxButton1->Width : 0)
						  + ((cxButton3->Visible) ? cxButton3->Width : 0);
   FlowPanel1->Left = (Panel7->Width-FlowPanelWidth)/2;
}
//---------------------------------------------------------------------------

void TPubForm::PopulateInputForm(void)
{
   if (AlwaysShowPubID) {
	 LabelNeotomaPubID->Visible =  true;
	 Panel10->Visible = true;
	 if (pub->NeotomaID > -1)
	   cxNeotomaPubIDEdit->Text = IntToStr(pub->NeotomaID);
	 else
       cxNeotomaPubIDEdit->Text = L"";
	 }
   else if (pub->NeotomaID > -1) {
	 LabelNeotomaPubID->Visible =  true;
	 Panel10->Visible = true;
	 cxNeotomaPubIDEdit->Text = IntToStr(pub->NeotomaID);
	 }
   else {
	 LabelNeotomaPubID->Visible =  false;
	 Panel10->Visible = false;
	 }

   SetNavigationButtons();
   switch (pub->pub_type)
   {
   case JOURNAL_ARTICLE:
	 cxButtonJournal->SpeedButtonOptions->Down = true;
	 FillAuthorFields();
	 cxYearEdit->Text = pub->PublicationYear;
	 cxTitleMemo->Text = pub->Title;
	 cxJournalNameEdit->Text = pub->Journal;
	 cxJournalVolumeEdit->Text = pub->Volume;
	 cxJournalIssueEdit->Text = pub->Issue;
	 cxPageEdit->Text = pub->Pages;
	 cxURLEdit->Text = pub->URL;
	 cxDOIEdit->Text = pub->DOI;
	 cxCitationNumber->Text = pub->CitationNumber;
	 cxNotesMemo->Text = pub->Notes;
	 FormatJournalCitation();
	 break;
   case BOOK_CHAPTER:
	 cxButtonBookChapter->SpeedButtonOptions->Down = true;
	 FillAuthorFields();
	 FillEditorFields();
	 cxYearEdit->Text = pub->PublicationYear;
	 cxTitleMemo->Text = pub->Title;
	 cxDOIEdit->Text = pub->DOI;
	 cxVolumeNumberEdit->Text = pub->Volume;
	 cxBookTitleMemo->Text = pub->BookTitle;
	 cxEditionEdit->Text = pub->Edition;
	 cxNumVolsEdit->Text = pub->NumVolumes;
	 cxVolumeTitleMemo->Text = pub->VolumeTitle;
	 cxSeriesTitleMemo->Text = pub->SeriesTitle;
	 cxSeriesVolumeEdit->Text = pub->SeriesNumber;
	 cxPageEdit->Text = pub->Pages;
	 cxPublisherEdit->Text = pub->Publisher;
	 cxCityEdit->Text = pub->City;
	 cxStateEdit->Text = pub->State;
	 cxCountryEdit->Text = pub->Country;
	 FillTranslatorFields();
	 cxOrigLangEdit->Text = pub->OrigLang;
	 cxNotesMemo->Text = pub->Notes;
	 FormatBookChapterCitation();
	 break;
   case AUTHORED_BOOK:
   case EDITED_BOOK:
	 cxButtonBook->SpeedButtonOptions->Down = true;
	 FillAuthorFields();
	 cxYearEdit->Text = pub->PublicationYear;
	 cxBookTitleMemo->Text = pub->BookTitle;
	 cxDOIEdit->Text = pub->DOI;
	 cxEditionEdit->Text = pub->Edition;
	 cxNumVolsEdit->Text = pub->NumVolumes;
	 cxVolumeNumberEdit->Text = pub->Volume;
	 cxVolumeTitleMemo->Text = pub->VolumeTitle;
	 cxSeriesTitleMemo->Text = pub->SeriesTitle;
	 cxSeriesVolumeEdit->Text = pub->SeriesNumber;
	 cxPublisherEdit->Text = pub->Publisher;
	 cxCityEdit->Text = pub->City;
	 cxStateEdit->Text = pub->State;
	 cxCountryEdit->Text = pub->Country;
	 FillTranslatorFields();
	 cxOrigLangEdit->Text = pub->OrigLang;
	 cxNotesMemo->Text = pub->Notes;
	 FormatBookCitation();
	 break;
   case AUTHORED_REPORT:
   case EDITED_REPORT:
	 cxButtonReport->SpeedButtonOptions->Down = true;
	 FillAuthorFields();
	 cxYearEdit->Text = pub->PublicationYear;
	 cxTitleMemo->Text = pub->Title;
	 cxDOIEdit->Text = pub->DOI;
	 cxSeriesTitleMemo->Text = pub->SeriesTitle;
	 cxSeriesVolumeEdit->Text = pub->SeriesNumber;
	 cxPublisherEdit->Text = pub->Publisher;
	 cxCityEdit->Text = pub->City;
	 cxStateEdit->Text = pub->State;
	 cxCountryEdit->Text = pub->Country;
	 cxNotesMemo->Text = pub->Notes;
	 FormatReportCitation();
	 break;
   case DOCTORAL_THESIS:
   case MASTERS_THESIS:
   case UNDERGRAD_THESIS:
	 cxButtonThesis->SpeedButtonOptions->Down = true;
	 FillAuthorFields();
	 cxYearEdit->Text = pub->PublicationYear;
	 cxTitleMemo->Text = pub->Title;
	 cxUniversityEdit->Text = pub->University;
	 cxCityEdit->Text = pub->City;
	 cxStateEdit->Text = pub->State;
	 cxCountryEdit->Text = pub->Country;
	 cxNotesMemo->Text = pub->Notes;
	 FormatThesisCitation();
	 break;
   case LEGACY:
	 cxButtonOther->SpeedButtonOptions->Down = true;
	 if (pub->PublicationYear.IsEmpty() && pub->AuthorList.size() == 0)
	   ParseCitation();
	 else {
	   bool AuthorsEmpty = true;
	   for (unsigned int i=0; i<pub->AuthorList.size(); i++) {
		 if (!pub->AuthorList[i].LastName.IsEmpty()) {
		   AuthorsEmpty = false;
		   break;
		   }
		 }
	   if (AuthorsEmpty)
		 ParseCitation();
	   }
	 FillAuthorFields();
	 cxYearEdit->Text = pub->PublicationYear;
	 cxTitleMemo->Text = pub->Title;
	 cxWorkSpaceMemo->Text = pub->Citation;
	 cxCitationMemo->Text = pub->Citation;
	 cxNotesMemo->Text = pub->Notes;
	 break;
   case OTHER_AUTHORED:
   case OTHER_EDITED:
	 cxButtonOther->SpeedButtonOptions->Down = true;
	 FillAuthorFields();
	 cxYearEdit->Text = pub->PublicationYear;
	 cxTitleMemo->Text = pub->Title;
	 cxNotesMemo->Text = pub->Notes;
	 FormatOtherCitation();
	 break;
   case WEBSITE:
	 cxButtonWebsite->SpeedButtonOptions->Down = true;
	 FillAuthorFields();
	 cxYearEdit->Text = pub->PublicationYear;
	 cxTitleMemo->Text = pub->Title;
	 cxURLEdit->Text = pub->URL;
	 cxNotesMemo->Text = pub->Notes;
	 FormatWebsiteCitation();
	 break;
   };

   if (cxButton3->Visible && pub->AuthorList.size() > 0)
	 cxButton3->Enabled = Panel10->Visible;
}
//---------------------------------------------------------------------------

void TPubForm::FillAuthorFields(void)
{
   AuthorsGrid->RowCount = pub->AuthorList.size();
   AuthorsGrid->Clear();
   for (unsigned int i=0; i<pub->AuthorList.size(); i++)
	 AuthorsGrid->Cells[0][i] = pub->AuthorList[i].FormAuthor();
   cxThesisAuthorEdit->Text = AuthorsGrid->Cells[0][0];
}
//---------------------------------------------------------------------------

void TPubForm::FillEditorFields(void)
{
   EditorsGrid->RowCount = pub->EditorList.size();
   EditorsGrid->Clear();
   for (unsigned int i=0; i<pub->EditorList.size(); i++)
	 EditorsGrid->Cells[0][i] = pub->EditorList[i].FormatEditor();
}
//---------------------------------------------------------------------------

void TPubForm::FillTranslatorFields(void)
{
   TranslatorGrid->RowCount = pub->TranslatorList.size();
   TranslatorGrid->Clear();
   for (unsigned int i=0; i<pub->TranslatorList.size(); i++)
	 TranslatorGrid->Cells[0][i] = pub->TranslatorList[i].FormatEditor();
}
//---------------------------------------------------------------------------

void TPubForm::ClearInputForm(void)
{
   AuthorsGrid->Clear();
   AuthorsGrid->RowCount = 1;
   EditorsGrid->Clear();
   EditorsGrid->RowCount = 1;
   TranslatorGrid->Clear();
   TranslatorGrid->RowCount = 1;
   cxNeotomaPubIDEdit->Text = L"";
   SetNavigationButtons();
   RadioButton1->Checked = false;
   RadioButton2->Checked = false;
   RadioButton3->Checked = false;
   RadioButton4->Checked = false;
   RadioButton5->Checked = false;
   cxThesisAuthorEdit->Text = L"";
   cxYearEdit->Text = L"";
   cxTitleMemo->Text = L"";
   cxJournalNameEdit->Text = L"";
   cxJournalVolumeEdit->Text = L"";
   cxJournalIssueEdit->Text = L"";
   cxPageEdit->Text = L"";
   cxCitationNumber->Text = L"";
   cxURLEdit->Text = L"";
   cxDOIEdit->Text = L"";
   cxBookTitleMemo->Text = L"";
   cxEditionEdit->Text = L"";
   cxNumVolsEdit->Text = L"";
   cxVolumeNumberEdit->Text = L"";
   cxVolumeTitleMemo->Text = L"";
   cxSeriesTitleMemo->Text = L"";
   cxSeriesVolumeEdit->Text = L"";
   cxPublisherEdit->Text = L"";
   cxUniversityEdit->Text = L"";
   cxCityEdit->Text = L"";
   cxStateEdit->Text = L"";
   cxCountryEdit->Text = L"";
   cxOrigLangEdit->Text = L"";
   cxNotesMemo->Text = L"";
   cxWorkSpaceMemo->Text = L"";
   cxCitationMemo->Text = L"";
}
//---------------------------------------------------------------------------

void TPubForm::FormatInputForm(void)
{
   switch (pub->pub_type) {
	 case JOURNAL_ARTICLE:
	   Panel1->Visible = false;   // radiobuttons
	   Panel2->Visible = false;
	   Panel3->Visible = false;
	   Panel4->Visible = false;
	   LabelAuthors->Visible = true;     // authors
	   PanelAuthors->Visible = true;
	   LabelThesisAuthor->Visible = false;     // thesis author
	   cxThesisAuthorEdit->Visible = false;
	   LabelTitle->Caption = L"Article Title: ";   // title
	   LabelTitle->Visible = true;
	   cxTitleMemo->Visible = true;
	   LabelJournal->Visible = true;          // journal
	   cxJournalNameEdit->Visible = true;
	   LabelJournalVolume->Visible = true;    // journal volume
	   cxJournalVolumeEdit->Visible = true;
	   LabelJournalIssue->Visible = true;     // journal issue
	   cxJournalIssueEdit->Visible = true;
	   LabelPages->Visible = true;    // pages
	   cxPageEdit->Visible = true;
	   LabelCitationNumber->Visible = true;      // citation number
	   cxCitationNumber->Visible = true;
	   LabelURL->Visible = true;       // URL
	   cxURLEdit->Visible = true;
	   LabelDOI->Visible = true;       // DOI
	   cxDOIEdit->Visible = true;
	   LabelEditors->Visible = false;     // editors
	   PanelEditors->Visible = false;
	   LabelBookTitle->Visible = false;   // book title
	   cxBookTitleMemo->Visible = false;
	   LabelEdition->Visible = false;     // edition
	   cxEditionEdit->Visible = false;
	   LabelNumVols->Visible = false;     // number of volumes
	   cxNumVolsEdit->Visible = false;
	   LabelVolumeNumber->Visible = false;  // volume number
	   cxVolumeNumberEdit->Visible = false;
	   LabelVolumeTitle->Visible = false;   // volumen title
	   cxVolumeTitleMemo->Visible = false;
	   LabelSeriesTitle->Visible = false;   // series title
	   cxSeriesTitleMemo->Visible = false;
	   LabelSeriesVolumeNumber->Visible = false;   // series volume
	   cxSeriesVolumeEdit->Visible = false;
	   LabelPublisher->Visible = false;    // publisher
	   cxPublisherEdit->Visible = false;
	   LabelUniversity->Visible = false;   // university
	   cxUniversityEdit->Visible = false;
	   LabelCity->Visible = false;    // city
	   cxCityEdit->Visible = false;
	   LabelState->Visible = false;   // state
	   cxStateEdit->Visible = false;
	   LabelCountry->Visible = false;  // country
	   cxCountryEdit->Visible = false;
	   LabelTranslator->Visible = false;  // translator
	   PanelTranslator->Visible = false;
	   LabelOrigLang->Visible = false;  // original language
	   cxOrigLangEdit->Visible = false;
	   break;
	 case BOOK_CHAPTER:
	   Panel1->Visible = false;   // radiobuttons
	   Panel2->Visible = false;
	   Panel3->Visible = false;
	   Panel4->Visible = false;
	   LabelAuthors->Visible = true;      // authors
	   PanelAuthors->Visible = true;
	   LabelThesisAuthor->Visible = false;   // thesis author
	   cxThesisAuthorEdit->Visible = false;
	   LabelTitle->Caption = L"Chapter Title: ";   // title
	   LabelTitle->Visible = true;
	   cxTitleMemo->Visible = true;
	   LabelJournal->Visible = false;          // journal
	   cxJournalNameEdit->Visible = false;
	   LabelJournalVolume->Visible = false;    // journal volume
	   cxJournalVolumeEdit->Visible = false;
	   LabelJournalIssue->Visible = false;     // journal issue
	   cxJournalIssueEdit->Visible = false;
	   LabelPages->Visible = true;    // pages
	   cxPageEdit->Visible = true;
	   LabelCitationNumber->Visible = false;      // citation number
	   cxCitationNumber->Visible = false;
	   LabelURL->Visible = false;       // URL
	   cxURLEdit->Visible = false;
	   LabelDOI->Visible = true;       // DOI
	   cxDOIEdit->Visible = true;
	   LabelEditors->Visible = true;        // editors
	   PanelEditors->Visible = true;
	   LabelBookTitle->Visible = true;      // book title
	   cxBookTitleMemo->Visible = true;
	   LabelEdition->Visible = true;     // edition
	   cxEditionEdit->Visible = true;
	   LabelNumVols->Visible = true;     // number of volumes
	   cxNumVolsEdit->Visible = true;
	   LabelVolumeNumber->Visible = true;  // volume number
	   cxVolumeNumberEdit->Visible = true;
	   LabelVolumeTitle->Visible = true;   // volume title
	   cxVolumeTitleMemo->Visible = true;
	   LabelSeriesTitle->Caption = L"Series Title: ";  // series title
	   LabelSeriesTitle->Visible = true;
	   cxSeriesTitleMemo->Visible = true;
	   LabelSeriesVolumeNumber->Caption = L"Series Volume Number: ";   // series volume
	   LabelSeriesVolumeNumber->Visible = true;
	   cxSeriesVolumeEdit->Visible = true;
	   LabelPublisher->Caption = L"Publisher: ";   // publisher
	   LabelPublisher->Visible = true;
	   cxPublisherEdit->Visible = true;
	   LabelUniversity->Visible = false;   // university
	   cxUniversityEdit->Visible = false;
	   LabelCity->Visible = true;    // city
	   cxCityEdit->Visible = true;
	   LabelState->Visible = true;   // state
	   cxStateEdit->Visible = true;
	   LabelCountry->Visible = true;  // country
	   cxCountryEdit->Visible = true;
	   LabelTranslator->Visible = true;  // translator
	   PanelTranslator->Visible = true;
	   LabelOrigLang->Visible = true;  // original language
	   cxOrigLangEdit->Visible = true;
	   break;
	 case AUTHORED_BOOK:
	 case EDITED_BOOK:
	   Panel1->Visible = true;   // radiobuttons
	   Panel2->Visible = true;
	   Panel3->Visible = false;
	   Panel4->Visible = false;
	   RadioButton1->Caption = L"Authored Book";
	   RadioButton2->Caption = L"Edited Book";
	   switch (pub->pub_type) {
		 case AUTHORED_BOOK:
		   RadioButton1->Checked = true;
		   LabelAuthors->Caption = L"Authors: ";
		   break;
		 case EDITED_BOOK:
		   RadioButton2->Checked = true;
           LabelAuthors->Caption = L"Editors: ";
		   break;
		 }
	   LabelAuthors->Visible = true;      // authors
	   PanelAuthors->Visible = true;
       LabelThesisAuthor->Visible = false;   // thesis author
	   cxThesisAuthorEdit->Visible = false;
	   LabelTitle->Visible = false;             // title
	   cxTitleMemo->Visible = false;
	   LabelJournal->Visible = false;          // journal
	   cxJournalNameEdit->Visible = false;
	   LabelJournalVolume->Visible = false;    // journal volume
	   cxJournalVolumeEdit->Visible = false;
	   LabelJournalIssue->Visible = false;     // journal issue
	   cxJournalIssueEdit->Visible = false;
	   LabelPages->Visible = false;    // pages
	   cxPageEdit->Visible = false;
	   LabelCitationNumber->Visible = false;      // citation number
	   cxCitationNumber->Visible = false;
	   LabelURL->Visible = false;       // URL
	   cxURLEdit->Visible = false;
	   LabelDOI->Visible = true;       // DOI
	   cxDOIEdit->Visible = true;
	   LabelEditors->Visible = false;        // editors
	   PanelEditors->Visible = false;
	   LabelBookTitle->Visible = true;      // book title
	   cxBookTitleMemo->Visible = true;
	   LabelEdition->Visible = true;     // edition
	   cxEditionEdit->Visible = true;
	   LabelNumVols->Visible = true;     // number of volumes
	   cxNumVolsEdit->Visible = true;
	   LabelVolumeNumber->Visible = true;  // volume number
	   cxVolumeNumberEdit->Visible = true;
	   LabelVolumeTitle->Visible = true;   // volume title
	   cxVolumeTitleMemo->Visible = true;
	   LabelSeriesTitle->Caption = L"Series Title: ";  // series title
	   LabelSeriesTitle->Visible = true;
	   cxSeriesTitleMemo->Visible = true;
	   LabelSeriesVolumeNumber->Caption = L"Series Volume Number: ";   // series volume
	   LabelSeriesVolumeNumber->Visible = true;
	   cxSeriesVolumeEdit->Visible = true;
	   LabelPublisher->Caption = L"Publisher ";   // publisher
	   LabelPublisher->Visible = true;
	   cxPublisherEdit->Visible = true;
	   LabelUniversity->Visible = false;   // university
	   cxUniversityEdit->Visible = false;
	   LabelCity->Visible = true;    // city
	   cxCityEdit->Visible = true;
	   LabelState->Visible = true;   // state
	   cxStateEdit->Visible = true;
	   LabelCountry->Visible = true;  // country
	   cxCountryEdit->Visible = true;
	   LabelTranslator->Visible = true;  // translator
	   PanelTranslator->Visible = true;
	   LabelOrigLang->Visible = true;  // original language
	   cxOrigLangEdit->Visible = true;
	   break;
	 case AUTHORED_REPORT:
	 case EDITED_REPORT:
	   Panel1->Visible = true;   // radiobuttons
	   Panel2->Visible = true;
	   Panel3->Visible = false;
	   Panel4->Visible = false;
	   RadioButton1->Caption = L"Authored Report";
	   RadioButton2->Caption = L"Edited Report";
	   switch (pub->pub_type) {
		 case AUTHORED_REPORT:
		   RadioButton1->Checked = true;
		   LabelAuthors->Caption = L"Authors: ";
		   break;
		 case EDITED_REPORT:
		   RadioButton2->Checked = true;
		   LabelAuthors->Caption = L"Editors: ";
		   break;
		 }
	   LabelAuthors->Visible = true;      // authors
	   PanelAuthors->Visible = true;
	   LabelThesisAuthor->Visible = false;   // thesis author
	   cxThesisAuthorEdit->Visible = false;
	   LabelTitle->Caption = L"Report Title: ";   // title
	   LabelTitle->Visible = true;
	   cxTitleMemo->Visible = true;
	   LabelJournal->Visible = false;          // journal
	   cxJournalNameEdit->Visible = false;
	   LabelJournalVolume->Visible = false;    // journal volume
	   cxJournalVolumeEdit->Visible = false;
	   LabelJournalIssue->Visible = false;     // journal issue
	   cxJournalIssueEdit->Visible = false;
	   LabelPages->Visible = false;    // pages
	   cxPageEdit->Visible = false;
	   LabelCitationNumber->Visible = false;      // citation number
	   cxCitationNumber->Visible = false;
	   LabelURL->Visible = false;       // URL
	   cxURLEdit->Visible = false;
	   LabelDOI->Visible = true;       // DOI
	   cxDOIEdit->Visible = true;
	   LabelEditors->Visible = false;        // editors
	   PanelEditors->Visible = false;
	   LabelBookTitle->Visible = false;      // book title
	   cxBookTitleMemo->Visible = false;
	   LabelEdition->Visible = false;     // edition
	   cxEditionEdit->Visible = false;
	   LabelNumVols->Visible = false;     // number of volumes
	   cxNumVolsEdit->Visible = false;
	   LabelVolumeNumber->Visible = false;  // volume number
	   cxVolumeNumberEdit->Visible = false;
	   LabelVolumeTitle->Visible = false;   // volume title
	   cxVolumeTitleMemo->Visible = false;
	   LabelSeriesTitle->Caption = L"Report Series: ";  // series title
	   LabelSeriesTitle->Visible = true;
	   cxSeriesTitleMemo->Visible = true;
	   LabelSeriesVolumeNumber->Caption = L"Report Number: ";   // series volume
	   LabelSeriesVolumeNumber->Visible = true;
	   cxSeriesVolumeEdit->Visible = true;
	   LabelPublisher->Caption = L"Institution/Agency: ";   // publisher
	   LabelPublisher->Visible = true;
	   cxPublisherEdit->Visible = true;
	   LabelUniversity->Visible = false;   // university
	   cxUniversityEdit->Visible = false;
	   LabelCity->Visible = true;    // city
	   cxCityEdit->Visible = true;
	   LabelState->Visible = true;   // state
	   cxStateEdit->Visible = true;
	   LabelCountry->Visible = true;  // country
	   cxCountryEdit->Visible = true;
	   LabelTranslator->Visible = false;  // translator
	   PanelTranslator->Visible = false;
	   LabelOrigLang->Visible = false;  // original language
	   cxOrigLangEdit->Visible = false;
	   break;
	 case DOCTORAL_THESIS:
	 case MASTERS_THESIS:
	 case UNDERGRAD_THESIS:
	   Panel1->Visible = false;   // radiobuttons
	   Panel2->Visible = false;
	   Panel3->Visible = true;
	   Panel4->Visible = true;
	   switch (pub->pub_type) {
		 case DOCTORAL_THESIS:
		   RadioButton3->Checked = true;
		   break;
		 case MASTERS_THESIS:
		   RadioButton4->Checked = true;
		   break;
		 case UNDERGRAD_THESIS:
		   RadioButton5->Checked = true;
		   break;
		 }
	   LabelAuthors->Visible = false;      // authors
	   PanelAuthors->Visible = false;
	   LabelThesisAuthor->Visible = true;   // thesis author
	   cxThesisAuthorEdit->Visible = true;
	   LabelTitle->Caption = L"Title: ";   // title
	   LabelTitle->Visible = true;
	   cxTitleMemo->Visible = true;
	   LabelJournal->Visible = false;          // journal
	   cxJournalNameEdit->Visible = false;
	   LabelJournalVolume->Visible = false;    // journal volume
	   cxJournalVolumeEdit->Visible = false;
	   LabelJournalIssue->Visible = false;     // journal issue
	   cxJournalIssueEdit->Visible = false;
	   LabelPages->Visible = false;    // pages
	   cxPageEdit->Visible = false;
	   LabelCitationNumber->Visible = false;      // citation number
	   cxCitationNumber->Visible = false;
	   LabelURL->Visible = false;       // URL
	   cxURLEdit->Visible = false;
	   LabelDOI->Visible = false;       // DOI
	   cxDOIEdit->Visible = false;
	   LabelEditors->Visible = false;        // editors
	   PanelEditors->Visible = false;
	   LabelBookTitle->Visible = false;      // book title
	   cxBookTitleMemo->Visible = false;
	   LabelEdition->Visible = false;     // edition
	   cxEditionEdit->Visible = false;
	   LabelNumVols->Visible = false;     // number of volumes
	   cxNumVolsEdit->Visible = false;
	   LabelVolumeNumber->Visible = false;  // volume number
	   cxVolumeNumberEdit->Visible = false;
	   LabelVolumeTitle->Visible = false;   // volume title
	   cxVolumeTitleMemo->Visible = false;
	   LabelSeriesTitle->Visible = false;   // series title
	   cxSeriesTitleMemo->Visible = false;
	   LabelSeriesVolumeNumber->Visible = false;   // series volume
	   cxSeriesVolumeEdit->Visible = false;
	   LabelPublisher->Visible = false;    // publisher
	   cxPublisherEdit->Visible = false;
	   LabelUniversity->Visible = true;   // university
	   cxUniversityEdit->Visible = true;
	   LabelCity->Visible = true;    // city
	   cxCityEdit->Visible = true;
	   LabelState->Visible = true;   // state
	   cxStateEdit->Visible = true;
	   LabelCountry->Visible = true;  // country
	   cxCountryEdit->Visible = true;
	   LabelTranslator->Visible = false;  // translator
	   PanelTranslator->Visible = false;
	   LabelOrigLang->Visible = false;  // original language
	   cxOrigLangEdit->Visible = false;
	   break;
	 case LEGACY:
	 case OTHER_AUTHORED:
	 case OTHER_EDITED:
	   Panel1->Visible = true;   // radiobuttons
	   Panel2->Visible = true;
	   Panel3->Visible = false;
	   Panel4->Visible = false;
	   RadioButton1->Caption = L"Authored Document";
	   RadioButton2->Caption = L"Edited Document";
	   switch (pub->pub_type) {
		 case LEGACY:
		   RadioButton1->Checked = false;
		   RadioButton2->Checked = false;
		   LabelAuthors->Caption = L"Authors: ";
		   break;
		 case OTHER_AUTHORED:
		   RadioButton1->Checked = true;
		   LabelAuthors->Caption = L"Authors: ";
		   break;
		 case OTHER_EDITED:
		   RadioButton2->Checked = true;
           LabelAuthors->Caption = L"Editors: ";
		   break;
		 }
	   LabelAuthors->Visible = true;      // authors
	   PanelAuthors->Visible = true;
	   LabelThesisAuthor->Visible = false;   // thesis author
	   cxThesisAuthorEdit->Visible = false;
	   LabelTitle->Caption = L"Document Title: ";   // title
	   LabelTitle->Visible = true;
	   cxTitleMemo->Visible = true;
	   LabelJournal->Visible = false;          // journal
	   cxJournalNameEdit->Visible = false;
	   LabelJournalVolume->Visible = false;    // journal volume
	   cxJournalVolumeEdit->Visible = false;
	   LabelJournalIssue->Visible = false;     // journal issue
	   cxJournalIssueEdit->Visible = false;
	   LabelPages->Visible = false;    // pages
	   cxPageEdit->Visible = false;
	   LabelCitationNumber->Visible = false;      // citation number
	   cxCitationNumber->Visible = false;
	   LabelURL->Visible = false;       // URL
	   cxURLEdit->Visible = false;
	   LabelDOI->Visible = true;       // DOI
	   cxDOIEdit->Visible = true;
	   LabelEditors->Visible = false;        // editors
	   PanelEditors->Visible = false;
	   LabelBookTitle->Visible = false;      // book title
	   cxBookTitleMemo->Visible = false;
	   LabelEdition->Visible = false;     // edition
	   cxEditionEdit->Visible = false;
	   LabelNumVols->Visible = false;     // number of volumes
	   cxNumVolsEdit->Visible = false;
	   LabelVolumeNumber->Visible = false;  // volume number
	   cxVolumeNumberEdit->Visible = false;
	   LabelVolumeTitle->Visible = false;   // volume title
	   cxVolumeTitleMemo->Visible = false;
	   LabelSeriesTitle->Visible = false;     // series title
	   cxSeriesTitleMemo->Visible = false;
	   LabelSeriesVolumeNumber->Visible = false;    // series volume
	   cxSeriesVolumeEdit->Visible = false;
	   LabelPublisher->Visible = false;        // publisher
	   cxPublisherEdit->Visible = false;
	   LabelUniversity->Visible = false;   // university
	   cxUniversityEdit->Visible = false;
	   LabelCity->Visible = false;    // city
	   cxCityEdit->Visible = false;
	   LabelState->Visible = false;   // state
	   cxStateEdit->Visible = false;
	   LabelCountry->Visible = false;  // country
	   cxCountryEdit->Visible = false;
	   LabelTranslator->Visible = false;  // translator
	   PanelTranslator->Visible = false;
	   LabelOrigLang->Visible = false;  // original language
	   cxOrigLangEdit->Visible = false;
	   break;
	 case WEBSITE:
	   Panel1->Visible = false;   // radiobuttons
	   Panel2->Visible = false;
	   Panel3->Visible = false;
	   Panel4->Visible = false;
	   LabelAuthors->Visible = true;     // authors
	   PanelAuthors->Visible = true;
	   LabelThesisAuthor->Visible = false;     // thesis author
	   cxThesisAuthorEdit->Visible = false;
	   LabelTitle->Caption = L"Website Title: ";   // title
	   LabelTitle->Visible = true;
	   cxTitleMemo->Visible = true;
	   LabelJournal->Visible = false;          // journal
	   cxJournalNameEdit->Visible = false;
	   LabelJournalVolume->Visible = false;    // journal volume
	   cxJournalVolumeEdit->Visible = false;
	   LabelJournalIssue->Visible = false;     // journal issue
	   cxJournalIssueEdit->Visible = false;
	   LabelPages->Visible = false;    // pages
	   cxPageEdit->Visible = false;
	   LabelCitationNumber->Visible = false;      // citation number
	   cxCitationNumber->Visible = false;
	   LabelURL->Visible = true;       // URL
	   cxURLEdit->Visible = true;
	   LabelDOI->Visible = false;       // DOI
	   cxDOIEdit->Visible = false;
	   LabelEditors->Visible = false;     // editors
	   PanelEditors->Visible = false;
	   LabelBookTitle->Visible = false;   // book title
	   cxBookTitleMemo->Visible = false;
	   LabelEdition->Visible = false;     // edition
	   cxEditionEdit->Visible = false;
	   LabelNumVols->Visible = false;     // number of volumes
	   cxNumVolsEdit->Visible = false;
	   LabelVolumeNumber->Visible = false;  // volume number
	   cxVolumeNumberEdit->Visible = false;
	   LabelVolumeTitle->Visible = false;   // volumen title
	   cxVolumeTitleMemo->Visible = false;
	   LabelSeriesTitle->Visible = false;   // series title
	   cxSeriesTitleMemo->Visible = false;
	   LabelSeriesVolumeNumber->Visible = false;   // series volume
	   cxSeriesVolumeEdit->Visible = false;
	   LabelPublisher->Visible = false;    // publisher
	   cxPublisherEdit->Visible = false;
	   LabelUniversity->Visible = false;   // university
	   cxUniversityEdit->Visible = false;
	   LabelCity->Visible = false;    // city
	   cxCityEdit->Visible = false;
	   LabelState->Visible = false;   // state
	   cxStateEdit->Visible = false;
	   LabelCountry->Visible = false;  // country
	   cxCountryEdit->Visible = false;
	   LabelTranslator->Visible = false;  // translator
	   PanelTranslator->Visible = false;
	   LabelOrigLang->Visible = false;  // original language
	   cxOrigLangEdit->Visible = false;
	   break;
	 }
   ScrollBox1->VertScrollBar->Range = Panel5->Top + Panel5->Height + 10;
}
//---------------------------------------------------------------------------

UnicodeString TPubForm::FormatJournalCitation(void)
{
   UnicodeString Citation;

   Citation = FormatAuthors(pub->AuthorList, 1);

   if (Citation.SubString(Citation.Length(), 1) != L".")
	 Citation += L".";
   if (!pub->PublicationYear.IsEmpty())
	 Citation += (L" " + pub->PublicationYear + L".");
   if (!pub->Title.IsEmpty())
	 Citation += (L" " + pub->Title);
   if (pub->Title.LastDelimiter(L".") < pub->Title.Length())
	 Citation += L".";
   if (!pub->Journal.IsEmpty()) {
	 Citation += (L" " + pub->Journal);
	 if (!pub->Volume.IsEmpty()) {
	   Citation += (L" " + pub->Volume);
	   if (!pub->Issue.IsEmpty())
		 Citation += (L"(" + pub->Issue + L")");
	   }
	 if (!pub->Pages.IsEmpty())
	   Citation += (L":" + pub->Pages);
	 else if (!pub->CitationNumber.IsEmpty())
	   Citation += (L":" + pub->CitationNumber);
	 Citation += L".";
	 }
   if (!pub->URL.IsEmpty()) {
	 Citation += (L" " + pub->URL);
     if (Citation.SubString(Citation.Length(), 1) != L".")
	   Citation += L".";
	 }
   if (!pub->DOI.IsEmpty())
	 Citation += (L" [DOI: " + pub->DOI + L"]");
   if (!pub->Notes.IsEmpty())
	 Citation += L" Notes: " + pub->Notes;
   cxCitationMemo->Text = Citation;
   return Citation;
}
//---------------------------------------------------------------------------

UnicodeString TPubForm::FormatBookChapterCitation(void)
{
   UnicodeString Citation;

   Citation = FormatAuthors(pub->AuthorList, 1);

   if (Citation.SubString(Citation.Length(), 1) != L".")
	 Citation += L".";
   if (!pub->PublicationYear.IsEmpty())
	 Citation += (L" " + pub->PublicationYear + L".");
   if (!pub->Title.IsEmpty()) {
	 Citation += (L" " + pub->Title);
	 if (Citation.SubString(Citation.Length(), 1) != L".")
	   Citation += L".";
	 }
   if (!pub->Pages.IsEmpty())
	 Citation += (L" Pages " + pub->Pages + L" in ");

   if (pub->EditorList.size() > 0) {
	 Citation += FormatEditors(pub->EditorList);
	 if (pub->EditorList.size() == 1)
	   Citation += L", editor.";
	 else
	   Citation += L", editors.";
	 if (!pub->BookTitle.IsEmpty())
	   Citation += L" ";
	 }

   Citation += pub->BookTitle;

   if (pub->Edition.IsEmpty()) {
	 if (Citation.SubString(Citation.Length(), 1) != L".")
	   Citation += L".";
	 }
   else
	 Citation += (L", " + pub->Edition + L" edition.");
   if (!pub->NumVolumes.IsEmpty())
	 Citation += L" " + pub->NumVolumes + L" volumes.";

   if (!pub->Volume.IsEmpty())
	 Citation += (L" Volume " + pub->Volume + L".");
   if (!pub->VolumeTitle.IsEmpty())
	 Citation += (L" " + pub->VolumeTitle + L".");
   if (!pub->SeriesTitle.IsEmpty()) {
	 Citation += (L" " + pub->SeriesTitle);
	 if (!pub->SeriesNumber.IsEmpty())
	   Citation += (L" " + pub->SeriesNumber);
	 Citation += L".";
	 }
   if (!pub->Publisher.IsEmpty())
	 Citation += (L" " + pub->Publisher);
   if (!pub->City.IsEmpty()) {
	 if (!pub->Publisher.IsEmpty())
	   Citation += L",";
	 Citation += (L" " + pub->City);
	 }
   if (!pub->State.IsEmpty()) {
	 if (!pub->City.IsEmpty() || !pub->Publisher.IsEmpty())
	   Citation += L",";
	 Citation += (L" " + pub->State);
	 }
   if (!pub->Country.IsEmpty()) {
	 if (!pub->State.IsEmpty() ||
		 !pub->City.IsEmpty() ||
		 !pub->Publisher.IsEmpty())
	   Citation += L",";
	 Citation += (L" " + pub->Country);
	 }
   if (Citation.SubString(Citation.Length(), 1) != L".")
	 Citation += L".";

   UnicodeString Translator = FormatEditors(pub->TranslatorList);
   if (!pub->OrigLang.IsEmpty()) {
	 Citation += (L" Translated from " + pub->OrigLang);
	 if (!Translator.IsEmpty())
	  Citation += (L" by " + Translator);
	 Citation += L".";
	 }
   else if (!Translator.IsEmpty())
	 Citation += (L" Translated by " + Translator + L".");

   if (!pub->DOI.IsEmpty())
	 Citation += (L" [DOI: " + pub->DOI + L"]");

   if (!pub->Notes.IsEmpty())
	 Citation += L" Notes: " + pub->Notes;
   cxCitationMemo->Text = Citation;
   return Citation;
}
//---------------------------------------------------------------------------

UnicodeString TPubForm::FormatBookCitation(void)
{
   UnicodeString Citation;

   Citation = FormatAuthors(pub->AuthorList, 1);

   if (pub->pub_type == AUTHORED_BOOK) {
	 if (Citation.SubString(Citation.Length(), 1) != L".")
	   Citation += L".";
	 }
   else {
	 if (pub->AuthorList.size() == 1)
	   Citation += L", editor.";
	 else
	   Citation += L", editors.";
	 }

   if (!pub->PublicationYear.IsEmpty())
	 Citation += (L" " + pub->PublicationYear + L".");
   if (!pub->BookTitle.IsEmpty())
	 Citation += (L" " + pub->BookTitle);

   if (pub->Edition.IsEmpty()) {
	 if (Citation.SubString(Citation.Length(), 1) != L".")
	   Citation += L".";
	 }
   else
	 Citation += (L", " + pub->Edition + L" edition.");
   if (!pub->NumVolumes.IsEmpty())
	 Citation += L" " + pub->NumVolumes + L" volumes.";

   if (!pub->Volume.IsEmpty())
	 Citation += (L" Volume " + pub->Volume + L".");
   if (!pub->VolumeTitle.IsEmpty())
	 Citation += (L" " + pub->VolumeTitle + L".");
   if (!pub->SeriesTitle.IsEmpty()) {
	 Citation += (L" " + pub->SeriesTitle);
	 if (!pub->SeriesNumber.IsEmpty())
	   Citation += (L" " + pub->SeriesNumber);
	 Citation += L".";
	 }
   if (!pub->Publisher.IsEmpty())
	 Citation += (L" " + pub->Publisher);
   if (!pub->City.IsEmpty()) {
	 if (!pub->Publisher.IsEmpty())
	   Citation += L",";
	 Citation += (L" " + pub->City);
	 }
   if (!pub->State.IsEmpty()) {
	 if (!pub->City.IsEmpty() || !pub->Publisher.IsEmpty())
	   Citation += L",";
	 Citation += (L" " + pub->State);
	 }
   if (!pub->Country.IsEmpty()) {
	 if (!pub->State.IsEmpty() ||
		 !pub->City.IsEmpty() ||
		 !pub->Publisher.IsEmpty())
	   Citation += L",";
	 Citation += (L" " + pub->Country);
	 }
   if (Citation.SubString(Citation.Length(), 1) != L".")
	 Citation += L".";

   UnicodeString Translator = FormatEditors(pub->TranslatorList);
   if (!pub->OrigLang.IsEmpty()) {
	 Citation += (L" Translated from " + pub->OrigLang);
	 if (!Translator.IsEmpty())
	  Citation += (L" by " + Translator);
	 Citation += L".";
	 }
   else if (!Translator.IsEmpty())
	 Citation += (L" Translated by " + Translator + L".");

   if (!pub->DOI.IsEmpty())
	 Citation += (L" [DOI: " + pub->DOI + L"]");

   if (!pub->Notes.IsEmpty())
	 Citation += L" Notes: " + pub->Notes;
   cxCitationMemo->Text = Citation;
   return Citation;
}
//---------------------------------------------------------------------------

UnicodeString TPubForm::FormatThesisCitation(void)
{
   UnicodeString Citation;

   Citation = FormatAuthors(pub->AuthorList, 1);

   if (Citation.SubString(Citation.Length(), 1) != ".")
     Citation += ".";
   if (!pub->PublicationYear.IsEmpty())
     Citation += (" " + pub->PublicationYear + ".");
   if (!pub->Title.IsEmpty())
     Citation += (" " + pub->Title + ".");

   switch (pub->pub_type) {
	 case DOCTORAL_THESIS:
	   Citation += L" Doctoral dissertation.";
	   break;
	 case MASTERS_THESIS:
	   Citation += L" Master's thesis.";
	   break;
	 case UNDERGRAD_THESIS:
	   Citation += L" Undergraduate thesis.";
	   break;
	 }

   if (!pub->University.IsEmpty())
	 Citation += (" " + pub->University);

   if (!pub->City.IsEmpty()) {
	 if (!pub->University.IsEmpty())
       Citation += ",";
     Citation += (" " + pub->City);
     }
   if (!pub->State.IsEmpty()) {
     if (!pub->City.IsEmpty() || !pub->University.IsEmpty())
       Citation += ",";
     Citation += (" " + pub->State);
     }
   if (!pub->Country.IsEmpty()) {
     if (!pub->State.IsEmpty() ||
         !pub->City.IsEmpty() ||
         !pub->University.IsEmpty())
       Citation += ",";
     Citation += (" " + pub->Country);
     }
   if (Citation.SubString(Citation.Length(), 1) != ".")
     Citation += ".";
   if (!pub->Notes.IsEmpty())
	 Citation += L" Notes: " + pub->Notes;
   cxCitationMemo->Text = Citation;
   return Citation;
}
//---------------------------------------------------------------------------

UnicodeString TPubForm::FormatReportCitation(void)
{
   UnicodeString Citation;

   Citation = FormatAuthors(pub->AuthorList, 1);

   if (pub->pub_type == AUTHORED_REPORT) {
	 if (Citation.SubString(Citation.Length(), 1) != L".")
	   Citation += L".";
	 }
   else {
	 if (pub->AuthorList.size() == 1)
	   Citation += L", editor.";
	 else
	   Citation += L", editors.";
	 }

   if (Citation.SubString(Citation.Length(), 1) != ".")
	 Citation += ".";
   if (!pub->PublicationYear.IsEmpty())
	 Citation += (" " + pub->PublicationYear + ".");
   if (!pub->Title.IsEmpty())
	 Citation += (" " + pub->Title + ".");
   if (!pub->SeriesTitle.IsEmpty())
	 Citation += (" " + pub->SeriesTitle);
   if (!pub->SeriesNumber.IsEmpty())
	 Citation += (" " + pub->SeriesNumber);
   if (!pub->Publisher.IsEmpty()) {
     if (!pub->SeriesNumber.IsEmpty() || !pub->SeriesTitle.IsEmpty())
       Citation += ",";
     Citation += (" " + pub->Publisher);
     }
   if (!pub->City.IsEmpty()) {
     if (!pub->SeriesNumber.IsEmpty() ||
         !pub->Publisher.IsEmpty())
       Citation += ",";
     Citation += (" " + pub->City);
     }
   if (!pub->State.IsEmpty()) {
     if (!pub->City.IsEmpty() ||
         !pub->Publisher.IsEmpty() ||
         !pub->SeriesNumber.IsEmpty())
	   Citation += ",";
	 Citation += (" " + pub->State);
     }
   if (!pub->Country.IsEmpty()) {
     if (!pub->State.IsEmpty() ||
         !pub->City.IsEmpty() ||
         !pub->Publisher.IsEmpty() ||
         !pub->SeriesNumber.IsEmpty())
       Citation += ",";
     Citation += (" " + pub->Country);
     }
   if (Citation.SubString(Citation.Length(), 1) != ".")
	 Citation += ".";

   if (!pub->DOI.IsEmpty())
	 Citation += (L" [DOI: " + pub->DOI + L"]");
   if (!pub->Notes.IsEmpty())
	 Citation += L" Notes: " + pub->Notes;
   cxCitationMemo->Text = Citation;
   return Citation;
}
//---------------------------------------------------------------------------

UnicodeString TPubForm::FormatOtherCitation(void)
{
   UnicodeString Citation;

   Citation = FormatAuthors(pub->AuthorList, 1);

   if (!Citation.IsEmpty()) {
	 if (Citation.SubString(Citation.Length(), 1) != L".")
	   Citation += L".";
	 }
   if (!pub->PublicationYear.IsEmpty())
	 Citation += (L" " + pub->PublicationYear + L".");
   if (!pub->Title.IsEmpty())
	 Citation += (L" " + pub->Title + L".");
   if (Citation.SubString(Citation.Length(), 1) != L".")
	 Citation += L".";
   Citation.TrimLeft();
   if (!pub->DOI.IsEmpty())
	 Citation += (L" [DOI: " + pub->DOI + L"]");
   if (!pub->Notes.IsEmpty())
	 Citation += L" Notes: " + pub->Notes;
   cxCitationMemo->Text = Citation;
   return Citation;
}
//---------------------------------------------------------------------------

UnicodeString TPubForm::FormatWebsiteCitation(void)
{
   UnicodeString Citation;

   if (pub->AuthorList.size() > 0) {
	 Citation = FormatAuthors(pub->AuthorList, 1);
	 if (!Citation.IsEmpty()) {
	   if (Citation[Citation.Length()] != L'.')
		 Citation += L".";
	   }
	 if (!pub->PublicationYear.IsEmpty()) {
	   if (!Citation.IsEmpty())
		 Citation += L" ";
	   Citation += (pub->PublicationYear + L".");
	   }
	 if (!pub->Title.IsEmpty()) {
	   if (!Citation.IsEmpty())
		 Citation += L" ";
	   Citation += (pub->Title + L".");
	   }
	 if (Citation[Citation.Length()] != L'.')
	   Citation += L".";
	 }
   else {
	 if (!pub->Title.IsEmpty())
	   Citation = (pub->Title + L".");
     if (!pub->PublicationYear.IsEmpty()) {
	   if (!Citation.IsEmpty())
		 Citation += L" ";
	   Citation += (pub->PublicationYear + L".");
	   }
	 }

   if (!pub->URL.IsEmpty()) {
     if (!Citation.IsEmpty())
	   Citation += L" ";
	 Citation += pub->URL;
	 }
   if (Citation.SubString(Citation.Length(), 1) != L".")
	 Citation += L".";
   if (!pub->Notes.IsEmpty())
	 Citation += L" Notes: " + pub->Notes;
   cxCitationMemo->Text = Citation;
   return Citation;
}
//---------------------------------------------------------------------------

UnicodeString TPubForm::FormatAuthors(vector<AUTHOR>& AuthorList, int style)
{
   // formats a string of authors for the citation from the lines in a TMemo
   // style 1: Smith, E.B., A.B. Jones, and E.C. Wilson
   // style 2: E.B. Smith, A.B. Jones, and E.C. Wilson

   //UnicodeString Author;
   UnicodeString Citation;

   for (unsigned int i=0; i<AuthorList.size(); i++) {
	 if (style == 1 && i == 0) {
	   //Citation = AuthorList[i].LastName + ", " + AuthorList[i].Initials;
	   Citation = AuthorList[i].LastName;
	   if (!AuthorList[i].Initials.IsEmpty())
		 Citation += (", " + AuthorList[i].Initials);
	   if (!AuthorList[i].Suffix.IsEmpty())
		 Citation += (", " + AuthorList[i].Suffix);
	   }
	 else {
	   if (i > 0) {
		 if (i == AuthorList.size()-1) {
		   if (style == 1 || i > 1)
			 Citation += ",";
		   Citation += " and ";
		   }
		 else
		   Citation += ", ";
		 }
	   Citation += (AuthorList[i].Initials + " " + AuthorList[i].LastName);
	   if (!AuthorList[i].Suffix.IsEmpty()) {
		 if (AuthorList[i].Suffix.SubString(1,2) == "Jr")
		   Citation += ",";
		 Citation += " ";
		 Citation += AuthorList[i].Suffix;
		 }
       }
	 }
   return Citation;
}
//---------------------------------------------------------------------------

UnicodeString TPubForm::FormatEditors(vector<EDITOR>& EditorList)
{
   // formats a string of authors for the citation
   // style: E.B. Smith, A.B. Jones, and E.C. Wilson

   UnicodeString Citation;
   for (unsigned int i=0; i<EditorList.size(); i++) {
	 if (i > 0) {
	   if (i == EditorList.size()-1) {
		 if (i > 1)
		   Citation += ",";
		 Citation += " and ";
		 }
	   else
		 Citation += ", ";
	   }
	 Citation += (EditorList[i].Initials + " " + EditorList[i].LastName);
	 if (!EditorList[i].Suffix.IsEmpty()) {
	   if (EditorList[i].Suffix.SubString(1,2) == "Jr")
		 Citation += ",";
	   Citation += " ";
	   Citation += EditorList[i].Suffix;
	   }
	 }

   return Citation;
}
//---------------------------------------------------------------------------

void TPubForm::ParseAuthor(UnicodeString& Author, AUTHOR& NewAuthor)
{
   int pos;

   if ((pos = Author.Pos(",")) > 0) {
	 NewAuthor.LastName = Author.SubString(1, pos-1);
	 Author.Delete(1, pos);
	 }
   else {
	 NewAuthor.LastName = Author;
	 Author.SetLength(0);
	 }
   if ((pos = Author.Pos(",")) > 0) {   // suffix exists
	 NewAuthor.Initials = Author.SubString(1, pos-1);
	 Author.Delete(1, pos);
	 NewAuthor.Suffix = Author;
	 NewAuthor.Suffix = NewAuthor.Suffix.Trim();
	 }
   else
	 NewAuthor.Initials = Author;
   NewAuthor.Initials = NewAuthor.Initials.Trim();
}
//---------------------------------------------------------------------------

void TPubForm::ParseEditor(UnicodeString& Editor, EDITOR& NewEditor)
{
   int pos;

   if ((pos = Editor.Pos(",")) > 0) {
	 NewEditor.LastName = Editor.SubString(1, pos-1);
	 Editor.Delete(1, pos);
	 }
   else {
	 NewEditor.LastName = Editor;
	 Editor.SetLength(0);
	 }
   if ((pos = Editor.Pos(",")) > 0) {   // suffix exists
	 NewEditor.Initials = Editor.SubString(1, pos-1);
	 Editor.Delete(1, pos);
	 NewEditor.Suffix = Editor;
	 NewEditor.Suffix = NewEditor.Suffix.Trim();
	 }
   else
	 NewEditor.Initials = Editor;
   NewEditor.Initials = NewEditor.Initials.Trim();
}
//---------------------------------------------------------------------------

void __fastcall TPubForm::cxButtonJournalClick(TObject *Sender)
{
   pub->pub_type = JOURNAL_ARTICLE;
   FormatInputForm();
}
//---------------------------------------------------------------------------

void __fastcall TPubForm::cxButtonBookChapterClick(TObject *Sender)
{
   pub->pub_type = BOOK_CHAPTER;
   FormatInputForm();
}
//---------------------------------------------------------------------------

void __fastcall TPubForm::cxButtonBookClick(TObject *Sender)
{
   switch (pub->pub_type) {
	 case EDITED_REPORT:
	 case OTHER_EDITED:
	   pub->pub_type = EDITED_BOOK;
	   break;
	 default:
	   pub->pub_type = AUTHORED_BOOK;
	   break;
	 }
   FormatInputForm();
}
//---------------------------------------------------------------------------

void __fastcall TPubForm::cxButtonReportClick(TObject *Sender)
{
   switch (pub->pub_type) {
	 case EDITED_BOOK:
	 case OTHER_EDITED:
	   pub->pub_type = EDITED_REPORT;
	   break;
	 default:
	   pub->pub_type = AUTHORED_REPORT;
	   break;
	 }
   FormatInputForm();
}
//---------------------------------------------------------------------------

void __fastcall TPubForm::cxButtonThesisClick(TObject *Sender)
{
   pub->DecodeThesisType(pub->Citation);
   FormatInputForm();
}
//---------------------------------------------------------------------------

void __fastcall TPubForm::cxButtonOtherClick(TObject *Sender)
{
   switch (pub->pub_type) {
	 case EDITED_BOOK:
	 case EDITED_REPORT:
	   pub->pub_type = OTHER_EDITED;
	   break;
	 default:
	   pub->pub_type = OTHER_AUTHORED;
	   break;
	 }
   FormatInputForm();
}
//---------------------------------------------------------------------------

void __fastcall TPubForm::cxButtonWebsiteClick(TObject *Sender)
{
   pub->pub_type = WEBSITE;
   FormatInputForm();
}
//---------------------------------------------------------------------------

// format citation
void __fastcall TPubForm::cxButton2Click(TObject *Sender)
{
   FormatCitation();
}
//---------------------------------------------------------------------------

void TPubForm::FormatCitation(void)
{
   switch (pub->pub_type) {
	 case JOURNAL_ARTICLE:
	   FormatJournalCitation();
	   break;
	 case BOOK_CHAPTER:
	   FormatBookChapterCitation();
	   break;
	 case AUTHORED_BOOK:
	 case EDITED_BOOK:
	   FormatBookCitation();
	   break;
	 case AUTHORED_REPORT:
	 case EDITED_REPORT:
	   FormatReportCitation();
	   break;
	 case DOCTORAL_THESIS:
	 case MASTERS_THESIS:
	 case UNDERGRAD_THESIS:
	   FormatThesisCitation();
	   break;
	 case LEGACY:
	 case OTHER_AUTHORED:
	 case OTHER_EDITED:
	   FormatOtherCitation();
	   break;
	 case WEBSITE:
	   FormatWebsiteCitation();
	   break;
	 }
}
//---------------------------------------------------------------------------

void TPubForm::ParseCitation(void)
{
   UnicodeString year;
   bool is_year;
   int begin_year = 0;
   const UnicodeString delimiters = "1234567890";
   for (int i=1; i<=pub->Citation.Length()-4; i++) {
	 year = pub->Citation.SubString(i,4);
	 is_year = true;
	 for (int j=1; j<=4; j++) {
	   if (!year.IsDelimiter(delimiters, j)) {
		 is_year = false;
		 break;
		 }
	   }
	 if (is_year) {
	   begin_year = i;
	   break;
	   }
	 }

   if (begin_year) {
	 UnicodeString Authors = pub->Citation.SubString(1, begin_year-2);
	 ParseAuthorsString(Authors);
	 pub->PublicationYear = pub->Citation.SubString(begin_year, 4);
	 pub->Title = pub->Citation.SubString(begin_year+6, pub->Citation.Length()-begin_year-4);
	 }
}
//---------------------------------------------------------------------------

void TPubForm::ParseAuthorsString(UnicodeString& Authors)
{
   // This function takes a string of authors from a citation
   int pos;
   UnicodeString OldAuthors;
   UnicodeString NewAuthors;
   UnicodeString Temp;
   UnicodeString Author, Initials, LastName;

   OldAuthors = Authors;
   pub->AuthorList.clear();

   // get first author
   AUTHOR Author1;
   pos = OldAuthors.Pos(L",");
   if (pos) {
	 // get last name
	 NewAuthors = OldAuthors.SubString(1, pos);
	 OldAuthors = OldAuthors.SubString(pos+1, OldAuthors.Length()-pos);
	 // get initials
	 pos = OldAuthors.Pos(L",");
	 if (pos) {   // multiple authors in list
	   NewAuthors += OldAuthors.SubString(1, pos-1);
	   OldAuthors = OldAuthors.SubString(pos+1, OldAuthors.Length()-pos);
	   pos = OldAuthors.Pos(L",");
	   // get suffix
	   if (pos)
         Temp = OldAuthors.SubString(1, pos-1);
       else
         Temp = OldAuthors;
       Temp = Temp.Trim();
	   if (Temp == L"Jr." || Temp == L"Jr" || Temp == L"I" || Temp == L"II" ||
		   Temp == L"III" || Temp == L"IV") {
		 NewAuthors += (L", " + Temp);
		 if (pos)
		   OldAuthors = OldAuthors.SubString(pos+1, OldAuthors.Length()-pos);
		 else
		   OldAuthors.SetLength(0);
		 }
	   }
	 else {
	   NewAuthors += OldAuthors;
	   OldAuthors.SetLength(0);
	   }
	 ParseAuthorName(NewAuthors, Author1);
	 pub->AuthorList.push_back(Author1);

	 // get rest of authors
	 // delete last period if there
	 if (OldAuthors.Length() > 0) {
	   pos = OldAuthors.LastDelimiter(L".");
	   if (pos == OldAuthors.Length()) {
	   if ((OldAuthors.SubString(pos-2, 2)).CompareIC("jr"))
		 OldAuthors.SetLength(pos-1);
		 }
	   }
	 while (OldAuthors.Length() > 0) {
	   OldAuthors = OldAuthors.TrimLeft();
	   pos = OldAuthors.Pos(L",");
	   if (pos) {
		 Author = OldAuthors.SubString(1, pos-1);
		 OldAuthors = OldAuthors.SubString(pos+1, OldAuthors.Length()-pos);
		 }
	   else {
		 Author = OldAuthors;
		 OldAuthors.SetLength(0);
		 }
	   Author = Author.TrimLeft();
	   if (Author.SubString(1,4) == L"and ")
		 Author = Author.SubString(5, Author.Length()-4);
	   pos = Author.LastDelimiter(L".");
	   if (pos) {
		 Initials = Author.SubString(1, pos);
		 LastName = Author.SubString(pos+1, Author.Length()-pos);
		 LastName = LastName.TrimLeft();
		 Author = LastName + L", " + Initials;
		 }
	   // get suffix
	   if (OldAuthors.Length()) {
		 pos = OldAuthors.Pos(L",");
		 if (pos)
		   Temp = OldAuthors.SubString(1, pos-1);
		 else
		   Temp = OldAuthors;
		 Temp = Temp.Trim();
		 if (Temp == L"Jr." || Temp == L"Jr" || Temp == L"I" || Temp == L"II" ||
			 Temp == L"III" || Temp == L"IV") {
		   Author += (L", " + Temp);
           if (pos)
             OldAuthors = OldAuthors.SubString(pos+1, OldAuthors.Length()-pos);
           else
             OldAuthors.SetLength(0);
           }
         }
	   AUTHOR Author2;
	   ParseAuthorName(Author, Author2);
	   pub->AuthorList.push_back(Author2);
	   }
	 }
   else {
	 AUTHOR Author2;
	 ParseAuthorName(Authors, Author2);
	 pub->AuthorList.push_back(Author2);
	 }
}
//---------------------------------------------------------------------------

void TPubForm::CheckAuthorFormat(TAdvStringGrid* AuthorsGrid, vector<AUTHOR>& AuthorList)
{
   vector<AUTHOR> OldAuthorList(AuthorList.begin(), AuthorList.end());
   AuthorList.clear();
   for (int i=0; i<AuthorsGrid->RowCount; i++) {
	 UnicodeString AuthorStr = AuthorsGrid->Cells[0][i];
	 if (AuthorStr.IsEmpty()) continue;
	 AuthorStr = AuthorStr.Trim();
	 AUTHOR Author;
	 AuthorStr = ParseAuthorName(AuthorStr, Author);
	 AuthorList.push_back(Author);
	 AuthorsGrid->Cells[0][i] = AuthorStr;
	 for (unsigned int i=0; i<OldAuthorList.size(); i++) {
	   if (Author == OldAuthorList[i]) {
		 Author.contact = OldAuthorList[i].contact;
		 Author.NeotomaContactID = OldAuthorList[i].NeotomaContactID;
		 break;
		 }
	   }
	 }
   if (AuthorsGrid->RowCount > 0)
	 cxThesisAuthorEdit->Text = AuthorsGrid->Cells[0][0];

   bool changed = false;
   if (OldAuthorList.size() == AuthorList.size()) {
	 for (unsigned int i=0; i<AuthorList.size(); i++) {
	   if (!(AuthorList[i] == OldAuthorList[i])) {
		 changed = true;
		 break;
		 }
	   }
	 }
   else
	 changed = true;

   if (changed) {
	 if (cxButton3->Visible)
	   cxButton3->Enabled = true;
	 PubChanged = true;
	 }
}
//---------------------------------------------------------------------------

void TPubForm::CheckEditorFormat(TAdvStringGrid* EditorsGrid, vector<EDITOR>& EditorList)
{
   vector<EDITOR> OldEditorList(EditorList.begin(), EditorList.end());
   EditorList.clear();
   for (int i=0; i<EditorsGrid->RowCount; i++) {
	 UnicodeString EditorStr = EditorsGrid->Cells[0][i];
	 if (EditorStr.IsEmpty()) continue;
	 EditorStr = EditorStr.Trim();
	 EDITOR Editor;
	 EditorStr = ParseEditorName(EditorStr, Editor);
	 EditorList.push_back(Editor);
	 EditorsGrid->Cells[0][i] = EditorStr;
	 }

   bool changed = false;
   if (OldEditorList.size() == EditorList.size()) {
	 for (unsigned int i=0; i<EditorList.size(); i++) {
	   if (!(EditorList[i] == OldEditorList[i])) {
		 changed = true;
		 break;
		 }
	   }
	 }
   else
	 changed = true;

   if (changed) {
	 if (cxButton3->Visible)
	   cxButton3->Enabled = true;
	 PubChanged = true;
	 }
}
//---------------------------------------------------------------------------

UnicodeString TPubForm::FormatAuthor(UnicodeString& Author)
{
   int pos;
   UnicodeString Surname;
   UnicodeString Forenames;
   UnicodeString Initials;
   UnicodeString Suffix;
   UnicodeString Temp;

   int len = Author.Length();
   if (Author.SubString(len-3,4) == " Jr.") {
     Suffix = "Jr.";
     Author.SetLength(len-4);
     }
   else if (Author.SubString(len-2,3) == " Jr") {
     Suffix = "Jr";
     Author.SetLength(len-3);
     }
   else if (Author.SubString(len-1,2) == " I") {
     Suffix = "I";
     Author.SetLength(len-2);
     }
   else if (Author.SubString(len-2,3) == " II") {
     Suffix = "II";
     Author.SetLength(len-3);
     }
   else if (Author.SubString(len-3,4) == " III") {
     Suffix = "III";
     Author.SetLength(len-4);
     }
   else if (Author.SubString(len-2,3) == " IV") {
     Suffix = "IV";
     Author.SetLength(len-3);
     }

   pos = Author.LastDelimiter(",");     // remove trailing comma
   if (pos == Author.Length())
     Author.SetLength(pos-1);

   pos = Author.Pos(",");
   if (pos) {                           // forenames or initials after surname
     Surname = Author.SubString(1,pos-1);
     Forenames = Author.SubString(pos+1, Author.Length()-pos);
     Forenames = Forenames.TrimLeft();
     }
   else {                               // forenames or initials before surname
     pos = Author.LastDelimiter(" ");
	 if (pos) {
	   Surname = Author.SubString(pos+1,Author.Length()-pos);
       Forenames = Author.SubString(1,pos-1);
       Forenames = Forenames.TrimRight();
       }
     }
   if (pos) {
	 Initials = ParseForenames(Forenames);
	 Author = Surname + ", " + Initials;
	 if (!Suffix.IsEmpty())
	   Author += (", " + Suffix);
	 }
     
   return Author;
}
//---------------------------------------------------------------------------

UnicodeString TPubForm::ParseAuthorName(UnicodeString AuthorStr, AUTHOR& Author)
{
   AuthorStr = ParseName(AuthorStr, Author.Initials, Author.GivenNames, Author.LastName, Author.Suffix);
   return AuthorStr;
}
//---------------------------------------------------------------------------

UnicodeString TPubForm::ParseEditorName(UnicodeString EditorStr, EDITOR& Editor)
{
   UnicodeString GivenNames;
   EditorStr = ParseName(EditorStr, Editor.Initials, GivenNames, Editor.LastName, Editor.Suffix);
   return EditorStr;
}
//---------------------------------------------------------------------------

UnicodeString TPubForm::ParseName(UnicodeString NameStr, UnicodeString& Initials,
  UnicodeString& GivenNames, UnicodeString& LastName, UnicodeString& Suffix)
{
   Suffix = ParseSuffix(NameStr);

   NameStr = NameStr.Trim();
   int pos = NameStr.LastDelimiter(",");     // remove trailing comma
   if (pos == NameStr.Length())
	 NameStr.SetLength(pos-1);

   pos = NameStr.Pos(",");
   if (pos) {                           // forenames or initials after surname
	 LastName = NameStr.SubString(1,pos-1);
	 GivenNames = NameStr.SubString(pos+1, NameStr.Length()-pos);
	 GivenNames = GivenNames.TrimLeft();
	 }
   else {                               // forenames or initials before surname
	 pos = NameStr.LastDelimiter(" ");
	 if (pos) {
	   LastName = NameStr.SubString(pos+1,NameStr.Length()-pos);
	   GivenNames = NameStr.SubString(1,pos-1);
	   GivenNames = GivenNames.TrimRight();
	   }
	 else
	   LastName = NameStr;
	 }
   int idx;     // replace non-breaking space character ~ with space
   while ((idx = LastName.Pos(L"~")) > 0) {
	 LastName.Delete(idx,1);
	 LastName.Insert(L" ",idx);
	 }
   if (pos) {   // given names exist
	 Initials = ParseForenames(GivenNames);
	 NameStr = LastName + ", " + Initials;
	 if (!Suffix.IsEmpty())
	   NameStr += (", " + Suffix);
	 }
   else
     NameStr = LastName;
   return NameStr;
}
//---------------------------------------------------------------------------

UnicodeString TPubForm::ParseSuffix(UnicodeString& NameStr)
{
   UnicodeString Suffix;
   int len = NameStr.Length();
   if (NameStr.SubString(len-3,4) == " Jr.") {
	 Suffix = "Jr.";
	 NameStr.SetLength(len-4);
	 }
   else if (NameStr.SubString(len-2,3) == " Jr") {
	 Suffix = "Jr";
	 NameStr.SetLength(len-3);
	 }
   else if (NameStr.SubString(len-1,2) == " I") {
	 Suffix = "I";
	 NameStr.SetLength(len-2);
	 }
   else if (NameStr.SubString(len-2,3) == " II") {
	 Suffix = "II";
	 NameStr.SetLength(len-3);
	 }
   else if (NameStr.SubString(len-3,4) == " III") {
	 Suffix = "III";
	 NameStr.SetLength(len-4);
	 }
   else if (NameStr.SubString(len-2,3) == " IV") {
	 Suffix = "IV";
	 NameStr.SetLength(len-3);
	 }
   return Suffix;
}
//---------------------------------------------------------------------------

UnicodeString TPubForm::ParseForenames(UnicodeString& Forenames)
{
   int spos, hpos, pos;
   UnicodeString Initials;

   spos = Forenames.Pos("  ");  // remove any double spaces
   while (spos) {
     Forenames.Delete(spos, 1);
     spos = Forenames.Pos("  ");
     }
   hpos = Forenames.Pos("-");  // put a period before any a hyphen
   if (hpos > 1) {
     if (Forenames.SubString(hpos-1,1) != ".")
       Forenames.Insert(".", hpos);
     }
   spos = Forenames.Pos(" ");   // replace spaces with periods
   while (spos) {
     Forenames.Delete(spos, 1);
     Forenames.Insert(".", spos);
	 spos = Forenames.Pos(" ");
     }
   if (Forenames.LastDelimiter(".") != Forenames.Length())
     Forenames += ".";

   //remove any double periods
   pos = Forenames.Pos(L"..");
   while (pos > 0) {
	 Forenames.Delete(pos,1);
	 pos = Forenames.Pos(L"..");
	 }

   while (Forenames.Length()) {      // replace names with initials
	 hpos = Forenames.Pos("-");
     if (hpos == 1)
       Initials += (Forenames.SubString(1,2) + ".");
     else
       Initials += (Forenames.SubString(1,1) + ".");
	 spos = Forenames.Pos(".");
     Forenames = Forenames.SubString(spos+1, Forenames.Length()-spos);
     }
   return Initials;
}
//---------------------------------------------------------------------------

void __fastcall TPubForm::AuthorsGridExit(TObject *Sender)
{
   CheckAuthorFormat(AuthorsGrid, pub->AuthorList);
}
//---------------------------------------------------------------------------

void __fastcall TPubForm::EditorsGridExit(TObject *Sender)
{
   CheckEditorFormat(EditorsGrid, pub->EditorList);
}
//---------------------------------------------------------------------------

void __fastcall TPubForm::TranslatorGridExit(TObject *Sender)
{
   CheckEditorFormat(TranslatorGrid, pub->TranslatorList);
}
//---------------------------------------------------------------------------

void __fastcall TPubForm::cxThesisAuthorEditExit(TObject *Sender)
{
   vector<AUTHOR> OldAuthorList(pub->AuthorList.begin(), pub->AuthorList.end());
   pub->AuthorList.clear();
   AUTHOR NewAuthor;
   UnicodeString Author = cxThesisAuthorEdit->Text.Trim();
   ParseAuthor(Author, NewAuthor);
   pub->AuthorList.push_back(NewAuthor);
   AuthorsGrid->Cells[0][0] = cxThesisAuthorEdit->Text;
   for (unsigned int i=0; i<OldAuthorList.size(); i++) {
	 if (NewAuthor == OldAuthorList[i]) {
	   NewAuthor.contact = OldAuthorList[i].contact;
	   NewAuthor.NeotomaContactID = OldAuthorList[i].NeotomaContactID;
	   break;
	   }
	 }

   bool changed = false;
   if (OldAuthorList.size() == pub->AuthorList.size()) {
	 for (unsigned int i=0; i<pub->AuthorList.size(); i++) {
	   if (!(pub->AuthorList[i] == OldAuthorList[i])) {
		 changed = true;
		 break;
		 }
	   }
	 }
   else
	 changed = true;

   if (changed) {
	 if (cxButton3->Visible)
	   cxButton3->Enabled = true;
	 PubChanged = true;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TPubForm::cxYearEditExit(TObject *Sender)
{
   cxYearEdit->Text = cxYearEdit->Text.Trim();
   if (pub->PublicationYear != cxYearEdit->Text) {
	 pub->PublicationYear = cxYearEdit->Text;
	 if (cxButton3->Visible)
	   cxButton3->Enabled = true;
	 PubChanged = true;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TPubForm::cxTitleMemoExit(TObject *Sender)
{
   cxTitleMemo->Text = cxTitleMemo->Text.Trim();
   if (pub->Title != cxTitleMemo->Text) {
	 pub->Title = cxTitleMemo->Text;
	 if (cxButton3->Visible)
	   cxButton3->Enabled = true;
	 PubChanged = true;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TPubForm::cxJournalNameEditExit(TObject *Sender)
{
   cxJournalNameEdit->Text = cxJournalNameEdit->Text.Trim();
   if (pub->Journal != cxJournalNameEdit->Text) {
	 pub->Journal = cxJournalNameEdit->Text;
	 if (cxButton3->Visible)
	   cxButton3->Enabled = true;
	 PubChanged = true;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TPubForm::cxJournalVolumeEditExit(TObject *Sender)
{
   cxJournalVolumeEdit->Text = cxJournalVolumeEdit->Text.Trim();
   if (pub->Volume != cxJournalVolumeEdit->Text) {
	 pub->Volume = cxJournalVolumeEdit->Text;
	 if (cxButton3->Visible)
	   cxButton3->Enabled = true;
	 PubChanged = true;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TPubForm::cxJournalIssueEditExit(TObject *Sender)
{
   cxJournalIssueEdit->Text = cxJournalIssueEdit->Text.Trim();
   if (pub->Issue != cxJournalIssueEdit->Text) {
	 pub->Issue = cxJournalIssueEdit->Text;
	 if (cxButton3->Visible)
	   cxButton3->Enabled = true;
	 PubChanged = true;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TPubForm::cxPageEditExit(TObject *Sender)
{
   cxPageEdit->Text = cxPageEdit->Text.Trim();
   if (pub->Pages != cxPageEdit->Text) {
	 pub->Pages = cxPageEdit->Text;
	 if (cxButton3->Visible)
	   cxButton3->Enabled = true;
	 PubChanged = true;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TPubForm::cxCitationNumberExit(TObject *Sender)
{
   cxCitationNumber->Text = cxCitationNumber->Text.Trim();
   if (pub->CitationNumber != cxCitationNumber->Text) {
	 pub->CitationNumber = cxCitationNumber->Text;
	 if (cxButton3->Visible)
	   cxButton3->Enabled = true;
	 PubChanged = true;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TPubForm::cxURLEditExit(TObject *Sender)
{
   cxURLEdit->Text = cxURLEdit->Text.Trim();
   if (pub->URL != cxURLEdit->Text) {
	 pub->URL = cxURLEdit->Text;
	 if (cxButton3->Visible)
	   cxButton3->Enabled = true;
	 PubChanged = true;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TPubForm::cxDOIEditExit(TObject *Sender)
{
   cxDOIEdit->Text = cxDOIEdit->Text.Trim();
   if (pub->DOI != cxDOIEdit->Text) {
	 pub->DOI = cxDOIEdit->Text;
	 if (cxButton3->Visible)
	   cxButton3->Enabled = true;
	 PubChanged = true;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TPubForm::cxBookTitleMemoExit(TObject *Sender)
{
   cxBookTitleMemo->Text = cxBookTitleMemo->Text.Trim();
   if (pub->BookTitle != cxBookTitleMemo->Text) {
	 pub->BookTitle = cxBookTitleMemo->Text;
	 if (cxButton3->Visible)
	   cxButton3->Enabled = true;
	 PubChanged = true;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TPubForm::cxEditionEditExit(TObject *Sender)
{
   cxEditionEdit->Text = cxEditionEdit->Text.Trim();
   if (pub->Edition != cxEditionEdit->Text) {
	 pub->Edition = cxEditionEdit->Text;
	 if (cxButton3->Visible)
	   cxButton3->Enabled = true;
	 PubChanged = true;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TPubForm::cxNumVolsEditExit(TObject *Sender)
{
   cxNumVolsEdit->Text = cxNumVolsEdit->Text.Trim();
   if (pub->NumVolumes != cxNumVolsEdit->Text) {
	 pub->NumVolumes = cxNumVolsEdit->Text;
	 if (cxButton3->Visible)
	   cxButton3->Enabled = true;
	 PubChanged = true;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TPubForm::cxVolumeNumberEditExit(TObject *Sender)
{
   cxVolumeNumberEdit->Text = cxVolumeNumberEdit->Text.Trim();
   if (pub->Volume != cxVolumeNumberEdit->Text) {
	 pub->Volume = cxVolumeNumberEdit->Text;
	 if (cxButton3->Visible)
	   cxButton3->Enabled = true;
	 PubChanged = true;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TPubForm::cxVolumeTitleMemoExit(TObject *Sender)
{
   cxVolumeTitleMemo->Text = cxVolumeTitleMemo->Text.Trim();
   if (pub->VolumeTitle != cxVolumeTitleMemo->Text) {
	 pub->VolumeTitle = cxVolumeTitleMemo->Text;
	 if (cxButton3->Visible)
	   cxButton3->Enabled = true;
	 PubChanged = true;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TPubForm::cxSeriesTitleMemoExit(TObject *Sender)
{
   cxSeriesTitleMemo->Text = cxSeriesTitleMemo->Text.Trim();
   if (pub->SeriesTitle != cxSeriesTitleMemo->Text) {
	 pub->SeriesTitle = cxSeriesTitleMemo->Text;
	 if (cxButton3->Visible)
	   cxButton3->Enabled = true;
	 PubChanged = true;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TPubForm::cxSeriesVolumeEditExit(TObject *Sender)
{
   cxSeriesVolumeEdit->Text = cxSeriesVolumeEdit->Text.Trim();
   if (pub->SeriesNumber != cxSeriesVolumeEdit->Text) {
	 pub->SeriesNumber = cxSeriesVolumeEdit->Text;
	 if (cxButton3->Visible)
	   cxButton3->Enabled = true;
	 PubChanged = true;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TPubForm::cxPublisherEditExit(TObject *Sender)
{
   cxPublisherEdit->Text = cxPublisherEdit->Text.Trim();
   if (pub->Publisher != cxPublisherEdit->Text) {
	 pub->Publisher = cxPublisherEdit->Text;
	 if (cxButton3->Visible)
	   cxButton3->Enabled = true;
	 PubChanged = true;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TPubForm::cxUniversityEditExit(TObject *Sender)
{
   cxUniversityEdit->Text = cxUniversityEdit->Text.Trim();
   if (pub->University != cxUniversityEdit->Text) {
	 pub->University = cxUniversityEdit->Text;
	 if (cxButton3->Visible)
	   cxButton3->Enabled = true;
	 PubChanged = true;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TPubForm::cxCityEditExit(TObject *Sender)
{
   cxCityEdit->Text = cxCityEdit->Text.Trim();
   if (pub->City != cxCityEdit->Text) {
	 pub->City = cxCityEdit->Text;
	 if (cxButton3->Visible)
	   cxButton3->Enabled = true;
	 PubChanged = true;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TPubForm::cxStateEditExit(TObject *Sender)
{
   cxStateEdit->Text = cxStateEdit->Text.Trim();
   if (pub->State != cxStateEdit->Text) {
	 pub->State = cxStateEdit->Text;
	 if (cxButton3->Visible)
	   cxButton3->Enabled = true;
	 PubChanged = true;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TPubForm::cxCountryEditExit(TObject *Sender)
{
   cxCountryEdit->Text = cxCountryEdit->Text.Trim();
   if (pub->Country != cxCountryEdit->Text) {
	 pub->Country = cxCountryEdit->Text;
	 if (cxButton3->Visible)
	   cxButton3->Enabled = true;
	 PubChanged = true;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TPubForm::cxOrigLangEditExit(TObject *Sender)
{
   cxOrigLangEdit->Text = cxOrigLangEdit->Text.Trim();
   if (pub->OrigLang != cxOrigLangEdit->Text) {
	 pub->OrigLang = cxOrigLangEdit->Text;
	 if (cxButton3->Visible)
	   cxButton3->Enabled = true;
	 PubChanged = true;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TPubForm::cxNotesMemoExit(TObject *Sender)
{
   cxNotesMemo->Text = cxNotesMemo->Text.Trim();
   if (pub->Notes != cxNotesMemo->Text) {
	 pub->Notes = cxNotesMemo->Text;
     if (cxButton3->Visible)
	   cxButton3->Enabled = true;
	 PubChanged = true;
	 }
}
//---------------------------------------------------------------------------

// get Neotoma publication
void __fastcall TPubForm::NeotomaButtonClick(TObject *Sender)
{
   if (pub->AuthorList.size() > 0 && !pub->PublicationYear.IsEmpty())  // author and year entered
	 GetNeotomaPublicationID();
   else
	 GetNeotomaPublication();
}
//---------------------------------------------------------------------------

void TPubForm::GetNeotomaPublicationID(void)
{
   set<int> Pub1IDs;
   set<int>::iterator itr1;
   set<int>::iterator itr2;
   vector<UnicodeString> AuthorLastNames;
   // first get list of author last names
   for (unsigned int i=0; i<pub->AuthorList.size(); i++)
	 AuthorLastNames.push_back(pub->AuthorList[i].LastName);

   // get publications for first family name
   NeotomaPublicationsByFamilyName Publications1(ipsJSONS1, TcpClient1);
   UnicodeString FirstAuthor = AuthorLastNames[0];
   Publications1.AddParam(L"FAMILYNAME", FirstAuthor);
   StatusBar1->SimpleText = Publications1.WebServiceName();
   Screen->Cursor = crHourGlass;
   if (Publications1.Execute()) {
	 if (Publications1.Size() > 0) {
	   for (unsigned int i=0; i<Publications1.Size(); i++) {
		 UnicodeString Year = Publications1.Items[i].Year;
		 if (SameText(Year, pub->PublicationYear)) {
		   int PubID = Publications1.Items[i].PublicationID;
		   Pub1IDs.insert(PubID);
		   }
		 }
	   }
	 }


   // Next get PubIDs for second, third,... authors;
   // search for second, third,... author PubIDs in PubIDs set,
   // if not found, erase from set.

   for (unsigned int i=1; i<AuthorLastNames.size(); i++) {
	 NeotomaPublicationsByFamilyName Publications2(ipsJSONS1, TcpClient1);
	 UnicodeString NextAuthor = AuthorLastNames[i];
	 Publications2.AddParam(L"FAMILYNAME", NextAuthor);
	 StatusBar1->SimpleText = Publications2.WebServiceName();
	 if (Publications2.Execute()) {
	   if (Publications2.Size() > 0) {
		 set<int> Pub2IDs;
		 set<int> Pub3IDs;
		 for (unsigned int j=0; j<Publications2.Size(); j++) {
		   UnicodeString Year = Publications2.Items[j].Year;
		   if (SameText(Year, pub->PublicationYear)) {
			 int PubID2 = Publications2.Items[j].PublicationID;
			 Pub2IDs.insert(PubID2);
			 }
		   }
		 set<int> intersection;
		 set_intersection(Pub1IDs.begin(), Pub1IDs.end(),
						  Pub2IDs.begin(), Pub2IDs.end(),
						  inserter(intersection, intersection.end()));
		 Pub1IDs.clear();
		 Pub1IDs = intersection;
		 }
	   }
	 }

   StatusBar1->SimpleText = L"";
   Screen->Cursor = crDefault;

   if (Pub1IDs.size() > 0) {
	  TMatchPubForm *MatchPubForm = new TMatchPubForm(pub, Pub1IDs, this);
	  int rv = MatchPubForm->ShowModal();
	  if (rv == mrOk || rv == mrYes) {
		if (MatchPubForm->PubID > -1) {
		  LabelNeotomaPubID->Visible =  true;
		  Panel10->Visible = true;
		  cxNeotomaPubIDEdit->Text = IntToStr(pub->NeotomaID);
          SetNavigationButtons();
		  if (rv == mrYes) {
			ClearInputForm();
			FormatInputForm();
			PopulateInputForm();
			}
		  }
		}
	  delete MatchPubForm;
	  }
   else if (!NeotomaPubSearched || PubChanged) {
	 TForm* PubMsgDlg = CreateMessageDialog(L"message", mtInformation, TMsgDlgButtons() << mbYes << mbNo, mbYes);
	 UnicodeString msg1 = L"Neotoma has no publication with author";
	 if (pub->AuthorList.size() == 1)
	   msg1 += (L" " + pub->AuthorList[0].LastName);
	 else if (pub->AuthorList.size() == 2)
	   msg1 += (L"s " + pub->AuthorList[0].LastName + L" and " + pub->AuthorList[1].LastName);
	 else if (pub->AuthorList.size() == 3)
	   msg1 += (L"s " + pub->AuthorList[0].LastName + L", " + pub->AuthorList[1].LastName +
			   L", and " + pub->AuthorList[2].LastName);
	 else if (pub->AuthorList.size() > 3)
	   msg1 += (L"s " + pub->AuthorList[0].LastName + L", " + pub->AuthorList[1].LastName +
			   L", " + pub->AuthorList[2].LastName + L", et al.");
	 msg1 += (L" published in " + pub->PublicationYear + L". ");
	 msg1 += L"However, spellings of authors' names must match exactly, ";
	 msg1 += L"and a slight variaton in spelling will cause a mismatch. These variations ";
	 msg1 += L"are especially common for non-English names with umlauts, diphthongs, and ";
	 msg1 += L"diacritical marks, names that are optionally hyphenated, and names ";
	 msg1 += L"transliterated from languages with non-Latin alphabets. Examples:";
	 UnicodeString msg, msg2;
	 int pos = 1;
	 while (pos <= msg1.Length()) {
	   if (msg1.SubString(pos,1) == L" ") {
		 if (PubMsgDlg->Canvas->TextWidth(msg2) < 400)
		   msg2 += msg1.SubString(pos,1);
		 else {
		   msg += msg2;
		   msg += L"\n";
		   msg2 = L"";
		   }
		 }
	   else
		 msg2 += msg1.SubString(pos,1);
	   pos++;
	   }
	 msg += (msg2 + L"\n\n");
	 msg += L"  Müller, Mueller\n";
	 msg += L"  Fægri, Faegri\n";
	 msg += L"  Méliès, Melies\n";
	 msg += L"  León Portilla, León-Portilla\n";
	 msg += L"  Zaklinskaia, Zaklinskaya (Заклинская)\n\n";
	 msg += L"Would you like to do an advanced search?";

	 delete PubMsgDlg;

	 PubMsgDlg = CreateMessageDialog(msg, mtInformation, TMsgDlgButtons() << mbYes << mbNo, mbYes);
	 if (PubMsgDlg->ShowModal() == mrYes) {
	   Pub1IDs.clear();
	   TMatchPubForm *MatchPubForm = new TMatchPubForm(pub, Pub1IDs, this);
	   int rv = MatchPubForm->ShowModal();
	   if (rv == mrOk || rv == mrYes) {
		 if (MatchPubForm->PubID > -1) {
		   LabelNeotomaPubID->Visible =  true;
		   Panel10->Visible = true;
		   cxNeotomaPubIDEdit->Text = IntToStr(pub->NeotomaID);
		   SetNavigationButtons();
		   if (rv == mrYes) {
			 ClearInputForm();
			 FormatInputForm();
			 PopulateInputForm();
			 }
		   }
		 }
	   delete MatchPubForm;
	   }
	 delete PubMsgDlg;
	 }
}
//---------------------------------------------------------------------------

void TPubForm::GetNeotomaPublication(void)
{
   TGetPubForm *GetPubForm = new TGetPubForm(pub, this);
   if (GetPubForm->ShowModal() == mrOk) {
	 if (GetPubForm->PubID > -1) {
       ClearInputForm();
	   FormatInputForm();
	   PopulateInputForm();
       if (cxButton3->Visible) {
		 cxButton3->Caption = L"Update";
		 Style = EDITPUB;
		 }
	   }
	 }
   delete GetPubForm;
}
//---------------------------------------------------------------------------

void __fastcall TPubForm::FormCanResize(TObject *Sender, int &NewWidth, int &NewHeight,
		  bool &Resize)
{
   if (NewWidth < 432)
	 Resize = false;
}
//---------------------------------------------------------------------------

void __fastcall TPubForm::FormResize(TObject *Sender)
{
   if (!Activated) return;
   int NewWidth = Width - 174;

   Panel2->Width = NewWidth;
   Panel4->Width = NewWidth;
   PanelAuthors->Width = NewWidth;
   cxThesisAuthorEdit->Width = NewWidth;
   cxYearEdit->Width = NewWidth;
   cxTitleMemo->Width = NewWidth;
   cxJournalNameEdit->Width = NewWidth;
   cxJournalVolumeEdit->Width = NewWidth;
   cxJournalIssueEdit->Width = NewWidth;
   cxDOIEdit->Width = NewWidth;
   cxPageEdit->Width = NewWidth;
   cxCitationNumber->Width = NewWidth;
   cxDOIEdit->Width = NewWidth;
   cxURLEdit->Width = NewWidth;
   PanelEditors->Width = NewWidth;
   cxBookTitleMemo->Width = NewWidth;
   cxEditionEdit->Width = NewWidth;
   cxNumVolsEdit->Width = NewWidth;
   cxVolumeNumberEdit->Width = NewWidth;
   cxVolumeTitleMemo->Width = NewWidth;
   cxSeriesTitleMemo->Width = NewWidth;
   cxSeriesVolumeEdit->Width = NewWidth;
   cxPublisherEdit->Width = NewWidth;
   cxUniversityEdit->Width = NewWidth;
   cxCityEdit->Width = NewWidth;
   cxStateEdit->Width = NewWidth;
   cxCountryEdit->Width = NewWidth;
   PanelTranslator->Width = NewWidth;
   cxOrigLangEdit->Width = NewWidth;
   Panel5->Width = 124 + NewWidth;
   //Panel6->Width = 124 + NewWidth;
   cxWorkSpaceMemo->Width = NewWidth;
   cxNotesMemo->Width = NewWidth;
   cxCitationMemo->Width = NewWidth;
   SetFlowPanel1Position();
}
//---------------------------------------------------------------------------

void __fastcall TPubForm::RadioButton1Click(TObject *Sender)
{
   switch (pub->pub_type) {
	 case AUTHORED_BOOK:
	 case EDITED_BOOK:
	   LabelAuthors->Caption  = L"Authors: ";
	   pub->pub_type = AUTHORED_BOOK;
	   break;
	 case AUTHORED_REPORT:
	 case EDITED_REPORT:
	   LabelAuthors->Caption  = L"Authors: ";
	   pub->pub_type = AUTHORED_REPORT;
	   break;
	 case LEGACY:
	 case OTHER_AUTHORED:
	 case OTHER_EDITED:
	   LabelAuthors->Caption  = L"Authors: ";
	   pub->pub_type = OTHER_AUTHORED;
	   break;
	 }
   if (cxButton3->Visible)
	 cxButton3->Enabled = true;
   PubChanged = true;
}
//---------------------------------------------------------------------------

void __fastcall TPubForm::RadioButton2Click(TObject *Sender)
{
   switch (pub->pub_type) {
	 case AUTHORED_BOOK:
	 case EDITED_BOOK:
	   LabelAuthors->Caption  = L"Editors: ";
	   pub->pub_type = EDITED_BOOK;
	   break;
	 case AUTHORED_REPORT:
	 case EDITED_REPORT:
	   LabelAuthors->Caption  = L"Editors: ";
	   pub->pub_type = EDITED_REPORT;
	   break;
	 case LEGACY:
	 case OTHER_AUTHORED:
	 case OTHER_EDITED:
       LabelAuthors->Caption  = L"Editors: ";
	   pub->pub_type = OTHER_EDITED;
	   break;
	 }
   if (cxButton3->Visible)
	 cxButton3->Enabled = true;
   PubChanged = true;
}
//---------------------------------------------------------------------------

void __fastcall TPubForm::RadioButton3Click(TObject *Sender)
{
   pub->pub_type = DOCTORAL_THESIS;
   if (cxButton3->Visible)
	 cxButton3->Enabled = true;
   PubChanged = true;
}
//---------------------------------------------------------------------------

void __fastcall TPubForm::RadioButton4Click(TObject *Sender)
{
   pub->pub_type = MASTERS_THESIS;
   if (cxButton3->Visible)
	 cxButton3->Enabled = true;
   PubChanged = true;
}
//---------------------------------------------------------------------------

void __fastcall TPubForm::RadioButton5Click(TObject *Sender)
{
   pub->pub_type = UNDERGRAD_THESIS;
   if (cxButton3->Visible)
	 cxButton3->Enabled = true;
   PubChanged = true;
}
//---------------------------------------------------------------------------

// Ok button
void __fastcall TPubForm::cxButton9Click(TObject *Sender)
{
   CleanUp();
   Screen->Cursor = crDefault;
}
//---------------------------------------------------------------------------

void TPubForm::CleanUp(void)
{
   UnicodeString Blank;

   // blank any fields not used
   switch (pub->pub_type) {
	 case JOURNAL_ARTICLE:
	   pub->EditorList.clear();
	   pub->TranslatorList.clear();
	   pub->BookTitle = Blank;
	   pub->Edition = Blank;
	   pub->NumVolumes = Blank;
	   pub->VolumeTitle = Blank;
	   pub->SeriesTitle = Blank;
	   pub->SeriesNumber = Blank;
	   pub->OrigLang = Blank;
	   pub->Publisher = Blank;
	   pub->University = Blank;
	   pub->City = Blank;
	   pub->State = Blank;
	   pub->Country = Blank;
	   pub->Citation = FormatJournalCitation();
	   break;
	 case BOOK_CHAPTER:
	   pub->Journal = Blank;
	   pub->Issue = Blank;
	   pub->URL = Blank;
	   pub->CitationNumber = Blank;
	   pub->University = Blank;
	   pub->Citation = FormatBookChapterCitation();
	   break;
	 case AUTHORED_BOOK:
	 case EDITED_BOOK:
	   pub->EditorList.clear();
	   pub->Title = Blank;
	   pub->Journal = Blank;
	   pub->Issue = Blank;
	   pub->URL = Blank;
	   pub->Pages = Blank;
	   pub->CitationNumber = Blank;
	   pub->University = Blank;
	   pub->Citation = FormatBookCitation();
	   break;
     case AUTHORED_REPORT:
	 case EDITED_REPORT:
	   pub->EditorList.clear();
	   pub->TranslatorList.clear();
	   pub->Journal = Blank;
	   pub->Volume = Blank;
	   pub->Issue = Blank;
	   pub->URL = Blank;
	   pub->BookTitle = Blank;
	   pub->Edition = Blank;
	   pub->NumVolumes = Blank;
	   pub->VolumeTitle = Blank;
	   pub->OrigLang = Blank;
	   pub->Pages = Blank;
	   pub->CitationNumber = Blank;
	   pub->University = Blank;
	   pub->Citation = FormatReportCitation();
	   break;
	 case DOCTORAL_THESIS:
	 case MASTERS_THESIS:
	 case UNDERGRAD_THESIS:
	   pub->EditorList.clear();
	   pub->TranslatorList.clear();
	   pub->Journal = Blank;
	   pub->Volume = Blank;
	   pub->Issue = Blank;
	   pub->URL = Blank;
	   pub->DOI = Blank;
	   pub->BookTitle = Blank;
	   pub->Edition = Blank;
	   pub->NumVolumes = Blank;
	   pub->VolumeTitle = Blank;
	   pub->SeriesTitle = Blank;
	   pub->SeriesNumber = Blank;
	   pub->OrigLang = Blank;
	   pub->Pages = Blank;
	   pub->CitationNumber = Blank;
	   pub->Publisher = Blank;
	   pub->Citation = FormatThesisCitation();
	   break;
	 case LEGACY:
	 case OTHER_AUTHORED:
	 case OTHER_EDITED:
	   pub->EditorList.clear();
	   pub->TranslatorList.clear();
	   pub->Journal = Blank;
	   pub->Volume = Blank;
	   pub->Issue = Blank;
	   pub->URL = Blank;
	   pub->BookTitle = Blank;
	   pub->Edition = Blank;
	   pub->NumVolumes = Blank;
	   pub->VolumeTitle = Blank;
	   pub->SeriesTitle = Blank;
	   pub->SeriesNumber = Blank;
	   pub->OrigLang = Blank;
	   pub->Pages = Blank;
	   pub->CitationNumber = Blank;
	   pub->Publisher = Blank;
	   pub->University = Blank;
	   pub->City = Blank;
	   pub->State = Blank;
	   pub->Country = Blank;
	   pub->Citation = FormatOtherCitation();
	   break;
	 case WEBSITE:
	   pub->EditorList.clear();
	   pub->TranslatorList.clear();
	   pub->Journal = Blank;
	   pub->Volume = Blank;
	   pub->Issue = Blank;
	   pub->DOI = Blank;
	   pub->BookTitle = Blank;
	   pub->Edition = Blank;
	   pub->NumVolumes = Blank;
	   pub->VolumeTitle = Blank;
	   pub->SeriesTitle = Blank;
	   pub->SeriesNumber = Blank;
	   pub->OrigLang = Blank;
	   pub->Pages = Blank;
	   pub->CitationNumber = Blank;
	   pub->Publisher = Blank;
	   pub->University = Blank;
	   pub->City = Blank;
	   pub->State = Blank;
	   pub->Country = Blank;
	   pub->Citation = FormatWebsiteCitation();
	   break;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TPubForm::Splitter1CanResize(TObject *Sender, int &NewSize, bool &Accept)
{
   if (NewSize < (Splitter1->MinSize + 1) || NewSize > (Panel5->Height - 35))
	 Accept = false;
}
//---------------------------------------------------------------------------

// upload publication
void __fastcall TPubForm::cxButton3Click(TObject *Sender)
{
   return;
}
//---------------------------------------------------------------------------

void TPubForm::UploadPub(void)
{
   vector<int> NewPubIDs;
   vector<int> NewPubAuthIDs;
   vector<int> NewPubEdIDs;
   vector<int> NewPubTransIDs;
   UnicodeString ErrorMsg;

   //if (pub->AuthorList.size() == 0) {
   //	 MessageDlg(L"Cannot upload publication with no authors.", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
   //	 return;
   //	 }

   CleanUp();
   // First get Neotoma ContactID's for authors
   if (!GetContactIDs(false))
	 return;

   // check if pub already in database
   GetNeotomaPublicationID();
   if (pub->NeotomaID > -1) {
	 MessageDlg(L"Publication already in Neotoma! Upload aborted.", mtInformation, TMsgDlgButtons() << mbOK, 0);
	 return;
	 }

   Screen->Cursor = crHourGlass;

   InsertData InsertPublication(L"InsertPublication", 23, ipsHTTPS1, ipsJSONS1, TcpClient1);
   StatusBar1->SimpleText = L"InsertPublication";

   InsertPublication.Add(L"PUBTYPEID", pub->pub_type, -1);
   InsertPublication.Add(L"YEAR", pub->PublicationYear);
   InsertPublication.Add(L"CITATION", pub->Citation);
   InsertPublication.Add(L"TITLE", pub->Title);
   InsertPublication.Add(L"JOURNAL", pub->Journal);
   InsertPublication.Add(L"VOL", pub->Volume);
   InsertPublication.Add(L"ISSUE", pub->Issue);
   InsertPublication.Add(L"PAGES", pub->Pages);
   InsertPublication.Add(L"CITNUMBER", pub->CitationNumber);
   InsertPublication.Add(L"DOI", pub->DOI);
   InsertPublication.Add(L"BOOKTITLE", pub->BookTitle);
   InsertPublication.Add(L"NUMVOL", pub->NumVolumes);
   InsertPublication.Add(L"EDITION", pub->Edition);
   InsertPublication.Add(L"VOLTITLE", pub->VolumeTitle);
   InsertPublication.Add(L"SERTITLE", pub->SeriesTitle);
   InsertPublication.Add(L"SERVOL", pub->SeriesNumber);
   switch (pub->pub_type) {
	 case DOCTORAL_THESIS:
	 case MASTERS_THESIS:
	 case UNDERGRAD_THESIS:
	   InsertPublication.Add(L"PUBLISHER", pub->University);
	   break;
	 default:
	   InsertPublication.Add(L"PUBLISHER", pub->Publisher);
	   break;
	 }
   InsertPublication.Add(L"URL", pub->URL);
   InsertPublication.Add(L"CITY", pub->City);
   InsertPublication.Add(L"STATE", pub->State);
   InsertPublication.Add(L"COUNTRY", pub->Country);
   InsertPublication.Add(L"ORIGLANG", pub->OrigLang);
   InsertPublication.Add(L"NOTES", pub->Notes);

   Screen->Cursor = crHourGlass;
   InsertPublication.PostData();

   if (InsertPublication.Post(NewPubIDs, ErrorMsg)) {
	 if (NewPubIDs.size() > 0) {
	   int NewPubID = NewPubIDs[0];
	   int Order = 1;
	   bool success = true;
	   InsertData InsertPublicationAuthors(L"InsertPublicationAuthors", 6, ipsHTTPS1, ipsJSONS1, TcpClient1);
	   StatusBar1->SimpleText = L"InsertPublicationAuthors";
	   for (unsigned int i=0; i<pub->AuthorList.size(); i++) {
		 InsertPublicationAuthors.Add(L"PUBLICATIONID", NewPubID, -1);
		 InsertPublicationAuthors.Add(L"AUTHORORDER", Order++, -1);
		 InsertPublicationAuthors.Add(L"FAMILYNAME", pub->AuthorList[i].LastName);
		 InsertPublicationAuthors.Add(L"INITIALS", pub->AuthorList[i].Initials);
		 InsertPublicationAuthors.Add(L"SUFFIX", pub->AuthorList[i].Suffix);
		 InsertPublicationAuthors.Add(L"CONTACTID", pub->AuthorList[i].NeotomaContactID, -1);
		 }
	   InsertPublicationAuthors.PostData();
	   if (!InsertPublicationAuthors.Post(NewPubAuthIDs, ErrorMsg)) {
		 success = false;
		 if (!ErrorMsg.IsEmpty())
		   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 }

	   if (success && pub->EditorList.size() > 0) {
		 Order = 1;
		 InsertData InsertPublicationEditors(L"InsertPublicationEditors", 5, ipsHTTPS1, ipsJSONS1, TcpClient1);
		 StatusBar1->SimpleText = L"InsertPublicationEditors";
		 for (unsigned int i=0; i<pub->EditorList.size(); i++) {
		   InsertPublicationEditors.Add(L"PUBLICATIONID", NewPubID, -1);
		   InsertPublicationEditors.Add(L"EDITORORDER", Order++, -1);
		   InsertPublicationEditors.Add(L"FAMILYNAME", pub->EditorList[i].LastName);
		   InsertPublicationEditors.Add(L"INITIALS", pub->EditorList[i].Initials);
		   InsertPublicationEditors.Add(L"SUFFIX", pub->EditorList[i].Suffix);
		   }
		 InsertPublicationEditors.PostData();
		 if (!InsertPublicationEditors.Post(NewPubEdIDs, ErrorMsg)) {
		   success = false;
		   if (!ErrorMsg.IsEmpty())
			 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   }
		 }

	   if (success && pub->TranslatorList.size() > 0) {
		 Order = 1;
		 InsertData InsertPublicationTranslators(L"InsertPublicationTranslators", 5, ipsHTTPS1, ipsJSONS1, TcpClient1);
		 StatusBar1->SimpleText = L"InsertPublicationTranslators";
		 for (unsigned int i=0; i<pub->TranslatorList.size(); i++) {
		   InsertPublicationTranslators.Add(L"PUBLICATIONID", NewPubID, -1);
		   InsertPublicationTranslators.Add(L"TRANSLATORORDER", Order++, -1);
		   InsertPublicationTranslators.Add(L"FAMILYNAME", pub->TranslatorList[i].LastName);
		   InsertPublicationTranslators.Add(L"INITIALS", pub->TranslatorList[i].Initials);
		   InsertPublicationTranslators.Add(L"SUFFIX", pub->TranslatorList[i].Suffix);
		   }
		 InsertPublicationTranslators.PostData();
		 if (!InsertPublicationTranslators.Post(NewPubTransIDs, ErrorMsg)) {
		   success = false;
		   if (!ErrorMsg.IsEmpty())
			 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   }
		 }

	   if (success) {
		 pub->NeotomaID = NewPubID;
		 LabelNeotomaPubID->Visible =  true;
		 Panel10->Visible = true;
		 cxNeotomaPubIDEdit->Text = IntToStr(NewPubID);
		 SetNavigationButtons();
		 cxButton3->Caption = L"Update";
		 Style = EDITPUB;
		 UnicodeString msg = L"Publication successfully uploaded. ID = " + IntToStr(NewPubID);
		 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
		 }
	   }
	 }
   else if (!ErrorMsg.IsEmpty())
	 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
   Screen->Cursor = crDefault;
}
//---------------------------------------------------------------------------

bool TPubForm::GetContactIDs(bool AlwaysReset)
{
   bool ContactIDsSet = false;

   if (AlwaysReset) {
	 for (unsigned int i=0; i<pub->AuthorList.size(); i++)
	   pub->AuthorList[i].NeotomaContactID = -1;
	 }
   else {
	 for (unsigned int i=0; i<pub->AuthorList.size(); i++) {
	   if (pub->AuthorList[i].NeotomaContactID > -1) {
		 ContactIDsSet = true;
		 break;
		 }
	   }
	 if (ContactIDsSet) {
	   if (MessageDlg(L"Author contacts are already set. Do you want to reset them?",
		 mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes)
		 {
		 for (unsigned int i=0; i<pub->AuthorList.size(); i++)
		   pub->AuthorList[i].NeotomaContactID = -1;
		 ContactIDsSet = false;
		 }
	   }
	 }

   if (!ContactIDsSet) {
	 bool found = false;
	 TUploadAuthorForm* UploadAuthorForm = new TUploadAuthorForm(pub->AuthorList, ContactList, this);
	 if (UploadAuthorForm->ShowModal() == mrOk) {
	   pub->AuthorList.clear();
	   //pub->AuthorList.assign(UploadAuthorForm->AuthorList.begin(), UploadAuthorForm->AuthorList.end());
	   vector<AUTHOR>::iterator itr;
	   vector<AUTHOR>::iterator begin = UploadAuthorForm->AuthorList.begin();
	   vector<AUTHOR>::iterator end = UploadAuthorForm->AuthorList.end();
	   for (itr = begin; itr != end; itr++) {
		 if (!itr->LastName.IsEmpty())
		   pub->AuthorList.push_back(*itr);
		 }
	   found = true;
	   }
	 delete UploadAuthorForm;
	 if (!found) {
	   MessageDlg(L"Author contacts not set! Upload aborted.", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return false;
	   }
	 }
   return true;
}
//---------------------------------------------------------------------------

// first PublicationID
void __fastcall TPubForm::cxButtonFirstClick(TObject *Sender)
{
   return;
}
//---------------------------------------------------------------------------

// previous PublicationID
void __fastcall TPubForm::cxButtonPrevClick(TObject *Sender)
{
   return;
}
//---------------------------------------------------------------------------

// next PublicationID
void __fastcall TPubForm::cxButtonNextClick(TObject *Sender)
{
   return;
}
//---------------------------------------------------------------------------

// last PublicationID
void __fastcall TPubForm::cxButtonLastClick(TObject *Sender)
{
   return;
}
//---------------------------------------------------------------------------

void __fastcall TPubForm::AdvMultiColumnDropDown1Select(TObject *Sender)
{
   return;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

__fastcall TStewardPubForm::TStewardPubForm(PUBLICATION *p, short style,
	TContactList* contact_list, TComponent* Owner) : TPubForm(p, Owner)
{
   Style = style;
   ContactList = contact_list;
   local_pub = false;
   AlwaysShowPubID = true;
   PubTypeID = -1;

   switch (Style) {
	 case NEWPUB:
	   Caption = L"New Publication";
	   if (pub == NULL) {
		 pub = new PUBLICATION(JOURNAL_ARTICLE);
		 local_pub = true;
		 cxButton9->Visible = false;
		 cxButton1->Caption = L"Close";
		 cxButton1->ModalResult = mrClose;
		 }
	   break;
	 case EDITPUB:
	   Caption = L"Edit Publication";
	   if (pub->NeotomaID == -1)
		 Style = NEWPUB;
	   else
		 cxButton3->Caption = L"Update";
	   break;
	 }

   cxButton4->Visible = true;

   Panel10->Visible = true;
   cxButton3->Visible = true;
   FlowPanel3->Visible = true;
   SetFlowPanel1Position();
   GetPublicationTypes();
}
//---------------------------------------------------------------------------

__fastcall TStewardPubForm::~TStewardPubForm()
{
   if (local_pub)
	 delete pub;
}
//---------------------------------------------------------------------------

void TStewardPubForm::SetNavigationButtons(void)
{
   if (!FlowPanel3->Visible) return;

   if (!cxNeotomaPubIDEdit->Text.IsEmpty() && pub != NULL && pub->NeotomaID > -1) {
	 cxButtonFirst->Enabled = (pub->NeotomaID > MinPubID);
	 cxButtonPrev->Enabled = (pub->NeotomaID > MinPubID);
	 cxButtonLast->Enabled = (pub->NeotomaID < MaxPubID);
	 cxButtonNext->Enabled = (pub->NeotomaID < MaxPubID);
	 }
   else if (cxNeotomaPubIDEdit->Text.IsEmpty()) {
	 cxButtonFirst->Enabled = true;
	 cxButtonPrev->Enabled = false;
	 cxButtonNext->Enabled = false;
	 cxButtonLast->Enabled = true;
	 }
   else {   // this should never happen, but...
	 cxButtonFirst->Enabled = false;
	 cxButtonPrev->Enabled = false;
	 cxButtonNext->Enabled = false;
	 cxButtonLast->Enabled = false;
	 }
}
//---------------------------------------------------------------------------

void TStewardPubForm::GetPublicationTypes(void)
{
   Advmulticolumndropdown::TDropDownItem *Item;
   Item = AdvMultiColumnDropDown1->Items->Add();
   Item->Text->Add(L"");
   Item->Text->Add(L"All types");

   Screen->Cursor = crHourGlass;
   NeotomaPublicationTypesTable PubTypesTable(ipsJSONS1, TcpClient1);
   StatusBar1->SimpleText = PubTypesTable.WebServiceName();
   if (PubTypesTable.Execute()) {
	 map<int,UnicodeString>::iterator itr;
	 map<int,UnicodeString>::iterator begin = PubTypesTable.Items.begin();
	 map<int,UnicodeString>::iterator end = PubTypesTable.Items.end();
	 for (itr = begin; itr != end; itr++) {
	   Advmulticolumndropdown::TDropDownItem *Item;
	   Item = AdvMultiColumnDropDown1->Items->Add();
	   Item->Text->Add(itr->first);
	   Item->Text->Add(itr->second);
	   }
	 }
   AdvMultiColumnDropDown1->ItemIndex = 0;
   GetTableMinPubID();
   GetTableMaxPubID();
   Screen->Cursor = crDefault;
}
//---------------------------------------------------------------------------

void TStewardPubForm::GetTableMinPubID(void)
{
   NeotomaTableMinID GetMinPubID(ipsJSONS1, TcpClient1);
   GetMinPubID.AddParam(L"TABLENAME", UnicodeString(L"NDB.Publications"));
   GetMinPubID.AddParam(L"COLUMNNAME", UnicodeString(L"NDB.Publications.PublicationID"));
   StatusBar1->SimpleText = GetMinPubID.WebServiceName();
   if (GetMinPubID.Execute())
	 MinPubID = GetMinPubID.Items[0];
   else
	 MinPubID = -1;
}
//---------------------------------------------------------------------------

void TStewardPubForm::GetTableMaxPubID(void)
{
   NeotomaTableMaxID GetMaxPubID(ipsJSONS1, TcpClient1);
   GetMaxPubID.AddParam(L"TABLENAME", UnicodeString(L"NDB.Publications"));
   GetMaxPubID.AddParam(L"COLUMNNAME", UnicodeString(L"NDB.Publications.PublicationID"));
   StatusBar1->SimpleText = GetMaxPubID.WebServiceName();
   if (GetMaxPubID.Execute())
	 MaxPubID = GetMaxPubID.Items[0];
   else
	 MaxPubID = -1;
}
//---------------------------------------------------------------------------

void TStewardPubForm::GetMinPubIDByPubIDType(int PubTypeID)
{
   NeotomaGetMinPubIDByPubIDType GetMinPubID(ipsJSONS1, TcpClient1);
   GetMinPubID.AddParam(L"PUBTYPEID", PubTypeID);
   StatusBar1->SimpleText = GetMinPubID.WebServiceName();
   if (GetMinPubID.Execute())
	 MinPubID = GetMinPubID.Items[0];
   else
	 MinPubID = -1;
}
//---------------------------------------------------------------------------

void TStewardPubForm::GetMaxPubIDByPubIDType(int PubTypeID)
{
   NeotomaGetMaxPubIDByPubIDType GetMaxPubID(ipsJSONS1, TcpClient1);
   GetMaxPubID.AddParam(L"PUBTYPEID", PubTypeID);
   StatusBar1->SimpleText = GetMaxPubID.WebServiceName();
   if (GetMaxPubID.Execute())
	 MaxPubID = GetMaxPubID.Items[0];
   else
	 MaxPubID = -1;
}
//---------------------------------------------------------------------------


// get Neotoma publication
void __fastcall TStewardPubForm::NeotomaButtonClick(TObject *Sender)
{
   if (!local_pub && pub->AuthorList.size() > 0 && !pub->PublicationYear.IsEmpty())  // author and year entered
	 GetNeotomaPublicationID();
   else
	 GetNeotomaPublication();

   // if (Panel10->Visible) [  // a Neotoma pub has been found
   if (!cxNeotomaPubIDEdit->Text.IsEmpty()) {
	 cxButton3->Caption = L"Update";
	 Style = EDITPUB;
	 if (cxButton3->Visible)
	   cxButton3->Enabled = true;
	 }
   else
	 cxButton3->Enabled = false;
}
//---------------------------------------------------------------------------

// upload publication
void __fastcall TStewardPubForm::cxButton3Click(TObject *Sender)
{
   if (!Login->IsLoggedIn) {
	 NeotomaLoginForm = new TNeotomaLoginForm(this);
	 NeotomaLoginForm->ShowModal();
	 delete NeotomaLoginForm;
	 }
   if (Login->IsLoggedIn) {
	 switch (Style) {
	   case NEWPUB:
		 UploadPub();
		 if (pub->NeotomaID > -1) {
		   cxButton3->Caption = L"Update";
		   Style = EDITPUB;
		   }
		 break;
	   case EDITPUB:
		 UpdatePub();
		 break;
	   }
	 Screen->Cursor = crDefault;
	 }
}
//---------------------------------------------------------------------------

void TStewardPubForm::UpdatePub(void)
{
   UnicodeString ErrorMsg;
   bool error = false;

   if (pub->NeotomaID == -1) {
	 MessageDlg(L"PublicationID not acquired. Cannot update.", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 return;
	 }

   if (!Login->IsLoggedIn) {
	 NeotomaLoginForm = new TNeotomaLoginForm(this);
	 NeotomaLoginForm->ShowModal();
	 delete NeotomaLoginForm;
	 }
   if (Login->IsLoggedIn) {
	 CleanUp();
	 Screen->Cursor = crHourGlass;
	 NeotomaPublicationAuthors NeotomaPubAuthors(ipsJSONS1, TcpClient1);
	 NeotomaPubAuthors.AddParam(L"PUBLICATIONID", pub->NeotomaID);
	 StatusBar1->SimpleText = NeotomaPubAuthors.WebServiceName();
	 if (NeotomaPubAuthors.Execute()) {
	   set<int> AuthorIDs;
	   UnicodeString RevalidateMsg = L"Authors must be revalidated with Neotoma contacts.";

	   if (pub->AuthorList.size() == 0) {
		 if (NeotomaPubAuthors.Size() > 0) {
		   for (unsigned int i=0; i<NeotomaPubAuthors.Size(); i++) {
			 DeleteData DeletePubAuth(L"DeletePublicationAuthor", 1, ipsHTTPS1, ipsJSONS1, TcpClient1);
			 StatusBar1->SimpleText = L"DeletePublicationAuthor";
			 DeletePubAuth.Add(L"AuthorID", NeotomaPubAuthors.Items[i].AuthorID);
			 if (!DeletePubAuth.Post(ErrorMsg)) {
			   UnicodeString msg = L"Update aborted";
			   if (!ErrorMsg.IsEmpty())
				 msg += (L": " + ErrorMsg);
			   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			   error = true;
			   break;
			   }
			 }
		   }
		 }
	   else {
		 if (MessageDlg(RevalidateMsg, mtInformation, TMsgDlgButtons() << mbOK << mbCancel, 0) == mrCancel) {
		   MessageDlg(L"Update canceled!", mtInformation, TMsgDlgButtons() << mbOK, 0);
		   Screen->Cursor = crDefault;
		   return;
		   }

		 if (GetContactIDs(true)) {
		   Screen->Cursor = crHourGlass;
		   for (unsigned int i=0; i<NeotomaPubAuthors.Size(); i++)
			 AuthorIDs.insert(NeotomaPubAuthors.Items[i].AuthorID);
		   if (UpdateAuthors(AuthorIDs)) {
			 if (NeotomaPubAuthors.Size() < pub->AuthorList.size()) {
			   // upload additional authors to Neotoma
			   int begin = NeotomaPubAuthors.Size();
			   int end = pub->AuthorList.size();

			   InsertData InsertPublicationAuthors(L"InsertPublicationAuthors", 6, ipsHTTPS1, ipsJSONS1, TcpClient1);
			   StatusBar1->SimpleText = L"InsertPublicationAuthors";
			   for (int i=begin; i<end; i++) {
				 int order = i+1;
				 InsertPublicationAuthors.Add(L"PUBLICATIONID", pub->NeotomaID, -1);
				 InsertPublicationAuthors.Add(L"AUTHORORDER", order, -1);
				 InsertPublicationAuthors.Add(L"FAMILYNAME", pub->AuthorList[i].LastName);
				 InsertPublicationAuthors.Add(L"INITIALS", pub->AuthorList[i].Initials);
				 InsertPublicationAuthors.Add(L"SUFFIX", pub->AuthorList[i].Suffix);
				 InsertPublicationAuthors.Add(L"CONTACTID", pub->AuthorList[i].NeotomaContactID, -1);
				 }
			   InsertPublicationAuthors.PostData();
			   vector<int> newids;
			   if (!InsertPublicationAuthors.Post(newids, ErrorMsg)) {
				 UnicodeString msg = L"Update aborted";
				 if (!ErrorMsg.IsEmpty())
				   msg += (L": " + ErrorMsg);
				 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
				 error = true;
				 }
			   }
			 else if (NeotomaPubAuthors.Size() > pub->AuthorList.size()) {
			   // delete surplus authors from Neotoma
			   int begin = pub->AuthorList.size();
			   int end = NeotomaPubAuthors.Size();
			   for (int i=begin; i<end; i++) {
				 DeleteData DeletePubAuth(L"DeletePublicationAuthor", 1, ipsHTTPS1, ipsJSONS1, TcpClient1);
				 StatusBar1->SimpleText = L"DeletePublicationAuthor";
				 DeletePubAuth.Add(L"AuthorID", NeotomaPubAuthors.Items[i].AuthorID);
				 if (!DeletePubAuth.Post(ErrorMsg)) {
				   UnicodeString msg = L"Update aborted";
				   if (!ErrorMsg.IsEmpty())
					 msg += (L": " + ErrorMsg);
				   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
				   error = true;
				   break;
				   }
				 }
			   }
			 }
		   else
			 error = true;
		   }
		 else
		   error = true;
		 }
	   }

	 if (error) {
	   Screen->Cursor = crDefault;
	   return;
	   }

	 // update editors
	 Screen->Cursor = crHourGlass;
	 NeotomaPublicationEditors NeotomaEditors(ipsJSONS1, TcpClient1);
	 NeotomaEditors.AddParam(L"PUBLICATIONID", pub->NeotomaID);
	 StatusBar1->SimpleText = NeotomaEditors.WebServiceName();
	 if (NeotomaEditors.Execute()) {
	   set<int> EditorIDs;

	   if (pub->EditorList.size() == 0) {
		 if (NeotomaEditors.Size() > 0) {
		   for (unsigned int i=0; i<NeotomaEditors.Size(); i++) {
			 DeleteData DeletePubEditor(L"DeletePublicationEditor", 1, ipsHTTPS1, ipsJSONS1, TcpClient1);
			 StatusBar1->SimpleText = L"DeletePublicationEditor";
			 DeletePubEditor.Add(L"EditorID", NeotomaEditors.Items[i].EditorID);
			 if (!DeletePubEditor.Post(ErrorMsg)) {
			   UnicodeString msg = L"Update aborted";
			   if (!ErrorMsg.IsEmpty())
				 msg += (L": " + ErrorMsg);
			   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			   error = true;
			   break;
			   }
			 }
		   }
		 }
	   else {
		 Screen->Cursor = crHourGlass;
		 for (unsigned int i=0; i<NeotomaEditors.Size(); i++)
		   EditorIDs.insert(NeotomaEditors.Items[i].EditorID);
		 if (UpdateEditors(EditorIDs)) {
		   if (NeotomaEditors.Size() < pub->EditorList.size()) {
			 // upload additional editors to Neotoma
			 int begin = NeotomaEditors.Size();
			 int end = pub->EditorList.size();

			 InsertData InsertPublicationEditors(L"InsertPublicationEditors", 5, ipsHTTPS1, ipsJSONS1, TcpClient1);
			 StatusBar1->SimpleText = L"InsertPublicationEditors";
			 for (int i=begin; i<end; i++) {
			   int order = i+1;
			   InsertPublicationEditors.Add(L"PUBLICATIONID", pub->NeotomaID, -1);
			   InsertPublicationEditors.Add(L"EDITORORDER", order, -1);
			   InsertPublicationEditors.Add(L"FAMILYNAME", pub->EditorList[i].LastName);
			   InsertPublicationEditors.Add(L"INITIALS", pub->EditorList[i].Initials);
			   InsertPublicationEditors.Add(L"SUFFIX", pub->EditorList[i].Suffix);
			   }
			 InsertPublicationEditors.PostData();
			 vector<int> newids;
			 if (!InsertPublicationEditors.Post(newids, ErrorMsg)) {
			   UnicodeString msg = L"Update aborted";
			   if (!ErrorMsg.IsEmpty())
				 msg += (L": " + ErrorMsg);
			   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			   error = true;
			   }
			 }
		   else if (NeotomaEditors.Size() > pub->EditorList.size()) {
			 int begin = pub->EditorList.size();
			 int end = NeotomaEditors.Size();

			 for (int i=begin; i<end; i++) {
			   DeleteData DeletePubEditor(L"DeletePublicationEditor", 1, ipsHTTPS1, ipsJSONS1, TcpClient1);
			   StatusBar1->SimpleText = L"DeletePublicationEditor";
			   DeletePubEditor.Add(L"EditorID", NeotomaEditors.Items[i].EditorID);
			   if (!DeletePubEditor.Post(ErrorMsg)) {
				 UnicodeString msg = L"Update aborted";
				 if (!ErrorMsg.IsEmpty())
				   msg += (L": " + ErrorMsg);
				 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
				 error = true;
				 break;
				 }
			   }
			 }
		   }
		 else
		   error = true;
		 }
	   }

	 if (error) {
	   Screen->Cursor = crDefault;
	   return;
	   }

	 // update translators
	 Screen->Cursor = crHourGlass;
	 NeotomaPublicationTranslators NeotomaTranslators(ipsJSONS1, TcpClient1);
	 NeotomaTranslators.AddParam(L"PUBLICATIONID", pub->NeotomaID);
	 StatusBar1->SimpleText = NeotomaTranslators.WebServiceName();
	 if (NeotomaTranslators.Execute()) {
	   set<int> TranslatorIDs;

	   if (pub->TranslatorList.size() == 0) {
		 if (NeotomaTranslators.Size() > 0) {
		   for (unsigned int i=0; i<NeotomaTranslators.Size(); i++) {
			 DeleteData DeletePubTranslator(L"DeletePublicationTranslator", 1, ipsHTTPS1, ipsJSONS1, TcpClient1);
			 StatusBar1->SimpleText = L"DeletePublicationTranslator";
			 DeletePubTranslator.Add(L"TranslatorID", NeotomaTranslators.Items[i].TranslatorID);
			 if (!DeletePubTranslator.Post(ErrorMsg)) {
			   UnicodeString msg = L"Update aborted";
			   if (!ErrorMsg.IsEmpty())
				 msg += (L": " + ErrorMsg);
			   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			   error = true;
			   break;
			   }
			 }
		   }
		 }
	   else {
		 Screen->Cursor = crHourGlass;
		 for (unsigned int i=0; i<NeotomaTranslators.Size(); i++)
		   TranslatorIDs.insert(NeotomaTranslators.Items[i].TranslatorID);
		 if (UpdateTranslators(TranslatorIDs)) {
		   if (NeotomaTranslators.Size() < pub->TranslatorList.size()) {
			 // upload additional translators to Neotoma
			 int begin = NeotomaTranslators.Size();
			 int end = pub->TranslatorList.size();

			 InsertData InsertPublicationTranslators(L"InsertPublicationTranslators", 5, ipsHTTPS1, ipsJSONS1, TcpClient1);
			 StatusBar1->SimpleText = L"InsertPublicationTranslators";
			 for (int i=begin; i<end; i++) {
			   int order = i+1;
			   InsertPublicationTranslators.Add(L"PUBLICATIONID", pub->NeotomaID, -1);
			   InsertPublicationTranslators.Add(L"TRANSLATORORDER", order, -1);
			   InsertPublicationTranslators.Add(L"FAMILYNAME", pub->TranslatorList[i].LastName);
			   InsertPublicationTranslators.Add(L"INITIALS", pub->TranslatorList[i].Initials);
			   InsertPublicationTranslators.Add(L"SUFFIX", pub->TranslatorList[i].Suffix);
			   }
			 InsertPublicationTranslators.PostData();
			 vector<int> newids;
			 if (!InsertPublicationTranslators.Post(newids, ErrorMsg)) {
			   UnicodeString msg = L"Update aborted";
			   if (!ErrorMsg.IsEmpty())
				 msg += (L": " + ErrorMsg);
			   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			   error = true;
			   }
			 }
		   else if (NeotomaTranslators.Size() > pub->TranslatorList.size()) {
			 int begin = pub->TranslatorList.size();
			 int end = NeotomaTranslators.Size();

			 for (int i=begin; i<end; i++) {
			   DeleteData DeletePubTranslator(L"DeletePublicationTranslator", 1, ipsHTTPS1, ipsJSONS1, TcpClient1);
			   StatusBar1->SimpleText = L"DeletePublicationTranslator";
			   DeletePubTranslator.Add(L"TranslatorID", NeotomaTranslators.Items[i].TranslatorID);
			   if (!DeletePubTranslator.Post(ErrorMsg)) {
				 UnicodeString msg = L"Update aborted";
				 if (!ErrorMsg.IsEmpty())
				   msg += (L": " + ErrorMsg);
				 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
				 error = true;
				 break;
				 }
			   }
			 }
		   }
		 else
		   error = true;
		 }
	   }

	 if (error) {
	   Screen->Cursor = crDefault;
	   return;
	   }

	 UpdateData UpdatePub(L"UpdatePublication", 24, ipsHTTPS1, ipsJSONS1, TcpClient1);
	 StatusBar1->SimpleText = L"UpdatePublication";
	 UpdatePub.Add(L"PUBLICATIONID", pub->NeotomaID);
	 UpdatePub.Add(L"PUBTYPEID", pub->pub_type);
	 UpdatePub.Add(L"YEAR", pub->PublicationYear);
	 UpdatePub.Add(L"CITATION", pub->Citation);
	 UpdatePub.Add(L"TITLE", pub->Title);
	 UpdatePub.Add(L"JOURNAL", pub->Journal);
	 UpdatePub.Add(L"VOL", pub->Volume);
	 UpdatePub.Add(L"ISSUE", pub->Issue);
	 UpdatePub.Add(L"PAGES", pub->Pages);
	 UpdatePub.Add(L"CITNUMBER", pub->CitationNumber);
	 UpdatePub.Add(L"DOI", pub->DOI);
	 UpdatePub.Add(L"BOOKTITLE", pub->BookTitle);
	 UpdatePub.Add(L"NUMVOL", pub->NumVolumes);
	 UpdatePub.Add(L"EDITION", pub->Edition);
	 UpdatePub.Add(L"VOLTITLE", pub->VolumeTitle);
	 UpdatePub.Add(L"SERTITLE", pub->SeriesTitle);
	 UpdatePub.Add(L"SERVOL", pub->SeriesNumber);
	 switch (pub->pub_type) {
	   case DOCTORAL_THESIS:
	   case MASTERS_THESIS:
	   case UNDERGRAD_THESIS:
		 UpdatePub.Add(L"PUBLISHER", pub->University);
		 break;
	   default:
		 UpdatePub.Add(L"PUBLISHER", pub->Publisher);
		 break;
	   }
	 UpdatePub.Add(L"URL", pub->URL);
	 UpdatePub.Add(L"CITY", pub->City);
	 UpdatePub.Add(L"STATE", pub->State);
	 UpdatePub.Add(L"COUNTRY", pub->Country);
	 UpdatePub.Add(L"ORIGLANG", pub->OrigLang);
	 UpdatePub.Add(L"NOTES", pub->Notes);

	 if (UpdatePub.Post(ErrorMsg))
	   MessageDlg(L"Success: Publication updated!", mtInformation, TMsgDlgButtons() << mbOK, 0);
	 else if (!ErrorMsg.IsEmpty())
	   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 StatusBar1->SimpleText = L"";
	 Screen->Cursor = crDefault;
	 }

   if (PubTypeID != -1 && pub->NeotomaID == MinPubID)
	 GetMinPubIDByPubIDType(PubTypeID);
   else if (PubTypeID != -1 && pub->NeotomaID == MaxPubID)
	 GetMaxPubIDByPubIDType(PubTypeID);
}
//---------------------------------------------------------------------------

bool TStewardPubForm::UpdateAuthors(set<int> AuthorIDs)
{
   UnicodeString ErrorMsg;

   set<int>::iterator itr = AuthorIDs.begin();
   unsigned int size = Math::Min((int)pub->AuthorList.size(), (int)AuthorIDs.size());
   for (unsigned int i=0; i<size; i++) {
	 int order = i+1;
	 UpdateData UpdatePubAuthors(L"UpdatePublicationAuthor", 7, ipsHTTPS1, ipsJSONS1, TcpClient1);
	 StatusBar1->SimpleText = L"UpdatePublicationAuthor";
	 UpdatePubAuthors.Add(L"AUTHORID", *itr);
	 itr++;
	 UpdatePubAuthors.Add(L"PUBLICATIONID", pub->NeotomaID);
	 UpdatePubAuthors.Add(L"AUTHORORDER", order);
	 UpdatePubAuthors.Add(L"FAMILYNAME", pub->AuthorList[i].LastName);
	 UpdatePubAuthors.Add(L"INITIALS", pub->AuthorList[i].Initials);
	 UpdatePubAuthors.Add(L"SUFFIX", pub->AuthorList[i].Suffix);
	 UpdatePubAuthors.Add(L"CONTACTID", pub->AuthorList[i].NeotomaContactID);
	 if (!UpdatePubAuthors.Post(ErrorMsg)) {
	   UnicodeString msg = L"Update aborted";
	   if (!ErrorMsg.IsEmpty())
		 msg += (L": " + ErrorMsg);
	   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return false;
	   }
	 }
   return true;
}
//---------------------------------------------------------------------------

bool TStewardPubForm::UpdateEditors(set<int> EditorIDs)
{
   UnicodeString ErrorMsg;

   set<int>::iterator itr = EditorIDs.begin();
   unsigned int size = Math::Min((int)pub->EditorList.size(), (int)EditorIDs.size());
   for (unsigned int i=0; i<size; i++) {
	 int order = i+1;
	 UpdateData UpdatePubEditors(L"UpdatePublicationEditor", 6, ipsHTTPS1, ipsJSONS1, TcpClient1);
	 StatusBar1->SimpleText = L"UpdatePublicationEditor";
	 UpdatePubEditors.Add(L"EDITORID", *itr);
	 itr++;
	 UpdatePubEditors.Add(L"PUBLICATIONID", pub->NeotomaID);
	 UpdatePubEditors.Add(L"EDITORORDER", order);
	 UpdatePubEditors.Add(L"FAMILYNAME", pub->EditorList[i].LastName);
	 UpdatePubEditors.Add(L"INITIALS", pub->EditorList[i].Initials);
	 UpdatePubEditors.Add(L"SUFFIX", pub->EditorList[i].Suffix);
	 if (!UpdatePubEditors.Post(ErrorMsg)) {
	   UnicodeString msg = L"Update aborted";
	   if (!ErrorMsg.IsEmpty())
		 msg += (L": " + ErrorMsg);
	   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return false;
	   }
	 }

   return true;
}
//---------------------------------------------------------------------------

bool TStewardPubForm::UpdateTranslators(set<int> TranslatorIDs)
{
   UnicodeString ErrorMsg;

   set<int>::iterator itr = TranslatorIDs.begin();
   unsigned int size = Math::Min((int)pub->TranslatorList.size(), (int)TranslatorIDs.size());
   for (unsigned int i=0; i<size; i++) {
	 int order = i+1;
	 UpdateData UpdatePubTranslators(L"UpdatePublicationTranslator", 6, ipsHTTPS1, ipsJSONS1, TcpClient1);
	 StatusBar1->SimpleText = L"UpdatePublicationTranslator";
	 UpdatePubTranslators.Add(L"TRANSLATORID", *itr);
	 itr++;
	 UpdatePubTranslators.Add(L"PUBLICATIONID", pub->NeotomaID);
	 UpdatePubTranslators.Add(L"TRANSLATORORDER", order);
	 UpdatePubTranslators.Add(L"FAMILYNAME", pub->TranslatorList[i].LastName);
	 UpdatePubTranslators.Add(L"INITIALS", pub->TranslatorList[i].Initials);
	 UpdatePubTranslators.Add(L"SUFFIX", pub->TranslatorList[i].Suffix);
	 if (!UpdatePubTranslators.Post(ErrorMsg)) {
	   UnicodeString msg = L"Update aborted";
	   if (!ErrorMsg.IsEmpty())
		 msg += (L": " + ErrorMsg);
	   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return false;
	   }
	 }

   return true;
}
//---------------------------------------------------------------------------

// first PublicationID
void __fastcall TStewardPubForm::cxButtonFirstClick(TObject *Sender)
{
   Navigate(MinPubID);
}
//---------------------------------------------------------------------------

// previous PublicationID
void __fastcall TStewardPubForm::cxButtonPrevClick(TObject *Sender)
{
   Screen->Cursor = crHourGlass;
   if (PubTypeID == -1) {
	 NeotomaPreviousPublicationByID PrevPub(ipsJSONS1, TcpClient1);
	 PrevPub.AddParam(L"PUBLICATIONID", pub->NeotomaID);
	 StatusBar1->SimpleText = PrevPub.WebServiceName();
	 if (PrevPub.Execute()) {
	   if (PrevPub.Size() > 0)
		 Navigate(PrevPub.Items[0].PublicationID);
	   }
	 }
   else {
	 NeotomaPreviousPublicationByIDAndPubTypeID PrevPub(ipsJSONS1, TcpClient1);
	 PrevPub.AddParam(L"PUBLICATIONID", pub->NeotomaID);
	 PrevPub.AddParam(L"PUBTYPEID", PubTypeID);
	 StatusBar1->SimpleText = PrevPub.WebServiceName();
	 if (PrevPub.Execute()) {
	   if (PrevPub.Size() > 0)
		 Navigate(PrevPub.Items[0].PublicationID);
	   }
	 }
}
//---------------------------------------------------------------------------

// next PublicationID
void __fastcall TStewardPubForm::cxButtonNextClick(TObject *Sender)
{
   Screen->Cursor = crHourGlass;
   if (PubTypeID == -1) {
	 NeotomaNextPublicationByID NextPub(ipsJSONS1, TcpClient1);
	 NextPub.AddParam(L"PUBLICATIONID", pub->NeotomaID);
	 StatusBar1->SimpleText = NextPub.WebServiceName();
	 if (NextPub.Execute()) {
	   if (NextPub.Size() > 0)
		 Navigate(NextPub.Items[0].PublicationID);
	   }
	 }
   else {
	 NeotomaNextPublicationByIDAndPubTypeID NextPub(ipsJSONS1, TcpClient1);
	 NextPub.AddParam(L"PUBLICATIONID", pub->NeotomaID);
	 NextPub.AddParam(L"PUBTYPEID", PubTypeID);
	 StatusBar1->SimpleText = NextPub.WebServiceName();
	 if (NextPub.Execute()) {
	   if (NextPub.Size() > 0)
		 Navigate(NextPub.Items[0].PublicationID);
	   }
	 }
}
//---------------------------------------------------------------------------

// last PublicationID
void __fastcall TStewardPubForm::cxButtonLastClick(TObject *Sender)
{
   Navigate(MaxPubID);
}
//---------------------------------------------------------------------------

// change publication type
void __fastcall TStewardPubForm::AdvMultiColumnDropDown1Select(TObject *Sender)
{
   int ItemIndex = AdvMultiColumnDropDown1->ItemIndex;
   UnicodeString Text = AdvMultiColumnDropDown1->Items->Items[ItemIndex]->Text->Strings[0];
   if (Text.IsEmpty())
	 PubTypeID = -1;
   else if (!TryStrToInt(Text, PubTypeID))
	 PubTypeID = -1;

   if (PubTypeID == -1) {
	 GetTableMinPubID();
	 GetTableMaxPubID();
	 }
   else {
	 GetMinPubIDByPubIDType(PubTypeID);
	 GetMaxPubIDByPubIDType(PubTypeID);
	 }
   Navigate(MinPubID);
}
//---------------------------------------------------------------------------


void TStewardPubForm::Navigate(int PubID)
{
   NTMPUBLICATION ntm_pub;
   vector<PUBAUTHOR> Authors;
   vector<EDITOR> Editors;
   vector<EDITOR> Translators;

   Screen->Cursor = crHourGlass;
   NeotomaPublicationsByPubID Publications(ipsJSONS1, TcpClient1);
   Publications.AddParam(L"PUBLICATIONID", PubID);
   if (Publications.Execute()) {
	 if (Publications.Size() > 0)
	   ntm_pub = Publications.Items[0];
	 else
	   return;
	 }
   else return;

   // get authors
   NeotomaPublicationAuthors GetAuthors(ipsJSONS1, TcpClient1);
   GetAuthors.AddParam(L"PUBLICATIONID", PubID);
   StatusBar1->SimpleText = GetAuthors.WebServiceName();
   if (GetAuthors.Execute()) {
	 if (GetAuthors.Size() > 0) {
	   for (unsigned int i=0; i<GetAuthors.Size(); i++) {
		 PUBAUTHOR Author;
		 Author.FamilyName = GetAuthors.Items[i].FamilyName;
		 Author.Initials = GetAuthors.Items[i].Initials;
		 Author.Suffix = GetAuthors.Items[i].Suffix;
		 Author.ContactID = GetAuthors.Items[i].ContactID;
		 Authors.push_back(Author);
		 }
	   }
	 }

   // get editors
   switch (ntm_pub.PubTypeID) {
	 case BOOK_CHAPTER:
	 case BOOKCHAPTER:
	   NeotomaPublicationEditors GetEditors(ipsJSONS1, TcpClient1);
	   GetEditors.AddParam(L"PUBLICATIONID", PubID);
	   StatusBar1->SimpleText = GetEditors.WebServiceName();
	   if (GetEditors.Execute()) {
		 if (GetEditors.Size() > 0) {
		   for (unsigned int i=0; i<GetEditors.Size(); i++) {
			 EDITOR Editor;
			 Editor.LastName = GetEditors.Items[i].FamilyName;
			 Editor.Initials = GetEditors.Items[i].Initials;
			 Editor.Suffix = GetEditors.Items[i].Suffix;
			 Editors.push_back(Editor);
			 }
		   }
		 }
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
	   NeotomaPublicationTranslators GetTranslators(ipsJSONS1, TcpClient1);
	   GetTranslators.AddParam(L"PUBLICATIONID", PubID);
	   StatusBar1->SimpleText = GetTranslators.WebServiceName();
	   if (GetTranslators.Execute()) {
		 if (GetTranslators.Size() > 0) {
		   for (unsigned int i=0; i<GetTranslators.Size(); i++) {
			 EDITOR Translator;
			 Translator.LastName = GetTranslators.Items[i].FamilyName;
			 Translator.Initials = GetTranslators.Items[i].Initials;
			 Translator.Suffix = GetTranslators.Items[i].Suffix;
			 Translators.push_back(Translator);
			 }
		   }
		 }
	   break;
	 }

   StatusBar1->SimpleText = L"";
   cxButton3->Caption = L"Update";
   Style = EDITPUB;
   pub->NeotomaID = PubID;
   pub->pub_type = ntm_pub.PubTypeID;
   pub->SetPublication(&ntm_pub, Authors, Editors, Translators);
   ClearInputForm();
   FormatInputForm();
   PopulateInputForm();
   Screen->Cursor = crDefault;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

__fastcall TValidatePubForm::TValidatePubForm(PUBLICATION *p, short style,
	TContactList* contact_list, TComponent* Owner)
	: TStewardPubForm(p, style, contact_list, Owner)
{
   Caption = L"Validate Publication";
   FlowPanel3->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TValidatePubForm::FormActivate(TObject *Sender)
{
   if (!Activated) {
	 FormatInputForm();
	 PopulateInputForm();
	 Activated = true;

	 if (pub->AuthorList.size() > 0 && !pub->PublicationYear.IsEmpty()) { // author and year entered
	   GetNeotomaPublicationID();
	   NeotomaPubSearched = true;
	   PubChanged = false;
	   }
	 //else    // TODO: deal with this: show error message
	 //  GetNeotomaPublication();

	 if (Panel10->Visible) {  // a Neotoma pub has been found
	   if (cxNeotomaPubIDEdit->Text.IsEmpty()) {
		 cxButton3->Caption = L"Upload";
		 Style = NEWPUB;
		 LabelNeotomaPubID->Visible = false;
		 Panel10->Visible = false;
		 }
	   else {
		 cxButton3->Caption = L"Update";
		 Style = EDITPUB;
		 }
	   }

	 cxButton3->Enabled = true;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TPubForm::cxButton4Click(TObject *Sender)
{
   return;
}
//---------------------------------------------------------------------------

void __fastcall TStewardPubForm::cxButton4Click(TObject *Sender)
{
   pub->NeotomaID = -1;
   cxNeotomaPubIDEdit->Text = L"";
   cxButton3->Caption = L"Upload";
   Style = NEWPUB;
   LabelNeotomaPubID->Visible = false;
   Panel10->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TPubForm::ipsJSONS1SSLServerAuthentication(TObject *Sender, TipsJSONSSSLServerAuthenticationEventParams *e)
{
   e->Accept = true;
}
//---------------------------------------------------------------------------

