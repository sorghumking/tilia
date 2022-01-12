//---------------------------------------------------------------------------

#ifndef TIUpContactH
#define TIUpContactH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include "cxButtons.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include <Graphics.hpp>
#include <Menus.hpp>
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxEdit.hpp"
#include "cxListBox.hpp"
#include "cxTextEdit.hpp"
#include "cxDropDownEdit.hpp"
#include "cxMaskEdit.hpp"
#include "cxMemo.hpp"
#include "ipwjson.h"
#include <Sockets.hpp>
#include "cxGroupBox.hpp"
#include "cxLabel.hpp"
#include <ImgList.hpp>
#include "cxCheckBox.hpp"
#include "cxRichEdit.hpp"
#include <ComCtrls.hpp>
#include "cxSpinEdit.hpp"
#include "ipshttps.h"
#include "cxProgressBar.hpp"
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
#include "dxSkinOffice2016Colorful.hpp"
#include "dxSkinOffice2016Dark.hpp"
#include "dxSkinVisualStudio2013Blue.hpp"
#include "dxSkinVisualStudio2013Dark.hpp"
#include "dxSkinVisualStudio2013Light.hpp"
#include "ipsjsons.h"
//---------------------------------------------------------------------------
#include <vector>
#ifndef TIPubH
#include "TIPub.h"
#endif
#ifndef TIJSONH
#include "TIJSON.h"
#endif
#ifndef TINeotomaH
#include "TINeotoma.h"
#endif


//---------------------------------------------------------------------------
enum CONTACTBUTTON { LEFTARROW=0, RIGHTARROW=1 };
class TUploadAuthorForm;
class TGetNeotomaContact;
//---------------------------------------------------------------------------

class TNeotomaContactForm : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TPanel *Panel2;
	TPanel *Panel3;
	TFlowPanel *FlowPanel1;
	TLabel *LabelFamilyName1;
	TLabel *LabelGivenNames1;
	TLabel *LabelInitials1;
	TLabel *LabelSuffix1;
	TLabel *LabelTitle1;
	TLabel *LabelStatus1;
	TLabel *LabelPhone1;
	TLabel *LabelFax1;
	TLabel *LabelEmail1;
	TLabel *LabelURL1;
	TLabel *LabelAddress1;
	TLabel *LabelNotes1;
	TPanel *Panel4;
	TFlowPanel *FlowPanel2;
	TPanel *Panel5;
	TLabel *Label9;
	TLabel *Label14;
	TLabel *Label15;
	TLabel *Label16;
	TLabel *Label17;
	TLabel *Label18;
	TLabel *Label19;
	TLabel *Label20;
	TLabel *Label21;
	TLabel *Label22;
	TLabel *Label23;
	TLabel *Label24;
	TPanel *Panel6;
	TcxListBox *cxListBox1;
	TcxTextEdit *cxTextEditFamilyName1;
	TcxTextEdit *cxTextEditFamilyName2;
	TcxTextEdit *cxTextEditGivenNames1;
	TcxTextEdit *cxTextEditGivenNames2;
	TcxTextEdit *cxTextEditInitials1;
	TcxTextEdit *cxTextEditInitials2;
	TcxTextEdit *cxTextEditSuffix1;
	TcxTextEdit *cxTextEditSuffix2;
	TcxComboBox *cxComboBoxTitle1;
	TcxComboBox *cxComboBoxTitle2;
	TcxComboBox *cxComboBoxStatus1;
	TcxComboBox *cxComboBoxStatus2;
	TcxTextEdit *cxTextEditPhone1;
	TcxTextEdit *cxTextEditPhone2;
	TcxTextEdit *cxTextEditFax1;
	TcxTextEdit *cxTextEditFax2;
	TcxTextEdit *cxTextEditEmail1;
	TcxTextEdit *cxTextEditEmail2;
	TcxTextEdit *cxTextEditURL1;
	TcxTextEdit *cxTextEditURL2;
	TcxMemo *cxMemoAddress1;
	TcxMemo *cxMemoAddress2;
	TcxMemo *cxMemoNotes1;
	TcxMemo *cxMemoNotes2;
	TTcpClient *TcpClient1;
	TcxGroupBox *cxGroupBox1;
	TFlowPanel *FlowPanel3;
	TcxLabel *cxLabel1;
	TcxLabel *cxLabel2;
	TcxTextEdit *cxTextEdit1;
	TcxTextEdit *cxTextEdit2;
	TcxButton *cxButton2;
	TcxGroupBox *cxGroupBox2;
	TcxGroupBox *cxGroupBox3;
	TcxRichEdit *cxRichEdit1;
	TcxTextEdit *cxTextEditID2;
	TcxLabel *cxLabel3;
	TcxTextEdit *cxTextEditID1;
	TcxLabel *cxLabelID1;
	TcxButton *cxButton3;
	TcxButton *cxButtonRightArrow;
	TcxButton *cxButton1;
	TcxButton *cxButton4;
	TStatusBar *StatusBar1;
	TcxSpinEdit *cxSpinEdit1;
	TcxButton *cxButton5;
	TipsHTTPS *ipsHTTPS1;
	TcxButton *cxButton6;
	TPopupMenu *PopupMenu1;
	TMenuItem *Publications1;
	TMenuItem *Datasets1;
	TcxButton *cxButton7;
	TcxGroupBox *cxGroupBox4;
	TcxLabel *cxLabel4;
	TcxProgressBar *cxProgressBar1;
	TcxButton *cxButtonUpdate;
	TcxImageList *cxImageList1;
	TipsJSONS *ipsJSONS1;
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall cxListBox1Click(TObject *Sender);
	void __fastcall cxButton2Click(TObject *Sender);
	void __fastcall cxButtonRightArrowClick(TObject *Sender);
	void __fastcall cxButton1Click(TObject *Sender);
	void __fastcall cxTextEditGivenNames2PropertiesValidate(TObject *Sender, Variant &DisplayValue,
		  TCaption &ErrorText, bool &Error);
	void __fastcall cxTextEditPropertiesChange(TObject *Sender);
	void __fastcall cxComboBoxPropertiesChange(TObject *Sender);
	void __fastcall cxMemoPropertiesChange(TObject *Sender);
	void __fastcall cxComboBoxStatusPropertiesValidate(TObject *Sender, Variant &DisplayValue,
		  TCaption &ErrorText, bool &Error);
	void __fastcall cxTextEditEnter(TObject *Sender);
	void __fastcall cxComboBoxEnter(TObject *Sender);
	void __fastcall cxMemoEnter(TObject *Sender);
	void __fastcall cxButton7Click(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall cxSpinEdit1PropertiesChange(TObject *Sender);
	void __fastcall cxButton3Click(TObject *Sender);
	void __fastcall cxExit(TObject *Sender);
	void __fastcall Publications1Click(TObject *Sender);
	void __fastcall Datasets1Click(TObject *Sender);
	void __fastcall cxButtonUpdateClick(TObject *Sender);
	void __fastcall ipsJSONS1SSLServerAuthentication(TObject *Sender, TipsJSONSSSLServerAuthenticationEventParams *e);


private:	// User declarations
	friend TUploadAuthorForm;
	friend TGetNeotomaContact;
	bool Activated;
	map<int, UnicodeString> ContactStatuses;
	CONTACT* CurrentContact;
	bool ManualSpin;
	bool ManualEdit;
	UnicodeString oldtext;
private:
	void FillNeotomaContactCard(CONTACT*);
	void FillContactCard(CONTACT*);
	void ClearNeotomaContactCard(void);
	void SearchContact(UnicodeString LastName, UnicodeString Initials, int& size);
	void SearchContact(UnicodeString LastName, int& size);
	void HighLight(map<int, int>& highlights);
	void GetContactStatuses(void);
	bool GetContactByID(int ContactID, NTMCONTACT& ntm_contact);
	void ProcessAuthor(UnicodeString LastName, UnicodeString Initials, NTMCONTACT& ntm_contact);
	void ClearContactsList(void);
	UnicodeString FormatAuthorName(UnicodeString LastName, UnicodeString Initials, UnicodeString Suffix);
	UnicodeString FormatContactName(UnicodeString LastName, UnicodeString GivenNames,
		UnicodeString Initials, UnicodeString Suffix);
	int GetSetStatusIndex(TcxComboBox* cxComboBoxStatus);
	UnicodeString CheckGivenNameSpaces(UnicodeString);
	UnicodeString InitialsFromGivenNames(UnicodeString GivenNames);
	virtual void Instructions(UnicodeString LastName, UnicodeString GivenNames,
		UnicodeString Initials, UnicodeString Suffix, int size) = 0;
	bool CheckUploadData(UnicodeString& FamilyName, UnicodeString& GivenNames, UnicodeString& Initials);
	void UploadContact(UnicodeString FamilyName, UnicodeString GivenNames, UnicodeString Initials);
public:		// User declarations
	__fastcall TNeotomaContactForm(TComponent* Owner);
};

