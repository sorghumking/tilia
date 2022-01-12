//---------------------------------------------------------------------------

#ifndef TNAnlUntH
#define TNAnlUntH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include "AdvCGrid.hpp"
#include "AdvGrid.hpp"
#include "AdvObj.hpp"
#include "AdvUtil.hpp"
#include "BaseGrid.hpp"
#include <Grids.hpp>
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxEdit.hpp"
#include "cxGraphics.hpp"
#include "cxGroupBox.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include "cxRadioGroup.hpp"
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
#ifndef TIUploadH
#include "TIUpload.h"
#endif
#ifndef TIJSONH
#include "TIJSON.h"
#endif

//---------------------------------------------------------------------------
class AnalUnitMatch
{
public:
	bool depth;
	bool thick;
	bool name;
public:
	AnalUnitMatch() { depth = false; thick = false; name = false; }
};
//---------------------------------------------------------------------------

class StorePos
{
private:
	TAdvColumnGrid *AdvColumnGrid1;
	int ARow;
	int ACol;
public:
	StorePos(TAdvColumnGrid *acg) {AdvColumnGrid1 = acg; ACol = acg->Col; ARow = acg->Row; }
	void MoveTo(void);
};
//---------------------------------------------------------------------------

class TAnalUnitMatchForm : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TPanel *Panel2;
	TAdvColumnGrid *AdvColumnGrid1;
	TAdvColumnGrid *AdvColumnGrid2;
	TcxRadioButton *cxRadioButton1;
	TcxRadioButton *cxRadioButton2;
	TcxButton *cxButton1;
	TcxButton *cxButton2;
	TcxImageList *cxImageList1;
	TFlowPanel *FlowPanel1;
	TcxRadioButton *cxRadioButton3;
	TcxRadioButton *cxRadioButton4;
	TcxRadioButton *cxRadioButton5;
	TcxRadioButton *cxRadioButton6;
	TCheckBox *CheckBox1;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall AdvColumnGrid1SelectionChanged(TObject *Sender, int ALeft, int ATop,
          int ARight, int ABottom);
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall AdvColumnGrid1Resize(TObject *Sender);
	void __fastcall cxRadioButton1Click(TObject *Sender);
	void __fastcall cxRadioButton2Click(TObject *Sender);
	void __fastcall cxButton2Click(TObject *Sender);
	void __fastcall AdvColumnGrid1ButtonClick(TObject *Sender, int ACol, int ARow);
	void __fastcall AdvColumnGrid1CanClickCell(TObject *Sender, int ARow, int ACol,
          bool &Allow);
	void __fastcall AdvColumnGrid1CellBalloon(TObject *Sender, int ACol, int ARow, UnicodeString &ATitle,
          UnicodeString &AText, int &AIcon);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall cxRadioButton3Click(TObject *Sender);
	void __fastcall cxRadioButton4Click(TObject *Sender);
	void __fastcall cxRadioButton5Click(TObject *Sender);
	void __fastcall cxRadioButton6Click(TObject *Sender);
private:
	bool TilAnalUnitIsEmpty(int row);
	bool NtmAnalUnitIsEmpty(int row);
	void CopyTil(int to, int from);
	void CopyNtm(int to, int from);
	void MatchByDepth(void);
	void MatchByName(void);
	void NoMatches(void);
	void GetRemainingAnalUnits(void);
	bool FReplaceEPDDataset;
private:	// User declarations
	vector<NEOTOMAANALUNIT>* TilAnalUnits;
	vector<NTMANALYSISUNIT>* NtmAnalUnits;
	vector<float> ColWidthProps;
	bool activated;
	Graphics::TBitmap *TiliaBmp;
	Graphics::TBitmap *RatBmp;
	set<double> depths;
	multimap<double,unsigned int> tildepthidx;
	multimap<double,unsigned int> ntmdepthidx;
	set<unsigned int> tilidx;
	set<unsigned int> ntmidx;
	set<UnicodeString> names;
	map<UnicodeString,unsigned int> tilnameidx;
	map<UnicodeString,unsigned int> ntmnameidx;
	map<UnicodeString,UnicodeString> tilnames;
	map<UnicodeString,UnicodeString> ntmnames;
public:		// User declarations
	__fastcall TAnalUnitMatchForm(vector<NEOTOMAANALUNIT>* tilAnalUnits,
		vector<NTMANALYSISUNIT>* ntmAnalUnits, int EPDSiteID, TComponent* Owner);
	__property bool ReplaceEPDDataset = {read = FReplaceEPDDataset};
};
//---------------------------------------------------------------------------
extern PACKAGE TAnalUnitMatchForm *AnalUnitMatchForm;
//---------------------------------------------------------------------------
#endif
