//---------------------------------------------------------------------------
#include <vcl.h>
#include "pch.h"

#pragma hdrstop

#include "TISpread5.h"
#ifndef TISpreadH
#include "TISpread.h"
#endif
#ifndef TIGlobalsH
#include "TIGlobals.h"
#endif
#ifndef TIChkVarH
#include "TIChkVar.h"
#endif
#ifndef TIAdmUntH
#include "TIAdmUnt.h"
#endif
#ifndef TICalibH
#include "TICalib.h"
#endif
#ifndef TIChronH
#include "TIChron.h"
#endif
#ifndef TIExpChrH
#include "TIExpChr.h"
#endif
#ifndef TIImpChrH
#include "TIImpChr.h"
#endif
#ifndef TIAUAgesH
#include "TIAUAges.h"
#endif
#ifndef TIImpDatH
#include "TIImpDat.h"
#endif
#ifndef TIUpContactH
#include "TIUpContact.h"
#endif
#ifndef TINwLkUpH
#include "TINwLkUp.h"
#endif
#ifndef TIAddCalH
#include "TIAddCal.h"
#endif
#ifndef TIVrLkUpH
#include "TIVrLkUp.h"
#endif
#ifndef TISpecH
#include "TISpec.h"
#endif

//---------------------------------------------------------------------------

#pragma package(smart_init)

void __fastcall TTilSpreadSheetForm::CalibrateAction1Execute(TObject *Sender)
{
   CalibForm = new TCalibForm(this);
   CalibForm->ShowModal();
   delete CalibForm;
}
//---------------------------------------------------------------------------

