//---------------------------------------------------------------------------
#define VCL_IOSTREAM
#include <vcl.h>
#include "pch.h"
#pragma hdrstop

//#ifndef TGraphicH
//#include "TGraphic.h"
//#endif
#ifndef TGParentH
#include "TGParent.h"
#endif
#ifndef TGDiagrmH
#include "TGDiagrm.h"
#endif
#ifndef TGTextH
#include "TGText.h"
#endif
#ifndef TGUtilsH
#include "TGUtils.h"
#endif

//---------------------------------------------------------------------------
#pragma package(smart_init)

MYFONT::MYFONT()
{
  FontName = "Arial";
  Height = 0.35;
  Color = clBlack;
  Style.italic = 0;
  Style.bold = 0;
  Style.greek = 0;
  Style.subscript = 0;
  Style.superscript = 0;
  Style.underline = 0;
  Style.strikeout = 0;
  Style.charset = DEFAULT_CHARSET;
  StyleCompare = true;
}
//---------------------------------------------------------------------------

void MYFONT::XMLOUT(WriteXML* xmlout)
{
   UnicodeString ustr;
   xmlout->BeginTag("Font");
   xmlout->Element("FontName", FontName);
   xmlout->Element("FontHeight", Height);
   xmlout->Element("Color", ustr.sprintf(L"%08x", Color));
   xmlout->BeginTag("FontStyle");
   xmlout->Element("Italic", Style.italic);
   xmlout->Element("Bold", Style.bold);
   xmlout->Element("Greek", Style.greek);
   xmlout->Element("Subscript", Style.subscript);
   xmlout->Element("Superscript", Style.superscript);
   xmlout->Element("Underline", Style.underline);
   xmlout->Element("Strikeout", Style.strikeout);
   xmlout->Element("CharSet", (unsigned)Style.charset);
   xmlout->EndTag("FontStyle");
   xmlout->EndTag("Font");
}
//---------------------------------------------------------------------------

void MYFONT::ToggleSAXElement(UnicodeString& Element, TGXXML& tgx, bool toggle)
{
   if (Element == "FontName")
	 tgx.FontName = toggle;
   else if (Element == "FontHeight")
	 tgx.FontHeight = toggle;
   else if (Element == "Color")
	 tgx.Color = toggle;
   else if (Element == "FontStyle")
	 tgx.FontStyle = toggle;
   else if (tgx.FontStyle) {
	 if (Element == "Italic")
	   tgx.Italic = toggle;
	 else if (Element == "Bold")
	   tgx.Bold = toggle;
	 else if (Element == "Greek")
	   tgx.Greek = toggle;
	 else if (Element == "Subscript")
	   tgx.Subscript = toggle;
	 else if (Element == "Superscript")
	   tgx.Superscript = toggle;
	 else if (Element == "Underline")
	   tgx.Underline = toggle;
	 else if (Element == "Strikeout")
	   tgx.Strikeout = toggle;
	 else if (Element == "CharSet")
	   tgx.CharSet = toggle;
	 }
}
//---------------------------------------------------------------------------

