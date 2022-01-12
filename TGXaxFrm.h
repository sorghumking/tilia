//---------------------------------------------------------------------------

#ifndef TGXaxFrmH
#define TGXaxFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Dialogs.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------

#ifndef TGDiagrmH
#include "TGDiagrm.h"
#endif
#ifndef TGH
#include "tg.h"
#endif
#ifndef TGFormsH
#include "TGForms.h"
#endif
#ifndef TGUtilsH
#include "TGUtils.h"
#endif
class TStyleForm;

typedef struct
{
bool ShowAxisLength;
bool ShowGraphWidth;
bool ShowXfac;
bool AutoMinChanged;
bool AutoMaxChanged;
bool ShowAutoMin;
bool ShowAutoMax;
bool ShowAxisLabel;
bool ShowLineWidth;
bool ShowAxisColor;
bool ShowBetweenGrf;
bool ShowAutoTic;
bool ShowMinorTics;
bool ShowMajorTics;
bool ShowLabelledTics;
bool ShowLenMinorTic;
bool ShowLenMajorTic;
bool ShowLenTopTic;
bool ShowTicLabDist;
bool ShowTicFac;
bool ShowTicDec;
bool ShowLabelOrigin;
bool ShowGridLines;
bool ShowGridLineWidth;
bool ShowAngle;
bool ShowXOffSet;
bool ShowYOffSet;
bool ShowTruncate;
bool ShowTruncWhere;
bool ShowTruncPrinted;
bool ShowTruncScaled;
bool ShowTruncNdec;
XAXIS xax;
} XOPTIONS;


