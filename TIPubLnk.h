//---------------------------------------------------------------------------

#ifndef TIPubLnkH
#define TIPubLnkH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TPubLinkForm : public TForm
{
__published:	// IDE-managed Components
        TListBox *ListBox1;
private:	// User declarations
public:		// User declarations
        __fastcall TPubLinkForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TPubLinkForm *PubLinkForm;
//---------------------------------------------------------------------------
#endif
