//---------------------------------------------------------------------------

#ifndef TGItalicH
#define TGItalicH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>

enum ITALICS { ITALICIZE, REMOVEITALICS, AUTOITALICS };

//---------------------------------------------------------------------------
class TItalicsForm : public TForm
{
__published:	// IDE-managed Components
        TButton *Button1;
        TButton *Button2;
        TButton *Button3;
        TButton *Button4;
        TButton *Button5;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall FormActivate(TObject *Sender);
        void __fastcall Button5Click(TObject *Sender);
        bool __fastcall FormHelp(WORD Command, int Data, bool &CallHelp);
private:	// User declarations
public:		// User declarations
        __fastcall TItalicsForm(TComponent* Owner);
        int Action;
};
//---------------------------------------------------------------------------
extern PACKAGE TItalicsForm *ItalicsForm;
//---------------------------------------------------------------------------
#endif
