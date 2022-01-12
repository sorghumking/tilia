//---------------------------------------------------------------------------

#ifndef TIDelEmpH
#define TIDelEmpH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "cxButtons.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TDelEmptyRowColForm : public TForm
{
__published:	// IDE-managed Components
	TCheckBox *CheckBox1;
	TcxButton *cxButton1;
	TcxButton *cxButton2;
	TRadioButton *RadioButton1;
	TRadioButton *RadioButton2;
private:	// User declarations
public:		// User declarations
	__fastcall TDelEmptyRowColForm(TComponent* Owner);
	void SetColumns(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TDelEmptyRowColForm *DelEmptyRowColForm;
//---------------------------------------------------------------------------
#endif
