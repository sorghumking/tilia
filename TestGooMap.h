//---------------------------------------------------------------------------

#ifndef TestGooMapH
#define TestGooMapH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "UWebGMaps.hpp"
#include "UWebGMapsCommon.hpp"
//---------------------------------------------------------------------------
class TTestGoogleMapForm : public TForm
{
__published:	// IDE-managed Components
	TWebGMaps *WebGMaps1;
private:	// User declarations
public:		// User declarations
	__fastcall TTestGoogleMapForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTestGoogleMapForm *TestGoogleMapForm;
//---------------------------------------------------------------------------
#endif
