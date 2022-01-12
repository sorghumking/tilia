//---------------------------------------------------------------------------

#include <vcl.h>
#include "pch.h"
#pragma hdrstop

#include "TNValid.h"
#ifndef TIUploadH
#include "TIUpload.h"
#endif
#ifndef TIChkVarH
#include "TIChkVar.h"
#endif
#ifndef TIChkVarFrmH
#include "TIChkVarFrm.h"
#endif
#ifndef TIPublH
#include "TIPubl.h"
#endif
#ifndef TIEdtModH
#include "TIEdtMod.h"
#endif
#ifndef TNUtilsH
#include "TNUtils.h"
#endif
#ifndef TIShoMemH
#include "TIShoMem.h"
#endif

//---------------------------------------------------------------------------

#pragma package(smart_init)

CONTACT* TNeotomaUploadForm::GetStewardContact(void)
{
   CONTACT *Steward = NULL;

   for (int i=0; i<TSSForm->ContactList->Count; i++) {
	 CONTACT* Contact = TSSForm->ContactList->Contacts[i];
	 if (Login->ContactID == Contact->NeotomaContactID) {
	   Steward = Contact;
	   break;
	   }
	 }
   if (Steward == NULL) {
	 NeotomaContactByID GetContact(ipsJSONS1, TcpClient1);
	 GetContact.AddParam(L"CONTACTID", Login->ContactID);
	 StatusBar1->SimpleText = GetContact.WebServiceName();
	 if (GetContact.Execute()) {
	   if (GetContact.Size() > 0) {
		 NTMCONTACT ntm_contact = GetContact.Items[0];
		 Steward = new CONTACT(ntm_contact, NeotomaContactStatuses);
		 TSSForm->ContactList->Add(Steward);
		 }
	   }
	 StatusBar1->SimpleText = L"";
	 }
   return Steward;
}
//---------------------------------------------------------------------------

vector<NEOTOMAGEOCHRON>::pointer TNeotomaUploadForm::GetNeotomaGeochron(int GeochronID)
{
  vector<NEOTOMAGEOCHRON>::pointer ptr = NULL;
  for (unsigned int i=0; i<NeotomaGeochrons.size(); i++) {
	if (GeochronID == NeotomaGeochrons[i].GeochronID) {
	  ptr = &NeotomaGeochrons[i];
	  break;
	  }
	}
  return ptr;
}
//---------------------------------------------------------------------------

UnicodeString TNeotomaUploadForm::AnalysisUnitDescript(int AnalysisUnitID)
{
   // Level IV, Depth 120, Thickness 4
   UnicodeString Descript;
   for (unsigned int i=0; i<NeotomaAnalysisUnits.size(); i++) {
	 if (AnalysisUnitID == NeotomaAnalysisUnits[i].AnalysisUnitID) {
	   if (!NeotomaAnalysisUnits[i].AnalysisUnitName.IsEmpty())
		 Descript = NeotomaAnalysisUnits[i].AnalysisUnitName;
	   if (!NeotomaAnalysisUnits[i].Depth.IsEmpty()) {
		 double depth = NeotomaAnalysisUnits[i].Depth;
		 if (!Descript.IsEmpty())
		   Descript += L", ";
		 Descript += (L"Depth " + FloatToStr(depth));
		 if (!NeotomaAnalysisUnits[i].Thickness.IsEmpty()) {
		   double thick = NeotomaAnalysisUnits[i].Thickness;
		   Descript += (L", Thickness " + FloatToStr(thick));
		   }
		 }
	   break;
	   }
	 }
   return Descript;
}
//---------------------------------------------------------------------------

double TNeotomaUploadForm::GetSiteLatitude(int AnalysisUnitID)
{
   double latitude;

   for (unsigned int j=0; j<NeotomaAnalysisUnits.size(); j++) {
	 if (AnalysisUnitID == NeotomaAnalysisUnits[j].AnalysisUnitID) {
	   int CollUnitID = NeotomaAnalysisUnits[j].CollectionUnitID;
	   for (int k=0; k<TSSForm->Sites->Count; k++) {
		 SITE* site_ptr = (SITE*)TSSForm->Sites->Items[k];
		 for (unsigned int m=0; m<site_ptr->CollUnits.size(); m++) {
		   if (CollUnitID == site_ptr->CollUnits[m].NeotomaCollUnitID) {
			 latitude = site_ptr->LatNorth;
			 return latitude;
			 }
		   }
		 }
	   }
	 }
   return latitude;
}
//---------------------------------------------------------------------------

UnicodeString TNeotomaUploadForm::GetNeotomaAgeType(int AgeTypeID)
{
   UnicodeString AgeType;
   for (unsigned int i=0; i<NeotomaAgeTypes.size(); i++) {
	 if (AgeTypeID == NeotomaAgeTypes[i].AgeTypeID) {
	   AgeType = NeotomaAgeTypes[i].AgeType;
	   break;
	   }
	 }
   return AgeType;
}
//---------------------------------------------------------------------------

int TNeotomaUploadForm::FindPairSecond(vector<pair<UnicodeString,int> >& vec, UnicodeString item)
{
   int second = -1;
   vector<pair<UnicodeString,int> >::iterator itr;
   for (itr = vec.begin(); itr != vec.end(); itr++) {
	 if (SameText(itr->first, item)) {
	   second = itr->second;
	   break;
	   }
	 }
   return second;
}
//---------------------------------------------------------------------------

bool TNeotomaUploadForm::PairFirstExists(vector<pair<UnicodeString,int> >& vec, UnicodeString item)
{
   bool exists = false;
   vector<pair<UnicodeString,int> >::iterator itr;
   for (itr = vec.begin(); itr != vec.end(); itr++) {
	 if (SameText(itr->first, item)) {
	   exists = true;
	   break;
	   }
	 }
   return exists;
}
//---------------------------------------------------------------------------

UnicodeString TNeotomaUploadForm::DateDescript(GEOCHRON* Date)
{
   UnicodeString Descript;
   if (!Date->LabNumber.IsEmpty())
	 Descript = Date->LabNumber;
   if (!Date->Age.IsEmpty()) {
	 if (!Descript.IsEmpty())
	   Descript += L": ";
	 Descript += VarToStr(Date->Age);
	 if (!Date->ErrorOlder.IsEmpty() && !Date->ErrorYounger.IsEmpty()) {
	   if (Date->ErrorOlder == Date->ErrorYounger)
		 Descript += (L"±" + VarToStr(Date->ErrorOlder));
	   else
		 Descript += (L"+" + VarToStr(Date->ErrorOlder) + L"/-" + VarToStr(Date->ErrorYounger));
	   }
	 }
   Descript.Insert(L"«",1);
   Descript += L"»";
   return Descript;
}
//---------------------------------------------------------------------------

int TNeotomaUploadForm::FindGeochronType(UnicodeString Method, map<int,UnicodeString>& GeochronTypes)
{
   map<int,UnicodeString>::iterator itr;
   for (itr = GeochronTypes.begin(); itr != GeochronTypes.end(); itr++) {
	 if (SameText(Method, itr->second))
	   return itr->first;
	 }
   return -1;
}
//---------------------------------------------------------------------------

int TNeotomaUploadForm::FindAgeType(UnicodeString AgeUnits, vector<AGETYPE>& AgeTypes)
{
   for (unsigned int i=0; i<AgeTypes.size(); i++) {
	 if (SameText(AgeUnits, AgeTypes[i].AgeType))
	   return AgeTypes[i].AgeTypeID;
	 }
   return -1;
}
//---------------------------------------------------------------------------

bool TNeotomaUploadForm::ProcessFacies(NEOTOMAANALUNIT& AnalUnit, TProfGridCell* ACell)
{
   UnicodeString FaciesType = ACell->Text;

   NeotomaFaciesTypeByName Facies(ipsJSONS1, TcpClient1);
   StatusBar1->SimpleText = Facies.WebServiceName();
   Facies.AddParam(L"FACIES", FaciesType);
   if (Facies.Execute()) {
	 if (Facies.Size() > 0)
	   AnalUnit.FaciesID = Facies.Items.begin()->first;
	 else {                 // AnalUnit.AnalysisUnitName
	   UnicodeString msg = L"Facies type «" + FaciesType + L"» in Column " + ACell->A1Name;
	   if (!AnalUnit.Depth.IsEmpty()) {
		 double depth = (double)AnalUnit.Depth;
		 msg += (L", Depth " + FloatToStr(depth));
		 }
	   if (!AnalUnit.AnalysisUnitName.IsEmpty())
		 msg += (L", Analysis Unit «" + AnalUnit.AnalysisUnitName + L"»");
	   msg += L" is not in Neotoma.";
	   UnicodeString query = L"\nUpload new facies type «" + FaciesType + L"» to Neotoma?";
	   int rv = MessageDlg(msg+query, Dialogs::mtError, TMsgDlgButtons() << mbYes << mbNo << mbAbort, 0);
	   if (rv == mrYes) {
		 NeotomaFaciesTypesTable FaciesTable(ipsJSONS1, TcpClient1);
		 StatusBar1->SimpleText = FaciesTable.WebServiceName();
		 if (!FaciesTable.Execute())
		   return false;
		 vector<UnicodeString> FaciesTypes;
		 map<int,UnicodeString>::iterator itr;
		 for (itr = FaciesTable.Items.begin(); itr != FaciesTable.Items.end(); itr++)
		   FaciesTypes.push_back(itr->second);
		 bool repeat;
		 do {
			repeat = false;
			EditFaciesForm = new TEditFaciesForm(FaciesTypes, FaciesType, TSSForm, this);
			EditFaciesForm->ShowModal();
			for (unsigned int i=0; i<EditFaciesForm->OutputMessages.size(); i++)
			  OutputLine(EditFaciesForm->OutputMessages[i]);
			delete EditFaciesForm;
			NeotomaFaciesTypeByName CheckFacies(ipsJSONS1, TcpClient1);
			StatusBar1->SimpleText = CheckFacies.WebServiceName();
			CheckFacies.AddParam(L"FACIES", FaciesType);
			if (CheckFacies.Execute()) {
			  if (CheckFacies.Size() == 0) {
				msg = L"Facies type «" + FaciesType + L"» was not uploaded!";
				rv = MessageDlg(msg, mtWarning, TMsgDlgButtons() << mbRetry << mbCancel << mbAbort, 0);
				switch (rv) {
				  case mrRetry:
					repeat = true;
					break;
				  case mrCancel:
					OutputError("ERROR: " + msg);
					break;
				  case mrAbort:
					OutputError("ERROR: " + msg);
					return false;
				  }
				}
			  }
			else
			  return false;
			} while (repeat);
		 }
	   else {
		 OutputError("ERROR: " + msg);
		 if (rv == mrAbort)
		   return false;
		 }
	   }
	 }
   else
	 return false;

   return true;
}
//---------------------------------------------------------------------------

bool TNeotomaUploadForm::ProcessDepAgent(NEOTOMAANALUNIT& AnalUnit, TProfGridCell* ACell)
{
   UnicodeString DepAgentType = ACell->Text;

   NeotomaDepAgentByName DepAgent(ipsJSONS1, TcpClient1);
   StatusBar1->SimpleText = DepAgent.WebServiceName();
   DepAgent.AddParam(L"DEPAGENT", DepAgentType);
   if (DepAgent.Execute()) {
	 if (DepAgent.Size() > 0)
	   AnalUnit.DepAgentID = DepAgent.Items.begin()->first;
	 else {                 // AnalUnit.AnalysisUnitName
	   UnicodeString msg = L"Depositional Agent «" + DepAgentType + L"» in Column " + ACell->A1Name;
	   if (!AnalUnit.Depth.IsEmpty()) {
		 double depth = (double)AnalUnit.Depth;
		 msg += (L", Depth " + FloatToStr(depth));
		 }
	   if (!AnalUnit.AnalysisUnitName.IsEmpty())
		 msg += (L", Analysis Unit «" + AnalUnit.AnalysisUnitName + L"»");
	   msg += L" is not in Neotoma.";
	   UnicodeString query = L"\nUpload new Depositional Agent «" + DepAgentType + L"» to Neotoma?";
	   int rv = MessageDlg(msg+query, Dialogs::mtError, TMsgDlgButtons() << mbYes << mbNo << mbAbort, 0);
	   if (rv == mrYes) {
		 NeotomaDepAgentsTable DepAgentsTable(ipsJSONS1, TcpClient1);
		 StatusBar1->SimpleText = DepAgentsTable.WebServiceName();
		 if (!DepAgentsTable.Execute())
		   return false;

		 vector<UnicodeString> DepAgents;
		 map<int,UnicodeString>::iterator itr;
		 for (itr = DepAgentsTable.Items.begin(); itr != DepAgentsTable.Items.end(); itr++)
		   DepAgents.push_back(itr->second);
		 bool repeat;
		 do {
			repeat = false;
			EditDepAgentsForm = new TEditDepAgentsForm(DepAgents, DepAgentType, TSSForm, this);
			EditDepAgentsForm->ShowModal();
			for (unsigned int i=0; i<EditDepAgentsForm->OutputMessages.size(); i++)
			  OutputLine(EditDepAgentsForm->OutputMessages[i]);
			delete EditDepAgentsForm;
			NeotomaDepAgentByName CheckDepAgent(ipsJSONS1, TcpClient1);
			StatusBar1->SimpleText = CheckDepAgent.WebServiceName();
			CheckDepAgent.AddParam(L"DEPAGENT", DepAgentType);
			if (CheckDepAgent.Execute()) {
			  if (CheckDepAgent.Size() == 0) {
				msg = L"Depositional agent «" + DepAgentType + L"» was not uploaded!";
				rv = MessageDlg(msg, mtWarning, TMsgDlgButtons() << mbRetry << mbCancel << mbAbort, 0);
				switch (rv) {
				  case mrRetry:
					repeat = true;
					break;
				  case mrCancel:
					OutputError("ERROR: " + msg);
					break;
				  case mrAbort:
					OutputError("ERROR: " + msg);
					return false;
				  }
				}
			  }
			else
			  return false;
			} while (repeat);
		 }
	   else {
		 OutputError("ERROR: " + msg);
		 if (rv = mrAbort)
		   return false;
		 }
	   }
	 }
   else
	 return false;

   return true;
}
//---------------------------------------------------------------------------

