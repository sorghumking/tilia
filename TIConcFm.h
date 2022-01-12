//---------------------------------------------------------------------------

#ifndef TIConcFmH
#define TIConcFmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <CheckLst.hpp>
#include "cxCheckListBox.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include <ExtCtrls.hpp>
#include "cxEdit.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"

#ifndef TISpreadH
#include "TISpread.h"
#endif

//---------------------------------------------------------------------------
class TConcForm : public TForm
{
__published:	// IDE-managed Components
        TcxCheckListBox *cxCheckListBox1;
        TRadioGroup *RadioGroup1;
        TLabel *Label1;
        TcxCheckListBox *cxCheckListBox4;
        TLabel *Label4;
        TcxCheckListBox *cxCheckListBox5;
        TLabel *Label5;
        TcxCheckListBox *cxCheckListBox3;
        TLabel *Label3;
        TButton *Button1;
        TButton *Button2;
        TcxCheckListBox *cxCheckListBox2;
        TLabel *Label2;
        TButton *Button3;
        TButton *Button4;
        TRadioGroup *RadioGroup2;
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall FormDestroy(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall RadioGroup1Click(TObject *Sender);
private:	// User declarations
        TTilSpreadSheetForm* TSSForm;
        TStringList* Elements;
public:		// User declarations
        __fastcall TConcForm(TComponent* Owner);
        int TreatNulls;
};
//---------------------------------------------------------------------------
extern PACKAGE TConcForm *ConcForm;
//---------------------------------------------------------------------------
#endif
