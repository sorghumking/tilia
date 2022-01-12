//---------------------------------------------------------------------------
#include <FileCtrl.hpp>
#define VCL_IOSTREAM
#include <vcl.h>
#include "pch.h"
#include "io.h"
#include <map>
#include <list>
#include <vector>
#include <iterator>
#include <algorithm>
#pragma hdrstop

#include <DateUtils.hpp>
#include <Math.hpp>
#include <SysUtils.hpp>

#include "TISpread.h"
#ifndef TIGlobalsH
#include "TIGlobals.h"
#endif
#ifndef TGH
#include "tg.h"
#endif
#ifndef TGTextH
#include "TGText.h"
#endif
#ifndef TGtgfioH
#include "Tgtgfio.h"
#endif
#ifndef TItlxioH
#include "TItlxout.h"
#endif
#ifndef TGUtilsH
#include "TGUtils.h"
#endif
#ifndef TIPublH
#include "TIPubl.h"
#endif
#ifndef TIMemoH
#include "TIMemo.h"
#endif
#ifndef TINewConH
#include "TINewCon.h"
#endif
#ifndef TIPubLnkH
#include "TIPubLnk.h"
#endif
#ifndef TIErrFrmH
#include "TIErrFrm.h"
#endif
#ifndef TIEdtElmH
#include "TIEdtElm.h"
#endif
#ifndef TITrainH
#include "TITrain.h"
#endif
#ifndef TISeEcGrH
#include "TISeEcGr.h"
#endif
#ifndef TIAgeBasH
#include "TIAgeBas.h"
#endif
#ifndef TICONShtH
#include "TICONSht.h"
#endif
#ifndef TIConcH
#include "TIConc.h"
#endif
#ifndef TIAddCalH
#include "TIAddCal.h"
#endif
#ifndef TISlpAspH
#include "TISlpAsp.h"
#endif
#ifndef TIUploadH
#include "TIUpload.h"
#endif
#ifndef TNTaxaH
#include "TNTaxa.h"
#endif
#ifndef TNVarModsH
#include "TNVarMods.h"
#endif
#ifndef TIUpContactH
#include "TIUpContact.h"
#endif
#ifndef TNLoginH
#include "TNLogin.h"
#endif
#ifndef TINeotomaH
#include "TINeotoma.h"
#endif
#ifndef TITphChkH
#include "TITphChk.h"
#endif
#ifndef TNLookupH
#include "TNLookup.h"
#endif
#ifndef TICalibH
#include "TICalib.h"
#endif
#ifndef TINwLkUpH
#include "TINwLkUp.h"
#endif
#ifndef TINtmWebH
#include "TINtmWeb.h"
#endif
#ifndef TIWhitSmpIDH
#include "TIWhitSmpID.h"
#endif
#ifndef TINtmSitFrmH
#include "TINtmSitFrm.h"
#endif
#ifndef TIWhitRemH
#include "TIWhitRem.h"
#endif
#ifndef TICounterH
#include "TICounter.h"
#endif

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxControls"
#pragma link "ipwCore"
#pragma link "ipwxmlp"
#pragma link "cxClasses"
#pragma link "cxCustomData"
#pragma link "cxData"
#pragma link "cxDataStorage"
#pragma link "cxEdit"
#pragma link "cxFilter"
#pragma link "cxGraphics"
#pragma link "cxGrid"
#pragma link "cxGridCardView"
#pragma link "cxGridCustomTableView"
#pragma link "cxGridCustomView"
#pragma link "cxGridLevel"
#pragma link "cxStyles"
#pragma link "cxGridTableView"
#pragma link "cxTextEdit"
#pragma link "cxBlobEdit"
#pragma link "cxMemo"
#pragma link "cxRichEdit"
#pragma link "cxDropDownEdit"
#pragma link "cxCheckComboBox"
#pragma link "cxContainer"
#pragma link "cxMaskEdit"
#pragma link "cxCheckListBox"
#pragma link "cxButtonEdit"
#pragma link "cxCheckBox"
#pragma link "cxCalendar"
#pragma link "cxPC"
#pragma link "ProfGrid"
#pragma link "cxTreeView"
#pragma link "cxLabel"
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxDBExtLookupComboBox"
#pragma link "cxSpinEdit"
#pragma link "cxLookAndFeels"
#pragma link "ipworks"
#pragma link "cxImage"
#pragma link "cxCalc"
#pragma link "AdvControlDropDown"
#pragma link "AdvDropDown"
#pragma link "cxGridCustomLayoutView"
#pragma link "dxCore"
#pragma link "dxdbtrel"
#pragma link "AdvMultiColumnDropDown"
#pragma link "AdvCustomGridDropDown"
#pragma link "AdvGridDropDown"
#pragma link "AdvGrid"
#pragma link "AdvObj"
#pragma link "BaseGrid"
#pragma link "AdvGrid"
#pragma link "AdvObj"
#pragma link "cxDateUtils"
#pragma link "cxNavigator"
#pragma link "AdvCGrid"
#pragma link "ipwhttp"
#pragma link "ipshttps"
#pragma link "ipwjson"
#pragma link "ipsjsons"
#pragma link "dxGDIPlusClasses"
#pragma link "cxGroupBox"
#pragma link "cxRadioGroup"
#pragma link "AdvCustomGridDropDown"
#pragma link "AdvGridDropDown"
#pragma link "cxPCdxBarPopupMenu"
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
#pragma link "dxSkinscxPCPainter"
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
#pragma link "AdvSprd"
#pragma link "dxBarBuiltInMenu"
#pragma link "dxBarBuiltInMenu"
#pragma link "dxSkinOffice2016Colorful"
#pragma link "dxSkinOffice2016Dark"
#pragma link "dxSkinVisualStudio2013Blue"
#pragma link "dxSkinVisualStudio2013Dark"
#pragma link "dxSkinVisualStudio2013Light"
#pragma link "htmlbtns"
#pragma link "frmctrllink"

#pragma link "AdvPanel"
#pragma link "AsgMemo"
#pragma link "AdvMemoDropDown"
#pragma link "AdvNavBar"
#pragma link "DBAdvGlowNavigator"
#pragma link "DBAdvNavigator"
#pragma link "cxNavigator"
#pragma resource "*.dfm"
TTilSpreadSheetForm *TilSpreadSheetForm;
//---------------------------------------------------------------------------

/*  This code is used to generate runtime menu items. They need to be deleted when finished.

	MenuItem = NewItem("Herbie", 0, false, true, Action1->OnExecute, 0, "Herbie1");
	MenuItem->GroupIndex = 1;
	MenuItem->RadioItem = true;
	Category1->Add(MenuItem);

	MenuItem = NewItem("Howie", 0, false, true, Action1->OnExecute, 0, "Howie1");
	MenuItem->GroupIndex = 1;
	MenuItem->RadioItem = true;
	Category1->Add(MenuItem);
*/
//---------------------------------------------------------------------------

UNDO::UNDO(short type, TProfGrid* grid, int ACol, int ARow)
{
   Type = type;
   ProfGrid = grid;
   Rect.Left = ACol;
   Rect.Right = ACol;
   Rect.Top = ARow;
   Rect.Bottom = ARow;
   TProfGridCell* ACell = ProfGrid->Cells[ACol][ARow];
   UNDOCELL Cell;
   Cell.Col = ACell->AbsoluteCol;
   Cell.Row = ACell->AbsoluteRow;
   Cell.Value = ACell->Value;
   Cell.Object = ACell->CellObject;
   Cell.CheckBox = false;
   Cells.push_back(Cell);
}
//---------------------------------------------------------------------------

// for CheckBoxes
UNDO::UNDO(short type, TProfGrid* grid, int ACol, int ARow, bool Checked)
{
   Type = type;
   ProfGrid = grid;
   Rect.Left = ACol;
   Rect.Right = ACol;
   Rect.Top = ARow;
   Rect.Bottom = ARow;
   TProfGridCell* ACell = ProfGrid->Cells[ACol][ARow];
   UNDOCELL Cell;
   Cell.Col = ACell->AbsoluteCol;
   Cell.Row = ACell->AbsoluteRow;
   Cell.CheckBox = true;
   Cell.Value = Checked;
   Cell.Object = ACell->CellObject;
   Cells.push_back(Cell);
}
//---------------------------------------------------------------------------

UNDO::UNDO(short type, TProfGrid* grid)
{
   Type = type;
   ProfGrid = grid;
   Rect.Left = ProfGrid->Selection->Rect.Left;
   Rect.Right = ProfGrid->Selection->Rect.Right;
   Rect.Top = ProfGrid->Selection->Rect.Top;
   Rect.Bottom = ProfGrid->Selection->Rect.Bottom;
}
//---------------------------------------------------------------------------

void UNDOSELECTION::operator = (const UNDOSELECTION& copy)
{
   if (this == &copy) return;
   Left = copy.Left;
   Right = copy.Right;
   Top = copy.Top;
   Bottom = copy.Bottom;
   ProfGrid = copy.ProfGrid;
}
//---------------------------------------------------------------------------

