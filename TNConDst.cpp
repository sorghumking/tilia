//---------------------------------------------------------------------------

#include <vcl.h>
#include "pch.h"
#pragma hdrstop

#include "TNConDst.h"
#ifndef TIJSONH
#include "TIJSON.h"
#endif
#include <map>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvCGrid"
#pragma link "AdvGrid"
#pragma link "AdvObj"
#pragma link "BaseGrid"
#pragma link "cxButtons"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "ipwjson"
#pragma link "AdvUtil"
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
#pragma link "ipsjsons"
#pragma resource "*.dfm"
TNeotomaContactDatasetsForm *NeotomaContactDatasetsForm;
//---------------------------------------------------------------------------
__fastcall TNeotomaContactDatasetsForm::TNeotomaContactDatasetsForm(int contact_id,
	UnicodeString contact_name, TStatusBar* status_bar, TComponent* Owner) : TForm(Owner)
{
   ContactID = contact_id;
   ContactName = contact_name;
   StatusBar = status_bar;
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaContactDatasetsForm::FormCreate(TObject *Sender)
{
   Screen->Cursor = crHourGlass;

   NeotomaContactDatasets Datasets(ipsJSONS1, TcpClient1);
   Datasets.AddParam(L"CONTACTID", ContactID);
   StatusBar->SimpleText = Datasets.WebServiceName();
   if (Datasets.Execute()) {
	 if (Datasets.Size() > 0) {
	   Panel1->Caption = ContactName;
	   AdvColumnGrid1->RowCount = Datasets.Size();
	   for (unsigned int i=0, row=1; i<Datasets.Size(); i++, row++) {
		 AdvColumnGrid1->Cells[0][row] = VarToStr(Datasets.Items[i].DatasetType);
		 AdvColumnGrid1->Cells[1][row] = VarToStr(Datasets.Items[i].SiteName);
		 UnicodeString GeoPolUnits;
		 if (!Datasets.Items[i].GeoPolName1.IsEmpty()) {
		   GeoPolUnits = VarToStr(Datasets.Items[i].GeoPolName1);
		   if (!Datasets.Items[i].GeoPolName2.IsEmpty()) {
			 GeoPolUnits += (L":" + VarToStr(Datasets.Items[i].GeoPolName2));
			 if (!Datasets.Items[i].GeoPolName3.IsEmpty())
			   GeoPolUnits += (L":" + VarToStr(Datasets.Items[i].GeoPolName3));
			 }
		   }
		 AdvColumnGrid1->Cells[2][row] = GeoPolUnits;
		 }
	   }
	 else
	   Panel1->Caption = L"No datasets for ContactID " + IntToStr(ContactID) +
		   L" (" + ContactName + L")";
	 }

   StatusBar->SimpleText = L"";
   Screen->Cursor = crDefault;
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaContactDatasetsForm::FormResize(TObject *Sender)
{
   cxButton1->Left = (Panel2->Width - cxButton1->Width)/2;
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaContactDatasetsForm::ipsJSONS1SSLServerAuthentication(TObject *Sender,
          TipsJSONSSSLServerAuthenticationEventParams *e)
{
   e->Accept = true;
}
//---------------------------------------------------------------------------

