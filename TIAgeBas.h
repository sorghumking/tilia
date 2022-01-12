//---------------------------------------------------------------------------

#ifndef TIAgeBasH
#define TIAgeBasH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
#include "cxButtons.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include <Menus.hpp>
#include "ipshttps.h"
#include "ipwjson.h"
#include <Sockets.hpp>
#include <ComCtrls.hpp>
#include "AdvCGrid.hpp"
#include "AdvGrid.hpp"
#include "AdvObj.hpp"
#include "BaseGrid.hpp"
#include <Grids.hpp>
#include <DBCtrls.hpp>
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxEdit.hpp"
#include "cxGroupBox.hpp"
#include "cxLabel.hpp"
#include "cxMemo.hpp"
#include "cxTextEdit.hpp"
#include "AdvControlDropDown.hpp"
#include "AdvDropDown.hpp"
#include "frmctrllink.hpp"
#include <Mask.hpp>
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
#include "AdvUtil.hpp"
#include "dxSkinOffice2016Colorful.hpp"
#include "dxSkinOffice2016Dark.hpp"
#include "dxSkinVisualStudio2013Blue.hpp"
#include "dxSkinVisualStudio2013Dark.hpp"
#include "dxSkinVisualStudio2013Light.hpp"
#include "ipsjsons.h"
#include <map>
//---------------------------------------------------------------------------
enum AGEBASISOPERATION { abOther, abEdit, abAddChild, abAddSibling };
//---------------------------------------------------------------------------

class TChronControlForm : public TForm
{
__published:	// IDE-managed Components
	TLabeledEdit *LabeledEdit1;
	TGroupBox *GroupBox1;
	TLabeledEdit *LabeledEdit2;
	TLabeledEdit *LabeledEdit3;
	TLabeledEdit *LabeledEdit4;
	TGroupBox *GroupBox2;
	TLabeledEdit *LabeledEdit5;
	TLabeledEdit *LabeledEdit6;
	TLabeledEdit *LabeledEdit7;
	TcxButton *cxButton1;
	TcxButton *cxButton2;
	TFlowPanel *FlowPanel1;
	TcxButton *cxButton3;
	TipsHTTPS *ipsHTTPS1;
	TTcpClient *TcpClient1;
	TStatusBar *StatusBar1;
	TMemo *Memo1;
	TLabel *Label1;
	TLabel *Label2;
	TcxButton *cxButton4;
	TPanel *Panel1;
	TPanel *Panel2;
	TPanel *Panel3;
	TPanel *Panel4;
	TAdvColumnGrid *AdvColumnGrid1;
	TFlowPanel *FlowPanel2;
	TcxButton *cxButton5;
	TcxGroupBox *cxGroupBox1;
	TcxLabel *cxLabel1;
	TcxMemo *cxMemo1;
	TAdvControlDropDown *AdvControlDropDown1;
	TFormControlEditLink *FormControlEditLink1;
	TComboBox *ComboBox1;
	TLabel *Label3;
	TcxImageList *cxImageList1;
	TipsJSONS *ipsJSONS1;
	void __fastcall cxButton3Click(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall FormControlEditLink1GetEditorValue(TObject *Sender, TAdvStringGrid *Grid,
          UnicodeString &AValue);
	void __fastcall FormControlEditLink1SetEditorValue(TObject *Sender, TAdvStringGrid *Grid,
          UnicodeString AValue);
	void __fastcall AdvColumnGrid1GetEditorProp(TObject *Sender, int ACol, int ARow,
          TEditLink *AEditLink);
	void __fastcall cxButton5Click(TObject *Sender);
	void __fastcall cxButton4Click(TObject *Sender);
	void __fastcall cxButton2Click(TObject *Sender);
	void __fastcall ipsJSONS1SSLServerAuthentication(TObject *Sender, TipsJSONSSSLServerAuthenticationEventParams *e);


private:	// User declarations
	TTreeNode* Node;
	short operation;
	bool IsRelAge;
	bool IsEvtAge;
	bool activated;
	int EventID;
	int RelativeAgeID;
	int RelativeAgeUnitID;
	UnicodeString RelativeAgeScale;
	map<UnicodeString,int> AgeUnitIDs;
private:
	bool LoggedIn(void);
	bool CheckAges(Variant C14AgeOlder, Variant C14AgeYounger, Variant C14Age,
		Variant CalAgeOlder, Variant CalAgeYounger, Variant CalAge);
	bool UpdateChronControlType(void);
	bool UploadChronControlType(void);
	bool UpdateEventAge(void);
	bool UploadEventAge(void);
	bool UpdateRelativeAge(void);
	bool UploadRelativeAge(void);
	void AddEventPub(void);
	void DeleteEventPub(void);
	void AddRelativeAgePub(void);
	void DeleteRelativeAgePub(void);
	void AddPub(void);
	void RemovePub(void);
public:		// User declarations
	__fastcall TChronControlForm(UnicodeString caption, TTreeNode* Node,
		bool is_rel_age, bool is_evt_age, TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TChronControlForm *ChronControlForm;
//---------------------------------------------------------------------------
#endif
