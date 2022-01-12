//---------------------------------------------------------------------------
#include <vcl.h>
#include "pch.h"
#pragma hdrstop

#include "TGDates.h"
#ifndef TGH
#include "tg.h"
#endif
#ifndef TGDiagrmH
#include "TGDiagrm.h"
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
#ifndef TGYaxisH
#include "TGYaxis.h"
#endif


//---------------------------------------------------------------------------
#pragma package(smart_init)


void TTGDiagram::plot_dates(double yfac)
{
  int i;
  double l, len, xseg, xtxt, ytxt;
  double xmin, xmax, ymin, ymax;
  MyText *Text;
  int vert_align, horz_align;
  //DblRect *rect;

  Picture->NewSegment("Dates");

  NEWYAXIS *Axis1 = (NEWYAXIS*)YAxes->Items[0];

  DATES* Date = (DATES*)Dates->Items[0];
  Text = new MyText(dopt.DateFont, Date->date, Picture);
  len = Text->Length();
  delete Text;
  for (i=1; i<Dates->Count; i++) {
    DATES* Date = (DATES*)Dates->Items[i];
    Text = new MyText(dopt.DateFont, Date->date, Picture);
    if ((l = Text->Length()) > len)
      len = l;
    delete Text;
    }
  switch (dopt.DatesPosition)
    {
      case LEFT:
        xseg = Picture->MinExtentX() - 0.3;
	xtxt = xseg - 0.1;
        horz_align = TEXT_RIGHT;
        vert_align = TEXT_HALF;
	break;
      case RIGHT:
	xseg = end_graphs + 0.1;
	xtxt = xseg + 0.15;
        horz_align = TEXT_LEFT;
        vert_align = TEXT_HALF;
        break;
    }

  for (i=0; i<Dates->Count; i++)
    {
      xmin = xseg;
      xmax = xseg + 0.1;
      DATES* Date = (DATES*)Dates->Items[i];
      ymin = Axis1->ywc(Date->bot);
      ymax = Axis1->ywc(Date->top);
	  //rect = new DblRect(xmin, xmax, ymin, ymax);
	  DblRect rect(xmin, xmax, ymin, ymax);
	  Picture->FillRect(rect, dopt.Color, SOLID_FILL);
	  //delete rect;
      ytxt = (ymin+ymax)/2.0 + Date->voff;
      Text = new MyText(xtxt, ytxt, dopt.DateFont, 0.0, horz_align,
                        vert_align, Date->date, Picture);
      Text->TextOut();
      delete Text;
    }

  if (! dopt.DateTitle.IsEmpty())  // plot label
    {
      switch (dopt.DatesTitlePosition)
      {
      case SIDE:
        dopt.Y_Title = Axis1->ywc(Axis1->ScaleMin) - 0.5*yfac*(Axis1->ScaleMax - Axis1->ScaleMin);
        switch (dopt.DatesPosition)
        {
        case LEFT:
		  //dopt.X_Title = ((SEGLIMITS*)Picture->sl->Last())->xmin;
		  dopt.X_Title = Picture->sl.back().xmin;
		  break;
		case RIGHT:
		  //dopt.X_Title = ((SEGLIMITS*)Picture->sl->Last())->xmax + dopt.DateTitleFont.Height;
		  dopt.X_Title = Picture->sl.back().xmax + dopt.DateTitleFont.Height;
		  break;
		}

        Text = new MyText(dopt.X_Title, dopt.Y_Title, dopt.DateTitleFont, 90.0,
                          TEXT_CENTER, TEXT_BOTTOM, dopt.DateTitle, Picture);
        Text->TextOut();
        delete Text;
        break;
      case TOP:
        dopt.Y_Title = Axis1->Length() + dopt.DatesTitleTopYOffset;
        if (dopt.Angle == 0.0)
	  {
	    switch (dopt.DatesPosition)
	    {
            case LEFT:
              horz_align = TEXT_RIGHT;
              vert_align = TEXT_BASE;
			  //dopt.X_Title = ((SEGLIMITS*)Picture->sl->Last())->xmax;
              dopt.X_Title = Picture->sl.back().xmax;
			  break;
            case RIGHT:
              horz_align = TEXT_LEFT;
              vert_align = TEXT_BASE;
              dopt.X_Title = xseg + Default.Xaxis.GraphNameXOffset;
              break;
            }
          }
        else
	  {
            horz_align = TEXT_LEFT;
            vert_align = TEXT_BASE;
            switch (dopt.DatesPosition)
            {
	    case LEFT:
	      if (dopt.Angle == 90.0)
				//dopt.X_Title = ((SEGLIMITS*)Picture->sl->Last())->xmax - 0.1;
				dopt.X_Title = Picture->sl.back().xmax - 0.1;
			  else
				//dopt.X_Title = ((SEGLIMITS*)Picture->sl->Last())->xmax - 0.1 - 0.8*dopt.DateFont.Height;
				dopt.X_Title = Picture->sl.back().xmax - 0.1 - 0.8*dopt.DateFont.Height;
              break;
            case RIGHT:
	      if (dopt.Angle == 90.0)
                dopt.X_Title = xseg + 0.1 + dopt.DateTitleFont.Height;
              else
		dopt.X_Title = xseg + Default.Xaxis.GraphNameXOffset;
              break;
            }
          }
        Text = new MyText(dopt.X_Title, dopt.Y_Title, dopt.DateTitleFont, dopt.Angle,
                        horz_align, vert_align, dopt.DateTitle, Picture);
        Text->TextOut();
        delete Text;
        break;
      default:  // user defined
        Text = new MyText(dopt.X_Title, dopt.Y_Title, dopt.DateTitleFont, dopt.Angle,
                          TEXT_LEFT, TEXT_BASE, dopt.DateTitle, Picture);
        Text->TextOut();
        delete Text;
        break;
      }
    }
  Picture->CloseSegment();
}

