//---------------------------------------------------------------------------

#ifndef TIExpChrH
#define TIExpChrH
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "cxButtons.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include "cxRadioGroup.hpp"
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxEdit.hpp"
#include "cxGroupBox.hpp"
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
#include "AdvEdit.hpp"
#include "cxLabel.hpp"
#include "cxCheckBox.hpp"
#ifndef TIAgeModH
#include "TIAgeMod.h"
#endif
#ifndef TIGeochrH
#include "TIGeochr.h"
#endif
//---------------------------------------------------------------------------

enum CHRONCONTROLOUTPUTTYPES { ccoClam=0, ccoBacon=1, ccoBchron=2, ccoPSequence=3 };
enum CHRONCONTROLOUTHEMISPHERE { cchIntCal=0, cchSHCal=1, cchMarine=2 };
enum OXCALLIST { oxDate=0, oxSample=1 };
//---------------------------------------------------------------------------

class OXCALSCRIPT
{
private:
	double FDepth;
	AnsiString FLine;
public:
	OXCALSCRIPT(double depth, AnsiString line)
	  { FDepth = depth; FLine = line; }
	__property double Depth = {read = FDepth, write = FDepth};
	__property AnsiString Line = {read = FLine, write = FLine};
} ;
//---------------------------------------------------------------------------

class TChronControlExportForm : public TForm
{
__published:	// IDE-managed Components
	TFlowPanel *FlowPanel1;
	TcxButton *cxButton1;
	TcxButton *cxButton2;
	TSaveDialog *SaveDialog1;
	TcxRadioGroup *cxRadioGroup1;
	TcxRadioGroup *cxRadioGroup2;
	TAdvEdit *AdvEdit1;
	TcxGroupBox *cxGroupBox1;
	TcxRadioGroup *cxRadioGroup3;
	TcxLabel *cxLabel1;
	TcxGroupBox *cxGroupBox2;
	TcxRadioButton *cxRadioButton1;
	TcxRadioButton *cxRadioButton2;
	void __fastcall cxButton1Click(TObject *Sender);
	void __fastcall cxRadioGroup1Click(TObject *Sender);
	void __fastcall cxRadioGroup2Click(TObject *Sender);
	void __fastcall cxRadioGroup3Click(TObject *Sender);
	void __fastcall cxRadioButton1Click(TObject *Sender);
	void __fastcall cxRadioButton2Click(TObject *Sender);
private:	// User declarations
	AGEMODEL* AgeModel;
	TGeochronList* GeochronList;
	set<UnicodeString> GeochronControls;
	map<double,double> Depths;   // depth, thickness
private:
	GEOCHRON* GetDate(int ID);
	bool GetAge(CHRON* ChronControl, double& age);
	double GetThickness(CHRON* ChronControl);
	bool GetError(CHRON* ChronControl, double& error);
	UnicodeString GetName(CHRON* ChronControl);
	int GetReservoir(CHRON* ChronControl);
	bool WriteDepths(UnicodeString& FileName);
	void SetOxCalInterval(void);
public:		// User declarations
	__fastcall TChronControlExportForm(AGEMODEL* age_model, TGeochronList* geochron_list,
		TcxTreeView* tree_view, map<double,double>& depths, TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TChronControlExportForm *ChronControlExportForm;
//---------------------------------------------------------------------------
#endif
