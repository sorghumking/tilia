//---------------------------------------------------------------------------

#ifndef TGColorsH
#define TGColorsH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Dialogs.hpp>
#include "cxButtons.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include <Menus.hpp>
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
//---------------------------------------------------------------------------
class TColorsForm : public TForm
{
__published:	// IDE-managed Components
	TColorDialog *ColorDialog1;
	TColorBox *ColorBox1;
	TLabel *Label1;
	TColorBox *ColorBox2;
	TLabel *Label2;
	TColorBox *ColorBox3;
	TLabel *Label3;
	TColorBox *ColorBox4;
	TLabel *Label4;
	TColorBox *ColorBox5;
	TLabel *Label5;
	TColorBox *ColorBox6;
	TLabel *Label6;
	TColorBox *ColorBox7;
	TLabel *Label7;
	TColorBox *ColorBox8;
	TLabel *Label8;
	TColorBox *ColorBox9;
	TLabel *Label9;
	TColorBox *ColorBox10;
	TLabel *Label10;
	TColorBox *ColorBox11;
	TLabel *Label11;
	TColorBox *ColorBox12;
	TLabel *Label12;
	TColorBox *ColorBox13;
	TLabel *Label13;
	TcxButton *cxButton1;
	TcxButton *cxButton2;
	TcxButton *cxButton3;
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall ColorBox1Change(TObject *Sender);
	void __fastcall ColorBox2Change(TObject *Sender);
	void __fastcall ColorBox3Change(TObject *Sender);
	void __fastcall ColorBox4Change(TObject *Sender);
	void __fastcall ColorBox5Change(TObject *Sender);
	void __fastcall ColorBox6Change(TObject *Sender);
	void __fastcall ColorBox7Change(TObject *Sender);
	void __fastcall ColorBox8Change(TObject *Sender);
	void __fastcall ColorBox9Change(TObject *Sender);
	void __fastcall ColorBox10Change(TObject *Sender);
	void __fastcall ColorBox11Change(TObject *Sender);
	bool __fastcall FormHelp(WORD Command, int Data, bool &CallHelp);
	void __fastcall ColorBox12Change(TObject *Sender);
	void __fastcall ColorBox13Change(TObject *Sender);
	void __fastcall cxButton2Click(TObject *Sender);
	void __fastcall cxButton1Click(TObject *Sender);
private:	// User declarations
	bool g_color_changed;
	bool go_color_changed;
	bool e_color_changed;
	bool eo_color_changed;
	bool db_color_changed;
	bool a_color_changed;
	bool t_color_changed;
	bool z_color_changed;
	bool group_color_changed;
	bool date_color_changed;
	bool lith_color_changed;
	bool dend_color_changed;
	TTGDiagram *Diag;
public:		// User declarations
	__fastcall TColorsForm(TComponent* Owner);
	bool color_changed;
};
//---------------------------------------------------------------------------
extern PACKAGE TColorsForm *ColorsForm;
//---------------------------------------------------------------------------
#endif
