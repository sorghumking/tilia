//---------------------------------------------------------------------------

#include <vcl.h>
#include "pch.h"
#include <set>
#pragma hdrstop

#include "TIsoDat.h"
#ifndef TIsotopeH
#include "TIsotope.h"
#endif
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxBlobEdit"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDropDownEdit"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxLabel"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxMaskEdit"
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
#pragma link "AdvCGrid"
#pragma link "AdvGrid"
#pragma link "AdvObj"
#pragma link "AdvUtil"
#pragma link "BaseGrid"
#pragma link "cxButtons"
#pragma link "HTMLDialog"
#pragma resource "*.dfm"
TIsoDatasetMetadataForm *IsoDatasetMetadataForm;
//---------------------------------------------------------------------------
__fastcall TIsoDatasetMetadataForm::TIsoDatasetMetadataForm(TPoint& pos, short isotope, TComponent* Owner)
	: TForm(Owner)
{
   TSSForm = (TTilSpreadSheetForm*)Owner;
   Position = pos;
   Isotope = isotope;
   activated = false;
   standards_set = false;
   UnicodeString Header;

   if (Isotope != isoStrontium) {
	 Panel5->Visible = false;
	 GridPanel4->Visible = false;
	 }

   switch (Isotope) {
	 case isoNitrogen:
	   AdvStandardsGrid->Columns->Items[2]->Header =
		 L"<P align=\"center\"><FONT size=\"8\" face=\"Tahoma\">δ</FONT><FONT size=\"6\" \
		 face=\"Tahoma\"><SUP>15</SUP></FONT><FONT size=\"8\" face=\"Tahoma\">N (‰)</FONT></P>";
	   break;
	 case isoOxygen:
	   AdvStandardsGrid->Columns->Items[2]->Header =
		 L"<P align=\"center\"><FONT size=\"8\" face=\"Tahoma\">δ</FONT><FONT size=\"6\" \
		 face=\"Tahoma\"><SUP>18</SUP></FONT><FONT size=\"8\" face=\"Tahoma\">O (‰)</FONT></P>";
	   break;
	 case isoSulfur:
	   AdvStandardsGrid->Columns->Items[2]->Header =
		 L"<P align=\"center\"><FONT size=\"8\" face=\"Tahoma\">δ</FONT><FONT size=\"6\" \
		 face=\"Tahoma\"><SUP>34</SUP></FONT><FONT size=\"8\" face=\"Tahoma\">S (‰)</FONT></P>";
	   break;
	 case isoHydrogen:
	   AdvStandardsGrid->Columns->Items[2]->Header =
		 L"<P align=\"center\"><FONT size=\"8\" face=\"Tahoma\">δD (‰)</FONT></P>";
	   break;
	 case isoStrontium:
	   Header = L"<P align=\"center\"><FONT size=\"6\" face=\"Tahoma\"><SUP>87</SUP></FONT>";
	   Header += L"<FONT size=\"8\" face=\"Tahoma\">Sr/</FONT><FONT size=\"6\" face=\"Tahoma\">";
	   Header += L"<SUP>86</SUP></FONT><FONT size=\"8\" face=\"Tahoma\">Sr</FONT></P>";
	   AdvStandardsGrid->Columns->Items[2]->Header = Header;
	   break;
	 }

   Height -= (Panel5->Height + GridPanel4->Height);

   set<UnicodeString>::iterator itr;
   set<UnicodeString>::iterator begin = TSSForm->IsoInstrumentation.begin();
   set<UnicodeString>::iterator end = TSSForm->IsoInstrumentation.end();
   for (itr = begin; itr != end; itr++)
	 cxComboBox1->Properties->Items->Add(*itr);

   begin = TSSForm->IsoSampleIntroSystems.begin();
   end = TSSForm->IsoSampleIntroSystems.end();
   for (itr = begin; itr != end; itr++)
	 cxComboBox2->Properties->Items->Add(*itr);

   map<short,ISOMETADATA>::iterator mit = TSSForm->IsoMetadata.find(Isotope);
   if (mit != TSSForm->IsoMetadata.end()) {
	 if (!mit->second.TechError.IsEmpty())
	   cxTextEdit1->Text = mit->second.TechError;
	 if (!mit->second.TechErrorSD.IsEmpty())
	   cxTextEdit2->Text = mit->second.TechErrorSD;
	 if (!mit->second.LongTermError.IsEmpty())
	   cxTextEdit3->Text = mit->second.LongTermError;
	 cxComboBox1->Text = mit->second.Instrument;
	 cxComboBox2->Text = mit->second.IntroSystem;
	 if (mit->second.Standards.size() > 0) {
	   AdvStandardsGrid->RowCount = mit->second.Standards.size() + 1;
	   for (unsigned int i=0, row=1; i<mit->second.Standards.size(); i++, row++) {
		 AdvStandardsGrid->Cells[1][row] = mit->second.Standards[i].first;
		 if (!mit->second.Standards[i].second.IsEmpty())
		   AdvStandardsGrid->Cells[2][row] = mit->second.Standards[i].second;
		 }
	   }
	 if (Isotope == isoStrontium) {
	   cxTextEdit4->Text = mit->second.SrLocalValue;
	   cxTextEdit5->Text = mit->second.SrLocalValueSD;
	   cxBlobEdit2->Text = mit->second.SrLocalGeolContext;
	   }
	 cxBlobEdit3->Text = mit->second.Notes;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TIsoDatasetMetadataForm::FormActivate(TObject *Sender)
{
   if (! activated) {
	 Left = Position.X;
	 Top = Position.Y;
	 activated = true;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TIsoDatasetMetadataForm::AdvStandardsGridGetDisplText(TObject *Sender,
		  int ACol, int ARow, UnicodeString &Value)
{
   if (ACol == 0 && ARow > 0)
	 Value = IntToStr(ARow);
}
//---------------------------------------------------------------------------

void __fastcall TIsoDatasetMetadataForm::AdvStandardsGridGetEditorProp(TObject *Sender,
		  int ACol, int ARow, TEditLink *AEditLink)
{
   Advmulticolumndropdown::TDropDownColumn* dc;
   Advmulticolumndropdown::TDropDownItem* di;

   if (!standards_set && ACol == 1) {
	 dc = AdvStandardsGrid->GridDropDown->Columns->Add();
	 dc->Header = L"Standard";
	 dc->Width = 64;
	 dc = AdvStandardsGrid->GridDropDown->Columns->Add();
	 dc->Header = L"Material";
	 dc->Width  = 150;

	 map<UnicodeString,UnicodeString>::iterator itr;
	 map<UnicodeString,UnicodeString>::iterator begin = TSSForm->IsoStandards.begin();
	 map<UnicodeString,UnicodeString>::iterator end = TSSForm->IsoStandards.end();

	 for (itr = begin; itr != end; itr++) {
	   di = AdvStandardsGrid->GridDropDown->Items->Add();
	   di->Text->Add(itr->first);
	   di->Text->Add(itr->second);
	   }

	 AdvStandardsGrid->GridDropDown->LookupColumn = 0;
	 AdvStandardsGrid->GridDropDown->DropDownRowHeight = 20;
	 AdvStandardsGrid->GridDropDown->DropDownAutoWidth = true;
	 AdvStandardsGrid->GridDropDown->ColumnSizing = true;
	 standards_set = true;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TIsoDatasetMetadataForm::cxTextEdit1PropertiesValidate(TObject *Sender,
		  Variant &DisplayValue, TCaption &ErrorText, bool &Error)
{
   UnicodeString Value = DisplayValue;
   double dVal;
   if (!Value.IsEmpty()) {
	 if (!TryStrToFloat(Value,dVal)) {
	   ErrorText = L"Technical Error not a valid number!";
	   Error = true;
	   }
	 }
}
//---------------------------------------------------------------------------

void __fastcall TIsoDatasetMetadataForm::cxTextEdit2PropertiesValidate(TObject *Sender,
		  Variant &DisplayValue, TCaption &ErrorText, bool &Error)
{
   UnicodeString Value = DisplayValue;
   double dVal;
   if (!Value.IsEmpty()) {
	 if (!TryStrToFloat(Value,dVal)) {
	   ErrorText = L"SD of Material in Run not a valid number!";
	   Error = true;
	   }
	 }
}
//---------------------------------------------------------------------------

void __fastcall TIsoDatasetMetadataForm::cxTextEdit3PropertiesValidate(TObject *Sender,
		  Variant &DisplayValue, TCaption &ErrorText, bool &Error)
{
   UnicodeString Value = DisplayValue;
   double dVal;
   if (!Value.IsEmpty()) {
	 if (!TryStrToFloat(Value,dVal)) {
	   ErrorText = L"Long Term Lab Error not a valid number!";
	   Error = true;
	   }
	 }
}
//---------------------------------------------------------------------------

void __fastcall TIsoDatasetMetadataForm::cxTextEdit4PropertiesValidate(TObject *Sender,
		  Variant &DisplayValue, TCaption &ErrorText, bool &Error)
{
   UnicodeString Value = DisplayValue;
   double dVal;
   if (!Value.IsEmpty()) {
	 if (!TryStrToFloat(Value,dVal)) {
	   ErrorText = L"Sr local value not a valid number!";
	   Error = true;
	   }
	 }
}
//---------------------------------------------------------------------------

void __fastcall TIsoDatasetMetadataForm::cxTextEdit5PropertiesValidate(TObject *Sender,
		  Variant &DisplayValue, TCaption &ErrorText, bool &Error)
{
   UnicodeString Value = DisplayValue;
   double dVal;
   if (!Value.IsEmpty()) {
	 if (!TryStrToFloat(Value,dVal)) {
	   ErrorText = L"Sr local value SD not a valid number!";
	   Error = true;
	   }
	 }
}
//---------------------------------------------------------------------------

void __fastcall TIsoDatasetMetadataForm::AdvStandardsGridCellValidate(TObject *Sender,
		  int ACol, int ARow, UnicodeString &Value, bool &Valid)
{
   if (ACol == 2) {
	 double dVal;
	 if (!Value.IsEmpty()) {
	   if (!TryStrToFloat(Value,dVal)) {
		 UnicodeString ErrorText;
		 switch (Isotope) {
		   case isoCarbon:
			 ErrorText = L"δ13C value is not valid number!";
			 break;
		   case isoNitrogen:
			 ErrorText = L"δ15N value is not valid number!";
			 break;
		   case isoOxygen:
			 ErrorText = L"δ18O value is not valid number!";
			 break;
		   case isoSulfur:
			 ErrorText = L"δ34S value is not valid number!";
			 break;
		   }
		 MessageDlg(ErrorText, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 Valid = false;
		 }
	   }
	 }
}
//---------------------------------------------------------------------------

void __fastcall TIsoDatasetMetadataForm::AdvStandardsGridClipboardPasteDone(TObject *Sender,
          TGridRect &CellRect)
{
   double dVal;
   UnicodeString ErrorText;
   map<UnicodeString,UnicodeString>::iterator end = TSSForm->IsoStandards.end();

   for (int row = CellRect.Top; row < CellRect.Bottom; row++) {
	 if (TSSForm->IsoStandards.find(AdvStandardsGrid->Cells[1][row]) == end) {
	   ErrorText = L"Standard pasted into row " + IntToStr(row) + L" is not valid.";
	   MessageDlg(ErrorText, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   AdvStandardsGrid->Cells[1][row] = L"";
	   }
	 if (!TryStrToFloat(AdvStandardsGrid->Cells[2][row],dVal)) {
	   switch (Isotope) {
		 case isoCarbon:
		   ErrorText = L"δ13C";
		   break;
		 case isoNitrogen:
		   ErrorText = L"δ15N";
		   break;
		 case isoOxygen:
		   ErrorText = L"δ18O";
		   break;
		 case isoSulfur:
		   ErrorText = L"δ34S";
		   break;
		 }
	   ErrorText += (L" value pasted into row " + IntToStr(row) + L" is not valid number.");
	   MessageDlg(ErrorText, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   AdvStandardsGrid->Cells[2][row] = L"";
	   }
	 }
}
//---------------------------------------------------------------------------

// Ok button
void __fastcall TIsoDatasetMetadataForm::cxButton1Click(TObject *Sender)
{
   // store metadata in IsoMetadata map
   double dVal;

   ISOMETADATA Metadata;
   if (TryStrToFloat(cxTextEdit1->Text,dVal))
	 Metadata.TechError = dVal;
   if (TryStrToFloat(cxTextEdit2->Text,dVal))
	 Metadata.TechErrorSD = dVal;
   if (TryStrToFloat(cxTextEdit3->Text,dVal))
	 Metadata.LongTermError = dVal;
   Metadata.Instrument = cxComboBox1->Text;
   Metadata.IntroSystem = cxComboBox2->Text;
   for (int row = 1; row < AdvStandardsGrid->RowCount; row++) {
	 Variant Value;
	 if (!AdvStandardsGrid->Cells[2][row].IsEmpty()) {
	   if (TryStrToFloat(AdvStandardsGrid->Cells[2][row],dVal))
		 Value = dVal;
	   }
	 if (!AdvStandardsGrid->Cells[1][row].IsEmpty() && !Value.IsEmpty())
	   Metadata.Standards.push_back(pair<UnicodeString,Variant>(AdvStandardsGrid->Cells[1][row],Value));
	 }
   if (Isotope == isoStrontium) {
	 Metadata.SrLocalValue = (cxTextEdit4->Text.IsEmpty()) ? Unassigned() : cxTextEdit4->Text.ToDouble();
	 Metadata.SrLocalValueSD = (cxTextEdit5->Text.IsEmpty()) ? Unassigned() : cxTextEdit5->Text.ToDouble();
	 Metadata.SrLocalGeolContext = cxBlobEdit2->Text;
	 }
   Metadata.Notes = cxBlobEdit3->Text;
   TSSForm->IsoMetadata[Isotope] = Metadata;
}
//---------------------------------------------------------------------------

void __fastcall TIsoDatasetMetadataForm::GridPanel1Resize(TObject *Sender)
{
   GridPanel1->ColumnCollection->Items[1]->Value = GridPanel1->Width - 150;
}
//---------------------------------------------------------------------------

void __fastcall TIsoDatasetMetadataForm::GridPanel2Resize(TObject *Sender)
{
   GridPanel2->ColumnCollection->Items[1]->Value = GridPanel1->Width - 150;
}
//---------------------------------------------------------------------------

