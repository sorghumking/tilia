//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TNAnlUnt.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvCGrid"
#pragma link "AdvGrid"
#pragma link "AdvObj"
#pragma link "AdvUtil"
#pragma link "BaseGrid"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxGroupBox"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxRadioGroup"
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
#pragma resource "*.dfm"
TAnalUnitMatchForm *AnalUnitMatchForm;
//---------------------------------------------------------------------------

void StorePos::MoveTo(void)
{
   if (ARow >= AdvColumnGrid1->RowCount)
	 ARow = AdvColumnGrid1->RowCount - 1;
   if (ACol >= 0 && ACol <= 2)
	 AdvColumnGrid1->SelectCells(0,ARow,2,ARow);
   else if (ACol >= 4 && ACol <= 7)
	 AdvColumnGrid1->SelectCells(4,ARow,7,ARow);
   else
	 AdvColumnGrid1->SelectCells(3,ARow,3,ARow);
}
//---------------------------------------------------------------------------

__fastcall TAnalUnitMatchForm::TAnalUnitMatchForm(vector<NEOTOMAANALUNIT>* tilAnalUnits,
	vector<NTMANALYSISUNIT>* ntmAnalUnits, int EPDSiteID, TComponent* Owner) : TForm(Owner)
{
   TilAnalUnits = tilAnalUnits;
   NtmAnalUnits = ntmAnalUnits;
   if (EPDSiteID > -1)
	 CheckBox1->Visible = true;
   activated = false;
   FReplaceEPDDataset = false;
}
//---------------------------------------------------------------------------

void __fastcall TAnalUnitMatchForm::FormCreate(TObject *Sender)
{
   UnicodeString msg;

   Screen->Cursor = crHourGlass;
   AdvColumnGrid2->Cells[0][0] = L"Tilia Analysis Units";
   AdvColumnGrid2->Cells[2][0] = L"Neotoma Analysis Units";
   int namewidth = (AdvColumnGrid1->Width - AdvColumnGrid1->ScrollWidth - 397)/2;
   AdvColumnGrid1->Columns->Items[2]->Width = namewidth;
   AdvColumnGrid1->Columns->Items[6]->Width = namewidth;
   float GridWidth = AdvColumnGrid1->Width - AdvColumnGrid1->ScrollWidth;
   ColWidthProps.push_back((float)AdvColumnGrid1->Columns->Items[0]->Width/GridWidth);
   ColWidthProps.push_back((float)AdvColumnGrid1->Columns->Items[1]->Width/GridWidth);
   ColWidthProps.push_back((float)AdvColumnGrid1->Columns->Items[2]->Width/GridWidth);
   ColWidthProps.push_back((float)AdvColumnGrid1->Columns->Items[3]->Width/GridWidth);
   ColWidthProps.push_back((float)AdvColumnGrid1->Columns->Items[4]->Width/GridWidth);
   ColWidthProps.push_back((float)AdvColumnGrid1->Columns->Items[5]->Width/GridWidth);
   ColWidthProps.push_back((float)AdvColumnGrid1->Columns->Items[6]->Width/GridWidth);
   ColWidthProps.push_back((float)AdvColumnGrid1->Columns->Items[7]->Width/GridWidth);

   TiliaBmp = new Graphics::TBitmap;
   cxImageList1->GetBitmap(3,TiliaBmp);
   AdvColumnGrid2->AddBitmap(0,0,TiliaBmp,true,haBeforeText,TCellVAlign::vaCenter);
   RatBmp = new Graphics::TBitmap;
   cxImageList1->GetBitmap(2,RatBmp);
   AdvColumnGrid2->AddBitmap(2,0,RatBmp,true,haBeforeText,TCellVAlign::vaCenter);


   // AdvColumnGrid1->ColumnSize->SynchWithGrid = true;

   // depth, thickness, name : all three exist in both
   // depth, thickness       : depth & thickness in both
   // depth, name            : depth & name in both
   // depth                  : depth in both
   // name                   : name in both
   // no matches             : last resort

   AnalUnitMatch til;
   AnalUnitMatch ntm;

   for (unsigned int i=0; i<TilAnalUnits->size(); i++) {
	 if (!(*TilAnalUnits)[i].Depth.IsEmpty()) {
	   til.depth = true;
	   double depth = (*TilAnalUnits)[i].Depth;
	   tildepthidx.insert(pair<double,unsigned int>(depth,i));
	   depths.insert(depth);
	   }
	 if (!(*TilAnalUnits)[i].Thickness.IsEmpty()) {
	   til.thick = true;
	   }
	 if (!(*TilAnalUnits)[i].AnalysisUnitName.IsEmpty()) {
	   til.name = true;
	   UnicodeString lcname = (*TilAnalUnits)[i].AnalysisUnitName.LowerCase();
	   tilnameidx[lcname] = i;
	   names.insert(lcname);
	   tilnames[lcname] = (*TilAnalUnits)[i].AnalysisUnitName;
	   }
	 }

   for (unsigned int i=0; i<NtmAnalUnits->size(); i++) {
	 if (!(*NtmAnalUnits)[i].Depth.IsEmpty()) {
	   ntm.depth = true;
	   double depth = (*NtmAnalUnits)[i].Depth;
	   ntmdepthidx.insert(pair<double,unsigned int>(depth,i));
	   depths.insert(depth);
	   }
	 if (!(*NtmAnalUnits)[i].Thickness.IsEmpty()) {
	   ntm.thick = true;
	   }
	 if (!(*NtmAnalUnits)[i].AnalysisUnitName.IsEmpty()) {
	   ntm.name = true;
	   UnicodeString lcname = (*NtmAnalUnits)[i].AnalysisUnitName.LowerCase();
	   ntmnameidx[lcname] = i;
	   names.insert(lcname);
	   ntmnames[lcname] = (*NtmAnalUnits)[i].AnalysisUnitName;
	   }
	 }

   // depths, thicknesses, and names in both Tilia and Neotoma
   if (til.depth && til.thick && til.name && ntm.depth && ntm.thick && ntm.name) {
	 MatchByDepth();
	 GetRemainingAnalUnits();
	 // Analysis units initially matched by depth, Checking cxRadioButton2 completes the
	 // matching by thickness and name
	 cxRadioButton2->Checked = true;
	 }
   // depths and thicknesses in both Tilia and Neotoma
   else if (til.depth && til.thick && ntm.depth && ntm.thick) {
	 MatchByDepth();
	 GetRemainingAnalUnits();
	 cxRadioButton3->Checked = true;
	 }
   // depths and names in both Tilia and Neotoma
   else if (til.depth && til.name && ntm.depth && ntm.name) {
	 MatchByDepth();
	 GetRemainingAnalUnits();
	 cxRadioButton6->Checked = true;
	 }
   // depths in both Tilia and Neotoma
   else if (til.depth && ntm.depth) {
	 MatchByDepth();
	 GetRemainingAnalUnits();
	 cxRadioButton4->Checked = true;
	 }
   // names in both Tilia and Neotoma
   else if (til.name && ntm.name) {
	 MatchByName();
	 GetRemainingAnalUnits();
	 cxRadioButton5->Checked = true;
	 }
   else {
	 MatchByDepth();
	 GetRemainingAnalUnits();
	 NoMatches();
	 }

   for (int row = 1; row < AdvColumnGrid1->RowCount; row++) {
	 AdvColumnGrid1->AddButton(3,row,32,18,AdvColumnGrid1->Cells[3][row],TCellHAlign::haCenter,TCellVAlign::vaCenter);
	 if (TilAnalUnitIsEmpty(row) || NtmAnalUnitIsEmpty(row)) {
	   AdvColumnGrid1->Cells[3][row] = L"";
	   AdvColumnGrid1->SetButtonText(3,row,L"");
	   }
	 }
   Screen->Cursor = crDefault;
}
//---------------------------------------------------------------------------

