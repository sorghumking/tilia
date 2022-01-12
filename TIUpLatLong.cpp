//---------------------------------------------------------------------------
#include <vcl.h>
#include "pch.h"
#pragma hdrstop

#include "TIUpLatLong.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxGroupBox"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxMemo"
#pragma link "cxTextEdit"
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
TValidateLatLongForm *ValidateLatLongForm;

//---------------------------------------------------------------------------
__fastcall TValidateLatLongForm::TValidateLatLongForm(TComponent* Owner)
	: TForm(Owner)
{
   upf = (TNeotomaUploadForm*)Owner;
   TSSForm = upf->TSSForm;
}
//---------------------------------------------------------------------------

void __fastcall TValidateLatLongForm::FormCreate(TObject *Sender)
{
   WorldMap = new Graphics::TBitmap;

   LatLongLines.push_back(L"Site is located in the Northern and Eastern Hemispheres.");  //0
   LatLongLines.push_back(L"Site is located in the Southern and Eastern Hemispheres.");  //1
   LatLongLines.push_back(L"Site is located in the Southern and Western Hemispheres.");  //2
   LatLongLines.push_back(L"Site is located in the Northern and Western Hemispheres.");  //3
   LatLongLines.push_back(L"Site is located on the Equator in the Western Hemisphere."); //4
   LatLongLines.push_back(L"Site is located on the Equator in the Eastern Hemisphere."); //5
   LatLongLines.push_back(L"Site is located on the Greenwich Meridian in the Northern Hemisphere.");  //6
   LatLongLines.push_back(L"Site is located on the Greenwich Meridian in the Southern Hemisphere.");  //7
   LatLongLines.push_back(L"Site is located on the Equator and on the Greenwich Meridian."); //8
   LatLongLines.push_back(L"If the coordinates are correct, click «Yes».");                  //9
   LatLongLines.push_back(L"If the absolute values are correct, but in the wrong hemisphere, click the correct hemisphere."); //10
   LatLongLines.push_back(L"If the coordinates are incorrect, or if you're not sure, click «No».");   //11

   SiteMetadataUpdated = false;
   AllowHemisphereSwitch = false;
   UnicodeString Line;

   site_ptr = upf->site_ptr;

   LabeledEdit1->Text = site_ptr->LatNorth.AsType(varOleStr);
   LabeledEdit2->Text = site_ptr->LatSouth.AsType(varOleStr);
   LabeledEdit3->Text = site_ptr->LongWest.AsType(varOleStr);
   LabeledEdit4->Text = site_ptr->LongEast.AsType(varOleStr);

   cxMemo1->Lines->Clear();
   if (site_ptr->LatNorth > 0 && site_ptr->LatSouth >= 0) {  // Northern Hemisphere
	 if (site_ptr->LongEast > 0 && site_ptr->LongWest >= 0) { // NE Hemisphere
	   cxMemo1->Lines->Add(LatLongLines[0]);
	   ImageList1->GetBitmap(0, WorldMap);
	   Image1->Picture->Assign(WorldMap);
	   AllowHemisphereSwitch = true;
	   }
	 else if (site_ptr->LongWest < 0 && site_ptr->LongEast <= 0) {   // NW Hemisphere
	   cxMemo1->Lines->Add(LatLongLines[3]);
	   ImageList1->GetBitmap(3, WorldMap);
	   Image1->Picture->Assign(WorldMap);
	   AllowHemisphereSwitch = true;
	   }
	 else {  // North Greenwich
	   cxMemo1->Lines->Add(LatLongLines[6]);
	   ImageList1->GetBitmap(6, WorldMap);
	   Image1->Picture->Assign(WorldMap);
	   }
	 }
   else if (site_ptr->LatSouth < 0 && site_ptr->LatNorth <= 0) {  // Southern Hemisphere
	 if (site_ptr->LongEast > 0 && site_ptr->LongWest >= 0) { // SE Hemisphere
	   cxMemo1->Lines->Add(LatLongLines[1]);
	   ImageList1->GetBitmap(1, WorldMap);
	   Image1->Picture->Assign(WorldMap);
	   AllowHemisphereSwitch = true;
	   }
	 else if (site_ptr->LongWest < 0 && site_ptr->LongEast <= 0) {  // SW Hemisphere
	   cxMemo1->Lines->Add(LatLongLines[2]);
	   ImageList1->GetBitmap(2, WorldMap);
	   Image1->Picture->Assign(WorldMap);
	   AllowHemisphereSwitch = true;
	   }
	 else { // South Greenwich
	   cxMemo1->Lines->Add(LatLongLines[7]);
	   ImageList1->GetBitmap(7, WorldMap);
	   Image1->Picture->Assign(WorldMap);
	   }
	 }
   else {	// lies on Equator
	 if (site_ptr->LongEast > 0 && site_ptr->LongWest >= 0) {  // East Equator
	   cxMemo1->Lines->Add(LatLongLines[5]);
	   ImageList1->GetBitmap(5, WorldMap);
	   Image1->Picture->Assign(WorldMap);
	   }
	 else if (site_ptr->LongWest < 0 && site_ptr->LongEast <= 0) { // West Equator
	   cxMemo1->Lines->Add(LatLongLines[4]);
	   ImageList1->GetBitmap(4, WorldMap);
	   Image1->Picture->Assign(WorldMap);
	   }
	 else {   // Equator Greenwich
	   cxMemo1->Lines->Add(LatLongLines[8]);
	   ImageList1->GetBitmap(8, WorldMap);
	   Image1->Picture->Assign(WorldMap);
	   }
	 }

   cxMemo1->Lines->Add(LatLongLines[9]);
   if (AllowHemisphereSwitch)
	 cxMemo1->Lines->Add(LatLongLines[10]);
   cxMemo1->Lines->Add(LatLongLines[11]);
}
//---------------------------------------------------------------------------

