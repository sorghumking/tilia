//---------------------------------------------------------------------------

#include <vcl.h>
#include "pch.h"
#pragma hdrstop

#include "TITphChk.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDropDownEdit"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxLabel"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma resource "*.dfm"
TConvertTaphForm *ConvertTaphForm;
//---------------------------------------------------------------------------
__fastcall TConvertTaphForm::TConvertTaphForm(int row, UnicodeString DatasetType,
	set<UnicodeString>& Systems, TComponent* Owner) : TForm(Owner)
{
   UnicodeString Caption = cxLabel4->Caption;
   Caption += (L" " + IntToStr(row) + L".");
   cxLabel4->Caption = Caption;
   cxLabel1->Caption = L"Dataset Type: " + DatasetType;
   set<UnicodeString>::iterator itr;
   for (itr = Systems.begin(); itr != Systems.end(); itr++)
	 cxComboBox1->Properties->Items->Add(*itr);
   if (cxComboBox1->Properties->Items->Count > 0)
	 cxComboBox1->ItemIndex = 0;
}
//---------------------------------------------------------------------------