void __fastcall TAnalUnitMatchForm::FormActivate(TObject *Sender)
{
   AdvColumnGrid1->SelectCells(0,1,2,1);
   activated = true;
}
//---------------------------------------------------------------------------

void __fastcall TAnalUnitMatchForm::FormClose(TObject *Sender, TCloseAction &Action)
{
   for (int row = 1; row < AdvColumnGrid1->RowCount; row++) {
	 if (AdvColumnGrid1->Objects[0][row] != NULL) {
	   unsigned int* idxptr = (unsigned int*)AdvColumnGrid1->Objects[0][row];
	   delete idxptr;
	   }
	 }
   if (CheckBox1->Visible)
	 FReplaceEPDDataset = CheckBox1->Checked;
   delete TiliaBmp;
   delete RatBmp;
}
//---------------------------------------------------------------------------

void TAnalUnitMatchForm::GetRemainingAnalUnits(void)
{
   int row = AdvColumnGrid1->RowCount;
   if (tilidx.size() < TilAnalUnits->size()) {
	 for (unsigned int i = 0; i < TilAnalUnits->size(); i++) {
	   if (tilidx.find(i) == tilidx.end()) {
		 unsigned int* idxptr = new unsigned int;
		 *idxptr = i;
		 AdvColumnGrid1->Objects[0][row] = (TObject*)idxptr;
		 if (!(*TilAnalUnits)[i].Thickness.IsEmpty())
		   AdvColumnGrid1->Cells[1][row] = (*TilAnalUnits)[i].Thickness;
		 AdvColumnGrid1->Cells[2][row] = (*TilAnalUnits)[i].AnalysisUnitName;
		 row++;
		 }
	   }
	 }
   if (ntmidx.size() < NtmAnalUnits->size()) {
	 for (unsigned int i = 0; i < NtmAnalUnits->size(); i++) {
	   if (ntmidx.find(i) == ntmidx.end()) {
		 if (!(*NtmAnalUnits)[i].Thickness.IsEmpty())
		   AdvColumnGrid1->Cells[5][row] = (*NtmAnalUnits)[i].Thickness;
		 AdvColumnGrid1->Cells[6][row] = (*NtmAnalUnits)[i].AnalysisUnitName;
		 AdvColumnGrid1->Cells[7][row] = (*NtmAnalUnits)[i].AnalysisUnitID;
		 row++;
		 }
	   }
	 }
   AdvColumnGrid1->RowCount = row;
}
//---------------------------------------------------------------------------

