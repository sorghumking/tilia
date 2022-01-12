//---------------------------------------------------------------------------

#ifndef TGZoneOpH
#define TGZoneOpH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
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
#include "cxContainer.hpp"
#include "cxTextEdit.hpp"
#include <ImgList.hpp>
#include "cxImage.hpp"
#include "cxButtonEdit.hpp"
#include "cxCheckBox.hpp"
#include "cxDataStorage.hpp"
#include "cxDropDownEdit.hpp"
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

#ifndef TGH
#include "tg.h"
#endif
//---------------------------------------------------------------------------

enum TABSHEET { LEVELS_TABSHEET, LABELS_TABSHEET };

typedef void __fastcall (__closure *TcxNotifyEvent)(void * Ptr, TListNotification Action);

class TZoneList : public TList
{
private:
	::TcxNotifyEvent FOnNotify;
	void ReleaseAllZones();
	void ReleaseZone(int AIndex);
	ZONE* GetZone(int AIndex);
protected:
	void __fastcall Notify(void * Ptr, TListNotification Action);
	__property Items;
public:
	TZoneList() {}
	__fastcall ~TZoneList() {}
	void __fastcall Clear(void);
	void Add(ZONE* Zone);
	void Delete(int AIndex);
	void Insert(int AIndex, ZONE* Zone);
	__property ZONE* Zones[int Index] = {read = GetZone};
	__property ::TcxNotifyEvent OnNotify = {read=FOnNotify, write=FOnNotify};
};
//---------------------------------------------------------------------------

class TZoneDataSource : public TcxCustomDataSource
{
private:
    TZoneList* FZones;
    ZONE DefaultZone;
    ZONE *NewZone;
protected:
    void * __fastcall InsertRecord(void * ARecordHandle);
    void * __fastcall AppendRecord(void);
    void __fastcall DeleteRecord(void * ARecordHandle);
    int __fastcall GetRecordCount(void);
    Variant __fastcall GetValue(void * ARecordHandle, void * AItemHandle);
    void __fastcall Notify(void * Ptr, TListNotification Action);
    void __fastcall SetValue(void * ARecordHandle, void * AItemHandle, const Variant &AValue);
public:
    __fastcall TZoneDataSource(TZoneList* AZoneList, ZONE& DFZ, ZONE* NFZ);
    __fastcall ~TZoneDataSource() { }
};
//---------------------------------------------------------------------------

const int IndexOfLevel = 0;
const int IndexOfStyle = 1;
const int IndexOfLevelOptions = 2;
const int IndexOfOrder = 3;
const int IndexOfLabCol = 4;
//---------------------------------------------------------------------------

class TZoneLabelList : public TList
{
private:
	::TcxNotifyEvent FOnNotify;
	void ReleaseAllZoneLabels();
	void ReleaseZoneLabel(int AIndex);
	ZONELABELS* GetZoneLabel(int AIndex);
protected:
	void __fastcall Notify(void * Ptr, TListNotification Action);
	__property Items;
public:
	TZoneLabelList() {}
	__fastcall ~TZoneLabelList() {}
	void __fastcall Clear(void);
	void Add(ZONELABELS* ZoneLabel);
	void Delete(int AIndex);
	void Insert(int AIndex, ZONELABELS* ZoneLabel);
	__property ZONELABELS* ZoneLabels[int Index] = {read = GetZoneLabel};
	__property ::TcxNotifyEvent OnNotify = {read=FOnNotify, write=FOnNotify};
};
//---------------------------------------------------------------------------

class TZoneLabelDataSource : public TcxCustomDataSource
{
private:
    TZoneLabelList* FZoneLabels;
protected:
    void * __fastcall InsertRecord(void * ARecordHandle);
    void * __fastcall AppendRecord(void);
    void __fastcall DeleteRecord(void * ARecordHandle);
    int __fastcall GetRecordCount(void);
    Variant __fastcall GetValue(void * ARecordHandle, void * AItemHandle);
    void __fastcall Notify(void * Ptr, TListNotification Action);
    void __fastcall SetValue(void * ARecordHandle, void * AItemHandle, const Variant &AValue);
public:
    __fastcall TZoneLabelDataSource(TZoneLabelList* AZoneLabelList);
    __fastcall ~TZoneLabelDataSource() { }
};
//---------------------------------------------------------------------------

