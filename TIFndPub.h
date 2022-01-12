//---------------------------------------------------------------------------

#ifndef TIFndPubH
#define TIFndPubH
#include "AdvCGrid.hpp"
#include "AdvControlDropDown.hpp"
#include "AdvDropDown.hpp"
#include "AdvGrid.hpp"
#include "AdvObj.hpp"
#include "BaseGrid.hpp"
#include "cxButtons.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxEdit.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include "cxMemo.hpp"
#include "cxTextEdit.hpp"
#include "frmctrllink.hpp"
#include "ipwjson.h"

#include <Classes.hpp>
#include <ComCtrls.hpp>
#include <Controls.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <Mask.hpp>
#include <Menus.hpp>
#include <Sockets.hpp>
#include <StdCtrls.hpp>
#include "AdvCGrid.hpp"
#include "AdvControlDropDown.hpp"
#include "AdvDropDown.hpp"
#include "AdvGrid.hpp"
#include "AdvObj.hpp"
#include "BaseGrid.hpp"
#include "cxButtons.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxEdit.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include "cxMemo.hpp"
#include "cxTextEdit.hpp"
#include "frmctrllink.hpp"
#include "ipwjson.h"
#include <Classes.hpp>
#include <ComCtrls.hpp>
#include <Controls.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <Mask.hpp>
#include <Menus.hpp>
#include <Sockets.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ImgList.hpp>
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
#include <set>
#include "TIPubl.h"
#ifndef TIJSONH
#include "TIJSON.h"
#endif
#ifndef TIContacH
#include "TIContac.h"
#endif
#ifndef TINeotomaH
#include "TINeotoma.h"
#endif
//---------------------------------------------------------------------------
class TGetPubForm;
class TMatchPubForm;
//---------------------------------------------------------------------------

class TFindPubForm : public TForm
{
__published:	// IDE-managed Components
	TStatusBar *StatusBar1;
	TPanel *Panel1;
	TComboBox *ComboBox1;
	TLabel *Label1;
	TPanel *Panel2;
	TPanel *Panel3;
	TcxButton *cxButton1;
	TcxButton *cxButton2;
	TcxButton *cxButton3;
	TAdvColumnGrid *AdvColumnGrid1;
	TPanel *Panel4;
	TcxButton *cxButton4;
	TTcpClient *TcpClient1;
	TAdvControlDropDown *AdvControlDropDown1;
	TFormControlEditLink *FormControlEditLink1;
	TcxMemo *cxMemo1;
	TFlowPanel *FlowPanel1;
	TLabel *Label2;
	TEdit *Edit1;
	TcxMemo *cxMemo2;
	TcxImageList *cxImageList1;
	TipsJSONS *ipsJSONS1;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall cxButton4Click(TObject *Sender);
	void __fastcall FormControlEditLink1GetEditorValue(TObject *Sender, TAdvStringGrid *Grid,
          UnicodeString &AValue);
	void __fastcall FormControlEditLink1SetEditorValue(TObject *Sender, TAdvStringGrid *Grid,
          UnicodeString AValue);
	void __fastcall AdvColumnGrid1GetEditorProp(TObject *Sender, int ACol, int ARow,
          TEditLink *AEditLink);
	void __fastcall AdvColumnGrid1CheckBoxClick(TObject *Sender, int ACol, int ARow,
          bool State);
	void __fastcall AdvColumnGrid1MouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y);
	void __fastcall cxButton2Click(TObject *Sender);
	void __fastcall cxButton1Click(TObject *Sender);
	void __fastcall Edit1Change(TObject *Sender);
	void __fastcall ipsJSONS1SSLServerAuthentication(TObject *Sender, TipsJSONSSSLServerAuthenticationEventParams *e);


private:	// User declarations
	friend class TGetPubForm;
	friend class TMatchPubForm;
	TContactList* ContactList;
	UnicodeString Citation;
	PUBLICATION* local_pub;
	vector<PUBAUTHOR> Authors;
	vector<EDITOR> Editors;
	vector<EDITOR> Translators;
	vector<CONTACT> Contacts;
	void SetPub(int);
	void GetAuthors(void);
public:		// User declarations
	__fastcall TFindPubForm(TContactList* contact_list, TComponent* Owner);
	__fastcall TFindPubForm(TContactList* contact_list, int pub_id, TComponent* Owner);
	vector<NTMPUBLICATION> ntm_pubs;
	NTMPUBLICATION ntm_pub;
	int PubID;
	map<int, int> PubTypes;  // PubID, PubType
};

//---------------------------------------------------------------------------

// for use by non-stewards
class TGetPubForm : public TFindPubForm
{
__published:	// IDE-managed Components
	void __fastcall cxButton2Click(TObject *Sender);
public:
	__fastcall TGetPubForm(PUBLICATION *pub, TComponent* Owner);
};
//---------------------------------------------------------------------------

class TMatchPubForm : public TFindPubForm
{
__published:	// IDE-managed Components
	void __fastcall cxButton2Click(TObject *Sender);
private:
    vector<UnicodeString> Differences;
	void SetPubs(PUBLICATION *pub, set<int>& PubIDs);
	bool MatchPub(void);
	bool CompPubFields(UnicodeString LocalPubField, UnicodeString vNtmPubField,
		UnicodeString Field, bool CheckCaps);
public:
	__fastcall TMatchPubForm(PUBLICATION *pub, set<int>& PubIDs, TComponent* Owner);
};

//---------------------------------------------------------------------------
extern PACKAGE TFindPubForm *FindPubForm;
//---------------------------------------------------------------------------
#endif
