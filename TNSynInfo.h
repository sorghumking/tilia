//---------------------------------------------------------------------------

#ifndef TNSynInfoH
#define TNSynInfoH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "cxButtons.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxEdit.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include "cxMemo.hpp"
#include "cxTextEdit.hpp"
#include <Menus.hpp>
#include <ComCtrls.hpp>
#include "cxGroupBox.hpp"
#include "dxGDIPlusClasses.hpp"
#include <ExtCtrls.hpp>
#include "ipwjson.h"
#include <Sockets.hpp>
#include "cxLabel.hpp"
#include "cxListView.hpp"
#include "cxListBox.hpp"
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
#include "ipsjsons.h"
#ifndef TISpreadH
#include "TISpread.h"
#endif

//---------------------------------------------------------------------------
class TSynonymInfoForm : public TForm
{
__published:	// IDE-managed Components
	TcxMemo *cxMemo1;
	TcxMemo *cxMemo2;
	TcxTextEdit *cxTextEdit1;
	TcxTextEdit *cxTextEdit2;
	TcxButton *cxButton1;
	TStatusBar *StatusBar1;
	TcxMemo *cxMemo3;
	TcxTextEdit *cxTextEdit3;
	TcxTextEdit *cxTextEdit4;
	TcxTextEdit *cxTextEdit5;
	TcxTextEdit *cxTextEdit6;
	TcxGroupBox *cxGroupBox1;
	TTcpClient *TcpClient1;
	TcxLabel *cxLabel1;
	TcxLabel *cxLabel2;
	TcxLabel *cxLabel4;
	TcxLabel *cxLabel5;
	TcxLabel *cxLabel6;
	TcxLabel *cxLabel7;
	TcxLabel *cxLabel8;
	TcxLabel *cxLabel9;
	TcxLabel *cxLabel10;
	TcxGroupBox *cxGroupBox2;
	TcxMemo *cxMemo4;
	TcxTextEdit *cxTextEdit7;
	TcxLabel *cxLabel3;
	TcxButton *cxButton2;
	TcxLabel *cxLabel11;
	TcxButton *cxButton3;
	TcxButton *cxButton4;
	TcxListBox *cxListBox1;
	TipsJSONS *ipsJSONS1;
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall cxTextEdit7PropertiesChange(TObject *Sender);
	void __fastcall cxButton4Click(TObject *Sender);
	void __fastcall cxButton2Click(TObject *Sender);
	void __fastcall cxButton3Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall cxTextEdit7KeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall ipsJSONS1SSLServerAuthentication(TObject *Sender, TipsJSONSSSLServerAuthenticationEventParams *e);

private:	// User declarations
	bool activated;
	bool local;
	vector<SYNONYMROW>::pointer synrow_ptr;
	UnicodeString SavedSynonymName;
	void ShowInfo(void);
	void SynonymSearch(void);
	bool GetValidName(UnicodeString InvalidName, bool& found);
public:		// User declarations
	__fastcall TSynonymInfoForm(vector<SYNONYMROW>::pointer srptr, TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TSynonymInfoForm *SynonymInfoForm;
//---------------------------------------------------------------------------
#endif
