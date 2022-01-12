#ifndef TGDiagrmH
#define TGDiagrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <ComCtrls.hpp>
#include <Controls.hpp>
#include <ImgList.hpp>
#include <ToolWin.hpp>
#include "ipwCore.h"
#include "ipwxmlp.h"
#include <Dialogs.hpp>
#include "ProfGrid.hpp"
#include <Menus.hpp>
#include <ActnList.hpp>
#include "ipworks.h"
#include "cxGraphics.hpp"
//---------------------------------------------------------------------------

#include <vector>
#ifndef TGH
#include "tg.h"
#endif
#ifndef TGDOS
#include "TGDOS.h"
#endif
#ifndef TGYaxisH
#include "TGYaxis.h"
#endif
#ifndef TICommonH
#include "TICommon.h"
#endif
//---------------------------------------------------------------------------

enum XMLDIAGRAM { XML_BACKGROUNDCOLOR, XML_BOXSTYLE, XML_FONT, XML_DEFAULTSETTINGS,
     XML_FRAME, XML_RARESPECIES, XML_YAXIS, XML_LEVEL, XML_STYLES, XML_GRAPHSTYLE,
     XML_XAXES, XML_XAXISSTYLE };
//---------------------------------------------------------------------------

class TTGDiagram : public TForm
{
__published:	// IDE-managed Components
        TToolBar *ToolBar1;
        TToolButton *ToolButton1;
        TToolButton *ToolButton2;
        TToolButton *ToolButton3;
        TToolButton *ToolButton4;
        TImageList *ImageList1;
        TToolButton *ToolButton5;
        TipwXMLp *ipwXMLp1;
        TSaveDialog *SaveDialog1;
        TMainMenu *MainMenu1;
        TMenuItem *TGGraphics;
        TMenuItem *TGColors1;
        TMenuItem *TGLineWidths1;
        TMenuItem *TGFont1;
        TMenuItem *N1;
        TMenuItem *TGYaxes1;
        TMenuItem *TGXaxes1;
        TMenuItem *TGGraphStyles1;
        TMenuItem *TGVariables1;
        TMenuItem *TGZones1;
        TMenuItem *TGGroups1;
        TMenuItem *TGDates1;
        TMenuItem *TGLithology1;
        TMenuItem *TGText1;
        TMenuItem *TGClusterAnalysis1;
        TMenuItem *TGFrame1;
        TMenuItem *TGRare1;
        TMenuItem *TGBoxes1;
        TMenuItem *File1;
        TMenuItem *TG_Open1;
        TMenuItem *TG_New1;
        TMenuItem *TG_Close1;
        TMenuItem *N2;
        TMenuItem *TG_Save1;
        TMenuItem *TG_SaveAs1;
        TMenuItem *TG_Export1;
        TMenuItem *N3;
        TMenuItem *TG_Print1;
        TMenuItem *TG_PrintOptions1;
        TMenuItem *N4;
        TMenuItem *TG_Exit1;
        TPrintDialog *PrintDialog1;
        TActionList *ActionList1;
        TMenuItem *Help1;
        TMenuItem *TG_HelpTopics1;
        TMenuItem *N5;
        TMenuItem *TG_About1;
        TMenuItem *TG_Registration1;
        TAction *FileCloseAction1;
        TAction *FileSaveAction1;
        TAction *FileSaveAsAction1;
        TAction *FileExportAction1;
        TAction *PrintAction1;
        TAction *PrintOptionsAction1;
        TAction *YaxesAction1;
        TAction *XaxesAction1;
        TAction *GraphStyleAction1;
        TAction *VariablesAction1;
        TAction *ZonesAction1;
        TAction *GroupsAction1;
        TAction *DatesAction1;
        TAction *LithologyAction1;
        TAction *TextAction1;
        TAction *ClusterAnalysisAction1;
        TAction *FrameAction1;
        TAction *RareAction1;
        TAction *BoxesAction1;
        TAction *ColorsAction1;
        TAction *LineWidthsAction1;
        TAction *FontAction1;
	TMenuItem *Neotoma1;
	TMenuItem *N6;
	TcxImageList *cxImageList1;
		void __fastcall FormPaint(TObject *Sender);
		void __fastcall FormResize(TObject *Sender);
		void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
		void __fastcall FormActivate(TObject *Sender);
		void __fastcall FormClick(TObject *Sender);
		void __fastcall FormMouseDown(TObject *Sender, TMouseButton Button,
		  TShiftState Shift, int X, int Y);
		void __fastcall ToolButton1Click(TObject *Sender);
		void __fastcall FormMouseUp(TObject *Sender, TMouseButton Button,
		  TShiftState Shift, int X, int Y);
		void __fastcall ToolButton2Click(TObject *Sender);
		void __fastcall ToolButton3Click(TObject *Sender);
		void __fastcall ToolButton4Click(TObject *Sender);
		void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
		  TShiftState Shift);
		void __fastcall FormMouseMove(TObject *Sender, TShiftState Shift,
		  int X, int Y);
		void __fastcall ToolButton5Click(TObject *Sender);
		void __fastcall FormCreate(TObject *Sender);
		void __fastcall FormDeactivate(TObject *Sender);
        void __fastcall FileCloseAction1Execute(TObject *Sender);
        void __fastcall FileSaveAction1Execute(TObject *Sender);
        void __fastcall FileSaveAsAction1Execute(TObject *Sender);
        void __fastcall FileExportAction1Execute(TObject *Sender);
        void __fastcall PrintAction1Execute(TObject *Sender);
        void __fastcall PrintOptionsAction1Execute(TObject *Sender);
        void __fastcall YaxesAction1Execute(TObject *Sender);
        void __fastcall XaxesAction1Execute(TObject *Sender);
        void __fastcall GraphStyleAction1Execute(TObject *Sender);
        void __fastcall VariablesAction1Execute(TObject *Sender);
        void __fastcall ZonesAction1Execute(TObject *Sender);
        void __fastcall GroupsAction1Execute(TObject *Sender);
        void __fastcall DatesAction1Execute(TObject *Sender);
        void __fastcall LithologyAction1Execute(TObject *Sender);
        void __fastcall TextAction1Execute(TObject *Sender);
        void __fastcall ClusterAnalysisAction1Execute(TObject *Sender);
        void __fastcall FrameAction1Execute(TObject *Sender);
        void __fastcall RareAction1Execute(TObject *Sender);
        void __fastcall BoxesAction1Execute(TObject *Sender);
        void __fastcall ColorsAction1Execute(TObject *Sender);
        void __fastcall LineWidthsAction1Execute(TObject *Sender);
        void __fastcall FontAction1Execute(TObject *Sender);
        void __fastcall ipwXMLp1StartElement(TObject *Sender,
          TipwXMLpStartElementEventParams *e);
        void __fastcall ipwXMLp1EndElement(TObject *Sender,
          TipwXMLpEndElementEventParams *e);
        void __fastcall ipwXMLp1Characters(TObject *Sender,
          TipwXMLpCharactersEventParams *e);
        void __fastcall ipwXMLp1SpecialSection(TObject *Sender,
          TipwXMLpSpecialSectionEventParams *e);
        void __fastcall ipwXMLp1Error(TObject *Sender,
          TipwXMLpErrorEventParams *e);
