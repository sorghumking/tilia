//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TIUpDepEnv.h"
#ifndef TINeotomaH
#include "TINeotoma.h"
#endif
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxTreeView"
#pragma link "cxButtons"
#pragma link "cxLabel"
#pragma link "cxImage"
#pragma link "cxCheckBox"
#pragma link "cxGroupBox"
#pragma link "dxtree"
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
TNewDepEnvtForm *NewDepEnvtForm;

//---------------------------------------------------------------------------
__fastcall TNewDepEnvtForm::TNewDepEnvtForm(TComponent* Owner) : TForm(Owner)
{
   upf = (TNeotomaUploadForm*)Owner;
   TSSForm = upf->TSSForm;
   SelectedNode = NULL;
   DroppedNode = NULL;
}
//---------------------------------------------------------------------------

void __fastcall TNewDepEnvtForm::FormCreate(TObject *Sender)
{
   NewDepEnv = upf->coll_ptr->DepEnv;
   SelectedNode = FindTreeNode(TSSForm->dxTreeViewEdit1, NewDepEnv);
   Label2->Caption = L"Hierarchical placement of «" + NewDepEnv +L"» in Neotoma table";
   Panel1->Align = alTop;
   int center = Panel1->Width/2;
   cxButton7->Left = center - cxButton7->Width - 8;
   cxButton8->Left = center + 8;
   Label1->Width = Panel1->Width - Label1->Left - 24;
   UnicodeString msg = L"Depositional Environment «" + NewDepEnv;
   if (!upf->coll_ptr->CollectionName.IsEmpty())
	 msg += (L"» in Collection Unit «" + upf->coll_ptr->CollectionName);
   msg += L"» is not in the Neotoma DepEnvtTypes Table. ";
   msg += L"Is this a new Depositional Environment that should be added to the database?";
   Label1->Caption = msg;
   Modified = false;
   Uploaded = false;
}
//---------------------------------------------------------------------------

void __fastcall TNewDepEnvtForm::cxButton7Click(TObject *Sender)
{
   if (cxButton7->Caption == L"&Yes") {
	 if (!Go())
	   ModalResult = mrAbort;
	 }
   else if (cxButton7->Caption == L"&Ok")
	 ModalResult = mrAbort;
}
//---------------------------------------------------------------------------

void __fastcall TNewDepEnvtForm::cxButton8Click(TObject *Sender)
{
   ModalResult = mrCancel;
}
//---------------------------------------------------------------------------

void TNewDepEnvtForm::DepEnvtsAdd(int ID, UnicodeString Name, int HigherID)
{
   TREENODE DepEnvt;
   DepEnvt.ID = ID;
   DepEnvt.Name = Name;
   DepEnvt.HigherID = HigherID;
   DepEnvts.push_back(DepEnvt);
}
//---------------------------------------------------------------------------

int TNewDepEnvtForm::DepEnvtFindID(UnicodeString Name)
{
   int ID = -1;
   for (unsigned int i=0; i<DepEnvts.size(); i++) {
	 if (SameText(Name, DepEnvts[i].Name)) {
	   ID = DepEnvts[i].ID;
	   break;
	   }
	 }
   return ID;
}
//---------------------------------------------------------------------------

