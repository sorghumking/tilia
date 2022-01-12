//---------------------------------------------------------------------------
#include <vcl.h>
#include "pch.h"
#pragma hdrstop

#ifndef TGDiagrmH
#include "TGDiagrm.h"
#endif
#include "TGPDend.h"
#ifndef TGH
#include "tg.h"
#endif
#ifndef TGYaxisH
#include "TGYaxis.h"
#endif
#ifndef TGraphicH
#include "TGraphic.h"
#endif
#ifndef TGTextH
#include "TGText.h"
#endif
#ifndef TGUtilsH
#include "TGUtils.h"
#endif

//---------------------------------------------------------------------------
#pragma package(smart_init)

void TTGDiagram::plotDendrogram(double yfac, double *end_graphs)
{
  int i;
  UnicodeString TicLabel;
  double x[4], y[4];
  double *xd, *yd, *disp;
  double ScaleFactor, xtxt, ytxt, tic, max_disp, max_x, xbase;
  MyText *Text;
  DENDROGRAM *Cluster;

  xd = new double [Levs->Count];
  yd = new double [Levs->Count];
  disp = new double [Dgr->Count];

  for (i=0; i<Dgr->Count; i++) {
    Cluster = (DENDROGRAM*)Dgr->Items[i];
    switch (dgo.ScaleType)
      {
      case 1:
        disp[i] = Cluster->inc;
	break;
      case 2:
        disp[i] = Cluster->tot;
	break;
      case 3:
        disp[i] = Cluster->wcd;
	break;
      case 4:
        disp[i] = Cluster->mwcd;
	break;
      }
    }

  xbase = *end_graphs + 0.1;

  max_disp = disp[0];
  for (i=1; i<Dgr->Count; i++)       // find maximum dispersion
    if (disp[i] > max_disp)
      max_disp = disp[i];

  if (dgo.AutoTic) {
    dgo.MajorTics = auto_step(0.0, max_disp);
    if (max_disp/dgo.MajorTics > 8.0)
      dgo.MajorTics *= 4.0;
    else
      dgo.MajorTics *= 2.0;
    dgo.MinorTics = dgo.MajorTics;
    }

  if (dgo.AutoTicDecPts) {
    if (dgo.MajorTics < 1.0) {
      dgo.TicDecPts = 1;
      while ((dgo.MajorTics*pow(10.0, (double)dgo.TicDecPts)) < 1.0) dgo.TicDecPts++;
      }
    else
     dgo.TicDecPts = 0;
    }

  max_x = 0.0;
  while (max_x < max_disp)
    max_x += dgo.MajorTics;

  ScaleFactor = dgo.DendWidth/max_x;

  NEWYAXIS *Axis1 = (NEWYAXIS*)YAxes->Items[0];
  for (i=0; i<Levs->Count; i++) {
    xd[i] = xbase;
    yd[i] = Axis1->ywc(Axis1->Depth(i));
    }

  Picture->NewSegment("Dendrogram");

  x[0] = xbase;
  y[0] = 0.2;
  x[1] = x[0] + dgo.DendWidth;
  y[1] = 0.2;
  Picture->Polyline(2, x, y, dgo.AxisColor, dgo.AxisLineWidth);

  y[0] = Axis1->Length() - 0.2;
  y[1] = y[0];
  Picture->Polyline(2, x, y, dgo.AxisColor, dgo.AxisLineWidth);

  if (Boxes) {
    x[0] -= 0.1;
    x[2] = x[1];
    y[0] = y[1] = max_ytaxa + 0.2;
    y[2] = 0.2;
    Picture->Polyline(3, x, y, NameBoxes.Color, NameBoxes.LineWidth);
    }

  tic = 0.0;
  while (tic < (max_x+0.5*dgo.MinorTics))	// draw tic marks
    {
      x[0] = xbase + ScaleFactor*tic;
      x[1] = x[0];
      y[0] = Axis1->Length() - 0.2;
      y[1] = y[0] - dgo.TopTicLength;
      Picture->Polyline(2, x, y, dgo.AxisColor, dgo.AxisLineWidth);  // top tic

      y[0] = 0.2;
      if (eventic(tic, dgo.MajorTics, dgo.MinorTics))  // major tic
	{
	  y[1] = 0.2 - dgo.MajorTicLength;
	  if (tic > 0.0) {
	    if (dgo.TicDecPts == 0)
              TicLabel = IntToStr((int)tic);
	    else
              TicLabel = FormatFloat(FloatFormat(dgo.TicDecPts), tic);
	    xtxt = x[0];
	    ytxt = 0.2 - dgo.MajorTicLength - dgo.LabelToTicDistance;
            Text = new MyText(xtxt, ytxt, dgo.TicFont, 0.0,
                          TEXT_CENTER, TEXT_CAP, TicLabel, Picture);
            Text->TextOut();
            delete Text;
	    }
	}
      else                               // minor tic
	y[1] = 0.2 - dgo.MinorTicLength;

      Picture->Polyline(2, x, y, dgo.AxisColor, dgo.AxisLineWidth);
      tic += dgo.MinorTics;
    }

  /* ytxt = 0.2 -
	 dgo.MajorTicLength -
	 4.0*dgo.LabelToTicDistance -
	 dgo.TicFont.Height;  */

  ytxt = 0.2 -
	 dgo.MajorTicLength -
	 dgo.LabelToTicDistance -
	 1.6*dgo.TicFont.Height;

  xtxt = xbase + 0.5*dgo.DendWidth;
  Text = new MyText(xtxt, ytxt, dgo.AxisLabelFont, 0.0, TEXT_CENTER, TEXT_CAP,
                    dgo.DendAxisLabels[dgo.ScaleType-1], Picture);
  Text->TextOut();
  delete Text;

  Text = new MyText(xtxt, Axis1->Length()+dgo.GraphNameYOffset, dgo.DendTitleFont, 0.0,
                    TEXT_CENTER, TEXT_BASE, dgo.DendTitle, Picture);
  Text->TextOut();
  delete Text;

  // plot dendrogram
  for (i=0; i<Dgr->Count; i++) {
    Cluster = (DENDROGRAM*)Dgr->Items[DgrOrder[i]];
    x[0] = xd[Cluster->clus1];
    x[1] = xbase + ScaleFactor*disp[i];
    x[2] = x[1];
    x[3] = xd[Cluster->clus2];
    y[0] = yd[Cluster->clus1];
    y[1] = y[0];
    y[2] = yd[Cluster->clus2];
    y[3] = y[2];
    Picture->Polyline(4, x, y, dgo.DendColor, dgo.DendLineWidth);
    xd[Cluster->clus1] = x[1];
    yd[Cluster->clus1] = (yd[Cluster->clus1] + yd[Cluster->clus2])/2.0;
    }

  x[0] = x[1];
  x[1] = xbase + dgo.DendWidth;
  y[0] = yd[Cluster->clus1];
  y[1] = y[0];
  Picture->Polyline(2, x, y, dgo.DendColor, dgo.DendLineWidth);

  Picture->CloseSegment();
  delete[] xd;
  delete[] yd;
  delete[] disp;

  (*end_graphs) += dgo.DendWidth;
}

