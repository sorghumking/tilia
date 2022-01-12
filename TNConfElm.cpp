//---------------------------------------------------------------------------

#include <vcl.h>
#include "pch.h"
#pragma hdrstop

#include "TNConfElm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxLabel"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxTextEdit"
#pragma link "cxListBox"
#pragma link "cxButtons"
#pragma resource "*.dfm"
TConfirmElementUploadForm *ConfirmElementUploadForm;
//---------------------------------------------------------------------------
__fastcall TConfirmElementUploadForm::TConfirmElementUploadForm(UnicodeString Element,
	vector<UnicodeString>& TaxaNames, TComponent* Owner) : TForm(Owner)
{
   cxTextEdit1->Text = Element;
   for (unsigned int i=0; i<TaxaNames.size(); i++)
	 cxListBox1->Items->Add(TaxaNames[i]);
   cxListBox1->Sorted = true;
}
//---------------------------------------------------------------------------

// upload button
void __fastcall TConfirmElementUploadForm::cxButton1Click(TObject *Sender)
{
   Beep();
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

__fastcall TConfirmUnitsUploadForm::TConfirmUnitsUploadForm(UnicodeString Units,
	vector<UnicodeString>& TaxaNames, TComponent* Owner) :
	TConfirmElementUploadForm(Units, TaxaNames, Owner)
{
   cxLabel1->Caption = L"Variable Units:";
   UnicodeString msg = L"The taxa listed below have these variable units. ";
   msg += L"If these units are valid, click the Upload button.";
   cxLabel2->Caption = msg;
}
//---------------------------------------------------------------------------

__fastcall TConfirmContextUploadForm::TConfirmContextUploadForm(UnicodeString Context,
	vector<UnicodeString>& TaxaNames, TComponent* Owner) :
	TConfirmElementUploadForm(Context, TaxaNames, Owner)
{
   cxLabel1->Caption = L"Variable Context:";
   UnicodeString msg = L"The taxa listed below have this variable context. ";
   msg += L"If this context is valid, click the Upload button.";
   cxLabel2->Caption = msg;
}
//---------------------------------------------------------------------------
