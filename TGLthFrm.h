//---------------------------------------------------------------------------

#ifndef TGLthFrmH
#define TGLthFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <ComCtrls.hpp>
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
#include "cxCheckBox.hpp"
#include "cxDataStorage.hpp"
#include "cxTextEdit.hpp"
#include "cxButtonEdit.hpp"
#include "cxColorComboBox.hpp"
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
#include <ImgList.hpp>
#include "dxSkinOffice2016Colorful.hpp"
#include "dxSkinOffice2016Dark.hpp"
#include "dxSkinVisualStudio2013Blue.hpp"
#include "dxSkinVisualStudio2013Dark.hpp"
#include "dxSkinVisualStudio2013Light.hpp"

#ifndef TGDiagrmH
#include "TGDiagrm.h"
#endif
#ifndef TGUtilsH
#include "TGUtils.h"
#endif

//---------------------------------------------------------------------------
typedef void __fastcall (__closure *TcxNotifyEvent)(void * Ptr, TListNotification Action);

//---------------------------------------------------------------------------

class LITH2
{
public:
  UnicodeString LithCode;
  short Humo;
  double XShift;
  double YShift;
  TColor Color;
  TTabSheet *TabSheet;
  TSpeedButton *SpeedButton;
  TSpeedButton *H1SpeedButton;
  TSpeedButton *H2SpeedButton;
  TSpeedButton *H3SpeedButton;
  TSpeedButton *H4SpeedButton;
public:
  LITH2() { LithCode=0; Humo=0; XShift=0; YShift=0; Color=clBlack;
            TabSheet=NULL; SpeedButton=NULL; }
  LITH2(LITHCOMPONENT *, TStringList*);
};
//---------------------------------------------------------------------------

class LITH1
{
public:
  double Top;
  double Bot;
  bool DepthsSet;
  bool TopSet;
  bool BotSet;
  bool LoBound;
  TColor LoBoundColor;
  TList *Components;
public:
  LITH1(TColor);
  LITH1(LITHUNIT*);
  LITH1(LITH1*);
  ~LITH1();
};
//---------------------------------------------------------------------------

class TLithList : public TList
{
private:
	::TcxNotifyEvent FOnNotify;
	void ReleaseAllLiths();
	void ReleaseLith(int AIndex);
	LITH1* GetLith(int AIndex);
protected:
	void __fastcall Notify(void * Ptr, TListNotification Action);
	__property Items;
public:
	TLithList() {}
	__fastcall ~TLithList() {}
	void __fastcall Clear(void);
	void Add(LITH1* Lith1);
	void Delete(int AIndex);
	void Insert(int AIndex, LITH1* Lith1);
	__property LITH1* Liths[int Index] = {read = GetLith};
	__property ::TcxNotifyEvent OnNotify = {read=FOnNotify, write=FOnNotify};
};
//---------------------------------------------------------------------------

class TLithDataSource : public TcxCustomDataSource
{
private:
    TLithList* FLiths;
    TColor DefaultColor;
protected:
    void * __fastcall InsertRecord(void * ARecordHandle);
    void * __fastcall AppendRecord(void);
    void __fastcall DeleteRecord(void * ARecordHandle);
    int __fastcall GetRecordCount(void);
    Variant __fastcall GetValue(void * ARecordHandle, void * AItemHandle);
    void __fastcall Notify(void * Ptr, TListNotification Action);
    void __fastcall SetValue(void * ARecordHandle, void * AItemHandle, const Variant &AValue);
public:
    __fastcall TLithDataSource(TLithList* ALithList, TColor dcolor);
    __fastcall ~TLithDataSource() { }
    __property TLithList* LithList = {read = FLiths};
    LITH1* TempLith1;
};
//---------------------------------------------------------------------------

class TLithComponentSource : public TcxCustomDataSource
{
private:
    TLithDataSource* FDataSource; // master
protected:
    //void * __fastcall InsertRecord(void * ARecordHandle);
    void * __fastcall AppendRecord(void);
    int __fastcall GetRecordCount(void);
    Variant __fastcall GetValue(void * ARecordHandle, void * AItemHandle);
    void __fastcall Notify(void * Ptr, TListNotification Action);
    void __fastcall SetValue(void * ARecordHandle, void * AItemHandle, const Variant &AValue);
public:
    TLithComponentSource(TLithDataSource* ADataSource) { FDataSource = ADataSource;};
    //..void * __fastcall InsertRecord(void * ARecordHandle);
    void __fastcall DeleteRecord(void * ARecordHandle);
    int GetMasterRecordIndex();
    __property TLithDataSource* MasterDataSource = {read = FDataSource};
};
//---------------------------------------------------------------------------

