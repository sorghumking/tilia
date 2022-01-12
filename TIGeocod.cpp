//---------------------------------------------------------------------------

#include <vcl.h>
#include "pch.h"
#pragma hdrstop

#include "TIGeocod.h"
#include <vector>
#include <set>
#include <algorithm>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvCGrid"
#pragma link "AdvGrid"
#pragma link "AdvObj"
#pragma link "AdvUtil"
#pragma link "BaseGrid"
#pragma link "cxButtons"
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
#pragma link "dxSkinOffice2016Colorful"
#pragma link "dxSkinOffice2016Dark"
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
#pragma link "dxSkinVisualStudio2013Blue"
#pragma link "dxSkinVisualStudio2013Dark"
#pragma link "dxSkinVisualStudio2013Light"
#pragma link "dxSkinVS2010"
#pragma link "dxSkinWhiteprint"
#pragma link "dxSkinXmas2008Blue"
#pragma resource "*.dfm"
TGoogleGeocodesForm *GoogleGeocodesForm;
//---------------------------------------------------------------------------
__fastcall TGoogleGeocodesForm::TGoogleGeocodesForm(double latitude, double longitude,
	map<UnicodeString,UnicodeString>& PoliticalUnits, TComponent* Owner)
	: TForm(Owner)
{
   map<UnicodeString,UnicodeString> Types;
   vector<UnicodeString> Names;

   cxLabel1->Caption = L"Google Maps Reverse Geocoding for latitude " +
	 FloatToStr(latitude) + L", longitude " + FloatToStr(longitude);
   AdvColumnGrid1->RowCount = Max(PoliticalUnits.size() + 1, 2);

   map<UnicodeString,UnicodeString>::iterator itr;
   // get empty types
   for (itr = PoliticalUnits.begin(); itr != PoliticalUnits.end(); itr++) {
	 if(itr->second.IsEmpty())
	   Names.push_back(itr->first);
	 }
   // get country
   for (itr = PoliticalUnits.begin(); itr != PoliticalUnits.end(); itr++) {
	 if(SameText(itr->second, L"country"))
	   Types[itr->first] = itr->second;
	 }
   for (map<UnicodeString,UnicodeString>::iterator it = Types.begin(); it != Types.end(); it++)
	 Names.push_back(it->first);
   // get administrative units
   Types.clear();
   for (itr = PoliticalUnits.begin(); itr != PoliticalUnits.end(); itr++) {
	 if(ContainsText(itr->second, L"administrative_area_level"))
	   Types[itr->second] = itr->first;
	 }
   for (map<UnicodeString,UnicodeString>::iterator it = Types.begin(); it != Types.end(); it++)
	 Names.push_back(it->second);
   // get everything else
   Types.clear();
   for (itr = PoliticalUnits.begin(); itr != PoliticalUnits.end(); itr++) {
	 if (count(Names.begin(), Names.end(), itr->first) == 0)
	   Types[itr->second] = itr->first;
	 }
   for (map<UnicodeString,UnicodeString>::iterator it = Types.begin(); it != Types.end(); it++)
	 Names.push_back(it->second);

   for (unsigned int i=0, row=1; i<Names.size(); i++, row++) {
	 AdvColumnGrid1->Cells[0][row] = Names[i];
	 AdvColumnGrid1->Cells[1][row] = PoliticalUnits[Names[i]];
	 }
}
//---------------------------------------------------------------------------

void __fastcall TGoogleGeocodesForm::AdvColumnGrid1CellValidate(TObject *Sender, int ACol,
          int ARow, UnicodeString &Value, bool &Valid)
{
   Valid = false;
}
//---------------------------------------------------------------------------

