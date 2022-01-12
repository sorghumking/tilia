//---------------------------------------------------------------------------

#ifndef TIMapSitH
#define TIMapSitH
#include <iostream.h>
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxEdit.hpp"
#include "cxGraphics.hpp"
#include "cxLabel.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include <ExtCtrls.hpp>
#include "AdvCGrid.hpp"
#include "AdvGrid.hpp"
#include "AdvObj.hpp"
#include "BaseGrid.hpp"
#include <Grids.hpp>
#include "cxButtons.hpp"
#include <Menus.hpp>
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
#include "AdvUtil.hpp"
#include "dxSkinOffice2016Colorful.hpp"
#include "dxSkinOffice2016Dark.hpp"
#include "dxSkinVisualStudio2013Blue.hpp"
#include "dxSkinVisualStudio2013Dark.hpp"
#include "dxSkinVisualStudio2013Light.hpp"
#include <vector>
#include <map>
//---------------------------------------------------------------------------
typedef struct
{
  int SiteID;
  int CollUnitID;
  UnicodeString CollUnitName;
  int DatasetID;
  UnicodeString DatasetType;
} MAPDATASET;
//---------------------------------------------------------------------------

class TMapSiteForm : public TForm
{
__published:	// IDE-managed Components
	TcxLabel *cxLabel1;
	TPanel *Panel1;
	TPanel *Panel2;
	TAdvColumnGrid *AdvColumnGrid1;
	TFlowPanel *FlowPanel1;
	TcxButton *cxButton1;
	TcxButton *cxButton2;
	TBalloonHint *BalloonHint1;
	TcxImageList *cxImageList1;
	void __fastcall AdvColumnGrid1CheckBoxClick(TObject *Sender, int ACol, int ARow,
		  bool State);
	void __fastcall cxButton1Click(TObject *Sender);
	void __fastcall AdvColumnGrid1CellBalloon(TObject *Sender, int ACol, int ARow, UnicodeString &ATitle,
		  UnicodeString &AText, int &AIcon);

private:	// User declarations
	int FSiteID;
	vector<MAPDATASET> FSelectedDatasets;
	map<int,UnicodeString> CollUnits;  // ID, Name
public:		// User declarations
	__fastcall TMapSiteForm(int SiteID, UnicodeString SiteName, vector<MAPDATASET>& MapDatasets,
		TComponent* Owner);
	__fastcall TMapSiteForm(TComponent* Owner);
	__property vector<MAPDATASET> SelectedDatasets = {read = FSelectedDatasets};
};
//---------------------------------------------------------------------------

class TEPDMapSiteForm : public TMapSiteForm
{
__published:   // IDE-managed Components
	void __fastcall cxButton1Click(TObject *Sender);
	void __fastcall AdvColumnGrid1CheckBoxClick(TObject *Sender, int ACol, int ARow,
		  bool State);
	void __fastcall AdvColumnGrid1CellBalloon(TObject *Sender, int ACol, int ARow, UnicodeString &ATitle,
		  UnicodeString &AText, int &AIcon);
private:
	int FENr;
public:		   // User declarations
	__fastcall TEPDMapSiteForm(UnicodeString SiteName, map<int, pair<UnicodeString,UnicodeString> >& Entities,
		TComponent* Owner);
	__property int ENr = {read = FENr};
};
//---------------------------------------------------------------------------

extern PACKAGE TMapSiteForm *MapSiteForm;
extern PACKAGE TEPDMapSiteForm *EPDMapSiteForm;
//---------------------------------------------------------------------------
#endif
