//---------------------------------------------------------------------------

#include <vcl.h>
#include "pch.h"
#pragma hdrstop

#include "TIQuery.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxImage"
#pragma link "cxLabel"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxButtons"
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
TQueryForm *QueryForm;
TC14orCalQuery *C14orCalQuery;

//---------------------------------------------------------------------------
__fastcall TQueryForm::TQueryForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TQueryForm::cxButton1Click(TObject *Sender)
{
   return;
}
//---------------------------------------------------------------------------

void __fastcall TQueryForm::cxButton2Click(TObject *Sender)
{
   return;
}
//---------------------------------------------------------------------------

void __fastcall TQueryForm::cxButton3Click(TObject *Sender)
{
   return;
}
//---------------------------------------------------------------------------

void __fastcall TQueryForm::cxButton4Click(TObject *Sender)
{
   return;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

__fastcall TAddAppendTaxaGroupQuery::TAddAppendTaxaGroupQuery(TComponent* Owner)
	: TQueryForm(Owner)
{
   cxLabel1->Caption = L"Replace or add to current taxonomic tree?";
   cxButton1->Caption = L"&Replace";
   cxButton2->Caption = L"&Add";
   cxButton3->Caption = L"&Cancel";
   cxButton4->Visible = false;
   FlowPanel1->Width = 3*cxButton1->Width;
   FlowPanel1->Left = (Width - FlowPanel1->Width)/2;
}
//----------------------- ----------------------------------------------------

void __fastcall TAddAppendTaxaGroupQuery::cxButton1Click(TObject *Sender)
{
   ModalResult = mrReplace;
}
//---------------------------------------------------------------------------

void __fastcall TAddAppendTaxaGroupQuery::cxButton2Click(TObject *Sender)
{
   ModalResult = mrAdd;
}
//---------------------------------------------------------------------------

void __fastcall TAddAppendTaxaGroupQuery::cxButton3Click(TObject *Sender)
{
   ModalResult = mrCancel;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

__fastcall TC14orCalQuery::TC14orCalQuery(UnicodeString age_basis, TComponent* Owner)
	: TQueryForm(Owner)
{
   FAgeUnits = -1;
   UnicodeString msg = L"Age Basis «" + age_basis;
   msg += L"» has both radiocarbon and calendar year assignments. ";
   msg += L"Click the button for the age units you want to use.";
   cxLabel1->Caption = msg;
   cxButton1->Caption = L"&Radiocarbon";
   cxButton2->Caption = L"&Calendar";
   cxButton3->Caption = L"&Cancel";
   cxButton3->OptionsImage->ImageIndex = 2;
   cxButton4->Visible = false;
   FlowPanel1->Width = 3*cxButton1->Width;
   FlowPanel1->Left = (Width - FlowPanel1->Width)/2;
}
//----------------------- ----------------------------------------------------

void __fastcall TC14orCalQuery::cxButton1Click(TObject *Sender)
{
   FAgeUnits = auRadiocarbon;
   ModalResult = mrOk;
}
//---------------------------------------------------------------------------

void __fastcall TC14orCalQuery::cxButton2Click(TObject *Sender)
{
   FAgeUnits = auCalendar;
   ModalResult = mrOk;
}
//---------------------------------------------------------------------------

void __fastcall TC14orCalQuery::cxButton3Click(TObject *Sender)
{
   ModalResult = mrCancel;
}
//---------------------------------------------------------------------------

