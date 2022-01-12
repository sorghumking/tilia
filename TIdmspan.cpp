//---------------------------------------------------------------------------
#include <vcl.h>
#include "pch.h"
#include <Math.hpp>
#pragma hdrstop

#include "TIdmspan.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

void DMSPANEL::initialize(short dms_style, double lat_long, int lat_or_long)
{
   DMSStyle = dms_style;
   if (IsNan(lat_long))
     latlong.reset();
   else
     latlong.set_dd(lat_long);
   type = lat_or_long;
   LabeledEdit1->Text = "";
   LabeledEdit2->Text = "";
   LabeledEdit3->Text = "";
   LabeledEdit4->Text = "";
   LabeledEdit5->Text = "";
   LabeledEdit6->Text = "";

   switch (DMSStyle)
   {
     case 0:
       ToolButton1->Down = true;
       ToolButton2->Down = false;
       ToolButton3->Down = false;
       ToolButton1->Marked = true;
       ToolButton2->Marked = false;
       ToolButton3->Marked = false;
       LabeledEdit1->Visible = true;
       LabeledEdit2->Visible = false;
       LabeledEdit3->Visible = false;
       LabeledEdit4->Visible = false;
       LabeledEdit5->Visible = false;
       LabeledEdit6->Visible = false;
       if (!IsNan(lat_long))
         LabeledEdit1->Text = fabs(latlong.dd());
       break;
     case 1:
       ToolButton2->Down = true;
       ToolButton1->Down = false;
       ToolButton3->Down = false;
       ToolButton2->Marked = true;
       ToolButton1->Marked = false;
       ToolButton3->Marked = false;
       LabeledEdit1->Visible = false;
       LabeledEdit2->Visible = true;
       LabeledEdit3->Visible = true;
       LabeledEdit4->Visible = false;
       LabeledEdit5->Visible = false;
       LabeledEdit6->Visible = false;
       if (!IsNan(lat_long)) {
         LabeledEdit2->Text = latlong.deg();
         LabeledEdit3->Text = latlong.dmin();
         }
       break;
     case 2:
       ToolButton3->Down = true;
       ToolButton1->Down = false;
       ToolButton2->Down = false;
       ToolButton3->Marked = true;
       ToolButton1->Marked = false;
       ToolButton2->Marked = false;
       LabeledEdit1->Visible = false;
       LabeledEdit2->Visible = false;
       LabeledEdit3->Visible = false;
       LabeledEdit4->Visible = true;
       LabeledEdit5->Visible = true;
       LabeledEdit6->Visible = true;
       if (!IsNan(lat_long)) {
         LabeledEdit4->Text = latlong.deg();
         LabeledEdit5->Text = latlong.min();
         LabeledEdit6->Text = latlong.dsec();
         }
       break;
   }

   if (ComboBox1) {
     if (type == LATITUDE) {
       ComboBox1->Items->Clear();
       ComboBox1->Items->Add("N");
       ComboBox1->Items->Add("S");
       if (IsNan(lat_long))
         ComboBox1->ItemIndex = 0;
       else
         ComboBox1->ItemIndex = (lat_long >= 0.0) ? 0 : 1;
       }
     else {
       ComboBox1->Items->Clear();
       ComboBox1->Items->Add("E");
       ComboBox1->Items->Add("W");
       if (IsNan(lat_long))
         ComboBox1->ItemIndex = 0;
       else
         ComboBox1->ItemIndex = (lat_long >= 0.0) ? 0 : 1;
       }
     }
}
//---------------------------------------------------------------------------

void DMSPANEL::dclick(void)
{
   DMSStyle = 0;
   ToolButton1->Down = true;
   ToolButton2->Down = false;
   ToolButton3->Down = false;
   ToolButton1->Marked = true;
   ToolButton2->Marked = false;
   ToolButton3->Marked = false;
   LabeledEdit2->Visible = false;
   LabeledEdit3->Visible = false;
   LabeledEdit4->Visible = false;
   LabeledEdit5->Visible = false;
   LabeledEdit6->Visible = false;
   if (latlong.is_set())
     LabeledEdit1->Text = fabs(latlong.dd());
   LabeledEdit1->Visible = true;
   //Form->FocusControl(LabeledEdit1);
}
//---------------------------------------------------------------------------

void DMSPANEL::dmclick(void)
{
   DMSStyle = 1;
   ToolButton1->Down = false;
   ToolButton2->Down = true;
   ToolButton3->Down = false;
   ToolButton1->Marked = false;
   ToolButton2->Marked = true;
   ToolButton3->Marked = false;
   LabeledEdit1->Visible = false;
   LabeledEdit4->Visible = false;
   LabeledEdit5->Visible = false;
   LabeledEdit6->Visible = false;
   if (latlong.is_set()) {
     LabeledEdit2->Text = latlong.deg();
     LabeledEdit3->Text = latlong.dmin();
     }
   LabeledEdit2->Visible = true;
   LabeledEdit3->Visible = true;
   //Form->FocusControl(LabeledEdit2);
}
//---------------------------------------------------------------------------

