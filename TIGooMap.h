//---------------------------------------------------------------------------

#ifndef TIGooMapH
#define TIGooMapH
//---------------------------------------------------------------------------
#include "UWebGMapsGeocoding.hpp"
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxEdit.hpp"
#include "cxGraphics.hpp"
#include "cxLabel.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include "cxButtons.hpp"
#include "cxGroupBox.hpp"
#include "cxRadioGroup.hpp"
#include "cxImage.hpp"
#include "cxTextEdit.hpp"
#include <ImgList.hpp>
#include <Menus.hpp>
#include "UWebGMaps.hpp"
#include "UWebGMapsCommon.hpp"
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
class TGoogleMapForm : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TWebGMaps *WebGMaps1;
	TFlowPanel *FlowPanel1;
	TcxLabel *cxLabel1;
	TcxLabel *cxLabel2;
	TcxLabel *cxLabel3;
	TcxLabel *cxLabel4;
	TFlowPanel *FlowPanel2;
	TcxLabel *cxLabel5;
	TcxLabel *cxLabel6;
	TcxLabel *cxLabel7;
	TcxLabel *cxLabel8;
	TcxLabel *cxLabel9;
	TcxLabel *cxLabel10;
	TcxLabel *cxLabel11;
	TcxLabel *cxLabel12;
	TFlowPanel *FlowPanel3;
	TcxButton *cxButton1;
	TcxButton *cxButton2;
	TPanel *Panel2;
	TPanel *Panel3;
	TPanel *Panel4;
	TcxButton *cxButton3;
	TPanel *Panel5;
	TcxButton *cxButton4;
	TPanel *Panel6;
	TcxGroupBox *cxGroupBox1;
	TcxGroupBox *cxGroupBox2;
	TcxGroupBox *cxGroupBox3;
	TcxRadioButton *cxRadioButton1;
	TcxRadioButton *cxRadioButton2;
	TcxImageList *cxImageList1;
	TcxButton *cxButton5;
	TFlowPanel *FlowPanel4;
	TcxButton *cxButton6;
	TcxButton *cxButton7;
	TcxImageList *cxImageList2;
	TFlowPanel *FlowPanel5;
	TcxTextEdit *cxTextEdit1;
	TcxButton *cxButton8;
	TWebGMapsGeocoding *WebGMapsGeocoding1;
	TcxLabel *cxLabel13;
	TcxLabel *cxLabel14;
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall WebGMaps1MapMouseMove(TObject *Sender, double Latitude, double Longitude,
          int X, int Y);
	void __fastcall cxButton1Click(TObject *Sender);
	void __fastcall WebGMaps1MapClick(TObject *Sender, double Latitude, double Longitude,
          int X, int Y, TMouseButton Button);
	void __fastcall WebGMaps1DownloadFinish(TObject *Sender);
	void __fastcall WebGMaps1MarkerDrag(TObject *Sender, UnicodeString MarkerTitle,
          int IdMarker, double Latitude, double Longitude);
	void __fastcall WebGMaps1MarkerDragEnd(TObject *Sender, UnicodeString MarkerTitle,
          int IdMarker, double Latitude, double Longitude);
	void __fastcall cxButton5Click(TObject *Sender);
	void __fastcall cxButton4Click(TObject *Sender);
	void __fastcall cxButton2Click(TObject *Sender);
	void __fastcall cxButton3Click(TObject *Sender);
	void __fastcall cxRadioButton1Click(TObject *Sender);
	void __fastcall cxRadioButton2Click(TObject *Sender);
	void __fastcall cxButton8Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
	double FLatNorth;
	double FLatSouth;
	double FLongWest;
	double FLongEast;
	bool activated;
	int cxGroupBox1Height;
public:		// User declarations
	__fastcall TGoogleMapForm(bool point, Variant lat_north, Variant lat_south,
		Variant long_west, Variant long_east, TComponent* Owner);
	__property double LatNorth = {read = FLatNorth};
	__property double LatSouth = {read = FLatSouth};
	__property double LongWest = {read = FLongWest};
	__property double LongEast = {read = FLongEast};
	bool point() { return cxRadioButton1->Checked; }
};
//---------------------------------------------------------------------------
extern PACKAGE TGoogleMapForm *GoogleMapForm;
//---------------------------------------------------------------------------
#endif
