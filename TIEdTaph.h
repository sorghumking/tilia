//---------------------------------------------------------------------------

#ifndef TIEdTaphH
#define TIEdTaphH
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
#include "cxListBox.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include "cxButtons.hpp"
#include "cxDropDownEdit.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include <ExtCtrls.hpp>
#include <ImgList.hpp>
#include <Menus.hpp>
#include "cxGroupBox.hpp"
#include <ComCtrls.hpp>
#include "ipwjson.h"
#include <Sockets.hpp>
#include "ipshttps.h"
#include "cxMemo.hpp"
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
#ifndef TICommonH
#include "TICommon.h"
#endif

enum TAPHNOTESSHOWING { TAPHSYSTEMNOTES, TAPHTYPENOTES };

//---------------------------------------------------------------------------
class TEditTaphonomyForm : public TForm
{
__published:	// IDE-managed Components
	TcxListBox *cxListBox1;
	TcxLabel *cxLabel1;
	TcxListBox *cxListBox2;
	TcxLabel *cxLabel2;
	TcxListBox *cxListBox3;
	TcxLabel *cxLabel3;
	TFlowPanel *FlowPanel1;
	TcxButton *cxButton1;
	TcxButton *cxButton2;
	TcxImageList *cxImageList1;
	TcxTextEdit *cxTextEdit1;
	TcxLabel *cxLabel4;
	TcxComboBox *cxComboBox1;
	TcxLabel *cxLabel5;
	TcxTextEdit *cxTextEdit2;
	TcxLabel *cxLabel6;
	TcxGroupBox *cxGroupBox1;
	TcxLabel *cxLabel7;
	TFlowPanel *FlowPanel2;
	TcxButton *cxButton3;
	TcxButton *cxButton4;
	TFlowPanel *FlowPanel3;
	TcxButton *cxButton5;
	TcxButton *cxButton6;
	TcxButton *cxButton7;
	TcxButton *cxButton8;
	TcxLabel *cxLabel8;
	TcxLabel *cxLabel9;
	TcxTextEdit *cxTextEdit4;
	TPanel *Panel1;
	TcxComboBox *cxComboBox2;
	TPanel *Panel2;
	TcxButton *cxButton9;
	TcxButton *cxButton10;
	TcxButton *cxButton11;
	TcxButton *cxButton12;
	TFlowPanel *FlowPanel4;
	TStatusBar *StatusBar1;
	TTcpClient *TcpClient1;
	TipsHTTPS *ipsHTTPS1;
	TcxButton *cxButton13;
	TcxButton *cxButton14;
	TcxGroupBox *cxGroupBox2;
	TcxButton *cxButton15;
	TcxButton *cxButton16;
	TcxLabel *cxLabel11;
	TcxMemo *cxMemo1;
	TPanel *Panel3;
	TcxLabel *cxLabel10;
	TipsJSONS *ipsJSONS1;
	void __fastcall cxListBox1Click(TObject *Sender);
	void __fastcall cxListBox2Click(TObject *Sender);
	void __fastcall cxComboBox1Click(TObject *Sender);
	void __fastcall cxButton1Click(TObject *Sender);
	void __fastcall cxButton7Click(TObject *Sender);
	void __fastcall cxButton2Click(TObject *Sender);
	void __fastcall cxTextEdit1PropertiesChange(TObject *Sender);
	void __fastcall cxButton3Click(TObject *Sender);
	void __fastcall cxButton4Click(TObject *Sender);
	void __fastcall cxTextEdit2PropertiesChange(TObject *Sender);
	void __fastcall cxButton5Click(TObject *Sender);
	void __fastcall cxButton6Click(TObject *Sender);
	void __fastcall cxButton11Click(TObject *Sender);
	void __fastcall cxButton9Click(TObject *Sender);
	void __fastcall cxButton12Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall cxButton13Click(TObject *Sender);
	void __fastcall cxButton14Click(TObject *Sender);
	void __fastcall cxButton15Click(TObject *Sender);
	void __fastcall cxButton16Click(TObject *Sender);
	void __fastcall cxMemo1PropertiesChange(TObject *Sender);
	void __fastcall cxComboBox1PropertiesChange(TObject *Sender);
	void __fastcall ipsJSONS1SSLServerAuthentication(TObject *Sender, TipsJSONSSSLServerAuthenticationEventParams *e);

private:	// User declarations
	VARIABLELOOKUP* VarLookup;
	TAPHONOMYLOOKUP* TaphonomyLookup;
	TAPHONOMYLOOKUP* OriginalTaphLookup;
	short NotesShowing;
	NTMTAPHONOMICSYSTEMS TaphSystemNotes;
	NTMTAPHONOMICTYPES TaphTypeNotes;
private:
	void SetNewDatasetType(void);
	void RemoveDatasetType(UnicodeString DatasetType);
	void DeleteListBoxItem(TcxListBox* cxListBox, UnicodeString DatasetType);
	bool AddListBoxItem(TcxListBox* cxListBox, UnicodeString Item);
	UnicodeString CurrentDatasetType(void);
	UnicodeString CurrentSystem(void);
	UnicodeString CurrentType(void);
	void UploadTaphonomy(void);
	bool ValidateDatasetType(UnicodeString DatasetType, int& DatasetTypeID);
	void EnableTypes(bool Enabled);
public:		// User declarations
	__fastcall TEditTaphonomyForm(VARIABLELOOKUP* varLookup, TStrings* DatasetTypes,
		TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TEditTaphonomyForm *EditTaphonomyForm;
//---------------------------------------------------------------------------
#endif
