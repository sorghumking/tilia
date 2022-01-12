//---------------------------------------------------------------------------

#ifndef TIVrLkUpH
#define TIVrLkUpH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Dialogs.hpp>
#include "cxButtons.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include <Menus.hpp>
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxEdit.hpp"
#include "cxLabel.hpp"
#include "cxTextEdit.hpp"
#include "cxGroupBox.hpp"
#include "cxRadioGroup.hpp"
//---------------------------------------------------------------------------
class TVarLookupForm : public TForm
{
__published:	// IDE-managed Components
	TcxButton *cxButton1;
	TcxButton *cxButton2;
	TcxButton *cxButton3;
	TcxButton *cxButton4;
	TcxButton *cxButton5;
	TcxButton *cxButton6;
	TcxButton *cxButton7;
	TFlowPanel *FlowPanel1;
	TcxLabel *cxLabel1;
	TcxTextEdit *cxTextEdit1;
	TcxLabel *cxLabel2;
	TcxTextEdit *cxTextEdit2;
	TcxLabel *cxLabel3;
	TcxTextEdit *cxTextEdit3;
	TcxLabel *cxLabel4;
	TcxTextEdit *cxTextEdit4;
	TcxLabel *cxLabel5;
	TcxTextEdit *cxTextEdit5;
	TFlowPanel *FlowPanel2;
	TcxRadioGroup *cxRadioGroup1;
	TOpenDialog *OpenDialog1;
	void __fastcall cxButton1Click(TObject *Sender);
	void __fastcall cxButton2Click(TObject *Sender);
	void __fastcall cxButton3Click(TObject *Sender);
	void __fastcall cxButton4Click(TObject *Sender);
	void __fastcall cxButton5Click(TObject *Sender);
	void __fastcall cxRadioGroup1Click(TObject *Sender);
	void __fastcall cxTextEdit2PropertiesChange(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TVarLookupForm(TComponent* Owner);
};
//---------------------------------------------------------------------------

class TShortVarLookupForm : public TVarLookupForm
{
public:
	__fastcall TShortVarLookupForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TVarLookupForm *VarLookupForm;
extern PACKAGE TShortVarLookupForm *ShortVarLookupForm;
//---------------------------------------------------------------------------
#endif
