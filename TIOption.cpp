//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TIOption.h"
#ifndef TIGlobalsH
#include "TIGlobals.h"
#endif
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDropDownEdit"
#pragma link "cxEdit"
#pragma link "cxFontNameComboBox"
#pragma link "cxGraphics"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "cxSpinEdit"
#pragma link "cxLabel"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxButtons"
#pragma link "cxShellComboBox"
#pragma link "cxShellCommon"
#pragma link "cxRadioGroup"
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


TSSOptionsForm *SSOptionsForm;
//---------------------------------------------------------------------------
__fastcall TSSOptionsForm::TSSOptionsForm(TComponent* Owner)
		: TForm(Owner)
{
   TSSForm = (TTilSpreadSheetForm*)Owner;
   cxFontNameComboBox1->Text = tiGlobals->SSFontName;
   cxSpinEdit4->Text = tiGlobals->SSFontSize;
   cxSpinEdit5->Text = tiGlobals->UndoLimit;
   cxSpinEdit3->Text = IntToStr(TSSForm->ProfGrid1->DefaultRowHeight);
   cxSpinEdit2->Text = IntToStr(TSSForm->ProfGrid1->DefaultColWidth);
   cxSpinEdit8->Value = tiGlobals->InternetTimeout;

   OldPercentDecimalPlaces = tiGlobals->PercentDecimalPlaces;
   cxSpinEdit1->Value = OldPercentDecimalPlaces;
   OldConcDecimalPlaces = tiGlobals->ConcDecimalPlaces;
   cxSpinEdit6->Value = OldConcDecimalPlaces;
   OldInfluxDecimalPlaces = tiGlobals->InfluxDecimalPlaces;
   cxSpinEdit7->Value = OldInfluxDecimalPlaces;
   CheckBox1->Checked = TSSForm->ProfGrid1->AbsoluteCols[1]->Visible;
   CheckBox2->Checked = TSSForm->ProfGrid1->AbsoluteCols[3]->Visible;
   CheckBox3->Checked = TSSForm->ProfGrid1->AbsoluteCols[4]->Visible;
   CheckBox4->Checked = TSSForm->ProfGrid1->AbsoluteCols[5]->Visible;
   CheckBox5->Checked = TSSForm->ProfGrid1->AbsoluteCols[6]->Visible;
   CheckBox6->Checked = TSSForm->ProfGrid1->AbsoluteCols[7]->Visible;
   CheckBox7->Checked = tiGlobals->CodeOptionDups;
   CheckBox8->Checked = tiGlobals->CodeOptionCase;
   CheckBox9->Checked = tiGlobals->AddSynonyms;
   CheckBox10->Checked = tiGlobals->UseGoogleMaps;
   RadioGroup1->ItemIndex = TSSForm->HeaderRow2;

   cxShellComboBox1->AbsolutePath = tiGlobals->MyLookupPath;
   OldLookupPath = cxShellComboBox1->AbsolutePath;

   UnicodeString LookupPath;
   WCHAR szPath[MAX_PATH];
   if (SHGetFolderPathW(NULL, CSIDL_COMMON_APPDATA|CSIDL_FLAG_CREATE, NULL, 0, szPath) == S_OK) {
	 LookupPath = szPath;
	 LookupPath += L"\\Tilia\\Lookup\\";
	 }

   if (SameText(tiGlobals->MyLookupPath, LookupPath) || tiGlobals->MyLookupPath.IsEmpty())
	 cxRadioButton1->Checked = true;
   else
	 cxRadioButton2->Checked = true;

   cxTextEdit1->Text = tiGlobals->NeotomaEndpoint;
   cxTextEdit2->Text = tiGlobals->OxCalEndpoint;
}
//---------------------------------------------------------------------------

// Ok button
void __fastcall TSSOptionsForm::cxButton1Click(TObject *Sender)
{
   if (cxRadioButton1->Checked) {
	 tiGlobals->MyLookupPath = L"";
	 }
   else if (cxRadioButton2->Checked) {
	 UnicodeString NewLookupPath = cxShellComboBox1->AbsolutePath;
	 if (NewLookupPath.IsEmpty()) {
	   MessageDlg("Invalid lookup file path. Former path restored.", Dialogs::mtError,
				  TMsgDlgButtons() << mbOK, 0);
	   cxShellComboBox1->AbsolutePath = OldLookupPath;
	   ModalResult = mrNone;
	   return;
	   }
	 else {
	   if (*NewLookupPath.LastChar() != L'\\')
		 NewLookupPath += L"\\";
	   tiGlobals->MyLookupPath = NewLookupPath;
	   }
	 }

   PercentDecimalPlaces = cxSpinEdit1->Value;
   ConcDecimalPlaces = cxSpinEdit6->Value;
   InfluxDecimalPlaces = cxSpinEdit7->Value;

   tiGlobals->SSHideCodes = CheckBox1->Checked;
   tiGlobals->SSHideElements = CheckBox2->Checked;
   tiGlobals->SSHideUnits = CheckBox3->Checked;
   tiGlobals->SSHideContext = CheckBox4->Checked;
   tiGlobals->SSHideTaphonomy = CheckBox5->Checked;
   tiGlobals->SSHideGroups = CheckBox6->Checked;
   tiGlobals->CodeOptionDups = CheckBox7->Checked;
   tiGlobals->CodeOptionCase = CheckBox8->Checked;
   tiGlobals->AddSynonyms = CheckBox9->Checked;
   tiGlobals->SSFontSize = cxSpinEdit4->Value;
   tiGlobals->SSFontName = cxFontNameComboBox1->Text;
   tiGlobals->SSDefaultColWidth = cxSpinEdit2->Value;
   tiGlobals->SSDefaultRowHeight = cxSpinEdit3->Value;
   tiGlobals->UndoLimit = cxSpinEdit5->Value;
   tiGlobals->InternetTimeout = cxSpinEdit8->Value;
   tiGlobals->UseGoogleMaps = CheckBox10->Checked;
   TSSForm->HeaderRow2 = RadioGroup1->ItemIndex;
   TSSForm->cxButton27->Visible = CheckBox10->Checked;
   TSSForm->cxButton33->Visible = CheckBox10->Checked;

   if (PercentDecimalPlaces != OldPercentDecimalPlaces)
	 tiGlobals->PercentDecimalPlaces = PercentDecimalPlaces;
   else
	 PercentDecimalPlaces = -1;

   if (ConcDecimalPlaces != OldConcDecimalPlaces)
	 tiGlobals->ConcDecimalPlaces = ConcDecimalPlaces;
   else
	 ConcDecimalPlaces = -1;

   if (InfluxDecimalPlaces != OldInfluxDecimalPlaces)
	 tiGlobals->InfluxDecimalPlaces = InfluxDecimalPlaces;
   else
	 InfluxDecimalPlaces = -1;

   tiGlobals->NeotomaEndpoint = cxTextEdit1->Text;
   tiGlobals->OxCalEndpoint = cxTextEdit2->Text;
}
//---------------------------------------------------------------------------

void __fastcall TSSOptionsForm::cxRadioButton1Click(TObject *Sender)
{
   if (cxRadioButton1->Checked)
	 cxShellComboBox1->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TSSOptionsForm::cxRadioButton2Click(TObject *Sender)
{
   if (cxRadioButton2->Checked)
	 cxShellComboBox1->Enabled = true;
}
//---------------------------------------------------------------------------