bool TNeotomaUploadForm::ValidateDatasets(void)
{
   vector<DATASET>::pointer DatasetPtr;
   UnicodeString msg;
   bool rv = true;

   Screen->Cursor = crHourGlass;

   // validate DatasetTypes
   try {
   // check that all are aggregates if any are
   if (TSSForm->Datasets.size() > 1) {
	 unsigned int nagg = 0;
	 for (unsigned int i=0; i<TSSForm->Datasets.size(); i++) {
	   if (TSSForm->Datasets[i].IsAggregate)
		 nagg++;
	   }
	 if (nagg > 0) {
	   Aggregates = true;
	   if (nagg < TSSForm->Datasets.size()) {
		 msg = L"Some, but not all, dataset types are designated as aggregates.";
		 OutputWarning(L"WARNING: " + msg);
		 if (MessageDlg(msg, mtWarning, TMsgDlgButtons() << mbOK << mbAbort, 0) == mrAbort)
		   return (rv = false);
		 }
	   }
	 }

   for (unsigned int i=0; i<TSSForm->Datasets.size(); i++) {
	 DatasetPtr = &TSSForm->Datasets[i];
	 if (ValidateDatasetType(DatasetPtr)) {
	   if (DatasetPtr->Name.IsEmpty()) {
		 if (DatasetPtr->IsAggregate) {
		   msg = L"Aggregate dataset «" + DatasetPtr->DatasetType.LowerCase() + L"» dataset has no name.";
		   OutputError(L"ERROR: " + msg);
		   if (MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK << mbAbort, 0) == mrAbort)
			 return (rv = false);
		   }
		 else {
		   msg = L"NOTE: Dataset «" + DatasetPtr->DatasetType.LowerCase() + L"» dataset has no name.";
		   OutputNote(msg);
		   }
		 }
	   else
		 OutputLine(L"«" + DatasetPtr->DatasetType + L"» dataset name is «" + DatasetPtr->Name + L"».");

	   if (DatasetPtr->IsAggregate) {
		 AGGDATASET AggregateDataset;
		 AggregateDataset.Name = DatasetPtr->Name;
         AggregateDataset.DatasetTypeID = DatasetPtr->NeotomaDatasetTypeID;
		 if (AggregateDatasets.size() > 1 && !DatasetPtr->Name.IsEmpty()) {
		   for (unsigned int j = 0; j < AggregateDatasets.size(); j++) {
			 if (SameText(AggregateDataset.Name, AggregateDatasets[j].Name)) {
			   msg = L"Aggregate datasets for different datatypes must have different names.";
			   OutputError(L"ERROR: " + msg);
			   if (MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK << mbAbort, 0) == mrAbort)
				 return (rv = false);
			   break;
			   }
			 }
		   }

		 // see if aggregate dataset name already exists
		 NeotomaAggregateDatasetByName NtmAggregateDataset(ipsJSONS1, TcpClient1);
		 NtmAggregateDataset.AddParam(L"NAME", DatasetPtr->Name);
		 StatusBar1->SimpleText = NtmAggregateDataset.WebServiceName();
		 if (!NtmAggregateDataset.Execute())
		   return (rv = false);
		 if (NtmAggregateDataset.Size() > 0) {
		   msg = L"Aggregate dataset «" + DatasetPtr->Name +
				 L"» already exists in Neotoma. Add new samples to this dataset?";
		   if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes) {
			 AggregateDataset.ID = NtmAggregateDataset.Items[0].AggregateDatasetID;
			 AggregateDataset.OrderTypeID = NtmAggregateDataset.Items[0].AggregateOrderTypeID;
			 msg = L"Samples will be added to aggregate dataset «" + DatasetPtr->Name +
				   L"»; AggregateDatasetID = " + IntToStr(AggregateDataset.ID) + L".";
			 OutputLine(msg);
			 }
		   else {
			 msg = L"Duplicate names for aggregate datasets not allowed. Select a different name.";
			 OutputError(L"ERROR: " + msg);
			 if (MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK << mbAbort, 0) == mrAbort)
			   return (rv = false);
			 }
		   }

		 NeotomaAggregateOrderTypes AggregateOrderTypes(ipsJSONS1, TcpClient1);
		 StatusBar1->SimpleText = AggregateOrderTypes.WebServiceName();
		 if (!AggregateOrderTypes.Execute())
		   return (rv = false);

		 if (DatasetPtr->AggregateOrder.IsEmpty()) {
		   if (AggregateDataset.ID > -1) {
			 DatasetPtr->AggregateOrder = AggregateOrderTypes.Items[AggregateDataset.OrderTypeID];
			 msg = L"Default aggregate order set to «" + DatasetPtr->AggregateOrder + L"».";
			 OutputLine(msg);
			 TSSForm->cxComboBox14->ItemIndex = TSSForm->cxComboBox14->Properties->Items->IndexOf(DatasetPtr->AggregateOrder);
			 }
		   else {
			 msg = L"Default order for aggregate dataset not selected.";
			 OutputError(L"ERROR: " + msg);
			 if (MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK << mbAbort, 0) == mrAbort)
			   return (rv = false);
			 }
		   }
		 else {  // Aggregate order not empty
		   int OrderTypeID = -1;
		   map<int,UnicodeString>::iterator itr;
		   for (itr = AggregateOrderTypes.Items.begin(); itr != AggregateOrderTypes.Items.end(); itr++) {
			 if (SameText(DatasetPtr->AggregateOrder,itr->second)) {
			   OrderTypeID = itr->first;
			   break;
			  }
			 }
		   if (OrderTypeID == -1) {   // should never happen, but..
			 msg = L"Aggregate order «" + DatasetPtr->AggregateOrder + L"» not valid.";
			 OutputError(L"ERROR: " + msg);
			 if (MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK << mbAbort, 0) == mrAbort)
			   return (rv = false);
			 }
		   else {
			 if (AggregateDataset.ID > -1) {
			   if (AggregateDataset.OrderTypeID != OrderTypeID) {
				 msg = L"WARNING: Default aggregate dataset order «" + DatasetPtr->AggregateOrder +
					   L"» does not agree with database.";
				 OutputWarning(msg);
				 DatasetPtr->AggregateOrder = AggregateOrderTypes.Items[AggregateDataset.OrderTypeID];
				 msg = L"Default aggregate dataset order changed to «" + DatasetPtr->AggregateOrder + L"».";
				 OutputLine(msg);
				 TSSForm->cxComboBox14->ItemIndex = TSSForm->cxComboBox14->Properties->Items->IndexOf(DatasetPtr->AggregateOrder);
				 }
			   }
			 else {
			   AggregateDataset.OrderTypeID = OrderTypeID;
			   }
			 }
		   }
		 if (AggregateDataset.OrderTypeID > -1) {
		   msg = L"Default aggregate order: «" + DatasetPtr->AggregateOrder +
				 L"»; AggregateOrderTypeID = " + IntToStr(AggregateDataset.OrderTypeID) + L".";
		   OutputLine(msg);
		   }
		 AggregateDatasets.push_back(AggregateDataset);
		 }

	   // investigators
	   if (!ValidateDatasetInvestigators(DatasetPtr, valERROR))
		 return (rv = false);
	   // processors
	   if (!ValidateDatasetProcessors(DatasetPtr, valERROR))
		 return (rv = false);
	   // publications
	   if (!ValidateDatasetPubs(DatasetPtr))
		 return (rv = false);
	   // repositories
	   if (!ValidateDatasetRepositories(DatasetPtr))
		 return (rv = false);
	   }
	 else {  // dataset type not found
	   msg = L"Dataset Type «" + DatasetPtr->DatasetType.LowerCase() + L"» does not exist in Neotoma.";
	   OutputError(L"ERROR: " + msg);
	   if (MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK << mbAbort, 0) == mrAbort) {
		 Screen->Cursor = crDefault;
		 return (rv = false);
		 }
	   }
	 }
	 }
   __finally {
	 SetProgressBarPosition();
	 StatusBar1->SimpleText = L"";
	 Screen->Cursor = crDefault;
	 }
   return rv;
}
//---------------------------------------------------------------------------

bool TNeotomaUploadForm::ValidateDatasetType(DATASET* DatasetPtr)
{
   bool success = false;
   map<int,UnicodeString>::iterator ditr;
   for (ditr = NeotomaDatasetTypes.begin(); ditr != NeotomaDatasetTypes.end(); ditr++) {
	 if (SameText(DatasetPtr->DatasetType, ditr->second)) {
	   success = true;
	   DatasetPtr->NeotomaDatasetTypeID = ditr->first;
	   OutputLine(L"Neotoma Dataset Type «" + ditr->second + L"» validated: DatasetTypeID = " +
		 IntToStr(ditr->first) + L".");
	   break;
	   }
	 }
   return success;
}
//---------------------------------------------------------------------------

bool TNeotomaUploadForm::ValidateDatasetInvestigators(DATASET* DatasetPtr, int ValLev)
{
   bool success = true;
   if (DatasetPtr->Investigators.size() > 0) {
	 for (unsigned int i=0; i<DatasetPtr->Investigators.size(); i++) {
	   OutputLine(L"«" + DatasetPtr->DatasetType.LowerCase() + L"» dataset investigator «" +
		 DatasetPtr->Investigators[i]->FullContactName + L"»: ID = " +
		 IntToStr(DatasetPtr->Investigators[i]->NeotomaContactID) + L".");
	   }
	 }
   else {
	 UnicodeString msg = L"No investigators are assigned to «" + DatasetPtr->DatasetType + L"» dataset.";
	 switch (ValLev) {
	   case valERROR:
		 OutputError(L"ERROR: " + msg);
		 if (MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK << mbAbort, 0) == mrAbort) {
		   Screen->Cursor = crDefault;
		   success = false;
		   }
		 break;
	   case valWARNING:
		 OutputWarning(L"WARNING: " + msg);
		 break;
	   }
	 }
   return success;
}
//---------------------------------------------------------------------------

bool TNeotomaUploadForm::ValidateDatasetProcessors(DATASET* DatasetPtr, int ValLev)
{
   bool success = true;
   if (DatasetPtr->Processors.size() > 0) {
	  for (unsigned int i=0; i<DatasetPtr->Processors.size(); i++) {
		OutputLine(L"«" + DatasetPtr->DatasetType.LowerCase() + L"» data processor «" +
		  DatasetPtr->Processors[i]->FullContactName + L"»: ID = " +
		  IntToStr(DatasetPtr->Processors[i]->NeotomaContactID) + L".");
		}
	  }
   else {
	 UnicodeString msg = L"No data processors are assigned to «" + DatasetPtr->DatasetType + L"» dataset.";
	 switch (ValLev) {
	   case valERROR:
		 OutputError(L"ERROR: " + msg);
		 if (MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK << mbAbort, 0) == mrAbort) {
		   Screen->Cursor = crDefault;
		   success = false;
		   }
		 break;
	   case valWARNING:
		 OutputWarning(L"WARNING " + msg);
		 break;
	   }
	 }
   return success;
}
//---------------------------------------------------------------------------

