//---------------------------------------------------------------------------

#ifndef TISynFrmH
#define TISynFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include "AdvGrid.hpp"
#include "AdvObj.hpp"
#include "BaseGrid.hpp"
#include "cxButtons.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include <Grids.hpp>
#include <Menus.hpp>
#include "AdvCGrid.hpp"
#include <ImgList.hpp>

#ifndef TISpreadH
#include "TISpread.h"
#endif
#ifndef TNSynInfoH
#include "TNSynInfo.h"
#endif
//---------------------------------------------------------------------------
class TSynonymsForm : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TLabel *Label1;
	TcxButton *cxButton3;
	TcxButton *cxButton4;
	TcxButton *cxButton5;
	TcxButton *cxButton6;
	TAdvColumnGrid *AdvColumnGrid1;
	TcxButton *cxButton7;
	TcxButton *cxButton8;
	TImageList *ImageList1;
	void __fastcall cxButton3Click(TObject *Sender);
	void __fastcall cxButton4Click(TObject *Sender);
	void __fastcall cxButton5Click(TObject *Sender);
	void __fastcall cxButton6Click(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall AdvColumnGrid1GridHint(TObject *Sender, int ARow, int ACol, UnicodeString &hintstr);
	void __fastcall cxButton7Click(TObject *Sender);
	void __fastcall AdvColumnGrid1ButtonClick(TObject *Sender, int ACol, int ARow);
	void __fastcall cxButton8Click(TObject *Sender);
	void __fastcall AdvColumnGrid1CheckBoxClick(TObject *Sender, int ACol, int ARow,
		  bool State);
protected:
	vector<SYNONYMROW> synrows;
private:	// User declarations
	TTilSpreadSheetForm *TSSForm;
	map<unsigned int, unsigned int> idx;  // idx, row; index for synrows
	Graphics::TBitmap *Glyph;
public:		// User declarations
	__fastcall TSynonymsForm(vector<SYNONYMROW>& sr, TComponent* Owner);
	void SetSynonyms(vector<SYNONYMROW>&);
	void GetSynonyms(vector<SYNONYMROW>&);
};
//---------------------------------------------------------------------------

class TLocalSynonymsForm : public TSynonymsForm
{
__published:	// IDE-managed Components
	void __fastcall AdvColumnGrid1GridHint(TObject *Sender, int ARow, int ACol, UnicodeString &hintstr);
	void __fastcall cxButton7Click(TObject *Sender);
public:		// User declarations
	__fastcall TLocalSynonymsForm(vector<SYNONYMROW>& sr, TComponent* Owner);
};
//---------------------------------------------------------------------------

extern PACKAGE TSynonymsForm *SynonymsForm;
extern PACKAGE TLocalSynonymsForm *LocalSynonymsForm;
//---------------------------------------------------------------------------
#endif
