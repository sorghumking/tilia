//---------------------------------------------------------------------------

#ifndef TGNewTxtH
#define TGNewTxtH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <Dialogs.hpp>

#ifndef TGH
#include "TG.h"
#endif

//---------------------------------------------------------------------------
class TNewTextForm : public TForm
{
__published:	// IDE-managed Components
        TBitBtn *BitBtn1;
        TBitBtn *BitBtn2;
        TBitBtn *BitBtn3;
        TBitBtn *BitBtn4;
        TBitBtn *BitBtn5;
        TEdit *Edit1;
        TEdit *Edit2;
        TEdit *Edit3;
        TEdit *Edit4;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TButton *Button3;
        TButton *Button4;
        TButton *Button5;
        TBitBtn *BitBtn6;
        void __fastcall FormActivate(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall BitBtn1Click(TObject *Sender);
        void __fastcall BitBtn2Click(TObject *Sender);
        void __fastcall BitBtn3Click(TObject *Sender);
        void __fastcall BitBtn4Click(TObject *Sender);
        void __fastcall BitBtn5Click(TObject *Sender);
        void __fastcall Button5Click(TObject *Sender);
        void __fastcall BitBtn6Click(TObject *Sender);
        bool __fastcall FormHelp(WORD Command, int Data, bool &CallHelp);
private:	// User declarations
        double x, y, angle;
        void ToggleStyle(int);
public:		// User declarations
        __fastcall TNewTextForm(TComponent* Owner);
        TEXTLINE *Text;
};
//---------------------------------------------------------------------------
extern PACKAGE TNewTextForm *NewTextForm;
//---------------------------------------------------------------------------
#endif
