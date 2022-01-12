//---------------------------------------------------------------------------
#include <vcl.h>
#include "pch.h"

#pragma hdrstop

#include "TISpread3.h"
#ifndef TGParentH
#include "TGParent.h"
#endif
#ifndef TISpreadH
#include "TISpread.h"
#endif
#ifndef TIGlobalsH
#include "TIGlobals.h"
#endif
#ifndef TIConcH
#include "TIConc.h"
#endif
#ifndef TIUploadH
#include "TIUpload.h"
#endif
#ifndef TNLoginH
#include "TNLogin.h"
#endif
#ifndef TIAgeBasH
#include "TIAgeBas.h"
#endif
#ifndef TINewTxnH
#include "TINewTxn.h"
#endif
#ifndef TIChkHirH
#include "TIChkHir.h"
#endif
#ifndef TNTaxaH
#include "TNTaxa.h"
#endif
#ifndef TNVarModsH
#include "TNVarMods.h"
#endif
#ifndef TIQueryH
#include "TIQuery.h"
#endif

//---------------------------------------------------------------------------

#pragma package(smart_init)

void __fastcall TTilSpreadSheetForm::InsertConcSheetAction1Execute(
      TObject *Sender)
{
   ConcGrid = InsertNewWorksheet("Concentrations", 0, true);

   ConcGrid->ColCount = ProfGrid1->ColCount;
   ConcGrid->RowCount = ProfGrid1->RowCount;

   cxPageControl1->ActivePage = (TcxTabSheet*)ConcGrid->Parent;

   if (MessageDlg("Calculate concentrations?", mtConfirmation,
      TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes) {
     CalculateConc Conc(this);
     if (Conc.Run()) {
       Influx1->Enabled = true;
       ParentForm->EnableMenuItem(SS_CalcInflux, 44);
       }
     SpreadSheetChanged = true;
     }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::ConcAction1Execute(TObject *Sender)
{
   bool found = false;
   for (int i=1; i<cxPageControl1->PageCount; i++) {
     TcxTabSheet* TabSheet = cxPageControl1->Pages[i];
     if (TabSheet->Caption == "Concentrations") {
       cxPageControl1->ActivePage = TabSheet;
       ConcGrid->ResetCells();
       found = true;
       break;
       }
     }

   if (!found) {
     ConcGrid = InsertNewWorksheet("Concentrations", 0, true);
     cxPageControl1->ActivePage = (TcxTabSheet*)ConcGrid->Parent;
     }

   CalculateConc Conc(this);
   if (Conc.Run()) {
     Influx1->Enabled = true;
     ParentForm->EnableMenuItem(SS_CalcInflux, 44);
     }
   SpreadSheetChanged = true;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::InsertInfluxSheetAction1Execute(
      TObject *Sender)
{
   bool ConcExists = false;
   for (int i=1; i<cxPageControl1->PageCount; i++) {
     TcxTabSheet* TabSheet = cxPageControl1->Pages[i];
     if (TabSheet->Caption == "Concentrations") {
       ConcExists = true;
       break;
       }
     }
    if (!ConcExists) {
	  MessageDlg("Concentrations worksheet doesn't exist!", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	  return;
	  }

   InfluxGrid = InsertNewWorksheet("Influx", 0, true);
   InfluxGrid->ColCount = ConcGrid->ColCount;
   InfluxGrid->RowCount = ConcGrid->RowCount;

   cxPageControl1->ActivePage = (TcxTabSheet*)InfluxGrid->Parent;

   if (MessageDlg("Calculate influx?", mtConfirmation,
	 TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes) {
     CalculateInflux Influx(this);
     Influx.Run();
     SpreadSheetChanged = true;
     }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::InfluxAction1Execute(TObject *Sender)
{
   bool found = false;
   for (int i=1; i<cxPageControl1->PageCount; i++) {
     TcxTabSheet* TabSheet = cxPageControl1->Pages[i];
     if (TabSheet->Caption == "Concentrations") {
       found = true;
       break;
       }
     }
    if (!found) {
      MessageDlg("Concentrations worksheet doesn't exist!", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
      return;
      }

   // -------------------------
   found = false;
   for (int i=1; i<cxPageControl1->PageCount; i++) {
     TcxTabSheet* TabSheet = cxPageControl1->Pages[i];
     if (TabSheet->Caption == "Influx") {
       cxPageControl1->ActivePage = TabSheet;
       InfluxGrid->ResetCells();
       found = true;
       break;
       }
     }

   if (!found) {
     InfluxGrid = InsertNewWorksheet("Influx", 0, true);
     cxPageControl1->ActivePage = (TcxTabSheet*)InfluxGrid->Parent;
     }
   //-------------------------

   CalculateInflux Influx(this);
   Influx.Run();

   Influx1->Enabled = false;
   SpreadSheetChanged = true;
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::SetConcFluxMenuItems(bool Enable)
{
   if (Enable) {
     ParentForm->EnableMenuItem(SS_CalcConc, 43);
	 bool ConcExists = false;
	 bool InfluxExists = false;
	 for (int i=1; i<cxPageControl1->PageCount; i++) {
	   TcxTabSheet* TabSheet = cxPageControl1->Pages[i];
	   if (TabSheet->Caption == "Concentrations") {
		 Concentrations2->Enabled = false;
		 ConcExists = true;
		 }
	   if (TabSheet->Caption == "Influx") {
		 Influx1->Enabled = false;
		 InfluxExists = true;
		 }
	   }

     UnicodeString Caption = cxPageControl1->ActivePage->Caption;
     if (!ConcExists) {
       if (Caption == "Data") {
         ParentForm->EnableMenuItem(SS_CalcConc, 43);
         Concentrations2->Enabled = true;
         }
       else {
         ParentForm->DisableMenuItem(SS_CalcConc, 43);
         Concentrations2->Enabled = false;
         }
       Influx1->Enabled = false;
       ParentForm->DisableMenuItem(SS_CalcInflux, 44);
       }
     else {      // conc exists
       if (Caption == "Data" || Caption == "Concentrations") {
         ParentForm->EnableMenuItem(SS_CalcConc, 43);
         if (!InfluxExists) {
           ParentForm->EnableMenuItem(SS_CalcInflux, 44);
           Influx1->Enabled = true;
           }
         else
           ParentForm->DisableMenuItem(SS_CalcInflux, 44);
         }
       else
         ParentForm->DisableMenuItem(SS_CalcConc, 43);

       if (Caption == "Data" || Caption == "Influx")
         ParentForm->EnableMenuItem(SS_CalcInflux, 44);
       else if (Caption != "Concentrations") {
         ParentForm->DisableMenuItem(SS_CalcInflux, 44);
         Influx1->Enabled = false;
         }
       }
     }
   else {
     ParentForm->DisableMenuItem(SS_CalcConc, 43);
     ParentForm->DisableMenuItem(SS_CalcInflux, 44);
     Influx1->Enabled = false;
     Concentrations2->Enabled = false;
     }
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::InsertCONISSSheet(void)
{
   TNewCONISSSheetForm* CONISSForm = new TNewCONISSSheetForm(this);

   CONISSForm->SetGrids(ProfGrid1, ProfGrid2);
   CONISSForm->GetGroups(ProfGrid1);

   int result = CONISSForm->ShowModal();
   if (result == mrOk) {
     TStringList* GroupList = new TStringList();
     GroupList->Sorted = true;
	 for (int i=0; i<CONISSForm->cxCheckListBox1->Count; i++) {
	   TcxCheckListBoxItem* Item = CONISSForm->cxCheckListBox1->Items->Items[i];
       if (Item->Checked)
		 GroupList->Add(Item->Text);
	   }

     if (GroupList->Count == 0) {      // bail if no groups chosen
       delete GroupList;
	   delete CONISSForm;
       return;
       }

     TProfGrid* CONISSGrid = InsertNewWorksheet("CONISS", 0, false);
     SS_InsertCONISSWorksheet->Enabled = false;

	 TProfGrid* SourceGrid = CONISSForm->GetSourceGrid();
     SourceGrid->DisableControls();
     SourceGrid->SpreadsheetEnabled = false;
     CONISSGrid->DisableControls();
     CONISSGrid->SpreadsheetEnabled = false;

     CopyToCONISSSheet(CONISSForm, GroupList, SourceGrid, CONISSGrid);

     delete GroupList;
     CONISSGrid->SpreadsheetEnabled = true;
     CONISSGrid->EnableControls();
     SourceGrid->SpreadsheetEnabled = true;
     SourceGrid->EnableControls();

     bool Abort = false;
     if (CopyNumAnalErrors.Contains(1)) {
       TcxTabSheet* Sheet = (TcxTabSheet*)CONISSGrid->Parent;
       Workbook->Sheets.erase(Sheet);
       delete CONISSGrid;
       delete Sheet;
       Abort = true;
       }
     else {
       bool Errors = false;
       UnicodeString ErrorMsg = "The following errors ignored:";
       if (CopyNumAnalErrors.Contains(2)) {
         Errors = true;
         ErrorMsg += "\n-- Non-numerical values in minimum values worksheet";
         }
       if (CopyNumAnalErrors.Contains(3)) {
         Errors = true;
         ErrorMsg += "\n-- Non-numerical values in source worksheet";
         }
       if (CopyNumAnalErrors.Contains(4)) {
         Errors = true;
         ErrorMsg += "\n-- VarCode in source worksheet not found in minimum values worksheet";
         }
       if (Errors)
         MessageDlg(ErrorMsg, mtWarning, TMsgDlgButtons() << mbOK, 0);
       }
     if (!Abort) {
       int npages = 0;
       for (int i=1; i<cxPageControl1->PageCount; i++) {
         TcxTabSheet* TabSheet = cxPageControl1->Pages[i];
         if (TabSheet->Caption.SubString(1,6) == "CONISS")
           npages++;
         }
       if (npages > 1) {
         int npage = 1;
         for (int i=1; i<cxPageControl1->PageCount; i++) {
           TcxTabSheet* TabSheet = cxPageControl1->Pages[i];
           if (TabSheet->Caption.SubString(1,6) == "CONISS")
             TabSheet->Caption = "CONISS" + IntToStr(npage++);
           }
         }
       SpreadSheetChanged = true;
       }
     }

   delete CONISSForm;
}
//---------------------------------------------------------------------------

bool TTilSpreadSheetForm::CopyToCONISSSheet(TNewCONISSSheetForm* CONISSForm,
     TStringList* GroupList, TProfGrid* SourceGrid, TProfGrid* CONISSGrid)
{
   // Error Codes:
   // 1 - Abort
   // 2 - Double validation error ignored in MinValGrid (different from SourceGrid)
   // 3 - Double validation error ignored in SourceGrid
   // 4 - VarCode in SourceGrid not found in MinValGrid
   CopyNumAnalErrors.Clear();
   double dVal;

   int ColCount = AbsContentColCount(SourceGrid);
   int HeaderCols = AbsHeaderColCount(SourceGrid);
   int HeaderRows = AbsHeaderRowCount(SourceGrid);

   CONISSGrid->ColCount = SourceGrid->ColCount;
   CONISSGrid->RowCount = SourceGrid->RowCount;

   // write header rows
   for (int row=1; row<=HeaderRows; row++) {
	 for (int col=HeaderCols; col<=ColCount; col++)
	   CONISSGrid->AbsoluteCells[col][row]->Value = SourceGrid->AbsoluteCells[col][row]->Value;
     }
   // write header cols and data
   int RowCount = AbsContentRowCount(SourceGrid);
   int NewRow = HeaderRows;
   int Index;

   // setup for getting rows with values greater than the Minimum Value
   int MinimumValues = CONISSForm->GetMinimumValues();
   double MinValue = CONISSForm->GetMinValue();
   TProfGrid* MinValGrid = NULL;
   if (MinimumValues == MV_DATA)
     MinValGrid = ProfGrid1;
   else if (MinimumValues == MV_PERCENTS)
     MinValGrid = ProfGrid2;

   map<UnicodeString, bool> MinValRows;
   int MinValStatus = mrOk;
   if (MinValGrid) {
     if (MinValGrid != SourceGrid) {
       int nrows = AbsContentRowCount(MinValGrid);
       int ncols = AbsContentColCount(MinValGrid);
       for (int row=HeaderRows; row<=nrows; row++) {
         UnicodeString VarCode = MinValGrid->AbsoluteCells[1][row]->Value;
		 if (SameText(VarCode.SubString(1,1), L"#")) continue;
		 if (SameText(VarCode.SubString(1,3), L"SUM")) continue;
		 if (SameText(VarCode.SubString(1,4), L"SSUM")) continue;
		 bool gtMinVal = false;
         for (int col=HeaderCols; col<=ncols; col++) {
           if (ValidateCellDouble(MinValGrid->AbsoluteCells[col][row], MinValStatus, dVal)) {
             if (dVal >= MinValue) {
               gtMinVal = true;
               break;
               }
             }
           else {   // not a valid double value
             if (MinValStatus == mrAbort) {
               CopyNumAnalErrors << 1;
               return false;
               }
             else if (MinValStatus == mrIgnore)
               CopyNumAnalErrors << 2;
             }
           }
         MinValRows[VarCode] = gtMinVal;
         }
       }
     }

   int SourceValStatus = mrOk;
   for (int row=HeaderRows; row<=RowCount; row++) {
     UnicodeString VarCode = SourceGrid->AbsoluteCells[1][row]->Value;
	 if (SameText(VarCode.SubString(1,1), L"#")) continue;
	 if (SameText(VarCode.SubString(1,3), L"SUM")) continue;
     if (SameText(VarCode.SubString(1,4), L"SSUM")) continue;
     UnicodeString GroupCode = SourceGrid->AbsoluteCells[7][row]->Value;
     if (GroupList->Find(GroupCode, Index)) {  // row has included group code
       // check that MinValGrid contains all VarCodes in Source Grid
       bool go = true;
       if (MinValGrid) {     // check if minimum value needs to be checked
         if (MinValGrid == SourceGrid) {
           go = false;
           for (int col=HeaderCols; col<=ColCount; col++) {
             if (ValidateCellDouble(SourceGrid->AbsoluteCells[col][row], SourceValStatus, dVal)) {
               if (dVal >= MinValue) {
                 go = true;
                 break;
                 }
               }
             else {      // not a valid double value
               if (SourceValStatus == mrAbort) {
                 CopyNumAnalErrors << 1;
                 return false;
                 }
               else if (SourceValStatus == mrIgnore)
                 CopyNumAnalErrors << 3;
               }
             }
           }
         else {   // MinValGrid different from SourceGrid
           if (MinValRows.find(VarCode) != MinValRows.end())    // VarCode found in MinValGrid
             go = MinValRows[VarCode];
           else {
             // VarCode not found in MinValGrid
			 UnicodeString SourceTabSheet;
             UnicodeString MinValTabSheet;
             if (SourceGrid == ProfGrid1) {
               SourceTabSheet = "Data";
               MinValTabSheet = "Percents";
               }
             else {
               SourceTabSheet = "Percents";
               MinValTabSheet = "Data";
               }
             int rv = MessageDlg( "Variable code \"" + VarCode +
                      "\" in source grid " + SourceTabSheet +
                      " not fouund in minimum values grid " + MinValTabSheet + ".",
                      mtWarning, TMsgDlgButtons() << mbIgnore << mbAbort, 0);
             if (rv == mrAbort) {
               CopyNumAnalErrors << 1;
               return false;
               }
             else
               CopyNumAnalErrors << 4;
             }
           }
         }
       if (go) {
         for (int col=1; col<=ColCount; col++) {
           if (col < HeaderCols)
             CONISSGrid->AbsoluteCells[col][NewRow]->Value = SourceGrid->AbsoluteCells[col][row]->Value;
           else if (ValidateCellDouble(SourceGrid->AbsoluteCells[col][row], SourceValStatus, dVal))
             CONISSGrid->AbsoluteCells[col][NewRow]->Value = SourceGrid->AbsoluteCells[col][row]->Value;
           else {  // not a double
             if (SourceValStatus == mrAbort) {
               CopyNumAnalErrors << 1;
               return false;
               }
             else if (SourceValStatus == mrIgnore)
               CopyNumAnalErrors << 3;
             }
           }
         NewRow++;
         }
       }
     }
   return true;
}
//---------------------------------------------------------------------------

bool TTilSpreadSheetForm::ValidateCellDouble(TProfGridCell* Cell, int& Status, double& dVal)
{
   Variant Value = Cell->Value;
   if (Value.Type() == varDouble) {
	 dVal = Cell->Value;
	 return true;
	 }
   else {
	 UnicodeString GridName = (Cell->Grid == ProfGrid1) ? "Data" : "Percents";
     Status = MessageDlg("Value \"" + Value + "\" in " + GridName +
              " worksheet, cell " + Cell->A1Name +
              " is not a valid numerical value.",
              mtWarning, TMsgDlgButtons() << mbIgnore << mbAbort, 0);
     return false;
     }
}
//---------------------------------------------------------------------------

TProfGrid* TTilSpreadSheetForm::InsertNewWorksheet(UnicodeString Caption, int PageIndex, bool MakeActive)
{
   TcxTabSheet* NewPage = new TcxTabSheet(cxPageControl1->Owner);
   NewPage->PageControl = cxPageControl1;
   NewPage->Caption = Caption;
   TProfGrid* ProfGrid = new TProfGrid(this);
   NewPage->InsertControl(ProfGrid);

   ProfGrid->Align = alClient;
   ProfGrid->ColCount = 256;
   ProfGrid->RowCount = 1024;
   ProfGrid->FixedCols = 8;
   ProfGrid->FixedRows = 3;
   ProfGrid->DefaultColWidth = 64;
   ProfGrid->DefaultRowHeight = 18;
   ProfGrid->EditControlOptions << ecoMakeFlat;         // true
   ProfGrid->Ctl3D = false;
   ProfGrid->EndEllipsis = true;

   TProfGridEditorOptions MyEditorOptions;
   MyEditorOptions << eoAutoIncreaseRowHeight;
   MyEditorOptions << eoShowOnChar;
   MyEditorOptions << eoClearOnChar;
   MyEditorOptions << eoCursorAtEnd;
   MyEditorOptions << eoAllowPaste;
   MyEditorOptions << eoPreserveInnerBorders;
   ProfGrid->EditorOptions = MyEditorOptions;

   ProfGrid->Font->Height = -12;
   ProfGrid->Font->Size = 9;
   ProfGrid->FixedColor = clBtnFace;
   ProfGrid->FixedGridLineColor = clGray;
   ProfGrid->GridLineColor = clSilver;
   ProfGrid->ScrollBars = ssBoth;
   ProfGrid->SelectionColor = (TColor)0x00EACAB6;
   ProfGrid->SelectionFontColor = clWindowText;
   ProfGrid->SpreadsheetStyle = ssExcelXP;

   TProfGridOptions MyOptions;
   MyOptions << pgoFixedVertLine;
   MyOptions << pgoFixedHorzLine;
   MyOptions << pgoVertLine;
   MyOptions << pgoHorzLine;
   MyOptions << pgoRangeSelect;
   MyOptions << pgoRowSizing;
   MyOptions << pgoColSizing;
   MyOptions << pgoEditing;
   MyOptions << pgoTabs;
   MyOptions << pgoAutoIncreaseRowHeights;
   MyOptions << pgoDrawFocusRectangle;
   MyOptions << pgoMultiLineCells;
   MyOptions << pgoSelectFixedCols;
   MyOptions << pgoSelectFixedRows;
   MyOptions << pgoClearCellOnDel;
   MyOptions << pgoCut;
   MyOptions << pgoCopy;
   MyOptions << pgoPaste;
   MyOptions << pgoAddColsOnPaste;
   MyOptions << pgoAddRowsOnPaste;
   MyOptions << pgoFreeCellObjects;
   ProfGrid->Options = MyOptions;

   ProfGrid->ParentCtl3D = false;
   ProfGrid->SpreadsheetEnabled = true;
   ProfGrid->SpreadsheetHeaders = true;

   TProfGridSpreadsheetOptions MySpreadsheetOptions;
   MySpreadsheetOptions << soExcelStyleHeadings;
   MySpreadsheetOptions << soExcelStyleHeadingHighlight;
   MySpreadsheetOptions << soExcelStyleSelection;
   MySpreadsheetOptions << soExcelStyleNavigation;
   MySpreadsheetOptions << soExcelStyleComments;
   MySpreadsheetOptions << soColRowHeadingClickSelect;
   //MySpreadsheetOptions << soMouseBuildUpFormula;  // this crashes vcl60
   ProfGrid->SpreadsheetOptions = MySpreadsheetOptions;

   ProfGrid->WordWrap = false;
   ProfGrid->ColWidths[0] = 35;

   FormatWorksheet(ProfGrid);
   Workbook->Sheets[NewPage] = ProfGrid;
   if (PageIndex)
     NewPage->PageIndex = PageIndex;
   if (MakeActive)
     cxPageControl1->ActivePage = NewPage;

   ProfGrid->OnKeyDown = ProfGridKeyDown;
   ProfGrid->OnCellChanged = ProfGridCellChanged;
   ProfGrid->OnClearCell = ProfGridClearCell;
   ProfGrid->OnCellCleared = ProfGridCellCleared;
   ProfGrid->OnPaste = ProfGridPaste;
   ProfGrid->OnCutCell = ProfGridCutCell;

   return ProfGrid;
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::DeleteSheet(void)
{
   UnicodeString Caption = cxPageControl1->ActivePage->Caption;
   if (MessageDlg("Delete " + Caption + " worksheeet? Action cannot be undone.", mtConfirmation,
       TMsgDlgButtons() << mbYes << mbNo, 0) == mrNo) return;

   TcxTabSheet* Sheet = cxPageControl1->ActivePage;
   UnicodeString DeletedSheetCaption = Sheet->Caption;
   TProfGrid* ProfGrid = Workbook->Sheets[Sheet];

   // remove any undo's in deleted sheet
   list<UNDO>::iterator itr = UnDo.begin();
   while (itr != UnDo.end()) {
     UNDO undo = *itr;
     if (ProfGrid == undo.ProfGrid)
       itr = UnDo.erase(itr);
     else
       itr++;
     }

   Workbook->Sheets.erase(Sheet);
   delete ProfGrid;
   if (Caption == "Percents")
     ProfGrid2 = NULL;
   else if (Caption == "Concentrations") {
     ConcGrid = NULL;
     Influx1->Enabled = false;
     ParentForm->DisableMenuItem(SS_CalcInflux, 44);
     }
   else if (Caption == "Influx")
     InfluxGrid = NULL;

   delete Sheet;

   if (DeletedSheetCaption.SubString(1,6) == "CONISS" && DeletedSheetCaption.Length() > 6) {
     int npages = 0;
     for (int i=2; i<cxPageControl1->PageCount; i++) {
       TcxTabSheet* TabSheet = cxPageControl1->Pages[i];
       if (TabSheet->Caption.SubString(1,6) == "CONISS")
         npages++;
       }
     if (npages == 1) {
       for (int i=2; i<cxPageControl1->PageCount; i++) {
         TcxTabSheet* TabSheet = cxPageControl1->Pages[i];
         if (TabSheet->Caption.SubString(1,6) == "CONISS") {
           TabSheet->Caption = "CONISS";
           break;
           }
         }
       }
     else if (npages > 1) {
       int npage = 1;
       for (int i=2; i<cxPageControl1->PageCount; i++) {
         TcxTabSheet* TabSheet = cxPageControl1->Pages[i];
         if (TabSheet->Caption.SubString(1,6) == "CONISS")
           TabSheet->Caption = "CONISS" + IntToStr(npage++);
         }
       }
     SS_InsertCONISSWorksheet->Enabled = true;
     }
   else if (Caption == "CONISS")
     SS_InsertCONISSWorksheet->Enabled = true;
   else if (Caption == "Concentrations")
     Concentrations2->Enabled = true;
   SpreadSheetChanged = true;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::AdvControlDropDown4BeforeDropDown(TObject *Sender)
{
   AdvColumnGrid1->Top = 0;
   AdvColumnGrid1->Height = Panel7->Height - 3;
   //set<UnicodeString>* TaxaGroups = tiGlobals->GetTaxaGroups();
   set<UnicodeString> TaxaGroups = tiGlobals->TaxaGroups;

   // now get TaxaGroup for current taxon
   if (TaxaLookupOpen) {
	 TAXON Taxon;
	 int ARow = ProfGrid1->Row;
	 UnicodeString TaxonName = ProfGrid1->AbsoluteCells[2][ARow]->Text;
	 if (!TaxonName.IsEmpty()) {
	   UnicodeString TaxaGroupCode;
	   if (GetTaxon(ARow, Taxon)) {
		 TaxaGroupCode = Taxon.TaxaGroup;
		 UnicodeString TaxaGroupName;
		 for (unsigned int i=0; i<TaxaEcolGroups.size(); i++) {
		   if (SameText(TaxaGroupCode, TaxaEcolGroups[i].TaxaGroup.Code)) {
			 TaxaGroupName = TaxaEcolGroups[i].TaxaGroup.Name.LowerCase();
			 break;
			 }
		   }
		 if (!TaxaGroupName.IsEmpty()) {
		   if (TaxaGroups.find(TaxaGroupName) == TaxaGroups.end()) {
			 TaxaGroups.insert(TaxaGroupName);
             tiGlobals->TaxaGroups = TaxaGroups;
			 }
		   }
		 }
	   }
	 }
   sort(TaxaEcolGroups.begin(), TaxaEcolGroups.end(), TaxaGroupNameComp);
   set<UnicodeString>::iterator end = TaxaGroups.end();
   cxCheckComboBox8->Properties->Items->BeginUpdate();
   cxCheckComboBox8->Properties->Items->Clear();
   for (unsigned int i=0; i<TaxaEcolGroups.size(); i++) {
	 UnicodeString Name = TaxaEcolGroups[i].TaxaGroup.Name.LowerCase();
	 TcxCheckComboBoxItem* Item = cxCheckComboBox8->Properties->Items->AddCheckItem
		(Name, TaxaEcolGroups[i].TaxaGroup.Code);
	 if (TaxaGroups.find(Name) != end) {
	   cxCheckComboBox8->States[Item->Index] = cbsChecked;
	   }
	 }
   cxCheckComboBox8->Properties->Items->EndUpdate();
   FillEcolGroupsGrid(&TaxaGroups);
   SetEcolGroupsGridRow();

}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::SetEcolGroupsGridRow(void)
{
   int CurrentRow = -1;
   for (int row=0; row<AdvColumnGrid1->RowCount; row++) {
	 if (SameText(AdvColumnGrid1->Cells[0][row], AdvControlDropDown4->Text)) {
	   CurrentRow = row;
	   break;
	   }
	 }
   AdvColumnGrid1->Row = (CurrentRow > -1) ? CurrentRow : 0;
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::FillEcolGroupsGrid(set<UnicodeString>* TaxaGroups)
{
   set<UnicodeString>::iterator begin = TaxaGroups->begin();
   set<UnicodeString>::iterator end = TaxaGroups->end();
   set<UnicodeString>::iterator itr;
   vector<CODENAME> EcolGroups;
   for (itr = begin; itr != end; itr++) {
	 for (unsigned int i=0; i<TaxaEcolGroups.size(); i++) {
	   if (SameText(*itr, TaxaEcolGroups[i].TaxaGroup.Name)) {
		 for (unsigned int j=0; j<TaxaEcolGroups[i].EcolGroups.size(); j++) {
		   UnicodeString Code = TaxaEcolGroups[i].EcolGroups[j].Code;
		   bool found = false;
		   unsigned int k = 0;
		   while (!found && k<EcolGroups.size())
			 found = SameText(Code, EcolGroups[k++].Code);
		   if (!found)
			 EcolGroups.push_back(TaxaEcolGroups[i].EcolGroups[j]);
		   }
		 break;
		 }
	   }
	 }
   AdvColumnGrid1->BeginUpdate();
   AdvColumnGrid1->Clear();
   AdvColumnGrid1->RowCount = EcolGroups.size();
   for (unsigned int row=0; row<EcolGroups.size(); row++) {
	 AdvColumnGrid1->Cells[0][row] = EcolGroups[row].Code;
	 AdvColumnGrid1->Cells[1][row] = EcolGroups[row].Name;
	 }
   AdvColumnGrid1->QSort();
   AdvColumnGrid1->EndUpdate();
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::AdvControlDropDown4DropDownHeaderButtonClick(TObject *Sender,
		  int ButtonIndex)
{
   if (cxCheckComboBox8->Visible) {
	 cxCheckComboBox8->Visible = false;
	 AdvColumnGrid1->Top = 0;
	 AdvColumnGrid1->Height = Panel7->Height - 3;
	 }
   else {
	 cxCheckComboBox8->Visible = true;
	 AdvColumnGrid1->Height = Panel7->Height - 25;
	 AdvColumnGrid1->Top = 22;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::AdvControlDropDown4DropDownFooterButtonClick(TObject *Sender,
		  int ButtonIndex)
{
   if (ButtonIndex == 0)   // Ok button
	 AdvControlDropDown4->Text = AdvColumnGrid1->Cells[0][AdvColumnGrid1->Row];
   ProfGrid1->EditorMode = false;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::AdvColumnGrid1DblClick(TObject *Sender)
{
   AdvControlDropDown4->Text = AdvColumnGrid1->Cells[0][AdvColumnGrid1->Row];
   AdvControlDropDown4->HideDropDown(false);
   ProfGrid1->EditorMode = false;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::AdvControlDropDown4Exit(TObject *Sender)
{
   ProfGrid1->RowHeights[ProfGrid1->Row] = CurrentRowHeight;
}
//---------------------------------------------------------------------------

int TTilSpreadSheetForm::GetCurrentDataset(int ARow)
{
   int DatasetIdx = 0;

   if (Datasets.size() > 1) {  // if more than one DatasetType
	 for (int row=ARow; row>=3; row--) {
	   UnicodeString Code = ProfGrid1->AbsoluteCells[1][row]->Text;
	   if (SameText(Code, L"#Data.Type")) {
		 UnicodeString DatasetType = ProfGrid1->AbsoluteCells[2][row]->Text;
		 for (unsigned int i=0; i<Datasets.size(); i++) {
		   if (SameText(DatasetType, Datasets[i].DatasetType)) {
			 DatasetIdx = i;
			 break;
			 }
		   }
		 break;
		 }
	   }
	 }
   return DatasetIdx;
}
//---------------------------------------------------------------------------

int TTilSpreadSheetForm::GetCurrentDatasetHeaderRow(int ARow)
{
   int DatasetRow = 1;
   if (Datasets.size() > 1) {  // if more than one DatasetType
	 for (int row=ARow; row>=3; row--) {
	   UnicodeString Code = ProfGrid1->AbsoluteCells[1][row]->Text;
	   if (SameText(Code, L"#Data.Type")) {
		 DatasetRow = row;
		 break;
		 }
	   }
	 }
   return DatasetRow;
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::GetDatasetRows(int DatasetNo, pair<int,int>& DatasetRows)
{
   int RowCount = AbsContentRowCount(ProfGrid1);
   if (Datasets.size() == 1) {
	 DatasetRows.first = 3;
	 DatasetRows.second = RowCount;
	 }
   else {
	 UnicodeString DatasetType = Datasets[DatasetNo].DatasetType;
	 int TopRow = 1;
	 for (int row=3; row<=RowCount; row++) {
	   UnicodeString Code = ProfGrid1->AbsoluteCells[1][row]->Text;
	   if (SameText(Code, L"#Data.Type")) {
		 UnicodeString CurDatasetType = ProfGrid1->AbsoluteCells[2][row]->Text;
		 if (SameText(CurDatasetType,DatasetType)) {
		   TopRow = row;
		   break;
		   }
		 }
	   }
	 DatasetRows.first = TopRow;
	 int BottomRow = TopRow;
	 for (int row=TopRow+1; row<=RowCount; row++) {
	   UnicodeString Code = ProfGrid1->AbsoluteCells[1][row]->Text;
	   if (SameText(Code, L"#Data.Type"))
		 break;
	   else
		 BottomRow++;
	   }
	 DatasetRows.second = BottomRow;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxGrid3TableView1NavigatorButtonsButtonClick(TObject *Sender,
		  int AButtonIndex, bool &ADone)
{
   UnicodeString msg;

   if (AButtonIndex == NBDI_DELETE) {  // delete record button
	 if (tiLicense->Type() == verNEOTOMASTEWARD) {
	   int RecordIndex1 = cxGrid3TableView1->DataController->FocusedRecordIndex;
	   AGEMODEL* AgeModel = AgeModelList->AgeModels[RecordIndex1];
	   if (AgeModel->NeotomaChronologyID > -1) {  // a downloaded dataset
		 UnicodeString msg = L"Delete chronology " + IntToStr(AgeModel->NeotomaChronologyID) +
		   L" «" + AgeModel->ChronologyName + L"» from Neotoma?";
		 int rv = MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo << mbCancel, 0);
		 if (rv == mrYes)
		   DeleteNeotomaChron(AgeModel->ChronNumber, AgeModel->NeotomaChronologyID, AgeModel->ChronologyName);
		 else if (rv == mrCancel)
		   ADone = true;
		 }
	   }
	 }
   else if (AButtonIndex == NavigatorButtonCount) { // upload new chronology
	 if (!Login->IsLoggedIn) {
	   NeotomaLoginForm = new TNeotomaLoginForm(this);
	   NeotomaLoginForm->ShowModal();
	   delete NeotomaLoginForm;
	   }
	 if (Login->IsLoggedIn) {
	   int RecordIndex1 = cxGrid3TableView1->DataController->FocusedRecordIndex;
	   AGEMODEL* AgeModel = AgeModelList->AgeModels[RecordIndex1];
	   NeotomaUploadChronForm = new TNeotomaUploadChronForm(AgeModel, this);
	   NeotomaUploadChronForm->ShowModal();
	   // bool aborted = NeotomaUploadChronForm->validation_aborted;
	   int chron_row = NeotomaUploadChronForm->ChronRow;
	   int chron_row_young = NeotomaUploadChronForm->ChronRowYoung;
	   int chron_row_old = NeotomaUploadChronForm->ChronRowOld;
	   bool success = NeotomaUploadChronForm->upload_success;
	   delete NeotomaUploadChronForm;

	   if (success) {
		 cxGrid3TableView1->NavigatorButtons->CustomButtons->Items[0]->Visible = false;
		 // ProfGrid1->AbsoluteCells[ACol][ARow]->Color = TColor(0x00B4E0C6);  // light green
		 int ColCount = AbsContentColCount(ProfGrid1);
		 int HeaderCols = AbsHeaderColCount(ProfGrid1);
		 if (chron_row > 0) {
		   for (int col=HeaderCols; col<=ColCount; col++)
			 ProfGrid1->AbsoluteCells[col][chron_row]->Color = TColor(0x00B4E0C6);  // light green
		   }
		 if (chron_row_young > 0) {
		   for (int col=HeaderCols; col<=ColCount; col++)
			 ProfGrid1->AbsoluteCells[col][chron_row_young]->Color = TColor(0x00B4E0C6);  // light green
		   }
		 if (chron_row_old > 0) {
		   for (int col=HeaderCols; col<=ColCount; col++)
			 ProfGrid1->AbsoluteCells[col][chron_row_old]->Color = TColor(0x00B4E0C6);  // light green
		   }
		 }
	   }
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxGrid3TableView2DataControllerBeforeDelete(TcxCustomDataController *ADataController,
		  int ARecordIndex)
{
   if (tiLicense->Type() == verNEOTOMASTEWARD) {  // delete record button
     int RecordIndex1 = cxGrid3TableView1->DataController->FocusedRecordIndex;
	 AGEMODEL* AgeModel = AgeModelList->AgeModels[RecordIndex1];
	 if (AgeModel->NeotomaChronologyID != -1) {
	   CHRON* ChronControl = (CHRON*)AgeModel->ChronControls->Items[ARecordIndex];
	   DeleteChronControl(ChronControl->NeotomaChronControlID);
	   }
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxGrid3TableView1FocusedRecordChanged(TcxCustomGridTableView *Sender,
		  TcxCustomGridRecord *APrevFocusedRecord, TcxCustomGridRecord *AFocusedRecord,
		  bool ANewItemRecordFocusingChanged)
{
   if (AFocusedRecord == NULL || AFocusedRecord->IsNewItemRecord) {
	 cxGrid3TableView1->NavigatorButtons->CustomButtons->Items[0]->Visible = false;
	 return;
	 }

   if (tiLicense->Type() == verNEOTOMASTEWARD) {
	 bool amdownloaded = false;
	 for (unsigned int i = 0; i < Datasets.size(); i++) {
	   if (Datasets[i].NeotomaDatasetID > -1) {
		 amdownloaded = true;
		 break;
		 }
	   }
	 if (amdownloaded) {
	   AGEMODEL* AgeModel = AgeModelList->AgeModels[AFocusedRecord->RecordIndex];
	   cxGrid3TableView1->NavigatorButtons->CustomButtons->Items[0]->Visible = (AgeModel->NeotomaChronologyID == -1);
	   }
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxTreeView1Click(TObject *Sender)
{
   TTreeNode* Node = cxTreeView1->Selected;
   if (Node) {
	 ExpandArchTimeScale();
	 AgeBasis.Text = Node->Text;
	 AgeBasis.SetAges(cxTreeView1);
	 }
   else
	 AgeBasis.Text.SetLength(0);

   if (cxTreeView1CanSelect)
	 chAgeBasisPopupEdit->DroppedDown = false;
   else
	 cxTreeView1CanSelect = true;
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::ExpandArchTimeScale(void)
{
   if (cxTreeView1->Selected->Text.Pos("archaeological time scale")) {
	 if (!cxTreeView1->Selected->HasChildren) {
	   UnicodeString msg = "Expand " + cxTreeView1->Selected->Text + "?";
	   if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes) {
		 for (int i=0; i<ArchAges->Count; i++) {
		   RELATIVEAGE* ArchAge = (RELATIVEAGE*)ArchAges->Objects[i];
		   if (SameText(ArchAgeScales->Strings[ArchAge->ArchAgeScaleID], cxTreeView1->Selected->Text))
			 cxTreeView1->Items->AddChildObject(cxTreeView1->Selected, ArchAges->Strings[i], ArchAge);
		   }
		 cxTreeView1CanSelect = false;
		 }
	   }
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxTreeView1KeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
   if (Key == VK_RETURN) {
	 AgeBasis.Text = cxTreeView1->Selected->Text;
	 chAgeBasisPopupEdit->DroppedDown = false;
	 }
   else if (Key == VK_ESCAPE) {
	 chAgeBasisPopupEdit->DroppedDown = false;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxTreeView1Expanded(TObject *Sender,
      TTreeNode *Node)
{
   cxTreeView1CanSelect = false;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxTreeView1Collapsed(TObject *Sender,
	  TTreeNode *Node)
{
   cxTreeView1CanSelect = false;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxGrid3TableView2FocusedRecordChanged(
      TcxCustomGridTableView *Sender,
      TcxCustomGridRecord *APrevFocusedRecord,
	  TcxCustomGridRecord *AFocusedRecord,
      bool ANewItemRecordFocusingChanged)
{
   if (!AFocusedRecord) return;  // new

   Sender->DataController->Post();
   CurrentChronControlView = Sender;

   if (Downloaded && tiLicense->Type() == verNEOTOMASTEWARD) {
	 // instantiate a chron control containing the initial state before any editing
	 int RecordIndex1 = cxGrid3TableView1->DataController->FocusedRecordIndex;
	 int RecordIndex2 = AFocusedRecord->RecordIndex;

	 AGEMODEL* AgeModel = AgeModelList->AgeModels[RecordIndex1];
	 CHRON* ChronControl = (CHRON*)AgeModel->ChronControls->Items[RecordIndex2];

	 if (InitChronControl != NULL)
	   delete InitChronControl;
	 InitChronControl = new CHRON(ChronControl);
	 }

   if (EditAgeBasisList > -1)
	 Sender->DataController->FocusedRecordIndex = EditAgeBasisList;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxGrid3TableView2FocusedItemChanged(
      TcxCustomGridTableView *Sender,
      TcxCustomGridTableItem *APrevFocusedItem,
      TcxCustomGridTableItem *AFocusedItem)
{
   if (EditAgeBasisList > -1) {
	 Sender->Controller->FocusedItemIndex = chAgeBasis->Index;
     EditAgeBasisList = -2;
     }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxGrid3TableView2InitEdit(
      TcxCustomGridTableView *Sender, TcxCustomGridTableItem *AItem,
      TcxCustomEdit *AEdit)
{
   CheckBox2->Visible = false;
   cxButton11->Visible = true;
   cxButton19->Visible = true;
   cxButton20->Visible = true;
   CurrentChronControlView = Sender;
   if (EditAgeBasisList == -2) {
     EditAgeBasisList = -1;
     TcxPopupEdit* PopupEdit = (TcxPopupEdit*)AEdit;
     PopupEdit->DroppedDown = true;
     }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxGrid3TableView1InitEdit(TcxCustomGridTableView *Sender,
		  TcxCustomGridTableItem *AItem, TcxCustomEdit *AEdit)

{
   CheckBox2->Visible = true;
   cxButton11->Visible = false;
   cxButton19->Visible = false;
   cxButton20->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::chAgeBasisPropertiesPopup(
      TObject *Sender)
{
   AgeBasis.Text = ((TcxPopupEdit*)Sender)->Text;
   cxTreeView1->ClearSelection();
   for (int i=0; i<cxTreeView1->Items->Count; i++) {
	 TTreeNode *Node = cxTreeView1->Items->Item[i];
	 if (SameText(Node->Text, AgeBasis.Text)) {
	   cxTreeView1->Select(Node);
	   break;
	   }
	 }

   chAgeBasisPopupEdit = (TcxPopupEdit*)Sender;
   cxTreeView1CanSelect = true;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::chAgeBasisPropertiesCloseUp(
      TObject *Sender)
{
   // this function called when selection is made from drop down

   if (InitChronControl != NULL)
     if (AgeBasis.Text == InitChronControl->ControlType) return;

   int FocusedRecordIndex = CurrentChronControlView->DataController->FocusedRecordIndex;

   CurrentChronControlView->DataController->BeginUpdate();
   CurrentChronControlView->DataController->Values[FocusedRecordIndex][IndexOfchAgeBasis] = AgeBasis.Text;

   UnicodeString age = VarToStr(CurrentChronControlView->DataController->GetEditValue(chAge->Index, evsText));
   UnicodeString age_older = VarToStr(CurrentChronControlView->DataController->GetEditValue(chOlderLimit->Index, evsText));
   UnicodeString age_younger = VarToStr(CurrentChronControlView->DataController->GetEditValue(chYoungerLimit->Index, evsText));
   UnicodeString age_units = VarToStr(CurrentChronControlView->DataController->GetEditValue(chAgeUnits->Index, evsText));
   if (SameText(age_units,L"Calendar")) {
	 if (age.IsEmpty() && !IsNan(AgeBasis.CalAge))
	   CurrentChronControlView->DataController->SetEditValue(chAge->Index, AgeBasis.CalAge, evsValue);
	 if (age_older.IsEmpty() && !IsNan(AgeBasis.CalAgeOlder))
	   CurrentChronControlView->DataController->SetEditValue(chOlderLimit->Index, AgeBasis.CalAgeOlder, evsValue);
	 if (age_younger.IsEmpty() && !IsNan(AgeBasis.CalAgeYounger))
	   CurrentChronControlView->DataController->SetEditValue(chYoungerLimit->Index, AgeBasis.CalAgeYounger, evsValue);
	 }
   else if (SameText(age_units,L"Radiocarbon")) {
	 if (age.IsEmpty() && !IsNan(AgeBasis.C14Age))
	   CurrentChronControlView->DataController->SetEditValue(chAge->Index, AgeBasis.C14Age, evsValue);
	 if (age_older.IsEmpty() && !IsNan(AgeBasis.C14AgeOlder))
	   CurrentChronControlView->DataController->SetEditValue(chOlderLimit->Index, AgeBasis.C14AgeOlder, evsValue);
	 if (age_younger.IsEmpty() && !IsNan(AgeBasis.C14AgeYounger))
	   CurrentChronControlView->DataController->SetEditValue(chYoungerLimit->Index, AgeBasis.C14AgeYounger, evsValue);
	 }

   CurrentChronControlView->DataController->EndUpdate();

   EditAgeBasisList = -1;
   if (AgeBasisListChanged) {
     if (MessageDlg("Save changes to lookup file?", mtConfirmation,
		 TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes)
	   SaveLookupFile();
	 AgeBasisListChanged = false;
	 }

   UpdateNeotomaAgeBasis(true);
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::chAgeBasisPropertiesEditValueChanged(
      TObject *Sender)
{
   // this function called when age basis is typed in, not selected from dropdown
   AgeBasis.Text = ((TcxPopupEdit*)Sender)->Text;

   if (AgeBasis.Text.IsEmpty()) return;

   bool found = false;

   int Count = cxTreeView1->Items->Count;
   if (Count == 0) return;

   for (int i=0; i<Count; i++)
	 if (SameText(AgeBasis.Text, cxTreeView1->Items->Item[i]->Text)) {
	   found = true;
	   break;
	   }
   if (!found) {
     if (MessageDlg("Add \"" + AgeBasis.Text + "\" to lookup list?",
		 mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes)
       {
	   TTreeNode *FirstNode = cxTreeView1->Items->GetFirstNode();
	   cxTreeView1->Items->AddFirst(FirstNode, AgeBasis.Text);
	   EditAgeBasisList = CurrentChronControlView->DataController->FocusedRecordIndex;
	   MessageDlg("\"" + AgeBasis.Text + "\" added to top of lookup list." +
                   "\n Drag and drop item to proper position while holding down the Control key.",
                   mtInformation, TMsgDlgButtons() << mbOK, 0);
       }
     }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::PopupMenu8Popup(TObject *Sender)
{
   TComponent *pComponent = PopupMenu8->PopupComponent;
   if (pComponent) {
	 if (SameText(pComponent->Name, L"cxTreeView1"))
	   CurrentNode = cxTreeView1->Selected;
	 }
   else
	 CurrentNode = NULL;
}
//---------------------------------------------------------------------------

// edit AgeBasis node
void __fastcall TTilSpreadSheetForm::EditControl1Click(TObject *Sender)
{
   if (CurrentNode) {
	 if (cxTreeView1->Items == CurrentNode->Owner)
	   EditChronControl(CurrentNode, L"Edit Chronology Control");
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::AddChildControl1Click(TObject *Sender)
{
   if (CurrentNode) {
	 if (cxTreeView1->Items == CurrentNode->Owner)
	   EditChronControl(cxTreeView1->Items->AddChild(CurrentNode, ""), L"Add Child Control");
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::AddSiblingControl1Click(
	  TObject *Sender)
{
   // adds node above current one
   if (CurrentNode) {
	 if (cxTreeView1->Items == CurrentNode->Owner)
	   EditChronControl(cxTreeView1->Items->InsertObject(CurrentNode, "", NULL), L"Add Sibling Control");
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::DeleteControl1Click(TObject *Sender)
{
   if (CurrentNode) {
	 if (cxTreeView1->Items == CurrentNode->Owner) {
	   if (CurrentNode->Data) {
		 UnicodeString clName = ((TObject*)CurrentNode->Data)->ClassName();
		 if (SameText(clName, L"RELATIVEAGE")) {
		   RELATIVEAGE* Item = (RELATIVEAGE*)CurrentNode->Data;
		   RelativeAges->Remove(Item);
		   delete Item;
		   }
		 else if (SameText(clName, L"EVENT")) {
		   EVENT* Item = (EVENT*)CurrentNode->Data;
		   Events->Remove(Item);
		   delete Item;
		   }
		 CurrentNode->Data = NULL;
		 }

	   TTreeNode* PrevNode = CurrentNode->GetPrev();
	   cxTreeView1->Items->Delete(CurrentNode);
	   CurrentNode = NULL;
	   PrevNode->Focused = true;
	   cxTreeView1->Select(PrevNode);

	   AgeBasisListChanged = true;
	   }
	 }
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::EditChronControl(TTreeNode* Node, UnicodeString Caption)
{
   RELATIVEAGE* RelAge;
   EVENT* Event;

   bool IsRelAge = IsRelativeAge(Node);
   bool IsEvtAge = false;
   if (!IsRelAge)
	 IsEvtAge = IsEventAge(Node);

   ChronControlForm = new TChronControlForm(Caption, Node, IsRelAge, IsEvtAge, this);

   double dValue;
   UnicodeString msg = L" is not a valid floating point number.";
   if (ChronControlForm->ShowModal() == mrOk) {
     if (!ChronControlForm->LabeledEdit1->Text.IsEmpty())
       Node->Text = ChronControlForm->LabeledEdit1->Text;
     if (IsRelAge) {
       if (Node->Data)
         RelAge = (RELATIVEAGE*)Node->Data;
       else {
         RelAge = new RELATIVEAGE();
		 Node->Data = RelAge;
         }
       TI_TryStrToFloat(ChronControlForm->LabeledEdit2->Text, RelAge->C14AgeOlder);
       TI_TryStrToFloat(ChronControlForm->LabeledEdit3->Text, RelAge->C14AgeYounger);
       TI_TryStrToFloat(ChronControlForm->LabeledEdit5->Text, RelAge->CalAgeOlder);
       TI_TryStrToFloat(ChronControlForm->LabeledEdit6->Text, RelAge->CalAgeYounger);
       }
     else if (IsEvtAge) {
       if (Node->Data)
         Event = (EVENT*)Node->Data;
       else {
         Event = new EVENT();
         Node->Data = Event;
         }
       TI_TryStrToFloat(ChronControlForm->LabeledEdit2->Text, Event->C14AgeOlder);
       TI_TryStrToFloat(ChronControlForm->LabeledEdit3->Text, Event->C14AgeYounger);
       TI_TryStrToFloat(ChronControlForm->LabeledEdit4->Text, Event->C14Age);
	   TI_TryStrToFloat(ChronControlForm->LabeledEdit5->Text, Event->CalAgeOlder);
       TI_TryStrToFloat(ChronControlForm->LabeledEdit6->Text, Event->CalAgeYounger);
       TI_TryStrToFloat(ChronControlForm->LabeledEdit7->Text, Event->CalAge);
       }
     }

   delete ChronControlForm;
   AgeBasisListChanged = true;

   cxAgeBasisTreeView->Items->Assign(cxTreeView1->Items);
}
//---------------------------------------------------------------------------

bool TTilSpreadSheetForm::IsRelativeAge(TTreeNode* Node)
{
   bool IsRelAge = false;
   TTreeNode* ChildNode = Node;
   if (ChildNode->Level > 1) {
     while (ChildNode->Level > 0) {
       if (SameText(ChildNode->Parent->Text, L"Relative time scale")) {
         IsRelAge = true;
         break;
         }
       else
         ChildNode = ChildNode->Parent;
       }
     }
   return IsRelAge;
}
//---------------------------------------------------------------------------

bool TTilSpreadSheetForm::IsEventAge(TTreeNode* Node)
{
   bool IsEvAge = false;
   TTreeNode* ChildNode = Node;
   while (ChildNode->Level > 0) {
	 if (SameText(ChildNode->Parent->Text, L"Event stratigraphic")) {
       IsEvAge = true;
       break;
       }
     else
       ChildNode = ChildNode->Parent;
     }
   return IsEvAge;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxTreeView1MouseDown(TObject *Sender,
	  TMouseButton Button, TShiftState Shift, int X, int Y)
{
   if (Button == mbLeft && Shift.Contains(ssCtrl))
	 cxTreeView1->BeginDrag(false,-1);
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxTreeView1DragDrop(TObject *Sender,
	  TObject *Source, int X, int Y)
{
   if (!cxTreeView1->Selected)
	 return;
   THitTests HT = cxTreeView1->GetHitTestInfoAt(X, Y);
   TNodeAttachMode AttachMode;
   TTreeNode *pItem = cxTreeView1->GetNodeAt(X, Y);
   if (HT.Contains(htOnItem))
	 cxTreeView1->Selected->MoveTo(pItem, naInsert);
   AgeBasisListChanged = true;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxTreeView1DragOver(TObject *Sender,
	  TObject *Source, int X, int Y, TDragState State, bool &Accept)
{
   Accept = true;
}
//---------------------------------------------------------------------------

// ---- end TreeView1 functions

void __fastcall TTilSpreadSheetForm::cxButton26Click(TObject *Sender)
{
   chAgeBasisPopupEdit->DroppedDown = false;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::SSAnalysisUnit1Click(TObject *Sender)
{
   if (HeaderRow2 == ANAL_UNIT_NAME) return;

   MoveHeaderRow2DataToSS();
   MoveSSDataToHeaderRow2(ANAL_UNIT_NAME);

   HeaderRow2 = ANAL_UNIT_NAME;
   Row2HintStr = "Analysis Unit name.";
   SSAnalysisUnit1->Checked = true;
   SSCollectionUnitName1->Checked = false;
   SSCollectionUnitHandle1->Checked = false;
   SSSiteName1->Checked = false;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::SSCollectionUnitName1Click(TObject *Sender)
{
   if (HeaderRow2 == COLL_UNIT_NAME) return;

   MoveHeaderRow2DataToSS();
   MoveSSDataToHeaderRow2(COLL_UNIT_NAME);

   HeaderRow2 = COLL_UNIT_NAME;
   Row2HintStr = L"Collection Unit name.";
   SSAnalysisUnit1->Checked = false;
   SSCollectionUnitName1->Checked = true;
   SSCollectionUnitHandle1->Checked = false;
   SSSiteName1->Checked = false;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::SSCollectionUnitHandle1Click(TObject *Sender)
{
   if (HeaderRow2 == COLL_UNIT_HANDLE) return;

   MoveHeaderRow2DataToSS();
   MoveSSDataToHeaderRow2(COLL_UNIT_HANDLE);

   HeaderRow2 = COLL_UNIT_HANDLE;
   Row2HintStr = L"Collection Unit handle.";
   SSAnalysisUnit1->Checked = false;
   SSCollectionUnitName1->Checked = false;
   SSCollectionUnitHandle1->Checked = true;
   SSSiteName1->Checked = false;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::SSSiteName1Click(TObject *Sender)
{
   if (HeaderRow2 == SITE_NAME) return;

   MoveHeaderRow2DataToSS();
   MoveSSDataToHeaderRow2(SITE_NAME);

   HeaderRow2 = SITE_NAME;
   Row2HintStr = L"Site Name.";
   SSAnalysisUnit1->Checked = false;
   SSCollectionUnitName1->Checked = false;
   SSCollectionUnitHandle1->Checked = false;
   SSSiteName1->Checked = true;
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::MoveHeaderRow2DataToSS(void)
{
   int firstrow, lastrow, newrow;
   int StartCol = AbsHeaderColCount(ProfGrid1);
   int EndCol = AbsContentColCount(ProfGrid1);

   bool found = false;
   for (int col=StartCol; col<=EndCol; col++) {
	 if (!ProfGrid1->AbsoluteCells[col][2]->Text.IsEmpty()) {
	   found = true;
	   break;
	   }
	 }

   if (!found) return;

   // if data already exist in HeaderRow2, move to spreadsheet
   switch (HeaderRow2) {
	 case SITE_NAME:
	   if (MetaDataBounds(L"#SITE.", firstrow, lastrow))
		 newrow = firstrow;
	   else
		 newrow = 3;
	   ProfGrid1->Row = newrow;
	   EnterSSMetadataCode("#Site.Name", "Site Name");
	   break;
	 case ANAL_UNIT_NAME:
	   if (MetaDataBounds(L"#ANAL.", firstrow, lastrow))
		 newrow = firstrow;
	   else if (MetaDataBounds(L"#COLL.", firstrow, lastrow))
		 newrow = lastrow + 1;
	   else if (MetaDataBounds(L"#SITE.", firstrow, lastrow))
		 newrow = lastrow + 1;
	   else
		 newrow = 3;
	   ProfGrid1->Row = newrow;
	   EnterSSMetadataCode("#Anal.Name", "Analysis Unit Name");
	   break;
	 case COLL_UNIT_NAME:
	 case COLL_UNIT_HANDLE:
	   if (MetaDataBounds(L"#COLL.", firstrow, lastrow))
		 newrow = firstrow;
	   else if (MetaDataBounds(L"#SITE.", firstrow, lastrow))
		 newrow = lastrow + 1;
	   else if (MetaDataBounds(L"#ANAL.", firstrow, lastrow))
		 newrow = firstrow;
	   else
		 newrow = 3;
	   ProfGrid1->Row = newrow;
	   if (HeaderRow2 == COLL_UNIT_NAME)
		 EnterSSMetadataCode("#Coll.Name", "Collection Unit Name");
	   else
		 EnterSSMetadataCode("#Coll.Handle", "Handle");
	   break;
	 }

   for (int col=StartCol; col<=EndCol; col++) {
	 TProfGridCell* SourceCell = ProfGrid1->AbsoluteCells[col][2];
	 TProfGridCell* DestCell = ProfGrid1->AbsoluteCells[col][newrow];
	 DestCell->Value = SourceCell->Value;
	 SourceCell->Value = Unassigned();
	 if (HeaderRow2 == SITE_NAME) {
	   CELLOBJECT* CellObject = new CELLOBJECT((CELLOBJECT*)SourceCell->CellObject);
	   AddCellObject(DestCell, CellObject);
	   DeleteCellObject(SourceCell);
	   }
	 }
   ProfGrid1->Row = 2;
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::MoveSSDataToHeaderRow2(int MDType)
{
   int MDRow = FindRowMD(MDType);
   if (MDRow > 2) {
	 int StartCol = AbsHeaderColCount(ProfGrid1);
	 int EndCol = AbsContentColCount(ProfGrid1);
	 for (int col=StartCol; col<=EndCol; col++) {
	   TProfGridCell* SourceCell = ProfGrid1->AbsoluteCells[col][MDRow];
	   TProfGridCell* DestCell = ProfGrid1->AbsoluteCells[col][2];
	   DestCell->Value = SourceCell->Value;
	   if (MDType == SITE_NAME) {
		 CELLOBJECT* CellObject = new CELLOBJECT((CELLOBJECT*)SourceCell->CellObject);
		 AddCellObject(DestCell, CellObject);
		 DeleteCellObject(SourceCell);
		 }
	   }
	 ProfGrid1->DeleteRow(MDRow);
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::Login1Click(TObject *Sender)
{
   ParentForm->NeotomaLogin();
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::NeotomaUploadAction1Execute(TObject *Sender)
{
   if (!Login->IsLoggedIn) {
	 NeotomaLoginForm = new TNeotomaLoginForm(this);
	 NeotomaLoginForm->ShowModal();
	 delete NeotomaLoginForm;
	 }
   if (Login->IsLoggedIn) {
	 NeotomaUploadForm = new TNeotomaUploadForm(this);
	 NeotomaUploadForm->ShowModal();
	 delete NeotomaUploadForm;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::NeotomaEditTaxaTableAction1Execute(TObject *Sender)
{
   if (!Login->IsLoggedIn) {
	 NeotomaLoginForm = new TNeotomaLoginForm(this);
	 NeotomaLoginForm->ShowModal();
	 delete NeotomaLoginForm;
	 }
   if (Login->IsLoggedIn) {
	 TNeotomaEditTaxaForm* NeotomaEditTaxaForm = new TNeotomaEditTaxaForm(this);
	 NeotomaEditTaxaForm->ShowModal();
	 delete NeotomaEditTaxaForm;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::NeotomaEditPublicationsTableAction1Execute(TObject *Sender)
{
   if (!Login->IsLoggedIn) {
	 NeotomaLoginForm = new TNeotomaLoginForm(this);
	 NeotomaLoginForm->ShowModal();
	 delete NeotomaLoginForm;
	 }
   if (Login->IsLoggedIn) {
	 TStewardPubForm* NeotomaEditPubForm = new TStewardPubForm(NULL, NEWPUB, NULL, this);
	 NeotomaEditPubForm->ShowModal();
	 delete NeotomaEditPubForm;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::NeotomaValidateTaxaAction1Execute(TObject *Sender)
{
   NeotomaTaxaValidationForm = new TNeotomaTaxaValidationForm(this);
   NeotomaTaxaValidationForm->ShowModal();
   delete NeotomaTaxaValidationForm;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::NeotomaHierarchyCheckAction1Execute(TObject *Sender)
{
   CheckHierarchyForm = new TCheckHierarchyForm(this);
   CheckHierarchyForm->ShowModal();
   delete CheckHierarchyForm;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::NeotomaTaxaLookupAction1Execute(TObject *Sender)

{
   NeotomaTaxaLookupForm = new TNeotomaTaxaLookupForm(this);
   NeotomaTaxaLookupForm->ShowModal();
   delete NeotomaTaxaLookupForm;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::NeotomaModifiersAction1Execute(TObject *Sender)
{
   NeotomaVarModsLookupForm = new TNeotomaVarModsLookupForm(this);
   NeotomaVarModsLookupForm->ShowModal();
   delete NeotomaVarModsLookupForm;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::DataType1Click(TObject *Sender)
{
   SSAnalysisUnit1->Checked = false;
   SSCollectionUnitName1->Checked = false;
   SSCollectionUnitHandle1->Checked = false;
   SSSiteName1->Checked = false;
   switch (HeaderRow2) {
	 case ANAL_UNIT_NAME:
	   SSAnalysisUnit1->Checked = true;
	   break;
	 case COLL_UNIT_NAME:
	   SSCollectionUnitName1->Checked = true;
	   break;
	 case COLL_UNIT_HANDLE:
	   SSCollectionUnitHandle1->Checked = true;
	   break;
	 case SITE_NAME:
	   SSSiteName1->Checked = true;
	   break;
	 }
}
//---------------------------------------------------------------------------

// Geochronology grid
void __fastcall TTilSpreadSheetForm::cxGrid2TableView1EditKeyDown(
      TcxCustomGridTableView *Sender, TcxCustomGridTableItem *AItem,
      TcxCustomEdit *AEdit, WORD &Key, TShiftState Shift)
{
   if ((Key == 'V' || Key == 'v') && Shift.Contains(ssCtrl))
	 PasteGrid(Sender);
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::AfterGridPaste(UnicodeString text, TcxGridTableView* cxGridTableView)
{
   int pos, reci;
   TcxRowInfo RowInfo;

   if ((pos = text.Pos(L"\t")) > 0)
	 text = text.SubString(1,pos-1);
   else if ((pos = GridPaste.Pos(L"\r\n")) > 0)
	 text = text.SubString(1,pos-1);
   int FocusedItemIndex = cxGridTableView->Controller->FocusedItemIndex;
   int FocusedRecordIndex = cxGridTableView->Controller->FocusedRecordIndex;

   Variant Value = text;

   if (FocusedRecordIndex == -1)
	 reci = cxGridTableView->DataController->AppendRecord();
   else if (FocusedRecordIndex < cxGridTableView->DataController->RecordCount) {
	 RowInfo = cxGridTableView->DataController->GetRowInfo(FocusedRecordIndex);
	 reci = RowInfo.RecordIndex;
	 }
   else
	 reci = cxGridTableView->DataController->AppendRecord();

   unsigned int ItemCount = cxGridTableView->ItemCount;
   unsigned int item = FocusedItemIndex;
   unsigned int it = 0;
   while (it < item) {
	 if (!cxGridTableView->Items[it++]->Visible)
	   item++;
	 }

   while (item < ItemCount && !cxGridTableView->Items[item]->Visible) item++;
   if (item < ItemCount) {
	 cxGridTableView->DataController->SetValue(reci, item, Value);
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxGrid2TableView1EditKeyUp(
	  TcxCustomGridTableView *Sender, TcxCustomGridTableItem *AItem,
	  TcxCustomEdit *AEdit, WORD &Key, TShiftState Shift)
{
   if (((Key == 'V' || Key == 'v') && Shift.Contains(ssCtrl)) && !GridPaste.IsEmpty()) {
	 Clipboard()->Open();
	 Clipboard()->SetTextBuf(GridPaste.c_str());
	 Clipboard()->Close();
	 AfterGridPaste(GridPaste, cxGrid2TableView1);
	 }
   else if ((Key == 'C' || Key == 'c') && Shift.Contains(ssCtrl)) {
     if (cxGrid2TableView1->Controller->SelectedColumnCount > 1 ||
         cxGrid2TableView1->Controller->SelectedRowCount > 1)
           Sender->CopyToClipboard(false);
     }
   else if ((Key == 'X' || Key == 'x') && Shift.Contains(ssCtrl)) {
     SSCutAction1Execute(Sender);
     }
   else if ((Key == 'K' || Key == 'k') && Shift.Contains(ssCtrl)) {
     if (cxGrid2TableView1->Controller->SelectedColumnCount > 1 ||
         cxGrid2TableView1->Controller->SelectedRowCount > 1) {
           cxGrid2TableView1->OptionsBehavior->CopyCaptionsToClipboard = true;
           Sender->CopyToClipboard(false);
           cxGrid2TableView1->OptionsBehavior->CopyCaptionsToClipboard = false;
		   }
     }
   else if ((Key == 'A' || Key == 'a') && Shift.Contains(ssCtrl))
	 cxGrid2TableView1->Controller->SelectAll();
   else if ((Key == 'D' || Key == 'd') && Shift.Contains(ssCtrl)) {
	 if (AItem->Index == geParams->Index || AItem->Index == gePublication->Index) {
	   TcxCustomGridRecord *AFocusedRecord = cxGrid2TableView1->Controller->FocusedRecord;
	   if (AFocusedRecord != NULL) {
		 int RowIndex = AFocusedRecord->Index;
		 if (RowIndex > 0) {
		   int RecordIndex = AFocusedRecord->RecordIndex;     // index in data source
		   GEOCHRON& date = GeochronList->Dates[RecordIndex]; // current date
		   for (int i = 0; i < cxGrid2TableView1->DataController->RowCount; i++) {
			 if (cxGrid2TableView1->DataController->GetRowIndexByRecordIndex(i,false) == RowIndex-1) {
			   GEOCHRON& prevdate = GeochronList->Dates[i];
			   if (AItem->Index == geParams->Index) {
				 date.Parameters = prevdate.Parameters;

				 UnicodeString ParamStr;
				 if (date.Parameters.size() > 0) {
				   map<UnicodeString,Variant>::iterator begin = date.Parameters.begin();
				   map<UnicodeString,Variant>::iterator end = date.Parameters.end();
				   map<UnicodeString,Variant>::iterator itr;
				   for (itr = begin; itr != end; itr++) {
					 if (!ParamStr.IsEmpty())
					   ParamStr += L";";
					 ParamStr += (itr->first + L":" + VarToStr(itr->second));
					 }
				   }
				 cxGrid2TableView1->DataController->Values[RecordIndex][geParams->Index] = ParamStr;
				 }
			   else if (AItem->Index == gePublication->Index) {
				 date.publications = prevdate.publications;
				 date.PubComboBoxText.SetLength(0);
				 for (unsigned int i=0; i<date.publications.size(); i++) {
				   if (i > 0)
					 date.PubComboBoxText += L";";
				   date.PubComboBoxText += date.publications[i]->GetShortCitation(false);
				   }
				 cxGrid2TableView1->DataController->Values[RecordIndex][geParams->Index] = date.PubComboBoxText;
				 }
			   break;
			   }
			 }
		   }
		 }
	   }
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxGrid2TableView1CellClick(TcxCustomGridTableView *Sender,
		  TcxGridTableDataCellViewInfo *ACellViewInfo, TMouseButton AButton,
		  TShiftState AShift, bool &AHandled)
{
   if (Downloaded && AButton == mbRight) {
	 TcxCustomGridRecord *AFocusedRecord = cxGrid2TableView1->Controller->FocusedRecord;
	 GEOCHRON& date = GeochronList->Dates[AFocusedRecord->RecordIndex];
	 UnicodeString msg = L"GeochronID = " + IntToStr(date.NeotomaGeochronID) + L".";
	 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxGrid3TableView1EditKeyDown(
	  TcxCustomGridTableView *Sender, TcxCustomGridTableItem *AItem,
      TcxCustomEdit *AEdit, WORD &Key, TShiftState Shift)
{
   if ((Key == 'V' || Key == 'v') && Shift.Contains(ssCtrl))
     PasteGrid(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxGrid3TableView1EditKeyUp(
      TcxCustomGridTableView *Sender, TcxCustomGridTableItem *AItem,
      TcxCustomEdit *AEdit, WORD &Key, TShiftState Shift)
{
   if (((Key == 'V' || Key == 'v') && Shift.Contains(ssCtrl)) && !GridPaste.IsEmpty()) {
     Clipboard()->Open();
     Clipboard()->SetTextBuf(GridPaste.c_str());
     Clipboard()->Close();
	 //GridPaste.SetLength(0);
	 AfterGridPaste(GridPaste, cxGrid3TableView1);
     }
   else if ((Key == 'C' || Key == 'c') && Shift.Contains(ssCtrl)) {
     if (cxGrid3TableView1->Controller->SelectedColumnCount > 1 ||
         cxGrid3TableView1->Controller->SelectedRowCount > 1)
           Sender->CopyToClipboard(false);
     }
   else if ((Key == 'X' || Key == 'x') && Shift.Contains(ssCtrl)) {
     SSCutAction1Execute(Sender);
     }
   else if ((Key == 'K' || Key == 'k') && Shift.Contains(ssCtrl)) {
     if (cxGrid3TableView1->Controller->SelectedColumnCount > 1 ||
         cxGrid3TableView1->Controller->SelectedRowCount > 1) {
           cxGrid3TableView1->OptionsBehavior->CopyCaptionsToClipboard = true;
           Sender->CopyToClipboard(false);
           cxGrid3TableView1->OptionsBehavior->CopyCaptionsToClipboard = false;
           }
     }
   else if ((Key == 'A' || Key == 'a') && Shift.Contains(ssCtrl))
     cxGrid3TableView1->Controller->SelectAll();
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxGrid3TableView2EditKeyDown(
	  TcxCustomGridTableView *Sender, TcxCustomGridTableItem *AItem,
      TcxCustomEdit *AEdit, WORD &Key, TShiftState Shift)
{
   if ((Key == 'V' || Key == 'v') && Shift.Contains(ssCtrl))
	 PasteGrid(Sender);
   else if (Key == VK_DELETE)
	 Sender->Controller->FocusedRecord->Values[AItem->Index] = Unassigned();
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxGrid3TableView2EditKeyUp(
      TcxCustomGridTableView *Sender, TcxCustomGridTableItem *AItem,
      TcxCustomEdit *AEdit, WORD &Key, TShiftState Shift)
{
   TcxGridTableView* CurrentTableView;

   if (((Key == 'V' || Key == 'v') && Shift.Contains(ssCtrl)) && !GridPaste.IsEmpty()) {
     Clipboard()->Open();
     Clipboard()->SetTextBuf(GridPaste.c_str());
     Clipboard()->Close();
	 //GridPaste.SetLength(0);
	 AfterGridPaste(GridPaste, cxGrid3TableView2);
     }
   else if ((Key == 'C' || Key == 'c') && Shift.Contains(ssCtrl)) {
     CurrentTableView = dynamic_cast< TcxGridTableView *>(cxGrid3->FocusedView);
     if (CurrentTableView->Controller->SelectedColumnCount > 1 ||
         CurrentTableView->Controller->SelectedRowCount > 1)
           Sender->CopyToClipboard(false);
     }
   else if ((Key == 'X' || Key == 'x') && Shift.Contains(ssCtrl)) {
     SSCutAction1Execute(Sender);
     }
   else if ((Key == 'K' || Key == 'k') && Shift.Contains(ssCtrl)) {
     CurrentTableView = dynamic_cast< TcxGridTableView *>(cxGrid3->FocusedView);
     if (CurrentTableView->Controller->SelectedColumnCount > 1 ||
		 CurrentTableView->Controller->SelectedRowCount > 1) {
           CurrentTableView->OptionsBehavior->CopyCaptionsToClipboard = true;
           Sender->CopyToClipboard(false);
           CurrentTableView->OptionsBehavior->CopyCaptionsToClipboard = false;
           }
     }
   else if ((Key == 'A' || Key == 'a') && Shift.Contains(ssCtrl)) {
     CurrentTableView = dynamic_cast< TcxGridTableView *>(cxGrid3->FocusedView);
     CurrentTableView->Controller->SelectAll();
     }
}
//---------------------------------------------------------------------------

bool __fastcall TTilSpreadSheetForm::SetLithUnitItem(LITHOLOGYUNIT* LithUnit,
       UnicodeString& Value, int ItemIndex)
{
   // returns false if an error, true if ok
   switch (ItemIndex)
   {
   case 0:
     try {
         LithUnit->DepthTop = StrToFloat(Value);
         }
     catch(Exception &e) {
		 MessageDlg(e.Message, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 return false;
         }
	 break;
   case 1:
     try {
         LithUnit->DepthBottom = StrToFloat(Value);
         }
     catch(Exception &e) {
         MessageDlg(e.Message, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
         return false;
         }
     break;
   case 2:
     LithUnit->UnitDescription = Value;
     break;
   case 3:
     LithUnit->LowerBoundary = Value;
     break;
   }
   return true;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::liTopPropertiesValidate(
      TObject *Sender, Variant &DisplayValue, TCaption &ErrorText,
      bool &Error)
{
   ValidateNumericalDisplayValue(DisplayValue, ErrorText, Error);
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::liBottomPropertiesValidate(
      TObject *Sender, Variant &DisplayValue, TCaption &ErrorText,
      bool &Error)
{
   ValidateNumericalDisplayValue(DisplayValue, ErrorText, Error);
}
//---------------------------------------------------------------------------


int TTilSpreadSheetForm::GetTreeViewCount(TcxTreeView* cxTreeView)
{
   int count = 0;
   try {
	   cxTreeView->ClearSelection();
	   count = cxTreeView->Items->Count;
	   }
   catch (...) { }
   return count;
}
//---------------------------------------------------------------------------

int TTilSpreadSheetForm::GetTreeViewCount(TdxTreeView* dxTreeView)
{
   int count = 0;
   try {
	   dxTreeView->ClearSelection();
	   count = dxTreeView->Items->Count;
	   }
   catch (...) { }
   return count;
}
//---------------------------------------------------------------------------

int TTilSpreadSheetForm::GetTreeViewCount(TdxTreeViewEdit* dxTreeViewEdit)
{
   int count = 0;
   try {
	   count = dxTreeViewEdit->Items->Count;
	   }
   catch (...) { }
   return count;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::AdvControlDropDown3BeforeDropDown(TObject *Sender)
{
   if (ModifierType == MODTAPH)
	 TaphStatus = TAPHNONE;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::AdvControlDropDown3DropDownFooterButtonClick(TObject *Sender,
		  int ButtonIndex)
{
   SetModifiers(ButtonIndex);
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxCheckListBox1DblClick(TObject *Sender)
{
   SetModifiers(0);
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::SetModifiers(int ButtonIndex)
{
   switch (ModifierType) {
	 case MODELEMENT:
	   if (ButtonIndex == 0)    // Ok button
		 PostElement();
	   break;
	 case MODTAPH:
	   if (ButtonIndex == 0) {  // Ok button
		 PostTaphonomy();
		 TaphStatus = TAPHPOSTED;
		 }
	   else
		 TaphStatus = TAPHCANCELED;
	   break;
	 }
   AdvControlDropDown3->HideDropDown();
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxCheckListBox1ClickCheck(TObject *Sender, int AIndex,
		  TcxCheckBoxState APrevState, TcxCheckBoxState ANewState)
{
   if (ModifierType == MODTAPH) {
	 UnicodeString SystemName = cxComboBox12->Text;
	 for (unsigned int i=0; i<TempTaphSystems->Systems.size(); i++) {
	   if (SameText(TempTaphSystems->Systems[i].Name, SystemName)) {
		 UnicodeString Type = cxCheckListBox1->Items->Items[AIndex]->Text;
		 switch (ANewState) {
		   case cbsChecked:
			 TempTaphSystems->Systems[i].Types.insert(Type);
			 break;
		   case cbsUnchecked:
			 if (TempTaphSystems->Systems[i].Types.count(Type) > 0)
               TempTaphSystems->Systems[i].Types.erase(Type);
			 break;
		   }
		 }
	   }
	 }
}
//---------------------------------------------------------------------------

// --> Lithology Tabsheet

void __fastcall TTilSpreadSheetForm::GenerateLithologyUnitColumns()
{
   liTop->DataBinding->Data = (TObject*)IndexOfliTop;
   liBottom->DataBinding->Data = (TObject*)IndexOfliBottom;
   liDescription->DataBinding->Data = (TObject*)IndexOfliDescription;
   liLowerBound->DataBinding->Data = (TObject*)IndexOfliLowerBound;

   // this line is critical
   cxGrid1TableView1->DataController->CustomDataSource = LithologyUnitDataSource;
}
//---------------------------------------------------------------------------

bool __fastcall TTilSpreadSheetForm::AllCellsSelected(TcxGridTableView* Grid)
{
   return (Grid->Controller->SelectedColumnCount == Grid->VisibleColumnCount &&
           Grid->Controller->SelectedRowCount == Grid->DataController->RowCount);
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxGrid1TableView1EditKeyDown(
	  TcxCustomGridTableView *Sender, TcxCustomGridTableItem *AItem,
      TcxCustomEdit *AEdit, WORD &Key, TShiftState Shift)
{
   if ((Key == 'V' || Key == 'v') && Shift.Contains(ssCtrl))
     PasteGrid(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxGrid1TableView1EditKeyUp(
      TcxCustomGridTableView *Sender, TcxCustomGridTableItem *AItem,
      TcxCustomEdit *AEdit, WORD &Key, TShiftState Shift)
{
   if (((Key == 'V' || Key == 'v') && Shift.Contains(ssCtrl)) && !GridPaste.IsEmpty()) {
     Clipboard()->Open();
     Clipboard()->SetTextBuf(GridPaste.c_str());
     Clipboard()->Close();
	 //GridPaste.SetLength(0);
	 AfterGridPaste(GridPaste, cxGrid1TableView1);
     }
   else if ((Key == 'C' || Key == 'c') && Shift.Contains(ssCtrl)) {
     if (cxGrid1TableView1->Controller->SelectedColumnCount > 1 ||
         cxGrid1TableView1->Controller->SelectedRowCount > 1)
           Sender->CopyToClipboard(false);
     }
   else if ((Key == 'X' || Key == 'x') && Shift.Contains(ssCtrl)) {
     SSCutAction1Execute(Sender);
     }
   else if ((Key == 'K' || Key == 'k') && Shift.Contains(ssCtrl)) {
     if (cxGrid1TableView1->Controller->SelectedColumnCount > 1 ||
         cxGrid1TableView1->Controller->SelectedRowCount > 1) {
           cxGrid1TableView1->OptionsBehavior->CopyCaptionsToClipboard = true;
           Sender->CopyToClipboard(false);
           cxGrid1TableView1->OptionsBehavior->CopyCaptionsToClipboard = false;
           }
     }
   else if ((Key == 'A' || Key == 'a') && Shift.Contains(ssCtrl))
     cxGrid1TableView1->Controller->SelectAll();
}
//---------------------------------------------------------------------------

// --> Geochronlogy Tabsheet

void __fastcall TTilSpreadSheetForm::GenerateGeochronColumns()
{
   geMethod->DataBinding->Data = (TObject*)IndexOfgeMethod;
   geAgeUnits->DataBinding->Data = (TObject*)IndexOfgeAgeUnits;
   geDepth->DataBinding->Data = (TObject*)IndexOfgeDepth;
   geThickness->DataBinding->Data = (TObject*)IndexOfgeThickness;
   geAnalUnit->DataBinding->Data = (TObject*)IndexOfgeAnalUnit;
   geAnalUnitID->DataBinding->Data = (TObject*)IndexOfgeAnalUnitID;
   geLabNumber->DataBinding->Data = (TObject*)IndexOfgeLabNumber;
   geAge->DataBinding->Data = (TObject*)IndexOfgeAge;
   geErrorOlder->DataBinding->Data = (TObject*)IndexOfgeErrorOlder;
   geErrorYounger->DataBinding->Data = (TObject*)IndexOfgeErrorYounger;
   geSigma->DataBinding->Data = (TObject*)IndexOfgeSigma;
   geSD->DataBinding->Data = (TObject*)IndexOfgeSD;
   geInfinite->DataBinding->Data = (TObject*)IndexOfgeInfinite;
   geParams->DataBinding->Data = (TObject*)IndexOfgeParams;
   geMaterialDated->DataBinding->Data = (TObject*)IndexOfgeMaterialDated;
   gePublication->DataBinding->Data = (TObject*)IndexOfgePublication;
   geNotes->DataBinding->Data = (TObject*)IndexOfgeNotes;
   // this line is critical
   cxGrid2TableView1->DataController->CustomDataSource = GeochronDataSource;

   //txID->DataBinding->Data = (TObject*)IndexOftxID;
   txUserSpecimenID->DataBinding->Data = (TObject*)IndexOftxUserSpecimenID;
   txTaxon->DataBinding->Data = (TObject*)IndexOftxTaxon;
   txElement->DataBinding->Data = (TObject*)IndexOftxElement;
   txFraction->DataBinding->Data = (TObject*)IndexOftxFraction;
   txCalAgeOlder->DataBinding->Data = (TObject*)IndexOftxCalAgeMedian;
   txCalAgeOlder->DataBinding->Data = (TObject*)IndexOftxCalAgeOlder;
   txCalAgeYounger->DataBinding->Data = (TObject*)IndexOftxCalAgeYounger;
   txCalibCurve->DataBinding->Data = (TObject*)IndexOftxCalCurve;
   txCalibProgram->DataBinding->Data = (TObject*)IndexOftxCalProgram;
   txNotes->DataBinding->Data = (TObject*)IndexOftxNotes;

   // this line is critical
   cxGrid2TableView2->DataController->CustomDataSource = TaxonDatedDataSource;
}
//---------------------------------------------------------------------------

// +/- Sigma radiobutton
void __fastcall TTilSpreadSheetForm::cxRadioButton7Click(TObject *Sender)
{
   geErrorOlder->Visible = false;
   geErrorYounger->Visible = false;
   geSigma->Visible = false;
   geSD->Visible = true;
}
//---------------------------------------------------------------------------

// Older/Younger radiobutton
void __fastcall TTilSpreadSheetForm::cxRadioButton8Click(TObject *Sender)
{
   geErrorOlder->Visible = true;
   geErrorYounger->Visible = true;
   geSigma->Visible = true;
   geSD->Visible = false;
}
//---------------------------------------------------------------------------

// Geochronology Depth checkbox
void __fastcall TTilSpreadSheetForm::cxCheckBox2Click(TObject *Sender)
{
   if (cxCheckBox2->Checked) {
	 geDepth->Visible = true;
	 geThickness->Visible = true;
	 }
   else {
	 geDepth->Visible = false;
	 geThickness->Visible = false;
	 if (!cxCheckBox3->Checked)
	   cxCheckBox3->Checked = true;
	 }
}
//---------------------------------------------------------------------------

// Geochronology Analysis Unit checkbox
void __fastcall TTilSpreadSheetForm::cxCheckBox3Click(TObject *Sender)
{
   if (cxCheckBox3->Checked) {
	 geAnalUnit->Visible = true;
	 }
   else {
	 geAnalUnit->Visible = false;
	 if (!cxCheckBox2->Checked) {
	   cxCheckBox2->Checked = true;
	   }
	 }
}
//---------------------------------------------------------------------------

// Age Model Depth checkbox
void __fastcall TTilSpreadSheetForm::CheckBox1Click(TObject *Sender)
{
   if (CheckBox1->Checked) {
	 chDepth->Visible = true;
	 chThickness->Visible = true;
	 }
   else {
	 chDepth->Visible = false;
	 chThickness->Visible = false;
	 if (!CheckBox3->Checked)
	   CheckBox3->Checked = true;
	 }
}
//---------------------------------------------------------------------------

// Age Model Analysis Unit checkbox
void __fastcall TTilSpreadSheetForm::CheckBox3Click(TObject *Sender)
{
   if (CheckBox3->Checked) {
	 chAnalUnit->Visible = true;
	 }
   else {
	 chAnalUnit->Visible = false;
	 if (!cxCheckBox1->Checked) {
	   cxCheckBox1->Checked = true;
	   }
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::geDepthPropertiesValidate(
      TObject *Sender, Variant &DisplayValue, TCaption &ErrorText,
      bool &Error)
{
   ValidateNumericalDisplayValue(DisplayValue, ErrorText, Error);
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::geThicknessPropertiesValidate(
      TObject *Sender, Variant &DisplayValue, TCaption &ErrorText,
      bool &Error)
{
   ValidateNumericalDisplayValue(DisplayValue, ErrorText, Error);
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::geAgePropertiesValidate(
      TObject *Sender, Variant &DisplayValue, TCaption &ErrorText,
      bool &Error)
{
   ValidateNumericalDisplayValue(DisplayValue, ErrorText, Error);
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::geSDPropertiesValidate(
      TObject *Sender, Variant &DisplayValue, TCaption &ErrorText,
      bool &Error)
{
   ValidateNumericalDisplayValue(DisplayValue, ErrorText, Error);
   if (!Error) {
     TcxCustomGridRecord *AFocusedRecord = cxGrid2TableView1->Controller->FocusedRecord;
     if (AFocusedRecord)
       AFocusedRecord->Values[geInfinite->Index] = false;
     }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::geErrorOlderPropertiesValidate(
      TObject *Sender, Variant &DisplayValue, TCaption &ErrorText,
      bool &Error)
{
   ValidateNumericalDisplayValue(DisplayValue, ErrorText, Error);
   if (!Error) {
     TcxCustomGridRecord *AFocusedRecord = cxGrid2TableView1->Controller->FocusedRecord;
     if (AFocusedRecord)
       AFocusedRecord->Values[geInfinite->Index] = false;
     }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::geErrorYoungerPropertiesValidate(
      TObject *Sender, Variant &DisplayValue, TCaption &ErrorText,
      bool &Error)
{
   ValidateNumericalDisplayValue(DisplayValue, ErrorText, Error);
   if (!Error) {
     TcxCustomGridRecord *AFocusedRecord = cxGrid2TableView1->Controller->FocusedRecord;
     if (AFocusedRecord)
	   AFocusedRecord->Values[geInfinite->Index] = false;
     }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::geMethodPropertiesEditValueChanged(
      TObject *Sender)
{
   TcxCustomGridRecord *AFocusedRecord = cxGrid2TableView1->Controller->FocusedRecord;
   if (!AFocusedRecord) return;

   UnicodeString Method = ((TcxComboBox*)Sender)->Text;
   int RecordIndex = AFocusedRecord->RecordIndex;

   AFocusedRecord->Values[0] = Method;

   UnicodeString AgeType;
   if (SameText(Method.SubString(1,9), L"Carbon-14"))
	 AgeType = L"Radiocarbon years BP";
   else if (SameText(Method.SubString(1,8), L"Lead-210"))
	 AgeType = L"Calendar years AD/BC";
   else
	 AgeType = L"Calendar years BP";
   if (!AgeType.IsEmpty()) {
	 if (RecordIndex > -1)
	   cxGrid2TableView1->DataController->Values[RecordIndex][1] = AgeType;
	 else
	   cxGrid2TableView1->ViewData->NewItemRow->Values[1] = AgeType;
	 }

   if (RecordIndex > -1) {
	 GEOCHRON& date = GeochronList->Dates[RecordIndex];
	 date.Parameters.clear();
	 // the problem is in the next line -- doesn't seem to be needed
	 // cxGrid2TableView1->DataController->Values[RecordIndex][geParams->Index] = L"";
	 }

   if (RecordIndex == -1 && geErrorOlder->Visible)
	 cxGrid2TableView1->DataController->Values[RecordIndex][geSigma->Index] = L"1";
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::TabSheetGeochronShow(TObject *Sender)
{
   // refill publications list, which may have been cleared
   // this generates the list of items that can be checked
   TcxCheckComboBoxItems* CheckComboBoxItems =
	 (TcxCheckComboBoxItems*)(((TcxCheckComboBoxProperties*)(gePublication->Properties))->Items);
   UpdatePublications(CheckComboBoxItems, GeochronList->publications);

   // fill analysis units combobox
   TRect DataContent;
   TcxComboBoxProperties* ge_AnalUnit = (TcxComboBoxProperties*)(geAnalUnit->Properties);
   ge_AnalUnit->Items->Clear();
   DataContent.Left = AbsHeaderColCount(ProfGrid1);
   DataContent.Right = AbsContentColCount(ProfGrid1);
   int row = FindRowMD(ANAL_UNIT_NAME);
   TStringList *AnalysisUnits = new TStringList;
   AnalysisUnits->Duplicates = dupIgnore;
   AnalysisUnits->Sorted = true;
   for (int col=DataContent.Left; col<=DataContent.Right; col++) {
	 TProfGridCell *ACell = ProfGrid1->AbsoluteCells[col][row];
	 if (!ACell->IsEmpty())
	   AnalysisUnits->Add(ACell->Text);
	 }
   ge_AnalUnit->Items->AddStrings(AnalysisUnits);
   delete AnalysisUnits;

   // fill specimen numbers
   /*
   TcxComboBoxProperties* UserSpecIDs = (TcxComboBoxProperties*)(txUserSpecimenID->Properties);
   UserSpecIDs->Items->BeginUpdate();
   UserSpecIDs->Items->Clear();
   TaxonDatedDataSource->Specimens.clear();

   list<CELLOBJECT*>::iterator it;
   for (it = CellObjects.begin(); it != CellObjects.end(); it++) {
	 if ((*it)->ObjectType == CELLSPECIMENS) {
	   TList* Specimens = (TList*)(*it)->Object;
	   for (int i=0; i<Specimens->Count; i++) {
		 SPECIMEN *specimen = (SPECIMEN*)Specimens->Items[i];
		 if (!specimen->UserSpecimenID.IsEmpty()) {
		   UserSpecIDs->Items->Add(specimen->UserSpecimenID);
		   TaxonDatedDataSource->Specimens[specimen->UserSpecimenID] = specimen;
		   }
		 }
	   }
	 }
   UserSpecIDs->Items->EndUpdate();
   */

   for (int i=0; i<GeochronList->Count(); i++) {
	 GEOCHRON* Date = &GeochronList->Dates[i];
	 if (Date->TaxaDated.size() > 0) {
	   for (unsigned int j = 0; j < Date->TaxaDated.size(); j++) {
		 if (Date->TaxaDated[j].Specimen != NULL) {
		   UnicodeString UserSpecID = Date->TaxaDated[j].Specimen->UserSpecimenID;
		   if (UserSpecID != Date->TaxaDated[j].UserSpecID)
			 Date->TaxaDated[j].UserSpecID = UserSpecID;
		   }
		 }
	   }
	 }

   FocusControl(cxGrid2);
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::geParamsPropertiesInitPopup(TObject *Sender)
{
   UnicodeString GeochronType;

   TcxCustomGridRecord *AFocusedRecord = cxGrid2TableView1->Controller->FocusedRecord;

   geParamsPopupEdit = (TcxPopupEdit*)Sender;

   if (AFocusedRecord != NULL)
	 GeochronType = VarToStr(AFocusedRecord->Values[0]);
   AdvColumnGrid3->RowCount = 2;
   AdvColumnGrid3->Height = AdvColumnGrid3->DefaultRowHeight + 3;;
   AdvColumnGrid3->ClearNormalCells();

   // RadiocarbonParams
   if (SameText(GeochronType, L"Carbon-14")) {
	 AdvColumnGrid3->RowCount = RadiocarbonParams.size() + 1;
	 AdvColumnGrid3->Height = AdvColumnGrid3->RowCount * AdvColumnGrid3->DefaultRowHeight + 3;
	 Panel8->Height = AdvColumnGrid3->Height + 19;
	 for (unsigned int i=0, row=1; i<RadiocarbonParams.size(); i++, row++) {
	   AdvColumnGrid3->Cells[0][row] = RadiocarbonParams[i].Parameter;
	   AdvColumnGrid3->Cells[1][row] = L"";
		if (AFocusedRecord->RecordIndex > -1) {
		 GEOCHRON& Date = GeochronList->Dates[AFocusedRecord->RecordIndex];
		 if (Date.Parameters.size() > 0) {
		   map<UnicodeString,Variant>::iterator begin = Date.Parameters.begin();
		   map<UnicodeString,Variant>::iterator end = Date.Parameters.end();
		   map<UnicodeString,Variant>::iterator itr;
		   for (itr = begin; itr != end; itr++) {
			 if (SameText(RadiocarbonParams[i].Parameter, itr->first)) {
			   AdvColumnGrid3->Cells[1][row] = VarToStr(itr->second);
			   break;
			   }
			 }
		   }
		 }
	   }
	 }
   AdvColumnGrid3->AutoSizeColumns(true,0);
   AdvColumnGrid3->Width = AdvColumnGrid3->ColWidths[0] + AdvColumnGrid3->ColWidths[1] + AdvColumnGrid3->ScrollWidth;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::AdvColumnGrid3CellValidate(TObject *Sender, int ACol,
		  int ARow, UnicodeString &Value, bool &Valid)
{
   if (!Value.IsEmpty()) {
	 if (AdvColumnGrid3->Columns->Items[1]->Editor != edNormal) {
	   double dVal;
	   if (!TryStrToFloat(Value, dVal)) {
		 Value = L"";
		 Valid = false;
		 }
	   }
	 else {
	   if (!AdvColumnGrid3->Combobox->Text.IsEmpty()) {
		 if (AdvColumnGrid3->Combobox->Items->IndexOf(AdvColumnGrid3->Combobox->Text) == -1) {
		   AdvColumnGrid3->Combobox->Text = L"";
		   AdvColumnGrid3->Combobox->ItemIndex = -1;
		   Valid = false;
		   }
		 }
	   }
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::AdvColumnGrid3GetEditorType(TObject *Sender,
		  int ACol, int ARow, TEditorType &AEditor)
{
   TcxCustomGridRecord *AFocusedRecord = cxGrid2TableView1->Controller->FocusedRecord;
   UnicodeString GeochronType = VarToStr(AFocusedRecord->Values[0]);

   if (SameText(GeochronType, L"Carbon-14")) {
	 if (SameText(AdvColumnGrid3->Cells[0][ARow], L"Method"))
	   AEditor = edComboList;
	 }
   else
	 AEditor = edNormal;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::AdvColumnGrid3GetEditorProp(TObject *Sender,
		  int ACol, int ARow, TEditLink *AEditLink)
{
   TcxCustomGridRecord *AFocusedRecord = cxGrid2TableView1->Controller->FocusedRecord;
   UnicodeString GeochronType = VarToStr(AFocusedRecord->Values[0]);

   if (SameText(GeochronType, L"Carbon-14")) {
	 if (SameText(AdvColumnGrid3->Cells[0][ARow], L"Method")) {
	   AdvColumnGrid3->ClearComboString();
	   map<int,UnicodeString>::iterator itr;
	   for (itr = RadiocarbonParams[0].Categories.begin(); itr != RadiocarbonParams[0].Categories.end(); itr++) {
		 AdvColumnGrid3->AddComboString(itr->second);
		 }
	   }
	 }
}
//---------------------------------------------------------------------------

// geochron params post button
void __fastcall TTilSpreadSheetForm::cxButton24Click(TObject *Sender)
{
   bool update = false;
   map<UnicodeString,Variant> Parameters;

   TcxCustomGridRecord *AFocusedRecord = cxGrid2TableView1->Controller->FocusedRecord;
   UnicodeString GeochronType = VarToStr(AFocusedRecord->Values[0]);

   if (SameText(GeochronType, L"Carbon-14")) {
	 for (int i=1; i<AdvColumnGrid3->RowCount; i++) {
	   if (!AdvColumnGrid3->Cells[1][i].IsEmpty()) {
		 if (SameText(AdvColumnGrid3->Cells[0][i], L"Method")) {
		   Parameters[L"Method"] = AdvColumnGrid3->Cells[1][i];
		   }
		 else {
		   double Value;
		   if (TryStrToFloat(AdvColumnGrid3->Cells[1][i], Value))
			 Parameters[AdvColumnGrid3->Cells[0][i]] = Value;
		   }
		 }
	   }
	 }

   if (AFocusedRecord->RecordIndex == -1) {   // new item line
	 UnicodeString Text;
	 map<UnicodeString,Variant>::iterator itr;
	 for (itr = Parameters.begin(); itr != Parameters.end(); itr++) {
	   if (!Text.IsEmpty())
		 Text += L";";
	   Text += (itr->first + L":" + VarToStr(itr->second));
	   }
	 cxGrid2TableView1->ViewData->NewItemRow->Values[geParams->Index] = Text;
	 }
   else {
	 GEOCHRON& Date = GeochronList->Dates[AFocusedRecord->RecordIndex];
	 Date.Parameters = Parameters;
	 if (Downloaded && tiLicense->Type() == verNEOTOMASTEWARD)
	   update = true;
	 }

   geParamsPopupEdit->DroppedDown = false;
   geParams->Editing = false;

   if (update) {
	 UnicodeString msg = L"Update radiocarbon parameters?";
	 if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes) {
       GEOCHRON& Date = GeochronList->Dates[AFocusedRecord->RecordIndex];
	   UpdateRadiocarbonParams(Date);
	   }
	 }
}
//---------------------------------------------------------------------------

// geochron params cancel button
void __fastcall TTilSpreadSheetForm::cxButton25Click(TObject *Sender)
{
   geParamsPopupEdit->DroppedDown = false;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::gePublicationPropertiesEditValueToStates(
	  TObject *Sender, const Variant &AValue, TcxCheckStates &ACheckStates)
{
   // Enables you to convert the edit value into a check state manually.
   // Retrieve publications for record and check boxes

   TcxCustomGridRecord *AFocusedRecord = cxGrid2TableView1->Controller->FocusedRecord;
   if (!AFocusedRecord) return;

   if (AFocusedRecord->RecordIndex == -1) {
     if (PubCheckStates.size() == 0) {
       for (int i=0; i<ACheckStates.Length; i++)
         ACheckStates[i] = cbsUnchecked;
       }
     }
   else {
	 if (GeochronList->publications->Count == ACheckStates.Length) {
	   GEOCHRON& Date = GeochronList->Dates[AFocusedRecord->RecordIndex];
	   for (int i=0; i<GeochronList->publications->Count; i++) {
		 if (find(Date.publications.begin(), Date.publications.end(),
		   (PUBLICATION*)GeochronList->publications->Objects[i]) != Date.publications.end())
		   ACheckStates[i] = cbsChecked;
		 else
		   ACheckStates[i] = cbsUnchecked;
		 }
	   }
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::gePublicationPropertiesStatesToEditValue(
	  TObject *Sender, const TcxCheckStates ACheckStates, Variant &AValue)
{
   // Enables you to convert a check state into an edit value manually.
   // post selected publications to date record

   TcxCustomGridRecord *AFocusedRecord = cxGrid2TableView1->Controller->FocusedRecord;
   if (!AFocusedRecord) return;

   if (AFocusedRecord->RecordIndex == -1) {
	 PubCheckStates.clear();
	 bool FirstPub = true;
	 for (int i=0; i<GeochronList->publications->Count; i++) {
	   PubCheckStates.push_back((ACheckStates[i] == cbsChecked) ? true : false);
	   if (ACheckStates[i]) {
		 if (FirstPub) {
		   NewRecordPubText = GeochronList->publications->Strings[i];
		   FirstPub = false;
		   }
		 else
		   NewRecordPubText += (";" + GeochronList->publications->Strings[i]);
		 }
	   }
	 }
   else {
	 GEOCHRON& Date = GeochronList->Dates[AFocusedRecord->RecordIndex];
	 Date.publications.clear();
	 Date.PubComboBoxText.SetLength(0);
	 for (int i=0; i<GeochronList->publications->Count; i++) {
	   if (ACheckStates[i] == cbsChecked) {
		 Date.publications.push_back((PUBLICATION*)GeochronList->publications->Objects[i]);
		 if (Date.publications.size() == 1)
		   Date.PubComboBoxText = GeochronList->publications->Strings[i];
		 else
		   Date.PubComboBoxText += (";" + GeochronList->publications->Strings[i]);
		 }
	   }
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::gePublicationGetDisplayText(
	  TcxCustomGridTableItem *Sender, TcxCustomGridRecord *ARecord,
	  UnicodeString &AText)
{
   // display publication info
   if (!ARecord) return;

   if (ARecord->RecordIndex == -1)
	 AText = NewRecordPubText;
   else {
	 GEOCHRON& Date = GeochronList->Dates[ARecord->RecordIndex];
	 AText = Date.PubComboBoxText;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxGrid2TableView1DataControllerBeforePost(TcxCustomDataController *ADataController)
{
   UnicodeString param, value;
   TcxCustomGridRecord *AFocusedRecord = cxGrid2TableView1->Controller->FocusedRecord;

   if (AFocusedRecord->RecordIndex == -1) {
	 // decode params text
	 NewGeochronParams.clear();
	 UnicodeString ParamText = VarToStr(cxGrid2TableView1->ViewData->NewItemRow->Values[geParams->Index]);
	 if (!ParamText.IsEmpty()) {
	   vector<UnicodeString> Params;
	   int idx = ParamText.Pos(L";");
	   while (idx > 0) {
		 UnicodeString Param = ParamText.SubString(1,idx-1);
		 int pos = Param.Pos(L":");
		 param = Param.SubString(1,pos-1);
		 value = Param.Delete(1,pos);
		 NewGeochronParams[param] = value;
		 ParamText.Delete(1,idx);
		 idx = ParamText.Pos(L";");
		 }
	   int pos = ParamText.Pos(L":");
	   param = ParamText.SubString(1,pos-1);
	   value = ParamText.Delete(1,pos);
	   NewGeochronParams[param] = value;
	   }
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxGrid2TableView1DataControllerAfterPost(
      TcxCustomDataController *ADataController)
{
   TcxCustomGridRecord *AFocusedRecord = cxGrid2TableView1->Controller->FocusedRecord;

   if (AFocusedRecord->RecordIndex == -1) {
	 GEOCHRON& Date = GeochronList->Dates.back();
	 for (unsigned int i=0; i<PubCheckStates.size(); i++) {
	   if (PubCheckStates[i]) {
		 Date.publications.push_back((PUBLICATION*)GeochronList->publications->Objects[i]);
		 if (Date.publications.size() == 1)
		   Date.PubComboBoxText = GeochronList->publications->Strings[i];
		 else
		   Date.PubComboBoxText += (";" + GeochronList->publications->Strings[i]);
		 }
	   }
	 PubCheckStates.clear();
	 NewRecordPubText.SetLength(0);
	 ADataController->Values[-1][gePublication->Index] = Unassigned();
	 Date.Parameters = NewGeochronParams;
	 if (Downloaded && tiLicense->Type() == verNEOTOMASTEWARD) {
	   UploadNeotomaGeochron(Date);
	   }
	 }
   else if (Downloaded && tiLicense->Type() == verNEOTOMASTEWARD) {
	 GEOCHRON& Date = GeochronList->Dates[AFocusedRecord->RecordIndex];
	 UnicodeString msg = L"Update geochronologic measurement?";
	 if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes)
	   UpdateNeotomaGeochron(Date);
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxGrid2TableView2DataControllerAfterPost(TcxCustomDataController *ADataController)
{
   UnicodeString msg;

   if (Downloaded && tiLicense->Type() == verNEOTOMASTEWARD) {
	 int RecordIndex1 = cxGrid2TableView1->Controller->FocusedRecord->RecordIndex;
	 int RecordIndex2 = ADataController->FocusedRecordIndex;
	 vector<GEOCHRON>::pointer Date = GeochronList->Date[RecordIndex1];
	 if (RecordIndex2 == -1) {
	   TAXONDATED& TaxonDated = Date->TaxaDated.back();
	   msg = L"Upload new dated specimen to Neotoma?";
	   if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes)
		 UploadTaxonDated(Date->NeotomaGeochronID, TaxonDated);
	   }
	 else {
	   TAXONDATED& TaxonDated = Date->TaxaDated[RecordIndex2];
	   msg = L"Update dated specimen in Neotoma?";
	   if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes)
		 UpdateTaxonDated(TaxonDated);
	   }
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::txUserSpecimenIDGetCellHint(TcxCustomGridTableItem *Sender,
		  TcxCustomGridRecord *ARecord, TcxGridTableDataCellViewInfo *ACellViewInfo,
		  const TPoint &AMousePos, TCaption &AHintText,
		  bool &AIsHintMultiLine, TRect &AHintTextRect)
{
   if (ARecord->IsNewItemRecord)
     AHintText = L"Specimen ID from Data worksheet";
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::TabSheetAgeModelsShow(TObject *Sender)
{
   // refill preparers list, which may have been changed
   TcxCheckComboBoxItems* CheckComboBoxItems =
	 (TcxCheckComboBoxItems*)(((TcxCheckComboBoxProperties*)(amPreparer->Properties))->Items);

   CheckComboBoxItems->Clear();

   for (int i=0; i<ContactList->Count; i++) {
	 CONTACT* Contact = ContactList->Contacts[i];
	 CheckComboBoxItems->AddCheckItem(Contact->ShortContactName, Contact->ShortContactName);
	 }

   // fill analysis units combobox
   TcxComboBoxProperties* ch_AnalUnit = (TcxComboBoxProperties*)(chAnalUnit->Properties);
   ch_AnalUnit->Items->Clear();
   int StartCol = AbsHeaderColCount(ProfGrid1);
   int EndCol = AbsContentColCount(ProfGrid1);
   int row = FindRowMD(ANAL_UNIT_NAME);
   TStringList *AnalysisUnits = new TStringList;
   AnalysisUnits->Duplicates = dupIgnore;
   AnalysisUnits->Sorted = true;
   //AnalysisUnits->Add(L"");
   for (int col=StartCol; col<=EndCol; col++) {
	 TProfGridCell *ACell = ProfGrid1->AbsoluteCells[col][row];
	 if (!ACell->IsEmpty())
	   AnalysisUnits->Add(ACell->Text);
	 }
   ch_AnalUnit->Items->AddStrings(AnalysisUnits);
   delete AnalysisUnits;

   // fill Geochron popup
   TcxPopupEditProperties* PopupEditProperties = (TcxPopupEditProperties*)chGeochron->Properties;
   PopupEditProperties->PopupHeight = 46 + 14*min(12, GeochronList->Count());
   ProfGridGeochron->Align = alTop;
   ProfGridGeochron->RowCount = GeochronList->Count() + 1;
   WideString WideValue;
   for (int i=0, row=1; i<GeochronList->Count(); i++, row++) {
	 GEOCHRON& Date = GeochronList->Dates[i];
	 vector<GEOCHRON>::pointer DatePtr = &GeochronList->Dates[i];
	 ProfGridGeochron->AbsoluteCells[1][row]->Value = Date.LabNumber;
	 ProfGridGeochron->AbsoluteCells[1][row]->CustomData = (int)DatePtr;  // pointer to geochron
	 if (!Date.Depth.IsEmpty())
	   ProfGridGeochron->AbsoluteCells[2][row]->Value = Date.Depth;
	 else
	   ProfGridGeochron->AbsoluteCells[2][row]->Value = Unassigned();

	 if (!Date.Age.IsEmpty()) {
	   if (Date.GreaterThan) {
		 WideValue = WideString(">" + VarToStr(Date.Age));
		 ProfGridGeochron->AbsoluteCells[3][row]->Value = WideValue;
		 }
	   else
		 ProfGridGeochron->AbsoluteCells[3][row]->Value = Date.Age;
	   }
	 else
	   ProfGridGeochron->AbsoluteCells[3][row]->Value = Unassigned();

	 if (!Date.GreaterThan && !Date.ErrorOlder.IsEmpty() && !Date.ErrorYounger.IsEmpty()) {
	   if (Date.ErrorOlder == Date.ErrorYounger)
		 ProfGridGeochron->AbsoluteCells[4][row]->Value = Date.ErrorOlder;
	   else {
		 WideValue = WideString("+" + VarToStr(Date.ErrorOlder) + "/-" +
								VarToStr(Date.ErrorOlder));
         ProfGridGeochron->AbsoluteCells[4][row]->Value = WideValue;
         }
       }
     else
	   ProfGridGeochron->AbsoluteCells[4][row]->Value = Unassigned();
     }
   FocusControl(cxGrid3);
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::amPreparerPropertiesEditValueToStates(
      TObject *Sender, const Variant &AValue, TcxCheckStates &ACheckStates)
{
   // Enables you to convert the edit value into a check state manually.
   // Retrieve preparers for record and check boxes

   TcxCustomGridRecord *AFocusedRecord = cxGrid3TableView1->Controller->FocusedRecord;
   if (!AFocusedRecord) return;

   if (AFocusedRecord->RecordIndex == -1) {
     if (PrepCheckStates.size() == 0) {
       for (int i=0; i<ACheckStates.Length; i++)
         ACheckStates[i] = cbsUnchecked;
       }
     }
   else {
     if (ContactList->Count == ACheckStates.Length) {
	   AGEMODEL* AgeModel = AgeModelList->AgeModels[AFocusedRecord->RecordIndex];
       for (int i=0; i<ContactList->Count; i++) {
		 vector<CONTACT*>::iterator begin = AgeModel->Preparers.begin();
		 vector<CONTACT*>::iterator end = AgeModel->Preparers.end();
		 if (find(begin, end, ContactList->Contacts[i]) != end)
		   ACheckStates[i] = cbsChecked;
         else
           ACheckStates[i] = cbsUnchecked;
         }
       }
     }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::amPreparerPropertiesStatesToEditValue(
      TObject *Sender, const TcxCheckStates ACheckStates, Variant &AValue)
{
   TcxCustomGridRecord *AFocusedRecord = cxGrid3TableView1->Controller->FocusedRecord;
   if (!AFocusedRecord) return;

   if (AFocusedRecord->RecordIndex == -1) {
     PrepCheckStates.clear();
     bool FirstPreparer = true;
     for (int i=0; i<ContactList->Count; i++) {
       PrepCheckStates.push_back(ACheckStates[i] == cbsChecked);
       if (ACheckStates[i]) {
         CONTACT* Contact = ContactList->Contacts[i];
         if (FirstPreparer) {
           NewRecordPrepText = Contact->ShortContactName;
           FirstPreparer = false;
           }
         else
           NewRecordPrepText += (";" + Contact->ShortContactName);
         }
       }
     }
   else {
     AGEMODEL* AgeModel = AgeModelList->AgeModels[AFocusedRecord->RecordIndex];
     AgeModel->Preparers.clear();
	 AgeModel->PreparersComboBoxText.SetLength(0);
     for (int i=0; i<ContactList->Count; i++) {
       if (ACheckStates[i] == cbsChecked) {
         CONTACT* Contact = ContactList->Contacts[i];
		 AgeModel->Preparers.push_back(Contact);
		 if (AgeModel->Preparers.size() == 1)
           AgeModel->PreparersComboBoxText = Contact->ShortContactName;
         else
           AgeModel->PreparersComboBoxText += (";" + Contact->ShortContactName);
         }
       }
     }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::amPreparerGetDisplayText(
      TcxCustomGridTableItem *Sender, TcxCustomGridRecord *ARecord,
	  UnicodeString &AText)
{
   // display preparer info
   if (!ARecord) return;

   if (ARecord->RecordIndex == -1)
	 AText = NewRecordPrepText;
   else {
	 if (ARecord->RecordIndex > -1) {
	   AGEMODEL* AgeModel = AgeModelList->AgeModels[ARecord->RecordIndex];
	   AText = AgeModel->PreparersComboBoxText;
       }
     }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxGrid3TableView1DataControllerAfterPost(
      TcxCustomDataController *ADataController)
{
   TcxCustomGridRecord *AFocusedRecord = cxGrid3TableView1->Controller->FocusedRecord;
   if (!AFocusedRecord) return;
   if (AFocusedRecord->RecordIndex == -1) {
	 AGEMODEL* AgeModel = (AGEMODEL*)AgeModelList->Last();
	 for (unsigned int i=0; i<PrepCheckStates.size(); i++) {
	   CONTACT* Contact = ContactList->Contacts[i];
	   if (PrepCheckStates[i]) {
		 AgeModel->Preparers.push_back(Contact);
		 if (AgeModel->Preparers.size() == 1)
		   AgeModel->PreparersComboBoxText = Contact->ShortContactName;
		 else
		   AgeModel->PreparersComboBoxText += (";" + Contact->ShortContactName);
		 }
	   }
	 PrepCheckStates.clear();
	 NewRecordPrepText.SetLength(0);
	 ADataController->Values[-1][amPreparer->Index] = "";
	 }
   else if (tiLicense->Type() == verNEOTOMASTEWARD) {
	 AGEMODEL* AgeModel = AgeModelList->AgeModels[AFocusedRecord->RecordIndex];
	 if (AgeModel->NeotomaChronologyID > -1) {  // a downloaded dataset
	   UnicodeString msg = L"Update metadata in Neotoma for chronology " + IntToStr(AgeModel->NeotomaChronologyID) +
		 L" «" + AgeModel->ChronologyName + L"?";
	   if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes) {
		 UpdateNeotomaChronology(AgeModel);
		 }
	   }
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::amNamePropertiesEditValueChanged(
      TObject *Sender)
{
   TcxCustomGridRecord *AFocusedRecord = cxGrid3TableView1->Controller->FocusedRecord;
   if (!AFocusedRecord) return;

   if (AFocusedRecord->RecordIndex == -1)
     AFocusedRecord->Values[amDefault->Index] = false;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxGrid3TableView1DataControllerBeforePost(
      TcxCustomDataController *ADataController)
{
   TcxCustomGridRecord *AFocusedRecord = cxGrid3TableView1->Controller->FocusedRecord;
   if (AFocusedRecord->RecordIndex == -1) {
     int NextChronNumber = AgeModelList->Count + 1;
     for (int n=1; n<=AgeModelList->Count; n++) {
       bool found = false;
       for (int i=0; i<AgeModelList->Count; i++) {
         AGEMODEL* AgeModel = AgeModelList->AgeModels[i];
         if (AgeModel->ChronNumber == n) {
           found = true;
           break;
           }
         }
       if (!found) {
         NextChronNumber = n;
         break;
		 }
       }
     ADataController->Values[-1][amChronNo->Index] = NextChronNumber;
     }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::CheckBox2Click(TObject *Sender)
{
   TcxGridColumnOptions* Options = amChronNo->Options;
   Options->Focusing = !CheckBox2->Checked;
   Options->Editing = !CheckBox2->Checked;
}
//---------------------------------------------------------------------------





