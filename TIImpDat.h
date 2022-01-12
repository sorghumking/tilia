//---------------------------------------------------------------------------

#ifndef TIImpDatH
#define TIImpDatH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "cxButtons.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include "cxRadioGroup.hpp"
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxEdit.hpp"
#include "cxImage.hpp"
#include "dxGDIPlusClasses.hpp"
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
//---------------------------------------------------------------------------
class TImportGeochronForm : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TLabel *Label1;
	TPanel *Panel2;
	TLabel *Label2;
	TcxRadioButton *cxRadioButton1;
	TcxRadioButton *cxRadioButton2;
	TcxRadioButton *cxRadioButton3;
	TcxRadioButton *cxRadioButton4;
	TFlowPanel *FlowPanel1;
	TcxButton *cxButton1;
	TcxButton *cxButton2;
	TLabel *Label3;
	TBevel *Bevel1;
	TcxRadioButton *cxRadioButton5;
	TcxRadioButton *cxRadioButton6;
	TcxImage *cxImage1;
	void __fastcall cxRadioButton1Click(TObject *Sender);
	void __fastcall cxRadioButton2Click(TObject *Sender);
	void __fastcall cxRadioButton3Click(TObject *Sender);
	void __fastcall cxRadioButton4Click(TObject *Sender);
	void __fastcall cxButton1Click(TObject *Sender);
	void __fastcall cxRadioButton5Click(TObject *Sender);
	void __fastcall cxRadioButton6Click(TObject *Sender);
private:	// User declarations
	int fnsigma;
	bool fcalibrate;
	short fcalibcurve;
public:		// User declarations
	__fastcall TImportGeochronForm(Variant latitude, TComponent* Owner);
	__property int nsigma = {read = fnsigma};
	__property bool calibrate = {read = fcalibrate};
	__property short calibcurve = {read = fcalibcurve};
};
//---------------------------------------------------------------------------
extern PACKAGE TImportGeochronForm *ImportGeochronForm;
//---------------------------------------------------------------------------
#endif
