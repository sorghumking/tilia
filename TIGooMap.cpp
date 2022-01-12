//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#ifndef TIGlobalsH
#include "TIGlobals.h"
#endif
#include "TIGooMap.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "UWebGMaps"
#pragma link "UWebGMapsCommon"
#pragma link "UWebGMapsGeocoding"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxLabel"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxButtons"
#pragma link "cxGroupBox"
#pragma link "cxRadioGroup"
#pragma link "cxImage"
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
TGoogleMapForm *GoogleMapForm;
//---------------------------------------------------------------------------

__fastcall TGoogleMapForm::TGoogleMapForm(bool point, Variant lat_north, Variant lat_south,
	Variant long_west, Variant long_east, TComponent* Owner)
	: TForm(Owner)
{
   activated = false;
   Height = tiGlobals->GoogleMapHeight;
   Width = tiGlobals->GoogleMapWidth;
   cxGroupBox1Height = cxGroupBox1->Height;

   if (!lat_north.IsEmpty() && !lat_south.IsEmpty()) {
	 FLatNorth = lat_north;
	 FLatSouth = lat_south;
	 WebGMaps1->MapOptions->DefaultLatitude = (FLatNorth + FLatSouth)/2.0;
	 }
   else
	 WebGMaps1->MapOptions->DefaultLatitude = tiGlobals->GoogleMapLatitude;

   if (!long_west.IsEmpty() && !long_east.IsEmpty()) {
	 FLongWest = long_west;
	 FLongEast = long_east;
	 WebGMaps1->MapOptions->DefaultLongitude = (FLongWest + FLongEast)/2.0;
	 }
   else
	 WebGMaps1->MapOptions->DefaultLongitude = tiGlobals->GoogleMapLongitude;

   if (!point && (FLatNorth <= FLatSouth || FLongEast <= FLongWest))
	 point = true;

   if (point) {
	 cxRadioButton1->Checked = true;
	 cxLabel5->Width = 56;
	 cxLabel5->Caption = L"Latitude:";
	 cxLabel7->Width = 56;
	 cxLabel7->Caption = L"Longitude:";
	 cxGroupBox1->Height -= 34;
	 cxLabel9->Visible = false;
	 cxLabel10->Visible = false;
	 cxLabel11->Visible = false;
	 cxLabel12->Visible = false;
	 FlowPanel3->Visible = false;
	 }
   else
	 cxRadioButton2->Checked = true;

   UnicodeString Icon = L"";
   UnicodeString SiteName = L"";
   WebGMaps1->Markers->Add(WebGMaps1->MapOptions->DefaultLatitude,
	 WebGMaps1->MapOptions->DefaultLongitude, SiteName, Icon, false, true, true, true, false, 0);

  if (point) {
	cxLabel6->Caption = FloatToStr(SimpleRoundTo(WebGMaps1->MapOptions->DefaultLatitude,-5));
	cxLabel8->Caption = FloatToStr(SimpleRoundTo(WebGMaps1->MapOptions->DefaultLongitude,-5));
	WebGMaps1->Markers->Items[0]->Draggable = true;
	}
  else {
	TMapPolygon* Box = WebGMaps1->Polygons->Items[0]->Polygon;
	Box->Bounds->NorthEast->Latitude = FLatNorth;
	Box->Bounds->NorthEast->Longitude = FLongEast;
	Box->Bounds->SouthWest->Latitude = FLatSouth;
	Box->Bounds->SouthWest->Longitude = FLongWest;
	Box->Visible = true;
	cxLabel6->Caption = FloatToStr(SimpleRoundTo(Box->Bounds->NorthEast->Latitude,-5));
	cxLabel8->Caption = FloatToStr(SimpleRoundTo(Box->Bounds->SouthWest->Latitude,-5));
	cxLabel10->Caption = FloatToStr(SimpleRoundTo(Box->Bounds->SouthWest->Longitude,-5));
	cxLabel12->Caption = FloatToStr(SimpleRoundTo(Box->Bounds->NorthEast->Longitude,-5));
	}
}
//---------------------------------------------------------------------------

