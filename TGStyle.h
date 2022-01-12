//---------------------------------------------------------------------------
#ifndef TGStyleH
#define TGStyleH
//---------------------------------------------------------------------------

#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
#include <Dialogs.hpp>
#include <ImgList.hpp>
#include <ToolWin.hpp>
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxEdit.hpp"
#include "cxMaskEdit.hpp"
#include "cxSpinEdit.hpp"
#include "cxTextEdit.hpp"
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
#include "dxSkinOffice2016Colorful.hpp"
#include "dxSkinOffice2016Dark.hpp"
#include "dxSkinVisualStudio2013Blue.hpp"
#include "dxSkinVisualStudio2013Dark.hpp"
#include "dxSkinVisualStudio2013Light.hpp"
#include "cxColorComboBox.hpp"
#include "cxDropDownEdit.hpp"

#ifndef TGDiagrmH
#include "TGDiagrm.h"
#endif
#ifndef TGFormsH
#include "TGForms.h"
#endif
#ifndef TGUtilsH
#include "TGUtils.h"
#endif
class TXaxesForm;

typedef struct
{
double i;
bool show;
} SHORTSELECTION;

typedef struct
{
double x;
bool show;
} DOUBLESELECTION;


typedef struct
{
bool DepthBars;
bool DottedBaseLine;
bool TabSheetInitialized;
short SilhouetteFill;
short SilhouettePattern;
SHORTSELECTION Exag;
short ExagFill;
short ExagPattern;
short ExagGrid;
COLORSELECTION GraphColor;
COLORSELECTION ExagColor;
COLORSELECTION GraphOutlineColor;
COLORSELECTION ExagOutlineColor;
COLORSELECTION DepthBarsColor;
DOUBLESELECTION SilhouetteLineWidth;
} SILHOUTTEOPTIONS;

typedef struct
{
bool VerticalAxis;
bool TabSheetInitialized;
bool UseThickVar;
short BarFill;
short BarPattern;
COLORSELECTION GraphColor;
DOUBLESELECTION BarWidth;
DOUBLESELECTION HistogramLineWidth;
} HISTOGRAMOPTIONS;


typedef struct
{
bool ZeroSymbol;
bool SymbolName;
bool PlotGraphName;
bool TabSheetInitialized;
COLORSELECTION GraphColor;
bool   AutoMarkerTop;
bool   AutoMarkerBottom;
bool   marker_type_clicked;
short  MarkerType;
DOUBLESELECTION MarkerSize;
DOUBLESELECTION XMarkerLabel;
DOUBLESELECTION YMarkerLabel;
DOUBLESELECTION AngleMarkerLabel;
DOUBLESELECTION LineGraphLineWidth;
} LINEGRAPHOPTIONS;

typedef struct
{
bool TabSheetInitialized;
bool PlotZeroNumbers;
SHORTSELECTION DecimalPoints;
MYFONT NumberFont;
} NUMBEROPTIONS;

typedef struct
{
bool PresenceSymbol;
bool TabSheetInitialized;
COLORSELECTION GraphColor;
DOUBLESELECTION MarkerSize;
DOUBLESELECTION XPresence;
} PRESENCEOPTIONS;

