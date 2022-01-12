//---------------------------------------------------------------------------

#ifndef TNFindTaxonH
#define TNFindTaxonH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "cxButtons.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include "ipwjson.h"
#include <Sockets.hpp>
#include <ComCtrls.hpp>
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxEdit.hpp"
#include "cxTextEdit.hpp"
#include "cxLabel.hpp"
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
#include "ipsjsons.h"

#ifndef TIUtilsH
#include "TIUtils.h"
#endif
#ifndef TISpreadH
#include "TISpread.h"
#endif
#ifndef TIChkVarH
#include "TIChkVar.h"
#endif
#ifndef TIUploadH
#include "TIUpload.h"
#endif
#ifndef TINewTxnH
#include "TINewTxn.h"
#endif

class TNeotomaFindTaxonForm;
//---------------------------------------------------------------------------
class TFindTaxonForm : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TcxButton *cxButton1;
	TcxButton *cxButton2;
	TPanel *Panel3;
	TListBox *ListBox1;
	TPanel *Panel4;
	TLabel *Label2;
	TSplitter *Splitter1;
	TPanel *Panel5;
	TListBox *ListBox2;
	TcxButton *cxButton3;
	TcxButton *cxButton4;
	TPanel *Panel2;
	TPanel *Panel6;
	TPanel *Panel7;
	TPanel *Panel8;
	TTcpClient *TcpClient1;
	TStatusBar *StatusBar1;
	TPanel *Panel9;
	TFlowPanel *FlowPanel1;
	TcxTextEdit *cxTextEdit1;
	TcxLabel *cxLabel1;
	TcxImageList *cxImageList1;
	TipsJSONS *ipsJSONS1;
	void __fastcall cxButton1Click(TObject *Sender);
	void __fastcall cxButton2Click(TObject *Sender);
	void __fastcall ListBox2Click(TObject *Sender);
	void __fastcall ListBox1Click(TObject *Sender);
	void __fastcall cxButton4Click(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall cxButton3Click(TObject *Sender);
	void __fastcall cxTextEdit1KeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall cxTextEdit1PropertiesChange(TObject *Sender);
	void __fastcall ipsJSONS1SSLServerAuthentication(TObject *Sender, TipsJSONSSSLServerAuthenticationEventParams *e);


protected:  // User declarations
	bool ReplaceTaxonName(void);
private:	// User declarations
	friend class TNeotomaFindTaxonForm;
	TTaxaVector* TaxaList;
	vector<SSTAXANAME>* taxa_not_found;
	TTilSpreadSheetForm *TSSForm;
	short SubVarCodes;
	short SubGroups;
	short SubElements;
	short SubUnits;
	UnicodeString UnitsValue;
	UnicodeString OldName;
	UnicodeString NewName;
	int SSRow;
private:
	bool Search(void);
public:		// User declarations
	__fastcall TFindTaxonForm(vector<SSTAXANAME>* tnf, TTilSpreadSheetForm *tssform,
		TComponent* Owner);
	void SetTaxaList(TTaxaVector* tl) { TaxaList = tl; }
};
//---------------------------------------------------------------------------

class TNeotomaFindTaxonForm : public TFindTaxonForm
{
__published:	// IDE-managed Components
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall cxButton1Click(TObject *Sender);
	void __fastcall cxButton2Click(TObject *Sender);
	void __fastcall cxButton3Click(TObject *Sender);
	void __fastcall cxButton4Click(TObject *Sender);
	void __fastcall ListBox1Click(TObject *Sender);
	void __fastcall cxTextEdit1KeyPress(TObject *Sender, wchar_t &Key);
private:
	TList *TaxonPtrs;
	TNewTaxonForm* NewTaxonForm;
private:
    friend TNewTaxonForm;
	void (__closure *OutputLine)(UnicodeString);
	bool Search(void);
	void ClearTaxonPtrs(void);
public:		// User declarations            //void PassPtr(int (*pt2Func)(float, char, char))
	__fastcall TNeotomaFindTaxonForm(vector<SSTAXANAME>* tnf, void (__closure *output_line)(UnicodeString),
		TTilSpreadSheetForm *tssform, TComponent* Owner);
	bool NewSynonyms;
};

//---------------------------------------------------------------------------
extern PACKAGE TFindTaxonForm *FindTaxonForm;
//extern PACKAGE TNeotomaFindTaxonForm *NeotomaFindTaxonForm;
//---------------------------------------------------------------------------
#endif
