//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TIAddCal.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"
TAddCalibProgForm *AddCalibProgForm;
//---------------------------------------------------------------------------
__fastcall TAddCalibProgForm::TAddCalibProgForm(TComponent* Owner)
        : TForm(Owner)
{
   left = -1;
   top = -1;
}
//---------------------------------------------------------------------------

void __fastcall TAddCalibProgForm::FormActivate(TObject *Sender)
{
   if (left > -1 && top > -1) {
     Left = left;
     Top = top;
     }
}
//---------------------------------------------------------------------------

void __fastcall TAddCalibProgForm::cxButton1Click(TObject *Sender)
{
   if (LabeledEdit1->Text.IsEmpty()) {
     MessageDlg("No Program entered!", mtError, TMsgDlgButtons() << mbOK, 0);
     ModalResult = mrNone;
     FocusControl(LabeledEdit1);
     return;
     }
}
//---------------------------------------------------------------------------
