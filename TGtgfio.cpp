//---------------------------------------------------------------------------
#include <FileCtrl.hpp>
#include <vcl.h>
#include "pch.h"
#include <map>
#pragma hdrstop

#ifndef TGParentH
#include "TGParent.h"
#endif
#ifndef TIGlobalsH
#include "TIGlobals.h"
#endif
#ifndef TGDiagrmH
#include "TGDiagrm.h"
#endif
#include "Tgtgfioc.h"  // const vars
#ifndef TgtgfioH
#include "Tgtgfio.h"
#endif
#ifndef TGDOS
#include "TGDOS.h"
#endif
#ifndef TGYaxisH
#include "TGYaxis.h"
#endif
#ifndef TGUtilsH
#include "TGUtils.h"
#endif
#ifndef TIPubH
#include "TIPub.h"
#endif
#ifndef TINewAnlH
#include "TINewAnl.h"
#endif
#ifndef TGUtilsH
#include "TGUtils.h"
#endif

//---------------------------------------------------------------------------
#pragma package(smart_init)

void ReadDOSFile::SpecialVarCodes(UnicodeString& VarCode)
{
  UnicodeString Code = VarCode.SubString(1, 5);
  if (Code.CompareIC("chron") == 0) {
	VarCode.Delete(1,5);
	VarCode.Insert("#Chron", 1);
	}
  else if (Code.CompareIC("depth") == 0) {
	VarCode.Delete(1,5);
	VarCode.Insert("#Depth", 1);
	}
  else if (Code.CompareIC("thick") == 0) {
	VarCode.Delete(1,5);
	VarCode.Insert("#Thick", 1);
	}
  else if (Code.CompareIC("error") == 0) {
	VarCode.Delete(1,5);
	VarCode.Insert("#Error", 1);
	}
  //else if (VarCode.c_str()[0] == '\xD3') {
  else if (Code.CompareIC("Ó") == 0) {
	VarCode.Delete(1,1);
	}
}
//---------------------------------------------------------------------------

TColor ReadDOSFile::DOSColorToRGB(COLOR *d_color, Byte color_index)
{
  Byte red, green, blue;
  TColor color;

  if (color_index == 255)
    color = clWhite;
  else
    {
      red = (Byte)nint(255.0 * d_color[color_index].red);
      green = (Byte)nint(255.0 * d_color[color_index].green);
      blue = (Byte)nint(255.0 * d_color[color_index].blue);
      color = (TColor)RGB(red, green, blue);
    }
  return color;
}
//---------------------------------------------------------------------------

short ReadDOSFile::getshort(char buffer[])
{
  union {
    short i;
    char buff[2];
    } ushort;

  ushort.buff[0] = buffer[0];
  ushort.buff[1] = buffer[1];
  return ushort.i;
}
//---------------------------------------------------------------------------

unsigned short ReadDOSFile::getushort(char buffer[])
{
  union {
    unsigned short u;
    char buff[2];
    } ushort;

  ushort.buff[0] = buffer[0];
  ushort.buff[1] = buffer[1];
  return ushort.u;
}
//---------------------------------------------------------------------------

double ReadDOSFile::getdouble(char buffer[])
{
  union {
    double x;
    char buff[8];
    } udouble;

  for (int i=0; i<8; i++)
    udouble.buff[i] = buffer[i];
  return udouble.x;
}
//---------------------------------------------------------------------------

double ReadDOSFile::getdoubleNan(char buffer[])
{
  union {
    double x;
    char buff[8];
    } udouble;

  bool zero = true;
  for (int i=0; i<8; i++) {
    if (buffer[i] != '\0')
      zero = false;
    udouble.buff[i] = buffer[i];
    }

  if (zero)
    return NaN;
  else
    return udouble.x;
}
//---------------------------------------------------------------------------

double ReadDOSFile::getfloat(char buffer[])
{
  // gets a float and returns as a double
  union {
    float x;
    char buff[4];
    } ufloat;

  for (int i=0; i<4; i++)
    ufloat.buff[i] = buffer[i];

  UnicodeString buff = FloatToStrF(ufloat.x, ffExponent, 7, 3);
  double xx = IntlStrToDouble::GetDouble(buff);

  return xx;
}
//---------------------------------------------------------------------------

// translantes from OEM text to Windows text
UnicodeString ReadDOSFile::getUnicodeString1(UnicodeString &dest, char src[])
{
  bool Sigma = (src[0] == '\xE4') ? true : false;   // upper case sigma
  int n = strlen(src);
  wchar_t *WinText = new wchar_t [n+1];
  WinText[n] = L'\0';
  OemToCharBuff(src, WinText, n);
  WideString temp = WinText;
  temp = temp.TrimRight();
  delete[] WinText;
  if (Sigma) {
	temp.Delete(1,1);
	temp.Insert(L"SUM(", 1);
	temp += L")";
	}
  ConvertToggles(temp);
  dest = UnicodeString(temp);
  return dest;
}
//---------------------------------------------------------------------------

// this version translates extended ASCII Greek characters
UnicodeString ReadDOSFile::getUnicodeString2(UnicodeString &dest, char src[])
{
  //dest.SetLength(0);
  WideString temp;

  wchar_t WinText[2];
  WinText[1] = L'\0';
  int n = strlen(src);

  for (int i=0; i<n; i++) {
	switch ((unsigned char)src[i])
	  {
	  case 0xE4:   // upper case sigma
		temp += L"<g>SIGMA</g>";
		break;
	  case 0xE5:   // lower case sigma
		temp += L"<g>sigma</g>";
		break;
	  case 0xE6:   // lower case mu
		temp += L"<g>mu</g>";
		break;
	  case 0xEB:   // lower case delta
		temp += L"<g>delta</g>";
		break;
	  default:
		OemToCharBuff(&src[i], WinText, 1);
		temp += WinText;
		break;
	  }
	}
  ConvertToggles(temp);
  dest = UnicodeString(temp);
  return dest;
}
//---------------------------------------------------------------------------

void ReadDOSFile::ConvertToggles(WideString& Text)
{
  CheckEntityRefs(Text);

  int pos1 = Text.Pos("\\");
  if (pos1 > 0) {
	int pos2 = Text.Pos("\\i");
	while (pos2 > 0) {
	  Text.Delete(pos2, 2);
	  Text.Insert("<i>", pos2);
	  int pos3 = Text.Pos("\\i");
	  if (pos3 > 0) {
		Text.Delete(pos3, 2);
		Text.Insert("</i>", pos3);
		}
	  pos2 = Text.Pos("\\i");
	  }

	pos2 = Text.Pos("\\b");
	while (pos2 > 0) {
	  Text.Delete(pos2, 2);
	  Text.Insert("<b>", pos2);
	  int pos3 = Text.Pos("\\b");
	  if (pos3 > 0) {
		Text.Delete(pos3, 2);
		Text.Insert("</b>", pos3);
		}
	  pos2 = Text.Pos("\\b");
	  }

	pos2 = Text.Pos("\\v");
	while (pos2 > 0) {
	  Text.Delete(pos2, 2);
	  Text.Insert("<sub>", pos2);
	  int pos3 = Text.Pos("\\v");
	  if (pos3 > 0) {
		Text.Delete(pos3, 2);
		Text.Insert("</sub>", pos3);
		}
	  pos2 = Text.Pos("\\v");
	  }

	pos2 = Text.Pos("\\^");
	while (pos2 > 0) {
	  Text.Delete(pos2, 2);
	  Text.Insert("<sup>", pos2);
	  int pos3 = Text.Pos("\\^");
	  if (pos3 > 0) {
		Text.Delete(pos3, 2);
		Text.Insert("</sup>", pos3);
		}
      pos2 = Text.Pos("\\^");
      }
    }
}
//---------------------------------------------------------------------------

ReadTGF::ReadTGF(UnicodeString& FileName, TTGDiagram *diag)
{
  TGFileName = FileName;
  InputFileOpen = false;

  DefaultFont.FontName = "Arial";
  DefaultFont.Height = 0.0;
  DefaultFont.Color = clBlack;
  DefaultFont.Style.italic = false;
  DefaultFont.Style.bold = false;
  DefaultFont.Style.greek = false;
  DefaultFont.Style.subscript = false;
  DefaultFont.Style.superscript = false;
  DefaultFont.Style.underline = false;
  DefaultFont.Style.strikeout = false;
  DefaultFont.Style.charset = DEFAULT_CHARSET;

  d = diag;

  Vars = new TList;
  Vars->Capacity = 1000;

  vdx = NULL;
}
//---------------------------------------------------------------------------

ReadTGF::~ReadTGF()
{
  if (Vars) {
    for (int i=0; i<Vars->Count; i++) {
      TGVARS* Var = (TGVARS*)Vars->Items[i];
      delete Var;
      Vars->Items[i] = 0;
      }
    Vars->Clear();
    delete Vars;
  }

  if (vdx != NULL) delete[] vdx;

  if (InputFileOpen) //fclose(input);
    infile.close();
}
//---------------------------------------------------------------------------

double ReadTGF::FontHeight(double Height)
{
  int iHeight = nint(72*Height);
  return ((double)iHeight/72.0);
}
//---------------------------------------------------------------------------

void ReadTGF::DecodeTGN126(char buffer[])
{
  n.vars = getshort(&buffer[0]);
  n.levs = getshort(&buffer[2]);
  n.groups = getshort(&buffer[4]);
  n.zones = getshort(&buffer[6]);
  n.zlabels = getshort(&buffer[8]);
  n.dates = getshort(&buffer[10]);
  n.dend = (getshort(&buffer[12]) == 1) ? true : false;
  n.text = getshort(&buffer[14]);
  d->Boxes = getshort(&buffer[16]);
  n.lith = getshort(&buffer[18]);
  n.lithboxes = getshort(&buffer[20]);
}
//---------------------------------------------------------------------------

void ReadTGF::DecodeTGN123(char buffer[])
{
  n.vars = getshort(&buffer[0]);
  n.levs = getshort(&buffer[2]);
  n.groups = getshort(&buffer[4]);
  n.zones = getshort(&buffer[6]);
  n.zlabels = getshort(&buffer[8]);
  n.dates = getshort(&buffer[10]);
  n.dend = (getshort(&buffer[12]) == 1) ? true : false;
  n.text = getshort(&buffer[14]);
  d->Boxes = getshort(&buffer[16]);
  n.lith = getshort(&buffer[18]);
  n.lithboxes = n.lith;         // new in v. 1.24
}
//---------------------------------------------------------------------------

void ReadTGF::DecodeTGN119(char buffer[])
{
  n.vars = getshort(&buffer[0]);
  n.levs = getshort(&buffer[2]);
  n.groups = getshort(&buffer[4]);
  n.zones = getshort(&buffer[6]);
  n.zlabels = getshort(&buffer[8]);
  n.dates = getshort(&buffer[10]);
  n.dend = (getshort(&buffer[12]) == 1) ? true : false;
  n.text = getshort(&buffer[14]);
  d->Boxes = getshort(&buffer[16]);
  n.lith      = 0;                 // new in v. 1.20
  n.lithboxes = 0;                 // new in v. 1.24
}
//---------------------------------------------------------------------------

void ReadTGF::DecodeColors126(char buffer[])
{
  int i;
  co.a_color_index = buffer[0];
  co.d_color_index = buffer[1];
  co.f_color_index = buffer[2];
  co.g_color_index = buffer[3];
  co.e_color_index = buffer[4];
  co.o_color_index = buffer[5];
  if (co.o_color_index == 0) co.o_color_index = 255;
  co.t_color_index = buffer[6];
  co.h_color_index = buffer[7];
  co.z_color_index = buffer[8];
  co.r_color_index = buffer[9];
  co.shades_of_gray = buffer[10];
  int j = 11;
  for (i=0; i<26; i++)
    {
      co.group_index[i].g = buffer[j++];
      co.group_index[i].e = buffer[j++];
    }
  j = 63;
  for (i=0; i<16; i++)
    {
      co.d_color[i].red   = getdouble(&buffer[j]);
      co.d_color[i].green = getdouble(&buffer[j+8]);
      co.d_color[i].blue  = getdouble(&buffer[j+16]);
      j+=24;
    }
  TranslateColors(d);

  j = 447;
  for (i=0; i<24; i++)
    {
      co.s_color[i].red   = getdouble(&buffer[j]);
      co.s_color[i].green = getdouble(&buffer[j+8]);
      co.s_color[i].blue  = getdouble(&buffer[j+16]);
      j+=24;
    }
}
//---------------------------------------------------------------------------

void ReadTGF::DecodeColors111(char buffer[])
{
  int i;
  co.a_color_index = buffer[0];
  co.d_color_index = buffer[1];
  co.f_color_index = buffer[2];
  co.g_color_index = buffer[3];
  co.e_color_index = buffer[4];
  co.o_color_index = buffer[5];
  if (co.o_color_index == 0) co.o_color_index = 255;
  co.t_color_index = buffer[6];
  co.h_color_index = buffer[7];
  co.z_color_index = buffer[8];
  co.r_color_index = buffer[9];
  co.shades_of_gray = false;
  int j = 10;
  for (i=0; i<26; i++)
    {
      co.group_index[i].g = buffer[j++];
      co.group_index[i].e = buffer[j++];
    }
  j = 62;
  for (i=0; i<16; i++)
    {
      co.d_color[i].red   = getdouble(&buffer[j]);
      co.d_color[i].green = getdouble(&buffer[j+8]);
      co.d_color[i].blue  = getdouble(&buffer[j+16]);
      j+=24;
    }
  TranslateColors(d);

  j = 446;
  for (i=0; i<24; i++)
    {
      co.s_color[i].red   = getdouble(&buffer[j]);
      co.s_color[i].green = getdouble(&buffer[j+8]);
      co.s_color[i].blue  = getdouble(&buffer[j+16]);
      j+=24;
    }
}
//---------------------------------------------------------------------------

void ReadTGF::DecodeLineWidths126(char buffer[])
{
  d->Default.LineWidth = nint(getdouble(&buffer[0]));
  AxisLineWidth = nint(getdouble(&buffer[8]));
  d->Default.Graph.SilhouetteLineWidth = nint(getdouble(&buffer[16]));
  d->Default.Graph.HistogramLineWidth  = nint(getdouble(&buffer[24]));
  d->Default.Xaxis.GridLineWidth = nint(getdouble(&buffer[32]));
  d->Default.GroupAttr.LineWidth = nint(getdouble(&buffer[40]));
  d->dgo.DendLineWidth = nint(getdouble(&buffer[48]));
  d->Default.ZoneAttr.LineWidth  = nint(getdouble(&buffer[56]));
  d->Frame.LineWidth = nint(getdouble(&buffer[64]));

  if (d->Default.LineWidth < 1) d->Default.LineWidth = 1;
  if (AxisLineWidth  < 1) AxisLineWidth  = 1;
  if (d->Default.Graph.SilhouetteLineWidth   < 1) d->Default.Graph.SilhouetteLineWidth   = 1;
  if (d->Default.Graph.HistogramLineWidth  < 1) d->Default.Graph.HistogramLineWidth  = 1;
  if (d->Default.Xaxis.GridLineWidth  < 1) d->Default.Xaxis.GridLineWidth  = 1;
  if (d->Default.GroupAttr.LineWidth < 1) d->Default.GroupAttr.LineWidth = 1;
  if (d->dgo.DendLineWidth  < 1) d->dgo.DendLineWidth  = 1;
  if (d->Default.ZoneAttr.LineWidth  < 1) d->Default.ZoneAttr.LineWidth  = 1;
  if (d->Frame.LineWidth < 1) d->Frame.LineWidth = 1;

  d->Default.LineWidth *= 0.25;
  AxisLineWidth *= 0.25;
  d->Default.Graph.SilhouetteLineWidth *= 0.25;
  d->Default.Graph.HistogramLineWidth *= 0.25;
  d->Default.Xaxis.GridLineWidth *= 0.25;
  d->Default.GroupAttr.LineWidth *= 0.25;
  d->dgo.DendLineWidth *= 0.25;
  d->Default.ZoneAttr.LineWidth *= 0.25;
  d->Frame.LineWidth *= 0.25;
  //d->LineWidth.lith = 0.25;
}
//---------------------------------------------------------------------------

void ReadTGF::DecodeRareSpecies126(char buffer[])
{
  d->Rare.Symbol = buffer[1];
  d->Rare.Size = getfloat(&buffer[2]);
  d->Rare.LineWidth = d->Default.LineWidth;
}

void ReadTGF::DecodeLimits126(char buffer[])
{
  d->Frame.Bottom = getdouble(&buffer[32]);
  d->Frame.Top = getdouble(&buffer[40]);
  d->Frame.Left = getdouble(&buffer[48]);
  d->Frame.Right = getdouble(&buffer[56]);
  d->Frame.Plot = buffer[64];
  d->Frame.FrameMargin = 0.1;
}
//---------------------------------------------------------------------------

void ReadTGF::DecodeLithOptions126(char buffer[])
{
  d->lopt.On = buffer[0];
  d->lopt.KeyOn = buffer[1];
  d->lopt.AutoTopDepth = buffer[2];
  d->lopt.AutoBotDepth = buffer[3];
  d->lopt.TopDepth = getdouble(&buffer[4]);
  d->lopt.BotDepth = getdouble(&buffer[12]);
  double hite_title = getdouble(&buffer[20])/0.7;
  d->lopt.Angle = getdouble(&buffer[28]);
  double hiteKeyText = getdouble(&buffer[36])/0.7;
  d->lopt.BoxWidth = getdouble(&buffer[44]);
  d->lopt.LithLineWidth = 0.25;                     // new
  d->lopt.KeyLineWidth = d->Default.LineWidth;      // new
  d->lopt.ColumnLineWidth = d->Default.LineWidth;   // new
  d->lopt.BoundaryLineWidth = d->Default.LineWidth; // new
  getUnicodeString2(d->lopt.LithTitle, &buffer[52]);
  d->lopt.LithTitleFont = DefaultFont;
  d->lopt.LithTitleFont.Height = FontHeight(hite_title);
  d->lopt.KeyFont = DefaultFont;
  d->lopt.KeyFont.Height = FontHeight(hiteKeyText);
}
//---------------------------------------------------------------------------

void ReadTGF::DecodeLithOptions120(char buffer[])
{
  d->lopt.On = buffer[0];
  d->lopt.KeyOn = 0;                                  // new in v. 1.21
  d->lopt.AutoTopDepth = buffer[1];
  d->lopt.AutoBotDepth = buffer[2];
  d->lopt.TopDepth = getdouble(&buffer[3]);
  d->lopt.BotDepth = getdouble(&buffer[11]);
  double hite_title = getdouble(&buffer[19])/0.7;
  d->lopt.Angle = getdouble(&buffer[27]);
  double hiteKeyText = 0.25/0.7;                     // new in v. 1.21
  d->lopt.BoxWidth = 1.2;                             // new in v. 1.21
  getUnicodeString2(d->lopt.LithTitle, &buffer[35]);

  d->lopt.LithTitleFont = DefaultFont;
  d->lopt.LithTitleFont.Height = FontHeight(hite_title);
  d->lopt.KeyFont = DefaultFont;
  d->lopt.KeyFont.Height = FontHeight(hiteKeyText);
}
//---------------------------------------------------------------------------

