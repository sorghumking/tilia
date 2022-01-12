//---------------------------------------------------------------------------

#include <vcl.h>
#include "pch.h"
#pragma hdrstop

#include "TIChkHir.h"
#ifndef TIJSONH
#include "TIJSON.h"
#endif
#ifndef TIGlobalsH
#include "TIGlobals.h"
#endif

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvCGrid"
#pragma link "AdvGrid"
#pragma link "AdvObj"
#pragma link "BaseGrid"
#pragma link "ipwjson"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxLabel"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxButtons"
#pragma link "AdvUtil"
#pragma link "dxSkinBlack"
#pragma link "dxSkinBlue"
#pragma link "dxSkinBlueprint"
#pragma link "dxSkinCaramel"
#pragma link "dxSkinCoffee"
#pragma link "dxSkinDarkRoom"
#pragma link "dxSkinDarkSide"
#pragma link "dxSkinDevExpressDarkStyle"
#pragma link "dxSkinDevExpressStyle"
#pragma link "dxSkinFoggy"
#pragma link "dxSkinGlassOceans"
#pragma link "dxSkinHighContrast"
#pragma link "dxSkiniMaginary"
#pragma link "dxSkinLilian"
#pragma link "dxSkinLiquidSky"
#pragma link "dxSkinLondonLiquidSky"
#pragma link "dxSkinMcSkin"
#pragma link "dxSkinMetropolis"
#pragma link "dxSkinMetropolisDark"
#pragma link "dxSkinMoneyTwins"
#pragma link "dxSkinOffice2007Black"
#pragma link "dxSkinOffice2007Blue"
#pragma link "dxSkinOffice2007Green"
#pragma link "dxSkinOffice2007Pink"
#pragma link "dxSkinOffice2007Silver"
#pragma link "dxSkinOffice2010Black"
#pragma link "dxSkinOffice2010Blue"
#pragma link "dxSkinOffice2010Silver"
#pragma link "dxSkinOffice2013DarkGray"
#pragma link "dxSkinOffice2013LightGray"
#pragma link "dxSkinOffice2013White"
#pragma link "dxSkinOffice2016Colorful"
#pragma link "dxSkinOffice2016Dark"
#pragma link "dxSkinPumpkin"
#pragma link "dxSkinsCore"
#pragma link "dxSkinsDefaultPainters"
#pragma link "dxSkinSeven"
#pragma link "dxSkinSevenClassic"
#pragma link "dxSkinSharp"
#pragma link "dxSkinSharpPlus"
#pragma link "dxSkinSilver"
#pragma link "dxSkinSpringTime"
#pragma link "dxSkinStardust"
#pragma link "dxSkinSummer2008"
#pragma link "dxSkinTheAsphaltWorld"
#pragma link "dxSkinValentine"
#pragma link "dxSkinVisualStudio2013Blue"
#pragma link "dxSkinVisualStudio2013Dark"
#pragma link "dxSkinVisualStudio2013Light"
#pragma link "dxSkinVS2010"
#pragma link "dxSkinWhiteprint"
#pragma link "dxSkinXmas2008Blue"
#pragma link "ipsjsons"
#pragma resource "*.dfm"
TCheckHierarchyForm *CheckHierarchyForm;
//---------------------------------------------------------------------------

__fastcall TCheckHierarchyForm::TCheckHierarchyForm(TComponent* Owner)
	: TForm(Owner)
{
   TSSForm = (TTilSpreadSheetForm*)Owner;
   activated = false;
   close_er_up = false;
   RatStart = 8;
   RatEnd = 500;
   RatPos = 16;
   FixType = -1;
   UnresolvedNonExclusive = 0;
   nNonExclusive = 0;
   nNoSibs = 0;
   FlowPanel1->Left = (Panel1->Width - cxButton1->Width - cxButton2->Width)/2;
   FlowPanel1->Width = cxButton1->Width + cxButton2->Width;
}
//---------------------------------------------------------------------------

