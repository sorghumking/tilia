//---------------------------------------------------------------------------

#include <vcl.h>
#include "pch.h"
#include <DateUtils.hpp>
#include <algorithm>
#pragma hdrstop

#include "TICtbFrm.h"
#ifndef TINewConH
#include "TINewCon.h"
#endif

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxCalendar"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDropDownEdit"
#pragma link "cxEdit"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "cxCheckComboBox"
#pragma link "cxGraphics"
#pragma link "cxClasses"
#pragma link "cxCustomData"
#pragma link "cxData"
#pragma link "cxDataStorage"
#pragma link "cxFilter"
#pragma link "cxGrid"
#pragma link "cxGridCustomTableView"
#pragma link "cxGridCustomView"
#pragma link "cxGridLevel"
#pragma link "cxGridTableView"
#pragma link "cxStyles"
#pragma link "cxGridCardView"
#pragma link "cxMemo"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxGridCustomLayoutView"
#pragma link "cxNavigator"
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
#pragma link "dxSkinscxPCPainter"
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

TSubmissionForm *SubmissionForm;

SUBMISSION::SUBMISSION()
{
  Archived = false;
  SubmissionDate = NaN;
  //Submitters = new TList;
}
//---------------------------------------------------------------------------

SUBMISSION::SUBMISSION(UnicodeString& InitialDataForm)
{
  Archived = false;
  SubmissionDate = NaN;
  //Submitters = new TList;
  SubmittedForm = InitialDataForm;
  SubmissionDate = Today();
}
//---------------------------------------------------------------------------

SUBMISSION::~SUBMISSION()
{
  //Submitters->Clear();
  //delete Submitters;
}
//---------------------------------------------------------------------------

__fastcall TSubmissionForm::TSubmissionForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TSubmissionForm::FormCreate(TObject *Sender)
{
   InitialActivation = true;
   ParamsSet = false;
   CleanedUp = false;

   SubmissionList = new TSubmissionList;
   SubmissionDataSource = new TSubmissionDataSource(SubmissionList);
   GenerateSubmissionColumns();
}
//---------------------------------------------------------------------------

void __fastcall TSubmissionForm::FormActivate(TObject *Sender)
{
   SubmissionDataSource->SetInitialDataForm(InitialDataForm);
   FocusControl(SubmissionGrid);

   if (!InitialActivation) return;

   InitialActivation = false;
   Changed = false;
   Caption = "Submission 1";

   // force showing of submitters
   /*
   if (SubmissionList->Count) {
     SubmissionGridCardView1->Controller->FocusedRecordIndex = 0;
     SubmissionGridCardView1->Controller->FocusedItemIndex = IndexOf_suSubmitters;
     SubmissionGridCardView1->Controller->FocusedItemIndex = 0;
     }
   */
   
}
//---------------------------------------------------------------------------

void __fastcall TSubmissionForm::FormDestroy(TObject *Sender)
{
   if (!CleanedUp) {
     int last = SubmissionList->Count - 1;
     for (int i=last; i>=0; i--) {
       SUBMISSION* Submission = SubmissionList->Submission[i];
       if (Submission->Archived)
         SubmissionList->Extract(Submission);
       }
     }
   delete SubmissionList;
   delete SubmissionDataSource;
}
//---------------------------------------------------------------------------

