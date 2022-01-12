//---------------------------------------------------------------------------

#ifndef TISitHirH
#define TISitHirH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>

#ifndef TISpreadH
#include "TISpread.h"
#endif
//---------------------------------------------------------------------------
class TSiteHierarchyForm : public TForm
{
__published:	// IDE-managed Components
	TPageScroller *PageScroller1;
	TTreeView *TreeView1;
	void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
	TTilSpreadSheetForm* TSSForm;
public:		// User declarations
	__fastcall TSiteHierarchyForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TSiteHierarchyForm *SiteHierarchyForm;
//---------------------------------------------------------------------------
#endif
