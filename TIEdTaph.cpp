//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TIEdTaph.h"
#ifndef TIVersionH
#include "TIVersion.h"
#endif
#ifndef TINeotomaH
#include "TINeotoma.h"
#endif
#ifndef TNLoginH
#include "TNLogin.h"
#endif

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
#pragma link "cxDropDownEdit"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "cxGroupBox"
#pragma link "ipwjson"
#pragma link "ipshttps"
#pragma link "cxMemo"
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
TEditTaphonomyForm *EditTaphonomyForm;
//---------------------------------------------------------------------------
__fastcall TEditTaphonomyForm::TEditTaphonomyForm(VARIABLELOOKUP* varLookup,
	 TStrings* DatasetTypes, TComponent* Owner) : TForm(Owner)
{
   VarLookup = varLookup;
   OriginalTaphLookup = VarLookup->GetTaphonomyLookup();
   //OriginalTaphLookup = TaphonomyLookup;
   TaphonomyLookup = new TAPHONOMYLOOKUP(OriginalTaphLookup);

   map<UnicodeString, TAPHONOMICSYSTEM>::iterator itr;
   map<UnicodeString, TAPHONOMICSYSTEM>::iterator begin = TaphonomyLookup->DatasetType.begin();
   map<UnicodeString, TAPHONOMICSYSTEM>::iterator end = TaphonomyLookup->DatasetType.end();

   if (TaphonomyLookup->DatasetType.size() == 1 && SameText(begin->first, L"none")) {
	 cxListBox1->Items->Add(begin->first);
	 }
   else {
	 for (itr = begin; itr != end; itr++) {
	   if (!SameText(itr->first, L"none"))
		 cxListBox1->Items->Add(itr->first);
	   }
	 }
   cxListBox1->ItemIndex = 0;

   UnicodeString DatasetType = cxListBox1->Items->Strings[0];
   set<UnicodeString> Systems;
   TaphonomyLookup->GetSystems(DatasetType, Systems);
   if (Systems.size() > 0) {
	 set<UnicodeString>::iterator it;
	 for (it = Systems.begin(); it != Systems.end(); it++)
	   cxListBox2->Items->Add(*it);
	 cxListBox2->ItemIndex = 0;
	 UnicodeString System = cxListBox2->Items->Strings[0];
	 set<UnicodeString> Types;
	 TaphonomyLookup->GetTypes(DatasetType, System, Types);
	 if (Types.size() > 0) {
	   for (it = Types.begin(); it != Types.end(); it++)
		 cxListBox3->Items->Add(*it);
	   cxListBox3->ItemIndex = 0;
	   }
	 }

   for (int i=0; i<DatasetTypes->Count; i++) {
	 UnicodeString DatasetType = DatasetTypes->Strings[i];
	 if (!ContainsText(DatasetType, L"surface sample") && cxListBox1->Items->IndexOf(DatasetType) == -1)
	   cxComboBox1->Properties->Items->Add(DatasetType.LowerCase());
	 }

   if (SameText(begin->first, L"none")) {
	 cxGroupBox1->Visible = true;
	 for (int i=0; i<DatasetTypes->Count; i++) {
	   UnicodeString DatasetType = DatasetTypes->Strings[i];
	   if (!ContainsText(DatasetType, L"surface sample"))
		 cxComboBox2->Properties->Items->Add(DatasetType.LowerCase());
	   }
	 Panel1->Enabled = false;
	 }

   if (tiLicense->Type() != verNEOTOMASTEWARD) {
	 cxButton12->Visible = false;
	 FlowPanel4->Width = 3*cxButton9->Width + 1;
	 FlowPanel4->Left = (Panel2->Width - FlowPanel4->Width)/2 + 1;
	 StatusBar1->Visible = false;
	 Height -= StatusBar1->Height;
	 }

   cxGroupBox2->Left = 95;
   cxGroupBox2->Top = 52;
   cxGroupBox2->Height = 148;
   cxGroupBox2->Width = 297;
   cxMemo1->Height = 84;
   cxMemo1->Width = 277;
   cxLabel10->Top = cxMemo1->Top;
   cxLabel10->Left = cxMemo1->Left + 2;
   if (tiLicense->Type() == verNEOTOMASTEWARD) {
	 cxButton15->Left = 72;
	 cxButton15->Top = 112;
	 cxButton16->Left = 150;
	 cxButton16->Top = 112;
	 cxButton16->Visible = true;
	 }
   else {
	 cxButton15->Left = (cxGroupBox2->Width - cxButton15->Width)/2;
	 cxButton15->Top = 112;
	 cxButton16->Visible = false;
	 }
   Panel3->Align = alClient;
}
//---------------------------------------------------------------------------

