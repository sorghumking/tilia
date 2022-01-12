//---------------------------------------------------------------------------
#include <vcl.h>
#include "pch.h"
#pragma hdrstop

#include <algorithm>
#include <vector>
#include <SysUtils.hpp>

#ifndef TGDiagrmH
#include "TGDiagrm.h"
#endif
#include "TGGraph.h"
#ifndef TGH
#include "tg.h"
#endif
#ifndef TGYaxisH
#include "TGYaxis.h"
#endif
#ifndef TGUtilsH
#include "TGUtils.h"
#endif
#ifndef TGraphicH
#include "TGraphic.h"
#endif
#ifndef TGTextH
#include "TGText.h"
#endif
#ifndef TGMarkerH
#include "TGMarker.h"
#endif

//---------------------------------------------------------------------------
#pragma package(smart_init)

void TTGDiagram::make_diagram(void)
{
  int i, j;
  double yfac;
  UnicodeString buffer;

  Picture->Reset();

  thicks = false;
  for (i=0; i<grf->Count; i++) {
    GRAPH* g = (GRAPH*)grf->Items[i];
    if (g->code.SubString(1, 5) == "Thick") { // Thickness var exists
      thick = new double[Levs->Count];
      for (j=0; j<Levs->Count; j++)		      // read data
        thick[j] = ((GRAPH*)grf->Items[i])->data[j].x;
      thicks = true;
      break;
      }
    }

  end_graphs = 0.0;
  max_ytaxa = 0.0;

  if (!plot_yaxes()) return;

  NEWYAXIS *Axis1 = (NEWYAXIS*)YAxes->Items[0];
  yfac = Axis1->yfac;

  if (Dates->Count > 0 && dopt.DatesPosition == LEFT)
    plot_dates(yfac);

  if (!plot_graphs(yfac)) return;

  if (ZoneLabels->Count > 0)
    plot_zone_labels(yfac);

  if (Zones->Count > 0)     // plot high priority zones
    plot_zones(yfac);

  if (Groups->Count > 0)
    plot_groups();	   // plot groups

  plot_heading();	   // plot diagram heading
  plot_footer();	   // plot diagram footer

  if (dgo.On)
    plotDendrogram(yfac, &end_graphs);

  if (Dates->Count > 0 && dopt.DatesPosition == RIGHT)
    plot_dates(yfac);

  if (RandomText->Count > 0) plot_atext();

  if (lopt.On) plot_lith(yfac);		 // lithology column

  if (lopt.On && lopt.KeyOn) plot_lith_boxes();

  if (Frame.Plot) plot_frame();

  // white space
  Picture->ExtentX(Picture->MinExtentX()-Frame.Left);
  Picture->ExtentX(Picture->MaxExtentX()+Frame.Right);
  Picture->ExtentY(Picture->MaxExtentY()+Frame.Top);
  Picture->ExtentY(Picture->MinExtentY()-Frame.Bottom);

  if (thick != NULL) { delete[] thick; thick = NULL; }


}
//---------------------------------------------------------------------------

bool TTGDiagram::PlottedGraph(GRAPH* g)
{
   if (g->status == SKIP) return false;
   if (g->status == NOGRAPH) return false;
   if (g->code.SubString(1, 1) == "#") return false;
   UnicodeString TempStr = g->code.SubString(1, 5);
   if (TempStr == "Chron") return false;
   if (TempStr == "Depth") return false;
   if (TempStr == "Thick") return false;
   if (TempStr == "Error") return false;
   return true;
}
//---------------------------------------------------------------------------

bool TTGDiagram::BaseGraph(GRAPH* g)
{
   UnicodeString TempStr;
   if (g->status != NORMAL && g->status != BASE) return false;
   TempStr = g->code.SubString(1, 5);
   if (TempStr == "Chron") return false;
   if (TempStr == "Depth") return false;
   if (TempStr == "Thick") return false;
   if (TempStr == "Error") return false;
   return true;
}
//---------------------------------------------------------------------------

