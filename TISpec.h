//---------------------------------------------------------------------------

#ifndef TISpecH
#define TISpecH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include "AdvCGrid.hpp"
#include "AdvGrid.hpp"
#include "AdvObj.hpp"
#include "BaseGrid.hpp"
#include "cxButtons.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
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
#include <Grids.hpp>
#include <Menus.hpp>
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxDropDownEdit.hpp"
#include "cxEdit.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include "AdvUtil.hpp"
#include "dxSkinOffice2016Colorful.hpp"
#include "dxSkinOffice2016Dark.hpp"
#include "dxSkinVisualStudio2013Blue.hpp"
#include "dxSkinVisualStudio2013Dark.hpp"
#include "dxSkinVisualStudio2013Light.hpp"
#include <ComCtrls.hpp>
#include <ImgList.hpp>
#include <ToolWin.hpp>
#include "frmctrllink.hpp"
#include <Mask.hpp>
#include "AdvCustomGridDropDown.hpp"
#include "AdvDropDown.hpp"
#include "AdvControlDropDown.hpp"
#include "AdvEdit.hpp"
#include "clisted.hpp"
#include "AdvCombo.hpp"
#include "cxCheckBox.hpp"
#include "ipshttps.h"
#include "ipwjson.h"
#include <Sockets.hpp>
#include "ipsjsons.h"
//---------------------------------------------------------------------------
#ifndef TISpreadH
#include "TISpread.h"
#endif
#ifndef TICommonH
#include "TICommon.h"
#endif
//---------------------------------------------------------------------------

class TAllSpecimensForm;
//---------------------------------------------------------------------------

typedef struct {
  short SpecID;
  short Dep;
  short Anal;
  short Tax;
  short Elem;
  short Sym;
  short Por;
  short Mat;
  short Sex;
  short Dom;
  short Taph;
  short Pres;
  short NISP;
  short Rep;
  short SpecNr;
  short FldNr;
  short ArcNr;
  short GenNr;
  short Note;
} SPECCOLS;
//---------------------------------------------------------------------------

class TSpecimenForm : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TAdvColumnGrid *AdvColumnGrid1;
	TFlowPanel *FlowPanel1;
	TcxButton *cxButton1;
	TcxButton *cxButton2;
	TPanel *Panel2;
	TcxComboBox *cxComboBox1;
	TToolBar *ToolBar1;
	TToolButton *ToolButton1;
	TToolButton *ToolButton2;
	TcxImageList *cxImageList1;
	TFormControlEditLink *FormControlEditLink1;
	TcxImageList *cxImageList2;
	TAdvControlDropDown *AdvControlDropDown1;
	TAdvStringGrid *AdvStringGrid1;
	TFormControlEditLink *FormControlEditLink2;
	TAdvEdit *AdvEdit1;
	TCheckListEdit *CheckListEdit2;
	TFormControlEditLink *FormControlEditLink3;
	TCheckListEdit *CheckListEdit1;
	TcxCheckBox *cxCheckBox1;
	TTcpClient *TcpClient1;
	TipsJSONS *ipsJSONS1;
	TipsHTTPS *ipsHTTPS1;
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall cxComboBox1Click(TObject *Sender);
	void __fastcall AdvColumnGrid1CanEditCell(TObject *Sender, int ARow, int ACol, bool &CanEdit);
	void __fastcall AdvColumnGrid1GetEditorProp(TObject *Sender, int ACol, int ARow,
          TEditLink *AEditLink);
	void __fastcall AdvColumnGrid1GetEditorType(TObject *Sender, int ACol, int ARow,
          TEditorType &AEditor);
	void __fastcall Panel1Resize(TObject *Sender);
	void __fastcall AdvColumnGrid1Resize(TObject *Sender);
	void __fastcall cxButton1Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall AdvColumnGrid1GetDisplText(TObject *Sender, int ACol, int ARow,
          UnicodeString &Value);
	void __fastcall ToolButton1Click(TObject *Sender);
	void __fastcall ToolButton2Click(TObject *Sender);
	void __fastcall AdvColumnGrid1CellValidate(TObject *Sender, int ACol, int ARow,
          UnicodeString &Value, bool &Valid);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall AdvControlDropDown1DropDownFooterButtonClick(TObject *Sender, int ButtonIndex);
	void __fastcall FormControlEditLink1GetEditorValue(TObject *Sender, TAdvStringGrid *Grid,
          UnicodeString &AValue);
	void __fastcall FormControlEditLink1SetEditorValue(TObject *Sender, TAdvStringGrid *Grid,
          UnicodeString AValue);
	void __fastcall FormControlEditLink2GetEditorValue(TObject *Sender, TAdvStringGrid *Grid,
          UnicodeString &AValue);
	void __fastcall FormControlEditLink2SetEditorValue(TObject *Sender, TAdvStringGrid *Grid,
          UnicodeString AValue);
	void __fastcall AdvControlDropDown1DropUp(TObject *Sender, bool Cancelled);
	void __fastcall AdvColumnGrid1CellBalloon(TObject *Sender, int ACol, int ARow, UnicodeString &ATitle,
          UnicodeString &AText, int &AIcon);
	void __fastcall FormControlEditLink3GetEditorValue(TObject *Sender, TAdvStringGrid *Grid,
          UnicodeString &AValue);
	void __fastcall FormControlEditLink3SetEditorValue(TObject *Sender, TAdvStringGrid *Grid,
          UnicodeString AValue);
	void __fastcall AdvColumnGrid1EndColumnSize(TObject *Sender, int ACol);
	void __fastcall AdvColumnGrid1TopLeftChanged(TObject *Sender);
	void __fastcall CheckListEdit1Change(TObject *Sender);
	void __fastcall AdvColumnGrid1ClipboardBeforePasteCell(TObject *Sender, int ACol,
          int ARow, UnicodeString &Value, bool &Allow);
	void __fastcall AdvColumnGrid1ClipboardAfterPasteCell(TObject *Sender, int ACol,
          int ARow, UnicodeString Value);
	void __fastcall cxCheckBox1Click(TObject *Sender);
	void __fastcall AdvColumnGrid1RowChanging(TObject *Sender, int OldRow, int NewRow,
          bool &Allow);
	void __fastcall ipsJSONS1SSLServerAuthentication(TObject *Sender, TipsJSONSSSLServerAuthenticationEventParams *e);

