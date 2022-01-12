//---------------------------------------------------------------------------

#ifndef TIErrFrmH
#define TIErrFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TErrorListForm : public TForm
{
__published:	// IDE-managed Components
        TMemo *Memo1;
        TButton *Button1;
        TButton *Button2;
private:	// User declarations
public:		// User declarations
        __fastcall TErrorListForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TErrorListForm *ErrorListForm;
//---------------------------------------------------------------------------
#endif