void TSubmissionForm::SetParams(UnicodeString DatasetType, TList* contribs,
     TList* loi_contribs, TList* contacts, TContactList* contact_list, TStrings* countries)
{

   SpeedButton1Down = true;
   SpeedButton2Down = false;
   SubmissionList->Assign(contribs);

   SpeedButton1->Caption = DatasetType;
   Contacts = contacts;    
   ContactList = contact_list;
   Submissions = contribs;

   TcxCheckComboBoxItems* CheckComboBoxItems =
     (TcxCheckComboBoxItems*)(((TcxCheckComboBoxProperties*)(suSubmitters->Properties))->Items);
   CheckComboBoxItems->Clear();
   for (int i=0; i<Contacts->Count; i++) {
     CONTACT* Contact = (CONTACT*)Contacts->Items[i];
     CheckComboBoxItems->AddCheckItem(Contact->ShortContactName, Contact->ShortContactName);
     }

   if (Submissions->Count) {
     SUBMISSION* Submission = (SUBMISSION*)Submissions->Items[0];
	 //for (int i=0; i<Submission->Submitters->Count; i++) {
	 for (unsigned int i=0; i<Submission->Submitters.size(); i++) {
	   //CONTACT* Contact = (CONTACT*)Submission->Submitters->Items[i];
	   CONTACT* Contact = Submission->Submitters[i];
	   if (i == 0)
		 Submission->SubmittersComboBoxText = Contact->ShortContactName;
       else
         Submission->SubmittersComboBoxText += (";" + Contact->ShortContactName);
	   }
	 //if (!Submission->Submitters->Count)
     if (Submission->Submitters.size() == 0)
	   Submission->SubmittersComboBoxText = "None selected";
	 }

   loi_submissions = loi_contribs;
   Countries = countries;
   if (!loi_contribs) 
     SpeedButton2->Visible = false;

   if (SubmissionList->Count > 1)
     SubmissionList->SortAscending();
   ParamsSet = true;

   if (SubmissionList->Count) {
     SubmissionGridCardView1->Controller->FocusedRecordIndex = 0;
     SubmissionGridCardView1->Controller->FocusedItemIndex = 0;
     }
}
//---------------------------------------------------------------------------
//START
void TSubmissionList::ReleaseAllSubmissions()
{
  for (int i = 0; i < Count; i++)
    ReleaseSubmission(i);
}
//---------------------------------------------------------------------------

void TSubmissionList::ReleaseSubmission(int AIndex)
{
  delete (SUBMISSION*)Items[AIndex];
}
//---------------------------------------------------------------------------

SUBMISSION* TSubmissionList::GetSubmission(int AIndex)
{
  return (SUBMISSION*)Items[AIndex];
}
//---------------------------------------------------------------------------

void __fastcall TSubmissionList::Notify(void * Ptr, TListNotification Action)
{
  if (FOnNotify != NULL)
    FOnNotify(Ptr, Action);
}
//---------------------------------------------------------------------------

void __fastcall TSubmissionList::Clear(void)
{
  ReleaseAllSubmissions();
}
//---------------------------------------------------------------------------

void TSubmissionList::Add(SUBMISSION* Submission)
{
  TList::Add(Submission);
}
//---------------------------------------------------------------------------

void TSubmissionList::Delete(int AIndex)
{
  ReleaseSubmission(AIndex);
  TList::Delete(AIndex);
}
//---------------------------------------------------------------------------

void TSubmissionList::Insert(int AIndex, SUBMISSION* Submission)
{
  TList::Insert(AIndex, Submission);
}
//---------------------------------------------------------------------------

void TSubmissionList::SortAscending(void)
{
   Sort(SubmissionCompare);
}
//---------------------------------------------------------------------------

int __fastcall TSubmissionList::SubmissionCompare(void * Item1, void * Item2)
{
   SUBMISSION* submission1 = (SUBMISSION*)Item1;
   SUBMISSION* submission2 = (SUBMISSION*)Item2;

   if (submission1->SubmissionDate < submission2->SubmissionDate)
     return -1;
   else if (submission1->SubmissionDate > submission2->SubmissionDate)
     return 1;
   else
     return 0;
}
//---------------------------------------------------------------------------

__fastcall TSubmissionDataSource::TSubmissionDataSource(TSubmissionList* ASubmissionList)
{
  FSubmissions = ASubmissionList;
  FSubmissions->OnNotify = Notify;
}
//---------------------------------------------------------------------------

void __fastcall TSubmissionDataSource::DeleteRecord(void * ARecordHandle)
{
  FSubmissions->Delete((int)ARecordHandle);
}
//---------------------------------------------------------------------------

int __fastcall TSubmissionDataSource::GetRecordCount(void)
{
  return(FSubmissions->Count);
}
//---------------------------------------------------------------------------

