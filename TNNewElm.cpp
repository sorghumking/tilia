//---------------------------------------------------------------------------

#include <vcl.h>
#include "pch.h"
#pragma hdrstop
#include "TNNewElm.h"
#ifndef TIJSONH
#include "TIJSON.h"
#endif
#ifndef TINeotomaH
#include "TINeotoma.h"
#endif

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
#pragma link "cxMemo"
#pragma link "cxRichEdit"
#pragma link "cxTextEdit"
#pragma link "ipwjson"
#pragma link "ipshttps"
#pragma link "cxButtons"
#pragma link "AdvCGrid"
#pragma link "AdvGrid"
#pragma link "AdvObj"
#pragma link "BaseGrid"
#pragma link "cxButtons"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxLabel"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxMemo"
#pragma link "cxTextEdit"
#pragma link "ipshttps"
#pragma link "ipwjson"
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
TNewElementsForm *NewElementsForm;
//---------------------------------------------------------------------------
__fastcall TNewElementsForm::TNewElementsForm(UnicodeString new_element,
	SSELEMENT* ss_element, map<UnicodeString,int>* taxa_map,
	map<int,NEOTOMAVARIABLE>* neotoma_variables,
	map<int,UnicodeString>* neotoma_dataset_types, TComponent* Owner)
	: TForm(Owner)
{
   NewElement = new_element;
   OldElement = new_element;
   sselement = ss_element;
   TaxaMap = taxa_map;
   NeotomaVariables = neotoma_variables;
   NeotomaDatasetTypes = neotoma_dataset_types;
   activated = false;
   rat_button = false;
   startsel = -1;
   lensel = -1;
   cxRichEdit1->Text = NewElement;
   AdvColumnGrid1->RowCount = TaxaMap->size() + 1;
   ButtonGlyph = new Graphics::TBitmap;
   cxImageList1->GetBitmap(0, ButtonGlyph);
   AdvColumnGrid1->ControlLook->NoDisabledButtonLook = true;
   map<UnicodeString,int>::iterator itr;
   int row = 1;
   for (itr = TaxaMap->begin(); itr != TaxaMap->end(); itr++)
	 AdvColumnGrid1->Cells[0][row++] = itr->first;
   FormatCaption(L"element");
}
//---------------------------------------------------------------------------

