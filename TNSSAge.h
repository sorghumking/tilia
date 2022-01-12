//---------------------------------------------------------------------------

#ifndef TNSSAgeH
#define TNSSAgeH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxEdit.hpp"
#include "cxGraphics.hpp"
#include "cxLabel.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include <ExtCtrls.hpp>
#include "cxRadioGroup.hpp"
#include "cxCalendar.hpp"
#include "cxDateUtils.hpp"
#include "cxDropDownEdit.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include "dxCore.hpp"
#include <ComCtrls.hpp>
#include "cxButtons.hpp"
#include <Menus.hpp>
#include "cxImage.hpp"
#include <Graphics.hpp>
#include "dxGDIPlusClasses.hpp"
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
#include "dxSkinOffice2016Colorful.hpp"
#include "dxSkinOffice2016Dark.hpp"
#include "dxSkinVisualStudio2013Blue.hpp"
#include "dxSkinVisualStudio2013Dark.hpp"
#include "dxSkinVisualStudio2013Light.hpp"
#include "cxCheckBox.hpp"

//---------------------------------------------------------------------------
enum SSSAMPLEAGESYTLE { dsEXACTDATE, dsYEAR, dsYEARRANGE };
//---------------------------------------------------------------------------

class TSurfaceSampleAgeForm : public TForm
{
__published:	// IDE-managed Components
	TcxLabel *cxLabel1;
	TcxRadioButton *cxRadioButton1;
	TcxRadioButton *cxRadioButton2;
	TcxRadioButton *cxRadioButton3;
	TFlowPanel *FlowPanel1;
	TcxDateEdit *cxDateEdit1;
	TFlowPanel *FlowPanel2;
	TcxTextEdit *cxTextEdit1;
	TPanel *Panel1;
	TFlowPanel *FlowPanel3;
	TcxTextEdit *cxTextEdit2;
	TcxLabel *cxLabel2;
	TcxTextEdit *cxTextEdit3;
	TPanel *Panel2;
	TcxRadioButton *cxRadioButton4;
	TcxRadioButton *cxRadioButton5;
	TPanel *Panel3;
	TcxRadioButton *cxRadioButton6;
	TcxRadioButton *cxRadioButton7;
	TFlowPanel *FlowPanel4;
	TcxButton *cxButton1;
	TcxButton *cxButton2;
	TcxButton *cxButton3;
	TcxImage *cxImage1;
	TcxImageList *cxImageList1;
	TcxCheckBox *cxCheckBox1;
	void __fastcall cxRadioButton1Click(TObject *Sender);
	void __fastcall cxRadioButton2Click(TObject *Sender);
	void __fastcall cxRadioButton3Click(TObject *Sender);
	void __fastcall cxTextEdit1PropertiesValidate(TObject *Sender, Variant &DisplayValue,
          TCaption &ErrorText, bool &Error);
	void __fastcall cxButton1Click(TObject *Sender);
	void __fastcall cxTextEdit3PropertiesValidate(TObject *Sender, Variant &DisplayValue,
		  TCaption &ErrorText, bool &Error);
private:	// User declarations
	int Year1, Year2;
	int FYearBP, FYearOlderBP, FYearYoungerBP;
	int FSampleAgeStyle;
	void GetYear(Variant &DisplayValue, UnicodeString &ErrorText, bool &Error, int &Year);
public:		// User declarations
	__fastcall TSurfaceSampleAgeForm(TComponent* Owner);
	void SetManual(void);
	__property int YearBP = {read = FYearBP};
	__property int YearOlderBP = {read = FYearOlderBP};
	__property int YearYoungerBP = {read = FYearYoungerBP};
	__property int SampleAgeStyle = {read = FSampleAgeStyle};
};
//---------------------------------------------------------------------------
extern PACKAGE TSurfaceSampleAgeForm *SurfaceSampleAgeForm;
//---------------------------------------------------------------------------
#endif