void ReadTGF::DecodeGRAPHS126(char buffer[], GRAPHS *grf)
{
  grf->GraphType      = buffer[0];
  grf->SilhouetteFill = buffer[1];
  grf->SilhouettePattern = buffer[2];
  grf->Exag           = buffer[3];
  grf->ExagFill       = buffer[4];
  grf->ExagPattern    = buffer[5];
  grf->ExagGrid       = buffer[6];
  grf->BarWidth       = getdouble(&buffer[7]);
  grf->BarFill        = buffer[15];
  grf->BarPattern     = buffer[16];
  grf->VerticalAxis   = buffer[17];
  double number_hite  = getdouble(&buffer[18])/0.7;
  grf->DecimalPoints  = buffer[26];
  grf->MarkerType     = buffer[27];
  grf->MarkerSize     = getfloat(&buffer[28]);
  grf->SymbolName     = buffer[32];
  grf->ZeroSymbol     = buffer[33];
  grf->AutoMarkerTop  = buffer[34];
  grf->AutoMarkerBottom = buffer[35];
  grf->XMarkerLabel   = getdouble(&buffer[36]);
  grf->YMarkerLabel   = getdouble(&buffer[44]);
  grf->XPresence      = getdouble(&buffer[52]);
  grf->PresenceSymbol = buffer[60];
  grf->DepthBars      = buffer[61];
  grf->DottedBaseLine = buffer[62];
  grf->GraphColor = DOSColorToRGB(co.d_color, buffer[63]);
  grf->ExagColor = DOSColorToRGB(co.d_color, buffer[64]);
  //grf->GraphOutlineColor = (d->Colors.shades_of_gray) ? d->Colors.a_color : grf->GraphColor;
  grf->GraphOutlineColor = (co.shades_of_gray) ? d->Default.Xaxis.Color : grf->GraphColor;
  grf->ExagOutlineColor = d->Default.Graph.ExagOutlineColor;
  grf->DepthBarsColor = d->Default.Xaxis.Color;
  grf->SilhouetteLineWidth = d->Default.Graph.SilhouetteLineWidth;
  grf->HistogramLineWidth = d->Default.Graph.HistogramLineWidth;
  grf->LineGraphLineWidth = d->Default.Graph.SilhouetteLineWidth;       // new
  grf->MarkerLineWidth = d->Default.LineWidth;    // new
  grf->NumberFont = DefaultFont;
  grf->NumberFont.Height = FontHeight(number_hite);
  grf->PlotZeroNumbers = true;
  grf->UseThickVar = false;   // new
}
//---------------------------------------------------------------------------

void ReadTGF::DecodeGRAPHS125(char buffer[], GRAPHS *grf)
{
  grf->GraphType      = buffer[0];
  grf->SilhouetteFill = buffer[1];
  grf->SilhouettePattern = buffer[2];
  grf->Exag           = buffer[3];
  grf->ExagFill       = buffer[4];
  grf->ExagPattern    = buffer[5];
  grf->ExagGrid       = buffer[6];
  grf->BarWidth       = getdouble(&buffer[7]);
  grf->BarFill        = buffer[15];
  grf->BarPattern     = buffer[16];
  grf->VerticalAxis   = buffer[17];
  double number_hite  = getdouble(&buffer[18])/0.7;
  grf->DecimalPoints  = buffer[26];
  grf->MarkerType     = buffer[27];
  grf->MarkerSize     = getfloat(&buffer[28]);
  grf->SymbolName     = buffer[32];
  grf->ZeroSymbol     = true;          // new in v. 1.26
  grf->AutoMarkerTop  = buffer[33];
  grf->AutoMarkerBottom = buffer[34];
  grf->XMarkerLabel   = getdouble(&buffer[35]);
  grf->YMarkerLabel   = getdouble(&buffer[43]);
  grf->XPresence      = getdouble(&buffer[51]);
  grf->PresenceSymbol = buffer[59];
  grf->DepthBars      = buffer[60];
  grf->DottedBaseLine = buffer[61];
  grf->GraphColor = DOSColorToRGB(co.d_color, buffer[62]);
  grf->ExagColor = DOSColorToRGB(co.d_color, buffer[63]);
  grf->GraphOutlineColor = (co.shades_of_gray) ? d->Default.Xaxis.Color : grf->GraphColor;
  grf->ExagOutlineColor = d->Default.Graph.ExagOutlineColor;
  grf->DepthBarsColor = d->Default.Xaxis.Color;
  grf->SilhouetteLineWidth = d->Default.Graph.SilhouetteLineWidth;
  grf->HistogramLineWidth = d->Default.Graph.HistogramLineWidth;
  grf->LineGraphLineWidth = d->Default.Graph.SilhouetteLineWidth;       // new
  grf->MarkerLineWidth = d->Default.LineWidth;    // new
  grf->NumberFont = DefaultFont;
  grf->NumberFont.Height = FontHeight(number_hite);
  grf->PlotZeroNumbers = true;
  grf->UseThickVar = false;   // new
}
//---------------------------------------------------------------------------

void ReadTGF::DecodeXAXIS126(char buffer[], XAXIS *xax)
{
  xax->AutoTic         = buffer[0];
  xax->AutoScaleFactor = buffer[1];
  xax->AutoMin         = buffer[2];
  xax->AutoMax         = buffer[3];
  xax->LabelOriginTic  = buffer[4];
  xax->TicDecPts       = buffer[5];
  xax->GraphWidth      = getdouble(&buffer[6]);
  xax->ScaleFactor     = getdouble(&buffer[14]);
  xax->MinorTics       = getdouble(&buffer[22]);
  xax->MajorTics       = getdouble(&buffer[30]);
  xax->LabeledTics     = getdouble(&buffer[38]);
  //xax->pres_minor_tics = xax->MinorTics;  //new
  xax->TicLabelDivideBy  = getdouble(&buffer[46]);
  xax->GridLines       = getshort(&buffer[54]);
  double hite_tic_label  = getdouble(&buffer[56])/0.7;
  double hite_axis_label = getdouble(&buffer[64])/0.7;
  xax->LabelToTicDistance = getdouble(&buffer[72]);
  xax->MajorTicLength   = getdouble(&buffer[80]);
  xax->MinorTicLength   = getdouble(&buffer[88]);
  xax->TopTicLength     = getdouble(&buffer[96]);
  xax->GraphNameAngle   = getdouble(&buffer[104]);
  double hite_gn       = getdouble(&buffer[112])/0.7;
  xax->GraphNameXOffset = getdouble(&buffer[120]);
  xax->GraphNameYOffset         = getdouble(&buffer[128]);
  xax->DistanceToNextGraph     = getdouble(&buffer[136]);
  xax->XaxisMin        = getdouble(&buffer[144]);
  xax->XaxisMax        = getdouble(&buffer[152]);
  xax->Truncate        = buffer[160];
  short trunc_val      = buffer[161];
  xax->PrintTruncatedValues = (trunc_val == 0) ? false : true;  // new
  xax->ScaleTruncatedValues = true;  // new
  double trunc_hite    = getdouble(&buffer[162])/0.7;
  xax->TruncateWhere   = buffer[170];
  xax->TruncateDecPts  = 0;     // new in TGView
  xax->PlotGraphName   = true;  // new in TGView
  xax->Color           = d->Default.Xaxis.Color;  // new in TGView
  getUnicodeString2(xax->AxisLabel, &buffer[171]);

  xax->TicFont = DefaultFont;          
  xax->TicFont.Height = FontHeight(hite_tic_label);
  xax->AxisLabelFont = DefaultFont;
  xax->AxisLabelFont.Height = FontHeight(hite_axis_label);
  xax->GraphNameFont = DefaultFont;
  xax->GraphNameFont.Height = FontHeight(hite_gn);
  xax->TruncFont = DefaultFont;
  xax->TruncFont.Height = FontHeight(trunc_hite);
  xax->AxisLineWidth = AxisLineWidth;
  xax->GridLineWidth = d->Default.Xaxis.GridLineWidth;
}
//---------------------------------------------------------------------------

void ReadTGF::DecodeXAXIS117(char buffer[], XAXIS *xax)
{
  xax->AutoTic         = buffer[0];
  xax->AutoScaleFactor = buffer[1];
  xax->AutoMin         = buffer[2];
  xax->AutoMax         = buffer[3];
  xax->LabelOriginTic  = false;              // new in v. 1.18
  xax->TicDecPts       = buffer[4];
  xax->GraphWidth      = getdouble(&buffer[5]);
  xax->ScaleFactor     = getdouble(&buffer[13]);
  xax->MinorTics       = getdouble(&buffer[21]);
  xax->MajorTics       = getdouble(&buffer[29]);
  xax->LabeledTics     = getdouble(&buffer[37]);
  //xax->pres_minor_tics = xax->MinorTics;  //new
  xax->TicLabelDivideBy  = getdouble(&buffer[45]);
  xax->GridLines       = getshort(&buffer[53]);
  double hite_tic_label  = getdouble(&buffer[55])/0.7;
  double hite_axis_label = getdouble(&buffer[63])/0.7;
  xax->LabelToTicDistance    = getdouble(&buffer[71]);
  xax->MajorTicLength   = getdouble(&buffer[79]);
  xax->MinorTicLength   = getdouble(&buffer[87]);
  xax->TopTicLength     = getdouble(&buffer[95]);
  xax->GraphNameAngle   = getdouble(&buffer[103]);
  double hite_gn       = getdouble(&buffer[111])/0.7;
  xax->GraphNameXOffset = getdouble(&buffer[119]);
  xax->GraphNameYOffset = getdouble(&buffer[127]);
  xax->DistanceToNextGraph = getdouble(&buffer[135]);
  xax->XaxisMin        = getdouble(&buffer[143]);
  xax->XaxisMax        = getdouble(&buffer[151]);
  xax->Truncate        = buffer[159];
  //xax->trunc_val       = (short)buffer[160];
  short trunc_val      = buffer[161];
  xax->PrintTruncatedValues = (trunc_val == 0) ? false : true;   // new
  xax->ScaleTruncatedValues = true;   // new
  double trunc_hite    = getdouble(&buffer[161])/0.7;
  xax->TruncateWhere   = buffer[169];
  xax->TruncateDecPts  = 0;     // new in TGView
  xax->PlotGraphName   = true;  // new in TGView
  xax->Color           = d->Default.Xaxis.Color;  // new in TGView
  getUnicodeString2(xax->AxisLabel, &buffer[170]);

  xax->TicFont = DefaultFont;
  xax->TicFont.Height = FontHeight(hite_tic_label);
  xax->AxisLabelFont = DefaultFont;
  xax->AxisLabelFont.Height = FontHeight(hite_axis_label);
  xax->GraphNameFont = DefaultFont;
  xax->GraphNameFont.Height = FontHeight(hite_gn);
  xax->TruncFont = DefaultFont;
  xax->TruncFont.Height = FontHeight(trunc_hite);
  xax->AxisLineWidth = AxisLineWidth;
  xax->GridLineWidth = d->Default.Xaxis.GridLineWidth;
}
//---------------------------------------------------------------------------

void ReadTGF::DecodeXAXIS116(char buffer[], XAXIS *xax)
{
  xax->AutoTic         = buffer[0];
  xax->AutoScaleFactor = buffer[1];
  xax->AutoMin         = buffer[2];
  xax->AutoMax         = buffer[3];
  xax->LabelOriginTic  = false;              // new in v. 1.18
  xax->TicDecPts       = buffer[4];
  xax->GraphWidth      = getdouble(&buffer[5]);
  xax->ScaleFactor     = getdouble(&buffer[13]);
  xax->MinorTics       = getdouble(&buffer[21]);
  xax->MajorTics       = getdouble(&buffer[29]);
  xax->LabeledTics     = getdouble(&buffer[37]);
  //xax->pres_minor_tics = xax->MinorTics;  //new
  xax->TicLabelDivideBy  = getdouble(&buffer[45]);
  xax->GridLines       = getshort(&buffer[53]);
  double hite_tic_label  = getdouble(&buffer[55])/0.7;
  double hite_axis_label = getdouble(&buffer[63])/0.7;
  xax->LabelToTicDistance    = getdouble(&buffer[71]);
  xax->MajorTicLength   = getdouble(&buffer[79]);
  xax->MinorTicLength   = getdouble(&buffer[87]);
  xax->TopTicLength     = getdouble(&buffer[95]);
  xax->GraphNameAngle   = getdouble(&buffer[103]);
  double hite_gn       = getdouble(&buffer[111])/0.7;
  xax->GraphNameXOffset = getdouble(&buffer[119]);
  xax->GraphNameYOffset = getdouble(&buffer[127]);
  xax->DistanceToNextGraph = getdouble(&buffer[135]);
  xax->XaxisMin        = getdouble(&buffer[143]);
  xax->XaxisMax        = getdouble(&buffer[151]);
  xax->Truncate        = buffer[159];
  //xax->trunc_val       = (short)buffer[160];
  short trunc_val      = buffer[161];
  xax->PrintTruncatedValues = (trunc_val == 0) ? false : true;   // new
  xax->ScaleTruncatedValues = true;   // new
  double trunc_hite    = getdouble(&buffer[161])/0.7;
  xax->TruncateWhere   = buffer[169];
  xax->TruncateDecPts  = 0;     // new in TGView
  xax->PlotGraphName   = true;  // new in TGView
  xax->Color           = d->Default.Xaxis.Color;  // new in TGView
  getUnicodeString2(xax->AxisLabel, &buffer[170]);

  xax->TicFont = DefaultFont;
  xax->TicFont.Height = FontHeight(hite_tic_label);
  xax->AxisLabelFont = DefaultFont;
  xax->AxisLabelFont.Height = FontHeight(hite_axis_label);
  xax->GraphNameFont = DefaultFont;
  xax->GraphNameFont.Height = FontHeight(hite_gn);
  xax->TruncFont = DefaultFont;
  xax->TruncFont.Height = FontHeight(trunc_hite);
  xax->AxisLineWidth = AxisLineWidth;
  xax->GridLineWidth = d->Default.Xaxis.GridLineWidth;
}
//---------------------------------------------------------------------------

void ReadTGF::DecodeYAXIS126(char buffer[])
{
  yax.style           = buffer[0];
  yax.primary         = buffer[1];
  yax.secondary       = buffer[2];
  yax.axisNo          = getshort(&buffer[3]);
  yax.plot_primary    = buffer[5];
  yax.plot_secondary  = buffer[6];
  yax.automin         = buffer[7];
  yax.automax         = buffer[8];
  yax.automin1        = buffer[9];
  yax.automax1        = buffer[10];
  yax.automin2        = buffer[11];
  yax.automax2        = buffer[12];
  yax.autotic1        = buffer[13];
  yax.autotic2        = buffer[14];
  yax.ticdec1         = buffer[15];
  yax.ticdec2         = buffer[16];
  yax.label_position1 = buffer[17];
  yax.label_position2 = buffer[18];
  yax.color           = d->Default.Xaxis.Color;      // new
  yax.LineWidth       = AxisLineWidth;        // new
  yax.space           = getdouble(&buffer[19]);
  yax.len             = getdouble(&buffer[27]);
  yax.xdist           = getdouble(&buffer[35]);
  yax.min             = getdouble(&buffer[43]);
  yax.max             = getdouble(&buffer[51]);
  yax.min1            = getdouble(&buffer[59]);
  yax.max1            = getdouble(&buffer[67]);
  yax.min2            = getdouble(&buffer[75]);
  yax.max2            = getdouble(&buffer[83]);
  double hite_tic_label  = getdouble(&buffer[91])/0.7;
  double hite_axis_label = getdouble(&buffer[99])/0.7;
  yax.minor_tics1     = getdouble(&buffer[107]);
  yax.major_tics1     = getdouble(&buffer[115]);
  yax.minor_tics2     = getdouble(&buffer[123]);
  yax.major_tics2     = getdouble(&buffer[131]);
  yax.ticfac1         = getdouble(&buffer[139]);
  yax.ticfac2         = getdouble(&buffer[147]);
  yax.LabelToTicDistance    = getdouble(&buffer[155]);
  yax.MajorTicLength   = getdouble(&buffer[163]);
  yax.MinorTicLength   = getdouble(&buffer[171]);
  yax.xlab1           = getdouble(&buffer[179]);
  yax.ylab1           = getdouble(&buffer[187]);
  yax.xlab2           = getdouble(&buffer[195]);
  yax.ylab2           = getdouble(&buffer[203]);
  yax.angle1          = getdouble(&buffer[211]);
  yax.angle2          = getdouble(&buffer[219]);
  getUnicodeString2(yax.label1, &buffer[227]);
  getUnicodeString2(yax.label2, &buffer[298]);

  yax.TicFont = DefaultFont;
  yax.TicFont.Height = FontHeight(hite_tic_label);
  yax.LabelFont = DefaultFont;
  yax.LabelFont.Height = FontHeight(hite_axis_label);
}
//---------------------------------------------------------------------------

void ReadTGF::DecodeYAXIS118(char buffer[])
{
  yax.style           = buffer[0];
  yax.primary         = buffer[1];
  yax.secondary       = buffer[2];
  yax.axisNo          = 1;                    // new in v. 1.19
  yax.plot_primary    = buffer[3];
  yax.plot_secondary  = buffer[4];
  yax.automin         = buffer[5];
  yax.automax         = buffer[6];
  yax.automin1        = buffer[7];
  yax.automax1        = buffer[8];
  yax.automin2        = buffer[9];
  yax.automax2        = buffer[10];
  yax.autotic1        = buffer[11];
  yax.autotic2        = buffer[12];
  yax.ticdec1         = buffer[13];
  yax.ticdec2         = buffer[14];
  yax.label_position1 = buffer[15];
  yax.label_position2 = buffer[16];
  yax.color           = d->Default.Xaxis.Color;      // new
  yax.LineWidth       = AxisLineWidth;        // new
  yax.space           = getdouble(&buffer[17]);
  yax.len             = getdouble(&buffer[25]);
  yax.xdist           = getdouble(&buffer[33]);
  yax.min             = getdouble(&buffer[41]);
  yax.max             = getdouble(&buffer[49]);
  yax.min1            = getdouble(&buffer[57]);
  yax.max1            = getdouble(&buffer[65]);
  yax.min2            = getdouble(&buffer[73]);
  yax.max2            = getdouble(&buffer[81]);
  double hite_tic_label  = getdouble(&buffer[89])/0.7;
  double hite_axis_label = getdouble(&buffer[97])/0.7;
  yax.minor_tics1     = getdouble(&buffer[105]);
  yax.major_tics1     = getdouble(&buffer[113]);
  yax.minor_tics2     = getdouble(&buffer[121]);
  yax.major_tics2     = getdouble(&buffer[129]);
  yax.ticfac1         = getdouble(&buffer[137]);
  yax.ticfac2         = getdouble(&buffer[145]);
  yax.LabelToTicDistance    = getdouble(&buffer[153]);
  yax.MajorTicLength   = getdouble(&buffer[161]);
  yax.MinorTicLength   = getdouble(&buffer[169]);
  yax.xlab1           = getdouble(&buffer[177]);
  yax.ylab1           = getdouble(&buffer[185]);
  yax.xlab2           = getdouble(&buffer[193]);
  yax.ylab2           = getdouble(&buffer[201]);
  yax.angle1          = getdouble(&buffer[209]);
  yax.angle2          = getdouble(&buffer[217]);
  getUnicodeString2(yax.label1, &buffer[225]);
  getUnicodeString2(yax.label2, &buffer[296]);

  yax.TicFont = DefaultFont;
  yax.TicFont.Height = FontHeight(hite_tic_label);
  yax.LabelFont = DefaultFont;
  yax.LabelFont.Height = FontHeight(hite_axis_label);
}
//---------------------------------------------------------------------------