void TAnalUnitMatchForm::MatchByDepth(void)
{
   Screen->Cursor = crHourGlass;
   int row = 1;
   set<double>::iterator itr;
   // bool match_found = false;
   for (itr = depths.begin(); itr != depths.end(); itr++) {
	 bool match = false;
	 int row1 = row;
	 multimap<double,unsigned int>::iterator mitr;
	 pair<multimap<double,unsigned int>::iterator,multimap<double,unsigned int>::iterator> range;
	 if (tildepthidx.count(*itr) > 0) {
	   range = tildepthidx.equal_range(*itr);
	   for (mitr = range.first; mitr != range.second; mitr++) {
		 unsigned int idx = mitr->second;
		 tilidx.insert(idx);
		 AdvColumnGrid1->Cells[0][row] = (*TilAnalUnits)[idx].Depth;
		 unsigned int* idxptr = new unsigned int;
		 *idxptr = idx;
		 AdvColumnGrid1->Objects[0][row] = (TObject*)idxptr;
		 if (!(*TilAnalUnits)[idx].Thickness.IsEmpty())
		   AdvColumnGrid1->Cells[1][row] = (*TilAnalUnits)[idx].Thickness;
		 AdvColumnGrid1->Cells[2][row] = (*TilAnalUnits)[idx].AnalysisUnitName;  // extra line
		 match = true;
		 row++;
		 }
	   }

	 if (ntmdepthidx.count(*itr) > 0) {
	   range = ntmdepthidx.equal_range(*itr);
	   for (mitr = range.first; mitr != range.second; mitr++) {
		 int idx = mitr->second;
		 ntmidx.insert(idx);
		 AdvColumnGrid1->Cells[4][row1] = (*NtmAnalUnits)[idx].Depth;
		 if (!(*NtmAnalUnits)[idx].Thickness.IsEmpty())
		   AdvColumnGrid1->Cells[5][row1] = (*NtmAnalUnits)[idx].Thickness;
		 AdvColumnGrid1->Cells[6][row1] = (*NtmAnalUnits)[idx].AnalysisUnitName;  // extra line
		 AdvColumnGrid1->Cells[7][row1] = (*NtmAnalUnits)[idx].AnalysisUnitID;
		 if (match) {
		   AdvColumnGrid1->Cells[3][row1] = L"=";
		   AdvColumnGrid1->SetButtonText(3,row1,L"=");
		   }
		 row1++;
		 }
	   }
	 row = max(row,row1);
	 }
   AdvColumnGrid1->RowCount = row;
}
//---------------------------------------------------------------------------

void TAnalUnitMatchForm::MatchByName(void)
{
   Screen->Cursor = crHourGlass;
   int row = 1;

   // bool match_found = false;

   set<UnicodeString>::iterator name;
   map<UnicodeString,UnicodeString>::iterator tilitr;
   map<UnicodeString,UnicodeString>::iterator ntmitr;

   for (name = names.begin(); name != names.end(); name++) {
	 tilitr = tilnames.find(*name);
	 if (tilitr != tilnames.end()) {
	   AdvColumnGrid1->Cells[2][row] = tilitr->second;
	   unsigned int idx = tilnameidx[tilitr->first];
	   tilidx.insert(idx);
	   if (!(*TilAnalUnits)[idx].Depth.IsEmpty())
		 AdvColumnGrid1->Cells[0][row] = (*TilAnalUnits)[idx].Depth;
	   if (!(*TilAnalUnits)[idx].Thickness.IsEmpty())
		 AdvColumnGrid1->Cells[1][row] = (*TilAnalUnits)[idx].Thickness;
	   unsigned int* idxptr = new unsigned int;
	   *idxptr = idx;
	   AdvColumnGrid1->Objects[0][row] = (TObject*)idxptr;
	   ntmitr = ntmnames.find(*name);
	   if (ntmitr != ntmnames.end()) {
		 AdvColumnGrid1->Cells[6][row] = ntmitr->second;
		 unsigned int ndx = ntmnameidx[*name];
		 ntmidx.insert(ndx);
		 if (!(*NtmAnalUnits)[ndx].Depth.IsEmpty())
		   AdvColumnGrid1->Cells[4][row] = (*NtmAnalUnits)[ndx].Depth;
		 if (!(*NtmAnalUnits)[ndx].Thickness.IsEmpty())
		   AdvColumnGrid1->Cells[5][row] = (*NtmAnalUnits)[ndx].Thickness;
		 AdvColumnGrid1->Cells[7][row] = (*NtmAnalUnits)[ndx].AnalysisUnitID;
		 AdvColumnGrid1->Cells[3][row] = L"=";
		 AdvColumnGrid1->SetButtonText(3,row,L"=");
		 }
	   row++;
	   }
	 else {
	   ntmitr = ntmnames.find(*name);
	   if (ntmitr != ntmnames.end()) {
		 AdvColumnGrid1->Cells[6][row] = ntmitr->second;
		 unsigned int ndx = ntmnameidx[*name];
		 ntmidx.insert(ndx);
		 if (!(*NtmAnalUnits)[ndx].Depth.IsEmpty())
		   AdvColumnGrid1->Cells[4][row] = (*NtmAnalUnits)[ndx].Depth;
		 if (!(*NtmAnalUnits)[ndx].Thickness.IsEmpty())
		   AdvColumnGrid1->Cells[5][row] = (*NtmAnalUnits)[ndx].Thickness;
		 AdvColumnGrid1->Cells[7][row] = (*NtmAnalUnits)[ndx].AnalysisUnitID;
		 }
	   row++;
	   }
	 }
   AdvColumnGrid1->RowCount = row;
}
//---------------------------------------------------------------------------

