//---------------------------------------------------------------------------

#ifndef TGRareH
#define TGRareH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <ImgList.hpp>
#include <ToolWin.hpp>
#ifndef TGDiagrmH
#include "TGDiagrm.h"
#endif
#ifndef TGUtilsH
#include "TGUtils.h"
#endif
//---------------------------------------------------------------------------
class TRareForm : public TForm
{
__published:	// IDE-managed Components
        TToolBar *ToolBar1;
        TToolButton *ToolButton1;
        TToolButton *ToolButton2;
        TImageList *ImageList1;
        TLabel *Label1;
        TLabeledEdit *LabeledEdit1;
        TButton *Button1;
        TButton *Button2;
        TButton *Button3;
        TComboBox *LineWidthComboBox1;
        TLabel *Label2;
        void __fastcall FormActivate(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall ToolButton1Click(TObject *Sender);
        void __fastcall ToolButton2Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        bool __fastcall FormHelp(WORD Command, int Data, bool &CallHelp);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormDestroy(TObject *Sender);
private:	// User declarations
        LineWidthComboBox *RareLineWidthComboBox;
public:		// User declarations
        __fastcall TRareForm(TComponent* Owner);
        TTGDiagram* Diag;
};
//---------------------------------------------------------------------------
extern PACKAGE TRareForm *RareForm;
//---------------------------------------------------------------------------
#endif
