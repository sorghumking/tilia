//---------------------------------------------------------------------------

#ifndef TIAddCalH
#define TIAddCalH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "cxButtons.hpp"
#include "cxLookAndFeelPainters.hpp"
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include "cxGraphics.hpp"
#include "cxLookAndFeels.hpp"
//---------------------------------------------------------------------------
class TAddCalibProgForm : public TForm
{
__published:	// IDE-managed Components
        TLabeledEdit *LabeledEdit1;
        TLabeledEdit *LabeledEdit2;
        TcxButton *cxButton1;
        TcxButton *cxButton2;
        void __fastcall FormActivate(TObject *Sender);
        void __fastcall cxButton1Click(TObject *Sender);
private:	// User declarations
        int top;
        int left;
public:		// User declarations
        __fastcall TAddCalibProgForm(TComponent* Owner);
        void SetPosition(int l, int t) { left = l; top = t; }
};
//---------------------------------------------------------------------------
extern PACKAGE TAddCalibProgForm *AddCalibProgForm;
//---------------------------------------------------------------------------
#endif
