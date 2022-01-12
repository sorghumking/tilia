//---------------------------------------------------------------------------

#ifndef TIMemoH
#define TIMemoH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "cxButtons.hpp"
#include "cxLookAndFeelPainters.hpp"
#include <Menus.hpp>
#include "cxGraphics.hpp"
#include "cxLookAndFeels.hpp"
#include <ExtCtrls.hpp>
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxEdit.hpp"
#include "cxTextEdit.hpp"
#include <ImgList.hpp>
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

//---------------------------------------------------------------------------
enum MEMOFORMOPTIONS { mfoCancelButton = 0, mfoBlankButton = 1, mfoReadOnly = 2,
	mfoTextEdit = 3, mfoOkOnEnter = 4 };
//---------------------------------------------------------------------------

typedef System::Set <short, 0, 9> MemoFormOptions;
//---------------------------------------------------------------------------

class TMemoForm : public TForm
{
__published:	// IDE-managed Components
	TMemo *Memo1;
	TcxButton *cxButton1;
	TcxButton *cxButton2;
	TFlowPanel *FlowPanel1;
	TcxTextEdit *cxTextEdit1;
	TPanel *Panel1;
	TcxImageList *cxImageList1;
	TcxButton *cxButton3;
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall cxButton1Click(TObject *Sender);
	void __fastcall cxButton2Click(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);
	void __fastcall cxTextEdit1KeyPress(TObject *Sender, wchar_t &Key);

private:	// User declarations
	MemoFormOptions Options;
	TStrings* getlines(void) { return Memo1->Lines; }
	UnicodeString gettext(void);
public:		// User declarations
	__fastcall TMemoForm(UnicodeString caption, UnicodeString Text,
		MemoFormOptions options, TComponent* Owner);
	__property TStrings* lines = {read = getlines};
	__property UnicodeString Text = {read = gettext};
};
//---------------------------------------------------------------------------

class TTaxonNotesForm : public TMemoForm
{
__published:	// IDE-managed Components
   void __fastcall FormActivate(TObject *Sender);
private:
	TPoint Position;
public:
   __fastcall TTaxonNotesForm(UnicodeString caption, UnicodeString Text,
		MemoFormOptions options, TPoint& Pos, TComponent* Owner);
};
//---------------------------------------------------------------------------

class TEPDNotesPrepForm : public TMemoForm
{
__published:	// IDE-managed Components
	void __fastcall cxButton1Click(TObject *Sender);
	void __fastcall cxButton2Click(TObject *Sender);
private:
	int FCommentType;
public:
   __fastcall TEPDNotesPrepForm(UnicodeString caption, UnicodeString Text,
		MemoFormOptions options, TComponent* Owner);
   __property int CommentType = {read = FCommentType};
};
//---------------------------------------------------------------------------

extern PACKAGE TMemoForm *MemoForm;
extern PACKAGE TTaxonNotesForm *TaxonNotesForm;
extern PACKAGE TEPDNotesPrepForm *EPDNotesPrepForm;
//---------------------------------------------------------------------------
#endif
