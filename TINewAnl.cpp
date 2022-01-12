//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TINewAnl.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TNewAnalystForm *NewAnalystForm;
//---------------------------------------------------------------------------
__fastcall TNewAnalystForm::TNewAnalystForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TNewAnalystForm::ListBox1Click(TObject *Sender)
{
   LabeledEdit1->Text = "";
   LabeledEdit2->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TNewAnalystForm::LabeledEdit1Enter(TObject *Sender)
{
   ListBox1->ItemIndex = -1;
}
//---------------------------------------------------------------------------

void __fastcall TNewAnalystForm::LabeledEdit2Enter(TObject *Sender)
{
   ListBox1->ItemIndex = -1;
}
//---------------------------------------------------------------------------


