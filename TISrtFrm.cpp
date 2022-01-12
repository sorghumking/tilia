//---------------------------------------------------------------------------

#include <vcl.h>
#include "pch.h"
#pragma hdrstop

#include "TISrtFrm.h"


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TSortForm *SortForm;

//---------------------------------------------------------------------------
__fastcall TSortForm::TSortForm(TComponent* Owner)
        : TForm(Owner)
{
   TTilSpreadSheetForm* TilSpreadSheetForm = (TTilSpreadSheetForm*)Owner;
   Grid = TilSpreadSheetForm->ProfGrid();
   if (!Grid->AbsoluteCols[1]->Visible) {
     RadioButton3->Visible = false;
     RadioButton4->Top -= 24;
     RadioButton5->Top -= 24;
     RadioButton6->Top -= 24;
     RadioButton7->Top -= 24;
     RadioButton8->Top -= 24;
     RadioButton9->Top -= 24;
     }
   if (!Grid->AbsoluteCols[3]->Visible) {
     RadioButton5->Visible = false;
     RadioButton6->Top -= 24;
     RadioButton7->Top -= 24;
     RadioButton8->Top -= 24;
     RadioButton9->Top -= 24;
     }
   if (!Grid->AbsoluteCols[4]->Visible) {
     RadioButton6->Visible = false;
     RadioButton7->Top -= 24;
     RadioButton8->Top -= 24;
     RadioButton9->Top -= 24;
     }
   if (!Grid->AbsoluteCols[5]->Visible) {
     RadioButton7->Visible = false;
     RadioButton8->Top -= 24;
     RadioButton9->Top -= 24;
     }
   if (!Grid->AbsoluteCols[6]->Visible) {
     RadioButton8->Visible = false;
     RadioButton9->Top -= 24;
     }
   if (!Grid->AbsoluteCols[7]->Visible) 
     RadioButton9->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TSortForm::CheckBox1Click(TObject *Sender)
{
   RadioButton1->Enabled = CheckBox1->Checked;
   RadioButton2->Enabled = CheckBox1->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TSortForm::CheckBox2Click(TObject *Sender)
{
   if (Grid->AbsoluteCols[1]->Visible)
     RadioButton3->Enabled = CheckBox2->Checked;
   RadioButton4->Enabled = CheckBox2->Checked;
   if (Grid->AbsoluteCols[3]->Visible)
     RadioButton5->Enabled = CheckBox2->Checked;
   if (Grid->AbsoluteCols[4]->Visible)
     RadioButton6->Enabled = CheckBox2->Checked;
   if (Grid->AbsoluteCols[5]->Visible)
     RadioButton7->Enabled = CheckBox2->Checked;
   if (Grid->AbsoluteCols[6]->Visible)
     RadioButton8->Enabled = CheckBox2->Checked;
   if (Grid->AbsoluteCols[7]->Visible)
     RadioButton9->Enabled = CheckBox2->Checked;
   Label1->Enabled = CheckBox2->Checked;
   ListBox1->Enabled = CheckBox2->Checked;
   SpeedButton1->Enabled = CheckBox2->Checked;
   SpeedButton2->Enabled = CheckBox2->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TSortForm::RadioButton3Click(TObject *Sender)
{
   Label1->Visible = false;
   ListBox1->Visible = false;
   SpeedButton1->Visible = false;
   SpeedButton2->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TSortForm::RadioButton4Click(TObject *Sender)
{
   Label1->Visible = false;
   ListBox1->Visible = false;
   SpeedButton1->Visible = false;
   SpeedButton2->Visible = false;
}
//---------------------------------------------------------------------------
void __fastcall TSortForm::RadioButton5Click(TObject *Sender)
{
   Label1->Visible = true;
   ListBox1->Visible = true;
   SpeedButton1->Visible = false;
   SpeedButton2->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TSortForm::RadioButton6Click(TObject *Sender)
{
   Label1->Visible = false;
   ListBox1->Visible = false;
   SpeedButton1->Visible = false;
   SpeedButton2->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TSortForm::RadioButton7Click(TObject *Sender)
{
   Label1->Visible = false;
   ListBox1->Visible = false;
   SpeedButton1->Visible = false;
   SpeedButton2->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TSortForm::RadioButton8Click(TObject *Sender)
{
   Label1->Visible = false;
   ListBox1->Visible = false;
   SpeedButton1->Visible = false;
   SpeedButton2->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TSortForm::RadioButton9Click(TObject *Sender)
{
   Label1->Visible = true;
   ListBox1->Visible = true;
   SpeedButton1->Visible = true;
   SpeedButton2->Visible = true;

   int row_end = TilSpreadSheetForm->AbsContentRowCount(Grid);
   int row_beg = TilSpreadSheetForm->AbsHeaderRowCount(Grid);

   UnicodeString name;
   bool FirstBlank = true;
   for (int row=row_beg; row<=row_end; row++) {
     Variant Value = Grid->AbsoluteCells[7][row]->Value;
     if (Value.IsNull() || Value.IsEmpty()) {
       if (FirstBlank) {
         name = "(blank)";
         ListBox1->Items->Add(name);
         FirstBlank = false;
         }
       }
     else {
	   name = Value;
       if (ListBox1->Items->IndexOf(name) == -1)
         ListBox1->Items->Add(name);
       }
     }

   ListBox1->Sorted = false;
}
//---------------------------------------------------------------------------

// move item up one
void __fastcall TSortForm::SpeedButton1Click(TObject *Sender)
{
   int Index = ListBox1->ItemIndex;
   if (Index > 0) {
     ListBox1->Items->Move(Index, Index-1);
     ListBox1->Selected[Index-1] = true;
     }
}
//---------------------------------------------------------------------------

// move item down one
void __fastcall TSortForm::SpeedButton2Click(TObject *Sender)
{
   int Index = ListBox1->ItemIndex;
   if (Index >= 0 && Index < ListBox1->Items->Count-1) {
     ListBox1->Items->Move(Index, Index+1);
     ListBox1->Selected[Index+1] = true;
     }
}
//---------------------------------------------------------------------------

