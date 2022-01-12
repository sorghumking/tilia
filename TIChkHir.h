//---------------------------------------------------------------------------

#ifndef TIChkHirH
#define TIChkHirH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include "AdvCGrid.hpp"
#include "AdvGrid.hpp"
#include "AdvObj.hpp"
#include "BaseGrid.hpp"
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include "ipwjson.h"
#include <Sockets.hpp>
#include <Graphics.hpp>
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxEdit.hpp"
#include "cxGraphics.hpp"
#include "cxLabel.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include "cxButtons.hpp"
#include <Menus.hpp>
#include <ImgList.hpp>
#include "AdvUtil.hpp"
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
#include "ipsjsons.h"

#ifndef TGSpreadH
#include "TISpread.h"
#endif
#ifndef TIChkVarH
#include "TIChkVar.h"
#endif

//---------------------------------------------------------------------------
enum FIXTYPES { FIXNONEXCLUSIVETAXA, FIXNOSIBLINGS };
//---------------------------------------------------------------------------

typedef struct
{
  int row;
  UnicodeString old_name;
  UnicodeString new_name;
} VARCHANGE;
//---------------------------------------------------------------------------

class TCheckHierarchyForm : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TAdvColumnGrid *AdvColumnGrid1;
	TTcpClient *TcpClient1;
	TPanel *Panel2;
	TImage *Image1;
	TTimer *Timer1;
	TcxLabel *cxLabel1;
	TFlowPanel *FlowPanel1;
	TcxButton *cxButton1;
	TcxButton *cxButton2;
	TcxButton *cxButton3;
	TcxImageList *cxImageList1;
	TPanel *Panel3;
	TipsJSONS *ipsJSONS1;
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall cxButton1Click(TObject *Sender);
	void __fastcall cxButton3Click(TObject *Sender);
	void __fastcall ipsJSONS1SSLServerAuthentication(TObject *Sender, TipsJSONSSSLServerAuthenticationEventParams *e);


private:	// User declarations
	TTilSpreadSheetForm *TSSForm;
	bool activated;
	bool close_er_up;
	short FixType;
	int RatStart;
	int RatEnd;
	int RatPos;
	int nNonExclusive;
	int nNoSibs;
	int UnresolvedNonExclusive;
	vector<SSTAXANAME> Undiffs;
	vector<VARCHANGE> VarChanges;
	vector<SSVAR> SSVarList;
	//vector<SSVAR>::pointer ssvar_ptr;
private:
	static bool SSVARComp (SSVAR sv1, SSVAR sv2) { return (sv1.name < sv2.name); }
	//vector<SSVAR>::pointer __fastcall FindSSVAR(UnicodeString&);
	//void SortSSVarList(vector<SSVAR>& SSVarList);
	void AddMessage(int& row, int var_row, UnicodeString ErrMsg);
    bool GetTaxonHierarchy(SSVAR* ssvar, UnicodeString& ErrMsg);
	bool GetNeotomaHierarchy(void);
	void DiffCheckMutExlusive(void);
	void DiffCheckNoSibs(void);
	bool AddVarChange(int row, UnicodeString old_name, UnicodeString new_name);
	void FixNonExclusive(void);
	void FixNoSiblings(void);
public:		// User declarations
	__fastcall TCheckHierarchyForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TCheckHierarchyForm *CheckHierarchyForm;
//---------------------------------------------------------------------------
#endif
