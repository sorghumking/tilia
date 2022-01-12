//---------------------------------------------------------------------------

#ifndef TIsoDatH
#define TIsoDatH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "cxBlobEdit.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxDropDownEdit.hpp"
#include "cxEdit.hpp"
#include "cxGraphics.hpp"
#include "cxLabel.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include "cxMaskEdit.hpp"
#include "cxMemo.hpp"
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
#include "AdvCGrid.hpp"
#include "AdvGrid.hpp"
#include "AdvObj.hpp"
#include "AdvUtil.hpp"
#include "BaseGrid.hpp"
#include <Grids.hpp>
#include "cxButtons.hpp"
#include <Menus.hpp>
//---------------------------------------------------------------------------
#ifndef TISpreadH
#include "TISpread.h"
#endif
//---------------------------------------------------------------------------

class TIsoDatasetMetadataForm : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TGridPanel *GridPanel1;
	TcxLabel *cxLabel1;
	TcxTextEdit *cxTextEdit1;
	TcxLabel *cxLabel2;
	TcxTextEdit *cxTextEdit2;
	TcxLabel *cxLabel3;
	TcxTextEdit *cxTextEdit3;
	TPanel *Panel2;
	TGridPanel *GridPanel2;
	TcxLabel *cxLabel4;
	TcxComboBox *cxComboBox1;
	TcxLabel *cxLabel5;
	TcxComboBox *cxComboBox2;
	TPanel *Panel4;
	TcxLabel *cxLabel6;
	TPanel *Panel3;
	TGridPanel *GridPanel4;
	TPanel *Panel5;
	TcxLabel *cxLabel7;
	TcxLabel *cxLabel8;
	TcxBlobEdit *cxBlobEdit2;
	TcxBlobEdit *cxBlobEdit3;
	TPanel *Panel6;
	TAdvColumnGrid *AdvStandardsGrid;
	TFlowPanel *FlowPanel1;
	TcxButton *cxButton1;
	TcxButton *cxButton2;
	TPanel *Panel7;
	TcxTextEdit *cxTextEdit4;
	TcxLabel *cxLabel9;
	TcxTextEdit *cxTextEdit5;
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall AdvStandardsGridGetEditorProp(TObject *Sender, int ACol, int ARow,
          TEditLink *AEditLink);
	void __fastcall cxButton1Click(TObject *Sender);
	void __fastcall cxTextEdit1PropertiesValidate(TObject *Sender, Variant &DisplayValue,
		  TCaption &ErrorText, bool &Error);
	void __fastcall cxTextEdit2PropertiesValidate(TObject *Sender, Variant &DisplayValue,
		  TCaption &ErrorText, bool &Error);
	void __fastcall cxTextEdit3PropertiesValidate(TObject *Sender, Variant &DisplayValue,
		  TCaption &ErrorText, bool &Error);
	void __fastcall AdvStandardsGridCellValidate(TObject *Sender, int ACol, int ARow,
          UnicodeString &Value, bool &Valid);
	void __fastcall AdvStandardsGridClipboardPasteDone(TObject *Sender, TGridRect &CellRect);
	void __fastcall AdvStandardsGridGetDisplText(TObject *Sender, int ACol, int ARow,
          UnicodeString &Value);
	void __fastcall GridPanel1Resize(TObject *Sender);
	void __fastcall GridPanel2Resize(TObject *Sender);
	void __fastcall cxTextEdit4PropertiesValidate(TObject *Sender, Variant &DisplayValue,
          TCaption &ErrorText, bool &Error);
	void __fastcall cxTextEdit5PropertiesValidate(TObject *Sender, Variant &DisplayValue,
          TCaption &ErrorText, bool &Error);

private:	// User declarations
	TTilSpreadSheetForm* TSSForm;
	short Isotope;
	bool activated;
	bool standards_set;
	TPoint Position;
public:		// User declarations
	__fastcall TIsoDatasetMetadataForm(TPoint& pos, short isotope, TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TIsoDatasetMetadataForm *IsoDatasetMetadataForm;
//---------------------------------------------------------------------------
#endif
