//---------------------------------------------------------------------------

#ifndef TNConfTaxNamChngH
#define TNConfTaxNamChngH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxEdit.hpp"
#include "cxGraphics.hpp"
#include "cxLabel.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include "cxButtons.hpp"
#include "cxGroupBox.hpp"
#include "cxRadioGroup.hpp"
#include "cxTextEdit.hpp"
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TConfirmReplaceTaxonForm : public TForm
{
__published:	// IDE-managed Components
	TImage *Image1;
	TcxLabel *cxLabel1;
	TcxTextEdit *cxTextEdit1;
	TcxLabel *cxLabel2;
	TcxTextEdit *cxTextEdit2;
	TcxRadioGroup *cxRadioGroup1;
	TcxButton *cxButton1;
	TcxButton *cxButton2;
	void __fastcall cxButton1Click(TObject *Sender);
	void __fastcall cxRadioGroup1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TConfirmReplaceTaxonForm(UnicodeString OldName,
		UnicodeString NewName, TComponent* Owner);
	bool SaveOrigID;
};
//---------------------------------------------------------------------------
extern PACKAGE TConfirmReplaceTaxonForm *ConfirmReplaceTaxonForm;
//---------------------------------------------------------------------------
#endif