void ReadTGF::DecodeYAXIS117(char buffer[])
{
  yax.style           = buffer[0];
  yax.primary         = buffer[1];
  yax.secondary       = buffer[2];
  yax.axisNo          = 1;                    // new in v. 1.19
  yax.plot_primary    = buffer[3];
  yax.plot_secondary  = buffer[4];
  yax.automin         = buffer[5];
  yax.automax         = buffer[6];
  yax.automin1        = buffer[7];
  yax.automax1        = buffer[8];
  yax.automin2        = buffer[9];
  yax.automax2        = buffer[10];
  yax.autotic1        = buffer[11];
  yax.autotic2        = buffer[12];
  yax.ticdec1         = buffer[13];
  yax.ticdec2         = buffer[14];
  yax.label_position1 = buffer[15];
  yax.label_position2 = buffer[16];
  yax.color           = d->Default.Xaxis.Color;      // new
  yax.LineWidth       = AxisLineWidth;        // new
  yax.space           = 0.2;                  // new in v. 1.18
  yax.len             = getdouble(&buffer[17]);
  yax.xdist           = getdouble(&buffer[25]);
  yax.min             = getdouble(&buffer[33]);
  yax.max             = getdouble(&buffer[41]);
  yax.min1            = getdouble(&buffer[49]);
  yax.max1            = getdouble(&buffer[57]);
  yax.min2            = getdouble(&buffer[65]);
  yax.max2            = getdouble(&buffer[73]);
  double hite_tic_label  = getdouble(&buffer[81])/0.7;
  double hite_axis_label = getdouble(&buffer[89])/0.7;
  yax.minor_tics1     = getdouble(&buffer[97]);
  yax.major_tics1     = getdouble(&buffer[105]);
  yax.minor_tics2     = getdouble(&buffer[113]);
  yax.major_tics2     = getdouble(&buffer[121]);
  yax.ticfac1         = getdouble(&buffer[129]);
  yax.ticfac2         = getdouble(&buffer[137]);
  yax.LabelToTicDistance    = getdouble(&buffer[145]);
  yax.MajorTicLength   = getdouble(&buffer[153]);
  yax.MinorTicLength   = getdouble(&buffer[161]);
  yax.xlab1           = getdouble(&buffer[169]);
  yax.ylab1           = getdouble(&buffer[177]);
  yax.xlab2           = getdouble(&buffer[185]);
  yax.ylab2           = getdouble(&buffer[193]);
  yax.angle1          = getdouble(&buffer[201]);
  yax.angle2          = getdouble(&buffer[209]);
  getUnicodeString2(yax.label1, &buffer[217]);
  getUnicodeString2(yax.label2, &buffer[288]);

  yax.TicFont = DefaultFont;
  yax.TicFont.Height = FontHeight(hite_tic_label);
  yax.LabelFont = DefaultFont;
  yax.LabelFont.Height = FontHeight(hite_axis_label);
}
//---------------------------------------------------------------------------

void ReadTGF::DecodeYAXIS110(char buffer[])
{
  yax.style           = buffer[0];
  yax.primary         = buffer[1];
  yax.secondary       = buffer[2];
  yax.axisNo          = 1;                    // new in v. 1.19
  yax.plot_primary    = buffer[3];
  yax.plot_secondary  = buffer[4];
  yax.automin         = buffer[5];
  yax.automax         = buffer[6];
  yax.automin1        = buffer[7];
  yax.automax1        = buffer[8];
  yax.automin2        = buffer[9];
  yax.automax2        = buffer[10];
  yax.autotic1        = buffer[11];
  yax.autotic2        = buffer[12];
  yax.ticdec1         = buffer[13];
  yax.ticdec2         = buffer[14];
  yax.label_position1 = buffer[15];
  yax.label_position2 = buffer[16];
  yax.color           = d->Default.Xaxis.Color;      // new
  yax.LineWidth       = AxisLineWidth;        // new
  yax.space           = 0.2;                  // new in v. 1.18
  yax.len             = getdouble(&buffer[17]);
  yax.xdist           = 0.3;                  // new in v. 1.11
  yax.min             = getdouble(&buffer[25]);
  yax.max             = getdouble(&buffer[33]);
  yax.min1            = getdouble(&buffer[41]);
  yax.max1            = getdouble(&buffer[49]);
  yax.min2            = getdouble(&buffer[57]);
  yax.max2            = getdouble(&buffer[65]);
  double hite_tic_label  = getdouble(&buffer[73])/0.7;
  double hite_axis_label = getdouble(&buffer[81])/0.7;
  yax.minor_tics1     = getdouble(&buffer[89]);
  yax.major_tics1     = getdouble(&buffer[97]);
  yax.minor_tics2     = getdouble(&buffer[105]);
  yax.major_tics2     = getdouble(&buffer[113]);
  yax.ticfac1         = getdouble(&buffer[121]);
  yax.ticfac2         = getdouble(&buffer[129]);
  yax.LabelToTicDistance    = getdouble(&buffer[137]);
  yax.MajorTicLength   = getdouble(&buffer[145]);
  yax.MinorTicLength   = getdouble(&buffer[153]);
  yax.xlab1           = getdouble(&buffer[161]);
  yax.ylab1           = getdouble(&buffer[169]);
  yax.xlab2           = getdouble(&buffer[177]);
  yax.ylab2           = getdouble(&buffer[185]);
  yax.angle1          = getdouble(&buffer[293]);
  yax.angle2          = getdouble(&buffer[201]);
  getUnicodeString2(yax.label1, &buffer[209]);
  getUnicodeString2(yax.label2, &buffer[280]);

  yax.TicFont = DefaultFont;
  yax.TicFont.Height = FontHeight(hite_tic_label);
  yax.LabelFont = DefaultFont;
  yax.LabelFont.Height = FontHeight(hite_axis_label);
}
//---------------------------------------------------------------------------

void ReadTGF::DecodeVarNames126(int i, char buffer[])
{
  char sum[2];
  char status;
  TGVARS *Var = new TGVARS();
  getUnicodeString1(Var->code, buffer);
  sum[0] = buffer[9];
  sum[1] = '\0';
  Var->sum = sum;
  getUnicodeString2(Var->name, &buffer[10]);
  status = buffer[71];
  SpecialVarCodes(Var->code);
  UnicodeString code = Var->code.SubString(1, 5);
  if (code == "Chron" || code == "Depth" || code == "Thick")
     status = 'X';
  else if (code == "Error")
     status = 'E';
  switch (status) {
    case 'B': Var->status = BASE; break;
    case 'O': Var->status = OVERLAY; break;
    case 'C': Var->status = STACKED; break;
    case 'S': Var->status = SKIP; break;
    case 'E': Var->status = ERRORBAR; break;
    case 'X': Var->status = NOGRAPH; break;
    default: Var->status = NORMAL;
    }
  Vars->Add(Var);
}
//---------------------------------------------------------------------------

void ReadTGF::DecodeVarNames118(int i, char buffer[])
{
  char sum[2];
  char status;
  TGVARS *Var = new TGVARS();
  getUnicodeString1(Var->code, buffer);
  sum[0] = buffer[3];
  sum[1] = '\0';
  Var->sum = sum;
  getUnicodeString2(Var->name, &buffer[4]);
  status = buffer[45];
  if (Var->code == "=A")
    Var->code = "Chron1";
  else if (Var->code == "=D")
    Var->code = "Depth1";
  SpecialVarCodes(Var->code);
  UnicodeString code = Var->code.SubString(1, 5);
  if (code == "Chron" || code == "Depth" || code == "Thick")
     status = 'X';
  else if (code == "Error")
     status = 'E';
  switch (status) {
    case 'B': Var->status = BASE; break;
    case 'O': Var->status = OVERLAY; break;
    case 'C': Var->status = STACKED; break;
    case 'S': Var->status = SKIP; break;
    case 'E': Var->status = ERRORBAR; break;
    case 'X': Var->status = NOGRAPH; break;
    default: Var->status = NORMAL;
    }
  Vars->Add(Var);
}
//---------------------------------------------------------------------------

void ReadTGF::DecodeDendOptions126(char buffer[])
{
  int i, j;
  d->dgo.Loaded = n.dend;   // new
  d->dgo.On = buffer[0];
  d->dgo.ScaleType = buffer[1];
  d->dgo.DendWidth = getdouble(&buffer[2]);
  d->dgo.AutoTic = buffer[10];
  //d->dgo.autominortics = buffer[11];
  d->dgo.AutoTicDecPts = buffer[12];
  d->dgo.MajorTics = getdouble(&buffer[13]);
  d->dgo.MinorTics = getdouble(&buffer[21]);
  d->dgo.TicDecPts = getshort(&buffer[29]);
  d->dgo.AxisColor = d->Default.Xaxis.Color;        // new
  d->dgo.DendColor = d->Default.Xaxis.Color;        // new
  d->dgo.AxisLineWidth = AxisLineWidth;           // new
  //d->dgo.DendLineWidth = AxisLineWidth;           // new
  double hite_axis_label = getdouble(&buffer[31])/0.7;
  double hite_graph_name = getdouble(&buffer[39])/0.7;
  double hite_tic_label = getdouble(&buffer[47])/0.7;
  getUnicodeString2(d->dgo.DendTitle, &buffer[55]);
  for (i=0, j=96; i<4; i++, j+=41)
	getUnicodeString2(d->dgo.DendAxisLabels[i], &buffer[j]);

  d->dgo.AxisLabelFont = DefaultFont;
  d->dgo.AxisLabelFont.Height = FontHeight(hite_axis_label);
  d->dgo.DendTitleFont = DefaultFont;
  d->dgo.DendTitleFont.Height = FontHeight(hite_graph_name);
  d->dgo.TicFont = DefaultFont;
  d->dgo.TicFont.Height = FontHeight(hite_tic_label);

  d->dgo.TopTicLength = d->Default.Xaxis.TopTicLength;        // new
  d->dgo.MajorTicLength = d->Default.Xaxis.MajorTicLength;    // new
  d->dgo.MinorTicLength = d->Default.Xaxis.MinorTicLength;    // new
  d->dgo.LabelToTicDistance = d->Default.Xaxis.LabelToTicDistance;      // new
  d->dgo.GraphNameYOffset = d->Default.Xaxis.GraphNameYOffset;   // new
}
//---------------------------------------------------------------------------

//void ReadTGF::DecodeDendrogram126(int i, char buffer[])
void ReadTGF::DecodeDendrogram126(char buffer[], DENDROGRAM *Cluster)
{
  Cluster->clus1 = getshort(buffer);
  Cluster->clus2 = getshort(&buffer[2]);
  Cluster->inc = getfloat(&buffer[4]);
  Cluster->tot = getfloat(&buffer[8]);
  Cluster->wcd = getfloat(&buffer[12]);
  Cluster->mwcd = getfloat(&buffer[16]);
  d->Dgr->Add(Cluster);
}
//---------------------------------------------------------------------------

void ReadTGF::DecodeGroups126(char buffer[])
{
  GROUPS *Group = new GROUPS();
  Group->Position = INLINE;          // new
  Group->Color = d->Default.GroupAttr.Color;  // new
  Group->LineWidth = d->Default.GroupAttr.LineWidth;   // new
  getUnicodeString1(Group->code1, buffer);
  getUnicodeString1(Group->code2, &buffer[9]);
  getUnicodeString2(Group->name, &buffer[18]);
  double hite_gn = getdouble(&buffer[59])/0.7;
  if (hite_gn == 0) hite_gn = 0.35/0.7;
  Group->Font = DefaultFont;
  Group->Font.Height = FontHeight(hite_gn);
  if (Group->code1.Length() > 0 &&
      Group->code2.Length() > 0 &&
      Group->name.Length() > 0)
        d->Groups->Add(Group);
  else
    delete Group;
}
//---------------------------------------------------------------------------

void ReadTGF::DecodeGroups118(char buffer[])
{
  GROUPS *Group = new GROUPS();
  Group->Position = INLINE;          // new
  Group->Color = clBlack;            // new
  Group->LineWidth = d->Default.GroupAttr.LineWidth;   // new
  getUnicodeString1(Group->code1, buffer);
  getUnicodeString1(Group->code2, &buffer[3]);
  getUnicodeString2(Group->name, &buffer[6]);
  double hite_gn = getdouble(&buffer[47])/0.7;
  Group->Font = DefaultFont;
  Group->Font.Height = FontHeight(hite_gn);
  if (Group->code1.Length() > 0 &&
      Group->code2.Length() > 0 &&
      Group->name.Length() > 0)
         d->Groups->Add(Group);
  else
    delete Group;
}
//---------------------------------------------------------------------------

void ReadTGF::DecodeZoneDefault126(char buffer[])
{
  d->Default.ZoneAttr.Priority   = getshort(buffer);
  d->Default.ZoneAttr.ZoneStyle  = getshort(&buffer[2]);
  d->Default.ZoneAttr.Border     = getshort(&buffer[4]);
  d->Default.ZoneAttr.Pattern    = getshort(&buffer[6]);
  d->Default.ZoneAttr.LineStyle  = getshort(&buffer[8]);
  d->Default.ZoneAttr.ZoneColor      = DOSColorToRGB(co.d_color, buffer[10]);
  d->Default.ZoneAttr.ZoneWidth      = getfloat(&buffer[11]);
  //d->zone_default.LineWidth     = d->LineWidth.zone;        // new
  d->Default.ZoneAttr.user.dash  = nint(getdouble(&buffer[15]));
  d->Default.ZoneAttr.user.space = nint(getdouble(&buffer[23]));
  d->Default.ZoneAttr.ThruLabelCol = true;     // new
}
//---------------------------------------------------------------------------

// TODO: make sure all vars in defaults and vica versa
void ReadTGF::DecodeZoneDefault115(char buffer[])
{
  d->Default.ZoneAttr.Priority   = getshort(buffer);
  d->Default.ZoneAttr.ZoneStyle      = getshort(&buffer[2]);
  d->Default.ZoneAttr.Border     = getshort(&buffer[4]);
  d->Default.ZoneAttr.Pattern    = getshort(&buffer[6]);
  d->Default.ZoneAttr.LineStyle  = getshort(&buffer[8]);
  d->Default.ZoneAttr.ZoneColor      = DOSColorToRGB(co.d_color, buffer[10]);
  d->Default.ZoneAttr.ZoneWidth      = getfloat(&buffer[11]);
  //d->zone_default.LineWidth     = d->LineWidth.zone;        // new
  d->Default.ZoneAttr.user.dash  = 0;
  d->Default.ZoneAttr.user.space = 0;
  d->Default.ZoneAttr.ThruLabelCol = true;  // new
}
//---------------------------------------------------------------------------

void ReadTGF::DecodeZones126(char buffer[])
{
  ZONE *Zone = new ZONE();
  Zone->depth      = getdouble(buffer);
  Zone->ZoneStyle  = getshort(&buffer[8]);
  Zone->LineStyle  = getshort(&buffer[10]);
  Zone->Pattern = (Zone->ZoneStyle == PATTERNZONE) ? Zone->LineStyle : 1;  // new
  if (Zone->ZoneStyle == PATTERNZONE) Zone->LineStyle = 1;
  Zone->Border     = (bool)getshort(&buffer[12]);
  Zone->ZoneWidth      = getfloat(&buffer[14]);
  Zone->Priority   = getshort(&buffer[18]);
  Zone->ZoneColor  = DOSColorToRGB(co.d_color, buffer[20]);
  Zone->BorderColor = Zone->ZoneColor;
  Zone->user.dash  = nint(getdouble(&buffer[21]));
  Zone->user.space = nint(getdouble(&buffer[29]));
  Zone->LineWidth  = d->Default.ZoneAttr.LineWidth;        // new
  Zone->ThruLabelCol = true;    // new
  d->Zones->Add(Zone);
}
//---------------------------------------------------------------------------

void ReadTGF::DecodeZones115(char buffer[])
{
  ZONE *Zone = new ZONE();
  Zone->depth      = getdouble(buffer);
  Zone->ZoneStyle  = getshort(&buffer[8]);
  Zone->LineStyle  = getshort(&buffer[10]);
  Zone->Pattern = (Zone->ZoneStyle == PATTERNZONE) ? Zone->LineStyle : 1;  // new
  if (Zone->ZoneStyle == PATTERNZONE) Zone->LineStyle = 1;
  Zone->Border     = (bool)getshort(&buffer[12]);
  Zone->ZoneWidth  = getfloat(&buffer[14]);
  Zone->Priority   = getshort(&buffer[18]);
  Zone->ZoneColor  = DOSColorToRGB(co.d_color, buffer[20]);
  Zone->BorderColor = Zone->ZoneColor;
  Zone->user.dash  = 0;
  Zone->user.space = 0;
  Zone->LineWidth  = d->Default.ZoneAttr.LineWidth;        // new
  Zone->ThruLabelCol = true;    // new
  d->Zones->Add(Zone);
}
//---------------------------------------------------------------------------

void ReadTGF::DecodeZoneOptions126(char buffer[])
{
  d->zopt.ZoneTitleAngle = getdouble(buffer);
  double hite_gn  = getdouble(&buffer[8])/0.7;
  d->zopt.ZoneTitleXOffset = getdouble(&buffer[16]);
  d->zopt.Center = (d->zopt.ZoneTitleXOffset < 0.0) ? true : false;
  d->zopt.ZoneTitleYOffset = getdouble(&buffer[24]);
  double hite_zn  = getdouble(&buffer[32])/0.7;
  //d->zopt.ZoneTitle.SetLength(0);
  getUnicodeString2(d->zopt.ZoneTitle, &buffer[40]);

  d->zopt.ZoneTitleFont = DefaultFont;
  d->zopt.ZoneTitleFont.Height = FontHeight(hite_gn);
  d->zopt.ZoneFont = DefaultFont;
  d->zopt.ZoneFont.Height = FontHeight(hite_zn);
}
//---------------------------------------------------------------------------

void ReadTGF::DecodeZoneLabels126(char buffer[])
{
  ZONELABELS *ZoneLabel = new ZONELABELS();
  ZoneLabel->top = getdouble(buffer);
  ZoneLabel->bottom = getdouble(&buffer[8]);
  getUnicodeString2(ZoneLabel->label, &buffer[16]);
  d->ZoneLabels->Add(ZoneLabel);
}
//---------------------------------------------------------------------------

void ReadTGF::DecodeDateOptions126(char buffer[])
{
  double hite_lab;
  d->dopt.DatesPosition = buffer[0];
  d->dopt.DatesTitlePosition = buffer[1];
  d->dopt.X_Title        = getdouble(&buffer[2]);
  d->dopt.Y_Title        = getdouble(&buffer[10]);
  d->dopt.Angle          = getdouble(&buffer[18]);
  hite_lab               = getdouble(&buffer[26])/0.7;

  d->dopt.DateTitleFont = DefaultFont;
  d->dopt.DateTitleFont.Height = FontHeight(hite_lab);
  d->dopt.DateFont = DefaultFont;
  d->dopt.DateFont.Height = FontHeight(yax.TicFont.Height);

  //d->dopt.DateTitle.SetLength(0);
  getUnicodeString2(d->dopt.DateTitle, &buffer[34]);

  d->dopt.DatesTitleTopYOffset = d->Default.Xaxis.GraphNameYOffset;
  d->dopt.Color = d->Default.Xaxis.Color;
}
//---------------------------------------------------------------------------

void ReadTGF::DecodeDates126(char buffer[])
{
  DATES *Date = new DATES();

  Date->top = getdouble(buffer);
  Date->bot = getdouble(&buffer[8]);
  getUnicodeString2(Date->date, &buffer[16]);

  int pos;
  while ((pos = Date->date.Pos("¦")) > 0) {
    Date->date.Delete(pos, 1);
    Date->date.Insert(" ", pos);
    }

  Date->voff = getdouble(&buffer[37]);
  d->Dates->Add(Date);
}
//---------------------------------------------------------------------------

