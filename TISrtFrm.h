//---------------------------------------------------------------------------

#ifndef TISrtFrmH
#define TISrtFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
#include "ProfGrid.hpp"

#ifndef TISpreadH
#include "TISpread.h"
#endif
//---------------------------------------------------------------------------
class TSortForm : public TForm
{
__published:	// IDE-managed Components
        TCheckBox *CheckBox1;
        TCheckBox *CheckBox2;
        TPanel *Panel1;
        TRadioButton *RadioButton1;
        TRadioButton *RadioButton2;
        TPanel *Panel2;
        TRadioButton *RadioButton3;
        TRadioButton *RadioButton4;
        TRadioButton *RadioButton5;
        TListBox *ListBox1;
        TSpeedButton *SpeedButton1;
        TSpeedButton *SpeedButton2;
        TLabel *Label1;
        TButton *Button1;
        TButton *Button2;
        TRadioButton *RadioButton6;
        TRadioButton *RadioButton7;
        TRadioButton *RadioButton8;
        TRadioButton *RadioButton9;
        void __fastcall CheckBox1Click(TObject *Sender);
        void __fastcall CheckBox2Click(TObject *Sender);
        void __fastcall RadioButton3Click(TObject *Sender);
        void __fastcall RadioButton4Click(TObject *Sender);
        void __fastcall RadioButton5Click(TObject *Sender);
        void __fastcall RadioButton6Click(TObject *Sender);
        void __fastcall RadioButton7Click(TObject *Sender);
        void __fastcall RadioButton8Click(TObject *Sender);
        void __fastcall RadioButton9Click(TObject *Sender);
        void __fastcall SpeedButton1Click(TObject *Sender);
        void __fastcall SpeedButton2Click(TObject *Sender);
private:	// User declarations
        TTilSpreadSheetForm* TilSpreadSheetForm;
        TProfGrid* Grid;
public:		// User declarations
        __fastcall TSortForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TSortForm *SortForm;
//---------------------------------------------------------------------------
#endif