const int IndexOfTopDepth = 0;
const int IndexOfBottomDepth = 1;
const int IndexOfLoBound = 2;

const int IndexOfLithCode = 0;
const int IndexOfHumo = 1;
const int IndexOfXShift = 2;
const int IndexOfYShift = 3;
//---------------------------------------------------------------------------

class TLithKeyList : public TList
{
private:
	::TcxNotifyEvent FOnNotify;
    void ReleaseAllLithKeys();
    void ReleaseLithKey(int AIndex);
    LITHKEY* GetLithKey(int AIndex);
protected:
    void __fastcall Notify(void * Ptr, TListNotification Action);
    __property Items;
public:
    TLithKeyList() {}
    __fastcall ~TLithKeyList() {}
    void __fastcall Clear(void);
    void Add(LITHKEY* LithKey);
    void Delete(int AIndex);
    void Insert(int AIndex, LITHKEY* LithKey);
    __property LITHKEY* LithKeys[int Index] = {read = GetLithKey};
    __property ::TcxNotifyEvent OnNotify = {read=FOnNotify, write=FOnNotify};
};
//---------------------------------------------------------------------------

class TLithKeyDataSource : public TcxCustomDataSource
{
private:
    TLithKeyList* FLithKeys;
    TStringList* TroelsSmithCodes;
protected:
    void * __fastcall InsertRecord(void * ARecordHandle);
    void * __fastcall AppendRecord(void);
    void __fastcall DeleteRecord(void * ARecordHandle);
    int __fastcall GetRecordCount(void);
    Variant __fastcall GetValue(void * ARecordHandle, void * AItemHandle);
    void __fastcall Notify(void * Ptr, TListNotification Action);
    void __fastcall SetValue(void * ARecordHandle, void * AItemHandle, const Variant &AValue);
public:
    __fastcall TLithKeyDataSource(TLithKeyList* ALithKeyList, TStringList* TSCodes);
    __fastcall ~TLithKeyDataSource() { }
};
//---------------------------------------------------------------------------

const int IndexOfUnit = 0;
const int IndexOfX = 1;
const int IndexOfY = 2;
const int IndexOfLithLabel = 3;
const int IndexOfColor =4;
const int IndexOfPlot = 5;

//---------------------------------------------------------------------------
                       
