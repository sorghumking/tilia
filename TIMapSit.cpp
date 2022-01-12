//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TIMapSit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxLabel"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "AdvCGrid"
#pragma link "AdvGrid"
#pragma link "AdvObj"
#pragma link "BaseGrid"
#pragma link "cxButtons"
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
#pragma link "dxSkinVS2010"
#pragma link "dxSkinWhiteprint"
#pragma link "dxSkinXmas2008Blue"
#pragma link "AdvUtil"
#pragma link "dxSkinOffice2016Colorful"
#pragma link "dxSkinOffice2016Dark"
#pragma link "dxSkinVisualStudio2013Blue"
#pragma link "dxSkinVisualStudio2013Dark"
#pragma link "dxSkinVisualStudio2013Light"
#pragma resource "*.dfm"
TMapSiteForm *MapSiteForm;
TEPDMapSiteForm *EPDMapSiteForm;
//---------------------------------------------------------------------------

__fastcall TMapSiteForm::TMapSiteForm(TComponent* Owner) : TForm(Owner)
{

}
//---------------------------------------------------------------------------

__fastcall TMapSiteForm::TMapSiteForm(int SiteID, UnicodeString SiteName,
	vector<MAPDATASET>& MapDatasets, TComponent* Owner) : TForm(Owner)
{
   FSiteID = SiteID;
   UnicodeString Text = L"SiteID " + IntToStr(SiteID);
   Caption = Text;
   cxLabel1->Caption = SiteName;
   AdvColumnGrid1->RowCount = MapDatasets.size() + 1;
   for (unsigned int i=0,row=1; i<MapDatasets.size(); i++,row++) {
	 AdvColumnGrid1->Cells[1][row] = MapDatasets[i].CollUnitID;
	 AdvColumnGrid1->Cells[2][row] = MapDatasets[i].DatasetID;
	 AdvColumnGrid1->Cells[3][row] = MapDatasets[i].DatasetType;
	 if (!MapDatasets[i].CollUnitName.IsEmpty()) {
	   if (CollUnits.count(MapDatasets[i].CollUnitID) == 0)
		 CollUnits[MapDatasets[i].CollUnitID] = MapDatasets[i].CollUnitName;
	   }
	 }
   AdvColumnGrid1->AddCheckBoxColumn(0,false,false);
   AdvColumnGrid1->QSort();
}
//---------------------------------------------------------------------------

void __fastcall TMapSiteForm::AdvColumnGrid1CheckBoxClick(TObject *Sender, int ACol,
		  int ARow, bool State)
{
   if (ARow == 0) {
     cxButton1->Enabled = State;
	 return;
	 }

   bool any_checked = false;
   if (State) {
	 int CollUnitID = AdvColumnGrid1->Cells[1][ARow].ToInt();
	 for (int row=1; row<AdvColumnGrid1->RowCount; row++) {
	   if (row != ARow) {
		 UnicodeString DatasetType = AdvColumnGrid1->Cells[3][row];
		 if (CollUnitID == AdvColumnGrid1->Cells[1][row].ToInt()) {
		   if (SameText(DatasetType, L"geochronologic") || SameText(DatasetType, L"loss-on-ignition")) {
			 AdvColumnGrid1->SetCheckBoxState(0,row,true);
			 any_checked = true;
			 }
		   }
		 //else
		 //  AdvColumnGrid1->SetCheckBoxState(0,row,false);
		 }
	   }
	 }
   if (!any_checked) {
	 for (int row=1; row<AdvColumnGrid1->RowCount; row++) {
	   AdvColumnGrid1->GetCheckBoxState(0,row,any_checked);
	   if (any_checked) break;
	   }
	 }
   cxButton1->Enabled = any_checked;
}
//---------------------------------------------------------------------------

// download button
void __fastcall TMapSiteForm::cxButton1Click(TObject *Sender)
{
   FSelectedDatasets.clear();
   for (int row=1; row<AdvColumnGrid1->RowCount; row++) {
	 bool state;
	 AdvColumnGrid1->GetCheckBoxState(0,row,state);
	 if (state) {
	   MAPDATASET mds;
	   mds.SiteID = FSiteID;
	   mds.CollUnitID = AdvColumnGrid1->Cells[1][row].ToInt();
	   mds.DatasetID = AdvColumnGrid1->Cells[2][row].ToInt();
	   mds.DatasetType = AdvColumnGrid1->Cells[3][row];
	   FSelectedDatasets.push_back(mds);
	   }
	 }

   UnicodeString msg = L"Download Dataset";
   if (FSelectedDatasets.size() > 1)
	 msg += L"s";
   msg += L"?\n";
   for (unsigned int i=0; i<FSelectedDatasets.size(); i++) {
	 msg += (L"\nDatasetID " + IntToStr(FSelectedDatasets[i].DatasetID) + L": " +
			 FSelectedDatasets[i].DatasetType);
	 }

   if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes)
     ModalResult = mrOk;
}
//---------------------------------------------------------------------------

