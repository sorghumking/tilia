//---------------------------------------------------------------------------
#include <vcl.h>
#include "pch.h"
#pragma hdrstop

#include "TGGroups.h"
#ifndef TGDiagrmH
#include "TGDiagrm.h"
#endif
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

// plots group lines on top of diagram
void TTGDiagram::plot_groups(void)
{
  int i, ng, n1, n2, m1, m2, pos;
  double x[6], y[6];
  double dx, dy, x_center, alpha, max_hite_gn;
  double y_group_name;
  UnicodeString GroupSegment;
  MyText *Text;
  SEGLIMITS *s;
  GRAPH* g1;
  GRAPH* g2;

  // test that no start or end graphs are skipped
  bool error;
  do {
     error = false;
     for (ng=0; ng<Groups->Count; ng++) {
       GROUPS *Group = (GROUPS*)Groups->Items[ng];
       i = 0;
       GRAPH *g = (GRAPH*)grf->Items[i];
       while (g->code != Group->code1) {  // find graph
         i++;
         g = (GRAPH*)grf->Items[i];
         }
       if (g->status != NORMAL && g->status != BASE) {
         Groups->Delete(ng);
         delete Group;
         error = true;
         break;
         }
       i = 0;
       g = (GRAPH*)grf->Items[i];
       while (g->code != Group->code2) {   // find graph
         i++;
         g = (GRAPH*)grf->Items[i];
         }
       if (g->status != NORMAL && g->status != BASE) {
         Groups->Delete(ng);
         delete Group;
         error = true;
         break;
         }
       }
     } while (error);

  if (Groups->Count == 0) return;

  NEWYAXIS *Axis1 = (NEWYAXIS*)YAxes->Items[0];

  max_hite_gn = 0.0;
  for (ng=0; ng<Groups->Count; ng++) {
    GROUPS *Group = (GROUPS*)Groups->Items[ng];
    max_hite_gn = max(max_hite_gn, Group->Font.Height);
    }

  for (ng=0; ng<Groups->Count; ng++)
    {
	  GROUPS *Group = (GROUPS*)Groups->Items[ng];
	  for (unsigned int i=0; i<Picture->sl.size(); i++) {
		//s = (SEGLIMITS*)Picture->sl->Items[i];
		SEGLIMITS& s = Picture->sl[i];
		UnicodeString ss = s.name.SubString(1, 6);
		if (ss == "Graph:") {
		  UnicodeString VarCode = s.name.SubString(8, s.name.Length()-7);
		  UnicodeString GroupCode = Group->code1;
		  if (VarCode.Compare(GroupCode) == 0) {
			m1 = i;
			break;
			}
		  }
		}

	  for (i=0; i<grf->Count; i++) {
		GRAPH *g = (GRAPH*)grf->Items[i];
		if (g->code == Group->code1) {
		  n1 = i;
		  break;
		  }
		}
	  if (i == grf->Count) continue;

	  for (unsigned i=0; i<Picture->sl.size(); i++) {
		//s = (SEGLIMITS*)Picture->sl->Items[i];
		SEGLIMITS& s = Picture->sl[i];
		UnicodeString ss = s.name.SubString(1, 6);
		if (ss == "Graph:") {
		  UnicodeString VarCode = s.name.SubString(8, s.name.Length()-7);
		  UnicodeString GroupCode = Group->code2;
		  if (VarCode.Compare(GroupCode) == 0) {
			m2 = i;
			break;
			}
		  }
		}

	  for (i=0; i<grf->Count; i++) {
		GRAPH *g = (GRAPH*)grf->Items[i];
		if (g->code == Group->code2) {
		  n2 = i;
		  break;
		  }
		}
      if (i == grf->Count) continue;

      GroupSegment = "Group " + IntToStr(ng+1);
      Picture->NewSegment(GroupSegment);

      if (Boxes)
	{
		  //s = (SEGLIMITS*)Picture->sl->Items[m1];
		  //SEGLIMITS& s = Picture->sl[m1];
		  x[0] = x[1] = Picture->sl[m1].xmin;
		  //s = (SEGLIMITS*)Picture->sl->Items[m2+1];
		  x[2] = x[3] = Picture->sl[m2+1].xmin;

	  y[0] = y[3] = max_ytaxa + 0.2;
	  y[1] = y[2] = y[0] + (3.0*max_hite_gn);
          Picture->Polyline(4, x, y, Group->Color, Group->LineWidth);
	  y_group_name = (y[0]+y[1])/2.0;
	  x_center = (x[0]+x[2])/2.0;
          Text = new MyText(x_center, y_group_name, Group->Font, 0.0,
                            TEXT_CENTER, TEXT_HALF, Group->name, Picture);
          Text->TextOut();
          delete Text;
	}
      else
	{
	  y_group_name = max_ytaxa + 0.3 + 0.5*max_hite_gn;
          g1 = (GRAPH*)grf->Items[n1];
          g2 = (GRAPH*)grf->Items[n2];

          if (g1->xax->GraphNameXOffset >= 0.0 && g2->xax->GraphNameXOffset >= 0.0)
	    {
              if (g1->xax->GraphNameAngle == 0.0) continue;

	      alpha = g1->xax->GraphNameAngle*RPD;	    // convert angle to radians
              GRAPH *g_n1 = (GRAPH*)grf->Items[n1];
              Text = new MyText(g1->xax->GraphNameFont, g_n1->name, Picture);
              dx = Text->Length();
              delete Text;

	      dx += 0.2;
              UnicodeString str1 = g_n1->name;
			  pos = str1.Pos("\\");
              if (pos == 0)       // no style in string
                dy = 0.20*g1->xax->GraphNameFont.Height;
              else
                dy = 0.35*g1->xax->GraphNameFont.Height;
	      rotate(alpha, &dx, &dy);

			  //s = (SEGLIMITS*)Picture->sl->Items[m1];
			  x[0] = dx + g1->xax->GraphNameXOffset + Picture->sl[m1].xmin;
              y[0] = dy + Axis1->Length() + g1->xax->GraphNameYOffset;

              if (g1->graph->AutoMarkerTop) {
                x[0] += (1.0-g1->xax->GraphNameAngle/90.0)*(g1->graph->MarkerSize+0.1);
                y[0] += (g1->xax->GraphNameAngle/90.0)*(g1->graph->MarkerSize+0.1);
                }

	      dy = y_group_name - y[0];
	      dx = dy/tan(alpha);
	      x[1] = x[0] + dx;
	      y[1] = y_group_name;

	      if (g2->xax->GraphNameAngle == 0.0) continue;
	      alpha = g2->xax->GraphNameAngle*RPD;	    // convert angle to radians

              GRAPH *g_n2 = (GRAPH*)grf->Items[n2];
              Text = new MyText(g2->xax->GraphNameFont, g_n2->name, Picture);
              dx = Text->Length();
              delete Text;

	      dx += 0.1;
			  UnicodeString str2 = g_n1->name;
              pos = str2.Pos("\\");
              if (pos == 0)       // no style in string
                dy = 0.20*g2->xax->GraphNameFont.Height;
              else
                dy = 0.35*g2->xax->GraphNameFont.Height;

	      rotate(alpha, &dx, &dy);
			  //s = (SEGLIMITS*)Picture->sl->Items[m2];
			  x[5] = dx + g2->xax->GraphNameXOffset + Picture->sl[m2].xmin;
              y[5] = dy + Axis1->Length() + g2->xax->GraphNameYOffset;

              if (g1->graph->AutoMarkerTop) {
                x[5] += (1.0-g1->xax->GraphNameAngle/90.0)*(g1->graph->MarkerSize+0.1);
                y[5] += (g1->xax->GraphNameAngle/90.0)*(g1->graph->MarkerSize+0.1);
                }

	      dy = y_group_name - y[5];
	      dx = dy/tan(alpha);
	      x[4] = x[5] + dx;
	      y[4] = y_group_name;
	    }
	  else	// centered graph names
	    {
			  //s = (SEGLIMITS*)Picture->sl->Items[m1];
			  x[0] = x[1] = Picture->sl[m1].xmin;
              y[0] = Axis1->Length();
	      y[1] = y_group_name;
			  //s = (SEGLIMITS*)Picture->sl->Items[m2+1];
			  x[5] = x[4] = Picture->sl[m2+1].xmin;
              y[5] = Axis1->Length();
	      y[4] = y_group_name;
	    }

	  x_center = (x[1] + x[4])/2.0;
          Text = new MyText(Group->Font, Group->name, Picture);
          dx = 0.5*Text->Length();
          delete Text;

	  dx += 0.2;
	  x[2] = x_center - dx;
	  x[3] = x_center + dx;
	  y[2] = y_group_name;
	  y[3] = y_group_name;

          if (Group->Position == INLINE) {
	   if (x[2] > x[1])
             Picture->Polyline(3, x, y, Group->Color, Group->LineWidth);
	   else
             Picture->Polyline(2, x, y, Group->Color, Group->LineWidth);

	   if (x[4] > x[3])
             Picture->Polyline(3, &x[3], &y[3], Group->Color, Group->LineWidth);
	   else
             Picture->Polyline(2, &x[4], &y[4], Group->Color, Group->LineWidth);

           Text = new MyText(x_center, y_group_name, Group->Font, 0.0,
                             TEXT_CENTER, TEXT_HALF, Group->name, Picture);
           Text->TextOut();
           delete Text;
          }
         else {
           x[2] = x[4];
           y[2] = y[4];
           x[3] = x[5];
           y[3] = y[5];
           Picture->Polyline(4, x, y, Group->Color, Group->LineWidth);
           Text = new MyText(x_center, y_group_name+0.3*Group->Font.Height, Group->Font, 0.0,
                             TEXT_CENTER, TEXT_BOTTOM, Group->name, Picture);
           Text->TextOut();
           delete Text;
           }

	}
      Picture->CloseSegment();
    }
}

