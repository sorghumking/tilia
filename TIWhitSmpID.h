//---------------------------------------------------------------------------

#ifndef TIWhitSmpIDH
#define TIWhitSmpIDH
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
#include "cxLabel.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
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
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include "cxTextEdit.hpp"
#include "ipwhttp.h"
#include "ipwjson.h"
#include <Sockets.hpp>
#include <ADODB.hpp>
#include <DB.hpp>
#include "ipsjsons.h"

#ifndef TISpreadH
#include "TISpread.h"
#endif

//---------------------------------------------------------------------------
class TWhitmoreSampleIDForm : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TLabeledEdit *LabeledEdit1;
	TcxButton *cxButton1;
	TPanel *Panel2;
	TcxButton *cxButton2;
	TPanel *Panel3;
	TGridPanel *GridPanel1;
	TcxLabel *cxLabel1;
	TcxLabel *cxLabel2;
	TcxLabel *cxLabel3;
	TcxButton *cxButton3;
	TcxTextEdit *cxTextEdit1;
	TcxTextEdit *cxTextEdit2;
	TcxTextEdit *cxTextEdit3;
	TGridPanel *GridPanel2;
	TcxLabel *cxLabel4;
	TcxTextEdit *cxTextEdit4;
	TcxLabel *cxLabel5;
	TcxTextEdit *cxTextEdit5;
	TcxLabel *cxLabel6;
	TcxTextEdit *cxTextEdit6;
	TipwHTTP *ipwHTTP1;
	TTcpClient *TcpClient1;
	TADOConnection *ADOConnection1;
	TADOQuery *ADOQuery1;
	TFlowPanel *FlowPanel1;
	TipsJSONS *ipsJSONS1;
	void __fastcall cxButton1Click(TObject *Sender);
	void __fastcall cxButton3Click(TObject *Sender);
	void __fastcall ipsJSONS1SSLServerAuthentication(TObject *Sender, TipsJSONSSSLServerAuthenticationEventParams *e);

private:	// User declarations
	TTilSpreadSheetForm* TSSForm;
public:		// User declarations
	__fastcall TWhitmoreSampleIDForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TWhitmoreSampleIDForm *WhitmoreSampleIDForm;
//---------------------------------------------------------------------------
#endif
