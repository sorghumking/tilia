//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TISelSpe.h"
#ifndef TIsotopeH
#include "TIsotope.h"
#endif

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvCGrid"
#pragma link "AdvGrid"
#pragma link "AdvObj"
#pragma link "BaseGrid"
#pragma link "cxButtons"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
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
TSelectSpecimensForm *SelectSpecimensForm;
//---------------------------------------------------------------------------
__fastcall TSelectSpecimensForm::TSelectSpecimensForm(short import_style, TComponent* Owner)
	: TForm(Owner)
{
   TSSForm = (TTilSpreadSheetForm*)Owner;
   ImportStyle = import_style;

   int specrow = 1;

   // get list of specimens already in isotope grid
   vector<SPECIMEN*> IsotopeSpecimens;
   for (int row=1; row<TSSForm->AdvIsotopeStringGrid->RowCount; row++) {
	 if (TSSForm->AdvIsotopeStringGrid->Objects[0][row] != NULL) {
	   SPECIMEN* Specimen = (SPECIMEN*)TSSForm->AdvIsotopeStringGrid->Objects[0][row];
	   IsotopeSpecimens.push_back(Specimen);
	   }
	 else
	   break;
	 }

   int StartCol = TSSForm->AbsHeaderColCount(TSSForm->ProfGrid1);
   int EndCol = TSSForm->AbsContentColCount(TSSForm->ProfGrid1);
   int StartRow = TSSForm->AbsHeaderRowCount(TSSForm->ProfGrid1);
   int EndRow = TSSForm->AbsContentRowCount(TSSForm->ProfGrid1);
   for (int col=StartCol; col<=EndCol; col++) {
	 for (int row=StartRow; row<=EndRow; row++) {
	   TProfGridCell* ACell = TSSForm->ProfGrid1->AbsoluteCells[col][row];
	   if (ACell->CellObject != NULL) {
		 CELLOBJECT* CellObject = (CELLOBJECT*)ACell->CellObject;
		 if (CellObject->ObjectType == CELLSPECIMENS) {
		   TList* Specimens = (TList*)CellObject->Object;
		   for (int i=0; i<Specimens->Count; i++) {
			 SPECIMEN *Specimen = (SPECIMEN*)Specimens->Items[i];
			 if (find(IsotopeSpecimens.begin(), IsotopeSpecimens.end(), Specimen) != IsotopeSpecimens.end())
			   continue;   // specimen already in isotopes grid
			 AdvColumnGrid1->Objects[0][specrow] = (TObject*)Specimen;
			 UnicodeString AnalUnit = L"";
			 if (!TSSForm->ProfGrid1->AbsoluteCells[col][1]->Text.IsEmpty())  // sample depth
			   AnalUnit = TSSForm->ProfGrid1->AbsoluteCells[col][1]->Text;
			 if (!TSSForm->ProfGrid1->AbsoluteCells[col][2]->Text.IsEmpty()) { // sample name
			   if (!AnalUnit.IsEmpty())
				 AnalUnit += L" | ";
			   AnalUnit += TSSForm->ProfGrid1->AbsoluteCells[col][2]->Text;
			   }
			 AdvColumnGrid1->Cells[1][specrow] = AnalUnit;
			 AdvColumnGrid1->Cells[3][specrow] = IntToStr(row);
			 AdvColumnGrid1->Objects[3][specrow] = (TObject*)((int*)col);
			 AdvColumnGrid1->Cells[4][specrow] = TSSForm->ProfGrid1->AbsoluteCells[2][row]->Text;  // taxon name
			 if (!Specimen->Element.IsEmpty()) {
			   UnicodeString Element;
			   Element = Specimen->Element;
			   if (!Specimen->Symmetry.IsEmpty())
				 Element += (L";" + Specimen->Symmetry);
			   if (!Specimen->Portion.IsEmpty())
				 Element += (L";" + Specimen->Portion);
			   if (!Specimen->Maturity.IsEmpty())
				 Element += (L";" + Specimen->Maturity);
			   AdvColumnGrid1->Cells[5][specrow] = Element;
			   }
			 AdvColumnGrid1->Cells[6][specrow] = Specimen->UserSpecimenID;
			 specrow++;
			 }
		   }
		 }
	   }
	 }

   AdvColumnGrid1->RowCount = specrow;
   AdvColumnGrid1->AddCheckBoxColumn(2,false,false);
   AdvColumnGrid1->Group(1);
   AdvColumnGrid1->Row = 2;
   AdvColumnGrid1->GotoCell(2,2);
   Width -= 64;
   FlowPanel1->Left -= 32;
}
//---------------------------------------------------------------------------

