//---------------------------------------------------------------------------

#ifndef TNNewEcGrH
#define TNNewEcGrH
#include <vcl.h>
#include "pch.h"
#include "AdvCGrid.hpp"
#include "AdvGrid.hpp"
#include "AdvObj.hpp"
#include "BaseGrid.hpp"
#include "cxButtons.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxEdit.hpp"
#include "cxGraphics.hpp"
#include "cxGroupBox.hpp"
#include "cxLabel.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include "ipshttps.h"
#include "ipwjson.h"
#include <Classes.hpp>
#include <ComCtrls.hpp>
#include <Controls.hpp>
#include <Grids.hpp>
#include <Menus.hpp>
#include <Sockets.hpp>
#include <StdCtrls.hpp>
#include "cxClasses.hpp"
#include "cxCustomData.hpp"
#include "cxData.hpp"
#include "cxDataStorage.hpp"
#include "cxDBData.hpp"
#include "cxFilter.hpp"
#include "cxGrid.hpp"
#include "cxGridCustomTableView.hpp"
#include "cxGridCustomView.hpp"
#include "cxGridDBTableView.hpp"
#include "cxGridLevel.hpp"
#include "cxGridTableView.hpp"
#include "cxNavigator.hpp"
#include "cxStyles.hpp"
#include <DB.hpp>
#include "cxTextEdit.hpp"
#include "cxTimeEdit.hpp"
#include <ExtCtrls.hpp>
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
#include "dxSkinscxPCPainter.hpp"
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
#include <map>
#include <vector>
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxEdit.hpp"
#include "cxGraphics.hpp"
#include "cxGroupBox.hpp"
#include "cxLabel.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include "cxTextEdit.hpp"
#include <ComCtrls.hpp>
#include "AdvCGrid.hpp"
#include "AdvGrid.hpp"
#include "AdvObj.hpp"
#include "BaseGrid.hpp"
#include "cxButtons.hpp"
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <Menus.hpp>
#include "ipwjson.h"
#include <Sockets.hpp>
#include "ipshttps.h"
//---------------------------------------------------------------------------

class ECOLGROUP
{
public:
  UnicodeString EcolGroupID;
  UnicodeString EcolGroup;
public:
  ECOLGROUP() { };
  ECOLGROUP(UnicodeString id, UnicodeString eg) { EcolGroupID = id; EcolGroup = eg; }
  void Clear(void) { EcolGroupID = L""; EcolGroup = L""; }
};
//---------------------------------------------------------------------------

class TEcolGroup
{
private:
	vector<ECOLGROUP> Items;
	vector<ECOLGROUP>::pointer GetEcolGroup(int AIndex);
public:
	TEcolGroup() {}
	TEcolGroup(vector<ECOLGROUP>& EcolGroups);
	__fastcall ~TEcolGroup() {}
	void __fastcall Clear(void);
	void __fastcall Add(ECOLGROUP& EcolGroup);
	//void Delete(int AIndex);
	void Insert(int AIndex, ECOLGROUP& EcolGroup);
	int Count(void) { return Items.size(); }
	__property vector<ECOLGROUP>::pointer EcolGroup[int Index] = {read = GetEcolGroup};
	__property vector<ECOLGROUP> EcolGroups = {read = Items};
};
//---------------------------------------------------------------------------

class TNeotomaEcolGroupDataSource : public TcxCustomDataSource
{
private:
	TEcolGroup* FEcolGroup;
protected:
	void * __fastcall InsertRecord(void * ARecordHandle);
	void * __fastcall AppendRecord(void);
	//void __fastcall DeleteRecord(void * ARecordHandle);
	int __fastcall GetRecordCount(void);
	Variant __fastcall GetValue(void * ARecordHandle, void * AItemHandle);
	void __fastcall SetValue(void * ARecordHandle, void * AItemHandle, const Variant &AValue);
public:
	__fastcall TNeotomaEcolGroupDataSource(TEcolGroup* AEcolGroup);
	__fastcall ~TNeotomaEcolGroupDataSource() { }
	__property TEcolGroup* EcolGroup = {read = FEcolGroup};
};
//---------------------------------------------------------------------------

const int IndexOfEcolGroupID = 0;
const int IndexOfEcolGroup   = 1;
//---------------------------------------------------------------------------


class TNewEcolGroupForm : public TForm
{
__published:	// IDE-managed Components
	TcxGroupBox *cxGroupBox1;
	TcxButton *cxButton1;
	TTcpClient *TcpClient1;
	TipsHTTPS *ipsHTTPS1;
	TcxGridLevel *cxGrid1Level1;
	TcxGrid *cxGrid1;
	TcxGridTableView *cxGrid1TableView1;
	TcxGridColumn *egID;
	TcxGridColumn *egName;
	TcxStyleRepository *cxStyleRepository1;
	TcxStyle *cxStyle1;
	TcxStyle *cxStyle2;
	TPanel *StatusBar1;
	TipsJSONS *ipsJSONS1;
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall cxGrid1TableView1Editing(TcxCustomGridTableView *Sender, TcxCustomGridTableItem *AItem,
		  bool &AAllow);
	void __fastcall cxGrid1TableView1DataControllerBeforePost(TcxCustomDataController *ADataController);
	void __fastcall egIDPropertiesValidate(TObject *Sender, Variant &DisplayValue, TCaption &ErrorText,
          bool &Error);
	void __fastcall egNamePropertiesValidate(TObject *Sender, Variant &DisplayValue,
		  TCaption &ErrorText, bool &Error);
	void __fastcall cxGrid1TableView1FocusedRecordChanged(TcxCustomGridTableView *Sender,
          TcxCustomGridRecord *APrevFocusedRecord, TcxCustomGridRecord *AFocusedRecord,
          bool ANewItemRecordFocusingChanged);
	void __fastcall ipsJSONS1SSLServerAuthentication(TObject *Sender, TipsJSONSSSLServerAuthenticationEventParams *e);



private:	// User declarations
	bool Activated;
	bool CodeGood;
	bool NameGood;
	map<UnicodeString,UnicodeString> EcolGroups;
	void GetEcolGroupTypes(void);
	bool CheckCode(Variant &Value, TCaption &ErrorText);
	bool CheckName(Variant &Value, TCaption &ErrorText);
	void FillEcolGroupTypesGrid(map<UnicodeString, UnicodeString>& EcolGroups);
	int Upload(void);
	TEcolGroup* EcolGroupsList;
	TNeotomaEcolGroupDataSource* NeotomaEcolGroupDataSource;
	void __fastcall GenerateEcolGroupColumns();
public:		// User declarations
	__fastcall TNewEcolGroupForm(TComponent* Owner);
	map<UnicodeString,UnicodeString> NewEcolGroups;
	UnicodeString NewEcolTypeID;
};
//---------------------------------------------------------------------------
extern PACKAGE TNewEcolGroupForm *NewEcolGroupForm;
//---------------------------------------------------------------------------
#endif