Variant __fastcall TSubmissionDataSource::GetValue(void * ARecordHandle, void * AItemHandle)
{
  // displays value in grid based on stored data
  int AColumnId = GetDefaultItemID((int)AItemHandle);
  SUBMISSION* Submission = FSubmissions->Submission[(int)ARecordHandle];
  Variant Result;

  switch (AColumnId) {
    case IndexOf_suSubmittedForm:
      Result = Submission->SubmittedForm;
      break;
    case IndexOf_suSubmissionDate:
      if (IsNan(Submission->SubmissionDate))
        Result.ChangeType(varEmpty);
      else
        Result = Submission->SubmissionDate;
      break;
    case IndexOf_suSubmissionType:
      Result = Submission->SubmissionType;
      break;
    case IndexOf_suSubmitters:
      Result = Submission->SubmittersComboBoxText;
      break;
    case IndexOf_suNotes:
      Result = Submission->Notes;
      break;
  }
  return (Result);
}
//---------------------------------------------------------------------------

void __fastcall TSubmissionDataSource::Notify(void * Ptr, TListNotification Action)
{
  DataChanged();
}
//---------------------------------------------------------------------------

void * __fastcall TSubmissionDataSource::InsertRecord(void * ARecordHandle)
{
  SUBMISSION* Submission = new SUBMISSION(InitialDataForm);
  FSubmissions->Insert((int)ARecordHandle, Submission);
  TcxDataRecordHandle* Result = (TcxDataRecordHandle*)ARecordHandle;
  return (Result);
}
//---------------------------------------------------------------------------

void * __fastcall TSubmissionDataSource::AppendRecord(void)
{
  TcxDataRecordHandle* Result = (TcxDataRecordHandle*)FSubmissions->Count;
  SUBMISSION* Submission = new SUBMISSION(InitialDataForm);
  FSubmissions->Add(Submission);
  return (Result);
}
//---------------------------------------------------------------------------

void __fastcall TSubmissionDataSource::SetValue(void * ARecordHandle, void * AItemHandle, const Variant &AValue)
{
  // gets values from grid and stores them
  int AColumnId = GetDefaultItemID((int)AItemHandle);
  SUBMISSION* Submission = FSubmissions->Submission[(int)ARecordHandle];
  switch (AColumnId) {
    case IndexOf_suSubmittedForm:
	  Submission->SubmittedForm = VarToStr(AValue);
      break;
    case IndexOf_suSubmissionDate:
      if (AValue.IsNull())
        Submission->SubmissionDate = NaN;
      else
        Submission->SubmissionDate = AValue;
      break;
    case IndexOf_suSubmissionType:
	  Submission->SubmissionType = VarToStr(AValue);
	  break;
    case IndexOf_suSubmitters:
      break;
    case IndexOf_suNotes:
	  Submission->Notes = VarToStr(AValue);
      break;
  }
}
//---------------------------------------------------------------------------

void __fastcall TSubmissionForm::GenerateSubmissionColumns()
{
   suSubmittedForm->DataBinding->Data = (TObject*)IndexOf_suSubmittedForm;
   suSubmissionDate->DataBinding->Data = (TObject*)IndexOf_suSubmissionDate;
   suSubmissionType->DataBinding->Data = (TObject*)IndexOf_suSubmissionType;
   suSubmitters->DataBinding->Data = (TObject*)IndexOf_suSubmitters;
   suNotes->DataBinding->Data = (TObject*)IndexOf_suNotes;

   // this line is critical
   SubmissionGridCardView1->DataController->CustomDataSource = SubmissionDataSource;
}

//END
//---------------------------------------------------------------------------

// add new contact
void __fastcall TSubmissionForm::Button3Click(TObject *Sender)
{
   int FocusedRecordIndex = SubmissionGridCardView1->Controller->FocusedRecordIndex;

   CONTACT* Contact;
   TNewContactForm* NewContactForm = new TNewContactForm(&Contact, this);
   bool NewContactAdded = false;
   if (NewContactForm->ShowModal()== mrOk) {
	 if (Contact != NULL) {
	   ContactList->Add(Contact);
       Contacts->Clear();
       Contacts->Assign(ContactList);
       NewContactAdded = true;
       }
     }
   delete NewContactForm;

   if (NewContactAdded) {
     TcxCheckComboBoxItems* CheckComboBoxItems =
       (TcxCheckComboBoxItems*)(((TcxCheckComboBoxProperties*)(suSubmitters->Properties))->Items);
     CheckComboBoxItems->Clear();
     for (int i=0; i<Contacts->Count; i++) {
       CONTACT* Contact = (CONTACT*)Contacts->Items[i];
       CheckComboBoxItems->AddCheckItem(Contact->ShortContactName, Contact->ShortContactName);
       }
     }

  FocusControl(SubmissionGrid);
  SubmissionGridCardView1->Controller->FocusedRecordIndex = FocusedRecordIndex;
  SubmissionGridCardView1->Controller->FocusedItemIndex = IndexOf_suSubmitters;
}
//---------------------------------------------------------------------------

