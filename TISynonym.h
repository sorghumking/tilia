//---------------------------------------------------------------------------

#ifndef TISynonymH
#define TISynonymH
#include "cxBlobEdit.hpp"
#include "cxButtons.hpp"
#include "cxCheckBox.hpp"
#include "cxClasses.hpp"
#include "cxControls.hpp"
#include "cxCustomData.hpp"
#include "cxData.hpp"
#include "cxDataStorage.hpp"
#include "cxDropDownEdit.hpp"
#include "cxEdit.hpp"
#include "cxFilter.hpp"
#include "cxGraphics.hpp"
#include "cxGrid.hpp"
#include "cxGridCustomTableView.hpp"
#include "cxGridCustomView.hpp"
#include "cxGridLevel.hpp"
#include "cxGridTableView.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include "cxNavigator.hpp"
#include "cxStyles.hpp"
#include <Classes.hpp>
#include <Controls.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include <StdCtrls.hpp>
#include <ComCtrls.hpp>
#include "ipwjson.h"
#include <Sockets.hpp>
#include "ipshttps.h"
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
#include "ipsjsons.h"
//---------------------------------------------------------------------------
#ifndef TISpreadH
#include "TISpread.h"
#endif
#ifndef TITaxSynH
#include "TITaxSyn.h"
#endif
#ifndef TIPubH
#include "TIPub.h"
#endif
#include <vector>
//---------------------------------------------------------------------------

class TSynonymForm : public TForm
{
__published:	// IDE-managed Components
	TcxGrid *cxGrid5;
	TcxGridTableView *cxGrid5TableView1;
	TcxGridColumn *synName;
	TcxGridColumn *synContrib;
	TcxGridColumn *synPub;
	TcxGridColumn *synNotes;
	TcxGridLevel *cxGrid5Level1;
	TPanel *Panel1;
	TFlowPanel *FlowPanel1;
	TcxButton *cxButton1;
	TcxButton *cxButton2;
	TcxButton *cxButton3;
	TStatusBar *StatusBar1;
	TTcpClient *TcpClient1;
	TipsHTTPS *ipsHTTPS1;
	TipsJSONS *ipsJSONS1;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall cxButton1Click(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall cxButton3Click(TObject *Sender);
	void __fastcall ipsJSONS1SSLServerAuthentication(TObject *Sender, TipsJSONSSSLServerAuthenticationEventParams *e);

private:	// User declarations
	TTilSpreadSheetForm* TSSForm;
	TAXON_NOTES* EditTaxonNotes;
	TSynonymyDataSource* SynonymyDataSource;
	TSynonymy* EditSynonymy;
	TPoint Position;
	int NeotomaDatasetID;
	int NeotomaVariableID;
	bool ValidateRefTaxaNames(vector<unsigned int>& Records, map<UnicodeString,int>& RefTaxonIDMap);
	bool GetVariableTaxonID(int& TaxonID);
public:		// User declarations
	__fastcall TSynonymForm(TAXON_NOTES* edit_taxon_notes, TPoint& pos, TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TSynonymForm *SynonymForm;
//---------------------------------------------------------------------------
#endif