void __fastcall TAnalUnitMatchForm::AdvColumnGrid1SelectionChanged(TObject *Sender,
		  int ALeft, int ATop, int ARight, int ABottom)
{
   if (ALeft >= 0 && ALeft <= 2)
	 AdvColumnGrid1->SelectCells(0,ATop,2,ATop);
   else if (ALeft >= 4 && ALeft <= 7)
	 AdvColumnGrid1->SelectCells(4,ATop,7,ATop);
}
//---------------------------------------------------------------------------

void __fastcall TAnalUnitMatchForm::AdvColumnGrid1Resize(TObject *Sender)
{
   float GridWidth = AdvColumnGrid1->Width - AdvColumnGrid1->ScrollWidth;
   AdvColumnGrid1->Columns->Items[0]->Width = (int)(ColWidthProps[0]*GridWidth);
   AdvColumnGrid1->Columns->Items[1]->Width = (int)(ColWidthProps[1]*GridWidth);
   AdvColumnGrid1->Columns->Items[2]->Width = (int)(ColWidthProps[2]*GridWidth);
   AdvColumnGrid1->Columns->Items[3]->Width = (int)(ColWidthProps[3]*GridWidth);
   AdvColumnGrid1->Columns->Items[4]->Width = (int)(ColWidthProps[4]*GridWidth);
   AdvColumnGrid1->Columns->Items[5]->Width = (int)(ColWidthProps[5]*GridWidth);
   AdvColumnGrid1->Columns->Items[6]->Width = (int)(ColWidthProps[6]*GridWidth);
   AdvColumnGrid1->Columns->Items[7]->Width = (int)(ColWidthProps[7]*GridWidth);

   AdvColumnGrid2->Columns->Items[0]->Width =
	  AdvColumnGrid1->Columns->Items[0]->Width +
	  AdvColumnGrid1->Columns->Items[1]->Width +
	  AdvColumnGrid1->Columns->Items[2]->Width;
   AdvColumnGrid2->Columns->Items[1]->Width =
	  AdvColumnGrid1->Columns->Items[3]->Width;
   AdvColumnGrid2->Columns->Items[2]->Width =
	  AdvColumnGrid1->Columns->Items[4]->Width +
	  AdvColumnGrid1->Columns->Items[5]->Width +
	  AdvColumnGrid1->Columns->Items[6]->Width +
	  AdvColumnGrid1->Columns->Items[7]->Width;
}
//---------------------------------------------------------------------------

// all new analysis units
void __fastcall TAnalUnitMatchForm::cxRadioButton1Click(TObject *Sender)
{
  NoMatches();
}
//---------------------------------------------------------------------------

void TAnalUnitMatchForm::NoMatches(void)
{
   StorePos pos(AdvColumnGrid1);
   for (int row = AdvColumnGrid1->RowCount-1; row >= 1; row--) {
	 if (AdvColumnGrid1->Cells[3][row] == L"=") {
	   AdvColumnGrid1->Cells[3][row] = L"";
	   AdvColumnGrid1->SetButtonText(3,row,L"");
	   AdvColumnGrid1->InsertRows(row,1,false);
	   AdvColumnGrid1->AddButton(3,row,32,18,AdvColumnGrid1->Cells[3][row],TCellHAlign::haCenter,TCellVAlign::vaCenter);
	   int row1 = row+1;
	   CopyTil(row,row1);
	   AdvColumnGrid1->ClearRect(0,row1,2,row1);
	   }
	 }
   pos.MoveTo();
}
//---------------------------------------------------------------------------

