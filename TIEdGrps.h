//---------------------------------------------------------------------------

#ifndef TIEdGrpsH
#define TIEdGrpsH
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
#include "cxEdit.hpp"
#include "cxFilter.hpp"
#include "cxGraphics.hpp"
#include "cxGrid.hpp"
#include "cxGridCustomTableView.hpp"
#include "cxGridCustomView.hpp"
#include "cxGridLevel.hpp"
#include "cxGridTableView.hpp"
#include "cxStyles.hpp"
#include "cxTextEdit.hpp"
#include "cxMaskEdit.hpp"
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include "cxNavigator.hpp"
#include "cxContainer.hpp"
#include "cxDropDownEdit.hpp"
#include "cxLabel.hpp"
#include "cxButtons.hpp"
#include <Menus.hpp>
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

const int IndexOfcaCategoryCode = 0;
const int IndexOfcaCategoryName = 1;
//---------------------------------------------------------------------------

const int IndexOfegEcolGroupCode = 0;
const int IndexOfegEcolGroupName = 1;
//---------------------------------------------------------------------------

class TEditGroupsForm : public TForm
{
__published:	// IDE-managed Components
	TcxGrid *GroupsGrid;
	TcxGridTableView *GroupsGridTableView1;
	TcxGridColumn *caCategoryCode;
	TcxGridColumn *caCategoryName;
	TcxGridTableView *GroupsGridTableView2;
	TcxGridColumn *egEcolGroupCode;
	TcxGridLevel *GroupsGrid1;
	TcxGridLevel *GroupsGrid2;
	TcxGridColumn *egEcolGroupName;
	TcxStyleRepository *cxStyleRepository1;
	TcxStyle *cxStyle1;
	TcxStyle *cxStyle2;
	TPanel *Panel1;
	TFlowPanel *FlowPanel1;
	TcxButton *cxButton1;
	TcxButton *cxButton2;
	TcxButton *cxButton3;
		void __fastcall FormDestroy(TObject *Sender);
	void __fastcall GroupsGridTableView1DataControllerAfterPost(TcxCustomDataController *ADataController);
	void __fastcall GroupsGridTableView2DataControllerAfterPost(TcxCustomDataController *ADataController);
	void __fastcall cxButton1Click(TObject *Sender);
	void __fastcall cxButton3Click(TObject *Sender);


private:	// User declarations
	vector<TAXAECOLGROUPS>* OriginalTaxaEcolGroupsPtr;
	TTaxaEcolGroups* TaxaEcolGroupList;
	UnicodeString TaxaFile;
	UnicodeString TaxaTitle;
	//vector<TAXON>* TaxaList;
	TTaxaVector* TaxaList;
	TTaxaGroupDataSource* TaxaGroupDataSource;
	TEcolGroupDataSource* EcolGroupDataSource;
	void __fastcall GenerateGroupCategoryColumns();
public:		// User declarations
	__fastcall TEditGroupsForm(vector<TAXAECOLGROUPS>* TaxaEcolGroupsPtr, TComponent* Owner);
	//void SetTaxa(UnicodeString fname, UnicodeString title, vector<TAXON>* tList)
	//  { TaxaFile = fname; TaxaTitle = title; TaxaList = tList; }
	void SetTaxa(UnicodeString fname, UnicodeString title, TTaxaVector* tList)
	  { TaxaFile = fname; TaxaTitle = title; TaxaList = tList; }
	TTaxaEcolGroups* GetGroupCategoryList(void) { return TaxaEcolGroupList; }
};
//---------------------------------------------------------------------------
extern PACKAGE TEditGroupsForm *EditGroupsForm;
//---------------------------------------------------------------------------
#endif
