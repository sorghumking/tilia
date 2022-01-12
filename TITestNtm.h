//---------------------------------------------------------------------------

#ifndef TITestNtmH
#define TITestNtmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TWebServicesForm : public TForm
{
__published:	// IDE-managed Components
	TListBox *ListBox1;
private:	// User declarations
public:		// User declarations
	__fastcall TWebServicesForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TWebServicesForm *WebServicesForm;
//---------------------------------------------------------------------------
#endif