// match by depth, thickness, and name
void __fastcall TAnalUnitMatchForm::cxRadioButton2Click(TObject *Sender)
{
   Screen->Cursor = crHourGlass;
   StorePos pos(AdvColumnGrid1);
   int start = 1;
   int row1 = 1;
   do {
	  for (row1 = start; row1 < AdvColumnGrid1->RowCount; row1++) {
		if (TilAnalUnitIsEmpty(row1)) continue;
		bool restart = false;
		for (int row2 = 1; row2 < AdvColumnGrid1->RowCount; row2++) {
		  //if (row1 == row2) continue;
		  if (NtmAnalUnitIsEmpty(row2)) continue;
          if (row1 == row2) {
			if (AdvColumnGrid1->Cells[0][row1] != AdvColumnGrid1->Cells[4][row2] ||
				AdvColumnGrid1->Cells[1][row1] != AdvColumnGrid1->Cells[5][row2] ||
				!SameText(AdvColumnGrid1->Cells[2][row1], AdvColumnGrid1->Cells[6][row2])) {
			   AdvColumnGrid1->Cells[3][row1] = L"";
			   AdvColumnGrid1->SetButtonText(3,row1,L"");
			   AdvColumnGrid1->InsertRows(row1,1,false);
			   AdvColumnGrid1->AddButton(3,row1,32,18,AdvColumnGrid1->Cells[3][row1],TCellHAlign::haCenter,TCellVAlign::vaCenter);
			   CopyTil(row1,row1+1);
			   row1++;
			   AdvColumnGrid1->ClearRect(0,row1,2,row1);
			   start = row1+1;
			   restart = true;
			   break;
			   }
			}
		  else if (AdvColumnGrid1->Cells[0][row1] == AdvColumnGrid1->Cells[4][row2] &&
			  AdvColumnGrid1->Cells[1][row1] == AdvColumnGrid1->Cells[5][row2] &&
			  SameText(AdvColumnGrid1->Cells[2][row1],AdvColumnGrid1->Cells[6][row2])) {
			if (row1 < row2) {
			  CopyNtm(row1,row2);
			  AdvColumnGrid1->Cells[3][row1] = L"=";
			  AdvColumnGrid1->SetButtonText(3,row1,L"=");
			  AdvColumnGrid1->RemoveRows(row2,1);
			  start = row1+1;
			  }
			else {
			  CopyNtm(row2,row1);
			  AdvColumnGrid1->Cells[3][row2] = L"=";
			  AdvColumnGrid1->SetButtonText(3,row2,L"=");
			  AdvColumnGrid1->RemoveRows(row1,1);
			  start = row1;
			  }
			restart = true;
			break;
			}
		  }
		if (restart)
		  break;
		}
	 } while (row1 < AdvColumnGrid1->RowCount);
   pos.MoveTo();
   Screen->Cursor = crDefault;
}
//---------------------------------------------------------------------------

// match by depth and thickness
void __fastcall TAnalUnitMatchForm::cxRadioButton3Click(TObject *Sender)
{
   Screen->Cursor = crHourGlass;
   StorePos pos(AdvColumnGrid1);
   int start = 1;
   int row1 = 1;
   do {
	  for (row1 = start; row1 < AdvColumnGrid1->RowCount; row1++) {
		if (TilAnalUnitIsEmpty(row1)) continue;
		bool restart = false;
		for (int row2 = 1; row2 < AdvColumnGrid1->RowCount; row2++) {
		  if (NtmAnalUnitIsEmpty(row2)) continue;
		  if (row1 == row2) {
			if (AdvColumnGrid1->Cells[0][row1] != AdvColumnGrid1->Cells[4][row2] ||
				AdvColumnGrid1->Cells[1][row1] != AdvColumnGrid1->Cells[5][row2]) {
			   AdvColumnGrid1->Cells[3][row1] = L"";
			   AdvColumnGrid1->SetButtonText(3,row1,L"");
			   AdvColumnGrid1->InsertRows(row1,1,false);
			   AdvColumnGrid1->AddButton(3,row1,32,18,AdvColumnGrid1->Cells[3][row1],TCellHAlign::haCenter,TCellVAlign::vaCenter);
			   CopyTil(row1,row1+1);
			   row1++;
			   AdvColumnGrid1->ClearRect(0,row1,2,row1);
			   start = row1+1;
			   restart = true;
			   break;
			   }
			}
		  else if (AdvColumnGrid1->Cells[0][row1] == AdvColumnGrid1->Cells[4][row2] &&
			  (AdvColumnGrid1->Cells[1][row1] == AdvColumnGrid1->Cells[5][row2] ||
			  (AdvColumnGrid1->Cells[1][row1].IsEmpty() && AdvColumnGrid1->Cells[5][row2].IsEmpty()))) {
			if (row1 < row2) {
			  CopyNtm(row1,row2);
			  AdvColumnGrid1->Cells[3][row1] = L"=";
			  AdvColumnGrid1->SetButtonText(3,row1,L"=");
			  AdvColumnGrid1->RemoveRows(row2,1);
			  start = row1+1;
			  }
			else {
			  CopyNtm(row2,row1);
			  AdvColumnGrid1->Cells[3][row2] = L"=";
			  AdvColumnGrid1->SetButtonText(3,row2,L"=");
			  AdvColumnGrid1->RemoveRows(row1,1);
			  start = row1;
			  }
			restart = true;
			break;
			}
		  }
		if (restart)
		  break;
		}
	 } while (row1 < AdvColumnGrid1->RowCount);
   pos.MoveTo();
   Screen->Cursor = crDefault;
}
//---------------------------------------------------------------------------