void __fastcall TMapSiteForm::AdvColumnGrid1CellBalloon(TObject *Sender, int ACol,
		  int ARow, UnicodeString &ATitle, UnicodeString &AText, int &AIcon)
{
   if (ARow == 0)
     return;

   AIcon = 1;
   ATitle = cxLabel1->Caption;
   int CollUnitID;

   switch (ACol) {
	 case 1:
	   CollUnitID = AdvColumnGrid1->Cells[1][ARow].ToInt();
	   if (CollUnits.count(CollUnitID) == 1)
		 AText = L"Collection Unit: " + CollUnits[CollUnitID];
	   else
		 AText = L"CollectionUnitID " + IntToStr(CollUnitID);
	   break;
	 case 2:
	   AText = L"DatsetID: " + AdvColumnGrid1->Cells[2][ARow];
	   break;
	 case 3:
	   AText = L"DatasetType: " + AdvColumnGrid1->Cells[3][ARow];
	   break;
	 }
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

__fastcall TEPDMapSiteForm::TEPDMapSiteForm(UnicodeString SiteName,
	map<int,pair<UnicodeString,UnicodeString> >& Entities,
	TComponent* Owner) : TMapSiteForm(Owner)
{
   Caption = SiteName;
   cxLabel1->Caption = SiteName;
   AdvColumnGrid1->MouseActions->CheckAllCheck = false;
   AdvColumnGrid1->Columns->Items[1]->Header = L"E#";
   AdvColumnGrid1->Columns->Items[2]->Header = L"Sigle";
   AdvColumnGrid1->Columns->Items[3]->Header = L"Name";
   AdvColumnGrid1->Columns->Items[3]->Alignment = taRightJustify;
   AdvColumnGrid1->Columns->Items[2]->Width = 120;
   AdvColumnGrid1->RowCount = Entities.size() + 1;

   map<int,pair<UnicodeString,UnicodeString> >::iterator itr;
   map<int,pair<UnicodeString,UnicodeString> >::iterator begin = Entities.begin();
   map<int,pair<UnicodeString,UnicodeString> >::iterator end = Entities.end();
   int row = 1;
   for (itr = begin; itr != end; itr++) {
	 AdvColumnGrid1->Cells[1][row] = itr->first;
	 AdvColumnGrid1->Cells[2][row] = itr->second.first;
	 AdvColumnGrid1->Cells[3][row++] = itr->second.second;
	 }
   AdvColumnGrid1->AddCheckBoxColumn(0,false,false);
}
//---------------------------------------------------------------------------

void __fastcall TEPDMapSiteForm::AdvColumnGrid1CheckBoxClick(TObject *Sender, int ACol,
		  int ARow, bool State)
{
   if (AdvColumnGrid1->RowCount > 2 && State) {
	 for (int row=1; row<AdvColumnGrid1->RowCount; row++) {
	   if (row != ARow)
		 AdvColumnGrid1->SetCheckBoxState(0,row,false);
	   }
	 }
   cxButton1->Enabled = State;
}
//---------------------------------------------------------------------------

// download button
void __fastcall TEPDMapSiteForm::cxButton1Click(TObject *Sender)
{
   for (int row=1; row<AdvColumnGrid1->RowCount; row++) {
	 bool state;
	 AdvColumnGrid1->GetCheckBoxState(0,row,state);
	 if (state) {
	   FENr = AdvColumnGrid1->Cells[1][row].ToInt();
	   break;
	   }
	 }
   ModalResult = mrOk;
}
//---------------------------------------------------------------------------

void __fastcall TEPDMapSiteForm::AdvColumnGrid1CellBalloon(TObject *Sender, int ACol,
		  int ARow, UnicodeString &ATitle, UnicodeString &AText, int &AIcon)
{
   if (ARow == 0)
     return;

   AIcon = 1;
   ATitle = cxLabel1->Caption;
   int CollUnitID;

   switch (ACol) {
	 case 1:
	   AText = L"E# " + AdvColumnGrid1->Cells[1][ARow];
	   break;
	 case 2:
	   AText = L"Sigle: " + AdvColumnGrid1->Cells[2][ARow];
	   break;
	 case 3:
	   AText = L"Entity Name: " + AdvColumnGrid1->Cells[3][ARow];
	   break;
	 }
}
//---------------------------------------------------------------------------



