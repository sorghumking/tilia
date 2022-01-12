//---------------------------------------------------------------------------

#ifndef TIEdTreeH
#define TIEdTreeH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "cxButtons.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include "dxtree.hpp"
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TEditTreeForm : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TLabeledEdit *LabeledEdit1;
	TcxButton *cxButton1;
	TcxButton *cxButton2;
	TPanel *Panel2;
	TcxButton *cxButton3;
	TcxButton *cxButton4;
	TdxTreeView *dxTreeView1;
	TcxButton *cxButton5;
	TcxButton *cxButton6;
	void __fastcall cxButton6Click(TObject *Sender);
	void __fastcall LabeledEdit1Change(TObject *Sender);
	void __fastcall cxButton5Click(TObject *Sender);
	void __fastcall cxButton1Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall dxTreeView1Change(TObject *Sender, TTreeNode *Node);
	void __fastcall dxTreeView1Deletion(TObject *Sender, TTreeNode *Node);
	void __fastcall FormDeactivate(TObject *Sender);
	void __fastcall dxTreeView1CustomDraw(TObject *Sender, TTreeNode *TreeNode, TFont *AFont,
          TColor &AColor, TColor &ABkColor);
	void __fastcall cxButton6MouseEnter(TObject *Sender);
	void __fastcall cxButton6MouseLeave(TObject *Sender);
	void __fastcall LabeledEdit1Enter(TObject *Sender);
	void __fastcall LabeledEdit1Exit(TObject *Sender);
	void __fastcall cxButton2Click(TObject *Sender);
	void __fastcall dxTreeView1Edited(TObject *Sender, TTreeNode *Node, UnicodeString &S);

private:	// User declarations
	bool Modified;
	bool Activated;
	bool HotLight;
	TTreeNode *SelectedNode;
public:		// User declarations
	__fastcall TEditTreeForm(TComponent* Owner);
	bool TreeModified(void) { return Modified; }
};
//---------------------------------------------------------------------------
extern PACKAGE TEditTreeForm *EditTreeForm;
//---------------------------------------------------------------------------
#endif
