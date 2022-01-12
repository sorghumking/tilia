//---------------------------------------------------------------------------

#ifndef TICalibH
#define TICalibH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "cxButtons.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include <Menus.hpp>
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxEdit.hpp"
#include "cxLabel.hpp"
#include "cxTextEdit.hpp"
#include "ipwhttp.h"
#include <Sockets.hpp>
#include "ipwjson.h"
#include "AdvCGrid.hpp"
#include "AdvGrid.hpp"
#include "AdvObj.hpp"
#include "BaseGrid.hpp"
#include <Grids.hpp>
#include "cxDropDownEdit.hpp"
#include "cxMaskEdit.hpp"
#include "ipsjsons.h"
#include "ipshttps.h"
#include "AdvSprd.hpp"
#include <ExtCtrls.hpp>
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
#include <vector>
#include <map>
#include <set>
//---------------------------------------------------------------------------

enum CALIBCURVES { INTCAL13, SHCAL13 };
//---------------------------------------------------------------------------

class CALIBRANGE
{
private:
	Variant FYounger;
	Variant FOlder;
	Variant FProb;
public:
	Variant DecodeInt(UnicodeString XText);
	Variant DecodeFloat(UnicodeString XText);
	__property Variant Younger = {read = FYounger, write = FYounger};
	__property Variant Older = {read = FOlder, write = FOlder};
	__property Variant Prob = {read = FProb, write = FProb};
};
//---------------------------------------------------------------------------

typedef struct
{
  UnicodeString LabNumber;
  int Age;
  int SD;
  Variant Median;
  UnicodeString ProgramVersion;
  vector<CALIBRANGE> Ranges;
} CALIBDATE;
//---------------------------------------------------------------------------

class OXCAL
{
private:
	TipsJSONS *ipsJSONS1;
	TTcpClient *TcpClient1;
public:
	OXCAL(TipsJSONS *ipsjsons, TTcpClient *tcpclient);
	bool Calibrate(UnicodeString Curve, vector<CALIBDATE>& Dates);
	Variant ConvertAge(Variant Gage, short AgeType);
};
//---------------------------------------------------------------------------

class TCalibForm : public TForm
{
__published:	// IDE-managed Components
	TcxButton *cxButton1;
	TipwHTTP *ipwHTTP1;
	TTcpClient *TcpClient1;
	TAdvColumnGrid *AdvColumnGrid1;
	TcxLabel *cxLabel3;
	TcxComboBox *cxComboBox1;
	TcxButton *cxButton2;
	TcxLabel *cxLabel1;
	TcxTextEdit *cxTextEdit1;
	TFlowPanel *FlowPanel1;
	TcxImageList *cxImageList1;
	TcxButton *cxButton3;
	TcxButton *cxButton4;
	TipsJSONS *ipsJSONS1;
	void __fastcall cxButton1Click(TObject *Sender);
	void __fastcall cxButton2Click(TObject *Sender);
	void __fastcall cxButton3Click(TObject *Sender);
	void __fastcall AdvColumnGrid1KeyUp(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall ipsJSONS1SSLServerAuthentication(TObject *Sender, TipsJSONSSSLServerAuthenticationEventParams *e);

private:	// User declarations
	vector<CALIBDATE> Dates;
public:		// User declarations
	__fastcall TCalibForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TCalibForm *CalibForm;
//---------------------------------------------------------------------------
#endif
