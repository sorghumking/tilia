//---------------------------------------------------------------------------

#ifndef TIdmspanH
#define TIdmspanH

#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <StdCtrls.hpp>
#ifndef TGUtilsH
#include "TGUtils.h"
#endif

//---------------------------------------------------------------------------
class DMSPANEL
{
private:
   TForm *Form;
   TToolButton *ToolButton1;
   TToolButton *ToolButton2;
   TToolButton *ToolButton3;
   TLabeledEdit *LabeledEdit1;
   TLabeledEdit *LabeledEdit2;
   TLabeledEdit *LabeledEdit3;
   TLabeledEdit *LabeledEdit4;
   TLabeledEdit *LabeledEdit5;
   TLabeledEdit *LabeledEdit6;
   TComboBox *ComboBox1;

public:
   short DMSStyle;
   LATLONG latlong;
   int type;

public:
   DMSPANEL(TForm *frm, TToolButton *tb1, TToolButton *tb2, TToolButton *tb3,
       TLabeledEdit *le1, TLabeledEdit *le2, TLabeledEdit *le3, TLabeledEdit *le4,
       TLabeledEdit *le5, TLabeledEdit *le6, TComboBox *cb)
         { Form = frm; ToolButton1 = tb1; ToolButton2 = tb2; ToolButton3 = tb3;
           LabeledEdit1 = le1; LabeledEdit2 = le2; LabeledEdit3 = le3;
           LabeledEdit4 = le4; LabeledEdit5 = le5; LabeledEdit6 = le6;
           ComboBox1 = cb; }
   void initialize(short, double, int);
   void activate(void);
   void dclick(void);
   void dmclick(void);
   void dmsclick(void);
   void dexit(void);
   void dmdexit(void);
   void dmmexit(void);
   void dmsdexit(void);
   void dmsmexit(void);
   void dmssexit(void);
   double GetDD(void);
};
//---------------------------------------------------------------------------


#endif
