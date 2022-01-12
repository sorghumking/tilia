//---------------------------------------------------------------------------

#ifndef TISeEcGrH
#define TISeEcGrH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <CheckLst.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
#include <ExtCtrls.hpp>
#include "cxButtons.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TSelectEcolGroupsForm : public TForm
{
__published:	// IDE-managed Components
        TCheckListBox *CheckListBox1;
        TPanel *Panel1;
	TFlowPanel *FlowPanel1;
	TcxButton *cxButton1;
	TcxButton *cxButton2;
private:	// User declarations
public:		// User declarations
        __fastcall TSelectEcolGroupsForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TSelectEcolGroupsForm *SelectEcolGroupsForm;
//---------------------------------------------------------------------------
#endif
