//---------------------------------------------------------------------------

#ifndef TIUpDepEnvH
#define TIUpDepEnvH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxEdit.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include "cxTreeView.hpp"
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include "cxButtons.hpp"
#include "cxLabel.hpp"
#include <Graphics.hpp>
#include <Menus.hpp>
#include <ImgList.hpp>
#include "cxImage.hpp"
#include "cxCheckBox.hpp"
#include "cxGroupBox.hpp"
#include "dxtree.hpp"
#include "ipshttps.h"
#include "ipwjson.h"
#include <Sockets.hpp>
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
#include "dxSkinOffice2016Colorful.hpp"
#include "dxSkinOffice2016Dark.hpp"
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
#include "dxSkinVisualStudio2013Blue.hpp"
#include "dxSkinVisualStudio2013Dark.hpp"
#include "dxSkinVisualStudio2013Light.hpp"
#include "dxSkinVS2010.hpp"
#include "dxSkinWhiteprint.hpp"
#include "dxSkinXmas2008Blue.hpp"
#include "ipsjsons.h"
#include <deque>
#ifndef TISpreadH
#include "TISpread.h"
#endif
#ifndef TIUploadH
#include "TIUpload.h"
#endif

//---------------------------------------------------------------------------
class TNewDepEnvtForm : public TForm
{
__published:	// IDE-managed Components
	TcxImageList *cxImageList1;
	TPanel *Panel1;
	TLabel *Label1;
	TImage *Image1;
	TcxButton *cxButton7;
	TcxButton *cxButton8;
	TPanel *Panel2;
	TImage *Image2;
	TLabel *Label2;
	TGroupBox *GroupBox2;
	TImage *Image3;
	TLabel *Label3;
	TImage *Image4;
	TLabel *Label4;
	TImage *Image5;
	TLabel *Label5;
	TcxButton *cxButton9;
	TcxButton *cxButton10;
	TcxButton *cxButton11;
	TcxButton *cxButton12;
	TcxGroupBox *cxGroupBox1;
	TcxCheckBox *cxCheckBox1;
	TcxCheckBox *cxCheckBox2;
	TPanel *Panel3;
	TcxButton *cxButton13;
	TcxButton *cxButton14;
	TdxTreeView *dxTreeView1;
	TipsHTTPS *ipsHTTPS1;
	TTcpClient *TcpClient1;
	TipsJSONS *ipsJSONS1;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall cxButton7Click(TObject *Sender);
	void __fastcall cxButton8Click(TObject *Sender);
	void __fastcall cxButton9Click(TObject *Sender);
	void __fastcall cxButton14Click(TObject *Sender);
	void __fastcall cxButton11Click(TObject *Sender);
	void __fastcall cxButton13Click(TObject *Sender);
	void __fastcall cxCheckBox1Click(TObject *Sender);
	void __fastcall dxTreeView1DragDropTreeNode(TTreeNode *Destination, TTreeNode *Source,
          bool &Accept);
	void __fastcall dxTreeView1Edited(TObject *Sender, TTreeNode *Node, UnicodeString &S);
	void __fastcall dxTreeView1Changing(TObject *Sender, TTreeNode *Node, bool &AllowChange);
	void __fastcall dxTreeView1EndDragTreeNode(TTreeNode *Destination, TTreeNode *Source,
          TNodeAttachMode &AttachMode);
	void __fastcall dxTreeView1Editing(TObject *Sender, TTreeNode *Node, bool &AllowEdit);
	void __fastcall dxTreeView1EndDrag(TObject *Sender, TObject *Target, int X, int Y);
	void __fastcall cxButton10Click(TObject *Sender);
	void __fastcall ipsJSONS1SSLServerAuthentication(TObject *Sender, TipsJSONSSSLServerAuthenticationEventParams *e);


private:	// User declarations
	TNeotomaUploadForm* upf;
	TTilSpreadSheetForm* TSSForm;
	vector<TREENODE> DepEnvts;
	vector<TREENODE> NewDepEnvts;
	UnicodeString NewDepEnv;
	TTreeNode *SelectedNode;
	TTreeNode *NewNode;
	TTreeNode *DroppedNode;
	vector<TTreeNode*> NewNodes;
	vector<TTreeNode*> OptionalNodes;
	vector<TTreeNode*> CutNodes;
	bool cxTreeView2CanSelect;
	bool Modified;
private:
	bool Go(void);
	void DepEnvtsAdd(int, UnicodeString, int);
	int DepEnvtFindID(UnicodeString);
	void GetAllChildNodes(TTreeNode*, vector<TTreeNode*>&);
	TTreeNode* FindTreeNode(TdxTreeView*, UnicodeString);
	TTreeNode* FindTreeNode(TdxTreeViewEdit*, UnicodeString);
	bool Upload(UnicodeString&);
	bool UploadNewDepEnvt(UnicodeString, int, vector<int>&, UnicodeString&);
public:		// User declarations
	__fastcall TNewDepEnvtForm(TComponent* Owner);
	bool Uploaded;
};
//---------------------------------------------------------------------------
extern PACKAGE TNewDepEnvtForm *NewDepEnvtForm;
//---------------------------------------------------------------------------
#endif