class TXaxesForm : public TForm
{
__published:	// IDE-managed Components
        TPageControl *PageControl1;
        TTabSheet *TabSheet1;
        TTabSheet *TabSheet2;
        TTabSheet *TabSheet3;
        TTabSheet *TabSheet4;
        TGroupBox *GroupBox1;
        TEdit *Edit3;
        TGroupBox *GroupBox2;
        TEdit *Edit5;
        TCheckBox *CheckBox1;
        TGroupBox *GroupBox3;
        TCheckBox *CheckBox2;
        TEdit *Edit4;
        TComboBox *LineWidthComboBox1;
        TLabel *Label1;
        TButton *Button2;
        TRadioGroup *RadioGroup1;
        TEdit *Edit1;
        TEdit *Edit2;
        TPanel *Panel1;
        TStaticText *StaticText1;
        TButton *Button3;
        TButton *CancelButton;
        TButton *Button5;
        TButton *Button6;
        TColorDialog *ColorDialog1;
        TGroupBox *GroupBox4;
        TCheckBox *CheckBox3;
        TGroupBox *GroupBox5;
        TGroupBox *GroupBox6;
        TGroupBox *GroupBox7;
        TCheckBox *CheckBox6;
        TGroupBox *GroupBox8;
        TCheckBox *CheckBox7;
        TRadioGroup *RadioGroup2;
        TGroupBox *GroupBox9;
        TCheckBox *CheckBox8;
        TCheckBox *CheckBox9;
        TRadioGroup *RadioGroup3;
        TCheckBox *CheckBox4;
        TBitBtn *BitBtn1;
        TComboBox *LineWidthComboBox2;
        TLabel *Label14;
        TColorBox *ColorBox2;
        TLabeledEdit *LabeledEdit1;
        TLabeledEdit *LabeledEdit2;
        TLabeledEdit *LabeledEdit3;
        TLabeledEdit *LabeledEdit4;
        TLabeledEdit *LabeledEdit5;
        TLabeledEdit *LabeledEdit6;
        TLabeledEdit *LabeledEdit7;
        TLabeledEdit *LabeledEdit8;
        TLabeledEdit *LabeledEdit9;
        TLabeledEdit *LabeledEdit10;
        TLabeledEdit *LabeledEdit11;
        TLabeledEdit *LabeledEdit12;
        TLabeledEdit *LabeledEdit13;
        TLabeledEdit *LabeledEdit14;
        TLabel *Label2;
        TBitBtn *BitBtn2;
        TBitBtn *BitBtn3;
        TBitBtn *BitBtn4;
        TBitBtn *BitBtn5;
        TPanel *Panel2;
        void __fastcall FormActivate(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall RadioGroup1Click(TObject *Sender);
        void __fastcall Button6Click(TObject *Sender);
        void __fastcall CheckBox1Click(TObject *Sender);
        void __fastcall Edit3Change(TObject *Sender);
        void __fastcall CheckBox2Click(TObject *Sender);
        void __fastcall Edit4Change(TObject *Sender);
        void __fastcall LineWidthComboBox1Change(TObject *Sender);
        void __fastcall Edit5Change(TObject *Sender);
        void __fastcall CheckBox3Click(TObject *Sender);
        void __fastcall GroupBox4Exit(TObject *Sender);
        void __fastcall GroupBox6Exit(TObject *Sender);
        void __fastcall GroupBox5Exit(TObject *Sender);
        void __fastcall CheckBox4Click(TObject *Sender);
        void __fastcall RadioGroup3Click(TObject *Sender);
        void __fastcall RadioGroup1Exit(TObject *Sender);
        void __fastcall Edit1Exit(TObject *Sender);
        void __fastcall Edit2Exit(TObject *Sender);
        void __fastcall GroupBox1Exit(TObject *Sender);
        void __fastcall GroupBox3Exit(TObject *Sender);
        void __fastcall GroupBox8Exit(TObject *Sender);
        void __fastcall CheckBox6Click(TObject *Sender);
        void __fastcall GroupBox7Exit(TObject *Sender);
        void __fastcall CheckBox7Click(TObject *Sender);
        void __fastcall CheckBox8Click(TObject *Sender);
        void __fastcall CheckBox9Click(TObject *Sender);
        void __fastcall BitBtn1Click(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall RadioGroup2Click(TObject *Sender);
        void __fastcall LineWidthComboBox2Change(TObject *Sender);
        void __fastcall ColorBox2Change(TObject *Sender);
        void __fastcall LabeledEdit1Change(TObject *Sender);
        void __fastcall LabeledEdit2Change(TObject *Sender);
        void __fastcall LabeledEdit3Change(TObject *Sender);
        void __fastcall LabeledEdit4Change(TObject *Sender);
        void __fastcall LabeledEdit4Exit(TObject *Sender);
        void __fastcall LabeledEdit5Change(TObject *Sender);
        void __fastcall LabeledEdit6Change(TObject *Sender);
        void __fastcall LabeledEdit7Change(TObject *Sender);
        void __fastcall LabeledEdit8Change(TObject *Sender);
        void __fastcall LabeledEdit9Change(TObject *Sender);
        void __fastcall LabeledEdit10Change(TObject *Sender);
        void __fastcall LabeledEdit11Change(TObject *Sender);
        void __fastcall LabeledEdit12Change(TObject *Sender);
        void __fastcall LabeledEdit13Change(TObject *Sender);
        void __fastcall LabeledEdit14Change(TObject *Sender);
        void __fastcall BitBtn2Click(TObject *Sender);
        void __fastcall BitBtn3Click(TObject *Sender);
        void __fastcall BitBtn4Click(TObject *Sender);
        void __fastcall BitBtn5Click(TObject *Sender);
        void __fastcall Edit5Exit(TObject *Sender);
        void __fastcall Button5Click(TObject *Sender);
        bool __fastcall FormHelp(WORD Command, int Data, bool &CallHelp);
        void __fastcall FormDestroy(TObject *Sender);
private:	// User declarations
        int VarCount;
        int VarsChecked;
        bool NoChange;
        bool Cancel;
        bool Spawned;
        bool Activated;
		UnicodeString InitialVar;
        FORMVARLIST *VarList;
        TStyleForm *StyleForm;
        LineWidthComboBox *AxisLineWidthComboBox;
        LineWidthComboBox *GridLineWidthComboBox;
        void InitOptions(XAXIS *);
        void MultipleOptions(void);
        void ApplyOptions(void);
        void ExecuteOptions(XAXIS *, GRAPHS*);
        bool CheckFixedWidth(void);
        bool CheckScaleFactor(void);
        void InitializeForm(void);
        void MakeVarList(void);
        void PrintTruncValuesMenu(void);
public:		// User declarations
        __fastcall TXaxesForm(TComponent* Owner);
        XOPTIONS X;
        TTGDiagram* Diag;
        void Spawn(FORMVARLIST *, int, TStyleForm *);
        void SetInitialVar(UnicodeString&);
};
//---------------------------------------------------------------------------
extern PACKAGE TXaxesForm *XaxesForm;
//---------------------------------------------------------------------------
#endif
