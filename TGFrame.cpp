//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "TGFrame.h"
#ifndef TGParentH
#include "TGParent.h"
#endif
#ifndef TGHelpH
#include "TGHelp.h"
#endif

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFrameForm *FrameForm;
//---------------------------------------------------------------------------
__fastcall TFrameForm::TFrameForm(TComponent* Owner)
        : TForm(Owner)
{
   Diag = (TTGDiagram*)Owner;
}
//---------------------------------------------------------------------------

void __fastcall TFrameForm::FormCreate(TObject *Sender)
{
   FramLineWidthComboBox = new LineWidthComboBox(LineWidthComboBox1);
}
//---------------------------------------------------------------------------

void __fastcall TFrameForm::FormDestroy(TObject *Sender)
{
   delete FramLineWidthComboBox;
}
//---------------------------------------------------------------------------

void __fastcall TFrameForm::FormActivate(TObject *Sender)
{
    CheckBox1->Checked = Diag->Frame.Plot;
    Diag->SetColorBox(ColorBox1, (TColor)Diag->Frame.Color);

    FramLineWidthComboBox->SetLineWidth(Diag->Frame.LineWidth);

    if (CheckBox1->Checked) {
      ColorBox1->Enabled = true;
      LineWidthComboBox1->Enabled = true;
      LabeledEdit5->Enabled = true;
      ColorBox1->Color = clWindow;
      LineWidthComboBox1->Color = clWindow;
      LabeledEdit5->Color = clWindow;
      }
    else {
      ColorBox1->Enabled = false;
      LineWidthComboBox1->Enabled = false;
      LabeledEdit5->Enabled = false;
      ColorBox1->Color = clBtnFace;
      LineWidthComboBox1->Color = clBtnFace;
      LabeledEdit5->Color = clBtnFace;
      }

    LabeledEdit1->Text = FloatToStr(Diag->Frame.Top);
    LabeledEdit2->Text = FloatToStr(Diag->Frame.Bottom);
    LabeledEdit3->Text = FloatToStr(Diag->Frame.Left);
    LabeledEdit4->Text = FloatToStr(Diag->Frame.Right);
    LabeledEdit5->Text = FloatToStr(Diag->Frame.FrameMargin);
}
//---------------------------------------------------------------------------

// Ok button
void __fastcall TFrameForm::Button1Click(TObject *Sender)
{
    Diag->Modified = true;
    Diag->Frame.Plot = CheckBox1->Checked;
    if (CheckBox1->Checked) {
      Diag->Frame.LineWidth = FramLineWidthComboBox->GetLineWidth();
      Diag->Frame.Color = ColorBox1->Selected;
      Diag->Frame.FrameMargin = GetDoubleFromText(LabeledEdit5->Text, 0.0);
      }
    Diag->Frame.Top = GetDoubleFromText(LabeledEdit1->Text, 0.0);
    Diag->Frame.Bottom = GetDoubleFromText(LabeledEdit2->Text, 0.0);
    Diag->Frame.Left = GetDoubleFromText(LabeledEdit3->Text, 0.0);
    Diag->Frame.Right = GetDoubleFromText(LabeledEdit4->Text, 0.0);
}
//---------------------------------------------------------------------------

void __fastcall TFrameForm::CheckBox1Click(TObject *Sender)
{
   if (CheckBox1->Checked) {
      ColorBox1->Enabled = true;
      LineWidthComboBox1->Enabled = true;
      LabeledEdit5->Enabled = true;
      ColorBox1->Color = clWindow;
      LineWidthComboBox1->Color = clWindow;
      LabeledEdit5->Color = clWindow;
      }
    else {
      ColorBox1->Enabled = false;
      LineWidthComboBox1->Enabled = false;
      LabeledEdit5->Enabled = false;
      ColorBox1->Color = clBtnFace;
      LineWidthComboBox1->Color = clBtnFace;
      LabeledEdit5->Color = clBtnFace;
      }
}
//---------------------------------------------------------------------------

// Help button
void __fastcall TFrameForm::Button3Click(TObject *Sender)
{
   Application->HelpContext(IDH_Frame_Dialog_Box);
}
//---------------------------------------------------------------------------

bool __fastcall TFrameForm::FormHelp(WORD Command, int Data, bool &CallHelp)
{
   return true;
}
//---------------------------------------------------------------------------