void __fastcall TCheckHierarchyForm::FormActivate(TObject *Sender)
{
   vector<UnicodeString> ErrMsgs;

   if (!activated) {
	 Screen->Cursor = crHourGlass;
	 Timer1->Enabled = true;
	 TSSForm->GetSSVarList(SSVarList, false, ErrMsgs);
	 if (SSVarList.size() > 1) {
	   if (GetNeotomaHierarchy())
		 DiffCheckMutExlusive();
	   else
		 close_er_up = true;
	   }
	 else {
	   Timer1->Enabled = false;
	   Image1->Visible = false;
	   UnicodeString msg = L"Hierarchy check requires two or more taxa.";
	   MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
	   close_er_up = true;
	   }

	 Timer1->Enabled = false;
	 Image1->Visible = false;
	 Panel3->Caption = L"";
	 Screen->Cursor = crDefault;
	 if (close_er_up) {
       cxButton1->Visible = false;
	   FlowPanel1->Left = (Panel1->Width - cxButton2->Width)/2;
	   FlowPanel1->Width = cxButton2->Width;
	   cxButton2->Caption = L"Close";
	   FlowPanel1->Visible = true;
	   }
	 else
	   AdvColumnGrid1->Enabled = true;
	 Screen->Cursor = crDefault;
	 activated = true;
	 }
}
//---------------------------------------------------------------------------