bool TNeotomaUploadForm::ValidateDatasetPubs(DATASET* DatasetPtr)
{
   bool success = true;
   if (DatasetPtr->Publications.size() > 0) {
	 for (unsigned int i=0; i<DatasetPtr->Publications.size(); i++) {
	   OutputLine(L"«" + DatasetPtr->DatasetType.LowerCase() + L"» dataset publication " +
		 DatasetPtr->Publications[i]->GetShortCitation(true) + L": ID = " +
		 IntToStr(DatasetPtr->Publications[i]->NeotomaID) + L".");
	   }
	 }
   else {
	 UnicodeString msg = L"«" + DatasetPtr->DatasetType.LowerCase() + L"» dataset has no publications";
	 OutputWarning(L"WARNING: " + msg + L".");
	 if (MessageDlg(msg + L"!", mtWarning, TMsgDlgButtons() << mbOK << mbAbort, 0) == mrAbort) {
	   Screen->Cursor = crDefault;
	   success = false;
	   }
	 }
   return success;
}
//---------------------------------------------------------------------------

bool TNeotomaUploadForm::ValidateDatasetRepositories(DATASET* DatasetPtr)
{
   if (DatasetPtr->Repositories.size() > 0) {
	 NeotomaRepositoryInstitutionsTable NeotomaRepositories(ipsJSONS1, TcpClient1);
	 StatusBar1->SimpleText = NeotomaRepositories.WebServiceName();
	 if (!NeotomaRepositories.Execute()) {
	   Screen->Cursor = crDefault;
	   return false;
	   }
	 for (unsigned int i=0; i<DatasetPtr->Repositories.size(); i++) {
	   UnicodeString Repository = DatasetPtr->Repositories[i].Repository;
	   DatasetPtr->Repositories[i].RepositoryID = -1;
	   for (unsigned int j=0; j<NeotomaRepositories.Size(); j++) {
		 if (SameText(Repository, NeotomaRepositories.Items[j].Repository)) {
		   DatasetPtr->Repositories[i].RepositoryID = NeotomaRepositories.Items[j].RepositoryID;
		   break;
		   }
		 }
	   if (DatasetPtr->Repositories[i].RepositoryID == -1) {
		 UnicodeString msg = L"Repository «" + Repository + L"» assigned to «" +
		   DatasetPtr->DatasetType.LowerCase() + L"» dataset is not in Neotoma.";
		 OutputError(L"ERROR: " + msg);
		 if (MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK << mbAbort, 0) == mrAbort) {
		   Screen->Cursor = crDefault;
		   return false;
		   }
		 }
	   else {
		 OutputLine(L"Specimens from «" + DatasetPtr->DatasetType.LowerCase() +
		   L"» dataset are in repository «" + Repository + L"»: ID = " +
		   IntToStr(DatasetPtr->Repositories[i].RepositoryID) + L".");
		 }
	   }
	 }
   return true;
}
//---------------------------------------------------------------------------