void ReadTGF::DecodeLith126(int i, char buffer[])
{
  LITHUNIT *Lith = new LITHUNIT(clBlack);
  LITHCOMPONENT *Component = new LITHCOMPONENT;
  Lith->Top = getdouble(buffer);
  Lith->Bot = getdouble(&buffer[8]);
  Component->LithCode = getshort(&buffer[16]);
  Component->Humo   = getshort(&buffer[18]);
  Component->XShift = getdouble(&buffer[20]);
  Component->YShift = getdouble(&buffer[28]);
  Lith->LoBound = (buffer[36] == 'Y') ? true : false;
  Component->Color = d->lopt.DefaultColor;
  Lith->LoBoundColor = d->lopt.DefaultColor;
  ProcessLith(Lith, Component);
}
//---------------------------------------------------------------------------

void ReadTGF::ProcessLith(LITHUNIT* Lith, LITHCOMPONENT* Component)
{
  bool found = false;
  LITHUNIT *L;
  for (int i=0; i<d->Lithology->Count; i++) {
    L = (LITHUNIT*)d->Lithology->Items[i];
    if (Lith->Top == L->Top && Lith->Bot == L->Bot) {
      found = true;
      break; }
    }
  if (found) {
    L->Components->Add(Component);
    delete Lith;
    }
  else {
    Lith->Components->Add(Component);
    d->Lithology->Add(Lith);
    }
}
//---------------------------------------------------------------------------

void ReadTGF::DecodeLith122(int i, char buffer[])
{
  LITHUNIT *Lith = new LITHUNIT(clBlack);
  LITHCOMPONENT *Component = new LITHCOMPONENT;
  Lith->Top = getdouble(buffer);
  Lith->Bot = getdouble(&buffer[8]);
  Component->LithCode  = getshort(&buffer[16]);
  Component->Humo = getshort(&buffer[18]);
  Component->XShift = 0.0;               // added in v. 1.23
  Component->YShift = 0.0;               // added in v. 1.23
  Lith->LoBound = (buffer[36] == 'Y') ? true : false;
  Component->Color = d->lopt.DefaultColor;
  Lith->LoBoundColor = d->lopt.DefaultColor;
  ProcessLith(Lith, Component);
}
//---------------------------------------------------------------------------

void ReadTGF::DecodeLith121(int i, char buffer[])
{
  LITHUNIT *Lith = new LITHUNIT(clBlack);
  LITHCOMPONENT *Component = new LITHCOMPONENT;
  Lith->Top = getdouble(buffer);
  Lith->Bot = getdouble(&buffer[8]);
  Component->LithCode   = getshort(&buffer[16]);
  Component->Humo = 0;                 // added in v. 1.22
  Component->XShift = 0.0;               // added in v. 1.23
  Component->YShift = 0.0;               // added in v. 1.23
  Lith->LoBound = (buffer[36] == 'Y') ? true : false;
  Component->Color = d->lopt.DefaultColor;
  Lith->LoBoundColor = d->lopt.DefaultColor;
  ProcessLith(Lith, Component);
}
//---------------------------------------------------------------------------

void ReadTGF::DecodeLithKey126(int i, char buffer[])
{
  LITHKEY *LithKey = new LITHKEY();
  LithKey->Plot  = (buffer[0] == 'Y') ? true : false;
  //LithKey->LithCode  = getshort(&buffer[1]);
  LithKey->SetLithCode(getshort(&buffer[1]));
  //LithKey->Humo  = getshort(&buffer[3]);
  LithKey->SetHumo(getshort(&buffer[3]));
  LithKey->x     = getdouble(&buffer[5]);
  LithKey->y     = getdouble(&buffer[13]);
  LithKey->AutoX = buffer[21];
  LithKey->AutoY = buffer[22];
  getUnicodeString2(LithKey->LithLabel, &buffer[23]);
  LithKey->Color = d->lopt.DefaultColor;
  d->LithKeys->Add(LithKey);
}
//---------------------------------------------------------------------------

void ReadTGF::DecodeLithKey124(int i, char buffer[])
{
  LITHKEY *LithKey = new LITHKEY();
  LithKey->Plot  = true;                  // new in v. 1.25
  //LithKey->LithCode  = getshort(buffer);
  //LithKey->Humo  = getshort(&buffer[2]);
  LithKey->SetLithCode(getshort(buffer));
  LithKey->SetHumo(getshort(&buffer[2]));
  LithKey->x     = getdouble(&buffer[4]);
  LithKey->y     = getdouble(&buffer[12]);
  LithKey->AutoX = buffer[20];
  LithKey->AutoY = buffer[21];
  getUnicodeString2(LithKey->LithLabel, &buffer[22]);
  LithKey->Color = d->lopt.DefaultColor;
  d->LithKeys->Add(LithKey);
}
//---------------------------------------------------------------------------

void ReadTGF::DecodeLithKey123(int i, char buffer[])
{
  LITHKEY *LithKey = new LITHKEY();
  LithKey->Plot  = true;         // new in v. 1.25
  //LithKey->LithCode  = 0;            // new in v. 1.24
  //LithKey->Humo  = 0;            // new in v. 1.24
  LithKey->SetLithCode(0);            // new in v. 1.24
  LithKey->SetHumo(0);            // new in v. 1.24
  LithKey->x     = getdouble(buffer);
  LithKey->y     = getdouble(&buffer[8]);
  LithKey->AutoX = buffer[16];
  LithKey->AutoY = buffer[17];
  getUnicodeString2(LithKey->LithLabel, &buffer[18]);
  LithKey->Color = d->lopt.DefaultColor;
  d->LithKeys->Add(LithKey);
}
//---------------------------------------------------------------------------

void ReadTGF::DecodeText126(char buffer[])
{
  TEXTLINE *Text = new TEXTLINE();
  Text->x     = getdouble(buffer);
  Text->y     = getdouble(&buffer[8]);
  Text->angle = getdouble(&buffer[16]);
  double hite = getdouble(&buffer[24])/0.7;
  getUnicodeString2(Text->Text, &buffer[32]);

  Text->Font = DefaultFont;
  Text->Font.Height = FontHeight(hite);
  d->RandomText->Add(Text);
}
//---------------------------------------------------------------------------

