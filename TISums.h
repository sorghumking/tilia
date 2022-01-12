//---------------------------------------------------------------------------

#ifndef TISumsH
#define TISumsH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "cxCheckBox.hpp"
#include "cxCheckComboBox.hpp"
#include "cxClasses.hpp"
#include "cxControls.hpp"
#include "cxCustomData.hpp"
#include "cxData.hpp"
#include "cxDataStorage.hpp"
#include "cxDropDownEdit.hpp"
#include "cxEdit.hpp"
#include "cxFilter.hpp"
#include "cxGraphics.hpp"
#include "cxGrid.hpp"
#include "cxGridCustomTableView.hpp"
#include "cxGridCustomView.hpp"
#include "cxGridLevel.hpp"
#include "cxGridTableView.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include "cxStyles.hpp"
#include "cxTextEdit.hpp"
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
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
#include <algorithm>
#include "cxCheckBox.hpp"
#include "cxClasses.hpp"
#include "cxControls.hpp"
#include "cxCustomData.hpp"
#include "cxData.hpp"
#include "cxDataStorage.hpp"
#include "cxDropDownEdit.hpp"
#include "cxEdit.hpp"
#include "cxFilter.hpp"
#include "cxGraphics.hpp"
#include "cxGrid.hpp"
#include "cxGridCustomTableView.hpp"
#include "cxGridCustomView.hpp"
#include "cxGridLevel.hpp"
#include "cxGridTableView.hpp"
#include "cxStyles.hpp"
#include "cxTextEdit.hpp"
#include "cxCheckComboBox.hpp"
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"

#ifndef TGDiagrmH
#include "TGDiagrm.h"
#endif
#ifndef TISpreadH
#include "TISpread.h"
#endif
//---------------------------------------------------------------------------

typedef void __fastcall (__closure *TcxNotifyEvent)(void * Ptr, TListNotification Action);
//---------------------------------------------------------------------------

class TSumDataSource : public TcxCustomDataSource
{
private:
    TSumList* FSums;
protected:
    void * __fastcall InsertRecord(void * ARecordHandle);
    void * __fastcall AppendRecord(void);
    void __fastcall DeleteRecord(void * ARecordHandle);
    int __fastcall GetRecordCount(void);
    Variant __fastcall GetValue(void * ARecordHandle, void * AItemHandle);
    void __fastcall Notify(void * Ptr, TListNotification Action);
    void __fastcall SetValue(void * ARecordHandle, void * AItemHandle, const Variant &AValue);
public:
    __fastcall TSumDataSource(TSumList* ASumList);
    __fastcall ~TSumDataSource() { }
};
//---------------------------------------------------------------------------

const int IndexOfSumCode = 0;
const int IndexOfSumName = 1;
const int IndexOfBase = 2;
const int IndexOfPercent = 3;
const int IndexOfSkip = 4;
//---------------------------------------------------------------------------

class TSuperSumDataSource : public TcxCustomDataSource
{
private:
    TSuperSumList* FSuperSums;
protected:
    void * __fastcall InsertRecord(void * ARecordHandle);
    void * __fastcall AppendRecord(void);
    void __fastcall DeleteRecord(void * ARecordHandle);
    int __fastcall GetRecordCount(void);
    Variant __fastcall GetValue(void * ARecordHandle, void * AItemHandle);
    void __fastcall Notify(void * Ptr, TListNotification Action);
    void __fastcall SetValue(void * ARecordHandle, void * AItemHandle, const Variant &AValue);
public:
    __fastcall TSuperSumDataSource(TSuperSumList* ASuperSumList);
    __fastcall ~TSuperSumDataSource() { }
};
//---------------------------------------------------------------------------

const int IndexOfSuperSumCode = 0;
const int IndexOfSuperSumName = 1;
const int IndexOfIncludeSums = 2;
//---------------------------------------------------------------------------


class TSumsForm : public TForm
{
__published:	// IDE-managed Components
        TcxGridLevel *SumsGridLevel1;
        TcxGrid *SumsGrid;
        TcxGridTableView *SumsGridTableView;
        TcxGridColumn *suCode;
        TcxGridColumn *suName;
        TcxGridColumn *suBase;
        TcxGridColumn *suPercent;
        TcxGrid *SuperSumsGrid;
        TcxGridLevel *SuperSumsGridLevel1;
        TcxGridTableView *SuperSumsGridTableView;
        TcxGridColumn *ssCode;
        TcxGridColumn *ssName;
        TcxGridColumn *ssInclude;
        TButton *Button1;
        TButton *Button2;
        TButton *Button3;
        TButton *Button4;
        TPanel *Panel1;
        TImage *Image1;
        TLabel *Label1;
        TButton *Button5;
        TPanel *Panel2;
        TImage *Image2;
        TLabel *Label2;
        TPanel *Panel3;
        TImage *Image3;
        TLabel *Label3;
        TPanel *Panel4;
        TImage *Image4;
        TLabel *Label4;
        TPanel *Panel5;
        TImage *Image5;
        TLabel *Label5;
        TPanel *Panel6;
        TImage *Image6;
        TLabel *Label6;
        TPanel *Panel7;
        TImage *Image7;
        TLabel *Label7;
        TPanel *Panel8;
        TImage *Image8;
        TLabel *Label8;
        TPanel *Panel9;
        TImage *Image9;
        TLabel *Label9;
        TButton *Button6;
        TRadioGroup *RadioGroup1;
        TButton *Button7;
        TcxGridColumn *suSkip;
        TPanel *Panel10;
        TImage *Image10;
        TLabel *Label10;
        void __fastcall FormActivate(TObject *Sender);
        void __fastcall FormDeactivate(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall ssCodePropertiesEditValueChanged(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall Button5Click(TObject *Sender);
        void __fastcall Button6Click(TObject *Sender);
        void __fastcall SuperSumsGridTableViewNavigatorButtonsButtonClick(
          TObject *Sender, int AButtonIndex, bool &ADone);
        void __fastcall RadioGroup1Click(TObject *Sender);
        void __fastcall Button7Click(TObject *Sender);
private:	// User declarations
        TTilSpreadSheetForm* TilSpreadSheetForm;
        TSumDataSource* SumDataSource;
        TSuperSumDataSource* SuperSumDataSource;
        TSumList* SumList;
        TSuperSumList* SuperSumList;
        void __fastcall GenerateSumColumns();
        void __fastcall GenerateSuperSumColumns();
		void SetDefaultSuperSums(int, map<UnicodeString, SUMVARIABLE>&, vector<UnicodeString>&);
public:		// User declarations
        __fastcall TSumsForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TSumsForm *SumsForm;
//---------------------------------------------------------------------------
#endif