// Ok button
void __fastcall TSubmissionForm::Button1Click(TObject *Sender)
{
   if (SpeedButton1->Down) {
     Submissions->Clear();
     if (SubmissionList->Count) {
       Submissions->Capacity = SubmissionList->Count;
       Submissions->Assign(SubmissionList);
       for (int i=0; i<Submissions->Count; i++) {
         SUBMISSION* Submission = (SUBMISSION*)Submissions->Items[i];
         Submission->Archived = true;
         }
       }
     }
   else if (SpeedButton2->Down) {
     loi_submissions->Clear();
     if (SubmissionList->Count) {
       loi_submissions->Capacity = SubmissionList->Count;
       loi_submissions->Assign(SubmissionList);
       for (int i=0; i<loi_submissions->Count; i++) {
         SUBMISSION* Submission = (SUBMISSION*)loi_submissions->Items[i];
         Submission->Archived = true;
         }
       }
     }

   for (int i=SubmissionList->Count-1; i>=0; i--) {
     SUBMISSION* Submission = SubmissionList->Submission[i];
     SubmissionList->Extract(Submission);
     }
}
//---------------------------------------------------------------------------

// Cancel button
void __fastcall TSubmissionForm::Button2Click(TObject *Sender)
{
   if (SpeedButton1->Down) {
     Submissions->Clear();
     if (SubmissionList->Count) {
       Submissions->Capacity = SubmissionList->Count;
       Submissions->Assign(SubmissionList);
       }
     }
   else if (SpeedButton2->Down) {
     loi_submissions->Clear();
     if (SubmissionList->Count) {
       loi_submissions->Capacity = SubmissionList->Count;
       loi_submissions->Assign(SubmissionList);
       }
     }
 
   int last = SubmissionList->Count - 1;
   for (int i=last; i>=0; i--) {
     SUBMISSION* Submission = SubmissionList->Submission[i];
     SubmissionList->Extract(Submission);
     }

   last = Submissions->Count - 1;
   for (int i=last; i>=0; i--) {
     SUBMISSION* Submission = (SUBMISSION*)Submissions->Items[i];
     if (!Submission->Archived) {
       Submissions->Delete(i);
       delete Submission;
       }
     }
   if (loi_submissions) {
     last = loi_submissions->Count - 1;
     for (int i=last; i>=0; i--) {
       SUBMISSION* Submission = (SUBMISSION*)loi_submissions->Items[i];
       if (!Submission->Archived) {
         loi_submissions->Delete(i);
         delete Submission;
         }
       }
     }
   CleanedUp = true;
}
//---------------------------------------------------------------------------

void __fastcall TSubmissionForm::SpeedButton2Click(TObject *Sender)
{
   if (SpeedButton2Down) {
     Beep();
     return;
     }
     
   SubmissionGridCardView1->DataController->Post();

   // copy SubmissionList to submissions and empty SubmissionList
   Submissions->Clear();
   if (SubmissionList->Count) {
     Submissions->Capacity = SubmissionList->Count;
     Submissions->Assign(SubmissionList);
     for (int i=SubmissionList->Count-1; i>=0; i--) {
       SUBMISSION* Submission = SubmissionList->Submission[i];
       SubmissionList->Extract(Submission);
       }
     }

   if (loi_submissions->Count)
     SubmissionList->Assign(loi_submissions);

   if (SubmissionList->Count) {
     SUBMISSION* Submission = SubmissionList->Submission[0];
	 //for (int i=0; i<Submission->Submitters->Count; i++) {
	 for (unsigned int i=0; i<Submission->Submitters.size(); i++) {
	   //CONTACT* Contact = (CONTACT*)Submission->Submitters->Items[i];
       CONTACT* Contact = Submission->Submitters[i];
	   if (i == 0)
         Submission->SubmittersComboBoxText = Contact->ShortContactName;
       else
		 Submission->SubmittersComboBoxText += (";" + Contact->ShortContactName);
	   }
	 //if (!Submission->Submitters->Count)
	 if (Submission->Submitters.size() == 0)
	   Submission->SubmittersComboBoxText = "None selected";
     }

   FocusControl(SubmissionGrid);
   // force showing of submitters
   if (SubmissionList->Count) {
     SubmissionGridCardView1->Controller->FocusedRecordIndex = 0;
     SubmissionGridCardView1->Controller->FocusedItemIndex = IndexOf_suSubmitters;
     SubmissionGridCardView1->Controller->FocusedItemIndex = 0;
     }

   SpeedButton2Down = true;
   SpeedButton1Down = false;
}
//---------------------------------------------------------------------------

