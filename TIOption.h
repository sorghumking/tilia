//---------------------------------------------------------------------------

#ifndef TIOptionH
#define TIOptionH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxDropDownEdit.hpp"
#include "cxEdit.hpp"
#include "cxFontNameComboBox.hpp"
#include "cxGraphics.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include <ExtCtrls.hpp>
//#include "CSPIN.h"
#include "cxSpinEdit.hpp"
#include "cxLabel.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include "cxButtons.hpp"
#include <Menus.hpp>
#include "cxShellComboBox.hpp"
#include "cxShellCommon.hpp"
#include <ComCtrls.hpp>
#include <ShlObj.hpp>
#include "cxRadioGroup.hpp"
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
#ifndef TISpreadH
#include "TISpread.h"
#endif
//---------------------------------------------------------------------------
class TSSOptionsForm : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label2;
	TcxFontNameComboBox *cxFontNameComboBox1;
	TGroupBox *GroupBox1;
	TCheckBox *CheckBox1;
	TCheckBox *CheckBox2;
	TCheckBox *CheckBox3;
	TCheckBox *CheckBox4;
	TCheckBox *CheckBox5;
	TCheckBox *CheckBox6;
	TGroupBox *GroupBox2;
	TcxSpinEdit *cxSpinEdit1;
	TcxSpinEdit *cxSpinEdit2;
	TLabel *Label3;
	TLabel *Label1;
	TcxSpinEdit *cxSpinEdit3;
	TLabel *Label4;
	TcxSpinEdit *cxSpinEdit4;
	TGroupBox *GroupBox3;
	TCheckBox *CheckBox7;
	TCheckBox *CheckBox8;
	TcxSpinEdit *cxSpinEdit5;
	TLabel *Label5;
	TcxSpinEdit *cxSpinEdit6;
	TLabel *Label6;
	TGroupBox *GroupBox4;
	TcxSpinEdit *cxSpinEdit7;
	TLabel *Label7;
	TRadioGroup *RadioGroup1;
	TGroupBox *GroupBox5;
	TcxButton *cxButton1;
	TcxButton *cxButton2;
	TcxShellComboBox *cxShellComboBox1;
	TCheckBox *CheckBox9;
	TcxSpinEdit *cxSpinEdit8;
	TLabel *Label8;
	TFlowPanel *FlowPanel1;
	TcxRadioButton *cxRadioButton1;
	TcxRadioButton *cxRadioButton2;
	TCheckBox *CheckBox10;
	TGroupBox *GroupBox6;
	TcxTextEdit *cxTextEdit1;
	TGroupBox *GroupBox7;
	TcxTextEdit *cxTextEdit2;
		void __fastcall cxButton1Click(TObject *Sender);
	void __fastcall cxRadioButton1Click(TObject *Sender);
	void __fastcall cxRadioButton2Click(TObject *Sender);
private:	// User declarations
	TTilSpreadSheetForm* TSSForm;
	int OldPercentDecimalPlaces;
	int OldConcDecimalPlaces;
	int OldInfluxDecimalPlaces;
	UnicodeString OldLookupPath;
public:		// User declarations
	__fastcall TSSOptionsForm(TComponent* Owner);
	int PercentDecimalPlaces;
	int ConcDecimalPlaces;
	int InfluxDecimalPlaces;
};
//---------------------------------------------------------------------------
extern PACKAGE TSSOptionsForm *SSOptionsForm;
//---------------------------------------------------------------------------
#endif
