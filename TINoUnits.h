//---------------------------------------------------------------------------

#ifndef TINoUnitsH
#define TINoUnitsH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include "cxButtons.hpp"
#include "cxCheckListBox.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxEdit.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TConfirmNoUnitsForm : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TLabel *Label2;
	TRadioGroup *RadioGroup1;
	TcxCheckListBox *cxCheckListBox1;
	TcxButton *cxButton1;
	TcxButton *cxButton2;
	TLabeledEdit *LabeledEdit1;
	void __fastcall cxCheckListBox1ClickCheck(TObject *Sender, int AIndex, TcxCheckBoxState APrevState,
          TcxCheckBoxState ANewState);
	void __fastcall cxButton1Click(TObject *Sender);
	void __fastcall RadioGroup1Click(TObject *Sender);
protected:	// User declarations
	bool RadioCheck;
public:		// User declarations
	__fastcall TConfirmNoUnitsForm(TComponent* Owner);
	UnicodeString Units;
};
//---------------------------------------------------------------------------

class TConfirmNoElementsForm : public TConfirmNoUnitsForm
{
__published:	// IDE-managed Components
	void __fastcall cxButton1Click(TObject *Sender);
	void __fastcall RadioGroup1Click(TObject *Sender);
public:		// User declarations
	__fastcall TConfirmNoElementsForm(TComponent* Owner);
	UnicodeString Elements;
};

//---------------------------------------------------------------------------
extern PACKAGE TConfirmNoUnitsForm *ConfirmNoUnitsForm;
//---------------------------------------------------------------------------
#endif
