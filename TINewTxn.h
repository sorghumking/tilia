//---------------------------------------------------------------------------

#ifndef TINewTxnH
#define TINewTxnH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxEdit.hpp"
#include "cxGraphics.hpp"
#include "cxListBox.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include "cxTextEdit.hpp"
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include "cxButtons.hpp"
#include <Menus.hpp>
#include "ipwjson.h"
#include <Sockets.hpp>
#include "dxtree.hpp"
#include "AdvDropDown.hpp"
#include "AdvMultiColumnDropDown.hpp"
#include <Mask.hpp>
#include "cxDropDownEdit.hpp"
#include "cxMaskEdit.hpp"
#include "AdvCGrid.hpp"
#include "AdvGrid.hpp"
#include "AdvObj.hpp"
#include "BaseGrid.hpp"
#include <Grids.hpp>
#include "AdvMemoDropDown.hpp"
#include "frmctrllink.hpp"
#include "AdvControlDropDown.hpp"
#include "cxMemo.hpp"
#include "cxGroupBox.hpp"
#include "cxRadioGroup.hpp"
#include "cxImage.hpp"
#include "cxLabel.hpp"
#include <ImgList.hpp>
#include "ipshttps.h"
#include <Graphics.hpp>
#include "cxClasses.hpp"
#include "cxCustomData.hpp"
#include "cxData.hpp"
#include "cxDataStorage.hpp"
#include "cxDBData.hpp"
#include "cxFilter.hpp"
#include "cxGrid.hpp"
#include "cxGridCustomTableView.hpp"
#include "cxGridCustomView.hpp"
#include "cxGridDBTableView.hpp"
#include "cxGridLevel.hpp"
#include "cxGridTableView.hpp"
#include "cxNavigator.hpp"
#include "cxStyles.hpp"
#include <DB.hpp>
#include "cxBlobEdit.hpp"
#include "cxCheckBox.hpp"
#include "cxCalendar.hpp"
#include "cxButtonEdit.hpp"
#include "cxListView.hpp"
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
#include "dxSkinOffice2016Colorful.hpp"
#include "dxSkinOffice2016Dark.hpp"
#include "dxSkinVisualStudio2013Blue.hpp"
#include "dxSkinVisualStudio2013Dark.hpp"
#include "dxSkinVisualStudio2013Light.hpp"
#include "ipsjsons.h"

#ifndef TIJSONH
#include "TIJSON.h"
#endif
#ifndef TIFndPubH
#include "TIFndPub.h"
#endif
#ifndef TINeotomaH
#include "TINeotoma.h"
#endif
#ifndef TNFindTaxonH
#include "TNFindTaxon.h"
#endif
#ifndef TIContacH
#include "TIContac.h"
#endif

//---------------------------------------------------------------------------
class TNeotomaEditTaxaForm;
//---------------------------------------------------------------------------
enum DBTAXONACTION { dbaUPLOAD, dbaUPDATE };
//---------------------------------------------------------------------------

class WSPARAMETER
{
public:
  UnicodeString Name;
  UnicodeString Value;
public:
  WSPARAMETER(UnicodeString name, UnicodeString value) { Name = name; Value = value;  }
};
//---------------------------------------------------------------------------

class NTMTAXONMAP
{
public:
  UnicodeString TaxonCode;
  UnicodeString TaxonName;
  UnicodeString Author;
  bool Valid;
  Variant HigherTaxonID;
  bool Extinct;
  UnicodeString TaxaGroupID;
  Variant PublicationID;
  UnicodeString Notes;
  Variant ValidatorID;
  Variant ValidateDate;
  map<UnicodeString, UnicodeString> EcolSetsGroups; // EcolSetName, EcolGroupID
public:
  NTMTAXONMAP();
  void Clear(void);
};
//---------------------------------------------------------------------------

class NTMSYNONYMREC : public NTMTAXONMAP
{
public:
  Variant TaxonID;
public:
  NTMSYNONYMREC();
  void Clear(void);
  __property Variant SynonymTypeID = {read = HigherTaxonID, write = HigherTaxonID};
};
//---------------------------------------------------------------------------

