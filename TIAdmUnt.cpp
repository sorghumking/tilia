//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TIAdmUnt.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxCheckComboBox"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDropDownEdit"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxButtons"
#pragma link "cxCheckBox"
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

TNewAdminUnit *NewAdminUnit;
//---------------------------------------------------------------------------
__fastcall TNewAdminUnit::TNewAdminUnit(TComponent* Owner)
        : TForm(Owner)
{
   TSSForm = (TTilSpreadSheetForm*)Owner;
}
//---------------------------------------------------------------------------

void __fastcall TNewAdminUnit::FormCreate(TObject *Sender)
{
   Activated = false;
   SaveFile = false;
   ComboBox1->Items->AddStrings(TSSForm->AdminUnitTypes);
}
//---------------------------------------------------------------------------

void __fastcall TNewAdminUnit::FormActivate(TObject *Sender)
{
   InitialStateItemIndex = cxCheckComboBox1->ItemIndex;
   Activated = true;
}
//---------------------------------------------------------------------------

void __fastcall TNewAdminUnit::cxCheckComboBox2PropertiesClickCheck(
      TObject *Sender, int ItemIndex, bool &AllowToggle)
{
   if (Activated) {
     for (int i=0; i<cxCheckComboBox1->Properties->Items->Count; i++)
       cxCheckComboBox1->States[i] = (i == InitialStateItemIndex) ? cbsChecked : cbsUnchecked;
     }
}
//---------------------------------------------------------------------------

void __fastcall TNewAdminUnit::RadioButton3Click(TObject *Sender)
{
   for (int i=0; i<cxCheckComboBox1->Properties->Items->Count; i++)
     cxCheckComboBox1->States[i] = (i == InitialStateItemIndex) ? cbsChecked : cbsUnchecked;
   cxCheckComboBox1->Properties->ReadOnly = true;
}
//---------------------------------------------------------------------------

void __fastcall TNewAdminUnit::RadioButton2Click(TObject *Sender)
{
   cxCheckComboBox1->Properties->ReadOnly = false;
}
//---------------------------------------------------------------------------

// Ok button
void __fastcall TNewAdminUnit::cxButton1Click(TObject *Sender)
{
   ModalResult = ValidateSelections();
   if (ModalResult == mrOk) {
	 ComboBox1->Text = LowerCase(ComboBox1->Text);
	 if (MessageDlg("Save to GeoPoliticalUnits lookup file?", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes)
	   SaveFile = true;
	 }
}
//---------------------------------------------------------------------------

// Upload button
void __fastcall TNewAdminUnit::cxButton3Click(TObject *Sender)
{
   ModalResult = ValidateSelections();
   if (ModalResult == mrOk)
	 ComboBox1->Text = LowerCase(ComboBox1->Text);
}
//---------------------------------------------------------------------------

int TNewAdminUnit::ValidateSelections(void)
{
   UnicodeString msg;
   int rv;

   if (ComboBox1->Text.IsEmpty())
	 msg = "Type of administrative unit not selected.";
   else if (!RadioButton1->Checked && !RadioButton2->Checked && !RadioButton3->Checked)
	 msg = "No geopolitical division selected.";
   else if ((RadioButton2->Checked && cxCheckComboBox1->Text.IsEmpty()) ||
			(RadioButton3->Checked && cxCheckComboBox2->Text.IsEmpty()))
	 msg = "No geopolitical unit selected for checked divison.";

   if (!msg.IsEmpty()) {
	 rv = MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbRetry << mbAbort, 0);
	 return ((rv == mrRetry || rv == mrCancel) ? mrNone : mrCancel);
	 }
   else
	 return mrOk;
}
//---------------------------------------------------------------------------

void TNewAdminUnit::SetGeoPol2Units(map<UnicodeString, UnicodeString>& ExtGeoPol2Units)
{
   GeoPol2Units.insert(ExtGeoPol2Units.begin(), ExtGeoPol2Units.end());
}
//---------------------------------------------------------------------------

void TNewAdminUnit::SetGeoPol3Units(map<UnicodeString, UnicodeString>& ExtGeoPol3Units)
{
   GeoPol3Units.insert(ExtGeoPol3Units.begin(), ExtGeoPol3Units.end());
}
//---------------------------------------------------------------------------

void __fastcall TNewAdminUnit::cxCheckComboBox1PropertiesChange(TObject *Sender)
{
   if (GeoPol2Units.size() > 0) {
	 set<UnicodeString> UnitTypes;
	 for (int i=0; i<cxCheckComboBox1->Properties->Items->Count; i++) {
	   if (cxCheckComboBox1->States[i] == cbsChecked) {
		 UnicodeString State = cxCheckComboBox1->Properties->Items->Items[i]->Description;
		 UnitTypes.insert(GeoPol2Units[State]);
		 }
	   }
	 UnicodeString Caption;
	 set<UnicodeString>::iterator itr;
	 int i = 0;
	 for (itr = UnitTypes.begin(); itr != UnitTypes.end(); itr++) {
	   UnicodeString UnitType = *itr;
	   if (i++ == 0)
		 Caption = Capitalize(UnitType);
	   else
		 Caption += (L"/" + Capitalize(UnitType));
	   }
	 RadioButton2->Caption = Caption;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TNewAdminUnit::cxCheckComboBox2PropertiesChange(TObject *Sender)
{
   if (GeoPol3Units.size() > 0) {
	 set<UnicodeString> UnitTypes;
	 for (int i=0; i<cxCheckComboBox2->Properties->Items->Count; i++) {
	   if (cxCheckComboBox2->States[i] == cbsChecked) {
		 UnicodeString County = cxCheckComboBox2->Properties->Items->Items[i]->Description;
		 UnitTypes.insert(GeoPol3Units[County]);
		 }
	   }
	 UnicodeString Caption;
	 set<UnicodeString>::iterator itr;
	 int i = 0;
	 for (itr = UnitTypes.begin(); itr != UnitTypes.end(); itr++) {
	   UnicodeString UnitType = *itr;
	   if (i++ == 0)
		 Caption = Capitalize(UnitType);
	   else
		 Caption += (L"/" + Capitalize(UnitType));
	   }
	 RadioButton3->Caption = Caption;
	 }
}
//---------------------------------------------------------------------------

void TNewAdminUnit::ShowUploadButton(void)
{
   cxButton3->Left = cxButton1->Left;
   cxButton1->Visible = false;
   cxButton3->Visible = true;
}
//---------------------------------------------------------------------------

