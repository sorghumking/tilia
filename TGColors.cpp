//---------------------------------------------------------------------------

#include <vcl.h>
#include "pch.h"
#pragma hdrstop

#ifndef TGParentH
#include "TGParent.h"
#endif
#ifndef TGDiagrmH
#include "TGDiagrm.h"
#endif
#ifndef TGYaxisH
#include "TGYaxis.h"
#endif
#ifndef TGUtilsH
#include "TGUtils.h"
#endif
#ifndef TGHelpH
#include "TGHelp.h"
#endif
#include "TGColors.h"


//---------------------------------------------------------------------------
#pragma package(smart_init)
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
TColorsForm *ColorsForm;
//---------------------------------------------------------------------------
__fastcall TColorsForm::TColorsForm(TComponent* Owner)
        : TForm(Owner)
{
   Diag = (TTGDiagram*)Owner;
}
//---------------------------------------------------------------------------

void __fastcall TColorsForm::FormActivate(TObject *Sender)
{
   Diag->SetColorBox(ColorBox1, (TColor)Diag->Picture->BackgroundColor);
   Diag->SetColorBox(ColorBox2, Diag->Default.Graph.GraphColor);
   Diag->SetColorBox(ColorBox3, Diag->Default.Graph.GraphOutlineColor);
   Diag->SetColorBox(ColorBox4, Diag->Default.Graph.ExagColor);
   Diag->SetColorBox(ColorBox5, Diag->Default.Graph.ExagOutlineColor);
   Diag->SetColorBox(ColorBox6, Diag->Default.Graph.DepthBarsColor);
   Diag->SetColorBox(ColorBox7, Diag->Default.Xaxis.Color);
   Diag->SetColorBox(ColorBox8, Diag->Default.ZoneAttr.ZoneColor);
   Diag->SetColorBox(ColorBox9, Diag->Default.GroupAttr.Color);
   Diag->SetColorBox(ColorBox10, Diag->dopt.Color);
   Diag->SetColorBox(ColorBox11, Diag->Default.Font.Color);
   Diag->SetColorBox(ColorBox12, Diag->lopt.DefaultColor);
   Diag->SetColorBox(ColorBox13, Diag->dgo.DendColor);
   color_changed = false;
   g_color_changed = false;
   go_color_changed = false;
   e_color_changed = false;
   eo_color_changed = false;
   db_color_changed = false;
   a_color_changed = false;
   t_color_changed = false;
   z_color_changed = false;
   group_color_changed = false;
   date_color_changed = false;
   lith_color_changed = false;
   dend_color_changed = false;
}
//---------------------------------------------------------------------------

// background color
void __fastcall TColorsForm::ColorBox1Change(TObject *Sender)
{
  color_changed = true;
}
//---------------------------------------------------------------------------

