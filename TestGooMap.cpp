//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TestGooMap.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "UWebGMaps"
#pragma link "UWebGMapsCommon"
#pragma resource "*.dfm"
TTestGoogleMapForm *TestGoogleMapForm;
//---------------------------------------------------------------------------
__fastcall TTestGoogleMapForm::TTestGoogleMapForm(TComponent* Owner)
	: TForm(Owner)
{
   WebGMaps1->MapOptions->DefaultLatitude = 45.0;
   WebGMaps1->MapOptions->DefaultLongitude = -93.0;
}
//---------------------------------------------------------------------------
