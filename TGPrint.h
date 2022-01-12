//---------------------------------------------------------------------------
#ifndef TGPrintH
#define TGPrintH
#ifndef TGDiagrmH
#include "TGDiagrm.h"
#include <Classes.hpp>
#include <ComCtrls.hpp>
#include <Controls.hpp>
#include <ExtCtrls.hpp>
#include <StdCtrls.hpp>
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxEdit.hpp"
#include "cxMaskEdit.hpp"
#include "cxSpinEdit.hpp"
#include "cxTextEdit.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#endif
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TPrintForm : public TForm
{
__published:	// IDE-managed Components
        TRadioGroup *RadioGroup1;
        TButton *Button1;
        TButton *Button2;
        TStaticText *StaticText2;
        TButton *PrintButton;
        TButton *HelpButton;
        TcxSpinEdit *cxSpinEdit1;
        TcxSpinEdit *cxSpinEdit2;
        TcxSpinEdit *cxSpinEdit3;
        TRadioGroup *RadioGroup2;
        TRadioGroup *RadioGroup3;
        void __fastcall FormActivate(TObject *Sender);
        void __fastcall PrintButtonClick(TObject *Sender);
        void __fastcall HelpButtonClick(TObject *Sender);
        void __fastcall cxSpinEdit1PropertiesEditValueChanged(
          TObject *Sender);
        void __fastcall cxSpinEdit2PropertiesEditValueChanged(
          TObject *Sender);
        void __fastcall cxSpinEdit3PropertiesEditValueChanged(
          TObject *Sender);
        void __fastcall RadioGroup1Click(TObject *Sender);
        void __fastcall cxSpinEdit3PropertiesValidate(TObject *Sender,
          Variant &DisplayValue, TCaption &ErrorText, bool &Error);
        void __fastcall cxSpinEdit1PropertiesValidate(TObject *Sender,
          Variant &DisplayValue, TCaption &ErrorText, bool &Error);
        void __fastcall cxSpinEdit2PropertiesValidate(TObject *Sender,
          Variant &DisplayValue, TCaption &ErrorText, bool &Error);
        bool __fastcall FormHelp(WORD Command, int Data, bool &CallHelp);  
private:	// User declarations
        TTGDiagram *TGDiagram;
        double DiagramHeight;
        double YaxisHeight;
        int Overlap;
        bool ChangeEdit;
public:		// User declarations
        __fastcall TPrintForm(TComponent* Owner);
        bool PrintButtonClicked;
        double getDiagramHeight() { return DiagramHeight; }
        double getYaxisHeight() { return YaxisHeight; }
        int getOverlap() { return Overlap; }
};
//---------------------------------------------------------------------------
extern PACKAGE TPrintForm *PrintForm;
//---------------------------------------------------------------------------
#endif