void MYFONT::EvaluateXML(UnicodeString& ustr, TGXXML& tgx)
{
  if (tgx.FontName)
	FontName = ustr;
  else if (tgx.FontHeight) {
	try {
	   Height = IntlStrToDouble::GetDouble(ustr); }
	catch (...) {
	   UnicodeString Message = "Cannot read floating point value: " + ustr;
	   MessageDlg(Message, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   exit(0);
	   }
	}
  else if (tgx.Color) {
	UnicodeString Hex = "0x" + ustr;
	Color = (TColor)Hex.ToInt();
	}
  else if (tgx.FontStyle) {
	if (tgx.Italic)
	  Style.italic = (bool)ustr.ToInt();
	else if (tgx.Bold)
	  Style.bold = (bool)ustr.ToInt();
	else if (tgx.Greek)
	  Style.greek = (bool)ustr.ToInt();
	else if (tgx.Subscript)
	  Style.subscript = (bool)ustr.ToInt();
	else if (tgx.Superscript)
	  Style.superscript = (bool)ustr.ToInt();
	else if (tgx.Underline)
	  Style.underline = (bool)ustr.ToInt();
	else if (tgx.Strikeout)
	  Style.strikeout = (bool)ustr.ToInt();
	else if (tgx.CharSet)
	  Style.charset = (TFontCharset)ustr.ToInt();
	}
}
//---------------------------------------------------------------------------

void MYFONT::operator = (const MYFONT& copy)
{
   if (this == &copy) return;

   if (copy.FontName.Length() > 0)
	 FontName = copy.FontName;
   if (copy.Height > -1.0)
     Height = copy.Height;
   if (copy.Color > -1)
     Color = copy.Color;
   if (copy.StyleCompare) {
     Style.italic = copy.Style.italic;
     Style.bold = copy.Style.bold;
     Style.greek = copy.Style.greek;
     Style.subscript = copy.Style.subscript;
     Style.superscript = copy.Style.superscript;
     Style.underline = copy.Style.underline;
     Style.strikeout = copy.Style.strikeout;
     Style.charset = copy.Style.charset;
     }
}
//---------------------------------------------------------------------------

bool MYFONT::operator != (const MYFONT& compare )
{
   // return true if any of the variables are not equal
   if (this == &compare) return false;

   if (FontName != compare.FontName) return true;
   if (Height != compare.Height) return true;
   if (Color != compare.Color) return true;
   if (Style.italic != compare.Style.italic) return true;
   if (Style.bold != compare.Style.bold) return true;
   if (Style.greek != compare.Style.greek) return true;
   if (Style.subscript != compare.Style.subscript) return true;
   if (Style.superscript != compare.Style.superscript) return true;
   if (Style.underline != compare.Style.underline) return true;
   if (Style.strikeout != compare.Style.strikeout) return true;
   if (Style.charset != compare.Style.charset) return true;
   return false;
}
//---------------------------------------------------------------------------

bool MYFONT::operator == (const MYFONT& compare )
{
   // return false if any of the variables are not equal
   if (this == &compare) return true;

   if (FontName != compare.FontName) return false;
   if (Height != compare.Height) return false;
   if (Color != compare.Color) return false;
   if (Style.italic != compare.Style.italic) return false;
   if (Style.bold != compare.Style.bold) return false;
   if (Style.greek != compare.Style.greek) return false;
   if (Style.subscript != compare.Style.subscript) return false;
   if (Style.superscript != compare.Style.superscript) return false;
   if (Style.underline != compare.Style.underline) return false;
   if (Style.strikeout != compare.Style.strikeout) return false;
   if (Style.charset != compare.Style.charset) return false;
   return true;
}
//---------------------------------------------------------------------------

void MYFONT::Compare(const MYFONT& compare)
{
   if (FontName != compare.FontName) FontName.SetLength(0);
   if (Height != compare.Height) Height = -1.0;
   if (Color != compare.Color) Color = (TColor)-1;
   if (Style.italic != compare.Style.italic) StyleCompare = false;
   if (Style.bold != compare.Style.bold) StyleCompare = false;
}
//---------------------------------------------------------------------------

TextObject::TextObject(double X, double Y, double ang, UINT Horz, UINT Vert,
                       int bkco, MYFONT &F, UnicodeString txt)
{
  x = X;
  y = Y;
  angle = ang;
  HorzTextAlign = Horz;
  VertTextAlign = Vert;
  bkcolor = bkco;
  Font = F;
  Text = txt;
}
//---------------------------------------------------------------------------

MyText::MyText(double X, double Y, MYFONT& F, double a, UINT horz, UINT vert,
               UnicodeString text, MyGraphics *pic)
{
  x = X + pic->getXOffset();
  y = Y + pic->getYOffset();
  angle = a;
  SetAlignment(horz, vert);
  bkcolor = pic->BackgroundColor;
  Text = text;
  Picture = pic;
  Font = F;
  ssheight = Font.Height*2.0/3.0;
}
//---------------------------------------------------------------------------

MyText::MyText(MYFONT& F, UnicodeString text, MyGraphics *pic)
{
  x = 0.0;
  y = 0.0;
  angle = 0.0;
  SetAlignment(TEXT_LEFT, TEXT_BASE);
  bkcolor = pic->BackgroundColor;
  Text = text;
  Picture = pic;
  Font = F;
  ssheight = Font.Height*2.0/3.0;
}
//---------------------------------------------------------------------------

/*
MyText::MyText(TextObject *tp, MyGraphics *pic)
{
  x = tp->x;
  y = tp->y;
  angle = tp->angle;
  HorzTextAlign = tp->HorzTextAlign;
  VertTextAlign = tp->VertTextAlign;
  bkcolor = tp->bkcolor;
  Font = tp->Font;
  Text = tp->Text;
  ssheight = Font.Height*2.0/3.0;
  Picture = pic;
}
//---------------------------------------------------------------------------
*/

MyText::MyText(TextObject& tp, MyGraphics *pic)
{
  x = tp.x;
  y = tp.y;
  angle = tp.angle;
  HorzTextAlign = tp.HorzTextAlign;
  VertTextAlign = tp.VertTextAlign;
  bkcolor = tp.bkcolor;
  Font = tp.Font;
  Text = tp.Text;
  ssheight = Font.Height*2.0/3.0;
  Picture = pic;
}
//---------------------------------------------------------------------------

void MyText::Toggle(char style)
{
  switch (style) {
    case 'i':
      Font.Style.italic = (Font.Style.italic) ? false : true;
      break;
    case 'b':
      Font.Style.bold = (Font.Style.bold) ? false : true;
      break;
    case '^':
      Font.Style.superscript = (Font.Style.superscript) ? false : true;
      break;
    case 'v':
      Font.Style.subscript = (Font.Style.subscript) ? false : true;
      break;
    case 'g':
      Font.Style.greek = (Font.Style.greek) ? false : true;
      break;
    }
}
//---------------------------------------------------------------------------

void MyText::Toggle(UnicodeString& style)
{
  if (style == "i")
	Font.Style.italic = true;
  else if (style == "/i")
	Font.Style.italic = false;
  else if (style == "b")
	Font.Style.bold = true;
  else if (style == "/b")
	Font.Style.bold = false;
  else if (style == "sup")
	Font.Style.superscript = true;
  else if (style == "/sup")
	Font.Style.superscript = false;
  else if (style == "sub")
	Font.Style.subscript = true;
  else if (style == "/sub")
	Font.Style.subscript = false;
  else if (style == "g")
	Font.Style.greek = true;
  else if (style == "/g")
    Font.Style.greek = false;
}
//---------------------------------------------------------------------------

void MyText::SetAlignment(UINT horz_align, UINT vert_align)
{
   switch (horz_align) {
     case TEXT_RIGHT:
       HorzTextAlign = TA_RIGHT;
       break;
     case TEXT_LEFT:
       HorzTextAlign = TA_LEFT;
       break;
     case TEXT_CENTER:
       HorzTextAlign = TA_CENTER;
       break;
     }

   switch (vert_align) {
     case TEXT_BOTTOM:
       TextVertOffset = 0.0;
       VertTextAlign = TA_BOTTOM;
       break;
     case TEXT_BASE:
       TextVertOffset = 0.0;
       VertTextAlign = TA_BASELINE;
       break;
     case TEXT_HALF:
       TextVertOffset = -0.35;
       VertTextAlign = TA_BASELINE;
       break;
     case TEXT_TOP:
     case TEXT_CAP:
       TextVertOffset = 0.0;
       VertTextAlign = TA_TOP;
	   break;
	 }
}
//---------------------------------------------------------------------------

void MyText::TranslateGreek(UnicodeString& Text)
{
   if (!Text.Pos("<g>")) return;   // no Greek characters

   TransGreekChar(Text, "<g>ALPHA</g>",   L"\x0391");
   TransGreekChar(Text, "<g>BETA</g>",    L"\x0392");
   TransGreekChar(Text, "<g>GAMMA</g>",   L"\x0393");
   TransGreekChar(Text, "<g>DELTA</g>",   L"\x0394");
   TransGreekChar(Text, "<g>EPSILON</g>", L"\x0395");
   TransGreekChar(Text, "<g>ZETA</g>",    L"\x0396");
   TransGreekChar(Text, "<g>ETA</g>",     L"\x0397");
   TransGreekChar(Text, "<g>THETA</g>",   L"\x0398");
   TransGreekChar(Text, "<g>IOTA</g>",    L"\x0399");
   TransGreekChar(Text, "<g>KAPPA</g>",   L"\x039A");
   TransGreekChar(Text, "<g>LAMBDA</g>",  L"\x039B");
   TransGreekChar(Text, "<g>MU</g>",      L"\x039C");
   TransGreekChar(Text, "<g>NU</g>",      L"\x039D");
   TransGreekChar(Text, "<g>XI</g>",      L"\x039E");
   TransGreekChar(Text, "<g>OMICRON</g>", L"\x039F");
   TransGreekChar(Text, "<g>PI</g>",      L"\x03A0");
   TransGreekChar(Text, "<g>RHO</g>",     L"\x03A1");
   TransGreekChar(Text, "<g>SIGMA</g>",   L"\x03A3");
   TransGreekChar(Text, "<g>TAU</g>",     L"\x03A4");
   TransGreekChar(Text, "<g>UPSILON</g>", L"\x03A5");
   TransGreekChar(Text, "<g>PHI</g>",     L"\x03A6");
   TransGreekChar(Text, "<g>CHI</g>",     L"\x03A7");
   TransGreekChar(Text, "<g>PSI</g>",     L"\x03A8");
   TransGreekChar(Text, "<g>OMEGA</g>",   L"\x03A9");
   TransGreekChar(Text, "<g>alpha</g>",   L"\x03B1");
   TransGreekChar(Text, "<g>beta</g>",    L"\x03B2");
   TransGreekChar(Text, "<g>gamma</g>",   L"\x03B3");
   TransGreekChar(Text, "<g>delta</g>",   L"\x03B4");
   TransGreekChar(Text, "<g>epsilon</g>", L"\x03B5");
   TransGreekChar(Text, "<g>zeta</g>",    L"\x03B6");
   TransGreekChar(Text, "<g>eta</g>",     L"\x03B7");
   TransGreekChar(Text, "<g>theta</g>",   L"\x03B8");
   TransGreekChar(Text, "<g>iota</g>",    L"\x03B9");
   TransGreekChar(Text, "<g>kappa</g>",   L"\x03BA");
   TransGreekChar(Text, "<g>lambda</g>",  L"\x03BB");
   TransGreekChar(Text, "<g>mu</g>",      L"\x03BC");
   TransGreekChar(Text, "<g>nu</g>",      L"\x03BD");
   TransGreekChar(Text, "<g>xi</g>",      L"\x03BE");
   TransGreekChar(Text, "<g>omicron</g>", L"\x03BF");
   TransGreekChar(Text, "<g>pi</g>",      L"\x03C0");
   TransGreekChar(Text, "<g>rho</g>",     L"\x03C1");
   TransGreekChar(Text, "<g>sigma</g>",   L"\x03C3");
   TransGreekChar(Text, "<g>tau</g>",     L"\x03C4");
   TransGreekChar(Text, "<g>upsilon</g>", L"\x03C5");
   TransGreekChar(Text, "<g>phi</g>",     L"\x03C6");
   TransGreekChar(Text, "<g>chi</g>",     L"\x03C7");
   TransGreekChar(Text, "<g>psi</g>",     L"\x03C8");
   TransGreekChar(Text, "<g>omega</g>",   L"\x03C9");
}
//---------------------------------------------------------------------------

void MyText::TransGreekChar(UnicodeString& Text, UnicodeString Name, UnicodeString Code)
{
   int pos;
   do {
        if ((pos = Text.Pos(Name)) > 0) {
           Text.Delete(pos, Name.Length());
           Text.Insert(Code, pos); }
      } while (pos > 0);
}
//---------------------------------------------------------------------------

void MyText::TextOut(void)
{
  double l;
  //DblPoint* textbox[4];
  DblPoint origin(0.0, 0.0);
  vector<DblPoint> textbox(4, origin);
  FONTSTYLE SaveStyle;

  SaveStyle = Font.Style;

  UnicodeString Text1 = Text.TrimRight();  // trim leading and trailing spaces
  TranslateGreek(Text1);

  int pos = Text1.Pos("<");
  if (pos == 0) {
    SetTextAlign(Picture->Canvas()->Handle, HorzTextAlign | VertTextAlign);
    TextOut1(x, y, Text1);
    }
  else {
	//for (int i=0; i<4; i++)
	//  textbox[i] = new DblPoint(0, 0);

    double r = angle*pi()/180.0;
    double len = Length();
    switch (HorzTextAlign) {
      case TA_CENTER:
        x -= 0.5*cos(r)*len;
        y -= 0.5*sin(r)*len;
        break;
      case TA_RIGHT:
        x -= cos(r)*len;
        y -= sin(r)*len;
        break;
      }

    switch (VertTextAlign) {
      case TA_BASELINE:
        l = -(0.25-TextVertOffset)*Font.Height;
        break;
      case TA_TOP:
        l = -Font.Height;
        break;
      default:
        l = 0;
        break;
      }

    y += l*cos(r);
    x += -l*sin(r);
    HorzTextAlign = TA_LEFT;
    VertTextAlign = TA_BOTTOM;
	GetTextBox(x, y, textbox, Text1);
	TextVertOffset = 0.0;
	SetTextAlign(Picture->Canvas()->Handle, HorzTextAlign | VertTextAlign);
	TextOut1(textbox[0].x, textbox[0].y, Text1);
	//for (int i=0; i<4; i++) delete textbox[i];
    }
  Font.Style = SaveStyle;
}
//---------------------------------------------------------------------------

void MyText::TextOut1(double x1, double y1, UnicodeString Text1)
{
  int poslt, posgt;
  UnicodeString style;
  double xnext, ynext;

  poslt = Text1.Pos("<");

  if (poslt == 0) {      // no style in string
    if (! Text1.IsEmpty())
      TextOut2(x1, y1, Text1, &xnext, &ynext);
    }
  else if (poslt == 1) {  // style in first character
    posgt = Text1.Pos(">");
    style = Text1.SubString(2, posgt-2);
    Toggle(style);
	UnicodeString Text2 = Text1.SubString(posgt+1, Text1.Length()-2);
    TextOut1(x1, y1, Text2);
    }
  else {          // style later in string
	UnicodeString Text2 = Text1;
    Text2.SetLength(poslt-1);
    TextOut2(x1, y1, Text2, &xnext, &ynext);
    UnicodeString Text3 = Text1.SubString(poslt, Text1.Length()-poslt+1);
    TextOut1(xnext, ynext, Text3);
    }
}
//---------------------------------------------------------------------------

void MyText::TextOut2(double x2, double y2, UnicodeString Text2, double *xnext,
                      double *ynext)
{
  double xmin, xmax, ymin, ymax;
  double hite;
  MYFONT LocalFont;
  //DblPoint* textbox[4];
  DblPoint origin(0.0, 0.0);
  vector<DblPoint> textbox(4, origin);
  const double upfac = 0.5;
  const double downfac = 0.10;

  ConvertEntityReferences(Text2);

  double l = TextVertOffset;
  if (Font.Style.superscript) {
    l += upfac;
    hite = ssheight;
    }
  else if (Font.Style.subscript) {
    l -= downfac;
    hite = ssheight;
    }
  else
    hite = Font.Height;

  l *= Font.Height;
  SetFont();
  double r = angle*pi()/180.0;
  y2 += l*cos(r);
  x2 += -l*sin(r);

  // x2 and y2 are in diagram (world) units
  LocalFont = Font;
  LocalFont.Height = hite;
  //Picture->TextStrings->Add(new TextObject(x2, y2, angle, HorzTextAlign,
  //                          VertTextAlign, bkcolor, LocalFont, Text2));
  Picture->TextStrings.push_back(TextObject(x2, y2, angle, HorzTextAlign,
		   VertTextAlign, bkcolor, LocalFont, Text2));

  // problem here??
  //for (int i=0; i<4; i++)
  //	textbox[i] = new DblPoint(0, 0);

  // put entity reference for "<" sign back in so GetTextBox will work
  int pos = Text2.Pos("<");
  while (pos > 0) {
    Text2.Delete(pos, 1);
    Text2.Insert("&lt;", pos);
    pos = Text2.Pos("<");
    }
  GetTextBox(x2, y2, textbox, Text2);

  xmin = xmax = textbox[0].x;
  ymin = ymax = textbox[0].y;

  for (int i=1; i<=3; i++) {
	if (textbox[i].x < xmin) xmin = textbox[i].x;
	if (textbox[i].x > xmax) xmax = textbox[i].x;
	if (textbox[i].y < ymin) ymin = textbox[i].y;
	if (textbox[i].y > ymax) ymax = textbox[i].y;
    }

  Picture->Extent(xmin, ymin);
  Picture->Extent(xmax, ymax);

  if (Font.Style.superscript) {
    y2 -= Font.Height*upfac*cos(r);
    x2 -= -Font.Height*upfac*sin(r);
    GetTextBox(x2, y2, textbox, Text2);
    }
  else if (Font.Style.subscript) {
    y2 -= -Font.Height*downfac*cos(r);
    x2 -= Font.Height*downfac*sin(r);
    GetTextBox(x2, y2, textbox, Text2);
    }
  *xnext = textbox[1].x;
  *ynext = textbox[1].y;

  //for (int i=0; i<4; i++) delete textbox[i];
}
//---------------------------------------------------------------------------

void MyText::ConvertEntityReferences(UnicodeString& Text)
{
  int pos = Text.Pos("&");
  if (pos == 0) return;

  pos = Text.Pos("&amp;");
  while (pos > 0) {
    Text.Delete(pos, 5);
    Text.Insert("&", pos);
	pos = Text.Pos("&amp;");
    }
  pos = Text.Pos("&lt;");
  while (pos > 0) {
    Text.Delete(pos, 4);
    Text.Insert("<", pos);
	pos = Text.Pos("&lt;");
    }
  pos = Text.Pos("&gt;");
  while (pos > 0) {
    Text.Delete(pos, 4);
    Text.Insert(">", pos);
    pos = Text.Pos("&gt;");
    }
}
//---------------------------------------------------------------------------

void MyText::DisplayText(int ClientHeight, double fac, double xoffset, double yoffset)
{
  SetTextAlign(Picture->Canvas()->Handle, HorzTextAlign | VertTextAlign);
  int HitePixels = -nint(fac*Font.Height);
  Picture->Canvas()->Font->Height = HitePixels;
  Picture->Canvas()->Brush->Style = bsClear;
  Picture->Canvas()->Font->Color = TColor(Font.Color);

  SetFont();
  Picture->Canvas()->TextOut(nint((x - xoffset)*fac),
            nint((double)ClientHeight - (y - yoffset)*fac), Text);
}
//---------------------------------------------------------------------------

void MyText::MaxXY(double *xmax, double *ymax)
{
  //DblPoint* textbox[4];
  DblPoint origin(0.0, 0.0);
  vector<DblPoint> textbox(4, origin);

  //for (int i=0; i<4; i++) textbox[i] = new DblPoint(0, 0);
  GetTextBox(x, y, textbox, Text);
  *xmax = textbox[0].x;
  *ymax = textbox[0].y;
  for (int i=1; i<4; i++) {
	if (textbox[i].x > *xmax) *xmax = textbox[i].x;
	if (textbox[i].y > *ymax) *ymax = textbox[i].y;
	}
  //for (int i=0; i<4; i++) delete textbox[i];
}

// Returns coordinates of the text box rotated to fontangle
//
//       3----------2
//       |Text Sring|
//       0----------1
//
//void MyText::GetTextBox(double x, double y, DblPoint **textbox, UnicodeString text)
void MyText::GetTextBox(double x, double y, vector<DblPoint>& textbox, UnicodeString text)
{
  double xmin, xmax, ymin, ymax;
  //DblPoint *p1, *p2, *p3;
  DblPoint p1, p2, p3;

  double len = Length1(text, false);

  // form text box with no rotation
  switch (HorzTextAlign)
   {
   case TA_LEFT:
      xmin = x;
      xmax = x+len;
      break;
   case TA_RIGHT:
      xmin = x-len;
      xmax = x;
      break;
   case TA_CENTER:
      xmin = x-0.5*len;
      xmax = x+0.5*len;
      break;
   }

  switch (VertTextAlign)
   {
   case TA_BOTTOM:
      ymin = y;
      ymax = y + 1.15*Font.Height;
      break;
   case TA_BASELINE:
      ymin = y - 0.3*Font.Height;
      ymax = y + 0.85*Font.Height;
      break;
   case TA_TOP:
      ymin = y - 1.15*Font.Height;
      ymax = y;
      break;
   }

  // rotate text box and get extents
  //p1 = p2 = p3 = NULL;
  DblRect TextRect(xmin, xmax, ymin, ymax);

  switch (HorzTextAlign)
   {
   case TA_LEFT:
	 p1.SetPoints(TextRect.xmin, TextRect.ymin);
	 p2.SetPoints(TextRect.xmax, TextRect.ymin);
	 p3.SetPoints(0.0, 0.0);

	 textbox[0].SetPoints(p1.x, p1.y);

	 RotatePoint(angle, p1, p2, p3);
	 textbox[1].SetPoints(p3.x, p3.y);

	 p2.SetPoints(TextRect.xmax, TextRect.ymax);
	 RotatePoint(angle, p1, p2, p3);
	 textbox[2].SetPoints(p3.x, p3.y);

	 p2.SetPoints(TextRect.xmin, TextRect.ymax);
	 RotatePoint(angle, p1, p2, p3);
     textbox[3].SetPoints(p3.x, p3.y);

     break;
   case TA_RIGHT:
	 p1.SetPoints(TextRect.xmax, TextRect.ymin);
	 p2.SetPoints(TextRect.xmin, TextRect.ymin);
	 p3.SetPoints(0.0, 0.0);

	 textbox[0].SetPoints(p1.x, p1.y);

	 RotatePoint(angle, p1, p2, p3);
	 textbox[1].SetPoints(p3.x, p3.y);

	 p2.SetPoints(TextRect.xmin, TextRect.ymax);
	 RotatePoint(angle, p1, p2, p3);
	 textbox[3].SetPoints(p3.x, p3.y);

	 p2.SetPoints(TextRect.xmax, TextRect.ymax);
	 RotatePoint(angle, p1, p2, p3);
	 textbox[2].SetPoints(p3.x, p3.y);
	 break;
   case TA_CENTER:
	 p1.SetPoints(x, TextRect.ymin);
	 p2.SetPoints(TextRect.xmax, TextRect.ymin);
	 p3.SetPoints(0.0, 0.0);

	 RotatePoint(angle, p1, p2, p3);
	 textbox[1].SetPoints(p3.x, p3.y);

	 p2.SetPoints(TextRect.xmax, TextRect.ymax);
	 RotatePoint(angle, p1, p2, p3);
	 textbox[2].SetPoints(p3.x, p3.y);

	 p2.SetPoints(TextRect.xmin, TextRect.ymax);
	 RotatePoint(angle, p1, p2, p3);
	 textbox[3].SetPoints(p3.x, p3.y);

	 p2.SetPoints(TextRect.xmin, TextRect.ymin);
	 RotatePoint(angle, p1, p2, p3);
	 textbox[0].SetPoints(p3.x, p3.y);
	 break;
   }

  //if (p1 != NULL) delete p1;
  //if (p2 != NULL) delete p2;
  //if (p3 != NULL) delete p3;
}
//---------------------------------------------------------------------------

// rotate point (x2, y2) around (x1, y1)
void MyText::RotatePoint(double alpha, DblPoint& p1, DblPoint& p2, DblPoint& p3)
{
  double r, theta, beta;

  alpha *= (pi()/180.0);
  r = sqrt((p2.x - p1.x)*(p2.x - p1.x) + (p2.y - p1.y)*(p2.y - p1.y));
  if (r == 0) {
	p3.x = p1.x;
	p3.y = p1.y;
	return;
	}

  theta = asin((p2.y - p1.y)/r);

  if (p1.x <= p2.x) {
	beta = alpha + theta;
	p3.x = p1.x + r*cos(beta);
	p3.y = p1.y + r*sin(beta);
	}
  else {
	beta = alpha - theta;
	p3.x = p1.x - r*cos(beta);
	p3.y = p1.y - r*sin(beta);
    }
}
//---------------------------------------------------------------------------

bool MyText::FontCmp(LOGFONT &lf1, LOGFONT &lf2)
{
  if (lf1.lfHeight != lf2.lfHeight) return false;
  if (lf1.lfEscapement != lf2.lfEscapement) return false;
  if (lf1.lfOrientation != lf2.lfOrientation) return false;
  if (lf1.lfItalic != lf2.lfItalic) return false;
  if (lf1.lfWeight != lf2.lfWeight) return false;
  if (lf1.lfUnderline != lf2.lfUnderline) return false;
  if (lf1.lfStrikeOut != lf2.lfStrikeOut) return false;
  if (lf1.lfCharSet != lf2.lfCharSet) return false;
  if (lf1.lfOutPrecision != lf2.lfOutPrecision) return false;
  //if (AnsiCompareStr(lf1.lfFaceName, lf2.lfFaceName) != 0) return false;
  //if (Sysutils::SameText(lf1.lfFaceName, lf2.lfFaceName) != 0) return false;
  if (!Sysutils::SameText(lf1.lfFaceName, lf2.lfFaceName)) return false;
  return true;
}
//---------------------------------------------------------------------------

void MyText::SetFont(void)
{
  int i;
  bool FontFound;
  HFONT hFont, hFont1;
  LOGFONT lf, lf1;

  hFont = Picture->Canvas()->Font->Handle;
  GetObject(hFont, sizeof(LOGFONT), &lf);

  lf.lfEscapement = 10.0*angle;
  lf.lfOrientation = 10.0*angle;
  lf.lfItalic = (Font.Style.italic) ? true : false;
  lf.lfWeight = (Font.Style.bold) ? FW_BOLD : FW_NORMAL;
  lf.lfUnderline = (Font.Style.underline) ? true : false;
  lf.lfStrikeOut = (Font.Style.strikeout) ? true : false;
  lf.lfCharSet = (Font.Style.greek) ? (BYTE)GREEK_CHARSET : Font.Style.charset;
  lf.lfOutPrecision = (BYTE)OUT_TT_PRECIS;
  //strcpy(lf.lfFaceName, Font.Name.c_str());
  WideString WideFontName = Font.FontName;
  wcscpy(lf.lfFaceName, WideFontName.c_bstr());

  // store old font if it does not already exist
  //if (ParentForm->FontList->Count == 0)
  //  ParentForm->FontList->Add(hFont);
  if (ParentForm->FontList.size() == 0)
	ParentForm->FontList.push_back(hFont);

  FontFound = false;
  for (unsigned int i=0; i<ParentForm->FontList.size(); i++) {
	hFont1 = ParentForm->FontList[i];
	GetObject(hFont1, sizeof(LOGFONT), &lf1);
	if (FontCmp(lf, lf1)) {
	  FontFound = true;
	  break;
	  }
	}

  if (FontFound) {
	SelectObject(Picture->Canvas()->Handle, hFont1);
	return;
	}
  else {
	hFont = CreateFontIndirect(&lf);
	SelectObject(Picture->Canvas()->Handle, hFont);
	ParentForm->FontList.push_back(hFont);
    }
}
//---------------------------------------------------------------------------

double MyText::Length(void)
{
  return (Length1(Text, false));
}
//---------------------------------------------------------------------------

double MyText::TestLength(void)
{
  return (Length1(Text, true));
}
//---------------------------------------------------------------------------

double MyText::Length1(UnicodeString Text1, bool test)
{
  int poslt, posgt;
  UnicodeString style;
  double len = 0.0;
  FONTSTYLE SaveStyle;

  SaveStyle = Font.Style;

  TranslateGreek(Text1);
  double hite = (Font.Style.superscript || Font.Style.subscript) ? ssheight : Font.Height;

  int ppi = Picture->Canvas()->Font->PixelsPerInch;
  int HitePixels = (ppi < 100) ? 100 : ppi;  // minimum of 100 pixels
  Picture->Canvas()->Font->Height = -HitePixels;

  poslt = Text1.Pos("<");
  if (poslt == 0) {      // no style in string
	if (!Text1.IsEmpty()) {        // TextWidth is in pixels
	  SetFont();
      ConvertEntityReferences(Text1);
      len += hite*(double)Picture->Canvas()->TextWidth(Text1)/(double)HitePixels;
	  }
    }
  else if (poslt == 1) {  // style in first character
    posgt = Text1.Pos(">");
    style = Text1.SubString(2, posgt-2);
    Toggle(style);
	UnicodeString Text2 = Text1.SubString(posgt+1, Text1.Length()-2);
    SetFont();
    len += Length1(Text2, false);
    }
  else {          // style later in string
	UnicodeString Text2 = Text1;
    Text2.SetLength(poslt-1);
    SetFont();
    ConvertEntityReferences(Text2);
    len += hite*(double)Picture->Canvas()->TextWidth(Text2)/(double)HitePixels;
	UnicodeString Text3 = Text1.SubString(poslt, Text1.Length()-poslt+1);
    len += Length1(Text3, false);
    }
  Font.Style = SaveStyle;
  return len;
}
//---------------------------------------------------------------------------