bool UNDOSELECTION::operator != (const UNDOSELECTION& compare )
{
   // return true if any of the variables are not equal
   if (this == &compare) return false;

   if (ProfGrid != compare.ProfGrid) return true;
   if (Left != compare.Left) return true;
   if (Right != compare.Right) return true;
   if (Top != compare.Top) return true;
   if (Bottom != compare.Bottom) return true;

   return false;
}
//---------------------------------------------------------------------------

void AGEBASIS::SetAges(TcxTreeView* cxTreeView)
{
   if (cxTreeView && cxTreeView->Selected->Data) {
     UnicodeString clName = ((TObject*)cxTreeView->Selected->Data)->ClassName();
	 if (SameText(clName, L"RELATIVEAGE")) {
	   RELATIVEAGE* RelAge = (RELATIVEAGE*)cxTreeView->Selected->Data;
	   C14Age = NaN;
	   C14AgeYounger = RelAge->C14AgeYounger;
	   C14AgeOlder = RelAge->C14AgeOlder;
	   CalAge = NaN;
	   CalAgeYounger = RelAge->CalAgeYounger;
	   CalAgeOlder = RelAge->CalAgeOlder;
	   // ShowMessage(L"SetAges: " + FloatToStr(CalAgeYounger));
       }
     else if(SameText(clName, L"EVENT")){
       EVENT* Event = (EVENT*)cxTreeView->Selected->Data;
       C14Age = Event->C14Age;
       C14AgeYounger = Event->C14AgeYounger;
       C14AgeOlder = Event->C14AgeOlder;
       CalAge = Event->CalAge;
       CalAgeYounger = Event->CalAgeYounger;
       CalAgeOlder = Event->CalAgeOlder;
       }
     AgesSet = true;
     }
   else {
     C14Age = NaN;
     C14AgeYounger = NaN;
     C14AgeOlder = NaN;
	 CalAge = NaN;
     CalAgeYounger = NaN;
     CalAgeOlder = NaN;
     AgesSet = false;
     }
}
//---------------------------------------------------------------------------

PUBLETTERS::PUBLETTERS()
{
  letters = "abcdefghijklmnopqrstuvwxyz";
  idx = 0;
}
//---------------------------------------------------------------------------

UnicodeString __fastcall PUBLETTERS::NextLetter(void)
{
  idx = (idx == 26) ? 1 : idx+1;
  return letters.SubString(idx,1);
}
//---------------------------------------------------------------------------

SSUM::SSUM(UnicodeString& code, int row)
{
  Sums = new TStringList;
  Code = code;
  Row = row;
}
//---------------------------------------------------------------------------

SSUM::~SSUM()
{
  delete Sums;
}
//---------------------------------------------------------------------------

__fastcall TTilSpreadSheetForm::TTilSpreadSheetForm(TComponent* Owner)
		: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::FormCreate(TObject *Sender)
{
   //tiGlobals->SetDefaultLookupPath();

   //UnicodeString LookupPath = tiGlobals->AppDataTiliaLookupPath;

   bool CreateDefaultLookupFiles = false;
   bool LookupDirectoryExists = true;
   if (!DirectoryExists(tiGlobals->AppDataTiliaLookupPath)) {
	 LookupDirectoryExists = false;
	 if (!CreateLookupDirectory(tiGlobals->AppDataTiliaLookupPath, CreateDefaultLookupFiles)) {
	   Screen->Cursor = crDefault;
	   UnicodeString msg = L"Cannot create directory " + tiGlobals->AppDataTiliaLookupPath;
	   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   FatalError = 1;
	   return;
	   }
	 }

   if (!LookupFileExists(tiGlobals->AppDataTiliaLookupPath, CreateDefaultLookupFiles)) {
	 FatalError = 1;
	 return;
	 }
   if (!GeopoliticalLookupFileExists(tiGlobals->AppDataTiliaLookupPath, CreateDefaultLookupFiles)) {
	 FatalError = 1;
	 return;
	 }
   if (!LookupDirectoryExists) {
	 if (!VariableModifiersLookupFileExists(tiGlobals->AppDataTiliaLookupPath, CreateDefaultLookupFiles)) {
	   FatalError = 1;
	   return;
	   }
     UnicodeString msg = L"Tilia lookup files created:";
	 msg += L"\n  Lookup.xml";
	 msg += L"\n  GeoPoliticalUnits.xml";
	 msg += L"\n  NeotomaVariableModifiers";
	 msg += L"\n\nYou will probably also want to create a taxa lookup file.";
	 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
	 }

   if (tiLicense->Type() != verNEOTOMASTEWARD) {
	 Steward1->Visible = false;
	 Login1->Visible = false;
	 WebServices1->Visible = false;
	 }
   else if (Login->IsLoggedIn)
	 Login1->Caption = L"&Logout";

   if (tiLicense->Type() == verFREE) {
	 SS_Diagram->Visible = false;
     }

   Sites = new TList;
   SITE* site = new SITE();
   Sites->Add(site);
   ValidatedSites = NULL;

   ShowTaxonNotes = false;
   HeaderRow2 = ANAL_UNIT_NAME;
   Row2HintStr = L"Analysis Unit name.";
   HeaderNameEntered = false;
   FatalError = 0;
   PasteError = NO_PASTE_ERROR;
   StartUp = true;
   CheckBoxUndoEnabled = true;
   SAX.CurrentGroup = -1;
   SAX.CurrentElement = -1;
   DMSStyle = DEG;
   XMLLookUpError = false;
   ClientHeight = (int)(0.7*(double)ParentForm->ClientHeight);
   ClientWidth = (int)(0.8*(double)ParentForm->ClientWidth);
   ssc.col = -1;
   ssc.row = -1;
   SpreadSheetChanged = false;
   TaxaLookupOpen = false;
   GeochronTaxaOpen = false;
   GroupLookup = false;
   //VarLookup = new VARIABLELOOKUP;
   NewTaphonomicClasses = false;
   CurrentTaphSystem = L"none";
   MetadataPaste = false;
   MoreElements = false;
   SampModernRow = -1;

   LabeledEdit4->Left = 16;
   cxComboBox1->Left = 120;
   Label12->Left = 120;
   cxComboBox1->Width = 161;
   cxComboBox13->Left = 16;
   Label21->Left = 16;

   if (ParentForm->MDIChildCount == 1) {
     Left = 0;
     Top = 0;
	 }
   else {
     Left = 22 + ParentForm->CurrentChildPos.x;
     Top = 22 + ParentForm->CurrentChildPos.y;
     }

   NewAgeModels = false;
   WholeSheetSelected = false;
   ActiveCellChanging = false;
   TopLeftChanging = false;
   Scrolling = true;
   ResetCol = false;
   ResetRow = false;
   Resizing = false;
   EndKey = false;

   AllowRowColSelection = true;
   ColBlk = false;
   RowBlk = false;
   SheetBlk = false;

   //GenerateGeochronColumns();  //doesn't work here in XE; works where it is down below

   // get lookup items for comboboxes
   // RelativeAges keeps track of pointers that go into cxTreeView1 and eventually
   // need to be deleted
   RelativeAges = new TList;
   // these next two lists are for archaeogical time scales, which are not expanded
   // into cxTreeView1 unless the user requests them to be.
   ArchAges = new TStringList;
   ArchAgeScales = new TStringList;
   Events = new TList;
   Screen->Cursor = crHourGlass;

   XMLParsingStatus("Parsing Lookup.xml");
   if (!GetLookupItems()) {
	 DeleteRelativeAges();
	 ArchAges->Clear();
	 delete ArchAges;
	 ArchAgeScales->Clear();
	 delete ArchAgeScales;
	 DeleteEvents();
	 cxTreeView1->Items->Clear();
	 FatalError = 1;
	 Screen->Cursor = crDefault;
	 return;
	 }

   XMLParsingStatus("Parsing GeoPoliticalUnits.xml");
   AdminUnitTypes = new TStringList;
   AdminUnitTypes->Sorted = true;
   GeoPolUnits = new GEOPOLITICAL();
   if (OpenCountriesXML()) {
	 GeoPolUnits->GeoPol1(cxComboBox7->Properties->Items);
	 }

   // replaced new statements
   VarLookup = new VARIABLELOOKUP;
   GeochronVarLookup = new VARIABLELOOKUP;
   DatasetNum = 0;
   DATASET dataset;
   dataset.DatasetType = tiGlobals->DatasetType;
   Datasets.push_back(dataset);  // default dataset
   Sums = new TList;
   SSums = new TList;
   ContactList = new TContactList();
   LithologyUnitList = new TLithologyUnitList();
   GeochronList = new TGeochronList(this);
   AgeModelList = new TAgeModelList(GeochronList);
   Publications = new TList;

   // TODO: The *DataSource and Generate*Columns functions all need to be in FormCreate
   //       in all other modules. -- maybe not in XE
   ContactDataSource = new TContactDataSource(ContactList);
   GenerateContactColumns();
   LithologyUnitDataSource = new TLithologyUnitDataSource(LithologyUnitList);
   GenerateLithologyUnitColumns();
   GeochronDataSource = new TGeochronDataSource(GeochronList);
   TaxonDatedDataSource = new TTaxonDatedDataSource(GeochronDataSource);
   GenerateGeochronColumns();
   AgeModelDataSource = new TAgeModelDataSource(AgeModelList);
   ChronDataSource = new TChronDataSource(AgeModelDataSource);
   GenerateAgeModelColumns();

   AdvColumnGrid4->Width = Panel1->Width - 48;
   AdvColumnGrid4->Height = max(42, Panel1->Height - 100);

   for (int row=1; row<AdvColumnGrid5->RowCount; row++)
	 AdvColumnGrid5->Cells[0][row] = row;

   ProcessComboBox7OnExit = false;
   ProcessComboBox8OnExit = false;
   ComboBox7Clicked = false;
   ComboBox8Clicked = false;

   PageControl2->ActivePage = TabSheetSite;
   PageControl1->ActivePage = TabSheet1;

   Workbook = new WORKBOOK;
   Workbook->Sheets[cxTabSheet1] = ProfGrid1;
   cxPageControl1->ActivePage = cxTabSheet1;

   cxComboBox2->Style->Color = (TColor)0x00EACAB6;

   EditAgeBasisList = -1;
   AgeBasisListChanged = false;
   DepEnvListChanged = false;
   cxAgeBasisTreeView = new TcxTreeView(this);
   TabSheetAgeModels->InsertControl(cxAgeBasisTreeView);
   cxAgeBasisTreeView->Visible = false;
   cxAgeBasisTreeView->Items->Assign(cxTreeView1->Items);

   CurrentChronControlView = NULL;
   ProfGrid2 = NULL;
   ConcGrid = NULL;
   InfluxGrid = NULL;
   PrevSubstrateNode = NULL;
   SubstrateDescriptions = NULL;
   ElementLookup = NULL;
   UnitLookup = NULL;
   ContextLookup = NULL;
   TaphonomyLookup = NULL;
   GeochronElementLookup = NULL;
   TempTaphSystems = NULL;

   Application->OnHint = DisplayHint;
   AdvColumnGrid2->Height = 200;
   AdvColumnGrid6->Height = 200;
   Screen->Cursor = crDefault;

   // store initial properites for controls also used for spreadsheet metadata
   CONTROLPROPERTIES CP;
   SetInitControlProperties(CP, dxTreeViewEdit1->Left, dxTreeViewEdit1->Top, dxTreeViewEdit1->Width);
   InitialControlProperties[dxTreeViewEdit1] = CP;
   SetInitControlProperties(CP, dxTreeViewEdit2->Left, dxTreeViewEdit2->Top, dxTreeViewEdit2->Width);
   InitialControlProperties[dxTreeViewEdit2] = CP;
   SetInitControlProperties(CP, cxPopupEdit13->Left, cxPopupEdit13->Top, cxPopupEdit13->Width);
   InitialControlProperties[cxPopupEdit13] = CP;
   SetInitControlProperties(CP, cxPopupEdit14->Left, cxPopupEdit14->Top, cxPopupEdit14->Width);
   InitialControlProperties[cxPopupEdit14] = CP;

   ipwXMLp1->Config("CodePage=65001");   // UTF-8 CodePage
   ipwXMLp2->Config("CodePage=65001");
   ipwXMLp5->Config("CodePage=65001");
   ipwXMLp6->Config("CodePage=65001");

   //ipwXMLp1->Config("CodePage=0");   // Lookup, Elements, Units, Contexts, Taphonomy: DOM
   //ipwXMLp2->Config("CodePage=0");   // tlx file: SAX
   //ipwXMLp5->Config("CodePage=0");   // GeoPoliticalUnits.xml: SAX
   //ipwXMLp6->Config("CodePage=0");   // Taxa lookup: SAX

   // populate the isotope grid
   // AdvIsotopeGrid
   SetupIsotopeGrid();
   IsoGridShiftClickSelection = false;
   IsoRowSelected = false;
   IsoMultiRowsSelected = false;

   Downloaded = false;
   DownloadPaste.Pasting = false;
   DownloadPaste.Error = false;
   DownloadPaste.Row = -1;

   RepHoverButtons = new THoverButtonsCollection(AdvColumnGrid2);
   SpecHoverButtons = new THoverButtonsCollection(AdvColumnGrid2);
   RepHoverButtons->Assign(AdvColumnGrid2->HoverButtons->Buttons);
   SpecHoverButtons->Assign(AdvColumnGrid2->HoverButtons->Buttons);
   SpecHoverButtons->Delete(2);
   SpecHoverButtons->Delete(1);

   EPD.SiteID = -1;
   EPD.CollectionUnitID = -1;

   InitChronControl = NULL;

   Panel15->Height = 165;
   Panel19->Height = 165;

#ifdef WHITMORE
   Whitmore1->Visible = true;
#endif
}
//---------------------------------------------------------------------------

