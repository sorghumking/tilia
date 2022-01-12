//---------------------------------------------------------------------------
#include <vcl.h>
#include "pch.h"
#pragma hdrstop
#ifndef TGParentH
#include "TGParent.h"
#endif
#include "TIErrFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TErrorListForm *ErrorListForm;
//---------------------------------------------------------------------------
__fastcall TErrorListForm::TErrorListForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------



