//---------------------------------------------------------------------------
#include "pch.h"
#include <vcl.h>
#pragma hdrstop

#include "TIConcFm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxCheckListBox"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"
TConcForm *ConcForm;
//---------------------------------------------------------------------------
__fastcall TConcForm::TConcForm(TComponent* Owner)
        : TForm(Owner)
{
   TSSForm = (TTilSpreadSheetForm*)Owner;

   UnicodeString GroupCode;
   UnicodeString VarCode;
   UnicodeString Element;

   int RowCount = TSSForm->AbsContentRowCount(TSSForm->ProfGrid1);
   TStringList* GroupList = new TStringList();
   TStringList* VarCodes = new TStringList();
   Elements = new TStringList();
   GroupList->Sorted = true;
   int Index;
   for (int row=3; row<=RowCount; row++) {
     VarCode = TSSForm->ProfGrid1->AbsoluteCells[1][row]->Value;

     if (VarCode.SubString(1,1) == "#") continue;
     if (VarCode.SubString(1,3) == "SUM") continue;
     if (VarCode.SubString(1,4) == "SSUM") continue;

     GroupCode = TSSForm->ProfGrid1->AbsoluteCells[7][row]->Value;
     Element = TSSForm->ProfGrid1->AbsoluteCells[3][row]->Value;

     if (GroupCode.IsEmpty())
       continue;
     if (GroupCode == "CONC") {
       VarCodes->Add(VarCode);
       Elements->Add(Element);
       }
     else if (!GroupList->Find(GroupCode, Index))
       GroupList->Add(GroupCode);
     }
   for (int i=0; i<GroupList->Count; i++) {
     TcxCheckListBoxItem* Item = cxCheckListBox1->Items->Add();
     Item->Text = GroupList->Strings[i];
     }
   for (int i=0; i<VarCodes->Count; i++) {
     TcxCheckListBoxItem* Item = cxCheckListBox2->Items->Add();
     Item->Text = VarCodes->Strings[i];
     Item = cxCheckListBox3->Items->Add();
     Item->Text = VarCodes->Strings[i];
     Item = cxCheckListBox4->Items->Add();
     Item->Text = VarCodes->Strings[i];
     Item = cxCheckListBox5->Items->Add();
     Item->Text = VarCodes->Strings[i];
     }

   delete GroupList;
   delete VarCodes;
}
//---------------------------------------------------------------------------

void __fastcall TConcForm::FormDestroy(TObject *Sender)
{
   delete Elements;
}
//---------------------------------------------------------------------------

void __fastcall TConcForm::Button3Click(TObject *Sender)
{
   for (int i=0; i<cxCheckListBox1->Count; i++)
     cxCheckListBox1->Items->Items[i]->Checked = true;
}
//---------------------------------------------------------------------------

// default codes
void __fastcall TConcForm::Button4Click(TObject *Sender)
{
   bool default1 = false;
   bool default2 = false;
   bool default3 = false;
   bool default4 = false;
   UnicodeString msg;

   int Method = RadioGroup1->ItemIndex;
   if (Method == 2) {
     for (int i=0; i<cxCheckListBox2->Count; i++) {
	   if (SameText(Elements->Strings[i], "volume") || SameText(Elements->Strings[i], "mass")) {
         cxCheckListBox2->Items->Items[i]->Checked = true;
         default1 = true;
         }
       }
     if (!default1)
       msg += "No default code found for Quantity of sample examined";
     }
   else {
     for (int i=0; i<cxCheckListBox2->Count; i++) {
	   if (SameText(Elements->Strings[i], "counted")) {
         cxCheckListBox2->Items->Items[i]->Checked = true;
         default1 = true;
         }
	   if (SameText(Elements->Strings[i], "volume") || SameText(Elements->Strings[i], "mass")) {
		 cxCheckListBox3->Items->Items[i]->Checked = true;
		 default2 = true;
		 }
	   if (SameText(Elements->Strings[i], "quantity added")) {
		 cxCheckListBox4->Items->Items[i]->Checked = true;
		 default3 = true;
		 }
	   if (Method == 0) {
		 if (SameText(Elements->Strings[i], "concentration")) {
           cxCheckListBox5->Items->Items[i]->Checked = true;
           default4 = true;
           }
         }
       }
     if (!default1)
       msg += "No default code found for Spike";
     if (!default2) {
       if (!msg.IsEmpty()) msg += "\n";
       msg += "No default code found for Quantiy of sample";
       }
     if (!default3) {
       if (!msg.IsEmpty()) msg += "\n";
       if (Method == 0)
         msg += "No default code found for Quantiy of spike medium";
       else if (Method == 1)
         msg += "No default code found for Quantiy of spike added to sample";
       }
     if (Method == 0 && !default4) {
       if (!msg.IsEmpty()) msg += "\n";
       msg += "No default code found for Concentration of spike medium";
       }
     }

   if (!msg.IsEmpty())
     MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
}
//---------------------------------------------------------------------------

// Ok button
void __fastcall TConcForm::Button1Click(TObject *Sender)
{
   bool OneChecked = false;
   for (int i=0; i<cxCheckListBox1->Count; i++) {
     if (cxCheckListBox1->Items->Items[i]->Checked) {
       OneChecked = true;
       break;
       }
     }
   if (!OneChecked) {
     int reply = MessageDlg("No groups selected.", mtWarning,
                 TMsgDlgButtons() << mbOK << mbCancel << mbRetry, 0);
     if (reply == mrCancel)
       ModalResult = mrCancel;
     else if (reply == mrRetry)
       ModalResult = mrNone;
     }
   TreatNulls = RadioGroup2->ItemIndex;
}
//---------------------------------------------------------------------------

void __fastcall TConcForm::RadioGroup1Click(TObject *Sender)
{
   switch (RadioGroup1->ItemIndex)
    {
    case 0:
      cxCheckListBox3->Visible = true;
      Label3->Visible = true;
      cxCheckListBox4->Visible = true;
      Label4->Visible = true;
      cxCheckListBox5->Visible = true;
      Label5->Visible = true;
      Label2->Caption = "Spike:";
      Label4->Caption = "Quantity of spike medium:";
      break;
    case 1:
      cxCheckListBox3->Visible = true;
      Label3->Visible = true;
      cxCheckListBox4->Visible = true;
      Label4->Visible = true;
      cxCheckListBox5->Visible = false;
      Label5->Visible = false;
      Label2->Caption = "Spike:";
      Label4->Caption = "Quantity of spike added to sample:";
      break;
    case 2:
      cxCheckListBox3->Visible = false;
      Label3->Visible = false;
      cxCheckListBox4->Visible = false;
      Label4->Visible = false;
      cxCheckListBox5->Visible = false;
      Label5->Visible = false;
      Label2->Caption = "Quantity of sample examined:";
      break;
    }
}
//---------------------------------------------------------------------------

