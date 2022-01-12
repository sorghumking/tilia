//---------------------------------------------------------------------------

#ifndef TNTaxaH
#define TNTaxaH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <CheckLst.hpp>
#include <ComCtrls.hpp>
#include "cxButtons.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include <Menus.hpp>
#include "ipwjson.h"
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include "ipshttps.h"
#include <Sockets.hpp>
#include "ipsjsons.h"
#include "ipwhttp.h"
#include <ImgList.hpp>
#include "dxSkinBlack.hpp"
#include "dxSkinBlue.hpp"
#include "dxSkinBlueprint.hpp"
#include "dxSkinCaramel.hpp"
#include "dxSkinCoffee.hpp"
#include "dxSkinDarkRoom.hpp"
#include "dxSkinDarkSide.hpp"
#include "dxSkinDevExpressDarkStyle.hpp"
#include "dxSkinDevExpressStyle.hpp"
#include "dxSkinFoggy.hpp"
#include "dxSkinGlassOceans.hpp"
#include "dxSkinHighContrast.hpp"
#include "dxSkiniMaginary.hpp"
#include "dxSkinLilian.hpp"
#include "dxSkinLiquidSky.hpp"
#include "dxSkinLondonLiquidSky.hpp"
#include "dxSkinMcSkin.hpp"
#include "dxSkinMetropolis.hpp"
#include "dxSkinMetropolisDark.hpp"
#include "dxSkinMoneyTwins.hpp"
#include "dxSkinOffice2007Black.hpp"
#include "dxSkinOffice2007Blue.hpp"
#include "dxSkinOffice2007Green.hpp"
#include "dxSkinOffice2007Pink.hpp"
#include "dxSkinOffice2007Silver.hpp"
#include "dxSkinOffice2010Black.hpp"
#include "dxSkinOffice2010Blue.hpp"
#include "dxSkinOffice2010Silver.hpp"
#include "dxSkinOffice2013DarkGray.hpp"
#include "dxSkinOffice2013LightGray.hpp"
#include "dxSkinOffice2013White.hpp"
#include "dxSkinPumpkin.hpp"
#include "dxSkinsCore.hpp"
#include "dxSkinsDefaultPainters.hpp"
#include "dxSkinSeven.hpp"
#include "dxSkinSevenClassic.hpp"
#include "dxSkinSharp.hpp"
#include "dxSkinSharpPlus.hpp"
#include "dxSkinSilver.hpp"
#include "dxSkinSpringTime.hpp"
#include "dxSkinStardust.hpp"
#include "dxSkinSummer2008.hpp"
#include "dxSkinTheAsphaltWorld.hpp"
#include "dxSkinValentine.hpp"
#include "dxSkinVS2010.hpp"
#include "dxSkinWhiteprint.hpp"
#include "dxSkinXmas2008Blue.hpp"
#include "dxSkinOffice2016Colorful.hpp"
#include "dxSkinOffice2016Dark.hpp"
#include "dxSkinVisualStudio2013Blue.hpp"
#include "dxSkinVisualStudio2013Dark.hpp"
#include "dxSkinVisualStudio2013Light.hpp"
#ifndef TIJSONH
#include "TIJSON.h"
#endif
//---------------------------------------------------------------------------

enum DATASETTYPES { NODATASETTYPE, POLLEN, VERTEBRATE, PLANTMACROFOSSIL,
					MACROINVERTEBRATE, OSTRACODE, DIATOM };
//---------------------------------------------------------------------------

typedef struct
{
  CODENAME TaxaGroup;
  vector<CODENAME> EcolGroups;
} ECOLOGICALGROUP;
//---------------------------------------------------------------------------

class ELEMENTUNIT
{
public:
  UnicodeString Element;
  UnicodeString Units;
public:
  ELEMENTUNIT(UnicodeString& el, UnicodeString& un) { Element = el; Units = un; }
};
//---------------------------------------------------------------------------

class ElementUnits
{
public:
  vector<ELEMENTUNIT> eu;
  map<UnicodeString, vector<UnicodeString> > ElementTree;
public:
  ElementUnits() { };
  void Add(UnicodeString& element, UnicodeString& units);
  void BuildElementTree(void);
};
//---------------------------------------------------------------------------

class GENERICDATASETTYPE
{
public:
  UnicodeString Type;                   // generic type, e.g. pollen
  vector<UnicodeString> DatasetTypes;   // Neotoma DatasetTypes, e.g. pollen surface sample
public:
  GENERICDATASETTYPE(UnicodeString type) { Type = type; };
};
//---------------------------------------------------------------------------

class TNeotomaTaxaLookupForm : public TForm
{
__published:	// IDE-managed Components
	TStatusBar *StatusBar1;
	TCheckListBox *CheckListBox1;
	TcxButton *cxButton1;
	TGroupBox *GroupBox1;
	TGroupBox *GroupBox2;
	TCheckListBox *CheckListBox2;
	TcxButton *cxButton3;
	TSaveDialog *SaveDialog1;
	TcxButton *cxButton5;
	TcxButton *cxButton6;
	TGroupBox *GroupBox3;
	TEdit *Edit1;
	TcxButton *cxButton8;
	TPanel *Panel1;
	TTcpClient *TcpClient1;
	TcxImageList *cxImageList1;
	TRadioGroup *RadioGroup1;
	TipsJSONS *ipsJSONS1;
	void __fastcall CheckListBox1ClickCheck(TObject *Sender);
	void __fastcall cxButton1Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall cxButton3Click(TObject *Sender);
	void __fastcall Edit1Change(TObject *Sender);
	void __fastcall cxButton8Click(TObject *Sender);
	void __fastcall cxButton5Click(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall ipsJSONS1SSLServerAuthentication(TObject *Sender, TipsJSONSSSLServerAuthenticationEventParams *e);


private:
	bool GetFileName(void);
	void GetDynamicTaxaGroups(vector<UnicodeString>& TaxaLookup);
	void GetPredefinedTaxaGroups(vector<UnicodeString>& TaxaLookup);
	void GetTaxaGroups(vector<UnicodeString>& TaxaLookup, NeotomaTaxaGroupCodesBase& TaxaGroupCodes);
	void GetEcolGroups(void);
	bool LookupDatasetsInclude(UnicodeString DatasetType);
	static CompStr (UnicodeString s1, UnicodeString s2) { return (s1 < s2); }
private:	// User declarations
	bool activated;
	vector<UnicodeString> NeotomaLookupFiles;
	vector<UnicodeString> LookupDatasetTypes;  // list of dataset types in lookup file
	map<UnicodeString, UnicodeString> LookupFileDatasetTypes;
	vector<GENERICDATASETTYPE> GenericDatasetTypes;
	map<int, vector<UnicodeString> > DefaultUnits;
	vector<UnicodeString> PollenElements;
	UnicodeString FileName;
	NeotomaDatasetTypesTable *DatasetTypes;
	map<UnicodeString, UnicodeString> DatasetTypeTaxaGroups;  // TaxaGroup, TaxaGroupID
	vector<ECOLOGICALGROUP> EcologicalGroups;
public:		// User declarations
	__fastcall TNeotomaTaxaLookupForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TNeotomaTaxaLookupForm *NeotomaTaxaLookupForm;
//---------------------------------------------------------------------------
#endif