int ReadTGF::ReadFile(void)
{
  infile.open(TGFileName.c_str(), ios::binary);
  if (!infile)
    {
      Message = "Cannot open file " + TGFileName + ".";
	  MessageDlg(Message, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
      return 0;
	}
  else
    {
      InputFileOpen = true;
      infile.read(buffer, 8);
      if (strncmp(buffer, "tgf ", 4) != 0) {
        Message = TGFileName + " is not a valid .tgf file.";
        MessageDlg(Message, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
        return 0;
        }
      buffer[8] = '\0';
      version = atof(&buffer[4]);

     if (version >= 1.10) {
        if (ReadTGFFile()) {
          ParentForm->StatusBar1->Panels->Items[0]->Text =
            MinimizeName(TGFileName, ParentForm->StatusBar1->Canvas,
              ParentForm->StatusBar1->Panels->Items[0]->Width);

          d->Caption = MinimizeName(TGFileName, d->Canvas, d->Width);
          }
        else {
          Message = "Error reading " + TGFileName + ".";
		  MessageDlg(Message, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
          return 0;
          }
        }
      else {
        MessageDlg("Cannot read files before version 1.10", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
        return 0;
        }
    }
  return 1;
}
//---------------------------------------------------------------------------

int ReadTGF::ReadTGFFile(void)
{
  int i, j;
  GRAPHS *graf;
  XAXIS *xax;
  DATA *dat;
  NEWYAXIS *Axis;
  short nlevs;

  if (version < 1.20) {
    infile.read(buffer, sizeof_TGN119);
    if (!infile) return 0;
    DecodeTGN119(buffer);
    }
  else if (version < 1.24) {
    infile.read(buffer, sizeof_TGN123);
    if (!infile) return 0;
    DecodeTGN123(buffer);
    }
  else {
    infile.read(buffer, sizeof_TGN126);
    if (!infile) return 0;
    DecodeTGN126(buffer);
    }

  // read colors
  if (version < 1.12) {
    infile.read(buffer, sizeof_COLORS111);
    if (!infile) return 0;
    DecodeColors111(buffer);
    }
  else {
    infile.read(buffer, sizeof_COLORS126);
    if (!infile) return 0;
    DecodeColors126(buffer);
    }

  // read line widths
  infile.read(buffer, sizeof_LINEWIDTH126);
  if (!infile) return 0;
  DecodeLineWidths126(buffer);

  // read fonts - these no longer used
  if (version < 1.13) {
    infile.read(buffer, sizeof_FONT112);
    if (!infile) return 0;
    }
  else if (version < 1.14) {
    infile.read(buffer, sizeof_FONT113);
    if (!infile) return 0;
    }
  else if (version < 1.15) {
    infile.read(buffer, sizeof_FONT114);
    if (!infile) return 0;
    }
  else {
    infile.read(buffer, sizeof_FONT126);
    if (!infile) return 0;
    }

  infile.read(buffer, sizeof_RARESPECIES126);
  if (!infile) return 0;
  DecodeRareSpecies126(buffer);

  infile.read(buffer, sizeof_DIAG_LIMITS126);
  if (!infile) return 0;
  DecodeLimits126(buffer);

  if (version < 1.21) {
    infile.read(buffer, sizeof_LITHOPTIONS120);
    if (!infile) return 0;
    DecodeLithOptions120(buffer);
    }
  else {
    infile.read(buffer, sizeof_LITHOPTIONS126);
    if (!infile) return 0;
    DecodeLithOptions126(buffer);
    }

  if (version < 1.26)  {
    infile.read(buffer, sizeof_GRAPHS125);
    if (!infile) return 0;
    DecodeGRAPHS125(buffer, &d->Default.Graph);
    }
  else {
    infile.read(buffer, sizeof_GRAPHS126);
    if (!infile) return 0;
    DecodeGRAPHS126(buffer, &d->Default.Graph);
    }

  if (version < 1.17) {
    infile.read(buffer, sizeof_XAXIS116);
    if (!infile) return 0;
    DecodeXAXIS116(buffer, &d->Default.Xaxis);
    }
  else if (version < 1.18) {
    infile.read(buffer, sizeof_XAXIS117);
    if (!infile) return 0;
    DecodeXAXIS117(buffer, &d->Default.Xaxis);
    }
  else {
    infile.read(buffer, sizeof_XAXIS126);
    if (!infile) return 0;
    DecodeXAXIS126(buffer, &d->Default.Xaxis);
    }

  if (version < 1.11) {
    infile.read(buffer, sizeof_YAXIS110);
    if (!infile) return 0;
    DecodeYAXIS110(buffer);
    }
  else if (version < 1.18) {
    infile.read(buffer, sizeof_YAXIS117);
    if (!infile) return 0;
    DecodeYAXIS117(buffer);
    }
  else if (version < 1.19) {
    infile.read(buffer, sizeof_YAXIS118);
    if (!infile) return 0;
    DecodeYAXIS118(buffer);
    }
  else {
    infile.read(buffer, sizeof_YAXIS126);
    if (!infile) return 0;
    DecodeYAXIS126(buffer);
    }

  // instantiate Axis 1
  Axis = new NEWYAXIS(1, yax, 1.0, d, n.levs);
  d->YAxes->Add(Axis);
  // instantiate Axis 2 if necessary
  if (yax.secondary > -1) {
    Axis = new NEWYAXIS(2, yax, 2.0, d, n.levs);
    d->YAxes->Add(Axis);
    }

  // read variables
  for (i=0; i<n.vars; i++) {
    if (version < 1.19) {
      infile.read(buffer, sizeof_TGVARS118);
      if (!infile) return 0;
      DecodeVarNames118(i, buffer);
      }
    else {
      infile.read(buffer, sizeof_TGVARS126);
      if (!infile) return 0;
      DecodeVarNames126(i, buffer);
      }
    }

  // read variable index
  vdx = new int [n.vars];

  for (i=0; i<n.vars; i++) {
    infile.read(buffer, sizeof_int16);
    if (!infile) return 0;
    vdx[i] = getshort(buffer);
    }

  // read samples
  for (j=0; j<n.levs; j++) {
    LEVELS *Lev = new LEVELS();
    infile.read(buffer, sizeof_SAMPLES126);
    if (!infile) return 0;
    Lev->num = getfloat(buffer);
    getUnicodeString2(Lev->name, &buffer[4]);
    d->Levs->Add(Lev);
    }

  TColor h_color = DOSColorToRGB(co.d_color, co.h_color_index);
  // read diagram heading
  for (i=0; i<4; i++)
    {
      infile.read(buffer, sizeof_TEXT_BLOCK126);
      if (!infile) return 0;
      d->heading[i].x = getdouble(buffer);
      d->heading[i].y = getdouble(&buffer[8]);
      if (i==0) {
        d->heading[i].AutoX = (d->heading[i].x < -200.0) ? true : false;
        d->heading[i].AutoY = (d->heading[i].y < -200.0) ? true : false;
        if (d->heading[i].AutoX)
          d->heading[i].x = -1000000.0;
        if (d->heading[i].AutoY)
          d->heading[i].y = -1000000.0;
        }
      else {
        d->heading[i].AutoX = d->heading[0].AutoX;
        d->heading[i].AutoY = d->heading[0].AutoY;
        }
      double hite = getdouble(&buffer[16])/0.7;
      getUnicodeString2(d->heading[i].Text, &buffer[24]);
      d->heading[i].Font = DefaultFont;
      d->heading[i].Font.Height = FontHeight(hite);
      d->heading[i].Font.Color = h_color;
    }

  // read footer
  infile.read(buffer, sizeof_TEXT_BLOCK126);
  if (!infile) return 0;
  d->footer.x = getdouble(buffer);
  d->footer.y = getdouble(&buffer[8]);
  d->footer.AutoX = (d->footer.x < -200.0) ? true : false;
  d->footer.AutoY = (d->footer.y < -200.0) ? true : false;
  if (d->footer.AutoX)
    d->footer.x = -1000000.0;
  if (d->footer.AutoY)
    d->footer.y = -1000000.0;
  double hite = getdouble(&buffer[16])/0.7;
  getUnicodeString2(d->footer.Text, &buffer[24]);
  d->footer.Font = DefaultFont;
  d->footer.Font.Height = FontHeight(hite);

  // read Graphs

  for (i=0; i<n.vars; i++)
    {
      infile.read(buffer, sizeof_int16);
      if (!infile) return 0;

      nlevs = getshort(buffer);

      if (version < 1.26) {
        infile.read(buffer, sizeof_GRAPHS125);
        if (!infile) return 0;
        graf = new GRAPHS;
        DecodeGRAPHS125(buffer, graf);
	}
      else {
        infile.read(buffer, sizeof_GRAPHS126);
        if (!infile) return 0;
        graf = new GRAPHS;
        DecodeGRAPHS126(buffer, graf);
      }

      if (version < 1.17) {
        infile.read(buffer, sizeof_XAXIS116);
        if (!infile) return 0;
        xax = new XAXIS;
        DecodeXAXIS116(buffer, xax);
        }
      else if (version < 1.18) {
        infile.read(buffer, sizeof_XAXIS117);
        if (!infile) return 0;
        xax = new XAXIS;
        DecodeXAXIS117(buffer, xax);
	}
      else {
        infile.read(buffer, sizeof_XAXIS126);
        if (!infile) return 0;
        xax = new XAXIS;
        DecodeXAXIS126(buffer, xax);
      }

      DOSDATA ddat;
      dat = new DATA [n.levs];
      for (j=0; j<n.levs; j++) {
        infile.read(buffer, sizeof_DATA126);
        if (!infile) return 0;
        dat[j].x = getfloat(buffer);
        ddat.flag.byte = buffer[4];
        dat[j].null = ddat.flag.attr.null;
        dat[j].rare = ddat.flag.attr.rare;
        }

      TGVARS *Var = (TGVARS*)Vars->Items[i];
      d->grf->Add(new GRAPH (nlevs, graf, xax, dat, Var));
    }

  ReOrderVars();

  if (n.dend) {
    infile.read(buffer, sizeof_DGROPTIONS126);
    if (!infile) return 0;
    DecodeDendOptions126(buffer);

    for (i=0; i<n.levs-1; i++) {
      infile.read(buffer, sizeof_DENDROGRAM126);
      if (!infile) return 0;
      DENDROGRAM *Cluster = new DENDROGRAM;
      DecodeDendrogram126(buffer, Cluster);
      }

    for (i=0; i<n.levs; i++) {
      infile.read(buffer, sizeof_int16);
      if (!infile) return 0;
      d->DgrOrder.push_back((int)getshort(buffer));
      }
    }

  // Group defaults
  d->Default.GroupAttr.Position = INLINE;
  d->Default.GroupAttr.Color = clBlack;
  d->Default.GroupAttr.Font = DefaultFont;
  d->Default.GroupAttr.Font.Height = FontHeight(0.35);

  for (i=0; i<n.groups; i++) {
    if (version < 1.19) {
      infile.read(buffer, sizeof_GROUP118);
      if (!infile) return 0;
      DecodeGroups118(buffer);
      }
    else {
      infile.read(buffer, sizeof_GROUP126);
      if (!infile) return 0;
      DecodeGroups126(buffer);
      }
    }

  if (n.zones > 0) {                       // read zones
    if (version < 1.16) {
      infile.read(buffer, sizeof_ZONEDEFAULT115);
      if (!infile) return 0;
      DecodeZoneDefault115(buffer);
      }
     else {
      infile.read(buffer, sizeof_ZONEDEFAULT126);
      if (!infile) return 0;
      DecodeZoneDefault126(buffer);
      }

     for (i=0; i<n.zones; i++) {
       if (version < 1.16) {
         infile.read(buffer, sizeof_ZONE115);
         if (!infile) return 0;
         DecodeZones115(buffer);
         }
       else {
         infile.read(buffer, sizeof_ZONE126);
         if (!infile) return 0;
         DecodeZones126(buffer);
         }
       }
     }
  else {  // set up zone defaults
	d->Default.ZoneAttr.ZoneStyle = LINEZONE;
	d->Default.ZoneAttr.LineStyle = SOLID_LINE;
	d->Default.ZoneAttr.Priority = ZONETOBACK;
	d->Default.ZoneAttr.ThruLabelCol = true;
	d->Default.ZoneAttr.Pattern = 1;      // not needed for line zone
	d->Default.ZoneAttr.Border = false;   // not needed for line zone
    d->Default.ZoneAttr.ZoneWidth = 0.1;      // not needed for line zone
    }

  // read zone labels
  if (n.zlabels > 0) {
    infile.read(buffer, sizeof_ZONEOPTIONS126);
    if (!infile) return 0;
    DecodeZoneOptions126(buffer);

    for (i=0; i<n.zlabels; i++) {
      infile.read(buffer, sizeof_ZONE_LABELS126);
      if (!infile) return 0;
      DecodeZoneLabels126(buffer);
      }
    }
  else {
    d->zopt.ZoneTitleAngle = 0.0;
    d->zopt.ZoneTitleXOffset = -1.0;
    d->zopt.Center = true;
    d->zopt.ZoneTitleYOffset = d->Default.Xaxis.GraphNameYOffset;
    d->zopt.ZoneTitle = "Zone";
    d->zopt.ZoneTitleFont = DefaultFont;
    d->zopt.ZoneTitleFont.Height = FontHeight(xax->GraphNameFont.Height);
    d->zopt.ZoneFont = DefaultFont;
    d->zopt.ZoneFont.Height = FontHeight(xax->GraphNameFont.Height);
    }

  // read dates
  if (n.dates > 0) {
    infile.read(buffer, sizeof_DATE_OPTIONS126);
    if (!infile) return 0;
    DecodeDateOptions126(buffer);

    for (i=0; i<n.dates; i++) {
      infile.read(buffer, sizeof_DATES126);
      if (!infile) return 0;
      DecodeDates126(buffer);
      }
    }
  else { // default dopt options
    d->dopt.DatesPosition = LEFT;
    d->dopt.DatesTitlePosition = SIDE;
    d->dopt.Angle = 90.0;
    d->dopt.DateTitleFont = DefaultFont;
    d->dopt.DateTitleFont.Height = FontHeight(0.25);
    d->dopt.DateFont = DefaultFont;
    d->dopt.DateFont.Height = FontHeight(0.2);
    d->dopt.DatesTitleTopYOffset = d->Default.Xaxis.GraphNameYOffset;
    d->dopt.Color = clBlack;
    }

   // read lith units
   if (n.lith > 0) {
     //adjust_nlith = 0;
     for (i=0; i<n.lith; i++)  {
       if (version < 1.22) {
         infile.read(buffer, sizeof_LITH121);
         if (!infile) return 0;
         DecodeLith121(i, buffer);
         }
       else if (version < 1.23) {
         infile.read(buffer, sizeof_LITH122);
         if (!infile) return 0;
         DecodeLith122(i, buffer);
         }
       else {
         infile.read(buffer, sizeof_LITH126);
         if (!infile) return 0;
         DecodeLith126(i, buffer);
         }
       }
     //d->n.lith -= adjust_nlith;
     }

  if (n.lithboxes > 0) {
    for (i=0; i<n.lithboxes; i++) {
      if (version < 1.24) {
        infile.read(buffer, sizeof_LITHKEY123);
        if (!infile) return 0;
        DecodeLithKey123(i, buffer);
        }
      else if (version < 1.25) {
        infile.read(buffer, sizeof_LITHKEY124);
        if (!infile) return 0;
        DecodeLithKey124(i, buffer);
        }
      else {
        infile.read(buffer, sizeof_LITHKEY126);
        if (!infile) return 0;
        DecodeLithKey126(i, buffer);
        }
      }
    }

  // read general text
  if (n.text > 0) {
    for (i=0; i<n.text; i++) {
      infile.read(buffer, sizeof_TEXT126);
      if (!infile) return 0;
      DecodeText126(buffer);
      }
    }

  d->file_loaded = true;

  // Allocate new Y-axes
  for (i=0; i<n.vars; i++) {
    TGVARS *Var = (TGVARS*)Vars->Items[i];
    UnicodeString TempStr = Var->code.SubString(1,6);
    if (TempStr == "#Chron" || TempStr == "#Depth") {
      bool CodeFound = false;
      for (int k=0; k<d->YAxes->Count; k++) {
        NEWYAXIS *Axis = (NEWYAXIS*)d->YAxes->Items[k];
        UnicodeString AxisCode = "#" + Axis->AxisCode;
        if (Var->code == AxisCode) {
          CodeFound = true;
          break;
          }
        }
      if (!CodeFound) {
		UnicodeString VarCode = Var->code;
        VarCode.Delete(1,1);
        Axis = new NEWYAXIS(VarCode, Var->name, yax, 2.0, d);
        d->YAxes->Add(Axis);
        }
      }
    }

  // -------------
  // This code isn't necessary, but it will allow axes in some .tgf files with
  // non-monotonic depths/ages plot
  for (int k=0; k<d->YAxes->Count; k++) {
    NEWYAXIS *Axis = (NEWYAXIS*)d->YAxes->Items[k];
    UnicodeString AxisCode = "#" + Axis->AxisCode;
    bool CodeFound = false;
    GRAPH* g;
    for (int i=0; i<d->grf->Count; i++) {
      g = (GRAPH*)d->grf->Items[i];
      if (AxisCode == g->code) {
        CodeFound = true;
        break;
        }
      }
    if (CodeFound) {
      for (int i=0; i<n.levs; i++)
        Axis->PutDepth(i, g->data[i].x);
      }
    }
  // -------------

  // End line
  d->EndLine.Color = d->Default.Xaxis.Color;
  d->EndLine.LineWidth = AxisLineWidth;

  // Name boxes
  d->NameBoxes.Color = d->Default.Xaxis.Color;
  d->NameBoxes.LineWidth = AxisLineWidth;

  return(1);
}
//---------------------------------------------------------------------------

// This function reorders the vars so that special vars are first in the list
// in the order of Depth, Chron, Thick, and Error
void ReadTGF::ReOrderVars(void)
{
  // reorder so vdx[i] == i
  for (int i=0; i<n.vars; i++) {
    if (vdx[i] != i) {
      d->grf->Move(vdx[i], i);
      int old = vdx[i];
      vdx[i] = i;
      for (int k=i+1; k<n.vars; k++)
        if (vdx[k] < old)
          vdx[k]++;
      }
    }
  
  int ip = 0;
  for (int i=0; i<n.vars; i++) {
    GRAPH* g = (GRAPH*)d->grf->Items[i];
    UnicodeString Code = g->code.SubString(1, 5);
    if (Code == "Depth")
      d->grf->Move(i, ip++);
    }

  for (int i=0; i<n.vars; i++) {
    GRAPH* g = (GRAPH*)d->grf->Items[i];
    UnicodeString Code = g->code.SubString(1, 5);
    if (Code == "Chron")
      d->grf->Move(i, ip++);
    }

  for (int i=0; i<n.vars; i++) {
    GRAPH* g = (GRAPH*)d->grf->Items[i];
    UnicodeString Code = g->code.SubString(1, 5);
    if (Code == "Thick")
      d->grf->Move(i, ip++);
    }

  for (int i=0; i<n.vars; i++) {
    GRAPH* g = (GRAPH*)d->grf->Items[i];
    UnicodeString Code = g->code.SubString(1, 5);
    if (Code == "Error")
      d->grf->Move(i, ip++);
    }

  //for (int i=0; i<n.vars; i++)
  //  vdx[i] = i;
}
//---------------------------------------------------------------------------

void ReadTGF::TranslateColors(TTGDiagram *d)
{
  TColor ForegroundColor;

  // background color
  if (co.d_color[0].red == 0.0 && co.d_color[0].green == 0.0 &&
      floor(1000.0*co.d_color[0].blue) == 777.0)
    {                   // blue default
      co.d_color[0].red   = 1.0;
      co.d_color[0].green = 1.0;
      co.d_color[0].blue  = 1.0;
      d->BackgroundColor = (TColor)RGB(255, 255, 255);
    }
  else
    d->BackgroundColor = DOSColorToRGB(co.d_color, 0);

  if (co.d_color[1].red == 1.0 && co.d_color[1].green == 1.0 &&
      co.d_color[1].blue == 1.0)
    {
      co.d_color[1].red   = 0.0;
      co.d_color[1].green = 0.0;
      co.d_color[1].blue  = 0.0;
      ForegroundColor = (TColor)RGB(0, 0, 0);
    }
  else
    ForegroundColor = DOSColorToRGB(co.d_color, 1);

  d->Default.Xaxis.Color = DOSColorToRGB(co.d_color, co.a_color_index);
  d->lopt.DefaultColor = ForegroundColor;
  d->Default.Graph.GraphColor = DOSColorToRGB(co.d_color, co.g_color_index);
  d->Default.Graph.GraphOutlineColor = d->Default.Graph.GraphColor; // new
  d->Default.Graph.ExagColor = DOSColorToRGB(co.d_color, co.e_color_index);
  d->Default.Graph.ExagOutlineColor = DOSColorToRGB(co.d_color, co.o_color_index);
  d->Default.Graph.DepthBarsColor = d->Default.Xaxis.Color;
  d->Default.Font.Color = DOSColorToRGB(co.d_color, co.t_color_index);

  d->Default.ZoneAttr.ZoneColor = DOSColorToRGB(co.d_color, co.z_color_index);
  d->Frame.Color = DOSColorToRGB(co.d_color, co.r_color_index);
  d->Default.GroupAttr.Color = DOSColorToRGB(co.d_color, co.f_color_index);  // new
}
//---------------------------------------------------------------------------

ReadTIL::ReadTIL(UnicodeString& FileName, TTilSpreadSheetForm *spr)
{
  TilFileName = FileName;
  InputFileOpen = false;
  TSSForm = spr;
}
//---------------------------------------------------------------------------

ReadTIL::~ReadTIL()
{
  if (InputFileOpen)
    infile.close();
}
//---------------------------------------------------------------------------

void ReadTIL::ReadTiliaFile(void)
{
   N n;
   VARS TilVar;
   UnicodeString Buffer;
   UnicodeString Text;
   Double X;
   DATA dat;
   DOSDATA ddat;

   infile.open(TilFileName.c_str(), ios::binary);
   if (!infile)
     throw EReadBinaryFileError("Cannot open file " + TilFileName + ".");

   UnicodeString Status = "Loading " + ExtractFileName(TilFileName);
   ParentForm->StatusBar1->Panels->Items[0]->Text = Status;
   ParentForm->StatusBar1->Repaint();

   InputFileOpen = true;

   //NOTE: CodeGuard incorrectly shows an error here: http://qc.embarcadero.com/wc/qcmain.aspx?d=46102
   infile.read(buffer, 10);

   if (!infile)
	 throw EReadBinaryFileError("Error reading " + TilFileName);

   if (strncmp(buffer, "tilia ", 5) != 0)
	 throw EReadBinaryFileError(TilFileName + " is not a valid .til file.");

   buffer[10] = '\0';
   UnicodeString Header = buffer;
   if (Header.SubString(7,4) == "v0.9")
	 version = 0.0;
   else {
	 UnicodeString Value = Header.SubString(6,5);
	 version = IntlStrToDouble::GetDouble(Value);
	 }

   if (version < 2.0)
	 throw EReadBinaryFileError(TilFileName + " less than version 2.0");

   infile.read((char*)&n, sizeof(N));
   if (!infile)
	 throw EReadBinaryFileError("Error reading " + TilFileName);

   char sum[2];
   sum[1] = '\0';

   TProfGrid *ProfGrid1 = TSSForm->ProfGrid1;
   ProfGrid1->DisableControls();
   ProfGrid1->SpreadsheetEnabled = false;

   // read vars
   try
   {
     try
     {
     for (int j=0; j<n.vars; j++) {
       infile.read(buffer, 74);
       if (!infile)
         throw EReadBinaryFileError("Error reading " + TilFileName);
       sum[0] = buffer[3];
       int row = j+3;
       while (row >= ProfGrid1->RowCount)
         ProfGrid1->RowCount += 256;
       if (sum[0] != ' ' && sum[0] != '-') {
         UnicodeString Sum(sum);
         ProfGrid1->AbsoluteCells[7][row]->Value = Sum;
         }
       getUnicodeString1(Buffer, &buffer[65]);  // VarCode
       SpecialVarCodes(Buffer);
       ProfGrid1->AbsoluteCells[1][row]->Value = Buffer;
	   getUnicodeString2(Buffer, &buffer[4]);  // VarName
       ProfGrid1->AbsoluteCells[2][row]->Value = Buffer;
       }

     // read levels
     for (int i=0; i<n.levs; i++) {
       infile.read(buffer, 15);
       if (!infile)
         throw EReadBinaryFileError("Error reading " + TilFileName);
       X = getfloat(buffer);
       getUnicodeString2(Buffer, &buffer[4]);
       int col = i+8;
       while (col >= ProfGrid1->ColCount)
         ProfGrid1->ColCount += 256;
       ProfGrid1->AbsoluteCells[col][1]->Value = X;
       if (!Buffer.IsEmpty())
         ProfGrid1->AbsoluteCells[col][2]->Value = Buffer;
       }

     // read data
     for (int j=0; j<n.vars; j++) {
       for (int i=0; i<n.levs; i++) {
         infile.read(buffer, sizeof_DATA126);
         if (!infile)
           throw EReadBinaryFileError("Error reading " + TilFileName);
         dat.x = getfloat(buffer);
         ddat.flag.byte = buffer[4];
         dat.null = ddat.flag.attr.null;
         dat.rare = ddat.flag.attr.rare;
         if (!dat.null) {
           ProfGrid1->AbsoluteCells[i+8][j+3]->Value = dat.x;
           if (dat.rare)
             ProfGrid1->AbsoluteCells[i+8][j+3]->Font->Color = tiGlobals->RareColor;
           }
         }
       }
     }
	 catch(...)
     {
     throw EReadBinaryFileError("Error reading " + TilFileName);
     }
   }
   __finally
   {
   ProfGrid1->SpreadsheetEnabled = true;
   ProfGrid1->EnableControls();
   }

   rcmax.x = n.levs+7;
   rcmax.y = n.vars+2;

   TRect r(1,3,1,rcmax.y);
   TPoint cell;

   // move thickness var to top
   if (TSSForm->FindWholeText("#Thick", ProfGrid1, r, &cell)) {
     if (cell.y > 3)
       ProfGrid1->MoveRow(cell.y, 3);
     r.Top = 4;
     }

   // move chrons to top
   int TopDataRow = r.Top;
   while (r.Bottom >= r.Top && TSSForm->FindPartialText("#Chron", ProfGrid1, r, &cell)) {
     if (cell.y > TopDataRow)
       ProfGrid1->MoveRow(cell.y, TopDataRow);
     r.Top = cell.y + 1;
     TopDataRow++;
     }

   // find super sums
   UnicodeString Sums;
   UnicodeString VarCode;
   UnicodeString GroupCode;
   vector<int> SumRows;
   int RowCount = TSSForm->AbsContentRowCount(ProfGrid1);
   for (int i=3; i<=RowCount; i++) {
     VarCode = ProfGrid1->AbsoluteCells[1][i]->Text;
     if (VarCode.SubString(1,3) == "SUM")
       SumRows.push_back(i);
     else {
       GroupCode = ProfGrid1->AbsoluteCells[7][i]->Text;
       bool found = false;
       for (int k=1; k<=Sums.Length(); k++) {
         if (GroupCode == Sums[k]) {
           found = true;
           break;
           }
         }
       if (!found)
         Sums += GroupCode;
       }
     }
   for (unsigned int i=0; i<SumRows.size(); i++) {
     int row = SumRows[i];
     VarCode = ProfGrid1->AbsoluteCells[1][row]->Text;
     bool found = false;
     for (int k=1; k<=Sums.Length(); k++) {
       if (VarCode.SubString(5,1) == Sums.SubString(k,1)) {
         found = true;
         break;
         }
       }
     if (found)
       ProfGrid1->AbsoluteCells[4][row]->Value = (WideString)"percent";
     else {
       VarCode.Insert("S", 1);
       ProfGrid1->AbsoluteCells[1][row]->Value = VarCode;
       }
     }
}
//---------------------------------------------------------------------------

bool ReadTIL::readFormVar(double *Value, UnicodeString& FieldName, UnicodeString& Text)
{
   *Value = 0.0;
   Text.SetLength(0);
   infile.read(buffer, sizeof_FORMVAR);
   if (!infile) return false;
   int type = getshort(buffer);
   int fw = (int)getushort(&buffer[8]);
   *Value = getdouble(&buffer[10]);
   if (IsNan(*Value)) *Value = 0.0;
   getUnicodeString1(FieldName, &buffer[32]);
   if (strvar(type)) {
     fw = (type == BLOBVAR) ? 256 : fw+1;
     infile.read(buffer, fw);
     if (!infile) return false;
     getUnicodeString1(Text, buffer);
     }
   return true;
}
//---------------------------------------------------------------------------

void ReadTIL::openFormFile(UnicodeString& FormFileName)
{
   if (InputFileOpen)
     infile.close();
   InputFileOpen = false;
   infile.open(FormFileName.c_str(), ios::binary);
   if (!infile)
     throw EReadBinaryFileError("Cannot open file " + FormFileName + ".");

   InputFileOpen = true;

   infile.read(buffer, sizeof_FORMVERSION);
   if (!infile)
     throw EReadBinaryFileError("Error reading " + FormFileName);

   UnicodeString Text;
   getUnicodeString1(Text, &buffer[9]);
   double version = IntlStrToDouble::GetDouble(Text);
   if (version < 1.1)
     throw EReadBinaryFileError("Cannot read version " + FloatToStr(version) +
                                " of" + FormFileName + ".");

   infile.read(buffer, sizeof_HEADER);
   if (!infile)
     throw EReadBinaryFileError("Error reading " + FormFileName);
   ReadHeader();
}
//---------------------------------------------------------------------------

void ReadTIL::ReadSMPForm(TContactList* ContactList)
{
   UnicodeString SMPFileName = ChangeFileExt(TilFileName, ".SMP");
   if (!FileExists(SMPFileName)) return;

   UnicodeString Status = "Loading " + ExtractFileName(SMPFileName);
   ParentForm->StatusBar1->Panels->Items[0]->Text = Status;
   ParentForm->StatusBar1->Repaint();

   openFormFile(SMPFileName);

   if (hdr.ext != ".SMP")
	 throw EReadBinaryFileError(SMPFileName + "is not a valid Samples Form.");

   int VarType;
   int char_record_width;
   int record_width = 0;
   int AnalystWidth;
   UnicodeString FieldName;

   for (int i=0; i<hdr.nfields; i++) {
     infile.read(buffer, sizeof_MULTIRECORD);
     if (!infile)
       throw EReadBinaryFileError("Error reading " + SMPFileName);
     VarType = getshort(buffer);
     switch (VarType)
       {
       case FLOATVAR:
       case DATEVAR:
         record_width += sizeof_DDATA;
         break;
       case CHARVAR:
         char_record_width = getshort(&buffer[4]) + 1;
         record_width += char_record_width;
         getUnicodeString1(FieldName, &buffer[18]);
         if (FieldName == "Analyst")
           AnalystWidth = char_record_width;
         break;
       case BLOBVAR:
         record_width += 256;
         break;
       }
     }

   int pos;
   unsigned short year, month, day;
   TList *SamplesMetaData = new TList;

   for (int i=0; i<hdr.nrecords; i++) {
     infile.read(buffer, record_width);
     if (!infile)
       throw EReadBinaryFileError("Error reading " + SMPFileName);
     SAMPLEMETADATA *SampleMetaData = new SAMPLEMETADATA;
     SampleMetaData->Depth = getdouble(buffer);
     pos = sizeof_DDATA;
     SampleMetaData->thickness = getdouble(&buffer[pos]);
     pos += sizeof_DDATA;
     getUnicodeString1(SampleMetaData->analyst, &buffer[pos]);
     pos += AnalystWidth;
     month = (unsigned short)getdouble(&buffer[pos]);
     pos += sizeof_DDATA;
     day = (unsigned short)getdouble(&buffer[pos]);
     pos += sizeof_DDATA;
     year = (unsigned short)getdouble(&buffer[pos]);
     if (year) {
       if (!month)
         month = 1;
       if (!day)
         day = 1;
       TDateTime DateAnalyzed(year, month, day);
       SampleMetaData->date = DateAnalyzed;
       }
     else {
       TDateTime DateAnalyzed(0);
       SampleMetaData->date = DateAnalyzed;
       }
     pos += sizeof_DDATA;
     getUnicodeString1(SampleMetaData->Notes, &buffer[pos]);
     SamplesMetaData->Add(SampleMetaData);
     }

   int thickness_row = 0;
   int analyst_row = 0;
   int date_row = 0;
   int notes_row = 0;
   int row = 4;
   SAMPLEMETADATA *SampleMetaData;
   UnicodeString VarCode, VarName;

   TProfGrid *ProfGrid1 = TSSForm->ProfGrid1;
   ProfGrid1->DisableControls();
   ProfGrid1->SpreadsheetEnabled = false;

   int i = 0;
   do {
      SampleMetaData = (SAMPLEMETADATA*)SamplesMetaData->Items[i++];
      if (!SampleMetaData->analyst.IsEmpty())
        analyst_row = row;
      } while (i < SamplesMetaData->Count && analyst_row < row);
   if (analyst_row == row) {
     ProfGrid1->InsertRow(row);
     ProfGrid1->AbsoluteCells[1][row]->Value = "#Analyst";
     ProfGrid1->AbsoluteCells[2][row]->Value = "Analyst";
     row++;
     }

   i = 0;
   do {
      SampleMetaData = (SAMPLEMETADATA*)SamplesMetaData->Items[i++];
      if ((int)SampleMetaData->date > 0)
        date_row = row;
      } while (i < SamplesMetaData->Count && date_row < row);
   if (date_row == row) {
     ProfGrid1->InsertRow(row);
     ProfGrid1->AbsoluteCells[1][row]->Value = "#DateAnal";
     ProfGrid1->AbsoluteCells[2][row]->Value = "Date analyzed";
     row++;
     }

   i = 0;
   do {
      SampleMetaData = (SAMPLEMETADATA*)SamplesMetaData->Items[i++];
      if (!SampleMetaData->Notes.IsEmpty())
        notes_row = row;
      } while (i < SamplesMetaData->Count && notes_row < row);
   if (notes_row == row) {
     ProfGrid1->InsertRow(row);
     ProfGrid1->AbsoluteCells[1][row]->Value = "#Notes";
     ProfGrid1->AbsoluteCells[2][row]->Value = "Sample notes";
     row++;
     }

   TRect r(1,3,1,rcmax.y);
   TPoint cell;

   if (TSSForm->FindWholeText("#Thick", ProfGrid1, r, &cell))
     thickness_row = cell.y;
   else {
     i = 0;
     do {
        SampleMetaData = (SAMPLEMETADATA*)SamplesMetaData->Items[i++];
        if (SampleMetaData->thickness > 0.0)
          thickness_row = row;
        } while (i < SamplesMetaData->Count && thickness_row < row);
     if (thickness_row == row) {
       ProfGrid1->InsertRow(row);
       ProfGrid1->AbsoluteCells[1][row]->Value = "#Thick";
       ProfGrid1->AbsoluteCells[2][row]->Value = "Sample thickness";
       }
     }

   CurrentSampleCol = 8;

   int col;
   UnicodeString Text;
   TStringList *AnalystCodes = new TStringList;
   for (i=0; i<ContactList->Count; i++) {
     CONTACT *contact = ContactList->Contacts[i];
     AnalystCodes->AddObject(FormAnalystCode(contact), (TObject*)contact);
     }

   bool IgnoreAnalysts = false;

   for (i=0; i<SamplesMetaData->Count; i++) {
     SampleMetaData = (SAMPLEMETADATA*)SamplesMetaData->Items[i];
     if ((col = GetSampleCol(SampleMetaData->Depth)) >= 8) {
       if (SampleMetaData->thickness > 0.0)
         ProfGrid1->AbsoluteCells[col][thickness_row]->Value = SampleMetaData->thickness;
       if (!IgnoreAnalysts && !SampleMetaData->analyst.IsEmpty()) {
         bool found = false;
         for (int j=0; j<AnalystCodes->Count; j++) {
           if (SampleMetaData->analyst == AnalystCodes->Strings[j]) {
             CONTACT *contact = (CONTACT*)AnalystCodes->Objects[j];
             ProfGrid1->AbsoluteCells[col][analyst_row]->Value = contact->ShortContactName;
             found = true;
             break;
             }
           }
         if (!found) {
           TNewAnalystForm *NewAnalystForm = new TNewAnalystForm(TSSForm);
           NewAnalystForm->Label1->Caption = "Analyst \"" + SampleMetaData->analyst + "\" not found.";
           for (int j=0; j<ContactList->Count; j++) {
             CONTACT *contact = ContactList->Contacts[j];
             NewAnalystForm->ListBox1->AddItem(contact->ShortContactName, (TObject*)contact);
             }
           int Result = NewAnalystForm->ShowModal();
           if (Result == mrOk) {
             if (NewAnalystForm->ListBox1->ItemIndex > -1) {
               CONTACT *contact = (CONTACT*)NewAnalystForm->ListBox1->Items->Objects[NewAnalystForm->ListBox1->ItemIndex];
               ProfGrid1->AbsoluteCells[col][analyst_row]->Value = contact->ShortContactName;
               }
             else if (!NewAnalystForm->LabeledEdit1->Text.IsEmpty()) {
               CONTACT *contact = new CONTACT;
               contact->FamilyName = NewAnalystForm->LabeledEdit1->Text;
               contact->LeadingInitials = NewAnalystForm->LabeledEdit2->Text;
               contact->FormatContactName();
               ContactList->Add(contact);
               //AnalystCodes->AddObject(FormAnalystCode(contact), (TObject*)contact);
               AnalystCodes->AddObject(SampleMetaData->analyst, (TObject*)contact);
               ProfGrid1->AbsoluteCells[col][analyst_row]->Value = contact->ShortContactName;
               }
             }
           else if (Result == mrAbort)
             IgnoreAnalysts = true;
           NewAnalystForm->Visible = false;
           delete NewAnalystForm;
           }
         }
       if ((int)SampleMetaData->date > 0)
         ProfGrid1->AbsoluteCells[col][date_row]->Value = SampleMetaData->date;
       if (!SampleMetaData->Notes.IsEmpty())
         ProfGrid1->AbsoluteCells[col][notes_row]->Value = SampleMetaData->Notes;
       }
     }

   tiGlobals->SSHideElements = false;
   tiGlobals->SSHideUnits = false;
   tiGlobals->SSHideContext = false;
   tiGlobals->SSHideTaphonomy = false;
   TSSForm->FormatWorksheet(ProfGrid1);

   ProfGrid1->SpreadsheetEnabled = true;
   ProfGrid1->EnableControls();
   delete AnalystCodes;
   DeleteList(SamplesMetaData);
}
//---------------------------------------------------------------------------

UnicodeString ReadTIL::FormAnalystCode(CONTACT* contact)
{
   UnicodeString AnalystCode = contact->FamilyName.SubString(1,4);
   while (AnalystCode.Length() < 4)
     AnalystCode += " ";
   for (int i=1; i<=contact->LeadingInitials.Length(); i++)
     if (contact->LeadingInitials.SubString(i,1) != "." &&
         contact->LeadingInitials.SubString(i,1) != "-")
           AnalystCode += contact->LeadingInitials.SubString(i,1);
   return AnalystCode;
}
//---------------------------------------------------------------------------

int ReadTIL::GetSampleCol(double depth)
{
   int col = -1;
   TProfGrid *ProfGrid1 = TSSForm->ProfGrid1;

   for (int i=CurrentSampleCol; i<rcmax.x; i++) {
     Variant Value = ProfGrid1->AbsoluteCells[i][1]->Value;
     if (!VarIsEmpty(Value)) {
       if (depth == Value) {
         col = i;
         CurrentSampleCol = i+1;
         break;
         }
       }
     }
   if (col == -1) {   // not yet found
     for (int i=8; i<=CurrentSampleCol; i++) {
       Variant Value = ProfGrid1->AbsoluteCells[i][1]->Value;
       if (!VarIsEmpty(Value)) {
         if (depth == Value) {
           col = i;
           CurrentSampleCol = i+1;
           break;
           }
         }
       }
     }
   return col;
}
//---------------------------------------------------------------------------

void ReadTIL::ReadAGEForm(TAgeModelList* AgeModelList, TContactList* ContactList)
{
   UnicodeString AGEFileName = ChangeFileExt(TilFileName, ".AGE");
   if (!FileExists(AGEFileName)) return;

   UnicodeString Status = "Loading " + ExtractFileName(AGEFileName);
   ParentForm->StatusBar1->Panels->Items[0]->Text = Status;
   ParentForm->StatusBar1->Repaint();

   openFormFile(AGEFileName);

   if (hdr.ext != ".AGE")
	 throw EReadBinaryFileError(AGEFileName + "is not a valid Age Basis Form.");

   int VarType;
   int char_record_width;
   int record_width = 0;
   UnicodeString FieldName;

   for (int i=0; i<hdr.nfields; i++) {
     infile.read(buffer, sizeof_MULTIRECORD);
     if (!infile)
       throw EReadBinaryFileError("Error reading " + AGEFileName);
     VarType = getshort(buffer);
     switch (VarType)
       {
       case INTVAR:
       case FLOATVAR:
         record_width += sizeof_DDATA;
         break;
       case CHARVAR:
         char_record_width = getshort(&buffer[4]) + 1;
         record_width += char_record_width;
         break;
       }
     }

   int NextChronNumber;
   int ChronNumber = -9999;
   int pos;
   UnicodeString RCode;
   AGEMODEL *AgeModel;

   bool LookupOpened = OpenLookupFile();

   for (int i=0; i<hdr.nrecords; i++) {
     infile.read(buffer, record_width);
     if (!infile)
       throw EReadBinaryFileError("Error reading " + AGEFileName);
     NextChronNumber = (int)getdouble(buffer);
     if (NextChronNumber != ChronNumber) {
       ChronNumber = NextChronNumber;
       AgeModel = new AGEMODEL();
       AgeModel->ChronNumber = ChronNumber;
       AgeModelList->Add(AgeModel);
       }
     CHRON *ChronControl = new CHRON();
     pos = sizeof_DDATA;
     ChronControl->Depth = getdouble(&buffer[pos]);
     pos += sizeof_DDATA;
     ChronControl->Thickness = getdouble(&buffer[pos]);
     pos += sizeof_DDATA;
     ChronControl->AgeValue = getdouble(&buffer[pos]);
     pos += sizeof_DDATA;
     ChronControl->AgeLimitOlder = getdouble(&buffer[pos]);
     pos += sizeof_DDATA;
     ChronControl->AgeLimitYounger = getdouble(&buffer[pos]);
     pos += sizeof_DDATA;
     if (ChronControl->AgeLimitOlder < ChronControl->AgeValue)
	   ChronControl->AgeLimitOlder = Unassigned();
	 if (ChronControl->AgeLimitYounger > ChronControl->AgeValue)
	   ChronControl->AgeLimitYounger = Unassigned();
	 if ((ChronControl->AgeLimitOlder == 0 || ChronControl->AgeLimitOlder.IsEmpty()) &&
		 (ChronControl->AgeLimitYounger == 0 || ChronControl->AgeLimitYounger.IsEmpty()) &&
         ChronControl->AgeValue != 0) {
	   ChronControl->AgeLimitOlder = Unassigned();
	   ChronControl->AgeLimitYounger = Unassigned();
	   }
     getUnicodeString1(RCode, &buffer[pos]);
     if (LookupOpened)
       ChronControl->ControlType = TranslateRCode(RCode);
	 AgeModel->ChronControls->Add(ChronControl);
     }

   UnicodeString CHRFileName = ChangeFileExt(TilFileName, ".CHR");
   if (!FileExists(CHRFileName)) return;

   Status = "Loading " + ExtractFileName(CHRFileName);
   ParentForm->StatusBar1->Panels->Items[0]->Text = Status;
   ParentForm->StatusBar1->Repaint();

   openFormFile(CHRFileName);

   if (hdr.ext != ".CHR")
     throw EReadBinaryFileError(AGEFileName + "is not a valid Age Basis Form.");

   record_width = 0;
   int NameWidth, PreparedByWidth, ModelWidth;

   for (int i=0; i<hdr.nfields; i++) {
     infile.read(buffer, sizeof_MULTIRECORD);
     if (!infile)
       throw EReadBinaryFileError("Error reading " + CHRFileName);
     VarType = getshort(buffer);
     switch (VarType)
       {
       case INTVAR:
       case DATEVAR:
         record_width += sizeof_DDATA;
         break;
       case CHARVAR:
         char_record_width = getshort(&buffer[4]) + 1;
         record_width += char_record_width;
         getUnicodeString1(FieldName, &buffer[18]);
         if (FieldName == "Name")
           NameWidth = char_record_width;
         else if (FieldName == "PreparedBy")
           PreparedByWidth = char_record_width;
         else if (FieldName == "Model")
           ModelWidth = char_record_width;
         break;
       case BLOBVAR:
         record_width += 256;
         break;
       case YNVAR:
         record_width += 2;
         break;
       }
     }

   char yn;
   UnicodeString Text;
   unsigned short year, month, day;

   for (int i=0; i<hdr.nrecords; i++) {
     infile.read(buffer, record_width);
     if (!infile)
       throw EReadBinaryFileError("Error reading " + CHRFileName);
     int ChronNumber = (int)getdouble(buffer);
     bool ChronNumberFound = false;
     for (int j=0; j<AgeModelList->Count; j++) {
       AgeModel = AgeModelList->AgeModels[j];
       if (ChronNumber == AgeModel->ChronNumber) {
         ChronNumberFound = true;
         break;
         }
       }
     if (!ChronNumberFound) continue;
     pos = sizeof_DDATA;
     yn = buffer[pos];
     AgeModel->Default = (yn == 'Y') ? true : false;
     pos += 2;
     getUnicodeString1(Text, &buffer[pos]);
     AgeModel->ChronologyName = Text;
     pos += NameWidth;
     getUnicodeString1(Text, &buffer[pos]);
     SetPreparer(Text, AgeModel, ContactList);
     pos += PreparedByWidth;
     month = (unsigned short)getdouble(&buffer[pos]);
     pos += sizeof_DDATA;
     day = (unsigned short)getdouble(&buffer[pos]);
     pos += sizeof_DDATA;
     year = (unsigned short)getdouble(&buffer[pos]);
     if (year) {
       if (!month)
         month = 1;
       if (!day)
         day = 1;
       TDateTime DatePrepared(year, month, day);
	   //AgeModel->DatePrepared = (double)DatePrepared;
	   AgeModel->DatePrepared = DatePrepared;
	   }
     pos += sizeof_DDATA;
	 getUnicodeString1(Text, &buffer[pos]);
     AgeModel->AgeModel = Text;
     pos += ModelWidth;
     getUnicodeString1(Text, &buffer[pos]);
     AgeModel->Notes = Text;
     }
}
//---------------------------------------------------------------------------

void ReadTIL::SetPreparer(UnicodeString& Preparer, AGEMODEL* AgeModel, TContactList* ContactList)
{
   UnicodeString Name;
   CONTACT* preparer = new CONTACT();

   if (Preparer == "COHMAP")
     Preparer = "Cooperative Holocene Mapping Project";

   int LastPeriod = Preparer.LastDelimiter(".");
   if (LastPeriod) {
     int len = Preparer.Length();
     if (Preparer.SubString(len-2,3) == "Jr.") {
       preparer->Suffix = "Jr.";
       Name = Preparer.SubString(1,len-3);
       }
     else if (Preparer.SubString(len-1,2) == "Jr") {
       preparer->Suffix = "Jr.";
       Name = Preparer.SubString(1,len-2);
       }
     else if (Preparer.SubString(len,1) == "I") {
       preparer->Suffix = "I";
       Name = Preparer.SubString(1,len-1);
       }
     else if (Preparer.SubString(len-1,2) == "II") {
       preparer->Suffix = "II";
       Name = Preparer.SubString(1,len-2);
       }
     else if (Preparer.SubString(len-1,2) == "III") {
       preparer->Suffix = "III";
       Name = Preparer.SubString(1,len-3);
       }
     else if (Preparer.SubString(len-1,2) == "IV") {
       preparer->Suffix = "IV";
       Name = Preparer.SubString(1,len-2);
       }
     else
       Name = Preparer;
     Name = Name.TrimRight();
     if (Name.LastDelimiter(",") == Name.Length())
       Name.SetLength(Name.Length()-1);
	 int CommaPos = Name.Pos(",");
	 UnicodeString FirstName;
	 UnicodeString FamilyName;
     if (CommaPos) {
       FamilyName = Name.SubString(1,CommaPos-1);
       FirstName = Name.SubString(CommaPos+1,Name.Length()-CommaPos);
       }
     else {
       LastPeriod = Name.LastDelimiter(".");
       FamilyName = Name.SubString(LastPeriod+1,Name.Length()-LastPeriod);
       FamilyName = FamilyName.Trim();
       FirstName = Name.SubString(1,LastPeriod);
	   while (FamilyName.Pos(" ")) {
         int pos = FamilyName.Pos(" ");
         FirstName += (" " + FamilyName.SubString(1,pos-1));
         FamilyName = FamilyName.SubString(pos+1, FamilyName.Length()-pos);
         }
       }
     preparer->FamilyName = FamilyName;
     FirstName = FirstName.Trim();
	 UnicodeString Initials;
     UnicodeString GivenNames;
     while (FirstName.Length()) {
       if (FirstName.SubString(2,1) == ".") {
         Initials += FirstName.SubString(1,2);
         if (GivenNames.Length()) {
           if (GivenNames.LastDelimiter(".") == GivenNames.Length())
             GivenNames += FirstName.SubString(1,2);
           else
             GivenNames += (" " + FirstName.SubString(1,2));
           }
         else
           GivenNames += FirstName.SubString(1,2);
         if (FirstName.Length() > 2) {
           FirstName = FirstName.SubString(3,FirstName.Length()-2);
           FirstName = FirstName.TrimLeft();
           }
         else
           FirstName.SetLength(0);
         }
	   else if (FirstName.Pos(" ")) {
         int pos = FirstName.Pos(" ");
         GivenNames += (" " + FirstName.SubString(1,pos-1));
         Initials += (FirstName.SubString(1,1) + ".");
         FirstName = FirstName.SubString(pos+1,FirstName.Length()-pos);
         }
       else {
         GivenNames += (" " + FirstName);
         Initials += (FirstName.SubString(1,1) + ".");
         FirstName.SetLength(0);
         }
       }
     GivenNames = GivenNames.TrimLeft();  
     if (Initials.Length())
       preparer->LeadingInitials = Initials;
     if (GivenNames.Length())
       preparer->GivenNames = GivenNames;
     }
   else
     preparer->FamilyName = Preparer;

   preparer->FormatContactName();
   AgeModel->PreparersComboBoxText = preparer->ShortContactName;
   
   CONTACT *contact;
   bool found = false;
   for (int i=0; i<ContactList->Count; i++) {
     contact = ContactList->Contacts[i];
     if (contact->FullContactName == preparer->FullContactName) {
       found = true;
       break;
       }
     }

   if (found) {
     delete preparer;
	 AgeModel->Preparers.push_back(contact);
	 }
   else {
	 ContactList->Add(preparer);
	 AgeModel->Preparers.push_back(preparer);
     }

}
//---------------------------------------------------------------------------

bool ReadTIL::OpenLookupFile(void)
{
   UnicodeString FilePathName;
   try {
	   FilePathName = TSSForm->SetXMLFileName("Lookup.xml");
       LookUp = TSSForm->GetXMLFilePtr();
       //LookUp->Config("CodePage=0");
	   LookUp->ParseFile(FilePathName);
       return true;
       }
   catch(...) {
	   MessageDlg("Cannot open Lookup.xml.", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
       return false;
       }
}
//---------------------------------------------------------------------------

UnicodeString ReadTIL::TranslateRCode(UnicodeString& RCode)
{
   UnicodeString ChronControl;
   RCode = RCode.UpperCase();

   if (RCode == "TOP")
     ChronControl = "Core top";
   else if (RCode == "C14" || RCode == "C13")
     ChronControl = "Radiocarbon";
   else if (RCode == "TEF")
     ChronControl = "Tephra";
   else if (RCode == "CAV")
     ChronControl = "Radiocarbon, average of two or more dates";
   else if (RCode == "OTH")
     ChronControl = "Other";
   else if (RCode == "POL")
     ChronControl = "Biostratigraphic, pollen";
   else if (RCode == "GUE")
     ChronControl = "Guess";
   else if (RCode == "SED")
     ChronControl = "Sediment stratigraphic";
   else if (RCode == "PB2")
      ChronControl = "Lead-210";
   else if (RCode == "EXT")
     ChronControl = "Extrapolated";
   else if (RCode == "ANL")
     ChronControl = "Annual laminations (varves)";
   else if (RCode == "BOT")
     ChronControl = "Core bottom";
   else if (RCode == "CAJ")
     ChronControl = "Radiocarbon, reservoir correction";
   else if (RCode == "CAL" || RCode == "DEN" || RCode == "CCA")
     ChronControl = "Radiocarbon, calibrated";
   else if (RCode == "COM")
     ChronControl = "Interpolated, corrected for compaction";
   else if (RCode == "DGL")
     ChronControl = "Deglaciation";
   else if (RCode == "INT")
     ChronControl = "Interpolated";
   else if (RCode == "RCY")
     ChronControl = "Radiocarbon, calibrated from calendar years";
   else if (RCode == "THL")
     ChronControl = "Thermoluminescence";
   else if (RCode == "USE")
     ChronControl = "Uranium-series";
   else if (RCode == "MAG")
     ChronControl = "Paleomagnetic";
   else if (RCode == "AAR")
     ChronControl = "Argon-argon";
   else if (RCode == "KAR")
     ChronControl = "Potassium-argon";
   else if (RCode == "ESH")
     ChronControl = "European settlement horizon";
   else if (RCode == "AMR")
     ChronControl = "Ambrosia rise";
   else if (RCode == "SAL")
     ChronControl = "Salsola rise";
   else if (RCode == "TSD")
     ChronControl = "Tsuga decline";
   else if (RCode == "CSR")
     ChronControl = "Casuarina rise";
   else if (RCode == "ATL")
     ChronControl = "Beginning of the Atlantic";
   else if (RCode == "HOL")
     ChronControl = "Beginning of the Holocene";
   else if (RCode == "LST")
     ChronControl = "Laarcher See";
   else if (RCode == "MAZ")
     ChronControl = "Mazama";
   return ChronControl;
}
//---------------------------------------------------------------------------

void ReadTIL::ReadLOIForm(void)
{
   UnicodeString LOIFileName = ChangeFileExt(TilFileName, ".LOI");
   if (!FileExists(LOIFileName)) return;

   UnicodeString Status = "Loading " + ExtractFileName(LOIFileName);
   ParentForm->StatusBar1->Panels->Items[0]->Text = Status;
   ParentForm->StatusBar1->Repaint();

   openFormFile(LOIFileName);

   if (hdr.ext != ".LOI")
     throw EReadBinaryFileError(LOIFileName + "is not a valid Loss-on-ignition Form.");

   int record_width = 0;

   for (int i=0; i<hdr.nfields; i++) {
     infile.read(buffer, sizeof_MULTIRECORD);
     if (!infile)
       throw EReadBinaryFileError("Error reading " + LOIFileName);
     record_width += sizeof_DDATA;
     }

   int pos;
   double dVal;
   int temp_org;
   int temp_carb;
   set<int> temporg;
   set<int> tempcarb;

   int row = 1;
   for (int i=0; i<hdr.nrecords; i++) {
	 infile.read(buffer, record_width);
	 if (!infile)
	   throw EReadBinaryFileError("Error reading " + LOIFileName);
	 //LOISAMPLE* LOISample = new LOISAMPLE();
	 dVal = getdouble(buffer);   // depth
	 TSSForm->AdvColumnGrid5->AllCells[1][row] = dVal;
	 pos = sizeof_DDATA;
	 dVal = getdoubleNan(&buffer[pos]);  // thickness
	 if (!IsNan(dVal))
	   TSSForm->AdvColumnGrid5->AllCells[2][row] = dVal;
	 pos += sizeof_DDATA;
	 dVal = getdoubleNan(&buffer[pos]);   // TempOrg
	 if (!IsNan(dVal)) {
	   temp_org = (int)dVal;
	   temporg.insert(temp_org);
	   TSSForm->AdvColumnGrid5->AllCells[3][row] = temp_org;
	   }
	 pos += sizeof_DDATA;
	 dVal = getdoubleNan(&buffer[pos]);   // LOIOrganic
	 if (!IsNan(dVal))
	   TSSForm->AdvColumnGrid5->AllCells[4][row] = dVal;
	 pos += sizeof_DDATA;
	 dVal = getdoubleNan(&buffer[pos]);  // TempCarb
	 if (!IsNan(dVal)) {
	   temp_carb = (int)dVal;
	   tempcarb.insert(temp_carb);
	   TSSForm->AdvColumnGrid5->AllCells[5][row] = temp_carb;
	   }
	 pos += sizeof_DDATA;
	 dVal = getdoubleNan(&buffer[pos]);  // LOICarb
	 if (!IsNan(dVal))
	   TSSForm->AdvColumnGrid5->AllCells[6][row] = dVal;
	 pos += sizeof_DDATA;
	 dVal = getdoubleNan(&buffer[pos]);  // BulkDens
	 if (!IsNan(dVal))
	   TSSForm->AdvColumnGrid5->AllCells[7][row] = dVal;
	 pos += sizeof_DDATA;
	 row++;
	 //LOIList->Add(LOISample);
	 }

   //if (!LOIList->Count) return;
   if (row == 1) return;


   //LOISAMPLE* LOISample = LOIList->LOISamples[0];
   //int temp_org = LOISample->TempOrganic;
   //int temp_carb = LOISample->TempCarbonate;
   /*
   for (int i=1; i<LOIList->Count; i++) {
	 LOISAMPLE* LOISample = LOIList->LOISamples[i];
	 if (LOISample->TempOrganic != temp_org) {
	   temp_org = -2;
	   break;
	   }
	 }
   */
   switch (temporg.size()) {
	 case 0:
	   temp_org = -1;
	   break;
	 case 1:
	   temp_org = *(temporg.begin());
	   break;
	 default:
	   temp_org = -2;
	   break;
	 }

   SetTempComboBox(TSSForm->ComboBox7, temp_org);
   //TSSForm->loiTempOrganic->Visible =
   //  (TSSForm->ComboBox7->ItemIndex == 1) ? true : false;
   if (TSSForm->ComboBox7->ItemIndex == 1)
	 TSSForm->AdvColumnGrid5->HideColumn(3);
   /*
   for (int i=1; i<LOIList->Count; i++) {
	 LOISAMPLE* LOISample = LOIList->LOISamples[i];
	 if (LOISample->TempCarbonate != temp_carb) {
	   temp_carb = -2;
	   break;
	   }
	 }
   */
   switch (tempcarb.size()) {
	 case 0:
	   temp_carb = -1;
	   break;
	 case 1:
	   temp_carb = *(tempcarb.begin());
	   break;
	 default:
	   temp_carb = -2;
	   break;
	 }

   SetTempComboBox(TSSForm->ComboBox8, temp_carb);
   //TSSForm->loiTempCarbonate->Visible =
   //	 (TSSForm->ComboBox8->ItemIndex == 1) ? true : false;
   if (TSSForm->ComboBox8->ItemIndex == 1)
	 TSSForm->AdvColumnGrid5->HideColumn(5);

   if (TSSForm->Datasets[0].Investigators.size() > 0)
	 TSSForm->loi.Investigators = TSSForm->Datasets[0].Investigators;
}
//---------------------------------------------------------------------------

void ReadTIL::SetTempComboBox(TComboBox* ComboBox, int temp)
{
   if (temp == -2)
     ComboBox->ItemIndex = 1;  // variable
   else if (temp == -1)
     ComboBox->ItemIndex = 0;  // unknown
   else {
	 UnicodeString tempstr = IntToStr(temp);
     int index = ComboBox->Items->IndexOf(tempstr);
     if (index == -1) {
       bool done = false;
       for (int i=2; i<ComboBox->Items->Count; i++) {
         int temp2 = StrToInt(ComboBox->Items->Strings[i]);
         if (temp < temp2) {
           ComboBox->Items->Insert(i, tempstr);
           done = true;
           break;
           }
         }
       if (!done)
         ComboBox->Items->Add(tempstr);
       ComboBox->ItemIndex = ComboBox->Items->IndexOf(tempstr);
       }
     else
       ComboBox->ItemIndex = index;
     }
}
//---------------------------------------------------------------------------

void ReadTIL::ReadPB2Form(TGeochronList* GeochronList)
{
   UnicodeString PB2FileName = ChangeFileExt(TilFileName, ".PB2");
   if (!FileExists(PB2FileName)) return;

   UnicodeString Status = "Loading " + ExtractFileName(PB2FileName);
   ParentForm->StatusBar1->Panels->Items[0]->Text = Status;
   ParentForm->StatusBar1->Repaint();

   openFormFile(PB2FileName);

   if (hdr.ext != ".PB2")
     throw EReadBinaryFileError(PB2FileName + "is not a valid Lead-210 Form.");

   int VarType;
   int char_record_width;
   int record_width = 0;
   int MaterialDatedWidth;
   UnicodeString FieldName;

   for (int i=0; i<hdr.nfields; i++) {
     infile.read(buffer, sizeof_MULTIRECORD);
     if (!infile)
       throw EReadBinaryFileError("Error reading " + PB2FileName);
     VarType = getshort(buffer);
     switch (VarType)
       {
       case FLOATVAR:
         record_width += sizeof_DDATA;
         break;
       case CHARVAR:
         char_record_width = getshort(&buffer[4]) + 1;
         record_width += char_record_width;
		 getUnicodeString1(FieldName, &buffer[18]);
         if (FieldName == "MaterialDated")
           MaterialDatedWidth = char_record_width;
         break;
       case BLOBVAR:
         record_width += 256;
         break;
       case YNVAR:
		 record_width += 2;
		 break;
	   }
	 }

   char yn, c;
   UnicodeString Text;
   int pos;

   for (int i=0; i<hdr.nrecords; i++) {
	 infile.read(buffer, record_width);
	 if (!infile)
	   throw EReadBinaryFileError("Error reading " + PB2FileName);
	 GEOCHRON Date;
	 Date.Depth = getdouble(buffer);
	 pos = sizeof_DDATA;
	 Date.Thickness = getdouble(&buffer[pos]);
	 pos += sizeof_DDATA;
	 Date.Age = getdouble(&buffer[pos]);
	 pos += sizeof_DDATA;
	 Date.StdDev = getdouble(&buffer[pos]);
	 if (Date.StdDev == 0)
	   Date.StdDev = Unassigned();
	 Date.ErrorOlder = Date.StdDev;
	 Date.ErrorYounger = Date.StdDev;
	 pos += sizeof_DDATA;
	 yn = buffer[pos];
	 pos += 2;
	 Date.GreaterThan = (yn == 'Y') ? true : false;
	 if (Date.GreaterThan) {
	   Date.StdDev = Unassigned();
	   Date.ErrorOlder = Unassigned();
	   Date.ErrorYounger = Unassigned();
	   }
	 getUnicodeString1(Text, &buffer[pos]);
	 pos += MaterialDatedWidth;
	 Date.MaterialDated = Text;
	 getUnicodeString1(Text, &buffer[pos]);
	 Date.Notes = Text;

	 // extra fields not in PB2 form
	 Date.Method = "Lead-210";
	 Date.AgeUnits = "Calendar years AD/BC";
	 Date.Sigma = 1;  // make negative to indicate null?

	 GeochronList->Add(Date);
	 }
}
//---------------------------------------------------------------------------

void ReadTIL::ReadC14Form(TGeochronList* GeochronList)
{
   UnicodeString C14FileName = ChangeFileExt(TilFileName, ".C14");
   if (!FileExists(C14FileName)) return;

   UnicodeString Status = "Loading " + ExtractFileName(C14FileName);
   ParentForm->StatusBar1->Panels->Items[0]->Text = Status;
   ParentForm->StatusBar1->Repaint();

   openFormFile(C14FileName);

   if (hdr.ext != ".C14")
     throw EReadBinaryFileError(C14FileName + "is not a valid Radiocarbon Form.");

   int VarType;
   int char_record_width;
   int record_width = 0;
   int LabNumberWidth, BasisWidth, MaterialDatedWidth;
   UnicodeString FieldName;

   for (int i=0; i<hdr.nfields; i++) {
     infile.read(buffer, sizeof_MULTIRECORD);
     if (!infile)
       throw EReadBinaryFileError("Error reading " + C14FileName);
     VarType = getshort(buffer);
     switch (VarType)
       {
       case FLOATVAR:
         record_width += sizeof_DDATA;
         break;
       case CHARVAR:
         char_record_width = getshort(&buffer[4]) + 1;
         record_width += char_record_width;
		 getUnicodeString1(FieldName, &buffer[18]);
         if (FieldName == "LabNumber")
           LabNumberWidth = char_record_width;
         else if (FieldName == "Basis")
           BasisWidth = char_record_width;
         else if (FieldName == "MaterialDated")
           MaterialDatedWidth = char_record_width;
         break;
       case BLOBVAR:
         record_width += 256;
         break;
       case YNVAR:
         record_width += 2;
         break;
       }
     }

   char yn, c;
   UnicodeString Text;
   int pos;

   for (int i=0; i<hdr.nrecords; i++) {
     infile.read(buffer, record_width);
     if (!infile)
       throw EReadBinaryFileError("Error reading " + C14FileName);
	 //GEOCHRON *Date = new GEOCHRON();
	 GEOCHRON Date;
	 Date.Depth = getdouble(buffer);
     pos = sizeof_DDATA;
	 Date.Thickness = getdouble(&buffer[pos]);
     pos += sizeof_DDATA;
	 Date.Age = getdouble(&buffer[pos]);
     pos += sizeof_DDATA;
	 Date.ErrorOlder = getdouble(&buffer[pos]);
     pos += sizeof_DDATA;
	 Date.ErrorYounger = getdouble(&buffer[pos]);
     if (Date.ErrorOlder == Date.ErrorYounger)
	   Date.StdDev = (!Date.ErrorOlder.IsEmpty()) ? Date.ErrorOlder : Unassigned();
	 else
	   Date.StdDev = Unassigned();
	 pos += sizeof_DDATA;
	 yn = buffer[pos];
     pos += 2;
	 Date.GreaterThan = (yn == 'Y') ? true : false;
     if (Date.GreaterThan) {
	   Date.StdDev = Unassigned();
	   Date.ErrorOlder = Unassigned();
       Date.ErrorYounger = Unassigned();
       }
	 getUnicodeString1(Text, &buffer[pos]);
     pos += LabNumberWidth;
	 Date.LabNumber = Text;
     getUnicodeString1(Text, &buffer[pos]);
	 pos += BasisWidth;
	 if (Text == "A") {
	   Date.Method = "Carbon-14";
	   Date.Parameters[L"Method"] = 1;
	   }
	 else if (Text == "G") {
	   Date.Method = "Carbon-14";
	   Date.Parameters[L"Method"] = 3;
	   }
	 else if (Text == "L") {
	   Date.Method = "Carbon-14";
	   Date.Parameters[L"Method"] = 4;
	   }
	 else {
	   Date.Method = "Carbon-14";
	   Date.Parameters[L"Method"] = 2;
	   }
	 pos += 2;  // Enriched Y/N

	 double Delta13C;
	 Delta13C = getdouble(&buffer[pos]);
	 if (Delta13C != 0.0)
	   Date.Parameters[L"δ13C"] = Delta13C;

	 pos += sizeof_DDATA;
	 getUnicodeString1(Text, &buffer[pos]);
	 pos += MaterialDatedWidth;
	 Date.MaterialDated = Text;
     getUnicodeString1(Text, &buffer[pos]);
     Date.Notes = Text;

     // extra fields not in C14 form
     Date.AgeUnits = "Radiocarbon years BP";
     Date.Sigma = 1;  // make negative to indicate null?

     GeochronList->Add(Date);
     }
}
//---------------------------------------------------------------------------

void ReadTIL::ReadLTHForm(TLithologyUnitList* LithologyUnitList)
{
   UnicodeString LthFileName = ChangeFileExt(TilFileName, ".LTH");
   if (!FileExists(LthFileName)) return;

   UnicodeString Status = "Loading " + ExtractFileName(LthFileName);
   ParentForm->StatusBar1->Panels->Items[0]->Text = Status;
   ParentForm->StatusBar1->Repaint();

   openFormFile(LthFileName);

   if (hdr.ext != ".LTH")
     throw EReadBinaryFileError(LthFileName + "is not a valid Lithology Form.");

   int VarType;
   int record_width = 2*sizeof_DDATA;
   int Descript_width;
   int nCharRecords = 0;
   for (int i=0; i<hdr.nfields; i++) {
     infile.read(buffer, sizeof_MULTIRECORD);
     if (!infile)
       throw EReadBinaryFileError("Error reading " + LthFileName);
     VarType = getshort(buffer);
     if (VarType == CHARVAR) {
       int char_record_width = getshort(&buffer[4]) + 1;
       record_width += char_record_width;
       if (nCharRecords == 0) {
         Descript_width = char_record_width;
         nCharRecords++;
         }
       }
     }

   double DepthTopCM;
   double DepthBotCM;
   UnicodeString Descript;
   UnicodeString LoBoundary;

   for (int i=0; i<hdr.nrecords; i++) {
     infile.read(buffer, record_width);
     if (!infile)
       throw EReadBinaryFileError("Error reading " + LthFileName);
     DepthTopCM = getdouble(buffer);
     DepthBotCM = getdouble(&buffer[9]);
	 getUnicodeString1(Descript, &buffer[18]);
	 getUnicodeString1(LoBoundary, &buffer[18+Descript_width]);
     LITHOLOGYUNIT *LithUnit = new LITHOLOGYUNIT(DepthTopCM, DepthBotCM,
          Descript, LoBoundary);
     LithologyUnitList->Add(LithUnit);
     }
}
//---------------------------------------------------------------------------

void ReadTIL::ReadPUBForm(TList* Publications)
{
   UnicodeString PubFileName = ChangeFileExt(TilFileName, ".PUB");
   if (!FileExists(PubFileName)) return;

   UnicodeString Status = "Loading " + ExtractFileName(PubFileName);
   ParentForm->StatusBar1->Panels->Items[0]->Text = Status;
   ParentForm->StatusBar1->Repaint();

   openFormFile(PubFileName);

   if (hdr.ext != ".PUB")
     throw EReadBinaryFileError(PubFileName + "is not a valid Publications Form.");

   int VarType;
   int record_width = sizeof_DDATA;
   for (int i=0; i<hdr.nfields; i++) {
     infile.read(buffer, sizeof_MULTIRECORD);
     if (!infile)
       throw EReadBinaryFileError("Error reading " + PubFileName);
     VarType = getshort(buffer);
     if (VarType == CHARVAR)
       record_width += (getshort(&buffer[4]) + 1);
     }

   int old_publ_no = -999;
   int publ_no = -999;
   UnicodeString line;
   UnicodeString Citation;
   for (int i=0; i<hdr.nrecords; i++) {
     infile.read(buffer, record_width);
     if (!infile)
       throw EReadBinaryFileError("Error reading " + PubFileName);
     publ_no = (int)getdouble(buffer);
	 getUnicodeString1(line, &buffer[9]);
     if (publ_no != old_publ_no) {
       if (old_publ_no >= 0) {
         PUBLICATION *pub = new PUBLICATION(NOTSELECTED);
		 pub->Citation = Citation;
		 pub->pub_type = LEGACY;
         Publications->Add(pub);
         }
       Citation = line;
       old_publ_no = publ_no;
       }
     else {
       Citation += " ";
       Citation += line;
       }
     }
   if (publ_no >= 0 && !Citation.IsEmpty()) {
     PUBLICATION *pub = new PUBLICATION(NOTSELECTED);
	 pub->Citation = Citation;
	 pub->pub_type = LEGACY;
     Publications->Add(pub);
     }
}
//---------------------------------------------------------------------------

bool ReadTIL::ReadSITForm(SITE* site, COLLECTION& collection, DATASET* dataset,
                          TContactList* ContactList)
{
   UnicodeString SiteFileName = ChangeFileExt(TilFileName, ".SIT");
   if (!FileExists(SiteFileName)) return false;

   UnicodeString Status = "Loading " + ExtractFileName(SiteFileName);
   ParentForm->StatusBar1->Panels->Items[0]->Text = Status;
   ParentForm->StatusBar1->Repaint();

   openFormFile(SiteFileName);

   if (hdr.ext != ".SIT")
     throw EReadBinaryFileError(SiteFileName + "is not a valid Site Form.");

   double Value;
   UnicodeString Text;
   UnicodeString FieldName;
   double LatDeg;
   double LatMin;
   double LatSec;
   UnicodeString LatNS;
   double LonDeg;
   double LonMin;
   double LonSec;
   UnicodeString LonEW;
   UnicodeString SiteDescript;
   UnicodeString Physiography;
   UnicodeString SurroundVeg;
   UnicodeString Descriptor;
   UnicodeString LocalVeg;
   UnicodeString Notes;
   UnicodeString CollLastName;
   UnicodeString CollInitials;
   UnicodeString ContLastName;
   UnicodeString ContInitials;
   double DepthAtLoc;
   double CoreDiamCM;
   int SampYear;
   int SampMonth;
   int SampDay;
   bool IsCore = false;
   bool IsSect = false;
   bool IsSSamp = false;
   unsigned short year, month, day;
   map<UnicodeString, UnicodeString> DepEnv;
   DepEnv["AERI"] = "Sampler";
   DepEnv["AAIR"] = "Air Pollen sampler";
   DepEnv["COAS"] = "Coastal";
   DepEnv["CEST"] = "Estuarine";
   DepEnv["CSLT"] = "Salt Marsh";
   DepEnv["FLUV"] = "Fluvial";
   DepEnv["HOLL"] = "Small Hollow";
   DepEnv["HVER"] = "Vernal Pool";
   DepEnv["LRES"] = "Reservoir";
   DepEnv["LSTK"] = "Stock Pond";
   DepEnv["LOTH"] = "Natural Lake (Origin Unknown)";
   DepEnv["LDRA"] = "Drained Lake";
   DepEnv["LFLU"] = "Fluvial Origin Lake";
   DepEnv["LGLA"] = "Glacial Origin Lake";
   DepEnv["LKET"] = "Kettle Lake";
   DepEnv["LGSC"] = "Glacial Scour Lake";
   DepEnv["LCIR"] = "Cirque Lake";
   DepEnv["LMOR"] = "Morainally Dammed Lake";
   DepEnv["LGMC"] = "Glacial Meltwater Channel Lake";
   DepEnv["LPER"] = "Periglacial Origin Lake";
   DepEnv["LTHK"] = "Thermokarst Lake";
   DepEnv["LSOL"] = "Solution Origin Lake";
   DepEnv["LVOL"] = "Volcanic Origin Lake";
   DepEnv["LEXP"] = "Explosion Crater Lake";
   DepEnv["LUNK"] = "Natural Lake (Origin Unknown)";
   DepEnv["LPRO"] = "Proglacial Lake";
   DepEnv["LPLY"] = "Playa";
   DepEnv["PTRP"] = "Pollen Trap (Terrestrial)";
   DepEnv["PTLK"] = "Pollen Trap (Lacustrine)";
   DepEnv["TLUS"] = "Loess";
   DepEnv["TMIR"] = "Mire";
   DepEnv["TBOG"] = "Bog";
   DepEnv["TBLA"] = "Blanket Bog";
   DepEnv["TRAI"] = "Raised Bog";
   DepEnv["TFEN"] = "Fen";
   DepEnv["TVAL"] = "Valley Mire";
   DepEnv["TSOL"] = "Soligenous Mire";
   DepEnv["TOWT"] = "Open-water Transition Mire";
   DepEnv["TFLO"] = "Floating Mire";
   DepEnv["TFLP"] = "Floodplain Mire";
   DepEnv["TSWA"] = "Swamp";
   DepEnv["TMOS"] = "Moss Polster";
   DepEnv["TMSH"] = "Marsh";
   DepEnv["ABUR"] = "Archaeological Burial";
   DepEnv["AMID"] = "Archaeological Midden";
   DepEnv["AMOU"] = "Archaeological Mound";
   DepEnv["AOCD"] = "Occupational Debris";
   DepEnv["ARCH"] = "Archaeological";
   DepEnv["BDNG"] = "Dung";
   DepEnv["BGUT"] = "Animal Gut Contents";
   DepEnv["BIOL"] = "Biological";
   DepEnv["BMID"] = "Animal Midden";
   DepEnv["BMOS"] = "Moss Polster";
   DepEnv["BMRT"] = "Packrat (Neotoma) Midden";
   DepEnv["BORD"] = "Organic Detritus";
   DepEnv["BSFO"] = "Surficial Fossil";
   DepEnv["BSGP"] = "Surficial Fossil in Growth Position";
   DepEnv["BSSF"] = "Surficial Fossil Float";
   DepEnv["EMNG"] = "Mangrove Swamp";
   DepEnv["EMSH"] = "Salt Marsh";
   DepEnv["ESTU"] = "Estuarine";
   DepEnv["LABO"] = "Borrow Pit";
   DepEnv["LACU"] = "Lacustrine";
   DepEnv["LARS"] = "Reservoir";
   DepEnv["LART"] = "Artificial Lake";
   DepEnv["LAST"] = "Stock Pond";
   DepEnv["LBEA"] = "Lacustrine Beach";
   DepEnv["LDDM"] = "Dune Dammed Lake";
   DepEnv["LNAT"] = "Natural Lake";
   DepEnv["LNDR"] = "Drained Lake";
   DepEnv["LNFB"] = "Backwater Lake";
   DepEnv["LNFL"] = "Fluvial Origin Lake";
   DepEnv["LNFO"] = "Nonspecific Floodplain Lake";
   DepEnv["LNFX"] = "Oxbow Lake";
   DepEnv["LNGC"] = "Cirque Lake";
   DepEnv["LNGD"] = "Moraine Dammed Lake";
   DepEnv["LNGK"] = "Kettle Lake";
   DepEnv["LNGL"] = "Glacial Origin Lake";
   DepEnv["LNGM"] = "Glacial Meltwater Channel Lake";
   DepEnv["LNGP"] = "Proglacial Lake";
   DepEnv["LNGS"] = "Glacial Scour Lake";
   DepEnv["LNLD"] = "Landslide Origin Lake";
   DepEnv["LNPE"] = "Periglacial Origin Lake";
   DepEnv["LNPL"] = "Playa";
   DepEnv["LNPT"] = "Thermokarst Lake";
   DepEnv["LNSL"] = "Solution Origin Lake";
   DepEnv["LNTC"] = "Tectonic Origin Lake";
   DepEnv["LNUN"] = "Natural Lake (Origin Unknown)";
   DepEnv["LNVE"] = "Explosion Crater Lake";
   DepEnv["LNVO"] = "Volcanic Origin Lake";
   DepEnv["LNWD"] = "Deflation Basin Lake";
   DepEnv["LNWI"] = "Interdunal Lake";
   DepEnv["LNWN"] = "Wind Origin Lake";
   DepEnv["MARI"] = "Marine";
   DepEnv["MCBA"] = "Coastal Bar";
   DepEnv["MCBE"] = "Marine Beach";
   DepEnv["MCOA"] = "Coastal";
   DepEnv["MDEL"] = "Submerged Marine Delta";
   DepEnv["MDSE"] = "Deep Sea Benthic";
   DepEnv["MLBE"] = "Marine Littoral Benthic";
   DepEnv["MWCP"] = "Marine Wave-cut Platform";
   DepEnv["OTHR"] = "Other";
   DepEnv["PALU"] = "Palustrine";
   DepEnv["PBLA"] = "Blanket Bog";
   DepEnv["PBOG"] = "Bog";
   DepEnv["PBRA"] = "Raised Bog";
   DepEnv["PFEN"] = "Fen";
   DepEnv["PFIB"] = "Iron Bog";
   DepEnv["PFLO"] = "Floating Mire";
   DepEnv["PFLP"] = "Floodplain Mire";
   DepEnv["PFOW"] = "Open-water Transition Mire";
   DepEnv["PFSL"] = "Soligenous Mire";
   DepEnv["PFVL"] = "Valley Mire";
   DepEnv["PMIR"] = "Mire";
   DepEnv["PMSH"] = "Marsh";
   DepEnv["POND"] = "Pond";
   DepEnv["PPHO"] = "Small Hollow";
   DepEnv["PPHV"] = "Vernal Pool";
   DepEnv["PSWA"] = "Swamp";
   DepEnv["RCUT"] = "Stream-cut Exposure";
   DepEnv["RFAR"] = "Arroyo";
   DepEnv["RFBR"] = "Braided Stream";
   DepEnv["RFBV"] = "Beaver Dam";
   DepEnv["RFCB"] = "River Bar";
   DepEnv["RFCH"] = "River Channel";
   DepEnv["RFCL"] = "Channel Lag";
   DepEnv["RFCP"] = "Point Bar";
   DepEnv["RFCS"] = "Crevasse Splay";
   DepEnv["RFDL"] = "Delta";
   DepEnv["RFFL"] = "Floodplain";
   DepEnv["RFLU"] = "Fluvial";
   DepEnv["RFLV"] = "Natural Levee";
   DepEnv["RFME"] = "Meander Belt";
   DepEnv["RFTE"] = "River Terrace";
   DepEnv["RFWA"] = "Wadi";
   DepEnv["RIVR"] = "Riverine";
   DepEnv["SAIR"] = "Air Pollen Sampler";
   DepEnv["SAMP"] = "Sampler";
   DepEnv["SPAS"] = "Asphalt";
   DepEnv["SPCO"] = "Spring Conduit";
   DepEnv["SPRI"] = "Spring";
   DepEnv["SPTU"] = "Tufa";
   DepEnv["STLA"] = "Pollen Trap (Lacustrine)";
   DepEnv["STRP"] = "Pollen Trap";
   DepEnv["STTE"] = "Pollen Trap (Terrestrial)";
   DepEnv["STTT"] = "Tauber Trap";
   DepEnv["TADL"] = "Deflation Lag";
   DepEnv["TADU"] = "Dune";
   DepEnv["TAEO"] = "Aeolian";
   DepEnv["TALO"] = "Loess";
   DepEnv["TASS"] = "Sand Sheet";
   DepEnv["TCAV"] = "Cave";
   DepEnv["TCDU"] = "Cave Dung Deposit";
   DepEnv["TCFI"] = "Fissure";
   DepEnv["TCHZ"] = "Horizontal Cave Passage";
   DepEnv["TCLT"] = "Lava Tube";
   DepEnv["TCPT"] = "Pit Cave";
   DepEnv["TCRS"] = "Rock Shelter";
   DepEnv["TCSI"] = "Sinkhole";
   DepEnv["TERR"] = "Terrestrial";
   DepEnv["TGCF"] = "Colluvial Fan";
   DepEnv["TGCO"] = "Colluvium";
   DepEnv["TGFL"] = "Unspecified Gravity Flow";
   DepEnv["TGLA"] = "Glacial";
   DepEnv["TGLD"] = "Glacial Diamicton";
   DepEnv["TGLO"] = "Glacial Outwash";
   DepEnv["TGLP"] = "Proglacial Lake";
   DepEnv["TGLT"] = "Glacial Till";
   DepEnv["TGRA"] = "Gravity";
   DepEnv["TGSL"] = "Slump";
   DepEnv["TMOR"] = "Mor Humus";
   DepEnv["TPAL"] = "Paleosol";
   DepEnv["TPOB"] = "Buried Organic Bed";
   DepEnv["TSOI"] = "Soil";
   DepEnv["TVAF"] = "Ash Fall";
   DepEnv["TVDF"] = "Volcanic Debris Fall";
   DepEnv["TVLF"] = "Lava Flow";
   DepEnv["TVOL"] = "Volcanic";
   DepEnv["TVNA"] = "Nuee Ardente";
   DepEnv["UNKN"] = "Unknown";

   for (int i=0; i<hdr.nfields; i++) {
     if (!readFormVar(&Value, FieldName, Text))
	   throw EReadBinaryFileError("Error reading " + SiteFileName);

     if (FieldName == "SiteName")
       site->SiteName = Text;
     else if (FieldName == "LatDeg")
       LatDeg = Value;
     else if (FieldName == "LatMin")
       LatMin = Value;
     else if (FieldName == "LatSec")
       LatSec = Value;
     else if (FieldName == "LatNS")
       LatNS = Text;
     else if (FieldName == "LonDeg")
       LonDeg = Value;
     else if (FieldName == "LonMin")
       LonMin = Value;
     else if (FieldName == "LonSec")
       LonSec = Value;
     else if (FieldName == "LonEW")
       LonEW = Text;
     else if (FieldName == "AreaOfSite")
       site->Area = Value;
     else if (FieldName == "Elevation")
	   site->Altitude = Value;
	 else if (FieldName == "PolDiv1") {
	   if (Text == "USA")
		 site->Country = "United States";
	   else
		 site->Country = Text;
	   }
	 else if (FieldName == "PolDiv2Name")
	   site->State = Text;
	 else if (FieldName == "PolDiv3Name")
	   site->County = Text;
	 else if (FieldName == "SiteDescript")
	   SiteDescript = Text;
	 else if (FieldName == "Physiography")
	   Physiography = Text;
	 else if (FieldName == "SurroundVeg")
	   SurroundVeg = Text;
	 else if (FieldName == "Sigle")
	   collection.Handle = Text.UpperCase();
	 else if (FieldName == "Name")
       collection.CollectionName = Text;
     else if (FieldName == "EntLoc")
       collection.Location = Text;
     else if (FieldName == "DepthAtLoc")
       DepthAtLoc = Value;
     else if (FieldName == "Descriptor")
       Descriptor = Text;
     else if (FieldName == "SampDevice")
       collection.CollectionDevice = Text;
     else if (FieldName == "CoreDiamCM")
       CoreDiamCM = Value;
     else if (FieldName == "SampYear")
       year = (unsigned short)Value;
     else if (FieldName == "SampMonth")
       month = (unsigned short)Value;
     else if (FieldName == "SampDay")
       day = (unsigned short)Value;
     else if (FieldName == "IsCore") {
       if (Text == "Y") IsCore = true; }
     else if (FieldName == "IsSect") {
       if (Text == "Y") IsSect = true; }
     else if (FieldName == "IsSSamp") {
       if (Text == "Y") IsSSamp = true; }
     else if (FieldName == "LocalVeg")
       LocalVeg = Text;
     else if (FieldName == "Notes")
       Notes = Text;
     else if (FieldName == "CollLastName")
       CollLastName = Text;
     else if (FieldName == "CollInitials")
       CollInitials = Text;
     else if (FieldName == "ContLastName")
       ContLastName = Text;
     else if (FieldName == "ContInitials")
       ContInitials = Text;
     }

   if (year) {
     if (!month) month = 1;
     if (!day) day = 1;
     TDateTime Date(year, month, day);
	 //collection.CollDate = (double)Date;
     collection.CollDate = Date;
	 }

   LATLONG LatNorth;
   LatNorth.set_dd(LatDeg, LatMin, LatSec, LatNS);
   site->LatNorth = LatNorth.dd();
   site->LatSouth = site->LatNorth;

   LATLONG LongWest;
   LongWest.set_dd(LonDeg, LonMin, LonSec, LonEW);
   site->LongWest = LongWest.dd();
   site->LongEast = site->LongWest;

   if (!SiteDescript.IsEmpty()) {
	 site->SiteDescription = SiteDescript + ".";
	 site->SiteDescription = Capitalize(site->SiteDescription);
	 }

   if (!Physiography.IsEmpty()) {
	 if (!site->SiteDescription.IsEmpty())
	   site->SiteDescription += " ";
	 site->SiteDescription += ("Physiography: " + Physiography + ".");
	 }
   if (!SurroundVeg.IsEmpty()) {
	 if (!site->SiteDescription.IsEmpty())
	   site->SiteDescription += " ";
     site->SiteDescription += ("Surrounding vegetation: " + SurroundVeg + ".");
     }

   if (IsCore & !IsSect)
     collection.CollectionType = "Sediment core";
   else if (!IsCore & IsSect)
     collection.CollectionType = "Sediment section";
   else if (IsCore && IsSect)
     collection.CollectionType = "Composite sediment";
   else if (!IsCore && !IsSect && IsSSamp)
     collection.CollectionType = "Modern";
   dataset->IsSSamp = IsSSamp;

   if (!Notes.IsEmpty())
     collection.Notes = Notes;

   Text = LocalVeg.LowerCase();
   if (Text == "open water")
     LocalVeg.SetLength(0);
   if (!LocalVeg.IsEmpty()) {
     if (dataset->Notes.IsEmpty())
       dataset->Notes = "Local vegetation: " + LocalVeg + ".";
     else {
       if (dataset->Notes.SubString(dataset->Notes.Length(), 1) != ".")
         dataset->Notes += ".";
       dataset->Notes += (" Local vegetation: " + LocalVeg + ".");
       }
     }

   if (!ContLastName.IsEmpty()) {
     CONTACT* contact = new CONTACT();
     contact->FamilyName = ContLastName;
     if (!ContInitials.IsEmpty())
       contact->LeadingInitials = ContInitials;
     contact->FormatContactName();
     ContactList->Add(contact);
	 //dataset->Investigators->Add(contact);
	 dataset->Investigators.push_back(contact);
	 }

   CONTACT* Collector;
   if (!CollLastName.IsEmpty()) {
     CONTACT* contact = new CONTACT();
     contact->FamilyName = CollLastName;
     if (!CollInitials.IsEmpty())
       contact->LeadingInitials = CollInitials;
	 contact->FormatContactName();
     bool found = false;
     for (int i=0; i<ContactList->Count; i++) {
       Collector = ContactList->Contacts[i];
       if (Collector->FullContactName == contact->FullContactName) {
         found = true;
         break;
         }
       }
     if (found) {
       delete contact;
	   //collection.Collectors->Add(Collector);
	   collection.Collectors.push_back(Collector);
	   }
	 else {
	   ContactList->Add(contact);
	   //collection.Collectors->Add(contact);
	   collection.Collectors.push_back(contact);
       }
     }

   if (!Descriptor.IsEmpty()) {
	 //if(DepEnv.find(Descriptor.c_str()) != DepEnv.end())
	 //  collection.DepEnv = DepEnv[Descriptor.c_str()].data();
	 if(DepEnv.find(Descriptor) != DepEnv.end())
	   collection.DepEnv = DepEnv[Descriptor];
	 }

   if (!collection.Location.IsEmpty()) {
     if (DepthAtLoc > 0.0)
       collection.Location += (" (water depth = " + FloatToStr(DepthAtLoc/100) + "m)" );
     }

   if (!collection.CollectionDevice.IsEmpty()) {
     if (CoreDiamCM > 0.0)
       collection.CollectionDevice += (" (" + FloatToStr(CoreDiamCM) + "cm)" );
     }

   return true;
}
//---------------------------------------------------------------------------

void ReadTIL::ReadHeader(void)
{
   UnicodeString ext;
   getUnicodeString1(ext, &buffer[80]);
   hdr.ext = ext.UpperCase();
   hdr.seqnum = getshort(&buffer[126]);
   hdr.formtype = getshort(&buffer[128]);
   hdr.nfields = getshort(&buffer[130]);
   hdr.ntext = getshort(&buffer[132]);
   hdr.fleft = getshort(&buffer[134]);
   hdr.fright = getshort(&buffer[136]);
   hdr.ftop = getshort(&buffer[138]);
   hdr.fbottom = getshort(&buffer[140]);
   hdr.clrscr = getshort(&buffer[142]);
   hdr.maxrecords = getshort(&buffer[144]);
   hdr.nrecords = getshort(&buffer[146]);
}
//---------------------------------------------------------------------------



