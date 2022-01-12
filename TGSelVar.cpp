//---------------------------------------------------------------------------
#include <vcl.h>
#include "pch.h"
#pragma hdrstop

#ifndef TGParentH
#include "TGParent.h"
#endif
#ifndef TGHelpH
#include "TGHelp.h"
#endif
#include "TGSelVar.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TSelectVariableForm *SelectVariableForm;
//---------------------------------------------------------------------------
__fastcall TSelectVariableForm::TSelectVariableForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TSelectVariableForm::Button4Click(TObject *Sender)
{
  for (int i=0; i<CheckListBox1->Items->Count; i++)
    CheckListBox1->Checked[i] = true;
}
//---------------------------------------------------------------------------

void __fastcall TSelectVariableForm::Button5Click(TObject *Sender)
{
  for (int i=0; i<CheckListBox1->Items->Count; i++)
    CheckListBox1->Checked[i] = false;
}
//---------------------------------------------------------------------------

void __fastcall TSelectVariableForm::Button3Click(TObject *Sender)
{
  Application->HelpContext(IDH_Select_Variables);
}
//---------------------------------------------------------------------------

