//---------------------------------------------------------------------------

#ifndef TILOWESSH
#define TILOWESSH
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
class TLOWESSOptionsForm : public TForm
{
__published:	// IDE-managed Components
        TcxSpinEdit *cxSpinEdit1;
        TcxSpinEdit *cxSpinEdit2;
        TLabel *Label2;
        TButton *Button1;
        TButton *Button2;
        TRadioGroup *RadioGroup1;
        TEdit *Edit1;
        TEdit *Edit2;
        void __fastcall RadioGroup1Click(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormActivate(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
        int nChronControls;
        double MinDepth;
        double MaxDepth;
        double MinAge;
        double MaxAge;
public:		// User declarations
        __fastcall TLOWESSOptionsForm(TComponent* Owner);
        void SetMinMax(int n, double mnd, double mxd, double mna, double mxa)
          { nChronControls=n; MinDepth=mnd; MaxDepth=mxd; MinAge=mna; MaxAge=mxa; }
        double DepthWindow;
        double AgeWindow;
};
//---------------------------------------------------------------------------
extern PACKAGE TLOWESSOptionsForm *LOWESSOptionsForm;
//---------------------------------------------------------------------------
#endif
