//---------------------------------------------------------------------------
#include <vcl.h>
#include "pch.h"
#pragma hdrstop

#include "TGPrint.h"
#ifndef TGParentH
#include "TGParent.h"
#endif
#ifndef TGDiagrm
#include "TGDiagrm.h"
#endif
#ifndef TGHelpH
#include "TGHelp.h"
#endif

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxMaskEdit"
#pragma link "cxSpinEdit"
#pragma link "cxTextEdit"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"
TPrintForm *PrintForm;

//---------------------------------------------------------------------------
__fastcall TPrintForm::TPrintForm(TComponent* Owner)
        : TForm(Owner)
{
  TGDiagram = (TTGDiagram *)ParentForm->ActiveMDIChild;
  DiagramHeight = TGDiagram->Picture->PrintOptions.DiagramHeight;
  YaxisHeight = TGDiagram->Picture->PrintOptions.YaxisHeight;
  Overlap = (int)TGDiagram->Picture->PrintOptions.Overlap;
  PrintButtonClicked = false;
}
//---------------------------------------------------------------------------

void __fastcall TPrintForm::FormActivate(TObject *Sender)
{
   int option = TGDiagram->Picture->PrintOptions.Option;
   RadioGroup1->ItemIndex = option;
   RadioGroup2->ItemIndex = TGDiagram->Picture->PrintOptions.Units;
   RadioGroup3->ItemIndex = TGDiagram->Picture->PrintOptions.Orientation;
   cxSpinEdit1->Value = DiagramHeight;
   cxSpinEdit2->Value = YaxisHeight;
   cxSpinEdit3->Value = Overlap;
   switch (option) {
     case 0:
       cxSpinEdit1->Enabled = false;
       cxSpinEdit2->Enabled = false;
       cxSpinEdit3->Enabled = false;
       break;
     case 1:
       cxSpinEdit1->Enabled = false;
       cxSpinEdit2->Enabled = false;
       cxSpinEdit3->Enabled = true;
       break;
     case 2:
       cxSpinEdit1->Enabled = true;
       cxSpinEdit2->Enabled = false;
       cxSpinEdit3->Enabled = true;
       break;
     case 3:
       cxSpinEdit1->Enabled = false;
       cxSpinEdit2->Enabled = true;
       cxSpinEdit3->Enabled = true;
       break;
     }

   ChangeEdit = true;
}
//---------------------------------------------------------------------------

void __fastcall TPrintForm::PrintButtonClick(TObject *Sender)
{
  PrintButtonClicked = true;
}
//---------------------------------------------------------------------------

void __fastcall TPrintForm::cxSpinEdit1PropertiesEditValueChanged(
      TObject *Sender)
{
   DiagramHeight = cxSpinEdit1->EditValue;
}
//---------------------------------------------------------------------------

void __fastcall TPrintForm::cxSpinEdit2PropertiesEditValueChanged(
      TObject *Sender)
{
   YaxisHeight = cxSpinEdit2->EditValue;
}
//---------------------------------------------------------------------------

void __fastcall TPrintForm::cxSpinEdit3PropertiesEditValueChanged(
      TObject *Sender)
{
   Overlap = cxSpinEdit3->EditValue;
}
//---------------------------------------------------------------------------

void __fastcall TPrintForm::RadioGroup1Click(TObject *Sender)
{
   switch (RadioGroup1->ItemIndex) {
     case 0:
       cxSpinEdit1->Enabled = false;
       cxSpinEdit2->Enabled = false;
       cxSpinEdit3->Enabled = false;
       break;
     case 1:
       cxSpinEdit1->Enabled = false;
       cxSpinEdit2->Enabled = false;
       cxSpinEdit3->Enabled = true;
       break;
     case 2:
       cxSpinEdit1->Enabled = true;
       cxSpinEdit2->Enabled = false;
       cxSpinEdit3->Enabled = true;
       break;
     case 3:
       cxSpinEdit1->Enabled = false;
       cxSpinEdit2->Enabled = true;
       cxSpinEdit3->Enabled = true;
       break;
     }
}
//---------------------------------------------------------------------------

void __fastcall TPrintForm::cxSpinEdit3PropertiesValidate(TObject *Sender,
      Variant &DisplayValue, TCaption &ErrorText, bool &Error)
{
   if (Error && ErrorText == "Value out of bounds") {
     DisplayValue = 0;
     Error = false;
     ErrorText = "";
     }     
}
//---------------------------------------------------------------------------

void __fastcall TPrintForm::cxSpinEdit1PropertiesValidate(TObject *Sender,
      Variant &DisplayValue, TCaption &ErrorText, bool &Error)
{
   if (Error && ErrorText == "Value out of bounds") {
     DisplayValue = 0;
     Error = false;
     ErrorText = "";
     }     
}
//---------------------------------------------------------------------------

void __fastcall TPrintForm::cxSpinEdit2PropertiesValidate(TObject *Sender,
      Variant &DisplayValue, TCaption &ErrorText, bool &Error)
{
   if (Error && ErrorText == "Value out of bounds") {
     DisplayValue = 0;
     Error = false;
     ErrorText = "";
     }     
}
//---------------------------------------------------------------------------

void __fastcall TPrintForm::HelpButtonClick(TObject *Sender)
{
   Application->HelpContext(IDH_Printing);
}
//---------------------------------------------------------------------------

bool __fastcall TPrintForm::FormHelp(WORD Command, int Data, bool &CallHelp)
{
   return true;
}
//---------------------------------------------------------------------------

