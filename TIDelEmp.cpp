//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TIDelEmp.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"
TDelEmptyRowColForm *DelEmptyRowColForm;
//---------------------------------------------------------------------------
__fastcall TDelEmptyRowColForm::TDelEmptyRowColForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void TDelEmptyRowColForm::SetColumns(void)
{
   CheckBox1->Caption = L"Header rows must be empty";
   RadioButton1->Caption = L"Delete columns with all cells empty or zero";
   RadioButton2->Caption = L"Delete columns with all cells empty";
}
//---------------------------------------------------------------------------
