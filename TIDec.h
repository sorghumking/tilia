//---------------------------------------------------------------------------

#ifndef TIDecH
#define TIDecH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxEdit.hpp"
#include "cxMaskEdit.hpp"
#include "cxSpinEdit.hpp"
#include "cxTextEdit.hpp"
#include <ExtCtrls.hpp>
#include "cxGraphics.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
//---------------------------------------------------------------------------
class TSSFormatForm : public TForm
{
__published:	// IDE-managed Components
        TRadioGroup *RadioGroup1;
        TcxSpinEdit *cxSpinEdit1;
        TLabel *Label1;
        TCheckBox *CheckBox1;
        TCheckBox *CheckBox2;
        TButton *Button1;
        TButton *Button2;
        TRadioGroup *RadioGroup2;
        TRadioButton *RadioButton1;
        TRadioButton *RadioButton2;
        TPanel *Panel1;
        void __fastcall RadioButton1Click(TObject *Sender);
        void __fastcall RadioButton2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TSSFormatForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TSSFormatForm *SSFormatForm;
//---------------------------------------------------------------------------
#endif
