//---------------------------------------------------------------------------

#ifndef TINtmSitFrmH
#define TINtmSitFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include "AdvGrid.hpp"
#include "AdvObj.hpp"
#include "BaseGrid.hpp"
#include <Grids.hpp>
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxDropDownEdit.hpp"
#include "cxEdit.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include "AdvDropDown.hpp"
#include "AdvMemoDropDown.hpp"
#include <Mask.hpp>
#include "AdvControlDropDown.hpp"
#include "frmctrllink.hpp"
#include <ImgList.hpp>
#include "cxButtons.hpp"
#include "cxMemo.hpp"
#include <Menus.hpp>
#include "cxBlobEdit.hpp"
#include <Graphics.hpp>
#include "cxCheckBox.hpp"
#include "cxSpinEdit.hpp"
#include <ComCtrls.hpp>
#include "ipwjson.h"
#include <Sockets.hpp>
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
#include "AdvUtil.hpp"
#include "dxSkinOffice2016Colorful.hpp"
#include "dxSkinOffice2016Dark.hpp"
#include "dxSkinVisualStudio2013Blue.hpp"
#include "dxSkinVisualStudio2013Dark.hpp"
#include "dxSkinVisualStudio2013Light.hpp"
#include "cxRadioGroup.hpp"
#include "ipsjsons.h"
#ifndef TIUploadH
#include "TIUpload.h"
#endif
#ifndef TISpreadH
#include "TISpread.h"
#endif

//---------------------------------------------------------------------------

typedef struct
{
  int PIOrder;
  UnicodeString PIName;
} DATASETPI;
//---------------------------------------------------------------------------

typedef struct
{
  bool PrimaryPub;
  int PublicationID;
  UnicodeString Citation;
} DATASETPUB;
//---------------------------------------------------------------------------

typedef struct
{
  int DatasetID;
  UnicodeString DatasetType;
  vector<DATASETPI> DatasetPIs;
  vector<DATASETPUB> DatasetPubs;
} SITEDATASET;
//---------------------------------------------------------------------------

