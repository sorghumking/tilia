//---------------------------------------------------------------------------

#ifndef TNVarModsH
#define TNVarModsH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "cxButtons.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include <CheckLst.hpp>
#include <Menus.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include "ipwjson.h"
#include <Sockets.hpp>
#include <ImgList.hpp>
#include <Dialogs.hpp>
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
#include "dxSkinOffice2016Colorful.hpp"
#include "dxSkinOffice2016Dark.hpp"
#include "dxSkinVisualStudio2013Blue.hpp"
#include "dxSkinVisualStudio2013Dark.hpp"
#include "dxSkinVisualStudio2013Light.hpp"
#include "ipsjsons.h"
#ifndef TNTaxaH
#include "TNTaxa.h"
#endif

//---------------------------------------------------------------------------
class TNeotomaVarModsLookupForm : public TForm
{
__published:	// IDE-managed Components
	TGroupBox *GroupBox1;
	TCheckListBox *CheckListBox1;
	TPanel *Panel1;
	TcxButton *cxButton2;
	TTcpClient *TcpClient1;
	TcxButton *cxButton1;
	TSaveDialog *SaveDialog1;
	TFlowPanel *FlowPanel1;
	TPanel *StatusBar1;
	TipsJSONS *ipsJSONS1;
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall CheckListBox1ClickCheck(TObject *Sender);
	void __fastcall cxButton1Click(TObject *Sender);
	void __fastcall ipsJSONS1SSLServerAuthentication(TObject *Sender, TipsJSONSSSLServerAuthenticationEventParams *e);

private:	// User declarations
	bool activated;
	vector<GENERICDATASETTYPE> GenericDatasetTypes;
	NeotomaDatasetTypesTable *DatasetTypes;
	UnicodeString FileName;
	bool FLookupCreated;
private:
	friend class TNeotomaWriteLookupForm;
	bool GetFileName(void);
	void GetElDSTGLimits(NeotomaElementDatasetTaxaGroupsTable& ElDSTGTypes,
		int DatasetTypeID, int& first, int& last);
	void GetTaxaGroupElements(UnicodeString TaxaGroupID, map<int,int>& TaxaGroupElements,
		NeotomaElementTaxaGroupsTable& ElementTaxaGroups);
	void GetDatasetTypeIDs(vector<int>& DatasetTypeIDs, int id);
	void WriteVarMods(TPanel* StatusBar1, UnicodeString FileName, bool ShowMessage=true);
public:		// User declarations
	__fastcall TNeotomaVarModsLookupForm(TComponent* Owner);
	__property bool LookupCreated = {read = FLookupCreated};
};
//---------------------------------------------------------------------------
extern PACKAGE TNeotomaVarModsLookupForm *NeotomaVarModsLookupForm;
//---------------------------------------------------------------------------
#endif
