//---------------------------------------------------------------------------

#ifndef TGTxtFrmH
#define TGTxtFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
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
#include "cxButtonEdit.hpp"
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
//---------------------------------------------------------------------------

typedef void __fastcall (__closure *TcxNotifyEvent)(void * Ptr, TListNotification Action);

class TTextLineList : public TList
{
private:
	::TcxNotifyEvent FOnNotify;
	void ReleaseAllTextLines();
	void ReleaseTextLine(int AIndex);
	TEXTLINE* GetTextLine(int AIndex);
protected:
	void __fastcall Notify(void * Ptr, TListNotification Action);
	__property Items;
public:
	TTextLineList() {}
	__fastcall ~TTextLineList() {}
	void __fastcall Clear(void);
	void Add(TEXTLINE* TextLine);
	void Delete(int AIndex);
	void Insert(int AIndex, TEXTLINE* TextLine);
	__property TEXTLINE* TextLines[int Index] = {read = GetTextLine};
	__property ::TcxNotifyEvent OnNotify = {read=FOnNotify, write=FOnNotify};
};

//---------------------------------------------------------------------------
class TTextLineDataSource : public TcxCustomDataSource
{
private:
    TTextLineList* FTextLines;
protected:
    void * __fastcall InsertRecord(void * ARecordHandle);
    void * __fastcall AppendRecord(void);
    void __fastcall DeleteRecord(void * ARecordHandle);
    int __fastcall GetRecordCount(void);
    Variant __fastcall GetValue(void * ARecordHandle, void * AItemHandle);
    void __fastcall Notify(void * Ptr, TListNotification Action);
    void __fastcall SetValue(void * ARecordHandle, void * AItemHandle, const Variant &AValue);
public:
    __fastcall TTextLineDataSource(TTextLineList* ATextLineList);
    __fastcall ~TTextLineDataSource() { }
    TEXTLINE* TempTextLine;
};

//---------------------------------------------------------------------------
const int IndexOftlText = 0;
const int IndexOftlXCoord = 2;
const int IndexOftlYCoord = 3;
const int IndexOftlAngle = 4;
const int IndexOftlFont = 1;

//---------------------------------------------------------------------------

