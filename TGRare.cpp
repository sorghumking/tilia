//---------------------------------------------------------------------------
#include <vcl.h>
#include "pch.h"
#pragma hdrstop
 
#ifndef TGParentH
#include "TGParent.h"
#endif
#ifndef TGDiagrmH
#include "TGDiagrm.h"
#endif
#ifndef TGH
#include "tg.h"
#endif
#ifndef TGUtilsH
#include "TGUtils.h"
#endif
#ifndef TGHelpH
#include "TGHelp.h"
#endif
#include "TGRare.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TRareForm *RareForm;
//---------------------------------------------------------------------------
__fastcall TRareForm::TRareForm(TComponent* Owner)
        : TForm(Owner)
{
   Diag = (TTGDiagram*)Owner;
}
//---------------------------------------------------------------------------

void __fastcall TRareForm::FormCreate(TObject *Sender)
{
   RareLineWidthComboBox = new LineWidthComboBox(LineWidthComboBox1);
}
//---------------------------------------------------------------------------

void __fastcall TRareForm::FormDestroy(TObject *Sender)
{
   delete RareLineWidthComboBox;
}
//---------------------------------------------------------------------------

void __fastcall TRareForm::FormActivate(TObject *Sender)
{
   if (Diag->Rare.Symbol == RAREPLUS) {
     ToolButton1->Down = true;
     LineWidthComboBox1->Enabled = true;
     LineWidthComboBox1->Color = clWindow;
     }
   else {
     ToolButton2->Down = true;
     LineWidthComboBox1->Enabled = false;
     LineWidthComboBox1->Color = clBtnFace;
     }

   LabeledEdit1->Text = FloatToStr(Diag->Rare.Size);

   RareLineWidthComboBox->SetLineWidth(Diag->Rare.LineWidth);
}
//---------------------------------------------------------------------------

// Ok button
void __fastcall TRareForm::Button1Click(TObject *Sender)
{
   Diag->Modified = true;
   if (ToolButton1->Down)
     Diag->Rare.Symbol = RAREPLUS;
   else
     Diag->Rare.Symbol = RARECIRCLE;

   Diag->Rare.Size = GetDoubleFromText(LabeledEdit1->Text, 0.075);
   Diag->Rare.LineWidth = RareLineWidthComboBox->GetLineWidth();
}
//---------------------------------------------------------------------------

void __fastcall TRareForm::ToolButton1Click(TObject *Sender)
{
   LineWidthComboBox1->Enabled = true;
   LineWidthComboBox1->Color = clWindow;
}
//---------------------------------------------------------------------------

void __fastcall TRareForm::ToolButton2Click(TObject *Sender)
{
   LineWidthComboBox1->Enabled = false;
   LineWidthComboBox1->Color = clBtnFace;
}
//---------------------------------------------------------------------------

// Help button
void __fastcall TRareForm::Button3Click(TObject *Sender)
{
   Application->HelpContext(IDH_Rare_Types_Dialog_Box);
}
//---------------------------------------------------------------------------

bool __fastcall TRareForm::FormHelp(WORD Command, int Data, bool &CallHelp)
{
   return true;
}
//---------------------------------------------------------------------------

