//---------------------------------------------------------------------------

#include <vcl.h>
#include "pch.h"
#pragma hdrstop

#include "TNSubmit.h"
#ifndef TINeotomaH
#include "TINeotoma.h"
#endif
#include <map>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDropDownEdit"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxGroupBox"
#pragma link "cxLabel"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxMaskEdit"
#pragma link "cxRadioGroup"
#pragma link "cxTextEdit"
#pragma link "cxMemo"
#pragma link "AdvCGrid"
#pragma link "AdvGrid"
#pragma link "AdvObj"
#pragma link "BaseGrid"
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
TSubmitForm *SubmitForm;

//---------------------------------------------------------------------------
__fastcall TSubmitForm::TSubmitForm(int d1, int geochron_db_id, vector<DATASET>* datasets_ptr,
	 int EPDSiteID, TComponent* Owner) : TForm(Owner)
{
   first_dataset = d1;
   FGeochron.DatabaseID = geochron_db_id;
   DatasetsPtr = datasets_ptr;
   for (unsigned int i=first_dataset; i < DatasetsPtr->size(); i++)
	 DatasetsPtr->at(i).NeotomaDatabaseID = -1;

   int row = 1;
   if (FGeochron.DatabaseID > 0)
	 AdvColumnGrid1->Cells[0][row++] = L"Geochronologic";

   set<UnicodeString> DatasetTypes;
   for (unsigned int i=first_dataset; i < DatasetsPtr->size(); i++) {
	 UnicodeString DatasetType = DatasetsPtr->at(i).DatasetType;
	 if (DatasetTypes.count(DatasetType) == 0)
	   DatasetTypes.insert(DatasetType);
	 }

   for (set<UnicodeString>::iterator it = DatasetTypes.begin(); it != DatasetTypes.end(); it++)
	 AdvColumnGrid1->Cells[0][row++] = *it;

   AdvColumnGrid1->RowCount = row;

   if (EPDSiteID > -1) {
	 for (int r = 1; r < AdvColumnGrid1->RowCount; r++) {
	   AdvColumnGrid1->Cells[1][r] = L"European Pollen Database";
       AdvColumnGrid1->Cells[2][r] = L"Database";
	   }
	 }

   map<int,UnicodeString>::iterator itr;
   map<int,UnicodeString>::iterator begin = Login->Databases->Items.begin();
   map<int,UnicodeString>::iterator end = Login->Databases->Items.end();
   for (itr = begin; itr != end; itr++)
	 DatabaseIDmap[itr->second] = itr->first;   // UnicodeString, int

   for (map<UnicodeString,int>::iterator it = DatabaseIDmap.begin(); it != DatabaseIDmap.end(); it++)
	 AdvColumnGrid1->Columns->Items[1]->ComboItems->Add(it->first);
}
//---------------------------------------------------------------------------

// Ok button
void __fastcall TSubmitForm::cxButton1Click(TObject *Sender)
{
   UnicodeString msg;
   map<UnicodeString,int> DataSourceID;
   DataSourceID[L"Contributor"] = 1;
   DataSourceID[L"Database"] = 7;
   DataSourceID[L"Publication"] = 8;

   for (int row=1; row<AdvColumnGrid1->RowCount; row++) {
	 if (AdvColumnGrid1->Cells[1][row].IsEmpty()) {
	   msg = L"Constitutent database not selected in row " + IntToStr(row) + L"!";
	   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return;
	   }
	 }

   for (int row=1; row<AdvColumnGrid1->RowCount; row++) {
	 if (AdvColumnGrid1->Cells[2][row].IsEmpty()) {
	   msg = L"Data source not selected in row " + IntToStr(row) + L"!";
	   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return;
	   }
	 }

   int row1 = 1;
   if (SameText(AdvColumnGrid1->Cells[0][row1], L"Geochronologic")) {
	 FGeochron.DatabaseID = DatabaseIDmap[AdvColumnGrid1->Cells[1][row1]];
	 FGeochron.SubmissionTypeID = DataSourceID[AdvColumnGrid1->Cells[2][row1]];
	 FGeochron.Notes = AdvColumnGrid1->Cells[3][row1];
	 row1++;
	 }

   // get DatabaseIDs and Submission Notes for datasets from grid
   for (unsigned int i=first_dataset; i<DatasetsPtr->size(); i++) {
	 UnicodeString DatasetType = DatasetsPtr->at(i).DatasetType;
	 for (int row=row1; row<AdvColumnGrid1->RowCount; row++) {
	   if (SameText(DatasetType, AdvColumnGrid1->Cells[0][row])) {
		 DatasetsPtr->at(i).NeotomaDatabaseID = DatabaseIDmap[AdvColumnGrid1->Cells[1][row]];
		 DatasetsPtr->at(i).NeotomaSubmissionTypeID = DataSourceID[AdvColumnGrid1->Cells[2][row]];
		 DatasetsPtr->at(i).NeotomaSubmissionNotes = AdvColumnGrid1->Cells[3][row];
		 break;
		 }
	   }
	 }

   ModalResult = mrOk;
}
//---------------------------------------------------------------------------