class TTextForm : public TForm
{
__published:	// IDE-managed Components
        TPageControl *PageControl1;
        TTabSheet *TabSheet1;
        TBitBtn *HbtnBold;
        TBitBtn *HBtnItalic;
        TTabSheet *TabSheet2;
        TGroupBox *GroupBox1;
        TEdit *Edit1;
        TEdit *Edit2;
        TEdit *Edit3;
        TEdit *Edit4;
        TGroupBox *GroupBox2;
        TEdit *Edit5;
        TBitBtn *HBtnSuper;
        TBitBtn *HBtnSub;
        TBitBtn *HBtnGreek;
        TBitBtn *BitBtn4;
        TBitBtn *BitBtn5;
        TBitBtn *BitBtn6;
        TBitBtn *BitBtn7;
        TBitBtn *BitBtn8;
        TGroupBox *GroupBox3;
        TCheckBox *CheckBox1;
        TEdit *Edit7;
        TGroupBox *GroupBox4;
        TCheckBox *CheckBox2;
        TEdit *Edit8;
        TGroupBox *GroupBox5;
        TGroupBox *GroupBox6;
        TCheckBox *CheckBox3;
        TEdit *Edit9;
        TCheckBox *CheckBox4;
        TEdit *Edit10;
        TGroupBox *GroupBox7;
        TStaticText *StaticText1;
        TButton *Button11;
        TButton *Button12;
        TButton *Button13;
        TcxGridLevel *RandTextGridLevel1;
        TcxGrid *RandTextGrid;
        TcxGridTableView *RandTextGridTableView;
        TcxGridColumn *tlText;
        TcxGridColumn *tlXCoord;
        TcxGridColumn *tlYCoord;
        TcxGridColumn *tlAngle;
        TcxGridColumn *tlFont;
        TBitBtn *BitBtn3;
        TBitBtn *BitBtn9;
        TBitBtn *BitBtn10;
        TBitBtn *BitBtn11;
        TBitBtn *BitBtn12;
        void __fastcall HbtnBoldClick(TObject *Sender);
        void __fastcall FormActivate(TObject *Sender);
        void __fastcall CheckBox1Click(TObject *Sender);
        void __fastcall CheckBox2Click(TObject *Sender);
        void __fastcall CheckBox3Click(TObject *Sender);
        void __fastcall CheckBox4Click(TObject *Sender);
        void __fastcall Button11Click(TObject *Sender);
        void __fastcall Edit1Enter(TObject *Sender);
        void __fastcall Edit2Enter(TObject *Sender);
        void __fastcall Edit3Enter(TObject *Sender);
        void __fastcall Edit4Enter(TObject *Sender);
        void __fastcall Edit5Enter(TObject *Sender);
        void __fastcall Edit7Enter(TObject *Sender);
        void __fastcall Edit8Enter(TObject *Sender);
        void __fastcall Edit9Enter(TObject *Sender);
        void __fastcall Edit10Enter(TObject *Sender);
        void __fastcall HBtnItalicClick(TObject *Sender);
        void __fastcall HBtnSuperClick(TObject *Sender);
        void __fastcall HBtnSubClick(TObject *Sender);
        void __fastcall HBtnGreekClick(TObject *Sender);
        void __fastcall BitBtn4Click(TObject *Sender);
        void __fastcall BitBtn5Click(TObject *Sender);
        void __fastcall BitBtn6Click(TObject *Sender);
        void __fastcall BitBtn7Click(TObject *Sender);
        void __fastcall BitBtn8Click(TObject *Sender);
        void __fastcall TabSheet2Enter(TObject *Sender);
        void __fastcall FormDeactivate(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall Button13Click(TObject *Sender);
        void __fastcall tlFontPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
        void __fastcall RandTextGridTableViewFocusedItemChanged(
          TcxCustomGridTableView *Sender,
          TcxCustomGridTableItem *APrevFocusedItem,
          TcxCustomGridTableItem *AFocusedItem);
        void __fastcall BitBtn3Click(TObject *Sender);
        void __fastcall BitBtn9Click(TObject *Sender);
        void __fastcall BitBtn10Click(TObject *Sender);
        void __fastcall BitBtn11Click(TObject *Sender);
        void __fastcall BitBtn12Click(TObject *Sender);
        bool __fastcall FormHelp(WORD Command, int Data, bool &CallHelp);
        void __fastcall tlTextGetDisplayText(
          TcxCustomGridTableItem *Sender, TcxCustomGridRecord *ARecord,
          UnicodeString &AText);
        void __fastcall RandTextGridTableViewEditKeyUp(
          TcxCustomGridTableView *Sender, TcxCustomGridTableItem *AItem,
          TcxCustomEdit *AEdit, WORD &Key, TShiftState Shift);
        void __fastcall tlXCoordPropertiesValidate(TObject *Sender,
          Variant &DisplayValue, TCaption &ErrorText, bool &Error);
        void __fastcall tlYCoordPropertiesValidate(TObject *Sender,
          Variant &DisplayValue, TCaption &ErrorText, bool &Error);
        void __fastcall tlAnglePropertiesValidate(TObject *Sender,
          Variant &DisplayValue, TCaption &ErrorText, bool &Error);
private:	// User declarations
        MYFONT HFont[4];
        MYFONT FFont;
        bool HeadActive[4];
        bool FootActive;
        void DeactivateText();
        void ToggleStyle(int);
        void ToggleStyle2(int);
		void ToggleStyle2(UnicodeString);
        void InsertGreek(TEdit*);
        long EditRow;
        long EditCol;
        int curpos;
        int SelLen;
        TTextLineList* TextLineList;
        TTextLineDataSource* TextLineDataSource;
        void __fastcall GenerateTextLineColumns();
        void __fastcall LoadTextLineData();
public:		// User declarations
        __fastcall TTextForm(TComponent* Owner);
        TTGDiagram *Diag;
        int InitialItem;
};
//---------------------------------------------------------------------------
extern PACKAGE TTextForm *TextForm;
//---------------------------------------------------------------------------
#endif
