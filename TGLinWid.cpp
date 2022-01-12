//---------------------------------------------------------------------------
#include <vcl.h>
#include "pch.h"
#pragma hdrstop

#include "TGLinWid.h"
#ifndef TGParentH
#include "TGParent.h"
#endif
#ifndef TGUtilsH
#include "TGUtils.h"
#endif
#ifndef TGHelpH
#include "TGHelp.h"
#endif

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TLineWidthForm *LineWidthForm;
//---------------------------------------------------------------------------
__fastcall TLineWidthForm::TLineWidthForm(TComponent* Owner)
        : TForm(Owner)
{
   Diag = (TTGDiagram*)Owner;
}
//---------------------------------------------------------------------------

void __fastcall TLineWidthForm::FormCreate(TObject *Sender)
{
   DfltLineWidthComboBox = new LineWidthComboBox(LineWidthComboBox1);
   AxisLineWidthComboBox = new LineWidthComboBox(LineWidthComboBox2);
   SilhLineWidthComboBox = new LineWidthComboBox(LineWidthComboBox3);
   HistLineWidthComboBox = new LineWidthComboBox(LineWidthComboBox4);
   GridLineWidthComboBox = new LineWidthComboBox(LineWidthComboBox5);
   GrupLineWidthComboBox = new LineWidthComboBox(LineWidthComboBox6);
   DendLineWidthComboBox = new LineWidthComboBox(LineWidthComboBox7);
   ZoneLineWidthComboBox = new LineWidthComboBox(LineWidthComboBox8);
   FramLineWidthComboBox = new LineWidthComboBox(LineWidthComboBox9);
   EndlLineWidthComboBox = new LineWidthComboBox(LineWidthComboBox10);
   LiCoLineWidthComboBox = new LineWidthComboBox(LineWidthComboBox11);
   LiKyLineWidthComboBox = new LineWidthComboBox(LineWidthComboBox12);
}
//---------------------------------------------------------------------------

void __fastcall TLineWidthForm::FormDestroy(TObject *Sender)
{
   delete DfltLineWidthComboBox;
   delete AxisLineWidthComboBox;
   delete SilhLineWidthComboBox;
   delete HistLineWidthComboBox;
   delete GridLineWidthComboBox;
   delete GrupLineWidthComboBox;
   delete DendLineWidthComboBox;
   delete ZoneLineWidthComboBox;
   delete FramLineWidthComboBox;
   delete EndlLineWidthComboBox;
   delete LiCoLineWidthComboBox;
   delete LiKyLineWidthComboBox;
}
//---------------------------------------------------------------------------

void __fastcall TLineWidthForm::FormActivate(TObject *Sender)
{
   DfltLineWidthComboBox->SetLineWidth(Diag->Default.LineWidth);
   AxisLineWidthComboBox->SetLineWidth(Diag->Default.Xaxis.AxisLineWidth);
   SilhLineWidthComboBox->SetLineWidth(Diag->Default.Graph.SilhouetteLineWidth);
   HistLineWidthComboBox->SetLineWidth(Diag->Default.Graph.HistogramLineWidth);
   GridLineWidthComboBox->SetLineWidth(Diag->Default.Xaxis.GridLineWidth);
   GrupLineWidthComboBox->SetLineWidth(Diag->Default.GroupAttr.LineWidth);
   DendLineWidthComboBox->SetLineWidth(Diag->dgo.DendLineWidth);
   ZoneLineWidthComboBox->SetLineWidth(Diag->Default.ZoneAttr.LineWidth);
   FramLineWidthComboBox->SetLineWidth(Diag->Frame.LineWidth);
   EndlLineWidthComboBox->SetLineWidth(Diag->EndLine.LineWidth);
   LiCoLineWidthComboBox->SetLineWidth(Diag->lopt.ColumnLineWidth);
   LiKyLineWidthComboBox->SetLineWidth(Diag->lopt.KeyLineWidth);
}
//---------------------------------------------------------------------------
    
