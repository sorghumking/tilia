//---------------------------------------------------------------------------
#ifndef TIChkVarH
#define TIChkVarH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include "cxButtons.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include <Menus.hpp>
#include "ipwCore.h"
#include "ipwxmlp.h"
#include "cxCheckListBox.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxEdit.hpp"
#include <Buttons.hpp>
#include "cxLabel.hpp"
#include "cxTextEdit.hpp"
#include "cxDropDownEdit.hpp"
#include "cxMaskEdit.hpp"
#include "cxGroupBox.hpp"
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

#ifndef TISpreadH
#include "TISpread.h"
#endif
#ifndef TIUtilsH
#include "TIUtils.h"
#endif
#ifndef TIXMLH
#include "TIXML.h"
#endif

//---------------------------------------------------------------------------
//enum FIXTYPES { TAXANOTFOUND, FIXSYNONYMS, FIXDUPLICATES, FIXTAXANOTFOUND,
//				FIXNONEXCLUSIVETAXA, FIXNOSIBLINGS };
//---------------------------------------------------------------------------

class TCheckVarForm : public TForm
{
__published:	// IDE-managed Components
	TEdit *Edit1;
	TLabel *Label1;
	TOpenDialog *OpenDialog1;
	TRadioGroup *RadioGroup1;
	TRadioGroup *RadioGroup2;
	TRadioGroup *RadioGroup3;
	TRadioGroup *RadioGroup4;
	TcxButton *cxButton1;
	TcxButton *cxButton3;
	TcxButton *cxButton4;
	TFlowPanel *FlowPanel1;
	TPanel *Panel1;
	TcxLabel *cxLabel1;
	TcxComboBox *cxComboBox1;
	TFlowPanel *FlowPanel2;
	TcxGroupBox *cxGroupBox1;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall cxButton1Click(TObject *Sender);
	void __fastcall cxButton3Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall RadioGroup2Click(TObject *Sender);
	void __fastcall cxComboBox1PropertiesInitPopup(TObject *Sender);
private:	// User declarations
	friend class TFindTaxonForm;
	TTilSpreadSheetForm *TSSForm;
    vector<SSVAR> SSVarList;
	UnicodeString TaxaFile;
	UnicodeString HierarchyFile;
	UnicodeString UnitsValue;
	short FixType;
	map<int, TAXON*> TaxaIDIndex;   // index for Taxa by TaxaID's
	vector<SSTAXANAME> TaxaNotFound;
	vector<int> SynonymRows;
	vector<DUPVAR> DupVars;
	vector<UnicodeString> VarsNotFound;
	TTaxaVector* TaxaVector;
	vector<TAXAECOLGROUPS> TaxaEcolGroups;
	map<UnicodeString, int>* Synonyms;
	set<UnicodeString> Elements;
	bool LocalTaxaLookupOpen;
private:
	bool LoadTaxaLookup(void);
	void LoadElements(void);
	void FixSynonyms(void);
	void OtherTaxaNotFound(void);
	void CheckDuplicates(vector<SSVAR>& SSVarList);
public:		// User declarations
	__fastcall TCheckVarForm(TComponent* Owner);
	short SubVarCodes;
	short SubElements;
	short SubUnits;
	short SubGroups;
};
//---------------------------------------------------------------------------

class TNeotomaValidateTaxaForm : public TCheckVarForm
{
__published:	// IDE-managed Components
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall cxButton3Click(TObject *Sender);
public:		// User declarations
	__fastcall TNeotomaValidateTaxaForm(TComponent* Owner);
};

//---------------------------------------------------------------------------
extern PACKAGE TCheckVarForm *CheckVarForm;
extern PACKAGE TNeotomaValidateTaxaForm *NeotomaValidateTaxaForm;
//---------------------------------------------------------------------------
#endif
