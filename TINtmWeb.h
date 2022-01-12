//---------------------------------------------------------------------------

#ifndef TINtmWebH
#define TINtmWebH
#include "AdvCGrid.hpp"
#include "AdvEdit.hpp"
#include "AdvGrid.hpp"
#include "AdvObj.hpp"
#include "AdvPageControl.hpp"
#include "AdvUtil.hpp"
#include "BaseGrid.hpp"
#include "cxButtons.hpp"
#include "cxControls.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include "cxSplitter.hpp"
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
#include "dxSkinOffice2016Colorful.hpp"
#include "dxSkinOffice2016Dark.hpp"
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
#include "dxSkinVisualStudio2013Blue.hpp"
#include "dxSkinVisualStudio2013Dark.hpp"
#include "dxSkinVisualStudio2013Light.hpp"
#include "dxSkinVS2010.hpp"
#include "dxSkinWhiteprint.hpp"
#include "dxSkinXmas2008Blue.hpp"
#include "ipwjson.h"
#include <Classes.hpp>
#include <ComCtrls.hpp>
#include <Controls.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <Menus.hpp>
#include <Sockets.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "AdvMemo.hpp"
#include "AdvMemoStylerManager.hpp"
#include "advmjson.hpp"
#include "cxRadioGroup.hpp"
#include "cxContainer.hpp"
#include "cxEdit.hpp"
#include "cxLabel.hpp"
#include "ipshttps.h"
#include "ipsjsons.h"
#include "ipscertmgr.h"
#include "ipsipdaemons.h"

#ifndef TIJSONH
#include "TIJSON.h"
#endif
#ifndef TINeotomaH
#include "TINeotoma.h"
#endif

//---------------------------------------------------------------------------

template <class T> class service
{
public:
	T* name;
	service(TipsJSONS *ipsjsons, TTcpClient *tcpClient);
	~service() { delete name; }
};
//---------------------------------------------------------------------------

class TWebServicesForm : public TForm
{
__published:	// IDE-managed Components
	TListBox *ListBox1;
	TPanel *Panel1;
	TTcpClient *TcpClient1;
	TAdvColumnGrid *AdvColumnGrid1;
	TPanel *Panel2;
	TcxButton *cxButton1;
	TcxSplitter *cxSplitter1;
	TAdvPageControl *AdvPageControl1;
	TAdvTabSheet *AdvTabSheet1;
	TAdvTabSheet *AdvTabSheet2;
	TAdvEdit *AdvEdit1;
	TAdvColumnGrid *AdvColumnGrid2;
	TAdvJSONMemoStyler *AdvJSONMemoStyler1;
	TAdvMemoStylerManager *AdvMemoStylerManager1;
	TAdvMemo *AdvMemo1;
	TPanel *Panel3;
	TcxButton *cxButton2;
	TPopupMenu *PopupMenu1;
	TcxButton *cxButton3;
	TMenuItem *Copy1;
	TcxButton *cxButton4;
	TPopupMenu *PopupMenu2;
	TMenuItem *CopyLowercase1;
	TMenuItem *Copy2;
	TMenuItem *CopyLowercase2;
	TcxLabel *cxLabel1;
	TipsHTTPS *ipsHTTPS1;
	TipsJSONS *ipsJSONS1;
	TipsCertMgr *ipsCertMgr1;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall ListBox1Click(TObject *Sender);
	void __fastcall cxButton1Click(TObject *Sender);
	void __fastcall Panel2Resize(TObject *Sender);
	void __fastcall cxButton2Click(TObject *Sender);
	void __fastcall cxButton3Click(TObject *Sender);
	void __fastcall Copy1Click(TObject *Sender);
	void __fastcall PopupMenu1Popup(TObject *Sender);
	void __fastcall AdvColumnGrid1CheckBoxCanToggle(TObject *Sender, int ACol, int ARow,
		  bool State, bool &Allow);
	void __fastcall CopyLowercase1Click(TObject *Sender);
	void __fastcall Copy2Click(TObject *Sender);
	void __fastcall CopyLowercase2Click(TObject *Sender);
	void __fastcall ipsJSONS1SSLServerAuthentication(TObject *Sender, TipsJSONSSSLServerAuthenticationEventParams *e);
	void __fastcall ipsHTTPS1SSLServerAuthentication(TObject *Sender, TipsHTTPSSSLServerAuthenticationEventParams *e);
	void __fastcall ipsHTTPS1Header(TObject *Sender, TipsHTTPSHeaderEventParams *e);
	void __fastcall ipsHTTPS1ConnectionStatus(TObject *Sender, TipsHTTPSConnectionStatusEventParams *e);
	void __fastcall ipsHTTPS1SSLStatus(TObject *Sender, TipsHTTPSSSLStatusEventParams *e);
	void __fastcall ipsHTTPS1Status(TObject *Sender, TipsHTTPSStatusEventParams *e);
private:	// User declarations
	friend class TTSServicesForm;
	UnicodeString Schema;
	UnicodeString CurrentService;
	map<UnicodeString,int> typemap;
	UnicodeString WebService;
	vector<JSONFIELD> Fields;
	map<UnicodeString, UnicodeString> Parameters;
	vector<vector<Variant> > Table;
	void GetData(void);
	void MakeRequest(SJSONTABLE* func);
	void PrettyJSON(void);
	void SetupRequest(void);
	int QuotePos(UnicodeString& Text);
	void DefineTypes(void);
public:		// User declarations
	__fastcall TWebServicesForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

class TTSServicesForm : public TWebServicesForm
{
__published:	// IDE-managed Components
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall cxButton1Click(TObject *Sender);
private:	// User declarations
	map<UnicodeString,bool> func;
	void PutData(void);
	void RunInsertFunc(void);
	//void RunUpdateFunc(void);
public:		// User declarations
	__fastcall TTSServicesForm(TComponent* Owner);
};

//---------------------------------------------------------------------------
extern PACKAGE TWebServicesForm *WebServicesForm;
extern PACKAGE TTSServicesForm *TSServicesForm;
//---------------------------------------------------------------------------
#endif

