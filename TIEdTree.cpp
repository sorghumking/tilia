//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TIEdTree.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "dxtree"
#pragma resource "*.dfm"
TEditTreeForm *EditTreeForm;
//---------------------------------------------------------------------------
__fastcall TEditTreeForm::TEditTreeForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TEditTreeForm::FormCreate(TObject *Sender)
{
   Modified = false;
   Activated = true;
   HotLight = false;
   SelectedNode = NULL;
}
//---------------------------------------------------------------------------

void __fastcall TEditTreeForm::FormDeactivate(TObject *Sender)
{
   Activated = false;
}
//---------------------------------------------------------------------------

// add new item button
void __fastcall TEditTreeForm::cxButton6Click(TObject *Sender)
{
   cxButton6->Visible = false;
   Panel2->Visible = false;
   LabeledEdit1->Text = L"";
   Panel1->Visible = true;
   FocusControl(LabeledEdit1);
}
//---------------------------------------------------------------------------

void __fastcall TEditTreeForm::LabeledEdit1Change(TObject *Sender)
{
   if (!LabeledEdit1->Text.IsEmpty()) {
	 cxButton1->Enabled = true;
	 cxButton2->Enabled = true;
	 }
   else {
	 cxButton1->Enabled = false;
	 cxButton2->Enabled = false;
	 }
}
//---------------------------------------------------------------------------

// cancel new item
void __fastcall TEditTreeForm::cxButton5Click(TObject *Sender)
{
   Panel1->Visible = false;
   Panel2->Visible = true;
   cxButton6->Visible = true;
   FocusControl(dxTreeView1);
}
//---------------------------------------------------------------------------

// add sibling
void __fastcall TEditTreeForm::cxButton1Click(TObject *Sender)
{
   dxTreeView1->Items->BeginUpdate();
   TTreeNode* NewNode = dxTreeView1->Items->Add(dxTreeView1->Selected, LabeledEdit1->Text);
   dxTreeView1->AlphaSort();
   dxTreeView1->Items->EndUpdate();
   Panel1->Visible = false;
   Panel2->Visible = true;
   cxButton6->Visible = true;
   Modified = true;
   dxTreeView1->Selected = NewNode;
   FocusControl(dxTreeView1);
}
//---------------------------------------------------------------------------

// add child
void __fastcall TEditTreeForm::cxButton2Click(TObject *Sender)
{
   dxTreeView1->Items->BeginUpdate();
   TTreeNode* NewNode = dxTreeView1->Items->AddChild(dxTreeView1->Selected, LabeledEdit1->Text);
   dxTreeView1->AlphaSort();
   dxTreeView1->Items->EndUpdate();
   Panel1->Visible = false;
   Panel2->Visible = true;
   cxButton6->Visible = true;
   Modified = true;
   dxTreeView1->Selected = NewNode;
   FocusControl(dxTreeView1);
}
//---------------------------------------------------------------------------

void __fastcall TEditTreeForm::dxTreeView1Change(TObject *Sender, TTreeNode *Node)
{
   SelectedNode = Node;
}
//---------------------------------------------------------------------------

void __fastcall TEditTreeForm::dxTreeView1Edited(TObject *Sender, TTreeNode *Node,
		  UnicodeString &S)
{
   Modified = true;
}
//---------------------------------------------------------------------------

void __fastcall TEditTreeForm::dxTreeView1Deletion(TObject *Sender, TTreeNode *Node)
{
   if (Activated)
	 Modified = true;
}
//---------------------------------------------------------------------------

void __fastcall TEditTreeForm::dxTreeView1CustomDraw(TObject *Sender, TTreeNode *TreeNode,
		  TFont *AFont, TColor &AColor, TColor &ABkColor)
{
   if (TreeNode == SelectedNode)
	 AColor = (HotLight) ? clHotLight : clWindowText;
}
//---------------------------------------------------------------------------

void __fastcall TEditTreeForm::cxButton6MouseEnter(TObject *Sender)
{
   HotLight = true;
}
//---------------------------------------------------------------------------

void __fastcall TEditTreeForm::cxButton6MouseLeave(TObject *Sender)
{
   HotLight = false;
}
//---------------------------------------------------------------------------

void __fastcall TEditTreeForm::LabeledEdit1Enter(TObject *Sender)
{
   HotLight = true;
}
//---------------------------------------------------------------------------

void __fastcall TEditTreeForm::LabeledEdit1Exit(TObject *Sender)
{
   HotLight = false;
}
//---------------------------------------------------------------------------