void __fastcall TGoogleMapForm::FormActivate(TObject *Sender)
{
   if (!activated) {
	 activated = true;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TGoogleMapForm::FormClose(TObject *Sender, TCloseAction &Action)
{
   tiGlobals->GoogleMapHeight = Height;
   tiGlobals->GoogleMapWidth = Width;
}
//---------------------------------------------------------------------------

void __fastcall TGoogleMapForm::WebGMaps1DownloadFinish(TObject *Sender)
{
   if (cxRadioButton2->Checked) {  // box
	 TBounds* Bounds = WebGMaps1->Polygons->Items[0]->Polygon->Bounds;
	 WebGMaps1->MapZoomTo(Bounds);
	 }
}
//---------------------------------------------------------------------------

void __fastcall TGoogleMapForm::WebGMaps1MapMouseMove(TObject *Sender, double Latitude,
          double Longitude, int X, int Y)
{
   cxLabel2->Caption = FloatToStr(SimpleRoundTo(Latitude,-5));
   cxLabel4->Caption = FloatToStr(SimpleRoundTo(Longitude,-5));
   //WebGMaps1->GetElevation(Latitude,Longitude);
   //int count = WebGMaps1->Elevations->Count;
   //cxLabel14->Caption = FloatToStr(SimpleRoundTo(WebGMaps1->Elevations->Items[count-1]->Elevation,0));
}
//---------------------------------------------------------------------------

// North button
void __fastcall TGoogleMapForm::cxButton1Click(TObject *Sender)
{
   if (cxButton1->Down) {
	 WebGMaps1->MapOptions->Draggable = false;
	 cxButton5->OptionsImage->ImageIndex = 0;
	 }
   else {
	 WebGMaps1->MapOptions->Draggable = true;
	 cxButton5->OptionsImage->ImageIndex = -1;
	 }
}
//---------------------------------------------------------------------------

// East button
void __fastcall TGoogleMapForm::cxButton3Click(TObject *Sender)
{
   if (cxButton3->Down) {
	 WebGMaps1->MapOptions->Draggable = false;
	 cxButton5->OptionsImage->ImageIndex = 1;
	 }
   else {
	 WebGMaps1->MapOptions->Draggable = true;
	 cxButton5->OptionsImage->ImageIndex = -1;
	 }
}
//---------------------------------------------------------------------------

// South button
void __fastcall TGoogleMapForm::cxButton4Click(TObject *Sender)
{
   if (cxButton4->Down) {
	 WebGMaps1->MapOptions->Draggable = false;
	 cxButton5->OptionsImage->ImageIndex = 2;
	 }
   else {
	 WebGMaps1->MapOptions->Draggable = true;
	 cxButton5->OptionsImage->ImageIndex = -1;
	 }
}
//---------------------------------------------------------------------------

// West button
void __fastcall TGoogleMapForm::cxButton2Click(TObject *Sender)
{
   if (cxButton2->Down) {
	 WebGMaps1->MapOptions->Draggable = false;
	 cxButton5->OptionsImage->ImageIndex = 3;
	 }
   else {
	 WebGMaps1->MapOptions->Draggable = true;
	 cxButton5->OptionsImage->ImageIndex = -1;
	 }
}
//---------------------------------------------------------------------------

// compass button
void __fastcall TGoogleMapForm::cxButton5Click(TObject *Sender)
{
   switch (cxButton5->OptionsImage->ImageIndex) {
	 case -1:
	 case 3:
	   cxButton5->OptionsImage->ImageIndex = 0;
	   cxButton1->Down = true;
	   break;
	 case 0:
	   cxButton5->OptionsImage->ImageIndex = 1;
	   cxButton3->Down = true;
	   break;
	 case 1:
	   cxButton5->OptionsImage->ImageIndex = 2;
	   cxButton4->Down = true;
	   break;
	 case 2:
	   cxButton5->OptionsImage->ImageIndex = 3;
	   cxButton2->Down = true;
	   break;
	 }
   WebGMaps1->MapOptions->Draggable = false;
}
//---------------------------------------------------------------------------

void __fastcall TGoogleMapForm::WebGMaps1MapClick(TObject *Sender, double Latitude,
          double Longitude, int X, int Y, TMouseButton Button)
{
   if (cxButton1->Down) {   // north
	 if (Latitude > FLatSouth) {
	   WebGMaps1->Polygons->Items[0]->Polygon->Bounds->NorthEast->Latitude = Latitude;
	   WebGMaps1->UpdateMapPolygon(WebGMaps1->Polygons->Items[0]->Polygon);
	   FLatNorth = SimpleRoundTo(Latitude,-5);
	   cxLabel6->Caption = FloatToStr(FLatNorth);
	   WebGMaps1->Markers->Items[0]->Latitude = (FLatNorth + FLatSouth)/2.0;
	   }
	 else
	   Beep();
	 }
   else if (cxButton3->Down) {  // east
	 if (Longitude > FLongWest) {
	   WebGMaps1->Polygons->Items[0]->Polygon->Bounds->NorthEast->Longitude = Longitude;
	   WebGMaps1->UpdateMapPolygon(WebGMaps1->Polygons->Items[0]->Polygon);
	   FLongEast = SimpleRoundTo(Longitude,-5);
	   cxLabel12->Caption = FloatToStr(FLongEast);
	   WebGMaps1->Markers->Items[0]->Longitude = (FLongWest + FLongEast)/2.0;
	   }
	 else
	   Beep();
	 }
   else if (cxButton4->Down) {   // south
	 if (Latitude < FLatNorth) {
	   WebGMaps1->Polygons->Items[0]->Polygon->Bounds->SouthWest->Latitude = Latitude;
	   WebGMaps1->UpdateMapPolygon(WebGMaps1->Polygons->Items[0]->Polygon);
	   FLatSouth = SimpleRoundTo(Latitude,-5);
	   cxLabel8->Caption = FloatToStr(FLatSouth);
	   WebGMaps1->Markers->Items[0]->Latitude = (FLatNorth + FLatSouth)/2.0;
	   }
	 else
	   Beep();
	 }
   else if (cxButton2->Down) {  // west
	 if (Longitude < FLongEast) {
	   WebGMaps1->Polygons->Items[0]->Polygon->Bounds->SouthWest->Longitude = Longitude;
	   WebGMaps1->UpdateMapPolygon(WebGMaps1->Polygons->Items[0]->Polygon);
	   FLongWest = SimpleRoundTo(Longitude,-5);
	   cxLabel10->Caption = FloatToStr(FLongWest);
	   WebGMaps1->Markers->Items[0]->Longitude = (FLongWest + FLongEast)/2.0;
	   }
	 else
	   Beep();
	 }

   WebGMaps1->GetElevation(Latitude,Longitude);
   int count = WebGMaps1->Elevations->Count;
   cxLabel14->Caption = FloatToStr(SimpleRoundTo(WebGMaps1->Elevations->Items[count-1]->Elevation,0));
}
//---------------------------------------------------------------------------

void __fastcall TGoogleMapForm::WebGMaps1MarkerDrag(TObject *Sender, UnicodeString MarkerTitle,
          int IdMarker, double Latitude, double Longitude)
{
   cxLabel6->Caption = FloatToStr(SimpleRoundTo(Latitude,-5));
   cxLabel8->Caption = FloatToStr(SimpleRoundTo(Longitude,-5));
}
//---------------------------------------------------------------------------

void __fastcall TGoogleMapForm::WebGMaps1MarkerDragEnd(TObject *Sender, UnicodeString MarkerTitle,
          int IdMarker, double Latitude, double Longitude)
{
   FLatNorth = SimpleRoundTo(Latitude,-5);
   FLatSouth = FLatNorth;
   FLongWest = SimpleRoundTo(Longitude,-5);
   FLongEast = FLongWest;
   cxLabel6->Caption = FloatToStr(FLatNorth);
   cxLabel8->Caption = FloatToStr(FLongWest);
}
//---------------------------------------------------------------------------

// point button
void __fastcall TGoogleMapForm::cxRadioButton1Click(TObject *Sender)
{
   if (activated && cxRadioButton1->Checked) {
	 WebGMaps1->Polygons->Items[0]->Polygon->Visible = false;
	 cxLabel5->Width = 56;
	 cxLabel5->Caption = L"Latitude:";
	 cxLabel7->Width = 56;
	 cxLabel7->Caption = L"Longitude:";
	 cxGroupBox1->Height = cxGroupBox1Height - 34;
	 cxLabel9->Visible = false;
	 cxLabel10->Visible = false;
	 cxLabel11->Visible = false;
	 cxLabel12->Visible = false;
	 FlowPanel3->Visible = false;
	 FLatSouth = FLatNorth;
	 FLongEast = FLongWest;
	 WebGMaps1->Markers->Items[0]->Latitude = FLatNorth;
	 WebGMaps1->Markers->Items[0]->Longitude = FLongWest;
	 WebGMaps1->Markers->Items[0]->Draggable = true;
	 WebGMaps1->MapOptions->Draggable = true;
	 WebGMaps1->UpdateMapPolygon(WebGMaps1->Polygons->Items[0]->Polygon);
	 }
}
//---------------------------------------------------------------------------

// box button
void __fastcall TGoogleMapForm::cxRadioButton2Click(TObject *Sender)
{
   if (activated && cxRadioButton2->Checked) {
	 cxLabel5->Width = 40;
	 cxLabel5->Caption = L"North:";
	 cxLabel7->Width = 40;
	 cxLabel7->Caption = L"South:";
	 cxGroupBox1->Height = cxGroupBox1Height;
	 cxLabel9->Visible = true;
	 cxLabel10->Visible = true;
	 cxLabel11->Visible = true;
	 cxLabel12->Visible = true;
	 cxButton1->Down = false;
	 cxButton2->Down = false;
	 cxButton3->Down = false;
	 cxButton4->Down = false;
	 cxButton5->OptionsImage->ImageIndex = -1;
	 FlowPanel3->Visible = true;
	 WebGMaps1->MapOptions->Draggable = true;
	 WebGMaps1->Markers->Items[0]->Draggable = false;
	 TMapPolygon* Box = WebGMaps1->Polygons->Items[0]->Polygon;
	 Box->Bounds->NorthEast->Latitude = FLatNorth + 0.001;
	 Box->Bounds->NorthEast->Longitude = FLongEast + 0.001;
	 Box->Bounds->SouthWest->Latitude = FLatSouth - 0.001;
	 Box->Bounds->SouthWest->Longitude = FLongWest - 0.001;
	 WebGMaps1->Polygons->Items[0]->Polygon->Visible = true;
	 WebGMaps1->UpdateMapPolygon(WebGMaps1->Polygons->Items[0]->Polygon);
	 }
}
//---------------------------------------------------------------------------

void __fastcall TGoogleMapForm::cxButton8Click(TObject *Sender)
{
   WebGMapsGeocoding1->Address = cxTextEdit1->Text;
   if (WebGMapsGeocoding1->LaunchGeocoding() == erOk) {
	 WebGMaps1->MapPanTo(WebGMapsGeocoding1->ResultLatitude, WebGMapsGeocoding1->ResultLongitude);
	 WebGMaps1->Markers->Items[0]->Latitude = WebGMapsGeocoding1->ResultLatitude;
	 WebGMaps1->Markers->Items[0]->Longitude = WebGMapsGeocoding1->ResultLongitude;
	 }
   else
	 MessageDlg(L"Location not found!", mtWarning, TMsgDlgButtons() << mbOK, 0);
}
//---------------------------------------------------------------------------


