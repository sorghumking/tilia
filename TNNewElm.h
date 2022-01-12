//---------------------------------------------------------------------------

#ifndef TNNewElmH
#define TNNewElmH
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
#include <ImgList.hpp>
#include "cxMemo.hpp"
#include "cxRichEdit.hpp"
#include "cxTextEdit.hpp"
#include <ComCtrls.hpp>
#include "ipwjson.h"
#include "ipshttps.h"
#include <Sockets.hpp>
#include "cxButtons.hpp"
#include <Menus.hpp>
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
#include <set>
#include <map>

#ifndef TIUploadH
#include "TIUpload.h"
#endif
//---------------------------------------------------------------------------

class TNewElementsForm : public TForm
{
__published:	// IDE-managed Components
	TAdvColumnGrid *AdvColumnGrid1;
	TPanel *Panel2;
	TSplitter *Splitter1;
	TAdvColumnGrid *AdvColumnGrid2;
	TPanel *Panel1;
	TTcpClient *TcpClient1;
	TipsHTTPS *ipsHTTPS1;
	TFlowPanel *FlowPanel1;
	TPanel *Panel3;
	TcxLabel *cxLabel1;
	TcxButton *cxButton1;
	TcxMemo *cxMemo1;
	TcxRichEdit *cxRichEdit1;
	TcxButton *cxButton2;
	TcxButton *cxButton4;
	TPanel *StatusBar1;
	TcxImageList *cxImageList1;
	TipsJSONS *ipsJSONS1;
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall AdvColumnGrid2ButtonClick(TObject *Sender, int ACol, int ARow);
	void __fastcall cxButton1Click(TObject *Sender);
	void __fastcall AdvColumnGrid2GridHint(TObject *Sender, int ARow, int ACol, UnicodeString &hintstr);
	void __fastcall AdvColumnGrid2EditCellDone(TObject *Sender, int ACol, int ARow);
	void __fastcall AdvColumnGrid1RowChanging(TObject *Sender, int OldRow, int NewRow,
          bool &Allow);
	void __fastcall ipsJSONS1SSLServerAuthentication(TObject *Sender, TipsJSONSSSLServerAuthenticationEventParams *e);

private:	// User declarations
	bool activated;
	bool rat_button;
	int startsel;
	int lensel;
	UnicodeString NewElement;
	UnicodeString OldElement;
	UnicodeString EditingText;
	SSELEMENT* sselement;
	Graphics::TBitmap *ButtonGlyph;
	map<UnicodeString,int>* TaxaMap;            // TaxonName, TaxonID
	map<int,NEOTOMAVARIABLE>* NeotomaVariables;
	map<int,UnicodeString>* NeotomaDatasetTypes;
	//map<int, set<UnicodeString> > ElementTypes;  // row, set of current ElementTypes for taxon
	void FormatCaption(UnicodeString ItemType);
	bool GetElements(int TaxonID);
	void HighlightText(int start, int len);
	int GetSelection(UnicodeString Element, UnicodeString Part);
	void GetTaxaGroupIDs(vector<UnicodeString>& TaxaGroupIDs);
public:		// User declarations
	__fastcall TNewElementsForm(UnicodeString new_element, SSELEMENT* ss_element,
		map<UnicodeString,int>* taxa_map, map<int,NEOTOMAVARIABLE>* neotoma_variables,
		map<int,UnicodeString>* neotoma_dataset_types, TComponent* Owner);
	vector<UnicodeString> OutputLines;
	UnicodeString GetNewElement(void) { return NewElement; }
};
//---------------------------------------------------------------------------
extern PACKAGE TNewElementsForm *NewElementsForm;
//---------------------------------------------------------------------------
#endif
