//---------------------------------------------------------------------------

#include <vcl.h>
#include "pch.h"
#pragma hdrstop

#include "TGZoneSc.h"
#ifndef TGParentH
#include "TGParent.h"
#endif
#ifndef TGPattH
#include "TGPatt.h"
#endif
#ifndef TGUtilsH
#include "TGUtils.h"
#endif
#ifndef TGHelpH
#include "TGHelp.h"
#endif

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TZoneScreenForm *ZoneScreenForm;
//---------------------------------------------------------------------------
__fastcall TZoneScreenForm::TZoneScreenForm(TComponent* Owner)
        : TForm(Owner)
{
   Diag = (TTGDiagram*)Owner;
}
//---------------------------------------------------------------------------

void __fastcall TZoneScreenForm::FormCreate(TObject *Sender)
{
   ZoneLineWidthComboBox = new LineWidthComboBox(LineWidthComboBox1);
}
//---------------------------------------------------------------------------

void __fastcall TZoneScreenForm::FormDestroy(TObject *Sender)
{
   delete ZoneLineWidthComboBox;
}
//---------------------------------------------------------------------------

void __fastcall TZoneScreenForm::PaintBox1Paint(TObject *Sender)
{
    TPoint points[4];
    points[0] = Point(0, 0);
    points[1] = Point(PaintBox1->Width, 0);
    points[2] = Point(PaintBox1->Width, PaintBox1->Height);
    points[3] = Point(0, PaintBox1->Height);

	if (Pattern <= 33) {
	  //PaintBox1->Canvas->Brush->Bitmap =
	  //	(Graphics::TBitmap *)ParentForm->GKSBitmaps->Items[Pattern-1];
      PaintBox1->Canvas->Brush->Bitmap = ParentForm->GKSBitmaps[Pattern-1];

	  SetTextColor(PaintBox1->Canvas->Handle, Color);
      PaintBox1->Canvas->Pen->Style = psClear;
      PaintBox1->Canvas->Polygon(points, 3);
      PaintBox1->Canvas->Brush->Bitmap = NULL;
      }
    else if (Pattern == 34) {
      PaintBox1->Canvas->Brush->Bitmap = NULL;
      PaintBox1->Canvas->Brush->Style = bsSolid;
      PaintBox1->Canvas->Brush->Color = (TColor)Color;
      PaintBox1->Canvas->Pen->Style = psClear;
      PaintBox1->Canvas->Polygon(points, 3);
      }
    else {
      if (Dash > 0 && Space > 0) {
        PaintBox1->Canvas->Brush->Bitmap = NULL;
        PaintBox1->Canvas->Brush->Style = bsSolid;
        PaintBox1->Canvas->Brush->Color = (TColor)Color;
        PaintBox1->Canvas->Pen->Style = psClear;

        int DashPix = Dash/2;
        int SpacePix = Space/2;
        int x1 = 0;
        int x2 = DashPix;

        while (x1 < PaintBox1->Width) {
          if (x2 > PaintBox1->Width)
            x2 = PaintBox1->Width;
          points[0] = Point(x1, 0);
          points[1] = Point(x2, 0);
          points[2] = Point(x2, PaintBox1->Height);
          points[3] = Point(x1, PaintBox1->Height);
          PaintBox1->Canvas->Polygon(points, 3);
          x1 += (DashPix + SpacePix);
          x2 = x1 + DashPix;
          }
        }
      }

    if (Zone->Border || CheckBox1->Checked) {
      PaintBox1->Canvas->Pen->Style = psSolid;
      PaintBox1->Canvas->Pen->Color = (TColor)BorderColor;
      PaintBox1->Canvas->MoveTo(0, 0);
      PaintBox1->Canvas->LineTo(PaintBox1->Width, 0);
      PaintBox1->Canvas->MoveTo(0, PaintBox1->Height-1);
      PaintBox1->Canvas->LineTo(PaintBox1->Width, PaintBox1->Height-1);
      }
}
//---------------------------------------------------------------------------