void __fastcall TAnalUnitMatchForm::cxRadioButton6Click(TObject *Sender)
{
   Screen->Cursor = crHourGlass;
   StorePos pos(AdvColumnGrid1);
   int start = 1;
   int row1 = 1;
   do {
	  for (row1 = start; row1 < AdvColumnGrid1->RowCount; row1++) {
		if (TilAnalUnitIsEmpty(row1)) continue;
		bool restart = false;
		for (int row2 = 1; row2 < AdvColumnGrid1->RowCount; row2++) {
		  if (NtmAnalUnitIsEmpty(row2)) continue;
		  if (row1 == row2) {
			if (AdvColumnGrid1->Cells[0][row1] != AdvColumnGrid1->Cells[4][row2] ||
				AdvColumnGrid1->Cells[2][row1] != AdvColumnGrid1->Cells[6][row2]) {
			   AdvColumnGrid1->Cells[3][row1] = L"";
			   AdvColumnGrid1->SetButtonText(3,row1,L"");
			   AdvColumnGrid1->InsertRows(row1,1,false);
			   AdvColumnGrid1->AddButton(3,row1,32,18,AdvColumnGrid1->Cells[3][row1],TCellHAlign::haCenter,TCellVAlign::vaCenter);
			   CopyTil(row1,row1+1);
			   row1++;
			   AdvColumnGrid1->ClearRect(0,row1,2,row1);
			   start = row1+1;
			   restart = true;
			   break;
			   }
			}
		  else if (AdvColumnGrid1->Cells[0][row1] == AdvColumnGrid1->Cells[4][row2] &&
			  (AdvColumnGrid1->Cells[2][row1] == AdvColumnGrid1->Cells[6][row2] ||
			  (AdvColumnGrid1->Cells[2][row1].IsEmpty() && AdvColumnGrid1->Cells[6][row2].IsEmpty()))) {
			if (row1 < row2) {
			  CopyNtm(row1,row2);
			  AdvColumnGrid1->Cells[3][row1] = L"=";
			  AdvColumnGrid1->SetButtonText(3,row1,L"=");
			  AdvColumnGrid1->RemoveRows(row2,1);
			  start = row1+1;
			  }
			else {
			  CopyNtm(row2,row1);
			  AdvColumnGrid1->Cells[3][row2] = L"=";
			  AdvColumnGrid1->SetButtonText(3,row2,L"=");
			  AdvColumnGrid1->RemoveRows(row1,1);
			  start = row1;
			  }
			restart = true;
			break;
			}
		  }
		if (restart)
		  break;
		}
	 } while (row1 < AdvColumnGrid1->RowCount);
   pos.MoveTo();
   Screen->Cursor = crDefault;
}
//---------------------------------------------------------------------------

// match by depths only
void __fastcall TAnalUnitMatchForm::cxRadioButton4Click(TObject *Sender)
{
   if (!activated)
	 return;

   Screen->Cursor = crHourGlass;
   StorePos pos(AdvColumnGrid1);
   int start = 1;
   int row1 = 1;
   do {
	  for (row1 = start; row1 < AdvColumnGrid1->RowCount; row1++) {
		if (TilAnalUnitIsEmpty(row1)) continue;
		bool restart = false;
		for (int row2 = 1; row2 < AdvColumnGrid1->RowCount; row2++) {
		  if (NtmAnalUnitIsEmpty(row2)) continue;
		  if (row1 == row2) {
			if (AdvColumnGrid1->Cells[0][row1] != AdvColumnGrid1->Cells[4][row2]) {
			   AdvColumnGrid1->Cells[3][row1] = L"";
			   AdvColumnGrid1->SetButtonText(3,row1,L"");
			   AdvColumnGrid1->InsertRows(row1,1,false);
			   AdvColumnGrid1->AddButton(3,row1,32,18,AdvColumnGrid1->Cells[3][row1],TCellHAlign::haCenter,TCellVAlign::vaCenter);
			   CopyTil(row1,row1+1);
			   row1++;
			   AdvColumnGrid1->ClearRect(0,row1,2,row1);
			   start = row1+1;
			   restart = true;
			   break;
			   }
			}
		  else if (AdvColumnGrid1->Cells[0][row1] == AdvColumnGrid1->Cells[4][row2]) {
			if (row1 < row2) {
			  CopyNtm(row1,row2);
			  AdvColumnGrid1->Cells[3][row1] = L"=";
			  AdvColumnGrid1->SetButtonText(3,row1,L"=");
			  AdvColumnGrid1->RemoveRows(row2,1);
			  start = row1+1;
			  }
			else {
			  CopyNtm(row2,row1);
			  AdvColumnGrid1->Cells[3][row2] = L"=";
			  AdvColumnGrid1->SetButtonText(3,row2,L"=");
			  AdvColumnGrid1->RemoveRows(row1,1);
			  start = row1;
			  }
			restart = true;
			break;
			}
		  }
		if (restart)
		  break;
		}
	 } while (row1 < AdvColumnGrid1->RowCount);
   pos.MoveTo();
   Screen->Cursor = crDefault;
}
//---------------------------------------------------------------------------