// module for calculating a chronlogy -- not finished yet
void TTilSpreadSheetForm::Chronology(void)
{
   UnicodeString VarCode;
   Variant value;
   double dValue, lastdValue;

   if (!AgeModelList->Count) {
	 MessageDlg("No age models defined.", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 return;
	 }

   int col_beg = ProfGrid1->FixedCols;  // = number of visible fixed cols
   int col_end = ContentColCount(ProfGrid1);
   int size = col_end - col_beg + 1;
   if (size < 1) {
     MessageDlg("No samples entered.", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
     return;
	 }

   TChronForm* ChronForm = new TChronForm(this);
   ChronForm->SetAgeModelList(AgeModelList);

   // get sample depths and place in vector Depths
   bool error = false;
   for (int col=col_beg, i=0; col<=col_end; col++, i++) {
	 try {
		 if (!ProfGrid1->Cells[col][1]->Value.IsNull() &&
			 !ProfGrid1->Cells[col][1]->Value.IsEmpty() ) {
			 dValue = ProfGrid1->Cells[col][1]->Value;
			 if (col > col_beg && dValue < lastdValue) {
			   error = true;
               MessageDlg("Sample number in column " + ProfGrid1->Cols[col]->A1Name +
                 " not in ascending order.", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			   }
             }
         else {
		   error = true;
           MessageDlg("No sample number in column " + ProfGrid1->Cols[col]->A1Name + ".",
			 Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
           }
		 }
	 catch ( ... )
		 {
		 error = true;
		 MessageDlg("Error in sample number in column " + ProfGrid1->Cols[col]->A1Name + ".",
		   Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 }
	 if (error) {
	   delete ChronForm;
	   return;
	   }
	 ChronForm->Depths.push_back(dValue);
	 lastdValue = dValue;
	 }

   // get chrons in Age Models tab sheet
   for (int i=0; i<AgeModelList->Count; i++) {
     AGEMODEL* AgeModel = AgeModelList->AgeModels[i];
     ChronForm->ComboBox1->Items->Add("Chron" + IntToStr(AgeModel->ChronNumber));
     CHRONDATA *ChronData = new CHRONDATA(AgeModel->ChronNumber,
       AgeModel->ChronologyName, AgeModel->AgeUnits);
	 ChronForm->Chrons->Add(ChronData);
     }

   // get chron sample ages from spreadsheet
   int nrows = AbsContentRowCount(ProfGrid1);
   int start = AbsHeaderRowCount(ProfGrid1);

   // TODO: need to deal with #Chron1.younger

   int ChronNo;
   for (int row=start; row<=nrows; row++) {
	 VarCode = ProfGrid1->AbsoluteCells[1][row]->Text;
	 if (SameText(VarCode.SubString(1,6), L"#Chron") &&
		 !ContainsText(VarCode, L".Young") &&
		 !ContainsText(VarCode, L".Old")) {
       try {
           ChronNo = StrToInt(VarCode.SubString(7, VarCode.Length()-6));
           }
	   catch(Exception &e)
           {
           MessageDlg("Chronology " + VarCode + " ignored: " + e.Message,
             mtWarning, TMsgDlgButtons() << mbOK, 0);
           continue;
		   }

       // check if ChronNo in spreadsheet has a defined age model
	   bool found = false;
       for (int i=0; i<AgeModelList->Count; i++) {
         AGEMODEL* AgeModel = AgeModelList->AgeModels[i];
         if (AgeModel->ChronNumber == ChronNo) {
           found = true;
           break;
           }
         }
       if (!found) {
         MessageDlg("Chronology " + IntToStr(ChronNo) + " does not have a defined age model.",
             mtWarning, TMsgDlgButtons() << mbOK, 0);
         continue;
         }

       CHRONDATA *ChronData;
       found = false;
       for (int i=0; i<ChronForm->Chrons->Count; i++) {
         ChronData = (CHRONDATA*)ChronForm->Chrons->Items[i];
         if (ChronData->ChronNumber == ChronNo) {
           found = true;
           ChronData->Row = row;
           break;
           }
         }
       if (found) {
         ChronData->alloc(size);
         ChronData->NewAges = false;

         bool NullError = false;
         for (int col=col_beg, i=0; col<=col_end; col++, i++) {
           try {
               if (!ProfGrid1->Cells[col][row]->Value.IsNull() &&
                   !ProfGrid1->Cells[col][row]->Value.IsEmpty() ) {
                   dValue = ProfGrid1->Cells[col][row]->Value;
                   }
               else {
                 dValue = NaN;
                 NullError = true;
                 }
               }
           catch(Exception &e)
               {
               dValue = NaN;
			   MessageDlg("Error in column " + ProfGrid1->Cols[col]->A1Name +
                 " in " + VarCode + ": " + e.Message, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
               error = true;
               }
           if (error) {
             delete ChronForm;
             return;
             }
           ChronData->SampleAges[i].Age = dValue;
           }
         if (NullError) {
           MessageDlg("Samples with no ages assigned in " + VarCode,
             mtWarning, TMsgDlgButtons() << mbOK, 0);
           NullError = false;
           }
         }
       }
     }

   ChronForm->ComboBox1->ItemIndex = 0;
   ChronForm->ShowModal();
   if (ChronForm->Saved) {
     SpreadSheetChanged = true;
     NewAgeModels = true;  // used to repaint age models grid
     }
   delete ChronForm;
}
//---------------------------------------------------------------------------

// write clam and bacon csv files
void __fastcall TTilSpreadSheetForm::cxButton20Click(TObject *Sender)
{
   int RecordIndex1 = cxGrid3TableView1->Controller->FocusedRecordIndex;
   if (RecordIndex1 < 0) {
	 MessageDlg("No chronology selected.", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 return;
	 }
   AGEMODEL* AgeModel = AgeModelList->AgeModels[RecordIndex1];

   map<double,double> Depths;   // depth, thickness
   int thick_row = FindRowCodeIC("#Anal.Thick", ProfGrid1);
   int StartCol = AbsHeaderColCount(ProfGrid1);
   int EndCol = AbsContentColCount(ProfGrid1);
   double Depth, Thickness;
   for (int col=StartCol; col<=EndCol; col++) {
	 if (ProfGrid1->AbsoluteCells[col][1]->Value.Type() == varDouble) {
	   Depth = ProfGrid1->AbsoluteCells[col][1]->Value;
	   Thickness = 0;
	   if (thick_row > 0) {
		 if (ProfGrid1->AbsoluteCells[col][thick_row]->Value.Type() == varDouble)
		   Thickness = ProfGrid1->AbsoluteCells[col][thick_row]->Value;
		 }
	   Depths[Depth] = Thickness;
	   }
	 }

   ChronControlExportForm = new TChronControlExportForm(AgeModel, GeochronList, cxTreeView1, Depths, this);
   ChronControlExportForm->ShowModal();
   delete ChronControlExportForm;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::ImportClamAction1Execute(TObject *Sender)
{
   ImportClamForm = new TImportClamForm(this);
   ImportClamForm->ShowModal();
   delete ImportClamForm;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::ImportBaconAction1Execute(TObject *Sender)
{
   ImportBaconForm = new TImportBaconForm(this);
   ImportBaconForm->ShowModal();
   delete ImportBaconForm;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::ImportBchronAction1Execute(TObject *Sender)
{
   ImportBchronForm = new TImportBchronForm(this);
   ImportBchronForm->ShowModal();
   delete ImportBchronForm;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::ImportOxCalAction1Execute(TObject *Sender)
{
   ImportOxCalForm = new TImportOxCalForm(this);
   ImportOxCalForm->ShowModal();
   delete ImportOxCalForm;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::ImportChronologiesTabsheet1Execute(TObject *Sender)
{
   ImportChronTabsheetForm = new TImportChronTabsheetForm(this);
   ImportChronTabsheetForm->ShowModal();
   delete ImportChronTabsheetForm;
}
//---------------------------------------------------------------------------

// import age model dates from geochron grid
void __fastcall TTilSpreadSheetForm::cxButton19Click(TObject *Sender)
{
   UnicodeString msg;
   bool hasdepths = false;
   bool hasanalunits = false;

   int RecordIndex1 = cxGrid3TableView1->Controller->FocusedRecordIndex;
   if (RecordIndex1 < 0) {
	 MessageDlg("No chronology selected.", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 return;
	 }

   SITE* site_ptr = (SITE*)Sites->Items[0];
   ImportGeochronForm = new TImportGeochronForm(site_ptr->LatNorth, this);
   int rv = ImportGeochronForm->ShowModal();
   int nsigma = ImportGeochronForm->nsigma;
   bool calibrate = ImportGeochronForm->calibrate;
   UnicodeString curve = (ImportGeochronForm->calibcurve == INTCAL13) ? L"IntCal13.14c" : L"ShCal13.14c";
   delete ImportGeochronForm;
   if (rv == mrCancel)
	 return;

   AGEMODEL* AgeModel = AgeModelList->AgeModels[RecordIndex1];

   bool missing_data = false;
   Screen->Cursor = crHourGlass;
   int transferred = 0;
   int import = mrNone;
   for (int i=0; i<GeochronList->Count(); i++) {
	 bool go = true;
	 GEOCHRON* Date = &GeochronList->Dates[i];
	 if (Date->GreaterThan) {
	   switch (import) {
		 case mrNone:
		 case mrYes:
		 case mrNo:
		   msg = L"Import infinite \"greater than\" date?";
		   import = MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes <<mbYesToAll << mbNo << mbNoToAll, 0);
		   break;
		 }
	   switch (import) {
		 case mrYes:
		 case mrYesToAll:
		   go = true;
		   break;
		 case mrNo:
		 case mrNoToAll:
		   go = false;
		   break;
		 default:
		   import = mrNone;
		   go = false;
		   break;
		 }
	   }
	 if (go) {
	   CHRON* ChronControl = new CHRON();
	   if (!Date->Depth.IsEmpty()) {
		 ChronControl->Depth = Date->Depth;
		 hasdepths = true;
		 }
	   if (!Date->Thickness.IsEmpty())
		 ChronControl->Thickness = Date->Thickness;
	   ChronControl->AnalUnit = Date->AnalUnit;
	   if (!ChronControl->AnalUnit.IsEmpty())
		 hasanalunits = true;
	   if (calibrate && !Date->GreaterThan && SameText(Date->Method, L"Carbon-14")) {
		 vector<CALIBDATE> CalibDates;
		 CALIBDATE CalibDate;
		 OXCAL OxCal(ipsJSONS1, TcpClient1);
		 if (!Date->LabNumber.IsEmpty())
		   CalibDate.LabNumber = Date->LabNumber;
		 else {
		   msg = L"OxCal requires a lab number. Cannot calibrate";
		   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   missing_data = true;
		   }

		 int iReservoir;
		 if (!Date->Age.IsEmpty())
		   CalibDate.Age = (int)Date->Age;
		 else
		   missing_data = true;
		 if (Date->ErrorOlder.IsEmpty() || Date->ErrorYounger.IsEmpty())
		   missing_data = true;
		 else {
		   if (Date->ErrorYounger == Date->ErrorOlder)
			 CalibDate.SD = (int)Date->ErrorYounger;
		   else
			 CalibDate.SD = (int)Max((double)Date->ErrorYounger, (double)Date->ErrorOlder);
		   }

		 if (missing_data)
		   continue;

		 ChronControl->AgeUnits = L"Calendar";

		 map<UnicodeString,Variant>::iterator itr = Date->Parameters.find(L"Reservoir (yrs)");
		 if (itr != Date->Parameters.end()) {
		   iReservoir = (int)VariantToDouble(itr->second, 0);
		   if (iReservoir > 0)
			 CalibDate.Age -= iReservoir;
		   }
		 CalibDates.push_back(CalibDate);

		 try {
			 if (OxCal.Calibrate(curve, CalibDates)) {
			   ChronControl->AgeValue = OxCal.ConvertAge(CalibDates[0].Median,1);
			   ChronControl->AgeLimitOlder = OxCal.ConvertAge(CalibDates[0].Ranges[0].Older,1);
			   ChronControl->AgeLimitYounger = OxCal.ConvertAge(CalibDates[0].Ranges.back().Younger,1);
			   ChronControl->ControlType = L"Radiocarbon, calibrated";
			   ChronControl->CalibCurve = curve.SubString(1,curve.Pos(L".")-1);
			   UnicodeString CalibProgram = CalibDates[0].ProgramVersion;
			   ChronControl->Calib.Program = L"OxCal";
			   // OxCal v4.2.4 Bronk Ramsey (2013); r:5
			   int pos = CalibProgram.Pos(L"v");
			   if (pos > 1) {
				 CalibProgram.Delete(1,pos);
				 pos = CalibProgram.Pos(L" ");
				 if (pos > 1)
				   ChronControl->Calib.Version = CalibProgram.SubString(1,pos-1);
				 }
			   }
			 }
		 catch(Exception &e) {
			 MessageDlg(e.Message, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			 delete ChronControl;
			 break;
			 }
		 }
	   else {
		 ChronControl->AgeValue = Date->Age;
		 if (!Date->ErrorOlder.IsEmpty())
		   ChronControl->AgeLimitOlder = (double)Date->Age + nsigma*(double)Date->ErrorOlder;
		 if (!Date->ErrorYounger.IsEmpty())
		   ChronControl->AgeLimitYounger = (double)Date->Age - nsigma*(double)Date->ErrorYounger;
		 if (SameText(Date->Method, L"Carbon-14")) {
		   ChronControl->ControlType = L"Radiocarbon";
		   ChronControl->AgeUnits = L"Radiocarbon";
		   }
		 }
	   ChronControl->GeochronIDs.push_back(Date->ID);
	   AgeModel->ChronControls->Add(ChronControl);
	   transferred++;
	   }
	 }
   if (transferred > 0) {
	 if (hasanalunits)
	   CheckBox3->Checked = true;
	 if (hasdepths || (!hasdepths && !hasanalunits))
	   CheckBox1->Checked = true;
	 ChronDataSource->DataChanged();
	 }
   Screen->Cursor = crDefault;
   if (missing_data) {
	 msg = L"Some radiocarbon dates had missing data and were not calibrated.";
	 MessageDlg(msg, mtWarning, TMsgDlgButtons() << mbOK, 0);
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::co_family_namePropertiesValidate(TObject *Sender,
		  Variant &DisplayValue, TCaption &ErrorText, bool &Error)
{
   CONTACT *Contact = ContactList->Contacts[ContactsGridCardView1->Controller->FocusedRecord->RecordIndex];
   UnicodeString FamilyName = VarToStr(DisplayValue);
   if (!SameText(Contact->FamilyName, FamilyName)) {
	 Contact->NeotomaContactID = -1;
	 Contact->NeotomaAliasID = -1;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::co_family_namePropertiesButtonClick(TObject *Sender,
		  int AButtonIndex)
{
   if (((TcxButtonEdit*)Sender)->Text.IsEmpty()) {
	 MessageDlg("A Family Name must be entered for a Neotoma search!", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 return;
	 }
   ContactsGridCardView1->DataController->Post();
   CONTACT *Contact = ContactList->Contacts[ContactsGridCardView1->Controller->FocusedRecord->RecordIndex];
   TGetNeotomaContact* GetNeotomaContactForm = new TGetNeotomaContact(Contact, this);
   GetNeotomaContactForm->ShowModal();
   delete GetNeotomaContactForm;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::co_leading_initialsPropertiesValidate(TObject *Sender,
          Variant &DisplayValue, TCaption &ErrorText, bool &Error)
{
   CONTACT *Contact = ContactList->Contacts[ContactsGridCardView1->Controller->FocusedRecord->RecordIndex];
   UnicodeString LeadingInitials = VarToStr(DisplayValue);
   if (!SameText(Contact->LeadingInitials, LeadingInitials)) {
	 Contact->NeotomaContactID = -1;
	 Contact->NeotomaAliasID = -1;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::co_suffixPropertiesValidate(TObject *Sender,
		  Variant &DisplayValue, TCaption &ErrorText, bool &Error)
{
   CONTACT *Contact = ContactList->Contacts[ContactsGridCardView1->Controller->FocusedRecord->RecordIndex];
   UnicodeString Suffix = VarToStr(DisplayValue);
   if (!SameText(Contact->Suffix, Suffix)) {
	 Contact->NeotomaContactID = -1;
	 Contact->NeotomaAliasID = -1;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::ContactsGridCardView1DataControllerCompare(TcxCustomDataController *ADataController,
		  int ARecordIndex1, int ARecordIndex2, int AItemIndex,
          const Variant &V1, const Variant &V2, int &Compare)
{
   UnicodeString S1 = VarToStr(V1);
   UnicodeString S2 = VarToStr(V2);
   Compare = CompareText(S1,S2);
}
//---------------------------------------------------------------------------

// calibrate dated taxon
void __fastcall TTilSpreadSheetForm::cxButton17Click(TObject *Sender)
{
   UnicodeString msg;
   UnicodeString curve;

   // int idx1 = cxGrid2TableView1->Controller->FocusedRecordIndex;
   // int idx1 = cxGrid2TableView1->DataController->FocusedRecordIndex;
   int idx1 = cxGrid2TableView1->Controller->FocusedRecord->RecordIndex;
   int idx2 = cxGrid2TableView1->DataController->GetDetailDataController(idx1,0)->FocusedRecordIndex;

   if (idx2 >= 0) {
	 vector<CALIBDATE> CalibDates;
	 CALIBDATE CalibDate;
	 OXCAL OxCal(ipsJSONS1, TcpClient1);
	 SITE* site_ptr = (SITE*)Sites->Items[0];
	 if (site_ptr->LatNorth.IsEmpty()) {
	   msg = L"Enter site latitude on site tabsheet to designate IntCal13 or SHCal13 calibration curve";
	   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return;
	   }
	 else {
	   curve = (site_ptr->LatNorth >= 0.0) ? L"IntCal13.14c" : L"ShCal13.14c";
	   GEOCHRON* Date = &GeochronList->Dates[idx1];
	   if (!Date->LabNumber.IsEmpty())
		 CalibDate.LabNumber = Date->LabNumber;
	   else {
		 msg = L"OxCal requires a lab number. Cannot calibrate";
		 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 return;
		 }
	   if (Date->Age.IsEmpty()) {
		 msg = L"Age missing. Cannot calibrate.";
		 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 return;
		 }
	   else
		 CalibDate.Age = (int)Date->Age;
	   if (Date->ErrorOlder.IsEmpty() || Date->ErrorYounger.IsEmpty()) {
		 msg = L"SD missing. Cannot calibrate.";
		 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 return;
		 }
	   else {
		 if (Date->ErrorYounger == Date->ErrorOlder)
		   CalibDate.SD = (int)Date->ErrorYounger;
		 else
		   CalibDate.SD = (int)Max((double)Date->ErrorYounger, (double)Date->ErrorOlder);
		 }
	   CalibDates.push_back(CalibDate);
	   Screen->Cursor = crHourGlass;
	   try {
		   if (OxCal.Calibrate(curve, CalibDates)) {
			 Date->TaxaDated[idx2].CalAgeMedian = OxCal.ConvertAge(CalibDates[0].Median,1);
			 Date->TaxaDated[idx2].CalAgeOlder = OxCal.ConvertAge(CalibDates[0].Ranges[0].Older,1);
			 Date->TaxaDated[idx2].CalAgeYounger = OxCal.ConvertAge(CalibDates[0].Ranges.back().Younger,1);
			 Date->TaxaDated[idx2].CalibCurve = curve.SubString(1,curve.Pos(L".")-1);
			 UnicodeString CalibProgram = CalibDates[0].ProgramVersion;
			 Date->TaxaDated[idx2].Calib.Program = L"OxCal";
			 // OxCal v4.2.4 Bronk Ramsey (2013); r:5
			 int pos = CalibProgram.Pos(L"v");
			 if (pos > 1) {
			   CalibProgram.Delete(1,pos);
			   pos = CalibProgram.Pos(L" ");
			   if (pos > 1)
				 Date->TaxaDated[idx2].Calib.Version = CalibProgram.SubString(1,pos-1);
			   }
			 TaxonDatedDataSource->DataChanged();
			 if (Downloaded && tiLicense->Type() == verNEOTOMASTEWARD) {
			   msg = L"Update calibrated specimen date in Neotoma?";
			   if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes)
				 UpdateTaxonDated(Date->TaxaDated[idx2]);
			   }
			 }
		   }
	   catch(Exception &e) {
		   MessageDlg(e.Message, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   }
	   Screen->Cursor = crDefault;
	   }
	 }
}
//---------------------------------------------------------------------------

// new fraction dated
void __fastcall TTilSpreadSheetForm::cxButton18Click(TObject *Sender)
{
   NewFractionForm = new TNewFractionForm(this);
   NewFractionForm->ShowModal();
   delete NewFractionForm;
}
//---------------------------------------------------------------------------

// load fractions into ComboBox -- this is necessary if a new fraction has been added
void __fastcall TTilSpreadSheetForm::txFractionPropertiesInitPopup(TObject *Sender)
{
   TcxComboBox* ComboBox = (TcxComboBox*)Sender;
   TcxComboBoxProperties* Fractions = (TcxComboBoxProperties*)(txFraction->Properties);
   ComboBox->Properties->Items->Clear();
   ComboBox->Properties->Items->AddStrings(Fractions->Items);
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::ReplaceSynonyms(vector<SYNONYMROW>& synrows, short SubVarCodes,
	 short SubGroups, short SubElements, short SubUnits, UnicodeString UnitsValue)
{
   // TODO: replace synonyms in other worksheets

   TAXON_NOTES* TaxonNotes;
   for (unsigned int i=0; i<synrows.size(); i++) {
	 if (synrows[i].replace) {
	   int row = synrows[i].row;
	   TProfGridCell *NameCell = ProfGrid1->AbsoluteCells[2][row];
	   TAXON* Taxon = synrows[i].taxon;
	   if (synrows[i].orig_id) {
		 CELLOBJECT* CellObject;
		 if (NameCell->CellObject)
		   //TaxonNotes = (TAXON_NOTES*)NameCell->CellObject;
		   CellObject = (CELLOBJECT*)NameCell->CellObject;
		 else {
		   //TaxonNotes = new TAXON_NOTES;
		   //CellObjects[(TObject*)TaxonNotes] = CELLTAXONNOTES;
		   //NameCell->CellObject = (TObject*)TaxonNotes;
		   CellObject = new CELLOBJECT(CELLTAXONNOTES);
		   //CellObjects.push_back(CellObject);
		   //NameCell->CellObject = (TObject*)CellObject;
		   //AddTaxonNotesIcon(NameCell);
		   AddCellObject(NameCell, CellObject);
		   }
		 TaxonNotes = (TAXON_NOTES*)CellObject->Object;
		 SYNONYMY Synonym;
		 Synonym.TaxonName = NameCell->Text;
		 TaxonNotes->Synonymy.push_back(Synonym);
		 }
	   NameCell->Value = Taxon->Name;
	   ReplaceVarCodes(Taxon, row, SubVarCodes);
	   ReplaceGroupCodes(Taxon, row, SubGroups);
	   ReplaceElements(Taxon, row, SubElements);
	   ReplaceUnits(Taxon, row, SubUnits, UnitsValue);
	   SpreadSheetChanged = true;
	   }
	 }
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::ReplaceVarCodes(TAXON* Taxon, int row, short SubVarCodes)
{
   TProfGridCell *ACell = ProfGrid1->AbsoluteCells[1][row];
   UnicodeString NewCode = Taxon->Code;
   if (SubVarCodes == SUBALL || (SubVarCodes == SUBBLANK && ACell->IsEmpty())) {
	 UnicodeString OldCode = VarToStr(ACell->Value);
	 int colon_pos = OldCode.Pos(L":");
	 if (colon_pos > 0) {
	   UnicodeString modifiers = OldCode.Delete(1,colon_pos-1);  // include colon
	   ACell->Value = NewCode + modifiers;
	   }
	 else
	   ACell->Value = NewCode;
	 }
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::ReplaceGroupCodes(TAXON* Taxon, int row, short SubGroups)
{
   TProfGridCell *ACell = ProfGrid1->AbsoluteCells[7][row];
   if (SubGroups == SUBALL || (SubGroups == SUBBLANK && ACell->IsEmpty()))
	 ACell->Value = Taxon->EcolGroup;
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::ReplaceElements(TAXON* Taxon, int row, short SubElements)
{
   TProfGridCell *ACell = ProfGrid1->AbsoluteCells[3][row];
   if (SubElements == SUBALL || (SubElements == SUBBLANK && ACell->IsEmpty())) {
	 if (Taxon->Elements.size() == 1)
	   ACell->Value = Taxon->Elements[0].Name;
	 else if (ContainsText(Datasets[0].DatasetType, L"pollen")) {
	   // if pollen or spore, use whichever
	   // if pollen and spore and pollen/spore, use pollen/spore
	   bool pollen = false;
	   bool spore = false;
	   int pollen_spore = -1;
	   int elem = 0;
	   for (unsigned int i=0; i<Taxon->Elements.size(); i++) {
		 UnicodeString Element = Taxon->Elements[i].Name;
		 if (!pollen && SameText(Element, L"pollen"))
		   { pollen = true; elem = i; }
		 else if (!spore && SameText(Element, L"spore"))
		   { spore = true; elem = i; }
		 else if (pollen_spore == -1 && SameText(Element, L"pollen/spore"))
		   pollen_spore = i;
		 }
	   if (pollen != spore)
		 ACell->Value = Taxon->Elements[elem].Name;
	   else if (pollen && spore && pollen_spore > -1)
		 ACell->Value = Taxon->Elements[pollen_spore].Name;
	   }
	 }
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::ReplaceUnits(TAXON* Taxon, int row, short SubUnits, UnicodeString UnitsValue)
{
   TProfGridCell *ACell = ProfGrid1->AbsoluteCells[4][row];
   if (SubUnits == SUBALL || (SubUnits == SUBBLANK && ACell->IsEmpty())) {
	 if (!UnitsValue.IsEmpty())
	   ACell->Value = UnitsValue;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::AdvControlDropDown3DropUp(TObject *Sender, bool Cancelled)
{
   //if (ModifierType == MODTAPH && TaphStatus == TAPHNONE)
   //	 PostTaphonomy();

   switch (ModifierType) {
	 case MODELEMENT:

	   break;
	 case MODTAPH:
	   if (TaphStatus == TAPHNONE)
	     PostTaphonomy();
	   break;
	 }
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::PostElement(void)
{
   if (cxCheckListBox1->ItemIndex > -1) {
	 UnicodeString TaxaGroup = cxCheckListBox1->Items->Items[cxCheckListBox1->ItemIndex]->Text;
	 AdvControlDropDown3->Text = TaxaGroup;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::AdvControlDropDown3Exit(TObject *Sender)
{
   ProfGrid1->RowHeights[ProfGrid1->Row] = CurrentRowHeight;
}
//---------------------------------------------------------------------------



void __fastcall TTilSpreadSheetForm::chCalibProgramPropertiesInitPopup(
      TObject *Sender)
{
   CalibProgramPopup = CALIBAGEMODEL;
   if (AdvColumnGrid9->VisibleRowCount == AdvColumnGrid9->RowCount - 1) {
	 AdvColumnGrid9->Columns->Items[0]->Width = 73;
	 //AdvColumnGrid9->Columns->Items[0]->Width = 72;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::txCalibProgramPropertiesInitPopup(TObject *Sender)
{
   CalibProgramPopup = CALIBGEOCHRON;
   if (AdvColumnGrid9->VisibleRowCount == AdvColumnGrid9->RowCount - 1) {
	 AdvColumnGrid9->Columns->Items[0]->Width = 73;
	 //AdvColumnGrid9->Columns->Items[0]->Width = 72;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::chCalibProgramPropertiesPopup(
	  TObject *Sender)
{
   chCalibProgramPopupEdit = (TcxPopupEdit*)Sender;

   int RecordIndex1 = cxGrid3TableView1->Controller->FocusedRecordIndex;
   int RecordIndex2 = CurrentChronControlView->DataController->FocusedRecordIndex;
   AGEMODEL* AgeModel = AgeModelList->AgeModels[RecordIndex1];
   bool selected = false;
   if (RecordIndex2 >= 0) {
	 CHRON* ChronControl = (CHRON*)AgeModel->ChronControls->Items[RecordIndex2];
	 for (int row=1; row<AdvColumnGrid9->RowCount; row++) {
	   if (SameText(AdvColumnGrid9->Cells[0][row], ChronControl->Calib.Program) &&
		   SameText(AdvColumnGrid9->Cells[1][row], ChronControl->Calib.Version)) {
		 AdvColumnGrid9->Row = row;
		 selected = true;
		 break;
		 }
	   }
	 }
   if (!selected)
	 AdvColumnGrid9->Row = 1;
   CalibProgramSelected = false;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::txCalibProgramPropertiesPopup(TObject *Sender)
{
   txCalibProgramPopupEdit = (TcxPopupEdit*)Sender;

   int RecordIndex1 = cxGrid2TableView1->Controller->FocusedRecordIndex;

   int RecordIndex2 =
	 cxGrid2TableView1->DataController->GetDetailDataController(RecordIndex1,0)->FocusedRecordIndex;

   GEOCHRON* Geochron = &GeochronList->Dates[RecordIndex1];
   bool selected = false;
   if (RecordIndex2 >= 0) {
	 for (int row=1; row<AdvColumnGrid9->RowCount; row++) {
	   if (SameText(AdvColumnGrid9->Cells[0][row], Geochron->TaxaDated[RecordIndex2].Calib.Program) &&
		   SameText(AdvColumnGrid9->Cells[1][row], Geochron->TaxaDated[RecordIndex2].Calib.Program)) {
		 AdvColumnGrid9->Row = row;
		 selected = true;
		 break;
		 }
	   }
	 }
   if (!selected)
	 AdvColumnGrid9->Row = 1;
   CalibProgramSelected = false;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::AdvColumnGrid9ClickCell(TObject *Sender, int ARow,
		  int ACol)
{
   if (ARow > 0) {
	 CalibProgramSelected = true;
	 if (CalibProgramPopup == CALIBAGEMODEL)
	   chCalibProgramPopupEdit->DroppedDown = false;
	 else if (CalibProgramPopup == CALIBGEOCHRON)
	   txCalibProgramPopupEdit->DroppedDown = false;
	 }
}
//---------------------------------------------------------------------------


void __fastcall TTilSpreadSheetForm::chCalibProgramPropertiesCloseUp(
      TObject *Sender)
{
   if (!CalibProgramSelected) return;

   int row = AdvColumnGrid9->Row;
   UnicodeString Program = AdvColumnGrid9->Cells[0][row];
   UnicodeString Version = AdvColumnGrid9->Cells[1][row];

   UnicodeString Text = Program;
   if (!Version.IsEmpty());
	 Text += (" " + Version);
   ((TcxPopupEdit*)Sender)->Text = Text;

   int RecordIndex1 = cxGrid3TableView1->Controller->FocusedRecordIndex;
   int RecordIndex2 = CurrentChronControlView->DataController->FocusedRecordIndex;
   if (RecordIndex2 == -1) {
	 NewRecordCalibProgram.Program = Program;
	 NewRecordCalibProgram.Version = Version;
	 }
   else {
	 AGEMODEL* AgeModel = AgeModelList->AgeModels[RecordIndex1];
	 CHRON* ChronControl = (CHRON*)AgeModel->ChronControls->Items[RecordIndex2];
	 ChronControl->Calib.Program = Program;
	 ChronControl->Calib.Version = Version;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::txCalibProgramPropertiesCloseUp(TObject *Sender)
{
   if (!CalibProgramSelected) return;

   int row = AdvColumnGrid9->Row;
   UnicodeString Program = AdvColumnGrid9->Cells[0][row];
   UnicodeString Version = AdvColumnGrid9->Cells[1][row];

   UnicodeString Text = Program;
   if (!Version.IsEmpty());
	 Text += (" " + Version);
   ((TcxPopupEdit*)Sender)->Text = Text;

   int RecordIndex1 = cxGrid2TableView1->Controller->FocusedRecordIndex;
   int RecordIndex2 =
	 cxGrid2TableView1->DataController->GetDetailDataController(RecordIndex1,0)->FocusedRecordIndex;

   if (RecordIndex2 == -1) {
	 NewRecordCalibProgram.Program = Program;
	 NewRecordCalibProgram.Version = Version;
	 }
   else {
	 GEOCHRON* Geochron = &GeochronList->Dates[RecordIndex1];
	 Geochron->TaxaDated[RecordIndex2].Calib.Program = Program;
	 Geochron->TaxaDated[RecordIndex2].Calib.Version = Version;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::chCalibProgramPropertiesEditValueChanged(
      TObject *Sender)
{
   UnicodeString Text = ((TcxPopupEdit*)Sender)->Text;
   if (Text.IsEmpty()) {
	 int RecordIndex1 = cxGrid3TableView1->Controller->FocusedRecordIndex;
	 int RecordIndex2 = CurrentChronControlView->DataController->FocusedRecordIndex;
	 AGEMODEL* AgeModel = AgeModelList->AgeModels[RecordIndex1];
	 CHRON* ChronControl = (CHRON*)AgeModel->ChronControls->Items[RecordIndex2];
	 ChronControl->Calib.Program.SetLength(0);
	 ChronControl->Calib.Version.SetLength(0);
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::txCalibProgramPropertiesEditValueChanged(TObject *Sender)
{
   UnicodeString Text = ((TcxPopupEdit*)Sender)->Text;
   if (Text.IsEmpty()) {
	 int RecordIndex1 = cxGrid2TableView1->Controller->FocusedRecordIndex;
	 int RecordIndex2 =
	   cxGrid2TableView1->DataController->GetDetailDataController(RecordIndex1,0)->FocusedRecordIndex;

	 GEOCHRON* Geochron = &GeochronList->Dates[RecordIndex1];
	 Geochron->TaxaDated[RecordIndex2].Calib.Program.SetLength(0);
	 Geochron->TaxaDated[RecordIndex2].Calib.Version.SetLength(0);
	 }
}
//---------------------------------------------------------------------------


void __fastcall TTilSpreadSheetForm::CalibProgramGetDisplayText(TcxCustomGridTableItem *Sender,
		  TcxCustomGridRecord *ARecord, UnicodeString &AText)
{
   // display calibration program info
   if (!ARecord) return;

   if (ARecord->RecordIndex == -1) {
	 UnicodeString Text = NewRecordCalibProgram.Program;
	 if (!Text.IsEmpty() && !NewRecordCalibProgram.Version.IsEmpty())
	   Text += NewRecordCalibProgram.Version;
	 AText = Text;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxGrid3TableView2DataControllerAfterPost(TcxCustomDataController *ADataController)
{
   UnicodeString msg;

   int RecordIndex1 = cxGrid3TableView1->Controller->FocusedRecordIndex;
   // int RecordIndex2 = ADataController->FocusedRowIndex;  // this is wrong!
   int RecordIndex2 = ADataController->FocusedRecordIndex;  // this accounts for sorting

   AGEMODEL* AgeModel = AgeModelList->AgeModels[RecordIndex1];
   if (RecordIndex2 == -1) {
	 CHRON* ChronControl = (CHRON*)AgeModel->ChronControls->Last();
	 ChronControl->Calib.Program = NewRecordCalibProgram.Program;
	 ChronControl->Calib.Version = NewRecordCalibProgram.Version;
	 NewRecordCalibProgram.Program = L"";
	 NewRecordCalibProgram.Version = L"";
	 ADataController->Values[-1][chCalibProgram->Index] = "";

	 ChronControl->GeochronIDs = NewGeochronIDs;
	 NewGeochronIDs.clear();
	 ADataController->Values[-1][chGeochron->Index] = "";
	 }

   //  TODO: This is code for uploading new chron controls or updating existing
   //  chron controls. Functions UploadChronControl and UpdateTaxonDated still need
   //  to be written.

   CHRON* ChronControl;
   if (Downloaded && tiLicense->Type() == verNEOTOMASTEWARD) {
	 if (AgeModel->NeotomaChronologyID != -1) {
	   int NeotomaChronControlID = -1;
	   if (RecordIndex2 != -1) {
		 ChronControl = (CHRON*)AgeModel->ChronControls->Items[RecordIndex2];
		 NeotomaChronControlID = ChronControl->NeotomaChronControlID;
		 if (NeotomaChronControlID != -1) {
		   if (*ChronControl != *InitChronControl) {
			 msg = L"Update chronology control in Neotoma?";
			 if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes)
			   UpdateChronControl(ChronControl, AgeModel);
			 }
		   }
		 }
	   if (RecordIndex2 == -1 || NeotomaChronControlID == -1) {
		 msg = L"Upload chronology control to Neotoma?";
		 if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes) {
		   if (RecordIndex2 == -1)
			 ChronControl = (CHRON*)AgeModel->ChronControls->Last();
		   else
			 ChronControl = (CHRON*)AgeModel->ChronControls->Items[RecordIndex2];
		   InsertChronControl(ChronControl, AgeModel);
		   }
		 }
	   }
	 }
}
//---------------------------------------------------------------------------

bool TTilSpreadSheetForm::IsAgeYounger(Variant vAge, Variant vAgeOlder, UnicodeString AgeUnits)
{
   double Age = VariantToDouble(vAge,0.0);
   double AgeOlder = VariantToDouble(vAgeOlder,0.0);

   if (ContainsText(AgeUnits, L"AD/BC")) {
	 if (AgeOlder > Age)
	   return false;
	 }
   else if (AgeOlder < Age)
	 return false;
   return true;
}
//---------------------------------------------------------------------------

bool TTilSpreadSheetForm::IsAgeOlder(Variant vAge, Variant vAgeYounger, UnicodeString AgeUnits)
{
   double Age = VariantToDouble(vAge,0.0);
   double AgeYounger = VariantToDouble(vAgeYounger,0.0);

   if (ContainsText(AgeUnits, L"AD/BC")) {
	 if (AgeYounger < Age)
	   return false;
	 }
   else if (AgeYounger > Age)
	 return false;
   return true;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxButton5Click(TObject *Sender)
{
   CalibProgramSelected = false;
   if (CalibProgramPopup == CALIBAGEMODEL)
	 chCalibProgramPopupEdit->DroppedDown = false;
   else
	 txCalibProgramPopupEdit->DroppedDown = false;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxButton6Click(TObject *Sender)
{
   map<UnicodeString, pair<UnicodeString,UnicodeString> > calibprogs;
   UnicodeString calibprog;

   TAddCalibProgForm* AddCalibForm = new TAddCalibProgForm(this);
   AddCalibForm->SetPosition(Mouse->CursorPos.x, Mouse->CursorPos.y);
   if (AddCalibForm->ShowModal() == mrOk) {
	 if (!AddCalibForm->LabeledEdit1->Text.IsEmpty()) {
	   calibprog = AddCalibForm->LabeledEdit1->Text + L" " + AddCalibForm->LabeledEdit2->Text;
	   calibprogs[calibprog] = pair<UnicodeString,UnicodeString>(AddCalibForm->LabeledEdit1->Text, AddCalibForm->LabeledEdit2->Text);
	   for (int row = 1; row < AdvColumnGrid9->RowCount; row++) {
		 calibprog = AdvColumnGrid9->Cells[0][row] + L" " + AdvColumnGrid9->Cells[1][row];
		 calibprogs[calibprog] = pair<UnicodeString,UnicodeString>(AdvColumnGrid9->Cells[0][row],AdvColumnGrid9->Cells[1][row]);
		 }

	   AdvColumnGrid9->RowCount++;
	   map<UnicodeString, pair<UnicodeString,UnicodeString> >::iterator itr;
	   int row = 1;
	   for (itr = calibprogs.begin(); itr != calibprogs.end(); itr++) {
		 AdvColumnGrid9->Cells[0][row] = itr->second.first;
		 AdvColumnGrid9->Cells[1][row++] = itr->second.second;
		 }
       }
     }
   delete AddCalibForm;
}
//---------------------------------------------------------------------------

// Taxa lookup from Geochron tabsheeet
void __fastcall TTilSpreadSheetForm::cxButton4Click(TObject *Sender)
{
   UnicodeString TaxaFile, ElementsFile;

   ShortVarLookupForm = new TShortVarLookupForm(this);

   if (ShortVarLookupForm->ShowModal() == mrOk) {
     Repaint();
	 TaxaFile = ShortVarLookupForm->cxTextEdit1->Text;
	 ElementsFile = ShortVarLookupForm->cxTextEdit2->Text;
	 Screen->Cursor = crHourGlass;

	 if (!TaxaFile.IsEmpty()) {
	   txml = new TAXAXML();
	   ParseTaxa = new PARSETAXA(ipwXMLp6, this);
	   bool rv = ParseTaxa->Parse(TaxaFile);
	   delete txml;

	   GeochronTaxaEcolGroups.clear();
	   GeochronTaxaEcolGroups = ParseTaxa->TaxaEcolGroups;

	   TaxaList = ParseTaxa->TaxaList;
	   if (rv && ParseTaxa->TaxaList.size()) {
		 if (GeochronTaxaOpen)
		   GeochronTaxaList.clear();
		 GeochronTaxaList = TaxaList;
		 GeochronTaxaOpen = true;
		 }
	   delete ParseTaxa;
	   }

	 if (!ElementsFile.IsEmpty()) {
	   if (GeochronElementLookup) {
		 delete GeochronElementLookup;
		 GeochronElementLookup = NULL;
		 GeochronVarLookup->SetElementLookup(NULL);
		 }
	   GeochronElementLookup = new ELEMENTLOOKUP(GeochronTaxaEcolGroups);
	   if (GeochronElementLookup->Load(ElementsFile, ipwXMLp1, false)) {
		 GeochronVarLookup->SetElementLookup(GeochronElementLookup);
		 vector<UnicodeString> DatasetTypes;
		 GeochronElementLookup->GetDatasetTypes(DatasetTypes);
		 }
	   else {
		 delete GeochronElementLookup;
		 GeochronElementLookup = NULL;
		 GeochronVarLookup->SetElementLookup(NULL);
		 }
	   }
	 }

   delete VarLookupForm;
   Screen->Cursor = crDefault;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::ProfGridGeochronMouseMove(
      TObject *Sender, TShiftState Shift, int X, int Y)
{
   int ACol, ARow;
   if (ProfGridGeochron->MouseToCell(X, Y, ACol, ARow)) {
     if (ProfGridGeochron->SelectionColor != clHighlight) {
       ProfGridGeochron->SelectionColor = clHighlight;
       ProfGridGeochron->SelectionFontColor = clHighlightText;
       }
	 ProfGridGeochron->SetSelection(0, ARow, 4, ARow);
     }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::ProfGridGeochronMouseDown(
      TObject *Sender, TMouseButton Button, TShiftState Shift, int X,
      int Y)
{
   int ACol, ARow;
   if (ProfGridGeochron->MouseToCell(X, Y, ACol, ARow))
     ProfGridGeochron->Cells[0][ARow]->CheckBoxChecked =
       !ProfGridGeochron->Cells[0][ARow]->CheckBoxChecked;
}
//---------------------------------------------------------------------------

// --> Age Model tabsheet

void __fastcall TTilSpreadSheetForm::GenerateAgeModelColumns()
{
   amChronNo->DataBinding->Data = (TObject*)IndexOfamChronNo;
   amName->DataBinding->Data = (TObject*)IndexOfamName;
   amAgeUnits->DataBinding->Data = (TObject*)IndexOfamAgeUnits;
   amDefault->DataBinding->Data = (TObject*)IndexOfamDefault;
   amAgeModel->DataBinding->Data = (TObject*)IndexOfamAgeModel;
   amOlderBound->DataBinding->Data = (TObject*)IndexOfamOlderBound;
   amYoungerBound->DataBinding->Data = (TObject*)IndexOfamYoungerBound;
   amPreparer->DataBinding->Data = (TObject*)IndexOfamPreparers;
   amDatePrepared->DataBinding->Data = (TObject*)IndexOfamDatePrepared;
   amNotes->DataBinding->Data = (TObject*)IndexOfamNotes;

   // this line is critical
   cxGrid3TableView1->DataController->CustomDataSource = AgeModelDataSource;

   chDepth->DataBinding->Data = (TObject*)IndexOfchDepth;
   chThickness->DataBinding->Data = (TObject*)IndexOfchThickness;
   chAnalUnit->DataBinding->Data = (TObject*)IndexOfchAnalUnit;
   chAgeUnits->DataBinding->Data = (TObject*)IndexOfchAgeUnits;
   chAge->DataBinding->Data = (TObject*)IndexOfchAge;
   chOlderLimit->DataBinding->Data = (TObject*)IndexOfchOlderLimit;
   chYoungerLimit->DataBinding->Data = (TObject*)IndexOfchYoungerLimit;
   chAgeBasis->DataBinding->Data = (TObject*)IndexOfchAgeBasis;
   chCalibCurve->DataBinding->Data = (TObject*)IndexOfchCalibCurve;
   chCalibProgram->DataBinding->Data = (TObject*)IndexOfchCalibProgram;
   chGeochron->DataBinding->Data = (TObject*)IndexOfchGeochron;

   // this line is critical
   cxGrid3TableView2->DataController->CustomDataSource = ChronDataSource;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::amOlderBoundPropertiesValidate(
      TObject *Sender, Variant &DisplayValue, TCaption &ErrorText,
      bool &Error)
{
   ValidateNumericalDisplayValue(DisplayValue, ErrorText, Error);
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::amYoungerBoundPropertiesValidate(
      TObject *Sender, Variant &DisplayValue, TCaption &ErrorText,
      bool &Error)
{
   ValidateNumericalDisplayValue(DisplayValue, ErrorText, Error);
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::chDepthPropertiesValidate(
      TObject *Sender, Variant &DisplayValue, TCaption &ErrorText,
      bool &Error)
{
   ValidateNumericalDisplayValue(DisplayValue, ErrorText, Error);
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::chThicknessPropertiesValidate(
	  TObject *Sender, Variant &DisplayValue, TCaption &ErrorText,
      bool &Error)
{
   ValidateNumericalDisplayValue(DisplayValue, ErrorText, Error);
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::chAgePropertiesValidate(
      TObject *Sender, Variant &DisplayValue, TCaption &ErrorText,
      bool &Error)
{
   ValidateNumericalDisplayValue(DisplayValue, ErrorText, Error);
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::chOlderLimitPropertiesValidate(
      TObject *Sender, Variant &DisplayValue, TCaption &ErrorText,
      bool &Error)
{
   ValidateNumericalDisplayValue(DisplayValue, ErrorText, Error);
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::chYoungerLimitPropertiesValidate(
      TObject *Sender, Variant &DisplayValue, TCaption &ErrorText,
      bool &Error)
{
   ValidateNumericalDisplayValue(DisplayValue, ErrorText, Error);
}
//---------------------------------------------------------------------------

// --> contacts tabsheet

void __fastcall TTilSpreadSheetForm::TabSheetContactsShow(TObject *Sender)
{
   FocusControl(ContactsGrid);
   if (ContactsGridCardView1->Controller->FocusedRecordIndex < 0)
     ContactsGridCardView1->Controller->FocusedRecordIndex = 0;
}
//---------------------------------------------------------------------------

// --> site tabsheet

void __fastcall TTilSpreadSheetForm::TabSheetSiteShow(TObject *Sender)
{
   if (Edit1->Enabled)
	 FocusControl(Edit1);
   else
     FocusControl(cxMemo1);
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxComboBox7PropertiesValidate(
	  TObject *Sender, Variant &DisplayValue, TCaption &ErrorText,
      bool &Error)
{
   UnicodeString Country = DisplayValue;
   SitePtr->Country = Country;
   GeoPolUnits->SetGeoPolRec1(Country);
   if (!SameText(Country, CurrentCountry)) {
	 SitePtr->State = L"";
	 SitePtr->County = L"";
	 SitePtr->AdminUnit = L"";
	 }
   SetStateProvinceList();
   SetAdminUnitList1();
   //UnicodeString Unit = GeoPolUnits->GetUnit1(Country);
   UnicodeString Unit = GeoPolUnits->GetUnit1();
   SetGeoPolCaption("First", Unit, cxComboBox7, Label6);
   Label7->Caption = "Second Geopolitical Divsion";
   Label3->Caption = "Third Geopolitical Divsion";
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxComboBox7Exit(TObject *Sender)
{
   if (cxComboBox7->Text.IsEmpty()) {
	 SitePtr->Country = L"";
	 CurrentCountry = L"";
	 SitePtr->State = L"";
	 SitePtr->County = L"";
	 SitePtr->AdminUnit = L"";
	 SetStateProvinceList();
	 SetAdminUnitList1();
	 Label6->Caption = "First Geopolitical Divsion";
	 Label7->Caption = "Second Geopolitical Divsion";
	 Label3->Caption = "Third Geopolitical Divsion";
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxComboBox8PropertiesValidate(
	  TObject *Sender, Variant &DisplayValue, TCaption &ErrorText,
	  bool &Error)
{
   UnicodeString State = DisplayValue;
   SitePtr->State = State;
   GeoPolUnits->SetGeoPolRec2(State);

   if (!SameText(State, CurrentState)) {
	 SitePtr->County = L"";
	 SitePtr->AdminUnit = L"";
	 }

   SetCountyList();
   SetAdminUnitList2();
   UnicodeString Unit = GeoPolUnits->GetUnit2();
   SetGeoPolCaption("Second", Unit, cxComboBox8, Label7);
   Label3->Caption = "Third Geopolitical Divsion";
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxComboBox8Exit(TObject *Sender)
{
   if (cxComboBox8->Text.IsEmpty()) {
	 SitePtr->State = L"";
	 SitePtr->County = L"";
	 cxComboBox9->ItemIndex = -1;
	 cxComboBox9->Properties->Items->Clear();
	 Label7->Caption = "Second Geopolitical Divsion";
	 Label3->Caption = "Third Geopolitical Divsion";
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxComboBox9Exit(TObject *Sender)
{
   if (cxComboBox9->Text.IsEmpty()) {
	 SitePtr->County = L"";
	 Label3->Caption = "Third Geopolitical Divsion";
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxComboBox10Exit(TObject *Sender)
{
   if (cxComboBox10->Text.IsEmpty())
	 SitePtr->AdminUnit = L"";
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxComboBox9PropertiesValidate(
      TObject *Sender, Variant &DisplayValue, TCaption &ErrorText,
      bool &Error)
{
   SitePtr->County = cxComboBox9->Text;
   GeoPolUnits->SetGeoPolRec3(cxComboBox9->Text);
   SetAdminUnitList3();
   UnicodeString Unit = GeoPolUnits->GetUnit3();
   SetGeoPolCaption("Third", Unit, cxComboBox9, Label3);
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxComboBox10PropertiesValidate(
	  TObject *Sender, Variant &DisplayValue, TCaption &ErrorText,
	  bool &Error)
{
   SitePtr->AdminUnit = cxComboBox10->Text;
   if (GeoPolUnits->SetGeoPolRec4(cxComboBox10->Text)) {
	 UnicodeString Unit = GeoPolUnits->GetUnit4();
     SetGeoPolCaption("Administrative unit", Unit, cxComboBox10, NULL);
     }
   else {
	 NewAdminUnit = new TNewAdminUnit(this);
	 SetupNewAdminUnitForm();

	 if (NewAdminUnit->ShowModal() == mrOk) {
       bool RadioButtonChecked = false;
	   if (NewAdminUnit->RadioButton1->Checked) {
		 GeoPolUnits->AddAdminUnit1(NewAdminUnit->LabeledEdit1->Text, NewAdminUnit->ComboBox1->Text);
         RadioButtonChecked = true;
         }
       else if (NewAdminUnit->RadioButton2->Checked) {
         TStringList* StateNames = new TStringList;
		 for (int i=0; i<NewAdminUnit->cxCheckComboBox1->Properties->Items->Count; i++)
		   if (NewAdminUnit->cxCheckComboBox1->States[i] == cbsChecked)
			 StateNames->Add(NewAdminUnit->cxCheckComboBox1->Properties->Items->Items[i]->Description);
         GeoPolUnits->AddAdminUnit2(StateNames, NewAdminUnit->LabeledEdit1->Text, NewAdminUnit->ComboBox1->Text);
		 delete StateNames;
         RadioButtonChecked = true;
         }
	   else if (NewAdminUnit->RadioButton3->Checked) {
         TStringList* CountyNames = new TStringList;
         for (int i=0; i<NewAdminUnit->cxCheckComboBox2->Properties->Items->Count; i++)
           if (NewAdminUnit->cxCheckComboBox2->States[i] == cbsChecked)
             CountyNames->Add(NewAdminUnit->cxCheckComboBox2->Properties->Items->Items[i]->Description);
		 GeoPolUnits->AddAdminUnit3(CountyNames, NewAdminUnit->LabeledEdit1->Text, NewAdminUnit->ComboBox1->Text);
         delete CountyNames;
         RadioButtonChecked = true;
		 }

	   cxComboBox10->Properties->Items->Clear();
       if (RadioButtonChecked) {
         if (!cxComboBox9->Text.IsEmpty())
           GeoPolUnits->GeoPol4Unit3(cxComboBox9->Text, cxComboBox10->Properties->Items);
         else if (!cxComboBox8->Text.IsEmpty())
           GeoPolUnits->GeoPol4Unit2(cxComboBox8->Text, cxComboBox10->Properties->Items);
         else if (!cxComboBox7->Text.IsEmpty())
           GeoPolUnits->GeoPol4Unit1(cxComboBox7->Text, cxComboBox10->Properties->Items);
         cxComboBox10->Text = NewAdminUnit->LabeledEdit1->Text;
         }

       if (NewAdminUnit->SaveFile)
         GeoPolUnits->Save();
       }
     delete NewAdminUnit;
     }
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::SetupNewAdminUnitForm()
{
   UnicodeString Caption;
   map<UnicodeString, UnicodeString> GeoPol2Units;  // map of GeoPol2 names and unit names
   map<UnicodeString, UnicodeString> GeoPol3Units;  // map of GeoPol3 names and unit names

   NewAdminUnit->LabeledEdit1->Text = cxComboBox10->Text;
   NewAdminUnit->Edit1->Text = cxComboBox7->Text;
   Caption = GeoPolUnits->GetUnit1();
   NewAdminUnit->RadioButton1->Caption = Capitalize(Caption);
   if (cxComboBox8->ItemIndex > -1) {
	 for (int i=0; i<cxComboBox8->Properties->Items->Count; i++) {
	   UnicodeString State = cxComboBox8->Properties->Items->Strings[i];
	   NewAdminUnit->cxCheckComboBox1->Properties->Items->AddCheckItem(State);
	   GeoPol2Units[State] = GeoPolUnits->GetUnitForGeoPol2(State); // populate GeoPol2 names/units map
	   }
	 NewAdminUnit->SetGeoPol2Units(GeoPol2Units);
	 NewAdminUnit->cxCheckComboBox1->ItemIndex = cxComboBox8->ItemIndex;
	 NewAdminUnit->cxCheckComboBox1->States[cxComboBox8->ItemIndex] = cbsChecked;
	 Caption = GeoPolUnits->GetUnit2();
	 NewAdminUnit->RadioButton2->Caption = Capitalize(Caption);
	 if (cxComboBox9->ItemIndex > -1) {
	   for (int i=0; i<cxComboBox9->Properties->Items->Count; i++) {
		 UnicodeString County = cxComboBox9->Properties->Items->Strings[i];
		 NewAdminUnit->cxCheckComboBox2->Properties->Items->AddCheckItem(County);
		 GeoPol3Units[County] = GeoPolUnits->GetUnitForGeoPol3(County);  // populate GeoPol3 names/units map
		 }
	   NewAdminUnit->SetGeoPol3Units(GeoPol3Units);
	   NewAdminUnit->cxCheckComboBox2->ItemIndex = cxComboBox9->ItemIndex;
	   NewAdminUnit->cxCheckComboBox2->States[cxComboBox9->ItemIndex] = cbsChecked;
	   Caption = GeoPolUnits->GetUnit3();
	   NewAdminUnit->RadioButton3->Caption = Capitalize(Caption);
	   }
	 else {
	   NewAdminUnit->cxCheckComboBox2->Enabled = false;
	   NewAdminUnit->RadioButton3->Caption = "Third Geopolitical Divsion";
	   NewAdminUnit->RadioButton3->Enabled = false;
	   }
	 }
   else {
	 NewAdminUnit->cxCheckComboBox1->Enabled = false;
	 NewAdminUnit->cxCheckComboBox2->Enabled = false;
	 NewAdminUnit->RadioButton2->Caption = "Second Geopolitical Divsion";
	 NewAdminUnit->RadioButton3->Caption = "Third Geopolitical Divsion";
	 NewAdminUnit->RadioButton2->Enabled = false;
	 NewAdminUnit->RadioButton3->Enabled = false;
	 NewAdminUnit->RadioButton1->Checked = true;
	 }
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::SetStateProvinceList (void)
{
   if (SameText(cxComboBox7->Text, CurrentCountry))
	 return;
   else {
	 CurrentCountry = cxComboBox7->Text;
	 cxComboBox8->ItemIndex = -1;
	 cxComboBox8->Properties->Items->Clear();  // clear state/prov combobox
	 cxComboBox9->ItemIndex = -1;
	 cxComboBox9->Properties->Items->Clear();
	 cxComboBox10->ItemIndex = -1;
     cxComboBox10->Properties->Items->Clear();
     }

   if (!cxComboBox7->Text.IsEmpty())
     GeoPolUnits->GeoPol2(cxComboBox7->Text, cxComboBox8->Properties->Items);
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::SetCountyList(void)
{
   if (SameText(cxComboBox8->Text, CurrentState))
     return;
   else {
	 CurrentState = cxComboBox8->Text;
	 cxComboBox9->ItemIndex = -1;
     cxComboBox9->Properties->Items->Clear();
     }

   if (!cxComboBox8->Text.IsEmpty())
     GeoPolUnits->GeoPol3(cxComboBox8->Text, cxComboBox9->Properties->Items);
}
//---------------------------------------------------------------------------

// country level
void TTilSpreadSheetForm::SetAdminUnitList1(void)
{
   cxComboBox10->ItemIndex = -1;
   cxComboBox10->Properties->Items->Clear();
   if (!cxComboBox7->Text.IsEmpty())
	 GeoPolUnits->GeoPol4Unit1(cxComboBox7->Text, cxComboBox10->Properties->Items);
}
//---------------------------------------------------------------------------

// state level
void TTilSpreadSheetForm::SetAdminUnitList2(void)
{
   cxComboBox10->ItemIndex = -1;
   cxComboBox10->Properties->Items->Clear();
   if (!cxComboBox8->Text.IsEmpty())
	 GeoPolUnits->GeoPol4Unit2(cxComboBox8->Text, cxComboBox10->Properties->Items);
}
//---------------------------------------------------------------------------

// county level
void TTilSpreadSheetForm::SetAdminUnitList3(void)
{
   cxComboBox10->ItemIndex = -1;
   cxComboBox10->Properties->Items->Clear();
   if (!cxComboBox9->Text.IsEmpty())
	 GeoPolUnits->GeoPol4Unit3(cxComboBox9->Text, cxComboBox10->Properties->Items);
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::SetGeoPolCaption(UnicodeString Caption, UnicodeString Unit,
	 TcxComboBox* cxComboBox, TLabel* Label)
{
   if (Unit.IsEmpty()) {
     if (Label) {
       Caption += " Geopolitical Division:";
       Label->Caption = Caption;
       }
     cxComboBox->Hint = Caption;
     }
   else {
     Unit = Capitalize(Unit);
     cxComboBox->Hint = Capitalize(Unit);
     if (Label)
       Label->Caption = Unit + ":";
     }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxComboBox7Enter(TObject *Sender)
{
   CurrentCountry = cxComboBox7->Text;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxComboBox8Enter(TObject *Sender)
{
   CurrentState = cxComboBox8->Text;
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::ParseSITFormData(void)
{
   // Site data
   SITE* site_ptr = (SITE*)Sites->Items[0];
   Edit1->Text = site_ptr->SiteName;
   if (!site_ptr->LatNorth.IsEmpty())
	 cxPopupEdit4->Text = site_ptr->LatNorth.AsType(varOleStr);
   if (!site_ptr->LatSouth.IsEmpty())
	 cxPopupEdit5->Text = site_ptr->LatSouth.AsType(varOleStr);
   if (!site_ptr->LongWest.IsEmpty())
	 cxPopupEdit6->Text = site_ptr->LongWest.AsType(varOleStr);
   if (!site_ptr->LongEast.IsEmpty())
	 cxPopupEdit7->Text = site_ptr->LongEast.AsType(varOleStr);

   cxPopupEdit5->Visible = false;
   cxPopupEdit7->Visible = false;
   Label8->Caption = "Latitude";
   Label9->Visible = false;
   Label10->Caption = "Longitude";
   Label11->Visible = false;

   if (!site_ptr->Country.IsEmpty()) {
	 cxComboBox7->ItemIndex = cxComboBox7->Properties->Items->IndexOf(site_ptr->Country);
     if (cxComboBox7->ItemIndex > -1) {
       GeoPolUnits->SetGeoPolRec1(cxComboBox7->Text);
       SetStateProvinceList();
       SetAdminUnitList1();
	   UnicodeString Unit = GeoPolUnits->GetUnit1();
	   SetGeoPolCaption("First", Unit, cxComboBox7, Label6);
	   if (!site_ptr->State.IsEmpty()) {
		 cxComboBox8->ItemIndex = cxComboBox8->Properties->Items->IndexOf(site_ptr->State);
		 if (cxComboBox8->ItemIndex > -1) {
		   GeoPolUnits->SetGeoPolRec2(cxComboBox8->Text);
		   SetCountyList();
		   SetAdminUnitList2();
		   UnicodeString Unit = GeoPolUnits->GetUnit2();
		   SetGeoPolCaption("Second", Unit, cxComboBox8, Label7);
		   if (!site_ptr->County.IsEmpty()) {
			 cxComboBox9->ItemIndex = cxComboBox9->Properties->Items->IndexOf(site_ptr->County);
			 if (cxComboBox9->ItemIndex > -1) {
			   GeoPolUnits->SetGeoPolRec3(cxComboBox9->Text);
			   SetAdminUnitList3();
			   UnicodeString Unit = GeoPolUnits->GetUnit3();
			   SetGeoPolCaption("Third", Unit, cxComboBox9, Label3);
			   }
			 }
		   }
		 }
	   }
	 }
   if (!site_ptr->Altitude.IsEmpty())
	 cxTextEdit1->Text = site_ptr->Altitude.AsType(varOleStr);
   if (!site_ptr->Area.IsEmpty())
	 cxTextEdit2->Text = site_ptr->Area.AsType(varOleStr);
   cxMemo1->Text = site_ptr->SiteDescription;
   cxMemo2->Text = site_ptr->Notes;

   // Collection data
   LabeledEdit4->Text = site_ptr->CollUnits[0].Handle;
   //ComboBox5->ItemIndex = ComboBox5->Items->IndexOf(site_ptr->CollUnits[0].CollectionType);
   cxComboBox1->ItemIndex = cxComboBox1->Properties->Items->IndexOf(site_ptr->CollUnits[0].CollectionType);
   LabeledEdit5->Text = site_ptr->CollUnits[0].CollectionName;
   dxTreeViewEdit1->Text = site_ptr->CollUnits[0].DepEnv;
   LabeledEdit10->Text = site_ptr->CollUnits[0].CollectionDevice;
   LabeledEdit6->Text = site_ptr->CollUnits[0].Location;
   if (!site_ptr->CollUnits[0].CollDate.IsEmpty())
	 cxDateEdit1->Date = site_ptr->CollUnits[0].CollDate;
   UpdateContacts(cxCheckComboBox1, site_ptr->CollUnits[0].Collectors);
   Memo4->Text = site_ptr->CollUnits[0].Notes;

   // Dataset data
   cxCheckBox1->Checked = Datasets[0].IsSSamp;
   cxCheckBox4->Checked = false;
   Memo2->Text = Datasets[0].Notes;
   UpdateContacts(cxCheckComboBox2, Datasets[0].Investigators);
   UpdateContacts(cxCheckComboBox9, Datasets[0].Processors);
}
//---------------------------------------------------------------------------

// location a point
void __fastcall TTilSpreadSheetForm::cxRadioButton1Click(TObject *Sender)
{
   if (cxRadioButton1->Checked) {
	 Label8->Caption = "Latitude";
	 Label10->Caption = "Longitude";
	 Label9->Visible = false;
	 Label11->Visible = false;
	 cxPopupEdit5->Visible = false;
	 cxPopupEdit7->Visible = false;
	 SitePtr->LatSouth = SitePtr->LatNorth;
	 SitePtr->LongEast = SitePtr->LongWest;
	 }
}
//---------------------------------------------------------------------------

// location a box
void __fastcall TTilSpreadSheetForm::cxRadioButton2Click(TObject *Sender)
{
   if (cxRadioButton2->Checked) {
     Label8->Caption = "North Bounding Latitude";
	 Label10->Caption = "West Bounding Longitude";
	 Label9->Visible = true;
	 Label11->Visible = true;
	 cxPopupEdit5->Visible = true;
	 cxPopupEdit7->Visible = true;
	 if (!SitePtr->LatSouth.IsEmpty())    // Here's the problem
	   cxPopupEdit5->Text = SitePtr->LatSouth;
	 else
	   cxPopupEdit5->Text = "";
	 if (!SitePtr->LongEast.IsEmpty())
	   cxPopupEdit7->Text = SitePtr->LongEast.AsType(varOleStr);
	 else
	   cxPopupEdit7->Text = "";
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxPopupEdit4PropertiesPopup(
      TObject *Sender)
{
   double dd;

   dms = new DMSPANEL(this, ToolButton5, ToolButton7, ToolButton8, LabeledEdit16,
         LabeledEdit13, LabeledEdit15, LabeledEdit3, LabeledEdit9, LabeledEdit12,
         ComboBox2);

   if (cxPopupEdit4->Text.IsEmpty())
     dd = NaN;
   else if (!TryStrToFloat(cxPopupEdit4->Text, dd))
     dd = NaN;

   dms->initialize(DMSStyle, dd, LATITUDE);
   LatLongPopupEdit = cxPopupEdit4;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxPopupEdit4PropertiesCloseUp(
      TObject *Sender)
{
   DMSStyle = dms->DMSStyle;
   delete dms;
   dms = NULL;
   SetLatitudeNorth();
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxPopupEdit4Exit(TObject *Sender)
{
   SetLatitudeNorth();
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::SetLatitudeNorth(void)
{
   double LatNorth;
   if (cxPopupEdit4->Text.IsEmpty()) {
	 SitePtr->LatNorth = Unassigned();
	 if (cxRadioButton1->Checked) { // Point
	   SitePtr->LatSouth = Unassigned();
       cxPopupEdit5->Text = "";
       }
	 return;
     }
   try {
       LatNorth = cxPopupEdit4->Text.ToDouble();
       double fabsLatNorth = fabs(LatNorth);
       if (fabsLatNorth < 0.0 || fabsLatNorth > 90.0) {
         MessageDlg("Degrees latitude must be >= 0 and <= 90", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
         FocusControl(cxPopupEdit4);
         }
       else {
		 SitePtr->LatNorth = LatNorth;
		 if (cxRadioButton1->Checked) { // Point
		   SitePtr->LatSouth = SitePtr->LatNorth;
		   cxPopupEdit5->Text = SitePtr->LatSouth.AsType(varOleStr);
           }
         }
       }
   catch(Exception &e) {
       MessageDlg(e.Message, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
       FocusControl(cxPopupEdit4);
       }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxPopupEdit5PropertiesPopup(
      TObject *Sender)
{
   double dd;

   dms = new DMSPANEL(this, ToolButton5, ToolButton7, ToolButton8, LabeledEdit16,
         LabeledEdit13, LabeledEdit15, LabeledEdit3, LabeledEdit9, LabeledEdit12,
         ComboBox2);

   if (cxPopupEdit5->Text.IsEmpty())
     dd = NaN;
   else if (!TryStrToFloat(cxPopupEdit5->Text, dd))
     dd = NaN;

   dms->initialize(DMSStyle, dd, LATITUDE);
   LatLongPopupEdit = cxPopupEdit5;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxPopupEdit5PropertiesCloseUp(
      TObject *Sender)
{
   DMSStyle = dms->DMSStyle;
   delete dms;
   dms = NULL;
   SetLatitudeSouth();
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxPopupEdit5Exit(TObject *Sender)
{
   SetLatitudeSouth();
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::SetLatitudeSouth(void)
{
   double LatSouth;
   if (cxPopupEdit5->Text.IsEmpty()) {
	 SitePtr->LatSouth = Unassigned();
     return;
     }
   try {
       LatSouth = cxPopupEdit5->Text.ToDouble();
       double fabsLatSouth = fabs(LatSouth);
       if (fabsLatSouth < 0.0 || fabsLatSouth > 90.0) {
		 MessageDlg("Degrees latitude must be >= 0 and <= 90", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
         FocusControl(cxPopupEdit5);
         }
       else
		 SitePtr->LatSouth = LatSouth;
       }
   catch(Exception &e) {
       MessageDlg(e.Message, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
       FocusControl(cxPopupEdit5);
       }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxPopupEdit6PropertiesPopup(
      TObject *Sender)
{
   double dd;

   dms = new DMSPANEL(this, ToolButton5, ToolButton7, ToolButton8, LabeledEdit16,
         LabeledEdit13, LabeledEdit15, LabeledEdit3, LabeledEdit9, LabeledEdit12,
         ComboBox2);

   if (cxPopupEdit6->Text.IsEmpty())
     dd = NaN;
   else if (!TryStrToFloat(cxPopupEdit6->Text, dd))
     dd = NaN;

   dms->initialize(DMSStyle, dd, LONGITUDE);
   LatLongPopupEdit = cxPopupEdit6;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxPopupEdit6PropertiesCloseUp(
      TObject *Sender)
{
   DMSStyle = dms->DMSStyle;
   delete dms;
   dms = NULL;
   SetLongitudeWest();
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxPopupEdit6Exit(TObject *Sender)
{
   SetLongitudeWest();
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::SetLongitudeWest(void)
{
   double LongWest;

   if (cxPopupEdit6->Text.IsEmpty()) {
	 SitePtr->LongWest = Unassigned();
	 if (cxRadioButton1->Checked) { // Point
	   SitePtr->LongEast = Unassigned();
       cxPopupEdit7->Text = "";
       }
     return;
     }
   try {
       LongWest = cxPopupEdit6->Text.ToDouble();
       double fabsLongWest = fabs(LongWest);
       if (fabsLongWest < 0.0 || fabsLongWest > 180.0) {
		 MessageDlg("Degrees longitude must be >= 0 and <= 180", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
         FocusControl(cxPopupEdit6);
         }
       else {
		 SitePtr->LongWest = LongWest;
		 if (cxRadioButton1->Checked) { // Point
		   SitePtr->LongEast = SitePtr->LongWest;
		   cxPopupEdit7->Text = SitePtr->LongEast.AsType(varOleStr);
           }
         }
       }
   catch(Exception &e) {
       MessageDlg(e.Message, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
       FocusControl(cxPopupEdit6);
       }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxPopupEdit7PropertiesPopup(
      TObject *Sender)
{
   double dd;

   dms = new DMSPANEL(this, ToolButton5, ToolButton7, ToolButton8, LabeledEdit16,
         LabeledEdit13, LabeledEdit15, LabeledEdit3, LabeledEdit9, LabeledEdit12,
         ComboBox2);

   if (cxPopupEdit7->Text.IsEmpty())
     dd = NaN;
   else if (!TryStrToFloat(cxPopupEdit7->Text, dd))
     dd = NaN;

   dms->initialize(DMSStyle, dd, LONGITUDE);
   LatLongPopupEdit = cxPopupEdit7;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxPopupEdit7PropertiesCloseUp(
      TObject *Sender)
{
   DMSStyle = dms->DMSStyle;
   delete dms;
   dms = NULL;
   SetLongitudeEast();
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxPopupEdit7Exit(TObject *Sender)
{
   SetLongitudeEast();
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::SetLongitudeEast(void)
{
   double LongEast;
   if (cxPopupEdit7->Text.IsEmpty()) {
	 SitePtr->LongEast = Unassigned();
     return;
     }
   try {
       LongEast = cxPopupEdit7->Text.ToDouble();
       double fabsLongEast = fabs(LongEast);
       if (fabsLongEast < 0.0 || fabsLongEast > 180.0) {
		 MessageDlg("Degrees longitude must be >= 0 and <= 180", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
         FocusControl(cxPopupEdit7);
         }
       else
		 SitePtr->LongEast = LongEast;
       }
   catch(Exception &e) {
       MessageDlg(e.Message, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
       FocusControl(cxPopupEdit7);
       }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxPopupEdit4KeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
   if (Key == VK_RETURN) {
     if (cxPopupEdit5->Visible)
       FocusControl(cxPopupEdit5);
     else
       FocusControl(cxPopupEdit6);
     }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxPopupEdit5KeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
   if (Key == VK_RETURN)
	 FocusControl(cxPopupEdit6);
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxPopupEdit6KeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
   if (Key == VK_RETURN) {
     if (cxPopupEdit7->Visible)
       FocusControl(cxPopupEdit7);
     }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::Edit1Exit(TObject *Sender)
{
   if (SitePtr)
	 SitePtr->SiteName = Edit1->Text;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::LabeledEdit2Exit(TObject *Sender)
{
   double dValue;
   if (LabeledEdit2->Text.IsEmpty())
	 CollPtr->WaterDepth = Unassigned();
   else if (TryStrToFloat(LabeledEdit2->Text, dValue))
	 CollPtr->WaterDepth = dValue;
   else {
	 MessageDlg("Water depth must be a number.", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
     FocusControl(LabeledEdit2);
     }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxTextEdit1Exit(TObject *Sender)
{
   if (cxTextEdit1->Text.IsEmpty()) {
	 SitePtr->Altitude = Unassigned();
	 return;
	 }
   double dValue;
   if (TryStrToFloat(cxTextEdit1->Text, dValue))
	 SitePtr->Altitude = dValue;
   else {
     MessageDlg("Altitude must be a number.", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
     FocusControl(cxTextEdit1);
     }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxTextEdit2Exit(TObject *Sender)
{
   if (cxTextEdit2->Text.IsEmpty()) {
	 SitePtr->Area = Unassigned();
	 return;
	 }
   double dValue;
   if (TryStrToFloat(cxTextEdit2->Text, dValue))
	 SitePtr->Area = dValue;
   else {
     MessageDlg("Area must be a number.", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
     FocusControl(cxTextEdit2);
     }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxMemo1Exit(TObject *Sender)
{
   SitePtr->SiteDescription = cxMemo1->Text;
   //UTF8String ustr = cxMemo1->Text;
   //ShowMessage("Length = " + IntToStr(ustr.Length()) + L", NumBytes = " + IntToStr(ustr.BytesOf().Length));
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxMemo2Exit(TObject *Sender)
{
   SitePtr->Notes = cxMemo2->Text;
}
//---------------------------------------------------------------------------

// ---> Collection Tab Sheet

void __fastcall TTilSpreadSheetForm::Button4Click(TObject *Sender)
{
   int ItemIndex = cxCheckComboBox1->ItemIndex;
   if (NewContact())
	 UpdateContacts(cxCheckComboBox1, CollPtr->Collectors);
   FocusControl(cxCheckComboBox1);
   cxCheckComboBox1->DroppedDown = true;
   cxCheckComboBox1->ItemIndex = ItemIndex;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxPopupEdit8PropertiesPopup(
      TObject *Sender)
{
   double dd;

   dms = new DMSPANEL(this, ToolButton5, ToolButton7, ToolButton8, LabeledEdit16,
         LabeledEdit13, LabeledEdit15, LabeledEdit3, LabeledEdit9, LabeledEdit12,
         ComboBox2);

   if (cxPopupEdit8->Text.IsEmpty())
     dd = NaN;
   else if (!TryStrToFloat(cxPopupEdit8->Text, dd))
     dd = NaN;

   dms->initialize(DMSStyle, dd, LATITUDE);
   LatLongPopupEdit = cxPopupEdit8;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxPopupEdit8PropertiesCloseUp(
      TObject *Sender)
{
   DMSStyle = dms->DMSStyle;
   delete dms;
   dms = NULL;
   SetLatitudeGPS();
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxPopupEdit8Exit(TObject *Sender)
{
   SetLatitudeGPS();
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::SetLatitudeGPS(void)
{
   double GPSLat;
   if  (cxPopupEdit8->Text.IsEmpty()) {
	 CollPtr->GPSLat = Unassigned();
     return;
	 }
   try {
       GPSLat = cxPopupEdit8->Text.ToDouble();
       double fabsGPSLat = fabs(GPSLat);
       if (fabsGPSLat < 0.0 || fabsGPSLat > 90.0) {
         MessageDlg("Degrees latitude must be >= 0 and <= 90", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
         FocusControl(cxPopupEdit8);
         }
       else
		 CollPtr->GPSLat = GPSLat;
       }
   catch(Exception &e) {
       MessageDlg(e.Message, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
       FocusControl(cxPopupEdit8);
       }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxPopupEdit9PropertiesPopup(
      TObject *Sender)
{
   double dd;

   dms = new DMSPANEL(this, ToolButton5, ToolButton7, ToolButton8, LabeledEdit16,
         LabeledEdit13, LabeledEdit15, LabeledEdit3, LabeledEdit9, LabeledEdit12,
         ComboBox2);

   if (cxPopupEdit9->Text.IsEmpty())
     dd = NaN;
   else if (!TryStrToFloat(cxPopupEdit9->Text, dd))
     dd = NaN;

   dms->initialize(DMSStyle, dd, LONGITUDE);
   LatLongPopupEdit = cxPopupEdit9;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxPopupEdit9PropertiesCloseUp(
      TObject *Sender)
{
   DMSStyle = dms->DMSStyle;
   delete dms;
   dms = NULL;
   SetLongitudeGPS();
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxPopupEdit9Exit(TObject *Sender)
{
   SetLongitudeGPS();
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::SetLongitudeGPS(void)
{
   double GPSLong;
   if  (cxPopupEdit9->Text.IsEmpty()) {
	 CollPtr->GPSLong = Unassigned();
     return;
     }
   try {
       GPSLong = cxPopupEdit9->Text.ToDouble();
       double fabsGPSLong = fabs(GPSLong);
       if (fabsGPSLong < 0.0 || fabsGPSLong > 180.0) {
         MessageDlg("Degrees longitude must be >= 0 and <= 180", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
         FocusControl(cxPopupEdit9);
         }
       else
		 CollPtr->GPSLong = GPSLong;
       }
   catch(Exception &e) {
       MessageDlg(e.Message, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
       FocusControl(cxPopupEdit9);
       }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::LabeledEdit1Exit(TObject *Sender)
{
   double dValue;

   if (LabeledEdit1->Text.IsEmpty())
	 CollPtr->GPSAltitude = Unassigned();
   else if (TryStrToFloat(LabeledEdit1->Text, dValue))
	 CollPtr->GPSAltitude = dValue;
   else {
     MessageDlg("Altitude must be a number.", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
     FocusControl(LabeledEdit1);
     }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::LabeledEdit14Exit(TObject *Sender)
{
   if (LabeledEdit14->Text.IsEmpty())
	 CollPtr->GPSError = Unassigned();
   else {
	 try {
		 CollPtr->GPSError = LabeledEdit14->Text.ToDouble();
		 if (CollPtr->GPSError < 0) {
           MessageDlg("Error must be >= 0.", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
           FocusControl(LabeledEdit14);
           }
         }
     catch(Exception &e) {
         MessageDlg(e.Message, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
         FocusControl(LabeledEdit14);
         }
     }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxPopupEdit8KeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
   if (Key == VK_RETURN)
     FocusControl(cxPopupEdit9);
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::LabeledEdit4Exit(TObject *Sender)
{
   if (CollPtr)
     CollPtr->Handle = LabeledEdit4->Text;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxComboBox1Exit(TObject *Sender)
{
   CollPtr->CollectionType = cxComboBox1->Text;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::LabeledEdit5Exit(TObject *Sender)
{
   CollPtr->CollectionName = LabeledEdit5->Text;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::LabeledEdit10Exit(TObject *Sender)
{
   CollPtr->CollectionDevice = LabeledEdit10->Text;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::LabeledEdit6Exit(TObject *Sender)
{
   CollPtr->Location = LabeledEdit6->Text;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::Memo4Exit(TObject *Sender)
{
   CollPtr->Notes = Memo4->Text;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxCheckComboBox1PropertiesInitPopup(
      TObject *Sender)
{
   UpdateContacts(cxCheckComboBox1, CollPtr->Collectors);
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxCheckComboBox1PropertiesPopup(
      TObject *Sender)
{
   Button4->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxCheckComboBox1PropertiesCloseUp(
      TObject *Sender)
{
   CollPtr->Collectors.clear();
   for (int i=0; i<cxCheckComboBox1->Properties->Items->Count; i++) {
	 if (cxCheckComboBox1->States[i] == cbsChecked) {
	   TcxCheckComboBoxItem* Item = cxCheckComboBox1->Properties->Items->Items[i];
	   CONTACT* Contact = (CONTACT*)Item->Tag;
	   CollPtr->Collectors.push_back(Contact);
       }
     }
   Button4->Visible = false;
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::UpdateContacts(TcxCheckComboBox* cxCheckComboBox, vector<CONTACT*>& Contacts)
{
   cxCheckComboBox->Properties->Items->Clear();
   for (int i=0; i<ContactList->Count; i++) {
	 CONTACT* Contact = ContactList->Contacts[i];
	 TcxCheckComboBoxItem* Item = cxCheckComboBox->Properties->Items->AddCheckItem(Contact->ShortContactName, Contact->ShortContactName);
	 Item->Tag = (Longint)Contact;
	 }

   for (int i=0; i<cxCheckComboBox->Properties->Items->Count; i++) {
	 TcxCheckComboBoxItem* Item = cxCheckComboBox->Properties->Items->Items[i];
	 CONTACT* Contact = (CONTACT*)Item->Tag;
	 if (find(Contacts.begin(), Contacts.end(), Contact) != Contacts.end())
	   cxCheckComboBox->States[i] = cbsChecked;
	 }
}
//---------------------------------------------------------------------------

bool __fastcall TTilSpreadSheetForm::FindWholeText(UnicodeString text,
     TProfGrid* ProfGrid, TRect r, TPoint* pt)
{
   UnicodeString cell_text;
   for (int i=r.Left; i<=r.Right; i++) {
	 for (int j=r.Top; j<=r.Bottom; j++) {
	   cell_text = ProfGrid->Cells[i][j]->Text;
	   if (SameText(text, cell_text)) {
         pt->x = i;
         pt->y = j;
         return true;
         }
       }
     }
   return false;
}
//---------------------------------------------------------------------------

int __fastcall TTilSpreadSheetForm::FindPartialText(UnicodeString text,
      TProfGrid* ProfGrid, TRect r, TPoint* pt)
{
   UnicodeString cell_text;
   int index;
   text = text.LowerCase();
   for (int i=r.Left; i<=r.Right; i++) {
     for (int j=r.Top; j<=r.Bottom; j++) {
       cell_text = ProfGrid->Cells[i][j]->Text;
       cell_text = cell_text.LowerCase();
       index = cell_text.Pos(text);
       if (index) {
         pt->x = i;
         pt->y = j;
         return index;
         }
       }
     }
   return 0;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::ContactsGridCardView1NavigatorButtonsButtonClick(
      TObject *Sender, int AButtonIndex, bool &ADone)
{
   if (AButtonIndex == 8) {  // delete button
	 CONTACT *Contact = ContactList->Contacts[ContactsGridCardView1->Controller->FocusedRecord->RecordIndex];

	 list<CELLOBJECT*>::iterator itr;
	 for (itr=CellObjects.begin(); itr != CellObjects.end(); itr++ ) {
	   if ((*itr)->ObjectType == CELLCONTACTS) {
		 TList* CellContacts = (TList*)(*itr)->Object;
		 for (int i=0; i<CellContacts->Count; i++) {
		   if (Contact == CellContacts->Items[i]) {
			 MessageDlg("Contact is linked to sample analyst. Cannot delete linked contact.",
			   Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			 ADone = true;
			 return;
			 }
		   }
		 }
	   }

	 for (int k=0; k<Sites->Count; k++) {
	   SITE* site_ptr = (SITE*)Sites->Items[0];
	   for (unsigned int j = 0; j < site_ptr->CollUnits.size(); j++) {
		 for (unsigned int i=0; i<site_ptr->CollUnits[j].Collectors.size(); i++) {
		   if (site_ptr->CollUnits[j].Collectors[i] == Contact) {
			 MessageDlg("Contact is a collector. Cannot delete linked contact.",
			   Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			 ADone = true;
			 return;
			 }
		   }
		 }
	   }

	 for (unsigned int i=0; i<Datasets.size(); i++) {
	   for (unsigned int j=0; j<Datasets[i].Investigators.size(); j++) {
		 if (Datasets[i].Investigators[j] == Contact) {
		   MessageDlg("Contact is an investigator. Cannot delete linked contact.",
			 Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   ADone = true;
		   return;
		   }
		 }
	   }

	 for (unsigned int i=0; i<Datasets.size(); i++) {
	   for (unsigned int j=0; j<Datasets[i].Processors.size(); j++) {
		 if (Datasets[i].Processors[j] == Contact) {
		   MessageDlg("Contact is an data processor. Cannot delete linked contact.",
			 Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   ADone = true;
		   return;
		   }
		 }
	   }

	 for (unsigned int i=0; i<Datasets.size(); i++) {
	   for (unsigned int j=0; j<Datasets[i].Submissions.size(); j++) {
		 for (unsigned int k=0; k<Datasets[i].Submissions[j].Submitters.size(); k++) {
		   if (Datasets[i].Submissions[j].Submitters[k] == Contact) {
			 MessageDlg("Contact is a submitter. Cannot delete linked contact.",
			   Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			 ADone = true;
			 return;
			 }
		   }
		 }
	   }

	 for (int i=0; i<AgeModelList->Count; i++) {
	   AGEMODEL* AgeModel = AgeModelList->AgeModels[i];
	   for (unsigned int j=0; j<AgeModel->Preparers.size(); j++) {
		 if (AgeModel->Preparers[j] ==  Contact) {
		   MessageDlg("Contact is an age model preparer. Cannot delete linked contact.",
			 Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   ADone = true;
		   return;
		   }
		 }
	   }

	 for (unsigned int i=0; i<loi.Investigators.size(); i++) {
	   if (loi.Investigators[i] == Contact) {
		 MessageDlg("Contact is an LOI investigator. Cannot delete linked contact.",
		   Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 ADone = true;
		 return;
		 }
	   }

	 for (int i=0; i<Publications->Count; i++) {
	   PUBLICATION *pub = (PUBLICATION*)Publications->Items[i];
	   for (unsigned int j=0; j<pub->AuthorList.size(); j++) {
		 if (pub->AuthorList[j].contact == Contact) {
		   MessageDlg("Contact is linked to publication. Cannot delete linked contact.",
			 Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   ADone = true;
		   return;
		   }
         }
	   }
	 }
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::SpecialFormating(void)
{
   int row, StartCol, EndCol;
   TProfGridCell *ACell;
   TProfGridRow* ARow;

   if ((row = FindRowCodeIC("#ANAL.MIXED", ProfGrid1)) > 0) {
	 ARow = ProfGrid1->AbsoluteRows[row];
	 StartCol = AbsHeaderColCount(ProfGrid1);
	 EndCol = ProfGrid1->AbsoluteColCount;
	 for (int col=StartCol; col<EndCol; col++) {
	   ACell = ARow->AbsoluteCells[col];
	   if (!ACell->CheckBox)
		 ACell->CheckBox = true;
	   }
	 }

   if ((row = FindRowCodeIC("#DATA.TYPE", ProfGrid1)) > 0) {
	 int StartRow = 3;
	 while ((row = FindRowCodeIC("#Data.Type", ProfGrid1, StartRow)) > 0) {
	   ARow = ProfGrid1->AbsoluteRows[row];
	   EndCol = ProfGrid1->AbsoluteColCount;
	   for (int col=1; col<EndCol; col++) {
		 ACell = ARow->AbsoluteCells[col];
		 ACell->Color = (TColor)0x00EACAB6;
		 ACell->Font->Color = clNavy;
		 }
	   StartRow = row+1;
	   }
	 }

   if ((row = FindRowCodeIC("#Anal.Bottom", ProfGrid1)) > 0) {
	 ARow = ProfGrid1->AbsoluteRows[row];
	 EndCol = ProfGrid1->AbsoluteColCount;
	 for (int col=1; col<EndCol; col++) {
	   ACell = ARow->AbsoluteCells[col];
	   ACell->Color = (TColor)0x00EACAB6;
	   ACell->Font->Color = clNavy;
	   }
	 }
}
//---------------------------------------------------------------------------

// this called after opening a .tlx file
void TTilSpreadSheetForm::FillMetaData(void)
{
   int StartCol = AbsHeaderColCount(ProfGrid1);
   int EndCol = AbsContentColCount(ProfGrid1);
   for (int col=StartCol; col<=EndCol; col++) {
	 if (!ProfGrid1->AbsoluteCells[col][2]->Value.IsEmpty()) {
	   HeaderNameEntered = true;
	   break;
	   }
	 }

   // Site metadata
   GetSSSiteMetaData();
   if (Sites->Count == 1) {
	 SitePtr = (SITE*)Sites->Items[0];
	 FillSiteMetaData(SitePtr);
	 }

   // Publications
   if (Publications->Count > 0) {
	 AdvColumnGrid4->RowCount = Math::Max(2,Publications->Count+1);
	 AdvColumnGrid4->ClearNormalCells();
	 for (int j=0, row=1; j<Publications->Count; j++, row++) {
	   PUBLICATION* pub = (PUBLICATION*)Publications->Items[j];
	   AdvColumnGrid4->Cells[1][row] = pub->Citation;
	   AdvColumnGrid4->Objects[1][row] = (TObject*)pub;
	   }
	 }

   // Collection metadata
   if (Sites->Count == 1) {
	 CollPtr = &SitePtr->CollUnits[0];
	 FillCollUnitMetaData();
	 }
   else {
	 //TODO: take care of multisite datasets
	 }

   // Dataset metadata
   FillDatasetMetaData(DatasetNum);

   // Geochronology metadata
   UpdateContacts(cxCheckComboBox10, GeochronDataset.Investigators);
   if (GeochronList->Count() > 0) {
     cxGrid2TableView1->DataController->ClearSorting(false);  // force sorting
     geDepth->SortOrder = soAscending;
     }

   // Lithology metadata
   if (LithologyUnitList->Count) {
     cxGrid1TableView1->DataController->ClearSorting(false);  // force sorting
     liTop->SortOrder = soAscending;
     }

   UpdateContacts(cxCheckComboBox3, loi.Investigators);
   UpdatePublications(cxCheckComboBox7, loi.Publications);
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::FillSiteMetaData(SITE* site_ptr)
{
   if (Downloaded) {
	 AdvPanel7->Visible = true;
	 Label4->Caption = L"Neotoma SiteID: " + IntToStr(site_ptr->NeotomaSiteID);
	 }

   Edit1->Text = site_ptr->SiteName;

   if (site_ptr->Country.IsEmpty())
     cxComboBox7->ItemIndex = -1;
   else
	 cxComboBox7->ItemIndex = cxComboBox7->Properties->Items->IndexOf(site_ptr->Country);
   if (cxComboBox7->ItemIndex < 0) {
	 site_ptr->Country = "";
	 site_ptr->State = "";
	 site_ptr->County = "";
	 cxComboBox8->ItemIndex = -1;
	 cxComboBox9->ItemIndex = -1;
	 }
   else {
     GeoPolUnits->SetGeoPolRec1(cxComboBox7->Text);
     SetStateProvinceList();
	 if (site_ptr->State.IsEmpty())
       cxComboBox8->ItemIndex = -1;
     else
       cxComboBox8->ItemIndex = cxComboBox8->Properties->Items->IndexOf(site_ptr->State);
     SetAdminUnitList1();
	 UnicodeString Unit = GeoPolUnits->GetUnit1();
	 SetGeoPolCaption("First", Unit, cxComboBox7, Label6);
	 if (cxComboBox8->ItemIndex < 0) {
	   site_ptr->State = "";
	   site_ptr->County = "";
	   cxComboBox8->ItemIndex = -1;
	   cxComboBox9->ItemIndex = -1;
	   }
	 else {
	   GeoPolUnits->SetGeoPolRec2(cxComboBox8->Text);
	   SetCountyList();
	   SetAdminUnitList2();
	   UnicodeString Unit = GeoPolUnits->GetUnit2();
	   SetGeoPolCaption("Second", Unit, cxComboBox8, Label7);

	   cxComboBox9->ItemIndex = cxComboBox9->Properties->Items->IndexOf(site_ptr->County);
	   if (cxComboBox9->ItemIndex < 0)
		 site_ptr->County = "";
	   GeoPolUnits->SetGeoPolRec3(cxComboBox9->Text);
	   SetAdminUnitList3();
	   Unit = GeoPolUnits->GetUnit3();
	   SetGeoPolCaption("Third", Unit, cxComboBox9, Label3);
	   }
	 cxComboBox10->Text = site_ptr->AdminUnit;
	 GeoPolUnits->SetGeoPolRec4(cxComboBox10->Text);
	 Unit = GeoPolUnits->GetUnit4();
	 SetGeoPolCaption("Administrative unit", Unit, cxComboBox10, NULL);
     }

   if (site_ptr->Altitude.IsEmpty())
	 cxTextEdit1->Text = "";
   else
	 cxTextEdit1->Text = site_ptr->Altitude.AsType(varOleStr);

   if (site_ptr->Area.IsEmpty())
	 cxTextEdit2->Text = "";
   else
	 cxTextEdit2->Text = site_ptr->Area.AsType(varOleStr);

   cxMemo1->Text = site_ptr->SiteDescription;
   cxMemo2->Text = site_ptr->Notes;

   if (site_ptr->LatNorth.IsEmpty())
     cxPopupEdit4->Text = "";
   else
	 cxPopupEdit4->Text = site_ptr->LatNorth.AsType(varOleStr);

   if (site_ptr->LatSouth.IsEmpty())
	 cxPopupEdit5->Text = "";
   else {
	 Label9->Visible = true;
	 Label8->Caption = "North Bounding Latitude:";
	 cxPopupEdit5->Visible = true;
	 cxPopupEdit5->Text = site_ptr->LatSouth.AsType(varOleStr);
	 }

   if (site_ptr->LongWest.IsEmpty())
	 cxPopupEdit6->Text = "";
   else
	 cxPopupEdit6->Text = site_ptr->LongWest.AsType(varOleStr);

   if (site_ptr->LongEast.IsEmpty())
	 cxPopupEdit7->Text = "";
   else {
	 Label10->Caption = "West Bounding Longitude:";
	 Label11->Visible = true;
	 cxPopupEdit7->Visible = true;
	 cxPopupEdit7->Text = site_ptr->LongEast.AsType(varOleStr);
	 }

   if (site_ptr->LatNorth.IsEmpty() || site_ptr->LatNorth == site_ptr->LatSouth) {
	 Label8->Caption = "Latitude:";
	 Label9->Visible = false;
	 cxPopupEdit5->Visible = false;
	 }

   if (site_ptr->LongWest.IsEmpty() || site_ptr->LongWest == site_ptr->LongEast) {
	 Label10->Caption = "Longitude:";
	 Label11->Visible = false;
	 cxPopupEdit7->Visible = false;
	 }

   if (site_ptr->LatNorth.IsEmpty() || site_ptr->LongWest.IsEmpty())
	 cxRadioButton1->Checked = true;
   else if (site_ptr->LatNorth == site_ptr->LatSouth && site_ptr->LongWest == site_ptr->LongEast)
	 cxRadioButton1->Checked = true;
   else {
	 // this is the problem
	 cxRadioButton2->Checked = true;
	 }

   UnicodeString lpText;
   int rows = AdvStringGridLake->RowCount;
   for (int k=1; k<rows; k++)    // blank all values before filling
	 AdvStringGridLake->Cells[1][k] = L"";
   AdvControlDropDown2->Text = lpText;
   if (site_ptr->LakeParams.size() > 0) {
	 vector<LAKEPARAM>::iterator itr = site_ptr->LakeParams.begin();
	 list<LAKEPARAMETER>::iterator lpitr;
	 while (itr != site_ptr->LakeParams.end()) {
	   for (int k=1; k<rows; k++) {
		 if (SameText(AdvStringGridLake->Cells[0][k], itr->Name)) {
		   AdvStringGridLake->Cells[1][k] = FloatToStr(itr->Value);
		   for (lpitr = LakeChar.begin(); lpitr != LakeChar.end(); lpitr++) {
			 if (SameText(itr->Name, lpitr->Name)) {
			   if (!lpText.IsEmpty())
				 lpText += L",";
			   lpText += ("\"" + lpitr->Code + L"\":" + FloatToStr(itr->Value));
			   break;
			   }
			 }
		   break;
		   }
		 }
	   itr++;
	   }
	 AdvControlDropDown2->Text = lpText;
     }
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::FillCollUnitMetaData(void)
{
   if (Downloaded) {
	 AdvPanel8->Visible = true;
	 Label15->Caption = L"Neotoma CollectionUnitID: " + IntToStr(CollPtr->NeotomaCollUnitID);
	 }
   LabeledEdit4->Text = CollPtr->Handle;
   cxComboBox1->ItemIndex = cxComboBox1->Properties->Items->IndexOf(CollPtr->CollectionType);
   LabeledEdit5->Text = CollPtr->CollectionName;
   dxTreeViewEdit1->Text = CollPtr->DepEnv;
   dxTreeViewEdit2->Text = CollPtr->Substrate;
   LabeledEdit10->Text = CollPtr->CollectionDevice;
   LabeledEdit6->Text = CollPtr->Location;
   UpdateContacts(cxCheckComboBox1, CollPtr->Collectors);
   Memo4->Text = CollPtr->Notes;
   if (!CollPtr->CollDate.IsEmpty())
	 cxDateEdit1->Date = CollPtr->CollDate;
   else
	 cxDateEdit1->Text = "";
   LabeledEdit2->Text = CollPtr->WaterDepth.AsType(varOleStr);
   cxPopupEdit13->Text = CollPtr->SlopeAngle.AsType(varOleStr);
   cxPopupEdit14->Text = CollPtr->SlopeAspect.AsType(varOleStr);
   cxPopupEdit8->Text = CollPtr->GPSLat.AsType(varOleStr);
   cxPopupEdit9->Text = CollPtr->GPSLong.AsType(varOleStr);
   LabeledEdit14->Text = CollPtr->GPSError.AsType(varOleStr);
   LabeledEdit1->Text = CollPtr->GPSAltitude.AsType(varOleStr);
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::CheckVariables(void)
{
   TCheckVarForm* CheckVarForm = new TCheckVarForm(this);
   if (CheckVarForm->ShowModal() == mrOk) {
	 tiGlobals->ReplaceVarCodes = CheckVarForm->SubVarCodes;
	 tiGlobals->ReplaceElements = CheckVarForm->SubElements;
	 tiGlobals->ReplaceUnits = CheckVarForm->SubUnits;
	 tiGlobals->ReplaceGroups = CheckVarForm->SubGroups;
	 }
   delete CheckVarForm;
   TilSpreadSheetForm->Repaint();
}
//---------------------------------------------------------------------------

TErrorListForm* TTilSpreadSheetForm::GetErrorListForm(UnicodeString FormCaption,
   UnicodeString Button1Caption, TModalResult Button1ModalResult, UnicodeString Button2Caption,
   TModalResult Button2ModalResult, int ButtonWidth, TStringList* ErrorList)
{
   ErrorListForm = new TErrorListForm(this);
   ErrorListForm->Memo1->Lines->Assign(ErrorList);
   ErrorListForm->Caption = FormCaption;
   if (!Button1Caption.IsEmpty()) {
     ErrorListForm->Button1->Visible = true;
     ErrorListForm->Button1->Caption = Button1Caption;
     ErrorListForm->Button1->ModalResult = Button1ModalResult;
     ErrorListForm->Button1->Width = ButtonWidth;
     }
   if (!Button2Caption.IsEmpty()) {
	 ErrorListForm->Button2->Visible = true;
     ErrorListForm->Button2->Caption = Button2Caption;
     ErrorListForm->Button2->ModalResult = Button2ModalResult;
     ErrorListForm->Button2->Width = ButtonWidth;
     }
   if (ErrorListForm->Button1->Visible && !ErrorListForm->Button2->Visible)
     ErrorListForm->Button1->Left = (ErrorListForm->Width - ErrorListForm->Button1->Width)/2;
   else if (ErrorListForm->Button1->Visible && ErrorListForm->Button2->Visible) {
     ErrorListForm->Button1->Left = ErrorListForm->Width/2 - 8 - ErrorListForm->Button1->Width;
     ErrorListForm->Button2->Left = ErrorListForm->Width/2 + 8;
     }

   return ErrorListForm;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::MarkRareTypes(TProfGrid* ProfGrid)
{
   if (ProfGrid->Selection->Rect.Left < ProfGrid->FixedCols ||
       ProfGrid->Selection->Rect.Top < ProfGrid->FixedRows) {
         MessageDlg("Header columns or rows selected.", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 return;
         }

   TColor Color = tiGlobals->RareColor;
   if (ProfGrid->Selection->Cells[0]->Font->Color == Color)
     Color = clWindowText;

   for (int i=0; i<ProfGrid->Selection->Count; i++) {
     Variant Value = ProfGrid->Selection->Cells[i]->Value;
     if (Value.Type() == varDouble && Value > 0.0)
       ProfGrid->Selection->Cells[i]->Font->Color = Color;
     }
   ProfGrid->SelectionFontColor = Color;
   SpreadSheetChanged = true;
}

//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxDateEdit1Exit(TObject *Sender)
{
   if (cxDateEdit1->Text.IsEmpty())
	 CollPtr->CollDate = Unassigned();
   else
	 CollPtr->CollDate = cxDateEdit1->Date;
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::SetDatasetNum(void)
{
   DatasetNum = 0;
   if (Datasets.size() > 1) {  // if more than one DatasetType
	 for (int row=ProfGrid1->Row; row>=3; row--) {
	   UnicodeString Code = ProfGrid1->AbsoluteCells[1][row]->Text;
	   if (SameText(Code, L"#Data.Type")) {
		 UnicodeString DatasetType = ProfGrid1->AbsoluteCells[2][row]->Text;
		 if (DatasetType.IsEmpty()) continue;
		 bool found = false;
		 for (unsigned int i=1; i<Datasets.size(); i++) {
		   if (SameText(DatasetType, Datasets[i].DatasetType)) {
			 DatasetNum = i;
			 found = true;
			 break;
			 }
		   }
		 if (found) break;
		 }
	   }
	 }
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::GetAdvGridFormLoc(TAdvStringGrid* Grid, int Height, int Width, TPoint& FormPos)
{
   TPoint pnt = Grid->ClientToScreen(TPoint(0,0));

   TPoint origin = ClientToScreen(TPoint(0,0));

   TRect CellRect = Grid->CellRect(Grid->Col, Grid->Row);

   //int x = Grid->GetX(Grid->Col);
   int x = CellRect.Left;
   if (x + Width > Grid->Width)
	 FormPos.X = pnt.x + x - Width + Grid->ColWidths[Grid->Col];
   else
	 FormPos.X = pnt.x + x;
   if (FormPos.X < origin.X)
	 FormPos.X = origin.X;

   //int y = Grid->GetY(Grid->Row);
   int y = CellRect.Top;
   if (y + Height > Grid->Height)
	 FormPos.Y = pnt.y + y - Height;
   else
	 FormPos.Y = pnt.y + y + Grid->RowHeights[Grid->Row];
   if (FormPos.Y < origin.Y)
	 FormPos.Y = origin.Y;
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::GetProfGridFormLoc(TProfGrid* Grid, int Height, int Width, TPoint& FormPos)
{
   TPoint pnt = Grid->ClientToScreen(TPoint(0,0));

   TPoint origin = ClientToScreen(TPoint(0,0));

   int x = Grid->GetX(Grid->Col);
   if (x + Width > Grid->Width)
	 FormPos.X = pnt.x + x - Width + Grid->ColWidths[Grid->Col];
   else
	 FormPos.X = pnt.x + x;
   if (FormPos.X < origin.X)
	 FormPos.X = origin.X;

   int y = Grid->GetY(Grid->Row);
   if (y + Height > Grid->Height)
	 FormPos.Y = pnt.y + y - Height;
   else
	 FormPos.Y = pnt.y + y + Grid->Rows[Grid->Row]->Height;
   if (FormPos.Y < origin.Y)
	 FormPos.Y = origin.Y;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::Specimens1Click(TObject *Sender)
{
   TProfGridCell* ACell = ProfGrid1->Cells[ProfGrid1->Col][ProfGrid1->Row];

   if (VarLookup == NULL || !VarLookup->ElementOpen()) {
	 MessageDlg(L"Taxa lookup file not open!", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 return;
	 }

   TPoint SpecFormPos;

   GetProfGridFormLoc(ProfGrid1, 255, 698, SpecFormPos);

   CELLOBJECT* CellObject = NULL;

   if (ACell->CellObject != NULL)
	 CellObject = (CELLOBJECT*)ACell->CellObject;

   try {
	   SpecimenForm = new TSpecimenForm(SpecFormPos, CellObject, this);
	   }
   catch(Exception &e) {
	   MessageDlg(e.Message, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   }

   try {
	   SpecimenForm->ShowModal();
	   }
   catch(Exception &e) {
	   MessageDlg(e.Message, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   }

   delete SpecimenForm;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::Specimens2Click(TObject *Sender)
{
   if (!VarLookup->ElementOpen()) {
	 MessageDlg(L"Taxa lookup file not open!", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 return;
	 }

   TPoint origin = ClientToScreen(TPoint(0,0));

   try {
	   AllSpecimensForm = new TAllSpecimensForm(TPoint(origin.X+16,origin.Y+16), this);
	   }
   catch(Exception &e) {
	   MessageDlg(e.Message, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   }

   try {
	   AllSpecimensForm->ShowModal();
	   }
   catch(Exception &e) {
	   MessageDlg(e.Message, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   }

   delete AllSpecimensForm;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::chAnalUnitIDPropertiesPopup(TObject *Sender)
{
   cxButton40->ModalResult = mrNone;
   int RecordIndex1 = cxGrid3TableView1->Controller->FocusedRecordIndex;
   int RecordIndex2 = CurrentChronControlView->DataController->FocusedRecordIndex;
   AGEMODEL* AgeModel = AgeModelList->AgeModels[RecordIndex1];
   if (RecordIndex2 >= 0) {
	 CHRON* ChronControl = (CHRON*)AgeModel->ChronControls->Items[RecordIndex2];
	 AdvColumnGrid7->Row = 0;
	 for (int row=1; row<=AdvColumnGrid7->RowCount-1; row++) {
	   if (!AdvColumnGrid7->Cells[0][row].IsEmpty()) {
		 int AnalUnitID = AdvColumnGrid7->Cells[0][row].ToInt();
		 if (AnalUnitID == ChronControl->NeotomaAnalUnitID) {
		   AdvColumnGrid7->Row = row;
		   break;
		   }
		 }
	   }
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::chAnalUnitIDPropertiesCloseUp(TObject *Sender)
{
   if (cxButton40->ModalResult == mrOk && AdvColumnGrid7->Row > 0) {
	 ((TcxPopupEdit*)Sender)->Text = AdvColumnGrid7->Cells[0][AdvColumnGrid7->Row];
	 int RecordIndex1 = cxGrid3TableView1->Controller->FocusedRecordIndex;
	 int RecordIndex2 = CurrentChronControlView->DataController->FocusedRecordIndex;
	 AGEMODEL* AgeModel = AgeModelList->AgeModels[RecordIndex1];
	 if (RecordIndex2 >= 0) {
	   CHRON* ChronControl = (CHRON*)AgeModel->ChronControls->Items[RecordIndex2];
	   int NewAnalUnitID = AdvColumnGrid7->Cells[0][AdvColumnGrid7->Row].ToInt();
	   if (NewAnalUnitID != ChronControl->NeotomaAnalUnitID) {
		 ChronControl->NeotomaAnalUnitID = NewAnalUnitID;
		 ChronControl->AnalUnit = AdvColumnGrid7->Cells[1][AdvColumnGrid7->Row];
		 UnicodeString msg = L"Update Analysis Unit in Neotoma?";
		 if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes) {
		   if (UpdateNeotomaChronControlAnalUnit(ChronControl)) {
			 msg = L"AnalysisUnitID for ChronControlID " + IntToStr(ChronControl->NeotomaChronControlID) +
				   L" updated to " + IntToStr(ChronControl->NeotomaAnalUnitID) + L".";
			 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
			 }
		   }
		 }
	   }
	 }
}
//---------------------------------------------------------------------------

// Ok
void __fastcall TTilSpreadSheetForm::cxButton40Click(TObject *Sender)
{
   cxButton40->ModalResult = mrOk;
   ((TcxPopupEdit*)(CurrentChronControlView->Controller->EditingController->Edit))->DroppedDown = false;
}
//---------------------------------------------------------------------------

// Cancel
void __fastcall TTilSpreadSheetForm::cxButton41Click(TObject *Sender)
{
   ((TcxPopupEdit*)(CurrentChronControlView->Controller->EditingController->Edit))->DroppedDown = false;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::AdvColumnGrid7DblClick(TObject *Sender)
{
   cxButton40->ModalResult = mrOk;
   ((TcxPopupEdit*)(CurrentChronControlView->Controller->EditingController->Edit))->DroppedDown = false;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::geAnalUnitIDPropertiesPopup(TObject *Sender)
{
   cxButton42->ModalResult = mrNone;
   int RecordIndex1 = cxGrid2TableView1->DataController->FocusedRecordIndex;
   if (RecordIndex1 >= 0) {
	 GEOCHRON* Date = &GeochronList->Dates[RecordIndex1];
	 AdvColumnGrid8->Row = 0;
	 for (int row=1; row<=AdvColumnGrid8->RowCount-1; row++) {
	   if (!AdvColumnGrid8->Cells[0][row].IsEmpty()) {
		 int AnalUnitID = AdvColumnGrid8->Cells[0][row].ToInt();
		 if (AnalUnitID == Date->NeotomaAnalUnitID) {
		   AdvColumnGrid8->Row = row;
		   break;
		   }
		 }
	   }
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::geAnalUnitIDPropertiesCloseUp(TObject *Sender)
{
   if (cxButton42->ModalResult == mrOk && AdvColumnGrid8->Row > 0) {
	 ((TcxPopupEdit*)Sender)->Text = AdvColumnGrid8->Cells[0][AdvColumnGrid8->Row];
	 int RecordIndex1 = cxGrid2TableView1->DataController->FocusedRecordIndex;
	 if (RecordIndex1 >= 0) {
	   GEOCHRON* Date = &GeochronList->Dates[RecordIndex1];
	   int NewAnalUnitID = AdvColumnGrid8->Cells[0][AdvColumnGrid8->Row].ToInt();
	   if (NewAnalUnitID != Date->NeotomaAnalUnitID) {
		 Date->NeotomaAnalUnitID = NewAnalUnitID;
		 Date->AnalUnit = AdvColumnGrid8->Cells[1][AdvColumnGrid8->Row];
		 UnicodeString msg = L"Update Analysis Unit in Neotoma?";
		 if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes) {
		   if (UpdateNeotomaGeochronAnalUnit(Date)) {
			 msg = L"AnalysisUnitID for GeochronID " + IntToStr(Date->NeotomaGeochronID) +
				   L" updated to " + IntToStr(Date->NeotomaAnalUnitID) + L".";
			 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
			 }
		   }
		 }
	   }
	 }
}
//---------------------------------------------------------------------------

// Ok
void __fastcall TTilSpreadSheetForm::cxButton42Click(TObject *Sender)
{
   cxButton42->ModalResult = mrOk;
   ((TcxPopupEdit*)(cxGrid2TableView1->Controller->EditingController->Edit))->DroppedDown = false;
}
//---------------------------------------------------------------------------

// Cancel
void __fastcall TTilSpreadSheetForm::cxButton43Click(TObject *Sender)
{
   ((TcxPopupEdit*)(cxGrid2TableView1->Controller->EditingController->Edit))->DroppedDown = false;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::AdvColumnGrid8DblClick(TObject *Sender)
{
   cxButton42->ModalResult = mrOk;
   ((TcxPopupEdit*)(cxGrid2TableView1->Controller->EditingController->Edit))->DroppedDown = false;
}
//---------------------------------------------------------------------------



