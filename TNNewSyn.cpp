//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TNNewSyn.h"
#ifndef TINeotomaH
#include "TINeotoma.h"
#endif
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvCGrid"
#pragma link "AdvGrid"
#pragma link "AdvObj"
#pragma link "BaseGrid"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxTextEdit"
#pragma link "cxButtons"
#pragma link "cxLabel"
#pragma link "ipshttps"
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
TNewSynTypeForm *NewSynTypeForm;
//---------------------------------------------------------------------------
__fastcall TNewSynTypeForm::TNewSynTypeForm(TAdvColumnGrid* SourceGrid,
	TComponent* Owner) : TForm(Owner)
{
   SourceAdvColumnGrid = SourceGrid;
   AdvColumnGrid1->RowCount = SourceAdvColumnGrid->RowCount;
   for (int row=1; row<SourceAdvColumnGrid->RowCount; row++) {
	 AdvColumnGrid1->Cells[0][row] = SourceAdvColumnGrid->Cells[0][row];
	 AdvColumnGrid1->Cells[1][row] = SourceAdvColumnGrid->Cells[1][row];
	 }
}
//---------------------------------------------------------------------------

void __fastcall TNewSynTypeForm::cxTextEdit1PropertiesChange(TObject *Sender)
{
   cxButton1->Enabled = !cxTextEdit1->Text.IsEmpty();
}
//---------------------------------------------------------------------------

// upload new SynonymType to Neotoma
void __fastcall TNewSynTypeForm::cxButton1Click(TObject *Sender)
{
   UnicodeString msg;
   vector<int> newids;
   NTMSYNONYMTYPE NewSynType;
   NewSynType.SynonymType = cxTextEdit1->Text.LowerCase().Trim();

   // check if SynonymType already exists
   if (GetNeotomaSynonymType(NewSynType)) {
	 if (NewSynType.SynonymTypeID != -1) {
	   msg = L"Synonym Type «" + NewSynType.SynonymType + L"» already exists: ID = " +
		 IntToStr(NewSynType.SynonymTypeID) + L".";
	   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return;
	   }
	 }
   else
	 return;

   //Enquire if new SynonymType should be uploaded to Neotoma
   msg = L"Upload new Synonym Type «" + NewSynType.SynonymType + L"» to Neotoma?";
   if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) ==  mrNo)
	 return;

   InsertData InsertSynonymType(L"InsertSynonymType", 1, ipsHTTPS1, ipsJSONS1, TcpClient1);
   StatusBar1->Caption = L"InsertSynonymType";
   InsertSynonymType.Add(L"SYNONYMTYPE", NewSynType.SynonymType);
   InsertSynonymType.PostData();
   if (InsertSynonymType.Post(newids, msg)) {
	 if (newids.size() == 1) {
	   AdvColumnGrid1->SortSettings->Column = 0;
	   AdvColumnGrid1->QSort();
	   SourceAdvColumnGrid->SortSettings->Column = 0;
	   SourceAdvColumnGrid->QSort();
	   int row = AdvColumnGrid1->RowCount;
	   AdvColumnGrid1->RowCount++;
	   AdvColumnGrid1->Cells[0][row] = newids[0];
	   AdvColumnGrid1->Cells[1][row] = NewSynType.SynonymType;
	   SourceAdvColumnGrid->RowCount++;
	   SourceAdvColumnGrid->Cells[0][row] = newids[0];
	   SourceAdvColumnGrid->Cells[1][row] = NewSynType.SynonymType;
	   cxTextEdit1->Text= L"";
	   cxButton1->Enabled = false;
       AdvColumnGrid1->Row = AdvColumnGrid1->RowCount - 1;
	   msg = L"Success! New Synonym Type «" + NewSynType.SynonymType + L"» uploaded to Neotoma.";
       MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
	   }
	 }
   else
	 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);

   StatusBar1->Caption = L"";
}
//---------------------------------------------------------------------------

bool TNewSynTypeForm::GetNeotomaSynonymType(NTMSYNONYMTYPE& NewSynType)
{
   NewSynType.SynonymTypeID = -1;
   bool rv = true;
   NeotomaSynonymType SynonymType(ipsJSONS1, TcpClient1);
   SynonymType.AddParam(L"SYNONYMTYPE", NewSynType.SynonymType);
   StatusBar1->Caption = SynonymType.WebServiceName();
   if (SynonymType.Execute()) {
	 if (SynonymType.Size() > 0) {
	   map<int,UnicodeString>::iterator itr = SynonymType.Items.begin();
	   NewSynType.SynonymTypeID = itr->first;
	   }
	 }
   else
	 rv = false;
   StatusBar1->Caption = L"";
   return rv;
}
//---------------------------------------------------------------------------

void __fastcall TNewSynTypeForm::ipsJSONS1SSLServerAuthentication(TObject *Sender,
          TipsJSONSSSLServerAuthenticationEventParams *e)
{
   e->Accept = true;
}
//---------------------------------------------------------------------------