void __fastcall TNewElementsForm::FormActivate(TObject *Sender)
{
   if (!activated) {
	 UnicodeString TaxonName = AdvColumnGrid1->Cells[0][1];
	 int TaxonID = (*TaxaMap)[TaxonName];
	 //ShowMessage(L"TaxonID = " + IntToStr(TaxonID));
	 GetElements(TaxonID);
	 activated = true;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TNewElementsForm::FormDestroy(TObject *Sender)
{
   delete ButtonGlyph;
}
//---------------------------------------------------------------------------

void __fastcall TNewElementsForm::AdvColumnGrid1RowChanging(TObject *Sender, int OldRow,
		  int NewRow, bool &Allow)
{
   if (!rat_button) {
	 UnicodeString TaxonName = AdvColumnGrid1->Cells[0][NewRow];
	 int TaxonID = (*TaxaMap)[TaxonName];
	 GetElements(TaxonID);
	 }
}
//---------------------------------------------------------------------------

bool TNewElementsForm::GetElements(int TaxonID)
{
   int rv = true;
   AdvColumnGrid2->ClearNormalCells();
   Screen->Cursor = crHourGlass;
   NeotomaGetElementByTaxonID Elements(ipsJSONS1, TcpClient1);
   Elements.AddParam(L"TAXONID", TaxonID);
   StatusBar1->Caption = Elements.WebServiceName();
   if (Elements.Execute()) {
	 AdvColumnGrid2->RemoveAllButtons();
	 if (Elements.Size() > 0) {
	   AdvColumnGrid2->RowCount = Elements.Size() + 1;
	   for (unsigned int i=0; i<Elements.Size(); i++) {
		 int row = i+1;
		 AdvColumnGrid2->Cells[1][row] = Elements.Items[i].ElementType;
		 AdvColumnGrid2->Cells[2][row] = Elements.Items[i].Symmetry;
		 AdvColumnGrid2->Cells[3][row] = Elements.Items[i].Portion;
		 AdvColumnGrid2->Cells[4][row] = Elements.Items[i].Maturity;
		 }
	   for (int i=0, row=1; i<AdvColumnGrid2->RowCount; i++, row++)
		 AdvColumnGrid2->AddBitButton(0, row, 18, 18, L"", ButtonGlyph, haFull, vaFull);
	   }
	 else
	   AdvColumnGrid2->RowCount = 2;
	 }
   else
	 rv = false;
   StatusBar1->Caption = L"";
   Screen->Cursor = crDefault;
   return rv;
}
//---------------------------------------------------------------------------

void TNewElementsForm::FormatCaption(UnicodeString ItemType)
{
   UnicodeString msg = L"The taxa combined with this "  + ItemType +
	   L" are listed below on the left. Existing " + ItemType +
	   L"s for the highlighted taxon are listed on the right. To replace the spreadsheet " +
	   ItemType + L" with an existing " + ItemType +
	   L", click the green check button. Otherwise, if the new " + ItemType +
	   L" is valid, click the Parse button.";
   cxMemo1->Text = msg;
}
//---------------------------------------------------------------------------

void __fastcall TNewElementsForm::AdvColumnGrid2ButtonClick(TObject *Sender, int ACol,
		  int ARow)
{
   UnicodeString msg, ErrorMsg, line;
   vector<int> newids;
   vector<UnicodeString> TaxaGroupIDs;
   bool success = true;

   if (rat_button) {
	 Screen->Cursor = crHourGlass;
	 UnicodeString Element = cxRichEdit1->Text;
	 for (int col=1; col<=4; col++) {
	   UnicodeString Part = AdvColumnGrid2->Cells[col][1].Trim();
	   int start = GetSelection(Element, Part);
	   if (start > -1)
		 Element.Delete(start+1,Part.Length());
	   }
	 int pos = Element.Pos(L";");
	 while (pos > 0) {
	   Element.Delete(pos,1);
	   pos = Element.Pos(L";");
	   }
	 Element = Element.Trim();
	 if (!Element.IsEmpty()) {
	   Screen->Cursor = crDefault;
	   MessageDlg(L"Element is not completely parsed!", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return;
	   }

	 // upload parts
	 UnicodeString ElementType = AdvColumnGrid2->Cells[1][1].Trim();
	 UnicodeString Symmetry = AdvColumnGrid2->Cells[2][1].Trim();
	 UnicodeString Portion = AdvColumnGrid2->Cells[3][1].Trim();
	 UnicodeString Maturity = AdvColumnGrid2->Cells[4][1].Trim();
	 bool new_element_type = false;
	 bool new_symmetry = false;
	 bool new_portion = false;
	 bool new_maturity = false;

	 if (!ElementType.IsEmpty()) {
	   NeotomaElementTypeByName NeotomaElementType(ipsJSONS1, TcpClient1);
	   NeotomaElementType.AddParam(L"ELEMENTTYPE", ElementType);
	   StatusBar1->Caption = NeotomaElementType.WebServiceName();
	   if (NeotomaElementType.Execute()) {
		 if (NeotomaElementType.Size() == 0)
		   new_element_type = true;
		 else
		   sselement->ElementTypeID = NeotomaElementType.Items.begin()->first;
		 }
	   else {
		 Screen->Cursor = crDefault;
		 return;
		 }
	   }
	 else {
	   Screen->Cursor = crDefault;
	   MessageDlg(L"Element Type cannot be blank!", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return;
	   }

	 if (!Symmetry.IsEmpty()) {
	   NeotomaElementSymmetryByName NeotomaSymmetry(ipsJSONS1, TcpClient1);
	   NeotomaSymmetry.AddParam(L"SYMMETRY", Symmetry);
	   StatusBar1->Caption = NeotomaSymmetry.WebServiceName();
	   if (NeotomaSymmetry.Execute()) {
		 if (NeotomaSymmetry.Size() == 0)
		   new_symmetry = true;
		 else
		   sselement->SymmetryID = NeotomaSymmetry.Items.begin()->first;
		 }
	   else {
		 Screen->Cursor = crDefault;
		 return;
		 }
	   }

	 if (!Portion.IsEmpty()) {
	   NeotomaElementPortionByName NeotomaPortion(ipsJSONS1, TcpClient1);
	   NeotomaPortion.AddParam(L"PORTION", Portion);
	   StatusBar1->Caption = NeotomaPortion.WebServiceName();
	   if (NeotomaPortion.Execute()) {
		 if (NeotomaPortion.Size() == 0)
		   new_portion = true;
		 else
		   sselement->PortionID = NeotomaPortion.Items.begin()->first;
		 }
	   else {
		 Screen->Cursor = crDefault;
		 return;
		 }
	   }

	 if (!Maturity.IsEmpty()) {
	   NeotomaElementMaturityByName NeotomaMaturity(ipsJSONS1, TcpClient1);
	   NeotomaMaturity.AddParam(L"MATURITY", Maturity);
	   StatusBar1->Caption = NeotomaMaturity.WebServiceName();
	   if (NeotomaMaturity.Execute()) {
		 if (NeotomaMaturity.Size() == 0)
		   new_maturity = true;
		 else
		   sselement->MaturityID = NeotomaMaturity.Items.begin()->first;
		 }
	   else {
		 Screen->Cursor = crDefault;
		 return;
		 }
	   }

	 // upload new element components
	 if (new_element_type || new_symmetry || new_portion || new_maturity) {
	   msg = L"Upload these new Element components to Neotoma?\n";
	   if (new_element_type)
		 msg += (L"\n   Element Type: " + ElementType);
	   if (new_symmetry)
		 msg += (L"\n   Symmetry: " + Symmetry);
	   if (new_portion)
		 msg += (L"\n   Portion: " + Portion);
	   if (new_maturity)
		 msg += (L"\n   Maturity: " + Maturity);

	   if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes) {
		 if (new_element_type) {   // upload new element type
		   InsertData InsertElement(L"InsertElementType", 1, ipsHTTPS1, ipsJSONS1, TcpClient1);
		   InsertElement.Add(L"ELEMENTTYPE", ElementType);
		   StatusBar1->Caption = L"InsertElementType";
		   InsertElement.PostData();
		   if (InsertElement.Post(newids, ErrorMsg)) {
			 if (newids.size() == 1) {
			   sselement->ElementTypeID = newids[0];
			   line = L"Element Type uploaded: " + ElementType + L", ID = " + IntToStr(newids[0]);
			   OutputLines.push_back(line);
			   }
			 else {
			   msg = L"Error inserting into ElementTypes table!";
			   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			   success = false;
			   }
			 }
		   else {
			 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			 success = false;
			 }
		   if (!success) {
			 Screen->Cursor = crDefault;
			 return;
			 }

		   // insert new ElementTypes into ElementTaxaGroups table
		   GetTaxaGroupIDs(TaxaGroupIDs);
		   newids.clear();
		   InsertData InsertElemTaxaGroups(L"InsertElementTaxaGroups", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
		   StatusBar1->Caption = L"InsertElementTaxaGroups";
		   for (unsigned int i=0; i<TaxaGroupIDs.size(); i++) {
			 InsertElemTaxaGroups.Add(L"TAXAGROUPID", TaxaGroupIDs[i]);
			 InsertElemTaxaGroups.Add(L"ELEMENTTYPEID", sselement->ElementTypeID, -1);
			 }
		   InsertElemTaxaGroups.PostData();
		   if (InsertElemTaxaGroups.Post(newids, ErrorMsg)) {
			 if (newids.size() == TaxaGroupIDs.size()) {
			   for (unsigned int i=0; i<TaxaGroupIDs.size(); i++) {
				 line = L"Element «" + ElementType + L"» assigned to TaxaGroup «" +
						TaxaGroupIDs[i] + L"», ID = " + IntToStr(newids[i]);
				 OutputLines.push_back(line);
				 }
			   }
			 else {
			   msg = L"Error inserting into ElementTaxaGroups table!";
			   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			   success = false;
			   }
			 }
		   else {
			 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			 success = false;
			 }
		   if (!success) {
			 Screen->Cursor = crDefault;
			 return;
			 }

		   // insert new ElementTypes into ElementDatasetTaxaGroups table
		   // first get all combinations of TaxaGroupID and DatasetTypeID
		   vector<TAXAGROUPDATASETTYPE> dttgids;
           map<UnicodeString,int>::iterator itr;
		   for (itr = TaxaMap->begin(); itr != TaxaMap->end(); itr++) {
			 int TaxonID = itr->second;
			 map<int,NEOTOMAVARIABLE>::iterator vitr;
			 for (vitr = NeotomaVariables->begin(); vitr != NeotomaVariables->end(); vitr++) {
			   if (TaxonID == vitr->second.TaxonID) {
				 TAXAGROUPDATASETTYPE dttgid(vitr->second.DatasetTypeID, vitr->second.TaxaGroupID);
				 if (find(dttgids.begin(), dttgids.end(), dttgid) == dttgids.end())
				   dttgids.push_back(dttgid);
				 break;
				 }
			   }
			 }

		   // deal with surface samples
		   map<UnicodeString,int> DatasetTypeIdx;
		   map<UnicodeString,int>::iterator xitr;
		   map<int,UnicodeString>::iterator ditr;
		   for (ditr = NeotomaDatasetTypes->begin(); ditr != NeotomaDatasetTypes->end(); ditr++)
			 DatasetTypeIdx[ditr->second] = ditr->first;
		   int pos;
		   unsigned int size = dttgids.size();
		   for (unsigned int i=0; i<size; i++) {
			 UnicodeString DatasetType = (*NeotomaDatasetTypes)[dttgids[i].DatasetTypeID];
			 if ((pos = DatasetType.Pos(L"surface sample")) > 0)    // surface sample DatasetType
			   DatasetType = DatasetType.SubString(1,pos-1).TrimRight();  // root DatasetType
			 else   // DatasetType not surface sample
			   DatasetType += L" surface sample";
			 if ((xitr = DatasetTypeIdx.find(DatasetType)) != DatasetTypeIdx.end()) {  // find DatasetTypeID
			   TAXAGROUPDATASETTYPE dttgid(xitr->second, dttgids[i].TaxaGroupID);
			   if (find(dttgids.begin(), dttgids.end(), dttgid) == dttgids.end()) // DatasetType not in list
				 dttgids.push_back(dttgid);
				}
			 }

		   newids.clear();
		   InsertData InsertElemDatasetTaxaGroups(L"InsertElementDatasetTaxaGroups", 3, ipsHTTPS1, ipsJSONS1, TcpClient1);
		   StatusBar1->Caption = L"InsertElementDatasetTaxaGroups";
		   for (unsigned int i=0; i<dttgids.size(); i++) {
			 InsertElemDatasetTaxaGroups.Add(L"DATASETTYPEID", dttgids[i].DatasetTypeID, -1);
			 InsertElemDatasetTaxaGroups.Add(L"TAXAGROUPID", dttgids[i].TaxaGroupID);
			 InsertElemDatasetTaxaGroups.Add(L"ELEMENTTYPEID", sselement->ElementTypeID, -1);
			 }
		   InsertElemDatasetTaxaGroups.PostData();
		   if (InsertElemDatasetTaxaGroups.Post(ErrorMsg)) {
			 for (unsigned int i=0; i<dttgids.size(); i++) {
			   line = L"Element «" + ElementType + L"» and TaxaGroup «" +
					  dttgids[i].TaxaGroupID + L"» assigned to DatasetType «" +
					  (*NeotomaDatasetTypes)[dttgids[i].DatasetTypeID] + L"»";
			   OutputLines.push_back(line);
			   }
			 }
		   else {
			 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			 success = false;
			 }
           if (!success) {
			 Screen->Cursor = crDefault;
			 return;
			 }
		   }

		 if (new_symmetry)
		   newids.clear();

		 if (new_portion) {
		   newids.clear();
		   InsertData InsertPortion(L"InsertElementPortion", 1, ipsHTTPS1, ipsJSONS1, TcpClient1);
		   InsertPortion.Add(L"PORTION", Portion);
		   StatusBar1->Caption = L"InsertElementPortion";
		   InsertPortion.PostData();
		   if (InsertPortion.Post(newids, ErrorMsg)) {
			 if (newids.size() == 1) {
			   sselement->PortionID = newids[0];
			   line = L"Element portion uploaded: " + Portion + L", ID = " + IntToStr(newids[0]);
			   OutputLines.push_back(line);
			   }
			 else {
			   msg = L"Error inserting into ElementPortions table!";
			   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			   success = false;
			   }
			 }
		   else {
			 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			 success = false;
			 }
		   if (!success) {
			 Screen->Cursor = crDefault;
			 return;
			 }

		   // upload new portions to ElementTaxaGroupPortions table
		   // sselement->ElementTypeID
		   // sselement->PortionID

		   // first get vector of TaxaGroupIDs
		   GetTaxaGroupIDs(TaxaGroupIDs);


		   InsertData InsertElementTaxaGroupPortion(L"InsertElementTaxaGroupPortion", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
		   multimap<UnicodeString,int> ElementTaxaGroupIDs;
		   for (unsigned int i=0; i<TaxaGroupIDs.size(); i++) {
			 NeotomaElementTaxaGroupID ElementTaxaGroupID(ipsJSONS1, TcpClient1);
			 StatusBar1->Caption = ElementTaxaGroupID.WebServiceName();
			 ElementTaxaGroupID.AddParam(L"TAXAGROUPID", TaxaGroupIDs[i]);
			 ElementTaxaGroupID.AddParam(L"ELEMENTTYPEID", sselement->ElementTypeID);
			 if (ElementTaxaGroupID.Execute()) {
			   if (ElementTaxaGroupID.Size() == 1) {
				 InsertElementTaxaGroupPortion.Add(L"ELEMENTTAXAGROUPID", ElementTaxaGroupID.Items[0], -1);
				 InsertElementTaxaGroupPortion.Add(L"PORTIONID", sselement->PortionID, -1);
				 ElementTaxaGroupIDs.insert(pair<UnicodeString,int>(TaxaGroupIDs[i], ElementTaxaGroupID.Items[0]));
				 }
			   else {
				 msg = L"ERROR: Expected pair TaxaGroupID = " + TaxaGroupIDs[i] +
					   L", ElementTypeID = " + IntToStr(sselement->ElementTypeID) +
					   L" not found in ElementTaxaGroups table.";
				 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
				 success = false;
				 }
			   }
			 else {
			   success = false;
			   break;
			   }
			 }
		   if (!success) {
			 Screen->Cursor = crDefault;
			 return;
			 }
		   StatusBar1->Caption = L"InsertElementTaxaGroupPortion";
		   InsertElementTaxaGroupPortion.PostData();
		   if (InsertElementTaxaGroupPortion.Post(ErrorMsg)) {
			 multimap<UnicodeString,int>::iterator it;   // TaxaGroupID, ElementTaxaGroupID
			 // ElementTaxaGroupID = 5 (MAM; bone), PortionID = 1 (distal) inserted into ElementTaxaGroups table
			 for (it = ElementTaxaGroupIDs.begin(); it != ElementTaxaGroupIDs.end(); it++) {
			   line = L"ElementTaxaGroupID = " + IntToStr(it->second) + L" (" +
					  it->first + L"; " + ElementType + L"), PortionID = " +
					  IntToStr(sselement->PortionID) + L" (" + Portion +
					  L") inserted into ElementTaxaGroups table";
			   OutputLines.push_back(line);
			   }
			 }
		   else {
			 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			 Screen->Cursor = crDefault;
			 return;
			 }
		   }

		 // -------------------------------------

		 msg = L"Success: New variable element components uploaded to Neotoma!\n";
		 if (new_element_type)
		   msg += (L"\n   Element Type: " + ElementType + L", ID = " + IntToStr(sselement->ElementTypeID));
		 if (new_symmetry)
		   msg += (L"\n   Symmetry: " + Symmetry + L", ID = " + IntToStr(sselement->SymmetryID));
		 if (new_portion)
		   msg += (L"\n   Portion: " + Portion + L", ID = " + IntToStr(sselement->PortionID));
		 if (new_maturity)
		   msg += (L"\n   Maturity: " + Maturity + L", ID = " + IntToStr(sselement->MaturityID));
		 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);

		 NewElement = ElementType;
		 if (!Symmetry.IsEmpty())
		   NewElement += (L"; " + Symmetry);
		 if (!Portion.IsEmpty())
		   NewElement += (L"; " + Portion);
		 if (!Maturity.IsEmpty())
		   NewElement += (L"; " + Maturity);
		 ModalResult = mrOk;
		 }
	   }
	 else {  // already in Neotoma
	   NewElement = ElementType;
	   if (!Symmetry.IsEmpty())
		 NewElement += (L"; " + Symmetry);
	   if (!Portion.IsEmpty())
		 NewElement += (L"; " + Portion);
	   if (!Maturity.IsEmpty())
		 NewElement += (L"; " + Maturity);
	   msg = L"Variable element «" + NewElement + "» is already in Neotoma";
	   MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
	   ModalResult = mrOk;
	   }
	 }
   else {
	 NewElement = AdvColumnGrid2->Cells[1][ARow];
	 if (!AdvColumnGrid2->Cells[2][ARow].IsEmpty())
	   NewElement += (L"; " + AdvColumnGrid2->Cells[2][ARow]);
	 if (!AdvColumnGrid2->Cells[3][ARow].IsEmpty())
	   NewElement += (L"; " + AdvColumnGrid2->Cells[3][ARow]);
	 if (!AdvColumnGrid2->Cells[4][ARow].IsEmpty())
	   NewElement += (L"; " + AdvColumnGrid2->Cells[4][ARow]);
	 UnicodeString line = L"Variable element «" + OldElement + L"» changed to «" + NewElement + L"»";
	 OutputLines.push_back(line);
	 ModalResult = mrOk;
	 }
   Screen->Cursor = crDefault;
}
//---------------------------------------------------------------------------

void TNewElementsForm::GetTaxaGroupIDs(vector<UnicodeString>& TaxaGroupIDs)
{
   if (TaxaGroupIDs.size() > 0) return;
   map<UnicodeString,int>::iterator itr;
   for (itr = TaxaMap->begin(); itr != TaxaMap->end(); itr++) {
	 int TaxonID = itr->second;
	 map<int,NEOTOMAVARIABLE>::iterator vitr;
	 for (vitr = NeotomaVariables->begin(); vitr != NeotomaVariables->end(); vitr++) {
	   if (TaxonID == vitr->second.TaxonID) {
		 if (find(TaxaGroupIDs.begin(), TaxaGroupIDs.end(), vitr->second.TaxaGroupID) == TaxaGroupIDs.end())
		   TaxaGroupIDs.push_back(vitr->second.TaxaGroupID);
		 break;
		 }
	   }
	 }
}
//---------------------------------------------------------------------------

// parse button
void __fastcall TNewElementsForm::cxButton1Click(TObject *Sender)
{
   Screen->Cursor = crHourGlass;
   AdvColumnGrid2->RowCount = 2;
   AdvColumnGrid2->ClearNormalCells();
   AdvColumnGrid2->RemoveAllButtons();
   delete ButtonGlyph;
   ButtonGlyph = new Graphics::TBitmap;
   cxImageList1->GetBitmap(1, ButtonGlyph);
   rat_button = true;
   AdvColumnGrid2->AddBitButton(0, 1, 18, 18, L"", ButtonGlyph, haFull, vaFull);
   AdvColumnGrid2->Columns->Items[1]->ReadOnly = false;
   AdvColumnGrid2->Columns->Items[2]->ReadOnly = false;
   AdvColumnGrid2->Columns->Items[3]->ReadOnly = false;
   AdvColumnGrid2->Columns->Items[4]->ReadOnly = false;
   AdvColumnGrid2->Options = AdvColumnGrid2->Options >> goRowSelect;
   AdvColumnGrid2->SelectionColor = clWindow;
   AdvColumnGrid2->Hovering = false;

   // try to find ElementType
   bool PartsFound = false;
   UnicodeString element = NewElement;
   NeotomaElementTypeFromVariableElement ElementType(ipsJSONS1, TcpClient1);
   ElementType.AddParam(L"VARIABLEELEMENT", element);
   StatusBar1->Caption = ElementType.WebServiceName();
   if (ElementType.Execute()) {
	 if (ElementType.Size() == 1) {  // ElementType found
	   sselement->ElementTypeID = ElementType.Items.begin()->first;;
	   UnicodeString element_type = ElementType.Items.begin()->second;
	   AdvColumnGrid2->Cells[1][1] = element_type;
	   PartsFound = true;
	   int pos = element.Pos(element_type);
	   // 'femur, left, distal' --> ' left, distal'
	   // 'left, femur, distal' --> 'left , distal'
	   // 'left, femur'         --> 'left '
	   int len = element_type.Length();
	   if (element.Length() > len && element[len+1] == L',')
		 len++;
	   element.Delete(pos,len);
	   element = element.Trim();
	   }
	 }

   // parse what we can
   vector<UnicodeString> parts;
   UnicodeString Separator = (element.Pos(L";") > 0) ? L";" : L",";
   int pos = element.Pos(Separator);
   while (pos > 0) {
	 UnicodeString part = element.SubString(1,pos-1).Trim();
	 parts.push_back(part);
	 element.Delete(1,pos);
	 pos = element.Pos(Separator);
	 }
   parts.push_back(element);

   for (unsigned int i=0; i<parts.size(); i++) {
	 NeotomaGetElementPartID ElementPart(ipsJSONS1, TcpClient1);
	 ElementPart.AddParam(L"PARTNAME", parts[i]);
	 StatusBar1->Caption = ElementPart.WebServiceName();
	 if (ElementPart.Execute()) {
	   if (ElementPart.Size() == 1) {
		 if (ElementPart.Items[0].SymmetryID > -1) {
		   sselement->SymmetryID = ElementPart.Items[0].SymmetryID;
		   AdvColumnGrid2->Cells[2][1] = parts[i];
		   PartsFound = true;
		   }
		 else if (ElementPart.Items[0].PortionID > -1) {
		   sselement->PortionID = ElementPart.Items[0].PortionID;
		   AdvColumnGrid2->Cells[3][1] = parts[i];
		   PartsFound = true;
		   }
		 else if (ElementPart.Items[0].MaturityID > -1) {
		   sselement->MaturityID = ElementPart.Items[0].MaturityID;
		   AdvColumnGrid2->Cells[4][1] = parts[i];
		   PartsFound = true;
		   }
		 }
	   }
	 else
	   return;
	 }

   for (int col=1; col<=4; col++) {
	 UnicodeString Part = AdvColumnGrid2->Cells[col][1].Trim();
	 startsel = GetSelection(cxRichEdit1->Text, Part);
	 if (startsel > -1) {
	   lensel = Part.Length();
	   HighlightText(startsel, lensel);
	   }
	 }

   UnicodeString msg;
   if (PartsFound) {
	 msg = L"The variable element has been parsed into parts insofar as possible. ";
	 msg += L"Manually complete the element division and click the ";
	 msg += L"Neotoma button to upload the new element.";
	 }
   else {
	 msg = L"No recognizable parts were found in the element. ";
	 msg += L"Divide the element into its appropriate parts and click the ";
     msg += L"Neotoma button to upload the new element.";
	 }

   cxMemo1->Text = msg;
   Screen->Cursor = crDefault;
}
//---------------------------------------------------------------------------

void __fastcall TNewElementsForm::AdvColumnGrid2GridHint(TObject *Sender, int ARow,
          int ACol, UnicodeString &hintstr)
{
   if (ACol == 0) {
	 if (rat_button)
	   hintstr = L"Upload element to Neotoma";
	 else
	   hintstr = L"Replace spreadsheet element with this one";
	 }
   else
	 hintstr = L"";
}
//---------------------------------------------------------------------------

void TNewElementsForm::HighlightText(int start, int len)
{
   cxRichEdit1->SelStart = start;
   cxRichEdit1->SelLength = len;
   TTextAttributes* tattrib = cxRichEdit1->SelAttributes;
   tattrib->Style = tattrib->Style << fsBold;
   tattrib->Color = clRed;
}
//---------------------------------------------------------------------------

void __fastcall TNewElementsForm::AdvColumnGrid2EditCellDone(TObject *Sender, int ACol,
          int ARow)
{
   if (!rat_button) return;
   AdvColumnGrid2->Cells[ACol][ARow] = AdvColumnGrid2->Cells[ACol][ARow].LowerCase();
   cxRichEdit1->SelStart = 0;
   cxRichEdit1->SelLength = cxRichEdit1->Text.Length();
   TTextAttributes* tattrib = cxRichEdit1->SelAttributes;
   tattrib->Style = tattrib->Style >> fsBold;
   tattrib->Color = clWindowText;
   for (int col=1; col<=4; col++) {
	 UnicodeString Part = AdvColumnGrid2->Cells[col][1].Trim();
	 startsel = GetSelection(cxRichEdit1->Text, Part);
	 if (startsel > -1) {
	   lensel = Part.Length();
	   HighlightText(startsel, lensel);
	   }
	 }
}
//---------------------------------------------------------------------------

int TNewElementsForm::GetSelection(UnicodeString Element, UnicodeString Part)
{
   int start = -1;
   if (!rat_button) return start;
   if (SameText(Part, Element))
	 start = 0;
   else {
	 UnicodeString Part1 = Part + L";";
	 int pos = Element.Pos(Part1);
	 if (pos > 0)
	   start = pos-1;
	 else {
	   pos = Element.Length()-Part.Length()+1;
	   if (SameText(Part, Element.SubString(pos, Part.Length())))
		 start = pos-1;
	   }
	 }
   return start;
}
//---------------------------------------------------------------------------

void __fastcall TNewElementsForm::ipsJSONS1SSLServerAuthentication(TObject *Sender,
          TipsJSONSSSLServerAuthenticationEventParams *e)
{
   e->Accept = true;
}
//---------------------------------------------------------------------------

