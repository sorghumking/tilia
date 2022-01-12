//---------------------------------------------------------------------------

#ifndef TGYaxFrmH
#define TGYaxFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <OleCtrls.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
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
#include "cxCheckBox.hpp"
#include "cxDataStorage.hpp"
#include "cxTextEdit.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include "cxNavigator.hpp"
#include "cxPC.hpp"
#include "cxButtons.hpp"
#include <ImgList.hpp>
#include <Menus.hpp>
#include "cxPCdxBarPopupMenu.hpp"
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
#include "dxBarBuiltInMenu.hpp"
#include "dxSkinOffice2016Colorful.hpp"
#include "dxSkinOffice2016Dark.hpp"
#include "dxSkinVisualStudio2013Blue.hpp"
#include "dxSkinVisualStudio2013Dark.hpp"
#include "dxSkinVisualStudio2013Light.hpp"
//---------------------------------------------------------------------------
#ifndef TGDiagrm
#include "TGDiagrm.h"
#endif
#ifndef TGH
#include "tg.h"
#endif
#ifndef TGFormsH
#include "TGForms.h"
#endif
#ifndef TGUtilsH
#include "TGUtils.h"
#endif
#ifndef TGYaxisH
#include "TGYaxis.h"
#endif

//---------------------------------------------------------------------------
typedef void __fastcall (__closure *TcxNotifyEvent)(void * Ptr, TListNotification Action);

class TYaxesList : public TList
{
private:
	::TcxNotifyEvent FOnNotify;
    void ReleaseAllYaxes();
    void ReleaseYaxis(int AIndex);
    NEWYAXIS* GetYaxis(int AIndex);
protected:
    void __fastcall Notify(void * Ptr, TListNotification Action);
    __property Items;
public:
    TYaxesList() {}
    __fastcall ~TYaxesList() {}
    void __fastcall Clear(void);
    __property NEWYAXIS* Yaxes[int Index] = {read = GetYaxis};
	__property ::TcxNotifyEvent OnNotify = {read=FOnNotify, write=FOnNotify};
};

//---------------------------------------------------------------------------
class TYaxisDataSource : public TcxCustomDataSource
{
private:
    TYaxesList* FYaxes;
protected:
    int __fastcall GetRecordCount(void);
    Variant __fastcall GetValue(void * ARecordHandle, void * AItemHandle);
    void __fastcall Notify(void * Ptr, TListNotification Action);
    void __fastcall SetValue(void * ARecordHandle, void * AItemHandle, const Variant &AValue);
public:
    __fastcall TYaxisDataSource(TYaxesList* AYaxesList);
    __fastcall ~TYaxisDataSource() { }
};

//---------------------------------------------------------------------------
const int IndexOfyaCode = 0;
const int IndexOfyaName = 1;
const int IndexOfyaPlot = 2;

//---------------------------------------------------------------------------