private:	// User declarations
	friend class TAllSpecimensForm;
	TTilSpreadSheetForm* TSSForm;
	TPoint Position;
	map<UnicodeString,int> col;  // map of data columns and col index
	UnicodeString DatasetType;
	CELLOBJECT* CellObject;
	CELLOBJECT* CellObjectBackup;
	map<SPECIMEN*,SPECIMEN*> SpecMap;  // Backup Specimen, Specimen
	// SPECCOLS vc; // visible cols
	SPECCOLS rc; // real cols
	bool activated;
	bool repositories_init;
	bool genbank_init;
	void Setup(void);
	void FillElementList(void);
	void FillSexList(void);
	void FillDomesticStatusList(void);
	void EnterSpecimen(SPECIMEN* Specimen, int row);
	void UpdateTaphSelections(void);
	TList* GetGridSpecimens(void);
	void CreateSpecimen(int ARow, UnicodeString& Value);
	UnicodeString GetTaxaGroup(UnicodeString EcolGroupCode);
	bool Validate(int ACol, int ARow, UnicodeString &Value, bool &Allow);
	void InitRepositories(void);
	void InitGenBank(int ACol, int ARow);
	void UpdateSpecimens(TList* GridSpecimens);
	bool UpdateSpecimen(SPECIMEN* OldSpec, SPECIMEN* NewSpec);
public:		// User declarations
	__fastcall TSpecimenForm(TPoint pos, CELLOBJECT* cell_object, TComponent* Owner);
};
//---------------------------------------------------------------------------

class TAllSpecimensForm : public TSpecimenForm
{
__published:	// IDE-managed Components
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall cxButton1Click(TObject *Sender);
	void __fastcall AdvColumnGrid1RowChanging(TObject *Sender, int OldRow,
		int NewRow, bool &Allow);
	void __fastcall AdvColumnGrid1CellValidate(TObject *Sender, int ACol,
		int ARow, UnicodeString &Value, bool &Valid);
	void __fastcall AdvColumnGrid1ClipboardBeforePasteCell(TObject *Sender, int ACol,
		int ARow, UnicodeString &Value, bool &Allow);
	void __fastcall AdvColumnGrid1ClipboardAfterPasteCell(TObject *Sender,
		int ACol, int ARow, UnicodeString Value);
	void __fastcall AdvColumnGrid1GetEditorProp(TObject *Sender, int ACol,
		int ARow, TEditLink *AEditLink);
private:	// User declarations
	map<UnicodeString,UnicodeString> TaxaTaxaGroups;             // Taxon, TaxaGroup
	map<UnicodeString,set<UnicodeString> > TaxaGroupElements;    // TaxaGroup, set of elements
	map<UnicodeString,set<UnicodeString> > TaxaGroupSymmetries;  // TaxaGroup, set of symmetries
	map<UnicodeString,set<UnicodeString> > TaxaGroupPortions;    // TaxaGroup, set of portions
	map<UnicodeString,set<UnicodeString> > TaxaGroupMaturities;  // TaxaGroup, set of elements
	vector<pair<UnicodeString,UnicodeString> > AnalysisUnits;    // depth, analysis unit name
	UnicodeString CurrentTaxaGroup;
	void Setup(void);
	bool Validate(int ACol, int ARow, UnicodeString &Value, bool &Allow, SPECIMEN* Specimen);
	void InitAnalysisUnits(int ACol);
public:		// User declarations
	__fastcall TAllSpecimensForm(TPoint pos, TComponent* Owner);
};


//---------------------------------------------------------------------------
extern PACKAGE TSpecimenForm *SpecimenForm;
extern PACKAGE TAllSpecimensForm *AllSpecimensForm;
//---------------------------------------------------------------------------
#endif
