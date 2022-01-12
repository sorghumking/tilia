//---------------------------------------------------------------------------

#ifndef TIPublH
#define TIPublH
#include "AdvGrid.hpp"
#include "AdvObj.hpp"
#include "BaseGrid.hpp"
#include "cxButtons.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxEdit.hpp"
#include "cxGraphics.hpp"
#include "cxGroupBox.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include "cxMemo.hpp"
#include "cxTextEdit.hpp"
#include <Classes.hpp>
#include <Controls.hpp>
#include <ExtCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
#include <ImgList.hpp>
#include <Menus.hpp>
#include <StdCtrls.hpp>
#include <ComCtrls.hpp>
#include "ipwjson.h"
#include <Sockets.hpp>
#include "ipshttps.h"
#include "AdvDropDown.hpp"
#include "AdvMultiColumnDropDown.hpp"
#include <Mask.hpp>
#include "AdvCGrid.hpp"
#include "frmctrllink.hpp"
#include "dxSkinBlack.hpp"
#include "dxSkinBlue.hpp"
#include "dxSkinBlueprint.hpp"
#include "dxSkinCaramel.hpp"
#include "dxSkinCoffee.hpp"
#include "dxSkinDarkRoom.hpp"
#include "dxSkinDarkSide.hpp"
#include "dxSkinDevExpressDarkStyle.hpp"
#include "dxSkinDevExpressStyle.hpp"
#include "dxSkinFoggy.hpp"
#include "dxSkinGlassOceans.hpp"
#include "dxSkinHighContrast.hpp"
#include "dxSkiniMaginary.hpp"
#include "dxSkinLilian.hpp"
#include "dxSkinLiquidSky.hpp"
#include "dxSkinLondonLiquidSky.hpp"
#include "dxSkinMcSkin.hpp"
#include "dxSkinMetropolis.hpp"
#include "dxSkinMetropolisDark.hpp"
#include "dxSkinMoneyTwins.hpp"
#include "dxSkinOffice2007Black.hpp"
#include "dxSkinOffice2007Blue.hpp"
#include "dxSkinOffice2007Green.hpp"
#include "dxSkinOffice2007Pink.hpp"
#include "dxSkinOffice2007Silver.hpp"
#include "dxSkinOffice2010Black.hpp"
#include "dxSkinOffice2010Blue.hpp"
#include "dxSkinOffice2010Silver.hpp"
#include "dxSkinOffice2013DarkGray.hpp"
#include "dxSkinOffice2013LightGray.hpp"
#include "dxSkinOffice2013White.hpp"
#include "dxSkinPumpkin.hpp"
#include "dxSkinsCore.hpp"
#include "dxSkinsDefaultPainters.hpp"
#include "dxSkinSeven.hpp"
#include "dxSkinSevenClassic.hpp"
#include "dxSkinSharp.hpp"
#include "dxSkinSharpPlus.hpp"
#include "dxSkinSilver.hpp"
#include "dxSkinSpringTime.hpp"
#include "dxSkinStardust.hpp"
#include "dxSkinSummer2008.hpp"
#include "dxSkinTheAsphaltWorld.hpp"
#include "dxSkinValentine.hpp"
#include "dxSkinVS2010.hpp"
#include "dxSkinWhiteprint.hpp"
#include "dxSkinXmas2008Blue.hpp"
#include "AdvUtil.hpp"
#include "dxSkinOffice2016Colorful.hpp"
#include "dxSkinOffice2016Dark.hpp"
#include "dxSkinVisualStudio2013Blue.hpp"
#include "dxSkinVisualStudio2013Dark.hpp"
#include "dxSkinVisualStudio2013Light.hpp"
#include "ipsjsons.h"

//---------------------------------------------------------------------------

#ifndef TGUtilsH
#include "TGUtils.h"
#endif
#ifndef TIContacH
#include "TIContac.h"
#endif
#ifndef TIPubH
#include "TIPub.h"
#endif
#ifndef TIUpContactH
#include "TIUpContact.h"
#endif
#ifndef TINeotomaH
#include "TINeotoma.h"
#endif

//---------------------------------------------------------------------------
class TPutPubForm;
class TStewardPubForm;
class TValidatePubForm;
//---------------------------------------------------------------------------
enum STEWARDPUBFORMSYTLE { NEWPUB, EDITPUB };
//---------------------------------------------------------------------------