void __fastcall TEditTaphonomyForm::FormClose(TObject *Sender, TCloseAction &Action)
{
   delete TaphonomyLookup;
}
//---------------------------------------------------------------------------

// "none" DatasetType
void __fastcall TEditTaphonomyForm::cxButton7Click(TObject *Sender)
{
   if (cxLabel7->Visible) {
	 cxLabel7->Visible = false;
	 cxLabel8->Visible = true;
	 cxLabel9->Visible = true;
	 cxComboBox2->Visible = true;
	 cxTextEdit4->Visible = true;
	 FocusControl(cxComboBox2);
	 }
   else {
	 if (cxComboBox2->Text.IsEmpty() || SameText(cxComboBox2->Text, L"none")) {
	   MessageDlg(L"Invalid Dataset Type!", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return;
	   }
	 if (cxTextEdit4->Text.IsEmpty() || SameText(cxTextEdit4->Text, L"none")) {
	   MessageDlg(L"Invalid Taphonomic System!", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return;
	   }

	 UnicodeString DatasetType = cxComboBox2->Text.LowerCase();
	 UnicodeString System = cxTextEdit4->Text;
	 TaphonomyLookup->Add(DatasetType, System);

	 cxListBox1->Items->Clear();
	 cxListBox1->Items->Add(DatasetType);
	 cxListBox2->Items->Clear();
	 cxListBox2->Items->Add(System);
	 cxListBox1->ItemIndex = 0;
	 cxListBox2->ItemIndex = 0;
	 RemoveDatasetType(cxComboBox2->Text);
	 cxGroupBox1->Visible = false;
	 Panel1->Enabled = true;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TEditTaphonomyForm::cxListBox1Click(TObject *Sender)
{
   SetNewDatasetType();
}
//---------------------------------------------------------------------------

void TEditTaphonomyForm::SetNewDatasetType(void)
{
   UnicodeString DatasetType = CurrentDatasetType();
   set<UnicodeString> Systems;
   TaphonomyLookup->GetSystems(DatasetType, Systems);
   cxListBox2->Clear();
   cxListBox3->Clear();
   if (Systems.size() > 0) {
	 set<UnicodeString>::iterator itr;
	 for (itr = Systems.begin(); itr != Systems.end(); itr++)
	   cxListBox2->Items->Add(*itr);
	 cxListBox2->ItemIndex = 0;
	 UnicodeString System = cxListBox2->Items->Strings[0];
	 set<UnicodeString> Types;
	 TaphonomyLookup->GetTypes(DatasetType, System, Types);
	 if (Types.size() > 0) {
	   for (itr = Types.begin(); itr != Types.end(); itr++)
		 cxListBox3->Items->Add(*itr);
	   cxListBox3->ItemIndex = 0;
	   }
	 EnableTypes(true);
	 }
   else
	 EnableTypes(false);
}
//---------------------------------------------------------------------------

void TEditTaphonomyForm::EnableTypes(bool Enabled)
{
   cxListBox3->Enabled = Enabled;
   cxTextEdit2->Enabled = Enabled;
   cxButton6->Enabled = Enabled;
   cxButton14->Enabled = Enabled;
}
//---------------------------------------------------------------------------

void __fastcall TEditTaphonomyForm::cxListBox2Click(TObject *Sender)
{
   cxListBox3->Clear();
   set<UnicodeString> Types;
   TaphonomyLookup->GetTypes(CurrentDatasetType(), CurrentSystem(), Types);
   if (Types.size() > 0) {
	 set<UnicodeString>::iterator itr;
	 for (itr = Types.begin(); itr != Types.end(); itr++)
	   cxListBox3->Items->Add(*itr);
	 cxListBox3->ItemIndex = 0;
	 }
   cxButton4->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TEditTaphonomyForm::cxComboBox1Click(TObject *Sender)
{
   cxButton1->Enabled = true;
}
//---------------------------------------------------------------------------

// add new DatasetType
void __fastcall TEditTaphonomyForm::cxButton1Click(TObject *Sender)
{
   UnicodeString DatasetType = cxComboBox1->Text;
   if (AddListBoxItem(cxListBox1, DatasetType)) {
	 SetNewDatasetType();
	 RemoveDatasetType(DatasetType);  // remove DatasetType from cxCombobox1
	 cxButton1->Enabled = false;
	 cxButton11->Enabled = true;
	 }
   else {
	 UnicodeString msg = L"Dataset Type «" + DatasetType + "» already exists!";
	 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
	 }
}
//---------------------------------------------------------------------------

bool TEditTaphonomyForm::AddListBoxItem(TcxListBox* cxListBox, UnicodeString Item)
{
   if (cxListBox->Items->IndexOf(Item) == -1) {
	 cxListBox->Items->Add(Item);
	 cxListBox->Sorted = true;
	 cxListBox->ItemIndex = cxListBox->Items->IndexOf(Item);
	 return true;
	 }
   return false;
}
//---------------------------------------------------------------------------

void TEditTaphonomyForm::RemoveDatasetType(UnicodeString DatasetType)
{
   int idx = cxComboBox1->Properties->Items->IndexOf(DatasetType);
   if (idx > -1)
	 cxComboBox1->Properties->Items->Delete(idx);
   cxComboBox1->ItemIndex = -1;
   cxButton1->Enabled = false;
}
//---------------------------------------------------------------------------

// delete DatasetType
void __fastcall TEditTaphonomyForm::cxButton2Click(TObject *Sender)
{
   UnicodeString DatasetType = CurrentDatasetType();

   if (MessageDlg(L"Delete Dataset Type «" + DatasetType + "»?", mtConfirmation,
	   TMsgDlgButtons() << mbYes << mbNo, 0) == mrNo) return;

   DeleteListBoxItem(cxListBox1, DatasetType);
   if (cxListBox1->Count == 0)
	 cxButton2->Enabled = false;

   cxComboBox1->Properties->Items->Add(DatasetType);
   cxComboBox1->Properties->Sorted = true;
   cxListBox2->Clear();
   cxListBox2->ItemIndex = -1;
   cxButton4->Enabled = false;
   cxListBox3->Clear();
   cxListBox3->ItemIndex = -1;
   cxButton6->Enabled = false;
   TaphonomyLookup->DatasetType.erase(DatasetType);
   cxButton11->Enabled = true;
}
//---------------------------------------------------------------------------

void TEditTaphonomyForm::DeleteListBoxItem(TcxListBox* cxListBox, UnicodeString DatasetType)
{
   TStringList* Items = new TStringList;
   Items->Assign(cxListBox->Items);
   Items->Delete(Items->IndexOf(DatasetType));
   cxListBox->Clear();
   if (Items->Count > 0) {
	 cxListBox->Items->Assign(Items);
	 cxListBox->ItemIndex = 0;
	 }
   else
	 cxListBox->ItemIndex = -1;
   delete Items;
}
//---------------------------------------------------------------------------

void __fastcall TEditTaphonomyForm::cxTextEdit1PropertiesChange(TObject *Sender)
{
   cxButton3->Enabled = !cxTextEdit1->Text.IsEmpty();
}
//---------------------------------------------------------------------------

// add new system
void __fastcall TEditTaphonomyForm::cxButton3Click(TObject *Sender)
{
   UnicodeString System = cxTextEdit1->Text;
   if (AddListBoxItem(cxListBox2, System)) {
	 TaphonomyLookup->Add(CurrentDatasetType(), System);
	 cxListBox3->Clear();
	 cxTextEdit1->Text = L"";
	 cxButton3->Enabled = false;
	 cxListBox3->Enabled = true;
	 cxTextEdit2->Enabled = true;
	 cxButton6->Enabled = false;
	 cxButton14->Enabled = false;
	 cxButton11->Enabled = true;
	 cxButton12->Enabled = true;
	 }
   else {
	 UnicodeString msg = L"Taphonomic System «" + System + "» already exists!";
	 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
	 }
}
//---------------------------------------------------------------------------

//delete system
void __fastcall TEditTaphonomyForm::cxButton4Click(TObject *Sender)
{
   UnicodeString System = CurrentSystem();
   if (MessageDlg(L"Delete Taphonomic System «" + System + "»?", mtConfirmation,
	   TMsgDlgButtons() << mbYes << mbNo, 0) == mrNo) return;

   DeleteListBoxItem(cxListBox2, System);
   if (cxListBox2->Count == 0)
	 cxButton4->Enabled = false;

   cxListBox3->Clear();
   cxListBox3->ItemIndex = -1;
   cxButton6->Enabled = false;
   TaphonomyLookup->DatasetType[CurrentDatasetType()].erase(System);
   cxButton11->Enabled = true;
   cxButton12->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TEditTaphonomyForm::cxTextEdit2PropertiesChange(TObject *Sender)
{
   cxButton5->Enabled = !cxTextEdit2->Text.IsEmpty();
}
//---------------------------------------------------------------------------

// add new type
void __fastcall TEditTaphonomyForm::cxButton5Click(TObject *Sender)
{
   UnicodeString Type = cxTextEdit2->Text;
   if (AddListBoxItem(cxListBox3, Type)) {
	 TaphonomyLookup->Add(CurrentDatasetType(), CurrentSystem(), Type);
	 cxTextEdit2->Text = L"";
	 cxButton5->Enabled = false;
	 cxButton6->Enabled = true;
	 cxButton14->Enabled = true;
	 cxButton11->Enabled = true;
     cxButton12->Enabled = true;
	 }
   else {
	 UnicodeString msg = L"Taphonomic Type «" + Type + "» already exists!";
	 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
	 }
}
//---------------------------------------------------------------------------

// delete type
void __fastcall TEditTaphonomyForm::cxButton6Click(TObject *Sender)
{
   UnicodeString Type = CurrentType();
   if (MessageDlg(L"Delete Taphonomic Type «" + Type + "»?", mtConfirmation,
	   TMsgDlgButtons() << mbYes << mbNo, 0) == mrNo) return;

   DeleteListBoxItem(cxListBox3, Type);
   if (cxListBox3->Count == 0) {
	 cxButton6->Enabled = false;
	 cxButton14->Enabled = false;
	 //cxButton11->Enabled = true;
	 //cxButton12->Enabled = true;
	 }
   cxButton11->Enabled = true;

   TaphonomyLookup->DatasetType[CurrentDatasetType()][CurrentSystem()].erase(Type);
}
//---------------------------------------------------------------------------

UnicodeString TEditTaphonomyForm::CurrentDatasetType(void)
{
   return cxListBox1->Items->Strings[cxListBox1->ItemIndex];
}
//---------------------------------------------------------------------------

UnicodeString TEditTaphonomyForm::CurrentSystem(void)
{
   return cxListBox2->Items->Strings[cxListBox2->ItemIndex];
}
//---------------------------------------------------------------------------

UnicodeString TEditTaphonomyForm::CurrentType(void)
{
   return cxListBox3->Items->Strings[cxListBox3->ItemIndex];
}
//---------------------------------------------------------------------------

// Ok button
void __fastcall TEditTaphonomyForm::cxButton9Click(TObject *Sender)
{
   OriginalTaphLookup->DatasetType = TaphonomyLookup->DatasetType;
}
//---------------------------------------------------------------------------

// Save button: save taphonomy to local lookup file
void __fastcall TEditTaphonomyForm::cxButton11Click(TObject *Sender)
{
   OriginalTaphLookup->DatasetType = TaphonomyLookup->DatasetType;
   UnicodeString PathName = TaphonomyLookup->GetPathName();
   SaveVariableModifiers(MOD_TAPHONOMY, PathName, VarLookup, this);
}
//---------------------------------------------------------------------------

// Neotoma button
void __fastcall TEditTaphonomyForm::cxButton12Click(TObject *Sender)
{
   MessageDlg(L"Taphonomic uploads/updates will be for current Dataset Type and Taphonomic System only.",
	 mtInformation, TMsgDlgButtons() << mbOK, 0);

   if (!Login->IsLoggedIn) {
	 NeotomaLoginForm = new TNeotomaLoginForm(this);
	 NeotomaLoginForm->ShowModal();
	 delete NeotomaLoginForm;
	 }
   if (Login->IsLoggedIn) {
	 UploadTaphonomy();
	 Screen->Cursor = crDefault;
	 }
}
//---------------------------------------------------------------------------

void TEditTaphonomyForm::UploadTaphonomy(void)
{
   vector<void*> vptrs;
   vector<int> NewIDs;
   UnicodeString ErrorMsg;
   UnicodeString msg;

   int DatasetTypeID;
   UnicodeString DatasetType = CurrentDatasetType();
   UnicodeString System = CurrentSystem();

   // validate DatasetType
   Screen->Cursor = crHourGlass;

   if (!ValidateDatasetType(DatasetType, DatasetTypeID))
	 return;
   if (DatasetTypeID == -1) {
	 msg = L"«" + DatasetType + L"» is not a valid Neotoma Dataset Type! ";
	 msg += L"\nTaphonomic system cannot be uploaded.";
	 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
	 return;
	 }

   // validate Taphonomic system, if doesn't exist, add it.
   int TaphonomicSystemID;
   NeotomaTaphonomicSystemsTable TaphSystems(ipsJSONS1, TcpClient1);
   StatusBar1->SimpleText = TaphSystems.WebServiceName();
   if (!TaphSystems.Execute())
	 return;

   bool NewSystem = false;
   if (TaphSystems.Find("TaphonomicSystem", System, vptrs) > 0) {
	 NTMTAPHONOMICSYSTEMS* SystemRec = (NTMTAPHONOMICSYSTEMS*)vptrs[0];
	 TaphonomicSystemID = SystemRec->TaphonomicSystemID;
	 }
   else {
	 InsertData InsertSystem(L"InsertTaphonomicSystem", 1, ipsHTTPS1, ipsJSONS1, TcpClient1);
	 StatusBar1->SimpleText = L"InsertTaphonomicSystem";
	 InsertSystem.Add(L"TAPHONOMICSYSTEM", System);
	 InsertSystem.PostData();
	 if (InsertSystem.Post(NewIDs, ErrorMsg)) {
	   if (NewIDs.size() > 0) {
		 TaphonomicSystemID = NewIDs[0];
		 NewSystem = true;
		 }
	   else {
		 MessageDlg(L"Error: New Taphonomic System not posted.", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 return;
		 }
	   }
	 else {
	   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return;
	   }
	 }

   if (NewSystem) {
	 InsertData InsertSystemDatasetType(L"InsertTaphonomicSystemDatasetType", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
	 StatusBar1->SimpleText = L"InsertTaphonomicSystemDatasetType";
	 InsertSystemDatasetType.Add(L"DATASETTYPEID", DatasetTypeID, -1);
	 InsertSystemDatasetType.Add(L"TAPHONOMICSYSTEMID", TaphonomicSystemID, -1);
	 InsertSystemDatasetType.PostData();
	 if (!InsertSystemDatasetType.Post(ErrorMsg)) {
	   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return;
	   }
	 }

   set<UnicodeString> LocalTypes;
   TaphonomyLookup->GetTypes(DatasetType, System, LocalTypes);
   if (LocalTypes.size() == 0) {
	 if (NewSystem) {
	   msg = L"New Taphonomic System «" + System + L"» uploaded to Neotoma.";
	   msg += L"\nNo new Taphonomic Types uploaded at this time.";
	   MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
	   return;
	   }
	 else {
	   msg = L"Taphonomic System «" + System + L"» is already in Neotoma.";
	   msg += L"\nNo new Taphonomic Types are listed.";
	   msg += L"\nTypes cannot be deleted from Neotoma via this interface.";
	   MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
	   return;
	   }
	 }

   NeotomaTaphonomicTypesBySystem TaphTypes(ipsJSONS1, TcpClient1);
   StatusBar1->SimpleText = TaphTypes.WebServiceName();
   TaphTypes.AddParam(L"TAPHONOMICSYSTEMID", TaphonomicSystemID);
   if (!TaphTypes.Execute()) return;

   vector<UnicodeString> NewTypes;
   set<UnicodeString>::iterator itr;
   for (itr = LocalTypes.begin(); itr != LocalTypes.end(); itr++) {
	 if (TaphTypes.Find("TaphonomicType", *itr, vptrs) == 0)
	   NewTypes.push_back(*itr);
	 }

   if (NewTypes.size() == 0) {
	 msg = L"Taphonomic System «" + System + L"» is already in Neotoma.";
	 msg += L"\nNo new Taphonomic Types are listed.";
	 msg += L"\nTypes cannot be deleted from Neotoma via this interface.";
	 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
	 return;
	 }

   for (unsigned int i=0; i<NewTypes.size(); i++) {
	 InsertData InsertTaphType(L"InsertTaphonomicType", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
	 StatusBar1->SimpleText = L"InsertTaphonomicType";
	 InsertTaphType.Add(L"TAPHONOMICSYSTEMID", TaphonomicSystemID, -1);
	 InsertTaphType.Add(L"TAPHONOMICTYPE", NewTypes[i]);
	 //if (nparams == 3)
	 //  InsertTaphType.Add(L"NOTES", Notes);
	 InsertTaphType.PostData();
	 if (!InsertTaphType.Post(ErrorMsg)) {
	   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return;
	   }
	 }

   if (NewTypes.size() == 1)
	 msg = L"Taphonomic Type «" + NewTypes[0] + L"» in Taphonomic System «" +
		   System + L"» uploaded";
   else
	 msg = IntToStr((int)NewTypes.size()) + L" Taphonomic Types in Taphonomic System «" +
		   System + L"» uploaded";
   MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
}
//---------------------------------------------------------------------------

bool TEditTaphonomyForm::ValidateDatasetType(UnicodeString DatasetType, int& DatasetTypeID)
{
   NeotomaDatasetTypesTable DatasetTypes(ipsJSONS1, TcpClient1);
   StatusBar1->SimpleText = DatasetTypes.WebServiceName();
   DatasetTypeID = -1;
   bool rv = false;
   if (DatasetTypes.Execute()) {
     rv = true;
	 map<int, UnicodeString>::iterator itr;
	 map<int, UnicodeString>::iterator begin = DatasetTypes.Items.begin();
	 map<int, UnicodeString>::iterator end = DatasetTypes.Items.end();
	 itr = begin;
	 while (DatasetTypeID == -1 && itr != end) {
	   if (SameText(DatasetType, itr->second))
		 DatasetTypeID = itr->first;
	   itr++;
	   }
	 }
   return rv;
}
//---------------------------------------------------------------------------

// system notes
void __fastcall TEditTaphonomyForm::cxButton13Click(TObject *Sender)
{
   if (cxListBox2->Count == 0) return;
   UnicodeString DatasetType = CurrentDatasetType();
   int DatasetTypeID;
   UnicodeString msg;

   cxGroupBox2->Visible = true;
   Panel3->Visible = true;

   if (!ValidateDatasetType(DatasetType, DatasetTypeID)) {
	 cxGroupBox2->Visible = false;
	 return;
	 }
   if (DatasetTypeID == -1) {
	 msg = L"«" + DatasetType + L"» is not a valid Neotoma Dataset Type!";
	 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
	 cxGroupBox2->Visible = false;
	 return;
	 }

   NeotomaTaphonomicSystemsByDatasetType TaphSystems(ipsJSONS1, TcpClient1);
   StatusBar1->SimpleText = TaphSystems.WebServiceName();
   TaphSystems.AddParam(L"DATASETTYPEID", DatasetTypeID);
   if (!TaphSystems.Execute()) {
	 cxGroupBox2->Visible = false;
	 return;
	 }
   if (TaphSystems.Items.size() == 0) {
	 msg = L"No Neotoma Taphonomic Systems have been defined for Dataset Type «" + DatasetType + L"»";
	 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
	 cxGroupBox2->Visible = false;
	 return;
	 }
   TaphSystemNotes.TaphonomicSystem = CurrentSystem();
   TaphSystemNotes.TaphonomicSystemID = -1;
   UnicodeString Notes;
   for (unsigned int i=0; i<TaphSystems.Items.size(); i++) {
	 if (SameText(TaphSystemNotes.TaphonomicSystem, TaphSystems.Items[i].TaphonomicSystem)) {
	   TaphSystemNotes.TaphonomicSystemID = TaphSystems.Items[i].TaphonomicSystemID;
	   TaphSystemNotes.Notes = TaphSystems.Items[i].Notes;
	   break;
	   }
	 }
   if (TaphSystemNotes.TaphonomicSystemID == -1) {
	 msg = L"Taphonomic System «" + TaphSystemNotes.TaphonomicSystem +
		   L"» has not been defined for Dataset Type «" + DatasetType + L"»";
	 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
	 cxGroupBox2->Visible = false;
	 return;
	 }

   UnicodeString Caption = L"Notes for System: " + TaphSystemNotes.TaphonomicSystem;
   cxLabel11->Caption = Caption;
   cxMemo1->Text = TaphSystemNotes.Notes;
   cxLabel10->Visible = TaphSystemNotes.Notes.IsEmpty();
   NotesShowing = TAPHSYSTEMNOTES;
   cxButton16->Enabled = false;
   Panel3->Visible = false;
}
//---------------------------------------------------------------------------

// type notes
void __fastcall TEditTaphonomyForm::cxButton14Click(TObject *Sender)
{
   if (cxListBox3->Count == 0) return;
   UnicodeString DatasetType = CurrentDatasetType();
   int DatasetTypeID;
   UnicodeString msg;

   cxGroupBox2->Visible = true;
   Panel3->Visible = true;

   if (!ValidateDatasetType(DatasetType, DatasetTypeID)) {
	 cxGroupBox2->Visible = false;
	 return;
	 }
   if (DatasetTypeID == -1) {
	 msg = L"«" + DatasetType + L"» is not a valid Neotoma Dataset Type!";
	 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
	 cxGroupBox2->Visible = false;
	 return;
	 }

   NeotomaTaphonomicSystemsByDatasetType TaphSystems(ipsJSONS1, TcpClient1);
   StatusBar1->SimpleText = TaphSystems.WebServiceName();
   TaphSystems.AddParam(L"DATASETTYPEID", DatasetTypeID);
   if (!TaphSystems.Execute()) {
	 cxGroupBox2->Visible = false;
	 return;
	 }
   UnicodeString System = CurrentSystem();
   int TaphonomicSystemID = -1;
   for (unsigned int i=0; i<TaphSystems.Items.size(); i++) {
	 if (SameText(System, TaphSystems.Items[i].TaphonomicSystem)) {
	   TaphonomicSystemID = TaphSystems.Items[i].TaphonomicSystemID;
	   break;
	   }
	 }
   if (TaphonomicSystemID == -1) {
	 msg = L"Taphonomic System «" + TaphSystemNotes.TaphonomicSystem +
		   L"» has not been defined for Dataset Type «" + DatasetType + L"»";
	 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
	 cxGroupBox2->Visible = false;
	 return;
	 }

   NeotomaTaphonomicTypesBySystem TaphTypes(ipsJSONS1, TcpClient1);
   StatusBar1->SimpleText = TaphTypes.WebServiceName();
   TaphTypes.AddParam(L"TAPHONOMICSYSTEMID", TaphonomicSystemID);
   if (!TaphTypes.Execute()) {
	 cxGroupBox2->Visible = false;
	 return;
	 }
   TaphTypeNotes.TaphonomicTypeID = -1;
   TaphTypeNotes.TaphonomicType = CurrentType();
   for (unsigned int i=0; i<TaphTypes.Items.size(); i++) {
	 if (SameText(TaphTypeNotes.TaphonomicType, TaphTypes.Items[i].TaphonomicType)) {
	   TaphTypeNotes.TaphonomicTypeID = TaphTypes.Items[i].TaphonomicTypeID;
	   TaphTypeNotes.Notes = TaphTypes.Items[i].Notes;
	   break;
	   }
	 }

   if (TaphTypeNotes.TaphonomicTypeID == -1) {
	 msg = L"Taphonomic Type «" + TaphTypeNotes.TaphonomicType +
		   L"» has not been defined for Taphonomic System «" + System + L"»";
	 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
	 cxGroupBox2->Visible = false;
	 return;
	 }

   UnicodeString Caption = L"Notes for Type: " + TaphTypeNotes.TaphonomicType;
   cxLabel11->Caption = Caption;
   cxMemo1->Text = TaphTypeNotes.Notes;
   cxLabel10->Visible = TaphTypeNotes.Notes.IsEmpty();
   NotesShowing = TAPHTYPENOTES;
   cxButton16->Enabled = false;
   Panel3->Visible = false;
}
//---------------------------------------------------------------------------

// cancel notes button
void __fastcall TEditTaphonomyForm::cxButton15Click(TObject *Sender)
{
   cxGroupBox2->Visible = false;
}
//---------------------------------------------------------------------------

// update notes button
void __fastcall TEditTaphonomyForm::cxButton16Click(TObject *Sender)
{
   UnicodeString ErrorMsg;

   if (!Login->IsLoggedIn) {
	 NeotomaLoginForm = new TNeotomaLoginForm(this);
	 NeotomaLoginForm->ShowModal();
	 delete NeotomaLoginForm;
	 }
   if (!Login->IsLoggedIn)
	 return;

   UnicodeString NewNotes = cxMemo1->Text.Trim();
   if (NotesShowing == TAPHSYSTEMNOTES) {
	 UpdateData UpdateSystemNotes(L"UpdateTaphonomicSystemNotes", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
	 StatusBar1->SimpleText = L"UpdateTaphonomicSystemNotes";
	 UpdateSystemNotes.Add(L"TAPHONOMICSYSTEMID", TaphSystemNotes.TaphonomicSystemID);
	 UpdateSystemNotes.Add(L"NOTES", NewNotes);
	 if (UpdateSystemNotes.Post(ErrorMsg)) {
       TaphSystemNotes.Notes = NewNotes;
	   MessageDlg(L"Taphonomic System notes updated.", mtInformation, TMsgDlgButtons() << mbOK, 0);
	   }
	 else {
	   UnicodeString msg = L"Update aborted";
	   if (!ErrorMsg.IsEmpty())
		 msg += (L": " + ErrorMsg);
	   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   }
	 }
}
//---------------------------------------------------------------------------

void __fastcall TEditTaphonomyForm::cxMemo1PropertiesChange(TObject *Sender)
{
   cxButton16->Enabled = !SameText(cxMemo1->Text, TaphSystemNotes.Notes);
   cxLabel10->Visible = cxMemo1->Text.IsEmpty();
}
//---------------------------------------------------------------------------

void __fastcall TEditTaphonomyForm::cxComboBox1PropertiesChange(TObject *Sender)
{
   cxButton1->Enabled = !cxComboBox1->Text.IsEmpty();
}
//---------------------------------------------------------------------------

void __fastcall TEditTaphonomyForm::ipsJSONS1SSLServerAuthentication(TObject *Sender,
          TipsJSONSSSLServerAuthenticationEventParams *e)
{
   e->Accept = true;
}
//---------------------------------------------------------------------------

