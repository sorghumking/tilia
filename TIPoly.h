//---------------------------------------------------------------------------

#ifndef TIPolyH
#define TIPolyH
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
class TPolynomialOptionsForm : public TForm
{
__published:	// IDE-managed Components
        TcxSpinEdit *cxSpinEdit1;
        TLabel *Label1;
        TButton *Button1;
        TButton *Button2;
        TPanel *Panel1;
        TCheckBox *CheckBox1;
        TLabeledEdit *LabeledEdit1;
        TCheckBox *CheckBox2;
        void __fastcall CheckBox1Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall FormActivate(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TPolynomialOptionsForm(TComponent* Owner);
        double pFixedY;
        double pY0;
};
//---------------------------------------------------------------------------
extern PACKAGE TPolynomialOptionsForm *PolynomialOptionsForm;
//---------------------------------------------------------------------------
#endif
