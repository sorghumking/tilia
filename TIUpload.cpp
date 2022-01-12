//---------------------------------------------------------------------------

#include <vcl.h>
#include "pch.h"
#pragma hdrstop
#include <HTTPApp.hpp>
#include <VarHlpr.hpp>

#include "TIUpload.h"
#ifndef TIGlobalsH
#include "TIGlobals.h"
#endif
#ifndef TINeotomaH
#include "TINeotoma.h"
#endif
#ifndef TIChkVarFrmH
#include "TIChkVarFrm.h"
#endif
#ifndef TINoUnitsH
#include "TINoUnits.h"
#endif
#ifndef TNUtilsH
#include "TNUtils.h"
#endif
#ifndef TNNewElmH
#include "TNNewElm.h"
#endif
#ifndef TNConfElmH
#include "TNConfElm.h"
#endif
#ifndef TNDatTypH
#include "TNDatTyp.h"
#endif
#ifndef TIEdtModH
#include "TIEdtMod.h"
#endif
#ifndef TICalibH
#include "TICalib.h"
#endif
#ifndef TNUpdSitH
#include "TNUpdSit.h"
#endif
#ifndef TICommonH
#include "TICommon.h"
#endif

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "ipwcore"
#pragma link "ipworks"
#pragma link "cxButtons"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "ipwjson"
#pragma link "ipwhttp"
#pragma link "ProfGrid"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxMemo"
#pragma link "cxTextEdit"
#pragma link "cxGroupBox"
#pragma link "cxProgressBar"
#pragma link "ipshttps"
#pragma link "ipsjsons"
#pragma link "cxCheckListBox"
#pragma link "cxCheckBox"
#pragma link "dxGDIPlusClasses"
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
TNeotomaUploadForm *NeotomaUploadForm;
TNeotomaTaxaValidationForm *NeotomaTaxaValidationForm;
TNeotomaUploadChronForm *NeotomaUploadChronForm;
//---------------------------------------------------------------------------

bool TAXAGROUPDATASETTYPE::operator == (const TAXAGROUPDATASETTYPE& compare )
{
   if (this == &compare) return true;
   if (!SameText(TaxaGroupID, compare.TaxaGroupID)) return false;
   if (DatasetTypeID != compare.DatasetTypeID) return false;
   return true;
}
//---------------------------------------------------------------------------

bool NEOTOMATAPHSYSTEM::operator == (const NEOTOMATAPHSYSTEM& compare )
{
   if (this == &compare) return true;
   if (!SameText(DatasetType, compare.DatasetType)) return false;
   if (!SameText(SystemName, compare.SystemName)) return false;
   return true;
}
//---------------------------------------------------------------------------

void NEOTOMATAPHSYSTEM::AddTypes(set<UnicodeString>& types)
{
   for (set<UnicodeString>::iterator itr = types.begin(); itr != types.end(); itr++) {
	 if (Types.count(*itr) == 0)
	   Types.insert(*itr);
	 }
}
//---------------------------------------------------------------------------

NEOTOMATAXONDATE::NEOTOMATAXONDATE(int gcid, TAXONDATED td, vector<PUBLICATION*>& pubs, UnicodeString dd)
{
   GeochronID = gcid;
   if (td.Specimen != NULL)
	 SpecimenID = td.Specimen->SpecimenID;
   else
     SpecimenID = -1;
   Taxon = td.Taxon;
   ElementType = td.Element;
   Fraction = td.Fraction;
   Notes = td.Notes;
   Publications = pubs;
   DateDescript = dd;
   SampleID = -1;
   NeotomaSpecimenID = -1;
   NeotomaTaxonID = -1;
   NeotomaElementTypeID = -1;
   NeotomaFractionID = -1;
   Cal.Age = Unassigned();
   Cal.AgeOlder = Unassigned();
   Cal.AgeYounger = Unassigned();
   Cal.Date = Unassigned();
   Cal.CurveID = -1;
   Cal.ProgramID = -1;
}
//---------------------------------------------------------------------------

NEOTOMAAGEMODEL::NEOTOMAAGEMODEL(int chron_number, AGEMODEL* age_model, TList* chron_controls)
{
  ChronNumber = chron_number;
  NeotomaChronologyID = age_model->NeotomaChronologyID;
  ChronologyName = age_model->ChronologyName;
  AgeUnits = age_model->AgeUnits;
  Default = age_model->Default;
  DatePrepared = age_model->DatePrepared;
  AgeModel = age_model->AgeModel;
  AgeBoundOlder = age_model->AgeBoundOlder;
  AgeBoundYounger = age_model->AgeBoundYounger;
  Notes = age_model->Notes;
  Preparers = age_model->Preparers;
  PreparersComboBoxText = age_model->PreparersComboBoxText;
  if (chron_controls != NULL) {
	for (int i=0; i<chron_controls->Count; i++)
	  ChronControls.push_back(CHRON((CHRON*)chron_controls->Items[i]));
	  //ChronControls->Add(new CHRON((CHRON*)chron_controls->Items[i]));
	}
}
//---------------------------------------------------------------------------

bool ISOVARID::IsEmpty()
{
   if (d13C != -1)
	 return false;
   else if (d15N != -1)
	 return false;
   else if (d18O != -1)
	 return false;
   else if (dD != -1)
	 return false;
   else if (d34S != -1)
	 return false;
   else if (Sr87Sr86 != -1)
	 return false;
   else if (TotalSr != -1)
	 return false;
   else if (CN != -1)
	 return false;
   else if (OH != -1)
	 return false;
   else
     return true;
}
//---------------------------------------------------------------------------

