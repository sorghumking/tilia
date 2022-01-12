//---------------------------------------------------------------------------

#ifndef TGOrderH
#define TGOrderH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <OleCtrls.hpp>
#include <Buttons.hpp>
#include "cxClasses.hpp"
#include "cxControls.hpp"
#include "cxCustomData.hpp"
#include "cxData.hpp"
#include "cxEdit.hpp"
#include "cxFilter.hpp"
#include "cxGraphics.hpp"
#include "cxGrid.hpp"
#include "cxGridCustomTableView.hpp"
#include "cxGridCustomView.hpp"
#include "cxGridLevel.hpp"
#include "cxGridTableView.hpp"
#include "cxStyles.hpp"
#include <ImgList.hpp>
#include "cxCheckBox.hpp"
#include "cxDataStorage.hpp"
#include "cxTextEdit.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include "cxNavigator.hpp"
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

#ifndef TGDiagrmH
#include "TGDiagrm.h"
#endif
#ifndef TGHelpH
#include "TGHelp.h"
#endif


//---------------------------------------------------------------------------

typedef void __fastcall (__closure *TcxNotifyEvent)(void * Ptr, TListNotification Action);
class VAR
{
public:
  UnicodeString VarCode;
  UnicodeString VarName;
  bool Base;
  bool Overlay;
  bool Stack;
  bool Skip;
  bool Mark;

public:
  VAR() { Base=false; Overlay=false; Stack=false; Skip=false; Mark=false; }  
};

class TVarList : public TList
{
private:
	::TcxNotifyEvent FOnNotify;
	void ReleaseAllVars();
	void ReleaseVar(int AIndex);
	VAR* GetVar(int AIndex);
protected:
	void __fastcall Notify(void * Ptr, TListNotification Action);
	__property Items;
public:
	TVarList() {}
	__fastcall ~TVarList() {}
	void __fastcall Clear(void);
	__property VAR* Vars[int Index] = {read = GetVar};
	__property ::TcxNotifyEvent OnNotify = {read=FOnNotify, write=FOnNotify};
};

//---------------------------------------------------------------------------
class TVarDataSource : public TcxCustomDataSource
{
private:
    TVarList* FVars;
protected:
    int __fastcall GetRecordCount(void);
    Variant __fastcall GetValue(void * ARecordHandle, void * AItemHandle);
    void __fastcall Notify(void * Ptr, TListNotification Action);
    void __fastcall SetValue(void * ARecordHandle, void * AItemHandle, const Variant &AValue);
public:
    __fastcall TVarDataSource(TVarList* AVarList);
    __fastcall ~TVarDataSource() { }
};

//---------------------------------------------------------------------------
const int IndexOforVarName = 0;
const int IndexOforBase = 1;
const int IndexOforOverlay = 2;
const int IndexOforStack = 3;
const int IndexOforSkip = 4;
const int IndexOforMark = 5;


//---------------------------------------------------------------------------
class TOrderForm : public TForm
{
__published:	// IDE-managed Components
        TBitBtn *BitBtn1;
        TBitBtn *BitBtn2;
        TBitBtn *BitBtn3;
        TBitBtn *BitBtn4;
        TBitBtn *BitBtn5;
        TButton *Button1;
        TButton *Button2;
        TButton *Button3;
        TButton *Button4;
        TButton *Button5;
        TButton *Button6;
        TBitBtn *BitBtn6;
        TBitBtn *BitBtn7;
        TBitBtn *BitBtn8;
        TBitBtn *BitBtn9;
        TBitBtn *BitBtn10;
        TcxGridLevel *OrderGridLevel1;
        TcxGrid *OrderGrid;
        TcxGridTableView *OrderGridTableView;
        TcxGridColumn *orVarName;
        TcxGridColumn *orBase;
        TcxGridColumn *orOverlay;
        TcxGridColumn *orStack;
        TcxGridColumn *orSkip;
        TcxGridColumn *orMark;
        void __fastcall FormActivate(TObject *Sender);
        void __fastcall BitBtn1Click(TObject *Sender);
        void __fastcall BitBtn2Click(TObject *Sender);
        void __fastcall BitBtn3Click(TObject *Sender);
        void __fastcall BitBtn4Click(TObject *Sender);
        void __fastcall BitBtn5Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall BitBtn6Click(TObject *Sender);
        void __fastcall BitBtn7Click(TObject *Sender);
        void __fastcall BitBtn8Click(TObject *Sender);
        void __fastcall BitBtn9Click(TObject *Sender);
        void __fastcall BitBtn10Click(TObject *Sender);
        void __fastcall Button6Click(TObject *Sender);
        void __fastcall FormDeactivate(TObject *Sender);
        void __fastcall orMarkPropertiesEditValueChanged(TObject *Sender);
        void __fastcall orOverlayPropertiesChange(TObject *Sender);
        void __fastcall orStackPropertiesChange(TObject *Sender);
        void __fastcall orSkipPropertiesChange(TObject *Sender);
        void __fastcall orBasePropertiesChange(TObject *Sender);
        void __fastcall OrderGridTableViewMouseUp(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall OrderGridTableViewInitEdit(
          TcxCustomGridTableView *Sender, TcxCustomGridTableItem *AItem,
          TcxCustomEdit *AEdit);
        void __fastcall OrderGridTableViewFocusedItemChanged(
          TcxCustomGridTableView *Sender,
          TcxCustomGridTableItem *APrevFocusedItem,
          TcxCustomGridTableItem *AFocusedItem);
        bool __fastcall FormHelp(WORD Command, int Data, bool &CallHelp);
        void __fastcall orVarNameGetDisplayText(
          TcxCustomGridTableItem *Sender, TcxCustomGridRecord *ARecord,
          UnicodeString &AText);
        void __fastcall OrderGridTableViewEditKeyUp(
          TcxCustomGridTableView *Sender, TcxCustomGridTableItem *AItem,
          TcxCustomEdit *AEdit, WORD &Key, TShiftState Shift);
private:	// User declarations
        void CheckCheckBoxes(void);
		void ToggleStyle(UnicodeString);
        void ToggleStyle(int Style);
		void AutoItalics(UnicodeString&, UnicodeString&);
        long CopyBlockRow;
        long CopyBlockRow2;
        long EditRow;
        int CurPos;
        int SelLen;
        TVarList* VarList;
        TVarDataSource* VarDataSource;
        void __fastcall GenerateVarColumns();
        void __fastcall LoadVarData();
        void CheckForMarkedRecords(bool);
        void __fastcall EditKeyUp(TObject *Sender, WORD &Key, TShiftState Shift);
        void __fastcall EditKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
        void __fastcall EditMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
        void __fastcall EditMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
        void EnableButtons(void);
public:		// User declarations
        __fastcall TOrderForm(TComponent* Owner);
        TTGDiagram *Diag;
};
//---------------------------------------------------------------------------
extern PACKAGE TOrderForm *OrderForm;
//---------------------------------------------------------------------------
#endif
