//---------------------------------------------------------------------------

#ifndef TIAgeResH
#define TIAgeResH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "ProfGrid.hpp"
#include <Grids.hpp>
#include <ExtCtrls.hpp>
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxEdit.hpp"
#include "cxMaskEdit.hpp"
#include "cxSpinEdit.hpp"
#include "cxTextEdit.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include "cxButtons.hpp"
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TAgeModelResultsForm : public TForm
{
__published:	// IDE-managed Components
        TMemo *Memo1;
        TProfGrid *ProfGrid1;
        TSplitter *Splitter1;
        TcxSpinEdit *cxSpinEdit1;
        TLabel *Label1;
	TcxButton *cxButton1;
        void __fastcall cxSpinEdit1PropertiesChange(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TAgeModelResultsForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TAgeModelResultsForm *AgeModelResultsForm;
//---------------------------------------------------------------------------
#endif