class NTMTAXONREC : public NTMTAXONMAP
{
public:
  Variant TaxonID;
  vector<NTMSYNONYMREC> Synonyms;
public:
  NTMTAXONREC();
  void Clear(void);
};
//---------------------------------------------------------------------------

class TEditNeotomaTaxa
{
private:
	vector<NTMTAXONREC> Items;                        // new
	vector<NTMTAXONREC>::pointer GetTaxon(int AIndex); // new
public:
	TEditNeotomaTaxa() { }
	__fastcall ~TEditNeotomaTaxa() { }
	void __fastcall Clear(void);
	void __fastcall Add(NTMTAXONREC& Taxon);  // new
	void Delete(int AIndex);
	int Count(void) { return Items.size(); }  // new
	__property vector<NTMTAXONREC>::pointer Taxon[int Index] = {read = GetTaxon};  // new
	__property vector<NTMTAXONREC> Taxa = {read = Items};                       // new
};
//---------------------------------------------------------------------------

class TEditNeotomaTaxaDataSource : public TcxCustomDataSource
{
private:
	TEditNeotomaTaxa* FEditNeotomaTaxa;
	map<int,UnicodeString>* EcolSetTypes;
	int GetEcolSetID(UnicodeString EcolSetName);
protected:
	void * __fastcall AppendRecord(void);
	void __fastcall DeleteRecord(void * ARecordHandle);
	int __fastcall GetRecordCount(void);
	Variant __fastcall GetValue(void * ARecordHandle, void * AItemHandle);
	void __fastcall SetValue(void * ARecordHandle, void * AItemHandle, const Variant &AValue);
	bool __fastcall GetDetailHasChildren(int ARecordIndex, int ARelationIndex);
public:
	__fastcall TEditNeotomaTaxaDataSource(TEditNeotomaTaxa* AEditNeotomaTaxa, map<int,UnicodeString>* AEcolSetTypes);
	__fastcall ~TEditNeotomaTaxaDataSource() { }
	__property TEditNeotomaTaxa* EditNeotomaTaxa = {read = FEditNeotomaTaxa};
};
//---------------------------------------------------------------------------

class TEditNeotomaSynonymDataSource : public TcxCustomDataSource
{
private:
	TEditNeotomaTaxaDataSource* FDataSource; // master
protected:
	void * __fastcall AppendRecord(void);
	void __fastcall DeleteRecord(void * ARecordHandle);
	int __fastcall GetRecordCount(void);
	Variant __fastcall GetValue(void * ARecordHandle, void * AItemHandle);
	void __fastcall SetValue(void * ARecordHandle, void * AItemHandle, const Variant &AValue);
public:
	__fastcall TEditNeotomaSynonymDataSource(TEditNeotomaTaxaDataSource* ADataSource) { FDataSource = ADataSource;};
	int GetMasterRecordIndex();
	__property TEditNeotomaTaxaDataSource* MasterDataSource = {read = FDataSource};
};
//---------------------------------------------------------------------------

const int IndexOftxnID        = 0;
const int IndexOftxnCode      = 1;
const int IndexOftxnName      = 2;
const int IndexOftxnAuthor    = 3;
const int IndexOftxnHigherID  = 4;
const int IndexOftxnExtinct   = 5;
const int IndexOftxnGroupID   = 6;
const int IndexOftxnPubID     = 7;
const int IndexOftxnNotes     = 8;
const int IndexOftxnEcolGroup = 9;
const int IndexOftxnValidator = 10;
const int IndexOftxnValidDate = 11;

const int IndexOfsyID         = 0;
const int IndexOfsyCode       = 1;
const int IndexOfsyName       = 2;
const int IndexOfsyAuthor     = 3;
const int IndexOfsySynTypeID  = 4;
const int IndexOfsyExtinct    = 5;
const int IndexOfsyGroupID    = 6;
const int IndexOfsyPubID      = 7;
const int IndexOfsyNotes      = 8;
const int IndexOfsyValidator  = 9;
const int IndexOfsyValidDate  = 10;

