//---------------------------------------------------------------------------

#ifndef TGDgrFrmH
#define TGDgrFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <Dialogs.hpp>
#include "ipwCore.h"
#include "ipwxmlp.h"
#include "ipworks.h"
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
#ifndef TGDiagrmH
#include "TGDiagrm.h"
#endif
#ifndef TGH
#include "tg.h"
#endif
#ifndef TIXMLH
#include "TIXML.h"
#endif

//---------------------------------------------------------------------------
class TDendrogramForm : public TForm
{
__published:	// IDE-managed Components
	TRadioGroup *RadioGroup1;
	TGroupBox *GroupBox1;
	TEdit *Edit1;
	TGroupBox *GroupBox2;
	TEdit *Edit2;
	TGroupBox *GroupBox3;
	TLabeledEdit *LabeledEdit1;
	TLabeledEdit *LabeledEdit2;
	TCheckBox *CheckBox1;
	TGroupBox *GroupBox4;
	TLabeledEdit *LabeledEdit5;
	TLabeledEdit *LabeledEdit6;
	TLabeledEdit *LabeledEdit7;
	TLabeledEdit *LabeledEdit8;
	TGroupBox *GroupBox5;
	TLabeledEdit *LabeledEdit3;
	TLabeledEdit *LabeledEdit9;
	TGroupBox *GroupBox6;
	TColorBox *ColorBox1;
	TComboBox *LineWidthComboBox2;
	TLabel *Label1;
	TLabel *Label2;
	TGroupBox *GroupBox7;
	TLabeledEdit *LabeledEdit4;
	TColorBox *ColorBox2;
	TLabel *Label3;
	TComboBox *LineWidthComboBox1;
	TLabel *Label4;
	TCheckBox *CheckBox2;
	TOpenDialog *OpenDialog1;
	TipwXMLp *ipwXMLp1;
	TGroupBox *GroupBox8;
	TcxButton *cxButton1;
	TcxButton *cxButton2;
	TcxButton *cxButton3;
	TcxButton *cxButton4;
	TcxButton *cxButton5;
	TcxButton *cxButton6;
	TcxButton *cxButton7;
	TcxButton *cxButton8;
	TcxButton *cxButton9;
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall RadioGroup1Click(TObject *Sender);
	void __fastcall Edit2Exit(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall CheckBox1Click(TObject *Sender);
	bool __fastcall FormHelp(WORD Command, int Data, bool &CallHelp);
	void __fastcall ipwXMLp1StartElement(TObject *Sender, TipwXMLpStartElementEventParams *e);
	void __fastcall ipwXMLp1EndElement(TObject *Sender, TipwXMLpEndElementEventParams *e);
	void __fastcall ipwXMLp1Characters(TObject *Sender, TipwXMLpCharactersEventParams *e);
	void __fastcall cxButton1Click(TObject *Sender);
	void __fastcall cxButton2Click(TObject *Sender);
	void __fastcall cxButton3Click(TObject *Sender);
	void __fastcall cxButton4Click(TObject *Sender);
	void __fastcall cxButton5Click(TObject *Sender);
	void __fastcall cxButton6Click(TObject *Sender);
	void __fastcall cxButton7Click(TObject *Sender);
	void __fastcall cxButton9Click(TObject *Sender);

private:	// User declarations
	TTGDiagram* Diag;
	bool DGXFile;
	DENDROGRAM *InDgr;
	UnicodeString DendAxisLabels[4];
	MYFONT AxisLabelFont;
	MYFONT DendTitleFont;
	MYFONT TicFont;
	LineWidthComboBox *DendLineWidthComboBox;
	LineWidthComboBox *AxisLineWidthComboBox;
	UnicodeString MajorTics;
	UnicodeString MinorTics;
	void FillDialogBox(void);
	DGXXML dgx;
public:		// User declarations
	__fastcall TDendrogramForm(TComponent* Owner);

};
//---------------------------------------------------------------------------
extern PACKAGE TDendrogramForm *DendrogramForm;
//---------------------------------------------------------------------------
#endif