private:	// User declarations
    bool MouseDown;
    bool Dragging;
    int XGraphLeft, XGraphRight;
    int dx;
    TRect GraphRect;
    int XMouse, YMouse;   // mouse coordinates
    TMouseButton MouseButton;
    void MoveGraphLeft(void);
    void MoveGraphRight(void);
    void EditGraph(void);
    bool InsideGraphRect(int X, int Y) {
      return ((X >= GraphRect.Left && X <= GraphRect.Right &&
               Y >= GraphRect.Top && Y <= GraphRect.Bottom) ? true : false); }
	bool diagram_made;
	void display_entire_diagram(void);
	void Print(int);
	bool FormClicked;
	bool AddText;
	bool thicks;
	double *thick;
	double end_graphs;
	double max_ytaxa;		// y-max of graph names
	int ngraphs;
	bool baseline_plotted;
	double symbol_name_ytxt;
	double zone_col_width;
	UnicodeString TicLabel;
	MYFONT *InFont;
    TList *FontList;
    TList *GraphStyles;
    TList *XaxisStyles;
	UnicodeString AttrValue1;
	UnicodeString AttrValue2;
    NEWYAXIS *InYaxis;
    GRAPHS *InGraph;
    XAXIS *InXax;
    GRAPH *InGrf;
    LEVELS *InLev;
    GROUPS *InGroup;
    ZONE *InZone;
    ZONELABELS *InZoneLabel;
    DATES *InDate;
	DENDROGRAM *InDgr;
	LITHUNIT *InLith;
	LITHCOMPONENT *InLithComponent;
    LITHKEY *InLithKey;
    short InHead;
    TEXTLINE *InRandomText;
    int ParentElement;
	int CurrentElement;
	TGXXML tgx;
	list<pair<TColor,UnicodeString> > CustomColors;

