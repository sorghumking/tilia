//---------------------------------------------------------------------------
#include <vcl.h>
#include "pch.h"
#pragma hdrstop

#ifndef TGDiagrmH
#include "TGDiagrm.h"
#endif
#include "TGZone.h"
#ifndef TGraphicH
#include "TGraphic.h"
#endif
#ifndef TGTextH
#include "TGText.h"
#endif
#ifndef TGH
#include "tg.h"
#endif
#ifndef TGYaxisH
#include "TGYaxis.h"
#endif

//---------------------------------------------------------------------------
#pragma package(smart_init)

void ZONE_ATTRIBUTES::operator = (const ZONE_ATTRIBUTES& copy)
{
   if (this == &copy) return;
   ThruLabelCol = copy.ThruLabelCol;
   ZoneStyle = copy.ZoneStyle;
   LineStyle = copy.LineStyle;
   Pattern = copy.Pattern;
   Border = copy.Border;
   Priority = copy.Priority;
   ZoneColor = copy.ZoneColor;
   BorderColor = copy.BorderColor;
   ZoneWidth = copy.ZoneWidth;
   LineWidth = copy.LineWidth;
   user = copy.user;
}

void ZONE::operator = (const ZONE_ATTRIBUTES& copy)
{
   if (this == &copy) return;
   ThruLabelCol = copy.ThruLabelCol;
   ZoneStyle = copy.ZoneStyle;
   LineStyle = copy.LineStyle;
   Pattern = copy.Pattern;
   Border = copy.Border;
   Priority = copy.Priority;
   ZoneColor = copy.ZoneColor;
   BorderColor = copy.BorderColor;
   ZoneWidth = copy.ZoneWidth;
   LineWidth = copy.LineWidth;
   user = copy.user;
}

void ZONE::operator = (const ZONE& copy)
{
   if (this == &copy) return;
   ThruLabelCol = copy.ThruLabelCol;
   ZoneStyle = copy.ZoneStyle;
   LineStyle = copy.LineStyle;
   Pattern = copy.Pattern;
   Border = copy.Border;
   Priority = copy.Priority;
   ZoneColor = copy.ZoneColor;
   BorderColor = copy.BorderColor;
   ZoneWidth = copy.ZoneWidth;
   LineWidth = copy.LineWidth;
   user = copy.user;
   //depth = copy.depth;
}

ZONE::ZONE(ZONE* z)
{
  ZoneStyle = z->ZoneStyle;
  LineStyle = z->LineStyle;
  Pattern = z->Pattern;
  Border = z->Border;
  Priority = z->Priority;
  ZoneColor = z->ZoneColor;
  BorderColor = z->BorderColor;
  depth = z->depth;
  ZoneWidth = z->ZoneWidth;
  LineWidth = z->LineWidth;
  user = z->user;
  ThruLabelCol = z->ThruLabelCol;
}

// plots zone labels
void TTGDiagram::plot_zone_labels(double yfac)
{
  int i;
  double x[3], y[3];
  double xtxt, ytxt, depth, maxlen, len;
  MyText *Text;

  NEWYAXIS *Axis1 = (NEWYAXIS*)YAxes->Items[0];

  Picture->NewSegment("ZoneLabels");

  Text = new MyText(zopt.ZoneTitleFont, zopt.ZoneTitle, Picture);
  maxlen = Text->Length();
  delete Text;

  for (i=0; i<ZoneLabels->Count; i++) {
    ZONELABELS *ZoneLabel = (ZONELABELS*)ZoneLabels->Items[i];
    Text = new MyText(zopt.ZoneFont, ZoneLabel->label, Picture);
    len = Text->Length();
    delete Text;
    if (len > maxlen) maxlen = len;
    }
  zone_col_width = maxlen + 0.4;

  x[0] = x[1] = end_graphs + zone_col_width;
  y[0] = 0.0;
  y[1] = Axis1->Length();
  Picture->Polyline(2, x, y, EndLine.Color, EndLine.LineWidth);

  if (Boxes) {
    y[0] = y[1] = max_ytaxa + 0.2;
    y[2] = Axis1->Length();
    x[0] = end_graphs;
    x[1] = x[2] = end_graphs + zone_col_width;
    Picture->Polyline(3, x, y, NameBoxes.Color, NameBoxes.LineWidth);
    y[0] = y[1] = Axis1->Length() - 0.2;
    Picture->Polyline(2, x, y, NameBoxes.Color, NameBoxes.LineWidth);
    y[0] = y[1] = 0.2;
    Picture->Polyline(2, x, y, NameBoxes.Color, NameBoxes.LineWidth);
    }

  if (zopt.ZoneTitleAngle == 0.0 && zopt.Center) {
    xtxt = end_graphs + (zone_col_width/2.0);
    Text = new MyText(xtxt, Axis1->Length()+zopt.ZoneTitleYOffset, zopt.ZoneTitleFont, 0.0, TEXT_CENTER,
                        TEXT_BASE, zopt.ZoneTitle, Picture);
    Text->TextOut();
    delete Text;
    }
  else if (zopt.ZoneTitleAngle == 90.0 && zopt.Center) {
    xtxt = end_graphs + (zone_col_width/2.0);
    Text = new MyText(xtxt, Axis1->Length()+zopt.ZoneTitleYOffset, zopt.ZoneTitleFont, 90.0, TEXT_LEFT,
                      TEXT_HALF, zopt.ZoneTitle, Picture);
    Text->TextOut();
    delete Text;
    }
  else {
    if (zopt.Center)
      xtxt = end_graphs + (zone_col_width/2.0);
    else
      xtxt = end_graphs + zopt.ZoneTitleXOffset;
    ytxt = Axis1->Length() + zopt.ZoneTitleYOffset;
    Text = new MyText(xtxt, ytxt, zopt.ZoneTitleFont, zopt.ZoneTitleAngle, TEXT_LEFT,
                      TEXT_BASE, zopt.ZoneTitle, Picture);
    Text->TextOut();
    delete Text;
    }

  xtxt = end_graphs + (zone_col_width/2.0);
  for (i=0; i<ZoneLabels->Count; i++) {
    ZONELABELS *ZoneLabel = (ZONELABELS*)ZoneLabels->Items[i];
    depth = (ZoneLabel->top + ZoneLabel->bottom)/2.0;
    ytxt = Axis1->ywc(depth);
    Text = new MyText(xtxt, ytxt, zopt.ZoneFont, 0.0, TEXT_CENTER,
                      TEXT_HALF, ZoneLabel->label, Picture);
    Text->TextOut();
    delete Text;
    }

  end_graphs += zone_col_width;
  Picture->CloseSegment();
}
//---------------------------------------------------------------------------

