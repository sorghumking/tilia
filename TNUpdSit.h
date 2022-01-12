//---------------------------------------------------------------------------

#ifndef TNUpdSitH
#define TNUpdSitH

#include "AdvCGrid.hpp"
#include "AdvGrid.hpp"
#include "AdvObj.hpp"
#include "BaseGrid.hpp"
#include <Classes.hpp>
#include <Controls.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include "cxGraphics.hpp"
#include <ImgList.hpp>
#include "ipwjson.h"
#include <Sockets.hpp>
#include "cxButtons.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxEdit.hpp"
#include "cxLabel.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include <ComCtrls.hpp>
#include <Menus.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
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
#include "ipsjsons.h"

//---------------------------------------------------------------------------
#ifndef TISpreadH
#include "TISpread.h"
#endif
#ifndef TIUploadH
#include "TIUpload.h"
#endif
//---------------------------------------------------------------------------

class TUpdateNeotomaSiteForm : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TAdvColumnGrid *AdvColumnGrid1;
	TPanel *Panel2;
	TTcpClient *TcpClient1;
	TcxLabel *cxLabel1;
	TFlowPanel *FlowPanel1;
	TcxButton *cxButton1;
	TcxButton *cxButton2;
	TStatusBar *StatusBar1;
	TcxImageList *cxImageList1;
	TcxImageList *cxImageList2;
	TipsJSONS *ipsJSONS1;
	void __fastcall AdvColumnGrid1GetEditorType(TObject *Sender, int ACol, int ARow,
          TEditorType &AEditor);
	void __fastcall AdvColumnGrid1CellValidate(TObject *Sender, int ACol, int ARow,
		  UnicodeString &Value, bool &Valid);
	void __fastcall AdvColumnGrid1ButtonClick(TObject *Sender, int ACol, int ARow);
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall cxButton1Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall cxButton2Click(TObject *Sender);
	void __fastcall ipsJSONS1SSLServerAuthentication(TObject *Sender, TipsJSONSSSLServerAuthenticationEventParams *e);

private:	// User declarations
	friend class TUpdateNeotomaCollUnitForm;
	friend class TUpdateNeotomaDatasetForm;
	TTilSpreadSheetForm* TSSForm;
	TNeotomaUploadForm* TUploadForm;
	SITE* site_ptr;
	bool activated;
	bool update_tilia;
	bool allsame;
	map<int,int> GeoPolID;
	Graphics::TBitmap *TiliaBmp;
	Graphics::TBitmap *RatBmp;
	Graphics::TBitmap *ArrowBmp;
private:
	bool GetNeotomaSiteData(void);
	void UpdateSSMetadata(bool ssmd, map<UnicodeString, int>& MDRows, UnicodeString Code,
		UnicodeString Name, int ACol, UnicodeString& Value);
	void UpdateSSMetadata(bool ssmd, map<UnicodeString, int>& MDRows, UnicodeString Code,
		UnicodeString Name, int ACol, double Value);
	void UpdateSSLakeMetadata(bool ssmd, map<UnicodeString, int>& MDRows,
		map<UnicodeString, int>& LakeMDRows, LAKEPARAM& LakeParam, int ACol);
	int InsertNewSSMetaDataRow(map<UnicodeString, int>& mdrows, UnicodeString Code, UnicodeString Name);
public:		// User declarations
	__fastcall TUpdateNeotomaSiteForm(SITE* sptr, bool update, TComponent* Owner);
	__fastcall TUpdateNeotomaSiteForm(SITE* sptr, bool update, TComponent* Parent, TComponent* Owner);
};
//---------------------------------------------------------------------------

