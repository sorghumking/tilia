//---------------------------------------------------------------------------
#include <vcl.h>
#include "pch.h"
#pragma hdrstop

#include <DateUtils.hpp>
//#include <Math.hpp>
#include <SysUtils.hpp>
//#include <sysvari.hpp>
#include <vector>


#include "TIloi.h"
#ifndef TISpreadH
#include "TISpread.h"
#endif
//#ifndef TGUtilsH
//#include "TGUtils.h"
//#endif

//---------------------------------------------------------------------------

#pragma package(smart_init)

LOISAMPLE::LOISAMPLE()
{
   Thickness = Variant::Empty();
   TempOrg = Variant::Empty();
   LOIOrg = Variant::Empty();
   TempCarb = Variant::Empty();
   LOICarb = Variant::Empty();
   BulkDens = Variant::Empty();
   DateAnal = Variant::Empty();
   Analyst = NULL;
}
//---------------------------------------------------------------------------

// --> LOI Tabsheet

void __fastcall TTilSpreadSheetForm::TabSheetLOIShow(TObject *Sender)
{
   // refill analyst list, which may have been changed
   TStringList* ItemList = AdvColumnGrid5->Columns->Items[9]->ComboItems;
   ItemList->Clear();

   for (int i=0; i<ContactList->Count; i++) {
	 CONTACT* Contact = ContactList->Contacts[i];
	 ItemList->AddObject(Contact->ShortContactName, (TObject*)Contact);
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxCheckComboBox3PropertiesCloseUp(
      TObject *Sender)
{
   loi.Investigators.clear();
   for (int i=0; i<cxCheckComboBox3->Properties->Items->Count; i++) {
	 if (cxCheckComboBox3->States[i] == cbsChecked) {
	   TcxCheckComboBoxItem* Item = cxCheckComboBox3->Properties->Items->Items[i];
	   CONTACT* Contact = (CONTACT*)Item->Tag;
	   loi.Investigators.push_back(Contact);
	   }
     }
   Button14->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxCheckComboBox3PropertiesInitPopup(
      TObject *Sender)
{
   UpdateContacts(cxCheckComboBox3, loi.Investigators);
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxCheckComboBox3PropertiesPopup(
      TObject *Sender)
{
   Button14->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::Button14Click(TObject *Sender)
{
   int ItemIndex = cxCheckComboBox3->ItemIndex;
   if (NewContact())
	 UpdateContacts(cxCheckComboBox3, loi.Investigators);
   FocusControl(cxCheckComboBox3);
   cxCheckComboBox3->DroppedDown = true;
   cxCheckComboBox3->ItemIndex = ItemIndex;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxCheckComboBox7PropertiesInitPopup(
      TObject *Sender)
{
   UpdatePublications(cxCheckComboBox7, loi.Publications);
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxCheckComboBox7PropertiesPopup(
      TObject *Sender)
{
   Button15->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxCheckComboBox7PropertiesCloseUp(
      TObject *Sender)
{
   loi.Publications.clear();
   for (int i=0; i<cxCheckComboBox7->Properties->Items->Count; i++) {
	 if (cxCheckComboBox7->States[i] == cbsChecked) {
	   TcxCheckComboBoxItem* Item = cxCheckComboBox7->Properties->Items->Items[i];
	   PUBLICATION *pub = (PUBLICATION*)Item->Tag;
	   loi.Publications.push_back(pub);
       }
     }
   Button15->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::Button15Click(TObject *Sender)
{
   NewPublication();
   UpdatePublications(cxCheckComboBox7, loi.Publications);
   FocusControl(cxCheckComboBox7);
   cxCheckComboBox7->DroppedDown = true;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::ComboBox7Exit(TObject *Sender)
{
   if (ProcessComboBox7OnExit) {
	 int temp = ExitLOITemp(ComboBox7, 3);      //AdvColumnGrid5
	 if (temp > -1 && AdvColumnGrid5->IsHiddenColumn(3)) {
	   for (int row = 1; row < AdvColumnGrid5->RowCount; row++) {
		 if (!AdvColumnGrid5->AllCells[4][row].IsEmpty())
		   AdvColumnGrid5->AllCells[3][row] = temp;
		 }
	   }
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::ComboBox7Change(TObject *Sender)
{
   ProcessComboBox7OnExit = !ComboBox7Clicked;
   ComboBox7Clicked = false;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::ComboBox7Click(TObject *Sender)
{
   int temp;

   ComboBox7Clicked = true;

   if (ComboBox7->ItemIndex == 1)    // Variable
	 AdvColumnGrid5->UnHideColumn(3);
   else {
	 AdvColumnGrid5->HideColumn(3);
	 temp = (ComboBox7->ItemIndex == 0) ? -1 : StrToInt(ComboBox7->Text);
	 for (int row = 1; row < AdvColumnGrid5->RowCount; row++) {
	   if (!AdvColumnGrid5->AllCells[4][row].IsEmpty())
		 AdvColumnGrid5->AllCells[3][row] = temp;
	   }
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::ComboBox8Exit(TObject *Sender)
{
   if (ProcessComboBox8OnExit) {
	 int temp = ExitLOITemp(ComboBox8, 5);
	 if (temp > -1 && AdvColumnGrid5->IsHiddenColumn(5)) {
	   for (int row = 1; row < AdvColumnGrid5->RowCount; row++) {
		 if (!AdvColumnGrid5->AllCells[6][row].IsEmpty())
		   AdvColumnGrid5->AllCells[5][row] = temp;
		 }
       }
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::ComboBox8Change(TObject *Sender)
{
   ProcessComboBox8OnExit = !ComboBox8Clicked;
   ComboBox8Clicked = false;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::ComboBox8Click(TObject *Sender)
{
   int temp;

   ComboBox8Clicked = true;

   if (ComboBox8->ItemIndex == 1)    // Variable
	 AdvColumnGrid5->UnHideColumn(5);
   else {
	 AdvColumnGrid5->HideColumn(5);
	 temp = (ComboBox8->ItemIndex == 0) ? -1 : StrToInt(ComboBox8->Text);
	 for (int row = 1; row < AdvColumnGrid5->RowCount; row++) {
	   if (!AdvColumnGrid5->AllCells[6][row].IsEmpty())
		 AdvColumnGrid5->AllCells[5][row] = temp;
	   }
	 }
}
//---------------------------------------------------------------------------

int __fastcall TTilSpreadSheetForm::ExitLOITemp(TComboBox* ComboBox, int col)
{
   int temp;

   if (SameText(ComboBox->Text, L"Variable")) {
	 ComboBox->ItemIndex = 1;
	 AdvColumnGrid5->UnHideColumn(col);
	 }
   else if (SameText(ComboBox->Text, L"Unknown")) {
	 ComboBox->ItemIndex = 0;
	 AdvColumnGrid5->HideColumn(col);
	 temp = -1;
	 }
   else if (ComboBox->Text.IsEmpty()) {
	 ComboBox->ItemIndex = -1;
	 AdvColumnGrid5->HideColumn(col);
	 temp = -1;
	 }
   else if (ComboBox->Items->IndexOf(ComboBox->Text) == -1) {
	 try {
		 bool done = false;
		 int temp1 = StrToInt(ComboBox->Text);
		 for (int i=2; i<ComboBox->Items->Count; i++) {
		   int temp2 = StrToInt(ComboBox->Items->Strings[i]);
		   if (temp1 < temp2) {
			 ComboBox->Items->Insert(i, ComboBox->Text);
			 done = true;
			 break;
			 }
		   }
		 if (!done)
		   ComboBox->Items->Add(ComboBox->Text);
		 ComboBox->ItemIndex = ComboBox->Items->IndexOf(ComboBox->Text);
		 AdvColumnGrid5->HideColumn(col);
		 temp = temp1;
		 }
	 catch(Exception &e) {
		 MessageDlg(e.Message, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 FocusControl(ComboBox);
		 temp = -1;
		 }
	 }
   else {
	 AdvColumnGrid5->HideColumn(col);
	 temp = StrToInt(ComboBox->Text);
	 for (int i=2; i<ComboBox->Items->Count; i++) {
	   if (SameText(ComboBox->Text, ComboBox->Items->Strings[i])) {
		 ComboBox->ItemIndex = i;
		 break;
		 }
	   }
	 }

   return temp;
}
//---------------------------------------------------------------------------

 void __fastcall TTilSpreadSheetForm::AdvColumnGrid5CellValidate(TObject *Sender, int ACol,
		  int ARow, UnicodeString &Value, bool &Valid)
{
   // fill in temperature if not variable or delete temperature if LOI value deleted
   if (ACol == 4) {  // LOIOrganic
	 if (AdvColumnGrid5->AllCells[4][ARow].IsEmpty())
	   AdvColumnGrid5->AllCells[3][ARow] = L"";   // delete the temp
	 else if (ComboBox7->ItemIndex > 1) {
	   AdvColumnGrid5->AllCells[3][ARow] = ComboBox7->Items->Strings[ComboBox7->ItemIndex];
	   }
	 }
   else if (ACol == 6) {  // LOICarb
	 if (AdvColumnGrid5->AllCells[6][ARow].IsEmpty())
	   AdvColumnGrid5->AllCells[5][ARow] = L"";   // delete the temp
	 else if (ComboBox8->ItemIndex > 1) {
	   AdvColumnGrid5->AllCells[5][ARow] = ComboBox8->Items->Strings[ComboBox8->ItemIndex];
	   }
	 }
}
//---------------------------------------------------------------------------

// delete cell contents
void __fastcall TTilSpreadSheetForm::AdvColumnGrid5KeyDown(TObject *Sender, WORD &Key,
		  TShiftState Shift)
{
   if (Key == VK_DELETE) {
	 TGridRect rect = AdvColumnGrid5->Selection;
	 for (int dcol = rect.Left; dcol <= rect.Right; dcol++) {
	   int col = AdvColumnGrid5->RealColIndex(dcol);
	   for (int row = rect.Top; row <= rect.Bottom; row++) {
		 //int row = AdvColumnGrid5->Row;
		 if (col == 8)           // date analyzed
		   AdvColumnGrid5->AllCells[8][row] = L"";
		 else if (col == 9) {    // analyst
		   //AdvColumnGrid5->Objects[9][row] = NULL;
		   AdvColumnGrid5->AllCells[9][row] = L"";
		   }
		 else
		   AdvColumnGrid5->AllCells[col][row] = L"";
		 }
	   }
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::AdvColumnGrid5ClipboardBeforePasteCell(TObject *Sender,
		  int ACol, int ARow, UnicodeString &Value, bool &Allow)
{
   TDateTime date;
   double dVal;
   int iVal;
   // Navitation->AllowFmtClipboard is the key
   int col = AdvColumnGrid5->RealColIndex(ACol);
   switch (col) {
	 case 1:
	 case 2:
	 case 4:
	 case 6:
	 case 7:
	   if (!TryStrToFloat(Value,dVal))
		 Allow = false;
	   break;
	 case 3:
	 case 5:
       if (!TryStrToInt(Value,iVal))
		 Allow = false;
	   break;
	 case 8:  // date analyzed
	   if (!TryStrToDate(Value,date))
		 Allow = false;
	   break;
	 case 9:  // Analyst
	   if (AdvColumnGrid5->Columns->Items[9]->ComboItems->IndexOf(Value) == -1)
		 Allow = false;
	   break;
	 }
}
//---------------------------------------------------------------------------

// top
void __fastcall TTilSpreadSheetForm::ToolButton1Click(TObject *Sender)
{
   AdvColumnGrid5->Row = 1;
}
//---------------------------------------------------------------------------

// up
void __fastcall TTilSpreadSheetForm::ToolButton2Click(TObject *Sender)
{
   if (AdvColumnGrid5->Row > 1)
	 AdvColumnGrid5->Row--;
}
//---------------------------------------------------------------------------

// down
void __fastcall TTilSpreadSheetForm::ToolButton3Click(TObject *Sender)
{
   AdvColumnGrid5->Row++;
}
//---------------------------------------------------------------------------

// bottom
void __fastcall TTilSpreadSheetForm::ToolButton4Click(TObject *Sender)
{
   int LastContentRow = 1;
   for (int row = AdvColumnGrid5->RowCount-1; row > 0; row--) {
	  for (int col = 1; col < AdvColumnGrid5->ColCount; col++) {
		if (!AdvColumnGrid5->AllCells[col][row].IsEmpty()) {
		  LastContentRow = row;
		  break;
		  }
		}
	  if (LastContentRow > 1) break;
	  }
   AdvColumnGrid5->Row = LastContentRow;
}
//---------------------------------------------------------------------------

// insert
void __fastcall TTilSpreadSheetForm::ToolButton6Click(TObject *Sender)
{
   AdvColumnGrid5->InsertRows(AdvColumnGrid5->Row,1);
   for (int row=AdvColumnGrid5->Row; row<AdvColumnGrid5->RowCount; row++)
	 AdvColumnGrid5->Cells[0][row] = row;
}
//---------------------------------------------------------------------------

// delete
void __fastcall TTilSpreadSheetForm::ToolButton9Click(TObject *Sender)
{
   int Row1 = AdvColumnGrid5->Row;
   AdvColumnGrid5->RemoveRows(Row1,AdvColumnGrid5->SelectedRowCount);
   for (int row=Row1; row<AdvColumnGrid5->RowCount; row++)
	 AdvColumnGrid5->Cells[0][row] = row;
}
//---------------------------------------------------------------------------

// add row at bottom of grid
void __fastcall TTilSpreadSheetForm::AdvColumnGrid5AutoAddRow(TObject *Sender, int ARow)

{
   AdvColumnGrid5->Cells[0][ARow] = ARow;
}
//---------------------------------------------------------------------------

// export from LOI tabsheet to spreadsheet
void __fastcall TTilSpreadSheetForm::cxButton31Click(TObject *Sender)
{
   UnicodeString text, msg;
   double dVal;
   int iVal;
   TDateTime date;
   bool empty = true;

   int StartRow = AbsHeaderRowCount(ProfGrid1);
   int RowCount = AbsContentRowCount(ProfGrid1);

   // check if any other data in spreadsheet
   for (int row=StartRow; row<=RowCount; row++) {
	 UnicodeString VarCode = ProfGrid1->AbsoluteCells[1][row]->Text;
	 if (VarCode[1] != L'#') {
	   empty = false;
	   break;
	   }
	 }

   if (empty) {
	 ProfGrid1->Cells[1][1]->Value = WideString("Loss-on-ignition");
	 Datasets[0].DatasetType = L"Loss-on-ignition";
	 }
   else {
	 // check that LOI dataset isn't already in spreadsheet
	 for (int row=StartRow; row<=RowCount; row++) {
	   UnicodeString VarCode = ProfGrid1->AbsoluteCells[1][row]->Text;
	   UnicodeString VarName = ProfGrid1->AbsoluteCells[2][row]->Text;
	   if (SameText(VarCode, L"#Data.Type") && SameText(VarName, L"Loss-on-ignition")) {
		 msg = L"Loss-on-ignition dataset already exists in spreadsheet.";
		 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 return;
		 }
	   }
	 }

   // get LOI data
   multimap<double,LOISAMPLE> LOI;
   for (int row = 1; row < AdvColumnGrid5->RowCount; row++) {
	 text = AdvColumnGrid5->AllCells[1][row];
	 if (!text.IsEmpty()) {
	   if (TryStrToFloat(text,dVal)) {  // depth
		 double depth = dVal;
		 LOISAMPLE loi_sample;
		 text = AdvColumnGrid5->AllCells[2][row];
		 if (!text.IsEmpty()) {
		   if (TryStrToFloat(text,dVal))
			 loi_sample.Thickness = dVal;
		   else {
			 msg = L"Invalid value «" + text + "» for Thickness in LOI grid row " + IntToStr(row);
			 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			 return;
			 }
		   }

		 text = AdvColumnGrid5->AllCells[4][row];  // LOI Org
		 if (!text.IsEmpty()) {
		   if (TryStrToFloat(text,dVal)) {
			 loi_sample.LOIOrg = dVal;
			 text = AdvColumnGrid5->AllCells[3][row];  // Temp Org
			 if (!text.IsEmpty()) {
			   if (TryStrToInt(text,iVal))
				 loi_sample.TempOrg = iVal;
			   else {
				 msg = L"No value for Temp Org in LOI grid row " + IntToStr(row);
				 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
				 return;
				 }
			   }
			 else {
			   msg = L"Invalid value «" + text + "» for Temp Org in LOI grid row " + IntToStr(row);
			   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			   return;
			   }
			 }
		   else {
			 msg = L"Invalid value «" + text + "» for LOI Org in LOI grid row " + IntToStr(row);
			 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			 return;
			 }
		   }

		 text = AdvColumnGrid5->AllCells[6][row];  // LOI Carb
		 if (!text.IsEmpty()) {
		   if (TryStrToFloat(text,dVal)) {
			 loi_sample.LOICarb = dVal;
			 text = AdvColumnGrid5->AllCells[5][row];  // Temp Carb
			 if (!text.IsEmpty()) {
			   if (TryStrToInt(text,iVal))
				 loi_sample.TempCarb = iVal;
			   else {
				 msg = L"No value for Temp Carb in LOI grid row " + IntToStr(row);
				 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
				 return;
				 }
			   }
			 else {
			   msg = L"Invalid value «" + text + "» for Temp Carb in LOI grid row " + IntToStr(row);
			   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			   return;
			   }
			 }
		   else {
			 msg = L"Invalid value «" + text + "» for LOI Carb in LOI grid row " + IntToStr(row);
			 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			 return;
			 }
		   }

		 text = AdvColumnGrid5->AllCells[7][row];  // bulk density
		 if (!text.IsEmpty()) {
		   if (TryStrToFloat(text,dVal))
			 loi_sample.BulkDens = dVal;
		   else {
			 msg = L"Invalid value «" + text + "» for Bulk Density in LOI grid row " + IntToStr(row);
			 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			 return;
			 }
		   }

		 if (loi_sample.LOIOrg.IsEmpty() && loi_sample.LOICarb.IsEmpty() && loi_sample.BulkDens.IsEmpty()) {
		   msg = L"No values for LOI or Bulk Density entered in LOI grid row " + IntToStr(row);
		   if (MessageDlg(msg, mtWarning, TMsgDlgButtons() << mbOK << mbCancel, 0) == mrCancel)
			 return;
		   }

		 text = AdvColumnGrid5->AllCells[8][row];  // data analyzed
		 if (!text.IsEmpty()) {
		   if (TryStrToDate(text,date))
			 loi_sample.DateAnal = date;
		   else {
			 msg = L"Invalid value «" + text + "» for Date Anal in LOI grid row " + IntToStr(row);
			 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			 return;
			 }
		   }

		 text = AdvColumnGrid5->AllCells[9][row];  // analyst
		 if (!text.IsEmpty()) {
		   int idx = AdvColumnGrid5->Columns->Items[9]->ComboItems->IndexOf(text);
		   if (idx != -1)
			 loi_sample.Analyst = (CONTACT*)AdvColumnGrid5->Columns->Items[9]->ComboItems->Objects[idx];
		   }

		 LOI.insert(pair<double,LOISAMPLE>(depth,loi_sample));
		 }
	   else {
		 msg = L"Invalid value «" + text + "» for Depth in LOI Grid row " + IntToStr(row);
		 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 return;
		 }
	   }
	 }

   // get spreadsheet depths and thicknesses
   multimap<double,pair<Variant,int> > ss;   // depth, thickness, column
   int StartCol = AbsHeaderColCount(ProfGrid1);
   int EndCol = AbsContentColCount(ProfGrid1);
   int EndCol0 = EndCol;

   // look for thickness row
   int thkrow = 0;
   for (int row=StartRow; row<=RowCount; row++) {
	 UnicodeString VarCode = ProfGrid1->AbsoluteCells[1][row]->Text;
	 if (SameText(VarCode, L"#Anal.Thick")) {
	   thkrow = row;
	   break;
	   }
	 }

   // get spreadsheet depths, thicknesses, and columns
   for (int col=StartCol; col<=EndCol; col++) {
	 text = ProfGrid1->AbsoluteCells[col][1]->Text;
	 if (TryStrToFloat(text,dVal)) {
	   double depth = dVal;
	   Variant thickness = Variant::Empty();
	   if (thkrow > 0) {
		 text = ProfGrid1->AbsoluteCells[col][thkrow]->Text;
		 if (TryStrToFloat(text,dVal))
		   thickness = dVal;
		 else {
		   msg = L"Invalid value «" + text + "» for #Anal.Thick in spreadsheet cell " +
				 ProfGrid1->AbsoluteCells[col][thkrow]->A1Name;
		   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   return;
		   }
		 }
	   ss.insert(pair<double,pair<Variant,int> >(depth,pair<Variant,int>(thickness,col)));
	   }
	 else {
	   msg = L"Invalid value «" + text + "» for depth in spreadsheet cell " + ProfGrid1->AbsoluteCells[col][1]->A1Name;
	   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return;
	   }
	 }

   multimap<double,LOISAMPLE>::iterator loitr;
   multimap<double,pair<Variant,int> >::iterator ssitr;   // depth, thickness, column

   //

   // check thicknesses
   bool depth_only_match = false;
   bool loi_has_thick = true;
   for (loitr = LOI.begin(); loitr != LOI.end(); loitr++) {
	 LOISAMPLE loi_sample = loitr->second;
	 if (loi_sample.Thickness.IsEmpty()) {
	   loi_has_thick = false;
	   break;
	   }
	 }

   bool ss_has_thick = (thkrow > 0);
   if (ss_has_thick) {
	 for (ssitr = ss.begin(); ssitr != ss.end(); ssitr++) {
	   Variant ssthick = ssitr->second.first;
	   if (ssthick.IsEmpty()) {
		 ss_has_thick = false;
		 break;
		 }
	   }
	 }

   if (!empty && ss_has_thick && !loi_has_thick) {
	 msg = L"Spreadsheet analysis units have thicknesses, but some or all LOI analysis units do not have thicknesses.";
	 msg += L" Match analysis units by depths only, ignoring thicknesses?";
	 int rv = MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo << mbCancel, 0);
	 switch (rv) {
	   case mrYes:
		 depth_only_match = true;
		 break;
	   case mrCancel:
		 return;
	   }
	 }
   else if (!empty && !ss_has_thick && loi_has_thick) {
	 msg = L"LOI analysis units have thicknesses, but some or all spreadsheet analysis units do not have thicknesses.";
	 msg += L" Match analysis units by depths only, ignoring thicknesses?";
	 int rv = MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo << mbCancel, 0);
	 switch (rv) {
	   case mrYes:
		 depth_only_match = true;
	   case mrNo:
		 ProfGrid1->InsertRow(3);
		 RowCount++;
		 thkrow = 3;
		 ProfGrid1->AbsoluteCells[1][3]->Value = WideString(L"#Anal.Thick");
		 ProfGrid1->AbsoluteCells[2][3]->Value = WideString(L"Analysis Unit Thickness");
		 break;
	   case mrCancel:
		 return;
	   }
	 }
   else if (!empty && !ss_has_thick && !loi_has_thick) {
	 msg = L"Neither spreadsheet nor LOI analysis units have thicknesses.";
	 msg += L" Match analysis units by depths only?";
	 int rv = MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo << mbCancel, 0);
	 switch (rv) {
	   case mrYes:
		 depth_only_match = true;
		 break;
	   case mrCancel:
		 return;
	   }
	 }
   else if (empty && !ss_has_thick && loi_has_thick) {
	 ProfGrid1->InsertRow(3);
	 RowCount++;
	 thkrow = 3;
	 ProfGrid1->AbsoluteCells[1][3]->Value = WideString(L"#Anal.Thick");
	 ProfGrid1->AbsoluteCells[2][3]->Value = WideString(L"Analysis Unit Thickness");
	 }
   else if (!empty) {
	 msg = L"Both spreadsheet and LOI analysis units have thicknesses.";
	 msg += L" Analysis units will be matched by depth and thickness.";
	 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
	 }

   // insert LOI rows into spreadsheet
   if (!empty) {
	 ProfGrid1->Row = ++RowCount;
	 EnterSSMetadataCode(L"#Data.Type", "");
	 ProfGrid1->AbsoluteCells[2][RowCount]->Value = WideString("Loss-on-ignition");
	 EnterSSDataType();
	 }

   set<int> temps;
   bool has_bulkdens = false;
   bool has_analdate = false;
   bool has_analyst = false;
   //struct { int analyst; int date; map<int,int> temps; int bulkdens; } loirows;   // temps: temp, col
   LOIROW loirows;
   for (loitr = LOI.begin(); loitr != LOI.end(); loitr++) {
	 LOISAMPLE loi_sample = loitr->second;
	 if (!loi_sample.TempOrg.IsEmpty()) {
	   if (temps.count(loi_sample.TempOrg) == 0)
		 temps.insert((int)loi_sample.TempOrg);
	   }
	 if (!loi_sample.TempCarb.IsEmpty()) {
	   if (temps.count(loi_sample.TempCarb) == 0)
		 temps.insert((int)loi_sample.TempCarb);
	   }
	 if (!has_bulkdens && !loi_sample.BulkDens.IsEmpty())
	   has_bulkdens = true;
	 if (!has_analdate && !loi_sample.DateAnal.IsEmpty())
	   has_analdate = true;
	 if (!has_analyst && (loi_sample.Analyst != NULL))
	   has_analyst = true;
	 }
   if (has_analyst) {
	 loirows.analyst = ++RowCount;
	 ProfGrid1->AbsoluteCells[1][RowCount]->Value = WideString("#Samp.Analyst");
	 ProfGrid1->AbsoluteCells[2][RowCount]->Value = WideString("Sample Analyst");
	 }
   if (has_analdate) {
	 loirows.date = ++RowCount;
	 ProfGrid1->AbsoluteCells[1][RowCount]->Value = WideString("#Samp.DateAnal");
	 ProfGrid1->AbsoluteCells[2][RowCount]->Value = WideString("Date Analyzed");
	 }
   if (temps.size() > 0) {
	 for (set<int>::iterator itr = temps.begin(); itr != temps.end(); itr++) {
	   loirows.temps[*itr] = ++RowCount;
	   ProfGrid1->AbsoluteCells[1][RowCount]->Value = WideString("LOI");
	   ProfGrid1->AbsoluteCells[2][RowCount]->Value = WideString("loss-on-ignition");
	   WideString Element = WideString(IntToStr(*itr)) + WideString("°C");
	   ProfGrid1->AbsoluteCells[3][RowCount]->Value = Element;
	   ProfGrid1->AbsoluteCells[4][RowCount]->Value = WideString("percent");
	   ProfGrid1->AbsoluteCells[7][RowCount]->Value = WideString("PLOI");
	   }
	 }
   if (has_bulkdens) {
	 loirows.bulkdens = ++RowCount;
	 ProfGrid1->AbsoluteCells[1][RowCount]->Value = WideString("bulk.dens");
	 ProfGrid1->AbsoluteCells[2][RowCount]->Value = WideString("bulk density");
	 ProfGrid1->AbsoluteCells[4][RowCount]->Value = WideString("g/ml");
	 ProfGrid1->AbsoluteCells[7][RowCount]->Value = WideString("PLOI");
	 }

   set<double> LOIDepthsUsed;  // set of multi LOIDepths used
   for (loitr = LOI.begin(); loitr != LOI.end(); loitr++) {
	 double loidepth = loitr->first;
	 if (LOIDepthsUsed.count(loidepth) > 0) continue;
	 LOISAMPLE loi_sample = loitr->second;
	 if (LOI.count(loidepth) == 1) {
	   int ncols = ss.count(loidepth);
	   if (ncols == 0) {
		 AppendLOISampleToSpreadsheet(EndCol, loidepth, loi_sample, loirows, thkrow);
		 }
	   else if (ncols == 1) {
		 ssitr = ss.find(loidepth);
		 int col = ssitr->second.second;
		 if (depth_only_match) {
		   ExportLOIData(col, loi_sample, loirows);
		   }
		 else {  // match depth and thickness
		   Variant vthick = ssitr->second.first;
		   if (vthick == loi_sample.Thickness)
			 ExportLOIData(col, loi_sample, loirows);
		   else {
             AppendLOISampleToSpreadsheet(EndCol, loidepth, loi_sample, loirows, thkrow);
			 }
		   }
		 }
	   else {  // ncols > 1
		 if (depth_only_match) {
		   msg = L"Spreadsheet has more than one column with LOI depth " + FloatToStr(loidepth) +
				 L". LOI samples with depth " + FloatToStr(loidepth) + L" will copied to new columns.";
		   MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
           AppendLOISampleToSpreadsheet(EndCol, loidepth, loi_sample, loirows, thkrow);
		   }
		 else {
		   pair<multimap<double,pair<Variant,int> >::iterator, multimap<double,pair<Variant,int> >::iterator> range;
		   range = ss.equal_range(loidepth);
		   int nssthick = 0;
		   multimap<double,pair<Variant,int> >::iterator thkitr;
		   for (ssitr = range.first; ssitr != range.second; ssitr++) {
			 Variant vthick = ssitr->second.first;
			 if (!vthick.IsEmpty()) {
			   if (vthick == loi_sample.Thickness) {
				 thkitr = ssitr;
				 nssthick++;
				 }
			   }
			 }
		   if (nssthick == 1) {
			 int col = thkitr->second.second;
			 ExportLOIData(col, loi_sample, loirows);
			 }
		   else {
			 msg = L"Spreadsheet has more than one column with LOI depth " + FloatToStr(loidepth) +
				   L". LOI samples with depth " + FloatToStr(loidepth) + L" will copied to new columns.";
			 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
			 AppendLOISampleToSpreadsheet(EndCol, loidepth, loi_sample, loirows, thkrow);
			 }
		   }
		 }
	   }
	 else {  // loi.count > 1
	   LOIDepthsUsed.insert(loidepth);
	   int ncols = ss.count(loidepth);
	   pair<multimap<double,LOISAMPLE>::iterator, multimap<double,LOISAMPLE>::iterator> loirange;
	   loirange = LOI.equal_range(loidepth);
	   multimap<double,LOISAMPLE>::iterator loitr1;
	   if (ncols == 0) {
		 for (loitr1 = loirange.first; loitr1 != loirange.second; loitr1++) {
		   LOISAMPLE loi_sample = loitr1->second;
           AppendLOISampleToSpreadsheet(EndCol, loidepth, loi_sample, loirows, thkrow);
		   }
		 }
	   else if (ncols == 1) {
		 if (depth_only_match) {
		   msg = L"LOI grid has more than one sample with depth " + FloatToStr(loidepth) +
				 L". LOI samples with depth " + FloatToStr(loidepth) + L" will copied to new columns.";
		   MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
		   for (loitr1 = loirange.first; loitr1 != loirange.second; loitr1++) {
			 LOISAMPLE loi_sample = loitr1->second;
             AppendLOISampleToSpreadsheet(EndCol, loidepth, loi_sample, loirows, thkrow);
			 }
		   }
		 else {
		   ssitr = ss.find(loidepth);
		   Variant vssthick = ssitr->second.first;
		   int nloithick = 0;
		   for (loitr1 = loirange.first; loitr1 != loirange.second; loitr1++) {
			 if (vssthick == loitr1->second.Thickness)
			   nloithick++;
			 }
		   if (nloithick == 1) {
			 for (loitr1 = loirange.first; loitr1 != loirange.second; loitr1++) {
			   LOISAMPLE loi_sample = loitr1->second;
			   if (loi_sample.Thickness == vssthick) {
				 int col = ssitr->second.second;
				 ExportLOIData(col, loi_sample, loirows);
				 }
			   else {
			     AppendLOISampleToSpreadsheet(EndCol, loidepth, loi_sample, loirows, thkrow);
				 }
			   }
			 }
		   else {
			 if (nloithick > 1) {
			   msg = L"LOI grid has more than one sample with spreadsheet depth " + FloatToStr(loidepth) +
					 L". LOI samples with depth " + FloatToStr(loidepth) + L" will copied to new columns.";
			   MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
			   }
			 for (loitr1 = loirange.first; loitr1 != loirange.second; loitr1++) {
			   LOISAMPLE loi_sample = loitr1->second;
			   AppendLOISampleToSpreadsheet(EndCol, loidepth, loi_sample, loirows, thkrow);
			   }
			 }
		   }
		 }
	   else {  // ncols > 1 && loi.count > 1
		 // loithk and ssthk have the number of samples with different thicknesses
		 // if there's one in each, then they're a match
		 vector<pair<double,int> > loithk;   // thick, number
		 vector<pair<double,int> > ssthk;
		 for (loitr1 = loirange.first; loitr1 != loirange.second; loitr1++) {
		   LOISAMPLE loi_sample = loitr1->second;
		   bool found = false;
		   for (unsigned int i=0; i<loithk.size(); i++) {
			 if (loithk[i].first == loi_sample.Thickness) {
			   loithk[i].second++;
			   found = true;
			   break;
			   }
			 }
		   if (!found)
			 loithk.push_back(pair<double,int>(loi_sample.Thickness,1));
		   }

		 //  multimap<double,pair<Variant,int> > ss;   // depth, thickness, column
		 pair<multimap<double,pair<Variant,int> >::iterator, multimap<double,pair<Variant,int> >::iterator> ssrange;
		 ssrange = ss.equal_range(loidepth);
		 for (ssitr = ssrange.first; ssitr != ssrange.second; ssitr++) {
		   double ssthick = ssitr->second.first;
		   bool found = false;
		   for (unsigned int i=0; i<ssthk.size(); i++) {
			 if (ssthk[i].first == ssthick) {
			   ssthk[i].second++;
			   found = true;
			   break;
			   }
			 }
		   if (!found)
			 ssthk.push_back(pair<double,int>(ssthick,1));
		   }

		 int nmsg = 0;
		 for (loitr1 = loirange.first; loitr1 != loirange.second; loitr1++) {
		   LOISAMPLE loi_sample = loitr1->second;
		   int nloithk = getnthk(loi_sample.Thickness, loithk);
		   int nssthk = getnthk(loi_sample.Thickness, ssthk);
		   if (nloithk == 1) {
			 if (nssthk == 0) {  // no match in spreadsheet
			   AppendLOISampleToSpreadsheet(EndCol, loidepth, loi_sample, loirows, thkrow);
			   }
			 else if (nssthk == 1) {  // one in each loithk and ssthk
			   for (ssitr = ssrange.first; ssitr != ssrange.second; ssitr++) {
				 double ssthick = ssitr->second.first;
				 if (ssthick == loi_sample.Thickness) {
				   int col = ssitr->second.second;
				   ExportLOIData(col, loi_sample, loirows);
				   break;
				   }
				 }
			   }
			 else {  // nssthk > 1, i.e. spreadsheet has more than one sample with same thickness
			   msg = L"Spreadsheet has more than one column with LOI depth " + FloatToStr(loidepth) +
					 L" and thickness " + FloatToStr((double)loi_sample.Thickness) +
					 L". Matching LOI samples will copied to new columns.";
			   MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
			   AppendLOISampleToSpreadsheet(EndCol, loidepth, loi_sample, loirows, thkrow);
			   }
			 }
		   else {  // nloithk > 1
			 if (nssthk > 0) {
			   if (nmsg++ == 0) {
				 msg = L"LOI Grid has more than one sample with depth " +
					   FloatToStr(loidepth) +  L" and thickness " +
					   FloatToStr((double)loi_sample.Thickness) +
					   L", which cannot match uniquely with spreadsheet samples. LOI samples will copied to new columns.";
				 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
				 }
			   }
			 AppendLOISampleToSpreadsheet(EndCol, loidepth, loi_sample, loirows, thkrow);
			 }
		   }
		 }
	   }
	 }

   // add LOI dataset to the Datasets vector
   DATASET dataset;
   dataset.DatasetType = L"Loss-on-ignition";
   Datasets.push_back(dataset);

   // copy investigators and publications to LOI dataset
   DATASET& LOIDataset = Datasets.back();
   if (loi.Investigators.size() > 0)
	 LOIDataset.Investigators = loi.Investigators;
   if (loi.Publications.size() > 0)
     LOIDataset.Publications = loi.Publications;

   msg = L"LOI data copied to spreadsheet.";
   if (EndCol > EndCol0) {
	 msg += L"\nNew columns have been appended to spreadsheet.";
	 msg += L"\nRe-sort columns by depth?";
	 if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes)
	   SortSampleNumbers(ProfGrid1);
	 }
   else
	 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::AppendLOISampleToSpreadsheet(int& EndCol, double loidepth,
	LOISAMPLE loi_sample, LOIROW loi_row, int thkrow)
{
   ProfGrid1->AbsoluteCells[++EndCol][1]->Value = loidepth;
   if (!loi_sample.Thickness.IsEmpty())
	 ProfGrid1->AbsoluteCells[EndCol][thkrow]->Value = loi_sample.Thickness;
   ExportLOIData(EndCol, loi_sample, loi_row);
}
//---------------------------------------------------------------------------

int TTilSpreadSheetForm::getnthk(double thickness, vector<pair<double,int> >& thk)
{
   for (unsigned int i=0; i<thk.size(); i++) {
	 if (thickness == thk[i].first) {
	   return thk[i].second;
	   }
	 }
   return 0;
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::ExportLOIData(int col, LOISAMPLE loi_sample, LOIROW loi_row)
{
   int row;

   if (loi_sample.Analyst != NULL) {
	 TProfGridCell* ACell = ProfGrid1->AbsoluteCells[col][loi_row.analyst];
	 ACell->Value = loi_sample.Analyst->ShortContactName;
	 TList* CellContacts = InitCellContactsList(ACell);
	 CellContacts->Add(loi_sample.Analyst);
	 }
   if (!loi_sample.DateAnal.IsEmpty())
	 ProfGrid1->AbsoluteCells[col][loi_row.date]->Value = loi_sample.DateAnal;
   if (!loi_sample.LOIOrg.IsEmpty()) {
	 row = loi_row.temps[loi_sample.TempOrg];
	 ProfGrid1->AbsoluteCells[col][row]->Value = loi_sample.LOIOrg;
	 }
   if (!loi_sample.LOICarb.IsEmpty()) {
	 row = loi_row.temps[loi_sample.TempCarb];
	 ProfGrid1->AbsoluteCells[col][row]->Value = loi_sample.LOICarb;
	 }
   if (!loi_sample.BulkDens.IsEmpty())
	 ProfGrid1->AbsoluteCells[col][loi_row.bulkdens]->Value = loi_sample.BulkDens;
}
//---------------------------------------------------------------------------

