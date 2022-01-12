//---------------------------------------------------------------------------

#ifndef TIChkVarUnitsFrmH
#define TIChkVarUnitsFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "AdvGrid.hpp"
#include "AdvObj.hpp"
#include "BaseGrid.hpp"
#include "cxButtons.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <Menus.hpp>
#include "ipwjson.h"
#include <Sockets.hpp>
#include <ImgList.hpp>
#include "AdvCGrid.hpp"
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

#ifndef TISpreadH
#include "TISpread.h"
#endif
#ifndef TIUploadH
#include "TIUpload.h"
#endif

//---------------------------------------------------------------------------
class TCheckVarElementsForm;
//---------------------------------------------------------------------------

class TCheckVarUnitsForm : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TLabel *Label1;
	TTcpClient *TcpClient1;
	TImageList *ImageList1;
	TcxButton *cxButton1;
	TcxButton *cxButton2;
	TcxButton *cxButton5;
	TcxButton *cxButton3;
	TcxButton *cxButton4;
	TcxButton *cxButton6;
	TAdvColumnGrid *AdvColumnGrid1;
	TipsJSONS *ipsJSONS1;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall cxButton1Click(TObject *Sender);
	void __fastcall cxButton3Click(TObject *Sender);
	void __fastcall cxButton4Click(TObject *Sender);
	void __fastcall cxButton5Click(TObject *Sender);
	void __fastcall cxButton6Click(TObject *Sender);
	void __fastcall AdvColumnGrid1CheckBoxClick(TObject *Sender, int ACol, int ARow,
		  bool State);
	void __fastcall AdvColumnGrid1ButtonClick(TObject *Sender, int ACol, int ARow);
	void __fastcall AdvColumnGrid1EditCellDone(TObject *Sender, int ACol, int ARow);
	void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
	void __fastcall ipsJSONS1SSLServerAuthentication(TObject *Sender, TipsJSONSSSLServerAuthenticationEventParams *e);

protected:
	TNeotomaUploadForm* UploadForm;
	Graphics::TBitmap *RatGlyph;
private:	// User declarations
	friend class TCheckVarElementsForm;
	void FindTaxonUnits(UnicodeString, int);
	bool CloseQuery;
public:		// User declarations
	__fastcall TCheckVarUnitsForm(TComponent* Owner);
	void FillEmptyUnits(vector<EMPTYVAR>& EmptyUnits);
};
//---------------------------------------------------------------------------

class TCheckVarElementsForm : public TCheckVarUnitsForm
{
__published:	// IDE-managed Components
	void __fastcall AdvColumnGrid1CheckBoxClick(TObject *Sender, int ACol, int ARow,
		  bool State);
	void __fastcall AdvColumnGrid1ButtonClick(TObject *Sender, int ACol, int ARow);
	void __fastcall AdvColumnGrid1EditCellDone(TObject *Sender, int ACol, int ARow);
	void __fastcall cxButton1Click(TObject *Sender);
	void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
private:	// User declarations
	void FindTaxonElements(UnicodeString, int);
public:
	__fastcall TCheckVarElementsForm(TComponent* Owner);
	void FillEmptyElements(vector<EMPTYVAR>& EmptyElements);
};

//---------------------------------------------------------------------------
extern PACKAGE TCheckVarUnitsForm *CheckVarUnitsForm;
//---------------------------------------------------------------------------
#endif