//---------------------------------------------------------------------------
class TStyleForm : public TForm
{
__published:	// IDE-managed Components
        TPageControl *PageControl1;
        TTabSheet *TabSheet1;
        TTabSheet *TabSheet2;
        TTabSheet *TabSheet3;
        TTabSheet *TabSheet4;
        TTabSheet *TabSheet5;
        TButton *Button1;
        TButton *Button2;
        TButton *Button3;
        TRadioGroup *RadioGroup2;
        TGroupBox *GroupBox1;
        TRadioGroup *RadioGroup3;
        TCheckBox *CheckBox1;
        TCheckBox *CheckBox2;
        TButton *Button4;
        TRadioGroup *RadioGroup1;
        TButton *Button5;
        TButton *Button6;
        TShape *Shape1;
        TShape *Shape2;
        TGroupBox *GroupBox2;
        TComboBox *LineWidthComboBox1;
        TLabel *Label1;
        TCheckBox *CheckBox3;
        TToolBar *LineGraphToolBar;
        TToolButton *ToolButton1;
        TToolButton *ToolButton2;
        TImageList *MarkerImageList;
        TToolButton *ToolButton3;
        TToolButton *ToolButton4;
        TToolButton *ToolButton5;
        TToolButton *ToolButton6;
        TToolButton *ToolButton7;
        TToolButton *ToolButton8;
        TToolButton *ToolButton9;
        TToolButton *ToolButton10;
        TToolButton *ToolButton11;
        TToolButton *ToolButton12;
        TToolButton *ToolButton13;
        TToolButton *ToolButton14;
        TToolButton *ToolButton15;
        TToolButton *ToolButton16;
        TToolButton *ToolButton17;
        TToolButton *ToolButton18;
        TToolButton *ToolButton19;
        TToolButton *ToolButton20;
        TToolButton *ToolButton21;
        TToolButton *ToolButton22;
        TToolButton *ToolButton23;
        TToolButton *ToolButton24;
        TToolButton *ToolButton25;
        TToolButton *ToolButton26;
        TToolButton *ToolButton27;
        TToolButton *ToolButton28;
        TToolButton *ToolButton29;
        TToolButton *ToolButton30;
        TToolButton *ToolButton31;
        TToolButton *ToolButton32;
        TToolButton *ToolButton33;
        TCheckBox *CheckBox4;
        TRadioGroup *RadioGroup5;
        TGroupBox *GroupBox3;
        TCheckBox *CheckBox5;
        TLabel *Label6;
        TCheckBox *CheckBox6;
        TCheckBox *CheckBox7;
        TButton *Button18;
        TCheckBox *CheckBox8;
        TPanel *Panel1;
        TStaticText *StaticText2;
        TBitBtn *BitBtn1;
        TComboBox *LineWidthComboBox2;
        TLabel *Label10;
        TGroupBox *GroupBox4;
        TRadioGroup *RadioGroup4;
        TButton *Button11;
        TShape *Shape7;
        TGroupBox *GroupBox5;
        TComboBox *LineWidthComboBox3;
        TLabel *Label2;
        TRadioGroup *RadioGroup6;
        TLabel *Label12;
        TLabel *Label13;
        TLabel *Label14;
        TLabel *Label15;
        TLabel *Label16;
        TLabel *Label11;
        TLabeledEdit *LabeledEdit3;
        TLabel *Label3;
        TLabeledEdit *LabeledEdit4;
        TLabeledEdit *LabeledEdit5;
        TLabeledEdit *LabeledEdit7;
        TLabeledEdit *LabeledEdit8;
        TBitBtn *BitBtn2;
        TLabeledEdit *LabeledEdit9;
        TLabel *Label4;
        TPanel *Panel2;
        TPanel *Panel3;
        TPanel *Panel4;
        TPanel *Panel5;
        TPanel *Panel6;
        TPanel *Panel7;
        TcxSpinEdit *cxSpinEdit1;
        TLabel *Label5;
        TcxSpinEdit *cxSpinEdit2;
        TLabel *Label7;
        TcxSpinEdit *cxSpinEdit3;
        TLabel *Label8;
        TCheckBox *CheckBox9;
	TcxColorComboBox *cxColorComboBox1;
	TcxColorComboBox *cxColorComboBox2;
	TcxColorComboBox *cxColorComboBox3;
	TcxColorComboBox *cxColorComboBox4;
	TcxColorComboBox *cxColorComboBox5;
	TcxColorComboBox *cxColorComboBox6;
	TcxColorComboBox *cxColorComboBox7;
	TcxColorComboBox *cxColorComboBox8;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormActivate(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall RadioGroup3Click(TObject *Sender);
        void __fastcall Button5Click(TObject *Sender);
        void __fastcall RadioGroup2Click(TObject *Sender);
        void __fastcall Button6Click(TObject *Sender);
        void __fastcall RadioGroup4Click(TObject *Sender);
        void __fastcall Button11Click(TObject *Sender);
        void __fastcall CheckBox4Click(TObject *Sender);
        void __fastcall RadioGroup5Click(TObject *Sender);
        void __fastcall ToolButton1Click(TObject *Sender);
        void __fastcall ToolButton2Click(TObject *Sender);
        void __fastcall ToolButton3Click(TObject *Sender);
        void __fastcall ToolButton4Click(TObject *Sender);
        void __fastcall ToolButton5Click(TObject *Sender);
        void __fastcall ToolButton6Click(TObject *Sender);
        void __fastcall ToolButton7Click(TObject *Sender);
        void __fastcall ToolButton8Click(TObject *Sender);
        void __fastcall ToolButton9Click(TObject *Sender);
        void __fastcall ToolButton10Click(TObject *Sender);
        void __fastcall ToolButton11Click(TObject *Sender);
        void __fastcall ToolButton12Click(TObject *Sender);
        void __fastcall ToolButton13Click(TObject *Sender);
        void __fastcall ToolButton14Click(TObject *Sender);
        void __fastcall ToolButton15Click(TObject *Sender);
        void __fastcall ToolButton16Click(TObject *Sender);
        void __fastcall ToolButton17Click(TObject *Sender);
        void __fastcall ToolButton18Click(TObject *Sender);
        void __fastcall ToolButton19Click(TObject *Sender);
        void __fastcall ToolButton20Click(TObject *Sender);
        void __fastcall ToolButton21Click(TObject *Sender);
        void __fastcall ToolButton22Click(TObject *Sender);
        void __fastcall ToolButton23Click(TObject *Sender);
        void __fastcall ToolButton24Click(TObject *Sender);
        void __fastcall ToolButton25Click(TObject *Sender);
        void __fastcall ToolButton26Click(TObject *Sender);
        void __fastcall ToolButton27Click(TObject *Sender);
        void __fastcall ToolButton28Click(TObject *Sender);
        void __fastcall ToolButton29Click(TObject *Sender);
        void __fastcall ToolButton30Click(TObject *Sender);
        void __fastcall ToolButton31Click(TObject *Sender);
        void __fastcall ToolButton32Click(TObject *Sender);
        void __fastcall ToolButton33Click(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall LineWidthComboBox1Change(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall Button18Click(TObject *Sender);
        void __fastcall CheckBox2Click(TObject *Sender);
        void __fastcall CheckBox1Click(TObject *Sender);
        void __fastcall CheckBox3Click(TObject *Sender);
        void __fastcall CheckBox7Click(TObject *Sender);
        void __fastcall CheckBox5Click(TObject *Sender);
        void __fastcall CheckBox8Click(TObject *Sender);
        void __fastcall CheckBox6Click(TObject *Sender);
        void __fastcall BitBtn1Click(TObject *Sender);
        void __fastcall LineWidthComboBox2Change(TObject *Sender);
        void __fastcall RadioGroup6Click(TObject *Sender);
        void __fastcall LabeledEdit3Change(TObject *Sender);
        void __fastcall LabeledEdit4Change(TObject *Sender);
        void __fastcall LabeledEdit5Change(TObject *Sender);
        void __fastcall LabeledEdit7Change(TObject *Sender);
        void __fastcall LabeledEdit8Change(TObject *Sender);
        void __fastcall BitBtn2Click(TObject *Sender);
        void __fastcall LabeledEdit9Change(TObject *Sender);
        bool __fastcall FormHelp(WORD Command, int Data, bool &CallHelp);
        void __fastcall cxSpinEdit1PropertiesChange(TObject *Sender);
        void __fastcall cxSpinEdit2PropertiesChange(TObject *Sender);
        void __fastcall cxSpinEdit2PropertiesValidate(TObject *Sender,
          Variant &DisplayValue, TCaption &ErrorText, bool &Error);
        void __fastcall cxSpinEdit1PropertiesValidate(TObject *Sender,
          Variant &DisplayValue, TCaption &ErrorText, bool &Error);
        void __fastcall cxSpinEdit3PropertiesValidate(TObject *Sender,
          Variant &DisplayValue, TCaption &ErrorText, bool &Error);
        void __fastcall cxSpinEdit3PropertiesChange(TObject *Sender);
        void __fastcall FormDestroy(TObject *Sender);
        void __fastcall CheckBox9Click(TObject *Sender);
	void __fastcall cxColorComboBox1PropertiesSelectCustomColor(TObject *Sender, TColor &AColor,
          UnicodeString &AColorDescription, bool &AddToList);
	void __fastcall cxColorComboBox1PropertiesInitPopup(TObject *Sender);
	void __fastcall cxColorComboBox1PropertiesChange(TObject *Sender);
	void __fastcall cxColorComboBox2PropertiesChange(TObject *Sender);
	void __fastcall cxColorComboBox2PropertiesInitPopup(TObject *Sender);
	void __fastcall cxColorComboBox2PropertiesSelectCustomColor(TObject *Sender, TColor &AColor,
          UnicodeString &AColorDescription, bool &AddToList);
	void __fastcall cxColorComboBox3PropertiesChange(TObject *Sender);
	void __fastcall cxColorComboBox3PropertiesInitPopup(TObject *Sender);
	void __fastcall cxColorComboBox3PropertiesSelectCustomColor(TObject *Sender, TColor &AColor,
          UnicodeString &AColorDescription, bool &AddToList);
	void __fastcall cxColorComboBox4PropertiesChange(TObject *Sender);
	void __fastcall cxColorComboBox4PropertiesInitPopup(TObject *Sender);
	void __fastcall cxColorComboBox4PropertiesSelectCustomColor(TObject *Sender, TColor &AColor,
          UnicodeString &AColorDescription, bool &AddToList);
	void __fastcall cxColorComboBox5PropertiesChange(TObject *Sender);
	void __fastcall cxColorComboBox5PropertiesInitPopup(TObject *Sender);
	void __fastcall cxColorComboBox5PropertiesSelectCustomColor(TObject *Sender, TColor &AColor,
          UnicodeString &AColorDescription, bool &AddToList);
	void __fastcall cxColorComboBox6PropertiesChange(TObject *Sender);
	void __fastcall cxColorComboBox6PropertiesInitPopup(TObject *Sender);
	void __fastcall cxColorComboBox6PropertiesSelectCustomColor(TObject *Sender, TColor &AColor,
          UnicodeString &AColorDescription, bool &AddToList);
	void __fastcall cxColorComboBox7PropertiesChange(TObject *Sender);
	void __fastcall cxColorComboBox7PropertiesInitPopup(TObject *Sender);
	void __fastcall cxColorComboBox7PropertiesSelectCustomColor(TObject *Sender, TColor &AColor,
          UnicodeString &AColorDescription, bool &AddToList);
	void __fastcall cxColorComboBox8PropertiesChange(TObject *Sender);
	void __fastcall cxColorComboBox8PropertiesInitPopup(TObject *Sender);
	void __fastcall cxColorComboBox8PropertiesSelectCustomColor(TObject *Sender, TColor &AColor,
          UnicodeString &AColorDescription, bool &AddToList);
private:	// User declarations
        int VarCount;
        int VarsChecked;
		bool Spawned;
        UnicodeString InitialVar;
        FORMVARLIST *VarList;
        SILHOUTTEOPTIONS SilOpt;
        HISTOGRAMOPTIONS HistOpt;
        LINEGRAPHOPTIONS LineOpt;
        NUMBEROPTIONS NumOpt;
        TXaxesForm *XaxesForm;
        LineWidthComboBox *SilhLineWidthComboBox;
        LineWidthComboBox *LiGrLineWidthComboBox;
        LineWidthComboBox *HistLineWidthComboBox;
        void SelectTabSheet(short);
        void InitSilhouetteOptions(GRAPHS *);
        void InitHistogramOptions(GRAPHS *);
        void InitLineGraphOptions(GRAPHS *, XAXIS *);
        void InitNumberOptions(GRAPHS *);
        void InitPresenceOptions(GRAPHS *);
        void MultipleSilhouetteOptions(void);
        void MultipleHistogramOptions(void);
        void MultipleLineGraphOptions();
        void MultipleNumberOptions(void);
        void MultiplePresenceOptions(void);
        void InitSilhouetteTabSheet(void);
        void InitHistogramTabSheet(void);
        void InitHistogramLines(void);
        void InitHistogramBars(void);
        void InitLineGraphTabSheet(void);
        void InitNumberTabSheet(void);
        void InitPresenceTabSheet(void);
        void ApplyOptions(void);
        void SetSilhouetteOptions(void);
        void ApplySilhouetteOptions(GRAPHS *);
        void SetHistogramOptions(void);
        void ApplyHistogramOptions(GRAPHS *);
        void SetLineGraphOptions(void);
        void ApplyLineGraphOptions(GRAPHS *, XAXIS *);
        void SetNumberOptions(void);
        void ApplyNumberOptions(GRAPHS *);
        void SetPresenceOptions(void);
        void ApplyPresenceOptions(GRAPHS *, XAXIS *);
        void EnableLabels(void);
        void InitializeForm(void);
        void SetGraphColors(TColor);
        void MakeVarList(void);
public:		// User declarations
        __fastcall TStyleForm(TComponent* Owner);
        TTGDiagram* Diag;
        void Spawn(FORMVARLIST *, int, TXaxesForm *);
		void SetInitialVar(UnicodeString&);
        PRESENCEOPTIONS PresOpt;
};
//---------------------------------------------------------------------------
extern PACKAGE TStyleForm *StyleForm;
//---------------------------------------------------------------------------
#endif
