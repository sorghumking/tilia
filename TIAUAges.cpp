//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TIAUAges.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxLabel"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxCheckListBox"
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
TImportChronTabsheetForm *ImportChronTabsheetForm;
//---------------------------------------------------------------------------
__fastcall TImportChronTabsheetForm::TImportChronTabsheetForm(TComponent* Owner)
	: TForm(Owner)
{
   TSSForm = (TTilSpreadSheetForm*)Owner;
   if (TSSForm->AgeModelList->Count > 0) {
	 AdvColumnGrid1->RowCount = TSSForm->AgeModelList->Count + 1;
	 for (int i=0, row=1; i<TSSForm->AgeModelList->Count; i++, row++) {
	   AdvColumnGrid1->Cells[1][row] = IntToStr(TSSForm->AgeModelList->AgeModels[i]->ChronNumber);
	   AdvColumnGrid1->Cells[2][row] = TSSForm->AgeModelList->AgeModels[i]->ChronologyName;
	   }
	 AdvColumnGrid1->AddCheckBoxColumn(0, false, false);
	 }

   // get vector of Analysis Units and columns
   int AnalUnitRow = TSSForm->FindRowMD(ANAL_UNIT_NAME);
   int ThickRow = TSSForm->FindRowCodeIC(L"#Anal.Thick", TSSForm->ProfGrid1);
   int HeaderCols = TSSForm->AbsHeaderColCount(TSSForm->ProfGrid1);
   int ColCount = TSSForm->AbsContentColCount(TSSForm->ProfGrid1);
   for (int col=HeaderCols; col<=ColCount; col++) {
	 SSANALUNIT AnalUnit;
	 AnalUnit.col = col;
	 if (AnalUnitRow >= 2)
	   AnalUnit.Name = TSSForm->ProfGrid1->AbsoluteCells[col][AnalUnitRow]->Text;
	 if (!TSSForm->ProfGrid1->AbsoluteCells[col][1]->Value.IsEmpty())
	   AnalUnit.Depth = TSSForm->ProfGrid1->AbsoluteCells[col][1]->Value;
	 if (ThickRow > 0)
	   AnalUnit.Thickness = TSSForm->ProfGrid1->AbsoluteCells[col][ThickRow]->Value;
	 AnalUnits.push_back(AnalUnit);
	 }
}
//---------------------------------------------------------------------------

