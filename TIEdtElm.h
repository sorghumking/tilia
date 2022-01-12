//---------------------------------------------------------------------------

#ifndef TIEdtElmH
#define TIEdtElmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <CheckLst.hpp>
#include <Dialogs.hpp>
#include "cxButtons.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include <ImgList.hpp>
#include <Menus.hpp>
#include <ComCtrls.hpp>
#include "ipshttps.h"
#include "ipwjson.h"
#include <Sockets.hpp>
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxEdit.hpp"
#include "cxGroupBox.hpp"
#include "cxLabel.hpp"
#include "cxTextEdit.hpp"
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

//#ifndef TSUtilsH
//#include "TSUtils.h"
//#endif
#ifndef TICommonH
#include "TICommon.h"
#endif

//---------------------------------------------------------------------------
/*
typedef struct
{
  UnicodeString DatasetType;
  UnicodeString TaxaGroup;
} ELEMENTCATAGORY;
*/
//---------------------------------------------------------------------------

class TEditElementsForm : public TForm
{
__published:	// IDE-managed Components
	TListBox *ListBox2;
	TListBox *ListBox1;
	TCheckListBox *CheckListBox1;
	TCheckListBox *CheckListBox2;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TSaveDialog *SaveDialog1;
	TCheckListBox *CheckListBox3;
	TLabel *Label5;
	TFlowPanel *FlowPanel1;
	TcxButton *cxButton1;
	TcxImageList *cxImageList1;
	TcxButton *cxButton2;
	TListBox *ListBox3;
	TLabel *Label6;
	TFlowPanel *FlowPanel2;
	TEdit *Edit1;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	TLabel *Label10;
	TLabel *Label11;
	TLabel *Label12;
	TEdit *Edit6;
	TEdit *Edit2;
	TEdit *Edit3;
	TEdit *Edit4;
	TEdit *Edit5;
	TFlowPanel *FlowPanel3;
	TcxButton *cxButton3;
	TcxButton *cxButton4;
	TPanel *Panel1;
	TPanel *Panel2;
	TPanel *Panel3;
	TFlowPanel *FlowPanel4;
	TcxButton *cxButton5;
	TcxButton *cxButton6;
	TPanel *Panel4;
	TFlowPanel *FlowPanel5;
	TcxButton *cxButton7;
	TcxButton *cxButton8;
	TPanel *Panel5;
	TFlowPanel *FlowPanel6;
	TcxButton *cxButton9;
	TcxButton *cxButton10;
	TPanel *Panel6;
	TFlowPanel *FlowPanel7;
	TcxButton *cxButton11;
	TcxButton *cxButton12;
	TFlowPanel *FlowPanel8;
	TcxButton *cxButton13;
	TcxButton *cxButton14;
	TcxButton *cxButton15;
	TcxButton *cxButton16;
	TStatusBar *StatusBar1;
	TTcpClient *TcpClient1;
	TipsHTTPS *ipsHTTPS1;
	TPanel *Panel7;
	TipsJSONS *ipsJSONS1;
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall ListBox1Click(TObject *Sender);
	void __fastcall ListBox2Click(TObject *Sender);
	void __fastcall CheckListBox1ClickCheck(TObject *Sender);
	void __fastcall CheckListBox2ClickCheck(TObject *Sender);
	void __fastcall CheckListBox3ClickCheck(TObject *Sender);
	void __fastcall cxButton1Click(TObject *Sender);
	void __fastcall Edit1Change(TObject *Sender);
	void __fastcall Edit2Change(TObject *Sender);
	void __fastcall Edit3Change(TObject *Sender);
	void __fastcall Edit4Change(TObject *Sender);
	void __fastcall Edit5Change(TObject *Sender);
	void __fastcall cxButton2Click(TObject *Sender);
	void __fastcall ListBox3Click(TObject *Sender);
	void __fastcall Edit6Change(TObject *Sender);
	void __fastcall cxButton3Click(TObject *Sender);
	void __fastcall cxButton4Click(TObject *Sender);
	void __fastcall cxButton5Click(TObject *Sender);
	void __fastcall cxButton6Click(TObject *Sender);
	void __fastcall cxButton7Click(TObject *Sender);
	void __fastcall cxButton8Click(TObject *Sender);
	void __fastcall cxButton9Click(TObject *Sender);
	void __fastcall cxButton10Click(TObject *Sender);
	void __fastcall cxButton11Click(TObject *Sender);
	void __fastcall cxButton12Click(TObject *Sender);
	void __fastcall cxButton13Click(TObject *Sender);
	void __fastcall cxButton15Click(TObject *Sender);
	void __fastcall cxButton16Click(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall ipsJSONS1SSLServerAuthentication(TObject *Sender, TipsJSONSSSLServerAuthenticationEventParams *e);

private:	// User declarations
	friend class TNewTaxaGroupForm;
	bool Activated;
	//UnicodeString PathName;
	ELEMENTLOOKUP* ElementLookup;
	map<UnicodeString, map<UnicodeString, ELEMENTMODIFIERS> > AllModifiers;   // DatasetType, TaxaGroup, Modifiers
	TStringList* Elements;
	ELEMENTLOOKUP* LocalElementLookup;
	VARIABLELOOKUP* VarLookup;
	map<UnicodeString, int> ElementTypeIDs;
private:
	void LoadElementLookup(void);
	void Save(void);
	UnicodeString CurrentDatasetType(void) { return ListBox1->Items->Strings[ListBox1->ItemIndex]; }
	UnicodeString CurrentTaxaGroup(void)
	  { return (ListBox3->Count > 0 ? ListBox3->Items->Strings[ListBox3->ItemIndex] : UnicodeString(L"")); }
	UnicodeString CurrentElement(void);
	UnicodeString CurrentSymmetry(void);
	UnicodeString CurrentPortion(void);
	UnicodeString CurrentMaturity(void);
	void ChangeDatasetType(void);
	void ChangeTaxaGroup(void);
	void ChangeElement(void);
	void UploadElements(void);
	bool ValidateDatasetType(UnicodeString DatasetType, vector<int>& DatasetTypeIDs);
	bool ValidateTaxaGroup(UnicodeString& TaxaGroup, UnicodeString& TaxaGroupID);
	bool ValidateElementTypes(vector<int>& DatasetTypeIDs, UnicodeString TaxaGroupID);
	bool ValidateSymmetries(UnicodeString TaxaGroupID);
	bool ValidatePortions(UnicodeString TaxaGroupID);
	bool ValidateMaturities(UnicodeString TaxaGroupID);
public:		// User declarations
	__fastcall TEditElementsForm(VARIABLELOOKUP* var_lookup, TComponent* Owner);
	UnicodeString CurrentCategory(void);
	ELEMENTLOOKUP* GetElementLookup(void) { return ElementLookup; }
};
//---------------------------------------------------------------------------
extern PACKAGE TEditElementsForm *EditElementsForm;
//---------------------------------------------------------------------------
#endif
