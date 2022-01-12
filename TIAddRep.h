//---------------------------------------------------------------------------

#ifndef TIAddRepH
#define TIAddRepH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "cxBlobEdit.hpp"
#include "cxButtons.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxDropDownEdit.hpp"
#include "cxEdit.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include "cxGraphics.hpp"
#include "cxLookAndFeels.hpp"
#include <ImgList.hpp>
#include "ipshttps.h"
#include "ipwjson.h"
#include <Sockets.hpp>
#include <ComCtrls.hpp>
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
#include "cxLabel.hpp"
#include "ipsjsons.h"

#ifndef TISpreadH
#include "TISpread.h"
#endif

//---------------------------------------------------------------------------
class TAddRepositoryForm : public TForm
{
__published:	// IDE-managed Components
	TcxBlobEdit *cxBlobEdit1;
	TcxButton *cxButton1;
	TcxButton *cxButton2;
	TFlowPanel *FlowPanel1;
	TcxButton *cxButton3;
	TcxImageList *cxImageList1;
	TipsHTTPS *ipsHTTPS1;
	TTcpClient *TcpClient1;
	TStatusBar *StatusBar1;
	TcxTextEdit *cxTextEdit1;
	TcxTextEdit *cxTextEdit2;
	TcxLabel *cxLabel1;
	TcxLabel *cxLabel2;
	TcxLabel *cxLabel3;
	TipsJSONS *ipsJSONS1;
	void __fastcall cxButton1Click(TObject *Sender);
	void __fastcall cxButton3Click(TObject *Sender);
	void __fastcall cxTextEdit1PropertiesChange(TObject *Sender);
	void __fastcall cxTextEdit2PropertiesChange(TObject *Sender);
	void __fastcall cxTextEdit1PropertiesValidate(TObject *Sender, Variant &DisplayValue,
          TCaption &ErrorText, bool &Error);
	void __fastcall cxTextEdit2PropertiesValidate(TObject *Sender, Variant &DisplayValue,
          TCaption &ErrorText, bool &Error);
	void __fastcall cxButton2MouseEnter(TObject *Sender);
	void __fastcall cxButton2MouseLeave(TObject *Sender);
	void __fastcall ipsJSONS1SSLServerAuthentication(TObject *Sender, TipsJSONSSSLServerAuthenticationEventParams *e);

private:	// User declarations
    friend class TEditRepositoryForm;
	bool CancelClicked;
	TAdvColumnGrid* AdvColumnGrid2;
	bool AcronymExists(void);
	bool RepositoryExists(void);
	bool AcronymInNeotoma(UnicodeString Acronym, bool& error);
	bool RepositoryInNeotoma(UnicodeString Repository, bool& error);
public:		// User declarations
	__fastcall TAddRepositoryForm(TAdvColumnGrid* advcolgrid, TComponent* Owner);
};
//---------------------------------------------------------------------------

class TEditRepositoryForm : public TAddRepositoryForm
{
__published:	// IDE-managed Components
	void __fastcall cxButton3Click(TObject *Sender);
private:
	UnicodeString OriginalAcronym;
	UnicodeString OriginalRepository;
	UnicodeString OriginalNotes;
public:
	__fastcall TEditRepositoryForm(TAdvColumnGrid* advcolgrid, UnicodeString notes,
		TComponent* Owner);
};

//---------------------------------------------------------------------------
extern PACKAGE TAddRepositoryForm *AddRepositoryForm;
extern PACKAGE TEditRepositoryForm *EditRepositoryForm;
//---------------------------------------------------------------------------
#endif
