//---------------------------------------------------------------------------
#include <vcl.h>
#include "pch.h"
#pragma hdrstop

#ifndef TGDiagrmH
#include "TGDiagrm.h"
#endif
#include "TGTxtOut.h"
#ifndef TGraphicH
#include "TGraphic.h"
#endif
#ifndef TGTextH
#include "TGText.h"
#endif

//---------------------------------------------------------------------------
#pragma package(smart_init)

// plots diagram heading
void TTGDiagram::plot_heading(void)
{
  int nh;
  double minseg, dy;
  SEGLIMITS *s;
  MyText *Text;

  if (! heading[0].Text.IsEmpty())
	{
	  if (heading[0].AutoX) {         // calculate coordinates
		//s = (SEGLIMITS*)Picture->sl->Items[0];
		minseg = Picture->sl[0].xmin;
		for (unsigned i=1; i<Picture->sl.size(); i++) {
		  //s = (SEGLIMITS*)Picture->sl->Items[i];
		  SEGLIMITS& s = Picture->sl[i];
		  if (s.xmin < minseg)
			minseg = s.xmin;
		  }
		for (int i=0; i<4; i++)
          heading[i].x = minseg;
        heading[0].AutoX = false;
	}

      if (heading[0].AutoY) {
	nh = 0;
	heading[0].y = 0.0;
	for (int i=1; i<4; i++) {
          if (! heading[i].Text.IsEmpty()) {
	    heading[i].y = heading[i-1].y - 1.3*heading[i-1].Font.Height;
	    nh++;
	    }
          else
	    break;
	  }

	dy = -(heading[nh].y - heading[nh].Font.Height);
	if (Groups->Count > 0) dy += 0.5;
	for (int i=0; i<=nh; i++)
		  heading[i].y += (dy + Picture->MaxExtentY());
		heading[0].AutoY = false;
	}
	  else {
	for (int i=1; i<4; i++) {
          if (! heading[i].Text.IsEmpty())
	    heading[i].y = heading[i-1].y - 1.3*heading[i-1].Font.Height;
	  else
	    break;
	  }
	}

      Picture->NewSegment("Heading");

      for (int i=0; i<4; i++) {
        if (! heading[i].Text.IsEmpty()) {
          heading[i].x = heading[0].x;
          double ytxt = heading[i].y - heading[i].Font.Height;
          Text = new MyText(heading[i].x, ytxt, heading[i].Font,
                 0.0, TEXT_LEFT, TEXT_BOTTOM, heading[i].Text, Picture);
          Text->TextOut();
          delete Text;
	  }
	else
	  break;
	}
      Picture->CloseSegment();
    }
}
//---------------------------------------------------------------------------

// plots diagram footer
void TTGDiagram::plot_footer(void)
{
  if (!footer.Text.IsEmpty())
    {
      if (footer.AutoX) {            // lower righthand corner of footer
        footer.x = Picture->MaxExtentX();
        footer.AutoX = false;
        }
      if (footer.AutoY) {            // bottom of footer
        footer.y = Picture->MinExtentY() - 1.3*footer.Font.Height - 0.3;
        footer.AutoY = false;
        }

      Picture->NewSegment("Footer");

      MyText *Text = new MyText(footer.x, footer.y, footer.Font, 0.0,
                        TEXT_RIGHT, TEXT_BASE, footer.Text, Picture);
      Text->TextOut();
      delete Text;

      Picture->CloseSegment();
    }
}
//---------------------------------------------------------------------------

// plots random text
void TTGDiagram::plot_atext(void)
{
  for (int i=0; i<RandomText->Count; i++) {
	UnicodeString Buffer = "Text " + IntToStr(i+1);
    Picture->NewSegment(Buffer);
    TEXTLINE *TextLine = (TEXTLINE*)RandomText->Items[i];
    MyText *Text = new MyText(TextLine->x, TextLine->y, TextLine->Font,
              TextLine->angle, TEXT_LEFT, TEXT_BASE, TextLine->Text, Picture);
    Text->TextOut();
    delete Text;
    Picture->CloseSegment();
    }
}
//---------------------------------------------------------------------------

