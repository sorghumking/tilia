//---------------------------------------------------------------------------

#include <vcl.h>
#include "pch.h"
#pragma hdrstop

#include "TIImpDat.h"
#ifndef TICalibH
#include "TICalib.h"
#endif
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxRadioGroup"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxImage"
#pragma link "dxGDIPlusClasses"
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
#pragma resource "*.dfm"
TImportGeochronForm *ImportGeochronForm;
//---------------------------------------------------------------------------
__fastcall TImportGeochronForm::TImportGeochronForm(Variant latitude, TComponent* Owner)
	: TForm(Owner)
{
   fnsigma = 1;
   fcalibrate = false;
   if (!latitude.IsEmpty()) {
	 double Latitude = latitude;
	 if (Latitude >= 0.0) {
	   fcalibcurve = INTCAL13;
	   cxRadioButton5->Checked = true;
	   }
	 else {
	   fcalibcurve = SHCAL13;
	   cxRadioButton6->Checked = true;
	   }
	 }
   else
     fcalibcurve = -1;
}
//---------------------------------------------------------------------------

void __fastcall TImportGeochronForm::cxRadioButton1Click(TObject *Sender)
{
   fcalibrate = true;
   Label2->Enabled = false;
   cxRadioButton3->Enabled = false;
   cxRadioButton4->Enabled = false;
   Label3->Enabled = true;
   cxRadioButton5->Enabled = true;
   cxRadioButton6->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TImportGeochronForm::cxRadioButton2Click(TObject *Sender)
{
   fcalibrate = false;
   Label2->Enabled = true;
   cxRadioButton3->Enabled = true;
   cxRadioButton4->Enabled = true;
   Label3->Enabled = false;
   cxRadioButton5->Enabled = false;
   cxRadioButton6->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TImportGeochronForm::cxRadioButton3Click(TObject *Sender)
{
  fnsigma = 1;
}
//---------------------------------------------------------------------------

void __fastcall TImportGeochronForm::cxRadioButton4Click(TObject *Sender)
{
  fnsigma = 2;
}
//---------------------------------------------------------------------------

void __fastcall TImportGeochronForm::cxRadioButton5Click(TObject *Sender)
{
   fcalibcurve = INTCAL13;
}
//---------------------------------------------------------------------------

void __fastcall TImportGeochronForm::cxRadioButton6Click(TObject *Sender)
{
   fcalibcurve = SHCAL13;
}
//---------------------------------------------------------------------------

// Ok button
void __fastcall TImportGeochronForm::cxButton1Click(TObject *Sender)
{
   ModalResult = mrOk;
   if (fcalibrate && fcalibcurve == -1) {
	 UnicodeString msg = L"Calibration curve not selected!";
	 if (MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbRetry << mbCancel, 0) == mrRetry)
	   ModalResult = mrNone;
	 else
	   ModalResult = mrCancel;
	 }
}
//---------------------------------------------------------------------------