// Ok button
void __fastcall TImportChronTabsheetForm::cxButton1Click(TObject *Sender)
{
   ModalResult = mrOk;
   bool somthing_checked = false;

   if (TSSForm->ProfGrid1->Row < 3)
     TSSForm->ProfGrid1->Row = 3;

   Screen->Cursor = crHourGlass;
   TSSForm->ProfGrid1->DisableControls();
   TSSForm->ProfGrid1->SpreadsheetEnabled = false;

   try {
   try {
	 for (int row = AdvColumnGrid1->RowCount-1; row >= 1; row--) {
	   if (AdvColumnGrid1->IsChecked(0,row)) {
		 somthing_checked = true;
		 int ChronNo = AdvColumnGrid1->Cells[1][row].ToInt();
		 for (int i=0; i<TSSForm->AgeModelList->Count; i++) {
		   AGEMODEL* AgeModel = TSSForm->AgeModelList->AgeModels[i];
		   if (ChronNo == AgeModel->ChronNumber) {
			 bool has_age = false;
			 bool has_age_older = false;
			 bool has_age_younger = false;
			 for (int j=0; j<AgeModel->ChronControls->Count; j++) {
			   CHRON* ChronControl = (CHRON*)AgeModel->ChronControls->Items[j];
			   if (!has_age && !ChronControl->AgeValue.IsEmpty())
				 has_age = true;
			   if (!has_age_older && !ChronControl->AgeLimitOlder.IsEmpty())
				 has_age_older = true;
			   if (!has_age_younger && !ChronControl->AgeLimitYounger.IsEmpty())
				 has_age_younger = true;
			   if (has_age && has_age_older && has_age_younger)
				 break;
			   }
			 int ChronRow, ChronRowOlder, ChronRowYounger;
			 UnicodeString VarCodeAge, VarCodeYounger, VarCodeOlder;
			 if (has_age_older) {
			   VarCodeOlder = L"#Chron" + IntToStr(ChronNo) + L".Old";
			   ChronRowOlder = TSSForm->FindRowCodeIC(VarCodeOlder, TSSForm->ProfGrid1);
			   if (ChronRowOlder == 0)
				 TSSForm->EnterSSMetadataCode(VarCodeOlder, AgeModel->ChronologyName + L" Older");
			   }
			 if (has_age_younger) {
			   VarCodeYounger = L"#Chron" + IntToStr(ChronNo) + L".Young";
			   ChronRowYounger = TSSForm->FindRowCodeIC(VarCodeYounger, TSSForm->ProfGrid1);
			   if (ChronRowYounger == 0)
				 TSSForm->EnterSSMetadataCode(VarCodeYounger, AgeModel->ChronologyName + L" Younger");
			   }
			 if (has_age) {
			   VarCodeAge = L"#Chron" + IntToStr(ChronNo);
			   ChronRow = TSSForm->FindRowCodeIC(VarCodeAge, TSSForm->ProfGrid1);
			   if (ChronRow == 0)
				 TSSForm->EnterSSMetadataCode(VarCodeAge, AgeModel->ChronologyName);
			   }
			 if (has_age)
			   ChronRow = TSSForm->FindRowCodeIC(VarCodeAge, TSSForm->ProfGrid1);
			 if (has_age_older)
			   ChronRowOlder = TSSForm->FindRowCodeIC(VarCodeOlder, TSSForm->ProfGrid1);
			 if (has_age_younger)
			   ChronRowYounger = TSSForm->FindRowCodeIC(VarCodeYounger, TSSForm->ProfGrid1);

			 for (int j=0; j<AgeModel->ChronControls->Count; j++) {
			   CHRON* ChronControl = (CHRON*)AgeModel->ChronControls->Items[j];
			   for (unsigned int k=0; k<AnalUnits.size(); k++) {
				 bool found = false;
				 if (!ChronControl->AnalUnit.IsEmpty()) {
				   if (SameText(ChronControl->AnalUnit, AnalUnits[k].Name))
					 found = true;
				   }
				 else if (!ChronControl->Depth.IsEmpty()) {
				   if (!ChronControl->Thickness.IsEmpty()) {
					 if (ChronControl->Depth == AnalUnits[k].Depth && ChronControl->Thickness == AnalUnits[k].Thickness)
					   found = true;
					 }
				   else if (ChronControl->Depth == AnalUnits[k].Depth && AnalUnits[k].Thickness.IsEmpty())
					 found = true;
				   }

				 if (found)	{
				   if (!ChronControl->AgeValue.IsEmpty())
					 TSSForm->ProfGrid1->AbsoluteCells[AnalUnits[k].col][ChronRow]->Value = ChronControl->AgeValue;
				   if (!ChronControl->AgeLimitOlder.IsEmpty())
					 TSSForm->ProfGrid1->AbsoluteCells[AnalUnits[k].col][ChronRowOlder]->Value = ChronControl->AgeLimitOlder;
				   if (!ChronControl->AgeLimitYounger.IsEmpty())
					 TSSForm->ProfGrid1->AbsoluteCells[AnalUnits[k].col][ChronRowYounger]->Value = ChronControl->AgeLimitYounger;
				   }
				 }
			   }
			 break;
			 }
		   }
		 }
	   }
	 } catch(Exception &e)
	   {
	   MessageDlg(e.Message, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   ModalResult = mrNone;
	   }
	 }
   __finally {
	 TSSForm->ProfGrid1->SpreadsheetEnabled = true;
	 TSSForm->ProfGrid1->EnableControls();
	 Screen->Cursor = crDefault;
	 }

   if (!somthing_checked) {
	 MessageDlg(L"No chronologies checked!", mtWarning, TMsgDlgButtons() << mbOK, 0);
	 ModalResult = mrNone;
	 }
}
//---------------------------------------------------------------------------