void __fastcall TSubmissionForm::SpeedButton1Click(TObject *Sender)
{
   if (SpeedButton1Down) {
     Beep();
     return;
     }

   SubmissionGridCardView1->DataController->Post();

   // copy SubmissionList to submissions and empty SubmissionList
   loi_submissions->Clear();
   if (SubmissionList->Count) {
     loi_submissions->Capacity = SubmissionList->Count;
     loi_submissions->Assign(SubmissionList);
     for (int i=SubmissionList->Count-1; i>=0; i--) {
       SUBMISSION* Submission = SubmissionList->Submission[i];
       SubmissionList->Extract(Submission);
       }
     }

   if (Submissions->Count)
     SubmissionList->Assign(Submissions);

   if (SubmissionList->Count) {
     SUBMISSION* Submission = SubmissionList->Submission[0];
	 //for (int i=0; i<Submission->Submitters->Count; i++) {
	 for (unsigned int i=0; i<Submission->Submitters.size(); i++) {
	   //CONTACT* Contact = (CONTACT*)Submission->Submitters->Items[i];
       CONTACT* Contact = Submission->Submitters[i];
	   if (i == 0)
         Submission->SubmittersComboBoxText = Contact->ShortContactName;
       else
         Submission->SubmittersComboBoxText += (";" + Contact->ShortContactName);
       }
	 //if (!Submission->Submitters->Count)
	 if (Submission->Submitters.size() == 0)
	   Submission->SubmittersComboBoxText = "None selected";
	 }

   FocusControl(SubmissionGrid);
   // force showing of submitters
   if (SubmissionList->Count) {
     SubmissionGridCardView1->Controller->FocusedRecordIndex = 0;
     SubmissionGridCardView1->Controller->FocusedItemIndex = IndexOf_suSubmitters;
     SubmissionGridCardView1->Controller->FocusedItemIndex = 0;
     }

   SpeedButton1Down = true;
   SpeedButton2Down = false;
}
//---------------------------------------------------------------------------

void __fastcall TSubmissionForm::suSubmittersPropertiesEditValueToStates(
      TObject *Sender, const Variant &AValue, TcxCheckStates &ACheckStates)
{
   // Enables you to convert the edit value into a check state manually.
   // Retrieve submitters for record and check boxes
   // i.e. this routine checks the checkbox boxes

   TcxCustomGridRecord *AFocusedRecord = SubmissionGridCardView1->Controller->FocusedRecord;
   if (!AFocusedRecord) return;

   if (Contacts->Count == ACheckStates.Length) {
	 SUBMISSION* Submission = SubmissionList->Submission[AFocusedRecord->RecordIndex];
	 for (int i=0; i<Contacts->Count; i++) {
	   vector<CONTACT*>::iterator begin = Submission->Submitters.begin();
	   vector<CONTACT*>::iterator end = Submission->Submitters.end();
	   vector<CONTACT*>::iterator itr = find(begin, end, Contacts->Items[i]);
	   //if (Submission->Submitters->IndexOf(Contacts->Items[i]) >= 0)
	   if (itr != end)
		 ACheckStates[i] = cbsChecked;
       else
		 ACheckStates[i] = cbsUnchecked;
       }
	 }
}          //it = find (myvector.begin(), myvector.end(), 30);
//---------------------------------------------------------------------------