class TPubForm : public TForm
{
__published:	// IDE-managed Components
	TScrollBox *ScrollBox1;
	TRadioButton *RadioButton1;
	TRadioButton *RadioButton2;
	TLabel *LabelJournal;
	TcxTextEdit *cxJournalNameEdit;
	TLabel *LabelJournalVolume;
	TcxTextEdit *cxJournalVolumeEdit;
	TLabel *LabelJournalIssue;
	TcxTextEdit *cxJournalIssueEdit;
	TLabel *LabelCitationNumber;
	TcxTextEdit *cxCitationNumber;
	TFlowPanel *FlowPanel2;
	TLabel *LabelAuthors;
	TPanel *PanelAuthors;
	TAdvStringGrid *AuthorsGrid;
	TLabel *LabelYear;
	TcxTextEdit *cxYearEdit;
	TLabel *LabelTitle;
	TcxMemo *cxTitleMemo;
	TLabel *LabelEditors;
	TPanel *PanelEditors;
	TAdvStringGrid *EditorsGrid;
	TLabel *LabelBookTitle;
	TcxMemo *cxBookTitleMemo;
	TLabel *LabelVolumeNumber;
	TcxTextEdit *cxVolumeNumberEdit;
	TLabel *LabelVolumeTitle;
	TcxMemo *cxVolumeTitleMemo;
	TLabel *LabelSeriesTitle;
	TcxMemo *cxSeriesTitleMemo;
	TLabel *LabelSeriesVolumeNumber;
	TcxTextEdit *cxSeriesVolumeEdit;
	TLabel *LabelPages;
	TcxTextEdit *cxPageEdit;
	TLabel *LabelPublisher;
	TcxTextEdit *cxPublisherEdit;
	TLabel *LabelCity;
	TcxTextEdit *cxCityEdit;
	TLabel *LabelState;
	TcxTextEdit *cxStateEdit;
	TLabel *LabelCountry;
	TcxTextEdit *cxCountryEdit;
	TLabel *LabelTranslator;
	TPanel *PanelTranslator;
	TAdvStringGrid *TranslatorGrid;
	TLabel *LabelOrigLang;
	TcxTextEdit *cxOrigLangEdit;
	TcxButton *cxButton2;
	TcxMemo *cxCitationMemo;
	TLabel *LabelEdition;
	TcxTextEdit *cxEditionEdit;
	TLabel *LabelNumVols;
	TcxTextEdit *cxNumVolsEdit;
	TLabel *LabelDOI;
	TcxTextEdit *cxDOIEdit;
	TcxGroupBox *cxGroupBox1;
	TcxTextEdit *cxThesisAuthorEdit;
	TLabel *LabelThesisAuthor;
	TPanel *Panel17;
	TPanel *Panel18;
	TcxButton *cxButton8;
	TFlowPanel *FlowPanel5;
	TcxButton *cxButtonJournal;
	TcxButton *cxButtonBookChapter;
	TcxButton *cxButtonBook;
	TcxButton *cxButtonReport;
	TcxButton *cxButtonThesis;
	TcxButton *cxButtonWebsite;
	TcxButton *cxButtonOther;
	TcxButton *cxButton9;
	TPanel *Panel1;
	TPanel *Panel2;
	TLabel *LabelUniversity;
	TcxTextEdit *cxUniversityEdit;
	TPanel *Panel3;
	TPanel *Panel4;
	TcxGroupBox *cxGroupBox2;
	TRadioButton *RadioButton3;
	TRadioButton *RadioButton4;
	TRadioButton *RadioButton5;
	TLabel *LabelUnparsedCitation;
	TcxMemo *cxWorkSpaceMemo;
	TPanel *Panel5;
	TPanel *Panel6;
	TSplitter *Splitter1;
	TPanel *Panel8;
	TPanel *Panel9;
	TPanel *Panel7;
	TcxButton *cxButton1;
	TLabel *NotesLabel;
	TcxMemo *cxNotesMemo;
	TLabel *LabelURL;
	TcxTextEdit *cxURLEdit;
	TFlowPanel *FlowPanel1;
	TcxButton *cxButton3;
	TcxImageList *cxImageList1;
	TStatusBar *StatusBar1;
	TLabel *LabelNeotomaPubID;
	TcxTextEdit *cxNeotomaPubIDEdit;
	TPanel *Panel10;
	TTcpClient *TcpClient1;
	TipsHTTPS *ipsHTTPS1;
	TFlowPanel *FlowPanel3;
	TcxButton *cxButtonFirst;
	TcxButton *cxButtonPrev;
	TcxButton *cxButtonNext;
	TcxButton *cxButtonLast;
	TAdvMultiColumnDropDown *AdvMultiColumnDropDown1;
	TcxButton *cxButton4;
	TipsJSONS *ipsJSONS1;
    void __fastcall FormActivate(TObject *Sender);
	void __fastcall cxButton2Click(TObject *Sender);
	void __fastcall NeotomaButtonClick(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);
	void __fastcall FormCanResize(TObject *Sender, int &NewWidth, int &NewHeight, bool &Resize);
	void __fastcall RadioButton1Click(TObject *Sender);
	void __fastcall RadioButton2Click(TObject *Sender);
	void __fastcall AuthorsGridExit(TObject *Sender);
	void __fastcall EditorsGridExit(TObject *Sender);
	void __fastcall TranslatorGridExit(TObject *Sender);
	void __fastcall cxButtonBookChapterClick(TObject *Sender);
	void __fastcall cxButton9Click(TObject *Sender);
	void __fastcall cxButtonJournalClick(TObject *Sender);
	void __fastcall cxButtonBookClick(TObject *Sender);
	void __fastcall cxThesisAuthorEditExit(TObject *Sender);
	void __fastcall cxYearEditExit(TObject *Sender);
	void __fastcall cxTitleMemoExit(TObject *Sender);
	void __fastcall cxJournalNameEditExit(TObject *Sender);
	void __fastcall cxJournalVolumeEditExit(TObject *Sender);
	void __fastcall cxJournalIssueEditExit(TObject *Sender);
	void __fastcall cxPageEditExit(TObject *Sender);
	void __fastcall cxCitationNumberExit(TObject *Sender);
	void __fastcall cxDOIEditExit(TObject *Sender);
	void __fastcall cxBookTitleMemoExit(TObject *Sender);
	void __fastcall cxEditionEditExit(TObject *Sender);
	void __fastcall cxNumVolsEditExit(TObject *Sender);
	void __fastcall cxVolumeNumberEditExit(TObject *Sender);
	void __fastcall cxVolumeTitleMemoExit(TObject *Sender);
	void __fastcall cxSeriesTitleMemoExit(TObject *Sender);
	void __fastcall cxSeriesVolumeEditExit(TObject *Sender);
	void __fastcall cxPublisherEditExit(TObject *Sender);
	void __fastcall cxUniversityEditExit(TObject *Sender);
	void __fastcall cxCityEditExit(TObject *Sender);
	void __fastcall cxStateEditExit(TObject *Sender);
	void __fastcall cxCountryEditExit(TObject *Sender);
	void __fastcall cxOrigLangEditExit(TObject *Sender);
	void __fastcall RadioButton3Click(TObject *Sender);
	void __fastcall RadioButton4Click(TObject *Sender);
	void __fastcall RadioButton5Click(TObject *Sender);
	void __fastcall cxButtonReportClick(TObject *Sender);
	void __fastcall cxButtonThesisClick(TObject *Sender);
	void __fastcall cxButtonOtherClick(TObject *Sender);
	void __fastcall Splitter1CanResize(TObject *Sender, int &NewSize, bool &Accept);
	void __fastcall cxButtonWebsiteClick(TObject *Sender);
	void __fastcall cxButton3Click(TObject *Sender);
	void __fastcall cxNotesMemoExit(TObject *Sender);
	void __fastcall cxURLEditExit(TObject *Sender);
	void __fastcall cxButtonNextClick(TObject *Sender);
	void __fastcall cxButtonFirstClick(TObject *Sender);
	void __fastcall cxButtonPrevClick(TObject *Sender);
	void __fastcall cxButtonLastClick(TObject *Sender);
	void __fastcall AdvMultiColumnDropDown1Select(TObject *Sender);
	void __fastcall cxButton4Click(TObject *Sender);
	void __fastcall ipsJSONS1SSLServerAuthentication(TObject *Sender, TipsJSONSSSLServerAuthenticationEventParams *e);


__published:	// User declarations
	void CleanUp(void);
	void UploadPub(void);
private:	// User declarations
	friend TPutPubForm;
	friend TStewardPubForm;
	friend TValidatePubForm;
	bool Activated;
	bool PubChanged;
	bool NeotomaPubSearched;
	bool AlwaysShowPubID;
	short Style;
	PUBLICATION *pub;
	TContactList* ContactList;
	UnicodeString FormatJournalCitation(void);
	UnicodeString FormatBookChapterCitation(void);
	UnicodeString FormatBookCitation(void);
	UnicodeString FormatThesisCitation(void);
	UnicodeString FormatReportCitation(void);
	UnicodeString FormatOtherCitation(void);
	UnicodeString FormatWebsiteCitation(void);
	UnicodeString FormatAuthors(vector<AUTHOR>&, int);
	UnicodeString FormatEditors(vector<EDITOR>&);
	void ParseAuthorsString(UnicodeString&);
	void ParseAuthor(UnicodeString&, AUTHOR&);
	void ParseEditor(UnicodeString&, EDITOR&);
	void ParseCitation(void);
	void CheckAuthorFormat(TAdvStringGrid*, vector<AUTHOR>&);
	void CheckEditorFormat(TAdvStringGrid*, vector<EDITOR>&);
	UnicodeString ParseName(UnicodeString, UnicodeString&, UnicodeString&, UnicodeString&, UnicodeString&);
	UnicodeString ParseSuffix(UnicodeString&);
	UnicodeString ParseForenames(UnicodeString&);
	UnicodeString FormatAuthor(UnicodeString&);
	UnicodeString ParseAuthorName(UnicodeString, AUTHOR&);
	UnicodeString ParseEditorName(UnicodeString, EDITOR&);
	void ClearInputForm(void);
	void FormatInputForm(void);
	void PopulateInputForm(void);
	void FillAuthorFields(void);
	void FillEditorFields(void);
	void FillTranslatorFields(void);
	void GetNeotomaPublication(void);
	void GetNeotomaPublicationID(void);
	void FormatCitation(void);
	bool GetContactIDs(bool AlwaysReset);
	void SetFlowPanel1Position(void);
	virtual void SetNavigationButtons(void) { }
public:		// User declarations
	__fastcall TPubForm(PUBLICATION *p, TComponent* Owner);
};
//---------------------------------------------------------------------------

