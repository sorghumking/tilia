//---------------------------------------------------------------------------

#ifndef TGZoneScH
#define TGZoneScH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Dialogs.hpp>

#ifndef TGH
#include "tg.h"
#endif
#ifndef TGUtilsH
#include "TGUtils.h"
#endif
//---------------------------------------------------------------------------
class TZoneScreenForm : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TRadioGroup *RadioGroup1;
        TButton *Button1;
        TButton *Button2;
        TButton *Button3;
        TButton *Button5;
        TPaintBox *PaintBox1;
        TColorDialog *ColorDialog1;
        TCheckBox *CheckBox2;
        TGroupBox *GroupBox1;
        TCheckBox *CheckBox1;
        TComboBox *LineWidthComboBox1;
        TLabel *Label2;
        TColorBox *ColorBox1;
        TLabel *Label5;
        TColorBox *ColorBox2;
        TLabel *Label6;
        TLabeledEdit *LabeledEdit1;
        TLabeledEdit *LabeledEdit2;
        TGroupBox *GroupBox2;
        TLabeledEdit *LabeledEdit3;
        TRadioGroup *RadioGroup3;
        void __fastcall PaintBox1Paint(TObject *Sender);
        void __fastcall FormActivate(TObject *Sender);
        void __fastcall Button5Click(TObject *Sender);
        void __fastcall RadioGroup1Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall CheckBox1Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall ColorBox1Change(TObject *Sender);
        void __fastcall ColorBox2Change(TObject *Sender);
        void __fastcall LabeledEdit1Exit(TObject *Sender);
        void __fastcall LabeledEdit2Exit(TObject *Sender);
        bool __fastcall FormHelp(WORD Command, int Data, bool &CallHelp);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormDestroy(TObject *Sender);
private:	// User declarations
        Graphics::TBitmap *BrushBmp;
		short Pattern;
        TColor Color;
        TColor BorderColor;
        int Dash, Space;
		LineWidthComboBox *ZoneLineWidthComboBox;
		TTGDiagram* Diag;
public:		// User declarations
        __fastcall TZoneScreenForm(TComponent* Owner);
        ZONE* Zone;
};
//---------------------------------------------------------------------------
extern PACKAGE TZoneScreenForm *ZoneScreenForm;
//---------------------------------------------------------------------------
#endif
