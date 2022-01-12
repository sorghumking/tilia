//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TIWhitRem.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxGraphics"
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

#ifndef TIGlobalsH
#include "TIGlobals.h"
#endif
#ifndef TICommonH
#include "TICommon.h"
#endif
#ifndef TISpreadH
#include "TISpread.h"
#endif

TWhitmoreRemoveSampleForm *WhitmoreRemoveSampleForm;
//---------------------------------------------------------------------------
__fastcall TWhitmoreRemoveSampleForm::TWhitmoreRemoveSampleForm(TComponent* Owner)
	: TForm(Owner)
{
   TTilSpreadSheetForm* TSSForm = (TTilSpreadSheetForm*)Owner;
   int row = TSSForm->ProfGrid1->Row;
   UnicodeString VarCode = TSSForm->ProfGrid1->AbsoluteCells[1][row]->Text;
   if (SameText(VarCode,L"#Samp.Name")) {
	 int SampleID;
	 int col = TSSForm->ProfGrid1->Col;
	 UnicodeString SampStr = TSSForm->ProfGrid1->Cells[col][row]->Text;
	 if (TryStrToInt(SampStr,SampleID))
	   LabeledEdit1->Text = SampStr;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TWhitmoreRemoveSampleForm::cxButton1Click(TObject *Sender)
{
   UnicodeString msg;
   UnicodeString SQL;
   TParameter* Param;

   int ID1;
   if (!TryStrToInt(LabeledEdit1->Text, ID1)) {
	 msg = L"Whitmore ID1 not a valid integer.";
	 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 return;
	 }

   if (Memo1->Text.IsEmpty()) {
	 msg = L"Notes field is empty.";
	 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 return;
	 }

   Access WhitmoreAccess(ADOConnection1, tiGlobals->WhitmorePath);
   if (!WhitmoreAccess.Connect())
	 return;

   // SQL = L"SELECT Count(*) AS CountID1 FROM Whitmore WHERE (((Whitmore.[ID1])=:ID1));
   Param = ADODataSet1->Parameters->ParamByName("ID1");
   Param->Value = ID1;
   ADODataSet1->Open();
   ADODataSet1->First();
   int count = -1;
   int RecCount = ADODataSet1->RecordCount;
   if (RecCount == 1)
	 count = VariantToInt(ADODataSet1->FindField(L"CountID1")->Value, -1);

   if (count == 0) {
	 msg = L"ID1 " + IntToStr(ID1) + L" does not exist.";
	 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 return;
	 }
   else if (count != 1) {
	 msg = L"Something went wrong with SELECT COUNT. Either query failed or more than one ID1 value exists.";
	 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 return;
	 }

   Param = ADOQuery1->Parameters->ParamByName("ID1");
   Param->Value = ID1;

   int rows_affected = ADOQuery1->ExecSQL();
   if (rows_affected != 1) {
	 msg = L"Something went wrong. Removed not set to true for ID1 " + IntToStr(ID1) + L".";
	 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 return;
	 }

   Param = ADOQuery2->Parameters->ParamByName("ID1");
   Param->Value = ID1;
   Param = ADOQuery2->Parameters->ParamByName("Notes");
   Param->Value = Memo1->Text;

   rows_affected = ADOQuery2->ExecSQL();
   if (rows_affected != 1) {
	 msg = L"Something went wrong. Removed not set to true for ID1 " + IntToStr(ID1) + L".";
	 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 return;
	 }

   msg = L"Removal notes added for ID1 " + IntToStr(ID1);
   MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);

   ModalResult = mrClose;
}
//---------------------------------------------------------------------------
