//---------------------------------------------------------------------------

#ifndef TIFluxFmH
#define TIFluxFmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "cxCheckListBox.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include <ExtCtrls.hpp>
#include "cxEdit.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"

#ifndef TISpreadH
#include "TISpread.h"
#endif

enum DEPTHUNITS { CENTIMETRES, METRES };
enum DEPTIME { CALCDEPTIME, USEDEPTIMEVAR };

//---------------------------------------------------------------------------
class TInfluxForm : public TForm
{
__published:	// IDE-managed Components
        TRadioGroup *RadioGroup1;
        TcxCheckListBox *cxCheckListBox1;
        TLabel *Label1;
        TRadioGroup *RadioGroup2;
        TButton *Button1;
        TButton *Button2;
        TcxCheckListBox *cxCheckListBox2;
        TLabel *Label2;
        TRadioGroup *RadioGroup3;
        void __fastcall cxCheckListBox1ClickCheck(TObject *Sender,
          int AIndex, TcxCheckBoxState APrevState,
          TcxCheckBoxState ANewState);
        void __fastcall RadioGroup1Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall cxCheckListBox2ClickCheck(TObject *Sender,
          int AIndex, TcxCheckBoxState APrevState,
          TcxCheckBoxState ANewState);
private:	// User declarations
		TTilSpreadSheetForm* TSSForm;
		vector<UnicodeString> ChronList;
		vector<UnicodeString> DepthList;
		vector<UnicodeString> DTList;
		vector<int> ChronRows;
		vector<int> DepthRows;
        vector<int> DTRows;
public:		// User declarations
        __fastcall TInfluxForm(TComponent* Owner);
        int ErrorCode;
        int Method;
        int Units;
        int VarRow;
        int DepthRow;
        int TreatNulls;
};
//---------------------------------------------------------------------------
extern PACKAGE TInfluxForm *InfluxForm;
//---------------------------------------------------------------------------
#endif
