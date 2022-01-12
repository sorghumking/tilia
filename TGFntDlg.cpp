//---------------------------------------------------------------------------

#include <StrUtils.hpp>
#include <vcl.h>
#include "pch.h"
#pragma hdrstop

#include "TGFntDlg.h"
#ifndef TGParentH
#include "TGParent.h"
#endif
#ifndef TGTextH
#include "TGText.h"
#endif
#ifndef TGUtilsH
#include "TGUtils.h"
#endif
#ifndef TGHelpH
#include "TGHelp.h"
#endif

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDropDownEdit"
#pragma link "cxEdit"
#pragma link "cxFontNameComboBox"
#pragma link "cxGraphics"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"
TFontDialogBox *FontDialogBox;
//---------------------------------------------------------------------------
__fastcall TFontDialogBox::TFontDialogBox(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void TFontDialogBox::SetFont(MYFONT& Font)
{
   cxFontNameComboBox1->FontName = Font.FontName;

   if (Font.Style.bold)
     cxFontNameComboBox1->Properties->FontPreview->FontStyle << fsBold;
   if (Font.Style.italic)
     cxFontNameComboBox1->Properties->FontPreview->FontStyle << fsItalic;
   if (Font.Style.underline)
     cxFontNameComboBox1->Properties->FontPreview->FontStyle << fsUnderline;
   if (Font.Style.strikeout)
     cxFontNameComboBox1->Properties->FontPreview->FontStyle << fsStrikeOut;

   if (Font.Height > -1.0)
     ComboBox1->Text = nint(72*Font.Height);
   else
     ColorBox1->ItemIndex = -1;

   if (Font.Color > -1) {
     ColorBox1->Selected = (TColor)Font.Color;
     if (ColorBox1->Selected == clBlack)
       ColorBox1->ItemIndex = 1;
     }
   else
     ColorBox1->ItemIndex = -1;
}
//---------------------------------------------------------------------------

void TFontDialogBox::GetFont(MYFONT& Font)
{
   if (cxFontNameComboBox1->FontName.Length() > 0)
     Font.FontName = cxFontNameComboBox1->FontName;

   if (ComboBox1->Text.Length() > 0)
     Font.Height =
       IntlStrToDouble::GetDouble(&(ComboBox1->Text), 72.0*Font.Height)/72.0;

   if (ColorBox1->ItemIndex >= 0)
     Font.Color = ColorBox1->Selected;

   Font.Style.bold =
     cxFontNameComboBox1->Properties->FontPreview->FontStyle.Contains(fsBold);
   Font.Style.italic =
     cxFontNameComboBox1->Properties->FontPreview->FontStyle.Contains(fsItalic);
   Font.Style.underline =
     cxFontNameComboBox1->Properties->FontPreview->FontStyle.Contains(fsUnderline);
   Font.Style.strikeout =
     cxFontNameComboBox1->Properties->FontPreview->FontStyle.Contains(fsStrikeOut);
}
//---------------------------------------------------------------------------

void __fastcall TFontDialogBox::Button3Click(TObject *Sender)
{
   Application->HelpContext(IDH_Font_Dialog_Box);
}
//---------------------------------------------------------------------------

bool __fastcall TFontDialogBox::FormHelp(WORD Command, int Data, bool &CallHelp)
{
   return true;
}
//---------------------------------------------------------------------------

