//---------------------------------------------------------------------------

#ifndef TIEdtModH
#define TIEdtModH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxDropDownEdit.hpp"
#include "cxEdit.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include "cxButtons.hpp"
#include <ImgList.hpp>
#include <Menus.hpp>
#include "cxListBox.hpp"
#include <ComCtrls.hpp>
#include "ipshttps.h"
#include "ipwjson.h"
#include <Sockets.hpp>
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

//#ifndef TSUtilsH
//#include "TSUtils.h"
//#endif
#ifndef TISpreadH
#include "TISpread.h"
#endif

//---------------------------------------------------------------------------
class TEditModifiersForm : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *Label2;
	TSpeedButton *SpeedButton2;
	TLabel *Label3;
	TcxComboBox *cxComboBox1;
	TFlowPanel *FlowPanel1;
	TcxButton *cxButton1;
	TcxButton *cxButton2;
	TcxImageList *cxImageList1;
	TcxListBox *cxListBox1;
	TcxListBox *cxListBox2;
	TcxTextEdit *cxTextEdit1;
	TLabel *Label4;
	TFlowPanel *FlowPanel2;
	TcxButton *cxButton3;
	TcxButton *cxButton4;
	TFlowPanel *FlowPanel3;
	TcxButton *cxButton5;
	TcxButton *cxButton6;
	TcxButton *cxButton7;
	TcxButton *cxButton8;
	TStatusBar *StatusBar1;
	TipsHTTPS *ipsHTTPS1;
	TTcpClient *TcpClient1;
	TipsJSONS *ipsJSONS1;
	void __fastcall cxComboBox1PropertiesChange(TObject *Sender);
	void __fastcall cxButton1Click(TObject *Sender);
	void __fastcall cxListBox1Click(TObject *Sender);
	void __fastcall cxButton2Click(TObject *Sender);
	void __fastcall cxListBox2Click(TObject *Sender);
	void __fastcall cxTextEdit1PropertiesChange(TObject *Sender);
	void __fastcall cxButton3Click(TObject *Sender);
	void __fastcall cxButton4Click(TObject *Sender);
	void __fastcall cxButton5Click(TObject *Sender);
	void __fastcall cxButton7Click(TObject *Sender);
	void __fastcall cxButton8Click(TObject *Sender);
	void __fastcall ipsJSONS1SSLServerAuthentication(TObject *Sender, TipsJSONSSSLServerAuthenticationEventParams *e);

private:	// User declarations
	friend class TEditUnitsForm;
	friend class TEditContextsForm;
	map<UnicodeString, set<UnicodeString> > Modifiers;    // e.g. DatasetType, Units
	VARIABLELOOKUP* VarLookup;
	virtual void Save(void) = 0;
	void SetModifiers(set<UnicodeString>& Items);
	bool ValidateDatasetType(UnicodeString DatasetType, vector<int>& DatasetTypeIDs);
	map<int, UnicodeString> NeotomaDatasetTypes;
public:		// User declarations
	__fastcall TEditModifiersForm(TComponent* Owner);
	void SetVarLookup(VARIABLELOOKUP* vl) { VarLookup = vl; };
	UnicodeString PathName;
};
//---------------------------------------------------------------------------

class TEditUnitsForm : public TEditModifiersForm
{
__published:
	void __fastcall cxButton5Click(TObject *Sender);
	void __fastcall cxButton8Click(TObject *Sender);
private:
	UNITLOOKUP* UnitLookup;
private:
	void Save(void);
	void UploadUnits(void);
	bool ValidateUnits(vector<int>& DatasetTypeIDs);
public:
	__fastcall TEditUnitsForm(VARIABLELOOKUP* var_lookup, TStrings* DatasetTypes,
		UnicodeString DatasetType, TComponent* Owner);
};
//---------------------------------------------------------------------------

class TEditContextsForm : public TEditModifiersForm
{
__published:
	void __fastcall cxButton5Click(TObject *Sender);
	void __fastcall cxButton8Click(TObject *Sender);
private:
	CONTEXTLOOKUP* ContextLookup;
private:
	void Save(void);
	void UploadContexts(void);
	bool ValidateContexts(vector<int>& DatasetTypeIDs);
public:
	__fastcall TEditContextsForm(VARIABLELOOKUP* var_lookup, TStrings* DatasetTypes,
		UnicodeString DatasetType, TComponent* Owner);
};
//---------------------------------------------------------------------------

class TEditFaciesForm : public TEditModifiersForm
{
__published:
	void __fastcall cxButton5Click(TObject *Sender);
	void __fastcall cxButton8Click(TObject *Sender);
	void __fastcall cxButton3Click(TObject *Sender);
	void __fastcall cxButton4Click(TObject *Sender);
private:
	TTilSpreadSheetForm* TSSForm;
private:
	void Save(void);
	void UpdateFacies(void);
public:
	__fastcall TEditFaciesForm(vector<UnicodeString>& facies_types,
		UnicodeString facies, TTilSpreadSheetForm* tssform, TComponent* Owner);
	vector<UnicodeString> OutputMessages;
};
//---------------------------------------------------------------------------

class TEditDepAgentsForm : public TEditModifiersForm
{
__published:
	void __fastcall cxButton5Click(TObject *Sender);
	void __fastcall cxButton8Click(TObject *Sender);
	void __fastcall cxButton3Click(TObject *Sender);
	void __fastcall cxButton4Click(TObject *Sender);
private:
	TTilSpreadSheetForm* TSSForm;
private:
	void Save(void);
	void UpdateDepAgents(void);
public:
	__fastcall TEditDepAgentsForm(vector<UnicodeString>& dep_agents,
		UnicodeString dep_agent, TTilSpreadSheetForm* tssform, TComponent* Owner);
	vector<UnicodeString> OutputMessages;
};
//---------------------------------------------------------------------------

extern PACKAGE TEditModifiersForm *EditModifiersForm;
extern PACKAGE TEditUnitsForm *EditUnitsForm;
extern PACKAGE TEditContextsForm *EditContextsForm;
extern PACKAGE TEditFaciesForm *EditFaciesForm;
extern PACKAGE TEditDepAgentsForm *EditDepAgentsForm;
//---------------------------------------------------------------------------
#endif
