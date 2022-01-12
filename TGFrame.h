//---------------------------------------------------------------------------

#ifndef TGFrameH
#define TGFrameH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>

#ifndef TGDiagrmH
#include "TGDiagrm.h"
#endif
#ifndef TGUtilsH
#include "TGUtils.h"
#endif

//---------------------------------------------------------------------------
class TFrameForm : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TGroupBox *GroupBox1;
	TCheckBox *CheckBox1;
	TComboBox *LineWidthComboBox1;
	TLabel *Label1;
	TColorBox *ColorBox1;
	TLabel *Label2;
	TGroupBox *GroupBox2;
	TLabeledEdit *LabeledEdit1;
	TLabeledEdit *LabeledEdit2;
	TLabeledEdit *LabeledEdit3;
	TLabeledEdit *LabeledEdit4;
	TLabeledEdit *LabeledEdit5;
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall CheckBox1Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	bool __fastcall FormHelp(WORD Command, int Data, bool &CallHelp);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
private:	// User declarations
	LineWidthComboBox *FramLineWidthComboBox;
	TTGDiagram* Diag;
public:		// User declarations
	__fastcall TFrameForm(TComponent* Owner);

};
//---------------------------------------------------------------------------
extern PACKAGE TFrameForm *FrameForm;
//---------------------------------------------------------------------------
#endif
