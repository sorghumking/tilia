//---------------------------------------------------------------------------
#include <vcl.h>
#include "pch.h"
#pragma hdrstop

#include <SysUtils.hpp>
#include "TIsotope.h"
#ifndef TISpreadH
#include "TISpread.h"
#endif
#ifndef TISelSpeH
#include "TISelSpe.h"
#endif
#ifndef TIsoSerH
#include "TIsoSer.h"
#endif
#ifndef TIIsoDatH
#include "TIsoDat.h"
#endif

//---------------------------------------------------------------------------

#pragma package(smart_init)

void TTilSpreadSheetForm::SetupIsotopeGrid(void)
{
   AdvIsotopeStringGrid->RowHeights[1] = 22;

   map<int,UnicodeString> IsoColHeaders; // col, header

   int n = 1;
   IsoColHeaders[n++] = L"Depth";
   IsoColHeaders[n++] = L"Unit";
   IsoColHeaders[n++] = L"Taxon";
   IsoColHeaders[n++] = L"Element";
   IsoColHeaders[n++] = L"Spec ID";
   IsoColHeaders[n++] = L"Type";
   IsoColHeaders[n++] = L"Serial ID";
   IsoColHeaders[n++] = L"Distance (mm)";
   IsoColHeaders[n++] = L"Depth (mm)";
   IsoColHeaders[n++] = L"Band Sampled";
   IsoColHeaders[n++] = L"Material Analyzed";  // col 11, start of carbon
   IsoColHeaders[n++] = L"Substrate";
   IsoColHeaders[n++] = L"Pretreatment";
   IsoColHeaders[n++] = L"Analyst";
   IsoColHeaders[n++] = L"Lab";
   IsoColHeaders[n++] = L"Lab Nr";
   IsoColHeaders[n++] = L"Mass (mg)";
   IsoColHeaders[n++] = L"Weight %";
   IsoColHeaders[n++] = L"Atomic %";
   IsoColHeaders[n++] = L"<P align=\"center\">δ<FONT size=\"6\"><SUP>13</SUP></FONT>C</P>";
   IsoColHeaders[n++] = L"SD";
   IsoColHeaders[n++] = L"Scale";
   IsoColHeaders[n++] = L"Reps";

   IsoColHeaders[n++] = L"C:N Ratio";

   IsoColHeaders[n++] = L"Material Analyzed";  // col 25, start of nitrogen
   IsoColHeaders[n++] = L"Substrate";
   IsoColHeaders[n++] = L"Pretreatment";
   IsoColHeaders[n++] = L"Analyst";
   IsoColHeaders[n++] = L"Lab";
   IsoColHeaders[n++] = L"Lab Nr";
   IsoColHeaders[n++] = L"Mass (mg)";
   IsoColHeaders[n++] = L"Weight %";
   IsoColHeaders[n++] = L"Atomic %";
   IsoColHeaders[n++] = L"<P align=\"center\">δ<FONT size=\"6\"><SUP>15</SUP></FONT>N</P>";
   IsoColHeaders[n++] = L"SD";
   IsoColHeaders[n++] = L"Scale";
   IsoColHeaders[n++] = L"Reps";
   IsoColHeaders[n++] = L"Material Analyzed";  // col 38, start of oxygen
   IsoColHeaders[n++] = L"Substrate";
   IsoColHeaders[n++] = L"Pretreatment";
   IsoColHeaders[n++] = L"Analyst";
   IsoColHeaders[n++] = L"Lab";
   IsoColHeaders[n++] = L"Lab Nr";
   IsoColHeaders[n++] = L"Mass (mg)";
   IsoColHeaders[n++] = L"Weight %";
   IsoColHeaders[n++] = L"Atomic %";
   IsoColHeaders[n++] = L"<P align=\"center\">δ<FONT size=\"6\"><SUP>18</SUP></FONT>O</P>";
   IsoColHeaders[n++] = L"SD";
   IsoColHeaders[n++] = L"Scale";
   IsoColHeaders[n++] = L"Reps";

   IsoColHeaders[n++] = L"O:H Ratio";

   IsoColHeaders[n++] = L"Material Analyzed";  // col 51, start of hydrogen
   IsoColHeaders[n++] = L"Substrate";
   IsoColHeaders[n++] = L"Pretreatment";
   IsoColHeaders[n++] = L"Analyst";
   IsoColHeaders[n++] = L"Lab";
   IsoColHeaders[n++] = L"Lab Nr";
   IsoColHeaders[n++] = L"Mass (mg)";
   IsoColHeaders[n++] = L"Weight %";
   IsoColHeaders[n++] = L"Atomic %";
   IsoColHeaders[n++] = L"<P align=\"center\">δD</P>";
   IsoColHeaders[n++] = L"SD";
   IsoColHeaders[n++] = L"Scale";
   IsoColHeaders[n++] = L"Reps";

   IsoColHeaders[n++] = L"Material Analyzed";  // col 51, start of sulfur
   IsoColHeaders[n++] = L"Substrate";
   IsoColHeaders[n++] = L"Pretreatment";
   IsoColHeaders[n++] = L"Analyst";
   IsoColHeaders[n++] = L"Lab";
   IsoColHeaders[n++] = L"Lab Nr";
   IsoColHeaders[n++] = L"Mass (mg)";
   IsoColHeaders[n++] = L"Weight %";
   IsoColHeaders[n++] = L"Atomic %";
   IsoColHeaders[n++] = L"<P align=\"center\">δ<FONT size=\"6\"><SUP>34</SUP></FONT>S</P>";
   IsoColHeaders[n++] = L"SD";
   IsoColHeaders[n++] = L"Scale";
   IsoColHeaders[n++] = L"Reps";

   IsoColHeaders[n++] = L"Material Analyzed";  // col 51, start of strontium
   IsoColHeaders[n++] = L"Substrate";
   IsoColHeaders[n++] = L"Pretreatment";
   IsoColHeaders[n++] = L"Analyst";
   IsoColHeaders[n++] = L"Lab";
   IsoColHeaders[n++] = L"Lab Nr";
   IsoColHeaders[n++] = L"Mass (mg)";
   IsoColHeaders[n++] = L"Weight %";
   IsoColHeaders[n++] = L"Atomic %";
   IsoColHeaders[n++] = L"Total Sr (ppm)";
   IsoColHeaders[n++] = L"<P align=\"center\"><FONT size=\"6\"><SUP>87</SUP></FONT>Sr/<FONT size=\"6\"><SUP>86</SUP></FONT>Sr</P>";
   IsoColHeaders[n++] = L"SD";
   IsoColHeaders[n++] = L"Reps";

   for (map<int,UnicodeString>::iterator itr = IsoColHeaders.begin(); itr != IsoColHeaders.end(); itr++)
	 AdvIsotopeStringGrid->AllCells[itr->first][1] = itr->second;

   IsoCols[isoCarbon] = pair<int,int>(11,23);    // carbon
   IsoCols[isoCNratio] = pair<int,int>(24,24);   // C:N
   IsoCols[isoNitrogen] = pair<int,int>(25,37);  // nitrogen
   IsoCols[isoOxygen] = pair<int,int>(38,50);    // oxygen
   IsoCols[isoOHratio] = pair<int,int>(51,51);   // O:H
   IsoCols[isoHydrogen] = pair<int,int>(52,64);  // hydrogen
   IsoCols[isoSulfur] = pair<int,int>(65,77);    // sulfur
   IsoCols[isoStrontium] = pair<int,int>(78,90); // strontium

   for (int col=1; col <= AdvIsotopeStringGrid->ColCount; col++)
	 AdvIsotopeStringGrid->Cells[col][0] = L"";

   AdvIsotopeStringGrid->AllCells[1][0] = L"Specimen";
   AdvIsotopeStringGrid->AllCells[2][0] = L"Specimen";
   AdvIsotopeStringGrid->AllCells[6][0] = L"Sample";
   AdvIsotopeStringGrid->AllCells[IsoCols[isoCNratio].first][0] = L"C:N";
   AdvIsotopeStringGrid->AllCells[IsoCols[isoOHratio].first][0] = L"O:H";
   AdvIsotopeStringGrid->ColWidths[3] = 128;      // make taxon column wider
   AdvIsotopeStringGrid->MergeCells(1,0,5,1);     // merge fixed specimen column header
   AdvIsotopeStringGrid->HideColumns(7,90);       // 7-10 series, 11-23 C, 24 C:N, 25-37 N, 38-50 O
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::AdvIsotopeStringGridGetAlignment(TObject *Sender,
		  int ARow, int ACol, TAlignment &HAlign, TVAlignment &VAlign)
{
   if (ARow == 0 || ACol == 0)
	 HAlign = taCenter;
   else if (ACol > 0 && (ARow == 0| ARow == 1))
	 HAlign = taCenter;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::AdvIsotopeStringGridGetCellColor(TObject *Sender,
		  int ARow, int ACol, TGridDrawState AState, TBrush *ABrush, TFont *AFont)
{
   if (ACol > 0 && ARow == 1)
	 AFont->Color = clNavy;
   else if (ARow == 0) {
	 if (ACol >= 1 && ACol <= 10)
	   AFont->Color = clNavy;
	 else {
	   short isotope = GetIsotopeColumn(ACol);
	   switch (isotope) {
		 case isoCarbon:
		   ABrush->Color = (TColor)RGB(38, 38, 38);
		   break;
		 case isoCNratio:
		   AFont->Color = clWhite;
		   ABrush->Color = (TColor)RGB(0, 75, 75);
		   break;
		 case isoNitrogen:
		   ABrush->Color = (TColor)RGB(0, 153, 153);
		   break;
		 case isoOxygen:
		   ABrush->Color = (TColor)RGB(255, 41, 41);
		   break;
		 case isoOHratio:
		   AFont->Color = clWhite;
		   ABrush->Color = (TColor)RGB(255, 142, 123);
		   break;
		 case isoHydrogen:
		   ABrush->Color = (TColor)RGB(255, 242, 204);
		   break;
		 case isoSulfur:
		   ABrush->Color = (TColor)RGB(255, 217, 102);
		   break;
		 case isoStrontium:
		   ABrush->Color = (TColor)RGB(0, 255, 0);
		   break;
		 }
	   }


	 /*
	 else if (ACol >= IsoCols[isoCarbon].first && ACol <= IsoCols[isoCarbon].second) {    // carbon
	   //AFont->Color = clWhite;
	   ABrush->Color = (TColor)RGB(38, 38, 38);
	   }
	 else if (ACol == IsoCols[isoCNratio].first) {                  // C:N
	   AFont->Color = clWhite;
	   ABrush->Color = (TColor)RGB(0, 75, 75);
	   }
	 else if (ACol >= IsoCols[isoNitrogen].first && ACol <= IsoCols[isoNitrogen].second) {    // nitrogen
	   //AFont->Color = clWhite;
	   ABrush->Color = (TColor)RGB(0, 153, 153);
	   }
	 else if (ACol >= IsoCols[isoOxygen].first && ACol <= IsoCols[isoOxygen].second) {    // oxygen
	   //AFont->Color = clWhite;
	   ABrush->Color = (TColor)RGB(255, 41, 41);
	   }
	 else if (ACol == IsoCols[isoOHratio].first) {                  // O:H
	   AFont->Color = clWhite;
	   ABrush->Color = (TColor)RGB(255, 142, 123);
	   }
	 else if (ACol >= IsoCols[isoHydrogen].first && ACol <= IsoCols[isoHydrogen].second) {    // hydrogen
	   //AFont->Color = clBlack;
	   ABrush->Color = (TColor)RGB(255, 242, 204);
	   }
	 else if (ACol >= IsoCols[isoSulfur].first && ACol <= IsoCols[isoSulfur].second) {    // sulfur
	   //AFont->Color = clBlack;
	   ABrush->Color = (TColor)RGB(255, 217, 102);
	   }
	 else if (ACol >= IsoCols[isoStrontium].first && ACol <= IsoCols[isoStrontium].second) {    // strontium
	   //AFont->Color = clBlack;
	   ABrush->Color = (TColor)RGB(0, 255, 0);
	   }
	 */
	 }
   else if (!AdvIsotopeStringGrid->IsHiddenColumn(7)) {   // series exist
	 if (AdvIsotopeStringGrid->IsMergedCell(6,ARow)) {
	   if (ACol >= 6)
		 ABrush->Color = (TColor)RGB(198, 224, 180);
	   else if (ACol >= 1)
		 ABrush->Color = (TColor)RGB(169, 208, 142);
	   }
	 else {
	   if (ACol == 7)
		 ABrush->Color = clBtnFace;
	   else if (ACol >= 8 && ACol <= 10 &&
				(SameText(AdvIsotopeStringGrid->Cells[6][ARow], L"bulk") ||
				AdvIsotopeStringGrid->Cells[6][ARow].IsEmpty())) {
			ABrush->Color = clBtnFace;
		 }
	   }
	 }
   else if (ACol >= 7 && ACol <= 10 && AdvIsotopeStringGrid->IsHiddenColumn(7)) {
	 ABrush->Color = clWindow;
	 }
}
//---------------------------------------------------------------------------

short TTilSpreadSheetForm::GetIsotopeColumn(int ACol)
{
   if (ACol >= IsoCols[isoCarbon].first && ACol <= IsoCols[isoCarbon].second)     // carbon
	 return(isoCarbon);
   else if (ACol == IsoCols[isoCNratio].first)                   // C:N
	 return(isoCNratio);
   else if (ACol >= IsoCols[isoNitrogen].first && ACol <= IsoCols[isoNitrogen].second)     // nitrogen
	 return(isoNitrogen);
   else if (ACol >= IsoCols[isoOxygen].first && ACol <= IsoCols[isoOxygen].second)     // oxygen
	 return(isoOxygen);
   else if (ACol == IsoCols[isoOHratio].first)                   // O:H
	 return(isoOHratio);
   else if (ACol >= IsoCols[isoHydrogen].first && ACol <= IsoCols[isoHydrogen].second)     // hydrogen
	 return(isoHydrogen);
   else if (ACol >= IsoCols[isoSulfur].first && ACol <= IsoCols[isoSulfur].second)     // sulfur
	 return(isoSulfur);
   else if (ACol >= IsoCols[isoStrontium].first && ACol <= IsoCols[isoStrontium].second)     // strontium
	 return(isoStrontium);
   return -1;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::AdvIsotopeStringGridGetCellGradient(TObject *Sender,
		  int ARow, int ACol, TColor &Color, TColor &ColorTo, TColor &ColorMirror,
		  TColor &ColorMirrorTo, TCellGradientDirection &GD)
{
   if (ARow == 0) {
	 if (ACol >= 1 && ACol <= 5) {    // specimen
	   Color = (TColor)RGB(189, 215, 238);
	   ColorTo = (TColor)RGB(189, 215, 238);
	   ColorMirrorTo = (TColor)RGB(189, 215, 238);
	   }
	 else {
	   short isotope = GetIsotopeColumn(ACol);
	   switch (isotope) {
		 case isoCarbon:
           Color = (TColor)RGB(38, 38, 38);
		   ColorTo = (TColor)RGB(38, 38, 38);
		   ColorMirrorTo = (TColor)RGB(38, 38, 38);
		   break;
		 case isoCNratio:
           Color = (TColor)RGB(0, 75, 75);
		   ColorTo = (TColor)RGB(0, 75, 75);
		   ColorMirrorTo = (TColor)RGB(0, 75, 75);
		   break;
		 case isoNitrogen:
           Color = (TColor)RGB(0, 153, 153);
		   ColorTo = (TColor)RGB(0, 153, 153);
		   ColorMirrorTo = (TColor)RGB(0, 153, 153);
		   break;
		 case isoOxygen:
           Color = (TColor)RGB(255, 41, 41);
		   ColorTo = (TColor)RGB(255, 41, 41);
		   ColorMirrorTo = (TColor)RGB(255, 41, 41);
		   break;
		 case isoOHratio:
           Color = (TColor)RGB(255, 142, 123);
		   ColorTo = (TColor)RGB(255, 142, 123);
		   ColorMirrorTo = (TColor)RGB(255, 142, 123);
		   break;
		 case isoHydrogen:
           Color = (TColor)RGB(255, 242, 204);
		   ColorTo = (TColor)RGB(255, 242, 204);
		   ColorMirrorTo = (TColor)RGB(255, 242, 204);
		   break;
		 case isoSulfur:
		   Color = (TColor)RGB(255, 217, 102);
		   ColorTo = (TColor)RGB(255, 217, 102);
		   ColorMirrorTo = (TColor)RGB(255, 217, 102);
		   break;
		 case isoStrontium:
           Color = (TColor)RGB(0, 255, 0);
		   ColorTo = (TColor)RGB(0, 255, 0);
		   ColorMirrorTo = (TColor)RGB(0, 255, 0);
		   break;
		 }
	   }
	 /*
	 else if (ACol >= IsoCols[isoCarbon].first && ACol <= IsoCols[isoCarbon].second) {   // carbon
	   Color = (TColor)RGB(38, 38, 38);
	   ColorTo = (TColor)RGB(38, 38, 38);
	   ColorMirrorTo = (TColor)RGB(38, 38, 38);
	   }
	 else if (ACol == IsoCols[isoCNratio].first) {   // C:N
	   Color = (TColor)RGB(0, 75, 75);
	   ColorTo = (TColor)RGB(0, 75, 75);
	   ColorMirrorTo = (TColor)RGB(0, 75, 75);
	   }
	 else if (ACol >= IsoCols[isoNitrogen].first && ACol <= IsoCols[isoNitrogen].second) {   // nitrogen
	   Color = (TColor)RGB(0, 153, 153);
	   ColorTo = (TColor)RGB(0, 153, 153);
	   ColorMirrorTo = (TColor)RGB(0, 153, 153);
	   }
	 else if (ACol >= IsoCols[isoOxygen].first && ACol <= IsoCols[isoOxygen].second) {   // oxygen
	   Color = (TColor)RGB(255, 41, 41);
	   ColorTo = (TColor)RGB(255, 41, 41);
	   ColorMirrorTo = (TColor)RGB(255, 41, 41);
	   }
	 else if (ACol == IsoCols[isoOHratio].first) {   // O:H
	   Color = (TColor)RGB(255, 142, 123);
	   ColorTo = (TColor)RGB(255, 142, 123);
	   ColorMirrorTo = (TColor)RGB(255, 142, 123);
	   }
	 else if (ACol >= IsoCols[isoHydrogen].first && ACol <= IsoCols[isoHydrogen].second) {   // hydrogen
	   Color = (TColor)RGB(255, 242, 204);
	   ColorTo = (TColor)RGB(255, 242, 204);
	   ColorMirrorTo = (TColor)RGB(255, 242, 204);
	   }
	 else if (ACol >= IsoCols[isoSulfur].first && ACol <= IsoCols[isoSulfur].second) {   // sulfur
	   Color = (TColor)RGB(255, 217, 102);
	   ColorTo = (TColor)RGB(255, 217, 102);
	   ColorMirrorTo = (TColor)RGB(255, 217, 102);
	   }
	 else if (ACol >= IsoCols[isoStrontium].first && ACol <= IsoCols[isoStrontium].second) {   // strontium
	   Color = (TColor)RGB(0, 255, 0);
	   ColorTo = (TColor)RGB(0, 255, 0);
	   ColorMirrorTo = (TColor)RGB(0, 255, 0);
	   }
	 */
	 }
   else if (ACol >= 1 && ACol <= 5) {  // in fixed column
	 if (AdvIsotopeStringGrid->IsMergedCell(ACol,ARow)) {
	   ColorTo = (TColor)RGB(226, 239, 218);
	   ColorMirrorTo = (TColor)RGB(226, 239, 218);
	   }
	 else {
	   if (IsoFixedSelected.size() > 0) {
		 vector<TPoint>::iterator itr = find(IsoFixedSelected.begin(), IsoFixedSelected.end(), TPoint(ACol,ARow));
		 if (itr != IsoFixedSelected.end()) {
		   Color = (TColor)0x00EACAB6;
		   ColorTo = (TColor)0x00EACAB6;
		   ColorMirrorTo = (TColor)0x00EACAB6;
		   }
		 else {
		   Color = clBtnFace;
		   ColorTo = (TColor)RGB(255, 255, 255);
		   ColorMirrorTo = (TColor)RGB(240, 240, 240);
		   }
		 }
	   else {
         Color = clBtnFace;
		 ColorTo = (TColor)RGB(255, 255, 255);
		 ColorMirrorTo = (TColor)RGB(240, 240, 240);
		 }
	   }
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::AdvIsotopeStringGridGetDisplText(TObject *Sender,
		  int ACol, int ARow, UnicodeString &Value)
{
   if (ACol == 0 && ARow >= 2)
	 Value = IntToStr(ARow-1);
   //else if (ARow == 0 && ACol > 0)
   //	 Value = L"";
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::CheckIsotopeDataset(void)
{
   vector<DATASET>::iterator isoitr = Datasets.end();
   vector<DATASET>::iterator itr;
   for (itr = Datasets.begin(); itr != Datasets.end(); itr++) {
	 if (SameText((*itr).DatasetType, L"specimen stable isotope")) {
	   isoitr = itr;
	   break;
	   }
	 }
   if (!AdvIsotopeStringGrid->AllCells[3][2].IsEmpty() && isoitr == Datasets.end()) {
	 DATASET Dataset;
	 Dataset.DatasetType = L"Specimen stable isotope";
	 Datasets.push_back(Dataset);
	 FillDatasetMetaData(Datasets.size()-1);
	 }
   else if (AdvIsotopeStringGrid->AllCells[3][2].IsEmpty() && isoitr != Datasets.end()) {
	 Datasets.erase(isoitr);
     FillDatasetMetaData(0);
	 }
}
//---------------------------------------------------------------------------

// import from spreadsheet
void __fastcall TTilSpreadSheetForm::ImportAllSpecimens1Click(TObject *Sender)
{
   AdvIsotopeStringGrid->ClearRows(3, AdvIsotopeStringGrid->RowCount-4);

   int specrow = 2;

   int StartCol = AbsHeaderColCount(ProfGrid1);
   int EndCol = AbsContentColCount(ProfGrid1);
   int StartRow = AbsHeaderRowCount(ProfGrid1);
   int EndRow = AbsContentRowCount(ProfGrid1);
   for (int col=StartCol; col<=EndCol; col++) {
	 for (int row=StartRow; row<=EndRow; row++)
	   ImportIsotopeSpecimen(col, row, specrow);
	 }
   AdvIsotopeStringGrid->RowCount = specrow;
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::ImportIsotopeSpecimen(int col, int row, int& specrow)
{
   TProfGridCell* ACell = ProfGrid1->AbsoluteCells[col][row];
   if (ACell->CellObject != NULL) {
	 CELLOBJECT* CellObject = (CELLOBJECT*)ACell->CellObject;
	 if (CellObject->ObjectType == CELLSPECIMENS) {
	   TList* Specimens = (TList*)CellObject->Object;
	   for (int i=0; i<Specimens->Count; i++) {
		 SPECIMEN* Specimen = (SPECIMEN*)Specimens->Items[i];
		 AdvIsotopeStringGrid->Objects[0][specrow] = (TObject*)Specimen;
		 if (!ProfGrid1->AbsoluteCells[col][1]->Text.IsEmpty())  // sample depth
		   AdvIsotopeStringGrid->Cells[1][specrow] = ProfGrid1->AbsoluteCells[col][1]->Text;
		 if (!ProfGrid1->AbsoluteCells[col][2]->Text.IsEmpty())  // sample name
		   AdvIsotopeStringGrid->Cells[2][specrow] = ProfGrid1->AbsoluteCells[col][2]->Text;
		 AdvIsotopeStringGrid->Cells[3][specrow] = ProfGrid1->AbsoluteCells[2][row]->Text;  // taxon name
		 UnicodeString Element;
		 Element = Specimen->Element;
		 if (!Specimen->Symmetry.IsEmpty())
		   Element += (L";" + Specimen->Symmetry);
		 if (!Specimen->Portion.IsEmpty())
		   Element += (L";" + Specimen->Portion);
		 if (!Specimen->Maturity.IsEmpty())
		   Element += (L";" + Specimen->Maturity);
		 AdvIsotopeStringGrid->Cells[4][specrow] = Element;
		 AdvIsotopeStringGrid->Cells[5][specrow] = Specimen->UserSpecimenID;
		 specrow++;
		 }
	   }
	 }
   CheckIsotopeDataset();
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::InsertSingleSpecimen1Click(TObject *Sender)
{
   SelectSpecimensForm = new TSelectSpecimensForm(isoINSERT, this);
   SelectSpecimensForm->ShowModal();
   CheckIsotopeDataset();
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::AppendSingleSpecimen1Click(TObject *Sender)
{
   SelectSpecimensForm = new TSelectSpecimensForm(isoAPPEND, this);
   SelectSpecimensForm->ShowModal();
   CheckIsotopeDataset();
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::SetIsotopeHeaders(void)
{
  if (HTMLCheckBox1->Checked)    // carbon
	ShowIsotopeHeader(isoCarbon, AdvPanel1);
  if (HTMLCheckBox2->Checked)    // nitrogen
	ShowIsotopeHeader(isoNitrogen, AdvPanel2);
  if (HTMLCheckBox3->Checked)    // oxygen
	ShowIsotopeHeader(isoOxygen, AdvPanel3);
  if (HTMLCheckBox5->Checked)    // hydrogen
	ShowIsotopeHeader(isoHydrogen, AdvPanel4);
  if (HTMLCheckBox4->Checked)    // sulfur
	ShowIsotopeHeader(isoSulfur, AdvPanel5);
  if (HTMLCheckBox6->Checked)    // strontium
	ShowIsotopeHeader(isoStrontium, AdvPanel6);
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::ShowIsotopeHeader(short isotope, TAdvPanel* AdvPanel)
{
   TRect CellRect;
   int left = 0;
   int width = 0;

   for (int col = IsoCols[isotope].first; col <= IsoCols[isotope].second; col++) {
	 int DisplColIdx = AdvIsotopeStringGrid->DisplColIndex(col);
	 CellRect = AdvIsotopeStringGrid->CellRect(DisplColIdx,0);
	 if (left == 0 && CellRect.Left > 0)
	   left = CellRect.Left;
	 if (left > 0) {
	   if (CellRect.Left > 0) {
		 TPoint CellSize = AdvIsotopeStringGrid->CellSize(DisplColIdx,0);
		 width += CellSize.X;
		 }
	   else
		 break;
		}
	 }
   if (width > 0) {
	 AdvPanel->Left = left;
	 AdvPanel->Top = CellRect.Top;
	 if (AdvPanel->Left + width > AdvIsotopeStringGrid->Width)
	   width = AdvIsotopeStringGrid->Width - AdvPanel->Left;
	 AdvPanel->Width = width;
	 AdvPanel->Visible = true;
	 }
   else
	 AdvPanel->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::AdvIsotopeStringGridResize(TObject *Sender)
{
   SetIsotopeHeaders();
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::AdvIsotopeStringGridColumnSizing(TObject *Sender,
          int ACol, int ColumnSize)
{
   SetIsotopeHeaders();
}
//---------------------------------------------------------------------------

// carbon
void __fastcall TTilSpreadSheetForm::HTMLCheckBox1Click(TObject *Sender)
{
   if (HTMLCheckBox1->Checked) {
	 AdvIsotopeStringGrid->UnHideColumns(IsoCols[isoCarbon].first, IsoCols[isoCarbon].second);
	 if (!HTMLCheckBox2->Checked)
	   AdvIsotopeStringGrid->UnHideColumn(IsoCols[isoCNratio].first);
	 ToolButton17->Enabled = true;
	 }
   else {
	 AdvIsotopeStringGrid->HideColumns(IsoCols[isoCarbon].first, IsoCols[isoCarbon].second);
	 if (!HTMLCheckBox2->Checked)
	   AdvIsotopeStringGrid->HideColumn(IsoCols[isoCNratio].first);
	 ToolButton17->Enabled = false;
	 AdvPanel1->Visible = false;
	 }
   SetIsotopeHeaders();
}
//---------------------------------------------------------------------------

// nitrogen
void __fastcall TTilSpreadSheetForm::HTMLCheckBox2Click(TObject *Sender)
{
   if (HTMLCheckBox2->Checked) {
	  AdvIsotopeStringGrid->UnHideColumns(IsoCols[isoNitrogen].first, IsoCols[isoNitrogen].second);
	  if (!HTMLCheckBox1->Checked)
		AdvIsotopeStringGrid->UnHideColumn(IsoCols[isoCNratio].first);
	  ToolButton19->Enabled = true;
	 }
   else {
	 AdvIsotopeStringGrid->HideColumns(IsoCols[isoNitrogen].first, IsoCols[isoNitrogen].second);
	 if (!HTMLCheckBox1->Checked)
	   AdvIsotopeStringGrid->HideColumn(IsoCols[isoCNratio].first);
	 ToolButton19->Enabled = false;
	 AdvPanel2->Visible = false;
	 }
   SetIsotopeHeaders();
}
//---------------------------------------------------------------------------

// oxygen
void __fastcall TTilSpreadSheetForm::HTMLCheckBox3Click(TObject *Sender)
{
   if (HTMLCheckBox3->Checked) {
	 AdvIsotopeStringGrid->UnHideColumns(IsoCols[isoOxygen].first, IsoCols[isoOxygen].second);
	 if (!HTMLCheckBox5->Checked)
	   AdvIsotopeStringGrid->UnHideColumn(IsoCols[isoOHratio].first);
	 ToolButton21->Enabled = true;
	 }
   else {
	 AdvIsotopeStringGrid->HideColumns(IsoCols[isoOxygen].first, IsoCols[isoOxygen].second);
	 if (!HTMLCheckBox5->Checked)
	   AdvIsotopeStringGrid->HideColumn(IsoCols[isoOHratio].first);
	 ToolButton21->Enabled = false;
	 }
   AdvPanel3->Visible = false;
}
//---------------------------------------------------------------------------

// Hydrogen
void __fastcall TTilSpreadSheetForm::HTMLCheckBox5Click(TObject *Sender)
{
   if (HTMLCheckBox5->Checked) {
	 AdvIsotopeStringGrid->UnHideColumns(IsoCols[isoHydrogen].first, IsoCols[isoHydrogen].second);
	 if (!HTMLCheckBox3->Checked)
	   AdvIsotopeStringGrid->UnHideColumn(IsoCols[isoOHratio].first);
	 ToolButton25->Enabled = true;
	 }
   else {
	 AdvIsotopeStringGrid->HideColumns(IsoCols[isoHydrogen].first, IsoCols[isoHydrogen].second);
	 if (!HTMLCheckBox3->Checked)
	   AdvIsotopeStringGrid->HideColumn(IsoCols[isoOHratio].first);
	 ToolButton25->Enabled = false;
	 }
   AdvPanel4->Visible = false;
}
//---------------------------------------------------------------------------

// Sulfur
void __fastcall TTilSpreadSheetForm::HTMLCheckBox4Click(TObject *Sender)
{
   if (HTMLCheckBox4->Checked) {
	 AdvIsotopeStringGrid->UnHideColumns(IsoCols[isoSulfur].first, IsoCols[isoSulfur].second);
	 ToolButton23->Enabled = true;
	 }
   else {
	 AdvIsotopeStringGrid->HideColumns(IsoCols[isoSulfur].first, IsoCols[isoSulfur].second);
	 ToolButton23->Enabled = false;
	 }
   AdvPanel5->Visible = false;
}
//---------------------------------------------------------------------------

// Strontium
void __fastcall TTilSpreadSheetForm::HTMLCheckBox6Click(TObject *Sender)
{
   if (HTMLCheckBox6->Checked) {
	 AdvIsotopeStringGrid->UnHideColumns(IsoCols[isoStrontium].first, IsoCols[isoStrontium].second);
	 ToolButton27->Enabled = true;
	 }
   else {
	 AdvIsotopeStringGrid->HideColumns(IsoCols[isoStrontium].first, IsoCols[isoStrontium].second);
	 ToolButton27->Enabled = false;
	 }
   AdvPanel6->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::AdvIsotopeStringGridTopLeftChanged(TObject *Sender)
{
   SetIsotopeHeaders();
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::AdvIsotopeStringGridGetEditorType(TObject *Sender,
		  int ACol, int ARow, TEditorType &AEditor)
{
   if (SameText(AdvIsotopeStringGrid->Cells[ACol][1], L"Type"))
	 AEditor = edComboList;
   else if (SameText(AdvIsotopeStringGrid->Cells[ACol][1], L"Material Analyzed"))
	 AEditor = edComboList;
   else if (SameText(AdvIsotopeStringGrid->Cells[ACol][1], L"Substrate"))
	 AEditor = edComboList;
   else if (SameText(AdvIsotopeStringGrid->Cells[ACol][1], L"Pretreatment")) {
	 AEditor = edCustom;
	 AdvIsotopeStringGrid->EditLink = FormControlEditLinkPretreat;
	 }
   else if (SameText(AdvIsotopeStringGrid->Cells[ACol][1], L"Band Sampled"))
	 AEditor = edComboList;
   else if (SameText(AdvIsotopeStringGrid->Cells[ACol][1], L"Analyst"))
	 AEditor = edComboList;
   else if (SameText(AdvIsotopeStringGrid->Cells[ACol][1], L"Scale"))
	 AEditor = edComboList;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::AdvIsotopeStringGridGetEditorProp(TObject *Sender,
		  int ACol, int ARow, TEditLink *AEditLink)
{
   if (SameText(AdvIsotopeStringGrid->Cells[ACol][1], L"Type")) {
	 AdvIsotopeStringGrid->Combobox->Clear();
	 AdvIsotopeStringGrid->Combobox->Items->Add(L"bulk");
	 AdvIsotopeStringGrid->Combobox->Items->Add(L"serial");
	 }
   else if (SameText(AdvIsotopeStringGrid->Cells[ACol][1], L"Material Analyzed")) {
	 AdvIsotopeStringGrid->Combobox->Clear();
	 set<UnicodeString>::iterator itr;
	 set<UnicodeString>::iterator begin = IsoMaterialsAnalyzed.begin();
	 set<UnicodeString>::iterator end = IsoMaterialsAnalyzed.end();
	 AdvIsotopeStringGrid->Combobox->Items->Add(L"");
	 for (itr = begin; itr != end; itr++)
	   AdvIsotopeStringGrid->Combobox->Items->Add(*itr);
	 }
   else if (SameText(AdvIsotopeStringGrid->Cells[ACol][1], L"Substrate")) {
	 AdvIsotopeStringGrid->Combobox->Clear();
	 UnicodeString MatAnal = AdvIsotopeStringGrid->Cells[ACol-1][ARow];
	 if (!MatAnal.IsEmpty()) {
	   multimap<UnicodeString,UnicodeString>::iterator itr;
	   pair<multimap<UnicodeString,UnicodeString>::iterator, multimap<UnicodeString,UnicodeString>::iterator> range;
	   range = IsoSubstrates.equal_range(MatAnal);
	   if (range.first != IsoSubstrates.end()) {
		 AdvIsotopeStringGrid->Combobox->Items->Add(L"");
		 for (itr=range.first; itr!=range.second; itr++)
		   AdvIsotopeStringGrid->Combobox->Items->Add(itr->second);
		 }
	   }
	 }
   else if (SameText(AdvIsotopeStringGrid->Cells[ACol][1], L"Band Sampled")) {
	 AdvIsotopeStringGrid->Combobox->Clear();
	 TPoint BaseCell = AdvIsotopeStringGrid->BaseCell(6,ARow);
	 ISOTOPESERIES* Series = (ISOTOPESERIES*)AdvIsotopeStringGrid->Objects[BaseCell.X][BaseCell.Y];
	 if (!Series->SampledBiolMarker.IsEmpty()) {
	   multimap<UnicodeString,UnicodeString>::iterator itr;
	   pair<multimap<UnicodeString,UnicodeString>::iterator, multimap<UnicodeString,UnicodeString>::iterator> range;
	   range = IsoBioMarkers.equal_range(Series->SampledBiolMarker);
	   if (range.first != IsoBioMarkers.end()) {
		 AdvIsotopeStringGrid->Combobox->Items->Add(L"");
		 for (itr=range.first; itr!=range.second; itr++)
		   AdvIsotopeStringGrid->Combobox->Items->Add(itr->second);
		 }
	   }
	 else {
	   MessageDlg("Sampled Biologaical Marker not set in Series Metadata.",
	     mtInformation, TMsgDlgButtons() << mbOK, 0);
	   }
	 }
   else if (SameText(AdvIsotopeStringGrid->Cells[ACol][1], L"Analyst")) {
	 AdvIsotopeStringGrid->Combobox->Clear();
     AdvIsotopeStringGrid->Combobox->Items->Add(L"");
	 for (int i=0; i<ContactList->Count; i++) {
	   CONTACT* Contact = ContactList->Contacts[i];
	   AdvIsotopeStringGrid->Combobox->Items->AddObject(Contact->ShortContactName, (TObject*)Contact);
	   }
	 }
   else if (SameText(AdvIsotopeStringGrid->Cells[ACol][1], L"Scale")) {
	 AdvIsotopeStringGrid->Combobox->Clear();
	 //UnicodeString Element = AdvIsotopeStringGrid->Cells[ACol][0];
	 //ShowMessage(Element);
	 UnicodeString Isotope;
	 short isotope = GetIsotopeColumn(ACol);
	 switch (isotope) {
	   case isoCarbon:
		 Isotope = L"δ13C";
		 break;
	   case isoNitrogen:
		 Isotope = L"δ15N";
		 break;
	   case isoOxygen:
		 Isotope = L"δ18O";
		 break;
	   case isoHydrogen:
		 Isotope = L"δD";
		 break;
	   case isoSulfur:
		 Isotope = L"δ34S";
		 break;
	   }

	 multimap<UnicodeString,UnicodeString>::iterator itr;
	 pair<multimap<UnicodeString,UnicodeString>::iterator, multimap<UnicodeString,UnicodeString>::iterator> range;
	 range = IsoTypeVariables.equal_range(Isotope);
	 if (range.first != IsoTypeVariables.end()) {
	   AdvIsotopeStringGrid->Combobox->Items->Add(L"");
	   for (itr=range.first; itr!=range.second; itr++)
		 AdvIsotopeStringGrid->Combobox->Items->Add(itr->second);
	   }
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::AdvIsotopeStringGridComboChange(TObject *Sender,
		  int ACol, int ARow, int AItemIndex, UnicodeString ASelection)
{
   if (SameText(AdvIsotopeStringGrid->Cells[ACol][1], L"Type")) {
	 UnicodeString CurrentType = AdvIsotopeStringGrid->Cells[ACol][ARow];
	 if (SameText(ASelection, L"serial") && !SameText(CurrentType, L"serial")) {
	   TPoint FormPos;
	   GetAdvGridFormLoc(AdvIsotopeStringGrid, 255, 288, FormPos);
	   IsotopeSeriesForm = new TIsotopeSeriesForm(FormPos, this);
	   if (IsotopeSeriesForm->ShowModal() == mrOk) {
		 int n = IsotopeSeriesForm->Series.NumberOfSamples;
		 AdvIsotopeStringGrid->InsertRows(ARow, n-1, false);
		 int last = ARow + n - 1;
		 for (int row = ARow; row < last; row++) {
		   for (int col = 1; col <= 5; col++)
			 AdvIsotopeStringGrid->AllCells[col][row] = AdvIsotopeStringGrid->AllCells[col][last];
		   }
		 AdvIsotopeStringGrid->AllObjects[0][ARow] = AdvIsotopeStringGrid->AllObjects[0][last];
		 AdvIsotopeStringGrid->AllObjects[0][last] = NULL;

		 if (AdvIsotopeStringGrid->IsHiddenColumn(7)) {   // serial columns currently hidden
		   AdvIsotopeStringGrid->UnHideColumns(7,10);
		   AdvIsotopeStringGrid->MergeCells(6,0,5,1);     // merge fixed sample column header
		   SetIsotopeHeaders();
		   }

		 // store IsotopeSeries object in order to delete when program closes
		 ISOTOPESERIES *IsoSer = new ISOTOPESERIES(IsotopeSeriesForm->Series);
		 AdvIsotopeStringGrid->Objects[6][ARow] = (TObject*)IsoSer;
		 IsotopeSeries.push_back(IsoSer);

		 // merge series cells in fixed columns and Type column
		 for (int col = 1; col <= 6; col++)
		   AdvIsotopeStringGrid->MergeCells(col,ARow,1,n);

		 // assign GUID to series members
         TGUID Guid;
		 CreateGUID(Guid);
		 UnicodeString GUID = Sysutils::GUIDToString(Guid);
		 for (int row = ARow; row <= last; row++)
		   AdvIsotopeStringGrid->Cells[7][row] = GUID;

		 // assign units in Distance header
		 AdvIsotopeStringGrid->Cells[8][1] = L"Distance (" + IsoSer->SampleDistUnits + L")";
		 }
	   delete IsotopeSeriesForm;
	   }
	 else if (SameText(ASelection, L"bulk") && SameText(CurrentType, L"serial")) {
	   UnicodeString msg = L"Changing «serial» to «bulk» will delete all serial samples. Proceed?";
	   if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes) {
		 AdvIsotopeStringGrid->HideCellEdit();
		 ISOTOPESERIES* Series = (ISOTOPESERIES*)AdvIsotopeStringGrid->Objects[ACol][ARow];
		 for (int col = 1; col <= 6; col++)
		   AdvIsotopeStringGrid->SplitCells(col,ARow);
		 for (int col = 7; col <= 10; col++)
		   AdvIsotopeStringGrid->Cells[col][ARow] = L"";
		 AdvIsotopeStringGrid->RemoveRows(ARow+1, Series->NumberOfSamples-1);
		 // remove series object from vector
		 vector<ISOTOPESERIES*>::iterator itr;
		 for (itr = IsotopeSeries.begin(); itr != IsotopeSeries.end(); itr++) {
		   if (*itr == Series) {
			 IsotopeSeries.erase(itr);
			 delete Series;
			 break;
			 }
		   }
		 // if no other series, hide series metadata columns 7-10
		 if (IsotopeSeries.size() == 0)
		   AdvIsotopeStringGrid->HideColumns(7,10);
		 AdvIsotopeStringGrid->Cells[6][ARow] = L"bulk";
		 }
	   }
	 }
   else if (SameText(AdvIsotopeStringGrid->Cells[ACol][1], L"Analyst")) {
	 if (ASelection.IsEmpty())
	   AdvIsotopeStringGrid->Objects[ACol][ARow] = NULL;
	 else
	   AdvIsotopeStringGrid->Objects[ACol][ARow] = (TObject*)AdvIsotopeStringGrid->Combobox->Items->Objects[AItemIndex];
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::AdvIsotopeStringGridClipboardAfterPasteCell(TObject *Sender,
		  int ACol, int ARow, UnicodeString Value)
{
   // if pasted value is an analyst, add contact object
   int RCol = AdvIsotopeStringGrid->RealColIndex(ACol);
   if (SameText(AdvIsotopeStringGrid->AllCells[RCol][1], L"Analyst")) {
	 for (int i=0; i<ContactList->Count; i++) {
	   CONTACT* Contact = ContactList->Contacts[i];
	   if (SameText(Value,Contact->ShortContactName)) {
		 AdvIsotopeStringGrid->Objects[RCol][ARow] = (TObject*)Contact;
		 break;
		 }
	   }
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::AdvIsotopeStringGridCanEditCell(TObject *Sender,
		  int ARow, int ACol, bool &CanEdit)
{
   UnicodeString ColHeader = AdvIsotopeStringGrid->Cells[ACol][1];
   int TypeCol = AdvIsotopeStringGrid->DisplColIndex(6);
   bool IsSerial = AdvIsotopeStringGrid->IsMergedCell(TypeCol,ARow);
   int RealCol = AdvIsotopeStringGrid->RealColIndex(ACol);

   if (SameText(ColHeader, L"Serial ID"))
	 CanEdit = false;
   else if (!IsSerial && (RealCol >= 7 && RealCol <= 10))
	 CanEdit = false;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::AdvIsotopeStringGridCellValidate(TObject *Sender,
		  int ACol, int ARow, UnicodeString &Value, bool &Valid)
{
   if (SameText(AdvIsotopeStringGrid->Cells[ACol][1], L"Band Sampled")) {
	 if (!Value.IsEmpty() && AdvIsotopeStringGrid->Combobox->Items->IndexOf(Value) == -1)
	   Valid = false;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::AdvIsotopeStringGridCellChanging(TObject *Sender,
		  int OldRow, int OldCol, int NewRow, int NewCol, bool &Allow)
{
   if (SameText(AdvIsotopeStringGrid->Cells[NewCol][1], L"Type") && AdvIsotopeStringGrid->IsMergedCell(NewCol,NewRow))
	 AdvIsotopeStringGrid->PopupMenu = PopupMenuIsotope;
   else
	 AdvIsotopeStringGrid->PopupMenu = NULL;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::SeriesMetadata1Click(TObject *Sender)
{
   TPoint BaseCell = AdvIsotopeStringGrid->BaseCell(AdvIsotopeStringGrid->Col, AdvIsotopeStringGrid->Row);
   ISOTOPESERIES* Series = (ISOTOPESERIES*)AdvIsotopeStringGrid->Objects[BaseCell.X][BaseCell.Y];
   TPoint FormPos;
   GetAdvGridFormLoc(AdvIsotopeStringGrid, 255, 288, FormPos);
   IsotopeSeriesForm = new TIsotopeSeriesForm(FormPos, Series, this);
   if (IsotopeSeriesForm->ShowModal() == mrOk) {
	 int n = IsotopeSeriesForm->Series.NumberOfSamples;
	 int first = BaseCell.Y;
	 int last = first + n - 1;
	 if (n != Series->NumberOfSamples) {
	   if (n > Series->NumberOfSamples) {
		 AdvIsotopeStringGrid->InsertRows(first+Series->NumberOfSamples, n-Series->NumberOfSamples);

		 for (int row = first+Series->NumberOfSamples; row <= last; row++) {
		   for (int col = 1; col <= 5; col++)
			 AdvIsotopeStringGrid->AllCells[col][row] = AdvIsotopeStringGrid->AllCells[col][last];
		   }

		 // merge series cells in fixed columns and Type column
		 for (int col = 1; col <= 6; col++)
		   AdvIsotopeStringGrid->MergeCells(col,first,1,n);

		 // assign new GUIDs
		 for (int row = first+Series->NumberOfSamples; row <= last; row++) {
		   TGUID Guid;
		   CreateGUID(Guid);
		   AdvIsotopeStringGrid->Cells[7][row] = Sysutils::GUIDToString(Guid);
		   }
		 }
	   else {  // new n < Series->NumberOfSamples
		 for (int col = 1; col <= 6; col++)
		   AdvIsotopeStringGrid->SplitCells(col,first);
		 AdvIsotopeStringGrid->RemoveRows(first+n, Series->NumberOfSamples-n);
		 for (int col = 1; col <= 6; col++)
		   AdvIsotopeStringGrid->MergeCells(col,first,1,n);
		 }
	   }

	 // check sampled band consistency
	 if (!SameText(IsotopeSeriesForm->Series.SampledBiolMarker, Series->SampledBiolMarker)) {
	   int end = (Series->NumberOfSamples <= IsotopeSeriesForm->Series.NumberOfSamples) ?
				 first+Series->NumberOfSamples : first+IsotopeSeriesForm->Series.NumberOfSamples;
	   bool band_exists = false;
	   for (int row = first; row < end; row++) {
		 if (!AdvIsotopeStringGrid->Cells[10][row].IsEmpty()) {
		   AdvIsotopeStringGrid->Cells[10][row] = L"";
		   band_exists = true;
		   }
		 }
	   if (band_exists) {
		 UnicodeString msg = L"Sampled biological marker changed. Existing sampled bands deleted.";
		 MessageDlg(msg, mtWarning, TMsgDlgButtons() << mbOK, 0);
		 }
	   }

	 Series->Update(IsotopeSeriesForm->Series);
	 }
   delete IsotopeSeriesForm;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::AdvIsotopeStringGridFixedCellClick(TObject *Sender,
		  int ACol, int ARow)
{
   if (ACol == 0 && ARow >= 3) {
	 if (!IsoMultiRowsSelected) {
	   int row1 = -1;
	   int row2;
	   if (IsoGridShiftClickSelection) {
		 TGridRect rect = AdvIsotopeStringGrid->Selection;
		 if (rect.Left == 1 && rect.Right == AdvIsotopeStringGrid->ColCount-1)
		   row1 = rect.Top;
		   row2 = rect.Bottom;
		 }

	   if (IsoFixedSelected.size() > 0) {
		 for (unsigned int i=0; i<IsoFixedSelected.size(); i++)
		   AdvIsotopeStringGrid->Colors[IsoFixedSelected[i].X][IsoFixedSelected[i].Y] = clBtnFace;
		 IsoFixedSelected.clear();
		 }
	   IsoRowSelected = true;

	   if (row1 == -1) {
		 row1 = ARow;
		 row2 = ARow;
		 }
	   else  if (ARow > row1)
		 row2 = ARow;
	   else if (ARow <= row1)
		 row1 = ARow;

	   if (AdvIsotopeStringGrid->IsMergedCell(1,ARow)) {
		 TRect FullCell = AdvIsotopeStringGrid->FullCell(1,ARow);
		 if (row1 > FullCell.Top)
		   row1 = FullCell.Top;
		 if (row2 < FullCell.Bottom)
		   row2 = FullCell.Bottom;
		 }

	   for (int col=1; col<=5; col++) {
		 for (int row = row1; row <= row2; row++)
		   IsoFixedSelected.push_back(TPoint(col,ARow));
		 }

	   IsoMultiRowsSelected = (row2 > row1);
	   AdvIsotopeStringGrid->SelectCells(1, row1, AdvIsotopeStringGrid->ColCount-1, row2);
	   AdvIsotopeStringGrid->ColorRect(1, row1 ,5, row2 ,(TColor)0x00EACAB6);
	   }
	 else {
	   IsoMultiRowsSelected = false;
	   IsoRowSelected = false;
	   }
	 }
   else if (ACol >= 1 && ACol <= 5 && ARow >= 3) {
	 if (IsoFixedSelected.size() > 0) {
	   vector<TPoint>::iterator itr = find(IsoFixedSelected.begin(), IsoFixedSelected.end(), TPoint(ACol,ARow));
	   if (itr != IsoFixedSelected.end())
		 AdvIsotopeStringGrid->Colors[itr->X][itr->Y] = (TColor)0x00EACAB6;
	   }
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::AdvIsotopeStringGridKeyUp(TObject *Sender, WORD &Key,
		  TShiftState Shift)
{
   if (Key == VK_DELETE) {
	 TGridRect rect = AdvIsotopeStringGrid->Selection;
	 int left = AdvIsotopeStringGrid->RealColIndex(Max(7,rect.Left));
	 int right = AdvIsotopeStringGrid->RealColIndex(rect.Right);
	 int top = Max(2,rect.Top);
	 for (int col = left; col <= right; col++) {
	   for (int row = top; row <= rect.Bottom; row++) {
		 AdvIsotopeStringGrid->AllCells[col][row] = L"";
		 }
	   }
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::AdvIsotopeStringGridSelectionChanged(TObject *Sender,
		  int ALeft, int ATop, int ARight, int ABottom)
{
   TGridRect rect = AdvIsotopeStringGrid->Selection;
   if (!IsoGridShiftClickSelection) {   // mouse is already up
	 if (!IsoMultiRowsSelected) {
	   if (IsoFixedSelected.size() > 0) {
		 for (unsigned int i=0; i<IsoFixedSelected.size(); i++)
		   AdvIsotopeStringGrid->Colors[IsoFixedSelected[i].X][IsoFixedSelected[i].Y] = clBtnFace;
		 IsoRowSelected = false;
		 }
	   NewIsoGridSelection.Top = ATop;
	   NewIsoGridSelection.Left = ALeft;
	   NewIsoGridSelection.Right = ARight;
	   NewIsoGridSelection.Bottom = ABottom;
	   }
	 else {
	   TGridRect Selection = AdvIsotopeStringGrid->Selection;
	   int top = Selection.Top;
	   int bottom = Selection.Bottom;
	   AdvIsotopeStringGrid->SelectCells(1,top,AdvIsotopeStringGrid->ColCount-1,bottom);
	   NewIsoGridSelection.Top = top;
	   NewIsoGridSelection.Left = 1;
	   NewIsoGridSelection.Right = AdvIsotopeStringGrid->ColCount - 1;
	   NewIsoGridSelection.Bottom = bottom;
	   }
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::AdvIsotopeStringGridMouseDown(TObject *Sender,
		  TMouseButton Button, TShiftState Shift, int X, int Y)
{
   int col, row;
   AdvIsotopeStringGrid->MouseToCell(X, Y, col, row);

   if (Shift.Contains(ssShift) && Button == mbLeft) {
	 TRect OldRect = NewIsoGridSelection;
	 if (col == 0)  // new
	   col = 1;
	 if (row >= OldRect.Top && col >= OldRect.Left) {
	   NewIsoGridSelection.Top = OldRect.Top;
	   NewIsoGridSelection.Left = OldRect.Left;
	   NewIsoGridSelection.Right = col;
	   NewIsoGridSelection.Bottom = row;
	   }
	 else if (row >= OldRect.Top && col < OldRect.Left) {
	   NewIsoGridSelection.Top = OldRect.Top;
	   NewIsoGridSelection.Left = col;
	   NewIsoGridSelection.Right = OldRect.Left;
	   NewIsoGridSelection.Bottom = row;
	   }
	 else if (row < OldRect.Top && col <= OldRect.Left) {
	   NewIsoGridSelection.Top = row;
	   NewIsoGridSelection.Left = col;
	   NewIsoGridSelection.Right = OldRect.Left;
	   NewIsoGridSelection.Bottom = OldRect.Top;
	   }
	 else {
	   NewIsoGridSelection.Top = row;
	   NewIsoGridSelection.Left = OldRect.Left;
	   NewIsoGridSelection.Right = col;
	   NewIsoGridSelection.Bottom = OldRect.Top;
	   }

	 IsoGridShiftClickSelection = true;
	 }
   else if ((Button == mbRight && col == 0) || (col > 0 && col <= 5)) {
     AdvIsotopeStringGrid->SelectCells(6, row, 6, row);
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::AdvIsotopeStringGridMouseUp(TObject *Sender,
		  TMouseButton Button, TShiftState Shift, int X, int Y)
{
   if (IsoFixedSelected.size() > 0) {
	 for (unsigned int i=0; i<IsoFixedSelected.size(); i++)
	   AdvIsotopeStringGrid->Colors[IsoFixedSelected[i].X][IsoFixedSelected[i].Y] = clBtnFace;
	 IsoRowSelected = false;
	 IsoFixedSelected.clear();
	 }
   if (IsoGridShiftClickSelection) {
	 AdvIsotopeStringGrid->SelectCells(NewIsoGridSelection.Left,NewIsoGridSelection.Top,NewIsoGridSelection.Right,NewIsoGridSelection.Bottom);
	 if (NewIsoGridSelection.Left <= 5) {
	   for (int col = NewIsoGridSelection.Left; col <= 5; col++) {
		 for (int row = NewIsoGridSelection.Top; row <= NewIsoGridSelection.Bottom; row++) {
		   AdvIsotopeStringGrid->Colors[col][row] = (TColor)0x00EACAB6;
		   IsoFixedSelected.push_back(TPoint(col,row));
		   }
		 }
	   }
	 IsoGridShiftClickSelection = false;
	 }

   TGridRect Rect = AdvIsotopeStringGrid->Selection;
}
//---------------------------------------------------------------------------

// top
void __fastcall TTilSpreadSheetForm::ToolButton10Click(TObject *Sender)
{
   AdvIsotopeStringGrid->Row = 3;
}
//---------------------------------------------------------------------------

// up
void __fastcall TTilSpreadSheetForm::ToolButton11Click(TObject *Sender)
{
   if (AdvIsotopeStringGrid->Row > 1)
	 AdvIsotopeStringGrid->Row--;
}
//---------------------------------------------------------------------------

// down
void __fastcall TTilSpreadSheetForm::ToolButton12Click(TObject *Sender)
{
   AdvIsotopeStringGrid->Row++;
}
//---------------------------------------------------------------------------

// bottom
void __fastcall TTilSpreadSheetForm::ToolButton13Click(TObject *Sender)
{
   AdvIsotopeStringGrid->Row = AdvIsotopeStringGrid->RowCount - 1;
}
//---------------------------------------------------------------------------

// insert
void __fastcall TTilSpreadSheetForm::ToolButton14Click(TObject *Sender)
{
   SelectSpecimensForm = new TSelectSpecimensForm(isoINSERT, this);
   SelectSpecimensForm->ShowModal();
   CheckIsotopeDataset();

   /*
   for (int row = 3; row < AdvIsotopeGrid->RowCount; row++) {
	 ShowMessage(L"row = " + IntToStr(row) + L": " + AdvIsotopeGrid->AllCells[6][row] +
				 L", " + AdvIsotopeGrid->Cells[6][row]);
	 if (AdvIsotopeGrid->Objects[0][row] != NULL) {
	   SPECIMEN* specimen = (SPECIMEN*)AdvIsotopeGrid->Objects[0][row];
	   ShowMessage(L"row = " + IntToStr(row) + L": " + specimen->UserSpecimenID);
	   }
	 else
	   ShowMessage(L"row = " + IntToStr(row) + L": NULL");
	 }
   */
}
//---------------------------------------------------------------------------

// delete rows
void __fastcall TTilSpreadSheetForm::ToolButton15Click(TObject *Sender)
{
   int Row1 = AdvIsotopeStringGrid->Row;
   if (Row1 > 2 || (Row1 == 2 && AdvIsotopeStringGrid->RowCount > 3))
	 AdvIsotopeStringGrid->RemoveRows(Row1,AdvIsotopeStringGrid->SelectedRowCount);
   else if (Row1 == 2 && AdvIsotopeStringGrid->RowCount == 3) {
	 AdvIsotopeStringGrid->ClearRows(2,1);
	 AdvIsotopeStringGrid->Objects[0][2] = NULL;
	 }
   else
	 Beep();
   CheckIsotopeDataset();
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::ToolButton17Click(TObject *Sender)
{
   ShowIsoMetadataForm(ToolButton17, isoCarbon);
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::ToolButton19Click(TObject *Sender)
{
   ShowIsoMetadataForm(ToolButton19, isoNitrogen);
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::ToolButton21Click(TObject *Sender)
{
   ShowIsoMetadataForm(ToolButton21, isoOxygen);
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::ToolButton25Click(TObject *Sender)
{
   ShowIsoMetadataForm(ToolButton25, isoHydrogen);
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::ToolButton23Click(TObject *Sender)
{
   ShowIsoMetadataForm(ToolButton23, isoSulfur);
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::ToolButton27Click(TObject *Sender)
{
   ShowIsoMetadataForm(ToolButton27, isoStrontium);
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::ShowIsoMetadataForm(TToolButton* ToolButton, short isotope)
{
   TPoint FormPos;
   TPoint pnt = ToolButton->ClientToScreen(TPoint(0,0));
   FormPos.X = pnt.X;
   FormPos.Y = pnt.Y + ToolBar4->Height;
   IsoDatasetMetadataForm = new TIsoDatasetMetadataForm(FormPos, isotope, this);
   IsoDatasetMetadataForm->ShowModal();
   delete IsoDatasetMetadataForm;

   if (IsoMetadata.count(isotope) == 0)
	 ToolButton->ImageIndex = 68;
   else if (IsoMetadata[isotope].IsEmpty())
	 ToolButton->ImageIndex = 68;
   else
	 ToolButton->ImageIndex = 69;
}
//---------------------------------------------------------------------------

// pretreatment dropdown

// sets the value in the editor for the pretreatment dropdown
void __fastcall TTilSpreadSheetForm::FormControlEditLinkPretreatSetEditorValue(TObject *Sender,
		  TAdvStringGrid *Grid, UnicodeString AValue)
{
   AdvControlDropDownPretreatment->Text = AValue;
}
//---------------------------------------------------------------------------

// gets value from the pretreatment dropdown editor after dropping up
void __fastcall TTilSpreadSheetForm::FormControlEditLinkPretreatGetEditorValue(TObject *Sender,
		  TAdvStringGrid *Grid, UnicodeString &AValue)
{
   AValue = AdvControlDropDownPretreatment->Text;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::AdvColumnGridPretreatGetEditorType(TObject *Sender,
		  int ACol, int ARow, TEditorType &AEditor)
{
   if (ACol == 0) {
	 AEditor = edSpinEdit;
	 AdvColumnGridPretreat->SpinEdit->MinValue = 1;
	 AdvColumnGridPretreat->SpinEdit->MaxValue = AdvColumnGridPretreat->RowCount - 1;
	 AdvColumnGridPretreat->SpinEdit->Increment = 1;
	 }
   else if (ACol == 1) {
	 AEditor = edComboList;
	 }
   else if (ACol == 2) {
	 int count = IsoPretreatments.count(AdvColumnGridPretreat->Cells[1][ARow]);
	 AEditor = (count > 1) ? edComboList : edNone;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::AdvColumnGridPretreatGetEditorProp(TObject *Sender,
		  int ACol, int ARow, TEditLink *AEditLink)
{
   if (ACol == 1) {      // pretreatment
	 AdvColumnGridPretreat->Combobox->Clear();
	 multimap<UnicodeString,UnicodeString>::iterator itr;
	 multimap<UnicodeString,UnicodeString>::iterator begin = IsoPretreatments.begin();
	 multimap<UnicodeString,UnicodeString>::iterator end = IsoPretreatments.end();
	 for (itr = begin; itr != end; itr++) {
	   if (AdvColumnGridPretreat->Combobox->Items->IndexOf(itr->first) == -1)
		 AdvColumnGridPretreat->Combobox->Items->Add(itr->first);
	   }
	 }
   else if (ACol == 2) {    // units
	 int count = IsoPretreatments.count(AdvColumnGridPretreat->Cells[1][ARow]);
	 if (count > 1) {
	   AdvColumnGridPretreat->Combobox->Clear();
	   multimap<UnicodeString,UnicodeString>::iterator itr;
	   pair<multimap<UnicodeString,UnicodeString>::iterator, multimap<UnicodeString,UnicodeString>::iterator> range;
	   range = IsoPretreatments.equal_range(AdvColumnGridPretreat->Cells[1][ARow]);
	   for (itr=range.first; itr!=range.second; itr++)
		 AdvColumnGridPretreat->Combobox->Items->Add(itr->second);
	   }
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::AdvColumnGridPretreatComboChange(TObject *Sender,
		  int ACol, int ARow, int AItemIndex, UnicodeString ASelection)
{
   // add qualifier
   if (ACol == 1) {
	 int count = IsoPretreatments.count(ASelection);
	 if (count > 1) {
	   AdvColumnGridPretreat->Cells[2][ARow] = L"";
	   AdvColumnGridPretreat->Colors[2][ARow] = clWindow;
	   AdvColumnGridPretreat->FontColors[2][ARow] = clWindowText;
	   AdvColumnGridPretreat->Colors[3][ARow] = clWindow;
	   }
	 else {
	   multimap<UnicodeString,UnicodeString>::iterator itr = IsoPretreatments.find(ASelection);
	   AdvColumnGridPretreat->Cells[2][ARow] = itr->second;
	   AdvColumnGridPretreat->Colors[2][ARow] = clBtnFace;
	   AdvColumnGridPretreat->FontColors[2][ARow] = clNavy;
	   AdvColumnGridPretreat->Colors[3][ARow] = (itr->second.IsEmpty()) ? clBtnFace : clWindow;
	   }
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::AdvColumnGridPretreatGetCellColor(TObject *Sender,
		  int ARow, int ACol, TGridDrawState AState, TBrush *ABrush, TFont *AFont)
{
   if (ACol == 3)
	 ABrush->Color = (AdvColumnGridPretreat->Cells[2][ARow].IsEmpty()) ? clBtnFace : clWindow;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::AdvColumnGridPretreatCanEditCell(TObject *Sender,
		  int ARow, int ACol, bool &CanEdit)
{
   if (ACol == 3)
	 CanEdit = !AdvColumnGridPretreat->Cells[2][ARow].IsEmpty();
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::AdvControlDropDownPretreatmentBeforeDropDown(TObject *Sender)
{
   AdvColumnGridPretreat->ClearNormalCells();

   vector<UnicodeString> Treatments;
   UnicodeString Text = AdvIsotopeStringGrid->AllCells[AdvIsotopeStringGrid->RealCol][AdvIsotopeStringGrid->RealRow];

   ParsePartsIC(Text, L";", Treatments);

   for (unsigned int i=0, row=1; i<Treatments.size(); i++, row++) {
	 vector<UnicodeString> Elements;
	 ParsePartsIC(Treatments[i], L",", Elements);
	 AdvColumnGridPretreat->Cells[0][row] = Elements[0];
	 AdvColumnGridPretreat->Cells[1][row] = Elements[1].SubString(2,Elements[1].Length()-2);
	 if (Elements[2].Length() > 2)
	   AdvColumnGridPretreat->Cells[2][row] = Elements[2].SubString(2,Elements[2].Length()-2);

	 if (Elements.size() == 4)
	   AdvColumnGridPretreat->Cells[3][row] = Elements[3];
	 AdvColumnGridPretreat->Colors[3][row] = (AdvColumnGridPretreat->Cells[2][row].IsEmpty()) ? clBtnFace : clWindow;
	 }

   AdvColumnGridPretreat->Row = 1;
   AdvColumnGridPretreat->Col = 0;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::AdvControlDropDownPretreatmentBeforeDropUp(TObject *Sender)
{
   UnicodeString DisplayText;
   bool error = SetIsotopePretreatments(DisplayText, false);
   if (!error) {
	 if (!SameText(DisplayText, AdvControlDropDownPretreatment->Text)) {
	   if (MessageDlg(L"Save changes to pretreatments?", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes)
		 AdvControlDropDownPretreatment->Text = DisplayText;
	   }
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::AdvControlDropDownPretreatmentDropDownFooterButtonClick(TObject *Sender,
		  int ButtonIndex)
{
   UnicodeString DisplayText;

   if (ButtonIndex == 0) {    // Ok button
	 if (SetIsotopePretreatments(DisplayText, true)) {
	   AdvControlDropDownPretreatment->Text = DisplayText;
	   AdvControlDropDownPretreatment->HideDropDown();
	   }
	 }
   else if (ButtonIndex == 2) {  // clear button
	 int ARow = AdvColumnGridPretreat->Row;
	 if (AdvColumnGridPretreat->RowCount > 2) {
	   int RowCount = AdvColumnGridPretreat->RowCount;
	   AdvColumnGridPretreat->RemoveRows(ARow,1);
	   AdvColumnGridPretreat->RowCount = RowCount;
	   }
	 else if (AdvColumnGridPretreat->RowCount == 2 && ARow == 1) {
	   AdvColumnGridPretreat->ClearRows(ARow,1);
	   }
	 }
}
//---------------------------------------------------------------------------

bool TTilSpreadSheetForm::SetIsotopePretreatments(UnicodeString& DisplayText, bool ShowError)
{
   UnicodeString Text;
   Text = L"";
   int iVal;
   double dVal;
   bool error = false;
   UnicodeString ErrorMsg;

   DisplayText = L"";
   int n = 1;
   for (int row=1; row<AdvColumnGridPretreat->RowCount; row++) {
	 if (!AdvColumnGridPretreat->Cells[1][row].IsEmpty()) {
	   if (row > 1) Text += L";";
	   if (TryStrToInt(AdvColumnGridPretreat->Cells[0][row],iVal)) {
		 if (iVal == n++)
		   Text += IntToStr(iVal);
		 else {
		   if (ShowError)
			 ErrorMsg = L"Order number error.";
		   error = true;
		   break;
		   }
		 }
	   Text += (L",\"" + AdvColumnGridPretreat->Cells[1][row] + L"\"");
	   Text += (L",\"" + AdvColumnGridPretreat->Cells[2][row] + L"\"");
	   if (!AdvColumnGridPretreat->Cells[3][row].IsEmpty()) {
		 if (TryStrToFloat(AdvColumnGridPretreat->Cells[3][row],dVal))
		   Text += (L"," + FloatToStr(dVal));
		 else {
		   if (ShowError)
			 ErrorMsg = L"Error in Qualifier value.";
		   error = true;
		   break;
		   }
		 }
	   }
	 else
	   break;
	 }

   if (error) {
	 if (ShowMessage)
	   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 }
   else
	 DisplayText = Text;

   return !error;
}
//---------------------------------------------------------------------------

