//---------------------------------------------------------------------------

#ifndef TNSelItmH
#define TNSelItmH
#include "AdvCGrid.hpp"
#include "AdvGrid.hpp"
#include "AdvObj.hpp"
#include "BaseGrid.hpp"
#include "cxButtons.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include <Classes.hpp>
#include <Controls.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <Menus.hpp>
#include <StdCtrls.hpp>
#include "pch.h"
#include <map>

//---------------------------------------------------------------------------
class TSelectItemForm : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TAdvColumnGrid *AdvColumnGrid1;
	TPanel *Panel2;
	TFlowPanel *FlowPanel1;
	TcxButton *cxButton1;
	TcxButton *cxButton2;
	void __fastcall cxButton1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TSelectItemForm(TComponent* Owner);
};
//---------------------------------------------------------------------------


class TSelectSynonymTypeForm : public TSelectItemForm
{
__published:	// IDE-managed Components
	void __fastcall cxButton1Click(TObject *Sender);
public:
   __fastcall TSelectSynonymTypeForm(map<int,UnicodeString>& Items, TComponent* Owner);
   int SynonymTypeID;
   UnicodeString SynonymType;
};
//---------------------------------------------------------------------------
extern PACKAGE TSelectItemForm *SelectItemForm;
extern PACKAGE TSelectSynonymTypeForm *SelectSynonymTypeForm;
//---------------------------------------------------------------------------
#endif
