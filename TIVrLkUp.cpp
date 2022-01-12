//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TIVrLkUp.h"
#ifndef TIGlobalsH
#include "TIGlobals.h"
#endif
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxLabel"
#pragma link "cxTextEdit"
#pragma link "cxGroupBox"
#pragma link "cxRadioGroup"
#pragma resource "*.dfm"
TVarLookupForm *VarLookupForm;
TShortVarLookupForm *ShortVarLookupForm;
//---------------------------------------------------------------------------
__fastcall TVarLookupForm::TVarLookupForm(TComponent* Owner)
		: TForm(Owner)
{
   UnicodeString LookupPath, TaxaFile, ElementsFile, UnitsFile, ContextFile, TaphonomyFile;

   if (!tiGlobals->MyLookupPath.IsEmpty())
	 LookupPath = tiGlobals->MyLookupPath;
   else
	 LookupPath = tiGlobals->AppDataTiliaLookupPath;

   // ExtractFileName is used because formerly the entire path was saved in the registry
   if (!tiGlobals->TaxaFile.IsEmpty())
	 TaxaFile = LookupPath + ExtractFileName(tiGlobals->TaxaFile);
   if (!tiGlobals->ElementsFile.IsEmpty())
	 ElementsFile = LookupPath + ExtractFileName(tiGlobals->ElementsFile);
   if (!tiGlobals->UnitsFile.IsEmpty())
	 UnitsFile = LookupPath + ExtractFileName(tiGlobals->UnitsFile);
   if (!tiGlobals->ContextFile.IsEmpty())
	 ContextFile = LookupPath + ExtractFileName(tiGlobals->ContextFile);
   if (!tiGlobals->TaphonomyFile.IsEmpty())
	 TaphonomyFile = LookupPath + ExtractFileName(tiGlobals->TaphonomyFile);

   if (TaxaFile.IsEmpty())
	 TaxaFile = LookupPath + L"NeotomaPollenTaxa.xml";
   if (FileExists(TaxaFile))
	 cxTextEdit1->Text = TaxaFile;

   if (ElementsFile.IsEmpty())
	 ElementsFile = LookupPath + L"NeotomaVariableModifiers.xml";
   if (FileExists(ElementsFile))
	 cxTextEdit2->Text = ElementsFile;

   if (UnitsFile.IsEmpty())
	 UnitsFile = LookupPath + L"NeotomaVariableModifiers.xml";
   if (FileExists(UnitsFile))
	 cxTextEdit3->Text = UnitsFile;

   if (ContextFile.IsEmpty())
	 ContextFile = LookupPath + L"NeotomaVariableModifiers.xml";
   if (FileExists(ContextFile))
	 cxTextEdit4->Text = ContextFile;

   if (TaphonomyFile.IsEmpty())
	 TaphonomyFile = LookupPath + L"NeotomaVariableModifiers.xml";
   if (FileExists(TaphonomyFile))
	 cxTextEdit5->Text = TaphonomyFile;

   cxRadioGroup1->ItemIndex = 1;
   cxRadioGroup1->Enabled = false;
   if (SameText(ElementsFile, UnitsFile)) {
	 if (SameText(ElementsFile, ContextFile)) {
	   if (SameText(ElementsFile, TaphonomyFile)) {
		 cxLabel2->Caption = L"Modifiers:";
		 cxButton5->Visible = false;
		 cxTextEdit5->Visible = false;
		 cxLabel5->Visible = false;
		 cxButton4->Visible = false;
		 cxTextEdit4->Visible = false;
		 cxLabel4->Visible = false;
		 cxButton3->Visible = false;
		 cxTextEdit3->Visible = false;
		 cxLabel3->Visible = false;
		 cxRadioGroup1->ItemIndex = 0;
		 cxRadioGroup1->Enabled = true;
		 }
	   }
	 }
}
//---------------------------------------------------------------------------

