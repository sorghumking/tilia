//---------------------------------------------------------------------------

#ifndef TGGrpOptH
#define TGGrpOptH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Dialogs.hpp>
#include <Buttons.hpp>

#ifndef TGTextH
#include "TGText.h"
#endif
#ifndef TGUtilsH
#include "TGUtils.h"
#endif

//---------------------------------------------------------------------------
class TGroupOptionsForm : public TForm
{
__published:	// IDE-managed Components
        TRadioGroup *RadioGroup1;
        TGroupBox *GroupBox2;
        TComboBox *LineWidthComboBox1;
        TButton *Button4;
        TButton *Button5;
        TButton *Button6;
        TLabel *Label1;
        TCheckBox *CheckBox1;
        TColorDialog *ColorDialog1;
        TColorBox *ColorBox2;
        TLabel *Label3;
        TBitBtn *BitBtn1;
        void __fastcall Button6Click(TObject *Sender);
        void __fastcall BitBtn1Click(TObject *Sender);
        bool __fastcall FormHelp(WORD Command, int Data, bool &CallHelp);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormDestroy(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TGroupOptionsForm(TComponent* Owner);
        MYFONT GroupFont;
        LineWidthComboBox *GrupLineWidthComboBox;
};
//---------------------------------------------------------------------------
extern PACKAGE TGroupOptionsForm *GroupOptionsForm;
//---------------------------------------------------------------------------
#endif
