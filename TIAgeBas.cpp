//---------------------------------------------------------------------------

#include <vcl.h>
#include "pch.h"
#pragma hdrstop

#include "TIAgeBas.h"
#ifndef TIVersionH
#include "TIVersion.h"
#endif
#ifndef TILookupH
#include "TILookup.h"
#endif
#ifndef TIJSONH
#include "TIJSON.h"
#endif
#ifndef TINeotomaH
#include "TINeotoma.h"
#endif
#ifndef TNLoginH
#include "TNLogin.h"
#endif
#ifndef TIPublH
#include "TIPubl.h"
#endif

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "ipshttps"
#pragma link "ipwjson"
#pragma link "AdvCGrid"
#pragma link "AdvGrid"
#pragma link "AdvObj"
#pragma link "BaseGrid"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxGroupBox"
#pragma link "cxLabel"
#pragma link "cxMemo"
#pragma link "cxTextEdit"
#pragma link "AdvControlDropDown"
#pragma link "AdvDropDown"
#pragma link "frmctrllink"
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
#pragma link "AdvUtil"
#pragma link "dxSkinOffice2016Colorful"
#pragma link "dxSkinOffice2016Dark"
#pragma link "dxSkinVisualStudio2013Blue"
#pragma link "dxSkinVisualStudio2013Dark"
#pragma link "dxSkinVisualStudio2013Light"
#pragma link "ipsjsons"
#pragma resource "*.dfm"
TChronControlForm *ChronControlForm;
//---------------------------------------------------------------------------
__fastcall TChronControlForm::TChronControlForm(UnicodeString caption, TTreeNode* node,
	bool is_rel_age, bool is_evt_age, TComponent* Owner) : TForm(Owner)
{
   Node = node;
   IsRelAge = is_rel_age;
   IsEvtAge = is_evt_age;
   Caption = caption;
   activated = false;
   EventID = -1;
   RelativeAgeID = -1;
   RelativeAgeUnitID = -1;

   //EditChronControl(cxTreeView1->Items->AddChild(CurrentNode, ""), L"Add Child Control");

   //L"Add Sibling Control"

   if (SameText(Caption, L"Edit Chronology Control"))
	 operation = abEdit;
   else if (SameText(Caption, L"Add Child Control"))
	 operation = abAddChild;
   else if (SameText(Caption, L"Add Sibling Control"))
	 operation = abAddSibling;
   else
	 operation = abOther;

   LabeledEdit1->Text = Node->Text;
   if (tiLicense->Type() == verNEOTOMASTEWARD) {
	 if (operation == abEdit)
	   cxButton3->Caption = L"Update";
	 }

   if (tiLicense->Type() != verNEOTOMASTEWARD ||
	   Node->Level == 0 ||
	   SameText(Node->Parent->Text, L"Relative time scale") ||
	   SameText(Node->Text, L"Event stratigraphic") ||
	   SameText(Node->Parent->Text, L"Event stratigraphic")) {
	 cxButton3->Visible = false;
	 FlowPanel1->Left += cxButton3->Width/2;
	 }

   if (operation == abAddChild) {
	 if (IsRelAge) {
	   LabeledEdit4->Visible = false;
	   LabeledEdit7->Visible = false;
	   Label3->Visible = true;
	   ComboBox1->Visible = true;
	   Memo1->Width = 225;
	   }
	 //else if (IsEvtAge && Node->Level > 2) {
	 //  ShowMessage(L"Add Event");
	 //  }
	 else if (!(IsEvtAge && Node->Level > 2)){
	   Panel1->Visible = false;
	   Panel2->Visible = false;
	   Height -= (Panel1->Height + Panel2->Height);
	   //if (cxButton3->Visible) {
	   //	 cxButton3->Visible = false;
	   //	 FlowPanel1->Left += cxButton3->Width/2;
	   //	 }
	   }
	 }
   else if (operation == abEdit) {
	 if (IsRelAge) {
	   LabeledEdit4->Visible = false;
	   LabeledEdit7->Visible = false;
	   if (Node->Data) {
		 UnicodeString clName = ((TObject*)Node->Data)->ClassName();
		 if (SameText(clName, L"RELATIVEAGE")) {
		   RELATIVEAGE* RelAge = (RELATIVEAGE*)Node->Data;
		   if (!IsNan(RelAge->C14AgeOlder))
			 LabeledEdit2->Text = FloatToStr(RelAge->C14AgeOlder);
		   if (!IsNan(RelAge->C14AgeYounger))
			 LabeledEdit3->Text = FloatToStr(RelAge->C14AgeYounger);
		   if (!IsNan(RelAge->CalAgeOlder))
			 LabeledEdit5->Text = FloatToStr(RelAge->CalAgeOlder);
		   if (!IsNan(RelAge->CalAgeYounger))
			 LabeledEdit6->Text = FloatToStr(RelAge->CalAgeYounger);
		   }
		 }
	   }
	 else if (IsEvtAge && Node->Level > 2) {
	   if (Node->Data) {
		 UnicodeString clName = ((TObject*)Node->Data)->ClassName();
		 if (SameText(clName, L"EVENT")) {
		   EVENT* Event = (EVENT*)Node->Data;
		   if (!IsNan(Event->C14AgeOlder))
			 LabeledEdit2->Text = FloatToStr(Event->C14AgeOlder);
		   if (!IsNan(Event->C14AgeYounger))
			 LabeledEdit3->Text = FloatToStr(Event->C14AgeYounger);
		   if (!IsNan(Event->C14Age))
			 LabeledEdit4->Text = FloatToStr(Event->C14Age);
		   if (!IsNan(Event->CalAgeOlder))
			 LabeledEdit5->Text = FloatToStr(Event->CalAgeOlder);
		   if (!IsNan(Event->CalAgeYounger))
			 LabeledEdit6->Text = FloatToStr(Event->CalAgeYounger);
		   if (!IsNan(Event->CalAge))
			 LabeledEdit7->Text = FloatToStr(Event->CalAge);
		   Memo1->Text =  Event->Notes;
		   }
		 }
	   }
	 else {
	   Panel1->Visible = false;
	   Panel2->Visible = false;
	   Height -= (Panel1->Height + Panel2->Height);
	   //if (cxButton3->Visible) {
	   //	 cxButton3->Visible = false;
	   //	 FlowPanel1->Left += cxButton3->Width/2;
	   //	 }
	   }
	 }

   if (!cxButton3->Visible) {
	 StatusBar1->Visible = false;
	 Height -= StatusBar1->Height;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TChronControlForm::FormActivate(TObject *Sender)
{
   Screen->Cursor = crHourGlass;
   if (!activated && tiLicense->Type() == verNEOTOMASTEWARD) {
	 if (operation == abAddChild) {
	   if (IsRelAge) {
		 TTreeNode* Parent = Node->Parent;
		 while (Parent->Level > 1)
		   Parent = Parent->Parent;
		 RelativeAgeScale = Parent->Text;
		 NeotomaRelativeAgeUnitsByAgeScale AgeUnits(ipsJSONS1, TcpClient1);
		 AgeUnits.AddParam(L"RELATIVEAGESCALE", RelativeAgeScale);
		 StatusBar1->SimpleText = AgeUnits.WebServiceName();
		 if (AgeUnits.Execute()) {
		   if (AgeUnits.Size() > 0) {
			 map<int,UnicodeString>::iterator itr;
			 for (itr = AgeUnits.Items.begin(); itr != AgeUnits.Items.end(); itr++) {
			   ComboBox1->Items->Add(itr->second);
			   AgeUnitIDs[itr->second] = itr->first;
			   }
			 ComboBox1->ItemIndex = 0;
			 }
		   }
		 }
	   /*
	   else if (IsEvtAge && Node->Level > 2) {
		 TTreeNode* Parent = Node->Parent;
		 while (Parent->Level > 1)
		   Parent = Parent->Parent;
		 EventType = Parent->Text;
		 }  */
	   }
	 else if (operation == abEdit) {
	   if (IsRelAge) {
		 NeotomaRelativeAgeByName RelativeAge(ipsJSONS1, TcpClient1);
		 RelativeAge.AddParam(L"RELATIVEAGE", Node->Text);
		 StatusBar1->SimpleText = RelativeAge.WebServiceName();
		 if (RelativeAge.Execute()) {
		   if (RelativeAge.Size() == 1) {
			 RelativeAgeID = RelativeAge.Items[0].RelativeAgeID;
			 RelativeAgeUnitID = RelativeAge.Items[0].RelativeAgeUnitID;
			 Memo1->Text = RelativeAge.Items[0].Notes;
			 if (RelativeAge.Items[0].C14AgeOlder.IsEmpty())
			   LabeledEdit2->Text = L"";
			 else
			   LabeledEdit2->Text = VarToStr(RelativeAge.Items[0].C14AgeOlder);
			 if (RelativeAge.Items[0].C14AgeYounger.IsEmpty())
			   LabeledEdit3->Text = L"";
			 else
			   LabeledEdit3->Text = VarToStr(RelativeAge.Items[0].C14AgeYounger);
			 if (RelativeAge.Items[0].CalAgeOlder.IsEmpty())
			   LabeledEdit5->Text = L"";
			 else
			   LabeledEdit5->Text = VarToStr(RelativeAge.Items[0].CalAgeOlder);
			 if (RelativeAge.Items[0].CalAgeYounger.IsEmpty())
			   LabeledEdit6->Text = L"";
			 else
			   LabeledEdit6->Text = VarToStr(RelativeAge.Items[0].CalAgeYounger);
			 NeotomaRelativeAgePublications RelAgePubs(ipsJSONS1, TcpClient1);
			 RelAgePubs.AddParam(L"RELATIVEAGEID", RelativeAgeID);
			 StatusBar1->SimpleText = RelAgePubs.WebServiceName();
			 if (RelAgePubs.Execute()) {
			   if (RelAgePubs.Size() > 0) {
				 AdvColumnGrid1->RowCount = RelAgePubs.Size() + 1;
				 for (unsigned int i=0, row=1; i<RelAgePubs.Size(); i++, row++) {
				   AdvColumnGrid1->Cells[0][row] = IntToStr(RelAgePubs.Items[i].PublicationID);
				   AdvColumnGrid1->Cells[1][row] = RelAgePubs.Items[i].Citation;
				   }
				 }
			   }
			 }
		   }
		 }
	   else if (IsEvtAge && Node->Level > 2) {
		 NeotomaEventByName Event(ipsJSONS1, TcpClient1);
		 Event.AddParam(L"EVENTNAME", Node->Text);
		 StatusBar1->SimpleText = Event.WebServiceName();
		 if (Event.Execute()) {
		   if (Event.Size() == 1) {
			 EventID = Event.Items[0].EventID;
			 Memo1->Text = Event.Items[0].Notes;
			 if (Event.Items[0].C14AgeOlder.IsEmpty())
			   LabeledEdit2->Text = L"";
			 else
			   LabeledEdit2->Text = VarToStr(Event.Items[0].C14AgeOlder);
			 if (Event.Items[0].C14AgeYounger.IsEmpty())
			   LabeledEdit3->Text = L"";
			 else
			   LabeledEdit3->Text = VarToStr(Event.Items[0].C14AgeYounger);
			 if (Event.Items[0].C14Age.IsEmpty())
			   LabeledEdit4->Text = L"";
			 else
			   LabeledEdit4->Text = VarToStr(Event.Items[0].C14Age);
			 if (Event.Items[0].CalAgeOlder.IsEmpty())
			   LabeledEdit5->Text = L"";
			 else
			   LabeledEdit5->Text = VarToStr(Event.Items[0].CalAgeOlder);
			 if (Event.Items[0].CalAgeYounger.IsEmpty())
			   LabeledEdit6->Text = L"";
			 else
			   LabeledEdit6->Text = VarToStr(Event.Items[0].CalAgeYounger);
			 if (Event.Items[0].CalAge.IsEmpty())
			   LabeledEdit7->Text = L"";
			 else
			   LabeledEdit7->Text = VarToStr(Event.Items[0].CalAge);

			 NeotomaEventPublications EventPubs(ipsJSONS1, TcpClient1);
			 EventPubs.AddParam(L"EVENTID", EventID);
			 StatusBar1->SimpleText = EventPubs.WebServiceName();
			 if (EventPubs.Execute()) {
			   if (EventPubs.Size() > 0) {
				 AdvColumnGrid1->RowCount = EventPubs.Size() + 1;
				 for (unsigned int i=0, row=1; i<EventPubs.Size(); i++, row++) {
				   AdvColumnGrid1->Cells[0][row] = IntToStr(EventPubs.Items[i].PublicationID);
				   AdvColumnGrid1->Cells[1][row] = EventPubs.Items[i].Citation;
				   }
				 }
			   }
			 }
		   }
		 }
	   }
	 }
   activated = true;
   StatusBar1->SimpleText = L"";
   cxGroupBox1->Visible = false;
   Screen->Cursor = crDefault;
}
//---------------------------------------------------------------------------

// upload/update button
void __fastcall TChronControlForm::cxButton3Click(TObject *Sender)
{

   bool success;
   if (operation == abEdit) {
	 if (IsRelAge)
	   success = UpdateRelativeAge();
	 else if (IsEvtAge)
	   success = UpdateEventAge();
	 else
	   success = UpdateChronControlType();
	 }
   else if (operation == abAddChild) {
	 if (IsRelAge)
	   success = UploadRelativeAge();
	 else if (IsEvtAge && Node->Level > 2)
	   success = UploadEventAge();
	 else
	   success = UploadChronControlType();
	 }

   Screen->Cursor = crDefault;
   if (success)
     ModalResult = mrOk;
}
//---------------------------------------------------------------------------

// add publication
void __fastcall TChronControlForm::cxButton5Click(TObject *Sender)
{
   if (operation == abEdit) {
	 if (IsRelAge)
	   AddRelativeAgePub();
	 else if (IsEvtAge)
	   AddEventPub();
	 }
   else if (operation == abAddChild) {
	 if (IsRelAge || IsEvtAge)
	   AddPub();
	 }
}
//---------------------------------------------------------------------------

// remove publication
void __fastcall TChronControlForm::cxButton4Click(TObject *Sender)
{
   if (operation == abEdit) {
	 if (IsRelAge)
	   DeleteRelativeAgePub();
	 else if (IsEvtAge)
	   DeleteEventPub();
	 }
   else if (operation == abAddChild) {
	 if (IsRelAge || IsEvtAge)
	   RemovePub();
	 }
}
//---------------------------------------------------------------------------

bool TChronControlForm::LoggedIn(void)
{
   if (!Login->IsLoggedIn) {
	 NeotomaLoginForm = new TNeotomaLoginForm(this);
	 NeotomaLoginForm->ShowModal();
	 delete NeotomaLoginForm;
	 }
   return (Login->IsLoggedIn);
}
//---------------------------------------------------------------------------

bool TChronControlForm::UploadEventAge(void)
{
   UnicodeString msg, ErrorMsg;
   int EventTypeID;
   UnicodeString EventName;
   UnicodeString EventType;
   double Value;
   Variant C14Age = Unassigned();
   Variant C14AgeYounger = Unassigned();
   Variant C14AgeOlder = Unassigned();
   Variant CalAge = Unassigned();
   Variant CalAgeYounger = Unassigned();
   Variant CalAgeOlder = Unassigned();

   UnicodeString Notes;
   vector<int> newids;

   EventName = LabeledEdit1->Text;
   if (EventName.IsEmpty()) {
	 msg = L"Event name cannot be empty.";
	 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 return false;
	 }

   // check that age is not already in Neotoma
   Screen->Cursor = crHourGlass;
   NeotomaEventByName NeotomaEvent(ipsJSONS1, TcpClient1);
   NeotomaEvent.AddParam(L"EVENTNAME", EventName);
   StatusBar1->SimpleText = NeotomaEvent.WebServiceName();
   if (NeotomaEvent.Execute()) {
	 if (NeotomaEvent.Size() > 0) {
	   msg = L"Event name «" + EventName + L"» already exists in Neotoma: EventID = " +
			 IntToStr(NeotomaEvent.Items[0].EventID) + L".";
	   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return false;
	   }
	 }
   else
	 return false;

   // get EventType
   TTreeNode* Parent = Node->Parent;
   while (Parent->Level > 2)
	 Parent = Parent->Parent;
   EventType = Parent->Text;

   // get EventTypeID
   NeotomaEventTypeByName NeotomaEventType(ipsJSONS1, TcpClient1);
   NeotomaEventType.AddParam(L"EVENTTYPE", EventType);
   StatusBar1->SimpleText = NeotomaEventType.WebServiceName();
   if (NeotomaEventType.Execute()) {
	 if (NeotomaEventType.Size() == 1)
	   EventTypeID = NeotomaEventType.Items.begin()->first;
	 else {
	   msg = L"Event type «" + EventType + L"» is not in the Neotoma EventTypes table!";
	   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   Screen->Cursor = crDefault;
	   return false;
	   }
	 }
   else
	 return false;

   if (!LoggedIn())
	 return false;

   int nparams = 2;
   vector<UnicodeString> errors;

   if (!LabeledEdit4->Text.IsEmpty()) {
	 if (TryStrToFloat(LabeledEdit4->Text, Value)) {
	   C14Age = Value;
	   nparams++;
	   }
	 else
	   errors.push_back(L"Radiocarbon Age «" + LabeledEdit4->Text + L"» is not a valid number.");
	 }
   if (!LabeledEdit3->Text.IsEmpty()) {
	 if (TryStrToFloat(LabeledEdit3->Text, Value)) {
	   C14AgeYounger = Value;
	   nparams++;
	   }
	 else
	   errors.push_back(L"Radiocarbon YoungerAge Limit «" + LabeledEdit3->Text + L"» is not a valid number.");
	 }
   if (!LabeledEdit2->Text.IsEmpty()) {
	 if (TryStrToFloat(LabeledEdit2->Text,Value)) {
	   C14AgeOlder = Value;
	   nparams++;
	   }
	 else
	   errors.push_back(L"Radiocarbon Older Age Limit «" + LabeledEdit2->Text + L"» is not a valid number.");
	 }

   if (!LabeledEdit7->Text.IsEmpty()) {
	 if (TryStrToFloat(LabeledEdit7->Text,Value)) {
	   CalAge = Value;
	   nparams++;
	   }
	 else
	   errors.push_back(L"Cal Age «" + LabeledEdit7->Text + L"» is not a valid number.");
	 }
   if (!LabeledEdit6->Text.IsEmpty()) {
	 if (TryStrToFloat(LabeledEdit6->Text,Value)) {
	   CalAgeYounger = Value;
	   nparams++;
	   }
	 else
	   errors.push_back(L"Cal Age Younger Limit «" + LabeledEdit6->Text + L"» is not a valid number.");
	 }
   if (!LabeledEdit5->Text.IsEmpty()) {
	 if (TryStrToFloat(LabeledEdit5->Text,Value)) {
	   CalAgeOlder = Value;
	   nparams++;
	   }
	 else
	   errors.push_back(L"Cal Age Older Limit «" + LabeledEdit5->Text + L"» is not a valid number.");
	 }

   if (errors.size() > 0) {
	 for (unsigned int i=0; i<errors.size(); i++)
	   MessageDlg(errors[i], Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 return false;
	 }

   if (!CheckAges(C14AgeOlder, C14AgeYounger, C14Age, CalAgeOlder, CalAgeYounger, CalAge))
	 return false;

   if (!Memo1->Text.IsEmpty()) {
	 Notes = Memo1->Text;
	 nparams++;
	 }

   InsertData InsertEvent(L"InsertEvent", nparams, ipsHTTPS1, ipsJSONS1, TcpClient1);
   InsertEvent.Add(L"EVENTTYPEID", EventTypeID, -1);
   InsertEvent.Add(L"EVENTNAME", EventName);
   if (!C14Age.IsEmpty())
	 InsertEvent.Add(L"C14AGE", (double)C14Age);
   if (!C14AgeYounger.IsEmpty())
	 InsertEvent.Add(L"C14AGEYOUNGER", (double)C14AgeYounger);
   if (!C14AgeOlder.IsEmpty())
	 InsertEvent.Add(L"C14AGEOLDER", (double)C14AgeOlder);
   if (!CalAge.IsEmpty())
	 InsertEvent.Add(L"CALAGE", (double)CalAge);
   if (!CalAgeYounger.IsEmpty())
	 InsertEvent.Add(L"CALAGEYOUNGER", (double)CalAgeYounger);
   if (!CalAgeOlder.IsEmpty())
	 InsertEvent.Add(L"CALAGEOLDER", (double)CalAgeOlder);
   if (!Notes.IsEmpty())
	 InsertEvent.Add(L"NOTES", Notes);

   StatusBar1->SimpleText = L"InsertEvent";
   InsertEvent.PostData();
   if (InsertEvent.Post(newids, ErrorMsg)) {
	 // upload publications
	 vector<UnicodeString> PubMessages;
	 for (int row=1; row<AdvColumnGrid1->RowCount; row++) {
	   int PubID = AdvColumnGrid1->Cells[0][row].ToInt();
	   InsertData InsertEventPub(L"InsertEventPublication", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
	   InsertEventPub.Add(L"EVENTID", newids[0], -1);
	   InsertEventPub.Add(L"PUBLICATIONID", PubID, -1);
	   StatusBar1->SimpleText = L"InsertEventPublication";
	   InsertEventPub.PostData();
	   if (InsertEventPub.Post(ErrorMsg)) {
		 msg = L"PublicationID " + IntToStr(PubID) +
			   L" added to Neotoma as reference for event «" + EventName + L"».";
		 PubMessages.push_back(msg);
		 }
	   else
		 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   }

	 //-----------
	 msg = L"Success! Event «" + EventName + L"» added to Neotoma Event Types «" +
		   EventType + L"»: EventID = " + IntToStr(newids[0]) + L".";
	 for (unsigned int i=0; i<PubMessages.size(); i++)
	   msg += (L"\n" + PubMessages[i]);
	 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
	 }
   else {
	 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 return false;
	 }

   return true;
}
//---------------------------------------------------------------------------

bool TChronControlForm::UpdateEventAge(void)
{
   UnicodeString msg, ErrorMsg;
   int EventTypeID;
   double Value;

   if (EventID == -1) {  // this should never happen, but...
	 msg = L"Event «" + Node->Text + L"» is not in the Neotoma Events table. Cannot update.";
	 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 return false;
	 }

   UnicodeString EventName = LabeledEdit1->Text;
   if (EventName.IsEmpty()) {
	 msg = L"Event name cannot be empty.";
	 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 return false;
     }

   UnicodeString EventType = Node->Parent->Text;
   // get EventTypeID
   Screen->Cursor = crHourGlass;
   NeotomaEventTypeByName NeotomaEventType(ipsJSONS1, TcpClient1);
   NeotomaEventType.AddParam(L"EVENTTYPE", EventType);
   StatusBar1->SimpleText = NeotomaEventType.WebServiceName();
   if (NeotomaEventType.Execute()) {
	 if (NeotomaEventType.Size() == 1)
	   EventTypeID = NeotomaEventType.Items.begin()->first;
	 else {
	   msg = L"Event type «" + EventType + L"» is not in the Neotoma EventTypes table!";
	   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   Screen->Cursor = crDefault;
	   return false;
	   }
	 }
   else
	 return false;

   if (EventName == Node->Text)   // name not changed
	 msg = L"Update «" + EventType + "» Event «" + EventName + L"» in Neotoma?";
   else
	 msg = L"Update «" + EventType + "» Event «" + Node->Text + L"» to «" + EventName + L"» in Neotoma?";
   if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrNo)
	 return false;

   if (!LoggedIn())
	 return false;

   vector<UnicodeString> errors;
   UpdateData UpdateEvent(L"UpdateEvent", 10, ipsHTTPS1, ipsJSONS1, TcpClient1);
   StatusBar1->SimpleText = L"UpdateEvent";
   UpdateEvent.Add(L"EVENTID", EventID);
   UpdateEvent.Add(L"EVENTTYPEID", EventTypeID);
   UpdateEvent.Add(L"EVENTNAME", EventName);
   if (!LabeledEdit4->Text.IsEmpty()) {
	 if (TryStrToFloat(LabeledEdit4->Text,Value))
	   UpdateEvent.Add(L"C14AGE", Value);
	 else
	   errors.push_back(L"Radiocarbon Age «" + LabeledEdit4->Text + L"» is not a valid number.");
	 }
   if (!LabeledEdit3->Text.IsEmpty()) {
	 if (TryStrToFloat(LabeledEdit3->Text,Value))
	   UpdateEvent.Add(L"C14AGEYOUNGER", Value);
	 else
	   errors.push_back(L"Radiocarbon YoungerAge Limit «" + LabeledEdit3->Text + L"» is not a valid number.");
	 }
   if (!LabeledEdit2->Text.IsEmpty()) {
	 if (TryStrToFloat(LabeledEdit2->Text,Value))
	   UpdateEvent.Add(L"C14AGEOLDER", Value);
	 else
	   errors.push_back(L"Radiocarbon Older Age Limit «" + LabeledEdit2->Text + L"» is not a valid number.");
	 }
   if (!LabeledEdit7->Text.IsEmpty()) {
	 if (TryStrToFloat(LabeledEdit7->Text,Value))
	   UpdateEvent.Add(L"CALAGE", Value);
	 else
	   errors.push_back(L"Cal Age «" + LabeledEdit7->Text + L"» is not a valid number.");
	 }
   if (!LabeledEdit6->Text.IsEmpty()) {
	 if (TryStrToFloat(LabeledEdit6->Text,Value))
	   UpdateEvent.Add(L"CALAGEYOUNGER", Value);
	 else
	   errors.push_back(L"Cal Age Younger Limit «" + LabeledEdit6->Text + L"» is not a valid number.");
	 }
   if (!LabeledEdit5->Text.IsEmpty()) {
	 if (TryStrToFloat(LabeledEdit5->Text,Value))
	   UpdateEvent.Add(L"CALAGEOLDER", Value);
	 else
	   errors.push_back(L"Cal Age Older Limit «" + LabeledEdit5->Text + L"» is not a valid number.");
	 }

   if (errors.size() > 0) {
	 for (unsigned int i=0; i<errors.size(); i++)
	   MessageDlg(errors[i], Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 return false;
	 }

   // if (!Memo1->Text.IsEmpty())
   UpdateEvent.Add(L"NOTES", Memo1->Text.Trim());

   // everything checks out, so update
   if (UpdateEvent.Post(ErrorMsg)) {
	 if (EventName == Node->Text)   // name not changed
	   msg = L"Success! Event «" + EventName + L"» updated.";
	 else {
	   msg = L"Success! Event «" + Node->Text + L"» updated to «" + EventName + L"».";
	   Node->Text = EventName;
	   }
	 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
	 }
   else {
	 UnicodeString msg = L"Update aborted";
	 if (!ErrorMsg.IsEmpty())
	   msg += (L": " + ErrorMsg);
	 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 }

   return true;
}
//---------------------------------------------------------------------------

bool TChronControlForm::UploadRelativeAge(void)
{
   UnicodeString msg, ErrorMsg;
   int RelativeAgeUnitID;
   int RelativeAgeScaleID;
   UnicodeString RelativeAge;
   double Value;
   Variant C14AgeYounger = Unassigned();
   Variant C14AgeOlder = Unassigned();
   Variant CalAgeYounger = Unassigned();
   Variant CalAgeOlder = Unassigned();
   UnicodeString Notes;
   vector<int> newids;

   RelativeAge = LabeledEdit1->Text;
   if (RelativeAge.IsEmpty()) {
	 msg = L"Relative age cannot be empty.";
	 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 return false;
	 }

   // check that age is not already in Neotoma
   Screen->Cursor = crHourGlass;
   NeotomaRelativeAgeByName NeotomaRelativeAge(ipsJSONS1, TcpClient1);
   NeotomaRelativeAge.AddParam(L"RELATIVEAGE", RelativeAge);
   StatusBar1->SimpleText = NeotomaRelativeAge.WebServiceName();
   if (NeotomaRelativeAge.Execute()) {
	 if (NeotomaRelativeAge.Size() > 0) {
	   msg = L"Relative age «" + RelativeAge + L"» already exists in Neotoma: RelativeAgeID = " +
			 IntToStr(NeotomaRelativeAge.Items[0].RelativeAgeID) + L".";
	   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return false;
	   }
	 }
   else
	 return false;

   // get RelativeAgeScaleID
   NeotomaRelativeAgeScaleByName RelAgeScale(ipsJSONS1, TcpClient1);
   RelAgeScale.AddParam(L"RELATIVEAGESCALE", RelativeAgeScale);
   StatusBar1->SimpleText = RelAgeScale.WebServiceName();
   if (RelAgeScale.Execute()) {
	 if (RelAgeScale.Size() == 1)
	   RelativeAgeScaleID = RelAgeScale.Items.begin()->first;
	 else {
	   msg = L"Relative age scale «" + RelativeAgeScale + L"» is not in the Neotoma RelativeAgeScales table!";
	   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   Screen->Cursor = crDefault;
	   return false;
	   }
	 }
   else
	 return false;

   if (!LoggedIn())
	 return false;

   UnicodeString RelativeAgeUnit = ComboBox1->Items->Strings[ComboBox1->ItemIndex];
   RelativeAgeUnitID = AgeUnitIDs[RelativeAgeUnit];

   int nparams = 3;
   vector<UnicodeString> errors;
   if (!LabeledEdit3->Text.IsEmpty()) {
	 if (TryStrToFloat(LabeledEdit3->Text, Value)) {
	   C14AgeYounger = Value;
	   nparams++;
	   }
	 else
	   errors.push_back(L"Radiocarbon YoungerAge Limit «" + LabeledEdit3->Text + L"» is not a valid number.");
	 }
   if (!LabeledEdit2->Text.IsEmpty()) {
	 if (TryStrToFloat(LabeledEdit2->Text,Value)) {
	   C14AgeOlder = Value;
	   nparams++;
	   }
	 else
	   errors.push_back(L"Radiocarbon Older Age Limit «" + LabeledEdit2->Text + L"» is not a valid number.");
	 }

   if (!LabeledEdit6->Text.IsEmpty()) {
	 if (TryStrToFloat(LabeledEdit6->Text,Value)) {
	   CalAgeYounger = Value;
	   nparams++;
	   }
	 else
	   errors.push_back(L"Cal Age Younger Limit «" + LabeledEdit6->Text + L"» is not a valid number.");
	 }
   if (!LabeledEdit5->Text.IsEmpty()) {
	 if (TryStrToFloat(LabeledEdit5->Text,Value)) {
	   CalAgeOlder = Value;
	   nparams++;
	   }
	 else
	   errors.push_back(L"Cal Age Older Limit «" + LabeledEdit5->Text + L"» is not a valid number.");
	 }

   if (errors.size() > 0) {
	 for (unsigned int i=0; i<errors.size(); i++)
	   MessageDlg(errors[i], Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 return false;
	 }

   if (!CheckAges(C14AgeOlder, C14AgeYounger, Unassigned(), CalAgeOlder, CalAgeYounger, Unassigned()))
	 return false;

   if (!Memo1->Text.IsEmpty()) {
	 Notes = Memo1->Text;
	 nparams++;
	 }

   InsertData InsertRelativeAge(L"InsertRelativeAge", nparams, ipsHTTPS1, ipsJSONS1, TcpClient1);
   InsertRelativeAge.Add(L"RELATIVEAGEUNITID", RelativeAgeUnitID, -1);
   InsertRelativeAge.Add(L"RELATIVEAGESCALEID", RelativeAgeScaleID, -1);
   InsertRelativeAge.Add(L"RELATIVEAGE", RelativeAge);
   if (!C14AgeYounger.IsEmpty())
	 InsertRelativeAge.Add(L"C14AGEYOUNGER", (double)C14AgeYounger);
   if (!C14AgeOlder.IsEmpty())
	 InsertRelativeAge.Add(L"C14AGEOLDER", (double)C14AgeOlder);
   if (!CalAgeYounger.IsEmpty())
	 InsertRelativeAge.Add(L"CALAGEYOUNGER", (double)CalAgeYounger);
   if (!CalAgeOlder.IsEmpty())
	 InsertRelativeAge.Add(L"CALAGEOLDER", (double)CalAgeOlder);
   if (!Notes.IsEmpty())
	 InsertRelativeAge.Add(L"NOTES", Notes);

   StatusBar1->SimpleText = L"InsertRelativeAge";
   InsertRelativeAge.PostData();
   if (InsertRelativeAge.Post(newids, ErrorMsg)) {
	 // upload publications
	 vector<UnicodeString> PubMessages;
	 for (int row=1; row<AdvColumnGrid1->RowCount; row++) {
	   int PubID = AdvColumnGrid1->Cells[0][row].ToInt();
	   InsertData InsertRelativeAgePub(L"InsertRelativeAgePublication", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
	   InsertRelativeAgePub.Add(L"RELATIVEAGEID", newids[0], -1);
	   InsertRelativeAgePub.Add(L"PUBLICATIONID", PubID, -1);
	   StatusBar1->SimpleText = L"InsertRelativeAgePublication";
	   InsertRelativeAgePub.PostData();
	   if (InsertRelativeAgePub.Post(ErrorMsg)) {
		 msg = L"PublicationID " + IntToStr(PubID) +
			   L" added to Neotoma as reference for relative age «" + RelativeAge +
			   L"».";
		 PubMessages.push_back(msg);
		 }
	   else {
		 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 return false;
		 }
	   }

	 //-----------
	 msg = L"Success! Relative age «" + RelativeAge +
		   L"» added to Neotoma relative age scale «" + RelativeAgeScale +
		   L"»: RelativeAgeID = " + IntToStr(newids[0]) + L".";
	 for (unsigned int i=0; i<PubMessages.size(); i++)
	   msg += (L"\n" + PubMessages[i]);
	 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
	 }
   else {
	 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 return false;
	 }

   return true;
}
//---------------------------------------------------------------------------

bool TChronControlForm::UpdateRelativeAge(void)
{
   UnicodeString msg, ErrorMsg;
   int RelativeAgeScaleID;
   double Value;

   if (RelativeAgeID == -1) {  // this should never happen, but...
	 msg = L"Relative age «" + Node->Text + L"» is not in the Neotoma RelativeAges table. Cannot update.";
	 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 return false;
	 }

   UnicodeString RelativeAge = LabeledEdit1->Text;
   if (RelativeAge.IsEmpty()) {
	 msg = L"Relative age cannot be empty.";
	 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 return false;
	 }

   UnicodeString RelativeAgeScale = Node->Parent->Text;

   // get RelativeAgeScaleID
   Screen->Cursor = crHourGlass;
   NeotomaRelativeAgeScaleByName RelAgeScale(ipsJSONS1, TcpClient1);
   RelAgeScale.AddParam(L"RELATIVEAGESCALE", RelativeAgeScale);
   StatusBar1->SimpleText = RelAgeScale.WebServiceName();
   if (RelAgeScale.Execute()) {
	 if (RelAgeScale.Size() == 1)
	   RelativeAgeScaleID = RelAgeScale.Items.begin()->first;
	 else {
	   msg = L"Relative age scale «" + RelativeAgeScale + L"» is not in the Neotoma RelativeAgeScales table!";
	   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   Screen->Cursor = crDefault;
	   return false;
	   }
	 }
   else
	 return false;

   if (RelativeAge == Node->Text)   // name not changed
	 msg = L"Update " + RelativeAgeScale + " relative age «" + RelativeAge + L"» in Neotoma?";
   else
	 msg = L"Update «" + RelativeAgeScale + "» relative age «" + Node->Text + L"» to «" + RelativeAge + L"» in Neotoma?";
   if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrNo)
	 return false;

   if (!LoggedIn())
	 return false;

   vector<UnicodeString> errors;
   UpdateData UpdateRelativeAge(L"UpdateRelativeAge", 9, ipsHTTPS1, ipsJSONS1, TcpClient1);
   StatusBar1->SimpleText = L"UpdateRelativeAge";
   UpdateRelativeAge.Add(L"RELATIVEAGEID", RelativeAgeID);
   UpdateRelativeAge.Add(L"RELATIVEAGEUNITID", RelativeAgeUnitID);
   UpdateRelativeAge.Add(L"RELATIVEAGESCALEID", RelativeAgeScaleID);
   UpdateRelativeAge.Add(L"RELATIVEAGE", RelativeAge);

   if (!LabeledEdit3->Text.IsEmpty()) {
	 if (TryStrToFloat(LabeledEdit3->Text,Value))
	   UpdateRelativeAge.Add(L"C14AGEYOUNGER", Value);
	 else
	   errors.push_back(L"Radiocarbon YoungerAge Limit «" + LabeledEdit3->Text + L"» is not a valid number.");
	 }
   if (!LabeledEdit2->Text.IsEmpty()) {
	 if (TryStrToFloat(LabeledEdit2->Text,Value))
	   UpdateRelativeAge.Add(L"C14AGEOLDER", Value);
	 else
	   errors.push_back(L"Radiocarbon Older Age Limit «" + LabeledEdit2->Text + L"» is not a valid number.");
	 }

   if (!LabeledEdit6->Text.IsEmpty()) {
	 if (TryStrToFloat(LabeledEdit6->Text,Value))
	   UpdateRelativeAge.Add(L"CALAGEYOUNGER", Value);
	 else
	   errors.push_back(L"Cal Age Younger Limit «" + LabeledEdit6->Text + L"» is not a valid number.");
	 }
   if (!LabeledEdit5->Text.IsEmpty()) {
	 if (TryStrToFloat(LabeledEdit5->Text,Value))
	   UpdateRelativeAge.Add(L"CALAGEOLDER", Value);
	 else
	   errors.push_back(L"Cal Age Older Limit «" + LabeledEdit5->Text + L"» is not a valid number.");
	 }

   if (errors.size() > 0) {
	 for (unsigned int i=0; i<errors.size(); i++)
	   MessageDlg(errors[i], Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 return false;
	 }

   // if (!Memo1->Text.IsEmpty())
   UpdateRelativeAge.Add(L"NOTES", Memo1->Text.Trim());

   // everything checks out, so update
   if (UpdateRelativeAge.Post(ErrorMsg)) {
	 if (RelativeAge == Node->Text)   // name not changed
	   msg = L"Success! Relative age «" + RelativeAge + L"» updated.";
	 else {
	   msg = L"Success! Relative age «" + Node->Text + L"» updated to «" + RelativeAge + L"».";
	   Node->Text = RelativeAge;
	   }
	 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
	 }
   else {
	 UnicodeString msg = L"Update aborted";
	 if (!ErrorMsg.IsEmpty())
	   msg += (L": " + ErrorMsg);
	 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 return false;
	 }

   return true;
}
//---------------------------------------------------------------------------

void TChronControlForm::AddPub(void)
{
   PUBLICATION *pub = new PUBLICATION(JOURNAL_ARTICLE);
   TStewardPubForm* PubForm = new TStewardPubForm(pub, NEWPUB, NULL, this);
   if (PubForm->ShowModal() == mrOk) {
	 if (pub->NeotomaID > -1) {
	   int row = AdvColumnGrid1->RowCount - 1;
	   if (!AdvColumnGrid1->Cells[0][row].IsEmpty()) {
		 AdvColumnGrid1->RowCount++;
		 row++;
		 }
	   AdvColumnGrid1->Cells[0][row] = IntToStr(pub->NeotomaID);
	   AdvColumnGrid1->Cells[1][row] = pub->Citation;
	   }
	 }
   delete pub;
   delete PubForm;
   StatusBar1->SimpleText = L"";
}
//---------------------------------------------------------------------------

void TChronControlForm::RemovePub(void)
{
   int row = AdvColumnGrid1->Row;
   if (AdvColumnGrid1->RowCount > 2)
	 AdvColumnGrid1->RemoveRows(row,1);
   else {
	 AdvColumnGrid1->Cells[0][1] = L"";
	 AdvColumnGrid1->Cells[1][1] = L"";
	 }
}
//---------------------------------------------------------------------------

void TChronControlForm::AddEventPub(void)
{
   UnicodeString msg, ErrorMsg;

   if (EventID == -1) {  // this should never happen, but...
	 msg = L"Event «" + Node->Text + L"» is not in the Neotoma Events table. Cannot add publication.";
	 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 return;
	 }

   if (!LoggedIn())
	 return;

   PUBLICATION *pub = new PUBLICATION(JOURNAL_ARTICLE);
   TStewardPubForm* PubForm = new TStewardPubForm(pub, NEWPUB, NULL, this);
   if (PubForm->ShowModal() == mrOk) {
	 if (pub->NeotomaID > -1) {
	   int row = AdvColumnGrid1->RowCount - 1;
	   if (!AdvColumnGrid1->Cells[0][row].IsEmpty()) {
		 AdvColumnGrid1->RowCount++;
		 row++;
		 }
	   AdvColumnGrid1->Cells[0][row] = IntToStr(pub->NeotomaID);
	   AdvColumnGrid1->Cells[1][row] = pub->Citation;

	   InsertData InsertEventPub(L"InsertEventPublication", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
	   InsertEventPub.Add(L"EVENTID", EventID, -1);
	   InsertEventPub.Add(L"PUBLICATIONID", pub->NeotomaID, -1);
	   StatusBar1->SimpleText = L"InsertEventPublication";
	   InsertEventPub.PostData();
	   if (InsertEventPub.Post(ErrorMsg)) {
		 msg = L"Success! PublicationID " + IntToStr(pub->NeotomaID) +
			   L" added to Neotoma as reference for Event «" + Node->Text +
			   L"»: EventID = " + IntToStr(EventID) + L".";
		 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
		 }
	   else
		 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   }
	 }
   delete pub;
   delete PubForm;
   StatusBar1->SimpleText = L"";
}
//---------------------------------------------------------------------------

void TChronControlForm::DeleteEventPub(void)
{
   UnicodeString msg, ErrorMsg;

   if (EventID == -1) {  // this should never happen, but...
	 msg = L"Event «" + Node->Text + L"» is not in the Neotoma Events table. Cannot remove publication.";
	 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 return;
	 }

   int row = AdvColumnGrid1->Row;
   int PublicationID = AdvColumnGrid1->Cells[0][row].ToInt();

   msg = L"Remove PublicationID " + IntToStr(PublicationID) + L" as reference to event «" + Node->Text + L"»?";
   if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrNo)
	 return;

   if (!LoggedIn())
	 return;

   DeleteData DeleteEventPub(L"DeleteEventPublication", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
   StatusBar1->SimpleText = L"DeleteEventPublication";
   DeleteEventPub.Add(L"EVENTID", EventID);
   DeleteEventPub.Add(L"PUBLICATIONID", PublicationID);
   if (DeleteEventPub.Post(ErrorMsg)) {
	 if (AdvColumnGrid1->RowCount > 2)
	   AdvColumnGrid1->RemoveRows(row,1);
	 else {
	   AdvColumnGrid1->Cells[0][1] = L"";
	   AdvColumnGrid1->Cells[1][1] = L"";
	   }
	 msg = L"Success! PublicationID " + IntToStr(PublicationID) + L" removed as reference to event «" + Node->Text + L"».";
	 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
	 }
   else
	 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
}
//---------------------------------------------------------------------------

void TChronControlForm::AddRelativeAgePub(void)
{
   UnicodeString msg, ErrorMsg;

   if (RelativeAgeID == -1) {  // this should never happen, but...
	 msg = L"Relative age «" + Node->Text + L"» is not in the Neotoma RelativeAges table. Cannot update.";
	 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 return;
	 }

   if (!LoggedIn())
	 return;

   PUBLICATION *pub = new PUBLICATION(JOURNAL_ARTICLE);
   TStewardPubForm* PubForm = new TStewardPubForm(pub, NEWPUB, NULL, this);
   if (PubForm->ShowModal() == mrOk) {
	 if (pub->NeotomaID > -1) {
	   int row = AdvColumnGrid1->RowCount - 1;
	   if (!AdvColumnGrid1->Cells[0][row].IsEmpty()) {
		 AdvColumnGrid1->RowCount++;
		 row++;
		 }
	   AdvColumnGrid1->Cells[0][row] = IntToStr(pub->NeotomaID);
	   AdvColumnGrid1->Cells[1][row] = pub->Citation;
	   InsertData InsertRelativeAgePub(L"InsertRelativeAgePublication", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
	   InsertRelativeAgePub.Add(L"RELATIVEAGEID", RelativeAgeID, -1);
	   InsertRelativeAgePub.Add(L"PUBLICATIONID", pub->NeotomaID, -1);
	   StatusBar1->SimpleText = L"InsertRelativeAgePublication";
	   InsertRelativeAgePub.PostData();
	   if (InsertRelativeAgePub.Post(ErrorMsg)) {
		 msg = L"Success! PublicationID " + IntToStr(pub->NeotomaID) +
			   L" added to Neotoma as reference for relative age «" + Node->Text +
			   L"»: RelativeAgeID = " + IntToStr(RelativeAgeID) + L".";
		 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
		 }
	   else
		 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   }
	 }
   delete pub;
   delete PubForm;
   StatusBar1->SimpleText = L"";
}
//---------------------------------------------------------------------------

void TChronControlForm::DeleteRelativeAgePub(void)
{
   UnicodeString msg, ErrorMsg;

   if (RelativeAgeID == -1) {  // this should never happen, but...
	 msg = L"Relative age «" + Node->Text + L"» is not in the Neotoma RelativeAges table. Cannot update.";
	 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 return;
	 }

   int row = AdvColumnGrid1->Row;
   int PublicationID = AdvColumnGrid1->Cells[0][row].ToInt();

   msg = L"Remove PublicationID " + IntToStr(PublicationID) + L" as reference to relative age «" + Node->Text + L"»?";
   if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrNo)
	 return;

   if (!LoggedIn())
	 return;

   DeleteData DeleteRelativeAgePub(L"DeleteRelativeAgePublication", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
   StatusBar1->SimpleText = L"DeleteRelativeAgePublication";
   DeleteRelativeAgePub.Add(L"RELATIVEAGEID", RelativeAgeID);
   DeleteRelativeAgePub.Add(L"PUBLICATIONID", PublicationID);
   if (DeleteRelativeAgePub.Post(ErrorMsg)) {
	 if (AdvColumnGrid1->RowCount > 2)
	   AdvColumnGrid1->RemoveRows(row,1);
	 else {
	   AdvColumnGrid1->Cells[0][1] = L"";
	   AdvColumnGrid1->Cells[1][1] = L"";
	   }
	 msg = L"Success! PublicationID " + IntToStr(PublicationID) + L" removed as reference to relative age «" + Node->Text + L"».";
	 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
	 }
   else
	 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
}
//---------------------------------------------------------------------------

bool TChronControlForm::UploadChronControlType(void)
{
   UnicodeString msg, ErrorMsg;
   UnicodeString NewChronControlType;
   int HigherChronControlTypeID;
   vector<int> newids;

   NewChronControlType = LabeledEdit1->Text;
   if (NewChronControlType.IsEmpty()) {
	 msg = L"Name of Chron Control Type cannot be empty.";
	 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 return false;
	 }

   if (!LoggedIn())
	 return false;

   Screen->Cursor = crHourGlass;
   int ChronControlTypeID;
   NeotomaChronControlTypeByName ChronControlType(ipsJSONS1, TcpClient1);
   ChronControlType.AddParam(L"CHRONCONTROLTYPE", NewChronControlType);
   StatusBar1->SimpleText = ChronControlType.WebServiceName();
   if (ChronControlType.Execute()) {
	 if (ChronControlType.Size() > 0) {
	   msg = L"The ChronControlType «" + NewChronControlType +
			 L"» is already in the Neotoma ChronControlTypes table. ChronControlTypeID = " +
			 IntToStr(ChronControlType.Items[0].ChronControlTypeID) + L".";
	   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return false;
	   }
	 }
   else
	 return false;

   NeotomaChronControlTypeByName HigherChronControlType(ipsJSONS1, TcpClient1);
   HigherChronControlType.AddParam(L"CHRONCONTROLTYPE", Node->Parent->Text);
   StatusBar1->SimpleText = HigherChronControlType.WebServiceName();
   if (HigherChronControlType.Execute()) {
	 if (HigherChronControlType.Size() == 1)
	   HigherChronControlTypeID = HigherChronControlType.Items[0].HigherChronControlTypeID;
	 else {
	   msg = L"The parent ChronControlType «" + Node->Parent->Text +
			 L"» is not in the Neotoma ChronControlTypes table.";
	   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return false;
	   }
	 }
   else
	 return false;

   msg = L"Upload new Chron Control Type «" + NewChronControlType +
		 L"» as a child of «" + Node->Parent->Text + L"»?";
   if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrNo)
	 return false;

   InsertData InsertChronControlType(L"InsertChronControlType", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
   InsertChronControlType.Add(L"CHRONCONTROLTYPE", NewChronControlType);
   InsertChronControlType.Add(L"HIGHERCHRONCONTROLTYPEID", HigherChronControlTypeID, -1);
   StatusBar1->SimpleText = L"InsertChronControlType";
   InsertChronControlType.PostData();
   if (InsertChronControlType.Post(newids, ErrorMsg)) {
	 msg = L"Success! «" + NewChronControlType +
		   L"» added to Neotoma ChronControlTypes table: ChronControlTypeID = " +
		   IntToStr(newids[0]) + L".";
	 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
	 }
   else {
	 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 return false;
	 }

   return true;
}
//---------------------------------------------------------------------------

bool TChronControlForm::UpdateChronControlType(void)
{
   UnicodeString msg, ErrorMsg;

   if (!LoggedIn())
	 return false;

   Screen->Cursor = crHourGlass;
   int ChronControlTypeID;
   NeotomaChronControlTypeByName ChronControlType(ipsJSONS1, TcpClient1);
   ChronControlType.AddParam(L"CHRONCONTROLTYPE", Node->Text);
   StatusBar1->SimpleText = ChronControlType.WebServiceName();
   if (ChronControlType.Execute()) {
	 if (ChronControlType.Size() == 1)
	   ChronControlTypeID = ChronControlType.Items[0].ChronControlTypeID;
	 else {
	   msg = L"The original ChronControlType «" + Node->Text + L"» is not in the Neotoma ChronControlTypes table.";
	   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return false;
	   }
	 }
   else
	 return false;

   UnicodeString NewName = LabeledEdit1->Text;
   msg = L"Update ChronControlType «" + Node->Text + L"» to «" + NewName + L"»?";
   if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrNo)
	 return false;

   UpdateData UpdateChronControlType(L"UpdateChronControlType", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
   StatusBar1->SimpleText = L"UpdateChronControlType";
   UpdateChronControlType.Add(L"CHRONCONTROLTYPEID", ChronControlTypeID);
   UpdateChronControlType.Add(L"CHRONCONTROLTYPE", NewName);
   if (UpdateChronControlType.Post(ErrorMsg)) {
	 msg = L"Success! ChronControlType updated from «" + Node->Text + L"» to «" + NewName + L"».";
	 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
	 }
   else {
	 UnicodeString msg = L"Update aborted";
	 if (!ErrorMsg.IsEmpty())
	   msg += (L": " + ErrorMsg);
	 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 }
   Screen->Cursor = crDefault;
   return true;
}
//---------------------------------------------------------------------------

bool TChronControlForm::CheckAges(Variant C14AgeOlder, Variant C14AgeYounger,
	Variant C14Age, Variant CalAgeOlder, Variant CalAgeYounger, Variant CalAge)
{
   UnicodeString msg;

   if (C14AgeOlder.IsEmpty() && !C14AgeYounger.IsEmpty() ||
	   !C14AgeOlder.IsEmpty() && C14AgeYounger.IsEmpty()) {
	 msg = L"Both younger and older radiocarbon ages must have values or be blank.";
	 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 return false;
	 }
   if (CalAgeOlder.IsEmpty() && !CalAgeYounger.IsEmpty() ||
	   !CalAgeOlder.IsEmpty() && CalAgeYounger.IsEmpty()) {
	 msg = L"Both younger and older calendar/calibrated ages must have values or be blank.";
	 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 return false;
	 }

   if (!C14AgeOlder.IsEmpty() && !C14AgeYounger.IsEmpty()) {
	 if (C14AgeOlder < C14AgeYounger) {
	   msg = L"Older radiocarbon age must be >= the younger age!";
	   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return false;
	   }
	 if (!C14Age.IsEmpty()) {
	   if (C14Age > C14AgeOlder || C14Age < C14AgeYounger) {
		 msg = L"Radiocarbon age must be fall between the older and younger ages!";
		 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 return false;
		 }
	   }
	 }
   if (!CalAgeOlder.IsEmpty() && !CalAgeYounger.IsEmpty()) {
	 if (CalAgeOlder < CalAgeYounger) {
	   msg = L"Older calendar/calibrated age must be >= the younger age!";
	   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return false;
	   }
	 if (!CalAge.IsEmpty()) {
	   if (CalAge > CalAgeOlder || CalAge < CalAgeYounger) {
		 msg = L"Calendar/Calibrated age must be fall between the older and younger ages!";
		 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 return false;
		 }
	   }
	 }

   return true;
}
//---------------------------------------------------------------------------

// gets value from the dropdown editor after dropping up
void __fastcall TChronControlForm::FormControlEditLink1GetEditorValue(TObject *Sender,
		  TAdvStringGrid *Grid, UnicodeString &AValue)
{
   AValue = AdvControlDropDown1->Text;
}
//---------------------------------------------------------------------------

// sets the value in the editor for the dropdown
void __fastcall TChronControlForm::FormControlEditLink1SetEditorValue(TObject *Sender,
		  TAdvStringGrid *Grid, UnicodeString AValue)
{
   AdvControlDropDown1->Text = AValue;
}
//---------------------------------------------------------------------------

// sets text in the memo control
void __fastcall TChronControlForm::AdvColumnGrid1GetEditorProp(TObject *Sender, int ACol,
		  int ARow, TEditLink *AEditLink)
{
   if (ACol == 1) {
	 cxMemo1->Text = AdvColumnGrid1->Cells[ACol][ARow];
	 if (AdvControlDropDown1->DropDownWidth == 0)
	   AdvControlDropDown1->DropDownWidth = AdvColumnGrid1->Columns->Items[1]->Width - 6;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TChronControlForm::cxButton2Click(TObject *Sender)
{
   if (operation == abAddChild || operation == abAddSibling)
	 Node->Owner->Delete(Node);
}
//---------------------------------------------------------------------------

void __fastcall TChronControlForm::ipsJSONS1SSLServerAuthentication(TObject *Sender,
          TipsJSONSSSLServerAuthenticationEventParams *e)
{
   e->Accept = true;
}
//---------------------------------------------------------------------------

