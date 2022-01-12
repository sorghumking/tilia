//---------------------------------------------------------------------------

#ifndef TGDatFrmH
#define TGDatFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
#include <Dialogs.hpp>
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
#include "cxDataStorage.hpp"
#include "cxTextEdit.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include "cxButtons.hpp"
#include <Menus.hpp>
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

//---------------------------------------------------------------------------

typedef void __fastcall (__closure *TcxNotifyEvent)(void * Ptr, TListNotification Action);

class TDateList : public TList
{
private:
	::TcxNotifyEvent FOnNotify;
    void ReleaseAllDates();
    void ReleaseDate(int AIndex);
    DATES* GetDate(int AIndex);
protected:
    void __fastcall Notify(void * Ptr, TListNotification Action);
    __property Items;
public:
    TDateList() {}
    __fastcall ~TDateList() {}
    void __fastcall Clear(void);
    void Add(DATES* Date);
    void Delete(int AIndex);
    void Insert(int AIndex, DATES* Date);
    __property DATES* Dates[int Index] = {read = GetDate};
    __property ::TcxNotifyEvent OnNotify = {read=FOnNotify, write=FOnNotify};
};

//---------------------------------------------------------------------------
class TDateDataSource : public TcxCustomDataSource
{
private:
    TDateList* FDates;
protected:
    void * __fastcall InsertRecord(void * ARecordHandle);
    void * __fastcall AppendRecord(void);
    void __fastcall DeleteRecord(void * ARecordHandle);
    int __fastcall GetRecordCount(void);
    Variant __fastcall GetValue(void * ARecordHandle, void * AItemHandle);
    void __fastcall Notify(void * Ptr, TListNotification Action);
    void __fastcall SetValue(void * ARecordHandle, void * AItemHandle, const Variant &AValue);
public:
    __fastcall TDateDataSource(TDateList* ADateList);
    __fastcall ~TDateDataSource() { }
};

//---------------------------------------------------------------------------
const int IndexOfdaTopDepth = 0;
const int IndexOfdaBottomDepth = 1;
const int IndexOfdaDate = 2;
const int IndexOfdaOffset = 3;

//---------------------------------------------------------------------------
class TDatesForm : public TForm
{
__published:	// IDE-managed Components
        TRadioGroup *RadioGroup1;
        TGroupBox *GroupBox1;
        TEdit *Edit1;
        TRadioGroup *RadioGroup2;
        TGroupBox *GroupBox2;
        TColorBox *ColorBox1;
        TLabeledEdit *LabeledEdit1;
        TLabeledEdit *LabeledEdit2;
        TLabeledEdit *LabeledEdit3;
        TLabel *Label1;
        TcxGrid *DatesGrid;
        TcxGridLevel *DatesGridLevel1;
        TcxGridTableView *DatesGridTableView;
        TcxGridColumn *daTopDepth;
        TcxGridColumn *daBottomDepth;
        TcxGridColumn *daDate;
        TcxGridColumn *daOffset;
	TcxButton *cxButton1;
	TcxButton *cxButton2;
	TcxButton *cxButton3;
	TcxButton *cxButton4;
	TcxButton *cxButton5;
	TcxButton *cxButton6;
        void __fastcall FormActivate(TObject *Sender);
        void __fastcall RadioGroup2Click(TObject *Sender);
        void __fastcall FormDeactivate(TObject *Sender);
        void __fastcall DatesGridTableViewFocusedItemChanged(
          TcxCustomGridTableView *Sender,
          TcxCustomGridTableItem *APrevFocusedItem,
          TcxCustomGridTableItem *AFocusedItem);
        bool __fastcall FormHelp(WORD Command, int Data, bool &CallHelp);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall DatesGridTableViewEditKeyUp(
          TcxCustomGridTableView *Sender, TcxCustomGridTableItem *AItem,
          TcxCustomEdit *AEdit, WORD &Key, TShiftState Shift);
		void __fastcall daDateGetDisplayText(
          TcxCustomGridTableItem *Sender, TcxCustomGridRecord *ARecord,
		  UnicodeString &AText);
        void __fastcall daTopDepthPropertiesValidate(TObject *Sender,
          Variant &DisplayValue, TCaption &ErrorText, bool &Error);
        void __fastcall daBottomDepthPropertiesValidate(TObject *Sender,
          Variant &DisplayValue, TCaption &ErrorText, bool &Error);
        void __fastcall daOffsetPropertiesValidate(TObject *Sender,
          Variant &DisplayValue, TCaption &ErrorText, bool &Error);
	void __fastcall cxButton1Click(TObject *Sender);
	void __fastcall cxButton3Click(TObject *Sender);
	void __fastcall cxButton4Click(TObject *Sender);
	void __fastcall cxButton5Click(TObject *Sender);
	void __fastcall cxButton6Click(TObject *Sender);
private:	// User declarations
        //void __fastcall MyIdleHandler(TObject *Sender, bool &Done);
        MYFONT LabelFont;
        MYFONT DateFont;
        int curpos;
        TDateList* DateList;
        TDateDataSource* DateDataSource;
        void __fastcall GenerateDateColumns();
        void __fastcall LoadDateData();
public:		// User declarations
        __fastcall TDatesForm(TComponent* Owner);
        TTGDiagram* Diag;
};
//---------------------------------------------------------------------------
extern PACKAGE TDatesForm *DatesForm;
//---------------------------------------------------------------------------
#endif
