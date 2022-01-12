//---------------------------------------------------------------------------

#ifndef TIOpnXLSH
#define TIOpnXLSH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "cxCheckListBox.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxEdit.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include "cxButtons.hpp"
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TImportExcelForm : public TForm
{
__published:	// IDE-managed Components
	TcxCheckListBox *cxCheckListBox1;
	TLabel *Label1;
	TCheckBox *CheckBox1;
	TcxButton *cxButton1;
	TcxButton *cxButton2;
	void __fastcall cxCheckListBox1Click(TObject *Sender);
	void __fastcall cxButton1Click(TObject *Sender);
private:	// User declarations
	UnicodeString SheetName;
	bool NullToZero;
public:		// User declarations
	__fastcall TImportExcelForm(TStringList* Sheets, TComponent* Owner);
	UnicodeString GetSheetName(void) { return SheetName; }
	bool GetNullToZero(void) { return NullToZero; }
};
//---------------------------------------------------------------------------
extern PACKAGE TImportExcelForm *ImportExcelForm;
//---------------------------------------------------------------------------
#endif
