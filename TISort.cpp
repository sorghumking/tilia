//---------------------------------------------------------------------------

#include <vcl.h>
#include <algorithm>
#include <iterator>
#include <deque>
#include "pch.h"
#pragma hdrstop

#include "TISort.h"
#ifndef TISpreadH
#include "TISpread.h"
#endif
#ifndef TISrtFrmH
#include "TISrtFrm.h"
#endif

//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::SSSort(void)
{
   bool sort_samples;
   bool sort_sample_numbers;
   bool sort_sample_names;
   bool sort_rows;
   bool sort_codes;
   bool sort_names;
   bool sort_elements;
   bool sort_units;
   bool sort_contexts;
   bool sort_modifications;
   bool sort_groups;

   TSortForm* SortForm = new TSortForm(this);

   if (SortForm->ShowModal()== mrOk) {
     sort_samples = SortForm->CheckBox1->Checked;
     sort_sample_numbers = SortForm->RadioButton1->Checked;
     sort_sample_names = SortForm->RadioButton2->Checked;
     sort_rows = SortForm->CheckBox2->Checked;
     sort_codes = SortForm->RadioButton3->Checked;
     sort_names = SortForm->RadioButton4->Checked;
     sort_elements = SortForm->RadioButton5->Checked;
     sort_units = SortForm->RadioButton6->Checked;
     sort_contexts = SortForm->RadioButton7->Checked;
     sort_modifications = SortForm->RadioButton8->Checked;
     sort_groups = SortForm->RadioButton9->Checked;
     }
   else
     return;  

   TStringList* SortOrder = new TStringList;
   SortOrder->Assign(SortForm->ListBox1->Items);
   delete SortForm;

   if (sort_samples) {
     if (sort_sample_numbers)
       SortSampleNumbers(ProfGrid());
     else if (sort_sample_names)
       SortSampleNames();
     }

   if (sort_rows) {
     if (sort_codes)
	   SortRows(1,NULL);
     else if (sort_names)
	   SortRows(2,NULL);
     else if (sort_elements)
	   SortRows(3,NULL);
     else if (sort_units)
	   SortRows(4,NULL);
     else if (sort_contexts)
	   SortRows(5,NULL);
     else if (sort_modifications)
	   SortRows(6,NULL);
     else if (sort_groups)
       SortRows(7,SortOrder,NULL);
     }

   delete SortOrder;  
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::SortSampleNumbers(TProfGrid* Grid)
{
   Variant Value;
   UnicodeString msg;

   Screen->Cursor = crHourGlass;

   //TProfGrid* Grid = ProfGrid();

   int col_beg = Grid->FixedCols;
   int col_end = ContentColCount(Grid);

   vector<double> depths;
   deque<double> orig_depths;
   for (int col=col_beg; col<=col_end; col++) {
     try {
         Value = Grid->Cells[col][1]->Value;
         if (Value.Type() != varDouble || Value.IsNull() || Value.IsEmpty()) {
           int acol = Grid->Cells[col][1]->AbsoluteCol;
           msg = "Column " + ColumnNameByIndex(acol) + " has invalid sample number. Cannot sort.";
		   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
           Screen->Cursor = crDefault;
		   return;
           }
         double x = (double)Value;
         depths.push_back(x);
         }
     catch ( ... )
         {
         msg = "Column " + ColumnNameByIndex(col+1) + " has invalid sample number. Cannot sort.";
		 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
         Screen->Cursor = crDefault;
         return;
         }
     }

   bool sorted = true;
   for (unsigned int i=1; i<depths.size(); i++) {
     if (depths[i] < depths[i-1]) {
       sorted = false;
       break;
       }
     }
   if (sorted) {
     Screen->Cursor = crDefault;
     return;
     }
   else {
     copy(depths.begin(),depths.end(),back_inserter(orig_depths));
     stable_sort(depths.begin(), depths.end());
     }

   // find a value larger than any depth
   deque<double>::iterator itr = max_element(orig_depths.begin(), orig_depths.end());
   double MaxValue = *itr + 1.0;

   // iterate through the vector of sorted depths.
   for (unsigned int i=0; i<depths.size(); i++) {
     double depth = depths[i];
     // find depth in the orig_depths deque
     itr = find(orig_depths.begin(), orig_depths.end(), depth);
     // obtain the position of the original depth
     unsigned int pos = itr - orig_depths.begin();
     // delete the depth from orig_depths
     orig_depths.erase(itr);
     // place a dummy depth at the beginning of the deque to keep size the same
     orig_depths.push_front(MaxValue);
     // move column
     if (pos > i)
       Grid->MoveColumn(pos+col_beg, i+col_beg);
     }

   SpreadSheetChanged = true;
   Screen->Cursor = crDefault;
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::SortSampleNames(void)
{
   Variant Value;

   Screen->Cursor = crHourGlass;

   TProfGrid* Grid = ProfGrid();

   int col_beg = Grid->FixedCols;
   int col_end = ContentColCount(Grid);

   TStringList* names = new TStringList;
   TStringList* orig_names = new TStringList;
   names->CaseSensitive = false;
   orig_names->CaseSensitive = false;

   for (int col=col_beg; col<=col_end; col++) {
     Value = Grid->Cells[col][2]->Value;
     UnicodeString name = Value;
     names->Add(name);
     }

   bool sorted = true;
   for (int i=1; i<names->Count; i++) {
     if (names->Strings[i] < names->Strings[i-1]) {
       sorted = false;
       break;
       }
     }
   if (sorted) {
     Screen->Cursor = crDefault;
     return;
     }
   else {
     orig_names->AddStrings(names);
     names->Sort();
     }

   // iterate through the vector of sorted names.
   for (int i=0; i<names->Count; i++) {
     UnicodeString name = names->Strings[i];
     int pos = orig_names->IndexOf(name);
     if (pos > 0)
       orig_names->Move(pos, 0);
     orig_names->Strings[0] = "@#$%^&*_%$#@!";  
     if (pos > i)
       Grid->MoveColumn(pos+col_beg, i+col_beg);
     }

   delete names;
   delete orig_names;
   SpreadSheetChanged = true;
   Screen->Cursor = crDefault;
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::SortRows(int sort_col, TProfGrid* grid)
{
   Variant Value;
   UnicodeString msg;
   TProfGrid* Grid;

   Screen->Cursor = crHourGlass;

   if (grid == NULL)
	 Grid = ProfGrid();
   else
	 Grid = grid;

   int wtf = Grid->FixedRows;
   int row_beg = AbsHeaderRowCount(Grid);
   int row_end = AbsContentRowCount(Grid);

   TStringList* names = new TStringList;
   TStringList* orig_names = new TStringList;
   names->CaseSensitive = false;
   orig_names->CaseSensitive = false;

   for (int row=row_beg; row<=row_end; row++) {
	 Value = Grid->AbsoluteCells[sort_col][row]->Value;
	 UnicodeString name = Value;
     names->Add(name);
     }

   bool sorted = true;
   for (int i=1; i<names->Count; i++) {
     if (names->Strings[i] < names->Strings[i-1]) {
       sorted = false;
       break;
       }
     }
   if (sorted) {
     Screen->Cursor = crDefault;
     return;
     }
   else {
     orig_names->AddStrings(names);
     names->Sort();
     }

   // iterate through the vector of sorted names.
   row_beg = Grid->FixedRows;
   for (int i=0; i<names->Count; i++) {
     UnicodeString name = names->Strings[i];
     int pos = orig_names->IndexOf(name);
     if (pos > 0)
       orig_names->Move(pos, 0);
     orig_names->Strings[0] = "@#$%^&*_%$#@!";
     if (pos > i)
       Grid->MoveRow(pos+row_beg, i+row_beg);
     }

   delete names;
   delete orig_names;
   SpreadSheetChanged = true;
   Screen->Cursor = crDefault;
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::SortRows(int abs_sort_col, TStringList* SortOrder, TProfGrid* grid)
{
   Variant Value;
   UnicodeString name;
   TProfGrid* Grid;

   Screen->Cursor = crHourGlass;

   if (grid == NULL)
	 Grid = ProfGrid();
   else
	 Grid = grid;

   int row_beg = Grid->FixedRows;
   int row_end = ContentRowCount(Grid);

   TStringList* names = new TStringList;
   names->CaseSensitive = false;

   // iterate through the vector of sorted names
   int pos = row_beg;

   int sort_col = abs_sort_col;
   for (int i=1; i<abs_sort_col; i++)
	 if (!Grid->AbsoluteCols[i]->Visible)
       sort_col--;

   for (int i=0; i<SortOrder->Count; i++) {
	 UnicodeString CurrentSort = SortOrder->Strings[i];
     int ipos = pos;
     for (int row=ipos; row<=row_end; row++) {
       Value = Grid->Cells[sort_col][row]->Value;
       if (Value.IsNull() || Value.IsEmpty())
         name = "(blank)";
       else
		 name = Value;
       if (name == CurrentSort) {
         if (row > pos) 
           Grid->MoveRow(row, pos);
         pos++;
         }
       }
     }

   delete names;
   SpreadSheetChanged = true;
   Screen->Cursor = crDefault;
}
//---------------------------------------------------------------------------

