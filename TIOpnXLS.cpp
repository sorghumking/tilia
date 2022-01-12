//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TIOpnXLS.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxCheckListBox"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxButtons"
#pragma resource "*.dfm"
TImportExcelForm *ImportExcelForm;
//---------------------------------------------------------------------------
__fastcall TImportExcelForm::TImportExcelForm(TStringList* Sheets, TComponent* Owner)
        : TForm(Owner)
{
   for (int i=0; i<Sheets->Count; i++) {
	 TcxCheckListBoxItem* Item = cxCheckListBox1->Items->Add();
	 Item->Text = Sheets->Strings[i];
	 if (Item->Text == "Data")
	   Item->Checked = true;
	 }
}
//---------------------------------------------------------------------------

// uncheck all boxes except one being checked
void __fastcall TImportExcelForm::cxCheckListBox1Click(TObject *Sender)
{
   for (int i=0; i<cxCheckListBox1->Count; i++) {
     if (i != cxCheckListBox1->ItemIndex)
       cxCheckListBox1->Items->Items[i]->Checked = false;
     }
}
//---------------------------------------------------------------------------

// Ok button
void __fastcall TImportExcelForm::cxButton1Click(TObject *Sender)
{
   SheetName = L"";
   for (int i=0; i<cxCheckListBox1->Count; i++) {
	 if (cxCheckListBox1->Items->Items[i]->Checked) {
	   TcxCheckListBoxItem* Item = cxCheckListBox1->Items->Items[i];
	   SheetName = Item->Text;
	   break;
	   }
	 }
   NullToZero = CheckBox1->Checked;
}
//---------------------------------------------------------------------------