void DMSPANEL::dmsclick(void)
{
   DMSStyle = 2;
   ToolButton1->Down = false;
   ToolButton2->Down = false;
   ToolButton3->Down = true;
   ToolButton1->Marked = false;
   ToolButton2->Marked = false;
   ToolButton3->Marked = true;
   LabeledEdit1->Visible = false;
   LabeledEdit2->Visible = false;
   LabeledEdit3->Visible = false;
   if (latlong.is_set()) {
     LabeledEdit4->Text = latlong.deg();
     LabeledEdit5->Text = latlong.min();
     LabeledEdit6->Text = latlong.dsec();
     }
   LabeledEdit4->Visible = true;
   LabeledEdit5->Visible = true;
   LabeledEdit6->Visible = true;
   //Form->FocusControl(LabeledEdit4);
}
//---------------------------------------------------------------------------

void DMSPANEL::dexit(void)
{
   UnicodeString DegStr, MinStr, SecStr;
   DegStr = LabeledEdit1->Text;

   if (DegStr.IsEmpty())
     latlong.reset();
   else if (!latlong.set_dd(DegStr, MinStr, SecStr, false, type))
     //Form->FocusControl(LabeledEdit1);
     Beep();
}
//---------------------------------------------------------------------------

void DMSPANEL::dmdexit(void)
{
   UnicodeString DegStr, MinStr, SecStr;
   DegStr = LabeledEdit2->Text;
   MinStr = LabeledEdit3->Text;

   if (DegStr.IsEmpty() && MinStr.IsEmpty())
     latlong.reset();
   else if (!latlong.set_dd(DegStr, MinStr, SecStr, false, type))
     //Form->FocusControl(LabeledEdit2);
     Beep();
}
//---------------------------------------------------------------------------

void DMSPANEL::dmmexit(void)
{
   UnicodeString DegStr, MinStr, SecStr;
   DegStr = LabeledEdit2->Text;
   MinStr = LabeledEdit3->Text;

   if (DegStr.IsEmpty() && MinStr.IsEmpty())
     latlong.reset();
   else if (!latlong.set_dd(DegStr, MinStr, SecStr, false, type))
     //Form->FocusControl(LabeledEdit3);
     Beep();
}
//---------------------------------------------------------------------------

void DMSPANEL::dmsdexit(void)
{
   UnicodeString DegStr, MinStr, SecStr;
   DegStr = LabeledEdit4->Text;
   MinStr = LabeledEdit5->Text;
   SecStr = LabeledEdit6->Text;

   if (DegStr.IsEmpty() && MinStr.IsEmpty() && SecStr.IsEmpty())
     latlong.reset();
   else if (!latlong.set_dd(DegStr, MinStr, SecStr, false, type))
     //Form->FocusControl(LabeledEdit4);
     Beep();
}
//---------------------------------------------------------------------------

void DMSPANEL::dmsmexit(void)
{
   UnicodeString DegStr, MinStr, SecStr;
   DegStr = LabeledEdit4->Text;
   MinStr = LabeledEdit5->Text;
   SecStr = LabeledEdit6->Text;

   if (DegStr.IsEmpty() && MinStr.IsEmpty() && SecStr.IsEmpty())
     latlong.reset();
   else if (!latlong.set_dd(DegStr, MinStr, SecStr, false, type))
     //Form->FocusControl(LabeledEdit5);
     Beep();
}
//---------------------------------------------------------------------------

void DMSPANEL::dmssexit(void)
{
   UnicodeString DegStr, MinStr, SecStr;
   DegStr = LabeledEdit4->Text;
   MinStr = LabeledEdit5->Text;
   SecStr = LabeledEdit6->Text;

   if (DegStr.IsEmpty() && MinStr.IsEmpty() && SecStr.IsEmpty())
     latlong.reset();
   else if (!latlong.set_dd(DegStr, MinStr, SecStr, false, type))
     //Form->FocusControl(LabeledEdit6);
     Beep();
}
//---------------------------------------------------------------------------

void DMSPANEL::activate(void)
{
   switch (DMSStyle) {
     case 0:
       Form->FocusControl(LabeledEdit1);
       break;
     case 1:
       Form->FocusControl(LabeledEdit2);
       break;
     case 2:
       Form->FocusControl(LabeledEdit4);
       break;
     }
}
//---------------------------------------------------------------------------

double DMSPANEL::GetDD(void)
{
   double dd;
   if (latlong.is_set()) {
     dd = latlong.dd();
     if (!IsNan(dd)) {
       if (ComboBox1->ItemIndex == 1)
         dd *= -1;
       }
     }
   else
     dd = NaN;
   return dd;
}
//---------------------------------------------------------------------------