private:
    void rotate(double, double*, double*);
    bool plot_yaxes(void);
    void plot_dates(double);
    void plot_text(double, double, char *);
    double set_char_upvec(double);
    void plot_yaxis(int, bool *, bool *, bool *, double *, double *, double *,
                    double *, double, double, double, double, int,double, int,
                    double *, double *, double, double, UnicodeString);
    int getVarNum(UnicodeString&);
    bool plot_graphs(double yfac);
    void plot_Xaxes(int, bool, double, double, double&, double&);
    void plot_grid(int, double);
    void logtic(int, double, double, double *, double *, int, int);
    void label_tic(int, double, double);
    bool last_overlay(int);
	void graphName(int, UnicodeString, double, double);
	void exag_graph(int, int, vector<double>&, vector<double>&, vector<double>&,
		vector<double>&, double, double, double, int);
    double start_gridline(int, int *, double, vector<double>&, vector<double>&);
	double endGridline(int *, double, vector<double>&, vector<double>&, double, int);
    void plot_baseline(int, vector<bool>&, vector<double>&, int, int, double);
    void truncated_numbers(int, vector<double>&, vector<double>&, double, int);
    void box(vector<double>&, vector<double>&, double, double, double, double);
    void plot_rare_species(vector<int>&, vector<double>&, int, int);
	void line_graph(int, vector<double>&, vector<double>&, vector<double>&,
		vector<double>&, vector<double>&, vector<double>&, vector<bool>&, double,
		double, double, double, int, bool, bool, int);
	void numbers_graph(int, vector<double>&, vector<int>&, vector<double>&, double *, int);
	void presence_graph(int, vector<double>&, vector<double>&, vector<bool>&, int,
		double, double, int);
    void Markers(GRAPH *, int, double, double *, double *);
    void symbol_name(int, int, int, double, double);
    void TopSymbolName(int, int, MYFONT&, double, double, double);
    double CenterSymbolLabel(int, MYFONT&, double, double);
    void endLine(void);
    void nameBoxes(void);
    void copy_segments(int, double, double);
    void plot_zones(double);
    void plot_zone_labels(double);
    void zone_segment(int, double);
    void plot_groups(void);
    void plot_heading(void);
    void plot_footer(void);
    void plot_atext(void);
    void plotDendrogram(double, double *);
    void plot_lith(double);
    void plot_lith_boxes(void);
    void plot_frame(void);
	void LoadSSData(DiagramParams& Params);
	void YaxisOptions(int);
	void Text(int);
	void SetColorBox(TColorBox*, TColor);
	void SetCustomColor(TColor AColor, UnicodeString AColorDescription);
	void SetColorComboBox(TcxColorComboBox* ColorComboBox, TColor Color);
	void InitColorComboBoxPopup(TcxColorComboBox* cxColorComboBox);

public:		// User declarations
	friend class TStyleForm;
	friend class TZoneLineForm;
	friend class TZoneScreenForm;
	friend class TGroupForm;
	friend class TLithForm;
	friend class TDendrogramForm;
	friend class TColorsForm;
	friend class TFrameForm;
    __fastcall TTGDiagram(TComponent* Owner);
    TColor BackgroundColor;
    DEFAULT Default;
    MyGraphics *Picture;
    bool Modified;
    bool Boxes;  // boxes style of diagram
	UnicodeString TGFileName;
    UnicodeString ActiveSegment;
    bool file_loaded;
    TList *Levs;
    TList *YAxes;
    TList *Zones;
    TList *ZoneLabels;
    TList *Groups;
    TList *Dates;
    TList *grf;
    TList *RandomText;
    TList *Lithology;
    TList *LithKeys;
    TEXT_BLOCK heading[4];
    TEXT_BLOCK footer;
    TList *Dgr;
    vector<int> DgrOrder;
    ZONEOPTIONS zopt;
    DATEOPTIONS dopt;
    LITHOPTIONS lopt;
    DGROPTIONS dgo;
    FRAME Frame;
    RARESPECIES Rare;
    LINEPARAMS EndLine;
    LINEPARAMS NameBoxes;
	bool InitializeDiagram(DiagramParams& Params);
    void make_diagram(void);
    bool PlottedGraph(GRAPH *);
    bool BaseGraph(GRAPH *);
	void WriteMetafile(UnicodeString);
    void Save(void);
	void SaveAs(void);
    void InteractiveText(void);
};
//---------------------------------------------------------------------------
//extern PACKAGE TForm2 *Form2;
extern PACKAGE TTGDiagram *TGDiagram;
//---------------------------------------------------------------------------
#endif
