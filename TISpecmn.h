//---------------------------------------------------------------------------

#ifndef TISpecmnH
#define TISpecmnH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "cxButtons.hpp"
#include "cxGraphics.hpp"
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
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxDropDownEdit.hpp"
#include "cxEdit.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
//---------------------------------------------------------------------------
#ifndef TISpreadH
#include "TISpread.h"
#endif
//---------------------------------------------------------------------------
/*
class SPECIMEN
{
private:
	UnicodeString FElement;
	UnicodeString FSymmetry;
	UnicodeString FPortion;
	UnicodeString FMaturity;
	Variant FNISP;
	UnicodeString FRepository;
	UnicodeString FSpecNr;
	UnicodeString FNotes;
public:
	SPECIMEN() { };
	__property UnicodeString Element = {read = FElement, write = FElement};
	__property UnicodeString Symmetry = {read = FSymmetry, write = FSymmetry};
	__property UnicodeString Portion = {read = FPortion, write = FPortion};
	__property UnicodeString Maturity = {read = FMaturity, write = FMaturity};
	__property Variant NISP = {read = FNISP, write = FNISP};
	__property UnicodeString Repository = {read = FRepository, write = FRepository};
	__property UnicodeString SpecNr = {read = FSpecNr, write = FSpecNr};
	__property UnicodeString Notes = {read = FNotes, write = FNotes};

};
*/
//---------------------------------------------------------------------------

class TSpecDataForm : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TFlowPanel *FlowPanel1;
	TcxButton *cxButton1;
	TcxButton *cxButton2;
	TPanel *Panel2;
	TcxComboBox *cxComboBox1;
	void __fastcall FormActivate(TObject *Sender);
private:	// User declarations
	TTilSpreadSheetForm* TSSForm;
	TPoint Position;
	TList* Specimens;
	bool repositories_set;
	//void FillElementList(void);
public:		// User declarations
	__fastcall TSpecDataForm(TPoint& pos, TList* specimens, TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TSpecDataForm *SpecDataForm;
//---------------------------------------------------------------------------
#endif
