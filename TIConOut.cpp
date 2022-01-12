//---------------------------------------------------------------------------

#include <vcl.h>
#include "pch.h"
#pragma hdrstop

#include "TIConOut.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TCONISSOutput *CONISSOutput;
//---------------------------------------------------------------------------
__fastcall TCONISSOutput::TCONISSOutput(TComponent* Owner)
        : TForm(Owner)
{
   ConissForm = (TConissForm*)Owner;
}
//---------------------------------------------------------------------------

void __fastcall TCONISSOutput::Saveas1Click(TObject *Sender)
{
   int pos;
   // set PlainText = true for txt format, false for rtf format
   SaveDialog1->FileName = OutputFileName + ".rtf";
   SaveDialog1->Title = "Save As";

   if (SaveDialog1->Execute()) {
	 UnicodeString PathName = SaveDialog1->FileName;
	 if ((pos = PathName.Pos(".")) > 0)
       PathName.SetLength(pos-1);

     if (SaveDialog1->FilterIndex == 1) {
       PathName += ".rtf";
       RichEdit1->PlainText = false;
       RichEdit1->Lines->SaveToFile(PathName);
       }
     else if (SaveDialog1->FilterIndex == 2) {
       PathName += ".txt";
       RichEdit1->PlainText = true;
       RichEdit1->Lines->SaveToFile(PathName);
       }
     else
	   MessageDlg("File extension not valid", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
     }
}
//---------------------------------------------------------------------------

void __fastcall TCONISSOutput::Print1Click(TObject *Sender)
{
   RichEdit1->Print("CONISS Results");
}
//---------------------------------------------------------------------------

void __fastcall TCONISSOutput::PrintSetup1Click(TObject *Sender)
{
   PrinterSetupDialog1->Execute();
}
//---------------------------------------------------------------------------

void __fastcall TCONISSOutput::Close1Click(TObject *Sender)
{
   Close();
   ConissForm->Close();
}
//---------------------------------------------------------------------------

void __fastcall TCONISSOutput::FormClose(TObject *Sender,
      TCloseAction &Action)
{
   ConissForm->Close();
}
//---------------------------------------------------------------------------

