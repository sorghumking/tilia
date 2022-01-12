//---------------------------------------------------------------------------

#include <vcl.h>
#include "pch.h"
#pragma hdrstop

#include "TNtmPubs.h"
#ifndef TIJSONH
#include "TIJSON.h"
#endif
#include <map>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvGrid"
#pragma link "AdvObj"
#pragma link "BaseGrid"
#pragma link "cxButtons"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "ipwjson"
#pragma link "AdvCGrid"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxMemo"
#pragma link "cxTextEdit"
#pragma link "frmctrllink"
#pragma link "AdvControlDropDown"
#pragma link "AdvDropDown"
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
TNeotomaContactPubForm *NeotomaContactPubForm;
//---------------------------------------------------------------------------
__fastcall TNeotomaContactPubForm::TNeotomaContactPubForm(int contact_id,
	UnicodeString contact_name, TStatusBar* status_bar, TComponent* Owner) : TForm(Owner)
{
   ContactID = contact_id;
   ContactName = contact_name;
   StatusBar = status_bar;
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaContactPubForm::FormCreate(TObject *Sender)
{
   Screen->Cursor = crHourGlass;
   NeotomaPublicationsByContactID Publications(ipsJSONS1, TcpClient1);
   Publications.AddParam(L"CONTACTID", ContactID);
   StatusBar->SimpleText = Publications.WebServiceName();
   if (Publications.Execute()) {
	 if (Publications.Size() > 0) {
	   Panel1->Caption = ContactName;
	   AdvColumnGrid1->RowCount = Publications.Size();
	   for (unsigned int i=0; i<Publications.Size(); i++)
		 AdvColumnGrid1->Cells[0][i] = Publications.Items[i].Citation;
	   }
	 else
	   Panel1->Caption = L"No publications for ContactID " + IntToStr(ContactID) +
		   L" (" + ContactName + L")";
	 }

   StatusBar->SimpleText = L"";
   Screen->Cursor = crDefault;
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaContactPubForm::FormResize(TObject *Sender)
{
   cxButton1->Left = (Panel2->Width - cxButton1->Width)/2;
}
//---------------------------------------------------------------------------

// sets the value in the editor for the dropdown
void __fastcall TNeotomaContactPubForm::FormControlEditLink1SetEditorValue(TObject *Sender,
          TAdvStringGrid *Grid, UnicodeString AValue)
{
   Citation = AValue;
   AdvControlDropDown1->Text = AValue;
}
//---------------------------------------------------------------------------

// gets value from the dropdown editor after dropping up
void __fastcall TNeotomaContactPubForm::FormControlEditLink1GetEditorValue(TObject *Sender,
		  TAdvStringGrid *Grid, UnicodeString &AValue)
{
   AValue = Citation;
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaContactPubForm::AdvColumnGrid1GetEditorProp(TObject *Sender,
          int ACol, int ARow, TEditLink *AEditLink)
{
   cxMemo1->Text = AdvColumnGrid1->Cells[ACol][ARow];
   if (AdvControlDropDown1->DropDownWidth == 0)
	 AdvControlDropDown1->DropDownWidth = AdvColumnGrid1->Columns->Items[0]->Width - 6;
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaContactPubForm::ipsJSONS1SSLServerAuthentication(TObject *Sender,
          TipsJSONSSSLServerAuthenticationEventParams *e)
{
   e->Accept = true;
}
//---------------------------------------------------------------------------

