//---------------------------------------------------------------------------

#ifndef TISpreadH
#define TISpreadH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <ComCtrls.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
#include "cxControls.hpp"
#include "ipwCore.h"
#include "ipwxmlp.h"
#include "cxClasses.hpp"
#include "cxCustomData.hpp"
#include "cxData.hpp"
#include "cxDataStorage.hpp"
#include "cxEdit.hpp"
#include "cxFilter.hpp"
#include "cxGraphics.hpp"
#include "cxGrid.hpp"
#include "cxGridCardView.hpp"
#include "cxGridCustomTableView.hpp"
#include "cxGridCustomView.hpp"
#include "cxGridLevel.hpp"
#include "cxStyles.hpp"
#include "cxGridTableView.hpp"
#include "cxTextEdit.hpp"
#include "cxBlobEdit.hpp"
#include "cxMemo.hpp"
#include "cxRichEdit.hpp"
#include "cxDropDownEdit.hpp"
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include "cxCheckComboBox.hpp"
#include "cxContainer.hpp"
#include "cxMaskEdit.hpp"
#include <CheckLst.hpp>
#include "cxCheckListBox.hpp"
#include "cxButtonEdit.hpp"
//---------------------------------------------------------------------------
#include <Clipbrd.hpp>
#include "cxCheckBox.hpp"
#include <ToolWin.hpp>
#include "cxCalendar.hpp"
#include <Menus.hpp>
#include "cxPC.hpp"
#include "ProfGrid.hpp"
#include "cxListBox.hpp"
#include <ActnList.hpp>
#include <ValEdit.hpp>
#include <Buttons.hpp>
#include "cxTreeView.hpp"
#include "dxtree.hpp"
#include "cxLabel.hpp"
#include <ImgList.hpp>
#include "cxButtons.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxDBExtLookupComboBox.hpp"
#include "cxSpinEdit.hpp"
#include <Graphics.hpp>
#include "cxLookAndFeels.hpp"
#include "ipworks.h"
#include <Mask.hpp>
#include "cxImage.hpp"
#include "cxCalc.hpp"
#include "BaseGrid.hpp"
#include "AdvGrid.hpp"
#include "AdvObj.hpp"
#include "AdvCustomGridDropDown.hpp"
#include "AdvGridDropDown.hpp"
#include "AdvControlDropDown.hpp"
#include "AdvDropDown.hpp"
#include "cxGridCustomLayoutView.hpp"
#include "dxCore.hpp"
#include "dxdbtrel.hpp"
#include "cxDateUtils.hpp"
//#include "cxNavigator.hpp"
#include "AdvCGrid.hpp"
#include "ipwhttp.h"
#include <Sockets.hpp>
#include "ipshttps.h"
#include "ipwjson.h"
#include "ipsjsons.h"
#include "dxGDIPlusClasses.hpp"
#include "cxGroupBox.hpp"
#include "cxRadioGroup.hpp"
#include "cxPCdxBarPopupMenu.hpp"
#include "dxSkinBlack.hpp"
#include "dxSkinBlue.hpp"
#include "dxSkinBlueprint.hpp"
#include "dxSkinCaramel.hpp"
#include "dxSkinCoffee.hpp"
#include "dxSkinDarkRoom.hpp"
#include "dxSkinDarkSide.hpp"
#include "dxSkinDevExpressDarkStyle.hpp"
#include "dxSkinDevExpressStyle.hpp"
#include "dxSkinFoggy.hpp"
#include "dxSkinGlassOceans.hpp"
#include "dxSkinHighContrast.hpp"
#include "dxSkiniMaginary.hpp"
#include "dxSkinLilian.hpp"
#include "dxSkinLiquidSky.hpp"
#include "dxSkinLondonLiquidSky.hpp"
#include "dxSkinMcSkin.hpp"
#include "dxSkinMetropolis.hpp"
#include "dxSkinMetropolisDark.hpp"
#include "dxSkinMoneyTwins.hpp"
#include "dxSkinOffice2007Black.hpp"
#include "dxSkinOffice2007Blue.hpp"
#include "dxSkinOffice2007Green.hpp"
#include "dxSkinOffice2007Pink.hpp"
#include "dxSkinOffice2007Silver.hpp"
#include "dxSkinOffice2010Black.hpp"
#include "dxSkinOffice2010Blue.hpp"
#include "dxSkinOffice2010Silver.hpp"
#include "dxSkinOffice2013DarkGray.hpp"
#include "dxSkinOffice2013LightGray.hpp"
#include "dxSkinOffice2013White.hpp"
#include "dxSkinPumpkin.hpp"
#include "dxSkinsCore.hpp"
#include "dxSkinscxPCPainter.hpp"
#include "dxSkinsDefaultPainters.hpp"
#include "dxSkinSeven.hpp"
#include "dxSkinSevenClassic.hpp"
#include "dxSkinSharp.hpp"
#include "dxSkinSharpPlus.hpp"
#include "dxSkinSilver.hpp"
#include "dxSkinSpringTime.hpp"
#include "dxSkinStardust.hpp"
#include "dxSkinSummer2008.hpp"
#include "dxSkinTheAsphaltWorld.hpp"
#include "dxSkinValentine.hpp"
#include "dxSkinVS2010.hpp"
#include "dxSkinWhiteprint.hpp"
#include "dxSkinXmas2008Blue.hpp"
#include "AdvUtil.hpp"
#include "AdvSprd.hpp"
#include "dxBarBuiltInMenu.hpp"
#include "dxSkinOffice2016Colorful.hpp"
#include "dxSkinOffice2016Dark.hpp"
#include "dxSkinVisualStudio2013Blue.hpp"
#include "dxSkinVisualStudio2013Dark.hpp"
#include "dxSkinVisualStudio2013Light.hpp"
#include "htmlbtns.hpp"
#include "frmctrllink.hpp"
#include "AdvPanel.hpp"
#include "AsgMemo.hpp"
#include "AdvMemoDropDown.hpp"
//#include "AdvNavBar.hpp"
//#include "DBAdvGlowNavigator.hpp"
#include <DBCtrls.hpp>
#include "cxNavigator.hpp"
//#include "DBAdvNavigator.hpp"
#include <vector>
#include <list>
#include <map>
#include <set>
//#include "olexlsf_TLB.h"
#ifndef TGUtilsH
#include "TGUtils.h"
#endif
#ifndef TIContacH
#include "TIContac.h"
#endif
#ifndef TILithH
#include "TILith.h"
#endif
#ifndef TIPubH
#include "TIPub.h"
#endif
#ifndef TIGeochrH
#include "TIGeochr.h"
#endif
#ifndef TIAgeModH
#include "TIAgeMod.h"
#endif
#ifndef TIloiH
#include "TIloi.h"
#endif
#ifndef TICtbFrmH
#include "TICtbFrm.h"
#endif
#ifndef TIErrFrmH
#include "TIErrFrm.h"
#endif
#ifndef TIElmFrmH
#include "TIElmFrm.h"
#endif
#ifndef TIUtilsH
#include "TIUtils.h"
#endif
#ifndef TIVersionH
#include "TIVersion.h"
#endif
#ifndef TILookupH
#include "TILookup.h"
#endif
#ifndef TIEdGrpsH
#include "TIEdGrps.h"
#endif
#ifndef TICONShtH
#include "TICONSht.h"
#endif
#ifndef TIdmspanH
#include "TIdmspan.h"
#endif
#ifndef TIXMLH
#include "TIXML.h"
#endif
#ifndef TIChkVarUtilsH
#include "TIChkVarUtils.h"
#endif
#ifndef TIMapSitH
#include "TIMapSit.h"
#endif
#ifndef TICommonH
#include "TICommon.h"
#endif

class TConcForm;

//---------------------------------------------------------------------------
enum CHECKVARS { SPELLING, HIERARCHY, NOVARCHECK };
enum SSACTIONS { SSKEY, SSMOUSE };
enum UNDOTYPE { CELLSCHANGED, ROWSDELETED, COLSDELETED, ROWSINSERTED, COLSINSERTED };
enum PASTEERRORS { NO_PASTE_ERROR, PASTE_INTO_CHECKBOX, PASTE_FROM_CHECKBOX };
enum HEADERROW { ANAL_UNIT_NAME, COLL_UNIT_NAME, COLL_UNIT_HANDLE, SITE_NAME };
enum GEOCHRONID { GEOCHRONDEPTH, GEOCHRONNAME, GEOCHRONNONE };
enum TAPHSTATUS { TAPHNONE, TAPHPOSTED, TAPHCANCELED };
enum MODIFIERTYPE { MODELEMENT, MODTAPH };
enum CALIBPROGRAMPOPUP { CALIBAGEMODEL, CALIBGEOCHRON };
//---------------------------------------------------------------------------

class ETLXFileError : public Exception
{
public:
  __fastcall ETLXFileError(const UnicodeString Msg) : Exception(Msg){}
};
//---------------------------------------------------------------------------

typedef struct
{
  Variant Technical;
  Variant SD;
  Variant LongTerm;
} IsotopeInstError;
//---------------------------------------------------------------------------

class ISOTOPEBASE
{
private:
	IsotopeInstError FInstError;
public:
	ISOTOPEBASE() { }
	__property IsotopeInstError InstError = {read = FInstError, write = FInstError};
};
//---------------------------------------------------------------------------

class UNDOCELL
{
public:
  int Col;
  int Row;
  Variant Value;
  TObject* Object;
  bool CheckBox;
public:
  UNDOCELL() { CheckBox = false; Object = NULL; }
};
//---------------------------------------------------------------------------

class UNDO
{
public:
  short Type;
  TProfGrid* ProfGrid;
  TGridRect Rect;
  list<UNDOCELL> Cells;    // stores deleted cells
  list<int> rc;            // stores deleted/inserted rows/columns
public:
  UNDO::UNDO(short, TProfGrid*, int, int);
  UNDO::UNDO(short, TProfGrid*, int, int, bool);
  UNDO::UNDO(short, TProfGrid*);
};
//---------------------------------------------------------------------------

class UNDOSELECTION
{
public:
  int Left;
  int Right;
  int Top;
  int Bottom;
  TProfGrid* ProfGrid;
public:
  UNDOSELECTION() { Left = 0; Right = 0; Top = 0; Bottom = 0; ProfGrid = NULL; }
  UNDOSELECTION(TProfGrid* gr) { Left = gr->Selection->Rect.Left;
    Right = gr->Selection->Rect.Right; Top = gr->Selection->Rect.Top;
    Bottom = gr->Selection->Rect.Bottom; ProfGrid = gr; }
  void operator = (const UNDOSELECTION& copy);
  bool operator != (const UNDOSELECTION& compare);
};
//---------------------------------------------------------------------------

class WORKBOOK
{
public:
  map<TcxTabSheet*, TProfGrid*> Sheets;
};
//---------------------------------------------------------------------------

typedef struct  // used for storing spreadsheet contact ID's before contacts read
{
  int col;
  int row;
  int id;
} SSMETADATAID;
//---------------------------------------------------------------------------

class MyTcxTextEdit : public TcxTextEdit
{
public:
  WideString Text;
};
//---------------------------------------------------------------------------

class GEOCHRONDATASET
{
public:
	int NeotomaDatasetID;
    set<int> NeotomaPublicationIDs;
	UnicodeString Notes;
	vector<CONTACT*> Investigators;
public:
	GEOCHRONDATASET() { NeotomaDatasetID = -1; }
};
//---------------------------------------------------------------------------

class PUBLETTERS
{
private:
  UnicodeString letters;
  int idx;
public:
  PUBLETTERS();
  UnicodeString __fastcall NextLetter(void);
};
//---------------------------------------------------------------------------

class PUBCITATION
{
public:
  UnicodeString Citation;
  PUBLICATION* PubPtr;
public:
  PUBCITATION(UnicodeString citation, PUBLICATION* pub_ptr)
	{ Citation = citation; PubPtr = pub_ptr; }
};
//---------------------------------------------------------------------------

class SUM
{
public:
  UnicodeString Code;
  UnicodeString Base;
  bool Percent;
  int Row;
  double Count;
  int Start;
  int End;

public:
  SUM(UnicodeString& code, UnicodeString& base, bool per, int row)
    { Code = code; Base = base; Percent = per; Row = row; }
};
//---------------------------------------------------------------------------

class SSUM
{
public:
  UnicodeString Code;
  TStringList* Sums;
  int Row;
  double Count;

public:
  SSUM(UnicodeString& code, int row);
  ~SSUM();
};
//---------------------------------------------------------------------------

struct SPREADSHEETCELL {
  int page;
  int row;
  int col;
};
//---------------------------------------------------------------------------

class AGEBASIS
{
public:
  double C14Age;
  double C14AgeYounger;
  double C14AgeOlder;
  double CalAge;
  double CalAgeYounger;
  double CalAgeOlder;
  bool AgesSet;
  UnicodeString Text;
public:
  AGEBASIS() { C14Age = NaN; C14AgeYounger = NaN; C14AgeOlder = NaN;
               CalAge = NaN; CalAgeYounger = NaN; CalAgeOlder = NaN;
               AgesSet = false; }
  void SetAges(TcxTreeView*);
};
//---------------------------------------------------------------------------

typedef struct
{
  int Left;
  int Top;
  int Width;
} CONTROLPROPERTIES;
//---------------------------------------------------------------------------

class CELLPASTED
{
public:
  int n;
  int Col;
  int Row;
  UnicodeString Code;
  Variant Value;
public:
  CELLPASTED() { n = 0; }
  void Save(UnicodeString code, Variant value, int col, int row)
	{ Code = code; Value = value; Col = col; Row = row; }
} ;
//---------------------------------------------------------------------------

class SSTAXANAME
{
public:
  UnicodeString Name;
  UnicodeString Author;
  int Row;
public:
  SSTAXANAME(UnicodeString name, UnicodeString author, int row)
    { Name = name; Author = author; Row = row; }
};
//---------------------------------------------------------------------------

class SYNONYMROW
{
public:
  int row;
  UnicodeString SynonymName;
  TAXONRECORD SynRec;
  TAXONRECORD TaxaRec;
  TAXON* taxon;
  bool replace;
  bool orig_id;
public:
  SYNONYMROW::SYNONYMROW(int r, UnicodeString sn, TAXON* tx)
	{ row = r; SynonymName = sn; taxon = tx; replace = false; orig_id = false; }
  SYNONYMROW::SYNONYMROW(int r, TAXONRECORD* sr, TAXONRECORD& tr, TAXON* tx)
	{ row = r; SynonymName = VarToStr(sr->TaxonName); SynRec = *sr; TaxaRec = tr;
	  taxon = tx; replace = false; orig_id = false; }
};
//---------------------------------------------------------------------------

typedef struct
{
  UnicodeString DupName;
  int row1;
  int row2;
  bool checked;
} DUPVAR;
//---------------------------------------------------------------------------

typedef struct
{
  int row;
  UnicodeString name;
  UnicodeString code;
  UnicodeString element;
  UnicodeString units;
} EMPTYVAR;
//---------------------------------------------------------------------------