// validate analysis units and samples
bool TNeotomaUploadForm::ValidateSamples(void)
{
   int TempCollUnitID, TempAnalUnitID, SampleID, DatasetID;
   Variant Value;
   UnicodeString msg;

   int start = TSSForm->AbsHeaderColCount(TSSForm->ProfGrid1);
   int ncols = TSSForm->AbsContentColCount(TSSForm->ProfGrid1);
   TProfGrid* ProfGrid = TSSForm->ProfGrid1;

   Screen->Cursor = crHourGlass;
   int idx1 = (TSSForm->Sites->Count == 1) ? 0 : 1;
   for (int idx = idx1; idx < TSSForm->Sites->Count; idx++) {
	 site_ptr = (SITE*)TSSForm->Sites->Items[idx];
	 if (site_ptr->NeotomaSiteID == -1)
	   site_ptr->NeotomaSiteID = NextTempSiteID();

	 int idx1 = (site_ptr->CollUnits.size() == 1) ? 0 : 1;
	 for (unsigned int nc=idx1; nc<site_ptr->CollUnits.size(); nc++) {
	   // get set of all spreadsheet columns for this collection unit
	   set<int> CollUnitCols;
	   if (site_ptr->CollUnits.size() == 1) {
		 for (int col=start; col<=ncols; col++)
		   CollUnitCols.insert(col);
		 }
	   else {
		 int row = TSSForm->FindRowMD(COLL_UNIT_NAME);
		 for (int col=start; col<=ncols; col++) {
		   UnicodeString CollUnitName = TSSForm->ProfGrid1->AbsoluteCells[col][row]->Text;
		   if (SameText(site_ptr->CollUnits[nc].CollectionName, CollUnitName))
			 CollUnitCols.insert(col);
		   }
		 }

	   map<int,NEOTOMAVARIABLE>::iterator avitr;
	   map<int,NEOTOMAVARIABLE>::iterator avbegin = NeotomaVariables.begin();
	   map<int,NEOTOMAVARIABLE>::iterator avend = NeotomaVariables.end();

	   // get map of all variables that actually occur in this collection unit
	   map<int,NEOTOMAVARIABLE> CollUnitNeotomaVariables;  // row, Variable
	   for (avitr = avbegin; avitr != avend; avitr++) {
		 int row = avitr->first;
		 for (set<int>::iterator itr = CollUnitCols.begin(); itr != CollUnitCols.end(); itr++) {
		   UnicodeString Value = TSSForm->ProfGrid1->AbsoluteCells[*itr][row]->Text;
		   if (!Value.IsEmpty()) {
			 // check if not zero or zero allowed
			 double dVal = Value.ToDouble();
			 if (dVal != 0.0 || (dVal == 0.0 && ZeroVarsAllowed.count(row) == 1)) {
			   CollUnitNeotomaVariables[row] = avitr->second;
			   break;
			   }
			 }
		   }
		 }

	   map<int,NEOTOMAVARIABLE>::iterator vitr;
	   map<int,NEOTOMAVARIABLE>::iterator vbegin = CollUnitNeotomaVariables.begin();
	   map<int,NEOTOMAVARIABLE>::iterator vend = CollUnitNeotomaVariables.end();

	   site_ptr->CollUnits[nc].NeotomaDatasets = TSSForm->Datasets;
	   for (unsigned int i=0; i<site_ptr->CollUnits[nc].NeotomaDatasets.size(); i++) {
		 site_ptr->CollUnits[nc].NeotomaDatasets[i].NeotomaDatasetID = NextTempDatasetID();
		 }

	   if (site_ptr->CollUnits[nc].NeotomaCollUnitID == -1)
		 site_ptr->CollUnits[nc].NeotomaCollUnitID = NextTempCollUnitID();
	   TempCollUnitID = site_ptr->CollUnits[nc].NeotomaCollUnitID;

	   map<UnicodeString,int> MDAnalRows;
	   map<UnicodeString,int> MDAnalRows2;

	   map<UnicodeString,int>::iterator mitr;
	   TSSForm->GetMetaDataRows(L"#ANAL.", MDAnalRows);
	   if (ContainsText(TSSForm->Datasets[0].DatasetType, L"top-bottom")) {
		 int start_row = TSSForm->FindRowCodeIC(L"#Anal.Bottom", TSSForm->ProfGrid1) + 1;
		 TSSForm->GetMetaDataRows(L"#ANAL.", MDAnalRows2, start_row);
		 }

	   map<UnicodeString,int>::iterator it;

	   // process alternative depths. Go in AnalysisUnitAltDepthScales table
	   map<UnicodeString,int> DepthIDs;
	   for (mitr = MDAnalRows.begin(); mitr != MDAnalRows.end(); mitr++) {
		 UnicodeString Code = mitr->first;
		 if (SameText(Code.SubString(1,5), L"Depth")) {
		   int AltDepthID;
		   if (TryStrToInt(Code.SubString(6,Code.Length()-5),AltDepthID)) {
			 DepthIDs[Code] = AltDepthID;    // DepthIDs["Depth1"] = 1;
			 ALTDEPTHS AltDepths;
			 AltDepths.AltDepthName = TSSForm->ProfGrid1->AbsoluteCells[2][mitr->second]->Text;
			 if (AltDepths.AltDepthName.IsEmpty()) {
			   msg = L"Name for «" + TSSForm->ProfGrid1->AbsoluteCells[1][mitr->second]->Text +
					 L"» cannot be blank.";
			   OutputError(L"ERROR: " + msg);
			   Screen->Cursor = crDefault;
			   if (MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbIgnore << mbAbort, 0) == mrAbort)
				 return false;
			   else {
				 DepthIDs.clear();
				 break;
				 }
			   }
			 UnicodeString DepthUnits = TSSForm->ProfGrid1->AbsoluteCells[4][mitr->second]->Text;
			 if (DepthUnits.IsEmpty()) {
			   msg = L"Units for «" + TSSForm->ProfGrid1->AbsoluteCells[1][mitr->second]->Text +
					 L"» cannot be blank.";
			   OutputError(L"ERROR: " + msg);
			   Screen->Cursor = crDefault;
			   if (MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbIgnore << mbAbort, 0) == mrAbort)
				 return false;
			   else {
				 DepthIDs.clear();
				 break;
				 }
			   }
			 else {
			   NeotomaVariableUnitsID VariableUnitsID(ipsJSONS1, TcpClient1);
			   VariableUnitsID.AddParam(L"VARIABLEUNITS", DepthUnits);
			   StatusBar1->SimpleText = VariableUnitsID.WebServiceName();
			   if (VariableUnitsID.Execute()) {
				 if (VariableUnitsID.Size() == 1)   // Units exist in Neotoma
				   AltDepths.VariableUnitsID = VariableUnitsID.Items[0];
				 else {
				   msg = L"Units «" + DepthUnits + L"» for Depth «" +
						 TSSForm->ProfGrid1->AbsoluteCells[1][mitr->second]->Text +
						 L"» are not in the Neotoma VariableUnits table.";
				   OutputError(L"ERROR: " + msg);
				   Screen->Cursor = crDefault;
				   if (MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbIgnore << mbAbort, 0) == mrAbort)
					 return false;
				   else {
					 DepthIDs.clear();
					 break;
					 }
				   }
				 }
			   else {
				 Screen->Cursor = crDefault;
				 return false;
				 }
			   }
			 AltDepthScales[AltDepthID] = AltDepths;
			 OutputLine(L"Alternative Depth scale " + IntToStr(AltDepthID) +
						L" «" + AltDepths.AltDepthName + "» validated. ");
			 // TODO: deal with Notes for AltDepths
			 }
		   else {
			 msg = L"Invalid Depth number for " + TSSForm->ProfGrid1->AbsoluteCells[1][mitr->second]->Text;
			 OutputError(L"ERROR: " + msg);
			 Screen->Cursor = crDefault;
			 if (MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbIgnore << mbAbort, 0) == mrAbort)
			   return false;
			 else {
			   DepthIDs.clear();
			   break;
			   }
			 }
		   }
		 }

	   // assign temporary DatasetIDs to NeotomaVariables and sample metadata rows
	   multimap<int,SAMPLEMETADATAROW> SampleMetadata;  // DatasetID, Sample metadata code
	   multimap<int,int> DatasetRows;                   // DatasetID, row
	   int TempDatasetID = site_ptr->CollUnits[nc].NeotomaDatasets[0].NeotomaDatasetID;
	   int row = 3;
	   vitr = vbegin;        // map<int,NEOTOMAVARIABLE>::iterator vitr;
	   while (vitr != vend) {
		 if (vitr->first > row) {
		   do {
				UnicodeString Code = TSSForm->ProfGrid1->AbsoluteCells[1][row]->Text;
				if (SameText(Code, L"#Data.Type")) {
				  UnicodeString DatasetType = TSSForm->ProfGrid1->AbsoluteCells[2][row]->Text;
				  for (unsigned int i=0; i<site_ptr->CollUnits[nc].NeotomaDatasets.size(); i++) {
					if (SameText(DatasetType, site_ptr->CollUnits[nc].NeotomaDatasets[i].DatasetType)) {
					  TempDatasetID = site_ptr->CollUnits[nc].NeotomaDatasets[i].NeotomaDatasetID;
					  break;
					  }
					}
				  }
				else if (SameText(Code.SubString(1,6), L"#Samp.")) {
				  Code.Delete(1,6);
				  SAMPLEMETADATAROW sm;
				  sm.row = row;
				  sm.code = Code;
				  SampleMetadata.insert(pair<int,SAMPLEMETADATAROW>(TempDatasetID,sm));
				  }
			  } while (++row < vitr->first);
		   }
		 vitr->second.DatasetID = TempDatasetID;
		 DatasetRows.insert(pair<int,int>(TempDatasetID,vitr->first));
		 vitr++;
		 }

	   // set of all datasets with samples
	   set<int>	DatasetsWithData;
	   map<int,bool> AllowZero;  // DatasetTypeID, T/F
	   set<int> AllowZeroQueried;  // set of DatasetTypeIDs queried already zero values allowed

	   for (int col=start; col<=ncols; col++) {  // loop through all columns (analysis units)
		 if (CollUnitCols.count(col) == 0) continue;

		 NEOTOMAANALUNIT AnalUnit;
		 if (!GetAnalUnitDepth(col, AnalUnit.Depth))
		   return false;

		 if (TSSForm->HeaderRow2 == ANAL_UNIT_NAME)
		   AnalUnit.AnalysisUnitName = VarToStr(ProfGrid->AbsoluteCells[col][2]->Value);

		 for (mitr = MDAnalRows.begin(); mitr != MDAnalRows.end(); mitr++) {
		   int row = mitr->second;
		   TProfGridCell* ACell = ProfGrid->AbsoluteCells[col][row];
		   if (TSSForm->GridCellIsEmpty(ACell) && !ACell->CheckBox)
			 continue;

		   // process Analysis Unit metadata
		   UnicodeString Code = mitr->first;
		   if (SameText(Code, L"Name"))
			 AnalUnit.AnalysisUnitName = VarToStr(ACell->Value);
		   else if (SameText(Code, L"Thick")) {
			 if (!GetAnalUnitThickness(col, row, AnalUnit.Thickness))
			   return false;
			 }
		   else if (SameText(Code, L"Facies")) {
			 if (!ProcessFacies(AnalUnit, ACell)) {
			   Screen->Cursor = crDefault;
			   return false;
			   }
			 }
		   else if (SameText(Code, L"DepAgent")) {
			 if (!ProcessDepAgent(AnalUnit, ACell)) {
			   Screen->Cursor = crDefault;
			   return false;
			   }
			 }
		   else if (SameText(Code, L"Mixed"))
			 AnalUnit.Mixed = ACell->CheckBoxChecked;
		   else if (SameText(Code, L"IGSN"))
			 AnalUnit.IGSN = ACell->Text;
		   else if (SameText(Code, L"Notes"))
			 AnalUnit.Notes = ACell->Text;
		   else if (SameText(Code.SubString(1,5), L"Depth") && DepthIDs.size() > 0) {
			 if (ACell->Value.Type() == varDouble) {
			   AnalUnit.AltDepths[DepthIDs[Code]] = (double)ACell->Value;
			   OutputLine(L"AltDepth " + IntToStr(DepthIDs[Code]) + L" = " +
						  FloatToStr(AnalUnit.AltDepths[DepthIDs[Code]]));
			   }
			 else {
			   InvalidSSNumber(col, 1, L"for Analysis Unit alternative depth", msg);
			   OutputError(L"ERROR: " + msg);
			   if (MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbIgnore << mbAbort, 0) == mrAbort) {
				 Screen->Cursor = crDefault;
				 return false;
				 }
			   }
			 }
		   }

		 // check that analysis units have a depth or name
		 bool is_surface_sample = false;
		 for (unsigned int i=0; i<site_ptr->CollUnits[nc].NeotomaDatasets.size(); i++) {
		   switch (site_ptr->CollUnits[nc].NeotomaDatasets[i].NeotomaDatasetTypeID) {
			 case 7:   // pollen surface sample
			 case 12:  // ostracode surface sample
			 case 13:  // diatom surface sample
			 case 22:  // modern plant biomarker
			 case 27:  // modern biochemistry
			 case 29:  // insect modern
			 case 32:  // testate amoebae surface sample
			   is_surface_sample = true;
			   break;
			 }
		   if (is_surface_sample)
			 break;
		   }

		 msg = L"";
		 if (is_surface_sample) {
		   if (AnalUnit.AnalysisUnitName.IsEmpty()) {
			 msg = L" must have a name row 2.";
			 }
		   }
		 else if (AnalUnit.Depth.IsEmpty() && AnalUnit.AnalysisUnitName.IsEmpty()) {
		   msg = L" must have a depth or name in rows 1 or 2.";
		   }
		 if (!msg.IsEmpty())
		   OutputError(L"ERROR: Analysis Unit in column " + ProfGrid->AbsoluteCols[col]->A1Name + msg);

		 // check if analysis unit already exists (analysis unit has more than one sample)
		 int idx = -1;
		 for (unsigned int i=0; i<NeotomaAnalysisUnits.size(); i++) {
		   if (AnalUnit.Depth == NeotomaAnalysisUnits[i].Depth &&
			   AnalUnit.Thickness == NeotomaAnalysisUnits[i].Thickness &&
			   SameText(AnalUnit.AnalysisUnitName, NeotomaAnalysisUnits[i].AnalysisUnitName)) {
			 idx = i;
			 break;
			 }
		   }

		 if (idx > -1) {
		   if (NeotomaAnalysisUnits[idx].AnalysisUnitID == -1) {  // not yet defined
			 TempAnalUnitID = NextTempAnalUnitID();
			 NeotomaAnalysisUnits[idx].AnalysisUnitID = TempAnalUnitID;
			 }
		   else
			 TempAnalUnitID = NeotomaAnalysisUnits[idx].AnalysisUnitID;
		   AnalUnit = NeotomaAnalysisUnits[idx];
		   }
		 else {
		   TempAnalUnitID = NextTempAnalUnitID();
		   AnalUnit.AnalysisUnitID = TempAnalUnitID;
		   AnalUnit.CollectionUnitID = TempCollUnitID;   // uncommented this line
		   NeotomaAnalysisUnits.push_back(AnalUnit);
		   }
		 AnalUnit.CollectionUnitID = TempCollUnitID;

		 // get sample data and metadata
		 for (unsigned int i=0; i<site_ptr->CollUnits[nc].NeotomaDatasets.size(); i++) {
		   int TempDatasetID = site_ptr->CollUnits[nc].NeotomaDatasets[i].NeotomaDatasetID;

		   if (DatasetRows.count(TempDatasetID) > 0) {   // dataset has variables
			 NEOTOMASAMPLE Sample;
			 Sample.DatasetTypeID = site_ptr->CollUnits[nc].NeotomaDatasets[i].NeotomaDatasetTypeID;
			 multimap<int,int>::iterator ditr;
			 pair<multimap<int,int>::iterator, multimap<int,int>::iterator> data_range;
			 data_range = DatasetRows.equal_range(TempDatasetID);

			 for (ditr = data_range.first; ditr != data_range.second; ditr++) {  // loop through dataset rows
			   int row = ditr->second;
			   TProfGridCell* ACell = ProfGrid->AbsoluteCells[col][row];

			   if (ACell->Value.Type() == varDouble && !ACell->Text.IsEmpty()) {
				 NEOTOMADATA data;
				 data.Value = (double)ACell->Value;
				 // TODO: deal with zero values -- probably handle by DataType (e.g. LABO)
				 int DatasetTypeID = NeotomaVariables[row].DatasetTypeID;
				 bool allow_zero = false;
				 if (data.Value == 0.0) {
				   if (ZeroVarsAllowed.count(row) == 1)
					 allow_zero = true;
				   else {
					 switch (DatasetTypeID) {
					   case 2:   // loss-on-ignition
					   case 10:  // water chemistry
					   case 14:  // geochemistry
					   case 15:  // physical sedimentology
					   case 16:  // charcoal
					   case 18:  // XRF
					   case 19:  // XRD
					   case 20:  // EDS/EDX
					   case 21:  // biomarker
					   case 24:  // specimen stable isotope
					   case 25:  // paleomagnetic
					   case 31:  // stable isotope
					   case 36:  // microcharcoal
					   case 37:  // macrocharcoal
						 if (AllowZero.count(DatasetTypeID) == 0) {
						   UnicodeString DatasetType = NeotomaDatasetTypes[DatasetTypeID];
						   msg = L"Allow zero values for «" + DatasetType + L"» dataset type?";
						   allow_zero = (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes);
						   AllowZero[DatasetTypeID] = allow_zero;
						   if (allow_zero)
							 msg = L"Zero values allowed for dataset type «" + DatasetType + L"».";
						   else
							 msg = L"Zero values not allowed for dataset type «" + DatasetType + L"».";
						   OutputLine(msg);
						   }
						 else
						   allow_zero = AllowZero[DatasetTypeID];
						 break;
					   default:  // for other dataset types check for samples with all zero values
						 if (AllowZero.count(DatasetTypeID) == 0 && AllowZeroQueried.count(DatasetTypeID) == 0) {
						   bool zerocol = true;
							 multimap<int,int>::iterator rit;
							 for (rit = data_range.first; rit != data_range.second; rit++) {  // loop through dataset rows
							   int arow = rit->second;
							   TProfGridCell* ACell = ProfGrid->AbsoluteCells[col][arow];
							   if (!ACell->Text.IsEmpty()) {
								 if (ACell->Value.Type() == varDouble) {
								   double Value = (double)ACell->Value;
								   if (Value != 0.0) {
									 zerocol = false;
									 break;
									 }
								   }
								 }
							   }
						   if (zerocol) {
							 UnicodeString DatasetType = NeotomaDatasetTypes[DatasetTypeID];
							 msg = L"Some samples for dataset type «" + DatasetType + L"» have all zero values.";
							 msg += L"\nAllow zero values for this dataset?";
                             allow_zero = (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes);
							 AllowZero[DatasetTypeID] = allow_zero;
							 if (allow_zero) {
							   msg = L"Zero values allowed for dataset type «" + DatasetType + L"».";
							   OutputLine(msg);
							   }
							 AllowZeroQueried.insert(DatasetTypeID);
							 }
						   }
						 else if (AllowZero.count(DatasetTypeID) > 0)
						   allow_zero = AllowZero[DatasetTypeID];
					   }
					 }
				   }

				 if (data.Value != 0.0 || allow_zero) {
				   data.VariableID = NeotomaVariables[row].VariableID;
				   // ShowMessage(L"VariableID = " + IntToStr(data.VariableID) + L", row = " + IntToStr(row));
				   TProfGridCell* ACell = ProfGrid->AbsoluteCells[col][row];
				   if (ACell->CellObject != NULL) {
					 CELLOBJECT* CellObject = (CELLOBJECT*)ACell->CellObject;
					 if (CellObject->ObjectType == CELLSPECIMENS) {
					   data.Specimens = (TList*)CellObject->Object;
					   }
					 }
				   if (NeotomaVariables[row].TaphTypeIDs.size() > 0) {
					 // ShowMessage(L"Taph row = " + IntToStr(row));
					 data.TaphTypeIDs = NeotomaVariables[row].TaphTypeIDs;
					 }
				   if (DatasetTypeID == 31) {  // stable isotope dataset
					 if (NeotomaVariables[row].TaxonAnalyzedID != -1) {
					   data.IsoStratData.TaxonID = NeotomaVariables[row].TaxonAnalyzedID;
					   data.IsoStratData.empty = false;
					   }
					 if (NeotomaVariables[row].ElementAnalyzedID != -1) {
					   data.IsoStratData.ElementTypeID = NeotomaVariables[row].ElementAnalyzedID;
					   data.IsoStratData.empty = false;
					   }
					 // map<int,pair<UnicodeString,UnicodeString> > MetadataCodes;  // row, <complete code, code>, e.g. #dD.SD, SD
					 if (IsoDataset.size() > 0) {
					   for (unsigned int i=0; i<IsoDataset.size(); i++) {
						 if (IsoDataset[i].Row == row) {
						   map<int,pair<UnicodeString,UnicodeString> >::iterator itr;
						   for (itr = IsoDataset[i].MetadataCodes.begin(); itr != IsoDataset[i].MetadataCodes.end(); itr++) {
							 int mdrow = itr->first;
							 UnicodeString mdItem = itr->second.second;
							 if (SameText(mdItem,L"SD")) {
							   if (ProfGrid->AbsoluteCells[col][mdrow]->Value.Type() == varDouble) {
								 data.IsoStratData.SD = (double)ProfGrid->AbsoluteCells[col][mdrow]->Value;
                                 data.IsoStratData.empty = false;
								 }
							   }
							 }
						   }
						 }
					   }
					 }
				   Sample.data.push_back(data);
				   }
				 }
			   else if (!ACell->IsEmpty()) {
				 InvalidSSNumber(col, row, L"", msg);
				 OutputError(L"ERROR: " + msg);
				 }
			   }

			 if (Sample.data.size() > 0) {  // data exists for sample
			   Sample.col = col;
			   Sample.SampleID = NextTempSampleID();
			   Sample.DatasetID = TempDatasetID;
			   Sample.AnalysisUnitID = TempAnalUnitID;
			   Sample.CollUnitID = TempCollUnitID;
			   // assign SampleID to Specimens in sample
			   if (Sample.data.size() > 0) {
				 for (unsigned int j = 0; j < Sample.data.size(); j++) {
				   if (Sample.data[j].Specimens != NULL) {
					 if (Sample.data[j].Specimens->Count > 0) {
					   for (int k=0; k<Sample.data[j].Specimens->Count; k++) {
						 SPECIMEN* Specimen = (SPECIMEN*)Sample.data[j].Specimens->Items[k];
						 Specimen->SampleID = Sample.SampleID;
						 }
					   }
					 }
				   }
				 }

			   // get sample metadata
			   if (SampleMetadata.count(TempDatasetID) > 0) {
				 multimap<int,SAMPLEMETADATAROW>::iterator smitr;
				 pair<multimap<int,SAMPLEMETADATAROW>::iterator, multimap<int,SAMPLEMETADATAROW>::iterator> metadata_range;
				 metadata_range = SampleMetadata.equal_range(TempDatasetID);
				 for (smitr = metadata_range.first; smitr != metadata_range.second; smitr++) {
				   int row = smitr->second.row;
				   TProfGridCell* ACell = ProfGrid->AbsoluteCells[col][row];
				   if (TSSForm->GridCellIsEmpty(ACell) && !ACell->CheckBox)
					 continue;

				   // process sample metadata
				   UnicodeString Code = smitr->second.code;

				   if (SameText(Code, L"Name")) {
#ifdef WHITMORE
					 // if (TSSForm->Datasets[0].WhitmoreID1 == -1)
					 if (!TSSForm->Datasets[0].WhitmoreData)
					   Sample.SampleName = VarToStr(ACell->Value);
#else
					 Sample.SampleName = VarToStr(ACell->Value);
#endif
					 }
				   else if (SameText(Code, L"Keywords")) {
					 UnicodeString KeywordList = ACell->Value;
					 if (!KeywordList.IsEmpty()) {
					   vector<UnicodeString> Keywords;
					   ParsePartsIC(KeywordList, L";", Keywords);
					   Sample.Keywords = Keywords;
					   }
					 }
				   else if (SameText(Code, L"Taxon")) {
					 if (!ACell->Text.IsEmpty()) {
					   Sample.TaxonID = SampledTaxa[ACell->Text];
					   }
					 }
				   else if (SameText(Code, L"Analyst")) {
					 CELLOBJECT* CellObject = (CELLOBJECT*)ACell->CellObject;
					 if (CellObject != NULL && CellObject->ObjectType == CELLCONTACTS) {
					   // check that analyst names in cell agree with CellObject
					   TList* CellContacts = (TList*)CellObject->Object;
					   set<UnicodeString> Analysts;
					   UnicodeString AnalStr = ACell->Text;
					   int pos;
					   while ((pos = AnalStr.Pos(L";")) > 0) {
						 Analysts.insert(AnalStr.SubString(1,pos-1));
						 AnalStr.Delete(1,pos);
						 }
					   Analysts.insert(AnalStr);

					   if (Analysts.size() == (unsigned int)CellContacts->Count) {
						 set<UnicodeString>::iterator itr;
						 for (itr = Analysts.begin(); itr != Analysts.end(); itr++) {
						   bool found = false;
						   for (int i=0; i<CellContacts->Count; i++) {
							 CONTACT* Contact = (CONTACT*)CellContacts->Items[i];
							 if (Contact->ShortContactName == *itr) {
							   Sample.AnalystIDs.push_back(Contact->NeotomaContactID);
							   found = true;
							   }
							 }
						   if (!found) {
							 msg = L"Analyst name «" + *itr + L"» in cell " +
							   ACell->A1Name + L" is not linked with ContactID.";
							 OutputError(L"ERROR: " + msg);
							 }
						   }
						 }
					   else {
						 msg = L"Number of analyst names in cell " +
							   ACell->A1Name + L" does not agree with linked ContactIDs.";
						 OutputError(L"ERROR: " + msg);
						 }
					   }
					 else {
					   msg = L"Analyst name «" + ACell->Text + L"» in cell " +
							 ACell->A1Name + L" is not linked to a ContactID.";
					   OutputError(L"ERROR: " + msg);
					   }
					 }
				   else if (SameText(Code, L"DateSamp"))
					 Sample.DateSampled = ACell->Value;
				   else if (SameText(Code, L"DateAnal"))
					 Sample.DateAnalyzed = ACell->Value;
				   else if (SameText(Code, L"LabNum"))
					 Sample.LabNumber = VarToStr(ACell->Value);
				   else if (SameText(Code, L"Method"))
					 Sample.PrepMethod = VarToStr(ACell->Value);
				   else if (SameText(Code, L"Notes"))
					 Sample.Notes = VarToStr(ACell->Value);
				   }
				 }

			   UnicodeString DepthStr;
			   if (AnalUnit.Depth.Type() == varDouble)
				 DepthStr = FloatToStr((double)AnalUnit.Depth);
			   NeotomaSamples.push_back(Sample);

			   if (DatasetsWithData.count(TempDatasetID) == 0)
				 DatasetsWithData.insert(TempDatasetID);
			   }  // end data exists for sample
			 }    // end dataset has varibles
		   }
		 }  // end processing columns (Analysis units and samples)

	   // check if analysts in all samples or none per dataset
	   map<int,bool> DatasetHasAnalysts;    // TempDatasetID, HasAnalysts
	   map<int,UnicodeString> DatasetTypes; // TempDatasetID, DatasetType
	   for (unsigned int i=0; i<site_ptr->CollUnits[nc].NeotomaDatasets.size(); i++) {
		 int nsamp = 0;
		 int TempDatasetID = site_ptr->CollUnits[nc].NeotomaDatasets[i].NeotomaDatasetID;

		 if (DatasetsWithData.count(TempDatasetID) == 0) continue;

		 UnicodeString DatasetType = site_ptr->CollUnits[nc].NeotomaDatasets[i].DatasetType;
		 DatasetTypes[TempDatasetID] = DatasetType;
		 for (unsigned int j=0; j<NeotomaSamples.size(); j++) {
		   if (NeotomaSamples[j].DatasetID == TempDatasetID) {
			 if (nsamp == 0)
			   DatasetHasAnalysts[TempDatasetID] = (NeotomaSamples[j].AnalystIDs.size() > 0);
			 else {
			   bool HasAnalysts = (NeotomaSamples[j].AnalystIDs.size() > 0);
			   if (HasAnalysts != DatasetHasAnalysts[TempDatasetID]) {
				 msg = L"WARNING: Analysts are assigned to some, but not all, «" + DatasetType + L"» samples.";
				 OutputWarning(msg);
				 DatasetHasAnalysts[TempDatasetID] = true;
				 break;
				 }
			   }
			 nsamp++;
			 }
		   }
		 }

	   // check if samples from all datasets have analysts
	   if (site_ptr->CollUnits[nc].NeotomaDatasets.size() > 1) {
		 map<int,bool>::iterator bitr;
		 for (bitr = DatasetHasAnalysts.begin(); bitr != DatasetHasAnalysts.end(); bitr++) {
		   if (!bitr->second && DatasetsWithData.count(bitr->first) > 0) {
			 msg = L"WARNING: «" + DatasetTypes[bitr->first] + L"» dataset does not have analysts assigned.";
			 OutputWarning(msg);
			 }
		   }
		 }

	   // check surface sample
	   for (unsigned int i=0; i<site_ptr->CollUnits[nc].NeotomaDatasets.size(); i++) {
		 bool HasDepths = false;
		 if (DatasetsWithData.count(site_ptr->CollUnits[nc].NeotomaDatasets[i].NeotomaDatasetID) == 0)
		   continue;

		 DATASET* DatasetPtr = &site_ptr->CollUnits[nc].NeotomaDatasets[i];
		 if (ContainsText(DatasetPtr->DatasetType, L"surface sample")) {
		   DatasetPtr->IsSSamp = true;
		   // TODO: set NeotomaSamples[j].Modern = true;
		   }
		 else if (DatasetPtr->IsSSamp) {
		   msg = L"The top sample of dataset «" + DatasetPtr->DatasetType +
			 "» is designated as a modern surface sample.\nShould it be?";
		   if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes) {
			 double MinDepth;
			 int ModernSampleID = 0;
			 for (unsigned int j=0; j<NeotomaSamples.size(); j++) {
			   if (NeotomaSamples[j].DatasetID == DatasetPtr->NeotomaDatasetID) {
				 int AnalUnitID = NeotomaSamples[j].AnalysisUnitID;
				 for (unsigned int k=0; k<NeotomaAnalysisUnits.size(); k++) {
				   if (AnalUnitID == NeotomaAnalysisUnits[k].AnalysisUnitID) {
					 if (!NeotomaAnalysisUnits[k].Depth.IsEmpty()) {
					   HasDepths = true;
					   if (ModernSampleID != 0) {
						 double Depth = NeotomaAnalysisUnits[k].Depth;
						 if (Depth < MinDepth) {
						   MinDepth = Depth;
						   ModernSampleID = NeotomaSamples[j].SampleID;
						   }
						 }
					   else {
						 MinDepth = NeotomaAnalysisUnits[k].Depth;
						 ModernSampleID = NeotomaSamples[j].SampleID;
						 }
					   }
					 break;
					 }
				   }
				 }
			   }  // end surface samples

			 if (ModernSampleID != 0) {   // a modern SampleID found
			   for (unsigned int j=0; j<NeotomaSamples.size(); j++) {
				 if (ModernSampleID == NeotomaSamples[j].SampleID) {
				   bool found = false;
				   // check if modern keyword already listed for sample
				   if (NeotomaSamples[j].Keywords.size() > 0) {
					 for (unsigned int k=0; k<NeotomaSamples[j].Keywords.size(); k++) {
					   // if (ContainsText(NeotomaSamples[j].Keywords[k], L"modern")) [
					   if (SameText(NeotomaSamples[j].Keywords[k], L"modern")) {
						 found = true;  // sample already has modern keyword
						 break;
						 }
					   }
					 }
				   if (!found) {  // modern keyword not found, so add it
					 if (NeotomaKeywords.size() == 0) {
					   if (!GetNeotomaKeywords())
						 return false;
					   }
					 map<int,UnicodeString>::iterator itr;
					 for (itr = NeotomaKeywords.begin(); itr != NeotomaKeywords.end(); itr++) {
					   // if (ContainsText(itr->second, L"modern")) [
					   if (SameText(itr->second, L"modern")) {
						 NeotomaSamples[j].Keywords.push_back(itr->second);  // modern keyword added
						 found = true;
						 break;
						 }
					   }
					 }
				   if (found) {  // output message
					 int TempAnalUnitID = NeotomaSamples[j].AnalysisUnitID;
					 for (unsigned int j=0; j<NeotomaAnalysisUnits.size(); j++) {
					   if (NeotomaAnalysisUnits[j].AnalysisUnitID == TempAnalUnitID) {
						 OutputLine(L"Dataset modern sample: Analysis Unit depth = " +
						   FloatToStr((double)NeotomaAnalysisUnits[j].Depth) + L".");
						 break;
						 }
					   }
					 }
				   break;
				   }
				 }
			   }

			 if (!HasDepths && ModernSampleID == 0) {  // samples don't have depths
			   OutputWarning(L"WARNING: Cannot designate surface sample. The surface sample checkbox is checked on the Dataset tabsheet for «"
				 + DatasetPtr->DatasetType + L"» dataset, but analysis units do not have depths.");
			   }
			 }
		   else {
             DatasetPtr->IsSSamp = false;
			 }
		   }
		 }
	   }    // end single collection unit
	 }      // end single site

   set<int> IDs;
   for (unsigned int i=0; i<NeotomaSamples.size(); i++) {
	 if (IDs.find(NeotomaSamples[i].SiteID) == IDs.end())
	   IDs.insert(NeotomaSamples[i].SiteID);
	 }
   msg = IntToStr((int)IDs.size());
   if (IDs.size() == 1)
	 msg += L" site";
   else
	 msg += L" sites";
   msg += L" validated.";
   OutputLine(msg);

   IDs.clear();
   for (unsigned int i=0; i<NeotomaSamples.size(); i++) {
	 if (IDs.find(NeotomaSamples[i].CollUnitID) == IDs.end())
	   IDs.insert(NeotomaSamples[i].CollUnitID);
	 }
   msg = IntToStr((int)IDs.size());
   if (IDs.size() == 1)
	 msg += L" collection unit";
   else
	 msg += L" collection units";
   msg += L" validated.";
   OutputLine(msg);

   IDs.clear();
   for (unsigned int i=0; i<NeotomaSamples.size(); i++) {
	 if (IDs.find(NeotomaSamples[i].AnalysisUnitID) == IDs.end())
	   IDs.insert(NeotomaSamples[i].AnalysisUnitID);
	 }
   msg = IntToStr((int)IDs.size());
   if (IDs.size() == 1)
	 msg += L" analysis unit";
   else
	 msg += L" analysis units";
   msg += L" validated.";
   OutputLine(msg);

   IDs.clear();
   // get set of DatasetIDs with data
   for (unsigned int i=0; i<NeotomaSamples.size(); i++) {
	 if (IDs.find(NeotomaSamples[i].DatasetID) == IDs.end())
	   IDs.insert(NeotomaSamples[i].DatasetID);
	 }
   msg = IntToStr((int)IDs.size());
   if (IDs.size() == 1)
	 msg += L" dataset";
   else
	 msg += L" datasets";
   msg += L" validated.";
   OutputLine(msg);

   set<int>::reverse_iterator sitr;
   for (sitr = IDs.rbegin(); sitr != IDs.rend(); sitr++) {    // iterate through DatasetIDs
	 int DatasetID = *sitr;
	 UnicodeString DatasetType;
	 UnicodeString SiteName;
	 UnicodeString Handle;
	 for (int ns=0; ns<TSSForm->Sites->Count; ns++) {
	   site_ptr = (SITE*)TSSForm->Sites->Items[ns];
	   int idx1 = (site_ptr->CollUnits.size() == 1) ? 0 : 1;
	   for (unsigned int nc=idx1; nc<site_ptr->CollUnits.size(); nc++) {
		 for (unsigned int i=0; i<site_ptr->CollUnits[nc].NeotomaDatasets.size(); i++) {
		   if (DatasetID == site_ptr->CollUnits[nc].NeotomaDatasets[i].NeotomaDatasetID) {
			 DatasetType = site_ptr->CollUnits[nc].NeotomaDatasets[i].DatasetType;
			 SiteName = site_ptr->SiteName;
			 Handle = site_ptr->CollUnits[nc].Handle;
			 break;
			 }
		   }
		 }
	   }

	 int nSamples = 0;
	 for (unsigned int i=0; i<NeotomaSamples.size(); i++) {
	   if (DatasetID == NeotomaSamples[i].DatasetID)
		 nSamples++;
	   }
	 if (nSamples > 0) {
	   msg = L"Site «" + SiteName + L"», Collection Unit «" + Handle + L"», " +
	         L"Dataset «" + DatasetType + L"» has " + IntToStr(nSamples);
	   if (nSamples == 1)
		 msg += L" sample.";
	   else
		 msg += L" samples.";
	   OutputLine(msg);
	   }
	 }

   Screen->Cursor = crDefault;
   SetProgressBarPosition();
   return true;
}
//---------------------------------------------------------------------------

