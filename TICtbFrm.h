//---------------------------------------------------------------------------
#ifndef TICtbFrmH
#define TICtbFrmH
#include <Buttons.hpp>
#include <Classes.hpp>
#include <Controls.hpp>
#include <ExtCtrls.hpp>
#include <StdCtrls.hpp>
#include "cxCalendar.hpp"
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
#include "cxGridCardView.hpp"
#include "cxGridCustomTableView.hpp"
#include "cxGridCustomView.hpp"
#include "cxGridLevel.hpp"
#include "cxGridTableView.hpp"
#include "cxMemo.hpp"
#include "cxContainer.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include "cxStyles.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include "cxGridCustomLayoutView.hpp"
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
//---------------------------------------------------------------------------

#include <vector>
#ifndef TIContacH
#include "TIContac.h"
#endif
#ifndef TICommonH
#include "TICommon.h"
#endif

//---------------------------------------------------------------------------

typedef void __fastcall (__closure *TcxNotifyEvent)(void * Ptr, TListNotification Action);

class TSubmissionList : public TList
{
private:
	::TcxNotifyEvent FOnNotify;
	void ReleaseAllSubmissions();
	void ReleaseSubmission(int AIndex);
	SUBMISSION* GetSubmission(int AIndex);
	static int __fastcall SubmissionCompare(void*, void*);
protected:
	void __fastcall Notify(void * Ptr, TListNotification Action);
	__property Items;
public:
	TSubmissionList() {}
	__fastcall ~TSubmissionList() {}
	void __fastcall Clear(void);
	void Add(SUBMISSION* Submission);
	void Delete(int AIndex);
	void Insert(int AIndex, SUBMISSION* Submission);
	__property SUBMISSION* Submission[int Index] = {read = GetSubmission};
	__property ::TcxNotifyEvent OnNotify = {read=FOnNotify, write=FOnNotify};
	void SortAscending(void);
};
//---------------------------------------------------------------------------

class TSubmissionDataSource : public TcxCustomDataSource
{
private:
    TSubmissionList* FSubmissions;
    UnicodeString InitialDataForm;
protected:
    void * __fastcall InsertRecord(void * ARecordHandle);
    void * __fastcall AppendRecord(void);
    void __fastcall DeleteRecord(void * ARecordHandle);
    int __fastcall GetRecordCount(void);
    Variant __fastcall GetValue(void * ARecordHandle, void * AItemHandle);
    void __fastcall Notify(void * Ptr, TListNotification Action);
    void __fastcall SetValue(void * ARecordHandle, void * AItemHandle, const Variant &AValue);
public:
    __fastcall TSubmissionDataSource(TSubmissionList* ASubmissionList);
    __fastcall ~TSubmissionDataSource() { }
    void SetInitialDataForm(UnicodeString& DataForm) { InitialDataForm = DataForm; }
};

//---------------------------------------------------------------------------
const int IndexOf_suSubmittedForm  = 0;
const int IndexOf_suSubmissionDate = 1;
const int IndexOf_suSubmissionType = 2;
const int IndexOf_suSubmitters     = 3;
const int IndexOf_suNotes          = 4;
//---------------------------------------------------------------------------

