//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TNSelItm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvCGrid"
#pragma link "AdvGrid"
#pragma link "AdvObj"
#pragma link "BaseGrid"
#pragma link "cxButtons"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "AdvCGrid"
#pragma link "AdvGrid"
#pragma link "AdvObj"
#pragma link "BaseGrid"
#pragma link "cxButtons"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "AdvCGrid"
#pragma link "AdvGrid"
#pragma link "AdvObj"
#pragma link "BaseGrid"
#pragma link "cxButtons"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "AdvCGrid"
#pragma link "AdvGrid"
#pragma link "AdvObj"
#pragma link "BaseGrid"
#pragma link "cxButtons"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"
TSelectItemForm *SelectItemForm;
TSelectSynonymTypeForm *SelectSynonymTypeForm;
//---------------------------------------------------------------------------

__fastcall TSelectItemForm::TSelectItemForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

// ok button
void __fastcall TSelectItemForm::cxButton1Click(TObject *Sender)
{
   return;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

__fastcall TSelectSynonymTypeForm::TSelectSynonymTypeForm(map<int,UnicodeString>& Items, TComponent* Owner)
	: TSelectItemForm(Owner)
{
   Caption = L"Synonym Type";
   Panel1->Caption = L"Select Synonym Type";
   AdvColumnGrid1->RowCount = Items.size() + 1;
   int row = 1;
   map<int,UnicodeString>::iterator itr;
   for (itr = Items.begin(); itr != Items.end(); itr++) {
	 AdvColumnGrid1->Cells[0][row] = itr->first;
	 AdvColumnGrid1->Cells[1][row++] = itr->second;
	 }
   AdvColumnGrid1->Row = 1;
}
//---------------------------------------------------------------------------

// ok button
void __fastcall TSelectSynonymTypeForm::cxButton1Click(TObject *Sender)
{
   SynonymTypeID = AdvColumnGrid1->Cells[0][AdvColumnGrid1->Row].ToInt();
   SynonymType = AdvColumnGrid1->Cells[1][AdvColumnGrid1->Row];
}
//---------------------------------------------------------------------------