//---------------------------------------------------------------------------

class TUploadAuthorForm : public TNeotomaContactForm
{
__published:	// IDE-managed Components
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall cxButtonRightArrowClick(TObject *Sender);
	void __fastcall cxButton1Click(TObject *Sender);
	void __fastcall cxButton3Click(TObject *Sender);
	void __fastcall cxSpinEdit1PropertiesChange(TObject *Sender);
private:        // User declarations
    bool LocalContactList;
    TContactList* ContactList;
	int CurrentAuthorIndex;
	void SetAuthorList(vector<AUTHOR>& author_list);
	void SetAuthor(int idx);
	void Instructions(UnicodeString LastName, UnicodeString GivenNames,
		UnicodeString Initials, UnicodeString Suffix, int size);
public:
	__fastcall TUploadAuthorForm(vector<AUTHOR>& author_list,
		TContactList* contact_list, TComponent* Owner);
	vector<AUTHOR> AuthorList;
	int GetContactID(void);
};
//---------------------------------------------------------------------------

class TGetNeotomaContact : public TNeotomaContactForm
{
__published:	// IDE-managed Components
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall cxSpinEdit1PropertiesChange(TObject *Sender) { };
	void __fastcall cxButtonRightArrowClick(TObject *Sender);
	void __fastcall cxButtonUpdateClick(TObject *Sender);
	void __fastcall cxButton1Click(TObject *Sender);
	void __fastcall cxButton3Click(TObject *Sender);
private:        // User declarations
	CONTACT* Contact;
	void SetContact(void);
	void Instructions(UnicodeString LastName, UnicodeString GivenNames,
		UnicodeString Initials, UnicodeString Suffix, int size);
	void UpdateNeotomaContact(void);
public:
	__fastcall TGetNeotomaContact(CONTACT *contact, TComponent* Owner);
};

//---------------------------------------------------------------------------
extern PACKAGE TNeotomaContactForm *NeotomaContactForm;
//---------------------------------------------------------------------------
#endif
