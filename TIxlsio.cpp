//---------------------------------------------------------------------------
#include <vcl.h>
#include "pch.h"
#pragma hdrstop

#include "TIxlsio.h"
//#include "olexlsf_TLB.h"
//#ifndef TIExpXLSH
//#include "TIExpXLS.h"
//#endif
#ifndef TIOpnXLSH
#include "TIOpnXLS.h"
#endif

//---------------------------------------------------------------------------

#pragma package(smart_init)

//---------------------------------------------------------------------------

bool TTilSpreadSheetForm::OpenXLS(UnicodeString& xlsPathName)
{
   TStringList* Sheets = AdvStringGridXLS->GetXLSSheets(xlsPathName);
   TImportExcelForm* ExcelForm = new TImportExcelForm(Sheets, this);
   int result = ExcelForm->ShowModal();
   UnicodeString SheetName = ExcelForm->GetSheetName();
   bool NullToZero = ExcelForm->GetNullToZero();
   delete ExcelForm;
   if (result == mrCancel || SheetName.IsEmpty()) return false;
   Screen->Cursor = crHourGlass;
   AdvStringGridXLS->LoadFromXLSSheet(xlsPathName, SheetName);

   ProfGrid1->DisableControls();
   ProfGrid1->SpreadsheetEnabled = false;
   UnicodeString DatasetType = AdvStringGridXLS->Cells[0][0];
   //if (ComboBox9->Items->IndexOf(DatasetType) > -1)
   if (cxComboBox2->Properties->Items->IndexOf(DatasetType) > -1)
	 Datasets[0].DatasetType = AdvStringGridXLS->Cells[0][0];
   for (int arow=0, irow=1; arow<2; arow++, irow++) {
	 for (int acol=7, icol=8; acol<AdvStringGridXLS->ColCount; acol++, icol++) {
	   UnicodeString Text = AdvStringGridXLS->Cells[acol][arow];
	   double Value;
	   if (TryStrToFloat(Text, Value))
		 ProfGrid1->Cells[icol][irow]->Value = Value;
	   else
		 ProfGrid1->Cells[icol][irow]->Value = Text;
	   }
	 }
   for (int arow=2, irow=3; arow<AdvStringGridXLS->RowCount; arow++, irow++) {
	 for (int acol=0, icol=1; acol<AdvStringGridXLS->ColCount; acol++, icol++) {
	   UnicodeString Text = AdvStringGridXLS->Cells[acol][arow];
	   if (NullToZero && Text.IsEmpty() && icol >= 8)
		 ProfGrid1->Cells[icol][irow]->Value = 0.0;
	   else {
		 double Value;
		 if (TryStrToFloat(Text, Value))
		   ProfGrid1->Cells[icol][irow]->Value = Value;
		 else
		   ProfGrid1->Cells[icol][irow]->Value = Text;
		 }
	   }
	 }
   //AddComment(int ACol, int ARow, AnsiString Comment)

   ProfGrid1->SpreadsheetEnabled = true;
   ProfGrid1->EnableControls();
   SpreadSheetChanged = true;
   Screen->Cursor = crDefault;

   return true;
}
//---------------------------------------------------------------------------