// ok button
void __fastcall TColorsForm::cxButton2Click(TObject *Sender)
{
   int i;
   GRAPH* g;
   NEWYAXIS *Axis;

   Diag->Modified = true;
   Diag->Picture->BackgroundColor = ColorBox1->Selected;
   Diag->BackgroundColor = ColorBox1->Selected;

   if (g_color_changed) {
     color_changed = true;
     Diag->Default.Graph.GraphColor = ColorBox2->Selected;
     for (i=0; i<Diag->grf->Count; i++) {
       g = (GRAPH*)Diag->grf->Items[i];
       g->graph->GraphColor = Diag->Default.Graph.GraphColor;
       }
     }

   if (go_color_changed) {
     color_changed = true;
     Diag->Default.Graph.GraphOutlineColor = ColorBox3->Selected;
     for (i=0; i<Diag->grf->Count; i++) {
       g = (GRAPH*)Diag->grf->Items[i];
       g->graph->GraphOutlineColor = Diag->Default.Graph.GraphOutlineColor;
       }
     }

   if (e_color_changed) {
     color_changed = true;
     Diag->Default.Graph.ExagColor = ColorBox4->Selected;
     for (i=0; i<Diag->grf->Count; i++) {
       g = (GRAPH*)Diag->grf->Items[i];
       g->graph->ExagColor = Diag->Default.Graph.ExagColor;
       }
     }

   if (eo_color_changed) {
     color_changed = true;
     Diag->Default.Graph.ExagOutlineColor = ColorBox5->Selected;
     for (i=0; i<Diag->grf->Count; i++) {
       g = (GRAPH*)Diag->grf->Items[i];
       g->graph->ExagOutlineColor = Diag->Default.Graph.ExagOutlineColor;
       }
     }

   if (db_color_changed) {
     color_changed = true;
     Diag->Default.Graph.DepthBarsColor = ColorBox6->Selected;
     for (i=0; i<Diag->grf->Count; i++) {
       g = (GRAPH*)Diag->grf->Items[i];
       g->graph->DepthBarsColor = Diag->Default.Graph.DepthBarsColor;
       }
     }

   if (a_color_changed) {
     color_changed = true;
     Diag->Default.Xaxis.Color = ColorBox7->Selected;
     for (i=0; i<Diag->grf->Count; i++) {
       g = (GRAPH*)Diag->grf->Items[i];
       g->xax->Color = Diag->Default.Xaxis.Color;
       }
     for (i=0; i<Diag->YAxes->Count; i++) {
       NEWYAXIS* Axis = (NEWYAXIS*)Diag->YAxes->Items[i];
       Axis->Color = Diag->Default.Xaxis.Color;
       }
     Diag->dgo.AxisColor = Diag->Default.Xaxis.Color;
     }

   if (z_color_changed) {
     color_changed = true;
	 Diag->Default.ZoneAttr.ZoneColor = ColorBox8->Selected;
     for (i=0; i<Diag->Zones->Count; i++) {
       ZONE* Zone = (ZONE*)Diag->Zones->Items[i];
	   Zone->ZoneColor = Diag->Default.ZoneAttr.ZoneColor;
       }
     }

   if (group_color_changed) {
     color_changed = true;
	 Diag->Default.GroupAttr.Color = ColorBox9->Selected;
     for (i=0; i<Diag->Groups->Count; i++) {
       GROUPS* Group = (GROUPS*)Diag->Groups->Items[i];
       Group->Color = (TColor)Diag->Default.GroupAttr.Color;
       }
     }

   if (date_color_changed) {
     color_changed = true;
     Diag->dopt.Color = ColorBox10->Selected;
     }

   if (lith_color_changed) {
     color_changed = true;
     Diag->lopt.DefaultColor = ColorBox12->Selected;
     for (int i=0; i<Diag->Lithology->Count; i++) {
       LITHUNIT *LithUnit = (LITHUNIT*)Diag->Lithology->Items[i];
       LithUnit->LoBoundColor = (TColor)Diag->lopt.DefaultColor;
       for (int j=0; j<LithUnit->Components->Count; j++) {
         LITHCOMPONENT *Component = (LITHCOMPONENT*)LithUnit->Components->Items[j];
         Component->Color = (TColor)Diag->lopt.DefaultColor;
         }
       }
     for (int i=0; i<Diag->LithKeys->Count; i++) {
       LITHKEY* LithKey = (LITHKEY*)Diag->LithKeys->Items[i];
       LithKey->Color = (TColor)Diag->lopt.DefaultColor;
       }
     }

   if (dend_color_changed) {
     color_changed = true;
     Diag->dgo.DendColor = ColorBox13->Selected;
     }

   if (t_color_changed) {
     color_changed = true;
     Diag->Default.Font.Color = ColorBox11->Selected;

     Diag->dopt.DateTitleFont.Color = Diag->Default.Font.Color;
     Diag->dopt.DateFont.Color = Diag->Default.Font.Color;

     Diag->lopt.LithTitleFont.Color = Diag->Default.Font.Color;
     Diag->lopt.KeyFont.Color = Diag->Default.Font.Color;

     Diag->zopt.ZoneTitleFont.Color = Diag->Default.Font.Color;
     Diag->zopt.ZoneFont.Color = Diag->Default.Font.Color;

     Diag->dgo.AxisLabelFont.Color = Diag->Default.Font.Color;
     Diag->dgo.DendTitleFont.Color = Diag->Default.Font.Color;
     Diag->dgo.TicFont.Color = Diag->Default.Font.Color;

     Diag->Default.Graph.NumberFont.Color = Diag->Default.Font.Color;

     Diag->Default.Xaxis.TicFont.Color = Diag->Default.Font.Color;
     Diag->Default.Xaxis.AxisLabelFont.Color = Diag->Default.Font.Color;
     Diag->Default.Xaxis.GraphNameFont.Color = Diag->Default.Font.Color;
     Diag->Default.Xaxis.TruncFont.Color = Diag->Default.Font.Color;

     for (int i=0; i<Diag->YAxes->Count; i++) {
       Axis = (NEWYAXIS*)Diag->YAxes->Items[i];
       Axis->TicFont.Color = Diag->Default.Font.Color;
       Axis->LabelFont.Color = Diag->Default.Font.Color;
       }

     for (int i=0; i<Diag->Groups->Count; i++) {
       GROUPS *Group = (GROUPS*)Diag->Groups->Items[i];
       Group->Font.Color = Diag->Default.Font.Color;
       }

     for (i=0; i<Diag->RandomText->Count; i++) {
       TEXTLINE *TextLine = (TEXTLINE*)Diag->RandomText->Items[i];
       TextLine->Font.Color = Diag->Default.Font.Color;
       }

     for (int i=0; i<4; i++)
       Diag->heading[i].Font.Color = Diag->Default.Font.Color;

     Diag->footer.Font.Color = Diag->Default.Font.Color;

     for (int i=0; i<Diag->grf->Count; i++) {
       g = (GRAPH*)Diag->grf->Items[i];
       g->graph->NumberFont.Color = Diag->Default.Font.Color;
       g->xax->TicFont.Color = Diag->Default.Font.Color;
       g->xax->AxisLabelFont.Color = Diag->Default.Font.Color;
       g->xax->GraphNameFont.Color = Diag->Default.Font.Color;
       g->xax->TruncFont.Color = Diag->Default.Font.Color;
       }
	 }
}
//---------------------------------------------------------------------------

