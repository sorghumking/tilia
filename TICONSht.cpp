//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "cxPC.hpp"
#include "TICONSht.h"
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
TNewCONISSSheetForm *NewCONISSSheetForm;

//---------------------------------------------------------------------------
__fastcall TNewCONISSSheetForm::TNewCONISSSheetForm(TComponent* Owner)
        : TForm(Owner)
{
   Checking = false;
   MinimumValues = MV_NONE;
   MinValue = 0.0;
}
//---------------------------------------------------------------------------

void TNewCONISSSheetForm::SetGrids(TProfGrid* pg1, TProfGrid* pg2)
{
   ProfGrid1 = pg1;
   SourceGrid = pg1;

   if (pg2)                 // Percents worksheet exists
     ProfGrid2 = pg2;
   else {
     RadioGroup1->Items->Delete(1);
     CheckBox2->Visible = false;
     }
}
//---------------------------------------------------------------------------

void TNewCONISSSheetForm::GetGroups(TProfGrid* ProfGrid)
{
   UnicodeString GroupCode;
   UnicodeString VarCode;

   int RowCount = AbsContentRowCount(ProfGrid);
   TStringList* GroupList = new TStringList();
   GroupList->Sorted = true;
   int Index;
   for (int row=3; row<RowCount; row++) {
     VarCode = ProfGrid->AbsoluteCells[1][row]->Value;
     if (VarCode.SubString(1,1) == "#") continue;
     if (VarCode.SubString(1,3) == "SUM") continue;
     if (VarCode.SubString(1,4) == "SSUM") continue;
     GroupCode = ProfGrid->AbsoluteCells[7][row]->Value;
     if (GroupCode.IsEmpty())
       GroupCode = "(blank)";
     if (!GroupList->Find(GroupCode, Index))
       GroupList->Add(GroupCode);
     }
   for (int i=0; i<GroupList->Count; i++) {
     TcxCheckListBoxItem* Item = cxCheckListBox1->Items->Add();
     Item->Text = GroupList->Strings[i];
     }
   delete GroupList;
}
//---------------------------------------------------------------------------

int __fastcall TNewCONISSSheetForm::AbsContentRowCount(TProfGrid* ProfGrid)
{
   for (int i=ProfGrid->RowCount-1; i>0; i--)
     if (!ProfGrid->RowIsEmpty(i))
       return(i);
   return 0;
}
//---------------------------------------------------------------------------

void __fastcall TNewCONISSSheetForm::RadioGroup1Click(TObject *Sender)
{
   cxCheckListBox1->Clear();
   switch (RadioGroup1->ItemIndex) {
     case 0:
       GetGroups(ProfGrid1);
       SourceGrid = ProfGrid1;
       break;
     case 1:
       GetGroups(ProfGrid2);
       SourceGrid = ProfGrid2;
       break;
     };
}
//---------------------------------------------------------------------------

void __fastcall TNewCONISSSheetForm::CheckBox1Click(TObject *Sender)
{
   if (Checking) return;
   Checking = true;
   CheckBox2->Checked = false;
   if (CheckBox1->Checked) {
     LabeledEdit1->Color = clWindow;
     MinimumValues = MV_DATA;
     }
   else {
     LabeledEdit1->Color = clBtnFace;
     MinimumValues = MV_NONE;
     }
   Checking = false;
}
//---------------------------------------------------------------------------

void __fastcall TNewCONISSSheetForm::CheckBox2Click(TObject *Sender)
{
   if (Checking) return;
   Checking = true;
   CheckBox1->Checked = false;
   if (CheckBox2->Checked) {
     LabeledEdit1->Color = clWindow;
     MinimumValues = MV_PERCENTS;
     }
   else {
     LabeledEdit1->Color = clBtnFace;
     MinimumValues = MV_NONE;
     }
   Checking = false;
}
//---------------------------------------------------------------------------

// Ok button
void __fastcall TNewCONISSSheetForm::Button1Click(TObject *Sender)
{
   bool Selected = false;
   for (int i=0; i<cxCheckListBox1->Count; i++) {
     if (cxCheckListBox1->Selected[i]) {
       Selected = true;
       break;
       }
     }
   if (Selected) {
     if (CheckBox1->Checked || CheckBox2->Checked) {
       if (LabeledEdit1->Text.IsEmpty()) {
		 UnicodeString msg = (CheckBox1->Checked) ? "Data" : "Percents";
         int rv = MessageDlg(msg + " Sheet checked for Minimum Values, but no Minimum Value set.",
                  mtWarning, TMsgDlgButtons() << mbRetry << mbIgnore << mbCancel, 0);
         switch (rv) {
           case mrRetry:
             ModalResult = mrNone;
             break;
           case mrIgnore:
             MinimumValues = MV_NONE;
             break;
           case mrCancel:
             ModalResult = mrCancel;
             break;
           };
         }
       else {
         double dValue;
         if (TryStrToFloat(LabeledEdit1->Text, dValue))
           MinValue = dValue;
         else {
           if (MessageDlg("Minimum Value is invalid.", mtWarning,
               TMsgDlgButtons() << mbRetry << mbCancel, 0) == mrRetry)
             ModalResult = mrNone;
           else
             ModalResult = mrCancel;
           }
         }
       }
     }
   else {
     if (MessageDlg("No groups selected.", mtWarning,
         TMsgDlgButtons() << mbRetry << mbCancel, 0) == mrRetry)
       ModalResult = mrNone;
     else
       ModalResult = mrCancel;
     }
}
//---------------------------------------------------------------------------

