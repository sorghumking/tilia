//---------------------------------------------------------------------------

#ifndef TIAdmUntH
#define TIAdmUntH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "cxCheckComboBox.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxDropDownEdit.hpp"
#include "cxEdit.hpp"
#include "cxGraphics.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include <ExtCtrls.hpp>
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include "cxButtons.hpp"
#include <Menus.hpp>
#include "cxCheckBox.hpp"
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
#ifndef TISpreadH
#include "TISpread.h"
#endif
//---------------------------------------------------------------------------
class TNewAdminUnit : public TForm
{
__published:	// IDE-managed Components
	TcxCheckComboBox *cxCheckComboBox1;
	TcxCheckComboBox *cxCheckComboBox2;
	TEdit *Edit1;
	TRadioButton *RadioButton1;
	TRadioButton *RadioButton2;
	TRadioButton *RadioButton3;
	TLabeledEdit *LabeledEdit1;
	TMemo *Memo1;
	TPanel *Panel1;
	TPanel *Panel2;
	TcxButton *cxButton1;
	TcxButton *cxButton2;
	TComboBox *ComboBox1;
	TLabel *Label1;
	TcxButton *cxButton3;
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall RadioButton3Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall RadioButton2Click(TObject *Sender);
	void __fastcall cxCheckComboBox2PropertiesClickCheck(
		TObject *Sender, int ItemIndex, bool &AllowToggle);
	void __fastcall cxButton1Click(TObject *Sender);
	void __fastcall cxCheckComboBox1PropertiesChange(TObject *Sender);
	void __fastcall cxCheckComboBox2PropertiesChange(TObject *Sender);
	void __fastcall cxButton3Click(TObject *Sender);
private:	// User declarations
	TTilSpreadSheetForm* TSSForm;
	bool Activated;
	int InitialStateItemIndex;
	map<UnicodeString, UnicodeString> GeoPol2Units;
	map<UnicodeString, UnicodeString> GeoPol3Units;
private:
	int ValidateSelections(void);
public:		// User declarations
	__fastcall TNewAdminUnit(TComponent* Owner);
	void SetGeoPol2Units(map<UnicodeString, UnicodeString>&);
	void SetGeoPol3Units(map<UnicodeString, UnicodeString>&);
	void ShowUploadButton(void);
	UnicodeString GetGeoPoliticalUnitType(void) { return ComboBox1->Text.LowerCase(); }
	bool SaveFile;
};
//---------------------------------------------------------------------------
extern PACKAGE TNewAdminUnit *NewAdminUnit;
//---------------------------------------------------------------------------
#endif