bool TTilSpreadSheetForm::CreateLookupDirectory(UnicodeString LookupPath, bool& CreateDefaultLookupFiles)
{
   UnicodeString msg = L"Lookup directory " + LookupPath + L" does not exist. Create directory?";
   if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) != mrYes)
	 return false;

   // need to create subdirectories one at a time

   UnicodeString Path = tiGlobals->AppDataTiliaLookupPath;
   if (Path.IsEmpty())
	 return false;

   UnicodeString Dir = Path.SubString(1,Path.Length()-1);
   if (!DirectoryExists(Dir)) {
	 if (!CreateDir(Dir))
	   return false;
	 }

   // create lookup files
   msg = L"Lookup directory " + Path + L" successfully created.";
   msg += L"\nCreate lookup files? You must have an Internet connection.";
   if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes)
	 CreateDefaultLookupFiles = true;

   return true;
}
//---------------------------------------------------------------------------

bool TTilSpreadSheetForm::LookupFileExists(UnicodeString LookupPath, bool CreateDefaultLookupFiles)
{
   bool success = true;
   UnicodeString Path = LookupPath + L"Lookup.xml";
   if (!FileExists(Path)) {
	 if (!CreateDefaultLookupFiles) {
	   UnicodeString msg = L"Tilia lookup file Lookup.xml does not exist.";
	   msg += L"\nCreate lookup file? You must have an Internet connection.";
	   if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) != mrYes)
		 return false;
	   }
	 Screen->Cursor = crHourGlass;
	 NeotomaWriteLookupForm = new TNeotomaWriteLookupForm(LTLOOKUP, this);
	 NeotomaWriteLookupForm->ShowModal();
	 success = NeotomaWriteLookupForm->LookupCreated;
	 delete NeotomaWriteLookupForm;
	 Screen->Cursor = crDefault;
	 }
   return success;
}
//---------------------------------------------------------------------------

bool TTilSpreadSheetForm::GeopoliticalLookupFileExists(UnicodeString LookupPath, bool CreateDefaultLookupFiles)
{
   bool success = true;
   UnicodeString Path = LookupPath + L"GeoPoliticalUnits.xml";
   if (!FileExists(Path)) {
	 if (!CreateDefaultLookupFiles) {
	   UnicodeString msg = L"Tilia lookup file GeoPoliticalUnits.xml does not exist.";
	   msg += L"\nCreate lookup file? You must have an Internet connection.";
	   if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) != mrYes)
		 return false;
	   }
	 Screen->Cursor = crHourGlass;
	 NeotomaWriteLookupForm = new TNeotomaWriteLookupForm(LTGEOPOLITICAL, this);
	 NeotomaWriteLookupForm->ShowModal();
	 success = NeotomaWriteLookupForm->LookupCreated;
	 delete NeotomaWriteLookupForm;
	 Screen->Cursor = crDefault;
	 }
   return success;
}
//---------------------------------------------------------------------------

bool TTilSpreadSheetForm::VariableModifiersLookupFileExists(UnicodeString LookupPath, bool CreateDefaultLookupFiles)
{
   bool success = true;
   UnicodeString Path = LookupPath + L"NeotomaVariableModifiers.xml";
   if (!FileExists(Path)) {
	 if (!CreateDefaultLookupFiles) {
	   UnicodeString msg = L"Tilia lookup file NeotomaVariableModifiers.xml does not exist.";
	   msg += L"\nCreate lookup file? You must have an Internet connection.";
	   if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) != mrYes)
		 return false;
	   }
	 Screen->Cursor = crHourGlass;
	 NeotomaWriteLookupForm = new TNeotomaWriteLookupForm(LTVARMODS, this);
	 NeotomaWriteLookupForm->ShowModal();
	 success = NeotomaWriteLookupForm->LookupCreated;
	 delete NeotomaWriteLookupForm;
	 Screen->Cursor = crDefault;
	 }
   return success;
}
//---------------------------------------------------------------------------

