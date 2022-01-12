//---------------------------------------------------------------------------

#ifndef TICounterH
#define TICounterH
#include <vcl.h>
#include "pch.h"
#include "AdvCGrid.hpp"
#include "AdvCombo.hpp"
#include "AdvEdit.hpp"
#include "AdvGrid.hpp"
#include "AdvMemo.hpp"
#include "AdvMemoStylerManager.hpp"
#include "Advmxml.hpp"
#include "AdvObj.hpp"
#include "AdvSplitter.hpp"
#include "AdvToolBar.hpp"
#include "AdvToolBarStylers.hpp"
#include "AdvUtil.hpp"
#include "BaseGrid.hpp"
#include "cxButtons.hpp"
#include "cxCalendar.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxDateUtils.hpp"
#include "cxDropDownEdit.hpp"
#include "cxEdit.hpp"
#include "cxGraphics.hpp"
#include "cxLabel.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include "dxCore.hpp"
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
#include "dxSkinOffice2016Colorful.hpp"
#include "dxSkinOffice2016Dark.hpp"
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
#include "dxSkinVisualStudio2013Blue.hpp"
#include "dxSkinVisualStudio2013Dark.hpp"
#include "dxSkinVisualStudio2013Light.hpp"
#include "dxSkinVS2010.hpp"
#include "dxSkinWhiteprint.hpp"
#include "dxSkinXmas2008Blue.hpp"
#include "ipwxmlp.h"
#include <Classes.hpp>
#include <ComCtrls.hpp>
#include <Controls.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <ImgList.hpp>
#include <Menus.hpp>
#include <StdCtrls.hpp>
#include "AdvPanel.hpp"
#include "AdvMenus.hpp"
#include "AdvPicture.hpp"
//---------------------------------------------------------------------------
#ifndef TISpreadH
#include "TISpread.h"
#endif
#include <vector>
#include <map>
#include <set>

//---------------------------------------------------------------------------
class TAXACOUNT
{
private:
   UnicodeString FCode;
   UnicodeString FName;
   double FCount;
   map<int,float> FPres;
public:
   TAXACOUNT() { };
   TAXACOUNT(UnicodeString code, UnicodeString name, double count)
	{ FCode = code; FName = name, FCount = count; }
   bool operator == (const TAXACOUNT& comp);
   bool operator < (const TAXACOUNT& comp);
   __property UnicodeString Code = {read = FCode, write = FCode};
   __property UnicodeString Name = {read = FName, write = FName};
   __property double Count = {read = FCount, write = FCount};
   __property map<int,float> Pres = {read = FPres, write = FPres};
};
//---------------------------------------------------------------------------

