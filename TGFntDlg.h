//---------------------------------------------------------------------------

#ifndef TGFntDlgH
#define TGFntDlgH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxDropDownEdit.hpp"
#include "cxEdit.hpp"
#include "cxFontNameComboBox.hpp"
#include "cxGraphics.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#ifndef TGTextH
#include "TGText.h"
#endif
//---------------------------------------------------------------------------
class TFontDialogBox : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label2;
        TComboBox *ComboBox1;
        TColorBox *ColorBox1;
        TLabel *Label3;
        TLabel *Label4;
        TButton *Button1;
        TButton *Button2;
        TButton *Button3;
        TcxFontNameComboBox *cxFontNameComboBox1;
        void __fastcall Button3Click(TObject *Sender);
        bool __fastcall FormHelp(WORD Command, int Data, bool &CallHelp);
private:	// User declarations
public:		// User declarations
        __fastcall TFontDialogBox(TComponent* Owner);
        void SetFont(MYFONT&);
        void GetFont(MYFONT&);
};
//---------------------------------------------------------------------------
extern PACKAGE TFontDialogBox *FontDialogBox;
//---------------------------------------------------------------------------
#endif
