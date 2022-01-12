//---------------------------------------------------------------------------

#ifndef TITphChkH
#define TITphChkH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include "cxButtons.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxDropDownEdit.hpp"
#include "cxEdit.hpp"
#include "cxGraphics.hpp"
#include "cxLabel.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include <Menus.hpp>
#include <set>

//---------------------------------------------------------------------------
class TConvertTaphForm : public TForm
{
__published:	// IDE-managed Components
	TImage *Image1;
	TcxLabel *cxLabel1;
	TcxLabel *cxLabel2;
	TcxComboBox *cxComboBox1;
	TcxLabel *cxLabel3;
	TcxButton *cxButton1;
	TcxButton *cxButton2;
	TcxButton *cxButton3;
	TcxButton *cxButton4;
	TFlowPanel *FlowPanel1;
	TcxLabel *cxLabel4;
private:	// User declarations
public:		// User declarations
	__fastcall TConvertTaphForm(int row, UnicodeString DatasetType,
		set<UnicodeString>& Systems, TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TConvertTaphForm *ConvertTaphForm;
//---------------------------------------------------------------------------
#endif
