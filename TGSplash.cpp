//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "shlobj.h"
#include <Registry.hpp>
#include "TGSplash.h"
#ifndef TIVersionH
#include "TIVersion.h"
#endif
#ifndef TIGlobalsH
#include "TIGlobals.h"
#endif

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxLabel"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "dxSkinBlack"
#pragma link "dxSkinBlue"
#pragma link "dxSkinBlueprint"
#pragma link "dxSkinCaramel"
#pragma link "dxSkinCoffee"
#pragma link "dxSkinDarkRoom"
#pragma link "dxSkinDarkSide"
#pragma link "dxSkinDevExpressDarkStyle"
#pragma link "dxSkinDevExpressStyle"
#pragma link "dxSkinFoggy"
#pragma link "dxSkinGlassOceans"
#pragma link "dxSkinHighContrast"
#pragma link "dxSkiniMaginary"
#pragma link "dxSkinLilian"
#pragma link "dxSkinLiquidSky"
#pragma link "dxSkinLondonLiquidSky"
#pragma link "dxSkinMcSkin"
#pragma link "dxSkinMetropolis"
#pragma link "dxSkinMetropolisDark"
#pragma link "dxSkinMoneyTwins"
#pragma link "dxSkinOffice2007Black"
#pragma link "dxSkinOffice2007Blue"
#pragma link "dxSkinOffice2007Green"
#pragma link "dxSkinOffice2007Pink"
#pragma link "dxSkinOffice2007Silver"
#pragma link "dxSkinOffice2010Black"
#pragma link "dxSkinOffice2010Blue"
#pragma link "dxSkinOffice2010Silver"
#pragma link "dxSkinOffice2013DarkGray"
#pragma link "dxSkinOffice2013LightGray"
#pragma link "dxSkinOffice2013White"
#pragma link "dxSkinPumpkin"
#pragma link "dxSkinsCore"
#pragma link "dxSkinsDefaultPainters"
#pragma link "dxSkinSeven"
#pragma link "dxSkinSevenClassic"
#pragma link "dxSkinSharp"
#pragma link "dxSkinSharpPlus"
#pragma link "dxSkinSilver"
#pragma link "dxSkinSpringTime"
#pragma link "dxSkinStardust"
#pragma link "dxSkinSummer2008"
#pragma link "dxSkinTheAsphaltWorld"
#pragma link "dxSkinValentine"
#pragma link "dxSkinVS2010"
#pragma link "dxSkinWhiteprint"
#pragma link "dxSkinXmas2008Blue"
#pragma link "dxSkinOffice2016Colorful"
#pragma link "dxSkinOffice2016Dark"
#pragma link "dxSkinVisualStudio2013Blue"
#pragma link "dxSkinVisualStudio2013Dark"
#pragma link "dxSkinVisualStudio2013Light"
#pragma resource "*.dfm"
TSplashForm *SplashForm;
//---------------------------------------------------------------------------
__fastcall TSplashForm::TSplashForm(TComponent* Owner)
		: TForm(Owner)
{
  CURRENTVERSION CurrentVersion;
  Label2->Caption = "Version " + CurrentVersion.Version();
  Label2->Font->Color = (TColor)0x00006400;
  Label3->Font->Color = (TColor)0x00006400;
  Label4->Font->Color = (TColor)0x00006400;

  if (tiLicense->Type() != verFREE) {
	UnicodeString Owner;

	UnicodeString Path = tiGlobals->AppDataTiliaPath;
	if (!Path.IsEmpty()) {
	  Path += L"Tilia.INI";
	  TIniFile *SettingsFile = new TIniFile(Path);
	  try {
		  Owner = SettingsFile->ReadString(L"Registration", L"Owner", Owner);
		  }
	  catch(Exception &e) {
		  MessageDlg(e.Message, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		  }
	  delete SettingsFile;
	  }

	if (Owner.IsEmpty())
	  Label1->Visible = false;
	else if (tiLicense->Type() == verTRAINING)
	  Label1->Caption = Owner;
	else
	  Label1->Caption = "Licensed to " + Owner + ".";
	}
  else
	Label1->Visible = false;
}
//---------------------------------------------------------------------------


