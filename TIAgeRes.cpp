//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TIAgeRes.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "ProfGrid"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxMaskEdit"
#pragma link "cxSpinEdit"
#pragma link "cxTextEdit"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxButtons"
#pragma resource "*.dfm"
TAgeModelResultsForm *AgeModelResultsForm;
//---------------------------------------------------------------------------
__fastcall TAgeModelResultsForm::TAgeModelResultsForm(TComponent* Owner)
		: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TAgeModelResultsForm::cxSpinEdit1PropertiesChange(
      TObject *Sender)
{
   int dec = cxSpinEdit1->Value;
   WideString Format = "0.";
   for (int i=0; i<dec; i++)
     Format += "0";

   Screen->Cursor = crHourGlass;
   ProfGrid1->DisableControls();
   ProfGrid1->SpreadsheetEnabled = false;
   for (int i=1; i<ProfGrid1->RowCount; i++)
     ProfGrid1->Cells[2][i]->Format = Format;
   ProfGrid1->SpreadsheetEnabled = true;
   ProfGrid1->EnableControls();
   Screen->Cursor = crDefault;
}
//---------------------------------------------------------------------------