bool TCheckHierarchyForm::GetNeotomaHierarchy(void)
{
   UnicodeString ErrMsg;
   int row = 1;

   for (unsigned int i=0; i<SSVarList.size(); i++) {
	 if (GetTaxonHierarchy(&SSVarList[i], ErrMsg)) {
	   if (!ErrMsg.IsEmpty())
		 AddMessage(row, SSVarList[i].row, ErrMsg);
	   }
	 else
	   return false;
	 }

   if (row > 1) {
     Timer1->Enabled = false;
	 Image1->Visible = false;
	 ErrMsg = L"Hierarchy cannot be checked until errors resolved.";
	 MessageDlg(ErrMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 return false;
	 }

   return true;
}
//---------------------------------------------------------------------------

bool TCheckHierarchyForm::GetTaxonHierarchy(SSVAR* ssvar, UnicodeString& ErrMsg)
{
   ErrMsg = L"";

   NeotomaTaxonHierarchy Hierarchy(ipsJSONS1, TcpClient1);
   Hierarchy.AddParam(L"TAXONNAME", ssvar->name);
   Panel3->Caption = L"  " + Hierarchy.WebServiceName() + L": " + ssvar->name;
   if (Hierarchy.Execute()) {
	 if (Hierarchy.Size() > 0) {
	   if (Hierarchy.Items[0].Valid) {
		 if (Hierarchy.Size() > 1) {
		   for (unsigned int j=1; j<Hierarchy.Size(); j++)
			 ssvar->parents.push_back(Hierarchy.Items[j].TaxonName);
		   }
		 }
	   else
		 ErrMsg = L"Taxon «" + ssvar->name + L"» is not valid.";
	   }
	 else
	   ErrMsg = L"Taxon «" + ssvar->name + L"» is not in the Neotoma Taxa table.";
	 }
   else
	 return false;
   return true;
}
//---------------------------------------------------------------------------

void TCheckHierarchyForm::AddMessage(int& row, int var_row, UnicodeString ErrMsg)
{
   if (row == 1)
	 AdvColumnGrid1->Columns->Items[2]->Header = L"Taxon Errors";
   if (row == AdvColumnGrid1->RowCount)
	 AdvColumnGrid1->RowCount = row + 1;
   AdvColumnGrid1->Cells[1][row] = var_row;
   AdvColumnGrid1->Cells[2][row++] = ErrMsg;
}
//---------------------------------------------------------------------------

void TCheckHierarchyForm::DiffCheckMutExlusive(void)
{
   UnicodeString author;
   int row = 1;

   Screen->Cursor = crHourGlass;
   for (unsigned int i=0; i<SSVarList.size(); i++) {
	 SSVAR ssvi = SSVarList[i];
	 vector<UnicodeString>& parents = ssvi.parents;
	 for (unsigned int j=0; j<parents.size(); j++) {
	   for (unsigned int k=0; k<SSVarList.size(); k++) {
		 if (i == k) continue;
		 SSVAR ssvk = SSVarList[k];
		 if (SameText(ssvk.name, parents[j])) {
		   UnicodeString undiff = ssvk.name + " undiff.";
		   if (AddVarChange(ssvk.row, ssvk.name, undiff)) {
			 Undiffs.push_back(SSTAXANAME(undiff, author, ssvk.row));
			 UnicodeString ErrMsg = "Taxon «" + ssvk.name + "» is a parent of «" +
			   ssvi.name + "» in row " + IntToStr(ssvi.row) + ". Change to «" +
			   undiff + "»?";
			 AddMessage(row, ssvk.row, ErrMsg);
			 }
		   break;
		   }
		 }
	   }
	 }
   Screen->Cursor = crDefault;

   if (Undiffs.size() > 0) {
	 nNonExclusive = Undiffs.size();
	 cxLabel1->Align = alClient;
	 cxLabel1->Caption = L"Non-mutually exclusive taxa found. Change checked?";
	 cxLabel1->Visible = true;
     cxButton3->Visible = true;
	 FlowPanel1->Left = (Panel1->Width - cxButton1->Width - cxButton2->Width - cxButton3->Width)/2;
	 FlowPanel1->Width = cxButton1->Width + cxButton2->Width + cxButton3->Width;
	 FlowPanel1->Visible = true;
	 FixType = FIXNONEXCLUSIVETAXA;
	 }
  else {
	DiffCheckNoSibs();
	}
}
//---------------------------------------------------------------------------

void TCheckHierarchyForm::DiffCheckNoSibs(void)
{
   UnicodeString author;
   UnicodeString msg;
   int row = 1;

   Screen->Cursor = crHourGlass;
   if (cxButton3->Visible) {
	 cxButton3->Visible = false;
     FlowPanel1->Left = (Panel1->Width - cxButton1->Width - cxButton2->Width)/2;
	 FlowPanel1->Width = cxButton1->Width + cxButton2->Width;
	 }

   Undiffs.clear();
   VarChanges.clear();

   UnresolvedNonExclusive = AdvColumnGrid1->RowCount - 1;
   if (UnresolvedNonExclusive == 1) {
	 if (AdvColumnGrid1->Cells[2][1].IsEmpty())
	   UnresolvedNonExclusive = 0;
	 }

   if (AdvColumnGrid1->RowCount > 2) {
	 AdvColumnGrid1->RemoveRows(2,AdvColumnGrid1->RowCount-2);
	 AdvColumnGrid1->ClearNormalCells();
	 AdvColumnGrid1->SetCheckBoxState(0,1,false);
	 }

   for (unsigned int i=0; i < SSVarList.size(); i++) {
	 SSVAR ssvi = SSVarList[i];
	 int Index = ssvi.name.Pos(" undiff.");
	 if (Index) {
	   bool found = false;
	   UnicodeString RootName = ssvi.name.SubString(1, Index-1);
	   for (unsigned int j=0; j<SSVarList.size(); j++) {
		 if (j == i) continue;
		 SSVAR ssvj = SSVarList[j];
		 for (unsigned int k=0; k < ssvj.parents.size(); k++) {
		   if (ssvj.parents[k] == RootName) {
			 found = true;
			 break;
			 }
		   }
		 if (found) break;
		 }
	   if (!found) {
		 if (AddVarChange(ssvi.row, ssvi.name, RootName)) {
		   Undiffs.push_back(SSTAXANAME(RootName, author, ssvi.row));
		   UnicodeString ErrMsg = "Taxon «" + ssvi.name + "» has no siblings. Change to «" +
			 RootName + "»?";
		   AddMessage(row, ssvi.row, ErrMsg);
		   }
		 }
	   }
	 }
   Screen->Cursor = crDefault;

   if (Undiffs.size() > 0) {
	 nNoSibs = Undiffs.size();
	 cxLabel1->Align = alClient;
	 cxLabel1->Caption = L"Undifferentiated taxa with no siblings found. Change checked?";
	 cxLabel1->Visible = true;
	 FlowPanel1->Visible = true;
	 FixType = FIXNOSIBLINGS;
	 }
   else {
	 if (nNonExclusive == 0 && nNoSibs == 0) {
	   Timer1->Enabled = false;
	   Image1->Visible = false;
	   msg = L"Hierarchy check complete. No violations found.";
	   }
	 else if (UnresolvedNonExclusive > 0)
	   msg = L"Hierarchy check complete. Not all non-exclusive violations resolved.";
	 else
	   msg = L"Hierarchy check complete.";
	 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
	 close_er_up = true;
	 }
}
//---------------------------------------------------------------------------

bool TCheckHierarchyForm::AddVarChange(int row, UnicodeString old_name, UnicodeString new_name)
{
   // if a VarChange already exists for row, return
   for (unsigned int i=0; i<VarChanges.size(); i++) {
	 if (VarChanges[i].row == row)
	   return false;
	 }
   VARCHANGE vc;
   vc.row = row;
   vc.old_name = old_name;
   vc.new_name = new_name;
   VarChanges.push_back(vc);
   return true;
}
//---------------------------------------------------------------------------

void __fastcall TCheckHierarchyForm::Timer1Timer(TObject *Sender)
{
   if (Image1->Visible) {
	 RatPos += 48;
	 if (RatPos > RatEnd)
	   RatPos = RatStart;
	 Image1->Left = RatPos;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TCheckHierarchyForm::cxButton1Click(TObject *Sender)
{
   UnicodeString msg;

   if (FixType == FIXNONEXCLUSIVETAXA)
	 FixNonExclusive();
   else if (FixType == FIXNOSIBLINGS) {
	 FixNoSiblings();
	 if (AdvColumnGrid1->RowCount == 2 && AdvColumnGrid1->Cells[2][1].IsEmpty()) {
	   if (nNonExclusive == 0 && nNoSibs == 0)
		 msg = L"Hierarchy check complete. No violations found.";
	   else if (UnresolvedNonExclusive > 0)
	     msg = L"Hierarchy check complete. Not all non-exclusive violations resolved.";
	   else
		 msg = L"Hierarchy check complete.";
	   MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
	   ModalResult = mrClose;
	   }
	 }
}
//---------------------------------------------------------------------------

void TCheckHierarchyForm::FixNonExclusive(void)
{
   UnicodeString msg;
   bool checked;
   int nchecked = 0;

   Screen->Cursor = crHourGlass;
   for (int row=1, i=0; row<AdvColumnGrid1->RowCount; row++, i++) {
	 AdvColumnGrid1->GetCheckBoxState(0,row,checked);
	 if (checked) {
	   nchecked ++;
	   int ssrow = Undiffs[i].Row;
	   UnicodeString OldName = TSSForm->ProfGrid1->AbsoluteCells[2][ssrow]->Text;
	   TSSForm->ProfGrid1->AbsoluteCells[2][ssrow]->Value = Undiffs[i].Name;
	   TaxonByName NeotomaTaxon(ipsJSONS1, TcpClient1);
	   NeotomaTaxon.AddParam(L"TAXONNAME", Undiffs[i].Name);
	   Panel3->Caption = L"  " + NeotomaTaxon.WebServiceName();
	   if (NeotomaTaxon.Execute()) {
		 TAXON Taxon;
		 if (NeotomaTaxon.Size() > 0) {
		   Taxon.Code = NeotomaTaxon.Items[0].TaxonCode;
		   TSSForm->ReplaceVarCodes(&Taxon, ssrow, SUBALL);
		   for (unsigned int j=0; j<SSVarList.size(); j++) {
			 if (SameText(OldName, SSVarList[j].name)) {
			   SSVarList[j].name = Undiffs[i].Name;
               SSVarList[j].author = L"";
			   SSVarList[j].parents.clear();
			   if (!GetTaxonHierarchy(&SSVarList[j], msg))
				 return;
			   break;
			   }
			 }
		   }
		 else {
		   Screen->Cursor = crDefault;
		   Taxon.Code = TSSForm->ProfGrid1->AbsoluteCells[1][ssrow]->Text;
		   Taxon.Code += L".ud";
		   TSSForm->ReplaceVarCodes(&Taxon, ssrow, SUBALL);
		   msg = L"Undifferentiated taxon «" + Undiffs[i].Name + L"» is not in the Neotoma taxon table.";
		   MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
		   }
		 }
	   else {
		 Screen->Cursor = crDefault;
		 return;
		 }
	   TSSForm->SpreadSheetChanged = true;
	   }
	 }
   Screen->Cursor = crDefault;

   if (nchecked == 0) {
	 MessageDlg(L"No rows checked!", mtWarning, TMsgDlgButtons() << mbOK, 0);
	 return;
	 }

   for (int row=AdvColumnGrid1->RowCount-1; row > 1; row--) {
	 AdvColumnGrid1->GetCheckBoxState(0,row,checked);
	 if (checked)
	   AdvColumnGrid1->RemoveRows(row,1);
	 }

   AdvColumnGrid1->GetCheckBoxState(0,1,checked);
   if (checked) {
	 AdvColumnGrid1->ClearNormalCells();
	 AdvColumnGrid1->SetCheckBoxState(0,1,false);
	 }

   if (AdvColumnGrid1->RowCount == 2 && AdvColumnGrid1->Cells[2][1].IsEmpty()) {  // all non-exclusive taxa resolved
	 FlowPanel1->Visible = false;
	 msg = L"All non-exclusive taxa resolved";
	 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
	 FixType = FIXNOSIBLINGS;
	 DiffCheckNoSibs();
	 }
   else {
	 cxButton3->Visible = true;
	 FlowPanel1->Left = (Panel1->Width - cxButton1->Width - cxButton2->Width - cxButton3->Width)/2;
	 FlowPanel1->Width = cxButton1->Width + cxButton2->Width + cxButton3->Width;
	 msg = L"Not all non-exclusive taxa resolved. Fix remaining non-exclusive taxa,";
	 msg += L"\nor click the Continue button to check siblings.";
	 MessageDlg(msg, mtWarning, TMsgDlgButtons() << mbOK, 0);
	 }

   Panel3->Caption = L"";
}
//---------------------------------------------------------------------------

void TCheckHierarchyForm::FixNoSiblings(void)
{
   UnicodeString msg;
   bool checked;
   int nchecked = 0;

   Screen->Cursor = crHourGlass;
   for (int row=1, i=0; row<AdvColumnGrid1->RowCount; row++, i++) {
	 AdvColumnGrid1->GetCheckBoxState(0,row,checked);
	 if (checked) {
	   nchecked++;
       int ssrow = Undiffs[i].Row;
	   TSSForm->ProfGrid1->AbsoluteCells[2][ssrow]->Value = Undiffs[i].Name;
	   TaxonByName NeotomaTaxon(ipsJSONS1, TcpClient1);
	   NeotomaTaxon.AddParam(L"TAXONNAME", Undiffs[i].Name);
	   Panel3->Caption = L"  " + NeotomaTaxon.WebServiceName();
	   if (NeotomaTaxon.Execute()) {
		 TAXON Taxon;
		 if (NeotomaTaxon.Size() > 0) {
		   Taxon.Code = NeotomaTaxon.Items[0].TaxonCode;
		   TSSForm->ReplaceVarCodes(&Taxon, ssrow, SUBALL);
		   }
		 else {
		   Taxon.Code = TSSForm->ProfGrid1->AbsoluteCells[1][ssrow]->Text;
		   Taxon.Code += L".ud";
		   TSSForm->ReplaceVarCodes(&Taxon, ssrow, SUBALL);
		   msg = L"Undifferentiated taxon «" + Undiffs[i].Name + L"» is not in the Neotoma taxon table.";
		   MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
		   }
		 }
	   else {
		 Screen->Cursor = crDefault;
		 return;
		 }
	   TSSForm->SpreadSheetChanged = true;
	   }
	 }

   Screen->Cursor = crDefault;
   if (nchecked == 0) {
	 MessageDlg(L"No rows checked!", mtWarning, TMsgDlgButtons() << mbOK, 0);
	 return;
	 }

   for (int row=AdvColumnGrid1->RowCount-1; row > 1; row--) {
	 AdvColumnGrid1->GetCheckBoxState(0,row,checked);
	 if (checked)
	   AdvColumnGrid1->RemoveRows(row,1);
	 }
   AdvColumnGrid1->GetCheckBoxState(0,1,checked);
   if (checked) {
     AdvColumnGrid1->ClearNormalCells();
	 AdvColumnGrid1->SetCheckBoxState(0,1,false);
	 }
}
//---------------------------------------------------------------------------

void __fastcall TCheckHierarchyForm::cxButton3Click(TObject *Sender)
{
   if (!AdvColumnGrid1->Cells[2][1].IsEmpty()) {
     UnicodeString msg = L"Not all non-exclusive taxa resolved. Continue anyway?";
	 if (MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes) {
	   cxButton3->Visible = false;
	   FlowPanel1->Left = (Panel1->Width - cxButton1->Width - cxButton2->Width)/2;
	   FlowPanel1->Width = cxButton1->Width + cxButton2->Width;
	   FixType = FIXNOSIBLINGS;
	   DiffCheckNoSibs();
	   }
	 }
}
//---------------------------------------------------------------------------

void __fastcall TCheckHierarchyForm::ipsJSONS1SSLServerAuthentication(TObject *Sender,
          TipsJSONSSSLServerAuthenticationEventParams *e)
{
   e->Accept = true;
}
//---------------------------------------------------------------------------