void __fastcall TLineWidthForm::LineWidthComboBox1Change(TObject *Sender)
{
  LineWidthComboBox2->Text = LineWidthComboBox1->Text;
  LineWidthComboBox3->Text = LineWidthComboBox1->Text;
  LineWidthComboBox4->Text = LineWidthComboBox1->Text;
  LineWidthComboBox5->Text = LineWidthComboBox1->Text;
  LineWidthComboBox6->Text = LineWidthComboBox1->Text;
  LineWidthComboBox7->Text = LineWidthComboBox1->Text;
  LineWidthComboBox8->Text = LineWidthComboBox1->Text;
  LineWidthComboBox9->Text = LineWidthComboBox1->Text;
  LineWidthComboBox10->Text = LineWidthComboBox1->Text;
  LineWidthComboBox11->Text = LineWidthComboBox1->Text;
  LineWidthComboBox12->Text = LineWidthComboBox1->Text;
}
//---------------------------------------------------------------------------

void __fastcall TLineWidthForm::HelpButtonClick(TObject *Sender)
{
   Application->HelpContext(IDH_Line_Width_Dialog_Box);
}
//---------------------------------------------------------------------------

bool __fastcall TLineWidthForm::FormHelp(WORD Command, int Data, bool &CallHelp)
{
   return true;
}
//---------------------------------------------------------------------------

  void __fastcall TLineWidthForm::Button1Click(TObject *Sender)
{
   //Ok button
   Diag->Modified = true;
   Diag->Default.LineWidth = DfltLineWidthComboBox->GetLineWidth();
   Diag->Default.Xaxis.AxisLineWidth = AxisLineWidthComboBox->GetLineWidth();
   Diag->Default.Graph.SilhouetteLineWidth = SilhLineWidthComboBox->GetLineWidth();
   Diag->Default.Graph.HistogramLineWidth = HistLineWidthComboBox->GetLineWidth();
   Diag->Default.Xaxis.GridLineWidth = GridLineWidthComboBox->GetLineWidth();
   Diag->Default.GroupAttr.LineWidth = GrupLineWidthComboBox->GetLineWidth();
   Diag->dgo.DendLineWidth = DendLineWidthComboBox->GetLineWidth();
   Diag->Default.ZoneAttr.LineWidth = ZoneLineWidthComboBox->GetLineWidth();
   Diag->Frame.LineWidth = FramLineWidthComboBox->GetLineWidth();
   Diag->EndLine.LineWidth = EndlLineWidthComboBox->GetLineWidth();
   Diag->lopt.ColumnLineWidth = LiCoLineWidthComboBox->GetLineWidth();
   Diag->lopt.KeyLineWidth = LiKyLineWidthComboBox->GetLineWidth();

   Diag->NameBoxes.LineWidth = Diag->Default.Xaxis.AxisLineWidth;
   Diag->dgo.AxisLineWidth = Diag->Default.Xaxis.AxisLineWidth;
   for (int i=0; i<Diag->grf->Count; i++) {
     GRAPH* g = (GRAPH*)Diag->grf->Items[i];
     g->graph->SilhouetteLineWidth = Diag->Default.Graph.SilhouetteLineWidth;
     g->graph->HistogramLineWidth = Diag->Default.Graph.HistogramLineWidth;
     g->xax->AxisLineWidth = Diag->Default.Xaxis.AxisLineWidth;
     g->xax->GridLineWidth = Diag->Default.Xaxis.GridLineWidth;
     }
   for (int i=0; i<Diag->YAxes->Count; i++) {
     NEWYAXIS *Yaxis = (NEWYAXIS*)Diag->YAxes->Items[i];
     Yaxis->LineWidth = Diag->Default.Xaxis.AxisLineWidth;
     }
   for (int i=0; i<Diag->Zones->Count; i++) {
     ZONE *Zone = (ZONE*)Diag->Zones->Items[i];
     Zone->LineWidth = Diag->Default.ZoneAttr.LineWidth;
     }
   for (int i=0; i<Diag->Groups->Count; i++) {
     GROUPS *Group = (GROUPS*)Diag->Groups->Items[i];
     Group->LineWidth = Diag->Default.GroupAttr.LineWidth;
     }
}
//---------------------------------------------------------------------------


