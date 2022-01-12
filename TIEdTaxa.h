//---------------------------------------------------------------------------

#ifndef TIEdTaxaH
#define TIEdTaxaH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "cxClasses.hpp"
#include "cxControls.hpp"
#include "cxCustomData.hpp"
#include "cxData.hpp"
#include "cxDataStorage.hpp"
#include "cxDBData.hpp"
#include "cxEdit.hpp"
#include "cxFilter.hpp"
#include "cxGraphics.hpp"
#include "cxGrid.hpp"
#include "cxGridCustomTableView.hpp"
#include "cxGridCustomView.hpp"
#include "cxGridDBTableView.hpp"
#include "cxGridLevel.hpp"
#include "cxGridTableView.hpp"
#include "cxStyles.hpp"
#include <DB.hpp>
#include "cxTextEdit.hpp"
#include "cxDropDownEdit.hpp"
#include "cxContainer.hpp"
#include <Buttons.hpp>
#include <Menus.hpp>
#include <ExtCtrls.hpp>
#include "cxMaskEdit.hpp"
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
#include <ImgList.hpp>
#include <Dialogs.hpp>
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include "cxNavigator.hpp"
#include "cxButtons.hpp"
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
#include "dxSkinOffice2016Colorful.hpp"
#include "dxSkinOffice2016Dark.hpp"
#include "dxSkinVisualStudio2013Blue.hpp"
#include "dxSkinVisualStudio2013Dark.hpp"
#include "dxSkinVisualStudio2013Light.hpp"
//---------------------------------------------------------------------------
#ifndef TIUtilsH
#include "TIUtils.h"
#endif

//---------------------------------------------------------------------------

const int IndexOftxTaxonID = 0;
const int IndexOftxCode = 1;
const int IndexOftxName = 2;
const int IndexOftxHigherID = 3;
const int IndexOftxEcolGroup = 4;
//---------------------------------------------------------------------------

const int IndexOfelElement = 0;
//---------------------------------------------------------------------------

const int IndexOfunUnits = 0;
//---------------------------------------------------------------------------

class TEditTaxaForm : public TForm
{
__published:	// IDE-managed Components
	TcxGrid *TaxaGrid;
	TcxGridLevel *TaxaGrid1;
	TcxGridTableView *TaxaGridTableView1;
	TcxGridColumn *txCode;
	TcxGridColumn *txName;
	TcxGridColumn *txHigherID;
	TcxGridColumn *txEcolGroup;
	TcxGridColumn *txID;
	TPopupMenu *PopupMenu1;
	TMenuItem *PartialCompare1;
	TMenuItem *Forward1;
	TMenuItem *Backward1;
	TMenuItem *WholeField1;
	TMenuItem *StartofField1;
	TMenuItem *N1;
	TcxComboBox *cxComboBox1;
	TToolBar *ToolBar1;
	TToolButton *ToolButton3;
	TToolButton *ToolButton2;
	TToolButton *ToolButton4;
	TSaveDialog *SaveDialog1;
	TcxGridLevel *TaxaGrid2;
	TcxGridTableView *TaxaGridTableView2;
	TcxGridColumn *elElement;
	TcxStyleRepository *cxStyleRepository1;
	TcxStyle *cxStyle1;
	TPanel *Panel1;
	TPanel *Panel2;
	TLabeledEdit *LabeledEdit1;
	TSpeedButton *SpeedButton1;
	TcxGridLevel *TaxaGrid3;
	TcxGridTableView *TaxaGridTableView3;
	TcxGridColumn *unUnits;
	TcxStyle *cxStyle2;
	TcxStyle *cxStyle3;
	TcxStyle *cxStyle4;
	TcxStyle *cxStyle5;
	TFlowPanel *FlowPanel1;
	TcxButton *cxButton1;
	TcxButton *cxButton2;
	TcxButton *cxButton3;
	TcxImageList *cxImageList1;
	TcxButton *cxButton4;
	void __fastcall TaxaGridTableView1DataControllerBeforePost(
		TcxCustomDataController *ADataController);
	void __fastcall Forward1Click(TObject *Sender);
	void __fastcall Backward1Click(TObject *Sender);
	void __fastcall WholeField1Click(TObject *Sender);
	void __fastcall PartialCompare1Click(TObject *Sender);
	void __fastcall StartofField1Click(TObject *Sender);
	void __fastcall ToolButton2Click(TObject *Sender);
	void __fastcall ToolButton4Click(TObject *Sender);
	void __fastcall txEcolGroupPropertiesNewLookupDisplayText(
		TObject *Sender, const TCaption AText);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);
	void __fastcall SpeedButton1Click(TObject *Sender);
	void __fastcall TaxaGridTableView2DataControllerDetailExpanded(
		TcxCustomDataController *ADataController, int ARecordIndex);
	void __fastcall TaxaGridTableView1DataControllerDetailExpanding(
	TcxCustomDataController *ADataController, int ARecordIndex, bool &AAllow);
	void __fastcall cxButton1Click(TObject *Sender);
	void __fastcall cxButton2Click(TObject *Sender);
private:	// User declarations
	int MaxID;
	UnicodeString TaxaFile;
	UnicodeString TaxaTitle;
	TTaxaDataSource* TaxaDataSource;
	TElementsDataSource* ElementsDataSource;
	TUnitsDataSource* UnitsDataSource;
	vector<TAXAECOLGROUPS>* OriginalTaxaEcolGroupsPtr;
	vector<TAXAECOLGROUPS> TaxaEcolGroups;
private:
	void __fastcall GenerateTaxaColumns();
	UnicodeString FormCode(TcxCustomDataController*, UnicodeString);
	bool FindText(int);
	bool FindPartialTextForward(int, int, int, UnicodeString);
	bool FindPartialTextBackward(int, int, int, UnicodeString);
	void NewGroups(void);
	void EditGroups(void);
public:
	TTaxaList* TaxaList;
	TTaxaEcolGroups* GroupCategoryList;
	bool NewTaxa;
public:		// User declarations
	__fastcall TEditTaxaForm(TTaxaVector* TaxaListPtr, vector<TAXAECOLGROUPS>* TaxaEcolGroupsPtr,
		int max_id, bool new_taxa, TComponent* Owner);
	void SetTaxaFile(UnicodeString fname) { TaxaFile = fname; }
	void SetTaxaTitle(UnicodeString title) { TaxaTitle = title; }
	void ConvertTaxaList(TTaxaVector& vTaxaList);
};
//---------------------------------------------------------------------------
extern PACKAGE TEditTaxaForm *EditTaxaForm;
//---------------------------------------------------------------------------
#endif
