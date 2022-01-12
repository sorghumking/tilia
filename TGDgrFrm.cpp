//---------------------------------------------------------------------------

#include <vcl.h>
#include "pch.h"
#pragma hdrstop

#ifndef TIConFrmH
#include "TIConFrm.h"
#endif
#ifndef TIGlobalsH
#include "TIGlobals.h"
#endif
#ifndef TGUtilsH
#include "TGUtils.h"
#endif
#ifndef TGFntDlgH
#include "TGFntDlg.h"
#endif
#include "TGDgrFrm.h"
#include "TGHelp.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "ipwCore"
#pragma link "ipwxmlp"
#pragma link "ipworks"
#pragma link "cxButtons"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "dxSkinBlack"
#pragma link "dxSkinBlue"
#pragma link "dxSkinBlueprint"
#pragma link "dxSkinCaramel"
#pragma link "dxSkinCoffee"
#pragma link "dxSkinDarkRoom"
#pragma link "dxSkinDarkSide"
#pragma link "dxSkinDevExpressDarkStyle"
#pragma link "dxSkinDevExpressStyle"
#pragma link "dxSkinFoggy"
#pragma link "dxSkinGlassOceans"
#pragma link "dxSkinHighContrast"
#pragma link "dxSkiniMaginary"
#pragma link "dxSkinLilian"
#pragma link "dxSkinLiquidSky"
#pragma link "dxSkinLondonLiquidSky"
#pragma link "dxSkinMcSkin"
#pragma link "dxSkinMetropolis"
#pragma link "dxSkinMetropolisDark"
#pragma link "dxSkinMoneyTwins"
#pragma link "dxSkinOffice2007Black"
#pragma link "dxSkinOffice2007Blue"
#pragma link "dxSkinOffice2007Green"
#pragma link "dxSkinOffice2007Pink"
#pragma link "dxSkinOffice2007Silver"
#pragma link "dxSkinOffice2010Black"
#pragma link "dxSkinOffice2010Blue"
#pragma link "dxSkinOffice2010Silver"
#pragma link "dxSkinOffice2013DarkGray"
#pragma link "dxSkinOffice2013LightGray"
#pragma link "dxSkinOffice2013White"
#pragma link "dxSkinOffice2016Colorful"
#pragma link "dxSkinOffice2016Dark"
#pragma link "dxSkinPumpkin"
#pragma link "dxSkinsCore"
#pragma link "dxSkinsDefaultPainters"
#pragma link "dxSkinSeven"
#pragma link "dxSkinSevenClassic"
#pragma link "dxSkinSharp"
#pragma link "dxSkinSharpPlus"
#pragma link "dxSkinSilver"
#pragma link "dxSkinSpringTime"
#pragma link "dxSkinStardust"
#pragma link "dxSkinSummer2008"
#pragma link "dxSkinTheAsphaltWorld"
#pragma link "dxSkinValentine"
#pragma link "dxSkinVisualStudio2013Blue"
#pragma link "dxSkinVisualStudio2013Dark"
#pragma link "dxSkinVisualStudio2013Light"
#pragma link "dxSkinVS2010"
#pragma link "dxSkinWhiteprint"
#pragma link "dxSkinXmas2008Blue"
#pragma resource "*.dfm"
TDendrogramForm *DendrogramForm;
//---------------------------------------------------------------------------
__fastcall TDendrogramForm::TDendrogramForm(TComponent* Owner)
        : TForm(Owner)
{
   Diag = (TTGDiagram*)Owner;
}
//---------------------------------------------------------------------------

void __fastcall TDendrogramForm::FormCreate(TObject *Sender)
{
   DendLineWidthComboBox = new LineWidthComboBox(LineWidthComboBox1);
   AxisLineWidthComboBox = new LineWidthComboBox(LineWidthComboBox2);
   ipwXMLp1->Config("CodePage=65001");
}
//---------------------------------------------------------------------------

void __fastcall TDendrogramForm::FormDestroy(TObject *Sender)
{
   delete DendLineWidthComboBox;
   delete AxisLineWidthComboBox;
}
//---------------------------------------------------------------------------

