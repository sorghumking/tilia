//---------------------------------------------------------------------------

#ifndef TINewAnlH
#define TINewAnlH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TNewAnalystForm : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TListBox *ListBox1;
        TLabel *Label2;
        TPanel *Panel1;
        TLabel *Label3;
        TLabeledEdit *LabeledEdit1;
        TLabeledEdit *LabeledEdit2;
        TLabel *Label4;
        TButton *Button1;
        TButton *Button2;
        TImage *Image1;
        TButton *Button3;
        void __fastcall ListBox1Click(TObject *Sender);
        void __fastcall LabeledEdit1Enter(TObject *Sender);
        void __fastcall LabeledEdit2Enter(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TNewAnalystForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TNewAnalystForm *NewAnalystForm;
//---------------------------------------------------------------------------
#endif