__fastcall TNeotomaUploadForm::TNeotomaUploadForm(TComponent* Owner)
	: TForm(Owner)
{
   TSSForm = (TTilSpreadSheetForm*)Owner;
   Activated = false;
   RatStart = 16;
   RatEnd = 592;
   RatPos = 16;
   VarErrors = false;

   TempSiteID = -1000;
   TempCollUnitID = -1000;
   TempAnalUnitID = -1000;
   TempSampleID = -1000;
   TempDatasetID = -1000;
   TempGeochronID = -1000;
   TempChronID = -1000;
   TempChronControlID = -1000;

   SpecimenDateChronNo = -1;
   SpecimenDateDatasetID = -1;
   DataUploaded = false;
   Aggregates = false;
   ElementErrors = false;
   MultiSiteUpload = false;
   GeochronOnly = false;
   ReplaceEPDDataset = false;

   WhitmoreAccess = NULL;
   AddDataToExistingCollUnit = false;
   AddGeochronToExistingCollUnit = false;
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaUploadForm::FormCreate(TObject *Sender)
{
   Step = 0;
   nSteps = 49;
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaUploadForm::FormActivate(TObject *Sender)
{
   if (!Activated) {
	 Activated = true;
	 Validate();
	 }
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaUploadForm::FormClose(TObject *Sender, TCloseAction &Action)
{
   // reset temp IDs back to -1
   for (int i=0; i<TSSForm->Sites->Count; i++) {
	 site_ptr = (SITE*)TSSForm->Sites->Items[i];
	 if (site_ptr->NeotomaSiteID < -1)
	   site_ptr->NeotomaSiteID = -1;
	 for (unsigned int j=0; j<site_ptr->CollUnits.size(); j++) {
	   if (site_ptr->CollUnits[j].NeotomaCollUnitID < -1)
		 site_ptr->CollUnits[j].NeotomaCollUnitID = -1;
	   }
	 }

   if (SpecimenDateChronNo != -1) {
	 for (int i=0; i < TSSForm->AgeModelList->Count; i++) {
	   AGEMODEL* AgeModel = TSSForm->AgeModelList->AgeModels[i];
	   if (AgeModel->ChronNumber == SpecimenDateChronNo) {
		 TSSForm->AgeModelList->Delete(i);
		 break;
		 }
	   }
	 }
   if (SpecimenDateDatasetID != -1) {
	 vector<DATASET>::iterator itr;
	 for (itr = TSSForm->Datasets.begin(); itr != TSSForm->Datasets.end(); itr++) {
	   if (itr->NeotomaDatasetID == SpecimenDateDatasetID) {
		 TSSForm->Datasets.erase(itr);
		 break;
	     }
	   }
	 }

   if (WhitmoreAccess != NULL)
	 delete WhitmoreAccess;
}
//---------------------------------------------------------------------------

void TNeotomaUploadForm::StartRat(void)
{
   RatPos = 16;
   Image1->Visible = true;
   Timer1->Enabled = true;
}
//---------------------------------------------------------------------------

void TNeotomaUploadForm::EndRat(void)
{
   Timer1->Enabled = false;
   Image1->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaUploadForm::Timer1Timer(TObject *Sender)
{
   RatPos += 48;
   if (RatPos > RatEnd)
	 RatPos = RatStart;
   Image1->Left = RatPos;
}
//---------------------------------------------------------------------------

void TNeotomaUploadForm::OutputLine(UnicodeString line)
{
   RichEdit1->SelAttributes->Color = clBlack;
   RichEdit1->Lines->Add(line);
   /*
   RichEdit1.SetFocus;
   RichEdit1.SelStart := RichEdit1.GetTextLen;
   RichEdit1.Perform(EM_SCROLLCARET, 0, 0);
   */
}
//---------------------------------------------------------------------------

void TNeotomaUploadForm::OutputBoldLine(UnicodeString line)
{
   RichEdit1->SelAttributes->Style = RichEdit1->SelAttributes->Style << fsBold;
   RichEdit1->SelAttributes->Color = clBlack;
   RichEdit1->Lines->Add(line);
   RichEdit1->SelAttributes->Style = RichEdit1->SelAttributes->Style >> fsBold;
}
//---------------------------------------------------------------------------

void TNeotomaUploadForm::OutputError(UnicodeString line)
{
   RichEdit1->SelAttributes->Color = clRed;
   RichEdit1->Lines->Add(line);
   TotalMessages.Errors++;
}
//---------------------------------------------------------------------------

void TNeotomaUploadForm::OutputWarning(UnicodeString line)
{
   RichEdit1->SelAttributes->Color = clBlue;
   RichEdit1->Lines->Add(line);
   TotalMessages.Warnings++;
}
//--------------------------------------------------------------------------

void TNeotomaUploadForm::OutputNote(UnicodeString line)
{
   RichEdit1->SelAttributes->Color = clPurple;
   RichEdit1->Lines->Add(line);
   TotalMessages.Notes++;
}
//--------------------------------------------------------------------------

void TNeotomaUploadForm::SetProgressBar(short style)
{
   switch (style) {
	 case MARQUEE:
	   cxProgressBar1->Visible = false;
	   StartRat();
	   break;
	 case CORE:
	   EndRat();
	   cxProgressBar1->Visible = true;
	   cxProgressBar1->Style->TextColor = (cxProgressBar1->Position > 50) ? clYellow : clNavy;
	   break;
	 case NOBAR:
	   cxProgressBar1->Visible = false;
	   EndRat();
	   break;
	 }
}
//---------------------------------------------------------------------------

void TNeotomaUploadForm::SetProgressBarPosition(void)
{
   Step++;
   cxProgressBar1->Position = 100*Step/nSteps;
}
//---------------------------------------------------------------------------

void TNeotomaUploadForm::SetProgressBarPosition(int steps)
{
   Step += steps;
   cxProgressBar1->Position = 100*Step/nSteps;
}
//---------------------------------------------------------------------------

void TNeotomaUploadForm::Validate(void)
{
   if (!RunValidation()) {
	 OutputError(L"VALIDATION ABORTED");
	 cxButton2->Visible = false;
	 cxButton3->Visible = true;
	 cxButton1->Visible = true;
	 cxButton4->Visible = true;
	 SetProgressBar(CORE);
	 }
}
//---------------------------------------------------------------------------

bool TNeotomaUploadForm::RunValidation(void)
{
   int rv;

   // configure the IP*Works! HTTPS Component for uploading data to Neotoma
   ipsHTTPS1->ResetHeaders();
   ipsHTTPS1->Config("KeepAlive=true");
   ipsHTTPS1->Config("CodePage=65001");   // UTF-8 CodePage
   ipsHTTPS1->LocalHost = TcpClient1->LocalHostAddr();
   ipsHTTPS1->TransferredDataLimit = 0;
   OtherHeaders = L"username:" + Login->UserName + L"\r\npwd:" + Login->Password +
				  L"\r\nconstituentDatabase:" + IntToStr(Login->DatabaseID);
   ipsHTTPS1->OtherHeaders = OtherHeaders;

   // TODO: modify this to do a taxa check for non stewards
   //NewMessages.SetMessages(TotalMessages, ArchiveMessages);
   if (!InitialValidation())
     return false;

   OutputBoldLine(L"Initial data validation:");
   // delete any empty rows or columns
   CheckEmptyRows();
   CheckEmptyColumns();

   // get list of taxa with row numbers
   if (GetVariables() ==  mrAbort)
	 return false;

   // Check for all null or zero data rows
   if (VarErrors)
	 OutputError(L"ERROR: Errors in taxa names. Data validation skipped.");
   else if (!GeochronOnly){
	 if (!CheckEmptyData()) // 1 step
	   return false;
	 if (!CheckZeroData())  // 1 step, also checks for numerical data
	   return false;
	 if (!CheckDepthsNames())  // 1 step
	   return false;
	 if (!CheckTopBottom())
	   return false;
	 if (!AssembleIsoDataset())  // 1 step, also validate
	   return false;
	 if (!ValidateSSMetadata())  // 1 step, samples and analysis unit metadata
	   return false;
	 OutputBoldLine(L"Initial data validation completed: " + ValidationMsg(TotalMessages));
	 ArchiveMessages.SetMessages(TotalMessages);
	 }
   else
	 SetProgressBarPosition(5);

   // validate taxa and variables
   if (!VarErrors & !GeochronOnly) {
	 OutputLine(L"");
	 OutputBoldLine(L"Taxon name and variable validation:");
	 if (!CheckDuplicates())  // 1 step
	   return false;
	 if (!VarErrors) {
	   int begin_errors = TotalMessages.Errors;
	   if (CheckUnits() == mrAbort)
		 return false;   // 1 step
	   if (CheckElements() == mrAbort)  // 1 step, check that variables have elements
		 return false;
	   if (!ValidateTaxa())  // 1 step
		 return false;
	   if (!ValidateTaxaDatasetTypes())  // 1 step
		 return false;
	   if (!ValidateVariables())   // 1 step
	   	 return false;
	   if (!ValidateTaphonomy())   // 1 step
		 return false;
	   if (!ValidateTaxonNotes())  // 1 step
		 return false;
	   if (TotalMessages.Errors > begin_errors)
		 VarErrors = true;
	   }
	 }
   else
	 SetProgressBarPosition(8);

   NewMessages.SetMessages(TotalMessages, ArchiveMessages);
   OutputBoldLine(L"Taxon name and variable validation completed: " + ValidationMsg(NewMessages));
   ArchiveMessages.SetMessages(TotalMessages);

   // validate specimens
   if (!GeochronOnly) {
	 OutputLine(L"");
	 OutputBoldLine(L"Specimen validation:");
	 if (!VarErrors) {
	   if (!ValidateSpecimens())
		 return false;
	   }
	 NewMessages.SetMessages(TotalMessages, ArchiveMessages);
	 OutputBoldLine(L"Specimen validation completed: " + ValidationMsg(NewMessages));
	 ArchiveMessages.SetMessages(TotalMessages);
	 }
   SetProgressBarPosition();

   // validate publications
   OutputLine(L"");
   OutputBoldLine(L"Publication Metadata validation:");
   ValidatePublications();
   ValidatePublicationIDs();
   NewMessages.SetMessages(TotalMessages, ArchiveMessages);
   OutputBoldLine(L"Publication metadata validation completed: " + ValidationMsg(NewMessages));
   ArchiveMessages.SetMessages(TotalMessages);

   // validate contacts
   OutputLine(L"");
   OutputBoldLine(L"Contacts Metadata validation:");
   if (!ValidateContacts())
	 return false;
   NewMessages.SetMessages(TotalMessages, ArchiveMessages);
   OutputBoldLine(L"Contacts metadata validation completed: " + ValidationMsg(NewMessages));
   ArchiveMessages.SetMessages(TotalMessages);

   // validate site metadata
   OutputLine(L"");
   OutputBoldLine(L"Site Metadata validation:");
   // Check if site is already in Neotoma
   if (MultiSiteUpload && !GeochronOnly) {
	 bool validate = true;
	 if (TSSForm->ValidatedSites != NULL) {
	   if (TSSForm->ValidatedSites->Count == TSSForm->Sites->Count) {
		 bool revalidate = false;
		 for (int i=0; i<TSSForm->ValidatedSites->Count; i++) {
		   SITE* valsite = (SITE*)TSSForm->ValidatedSites->Items[i];
		   if (!valsite->SameSite((SITE*)TSSForm->Sites->Items[i])) {
			 revalidate = true;
			 break;
			 }
		   }
		 if (!revalidate) {
		   UnicodeString msg = L"Sites have already been validated. Would you like to revalidate?";
		   if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrNo)
			 validate = false;
		   }
		 }
	   }
	 if (validate) {
	   int nerr = TotalMessages.Errors;
	   for (int i=1; i<TSSForm->Sites->Count; i++) {
		 site_ptr = (SITE*)TSSForm->Sites->Items[i];
		 if (!ValidateSite(site_ptr))
		   return false;
		 if (!ValidateSiteExists(site_ptr))
		   return false;
		 }
	   if (nerr == TotalMessages.Errors) {  // all sites validated
		 if (TSSForm->ValidatedSites == NULL)
		   TSSForm->ValidatedSites = new TList;
		 else {
		   for (int i=0; i<TSSForm->ValidatedSites->Count; i++) {
			 SITE *site = (SITE*)TSSForm->ValidatedSites->Items[i];
			 delete site;
			 TSSForm->ValidatedSites->Items[i] = 0;
			 }
		   TSSForm->ValidatedSites->Clear();
		   }
		 for (int i=0; i<TSSForm->Sites->Count; i++) {
		   SITE* site = new SITE((SITE*)TSSForm->Sites->Items[i]);
		   TSSForm->ValidatedSites->Add(site);
		   }
		 }
	   }
	 }
   else {
	 if (!ValidateSite(site_ptr))
	   return false;
	 if (!ValidateSiteExists(site_ptr))
	   return false;
	 }
   SetProgressBarPosition(5);

   NewMessages.SetMessages(TotalMessages, ArchiveMessages);
   OutputBoldLine(L"Site metadata validation completed: " + ValidationMsg(NewMessages));
   ArchiveMessages.SetMessages(TotalMessages);

   // validate collection unit metadata
   OutputLine(L"");
   OutputBoldLine(L"Collection Unit Metadata validation:");
   if (MultiSiteUpload) {
	 for (int i=1; i<TSSForm->Sites->Count; i++) {
	   if (!ValidateCollectionUnit((SITE*)TSSForm->Sites->Items[i]))
		 return false;
	   }
	 }
   else if (!ValidateCollectionUnit(site_ptr))
	 return false;
   NewMessages.SetMessages(TotalMessages, ArchiveMessages);
   OutputBoldLine(L"Collection Unit metadata validation completed: " + ValidationMsg(NewMessages));
   ArchiveMessages.SetMessages(TotalMessages);

   // validate lithology
   if (!MultiSiteUpload) {
	 OutputLine(L"");
	 OutputBoldLine(L"Lithology validation:");
	 if (!ValidateLithology())
	   return false;
	 NewMessages.SetMessages(TotalMessages, ArchiveMessages);
	 OutputBoldLine(L"Lithology validation completed: " + ValidationMsg(NewMessages));
	 ArchiveMessages.SetMessages(TotalMessages);
	 }

   // validate dataset metadata
   bool is_surface_sample = false;
   if (!GeochronOnly) {
	 OutputLine(L"");
	 OutputBoldLine(L"Dataset validation:");
	 if (!ValidateDatasets())  // 1 step
	   return false;
	 NewMessages.SetMessages(TotalMessages, ArchiveMessages);
	 OutputBoldLine(L"Dataset validation completed: " + ValidationMsg(NewMessages));
	 ArchiveMessages.SetMessages(TotalMessages);

	 // validate analysis units and samples
	 OutputLine(L"");
	 OutputBoldLine(L"Analysis Unit and Sample validation:");
	 if (VarErrors)
	   OutputNote(L"NOTE: Errors in variables. Analysis Unit and Sample validation skipped.");
	 else if (!ValidateSamples())  // 1 step
	   return false;
	 NewMessages.SetMessages(TotalMessages, ArchiveMessages);
	 OutputBoldLine(L"Analysis Unit and Sample validation completed: " + ValidationMsg(NewMessages));
	 ArchiveMessages.SetMessages(TotalMessages);

	 // validate surface sample
	 if (!ValidateSurfaceSample(is_surface_sample))
	   return false;
	 }
   else
	 SetProgressBarPosition(3);

   if (is_surface_sample && !GeochronOnly) {
	 NewMessages.SetMessages(TotalMessages, ArchiveMessages);
	 OutputBoldLine(L"Surface sample validation completed: " + ValidationMsg(NewMessages));
	 ArchiveMessages.SetMessages(TotalMessages);
	 }
   else {
	 // validate geochronology
	 OutputLine(L"");
	 OutputBoldLine(L"Geochronology validation:");
	 if (!ValidateGeochron())
	   return false;
	 NewMessages.SetMessages(TotalMessages, ArchiveMessages);
	 OutputBoldLine(L"Geochronology validation completed: " + ValidationMsg(NewMessages));
	 ArchiveMessages.SetMessages(TotalMessages);

	 if (!GeochronOnly || TSSForm->Datasets.size() > 1) {
	   // validate age models
	   OutputLine(L"");
	   OutputBoldLine(L"Chronology validation:");
	   if (!ValidateAgeModels(NULL))   // 3 steps
		 return false;
	   NewMessages.SetMessages(TotalMessages, ArchiveMessages);
	   OutputBoldLine(L"Chronology validation completed: " + ValidationMsg(NewMessages));
	   ArchiveMessages.SetMessages(TotalMessages);

	   // validate sample ages
	   OutputLine(L"");
	   OutputBoldLine(L"Sample age validation:");
	   if (!ValidateSampleAges())    // 1 step
		 return false;
	   NewMessages.SetMessages(TotalMessages, ArchiveMessages);
	   OutputBoldLine(L"SampleAge validation completed: " + ValidationMsg(NewMessages));
	   ArchiveMessages.SetMessages(TotalMessages);
	   }
	 else
	   SetProgressBarPosition(4);
	 }

   UnicodeString msg;

   if (!GeochronOnly) {
	 // validate isotopes
	 if (!TSSForm->AdvIsotopeStringGrid->AllCells[3][2].IsEmpty()) {
	   OutputLine(L"");
	   OutputBoldLine(L"Isotope data validation:");
	   if (!ValidateIsotopeDataset(is_surface_sample))
		 return false;
	   NewMessages.SetMessages(TotalMessages, ArchiveMessages);
	   OutputBoldLine(L"Dataset validation completed: " + ValidationMsg(NewMessages));
	   ArchiveMessages.SetMessages(TotalMessages);
	   }
	 }
   SetProgressBarPosition();

   // delete any added chrons
   for (int i=0; i<TSSForm->AgeModelList->Count; i++) {
	 AGEMODEL* AgeModel = TSSForm->AgeModelList->AgeModels[i];
	 if (ChronNumbers.find(AgeModel->ChronNumber) == ChronNumbers.end()) {
	   TSSForm->AgeModelList->Delete(i);
	   }
	 }

   if (!GeochronOnly) {
	 // validate aggregate dataset chronology
	 if (AggregateDatasets.size() > 0) {
	   OutputLine(L"");
	   OutputBoldLine(L"Aggregate chronology validation:");
	   if (!ValidateAggregateChrons())
		 return false;
	   NewMessages.SetMessages(TotalMessages, ArchiveMessages);
	   OutputBoldLine(L"Aggregate chronology validation completed: " + ValidationMsg(NewMessages));
	   ArchiveMessages.SetMessages(TotalMessages);
	   }
	 }
   SetProgressBarPosition();

#ifdef WHITMORE
   if (TSSForm->Datasets[0].WhitmoreData) {
	 OutputLine(L"");
	 OutputBoldLine(L"Whitmore validation:");
	 int SampNameRow = TSSForm->FindRowCodeIC(L"#Samp.Name", TSSForm->ProfGrid1);
	 if (SampNameRow == 0) {  // this should never happen, but..
	   msg = L"#Samp.Name not found in spreadsheet.";
	   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return false;
	   }

	 int HandleRow = TSSForm->FindRowCodeIC(L"#Coll.Handle", TSSForm->ProfGrid1);

	 UnicodeString Handle;
	 UnicodeString ID1Str;
	 int ID1;

	 int StartCol = TSSForm->AbsHeaderColCount(TSSForm->ProfGrid1);
	 int EndCol = TSSForm->AbsContentColCount(TSSForm->ProfGrid1);
	 for (int col=StartCol; col<=EndCol; col++) {
	   if (HandleRow == 0) {
		 SITE* site_ptr = (SITE*)TSSForm->Sites->Items[0];
		 Handle = site_ptr->CollUnits[0].Handle;
		 }
	   else
		 Handle = TSSForm->ProfGrid1->AbsoluteCells[col][HandleRow]->Text;
	   UnicodeString ID1Str = TSSForm->ProfGrid1->AbsoluteCells[col][SampNameRow]->Text;
	   if (!TryStrToInt(ID1Str, ID1)) {
		 msg = L"Invalid value for ID1: " + ID1Str;
		 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 return false;
		 }
	   msg = L"Handle: «" + Handle + L"», Whitemore ID1 = " + IntToStr(ID1) + L".";
	   OutputLine(msg);
	   WhitmoreIDs[Handle] = ID1;
	   }
	 ArchiveMessages.SetMessages(TotalMessages);
	 OutputBoldLine(L"Whitmore validation completed: " + ValidationMsg(NewMessages));
	 }
#endif

   StatusBar1->SimpleText = L"";
   OutputLine(L"");
   OutputBoldLine(L"Initial validation completed: " + ValidationMsg(TotalMessages));
   OutputBoldLine(L"Number of steps = " + IntToStr(Step));

   if (TotalMessages.Errors > 0) {
	 msg = L"All validation errors must be resolved before data can be uploaded.";
	 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
	 }
   else if (TotalMessages.Warnings > 0 || TotalMessages.Notes > 0) {
	 msg = L"All data validated. Review all warnings and notes before uploading!";
	 MessageDlg(msg, mtWarning, TMsgDlgButtons() << mbOK, 0);
	 cxButton2->Visible = true;
	 }
   else {
	 msg =  L"All data validated. Data may be uploaded.";
	 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
	 cxButton2->Visible = true;
	 }
   cxButton3->Visible = true;
   cxButton1->Visible = true;
   cxButton4->Visible = true;
   return true;
}
//---------------------------------------------------------------------------

bool TNeotomaUploadForm::ValidateSite(SITE* site_ptr)
{
   bool rv = CheckSiteName(site_ptr);
   if (rv == mrOk) {
	 if (CheckNeotomaSite(site_ptr) == mrAbort)
	   return false;
	 }
   else if (rv == mrAbort)
	 return false;
   return true;
}
//---------------------------------------------------------------------------

bool TNeotomaUploadForm::ValidateSiteExists(SITE* site_ptr)
{
   if (site_ptr->NeotomaSiteID > 0) {  // site already exists
	 UpdateNeotomaSiteForm = new TUpdateNeotomaSiteForm(site_ptr, true, TSSForm, this);
	 UpdateNeotomaSiteForm->ShowModal();
	 delete UpdateNeotomaSiteForm;
	 if (TSSForm->Sites->Count == 1)
	   TSSForm->FillSiteMetaData(site_ptr);
	 // SetProgressBarPosition(5);
	 }
   else {  // new site
	 if (!CheckSiteLatLong(site_ptr))
	   return false;
	 if (CheckGeoPolUnits(site_ptr) == mrAbort)
	   return false;
	 CheckSiteAltitude(site_ptr);
	 CheckSiteArea(site_ptr);
	 CheckLakeParameters(site_ptr);
	 }
   return true;
}
//---------------------------------------------------------------------------

// upload button
void __fastcall TNeotomaUploadForm::cxButton2Click(TObject *Sender)
{
   int SiteID;
   int CollUnitID;
   UnicodeString msg;
   UnicodeString EPDDatasetName;
   int EPDDatasetID;
   vector<int> AnalysisUnitIDs;
   int GeochronDatabaseID = NeotomaGeochrons.size();

   DATASETSUBMISSION GeochronSubmission;

   if (TSSForm->EPD.SiteID > -1) {  // legacy EPD site
	 if (TSSForm->EPD.Datasets.count(1) > 0) {
	   GeochronSubmission.DatasetID = TSSForm->EPD.Datasets[1];
	   GeochronSubmission.DatabaseID = 3;
	   GeochronSubmission.SubmissionTypeID = 7;
	   }
	 //TODO: need to check what SubmitForm->Geochron is
	 for (unsigned int i=0; i<site_ptr->CollUnits[0].NeotomaDatasets.size(); i++) {
	   site_ptr->CollUnits[0].NeotomaDatasets[i].NeotomaDatabaseID = 3;
	   site_ptr->CollUnits[0].NeotomaDatasets[i].NeotomaSubmissionTypeID = 7;
	   }
	 }

   int first_dataset = (GeochronOnly) ? 1 : 0;
   SubmitForm = new TSubmitForm(first_dataset, GeochronDatabaseID, &TSSForm->Datasets, TSSForm->EPD.SiteID, this);
   int rv = SubmitForm->ShowModal();
   if (rv == mrOk) {
	 GeochronSubmission = SubmitForm->Geochron;
	 for (int ns=0; ns<TSSForm->Sites->Count; ns++) {
	   site_ptr = (SITE*)TSSForm->Sites->Items[ns];
	   int idx1 = (site_ptr->CollUnits.size() == 1) ? 0 : 1;
	   for (unsigned int nc=idx1; nc<site_ptr->CollUnits.size(); nc++) {
		 for (unsigned int i=0; i<site_ptr->CollUnits[nc].NeotomaDatasets.size(); i++) {
		   int j = (GeochronOnly) ? i+1 : i;
		   site_ptr->CollUnits[nc].NeotomaDatasets[i].NeotomaDatabaseID = TSSForm->Datasets[j].NeotomaDatabaseID;
		   site_ptr->CollUnits[nc].NeotomaDatasets[i].NeotomaSubmissionTypeID = TSSForm->Datasets[j].NeotomaSubmissionTypeID;
		   site_ptr->CollUnits[nc].NeotomaDatasets[i].NeotomaSubmissionNotes = TSSForm->Datasets[j].NeotomaSubmissionNotes;

		   // here's the problem
		   // site_ptr->CollUnits[nc].NeotomaDatasets[i].WhitmoreID1 = site_ptr->CollUnits[nc].WhitmoreID1;

		   }
		 }                    // CollUnit.NeotomaDatasets[i].NeotomaDatabaseID;
	   }
	 }
   delete SubmitForm;
   if (rv == mrCancel)
	 return;

   FocusControl(RichEdit1);
   OutputLine(L"");
   OutputBoldLine(L"Upload Process");
   OutputLine(L"Steward ContactID = " + IntToStr(Login->ContactID));

   // if (TSSForm->Datasets[0].WhitmoreID1 != -1) [  // Whitmore dataset
   if (TSSForm->Datasets[0].WhitmoreData) {  // Whitmore dataset
	 WhitmoreAccess = new Access(ADOConnection1, tiGlobals->WhitmorePath);
	 if (WhitmoreAccess->Connect()) {
	   OutputLine(L"Connected to Whitmore Access database.");
	   }
	 else {
	   OutputError(L"ERROR: Cannot connect to Whitmore Access database. Upload aborted. No data uploaded.");
	   return;
	   }
	 }

   // site_ptr = (SITE*)TSSForm->Sites->Items[0];

   int idx1 = (MultiSiteUpload) ? 1 : 0;
   for (int i=idx1; i<TSSForm->Sites->Count; i++) {
	 site_ptr = (SITE*)TSSForm->Sites->Items[i];
	 if (!UploadSite(SiteID)) return;
	 unsigned int start = (site_ptr->CollUnits.size() == 1) ? 0 : 1;
	 for (unsigned int j=start; j<site_ptr->CollUnits.size(); j++) {
	   NeotomaDatasetIDs.clear();
	   if (!UploadCollUnit(SiteID, site_ptr->CollUnits[j], CollUnitID)) return;  // returns Neotoma CollUnitID
	   if (!MultiSiteUpload && !AddDataToExistingCollUnit) // need to deal with this
		 if (!UploadLithology(CollUnitID)) return;
	   AnalysisUnitIDs.clear();
	   if (!UploadAnalysisUnits(CollUnitID, AnalysisUnitIDs)) return;
	   if (!GeochronOnly)
		 if (!UploadTephras(CollUnitID)) return;
	   if (GeochronOnly) {
		 if (!UploadGeochronology(CollUnitID, GeochronSubmission)) return;
		 }
	   // else if (!AddDataToExistingCollUnit || TSSForm->EPD.SiteID > -1) [   // need to deal with this
	   else if (!AddDataToExistingCollUnit || AddGeochronToExistingCollUnit || TSSForm->EPD.SiteID > -1) {
		 if (!UploadGeochronology(CollUnitID, GeochronSubmission)) return;
		 }
	   if (!GeochronOnly || TSSForm->Datasets.size() > 1)
		 if (!UploadChronologies(CollUnitID)) return;
	   vector<NEOTOMADATASET> NeotomaDatasets;
	   if (!UploadDatasets(CollUnitID, site_ptr->CollUnits[j], NeotomaDatasets)) return;
	   if (!UploadSamples(NeotomaDatasets)) return;  // also uploads data including specimen data and taphonomy
	   if (!GeochronOnly)
		 if (!UploadAccRates()) return;
	   if (!UploadSpecimenDates(CollUnitID)) return;
	   if (!GeochronOnly) {
		 if (!UploadSpecimenIsotopes(CollUnitID, NeotomaDatasets)) return;
		 for (unsigned int k = 0; k < NeotomaDatasets.size(); k++) {
		   UnicodeString DatasetName = NeotomaDatasets[k].DatasetName;
		   int DatasetTypeID = NeotomaDatasets[k].NeotomaDatasetTypeID;
		   if (SameText(DatasetName.SubString(1,6), L"EPD E#") && DatasetTypeID == 3) {
			 EPDDatasetName = DatasetName;
			 EPDDatasetID = NeotomaDatasets[k].DatasetID;
			 break;
			 }
		   }
		 }
	   if (!UploadDatasetSubmissions(CollUnitID, NeotomaDatasets, GeochronSubmission)) return;
	   }
	 if (!GeochronOnly || TSSForm->Datasets.size() > 1) {
	   if (!UploadGeochronControls()) return;
	   }
	 if (!EPDDatasetName.IsEmpty()) {
	   if (!UploadEPDEntityDatasetIDs(EPDDatasetName, NeotomaDatasetIDs[EPDDatasetID])) return;
	   }
	 }

   if (Aggregates && !GeochronOnly) {
	 UploadAggregate();
	 TSSForm->AgeModelList->Clear();
	 }

#ifdef WHITMORE
   if (WhitmoreSamples.size() > 0)
	 RegisterWhitmoreSamples();
#endif

   StatusBar1->SimpleText = L"";
   cxButton2->Visible = false;

   msg = L"Upload completed! " + DateTimeStr(UTCDateTime()) + L" UTC";
   OutputLine(msg);
   MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
   DataUploaded = true;
}
//---------------------------------------------------------------------------

void TNeotomaUploadForm::RegisterWhitmoreSamples(void)
{
   UnicodeString msg;
   TParameter* Param;
   int rows_affected = 0;

   map<int,int>::iterator itr;
   for (itr = WhitmoreSamples.begin(); itr != WhitmoreSamples.end(); itr++) {
	 Param = ADOQuery1->Parameters->ParamByName("ID1");
	 Param->Value = itr->first;
	 Param = ADOQuery1->Parameters->ParamByName("SampleID");
	 Param->Value = itr->second;
	 int rows = ADOQuery1->ExecSQL();
	 rows_affected += rows;
	 msg = L"Whitmore Access database ID1 = " + IntToStr(itr->first) +
		   L": NeotomaSampleID updated to " + IntToStr(itr->second) + L".";
	 OutputLine(msg);
	 }

   msg = L"Whitmore Access Database: " + IntToStr(rows_affected) + L" row";
   if (rows_affected > 1) msg += L"s";
   msg += L" updated.";
   OutputLine(msg);
}
//---------------------------------------------------------------------------

bool TNeotomaUploadForm::UploadEPDEntityDatasetIDs(UnicodeString EPDDatasetName, int EPDDatasetID)
{
   // EPD E# 2000
   UnicodeString ErrorMsg;
   UnicodeString ENr = EPDDatasetName.Delete(1,7);
   int EntityNr;

   if (!TryStrToInt(ENr,EntityNr))
	return false;

   vector<int> newids;
   InsertData InsertEntityDatasetID(L"InsertEPDEntityDatasetID", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
   InsertEntityDatasetID.Add(L"ENR", EntityNr);
   InsertEntityDatasetID.Add(L"DATASETID", EPDDatasetID);
   StatusBar1->SimpleText = L"InsertEPDEntityDatasetID";
   InsertEntityDatasetID.PostData();
   if (InsertEntityDatasetID.Post(newids, ErrorMsg)) {
	 if (newids.size() == 1) {
	   OutputLine(L"EPD E# = " + IntToStr(EntityNr) + L", DatasetID = " + IntToStr(EPDDatasetID));
	   }
	 else {
	   ErrorMsg = L"Error inserting into EPD EntityDatasetID table!";
	   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return false;
	   }
	 }
   else {
	 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 return false;
	 }

   return true;
}
//---------------------------------------------------------------------------

int TNeotomaUploadForm::GetVariables(void)
{
   vector<UnicodeString> ErrMsgs;
   bool querytype = true;
   bool converttype = true;
   UnicodeString msg;

   if (!TSSForm->GetSSVarList(SSVarList, false, ErrMsgs)) {
	 VarErrors = true;
	 for (unsigned int i=0; i<ErrMsgs.size(); i++)
	   OutputError(L"ERROR: " + ErrMsgs[i]);
	 return (MessageDlg(L"Errors in taxa names!", Dialogs::mtError, TMsgDlgButtons() << mbIgnore << mbAbort, 0));
	 }
   if (SSVarList.size() == 0) {
	 if (TSSForm->GeochronList->Count() > 0) {
	   msg = L"No data in spreadsheet. Upload geochronology dataset only?";
	   if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes) {
		 GeochronOnly = true;
		 return mrOk;
		 }
	   }
	 VarErrors = true;
	 OutputError(L"ERROR: No variables in spreadsheet.");
	 return (MessageDlg(L"No variables in spreadsheet!", Dialogs::mtError, TMsgDlgButtons() << mbIgnore << mbAbort, 0));
	 }

   // SSVarList.assign(TSSForm->SSVarList.begin(), TSSForm->SSVarList.end());
   // get a set of unique taxa names
   TaxaSet.clear();
   for (unsigned int i=0; i<SSVarList.size(); i++) {

     // convert Vepris-type nobilis > Vepris-type (V. nobilis)
	 if (converttype && ContainsText(SSVarList[i].name,L"-type ")) {
	   UnicodeString SSTaxonName = SSVarList[i].name;
	   UnicodeString LCTaxonName = SSTaxonName;
	   int pos = LCTaxonName.Pos(L"-type ");
	   if (LCTaxonName.Length() > pos+5 && LCTaxonName[pos+6] != L'(') {
		 if (querytype) {
		   msg = L"Convert taxon names of form «Vepris-type nobilis» to «Vepris-type (V. nobilis)»?";
		   if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes)
			 querytype = false;
		   else
			 converttype = false;
		   }
		 if (converttype) {
		   //UnicodeString originalname = SSTaxonName;
           int SSRow = SSVarList[i].row;
		   UnicodeString genustype = SSTaxonName.SubString(1,pos+4);
		   UnicodeString species = SSTaxonName.Delete(1,pos+4);
		   SSTaxonName = genustype + L" (" + genustype.SubString(1,1) + L"." + species + L")";
		   msg = L"Taxon name «" + SSVarList[i].name + L"» in row " + IntToStr(SSRow) +
				 L" changed to «" + SSTaxonName + L"».";
		   OutputLine(msg);
		   TSSForm->ProfGrid1->AbsoluteCells[2][SSRow]->Value = WideString(SSTaxonName);
		   SSVarList[i].name = SSTaxonName;
		   }
		 }
	   }

	 TAXONAUTHOR TaxonAuthor;
	 TaxonAuthor.name = SSVarList[i].name;
	 TaxonAuthor.author = SSVarList[i].author;
	 TaxaSet.insert(TaxonAuthor);
	 }
   return mrOk;
}
//---------------------------------------------------------------------------

int TNeotomaUploadForm::GetDatasetTypeID(UnicodeString DatasetType)
{
   int DatasetTypeID = -1;
   map<int,UnicodeString>::iterator itr;
   map<int,UnicodeString>::iterator begin = NeotomaDatasetTypes.begin();
   map<int,UnicodeString>::iterator end = NeotomaDatasetTypes.end();
   for (itr = begin; itr != end; itr++) {
	 if (SameText(DatasetType, itr->second)) {
	   DatasetTypeID = itr->first;
	   break;
	   }
	 }
   return DatasetTypeID;
}
//---------------------------------------------------------------------------

bool TNeotomaUploadForm::ValidateTaxaDatasetTypes(void)
{
   bool rv = true;

   // assign DatasetTypes based on spreadsheet designation
   UnicodeString DatasetType = TSSForm->Datasets[0].DatasetType;
   int DatasetTypeID = GetDatasetTypeID(DatasetType);
   if (DatasetTypeID == -1) {
	 MessageDlg(L"ERROR: Invalid DatasetType «" + DatasetType +L"»", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 return false;
	 }

   map<int,NEOTOMAVARIABLE>::iterator itr;
   map<int,NEOTOMAVARIABLE>::iterator begin = NeotomaVariables.begin();
   map<int,NEOTOMAVARIABLE>::iterator end = NeotomaVariables.end();
   if (TSSForm->Datasets.size() == 1) {
	 for (itr = begin; itr != end; itr++)
	   itr->second.DatasetTypeID = DatasetTypeID;
	 }
   else {   // go through SS rows and assign DatasetTypeIDs to variables
	 int nrows = TSSForm->AbsContentRowCount(TSSForm->ProfGrid1);
	 int row = TSSForm->AbsHeaderRowCount(TSSForm->ProfGrid1);
	 itr = begin;
	 while (row <= nrows && itr != end) {
	   UnicodeString VarCode = VarToStr(TSSForm->ProfGrid1->AbsoluteCells[1][row]->Value);
	   if (SameText(VarCode, L"#Data.Type")) {
		 DatasetType = VarToStr(TSSForm->ProfGrid1->AbsoluteCells[2][row]->Value);
		 DatasetTypeID = GetDatasetTypeID(DatasetType);
		 if (DatasetTypeID == -1) {
		   UnicodeString msg = L"ERROR: Invalid DatasetType «" + DatasetType + L"» in row " + IntToStr(row);
		   OutputError(msg);
		   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   return false;
		   }
		 }
	   else if (itr->first == row) {
		 itr->second.DatasetTypeID = DatasetTypeID;
		 itr++;
		 }
	   row++;
	   }
	 }

   // reassign any DatasetTypeIDs based on TaxaGroupIDs
   // TaxaGroupID, DatasetTypeID   MAM:5 | HRP:5 | MOL:5 | VPL:3 | VPL:4

   vector<TAXAGROUPDATASETTYPE> TaxaGroupDatasetIDs;
   for (itr = begin; itr != end; itr++) {
	 TAXAGROUPDATASETTYPE tgds;
	 tgds.TaxaGroupID = itr->second.TaxaGroupID;
	 tgds.DatasetTypeID = itr->second.DatasetTypeID;
	 vector<TAXAGROUPDATASETTYPE>::iterator first = TaxaGroupDatasetIDs.begin();
	 vector<TAXAGROUPDATASETTYPE>::iterator last = TaxaGroupDatasetIDs.end();
	 vector<TAXAGROUPDATASETTYPE>::iterator it = find(first, last, tgds);
	 if (it == last)
	   TaxaGroupDatasetIDs.push_back(tgds);
	 }

   for (unsigned int i=0; i<TaxaGroupDatasetIDs.size(); i++) {
	 NeotomaDatasetTypesByTaxaGroupID DatasetTypes(ipsJSONS1, TcpClient1);
	 DatasetTypes.AddParam(L"TAXAGROUPID", TaxaGroupDatasetIDs[i].TaxaGroupID);
	 StatusBar1->SimpleText = DatasetTypes.WebServiceName();
	 if (DatasetTypes.Execute()) {
	   if (DatasetTypes.Size() > 0) {
		 bool found = false;
		 map<int,UnicodeString>::iterator first = DatasetTypes.Items.begin();
		 map<int,UnicodeString>::iterator last = DatasetTypes.Items.end();
		 map<int,UnicodeString>::iterator it;
		 for (it = first; it != last; it++) {
		   if (TaxaGroupDatasetIDs[i].DatasetTypeID == it->first) {
			 found = true;
			 break;
			 }
		   }
		 if (!found) {
		   if (!GetTaxaGroups()) return false;
		   UnicodeString TaxaGroupID = TaxaGroupDatasetIDs[i].TaxaGroupID;
		   UnicodeString TaxaGroup = NeotomaTaxaGroups[TaxaGroupID];
		   int DatasetTypeID = TaxaGroupDatasetIDs[i].DatasetTypeID;
		   UnicodeString DatasetType = NeotomaDatasetTypes[DatasetTypeID];
		   vector<UnicodeString> TaxaNames; // names with assigned to invalid DatasetType
		   vector<int> rows;                // rows with invalid DatasetType

		   for (itr = begin; itr != end; itr++) {
			 if (SameText(itr->second.TaxaGroupID, TaxaGroupID) && itr->second.DatasetTypeID == DatasetTypeID) {
			   TaxaNames.push_back(itr->second.TaxonName);
			   rows.push_back(itr->first);
			   }
			 }
		   ReassignDatasetTypeForm = new TReassignDatasetTypeForm(TaxaGroup,
			 DatasetType, TaxaNames, DatasetTypes.Items, this);
		   int rv = ReassignDatasetTypeForm->ShowModal();
		   if (rv == mrOk) {
			 int NewDatasetTypeID = ReassignDatasetTypeForm->GetDatasetTypeID();
			 for (unsigned int i=0; i<rows.size(); i++)
			   NeotomaVariables[rows[i]].DatasetTypeID = NewDatasetTypeID;
			 OutputLine(L"Taxa in TaxaGroup «" + TaxaGroup + L"» reassigned to DatasetType «" +
			   NeotomaDatasetTypes[NewDatasetTypeID] + L"»");
			 }
		   delete ReassignDatasetTypeForm;
		   if (rv != mrOk) {
			 OutputError(L"ERROR: Taxa in TaxaGroup «" + TaxaGroup +
			   L"» are not assigned to the «" + DatasetType + L"» DatasetType.");
			 return (rv == mrCancel);
			 }
		   }
		 }
	   else {
		 MessageDlg(L"ERROR: TaxaGroup «" + TaxaGroupDatasetIDs[i].TaxaGroupID +
		     L"» not assigned to any DatasetType", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 return false;
		 }
	   }
	 else
	   return(false);
	 }
   SetProgressBarPosition();
   return rv;
}
//---------------------------------------------------------------------------

bool TNeotomaUploadForm::ValidateTaphonomy(void)
{
   UnicodeString msg;
   set<UnicodeString>::iterator sitr;
   vector<NEOTOMATAPHSYSTEM> SSTaphSystems;

   map<int,NEOTOMAVARIABLE>::iterator itr;
   map<int,NEOTOMAVARIABLE>::iterator begin = NeotomaVariables.begin();
   map<int,NEOTOMAVARIABLE>::iterator end = NeotomaVariables.end();
   Screen->Cursor = crHourGlass;
   bool error = false;

   // get vector of all taphonomic dataset,system pairs in spreadsheet
   for (itr = begin; itr != end; itr++) {
	 int row = itr->first;
	 TProfGridCell* ACell = TSSForm->ProfGrid1->AbsoluteCells[6][row];
	 if (ACell->CellObject != NULL) {
	   bool error1 = false;
	   CELLOBJECT* CellObject = (CELLOBJECT*)ACell->CellObject;
	   TAPHSYSTEMS* TaphSystems = (TAPHSYSTEMS*)CellObject->Object;
	   if (TaphSystems->DatasetType.IsEmpty() || SameText(TaphSystems->DatasetType, L"none")) {
		 OutputError(L"ERROR in Row " + IntToStr(row) +
		   L": Taphonomic Type is not assigned to a Dataset Type.");
		 error1 = true;
		 }
	   else {
		   // map<int,UnicodeString> NeotomaDatasetTypes;     // DatasetTypeID, DatasetType
		   UnicodeString DatasetType = NeotomaDatasetTypes[itr->second.DatasetTypeID];
		   int pos = DatasetType.LowerCase().Pos(L"surface sample");
		   if (pos > 0)
			 DatasetType = DatasetType.SubString(1,pos-1).Trim();

		   if (!SameText(TaphSystems->DatasetType, DatasetType)) {
		   OutputError(L"ERROR in Row " + IntToStr(row) + L": Dataset Type «" +
			 TaphSystems->DatasetType + L"» of Taphonomic Type does not agree with spreadsheet DatasetType «" +
			 NeotomaDatasetTypes[itr->second.DatasetTypeID] + L"».");
		   error1 = true;
		   }
		 }

	   for (unsigned int i=0; i<TaphSystems->Systems.size(); i++) {
		 if (TaphSystems->Systems[i].Name.IsEmpty() || SameText(TaphSystems->Systems[i].Name, L"none")) {
		   OutputError(L"ERROR in Row " + IntToStr(row) +
			 L": Taphonomic Type is not assigned to a Taphonomic System.");
		   error1 = true;
		   }
		 }

	   if (!error1) {
		 for (unsigned int i=0; i<TaphSystems->Systems.size(); i++) {
		   NEOTOMATAPHSYSTEM NtmTaphSystem(TaphSystems->DatasetType, TaphSystems->Systems[i].Name, TaphSystems->Systems[i].Types);
		   vector<NEOTOMATAPHSYSTEM>::iterator ssts_itr = find(SSTaphSystems.begin(), SSTaphSystems.end(), NtmTaphSystem);
           if (ssts_itr == SSTaphSystems.end()) {  // new TaphSystem
			 NtmTaphSystem.rows.push_back(row);
			 SSTaphSystems.push_back(NtmTaphSystem);
			 }
		   else { // TaphSystem found; add any new types
			 ssts_itr->rows.push_back(row);
			 ssts_itr->AddTypes(NtmTaphSystem.Types);
			 }
		   }
		 }
	   else
		 error = true;
	   }
	 }

   for (unsigned int i=0; i<SSTaphSystems.size(); i++) {
	 msg = L"DatasetType: " + SSTaphSystems[i].DatasetType + L"; System: " +
		   SSTaphSystems[i].SystemName + L" Types: ";
	 for (set<UnicodeString>::iterator sitr = SSTaphSystems[i].Types.begin(); sitr != SSTaphSystems[i].Types.end(); sitr++) {
	   if (sitr != SSTaphSystems[i].Types.begin())
		 msg += L", ";
	   msg += *sitr;
	   }
	 OutputLine(msg);
	 }

   // validate datasets and taphonomic systems
   if (!error) {
	 // get TaphonomicSystems table
	 NeotomaTaphonomicSystemsTable TaphonomicSystems(ipsJSONS1, TcpClient1);
	 StatusBar1->SimpleText = TaphonomicSystems.WebServiceName();
	 if (!TaphonomicSystems.Execute())
	   return false;
	 else
	   NeotomaTaphSystems = TaphonomicSystems.Items;   // save for use with specimens

	 for (unsigned int i=0; i<SSTaphSystems.size(); i++) {
	   if (SSTaphSystems[i].Types.size() > 0) {
		 // check that all DatasetTypes exist
		 int DatasetTypeID = GetDatasetTypeID(SSTaphSystems[i].DatasetType);
		 if (DatasetTypeID > -1)
		   SSTaphSystems[i].DatasetTypeID = DatasetTypeID;
		 else {
		   for (unsigned j=0; j<SSTaphSystems[i].rows.size(); j++) {
			 msg = L"ERROR in Row " + IntToStr(SSTaphSystems[i].rows[j]) + L": Dataset Type «" +
				   SSTaphSystems[i].DatasetType + L"» is not a valid Neotoma Dataset Type.";
			 OutputError(msg);
			 error = true;
			 }
		   }

		 // check that all TaphonomicSystems exist
		 int SystemID = GetTaphonomicSystemID(TaphonomicSystems.Items, SSTaphSystems[i].SystemName);
		 if (SystemID > -1)
		   SSTaphSystems[i].SystemID = SystemID;
		 else {
		   for (unsigned j=0; j<SSTaphSystems[i].rows.size(); j++) {
			 msg = L"ERROR in Row " + IntToStr(SSTaphSystems[i].rows[j]) + L": Taphonomic System «" +
				   SSTaphSystems[i].SystemName + L"» is not a valid Neotoma Taphonomic System.";
			 OutputError(msg);
			 error = true;
			 }
		   }
		 }
	   }
	 }

   for (unsigned int i=0; i<SSTaphSystems.size(); i++) {
	 msg = L"DatasetType: " + IntToStr(SSTaphSystems[i].DatasetTypeID) + L"; System: " +
		   IntToStr(SSTaphSystems[i].SystemID) + L" Types: ";
	 for (set<UnicodeString>::iterator sitr = SSTaphSystems[i].Types.begin(); sitr != SSTaphSystems[i].Types.end(); sitr++) {
	   if (sitr != SSTaphSystems[i].Types.begin())
		 msg += L", ";
	   msg += *sitr;
	   }
	 OutputLine(msg);
	 }

   // check that all systems are assiged to DatasetType in Neotoma
   if (!error) {
	 NeotomaTaphonomicSystemsDatasetTypesTable DatasetTypeSystems(ipsJSONS1, TcpClient1);
	 StatusBar1->SimpleText = DatasetTypeSystems.WebServiceName();
	 if (!DatasetTypeSystems.Execute())
	   return false;
	 else
	   NeotomaTaphDatasetTypes = DatasetTypeSystems.Items;

	 for (unsigned int i=0; i<SSTaphSystems.size(); i++) {
	   int DatasetTypeID = SSTaphSystems[i].DatasetTypeID;
	   int SystemID = SSTaphSystems[i].SystemID;
	   multimap<int,int>::iterator mitr = DatasetTypeSystems.Items.begin();
	   bool found = false;
	   while (!found && mitr != DatasetTypeSystems.Items.end()) {
		 if (DatasetTypeID == mitr->first && SystemID == mitr->second)
		   found = true;
		 else
		   mitr++;
		 }
	   if (!found) {
		 for (unsigned j=0; j<SSTaphSystems[i].rows.size(); j++) {
		   msg = L"ERROR in Row " + IntToStr(SSTaphSystems[i].rows[j]) + L": Taphonomic System «" +
				 SSTaphSystems[i].SystemName + L"» is not assigned to Dataset Type «" +
				 SSTaphSystems[i].DatasetType + L"» in Neotoma.";
		   OutputError(msg);
		   error = true;
		   }
		 }
	   }
	 }

   // check that all Types are assigned to System
   if (!error) {
	 for (unsigned int i=0; i<SSTaphSystems.size(); i++) {
	   NeotomaTaphonomicTypesBySystem TaphTypes(ipsJSONS1, TcpClient1);
	   StatusBar1->SimpleText = TaphTypes.WebServiceName();
	   TaphTypes.AddParam(L"TAPHONOMICSYSTEMID", SSTaphSystems[i].SystemID);
	   if (!TaphTypes.Execute())
		 return false;

	   for (sitr = SSTaphSystems[i].Types.begin(); sitr != SSTaphSystems[i].Types.end(); sitr++) {
		 bool found = false;
		 for (unsigned j=0; j<TaphTypes.Size(); j++) {  //TaphTypes.Items[j].TaphonomicSystemID
		   if (SameText(*sitr, TaphTypes.Items[j].TaphonomicType )) {
			 SSTaphSystems[i].TypeIDs[*sitr] = TaphTypes.Items[j].TaphonomicTypeID;
			 msg = L"Taphonomic Type: " + *sitr + L", ID = " + IntToStr(SSTaphSystems[i].TypeIDs[*sitr]);
			 OutputLine(msg);
			 found = true;
			 break;
			 }
		   }

		 if (!found) {
		   for (unsigned j=0; j<SSTaphSystems[i].rows.size(); j++) {
			 TProfGridCell* ACell = TSSForm->ProfGrid1->AbsoluteCells[6][SSTaphSystems[i].rows[j]];
			 TAPHSYSTEM* TaphSystem = (TAPHSYSTEM*)ACell->CellObject;
			 if (TaphSystem->Types.count(*sitr) > 0) {
			   msg = L"ERROR in row " + IntToStr(SSTaphSystems[i].rows[j]) + ": Taphonomic Type «" +
					 *sitr + L"» not assighed to Taphonomic System «" +
					 SSTaphSystems[i].SystemName + L"».";
			   OutputError(msg);
			   }
			 }
		   error = true;
		   }
		 }
	   }
	 }

   // finally, assign TaphSystemIDs and TaphonomicTypeIDs to NeotomaVariables
   // vector<pair<int,vector<int> > > Taphonomy;   // SystemID, TypeIDs
   for (unsigned int i=0; i<SSTaphSystems.size(); i++) {
	 for (unsigned int j=0; j<SSTaphSystems[i].rows.size(); j++) {
	   int row = SSTaphSystems[i].rows[j];
	   TProfGridCell* ACell = TSSForm->ProfGrid1->AbsoluteCells[6][row];
	   CELLOBJECT* CellObject = (CELLOBJECT*)ACell->CellObject;
	   TAPHSYSTEMS* TaphSystems = (TAPHSYSTEMS*)CellObject->Object;

	   for (unsigned int k=0; k<TaphSystems->Systems.size(); k++) {
		 if (SameText(TaphSystems->Systems[k].Name, SSTaphSystems[i].SystemName)) {
		   set<UnicodeString>::iterator begin = TaphSystems->Systems[k].Types.begin();
		   set<UnicodeString>::iterator end = TaphSystems->Systems[k].Types.end();
		   for (sitr = begin; sitr != end; sitr++) {
			 int TypeID = SSTaphSystems[i].TypeIDs[*sitr];
			 NeotomaVariables[row].TaphTypeIDs.push_back(TypeID);
			 msg = L"Type: " + *sitr + L", ID = " + IntToStr(TypeID);
			 OutputLine(msg);
			 }
		   }
		 }
	   }
	 }

   for (itr = begin; itr != end; itr++) {
	 int row = itr->first;
	 if (itr->second.TaphTypeIDs.size() > 0) {
	   msg = L"Row = " + IntToStr(row) + L", TaphonomyTypeIDS = ";
	   for (unsigned int i=0; i<itr->second.TaphTypeIDs.size(); i++) {
		 if (i > 0)
		   msg += L",";
		 msg += IntToStr(itr->second.TaphTypeIDs[i]);
		 }
	   OutputLine(msg);
	   }
	 }

   Screen->Cursor = crDefault;
   if (error) {
	 msg = L"Errors in Taphonomy!";
	 if (MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbIgnore << mbAbort, 0) == mrAbort)
	   return false;
	 }
   else {
	 OutputLine(L"Taphonomy validated.");
	 SetProgressBarPosition();
	 }

   return true;
}
//---------------------------------------------------------------------------

int TNeotomaUploadForm::GetTaphonomicSystemID(vector<NTMTAPHONOMICSYSTEMS>& Items, UnicodeString System)
{
  for (unsigned int i=0; i<Items.size(); i++) {
	if (SameText(System, Items[i].TaphonomicSystem))
	  return Items[i].TaphonomicSystemID;
	}
  return -1;
}
//---------------------------------------------------------------------------

bool TNeotomaUploadForm::ValidateTaxonNotes(void)
{
   bool error = false;
   UnicodeString msg;

   map<int,NEOTOMAVARIABLE>::iterator itr;
   map<int,NEOTOMAVARIABLE>::iterator begin = NeotomaVariables.begin();
   map<int,NEOTOMAVARIABLE>::iterator end = NeotomaVariables.end();
   Screen->Cursor = crHourGlass;

   for (itr = begin; itr != end; itr++) {
	 int row = itr->first;
	 TProfGridCell* ACell = TSSForm->ProfGrid1->AbsoluteCells[2][row];
	 if (ACell->CellObject != NULL) {
	   //TAXON_NOTES* TaxonNotes = (TAXON_NOTES*)ACell->CellObject;
	   CELLOBJECT* CellObject = (CELLOBJECT*)ACell->CellObject;
	   TAXON_NOTES* TaxonNotes = (TAXON_NOTES*)CellObject->Object;
	   itr->second.Notes = TaxonNotes->Notes;
	   for (unsigned int i=0; i<TaxonNotes->Synonymy.size(); i++)
		 itr->second.Synonymy.push_back(NEOTOMASYNONYMY(TaxonNotes->Synonymy[i]));

	   // validate invalid name
	   int ValidTaxonID = itr->second.TaxonID;
	   UnicodeString ValidTaxonName = itr->second.TaxonName;
	   for (unsigned int i=0; i<itr->second.Synonymy.size(); i++) {
		 UnicodeString InvalidTaxonName = itr->second.Synonymy[i].TaxonName;
		 //int InvalidTaxonID = itr->second.Synonymy[i].TaxonID;
		 TaxonByName NeotomaTaxon(ipsJSONS1, TcpClient1);
		 StatusBar1->SimpleText = NeotomaTaxon.WebServiceName();
		 NeotomaTaxon.AddParam(L"TAXONNAME", InvalidTaxonName);
		 if (NeotomaTaxon.Execute()) {
		   if (NeotomaTaxon.Size() == 1) {
			 bool Valid = VariantToBool(NeotomaTaxon.Items[0].Valid, false);
			 int InvalidTaxonID = VariantToInt(NeotomaTaxon.Items[0].TaxonID, -1);
			 // if invalid, check that it is a synonym of the valid taxon
			 if (!Valid) {
			   NeotomaSynonymsForInvalidTaxonID ValidSynonym(ipsJSONS1, TcpClient1);
			   StatusBar1->SimpleText = ValidSynonym.WebServiceName();

			   ValidSynonym.AddParam(L"INVALIDTAXONID", InvalidTaxonID);
			   if (ValidSynonym.Execute()) {
				 if (ValidSynonym.Size() == 1) {
				   if (ValidSynonym.Items[0].TaxonID == ValidTaxonID) {
					 itr->second.Synonymy[i].TaxonID = InvalidTaxonID;
					 }
				   else {
					 itr->second.Synonymy[i].TaxonID = InvalidTaxonID;
					 UnicodeString TaxonName = VarToStr(ValidSynonym.Items[0].TaxonName);
					 msg = L"WARNING: Taxon «" + InvalidTaxonName + L"» in row " + IntToStr(row) +
						   L" is designated as a synonym of «" + TaxonName + L"» in Neotoma not «" +
						   ValidTaxonName + L"».";
					 OutputWarning(msg);
					 }
				   }
				 else {
				   msg = L"ERROR: No valid synonyms are designated in Neotoma for taxon «" +
						 InvalidTaxonName + L"».";
				   OutputError(msg);
				   }
				 }
			   else
				 error = true;
			   }
			 else {  // prior ID is a valid taxon name
			   itr->second.Synonymy[i].TaxonID = InvalidTaxonID;
			   }
			 }
		   else {
			 msg = L"ERROR: Taxon «" + InvalidTaxonName + L"» in row " + IntToStr(row) +
				   L" designated as an original or prior ID is not in Neotoma.";
			 OutputError(msg);
			 error = true;
			 }
		   }
		 else
		   error = true;

		 if (!itr->second.Synonymy[i].Contrib && itr->second.Synonymy[i].Pub == NULL) {
		   msg = L"ERROR in row " + IntToStr(row) +
				 L": Contrib must be checked and/or a Publication must be entered for synonym «" +
				 itr->second.Synonymy[i].TaxonName + L"».";
		   OutputError(msg);
		   error = true;
		   }
		 }
	   }
	 }

   /*
   // wrong
   for (unsigned int j=0; j<NeotomaVariables.size(); j++) {
	 for (unsigned int k=0; k<NeotomaVariables[j].Synonymy.size(); k++)
	   OutputLine(L"Synonymy NeotomaPubID = " + IntToStr(NeotomaVariables[j].Synonymy[k].NeotomaPubID()));
	 }

   // right
   for (itr = begin; itr != end; itr++) {
	 for (unsigned int k=0; k<itr->second.Synonymy.size(); k++)
	   OutputLine(L"Synonymy NeotomaPubID = " + IntToStr(itr->second.Synonymy[k].NeotomaPubID()));
	 }
   */

   Screen->Cursor = crDefault;
   if (error) {
	 msg = L"Errors in synonyms!";
	 if (MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbIgnore << mbAbort, 0) == mrAbort)
	   return false;
	 }
   else {
	 OutputLine(L"Synonyms validated.");
	 SetProgressBarPosition();
	 }

   return true;
}
//---------------------------------------------------------------------------

bool TNeotomaUploadForm::ValidateVariables(void)
{
   UnicodeString ErrorMsg;;
   bool rv = true;

   // check that all elements, units, contexts, and taphonomies exist
   multimap<UnicodeString,int> SSElementRows;   // element, row
   map<UnicodeString,SSELEMENT> SSElements;  // element, SSELEMENT
   map<UnicodeString,set<int> > SSUnitTypes;  // units, set of DatasetTypeIDs
   map<UnicodeString,set<int> > SSContextTypes;  // contexts, set of DatasetTypeIDs
   set<UnicodeString> NewElementTypes;

   map<int,NEOTOMAVARIABLE>::iterator itr;
   map<int,NEOTOMAVARIABLE>::iterator begin = NeotomaVariables.begin();
   map<int,NEOTOMAVARIABLE>::iterator end = NeotomaVariables.end();
   Screen->Cursor = crHourGlass;


   // get list of all unique elements
   for (itr = begin; itr != end; itr++) {
	 int row = itr->first;
	 UnicodeString TaxaGroupID = itr->second.TaxaGroupID;

	 UnicodeString element = VarToStr(TSSForm->ProfGrid1->AbsoluteCells[3][row]->Value);

	 if (itr->second.DatasetTypeID == 31 && !element.IsEmpty()) {  // isotope dataset
	   UnicodeString TaxonAnal;
	   UnicodeString ElementAnal;
	   int pos = element.Pos(L";");
	   if (pos > 0) {
		 TaxonAnal = element.SubString(1,pos-1);
		 ElementAnal = element.Delete(1,pos);
		 ElementAnal = ElementAnal.Trim();
		 //itr->second.ElementAnalyzed = ElementAnal;
		 }
	   else
		 TaxonAnal = element;
	   TaxonAnal = TaxonAnal.Trim();

	   TaxonByName NeotomaTaxon(ipsJSONS1, TcpClient1);
	   StatusBar1->SimpleText = NeotomaTaxon.WebServiceName();
	   NeotomaTaxon.AddParam(L"TAXONNAME", TaxonAnal);
	   if (NeotomaTaxon.Execute()) {
		 bool err1 = false;
		 bool err2 = false;
		 if (NeotomaTaxon.Size() == 1) {
		   if (NeotomaTaxon.Items[0].Valid)
			 itr->second.TaxonAnalyzedID = NeotomaTaxon.Items[0].TaxonID;
		   else
			 err1 = true;

		   if (!ElementAnal.IsEmpty()) {
			 NeotomaElementTypeByName ElementType(ipsJSONS1, TcpClient1);
			 ElementType.AddParam(L"ELEMENTTYPE", ElementAnal);
			 StatusBar1->SimpleText = ElementType.WebServiceName();
			 if (ElementType.Execute()) {
			   if (ElementType.Size() == 1)
				 itr->second.ElementAnalyzedID = ElementType.Items.begin()->first;
			   else
				 err2 = true;
			   }
			 else
			   rv = false;
			 }
		   }
		 else
		   err1 = true;
		 if (err1) {
		   ErrorMsg = L"ERROR: Taxon analyzed «" + TaxonAnal + L"» for stable isotope «";
		   ErrorMsg += (itr->second.TaxonName + L"» in row " + IntToStr(itr->first));
		   ErrorMsg += L" is not valid.";
		   OutputError(ErrorMsg);
		   rv = false;
		   }
		 if (err2) {
		   ErrorMsg =  L"Element «" + ElementAnal + L"» for stable isotope «";
		   ErrorMsg += (itr->second.TaxonName + L"» in row " + IntToStr(itr->first));
		   ErrorMsg += L" is not in the Neotoma ElementTypes table.";
		   }
		 }
	   else
		 rv = false;

	   // element = L"";
	   }

	 if (!rv) {
	   OutputLine(L"Variable validation terminated.");
	   StatusBar1->SimpleText = L"";
	   Screen->Cursor = crDefault;
	   return rv;
	   }

	 itr->second.Element = element;
	 CheckElementFormat(itr->second.Element);
	 if (element != itr->second.Element)
	   TSSForm->ProfGrid1->AbsoluteCells[3][row]->Value = itr->second.Element;
	 SSElementRows.insert(pair<UnicodeString,int>(itr->second.Element,row));
	 if (SSElements.count(itr->second.Element) == 0) {
	   SSElements[itr->second.Element] = SSELEMENT(itr->second.Element);
	   }

	 UnicodeString Units = VarToStr(TSSForm->ProfGrid1->AbsoluteCells[4][row]->Value);
	 if (!Units.IsEmpty()) {
	   if (SSUnitTypes.count(Units) == 0) {
		 set<int> DatasetTypeIDs;
		 DatasetTypeIDs.insert(itr->second.DatasetTypeID);
		 SSUnitTypes[Units] = DatasetTypeIDs;
		 }
	   else if (SSUnitTypes[Units].count(itr->second.DatasetTypeID) == 0)
		 SSUnitTypes[Units].insert(itr->second.DatasetTypeID);
	   }

	 UnicodeString Context = VarToStr(TSSForm->ProfGrid1->AbsoluteCells[5][row]->Value);
	 if (!Context.IsEmpty()) {
	   if (SSContextTypes.count(Context) == 0) {
		 set<int> DatasetTypeIDs;
		 DatasetTypeIDs.insert(itr->second.DatasetTypeID);
		 SSContextTypes[Context] = DatasetTypeIDs;
		 }
	   else if (SSContextTypes[Context].count(itr->second.DatasetTypeID) == 0)
		 SSContextTypes[Context].insert(itr->second.DatasetTypeID);
	   }
	 }

   rv = ValidateElements(SSElements, SSElementRows);
   if (rv)
	 rv = ValidateUnits(SSUnitTypes);
   if (rv)
	 rv = ValidateContexts(SSContextTypes);

   // now validate complete variables and assign VariableIDs
   Screen->Cursor = crHourGlass;
   UnicodeString msg;
   bool errors = false;
   bool database_errors = false;
   vector<NEWNEOTOMAVARIABLE> NewVars;
   if (rv) {
	 for (itr = begin; itr != end; itr++) {
	   NeotomaVariableByComponents Variable(ipsJSONS1, TcpClient1);
	   Variable.AddParam(L"TAXONID", itr->second.TaxonID);
	   if (itr->second.ElementID > -1)
		 Variable.AddParam(L"VARIABLEELEMENTID", itr->second.ElementID);
	   if (itr->second.UnitsID > -1)
		 Variable.AddParam(L"VARIABLEUNITSID", itr->second.UnitsID);
	   if (itr->second.ContextID > -1)
		 Variable.AddParam(L"VARIABLECONTEXTID", itr->second.ContextID);
	   StatusBar1->SimpleText = Variable.WebServiceName();
	   if (Variable.Execute()) {
		 if (Variable.Size() == 1) {
		   itr->second.VariableID = Variable.Items[0].VariableID;
		   msg = L"Variable validated: VariableID = " + IntToStr(itr->second.VariableID) +
				 ", «" + itr->second.TaxonName + L"», TaxonID = " + IntToStr(Variable.Items[0].TaxonID);
		   if (itr->second.ElementID > -1)
			 msg += (L", ElementID = " + IntToStr(Variable.Items[0].VariableElementID));
		   if (itr->second.UnitsID > -1)
			 msg += (L", UnitsID = " + IntToStr(Variable.Items[0].VariableUnitsID));
		   if (itr->second.ContextID > -1)
			 msg += (L", ContextID = " + IntToStr(Variable.Items[0].VariableContextID));
		   msg += L".";
		   OutputLine(msg);
		   }
		 else if (Variable.Size() > 1) { // database error: more than one variable with same components
		   OutputError(L"DATABASE ERROR: Database has multiple entries of the same variable!");
		   for (unsigned int i=0; i<Variable.Size(); i++) {
			 msg = L"   VariableID = " + IntToStr(Variable.Items[i].VariableID) +
				   L": Taxon «" + itr->second.TaxonName +
				   L"», TaxonID = " + IntToStr(Variable.Items[i].TaxonID);
			 if (itr->second.ElementID > -1)
			   msg += (L", ElementID = " + IntToStr(Variable.Items[i].VariableElementID));
			 if (itr->second.UnitsID > -1)
			   msg += (L", UnitsID = " + IntToStr(Variable.Items[i].VariableUnitsID));
			 if (itr->second.ContextID > -1)
			   msg += (L", ContextID = " + IntToStr(Variable.Items[i].VariableContextID));
			 msg += L".";
			 OutputError(msg);
			 }
		   database_errors = true;
		   }
		 else {  // new variable
		   NEWNEOTOMAVARIABLE NewVar;
		   NewVar.TempVariableID = itr->second.VariableID;
		   NewVar.TaxonName = itr->second.TaxonName;
		   NewVar.TaxonID = itr->second.TaxonID;
		   NewVar.VariableElementID = itr->second.ElementID;
		   NewVar.VariableUnitsID = itr->second.UnitsID;
		   NewVar.VariableContextID = itr->second.ContextID;
		   // ensure that variable has not already been added--can happen with different taph types
		   bool found = false;
		   for (unsigned int i=0; i<NewVars.size(); i++) {
			 if (NewVar.TempVariableID == NewVars[i].TempVariableID &&
				 NewVar.TaxonName == NewVars[i].TaxonName &&
				 NewVar.TaxonID == NewVars[i].TaxonID &&
				 NewVar.VariableElementID == NewVars[i].VariableElementID &&
				 NewVar.VariableUnitsID == NewVars[i].VariableUnitsID &&
				 NewVar.VariableContextID == NewVars[i].VariableContextID) {
			   found = true;
			   break;
			   }
			 }
		   if (!found)
			 NewVars.push_back(NewVar);
		   }
		 }
	   else {
		 rv = false;
		 break;
		 }
	   }
	 }

   if (database_errors) {
	 msg = L"Database errors must be resolved before this dataset can be uploaded.";
	 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 rv = false;
	 }
   if (errors) {
	 msg = L"Variable errors must be resolved before this dataset can be uploaded.";
	 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 rv = false;
	 }

   if (rv && !ElementErrors && NewVars.size() > 0) {
	 vector<int> newids;
	 InsertData InsertVariable(L"InsertVariable", 4, ipsHTTPS1, ipsJSONS1, TcpClient1);
	 for (unsigned int i=0; i<NewVars.size(); i++) {
	   InsertVariable.Add(L"TAXONID", NewVars[i].TaxonID, -1);
	   InsertVariable.Add(L"VARIABLEELEMENTID", NewVars[i].VariableElementID, -1);
	   InsertVariable.Add(L"VARIABLEUNITSID", NewVars[i].VariableUnitsID, -1);
	   InsertVariable.Add(L"VARIABLECONTEXTID", NewVars[i].VariableContextID, -1);
	   }
	 StatusBar1->SimpleText = L"InsertVariable";
	 InsertVariable.PostData();
	 if (InsertVariable.Post(newids, ErrorMsg)) {
	   if (newids.size() == NewVars.size()) {
		 for (unsigned int i=0; i<newids.size(); i++) {
		   for (itr = begin; itr != end; itr++) {
			 if (itr->second.VariableID == NewVars[i].TempVariableID) {
			   itr->second.VariableID = newids[i];
			   break;
			   }
			 }
		   msg = L"New variable uploaded: VariableID = " + IntToStr(newids[i]) +
			 ", «" + NewVars[i].TaxonName + L"», TaxonID = " + IntToStr(NewVars[i].TaxonID);
		   if (NewVars[i].VariableElementID > -1)
			 msg += (L", ElementID = " + IntToStr(NewVars[i].VariableElementID));
		   if (NewVars[i].VariableUnitsID > -1)
			 msg += (L", UnitsID = " + IntToStr(NewVars[i].VariableUnitsID));
		   if (NewVars[i].VariableContextID > -1)
			 msg += (L", ContextID = " + IntToStr(NewVars[i].VariableContextID));
		   msg += L".";
		   OutputLine(msg);
		   }
		 }
	   else {
		 ErrorMsg = L"Error inserting into Variables table!";
		 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 rv = false;
		 }
	   }
	 else {
	   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   rv = false;
	   }
	 }

   if (rv) {
	 OutputLine(L"Variables validated.");
	 SetProgressBarPosition();
	 }
   StatusBar1->SimpleText = L"";
   Screen->Cursor = crDefault;
   return rv;
}
//---------------------------------------------------------------------------

// TODO: Then write code for validating taphonomy

bool TNeotomaUploadForm::ValidateUnits(map<UnicodeString,set<int> >& SSUnitTypes)
{
   map<int,NEOTOMAVARIABLE>::iterator itr;
   map<UnicodeString,set<int> >::iterator mitr;
   set<int>::iterator sitr;
   UnicodeString ErrorMsg;

   for (mitr = SSUnitTypes.begin(); mitr != SSUnitTypes.end(); mitr++) {
	 // check that units exist
	 int VariableUnitsID;
	 UnicodeString Units = mitr->first;
	 NeotomaVariableUnitsID GetVariableUnitsID(ipsJSONS1, TcpClient1);
	 GetVariableUnitsID.AddParam(L"VARIABLEUNITS", Units);
	 StatusBar1->SimpleText = GetVariableUnitsID.WebServiceName();
	 if (GetVariableUnitsID.Execute()) {
	   if (GetVariableUnitsID.Size() == 1) {  // Units exist in Neotoma
		 VariableUnitsID = GetVariableUnitsID.Items[0];
		 // check if DatasetTypeID, VariableUnitsID pair exists in UnitsDatasetTypes table
		 for (sitr = mitr->second.begin(); sitr != mitr->second.end(); sitr++) {
		   int DatasetTypeID = *sitr;
		   NeotomaUnitsDatasetTypeCount UnitsDatasetTypeCount(ipsJSONS1, TcpClient1);
		   UnitsDatasetTypeCount.AddParam(L"DATASETTYPEID", DatasetTypeID);
		   UnitsDatasetTypeCount.AddParam(L"VARIABLEUNITSID", VariableUnitsID);
		   StatusBar1->SimpleText = UnitsDatasetTypeCount.WebServiceName();
		   if (UnitsDatasetTypeCount.Execute()) {
			 if (UnitsDatasetTypeCount.Size() == 1) {
			   if (UnitsDatasetTypeCount.Items[0] == 0) { // DatasetTypeID, VariableUnitsID combo does not exist
				 if (!UploadUnitsDatasetType(Units, VariableUnitsID, DatasetTypeID))
				   return false;
				 }
			   }
			 }
		   else
			 return false;
		   }
		 }
	   else {  // Units don't exist in Neotoma
		 vector<UnicodeString> TaxaList;
		 for (itr = NeotomaVariables.begin(); itr != NeotomaVariables.end(); itr++) {
		   int row = itr->first;
		   UnicodeString SSUnits = VarToStr(TSSForm->ProfGrid1->AbsoluteCells[4][row]->Value);
		   if (SSUnits == Units)
			 TaxaList.push_back(itr->second.TaxonName);
		   }
		 TConfirmUnitsUploadForm *ConfirmUnitsUploadForm = new TConfirmUnitsUploadForm(Units, TaxaList, this);
		 Screen->Cursor = crDefault;
		 int rv = ConfirmUnitsUploadForm->ShowModal();
		 delete ConfirmUnitsUploadForm;
		 if (rv != mrOk) {
		   OutputError(L"ERROR: Variable units «" + Units + L"» not validated.");
		   return (rv == mrCancel);  // true if cancel, false if abort
		   }
		 Screen->Cursor = crHourGlass;
		 // upload new variable units
		 vector<int> newids;
		 InsertData InsertUnits(L"InsertVariableUnits", 1, ipsHTTPS1, ipsJSONS1, TcpClient1);
		 InsertUnits.Add(L"UNITS", Units);
		 StatusBar1->SimpleText = L"InsertVariableUnits";
		 InsertUnits.PostData();
		 if (InsertUnits.Post(newids, ErrorMsg)) {
		   if (newids.size() == 1) {
			 VariableUnitsID = newids[0];
			 OutputLine(L"New variable units uploaded: " + Units + L", ID = " + IntToStr(newids[0]));
			 }
		   else {
			 ErrorMsg = L"Error inserting into VariableUnits table!";
			 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			 return false;
			 }
		   }
		 else {
		   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   return false;
		   }

		 // insert DatasetTypeID, VariableUnitsID into UnitsDatasetTypes table
		 for (sitr = mitr->second.begin(); sitr != mitr->second.end(); sitr++) {
           int DatasetTypeID = *sitr;
		   if (!UploadUnitsDatasetType(Units, VariableUnitsID, DatasetTypeID))
			 return false;
		   }
		 }
	   // set NeotomaVariable UnitsID
	   for (itr = NeotomaVariables.begin(); itr != NeotomaVariables.end(); itr++) {
		 int row = itr->first;
		 UnicodeString SSUnits = VarToStr(TSSForm->ProfGrid1->AbsoluteCells[4][row]->Value);
		 if (SSUnits == Units)
		   itr->second.UnitsID = VariableUnitsID;
		 }
	   }
	 else
	   return false;
	 }

   OutputLine(L"Variable units validated.");
   SetProgressBarPosition();
   return true;
}
//---------------------------------------------------------------------------

bool TNeotomaUploadForm::UploadUnitsDatasetType(UnicodeString Units, int VariableUnitsID, int DatasetTypeID)
{
   vector<UnicodeString> DatasetTypes;
   UnicodeString ErrorMsg;

   UnicodeString DatasetType = NeotomaDatasetTypes[DatasetTypeID];
   DatasetTypes.push_back(DatasetType);
   InsertData InsertUnitsDatasetType(L"InsertUnitsDatasetTypes", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
   InsertUnitsDatasetType.Add(L"DATASETTYPEID", DatasetTypeID, -1);
   InsertUnitsDatasetType.Add(L"VARIABLEUNITSID", VariableUnitsID, -1);
   if (FindSimilarDatasetType(DatasetType, DatasetTypeID)) {
	 InsertUnitsDatasetType.Add(L"DATASETTYPEID", DatasetTypeID, -1);
	 InsertUnitsDatasetType.Add(L"VARIABLEUNITSID", VariableUnitsID, -1);
	 DatasetTypes.push_back(DatasetType);
	 }
   StatusBar1->SimpleText = L"InsertUnitsDatasetTypes";
   InsertUnitsDatasetType.PostData();
   if (InsertUnitsDatasetType.Post(ErrorMsg)) {
	 for (unsigned int i=0; i<DatasetTypes.size(); i++)
	   OutputLine(L"Variable units «" + Units + L"» assigned to Dataset Type «" + DatasetTypes[i] + L"»");
	 }
   else {
	 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 return false;
	 }
   return true;
}
//---------------------------------------------------------------------------

bool TNeotomaUploadForm::ValidateContexts(map<UnicodeString,set<int> >& SSContextTypes)
{
   map<int,NEOTOMAVARIABLE>::iterator itr;
   map<UnicodeString,set<int> >::iterator mitr;
   set<int>::iterator sitr;
   UnicodeString ErrorMsg;

   for (mitr = SSContextTypes.begin(); mitr != SSContextTypes.end(); mitr++) {
	 // check that contexts exist
	 int VariableContextID;
	 UnicodeString Context = mitr->first;
	 NeotomaVariableContextID GetVariableContextID(ipsJSONS1, TcpClient1);
	 GetVariableContextID.AddParam(L"VARIABLECONTEXT", Context);
	 StatusBar1->SimpleText = GetVariableContextID.WebServiceName();
	 if (GetVariableContextID.Execute()) {
	   if (GetVariableContextID.Size() == 1) {  // Context exists in Neotoma
		 VariableContextID = GetVariableContextID.Items[0];
		 // check if DatasetTypeID, VariableContextID pair exists in ContextsDatasetTypes table
		 for (sitr = mitr->second.begin(); sitr != mitr->second.end(); sitr++) {
		   int DatasetTypeID = *sitr;
		   NeotomaContextDatasetTypeCount ContextDatasetTypeCount(ipsJSONS1, TcpClient1);
		   ContextDatasetTypeCount.AddParam(L"DATASETTYPEID", DatasetTypeID);
		   ContextDatasetTypeCount.AddParam(L"VARIABLECONTEXTID", VariableContextID);
		   StatusBar1->SimpleText = ContextDatasetTypeCount.WebServiceName();
		   if (ContextDatasetTypeCount.Execute()) {
			 if (ContextDatasetTypeCount.Size() == 1) {
			   if (ContextDatasetTypeCount.Items[0] == 0) { // DatasetTypeID, VariableContextID combo does not exist
				 if (!UploadContextDatasetType(Context, VariableContextID, DatasetTypeID))
				   return false;
				 }
			   }
			 }
		   else
			 return false;
		   }
		 }
	   else {  // Context doesn't exist in Neotoma
		 vector<UnicodeString> TaxaList;
		 for (itr = NeotomaVariables.begin(); itr != NeotomaVariables.end(); itr++) {
		   int row = itr->first;
		   UnicodeString SSContext = VarToStr(TSSForm->ProfGrid1->AbsoluteCells[5][row]->Value);
		   if (SSContext == Context)
			 TaxaList.push_back(itr->second.TaxonName);
		   }
		 TConfirmContextUploadForm *ConfirmContextUploadForm = new TConfirmContextUploadForm(Context, TaxaList, this);
		 Screen->Cursor = crDefault;
		 int rv = ConfirmContextUploadForm->ShowModal();
		 delete ConfirmContextUploadForm;
		 if (rv != mrOk) {
		   OutputError(L"ERROR: Variable context «" + Context + L"» not validated.");
		   return (rv == mrCancel);  // true if cancel, false if abort
		   }
		 Screen->Cursor = crHourGlass;
		 // upload new variable context
		 vector<int> newids;
		 InsertData InsertContext(L"InsertVariableContext", 1, ipsHTTPS1, ipsJSONS1, TcpClient1);
		 InsertContext.Add(L"CONTEXT", Context);
		 StatusBar1->SimpleText = L"InsertVariableContext";
		 InsertContext.PostData();
		 if (InsertContext.Post(newids, ErrorMsg)) {
		   if (newids.size() == 1) {
			 VariableContextID = newids[0];
			 OutputLine(L"New variable context uploaded: " + Context + L", ID = " + IntToStr(newids[0]));
			 }
		   else {
			 ErrorMsg = L"Error inserting into VariableContexts table!";
			 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			 return false;
			 }
		   }
		 else {
		   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   return false;
		   }

		 // insert DatasetTypeID, VariableContextID into ContextsDatasetTypes table
		 for (sitr = mitr->second.begin(); sitr != mitr->second.end(); sitr++) {
		   int DatasetTypeID = *sitr;
		   if (!UploadContextDatasetType(Context, VariableContextID, DatasetTypeID))
			 return false;
		   }
		 }
	   // set NeotomaVariable ContextID
	   for (itr = NeotomaVariables.begin(); itr != NeotomaVariables.end(); itr++) {
		 int row = itr->first;
		 UnicodeString SSContext = VarToStr(TSSForm->ProfGrid1->AbsoluteCells[5][row]->Value);
		 if (SSContext == Context)
		   itr->second.ContextID = VariableContextID;
		 }
	   }
	 else
	   return false;
	 }

   OutputLine(L"Variable contexts validated.");
   SetProgressBarPosition();
   return true;
}
//---------------------------------------------------------------------------

bool TNeotomaUploadForm::UploadContextDatasetType(UnicodeString Context, int VariableContextID, int DatasetTypeID)
{
   vector<UnicodeString> DatasetTypes;
   UnicodeString ErrorMsg;

   UnicodeString DatasetType = NeotomaDatasetTypes[DatasetTypeID];
   DatasetTypes.push_back(DatasetType);
   InsertData InsertContextDatasetTypes(L"InsertContextDatasetTypes", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
   InsertContextDatasetTypes.Add(L"DATASETTYPEID", DatasetTypeID, -1);
   InsertContextDatasetTypes.Add(L"VARIABLECONTEXTID", VariableContextID, -1);
   if (FindSimilarDatasetType(DatasetType, DatasetTypeID)) {
	 InsertContextDatasetTypes.Add(L"DATASETTYPEID", DatasetTypeID, -1);
	 InsertContextDatasetTypes.Add(L"VARIABLECONTEXTID", VariableContextID, -1);
	 DatasetTypes.push_back(DatasetType);
	 }
   StatusBar1->SimpleText = L"InsertContextDatasetTypes";
   InsertContextDatasetTypes.PostData();
   if (InsertContextDatasetTypes.Post(ErrorMsg)) {
	 for (unsigned int i=0; i<DatasetTypes.size(); i++)
	   OutputLine(L"Variable context «" + Context + L"» assigned to Dataset Type «" + DatasetTypes[i] + L"»");
	 }
   else {
	 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 return false;
	 }
   return true;
}
//---------------------------------------------------------------------------

bool TNeotomaUploadForm::FindSimilarDatasetType(UnicodeString& dataset_type, int& DatasetTypeID)
{
   bool rv = false;
   map<int,UnicodeString>::iterator ditr;
   UnicodeString DatasetType = dataset_type;

   if (ContainsText(DatasetType, L"surface sample")) {  // input type is surface sample
	 DatasetType = DatasetType.LowerCase();
	 int pos = DatasetType.Pos(L"surface sample");
	 DatasetType = DatasetType.SubString(1,pos-1).TrimRight();
	 for (ditr = NeotomaDatasetTypes.begin(); ditr != NeotomaDatasetTypes.end(); ditr++) {
	   if (SameText(ditr->second, DatasetType)) {
		 DatasetTypeID = ditr->first;
		 dataset_type = DatasetType;
		 rv = true;
		 break;
		 }
	   }
	 }
   else {   // input type is not surface sample
	 for (ditr = NeotomaDatasetTypes.begin(); ditr != NeotomaDatasetTypes.end(); ditr++) {
	   if (ContainsText(ditr->second, DatasetType) && ContainsText(ditr->second, L"surface sample")) {
		 DatasetTypeID = ditr->first;
		 dataset_type = ditr->second;
		 rv = true;
		 break;
		 }
	   }
	 }
   return rv;
}
//---------------------------------------------------------------------------

bool TNeotomaUploadForm::ValidateElements(map<UnicodeString,SSELEMENT>& SSElements,
	multimap<UnicodeString,int>& SSElementRows)
{
   bool rv = true;
   set<UnicodeString>::iterator sitr;
   map<int,NEOTOMAVARIABLE>::iterator itr;
   map<int,NEOTOMAVARIABLE>::iterator begin = NeotomaVariables.begin();
   map<int,NEOTOMAVARIABLE>::iterator end = NeotomaVariables.end();

   // first pass: get exact matches
   map<UnicodeString,SSELEMENT>::iterator eitr;
   for (eitr = SSElements.begin(); eitr != SSElements.end(); eitr++) {
	 UnicodeString element = eitr->second.Element;

	 NeotomaGetVariableElementByName VarElement(ipsJSONS1, TcpClient1);
	 VarElement.AddParam(L"VARIABLEELEMENT", element);
	 StatusBar1->SimpleText = VarElement.WebServiceName();
	 if (VarElement.Execute()) {
	   if (VarElement.Size() == 1) {
		 eitr->second.VariableElementID = VarElement.Items[0].VariableElementID;
		 eitr->second.ElementTypeID = VarElement.Items[0].ElementTypeID;
		 eitr->second.SymmetryID = VarElement.Items[0].SymmetryID;
		 eitr->second.PortionID = VarElement.Items[0].PortionID;
		 eitr->second.MaturityID = VarElement.Items[0].MaturityID;
		 }
	   }
	 else {
	   Screen->Cursor = crDefault;
	   return(false);
	   }
	 }

   // second pass: see if element contains a valid ElementType,
   // if so, set ElementTypeID and parse remaining part of element
   // string into its semicolon-delimited parts
   map<UnicodeString,NEOTOMAELEMENTPARTIDS> ElementParts;
   for (eitr = SSElements.begin(); eitr != SSElements.end(); eitr++) {
	 if (!eitr->second.Element.IsEmpty()) {
	   if (eitr->second.VariableElementID == -1) {
		 // parse ElementType from Element string
		 NeotomaElementTypeFromVariableElement ElementType(ipsJSONS1, TcpClient1);
		 ElementType.AddParam(L"VARIABLEELEMENT", eitr->second.Element);
		 StatusBar1->SimpleText = ElementType.WebServiceName();
		 if (ElementType.Execute()) {
		   if (ElementType.Size() == 1) {
			 eitr->second.ElementTypeID = ElementType.Items.begin()->first;
			 UnicodeString element = eitr->second.Element;
			 UnicodeString element_type = ElementType.Items.begin()->second;
			 element.Delete(1,element_type.Length()+1);
			 element = element.TrimLeft();
			 eitr->second.ParseParts(element);
			 for (sitr = eitr->second.parts.begin(); sitr != eitr->second.parts.end(); sitr++) {
			   if (ElementParts.count(*sitr) == 0) {
				 NEOTOMAELEMENTPARTIDS part;
				 part.SymmetryID = -1;
				 part.PortionID = -1;
				 part.MaturityID = -1;
				 ElementParts[*sitr] = part;
				 }
			   }
			 }
		   else { // ElementType not found
			 UnicodeString element = eitr->second.Element;
			 if (!element.IsEmpty()) {
			   if (ParseNewElement(element, &eitr->second, SSElementRows)) {
				 if (element != eitr->second.Element)
				   eitr->second.Element = element;
				 }
			   else
				 return false;
			   }
			 }
		   }
		 else {
		   Screen->Cursor = crDefault;
		   return false;
		   }
		 }
	   }
	 }

   // third pass: parse symmetry, portion, and maturity parts already in Neotoma
   map<UnicodeString,NEOTOMAELEMENTPARTIDS>::iterator pitr;
   for (pitr = ElementParts.begin(); pitr != ElementParts.end(); pitr++) {
	 UnicodeString PartName = pitr->first;
	 NeotomaGetElementPartID ElementPart(ipsJSONS1, TcpClient1);
	 ElementPart.AddParam(L"PARTNAME", PartName);
	 StatusBar1->SimpleText = ElementPart.WebServiceName();
	 if (ElementPart.Execute()) {
	   if (ElementPart.Size() == 1) {
		 pitr->second.SymmetryID = ElementPart.Items[0].SymmetryID;
		 pitr->second.PortionID = ElementPart.Items[0].PortionID;
		 pitr->second.MaturityID = ElementPart.Items[0].MaturityID;
		 }
	   }
	 else {
	   Screen->Cursor = crDefault;
	   return(false);
	   }
	 }

   // fourth pass: iterate through SSElements, and for all SSElements with
   // VariableElemntID unassigned, assign the part ID from ElementParts.
   for (eitr = SSElements.begin(); eitr != SSElements.end(); eitr++) {
	 if (!eitr->second.Element.IsEmpty()) {
	   if (eitr->second.VariableElementID == -1) {
		 set<UnicodeString> parts = eitr->second.parts;
		 for (sitr = parts.begin(); sitr != parts.end(); sitr++) {
		   UnicodeString PartName = *sitr;
		   if (ElementParts[PartName].SymmetryID > -1) {
			 eitr->second.SymmetryID = ElementParts[PartName].SymmetryID;
			 eitr->second.parts.erase(PartName);
			 }
		   else if (ElementParts[PartName].PortionID > -1) {
			 eitr->second.PortionID = ElementParts[PartName].PortionID;
			 eitr->second.parts.erase(PartName);
			 }
		   else if (ElementParts[PartName].MaturityID > -1) {
			 eitr->second.MaturityID = ElementParts[PartName].MaturityID;
			 eitr->second.parts.erase(PartName);
			 }
		   }

		 // If all parts are accounted for, set the VariableElementID.
		 // Otherwise, upload any new parts, then set the VariableElementID
		 if (eitr->second.parts.size() == 0) {
		   rv = SetVariableElementID(eitr->first, eitr->second, SSElementRows);
		   }
		 else {  // all parts not found
		   UnicodeString element = eitr->second.Element;
		   if (ParseNewElement(element, &eitr->second, SSElementRows)) {
			 if (element != eitr->second.Element)
			   eitr->second.Element = element;
			 rv = SetVariableElementID(eitr->first, eitr->second, SSElementRows);
			 }
		   else
			 rv = false;
		   }
		 }
	   }
     if (!rv) {
	   Screen->Cursor = crDefault;
	   return false;
	   }
	 }

   // assign VariableElementID's to NeotomaVariables
   for (eitr = SSElements.begin(); eitr != SSElements.end(); eitr++) {
	 UnicodeString ElementKey = eitr->first;
	 int VariableElementID = eitr->second.VariableElementID;
	 multimap<UnicodeString,int>::iterator mitr;
	 pair<multimap<UnicodeString,int>::iterator, multimap<UnicodeString,int>::iterator> range;
	 range = SSElementRows.equal_range(ElementKey);
	 for (mitr = range.first; mitr != range.second; mitr++) {
	   int row = mitr->second;
	   NeotomaVariables[row].ElementID = VariableElementID;
	   }
	 }

   // update element changes in spreadsheet
   for (eitr = SSElements.begin(); eitr != SSElements.end(); eitr++) {
	 if (eitr->first != eitr->second.Element) {
	   for (itr = begin; itr != end; itr++) {
		 int row = itr->first;
		 UnicodeString element = VarToStr(TSSForm->ProfGrid1->AbsoluteCells[3][row]->Value);
		 if (element == eitr->first) {
		   TSSForm->ProfGrid1->AbsoluteCells[3][row]->Value = eitr->second.Element;
		   OutputLine(L"Variable element «" + eitr->first + L"» changed to «" +
			 eitr->second.Element + L"» in row " + IntToStr(row));
		   }
		 }
	   }
	 }

   // go through NeotomaVariables and make sure all ElementID's are assigned
   bool all_found = true;
   for (itr = begin; itr != end; itr++) {
	 if (!itr->second.Element.IsEmpty() && itr->second.ElementID == -1) {
	   OutputError(L"ERROR: Variable element not set for Taxon «" + itr->second.TaxonName +
		 L"» in row " + IntToStr(itr->first));
	   all_found = false;
	   }
	 }

   // check for pollen/spore element validity
   // vector<pair<int,int> > psrows;  // row, ElementID
   map<int,pair<int,int> > ps;  // row, TaxonID, ElementID
   UnicodeString TaxaIDList;
   for (itr = begin; itr != end; itr++) {
	 int ElementID = itr->second.ElementID;
	 int TaxonID = itr->second.TaxonID;
	 if (ElementID == 141 || ElementID == 166) {  // pollen or spore element
	   if (!TaxaIDList.IsEmpty())
		 TaxaIDList += L"$";
	   TaxaIDList += IntToStr(TaxonID);
	   //psrows.push_back(pair<int,int>(itr->first,ElementID));
	   ps[itr->first] = pair<int,int>(TaxonID,ElementID);
	   }
	 }

   NeotomaGetPollenSporeHigherTaxa PollenSpore(ipsJSONS1, TcpClient1);
   PollenSpore.AddParam(L"TAXAIDLIST", TaxaIDList);
   StatusBar1->SimpleText = PollenSpore.WebServiceName();
   if (!PollenSpore.Execute()) {
	 Screen->Cursor = crDefault;
	 return(false);
	 }
   /*
   for (unsigned int i=0; i<PollenSpore.Size(); i++) {
	 if (psrows[i].second == 141 && PollenSpore.Items[i].second != 5480) {   // pollen not in Spermatophyta
	   OutputError(L"ERROR: Taxon not in the Spermatophyta in row " + IntToStr(psrows[i].first) +
		 L" is assigned pollen element." );
	   ElementErrors = true;
	   }
	 else if (psrows[i].second == 166 && PollenSpore.Items[i].second == 5480) {  // spore assigned to Spermatophyta
	   OutputError(L"ERROR: Taxon in the Spermatophyta in row " + IntToStr(psrows[i].first) +
		 L" is assigned spore element." );
	   ElementErrors = true;
	   }
	 }
   */

   map<int,pair<int,int> >::iterator psitr;
   for (psitr = ps.begin(); psitr != ps.end(); psitr++) {
	 if (psitr->second.second == 141 && PollenSpore.Items[psitr->second.first] != 5480) {   // pollen not in Spermatophyta
	   OutputError(L"ERROR: Taxon not in the Spermatophyta in row " + IntToStr(psitr->first) +
		 L" is assigned pollen element." );
	   ElementErrors = true;
	   }
	 else if (psitr->second.second == 166 && PollenSpore.Items[psitr->second.first] == 5480) {  // spore assigned to Spermatophyta
	   OutputError(L"ERROR: Taxon in the Spermatophyta in row " + IntToStr(psitr->first) +
		 L" is assigned spore element." );
	   ElementErrors = true;
	   }
	 }

   Screen->Cursor = crDefault;
   if (all_found && !ElementErrors)
	 OutputLine(L"Variable element types validated.");
   else if (MessageDlg(L"Errors in variable elements!", Dialogs::mtError,
	 TMsgDlgButtons() << mbIgnore << mbAbort, 0) == mrAbort)
	   return false;

   SetProgressBarPosition();
   return true;
}
//---------------------------------------------------------------------------

bool TNeotomaUploadForm::ParseNewElement(UnicodeString& NewElement,
	SSELEMENT* sselement, multimap<UnicodeString,int>& SSElementRows)
{
   map<UnicodeString,int> TaxaNames;  // TaxonName, TaxonID

   // get taxa names with this element
   multimap<UnicodeString,int>::iterator mitr;
   pair<multimap<UnicodeString,int>::iterator, multimap<UnicodeString,int>::iterator> range;
   range = SSElementRows.equal_range(NewElement);
   for (mitr = range.first; mitr != range.second; mitr++) {
	 int row = mitr->second;
	 TaxaNames[NeotomaVariables[row].TaxonName] = NeotomaVariables[row].TaxonID;
	 }

   NewElementsForm = new TNewElementsForm(NewElement, sselement, &TaxaNames,
						 &NeotomaVariables, &NeotomaDatasetTypes, this);

   // TODO: get return value and bail if necessary
   int rv = NewElementsForm->ShowModal();
   if (rv == mrOk)
	 NewElement = NewElementsForm->GetNewElement();
   for (unsigned int i=0; i<NewElementsForm->OutputLines.size(); i++)
	 OutputLine(NewElementsForm->OutputLines[i]);
   delete NewElementsForm;
   return (rv != mrAbort);
}
//---------------------------------------------------------------------------

bool TNeotomaUploadForm::SetVariableElementID(UnicodeString ElementKey, SSELEMENT& sselement,
	multimap<UnicodeString,int>& SSElementRows)
{
   bool rv = true;
   NeotomaVariableElementByPartIDs VarElement(ipsJSONS1, TcpClient1);
   VarElement.AddParam(L"ELEMENTTYPEID", sselement.ElementTypeID);
   VarElement.AddParam(L"SYMMETRYID", sselement.SymmetryID);
   VarElement.AddParam(L"PORTIONID", sselement.PortionID);
   VarElement.AddParam(L"MATURITYID", sselement.MaturityID);
   StatusBar1->SimpleText = VarElement.WebServiceName();
   if (VarElement.Execute()) {
	 if (VarElement.Size() > 0)
	   sselement.VariableElementID = VarElement.Items[0];
	 else if (!UploadNewElementCombination(ElementKey, sselement, SSElementRows))
	   rv = false;
	 }
   else
	 rv = false;
   return rv;
}
//---------------------------------------------------------------------------

bool TNeotomaUploadForm::UploadNewElementCombination(UnicodeString ElementKey, SSELEMENT& sselement,
	multimap<UnicodeString,int>& SSElementRows)
{
   vector<int> newids;
   UnicodeString ErrorMsg;

   if (sselement.ElementTypeID == -1)    // this should never happen, but...
	 return true;

   // get list of taxa with this element
   vector<UnicodeString> TaxaNames;
   multimap<UnicodeString,int>::iterator mitr;
   pair<multimap<UnicodeString,int>::iterator, multimap<UnicodeString,int>::iterator> range;
   range = SSElementRows.equal_range(ElementKey);
   for (mitr = range.first; mitr != range.second; mitr++) {
	 int row = mitr->second;
	 //TaxaNames.push_back(NeotomaTaxonIDs[row].TaxonName);
	 TaxaNames.push_back(NeotomaVariables[row].TaxonName);
	 }
   ConfirmElementUploadForm = new TConfirmElementUploadForm(sselement.Element, TaxaNames, this);
   Screen->Cursor = crDefault;
   int rv = ConfirmElementUploadForm->ShowModal();
   if (rv != mrOk) {
	 OutputError(L"ERROR: Variable element «" + sselement.Element + L"» not validated.");
	 return (rv == mrCancel);  // true if cancel, false if abort
	 }

   // upload new variable element
   InsertData InsertVariableElement(L"InsertVariableElement", 5, ipsHTTPS1, ipsJSONS1, TcpClient1);
   InsertVariableElement.Add(L"VARIABLEELEMENT", sselement.Element);
   InsertVariableElement.Add(L"ELEMENTTYPEID", sselement.ElementTypeID, -1);
   InsertVariableElement.Add(L"SYMMETRYID", sselement.SymmetryID, -1);
   InsertVariableElement.Add(L"PORTIONID", sselement.PortionID, -1);
   InsertVariableElement.Add(L"MATURITYID", sselement.MaturityID, -1);
   StatusBar1->SimpleText = L"InsertVariableElement";
   InsertVariableElement.PostData();
   if (InsertVariableElement.Post(newids, ErrorMsg)) {
	 if (newids.size() == 1) {
	   sselement.VariableElementID = newids[0];
	   OutputLine(L"New variable element uploaded: " + sselement.Element + L", ID = " + IntToStr(newids[0]));
	   }
	 else {
	   ErrorMsg = L"Error inserting into VariableElements table!";
	   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return false;
	   }
	 }
   else {
	 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 return false;
	 }

   return true;
}
//---------------------------------------------------------------------------

bool TNeotomaUploadForm::ValidateTaxa(void)
{
   if (TaxaSet.size() == 0) return false;

   Check_cfs();

   NeotomaTaxaByNameList Taxa(ipsJSONS1, TcpClient1);
   NeotomaTaxaByNameList Synonyms(ipsJSONS1, TcpClient1);
   if (LoadNeotomaTaxa(Taxa, Synonyms, true) != mrOk)
	 return false;
   if (CheckTaxaNames(Taxa) == mrAbort)
	 return false;
   if (CheckSynonyms(Taxa, Synonyms) == mrAbort)
	 return false;
   bool NewSynonyms;
   if (ResolveRemainingTaxaNotFound(NewSynonyms) == mrAbort)
	 return false;
   if (NewSynonyms) {
	 Screen->Cursor = crHourGlass;
	 NeotomaTaxaByNameList Taxa1(ipsJSONS1, TcpClient1);
	 NeotomaTaxaByNameList Synonyms1(ipsJSONS1, TcpClient1);
	 if (LoadNeotomaTaxa(Taxa1, Synonyms1, false) != mrOk)
	   return false;
	 if (CheckSynonyms(Taxa1, Synonyms1) == mrAbort)
	   return false;
	 }
   return true;
}
//---------------------------------------------------------------------------

void TNeotomaUploadForm::Check_cfs(void)
{
   UnicodeString msg;

   map<int,UnicodeString> DatasetRows;
   DatasetRows[3] = TSSForm->ProfGrid1->AbsoluteCells[1][1]->Text;
   UnicodeString DatasetType = DatasetRows[3];

   // get dataset types for rows to avoid checking for diatoms
   int nrows = TSSForm->AbsContentRowCount(TSSForm->ProfGrid1);
   int start = TSSForm->AbsHeaderRowCount(TSSForm->ProfGrid1);
   for (int row=start; row<=nrows; row++) {
	 UnicodeString VarCode = TSSForm->ProfGrid1->AbsoluteCells[1][row]->Text;
	 if (SameText(VarCode, L"#Data.Type")) {
	   DatasetRows[row] = TSSForm->ProfGrid1->AbsoluteCells[2][row]->Text;
	   DatasetType = DatasetRows[row];
	   }
	 else
	   DatasetRows[row] = DatasetType;
	 }

   for (unsigned int i=0; i<SSVarList.size(); i++) {
	 if (ContainsText(DatasetRows[SSVarList[i].row], L"diatom"))
	   continue;
	 UnicodeString NewName;
	 if (check_cf(SSVarList[i].name, NewName)) {
	   // make cf. format change
	   msg = L"Taxon name «" + SSVarList[i].name + L"» changed to «" + NewName + L"»";
	   OutputLine(msg);
	   SSVarList[i].name = NewName;
	   TSSForm->ProfGrid1->AbsoluteCells[2][SSVarList[i].row]->Value = NewName;
	   }
	 else if (SSVarList[i].name != NewName) {
	   msg = L"Taxon name in the form «Genus cf. species» will not match with a Neotoma taxon name!";
	   MessageDlg(msg, mtWarning, TMsgDlgButtons() << mbOK, 0);
	   msg = L"ERROR: Taxon name «" + SSVarList[i].name +
			 L"» is not in the proper Neotoma format of «Genus cf. G. species».";
	   OutputError(msg);
	   }
	 }
   SetProgressBarPosition();
}
//---------------------------------------------------------------------------

void TNeotomaUploadForm::ResetControlButtons(bool control)
{
   cxButton2->Visible = control;
   cxButton3->Visible = control;
   cxButton1->Visible = control;
   cxButton4->Visible = control;
}
//---------------------------------------------------------------------------

bool TNeotomaUploadForm::InitialValidation(void)
{
   SetProgressBar(CORE);
   UnicodeString msg;

   if (TSSForm->Sites->Count > 1) {
	 // ensure only a single collection unit per site
	 for (int i=0; i<TSSForm->Sites->Count; i++) {
	   site_ptr = (SITE*)TSSForm->Sites->Items[0];
	   if (site_ptr->CollUnits.size() > 1) {
		 msg = L"Multisite uploads may not have more than one collection unit per site.";
		 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 OutputError(L"ERROR: " + msg);
		 return false;
		 }
	   }

	 // ensure there is only one analysis unit per collection unit
	 int HandleRow = TSSForm->FindRowCodeIC(L"#Coll.Handle", TSSForm->ProfGrid1, 3);
	 if (HandleRow == 0) {
	   msg = L"Collecton unit Handle metadata row not in spreadsheet.";
	   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   OutputError(L"ERROR: " + msg);
	   return false;
	   }
	 set<UnicodeString> Handles;
	 int start = TSSForm->AbsHeaderColCount(TSSForm->ProfGrid1);
	 int ncols = TSSForm->AbsContentColCount(TSSForm->ProfGrid1);
	 for (int col=start; col<=ncols; col++) {
	   UnicodeString Handle = TSSForm->ProfGrid1->AbsoluteCells[col][HandleRow]->Text;
	   if (Handle.IsEmpty()) {
		 msg = L"Handle in column " + TSSForm->ProfGrid1->AbsoluteCols[col]->A1Name + L" is empty.";
		 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 OutputError(L"ERROR: " + msg);
		 return false;
		 }
	   Handle = Handle.LowerCase();
	   if (Handles.count(Handle) == 0)
		 Handles.insert(Handle);
	   else {
		 msg = L"Handle «" + Handle +
		   L"» occurs more than once. Multisite uploads may have only one analysis unit per collection unit.";
         MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 OutputError(L"ERROR: " + msg);
		 return false;
		 }
	   }
	 }

   if (TSSForm->Sites->Count > 1)
	 MultiSiteUpload = true;
   else
	 site_ptr = (SITE*)TSSForm->Sites->Items[0];

   if (!GetNeotomaDatasetTypes())
	 return false;

   SetProgressBarPosition();
   return true;
}
//---------------------------------------------------------------------------

bool TNeotomaUploadForm::GetNeotomaDatasetTypes(void)
{
   int success = true;

   Screen->Cursor = crHourGlass;
   NeotomaDatasetTypesTable DatasetTypes(ipsJSONS1, TcpClient1);
   StatusBar1->SimpleText = DatasetTypes.WebServiceName();
   if (DatasetTypes.Execute()) {
	 map<int,UnicodeString>::iterator begin = DatasetTypes.Items.begin();
	 map<int,UnicodeString>::iterator end = DatasetTypes.Items.end();
	 NeotomaDatasetTypes.insert(begin, end);

	 // check that local DatasetTypes exist in Neotoma
	 map<int,UnicodeString>::iterator itr;
	 begin = NeotomaDatasetTypes.begin();
	 end = NeotomaDatasetTypes.end();
	 for (unsigned int i=0; i<TSSForm->Datasets.size(); i++) {
	   UnicodeString DatasetType = TSSForm->Datasets[i].DatasetType;
	   for (itr = begin; itr != end; itr++) {
		 if (SameText(itr->second, DatasetType)) {
		   TSSForm->Datasets[i].NeotomaDatasetTypeID = itr->first;
		   break;
		   }
		 }
	   if (TSSForm->Datasets[i].NeotomaDatasetTypeID == -1) {
		 UnicodeString msg = L"Dataset Type «" + DatasetType + L"» is not yet in Neotoma!";
		 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 success = false;
	     }
	   }
	 }
   else
	 success = false;
   StatusBar1->SimpleText = L"";
   Screen->Cursor = crDefault;
   return success;
}
//---------------------------------------------------------------------------

UnicodeString TNeotomaUploadForm::ValidationMsg(ValidationMessages& vmsg)
{
   UnicodeString msg;
   UnicodeString ErrorTxt = (vmsg.Errors == 1) ? L" Error, " : L" Errors, ";
   UnicodeString WarningTxt = (vmsg.Warnings == 1) ? L" Warning, " : L" Warnings, ";
   UnicodeString NoteTxt = (vmsg.Notes == 1) ? L" Note." : L" Notes.";
   msg = IntToStr(vmsg.Errors) + ErrorTxt + IntToStr(vmsg.Warnings) + WarningTxt + IntToStr(vmsg.Notes) + NoteTxt;
   return msg;
}
//---------------------------------------------------------------------------

void TNeotomaUploadForm::CheckEmptyRows(void)
{
   int nrows = TSSForm->AbsContentRowCount(TSSForm->ProfGrid1);
   vector<int> EmptyRows;
   TProfGrid* ProfGrid = TSSForm->ProfGrid1;
   for (int row=3; row<=nrows; row++) {
	 if (ProfGrid->RowIsEmpty(row))
	   EmptyRows.push_back(row);
	 }

   if (EmptyRows.size() > 0) {
	 vector<int>::reverse_iterator ritr;
	 for (ritr = EmptyRows.rbegin(); ritr != EmptyRows.rend(); ritr++)
	   ProfGrid->DeleteRow(*ritr);
	 TSSForm->SpreadSheetChanged = true;
	 UnicodeString msg = IntToStr((int)EmptyRows.size()) + L" empty row";
	 if (EmptyRows.size() > 1)
	   msg += L"s";
	 msg += L" deleted.";
	 OutputLine(msg);
	 }

   SetProgressBarPosition();
}
//---------------------------------------------------------------------------

void TNeotomaUploadForm::CheckEmptyColumns(void)
{
   int start = TSSForm->AbsHeaderColCount(TSSForm->ProfGrid1);
   int ncols = TSSForm->AbsContentColCount(TSSForm->ProfGrid1);
   vector<int> EmptyCols;
   TProfGrid* ProfGrid = TSSForm->ProfGrid1;
   for (int col=start; col<=ncols; col++) {
	 int VisCol = ProfGrid->AbsoluteCols[col]->VisibleNumber;
	 if (ProfGrid->ColumnIsEmpty(VisCol))
	   EmptyCols.push_back(col);
	 }
   if (EmptyCols.size() > 0) {
	 vector<int>::reverse_iterator ritr;
	 for (ritr = EmptyCols.rbegin(); ritr != EmptyCols.rend(); ritr++)
	   ProfGrid->DeleteAbsoluteColumn(*ritr);
	 TSSForm->SpreadSheetChanged = true;
	 UnicodeString msg = IntToStr((int)EmptyCols.size()) + L" empty column";
	 if (EmptyCols.size() > 1)
	   msg += L"s";
	 msg += L" deleted.";
	 OutputLine(msg);
	 }

   SetProgressBarPosition();
}
//---------------------------------------------------------------------------

bool TNeotomaUploadForm::CheckEmptyData(void)
{
   vector<EMPTYVAR> EmptyVars;

   int start = TSSForm->AbsHeaderColCount(TSSForm->ProfGrid1);
   int ncols = TSSForm->AbsContentColCount(TSSForm->ProfGrid1);

   TProfGrid* ProfGrid = TSSForm->ProfGrid1;
   for (unsigned int i=0; i<SSVarList.size(); i++) {
	 bool empty = true;
	 int row = SSVarList[i].row;
	 for (int col=start; col<=ncols; col++) {
	   if (!TSSForm->GridCellIsEmpty(ProfGrid->AbsoluteCells[col][row])) {
		 empty = false;
		 break;
		 }
	   }

	 if (empty) {
	   EMPTYVAR EmptyVar;
	   UnicodeString name = SSVarList[i].name;
	   if (!TSSForm->GridCellIsEmpty(ProfGrid->AbsoluteCells[3][row]))
		 name += (L":" + ProfGrid->AbsoluteCells[3][row]->Text);
	   if (!TSSForm->GridCellIsEmpty(ProfGrid->AbsoluteCells[4][row]))
		 name += (L":" + ProfGrid->AbsoluteCells[4][row]->Text);
	   if (!TSSForm->GridCellIsEmpty(ProfGrid->AbsoluteCells[5][row]))
		 name += (L":" + ProfGrid->AbsoluteCells[5][row]->Text);

	   EmptyVar.name = name;
	   EmptyVar.row = row;
	   EmptyVars.push_back(EmptyVar);
	   }
	 }

   if (EmptyVars.size() > 0) {
	 int InitRowCount = TSSForm->AbsContentRowCount(ProfGrid);
	 TCheckNoDataForm* CheckNoDataForm = new TCheckNoDataForm(TSSForm);
	 CheckNoDataForm->FillEmptyVars(EmptyVars);
	 int rv = CheckNoDataForm->ShowModal();          // also deletes empty rows
	 if (CheckNoDataForm->OutputLines.size() > 0) {
	   for (unsigned int i = 0; i<CheckNoDataForm->OutputLines.size(); i++)
		 OutputLine(CheckNoDataForm->OutputLines[i]);
	   }
	 if (CheckNoDataForm->OutputErrors.size() > 0) {
	   for (unsigned int i = 0; i<CheckNoDataForm->OutputErrors.size(); i++)
		 OutputError(CheckNoDataForm->OutputErrors[i]);
	   }
	 if (rv == mrAbort) {
	   Screen->Cursor = crDefault;
	   return false;
	   }
	 delete CheckNoDataForm;
	 int RowCount = TSSForm->AbsContentRowCount(ProfGrid);
	 if (RowCount < InitRowCount)
	   GetVariables();
	 }
   else
	 OutputLine(L"Empty data check passed.");

   SetProgressBarPosition();
   return true;
}
//---------------------------------------------------------------------------

bool TNeotomaUploadForm::ValidateAggregateChrons(void)
{
   bool rv = true;
   Screen->Cursor = crHourGlass;
   try {
	   for (unsigned int i = 0; i < AggregateDatasets.size(); i++) {
		 if (AggregateDatasets[i].ID != -1) {
		   NeotomaAggregateChronByDatasetID AggregateChrons(ipsJSONS1, TcpClient1);
		   StatusBar1->SimpleText = AggregateChrons.WebServiceName();
		   AggregateChrons.AddParam(L"AGGREGATEDATASETID", AggregateDatasets[i].ID);
		   if (AggregateChrons.Execute()) {
			 for (unsigned int j = 0; j < AggregateChrons.Size(); j++) {
			   if (SameText(AggregateChrons.Items[j].ChronologyName, AggregateChron.ChronologyName)) {
				 // AggregateChron.ChronologyID = AggregateChrons.Items[j].AggregateChronID;
				 AggregateDatasets[i].ChronID = AggregateChrons.Items[j].AggregateChronID;
				 OutputLine(L"Aggregate chronology for aggregate dataaset «" + AggregateDatasets[i].Name +
				   L"» assigned to AggregateChronID = " + IntToStr(AggregateDatasets[i].ChronID) + L".");
				 break;
				 }
			   }
			 }
		   else
			 return (rv = false);
		   }
		 }
	   }
   __finally {
	   Screen->Cursor = crDefault;
	   }
   return rv;
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaUploadForm::ipsJSONS1SSLServerAuthentication(TObject *Sender,
          TipsJSONSSSLServerAuthenticationEventParams *e)
{
   e->Accept = true;
}
//---------------------------------------------------------------------------