void __fastcall TVarLookupForm::cxButton1Click(TObject *Sender)
{
  UnicodeString TaxaFile;

  TaxaFile = cxTextEdit1->Text;
  if (!TaxaFile.IsEmpty()) {
	if (FileExists(TaxaFile)) {
	  OpenDialog1->FileName = TaxaFile;
	  OpenDialog1->InitialDir = ExtractFilePath(TaxaFile);
	  }
	}
  if (OpenDialog1->Execute()) {
	TaxaFile = OpenDialog1->FileName;
	UnicodeString FileExt = ExtractFileExt(TaxaFile);
	if (FileExt.CompareIC(".xml") != 0) {
	  cxTextEdit1->Text = "";
	  MessageDlg("Taxa file must be *.xml", mtError, TMsgDlgButtons() << mbOK, 0);
	  }
	else if (!FileExists(TaxaFile)) {
	  cxTextEdit1->Text = "";
	  MessageDlg("File <" + TaxaFile + "> does not exist.", mtError, TMsgDlgButtons() << mbOK, 0);
	  }
	else
	  cxTextEdit1->Text = TaxaFile;
	}
}
//---------------------------------------------------------------------------

void __fastcall TVarLookupForm::cxButton2Click(TObject *Sender)
{
   UnicodeString ElementsFile;

  ElementsFile = cxTextEdit2->Text;
  if (!ElementsFile.IsEmpty()) {
	if (FileExists(ElementsFile)) {
	  OpenDialog1->FileName = ElementsFile;
	  OpenDialog1->InitialDir = ExtractFilePath(ElementsFile);
	  }
	}
  if (OpenDialog1->Execute()) {
	ElementsFile = OpenDialog1->FileName;
	UnicodeString FileExt = ExtractFileExt(ElementsFile);
	if (FileExt.CompareIC(".xml") != 0) {
	  cxTextEdit2->Text = "";
	  MessageDlg("Variable elements file must be *.xml", mtError, TMsgDlgButtons() << mbOK, 0);
	  }
	else if (!FileExists(ElementsFile)) {
	  cxTextEdit2->Text = "";
	  MessageDlg("File <" + ElementsFile + "> does not exist.", mtError, TMsgDlgButtons() << mbOK, 0);
	  }
	else
	  cxTextEdit2->Text = ElementsFile;
    }
}
//---------------------------------------------------------------------------

void __fastcall TVarLookupForm::cxButton3Click(TObject *Sender)
{
  UnicodeString UnitsFile;

  UnitsFile = cxTextEdit3->Text;
  if (!UnitsFile.IsEmpty()) {
	if (FileExists(UnitsFile)) {
	  OpenDialog1->FileName = UnitsFile;
	  OpenDialog1->InitialDir = ExtractFilePath(UnitsFile);
	  }
	}
  if (OpenDialog1->Execute()) {
	UnitsFile = OpenDialog1->FileName;
	UnicodeString FileExt = ExtractFileExt(UnitsFile);
	if (FileExt.CompareIC(".xml") != 0) {
	  cxTextEdit3->Text = "";
	  MessageDlg("Variable elements file must be *.xml", mtError, TMsgDlgButtons() << mbOK, 0);
	  }
	else if (!FileExists(UnitsFile)) {
	  cxTextEdit3->Text = "";
	  MessageDlg("File <" + UnitsFile + "> does not exist.", mtError, TMsgDlgButtons() << mbOK, 0);
	  }
	else
	  cxTextEdit3->Text = UnitsFile;
	}
}
//---------------------------------------------------------------------------

void __fastcall TVarLookupForm::cxButton4Click(TObject *Sender)
{
  UnicodeString ContextsFile;

  ContextsFile = cxTextEdit4->Text;
  if (!ContextsFile.IsEmpty()) {
	if (FileExists(ContextsFile)) {
	  OpenDialog1->FileName = ContextsFile;
	  OpenDialog1->InitialDir = ExtractFilePath(ContextsFile);
	  }
	}
  if (OpenDialog1->Execute()) {
	ContextsFile = OpenDialog1->FileName;
	UnicodeString FileExt = ExtractFileExt(ContextsFile);
	if (FileExt.CompareIC(".xml") != 0) {
	  cxTextEdit4->Text = "";
	  MessageDlg("Variable contexts file must be *.xml", mtError, TMsgDlgButtons() << mbOK, 0);
	  }
	else if (!FileExists(ContextsFile)) {
	  cxTextEdit4->Text = "";
	  MessageDlg("File <" + ContextsFile + "> does not exist.", mtError, TMsgDlgButtons() << mbOK, 0);
	  }
	else
	  cxTextEdit4->Text = ContextsFile;
	}
}
//---------------------------------------------------------------------------

