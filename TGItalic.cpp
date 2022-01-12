//---------------------------------------------------------------------------
#include <vcl.h>
#include "pch.h"
#pragma hdrstop

#include "TGItalic.h"
#ifndef TGParentH
#include "TGParent.h"
#endif
#ifndef TGHelpH
#include "TGHelp.h"
#endif

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TItalicsForm *ItalicsForm;
//---------------------------------------------------------------------------
__fastcall TItalicsForm::TItalicsForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TItalicsForm::Button1Click(TObject *Sender)
{
  Action = ITALICIZE;      
}
//---------------------------------------------------------------------------

void __fastcall TItalicsForm::Button2Click(TObject *Sender)
{
  Action = REMOVEITALICS;
}
//---------------------------------------------------------------------------

void __fastcall TItalicsForm::Button3Click(TObject *Sender)
{
  Action = AUTOITALICS;
}
//---------------------------------------------------------------------------

void __fastcall TItalicsForm::FormActivate(TObject *Sender)
{
   Action = -999;      
}
//---------------------------------------------------------------------------

// Help button
void __fastcall TItalicsForm::Button5Click(TObject *Sender)
{
   Application->HelpContext(IDH_Italics_Dialog_Box);
}
//---------------------------------------------------------------------------

bool __fastcall TItalicsForm::FormHelp(WORD Command, int Data, bool &CallHelp)
{
   return true;
}
//---------------------------------------------------------------------------

