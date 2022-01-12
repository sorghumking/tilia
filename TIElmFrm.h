//---------------------------------------------------------------------------

#ifndef TIElmFrmH
#define TIElmFrmH
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
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include <ExtCtrls.hpp>
#include "cxCheckComboBox.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include "cxCheckBox.hpp"
#include "cxCheckListBox.hpp"
#include "cxListBox.hpp"
#include "cxButtons.hpp"
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

//#ifndef TSUtilsH
//#include "TSUtils.h"
//#endif
#ifndef TICommonH
#include "TICommon.h"
#endif

//---------------------------------------------------------------------------
class TElementForm : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label2;
	TPanel *Panel1;
	TLabel *Label1;
	TLabel *Label3;
	TLabel *Label4;
	TcxComboBox *cxComboBox4;
	TLabel *Label5;
	TLabel *Label6;
	TcxComboBox *cxComboBox3;
	TLabel *Label7;
	TcxCheckListBox *cxCheckListBox1;
	TcxListBox *cxListBox1;
	TcxCheckListBox *cxCheckListBox2;
	TcxCheckListBox *cxCheckListBox3;
	TFlowPanel *FlowPanel1;
	TcxButton *cxButton1;
	TcxButton *cxButton2;
	TFlowPanel *FlowPanel2;
	void __fastcall cxListBox1Click(TObject *Sender);
	void __fastcall cxCheckListBox1ClickCheck(TObject *Sender, int AIndex, TcxCheckBoxState APrevState,
          TcxCheckBoxState ANewState);
	void __fastcall cxCheckListBox2ClickCheck(TObject *Sender, int AIndex, TcxCheckBoxState APrevState,
          TcxCheckBoxState ANewState);
	void __fastcall cxCheckListBox3ClickCheck(TObject *Sender, int AIndex, TcxCheckBoxState APrevState,
          TcxCheckBoxState ANewState);
	void __fastcall cxComboBox4Click(TObject *Sender);
	void __fastcall cxComboBox3Click(TObject *Sender);
private:	// User declarations
	UnicodeString DatasetType;
	UnicodeString TaxaGroup;
	ELEMENTLOOKUP* ElementLookup;
	UnicodeString Element;
	UnicodeString Symmetry;
	UnicodeString Portion;
	UnicodeString Maturity;
	//set<UnicodeString> Portions;
	//set<UnicodeString> Maturities;
	map<UnicodeString, map<UnicodeString, ELEMENTMODIFIERS> > AllModifiers;
private:
	void BuildElement(void);
	void SetElements(UnicodeString DatasetType, UnicodeString TaxaGroup);
	void UncheckAll(TcxCheckListBox* cxCheckListBox);
	void SetElement(void);
public:		// User declarations
	__fastcall TElementForm(UnicodeString DatasetType, UnicodeString TaxaGroup,
		UnicodeString Element, ELEMENTLOOKUP* elem_lookup, TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TElementForm *ElementForm;
//---------------------------------------------------------------------------
#endif