bool TNeotomaUploadForm::GetAnalUnitDepth(int col, Variant& Depth)
{
   UnicodeString ErrMsg;
   Variant Value = TSSForm->ProfGrid1->AbsoluteCells[col][1]->Value;

   if (Value.Type() == varDouble)
	 Depth = (double)Value;
   else if (!TSSForm->GridCellIsEmpty(TSSForm->ProfGrid1->AbsoluteCells[col][1])) {
	 InvalidSSNumber(col, 1, L"for Analysis Unit depth or number", ErrMsg);
	 OutputError(L"ERROR: " + ErrMsg);
	 Screen->Cursor = crDefault;
	 return false;
	 }
   return true;
}
//---------------------------------------------------------------------------

bool TNeotomaUploadForm::GetAnalUnitThickness(int col, int row, Variant& Thickness)
{
   UnicodeString ErrMsg;
   Variant Value = TSSForm->ProfGrid1->AbsoluteCells[col][row]->Value;

   if (Value.Type() == varDouble)
	 Thickness = (double)Value;
   else {
	 InvalidSSNumber(col, row, L"for Analysis Unit thickness", ErrMsg);
	 OutputError(L"ERROR: " + ErrMsg);
	 Screen->Cursor = crDefault;
	 return false;
	 }
   return true;
}
//---------------------------------------------------------------------------