// graph color
void __fastcall TColorsForm::ColorBox2Change(TObject *Sender)
{
   g_color_changed = true;
}
//---------------------------------------------------------------------------

// graph outline
void __fastcall TColorsForm::ColorBox3Change(TObject *Sender)
{
   go_color_changed = true;
}
//---------------------------------------------------------------------------

// exaggeration
void __fastcall TColorsForm::ColorBox4Change(TObject *Sender)
{
   e_color_changed = true;
}
//---------------------------------------------------------------------------

// exaggeration outline
void __fastcall TColorsForm::ColorBox5Change(TObject *Sender)
{
   eo_color_changed = true;
}
//---------------------------------------------------------------------------

// depth bars
void __fastcall TColorsForm::ColorBox6Change(TObject *Sender)
{
   db_color_changed = true;
}
//---------------------------------------------------------------------------

// X-axes
void __fastcall TColorsForm::ColorBox7Change(TObject *Sender)
{
   a_color_changed = true;
}
//---------------------------------------------------------------------------

// Zones
void __fastcall TColorsForm::ColorBox8Change(TObject *Sender)
{
   z_color_changed = true;
}
//---------------------------------------------------------------------------

// Groups
void __fastcall TColorsForm::ColorBox9Change(TObject *Sender)
{
   group_color_changed = true;
}
//---------------------------------------------------------------------------

// Dates
void __fastcall TColorsForm::ColorBox10Change(TObject *Sender)
{
   date_color_changed = true;
}
//---------------------------------------------------------------------------

// text
void __fastcall TColorsForm::ColorBox11Change(TObject *Sender)
{
   t_color_changed = true;
}
//---------------------------------------------------------------------------

// help button
void __fastcall TColorsForm::cxButton1Click(TObject *Sender)
{
   Application->HelpContext(IDH_Colors_Dialog_Box);
}
//---------------------------------------------------------------------------

bool __fastcall TColorsForm::FormHelp(WORD Command, int Data, bool &CallHelp)
{
   return true;
}
//---------------------------------------------------------------------------

void __fastcall TColorsForm::ColorBox12Change(TObject *Sender)
{
   lith_color_changed = true;
}
//---------------------------------------------------------------------------

void __fastcall TColorsForm::ColorBox13Change(TObject *Sender)
{
   dend_color_changed = true;
}
//---------------------------------------------------------------------------

