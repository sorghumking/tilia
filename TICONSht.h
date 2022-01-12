//---------------------------------------------------------------------------

#ifndef TICONShtH
#define TICONShtH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include "cxCheckListBox.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "ProfGrid.hpp"
#include "cxEdit.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
//---------------------------------------------------------------------------
enum MINIMUMVALUES { MV_NONE, MV_DATA, MV_PERCENTS };
//---------------------------------------------------------------------------

class TNewCONISSSheetForm : public TForm
{
__published:	// IDE-managed Components
        TRadioGroup *RadioGroup1;
        TcxCheckListBox *cxCheckListBox1;
        TButton *Button1;
        TButton *Button2;
        TGroupBox *GroupBox1;
        TGroupBox *GroupBox2;
        TLabeledEdit *LabeledEdit1;
        TCheckBox *CheckBox1;
        TCheckBox *CheckBox2;
        void __fastcall RadioGroup1Click(TObject *Sender);
        void __fastcall CheckBox1Click(TObject *Sender);
        void __fastcall CheckBox2Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
        bool Checking;
        int MinimumValues;
        double MinValue;
        TProfGrid* ProfGrid1;
        TProfGrid* ProfGrid2;
        TProfGrid* SourceGrid;
        int __fastcall AbsContentRowCount(TProfGrid* ProfGrid);
public:		// User declarations
        __fastcall TNewCONISSSheetForm(TComponent* Owner);
        void SetGrids(TProfGrid*, TProfGrid*);
        void GetGroups(TProfGrid*);
        TProfGrid* GetSourceGrid(void) { return SourceGrid; }
        int GetMinimumValues(void) { return MinimumValues; }
        double GetMinValue(void) { return MinValue; }
};
//---------------------------------------------------------------------------
extern PACKAGE TNewCONISSSheetForm *NewCONISSSheetForm;
//---------------------------------------------------------------------------
#endif