bool TNeotomaUploadForm::ValidatePublicationIDs(void)
{
   bool error = false;
   UnicodeString msg;

   // Synonym pubs
   map<int,NEOTOMAVARIABLE>::iterator itr;
   map<int,NEOTOMAVARIABLE>::iterator begin = NeotomaVariables.begin();
   map<int,NEOTOMAVARIABLE>::iterator end = NeotomaVariables.end();
   Screen->Cursor = crHourGlass;

   int nValidated = 0;
   for (itr = begin; itr != end; itr++) {
	 if (itr->second.Synonymy.size() > 0) {
	   for (unsigned int i=0; i<itr->second.Synonymy.size(); i++) {
		 if (itr->second.Synonymy[i].Pub != NULL) {
		   nValidated++;
		   if (itr->second.Synonymy[i].Pub->NeotomaID == -1) {
			 msg = L"ERROR in row " + IntToStr(itr->first) +
				   L": Publication «" + itr->second.Synonymy[i].Pub->GetShortCitation(true) +
				   L"» for synonym «" + itr->second.Synonymy[i].TaxonName +
				   L"» not assigned a Neotoma Publication ID";
			 OutputError(msg);
			 error = true;
			 }
		   }
		 }
	   }
	 }

   Screen->Cursor = crDefault;
   if (error)
	 return false;
   else if (nValidated > 0)
	 OutputLine(L"Publication IDs validated.");
   SetProgressBarPosition();
   return true;
}
//---------------------------------------------------------------------------

bool TNeotomaUploadForm::ValidatePublications(void)
{
   PUBLICATION *pub;
   NTMPUBLICATION ntm_pub;
   vector<NTMAUTHOR> ntm_authors;
   vector<NTMEDITOR> ntm_editors;
   vector<NTMTRANSLATOR> ntm_translators;
   bool AuthorMatch, YearMatch, found;
   UnicodeString msg;
   bool success = true;

   int i = 0;
   while (i < TSSForm->Publications->Count) {
	 bool retry = false;
	 if (!success) {
	   msg = L"Publication " + FormatCitation(pub->AuthorList, pub->PublicationYear) +
			 L" not resolved. Continue validating publications?";
	   if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrNo) {
		 OutputError(L"ERROR: Validation of publications halted");
		 break;
		 }
	   else
		 success = true;
	   }
	 pub = (PUBLICATION*)TSSForm->Publications->Items[i];
	 // NeotomaID is already set, but need to revalidate pub
	 if (pub->NeotomaID > -1) {
	   if (!GetNeotomaPub(pub, ntm_pub, ntm_authors, ntm_editors, ntm_translators, found)) {
		 success = false;
		 break;
		 }

	   if (found) {
		 if (SamePub(pub, ntm_pub, ntm_authors, ntm_editors, ntm_translators, AuthorMatch, YearMatch)) {
		   OutputLine(L"Publication " + FormatCitation(pub->AuthorList, pub->PublicationYear) +
			   L" matched: PublicationID = " + IntToStr(pub->NeotomaID));
		   }
		 else {
		   int ntm_pubtype = ntm_pub.PubTypeID;
		   if (AuthorMatch && YearMatch && ntm_pubtype == LEGACY) {
			 msg = L"Publication " + FormatCitation(pub->AuthorList, pub->PublicationYear) +
				   L" matches Neotoma legacy PublicationID " + IntToStr(pub->NeotomaID) +
				   L", which has not been parsed into bibliogrphic fields." +
				   L"\nPublication must be updated.";
			 }
		   else {
			 msg = L"Publication " + FormatCitation(pub->AuthorList, pub->PublicationYear) +
				   L" has been matched with Neotoma PublicationID " + IntToStr(pub->NeotomaID) +
				   L";\nhowever, differences exist in one or more bibliographic fields." +
				   L"\nPublication must be updated.\n\nHint: Get publication from Neotoma to compare differences." +
				   L" Then either update\npublication from Neotoma or update Neotoma with current publication.";
			 }
		   MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);

		   PUBTYPEDEFS PubTypeDefs;

		   bool repeat;
		   int rv;
		   do {
			  rv = mrOk;
			  PUBLICATION* savepub = new PUBLICATION(NOTSELECTED);
			  *savepub = *pub;
			  TStewardPubForm* PubForm = new TStewardPubForm(pub, EDITPUB, TSSForm->ContactList, this);
			  if (PubForm->ShowModal() == mrOk) {
				TSSForm->Publications->Sort(TSSForm->CitationCompare);
				TSSForm->AddAuthorsToContacts(pub->AuthorList);
				ntm_authors.clear();
				//ntm_editors.clear();
				//ntm_translators.clear();
				if (GetNeotomaPub(pub, ntm_pub, ntm_authors, ntm_editors, ntm_translators, found)) {
				  if (found) {
					if (SamePub(pub, ntm_pub, ntm_authors, ntm_editors, ntm_translators, AuthorMatch, YearMatch)) {
					  OutputLine(L"Publication " + FormatCitation(pub->AuthorList, pub->PublicationYear) +
						  L" matched: PublicationID = " + IntToStr(pub->NeotomaID));
					  }
					else {
					  msg = L"Publication still not found in Neotoma. Is this a new publication?";
					  rv = MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo << mbAbort, 0);
					  }
					}
				  else {  // publication still not found
					msg = L"Publication still not found in Neotoma. Is this a new publication?";
					rv = MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo << mbAbort, 0);
					}
				  }
				else {
				  rv = mrAbort;
				  }
				}
			  else {
				*pub = *savepub;
				msg = L"No match made with Neotoma publication. Is this a new publication?";
				rv = MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo << mbAbort, 0);
				}
			  delete savepub;
			  delete PubForm;
			  switch (rv) {
				case mrYes:
				  OutputLine(L"Publication " + FormatCitation(pub->AuthorList, pub->PublicationYear) +
					  L" formerly matched with Neotoma PublicationID " + IntToStr(pub->NeotomaID) +
					  L" reassigned as new publication.");
				  pub->NeotomaID = -1;
				  repeat = false;
				  break;
				case mrNo:
				  repeat = true;
				  break;
				case mrAbort:
				  OutputError(L"ERROR: Publication " + FormatCitation(pub->AuthorList, pub->PublicationYear) +
					  L" has been assigned Neotoma PublicationID " + IntToStr(pub->NeotomaID) +
					  L"; however, publication fields do not match.");
				  success = false;
				  repeat = false;
				  break;
				default:
				  repeat = false;
				  break;
				}
			  } while (repeat);
		   }
		 }
	   }

	 // Neotoma PubID is not set and validation of a previously set ID was not aborted
	 if (success && pub->NeotomaID == -1) {
	   // first try to find publication
	   PUBLICATION* savepub = new PUBLICATION(NOTSELECTED);
	   *savepub = *pub;
	   TValidatePubForm* ValidatePubForm = new TValidatePubForm(pub, EDITPUB, TSSForm->ContactList, this);
	   if (ValidatePubForm->ShowModal() == mrOk) {
		 TSSForm->Publications->Sort(TSSForm->CitationCompare);
		 TSSForm->AddAuthorsToContacts(pub->AuthorList);
		 // during this step, pub is assigned the Neotoma PubID, but steward has
		 // opportunity to edit publication, so it needs to be revalidated
		 retry = true;
		 }
	   else {
		 *pub = *savepub;
		 msg = L"No match made with Neotoma publication.";
		 if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbRetry << mbAbort, 0) == mrRetry)
		   retry = true;
		 else {
		   OutputError(L"ERROR: Publication " + FormatCitation(pub->AuthorList, pub->PublicationYear) +
					   L" has not been assigned Neotoma PublicationID");
		   }
		 }
	   delete savepub;
	   delete ValidatePubForm;
	   }
	 if (!retry) i++;
	 }

   // check for primary pub
   if (success) {
	 if (TSSForm->Publications->Count == 1) {
	   pub = (PUBLICATION*)TSSForm->Publications->Items[0];
	   pub->Primary = true;
	   }
	 else if (TSSForm->Publications->Count > 1) {
	   bool primary_pub = false;
	   for (int i=0; i<TSSForm->Publications->Count; i++) {
		 pub = (PUBLICATION*)TSSForm->Publications->Items[i];
		 if (pub->Primary) {
		   primary_pub = true;
		   break;
		   }
		 }
	   if (!primary_pub) {
		 msg = L"No primary publication designated.";
		 OutputWarning(L"WARNING: " + msg);
		 MessageDlg(msg, mtWarning, TMsgDlgButtons() << mbOK, 0);
		 }
	   }
	 }

   SetProgressBar(CORE);
   SetProgressBarPosition();
   Screen->Cursor = crDefault;
   StatusBar1->SimpleText = L"";
   return success;
}
//---------------------------------------------------------------------------