// match by names only
void __fastcall TAnalUnitMatchForm::cxRadioButton5Click(TObject *Sender)
{
   Screen->Cursor = crHourGlass;
   StorePos pos(AdvColumnGrid1);
   int start = 1;
   int row1 = 1;
   do {
	  for (row1 = start; row1 < AdvColumnGrid1->RowCount; row1++) {
		if (TilAnalUnitIsEmpty(row1)) continue;
		bool restart = false;
		for (int row2 = 1; row2 < AdvColumnGrid1->RowCount; row2++) {
		  if (NtmAnalUnitIsEmpty(row2)) continue;
		  if (row1 == row2) {
			if (!SameText(AdvColumnGrid1->Cells[2][row1], AdvColumnGrid1->Cells[6][row2])) {
			   AdvColumnGrid1->Cells[3][row1] = L"";
			   AdvColumnGrid1->SetButtonText(3,row1,L"");
			   AdvColumnGrid1->InsertRows(row1,1,false);
			   AdvColumnGrid1->AddButton(3,row1,32,18,AdvColumnGrid1->Cells[3][row1],TCellHAlign::haCenter,TCellVAlign::vaCenter);
			   CopyTil(row1,row1+1);
			   row1++;
			   AdvColumnGrid1->ClearRect(0,row1,2,row1);
			   start = row1+1;
			   restart = true;
			   break;
			   }
			}
		  else if (SameText(AdvColumnGrid1->Cells[2][row1], AdvColumnGrid1->Cells[6][row2])) {
			if (row1 < row2) {
			  CopyNtm(row1,row2);
			  AdvColumnGrid1->Cells[3][row1] = L"=";
			  AdvColumnGrid1->SetButtonText(3,row1,L"=");
			  AdvColumnGrid1->RemoveRows(row2,1);
			  start = row1+1;
			  }
			else {
			  CopyNtm(row2,row1);
			  AdvColumnGrid1->Cells[3][row2] = L"=";
			  AdvColumnGrid1->SetButtonText(3,row2,L"=");
			  AdvColumnGrid1->RemoveRows(row1,1);
			  start = row1;
			  }
			restart = true;
			break;
			}
		  }
		if (restart)
		  break;
		}
	 } while (row1 < AdvColumnGrid1->RowCount);
   pos.MoveTo();
   Screen->Cursor = crDefault;
}
//---------------------------------------------------------------------------

bool TAnalUnitMatchForm::TilAnalUnitIsEmpty(int row)
{
   return (AdvColumnGrid1->Cells[0][row].IsEmpty() &&
		   AdvColumnGrid1->Cells[1][row].IsEmpty() &&
		   AdvColumnGrid1->Cells[2][row].IsEmpty());
}
//---------------------------------------------------------------------------

bool TAnalUnitMatchForm::NtmAnalUnitIsEmpty(int row)
{
   return (AdvColumnGrid1->Cells[4][row].IsEmpty() &&
		   AdvColumnGrid1->Cells[5][row].IsEmpty() &&
		   AdvColumnGrid1->Cells[6][row].IsEmpty());
}
//---------------------------------------------------------------------------

void TAnalUnitMatchForm::CopyTil(int to, int from)
{
   AdvColumnGrid1->Cells[0][to] = AdvColumnGrid1->Cells[0][from];
   if (AdvColumnGrid1->Objects[0][from] != NULL) {
	 AdvColumnGrid1->Objects[0][to] = AdvColumnGrid1->Objects[0][from];
	 AdvColumnGrid1->Objects[0][from] = NULL;
	 }
   AdvColumnGrid1->Cells[1][to] = AdvColumnGrid1->Cells[1][from];
   AdvColumnGrid1->Cells[2][to] = AdvColumnGrid1->Cells[2][from];
}
//---------------------------------------------------------------------------

void TAnalUnitMatchForm::CopyNtm(int to, int from)
{
   AdvColumnGrid1->Cells[4][to] = AdvColumnGrid1->Cells[4][from];
   AdvColumnGrid1->Cells[5][to] = AdvColumnGrid1->Cells[5][from];
   AdvColumnGrid1->Cells[6][to] = AdvColumnGrid1->Cells[6][from];
   AdvColumnGrid1->Cells[7][to] = AdvColumnGrid1->Cells[7][from];
}
//---------------------------------------------------------------------------