void __fastcall TSelectSpecimensForm::AdvColumnGrid1CanClickCell(TObject *Sender,
		  int ARow, int ACol, bool &Allow)
{
   if (ARow == 0 && ACol == 1) {
	 Allow = false;  // overrides checking all boxes in column
	 bool State;
	 AdvColumnGrid1->GetCheckBoxState(1,0,State);
	 State = !State;
	 AdvColumnGrid1->SetCheckBoxState(1,0,State);
	 for (int displrow=2; displrow<AdvColumnGrid1->RowCount; displrow++) {
	   if (!AdvColumnGrid1->GetNodeState(displrow)) {  // parent node is expanded
		 int realrow = AdvColumnGrid1->RealRowIndex(displrow);
		 AdvColumnGrid1->SetCheckBoxState(1, realrow, State);   // row is real row
		 }
	   }
	 }
}
//---------------------------------------------------------------------------

// Ok button
void __fastcall TSelectSpecimensForm::cxButton1Click(TObject *Sender)
{
   bool State;
   int OldRowCount = TSSForm->AdvIsotopeStringGrid->RowCount;
   int specrow = 2;
   int NewSpec = 0;

   if (ImportStyle == isoAPPEND) {
	 for (int row=2; row<TSSForm->AdvIsotopeStringGrid->RowCount; row++) {
	   if (TSSForm->AdvIsotopeStringGrid->AllCells[3][row].IsEmpty())
		 break;
	   else
		 specrow++;
	   }
	 if (TSSForm->AdvIsotopeStringGrid->AllCells[3][2].IsEmpty()) // first row of data
	   NewSpec--;
	 }
   else {     // isoINSERT
	 int count = 0;
	 for (int displrow=1; displrow<AdvColumnGrid1->RowCount; displrow++) {
	   int realrow = AdvColumnGrid1->RealRowIndex(displrow);
	   if (!AdvColumnGrid1->IsNode(displrow)) {
		 AdvColumnGrid1->GetCheckBoxState(1, realrow, State);
		 if (State)
		   count++;
		 }
	   }
	 specrow = TSSForm->AdvIsotopeStringGrid->Row;
	 if (!TSSForm->AdvIsotopeStringGrid->AllCells[3][2].IsEmpty()) // first row of data
	   TSSForm->AdvIsotopeStringGrid->InsertRows(specrow, count, true);
	 else
	   NewSpec--;
	 }

   //int NewSpec = 0;
   for (int displrow=1; displrow<AdvColumnGrid1->RowCount; displrow++) {
	 int realrow = AdvColumnGrid1->RealRowIndex(displrow);
	 if (!AdvColumnGrid1->IsNode(displrow)) {
	   AdvColumnGrid1->GetCheckBoxState(1, realrow, State);
	   if (State) {
		 int col = (int)((int*)AdvColumnGrid1->Objects[2][displrow]);
		 TSSForm->AdvIsotopeStringGrid->Objects[0][specrow] = AdvColumnGrid1->Objects[0][displrow];;
		 TSSForm->AdvIsotopeStringGrid->Cells[1][specrow] = TSSForm->ProfGrid1->AbsoluteCells[col][1]->Text; // depth
		 TSSForm->AdvIsotopeStringGrid->Cells[2][specrow] = TSSForm->ProfGrid1->AbsoluteCells[col][2]->Text; // analysis unit
		 TSSForm->AdvIsotopeStringGrid->Cells[3][specrow] = AdvColumnGrid1->Cells[3][displrow]; // taxon
		 TSSForm->AdvIsotopeStringGrid->Cells[4][specrow] = AdvColumnGrid1->Cells[4][displrow]; // element
		 TSSForm->AdvIsotopeStringGrid->Cells[5][specrow] = AdvColumnGrid1->Cells[5][displrow]; // UserSpecimenID
		 specrow++;
		 NewSpec++;
		 }
	   }
	 }

   TSSForm->AdvIsotopeStringGrid->RowCount = OldRowCount + NewSpec;
}
//---------------------------------------------------------------------------

