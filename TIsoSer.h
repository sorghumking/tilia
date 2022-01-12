//---------------------------------------------------------------------------

#ifndef TIsoSerH
#define TIsoSerH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxDropDownEdit.hpp"
#include "cxEdit.hpp"
#include "cxGraphics.hpp"
#include "cxLabel.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include "cxMaskEdit.hpp"
#include "cxSpinEdit.hpp"
#include "cxTextEdit.hpp"
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
#include "cxButtons.hpp"
#include <Menus.hpp>
//---------------------------------------------------------------------------
#ifndef TISpreadH
#include "TISpread.h"
#endif
#ifndef TICommonH
#include "TICommon.h"
#endif
//---------------------------------------------------------------------------

class TIsotopeSeriesForm : public TForm
{
__published:	// IDE-managed Components
	TGridPanel *GridPanel1;
	TcxLabel *cxLabel1;
	TcxSpinEdit *cxSpinEdit1;
	TcxLabel *cxLabel2;
	TcxTextEdit *cxTextEdit1;
	TcxLabel *cxLabel3;
	TcxTextEdit *cxTextEdit2;
	TcxLabel *cxLabel4;
	TcxTextEdit *cxTextEdit3;
	TcxLabel *cxLabel5;
	TcxComboBox *cxComboBox1;
	TcxLabel *cxLabel6;
	TcxComboBox *cxComboBox2;
	TcxLabel *cxLabel7;
	TcxComboBox *cxComboBox3;
	TcxLabel *cxLabel8;
	TFlowPanel *FlowPanel1;
	TcxButton *cxButton1;
	TcxButton *cxButton2;
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall cxButton1Click(TObject *Sender);
	void __fastcall cxTextEdit1PropertiesValidate(TObject *Sender, Variant &DisplayValue,
          TCaption &ErrorText, bool &Error);
	void __fastcall cxTextEdit2PropertiesValidate(TObject *Sender, Variant &DisplayValue,
          TCaption &ErrorText, bool &Error);
	void __fastcall cxTextEdit3PropertiesValidate(TObject *Sender, Variant &DisplayValue,
          TCaption &ErrorText, bool &Error);
private:	// User declarations
	TTilSpreadSheetForm* TSSForm;
	TPoint Position;
	ISOTOPESERIES FSeries;
	void FillComboBoxes(void);
	bool ValidateNumerical(Variant &DisplayValue, TCaption &ErrorText);
	void AssignFloatParam(UnicodeString& Text, Variant& Param);
public:		// User declarations
	__fastcall TIsotopeSeriesForm(TPoint& pos, TComponent* Owner);
	__fastcall TIsotopeSeriesForm(TPoint& pos, ISOTOPESERIES* series, TComponent* Owner);
	__property ISOTOPESERIES Series = {read = FSeries, write = FSeries};
};
//---------------------------------------------------------------------------
extern PACKAGE TIsotopeSeriesForm *IsotopeSeriesForm;
//---------------------------------------------------------------------------
#endif
