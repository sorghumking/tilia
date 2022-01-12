//---------------------------------------------------------------------------

#ifndef TGZoneLiH
#define TGZoneLiH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ImgList.hpp>
#include <ToolWin.hpp>
#include <ExtCtrls.hpp>
#include <Dialogs.hpp>

#ifndef TGH
#include "tg.h"
#endif
#ifndef TGUtilsH
#include "TGUtils.h"
#endif

//---------------------------------------------------------------------------
class TZoneLineForm : public TForm
{
__published:	// IDE-managed Components
        TToolBar *ToolBar1;
        TToolButton *ToolButton1;
        TToolButton *ToolButton2;
        TToolButton *ToolButton3;
        TToolButton *ToolButton4;
        TToolButton *ToolButton5;
        TImageList *ZoneLineImages;
        TButton *Button1;
        TButton *Button2;
        TButton *Button3;
        TImage *Image1;
        TComboBox *LineWidthComboBox1;
        TLabel *Label3;
        TColorDialog *ColorDialog1;
        TCheckBox *CheckBox1;
        TColorBox *ColorBox1;
        TLabel *Label4;
        TLabeledEdit *LabeledEdit1;
        TLabeledEdit *LabeledEdit2;
        void __fastcall ToolButton1Click(TObject *Sender);
        void __fastcall ToolButton2Click(TObject *Sender);
        void __fastcall ToolButton3Click(TObject *Sender);
        void __fastcall ToolButton4Click(TObject *Sender);
        void __fastcall ToolButton5Click(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormActivate(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall LabeledEdit1Exit(TObject *Sender);
        void __fastcall LabeledEdit2Exit(TObject *Sender);
        bool __fastcall FormHelp(WORD Command, int Data, bool &CallHelp);
        void __fastcall FormDestroy(TObject *Sender);
private:	// User declarations
        int Dash, Space;
		LineWidthComboBox *ZoneLineWidthComboBox;
		TTGDiagram* Diag;
public:		// User declarations
        __fastcall TZoneLineForm(TComponent* Owner);
        ZONE* Zone;
        ZONE* DefaultZone;
        void DrawZoneLine(int, int);
};
//---------------------------------------------------------------------------
extern PACKAGE TZoneLineForm *ZoneLineForm;
//---------------------------------------------------------------------------
#endif
