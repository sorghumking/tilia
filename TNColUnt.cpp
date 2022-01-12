//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TNColUnt.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxMemo"
#pragma link "cxTextEdit"
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
#pragma link "AdvCGrid"
#pragma link "AdvGrid"
#pragma link "AdvObj"
#pragma link "AdvUtil"
#pragma link "BaseGrid"
#pragma link "cxRadioGroup"
#pragma link "cxButtons"
#pragma link "cxLabel"
#pragma resource "*.dfm"
TNeotomaCollUnitForm *NeotomaCollUnitForm;
//---------------------------------------------------------------------------
__fastcall TNeotomaCollUnitForm::TNeotomaCollUnitForm(UnicodeString Handle, SITE* site_ptr,
	vector<NEOTOMACOLLUNIT>& collunits, TComponent* Owner) : TForm(Owner)
{
   Caption = L"Collection unit: " + Handle;
   SiteCollUnits = collunits;
   cxLabel1->Caption = L"The following collection units exist for site «" + site_ptr->SiteName +
	 L"», SiteID = " + IntToStr(site_ptr->NeotomaSiteID) +
	 L". Click a check box to assign new datasets for collection unit «" + Handle +
	 L"» to an existing Neotoma collection unit.";
   AdvColumnGrid1->RowCount = SiteCollUnits.size() + 1;
   for (unsigned int i=0; i<SiteCollUnits.size(); i++) {
	 int row = i + 1;
	 AdvColumnGrid1->Cells[1][row] = IntToStr(SiteCollUnits[i].CollectionUnitID);
	 AdvColumnGrid1->Cells[2][row] = SiteCollUnits[i].Handle;
	 AdvColumnGrid1->Cells[3][row] = SiteCollUnits[i].CollUnitName;
	 }
   for (int i=1; i<AdvColumnGrid1->RowCount; i++)
	 AdvColumnGrid1->AddCheckBox(0, i, false, false);
   CollectionUnitID = -1;
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaCollUnitForm::AdvColumnGrid1CheckBoxChange(TObject *Sender,
		  int ACol, int ARow, bool State)
{
   // uncheck all other rows
   if (State) {
	 bool state;
	 for (int row=1; row<AdvColumnGrid1->RowCount; row++) {
	   if (row == ARow) continue;
	   AdvColumnGrid1->GetCheckBoxState(0, row, state);
	   if (state)
		 AdvColumnGrid1->SetCheckBoxState(0, row, false);
	   }
	 cxRadioButton1->Enabled = true;
	 cxRadioButton1->Checked = true;
	 }
   else {
	 cxRadioButton2->Checked = true;
	 cxRadioButton1->Enabled = false;
	 }
}
//---------------------------------------------------------------------------

// assign data to new collection unit
void __fastcall TNeotomaCollUnitForm::cxRadioButton2Click(TObject *Sender)
{
   if (cxRadioButton2->Checked) {
	 AdvColumnGrid1->UnCheckAll(0);
	 cxRadioButton1->Enabled = false;
	 }
}
//---------------------------------------------------------------------------

// continue button
void __fastcall TNeotomaCollUnitForm::cxButton2Click(TObject *Sender)
{
   if (cxRadioButton1->Checked) {
	 bool state;
	 for (int row=1; row<AdvColumnGrid1->RowCount; row++) {
	   AdvColumnGrid1->GetCheckBoxState(0, row, state);
	   if (state) {
		 CollectionUnitID = AdvColumnGrid1->Cells[1][row].ToInt();
		 break;
		 }
	   }
	 }
}
//---------------------------------------------------------------------------