void __fastcall TDendrogramForm::FormActivate(TObject *Sender)
{
   Screen->Cursor = crHourGlass;

   if (Diag && Diag->dgo.Loaded) {
     FillDialogBox();
     }
   else {
     cxButton3->Enabled = (Diag) ? true : false;
     CheckBox2->Enabled = false;
     RadioGroup1->Enabled = false;

     GroupBox2->Enabled = false;
     Edit2->Enabled = false;
     Edit2->Color = clBtnFace;
     cxButton5->Enabled = false;
	 cxButton2->Enabled = false;

     GroupBox1->Enabled = false;
	 Edit1->Enabled = false;
     Edit1->Color = clBtnFace;
     cxButton4->Enabled = false;
     cxButton1->Enabled = false;
     LabeledEdit8->Enabled = false;
	 LabeledEdit8->Color = clBtnFace;

     GroupBox7->Enabled = false;
     LabeledEdit4->Enabled = false;
     LabeledEdit4->Color = clBtnFace;
     ColorBox2->Enabled = false;
     ColorBox2->Color = clBtnFace;
     LineWidthComboBox1->Enabled = false;
     LineWidthComboBox1->Color = clBtnFace;

     GroupBox6->Enabled = false;
     ColorBox1->Enabled = false;
     ColorBox1->Color = clBtnFace;
     LineWidthComboBox2->Enabled = false;
     LineWidthComboBox2->Color = clBtnFace;

     GroupBox3->Enabled = false;
     CheckBox1->Enabled = false;
     LabeledEdit1->Enabled = false;
     LabeledEdit1->Color = clBtnFace;
     LabeledEdit2->Enabled = false;
     LabeledEdit2->Color = clBtnFace;
     LabeledEdit3->Enabled = false;
     LabeledEdit3->Color = clBtnFace;
     LabeledEdit9->Enabled = false;
     LabeledEdit9->Color = clBtnFace;
     cxButton6->Enabled = false;
     LabeledEdit5->Enabled = false;
     LabeledEdit5->Color = clBtnFace;
     LabeledEdit6->Enabled = false;
     LabeledEdit6->Color = clBtnFace;
     LabeledEdit7->Enabled = false;
     LabeledEdit7->Color = clBtnFace;
     }
   Screen->Cursor = crDefault;
}
//---------------------------------------------------------------------------

void TDendrogramForm::FillDialogBox(void)
{
   AxisLabelFont = Diag->dgo.AxisLabelFont;
   DendTitleFont = Diag->dgo.DendTitleFont;
   TicFont = Diag->dgo.TicFont;
   for (int i=0; i<4; i++)
     DendAxisLabels[i] = Diag->dgo.DendAxisLabels[i];

   CheckBox2->Checked = Diag->dgo.On;
   RadioGroup1->ItemIndex = Diag->dgo.ScaleType - 1;
   Edit1->Text = Diag->dgo.DendTitle;
   LabeledEdit8->Text = Diag->dgo.GraphNameYOffset;
   Edit2->Text = Diag->dgo.DendAxisLabels[Diag->dgo.ScaleType-1];
   LabeledEdit4->Text = Diag->dgo.DendWidth;
   Diag->SetColorBox(ColorBox2, (TColor)Diag->dgo.DendColor);
   Diag->SetColorBox(ColorBox1, (TColor)Diag->dgo.AxisColor);
   DendLineWidthComboBox->SetLineWidth(Diag->dgo.DendLineWidth);
   AxisLineWidthComboBox->SetLineWidth(Diag->dgo.AxisLineWidth);

   CheckBox1->Checked = Diag->dgo.AutoTic;
   MajorTics = Diag->dgo.MajorTics;
   MinorTics = Diag->dgo.MinorTics;
   if (Diag->dgo.AutoTic) {
     LabeledEdit1->Color = clBtnFace;
     LabeledEdit2->Color = clBtnFace;
     LabeledEdit1->Enabled = false;
     LabeledEdit2->Enabled = false; }
   else {
     LabeledEdit1->Color = clWindow;
     LabeledEdit2->Color = clWindow;
     LabeledEdit1->Enabled = true;
     LabeledEdit2->Enabled = true;
     LabeledEdit1->Text = MajorTics;
     LabeledEdit2->Text = MinorTics; }

   LabeledEdit3->Text = Diag->dgo.LabelToTicDistance;
   if (Diag->dgo.AutoTicDecPts)
     LabeledEdit9->Text = "";
   else
     LabeledEdit9->Text = Diag->dgo.TicDecPts;

   LabeledEdit5->Text = Diag->dgo.MinorTicLength;
   LabeledEdit6->Text = Diag->dgo.MajorTicLength;
   LabeledEdit7->Text = Diag->dgo.TopTicLength;
}
//---------------------------------------------------------------------------