bool TNeotomaUploadForm::ValidateContacts(void)
{
   UnicodeString msg;
   vector<CONTACT*>::iterator begin;
   vector<CONTACT*>::iterator end;
   vector<UnicodeString> Analysts;
   bool success = true;

   // check that all contacts are linked

   // publications
   for (int i=0; i<TSSForm->Publications->Count; i++) {
	 PUBLICATION* pub = (PUBLICATION*)TSSForm->Publications->Items[i];
	 for (unsigned int j=0; j<pub->AuthorList.size(); j++) {
	   CONTACT* Contact = pub->AuthorList[j].contact;
       begin = LinkedContacts.begin();
	   end = LinkedContacts.end();
	   if (find(begin, end, Contact) == end)
		 LinkedContacts.push_back(Contact);
	   }
	 }

   // Collectors
   for (int i=0; i<TSSForm->Sites->Count; i++) {
	 SITE* site_ptr = (SITE*)TSSForm->Sites->Items[i];
	 for (unsigned int j=0; j<site_ptr->CollUnits.size(); j++) {
	   for (unsigned int k=0; k < site_ptr->CollUnits[j].Collectors.size(); k++) {
		 CONTACT* Contact = site_ptr->CollUnits[j].Collectors[k];
		 begin = LinkedContacts.begin();
		 end = LinkedContacts.end();
		 if (find(begin, end, Contact) == end)
		   LinkedContacts.push_back(Contact);
		 }
	   }
	 }

   // Dataset investigators
   for (unsigned int i=0; i<TSSForm->Datasets.size(); i++) {
	 DATASET& Dataset = TSSForm->Datasets[i];
	 for (unsigned int j=0; j<Dataset.Investigators.size(); j++) {
	   CONTACT* Contact = Dataset.Investigators[j];
	   begin = LinkedContacts.begin();
	   end = LinkedContacts.end();
	   if (find(begin, end, Contact) == end)
		 LinkedContacts.push_back(Contact);
	   }
	 }

   // Geochronology dataset investigators
   for (unsigned int i=0; i<TSSForm->GeochronDataset.Investigators.size(); i++) {
	 CONTACT* Contact = TSSForm->GeochronDataset.Investigators[i];
	 begin = LinkedContacts.begin();
	 end = LinkedContacts.end();
	 if (find(begin, end, Contact) == end)
	   LinkedContacts.push_back(Contact);
	 }

   // Dataset processors
   for (unsigned int i=0; i<TSSForm->Datasets.size(); i++) {
	 DATASET& Dataset = TSSForm->Datasets[i];
	 for (unsigned int j=0; j<Dataset.Processors.size(); j++) {
	   CONTACT* Contact = Dataset.Processors[j];
	   begin = LinkedContacts.begin();
	   end = LinkedContacts.end();
	   if (find(begin, end, Contact) == end)
		 LinkedContacts.push_back(Contact);
	   }
	 }

   // Age model preparers
   for (int i=0; i<TSSForm->AgeModelList->Count; i++) {
	 AGEMODEL* AgeModel = TSSForm->AgeModelList->AgeModels[i];
	 for (unsigned int j=0; j < AgeModel->Preparers.size(); j++) {
	   CONTACT* Contact = AgeModel->Preparers[j];
	   begin = LinkedContacts.begin();
	   end = LinkedContacts.end();
	   if (find(begin, end, Contact) == end)
		 LinkedContacts.push_back(Contact);
	   }
	 }

   // LOI investigators
   for (unsigned int i=0; i<TSSForm->loi.Investigators.size(); i++) {
	 CONTACT* Contact = TSSForm->loi.Investigators[i];
	 begin = LinkedContacts.begin();
	 end = LinkedContacts.end();
	 if (find(begin, end, Contact) == end)
	   LinkedContacts.push_back(Contact);
	 }

   // sample analysts
   //TODO: also check analysts when deleting a contact!
   int RowCount = TSSForm->ContentRowCount(TSSForm->ProfGrid1);
   int start = TSSForm->AbsHeaderColCount(TSSForm->ProfGrid1);
   int ncols = TSSForm->AbsContentColCount(TSSForm->ProfGrid1);
   for (int row=3; row<=RowCount; row++) {
	 UnicodeString Code = VarToStr(TSSForm->ProfGrid1->AbsoluteCells[1][row]->Value);
	 if (SameText(Code, L"#Samp.Analyst")) {
	   for (int col=start; col<=ncols; col++) {
		 TProfGridCell* ACell = TSSForm->ProfGrid1->AbsoluteCells[col][row];
		 UnicodeString Analyst = ACell->Text;
		 if (!Analyst.IsEmpty() && ACell->CellObject != NULL) {
		   CELLOBJECT* CellObject = (CELLOBJECT*)ACell->CellObject;
		   TList* Contacts = (TList*)CellObject->Object;
		   for (int i=0; i<Contacts->Count; i++) {
			 CONTACT* Contact = (CONTACT*)Contacts->Items[i];
			 begin = LinkedContacts.begin();
			 end = LinkedContacts.end();
			 if (find(begin, end, Contact) == end)
			   LinkedContacts.push_back(Contact);
			 }
		   }
		 }
	   }
	 }


   // TODO: need to search for duplicated contacts?? Probably not
   // TODO: probably need to check some more places for linked contacts when
   //       attempting to delete a contact!

   // Run through ContactList in reverse order
   int i = TSSForm->ContactList->Count - 1;
   while (i >= 0) {
	 CONTACT* Contact = TSSForm->ContactList->Contacts[i];
	 vector<CONTACT*>::iterator begin = LinkedContacts.begin();
	 vector<CONTACT*>::iterator end = LinkedContacts.end();
	 if (find(begin, end, Contact) == end) { // Contact not in LinkedContacts
	   UnicodeString ContactName = Contact->FullContactName;
	   OutputNote(L"NOTE: Contact «" + ContactName + L"» not linked to any metadata and not validated.");
	   }
	 i--;
	 }

   // now validate contacts
   // get Neotoma contact statuses
   //NeotomaContactStatusesTable ContactStatuses(ipsJSONS1, TcpClient1);
   NeotomaContactStatusesTable ContactStatuses(ipsJSONS1, TcpClient1);
   StatusBar1->SimpleText = ContactStatuses.WebServiceName();
   if (ContactStatuses.Execute()) {
	 if (ContactStatuses.Size() > 0) {
	   for (unsigned int i=0; i<ContactStatuses.Size(); i++) {
		 int ID = ContactStatuses.Items[i].ContactStatusID;
		 UnicodeString Status = ContactStatuses.Items[i].ContactStatus;
		 NeotomaContactStatuses[ID] = Status;
		 }
	   }
	 }
   else
	 success = false;

   if (success) {
	 unsigned int i = 0;
	 while (i < LinkedContacts.size()) {
	   bool contact_found = false;

	   // check against NeotomaContactID
	   if (LinkedContacts[i]->NeotomaContactID != -1) {
		 NeotomaContactByID NeotomaContact(ipsJSONS1, TcpClient1);
		 NeotomaContact.AddParam(L"CONTACTID", LinkedContacts[i]->NeotomaContactID);
		 StatusBar1->SimpleText = NeotomaContact.WebServiceName();
		 if (NeotomaContact.Execute()) {
		   if (NeotomaContact.Size() > 0) {
			 if (IsNeotomaContact(LinkedContacts[i], NeotomaContact.Items[0])) {
			   OutputLine(L"Contact «" + LinkedContacts[i]->FullContactName +
				 L"» validated: ContactID = " + IntToStr(LinkedContacts[i]->NeotomaContactID));
			   contact_found = true;
			   }
			 }
		   }
		 else {
		   success = false;
		   break;
		   }
		 }

	   // NeotomaContactID not set, or Tilia contact doesn't match NeotomaContactID (could have been edited)
	   if (!contact_found) {
		 if (LinkedContacts[i]->FamilyName.IsEmpty()) {
		   msg = L"No family name is entered for a contact!";
		   OutputError(L"ERROR: " + msg);
		   if (MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbIgnore << mbAbort, 0) == mrAbort) {
			 success = false;
			 break;
			 }
		   }
		 else {
		   TGetNeotomaContact* GetNeotomaContactForm = new TGetNeotomaContact(LinkedContacts[i], this);
		   int rv = GetNeotomaContactForm->ShowModal();
		   delete GetNeotomaContactForm;
		   if (rv == mrOk) {
			 OutputLine(L"Contact «" + LinkedContacts[i]->FullContactName +
			   L"» validated: ContactID = " + IntToStr(LinkedContacts[i]->NeotomaContactID));
			 contact_found = true;
			 }
		   }
	   	 }
	   if (!contact_found && !LinkedContacts[i]->FamilyName.IsEmpty()) {
		 msg = L"Contact «" + LinkedContacts[i]->FullContactName + L"» not validated";
		 int rv = MessageDlg(msg + L"!", Dialogs::mtError, TMsgDlgButtons() << mbRetry << mbIgnore << mbAbort, 0);
		 if (rv == mrIgnore) {
		   OutputError(L"ERROR:" + msg + L".");
		   i++;
		   }
		 else if (rv == mrAbort) {
		   success = false;
		   OutputError(L"ERROR:" + msg + L".");
		   break;
		   }
		 }
	   else
		 i++;
	   }   // end while
	 }

   SetProgressBar(CORE);
   if (success)
	 SetProgressBarPosition();
   Screen->Cursor = crDefault;
   StatusBar1->SimpleText = L"";
   return success;
}
//---------------------------------------------------------------------------

bool TNeotomaUploadForm::IsNeotomaContact(CONTACT* Contact, NTMCONTACT& NeotomaContact)
{
   if (Contact->NeotomaContactID != NeotomaContact.ContactID) {
	 return false;
	 }
   if (Contact->NeotomaAliasID != NeotomaContact.AliasID) {
	 return false;
	 }
   if (!SameText(Contact->Status, NeotomaContactStatuses[NeotomaContact.ContactStatusID])) {
	 return false;
	 }
   if (!SameText(Contact->FamilyName, NeotomaContact.FamilyName)) {
	 return false;
	 }
   if (!SameText(Contact->GivenNames, NeotomaContact.GivenNames)) {
	 return false;
	 }
   if (!SameText(Contact->LeadingInitials, NeotomaContact.LeadingInitials)) {
	 return false;
	 }
   if (!SameText(Contact->Suffix, NeotomaContact.Suffix)) {
	 return false;
	 }
   if (!SameText(Contact->Title, NeotomaContact.Title)) {
	 return false;
	 }
   if (!SameText(Contact->Telephone, NeotomaContact.Phone)) {
	 return false;
	 }
   if (!SameText(Contact->Fax, NeotomaContact.Fax)) {
	 return false;
	 }
   if (!SameText(Contact->Email, NeotomaContact.Email)) {
	 return false;
	 }
   if (!SameText(Contact->URL, NeotomaContact.URL)) {
	 return false;
	 }
   if (!SameText(Contact->Notes, NeotomaContact.Notes)) {
	 return false;
	 }

   UnicodeString NeotomaAddress = NeotomaContact.Address.Trim();
   Contact->Address = Contact->Address.Trim();

   int pos = Contact->Address.Pos(L"\r\n");
   while (pos > 0) {
	 Contact->Address.Delete(pos,1);
	 pos = Contact->Address.Pos(L"\r\n");
	 }
   pos = Contact->Address.Pos(L"\\r\\n");
   while (pos > 0) {
	 Contact->Address.Delete(pos,4);
	 Contact->Address.Insert(L"\n",pos);
	 pos = Contact->Address.Pos(L"\\r\\n");
	 }
   pos = NeotomaAddress.Pos(L"\r\n");
   while (pos > 0) {
	 NeotomaAddress.Delete(pos,1);
	 pos = NeotomaAddress.Pos(L"\r\n");
	 }
   pos = NeotomaAddress.Pos(L"\\r\\n");
   while (pos > 0) {
	 NeotomaAddress.Delete(pos,4);
	 NeotomaAddress.Insert(L"\n",pos);
	 pos = NeotomaAddress.Pos(L"\\r\\n");
	 }

   if (!SameText(Contact->Address, NeotomaAddress)) {
	 return false;
	 }
   return true;
}
//---------------------------------------------------------------------------

UnicodeString TNeotomaUploadForm::FormatCitation(vector<AUTHOR>& AuthorList, UnicodeString& Year)
{
   UnicodeString Citation;
   if (AuthorList.size() == 1)
	 Citation = AuthorList[0].LastName + L" (" + Year + L")";
   else if (AuthorList.size() == 2)
	 Citation = AuthorList[0].LastName + L" & " + AuthorList[1].LastName + L" (" + Year + L")";
   else if (AuthorList.size() > 2)
     Citation = AuthorList[0].LastName + L" et al. (" + Year + L")";
   return Citation;
}
//---------------------------------------------------------------------------

