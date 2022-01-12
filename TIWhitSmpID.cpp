//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TIWhitSmpID.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
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
#pragma link "cxTextEdit"
#pragma link "ipwhttp"
#pragma link "ipwjson"
#pragma link "ipsjsons"
#pragma resource "*.dfm"

#ifndef TIJSONH
#include "TIJSON.h"
#endif
#ifndef TIGlobalsH
#include "TIGlobals.h"
#endif


TWhitmoreSampleIDForm *WhitmoreSampleIDForm;
//---------------------------------------------------------------------------
__fastcall TWhitmoreSampleIDForm::TWhitmoreSampleIDForm(TComponent* Owner)
	: TForm(Owner)
{
   TSSForm = (TTilSpreadSheetForm*)Owner;
}
//---------------------------------------------------------------------------

void __fastcall TWhitmoreSampleIDForm::cxButton1Click(TObject *Sender)
{
   UnicodeString msg;
   int SampleID;
   vector<int> newids;

   msg = L"Sample ID is blank.";
   if (LabeledEdit1->Text.IsEmpty()) {
	 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 return;
	 }

   if (!TryStrToInt(LabeledEdit1->Text, SampleID)) {
	 msg = L"Invalid SampleID. Must be an integer.";
	 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 return;
	 }

   NeotomaSampleParents SampleParents(ipsJSONS1, TcpClient1);
   SampleParents.AddParam(L"SAMPLEID", SampleID);
   if (!SampleParents.Execute())
	 return;
   if (SampleParents.Size() == 1) {  // should always be true
     Panel3->Visible = true;
	 cxTextEdit1->Text = IntToStr(SampleParents.Items[0].SiteID);
	 cxTextEdit2->Text = IntToStr(SampleParents.Items[0].CollectionUnitID);
	 cxTextEdit3->Text = IntToStr(SampleParents.Items[0].AnalysisUnitID);
	 cxTextEdit4->Text = SampleParents.Items[0].SiteName;
	 cxTextEdit5->Text = SampleParents.Items[0].Handle;
	 cxTextEdit6->Text = FloatToStr(SampleParents.Items[0].Depth);
	 }
   else
	 return;

   cxButton3->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TWhitmoreSampleIDForm::cxButton3Click(TObject *Sender)
{
   UnicodeString msg;
   TParameter* Param;
   int SampleID;

   UnicodeString VarCode = TSSForm->ProfGrid1->AbsoluteCells[1][3]->Value;
   if (!SameText(VarCode, L"#Samp.Name")) {
	 MessageDlg(L"#Samp.Name not in row 3", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 return;
	 }
   TProfGridCell* ACell = TSSForm->ProfGrid1->Cells[TSSForm->ProfGrid1->Col][TSSForm->ProfGrid1->Row];
   Variant Value = TSSForm->ProfGrid1->AbsoluteCells[ACell->AbsoluteCol][3]->Value;
   int ID1 = VariantToInt(Value, -1);
   if (ID1 == -1) {
	 MessageDlg(L"Invalid Whitmore ID1", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 return;
	 }

   if (!TryStrToInt(LabeledEdit1->Text, SampleID)) {
	 msg = L"Something went wrong. Invalid SampleID.";
	 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 return;
	 }

   msg = L"Update Neotoma SampleID for Whitmore ID1 " + IntToStr(ID1) + L" to " + IntToStr(SampleID) + L"?";
   if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) != mrYes)
	 return;

   Access WhitmoreAccess(ADOConnection1, tiGlobals->WhitmorePath);
   if (!WhitmoreAccess.Connect())
	 return;

   Param = ADOQuery1->Parameters->ParamByName("ID1");
   Param->Value = ID1;
   Param = ADOQuery1->Parameters->ParamByName("SampleID");
   Param->Value = SampleID;
   int rows_affected = ADOQuery1->ExecSQL();
   if (rows_affected == 1) {
	 msg = L"Neotoma SampleID for Whitmore ID1 " + IntToStr(ID1) + L" updated to " + IntToStr(SampleID) + L".";
	 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
	 }

   ModalResult = mrClose;
}
//---------------------------------------------------------------------------

void __fastcall TWhitmoreSampleIDForm::ipsJSONS1SSLServerAuthentication(TObject *Sender,
          TipsJSONSSSLServerAuthenticationEventParams *e)
{
   e->Accept = true;
}
//---------------------------------------------------------------------------

