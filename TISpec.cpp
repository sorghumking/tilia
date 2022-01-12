//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TISpec.h"
#ifndef TGParentH
#include "TGParent.h"
#endif
#ifndef TIGlobalsH
#include "TIGlobals.h"
#endif
#ifndef TGUtilsH
#include "TGUtils.h"
#endif
#ifndef TNLoginH
#include "TNLogin.h"
#endif
#ifndef TINeotomaH
#include "TINeotoma.h"
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
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDropDownEdit"
#pragma link "cxEdit"
#pragma link "cxMaskEdit"
#pragma link "AdvUtil"
#pragma link "cxTextEdit"
#pragma link "dxSkinOffice2016Colorful"
#pragma link "dxSkinOffice2016Dark"
#pragma link "dxSkinVisualStudio2013Blue"
#pragma link "dxSkinVisualStudio2013Dark"
#pragma link "dxSkinVisualStudio2013Light"
#pragma link "frmctrllink"
#pragma link "AdvDropDown"
#pragma link "AdvControlDropDown"
#pragma link "AdvEdit"
#pragma link "clisted"
#pragma link "AdvCombo"
#pragma link "cxCheckBox"
#pragma link "ipshttps"
#pragma link "ipwjson"
#pragma link "ipsjsons"
#pragma resource "*.dfm"
TSpecimenForm *SpecimenForm;
TAllSpecimensForm *AllSpecimensForm;

