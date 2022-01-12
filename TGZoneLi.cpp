//---------------------------------------------------------------------------

#include <vcl.h>
#include "pch.h"
#pragma hdrstop

#include "TGZoneLi.h"
#ifndef TGParentH
#include "TGParent.h"
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
TZoneLineForm *ZoneLineForm;
//---------------------------------------------------------------------------
__fastcall TZoneLineForm::TZoneLineForm(TComponent* Owner)
        : TForm(Owner)
{
   Diag = (TTGDiagram*)Owner;
}
//---------------------------------------------------------------------------

void __fastcall TZoneLineForm::ToolButton1Click(TObject *Sender)
{
   LabeledEdit1->Clear();
   LabeledEdit2->Clear();
   LabeledEdit1->Color = clBtnFace;
   LabeledEdit2->Color = clBtnFace;
   DrawZoneLine(1, 0);
}
//---------------------------------------------------------------------------

void __fastcall TZoneLineForm::ToolButton2Click(TObject *Sender)
{
   LabeledEdit1->Clear();
   LabeledEdit2->Clear();
   LabeledEdit1->Color = clBtnFace;
   LabeledEdit2->Color = clBtnFace;
   DrawZoneLine(2, 4);
}
//---------------------------------------------------------------------------

void __fastcall TZoneLineForm::ToolButton3Click(TObject *Sender)
{
   LabeledEdit1->Clear();
   LabeledEdit2->Clear();
   LabeledEdit1->Color = clBtnFace;
   LabeledEdit2->Color = clBtnFace;
   DrawZoneLine(12, 6);
}
//---------------------------------------------------------------------------

void __fastcall TZoneLineForm::ToolButton4Click(TObject *Sender)
{
   LabeledEdit1->Clear();
   LabeledEdit2->Clear();
   LabeledEdit1->Color = clBtnFace;
   LabeledEdit2->Color = clBtnFace;
   DrawZoneLine(24, 12);
}
//---------------------------------------------------------------------------

void __fastcall TZoneLineForm::ToolButton5Click(TObject *Sender)
{
   LabeledEdit1->Color = clWindow;
   LabeledEdit2->Color = clWindow;
   if (Dash == 0 || Space == 0) {
     Dash = 20;
     Space = 10;
     }
   LabeledEdit1->Text = Dash;
   LabeledEdit2->Text = Space;
   DrawZoneLine(Dash, Space);
}
//---------------------------------------------------------------------------

void __fastcall TZoneLineForm::FormCreate(TObject *Sender)
{
   Image1->Picture->Bitmap = new Graphics::TBitmap;
   Image1->Picture->Bitmap->PixelFormat = pf24bit;
   Image1->Picture->Bitmap->Width = Image1->Width;
   Image1->Picture->Bitmap->Height = Image1->Height;
   ZoneLineWidthComboBox = new LineWidthComboBox(LineWidthComboBox1);
}
//---------------------------------------------------------------------------

void __fastcall TZoneLineForm::FormDestroy(TObject *Sender)
{
   delete ZoneLineWidthComboBox;
}
//---------------------------------------------------------------------------

void __fastcall TZoneLineForm::FormActivate(TObject *Sender)
{
   if (Zone->user.dash == 0 || Zone->user.space == 0) {
     Dash = 20;
     Space = 10;
     }
   else {
     Dash = Zone->user.dash;
     Space = Zone->user.space;
     }
   Diag->SetColorBox(ColorBox1, (TColor)Zone->ZoneColor);
   ZoneLineWidthComboBox->SetLineWidth(Zone->LineWidth);
}
//---------------------------------------------------------------------------

void TZoneLineForm::DrawZoneLine(int DashWidth, int SpaceWidth)
{
   if (SpaceWidth == 0 && DashWidth == 0) {
     for (int i=0; i<Image1->Picture->Bitmap->Width; i++)
       Image1->Canvas->Pixels[i][11] = clWhite;
     }
   else if (SpaceWidth == 0) {
     for (int i=0; i<Image1->Picture->Bitmap->Width; i++)
       Image1->Canvas->Pixels[i][11] = clBlack;
     }
   else {
     int DashPix = DashWidth/2;
     int SpacePix = SpaceWidth/2;
     int dash = 0;
     int space = 0;
     for (int i=0; i<Image1->Picture->Bitmap->Width; i++) {
       if (dash < DashPix) {
         Image1->Canvas->Pixels[i][11] = clBlack;
         dash++;
         if (dash == DashPix) space = 0; }
       else if (space < SpacePix) {
         Image1->Canvas->Pixels[i][11] = clWhite;
         space++;
         if (space == SpacePix) dash = 0; }
       }
     }
}
//---------------------------------------------------------------------------

void __fastcall TZoneLineForm::LabeledEdit1Exit(TObject *Sender)
{
   double temp;
   try {
     temp = LabeledEdit1->Text.ToDouble(); }
   catch (...) {
	 MessageDlg("Invalid value for dash", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
     return; }

   if (temp <= 0) {
	 MessageDlg("Dash must be >0", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
     return; }

   Dash = temp;
   DrawZoneLine(Dash, Space);
}
//---------------------------------------------------------------------------

void __fastcall TZoneLineForm::LabeledEdit2Exit(TObject *Sender)
{
   double temp;
   try {
     temp = LabeledEdit2->Text.ToDouble(); }
   catch (...) {
	 MessageDlg("Invalid value for space", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
     return; }

   if (temp <= 0) {
	 MessageDlg("Space must be >0", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
     return; }

  Space = temp;
  DrawZoneLine(Dash, Space);
}
//---------------------------------------------------------------------------

// Ok button
void __fastcall TZoneLineForm::Button1Click(TObject *Sender)
{
   if (ToolButton1->Down)
     Zone->LineStyle = SOLID_LINE;
   else if (ToolButton2->Down)
     Zone->LineStyle = DOTTED_LINE;
   else if (ToolButton3->Down)
     Zone->LineStyle = SHORT_DASHED_LINE;
   else if (ToolButton4->Down)
     Zone->LineStyle = LONG_DASHED_LINE;
   else if (ToolButton5->Down) {
     if (Dash <= 0.0 || Space <= 0.0) {
       Zone->user.dash = 0.0;
       Zone->user.space = 0.0;
       Zone->LineStyle = SOLID_LINE;
       }
     else {
       Zone->user.dash = Dash;
       Zone->user.space = Space;
       Zone->LineStyle = USER_DEFINED_LINE;
       }
     }
   else    // default if no line type selected
     //Zone->LineStyle = SOLID_LINE;
     Zone->LineStyle = DefaultZone->LineStyle;

   Zone->LineWidth = ZoneLineWidthComboBox->GetLineWidth();
   Zone->ZoneColor = ColorBox1->Selected;
}
//---------------------------------------------------------------------------

void __fastcall TZoneLineForm::Button3Click(TObject *Sender)
{
   Application->HelpContext(IDH_Zone_Line_Options);
}
//---------------------------------------------------------------------------

bool __fastcall TZoneLineForm::FormHelp(WORD Command, int Data, bool &CallHelp)
{
   return true;
}
//---------------------------------------------------------------------------

