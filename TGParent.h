//---------------------------------------------------------------------------
#ifndef TGParentH
#define TGParentH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <Dialogs.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
#include <ImgList.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
#include <ActnCtrls.hpp>
#include <ActnMan.hpp>
#include <ActnMenus.hpp>
#include <ActnList.hpp>
#include <HTMLHelpViewer.hpp>
#include "cxPC.hpp"
#include "ProfGrid.hpp"
#include <Grids.hpp>
#include <Outline.hpp>
#include "cxGraphics.hpp"
#ifndef TISpreadH
#include "TISpread.h"
#endif
#ifndef TIWhitmoreH
#include "TIWhitmore.h"
#endif
#ifndef TGDiagrmH
#include "TGDiagrm.h"
#endif
#ifndef TIUtilsH
#include "TIUtils.h"
#endif
#ifndef TITrainH
#include "TITrain.h"
#endif
#ifndef TINeotomaH
#include "TINeotoma.h"
#endif


//---------------------------------------------------------------------------
enum FILETYPE { TGDIAGRAM, TILSPREADSHEET };
enum CUSTOMCURSORS { crSelectCol=1, crSelectRow=2 };
typedef int __stdcall (*MouseHook)(void);
LRESULT CALLBACK MouseProc(int nCode, WPARAM wParam, LPARAM lParam);
//---------------------------------------------------------------------------

/*
typedef struct
{
  UnicodeString VERSION;
  UnicodeString GUID;
} TILIAVERSION;
//---------------------------------------------------------------------------
*/

