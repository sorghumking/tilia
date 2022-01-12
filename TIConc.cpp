//---------------------------------------------------------------------------
#include "pch.h"
#include <vcl.h>
#pragma hdrstop

#ifndef TIGlobalsH
#include "TIGlobals.h"
#endif
#include "TIConc.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
//---------------------------------------------------------------------------


bool CalculateConc::Run(void)
{
   UnicodeString VarCode, GroupCode, GroupCodes;
   int Index;
   int left, right, pos;
   bool metadata, sum, GroupFound;
   bool Calculated = false;
   vector<UnicodeString> ssum;

   ConcForm = new TConcForm(TSSForm);

   if (ConcForm->ShowModal() == mrOk) {
	 TreatNulls = ConcForm->TreatNulls;
	 Groups = new TStringList();
	 Groups->Sorted = true;
	 for (int i=0; i<ConcForm->cxCheckListBox1->Count; i++) {
	   if (ConcForm->cxCheckListBox1->Items->Items[i]->Checked)
		 Groups->Add(ConcForm->cxCheckListBox1->Items->Items[i]->Text);
	   }

	 Screen->Cursor = crHourGlass;
	 TSSForm->Concentrations2->Enabled = false;

	 TSSForm->ProfGrid1->DisableControls();
	 TSSForm->ProfGrid1->SpreadsheetEnabled = false;
	 TSSForm->ConcGrid->DisableControls();
	 TSSForm->ConcGrid->SpreadsheetEnabled = false;

	 int RowCount = TSSForm->AbsContentRowCount(TSSForm->ProfGrid1);
	 ColCount = TSSForm->AbsContentColCount(TSSForm->ProfGrid1);
	 int ConcRow = 3;

	 HeaderCols = TSSForm->AbsHeaderColCount(TSSForm->ProfGrid1);

	 for (int row=1; row<=2; row++) {
	   for (int col=HeaderCols; col<=ColCount; col++)
		 TSSForm->ConcGrid->AbsoluteCells[col][row]->Value =
		   TSSForm->ProfGrid1->AbsoluteCells[col][row]->Value;
	   }

	 // fill concentrations grid
	 VarCodes = new TStringList();
	 for (int row=3; row<=RowCount; row++) {
	   metadata = false;
	   sum = false;
	   VarCode = TSSForm->ProfGrid1->AbsoluteCells[1][row]->Value;

	   if (VarCode.SubString(1,1) == L"#")
		 metadata = true;
	   else if (VarCode.SubString(1,3) == L"SUM") {
		 // check if SUM is converted to concentrations
		 left = VarCode.Pos(L"(");
		 right = VarCode.Pos(L")");
		 if (left && right && right > left+1) {
		   GroupCode = VarCode.SubString(left+1, right-left-1);
		   if (Groups->Find(GroupCode, Index))
			 sum = true;
		   }
		 }
	   else if (VarCode.SubString(1,4) == L"SSUM") {
		 // check that all members of supersum converted to concentrations
		 GroupCodes = TSSForm->ProfGrid1->AbsoluteCells[7][row]->Value;
		 ssum.clear();
		 while ((pos = GroupCodes.Pos(L";")) > 0) {        // TRSH;UPHE
		   ssum.push_back(GroupCodes.SubString(1,pos-1));
		   GroupCodes.Delete(1,pos);
		   }
		 ssum.push_back(GroupCodes);  // last code
		 sum = true;
		 unsigned int i = 0;
		 while (sum && i < ssum.size()) {
		   sum = Groups->Find(ssum[i++], Index);
		   }
		 }

	   VarCodes->Add(VarCode);
	   if (!sum) {
		 GroupCode = TSSForm->ProfGrid1->AbsoluteCells[7][row]->Value;
		 GroupFound = Groups->Find(GroupCode, Index);
		 }
	   if (GroupFound || sum)
		 ToConc.push_back(ConcRow);
	   if (GroupFound || metadata || sum || GroupCode == L"CONC") {
         for (int col=1; col<=ColCount; col++)
           TSSForm->ConcGrid->AbsoluteCells[col][ConcRow]->Value =
             TSSForm->ProfGrid1->AbsoluteCells[col][row]->Value;
		 ConcRow++;
         }
       }

     CalcConc(ConcForm->RadioGroup1->ItemIndex);

     TSSForm->ConcGrid->SpreadsheetEnabled = true;
     TSSForm->ConcGrid->EnableControls();
     TSSForm->ProfGrid1->SpreadsheetEnabled = true;
     TSSForm->ProfGrid1->EnableControls();
     delete VarCodes;
     delete Groups;
     Calculated = true;
     }

   Screen->Cursor = crDefault;
   delete ConcForm;
   return Calculated;
}

