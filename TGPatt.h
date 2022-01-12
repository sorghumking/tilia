//---------------------------------------------------------------------------
#ifndef TGPattH
#define TGPattH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ImgList.hpp>
#include <ToolWin.hpp>
//---------------------------------------------------------------------------
class TPatternForm : public TForm
{
__published:	// IDE-managed Components
        TToolBar *ToolBar1;
        TToolButton *ToolButton1;
        TToolButton *ToolButton2;
        TToolButton *ToolButton3;
        TToolButton *ToolButton4;
        TToolButton *ToolButton5;
        TToolButton *ToolButton6;
        TImageList *PatternImageList;
        TToolButton *ToolButton7;
        TToolButton *ToolButton8;
        TToolButton *ToolButton9;
        TToolButton *ToolButton10;
        TToolButton *ToolButton11;
        TToolButton *ToolButton12;
        TToolButton *ToolButton13;
        TToolButton *ToolButton14;
        TToolButton *ToolButton15;
        TToolButton *ToolButton16;
        TToolButton *ToolButton17;
        TToolButton *ToolButton18;
        TToolButton *ToolButton19;
        TToolButton *ToolButton20;
        TToolButton *ToolButton21;
        TToolButton *ToolButton22;
        TToolButton *ToolButton23;
        TToolButton *ToolButton24;
        TToolButton *ToolButton25;
        TToolButton *ToolButton26;
        TToolButton *ToolButton27;
        TToolButton *ToolButton28;
        TToolButton *ToolButton29;
        TToolButton *ToolButton30;
        TToolButton *ToolButton31;
        TToolButton *ToolButton32;
        TToolButton *ToolButton33;
        TButton *Button1;
        TButton *Button2;
        void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TPatternForm(TComponent* Owner);
        short PatternIndex;
        void Initialize(short);
};
//---------------------------------------------------------------------------
extern PACKAGE TPatternForm *PatternForm;
//---------------------------------------------------------------------------
#endif
