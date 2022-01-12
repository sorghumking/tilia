//---------------------------------------------------------------------------

#include <vcl.h>
#include "pch.h"
#include <utilcls.h>
#pragma hdrstop

#include "TISumPer.h"
#ifndef TIGlobalsH
#include "TIGlobals.h"
#endif
#ifndef TISpreadH
#include "TISpread.h"
#endif
#ifndef TITrainH
#include "TITrain.h"
#endif
#ifndef TICommonH
#include "TICommon.h"
#endif

//---------------------------------------------------------------------------

#pragma package(smart_init)
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::ClearSums(void)
{
   if (Sums->Count > 0) {
     for (int i=0; i<Sums->Count; i++) {
       SUM* Sum = (SUM*)Sums->Items[i];
       delete Sum;
       Sums->Items[i] = 0;
       }
     Sums->Clear();
     }
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::ClearSSums(void)
{
   if (SSums->Count > 0) {
     for (int i=0; i<SSums->Count; i++) {
       SSUM* SSum = (SSUM*)SSums->Items[i];
       delete SSum;
       SSums->Items[i] = 0;
       }
     SSums->Clear();
     }
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::AddSum(UnicodeString& Code, UnicodeString& Base,
        bool Percent, int Row)
{
   SUM* Sum = new SUM(Code, Base, Percent, Row);
   Sums->Add(Sum);
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::AddSSum(UnicodeString& Code, UnicodeString& Groups,
        int Row)
{
   SSUM* SSum = new SSUM(Code, Row);
   UnicodeString temp = Groups;
   int pos;
   UnicodeString group;
   while ((pos = temp.Pos(";")) > 0) {
     group = temp.SubString(1, pos-1);
     SSum->Sums->Add(group);
     temp = temp.SubString(pos+1, temp.Length()-pos);
     }
   if (temp.Length() > 0)
     SSum->Sums->Add(temp);
   SSums->Add(SSum);
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::CalculateSums(int SumsAs)
{
   UnicodeString SumCode, VarCode, Formula;
   SUM* Sum;

   int VarRowCount = AbsContentRowCount(ProfGrid1);
   int End = AbsContentColCount(ProfGrid1);
   int Start = AbsHeaderColCount(ProfGrid1);

   Screen->Cursor = crHourGlass;
   if (SumsAs == 0) {
     for (int j=Start; j<=End; j++) {
       // zero sums
       for (int k=0; k<Sums->Count; k++) {
         Sum = (SUM*)Sums->Items[k];
         Sum->Count = 0.0;
         }
       // tally counts
       for (int i=3; i<=VarRowCount; i++) {
         SumCode = ProfGrid1->AbsoluteCells[7][i]->Text;
         VarCode = ProfGrid1->AbsoluteCells[1][i]->Text;
         if (VarCode.SubString(1,3) == "SUM" || VarCode.SubString(1,4) == "SSUM")
           continue;
         for (int k=0; k<Sums->Count; k++) {
           Sum = (SUM*)Sums->Items[k];
           if (Sum->Code == SumCode) {
             Variant Value = ProfGrid1->AbsoluteCells[j][i]->Value;
             if (Value.Type() == varDouble)
               Sum->Count += double(Value);
             break;
             }
           }
         }
       // write sums to spreadsheet
       for (int k=0; k<Sums->Count; k++) {
         Sum = (SUM*)Sums->Items[k];
         ProfGrid1->AbsoluteCells[j][Sum->Row]->Value = Sum->Count;
         }

       // tally and write supersums
       for (int k=0; k<SSums->Count; k++) {
         SSUM* SSum = (SSUM*)SSums->Items[k];
         SSum->Count = 0.0;
         for (int ks=0; ks<SSum->Sums->Count; ks++) {
           for (int i=0; i<Sums->Count; i++) {
             Sum = (SUM*)Sums->Items[i];
             SumCode = SSum->Sums->Strings[ks];
             if (SumCode == Sum->Code)
               SSum->Count += Sum->Count;
             }
           }
         ProfGrid1->AbsoluteCells[j][SSum->Row]->Value = SSum->Count;
         }
       }
     SpreadSheetChanged = true;
     }
   else if (SumsAs == 1) {
     UnicodeString LastSumCode;
     Sum = NULL;
     for (int i=3; i<=VarRowCount; i++) {
       SumCode = ProfGrid1->AbsoluteCells[7][i]->Text;
       VarCode = ProfGrid1->AbsoluteCells[1][i]->Text;
       if (SumCode.IsEmpty())
         continue;
       if (VarCode.SubString(1,3) == "SUM" || VarCode.SubString(1,4) == "SSUM")
         continue;
       if (SumCode == LastSumCode) {
         if (Sum != NULL)
           Sum->End = i;
         }
       else {
         for (int k=0; k<Sums->Count; k++) {
           Sum = (SUM*)Sums->Items[k];
           if (Sum->Code == SumCode) {
             Sum->Start = i;
             Sum->End = i;
             LastSumCode = SumCode;
             break;
             }
           }
         }
       }

     for (int j=Start; j<=End; j++) {
       UnicodeString A1Name = ProfGrid1->AbsoluteCols[j]->A1Name;
       for (int k=0; k<Sums->Count; k++) {
         Sum = (SUM*)Sums->Items[k];
         Formula = "SUM(" + A1Name + IntToStr(Sum->Start) + ":" + A1Name +
                   IntToStr(Sum->End) + ")";
         ProfGrid1->AbsoluteCells[j][Sum->Row]->Formula = Formula;
         }

       for (int k=0; k<SSums->Count; k++) {
         SSUM* SSum = (SSUM*)SSums->Items[k];
         Formula = "SUM(";
         for (int ks=0; ks<SSum->Sums->Count; ks++) {
           for (int i=0; i<Sums->Count; i++) {
             Sum = (SUM*)Sums->Items[i];
             SumCode = SSum->Sums->Strings[ks];
             if (SumCode == Sum->Code) {
               if (Formula.Length() > 4)
                 Formula += ",";
               Formula += A1Name;
               Formula += IntToStr(Sum->Row);
               }
             }
           }
         Formula += ")";
         ProfGrid1->AbsoluteCells[j][SSum->Row]->Formula = Formula;
         }
       }
     SpreadSheetChanged = true;
     }
   Screen->Cursor = crDefault;     
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::CalculatePercents(int DiagramType)
{
   UnicodeString VarCode, GroupCode, Message;
   UnicodeString Blank;
   double GroupSum, Count;
   int SumRow;
   bool NullEncountered = false;
   bool Aborted = false;
   bool TreatAsZero;
   map<int,int> r;
   int row = 3;

   Screen->Cursor = crHourGlass;
   ClearSums();
   ClearSSums();

   int VarRowCount = AbsContentRowCount(ProfGrid1);
   int SamColCount = AbsContentColCount(ProfGrid1);
   int HeaderCols = AbsHeaderColCount(ProfGrid1);
   int HeaderRows = AbsHeaderRowCount(ProfGrid1);

   TrainForm = new TTrainForm(this);
   TrainForm->Caption = "Calculating percents...";
   TrainForm->SetMinMaxPos(0, VarRowCount, 0);
   TrainForm->Show();
   TrainForm->Repaint();

   // get sums from data worksheet
   for (int i=HeaderRows; i<=VarRowCount; i++) {
     VarCode = ProfGrid1->AbsoluteCells[1][i]->Text;
     if (VarCode.SubString(1,3) == "SUM") {
       GroupCode = DecodeSum(VarCode);
	   UnicodeString Base = ProfGrid1->AbsoluteCells[7][i]->Text;
	   UnicodeString Units = ProfGrid1->AbsoluteCells[4][i]->Text;
       bool Percent = (Units.LowerCase() == "percent") ? true : false;
       AddSum(GroupCode, Base, Percent, i);
       }
     else if (VarCode.SubString(1,4) == "SSUM") {
	   UnicodeString GroupCode = DecodeSSum(VarCode);
       AddSSum(GroupCode, Blank, i);
       }
     }
   if (!Sums->Count) {
     TrainForm->Close();
     delete TrainForm;
	 MessageDlg("No sums found in spreadsheet.", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
     Screen->Cursor = crDefault;
	 return;
     }

   int dec = tiGlobals->PercentDecimalPlaces;
   WideString Format = "0.";
   for (int i=0; i<dec; i++)
     Format += "0";

   bool found = false;
   for (int i=1; i<cxPageControl1->PageCount; i++) {
     TcxTabSheet* TabSheet = cxPageControl1->Pages[i];
     if (TabSheet->Caption == "Percents") {
       cxPageControl1->ActivePage = TabSheet;
       ProfGrid2->ResetCells();
       found = true;
       break;
       }
	 }

   if (!found)
     InsertPercentsSheet(true);

   ProfGrid2->ColCount = ProfGrid1->ColCount;
   ProfGrid2->RowCount = ProfGrid1->RowCount;

   ProfGrid2->DisableControls();
   ProfGrid2->SpreadsheetEnabled = false;

   // copy row headers

   for (int i=3; i<=VarRowCount; i++) {
	 bool skip = false;
	 bool chron = false;
	 if (DiagramType == dtDefault) {
	   UnicodeString VarCode = ProfGrid1->AbsoluteCells[1][i]->Text;
	   if (!VarCode.IsEmpty()) {
		 if (VarCode[1] == L'#') {
		   if (SameText(VarCode.SubString(1,6),L"#Chron"))
			 chron = true;
		   else
			 skip = true;
		   }
		 }

	   if (!skip && !chron) {
		 UnicodeString GroupCode = ProfGrid1->AbsoluteCells[7][i]->Text;
		 if (GroupCode.IsEmpty() || SameText(GroupCode,L"LABO") ||
			 SameText(GroupCode,L"CONC") || SameText(GroupCode,L"CHAR") ||
			 SameText(GroupCode,L"MNRL") || SameText(GroupCode,L"BIOM")) {
		   skip = true;
		   }
		 }
	   }

	 if (!skip) {
	   r[i] = row++;
	   for (int j=1; j<HeaderCols; j++)      // <=7
		 ProfGrid2->AbsoluteCells[j][r[i]]->Value = ProfGrid1->AbsoluteCells[j][i]->Value;
	   }
	 else
	   r[i] = 0;
	 }

   // copy column headers
   for (int i=1; i<HeaderRows; i++) {        // <=2
     for (int j=HeaderCols; j<=SamColCount; j++)
       ProfGrid2->AbsoluteCells[j][i]->Value = ProfGrid1->AbsoluteCells[j][i]->Value;
     }

   for (int i=HeaderRows; i<=VarRowCount; i++) {     // i=3
     TrainForm->SetPosition(i);
	 if (r[i] == 0) continue;
	 VarCode = ProfGrid1->AbsoluteCells[1][i]->Text;
	 if (VarCode.SubString(1,1) == L"#") {
	   for (int j=HeaderCols; j<=SamColCount; j++)
		 ProfGrid2->AbsoluteCells[j][r[i]]->Value = ProfGrid1->AbsoluteCells[j][i]->Value;
	   }
	 else if (VarCode.SubString(1,3) == L"SUM") {
	   SumRow = 0;
	   UnicodeString Units = ProfGrid1->AbsoluteCells[4][i]->Text;
	   if (Units.LowerCase() == L"percent") {
         GroupCode = ProfGrid1->AbsoluteCells[7][i]->Text;
         for (int k=0; k<SSums->Count; k++) {
           SSUM* SSum = (SSUM*)SSums->Items[k];
           if (GroupCode == SSum->Code) {
             SumRow = SSum->Row;
             break;
             }
           }
         }
       if (SumRow > 0) {
         for (int j=HeaderCols; j<=SamColCount; j++) {
           Variant GroupSumValue = ProfGrid1->AbsoluteCells[j][SumRow]->Value;
           if (GroupSumValue.Type() == varDouble) {
             Variant CountValue = ProfGrid1->AbsoluteCells[j][i]->Value;
			 UnicodeString Text = ProfGrid1->AbsoluteCells[j][i]->Text;
             if (CountValue.Type() == varDouble) {
               GroupSum = (double)GroupSumValue;
               if (GroupSum > 0.0) {
                 Count = (double)CountValue;
				 ProfGrid2->AbsoluteCells[j][r[i]]->Value = (Count/GroupSum)*100.0;
				 ProfGrid2->AbsoluteCells[j][r[i]]->Format = Format;
				 }
               else if (CalcPercentsError(j, SumRow) == mrCancel) {
                 Aborted = true;
                 break;
                 }
               }
             else if (CountValue.IsNull() || CountValue.IsEmpty()) {
               if (!NullEncountered) {
				 int rv;
				 if (Downloaded)
				   rv = mrYes;
				 else {
				   UnicodeString msg = "Null value encountered. Treat as zero?\nClicking \"Ignore\" will treat as null.";
				   rv = MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbIgnore << mbAbort, 0);
				   }
				 if (rv == mrYes)
				   TreatAsZero = true;
                 else if (rv == mrIgnore)
                   TreatAsZero = false;
                 else if (rv == mrAbort) {
                   Aborted = true;
                   break;
                   }
                 NullEncountered = true;
                 }
               if (TreatAsZero) {
				 ProfGrid2->AbsoluteCells[j][r[i]]->Value = 0.0;
				 ProfGrid2->AbsoluteCells[j][r[i]]->Format = Format;
                 }
               }
             else if (CalcPercentsError(j,i) == mrCancel) {
               Aborted = true;
               break;
               }
             }
           else if (CalcPercentsError(j, SumRow) == mrCancel) {
             Aborted = true;
             break;
             }
           }
         }
       else {
		 for (int j=HeaderCols; j<=SamColCount; j++)
		   ProfGrid2->AbsoluteCells[j][r[i]]->Value = ProfGrid1->AbsoluteCells[j][i]->Value;
         }
       }
     else if (VarCode.SubString(1,4) == "SSUM") {
       for (int j=HeaderCols; j<=SamColCount; j++)
		 ProfGrid2->AbsoluteCells[j][r[i]]->Value = ProfGrid1->AbsoluteCells[j][i]->Value;
       }
     else if (ProfGrid1->AbsoluteCells[7][i]->Value.IsNull() ||
              ProfGrid1->AbsoluteCells[7][i]->Value.IsEmpty() ||
              ProfGrid1->AbsoluteCells[7][i]->Text == (WideString)"-")
       {
         for (int j=HeaderCols; j<=SamColCount; j++)
		   ProfGrid2->AbsoluteCells[j][r[i]]->Value = ProfGrid1->AbsoluteCells[j][i]->Value;
       }
     else {
       GroupCode = ProfGrid1->AbsoluteCells[7][i]->Text;
       SumRow = 0;
       for (int k=0; k<Sums->Count; k++) {
         SUM* Sum = (SUM*)Sums->Items[k];
         if (GroupCode == Sum->Code) {
           for (int m=0; m<SSums->Count; m++) {
             SSUM* SSum = (SSUM*)SSums->Items[m];
             if (Sum->Base == SSum->Code) {
               SumRow = SSum->Row;
               break;
               }
             }
           break;
           }
         }
	   TColor RareColor = tiGlobals->RareColor;
       if (SumRow > 0) {
         for (int j=HeaderCols; j<=SamColCount; j++) {
		   if (ProfGrid1->AbsoluteCells[j][i]->Font->Color == RareColor) {
			 ProfGrid2->AbsoluteCells[j][r[i]]->Value = ProfGrid1->AbsoluteCells[j][i]->Value;
			 ProfGrid2->AbsoluteCells[j][r[i]]->Font->Color = RareColor;
			 continue;
             }
           Variant GroupSumValue = ProfGrid1->AbsoluteCells[j][SumRow]->Value;
           if (GroupSumValue.Type() == varDouble) {
             Variant CountValue = ProfGrid1->AbsoluteCells[j][i]->Value;
             if (CountValue.Type() == varDouble) {
               GroupSum = (double)GroupSumValue;
               if (GroupSum > 0.0) {
                 Count = (double)CountValue;
				 ProfGrid2->AbsoluteCells[j][r[i]]->Value = (Count/GroupSum)*100.0;
                 //ProfGrid2->Cells[j][i]->Format = "0.00";  // always 2 decimal places
                 //ProfGrid2->Cells[j][i]->Format = "0.##";  // two decimal places if necessary
				 //ProfGrid2->Cells[j][i]->Format = "0.000E+00";
				 ProfGrid2->AbsoluteCells[j][r[i]]->Format = Format;
                 }
               else if (CalcPercentsError(j, SumRow) == mrCancel) {
                 Aborted = true;
                 break;
                 }
               }
             else if (CountValue.IsNull() || CountValue.IsEmpty()) {
               if (!NullEncountered) {
                 int rv;
				 if (Downloaded)
				   rv = mrYes;
				 else {
				   UnicodeString msg = "Null value encountered. Treat as zero?\nClicking \"Ignore\" will treat as null.";
				   rv = MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbIgnore << mbAbort, 0);
				   }
				 if (rv == mrYes)
                   TreatAsZero = true;
                 else if (rv == mrIgnore)
                   TreatAsZero = false;
                 else if (rv == mrAbort) {
                   Aborted = true;
                   break;
                   }
                 NullEncountered = true;
                 }
               if (TreatAsZero) {
				 ProfGrid2->AbsoluteCells[j][r[i]]->Value = 0.0;
				 ProfGrid2->AbsoluteCells[j][r[i]]->Format = Format;
                 }
               }
             else if (CalcPercentsError(j,i) == mrCancel) {
               Aborted = true;
               break;
               }
             }
           else if (CalcPercentsError(j, SumRow) == mrCancel) {
             Aborted = true;
             break;
             }
           }
		 ProfGrid2->AbsoluteCells[4][r[i]]->Value = "percent";
         }
       else {   // Group isn't included in any sum (e.g. LABO)
         for (int j=HeaderCols; j<=SamColCount; j++)
		   ProfGrid2->AbsoluteCells[j][r[i]]->Value = ProfGrid1->AbsoluteCells[j][i]->Value;
         }
       }
     if (Aborted) {
	   ProfGrid2->Reset();
       break;
       }
     }
   ProfGrid2->SpreadsheetEnabled = true;
   ProfGrid2->EnableControls();

   FormatWorksheet(ProfGrid2);

   TrainForm->Close();
   delete TrainForm;
   if (!Aborted) {
     SpreadSheetChanged = true;
     FocusControl(ProfGrid2);
     }
   Screen->Cursor = crDefault;
}
//---------------------------------------------------------------------------

UnicodeString TTilSpreadSheetForm::DecodeSum(UnicodeString& SumCode)
{
   return SumCode.SubString(5, SumCode.Length()-5);
}
//---------------------------------------------------------------------------

UnicodeString TTilSpreadSheetForm::DecodeSSum(UnicodeString& SumCode)
{
   return SumCode.SubString(6, SumCode.Length()-6);
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::FormatPercents(int dec)
{
   Screen->Cursor = crHourGlass;
   int RowCount = AbsContentRowCount(ProfGrid2);
   int ColCount = AbsContentColCount(ProfGrid2);
   int HeaderRows = AbsHeaderRowCount(ProfGrid2);
   int HeaderCols = AbsHeaderColCount(ProfGrid2);
   WideString Format = "0.";
   for (int i=0; i<dec; i++)
     Format += "0";

   ProfGrid2->DisableControls();
   ProfGrid2->SpreadsheetEnabled = false;
   for (int i=HeaderRows; i<=RowCount; i++) {
	 UnicodeString VarCode = ProfGrid2->AbsoluteCells[1][i]->Text;
	 UnicodeString Units = ProfGrid2->AbsoluteCells[4][i]->Text;
     Units = LowerCase(Units);
     UnicodeString Group = ProfGrid2->AbsoluteCells[7][i]->Text;
     if (VarCode.SubString(1,1) != "#" &&
         VarCode.SubString(1,4) != "SSUM" &&
         !(VarCode.SubString(1,3) == "SUM" && Units.LowerCase() != "percent") &&
         Group != "-" && Group.Length() > 0)
       {
       for (int j=HeaderCols; j<ColCount; j++)
         ProfGrid2->AbsoluteCells[j][i]->Format = Format;
       }
     }
  ProfGrid2->SpreadsheetEnabled = true;
  ProfGrid2->EnableControls();
  Screen->Cursor = crDefault;
}
//---------------------------------------------------------------------------

int TTilSpreadSheetForm::CalcPercentsError(int j, int i)
{
   UnicodeString Message = "Invalid value \"" + ProfGrid1->AbsoluteCells[j][i]->Text +
     "\" in cell " + ProfGrid1->AbsoluteCells[j][i]->A1Name + ".";
   return MessageDlg(Message, mtWarning, TMsgDlgButtons() << mbOK << mbCancel, 0);
}
//---------------------------------------------------------------------------

