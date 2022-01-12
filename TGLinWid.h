//---------------------------------------------------------------------------
#ifndef TGLinWidH
#define TGLinWidH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#ifndef TGDiagrmH
#include "TGDiagrm.h"
#endif
#ifndef TGUtilsH
#include "TGUtils.h"
#endif
//---------------------------------------------------------------------------
class TLineWidthForm : public TForm
{
__published:	// IDE-managed Components
        TComboBox *LineWidthComboBox1;
        TComboBox *LineWidthComboBox2;
        TComboBox *LineWidthComboBox3;
        TComboBox *LineWidthComboBox4;
        TComboBox *LineWidthComboBox5;
        TComboBox *LineWidthComboBox6;
        TComboBox *LineWidthComboBox7;
        TComboBox *LineWidthComboBox8;
        TComboBox *LineWidthComboBox9;
        TButton *Button1;
        TButton *Button2;
        TButton *HelpButton;
        TComboBox *LineWidthComboBox10;
        TLabel *Label10;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
        TLabel *Label7;
        TLabel *Label8;
        TLabel *Label9;
        TComboBox *LineWidthComboBox11;
        TLabel *Label11;
        TComboBox *LineWidthComboBox12;
        TLabel *Label12;
        void __fastcall LineWidthComboBox1Change(TObject *Sender);
        void __fastcall HelpButtonClick(TObject *Sender);
		//bool __fastcall FormHelp(WORD Command, int Data, bool &CallHelp);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormDestroy(TObject *Sender);
        void __fastcall FormActivate(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
		bool __fastcall FormHelp(WORD Command, int Data, bool &CallHelp);
private:	// User declarations
        LineWidthComboBox *DfltLineWidthComboBox;
        LineWidthComboBox *AxisLineWidthComboBox;
        LineWidthComboBox *SilhLineWidthComboBox;
        LineWidthComboBox *HistLineWidthComboBox;
        LineWidthComboBox *GridLineWidthComboBox;
        LineWidthComboBox *GrupLineWidthComboBox;
        LineWidthComboBox *DendLineWidthComboBox;
        LineWidthComboBox *ZoneLineWidthComboBox;
        LineWidthComboBox *FramLineWidthComboBox;
        LineWidthComboBox *EndlLineWidthComboBox;
        LineWidthComboBox *LiCoLineWidthComboBox;
        LineWidthComboBox *LiKyLineWidthComboBox;
public:		// User declarations
        __fastcall TLineWidthForm(TComponent* Owner);
        TTGDiagram* Diag;
};
//---------------------------------------------------------------------------
extern PACKAGE TLineWidthForm *LineWidthForm;
//---------------------------------------------------------------------------
#endif
