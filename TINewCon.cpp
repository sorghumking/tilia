//---------------------------------------------------------------------------

#include <vcl.h>
#include "pch.h"
#pragma hdrstop

#include "TINewCon.h"
#ifndef TIContacH
#include "TIContac.h"
#endif
#ifndef TIUpContactH
#include "TIUpContact.h"
#endif
//#ifndef TIXMLH
//#include "TIXML.h"
//#endif
//#ifndef TIGlobalsH
//#include "TIGlobals.h"
//#endif
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "ipwCore"
#pragma link "ipwxmlp"
#pragma link "ipworks"
#pragma link "cxButtons"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "dxSkinBlack"
#pragma link "dxSkinBlue"
#pragma link "dxSkinBlueprint"
#pragma link "dxSkinCaramel"
#pragma link "dxSkinCoffee"
#pragma link "dxSkinDarkRoom"
#pragma link "dxSkinDarkSide"
#pragma link "dxSkinDevExpressDarkStyle"
#pragma link "dxSkinDevExpressStyle"
#pragma link "dxSkinFoggy"
#pragma link "dxSkinGlassOceans"
#pragma link "dxSkinHighContrast"
#pragma link "dxSkiniMaginary"
#pragma link "dxSkinLilian"
#pragma link "dxSkinLiquidSky"
#pragma link "dxSkinLondonLiquidSky"
#pragma link "dxSkinMcSkin"
#pragma link "dxSkinMetropolis"
#pragma link "dxSkinMetropolisDark"
#pragma link "dxSkinMoneyTwins"
#pragma link "dxSkinOffice2007Black"
#pragma link "dxSkinOffice2007Blue"
#pragma link "dxSkinOffice2007Green"
#pragma link "dxSkinOffice2007Pink"
#pragma link "dxSkinOffice2007Silver"
#pragma link "dxSkinOffice2010Black"
#pragma link "dxSkinOffice2010Blue"
#pragma link "dxSkinOffice2010Silver"
#pragma link "dxSkinOffice2013DarkGray"
#pragma link "dxSkinOffice2013LightGray"
#pragma link "dxSkinOffice2013White"
#pragma link "dxSkinPumpkin"
#pragma link "dxSkinsCore"
#pragma link "dxSkinsDefaultPainters"
#pragma link "dxSkinSeven"
#pragma link "dxSkinSevenClassic"
#pragma link "dxSkinSharp"
#pragma link "dxSkinSharpPlus"
#pragma link "dxSkinSilver"
#pragma link "dxSkinSpringTime"
#pragma link "dxSkinStardust"
#pragma link "dxSkinSummer2008"
#pragma link "dxSkinTheAsphaltWorld"
#pragma link "dxSkinValentine"
#pragma link "dxSkinVS2010"
#pragma link "dxSkinWhiteprint"
#pragma link "dxSkinXmas2008Blue"
#pragma link "dxSkinOffice2016Colorful"
#pragma link "dxSkinOffice2016Dark"
#pragma link "dxSkinVisualStudio2013Blue"
#pragma link "dxSkinVisualStudio2013Dark"
#pragma link "dxSkinVisualStudio2013Light"
#pragma resource "*.dfm"
TNewContactForm *NewContactForm;
//---------------------------------------------------------------------------
__fastcall TNewContactForm::TNewContactForm(CONTACT** contact, TComponent* Owner)
		: TForm(Owner)
{
   Contact = contact;
   *Contact = NULL;
}
//---------------------------------------------------------------------------

__fastcall TNewContactForm::TNewContactForm(UnicodeString FamilyName,
		UnicodeString Initials, CONTACT** contact, TComponent* Owner) : TForm(Owner)
{
   Contact = contact;
   *Contact = NULL;
   Edit1->Text = FamilyName;
   Edit2->Text = Initials;
   Edit3->Text = Initials;
}
//---------------------------------------------------------------------------

void __fastcall TNewContactForm::Edit2Exit(TObject *Sender)
{
   if (Edit3->Text.IsEmpty())
	 Edit3->Text = (*Contact)->GetLeadingInitials();
}
//---------------------------------------------------------------------------

// Fill button
void __fastcall TNewContactForm::cxButton3Click(TObject *Sender)
{
   CONTACT* contact = new CONTACT();
   if (!Edit1->Text.IsEmpty())
	 contact->FamilyName = Edit1->Text;
   if (!Edit3->Text.IsEmpty())
	 contact->LeadingInitials = Edit3->Text;

   TGetNeotomaContact* GetNeotomaContactForm = new TGetNeotomaContact(contact, this);
   GetNeotomaContactForm->ShowModal();

   Edit1->Text = contact->FamilyName;
   Edit2->Text = contact->GivenNames;
   Edit3->Text = contact->LeadingInitials;
   Edit4->Text = contact->Suffix;

   int TitleIndex = ComboBox2->Items->IndexOf(contact->Title);
   if (TitleIndex > -1)
	 ComboBox2->ItemIndex = TitleIndex;
   else
	 ComboBox2->ItemIndex = ComboBox2->Items->Add(contact->Title);

   int StatusIndex = ComboBox3->Items->IndexOf(contact->Status);
   if (StatusIndex > -1)
	 ComboBox3->ItemIndex = StatusIndex;
   else
	 ComboBox3->ItemIndex = ComboBox3->Items->Add(contact->Status);

   Edit5->Text = contact->Telephone;
   Edit6->Text = contact->Fax;
   Edit7->Text = contact->Email;
   Memo1->Text = contact->Address;
   
   delete GetNeotomaContactForm;
   delete contact;
}
//---------------------------------------------------------------------------

// Ok button
void __fastcall TNewContactForm::cxButton1Click(TObject *Sender)
{
   *Contact = new CONTACT();
   (*Contact)->FamilyName = Edit1->Text;
   (*Contact)->GivenNames = Edit2->Text;
   if (!Edit3->Text.IsEmpty())
	 (*Contact)->LeadingInitials = Edit3->Text;
   else if (!Edit2->Text.IsEmpty())
	 (*Contact)->GetLeadingInitials();
   (*Contact)->Suffix = Edit4->Text;
   (*Contact)->Title = ComboBox2->Text;
   (*Contact)->FormatContactName();
   (*Contact)->Status = ComboBox3->Text;
   (*Contact)->Telephone = Edit5->Text;
   (*Contact)->Fax = Edit6->Text;
   (*Contact)->Email = Edit7->Text;
   int nlines = 0;
   for (int i=0; i<NewContactForm->Memo1->Lines->Count; i++) {
	 if (!(Memo1->Lines->Strings[i]).IsEmpty()) {
	   if (nlines > 0)
		 (*Contact)->Address += "\r\n";
	   (*Contact)->Address += Memo1->Lines->Strings[i];
	   nlines++;
	   }
	 }
}
//---------------------------------------------------------------------------