class TNeotomaSiteForm : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TAdvStringGrid *AdvStringGrid1;
	TAdvControlDropDown *AdvControlDropDownGeoPol;
	TFormControlEditLink *FormControlEditLinkGeoPol;
	TAdvStringGrid *AdvStringGridGeoPol;
	TAdvStringGrid *AdvStringGridDataset;
	TFormControlEditLink *FormControlEditLinkDataset;
	TAdvControlDropDown *AdvControlDropDownDataset;
	TAdvControlDropDown *AdvControlDropDownPI;
	TFormControlEditLink *FormControlEditLinkPI;
	TAdvStringGrid *AdvStringGridPI;
	TAdvControlDropDown *AdvControlDropDownPub;
	TFormControlEditLink *FormControlEditLinkPub;
	TAdvStringGrid *AdvStringGridPub;
	TFormControlEditLink *FormControlEditLinkPubMemo;
	TAdvControlDropDown *AdvControlDropDownPubMemo;
	TcxMemo *cxPubMemo;
	TImageList *ImageList1;
	TImage *Image1;
	TPanel *Panel2;
	TPanel *Panel4;
	TLabeledEdit *LabeledEdit1;
	TcxButton *cxButton1;
	TPanel *Panel5;
	TcxSpinEdit *cxSpinEdit1;
	TLabel *Label1;
	TLabel *Label2;
	TcxButton *cxButton2;
	TcxButton *cxButton3;
	TcxButton *cxButton4;
	TRichEdit *RichEdit1;
	TTcpClient *TcpClient1;
	TStatusBar *StatusBar1;
	TcxImageList *cxImageList1;
	TcxRadioButton *cxRadioButton1;
	TcxRadioButton *cxRadioButton2;
	TFlowPanel *FlowPanel1;
	TcxButton *cxButton5;
	TipsJSONS *ipsJSONS1;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall AdvStringGrid1GetEditorType(TObject *Sender, int ACol, int ARow,
          TEditorType &AEditor);
	void __fastcall AdvStringGrid1CheckBoxChange(TObject *Sender, int ACol, int ARow,
          bool State);
	void __fastcall AdvStringGrid1CanEditCell(TObject *Sender, int ARow, int ACol, bool &CanEdit);
	void __fastcall FormControlEditLinkGeoPolGetEditorValue(TObject *Sender, TAdvStringGrid *Grid,
          UnicodeString &AValue);
	void __fastcall FormControlEditLinkGeoPolSetEditorValue(TObject *Sender, TAdvStringGrid *Grid,
          UnicodeString AValue);
	void __fastcall AdvStringGrid1GetEditorProp(TObject *Sender, int ACol, int ARow,
          TEditLink *AEditLink);
	void __fastcall FormControlEditLinkDatasetGetEditorValue(TObject *Sender, TAdvStringGrid *Grid,
          UnicodeString &AValue);
	void __fastcall FormControlEditLinkDatasetSetEditorValue(TObject *Sender, TAdvStringGrid *Grid,
          UnicodeString AValue);
	void __fastcall AdvStringGridDatasetGetEditorType(TObject *Sender, int ACol, int ARow,
          TEditorType &AEditor);
	void __fastcall AdvStringGridDatasetGetEditorProp(TObject *Sender, int ACol, int ARow,
          TEditLink *AEditLink);
	void __fastcall FormControlEditLinkPIGetEditorValue(TObject *Sender, TAdvStringGrid *Grid,
          UnicodeString &AValue);
	void __fastcall FormControlEditLinkPISetEditorValue(TObject *Sender, TAdvStringGrid *Grid,
          UnicodeString AValue);
	void __fastcall AdvStringGridDatasetCanEditCell(TObject *Sender, int ARow, int ACol, bool &CanEdit);
	void __fastcall FormControlEditLinkPubGetEditorValue(TObject *Sender, TAdvStringGrid *Grid,
          UnicodeString &AValue);
	void __fastcall FormControlEditLinkPubSetEditorValue(TObject *Sender, TAdvStringGrid *Grid,
          UnicodeString AValue);
	void __fastcall AdvStringGridPubCanEditCell(TObject *Sender, int ARow, int ACol,
          bool &CanEdit);
	void __fastcall AdvStringGridPubGetEditorType(TObject *Sender, int ACol, int ARow,
          TEditorType &AEditor);
	void __fastcall AdvStringGridPubGetEditorProp(TObject *Sender, int ACol, int ARow,
          TEditLink *AEditLink);
	void __fastcall FormControlEditLinkPubMemoGetEditorValue(TObject *Sender, TAdvStringGrid *Grid,
          UnicodeString &AValue);
	void __fastcall FormControlEditLinkPubMemoSetEditorValue(TObject *Sender, TAdvStringGrid *Grid,
          UnicodeString AValue);
	void __fastcall cxButton1Click(TObject *Sender);
	void __fastcall cxButton2Click(TObject *Sender);
	void __fastcall cxButton3Click(TObject *Sender);
	void __fastcall AdvStringGrid1RowChanging(TObject *Sender, int OldRow, int NewRow,
          bool &Allow);
	void __fastcall AdvStringGrid1CellValidate(TObject *Sender, int ACol, int ARow,
          UnicodeString &Value, bool &Valid);
	void __fastcall cxRadioButton2Click(TObject *Sender);
	void __fastcall AdvStringGrid1GetAlignment(TObject *Sender, int ARow, int ACol,
          TAlignment &HAlign, TVAlignment &VAlign);
	void __fastcall cxButton5Click(TObject *Sender);
	void __fastcall ipsJSONS1SSLServerAuthentication(TObject *Sender, TipsJSONSSSLServerAuthenticationEventParams *e);


private:	// User declarations
	friend class TNeotomaSiteMetadataForm;
	TNeotomaUploadForm *upf;
	SITE *site_ptr;
	vector<SITEDATASET> Datasets;
	UnicodeString CurrentSiteName;
	static bool DatasetPIComp (DATASETPI PI1, DATASETPI PI2) { return (PI1.PIOrder < PI2.PIOrder); }
private:
	void InitializeForm(void);
	bool SearchSiteName(UnicodeString, int&);
    void SearchDistance(double km, int StartRow);
	void DisplaySiteNameStatus(int, UnicodeString);
	void HighlightText(int, UnicodeString);
	UnicodeString FormatDist(double);
	bool GetSiteDatasets(int, vector<SITEDATASET>*);
	bool GetDatasetPIs(SITEDATASET&);
	bool GetDatasetPubs(SITEDATASET&);
	bool GetSiteGeoPolUnits(int, TStringList*);
	void AdjustStringGridRowCount(TAdvStringGrid*, int, int);
public:
	bool InitializationSuccess;
public:		// User declarations
	__fastcall TNeotomaSiteForm(TComponent* Owner);
	int NeotomaSiteID;
};
//---------------------------------------------------------------------------

class TNeotomaSiteMetadataForm : public TNeotomaSiteForm
{
__published:	// IDE-managed Components
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall AdvStringGrid1CheckBoxChange(TObject *Sender, int ACol, int ARow,
		  bool State);
	void __fastcall AdvStringGrid1RowChanging(TObject *Sender, int OldRow,
		  int NewRow, bool &Allow);
	void __fastcall cxButton5Click(TObject *Sender);
private:
	TTilSpreadSheetForm* TSSForm;
public:
	__fastcall TNeotomaSiteMetadataForm(SITE* siteptr, TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TNeotomaSiteForm *NeotomaSiteForm;
extern PACKAGE TNeotomaSiteMetadataForm *NeotomaSiteMetadataForm;
//---------------------------------------------------------------------------
#endif