bool TNeotomaUploadForm::GetNeotomaPub(PUBLICATION* pub, NTMPUBLICATION& ntm_pub,
	vector<NTMAUTHOR>& ntm_authors, vector<NTMEDITOR>& ntm_editors,
	vector<NTMTRANSLATOR>& ntm_translators, bool& found)
{
   ntm_authors.clear();
   ntm_editors.clear();
   ntm_translators.clear();
   NeotomaPublicationsByPubID GetNtmPub(ipsJSONS1, TcpClient1);
   StatusBar1->SimpleText = GetNtmPub.WebServiceName();
   GetNtmPub.AddParam(L"PUBLICATIONID", pub->NeotomaID);
   Screen->Cursor = crHourGlass;
   bool success = true;
   found = false;
   if (GetNtmPub.Execute()) {
	 if (GetNtmPub.Size() > 0) {
	   ntm_pub = GetNtmPub.Items[0];
	   found = true;
	   NeotomaPublicationAuthors GetAuthors(ipsJSONS1, TcpClient1);
	   GetAuthors.AddParam(L"PUBLICATIONID", pub->NeotomaID);
	   StatusBar1->SimpleText = GetAuthors.WebServiceName();
	   if (GetAuthors.Execute()) {
		 if (GetAuthors.Size() > 0)
		   ntm_authors.assign(GetAuthors.Items.begin(), GetAuthors.Items.end());
		 }
	   else
		 success = false;

	   NeotomaPublicationEditors GetEditors(ipsJSONS1, TcpClient1);
	   GetEditors.AddParam(L"PUBLICATIONID", pub->NeotomaID);
	   StatusBar1->SimpleText = GetEditors.WebServiceName();
	   if (GetEditors.Execute()) {
		 if (GetEditors.Size() > 0)
		   ntm_editors.assign(GetEditors.Items.begin(), GetEditors.Items.end());
		 }
	   else
		 success = false;

	   NeotomaPublicationTranslators GetTranslators(ipsJSONS1, TcpClient1);
	   GetTranslators.AddParam(L"PUBLICATIONID", pub->NeotomaID);
	   StatusBar1->SimpleText = GetTranslators.WebServiceName();
	   if (GetTranslators.Execute()) {
		 if (GetTranslators.Size() > 0)
		   ntm_translators.assign(GetTranslators.Items.begin(), GetTranslators.Items.end());
		 }
	   else
		 success = false;
	   }
	 }
   else
	 success = false;

   Screen->Cursor = crDefault;
   return success;
}
//---------------------------------------------------------------------------

bool TNeotomaUploadForm::SamePub(PUBLICATION *pub, NTMPUBLICATION& ntm_pub,
	vector<NTMAUTHOR>& ntm_authors, vector<NTMEDITOR>& ntm_editors,
	vector<NTMTRANSLATOR>& ntm_translators, bool& AuthorMatch, bool& YearMatch)
{
   bool PubTypeMatch = (pub->pub_type == ntm_pub.PubTypeID);
   YearMatch = SameText(pub->PublicationYear, ntm_pub.Year);
   AuthorMatch = false;
   if (pub->AuthorList.size() != ntm_authors.size())
	 return false;
   sort(ntm_authors.begin(), ntm_authors.end(), ntm_author_comp);
   for (unsigned int i=0; i<ntm_authors.size(); i++) {
	 if (!SameText(pub->AuthorList[i].LastName, ntm_authors[i].FamilyName))
	   return false;
	 if (!SameText(pub->AuthorList[i].Initials, ntm_authors[i].Initials))
	   return false;
	 if (!SameText(pub->AuthorList[i].Suffix, ntm_authors[i].Suffix))
	   return false;
	 pub->AuthorList[i].NeotomaContactID = ntm_authors[i].ContactID;
	 }
   AuthorMatch = true;
   if (!PubTypeMatch) return false;

   if (pub->EditorList.size() != ntm_editors.size())
	 return false;
   if (pub->EditorList.size() > 0) {
	 sort(ntm_editors.begin(), ntm_editors.end(), ntm_editor_comp);
	 for (unsigned int i=0; i<ntm_editors.size(); i++) {
	   if (!SameText(pub->EditorList[i].LastName, ntm_editors[i].FamilyName))
		 return false;
	   if (!SameText(pub->EditorList[i].Initials, ntm_editors[i].Initials))
		 return false;
	   if (!SameText(pub->EditorList[i].Suffix, ntm_editors[i].Suffix))
		 return false;
	   }
	 }

   if (pub->TranslatorList.size() != ntm_translators.size())
	 return false;
   if (pub->TranslatorList.size() > 0) {
	 sort(ntm_translators.begin(), ntm_translators.end(), ntm_translator_comp);
	 for (unsigned int i=0; i<ntm_translators.size(); i++) {
	   if (!SameText(pub->TranslatorList[i].LastName, ntm_translators[i].FamilyName))
		 return false;
	   if (!SameText(pub->TranslatorList[i].Initials, ntm_translators[i].Initials))
		 return false;
	   if (!SameText(pub->TranslatorList[i].Suffix, ntm_translators[i].Suffix))
		 return false;
	   }
	 }

   if (!SameText(pub->Title, ntm_pub.ArticleTitle))
	 return false;
   if (!SameText(pub->Journal, ntm_pub.Journal))
	 return false;
   if (!SameText(pub->Volume, ntm_pub.Volume))
	 return false;
   if (!SameText(pub->Issue, ntm_pub.Issue))
	 return false;
   if (!SameText(pub->Pages, ntm_pub.Pages))
	 return false;
   if (!SameText(pub->CitationNumber, ntm_pub.CitationNumber))
	 return false;
   if (!SameText(pub->DOI, ntm_pub.DOI))
	 return false;
   if (!SameText(pub->BookTitle, ntm_pub.BookTitle))
	 return false;
   if (!SameText(pub->Edition, ntm_pub.Edition))
	 return false;
   if (!SameText(pub->NumVolumes, ntm_pub.NumVolumes))
	 return false;
   if (!SameText(pub->VolumeTitle, ntm_pub.VolumeTitle))
	 return false;
   if (!SameText(pub->SeriesTitle, ntm_pub.SeriesTitle))
	 return false;
   if (!SameText(pub->SeriesNumber, ntm_pub.SeriesVolume))
	 return false;
   switch (pub->pub_type) {
	 case DOCTORAL_THESIS:
	 case MASTERS_THESIS:
	 case UNDERGRAD_THESIS:
	   if (!SameText(pub->University, ntm_pub.Publisher))
		 return false;
	   break;
	 default:
	   if (!SameText(pub->Publisher, ntm_pub.Publisher))
		 return false;
	   break;
	 }
   if (!SameText(pub->City, ntm_pub.City))
	 return false;
   if (!SameText(pub->State, ntm_pub.State))
	 return false;
   if (!SameText(pub->Country, ntm_pub.Country))
	 return false;
   if (!SameText(pub->URL, ntm_pub.URL))
	 return false;
   if (!SameText(pub->OrigLang, ntm_pub.OriginalLanguage))
	 return false;
   if (!SameText(pub->Notes, ntm_pub.Notes))
	 return false;
   return true;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

__fastcall TNeotomaTaxaValidationForm::TNeotomaTaxaValidationForm(TComponent* Owner)
	: TNeotomaUploadForm(Owner)
{
   cxButton2->Visible = false;
   Caption = L"Validate Taxa Names";
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaTaxaValidationForm::FormCreate(TObject *Sender)
{
   Step = 0;
   nSteps = 5;
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaTaxaValidationForm::FormActivate(TObject *Sender)
{
   if (!Activated) {
	 Activated = true;
	 Validate();
	 }
}
//---------------------------------------------------------------------------

void TNeotomaTaxaValidationForm::Validate(void)
{
   if (!RunValidation())
	 OutputError(L"VALIDATION ABORTED");
   cxButton3->Visible = true;
   cxButton1->Visible = true;
   cxButton4->Visible = true;
   SetProgressBar(CORE);
}
//---------------------------------------------------------------------------

bool TNeotomaTaxaValidationForm::RunValidation(void)
{
   // get list of taxa with row numbers
   if (GetVariables() ==  mrAbort)
	 return false;
   if (VarErrors)
	 return false;
   if (!ValidateTaxa())
	 return false;
   NewMessages.SetMessages(TotalMessages, ArchiveMessages);
   OutputBoldLine(L"Taxon validation completed: " + ValidationMsg(NewMessages));
   StatusBar1->SimpleText = L"";
   return true;
}
//---------------------------------------------------------------------------

// This routine is for Validate Taxa, not Validate and Upload Data
int TNeotomaTaxaValidationForm::CheckTaxaNames(NeotomaTaxaBase& Taxa)
{
   vector<void*> vptrs;
   short SubVarCodes;

   NeotomaValidateTaxaForm = new TNeotomaValidateTaxaForm(this);
   int rv = NeotomaValidateTaxaForm->ShowModal();
   if (rv == mrOk)
	 SubVarCodes = NeotomaValidateTaxaForm->SubVarCodes;
   delete NeotomaValidateTaxaForm;
   if (rv == mrCancel)
	 return mrAbort;

   for (unsigned int i=0; i<SSVarList.size(); i++) {
	 int SSRow = SSVarList[i].row;
	 UnicodeString SSTaxonName = SSVarList[i].name;
	 UnicodeString SSTaxonAuth = SSVarList[i].author;
	 int count = Taxa.Find("TaxonName", SSTaxonName, vptrs);
	 if (count == 0)
	   TaxaNotFound.push_back(SSTAXANAME(SSTaxonName, SSTaxonAuth, SSRow));
	 else if (count == 1) {
	   TAXONRECORD* TaxonRec = (TAXONRECORD*)vptrs[0];
	   NEOTOMAVARIABLE NeotomaVariable;
	   NeotomaVariable.TaxonID = TaxonRec->TaxonID;
	   NeotomaVariable.TaxonName = SSTaxonName;
	   NeotomaVariables[SSRow] = NeotomaVariable;
	   switch (SubVarCodes) {
		 case SUBALL:
		   TSSForm->ProfGrid1->AbsoluteCells[1][SSRow]->Value = TaxonRec->TaxonCode;
		   break;
		 case SUBBLANK:
		   if (TSSForm->ProfGrid1->AbsoluteCells[1][SSRow]->IsEmpty())
			 TSSForm->ProfGrid1->AbsoluteCells[1][SSRow]->Value = TaxonRec->TaxonCode;
		   break;
		 }
	   }
	 else if (count > 1) {  // taxon with same name in more than one TaxaGroup
	   bool authfound = false;
	   for (unsigned int j=0; j<vptrs.size(); j++) {
		 TAXONRECORD* TaxonRec = (TAXONRECORD*)vptrs[j];
		 if (SameText(SSTaxonAuth,TaxonRec->Author)) {
		   NEOTOMAVARIABLE NeotomaVariable;
		   NeotomaVariable.TaxonID = TaxonRec->TaxonID;
		   NeotomaVariable.TaxonName = SSTaxonName;
		   NeotomaVariables[SSRow] = NeotomaVariable;
		   switch (SubVarCodes) {
			 case SUBALL:
			   TSSForm->ProfGrid1->AbsoluteCells[1][SSRow]->Value = TaxonRec->TaxonCode;
			   break;
			 case SUBBLANK:
			   if (TSSForm->ProfGrid1->AbsoluteCells[1][SSRow]->IsEmpty())
				 TSSForm->ProfGrid1->AbsoluteCells[1][SSRow]->Value = TaxonRec->TaxonCode;
			   break;
			 }
		   authfound = true;
		   break;
		   }
		 }

	   if (!authfound) {
		 if (!GetTaxaGroups())
		   return mrAbort;
		 vector<UnicodeString> TaxaGroupNames;
		 for (unsigned int j=0; j<vptrs.size(); j++) {
		   TAXONRECORD* TaxonRec = (TAXONRECORD*)vptrs[j];
		   UnicodeString TaxaGroupID = TaxonRec->TaxaGroupID;  // convert from Variant
		   if (NeotomaTaxaGroups.count(TaxaGroupID) > 0)
			 TaxaGroupNames.push_back(NeotomaTaxaGroups[TaxaGroupID]);
		   }
		 TMultiTaxonNamesForm* MultiTaxonNamesForm = new TMultiTaxonNamesForm(TSSForm);
		 MultiTaxonNamesForm->FillMultiTaxonNames(SSRow, SSTaxonName, TaxaGroupNames);
		 rv = MultiTaxonNamesForm->ShowModal();
		 if (rv == mrOk) {
		   TAXONRECORD* TaxonRec = (TAXONRECORD*)vptrs[MultiTaxonNamesForm->ItemChecked];
		   NEOTOMAVARIABLE NeotomaVariable;
		   NeotomaVariable.TaxonID = TaxonRec->TaxonID;
		   NeotomaVariable.TaxonName = SSTaxonName;
		   NeotomaVariables[SSRow] = NeotomaVariable;
		   UnicodeString TaxaGroupID = TaxonRec->TaxaGroupID;
		   OutputLine(L"Taxon «" + SSTaxonName + L"» assigned to Taxa Group «" + NeotomaTaxaGroups[TaxaGroupID] + L"».");
		   }
		 else if (rv == mrIgnore)
		   OutputError(L"ERROR: Taxon Group not resolved for taxon «" + SSTaxonName + L"».");
	     delete MultiTaxonNamesForm;
		 }
	   }
	 }


   SetProgressBarPosition();
   return rv;
}
//---------------------------------------------------------------------------

