//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TIEdtMod.h"
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
#pragma link "cxDropDownEdit"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "cxButtons"
#pragma link "cxListBox"
#pragma link "ipshttps"
#pragma link "ipwjson"
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
TEditModifiersForm *EditModifiersForm;
TEditUnitsForm *EditUnitsForm;
TEditContextsForm *EditContextsForm;
TEditFaciesForm *EditFaciesForm;
TEditDepAgentsForm *EditDepAgentsForm;
//---------------------------------------------------------------------------
__fastcall TEditModifiersForm::TEditModifiersForm(TComponent* Owner)
        : TForm(Owner)
{
   if (tiLicense->Type() != verNEOTOMASTEWARD) {
	 cxButton8->Visible = false;
	 FlowPanel3->Width = 3*cxButton5->Width + 1;
	 FlowPanel3->Left = (Width - FlowPanel3->Width)/2 + 1;
	 StatusBar1->Visible = false;
	 Height -= StatusBar1->Height;
   	 }
}
//---------------------------------------------------------------------------

void __fastcall TEditModifiersForm::cxListBox1Click(TObject *Sender)
{
   UnicodeString DatasetType = cxListBox1->Items->Strings[cxListBox1->ItemIndex];
   SetModifiers(Modifiers[DatasetType]);
}
//---------------------------------------------------------------------------