//---------------------------------------------------------------------------
typedef struct
{
  int ID;
  UnicodeString Name;
  bool IsSynonym;
} TAXONIDNAME;
//---------------------------------------------------------------------------

class TNewTaxonForm : public TForm
{
__published:	// IDE-managed Components
	TStatusBar *StatusBar1;
	TPanel *Panel2;
	TPanel *Panel3;
	TPanel *Panel4;
	TSplitter *Splitter1;
	TTcpClient *TcpClient1;
	TdxTreeView *dxTreeView1;
	TAdvMultiColumnDropDown *AdvMultiColumnDropDown1;
	TcxButton *cxButton2;
	TcxComboBox *cxComboBox1;
	TcxButton *cxButton3;
	TPanel *Panel6;
	TPanel *Panel1;
	TLabel *Label1;
	TPanel *Panel7;
	TcxTextEdit *cxTextEdit1;
	TPanel *Panel8;
	TLabel *Label2;
	TcxRadioButton *cxRadioButton1;
	TcxRadioButton *cxRadioButton2;
	TcxButton *cxButton1;
	TPanel *Panel9;
	TLabel *Label3;
	TcxRadioButton *cxRadioButton3;
	TcxRadioButton *cxRadioButton4;
	TcxButton *cxButton4;
	TcxTextEdit *cxTextEdit2;
	TcxButton *cxButton6;
	TPanel *Panel10;
	TcxTextEdit *cxTextEdit3;
	TcxLabel *cxLabel1;
	TcxImageList *cxImageList1;
	TFlowPanel *FlowPanel1;
	TipsHTTPS *ipsHTTPS1;
	TPanel *Panel11;
	TcxComboBox *cxComboBox2;
	TcxLabel *cxLabel2;
	TcxButton *cxButton7;
	TcxButton *cxButton8;
	TcxGroupBox *PleaseWaitGroupBox;
	TcxLabel *cxLabel3;
	TImage *Image1;
	TTimer *Timer1;
	TcxButton *cxButton9;
	TPopupMenu *PopupMenuValidator;
	TMenuItem *ShowValidator1;
	TPopupMenu *PopupMenuPubID;
	TMenuItem *ShowPublication1;
	TMenuItem *PubDitto1;
	TPopupMenu *PopupMenuAuthor;
	TMenuItem *AuthorDitto1;
	TPopupMenu *PopupMenuEcolGroup;
	TMenuItem *EcolGroupDitto1;
	TPopupMenu *PopupMenu1;
	TMenuItem *Mark1;
	TMenuItem *InsertChild1;
	TMenuItem *InsertSibling1;
	TMenuItem *Unmark1;
	TSplitter *Splitter2;
	TcxGrid *cxGrid1;
	TcxGridTableView *cxGrid1TableView1;
	TcxGridColumn *txnID;
	TcxGridColumn *txnCode;
	TcxGridColumn *txnName;
	TcxGridColumn *txnAuthor;
	TcxGridColumn *txnHigherID;
	TcxGridColumn *txnExtinct;
	TcxGridColumn *txnGroupID;
	TcxGridColumn *txnPubID;
	TcxGridColumn *txnNotes;
	TcxGridColumn *txnEcolGroup;
	TcxGridColumn *txnValidator;
	TcxGridColumn *txnValidDate;
	TcxGridTableView *cxGrid1TableView2;
	TcxGridColumn *syName;
	TcxGridColumn *syID;
	TcxGridColumn *syCode;
	TcxGridColumn *syNotes;
	TcxGridLevel *cxGrid1Level1;
	TcxGridLevel *cxGrid1Level2;
	TcxGridColumn *syAuthor;
	TcxGridColumn *sySynTypeID;
	TcxGridColumn *syExtinct;
	TcxGridColumn *syPubID;
	TcxGridColumn *syValidator;
	TcxGridColumn *syGroupID;
	TcxGridColumn *syValidDate;
	TFlowPanel *FlowPanel3;
	TcxButton *cxButton11;
	TcxButton *cxButton12;
	TcxButton *cxButton13;
	TcxButton *cxButton14;
	TFlowPanel *FlowPanel4;
	TcxButton *cxButton18;
	TcxPopupEdit *cxPopupEdit1;
	TAdvColumnGrid *AdvColumnGrid2;
	TPanel *Panel13;
	TFlowPanel *FlowPanel5;
	TcxButton *cxButton15;
	TcxButton *cxButton16;
	TcxButton *cxButton19;
	TcxButton *cxButton20;
	TcxLabel *cxLabel4;
	TFlowPanel *FlowPanel6;
	TcxStyleRepository *cxStyleRepository1;
	TcxStyle *cxStyle1;
	TcxStyle *cxStyle2;
	TMenuItem *PubDelete1;
	TcxStyle *cxStyle3;
	TcxStyle *cxStyle4;
	TPanel *Panel5;
	TAdvColumnGrid *AdvColumnGrid1;
	TFlowPanel *FlowPanel2;
	TcxButton *cxButton5;
	TcxButton *cxButton10;
	TcxButton *cxButton17;
	TMenuItem *InsertSynonym1;
	TipsJSONS *ipsJSONS1;
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall AdvMultiColumnDropDown1Select(TObject *Sender);
	void __fastcall cxButton2Click(TObject *Sender);
	void __fastcall cxComboBox1PropertiesChange(TObject *Sender);
	void __fastcall dxTreeView1Change(TObject *Sender, TTreeNode *Node);
	void __fastcall cxButton1Click(TObject *Sender);
	void __fastcall cxRadioButton1Click(TObject *Sender);
	void __fastcall cxRadioButton2Click(TObject *Sender);
	void __fastcall cxTextEdit2PropertiesChange(TObject *Sender);
	void __fastcall cxRadioButton3Click(TObject *Sender);
	void __fastcall cxRadioButton4Click(TObject *Sender);
	void __fastcall dxTreeView1CustomDraw(TObject *Sender, TTreeNode *TreeNode, TFont *AFont,
          TColor &AColor, TColor &ABkColor);
	void __fastcall cxTextEdit3PropertiesChange(TObject *Sender);
	void __fastcall cxComboBox1KeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall cxComboBox2Click(TObject *Sender);
	void __fastcall cxButton7Click(TObject *Sender);
	void __fastcall cxButton8Click(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall cxButton6Click(TObject *Sender);
	void __fastcall cxButton4Click(TObject *Sender);
	void __fastcall cxButton9Click(TObject *Sender);
	void __fastcall ShowValidator1Click(TObject *Sender);
	void __fastcall ShowPublication1Click(TObject *Sender);
	void __fastcall PubDitto1Click(TObject *Sender);
	void __fastcall PopupMenuPubIDPopup(TObject *Sender);
	void __fastcall cxButton3Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall AuthorDitto1Click(TObject *Sender);
	void __fastcall EcolGroupDitto1Click(TObject *Sender);
	void __fastcall Mark1Click(TObject *Sender);
	void __fastcall Unmark1Click(TObject *Sender);
	void __fastcall PopupMenu1Popup(TObject *Sender);
	void __fastcall InsertChild1Click(TObject *Sender);
	void __fastcall InsertSibling1Click(TObject *Sender);
	void __fastcall cxButton11Click(TObject *Sender);
	void __fastcall txnCodePropertiesInitPopup(TObject *Sender);
	void __fastcall cxButton12Click(TObject *Sender);
	void __fastcall cxButton13Click(TObject *Sender);
	void __fastcall cxButton14Click(TObject *Sender);
	void __fastcall txnEcolGroupPropertiesInitPopup(TObject *Sender);
	void __fastcall AdvColumnGrid2ClickCell(TObject *Sender, int ARow, int ACol);
	void __fastcall cxButton15Click(TObject *Sender);
	void __fastcall cxButton16Click(TObject *Sender);
	void __fastcall cxButton18Click(TObject *Sender);
	void __fastcall cxButton17Click(TObject *Sender);
	void __fastcall cxButton19Click(TObject *Sender);
	void __fastcall cxButton20Click(TObject *Sender);
	void __fastcall cxPopupEdit1PropertiesChange(TObject *Sender);
	void __fastcall txnCodeStylesGetContentStyle(TcxCustomGridTableView *Sender, TcxCustomGridRecord *ARecord,
          TcxCustomGridTableItem *AItem, TcxStyle *&AStyle);
	void __fastcall cxGrid1TableView1Editing(TcxCustomGridTableView *Sender, TcxCustomGridTableItem *AItem,
          bool &AAllow);
	void __fastcall txnNameStylesGetContentStyle(TcxCustomGridTableView *Sender, TcxCustomGridRecord *ARecord,
          TcxCustomGridTableItem *AItem, TcxStyle *&AStyle);
	void __fastcall txnAuthorStylesGetContentStyle(TcxCustomGridTableView *Sender, TcxCustomGridRecord *ARecord,
          TcxCustomGridTableItem *AItem, TcxStyle *&AStyle);
	void __fastcall txnExtinctStylesGetContentStyle(TcxCustomGridTableView *Sender,
          TcxCustomGridRecord *ARecord, TcxCustomGridTableItem *AItem,
          TcxStyle *&AStyle);
	void __fastcall txnPubIDStylesGetContentStyle(TcxCustomGridTableView *Sender, TcxCustomGridRecord *ARecord,
          TcxCustomGridTableItem *AItem, TcxStyle *&AStyle);
	void __fastcall txnNotesStylesGetContentStyle(TcxCustomGridTableView *Sender, TcxCustomGridRecord *ARecord,
          TcxCustomGridTableItem *AItem, TcxStyle *&AStyle);
	void __fastcall txnEcolGroupStylesGetContentStyle(TcxCustomGridTableView *Sender,
          TcxCustomGridRecord *ARecord, TcxCustomGridTableItem *AItem,
          TcxStyle *&AStyle);
	void __fastcall txnPubIDPropertiesButtonClick(TObject *Sender, int AButtonIndex);
	void __fastcall txnNamePropertiesValidate(TObject *Sender, Variant &DisplayValue,
          TCaption &ErrorText, bool &Error);
	void __fastcall txnAuthorPropertiesValidate(TObject *Sender, Variant &DisplayValue,
          TCaption &ErrorText, bool &Error);
	void __fastcall txnExtinctPropertiesChange(TObject *Sender);
	void __fastcall txnNotesPropertiesValidate(TObject *Sender, Variant &DisplayValue,
          TCaption &ErrorText, bool &Error);
	void __fastcall txnEcolGroupPropertiesCloseUp(TObject *Sender);
	void __fastcall cxGrid1TableView1FocusedItemChanged(TcxCustomGridTableView *Sender,
          TcxCustomGridTableItem *APrevFocusedItem, TcxCustomGridTableItem *AFocusedItem);
	void __fastcall cxGrid1TableView1FocusedRecordChanged(TcxCustomGridTableView *Sender,
          TcxCustomGridRecord *APrevFocusedRecord, TcxCustomGridRecord *AFocusedRecord,
		  bool ANewItemRecordFocusingChanged);
	void __fastcall PubDelete1Click(TObject *Sender);
	void __fastcall cxGrid1TableView2Editing(TcxCustomGridTableView *Sender, TcxCustomGridTableItem *AItem,
          bool &AAllow);
	void __fastcall syCodeStylesGetContentStyle(TcxCustomGridTableView *Sender, TcxCustomGridRecord *ARecord,
          TcxCustomGridTableItem *AItem, TcxStyle *&AStyle);
	void __fastcall syNameStylesGetContentStyle(TcxCustomGridTableView *Sender, TcxCustomGridRecord *ARecord,
          TcxCustomGridTableItem *AItem, TcxStyle *&AStyle);
	void __fastcall syAuthorStylesGetContentStyle(TcxCustomGridTableView *Sender, TcxCustomGridRecord *ARecord,
          TcxCustomGridTableItem *AItem, TcxStyle *&AStyle);
	void __fastcall sySynTypeIDStylesGetContentStyle(TcxCustomGridTableView *Sender,
          TcxCustomGridRecord *ARecord, TcxCustomGridTableItem *AItem,
          TcxStyle *&AStyle);
	void __fastcall syExtinctStylesGetContentStyle(TcxCustomGridTableView *Sender, TcxCustomGridRecord *ARecord,
          TcxCustomGridTableItem *AItem, TcxStyle *&AStyle);
	void __fastcall syPubIDStylesGetContentStyle(TcxCustomGridTableView *Sender, TcxCustomGridRecord *ARecord,
          TcxCustomGridTableItem *AItem, TcxStyle *&AStyle);
	void __fastcall syNotesStylesGetContentStyle(TcxCustomGridTableView *Sender, TcxCustomGridRecord *ARecord,
          TcxCustomGridTableItem *AItem, TcxStyle *&AStyle);
	void __fastcall cxGrid1FocusedViewChanged(TcxCustomGrid *Sender, TcxCustomGridView *APrevFocusedView,
          TcxCustomGridView *AFocusedView);
	void __fastcall syCodePropertiesInitPopup(TObject *Sender);
	void __fastcall cxGrid1TableView1NavigatorButtonsButtonClick(TObject *Sender, int AButtonIndex,
          bool &ADone);
	void __fastcall syNamePropertiesValidate(TObject *Sender, Variant &DisplayValue,
          TCaption &ErrorText, bool &Error);
	void __fastcall syAuthorPropertiesValidate(TObject *Sender, Variant &DisplayValue,
          TCaption &ErrorText, bool &Error);
	void __fastcall syExtinctPropertiesChange(TObject *Sender);
	void __fastcall syNotesPropertiesValidate(TObject *Sender, Variant &DisplayValue,
          TCaption &ErrorText, bool &Error);
	void __fastcall syPubIDPropertiesButtonClick(TObject *Sender, int AButtonIndex);
	void __fastcall sySynTypeIDPropertiesInitPopup(TObject *Sender);
	void __fastcall AdvColumnGrid1ClickCell(TObject *Sender, int ARow, int ACol);
	void __fastcall cxButton5Click(TObject *Sender);
	void __fastcall cxButton10Click(TObject *Sender);
	void __fastcall cxGrid1TableView2NavigatorButtonsButtonClick(TObject *Sender, int AButtonIndex,
          bool &ADone);
	void __fastcall cxGrid1TableView2FocusedRecordChanged(TcxCustomGridTableView *Sender,
          TcxCustomGridRecord *APrevFocusedRecord, TcxCustomGridRecord *AFocusedRecord,
          bool ANewItemRecordFocusingChanged);
	void __fastcall cxGrid1TableView2DataControllerAfterPost(TcxCustomDataController *ADataController);
	void __fastcall cxGrid1TableView1DataControllerDetailExpanding(TcxCustomDataController *ADataController,
		  int ARecordIndex, bool &AAllow);
	void __fastcall InsertSynonym1Click(TObject *Sender);
	void __fastcall ipsHTTPS1SSLServerAuthentication(TObject *Sender, TipsHTTPSSSLServerAuthenticationEventParams *e);
	void __fastcall ipsJSONS1SSLServerAuthentication(TObject *Sender, TipsJSONSSSLServerAuthenticationEventParams *e);

private:    // User declarations
	friend TNeotomaEditTaxaForm;
	TNeotomaFindTaxonForm* NtmFindTaxForm;
	map<int,NTMTAXONMAP> TaxaMap;
	multimap<UnicodeString, int> TaxaNameIndex;
	multimap<UnicodeString, int> TaxaCodeIndex;
	TList* TaxonIDPtrs;
	UnicodeString SSTaxonCode;  // taxon code from spreadsheet
	UnicodeString SSAuthor;     // author from spreadsheet
	int NewTaxonID;
	TTreeNode *CurrentNode;
	TTreeNode *NewNode;
	bool NewTaxonMetaData;
	set<int> NewIDs;
	NeotomaEcolSetsGroups *EcolSetGroup;
	map<int,UnicodeString> EcolSetTypes;
	map<UnicodeString,UnicodeString> EcolGroupTypes;
	map<UnicodeString, vector<CODENAME> > EcolSetsGroups;    // EcolSetName, EcolGroup vector
	void GetEcolSetsGroups(UnicodeString EcolSetID, UnicodeString EcolSetName);
	int RatStart;
	int RatEnd;
	int RatPos;
	bool EditingLocked;
	bool UploadButtonEnabled;
	short dbTaxonAction;
	bool NewTaxonValid;
	bool Activated;
	int MarkedTaxonID;
	TTreeNode* MarkedNode;
	bool from_ss;
	int Row2;
	TEditNeotomaTaxa* EditNeotomaTaxa;
	TEditNeotomaTaxaDataSource* TaxaDataSource;
	TEditNeotomaSynonymDataSource* SynonymDataSource;
	//TcxCustomGridTableView *SynonymView;
	short TaxonGridLevel;
	map<int,UnicodeString> NeotomaSynonymTypes;  // Synonym types lookup table
	vector<NTMSYNONYMREC> NeotomaSynonyms;
	set<int> UnvalidatedTaxa;
	map<UnicodeString,int> SynonymMap;
	bool loading_taxa;
private:	// User declarations
	bool GetTaxaGroups(void);
	void GetTaxaFromNeotoma(void);
	bool GetTaxa(vector<WSPARAMETER>&, NeotomaTaxaBase&);
	void TaxaRecordToMap(TAXONRECORD&, NTMTAXONMAP&);
	void BadHigherTaxonIDMsg(int, TAXONRECORD&);
	void ClearTaxonIDPtrs(void);
	void UpdateBuildTreeStatus(int, int&, int&);
	void ShowTaxonMetaData(int);
	UnicodeString FormCode(void);
	UnicodeString FormSynonymCode(void);
	bool TestCode(UnicodeString Code, bool show);
	void Search(UnicodeString SearchStr);
	void CheckNewTaxonComplete(void);
	void CheckUpdateTaxon(void* avoid);
	void CheckUpdateSynonym(void* avoid);
	int GetEcolSetID(UnicodeString EcolSetName);
	UnicodeString GetEcolGroupID(UnicodeString EcolGroupName);
	void InsertNewTaxon(TcxRadioButton* cxRadioButton1, TcxRadioButton* cxRadioButton2,
		UnicodeString TaxonName, UnicodeString TaxonCode, UnicodeString Author);
	void UploadTaxon(void);
	void UpdateTaxon(void);
	void UploadSynonym(void);
	void UpdateSynonym(void);
	void ToggleLock(void);
	void UnDo(void);
	void ChangeHigherTaxonID(TNodeAttachMode Mode);
	void __fastcall GenerateTaxonColumns();
	bool SetGroupExists(void);
	void SetCellStyle(int RecordIndex, TcxStyle *&AStyle);
	void ValidateAuthor(UnicodeString& NewAuthor);
	bool IsYear(UnicodeString str);
	void CheckYearSeparator(UnicodeString& NewAuthor, int& len, int start);
	TcxGridTableView* SynonymGridView(int idx1);
	TcxGridTableView* SynonymGridView(void);
	TcxCustomDataController* SynonymDataController(int idx1);
	TcxCustomDataController* SynonymDataController(void);
	void PleaseWaitStart(UnicodeString Text);
	void PleaseWaitEnd(void);
	int TaxonChildCount(int TaxonID);
	int SynonymCount(int TaxonID);
	bool GetNeotomaSynonymTypes(void);
	bool InsertSynonym(UnicodeString& ErrorMsg);
public:		// User declarations
	__fastcall TNewTaxonForm(TComponent* Owner);
	void AddNewTaxon(UnicodeString tn, UnicodeString tc, UnicodeString au)
	  { cxTextEdit1->Text = tn; SSTaxonCode = tc; SSAuthor = au; }
	vector<TAXONIDNAME> TaxaUploaded;
	bool AllowReactivate;
};
//---------------------------------------------------------------------------

class TNeotomaEditTaxaForm : public TNewTaxonForm
{
__published:	// IDE-managed Components
	void __fastcall cxButton3Click(TObject *Sender);
public:		// User declarations
	__fastcall TNeotomaEditTaxaForm(TComponent* Owner);
};

//---------------------------------------------------------------------------
extern PACKAGE TNewTaxonForm *NewTaxonForm;
//---------------------------------------------------------------------------
#endif