void __fastcall TVarLookupForm::cxButton5Click(TObject *Sender)
{
UnicodeString TaphonomyFile;

  TaphonomyFile = cxTextEdit5->Text;
  if (!TaphonomyFile.IsEmpty()) {
	if (FileExists(TaphonomyFile)) {
	  OpenDialog1->FileName = TaphonomyFile;
	  OpenDialog1->InitialDir = ExtractFilePath(TaphonomyFile);
	  }
	}
  if (OpenDialog1->Execute()) {
	TaphonomyFile = OpenDialog1->FileName;
	UnicodeString FileExt = ExtractFileExt(TaphonomyFile);
	if (FileExt.CompareIC(".xml") != 0) {
	  cxTextEdit5->Text = "";
	  MessageDlg("Variable contexts file must be *.xml", mtError, TMsgDlgButtons() << mbOK, 0);
	  }
	else if (!FileExists(TaphonomyFile)) {
	  cxTextEdit5->Text = "";
	  MessageDlg("File <" + TaphonomyFile + "> does not exist.", mtError, TMsgDlgButtons() << mbOK, 0);
	  }
	else
	  cxTextEdit5->Text = TaphonomyFile;
	}
}
//---------------------------------------------------------------------------

void __fastcall TVarLookupForm::cxRadioGroup1Click(TObject *Sender)
{
   switch (cxRadioGroup1->ItemIndex) {
	 case 0:  // short form
	   cxButton5->Visible = false;
	   cxTextEdit5->Visible = false;
	   cxLabel5->Visible = false;
	   cxButton4->Visible = false;
	   cxTextEdit4->Visible = false;
	   cxLabel4->Visible = false;
	   cxButton3->Visible = false;
	   cxTextEdit3->Visible = false;
	   cxLabel3->Visible = false;
	   cxLabel2->Caption = L"Modifiers:";
	   break;
	 case 1:  // long form
	   cxLabel3->Visible = true;
	   cxTextEdit3->Visible = true;
	   cxButton3->Visible = true;
	   cxLabel4->Visible = true;
	   cxTextEdit4->Visible = true;
	   cxButton4->Visible = true;
	   cxLabel5->Visible = true;
	   cxTextEdit5->Visible = true;
	   cxButton5->Visible = true;
	   cxLabel2->Caption = L"Elements:";
	   break;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TVarLookupForm::cxTextEdit2PropertiesChange(TObject *Sender)
{
   bool enabled = false;
   if (SameText(cxTextEdit2->Text, cxTextEdit3->Text)) {
	 if (SameText(cxTextEdit2->Text, cxTextEdit4->Text)) {
	   if (SameText(cxTextEdit2->Text, cxTextEdit5->Text)) {
		 cxRadioGroup1->Enabled = true;
		 enabled = true;
		 }
	   }
	 }
   if (!enabled) {
     cxRadioGroup1->ItemIndex = 1;
	 cxRadioGroup1->Enabled = false;
     }
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

__fastcall TShortVarLookupForm::TShortVarLookupForm(TComponent* Owner)
		: TVarLookupForm(Owner)
{
   cxButton5->Visible = false;
   cxTextEdit5->Visible = false;
   cxLabel5->Visible = false;
   cxButton4->Visible = false;
   cxTextEdit4->Visible = false;
   cxLabel4->Visible = false;
   cxButton3->Visible = false;
   cxTextEdit3->Visible = false;
   cxLabel3->Visible = false;
}
//---------------------------------------------------------------------------


