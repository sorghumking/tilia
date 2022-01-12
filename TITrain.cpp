//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TITrain.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxGraphics"
#pragma resource "*.dfm"
TTrainForm *TrainForm;
//---------------------------------------------------------------------------
__fastcall TTrainForm::TTrainForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TTrainForm::FormCreate(TObject *Sender)
{
   Delay = 4;
   FreeChug = true;
   RealPosition = 0;
   DoubleBuffered = true;
   TrainBmp = new Graphics::TBitmap;
   TrainBmp->PixelFormat = pf24bit;
   cxTrainImage->GetBitmap(0, TrainBmp);
   WheelsBmp1 = new Graphics::TBitmap;
   WheelsBmp1->PixelFormat = pf24bit;
   cxWheelImages->GetBitmap(0, WheelsBmp1);
   WheelsBmp2 = new Graphics::TBitmap;
   WheelsBmp2->PixelFormat = pf24bit;
   cxWheelImages->GetBitmap(1, WheelsBmp2);
   WheelsBmp3 = new Graphics::TBitmap;
   WheelsBmp3->PixelFormat = pf24bit;
   cxWheelImages->GetBitmap(2, WheelsBmp3);
   WheelsBmp4 = new Graphics::TBitmap;
   WheelsBmp4->PixelFormat = pf24bit;
   cxWheelImages->GetBitmap(3, WheelsBmp4);
   WheelsBmp5 = new Graphics::TBitmap;
   WheelsBmp5->PixelFormat = pf24bit;
   cxWheelImages->GetBitmap(4, WheelsBmp5);
   WheelsBmp6 = new Graphics::TBitmap;
   WheelsBmp6->PixelFormat = pf24bit;
   cxWheelImages->GetBitmap(5, WheelsBmp6);
   WheelsBmp7 = new Graphics::TBitmap;
   WheelsBmp7->PixelFormat = pf24bit;
   cxWheelImages->GetBitmap(6, WheelsBmp7);
   WheelsBmp8 = new Graphics::TBitmap;
   WheelsBmp8->PixelFormat = pf24bit;
   cxWheelImages->GetBitmap(7, WheelsBmp8);

   Image1->Picture->Bitmap->Height = 32;
   Image1->Picture->Bitmap->Width = 256;
   Image1->Picture->Bitmap->PixelFormat = pf24bit;

   left = 512;
   WheelPosition = 1;
   DestRect = Rect(0,0,255,32);
   WheelsRect = Rect(0,0,15,7);
   TrainWheelsRect = Rect(476,19,490,25);
   TrainBmp->Canvas->CopyRect(TrainWheelsRect, WheelsBmp1->Canvas, WheelsRect);
   TrainRect = Rect(left,0,left+255,32);

   Image1->Picture->Bitmap->Canvas->CopyRect(DestRect, TrainBmp->Canvas, TrainRect);
   Image1->Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TTrainForm::FormActivate(TObject *Sender)
{
   Time0 = TDateTime::CurrentTime();
}
//---------------------------------------------------------------------------

void __fastcall TTrainForm::FormDestroy(TObject *Sender)
{
   delete TrainBmp;
   delete WheelsBmp1;
   delete WheelsBmp2;
   delete WheelsBmp3;
   delete WheelsBmp4;
   delete WheelsBmp5;
   delete WheelsBmp6;
   delete WheelsBmp7;
   delete WheelsBmp8;
}
//---------------------------------------------------------------------------

void __fastcall TTrainForm::Chug(void)
{
   unsigned short hour, min, sec, msec;
   unsigned int isec;

   if (FreeChug) {
     TDateTime Time1 = TDateTime::CurrentTime();
     TDateTime DeltaTime = Time1 - Time0;
     DeltaTime.DecodeTime(&hour, &min, &sec, &msec);
     isec = 1000*sec + msec;
     if (isec < Delay) return;
     Time0 = Time1;
     }

   left -= 2;
   if (left < 0) left = 512;

   WheelPosition++;
   if (WheelPosition == 9) WheelPosition = 1;
   switch (WheelPosition)
    {
    case 1:
      TrainBmp->Canvas->CopyRect(TrainWheelsRect, WheelsBmp1->Canvas, WheelsRect);
      break;
    case 2:
      TrainBmp->Canvas->CopyRect(TrainWheelsRect, WheelsBmp2->Canvas, WheelsRect);
      break;
    case 3:
      TrainBmp->Canvas->CopyRect(TrainWheelsRect, WheelsBmp3->Canvas, WheelsRect);
      break;
    case 4:
      TrainBmp->Canvas->CopyRect(TrainWheelsRect, WheelsBmp4->Canvas, WheelsRect);
      break;
    case 5:
      TrainBmp->Canvas->CopyRect(TrainWheelsRect, WheelsBmp5->Canvas, WheelsRect);
      break;
    case 6:
      TrainBmp->Canvas->CopyRect(TrainWheelsRect, WheelsBmp6->Canvas, WheelsRect);
      break;
    case 7:
      TrainBmp->Canvas->CopyRect(TrainWheelsRect, WheelsBmp7->Canvas, WheelsRect);
      break;
    case 8:
      TrainBmp->Canvas->CopyRect(TrainWheelsRect, WheelsBmp8->Canvas, WheelsRect);
      break;
    }

   TrainRect = Rect(left,0,left+255,32);
   Image1->Picture->Bitmap->Canvas->CopyRect(DestRect, TrainBmp->Canvas, TrainRect);
   Image1->Repaint();
}
//---------------------------------------------------------------------------

void TTrainForm::SetMinMaxPos(int mn, int mx, int pos)
{
   FreeChug = false;
   left = 512;
   WheelPosition = 1;
   MinPosition = mn;
   MaxPosition = mx;
   Position = 0;
   RealPosition = 0;
   Step = (MaxPosition - MinPosition)/128.0;
}
//---------------------------------------------------------------------------

void __fastcall TTrainForm::SetPosition(int pos)
{
   if (!Step) return;
   RealPosition = (double)pos - MinPosition;
   int NewPosition = (int)(RealPosition/Step);
   while (Position < NewPosition) {
     Chug();
     Position++;
     }
}
//---------------------------------------------------------------------------

void __fastcall TTrainForm::ResetPosition(int pos)
{
   FreeChug = false;
   left = 512;
   WheelPosition = 1;
   Position = 0;
   RealPosition = 0;
}
//---------------------------------------------------------------------------

void TTrainForm::SetFreeChug(void)
{
   FreeChug = true;
   left = 512;
   WheelPosition = 1;
   Position = 0;
   RealPosition = 0;
   Time0 = TDateTime::CurrentTime();
}
//---------------------------------------------------------------------------

void __fastcall TTrainForm::IncrementPosition(void)
{
   RealPosition += Step;
   int NewPosition = (int)(RealPosition/Step);
   while (Position < NewPosition) {
     Chug();
     Position++;
     }
}
//---------------------------------------------------------------------------