class TLithForm : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TImage *Image1;
	TPageControl *PageControl1;
	TTabSheet *BitmapTabSheet;
	TTabSheet *ShTabSheet;
	TTabSheet *TbTabSheet;
	TSpeedButton *SpeedButton34;
	TSpeedButton *SpeedButton35;
	TSpeedButton *SpeedButton36;
	TSpeedButton *SpeedButton37;
	TPageControl *PageControl2;
	TTabSheet *DesignTabSheet;
	TTabSheet *OptionsTabSheet;
	TBitBtn *BitBtn1;
	TBitBtn *BitBtn2;
	TBitBtn *BitBtn3;
	TBitBtn *BitBtn4;
	TBitBtn *BitBtn5;
	TcxGridLevel *LithGridLevel1;
	TcxGrid *LithGrid;
	TcxGridLevel *LithGridLevel2;
	TcxGridTableView *LithGridTableView1;
	TcxGridColumn *lgTopDepth;
	TcxGridColumn *lgBottomDepth;
	TcxGridColumn *lgLoBound;
	TcxGridTableView *LithGridTableView2;
	TcxGridColumn *lgLithCode;
	TcxGridColumn *lgHumo;
	TcxGridColumn *lgXShift;
	TcxGridColumn *lgYShift;
	TSpeedButton *SpeedButton1;
	TSpeedButton *SpeedButton2;
	TSpeedButton *SpeedButton3;
	TSpeedButton *SpeedButton4;
	TSpeedButton *SpeedButton5;
	TSpeedButton *SpeedButton6;
	TSpeedButton *SpeedButton7;
	TSpeedButton *SpeedButton8;
	TSpeedButton *SpeedButton9;
	TSpeedButton *SpeedButton10;
	TSpeedButton *SpeedButton11;
	TSpeedButton *SpeedButton12;
	TSpeedButton *SpeedButton13;
	TSpeedButton *SpeedButton14;
	TSpeedButton *SpeedButton15;
	TSpeedButton *SpeedButton16;
	TSpeedButton *SpeedButton17;
	TSpeedButton *SpeedButton18;
	TSpeedButton *SpeedButton19;
	TSpeedButton *SpeedButton20;
	TSpeedButton *SpeedButton21;
	TSpeedButton *SpeedButton22;
	TSpeedButton *SpeedButton23;
	TSpeedButton *SpeedButton24;
	TSpeedButton *SpeedButton25;
	TSpeedButton *SpeedButton26;
	TSpeedButton *SpeedButton27;
	TSpeedButton *SpeedButton28;
	TSpeedButton *SpeedButton29;
	TSpeedButton *SpeedButton30;
	TSpeedButton *SpeedButton31;
	TSpeedButton *SpeedButton32;
	TSpeedButton *SpeedButton33;
	TSpeedButton *SpeedButton38;
	TSpeedButton *SpeedButton39;
	TSpeedButton *SpeedButton40;
	TSpeedButton *SpeedButton41;
	TLabel *Label34;
	TLabel *Label35;
	TLabel *Label36;
	TLabel *Label37;
	TLabel *ShLabel;
	TLabel *TbLabel;
	TLabel *Label38;
	TLabel *Label39;
	TLabel *Label40;
	TLabel *Label41;
	TGroupBox *GroupBox1;
	TColorBox *ColorBox1;
	TLabel *Label3;
	TLabel *Label4;
	TColorBox *ColorBox2;
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TTabSheet *TbSTabSheet;
	TSpeedButton *SpeedButton42;
	TSpeedButton *SpeedButton43;
	TSpeedButton *SpeedButton44;
	TSpeedButton *SpeedButton45;
	TLabel *Label42;
	TLabel *Label43;
	TLabel *Label44;
	TLabel *Label45;
	TLabel *Label5;
	TTabSheet *TbScTabSheet;
	TSpeedButton *SpeedButton46;
	TSpeedButton *SpeedButton47;
	TSpeedButton *SpeedButton48;
	TSpeedButton *SpeedButton49;
	TLabel *Label46;
	TLabel *Label47;
	TLabel *Label48;
	TLabel *Label49;
	TLabel *Label6;
	TTabSheet *TlTabSheet;
	TSpeedButton *SpeedButton50;
	TSpeedButton *SpeedButton51;
	TSpeedButton *SpeedButton52;
	TSpeedButton *SpeedButton53;
	TLabel *Label50;
	TLabel *Label51;
	TLabel *Label52;
	TLabel *Label53;
	TLabel *Label7;
	TTabSheet *ThTabSheet;
	TSpeedButton *SpeedButton54;
	TSpeedButton *SpeedButton55;
	TSpeedButton *SpeedButton56;
	TSpeedButton *SpeedButton57;
	TLabel *Th1;
	TLabel *Th2;
	TLabel *Th3;
	TLabel *Th4;
	TLabel *Label8;
	TTabSheet *ThhTabSheet;
	TSpeedButton *SpeedButton58;
	TSpeedButton *SpeedButton59;
	TSpeedButton *SpeedButton60;
	TSpeedButton *SpeedButton61;
	TLabel *Label58;
	TLabel *Label59;
	TLabel *Label60;
	TLabel *Label61;
	TLabel *Label9;
	TSpeedButton *TbH4SpeedButton;
	TSpeedButton *TbH1SpeedButton;
	TSpeedButton *TbH2SpeedButton;
	TSpeedButton *TbH3SpeedButton;
	TSpeedButton *TbSH4SpeedButton;
	TSpeedButton *TbSH1SpeedButton;
	TSpeedButton *TbSH2SpeedButton;
	TSpeedButton *TbSH3SpeedButton;
	TTabSheet *DlTabSheet;
	TSpeedButton *SpeedButton62;
	TSpeedButton *SpeedButton63;
	TSpeedButton *SpeedButton64;
	TSpeedButton *SpeedButton65;
	TLabel *Label62;
	TLabel *Label63;
	TLabel *Label64;
	TLabel *Label65;
	TLabel *Label10;
	TSpeedButton *TbScH1SpeedButton;
	TSpeedButton *TbScH2SpeedButton;
	TSpeedButton *TbScH3SpeedButton;
	TSpeedButton *TbScH4SpeedButton;
	TSpeedButton *TlH4SpeedButton;
	TSpeedButton *TlH3SpeedButton;
	TSpeedButton *TlH2SpeedButton;
	TSpeedButton *TlH1SpeedButton;
	TSpeedButton *ThH1SpeedButton;
	TSpeedButton *ThH2SpeedButton;
	TSpeedButton *ThH3SpeedButton;
	TTabSheet *DhTabSheet;
	TSpeedButton *SpeedButton66;
	TSpeedButton *SpeedButton67;
	TSpeedButton *SpeedButton68;
	TSpeedButton *SpeedButton69;
	TLabel *Label66;
	TLabel *Label67;
	TLabel *Label68;
	TLabel *Label69;
	TLabel *Label11;
	TTabSheet *DgTabSheet;
	TSpeedButton *SpeedButton70;
	TSpeedButton *SpeedButton71;
	TSpeedButton *SpeedButton72;
	TSpeedButton *SpeedButton73;
	TLabel *Label70;
	TLabel *Label71;
	TLabel *Label72;
	TLabel *Label73;
	TLabel *Label12;
	TTabSheet *LdTabSheet;
	TSpeedButton *SpeedButton74;
	TSpeedButton *SpeedButton75;
	TSpeedButton *SpeedButton76;
	TSpeedButton *SpeedButton77;
	TLabel *Label74;
	TLabel *Label75;
	TLabel *Label76;
	TLabel *Label77;
	TLabel *Label13;
	TSpeedButton *LdH4SpeedButton;
	TSpeedButton *LdH3SpeedButton;
	TSpeedButton *LdH2SpeedButton;
	TSpeedButton *LdH1SpeedButton;
	TTabSheet *LsoTabSheet;
	TTabSheet *LcTabSheet;
	TTabSheet *LfTabSheet;
	TTabSheet *AsTabSheet;
	TTabSheet *AgTabSheet;
	TTabSheet *GaTabSheet;
	TTabSheet *GsTabSheet;
	TTabSheet *GgminTabSheet;
	TTabSheet *GgmajTabSheet;
	TTabSheet *TestTabSheet;
	TTabSheet *PartTestTabSheet;
	TTabSheet *CortSecTabSheet;
	TTabSheet *CortTabSheet;
	TSpeedButton *SpeedButton78;
	TSpeedButton *SpeedButton79;
	TSpeedButton *SpeedButton80;
	TSpeedButton *SpeedButton81;
	TLabel *Label78;
	TLabel *Label79;
	TLabel *Label80;
	TLabel *Label81;
	TLabel *Label14;
	TSpeedButton *SpeedButton82;
	TSpeedButton *SpeedButton83;
	TSpeedButton *SpeedButton84;
	TSpeedButton *SpeedButton85;
	TLabel *Label82;
	TLabel *Label83;
	TLabel *Label84;
	TLabel *Label85;
	TLabel *Label15;
	TSpeedButton *SpeedButton86;
	TSpeedButton *SpeedButton87;
	TSpeedButton *SpeedButton88;
	TSpeedButton *SpeedButton89;
	TLabel *Label86;
	TLabel *Label87;
	TLabel *Label88;
	TLabel *Label89;
	TLabel *Label16;
	TSpeedButton *SpeedButton90;
	TSpeedButton *SpeedButton91;
	TSpeedButton *SpeedButton92;
	TSpeedButton *SpeedButton93;
	TLabel *Label90;
	TLabel *Label91;
	TLabel *Label92;
	TLabel *Label93;
	TLabel *Label17;
	TSpeedButton *SpeedButton94;
	TSpeedButton *SpeedButton95;
	TSpeedButton *SpeedButton96;
	TSpeedButton *SpeedButton97;
	TLabel *Label94;
	TLabel *Label95;
	TLabel *Label96;
	TLabel *Label97;
	TLabel *Label18;
	TSpeedButton *SpeedButton98;
	TSpeedButton *SpeedButton99;
	TSpeedButton *SpeedButton100;
	TSpeedButton *SpeedButton101;
	TLabel *Label98;
	TLabel *Label99;
	TLabel *Label100;
	TLabel *Label101;
	TLabel *Label19;
	TSpeedButton *SpeedButton102;
	TSpeedButton *SpeedButton103;
	TSpeedButton *SpeedButton104;
	TSpeedButton *SpeedButton105;
	TLabel *Label102;
	TLabel *Label103;
	TLabel *Label104;
	TLabel *Label105;
	TLabel *Label20;
	TSpeedButton *SpeedButton106;
	TSpeedButton *SpeedButton107;
	TSpeedButton *SpeedButton108;
	TSpeedButton *SpeedButton109;
	TLabel *Label106;
	TLabel *Label107;
	TLabel *Label108;
	TLabel *Label109;
	TLabel *Label21;
	TSpeedButton *SpeedButton110;
	TSpeedButton *SpeedButton111;
	TSpeedButton *SpeedButton112;
	TSpeedButton *SpeedButton113;
	TLabel *Label110;
	TLabel *Label111;
	TLabel *Label112;
	TLabel *Label113;
	TLabel *Label22;
	TSpeedButton *SpeedButton114;
	TSpeedButton *SpeedButton115;
	TSpeedButton *SpeedButton116;
	TSpeedButton *SpeedButton117;
	TLabel *Label114;
	TLabel *Label115;
	TLabel *Label116;
	TLabel *Label117;
	TLabel *Label23;
	TSpeedButton *SpeedButton118;
	TSpeedButton *SpeedButton119;
	TSpeedButton *SpeedButton120;
	TSpeedButton *SpeedButton121;
	TLabel *Label118;
	TLabel *Label119;
	TLabel *Label120;
	TLabel *Label121;
	TLabel *Label24;
	TSpeedButton *SpeedButton122;
	TSpeedButton *SpeedButton123;
	TSpeedButton *SpeedButton124;
	TSpeedButton *SpeedButton125;
	TLabel *Label122;
	TLabel *Label123;
	TLabel *Label124;
	TLabel *Label125;
	TLabel *Label25;
	TSpeedButton *SpeedButton126;
	TSpeedButton *SpeedButton127;
	TSpeedButton *SpeedButton128;
	TSpeedButton *SpeedButton129;
	TLabel *Label126;
	TLabel *Label127;
	TLabel *Label128;
	TLabel *Label129;
	TLabel *Label26;
	TcxGrid *LithKeyGrid1;
	TcxGridLevel *LithKeyGrid1Level1;
	TcxGridTableView *LithKeyGridTableView;
	TcxGridColumn *lkUnit;
	TcxGridColumn *lkX;
	TcxGridColumn *lkY;
	TcxGridColumn *lkLithLabel;
	TcxGridColumn *lkPlot;
	TcxGridColumn *lkColor;
	TBitBtn *BitBtn8;
	TPanel *Panel3;
	TCheckBox *CheckBox1;
	TCheckBox *CheckBox2;
	TGroupBox *GroupBox2;
	TLabeledEdit *LabeledEdit1;
	TLabeledEdit *LabeledEdit2;
	TGroupBox *GroupBox3;
	TLabeledEdit *LabeledEdit3;
	TBitBtn *BitBtn9;
	TLabeledEdit *LabeledEdit4;
	TGroupBox *GroupBox4;
	TLabeledEdit *LabeledEdit5;
	TBitBtn *BitBtn10;
	TGroupBox *GroupBox5;
	TComboBox *LineWidthComboBox1;
	TLabel *Label27;
	TLabel *Label28;
	TComboBox *LineWidthComboBox3;
	TLabel *Label29;
	TColorBox *ColorBox3;
	TLabel *Label30;
	TComboBox *LineWidthComboBox4;
	TLabel *Label31;
	TComboBox *LineWidthComboBox2;
	TButton *Button4;
	TButton *Button5;
	TcxImageList *cxImageList1;
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall SpeedButton34Click(TObject *Sender);
	void __fastcall FormDeactivate(TObject *Sender);
	void __fastcall SpeedButton1Click(TObject *Sender);
	void __fastcall LithGridTableView1FocusedRecordChanged(
		  TcxCustomGridTableView *Sender,
		  TcxCustomGridRecord *APrevFocusedRecord,
		  TcxCustomGridRecord *AFocusedRecord,
		  bool ANewItemRecordFocusingChanged);
	void __fastcall SpeedButton2Click(TObject *Sender);
	void __fastcall SpeedButton3Click(TObject *Sender);
	void __fastcall SpeedButton4Click(TObject *Sender);
	void __fastcall SpeedButton5Click(TObject *Sender);
	void __fastcall SpeedButton6Click(TObject *Sender);
	void __fastcall SpeedButton7Click(TObject *Sender);
	void __fastcall SpeedButton8Click(TObject *Sender);
	void __fastcall SpeedButton9Click(TObject *Sender);
	void __fastcall SpeedButton10Click(TObject *Sender);
	void __fastcall SpeedButton11Click(TObject *Sender);
	void __fastcall SpeedButton12Click(TObject *Sender);
	void __fastcall SpeedButton13Click(TObject *Sender);
	void __fastcall SpeedButton14Click(TObject *Sender);
	void __fastcall SpeedButton15Click(TObject *Sender);
	void __fastcall SpeedButton16Click(TObject *Sender);
	void __fastcall SpeedButton17Click(TObject *Sender);
	void __fastcall SpeedButton18Click(TObject *Sender);
	void __fastcall SpeedButton19Click(TObject *Sender);
	void __fastcall SpeedButton20Click(TObject *Sender);
	void __fastcall SpeedButton21Click(TObject *Sender);
	void __fastcall SpeedButton22Click(TObject *Sender);
	void __fastcall SpeedButton23Click(TObject *Sender);
	void __fastcall SpeedButton24Click(TObject *Sender);
	void __fastcall SpeedButton25Click(TObject *Sender);
	void __fastcall SpeedButton26Click(TObject *Sender);
	void __fastcall SpeedButton27Click(TObject *Sender);
	void __fastcall SpeedButton28Click(TObject *Sender);
	void __fastcall SpeedButton29Click(TObject *Sender);
	void __fastcall SpeedButton30Click(TObject *Sender);
	void __fastcall SpeedButton31Click(TObject *Sender);
	void __fastcall SpeedButton32Click(TObject *Sender);
	void __fastcall SpeedButton33Click(TObject *Sender);
	void __fastcall SpeedButton35Click(TObject *Sender);
	void __fastcall SpeedButton36Click(TObject *Sender);
	void __fastcall SpeedButton37Click(TObject *Sender);
	void __fastcall SpeedButton38Click(TObject *Sender);
	void __fastcall SpeedButton39Click(TObject *Sender);
	void __fastcall SpeedButton40Click(TObject *Sender);
	void __fastcall SpeedButton41Click(TObject *Sender);
	void __fastcall BitBtn4Click(TObject *Sender);
	void __fastcall LithGridTableView2KeyDown(TObject *Sender,
          WORD &Key, TShiftState Shift);
	void __fastcall PageControl1Change(TObject *Sender);
	void __fastcall BitBtn3Click(TObject *Sender);
	void __fastcall BitBtn2Click(TObject *Sender);
	void __fastcall BitBtn1Click(TObject *Sender);
	void __fastcall BitBtn5Click(TObject *Sender);
	void __fastcall ColorBox1Change(TObject *Sender);
	void __fastcall lgLoBoundPropertiesEditValueChanged(TObject *Sender);
	void __fastcall ColorBox2Change(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall SpeedButton42Click(TObject *Sender);
	void __fastcall SpeedButton43Click(TObject *Sender);
	void __fastcall SpeedButton44Click(TObject *Sender);
	void __fastcall SpeedButton45Click(TObject *Sender);
	void __fastcall SpeedButton46Click(TObject *Sender);
	void __fastcall SpeedButton47Click(TObject *Sender);
	void __fastcall SpeedButton48Click(TObject *Sender);
	void __fastcall SpeedButton49Click(TObject *Sender);
	void __fastcall SpeedButton50Click(TObject *Sender);
	void __fastcall SpeedButton51Click(TObject *Sender);
	void __fastcall SpeedButton52Click(TObject *Sender);
	void __fastcall SpeedButton53Click(TObject *Sender);
	void __fastcall SpeedButton54Click(TObject *Sender);
	void __fastcall SpeedButton55Click(TObject *Sender);
	void __fastcall SpeedButton56Click(TObject *Sender);
	void __fastcall SpeedButton57Click(TObject *Sender);
	void __fastcall SpeedButton58Click(TObject *Sender);
	void __fastcall SpeedButton59Click(TObject *Sender);
	void __fastcall SpeedButton60Click(TObject *Sender);
	void __fastcall SpeedButton61Click(TObject *Sender);
	void __fastcall TbH1SpeedButtonClick(TObject *Sender);
	void __fastcall TbH2SpeedButtonClick(TObject *Sender);
	void __fastcall TbH3SpeedButtonClick(TObject *Sender);
	void __fastcall TbH4SpeedButtonClick(TObject *Sender);
	void __fastcall SpeedButton62Click(TObject *Sender);
	void __fastcall SpeedButton63Click(TObject *Sender);
	void __fastcall SpeedButton64Click(TObject *Sender);
	void __fastcall SpeedButton65Click(TObject *Sender);
	void __fastcall TbSH1SpeedButtonClick(TObject *Sender);
	void __fastcall TbSH2SpeedButtonClick(TObject *Sender);
	void __fastcall TbSH3SpeedButtonClick(TObject *Sender);
	void __fastcall TbSH4SpeedButtonClick(TObject *Sender);
	void __fastcall TbScH1SpeedButtonClick(TObject *Sender);
	void __fastcall TbScH2SpeedButtonClick(TObject *Sender);
	void __fastcall TbScH3SpeedButtonClick(TObject *Sender);
	void __fastcall TbScH4SpeedButtonClick(TObject *Sender);
	void __fastcall TlH1SpeedButtonClick(TObject *Sender);
	void __fastcall TlH2SpeedButtonClick(TObject *Sender);
	void __fastcall TlH3SpeedButtonClick(TObject *Sender);
	void __fastcall TlH4SpeedButtonClick(TObject *Sender);
	void __fastcall ThH1SpeedButtonClick(TObject *Sender);
	void __fastcall ThH2SpeedButtonClick(TObject *Sender);
	void __fastcall ThH3SpeedButtonClick(TObject *Sender);
	void __fastcall SpeedButton66Click(TObject *Sender);
	void __fastcall SpeedButton67Click(TObject *Sender);
	void __fastcall SpeedButton68Click(TObject *Sender);
	void __fastcall SpeedButton69Click(TObject *Sender);
	void __fastcall SpeedButton70Click(TObject *Sender);
	void __fastcall SpeedButton71Click(TObject *Sender);
	void __fastcall SpeedButton72Click(TObject *Sender);
	void __fastcall SpeedButton73Click(TObject *Sender);
	void __fastcall SpeedButton74Click(TObject *Sender);
	void __fastcall SpeedButton75Click(TObject *Sender);
	void __fastcall SpeedButton76Click(TObject *Sender);
	void __fastcall SpeedButton77Click(TObject *Sender);
	void __fastcall LdH1SpeedButtonClick(TObject *Sender);
	void __fastcall LdH2SpeedButtonClick(TObject *Sender);
	void __fastcall LdH3SpeedButtonClick(TObject *Sender);
	void __fastcall LdH4SpeedButtonClick(TObject *Sender);
	void __fastcall SpeedButton78Click(TObject *Sender);
	void __fastcall SpeedButton79Click(TObject *Sender);
	void __fastcall SpeedButton80Click(TObject *Sender);
	void __fastcall SpeedButton81Click(TObject *Sender);
	void __fastcall SpeedButton82Click(TObject *Sender);
	void __fastcall SpeedButton83Click(TObject *Sender);
	void __fastcall SpeedButton84Click(TObject *Sender);
	void __fastcall SpeedButton85Click(TObject *Sender);
	void __fastcall SpeedButton86Click(TObject *Sender);
	void __fastcall SpeedButton87Click(TObject *Sender);
	void __fastcall SpeedButton88Click(TObject *Sender);
	void __fastcall SpeedButton89Click(TObject *Sender);
	void __fastcall SpeedButton90Click(TObject *Sender);
	void __fastcall SpeedButton91Click(TObject *Sender);
	void __fastcall SpeedButton92Click(TObject *Sender);
	void __fastcall SpeedButton93Click(TObject *Sender);
	void __fastcall SpeedButton94Click(TObject *Sender);
	void __fastcall SpeedButton95Click(TObject *Sender);
	void __fastcall SpeedButton96Click(TObject *Sender);
	void __fastcall SpeedButton97Click(TObject *Sender);
	void __fastcall SpeedButton98Click(TObject *Sender);
	void __fastcall SpeedButton99Click(TObject *Sender);
	void __fastcall SpeedButton100Click(TObject *Sender);
	void __fastcall SpeedButton101Click(TObject *Sender);
	void __fastcall SpeedButton102Click(TObject *Sender);
	void __fastcall SpeedButton103Click(TObject *Sender);
	void __fastcall SpeedButton104Click(TObject *Sender);
	void __fastcall SpeedButton105Click(TObject *Sender);
	void __fastcall SpeedButton106Click(TObject *Sender);
	void __fastcall SpeedButton107Click(TObject *Sender);
	void __fastcall SpeedButton108Click(TObject *Sender);
	void __fastcall SpeedButton109Click(TObject *Sender);
	void __fastcall SpeedButton110Click(TObject *Sender);
	void __fastcall SpeedButton111Click(TObject *Sender);
	void __fastcall SpeedButton112Click(TObject *Sender);
	void __fastcall SpeedButton113Click(TObject *Sender);
	void __fastcall SpeedButton114Click(TObject *Sender);
	void __fastcall SpeedButton115Click(TObject *Sender);
	void __fastcall SpeedButton116Click(TObject *Sender);
	void __fastcall SpeedButton117Click(TObject *Sender);
	void __fastcall SpeedButton118Click(TObject *Sender);
	void __fastcall SpeedButton119Click(TObject *Sender);
	void __fastcall SpeedButton120Click(TObject *Sender);
	void __fastcall SpeedButton121Click(TObject *Sender);
	void __fastcall SpeedButton122Click(TObject *Sender);
	void __fastcall SpeedButton123Click(TObject *Sender);
	void __fastcall SpeedButton124Click(TObject *Sender);
	void __fastcall SpeedButton125Click(TObject *Sender);
	void __fastcall SpeedButton126Click(TObject *Sender);
	void __fastcall SpeedButton127Click(TObject *Sender);
	void __fastcall SpeedButton128Click(TObject *Sender);
	void __fastcall SpeedButton129Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall BitBtn8Click(TObject *Sender);
	void __fastcall BitBtn9Click(TObject *Sender);
	void __fastcall BitBtn10Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall OptionsTabSheetEnter(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	bool __fastcall FormHelp(WORD Command, int Data, bool &CallHelp);
	void __fastcall LithGridTableView1DataControllerNewRecord(
          TcxCustomDataController *ADataController, int ARecordIndex);
	void __fastcall LithGridTableView1DataControllerAfterPost(
          TcxCustomDataController *ADataController);
	void __fastcall lgTopDepthPropertiesValidate(TObject *Sender,
          Variant &DisplayValue, TCaption &ErrorText, bool &Error);
	void __fastcall lgBottomDepthPropertiesValidate(TObject *Sender,
          Variant &DisplayValue, TCaption &ErrorText, bool &Error);
	void __fastcall lgLoBoundPropertiesValidate(TObject *Sender,
          Variant &DisplayValue, TCaption &ErrorText, bool &Error);
	void __fastcall lkXPropertiesValidate(TObject *Sender,
          Variant &DisplayValue, TCaption &ErrorText, bool &Error);
	void __fastcall lkYPropertiesValidate(TObject *Sender,
          Variant &DisplayValue, TCaption &ErrorText, bool &Error);
	void __fastcall lkXGetCellHint(TcxCustomGridTableItem *Sender,
          TcxCustomGridRecord *ARecord,
          TcxGridTableDataCellViewInfo *ACellViewInfo,
          const TPoint &AMousePos, TCaption &AHintText,
          bool &AIsHintMultiLine, TRect &AHintTextRect);
	void __fastcall lkYGetCellHint(TcxCustomGridTableItem *Sender,
          TcxCustomGridRecord *ARecord,
          TcxGridTableDataCellViewInfo *ACellViewInfo,
          const TPoint &AMousePos, TCaption &AHintText,
          bool &AIsHintMultiLine, TRect &AHintTextRect);
private:	// User declarations
	TTGDiagram* Diag;
	UnicodeString BitmapPath;
	Graphics::TBitmap *pBitmap;
	Graphics::TBitmap *LithBmp;
	vector<int> MaxXShift;
	vector<int> MaxYShift;
	TStringList* TroelsSmithCodes;
	vector<Graphics::TBitmap*> LTHBitmaps;
	vector<Graphics::TBitmap*> Image1Bitmaps;
	TLithList* LithList;
	TLithDataSource* LithDataSource;
	TLithComponentSource* LithComponentSource;
	TLithKeyList* LithKeyList;
	TLithKeyDataSource* LithKeyDataSource;
	MYFONT LithTitleFont;
	MYFONT KeyFont;
	LineWidthComboBox *PatLineWidthComboBox;
	LineWidthComboBox *ColLineWidthComboBox;
	LineWidthComboBox *BndLineWidthComboBox;
	LineWidthComboBox *KeyLineWidthComboBox;
	bool NewPost;
	bool InitialZero;
private:
	void __fastcall GenerateLithColumns();
	void __fastcall LoadLithData();
	bool SetTroelsSmithButtonBitmap(int, TSpeedButton*);
	void EnableButtons(void);
	void DisableButtons(void);
	void EnableShiftButtons(void);
	void DisableShiftButtons(void);
	void SetComponentColorBox(void);
	void DepressBitmapButton(LITH2*);
	void SetBitmap(int, TSpeedButton*);
	void DrawBitmap(int, TColor);
	void ClearBitmap(void);
	void SetTroelsSmith(int, UnicodeString, TSpeedButton*, TSpeedButton*);
	void SetHumoSpeedButton(short, UnicodeString, TSpeedButton*);
	bool ButtonsEnabled;
	void DepressTroelsSmithButtons(LITH1*, LITH1*);
	void RaiseTroelsSmithButtons(void);
	void RaiseBitmapButtons(void);
	void SetTroelsSmithTabSheet(LITH2*);
	void DrawTroelsSmith(LITH1*);
	LITH2* GetCurrentLith2(LITH1*);
	void DrawLowerBound(void);
	void RedrawExample(void);
	void __fastcall GenerateLithKeyColumns();
	void __fastcall LoadLithKeyData();
public:		// User declarations
	__fastcall TLithForm(TComponent* Owner);
	short InitialTabSheet;
};
//---------------------------------------------------------------------------
extern PACKAGE TLithForm *LithForm;
//---------------------------------------------------------------------------
#endif
