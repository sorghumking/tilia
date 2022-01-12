//---------------------------------------------------------------------------

#include <vcl.h>
#include "pch.h"
#pragma hdrstop

#include "TNDatTyp.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxLabel"
#pragma link "cxListBox"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxButtons"
#pragma link "cxButtons"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxLabel"
#pragma link "cxListBox"
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
#pragma resource "*.dfm"
TReassignDatasetTypeForm *ReassignDatasetTypeForm;
//---------------------------------------------------------------------------
__fastcall TReassignDatasetTypeForm::TReassignDatasetTypeForm(UnicodeString TaxaGroup,
	UnicodeString DatasetType, vector<UnicodeString>& TaxaNames,
	map<int,UnicodeString>& DatasetTypes, TComponent* Owner) : TForm(Owner)
{
   UnicodeString Caption = cxLabel1->Caption;
   int pos = Caption.Pos(L"«»");
   Caption.Insert(TaxaGroup, pos+1);
   pos = Caption.Pos(L"«»");
   Caption.Insert(DatasetType, pos+1);
   cxLabel1->Caption = Caption;
   cxLabel2->Caption = L"Taxa in Taxa Group «" + TaxaGroup + L"»";

   for (unsigned int i=0; i<TaxaNames.size(); i++)
	 cxListBox1->Items->Add(TaxaNames[i]);
   map<int,UnicodeString>::iterator itr;
   for (itr = DatasetTypes.begin(); itr != DatasetTypes.end(); itr++) {
	 cxListBox2->Items->Add(itr->second);
	 DatasetTypeIDs[itr->second] = itr->first;
	 }
   cxListBox2->ItemIndex = 0;
}
//---------------------------------------------------------------------------

int TReassignDatasetTypeForm::GetDatasetTypeID(void)
{
   if (cxListBox2->ItemIndex == -1)
	 return -1;
   else {
	 UnicodeString DatasetType = cxListBox2->Items->Strings[cxListBox2->ItemIndex];
	 return DatasetTypeIDs[DatasetType];
	 }
}
//---------------------------------------------------------------------------