void __fastcall TDendrogramForm::cxButton3Click(TObject *Sender)
{
   // load .dgx file
   if (Diag->dgo.Loaded) {
     if (MessageDlg("Dendrogram already loaded.\nLoad new dgx file?",
         mtConfirmation, TMsgDlgButtons() << mbYes << mbNo , 0) == mrYes)
       {
	   Diag->DgrOrder.clear();
       for (int i=0; i<Diag->Dgr->Count; i++) {
         DENDROGRAM* dg = (DENDROGRAM*)Diag->Dgr->Items[i];
         delete dg;
         Diag->Dgr->Items[i] = 0;
         }
       Diag->Dgr->Clear();
       Diag->dgo.Loaded = false;
       CheckBox2->Checked = false;
       }
     else
       return;
     }

   DGXFile = false;
   OpenDialog1->InitialDir = tiGlobals->InitialDirectory;

   if (OpenDialog1->Execute()) {
	 UnicodeString FileExt = ExtractFileExt(OpenDialog1->FileName);
	 if (FileExt.CompareIC(".dgx") != 0) {
	   UnicodeString Msg = OpenDialog1->FileName + " is not a valid CONISS dgx file.";
	   MessageDlg(Msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
       return;
	   }
	 //ipwXMLp1->Config("CodePage=0");
     ipwXMLp1->ParseFile(OpenDialog1->FileName);
     if (!DGXFile) {
	   UnicodeString Msg = OpenDialog1->FileName + " is not a valid CONISS dgx file.";
	   MessageDlg(Msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
       }
     else {
       FillDialogBox();
       Diag->dgo.Loaded = true;
       CheckBox2->Checked = true;
       CheckBox2->Enabled = true;

       RadioGroup1->Enabled = true;

       GroupBox2->Enabled = true;
       Edit2->Enabled = true;
       Edit2->Color = clWindow;
	   cxButton5->Enabled = true;
	   cxButton2->Enabled = true;

       GroupBox1->Enabled = true;
       Edit1->Enabled = true;
       Edit1->Color = clWindow;
	   cxButton4->Enabled = true;
	   cxButton1->Enabled = true;
	   LabeledEdit8->Enabled = true;
       LabeledEdit8->Color = clWindow;

       GroupBox7->Enabled = true;
       LabeledEdit4->Enabled = true;
       LabeledEdit4->Color = clWindow;
       ColorBox2->Enabled = true;
       ColorBox2->Color = clWindow;
       LineWidthComboBox1->Enabled = true;
       LineWidthComboBox1->Color = clWindow;

       GroupBox6->Enabled = true;
       ColorBox1->Enabled = true;
       ColorBox1->Color = clWindow;
       LineWidthComboBox2->Enabled = true;
       LineWidthComboBox2->Color = clWindow;

       GroupBox3->Enabled = true;
       CheckBox1->Enabled = true;
       LabeledEdit1->Enabled = true;
       LabeledEdit1->Color = clWindow;
       LabeledEdit2->Enabled = true;
       LabeledEdit2->Color = clWindow;
       LabeledEdit3->Enabled = true;
       LabeledEdit3->Color = clWindow;
       LabeledEdit9->Enabled = true;
       LabeledEdit9->Color = clWindow;
	   cxButton6->Enabled = true;
       LabeledEdit5->Enabled = true;
       LabeledEdit5->Color = clWindow;
       LabeledEdit6->Enabled = true;
       LabeledEdit6->Color = clWindow;
       LabeledEdit7->Enabled = true;
       LabeledEdit7->Color = clWindow;
       }
	 }
}
//---------------------------------------------------------------------------

void __fastcall TDendrogramForm::ipwXMLp1StartElement(TObject *Sender,
	 TipwXMLpStartElementEventParams *e)

{
   UnicodeString Element = e->Element.w_str();
   dgx.XText.SetLength(0);

   if (Element == "CONISS") {
	 DGXFile = true;
	 dgx.CONISS = true;
	 ipwXMLp1->Config("CodePage=65001");   // set to UTF-8
	 }
   else if (dgx.CONISS) {
	 if (Element == "Dendrogram")
	   dgx.Dendrogram = true;
	 else if (dgx.Dendrogram) {
	   if (Element == "Cluster") {
		 InDgr = new DENDROGRAM();
		 dgx.Cluster = true;
		 }
	   else if (dgx.Cluster)
		 InDgr->ToggleSAXElement(Element, dgx, true);
	   }
	 else if (Element == "DendrogramOrder")
	   dgx.DendrogramOrder = true;
	 else if (dgx.DendrogramOrder) {
	   if (Element == "DO")
		 dgx.DO = true;
	   }
	 }
}
//---------------------------------------------------------------------------

void __fastcall TDendrogramForm::ipwXMLp1Characters(TObject *Sender,
	 TipwXMLpCharactersEventParams *e)

{
   if (!DGXFile) return;
   UnicodeString ustr = e->Text.w_str();
   dgx.XText += ustr;
}
//---------------------------------------------------------------------------

void __fastcall TDendrogramForm::ipwXMLp1EndElement(TObject *Sender,
	 TipwXMLpEndElementEventParams *e)

{
   UnicodeString Element = e->Element.w_str();

   if (!DGXFile) return;
   if (dgx.CONISS) {
	 if (Element == "CONISS")
	   dgx.CONISS = false;
	 else if (dgx.Dendrogram) {
	   if (Element == "Dendrogram")
		 dgx.Dendrogram = false;
	   else if (dgx.Dendrogram) {
		 if (Element == "Cluster") {
		   dgx.Cluster = false;
		   Diag->Dgr->Add(InDgr);
		   }
		 else if (dgx.Cluster)  {
		   InDgr->EvaluateXML(dgx);
		   InDgr->ToggleSAXElement(Element, dgx, false);
		   }
		 }
	   }
	 else if (Element == "DendrogramOrder")
	   dgx.DendrogramOrder = false;
	 else if (dgx.DendrogramOrder) {
	   if (Element == "DO") {
		 dgx.DO = false;
		 Diag->DgrOrder.push_back(dgx.XText.ToInt());
		 }
	   }
	 }
}
//---------------------------------------------------------------------------

void __fastcall TDendrogramForm::cxButton7Click(TObject *Sender)
{
   //OK button
   if (!Diag) return;

   Diag->Modified = true;
   Diag->dgo.On = CheckBox2->Checked;

   Diag->dgo.ScaleType = RadioGroup1->ItemIndex + 1;
   for (int i=0; i<4; i++)
     Diag->dgo.DendAxisLabels[i] = DendAxisLabels[i];
   Diag->dgo.AxisLabelFont = AxisLabelFont;

   Diag->dgo.DendTitle = Edit1->Text;
   Diag->dgo.DendTitleFont = DendTitleFont;
   Diag->dgo.GraphNameYOffset = StrToFloatDef(LabeledEdit8->Text, -0.05);

   Diag->dgo.DendWidth = StrToFloatDef(LabeledEdit4->Text, 4.0);
   Diag->dgo.DendLineWidth = DendLineWidthComboBox->GetLineWidth();
   Diag->dgo.DendColor = ColorBox2->Selected;

   Diag->dgo.AxisLineWidth = AxisLineWidthComboBox->GetLineWidth();
   Diag->dgo.AxisColor = ColorBox1->Selected;

   Diag->dgo.AutoTic = CheckBox1->Checked;
   if (!Diag->dgo.AutoTic) {
     Diag->dgo.MajorTics = StrToFloatDef(LabeledEdit1->Text, 0.0);
     Diag->dgo.MinorTics = StrToFloatDef(LabeledEdit2->Text, 0.0);
     }
   if (Diag->dgo.MajorTics == 0.0 || Diag->dgo.MinorTics == 0.0)
     Diag->dgo.AutoTic = true;

   Diag->dgo.LabelToTicDistance = StrToFloatDef(LabeledEdit3->Text, 0.05);
   if (LabeledEdit9->Text.IsEmpty())
     Diag->dgo.AutoTicDecPts = true;
   else {
     Diag->dgo.TicDecPts = (short)StrToFloatDef(LabeledEdit9->Text, -1.0);
     if (Diag->dgo.TicDecPts < 0) {
       Diag->dgo.AutoTicDecPts = true;
       Diag->dgo.TicDecPts = 0;
       }
     else
       Diag->dgo.AutoTicDecPts = false;
     }
   Diag->dgo.TicFont = TicFont;

   Diag->dgo.MinorTicLength = StrToFloatDef(LabeledEdit5->Text, 0.06);
   Diag->dgo.MajorTicLength = StrToFloatDef(LabeledEdit6->Text, 0.1);
   Diag->dgo.TopTicLength = StrToFloatDef(LabeledEdit7->Text, 0.05);
}
//---------------------------------------------------------------------------

void __fastcall TDendrogramForm::cxButton1Click(TObject *Sender)
{
   TFontDialogBox* FontForm = new TFontDialogBox(this);
   FontForm->SetFont(DendTitleFont);
   if (FontForm->ShowModal() == mrOk)
	 FontForm->GetFont(DendTitleFont);
   delete FontForm;
}
//---------------------------------------------------------------------------

void __fastcall TDendrogramForm::cxButton2Click(TObject *Sender)
{
   TFontDialogBox* FontForm = new TFontDialogBox(this);
   FontForm->SetFont(AxisLabelFont);
   if (FontForm->ShowModal() == mrOk)
	 FontForm->GetFont(AxisLabelFont);
   delete FontForm;
}
//---------------------------------------------------------------------------

void __fastcall TDendrogramForm::cxButton6Click(TObject *Sender)
{
   TFontDialogBox* FontForm = new TFontDialogBox(this);
   FontForm->SetFont(TicFont);
   if (FontForm->ShowModal() == mrOk)
	 FontForm->GetFont(TicFont);
   delete FontForm;
}
//---------------------------------------------------------------------------

void __fastcall TDendrogramForm::cxButton4Click(TObject *Sender)
{
   Edit1->Text = "CONISS";
}
//---------------------------------------------------------------------------

void __fastcall TDendrogramForm::cxButton5Click(TObject *Sender)
{
   // default button
   DendAxisLabels[0] = "Increase in sum of squares";
   DendAxisLabels[1] = "Total sum of squares";
   DendAxisLabels[2] = "Within-cluster sum of squares";
   DendAxisLabels[3] = "Mean within-cluster sum of squares";
   Edit2->Text = DendAxisLabels[RadioGroup1->ItemIndex];
}
//---------------------------------------------------------------------------

void __fastcall TDendrogramForm::RadioGroup1Click(TObject *Sender)
{
   Edit2->Text = DendAxisLabels[RadioGroup1->ItemIndex];
}
//---------------------------------------------------------------------------

void __fastcall TDendrogramForm::Edit2Exit(TObject *Sender)
{
   DendAxisLabels[RadioGroup1->ItemIndex] = Edit2->Text;
}
//---------------------------------------------------------------------------

void __fastcall TDendrogramForm::CheckBox1Click(TObject *Sender)
{
   if (CheckBox1->Checked) {
     LabeledEdit1->Color = clBtnFace;
     LabeledEdit2->Color = clBtnFace;
     LabeledEdit1->Enabled = false;
     LabeledEdit2->Enabled = false;
     MajorTics = LabeledEdit1->Text;
     MinorTics = LabeledEdit2->Text;
     LabeledEdit1->Text = "";
     LabeledEdit2->Text = ""; }
   else {
     LabeledEdit1->Color = clWindow;
     LabeledEdit2->Color = clWindow;
     LabeledEdit1->Enabled = true;
     LabeledEdit2->Enabled = true;
     LabeledEdit1->Text = MajorTics;
     LabeledEdit2->Text = MinorTics; }
}
//---------------------------------------------------------------------------

void __fastcall TDendrogramForm::cxButton9Click(TObject *Sender)
{
   Application->HelpContext(IDH_Cluster_Analysis_Dialog_Box);
}
//---------------------------------------------------------------------------

bool __fastcall TDendrogramForm::FormHelp(WORD Command, int Data,
      bool &CallHelp)
{
   return true;
}
//---------------------------------------------------------------------------