void __fastcall TValidateLatLongForm::FormClose(TObject *Sender, TCloseAction &Action)
{
   delete WorldMap;
}
//---------------------------------------------------------------------------


void __fastcall TValidateLatLongForm::cxButton6Click(TObject *Sender)
{
   if (SiteMetadataUpdated && TSSForm->Sites->Count == 1) {
	 TSSForm->SitePtr = site_ptr;
	 TSSForm->FillSiteMetaData(site_ptr);
	 SiteMetadataUpdated = false;
	 }
   upf->OutputLine(L"Site lat-long coordinates validated.");
}
//---------------------------------------------------------------------------

void __fastcall TValidateLatLongForm::cxButton7Click(TObject *Sender)
{
   upf->OutputError(L"ERROR: Site lat-long coordinates are not valid.");
}
//---------------------------------------------------------------------------

// change hemispheres
void __fastcall TValidateLatLongForm::Image1MouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
   if (!AllowHemisphereSwitch) {
	 Beep();
	 return;
	 }

   bool north1 = (site_ptr->LatNorth > 0 && site_ptr->LatSouth >= 0);
   bool south1 = (site_ptr->LatSouth < 0 && site_ptr->LatNorth <= 0);
   bool east1 =  (site_ptr->LongEast > 0 && site_ptr->LongWest >= 0);
   bool west1 =  (site_ptr->LongWest < 0 && site_ptr->LongEast <= 0);

   int midx = Image1->Width/2;
   int midy = Image1->Height/2;
   if (X < midx && Y < midy) {  // NW
	 site_ptr->LatNorth = fabs(site_ptr->LatNorth);
	 site_ptr->LatSouth = fabs(site_ptr->LatSouth);
	 site_ptr->LongWest = -fabs(site_ptr->LongWest);
	 site_ptr->LongEast = -fabs(site_ptr->LongEast);
	 cxMemo1->Lines->Strings[0] = LatLongLines[3];
	 ImageList1->GetBitmap(3, WorldMap);
	 Image1->Picture->Assign(WorldMap);
	 }
   else if (X > midx && Y < midy) {  // NE
	 site_ptr->LatNorth = fabs(site_ptr->LatNorth);
	 site_ptr->LatSouth = fabs(site_ptr->LatSouth);
	 site_ptr->LongWest = fabs(site_ptr->LongWest);
	 site_ptr->LongEast = fabs(site_ptr->LongEast);
	 cxMemo1->Lines->Strings[0] = LatLongLines[0];
	 ImageList1->GetBitmap(0, WorldMap);
	 Image1->Picture->Assign(WorldMap);
	 }
   else if (X > midx && Y > midy) {  // SE
	 site_ptr->LatNorth = -fabs(site_ptr->LatNorth);
	 site_ptr->LatSouth = -fabs(site_ptr->LatSouth);
	 site_ptr->LongWest = fabs(site_ptr->LongWest);
	 site_ptr->LongEast = fabs(site_ptr->LongEast);
	 cxMemo1->Lines->Strings[0] = LatLongLines[1];
	 ImageList1->GetBitmap(1, WorldMap);
	 Image1->Picture->Assign(WorldMap);
	 }
   else if (X < midx && Y > midy) {  // SW
	 site_ptr->LatNorth = -fabs(site_ptr->LatNorth);
	 site_ptr->LatSouth = -fabs(site_ptr->LatSouth);
	 site_ptr->LongWest = -fabs(site_ptr->LongWest);
	 site_ptr->LongEast = -fabs(site_ptr->LongEast);
	 cxMemo1->Lines->Strings[0] = LatLongLines[2];
	 ImageList1->GetBitmap(2, WorldMap);
	 Image1->Picture->Assign(WorldMap);
	 }

   if (site_ptr->LatNorth < site_ptr->LatSouth) {
	 Variant temp = site_ptr->LatNorth;
	 site_ptr->LatNorth = site_ptr->LatSouth;
	 site_ptr->LatSouth = temp;
	 }
   if (site_ptr->LongEast < site_ptr->LongWest) {
	 Variant temp = site_ptr->LongEast;
	 site_ptr->LongEast = site_ptr->LongWest;
	 site_ptr->LongWest = temp;
	 }

   LabeledEdit1->Text = site_ptr->LatNorth.AsType(varOleStr);
   LabeledEdit2->Text = site_ptr->LatSouth.AsType(varOleStr);
   LabeledEdit3->Text = site_ptr->LongWest.AsType(varOleStr);
   LabeledEdit4->Text = site_ptr->LongEast.AsType(varOleStr);

   bool north2 = (site_ptr->LatNorth > 0 && site_ptr->LatSouth >= 0);
   bool south2 = (site_ptr->LatSouth < 0 && site_ptr->LatNorth <= 0);
   bool east2 =  (site_ptr->LongEast > 0 && site_ptr->LongWest >= 0);
   bool west2 =  (site_ptr->LongWest < 0 && site_ptr->LongEast <= 0);

   if (north1 && south2)
	 upf->OutputNote(L"NOTE: Site lat-long coordinates moved from Northern Hemisphere to Southern Hemisphere");
   else if (south1 && north2)
	 upf->OutputNote(L"NOTE: Site lat-long coordinates moved from Southern Hemisphere to Northern Hemisphere");
   if (east1 && west2)
	 upf->OutputNote(L"NOTE: Site lat-long coordinates moved from Eastern Hemisphere to Western Hemisphere");
   else if (west1 && east2)
	 upf->OutputNote(L"NOTE: Site lat-long coordinates moved from Western Hemisphere to Eastern Hemisphere");

   SiteMetadataUpdated = true;
}
//---------------------------------------------------------------------------