TipwXMLp* TTilSpreadSheetForm::GetXMLFilePtr(void)
{
   //ipwXMLp1->Config("CodePage=65001");
   return ipwXMLp1;
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::FormatWorksheet(TProfGrid* ProfGrid)
{
   if (xml_Version > VERSION(0,0,0) && xml_Version < VERSION(1,1,6)) {
     if (tlxRow2 && tlxRow3) {
       int ColCount = AbsContentColCount(ProfGrid);
       for (int i=8; i<=ColCount; i++) {
		 Variant Value = ProfGrid->AbsoluteCells[i][2]->Value;
         ProfGrid->AbsoluteCells[i][2]->Value = ProfGrid->AbsoluteCells[i][3]->Value;
         ProfGrid->AbsoluteCells[i][3]->Value = Value;
         }
       ProfGrid->AbsoluteCells[1][3]->Value = WideString("#SampleName");
       ProfGrid->AbsoluteCells[2][3]->Value = WideString("Sample Name");
	   }
	 else if (tlxRow2 && !tlxRow3)
	   ProfGrid->DeleteRow(3);
	 else if (!tlxRow2 && tlxRow3) {
       int ColCount = AbsContentColCount(ProfGrid);
       for (int i=8; i<=ColCount; i++)
         ProfGrid->AbsoluteCells[i][2]->Value = ProfGrid->AbsoluteCells[i][3]->Value;
       ProfGrid->DeleteRow(3);
       }
     else
       ProfGrid->DeleteRow(3);
     }

   // all cells are now split
   ProfGrid->AbsoluteCells[1][1]->Color = (TColor)0x00EACAB6;
   ProfGrid->AbsoluteCells[2][1]->Color = (TColor)0x00EACAB6;
   ProfGrid->AbsoluteCells[1][1]->Font->Color = clNavy;
   ProfGrid->AbsoluteCells[2][1]->Font->Color = clNavy;
   for (int i=3; i<=7; i++) {
     ProfGrid->AbsoluteCells[i][1]->ReadOnly = true;
     ProfGrid->AbsoluteCells[i][1]->Color = (TColor)0x00EACAB6;
     ProfGrid->AbsoluteCells[i][1]->Font->Color = clNavy;
     }
   for (int i=1; i<=7; i++) {
	 ProfGrid->AbsoluteCells[i][2]->HorizontalAlignment = Profgrid::haCenter;
     ProfGrid->AbsoluteCells[i][2]->ReadOnly = true;
     ProfGrid->AbsoluteCells[i][2]->Color = (TColor)0x00EACAB6;
     ProfGrid->AbsoluteCells[i][2]->Font->Color = clNavy;
	 }

   if (ProfGrid != ProfGrid1) {
     ProfGrid->AbsoluteCells[1][1]->ReadOnly = true;
     ProfGrid->AbsoluteCells[2][1]->ReadOnly = true;
     }

   ProfGrid->Font->Name = tiGlobals->SSFontName;
   ProfGrid->Font->Size = tiGlobals->SSFontSize;

   if (ProfGrid->DefaultColWidth != tiGlobals->SSDefaultColWidth) {
     int OldDefaultColWidth = ProfGrid->DefaultColWidth;
     vector<int> OldColWidths;
	 for (int j=0; j<ProfGrid->AbsoluteColCount; j++)
       OldColWidths.push_back(ProfGrid->AbsoluteCols[j]->Width);
     ProfGrid->DefaultColWidth = tiGlobals->SSDefaultColWidth;
     for (int j=0; j<ProfGrid->AbsoluteColCount; j++)
       if (OldColWidths[j] != OldDefaultColWidth)
         ProfGrid->AbsoluteCols[j]->Width = OldColWidths[j];
     }

   if (ProfGrid->DefaultRowHeight != tiGlobals->SSDefaultRowHeight)
	 ProfGrid->DefaultRowHeight = tiGlobals->SSDefaultRowHeight;

   ProfGrid->AbsoluteCols[2]->Width = 180;

   TGridRect MergeRect;
   if (tiGlobals->SSHideCodes) {  // col 1 visible
	 LabelSSColumns(ProfGrid, 2);
     ProfGrid->MergeHoriz(1,2,1);
     ProfGrid->MergeHoriz(3,7,1);
     }
   else {  // col 1 not visible
     LabelSSColumns(ProfGrid, 2);
	 ProfGrid->MergeHoriz(3,7,1);
     }

   ProfGrid->AbsoluteCols[1]->Visible = tiGlobals->SSHideCodes;
   ProfGrid->AbsoluteCols[3]->Visible = tiGlobals->SSHideElements;
   ProfGrid->AbsoluteCols[4]->Visible = tiGlobals->SSHideUnits;
   ProfGrid->AbsoluteCols[5]->Visible = tiGlobals->SSHideContext;
   ProfGrid->AbsoluteCols[6]->Visible = tiGlobals->SSHideTaphonomy;
   ProfGrid->AbsoluteCols[7]->Visible = tiGlobals->SSHideGroups;

   ProfGrid->Cells[1][1]->Value = Datasets[0].DatasetType;
   ProfGrid->FocusCell(1,3);
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::LabelSSColumns(TProfGrid* ProfGrid, int row)
{
   ProfGrid->AbsoluteCells[1][row]->Value = "Code";
   ProfGrid->AbsoluteCells[2][row]->Value = "Name";
   ProfGrid->AbsoluteCells[3][row]->Value = "Element";
   ProfGrid->AbsoluteCells[4][row]->Value = "Units";
   ProfGrid->AbsoluteCells[5][row]->Value = "Context";
   ProfGrid->AbsoluteCells[6][row]->Value = "Taphonomy";
   ProfGrid->AbsoluteCells[7][row]->Value = "Group";
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::FormActivate(TObject *Sender)
{
   if (FatalError) return;
   PageControl1->Visible = true;

   vector<TToolBar*> ToolBars;
   ToolBars.push_back(ParentForm->ToolBarFile);
   ToolBars.push_back(ParentForm->ToolBarHelp);
   ToolBars.push_back(ParentForm->ToolBarSpreadSheet);
   ToolBars.push_back(ParentForm->ToolBarNeotoma);
   ParentForm->SetToolBars(ToolBars);

   ParentForm->ActivateSpreadsheetMenu(true, PageControl1, cxPageControl1, PageControl2);

   ParentForm->StatusBar1->Panels->Items[0]->Text =
      MinimizeName(TilFileName, ParentForm->StatusBar1->Canvas,
        ParentForm->StatusBar1->Panels->Items[0]->Width);
   Caption = TilFileName;

   Modified = false;

   // only need to do this for initial activation
   if (StartUp) {
	 int row = (ProfGrid1->AbsoluteRows[2]->Visible && ProfGrid1->AbsoluteRows[3]->Visible) ? 4 : 3;
     FocusControl(ProfGrid1);
     ProfGrid1->FocusCell(1,row);
	 StartUp = false;
     }

   // remove the graph edit toolbar from previously active diagram form
  ParentForm->RemoveTGEditToolBar(this);
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::FormDeactivate(TObject *Sender)
{
   ParentForm->ActivateSpreadsheetMenu(false, PageControl1, cxPageControl1, PageControl2);
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::FormClose(TObject *Sender,
	  TCloseAction &Action)
{
   if (SpreadSheetChanged) {
	 if (MessageDlg("Do you want to save changes?",
		 mtWarning, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes)
		   Save();
	 }

   list<CELLOBJECT*>::iterator itr;
   for (itr=CellObjects.begin(); itr != CellObjects.end(); itr++ )
	 delete *itr;
   ClearCutObjects();

   for (int i=0; i<Sites->Count; i++) {
	 SITE *site = (SITE*)Sites->Items[i];
	 delete site;
	 Sites->Items[i] = 0;
	 }
   Sites->Clear();
   delete Sites;

   if (ValidatedSites != NULL) {
	 for (int i=0; i<ValidatedSites->Count; i++) {
	   SITE *site = (SITE*)ValidatedSites->Items[i];
	   delete site;
	   ValidatedSites->Items[i] = 0;
	   }
	 ValidatedSites->Clear();
	 delete ValidatedSites;
	 }

   delete ContactList;
   delete ContactDataSource;
   delete LithologyUnitList;
   delete LithologyUnitDataSource;
   delete GeochronList;
   delete GeochronDataSource;
   delete TaxonDatedDataSource;
   delete AgeModelList;
   delete AgeModelDataSource;
   delete ChronDataSource;

   Action = caFree;

   DeleteList(Sums);
   DeleteList(SSums);
   for (int i=0; i<Publications->Count; i++) {
	 PUBLICATION *pub = (PUBLICATION*)Publications->Items[i];
     delete pub;
     Publications->Items[i] = 0;
     }
   Publications->Clear();
   delete Publications;

   if (ParentForm->MDIChildCount == 1) {
	 ParentForm->ActivateSpreadsheetMenu(false, PageControl1, cxPageControl1, PageControl2);
	 vector<TToolBar*> ToolBars;
	 ToolBars.push_back(ParentForm->ToolBarFile);
	 ToolBars.push_back(ParentForm->ToolBarHelp);
	 ToolBars.push_back(ParentForm->ToolBarNeotoma);
	 ParentForm->SetToolBars(ToolBars);
	 }

   ParentForm->StatusBar1->Panels->Items[0]->Text = "";
   ParentForm->StatusBar1->Panels->Items[1]->Text = "";
   ParentForm->StatusBar1->Panels->Items[2]->Text = "";

   tiGlobals->DatasetType = Datasets[0].DatasetType;
   //delete DataTypes;
   delete Workbook;

   //delete FaciesTypes;
   //delete DepAgents;

   if (ElementLookup)
   	 delete ElementLookup;
   if (UnitLookup)
	 delete UnitLookup;
   if (ContextLookup)
	 delete ContextLookup;
   if (TaphonomyLookup)
	 delete TaphonomyLookup;

   delete VarLookup;
   delete GeochronVarLookup;

   if (GeochronElementLookup)
	delete GeochronElementLookup;

   delete GeoPolUnits;
   AdminUnitTypes->Clear();
   delete AdminUnitTypes;

   DeleteRelativeAges();

   ArchAges->Clear();
   delete ArchAges;
   ArchAgeScales->Clear();
   delete ArchAgeScales;

   if (SubstrateDescriptions) {
	 SubstrateDescriptions->Clear();
	 delete SubstrateDescriptions;
	 }

   DeleteEvents();

   cxTreeView1->Items->Clear();

   TabSheetAgeModels->RemoveControl(cxAgeBasisTreeView);
   //cxAgeBasisTreeView->Items->Clear();
   delete cxAgeBasisTreeView;

   for (int i=0; i<mdLakeCharacteristics1->Count; i++) {
     TMenuItem* MenuItem = mdLakeCharacteristics1->Items[i];
     delete MenuItem;
	 }

   if (IsotopeSeries.size() > 0) {
	 for (unsigned int i=0; i<IsotopeSeries.size(); i++)
	   delete IsotopeSeries[i];
	 }

   RepHoverButtons->Clear();
   delete RepHoverButtons;
   SpecHoverButtons->Clear();
   delete SpecHoverButtons;

   if (InitChronControl != NULL)
	 delete InitChronControl;
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::ClearCutObjects(void)
{
   list<CELLOBJECT*>::iterator itr;
   for (itr=CutObjects.begin(); itr != CutObjects.end(); itr++) {
	 if (*itr != NULL)
	   delete *itr;
	 }
   CutObjects.clear();
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::DeleteRelativeAges(void)
{
   for (int i=0; i<RelativeAges->Count; i++) {
	 RELATIVEAGE* Item = (RELATIVEAGE*)RelativeAges->Items[i];
	 delete Item;
     RelativeAges->Items[i] = 0;
     }
   RelativeAges->Clear();
   delete RelativeAges;
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::DeleteEvents(void)
{
   for (int i=0; i<Events->Count; i++) {
	 EVENT* Item = (EVENT*)Events->Items[i];
	 delete Item;
	 Events->Items[i] = 0;
     }
   Events->Clear();
   delete Events;
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::DeleteChronControls(void)
{
   //for (int i=0; i<ChronControls->Count; i++) {
   //  CHRONCONTROL* ChronControl = (CHRONCONTROL*)ChronControls->Objects[i];
   //  delete ChronControl;
   //  }
   //delete ChronControls;
}
//---------------------------------------------------------------------------

bool TTilSpreadSheetForm::LoadData(UnicodeString& FileName)
{
   bool ReturnValue = true;

   xml_Version.SetVersion(0,0,0);
   UnicodeString FileExt = ExtractFileExt(FileName);
   if (SameText(FileExt, L".til")) {
	 Screen->Cursor = crHourGlass;
     ReadTIL *r = new ReadTIL(FileName, this);   // read .til file
     try
       {
       try
         {
         r->ReadTiliaFile();
		 FormatWorksheet(ProfGrid1);
		 if (!XMLLookUpError) {
		   SITE* site_ptr = (SITE*)Sites->Items[0];
		   if (r->ReadSITForm(site_ptr, site_ptr->CollUnits[0], &Datasets[0], ContactList))
			 ParseSITFormData();
		   r->ReadPUBForm(Publications);
		   FillPubGrid();
		   r->ReadPB2Form(GeochronList);
           r->ReadC14Form(GeochronList);
           r->ReadAGEForm(AgeModelList, ContactList);
           r->ReadSMPForm(ContactList);
           r->ReadLTHForm(LithologyUnitList);
           r->ReadLOIForm();
		   for (int i=0; i<ContactList->Count; i++) {
			 CONTACT *contact = ContactList->Contacts[i];
			 if (SameText(contact->FamilyName, L"COHMAP")) {
               contact->FamilyName = "Cooperative Holocene Mapping Project";
			   contact->FormatContactName();
               }
             }
		   ProfGrid1->FocusCell(1,3);
           }
         TilFileName = FileName;
		 tiGlobals->OpenFileExt = TIL;
		 }
	   catch(Exception &e) {
		 MessageDlg(e.Message, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 ReturnValue = false;
		 }
	   }
     __finally
	   {
	   delete r;
	   Screen->Cursor = crDefault;
       }
     }
   else if (SameText(FileExt, L".tlx")) {
     if (!XMLLookUpError) {
       CheckBoxUndoEnabled = false;
       XMLParsingStatus("Building DOM");
       ssc.col = -1;
	   tlxRow2 = false;
	   tlxRow3 = false;
	   tlx = new TLXXML();
	   //ipwXMLp2->Config("CodePage=0");
	   ipwXMLp2->ParseFile(FileName);

	   if (ParseTLXFile(FileName)) {
		 for (int npages=0; npages<cxPageControl1->PageCount; npages++)
		   FormatWorksheet(Workbook->Sheets[cxPageControl1->Pages[npages]]);
		 CheckTLXDatasets();
		 SpecialFormating();
		 FillMetaData();
		 ResetSSMetadata();
		 ReformatElements();
		 TilFileName = FileName;
		 tiGlobals->OpenFileExt = TLX;
		 }
	   else {
		 ContactList->Clear();
		 }
	   delete tlx;
	   SingleSiteCheck();
       CheckBoxUndoEnabled = true;
       SetConcFluxMenuItems(true);
       ProfGrid1->FocusCell(1,3);
       }
     }
   else if (SameText(FileExt, L".xls")) {
	 if (!XMLLookUpError) {
       if (OpenXLS(FileName)) {
         FormatWorksheet(ProfGrid1);
         TilFileName = FileName;
         tiGlobals->OpenFileExt = XLS;
         }
       else
         ParentForm->CloseChild();  
       }
     }
   return ReturnValue;
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::FillPubGrid(void)
{
   if (Publications->Count >0) {
	 Publications->Sort(CitationCompare);
	 AdvColumnGrid4->RowCount = Math::Max(2,Publications->Count + 1);
	 for (int j=0, row=1; j<Publications->Count; j++, row++) {
	   PUBLICATION* pub = (PUBLICATION*)Publications->Items[j];
	   AdvColumnGrid4->Cells[1][row] = pub->Citation;
	   AdvColumnGrid4->Objects[1][row] = (TObject*)pub;
	   }
	 }
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::ExitMetadata(void)
{
   // force an exit from the active metadata control
   try {
       if (PageControl1->ActivePage == TabSheet2) {
         if (PageControl2->ActivePage != TabSheetLithology &&
             PageControl2->ActivePage != TabSheetContacts &&
             PageControl2->ActivePage != TabSheetGeochron &&
             PageControl2->ActivePage != TabSheetAgeModels) {
               TWinControl* Control = ActiveControl;
               FocusControl(PageControl2);
               if (Control->Visible && Control->Enabled && !Control->Name.IsEmpty())
                 FocusControl(Control);
               }
         }
       }
   catch(...) { }
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::Save(void)
{
   ExitMetadata();

   UnicodeString PathName;
   UnicodeString FilePath = ExtractFilePath(TilFileName);
   UnicodeString FileName = ExtractFileName(TilFileName);
   UnicodeString FileExt = ExtractFileExt(TilFileName);

   bool SaveFile = true;
   if (SameText(FileExt, L".tlx"))
	 // if file is already .tlx, then save without asking
	 PathName = TilFileName;
   else if (SameText(FileExt, L".til") || SameText(FileExt, L".xls")) {
	 int pos;
     if ((pos = FileName.Pos(".")) > 0) {
       FileName.SetLength(pos);
       FileName += "tlx";
       }
     SaveDialog1->Filter = "Tilia XML (*.tlx)|*.tlx";
     SaveDialog1->FileName = FileName;
     SaveDialog1->DefaultExt = "tlx";
     SaveDialog1->FilterIndex = 1;
     SaveDialog1->InitialDir = FilePath;
     SaveDialog1->Title = "Save As";

     if (SaveDialog1->Execute())
       PathName = SaveDialog1->FileName;
     else
       SaveFile = false;
     }
   else {  // no file yet
     SaveDialog1->Filter = "Tilia XML (*.tlx)|*.tlx";
     SaveDialog1->FileName.SetLength(0);
     SaveDialog1->InitialDir.SetLength(0);
     SaveDialog1->DefaultExt = "tlx";
     SaveDialog1->FilterIndex = 1;
     SaveDialog1->Title = "Save As";
     if (SaveDialog1->Execute())
       PathName = SaveDialog1->FileName;
     else
       SaveFile = false;
     }

   if (SaveFile) {
     FileExt = ExtractFileExt(PathName);
	 if (SameText(FileExt, L".tlx"))
	   SaveTLX(PathName);
	 //else if (SameText(FileExt, L".xls"))
     //  SaveXLS(PathName);
     SpreadSheetChanged = false;
     }
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::SaveAs(void)
{
   SaveDialog1->Filter = "Tilia XML (*.tlx)|*.tlx";
   SaveDialog1->Title = "Save As";
   ExportSaveAs();
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::Export(void)
{
   SaveDialog1->Filter = "Excel (*.xls)|*.xls";
   SaveDialog1->Title = "Export";
   ExportSaveAs();
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::ExportSaveAs(void)
{
   ExitMetadata();

   UnicodeString PathName;
   UnicodeString FilePath = ExtractFilePath(TilFileName);
   UnicodeString FileName = ExtractFileName(TilFileName);
   UnicodeString FileExt = ExtractFileExt(TilFileName);

   bool SaveFile = true;
   if (SameText(FileExt, L".tlx") || SameText(FileExt, L".xls") || SameText(FileExt, L".til")) {
	 // .tlx, .xls, or .til file already exists
	 int pos;
	 if ((pos = FileName.Pos(".")) > 0)
	   FileName.SetLength(pos-1);
	 SaveDialog1->FileName = FileName;
	 /*
	 if (SameText(FileExt, L".xls")) {
	   SaveDialog1->DefaultExt = "xls";
	   SaveDialog1->FilterIndex = 2;
	   }
	 else { */
	   SaveDialog1->DefaultExt = "tlx";
	   SaveDialog1->FilterIndex = 1;
     //  }
     SaveDialog1->InitialDir = FilePath;
     if (SaveDialog1->Execute())
       PathName = SaveDialog1->FileName;
     else
       SaveFile = false;
     }
   else {  // no file yet
     SaveDialog1->FileName.SetLength(0);
     SaveDialog1->InitialDir.SetLength(0);
     if (SaveDialog1->Execute())
       PathName = SaveDialog1->FileName;
     else
       SaveFile = false;
     }

   if (SaveFile) {
     FileExt = ExtractFileExt(PathName);
	 if (SameText(FileExt, L".tlx")) {
	   SaveTLX(PathName);
	   TilFileName = PathName;
	   SpreadSheetChanged = false;
	   }
	 //else if (SameText(FileExt, L".xls"))
     //  SaveXLS(PathName);
     }
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::SaveTLX(UnicodeString& PathName)
{
   Screen->Cursor = crHourGlass;
   WriteTLX *w = new WriteTLX(PathName, this);
   try
     {
     try
       {
       w->WriteFile();
       ParentForm->StatusBar1->Panels->Items[0]->Text =
         MinimizeName(PathName, ParentForm->StatusBar1->Canvas,
         ParentForm->StatusBar1->Panels->Items[0]->Width);
       Caption = PathName;
       TilFileName = PathName;
       Modified = false;
       }
     catch(Exception &e)
       {
	   if (FileExists(PathName))
		 DeleteFileW(PathName);
	   MessageDlg(e.Message, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
       }
     }
   __finally
     {
     delete w;
     Screen->Cursor = crDefault;
     }
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::InsertPercentsSheet(bool MakeActive)
{
   ProfGrid2 = InsertNewWorksheet("Percents", 1, MakeActive);
   ProfGrid2->OnKeyDown = ProfGrid2KeyDown;
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::Test(void)
{
  /*
  Variant Value = ProfGrid1->Cells[ProfGrid1->Col][ProfGrid1->Row]->Value;
  AnsiString Text = ProfGrid1->Cells[ProfGrid1->Col][ProfGrid1->Row]->Text;
  ShowMessage("Col = " + IntToStr(ProfGrid1->Col) + ", Row = " +
       IntToStr(ProfGrid1->Row) + ". " +  Text + ". Type = " + IntToHex(Value.Type(),4));
  */
  // ProfGrid1->AbsoluteCells[260][3]->Value = "Howie";

  /* int ContentRowCount = 0;
  for (int i=ProfGrid1->RowCount-1; i>0; i--)
    if (!ProfGrid1->RowIsEmpty(i)) {
	  ContentRowCount = i;
      break;
      } */

  //ShowMessage("ContentColCount = " + IntToStr(ContentColCount(ProfGrid1)));
  //ShowMessage("AbsContentColCount = " + IntToStr(AbsContentColCount(ProfGrid1)));
  //ShowMessage("UsedColumns = " + IntToStr(ProfGrid1->UsedColumns->Count));

  //ProfGrid1->FocusCell(1,3);

  //ExportToExcelFile(const FileName: TFileName; FileFormat: DWORD = 0): Boolean;
  //ProfGrid1->ExportToExcelFile("c:\\Projects\\Tilia\\test1.xls", 0);

  //ProfGrid1->MoveColumn(7, 5);

  // -----------------

  //ShowMessage(ProfGrid1->UsedColumns->Count);
   Beep();
}
//---------------------------------------------------------------------------

int __fastcall TTilSpreadSheetForm::ContentRowCount(TProfGrid* ProfGrid)
{
   for (int i=ProfGrid->RowCount-1; i>0; i--)
	 if (!ProfGrid->RowIsEmpty(i))
	   return(i);
   return 0;
}
//---------------------------------------------------------------------------

int __fastcall TTilSpreadSheetForm::AbsContentRowCount(TProfGrid* ProfGrid)
{
   for (int i=ProfGrid->RowCount-1; i>0; i--)
     if (!ProfGrid->RowIsEmpty(i))
       return(i);
   return 0;
}
//---------------------------------------------------------------------------

int __fastcall TTilSpreadSheetForm::ContentColCount(TProfGrid* ProfGrid)
{
   for (int i=ProfGrid->ColCount-1; i>0; i--)
     if (!ProfGrid->ColumnIsEmpty(i))
       return(i);
   return 0;
}
//---------------------------------------------------------------------------

int __fastcall TTilSpreadSheetForm::AbsContentColCount(TProfGrid* ProfGrid)
{
   for (int i=ProfGrid->ColCount-1; i>0; i--)
     if (!ProfGrid->ColumnIsEmpty(i))
	   return(i+ProfGrid->HiddenColCount);
   return 0;
}
//---------------------------------------------------------------------------

// Absolute number of header columns (including hidden ones)
int __fastcall TTilSpreadSheetForm::AbsHeaderColCount(TProfGrid* ProfGrid)
{
   int HeaderCols = ProfGrid->FixedCols + ProfGrid->HiddenColCount;
   return(HeaderCols);
}
//---------------------------------------------------------------------------

// Absolute number of header rows (including hidden ones)
int __fastcall TTilSpreadSheetForm::AbsHeaderRowCount(TProfGrid* ProfGrid)
{
   int HeaderRows = ProfGrid->FixedRows;
   return(HeaderRows);
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::GenerateContactColumns()
{
   co_family_name->DataBinding->Data = (TObject*)IndexOf_co_family_name;
   co_given_names->DataBinding->Data = (TObject*)IndexOf_co_given_names;
   co_leading_initials->DataBinding->Data = (TObject*)IndexOf_co_leading_initials;
   co_suffix->DataBinding->Data = (TObject*)IndexOf_co_suffix;
   co_title->DataBinding->Data = (TObject*)IndexOf_co_title;
   co_status->DataBinding->Data = (TObject*)IndexOf_co_status;
   co_telephone->DataBinding->Data = (TObject*)IndexOf_co_telephone;
   co_fax->DataBinding->Data = (TObject*)IndexOf_co_fax;
   co_email->DataBinding->Data = (TObject*)IndexOf_co_email;
   co_url->DataBinding->Data = (TObject*)IndexOf_co_url;
   co_address->DataBinding->Data = (TObject*)IndexOf_co_address;
   co_notes->DataBinding->Data = (TObject*)IndexOf_co_notes;

   // this line is critical
   ContactsGridCardView1->DataController->CustomDataSource = ContactDataSource;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::SaveDialog1TypeChange(TObject *Sender)
{
   UnicodeString FileName = ExtractFileName(SaveDialog1->FileName);

   int pos;
   if ((pos = FileName.Pos(".")) > 0)
	 FileName.SetLength(pos);

   if (SaveDialog1->FilterIndex == 1)
	 SaveDialog1->DefaultExt = "xml";
   else
	 SaveDialog1->DefaultExt = "xls";
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::Memo2Change(TObject *Sender)
{
   Datasets[DatasetTabsheetNum()].Notes = Memo2->Text;
}
//---------------------------------------------------------------------------

// --> publication tabsheet
void __fastcall TTilSpreadSheetForm::TabSheetPubsShow(TObject *Sender)
{
   FocusControl(AdvColumnGrid4);
   PUBTYPEDEFS PubTypeDefs;
   AdvColumnGrid4->Row = 1;
   if (Publications->Count > 0) {
	 PUBLICATION* pub = (PUBLICATION*)AdvColumnGrid4->Objects[1][1];
	 CheckPublicationLinkage(pub);
	 }
}
//---------------------------------------------------------------------------

// new publication
void __fastcall TTilSpreadSheetForm::cxButton13Click(TObject *Sender)
{
   NewPublication();
   FocusControl(AdvColumnGrid4);
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::NewPublication(void)
{
   PUBLICATION *pub = new PUBLICATION(JOURNAL_ARTICLE);

   void *PubFrom;

   if (tiLicense->Type() == verNEOTOMASTEWARD) {
	 try {
		 PubForm = new TStewardPubForm(pub, NEWPUB, ContactList, this);
		 }
	 catch(Exception &e) {
		 UnicodeString msg = e.Message + L"\nYou may not have an Internet connection.";
		 msg += L"\nTry non-steward version of publications form?";
		 if (MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbYes << mbNo, 0) != mrYes)
		   PubForm = new TPubForm(pub, this);
		 }
	 }
   else
	 PubForm = new TPubForm(pub, this);

   PUBTYPEDEFS PubTypeDefs;
   if (PubForm->ShowModal() == mrOk) {
	 Publications->Add(pub);
	 Publications->Sort(CitationCompare);

	 int row = AdvColumnGrid4->RowCount - 1;
	 if (!AdvColumnGrid4->Cells[1][row].IsEmpty()) {
	   row++;
	   AdvColumnGrid4->RowCount++;
	   }
	 AdvColumnGrid4->Cells[1][row] = pub->Citation;
	 AdvColumnGrid4->Objects[1][row] = (TObject*)pub;
     AdvColumnGrid4->SortByColumn(1);

	 AddAuthorsToContacts(pub->AuthorList);
	 cxButton14->Enabled = true;
	 }
   else
	 delete pub;

   delete PubForm;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::AdvColumnGrid4RowChanging(TObject *Sender, int OldRow,
		  int NewRow, bool &Allow)
{
   PUBTYPEDEFS PubTypeDefs;
   PUBLICATION* pub = (PUBLICATION*)AdvColumnGrid4->Objects[1][NewRow];
   CheckPublicationLinkage(pub);
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::CheckPublicationLinkage(PUBLICATION* pub)
{
   bool DeleteButtonEnabled = true;
   for (unsigned int i=0; i<Datasets.size(); i++) {
	 for (unsigned int j=0; j<Datasets[i].Publications.size(); j++) {
	   if (Datasets[i].Publications[j] == pub) {
		 DeleteButtonEnabled = false;
		 break;
		 }
	   }
	 if (!DeleteButtonEnabled) break;
	 }
   if (DeleteButtonEnabled) {
	 for (int i=0; i<GeochronList->Count(); i++) {
	   GEOCHRON* Date = &GeochronList->Dates[i];
	   for (unsigned int j=0; j<Date->publications.size(); j++) {
		 if (Date->publications[j] == pub) {
           DeleteButtonEnabled = false;
           break;
           }
         }
       if (!DeleteButtonEnabled) break;
       }
     }
   cxButton14->Enabled = DeleteButtonEnabled;
}
//---------------------------------------------------------------------------

// Edit publication
void __fastcall TTilSpreadSheetForm::cxButton16Click(TObject *Sender)
{
   EditPublication();
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::ListBox1DblClick(TObject *Sender)
{
   //EditPublication();
}
//---------------------------------------------------------------------------
void __fastcall TTilSpreadSheetForm::AdvColumnGrid4DblClickCell(TObject *Sender, int ARow,
          int ACol)
{
   if (ACol == 2)
     EditPublication();
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::EditPublication(void)
{
   int row = AdvColumnGrid4->Row;
   PUBLICATION* pub = (PUBLICATION*)AdvColumnGrid4->Objects[1][row];
   PUBLICATION* savepub = new PUBLICATION(NOTSELECTED);
   *savepub = *pub;

   void *PubFrom;

   if (tiLicense->Type() == verNEOTOMASTEWARD)
	 PubForm = new TStewardPubForm(pub, EDITPUB, ContactList, this);
   else
	 PubForm = new TPubForm(pub, this);

   PUBTYPEDEFS PubTypeDefs;
   if (PubForm->ShowModal() == mrOk) {
	 Publications->Sort(CitationCompare);

	 int highlight_row = 1;
	 for (int i=0, row=1; i<Publications->Count; i++, row++) {
	   PUBLICATION* pub1 = (PUBLICATION*)Publications->Items[i];
	   AdvColumnGrid4->Cells[1][row] = pub1->Citation;
	   AdvColumnGrid4->Objects[1][row] = (TObject*)pub1;
	   if (pub == pub1)
		 highlight_row = row;
	   }
	 AdvColumnGrid4->Row = highlight_row;
	 AddAuthorsToContacts(pub->AuthorList);
	 }
   else
	 *pub = *savepub;

   delete savepub;
   delete PubForm;
   FocusControl(AdvColumnGrid4);
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::AddAuthorsToContacts(vector<AUTHOR>& AuthorList)
{
   // adds authors from publications to contacts
   vector<AUTHOR>::pointer Author;

   for (unsigned int i=0; i<AuthorList.size(); i++) {
	 Author = &AuthorList[i];
	 if (Author->contact == NULL) {
	   if (!GetAuthorContact(Author, ContactList)) {
		 CONTACT* contact = new CONTACT(Author);
		 Author->contact = contact;
		 ContactList->Add(contact);
		 }
	   }
	}
}
//---------------------------------------------------------------------------

// delete row in pub list
void __fastcall TTilSpreadSheetForm::cxButton14Click(TObject *Sender)
{
   int row = AdvColumnGrid4->Row;
   int Count = Publications->Count;

   PUBLICATION* pub = (PUBLICATION*)AdvColumnGrid4->Objects[1][row];
   int idx = Publications->IndexOf(pub);
   Publications->Delete(idx);

   AdvColumnGrid4->RemoveRows(row,1);

   delete pub;
   if (Publications->Count == 0)
	 cxButton14->Enabled = false;

   if (Count == 1) {
	 AdvColumnGrid4->Row = 1;
	 AdvColumnGrid4->ClearNormalCells();
	 }
   else if (row == Count) {
	 //pub = (PUBLICATION*)AdvColumnGrid4->Objects[2][Count-1];
	 AdvColumnGrid4->Row = Count - 1;
	 }
   else {
	 //pub = (PUBLICATION*)AdvColumnGrid4->Objects[2][row];
	 AdvColumnGrid4->Row = row;
	 }

   FocusControl(AdvColumnGrid4);
}
//---------------------------------------------------------------------------

// Show Links
void __fastcall TTilSpreadSheetForm::cxButton15Click(TObject *Sender)
{
   UnicodeString Link;

   TStringList* Links = new TStringList;
   int row = AdvColumnGrid4->Row;
   PUBLICATION* pub = (PUBLICATION*)AdvColumnGrid4->Objects[1][row];

   for (unsigned int i=0; i<Datasets.size(); i++) {
	 for (unsigned int j=0; j < Datasets[i].Publications.size(); j++) {
	   if (Datasets[i].Publications[j] == pub) {
		 Links->Add(Datasets[i].DatasetType + " dataset");
		 break;
		 }
	   }
	 }

   for (int i=0; i<GeochronList->Count(); i++) {
	 GEOCHRON* Date = &GeochronList->Dates[i];
	 for (unsigned int j=0; j<Date->publications.size(); j++) {
	   if (Date->publications[j] == pub) {
		 Link = "Date: Depth = " + VarToStr(Date->Depth) + ", Age = " + VarToStr(Date->Age);
		 Links->Add(Link);
		 break;
		 }
	   }
	 }

   if (!Links->Count)
	 Links->Add("No links");

   TPubLinkForm* PubLinkForm = new TPubLinkForm(this);
   PubLinkForm->ListBox1->Items->Assign(Links);
   PubLinkForm->ShowModal();
   delete PubLinkForm;
   delete Links;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::Panel1Resize(TObject *Sender)
{
   AdvColumnGrid4->Width = Panel1->Width - 48;
   AdvColumnGrid4->Height = max(42, Panel1->Height - 123);
   AdvColumnGrid4->Repaint();
}
//---------------------------------------------------------------------------

int __fastcall TTilSpreadSheetForm::CitationCompare(void * Item1, void * Item2)
{
   PUBLICATION* pub1 = (PUBLICATION*)Item1;
   PUBLICATION* pub2 = (PUBLICATION*)Item2;
   return AnsiCompareText(pub1->Citation, pub2->Citation);
}
//---------------------------------------------------------------------------

int __fastcall TTilSpreadSheetForm::SubmissionCompare(void * Item1, void * Item2)
{
   SUBMISSION* sub1 = (SUBMISSION*)Item1;
   SUBMISSION* sub2 = (SUBMISSION*)Item2;

   if (sub1->SubmissionDate < sub2->SubmissionDate)
     return -1;
   else if (sub1->SubmissionDate > sub2->SubmissionDate)
     return 1;
   else
     return 0;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::NullToZero1Execute(TObject *Sender)
{
   TProfGrid* Grid = ProfGrid();
   Grid->DisableControls();
   Grid->SpreadsheetEnabled = false;
   for (int i=0; i<Grid->Selection->Count; i++) {
	 if (Grid->Selection->Cells[i]->IsEmpty()) {
	   Grid->Selection->Cells[i]->Value = 0;
       Grid->Selection->Cells[i]->Value.ChangeType(varDouble);
	   }
	 }
   Grid->SpreadsheetEnabled = true;
   Grid->EnableControls();
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxPopupEdit1PropertiesInitPopup(TObject *Sender)
{
   AdvColumnGrid6->UnCheckAll(0);
   AdvColumnGrid6->UnCheckAll(1);

   int dataset_num = DatasetTabsheetNum();

   AdvColumnGrid6->RowCount = Math::Max(2,Publications->Count+1);
   AdvColumnGrid6->ClearNormalCells();
   AdvColumnGrid6->Height = 4 + AdvColumnGrid6->DefaultRowHeight*(Publications->Count+1);
   AdvColumnGrid6->AddCheckBoxColumn(0, false, false);
   AdvColumnGrid6->AddCheckBoxColumn(1, false, false);

   for (int i=0,row=1; i<Publications->Count; i++,row++) {
	 PUBLICATION* pub = (PUBLICATION*)Publications->Items[i];
	 AdvColumnGrid6->Cells[2][row] = pub->GetShortCitation(false);
	 AdvColumnGrid6->Objects[2][row] = (TObject*)pub;
	 for (unsigned int j=0; j<Datasets[dataset_num].Publications.size(); j++) {
	   if (pub == Datasets[dataset_num].Publications[j]) {
		 AdvColumnGrid6->SetCheckBoxState(0,row,true);
		 if (pub->Primary)
		   AdvColumnGrid6->SetCheckBoxState(1,row,true);
		 }
	   }
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::AdvColumnGrid6CanEditCell(TObject *Sender, int ARow,
		  int ACol, bool &CanEdit)
{
   if (ACol == 1)
	 CanEdit = AdvColumnGrid6->IsChecked(0,ARow);
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::AdvColumnGrid6CheckBoxChange(TObject *Sender,
		  int ACol, int ARow, bool State)
{
   if (!AdvColumnGrid6->Visible)
	 return;
   if (ACol == 0 && State == false)
	 AdvColumnGrid6->SetCheckBoxState(1,ARow,false);
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::AdvColumnGrid6HoverButtonClick(TObject *Sender,
		  int ARow, THoverButtonsCollectionItem *AButton)
{
   PUBLICATION *pub = (PUBLICATION*)AdvColumnGrid6->Objects[2][ARow];
   TMemoForm* MemoForm = new TMemoForm(L"Reference", pub->Citation,
		MemoFormOptions(), this);
   MemoForm->ShowModal();
   delete MemoForm;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxPopupEdit1PropertiesCloseUp(TObject *Sender)
{
   UnicodeString pubs;
   int np = 0;

   int dataset_num = DatasetTabsheetNum();
   Datasets[dataset_num].Publications.clear();

   for (int row=1;  row<AdvColumnGrid6->RowCount; row++) {
	 if (AdvColumnGrid6->IsChecked(0,row)) {
	   PUBLICATION *pub = (PUBLICATION*)AdvColumnGrid6->Objects[2][row];
	   pub->Primary = AdvColumnGrid6->IsChecked(1,row);
	   Datasets[dataset_num].Publications.push_back(pub);
	   if (np++ > 0)
		 pubs += ";";
	   pubs += pub->GetShortCitation(false);
	   }
	 }
   cxPopupEdit1->Text = pubs;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::AdvColumnGrid4HoverButtonClick(TObject *Sender,
		  int ARow, THoverButtonsCollectionItem *AButton)
{
   PUBLICATION *pub = (PUBLICATION*)AdvColumnGrid4->Objects[1][ARow];
   TMemoForm* MemoForm = new TMemoForm(L"Reference", pub->Citation,
		MemoFormOptions(), this);
   MemoForm->ShowModal();
   delete MemoForm;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::WebServices1Click(TObject *Sender)
{
   WebServicesForm = new TWebServicesForm(this);
   WebServicesForm->ShowModal();
   delete WebServicesForm;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::ShowNeotomaIDs1Click(TObject *Sender)
{
   UnicodeString msg;
   int SiteID = -1;
   int CollUnitID = -1;

   TProfGridCell* ACell = ProfGrid1->Cells[ProfGrid1->Col][ProfGrid1->Row];

   SitePtr = (SITE*)Sites->Items[0];
   int site_row;
   SITE* site_ptr = GetSSSitePtr(ProfGrid1->Col, site_row);
   if (site_ptr == NULL)
	 site_ptr = SitePtr;

   if (site_ptr != NULL)
	 SiteID = site_ptr->NeotomaSiteID;
   if (GetCollPtr())
	 CollUnitID = CollPtr->NeotomaCollUnitID;

   int AnalysisUnitID = ProfGrid1->AbsoluteCells[ACell->AbsoluteCol][2]->CustomData;
   int SampleID = GetNeotomaSampleID(ACell->AbsoluteCol,ACell->AbsoluteRow);
   int DataID = ACell->CustomData;
   int DatasetIdx = GetCurrentDataset(ACell->AbsoluteRow);
   int DatasetID = Datasets[DatasetIdx].NeotomaDatasetID;

   msg  = L"SiteID = " + IntToStr(SiteID);
   msg += L"\nCollectionUnitID = " + IntToStr(CollUnitID);
   msg += L"\nAnalysisUnitID = " + IntToStr(AnalysisUnitID);
   msg += L"\nSampleID = " + IntToStr(SampleID);
   msg += L"\nDatasetID = " + IntToStr(DatasetID);
   msg += L"\nDataID = " + IntToStr(DataID);

   TMemoForm* MemoForm = new TMemoForm(L"Neotoma IDs", msg,
		MemoFormOptions(), this);
   MemoForm->ShowModal();
   delete MemoForm;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxButton38Click(TObject *Sender)
{
   UnicodeString msg;

   if (Edit1->Text.IsEmpty()) {
	 msg = L"Site name must be entered for Neotoma lookup.";
	 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 return;
	 }
   if (cxPopupEdit4->Text.IsEmpty() || cxPopupEdit6->Text.IsEmpty()) {
	 msg = L"Latitude/longitude coordinates must be entered for Neotoma lookup.";
     MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 return;
	 }

   if (SitePtr != NULL) {
	 try {
		 NeotomaSiteMetadataForm = new TNeotomaSiteMetadataForm(SitePtr, this);
		 if (NeotomaSiteMetadataForm->InitializationSuccess) {
		   if (NeotomaSiteMetadataForm->ShowModal() == mrOk) {
			 Screen->Cursor = crHourGlass;
			 FillSiteMetaData(SitePtr);
			 }
		   delete NeotomaSiteMetadataForm;
		   }
		 }
	 catch (Exception& e) {
		 Screen->Cursor = crDefault;
		 MessageDlg(e.Message, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 PostMessage(Handle, WM_CLOSE, 0, 0);
		 }
	 }
   Screen->Cursor = crDefault;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::WhitmoreAction1Execute(TObject *Sender)
{
   WhitmoreForm = new TWhitmoreForm(this);
   WhitmoreForm->ShowModal();
   delete WhitmoreForm;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::AssignWhitmore1Click(TObject *Sender)
{
   WhitmoreSampleIDForm = new TWhitmoreSampleIDForm(this);
   WhitmoreSampleIDForm->ShowModal();
   delete WhitmoreSampleIDForm;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::RemoveWhitmoreSample1Click(TObject *Sender)
{
   WhitmoreRemoveSampleForm = new TWhitmoreRemoveSampleForm(this);
   WhitmoreRemoveSampleForm->ShowModal();
   delete WhitmoreRemoveSampleForm;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::CounterAction1Execute(TObject *Sender)
{
   CounterForm = new TCounterForm(this);
   CounterForm->ShowModal();
   delete CounterForm;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::ipsJSONS1SSLServerAuthentication(TObject *Sender,
          TipsJSONSSSLServerAuthenticationEventParams *e)
{
   e->Accept = true;
}
//---------------------------------------------------------------------------

