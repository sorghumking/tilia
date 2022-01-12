//---------------------------------------------------------------------------

#ifndef TIChkVarFrmH
#define TIChkVarFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "cxButtons.hpp"
#include "cxCheckListBox.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxEdit.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include "AdvCGrid.hpp"
#include "AdvGrid.hpp"
#include "AdvObj.hpp"
#include "BaseGrid.hpp"
#include <Grids.hpp>
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

#ifndef TISpreadH
#include "TISpread.h"
#endif
#ifndef TIUploadH
#include "TIUpload.h"
#endif

//---------------------------------------------------------------------------
class TCheckZeroDataForm;
class TCheckNoDataForm;
class TMultiTaxonNamesForm;
//---------------------------------------------------------------------------

class TCheckListVarForm : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TcxButton *cxButton5;
	TcxButton *cxButton3;
	TcxButton *cxButton4;
	TcxButton *cxButton6;
	TMemo *Memo1;
	TAdvColumnGrid *AdvColumnGrid1;
	TcxButton *cxButton7;
	TcxButton *cxButton8;
	TFlowPanel *FlowPanel1;
	TcxButton *cxButton1;
	TcxButton *cxButton2;
	TFlowPanel *FlowPanel2;
	TPanel *Panel2;
	void __fastcall cxButton3Click(TObject *Sender);
	void __fastcall cxButton4Click(TObject *Sender);
	void __fastcall cxButton5Click(TObject *Sender);
	void __fastcall cxButton6Click(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall cxButton7Click(TObject *Sender);
	void __fastcall cxButton8Click(TObject *Sender);
	void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
	void __fastcall AdvColumnGrid1CheckBoxClick(TObject *Sender, int ACol, int ARow,
          bool State);
	void __fastcall cxButton1Click(TObject *Sender);
protected:
	TNeotomaUploadForm *UploadForm;
	TTilSpreadSheetForm *TSSForm;
	int FItemChecked;
private:	// User declarations
	friend class TCheckZeroDataForm;
	friend class TCheckNoDataForm;
	friend class TMultiTaxonNamesForm;
	bool CloseQuery;
public:		// User declarations
	__fastcall TCheckListVarForm(TComponent* Owner);
	vector<UnicodeString> OutputLines;
	vector<UnicodeString> OutputErrors;
	__property int ItemChecked = {read = FItemChecked};
};
//---------------------------------------------------------------------------

class TCheckDupsForm : public TCheckListVarForm
{
__published:	// IDE-managed Components
	void __fastcall cxButton7Click(TObject *Sender);
	void __fastcall cxButton8Click(TObject *Sender);
	void __fastcall AdvColumnGrid1CheckBoxClick(TObject *Sender, int ACol, int ARow,
		  bool State);
private:
	vector<DUPVAR> DupVars;
	vector<SSVAR> SSVarList;
public:
	__fastcall TCheckDupsForm(TComponent* Owner);
	void FillDupVars(vector<DUPVAR>&);
};
//---------------------------------------------------------------------------

class TCheckNoDataForm : public TCheckListVarForm
{
__published:	// IDE-managed Components
	void __fastcall cxButton7Click(TObject *Sender);
	void __fastcall cxButton8Click(TObject *Sender);
	void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
	void __fastcall AdvColumnGrid1CheckBoxClick(TObject *Sender, int ACol, int ARow,
		  bool State);
private:
	vector<EMPTYVAR> EmptyVars;
public:
	__fastcall TCheckNoDataForm(TComponent* Owner);
	void FillEmptyVars(vector<EMPTYVAR>&);
};
//---------------------------------------------------------------------------

class TMultiTaxonNamesForm : public TCheckListVarForm
{
__published:	// IDE-managed Components
	void __fastcall cxButton1Click(TObject *Sender);
	//void __fastcall cxButton7Click(TObject *Sender);
	void __fastcall cxButton8Click(TObject *Sender);
	void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
public:
	__fastcall TMultiTaxonNamesForm(TComponent* Owner);
	void FillMultiTaxonNames(int, UnicodeString, vector<UnicodeString>&);
	//int ItemChecked;
};
//---------------------------------------------------------------------------

class TCheckZeroDataForm : public TCheckListVarForm
{
__published:	// IDE-managed Components
	void __fastcall cxButton7Click(TObject *Sender);
	void __fastcall cxButton8Click(TObject *Sender);
	void __fastcall cxButton1Click(TObject *Sender);
	void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
	void __fastcall AdvColumnGrid1CheckBoxClick(TObject *Sender, int ACol, int ARow,
		  bool State);
private:
	vector<EMPTYVAR> ZeroVars;
	set<int> FZeroVarsAllowed;
	void DeleteCheckedRows(void);
public:
	__fastcall TCheckZeroDataForm(TComponent* Owner);
	void FillZeroVars(vector<EMPTYVAR>&);
	__property set<int> ZeroVarsAllowed = {read = FZeroVarsAllowed};
};

//---------------------------------------------------------------------------
extern PACKAGE TCheckListVarForm *CheckListVarForm;
//---------------------------------------------------------------------------
#endif
