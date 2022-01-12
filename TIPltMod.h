//---------------------------------------------------------------------------

#ifndef TIPltModH
#define TIPltModH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "cxCheckListBox.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include <ExtCtrls.hpp>
#include <CheckLst.hpp>
//---------------------------------------------------------------------------
class TPlotModsForm : public TForm
{
__published:	// IDE-managed Components
        TRadioGroup *RadioGroup1;
        TGroupBox *GroupBox1;
        TButton *Button1;
        TButton *Button2;
        TCheckListBox *CheckListBox1;
        TGroupBox *GroupBox2;
        TCheckListBox *CheckListBox2;
private:	// User declarations
public:		// User declarations
        __fastcall TPlotModsForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TPlotModsForm *PlotModsForm;
//---------------------------------------------------------------------------
#endif
