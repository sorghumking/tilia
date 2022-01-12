//---------------------------------------------------------------------------

#ifndef TNLoginH
#define TNLoginH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "cxButtons.hpp"
#include "cxCheckBox.hpp"
#include "cxCheckListBox.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxEdit.hpp"
#include "cxGraphics.hpp"
#include "cxGroupBox.hpp"
#include "cxLabel.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include "cxTextEdit.hpp"
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <Menus.hpp>
#include "ipsjsons.h"
#include "ipwjson.h"
#include <Sockets.hpp>
#include <ComCtrls.hpp>
#include "dxGDIPlusClasses.hpp"
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
#include "dxSkinOffice2016Colorful.hpp"
#include "dxSkinOffice2016Dark.hpp"
#include "dxSkinVisualStudio2013Blue.hpp"
#include "dxSkinVisualStudio2013Dark.hpp"
#include "dxSkinVisualStudio2013Light.hpp"
//---------------------------------------------------------------------------
class TNeotomaLoginForm : public TForm
{
__published:	// IDE-managed Components
	TcxGroupBox *cxGroupBox1;
	TImage *Image1;
	TcxCheckListBox *cxCheckListBox1;
	TcxButton *cxButton1;
	TcxButton *cxButton2;
	TcxLabel *cxLabel1;
	TcxTextEdit *cxTextEdit1;
	TcxLabel *cxLabel2;
	TcxTextEdit *cxTextEdit2;
	TcxLabel *cxLabel3;
	TcxCheckBox *cxCheckBox1;
	TipwJSON *ipwJSON1;
	TipsJSONS *ipsJSONS1;
	TTcpClient *TcpClient1;
	TImage *Image2;
	TTimer *Timer1;
	TcxButton *cxButton3;
	TLabel *Label1;
	TcxCheckBox *cxCheckBox2;
	TPanel *StatusBar1;
	TcxImageList *cxImageList1;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall cxButton1Click(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall cxTextEdit1PropertiesEditValueChanged(TObject *Sender);
	void __fastcall cxTextEdit2KeyUp(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall cxButton2Click(TObject *Sender);
	void __fastcall cxCheckListBox1ClickCheck(TObject *Sender, int AIndex, TcxCheckBoxState APrevState,
          TcxCheckBoxState ANewState);
	void __fastcall cxButton3Click(TObject *Sender);
	void __fastcall ipsJSONS1SSLServerAuthentication(TObject *Sender, TipsJSONSSSLServerAuthenticationEventParams *e);
private:	// User declarations
	int RatStart;
	int RatEnd;
	int RatPos;
private:
	bool ConfirmDatabaseID(void);
public:		// User declarations
	__fastcall TNeotomaLoginForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TNeotomaLoginForm *NeotomaLoginForm;
//---------------------------------------------------------------------------
#endif
