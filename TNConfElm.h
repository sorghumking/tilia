//---------------------------------------------------------------------------

#ifndef TNConfElmH
#define TNConfElmH
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
#include "cxTextEdit.hpp"
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include "cxListBox.hpp"
#include "cxButtons.hpp"
#include <Menus.hpp>
#include <vector>
//---------------------------------------------------------------------------
class TConfirmElementUploadForm : public TForm
{
__published:	// IDE-managed Components
	TcxTextEdit *cxTextEdit1;
	TcxLabel *cxLabel1;
	TFlowPanel *FlowPanel1;
	TcxLabel *cxLabel2;
	TcxListBox *cxListBox1;
	TFlowPanel *FlowPanel2;
	TcxButton *cxButton1;
	TcxButton *cxButton2;
	TcxButton *cxButton3;
	void __fastcall cxButton1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TConfirmElementUploadForm(UnicodeString element,
		vector<UnicodeString>& TaxaNames, TComponent* Owner);
};
//---------------------------------------------------------------------------

class TConfirmUnitsUploadForm : public TConfirmElementUploadForm
{
public:
	__fastcall TConfirmUnitsUploadForm(UnicodeString Units,
		vector<UnicodeString>& TaxaNames, TComponent* Owner);
};
//---------------------------------------------------------------------------

class TConfirmContextUploadForm : public TConfirmElementUploadForm
{
public:
	__fastcall TConfirmContextUploadForm(UnicodeString Context,
		vector<UnicodeString>& TaxaNames, TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TConfirmElementUploadForm *ConfirmElementUploadForm;
//---------------------------------------------------------------------------
#endif
