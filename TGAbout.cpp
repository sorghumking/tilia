//---------------------------------------------------------------------
#include <vcl.h>
#include "pch.h"
#pragma hdrstop
#include "TGAbout.h"
#ifndef TIVersionH
#include "TIVersion.h"
#endif

//--------------------------------------------------------------------- 
#pragma link "cxButtons"
#pragma link "cxGraphics"
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
TAboutBox *AboutBox;
//--------------------------------------------------------------------- 
__fastcall TAboutBox::TAboutBox(TComponent* AOwner) : TForm(AOwner)
{
   CURRENTVERSION CurrentVersion;
   Version->Caption = "Version " + CurrentVersion.Version();
   if (tiLicense->Type() == verFREE)
	 LicenseLabel->Visible = false;
}
//---------------------------------------------------------------------


void __fastcall TAboutBox::FormActivate(TObject *Sender)
{
   UnicodeString msg;
   if (tiLicense->Type() == verTRAINING) {
	 msg = tiLicense->GetOwner() + L" license. Expires " + tiLicense->GetExpirationDate() + L".";
	 LicenseLabel->Caption = msg;
	 }
   else if (tiLicense->Type() != verFREE) {
	 msg = "Licensed to: " + tiLicense->GetOwner() + ".";
	 if (tiLicense->Type() == verSTUDENT || tiLicense->Type() == verTRAINING)
	   msg += (L" Expires " + tiLicense->GetExpirationDate() + L".");
	 LicenseLabel->Caption = msg;
	 }
}
//---------------------------------------------------------------------------