//---------------------------------------------------------------------------
__fastcall TSpecimenForm::TSpecimenForm(TPoint pos, CELLOBJECT* cell_object,
	TComponent* Owner) : TForm(Owner)
{
   TSSForm = (TTilSpreadSheetForm*)Owner;
   Position = pos;
   CellObject = cell_object;
   repositories_init = false;
   genbank_init = false;
   activated = false;

   AdvStringGrid1->EditLink = FormControlEditLink2;
   AdvEdit1->BorderStyle = bsNone;
   AdvControlDropDown1->BorderStyle = bsNone;

   TAPHONOMYLOOKUP* TaphLookup = TSSForm->VarLookup->GetTaphonomyLookup();
   int DatasetID = TSSForm->GetCurrentDataset(TSSForm->ProfGrid1->Row);
   DatasetType = TSSForm->Datasets[DatasetID].DatasetType.LowerCase();
   set<UnicodeString> Systems;
   TaphLookup->GetSystems(DatasetType, Systems);
   if (Systems.size() > 0) {
	 set<UnicodeString>::iterator itr;
	 for (itr = Systems.begin(); itr != Systems.end(); itr++)
	   CheckListEdit1->Items->Add(*itr);
	 int idx = 0;
	 if (SameText(DatasetType,L"vertebrate fauna"))
	   idx = CheckListEdit1->Items->IndexOf(L"FAUNMAP");
	 CheckListEdit1->Checked[idx] = true;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TSpecimenForm::FormCreate(TObject *Sender)
{
   UnicodeString TaxaGroup;
   vector<UnicodeString> TaxaGroups;

   Setup();

   FillSexList();
   FillDomesticStatusList();

   // Make local copy of specimen object. All changes will be to copy. These
   // are transferred to the spreadsheet button if the Ok button is pressed.
   if (CellObject != NULL) {
	 CellObjectBackup = new CELLOBJECT(CellObject);
	 TList* Specimens = (TList*)CellObject->Object;
	 TList* BSpecimens = (TList*)CellObjectBackup->Object;
	 for (int i=0; i<Specimens->Count; i++) {
	   SPECIMEN* Specimen = (SPECIMEN*)Specimens->Items[i];
	   SPECIMEN* BSpecimen = (SPECIMEN*)BSpecimens->Items[i];
	   SpecMap[BSpecimen] = Specimen;
	   }
	 }
   else
	 CellObjectBackup = NULL;

   if (CellObject != NULL) {
	 TList* Specimens = (TList*)CellObject->Object;  // need as back up for cancels
	 for (int i=0, row=1; i<Specimens->Count; i++, row++) {
	   SPECIMEN *Specimen = (SPECIMEN*)Specimens->Items[i];
	   AdvColumnGrid1->Objects[rc.SpecID][row] = (TObject*)Specimen;
	   if (i == 0) TaxaGroup = Specimen->TaxaGroup;
	   EnterSpecimen(Specimen, row);
	   }
	 }

   // populate the TaxaGroup selections
   if (TSSForm->VarLookup->ElementOpen()) {
	 TSSForm->ModifierType = MODELEMENT;
	 UnicodeString DatasetType = TSSForm->Datasets[TSSForm->DatasetNum].DatasetType.LowerCase();
	 TSSForm->ElementLookup->GetTaxaGroups(DatasetType, TaxaGroups);
	 for (unsigned int i=0; i<TaxaGroups.size(); i++)
	   cxComboBox1->Properties->Items->Add(TaxaGroups[i]);
	 if (TaxaGroups.size() > 0) {
	   if (!TaxaGroup.IsEmpty())
		 cxComboBox1->ItemIndex = cxComboBox1->Properties->Items->IndexOf(TaxaGroup);
	   else {
		 UnicodeString EcolGroupCode = TSSForm->ProfGrid1->AbsoluteCells[7][TSSForm->ProfGrid1->Row]->Text;
		 if (!EcolGroupCode.IsEmpty()) {
		   TaxaGroup = GetTaxaGroup(EcolGroupCode);
		   TaxaGroup = TaxaGroup.LowerCase();
		   int idx = cxComboBox1->Properties->Items->IndexOf(TaxaGroup);
		   cxComboBox1->ItemIndex = (idx != -1) ? idx : 0;
		   TSSForm->SpecimenTaxaGroup = TaxaGroup;
		   }
		 else {
		   if (!TSSForm->SpecimenTaxaGroup.IsEmpty())
			 cxComboBox1->ItemIndex = cxComboBox1->Properties->Items->IndexOf(TSSForm->SpecimenTaxaGroup);
		   if (cxComboBox1->ItemIndex == -1)
			 cxComboBox1->ItemIndex = 0;
		   UnicodeString msg = L"Taxa group could not be set from Group code in Spreadsheet. ";
		   msg += L"Ensure that it is set correctly.";
		   MessageDlg(msg, mtWarning, TMsgDlgButtons() << mbOK, 0);
		   }
		 }
	   }
	 FillElementList();
   }
}
//---------------------------------------------------------------------------

UnicodeString TSpecimenForm::GetTaxaGroup(UnicodeString EcolGroupCode)
{
  UnicodeString TaxaGroup;
  if (!EcolGroupCode.IsEmpty()) {
	for (unsigned int i=0; i<TSSForm->TaxaEcolGroups.size(); i++) {
	  for (unsigned int j=0; j < TSSForm->TaxaEcolGroups[i].EcolGroups.size(); j++) {
		if (SameText(EcolGroupCode, TSSForm->TaxaEcolGroups[i].EcolGroups[j].Code)) {
		  TaxaGroup = TSSForm->TaxaEcolGroups[i].TaxaGroup.Name;
		  return TaxaGroup;
		  }
		}
	  }
	}
  return TaxaGroup;
}
//---------------------------------------------------------------------------

void TSpecimenForm::EnterSpecimen(SPECIMEN* Specimen, int row)
{
   // grid is not visible yet, so real cols get used
   AdvColumnGrid1->Cells[rc.SpecID][row] = Specimen->UserSpecimenID;
   AdvColumnGrid1->Cells[rc.Elem][row] = Specimen->Element;
   AdvColumnGrid1->Cells[rc.Sym][row] = Specimen->Symmetry;
   AdvColumnGrid1->Cells[rc.Por][row] = Specimen->Portion;
   AdvColumnGrid1->Cells[rc.Mat][row] = Specimen->Maturity;
   AdvColumnGrid1->Cells[rc.Sex][row] = Specimen->Sex;
   AdvColumnGrid1->Cells[rc.Dom][row] = Specimen->DomesticStatus;

   if (Specimen->Taphonomy.size() > 0) {
	 TAPHONOMICSYSTEM::iterator sit;
	 // this is needed if the taphonoomic system is not the default
	 for (sit = Specimen->Taphonomy.begin(); sit != Specimen->Taphonomy.end(); sit++) {
	   UnicodeString System = sit->first;
	   int idx = CheckListEdit1->Items->IndexOf(System);
	   if (idx > -1) {
		 if (!CheckListEdit1->Checked[idx]) {
		   CheckListEdit1->Checked[idx] = true;
		   UpdateTaphSelections();
		   }
		 }
	   }
	 UnicodeString text;
	 for (sit = Specimen->Taphonomy.begin(); sit != Specimen->Taphonomy.end(); sit++) {
	   UnicodeString System = sit->first;
	   set<UnicodeString>& Types = sit->second;
	   set<UnicodeString>::iterator tit;
	   for (tit = Types.begin(); tit != Types.end(); tit++) {
		 UnicodeString taph = System + L":" + *tit;
		 if (!text.IsEmpty())
		   text += L";";
		 text += taph;
		 }
	   }
	 AdvColumnGrid1->Cells[rc.Taph][row] = L"[" + text + L"]";
   }

   AdvColumnGrid1->Cells[rc.Pres][row] = Specimen->Preservative;
   if (!Specimen->NISP.IsEmpty())
	 AdvColumnGrid1->Cells[rc.NISP][row] = FloatToStr((double)Specimen->NISP);
   AdvColumnGrid1->Cells[rc.Rep][row] = Specimen->Repository;
   AdvColumnGrid1->Cells[rc.SpecNr][row] = Specimen->SpecNr;
   AdvColumnGrid1->Cells[rc.FldNr][row] = Specimen->FieldNr;
   AdvColumnGrid1->Cells[rc.ArcNr][row] = Specimen->ArctosNr;
   if (Specimen->GenBankNrs.size() > 0) {
	 UnicodeString Text;
	 set<UnicodeString>::iterator itr;
	 set<UnicodeString>::iterator begin = Specimen->GenBankNrs.begin();
	 set<UnicodeString>::iterator end = Specimen->GenBankNrs.end();
	 for (itr = begin; itr != end; itr++) {
	   if (itr != begin) Text += L";";
		 Text += *itr;
	   }
	 AdvColumnGrid1->Cells[rc.GenNr][row] = Text;
	 }
   AdvColumnGrid1->Cells[rc.Note][row] = Specimen->Notes;
}
//---------------------------------------------------------------------------

void __fastcall TSpecimenForm::FormActivate(TObject *Sender)
{
   if (! activated) {
	 Left = Position.X;
	 Top = Position.Y;
	 activated = true;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TSpecimenForm::FormClose(TObject *Sender, TCloseAction &Action)
{
   // restore original CellObjects, which may include any specimens linked to dates;
   if (CellObjectBackup != NULL) {
	 TList* Specimens = (TList*)CellObject->Object;
	 Specimens->Clear();
	 TList* BSpecimens = (TList*)CellObjectBackup->Object;
	 TList* GridSpecimens = GetGridSpecimens();
	 for (int i=0; i<BSpecimens->Count; i++) {
	   SPECIMEN* BSpecimen = (SPECIMEN*)BSpecimens->Items[i];
	   // if specimen pointer exists in the grid, use it, otherwise use the backup specimen
	   int idx = GridSpecimens->IndexOf((void*)SpecMap[BSpecimen]);
	   if (idx != -1) {
		 SPECIMEN* Specimen = (SPECIMEN*)GridSpecimens->Items[idx];
		 *Specimen = *BSpecimen;  // specimen values restored to original
		 Specimens->Add(Specimen);
		 GridSpecimens->Items[idx] = NULL;
		 delete BSpecimen;
		 BSpecimens->Items[i] = NULL;
		 }
	   else {
		 Specimens->Add(BSpecimen);
		 BSpecimens->Items[i] = NULL;
		 }
	   }

	 for (int i=0; i<GridSpecimens->Count; i++) {
	   SPECIMEN *GSpecimen = (SPECIMEN*)GridSpecimens->Items[i];
	   if (GSpecimen != NULL) {
		 delete GSpecimen;
		 GridSpecimens->Items[i] = NULL;
		 }
	   }
	 GridSpecimens->Clear();
	 delete GridSpecimens;
	 delete CellObjectBackup;
	 }
   tiGlobals->SpecWindHeight = Height;
   tiGlobals->SpecWindWidth = Width;
}
//---------------------------------------------------------------------------

void TSpecimenForm::Setup(void)
{
   AdvColumnGrid1->HideColumns(2,4);
   rc.SpecID = 1;
   rc.Elem = 5;
   rc.Sym = 6;
   rc.Por = 7;
   rc.Mat = 8;
   rc.Sex = 9;
   rc.Dom = 10;
   rc.Taph = 11;
   rc.Pres = 12;
   rc.NISP = 13;
   rc.Rep = 14;
   rc.SpecNr = 15;
   rc.FldNr = 16;
   rc.ArcNr = 17;
   rc.GenNr = 18;
   rc.Note = 19;

   Height = tiGlobals->SpecWindHeight;
   Width = tiGlobals->SpecWindWidth;
   FlowPanel1->Left = (Panel1->Width - FlowPanel1->Width)/2;
   TRect rect = AdvColumnGrid1->CellRect(AdvColumnGrid1->DisplColIndex(rc.Taph),0);
   CheckListEdit1->Left = rect.Left + 1;
   CheckListEdit1->Width = rect.Right - rect.Left + 1;
}
//---------------------------------------------------------------------------

void __fastcall TSpecimenForm::cxComboBox1Click(TObject *Sender)
{
   TSSForm->SpecimenTaxaGroup = cxComboBox1->Properties->Items->Strings[cxComboBox1->ItemIndex];
   FillElementList();
}
//---------------------------------------------------------------------------

void TSpecimenForm::FillElementList(void)
{
   // AdvColumnGrid1->Columns are all in real coordinates
   if (TSSForm->VarLookup->ElementOpen()) {
	 AdvColumnGrid1->Columns->Items[rc.Elem]->ComboItems->Clear();
	 UnicodeString TaxaGroup = cxComboBox1->Properties->Items->Strings[cxComboBox1->ItemIndex];
	 UnicodeString DatasetType = TSSForm->Datasets[TSSForm->DatasetNum].DatasetType.LowerCase();
	 vector<UnicodeString> Elements;
	 TSSForm->ElementLookup->GetElements(DatasetType, TaxaGroup, Elements);
	 AdvColumnGrid1->Columns->Items[rc.Elem]->ComboItems->Add(L"");
	 for (unsigned int i=0; i<Elements.size(); i++)
	   AdvColumnGrid1->Columns->Items[rc.Elem]->ComboItems->Add(Elements[i]);
	 AdvColumnGrid1->Columns->Items[rc.Elem]->ComboItems->Sort();

	 map<UnicodeString, map<UnicodeString, ELEMENTMODIFIERS> > AllModifiers;
	 TSSForm->ElementLookup->GetAllModifiers(AllModifiers);

	 // add symmetry items to ComboBox
	 AdvColumnGrid1->Columns->Items[rc.Sym]->ComboItems->Clear();
	 set<UnicodeString>::iterator itr;
	 set<UnicodeString>::iterator begin = AllModifiers[DatasetType][TaxaGroup].Symmetry.begin();
	 set<UnicodeString>::iterator end = AllModifiers[DatasetType][TaxaGroup].Symmetry.end();
	 AdvColumnGrid1->Columns->Items[rc.Sym]->ComboItems->Add(L"");
	 for (itr = begin; itr != end; itr++)
	   AdvColumnGrid1->Columns->Items[rc.Sym]->ComboItems->Add(*itr);
	 AdvColumnGrid1->Columns->Items[rc.Sym]->ComboItems->Sort();

	 // add portion items to ComboBox
	 AdvColumnGrid1->Columns->Items[rc.Por]->ComboItems->Clear();
	 begin = AllModifiers[DatasetType][TaxaGroup].Portion.begin();
	 end = AllModifiers[DatasetType][TaxaGroup].Portion.end();
	 AdvColumnGrid1->Columns->Items[rc.Por]->ComboItems->Add(L"");
	 for (itr = begin; itr != end; itr++)
	   AdvColumnGrid1->Columns->Items[rc.Por]->ComboItems->Add(*itr);
	 AdvColumnGrid1->Columns->Items[rc.Por]->ComboItems->Sort();

	 // add maturity items to ComboBox
	 AdvColumnGrid1->Columns->Items[rc.Mat]->ComboItems->Clear();
	 begin = AllModifiers[DatasetType][TaxaGroup].Maturity.begin();
	 end = AllModifiers[DatasetType][TaxaGroup].Maturity.end();
	 AdvColumnGrid1->Columns->Items[rc.Mat]->ComboItems->Add(L"");
	 for (itr = begin; itr != end; itr++)
	   AdvColumnGrid1->Columns->Items[rc.Mat]->ComboItems->Add(*itr);
	 AdvColumnGrid1->Columns->Items[rc.Mat]->ComboItems->Sort();
  }
}
//---------------------------------------------------------------------------

void TSpecimenForm::FillSexList(void)
{
   AdvColumnGrid1->Columns->Items[rc.Sex]->ComboItems->Clear();
   set<UnicodeString>::iterator itr;
   AdvColumnGrid1->Columns->Items[rc.Sex]->ComboItems->Add(L"");
   for (itr = TSSForm->SpecimenSex.begin(); itr != TSSForm->SpecimenSex.end(); itr++)
	 AdvColumnGrid1->Columns->Items[rc.Sex]->ComboItems->Add(*itr);
}
//---------------------------------------------------------------------------

void TSpecimenForm::FillDomesticStatusList(void)
{
   AdvColumnGrid1->Columns->Items[rc.Dom]->ComboItems->Clear();
   set<UnicodeString>::iterator itr;
   AdvColumnGrid1->Columns->Items[rc.Dom]->ComboItems->Add(L"");
   for (itr = TSSForm->DomesticStatus.begin(); itr != TSSForm->DomesticStatus.end(); itr++)
	 AdvColumnGrid1->Columns->Items[rc.Dom]->ComboItems->Add(*itr);
}
//---------------------------------------------------------------------------

void __fastcall TSpecimenForm::AdvColumnGrid1CanEditCell(TObject *Sender, int ARow,
		  int ACol, bool &CanEdit)
{
   // ACol is real
   if (ACol >= rc.Sym && AdvColumnGrid1->AllCells[rc.Elem][ARow].IsEmpty() )
	 CanEdit = false;
}
//---------------------------------------------------------------------------

void __fastcall TSpecimenForm::AdvColumnGrid1GetEditorType(TObject *Sender, int ACol,
		  int ARow, TEditorType &AEditor)
{
   //if (ACol == rc.Rep)
   //	 AEditor = edGridDropDown;
}
//---------------------------------------------------------------------------

void __fastcall TSpecimenForm::AdvColumnGrid1GetEditorProp(TObject *Sender, int ACol,
		  int ARow, TEditLink *AEditLink)
{
   if (!repositories_init && ACol == rc.Rep)
	 InitRepositories();
   else if (ACol == rc.GenNr)
	 InitGenBank(ACol,ARow);
}
//---------------------------------------------------------------------------

void TSpecimenForm::InitRepositories(void)
{
   AdvColumnGrid1->AdvGridDropDown->Columns->Clear();
   Advcustomgriddropdown::TDropDownColumn* dc;
   Advcustomgriddropdown::TDropDownItem* di;
   dc = AdvColumnGrid1->AdvGridDropDown->Columns->Add();
   dc->Header = L"Acronym";
   dc->Width = 64;
   dc = AdvColumnGrid1->AdvGridDropDown->Columns->Add();
   dc->Header = L"Repository";
   dc->Width  = 300;

   for (int i = 1; i < TSSForm->AdvColumnGrid2->RowCount; i++) {
	 di = AdvColumnGrid1->AdvGridDropDown->Items->Add();
	 di->Text->Add(TSSForm->AdvColumnGrid2->Cells[1][i]);
	 di->Text->Add(TSSForm->AdvColumnGrid2->Cells[2][i]);
	 }

   AdvColumnGrid1->AdvGridDropDown->LookupColumn = 1;
   AdvColumnGrid1->AdvGridDropDown->DropDownRowHeight = 20;
   AdvColumnGrid1->AdvGridDropDown->DropDownAutoWidth = true;
   AdvColumnGrid1->AdvGridDropDown->ColumnSizing = true;
   repositories_init = true;

   /*
   AdvColumnGrid1->GridDropDown->Columns->Clear();
   Advmulticolumndropdown::TDropDownColumn* dc;
   Advmulticolumndropdown::TDropDownItem* di;
   dc = AdvColumnGrid1->GridDropDown->Columns->Add();
   dc->Header = L"Acronym";
   dc->Width = 64;
   dc = AdvColumnGrid1->GridDropDown->Columns->Add();
   dc->Header = L"Repository";
   dc->Width  = 300;

   for (int i = 1; i < TSSForm->AdvColumnGrid2->RowCount; i++) {
	 di = AdvColumnGrid1->GridDropDown->Items->Add();
	 di->Text->Add(TSSForm->AdvColumnGrid2->Cells[1][i]);
	 di->Text->Add(TSSForm->AdvColumnGrid2->Cells[2][i]);
	 }

   AdvColumnGrid1->GridDropDown->LookupColumn = 1;
   AdvColumnGrid1->GridDropDown->DropDownRowHeight = 20;
   AdvColumnGrid1->GridDropDown->DropDownAutoWidth = true;
   AdvColumnGrid1->GridDropDown->ColumnSizing = true;
   repositories_init = true;
   */
}
//---------------------------------------------------------------------------

void TSpecimenForm::InitGenBank(int ACol, int ARow)
{
   AdvStringGrid1->ClearAll();
   AdvStringGrid1->Row = 0;
   if (!AdvColumnGrid1->Cells[ACol][ARow].IsEmpty()) {
	 vector<UnicodeString> GenBankNrs;
	 ParsePartsIC(AdvColumnGrid1->Cells[ACol][ARow], L";", GenBankNrs);
	 for (unsigned int i = 0; i < GenBankNrs.size(); i++)
	   AdvStringGrid1->Cells[0][i] = GenBankNrs[i];
	 }
}
//---------------------------------------------------------------------------

// gets value from the dropdown editor after dropping up
void __fastcall TSpecimenForm::FormControlEditLink1GetEditorValue(TObject *Sender,
		  TAdvStringGrid *Grid, UnicodeString &AValue)
{
   AValue = AdvControlDropDown1->Text;
}
//---------------------------------------------------------------------------

// sets the value in the editor for the dropdown
void __fastcall TSpecimenForm::FormControlEditLink1SetEditorValue(TObject *Sender,
		  TAdvStringGrid *Grid, UnicodeString AValue)
{
   AdvControlDropDown1->Text = AValue;
}
//---------------------------------------------------------------------------

void __fastcall TSpecimenForm::FormControlEditLink2GetEditorValue(TObject *Sender,
		  TAdvStringGrid *Grid, UnicodeString &AValue)
{
   AValue = AdvEdit1->Text;
}
//---------------------------------------------------------------------------

void __fastcall TSpecimenForm::FormControlEditLink2SetEditorValue(TObject *Sender,
		  TAdvStringGrid *Grid, UnicodeString AValue)
{
   AdvEdit1->Text = AValue;
}
//---------------------------------------------------------------------------

void __fastcall TSpecimenForm::FormControlEditLink3GetEditorValue(TObject *Sender,
		  TAdvStringGrid *Grid, UnicodeString &AValue)
{
   AValue = CheckListEdit2->Text;
}
//---------------------------------------------------------------------------

void __fastcall TSpecimenForm::FormControlEditLink3SetEditorValue(TObject *Sender,
		  TAdvStringGrid *Grid, UnicodeString AValue)
{
   CheckListEdit2->Text = AValue;
}
//---------------------------------------------------------------------------

void __fastcall TSpecimenForm::AdvControlDropDown1DropUp(TObject *Sender, bool Cancelled)
{
   if (!Cancelled) {
	 // post data in editor if still in edit mode
	 AdvStringGrid1->HideInplaceEdit();

	 UnicodeString Text;
	 set<UnicodeString> GenBankSet;
	 for (int row=0; row < AdvStringGrid1->RowCount; row++) {
	   if (!AdvStringGrid1->Cells[0][row].IsEmpty())
		 GenBankSet.insert(AdvStringGrid1->Cells[0][row]);
	   }
	 set<UnicodeString>::iterator itr;
	 for (itr = GenBankSet.begin(); itr != GenBankSet.end(); itr++) {
	   if (!Text.IsEmpty())
		 Text += L";";
	   Text += *itr;
	   }
	 AdvControlDropDown1->Text = Text;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TSpecimenForm::AdvControlDropDown1DropDownFooterButtonClick(TObject *Sender,
		  int ButtonIndex)
{
   if (ButtonIndex == 1) {  // Ok button
	 UnicodeString Text;
	 for (int i = 0; i < AdvStringGrid1->RowCount; i++) {
	   UnicodeString GenBankNr = AdvStringGrid1->Cells[0][i];
	   if (!GenBankNr.IsEmpty()) {
		 if (i > 0)
		   Text += L";";
		 Text += GenBankNr;
		 }
	   }
	 }
   else if (ButtonIndex == 2) {  // Add button
	 AdvStringGrid1->RowCount++;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TSpecimenForm::Panel1Resize(TObject *Sender)
{
   if (activated)
	 FlowPanel1->Left = (Panel1->Width - FlowPanel1->Width)/2;
}
//---------------------------------------------------------------------------

void __fastcall TSpecimenForm::AdvColumnGrid1Resize(TObject *Sender)
{
   if (activated)
	 cxComboBox1->Width = AdvColumnGrid1->Columns->Items[0]->Width +
	                      AdvColumnGrid1->Columns->Items[1]->Width + 1;
}
//---------------------------------------------------------------------------

// Ok button
void __fastcall TSpecimenForm::cxButton1Click(TObject *Sender)
{
   TProfGridCell* ACell = TSSForm->ProfGrid1->Cells[TSSForm->ProfGrid1->Col][TSSForm->ProfGrid1->Row];

   // if specimens exist and CellObject doesn't, create CellObject

   TList* GridSpecimens = GetGridSpecimens();

   if (GridSpecimens->Count > 0 && CellObject == NULL) {
	 CellObject = new CELLOBJECT(CELLSPECIMENS);
	 TSSForm->AddCellObject(ACell, CellObject);
	 }

   if (CellObject != NULL) {
	 if (GridSpecimens->Count > 0) {
	   TList* Specimens = (TList*)CellObject->Object;
	   // clear the existing specimens and add the new
	   Specimens->Clear();
	   Specimens->Assign(GridSpecimens);

	   if (TSSForm->Downloaded && tiLicense->Type() == verNEOTOMASTEWARD)
		 UpdateSpecimens(GridSpecimens);
	   }
	 else {
       TSSForm->DeleteCellObject(ACell);
	   }
	 }
   GridSpecimens->Clear();
   delete GridSpecimens;
   delete CellObjectBackup;
   CellObjectBackup = NULL;
}
//---------------------------------------------------------------------------

void TSpecimenForm::UpdateSpecimens(TList* GridSpecimens)
{
   bool update = false;
   vector<int> ChangedSpecimens;
   UnicodeString msg, ErrorMsg;
   vector<int> newids;

   // check if any new specimens have been added or changed
   for (int i=0; i<GridSpecimens->Count; i++) {
	 SPECIMEN* Specimen = (SPECIMEN*)GridSpecimens->Items[i];
	 if (Specimen->NeotomaSpecimenID == -1)
	   update = true;
	 else if (CellObjectBackup != NULL) {
	   TList* BSpecimens = (TList*)CellObjectBackup->Object;
	   for (int i=0; i<BSpecimens->Count; i++) {
		 SPECIMEN* BSpecimen = (SPECIMEN*)BSpecimens->Items[i];
		 if (Specimen->NeotomaSpecimenID == BSpecimen->NeotomaSpecimenID) {
		   if (!(*Specimen == *BSpecimen)) {
			 ChangedSpecimens.push_back(Specimen->NeotomaSpecimenID);
			 update = true;
			 }
		   break;
		   }
		 }
	   }
	 }

   if (!update)
	 return;
   else if (MessageDlg(L"Update specimens in Neotoma?", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrNo)
	 return;

   if (!Login->IsLoggedIn) {
	 Screen->Cursor = crDefault;
	 NeotomaLoginForm = new TNeotomaLoginForm(this);
	 NeotomaLoginForm->ShowModal();
	 delete NeotomaLoginForm;
	 Screen->Cursor = crHourGlass;
	 }
   if (!Login->IsLoggedIn) return;

   // add new specimens
   TProfGridCell* ACell = TSSForm->ProfGrid1->Cells[TSSForm->ProfGrid1->Col][TSSForm->ProfGrid1->Row];
   int DataID = ACell->CustomData;

   int new_specimens = 0;
   int updated_specimens = 0;
   for (int i=0; i<GridSpecimens->Count; i++) {
	 SPECIMEN* Specimen = (SPECIMEN*)GridSpecimens->Items[i];
	 if (Specimen->NeotomaSpecimenID == -1) {  // new specimen
	   NeotomaElementTypeByName NeotomaElementType(ipsJSONS1, TcpClient1);
	   NeotomaElementType.AddParam(L"ELEMENTTYPE", Specimen->Element);
	   ParentForm->StatusBar1->Panels->Items[0]->Text = NeotomaElementType.WebServiceName();
	   if (NeotomaElementType.Execute()) {
		 if (NeotomaElementType.Size() == 1)
		   Specimen->NeotomaElementID = NeotomaElementType.Items.begin()->first;
		 else {
		   msg = L"Element «" + Specimen->Element + L"» is not in the Neotoma ElementTypes table.";
		   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   return;
		   }
		 }
	   else
		 return;

	   if (!Specimen->Symmetry.IsEmpty()) {
		 NeotomaElementSymmetryByName NeotomaSymmetry(ipsJSONS1, TcpClient1);
		 NeotomaSymmetry.AddParam(L"SYMMETRY", Specimen->Symmetry);
		 ParentForm->StatusBar1->Panels->Items[0]->Text = NeotomaSymmetry.WebServiceName();
		 if (NeotomaSymmetry.Execute()) {
		   if (NeotomaSymmetry.Size() == 1)
			 Specimen->NeotomaSymmetryID = NeotomaSymmetry.Items.begin()->first;
		   else {
			 msg = L"Symmetry «" + Specimen->Symmetry + L"» is not in the Neotoma ElementSymmetries table.";
			 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			 return;
			 }
		   }
		 else
		   return;
		 }

	   if (!Specimen->Portion.IsEmpty()) {
		 NeotomaElementPortionByName NeotomaPortion(ipsJSONS1, TcpClient1);
		 NeotomaPortion.AddParam(L"PORTION", Specimen->Portion);
		 ParentForm->StatusBar1->Panels->Items[0]->Text = NeotomaPortion.WebServiceName();
		 if (NeotomaPortion.Execute()) {
		   if (NeotomaPortion.Size() == 1)
			 Specimen->NeotomaPortionID = NeotomaPortion.Items.begin()->first;
		   else {
			 msg = L"Portion «" + Specimen->Portion + L"» is not in the Neotoma ElementPortions table.";
			 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			 return;
			 }
		   }
		 else
		   return;
		 }

	   if (!Specimen->Maturity.IsEmpty()) {
		 NeotomaElementMaturityByName NeotomaMaturity(ipsJSONS1, TcpClient1);
		 NeotomaMaturity.AddParam(L"MATURITY", Specimen->Maturity);
		 ParentForm->StatusBar1->Panels->Items[0]->Text = NeotomaMaturity.WebServiceName();
		 if (NeotomaMaturity.Execute()) {
		   if (NeotomaMaturity.Size() == 1)
			 Specimen->NeotomaMaturityID = NeotomaMaturity.Items.begin()->first;
		   else {
			 msg = L"Maturity «" + Specimen->Maturity + L"» is not in the Neotoma ElementMaturities table.";
			 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			 return;
			 }
		   }
		 else
		   return;
		 }

	   if (!Specimen->Sex.IsEmpty()) {
		 NeotomaSpecimenSexByName NeotomaSex(ipsJSONS1, TcpClient1);
		 NeotomaSex.AddParam(L"SEX", Specimen->Sex);
		 ParentForm->StatusBar1->Panels->Items[0]->Text = NeotomaSex.WebServiceName();
		 if (NeotomaSex.Execute()) {
		   if (NeotomaSex.Size() == 1)
			 Specimen->NeotomaSexID = NeotomaSex.Items.begin()->first;
		   else {
			 msg = L"Sex «" + Specimen->Sex + L"» is not in the Neotoma SpecimenSexTypes table.";
			 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			 return;
			 }
		   }
		 else
		   return;
		 }

	   if (!Specimen->DomesticStatus.IsEmpty()) {
		 NeotomaSpecimenDomStatByName NeotomaDomStat(ipsJSONS1, TcpClient1);
		 NeotomaDomStat.AddParam(L"DOMESTICSTATUS", Specimen->DomesticStatus);
		 ParentForm->StatusBar1->Panels->Items[0]->Text = NeotomaDomStat.WebServiceName();
		 if (NeotomaDomStat.Execute()) {
		   if (NeotomaDomStat.Size() == 1)
			 Specimen->NeotomaDomesticStatusID = NeotomaDomStat.Items.begin()->first;
		   else {
			 msg = L"Domestic status «" + Specimen->DomesticStatus + L"» is not in the Neotoma SpecimenDomesticStatusTypes table.";
			 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			 return;
			 }
		   }
		 else
		   return;
		 }

	   if (!Specimen->Repository.IsEmpty()) {
		 NeotomaRepositoryInstitution Repository(ipsJSONS1, TcpClient1);
		 Repository.AddParam(L"REPOSITORY", Specimen->Repository);
		 ParentForm->StatusBar1->Panels->Items[0]->Text = Repository.WebServiceName();
		 if (Repository.Execute()) {
		   if (Repository.Size() == 1)
			 Specimen->NeotomaRepositoryID = Repository.Items[0].RepositoryID;
		   else {
			 msg = L"Repository «" + Specimen->Repository + L"» is not in the Neotoma RepositoryInstitutions table.";
			 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			 return;
			 }
		   }
		 else
		   return;
		 }

	   if (Specimen->Taphonomy.size() > 0) {
		 TAPHONOMICSYSTEM::iterator itr;
		 for (itr = Specimen->Taphonomy.begin(); itr != Specimen->Taphonomy.end(); itr++) {
		   UnicodeString System = itr->first;
		   NeotomaTaphonomicSystemByName TaphSystem(ipsJSONS1, TcpClient1);
		   TaphSystem.AddParam(L"TAPHONOMICSYSTEM", System);
		   ParentForm->StatusBar1->Panels->Items[0]->Text = TaphSystem.WebServiceName();
		   if (TaphSystem.Execute()) {
			 if (TaphSystem.Size() != 1) {
			   msg = L"Taphonomic system «" + System + L"» is not in the Neotoma TaphonomicSystems table.";
			   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			   return;
			   }
			 }
		   else
			 return;
		   int TaphSystemID = TaphSystem.Items[0].TaphonomicSystemID;

		   set<UnicodeString>& Types = itr->second;
		   set<UnicodeString>::iterator it;
		   for (it = Types.begin(); it != Types.end(); it++) {
			 NeotomaTaphonomicTypeID TaphType(ipsJSONS1, TcpClient1);
			 TaphType.AddParam(L"TAPHONOMICSYSTEMID", TaphSystemID);
			 TaphType.AddParam(L"TAPHONOMICTYPE", *it);
			 ParentForm->StatusBar1->Panels->Items[0]->Text = TaphType.WebServiceName();
			 if (TaphType.Execute()) {
			   if (TaphType.Size() != 1) {
				 msg = L"Taphonomic type «" + *it + L"» for system «" + System +
					   "» is not in the Neotoma TaphonomicTypes table.";
				 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
				 return;
				}
			   }
			 else
			   return;
			 int TaphTypeID = TaphType.Items[0];
			 Specimen->NeotomaTaphonomy.insert(TaphTypeID);
			 }
		   }
		 }

	   InsertData InsertSpecimen(L"InsertSpecimen", 14, ipsHTTPS1, ipsJSONS1, TcpClient1);
	   Specimen->NeotomaDataID = DataID;    // assign NeotomaDataID to specimen -- needed for isotopes
	   InsertSpecimen.Add(L"DATAID", DataID, -1);
	   InsertSpecimen.Add(L"ELEMENTTYPEID", Specimen->NeotomaElementID, -1);
	   InsertSpecimen.Add(L"SYMMETRYID", Specimen->NeotomaSymmetryID, -1);
	   InsertSpecimen.Add(L"PORTIONID", Specimen->NeotomaPortionID, -1);
	   InsertSpecimen.Add(L"MATURITYID", Specimen->NeotomaMaturityID, -1);
	   InsertSpecimen.Add(L"SEXID", Specimen->NeotomaSexID, -1);
	   InsertSpecimen.Add(L"DOMESTICSTATUSID", Specimen->NeotomaDomesticStatusID, -1);
	   InsertSpecimen.Add(L"PRESERVATIVE", Specimen->Preservative);
	   InsertSpecimen.AddDouble(L"NISP", Specimen->NISP);
	   InsertSpecimen.Add(L"REPOSITORYID", Specimen->NeotomaRepositoryID, -1);
	   InsertSpecimen.Add(L"SPECIMENNR", Specimen->SpecNr);
	   InsertSpecimen.Add(L"FIELDNR", Specimen->FieldNr);
	   InsertSpecimen.Add(L"ARCTOSNR", Specimen->ArctosNr);
	   InsertSpecimen.Add(L"NOTES", Specimen->Notes);

	   int SpecimenID;
	   newids.clear();
	   ParentForm->StatusBar1->Panels->Items[0]->Text = L"InsertSpecimen";
	   InsertSpecimen.PostData();
	   if (InsertSpecimen.Post(newids, ErrorMsg)) {
		 new_specimens++;
		 SpecimenID = newids[0];
		 Specimen->NeotomaSpecimenID = SpecimenID;
		 Specimen->UserSpecimenID = IntToStr(SpecimenID);
		 }
	   else {
		 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 return;
		 }

	   // upload GenBank numbers
	   if (Specimen->GenBankNrs.size() > 0) {
		 InsertData InsertGenBankNr(L"InsertSpecimenGenBankNr", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
		 set<UnicodeString>::iterator itr;
		 for (itr = Specimen->GenBankNrs.begin(); itr != Specimen->GenBankNrs.end(); itr++) {
		   InsertGenBankNr.Add(L"SPECIMENID", SpecimenID, -1);
		   InsertGenBankNr.Add(L"GENBANKNR", *itr);
		   }
		 ParentForm->StatusBar1->Panels->Items[0]->Text = L"InsertSpecimenGenBankNr";
		 InsertGenBankNr.PostData();
		 if (!InsertGenBankNr.Post(ErrorMsg)) {
		   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   return;
		   }
		 }

	   // upload Taphonomy
	   if (Specimen->NeotomaTaphonomy.size() > 0) {
		 InsertData InsertSpecTaph(L"InsertSpecimenTaphonomy", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
		 for (unsigned int k = 0; k < Specimen->NeotomaTaphonomy.size(); k++) {
		   set<int>::iterator itr;
		   for (itr = Specimen->NeotomaTaphonomy.begin(); itr != Specimen->NeotomaTaphonomy.end(); itr++) {
			 InsertSpecTaph.Add(L"SPECIMENID",SpecimenID,-1);
			 InsertSpecTaph.Add(L"TAPHONOMICTYPEID",*itr,-1);
			 }
		   }
		 ParentForm->StatusBar1->Panels->Items[0]->Text = L"InsertSpecimenTaphonomy";
		 InsertSpecTaph.PostData();
		 if (!InsertSpecTaph.Post(ErrorMsg)) {
		   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   return;
		   }
		 }
	   }
	 else if (CellObjectBackup != NULL) {   // existing specimen
	   TList* BSpecimens = (TList*)CellObjectBackup->Object;
	   SPECIMEN* Specimen = (SPECIMEN*)GridSpecimens->Items[i];
	   if (Specimen->NeotomaSpecimenID != -1) {
		 for (int j=0; j<BSpecimens->Count; j++) {
		   SPECIMEN* BSpecimen = (SPECIMEN*)BSpecimens->Items[j];
		   if (Specimen->NeotomaSpecimenID == BSpecimen->NeotomaSpecimenID) {
			 if (!(*Specimen == *BSpecimen))
			   if (UpdateSpecimen(BSpecimen, Specimen))
				 updated_specimens++;
			   else
				 return;
			 break;
			 }
		   }
		 }
	   }
	 }

   if (new_specimens > 0) {
	 msg = IntToStr(new_specimens) + L" new specimen";
	 if (new_specimens > 1)
	   msg += L"s";
	 msg += L" uploaded to Neotoma.";
	 }
   if (updated_specimens > 0) {
	 if (new_specimens > 0)
	   msg += L"\n";
	 msg += IntToStr(updated_specimens) + L" specimen";
	 if (updated_specimens > 1)
	   msg += L"s";
	 msg += L" updated.";
	 }
   ParentForm->StatusBar1->Panels->Items[0]->Text = L"";
   MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
}
//---------------------------------------------------------------------------

bool TSpecimenForm::UpdateSpecimen(SPECIMEN* OldSpec, SPECIMEN* NewSpec)
{
   UnicodeString ErrorMsg;
   vector<pair<int,UnicodeString> > Service;

   if (NewSpec->NISP != OldSpec->NISP)
	 Service.push_back(pair<int,UnicodeString>(1,L"UpdateSpecimenNISP"));
   if (NewSpec->Notes != OldSpec->Notes)
	 Service.push_back(pair<int,UnicodeString>(2,L"UpdateSpecimenNotes"));
   if (NewSpec->SpecNr != OldSpec->SpecNr)
	 Service.push_back(pair<int,UnicodeString>(3,L"UpdateSpecimenNumber"));

   for (unsigned int i = 0; i < Service.size(); i++) {
	 UpdateData UpdateSpecimen(Service[i].second, 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
	 UpdateSpecimen.Add(L"SPECIMENID", OldSpec->NeotomaSpecimenID);
	 switch (Service[i].first) {
	   case 1:
		 UpdateSpecimen.AddDouble(L"NISP", NewSpec->NISP);
		 break;
	   case 2:
		 UpdateSpecimen.Add(L"NOTES", NewSpec->Notes);
		 break;
	   case 3:
		 UpdateSpecimen.Add(L"SPECIMENNR", NewSpec->SpecNr);
		 break;
	   }
	 UpdateSpecimen.Add(L"CONTACTID", Login->ContactID);
	 ParentForm->StatusBar1->Panels->Items[0]->Text = Service[i].second;
	 if (!UpdateSpecimen.Post(ErrorMsg)) {
	   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return false;
	   }
	 }
   return true;
}
//---------------------------------------------------------------------------

TList* TSpecimenForm::GetGridSpecimens(void)
{
   TList* GridSpecimens = new TList;
   for (int row = 1; row < AdvColumnGrid1->RowCount; row++) {
	 if (AdvColumnGrid1->Objects[rc.SpecID][row] != NULL) {
	   SPECIMEN *Specimen = (SPECIMEN*)AdvColumnGrid1->Objects[rc.SpecID][row];
	   Specimen->UserSpecimenID = AdvColumnGrid1->Cells[rc.SpecID][row];
	   Specimen->Element = AdvColumnGrid1->Cells[rc.Elem][row];
	   Specimen->Symmetry = AdvColumnGrid1->Cells[rc.Sym][row];
	   Specimen->Portion = AdvColumnGrid1->Cells[rc.Por][row];
	   Specimen->Maturity = AdvColumnGrid1->Cells[rc.Mat][row];
	   Specimen->Sex = AdvColumnGrid1->Cells[rc.Sex][row];
	   Specimen->DomesticStatus = AdvColumnGrid1->Cells[rc.Dom][row];
	   Specimen->Taphonomy.clear();
	   vector<UnicodeString> taphvec;
	   UnicodeString taphs = AdvColumnGrid1->Cells[rc.Taph][row];
	   ParsePartsIC(taphs.SubString(2,taphs.Length()-2), L";", taphvec);
	   for (unsigned int j = 0; j < taphvec.size(); j++) {
		 UnicodeString taph = taphvec[j];
		 int pos = taph.Pos(L":");
		 UnicodeString System = taph.SubString(1,pos-1);
		 UnicodeString Type = taph.Delete(1,pos);
		 Specimen->Taphonomy[System].insert(Type);
		 }
	   Specimen->Preservative = AdvColumnGrid1->Cells[rc.Pres][row];
	   if (!AdvColumnGrid1->Cells[rc.NISP][row].IsEmpty())
		 Specimen->NISP = AdvColumnGrid1->Cells[rc.NISP][row].ToDouble();
	   Specimen->Repository = AdvColumnGrid1->Cells[rc.Rep][row];
	   Specimen->SpecNr = AdvColumnGrid1->Cells[rc.SpecNr][row];
	   Specimen->FieldNr = AdvColumnGrid1->Cells[rc.FldNr][row];
	   Specimen->ArctosNr = AdvColumnGrid1->Cells[rc.ArcNr][row];
	   Specimen->GenBankNrs.clear();
	   if (!AdvColumnGrid1->Cells[rc.GenNr][row].IsEmpty()) {
		 vector<UnicodeString> GenBankNrs;
		 ParsePartsIC(AdvColumnGrid1->Cells[rc.GenNr][row], L";", GenBankNrs);
		 for (unsigned int i = 0; i < GenBankNrs.size(); i++)
		   Specimen->GenBankNrs.insert(GenBankNrs[i]);
		 }
	   Specimen->Notes = AdvColumnGrid1->Cells[rc.Note][row];
	   GridSpecimens->Add(Specimen);
	   }
	 }
   return GridSpecimens;
}
//---------------------------------------------------------------------------

void __fastcall TSpecimenForm::AdvColumnGrid1GetDisplText(TObject *Sender, int ACol,
		  int ARow, UnicodeString &Value)
{
   if (ACol == 0 && ARow > 0)
	 Value = IntToStr(ARow);
}
//---------------------------------------------------------------------------

// add row
void __fastcall TSpecimenForm::ToolButton1Click(TObject *Sender)
{
   int row = AdvColumnGrid1->Row;
   AdvColumnGrid1->InsertRows(row,1);
}
//---------------------------------------------------------------------------

// delete row
void __fastcall TSpecimenForm::ToolButton2Click(TObject *Sender)
{
   int ARow = AdvColumnGrid1->Row;

   if (AdvColumnGrid1->Objects[rc.SpecID][ARow] != NULL) {
	 SPECIMEN* Specimen = (SPECIMEN*)AdvColumnGrid1->Objects[rc.SpecID][ARow];
	 if (TSSForm->HasGeochronLink(Specimen)) {
	   UnicodeString msg = L"Specimen is linked to dated taxon in Geochronology.\nCannot delete specimen.";
	   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return;
	   }
	 else {
	   TList* Specimens = (TList*)CellObject->Object;
	   Specimens->Extract(Specimen);
	   delete Specimen;
	   }
	 }
   AdvColumnGrid1->RemoveRows(ARow,1);
}
//---------------------------------------------------------------------------

void TSpecimenForm::CreateSpecimen(int ARow, UnicodeString& Value)
{
   SPECIMEN *Specimen = new SPECIMEN();
   if (TSSForm->SpecimenIDs.empty())
	 Specimen->SpecimenID = 1;
   else
	 Specimen->SpecimenID = *(TSSForm->SpecimenIDs.rbegin()) + 1;
   TSSForm->SpecimenIDs.insert(Specimen->SpecimenID);
   Specimen->Taxon = TSSForm->ProfGrid1->Cells[2][TSSForm->ProfGrid1->Row]->Text;
   Specimen->TaxaGroup = cxComboBox1->Properties->Items->Strings[cxComboBox1->ItemIndex];
   Specimen->Element = Value;
   AdvColumnGrid1->Objects[rc.SpecID][ARow] = (TObject*)Specimen;
}
//---------------------------------------------------------------------------

void __fastcall TSpecimenForm::AdvColumnGrid1CellBalloon(TObject *Sender, int ACol,
		  int ARow, UnicodeString &ATitle, UnicodeString &AText, int &AIcon)
{
   // ACol is real

   if (ARow == 0) {
	 if (ACol == rc.SpecID) {
	   ATitle = L"Specimen ID";
	   AText = L"Unique ID for linking with other worksheets";
	   }
	 else if (ACol == rc.Elem) {
	   ATitle = L"Element";
	   AText = L" ";
	   }
	 else if (ACol == rc.Sym) {
	   ATitle = L"Symmetry";
	   AText = L" ";
	   }
	 else if (ACol == rc.Por) {
	   ATitle = L"Portion";
	   AText = L" ";
	   }
	 else if (ACol == rc.Mat) {
	   ATitle = L"Maturity";
	   AText = L" ";
	   }
	 else if (ACol == rc.Sex) {
	   ATitle = L"Sex";
	   AText = L" ";
	   }
	 else if (ACol == rc.Dom) {
	   ATitle = L"Domestic Status";
	   AText = L" ";
	   }
	 else if (ACol == rc.Taph) {
	   ATitle = L"Taphonomy";
	   AText = L" ";
	   }
	 else if (ACol == rc.Pres) {
	   ATitle = L"Preservative";
	   AText = L" ";
	   }
	 else if (ACol == rc.NISP) {
	   ATitle = L"NISP";
	   AText = L" ";
	   }
	 else if (ACol == rc.Rep) {
	   ATitle = L"Repository";
	   AText = L" ";
	   }
	 else if (ACol == rc.SpecNr) {
	   ATitle = L"Specimen Number";
	   AText = L"Repository specimen, catalog, or accession number.\nDo not include repository acronym.";
	   }
	 else if (ACol == rc.FldNr) {
	   ATitle = L"Field Number";
	   AText = L" ";
	   }
	 else if (ACol == rc.ArcNr) {
	   ATitle = L"Arctos Number";
	   AText = L"e.g. MVZ:Mamm:5599\nhttps://arctosdb.org/";
	   }
	 else if (ACol == rc.GenNr) {
	   ATitle = L"GenBank Accession Numbers";
	   AText = L"http://www.ncbi.nlm.nih.gov/genbank/";
	   }
	 else if (ACol == rc.Note) {
	   ATitle = L"Notes";
	   AText = L" ";
	   }
	 }
   else
	 AText = L"";
}
//---------------------------------------------------------------------------

void __fastcall TSpecimenForm::AdvColumnGrid1EndColumnSize(TObject *Sender, int ACol)
{
   TRect rect = AdvColumnGrid1->CellRect(AdvColumnGrid1->DisplColIndex(rc.Taph),0);
   CheckListEdit1->Left = rect.Left + 1;
   CheckListEdit1->Width = rect.Right - rect.Left + 1;
}
//---------------------------------------------------------------------------

void __fastcall TSpecimenForm::AdvColumnGrid1TopLeftChanged(TObject *Sender)
{
   // keeps the Taphonomy System above the Taphonomy column
   TRect rect = AdvColumnGrid1->CellRect(AdvColumnGrid1->DisplColIndex(rc.Taph),0);
   CheckListEdit1->Left = rect.Left + 1;
   CheckListEdit1->Width = rect.Right - rect.Left + 1;
   TRect rect2 = AdvColumnGrid1->CellRect(2,0);
   CheckListEdit1->Visible = (CheckListEdit1->Left > cxComboBox1->Width-1);
}
//---------------------------------------------------------------------------

void __fastcall TSpecimenForm::CheckListEdit1Change(TObject *Sender)
{
   UpdateTaphSelections();
}
//---------------------------------------------------------------------------

void TSpecimenForm::UpdateTaphSelections(void)
{
   TAPHONOMYLOOKUP* TaphLookup = TSSForm->VarLookup->GetTaphonomyLookup();
   set<UnicodeString> Systems;
   for (int i = 0; i < CheckListEdit1->Items->Count; i++) {
	 if (CheckListEdit1->Checked[i])
	   Systems.insert(CheckListEdit1->Items->Strings[i]);
	 }
   CheckListEdit2->Items->Clear();
   set<UnicodeString>::iterator sitr;
   for (sitr = Systems.begin(); sitr != Systems.end(); sitr++) {
	 set<UnicodeString> Types;
	 TaphLookup->GetTypes(DatasetType, *sitr, Types);
	 set<UnicodeString>::iterator itr;
	 for (itr = Types.begin(); itr != Types.end(); itr++)
	   CheckListEdit2->Items->Add(*sitr + L":" + *itr);
	 }
}
//---------------------------------------------------------------------------

void __fastcall TSpecimenForm::AdvColumnGrid1CellValidate(TObject *Sender, int ACol,
		  int ARow, UnicodeString &Value, bool &Valid)
{
   // ACol is the real column

   UnicodeString msg;

   if (ACol == rc.Elem) {
	 if (Value.IsEmpty()) {
	   if (AdvColumnGrid1->Objects[rc.SpecID][ARow] != NULL) {
		 SPECIMEN* Specimen = (SPECIMEN*)AdvColumnGrid1->Objects[rc.SpecID][ARow];
         msg = L"Delete this specimen?";
		 if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes) {
		   if (TSSForm->HasGeochronLink(Specimen)) {
			 msg = L"Specimen is linked to dated taxon in Geochronology.\nCannot delete specimen.";
			 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			 Valid = false;
			 }
		   else {
			 delete Specimen;
			 AdvColumnGrid1->Objects[rc.SpecID][ARow] = NULL;
			 }
		   }
		 else
		   Valid = false;

		 /*
		 if (TSSForm->HasGeochronLink(Specimen)) {
		   UnicodeString msg = L"Specimen is linked to dated taxon in Geochronology.\nCannot delete specimen.";
		   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   Valid = false;
		   }
		 else {
		   msg = L"Delete this specimen?";
		   if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes) {
			 delete Specimen;
			 AdvColumnGrid1->Objects[rc.SpecID][ARow] = NULL;
			 }
		   else
			 Valid = false;
		   }
		 */
		 }
	   }
	 else {  // Value not empty
	   if (AdvColumnGrid1->Objects[rc.SpecID][ARow] == NULL)
		 CreateSpecimen(ARow, Value);
	   }
	 }
   else
	 Validate(ACol, ARow, Value, Valid);

   /*
   else if (ACol == rc.NISP) {
	 if (!TryStrToFloat(Value,dValue)) {
	   Beep();
	   Valid = false;
	   }
	 }
   */
}
//---------------------------------------------------------------------------

bool TSpecimenForm::Validate(int ACol, int ARow, UnicodeString &Value, bool &Allow)
{
   // ACol is the display column

   double dValue;

   //ShowMessage(L"ACol == " + IntToStr(ACol));
   //ShowMessage(L"DisplColIndex == " + IntToStr(AdvColumnGrid1->DisplColIndex(rc.Sym)));
   if (ACol == rc.Sym) {
	 Value = Value.LowerCase();
	 if (AdvColumnGrid1->Columns->Items[rc.Sym]->ComboItems->IndexOf(Value) == -1) {
	   Beep();
	   Allow = false;
	   }
	 }
   else if (ACol == rc.Por) {
	 Value = Value.LowerCase();
	 if (AdvColumnGrid1->Columns->Items[rc.Por]->ComboItems->IndexOf(Value) == -1) {
	   Beep();
	   Allow = false;
	   }
	 }
   else if (ACol == rc.Mat) {
	 Value = Value.LowerCase();
	 if (AdvColumnGrid1->Columns->Items[rc.Mat]->ComboItems->IndexOf(Value) == -1) {
	   Beep();
	   Allow = false;
	   }
	 }
   else if (ACol == rc.Sex) {
	 Value = Value.LowerCase();
	 if (AdvColumnGrid1->Columns->Items[rc.Sex]->ComboItems->IndexOf(Value) == -1) {
	   Beep();
	   Allow = false;
	   }
	 }
   else if (ACol == rc.Dom) {
	 Value = Value.LowerCase();
	 if (AdvColumnGrid1->Columns->Items[rc.Dom]->ComboItems->IndexOf(Value) == -1) {
	   Beep();
	   Allow = false;
	   }
	 }
   else if (ACol == rc.NISP) {
	 if (!TryStrToFloat(Value,dValue)) {
	   Beep();
	   Allow = false;
	   }
	 }

   return Allow;
}
//---------------------------------------------------------------------------

void __fastcall TSpecimenForm::AdvColumnGrid1ClipboardBeforePasteCell(TObject *Sender,
		  int ACol, int ARow, UnicodeString &Value, bool &Allow)
{
   // ACol is the display column

   double dValue;

   Value = Value.Trim();

   if (ACol == AdvColumnGrid1->DisplColIndex(rc.Elem)) {
	 if (Value.IsEmpty()) {
	   // this is because element cannot be empty.
	   ShowMessage(L"Value is empty");
	   Beep();
	   Allow = false;
	   }
	 else {
	   Value = Value.LowerCase();
	   if (AdvColumnGrid1->Columns->Items[rc.Elem]->ComboItems->IndexOf(Value) == -1) {
		 Beep();
		 Allow = false;
		 }
	   }
	 }
   else
	 Validate(ACol, ARow, Value, Allow);
}
//---------------------------------------------------------------------------

void __fastcall TSpecimenForm::AdvColumnGrid1ClipboardAfterPasteCell(TObject *Sender,
		  int ACol, int ARow, UnicodeString Value)
{
   // ACol is the display column
   if (ACol == AdvColumnGrid1->DisplColIndex(rc.Elem)) {
	 if (!Value.IsEmpty() && AdvColumnGrid1->Objects[rc.SpecID][ARow] == NULL)
	   CreateSpecimen(ARow, Value);
	 }
}
//---------------------------------------------------------------------------

void __fastcall TSpecimenForm::cxCheckBox1Click(TObject *Sender)
{
   AdvColumnGrid1->SortSettings->Show = cxCheckBox1->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TSpecimenForm::AdvColumnGrid1RowChanging(TObject *Sender, int OldRow,
		  int NewRow, bool &Allow)
{
   return;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

__fastcall TAllSpecimensForm::TAllSpecimensForm(TPoint pos, TComponent* Owner)
	: TSpecimenForm(pos, NULL, Owner)
{
}
//---------------------------------------------------------------------------

void TAllSpecimensForm::Setup(void)
{
   rc.SpecID = 1;
   rc.Dep = 2;
   rc.Anal = 3;
   rc.Tax = 4;
   rc.Elem = 5;
   rc.Sym = 6;
   rc.Por = 7;
   rc.Mat = 8;
   rc.Sex = 9;
   rc.Dom = 10;
   rc.Taph = 11;
   rc.Pres = 12;
   rc.NISP = 13;
   rc.Rep = 14;
   rc.SpecNr = 15;
   rc.FldNr = 16;
   rc.ArcNr = 17;
   rc.GenNr = 18;
   rc.Note = 19;

   Height = tiGlobals->SpecWindHeight;
   Width = tiGlobals->SpecWindWidth;
   FlowPanel1->Left = (Panel1->Width - FlowPanel1->Width)/2;
   TRect rect = AdvColumnGrid1->CellRect(AdvColumnGrid1->DisplColIndex(rc.Taph),0);
   CheckListEdit1->Left = rect.Left + 1;
   CheckListEdit1->Width = rect.Right - rect.Left + 1;
}
//---------------------------------------------------------------------------

void __fastcall TAllSpecimensForm::FormCreate(TObject *Sender)
{
   UnicodeString VarCode, Taxon, TaxaGroup;
   vector<UnicodeString> TaxaGroups;

   Setup();
   FillSexList();
   FillDomesticStatusList();

   int EndRow = TSSForm->AbsContentRowCount(TSSForm->ProfGrid1);
   int BeginRow = TSSForm->AbsHeaderRowCount(TSSForm->ProfGrid1);
   int EndCol = TSSForm->AbsContentColCount(TSSForm->ProfGrid1);
   int BeginCol = TSSForm->AbsHeaderColCount(TSSForm->ProfGrid1);

   // find begin and end rows for current dataset type
   int Row = TSSForm->ProfGrid1->Row;
   for (int row = Row; row >= BeginRow; row--) {
	 VarCode = TSSForm->ProfGrid1->AbsoluteCells[1][row]->Text;
	 if (SameText(VarCode,L"#Data.Type")) {
	   BeginRow = row + 1;
	   break;
	   }
	 }
   for (int row = Row; row <= EndRow; row++) {
	 VarCode = TSSForm->ProfGrid1->AbsoluteCells[1][row]->Text;
	 if (SameText(VarCode,L"#Data.Type")) {
	   EndRow = row - 1;
	   break;
	   }
	 }

   // populate grid with all specimens in the spreadsheet
   // set<UnicodeString> TaxaGroups;
   map<UnicodeString,UnicodeString> TaxonTaxaGroups;  // taxon name, TaxaGroup  e.g. Ursus, mammal
   int CurrentRow = 1;
   for (int col=8; col<=EndCol; col++) {
	 UnicodeString Depth = TSSForm->ProfGrid1->AbsoluteCells[col][1]->Text;
	 UnicodeString AnalUnit = TSSForm->ProfGrid1->AbsoluteCells[col][2]->Text;
	 for (int row=BeginRow; row<=EndRow; row++) {
	   UnicodeString Taxon = TSSForm->ProfGrid1->AbsoluteCells[2][row]->Text;
	   TProfGridCell* ACell = TSSForm->ProfGrid1->AbsoluteCells[col][row];
	   if (ACell->CellObject != NULL) {
		 CellObject = (CELLOBJECT*)ACell->CellObject;
		 if (CellObject->ObjectType == CELLSPECIMENS) {
		   TList* Specimens = (TList*)CellObject->Object;
		   for (int i=0; i<Specimens->Count; i++) {
			 SPECIMEN *Specimen = (SPECIMEN*)Specimens->Items[i];
			 AdvColumnGrid1->Objects[rc.SpecID][CurrentRow] = (TObject*)Specimen;
			 EnterSpecimen(Specimen, CurrentRow);
			 AdvColumnGrid1->Cells[rc.Dep][CurrentRow] = Depth;
			 AdvColumnGrid1->Cells[rc.Anal][CurrentRow] = AnalUnit;
			 AdvColumnGrid1->Cells[rc.Tax][CurrentRow] = Taxon;
			 CurrentRow++;
			 }
		   }
		 }
	   }                               // AdvColumnGrid1->DisplColIndex(rc.Taph)
	 }
   AdvColumnGrid1->RowCount = CurrentRow;

   // get all depths and analysis units
   for (int col=BeginCol; col<=EndCol; col++) {
	 UnicodeString Depth = TSSForm->ProfGrid1->AbsoluteCells[col][1]->Text;
	 UnicodeString AnalUnit = TSSForm->ProfGrid1->AbsoluteCells[col][2]->Text;
	 if (!Depth.IsEmpty())
	   AdvColumnGrid1->Columns->Items[rc.Dep]->ComboItems->Add(Depth);
	 if (!AnalUnit.IsEmpty())
	   AdvColumnGrid1->Columns->Items[rc.Dep]->ComboItems->Add(Depth);
	 AnalysisUnits.push_back(pair<UnicodeString,UnicodeString>(Depth,AnalUnit));
	 }

   // get all taxa
   for (int row=BeginRow; row<=EndRow; row++) {
	 Taxon = TSSForm->ProfGrid1->AbsoluteCells[2][row]->Text;
	 AdvColumnGrid1->Columns->Items[rc.Tax]->ComboItems->Add(Taxon);
	 }
   AdvColumnGrid1->Columns->Items[rc.Tax]->ComboItems->Sort();

   // get a map of all taxa and taxa groups
   map<UnicodeString,UnicodeString> EGTG;  // EcolGroupCode, TaxaGroupCode
   for (int row=BeginRow; row<=EndRow; row++) {
	 Taxon = TSSForm->ProfGrid1->AbsoluteCells[2][row]->Text;
	 if (TaxaTaxaGroups.count(Taxon) == 0) {
	   UnicodeString EcolGroupCode = TSSForm->ProfGrid1->AbsoluteCells[7][row]->Text;
	   if (EGTG.count(EcolGroupCode) != 0)
		 TaxaGroup = EGTG[EcolGroupCode];
	   else {
		 TaxaGroup = GetTaxaGroup(EcolGroupCode);
		 EGTG[EcolGroupCode] = TaxaGroup;
		 }
	   TaxaTaxaGroups[Taxon] = TaxaGroup.LowerCase();
	   }
	 }

   AdvColumnGrid1->Row = 1;
   Taxon = AdvColumnGrid1->AllCells[4][1];

   // populate the TaxaGroup selections
   if (TSSForm->VarLookup->ElementOpen()) {
	 TSSForm->ModifierType = MODELEMENT;
	 UnicodeString DatasetType = TSSForm->Datasets[TSSForm->DatasetNum].DatasetType.LowerCase();
	 TSSForm->ElementLookup->GetTaxaGroups(DatasetType, TaxaGroups);
	 for (unsigned int i=0; i<TaxaGroups.size(); i++)
	   cxComboBox1->Properties->Items->Add(TaxaGroups[i]);
	 if (TaxaGroups.size() > 0) {
	   if (!TaxaTaxaGroups[Taxon].IsEmpty()) {
		 CurrentTaxaGroup = TaxaTaxaGroups[Taxon];
		 cxComboBox1->ItemIndex = cxComboBox1->Properties->Items->IndexOf(CurrentTaxaGroup);
		 }
	   else {
		 cxComboBox1->ItemIndex = 0;
		 UnicodeString msg = L"Taxa group could not be set from Group code in Spreadsheet. ";
		 msg += L"Ensure that it is set correctly.";
		 MessageDlg(msg, mtWarning, TMsgDlgButtons() << mbOK, 0);
		 }
	   }
	 FillElementList();

	 for (unsigned int i=0; i<TaxaGroups.size(); i++) {
	   vector<UnicodeString> Elements;
	   TSSForm->ElementLookup->GetElements(DatasetType, TaxaGroups[i], Elements);
	   TaxaGroupElements[TaxaGroups[i]] = set<UnicodeString>(Elements.begin(),Elements.end());
	   }

     map<UnicodeString, map<UnicodeString, ELEMENTMODIFIERS> > AllModifiers;
	 TSSForm->ElementLookup->GetAllModifiers(AllModifiers);
	 set<UnicodeString>::iterator itr;
	 set<UnicodeString>::iterator begin;
	 set<UnicodeString>::iterator end;
	 for (unsigned int i=0; i<TaxaGroups.size(); i++) {
	   begin = AllModifiers[DatasetType][TaxaGroup].Symmetry.begin();
	   end = AllModifiers[DatasetType][TaxaGroup].Symmetry.end();
	   for (itr = begin; itr != end; itr++)
		 TaxaGroupSymmetries[TaxaGroup].insert(*itr);
	   }
	 for (unsigned int i=0; i<TaxaGroups.size(); i++) {
	   begin = AllModifiers[DatasetType][TaxaGroup].Portion.begin();
	   end = AllModifiers[DatasetType][TaxaGroup].Portion.end();
	   for (itr = begin; itr != end; itr++)
		 TaxaGroupPortions[TaxaGroup].insert(*itr);
	   }
	 for (unsigned int i=0; i<TaxaGroups.size(); i++) {
	   begin = AllModifiers[DatasetType][TaxaGroup].Maturity.begin();
	   end = AllModifiers[DatasetType][TaxaGroup].Maturity.end();
	   for (itr = begin; itr != end; itr++)
		 TaxaGroupMaturities[TaxaGroup].insert(*itr);
	   }
	 }
}
//---------------------------------------------------------------------------

void __fastcall TAllSpecimensForm::FormClose(TObject *Sender, TCloseAction &Action)
{
   tiGlobals->SpecWindHeight = Height;
   tiGlobals->SpecWindWidth = Width;
}
//---------------------------------------------------------------------------

// Ok button
void __fastcall TAllSpecimensForm::cxButton1Click(TObject *Sender)
{
  return;
}
//---------------------------------------------------------------------------

void __fastcall TAllSpecimensForm::AdvColumnGrid1RowChanging(TObject *Sender, int OldRow,
		  int NewRow, bool &Allow)
{
   UnicodeString Taxon = AdvColumnGrid1->AllCells[4][NewRow];
   if (TaxaTaxaGroups[Taxon] != CurrentTaxaGroup) {
	 if (!TaxaTaxaGroups[Taxon].IsEmpty()) {
	   CurrentTaxaGroup = TaxaTaxaGroups[Taxon];
	   cxComboBox1->ItemIndex = cxComboBox1->Properties->Items->IndexOf(CurrentTaxaGroup);
	   }
	 else {
	   UnicodeString msg = L"Taxa group for this taxon could not be set from Group code in Spreadsheet. ";
	   msg += L"Ensure that it is set correctly.";
	   MessageDlg(msg, mtWarning, TMsgDlgButtons() << mbOK, 0);
	   }
	 }
}
//---------------------------------------------------------------------------

bool TAllSpecimensForm::Validate(int ACol, int ARow, UnicodeString &Value, bool &Allow,
	SPECIMEN* Specimen)
{
   // ACol is the display column

   double dValue;

   if (ACol == AdvColumnGrid1->DisplColIndex(rc.Sex)) {
	 Value = Value.LowerCase();
	 if (AdvColumnGrid1->Columns->Items[rc.Sex]->ComboItems->IndexOf(Value) != -1) {
	   if (Specimen != NULL)
		 Specimen->Sex = Value;
	   }
	 else {
	   Beep();
	   Allow = false;
	   }
	 }
   else if (ACol == AdvColumnGrid1->DisplColIndex(rc.Dom)) {
	 Value = Value.LowerCase();
	 if (AdvColumnGrid1->Columns->Items[rc.Dom]->ComboItems->IndexOf(Value) != -1) {
	   if (Specimen != NULL)
		 Specimen->DomesticStatus = Value;
	   }
	 else {
	   Beep();
	   Allow = false;
	   }
	 }
   else if (ACol == AdvColumnGrid1->DisplColIndex(rc.NISP)) {
	 if (!TryStrToFloat(Value,dValue)) {
	   Beep();
	   Allow = false;
	   }
	 }

   return Allow;
}
//---------------------------------------------------------------------------

void __fastcall TAllSpecimensForm::AdvColumnGrid1CellValidate(TObject *Sender, int ACol,
		  int ARow, UnicodeString &Value, bool &Valid)
{
   UnicodeString msg;

   if (ACol == rc.Dep) {
     // TODO: change analysis unit if depth changes.
	 }
   else if (ACol == rc.Anal) {

	 }
   else if (ACol == rc.Elem) {
	 if (Value.IsEmpty()) {
	   if (AdvColumnGrid1->Objects[rc.SpecID][ARow] != NULL) {
		 SPECIMEN* Specimen = (SPECIMEN*)AdvColumnGrid1->Objects[rc.SpecID][ARow];
		 msg = L"Delete this specimen?";
		 if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes) {
		   if (TSSForm->HasGeochronLink(Specimen)) {
			 msg = L"Specimen is linked to dated taxon in Geochronology.\nCannot delete specimen.";
			 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			 Valid = false;
			 }
		   else {
			 delete Specimen;
			 AdvColumnGrid1->Objects[rc.SpecID][ARow] = NULL;
			 }
		   }
		 else
		   Valid = false;
		 }
	   }
	 }
   else
	 Validate(ACol, ARow, Value, Valid, NULL);
}
//---------------------------------------------------------------------------

void __fastcall TAllSpecimensForm::AdvColumnGrid1ClipboardBeforePasteCell(TObject *Sender,
          int ACol, int ARow, UnicodeString &Value, bool &Allow)
{
   // ACol is the display column
   UnicodeString Taxon, TaxaGroup;

   Value = Value.Trim();

   SPECIMEN *Specimen = (SPECIMEN*)AdvColumnGrid1->Objects[rc.SpecID][ARow];

   if (ACol == AdvColumnGrid1->DisplColIndex(rc.Elem)) {
	 if (Value.IsEmpty()) {
	   // this is because element cannot be empty.
	   Beep();
	   Allow = false;
	   }
	 else {
	   Value = Value.LowerCase();
	   Taxon = AdvColumnGrid1->AllCells[rc.Tax][ARow];
	   TaxaGroup = TaxaTaxaGroups[Taxon];
	   if (TaxaGroupElements[TaxaGroup].count(Value) != 0)
		 Specimen->Element = Value;
	   else {
		 Beep();
		 AdvColumnGrid1->Colors[ACol][ARow] = clHighlight;
		 Allow = false;
		 }
	   }
	 }
   else if (ACol == AdvColumnGrid1->DisplColIndex(rc.Sym)) {
	 Value = Value.LowerCase();
	 Taxon = AdvColumnGrid1->AllCells[rc.Tax][ARow];
	 TaxaGroup = TaxaTaxaGroups[Taxon];
	 if (TaxaGroupSymmetries[TaxaGroup].count(Value) != 0)
	   Specimen->Symmetry = Value;
	 else {
	   Beep();
	   AdvColumnGrid1->Colors[ACol][ARow] = clHighlight;
	   Allow = false;
	   }
	 }
   else if (ACol == AdvColumnGrid1->DisplColIndex(rc.Por)) {
	 Value = Value.LowerCase();
	 Taxon = AdvColumnGrid1->AllCells[rc.Tax][ARow];
	 TaxaGroup = TaxaTaxaGroups[Taxon];
	 if (TaxaGroupPortions[TaxaGroup].count(Value) != 0)
	   Specimen->Portion = Value;
	 else {
	   Beep();
	   AdvColumnGrid1->Colors[ACol][ARow] = clHighlight;
	   Allow = false;
	   }
	 }
   else if (ACol == AdvColumnGrid1->DisplColIndex(rc.Mat)) {
	 Value = Value.LowerCase();
	 Taxon = AdvColumnGrid1->AllCells[rc.Tax][ARow];
	 TaxaGroup = TaxaTaxaGroups[Taxon];
	 if (TaxaGroupMaturities[TaxaGroup].count(Value) != 0)
	   Specimen->Maturity = Value;
	 else {
	   Beep();
	   AdvColumnGrid1->Colors[ACol][ARow] = clHighlight;
	   Allow = false;
	   }
	 }

   else if (!Validate(ACol, ARow, Value, Allow, Specimen)) {
     AdvColumnGrid1->Colors[ACol][ARow] = clHighlight;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TAllSpecimensForm::AdvColumnGrid1ClipboardAfterPasteCell(TObject *Sender,
		  int ACol, int ARow, UnicodeString Value)
{
   // ACol is the display column

   // TODO: need to determine when to create a new specimen

   // SPECIMEN *Specimen = (SPECIMEN*)AdvColumnGrid1->Objects[rc.SpecID][ARow];



}
//---------------------------------------------------------------------------

void __fastcall TAllSpecimensForm::AdvColumnGrid1GetEditorProp(TObject *Sender, int ACol,
		  int ARow, TEditLink *AEditLink)
{
   if (ACol == rc.Rep)
	 InitRepositories();
   else if (ACol == rc.GenNr)
	 InitGenBank(ACol,ARow);
   else if (ACol == rc.Dep || ACol == rc.Anal)
	 InitAnalysisUnits(ACol);
}
//---------------------------------------------------------------------------

void TAllSpecimensForm::InitAnalysisUnits(int ACol)
{

   //AdvColumnGrid1->GridDropDown->Columns->Delete(0);
   //AdvColumnGrid1->GridDropDown->Columns->Delete(1);
   //AdvColumnGrid1->GridDropDown
   //ShowMessage(L"Number of columns = " + IntToStr(AdvColumnGrid1->GridDropDown->Columns->Count));
   //ShowMessage(L"Number of rows = " + IntToStr(AdvColumnGrid1->GridDropDown->Items->Count));
   //AdvColumnGrid1->GridDropDown->Columns->Clear();
   //ShowMessage(L"Number of columns = " + IntToStr(AdvColumnGrid1->GridDropDown->Columns->Count));

   int nrows = AdvColumnGrid1->AdvGridDropDown->Items->Count;
   for (int i = nrows-1; i > 0; i--) {
	 AdvColumnGrid1->AdvGridDropDown->Items->Delete(i);
   	 }

   AdvColumnGrid1->AdvGridDropDown->Columns->Clear();
   Advcustomgriddropdown::TDropDownColumn* dc;
   Advcustomgriddropdown::TDropDownItem* di;
   dc = AdvColumnGrid1->AdvGridDropDown->Columns->Add();
   dc->Header = L"Depth";
   dc->Width = AdvColumnGrid1->Columns->Items[rc.Dep]->Width;
   dc = AdvColumnGrid1->AdvGridDropDown->Columns->Add();
   dc->Header = L"Name";
   dc->Width  = AdvColumnGrid1->Columns->Items[rc.Anal]->Width;

   for (unsigned int i=0; i<AnalysisUnits.size(); i++) {
	 di = AdvColumnGrid1->AdvGridDropDown->Items->Add();
	 di->Text->Add(AnalysisUnits[i].first);
	 di->Text->Add(AnalysisUnits[i].second);
	 }

   AdvColumnGrid1->AdvGridDropDown->LookupColumn = (ACol == rc.Dep) ? 0 : 1;
   AdvColumnGrid1->AdvGridDropDown->DropDownRowHeight = 20;
   AdvColumnGrid1->AdvGridDropDown->DropDownAutoWidth = true;
   AdvColumnGrid1->AdvGridDropDown->ColumnSizing = true;


   /*
   Advmulticolumndropdown::TDropDownColumn* dc;
   Advmulticolumndropdown::TDropDownItem* di;
   //dc = AdvColumnGrid1->GridDropDown->Columns->Add();
   dc = AdvColumnGrid1->GridDropDown->Columns->Items[0];
   dc->Header = L"Depth";
   dc->Width = AdvColumnGrid1->Columns->Items[rc.Dep]->Width;
   //dc = AdvColumnGrid1->GridDropDown->Columns->Add();
   dc = AdvColumnGrid1->GridDropDown->Columns->Items[1];
   dc->Header = L"Name";
   dc->Width  = AdvColumnGrid1->Columns->Items[rc.Anal]->Width;

   for (unsigned int i=0; i<AnalysisUnits.size(); i++) {
	 di = AdvColumnGrid1->GridDropDown->Items->Add();
	 di->Text->Add(AnalysisUnits[i].first);
	 di->Text->Add(AnalysisUnits[i].second);
	 }

   AdvColumnGrid1->GridDropDown->LookupColumn = (ACol == rc.Dep) ? 0 : 1;
   AdvColumnGrid1->GridDropDown->DropDownRowHeight = 20;
   AdvColumnGrid1->GridDropDown->DropDownAutoWidth = true;
   AdvColumnGrid1->GridDropDown->ColumnSizing = true;
   */
}
//---------------------------------------------------------------------------

void __fastcall TSpecimenForm::ipsJSONS1SSLServerAuthentication(TObject *Sender, TipsJSONSSSLServerAuthenticationEventParams *e)
{
   e->Accept = true;
}
//---------------------------------------------------------------------------