void __fastcall TAnalUnitMatchForm::AdvColumnGrid1CanClickCell(TObject *Sender, int ARow,
		  int ACol, bool &Allow)
{
   if (ACol >=0 && ACol <= 2 && TilAnalUnitIsEmpty(ARow))
	 Allow = false;
   else if (ACol >=4 && ACol <= 7 && NtmAnalUnitIsEmpty(ARow))
	 Allow = false;
}
//---------------------------------------------------------------------------

void __fastcall TAnalUnitMatchForm::AdvColumnGrid1ButtonClick(TObject *Sender, int ACol,
		  int ARow)
{
   StorePos pos(AdvColumnGrid1);
   UnicodeString Text = AdvColumnGrid1->GetButtonText(ACol,ARow);
   if (Text == L"=") {
	 AdvColumnGrid1->SetButtonText(ACol,ARow,L"");
	 AdvColumnGrid1->Cells[ACol][ARow] = L"";
	 AdvColumnGrid1->InsertRows(ARow,1,false);
	 AdvColumnGrid1->AddButton(ACol,ARow,32,18,AdvColumnGrid1->Cells[ACol][ARow],TCellHAlign::haCenter,TCellVAlign::vaCenter);
	 int row = ARow+1;
	 CopyTil(ARow,row);
	 AdvColumnGrid1->ClearRect(0,row,2,row);
	 }
   else {
	 TGridRect r = AdvColumnGrid1->Selection;
	 int TRow = r.Top;
	 if (r.Left == 0 && r.Right == 2) {
	   if (NtmAnalUnitIsEmpty(TRow)) {
		 CopyNtm(TRow,ARow);
		 AdvColumnGrid1->Cells[3][TRow] = L"=";
		 AdvColumnGrid1->SetButtonText(3,TRow,L"=");
		 AdvColumnGrid1->RemoveRows(ARow,1);
		 }
	   else
		 Beep();
	   }
	 else if (r.Left == 4 && r.Right == 7) {
	   if (NtmAnalUnitIsEmpty(ARow)) {
		 CopyNtm(ARow,TRow);
		 AdvColumnGrid1->Cells[3][ARow] = L"=";
		 AdvColumnGrid1->SetButtonText(3,ARow,L"=");
		 AdvColumnGrid1->RemoveRows(TRow,1);
		 }
	   else
		 Beep();
	   }
	 }
   pos.MoveTo();
}
//---------------------------------------------------------------------------

void __fastcall TAnalUnitMatchForm::AdvColumnGrid1CellBalloon(TObject *Sender, int ACol,
		  int ARow, UnicodeString &ATitle, UnicodeString &AText, int &AIcon)
{
  if (ACol == 3) {
	UnicodeString Text = AdvColumnGrid1->GetButtonText(ACol,ARow);
	if (Text == L"=") {
	  ATitle = L"Click to:";
	  AText = L"Unassign";
	  }
	else {
	  TGridRect r = AdvColumnGrid1->Selection;
	  if (ARow != r.Top) {
		if (!TilAnalUnitIsEmpty(ARow) && NtmAnalUnitIsEmpty(ARow) && !NtmAnalUnitIsEmpty(r.Top)) {
		  ATitle = L"Click to:";
		  AText = L"Assign selected Neotoma analysis unit";
		  }
		else if (!TilAnalUnitIsEmpty(r.Top) && NtmAnalUnitIsEmpty(r.Top) && !NtmAnalUnitIsEmpty(ARow)) {
		  ATitle = L"Click to:";
		  AText = L"Assign to selected Tilia analysis unit";
		  }
		}
	  }
	}
}
//---------------------------------------------------------------------------

// continue button
void __fastcall TAnalUnitMatchForm::cxButton2Click(TObject *Sender)
{
   int matched = 0;
   int not_matched = 0;
   for (int row = 1; row < AdvColumnGrid1->RowCount; row++) {
	 if (AdvColumnGrid1->Cells[3][row] == L"=") {
	   matched++;
	   unsigned int *idxptr = (unsigned int*)AdvColumnGrid1->Objects[0][row];
	   (*TilAnalUnits)[*idxptr].AnalysisUnitID = AdvColumnGrid1->Cells[7][row].ToInt();
	   }
	 else if (!TilAnalUnitIsEmpty(row))
	   not_matched++;
	 }
   UnicodeString msg = IntToStr(matched) + L" analysis unit";
   if (matched != 1)
	 msg += L"s in spreadsheet are matched with Neotoma analysis units. ";
   else
	 msg += L" in spreadsheet is matched with a Neotoma analysis unit. ";
   msg += (IntToStr(not_matched) + L" analysis unit");
   if (not_matched != 1)
	 msg += L"s in spreadsheet are not matched with Neotoma analysis units";
   else
	 msg += L" in spreadsheet is not matched with a Neotoma analysis unit.";
   int rv = MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbRetry << mbCancel << mbOK, 0);
   switch (rv) {
	 case mrCancel:
	   ModalResult = mrCancel;
	   break;
	 case mrOk:
	   ModalResult = mrOk;
	   break;
	 default:
	   ModalResult = mrNone;
	   break;
	 }
}
//---------------------------------------------------------------------------

