//---------------------------------------------------------------------------

#ifndef TITrainH
#define TITrainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include "cxGraphics.hpp"
#include <ImgList.hpp>
//---------------------------------------------------------------------------
class TTrainForm : public TForm
{
__published:	// IDE-managed Components
        TImage *Image1;
        TPanel *Panel1;
	TcxImageList *cxTrainImage;
	TcxImageList *cxWheelImages;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormDestroy(TObject *Sender);
        void __fastcall FormActivate(TObject *Sender);
private:	// User declarations
        Graphics::TBitmap *TrainBmp;
        Graphics::TBitmap *WheelsBmp1;
        Graphics::TBitmap *WheelsBmp2;
        Graphics::TBitmap *WheelsBmp3;
        Graphics::TBitmap *WheelsBmp4;
        Graphics::TBitmap *WheelsBmp5;
        Graphics::TBitmap *WheelsBmp6;
        Graphics::TBitmap *WheelsBmp7;
        Graphics::TBitmap *WheelsBmp8;
        int left;
        int WheelPosition;
        TRect TrainRect;
        TRect DestRect;
        TRect WheelsRect;
        TRect TrainWheelsRect;
        TDateTime Time0;
        unsigned int Delay;
        double MaxPosition;
        double MinPosition;
        int Position;
        double RealPosition;
        double Step;
        bool FreeChug;
public:		// User declarations
        __fastcall TTrainForm(TComponent* Owner);
        void __fastcall Chug(void);
        void SetMinMaxPos(int, int, int);
        void __fastcall SetPosition(int);
        void __fastcall ResetPosition(int);
        void SetFreeChug(void);
        void __fastcall IncrementPosition(void);

};
//---------------------------------------------------------------------------
extern PACKAGE TTrainForm *TrainForm;
//---------------------------------------------------------------------------
#endif
