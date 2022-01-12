//---------------------------------------------------------------------------

#include <vcl.h>
#include "pch.h"
#pragma hdrstop

#include "TGNewTxt.h"
#include "TGGreek.h"
#ifndef TGParentH
#include "TGParent.h"
#endif
#ifndef TGUtilsH
#include "TGUtils.h"
#endif
#ifndef TGFntDlgH
#include "TGFntDlg.h"
#endif
#ifndef TGHelpH
#include "TGHelp.h"
#endif

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TNewTextForm *NewTextForm;
//---------------------------------------------------------------------------
__fastcall TNewTextForm::TNewTextForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TNewTextForm::FormActivate(TObject *Sender)
{
   Edit1->Font->Name = Text->Font.FontName;
   Edit1->Font->Color = (TColor)Text->Font.Color;
   Edit2->Text = FormatFloat("0.0#", Text->x);
   Edit3->Text = FormatFloat("0.0#", Text->y);
   Edit4->Text = FormatFloat("0.0#", Text->angle);
   x = Text->x;
   y = Text->y;
   angle = Text->angle;
   Screen->Cursor = crDefault;
}
//---------------------------------------------------------------------------
void __fastcall TNewTextForm::BitBtn6Click(TObject *Sender)
{
   TFontDialogBox* FontForm = new TFontDialogBox(this);
   FontForm->SetFont(Text->Font);
   if (FontForm->ShowModal() == mrOk) {
     FontForm->GetFont(Text->Font);
	 Edit1->Font->Name = Text->Font.FontName;
     Edit1->Font->Color = (TColor)Text->Font.Color;
     }
   delete FontForm;
}
//---------------------------------------------------------------------------

// Ok button
void __fastcall TNewTextForm::Button3Click(TObject *Sender)
{
   Text->Text = Edit1->Text;
   Text->x = IntlStrToDouble::GetDouble(&(Edit2->Text), x);
   Text->y = IntlStrToDouble::GetDouble(&(Edit3->Text), y);
   Text->angle = IntlStrToDouble::GetDouble(&(Edit4->Text), angle);
}
//---------------------------------------------------------------------------

void TNewTextForm::ToggleStyle(int Style)
{
  UnicodeString Text = Edit1->Text;

  int curpos = Edit1->SelStart;
  int Advance = 0;
  FormatString(Text, Style, curpos, Edit1->SelLength, &Advance);
  Edit1->Text = Text;
  FocusControl(Edit1);
  Edit1->SelLength = 0;
  Edit1->SelStart = curpos+Advance;
}

//---------------------------------------------------------------------------
// bold
void __fastcall TNewTextForm::BitBtn1Click(TObject *Sender)
{
   ToggleStyle(BOLD);
}
//---------------------------------------------------------------------------
// italic
void __fastcall TNewTextForm::BitBtn2Click(TObject *Sender)
{
   ToggleStyle(ITALIC);
}
//---------------------------------------------------------------------------
// superscript
void __fastcall TNewTextForm::BitBtn3Click(TObject *Sender)
{
   ToggleStyle(SUPERSCRIPT);
}
//---------------------------------------------------------------------------
// subscript
void __fastcall TNewTextForm::BitBtn4Click(TObject *Sender)
{
   ToggleStyle(SUBSCRIPT);
}
//---------------------------------------------------------------------------
// greek
void __fastcall TNewTextForm::BitBtn5Click(TObject *Sender)
{
   int SelStart = Edit1->SelStart;
   GreekForm = new TGreekForm(this);
   if (GreekForm->ShowModal() == mrOk) {
     if (GreekForm->StaticText1->Caption.Length() > 0) {
	   UnicodeString Buff = Edit1->Text;
       Buff.Insert(GreekForm->StaticText1->Caption, Edit1->SelStart+1);
       Edit1->Text = Buff;
       FocusControl(Edit1);
       Edit1->SelLength = 0;
       Edit1->SelStart = SelStart+GreekForm->StaticText1->Caption.Length();
       }
     }
   delete GreekForm;
}
//---------------------------------------------------------------------------

void __fastcall TNewTextForm::Button5Click(TObject *Sender)
{
   Application->HelpContext(IDH_Text_Interactive);
}
//---------------------------------------------------------------------------

bool __fastcall TNewTextForm::FormHelp(WORD Command, int Data, bool &CallHelp)
{
   return true;
}
//---------------------------------------------------------------------------