const int IndexOfTop = 0;
const int IndexOfBottom = 1;
const int IndexOfLabel = 2;
//---------------------------------------------------------------------------

class TZoneForm : public TForm
{
__published:	// IDE-managed Components
        TPageControl *PageControl1;
        TTabSheet *Levels;
        TTabSheet *Labels;
        TTabSheet *Text;
        TButton *Button1;
        TButton *Button2;
        TButton *Button3;
        TGroupBox *GroupBox1;
        TGroupBox *GroupBox2;
        TCheckBox *CheckBox1;
        TColorDialog *ColorDialog1;
        TButton *Button8;
        TLabeledEdit *LabeledEdit1;
        TLabeledEdit *LabeledEdit2;
        TLabeledEdit *LabeledEdit3;
        TLabeledEdit *LabeledEdit4;
        TcxGridLevel *LabelsGridLevel1;
        TcxGrid *LabelsGrid;
        TcxGridTableView *LabelsGridTableView;
        TcxGridColumn *lbTopDepth;
        TcxGridColumn *lbBottomDepth;
        TcxGridColumn *lbLabel;
        TcxGridLevel *LevelsGridLevel1;
        TcxGrid *LevelsGrid;
        TcxGridTableView *LevelsGridTableView;
        TcxGridColumn *lvLevel;
        TcxGridColumn *lvStyle;
        TcxGridColumn *lvOptions;
        TcxGridColumn *lvOrder;
        TcxGridColumn *lvLabelColumn;
        TImageList *ImageList1;
        TBitBtn *BitBtn1;
        TBitBtn *BitBtn3;
        TBitBtn *BitBtn7;
        void __fastcall FormActivate(TObject *Sender);
        void __fastcall FormDeactivate(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall CheckBox1Click(TObject *Sender);
        void __fastcall Button8Click(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall LabeledEdit3Change(TObject *Sender);
        void __fastcall lvOptionsPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
        void __fastcall lvOptionsCustomDrawCell(
          TcxCustomGridTableView *Sender, TcxCanvas *ACanvas,
          TcxGridTableDataCellViewInfo *AViewInfo, bool &ADone);
        void __fastcall lvStylePropertiesChange(TObject *Sender);
        void __fastcall LevelsEnter(TObject *Sender);
        void __fastcall LabelsEnter(TObject *Sender);
        void __fastcall BitBtn1Click(TObject *Sender);
        void __fastcall BitBtn3Click(TObject *Sender);
        bool __fastcall FormHelp(WORD Command, int Data, bool &CallHelp);
        void __fastcall BitBtn7Click(TObject *Sender);
        void __fastcall lvLevelPropertiesValidate(TObject *Sender,
          Variant &DisplayValue, TCaption &ErrorText, bool &Error);
        void __fastcall lbTopDepthPropertiesValidate(TObject *Sender,
          Variant &DisplayValue, TCaption &ErrorText, bool &Error);
        void __fastcall lbBottomDepthPropertiesValidate(TObject *Sender,
          Variant &DisplayValue, TCaption &ErrorText, bool &Error);
        void __fastcall LevelsGridTableViewDataControllerNewRecord(
          TcxCustomDataController *ADataController, int ARecordIndex);
private:	// User declarations
        bool Change;
        bool InsertRow;
        ZONE DefaultZone;
        ZONE NewZone;
        MYFONT ZoneTitleFont;
        MYFONT ZoneFont;
        void SetLineZoneOptions(ZONE*, ZONE*);
        void SetScreenZoneOptions(ZONE*, ZONE*);
        void ApplyOptions(void);
        int GetZoneImageIndex(int);
        static int __fastcall ZoneSortCompare(void*, void*);
        //TZoneList* ZoneList;
        TZoneDataSource* ZoneDataSource;
        TZoneLabelList* ZoneLabelList;
        TZoneLabelDataSource* ZoneLabelDataSource;
        void __fastcall GenerateLevelColumns();
        void __fastcall GenerateLabelColumns();
        void __fastcall LoadLevelData();
        void __fastcall LoadLabelData();
        void __fastcall CustomizeGrid();
        void __fastcall SaveData();
public:		// User declarations
        __fastcall TZoneForm(TComponent* Owner);
        TTGDiagram* Diag;
        int OpeningTabSheet;
        TZoneList* ZoneList;
};
//---------------------------------------------------------------------------
extern PACKAGE TZoneForm *ZoneForm;
//---------------------------------------------------------------------------
#endif
