//---------------------------------------------------------------------------

#ifndef TIImpChrH
#define TIImpChrH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxEdit.hpp"
#include "cxGraphics.hpp"
#include "cxGroupBox.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include "cxMaskEdit.hpp"
#include "cxRadioGroup.hpp"
#include "cxSpinEdit.hpp"
#include "cxTextEdit.hpp"
#include "cxButtons.hpp"
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <ImgList.hpp>
#include <Menus.hpp>
#include "cxCheckBox.hpp"
//---------------------------------------------------------------------------
#include <iostream.h>
#include <fstream.h>
#include <IOUtils.hpp>
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
#ifndef TISpreadH
#include "TISpread.h"
#endif
//---------------------------------------------------------------------------
enum AGEVALUETYPE { avtMedian, avtWeightedMean };
//---------------------------------------------------------------------------

typedef struct {
  double min;
  double max;
  double median;
  double wmean;
  } BACON;
//---------------------------------------------------------------------------

typedef struct
{
  double min;
  double max;
  double best;
  double accrate;
} CLAM;
//---------------------------------------------------------------------------

class TImportChronForm : public TForm
{
__published:	// IDE-managed Components
	TcxSpinEdit *cxSpinEdit1;
	TLabel *Label1;
	TcxRadioGroup *cxRadioGroup1;
	TFlowPanel *FlowPanel1;
	TcxButton *cxButton1;
	TcxImageList *cxImageList1;
	TcxButton *cxButton2;
	TOpenDialog *OpenDialog1;
	TcxCheckBox *cxCheckBox1;
	void __fastcall cxButton1Click(TObject *Sender);
protected:
	TTilSpreadSheetForm* TSSForm;
	TFileStream* InputFileStream;
	TStreamReader* reader;
	UnicodeString InputFileExt;
	map<double,BACON> Bacon;
	bool OpenFile(UnicodeString& FileName);
	bool GetTabbedValue(AnsiString& line, double& depth);
	void CloseFile(void);
	void WriteToSpreadsheet(UnicodeString Model);
public:		// User declarations
	__fastcall TImportChronForm(TComponent* Owner);
};
//---------------------------------------------------------------------------

class TImportClamForm : public TImportChronForm
{
__published:	// IDE-managed Components
	void __fastcall cxButton1Click(TObject *Sender);
private:
	bool ImportClam(void);
public:		// User declarations
	__fastcall TImportClamForm(TComponent* Owner);
};
//---------------------------------------------------------------------------

class TImportBaconForm : public TImportChronForm
{
__published:	// IDE-managed Components
	void __fastcall cxButton1Click(TObject *Sender);
private:
	bool ImportBacon(void);
public:		// User declarations
	__fastcall TImportBaconForm(TComponent* Owner);
};
//---------------------------------------------------------------------------

class TImportBchronForm : public TImportChronForm
{
__published:	// IDE-managed Components
	void __fastcall cxButton1Click(TObject *Sender);
private:
	bool ImportBchron(void);
	bool GetBchron(AnsiString line, AnsiString param, double& value);
public:		// User declarations
	__fastcall TImportBchronForm(TComponent* Owner);
};
//---------------------------------------------------------------------------

class TImportOxCalForm : public TImportChronForm
{
__published:	// IDE-managed Components
	void __fastcall cxButton1Click(TObject *Sender);
private:
	bool ImportOxCal(void);
public:		// User declarations
	__fastcall TImportOxCalForm(TComponent* Owner);
};
//---------------------------------------------------------------------------

extern PACKAGE TImportChronForm *ImportChronForm;
extern PACKAGE TImportClamForm *ImportClamForm;
extern PACKAGE TImportBaconForm *ImportBaconForm;
extern PACKAGE TImportBchronForm *ImportBchronForm;
extern PACKAGE TImportOxCalForm *ImportOxCalForm;
//---------------------------------------------------------------------------
#endif
