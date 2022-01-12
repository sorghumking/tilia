//---------------------------------------------------------------------------
#ifndef TGSelVarH
#define TGSelVarH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <CheckLst.hpp>
//---------------------------------------------------------------------------
class TSelectVariableForm : public TForm
{
__published:	// IDE-managed Components
        TCheckListBox *CheckListBox1;
        TButton *Button1;
        TButton *Button2;
        TButton *Button3;
        TButton *Button4;
        TButton *Button5;
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall Button5Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TSelectVariableForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TSelectVariableForm *SelectVariableForm;
//---------------------------------------------------------------------------
#endif