class TTilSpreadSheetForm : public TForm
{
__published:	// IDE-managed Components
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TTabSheet *TabSheet2;
	TSaveDialog *SaveDialog1;
	TipwXMLp *ipwXMLp1;
	TPageControl *PageControl2;
	TTabSheet *TabSheetSite;
	TTabSheet *TabSheetCollectionUnit;
	TTabSheet *TabSheetContacts;
	TcxGridLevel *ContactsGridLevel1;
	TcxGrid *ContactsGrid;
	TcxGridCardView *ContactsGridCardView1;
	TcxGridCardViewRow *co_family_name;
	TcxGridCardViewRow *co_given_names;
	TcxGridCardViewRow *co_leading_initials;
	TcxGridCardViewRow *co_suffix;
	TcxGridCardViewRow *co_telephone;
	TcxStyleRepository *cxStyleRepository1;
	TcxStyle *cxStyle1;
	TcxGridTableViewStyleSheet *GridTableViewStyleSheetWindowsStandard;
	TcxStyle *cxStyle3;
	TcxStyle *cxStyle4;
	TcxStyle *cxStyle5;
	TcxStyle *cxStyle6;
	TcxStyle *cxStyle7;
	TcxStyle *cxStyle8;
	TcxStyle *cxStyle9;
	TcxStyle *cxStyle10;
	TcxStyle *cxStyle11;
	TcxStyle *cxStyle12;
	TcxGridCardViewRow *co_fax;
	TcxGridCardViewRow *co_email;
	TcxGridCardViewRow *co_address;
	TLabel *Label1;
	TTabSheet *TabSheetPubs;
	TPanel *Panel1;
	TScrollBox *ScrollBox1;
	TEdit *Edit1;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	TLabel *Label10;
	TLabel *Label11;
	TScrollBox *ScrollBox2;
	TLabel *Label12;
	TLabel *Label13;
	TLabeledEdit *LabeledEdit4;
	TLabeledEdit *LabeledEdit5;
	TLabeledEdit *LabeledEdit6;
	TLabeledEdit *LabeledEdit10;
	TcxCheckComboBox *cxCheckComboBox1;
	TLabel *Label17;
	TLabel *Label18;
	TTabSheet *TabSheetDataset;
	TScrollBox *ScrollBox3;
	TMemo *Memo2;
	TLabel *Label2;
	TTabSheet *TabSheetGeochron;
	TTabSheet *TabSheetAgeModels;
	TTabSheet *TabSheetLithology;
	TButton *Button4;
	TLabel *Label19;
	TLabel *Label20;
	TMemo *Memo4;
	TLabeledEdit *LabeledEdit14;
	TLabel *Label21;
	TEdit *Edit15;
	TLabel *Label22;
	TcxCheckComboBox *cxCheckComboBox2;
	TLabel *Label24;
	TLabel *Label25;
	TcxGridLevel *cxGrid1Level1;
	TcxGrid *cxGrid1;
	TcxGridTableView *cxGrid1TableView1;
	TcxGridColumn *liTop;
	TcxGridColumn *liBottom;
	TcxGridColumn *liDescription;
	TcxGridColumn *liLowerBound;
	TcxGridLevel *cxGrid2Level1;
	TcxGrid *cxGrid2;
	TcxGridTableView *cxGrid2TableView1;
	TcxGridColumn *geMethod;
	TcxGridColumn *geAgeUnits;
	TcxGridColumn *geDepth;
	TcxGridColumn *geThickness;
	TcxGridColumn *geLabNumber;
	TcxGridColumn *geAge;
	TcxGridColumn *geErrorOlder;
	TcxGridColumn *geErrorYounger;
	TcxGridColumn *geSigma;
	TcxGridColumn *geSD;
	TcxGridColumn *geInfinite;
	TcxGridColumn *geParams;
	TcxGridColumn *geMaterialDated;
	TcxGridColumn *gePublication;
	TcxGridColumn *geNotes;
	TcxGridLevel *cxGrid3Level1;
	TcxGrid *cxGrid3;
	TcxGridTableView *cxGrid3TableView1;
	TcxGridLevel *cxGrid3Level2;
	TcxGridTableView *cxGrid3TableView2;
	TcxGridColumn *amName;
	TcxGridColumn *amAgeUnits;
	TcxGridColumn *amDefault;
	TcxGridColumn *amAgeModel;
	TcxGridColumn *amOlderBound;
	TcxGridColumn *amYoungerBound;
	TcxGridColumn *amPreparer;
	TcxGridColumn *amDatePrepared;
	TcxGridColumn *amNotes;
	TcxGridColumn *chDepth;
	TcxGridColumn *chThickness;
	TcxGridColumn *chAnalUnit;
	TcxGridColumn *chAge;
	TcxGridColumn *chOlderLimit;
	TcxGridColumn *chYoungerLimit;
	TcxGridColumn *chAgeBasis;
	TcxStyle *cxStyle2;
	TcxGridTableViewStyleSheet *GridTableViewStyleSheetDevExpress;
	TcxStyle *cxStyle13;
	TcxStyle *cxStyle14;
	TcxStyle *cxStyle15;
	TcxStyle *cxStyle16;
	TcxStyle *cxStyle17;
	TcxStyle *cxStyle18;
	TcxStyle *cxStyle19;
	TcxStyle *cxStyle20;
	TcxStyle *cxStyle21;
	TcxStyle *cxStyle22;
	TcxStyle *cxStyle23;
	TcxStyle *cxStyle24;
	TcxStyle *cxStyle25;
	TcxStyle *cxStyle26;
	TcxGridTableViewStyleSheet *GridTableViewStyleSheetWheat;
	TcxStyle *cxStyle27;
	TcxStyle *cxStyle28;
	TcxStyle *cxStyle29;
	TcxStyle *cxStyle30;
	TcxStyle *cxStyle31;
	TcxStyle *cxStyle32;
	TcxStyle *cxStyle33;
	TcxStyle *cxStyle34;
	TcxStyle *cxStyle35;
	TcxStyle *cxStyle36;
	TcxStyle *cxStyle37;
	TcxGridColumn *amChronNo;
	TcxDateEdit *cxDateEdit1;
	TLabel *Label26;
	TTabSheet *TabSheetLOI;
	TPageControl *PageControl3;
	TTabSheet *TabSheetLOIData;
	TTabSheet *TabSheetLOIWorksheet;
	TScrollBox *ScrollBox4;
	TPanel *Panel3;
	TPanel *Panel5;
	TPanel *Panel20;
	TPanel *Panel21;
	TcxButton *cxButton31;
	TFlowPanel *FlowPanel1;
	TcxCheckComboBox *cxCheckComboBox3;
	TLabel *Label14;
	TButton *Button14;
	TButton *Button15;
	TComboBox *ComboBox7;
	TLabel *Label16;
	TLabel *Label27;
	TComboBox *ComboBox8;
	TcxGridCardViewRow *co_title;
	TcxGridCardViewRow *co_status;
	TcxGridCardViewRow *co_url;
	TcxGridCardViewRow *co_notes;
	TipwXMLp *ipwXMLp2;
	TOpenDialog *OpenDialog1;
	TcxComboBox *cxComboBox2;
	TPopupMenu *PopupMenu1;
	TMenuItem *Copy1;
	TMenuItem *Cut1;
	TMenuItem *Paste1;
	TMenuItem *RareType1;
	TcxPageControl *cxPageControl1;
	TcxTabSheet *cxTabSheet1;
	TProfGrid *ProfGrid1;
	TcxComboBox *cxComboBox4;
	TcxComboBox *cxComboBox5;
	TcxComboBox *cxComboBox3;
	TPopupMenu *PopupMenu3;
	TMenuItem *BuildElement3;
	TMenuItem *Copy2;
	TMenuItem *Cut2;
	TMenuItem *Paste2;
	TMenuItem *EditElements1;
	TPopupMenu *PopupMenu4;
	TMenuItem *EditUnits1;
	TMenuItem *Copy3;
	TMenuItem *Cut3;
	TMenuItem *Paste3;
	TPopupMenu *PopupMenu5;
	TMenuItem *EditContexts1;
	TMenuItem *Copy4;
	TMenuItem *Cut4;
	TMenuItem *Paste4;
	TPopupMenu *PopupMenu6;
	TMenuItem *EditTaphonomy1;
	TMenuItem *Copy5;
	TMenuItem *Cut5;
	TMenuItem *Paste5;
	TPopupMenu *PopupMenu7;
	TMenuItem *Copy6;
	TMenuItem *Cut6;
	TMenuItem *Paste6;
	TMenuItem *EditGroups1;
	TipwXMLp *ipwXMLp5;
	TLabel *Label3;
	TcxComboBox *cxComboBox7;
	TcxComboBox *cxComboBox8;
	TcxComboBox *cxComboBox9;
	TcxComboBox *cxComboBox10;
	TLabel *Label28;
	TcxTreeView *cxTreeView1;
	TPopupMenu *PopupMenu8;
	TMenuItem *EditControl1;
	TMenuItem *AddChildControl1;
	TMenuItem *AddSiblingControl1;
	TMenuItem *DeleteControl1;
	TPopupMenu *PopupMenu9;
	TMenuItem *EditTaxa1;
	TMenuItem *Copy7;
	TMenuItem *Cut7;
	TMenuItem *Paste7;
	TcxBlobEdit *cxBlobEdit1;
	TcxLabel *cxLabel1;
	TMenuItem *Format1;
	TMenuItem *Text1;
	TMenuItem *Number1;
	TMenuItem *Date1;
	TcxDateEdit *cxDateEdit2;
	TMainMenu *MainMenu1;
	TMenuItem *File1;
	TMenuItem *SEdit;
	TMenuItem *SInsert;
	TMenuItem *SCalc;
	TMenuItem *STools;
	TMenuItem *SHelp;
	TMenuItem *SS_Open;
	TMenuItem *SS_New;
	TMenuItem *SS_Close;
	TMenuItem *N1;
	TMenuItem *SS_Save;
	TMenuItem *SS_SaveAs;
	TMenuItem *SS_Export;
	TMenuItem *N2;
	TMenuItem *SS_Exit;
	TMenuItem *SS_Cut;
	TMenuItem *SS_Copy;
	TMenuItem *SS_CopyAll;
	TMenuItem *SS_Paste;
	TMenuItem *SS_ClearAll;
	TMenuItem *N3;
	TMenuItem *SS_Sort;
	TMenuItem *SS_ToggleRare;
	TMenuItem *SS_InsertRow;
	TMenuItem *SS_InsertColumn;
	TMenuItem *N4;
	TMenuItem *SS_InsertWorksheet;
	TMenuItem *SS_InsertCONISSWorksheet;
	TMenuItem *SS_CalcSums;
	TMenuItem *SS_CalcPercents;
	TMenuItem *SS_VariableLookup;
	TMenuItem *SS_EditVariableLookup;
	TMenuItem *SS_NewVariableLookup;
	TMenuItem *SS_CheckVariables;
	TMenuItem *N5;
	TMenuItem *SS_Chronology;
	TMenuItem *SS_ClusterAnalysis;
	TMenuItem *SS_Diagram;
	TMenuItem *N6;
	TMenuItem *SS_Options;
	TMenuItem *SS_EditTaxa;
	TMenuItem *SS_EditGroups;
	TMenuItem *SS_EditElements;
	TMenuItem *SS_EditUnits;
	TMenuItem *SS_EditContexts;
	TMenuItem *SS_EditTaphonomy;
	TMenuItem *SS_NewTaxa;
	TMenuItem *SS_NewGroups;
	TMenuItem *SS_NewElements;
	TMenuItem *SS_NewUnits;
	TMenuItem *SS_NewContexts;
	TMenuItem *SS_NewTaphonomy;
	TipwXMLp *ipwXMLp6;
	TActionList *ActionList1;
	TAction *FileCloseAction1;
	TMenuItem *HelpTopics1;
	TMenuItem *N7;
	TMenuItem *About1;
	TMenuItem *Registration1;
	TAction *FileSaveAction1;
	TAction *FileSaveAsAction1;
	TAction *FileExportAction1;
	TAction *SSCutAction1;
	TAction *SSCopyAction1;
	TAction *SSCopyAllAction1;
	TAction *SSPasteAction1;
	TAction *ClearAllAction1;
	TAction *SortAction1;
	TAction *ToggleRareAction1;
	TAction *InsertRowAction1;
	TAction *DeleteRowAction1;
	TAction *InsertColumnAction1;
	TAction *DeleteColumnAction1;
	TAction *DeleteWorksheetAction1;
	TAction *InsertCONISSSheetAction1;
	TAction *SumsAction1;
	TAction *PercentsAction1;
	TAction *VariableLookupAction1;
	TAction *EditTaxaAction1;
	TAction *EditGroupsAction1;
	TAction *EditElementsAction1;
	TAction *EditUnitsAction1;
	TAction *EditContextsAction1;
	TAction *EditTaphonomyAction1;
	TAction *NewTaxaAction1;
	TAction *NewGroupsAction1;
	TAction *NewElementsAction1;
	TAction *NewUnitsAction1;
	TAction *NewContextsAction1;
	TAction *NewTaphonomyAction1;
	TAction *CheckVariablesAction1;
	TAction *ChronologyAction1;
	TAction *ClusterAnalysisAction1;
	TAction *DiagramAction1;
	TAction *OptionsAction1;
	TAction *BuildElementAction1;
	TAction *FormatTextAction1;
	TAction *FormatNumberAction1;
	TAction *FormatDateAction1;
	TMenuItem *FormulaToValue1;
	TAction *FormulaToValueAction1;
	TMenuItem *SS_FormatCells1;
	TMenuItem *N8;
	TAction *FormatCellsAction1;
	TcxCheckComboBox *cxCheckComboBox4;
	TcxGridColumn *chGeochron;
	TProfGrid *ProfGridGeochron;
	TLabeledEdit *LabeledEdit2;
	TcxComboBox *cxComboBox6;
	TPanel *Panel2;
	TLabel *Label23;
	TLabeledEdit *LabeledEdit3;
	TLabeledEdit *LabeledEdit9;
	TLabeledEdit *LabeledEdit12;
	TToolBar *ToolBar3;
	TToolButton *ToolButton5;
	TToolButton *ToolButton7;
	TToolButton *ToolButton8;
	TcxPopupEdit *cxPopupEdit3;
	TImageList *ImageList1;
	TcxButton *cxButton1;
	TcxButton *cxButton2;
	TLabeledEdit *LabeledEdit13;
	TLabeledEdit *LabeledEdit15;
	TLabeledEdit *LabeledEdit16;
	TComboBox *ComboBox2;
	TcxPopupEdit *cxPopupEdit4;
	TcxPopupEdit *cxPopupEdit5;
	TcxPopupEdit *cxPopupEdit6;
	TcxPopupEdit *cxPopupEdit7;
	TcxPopupEdit *cxPopupEdit8;
	TcxPopupEdit *cxPopupEdit9;
	TcxButton *cxButton3;
	TcxComboBox *cxComboBox11;
	TcxBlobEdit *cxBlobEdit2;
	TcxCheckComboBox *cxCheckComboBox5;
	TMenuItem *Undo1;
	TMenuItem *N9;
	TAction *UndoAction1;
	TMenuItem *SS_CalcConc;
	TAction *ConcAction1;
	TMenuItem *Concentrations2;
	TAction *InsertConcSheetAction1;
	TMenuItem *Influx1;
	TAction *InsertInfluxSheetAction1;
	TAction *InfluxAction1;
	TMenuItem *SS_CalcInflux;
	TMenuItem *Delete1;
	TMenuItem *DeleteRow1;
	TMenuItem *DeleteColumn1;
	TMenuItem *N10;
	TMenuItem *DeleteWorksheet1;
	TMenuItem *N11;
	TMenuItem *DeleteEmptyRows1;
	TMenuItem *DeleteEmptyColumns1;
	TAction *DeleteEmptyRowsAction1;
	TAction *DeleteEmptyColumnsAction1;
	TPopupMenu *PopupMenuCodes;
	TMenuItem *Copy8;
	TMenuItem *Cut8;
	TMenuItem *Paste8;
	TMenuItem *Metadata1;
	TMenuItem *mdSite1;
	TMenuItem *mdCollectionUnit1;
	TMenuItem *mdSiteName1;
	TMenuItem *mdLatNorth1;
	TMenuItem *mdLatSouth1;
	TMenuItem *mdLongWest1;
	TMenuItem *mdLongEast1;
	TMenuItem *mdGeoPol1;
	TMenuItem *mdGeoPol2;
	TMenuItem *mdGeoPol3;
	TMenuItem *mdAdmin1;
	TMenuItem *mdAltitude1;
	TMenuItem *mdArea1;
	TMenuItem *mdSiteDesc1;
	TMenuItem *mdSiteNotes1;
	TMenuItem *mdHandle1;
	TMenuItem *mdCollName1;
	TMenuItem *mdCollType1;
	TMenuItem *mdCollDevice1;
	TMenuItem *mdCollectors1;
	TMenuItem *mdDateColl1;
	TMenuItem *mdCollLoc1;
	TMenuItem *mdDepEnv1;
	TMenuItem *mdLatGPS1;
	TMenuItem *mdLongGPS1;
	TMenuItem *mdGPSErr1;
	TMenuItem *mdGPSAlt1;
	TMenuItem *mdCollNotes1;
	TMenuItem *mdAnalysisUnit1;
	TMenuItem *mdThick1;
	TMenuItem *mdDepth1;
	TMenuItem *mdFacies1;
	TMenuItem *mdChronology1;
	TMenuItem *mdChron;
	TMenuItem *mdChronOld;
	TMenuItem *ChronYoung1;
	TMenuItem *mdChron1;
	TMenuItem *mdChron2;
	TMenuItem *mdChron3;
	TMenuItem *mdChronOld1;
	TMenuItem *mdChronOld2;
	TMenuItem *mdChronOld3;
	TMenuItem *mdChronYoung1;
	TMenuItem *mdChronYoung2;
	TMenuItem *mdChronYoung3;
	TMenuItem *mdChron4;
	TMenuItem *mdChron5;
	TMenuItem *mdChron6;
	TMenuItem *mdChron7;
	TMenuItem *mdChron8;
	TMenuItem *mdChron9;
	TMenuItem *mdChronOld4;
	TMenuItem *mdChronOld5;
	TMenuItem *mdChronOld6;
	TMenuItem *mdChronOld7;
	TMenuItem *mdChronOld8;
	TMenuItem *mdChronOld9;
	TMenuItem *mdChronYoung4;
	TMenuItem *mdChronYoung5;
	TMenuItem *mdChronYoung6;
	TMenuItem *mdChronYoung7;
	TMenuItem *mdChronYoung8;
	TMenuItem *mdChronYoung9;
	TMenuItem *mdSample1;
	TMenuItem *mdAnalyst1;
	TMenuItem *mdDateAnal1;
	TMenuItem *mdKeywords1;
	TMenuItem *mdAltDepth1;
	TMenuItem *mdAltDepth2;
	TMenuItem *mdAltDepth3;
	TMenuItem *mdAltDepth4;
	TMenuItem *mdAltDepth5;
	TMenuItem *mdAltDepth6;
	TMenuItem *mdAltDepth7;
	TMenuItem *mdAltDepth8;
	TMenuItem *mdAltDepth9;
	TcxGridColumn *geAnalUnit;
	TMenuItem *mdAnalUnit1;
	TMenuItem *mdDataset1;
	TLabeledEdit *LabeledEdit1;
	TMenuItem *mdAllSiteItems1;
	TMenuItem *mdAlllCollectionUnitItems1;
	TLabel *Label30;
	TMenuItem *mdLakeCharacteristics1;
	TMenuItem *mdSubstrate1;
	TMenuItem *mdWaterDep1;
	TMenuItem *N12;
	TMenuItem *N14;
	TMenuItem *N15;
	TMenuItem *N13;
	TMenuItem *N16;
	TMenuItem *N17;
	TMenuItem *AllSampleItems1;
	TMenuItem *N18;
	TcxGridLevel *cxGrid2Level2;
	TcxGridTableView *cxGrid2TableView2;
	TcxGridColumn *txTaxon;
	TcxGridColumn *txElement;
	TcxGridColumn *txFraction;
	TcxButton *cxButton4;
	TcxGridColumn *txNotes;
	TcxGridColumn *chCalibCurve;
	TcxGridColumn *chCalibProgram;
	TcxCheckComboBox *cxCheckComboBox7;
	TCheckBox *CheckBox2;
	TPanel *Panel9;
	TcxPopupEdit *cxPopupEdit12;
	TLabel *Label31;
	TPanel *Panel10;
	TcxButton *cxButton5;
	TcxButton *cxButton6;
	TLabel *Label29;
	TPanel *Panel12;
	TcxButton *cxButton7;
	TcxButton *cxButton8;
	TcxSpinEdit *cxSpinEdit1;
	TcxPopupEdit *cxPopupEdit13;
	TLabel *Label32;
	TcxButton *cxButton9;
	TcxButton *cxButton10;
	TPanel *Panel13;
	TImage *Image1;
	TcxButton *cxAspectButtonN;
	TcxButton *cxAspectButtonS;
	TcxButton *cxAspectButtonW;
	TcxButton *cxAspectButtonE;
	TcxButton *cxAspectButtonNE;
	TcxButton *cxAspectButtonNW;
	TcxButton *cxAspectButtonSE;
	TcxButton *cxAspectButtonSW;
	TcxButton *cxAspectButtonNNE;
	TcxButton *cxAspectButtonNNW;
	TcxButton *cxAspectButtonENE;
	TcxButton *cxAspectButtonESE;
	TcxButton *cxAspectButtonWNW;
	TcxButton *cxAspectButtonWSW;
	TcxButton *cxAspectButtonSSE;
	TcxButton *cxAspectButtonSSW;
	TcxPopupEdit *cxPopupEdit14;
	TLabel *Label33;
	TMenuItem *mdSlopeAngle1;
	TMenuItem *mdSlopeAspect1;
	TMenuItem *N21;
	TcxTextEdit *cxTextEdit1;
	TcxLabel *cxLabel3;
	TcxTextEdit *cxTextEdit2;
	TcxLabel *cxLabel4;
	TcxMemo *cxMemo1;
	TcxMemo *cxMemo2;
	TMenuItem *Neotoma1;
	TMenuItem *Steward1;
	TMenuItem *Upload1;
	TMenuItem *Variables1;
	TAction *NeotomaValidateTaxaAction1;
	TMenuItem *ValidateSpreadsheetTaxa1;
	TAction *NeotomaTaxaLookupAction1;
	TMenuItem *DataType1;
	TMenuItem *SSAnalysisUnit1;
	TMenuItem *SSCollectionUnitName1;
	TMenuItem *SSCollectionUnitHandle1;
	TMenuItem *SSSiteName1;
	TMenuItem *Test1;
	TMenuItem *mdSampleName1;
	TMenuItem *mdLabNumber1;
	TMenuItem *mdPrepMethod1;
	TMenuItem *mdSampleNotes1;
	TcxButton *cxButton11;
	TcxPopupEdit *cxPopupEdit15;
	TdxTreeViewEdit *dxTreeViewEdit1;
	TcxButton *cxButton12;
	TPanel *Panel17;
	TdxTreeViewEdit *dxTreeViewEdit2;
	TPopupMenu *PopupMenuSubstrates;
	TMenuItem *ShowDescription1;
	TAdvControlDropDown *AdvControlDropDown2;
	TAdvStringGrid *AdvStringGridLake;
	TImageList *ImageList2;
	TcxButton *cxButton13;
	TcxButton *cxButton14;
	TcxButton *cxButton15;
	TcxButton *cxButton16;
	TMenuItem *Login1;
	TLabel *Label35;
	TcxCheckBox *cxCheckBox1;
	TcxComboBox *cxComboBox14;
	TMenuItem *HierarachyCheck1;
	TAction *NeotomaHierarchyCheckAction1;
	TAction *NeotomaModifiersAction1;
	TPanel *Panel6;
	TLabel *Label37;
	TcxComboBox *cxComboBox12;
	TcxCheckListBox *cxCheckListBox1;
	TAdvControlDropDown *AdvControlDropDown3;
	TAdvControlDropDown *AdvControlDropDown4;
	TPanel *Panel7;
	TcxCheckComboBox *cxCheckComboBox8;
	TAdvColumnGrid *AdvColumnGrid1;
	TAdvControlDropDown *AdvControlDropDown5;
	TImageList *ImageList4;
	TMenuItem *Lookup1;
	TMenuItem *NewLookupFile1;
	TMenuItem *NewGeoPoliticalLookupFile1;
	TAction *NeotomaLookupAction1;
	TAction *NeotomaGeoPoliticalLookupAction1;
	TMenuItem *NewTaxaLookupFile2;
	TMenuItem *NewVariableModifiersLookupFile1;
	TAdvStringGrid *AdvStringGridXLS;
	TMenuItem *EditTaxaTable1;
	TAction *NeotomaEditTaxaTableAction1;
	TMenuItem *EditPublicationsTable1;
	TAction *NeotomaEditPublicationsTableAction1;
	TPanel *Panel23;
	TMenuItem *mdMixed1;
	TMenuItem *mdIGSN1;
	TMenuItem *mdAnalUnitNotes1;
	TMenuItem *mdDepAgent1;
	TMenuItem *EditMetadataLookup1;
	TMenuItem *EditFacies1;
	TMenuItem *EditDepositionalAgents1;
	TAction *EditFaciesAction1;
	TAction *EditDepAgentAction1;
	TMenuItem *Calibrate1;
	TAction *CalibrateAction1;
	TcxGridColumn *txCalAgeOlder;
	TcxGridColumn *txCalAgeYounger;
	TcxGridColumn *txCalibCurve;
	TcxGridColumn *txCalibProgram;
	TcxGridColumn *txCalAgeMedian;
	TcxButton *cxButton17;
	TipwHTTP *ipwHTTP1;
	TTcpClient *TcpClient1;
	TcxButton *cxButton18;
	TcxImageList *cxImageList1;
	TAdvColumnGrid *AdvColumnGrid3;
	TcxButton *cxButton19;
	TcxButton *cxButton20;
	TMenuItem *N19;
	TMenuItem *ImportChronology1;
	TAction *ImportClamAction1;
	TcxCheckComboBox *cxCheckComboBox9;
	TLabel *Label34;
	TcxButton *cxButton21;
	TcxButton *cxButton22;
	TAdvColumnGrid *AdvColumnGrid4;
	TAction *NeotomaGetDataAction1;
	TipwJSON *ipwJSON1;
	TMenuItem *NeotomaData1;
	TMenuItem *N20;
	TPanel *Panel8;
	TcxButton *cxButton24;
	TFlowPanel *FlowPanel3;
	TcxButton *cxButton25;
	TcxGridColumn *chNotes;
	TPanel *Panel24;
	TcxButton *cxButton26;
	TcxGroupBox *cxGroupBox1;
	TcxGroupBox *cxGroupBox2;
	TcxRadioButton *cxRadioButton1;
	TcxRadioButton *cxRadioButton2;
	TcxGroupBox *cxGroupBox3;
	TcxComboBox *cxComboBox1;
	TcxGroupBox *cxGroupBox4;
	TFlowPanel *FlowPanel4;
	TcxButton *cxButton27;
	TcxComboBox *cxComboBox13;
	TcxButton *cxButton28;
	TFlowPanel *FlowPanel5;
	TipsHTTPS *ipsHTTPS1;
	TFlowPanel *FlowPanel6;
	TcxButton *cxButton29;
	TPanel *Panel16;
	TPanel *Panel18;
	TcxComboBox *cxComboBox15;
	TMenuItem *Synonyms1;
	TMenuItem *TaxonNotes1;
	TFlowPanel *FlowPanel7;
	TFlowPanel *FlowPanel8;
	TBevel *Bevel1;
	TPanel *Panel4;
	TcxLabel *cxLabel2;
	TcxCheckComboBox *cxCheckComboBox10;
	TMenuItem *BaconClam1;
	TMenuItem *ChronologiesTabsheet1;
	TAction *ImportChronologiesTabsheet1;
	TAction *NeotomaUploadAction1;
	TAdvColumnGrid *AdvColumnGrid2;
	TMenuItem *NeotomaVar1;
	TMenuItem *UpdateVariable1;
	TMenuItem *DeleteVariable1;
	TcxButton *cxButton30;
	TcxRadioButton *cxRadioButton7;
	TcxRadioButton *cxRadioButton8;
	TcxLabel *cxLabel5;
	TPanel *Panel25;
	TAdvColumnGrid *AdvColumnGrid5;
	TPanel *Panel26;
	TToolBar *ToolBar1;
	TToolButton *ToolButton1;
	TToolButton *ToolButton2;
	TToolButton *ToolButton3;
	TToolButton *ToolButton4;
	TToolButton *ToolButton6;
	TToolButton *ToolButton9;
	TPopupMenu *PopupMenuLOI;
	TMenuItem *LOIClear1;
	TMenuItem *Specimens1;
	TTabSheet *TabSheetIsotopes;
	TcxButton *cxButton32;
	TPopupMenu *PopupMenu2;
	TMenuItem *ImportAllSpecimens1;
	TMenuItem *InsertSingleSpecimen1;
	THTMLCheckBox *HTMLCheckBox1;
	TFormControlEditLink *FormControlEditLinkPretreat;
	TAdvColumnGrid *AdvColumnGridPretreat;
	TAdvControlDropDown *AdvControlDropDownPretreatment;
	TcxImageList *cxImageList2;
	TPopupMenu *PopupMenuIsotope;
	TMenuItem *SeriesMetadata1;
	TMenuItem *AppendSingleSpecimen1;
	THTMLCheckBox *HTMLCheckBox2;
	THTMLCheckBox *HTMLCheckBox3;
	THTMLCheckBox *HTMLCheckBox4;
	THTMLCheckBox *HTMLCheckBox5;
	THTMLCheckBox *HTMLCheckBox6;
	TcxGridColumn *txUserSpecimenID;
	TMenuItem *NulltoZero1;
	TAction *NullToZeroAction1;
	TToolBar *ToolBar2;
	TToolButton *ToolButton10;
	TToolButton *ToolButton11;
	TToolButton *ToolButton12;
	TToolButton *ToolButton13;
	TToolButton *ToolButton14;
	TToolButton *ToolButton15;
	TToolBar *ToolBar4;
	TToolButton *ToolButton16;
	TToolButton *ToolButton17;
	TToolButton *ToolButton18;
	TToolButton *ToolButton19;
	TToolButton *ToolButton20;
	TToolButton *ToolButton21;
	TToolButton *ToolButton22;
	TToolButton *ToolButton23;
	TToolButton *ToolButton24;
	TToolButton *ToolButton25;
	TToolButton *ToolButton26;
	TToolButton *ToolButton27;
	TcxGridColumn *chAgeUnits;
	TcxButton *cxButton33;
	TCheckBox *CheckBox1;
	TCheckBox *CheckBox3;
	TcxCheckBox *cxCheckBox2;
	TcxCheckBox *cxCheckBox3;
	TAdvStringGrid *AdvIsotopeStringGrid;
	TAdvPanel *AdvPanel1;
	TAdvPanel *AdvPanel2;
	TAdvPanel *AdvPanel3;
	TAdvPanel *AdvPanel4;
	TAdvPanel *AdvPanel5;
	TAdvPanel *AdvPanel6;
	TMenuItem *mdDateSampled1;
	TMenuItem *mdTaxonSampled1;
	TMenuItem *Specimens2;
	TMenuItem *N22;
	TcxImageList *cxImageList3;
	TAdvColumnGrid *AdvColumnGrid6;
	TcxPopupEdit *cxPopupEdit1;
	TcxButton *cxButton23;
	TcxLabel *cxLabel6;
	TcxCheckBox *cxCheckBox4;
	TipsJSONS *ipsJSONS1;
	TAction *DefaultDiagramAction1;
	TMenuItem *WebServices1;
	TMenuItem *ShowNeotomaIDs1;
	TMenuItem *WhitmoreTasks1;
	TMenuItem *Whitmore1;
	TcxButton *cxButton38;
	TFlowPanel *FlowPanel2;
	TcxButton *cxButton34;
	TcxButton *cxButton35;
	TcxButton *cxButton36;
	TcxButton *cxButton37;
	TAction *WhitmoreAction1;
	TMenuItem *AssignWhitmore1;
	TMenuItem *RemoveWhitmoreSample1;
	TcxButton *cxButton39;
	TFlowPanel *FlowPanel9;
	TPanel *Panel14;
	TMenuItem *mdBottom1;
	TLabel *Label4;
	TAdvPanel *AdvPanel7;
	TAdvPanel *AdvPanel8;
	TLabel *Label15;
	TAdvPanel *AdvPanel9;
	TLabel *Label36;
	TcxLabel *cxLabel7;
	TMenuItem *Counter1;
	TAction *CounterAction1;
	TcxGridColumn *chAnalUnitID;
	TAdvColumnGrid *AdvColumnGrid7;
	TPanel *Panel15;
	TFlowPanel *FlowPanel10;
	TcxButton *cxButton40;
	TcxButton *cxButton41;
	TcxGridColumn *geAnalUnitID;
	TPanel *Panel19;
	TAdvColumnGrid *AdvColumnGrid8;
	TFlowPanel *FlowPanel11;
	TcxButton *cxButton42;
	TcxButton *cxButton43;
	TMenuItem *Bacon;
	TMenuItem *Bchron;
	TAction *ImportBaconAction1;
	TAction *ImportBchronAction1;
	TAdvColumnGrid *AdvColumnGrid9;
	TFlowPanel *FlowPanel12;
	TMenuItem *OxCal1;
	TAction *ImportOxCalAction1;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall SaveDialog1TypeChange(TObject *Sender);
	void __fastcall Memo2Change(TObject *Sender);
	void __fastcall Panel1Resize(TObject *Sender);
	void __fastcall TabSheetContactsShow(TObject *Sender);
	void __fastcall ListBox1DblClick(TObject *Sender);
	void __fastcall Edit1Exit(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall TabSheetSiteShow(TObject *Sender);
	void __fastcall LabeledEdit4Exit(TObject *Sender);
	void __fastcall LabeledEdit5Exit(TObject *Sender);
	void __fastcall LabeledEdit10Exit(TObject *Sender);
	void __fastcall LabeledEdit6Exit(TObject *Sender);
	void __fastcall Memo4Exit(TObject *Sender);
	void __fastcall LabeledEdit14Exit(TObject *Sender);
	void __fastcall cxCheckComboBox2PropertiesPopup(TObject *Sender);
	void __fastcall cxCheckComboBox2PropertiesCloseUp(TObject *Sender);
	void __fastcall TabSheetPubsShow(TObject *Sender);
	void __fastcall Edit15Exit(TObject *Sender);
	void __fastcall Memo2Exit(TObject *Sender);
	void __fastcall cxCheckComboBox1PropertiesPopup(TObject *Sender);
	void __fastcall cxCheckComboBox1PropertiesCloseUp(TObject *Sender);
	void __fastcall cxGrid1TableView1EditKeyDown(
		TcxCustomGridTableView *Sender, TcxCustomGridTableItem *AItem,
		TcxCustomEdit *AEdit, WORD &Key, TShiftState Shift);
	void __fastcall liTopPropertiesValidate(TObject *Sender,
		Variant &DisplayValue, TCaption &ErrorText, bool &Error);
	void __fastcall liBottomPropertiesValidate(TObject *Sender,
		Variant &DisplayValue, TCaption &ErrorText, bool &Error);
	void __fastcall geThicknessPropertiesValidate(TObject *Sender,
		Variant &DisplayValue, TCaption &ErrorText, bool &Error);
	void __fastcall geDepthPropertiesValidate(TObject *Sender,
		Variant &DisplayValue, TCaption &ErrorText, bool &Error);
	void __fastcall geAgePropertiesValidate(TObject *Sender,
		Variant &DisplayValue, TCaption &ErrorText, bool &Error);
	void __fastcall geErrorOlderPropertiesValidate(TObject *Sender,
		Variant &DisplayValue, TCaption &ErrorText, bool &Error);
	void __fastcall geErrorYoungerPropertiesValidate(TObject *Sender,
		Variant &DisplayValue, TCaption &ErrorText, bool &Error);
	void __fastcall geSDPropertiesValidate(TObject *Sender,
		Variant &DisplayValue, TCaption &ErrorText, bool &Error);
	void __fastcall geMethodPropertiesEditValueChanged(TObject *Sender);
	void __fastcall TabSheetGeochronShow(TObject *Sender);
	void __fastcall gePublicationPropertiesEditValueToStates(TObject *Sender,
		const Variant &AValue, TcxCheckStates &ACheckStates);
	void __fastcall gePublicationPropertiesStatesToEditValue(
		TObject *Sender, const TcxCheckStates ACheckStates, Variant &AValue);
	void __fastcall gePublicationGetDisplayText(
		TcxCustomGridTableItem *Sender, TcxCustomGridRecord *ARecord,
		UnicodeString &AText);
	void __fastcall cxGrid2TableView1DataControllerAfterPost(
		TcxCustomDataController *ADataController);
	void __fastcall amOlderBoundPropertiesValidate(TObject *Sender,
		Variant &DisplayValue, TCaption &ErrorText, bool &Error);
	void __fastcall amYoungerBoundPropertiesValidate(TObject *Sender,
		Variant &DisplayValue, TCaption &ErrorText, bool &Error);
	void __fastcall chDepthPropertiesValidate(TObject *Sender,
		Variant &DisplayValue, TCaption &ErrorText, bool &Error);
	void __fastcall chThicknessPropertiesValidate(TObject *Sender,
		Variant &DisplayValue, TCaption &ErrorText, bool &Error);
	void __fastcall chAgePropertiesValidate(TObject *Sender,
		Variant &DisplayValue, TCaption &ErrorText, bool &Error);
	void __fastcall chOlderLimitPropertiesValidate(TObject *Sender,
		Variant &DisplayValue, TCaption &ErrorText, bool &Error);
	void __fastcall chYoungerLimitPropertiesValidate(TObject *Sender,
		Variant &DisplayValue, TCaption &ErrorText, bool &Error);
	void __fastcall TabSheetAgeModelsShow(TObject *Sender);
	void __fastcall amPreparerPropertiesEditValueToStates(
		TObject *Sender, const Variant &AValue, TcxCheckStates &ACheckStates);
	void __fastcall amPreparerPropertiesStatesToEditValue(
		TObject *Sender, const TcxCheckStates ACheckStates, Variant &AValue);
	void __fastcall amPreparerGetDisplayText(
		TcxCustomGridTableItem *Sender, TcxCustomGridRecord *ARecord,
		UnicodeString &AText);
	void __fastcall cxGrid3TableView1DataControllerAfterPost(
		TcxCustomDataController *ADataController);
	void __fastcall amNamePropertiesEditValueChanged(TObject *Sender);
	void __fastcall cxGrid3TableView1DataControllerBeforePost(
		TcxCustomDataController *ADataController);
	void __fastcall cxCheckComboBox3PropertiesCloseUp(TObject *Sender);
	void __fastcall cxCheckComboBox3PropertiesPopup(TObject *Sender);
	void __fastcall Button14Click(TObject *Sender);
	void __fastcall Button15Click(TObject *Sender);
	void __fastcall ComboBox7Exit(TObject *Sender);
	void __fastcall ComboBox8Exit(TObject *Sender);
	void __fastcall ComboBox7Click(TObject *Sender);
	void __fastcall ComboBox7Change(TObject *Sender);
	void __fastcall ComboBox8Change(TObject *Sender);
	void __fastcall ComboBox8Click(TObject *Sender);
	void __fastcall ContactsGridCardView1NavigatorButtonsButtonClick(
		TObject *Sender, int AButtonIndex, bool &ADone);
	void __fastcall FormDeactivate(TObject *Sender);
	void __fastcall cxComboBox3Exit(TObject *Sender);
	void __fastcall cxDateEdit1Exit(TObject *Sender);
	void __fastcall ProfGrid1GetEditControl(TProfGrid *Sender,
		int ACol, int ARow, TWinControl *&AControl);
	void __fastcall ProfGrid1CellChanged(TProfGrid *Sender, int ACol,
		int ARow, const WideString OldText, WideString &NewText,
		bool &AllowExit);
	void __fastcall ProfGrid1KeyDown(TObject *Sender, WORD &Key,
		TShiftState Shift);
	void __fastcall ProfGridKeyDown(TObject *Sender, WORD &Key,
		TShiftState Shift);
	void __fastcall ProfGrid1Click(TObject *Sender);
	void __fastcall PopupMenu1Popup(TObject *Sender);
	void __fastcall ProfGridCellChanged(TProfGrid *Sender, int ACol,
		int ARow, const WideString OldText, WideString &NewText,
		bool &AllowExit);
	void __fastcall cxComboBox4Exit(TObject *Sender);
	void __fastcall cxComboBox5Exit(TObject *Sender);
	void __fastcall cxComboBox6Exit(TObject *Sender);
	void __fastcall cxComboBox2Exit(TObject *Sender);
	void __fastcall ProfGridCellCleared(TProfGrid *Sender, int ACol, int ARow);
	void __fastcall ProfGrid1EndPaste(TObject *Sender);
	void __fastcall ProfGrid1MouseDown(TObject *Sender,
		TMouseButton Button, TShiftState Shift, int X, int Y);
	void __fastcall PopupMenu3Popup(TObject *Sender);
	void __fastcall PopupMenu7Popup(TObject *Sender);
	void __fastcall cxComboBox7Enter(TObject *Sender);
	void __fastcall cxComboBox8Enter(TObject *Sender);
	void __fastcall cxComboBox8PropertiesValidate(TObject *Sender,
		Variant &DisplayValue, TCaption &ErrorText, bool &Error);
	void __fastcall cxComboBox7PropertiesValidate(TObject *Sender,
		Variant &DisplayValue, TCaption &ErrorText, bool &Error);
	void __fastcall cxComboBox9PropertiesValidate(TObject *Sender,
		Variant &DisplayValue, TCaption &ErrorText, bool &Error);
	void __fastcall cxComboBox10PropertiesValidate(TObject *Sender,
		Variant &DisplayValue, TCaption &ErrorText, bool &Error);
	void __fastcall cxTreeView1Click(TObject *Sender);
	void __fastcall cxGrid3TableView2FocusedRecordChanged(
		TcxCustomGridTableView *Sender, TcxCustomGridRecord *APrevFocusedRecord,
		TcxCustomGridRecord *AFocusedRecord,
	bool ANewItemRecordFocusingChanged);
	void __fastcall chAgeBasisPropertiesCloseUp(TObject *Sender);
	void __fastcall chAgeBasisPropertiesEditValueChanged(TObject *Sender);
	void __fastcall cxTreeView1Expanded(TObject *Sender, TTreeNode *Node);
	void __fastcall cxTreeView1Collapsed(TObject *Sender, TTreeNode *Node);
	void __fastcall chAgeBasisPropertiesPopup(TObject *Sender);
	void __fastcall cxGrid3TableView2FocusedItemChanged(
		TcxCustomGridTableView *Sender,
		TcxCustomGridTableItem *APrevFocusedItem,
		TcxCustomGridTableItem *AFocusedItem);
	void __fastcall cxTreeView1KeyDown(TObject *Sender, WORD &Key,
		TShiftState Shift);
	void __fastcall EditControl1Click(TObject *Sender);
	void __fastcall AddChildControl1Click(TObject *Sender);
	void __fastcall AddSiblingControl1Click(TObject *Sender);
	void __fastcall DeleteControl1Click(TObject *Sender);
	void __fastcall PopupMenu8Popup(TObject *Sender);
	void __fastcall cxTreeView1MouseDown(TObject *Sender,
		TMouseButton Button, TShiftState Shift, int X, int Y);
	void __fastcall cxTreeView1DragDrop(TObject *Sender,
		TObject *Source, int X, int Y);
	void __fastcall cxTreeView1DragOver(TObject *Sender,
		TObject *Source, int X, int Y, TDragState State, bool &Accept);
	void __fastcall cxGrid3TableView2InitEdit(
		TcxCustomGridTableView *Sender, TcxCustomGridTableItem *AItem,
		TcxCustomEdit *AEdit);
	void __fastcall PageControl1Change(TObject *Sender);
	void __fastcall PageControl2Change(TObject *Sender);
	void __fastcall cxGrid2TableView1EditKeyDown(
		TcxCustomGridTableView *Sender, TcxCustomGridTableItem *AItem,
		TcxCustomEdit *AEdit, WORD &Key, TShiftState Shift);
	void __fastcall cxGrid2TableView1EditKeyUp(
		TcxCustomGridTableView *Sender, TcxCustomGridTableItem *AItem,
		TcxCustomEdit *AEdit, WORD &Key, TShiftState Shift);
	void __fastcall cxGrid1TableView1EditKeyUp(
		TcxCustomGridTableView *Sender, TcxCustomGridTableItem *AItem,
		TcxCustomEdit *AEdit, WORD &Key, TShiftState Shift);
	void __fastcall cxGrid3TableView1EditKeyDown(
		TcxCustomGridTableView *Sender, TcxCustomGridTableItem *AItem,
		TcxCustomEdit *AEdit, WORD &Key, TShiftState Shift);
	void __fastcall cxGrid3TableView1EditKeyUp(
		TcxCustomGridTableView *Sender, TcxCustomGridTableItem *AItem,
		TcxCustomEdit *AEdit, WORD &Key, TShiftState Shift);
	void __fastcall cxGrid3TableView2EditKeyDown(
		TcxCustomGridTableView *Sender, TcxCustomGridTableItem *AItem,
		TcxCustomEdit *AEdit, WORD &Key, TShiftState Shift);
	void __fastcall cxGrid3TableView2EditKeyUp(
		TcxCustomGridTableView *Sender, TcxCustomGridTableItem *AItem,
		TcxCustomEdit *AEdit, WORD &Key, TShiftState Shift);
	void __fastcall cxDateEdit2Exit(TObject *Sender);
	void __fastcall cxPageControl1Change(TObject *Sender);
	void __fastcall FileCloseAction1Execute(TObject *Sender);
	void __fastcall FileSaveAction1Execute(TObject *Sender);
	void __fastcall FileSaveAsAction1Execute(TObject *Sender);
	void __fastcall FileExportAction1Execute(TObject *Sender);
	void __fastcall SSCutAction1Execute(TObject *Sender);
	void __fastcall SSCopyAction1Execute(TObject *Sender);
	void __fastcall SSCopyAllAction1Execute(TObject *Sender);
	void __fastcall SSPasteAction1Execute(TObject *Sender);
	void __fastcall ClearAllAction1Execute(TObject *Sender);
	void __fastcall SortAction1Execute(TObject *Sender);
	void __fastcall ToggleRareAction1Execute(TObject *Sender);
	void __fastcall InsertRowAction1Execute(TObject *Sender);
	void __fastcall DeleteRowAction1Execute(TObject *Sender);
	void __fastcall InsertColumnAction1Execute(TObject *Sender);
	void __fastcall DeleteColumnAction1Execute(TObject *Sender);
	void __fastcall DeleteWorksheetAction1Execute(TObject *Sender);
	void __fastcall InsertCONISSSheetAction1Execute(TObject *Sender);
	void __fastcall SumsAction1Execute(TObject *Sender);
	void __fastcall PercentsAction1Execute(TObject *Sender);
	void __fastcall VariableLookupAction1Execute(TObject *Sender);
	void __fastcall EditTaxaAction1Execute(TObject *Sender);
	void __fastcall EditGroupsAction1Execute(TObject *Sender);
	void __fastcall EditElementsAction1Execute(TObject *Sender);
	void __fastcall EditUnitsAction1Execute(TObject *Sender);
	void __fastcall EditContextsAction1Execute(TObject *Sender);
	void __fastcall EditTaphonomyAction1Execute(TObject *Sender);
	void __fastcall NewTaxaAction1Execute(TObject *Sender);
	void __fastcall NewGroupsAction1Execute(TObject *Sender);
	void __fastcall NewElementsAction1Execute(TObject *Sender);
	void __fastcall NewUnitsAction1Execute(TObject *Sender);
	void __fastcall NewContextsAction1Execute(TObject *Sender);
	void __fastcall NewTaphonomyAction1Execute(TObject *Sender);
	void __fastcall CheckVariablesAction1Execute(TObject *Sender);
	void __fastcall ChronologyAction1Execute(TObject *Sender);
	void __fastcall ClusterAnalysisAction1Execute(TObject *Sender);
	void __fastcall DiagramAction1Execute(TObject *Sender);
	void __fastcall OptionsAction1Execute(TObject *Sender);
	void __fastcall BuildElementAction1Execute(TObject *Sender);
	void __fastcall FormatTextAction1Execute(TObject *Sender);
	void __fastcall FormatNumberAction1Execute(TObject *Sender);
	void __fastcall FormatDateAction1Execute(TObject *Sender);
	void __fastcall PopupMenu9Popup(TObject *Sender);
	void __fastcall FormulaToValueAction1Execute(TObject *Sender);
	void __fastcall FormatCellsAction1Execute(TObject *Sender);
	void __fastcall ProfGrid2KeyDown(TObject *Sender, WORD &Key,
		TShiftState Shift);
	void __fastcall cxCheckComboBox4Exit(TObject *Sender);
	void __fastcall LabeledEdit2Exit(TObject *Sender);
	void __fastcall chGeochronPropertiesPopup(TObject *Sender);
	void __fastcall chGeochronPropertiesCloseUp(TObject *Sender);
	void __fastcall cxPopupEdit3Exit(TObject *Sender);
	void __fastcall cxPopupEdit3PropertiesCloseUp(TObject *Sender);
	void __fastcall cxPopupEdit3PropertiesPopup(TObject *Sender);
	void __fastcall ToolButton5Click(TObject *Sender);
	void __fastcall ToolButton7Click(TObject *Sender);
	void __fastcall ToolButton8Click(TObject *Sender);
	void __fastcall LabeledEdit13Exit(TObject *Sender);
	void __fastcall LabeledEdit16Exit(TObject *Sender);
	void __fastcall LabeledEdit15Exit(TObject *Sender);
	void __fastcall LabeledEdit3Exit(TObject *Sender);
	void __fastcall LabeledEdit9Exit(TObject *Sender);
	void __fastcall LabeledEdit12Exit(TObject *Sender);
	void __fastcall cxButton1Click(TObject *Sender);
	void __fastcall cxPopupEdit4Exit(TObject *Sender);
	void __fastcall cxPopupEdit4PropertiesPopup(TObject *Sender);
	void __fastcall cxPopupEdit4PropertiesCloseUp(TObject *Sender);
	void __fastcall cxPopupEdit4KeyDown(TObject *Sender, WORD &Key,
		TShiftState Shift);
	void __fastcall cxPopupEdit5PropertiesPopup(TObject *Sender);
	void __fastcall cxPopupEdit5PropertiesCloseUp(TObject *Sender);
	void __fastcall cxPopupEdit5Exit(TObject *Sender);
	void __fastcall cxPopupEdit5KeyDown(TObject *Sender, WORD &Key,
		TShiftState Shift);
	void __fastcall cxPopupEdit6PropertiesPopup(TObject *Sender);
	void __fastcall cxPopupEdit6PropertiesCloseUp(TObject *Sender);
	void __fastcall cxPopupEdit6Exit(TObject *Sender);
	void __fastcall cxPopupEdit6KeyDown(TObject *Sender, WORD &Key,
		TShiftState Shift);
	void __fastcall cxPopupEdit7PropertiesPopup(TObject *Sender);
	void __fastcall cxPopupEdit7PropertiesCloseUp(TObject *Sender);
	void __fastcall cxPopupEdit7Exit(TObject *Sender);
	void __fastcall cxPopupEdit8PropertiesPopup(TObject *Sender);
	void __fastcall cxPopupEdit8PropertiesCloseUp(TObject *Sender);
	void __fastcall cxPopupEdit8Exit(TObject *Sender);
	void __fastcall cxPopupEdit8KeyDown(TObject *Sender, WORD &Key,
		TShiftState Shift);
	void __fastcall cxPopupEdit9PropertiesPopup(TObject *Sender);
	void __fastcall cxPopupEdit9PropertiesCloseUp(TObject *Sender);
	void __fastcall cxPopupEdit9Exit(TObject *Sender);
	void __fastcall cxButton3Click(TObject *Sender);
	void __fastcall ProfGrid1CellExit(TProfGrid *Sender, int ACol, int ARow);
	void __fastcall UndoAction1Execute(TObject *Sender);
	void __fastcall ProfGridClearCell(TProfGrid *Sender, int ACol,
		int ARow, bool &CanClear);
	void __fastcall ConcAction1Execute(TObject *Sender);
	void __fastcall InsertConcSheetAction1Execute(TObject *Sender);
	void __fastcall InsertInfluxSheetAction1Execute(TObject *Sender);
	void __fastcall InfluxAction1Execute(TObject *Sender);
	void __fastcall DeleteEmptyRowsAction1Execute(TObject *Sender);
	void __fastcall DeleteEmptyColumnsAction1Execute(TObject *Sender);
	void __fastcall ProfGrid1CheckBoxChanged(TProfGrid *Sender,
		int ACol, int ARow, bool Checked);
	void __fastcall ProfGridPaste(TProfGrid *Sender, int ACol,
		int ARow, TProfGridClipboardCell *ACell, bool &CanPaste);
	void __fastcall mdSiteName1Click(TObject *Sender);
	void __fastcall mdLatNorth1Click(TObject *Sender);
	void __fastcall mdLatSouth1Click(TObject *Sender);
	void __fastcall mdLongWest1Click(TObject *Sender);
	void __fastcall mdLongEast1Click(TObject *Sender);
	void __fastcall mdGeoPol1Click(TObject *Sender);
	void __fastcall mdGeoPol2Click(TObject *Sender);
	void __fastcall mdGeoPol3Click(TObject *Sender);
	void __fastcall mdAdmin1Click(TObject *Sender);
	void __fastcall mdAltitude1Click(TObject *Sender);
	void __fastcall mdArea1Click(TObject *Sender);
	void __fastcall mdSiteDesc1Click(TObject *Sender);
	void __fastcall mdSiteNotes1Click(TObject *Sender);
	void __fastcall mdHandle1Click(TObject *Sender);
	void __fastcall mdCollName1Click(TObject *Sender);
	void __fastcall mdCollType1Click(TObject *Sender);
	void __fastcall mdCollDevice1Click(TObject *Sender);
	void __fastcall mdCollectors1Click(TObject *Sender);
	void __fastcall mdDateColl1Click(TObject *Sender);
	void __fastcall mdCollLoc1Click(TObject *Sender);
	void __fastcall mdDepEnv1Click(TObject *Sender);
	void __fastcall mdLatGPS1Click(TObject *Sender);
	void __fastcall mdLongGPS1Click(TObject *Sender);
	void __fastcall mdGPSErr1Click(TObject *Sender);
	void __fastcall mdGPSAlt1Click(TObject *Sender);
	void __fastcall mdCollNotes1Click(TObject *Sender);
	void __fastcall mdChron1Click(TObject *Sender);
	void __fastcall mdThick1Click(TObject *Sender);
	void __fastcall mdFacies1Click(TObject *Sender);
	void __fastcall mdAnalyst1Click(TObject *Sender);
	void __fastcall mdDateAnal1Click(TObject *Sender);
	void __fastcall mdKeywords1Click(TObject *Sender);
	void __fastcall mdAltDepth1Click(TObject *Sender);
	void __fastcall mdAnalUnit1Click(TObject *Sender);
	void __fastcall LabeledEdit1Exit(TObject *Sender);
	void __fastcall mdAllSiteItems1Click(TObject *Sender);
	void __fastcall mdAllCollectionUnitItems1Click(TObject *Sender);
	void __fastcall mdWaterDep1Click(TObject *Sender);
	void __fastcall mdSubstrate1Click(TObject *Sender);
	void __fastcall AllSampleItems1Click(TObject *Sender);
	void __fastcall txElementGetPropertiesForEdit(
		TcxCustomGridTableItem *Sender, TcxCustomGridRecord *ARecord,
		TcxCustomEditProperties *&AProperties);
	void __fastcall txTaxonGetPropertiesForEdit(
		TcxCustomGridTableItem *Sender, TcxCustomGridRecord *ARecord,
		TcxCustomEditProperties *&AProperties);
	void __fastcall txTaxonPropertiesInitPopup(TObject *Sender);
	void __fastcall cxGrid2TableView2InitEdit(
		TcxCustomGridTableView *Sender, TcxCustomGridTableItem *AItem,
		TcxCustomEdit *AEdit);
	void __fastcall cxGrid2TableView1InitEdit(
		TcxCustomGridTableView *Sender, TcxCustomGridTableItem *AItem,
		TcxCustomEdit *AEdit);
	void __fastcall cxButton4Click(TObject *Sender);
	void __fastcall chCalibProgramPropertiesPopup(TObject *Sender);
	void __fastcall chCalibProgramPropertiesCloseUp(TObject *Sender);
	void __fastcall cxCheckComboBox7PropertiesInitPopup(TObject *Sender);
	void __fastcall cxCheckComboBox7PropertiesPopup(TObject *Sender);
	void __fastcall cxCheckComboBox7PropertiesCloseUp(TObject *Sender);
	void __fastcall cxCheckComboBox2PropertiesInitPopup(TObject *Sender);
	void __fastcall cxCheckComboBox3PropertiesInitPopup(TObject *Sender);
	void __fastcall cxCheckComboBox1PropertiesInitPopup(TObject *Sender);
	void __fastcall CheckBox2Click(TObject *Sender);
	void __fastcall chCalibProgramPropertiesEditValueChanged(TObject *Sender);
	void __fastcall ProfGridGeochronMouseMove(TObject *Sender,
		TShiftState Shift, int X, int Y);
	void __fastcall ProfGridGeochronMouseDown(TObject *Sender,
		TMouseButton Button, TShiftState Shift, int X, int Y);
	void __fastcall cxButton5Click(TObject *Sender);
	void __fastcall cxButton6Click(TObject *Sender);
	void __fastcall chCalibProgramPropertiesInitPopup(TObject *Sender);
	void __fastcall cxButton8Click(TObject *Sender);
	void __fastcall cxButton7Click(TObject *Sender);
	void __fastcall cxSpinEdit1PropertiesValidate(TObject *Sender,
		Variant &DisplayValue, TCaption &ErrorText, bool &Error);
	void __fastcall cxSpinEdit1PropertiesChange(TObject *Sender);
	void __fastcall cxPopupEdit13PropertiesInitPopup(TObject *Sender);
	void __fastcall cxButton9Click(TObject *Sender);
	void __fastcall cxPopupEdit13Exit(TObject *Sender);
	void __fastcall cxAspectButtonNClick(TObject *Sender);
	void __fastcall cxAspectButtonNNEClick(TObject *Sender);
	void __fastcall cxAspectButtonNEClick(TObject *Sender);
	void __fastcall cxAspectButtonENEClick(TObject *Sender);
	void __fastcall cxAspectButtonEClick(TObject *Sender);
	void __fastcall cxAspectButtonESEClick(TObject *Sender);
	void __fastcall cxAspectButtonSEClick(TObject *Sender);
	void __fastcall cxAspectButtonSSEClick(TObject *Sender);
	void __fastcall cxAspectButtonSClick(TObject *Sender);
	void __fastcall cxAspectButtonSSWClick(TObject *Sender);
	void __fastcall cxAspectButtonSWClick(TObject *Sender);
	void __fastcall cxAspectButtonWSWClick(TObject *Sender);
	void __fastcall cxAspectButtonWClick(TObject *Sender);
	void __fastcall cxAspectButtonWNWClick(TObject *Sender);
	void __fastcall cxAspectButtonNWClick(TObject *Sender);
	void __fastcall cxAspectButtonNNWClick(TObject *Sender);
	void __fastcall cxPopupEdit14PropertiesInitPopup(TObject *Sender);
	void __fastcall cxPopupEdit14Exit(TObject *Sender);
	void __fastcall mdSlopeAngle1Click(TObject *Sender);
	void __fastcall mdSlopeAspect1Click(TObject *Sender);
	void __fastcall cxPopupEdit13PropertiesValidate(TObject *Sender,
		Variant &DisplayValue, TCaption &ErrorText, bool &Error);
	void __fastcall cxPopupEdit14PropertiesValidate(TObject *Sender,
		Variant &DisplayValue, TCaption &ErrorText, bool &Error);
	void __fastcall cxPopupEdit12PropertiesInitPopup(TObject *Sender);
	void __fastcall mdSite1Click(TObject *Sender);
	void __fastcall cxTextEdit1Exit(TObject *Sender);
	void __fastcall cxTextEdit2Exit(TObject *Sender);
	void __fastcall cxMemo1Exit(TObject *Sender);
	void __fastcall cxMemo2Exit(TObject *Sender);
	void __fastcall ipwXMLp5EndElement(TObject *Sender,
		TipwXMLpEndElementEventParams *e);
	void __fastcall ipwXMLp5StartElement(TObject *Sender,
		TipwXMLpStartElementEventParams *e);
	void __fastcall ipwXMLp5Characters(TObject *Sender,
		TipwXMLpCharactersEventParams *e);
	void __fastcall ipwXMLp6Characters(TObject *Sender,
		TipwXMLpCharactersEventParams *e);
	void __fastcall ipwXMLp6EndElement(TObject *Sender,
		TipwXMLpEndElementEventParams *e);
	void __fastcall ipwXMLp6StartElement(TObject *Sender,
		TipwXMLpStartElementEventParams *e);
	void __fastcall ipwXMLp2Characters(TObject *Sender,
		TipwXMLpCharactersEventParams *e);
	void __fastcall ipwXMLp2EndElement(TObject *Sender,
		TipwXMLpEndElementEventParams *e);
	void __fastcall ipwXMLp2StartElement(TObject *Sender,
		TipwXMLpStartElementEventParams *e);
	void __fastcall NeotomaUploadAction1Execute(TObject *Sender);
	void __fastcall NeotomaValidateTaxaAction1Execute(TObject *Sender);
	void __fastcall NeotomaTaxaLookupAction1Execute(TObject *Sender);
	void __fastcall mdCollectionUnit1Click(TObject *Sender);
	void __fastcall mdLakeCharacteristics1Click(TObject *Sender);
	void __fastcall DataType1Click(TObject *Sender);
	void __fastcall SSAnalysisUnit1Click(TObject *Sender);
	void __fastcall SSCollectionUnitName1Click(TObject *Sender);
	void __fastcall SSCollectionUnitHandle1Click(TObject *Sender);
	void __fastcall SSSiteName1Click(TObject *Sender);
	void __fastcall PageControl1Changing(TObject *Sender, bool &AllowChange);
	void __fastcall Test1Click(TObject *Sender);
	void __fastcall mdAnalysisUnit1Click(TObject *Sender);
	void __fastcall mdSample1Click(TObject *Sender);
	void __fastcall mdDataset1Click(TObject *Sender);
	void __fastcall cxComboBox2PropertiesValidate(TObject *Sender, Variant &DisplayValue,
		TCaption &ErrorText, bool &Error);
	void __fastcall mdSampleName1Click(TObject *Sender);
	void __fastcall mdLabNumber1Click(TObject *Sender);
	void __fastcall mdPrepMethod1Click(TObject *Sender);
	void __fastcall mdSampleNotes1Click(TObject *Sender);
	void __fastcall cxBlobEdit2Exit(TObject *Sender);
	void __fastcall cxGrid3TableView1InitEdit(TcxCustomGridTableView *Sender, TcxCustomGridTableItem *AItem,
		TcxCustomEdit *AEdit);
	void __fastcall cxButton11Click(TObject *Sender);
	void __fastcall ProfGridCutCell(TProfGrid *Sender, TProfGridCell *Cell, bool &Allow);
	void __fastcall cxComboBox7Exit(TObject *Sender);
	void __fastcall cxComboBox8Exit(TObject *Sender);
	void __fastcall cxComboBox9Exit(TObject *Sender);
	void __fastcall cxComboBox10Exit(TObject *Sender);
	void __fastcall cxButton12Click(TObject *Sender);
	void __fastcall dxTreeViewEdit1Exit(TObject *Sender);
	void __fastcall dxTreeViewEdit2Exit(TObject *Sender);
	void __fastcall ShowDescription1Click(TObject *Sender);
	void __fastcall AdvControlDropDown2DropDownFooterButtonClick(TObject *Sender, int ButtonIndex);
	void __fastcall AdvControlDropDown2BeforeDropDown(TObject *Sender);
	void __fastcall AdvStringGridLakeEditChange(TObject *Sender, int ACol, int ARow,
		UnicodeString Value);
	void __fastcall AdvControlDropDown2BeforeDropUp(TObject *Sender);
	void __fastcall co_family_namePropertiesValidate(TObject *Sender, Variant &DisplayValue,
		TCaption &ErrorText, bool &Error);
	void __fastcall co_leading_initialsPropertiesValidate(TObject *Sender, Variant &DisplayValue,
		TCaption &ErrorText, bool &Error);
	void __fastcall co_suffixPropertiesValidate(TObject *Sender, Variant &DisplayValue,
		TCaption &ErrorText, bool &Error);
	void __fastcall cxButton13Click(TObject *Sender);
	void __fastcall cxButton14Click(TObject *Sender);
	void __fastcall cxButton15Click(TObject *Sender);
	void __fastcall cxButton16Click(TObject *Sender);
	void __fastcall co_family_namePropertiesButtonClick(TObject *Sender, int AButtonIndex);
	void __fastcall ContactsGridCardView1DataControllerCompare(TcxCustomDataController *ADataController,
		int ARecordIndex1, int ARecordIndex2, int AItemIndex,
		const Variant &V1, const Variant &V2, int &Compare);
	void __fastcall cxComboBox14Click(TObject *Sender);
	void __fastcall NeotomaHierarchyCheckAction1Execute(TObject *Sender);
	void __fastcall NeotomaModifiersAction1Execute(TObject *Sender);
	void __fastcall cxComboBox3Click(TObject *Sender);
	void __fastcall cxComboBox3PropertiesCloseUp(TObject *Sender);
	void __fastcall AdvControlDropDown3BeforeDropDown(TObject *Sender);
	void __fastcall AdvControlDropDown3DropDownFooterButtonClick(TObject *Sender, int ButtonIndex);
	void __fastcall AdvControlDropDown3DropUp(TObject *Sender, bool Cancelled);
	void __fastcall AdvControlDropDown3Exit(TObject *Sender);
	void __fastcall cxComboBox12Click(TObject *Sender);
	void __fastcall cxCheckListBox1DblClick(TObject *Sender);
	void __fastcall AdvControlDropDown4BeforeDropDown(TObject *Sender);
	void __fastcall AdvControlDropDown4DropDownFooterButtonClick(TObject *Sender, int ButtonIndex);
	void __fastcall AdvControlDropDown4DropDownHeaderButtonClick(TObject *Sender, int ButtonIndex);
	void __fastcall AdvControlDropDown4Exit(TObject *Sender);
	void __fastcall cxCheckComboBox8PropertiesCloseUp(TObject *Sender);
	void __fastcall AdvColumnGrid1DblClick(TObject *Sender);
	void __fastcall NeotomaLookupAction1Execute(TObject *Sender);
	void __fastcall NeotomaGeoPoliticalLookupAction1Execute(TObject *Sender);
	void __fastcall NeotomaEditTaxaTableAction1Execute(TObject *Sender);
	void __fastcall NeotomaEditPublicationsTableAction1Execute(TObject *Sender);
	void __fastcall mdMixed1Click(TObject *Sender);
	void __fastcall mdIGSN1Click(TObject *Sender);
	void __fastcall mdAnalUnitNotes1Click(TObject *Sender);
	void __fastcall mdDepAgent1Click(TObject *Sender);
	void __fastcall EditFaciesAction1Execute(TObject *Sender);
	void __fastcall EditDepAgentAction1Execute(TObject *Sender);
	void __fastcall cxCheckBox1Click(TObject *Sender);
	void __fastcall CalibProgramGetDisplayText(TcxCustomGridTableItem *Sender, TcxCustomGridRecord *ARecord,
		UnicodeString &AText);
	void __fastcall cxGrid3TableView2DataControllerAfterPost(TcxCustomDataController *ADataController);
	void __fastcall chGeochronGetDisplayText(TcxCustomGridTableItem *Sender, TcxCustomGridRecord *ARecord,
		UnicodeString &AText);
	void __fastcall CalibrateAction1Execute(TObject *Sender);
	void __fastcall txCalibProgramPropertiesCloseUp(TObject *Sender);
	void __fastcall txCalibProgramPropertiesEditValueChanged(TObject *Sender);
	void __fastcall txCalibProgramPropertiesInitPopup(TObject *Sender);
	void __fastcall txCalibProgramPropertiesPopup(TObject *Sender);
	void __fastcall cxButton17Click(TObject *Sender);
	void __fastcall cxGrid2TableView2FocusedItemChanged(TcxCustomGridTableView *Sender,
		TcxCustomGridTableItem *APrevFocusedItem, TcxCustomGridTableItem *AFocusedItem);
	void __fastcall cxButton18Click(TObject *Sender);
	void __fastcall txFractionPropertiesInitPopup(TObject *Sender);
	void __fastcall geParamsPropertiesInitPopup(TObject *Sender);
	void __fastcall AdvColumnGrid3GetEditorType(TObject *Sender, int ACol, int ARow,
		TEditorType &AEditor);
	void __fastcall AdvColumnGrid3CellValidate(TObject *Sender, int ACol, int ARow,
		UnicodeString &Value, bool &Valid);
	void __fastcall cxGrid2TableView1DataControllerBeforePost(TcxCustomDataController *ADataController);
	void __fastcall cxButton19Click(TObject *Sender);
	void __fastcall cxButton20Click(TObject *Sender);
	void __fastcall ImportClamAction1Execute(TObject *Sender);
	void __fastcall cxCheckComboBox9PropertiesInitPopup(TObject *Sender);
	void __fastcall cxCheckComboBox9PropertiesPopup(TObject *Sender);
	void __fastcall cxCheckComboBox9PropertiesCloseUp(TObject *Sender);
	void __fastcall cxButton21Click(TObject *Sender);
	void __fastcall cxButton22Click(TObject *Sender);
	void __fastcall AdvColumnGrid4RowChanging(TObject *Sender, int OldRow, int NewRow,
		bool &Allow);
	void __fastcall AdvColumnGrid4DblClickCell(TObject *Sender, int ARow, int ACol);
	void __fastcall cxCheckListBox1ClickCheck(TObject *Sender, int AIndex, TcxCheckBoxState APrevState,
		TcxCheckBoxState ANewState);
	void __fastcall AdvColumnGrid3GetEditorProp(TObject *Sender, int ACol, int ARow,
          TEditLink *AEditLink);
	void __fastcall cxButton24Click(TObject *Sender);
	void __fastcall cxButton25Click(TObject *Sender);
	void __fastcall cxButton26Click(TObject *Sender);
	void __fastcall cxRadioButton1Click(TObject *Sender);
	void __fastcall cxRadioButton2Click(TObject *Sender);
	void __fastcall cxComboBox1Exit(TObject *Sender);
	void __fastcall cxButton27Click(TObject *Sender);
	void __fastcall cxComboBox13PropertiesCloseUp(TObject *Sender);
	void __fastcall cxButton28Click(TObject *Sender);
	void __fastcall cxButton29Click(TObject *Sender);
	void __fastcall cxComboBox15Exit(TObject *Sender);
	void __fastcall Synonyms1Click(TObject *Sender);
	void __fastcall TaxonNotes1Click(TObject *Sender);
	void __fastcall cxBlobEdit1PropertiesCloseUp(TObject *Sender);
	void __fastcall cxCheckComboBox10PropertiesInitPopup(TObject *Sender);
	void __fastcall cxCheckComboBox10PropertiesCloseUp(TObject *Sender);
	void __fastcall ImportChronologiesTabsheet1Execute(TObject *Sender);
	void __fastcall Login1Click(TObject *Sender);
	void __fastcall dxTreeViewEdit1Click(TObject *Sender);
	void __fastcall AdvColumnGrid2CheckBoxChange(TObject *Sender, int ACol, int ARow,
          bool State);
	void __fastcall UpdateVariable1Click(TObject *Sender);
	void __fastcall DeleteVariable1Click(TObject *Sender);
	void __fastcall cxButton30Click(TObject *Sender);
	void __fastcall cxRadioButton7Click(TObject *Sender);
	void __fastcall cxRadioButton8Click(TObject *Sender);
	void __fastcall cxGrid3TableView1NavigatorButtonsButtonClick(TObject *Sender, int AButtonIndex,
          bool &ADone);
	void __fastcall cxGrid3TableView1FocusedRecordChanged(TcxCustomGridTableView *Sender,
          TcxCustomGridRecord *APrevFocusedRecord, TcxCustomGridRecord *AFocusedRecord,
          bool ANewItemRecordFocusingChanged);
	void __fastcall TabSheetLOIShow(TObject *Sender);
	void __fastcall AdvColumnGrid5CellValidate(TObject *Sender, int ACol, int ARow,
          UnicodeString &Value, bool &Valid);
	void __fastcall ToolButton1Click(TObject *Sender);
	void __fastcall ToolButton2Click(TObject *Sender);
	void __fastcall ToolButton3Click(TObject *Sender);
	void __fastcall ToolButton4Click(TObject *Sender);
	void __fastcall ToolButton6Click(TObject *Sender);
	void __fastcall ToolButton9Click(TObject *Sender);
	void __fastcall AdvColumnGrid5KeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall AdvColumnGrid5ClipboardBeforePasteCell(TObject *Sender, int ACol,
          int ARow, UnicodeString &Value, bool &Allow);
	void __fastcall cxButton31Click(TObject *Sender);
	void __fastcall AdvColumnGrid5AutoAddRow(TObject *Sender, int ARow);
	void __fastcall cxPopupEdit12KeyUp(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall Specimens1Click(TObject *Sender);
	void __fastcall ImportAllSpecimens1Click(TObject *Sender);
	void __fastcall InsertSingleSpecimen1Click(TObject *Sender);
	void __fastcall HTMLCheckBox1Click(TObject *Sender);
	void __fastcall FormControlEditLinkPretreatGetEditorValue(TObject *Sender, TAdvStringGrid *Grid,
          UnicodeString &AValue);
	void __fastcall FormControlEditLinkPretreatSetEditorValue(TObject *Sender, TAdvStringGrid *Grid,
          UnicodeString AValue);
	void __fastcall AdvColumnGridPretreatGetEditorType(TObject *Sender, int ACol, int ARow,
          TEditorType &AEditor);
	void __fastcall AdvColumnGridPretreatComboChange(TObject *Sender, int ACol, int ARow,
          int AItemIndex, UnicodeString ASelection);
	void __fastcall AdvColumnGridPretreatGetCellColor(TObject *Sender, int ARow, int ACol,
          TGridDrawState AState, TBrush *ABrush, TFont *AFont);
	void __fastcall AdvColumnGridPretreatCanEditCell(TObject *Sender, int ARow, int ACol,
          bool &CanEdit);
	void __fastcall AdvControlDropDownPretreatmentBeforeDropDown(TObject *Sender);
	void __fastcall AdvControlDropDownPretreatmentBeforeDropUp(TObject *Sender);
	void __fastcall AdvControlDropDownPretreatmentDropDownFooterButtonClick(TObject *Sender,
          int ButtonIndex);
	void __fastcall AdvColumnGridPretreatGetEditorProp(TObject *Sender, int ACol, int ARow,
          TEditLink *AEditLink);
	void __fastcall SeriesMetadata1Click(TObject *Sender);
	void __fastcall AppendSingleSpecimen1Click(TObject *Sender);
	void __fastcall ToolButton10Click(TObject *Sender);
	void __fastcall ToolButton11Click(TObject *Sender);
	void __fastcall ToolButton12Click(TObject *Sender);
	void __fastcall ToolButton13Click(TObject *Sender);
	void __fastcall ToolButton14Click(TObject *Sender);
	void __fastcall ToolButton15Click(TObject *Sender);
	void __fastcall HTMLCheckBox2Click(TObject *Sender);
	void __fastcall HTMLCheckBox3Click(TObject *Sender);
	void __fastcall HTMLCheckBox4Click(TObject *Sender);
	void __fastcall HTMLCheckBox5Click(TObject *Sender);
	void __fastcall HTMLCheckBox6Click(TObject *Sender);
	void __fastcall txUserSpecimenIDPropertiesValidate(TObject *Sender, Variant &DisplayValue,
		  TCaption &ErrorText, bool &Error);
	void __fastcall NullToZero1Execute(TObject *Sender);
	void __fastcall txUserSpecimenIDGetCellHint(TcxCustomGridTableItem *Sender, TcxCustomGridRecord *ARecord,
          TcxGridTableDataCellViewInfo *ACellViewInfo, const TPoint &AMousePos,
          TCaption &AHintText, bool &AIsHintMultiLine, TRect &AHintTextRect);
	void __fastcall ToolButton17Click(TObject *Sender);
	void __fastcall ToolButton19Click(TObject *Sender);
	void __fastcall ToolButton21Click(TObject *Sender);
	void __fastcall ToolButton23Click(TObject *Sender);
	void __fastcall ToolButton25Click(TObject *Sender);
	void __fastcall ToolButton27Click(TObject *Sender);
	void __fastcall cxCheckComboBox5PropertiesCloseUp(TObject *Sender);
	void __fastcall cxButton33Click(TObject *Sender);
	void __fastcall ProfGrid1PastePlainText(TProfGrid *Sender, int ACol, int ARow, WideString &AText,
          bool &CanPaste);
	void __fastcall ProfGrid1BeforePaste(TObject *Sender);
	void __fastcall CheckBox1Click(TObject *Sender);
	void __fastcall cxCheckBox2Click(TObject *Sender);
	void __fastcall cxCheckBox3Click(TObject *Sender);
	void __fastcall CheckBox3Click(TObject *Sender);
	void __fastcall AdvIsotopeStringGridGetAlignment(TObject *Sender, int ARow, int ACol,
          TAlignment &HAlign, TVAlignment &VAlign);
	void __fastcall AdvIsotopeStringGridGetCellColor(TObject *Sender, int ARow, int ACol,
          TGridDrawState AState, TBrush *ABrush, TFont *AFont);
	void __fastcall AdvIsotopeStringGridGetCellGradient(TObject *Sender, int ARow, int ACol,
          TColor &Color, TColor &ColorTo, TColor &ColorMirror, TColor &ColorMirrorTo,
          TCellGradientDirection &GD);
	void __fastcall AdvIsotopeStringGridGetDisplText(TObject *Sender, int ACol, int ARow,
          UnicodeString &Value);
	void __fastcall AdvIsotopeStringGridTopLeftChanged(TObject *Sender);
	void __fastcall AdvIsotopeStringGridGetEditorType(TObject *Sender, int ACol, int ARow,
          TEditorType &AEditor);
	void __fastcall AdvIsotopeStringGridGetEditorProp(TObject *Sender, int ACol, int ARow,
          TEditLink *AEditLink);
	void __fastcall AdvIsotopeStringGridComboChange(TObject *Sender, int ACol, int ARow,
          int AItemIndex, UnicodeString ASelection);
	void __fastcall AdvIsotopeStringGridClipboardAfterPasteCell(TObject *Sender, int ACol,
          int ARow, UnicodeString Value);
	void __fastcall AdvIsotopeStringGridCanEditCell(TObject *Sender, int ARow, int ACol,
          bool &CanEdit);
	void __fastcall AdvIsotopeStringGridCellValidate(TObject *Sender, int ACol, int ARow,
          UnicodeString &Value, bool &Valid);
	void __fastcall AdvIsotopeStringGridCellChanging(TObject *Sender, int OldRow, int OldCol,
          int NewRow, int NewCol, bool &Allow);
	void __fastcall AdvIsotopeStringGridKeyUp(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall AdvIsotopeStringGridSelectionChanged(TObject *Sender, int ALeft,
          int ATop, int ARight, int ABottom);
	void __fastcall AdvIsotopeStringGridMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
	void __fastcall AdvIsotopeStringGridMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
	void __fastcall AdvIsotopeStringGridFixedCellClick(TObject *Sender, int ACol, int ARow);
	void __fastcall AdvIsotopeStringGridResize(TObject *Sender);
	void __fastcall AdvIsotopeStringGridColumnSizing(TObject *Sender, int ACol, int ColumnSize);
	void __fastcall mdDateSampled1Click(TObject *Sender);
	void __fastcall mdTaxonSampled1Click(TObject *Sender);
	void __fastcall Specimens2Click(TObject *Sender);
	void __fastcall cxGrid2TableView1DataControllerDetailExpanding(TcxCustomDataController *ADataController,
          int ARecordIndex, bool &AAllow);
	void __fastcall cxPopupEdit1PropertiesInitPopup(TObject *Sender);
	void __fastcall cxPopupEdit1PropertiesCloseUp(TObject *Sender);
	void __fastcall AdvColumnGrid6CanEditCell(TObject *Sender, int ARow, int ACol, bool &CanEdit);
	void __fastcall AdvColumnGrid6CheckBoxChange(TObject *Sender, int ACol, int ARow,
          bool State);
	void __fastcall AdvColumnGrid6HoverButtonClick(TObject *Sender, int ARow, THoverButtonsCollectionItem *AButton);
	void __fastcall cxButton23Click(TObject *Sender);
	void __fastcall AdvColumnGrid4HoverButtonClick(TObject *Sender, int ARow, THoverButtonsCollectionItem *AButton);
	void __fastcall AdvColumnGrid2HoverButtonClick(TObject *Sender, int ARow, THoverButtonsCollectionItem *AButton);
	void __fastcall AdvColumnGrid2HoverButtonsShow(TObject *Sender, int X, int Y, bool &Allow);
	void __fastcall cxCheckBox4Click(TObject *Sender);
	void __fastcall cxGrid2TableView2DataControllerAfterPost(TcxCustomDataController *ADataController);
	void __fastcall DefaultDiagramAction1Execute(TObject *Sender);
	void __fastcall WebServices1Click(TObject *Sender);
	void __fastcall ShowNeotomaIDs1Click(TObject *Sender);
	void __fastcall AssignWhitmore1Click(TObject *Sender);
	void __fastcall cxButton38Click(TObject *Sender);
	void __fastcall cxButton34Click(TObject *Sender);
	void __fastcall cxButton35Click(TObject *Sender);
	void __fastcall cxButton36Click(TObject *Sender);
	void __fastcall cxButton37Click(TObject *Sender);
	void __fastcall WhitmoreAction1Execute(TObject *Sender);
	void __fastcall RemoveWhitmoreSample1Click(TObject *Sender);
	void __fastcall cxButton39Click(TObject *Sender);
	void __fastcall mdBottom1Click(TObject *Sender);
	void __fastcall Metadata1Click(TObject *Sender);
	void __fastcall cxGrid3TableView2DataControllerBeforeDelete(TcxCustomDataController *ADataController,
          int ARecordIndex);
	void __fastcall CounterAction1Execute(TObject *Sender);
	void __fastcall ipsJSONS1SSLServerAuthentication(TObject *Sender, TipsJSONSSSLServerAuthenticationEventParams *e);
	void __fastcall chAnalUnitIDPropertiesCloseUp(TObject *Sender);
	void __fastcall chAnalUnitIDPropertiesPopup(TObject *Sender);
	void __fastcall cxButton40Click(TObject *Sender);
	void __fastcall cxButton41Click(TObject *Sender);
	void __fastcall AdvColumnGrid7DblClick(TObject *Sender);
	void __fastcall AdvColumnGrid8DblClick(TObject *Sender);
	void __fastcall cxButton42Click(TObject *Sender);
	void __fastcall cxButton43Click(TObject *Sender);
	void __fastcall geAnalUnitIDPropertiesPopup(TObject *Sender);
	void __fastcall geAnalUnitIDPropertiesCloseUp(TObject *Sender);
	void __fastcall ImportBaconAction1Execute(TObject *Sender);
	void __fastcall ImportBchronAction1Execute(TObject *Sender);
	void __fastcall AdvColumnGrid9ClickCell(TObject *Sender, int ARow, int ACol);
	void __fastcall ImportOxCalAction1Execute(TObject *Sender);
	void __fastcall cxGrid2TableView1CellClick(TcxCustomGridTableView *Sender, TcxGridTableDataCellViewInfo *ACellViewInfo,
          TMouseButton AButton, TShiftState AShift,
          bool &AHandled);

private:	// User declarations
	bool XMLLookUpError;
	int nCountries;
	UnicodeString XMLFileName;
	bool ActiveCellChanging;
	bool TopLeftChanging;
	bool Scrolling;
	bool ResetCol;
	bool ResetRow;
	bool Resizing;
	bool WholeSheetSelected;
	bool EndKey;
	bool NewAgeModels;
	bool AllowRowColSelection;
	TPoint NewCell;
	bool ColBlk, RowBlk, SheetBlk;
	TRect ColRowBlk;
	bool Modified;
	short DMSStyle;
	DMSPANEL *dms;
	vector<bool> PubCheckStates;
	vector<bool> PrepCheckStates;
	map<UnicodeString,Variant> NewGeochronParams;;
	vector<int> Reorder;
	UnicodeString NewRecordPubText;
	UnicodeString NewRecordPrepText;
	CALIBRATION NewRecordCalibProgram;
	vector<int> NewGeochronIDs;
	UnicodeString CurrentCountry;
	UnicodeString CurrentState;
	UnicodeString CurrentSSCountry;
	UnicodeString CurrentSSState;
	TList* Sums;
	TList* SSums;
	TContactDataSource* ContactDataSource;
	SPREADSHEETCELL ssc;
	bool ProcessComboBox7OnExit;
	bool ProcessComboBox8OnExit;
	bool ComboBox7Clicked;
	bool ComboBox8Clicked;
	PARSEXMLSAX SAX;
	GEOPOLRECORD* GeoPolRec;
	GEOPOLITICAL* GeoPolUnits;
	TStringList* AdminUnitTypes;
	CONTACT *xml_contact;
	PUBLICATION *xml_pub;
	SPECIMEN *xml_specimen;
	AUTHOR *xml_author;
	SUBMISSION *xml_submission;
	AGEMODEL *xml_agemodel;
	int xml_chron_number;
	CHRON *xml_chron_control;
	LITHOLOGYUNIT *xml_lithunit;
	TProfGrid *xml_ProfGrid;
	TList* xml_Specimens;
	SPECIMEN* xml_Specimen;
	TAPHSYSTEMS* xml_TaphSystems;
	MANAGEPROGRESSBAR* CurrentProgressBar;
	set<UnicodeString> DataTypes;
	vector<UnicodeString> FaciesTypes;
	vector<UnicodeString> DepAgents;
	bool DataTypeCornerClicked;
	bool StartUp;
	TColor clFrozenBackground;
	VERSION xml_Version;
	VERSION temp_Version;
	int CurrentRowHeight;
	TElementForm* ElementForm;
	UnicodeString CurrentTaxaFile;
	UnicodeString EditingText;
	int SSAction;
	TcxPopupEdit* chAgeBasisPopupEdit;
	bool cxTreeView1CanSelect;
	TList* RelativeAges;
	TStringList* ArchAges;
	TStringList* ArchAgeScales;
	AGEBASIS AgeBasis;
	TcxCustomGridTableView *CurrentChronControlView;
	TList *Events;
	static int __fastcall EventNameCompare(void*, void*);
	static int __fastcall EventCalAgeCompare(void*, void*);
	vector<XMLEVENT> xmlEventTypes;
	TTreeNode* CurrentNode;
	int EditAgeBasisList;
	bool AgeBasisListChanged;
	bool DepEnvListChanged;
	bool tlxRow2;
	bool tlxRow3;
	UnicodeString GridPaste;
	UnicodeString xml_TaxaTitle;
	PARSETAXA* ParseTaxa;
	TcxTreeView* cxAgeBasisTreeView;
	bool NewTaphonomicClasses;
	int LatLongPopup;
	TcxPopupEdit* LatLongPopupEdit;
	TProfGrid* ProfGrid2;
	TProfGrid* ConcGrid;
	TProfGrid* InfluxGrid;
	vector<SSMETADATAID> SSContacts;
	vector<SSMETADATAID> SSPubs;
	vector<SSMETADATAID> SSSpecimens;
	list<UNDO> UnDo;
	UNDOSELECTION UndoSelection;
	short PasteError;
	bool CheckBoxUndoEnabled;
	TTreeNode* PrevSubstrateNode;
	TStringList* SubstrateDescriptions;
	list<LAKEPARAMETER> LakeChar;
	TcxPopupEdit* chCalibProgramPopupEdit;
    TcxPopupEdit* txCalibProgramPopupEdit;
	bool CalibProgramSelected;
	map<TWinControl*, CONTROLPROPERTIES> InitialControlProperties;
	TList* Sites;
	TList* ValidatedSites;
	SITE* SitePtr;
	vector<COLLECTION>::pointer CollPtr;
	ParseXMLUnicode* xmlin;
	GEOPOLITICALXML* gpx;
	TLXXML* tlx;
	TAXAXML* txml;
	map<UnicodeString, int> Synonyms;   // synonym, accepted name ID
	multimap<int, UnicodeString> MultiSynonyms; // accepted name ID, synonym
	list<CELLOBJECT*> CellObjects;
	list<CELLOBJECT*> CutObjects;
	int HeaderRow2;
	bool HeaderNameEntered;
	int DatasetNum;
	bool MetadataPaste;
	CELLPASTED CellPasted;
	UnicodeString InitialCollName;
	bool ShowTaxonNotes;
	UnicodeString Row2HintStr;
	bool LakeParamChanged;
	bool MoreElements;
	short ModifierType;
	short TaphStatus;
	bool TaphonomyPosted;
	TAPHSYSTEMS* TempTaphSystems;
	UnicodeString CurrentTaphSystem;
	UnicodeString CurrentTaxaGroup;
	UnicodeString SpecimenTaxaGroup;
	// UnicodeString OriginalTaxonName;
	NEOTOMAVARIABLEPARTS VarBeforeEdit;
	UnicodeString OriginalTaxonNotes;
	int AdvColumnGridAction;
	TPoint TaxonNotesPos;
	struct { UnicodeString text; int pos; } TaxonName;
	vector<UnicodeString> SampleKeywords;
	int SampModernRow;
	short CalibProgramPopup;
	vector<UnicodeString> GeochronTypes;
	vector<GEOCHRONPARAM> RadiocarbonParams;
	map<int,UnicodeString> NeotomaContactStatuses;
	TcxPopupEdit* geParamsPopupEdit;
	set<UnicodeString> IsoMaterialsAnalyzed;
	multimap<UnicodeString,UnicodeString> IsoSubstrates;
	multimap<UnicodeString,UnicodeString> IsoPretreatments;
	set<UnicodeString> IsoSamplingOrigins;
	set<UnicodeString> IsoInstrumentation;
	set<UnicodeString> IsoSampleIntroSystems;
	set<UnicodeString> SpecimenSex;
	set<UnicodeString> DomesticStatus;
	vector<ISOTOPESERIES*> IsotopeSeries;
	map<UnicodeString,UnicodeString> IsoStandards;
	multimap<UnicodeString,UnicodeString> IsoBioMarkers;
	multimap<UnicodeString,UnicodeString> IsoTypeVariables;
	TRect NewIsoGridSelection;
	bool IsoGridShiftClickSelection;
	vector<TPoint> IsoFixedSelected;
	bool IsoRowSelected;
	bool IsoMultiRowsSelected;
	map<short,ISOMETADATA> IsoMetadata;
	map<short,pair<int,int> > IsoCols;  // columns for worksheet; pair is first col, last col
	map<UnicodeString,UnicodeString> Repositories;     // institution, acronym
	map<UnicodeString,UnicodeString> RepositoryNotes;  // acronym, notes
	set<int> SpecimenIDs;
	bool Downloaded;
	vector<pair<int,int> > DownloadPasteCells;  // col, row
	struct { bool Pasting; bool Error; int Row; int n; int ncols; } DownloadPaste;
	THoverButtonsCollection* RepHoverButtons;
	THoverButtonsCollection* SpecHoverButtons;
	CHRON *InitChronControl;
	struct { bool MultiSite; int SiteCol; int SiteRow; int FirstCol; int LastCol; } CurrSS;
	struct { int SiteID; int CollectionUnitID; map<int,int> Datasets; } EPD;
	vector<NTMANALYSISUNIT> AllAnalUnits;
private:
	static bool SSVARComp (SSVAR sv1, SSVAR sv2) { return (sv1.name < sv2.name); }
	//vector<SSVAR>::pointer __fastcall FindSSVAR(UnicodeString&);
	void __fastcall GenerateContactColumns();
	TLithologyUnitDataSource* LithologyUnitDataSource;
	void __fastcall GenerateLithologyUnitColumns();
	TGeochronDataSource* GeochronDataSource;
	TTaxonDatedDataSource* TaxonDatedDataSource;
	void __fastcall GenerateGeochronColumns();
	TAgeModelDataSource* AgeModelDataSource;
	TChronDataSource* ChronDataSource;
	void __fastcall GenerateAgeModelColumns();
	void EditPublication(void);
	void AddAuthorsToContacts(vector<AUTHOR>&);
	static int __fastcall CitationCompare(void*, void*);
	static int __fastcall SubmissionCompare(void*, void*);
	void CheckPublicationLinkage(PUBLICATION*);
	void ParseSITFormData(void);
	void SetStateProvinceList(void);
	void SetCountyList(void);
	void SetAdminUnitList1(void);
	void SetAdminUnitList2(void);
	void SetAdminUnitList3(void);
	void SetGeoPolCaption(UnicodeString, UnicodeString, TcxComboBox*, TLabel*);
	bool GetLookupItems(void);
	bool GetLookupEvents(ParseXMLUnicode*, TTreeNode*, XMLEVENT&, XMLSubElement&, int);
	void BuildTree(vector<TREENODE>&, TcxTreeView*);
	void BuilddxTree(vector<TREENODE>&, TdxTreeView*);
	void BuilddxTreeViewEdit(vector<TREENODE>&, TdxTreeViewEdit*);
	UnicodeString SaveLookupFile(void);
	void UpdatePublications(TcxCheckComboBox*, vector<PUBLICATION*>&);
	void UpdatePublications(TcxCheckComboBoxItems*, TStringList*);
	void UpdatePublications(TcxCheckComboBoxItems*, map<UnicodeString, PUBLICATION*>&);
	void UpdatePublications(TStrings*, map<UnicodeString, PUBLICATION*>&);
	UnicodeString __fastcall getPubShortDescription(PUBLICATION*);
	void __fastcall CheckDuplicateCitations(vector<PUBCITATION>& PubList);
	void UpdateContacts(TcxCheckComboBox*, vector<CONTACT*>&);
	void NewPublication(void);
	CONTACT* NewContact(void);
	CONTACT* NewContact(UnicodeString Name);
	CONTACT* NewContact(UnicodeString FamilyName, UnicodeString Initials);
	UnicodeString Paste;
	bool __fastcall SetLithUnitItem(LITHOLOGYUNIT*, UnicodeString&, int);
	int __fastcall ExitLOITemp(TComboBox* ComboBox, int col);
	void FillMetaData(void);
	void FillSiteMetaData(SITE* site_ptr);
	void FillCollUnitMetaData(void);
	void FillDatasetMetaData(int dataset_num);
	void GetSSSiteMetaData(void);
	void SpecialFormating();
	void ReformatElements(void);
	void XMLParsingStatus(UnicodeString);
	//void AddVarChange(TList*, int, UnicodeString, UnicodeString);
	TErrorListForm* GetErrorListForm(UnicodeString, UnicodeString, TModalResult,
		UnicodeString, TModalResult, int, TStringList*);
	void SortSampleNumbers(TProfGrid*);
	void SortSampleNames(void);
	void SortRows(int sort_col, TProfGrid* Grid);
	void SortRows(int abs_sort_col, TStringList* SortOrder, TProfGrid* Grid);
	int CalcPercentsError(int, int);
	bool ParseTLXFile(UnicodeString&);
	bool ParseTLXSSOptions(void);
	bool ParseTLXContacts(void);
	bool ParseTLXPublications(void);
	bool ParseTLXSpecimens(void);
	bool ParseTLXSite(void);
	bool ParseTLXCollectionUnit(void);
	bool ParseTLXDataset(void);
	bool ParseTLXGeochronology(void);
	bool ParseTLXAgeModels(void);
	bool ParseTLXLithology(void);
	bool ParseTLXLOI(void);
	bool ParseTLXIsotopes(void);
	void ParseTLXIsotopeData1(int row, UTF8String XPath);
	void ParseTLXIsotopeData2(int row, short isotope, UTF8String XPath);
	void BuildTaphonomy(void);
	void ProcessSSPubs(void);
	void SingleSiteCheck(void);
	void __fastcall LakeCharacteristicMenuItem(TObject *Sender);
	//bool __fastcall SetUnitsCategory(UnicodeString&);
	//bool __fastcall SetContextCategory(UnicodeString&);
	bool __fastcall ProcessEndKey(WORD&, TProfGrid*);
	void LabelSSColumns(TProfGrid*, int);
	void ExpandArchTimeScale(void);
	void EditChronControl(TTreeNode*, UnicodeString);
	bool IsRelativeAge(TTreeNode*);
	bool IsEventAge(TTreeNode*);
	void __fastcall PasteGrid(TcxCustomGridTableView*);
	void __fastcall CutGrid(TcxGridTableView*);
	bool __fastcall AllCellsSelected(TcxGridTableView*);
	//bool LoadLookupTaxa(vector<TAXON>&, vector<TAXAECOLGROUPS>&);
	bool LoadLookupTaxa(TTaxaVector&, vector<TAXAECOLGROUPS>&);
	void EditTaxa(void);
	void EditGroups(void);
	void EditElements(void);
	void EditUnits(void);
	void EditContexts(void);
	void EditTaphonomy(void);
	void NewTaxa(void);
	void NewGroups(void);
	void NewElements(void);
	void NewUnits(void);
	void NewContexts(void);
	void NewTaphonomy(void);
	void MakeDiagram(void);
	void MakeDefaultDiagram(void);
	void Options(void);
	void ReorderSamples();
	void DeleteRelativeAges(void);
	void DeleteEvents(void);
	void DeleteChronControls(void);
	void SetLatitudeNorth(void);
	void SetLatitudeSouth(void);
	void SetLongitudeWest(void);
	void SetLongitudeEast(void);
	void SetLatitudeGPS(void);
	void SetLongitudeGPS(void);
	void DistBearingToLatLong(double, double, double, double, double*, double*);
	int FindRowCodeIC(UnicodeString Code, TProfGrid* ProfGrid, int StartRow=3);
	void AddUnDo(UNDO& undo);
	void SaveCells(TProfGrid*, TProfGridCell*);
	void WSDecimalPoints(UnicodeString, int);
	void EnterSSMetadataCode(UnicodeString, UnicodeString);
	//bool SSContactsMetaData(int, int);
	bool SSContactMetaData(int, int, UnicodeString);
	// bool SSPubMetaData(int, int);
	TList* InitCellContactsList(TProfGridCell*);
	void SetInitControlProperties(CONTROLPROPERTIES& cp, int left, int top, int width)
		{ cp.Left = left; cp.Top = top; cp.Width = width; }
	void InsertMedadataControls(TTabSheet*, TWinControl*);
	void EnableSSSiteMD(bool);
	void EnableSSCollUnitMD(bool);
	void MetaDataRowsExist(UnicodeString, set<UnicodeString>&, int start_row = 3);
	int FindSite(UnicodeString&);
	bool DecodeSSMD(double&, Variant&);
	bool DecodeSSMD(Variant&, Variant&);
	bool DecodeSSMD(int&, Variant&);
	bool DecodeSSMD(UnicodeString&, Variant&);
	void DecodeSSContacts(vector<CONTACT*>&, int, int);
	void EnterSSMetaData(UnicodeString&, Variant&, int, int);
	SITE* GetSSSitePtr(int, int&);
	void GetSSMetaDataItems(UnicodeString, TStringList*);
	void SiteMetaDataToSS(int ACol);
	void UpdateSSMD(UnicodeString, UnicodeString, UnicodeString,
		double&, int&, int&, vector<int>&, map<UnicodeString, int>&);
	void UpdateSSMD(UnicodeString, UnicodeString, UnicodeString,
		UnicodeString&, int&, int&, vector<int>&, map<UnicodeString, int>&);
	void UpdateSSMD(UnicodeString, UnicodeString, UnicodeString,
		Variant&, int&, int&, vector<int>&, map<UnicodeString, int>&);
	void CollUnitMetaDataToSS(int ACol);
	int GetMetaDataRows(UnicodeString, map<UnicodeString, int>&, int start_row = 3);
	bool MetaDataBounds(UnicodeString, int&, int&);
	bool EnterSSSite(Variant& Value, int ACol, int ARow, bool Query=true);
	void DeleteSSSiteName(Variant&, TProfGridCell*, int, int, bool);
	void AddSSSiteName(UnicodeString, TProfGridCell*, int);
	bool EnterSSCollUnit(Variant& Value, int ACol, int ARow);
	void DeleteSSCollName(Variant&, SITE*, TProfGridCell*, UnicodeString, int, int, int, bool);
	void AddSSCollName(SITE*, UnicodeString, TProfGridCell*, int, int);
	SITE* GetNextColSitePtr(int, int&, int, int);
	//bool UniqueCollUnitHandle(SITE*, UnicodeString, UnicodeString, int, int);
	bool UniqueCollUnitHandle(SITE* site_ptr, UnicodeString Handle, UnicodeString Name, int CurCol, int SiteRow);
	int FindRowMD(int);
	void ResetSSMetadata(void);
	void MoveHeaderRow2DataToSS(void);
	void MoveSSDataToHeaderRow2(int);
	bool CheckSelectionCut(TProfGridSelection*);
	int GetTreeViewCount(TcxTreeView*);
	int GetTreeViewCount(TdxTreeView*);
	int GetTreeViewCount(TdxTreeViewEdit*);
	void SetupNewAdminUnitForm(void);
	void ResetLakeParams(void);
	bool GetTaxon(int ARow, TAXON& Taxon);
	bool GetTaxon(UnicodeString TaxonName, TAXON& Taxon);
	bool GetGeochronTaxon(UnicodeString TaxonName, TAXON& Taxon);
	void PostElement(void);
	void PostTaphonomy(void);
	void CreateTaphSystems(TAPHSYSTEMS** TaphSystems);
	void CheckTaphonomy(void);
	UnicodeString GenericDatasetType(UnicodeString DatasetType);
	void SetDatasetNum(void);
	void SetModifiers(int);
	void FillEcolGroupsGrid(set<UnicodeString>* TaxaGroups);
	void SetEcolGroupsGridRow(void);
	//void ProcessTaxonNotes(int ARow, TAXON_NOTES* EditTaxonNotes);
	void ProcessTaxonNotes(int ARow, CELLOBJECT* CellObject);
	bool GridCellIsEmpty(TProfGridCell* ACell);
	void EditFacies(void);
	void EditDepAgents(void);
	UnicodeString FormatGeochronLinks(vector<int>& ChronControlIDs);
	void CheckHierarchy(void);
	bool GetSSVarList(vector<SSVAR>& SSVarList, bool SortByName, vector<UnicodeString>& ErrMsgs);
	void SortSSVarList(vector<SSVAR>& SSVarList);
	void CheckVarDuplicates(vector<SSVAR>& SSVarList, vector<DUPVAR>& DupVars);
	void AddCalibProgram(CALIBRATION& Calib);
	void CheckDatasetDelete(TProfGrid* Grid, int row, UNDO& undo);
	void DeleteSSMetadataItem(TProfGrid* Grid, int ARow);
	void EnterSSDataType(void);
	void CheckTLXDatasets(void);
	void FillPubGrid(void);
	bool GetNeotomaSite(int SiteID, SITE* SitePtr, set<int>* CollUnitIDs);
	bool GetNeotomaLithology(set<int>& CollUnitIDs);
	bool GetNeotomaDatasets(vector<DATASET>& Datasets, vector<MAPDATASET>& MapDatasets,
		vector<NTMDATASET>& neotoma_datasets, TList* Publications);
	bool GetNeotomaData(void);
	bool GetSampleAnalysts(map<int,CONTACT*>& ContactMap, NeotomaDatasetSampleAnalysts& SampleAnalysts);
	void GetLOITemp(int col, TComboBox* ComboBox);
	bool GetNeotomaGeochron(vector<NTMDATASET>& NeotomaDatasets);
	bool GetNeotomaChron(vector<NTMDATASET>& NeotomaDatasets);
	CONTACT* GetNeotomaContact(NTMCONTACT& ntm_contact);
	PUBLICATION* GetNeotomaPub(int DatasetID, TList* Publications, NTMPUBLICATION& ntm_pub);
	bool CreateLookupDirectory(UnicodeString LookupPath, bool& CreateDefaultLookupFiles);
	bool LookupFileExists(UnicodeString Path, bool CreateDefaultLookupFiles);
	bool GeopoliticalLookupFileExists(UnicodeString Path, bool CreateDefaultLookupFiles);
	bool VariableModifiersLookupFileExists(UnicodeString Path, bool CreateDefaultLookupFiles);
	int DatasetTabsheetNum(void);
	int GetCurrentDataset(int ARow);
	int GetCurrentDatasetHeaderRow(int ARow);
	void GetDatasetRows(int DatasetNo, pair<int,int>& DatasetRows);
	void AddTaxonNotesIcon(TProfGridCell* ACell);
	// bool ValidateSteward(int& NeotomaVariableID, int& DatasetIdx);
	void DeleteNeotomaChron(int ChronNo, int NeotomaChronologyID, UnicodeString ChronName);
	void ExportLOIData(int col, LOISAMPLE loi_sample, LOIROW loi_row);
	int getnthk(double thickness, vector<pair<double,int> >& thk);
	void AppendLOISampleToSpreadsheet(int& EndCol, double loidepth, LOISAMPLE loi_sample,
		LOIROW loi_row, int thkrow);
	void AfterGridPaste(UnicodeString text, TcxGridTableView* cxGridTableView);
	void UpdateNeotomaChronology(AGEMODEL* AgeModel);
	void UpdateNeotomaGeochron(GEOCHRON& Date);
	void UpdateGeochronPIs(set<int>& NewContactIDs);
	void DeleteGeochron(int GeochronID);
	void UploadNeotomaGeochron(GEOCHRON& Date);
	void UploadTaxonDated(int GeochronID, TAXONDATED& TaxonDated);
	void UpdateTaxonDated(TAXONDATED& TaxonDated);
	bool GetTaxonID(NEOTOMAVARIABLEPARTS& Variable);
	bool GetTaxonID(UnicodeString TaxonName, int& TaxonID, UnicodeString& TaxaGroupID);
	bool GetElementTypeID(UnicodeString ElementType, int TaxonID, UnicodeString TaxonName,
		int& ElementTypeID);
	bool GetFractionID(UnicodeString Fraction, int& FractionID);
	bool GetGeochronIDs(GEOCHRON& Date, int& GeochronTypeID, int& AgeTypeID);
	bool ValidateDate(GEOCHRON& Date);
	void UploadChronControl(int ChronologyID, CHRON* ChronControl);
	void UpdateChronControl(CHRON* ChronControl, AGEMODEL* AgeModel);
	void InsertChronControl(CHRON* ChronControl, AGEMODEL* AgeModel);
	void DeleteChronControl(int ChronControlID);
	bool IsAgeYounger(Variant vAge, Variant vAgeOlder, UnicodeString AgeUnits);
	bool IsAgeOlder(Variant vAge, Variant vAgeYounger, UnicodeString AgeUnits);
	bool GetCollPtr(void);
	bool UpdateSampleAnalysisUnit(GEOCHRON& Date, int SampleID, int NewAnalysisUnitID,
		int OldAnalysisUnitID);
	bool UploadAnalysisUnit(GEOCHRON& Date, int& AnalysisUnitID);
	bool UploadAnalysisUnit(NEOTOMAANALUNIT& AnalUnit);
	int GetSampleID(int ACol, int ARow);
	bool GetDateAnalysisUnitID(GEOCHRON& Date, int& AnalysisUnitID);
	bool GetRadiocarbonParams(GEOCHRON& Date, map<UnicodeString,double>& RadiocarbonParams);
	bool IsSameGeochron(int GeochronTypeID, int AgeTypeID, GEOCHRON& Date, NTMGEOCHRON& NtmDate);
	void UpdateRadiocarbonParams(GEOCHRON& Date);
	void GetProfGridFormLoc(TProfGrid* Grid, int Height, int Width, TPoint& FormPos);
	void GetAdvGridFormLoc(TAdvStringGrid* Grid, int Height, int Width, TPoint& FormPos);
	void ImportIsotopeSpecimen(int col, int row, int& specrow);
	void SetupIsotopeGrid(void);
	short GetIsotopeColumn(int ACol);
	bool SetIsotopePretreatments(UnicodeString& DisplayText, bool ShowError);
	void ShowIsoMetadataForm(TToolButton* ToolButton, short isotope);
	void CheckIsotopeDataset(void);
	//void ProcessSSContact(int ACol, int ARow, TcxCheckComboBox* cxCheckComboBox);
	bool HasGeochronLink(SPECIMEN* Specimen);
	bool DeleteGeochronLink(SPECIMEN* Specimen);
	void AddCellObject(TProfGridCell* ACell, CELLOBJECT* CellObject);
	void DeleteCellObject(TProfGridCell* ACell);
	void ClearCutObjects(void);
	//UnicodeString GetSpecimenNr(SPECIMEN* specimen);
	SPECIMEN* GetSpecimen(int SpecimenID);
	UnicodeString MakeSentence(UnicodeString phrase);
	void EPDWorker(int WorkerNr, map<int,CONTACT*>& Workers);
	void EPDPublToPub(EPDPUBL& Publ, PUBLICATION* pub, map<int,CONTACT*>& Workers);
	bool ValidateSteward(int& DatasetIdx);
	// void UpdateVariableUnits(int DatasetIdx, UnicodeString NewText, int VariableID);
	// void UpdateVariableTaxon(int DatasetIdx, UnicodeString NewText, int VariableID);
	bool UpdateVariable(int DatasetID, int VariableID, int NewVariableID);
	int GetSSDownloadVariableID(int ARow);
	bool GetVariableElementID(NEOTOMAVARIABLEPARTS& Variable);
	bool GetCompanionDatasetTypes(UnicodeString NeotomaDatasetType, vector<int>& DatasetTypeIDs);
	bool GetVariableUnitsID(NEOTOMAVARIABLEPARTS& Variable, int NeotomaDatasetTypeID,
		vector<int>& DatasetTypeIDs);
	bool GetVariableContextID(NEOTOMAVARIABLEPARTS& Variable, int NeotomaDatasetTypeID,
		vector<int>& DatasetTypeIDs);
	bool GetNeotomaVariableParts(int NeotomaVariableID, NEOTOMAVARIABLEPARTS& Variable);
    void GetSSVariable(int ARow, NEOTOMAVARIABLEPARTS& Variable);
	bool IsNewVariable(int ARow, NEOTOMAVARIABLEPARTS& DownloadVariable,
		NEOTOMAVARIABLEPARTS& Variable);
	bool GetVariableID(NEOTOMAVARIABLEPARTS& Variable, int DatasetIdx, bool show_message);
	void InsertDataValue(int ACol, int ARow, UnicodeString Text);
	void UploadDataValues(void);
	bool UpdateSampleAge(UnicodeString VarCode, UnicodeString NewText, int ACol, int ARow);
	bool UpdateSampleAge(UnicodeString VarCode, UnicodeString NewText, int ACol, int ARow,
		vector<UPDSAMPLEAGE>& SampleAges, int& ChronID, bool PullTheTrigger);
	bool UpdateSampleAge(vector<UPDSAMPLEAGE>& SampleAges, int ChronID, UnicodeString msg);
	bool UpdateSampleAnalyst(int ACol, int ARow);
	void UpdateSampleKeywords(int ACol, int ARow, UnicodeString NewText);
	void UpdateSampleName(int ACol, int ARow, UnicodeString SampleName);
	int GetNeotomaSampleID(int ACol, int ARow);
	bool DeleteNeotomaVariable(int ARow);
	void UpdateDataValue(int ACol, int ARow, UnicodeString Text);
	void UpdateAnalysisUnitName(int ACol, int ARow, int AnalysisUnitID, UnicodeString AnalysisUnitName);
	void UpdateAnalysisUnitDepth(int ACol, int ARow, int AnalysisUnitID, UnicodeString DepthStr);
	int UpdateAnalThickness(int ACol, int ARow, UnicodeString ThickStr, int rv);
	void CheckDownloadPaste(int ACol, int ARow, bool& CanPaste);
	void SetIsotopeHeaders(void);
	void ShowIsotopeHeader(short isotope, TAdvPanel* AdvPanel);
	int GetColMinDepth(void);
	bool MoveToSSSite(int ACol);
	void UpdateDatasetType(int NeotomaDatasetID, UnicodeString NewDataType);
	void UpdateNeotomaAgeBasis(bool query);
	void DeleteColumn(TProfGrid *Grid, int col);
	bool UpdateNeotomaChronControlAnalUnit(CHRON* ChronControl);
	bool UpdateNeotomaGeochronAnalUnit(GEOCHRON* Date);
public:		// User declarations
	__fastcall TTilSpreadSheetForm(TComponent* Owner);
	friend class TFuzzyForm;
	friend class TChronForm;
	friend class TConcForm;
	friend class CalculateConc;
	friend class TInfluxForm;
	friend class CalculateInflux;
	friend class WriteTLX;
	friend class TAddRepositoryForm;
	friend class TNewAdminUnit;
	friend class TNeotomaUploadForm;
	friend class TValidateLatLongForm;
	friend class TNewDepEnvtForm;
	friend class TCheckVarForm;
	friend class TCheckDupsForm;
	friend class TSSOptionsForm;
	friend class TSiteHierarchyForm;
	friend class TEditFaciesForm;
	friend class TEditDepAgentsForm;
	friend class TCheckHierarchyForm;
	friend class TNewLookupItemForm;
	friend class TNewFractionForm;
	friend class TImportChronForm;
	friend class TImportClamForm;
	friend class TImportBaconForm;
	friend class TImportBchronForm;
	friend class TImportChronTabsheetForm;
	friend class TSynonymForm;
	friend class TNeotomaUploadChronForm;
	friend class TUpdateNeotomaCollUnitForm;
	friend class TNeotomaCollUnitValidationForm;
	friend class TSpecimenForm;
	friend class TAllSpecimensForm;
	friend class TSelectSpecimensForm;
	friend class TIsotopeSeriesForm;
	friend class TIsoDatasetMetadataForm;
	friend class TUpdateNeotomaDatasetForm;
	friend class TNeotomaDatasetValidationForm;
	friend class TGeochronList;
	friend class TUpdateNeotomaSiteForm;
	friend class TAnalUnitMatchForm;
	friend class TWhitmoreForm;
	friend class TNeotomaSiteMetadataForm;
	friend class TCounterForm;
	template<typename T> friend class ValidateIsotope;
	bool LoadData(UnicodeString&);
	UnicodeString TilFileName;
	bool SpreadSheetChanged;
	void Save(void);
	void SaveAs(void);
	void Export(void);
	void ExportSaveAs(void);
	void SaveTLX(UnicodeString&);
	bool OpenXLS(UnicodeString&);
	void ExitMetadata(void);
	void CalculateSums(int);
	bool MakeDefaultSums(void);
	void GetValidElements(set<UnicodeString>& ValidElements,
		map<int,pair<UnicodeString,UnicodeString> >& ElementGroupCodes,
		UnicodeString& InvalidGroup);
	void ReplaceDefaultElementGroups(map<int,pair<UnicodeString,UnicodeString> >& ElementGroupCodes);
	void LoadSumData(TSumList* SumList);
	void MakeSumVars(int& Row, TSumList* SumList);
	void CalculatePercents(int DiagramType);
	void SortDefaultPercents(void);
	void Test(void);
	void ClearSums(void);
	void ClearSSums(void);
	void AddSum(UnicodeString&, UnicodeString&, bool, int);
	void AddSSum(UnicodeString&, UnicodeString&, int);
	void InsertCONISSSheet(void);
	void InsertPercentsSheet(bool);
	bool CopyToCONISSSheet(TNewCONISSSheetForm*, TStringList*, TProfGrid*, TProfGrid*);
	Set <int, 1, 4> CopyNumAnalErrors;
	void SetLatLongPopupEdit(TcxPopupEdit* PopupEdit) { LatLongPopupEdit = PopupEdit; }
	TProfGrid* InsertNewWorksheet(UnicodeString, int, bool);
	bool ValidateCellDouble(TProfGridCell*, int&, double&);
	void DeleteSheet(void);
	UnicodeString DecodeSum(UnicodeString&);
	UnicodeString DecodeSSum(UnicodeString&);
	TipwXMLp *GetXMLFilePtr(void);
	bool __fastcall OpenCountriesXML(void);
	UnicodeString SetXMLFileName(UnicodeString FileName);
	UnicodeString GetXMLFileName(void) { return XMLFileName; }
	int Get_nCountries(void) { return nCountries; }
	TContactList* ContactList;
	TLithologyUnitList* LithologyUnitList;
	TGeochronList* GeochronList;
	TAgeModelList* AgeModelList;
	TList* Publications;
	vector<DATASET> Datasets;
	GEOCHRONDATASET GeochronDataset;
	map<TcxTabSheet*, TProfGrid*> Worksheets;
	WORKBOOK* Workbook;
	LOI loi;
	ELEMENTLOOKUP* ElementLookup;
	UNITLOOKUP* UnitLookup;
	CONTEXTLOOKUP* ContextLookup;
	TAPHONOMYLOOKUP* TaphonomyLookup;
	VARIABLELOOKUP* VarLookup;
	VARIABLELOOKUP* GeochronVarLookup;
	vector<TAXAECOLGROUPS> TaxaEcolGroups;
	vector<TAXAECOLGROUPS> GeochronTaxaEcolGroups;
	TTaxaVector TaxaList;
	TTaxaVector GeochronTaxaList;
	ELEMENTLOOKUP* GeochronElementLookup;
	bool TaxaLookupOpen;
	bool GeochronTaxaOpen;
	bool GroupLookup;
	bool __fastcall FindWholeText(UnicodeString, TProfGrid*, TRect, TPoint*);
	int __fastcall FindPartialText(UnicodeString, TProfGrid*, TRect, TPoint*);
	void CheckVariables(void);
	void Chronology(void);
	void SSSort(void);
	static int __fastcall ContentRowCount(TProfGrid*);
	int __fastcall ContentRowCount(TAdvColumnGrid* ColumnGrid);
	static int __fastcall ContentColCount(TProfGrid*);
	static int __fastcall AbsContentRowCount(TProfGrid*);
	static int __fastcall AbsContentColCount(TProfGrid*);
	static int __fastcall AbsHeaderColCount(TProfGrid*);
	static int __fastcall AbsHeaderRowCount(TProfGrid*);
	void __fastcall MarkRareTypes(TProfGrid*);
	TProfGrid* __fastcall ProfGrid(void);
	void FormatPercents(int);
	void VariableLookup(void);
	//void LoadUnitsList(void);
	//void LoadContextsList(void);
	void LoadTaphonomyList(void);
	void FormatWorksheet(TProfGrid*);   // friend?
	map<UnicodeString, UnicodeString> AgeUnits;
	int FatalError;
	void SetConcFluxMenuItems(bool Enable);
	void __fastcall DisplayHint(TObject *Sender);
	void ReplaceSynonyms(vector<SYNONYMROW>&, short, short, short, short, UnicodeString);
	void ReplaceVarCodes(TAXON*, int, short);
	void ReplaceGroupCodes(TAXON*, int, short);
	void ReplaceElements(TAXON*, int, short);
	void ReplaceUnits(TAXON*, int, short, UnicodeString);
	void DownloadNeotomaData(vector<MAPDATASET>& Datasets);
	void DownloadEPDData(int EPDSiteNr, int EPDENr, EPDSITELOC& EPDSiteLoc);
};
//---------------------------------------------------------------------------

extern PACKAGE TTilSpreadSheetForm *TilSpreadSheetForm;
//---------------------------------------------------------------------------
#endif