// plots the diagram
bool TTGDiagram::plot_graphs(double yfac)
{
  int j, k, nv, nvo, npnts, nlevs, nover;
  double max_x, min_x, min_xax, max_xax, width_grf, ScaleFactor, width_rare;
  double DistanceToNextGraph, width_data, trunc_grf;
  //double *xc, *xo, *xe;
  vector<double> xthick;
  vector<double> xc;
  vector<double> xe;
  vector<double> xo;
  vector<double> yc;
  vector<double> ye;
  vector<double> yo;
  vector<double>::iterator itr;
  //int *xn;
  vector<int> xn;
  vector<bool> xz;
  //double y[5];
  //double x[5];
  vector<double> x(5,0.0);
  vector<double> y(5,0.0);
  double half_bar;
  bool base, overlay, stacked, lover;

  bool Truncate;
  bool errorbar;
  bool logcurv;
  UnicodeString SegmentName;
  GRAPH* g;

  NEWYAXIS *Axis1 = (NEWYAXIS*)YAxes->Items[0];

  bool plotrare = false;
  int maxrare=0;

  ngraphs = 0;

  xc.assign(Levs->Count+3, 0.0);
  yc.assign(Levs->Count+3, 0.0);
  xe.assign(3*Levs->Count+1, 0.0);
  ye.assign(3*Levs->Count+1, 0.0);
  xo.assign(2*Levs->Count+2, 0.0);
  yo.assign(2*Levs->Count+2, 0.0);
  xz.assign(Levs->Count+1, true);
  xn.assign(Levs->Count+1, 0);

  if (thicks)
	xthick.assign(Levs->Count, 0.0);

  ScaleFactor = 1.0;
  min_xax = 0.0;
  max_xax = 0.0;

  for (nv=0; nv<grf->Count; nv++) {
	plotrare = false;
	maxrare = 0;
	for (j=1; j<=Levs->Count; j++)
	  xn[j] = 0;

	GRAPH *Vnv = (GRAPH*)grf->Items[nv];
	if (! PlottedGraph(Vnv)) continue;

	logcurv = (Vnv->code == "salinity") ? true : false;

	base    = ((Vnv->status == BASE) ? true : false);
	overlay = ((Vnv->status == OVERLAY) ? true : false);
	stacked = ((Vnv->status == STACKED) ? true : false);
	lover   = ((overlay || stacked) ? true : false);

	errorbar = false;
	if (nv < grf->Count-1) {
	  GRAPH *Vnv1 = (GRAPH*)grf->Items[nv+1];
	  if (Vnv1->status == ERRORBAR) {
		base = true;
		errorbar = true;
		}
	  }

	if (! lover) {                    // first graph cannot be lover
	  SegmentName = "Graph: ";
	  SegmentName += Vnv->code;
	  Picture->NewSegment(SegmentName, end_graphs, 0.0);
	  nover = 0;
	  baseline_plotted = false;
	  }
	else
	  nover++;

	npnts = 1;
	nlevs = 0;

	g = (GRAPH*)grf->Items[nv];

	for (j=1; j<=Levs->Count; j++) {		    // read data
	  if (!Axis1->DataAutoMin && Axis1->Depth(j-1) < Axis1->DataMin) continue;
	  if (!Axis1->DataAutoMax && Axis1->Depth(j-1) > Axis1->DataMax) continue;

	  if (! g->data[j-1].null) {
		if (logcurv) {
		  if (g->data[j-1].x <= 0.0) {
			UnicodeString Msg = "Graph " + Vnv->name + " has zero or negative values. Cannot plot on log scale.";
			MessageDlg(Msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			return false;
			}
		  xc[npnts] = log10(g->data[j-1].x);
		  }
		else
		  xc[npnts] = g->data[j-1].x;

		if (g->data[j-1].rare) {
		  xn[npnts] = nint(xc[npnts]);
		  if (xn[npnts] == 0) xn[npnts] = 1;
		  if (xn[npnts] > maxrare) maxrare = xn[npnts];
		  xc[npnts] = 0.0;
		  plotrare = true;
		  }

		NEWYAXIS *Axis1 = (NEWYAXIS*)YAxes->Items[0];
		yc[npnts++] = Axis1->ywc(Axis1->Depth(j-1));
		if (thicks) xthick[nlevs] = thick[j-1];
		nlevs++;
		}
	  }
	npnts += 2;

	if (g->graph->GraphType == PRESENCE) {
	  for (j=1; j<=nlevs; j++)
		if (xc[j] > 0.0) xc[j] = g->graph->XPresence;
	  }

	if (g->graph->GraphType != NUMBERS && g->graph->GraphType != PRESENCE) {
	  if (! lover) { 	    // zero minumum x values
		for (j=1; j<=nlevs; j++)
		  xz[j] = (xc[j] > 0.0);
		  //xz[j] = ((xc[j] > 0.0) ? true : false);
		}
	  else {
		for (j=1; j<=nlevs; j++)
		  xz[j] = (xz[j] || xc[j] > 0.0);
		  //xz[j] = ((xz[j] || xc[j] > 0.0) ? true : false);
		}
	  }

	if (!lover && g->graph->GraphType != NUMBERS) { //G
	  if (g->graph->GraphType != PRESENCE) { //F
		//if (base && (g->xax->AutoMin || g->xax->AutoMax)) [ // get data for axis limits
		if (base) {             // get data for axis limits
		  nvo = nv+1;		  // use xe for temporary storage
		  for (j=1; j<=nlevs; j++)
			xe[j] = xc[j];
		  GRAPH *Vnvo = (GRAPH*)grf->Items[nvo];
		  while (nvo < grf->Count && (Vnvo->status == OVERLAY
				 || Vnvo->status == STACKED
				 || Vnvo->status == ERRORBAR
				 || Vnvo->status == SKIP))
			{ //D
			  if (Vnvo->status != SKIP) { //C
				k = 1;
				for (j=1; j<Levs->Count; j++) { //B
				  GRAPH* g1 = (GRAPH*)grf->Items[nvo];
				  if (!g1->data[j].null) {  //A
					if (Vnvo->status == OVERLAY)
					  xe[k] = max(xe[k], (double)g1->data[j-1].x);
					else	   // stacked or errorbar
					  xe[k] += g1->data[j-1].x;
					if (errorbar)
					  xo[k] = g1->data[j-1].x;
					k++;
					} //A
				  } //B
				} //C
			  nvo++;
			  if (nvo < grf->Count)
				Vnvo = (GRAPH*)grf->Items[nvo];
			} //D
		  }

		// calculate length of x-axis
		// max_xax is in graph coordinates, e.g. percent

		if (base)
		  min_x = mindouble(&xe[1], nlevs);
		else {
		  min_x = mindouble(&xc[1], nlevs);
		  //vector<double>::iterator itr = min_element(xc.begin()+1,
		  //  xc.begin()+nlevs, less<double>());
		  //min_x = *itr;
		  }

		if (base)
		  max_x = maxdouble(&xe[1], nlevs);
		else {
		  max_x = maxdouble(&xc[1], nlevs);
		  //vector<double>::iterator itr = max_element(xc.begin()+1,
		  //  xc.begin()+nlevs, less<double>());
		  //max_x = *itr;
		  }

		if (max_x > 100.0000 && max_x <= 100.00001) max_x = 100.0;

		width_data = max_x;
		Truncate = FALSE;
		if (!g->xax->AutoMax) {
		  if (g->xax->XaxisMax < max_x && g->xax->Truncate) {
			width_data = g->xax->XaxisMax;
			Truncate = TRUE;
			}
		  max_x = g->xax->XaxisMax;
		  }

		// calculate tic marks
		if (g->xax->AutoTic && ! logcurv) { //J
		  if (max_x <= 100.0) {
			g->xax->MinorTics = 5.0;
			g->xax->MajorTics = 10.0;
			g->xax->LabeledTics = 20.0;
			}
		  else {
			g->xax->MajorTics = pow(10.0, floor(log10(max_x)));
			if ( max_x/g->xax->MajorTics > 5.0)
			  g->xax->MajorTics *= 2.0;
			else if ( max_x/g->xax->MajorTics <= 2.0)
			  g->xax->MajorTics /= 2.0;
			g->xax->MinorTics = 0.5*g->xax->MajorTics;
			g->xax->LabeledTics = g->xax->MajorTics;
			if (max_x >= 10000)
			while (g->xax->MajorTics*g->xax->TicLabelDivideBy >= 1000.0)
			  g->xax->TicLabelDivideBy *= 0.1;
			}
		  } //J

		if (logcurv) { //K
		  if (g->xax->AutoMin || log10(g->xax->XaxisMin) > min_x)
			min_xax = 0.0;
		  else
			min_xax = log10(g->xax->XaxisMin);
		  } //K
		else { //L
		  if (g->xax->AutoMin || g->xax->XaxisMin > min_x) { //N
			if (min_x >= 0.0)
			  min_xax = 0.0;
			else { //M
			  min_xax = 0.0;
			  while (min_xax > min_x) min_xax -= g->xax->MajorTics;
			  } //M
			} //N
		  else
			min_xax = g->xax->XaxisMin;
		  } //L
		width_data -= min_xax;  // width_data = max data value - min x-axis value

		// calculate max_xax: in graph units
		if (logcurv) { //O
		  max_xax = 1.0;
		  while (log10(max_xax) < max_x)
			max_xax *= 10.0;
		  max_xax = log10(max_xax);
		  } //O
		else { //P
		  max_xax = min_xax;
		  while (max_xax < max_x)
			max_xax += g->xax->MajorTics;
		  if (max_xax == 0)
			max_xax = g->xax->MajorTics;
		  } //P
		} //F
	  else {    // GraphType == PRESENCE
		min_xax = 0.0;
		max_xax = g->xax->MajorTics;
		width_data = g->graph->XPresence;
		max_x = g->graph->XPresence;
		}

	  if (g->xax->GraphWidth > 0.0)	// user defined
		g->xax->ScaleFactor = fabs(g->xax->GraphWidth/max_xax);
	  else if (g->xax->AutoScaleFactor)
		g->xax->ScaleFactor = (max_x <= 100.0) ? 0.04 : 3.0/fabs(max_xax-min_xax);
	  ScaleFactor = g->xax->ScaleFactor;
	  DistanceToNextGraph = g->xax->DistanceToNextGraph;
	  width_grf = g->xax->ScaleFactor*fabs(max_xax-min_xax)+DistanceToNextGraph;    // calc width of graph in wc
	  if (plotrare) {
		width_rare = 1.5*Rare.Size*maxrare + 0.075;
		if (width_rare > width_grf) {
		  width_grf -= DistanceToNextGraph;
		  DistanceToNextGraph = width_rare-width_grf;
		  width_grf += DistanceToNextGraph;
		  }
		}

	  plot_Xaxes(nv, logcurv, max_xax, min_xax, DistanceToNextGraph, width_grf);
	  plot_grid(nv, max_xax);
	  } //G
	else
	  g->xax->ScaleFactor = ScaleFactor;
	
	// convert x-values to world coordinates
	if (g->graph->GraphType != NUMBERS) {
	  for (j=1; j<=nlevs; j++)
		xc[j] *= g->xax->ScaleFactor;

	  if ((min_xax > 0 && (base || overlay)) || min_xax < 0) {
		double dx = g->xax->ScaleFactor*min_xax;
		for (j=1; j<=nlevs; j++)
		  xc[j] -= dx;
		}

	  if (stacked) {
		for (j=nlevs+1, k=nlevs; j<=2*nlevs; j++, k--)
		  xo[j] = xc[k]+xo[k];
		xo[0] = xo[2*nlevs];
		xo[1+2*nlevs] = xo[1];
		}
	  }

	// convert y-values to world coordinates

	if (base) {
	  for (j=1, k=2*nlevs; j<=nlevs; j++, k--)
		yo[j] = yo[k] = yc[j];
	  yo[0] = yo[2*nlevs];
	  yo[1+2*nlevs] = yo[1];
	  }

	if (! stacked && g->graph->GraphType != NUMBERS) { // beginning and ending points
	  xc[0] = 0.0;
	  yc[0] = yc[1];
	  xc[nlevs+1] = 0.0;
	  yc[nlevs+1] = yc[nlevs];
	  xc[nlevs+2] = 0.0;
	  yc[nlevs+2] = yc[0];
	  }

	switch (g->graph->GraphType) {
	  case SILHOUETTE:
		if (Truncate) {
		  trunc_grf = (g->xax->TruncateWhere == END_OF_AXIS) ?
					  width_grf-DistanceToNextGraph : width_grf;
		  exag_graph(nv, TRUNCATE, xc, yc, xe, ye, 1.0, max_xax, trunc_grf, nlevs);
		  }
		else {
		  if (!stacked) {  // A
			switch (g->graph->SilhouetteFill) {
			  case HOLLOW_FILL:	// hollow
				Picture->Polygon(npnts, xc, yc, g->graph->SilhouetteLineWidth,
						 g->graph->GraphOutlineColor, 0, HOLLOW_FILL);
				break;
			  case SOLID_FILL:	// solid
				Picture->Polygon(npnts, xc, yc, g->graph->SilhouetteLineWidth,
						 g->graph->GraphOutlineColor, g->graph->GraphColor, SOLID_FILL);
				break;
			  case PATTERN_FILL:	// pattern
				Picture->Polygon(npnts, xc, yc, g->graph->SilhouetteLineWidth,
						 g->graph->GraphOutlineColor, g->graph->GraphColor, PATTERN_FILL,
						 g->graph->SilhouettePattern);
				break;
			  case BAR_FILL:	// hollow, bars
				x[0] = 0.0;
				for (j=1; j<=nlevs; j++) {	// draw bars
				  x[1] = xc[j];
				  y[0] = yc[j];
				  y[1] = yc[j];
				  Picture->Polyline(2, x.begin(), y.begin(), g->graph->GraphColor, g->graph->SilhouetteLineWidth);
				  }
				Picture->Polyline(npnts, xc.begin(), yc.begin(), g->graph->GraphOutlineColor, g->graph->SilhouetteLineWidth);
				break;
				}
			if (errorbar) {
			  for (j=1; j<=nlevs; j++) {	// draw bars
				if (xo[j] > 0.0) {
				  x[0] = xc[j] - g->xax->ScaleFactor * xo[j];
				  x[1] = xc[j] + g->xax->ScaleFactor * xo[j];
				  y[0] = yc[j];
				  y[1] = yc[j];
				  Picture->Polyline(2, x.begin(), y.begin(), g->graph->GraphColor, g->graph->SilhouetteLineWidth);
				  }
				 }
			  }
			}  // A
			else {   // stacked 	// n_levs changed starting here
			  switch (g->graph->SilhouetteFill) {
				case HOLLOW_FILL:	// hollow
				  Picture->Polygon(2*nlevs+1, xo, yo, g->graph->SilhouetteLineWidth,
						   g->graph->GraphOutlineColor, 0, HOLLOW_FILL);
				  break;
				case SOLID_FILL:	// solid
				  Picture->Polygon(2*nlevs+1, xo, yo, g->graph->SilhouetteLineWidth,
						   g->graph->GraphOutlineColor, g->graph->GraphColor, SOLID_FILL);
				  break;
				case PATTERN_FILL:	// pattern
				  Picture->Polygon(2*nlevs+1, xo, yo, g->graph->SilhouetteLineWidth,
						   g->graph->GraphOutlineColor, g->graph->GraphColor, PATTERN_FILL,
						   g->graph->SilhouettePattern);
				  break;
				case BAR_FILL:	// hollow, bars
				  for (j=1, k=2*nlevs; j<=nlevs; j++, k--) { // draw bars
					x[0] = xo[j];
					x[1] = xo[k];
					y[0] = yo[j];
					y[1] = yo[k];
					Picture->Polyline(2, x.begin(), y.begin(), g->graph->GraphColor,
							 g->graph->SilhouetteLineWidth);
					}
				  //Picture->Polyline(nlevs+2, &xo[nlevs], &yo[nlevs],
				  //		 g->graph->GraphOutlineColor, g->graph->SilhouetteLineWidth);
				  Picture->Polyline(nlevs+2, xo.begin()+nlevs, yo.begin()+nlevs,
						   g->graph->GraphOutlineColor, g->graph->SilhouetteLineWidth);
				  break;
				}
			  }     // n_levs change end here

		  if (! lover && g->graph->DepthBars) {
			x[1] = width_grf;
			for (j=1; j<=nlevs; j++) {	// draw bars
			  if (g->graph->Exag) {
				if ((x[0] = g->graph->Exag * xc[j]) > width_grf)
				  continue;
				}
			  else
				x[0] = xc[j];
			  y[0] = yc[j];
			  y[1] = yc[j];
			  Picture->Polyline(2, x.begin(), y.begin(), g->graph->DepthBarsColor,
					   g->graph->SilhouetteLineWidth);
			  }
			}
		  }

		if (!base && !lover && g->graph->Exag > 0) {	 // plot exaggerated curve
		  trunc_grf = (!Truncate || g->xax->TruncateWhere == END_OF_GRAPH) ?
					  width_grf : width_grf-DistanceToNextGraph;
		  exag_graph(nv, EXAGGERATE, xc, yc, xe, ye,
		  g->graph->Exag, max_xax, trunc_grf, nlevs);
		  }

		if (Vnv->status == NORMAL || nv == grf->Count-1 || last_overlay(nv)) {
		  plot_baseline(nv, xz, yc, g->graph->GraphOutlineColor, nlevs, min_xax);
		  baseline_plotted = true;
		  }

		//if (Truncate && g->xax->trunc_val != 0)
		if (Truncate && g->xax->PrintTruncatedValues) {
		  trunc_grf = (g->xax->TruncateWhere == END_OF_AXIS) ?
					  width_grf-DistanceToNextGraph : width_grf;
		  truncated_numbers(nv, xc, yc, trunc_grf, nlevs);
		  }

		//if (rare.species && plotrare)
		if (plotrare)
		  plot_rare_species(xn, yc, nlevs, g->graph->GraphColor);
		break;
	  case HISTOGRAM:
		if (g->graph->BarWidth <= 0.0) {
		  if (! stacked) {
			x[0] = 0.0;
			if (Truncate)
			  trunc_grf = (g->xax->TruncateWhere == END_OF_AXIS) ? width_grf-DistanceToNextGraph : width_grf;
			for (j=1; j<=nlevs; j++) {
			  if (xc[j] > x[0]) {
				x[1] = (Truncate) ? min(trunc_grf, xc[j]) : xc[j];
				y[0] = yc[j];
				y[1] = yc[j];
				Picture->Polyline(2, x.begin(), y.begin(), g->graph->GraphColor,
						 g->graph->HistogramLineWidth);
				}
			  }
			if (Truncate && g->xax->PrintTruncatedValues)
			truncated_numbers(nv, xc, yc, trunc_grf, nlevs);
			}
		  else { // stacked
			for (j=1, k=2*nlevs; j<=nlevs; j++, k--) {
			  if (xo[k] > xo[j]) {
				x[0] = xo[j];
				x[1] = xo[k];
				y[0] = yo[j];
				y[1] = yo[k];
				Picture->Polyline(2, x.begin(), y.begin(), g->graph->GraphColor,
						 g->graph->HistogramLineWidth);
				}
			  }
			}
		  }
		else {
		  half_bar = 0.5 * g->graph->BarWidth;
		  if (Truncate)
			trunc_grf = (g->xax->TruncateWhere == END_OF_AXIS) ? width_grf-DistanceToNextGraph : width_grf;
		  for (j=1, k=2*nlevs; j<=nlevs; j++, k--) {
			if (thicks && g->graph->UseThickVar)
			  half_bar = 0.5*yfac*xthick[j-1];
			if (stacked)
			  box(x, y, xo[j], yo[j]-half_bar, xo[k], yo[j]+half_bar);
			else {
			  x[1] = (Truncate) ? min(trunc_grf, xc[j]) : xc[j];
			  box(x, y, 0.0, yc[j]-half_bar, x[1], yc[j]+half_bar);
			  }
			if (x[1] > x[0]) {
			  switch (g->graph->BarFill) {
				case HOLLOW_FILL:    // hollow
				  Picture->Polygon(5, x, y, g->graph->SilhouetteLineWidth,
						   g->graph->GraphColor, 0, HOLLOW_FILL);
				  break;
				case SOLID_FILL:     // solid
				  Picture->Polygon(5, x, y, g->graph->SilhouetteLineWidth,
						   g->graph->GraphColor, g->graph->GraphColor, SOLID_FILL);    // fill bar
				  break;
				case PATTERN_FILL:   // pattern
				  Picture->Polygon(5, x, y, g->graph->SilhouetteLineWidth,
						   g->graph->GraphColor, g->graph->GraphColor, PATTERN_FILL,
						   g->graph->BarPattern);    // fill bar
				  break;
				}
			  }
			}
		  if (! stacked && Truncate && g->xax->PrintTruncatedValues)
			truncated_numbers(nv, xc, yc, trunc_grf, nlevs);
		  }

		//if (rare.species && plotrare)
		if (plotrare)
		  plot_rare_species(xn, yc, nlevs, g->graph->GraphColor);

		if (! baseline_plotted) {
		  if (g->graph->VerticalAxis) {
			plot_baseline(nv, xz, yc, g->xax->Color, nlevs, min_xax);
			baseline_plotted = true;
			}
		  else {
			x[0] = x[1] = 0.0;
			y[0] = (g->xax->LabelOriginTic) ? 0.2 - g->xax->MajorTicLength : 0.0;
			y[1] = 0.2;	          // base line from origin
			Picture->Polyline(2, x.begin(), y.begin(), g->xax->Color, g->xax->AxisLineWidth);
			if (g->xax->LabelOriginTic)
			  label_tic(nv, 0.0, min_xax);
			y[0] = (Axis1->Length() - 0.2 - g->xax->TopTicLength);
			y[1] = Axis1->Length();	  // base line from top
			Picture->Polyline(2, x.begin(), y.begin(), g->xax->Color, g->xax->AxisLineWidth);
			}
		  }
		break;
	  case LINEGRAPH:
		line_graph(nv, xc, yc, xe, ye, xo, yo, xz, min_xax, max_xax, width_grf,
		  DistanceToNextGraph, nover, stacked, Truncate, nlevs);
		if (errorbar) {
		  for (j=1; j<=nlevs; j++) {	// draw bars
			x[0] = xc[j] - g->xax->ScaleFactor * xo[j];
			x[1] = xc[j] + g->xax->ScaleFactor * xo[j];
			y[0] = yc[j];
			y[1] = yc[j];
			Picture->Polyline(2, x.begin(), y.begin(), g->graph->GraphColor, g->graph->LineGraphLineWidth);
			}
		  }
		break;
	  case NUMBERS:
		numbers_graph(nv, xc, xn, yc, &width_grf, nlevs);
		min_xax = 0.0;
		max_xax = width_grf/ScaleFactor;
		break;
	  case PRESENCE:
		presence_graph(nv, xc, yc, xz, nover, min_xax, max_xax, nlevs);
		break;
		}

	  //Beep();
	  if (base) {
		//double dx = g->xax->ScaleFactor*min_xax;
		for (j=1; j<=nlevs; j++) {
		  xo[j] = xc[j];
		  //if (dx != 0.0)
		  //  xo[j] -= dx;
		  }
		}
	  else if (stacked) {
		for (j=1, k=2*nlevs; j<=nlevs; j++, k--)
		  xo[j] = xo[k];
		}

	  // graph label

	  if (g->graph->GraphType != PRESENCE && g->graph->GraphType != LINEGRAPH &&
		  Vnv->name.SubString(1, 1) != "{" && !Vnv->name.IsEmpty())
			  graphName(nv, Vnv->name, min_xax, max_xax);

	  if (Vnv->status == NORMAL
		  || nv == grf->Count - 1
		  || last_overlay(nv)
		  || g->graph->GraphType == NUMBERS)
	  {
		Picture->CloseSegment();
		//close_segment(ngraphs, stran_in);
		end_graphs += width_grf;
		//grf_lim[ngraphs-1].xmax = end_graphs;
	  }
	}

  endLine();		   // draw diagram end line

  if (Boxes) nameBoxes();
  return(true);
}
//---------------------------------------------------------------------------

// plots symbols for rare species designated by negative numbers
void TTGDiagram::plot_rare_species(vector<int>& xn, vector<double>& yc, int nlevs, int color)
{
  int j, k;
  double xb, x[2], y[2];

  for (j=1; j<=nlevs; j++) {
	if (xn[j] > 0) {
	  xb = 0.075;
	  for (k=0; k<xn[j]; k++) {
		switch (Rare.Symbol) {
		  case RAREPLUS:
			x[0] = xb;
			x[1] = xb+Rare.Size;
			y[0] = y[1] = yc[j];
			Picture->Polyline(2, x, y, color, Rare.LineWidth);
			x[0] = x[1] = xb + 0.5*Rare.Size;
			y[0] = yc[j] + 0.5*Rare.Size;
			y[1] = y[0] - Rare.Size;
			Picture->Polyline(2, x, y, color, Rare.LineWidth);
			break;
		  case RARECIRCLE:
			double dx = Rare.Size/2.0;
			//DblRect *rect = new DblRect(xb, xb+2*dx, yc[j]-dx, yc[j]+dx);
			DblRect rect(xb, xb+2*dx, yc[j]-dx, yc[j]+dx);
			Picture->Ellipse(rect, color, SOLID_FILL);
			//delete rect;
			break;
		  }
		xb += (1.5*Rare.Size);
		}
	  }
	}
}
//---------------------------------------------------------------------------

void TTGDiagram::line_graph(int nv, vector<double>& xc, vector<double>& yc, vector<double>& xe, vector<double>& ye,
		vector<double>& xo, vector<double>& yo, vector<bool>& xz, double min_xax,
		double max_xax, double width_grf, double DistanceToNextGraph,
		int nover, bool stacked, bool Truncate, int nlevs)
{
  GRAPH* g = (GRAPH*)grf->Items[nv];

  if (Truncate) {
    exag_graph(nv, TRUNCATE, xc, yc, xe, ye, 1.0, max_xax, width_grf-DistanceToNextGraph, nlevs);
    if (g->xax->PrintTruncatedValues)
      truncated_numbers(nv, xc, yc, ((g->xax->TruncateWhere == END_OF_AXIS) ? width_grf-DistanceToNextGraph : width_grf), nlevs);
    }
  else {
    if (! stacked) {
      Picture->Polyline(nlevs, &xc[1], &yc[1], g->graph->GraphColor, g->graph->LineGraphLineWidth);
      if (g->graph->MarkerType > 0)
        Markers(g, nlevs, g->graph->MarkerLineWidth, &xc[1], &yc[1]);
      }
    else {
      Picture->Polyline(nlevs, &xo[nlevs+1], &yo[nlevs+1], g->graph->GraphColor, g->graph->LineGraphLineWidth);
      if (g->graph->MarkerType > 0)
        Markers(g, nlevs, g->graph->MarkerLineWidth, &xo[nlevs+1], &yo[nlevs+1]);
      }
    }

 if (g->status == NORMAL || nv == grf->Count-1 || last_overlay(nv)) {
   plot_baseline(nv, xz, yc, g->xax->Color, nlevs, min_xax);
   baseline_plotted = true;
   }

 if (g->graph->SymbolName)
   symbol_name(nv, nover, g->graph->GraphColor, min_xax, max_xax);

 if (g->xax->PlotGraphName)
   graphName(nv, g->name, min_xax, max_xax);
}
//---------------------------------------------------------------------------

void TTGDiagram::Markers(GRAPH *g, int nlevs, double LineWidth, double xc[], double yc[])
{
  Marker1 *Mrk1;
  Marker2 *Mrk2;
  Marker3 *Mrk3;
  Marker4 *Mrk4;
  Marker5 *Mrk5;
  Marker6 *Mrk6;
  Marker7 *Mrk7;
  Marker8 *Mrk8;
  Marker9 *Mrk9;
  Marker10 *Mrk10;
  Marker11 *Mrk11;
  Marker12 *Mrk12;
  Marker13 *Mrk13;
  Marker14 *Mrk14;
  Marker15 *Mrk15;
  Marker16 *Mrk16;
  Marker17 *Mrk17;
  Marker18 *Mrk18;
  Marker19 *Mrk19;
  Marker20 *Mrk20;
  Marker21 *Mrk21;
  Marker22 *Mrk22;
  Marker23 *Mrk23;
  Marker24 *Mrk24;
  Marker25 *Mrk25;
  Marker26 *Mrk26;
  Marker27 *Mrk27;
  Marker28 *Mrk28;
  Marker29 *Mrk29;
  Marker30 *Mrk30;
  Marker31 *Mrk31;
  Marker32 *Mrk32;

  switch (g->graph->MarkerType)
    {
    case 1:
	  Mrk1 = new Marker1(g->graph->MarkerSize, g->graph->ZeroSymbol,
              g->graph->GraphColor, nlevs, LineWidth, xc, yc, Picture);
      Mrk1->PlotMarkers();
      delete Mrk1;
      break;
    case 2:
      Mrk2 = new Marker2(g->graph->MarkerSize, g->graph->ZeroSymbol,
                 g->graph->GraphColor, nlevs, LineWidth, xc, yc, Picture);
      Mrk2->PlotMarkers();
      delete Mrk2;
      break;
    case 3:
      Mrk3 = new Marker3(g->graph->MarkerSize, g->graph->ZeroSymbol,
                 g->graph->GraphColor, nlevs, LineWidth, xc, yc, Picture);
      Mrk3->PlotMarkers();
      delete Mrk3;
      break;
    case 4:
      Mrk4 = new Marker4(g->graph->MarkerSize, g->graph->ZeroSymbol,
                 g->graph->GraphColor, nlevs, LineWidth, xc, yc, Picture);
      Mrk4->PlotMarkers();
      delete Mrk4;
      break;
    case 5:
      Mrk5 = new Marker5(g->graph->MarkerSize, g->graph->ZeroSymbol,
                g->graph->GraphColor, nlevs, LineWidth, xc, yc, Picture);
      Mrk5->PlotMarkers();
      delete Mrk5;
      break;
    case 6:
      Mrk6 = new Marker6(g->graph->MarkerSize, g->graph->ZeroSymbol,
                g->graph->GraphColor, nlevs, LineWidth, xc, yc, Picture);
      Mrk6->PlotMarkers();
      delete Mrk6;
      break;
    case 7:
      Mrk7 = new Marker7(g->graph->MarkerSize, g->graph->ZeroSymbol,
                g->graph->GraphColor, nlevs, LineWidth, xc, yc, Picture);
      Mrk7->PlotMarkers();
      delete Mrk7;
      break;
    case 8:
      Mrk8 = new Marker8(g->graph->MarkerSize, g->graph->ZeroSymbol,
                g->graph->GraphColor, nlevs, LineWidth, xc, yc, Picture);
      Mrk8->PlotMarkers();
      delete Mrk8;
      break;
    case 9:
      Mrk9 = new Marker9(g->graph->MarkerSize, g->graph->ZeroSymbol,
                g->graph->GraphColor, nlevs, LineWidth, xc, yc, Picture);
      Mrk9->PlotMarkers();
      delete Mrk9;
      break;
    case 10:
      Mrk10 = new Marker10(g->graph->MarkerSize, g->graph->ZeroSymbol,
                g->graph->GraphColor, nlevs, LineWidth, xc, yc, Picture);
      Mrk10->PlotMarkers();
      delete Mrk10;
      break;
    case 11:
      Mrk11 = new Marker11(g->graph->MarkerSize, g->graph->ZeroSymbol,
                g->graph->GraphColor, nlevs, LineWidth, xc, yc, Picture);
      Mrk11->PlotMarkers();
      delete Mrk11;
      break;
    case 12:
      Mrk12 = new Marker12(g->graph->MarkerSize, g->graph->ZeroSymbol,
                g->graph->GraphColor, nlevs, LineWidth, xc, yc, Picture);
      Mrk12->PlotMarkers();
      delete Mrk12;
      break;
    case 13:
      Mrk13 = new Marker13(g->graph->MarkerSize, g->graph->ZeroSymbol,
                g->graph->GraphColor, nlevs, LineWidth, xc, yc, Picture);
      Mrk13->PlotMarkers();
      delete Mrk13;
      break;
    case 14:
      Mrk14 = new Marker14(g->graph->MarkerSize, g->graph->ZeroSymbol,
                g->graph->GraphColor, nlevs, LineWidth, xc, yc, Picture);
      Mrk14->PlotMarkers();
      delete Mrk14;
      break;
    case 15:
      Mrk15 = new Marker15(g->graph->MarkerSize, g->graph->ZeroSymbol,
                g->graph->GraphColor, nlevs, LineWidth, xc, yc, Picture);
      Mrk15->PlotMarkers();
      delete Mrk15;
      break;
    case 16:
      Mrk16 = new Marker16(g->graph->MarkerSize, g->graph->ZeroSymbol,
                g->graph->GraphColor, nlevs, LineWidth, xc, yc, Picture);
      Mrk16->PlotMarkers();
      delete Mrk16;
      break;
    case 17:
      Mrk17 = new Marker17(g->graph->MarkerSize, g->graph->ZeroSymbol,
                g->graph->GraphColor, nlevs, LineWidth, xc, yc, Picture);
      Mrk17->PlotMarkers();
      delete Mrk17;
      break;
    case 18:
      Mrk18 = new Marker18(g->graph->MarkerSize, g->graph->ZeroSymbol,
                g->graph->GraphColor, nlevs, LineWidth, xc, yc, Picture);
      Mrk18->PlotMarkers();
      delete Mrk18;
      break;
    case 19:
      Mrk19 = new Marker19(g->graph->MarkerSize, g->graph->ZeroSymbol,
                g->graph->GraphColor, nlevs, LineWidth, xc, yc, Picture);
      Mrk19->PlotMarkers();
      delete Mrk19;
      break;
    case 20:
      Mrk20 = new Marker20(g->graph->MarkerSize, g->graph->ZeroSymbol,
                g->graph->GraphColor, nlevs, LineWidth, xc, yc, Picture);
      Mrk20->PlotMarkers();
      delete Mrk20;
      break;
    case 21:
      Mrk21 = new Marker21(g->graph->MarkerSize, g->graph->ZeroSymbol,
                g->graph->GraphColor, nlevs, LineWidth, xc, yc, Picture);
      Mrk21->PlotMarkers();
      delete Mrk21;
      break;
    case 22:
      Mrk22 = new Marker22(g->graph->MarkerSize, g->graph->ZeroSymbol,
                g->graph->GraphColor, nlevs, LineWidth, xc, yc, Picture);
      Mrk22->PlotMarkers();
      delete Mrk22;
      break;
    case 23:
      Mrk23 = new Marker23(g->graph->MarkerSize, g->graph->ZeroSymbol,
                g->graph->GraphColor, nlevs, LineWidth, xc, yc, Picture);
      Mrk23->PlotMarkers();
      delete Mrk23;
      break;
    case 24:
      Mrk24 = new Marker24(g->graph->MarkerSize, g->graph->ZeroSymbol,
                g->graph->GraphColor, nlevs, LineWidth, xc, yc, Picture);
      Mrk24->PlotMarkers();
      delete Mrk24;
      break;
    case 25:
      Mrk25 = new Marker25(g->graph->MarkerSize, g->graph->ZeroSymbol,
                g->graph->GraphColor, nlevs, LineWidth, xc, yc, Picture);
      Mrk25->PlotMarkers();
      delete Mrk25;
      break;
    case 26:
      Mrk26 = new Marker26(g->graph->MarkerSize, g->graph->ZeroSymbol,
                g->graph->GraphColor, nlevs, LineWidth, xc, yc, Picture);
      Mrk26->PlotMarkers();
      delete Mrk26;
      break;
    case 27:
      Mrk27 = new Marker27(g->graph->MarkerSize, g->graph->ZeroSymbol,
                g->graph->GraphColor, nlevs, LineWidth, xc, yc, Picture);
      Mrk27->PlotMarkers();
      delete Mrk27;
      break;
    case 28:
      Mrk28 = new Marker28(g->graph->MarkerSize, g->graph->ZeroSymbol,
                g->graph->GraphColor, nlevs, LineWidth, xc, yc, Picture);
      Mrk28->PlotMarkers();
      delete Mrk28;
      break;
    case 29:
      Mrk29 = new Marker29(g->graph->MarkerSize, g->graph->ZeroSymbol,
                g->graph->GraphColor, nlevs, LineWidth, xc, yc, Picture);
      Mrk29->PlotMarkers();
      delete Mrk29;
      break;
    case 30:
      Mrk30 = new Marker30(g->graph->MarkerSize, g->graph->ZeroSymbol,
                g->graph->GraphColor, nlevs, LineWidth, xc, yc, Picture);
      Mrk30->PlotMarkers();
      delete Mrk30;
      break;
    case 31:
      Mrk31 = new Marker31(g->graph->MarkerSize, g->graph->ZeroSymbol,
                g->graph->GraphColor, nlevs, LineWidth, xc, yc, Picture);
      Mrk31->PlotMarkers();
      delete Mrk31;
      break;
    case 32:
      Mrk32 = new Marker32(g->graph->MarkerSize, g->graph->ZeroSymbol,
                g->graph->GraphColor, nlevs, LineWidth, xc, yc, Picture);
      Mrk32->PlotMarkers();
      delete Mrk32;
      break;
    }
}
//---------------------------------------------------------------------------

// plots a presence graph
void TTGDiagram::presence_graph(int nv, vector<double>& xc, vector<double>& yc,
	vector<bool>& xz, int nover, double min_xax, double max_xax, int nlevs)
{
  int j;
  //DblRect *rect;

  GRAPH* g = (GRAPH*)grf->Items[nv];

  for (j=1; j<=nlevs; j++) {
	if (xc[j] > 0.0) {
	  double dx = 0.5*g->graph->MarkerSize;
	  DblRect rect(xc[j]-dx, xc[j]+dx, yc[j]-dx, yc[j]+dx);
	  Picture->Ellipse(rect, g->graph->GraphColor, SOLID_FILL);
	  //delete rect;
	  }
    }

  if (g->status == NORMAL || nv == grf->Count-1 || last_overlay(nv)) {
    plot_baseline(nv, xz, yc, g->xax->Color, nlevs, min_xax);
    baseline_plotted = true;
    }

  if (g->graph->PresenceSymbol) {
    g->graph->AutoMarkerTop = false;
    g->graph->AutoMarkerBottom = false;
    g->graph->XMarkerLabel = g->xax->GraphNameXOffset;
    NEWYAXIS *Axis1 = (NEWYAXIS*)YAxes->Items[0];
    g->graph->YMarkerLabel = Axis1->Length() + g->xax->GraphNameYOffset;
    g->graph->MarkerType = 8;
    symbol_name(nv, nover, g->graph->GraphColor, min_xax, max_xax);
    }
  else {
    if (g->name.SubString(1, 1) != "{" && !g->name.IsEmpty())
      graphName(nv, g->name, min_xax, max_xax);
    }
}
//---------------------------------------------------------------------------

// plots a numbers graph
void TTGDiagram::numbers_graph(int nv, vector<double>& xc, vector<int>& xn, vector<double>& yc, double *width_grf,
		   int nlevs)
{
  double x[2], y[2], max_x;
  UnicodeString Buffer;
  UnicodeString fmt;
  double max_len_text, xtxt, ytxt, y0, y1, x0;
  MyText *Text;

  GRAPH* g = (GRAPH*)grf->Items[nv];
  NEWYAXIS *Axis1 = (NEWYAXIS*)YAxes->Items[0];

  x[0] = x[1] = 0.0;    // plot baseline
  y[0] = 0.0;
  y[1] = Axis1->Length();
  Picture->Polyline(2, x, y, g->xax->Color, g->xax->AxisLineWidth);

  max_x = maxdouble(&xc[1], nlevs);

  fmt = FloatFormat(g->graph->DecimalPoints);
  Buffer = FormatFloat(fmt, max_x);

  Text = new MyText(g->graph->NumberFont, Buffer, Picture);
  max_len_text = Text->Length();
  delete Text;

  x0 = max_len_text + 0.2;	// max width
  *width_grf = x0;

  //y0 = y1 = Axis1->len + 2.0*g->graph->NumberFont.Height;
  y0 = y1 = Axis1->Length() + 2.0*g->graph->NumberFont.Height;
  xtxt = x0;

  for (int j=1; j<=nlevs; j++)
    {
      if (xc[j] == 0.0 && !g->graph->PlotZeroNumbers) continue;
      Buffer = FormatFloat(fmt, xc[j]);
      ytxt = yc[j];
      //if (y0-ytxt < 1.3*g->graph->NumberFont.Height ||
      //     (j < nlevs && (y1-yc[j+1] < 1.3*g->graph->NumberFont.Height)))
      if (y0-ytxt < g->graph->NumberFont.Height ||
           (j < nlevs && (y1-yc[j+1] < g->graph->NumberFont.Height)))
	{
	  xtxt += x0;
	  if (y0 == y1) y1 = ytxt;
	  *width_grf = max(*width_grf, xtxt);
	}
      else
	{
	  xtxt = x0;
	  y0 = y1 = ytxt;
	}

      g->graph->NumberFont.Color = g->graph->GraphColor;
      Text = new MyText(xtxt, ytxt, g->graph->NumberFont, 0.0, TEXT_RIGHT, TEXT_HALF,
                        Buffer, Picture);
      Text->TextOut();
      delete Text;
    }

  (*width_grf) += 0.2;
  if (Boxes) {
    x[0] = 0.0;
    x[1] = *width_grf;
    y[0] = y[1] = Axis1->Length() - 0.2;
    Picture->Polyline(2, x, y, g->xax->Color, g->xax->AxisLineWidth);
    y[0] = y[1] = 0.2;
    Picture->Polyline(2, x, y, g->xax->Color, g->xax->AxisLineWidth);
    }
}
//---------------------------------------------------------------------------

// plots exaggerated graph
void TTGDiagram::exag_graph(int nv, int type, vector<double>& xc, vector<double>& yc,
	vector<double>& xe, vector<double>& ye, double Exag, double max_xax,
	double width_grf, int nlevs)
{
  int i, j, nep, nepc;
  vector<double> y(2, 0.0);
  vector<double> x(2, 0.0);
  double gridtic, ExagGrid;
  int outline_color;


  //color = 2; // temp

  GRAPH* g = (GRAPH*)grf->Items[nv];
  nep = 0;

  // first point, top of normal curve
  xe[nep] = (type == EXAGGERATE) ? xc[1] : 0.0;
  ye[nep++] = yc[1];

  // second point
  xe[nep] = (Exag*xc[1] > width_grf) ? width_grf : Exag*xc[1];
  ye[nep] = yc[1];

  for (j=2; j<=nlevs; j++) {
    if (Exag*xc[j] > width_grf) {	// point > graph width
      if (Exag*xc[j-1] <= width_grf) {
        xe[++nep] = width_grf;
        ye[nep] = yinterp(Exag*xc[j-1], yc[j-1], Exag*xc[j], yc[j], width_grf);
	}
      }
    else {				       // point <= graph width
      if (Exag*xc[j-1] > width_grf) {	// last point > graph width
        xe[++nep] = width_grf;
        ye[nep] = yinterp(Exag*xc[j-1], yc[j-1], Exag*xc[j], yc[j], width_grf);
        }
      xe[++nep] = Exag*xc[j];
      ye[nep] = yc[j];
      }
    }
  if (Exag*xc[nlevs] > width_grf) {	// last point if necessary
    xe[++nep] = width_grf;
    ye[nep] = yc[nlevs];
    }

  nepc = ++nep;	// nepc == first point of normal curve in xe, ye

  if (type == EXAGGERATE)
    {
      for (j=nlevs; j>0; j--) {
	xe[nep] = min(xc[j], width_grf);
	ye[nep++] = yc[j];
        }
      switch (g->graph->ExagFill)
      {
       case HOLLOW_FILL:
         outline_color = (g->graph->ExagOutlineColor == -1) ? g->graph->ExagColor : g->graph->ExagOutlineColor;
         Picture->Polygon(nep, xe, ye, g->graph->SilhouetteLineWidth, outline_color, 0,
           HOLLOW_FILL);
         break;
       case PATTERN_FILL:
         outline_color = (g->graph->ExagOutlineColor == -1) ? g->graph->ExagColor : g->graph->ExagOutlineColor;
         Picture->Polygon(nep, xe, ye, g->graph->SilhouetteLineWidth, outline_color,
           g->graph->ExagColor, PATTERN_FILL, g->graph->ExagPattern);
         break;
       case SOLID_FILL:
         outline_color = (g->graph->ExagOutlineColor == -1) ? g->graph->ExagColor : g->graph->ExagOutlineColor;
         Picture->Polygon(nep, xe, ye, g->graph->SilhouetteLineWidth, outline_color,
           g->graph->ExagColor, SOLID_FILL);
         break;
       case BAR_FILL:
         for (j=1; j<=nlevs; j++) {	// draw bars
	   x[0] = xc[j];
	   x[1] = min(width_grf, Exag*xc[j]);
	   y[0] = yc[j];
	   y[1] = yc[j];
	   Picture->Polyline(2, x.begin(), y.begin(), g->graph->ExagColor, g->graph->SilhouetteLineWidth);
	   }
         if (g->graph->ExagOutlineColor != -1)
		   Picture->Polyline(nepc+1, xe.begin(), ye.begin(), g->graph->ExagOutlineColor, g->graph->SilhouetteLineWidth);
		 else
		   Picture->Polyline(nepc+1, xe.begin(), ye.begin(), g->graph->ExagColor, g->graph->SilhouetteLineWidth);  // outside Exag
         outline_color = (g->graph->ExagOutlineColor == -1) ? g->graph->GraphColor : g->graph->ExagOutlineColor;
         Picture->Polyline(nlevs, &xe[nepc], &ye[nepc], outline_color, g->graph->SilhouetteLineWidth);    // inside Exag
         break;
       case GRID_FILL:
         ExagGrid = (g->graph->ExagGrid == ONMINORTICS) ? g->xax->MinorTics :
                 g->xax->MajorTics;
         gridtic = g->xax->ScaleFactor * ExagGrid;
         do {
             i = 1;
	     x[0] = x[1] = gridtic;
	     do {
	        if ((y[0] = start_gridline(nv, &i, gridtic, xc, yc)) > 0.0) {
	          y[1] = endGridline(&i, gridtic, xc, yc, Exag, nlevs);
			  Picture->Polyline(2, x.begin(), y.begin(), g->graph->ExagColor, g->graph->SilhouetteLineWidth, DOTTED_LINE);
	          i++;
	          }
	        } while (y[0] > 0.0);
	     gridtic += g->xax->ScaleFactor * ExagGrid;
	    } while (gridtic < (g->xax->ScaleFactor * (max_xax+0.5*ExagGrid)));
          if (g->graph->ExagOutlineColor != -1)
			Picture->Polyline(nepc+1, xe.begin(), ye.begin(), g->graph->ExagOutlineColor, g->graph->SilhouetteLineWidth);
		  else
		Picture->Polyline(nepc+1, xe.begin(), ye.begin(), g->graph->ExagColor, g->graph->SilhouetteLineWidth);	 // outside Exag
		  outline_color = (g->graph->ExagOutlineColor == -1) ? g->graph->GraphColor : g->graph->ExagOutlineColor;
	   //Picture->Polyline(nlevs, &xe[nepc], &ye[nepc], outline_color, g->graph->SilhouetteLineWidth);  // inside Exag
	   Picture->Polyline(nlevs, xe.begin()+nepc, ye.begin()+nepc, outline_color, g->graph->SilhouetteLineWidth);  // inside Exag
	   break;
	   }
    }
  else   // TRUNCATE
	{
      xe[nep] = 0.0;
      ye[nep] = yc[nlevs];
      xe[nep+1] = 0.0;
      ye[nep+1] = yc[1];
      nep += 2;

      switch (g->graph->GraphType)
	   {
	    case SILHOUETTE:
	      switch (g->graph->SilhouetteFill)
	       {
	       case HOLLOW_FILL:	// hollow
                 Picture->Polygon(nep, xe, ye, g->graph->SilhouetteLineWidth,
                   g->graph->GraphOutlineColor, 0, HOLLOW_FILL);
		 break;
	       case SOLID_FILL:   // solid
                 Picture->Polygon(nep, xe, ye, g->graph->SilhouetteLineWidth,
                   g->graph->GraphOutlineColor, g->graph->GraphColor, SOLID_FILL);
	         break;
	       case PATTERN_FILL:	// pattern
                 Picture->Polygon(nep, xe, ye, g->graph->SilhouetteLineWidth,
                   g->graph->GraphOutlineColor, g->graph->GraphColor, PATTERN_FILL,
                   g->graph->SilhouettePattern);
	         break;
	       case BAR_FILL:  // hollow, bars
			 Picture->Polyline(nepc+1, xe.begin(), ye.begin(), g->graph->GraphColor, g->graph->SilhouetteLineWidth);
	         x[0] = 0.0;
	         for (j=1; j<=nlevs; j++) {	// draw bars
			   x[1] = min(xc[j], width_grf);
	           y[0] = yc[j];
			   y[1] = yc[j];
			   Picture->Polyline(2, x.begin(), y.begin(), g->graph->GraphColor, g->graph->SilhouetteLineWidth);
			   }
	         break;
               }

	      if (g->graph->DepthBars)
	        {
	          x[1] = width_grf;
	          for (j=1; j<=nlevs; j++) {	// draw bars
	            if (xc[j] < width_grf) {
	              x[0] = xc[j];
		      y[0] = yc[j];
		      y[1] = yc[j];
			  Picture->Polyline(2, x.begin(), y.begin(), g->graph->DepthBarsColor, g->graph->SilhouetteLineWidth);
		      }
		    }
	        }
		  break;
		case LINEGRAPH:
		  //Picture->Polyline(nepc-1, &xe[1], &ye[1], g->graph->GraphColor, g->graph->SilhouetteLineWidth);
		  Picture->Polyline(nepc-1, xe.begin()+1, &ye[1], g->graph->GraphColor, g->graph->SilhouetteLineWidth);
		  if (g->graph->MarkerType > 0) {
	        for (j=1; j<nepc; j++)
	          if (xe[j] < width_grf)
                     Markers(g, 1, g->graph->MarkerLineWidth, &xe[j], &ye[j]);
	        }
	      break;
	   }
    }
}
//---------------------------------------------------------------------------

// plots symbol name
void TTGDiagram::symbol_name(int nv, int nover, int color_index, double min_xax,
              double max_xax)
{
  double xtxt;
  double x, y;
  MyText *Text;
  MYFONT SymbolNameFont;

  GRAPH* g = (GRAPH*)grf->Items[nv];

  SymbolNameFont = g->xax->GraphNameFont;

  if (g->graph->MarkerType == 0) {
    graphName(nv, g->name, min_xax, max_xax);
    return;
    }

  if (SymbolNameFont.Height < 0.0) SymbolNameFont.Height = 0.1;

  if (g->graph->AutoMarkerBottom)
    {
      if (g->xax->PlotGraphName)
        graphName(nv, g->name, min_xax, max_xax);
      if (nover == 0)
        symbol_name_ytxt = -g->xax->MajorTicLength -
                    g->xax->LabelToTicDistance -
                    g->xax->TicFont.Height -
                    ( g->xax->AxisLabel.IsEmpty() ?
                    0.0 : (3.0*g->xax->LabelToTicDistance + g->xax->AxisLabelFont.Height));
      else
        symbol_name_ytxt -= (nover*1.2*SymbolNameFont.Height);

      x = 0.1 + 0.5*g->graph->MarkerSize;
      y = symbol_name_ytxt - 0.5*SymbolNameFont.Height;
      if (g->graph->MarkerType > 0)
        Markers(g, 1, g->graph->MarkerLineWidth, &x, &y);

      g->graph->XMarkerLabel = x;
      g->graph->YMarkerLabel = y;

      xtxt = 0.2 + g->graph->MarkerSize;

      Text = new MyText(xtxt, symbol_name_ytxt, SymbolNameFont, 0.0, TEXT_LEFT,
                        TEXT_CAP, g->name, Picture);
      Text->TextOut();
      delete Text;
    }
  else if (g->graph->AutoMarkerTop || g->graph->GraphType == PRESENCE)
    TopSymbolName(nv, nover, SymbolNameFont, min_xax, max_xax, g->xax->GraphNameAngle);
  else
    //TopSymbolName(nv, nover, SymbolNameFont, min_xax, max_xax, g->xax->GraphNameAngle);
    TopSymbolName(nv, nover, SymbolNameFont, min_xax, max_xax, g->graph->AngleMarkerLabel);
}   
//---------------------------------------------------------------------------

void TTGDiagram::TopSymbolName(int nv, int nover, MYFONT& SymbolNameFont, double min_xax,
                               double max_xax, double angle)
{
  double a, b, x, y, xtxt, ytxt, r, rad;
  double XMarkerLabel, YMarkerLabel;
  MyText *Text;

  GRAPH* g = (GRAPH*)grf->Items[nv];
  NEWYAXIS *Axis1 = (NEWYAXIS*)YAxes->Items[0];

  if (!g->graph->AutoMarkerTop && !g->graph->AutoMarkerBottom) {
    XMarkerLabel = g->graph->XMarkerLabel;
    YMarkerLabel = g->graph->YMarkerLabel;
    }
  else if (nover == 0) {
    YMarkerLabel = Axis1->Length() + g->xax->GraphNameYOffset;
    if (g->xax->GraphNameXOffset < 0.0)
      XMarkerLabel = CenterSymbolLabel(nv, SymbolNameFont, min_xax, max_xax);
    else {
      XMarkerLabel = g->xax->GraphNameXOffset;
      XMarkerLabel -= 0.5*(g->xax->GraphNameFont.Height/sin(angle));
      XMarkerLabel += (1.0-angle/90.0)*g->graph->MarkerSize;
      YMarkerLabel += (angle/90.0)*g->graph->MarkerSize;
      }
    }
  else {
    if (angle == 0.0) {
      if (g->xax->GraphNameXOffset < 0.0)
        XMarkerLabel = CenterSymbolLabel(nv, SymbolNameFont, min_xax, max_xax);
      YMarkerLabel += 1.5*SymbolNameFont.Height;
      }
    else
      XMarkerLabel += (0.2 + 0.5*max(SymbolNameFont.Height, g->graph->MarkerSize));
    }

  if (angle == 90.0 || (!g->graph->AutoMarkerTop && !g->graph->AutoMarkerBottom)) {
    x = XMarkerLabel;
    y = YMarkerLabel;
    }
  else {
    x = XMarkerLabel + 0.5*g->graph->MarkerSize;
    y = YMarkerLabel + 0.5*g->graph->MarkerSize;
    }

  g->graph->XMarkerLabel = x;
  g->graph->YMarkerLabel = y;

  Markers(g, 1, g->graph->MarkerLineWidth, &x, &y);
  r = 0.5*SQRT2*g->graph->MarkerSize + 0.03;
  rad = angle*pi()/180.0;
  xtxt = x + r * cos(rad);
  ytxt = y + r * sin(rad);
  Text = new MyText(xtxt, ytxt, SymbolNameFont, angle, TEXT_LEFT, TEXT_HALF,
                    g->name, Picture);
  Text->TextOut();
  Text->MaxXY(&a, &b);
  if (b > max_ytaxa) max_ytaxa = b;
  delete Text;
}   
//---------------------------------------------------------------------------

double TTGDiagram::CenterSymbolLabel(int nv, MYFONT& SymbolNameFont, double min_xax, double max_xax)
{
   double total_len;
   MyText *Text;

   GRAPH* g = (GRAPH*)grf->Items[nv];
   Text = new MyText(SymbolNameFont, g->name, Picture);
   total_len = Text->Length();
   delete Text;
   if (g->graph->MarkerType > 0) {
     total_len += (0.5*g->graph->MarkerSize);
     total_len += (0.5*SQRT2*g->graph->MarkerSize + 0.03);
   }
   total_len *= cos(g->xax->GraphNameAngle*pi()/180.0);
   return (g->xax->ScaleFactor*0.5*(max_xax-min_xax) - 0.5*total_len);
}    
//---------------------------------------------------------------------------

// returns TRUE if last overlay, FALSE if not
bool TTGDiagram::last_overlay(int nv)
{
  int k;
  for (k=nv+1; k<grf->Count; k++)
    {
      GRAPH *g = (GRAPH*)grf->Items[k];
      if (g->status == NORMAL || g->status == BASE)
	return(1);
      if (g->status == OVERLAY || g->status == STACKED)
	return(0);
    }
  return(1);
}
//---------------------------------------------------------------------------

// plots axis baseline
void TTGDiagram::plot_baseline(int nv, vector<bool>& xz, vector<double>& yc, int baseline_color, int nlevs, double min_xax)
{
  int j0, j1, j2;
  double x[2], y[2];

  GRAPH* g = (GRAPH*)grf->Items[nv];
  NEWYAXIS *Axis1 = (NEWYAXIS*)YAxes->Items[0];

  // baseline from origin to bottom of graph
  x[0] = x[1] = 0.0;
  y[0] = (g->xax->LabelOriginTic) ? 0.2-g->xax->MajorTicLength : 0.0;
  y[1] = yc[nlevs+1];
  Picture->Polyline(2, x, y, g->xax->Color, g->xax->AxisLineWidth);
  if (g->xax->LabelOriginTic)
    label_tic(nv, 0.0, min_xax);

  // baseline from top to top of graph
  y[0] = yc[nlevs+2];
  y[1] = Axis1->Length();
  Picture->Polyline(2, x, y, g->xax->Color, g->xax->AxisLineWidth);

  if (g->graph->GraphType == SILHOUETTE && g->graph->DottedBaseLine)
    {
      y[0] = yc[nlevs+1];
      y[1] = yc[0];
      Picture->Polyline(2, x, y, Picture->BackgroundColor, g->xax->AxisLineWidth);

      j0 = j1 = 0;
      do {
	   while (xz[j1] && j1 < nlevs) j1++;
	   if (j1 < nlevs)
	     {
	       y[0] = yc[j0];
	       y[1] = yc[j1];
               Picture->Polyline(2, x, y, baseline_color, g->xax->AxisLineWidth);
	       j2 = j1+1;
	       //while (! xz[j2] && j2 < nlevs+1) j2++;
               while (j2 < nlevs+1 && !xz[j2]) j2++;
	       y[0] = yc[j1];
	       y[1] = yc[j2-1];
               Picture->Polyline(2, x, y, baseline_color, g->xax->AxisLineWidth, DOTTED_LINE);
	       j0 = j2-1;
	       j1 = j2+1;
	     }
	   else
	     {
	       y[0] = yc[j0];
	       y[1] = yc[nlevs];
               Picture->Polyline(2, x, y, baseline_color, g->xax->AxisLineWidth);
	     }
	 } while (j1 < nlevs);
    }
  else
    {
      y[0] = yc[nlevs+1];
      y[1] = yc[0];
      Picture->Polyline(2, x, y, baseline_color, g->xax->AxisLineWidth);
    }
}
//---------------------------------------------------------------------------

// plots numbers in truncated graphs
void TTGDiagram::truncated_numbers(int nv, vector<double>& xc, vector<double>& yc, double width_grf, int nlevs)
{
  int j;
  int value;
  double x, len_space;
  UnicodeString TruncValue;
  UnicodeString fmt;
  MyText *Text;

  GRAPH* g = (GRAPH*)grf->Items[nv];

  Text = new MyText(0.0, 0.0, g->xax->TruncFont, 0.0, TEXT_RIGHT, TEXT_HALF,
                    "0", Picture);
  len_space = Text->Length();
  delete Text;

  for (j=1; j<=nlevs; j++) {
	if (xc[j] > width_grf) {
	  if (g->xax->TruncateDecPts == 0) {
		value = (g->xax->ScaleTruncatedValues) ?
				nint(g->xax->TicLabelDivideBy*xc[j]/g->xax->ScaleFactor) :
				nint(xc[j]/g->xax->ScaleFactor);
		TruncValue = IntToStr(value);
		}
	  else {
		x = (g->xax->ScaleTruncatedValues) ?
			(g->xax->TicLabelDivideBy*xc[j]/g->xax->ScaleFactor) : (xc[j]/g->xax->ScaleFactor);
		fmt = FloatFormat(g->xax->TruncateDecPts);
		TruncValue = FormatFloat(fmt, x);
		}

		Text = new MyText(width_grf-0.5*len_space, yc[j], g->xax->TruncFont,
				   0.0, TEXT_RIGHT, TEXT_HALF, TruncValue, Picture);
		double xmin = width_grf - Text->Length() - len_space;
		double ymin = yc[j] - 0.6*g->xax->TruncFont.Height;
		double ymax = yc[j] + 0.6*g->xax->TruncFont.Height;
		DblRect rect(xmin, width_grf+0.01, ymin, ymax);
		Picture->FillRect(rect, BackgroundColor, SOLID_FILL);
		//delete rect;
		Text->TextOut();
		delete Text;
	  }
	}
}
//---------------------------------------------------------------------------

// plots graph name
void TTGDiagram::graphName(int nv, UnicodeString name, double min_xax, double max_xax)
{
  double a, b, xtxt, ytxt;
  MyText *Text;

  GRAPH* g = (GRAPH*)grf->Items[nv];
  NEWYAXIS *Axis1 = (NEWYAXIS*)YAxes->Items[0];

  if (g->xax->GraphNameXOffset < 0.0)       // center graph name
    {
      xtxt = g->xax->ScaleFactor * (max_xax-min_xax)/2.0;
      //ytxt = Axis1->len + g->xax->GraphNameYOffset;
      ytxt = Axis1->Length() + g->xax->GraphNameYOffset;

      if (g->xax->GraphNameAngle == 0.0)
        Text = new MyText(xtxt, ytxt, g->xax->GraphNameFont, 0.0, TEXT_CENTER,
                          TEXT_BASE, name, Picture);
      else if (g->xax->GraphNameAngle == 90.0)
        Text = new MyText(xtxt, ytxt, g->xax->GraphNameFont, 90.0, TEXT_LEFT,
                          TEXT_HALF, name, Picture);
      else
        Text = new MyText(xtxt, ytxt, g->xax->GraphNameFont, g->xax->GraphNameAngle, TEXT_LEFT,
                          TEXT_BASE, name, Picture);
    }
  else
    {
      xtxt = g->xax->GraphNameXOffset;
      ytxt = Axis1->Length() + g->xax->GraphNameYOffset;
      Text = new MyText(xtxt, ytxt, g->xax->GraphNameFont, g->xax->GraphNameAngle, TEXT_LEFT,
                        TEXT_BASE, name, Picture);
    }

  Text->TextOut();
  Text->MaxXY(&a, &b);
  if (b > max_ytaxa) max_ytaxa = b;
  delete Text;
}
//---------------------------------------------------------------------------

// double function endGridline(int *, double, float *, float *, double, int)
// gets end of grid line for exaggerated curve
double TTGDiagram::endGridline(int *i, double gridtic, vector<double>& x,
	vector<double>& y, double Exag, int nlevs)
{
  int j, k;
  double xe1, xe2;
  k = *i;
  for (j=k; j<=nlevs; j++)
    {
      xe2 = Exag*x[j];
      xe1 = Exag*x[j-1];
      if (j == nlevs)
	   {
	    if (x[j] < gridtic)
	     {
	      if (xe2 > gridtic)
		    return(y[j]);
	      else
		    return(yinterp(xe2, y[j], xe1, y[j-1], gridtic));
	     }
	    else
	     return(yinterp(x[j], y[j], x[j-1], y[j-1], gridtic));
	   }
      if (xe2 < gridtic && xe1 > gridtic)
	    return(yinterp(xe2, y[j], xe1, y[j-1], gridtic));
      else if (x[j] > gridtic && x[j-1] < gridtic)
	    return(yinterp(x[j], y[j], x[j-1], y[j-1], gridtic));
      (*i)++;
    }
  return(0.0);
}
//---------------------------------------------------------------------------

// plots graph end line
void TTGDiagram::endLine(void)
{
  double x[2], y[2];

  NEWYAXIS *Axis1 = (NEWYAXIS*)YAxes->Items[0];
  Picture->NewSegment("EndLine");
  x[0] = x[1] = end_graphs;
  y[0] = 0.0;
  y[1] = Axis1->Length();
  Picture->Polyline(2, x, y, EndLine.Color, EndLine.LineWidth);
  Picture->CloseSegment();
}
//---------------------------------------------------------------------------

// plots name boxes
void TTGDiagram::nameBoxes(void)
{
  int i;
  double x[3], y[3];
  SEGLIMITS* s;
  NEWYAXIS *Axis;
  NEWYAXIS *Axis1;
  NEWYAXIS *Axis2;

  if (Default.Xaxis.GraphNameAngle != 90.0) return;

  Picture->NewSegment("NameBoxes");

  Axis1 = (NEWYAXIS*)YAxes->Items[0];
  if (Axis1->AxisStyle == COLUMN_AXIS)
    {
      for (i=0; i<YAxes->Count; i++) {
         Axis = (NEWYAXIS*)YAxes->Items[i];
         if (Axis->yname_max > max_ytaxa)
           max_ytaxa = Axis->yname_max;
         }
      y[0] = y[1] = max_ytaxa + 0.2;
      y[2] = Axis1->Length();
      x[0] = 0.0;
      x[1] = x[2] = -0.2;
	  Picture->Polyline(3, x, y, NameBoxes.Color, NameBoxes.LineWidth);
      if (lopt.On) {
	x[0] = -0.2;
	x[1] = x[2] = -1.4;
        Picture->Polyline(3, x, y, NameBoxes.Color, NameBoxes.LineWidth);
	}

      x[0] = Axis1->xbase;
      x[1] = x[2] = Axis1->xbasec;
      Picture->Polyline(3, x, y, NameBoxes.Color, NameBoxes.LineWidth);

      if (YAxes->Count > 1) {
        Axis2 = (NEWYAXIS*)YAxes->Items[1];
        if (Axis2->Plot) {
          x[0] = Axis2->xbase;
	  x[1] = x[2] = Axis2->xbasec;
          Picture->Polyline(3, x, y, NameBoxes.Color, NameBoxes.LineWidth);
          }
	}
      y[0] = y[1] = Axis1->Length() - 0.2;
      x[0] = 0.0;
      Picture->Polyline(2, x, y, NameBoxes.Color, NameBoxes.LineWidth);
    }

  y[0] = Axis1->Length();
  y[1] = max_ytaxa + 0.2;
  x[0] = x[1] = 0.0;
  Picture->Polyline(2, x, y, NameBoxes.Color, NameBoxes.LineWidth);
  y[0] = y[1] = max_ytaxa + 0.2;
  y[2] = Axis1->Length();

  int nv=0;
  for (unsigned i=0; i<Picture->sl.size(); i++) {
	//s = (SEGLIMITS*)Picture->sl->Items[i];
	SEGLIMITS& s = Picture->sl[i];
	UnicodeString ss = s.name.SubString(1, 6);
	if (ss == "Graph:") {
	  x[0] = x[1];
	  //s = (SEGLIMITS*)Picture->sl->Items[i+1];
	  SEGLIMITS& s1 = Picture->sl[i+1];
	  x[1] = x[2] = s1.xmin;
	  GRAPH* g = (GRAPH*)grf->Items[nv];
	  Picture->Polyline(3, x, y, g->xax->Color, NameBoxes.LineWidth);
      nv++;
      }
    }

  Picture->CloseSegment();
}
//---------------------------------------------------------------------------

// void function plot_grid(double)
// plots grid across graph
void TTGDiagram::plot_grid(int nv, double max_xax)
{
  double GridLines, gridtic;
  double x[2], y[2];

  GRAPH* g = (GRAPH*)grf->Items[nv];
  NEWYAXIS *Axis1 = (NEWYAXIS*)YAxes->Items[0];

  if (g->xax->GridLines != NOGRIDLINES)
    {
      if (g->xax->GridLines == ONMINORTICS)
	GridLines = g->xax->MinorTics;
      else
	GridLines = g->xax->MajorTics;
      y[0] = Axis1->Length() - Axis1->XaxisDistance;
      y[1] = Axis1->XaxisDistance;
      gridtic = g->xax->ScaleFactor*GridLines;
      while (gridtic < (g->xax->ScaleFactor*(max_xax+0.5*GridLines))) {
	x[0] = x[1] = gridtic;
        Picture->Polyline(2, x, y, g->xax->Color, g->xax->GridLineWidth, DOTTED_LINE);
	gridtic += g->xax->ScaleFactor*GridLines;
	}
    }
}
//---------------------------------------------------------------------------

// void function plot_Xaxes(double, double, double *, double *)
// plots the x-axes
void TTGDiagram::plot_Xaxes(int nv, bool logcurv, double max_xax, double min_xax,
	double& DistanceToNextGraph, double& width_grf)
{
  double x[2], y[2], yu[2], yl[2];
  double tic, xtxt, ytxt;
  double power;
  double lentxt;
  //MyText *Text;

  GRAPH* g = (GRAPH*)grf->Items[nv];
  NEWYAXIS *Axis1 = (NEWYAXIS*)YAxes->Items[0];

  x[0] = 0.0;
  x[1] = g->xax->ScaleFactor*(max_xax-min_xax);
  y[0] = y[1] = 0.2;
  Picture->Polyline(2, x, y, g->xax->Color, g->xax->AxisLineWidth);  // draw bottom x-axis

  y[0] = y[1] = Axis1->Length() - 0.2;
  Picture->Polyline(2, x, y, g->xax->Color, g->xax->AxisLineWidth);   // draw top x-axis

  if (g->xax->MajorTics < g->xax->MinorTics)
	g->xax->MajorTics = g->xax->MinorTics;
  if (g->xax->LabeledTics < g->xax->MinorTics)
	g->xax->LabeledTics = g->xax->MinorTics;

  tic = min_xax;
  x[0] = 0.0;
  if (logcurv) {
	//yu[0] = Axis1->len - 0.2;
	yu[0] = Axis1->Length() - 0.2;
	yu[1] = y[0]-g->xax->TopTicLength;
	yl[0] = 0.2;

	power = 1.0;

	while (log10(power) < max_xax) {
	  yl[1] = 0.2 - g->xax->MajorTicLength;
	  logtic(nv, 2.0*power, min_xax, yu, yl, TICLABEL, g->xax->Color);
	  logtic(nv, 5.0*power, min_xax, yu, yl, TICLABEL, g->xax->Color);
	  logtic(nv, 10.0*power, min_xax, yu, yl, TICLABEL, g->xax->Color);

	  yl[1] = 0.2 - g->xax->MinorTicLength;
	  logtic(nv, 3.0*power, min_xax, yu, yl, NOTICLABEL, g->xax->Color);
	  logtic(nv, 4.0*power, min_xax, yu, yl, NOTICLABEL, g->xax->Color);
	  logtic(nv, 6.0*power, min_xax, yu, yl, NOTICLABEL, g->xax->Color);
	  logtic(nv, 7.0*power, min_xax, yu, yl, NOTICLABEL, g->xax->Color);
	  logtic(nv, 8.0*power, min_xax, yu, yl, NOTICLABEL, g->xax->Color);
	  logtic(nv, 9.0*power, min_xax, yu, yl, NOTICLABEL, g->xax->Color);
	  power *= 10.0;
	  }

	if (min_xax < 0.0) {
	  power = 1.0;
	  while (log10(power) > min_xax) {
		yl[1] = 0.2 - g->xax->MajorTicLength;
		logtic(nv, power, min_xax, yu, yl, TICLABEL, g->xax->Color);
		logtic(nv, 0.5*power, min_xax, yu, yl, TICLABEL, g->xax->Color);
		logtic(nv, 0.2*power, min_xax, yu, yl, TICLABEL, g->xax->Color);

		yl[1] = 0.2 - g->xax->MinorTicLength;
		logtic(nv, 0.9*power, min_xax, yu, yl, NOTICLABEL, g->xax->Color);
		logtic(nv, 0.8*power, min_xax, yu, yl, NOTICLABEL, g->xax->Color);
		logtic(nv, 0.7*power, min_xax, yu, yl, NOTICLABEL, g->xax->Color);
		logtic(nv, 0.6*power, min_xax, yu, yl, NOTICLABEL, g->xax->Color);
		logtic(nv, 0.4*power, min_xax, yu, yl, NOTICLABEL, g->xax->Color);
		logtic(nv, 0.3*power, min_xax, yu, yl, NOTICLABEL, g->xax->Color);
		power *= 0.1;
		}
	  }
	}
  else {
	while (tic < max_xax) {     // draw tic marks
	  tic += g->xax->MinorTics;
	  x[0] += (g->xax->MinorTics*g->xax->ScaleFactor);
	  x[1] = x[0];
	  y[0] = Axis1->Length() - 0.2;
	  y[1] = y[0] - g->xax->TopTicLength;
	  Picture->Polyline(2, x, y, g->xax->Color, g->xax->AxisLineWidth);     // top tic

	  y[0] = 0.2;
	  if (eventic(tic, g->xax->MajorTics, g->xax->MinorTics))  // major tic
		y[1] = 0.2 - g->xax->MajorTicLength;
	  else						 // minor tic
		y[1] = 0.2 - g->xax->MinorTicLength;

	  if (eventic(tic, g->xax->LabeledTics, g->xax->MinorTics) &&
		 (DistanceToNextGraph > 0.0 || tic+g->xax->MinorTics < max_xax))	// label tic
		{
		  label_tic(nv, x[0], tic);
		}
	  Picture->Polyline(2, x, y, g->xax->Color, g->xax->AxisLineWidth);     // draw tic mark
	  }
	}

  // if tic label is too wide, increase the distance between graphs
  // TicLabel contains the last tic label
  //if (strlen(buffer) > 0 && *DistanceToNextGraph > 0.0)
  if (!TicLabel.IsEmpty() && DistanceToNextGraph > 0.0) {
	//Text = new MyText(g->xax->TicFont, TicLabel, Picture);
	MyText Text(g->xax->TicFont, TicLabel, Picture);
	if (nv == 100)
      lentxt = Text.TestLength();
	else
	  lentxt = Text.Length();    // Here's the trouble!

	xtxt = x[0] + 0.5*lentxt;
	if (xtxt > width_grf) {
	  DistanceToNextGraph += xtxt + 0.1 - width_grf;
	  width_grf = xtxt+0.1;
	  }
	}

  // draw axis label
  if (! g->xax->AxisLabel.IsEmpty()) {
	ytxt = 0.2 - g->xax->MajorTicLength - g->xax->LabelToTicDistance - 1.6*g->xax->TicFont.Height;
	xtxt = g->xax->ScaleFactor*max_xax/2.0;
	MyText Text(xtxt, ytxt, g->xax->AxisLabelFont, 0.0, TEXT_CENTER, TEXT_CAP, g->xax->AxisLabel, Picture);
	Text.TextOut();
	}
}
//---------------------------------------------------------------------------

void TTGDiagram::logtic(int nv, double tic, double min_xax, double yu[],
                     double yl[], int ticlabel, int color)
{
  double x[2];

  GRAPH* g = (GRAPH*)grf->Items[nv];
  x[0] = x[1] = g->xax->ScaleFactor*(fabs(min_xax)+log10(tic));
  if (x[0] > 0.00001) {
    Picture->Polyline(2, x, yu, color, g->xax->AxisLineWidth);      // top tic
    Picture->Polyline(2, x, yl, color, g->xax->AxisLineWidth);      // bottom tic
    if (ticlabel) label_tic(nv, x[0], tic);  // tic label
    }
}
//---------------------------------------------------------------------------

// labels tic mark
void TTGDiagram::label_tic(int nv, double xtxt, double tic)
{
  double ytxt;
  int itic;
  double dtic;
  MyText *Text;

  GRAPH* g = (GRAPH*)grf->Items[nv];
  if (g->xax->TicDecPts == 0) {
    itic = tic*g->xax->TicLabelDivideBy;
	TicLabel = IntToStr(itic);
    }
  else {
    dtic = tic*g->xax->TicLabelDivideBy;
    TicLabel = FormatFloat(FloatFormat(g->xax->TicDecPts), dtic);
    }

  ytxt = 0.2 - g->xax->MajorTicLength - g->xax->LabelToTicDistance;
  Text = new MyText(xtxt, ytxt, g->xax->TicFont, 0.0, TEXT_CENTER,
                    TEXT_TOP, TicLabel, Picture);
  Text->TextOut();
  delete Text;
}
//---------------------------------------------------------------------------

// gets start of grid line for exaggerated curve
double TTGDiagram::start_gridline(int nv, int *i, double gridtic, vector<double>& x, vector<double>& y)
{
  int j, k;
  double xe1, xe2;
  if (*i > Levs->Count)
    return(-1.0);

  GRAPH* g = (GRAPH*)grf->Items[nv];

  if (*i == 1) {
    (*i)++;
    if (gridtic > x[1] && gridtic < g->graph->Exag * x[1])
      return(y[1]);
    }
  k = *i;
  for (j=k; j<=Levs->Count; j++) {
    xe2 = g->graph->Exag * x[j];
    xe1 = g->graph->Exag * x[j-1];
    if (xe2 > gridtic && xe1 < gridtic)
      return(yinterp(xe2, y[j], xe1, y[j-1], gridtic));
    else if (x[j] < gridtic && x[j-1] > gridtic)
      return(yinterp(x[j], y[j], x[j-1], y[j-1], gridtic));
	(*i)++;
    }
  return(-1.0);
}
//---------------------------------------------------------------------------

void TTGDiagram::plot_frame(void)
{
  vector<double> x(5, 0.0);
  vector<double> y(5, 0.0);
  Picture->NewSegment("Frame");
  box(x, y, Picture->MinExtentX()-Frame.FrameMargin,
            Picture->MinExtentY()-Frame.FrameMargin,
            Picture->MaxExtentX()+Frame.FrameMargin,
            Picture->MaxExtentY()+Frame.FrameMargin);
  Picture->Polyline(5, x.begin(), y.begin(), Frame.Color, Frame.LineWidth);
  Picture->CloseSegment();
}
//---------------------------------------------------------------------------

// TODO: update this function
// rotate a point
void TTGDiagram::rotate(double alpha, double *x, double *y)
{
  double theta, r;
  if (*x == (double)0.0 && *y == (double)0.0) return;
  r = sqrt((*x)*(*x) + (*y)*(*y));
  if (*x == (double)0.0) {
    if (*y > (double)0.0)
      theta = (double)0.5*PI;
    else
	  theta = (double)1.5*PI;
    }
  else if (*y == (double)0.0) {
    if (*x > (double)0.0)
      theta = (double)0.0;
    else
      theta = PI;
    }
  else
    {
      if (*y > (double)0.0) {
      	if (*x > (double)0.0)
    	  theta = asin((*y)/r);    // quadrant I
    	else
    	  theta = acos((*x)/r);    // quadrant II
    	}
      else {
    	if (*x < (double)0.0)
    	  theta = (double)2.0*PI-acos((*x)/r);  // quadrant III
    	else
	  theta = (double)2.0*PI+asin((*y)/r);  // quadrant IV
    	}
    }
  theta += alpha;
  *y = r*sin(theta);
  *x = r*cos(theta);
}
//---------------------------------------------------------------------------

void TTGDiagram::box(vector<double>& x, vector<double>& y, double x1, double y1, double x2, double y2)
{
  x[0] = x1; y[0] = y1;
  x[1] = x2; y[1] = y1;
  x[2] = x2; y[2] = y2;
  x[3] = x1; y[3] = y2;
  x[4] = x1; y[4] = y1;
}
//---------------------------------------------------------------------------

// finds array position of VarName. Returns -1 if not found.
int TTGDiagram::getVarNum(UnicodeString& VarCode)
{
  for (int i=0; i<grf->Count; i++) {
    GRAPH *g = (GRAPH*)grf->Items[i];
    if (g->code == VarCode)
      return i;
    }
  return -1;
}
//---------------------------------------------------------------------------