//---------------------------------------------------------------------------

void CalculateConc::GetConcVarRows(TcxCheckListBox* cxCheckListBox, vector<int>& RowVec)
{
   UnicodeString VarCode;
   int Index;

   for (int i=0; i<cxCheckListBox->Count; i++) {
	 if (cxCheckListBox->Items->Items[i]->Checked) {
	   VarCode = cxCheckListBox->Items->Items[i]->Text;
       if ((Index = VarCodes->IndexOf(VarCode)) > -1)
         RowVec.push_back(Index+3);
       }
     }
}
//---------------------------------------------------------------------------

double CalculateConc::GetConcValue(int col, vector<int>& RowVec)
{
   Variant Value;
   int row;
   double rv = 0.0;

   for (unsigned int i=0; i<RowVec.size(); i++) {
	 row = RowVec[i];
	 Value = TSSForm->ProfGrid1->AbsoluteCells[col][row]->Value;
	 if (Value.Type() == varDouble) {
       if ((rv = Value) > 0.0)
         break;
       }
     }
   return rv;
}
//---------------------------------------------------------------------------

void CalculateConc::CalcConc(int Method)
{
   Variant Value;
   double SpikeAdded, SpikeConcInSample;   //, PollenToSpike;
   double qsm, csm, sq, cnt, count;
   int qsm_row, csm_row, sq_row, cnt_row, ErrorCode;
   vector<int> QuantSpike;
   vector<int> ConcSpikeMed;
   vector<int> SampleQuant;
   vector<int> SpikeCounted;

   // get row(s) for spike counted
   GetConcVarRows(ConcForm->cxCheckListBox2, SpikeCounted);
   if (SpikeCounted.size() == 0) {
     MessageDlg("No variable for Spike. Cannot calculate concentrations.",
				 Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
     TSSForm->ConcGrid->Reset();
     return;
	 }

   if (Method != 2) {
     // get row(s) for sample quantity
	 GetConcVarRows(ConcForm->cxCheckListBox3, SampleQuant);
     if (SampleQuant.size() == 0) {
       MessageDlg("No variable for Quantity of sample. Cannot calculate concentrations.",
                   Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
       TSSForm->ConcGrid->Reset();
       return;
       }

     // Method 0: get row(s) for quantity of spike medium added
     // Method 1: get row(s) for quantity of spike added
     GetConcVarRows(ConcForm->cxCheckListBox4, QuantSpike);
     if (QuantSpike.size() == 0) {
       MessageDlg("No variable for Quantity of spike medium. Cannot calculate concentrations.",
				   Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
       TSSForm->ConcGrid->Reset();
       return;
       }

     if (Method == 0) {
       // get row(s) for concentration of spike medium
       GetConcVarRows(ConcForm->cxCheckListBox5, ConcSpikeMed);
       if (ConcSpikeMed.size() == 0) {
         MessageDlg("No variable for Concentration of spike medium. Cannot calculate concentrations.",
                     Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
         TSSForm->ConcGrid->Reset();
         return;
         }
       }
     }

   bool single_qsm = true;
   bool single_csm = true;
   bool single_sq = true;
   bool single_cnt = true;

   if (SpikeCounted.size() == 1)
     cnt_row = SpikeCounted[0];
   else
     single_cnt = false;

   if (Method != 2) {
     if (QuantSpike.size() == 1)
       qsm_row = QuantSpike[0];
     else
       single_qsm = false;

	 if (SampleQuant.size() == 1)
       sq_row = SampleQuant[0];
     else
       single_sq = false;

     if (Method == 0) {
       if (ConcSpikeMed.size() == 1)
         csm_row = ConcSpikeMed[0];
       else
         single_csm = false;
       }
     }

   WideString Format = "0.";
   int dec = tiGlobals->ConcDecimalPlaces;
   for (int i=0; i<dec; i++)
     Format += "0";

   int result = mrIgnore;
   int col, row;

   try {
       for (col=HeaderCols; col<=ColCount; col++) {
         if (Method != 2) {
           if (single_qsm)
			 qsm = TSSForm->ProfGrid1->AbsoluteCells[col][qsm_row]->Value;
           else
             qsm = GetConcValue(col, QuantSpike);

           if (Method == 0) {
             if (single_csm)
			   csm = TSSForm->ProfGrid1->AbsoluteCells[col][csm_row]->Value;
             else
               csm = GetConcValue(col, ConcSpikeMed);
             }

		   if (single_sq)
			 sq = TSSForm->ProfGrid1->AbsoluteCells[col][sq_row]->Value;
		   else
             sq = GetConcValue(col, SampleQuant);
           }

         if (single_cnt)
		   cnt = TSSForm->ProfGrid1->AbsoluteCells[col][cnt_row]->Value;
         else
		   cnt = GetConcValue(col, SpikeCounted);

         if ((Method == 0 && (qsm == 0.0 || csm == 0.0 || sq == 0.0 || cnt == 0.0)) ||
             (Method == 1 && (qsm == 0.0 || sq == 0.0 || cnt == 0.0)) ||
             (Method == 2 && cnt == 0.0))
           {
           int reply = MessageDlg("Not all data required for calculating concentrations available in column " +
                       TSSForm->ConcGrid->AbsoluteCols[col]->A1Name + ".",
                       Dialogs::mtError, TMsgDlgButtons() << mbOK << mbAbort, 0);
           if (reply == mrOk)
             continue;
           else if (reply == mrAbort)
             return;
           }

         if (Method != 2) {
           if (Method == 0)
             SpikeAdded = qsm*csm;
           else
             SpikeAdded = qsm;
           SpikeConcInSample = SpikeAdded/sq;
           }
         for (unsigned int i=0; i<ToConc.size(); i++) {
           row = ToConc[i];
           Value = TSSForm->ConcGrid->AbsoluteCells[col][row]->Value;

           if (Value.IsNull() || Value.IsEmpty()) {
             if (TreatNulls == SKIPNULL)
               continue;
             else
               count = 0.0;
             }
           else if (Value.Type() == varDouble)
             count = Value;
           else {
             result = MessageDlg("Invalid value in Cell " +
                      TSSForm->ConcGrid->AbsoluteCols[col]->A1Name +
                      IntToStr(row) + ".",
                      mtInformation, TMsgDlgButtons() << mbIgnore << mbAbort, 0);
             if (result == mrIgnore)
               continue;
             else if (result == mrAbort)
               return;
             }

		   double conc = count/cnt;
           if (Method != 2)
             conc *= SpikeConcInSample;

           TProfGridCell* ACell = TSSForm->ConcGrid->AbsoluteCells[col][row];
           ACell->Value = conc;
           ACell->Format = Format;
           }
         }
       }
   catch(Exception &e)
       {
       MessageDlg("Error calculating concentrations near col " + IntToStr(col) +
                  ", row " + IntToStr(row) + ".\n" + e.Message,
                  Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
       }
}
//---------------------------------------------------------------------------

void CalculateInflux::Run(void)
{
   InfluxForm = new TInfluxForm(TSSForm);
   if (InfluxForm->ErrorCode == 0) {
     if (InfluxForm->ShowModal() == mrOk) {
       TSSForm->ConcGrid->DisableControls();
       TSSForm->ConcGrid->SpreadsheetEnabled = false;
       TSSForm->InfluxGrid->DisableControls();
       TSSForm->InfluxGrid->SpreadsheetEnabled = false;
       CalcInflux();
       TSSForm->InfluxGrid->SpreadsheetEnabled = true;
       TSSForm->InfluxGrid->EnableControls();
       TSSForm->ConcGrid->SpreadsheetEnabled = true;
       TSSForm->ConcGrid->EnableControls();
       }
     }
   delete InfluxForm;
   Screen->Cursor = crDefault;
}
//---------------------------------------------------------------------------

void CalculateInflux::CalcInflux(void)
{
   double DT, d1, d2, t1, t2, conc;
   list<int> InfluxRows;
   list<int>::iterator itr;
   UnicodeString VarCode, GroupCode;
   TProfGridCell* ACell;
   Variant Value;
   int reply;

   Screen->Cursor = crHourGlass;
   int HeaderCols = TSSForm->AbsHeaderColCount(TSSForm->ConcGrid);
   int ColCount = TSSForm->AbsContentColCount(TSSForm->ConcGrid);
   int DepthRow = InfluxForm->DepthRow;
   int Method = InfluxForm->Method;
   int ChronRow = InfluxForm->VarRow;

   // check that depths and ages in ascending order
   for (int col=HeaderCols+1; col<=ColCount; col++) {
     d1 = TSSForm->ConcGrid->AbsoluteCells[col-1][DepthRow]->Value;
     d2 = TSSForm->ConcGrid->AbsoluteCells[col][DepthRow]->Value;
     if (d2 <= d1) {
       Screen->Cursor = crDefault;
       MessageDlg("Depths not in ascending order beginning in column " +
                  TSSForm->ConcGrid->AbsoluteCols[col]->A1Name + ".",
				  Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
       return;
       }
     if (Method == 0) {
       t1 = TSSForm->ConcGrid->AbsoluteCells[col-1][ChronRow]->Value;
       t2 = TSSForm->ConcGrid->AbsoluteCells[col][ChronRow]->Value;
       if (t2 <= t1) {
		 Screen->Cursor = crDefault;
		 UnicodeString ChronCode = TSSForm->ConcGrid->AbsoluteCells[1][ChronRow]->Value;
         MessageDlg("Ages for " + ChronCode + " not in ascending order beginning in column " +
                    TSSForm->ConcGrid->AbsoluteCols[col]->A1Name + ".",
                    Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
         return;
         }
       }
     }

   int RowCount = TSSForm->AbsContentRowCount(TSSForm->ConcGrid);

   for (int row=1; row<=2; row++) {
     for (int col=HeaderCols; col<=ColCount; col++)
       TSSForm->InfluxGrid->AbsoluteCells[col][row]->Value =
         TSSForm->ConcGrid->AbsoluteCells[col][row]->Value;
     }
   for (int row=3; row<=RowCount; row++) {
     VarCode = TSSForm->ConcGrid->AbsoluteCells[1][row]->Value;
     GroupCode = TSSForm->ConcGrid->AbsoluteCells[7][row]->Value;
     if (VarCode.SubString(1,1) == "#" || GroupCode == "CONC") {
	   for (int col=1; col<=ColCount; col++)
		 TSSForm->InfluxGrid->AbsoluteCells[col][row]->Value =
           TSSForm->ConcGrid->AbsoluteCells[col][row]->Value;
       }
     else {
       InfluxRows.push_back(row);
       for (int col=1; col<HeaderCols; col++)
         TSSForm->InfluxGrid->AbsoluteCells[col][row]->Value =
           TSSForm->ConcGrid->AbsoluteCells[col][row]->Value;
       }
     }

   WideString Format = "0.";
   int dec = tiGlobals->InfluxDecimalPlaces;
   for (int i=0; i<dec; i++)
     Format += "0";

   list<int>::iterator end = InfluxRows.end();
   int Units = InfluxForm->Units;
   bool m = (Units == METRES);
   TreatNulls = InfluxForm->TreatNulls;

   try {
       if (Method == 0) {                         // calculate Deposition Time
         int DTRow =  RowCount + 1;
         TSSForm->InfluxGrid->AbsoluteCells[1][DTRow]->Value = "dep.time";
         TSSForm->InfluxGrid->AbsoluteCells[2][DTRow]->Value = "Deposition time";
         TSSForm->InfluxGrid->AbsoluteCells[4][DTRow]->Value = "yr/cm";
         // first column
         d1 = TSSForm->ConcGrid->AbsoluteCells[HeaderCols][DepthRow]->Value;
         d2 = TSSForm->ConcGrid->AbsoluteCells[HeaderCols+1][DepthRow]->Value;
         t1 = TSSForm->ConcGrid->AbsoluteCells[HeaderCols][ChronRow]->Value;
         t2 = TSSForm->ConcGrid->AbsoluteCells[HeaderCols+1][ChronRow]->Value;
         DT = (d2-d1)/(t2-t1);
         if (m) DT *= 100.0;
         TSSForm->InfluxGrid->AbsoluteCells[HeaderCols][DTRow]->Value = 1.0/DT;
         itr = InfluxRows.begin();
         while (itr != end) {
           int row = *itr;
           Value = TSSForm->ConcGrid->AbsoluteCells[HeaderCols][row]->Value;
           reply = Evaluate(Value, HeaderCols, row, conc);
           if (reply == mrOk) {
             ACell = TSSForm->InfluxGrid->AbsoluteCells[HeaderCols][row];
             ACell->Value = conc*DT;
             ACell->Format = Format;
             }
           else if (reply == mrAbort)
             return;
           itr++;
           }

         // all except first and last columns
         for (int col=HeaderCols+1; col<ColCount; col++) {
           d1 = TSSForm->ConcGrid->AbsoluteCells[col-1][DepthRow]->Value;
           d2 = TSSForm->ConcGrid->AbsoluteCells[col+1][DepthRow]->Value;
           t1 = TSSForm->ConcGrid->AbsoluteCells[col-1][ChronRow]->Value;
           t2 = TSSForm->ConcGrid->AbsoluteCells[col+1][ChronRow]->Value;
           DT = (d2-d1)/(t2-t1);
           if (m) DT *= 100.0;
           TSSForm->InfluxGrid->AbsoluteCells[col][DTRow]->Value = 1.0/DT;
           itr = InfluxRows.begin();
           while (itr != end) {
             int row = *itr;
             Value = TSSForm->ConcGrid->AbsoluteCells[col][row]->Value;
             reply = Evaluate(Value, col, row, conc);
             if (reply == mrOk) {
               ACell = TSSForm->InfluxGrid->AbsoluteCells[col][row];
               ACell->Value = conc*DT;
               ACell->Format = Format;
               }
             else if (reply == mrAbort)
               return;
             itr++;
             }
           }

         // last column
         d1 = TSSForm->ConcGrid->AbsoluteCells[ColCount-1][DepthRow]->Value;
         d2 = TSSForm->ConcGrid->AbsoluteCells[ColCount][DepthRow]->Value;
         t1 = TSSForm->ConcGrid->AbsoluteCells[ColCount-1][ChronRow]->Value;
         t2 = TSSForm->ConcGrid->AbsoluteCells[ColCount][ChronRow]->Value;
         DT = (d2-d1)/(t2-t1);
         if (m) DT *= 100.0;
         TSSForm->InfluxGrid->AbsoluteCells[ColCount][DTRow]->Value = 1.0/DT;
         itr = InfluxRows.begin();
         while (itr != end) {
           int row = *itr;
           Value = TSSForm->ConcGrid->AbsoluteCells[ColCount][row]->Value;
           reply = Evaluate(Value, ColCount, row, conc);
           if (reply == mrOk) {
             ACell = TSSForm->InfluxGrid->AbsoluteCells[ColCount][row];
             ACell->Value = conc*DT;
             ACell->Format = Format;
             }
           else if (reply == mrAbort)
             return;
           itr++;
           }
         }
       else if (Method == 1) {                         // Deposition Time provided
         int DTRow = InfluxForm->VarRow;
         for (int col=HeaderCols; col<=ColCount; col++) {
           Value = TSSForm->ConcGrid->AbsoluteCells[col][DTRow]->Value;
           if (Value.IsNull() || Value.IsEmpty()) {
             reply = MessageDlg("Null Deposition Time in column " +
                     TSSForm->ConcGrid->AbsoluteCols[col]->A1Name + ".",
                     mtInformation, TMsgDlgButtons() << mbOK << mbAbort, 0);
             if (reply == mrAbort)
               return;
             else
               continue;
             }
           DT = Value;
           if (DT == 0.0) {
             int reply = MessageDlg("Zero Deposition Time in column " +
                         TSSForm->ConcGrid->AbsoluteCols[col]->A1Name + ".",
                         mtInformation, TMsgDlgButtons() << mbOK << mbAbort, 0);
             if (reply == mrAbort)
               return;
             else
               continue;
             }
           if (m) DT *= 100.0;
           itr = InfluxRows.begin();
           while (itr != end) {
             int row = *itr;
             Value = TSSForm->ConcGrid->AbsoluteCells[col][row]->Value;
             reply = Evaluate(Value, col, row, conc);
             if (reply == mrOk) {
               ACell = TSSForm->InfluxGrid->AbsoluteCells[col][row];
               ACell->Value = conc/DT;
               ACell->Format = Format;
               }
             else if (reply == mrAbort)
               return;
             itr++;
             }
           }
         }
       }
   catch(Exception &e)
       {
	   MessageDlg("Error calculating influx. " + e.Message, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
       }
}
//---------------------------------------------------------------------------

int CalculateInflux::Evaluate(Variant& Value, int col, int row, double& count)
{
   if (Value.IsNull() || Value.IsEmpty()) {
     if (TreatNulls == SKIPNULL)
       return mrIgnore;
     else
       count = 0.0;
     }
   else if (Value.Type() == varDouble)
     count = Value;
   else {
     int result = MessageDlg("Invalid value in Cell " +
              TSSForm->ConcGrid->AbsoluteCols[col]->A1Name +
              IntToStr(row) + ".",
              mtInformation, TMsgDlgButtons() << mbIgnore << mbAbort, 0);
     if (result == mrIgnore)
       return mrIgnore;
     else if (result == mrAbort)
       return mrAbort;
     }
   return mrOk;
}
//---------------------------------------------------------------------------