class TUpdateNeotomaCollUnitForm : public TUpdateNeotomaSiteForm
{
__published:	// IDE-managed Components
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall cxButton1Click(TObject *Sender);
	void __fastcall AdvColumnGrid1GetEditorType(TObject *Sender, int ACol, int ARow,
		  TEditorType &AEditor);
	void __fastcall AdvColumnGrid1ButtonClick(TObject *Sender, int ACol, int ARow);
	void __fastcall cxButton2Click(TObject *Sender);
private:
	vector<COLLECTION>::pointer coll_ptr;
	bool GetNeotomaCollUnitData(void);
	vector<NTMCONTACT> NtmCollectors;
public:		// User declarations
	__fastcall TUpdateNeotomaCollUnitForm(SITE* sptr, vector<COLLECTION>::pointer,
		bool update, TComponent* Owner);
	__fastcall TUpdateNeotomaCollUnitForm(SITE* sptr, vector<COLLECTION>::pointer,
		bool update, TComponent* Parent, TComponent* Owner);
};
//---------------------------------------------------------------------------

class TUpdateNeotomaDatasetForm : public TUpdateNeotomaSiteForm
{
__published:	// IDE-managed Components
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall cxButton1Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall AdvColumnGrid1GetEditorType(TObject *Sender, int ACol, int ARow,
		  TEditorType &AEditor);
private:
	DATASET* dataset_ptr;
	DATASET ntmdataset;
	TList* DatasetPubs;
	map<UnicodeString,UnicodeString> TilRepositories;
	bool GetNeotomaDatasetData(void);
public:		// User declarations
	__fastcall TUpdateNeotomaDatasetForm(SITE* sptr, DATASET* dptr, bool update, TComponent* Owner);

};
//---------------------------------------------------------------------------

class TNeotomaSiteValidationForm : public TNeotomaUploadForm
{
__published:	// IDE-managed Components
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall cxButton2Click(TObject *Sender);
private:	// User declarations
	TAdvColumnGrid* AdvColumnGrid1;
	void Validate(void);
	int RunValidation(void);
	void UpdateSiteData(void);
	bool UpdateGeoPol(int rank, UnicodeString Division, UnicodeString GeopolUnit);
	bool InsertGeoPol(int rank, UnicodeString Division, UnicodeString GeopolUnit);
	bool DeleteGeoPol(int rank, UnicodeString Division, UnicodeString GeopolUnit);
	map<int,int> GeoPolID;
public:		// User declarations
	__fastcall TNeotomaSiteValidationForm(SITE* sptr, TAdvColumnGrid* grid,
		map<int,int>& geopol_id, TComponent* Owner);
};
//---------------------------------------------------------------------------

class TNeotomaCollUnitValidationForm : public TNeotomaUploadForm
{
__published:	// IDE-managed Components
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall cxButton2Click(TObject *Sender);
private:	// User declarations
    vector<COLLECTION>::pointer coll_ptr;
	TAdvColumnGrid* AdvColumnGrid1;
	void Validate(void);
	int RunValidation(void);
	void UpdateCollUnitData(void);
public:		// User declarations
	__fastcall TNeotomaCollUnitValidationForm(vector<COLLECTION>::pointer,
		TAdvColumnGrid* grid, TComponent* Owner);
};
//---------------------------------------------------------------------------

class TNeotomaDatasetValidationForm : public TNeotomaUploadForm
{
__published:	// IDE-managed Components
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall cxButton2Click(TObject *Sender);
private:	// User declarations
	DATASET* dataset_ptr;
	DATASET ntmdataset;
	TAdvColumnGrid* AdvColumnGrid1;
	void Validate(void);
	int RunValidation(void);
	void UpdateDatasetData(void);
public:		// User declarations
	__fastcall TNeotomaDatasetValidationForm(DATASET* dptr, DATASET& nd,
		TAdvColumnGrid* grid, TComponent* Owner);
};

//---------------------------------------------------------------------------
extern PACKAGE TUpdateNeotomaSiteForm *UpdateNeotomaSiteForm;
extern PACKAGE TUpdateNeotomaCollUnitForm *UpdateNeotomaCollUnitForm;
extern PACKAGE TUpdateNeotomaDatasetForm *UpdateNeotomaDatasetForm;
extern PACKAGE TNeotomaSiteValidationForm *NeotomaSiteValidationForm;
extern PACKAGE TNeotomaCollUnitValidationForm *NeotomaCollUnitValidationForm;
extern PACKAGE TNeotomaDatasetValidationForm *NeotomaDatasetValidationForm;
//---------------------------------------------------------------------------
#endif