class TParentForm : public TForm
{
__published:	// IDE-managed Components
    TMainMenu *MainMenu1;
    TMenuItem *File1;
    TMenuItem *Open;
    TOpenDialog *OpenDialog1;
    TPrintDialog *PrintDialog1;
        TMenuItem *Exit1;
        TMenuItem *N1;
		TMenuItem *Help1;
        TMenuItem *About1;
        TMenuItem *Index1;
        TMenuItem *N4;
        TStatusBar *StatusBar1;
        TControlBar *ControlBar1;
        TToolBar *ToolBarFile;
        TToolButton *OpenButton1;
        TToolButton *SaveButton1;
        TToolButton *PrintButton1;
        TToolBar *ToolBarZoomPlusMinus;
        TToolButton *ZoomInButton1;
        TToolButton *ZoomOutButton1;
        TToolBar *ToolBarGraphics;
        TToolButton *YaxisButton1;
        TToolButton *XaxisButton1;
        TToolButton *GraphStyleButton1;
        TToolButton *VariablesButton1;
        TToolButton *ZoneButton1;
        TToolButton *GroupButton1;
        TToolButton *DatesButton1;
        TToolButton *TextButton1;
        TToolButton *InteractiveTextButton1;
        TToolButton *ToolButton20;
        TToolButton *ColorButton1;
        TToolButton *LineWidthButton1;
        TToolButton *FontButton1;
        TToolButton *ToolButton24;
        TToolButton *HideButton1;
        TToolBar *ToolBarHelp;
        TToolButton *HelpButton1;
        TImageList *ImageList1;
        TToolBar *ToolBarZoomText;
        TComboBox *ZoomComboBox;
        TSaveDialog *SaveDialog1;
        TToolButton *FrameButton1;
        TToolButton *RareButton1;
        TToolButton *LithButton1;
        TToolButton *DendrogramButton1;
        TMenuItem *Registration1;
        TToolBar *ToolBarSpreadSheet;
        TToolButton *ToolButtonSSInsertRow;
        TMenuItem *New1;
        TToolButton *ToolButtonSSDeleteRow;
        TToolButton *ToolButtonSSInsertColumn;
        TToolButton *ToolButtonSSDeleteColumn;
        TToolButton *ToolButtonSSSum;
        TToolButton *ToolButtonSSCheckVars;
        TToolButton *ToolButtonSSSort;
        TToolButton *ToolButtonSSCut;
        TToolButton *ToolButtonSSCopy;
        TToolButton *ToolButtonSSPaste;
        TToolButton *ToolButtonSSPercent;
        TToolButton *ToolButtonSSGraphics;
        TToolButton *ToolButtonSSLookup;
        TToolButton *ToolButtonSSEditLookup;
        TPopupMenu *PopupMenu1;
        TMenuItem *TIEditTaxa2;
        TMenuItem *TIEditGroups2;
        TMenuItem *TIEditElements1;
        TMenuItem *TIEditUnits1;
        TMenuItem *TIEditContexts2;
        TMenuItem *TIEditTaphonomy1;
        TActionList *ActionList1;
        TAction *FileOpenAction1;
        TAction *FileNewAction1;
        TAction *ExitAction1;
        TAction *HelpTopicsAction1;
        TAction *AboutAction1;
        TAction *RegistrationAction1;
        TToolButton *NewFileButton1;
	TPopupMenu *PopupMenu2;
	TMenuItem *Login1;
	TAction *NeotomaAction1;
	TMenuItem *Neotoma2;
	TMenuItem *N2;
	TToolBar *ToolBarNeotoma;
	TToolButton *ToolButton3;
	TToolButton *ToolButton9;
	TToolButton *ToolButton4;
	TToolButton *ToolButton8;
	TcxImageList *cxImageList1;
	TcxImageList *cxImageList2;
	TcxImageList *GKSImageList;
	TMenuItem *EPD1;
	TAction *EPDAction1;
	TPopupMenu *PopupMenu3;
	TMenuItem *MakeDiagram1;
	TMenuItem *DefaultDiagram1;
	TMenuItem *Whitmore1;
	TAction *WhitmoreAction1;
	TMenuItem *WebServices1;
	TMenuItem *TSServices1;
        void __fastcall Close1Click(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall PrintClick(TObject *Sender);
		void __fastcall PrintOptions1Click(TObject *Sender);
        void __fastcall Linewidths1Click(TObject *Sender);
        void __fastcall FormActivate(TObject *Sender);
        void __fastcall ZoomInButtonClick(TObject *Sender);
        void __fastcall ZoomOutButtonClick(TObject *Sender);
        void __fastcall HideButtonClick(TObject *Sender);
        void __fastcall AddTextButtonClick(TObject *Sender);
        void __fastcall ZoomComboBoxChange(TObject *Sender);
        void __fastcall ZoomComboBoxKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall Test1Click(TObject *Sender);
        void __fastcall File1Click(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall ToolButtonSSSortClick(TObject *Sender);
        void __fastcall ToolButtonSSCopyClick(TObject *Sender);
        void __fastcall ToolButtonSSCutClick(TObject *Sender);
        void __fastcall ToolButtonSSPasteClick(TObject *Sender);
        void __fastcall ToolButtonSSInsertRowClick(TObject *Sender);
        void __fastcall ToolButtonSSDeleteRowClick(TObject *Sender);
        void __fastcall ToolButtonSSInsertColumnClick(TObject *Sender);
        void __fastcall ToolButtonSSDeleteColumnClick(TObject *Sender);
        void __fastcall ToolButtonSSSumClick(TObject *Sender);
        void __fastcall ToolButtonSSPercentClick(TObject *Sender);
        void __fastcall ToolButtonSSLookupClick(TObject *Sender);
        void __fastcall ToolButtonSSCheckVarsClick(TObject *Sender);
        void __fastcall ToolButtonSSGraphicsClick(TObject *Sender);
        void __fastcall TIEditTaxa2Click(TObject *Sender);
        void __fastcall TIEditGroups2Click(TObject *Sender);
        void __fastcall TIEditElements1Click(TObject *Sender);
        void __fastcall TIEditUnits1Click(TObject *Sender);
        void __fastcall TIEditContexts2Click(TObject *Sender);
        void __fastcall TIEditTaphonomy1Click(TObject *Sender);
        void __fastcall FileOpenAction1Execute(TObject *Sender);
        void __fastcall FileNewAction1Execute(TObject *Sender);
        void __fastcall ExitAction1Execute(TObject *Sender);
        void __fastcall HelpTopicsAction1Execute(TObject *Sender);
        void __fastcall AboutAction1Execute(TObject *Sender);
        void __fastcall RegistrationAction1Execute(TObject *Sender);
        void __fastcall YaxisButton1Click(TObject *Sender);
        void __fastcall XaxisButton1Click(TObject *Sender);
        void __fastcall GraphStyleButton1Click(TObject *Sender);
        void __fastcall VariablesButton1Click(TObject *Sender);
        void __fastcall ZoneButton1Click(TObject *Sender);
        void __fastcall GroupButton1Click(TObject *Sender);
        void __fastcall DatesButton1Click(TObject *Sender);
        void __fastcall LithButton1Click(TObject *Sender);
        void __fastcall TextButton1Click(TObject *Sender);
        void __fastcall FrameButton1Click(TObject *Sender);
        void __fastcall RareButton1Click(TObject *Sender);
        void __fastcall DendrogramButton1Click(TObject *Sender);
        void __fastcall ColorButton1Click(TObject *Sender);
        void __fastcall FontButton1Click(TObject *Sender);
        void __fastcall SaveButton1Click(TObject *Sender);
	void __fastcall Login1Click(TObject *Sender);
	void __fastcall NeotomaAction1Execute(TObject *Sender);
	void __fastcall EPDAction1Execute(TObject *Sender);
	void __fastcall DefaultDiagram1Click(TObject *Sender);
	void __fastcall WhitmoreAction1Execute(TObject *Sender);
	void __fastcall WebServices1Click(TObject *Sender);
	void __fastcall TSServices1Click(TObject *Sender);
private:	// User declarations
	void __fastcall DrawMenuItem(UnicodeString, TCanvas*, TRect&, bool);
	bool CommandLineFileOpened;
    void PrintDiagram(void);
    bool ValidFileExt(UnicodeString&, short*);
    bool ZoomKey;
    void Zoom(double);
	TTilSpreadSheetForm* __fastcall GetSSForm(void);
	TTGDiagram* __fastcall GetTGForm(void);
    void EnableMenuItem(TMenuItem*, int);
	void DisableMenuItem(TMenuItem*, int);
	TTilSpreadSheetForm* NewSpreadSheetForm(void);
	void SetToolBars(vector<TToolBar*>& ToolBars);
	void NeotomaLogin(void);
public:		// User declarations
	__fastcall TParentForm(TComponent* Owner);
	friend TTilSpreadSheetForm;
	friend TTGDiagram;
	friend class TWhitmoreForm;
	bool MainMenuClicked;
	void OpenTGDiagramWindow(DiagramParams& Params);
	void OpenSpreadSheetWindow(UnicodeString&);
	TPoint CurrentChildPos;
	vector<HFONT> FontList;
	vector<Graphics::TBitmap*> GKSBitmaps;
	void SetZoom(void);
	void CloseChild(void);
	int __fastcall ActiveMDIFormType(void);
	int __fastcall MDIFormType(int);
	void ActivateSpreadsheetMenu(bool, TPageControl*, TcxPageControl*, TPageControl*);
	void ActivateDiagramMenu(bool);
	void RemoveTGEditToolBar(TForm*);
};
//---------------------------------------------------------------------------
extern PACKAGE TParentForm *ParentForm;
//---------------------------------------------------------------------------
#endif
