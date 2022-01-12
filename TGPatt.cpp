//---------------------------------------------------------------------------
#include <vcl.h>
#include "pch.h"
#pragma hdrstop

#include "TGPatt.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TPatternForm *PatternForm;
//---------------------------------------------------------------------------
__fastcall TPatternForm::TPatternForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void TPatternForm::Initialize(short idx)
{
  ToolButton1->Down  = false;
  ToolButton2->Down  = false;
  ToolButton3->Down  = false;
  ToolButton4->Down  = false;
  ToolButton5->Down  = false;
  ToolButton6->Down  = false;
  ToolButton7->Down  = false;
  ToolButton8->Down  = false;
  ToolButton9->Down  = false;
  ToolButton10->Down = false;
  ToolButton11->Down = false;
  ToolButton12->Down = false;
  ToolButton13->Down = false;
  ToolButton14->Down = false;
  ToolButton15->Down = false;
  ToolButton16->Down = false;
  ToolButton17->Down = false;
  ToolButton18->Down = false;
  ToolButton19->Down = false;
  ToolButton20->Down = false;
  ToolButton21->Down = false;
  ToolButton22->Down = false;
  ToolButton23->Down = false;
  ToolButton24->Down = false;
  ToolButton25->Down = false;
  ToolButton26->Down = false;
  ToolButton27->Down = false;
  ToolButton28->Down = false;
  ToolButton29->Down = false;
  ToolButton30->Down = false;
  ToolButton31->Down = false;
  ToolButton32->Down = false;
  ToolButton33->Down = false;

  switch (idx)
  {
  case 1:  ToolButton1->Down =  true; break;
  case 2:  ToolButton2->Down =  true; break;
  case 3:  ToolButton3->Down =  true; break;
  case 4:  ToolButton4->Down =  true; break;
  case 5:  ToolButton5->Down =  true; break;
  case 6:  ToolButton6->Down =  true; break;
  case 7:  ToolButton7->Down =  true; break;
  case 8:  ToolButton8->Down =  true; break;
  case 9:  ToolButton9->Down =  true; break;
  case 10: ToolButton10->Down = true; break;
  case 11: ToolButton12->Down = true; break;
  case 12: ToolButton11->Down = true; break;
  case 13: ToolButton13->Down = true; break;
  case 14: ToolButton14->Down = true; break;
  case 15: ToolButton15->Down = true; break;
  case 16: ToolButton16->Down = true; break;
  case 17: ToolButton17->Down = true; break;
  case 18: ToolButton18->Down = true; break;
  case 19: ToolButton19->Down = true; break;
  case 20: ToolButton20->Down = true; break;
  case 21: ToolButton21->Down = true; break;
  case 22: ToolButton22->Down = true; break;
  case 23: ToolButton23->Down = true; break;
  case 24: ToolButton24->Down = true; break;
  case 25: ToolButton25->Down = true; break;
  case 26: ToolButton26->Down = true; break;
  case 27: ToolButton27->Down = true; break;
  case 28: ToolButton28->Down = true; break;
  case 29: ToolButton29->Down = true; break;
  case 30: ToolButton30->Down = true; break;
  case 31: ToolButton31->Down = true; break;
  case 32: ToolButton32->Down = true; break;
  case 33: ToolButton33->Down = true; break;
  }
}

//---------------------------------------------------------------------------
// Ok Button
void __fastcall TPatternForm::Button1Click(TObject *Sender)
{
  if (ToolButton1->Down) PatternIndex = 1;
  else if (ToolButton2->Down)  PatternIndex = 2;
  else if (ToolButton3->Down)  PatternIndex = 3;
  else if (ToolButton4->Down)  PatternIndex = 4;
  else if (ToolButton5->Down)  PatternIndex = 5;
  else if (ToolButton6->Down)  PatternIndex = 6;
  else if (ToolButton7->Down)  PatternIndex = 7;
  else if (ToolButton8->Down)  PatternIndex = 8;
  else if (ToolButton9->Down)  PatternIndex = 9;
  else if (ToolButton10->Down) PatternIndex = 10;
  else if (ToolButton11->Down) PatternIndex = 12;
  else if (ToolButton12->Down) PatternIndex = 11;
  else if (ToolButton13->Down) PatternIndex = 13;
  else if (ToolButton14->Down) PatternIndex = 14;
  else if (ToolButton15->Down) PatternIndex = 15;
  else if (ToolButton16->Down) PatternIndex = 16;
  else if (ToolButton17->Down) PatternIndex = 17;
  else if (ToolButton18->Down) PatternIndex = 18;
  else if (ToolButton19->Down) PatternIndex = 19;
  else if (ToolButton20->Down) PatternIndex = 20;
  else if (ToolButton21->Down) PatternIndex = 21;
  else if (ToolButton22->Down) PatternIndex = 22;
  else if (ToolButton23->Down) PatternIndex = 23;
  else if (ToolButton24->Down) PatternIndex = 24;
  else if (ToolButton25->Down) PatternIndex = 25;
  else if (ToolButton26->Down) PatternIndex = 26;
  else if (ToolButton27->Down) PatternIndex = 27;
  else if (ToolButton28->Down) PatternIndex = 28;
  else if (ToolButton29->Down) PatternIndex = 29;
  else if (ToolButton30->Down) PatternIndex = 30;
  else if (ToolButton31->Down) PatternIndex = 31;
  else if (ToolButton32->Down) PatternIndex = 32;
  else if (ToolButton33->Down) PatternIndex = 33;
  else PatternIndex = -1;
}
//---------------------------------------------------------------------------