bool TNewDepEnvtForm::Go(void)
{
   vector<void*> vptrs;
   vector<TTreeNode*> ChildNodes;
   deque<TTreeNode*> NodeChain;

   // build DepEnvt tree from Neotoma
   TREENODE DepEnvt;
   for (unsigned int i=0; i<upf->DepEnvtTypes->Size(); i++) {
	 DepEnvt.ID = upf->DepEnvtTypes->Items[i].DepEnvtID;
	 DepEnvt.Name = upf->DepEnvtTypes->Items[i].DepEnvt;
	 DepEnvt.HigherID = upf->DepEnvtTypes->Items[i].DepEnvtHigherID;
	 DepEnvts.push_back(DepEnvt);
	 }
   TSSForm->BuilddxTree(DepEnvts, dxTreeView1);
   dxTreeView1->AlphaSort();

   //--
   // find parent of NewDepEnv in Neotoma tree
   // first find parent in local tree, see if it exists in Neotoma tree
   TTreeNode* LocalNode = FindTreeNode(TSSForm->dxTreeViewEdit1, NewDepEnv);
   if (LocalNode) {  // should always be true
	 TTreeNode* NeotomaParentNode = NULL;
	 TTreeNode* LocalParentNode = LocalNode->Parent;
	 TTreeNode* TopLocalChildNode = LocalParentNode;
	 while (!NeotomaParentNode && LocalParentNode) {
	   TTreeNode* NeotomaNode = FindTreeNode(dxTreeView1, LocalParentNode->Text);
	   if (NeotomaNode)
		 NeotomaParentNode = NeotomaNode;
	   else {
		 TopLocalChildNode = LocalParentNode;
		 LocalParentNode = LocalParentNode->Parent;
		 }
	   }
	 // add new top local child node
	 if (NeotomaParentNode && SameText(NeotomaParentNode->Text, TopLocalChildNode->Text)) {
	   dxTreeView1->Items->AddChild(NeotomaParentNode, NewDepEnv);
	   }
	 else {
	   dxTreeView1->Items->AddChild(NeotomaParentNode, TopLocalChildNode->Text);
	   vector<TTreeNode*> NewLocalChildNodes;
	   GetAllChildNodes(TopLocalChildNode, NewLocalChildNodes);
	   int size = NewLocalChildNodes.size();
	   // add all child nodes below top child node
	   while (NewLocalChildNodes.size() > 0) {
		 for (int i = NewLocalChildNodes.size()-1; i >= 0; i--) {
		   TTreeNode* NtmParentNode = FindTreeNode(dxTreeView1, NewLocalChildNodes[i]->Parent->Text);
		   if (NtmParentNode) {
			 UnicodeString NodeName = NewLocalChildNodes[i]->Text;
			 dxTreeView1->Items->AddChild(NtmParentNode, NewLocalChildNodes[i]->Text);
			 NewLocalChildNodes.erase(NewLocalChildNodes.begin()+i);
			 }
		   }
		 }
	   }
	 dxTreeView1->AlphaSort();
	 }
   else {  // this should never happen
	 UnicodeString msg = L"ERROR: Depositional environment «" + NewDepEnv +
	   L"» not found in Depostional Environment lookup list on the Collection Units metadata tabsheet.";
	 Image2->Top = Image1->Top;
	 Image1->Visible = false;
	 Image2->Visible = true;
	 Label1->Caption = msg;
	 cxButton8->Visible = false;
	 cxButton7->Caption = L"&Ok";
	 cxButton7->Left = (Panel1->Width - cxButton7->Width)/2;
	 upf->OutputError(msg);
	 return true;
	 }

   NewNode = NULL;
   int count = dxTreeView1->Items->Count;
   for (int i=0; i<dxTreeView1->Items->Count; i++) {
	 TTreeNode *Node = dxTreeView1->Items->Item[i];
	 if (NewDepEnv == Node->Text) {
	   NewNode = Node;
	   Node->SelectedIndex = 1;
	   Node->ImageIndex = 1;
	   NewNodes.push_back(Node);
	   NodeChain.push_back(Node);
	   }
	 else {
	   Node->SelectedIndex = 0;
	   Node->ImageIndex = 0;
	   Node->Enabled = false;
	   }
	 }

   if (NewNode) {
	 TTreeNode* ParentNode = NewNode->Parent;
	 while (ParentNode != NULL) {
	   if (upf->DepEnvtTypes->Find("DepEnvt", ParentNode->Text, vptrs) == 0) {
		 ParentNode->Enabled = true;
		 ParentNode->SelectedIndex = 1;
		 ParentNode->ImageIndex = 1;
		 NewNodes.push_back(ParentNode);
		 NodeChain.push_front(ParentNode);
		 ParentNode = ParentNode->Parent;
		 }
	   else
		 break;
	   }

	 // mark any other child nodes under the top node orange
	 TTreeNode* TopNode = NodeChain[0];
	 TopNode->Expand(true);
	 ChildNodes.clear();
	 GetAllChildNodes(TopNode, ChildNodes);
	 for (unsigned int i=0; i<ChildNodes.size(); i++) {
	   if (ChildNodes[i]->ImageIndex != 1) {
		 NewNodes.push_back(ChildNodes[i]);
		 OptionalNodes.push_back(ChildNodes[i]);
		 ChildNodes[i]->Enabled = true;
		 ChildNodes[i]->ImageIndex = 2;
		 ChildNodes[i]->SelectedIndex = 2;
		 }
	   }
	 }
   dxTreeView1->Selected = NewNode;

   //TODO: If NewNode == NULL, then need to bail
   //--
   Panel1->Visible = false;
   Panel2->Visible = true;
   FocusControl(dxTreeView1);

   return true;
}
//---------------------------------------------------------------------------