void __fastcall TEditModifiersForm::cxListBox2Click(TObject *Sender)
{
   cxButton4->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TEditModifiersForm::cxComboBox1PropertiesChange(TObject *Sender)
{
   cxButton1->Enabled = !cxComboBox1->Text.IsEmpty();
}
//---------------------------------------------------------------------------

void __fastcall TEditModifiersForm::cxTextEdit1PropertiesChange(TObject *Sender)
{
   cxButton3->Enabled = !cxTextEdit1->Text.IsEmpty();
}
//---------------------------------------------------------------------------

void __fastcall TEditModifiersForm::cxButton1Click(TObject *Sender)
{
   if (!cxComboBox1->Text.IsEmpty()) {
	 UnicodeString DatasetType = cxComboBox1->Text.LowerCase();
	 if (cxListBox1->Items->IndexOf(DatasetType) > -1) {
	   UnicodeString msg = "Dataset type «" + DatasetType + "» is already in list.";
	   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   FocusControl(cxComboBox1);
	   return;
	   }
	 set<UnicodeString> Units;
	 Modifiers[DatasetType] = Units;
	 cxListBox1->Items->Add(DatasetType);
	 cxListBox1->ItemIndex = cxListBox1->Items->IndexOf(DatasetType);
	 cxListBox2->Items->Clear();
	 cxComboBox1->Clear();
	 cxButton1->Enabled = false;
	 cxButton2->Enabled = true;
	 cxButton7->Enabled = true;
	 cxButton5->Enabled = true;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TEditModifiersForm::cxButton2Click(TObject *Sender)
{
   int ItemIndex = cxListBox1->ItemIndex;
   UnicodeString DatasetType = cxListBox1->Items->Strings[ItemIndex];
   Modifiers.erase(DatasetType);
   cxListBox1->Items->Delete(ItemIndex);
   if (cxListBox1->Count == 0) {
	 cxButton2->Enabled = false;
	 cxListBox2->Clear();
	 }
   else {
	 cxListBox1->ItemIndex = (ItemIndex < cxListBox1->Count) ? ItemIndex : ItemIndex-1;
	 DatasetType = cxListBox1->Items->Strings[cxListBox1->ItemIndex];
	 SetModifiers(Modifiers[DatasetType]);
	 }
   cxButton4->Enabled = false;
   cxButton7->Enabled = true;
   cxButton5->Enabled = true;
}
//---------------------------------------------------------------------------

// add modifier
void __fastcall TEditModifiersForm::cxButton3Click(TObject *Sender)
{
   if (cxListBox1->ItemIndex == -1) {
	 MessageDlg("Dataset type must be selected.", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 return;
	 }

   if (!cxTextEdit1->Text.IsEmpty()) {
	 UnicodeString Units = cxTextEdit1->Text;
	 if (SpeedButton2->Down)
	   Units = Units.LowerCase();
	 if (cxListBox2->Items->IndexOf(Units) > -1) {
	   UnicodeString msg = "Measurement units «" + Units + "» are already in list.";
	   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   FocusControl(cxTextEdit1);
	   return;
	   }
	 cxListBox2->Items->Add(Units);
	 cxListBox2->ItemIndex = cxListBox2->Items->IndexOf(Units);
	 UnicodeString DatasetType = cxListBox1->Items->Strings[cxListBox1->ItemIndex];
	 Modifiers[DatasetType].insert(Units);
	 cxTextEdit1->Clear();
	 cxButton3->Enabled = false;
	 cxButton4->Enabled = true;
	 cxButton7->Enabled = true;
	 cxButton5->Enabled = true;
	 cxButton8->Enabled = true;
	 }
}
//---------------------------------------------------------------------------

// delete modifier
void __fastcall TEditModifiersForm::cxButton4Click(TObject *Sender)
{
   if (cxListBox1->ItemIndex == -1) {
	 MessageDlg("Dataset type must be selected.", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 return;
	 }
   UnicodeString DatasetType = cxListBox1->Items->Strings[cxListBox1->ItemIndex];
   int ItemIndex = cxListBox2->ItemIndex;
   UnicodeString Units = cxListBox2->Items->Strings[ItemIndex];
   Modifiers[DatasetType].erase(Units);
   cxListBox2->Items->Delete(ItemIndex);
   if (cxListBox2->Count == 0)
	 cxButton4->Enabled = false;
   else
	 cxListBox2->ItemIndex = (ItemIndex < cxListBox2->Count) ? ItemIndex : ItemIndex-1;

   cxButton7->Enabled = true;
   cxButton5->Enabled = true;
}
//---------------------------------------------------------------------------

// save
void __fastcall TEditModifiersForm::cxButton7Click(TObject *Sender)
{
   Save();
}
//---------------------------------------------------------------------------

// finish
void __fastcall TEditModifiersForm::cxButton5Click(TObject *Sender)
{
   return;
}
//---------------------------------------------------------------------------

void TEditModifiersForm::SetModifiers(set<UnicodeString>& Items)
{
   cxListBox2->Items->Clear();
   set<UnicodeString>::iterator itr;
   for (itr = Items.begin(); itr != Items.end(); itr++)
	 cxListBox2->Items->Add(*itr);

   if (cxListBox2->Count > 0) {
	 cxListBox2->ItemIndex = 0;
	 cxButton4->Enabled = true;
	 }
   else
	 cxButton4->Enabled = false;
   cxButton2->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TEditModifiersForm::cxButton8Click(TObject *Sender)
{
   return;
}
//---------------------------------------------------------------------------

bool TEditModifiersForm::ValidateDatasetType(UnicodeString DatasetType, vector<int>& DatasetTypeIDs)
{
   DatasetTypeIDs.clear();
   NeotomaDatasetTypesTable DatasetTypes(ipsJSONS1, TcpClient1);
   StatusBar1->SimpleText = DatasetTypes.WebServiceName();
   bool rv = false;
   if (DatasetTypes.Execute()) {
     NeotomaDatasetTypes  = DatasetTypes.Items;
	 rv = true;
	 map<int, UnicodeString>::iterator itr;
	 map<int, UnicodeString>::iterator begin = DatasetTypes.Items.begin();
	 map<int, UnicodeString>::iterator end = DatasetTypes.Items.end();
	 itr = begin;
	 while (itr != end) {
	   if (ContainsText(itr->second, DatasetType))
		 DatasetTypeIDs.push_back(itr->first);
	   itr++;
	   }
	 }
   return rv;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

__fastcall TEditUnitsForm::TEditUnitsForm(VARIABLELOOKUP* var_lookup,
	TStrings* DatasetTypes, UnicodeString DatasetType, TComponent* Owner)
	: TEditModifiersForm(Owner)
{
   Caption = L"Edit Units";
   Label2->Caption = L"Units";
   Label4->Caption = L"New Units:";
   VarLookup = var_lookup;
   UnitLookup = VarLookup->GetUnitLookup();
   Modifiers = UnitLookup->Units;

   //map<UnicodeString, set<UnicodeString> > Modifiers;    // DatasetType, Units
   map<UnicodeString, set<UnicodeString> >::iterator itr;
   map<UnicodeString, set<UnicodeString> >::iterator begin = Modifiers.begin();
   map<UnicodeString, set<UnicodeString> >::iterator end = Modifiers.end();
   for (itr = begin; itr != end; itr++)
	 cxListBox1->Items->Add(itr->first);
   cxListBox1->ItemIndex = Math::Max(0, cxListBox1->Items->IndexOf(DatasetType));

   for (int i=0; i<DatasetTypes->Count; i++) {
	 UnicodeString DatasetType = DatasetTypes->Strings[i];
	 if (!ContainsText(DatasetType, L"surface sample") && cxListBox1->Items->IndexOf(DatasetType) == -1)
	   cxComboBox1->Properties->Items->Add(DatasetType.LowerCase());
	 }

   DatasetType = cxListBox1->Items->Strings[cxListBox1->ItemIndex];
   SetModifiers(Modifiers[DatasetType]);
}
//---------------------------------------------------------------------------

// Ok button
void __fastcall TEditUnitsForm::cxButton5Click(TObject *Sender)
{
   if (cxButton7->Enabled) {
	 if (MessageDlg("Save changes to lookup file?", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes)
	   Save();
	 else
	   UnitLookup->Units = Modifiers;
	 }
}
//---------------------------------------------------------------------------

void TEditUnitsForm::Save(void)
{
   UnitLookup->Units = Modifiers;
   UnicodeString PathName = UnitLookup->GetPathName();
   if (SaveVariableModifiers(MOD_UNIT, PathName, VarLookup, this)) {
	 VarLookup->SetUnitPath(PathName);
	 cxButton7->Enabled = false;
	 }
}
//---------------------------------------------------------------------------

// upload button
void __fastcall TEditUnitsForm::cxButton8Click(TObject *Sender)
{
   UnicodeString msg = L"Uploads will be for current Dataset Type only.";
   msg += L"\nOnly new measurement units will be uploaded.\nDeletions will not be made.";
   MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);

   if (!Login->IsLoggedIn) {
	 NeotomaLoginForm = new TNeotomaLoginForm(this);
	 NeotomaLoginForm->ShowModal();
	 delete NeotomaLoginForm;
	 }
   if (Login->IsLoggedIn) {
	 UploadUnits();
	 Screen->Cursor = crDefault;
	 }
}
//---------------------------------------------------------------------------

void TEditUnitsForm::UploadUnits(void)
{
   UnicodeString msg;
   vector<int> DatasetTypeIDs;  // accommodates surface samples

   Screen->Cursor = crHourGlass;
   UnicodeString DatasetType = cxListBox1->Items->Strings[cxListBox1->ItemIndex];

   // validate DatasetType
   if (!ValidateDatasetType(DatasetType, DatasetTypeIDs))
	 return;
   if (DatasetTypeIDs.size() == 0) {
	 msg = L"«" + DatasetType + L"» is not a valid Neotoma Dataset Type! ";
	 msg += L"\nElements cannot be uploaded for this Dataset Type.";
	 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
	 return;
	 }
   if (!ValidateUnits(DatasetTypeIDs))
	 return;
}

//---------------------------------------------------------------------------
bool TEditUnitsForm::ValidateUnits(vector<int>& DatasetTypeIDs)
{
   UnicodeString msg;

   vector<UnicodeString> NewElements;
   UnicodeString DatasetType = cxListBox1->Items->Strings[cxListBox1->ItemIndex];

   map<UnicodeString, int> AllUnits;
   vector<UnicodeString> NewUnits;
   NeotomaVariableUnitsTable VariableUnits(ipsJSONS1, TcpClient1);
   StatusBar1->SimpleText = VariableUnits.WebServiceName();
   if (VariableUnits.Execute()) {
      map<int, UnicodeString>::iterator itr;
	  map<int, UnicodeString>::iterator begin = VariableUnits.Items.begin();
	  map<int, UnicodeString>::iterator end = VariableUnits.Items.end();
	  //AllUnits = VariableUnits.Items;
	  for (itr = begin; itr != end; itr++)
		AllUnits[itr->second] = itr->first;
	  for (int i=0; i<cxListBox2->Count; i++) {
		UnicodeString Units = cxListBox2->Items->Strings[i];
		begin = VariableUnits.Items.begin();
		end = VariableUnits.Items.end();
		bool found = false;
		for (itr = begin; itr != end; itr++) {
		  if (SameText(Units,itr->second)) {
			found = true;
			break;
			}
		  }
		if (!found)
		  NewUnits.push_back(Units);
		}
	 }
   else
	 return false;


   if (NewUnits.size() > 0) {
	 // upload new units
	 vector<int> newids;
	 UnicodeString ErrorMsg;
	 for (unsigned int i=0; i<NewUnits.size(); i++) {
	   newids.clear();
	   // insert new units into VariableUnits table
	   msg = L"Upload new measurement units «" + NewUnits[i] + L"» to Neotoma?";
	   if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes) {
		 InsertData InsertUnits(L"InsertVariableUnits", 1, ipsHTTPS1, ipsJSONS1, TcpClient1);
		 InsertUnits.Add(L"UNITS", NewUnits[i]);
		 StatusBar1->SimpleText = L"InsertVariableUnits";
		 InsertUnits.PostData();
		 if (InsertUnits.Post(newids, ErrorMsg)) {
		   if (newids.size() == 1) {
			 AllUnits[NewUnits[i]] = newids[0];
			 }
		   else {
			 msg = L"Error inserting into VariableUnits table!";
			 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			 return false;
			 }
		   }
		 else {
		   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   return false;
		   }
		 }
	   }
	 }

   // check if any Units, DatasetType combination needs to be added to
   // UnitsDatasetTypes table
   for (unsigned int i=0; i<DatasetTypeIDs.size(); i++) {
	 NeotomaVariableUnitsTableByDatasetTypeID DatasetUnits(ipsJSONS1, TcpClient1);
	 DatasetUnits.AddParam(L"DATASETTYPEID", DatasetTypeIDs[i]);
	 StatusBar1->SimpleText = DatasetUnits.WebServiceName();
	 int Uploaded = 0;
	 UnicodeString LastUnitsUploaded;
	 if (DatasetUnits.Execute()) {
	   for (int j=0; j<cxListBox2->Count; j++) {
		 UnicodeString Units = cxListBox2->Items->Strings[j];
		 if (DatasetUnits.Items.count(Units) == 0) {
		   InsertData InsertUnitsDatasetType(L"InsertUnitsDatasetTypes", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
		   InsertUnitsDatasetType.Add(L"DATASETTYPEID", DatasetTypeIDs[i], -1);
		   InsertUnitsDatasetType.Add(L"VARIABLEUNITSID", AllUnits[Units], -1);
		   StatusBar1->SimpleText = L"InsertUnitsDatasetTypes";
		   InsertUnitsDatasetType.PostData();
		   UnicodeString ErrorMsg;
		   if (!InsertUnitsDatasetType.Post(ErrorMsg)) {
			 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			 return false;
			 }
		   else {
			 Uploaded++;
			 LastUnitsUploaded = Units;
			 }
		   }
		 }
	   if (Uploaded == 1) {
		 msg = L"Measurement units «" + LastUnitsUploaded + L"» added to Dataset Type «" + NeotomaDatasetTypes[DatasetTypeIDs[i]] + L"»";
		 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
		 }
	   else if (Uploaded > 1) {
		 msg = L"Measurement units added to Dataset Type «" + NeotomaDatasetTypes[DatasetTypeIDs[i]] + L"»";
		 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
		 }
	   }
	 else
	   return false;
	 }
   return true;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

__fastcall TEditContextsForm::TEditContextsForm(VARIABLELOOKUP* var_lookup,
	TStrings* DatasetTypes, UnicodeString DatasetType, TComponent* Owner)
	: TEditModifiersForm(Owner)
{
   Caption = L"Edit Contexts";
   Label2->Caption = L"Contexts";
   Label4->Caption = L"New Context:";
   VarLookup = var_lookup;
   ContextLookup = VarLookup->GetContextLookup();
   Modifiers = ContextLookup->Contexts;

   //map<UnicodeString, set<UnicodeString> > Modifiers;    // DatasetType, Contexts
   map<UnicodeString, set<UnicodeString> >::iterator itr;
   map<UnicodeString, set<UnicodeString> >::iterator begin = Modifiers.begin();
   map<UnicodeString, set<UnicodeString> >::iterator end = Modifiers.end();
   for (itr = begin; itr != end; itr++)
	 cxListBox1->Items->Add(itr->first);
   cxListBox1->ItemIndex = Math::Max(0, cxListBox1->Items->IndexOf(DatasetType));

   for (int i=0; i<DatasetTypes->Count; i++) {
	 UnicodeString DatasetType = DatasetTypes->Strings[i];
	 if (!ContainsText(DatasetType, L"surface sample") && cxListBox1->Items->IndexOf(DatasetType) == -1)
	   cxComboBox1->Properties->Items->Add(DatasetType.LowerCase());
	 }

   DatasetType = cxListBox1->Items->Strings[cxListBox1->ItemIndex];
   SetModifiers(Modifiers[DatasetType]);
}
//---------------------------------------------------------------------------

// Ok button
void __fastcall TEditContextsForm::cxButton5Click(TObject *Sender)
{
   if (cxButton7->Enabled) {
	 if (MessageDlg("Save changes to lookup file?", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes)
	   Save();
	 else
	   ContextLookup->Contexts = Modifiers;
	 }
}
//---------------------------------------------------------------------------

void TEditContextsForm::Save(void)
{
   ContextLookup->Contexts = Modifiers;
   UnicodeString PathName = ContextLookup->GetPathName();
   if (SaveVariableModifiers(MOD_CONTEXT, PathName, VarLookup, this)) {
	 VarLookup->SetContextPath(PathName);
	 cxButton7->Enabled = false;
	 }
}
//---------------------------------------------------------------------------

// upload button
void __fastcall TEditContextsForm::cxButton8Click(TObject *Sender)
{
   UnicodeString msg = L"Uploads will be for current Dataset Type only.";
   msg += L"\nOnly new contexts will be uploaded.\nDeletions will not be made.";
   MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);

   if (!Login->IsLoggedIn) {
	 NeotomaLoginForm = new TNeotomaLoginForm(this);
	 NeotomaLoginForm->ShowModal();
	 delete NeotomaLoginForm;
	 }
   if (Login->IsLoggedIn) {
	 UploadContexts();
	 Screen->Cursor = crDefault;
	 }
}
//---------------------------------------------------------------------------

void TEditContextsForm::UploadContexts(void)
{
   UnicodeString msg;
   vector<int> DatasetTypeIDs;  // accommodates surface samples

   Screen->Cursor = crHourGlass;
   UnicodeString DatasetType = cxListBox1->Items->Strings[cxListBox1->ItemIndex];

   // validate DatasetType
   if (!ValidateDatasetType(DatasetType, DatasetTypeIDs))
	 return;
   if (DatasetTypeIDs.size() == 0) {
	 msg = L"«" + DatasetType + L"» is not a valid Neotoma Dataset Type! ";
	 msg += L"\nElements cannot be uploaded for this Dataset Type.";
	 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
	 return;
	 }
   if (!ValidateContexts(DatasetTypeIDs))
	 return;
}

//---------------------------------------------------------------------------
bool TEditContextsForm::ValidateContexts(vector<int>& DatasetTypeIDs)
{
   UnicodeString msg;

   vector<UnicodeString> NewElements;
   UnicodeString DatasetType = cxListBox1->Items->Strings[cxListBox1->ItemIndex];

   map<UnicodeString, int> AllContexts;
   vector<UnicodeString> NewContexts;
   NeotomaVariableContextsTable VariableContexts(ipsJSONS1, TcpClient1);
   StatusBar1->SimpleText = VariableContexts.WebServiceName();
   if (VariableContexts.Execute()) {
	  map<int, UnicodeString>::iterator itr;
	  map<int, UnicodeString>::iterator begin = VariableContexts.Items.begin();
	  map<int, UnicodeString>::iterator end = VariableContexts.Items.end();
	  for (itr = begin; itr != end; itr++)
		AllContexts[itr->second] = itr->first;
	  for (int i=0; i<cxListBox2->Count; i++) {
		UnicodeString Contexts = cxListBox2->Items->Strings[i];
		begin = VariableContexts.Items.begin();
		end = VariableContexts.Items.end();
		bool found = false;
		for (itr = begin; itr != end; itr++) {
		  if (SameText(Contexts,itr->second)) {
			found = true;
			break;
			}
		  }
		if (!found)
		  NewContexts.push_back(Contexts);
		}
	 }
   else
	 return false;

   if (NewContexts.size() > 0) {
	 // upload new contexts
	 vector<int> newids;
	 UnicodeString ErrorMsg;
	 for (unsigned int i=0; i<NewContexts.size(); i++) {
	   newids.clear();
	   // insert new contexts into VariableContexts table
	   msg = L"Upload new context «" + NewContexts[i] + L"» to Neotoma?";
	   if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes) {
		 InsertData InsertContext(L"InsertVariableContext", 1, ipsHTTPS1, ipsJSONS1, TcpClient1);
		 InsertContext.Add(L"CONTEXT", NewContexts[i]);
		 StatusBar1->SimpleText = L"InsertVariableContext";
		 InsertContext.PostData();
		 if (InsertContext.Post(newids, ErrorMsg)) {
		   if (newids.size() == 1) {
			 AllContexts[NewContexts[i]] = newids[0];
			 }
		   else {
			 msg = L"Error inserting into VariableContexts table!";
			 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			 return false;
			 }
		   }
		 else {
		   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   return false;
		   }
		 }
	   }
	 }

   // check if any context, DatasetType combination needs to be added to
   // ContextsDatasetTypes table
   for (unsigned int i=0; i<DatasetTypeIDs.size(); i++) {
	 NeotomaVariableContextsTableByDatasetTypeID DatasetContexts(ipsJSONS1, TcpClient1);
	 DatasetContexts.AddParam(L"DATASETTYPEID", DatasetTypeIDs[i]);
	 StatusBar1->SimpleText = DatasetContexts.WebServiceName();
	 int Uploaded = 0;
	 UnicodeString LastContextUploaded;
	 if (DatasetContexts.Execute()) {
	   for (int j=0; j<cxListBox2->Count; j++) {
		 UnicodeString Context = cxListBox2->Items->Strings[j];
		 if (DatasetContexts.Items.count(Context) == 0) {
		   InsertData InsertContextDatasetType(L"InsertContextDatasetTypes", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
		   InsertContextDatasetType.Add(L"DATASETTYPEID", DatasetTypeIDs[i], -1);
		   InsertContextDatasetType.Add(L"VARIABLECONTEXTID", AllContexts[Context], -1);
		   StatusBar1->SimpleText = L"InsertContextDatasetTypes";
		   InsertContextDatasetType.PostData();
		   UnicodeString ErrorMsg;
		   if (!InsertContextDatasetType.Post(ErrorMsg)) {
			 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			 return false;
			 }
		   else {
			 Uploaded++;
			 LastContextUploaded = Context;
			 }
		   }
		 }
	   if (Uploaded == 1) {
		 msg = L"Context «" + LastContextUploaded + L"» added to Dataset Type «" + NeotomaDatasetTypes[DatasetTypeIDs[i]] + L"»";
		 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
		 }
	   else if (Uploaded > 1) {
		 msg = L"Contexts added to Dataset Type «" + NeotomaDatasetTypes[DatasetTypeIDs[i]] + L"»";
		 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
		 }
	   }
	 else
	   return false;
	 }
   return true;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

__fastcall TEditFaciesForm::TEditFaciesForm(vector<UnicodeString>& facies_types,
		UnicodeString facies, TTilSpreadSheetForm* tssform, TComponent* Owner)
		: TEditModifiersForm(Owner)
{
   TSSForm = tssform;
   Caption = L"Edit Facies";
   Label2->Caption = L"Facies";
   Label4->Caption = L"New Facies:";
   cxButton8->Caption = L"Update";
   cxButton8->Enabled = true;
   SpeedButton2->Visible = false;

   Label1->Visible = false;
   cxListBox1->Visible = false;
   Label3->Visible = false;
   cxComboBox1->Visible = false;
   FlowPanel1->Visible = false;

   Label2->Left = 8;
   cxListBox2->Left = 8;
   Label4->Left = 8;
   cxTextEdit1->Left = 8;
   SpeedButton2->Left = 165;

   cxListBox2->Width = 180;
   cxTextEdit1->Width = 180;
   FlowPanel2->Left = 74;
   FlowPanel2->Top = 225;
   cxTextEdit1->Top = 199;
   Label4->Top = 184;
   cxListBox2->Height = 148;

   FlowPanel3->Left = 200;
   FlowPanel3->Top = 32;
   FlowPanel3->AutoWrap = true;
   FlowPanel3->Width = 69;
   FlowPanel3->Height = 120;

   Width = 284;

   for (unsigned int i=0; i<facies_types.size(); i++)
	 cxListBox2->Items->Add(facies_types[i]);
   if (!facies.IsEmpty()) {
	 if (find(facies_types.begin(), facies_types.end(), facies) == facies_types.end())
	   cxListBox1->ItemIndex = 0;
	 else
	   cxListBox1->ItemIndex = cxListBox1->Items->IndexOf(facies);
	 cxTextEdit1->Text = facies;
	 }
   else
     cxListBox1->ItemIndex = 0;

}
//---------------------------------------------------------------------------

// add item
void __fastcall TEditFaciesForm::cxButton3Click(TObject *Sender)
{
   if (!cxTextEdit1->Text.IsEmpty()) {
	 UnicodeString facies = cxTextEdit1->Text;
	 if (cxListBox2->Items->IndexOf(facies) > -1) {
	   UnicodeString msg = "Facies «" + facies + "» is already in list!";
	   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   FocusControl(cxTextEdit1);
	   return;
	   }
	 cxListBox2->Items->Add(facies);
	 cxListBox2->ItemIndex = cxListBox2->Items->IndexOf(facies);
	 cxButton3->Enabled = false;
	 cxButton4->Enabled = true;
	 cxButton7->Enabled = true;
	 cxButton5->Enabled = true;
	 cxButton8->Enabled = true;
	 }
}
//---------------------------------------------------------------------------

// delete item
void __fastcall TEditFaciesForm::cxButton4Click(TObject *Sender)
{
   int ItemIndex = cxListBox2->ItemIndex;
   UnicodeString facies = cxListBox2->Items->Strings[ItemIndex];
   cxListBox2->Items->Delete(ItemIndex);
   if (cxListBox2->Count == 0)
	 cxButton4->Enabled = false;
   else
	 cxListBox2->ItemIndex = (ItemIndex < cxListBox2->Count) ? ItemIndex : ItemIndex-1;

   cxButton7->Enabled = true;
   cxButton5->Enabled = true;
}
//---------------------------------------------------------------------------

// Save Button
void TEditFaciesForm::Save(void)
{
   TSSForm->FaciesTypes.clear();
   for (int i=0; i<cxListBox2->Count; i++)
	 TSSForm->FaciesTypes.push_back(cxListBox2->Items->Strings[i]);
   TSSForm->SaveLookupFile();
   cxButton7->Enabled = false;
   MessageDlg("Lookup file saved!", mtInformation, TMsgDlgButtons() << mbOK, 0);
}
//---------------------------------------------------------------------------

// Ok button
void __fastcall TEditFaciesForm::cxButton5Click(TObject *Sender)
{
   if (cxButton7->Enabled) {
	 if (MessageDlg("Save changes to lookup file?", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes)
	   Save();
	 }
}
//---------------------------------------------------------------------------

// update button
void __fastcall TEditFaciesForm::cxButton8Click(TObject *Sender)
{
   if (!Login->IsLoggedIn) {
	 NeotomaLoginForm = new TNeotomaLoginForm(this);
	 NeotomaLoginForm->ShowModal();
	 delete NeotomaLoginForm;
	 }
   if (Login->IsLoggedIn) {
	 UpdateFacies();
	 Screen->Cursor = crDefault;
	 }
}
//---------------------------------------------------------------------------

void TEditFaciesForm::UpdateFacies(void)
{
   UnicodeString msg;

   NeotomaFaciesTypesTable FaciesTable(ipsJSONS1, TcpClient1);
   StatusBar1->SimpleText = FaciesTable.WebServiceName();
   if (!FaciesTable.Execute())
	 return;

   // make lookup maps both ways and ensure all names lowercase for comparisons
   map<UnicodeString,int> FaciesNameMap;
   map<int,UnicodeString>::iterator id_itr;
   map<UnicodeString,int>::iterator name_itr;
   for (id_itr = FaciesTable.Items.begin(); id_itr != FaciesTable.Items.end(); id_itr++) {
	 UnicodeString Facies = id_itr->second.LowerCase();
	 FaciesNameMap[Facies] = id_itr->first;
	 }

   // check for deletions
   bool all_found = true;
   for (name_itr = FaciesNameMap.begin(); name_itr != FaciesNameMap.end() ; name_itr++) {
	 if (cxListBox2->Items->IndexOf(name_itr->first) == -1) {
	   all_found = false;
	   break;
	   }
	 }
   if (!all_found) {
	 msg = L"Facies have been deleted, or local lookup file does not contain all facies in the Neotoma FaciesTypes table.";
	 msg += L"\nFacies cannot be deleted from Neotoma with this interface.";
	 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
	 }

   vector<UnicodeString> NewFacies;
   for (int i=0; i<cxListBox2->Count; i++) {
	 UnicodeString Facies = cxListBox2->Items->Strings[i].LowerCase();
	 if (FaciesNameMap.find(Facies) == FaciesNameMap.end()) {
	   NewFacies.push_back(Facies);
	   }
	 }

   if (NewFacies.size() > 0) {
	 vector<int> newids;
	 UnicodeString ErrorMsg;
	 UnicodeString Facies1;
	 int NewFaciesUploaded = 0;
	 InsertData InsertFacies(L"InsertFaciesTypes", 1, ipsHTTPS1, ipsJSONS1, TcpClient1);

	 for (unsigned int i=0; i<NewFacies.size(); i++) {
	   msg = L"Upload new facies type «" + NewFacies[i] + L"» to Neotoma?";
	   if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes) {
		 NewFaciesUploaded++;
		 InsertFacies.Add(L"FACIES", NewFacies[i]);
		 if (NewFaciesUploaded ==  1)
		   Facies1 = NewFacies[i];
		 }
	   }
	 if (NewFaciesUploaded > 0) {
	   Screen->Cursor = crHourGlass;
	   StatusBar1->SimpleText = L"InsertFaciesTypes";
	   InsertFacies.PostData();
	   if (InsertFacies.Post(newids, ErrorMsg)) {
		 Screen->Cursor = crDefault;
		 if ((int)newids.size() == NewFaciesUploaded) {
		   if (NewFaciesUploaded == 1)
			 msg = L"Success! New facies type «" + Facies1 + L"» uploaded: ID = " + IntToStr(newids[0]) + L".";
		   else
			 msg = L"Success! " + IntToStr(NewFaciesUploaded) + L" new facies types uploaded.";
		   for (unsigned int i=0; i<newids.size(); i++)  {
			 msg = L"New facies type «" + NewFacies[i] + L"» uploaded: ID = " + IntToStr(newids[i]) + L".";
			 OutputMessages.push_back(msg);
			 }
		   MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
		   }
		 else {
		   msg = L"Error inserting into FaciesTypes table!";
		   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   }
		 }
	   else {
		 Screen->Cursor = crDefault;
		 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 }
	   }
	 else {
	   msg = L"No new facies types uploaded.";
	   MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
	   }
	 }
   else {
	 msg = L"All facies in the local list are in the Neotoma FaciesTypes table.";
	 msg += L"\nNo new facies uploaded.";
	 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
	 }
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

__fastcall TEditDepAgentsForm::TEditDepAgentsForm(vector<UnicodeString>& dep_agents,
		UnicodeString dep_agent, TTilSpreadSheetForm* tssform, TComponent* Owner)
		: TEditModifiersForm(Owner)
{
   TSSForm = tssform;
   Caption = L"Edit Depositional Agents";
   Label2->Caption = L"Depositional Agent";
   Label4->Caption = L"New Depositional Agent:";
   cxButton8->Caption = L"Update";
   cxButton8->Enabled = true;
   SpeedButton2->Visible = false;

   Label1->Visible = false;
   cxListBox1->Visible = false;
   Label3->Visible = false;
   cxComboBox1->Visible = false;
   FlowPanel1->Visible = false;

   Label2->Left = 8;
   cxListBox2->Left = 8;
   Label4->Left = 8;
   cxTextEdit1->Left = 8;
   SpeedButton2->Left = 165;

   cxListBox2->Width = 180;
   cxTextEdit1->Width = 180;
   FlowPanel2->Left = 74;
   FlowPanel2->Top = 225;
   cxTextEdit1->Top = 199;
   Label4->Top = 184;
   cxListBox2->Height = 148;

   FlowPanel3->Left = 200;
   FlowPanel3->Top = 32;
   FlowPanel3->AutoWrap = true;
   FlowPanel3->Width = 69;
   FlowPanel3->Height = 120;

   Width = 284;

   for (unsigned int i=0; i<dep_agents.size(); i++)
	 cxListBox2->Items->Add(dep_agents[i]);
   if (!dep_agent.IsEmpty()) {
	 if (find(dep_agents.begin(), dep_agents.end(), dep_agent) == dep_agents.end())
	   cxListBox1->ItemIndex = 0;
	 else
	   cxListBox1->ItemIndex = cxListBox1->Items->IndexOf(dep_agent);
	 cxTextEdit1->Text = dep_agent;
	 }
   else
     cxListBox1->ItemIndex = 0;

}
//---------------------------------------------------------------------------

// add item
void __fastcall TEditDepAgentsForm::cxButton3Click(TObject *Sender)
{
   if (!cxTextEdit1->Text.IsEmpty()) {
	 UnicodeString DepAgent = cxTextEdit1->Text;
	 if (cxListBox2->Items->IndexOf(DepAgent) > -1) {
	   UnicodeString msg = "Depositional agent «" + DepAgent + "» is already in list!";
	   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   FocusControl(cxTextEdit1);
	   return;
	   }
	 cxListBox2->Items->Add(DepAgent);
	 cxListBox2->ItemIndex = cxListBox2->Items->IndexOf(DepAgent);
	 cxButton3->Enabled = false;
	 cxButton4->Enabled = true;
	 cxButton7->Enabled = true;
	 cxButton5->Enabled = true;
	 cxButton8->Enabled = true;
	 }
}
//---------------------------------------------------------------------------

// delete item
void __fastcall TEditDepAgentsForm::cxButton4Click(TObject *Sender)
{
   int ItemIndex = cxListBox2->ItemIndex;
   UnicodeString DepAgent = cxListBox2->Items->Strings[ItemIndex];
   cxListBox2->Items->Delete(ItemIndex);
   if (cxListBox2->Count == 0)
	 cxButton4->Enabled = false;
   else
	 cxListBox2->ItemIndex = (ItemIndex < cxListBox2->Count) ? ItemIndex : ItemIndex-1;

   cxButton7->Enabled = true;
   cxButton5->Enabled = true;
}
//---------------------------------------------------------------------------

// Save Button
void TEditDepAgentsForm::Save(void)
{
   TSSForm->DepAgents.clear();
   for (int i=0; i<cxListBox2->Count; i++)
	 TSSForm->DepAgents.push_back(cxListBox2->Items->Strings[i]);
   TSSForm->SaveLookupFile();
   cxButton7->Enabled = false;
   MessageDlg("Lookup file saved!", mtInformation, TMsgDlgButtons() << mbOK, 0);
}
//---------------------------------------------------------------------------

// Ok button
void __fastcall TEditDepAgentsForm::cxButton5Click(TObject *Sender)
{
   if (cxButton7->Enabled) {
	 if (MessageDlg("Save changes to lookup file?", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes)
	   Save();
	 }
}
//---------------------------------------------------------------------------

// update button
void __fastcall TEditDepAgentsForm::cxButton8Click(TObject *Sender)
{
   if (!Login->IsLoggedIn) {
	 NeotomaLoginForm = new TNeotomaLoginForm(this);
	 NeotomaLoginForm->ShowModal();
	 delete NeotomaLoginForm;
	 }
   if (Login->IsLoggedIn) {
	 UpdateDepAgents();
	 Screen->Cursor = crDefault;
	 }
}
//---------------------------------------------------------------------------

void TEditDepAgentsForm::UpdateDepAgents(void)
{
   UnicodeString msg;

   NeotomaDepAgentsTable DepAgentsTable(ipsJSONS1, TcpClient1);
   StatusBar1->SimpleText = DepAgentsTable.WebServiceName();
   if (!DepAgentsTable.Execute())
	 return;

   // make lookup maps both ways and ensure all names lowercase for comparisons
   map<UnicodeString,int> DepAgentsNameMap;
   map<int,UnicodeString>::iterator id_itr;
   map<UnicodeString,int>::iterator name_itr;
   for (id_itr = DepAgentsTable.Items.begin(); id_itr != DepAgentsTable.Items.end(); id_itr++) {
	 UnicodeString DepAgent = id_itr->second.LowerCase();
	 DepAgentsNameMap[DepAgent] = id_itr->first;
	 }

   // check for deletions
   bool all_found = true;
   for (name_itr = DepAgentsNameMap.begin(); name_itr != DepAgentsNameMap.end() ; name_itr++) {
	 if (cxListBox2->Items->IndexOf(name_itr->first) == -1) {
	   all_found = false;
	   break;
	   }
	 }
   if (!all_found) {
	 msg = L"Depositional agents have been deleted, or local lookup file does not";
	 msg += L"\ncontain all Depositional agents in the Neotoma DepAgentTypes table.";
	 msg += L"\nDepositional agents cannot be deleted from Neotoma with this interface.";
	 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
	 }

   vector<UnicodeString> NewDepAgents;
   for (int i=0; i<cxListBox2->Count; i++) {
	 UnicodeString DepAgent = cxListBox2->Items->Strings[i].LowerCase();
	 if (DepAgentsNameMap.find(DepAgent) == DepAgentsNameMap.end()) {
	   NewDepAgents.push_back(DepAgent);
	   }
	 }

   if (NewDepAgents.size() > 0) {
	 vector<int> newids;
	 UnicodeString ErrorMsg;
	 UnicodeString DepAgent1;
	 int NewDepAgentsUploaded = 0;
	 InsertData InsertDepAgents(L"InsertDepAgentTypes", 1, ipsHTTPS1, ipsJSONS1, TcpClient1);

	 for (unsigned int i=0; i<NewDepAgents.size(); i++) {
	   msg = L"Upload new depositional agent «" + NewDepAgents[i] + L"» to Neotoma?";
	   if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes) {
		 NewDepAgentsUploaded++;
		 InsertDepAgents.Add(L"DEPAGENT", NewDepAgents[i]);
		 if (NewDepAgentsUploaded ==  1)
		   DepAgent1 = NewDepAgents[i];
		 }
	   }
	 if (NewDepAgentsUploaded > 0) {
	   Screen->Cursor = crHourGlass;
	   StatusBar1->SimpleText = L"InsertDepAgentTypes";
	   InsertDepAgents.PostData();
	   if (InsertDepAgents.Post(newids, ErrorMsg)) {
		 Screen->Cursor = crDefault;
		 if ((int)newids.size() == NewDepAgentsUploaded) {
		   if (NewDepAgentsUploaded == 1)
			 msg = L"Success! New depositional agent «" + DepAgent1 + L"» uploaded: ID = " + IntToStr(newids[0]) + L".";
		   else
			 msg = L"Success! " + IntToStr(NewDepAgentsUploaded) + L" new depositional agents uploaded.";
           for (unsigned int i=0; i<newids.size(); i++)  {
			 msg = L"New depositional agent «" + NewDepAgents[i] + L"» uploaded: ID = " + IntToStr(newids[i]) + L".";
			 OutputMessages.push_back(msg);
			 }
		   MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
		   }
		 else {
		   msg = L"Error inserting into DepAgentTypes table!";
		   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   }
		 }
	   else {
		 Screen->Cursor = crDefault;
		 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 }
	   }
	 else {
	   msg = L"No new depositional agents uploaded.";
	   MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
	   }
	 }
   else {
	 msg = L"All depositional agents in the local list are in the Neotoma DepAgentTypes table.";
	 msg += L"\nNo new depositional agents uploaded.";
	 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
	 }
}
//---------------------------------------------------------------------------

void __fastcall TEditModifiersForm::ipsJSONS1SSLServerAuthentication(TObject *Sender,
          TipsJSONSSSLServerAuthenticationEventParams *e)
{
   e->Accept = true;
}
//---------------------------------------------------------------------------

