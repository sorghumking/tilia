//---------------------------------------------------------------------------

#ifndef TIConFrmH
#define TIConFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
#include <Menus.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
#ifndef TISpreadH
#include "TISpread.h"
#endif

//---------------------------------------------------------------------------
class TConissForm : public TForm
{
__published:	// IDE-managed Components
        TRadioGroup *RadioGroup1;
        TCheckBox *CheckBox1;
        TRadioGroup *RadioGroup2;
        TRadioGroup *RadioGroup3;
        TBevel *Bevel1;
        TEdit *Edit2;
        TSpeedButton *SpeedButton2;
        TButton *Button1;
        TButton *Button2;
        TOpenDialog *OpenDialog1;
        TLabel *Label1;
        void __fastcall SpeedButton2Click(TObject *Sender);
        void __fastcall RadioGroup1Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
		UnicodeString InputFile;
		UnicodeString OutputFileName;
		UnicodeString DGXFile;
        TTilSpreadSheetForm* TSSForm;
public:		// User declarations
        __fastcall TConissForm(TComponent* Owner);
        bool Unconstrained(void);
        vector<int> order;
};
//---------------------------------------------------------------------------
extern PACKAGE TConissForm *ConissForm;
//---------------------------------------------------------------------------
#endif
