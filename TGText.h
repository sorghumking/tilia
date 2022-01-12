//---------------------------------------------------------------------------
#ifndef TGTextH
#define TGTextH
//---------------------------------------------------------------------------
#ifndef TGraphicH
#include "TGraphic.h"
#endif
#include "ipwxmlp.h"

class MyText
{
private:
  double angle;
  double ssheight;
  double x, y;
  double TextVertOffset;
  UINT VertTextAlign, HorzTextAlign;
  int bkcolor;
  MYFONT Font;
  UnicodeString Text;
  MyGraphics *Picture;

public:
  MyText(double, double, MYFONT&, double, UINT, UINT, UnicodeString, MyGraphics *);
  MyText(MYFONT&, UnicodeString, MyGraphics *);
  //MyText(TextObject *, MyGraphics *);
  MyText(TextObject&, MyGraphics*);
  void TextOut(void);
  double Length(void);
  double TestLength(void);
  void SetXY(double X, double Y) { x = X; y = Y; }
  void MaxXY(double *, double *);
  void SetHeight(double h)
    { Font.Height = h; ssheight = Font.Height*2.0/3.0; };
  void SetBackGroundColor(int bkco) { bkcolor = bkco; }
  void DisplayText(int, double, double, double);

private:
  void Toggle(char);
  void Toggle(UnicodeString&);
  void SetAlignment(UINT, UINT);
  //void GetTextBox(double, double, DblPoint **, UnicodeString);
  void GetTextBox(double, double, vector<DblPoint>&, UnicodeString);
  void SetFont(void);
  void DeleteFont(void);
  bool FontCmp(LOGFONT &lf1, LOGFONT &lf2);
  void TextOut1(double, double, UnicodeString);
  void TextOut2(double, double, UnicodeString, double *, double *);
  double Length1(UnicodeString, bool);
  void RotatePoint(double, DblPoint&, DblPoint&, DblPoint&);
  void TranslateGreek(UnicodeString&);
  void TransGreekChar(UnicodeString&, UnicodeString, UnicodeString);
  void ConvertEntityReferences(UnicodeString&);
};

//---------------------------------------------------------------------------
#endif