class TCounterForm : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TcxImageList *cxImageList1;
	TAdvColumnGrid *AdvColumnGrid1;
	TPanel *Panel2;
	TAdvToolBarOfficeStyler *AdvToolBarOfficeStyler1;
	TPanel *Panel3;
	TOpenDialog *OpenDialog1;
	TipwXMLp *ipwXMLp1;
	TPanel *Panel4;
	TcxImageList *cxImageList2;
	TAdvMemo *AdvMemo1;
	TAdvMemoStylerManager *AdvMemoStylerManager1;
	TAdvXMLMemoStyler *AdvXMLMemoStyler1;
	TAdvEdit *AdvEdit1;
	TAdvEdit *AdvEdit2;
	TAdvEdit *AdvEdit3;
	TAdvEdit *AdvEdit4;
	TAdvComboBox *AdvComboBox1;
	TAdvEdit *AdvEdit5;
	TAdvComboBox *AdvComboBox2;
	TAdvEdit *AdvEdit6;
	TAdvEdit *AdvEdit7;
	TAdvEdit *AdvEdit8;
	TAdvEdit *AdvEdit9;
	TAdvEdit *AdvEdit10;
	TAdvSplitter *AdvSplitter2;
	TcxDateEdit *cxDateEdit1;
	TcxLabel *cxLabel1;
	TAdvDockPanel *AdvDockPanel2;
	TAdvToolBar *AdvToolBar2;
	TAdvToolBarButton *AdvToolBarButton3;
	TAdvDockPanel *AdvDockPanel3;
	TAdvToolBar *AdvToolBar3;
	TAdvToolBarButton *AdvToolBarButton4;
	TAdvToolBarButton *AdvToolBarButton5;
	TPanel *Panel5;
	TAdvDockPanel *AdvDockPanel1;
	TAdvToolBar *AdvToolBar1;
	TAdvToolBarButton *AdvToolBarButton2;
	TcxImageList *cxImageList3;
	TAdvToolBarButton *AdvToolBarButton1;
	TAdvToolBarButton *AdvToolBarButton6;
	TAdvToolBarButton *AdvToolBarButton7;
	TAdvToolBarButton *AdvToolBarButton8;
	TAdvEdit *AdvEdit12;
	TAdvToolBarSeparator *AdvToolBarSeparator1;
	TAdvSplitter *AdvSplitter1;
	TBevel *Bevel1;
	TAdvEdit *AdvEdit13;
	TAdvComboBox *AdvComboBox3;
	TAdvPanel *AdvPanel1;
	TAdvComboBox *AdvComboBox4;
	TAdvComboBox *AdvComboBox5;
	TAdvColumnGrid *AdvColumnGrid2;
	TAdvToolBarButton *AdvToolBarButton9;
	TAdvToolBarButton *AdvToolBarButton10;
	TAdvStringGrid *AdvStringGrid1;
	TAdvColumnGrid *AdvColumnGrid3;
	TTimer *Timer1;
	TAdvPopupMenu *AdvPopupMenu1;
	TMenuItem *Edit1;
	TMenuItem *Delete1;
	TAdvMenuStyler *AdvMenuStyler1;
	TAdvPicture *AdvPicture1;
	TAdvToolBarButton *AdvToolBarButton11;
	TAdvColumnGrid *AdvColumnGrid4;
	TAdvSplitter *AdvSplitter3;
	TAdvDockPanel *AdvDockPanel4;
	TAdvToolBar *AdvToolBar4;
	TAdvToolBarButton *AdvToolBarButton12;
	TAdvToolBarButton *AdvToolBarButton13;
	TAdvToolBarButton *AdvToolBarButton14;
	TAdvToolBarButton *AdvToolBarButton15;
	TAdvToolBarButton *AdvToolBarButton16;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall AdvToolBarButton1Click(TObject *Sender);
	void __fastcall AdvEdit1Exit(TObject *Sender);
	void __fastcall AdvEdit2Exit(TObject *Sender);
	void __fastcall AdvToolBarButton3Click(TObject *Sender);
	void __fastcall AdvToolBarButton6Click(TObject *Sender);
	void __fastcall AdvSplitter1DblClick(TObject *Sender);
	void __fastcall AdvSplitter1CanResize(TObject *Sender, int &NewSize, bool &Accept);
	void __fastcall AdvEdit3Exit(TObject *Sender);
	void __fastcall AdvEdit9Exit(TObject *Sender);
	void __fastcall AdvEdit4Exit(TObject *Sender);
	void __fastcall AdvEdit8Exit(TObject *Sender);
	void __fastcall AdvEdit10Exit(TObject *Sender);
	void __fastcall AdvComboBox4Change(TObject *Sender);
	void __fastcall cxDateEdit1PropertiesChange(TObject *Sender);
	void __fastcall AdvEdit5Exit(TObject *Sender);
	void __fastcall AdvComboBox2Change(TObject *Sender);
	void __fastcall AdvComboBox1Change(TObject *Sender);
	void __fastcall AdvComboBox3Change(TObject *Sender);
	void __fastcall AdvEdit6Exit(TObject *Sender);
	void __fastcall AdvEdit7Exit(TObject *Sender);
	void __fastcall AdvEditValueValidate(TObject *Sender, UnicodeString Value, bool &IsValid);
	void __fastcall Panel3Resize(TObject *Sender);
	void __fastcall AdvToolBarButton7Click(TObject *Sender);
	void __fastcall AdvToolBarButton9Click(TObject *Sender);
	void __fastcall AdvColumnGrid2Exit(TObject *Sender);
	void __fastcall AdvToolBarButton4Click(TObject *Sender);
	void __fastcall AdvToolBarButton5Click(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall AdvMemo1GutterRightClick(TObject *Sender, int LineNo);
	void __fastcall Edit1Click(TObject *Sender);
	void __fastcall Delete1Click(TObject *Sender);
	void __fastcall AdvEdit12KeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall AdvToolBarButton2Click(TObject *Sender);
	void __fastcall AdvToolBarButton10Click(TObject *Sender);
	void __fastcall AdvComboBox1Enter(TObject *Sender);
	void __fastcall AdvComboBox3Enter(TObject *Sender);
	void __fastcall AdvToolBarButton11Click(TObject *Sender);
	void __fastcall AdvColumnGrid1ButtonClick(TObject *Sender, int ACol, int ARow);
	void __fastcall AdvToolBarButton13Click(TObject *Sender);
	void __fastcall AdvColumnGrid1CanClickCell(TObject *Sender, int ARow, int ACol,
          bool &Allow);
	void __fastcall AdvColumnGrid1CellChanging(TObject *Sender, int OldRow, int OldCol,
          int NewRow, int NewCol, bool &Allow);

private:	// User declarations
	TTilSpreadSheetForm *TSSForm;
	vector<UnicodeString> Sums;
	multimap<int,TControl*> MetadataControls;
	multimap<UnicodeString,int> SSTaxa;
	map<UnicodeString,bool> InSum;
	Graphics::TBitmap *ArrowBmp;
	UnicodeString Dictionary;
	vector<UnicodeString> Metadata;
	vector<TAXACOUNT> TaxaCounted;  // code, number
	int ssrow_end;
	int sscol;
	int spike_row;
	wchar_t SpikeChar;
	wchar_t ElemChar;
	UnicodeString ElemStr;
	double PSUM;
	double TSUM;
	double SpikeSampConc;
	int nspike;
	int nslide;
	int ntrans;
	int editrow;
	bool enter_spike;
	bool slide_query;
	bool conc_data;
	UnicodeString Comment;
	unsigned int Seconds;
	void InsertXMLLine(UnicodeString tag, UnicodeString text,
		UnicodeString attrtag=L"", UnicodeString attrval=L"");
	UnicodeString EncodeXMLDateTime(unsigned short year, unsigned short month, unsigned short day,
		unsigned short hour, unsigned short min, unsigned short sec);
	UnicodeString EncodeXMLDate(unsigned short year, unsigned short month, unsigned short day);
	int FindXMLLine(UnicodeString text);
	void ParseCode(UnicodeString& Code, UnicodeString& Pres, UnicodeString& Elem);
	void EnterCount(UnicodeString Code, UnicodeString Pres, UnicodeString Elem);
	void EnterSpike(void);
	int GetXMLSpikeCount(UnicodeString line);
	void InsertSS(UnicodeString Code, UnicodeString Name, Variant Value, int& row,
		UnicodeString Element=L"", UnicodeString Units=L"", UnicodeString Group=L"");
	void InsertSpike(void);
	bool ValidAdvEditFloatValue(TAdvEdit* AdvEdit);
	void ResetSums(void);
	void SetActiveLine(int row);
	void EditCount(void);
	void EnterSlide(void);
	void EnterTransect(void);
	bool ProcessKey(wchar_t& Key);
	bool ValidateCode(UnicodeString Code, wchar_t& Key);
	bool ValidateElem(UnicodeString Code, wchar_t& Key);
public:		// User declarations
	__fastcall TCounterForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TCounterForm *CounterForm;
//---------------------------------------------------------------------------
#endif