TTreeNode* TNewDepEnvtForm::FindTreeNode(TdxTreeViewEdit* dxTreeViewEdit, UnicodeString Text)
{
   TTreeNode* FoundNode = NULL;
   int count = dxTreeViewEdit->Items->Count;
   count = TSSForm->GetTreeViewCount(dxTreeViewEdit);
   for (int i=0; i<count; i++) {
	 TTreeNode *Node = dxTreeViewEdit->Items->Item[i];
	 if (SameText(Text, Node->Text)) {
	   FoundNode = Node;
	   break;
	   }
	 }
   return FoundNode;
}
//---------------------------------------------------------------------------

TTreeNode* TNewDepEnvtForm::FindTreeNode(TdxTreeView* dxTreeView, UnicodeString Text)
{
   TTreeNode* FoundNode = NULL;
   int count = dxTreeView->Items->Count;
   count = TSSForm->GetTreeViewCount(dxTreeView);
   for (int i=0; i<count; i++) {
	 TTreeNode *Node = dxTreeView->Items->Item[i];
	 if (SameText(Text, Node->Text)) {
	   FoundNode = Node;
	   break;
	   }
	 }
   return FoundNode;
}
//---------------------------------------------------------------------------

void TNewDepEnvtForm::GetAllChildNodes(TTreeNode* TopNode, vector<TTreeNode*>& ChildNodes)
{
   if (TopNode->HasChildren) {
	 TTreeNode *ChildNode = TopNode->getFirstChild();
	 ChildNodes.push_back(ChildNode);
	 GetAllChildNodes(ChildNode, ChildNodes);
	 while ((ChildNode = TopNode->GetNextChild(ChildNode)) != NULL) {
	   ChildNodes.push_back(ChildNode);
	   GetAllChildNodes(ChildNode, ChildNodes);
	   }
	 }
}
//---------------------------------------------------------------------------

void __fastcall TNewDepEnvtForm::dxTreeView1Changing(TObject *Sender, TTreeNode *Node,
		  bool &AllowChange)
{
   if (find(OptionalNodes.begin(), OptionalNodes.end(), Node) != OptionalNodes.end())    // Node is an optional node
	 cxButton9->Visible = true;  // visible if node not orphaned
   else
	 cxButton9->Visible = false;

   if (cxButton9->Visible) {
	 if (Node->ImageIndex == 1)
	   cxButton9->Caption = L"Undo Add";
	 else
	   cxButton9->Caption = L"Add to Neotoma";
	 }
}
//---------------------------------------------------------------------------

// optionally add to Neotoma
void __fastcall TNewDepEnvtForm::cxButton9Click(TObject *Sender)
{
   if (dxTreeView1->Selected->ImageIndex == 2) {
	 dxTreeView1->Selected->ImageIndex = 1;
	 dxTreeView1->Selected->SelectedIndex = 1;
	 cxButton9->Caption = L"Undo Add";
	 }
   else {
	 dxTreeView1->Selected->ImageIndex = 2;
	 dxTreeView1->Selected->SelectedIndex = 2;
	 cxButton9->Caption = L"Add to Neotoma";
	 }
   FocusControl(dxTreeView1);
}
//---------------------------------------------------------------------------