void __fastcall TSubmissionForm::suSubmittersPropertiesStatesToEditValue(
      TObject *Sender, const TcxCheckStates ACheckStates, Variant &AValue)
{
   // this routine provides the CheckComboBox Text, i.e. SubmittersComboBoxText
   TcxCustomGridRecord *AFocusedRecord = SubmissionGridCardView1->Controller->FocusedRecord;
   if (!AFocusedRecord) return;

   SUBMISSION* Submission = SubmissionList->Submission[AFocusedRecord->RecordIndex];
   //Submission->Submitters->Clear();
   Submission->Submitters.clear();
   Submission->SubmittersComboBoxText.SetLength(0);
   for (int i=0; i<Contacts->Count; i++) {
     if (ACheckStates[i] == cbsChecked) {
       CONTACT* Contact = (CONTACT*)Contacts->Items[i];
	   //Submission->Submitters->Add(Contact);
	   Submission->Submitters.push_back(Contact);
	   //if (Submission->Submitters->Count == 1)
       if (Submission->Submitters.size() == 1)
		 Submission->SubmittersComboBoxText = Contact->ShortContactName;
       else
		 Submission->SubmittersComboBoxText += (";" + Contact->ShortContactName);
       }
	 }
   //if (!Submission->Submitters->Count)
   if (Submission->Submitters.size() == 0)
	 Submission->SubmittersComboBoxText = "None selected";
}
//---------------------------------------------------------------------------

void __fastcall TSubmissionForm::suSubmittersGetDisplayText(
      TcxCustomGridTableItem *Sender, TcxCustomGridRecord *ARecord,
	  UnicodeString &AText)
{
   // this routine actually displays the SubmittersComboBoxText
   if (!ParamsSet) return;
   if (!ARecord) return;

   SUBMISSION* Submission = SubmissionList->Submission[ARecord->RecordIndex];
   AText = Submission->SubmittersComboBoxText;
}
//---------------------------------------------------------------------------

void __fastcall TSubmissionForm::SubmissionGridCardView1FocusedRecordChanged(
      TcxCustomGridTableView *Sender,
      TcxCustomGridRecord *APrevFocusedRecord,
      TcxCustomGridRecord *AFocusedRecord,
      bool ANewItemRecordFocusingChanged)
{
   if (AFocusedRecord) {
     SUBMISSION* Submission = SubmissionList->Submission[AFocusedRecord->RecordIndex];
     if (Submission->Archived && !SpeedButton3->Down) {
       SubmissionGridCardView1->OptionsData->Deleting = false;
       SubmissionGridCardView1->OptionsData->Editing = false;
       Label1->Visible = true;
       }
     else {
       SubmissionGridCardView1->OptionsData->Deleting = true;
       SubmissionGridCardView1->OptionsData->Editing = true;
       Label1->Visible = false;
       }
     Caption = "Submission " + IntToStr(AFocusedRecord->Index + 1);
     }
   else {
     SubmissionGridCardView1->OptionsData->Deleting = true;
     SubmissionGridCardView1->OptionsData->Editing = true;
     Label1->Visible = false;
     Caption = "Submission";
     }
}
//---------------------------------------------------------------------------

void __fastcall TSubmissionForm::SubmissionGridCardView1FocusedItemChanged(
      TcxCustomGridTableView *Sender,
      TcxCustomGridTableItem *APrevFocusedItem,
      TcxCustomGridTableItem *AFocusedItem)
{
   if (AFocusedItem)
	 Button3->Visible = (AFocusedItem->Index == suSubmitters->Index) ? true : false;
}
//---------------------------------------------------------------------------

void __fastcall TSubmissionForm::SpeedButton3Click(TObject *Sender)
{
   SUBMISSION* Submission;

   if (SubmissionGridCardView1->Controller->FocusedRecord->RecordIndex >= 0) {
     Submission = SubmissionList->Submission[SubmissionGridCardView1->Controller->FocusedRecord->RecordIndex];
     if (!SpeedButton3->Down && Submission->Archived) {
       SubmissionGridCardView1->OptionsData->Deleting = false;
       SubmissionGridCardView1->OptionsData->Editing = false;
       }
     else {
       SubmissionGridCardView1->OptionsData->Deleting = true;
       SubmissionGridCardView1->OptionsData->Editing = true;
       }
     }
}
//---------------------------------------------------------------------------


