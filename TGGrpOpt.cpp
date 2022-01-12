//---------------------------------------------------------------------------

#include <vcl.h>
#include "pch.h"
#pragma hdrstop

#include "TGGrpOpt.h"
#ifndef TGParentH
#include "TGParent.h"
#ifndef TGUtilsH
#include "TGUtils.h"
#endif
#endif
#ifndef TGHelpH
#include "TGHelp.h"
#endif
#ifndef TGFntDlgH
#include "TGFntDlg.h"
#endif

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TGroupOptionsForm *GroupOptionsForm;
//---------------------------------------------------------------------------
__fastcall TGroupOptionsForm::TGroupOptionsForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TGroupOptionsForm::FormCreate(TObject *Sender)
{
   GrupLineWidthComboBox = new LineWidthComboBox(LineWidthComboBox1);
}
//---------------------------------------------------------------------------

void __fastcall TGroupOptionsForm::FormDestroy(TObject *Sender)
{
   delete GrupLineWidthComboBox;
}
//---------------------------------------------------------------------------

void __fastcall TGroupOptionsForm::BitBtn1Click(TObject *Sender)
{
   TFontDialogBox* FontForm = new TFontDialogBox(this);
   FontForm->SetFont(GroupFont);
   if (FontForm->ShowModal() == mrOk)
     FontForm->GetFont(GroupFont);
   delete FontForm;
}
//---------------------------------------------------------------------------

void __fastcall TGroupOptionsForm::Button6Click(TObject *Sender)
{
   Application->HelpContext(IDH_Group_Options);
}
//---------------------------------------------------------------------------

bool __fastcall TGroupOptionsForm::FormHelp(WORD Command, int Data, bool &CallHelp)
{
   return true;
}
//---------------------------------------------------------------------------