void __fastcall TZoneScreenForm::FormActivate(TObject *Sender)
{
   Pattern = Zone->Pattern;
   CheckBox2->Checked = false;
   if (Zone->user.dash == 0 || Zone->user.space == 0) {
     Dash = 20;
     Space = 10;
     }
   else {
     Dash = Zone->user.dash;
     Space = Zone->user.space;
     }

   if (Pattern < 34) {         // pattern
     RadioGroup1->ItemIndex = 0;
     Button5->Enabled = true;
     LabeledEdit1->Enabled = false;
     LabeledEdit2->Enabled = false;
     LabeledEdit1->Color = clBtnFace;
     LabeledEdit2->Color = clBtnFace;
     }
   else if (Pattern == 34) {   // solid
     RadioGroup1->ItemIndex = 1;
     Button5->Enabled = false;
     LabeledEdit1->Enabled = false;
     LabeledEdit2->Enabled = false;
     LabeledEdit1->Color = clBtnFace;
     LabeledEdit2->Color = clBtnFace;
     }
   else {                            // dashed
     RadioGroup1->ItemIndex = 2;
     Button5->Enabled = false;
     LabeledEdit1->Enabled = true;
     LabeledEdit2->Enabled = true;
     LabeledEdit1->Text = Dash;
     LabeledEdit2->Text = Space;
     }

   CheckBox1->Checked = (Zone->Border) ? true : false;

   ZoneLineWidthComboBox->SetLineWidth(Zone->LineWidth);
   LabeledEdit3->Text = fabs(Zone->ZoneWidth);

   if (Zone->ZoneWidth >= 0)
     RadioGroup3->ItemIndex = 0;
   else
     RadioGroup3->ItemIndex = 1;

   Diag->SetColorBox(ColorBox1, (TColor)Zone->ZoneColor);
   Diag->SetColorBox(ColorBox2, (TColor)Zone->BorderColor);

   if (CheckBox1->Checked) {
     LineWidthComboBox1->Enabled = true;
     ColorBox2->Enabled = true;
     }
   else {
     LineWidthComboBox1->Enabled = false;
     ColorBox2->Enabled = false;
     }

   PaintBox1->Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TZoneScreenForm::Button5Click(TObject *Sender)
{
  PatternForm = new TPatternForm(this);
  PatternForm->Initialize(Pattern);
  if (PatternForm->ShowModal() == mrOk) {
    if (PatternForm->PatternIndex > 0) {
      Pattern = PatternForm->PatternIndex;
      PaintBox1->Repaint();
      }
    }
  delete PatternForm;
}
//---------------------------------------------------------------------------

void __fastcall TZoneScreenForm::ColorBox1Change(TObject *Sender)
{
   Color = ColorBox1->Selected;
   PaintBox1->Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TZoneScreenForm::RadioGroup1Click(TObject *Sender)
{
   if (RadioGroup1->ItemIndex == 0) {
     Button5->Enabled = true;
     LabeledEdit1->Enabled = false;
     LabeledEdit2->Enabled = false;
     LabeledEdit1->Clear();
     LabeledEdit2->Clear();
     LabeledEdit1->Color = clBtnFace;
     LabeledEdit2->Color = clBtnFace;
     if (Pattern < 1 || Pattern > 33)
       Pattern = 1;
     }
   else if (RadioGroup1->ItemIndex == 1) {
     Button5->Enabled = false;
     LabeledEdit1->Enabled = false;
     LabeledEdit2->Enabled = false;
     LabeledEdit1->Clear();
     LabeledEdit2->Clear();
     LabeledEdit1->Color = clBtnFace;
     LabeledEdit2->Color = clBtnFace;
     Pattern = 34;
     }
   else {
     Button5->Enabled = false;
     LabeledEdit1->Enabled = true;
     LabeledEdit2->Enabled = true;
     LabeledEdit1->Text = Dash;
     LabeledEdit2->Text = Space;
     LabeledEdit1->Color = clWindow;
     LabeledEdit2->Color = clWindow;
     Pattern = 35;
     }

   PaintBox1->Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TZoneScreenForm::LabeledEdit1Exit(TObject *Sender)
{
   double temp;
   if (!LabeledEdit1->Enabled) return;
   try {
     temp = LabeledEdit1->Text.ToDouble(); }
   catch (...) {
	 MessageDlg("Invalid value for dash", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
     return; }

   if (temp <= 0) {
     MessageDlg("Dash must be >0", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
     return; }

   Dash = temp;
   PaintBox1->Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TZoneScreenForm::LabeledEdit2Exit(TObject *Sender)
{
   double temp;
   if (!LabeledEdit2->Enabled) return;
   try {
     temp = LabeledEdit2->Text.ToDouble(); }
   catch (...) {
	 MessageDlg("Invalid value for space", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
     return; }

   if (temp <= 0) {
	 MessageDlg("Space must be >0", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
     return; }

   Space = temp;
   PaintBox1->Repaint();
}
//---------------------------------------------------------------------------

// Ok button
void __fastcall TZoneScreenForm::Button1Click(TObject *Sender)
{
   Zone->user.dash = Dash;
   Zone->user.space = Space;
   Zone->Pattern = Pattern;
   Zone->ZoneColor = Color;
   Zone->BorderColor = BorderColor;

   Zone->ZoneWidth = IntlStrToDouble::GetDouble(&(LabeledEdit3->Text), 0.0);
   if (Zone->ZoneWidth < 0.0) Zone->ZoneWidth = 0.0;

   if (RadioGroup3->ItemIndex == 1)
     Zone->ZoneWidth *= -1.0;

   Zone->Border = (CheckBox1->Checked) ? true : false;

   Zone->LineWidth = ZoneLineWidthComboBox->GetLineWidth();
}
//---------------------------------------------------------------------------

void __fastcall TZoneScreenForm::ColorBox2Change(TObject *Sender)
{
   BorderColor = ColorBox2->Selected;
   PaintBox1->Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TZoneScreenForm::CheckBox1Click(TObject *Sender)
{
    if (CheckBox1->Checked) {
      LineWidthComboBox1->Enabled = true;
      ColorBox2->Enabled = true;
      }
    else {
      LineWidthComboBox1->Enabled = false;
      ColorBox2->Enabled = false;
      }
   PaintBox1->Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TZoneScreenForm::Button3Click(TObject *Sender)
{
   Application->HelpContext(IDH_Zone_Screen_Options);
}
//---------------------------------------------------------------------------

bool __fastcall TZoneScreenForm::FormHelp(WORD Command, int Data, bool &CallHelp)
{
   return true;
}
//---------------------------------------------------------------------------