class TStewardPubForm : public TPubForm
{
__published:	// IDE-managed Components
	void __fastcall NeotomaButtonClick(TObject *Sender);
	void __fastcall cxButton3Click(TObject *Sender);
	void __fastcall cxButtonNextClick(TObject *Sender);
	void __fastcall cxButtonFirstClick(TObject *Sender);
	void __fastcall cxButtonPrevClick(TObject *Sender);
	void __fastcall cxButtonLastClick(TObject *Sender);
	void __fastcall AdvMultiColumnDropDown1Select(TObject *Sender);
	void __fastcall cxButton4Click(TObject *Sender);
private:
	int PubTypeID;
	bool local_pub;
	int MinPubID;
	int MaxPubID;
	void UpdatePub(void);
	bool UpdateAuthors(set<int> AuthorIDs);
	bool UpdateEditors(set<int> EditorIDs);
	bool UpdateTranslators(set<int> TranslatorIDs);
	void GetPublicationTypes(void);
	void SetNavigationButtons(void);
	void Navigate(int PubID);
	void GetTableMinPubID(void);
	void GetTableMaxPubID(void);
	void GetMinPubIDByPubIDType(int PubTypeID);
	void GetMaxPubIDByPubIDType(int PubTypeID);
public:
	__fastcall TStewardPubForm(PUBLICATION *p, short style, TContactList* contact_list,
		TComponent* Owner);
	__fastcall ~TStewardPubForm();
};
//---------------------------------------------------------------------------

class TValidatePubForm : public TStewardPubForm
{
__published:	// IDE-managed Components
   void __fastcall FormActivate(TObject *Sender);
public:
	__fastcall TValidatePubForm(PUBLICATION *p, short sytle, TContactList* contact_list,
		TComponent* Owner);
};
//---------------------------------------------------------------------------

extern PACKAGE TPubForm *PubForm;
//---------------------------------------------------------------------------
#endif
