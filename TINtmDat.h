//---------------------------------------------------------------------------

#ifndef TINtmDatH
#define TINtmDatH
#include "TIMapSit.h"
//---------------------------------------------------------------------------
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxDropDownEdit.hpp"
#include "cxEdit.hpp"
#include "cxGraphics.hpp"
#include "cxLabel.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Classes.hpp>
#include <Controls.hpp>
#include "cxButtons.hpp"
#include "cxGroupBox.hpp"
#include <Menus.hpp>
#include "ipwjson.h"
#include <Sockets.hpp>
#include "UWebGMaps.hpp"
#include "UWebGMapsCommon.hpp"
#include <Graphics.hpp>
#include <ImgList.hpp>
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
#include "AdvCGrid.hpp"
#include "AdvGrid.hpp"
#include "AdvObj.hpp"
#include "AdvUtil.hpp"
#include "BaseGrid.hpp"
#include <Grids.hpp>
#include "ipsjsons.h"

#ifndef TICommonH
#include "TICommon.h"
#endif
#ifndef TIJSONH
#include "TIJSON.h"
#endif

//---------------------------------------------------------------------------
class TNeotomaDataForm : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TWebGMaps *WebGMaps1;
	TcxComboBox *cxComboBox1;
	TcxLabel *cxLabel1;
	TTcpClient *TcpClient1;
	TStatusBar *StatusBar1;
	TcxTextEdit *cxTextEdit1;
	TcxLabel *cxLabel2;
	TFlowPanel *FlowPanel1;
	TcxButton *cxButton1;
	TcxButton *cxButton2;
	TcxLabel *cxLabel3;
	TcxComboBox *cxComboBox2;
	TcxComboBox *cxComboBox3;
	TcxLabel *cxLabel4;
	TcxComboBox *cxComboBox4;
	TcxLabel *cxLabel5;
	TcxComboBox *cxComboBox5;
	TcxLabel *cxLabel6;
	TcxGroupBox *PleaseWaitGroupBox;
	TImage *Image1;
	TcxLabel *cxLabel7;
	TTimer *Timer1;
	TcxComboBox *cxComboBox6;
	TcxLabel *cxLabel8;
	TcxComboBox *cxComboBox7;
	TcxLabel *cxLabel9;
	TcxImageList *cxImageList1;
	TcxButton *cxButton3;
	TcxButton *cxButton4;
	TcxButton *cxButton5;
	TFlowPanel *FlowPanel2;
	TcxButton *cxButton6;
	TcxButton *cxButton7;
	TAdvColumnGrid *AdvColumnGrid1;
	TPanel *Panel2;
	TipsJSONS *ipsJSONS1;
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall cxButton1Click(TObject *Sender);
	void __fastcall cxComboBox2Click(TObject *Sender);
	void __fastcall cxButton2Click(TObject *Sender);
	void __fastcall cxComboBox3Click(TObject *Sender);
	void __fastcall WebGMaps1MarkerClick(TObject *Sender, UnicodeString MarkerTitle,
		  int IdMarker, double Latitude, double Longitude, TMouseButton Button);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall cxComboBox6KeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall cxComboBox1KeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall cxComboBox7KeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall cxComboBox1PropertiesChange(TObject *Sender);
	void __fastcall cxComboBox6PropertiesChange(TObject *Sender);
	void __fastcall cxComboBox7PropertiesEditValueChanged(TObject *Sender);
	void __fastcall cxButton4Click(TObject *Sender);
	void __fastcall cxButton5Click(TObject *Sender);
	void __fastcall cxButton7Click(TObject *Sender);
	void __fastcall cxButton6Click(TObject *Sender);
	void __fastcall AdvColumnGrid1HoverButtonClick(TObject *Sender, int ARow, THoverButtonsCollectionItem *AButton);
	void __fastcall ipsJSONS1SSLServerAuthentication(TObject *Sender, TipsJSONSSSLServerAuthenticationEventParams *e);


protected:
	bool Launched;
	map<UnicodeString,int> GeoPol1;
	void HidePleaseWait();
private:	// User declarations
	int RatStart;
	int RatEnd;
	int RatPos;
	map<UnicodeString,int> DatasetTypes;
	map<int,NEOTOMASITELOC> Sites;
	map<UnicodeString,int> GeoPol2;
	map<UnicodeString,int> GeoPol3;
	map<UnicodeString,int> GeoPol4;
	map<UnicodeString,int> GeoPol14;
	map<UnicodeString,int> GeoPol24;
	map<UnicodeString,int> GeoPol34;
	vector<NTMALIASNAME> AliasNames;
	vector<MAPDATASET> FSelectedDatasets;
	bool AllContactsLoaded;
	bool AllAuthorsLoaded;
	map<UnicodeString,map<int,set<int> > > ContactMap;  // ContactName, DatasetTypeID, DatasetID
	map<UnicodeString,map<int,set<int> > > AuthorMap;   // ContactName, DatasetTypeID, DatasetID
	map<int,set<UnicodeString> > DatasetContactMap;     // DatasetTypeID, ContactName
	map<int,set<UnicodeString> > DatasetAuthorMap;      // DatasetTypeID, ContactName
	bool UseGoogleMaps;
private:
	void ShowPleaseWait(UnicodeString msg);
	void FillGeoPol4(void);
	void AddAliasNames(TcxComboBox* cxComboBox, map<UnicodeString,map<int,set<int> > >& ContactMap);
	void GetDatasetTypeIDList(map<int,set<UnicodeString> >& DatasetContactMap,
		UnicodeString& DatasetTypeIDList);
	void DownloadData(int SiteID, UnicodeString SiteName);
public:		// User declarations
	__fastcall TNeotomaDataForm(TComponent* Owner);
	__property vector<MAPDATASET> SelectedDatasets = {read = FSelectedDatasets};
};
//---------------------------------------------------------------------------

class TEPDDataForm : public TNeotomaDataForm
{
__published:	// IDE-managed Components
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall cxComboBox2Click(TObject *Sender);
	void __fastcall cxButton1Click(TObject *Sender);
	void __fastcall WebGMaps1MarkerClick(TObject *Sender, UnicodeString MarkerTitle,
		  int IdMarker, double Latitude, double Longitude, TMouseButton Button);
	void __fastcall cxButton7Click(TObject *Sender);
	void __fastcall cxButton6Click(TObject *Sender);
private:
	map<int,EPDSITELOC> Sites;
	int FSiteNr;
	int FENr;
	EPDSITELOC FEPDSiteLoc;
	map<UnicodeString,int> OldCountries;
	map<UnicodeString,int> NewCountries;
public:
	__fastcall TEPDDataForm(TComponent* Owner);
	__property int SiteNr = {read = FSiteNr};
	__property int ENr = {read = FENr};
	__property EPDSITELOC EPDSiteLoc = {read = FEPDSiteLoc};
};
//---------------------------------------------------------------------------

extern PACKAGE TNeotomaDataForm *NeotomaDataForm;
extern PACKAGE TEPDDataForm *EPDDataForm;
//---------------------------------------------------------------------------
#endif
