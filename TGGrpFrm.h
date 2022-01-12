//---------------------------------------------------------------------------

#ifndef TGGrpFrmH
#define TGGrpFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include "cxClasses.hpp"
#include "cxControls.hpp"
#include "cxCustomData.hpp"
#include "cxData.hpp"
#include "cxDBData.hpp"
#include "cxEdit.hpp"
#include "cxFilter.hpp"
#include "cxGraphics.hpp"
#include "cxGrid.hpp"
#include "cxGridCustomTableView.hpp"
#include "cxGridCustomView.hpp"
#include "cxGridDBTableView.hpp"
#include "cxGridLevel.hpp"
#include "cxGridTableView.hpp"
#include "cxStyles.hpp"
#include <DB.hpp>
#include "cxButtonEdit.hpp"
#include "cxDataStorage.hpp"
#include "cxDropDownEdit.hpp"
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

class TGroupList : public TList
{
private:
	::TcxNotifyEvent FOnNotify;
	void ReleaseAllGroups();
	void ReleaseGroup(int AIndex);
	GROUPS* GetGroup(int AIndex);
protected:
	void __fastcall Notify(void * Ptr, TListNotification Action);
	__property Items;
public:
	TGroupList() {}
	__fastcall ~TGroupList() {}
	void __fastcall Clear(void);
	void Add(GROUPS* Zone);
	void Delete(int AIndex);
	void Insert(int AIndex, GROUPS* Group);
	__property GROUPS* Groups[int Index] = {read = GetGroup};
	__property ::TcxNotifyEvent OnNotify = {read=FOnNotify, write=FOnNotify};
};

//---------------------------------------------------------------------------
class TGroupDataSource : public TcxCustomDataSource
{
private:
    TGroupList* FGroups;
    GROUPS DefaultGroup;  //?
    TList* grf;
	UnicodeString __fastcall GetVarCode(UnicodeString&);
	UnicodeString __fastcall GetVarName(UnicodeString&);
protected:
    void * __fastcall InsertRecord(void * ARecordHandle);
    void * __fastcall AppendRecord(void);
    void __fastcall DeleteRecord(void * ARecordHandle);
    int __fastcall GetRecordCount(void);
    Variant __fastcall GetValue(void * ARecordHandle, void * AItemHandle);
    void __fastcall Notify(void * Ptr, TListNotification Action);
    void __fastcall SetValue(void * ARecordHandle, void * AItemHandle, const Variant &AValue);
public:
    __fastcall TGroupDataSource(TGroupList* AGroupList, GROUPS& DFG, TList* g);
    __fastcall ~TGroupDataSource() { }
    GROUPS* TempGroup;
};

//---------------------------------------------------------------------------
const int IndexOfFirstGraph = 0;
const int IndexOfSecondGraph = 1;
const int IndexOfGroupName = 2;
const int IndexOfGroupOptions = 3;

//---------------------------------------------------------------------------
class TGroupForm : public TForm
{
__published:	// IDE-managed Components
        TButton *Button1;
        TButton *Button2;
        TButton *Button3;
        TcxGridLevel *GroupsGridLevel1;
        TcxGrid *GroupsGrid;
        TcxGridTableView *GroupsGridTableView;
        TcxGridColumn *grFirstGraph;
        TcxGridColumn *grSecondGraph;
        TcxGridColumn *grName;
        TcxGridColumn *grOptions;
        void __fastcall FormActivate(TObject *Sender);
        void __fastcall FormDeactivate(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall grOptionsPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
        bool __fastcall FormHelp(WORD Command, int Data, bool &CallHelp);
private:	// User declarations
        int FirstGraph;
        GROUPS DefaultGroup;
        TGroupList* GroupList;
        TGroupDataSource* GroupDataSource;
        void __fastcall GenerateGroupColumns();
        void __fastcall LoadGroupData();
public:		// User declarations
        __fastcall TGroupForm(TComponent* Owner);
        TTGDiagram* Diag;
        int InitialRow;
};
//---------------------------------------------------------------------------
extern PACKAGE TGroupForm *GroupForm;
//---------------------------------------------------------------------------
#endif
