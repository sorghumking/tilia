//---------------------------------------------------------------------------

#ifndef TIWhitmoreH
#define TIWhitmoreH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <Menus.hpp>
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
#include "dxSkinOffice2016Colorful.hpp"
#include "dxSkinOffice2016Dark.hpp"
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
#include "dxSkinVisualStudio2013Blue.hpp"
#include "dxSkinVisualStudio2013Dark.hpp"
#include "dxSkinVisualStudio2013Light.hpp"
#include "dxSkinVS2010.hpp"
#include "dxSkinWhiteprint.hpp"
#include "dxSkinXmas2008Blue.hpp"
#include "BaseGrid.hpp"
#include "AdvCGrid.hpp"
#include "AdvGrid.hpp"
#include "AdvObj.hpp"
#include "AdvUtil.hpp"
#include <ADODB.hpp>
#include <DB.hpp>
#include "FlCtrlEx.hpp"
#include <FileCtrl.hpp>
#include "AdvNavBar.hpp"
#include "AdvEdBtn.hpp"
#include "AdvEdit.hpp"
#include "AdvFileNameEdit.hpp"
#include <vector>
#include <map>
#include <set>
#include <Menus.hpp>
#include <ADODB.hpp>
#include <DB.hpp>
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxEdit.hpp"
#include "cxLabel.hpp"
#include <ExtCtrls.hpp>
#include "AdvCGrid.hpp"
#include "AdvGrid.hpp"
#include "AdvObj.hpp"
#include "AdvUtil.hpp"
#include "BaseGrid.hpp"
#include <Grids.hpp>

#ifndef TISpreadH
#include "TISpread.h"
#endif
#ifndef TIContacH
#include "TIContac.h"
#endif
#ifndef TICommonH
#include "TICommon.h"
#endif
//#ifndef ENASS
//#define ENASS
//#endif

//---------------------------------------------------------------------------
typedef struct
{
  int ID1;
  UnicodeString AuthYr;
  UnicodeString Citation;
} CITATION;
//---------------------------------------------------------------------------

typedef struct
{
  UnicodeString TaxonCode;
  UnicodeString Element;
  UnicodeString Units;
  UnicodeString EcolGroup;
  map<int,double> Values;    // col, value
} WHITMOREVAR;
//---------------------------------------------------------------------------

class WMETADATA
{
public:
	int Row;
	UnicodeString Code;
	UnicodeString Name;
public:
	WMETADATA () { };
	WMETADATA(int row, UnicodeString code, UnicodeString name)
	  { Row = row; Code = code; Name = name; }
};
//---------------------------------------------------------------------------

class TWhitmoreForm : public TForm
{
__published:	// IDE-managed Components
	TcxButton *cxButton1;
	TADOConnection *ADOConnection1;
	TADODataSet *ADODataSet1;
	TPanel *Panel1;
	TAdvColumnGrid *AdvColumnGrid1;
	TcxButton *cxButton2;
	TAdvFileNameEdit *AdvFileNameEdit1;
	TcxButton *cxButton3;
	TADOQuery *ADOQuery1;
	TFlowPanel *FlowPanel1;
	TCheckBox *CheckBox1;
	TCheckBox *CheckBox2;
	void __fastcall cxButton1Click(TObject *Sender);
	void __fastcall AdvColumnGrid1CheckBoxClick(TObject *Sender, int ACol, int ARow,
		  bool State);
	void __fastcall AdvColumnGrid1ClickSort(TObject *Sender, int ACol);
	void __fastcall cxButton2Click(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall AdvFileNameEdit1ValueValidate(TObject *Sender, UnicodeString Value,
          bool &IsValid);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
	Access *WhitmoreAccess;
	bool activated;
	UnicodeString PubYear;
	int CheckedRow;
	int current_col;
	TTilSpreadSheetForm* TSSForm;
	map<UnicodeString,WMETADATA> md;
	vector<CITATION> Citations;
	map<UnicodeString,UnicodeString> UniqueCitations;
	map<UnicodeString,CONTACT*> People;
private:
	bool ConnectToWhitmore(void);
	void AddCollector(UnicodeString Collector, COLLECTION& CollUnit);
	void AddPI(UnicodeString Investigator);
	void ParseName(UnicodeString Name, CONTACT* Contact);
	void GetPubYear(UnicodeString AuthYr, UnicodeString& PubYear);
	void RunQuery(int ID1, UnicodeString SQL);
	void GetSiteMetadata(SITE* Site, UnicodeString& SiteCode);
	bool GetAltSiteName(SITE* Site);
	void GetCollUnitMetadata(COLLECTION& CollUnit, int ID1, UnicodeString SiteCode,
		vector<pair<UnicodeString,UnicodeString> >& de);
	void GetDatasetMetadata(UnicodeString AuthYr);
	void GetData(int col, map<UnicodeString,WHITMOREVAR>& wdata);
	// void UpdateSampleIDToWhitmore(vector<int>& ID1);
public:		// User declarations
	__fastcall TWhitmoreForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TWhitmoreForm *WhitmoreForm;
//---------------------------------------------------------------------------
#endif