class TYaxesForm : public TForm
{
__published:	// IDE-managed Components
        TButton *Button1;
        TButton *Button2;
        TButton *Button3;
        TGroupBox *GroupBox1;
        TGroupBox *GroupBox2;
        TGroupBox *GroupBox3;
        TCheckBox *CheckBox1;
        TEdit *Edit1;
        TGroupBox *GroupBox4;
        TCheckBox *CheckBox2;
        TEdit *Edit2;
        TGroupBox *GroupBox5;
        TGroupBox *GroupBox6;
        TCheckBox *CheckBox3;
        TCheckBox *CheckBox4;
        TEdit *Edit3;
        TEdit *Edit4;
        TGroupBox *GroupBox7;
        TCheckBox *CheckBox5;
        TGroupBox *GroupBox8;
        TGroupBox *GroupBox9;
        TRadioGroup *RadioGroup1;
        TGroupBox *GroupBox10;
        TPanel *Panel1;
        TRadioGroup *RadioGroup2;
        TColorDialog *ColorDialog1;
        TComboBox *LineWidthComboBox1;
        TLabel *Label16;
        TCheckBox *CheckBox6;
        TLabeledEdit *LabeledEdit1;
        TLabeledEdit *LabeledEdit2;
        TLabeledEdit *LabeledEdit3;
        TLabeledEdit *LabeledEdit4;
        TLabeledEdit *LabeledEdit5;
        TLabeledEdit *LabeledEdit6;
        TLabeledEdit *LabeledEdit7;
        TLabeledEdit *LabeledEdit8;
        TLabeledEdit *LabeledEdit10;
        TLabeledEdit *LabeledEdit11;
        TLabeledEdit *LabeledEdit12;
        TColorBox *ColorBox3;
        TLabel *Label1;
        TLabeledEdit *LabeledEdit13;
        TLabeledEdit *LabeledEdit14;
        TcxGridLevel *YaxisGridLevel1;
        TcxGrid *YaxisGrid;
        TcxGridTableView *YaxisGridTableView;
        TcxGridColumn *yaCode;
        TcxGridColumn *yaName;
        TcxGridColumn *yaPlot;
        TPanel *Panel2;
        TPanel *Panel3;
        TPanel *Panel4;
        TGroupBox *GroupBox11;
        TGroupBox *GroupBox12;
        TCheckBox *CheckBox7;
        TEdit *Edit5;
        TGroupBox *GroupBox13;
        TCheckBox *CheckBox8;
        TEdit *Edit6;
	TFlowPanel *FlowPanel1;
	TPanel *Panel5;
	TcxPageControl *cxPageControl1;
	TcxTabSheet *cxTabSheet1;
	TcxTabSheet *cxTabSheet2;
	TcxTabSheet *cxTabSheet3;
	TcxTabSheet *cxTabSheet4;
	TFlowPanel *FlowPanel2;
	TcxButton *cxButton1;
	TcxImageList *cxImageList1;
	TcxButton *cxButton2;
	TcxButton *cxButton3;
	TcxButton *cxButton4;
        void __fastcall FormActivate(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall CheckBox1Click(TObject *Sender);
        void __fastcall CheckBox2Click(TObject *Sender);
        void __fastcall CheckBox4Click(TObject *Sender);
        void __fastcall FormDeactivate(TObject *Sender);
        void __fastcall CheckBox3Click(TObject *Sender);
        void __fastcall CheckBox5Click(TObject *Sender);
        void __fastcall RadioGroup1Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall ColorBox3Change(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall YaxisGridTableViewFocusedRecordChanged(
          TcxCustomGridTableView *Sender,
          TcxCustomGridRecord *APrevFocusedRecord,
          TcxCustomGridRecord *AFocusedRecord,
          bool ANewItemRecordFocusingChanged);
        void __fastcall yaPlotPropertiesChange(TObject *Sender);
        bool __fastcall FormHelp(WORD Command, int Data, bool &CallHelp);
        void __fastcall FormDestroy(TObject *Sender);
        void __fastcall CheckBox7Click(TObject *Sender);
        void __fastcall CheckBox8Click(TObject *Sender);
	void __fastcall cxButton1Click(TObject *Sender);
	void __fastcall cxButton2Click(TObject *Sender);
	void __fastcall cxButton3Click(TObject *Sender);
	void __fastcall cxButton4Click(TObject *Sender);

private:	// User declarations
        bool Activated;
        LineWidthComboBox *AxisLineWidthComboBox;
        void ShowAxisOptions(NEWYAXIS*);
        void ShowAxisLimits(NEWYAXIS*);
        void SetAxisOptions(NEWYAXIS*);
        TYaxesList* YaxesList;
        TYaxisDataSource* YaxisDataSource;
        void __fastcall GenerateYaxesColumns();
        void __fastcall LoadYaxesData();
        NEWYAXIS* FocusedAxis();
public:		// User declarations
        __fastcall TYaxesForm(TComponent* Owner);
        TTGDiagram* Diag;
        int InitialAxisNo;
};
//---------------------------------------------------------------------------
extern PACKAGE TYaxesForm *YaxesForm;
//---------------------------------------------------------------------------
#endif