void TTGDiagram::plot_zones(double yfac)
{

  int i, g1, g2;
  double width;
  double end;
  vector<double> x(5, 0.0);
  vector<double> y(5, 0.0);

  NEWYAXIS *Axis1 = (NEWYAXIS*)YAxes->Items[0];

  Picture->NewSegment("Zones");
  for (i=0; i<Zones->Count; i++)
    {
      ZONE *Zone = (ZONE*)Zones->Items[i];
      end = end_graphs;
      if (!Zone->ThruLabelCol)
        end -= zone_col_width;

      if (Zone->ZoneStyle == LINEZONE) {
        y[0] = y[1] = Axis1->ywc(Zone->depth);
        x[0] = 0.0;
        x[1] = end;
        if (Zone->LineStyle == USER_DEFINED_LINE)
		  Picture->Polyline(2, x.begin(), y.begin(), Zone->ZoneColor, Zone->LineWidth,
                            Zone->user, Zone->Priority);
        else
		  Picture->Polyline(2, x.begin(), y.begin(), Zone->ZoneColor, Zone->LineWidth,
                            Zone->LineStyle, Zone->Priority);
	}
      else {  // pattern
        if (Zone->ZoneWidth > 0.0)
          width = Zone->ZoneWidth;
        else
	  width = -yfac*Zone->ZoneWidth;

        y[0] = y[1] = y[4] = Axis1->ywc(Zone->depth) + 0.5*width;
	y[2] = y[3] = y[0] - width;

        if (Zone->Pattern < 35)
	  {
	    x[0] = x[3] = x[4] = 0.0;
            x[1] = x[2] = end;
            int fill = (Zone->Pattern < 34) ? PATTERN_FILL : SOLID_FILL;
            if (Zone->Border)
              Picture->Polygon(5, x, y, Zone->LineWidth, Zone->BorderColor,
                 Zone->ZoneColor, fill, Zone->Pattern, Zone->Priority);
            else
              Picture->Polygon(5, x, y, Zone->LineWidth, -1, Zone->ZoneColor,
                 fill, Zone->Pattern, Zone->Priority);

            // plot left and right ends of zone in axis color
			UnicodeString TempStr;
            if (Zone->Priority == ZONETOFRONT) {
              for (int nv=0; nv<grf->Count; nv++) {
                GRAPH *g = (GRAPH*)grf->Items[nv];
                if (PlottedGraph(g)) {
                  Picture->Polyline(2, &x[3], &y[3], g->graph->GraphOutlineColor,
                     Zone->LineWidth);
                  break;
                  }
                }

              // TODO: fix this for endline or zone name column color
              // right-hand side (end line) -- may be fixed now
              //Picture->Polyline(2, &x[1], &y[1], Colors.a_color, Zone->LineWidth);
              Picture->Polyline(2, &x[1], &y[1], EndLine.Color, EndLine.LineWidth);
              }
            }
          else   // dashed
	    {
              if (Zone->user.dash == 0 || Zone->user.space == 0) {
                Zone->user.dash = 20;
                Zone->user.space = 10;
                }
              double Dash = Zone->user.dash/72.0;
              double Space = Zone->user.space/72.0;

              x[0] = 0.0;
              x[1] = Dash;
              do {
                 x[2] = x[1];
	         x[3] = x[4] = x[0];
                 Picture->Polygon(5, x, y, 0.0, -1, Zone->ZoneColor,
                      SOLID_FILL, 0, Zone->Priority);
                 x[0] = x[1] + Space;
                 x[1] = min(x[0]+Dash, end);
                 } while (x[0] < end);

              if (Zone->Border) {
                x[0] = 0.0;
                x[1] = end;
                y[0] = y[1] = Axis1->ywc(Zone->depth) + 0.5*width;
				Picture->Polyline(2, x.begin(), y.begin(), Zone->BorderColor, Zone->LineWidth,
                        SOLID_LINE, Zone->Priority);
                y[0] -= width;
                y[1] -= width;
				Picture->Polyline(2, x.begin(), y.begin(), Zone->BorderColor, Zone->LineWidth,
                SOLID_LINE, Zone->Priority);
				}
            }
	}
    }
  Picture->CloseSegment();
}