class TSubmissionForm : public TForm
{
__published:	// IDE-managed Components
        TButton *Button1;
        TButton *Button2;
        TSpeedButton *SpeedButton1;
        TSpeedButton *SpeedButton2;
        TPanel *Panel2;
        TcxGridLevel *SubmissionGridLevel1;
        TcxGrid *SubmissionGrid;
        TcxGridCardView *SubmissionGridCardView1;
        TcxGridCardViewRow *suSubmittedForm;
        TcxGridCardViewRow *suSubmissionDate;
        TcxGridCardViewRow *suSubmissionType;
        TcxGridCardViewRow *suSubmitters;
        TcxGridCardViewRow *suNotes;
        TcxStyleRepository *cxStyleRepository1;
        TcxStyle *cxStyle1;
        TcxStyle *cxStyle3;
        TcxStyle *cxStyle4;
        TcxStyle *cxStyle5;
        TcxStyle *cxStyle6;
        TcxStyle *cxStyle7;
        TcxStyle *cxStyle8;
        TcxStyle *cxStyle9;
        TcxStyle *cxStyle10;
        TcxStyle *cxStyle11;
        TcxStyle *cxStyle12;
        TcxStyle *cxStyle2;
        TcxStyle *cxStyle13;
        TcxStyle *cxStyle14;
        TcxStyle *cxStyle15;
        TcxStyle *cxStyle16;
        TcxStyle *cxStyle17;
        TcxStyle *cxStyle18;
        TcxStyle *cxStyle19;
        TcxStyle *cxStyle20;
        TcxStyle *cxStyle21;
        TcxStyle *cxStyle22;
        TcxStyle *cxStyle23;
        TcxStyle *cxStyle24;
        TcxStyle *cxStyle25;
        TcxStyle *cxStyle26;
        TcxStyle *cxStyle27;
        TcxStyle *cxStyle28;
        TcxStyle *cxStyle29;
        TcxStyle *cxStyle30;
        TcxStyle *cxStyle31;
        TcxStyle *cxStyle32;
        TcxStyle *cxStyle33;
        TcxStyle *cxStyle34;
        TcxStyle *cxStyle35;
        TcxStyle *cxStyle36;
        TcxStyle *cxStyle37;
        TcxGridTableViewStyleSheet *GridTableViewStyleSheetWindowsStandard;
        TcxGridTableViewStyleSheet *GridTableViewStyleSheetDevExpress;
        TcxGridTableViewStyleSheet *GridTableViewStyleSheetWheat;
        TPanel *Panel1;
        TButton *Button3;
        TLabel *Label1;
        TSpeedButton *SpeedButton3;
        void __fastcall FormActivate(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall SpeedButton2Click(TObject *Sender);
        void __fastcall SpeedButton1Click(TObject *Sender);
        void __fastcall FormDestroy(TObject *Sender);
        void __fastcall suSubmittersPropertiesEditValueToStates(
          TObject *Sender, const Variant &AValue,
          TcxCheckStates &ACheckStates);
        void __fastcall suSubmittersPropertiesStatesToEditValue(
          TObject *Sender, const TcxCheckStates ACheckStates,
          Variant &AValue);
        void __fastcall suSubmittersGetDisplayText(
          TcxCustomGridTableItem *Sender, TcxCustomGridRecord *ARecord,
          UnicodeString &AText);
        void __fastcall SubmissionGridCardView1FocusedRecordChanged(
          TcxCustomGridTableView *Sender,
          TcxCustomGridRecord *APrevFocusedRecord,
          TcxCustomGridRecord *AFocusedRecord,
          bool ANewItemRecordFocusingChanged);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall SubmissionGridCardView1FocusedItemChanged(
          TcxCustomGridTableView *Sender,
          TcxCustomGridTableItem *APrevFocusedItem,
          TcxCustomGridTableItem *AFocusedItem);
        void __fastcall SpeedButton3Click(TObject *Sender);
private:	// User declarations
        void __fastcall GenerateSubmissionColumns();
        bool Changed;
        bool InitialActivation;
        bool ParamsSet;
        bool CleanedUp;
        bool SpeedButton1Down;
        bool SpeedButton2Down;
        int default_submission_form;
        TList* Contacts;
        TContactList* ContactList;
        TList* Submissions;
        TList* loi_submissions;
        TSubmissionList* SubmissionList;
        TSubmissionDataSource* SubmissionDataSource;
        TStrings* Countries;
        vector<bool> SubmitterCheckStates;
        UnicodeString NewRecordSubmitterText;
        //int __fastcall ContactCompare(void*, void*);
public:		// User declarations
		__fastcall TSubmissionForm(TComponent* Owner);
		void SetParams(UnicodeString, TList*, TList*, TList*, TContactList*, TStrings*);
        UnicodeString InitialDataForm;
};
//---------------------------------------------------------------------------
extern PACKAGE TSubmissionForm *SubmissionForm;
//---------------------------------------------------------------------------
#endif
