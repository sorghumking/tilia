//---------------------------------------------------------------------------

#ifndef TIFuzzyH
#define TIFuzzyH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "cxButtons.hpp"
#include "cxLookAndFeelPainters.hpp"
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxDropDownEdit.hpp"
#include "cxEdit.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeels.hpp"
#ifndef TISpreadH
#include "TISpread.h"
#endif
#ifndef TIdmspanH
#include "TIdmspan.h"
#endif

//---------------------------------------------------------------------------
class TFuzzyForm : public TForm
{
__published:	// IDE-managed Components
        TLabeledEdit *LabeledEdit1;
        TLabeledEdit *LabeledEdit2;
        TcxButton *cxButton1;
        TcxButton *cxButton2;
        TRadioGroup *RadioGroup1;
        TcxPopupEdit *cxPopupEdit1;
        TLabel *Label1;
        TcxPopupEdit *cxPopupEdit2;
        TLabel *Label2;
        TGroupBox *GroupBox1;
        TGroupBox *GroupBox2;
        TCheckBox *CheckBox1;
	TFlowPanel *FlowPanel1;
        void __fastcall cxButton1Click(TObject *Sender);
        void __fastcall cxPopupEdit1PropertiesPopup(TObject *Sender);
        void __fastcall cxPopupEdit1PropertiesCloseUp(TObject *Sender);
        void __fastcall cxPopupEdit2PropertiesCloseUp(TObject *Sender);
        void __fastcall cxPopupEdit2PropertiesPopup(TObject *Sender);
private:	// User declarations
        TTilSpreadSheetForm* TSSForm;
        int SetLatitude(void);
        int SetLongitude(void);
public:		// User declarations
        __fastcall TFuzzyForm(TComponent* Owner);
        void SetPreciseCoordinates(UnicodeString, UnicodeString);
        double latitude;
        double longitude;
        double dmin;
        double dmax;
};
//---------------------------------------------------------------------------
extern PACKAGE TFuzzyForm *FuzzyForm;
//---------------------------------------------------------------------------
#endif
