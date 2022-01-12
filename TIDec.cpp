//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TIDec.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxMaskEdit"
#pragma link "cxSpinEdit"
#pragma link "cxTextEdit"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"
TSSFormatForm *SSFormatForm;
//---------------------------------------------------------------------------
__fastcall TSSFormatForm::TSSFormatForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TSSFormatForm::RadioButton1Click(TObject *Sender)
{
   if (RadioButton1->Checked) {
     RadioButton2->Checked = false;
     cxSpinEdit1->Enabled = false;
     }
}
//---------------------------------------------------------------------------

void __fastcall TSSFormatForm::RadioButton2Click(TObject *Sender)
{
   if (RadioButton2->Checked) {
     RadioButton1->Checked = false;
     cxSpinEdit1->Enabled = true;
     }
}
//---------------------------------------------------------------------------

