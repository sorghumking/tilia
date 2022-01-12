//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TNNewTaxGrp.h"
#ifndef TINeotomaH
#include "TINeotoma.h"
#endif
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxGroupBox"
#pragma link "cxLabel"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxTextEdit"
#pragma link "ipwjson"
#pragma link "ipshttps"
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
TNewTaxaGroupForm *NewTaxaGroupForm;
//---------------------------------------------------------------------------
__fastcall TNewTaxaGroupForm::TNewTaxaGroupForm(UnicodeString* taxa_group_id_ptr,
	UnicodeString* taxa_group_ptr, TComponent* Owner) : TForm(Owner)
{
   EditElementsForm = (TEditElementsForm*)Owner;
   TaxaGroupPtr = taxa_group_ptr;
   TaxaGroup = *TaxaGroupPtr;
   TaxaGroupIDPtr = taxa_group_id_ptr;
   TaxaGroupID = *TaxaGroupIDPtr;
   cxLabel3->Caption = L"Taxa Group «" + TaxaGroup + L"» is not in Neotoma.";
   cxTextEdit2->Text = TaxaGroup;
}
//---------------------------------------------------------------------------

// search button for TaxaGroup
void __fastcall TNewTaxaGroupForm::cxButton1Click(TObject *Sender)
{
   UnicodeString TaxaGroupID;
   UnicodeString TaxaGroup = cxTextEdit2->Text;
   if (!EditElementsForm->ValidateTaxaGroup(TaxaGroup, TaxaGroupID))
	 return;
   if (TaxaGroupID.IsEmpty()) {
	 MessageDlg(L"Taxa Group not found.", mtInformation, TMsgDlgButtons() << mbOK, 0);
	 FocusControl(cxTextEdit2);
	 }
   else {
	 UnicodeString msg = L"Taxa Group «" + TaxaGroup + L"» found. Use this group?";
	 if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes) {
	   TListBox* ListBox3 = EditElementsForm->ListBox3;
	   TListBox* ListBox1 = EditElementsForm->ListBox1;
	   ELEMENTLOOKUP* LocalElementLookup = EditElementsForm->LocalElementLookup;
	   UnicodeString OldTaxaGroup = ListBox3->Items->Strings[ListBox3->ItemIndex];
	   ListBox3->Items->Delete(ListBox3->ItemIndex);
	   ListBox3->Items->Add(TaxaGroup.LowerCase());
	   ListBox3->ItemIndex = ListBox3->Items->IndexOf(TaxaGroup);
	   UnicodeString DatasetType = ListBox1->Items->Strings[ListBox1->ItemIndex];
	   LocalElementLookup->Elements[DatasetType][TaxaGroup] = LocalElementLookup->Elements[DatasetType][OldTaxaGroup];
	   LocalElementLookup->Elements[DatasetType].erase(OldTaxaGroup);
       *TaxaGroupPtr = TaxaGroup;
	   *TaxaGroupIDPtr = TaxaGroupID;
	   ModalResult = mrOk;
	   }
	 }
}
//---------------------------------------------------------------------------

// upload button
void __fastcall TNewTaxaGroupForm::cxButton3Click(TObject *Sender)
{
   UnicodeString TaxaGroup = cxTextEdit2->Text;
   if (TaxaGroup.Pos(L"%") > 0) {
	 MessageDlg(L"TaxaGroup name contains wildcard character \'%\'!",
	   Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 FocusControl(cxTextEdit2);
	 return;
	 }

   FlowPanel1->Visible = false;
   cxTextEdit1->Visible = true;
   cxLabel2->Visible = false;
   cxLabel1->Caption = L"Enter 3 Letter code for Taxa Group";
   cxLabel1->Properties->Alignment->Horz = taCenter;
   cxButton3->Visible = false;
   cxButton2->Visible = true;
   FocusControl(cxTextEdit1);
}
//---------------------------------------------------------------------------

// Ok button for new TaxaGroupID
void __fastcall TNewTaxaGroupForm::cxButton2Click(TObject *Sender)
{
   UnicodeString msg;

   UnicodeString TaxaGroupID = cxTextEdit1->Text.UpperCase();
   if (TaxaGroupID.Length() != 3) {
	 MessageDlg(L"Taxa Group ID must be 3 letters!", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 FocusControl(cxTextEdit1);
	 return;
	 }

   NeotomaGetTaxaGroupByID GetTaxaGroup(ipsJSONS1, TcpClient1);

   EditElementsForm->StatusBar1->SimpleText = GetTaxaGroup.WebServiceName();
   GetTaxaGroup.AddParam(L"TAXAGROUPID", TaxaGroupID);
   if (GetTaxaGroup.Execute()) {
	 if (GetTaxaGroup.Size() > 0) {
	   map<UnicodeString, UnicodeString>::iterator itr = GetTaxaGroup.Items.begin();
	   msg = L"TaxaGroupID «" + itr->first + L"» already exists for TaxaGroup «" +
		 itr->second + L"»!\nChoose another ID.";
	   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   FocusControl(cxTextEdit1);
	   return;
	   }
	 }

   UnicodeString TaxaGroup = cxTextEdit2->Text.LowerCase();
   UnicodeString FirstLetter = TaxaGroup.SubString(1,1).UpperCase();
   TaxaGroup.Delete(1,1);
   TaxaGroup.Insert(FirstLetter, 1);

   msg = L"Upload new Taxa Group «" + TaxaGroup + L"» with ID «" + TaxaGroupID + L"»?";
   if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrNo)
	 return;

   // proceed with upload
   //vector<UnicodeString> NewIDs;
   UnicodeString ErrorMsg;
   InsertData InsertTaxaGroup(L"InsertTaxaGroup", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
   EditElementsForm->StatusBar1->SimpleText = L"InsertTaxaGroup";
   InsertTaxaGroup.Add(L"TAXAGROUPID", TaxaGroupID);
   InsertTaxaGroup.Add(L"TAXAGROUP", TaxaGroup);
   InsertTaxaGroup.PostData();
   if (!InsertTaxaGroup.Post(ErrorMsg)) {
	 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 return;
	 }

   // if everything is ok
   *TaxaGroupPtr = TaxaGroup;
   *TaxaGroupIDPtr = TaxaGroupID;
   ModalResult = mrOk;
}
//---------------------------------------------------------------------------

void __fastcall TNewTaxaGroupForm::ipsJSONS1SSLServerAuthentication(TObject *Sender,
          TipsJSONSSSLServerAuthenticationEventParams *e)
{
   e->Accept = true;
}
//---------------------------------------------------------------------------