// Save button
void __fastcall TNewDepEnvtForm::cxButton11Click(TObject *Sender)
{
   cxGroupBox1->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TNewDepEnvtForm::cxButton14Click(TObject *Sender)
{
   cxGroupBox1->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TNewDepEnvtForm::cxCheckBox1Click(TObject *Sender)
{
   if (cxCheckBox1->Checked)
	 cxCheckBox2->Enabled = true;
   else {
	 cxCheckBox2->Checked = false;
	 cxCheckBox2->Enabled = false;
	 }
}
//---------------------------------------------------------------------------

// save depositional environments
void __fastcall TNewDepEnvtForm::cxButton13Click(TObject *Sender)
{
   UnicodeString msg;
   UnicodeString LookupFileName;
   if (cxCheckBox1->Checked) {    // save to CollUnit tabsheet
	 TSSForm->dxTreeViewEdit1->Items->Clear();
	 TSSForm->dxTreeViewEdit1->Items->Assign(dxTreeView1->Items);
	 TSSForm->dxTreeViewEdit1->Text = NewDepEnv;
	 TSSForm->CollPtr->DepEnv = NewDepEnv;
	 if (cxCheckBox2->Checked) {
	   LookupFileName = TSSForm->SaveLookupFile();
	   msg = L"Depositional Environments saved to Collection Units tabsheet\n";
	   msg += L"Depositional Environments saved to " + LookupFileName;
	   }
	 else
	   msg = L"Depositional Environments saved to Collection Units tabsheet";
	 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
	 cxButton11->Enabled = false;
	 }
   cxGroupBox1->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TNewDepEnvtForm::dxTreeView1Editing(TObject *Sender, TTreeNode *Node,
		  bool &AllowEdit)
{
   if (Node->ImageIndex == 0)
	 AllowEdit = false;
}
//---------------------------------------------------------------------------

// spelling changed
void __fastcall TNewDepEnvtForm::dxTreeView1Edited(TObject *Sender, TTreeNode *Node,
		  UnicodeString &S)
{
   if (Node == NewNode) {
	 NewDepEnv = S;
	 Label2->Caption = L"Hierarchical placement of «" + NewDepEnv +L"» in Neotoma table";
	 }
   Modified = true;
   cxButton11->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TNewDepEnvtForm::dxTreeView1DragDropTreeNode(TTreeNode *Destination,
          TTreeNode *Source, bool &Accept)
{
   if (Source->ImageIndex == 0)
	 Accept = false;
}
//---------------------------------------------------------------------------

void __fastcall TNewDepEnvtForm::dxTreeView1EndDragTreeNode(TTreeNode *Destination,
		  TTreeNode *Source, TNodeAttachMode &AttachMode)
{
   DroppedNode = Source;
   Modified = true;
   cxButton11->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TNewDepEnvtForm::dxTreeView1EndDrag(TObject *Sender, TObject *Target,
		  int X, int Y)
{
   vector<TTreeNode*> NodeChain;
   // check for optional nodes above NewNode
   if (DroppedNode) {
	 NodeChain.push_back(NewNode);
	 TTreeNode *ParentNode = NewNode->Parent;
	 while (ParentNode && ParentNode->ImageIndex != 0) {
	   NodeChain.push_back(ParentNode);
	   ParentNode->ImageIndex = 1;
	   ParentNode->SelectedIndex = 1;
	   ParentNode = ParentNode->Parent;
	   }
	 DroppedNode = NULL;
	 // mark any optional nodes
	 OptionalNodes.clear();
	 vector<TTreeNode*>::iterator itr;
	 for (unsigned int i=0; i<NewNodes.size(); i++) {
	   TTreeNode *Node = NewNodes[i];
	   itr = find(NodeChain.begin(), NodeChain.end(), Node);
	   if (itr == NodeChain.end()) {
		 OptionalNodes.push_back(Node);
		 Node->ImageIndex = 2;
		 Node->SelectedIndex = 2;
		 }
	   }
     dxTreeView1->AlphaSort();
	 dxTreeView1->Repaint();
	 }
}
//---------------------------------------------------------------------------

// upload to Neotoma
void __fastcall TNewDepEnvtForm::cxButton10Click(TObject *Sender)
{
   UnicodeString ErrorMsg, msg;
   bool CloseUp = true;

   Screen->Cursor = crHourGlass;
   if (Upload(ErrorMsg)) {
	 int size = NewDepEnvts.size();
	 if (size == 1)
	   msg = L"New Deopositonal Environment «" + NewDepEnvts[0].Name + L"» uploaded to Neotoma";
	 else
	   msg = IntToStr(size) + L" new Depositional Environments uploaded to Neotoma";
	 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
	 Uploaded = true;

	 if (cxButton11->Enabled) {
	   msg = L"Depositional Environments were modified but not saved to local lookup file.\n";
	   msg += L"Do you want to save them? If so, click the \"Yes\" button then \"Save\".";
	   if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes) {
		 cxButton10->Enabled = false;
		 cxButton10->ModalResult = mrNone;
		 dxTreeView1->Enabled = false;
		 CloseUp = false;
		 }
	   }
	 }
   else if (!ErrorMsg.IsEmpty())
	 upf->OutputError(ErrorMsg);
   Screen->Cursor = crDefault;
   if (CloseUp)
	 Close();
}
//---------------------------------------------------------------------------

bool TNewDepEnvtForm::Upload(UnicodeString& ErrorMsg)
{
   TREENODE NewDepEnvt;
   vector<int> newids;
   int newid;
   bool Error = false;
   UnicodeString Line;

   // get vector of new depositional environments to be added
   for (unsigned int i=0; i<NewNodes.size(); i++) {
	 if (NewNodes[i]->ImageIndex == 1) {
	   NewDepEnvt.ID = -1;
	   NewDepEnvt.HigherID = -1;
	   NewDepEnvt.Name = NewNodes[i]->Text;
	   NewDepEnvts.push_back(NewDepEnvt);
	   }
	 }

   // check if new types already in Neotoma
   for (unsigned int i=0; i<NewDepEnvts.size(); i++) {
	 for (unsigned int j=0; j<DepEnvts.size(); j++) {
	   if (SameText(NewDepEnvts[i].Name, DepEnvts[j].Name)) {
		 UnicodeString msg = L"Depositional Environment «" + NewDepEnvts[i].Name +
			L"» already in Neotoma. Cannot upload!";
		 int rv = MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK << mbAbort, 0);
		 if (rv == mrAbort)
		   return false;
		 Error = true;
		 }
	   }
	 }
   if (Error) {
	 MessageDlg(L"Errors encountered. Cannot proceed with upload.", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 return false;
	 }

   // find top new node(s) and assign HigherID(s)
   for (unsigned int i=0; i<NewDepEnvts.size(); i++) {
	 TTreeNode* dxNode = FindTreeNode(dxTreeView1, NewDepEnvts[i].Name);
	 if (dxNode->Parent == NULL)
	   NewDepEnvts[i].HigherID = -2;  // flags as new top node
	 else if (dxNode->Parent->ImageIndex == 0) {
	   for (unsigned int j=0; j<DepEnvts.size(); j++) {
		 if (SameText(dxNode->Parent->Text, DepEnvts[j].Name)) {
		   NewDepEnvts[i].HigherID = DepEnvts[j].ID;
		   break;
		   }
		 }
	   }
	 }

   // upload any new DepEnvts with HigherID already assigned
   for (unsigned int i=0; i<NewDepEnvts.size(); i++) {
	 if (NewDepEnvts[i].HigherID >= 0) {
	   if (UploadNewDepEnvt(NewDepEnvts[i].Name, NewDepEnvts[i].HigherID, newids, ErrorMsg)) {
		 DepEnvtsAdd(newids[0], NewDepEnvts[i].Name, NewDepEnvts[i].HigherID);
		 Line = L"New Depositional Type uploaded to Neotoma: ID = " +
				IntToStr(newids[0]) + L", Name = «" + NewDepEnvts[i].Name +
				L"», HigherID = " + IntToStr(NewDepEnvts[i].HigherID);
		 upf->OutputLine(Line);
		 }
	   else
		 return false;
	   }
	 }

   // upload new top nodes, i.e. those with HigherID == -2
   for (unsigned int i=0; i<NewDepEnvts.size(); i++) {
	 if (NewDepEnvts[i].HigherID == -2) {
	   // upload new Depositional Environment, setting HigherID = 0
	   if (UploadNewDepEnvt(NewDepEnvts[i].Name, 0, newids, ErrorMsg)) {
		 Line = L"New Depositional Type uploaded to Neotoma: ID = " +
				IntToStr(newids[0]) + L", Name = «" + NewDepEnvts[i].Name +
				L"»";
		 upf->OutputLine(Line);
		 }
	   else
		 return false;

	   //url = L"https://ceiwin5.cei.psu.edu/tilia/update/?method=UpdateDepEnvtType&DEPENVTID=172&DEPENVT=newtest&DEPENVTHIGHERID=6";

	   // get new ID and assign to HigherID of new Depositional Environment
	   newid = newids[0];
	   UpdateData UpdateDepEnvtHigherID(L"UpdateDepEnvtHigherID", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
	   UpdateDepEnvtHigherID.Add(L"DEPENVTID", newid);
	   UpdateDepEnvtHigherID.Add(L"DEPENVTHIGHERID", newid);

	   if (UpdateDepEnvtHigherID.Post(ErrorMsg)) {
		 Line = L"HigherID of new Depositional Environment «" + NewDepEnvts[i].Name +
				L"» updated to " + IntToStr(newid);
		 upf->OutputLine(Line);
		 NewDepEnvts[i].HigherID = newid;
		 DepEnvtsAdd(newid, NewDepEnvts[i].Name, newid);
		 }
	   else {
		 UnicodeString error_msg = L"ERROR: Attempt to update HigherID of new Depositional Type «" +
			 NewDepEnvts[i].Name + L"» to " + IntToStr(newid) + " failed.\n\n" + ErrorMsg;
		 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 return false;
		 }
	   }
	 }

   // upload new Depositional Environments that are not top nodes, i.e. HigherID == -1
   bool done;
   do {
	  done = true;
	  for (unsigned int i=0; i<NewDepEnvts.size(); i++) {
		if (NewDepEnvts[i].HigherID == -1) {
		  TTreeNode* dxNode = FindTreeNode(dxTreeView1, NewDepEnvts[i].Name);
		  int HigherID = DepEnvtFindID(dxNode->Parent->Text);
		  if (HigherID >= 0) {
			NewDepEnvts[i].HigherID = HigherID;
			// Add new DepEnvt to Neotoma here, and obtain newid
			if (UploadNewDepEnvt(NewDepEnvts[i].Name, HigherID, newids, ErrorMsg)) {
			  DepEnvtsAdd(newids[0], NewDepEnvts[i].Name, HigherID);
			  Line = L"New Depositional Type uploaded to Neotoma: ID = " +
					 IntToStr(newids[0]) + L", Name = «" + NewDepEnvts[i].Name +
					 L"», HigherID = " + IntToStr(HigherID);
			  upf->OutputLine(Line);
			  }
			else
			  return false;
			done = false;
			break;
			}
		  }
		}
	  } while(!done);

   return true;
}
//---------------------------------------------------------------------------

bool TNewDepEnvtForm::UploadNewDepEnvt(UnicodeString Name, int HigherID, vector<int>& newids, UnicodeString& ErrorMsg)
{
   UnicodeString Line;
   newids.clear();

   InsertData InsertDepEnvtType(L"InsertDepEnvtType", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
   InsertDepEnvtType.Add(L"DEPENVT", Name);
   InsertDepEnvtType.Add(L"DEPENVTHIGHERID", HigherID, -1);
   InsertDepEnvtType.PostData();
   bool rv = InsertDepEnvtType.Post(newids, ErrorMsg);
   return rv;
}
//---------------------------------------------------------------------------

void __fastcall TNewDepEnvtForm::ipsJSONS1SSLServerAuthentication(TObject *Sender,
          TipsJSONSSSLServerAuthenticationEventParams *e)
{
   e->Accept = true;
}
//---------------------------------------------------------------------------

