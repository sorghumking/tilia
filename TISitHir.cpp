//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TISitHir.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TSiteHierarchyForm *SiteHierarchyForm;

//---------------------------------------------------------------------------
__fastcall TSiteHierarchyForm::TSiteHierarchyForm(TComponent* Owner)
	: TForm(Owner)
{
   TSSForm = (TTilSpreadSheetForm*)Owner;
}
//---------------------------------------------------------------------------

void __fastcall TSiteHierarchyForm::FormCreate(TObject *Sender)
{
  TTreeNode *Node;

  for (int i=0; i<TSSForm->Sites->Count; i++) {
	SITE* site_ptr = (SITE*)TSSForm->Sites->Items[i];
	UnicodeString SiteName = site_ptr->SiteName;
	if (SiteName.IsEmpty())
	  SiteName = L"[empty]";
	Node = TreeView1->Items->Add(NULL, SiteName);
	for (unsigned int j=0; j<site_ptr->CollUnits.size(); j++) {
	  UnicodeString CollName = site_ptr->CollUnits[j].CollectionName;
	  if (CollName.IsEmpty())
		CollName = L"[empty]";
	  TreeView1->Items->AddChild(Node, CollName);
	  }
	}
}
//---------------------------------------------------------------------------
