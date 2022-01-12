//---------------------------------------------------------------------------

#ifndef TIConOutH
#define TIConOutH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Menus.hpp>
#include <Dialogs.hpp>
#ifndef TIConFrmH
#include "TIConFrm.h"
#endif

//---------------------------------------------------------------------------
class TCONISSOutput : public TForm
{
__published:	// IDE-managed Components
        TRichEdit *RichEdit1;
        TMainMenu *MainMenu1;
        TMenuItem *File1;
        TMenuItem *Saveas1;
        TMenuItem *Print1;
        TMenuItem *Close1;
        TSaveDialog *SaveDialog1;
        TPrinterSetupDialog *PrinterSetupDialog1;
        TMenuItem *PrintSetup1;
        void __fastcall Saveas1Click(TObject *Sender);
        void __fastcall Print1Click(TObject *Sender);
        void __fastcall PrintSetup1Click(TObject *Sender);
        void __fastcall Close1Click(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
        TConissForm* ConissForm;
public:		// User declarations
        __fastcall TCONISSOutput(TComponent* Owner);
		UnicodeString OutputFileName;
};
//---------------------------------------------------------------------------
extern PACKAGE TCONISSOutput *CONISSOutput;
//---------------------------------------------------------------------------
#endif
