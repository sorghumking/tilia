//---------------------------------------------------------------------------

#include <vcl.h>
#include "pch.h"
#pragma hdrstop

#include "TNUpdNtm.h"
#ifndef TGParentH
#include "TGParent.h"
#endif
#ifndef TISpreadH
#include "TISpread.h"
#endif
#ifndef TIGlobalsH
#include "TIGlobals.h"
#endif
#ifndef TNLoginH
#include "TNLogin.h"
#endif
#ifndef TINeotomaH
#include "TINeotoma.h"
#endif
#ifndef TIJSONH
#include "TIJSON.h"
#endif
#ifndef TNUpdSitH
#include "TNUpdSit.h"
#endif
#ifndef TUpUtilsH
#include "TUpUtils.h"
#endif
#ifndef TNConfElmH
#include "TNConfElm.h"
#endif
#ifndef TNUtilsH
#include "TNUtils.h"
#endif
#ifndef TNVerAnUnH
#include "TNVerAnUn.h"
#endif
#ifndef TICommonH
#include "TICommon.h"
#endif

#pragma hdrstop

//---------------------------------------------------------------------------

#pragma package(smart_init)

// update site lat-long coordinates
void __fastcall TTilSpreadSheetForm::cxButton28Click(TObject *Sender)
{
   UnicodeString msg, ErrorMsg;

   if (SitePtr == NULL) {
	 Beep();
	 return;
	 }

   // Check site lat/long coordinates
   vector<UnicodeString> Errors;
   if (cxRadioButton1->Checked) {     // point coordinate
	 if (SitePtr->LatNorth.IsEmpty())
	   Errors.push_back(L"Site latitude missing.");
	 else if (SitePtr->LatNorth > 90.0 || SitePtr->LatNorth < -90.0)
	   Errors.push_back(L"Latitude " + SitePtr->LatNorth.AsType(varOleStr) +
				   L" is not valid. Must be in the range -90.0 to 90.0.");
	 if (SitePtr->LongWest.IsEmpty())
	   Errors.push_back(L"Site longitude missing.");
	 }
   else {      // box coordinates
	 if (SitePtr->LatNorth.IsEmpty() || SitePtr->LatSouth.IsEmpty())
	   Errors.push_back(L"Site latitude missing.");
	 else if (SitePtr->LatNorth < SitePtr->LatSouth)
	   Errors.push_back(L"Site south latitude is greater than north latitude.");
	 if (SitePtr->LongWest.IsEmpty() || SitePtr->LongEast.IsEmpty())
	   Errors.push_back(L"Site longitude missing.");
	 else if (SitePtr->LongWest > SitePtr->LongEast)
	   Errors.push_back(L"Site west longitude is greater than east longitude.");
	 }
   if (Errors.size() > 0) {
	 msg = L"Errors in latitude-longitude coordinates. Cannot update.";
	 msg += L"\n";
	 for (unsigned int i=0; i<Errors.size(); i++)
	   msg += L"\n" + Errors[i];
	 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 return;
	 }

   msg = L"Update latitude-longitude coordinates for «" +
	 SitePtr->SiteName + L"», SiteID = " + IntToStr(SitePtr->NeotomaSiteID) + L"?";
   if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) != mrYes)
	 return;

   if (!Login->IsLoggedIn) {
	 NeotomaLoginForm = new TNeotomaLoginForm(this);
	 NeotomaLoginForm->ShowModal();
	 delete NeotomaLoginForm;
	 }
   if (!Login->IsLoggedIn)
	 return;

   Screen->Cursor = crHourGlass;
   UpdateData UpdateLatLon(L"UpdateSiteLatLon", 6, ipsHTTPS1, ipsJSONS1, TcpClient1);
   ParentForm->StatusBar1->Panels->Items[0]->Text = "UpdateSiteLatLon";
   UpdateLatLon.Add(L"SITEID", SitePtr->NeotomaSiteID);
   UpdateLatLon.Add(L"STEWARDCONTACTID", Login->ContactID);
   UpdateLatLon.AddDouble(L"EAST", SitePtr->LongEast);
   UpdateLatLon.AddDouble(L"NORTH", SitePtr->LatNorth);
   UpdateLatLon.AddDouble(L"WEST", SitePtr->LongWest);
   UpdateLatLon.AddDouble(L"SOUTH", SitePtr->LatSouth);

   if (UpdateLatLon.Post(ErrorMsg))
	 MessageDlg(L"Success! Site latitude-longitude updated.", mtInformation, TMsgDlgButtons() << mbOK, 0);
   else if (!ErrorMsg.IsEmpty())
	 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);

   ParentForm->StatusBar1->Panels->Items[0]->Text = "";
   Screen->Cursor = crDefault;
}
//---------------------------------------------------------------------------

// update site metadata
void __fastcall TTilSpreadSheetForm::cxButton29Click(TObject *Sender)
{
   if (SitePtr == NULL) {
	 Beep();
	 return;
	 }
   UpdateNeotomaSiteForm = new TUpdateNeotomaSiteForm(SitePtr, false, this);
   UpdateNeotomaSiteForm->ShowModal();
   delete UpdateNeotomaSiteForm;
   FillSiteMetaData(SitePtr);
}
//---------------------------------------------------------------------------

// update collection unit metadata
void __fastcall TTilSpreadSheetForm::cxButton30Click(TObject *Sender)
{
   if (!GetCollPtr())
	 return;
   UpdateNeotomaCollUnitForm = new TUpdateNeotomaCollUnitForm(SitePtr, CollPtr, false, this);
   UpdateNeotomaCollUnitForm->ShowModal();
   delete UpdateNeotomaCollUnitForm;
}
//---------------------------------------------------------------------------

// update dataset metadata
void __fastcall TTilSpreadSheetForm::cxButton23Click(TObject *Sender)
{
   int dataset_num = DatasetTabsheetNum();
   UpdateNeotomaDatasetForm = new TUpdateNeotomaDatasetForm(SitePtr, &Datasets[dataset_num], false, this);
   UpdateNeotomaDatasetForm->ShowModal();
   delete UpdateNeotomaDatasetForm;
}
//---------------------------------------------------------------------------

bool TTilSpreadSheetForm::GetCollPtr(void)
{
   if (SitePtr == NULL) {
	 return false;
	 }

   bool DefaultSite = false;
   int site_row = FindRowMD(SITE_NAME);
   if (Sites->Count == 1) { // default single site
	 if (site_row == 0)      // single site, no #Site.Name in SS
	   DefaultSite = true;
	 }

   int SSCol = ProfGrid1->Col;
   if (ProfGrid1->Selection->Count > 1)
	 SSCol = ProfGrid1->Selection->Rect.Left;

   int coll_row = FindRowMD(COLL_UNIT_NAME);
   if (DefaultSite && coll_row == 0) {
	 // default single site with no SS collection units
	 CollPtr = &SitePtr->CollUnits[0];
	 }
   else if (coll_row > 0) {
	 // either default single site or multi-site with SS collection units
	 UnicodeString CollName = ProfGrid1->Cells[SSCol][coll_row]->Text;
	 if (!CollName.IsEmpty()) {
	   for (unsigned int i=1; i<SitePtr->CollUnits.size(); i++) {
		 if (SameText(CollName, SitePtr->CollUnits[i].CollectionName)) {
		   CollPtr = &SitePtr->CollUnits[i];
		   break;
		   }
		 }
	   }
	 }
   else {  // multi-site with no SS collection units
	 Beep();
	 return false;
	 }

   return true;
}
//---------------------------------------------------------------------------

int TTilSpreadSheetForm::GetSSDownloadVariableID(int ARow)
{
   int VariableID = -1;
   UnicodeString VarCode = ProfGrid1->AbsoluteCells[1][ARow]->Text;
   if (!VarCode.IsEmpty() && VarCode[1] != L'#' && !ProfGrid1->AbsoluteCells[1][ARow]->CustomData.IsEmpty()) {
	 VariableID = ProfGrid1->AbsoluteCells[1][ARow]->CustomData;
	 }
   return VariableID;
}
//---------------------------------------------------------------------------

bool TTilSpreadSheetForm::ValidateSteward(int& DatasetIdx)
{
   bool steward = false;
   if (tiLicense->Type() == verNEOTOMASTEWARD) {
	 DatasetIdx = GetCurrentDataset(ProfGrid1->Row);
	 if (DatasetIdx > -1) {
	   int NeotomaDatasetID = Datasets[DatasetIdx].NeotomaDatasetID;
	   NeotomaDatasetDatabase Databases(ipsJSONS1, TcpClient1);
	   Databases.AddParam(L"DATASETID", NeotomaDatasetID);
	   if (Databases.Execute()) {
		 if (Databases.Size() == 0)
		   return false;
		 }
	   else
		 return false;

	   if (Databases.Items.count(11) == 0)
		 Databases.Items[11] = L"Neotoma";

	   if (!Login->IsLoggedIn) {
		 NeotomaLoginForm = new TNeotomaLoginForm(this);
		 NeotomaLoginForm->ShowModal();
		 delete NeotomaLoginForm;
		 }
	   if (Login->IsLoggedIn) {
		 if (Databases.Items.count(Login->DatabaseID) > 0)
		   steward = true;
		 else {
		   UnicodeString msg = L"You are not validated to edit this dataset.";
		   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   }
		 }
	   }
	 }
   return steward;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::UpdateVariable1Click(TObject *Sender)
{
   UnicodeString msg;
   UnicodeString ErrorMsg;

   int NeotomaVariableID;
   NEOTOMAVARIABLEPARTS DownloadVariable;
   NEOTOMAVARIABLEPARTS Variable;
   int DatasetIdx;

   if (!ValidateSteward(DatasetIdx))
	 return;

   NeotomaVariableID = GetSSDownloadVariableID(ProfGrid1->Row);
   if (NeotomaVariableID == -1)
	 return;

   int NeoetomaDatasetID = Datasets[DatasetIdx].NeotomaDatasetID;

   try {
	 Screen->Cursor = crHourGlass;

	 // get parts for NeotomaVariableID
	 if (!GetNeotomaVariableParts(NeotomaVariableID, DownloadVariable))
	   return;

	 int row = ProfGrid1->Row;

	 // get current spreadsheet variable and see if different from downloaded one
	 if (!IsNewVariable(row, DownloadVariable, Variable))
	   return;

	 // get the Neotoma VariableID for the new variable
	 if (!GetVariableID(Variable, DatasetIdx, true))
	   return;

	 // Update variable!
	 // UpdateDataVariable (@DATASETID int, @OLDVARIABLEID int, @NEWVARIABLEID int, @CONTACTID int
	 //UpdateData UpdateVariable(L"UpdateDataVariable", 4, ipsHTTPS1, ipsJSONS1, TcpClient1);
	 UpdateData UpdateVariable(L"UpdateDataVariable", 3, ipsHTTPS1, ipsJSONS1, TcpClient1);
	 ParentForm->StatusBar1->Panels->Items[0]->Text = L"UpdateDataVariable";
	 UpdateVariable.Add(L"DATASETID", NeoetomaDatasetID);
	 UpdateVariable.Add(L"OLDVARIABLEID", NeotomaVariableID);
	 UpdateVariable.Add(L"NEWVARIABLEID", Variable.VariableID);
	 //UpdateVariable.Add(L"CONTACTID", Login->ContactID);
	 if (UpdateVariable.Post(ErrorMsg)) {
	   if (!SameText(Variable.TaxonName, DownloadVariable.TaxonName)) {
		 ProfGrid1->AbsoluteCells[1][row]->Color = TColor(0x00B4E0C6);  // light green
		 ProfGrid1->AbsoluteCells[2][row]->Color = TColor(0x00B4E0C6);  // light green
		 ProfGrid1->AbsoluteCells[7][row]->Color = TColor(0x00B4E0C6);  // light green
		 }
	   if (!SameText(Variable.Element, DownloadVariable.Element))
		 ProfGrid1->AbsoluteCells[3][row]->Color = TColor(0x00B4E0C6);  // light green
	   if (!SameText(Variable.Units, DownloadVariable.Units))
		 ProfGrid1->AbsoluteCells[4][row]->Color = TColor(0x00B4E0C6);  // light green
	   if (!SameText(Variable.Context, DownloadVariable.Context))
		 ProfGrid1->AbsoluteCells[5][row]->Color = TColor(0x00B4E0C6);  // light green
	   msg = L"VariableID " + IntToStr(NeotomaVariableID) + L" in DatasetID " +
			 IntToStr(NeoetomaDatasetID) + L" updated to " + IntToStr(Variable.VariableID) + L".";
	   MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
	   }
	 else if (!ErrorMsg.IsEmpty()) {
	   msg = ErrorMsg + L"\nVariable not updated.";
	   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   }
	 }
   __finally {
	 Screen->Cursor = crDefault;
	 ParentForm->StatusBar1->Panels->Items[0]->Text = L"";
	 }
}
//---------------------------------------------------------------------------

bool TTilSpreadSheetForm::GetNeotomaVariableParts(int NeotomaVariableID, NEOTOMAVARIABLEPARTS& Variable)
{
   NeotomaVariableTextByID DownloadVariable(ipsJSONS1, TcpClient1);
   DownloadVariable.AddParam(L"VARIABLEID", NeotomaVariableID);
   ParentForm->StatusBar1->Panels->Items[0]->Text = DownloadVariable.WebServiceName();
   if (DownloadVariable.Execute()) {
	 if (DownloadVariable.Size() > 0) {
	   Variable.TaxonName = DownloadVariable.Items[0].TaxonName;
	   Variable.Element = DownloadVariable.Items[0].VariableElement;
	   Variable.Units = DownloadVariable.Items[0].VariableUnits;
	   Variable.Context = DownloadVariable.Items[0].VariableContext;
	   }
	 else {  // this should probably never happen, but...
	   UnicodeString msg = L"ERROR: VariableID " + IntToStr(NeotomaVariableID) + L" does not exist in Neotoma!";
	   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return false;
	   }
	 }
   else
	 return false;
   return true;
}
//---------------------------------------------------------------------------

bool TTilSpreadSheetForm::IsNewVariable(int ARow, NEOTOMAVARIABLEPARTS& DownloadVariable,
	NEOTOMAVARIABLEPARTS& Variable)
{
   GetSSVariable(ARow, Variable);
   // compare variable to that in spreadsheet
   if (SameText(Variable.TaxonName, DownloadVariable.TaxonName) &&
	   SameText(Variable.Element, DownloadVariable.Element) &&
	   SameText(Variable.Units, DownloadVariable.Units) &&
	   SameText(Variable.Context, DownloadVariable.Context))  {
	 UnicodeString msg = L"Variable unchanged. No update necessary.";
	 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
	 return false;
	 }
   return true;
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::GetSSVariable(int ARow, NEOTOMAVARIABLEPARTS& Variable)
{
   Variable.TaxonName = ProfGrid1->AbsoluteCells[2][ARow]->Text;
   Variable.Element = ProfGrid1->AbsoluteCells[3][ARow]->Text;
   Variable.Units = ProfGrid1->AbsoluteCells[4][ARow]->Text;
   Variable.Context = ProfGrid1->AbsoluteCells[5][ARow]->Text;

   // correct formatting of element if necessary
   UnicodeString CurrentElement = Variable.Element;
   CheckElementFormat(Variable.Element);
   if (Variable.Element != CurrentElement)
	 ProfGrid1->AbsoluteCells[3][ARow]->Value = Variable.Element;
}
//---------------------------------------------------------------------------

bool TTilSpreadSheetForm::GetVariableID(NEOTOMAVARIABLEPARTS& Variable, int DatasetIdx,
	bool show_message)
{
   UnicodeString msg, ErrorMsg;

   int NeotomaDatasetTypeID = Datasets[DatasetIdx].NeotomaDatasetTypeID;
   UnicodeString NeotomaDatasetType = Datasets[DatasetIdx].DatasetType;

   // get TaxonID
   if ((!GetTaxonID(Variable)))
	 return false;

   // get ElementID
   if (!GetVariableElementID(Variable))
	 return false;

   // get companion dataset types
   // this will return DatasetTypeIDs for e.g. "pollen" and "pollen surface sample"
   vector<int> DatasetTypeIDs;
   if (!GetCompanionDatasetTypes(NeotomaDatasetType, DatasetTypeIDs))
	 return false;

   // Get UnitsID
   if (!GetVariableUnitsID(Variable, NeotomaDatasetTypeID, DatasetTypeIDs))
	 return false;

	 // get ContextID
   if (!GetVariableContextID(Variable, NeotomaDatasetTypeID, DatasetTypeIDs))
	 return false;

   // now validate complete variables and assign VariableIDs
   NeotomaVariableByComponents NeotomaVariable(ipsJSONS1, TcpClient1);
   NeotomaVariable.AddParam(L"TAXONID", Variable.TaxonID);
   if (Variable.ElementID > -1)
	 NeotomaVariable.AddParam(L"VARIABLEELEMENTID", Variable.ElementID);
   if (Variable.UnitsID > -1)
	 NeotomaVariable.AddParam(L"VARIABLEUNITSID", Variable.UnitsID);
   if (Variable.ContextID > -1)
	 NeotomaVariable.AddParam(L"VARIABLECONTEXTID", Variable.ContextID);
   ParentForm->StatusBar1->Panels->Items[0]->Text = NeotomaVariable.WebServiceName();
   if (NeotomaVariable.Execute()) {
	 if (NeotomaVariable.Size() == 1) {
	   Variable.VariableID = NeotomaVariable.Items[0].VariableID;
	   if (show_message) {
		 msg = L"Variable validated: VariableID = " + IntToStr(Variable.VariableID) +
			   ", «" + Variable.TaxonName + L"», TaxonID = " + IntToStr(Variable.TaxonID);
		 if (Variable.ElementID > -1)
		   msg += (L", ElementID = " + IntToStr(Variable.ElementID));
		 if (Variable.UnitsID > -1)
		   msg += (L", UnitsID = " + IntToStr(Variable.UnitsID));
		 if (Variable.ContextID > -1)
		   msg += (L", ContextID = " + IntToStr(Variable.ContextID));
		 msg += L".";
		 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
		 }
	   }
	 else if (NeotomaVariable.Size() > 1) { // database error: more than one variable with same components
	   msg = L"DATABASE ERROR: Database has multiple entries of the same variable!";
	   msg += L"VariableID: ";
	   for (unsigned int i=0; i<NeotomaVariable.Size(); i++) {
		 if (i > 0)
		   msg += L", ";
		 IntToStr(NeotomaVariable.Items[i].VariableID);
		 }
	   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return false;
	   }
	 else {  // new variable
	   vector<int> newids;
	   InsertData InsertVariable(L"InsertVariable", 4, ipsHTTPS1, ipsJSONS1, TcpClient1);
	   InsertVariable.Add(L"TAXONID", Variable.TaxonID);
	   InsertVariable.Add(L"VARIABLEELEMENTID", Variable.ElementID, -1);
	   InsertVariable.Add(L"VARIABLEUNITSID", Variable.UnitsID, -1);
	   InsertVariable.Add(L"VARIABLECONTEXTID", Variable.ContextID, -1);
	   ParentForm->StatusBar1->Panels->Items[0]->Text = L"InsertVariable";
	   InsertVariable.PostData();
	   if (InsertVariable.Post(newids, ErrorMsg)) {
		 if (newids.size() == 1) {
		   Variable.VariableID = newids[0];
		   msg = L"New variable uploaded: VariableID = " + IntToStr(Variable.VariableID) +
				 ", «" + Variable.TaxonName + L"», TaxonID = " + IntToStr(Variable.TaxonID);
		   if (Variable.ElementID > -1)
			 msg += (L", ElementID = " + IntToStr(Variable.ElementID));
		   if (Variable.UnitsID > -1)
			 msg += (L", UnitsID = " + IntToStr(Variable.UnitsID));
		   if (Variable.ContextID > -1)
			 msg += (L", ContextID = " + IntToStr(Variable.ContextID));
		   msg += L".";
		   MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
		   }
		 else {
		   ErrorMsg = L"Error inserting into Variables table!";
		   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   return false;
		   }
		 }
	   else  {
		 return false;
		 }
	   }
	 }
   else
	 return false;

   return true;
}
//---------------------------------------------------------------------------

bool TTilSpreadSheetForm::GetTaxonID(NEOTOMAVARIABLEPARTS& Variable)
{
   TaxonByName NeotomaTaxon(ipsJSONS1, TcpClient1);
   NeotomaTaxon.AddParam(L"TAXONNAME", Variable.TaxonName);
   ParentForm->StatusBar1->Panels->Items[0]->Text = NeotomaTaxon.WebServiceName();
   if (NeotomaTaxon.Execute()) {
	 if (NeotomaTaxon.Size() > 0)
	   Variable.TaxonID = NeotomaTaxon.Items[0].TaxonID;
	 else {
	   UnicodeString msg = L"Taxon «" + Variable.TaxonName + L"» is not in Neotoma!";
	   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return false;
	   }
	 }
   else
	 return false;
   return true;
}
//---------------------------------------------------------------------------

bool TTilSpreadSheetForm::GetVariableElementID(NEOTOMAVARIABLEPARTS& Variable)
{
   UnicodeString msg, ErrorMsg;

   if (!Variable.Element.IsEmpty()) {
   SSELEMENT sselement(Variable.Element);
   NeotomaGetVariableElementByName VariableElement(ipsJSONS1, TcpClient1);
   VariableElement.AddParam(L"VARIABLEELEMENT", Variable.Element);
   ParentForm->StatusBar1->Panels->Items[0]->Text = VariableElement.WebServiceName();
   if (VariableElement.Execute()) {
	 if (VariableElement.Size() > 0) {
	   sselement.VariableElementID = VariableElement.Items[0].VariableElementID;
	   sselement.ElementTypeID = VariableElement.Items[0].ElementTypeID;
	   sselement.SymmetryID = VariableElement.Items[0].SymmetryID;
	   sselement.PortionID = VariableElement.Items[0].PortionID;
	   sselement.MaturityID = VariableElement.Items[0].MaturityID;
	   }
	 }
   else
	 return false;

   if (sselement.VariableElementID == -1) {  // element combination does not exist in Neotoma
	 // parse out ElementType
	 map<UnicodeString,NEOTOMAELEMENTPARTIDS> ElementParts;

	 NeotomaElementTypeFromVariableElement ElementType(ipsJSONS1, TcpClient1);
	 ElementType.AddParam(L"VARIABLEELEMENT", sselement.Element);
	 ParentForm->StatusBar1->Panels->Items[0]->Text = ElementType.WebServiceName();
	 if (ElementType.Execute()) {
	   if (ElementType.Size() == 1) {
		 sselement.ElementTypeID = ElementType.Items.begin()->first;
		 UnicodeString element = sselement.Element;
		 UnicodeString element_type = ElementType.Items.begin()->second;
		 element.Delete(1,element_type.Length()+1);
		 element = element.TrimLeft();
		 sselement.ParseParts(element);
		 set<UnicodeString>::iterator itr;
		 for (itr = sselement.parts.begin(); itr != sselement.parts.end(); itr++) {
		   if (ElementParts.count(*itr) == 0) {
			 NEOTOMAELEMENTPARTIDS part;
			 part.SymmetryID = -1;
			 part.PortionID = -1;
			 part.MaturityID = -1;
			 ElementParts[*itr] = part;
			 }
		   }
		 }
	   else { // ElementType not found
		 msg = L"Element «" + sselement.Element + L"» not in Neotoma!";
		 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 return false;
		 }
	   }
	 else
	   return false;

	 // third pass: parse symmetry, portion, and maturity parts already in Neotoma
	 map<UnicodeString,NEOTOMAELEMENTPARTIDS>::iterator pitr;
	 for (pitr = ElementParts.begin(); pitr != ElementParts.end(); pitr++) {
	   UnicodeString PartName = pitr->first;
	   NeotomaGetElementPartID ElementPart(ipsJSONS1, TcpClient1);
	   ElementPart.AddParam(L"PARTNAME", PartName);
	   ParentForm->StatusBar1->Panels->Items[0]->Text = ElementPart.WebServiceName();
	   if (ElementPart.Execute()) {
		 if (ElementPart.Size() == 1) {
		   pitr->second.SymmetryID = ElementPart.Items[0].SymmetryID;
		   pitr->second.PortionID = ElementPart.Items[0].PortionID;
		   pitr->second.MaturityID = ElementPart.Items[0].MaturityID;
		   }
		 }
	   else
		 return false;
	   }

	 if (!sselement.Element.IsEmpty()) {
	   if (sselement.VariableElementID == -1) {
		 set<UnicodeString> parts = sselement.parts;
		 set<UnicodeString>::iterator itr;
		 for (itr = parts.begin(); itr != parts.end(); itr++) {
		   UnicodeString PartName = *itr;
		   if (ElementParts[PartName].SymmetryID > -1) {
			 sselement.SymmetryID = ElementParts[PartName].SymmetryID;
			 sselement.parts.erase(PartName);
			 }
		   else if (ElementParts[PartName].PortionID > -1) {
			 sselement.PortionID = ElementParts[PartName].PortionID;
			 sselement.parts.erase(PartName);
			 }
		   else if (ElementParts[PartName].MaturityID > -1) {
			 sselement.MaturityID = ElementParts[PartName].MaturityID;
			 sselement.parts.erase(PartName);
			 }
		   }

		 // If all parts are accounted for, set the VariableElementID.
		 // Otherwise, upload any new parts, then set the VariableElementID

		 if (sselement.parts.size() == 0) {
		   NeotomaVariableElementByPartIDs VarElement(ipsJSONS1, TcpClient1);
		   VarElement.AddParam(L"ELEMENTTYPEID", sselement.ElementTypeID);
		   VarElement.AddParam(L"SYMMETRYID", sselement.SymmetryID);
		   VarElement.AddParam(L"PORTIONID", sselement.PortionID);
		   VarElement.AddParam(L"MATURITYID", sselement.MaturityID);
		   ParentForm->StatusBar1->Panels->Items[0]->Text = VarElement.WebServiceName();
		   if (VarElement.Execute()) {
			 if (VarElement.Size() > 0)
			   sselement.VariableElementID = VarElement.Items[0];
			 else {
			   if (sselement.ElementTypeID == -1)    // this should never happen, but...
				 return false;

			   // get list of taxa with this element
			   vector<UnicodeString> TaxaNames;
			   TaxaNames.push_back(Variable.TaxonName);
			   ConfirmElementUploadForm = new TConfirmElementUploadForm(sselement.Element, TaxaNames, this);
			   Screen->Cursor = crDefault;
			   if (!ConfirmElementUploadForm->ShowModal())
				 return false;

			   // upload new variable element
			   Screen->Cursor = crHourGlass;
			   vector<int> newids;
			   InsertData InsertVariableElement(L"InsertVariableElement", 5, ipsHTTPS1, ipsJSONS1, TcpClient1);
			   InsertVariableElement.Add(L"VARIABLEELEMENT", sselement.Element);
			   InsertVariableElement.Add(L"ELEMENTTYPEID", sselement.ElementTypeID, -1);
			   InsertVariableElement.Add(L"SYMMETRYID", sselement.SymmetryID, -1);
			   InsertVariableElement.Add(L"PORTIONID", sselement.PortionID, -1);
			   InsertVariableElement.Add(L"MATURITYID", sselement.MaturityID, -1);
			   ParentForm->StatusBar1->Panels->Items[0]->Text = L"InsertVariableElement";
			   InsertVariableElement.PostData();
			   if (InsertVariableElement.Post(newids, ErrorMsg)) {
				 if (newids.size() == 1) {
				   sselement.VariableElementID = newids[0];
				   msg = L"New variable element uploaded: " + sselement.Element + L", ID = " + IntToStr(newids[0]);
				   MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
				   }
				 else {
				   msg = L"Error inserting into VariableElements table!";
				   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
				   return false;
				   }
				 }
			   else {
				 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
				 return false;
				 }
			   }
			 }
		   else
			 return false;
		   }
		 else {  // all parts not found
		   msg = L"Not all variable elements (element type, symmetry, portion, maturity) are in Neotoma.";
		   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   return false;
		   }
		 }
	   }
	 }
   Variable.ElementID = sselement.VariableElementID;
   }
   return true;
}
//---------------------------------------------------------------------------

bool TTilSpreadSheetForm::GetCompanionDatasetTypes(UnicodeString NeotomaDatasetType,
	vector<int>& DatasetTypeIDs)
{
   // this will return DatasetTypeIDs for e.g. "pollen" and "pollen surface sample"
   DatasetTypeIDs.clear();
   UnicodeString DatasetType = NeotomaDatasetType;
   if (ContainsText(DatasetType, L"surface sample")) {  // input type is surface sample
	 DatasetType = DatasetType.LowerCase();
	 int pos = DatasetType.Pos(L"surface sample");
	 DatasetType = DatasetType.SubString(1,pos-1).TrimRight();
	 }
   NeotomaDatasetTypesByName DatasetTypes(ipsJSONS1, TcpClient1);
   DatasetTypes.AddParam(L"DATASETTYPE", DatasetType);
   ParentForm->StatusBar1->Panels->Items[0]->Text = DatasetTypes.WebServiceName();
   if (DatasetTypes.Execute()) {
	 map<int,UnicodeString>::iterator itr;
	 for (itr = DatasetTypes.Items.begin(); itr != DatasetTypes.Items.end(); itr++)
	   DatasetTypeIDs.push_back(itr->first);
	 }
   else
	 return false;
   return true;
}
//---------------------------------------------------------------------------

bool TTilSpreadSheetForm::GetVariableUnitsID(NEOTOMAVARIABLEPARTS& Variable,
	int NeotomaDatasetTypeID, vector<int>& DatasetTypeIDs)
{
   UnicodeString msg, ErrorMsg;

   if (!Variable.Units.IsEmpty()) {
	 NeotomaVariableUnitsID GetVariableUnitsID(ipsJSONS1, TcpClient1);
	 GetVariableUnitsID.AddParam(L"VARIABLEUNITS", Variable.Units);
	 ParentForm->StatusBar1->Panels->Items[0]->Text = GetVariableUnitsID.WebServiceName();
	 if (GetVariableUnitsID.Execute()) {
	   if (GetVariableUnitsID.Size() == 1) {  // Units exist in Neotoma
		 Variable.UnitsID = GetVariableUnitsID.Items[0];
		 // check if DatasetTypeID, VariableUnitsID pair exists in UnitsDatasetTypes table
		 NeotomaUnitsDatasetTypeCount UnitsDatasetTypeCount(ipsJSONS1, TcpClient1);
		 UnitsDatasetTypeCount.AddParam(L"DATASETTYPEID", NeotomaDatasetTypeID);
		 UnitsDatasetTypeCount.AddParam(L"VARIABLEUNITSID", Variable.UnitsID);
		 ParentForm->StatusBar1->Panels->Items[0]->Text = UnitsDatasetTypeCount.WebServiceName();
		 if (UnitsDatasetTypeCount.Execute()) {
		   if (UnitsDatasetTypeCount.Size() == 1) {
			 if (UnitsDatasetTypeCount.Items[0] == 0) { // DatasetTypeID, VariableUnitsID combo does not exist
			   InsertData InsertUnitsDatasetType(L"InsertUnitsDatasetTypes", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
			   for (unsigned int i = 0; i < DatasetTypeIDs.size(); i++) {
				 InsertUnitsDatasetType.Add(L"DATASETTYPEID", DatasetTypeIDs[i], -1);
				 InsertUnitsDatasetType.Add(L"VARIABLEUNITSID", Variable.UnitsID, -1);
				 }
			   ParentForm->StatusBar1->Panels->Items[0]->Text = L"InsertUnitsDatasetTypes";
			   InsertUnitsDatasetType.PostData();
			   if (!InsertUnitsDatasetType.Post(ErrorMsg)) {
				 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
				 return false;
				 }
			   }
			 }
		   }
		 else
		   return false;
		 }
	   else {  // Units don't exist in Neotoma
		 msg = L"Units «" + Variable.Units + L"» not defined in Neotoma!";
		 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 return false;
		 }
	   }
	 else
	   return false;
	 }
   else {
	 msg = L"No units are specified. Is that correct?";
	 if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrNo) {
	   MessageDlg(L"Update cancelled!", mtInformation, TMsgDlgButtons() << mbOK, 0);
	   return false;
	   }
	 }
   return true;
}
//---------------------------------------------------------------------------

bool TTilSpreadSheetForm::GetVariableContextID(NEOTOMAVARIABLEPARTS& Variable,
	int NeotomaDatasetTypeID, vector<int>& DatasetTypeIDs)
{
   UnicodeString msg, ErrorMsg;

   if (!Variable.Context.IsEmpty()) {
	 NeotomaVariableContextID GetVariableContextID(ipsJSONS1, TcpClient1);
	 GetVariableContextID.AddParam(L"VARIABLECONTEXT", Variable.Context);
	 ParentForm->StatusBar1->Panels->Items[0]->Text = GetVariableContextID.WebServiceName();
	 if (GetVariableContextID.Execute()) {
	   if (GetVariableContextID.Size() == 1) {  // Context exists in Neotoma
		 Variable.ContextID = GetVariableContextID.Items[0];
		 // check if DatasetTypeID, VariableContextID pair exists in ContextsDatasetTypes table
		 NeotomaContextDatasetTypeCount ContextDatasetTypeCount(ipsJSONS1, TcpClient1);
		 ContextDatasetTypeCount.AddParam(L"DATASETTYPEID", NeotomaDatasetTypeID);
		 ContextDatasetTypeCount.AddParam(L"VARIABLECONTEXTID", Variable.ContextID);
		 ParentForm->StatusBar1->Panels->Items[0]->Text = ContextDatasetTypeCount.WebServiceName();
		 if (ContextDatasetTypeCount.Execute()) {
		   if (ContextDatasetTypeCount.Size() == 1) {
			 if (ContextDatasetTypeCount.Items[0] == 0) { // DatasetTypeID, VariableContextID combo does not exist
			   InsertData InsertContextDatasetTypes(L"InsertContextDatasetTypes", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
			   ParentForm->StatusBar1->Panels->Items[0]->Text = L"InsertContextDatasetTypes";
			   for (unsigned int i = 0; i < DatasetTypeIDs.size(); i++) {
				 InsertContextDatasetTypes.Add(L"DATASETTYPEID", DatasetTypeIDs[i], -1);
				 InsertContextDatasetTypes.Add(L"VARIABLECONTEXTID", Variable.ContextID, -1);
				 }
			   InsertContextDatasetTypes.PostData();
			   if (!InsertContextDatasetTypes.Post(ErrorMsg)) {
				 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
				 return false;
				 }
			   }
			 }
		   }
		 else
		   return false;
		 }
	   else {  // Context doesn't exist in Neotoma
		 msg = L"Context «" + Variable.Context + L"» not defined in Neotoma!";
		 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 return false;
		 }
	   }
	 else
	   return false;
	 }
   return true;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::DeleteVariable1Click(TObject *Sender)
{
   Beep();
}
//---------------------------------------------------------------------------

bool TTilSpreadSheetForm::DeleteNeotomaVariable(int ARow)
{
   UnicodeString ErrorMsg;
   bool success = true;

   int VariableID = GetSSDownloadVariableID(ARow);
   int DatasetIdx = GetCurrentDataset(ARow);
   int DatasetID = Datasets[DatasetIdx].NeotomaDatasetID;
   UnicodeString VarName = ProfGrid1->AbsoluteCells[2][ARow]->Text;

   try {
	 if (!Login->IsLoggedIn) {
	   NeotomaLoginForm = new TNeotomaLoginForm(this);
	   NeotomaLoginForm->ShowModal();
	   delete NeotomaLoginForm;
	   }
	 if (!Login->IsLoggedIn) {
	   success = false;
	   return success;
	   }

	 Screen->Cursor = crHourGlass;
	 DeleteData DeleteVariable(L"DeleteDatasetVariable", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
	 DeleteVariable.Add(L"DATASETID", DatasetID);
	 DeleteVariable.Add(L"VARIABLEID", VariableID);
	 if (DeleteVariable.Post(ErrorMsg)) {
	   UnicodeString msg = L"Variable «" + VarName + L"» deleted from Dataset " + IntToStr(DatasetID) + L".";
	   MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
	   }
	 else {
	   UnicodeString msg = L"Attempt to delete variable «" + VarName + L"» from Dataset " +
						   IntToStr(DatasetID) + L" failed.";;
	   if (!ErrorMsg.IsEmpty())
		 msg += (L": " + ErrorMsg);
	   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   success = false;
	   }
	 }
   __finally {
	 Screen->Cursor = crDefault;
	 }
   return success;
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::InsertDataValue(int ACol, int ARow, UnicodeString Text)
{
   int DatasetIdx;
   int VariableID;
   NEOTOMAVARIABLEPARTS Variable;
   double Value;
   vector<int> newids;
   UnicodeString ErrorMsg;
   bool inserted = false;

   try {
	   if (!TryStrToFloat(Text,Value)) {
		 MessageDlg(L"Invalid data value.", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 return;
		 }

	   if (Value == 0) {
		 if (MessageDlg(L"Upload zero value to Neotoma?", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrNo)
		   return;
		 }

	   if (!ValidateSteward(DatasetIdx))
		 return;

	   // Check that downloaded Neotoma VariableID exists. If not, get it from Neotoma.
	   if (ProfGrid1->AbsoluteCells[1][ARow]->CustomData.IsEmpty()) {  // VariableID not present
		 GetSSVariable(ARow, Variable);
		 if (GetVariableID(Variable, DatasetIdx, false)) {
		   VariableID = Variable.VariableID;
		   ProfGrid1->AbsoluteCells[1][ARow]->CustomData = VariableID;
		   }
		 else
		   return;
		 }
	   else {
		 VariableID = GetSSDownloadVariableID(ARow);
		 }

	   if (VariableID != -1) {
		 // get SampleID
		 int SampleRow = GetCurrentDatasetHeaderRow(ARow);
		 int SampleID = ProfGrid1->AbsoluteCells[ACol][SampleRow]->CustomData;

		 if (SampleID == 0) {
		   if ((SampleID = GetSampleID(ACol,ARow)) != -1)
			 ProfGrid1->AbsoluteCells[ACol][SampleRow]->CustomData = SampleID;
		   else
			 return;
		   }
		 // insert data value
		 InsertData Insert_Data(L"InsertData", 3, ipsHTTPS1, ipsJSONS1, TcpClient1);
		 Insert_Data.Add(L"SAMPLEID", SampleID, -1);
		 Insert_Data.Add(L"VARIABLEID", VariableID, -1);
		 Insert_Data.Add(L"VALUE", Value);
		 ParentForm->StatusBar1->Panels->Items[0]->Text = L"InsertData";
		 Insert_Data.PostData();
		 if (Insert_Data.Post(newids, ErrorMsg)) {
		   if (newids.size() == 1) {
			 ProfGrid1->AbsoluteCells[ACol][ARow]->CustomData = newids[0];
			 ProfGrid1->AbsoluteCells[ACol][ARow]->Color = TColor(0x0099E6FF);  // yellow
			 if (ProfGrid1->AbsoluteCells[2][ARow]->Color == TColor(0x00B7B8E6)) {  // light red, new variable
			   for (int col=1; col<=5; col++)
				 ProfGrid1->AbsoluteCells[col][ARow]->Color = TColor(0x0099E6FF);  // yellow
			   ProfGrid1->AbsoluteCells[7][ARow]->Color = TColor(0x0099E6FF);      // yellow
			   }
			 inserted = true;
			 }
		   else {
			 ErrorMsg = L"Error inserting into Data table!";
			 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			 }
		   }
		 else
		   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 }
	   }
   __finally {
	   if (!inserted)
		 ProfGrid1->AbsoluteCells[ACol][ARow]->Color = TColor(0x00B7B8E6);  // light red
	   FocusControl(ProfGrid1);
	   }
}
//---------------------------------------------------------------------------

bool TTilSpreadSheetForm::UpdateSampleAnalyst(int ACol, int ARow)
{
   UnicodeString msg, ErrorMsg;
   vector<int> newids;

   if (!DownloadPaste.Pasting || (DownloadPaste.Pasting && DownloadPaste.n == 1)) {
	 if (MessageDlg(L"Update sample analysts in Neotoma?", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) != mrYes)
	   return false;
	 }

   int SampleID = GetNeotomaSampleID(ACol, ARow);
   if (SampleID == -1)
	 return true;

   Screen->Cursor = crHourGlass;
   // first, delete any existing analysts
   DeleteData DeleteAnalyst(L"DeleteSampleAnalysts", 1, ipsHTTPS1, ipsJSONS1, TcpClient1);
   ParentForm->StatusBar1->Panels->Items[0]->Text = L"DeleteSampleAnalysts";
   DeleteAnalyst.Add(L"SAMPLEID", SampleID);
   if (!DeleteAnalyst.Post(ErrorMsg)) {
	 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 return false;
	 }

   // now add new analysts if they exist
   bool success = true;
   TProfGridCell *ACell = ProfGrid1->AbsoluteCells[ACol][ARow];
   if (ACell->CellObject != NULL) {
	 CELLOBJECT* CellObject = (CELLOBJECT*)ACell->CellObject;
	 if (CellObject->ObjectType == CELLCONTACTS) {
	   InsertData InsertSampleAnalyst(L"InsertSampleAnalyst", 3, ipsHTTPS1, ipsJSONS1, TcpClient1);
	   TList* SSContacts = (TList*)CellObject->Object;
	   for (int i=0; i<SSContacts->Count; i++) {
		 CONTACT* Contact = (CONTACT*)SSContacts->Items[i];
		 InsertSampleAnalyst.Add(L"SAMPLEID", SampleID);
		 InsertSampleAnalyst.Add(L"CONTACTID", Contact->NeotomaContactID);
		 InsertSampleAnalyst.Add(L"ANALYSTORDER", i+1);
		 }
	   ParentForm->StatusBar1->Panels->Items[0]->Text = L"InsertSampleAnalyst";
	   InsertSampleAnalyst.PostData();
	   if (InsertSampleAnalyst.Post(newids, ErrorMsg)) {
		 if ((int)newids.size() == SSContacts->Count) {
		   ProfGrid1->AbsoluteCells[ACol][ARow]->Color = TColor(0x00B4E0C6);  // light green
		   if (!DownloadPaste.Pasting) {
			 msg = L"Analysts for SampleID " + IntToStr(SampleID) + L" updated.";
			 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
			 }
		   else if (DownloadPaste.n == DownloadPaste.ncols) {
			 if (DownloadPaste.ncols == 1)
			   msg = L"Analysts for SampleID " + IntToStr(SampleID) + L" updated.";
			 else
			   msg = L"Analysts updated for " + IntToStr(DownloadPaste.ncols) + L" samples.";
			 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
			 }
		   }
		 else {
		   ProfGrid1->AbsoluteCells[ACol][ARow]->Color = TColor(0x00ADCBF8);  // light orange
		   ErrorMsg = L"Error inserting into SampleAnalysts table!";
		   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   success = false;
		   }
		 }
	   else {
		 ProfGrid1->AbsoluteCells[ACol][ARow]->Color = TColor(0x00ADCBF8);  // light orange
		 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 success = false;
		 }
	   }
	 }
   return success;
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::UpdateSampleKeywords(int ACol, int ARow, UnicodeString Text)
{
   UnicodeString msg, ErrorMsg;
   vector<UnicodeString> Keywords;
   vector<UnicodeString> NewKeywords;
   map<int,UnicodeString> NeotomaKeywords;
   bool updated = false;

   if (MessageDlg(L"Update sample keywords in Neotoma?", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) != mrYes)
	 return;

   int SampleID = GetNeotomaSampleID(ACol, ARow);
   if (SampleID == -1)
	 return;

   Screen->Cursor = crHourGlass;
   UnicodeString KeywordList = Text;
   if (!KeywordList.IsEmpty())
	 ParsePartsIC(KeywordList, L";", Keywords);

   //for (unsigned int i = 0; i < Keywords.size(); i++) {
   //	ShowMessage(Keywords[i]);
   //	}

   try {
	   // get all keywords from Neotoma
	   NeotomaKeywordsTable KeywordsTable(ipsJSONS1, TcpClient1);
	   ParentForm->StatusBar1->Panels->Items[0]->Text = KeywordsTable.WebServiceName();
	   if (KeywordsTable.Execute()) {
		 if (KeywordsTable.Size() > 0)
		   NeotomaKeywords = KeywordsTable.Items;
		 else {
		   msg = L"Error retrieving keywords from Neotoma.";
		   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   return;
		   }
		 }
	   else
		 return;

	   // check that entered keywords exist in Neotoma
	   for (unsigned int i=0; i<Keywords.size(); i++) {
		 bool found = false;
		 map<int,UnicodeString>::iterator itr;
		 for (itr = NeotomaKeywords.begin(); itr != NeotomaKeywords.end(); itr++) {
		   if (SameText(Keywords[i],itr->second)) {
			 found = true;
			 break;
			 }
		   }
		 if (!found) {
		   msg = L"Keyword «" + Keywords[i] + L"» not found in Neotoma Keywords table.";
		   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   return;
		   }
		 }

	   // get keywords for sample already in Neotoma
	   NeotomaSampleKeywords SampleKeywords(ipsJSONS1, TcpClient1);
	   SampleKeywords.AddParam(L"SAMPLEID", SampleID);
	   ParentForm->StatusBar1->Panels->Items[0]->Text = SampleKeywords.WebServiceName();
	   if (!SampleKeywords.Execute())
		 return;
	   if (SampleKeywords.Size() == 0)
		 NewKeywords = Keywords;
	   else {
		 for (unsigned int i=0; i<Keywords.size(); i++) {
		   bool found = false;
		   map<int,UnicodeString>::iterator itr;
		   for (itr = SampleKeywords.Items.begin(); itr != SampleKeywords.Items.end(); itr++) {
			 if (SameText(Keywords[i],itr->second)) {
			   found = true;
			   break;
			   }
			 }
		   if (!found)
			 NewKeywords.push_back(Keywords[i]);
		   }
		 }

	   // delete any keywords no longer applied
	   if (SampleKeywords.Size() > 0) {
		 map<int,UnicodeString>::iterator itr;
		 for (itr = SampleKeywords.Items.begin(); itr != SampleKeywords.Items.end(); itr++) {
		   bool found = false;
		   for (unsigned int i=0; i<NewKeywords.size(); i++) {
			 if (SameText(itr->second, NewKeywords[i])) {
			   found = true;
			   break;
			   }
			 }
           if (!found) {
			 // delete keyword
			 // DeleteSampleKeyword](@SAMPLEID int, @KEYWORDID int)
			 DeleteData DeleteKeyword(L"DeleteSampleKeyword", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
			 DeleteKeyword.Add(L"SAMPLEID", SampleID);
			 int KeywordID;
			 map<int,UnicodeString>::iterator it;
			 for (it = NeotomaKeywords.begin(); it != NeotomaKeywords.end(); it++) {
			   if (SameText(itr->second,it->second)) {
				 KeywordID = it->first;
				 break;
				 }
			   }
			 DeleteKeyword.Add(L"KEYWORDID", KeywordID);
			 if (DeleteKeyword.Post(ErrorMsg))
			   updated = true;
			 else {
			   UnicodeString msg = L"Attempt to delete keyword from Neotoma failed.";
			   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			   return;
			   }
			 }
		   }
		 }

	   // upload any new sample keywords
	   if (NewKeywords.size() > 0) {
		 InsertData InsertSampleKeyword(L"InsertSampleKeyword", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
		 for (unsigned int i=0; i<NewKeywords.size(); i++) {
		   InsertSampleKeyword.Add(L"SAMPLEID", SampleID);
		   int KeywordID;
		   map<int,UnicodeString>::iterator itr;
		   for (itr = NeotomaKeywords.begin(); itr != NeotomaKeywords.end(); itr++) {
			 if (SameText(NewKeywords[i],itr->second)) {
			   KeywordID = itr->first;
			   break;
			   }
			 }
		   InsertSampleKeyword.Add(L"KEYWORDID", KeywordID);
		   }

		 ParentForm->StatusBar1->Panels->Items[0]->Text = L"InsertSampleKeyword";
		 InsertSampleKeyword.PostData();
		 if (InsertSampleKeyword.Post(ErrorMsg))
		   updated = true;
		 else {
		   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   return;
		   }
		 }

	   if (updated) {
		 msg = L"Keywords updated in Neotoma for SampleID " + IntToStr(SampleID) + L".";
		 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
		 }
	   }
   __finally {
	   ParentForm->StatusBar1->Panels->Items[0]->Text = L"";
	   Screen->Cursor = crDefault;
	   }
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::UpdateSampleName(int ACol, int ARow, UnicodeString SampleName)
{
   UnicodeString ErrorMsg;

   if (MessageDlg(L"Update sample name in Neotoma?", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) != mrYes)
	 return;

   int SampleID = GetNeotomaSampleID(ACol, ARow);
   if (SampleID == -1)
	 return;

   Screen->Cursor = crHourGlass;
   UpdateData UpdateSampleName(L"UpdateSampleName", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
   UpdateSampleName.Add(L"SAMPLEID", SampleID);
   UpdateSampleName.Add(L"SAMPLENAME", SampleName);
   ParentForm->StatusBar1->Panels->Items[0]->Text = L"UpdateSampleName";
   if (UpdateSampleName.Post(ErrorMsg)) {
	 ProfGrid1->AbsoluteCells[ACol][ARow]->Color = TColor(0x00B4E0C6);  // light green
	 UnicodeString msg = L"Sample name updated to «" + SampleName + L"».";
	 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
	 }
   else if (!ErrorMsg.IsEmpty())
	 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);

   ParentForm->StatusBar1->Panels->Items[0]->Text = L"";
}
//---------------------------------------------------------------------------

int TTilSpreadSheetForm::GetNeotomaSampleID(int ACol, int ARow)
{
   int SampleID = -1;

   if (!ProfGrid1->AbsoluteCells[ACol][1]->CustomData.IsEmpty())
	 SampleID = ProfGrid1->AbsoluteCells[ACol][1]->CustomData;

   int start = AbsHeaderRowCount(ProfGrid1);
   for (int row=start; row<ARow; row++) {
	 UnicodeString VarCode = ProfGrid1->AbsoluteCells[1][row]->Text;
	 if (SameText(VarCode, L"#Data.Type")) {
	   SampleID = -1;
	   if (!ProfGrid1->AbsoluteCells[ACol][row]->CustomData.IsEmpty())
		 SampleID = ProfGrid1->AbsoluteCells[ACol][row]->CustomData;
	   }
	 }

   return SampleID;
}
//---------------------------------------------------------------------------

bool TTilSpreadSheetForm::UpdateSampleAge(UnicodeString VarCode, UnicodeString NewText, int ACol, int ARow)
{
   vector<UPDSAMPLEAGE> SampleAges;
   int ChronID;
   return UpdateSampleAge(VarCode, NewText, ACol, ARow, SampleAges, ChronID, true);
}
//---------------------------------------------------------------------------

bool TTilSpreadSheetForm::UpdateSampleAge(UnicodeString VarCode, UnicodeString NewText,
	int ACol, int ARow, vector<UPDSAMPLEAGE>& SampleAges, int& ChronID, bool PullTheTrigger)
{
   int SampleID;
   vector<int> SampleIDs;
   UnicodeString msg;
   bool older = false;
   bool younger = false;
   double dValue;
   Variant AgeValue;

   Screen->Cursor = crHourGlass;
   if (TryStrToFloat(NewText, dValue))
	 AgeValue = dValue;
   else {
	 msg = L"«" + NewText + L"» is not a valid age value!";
	 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 Screen->Cursor = crDefault;
	 return false;
	 }

   if (ContainsText(VarCode,L"Young"))
	 younger = true;
   else if (ContainsText(VarCode,L"Old"))
	 older = true;

   if (!ProfGrid1->AbsoluteCells[1][ARow]->CustomData.IsEmpty()) {
	 ChronID = ProfGrid1->AbsoluteCells[1][ARow]->CustomData;
	 }
   else {
	 // AGEMODEL* AgeModel = AgeModelList->AgeModels[RecordIndex1];
	 // #Chron1.Old
	 UnicodeString ChronNo = VarCode;
	 ChronNo.Delete(1,6);
	 int pos = ChronNo.Pos(L".");
	 if (pos > 1)
	   ChronNo = ChronNo.SubString(1,pos-1);
	 int TempID;
	 if (!TryStrToInt(ChronNo,TempID)) {
	   Screen->Cursor = crDefault;
	   return false;
	   }

	 bool found = false;
	 for (int i=0; i<AgeModelList->Count; i++) {
	   AGEMODEL* AgeModel = AgeModelList->AgeModels[i];
	   if (TempID == AgeModel->ChronNumber) {
		 ChronID = AgeModel->NeotomaChronologyID;
		 ProfGrid1->AbsoluteCells[1][ARow]->CustomData = ChronID;
		 found = true;
		 break;
		 }
	   }
	 if (!found) {
	   Screen->Cursor = crDefault;
	   return false;
	   }
	 }

   if (!ProfGrid1->AbsoluteCells[ACol][1]->CustomData.IsEmpty()) {
	 SampleID = ProfGrid1->AbsoluteCells[ACol][1]->CustomData;
	 SampleIDs.push_back(SampleID);
	 }

   int nrows = AbsContentRowCount(ProfGrid1);
   int start = AbsHeaderRowCount(ProfGrid1);
   for (int row=start; row<=nrows; row++) {
	 UnicodeString VarCode = ProfGrid1->AbsoluteCells[1][row]->Text;
	 if (SameText(VarCode, L"#Data.Type")) {
	   if (!ProfGrid1->AbsoluteCells[ACol][row]->CustomData.IsEmpty()) {
		 SampleID = ProfGrid1->AbsoluteCells[ACol][row]->CustomData;
		 SampleIDs.push_back(SampleID);
		 }
	   }
	 }

   // vector<UPDSAMPLEAGE> SampleAges;

   unsigned int startnew = SampleAges.size();
   for (unsigned int i = 0; i < SampleIDs.size(); i++) {
	 NeotomaSampleAge SampleAge(ipsJSONS1, TcpClient1);
	 SampleAge.AddParam(L"CHRONOLOGYID", ChronID);
	 SampleAge.AddParam(L"SAMPLEID", SampleIDs[i]);
	 ParentForm->StatusBar1->Panels->Items[0]->Text = SampleAge.WebServiceName();
	 if (SampleAge.Execute()) {
	   UPDSAMPLEAGE age;
	   age.SampleID = SampleIDs[i];
	   if (SampleAge.Size() == 1) {
		 age.SampleAgeID = SampleAge.Items.begin()->first;
		 age.Age = SampleAge.Items.begin()->second.Age;
		 age.AgeOlder = SampleAge.Items.begin()->second.AgeOlder;
		 age.AgeYounger = SampleAge.Items.begin()->second.AgeYounger;
		 }
	   age.ACol = ACol;
	   age.ARow = ARow;
	   SampleAges.push_back(age);
	   }
	 else {
	   Screen->Cursor = crDefault;
	   return false;
	   }
	 }

   bool upload = false;
   bool update = false;

   for (unsigned int i = startnew; i < SampleAges.size(); i++) {
	 if (SampleAges[i].SampleAgeID == -1)
	   upload = true;
	 else if (older && SampleAges[i].AgeOlder != AgeValue) {
	   SampleAges[i].update = true;
	   update = true;
	   }
	 else if (younger && SampleAges[i].AgeYounger != AgeValue) {
	   SampleAges[i].update = true;
	   update = true;
	   }
	 else if (SampleAges[i].Age != AgeValue) {
	   SampleAges[i].update = true;
	   update = true;
	   }

	 if (younger)
	   SampleAges[i].AgeYounger = AgeValue;
	 else if (older)
	   SampleAges[i].AgeOlder = AgeValue;
	 else
	   SampleAges[i].Age = AgeValue;
	 }

   // ShowMessage(L"AgeValue = " + FloatToStr((double)AgeValue));

   if (upload && update)
	 msg = L"Upload/update age";
   else if (upload)
	 msg = L"Upload age";
   else if (update)
	 msg = L"Update age";
   else {
	 Screen->Cursor = crDefault;
	 return true;  // no changes in age value
	 }

   if (older)
	 msg += L" older?";
   else if (younger)
	 msg += L" younger?";
   else
	 msg += L"?";

   if (PullTheTrigger)
	 UpdateSampleAge(SampleAges, ChronID, msg);
   Screen->Cursor = crDefault;
   return true;
}
//---------------------------------------------------------------------------

bool TTilSpreadSheetForm::UpdateSampleAge(vector<UPDSAMPLEAGE>& SampleAges, int ChronID, UnicodeString msg)
{
   vector<int> newids;
   bool upload = false;
   bool update = false;

   if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes) {
	 Screen->Cursor = crHourGlass;
	 msg = L"";
	 for (unsigned int i = 0; i < SampleAges.size(); i++) {
	   if (SampleAges[i].SampleAgeID == -1) {   // insert new age
		 InsertData InsertSampleAge(L"InsertSampleAge", 5, ipsHTTPS1, ipsJSONS1, TcpClient1);
		 InsertSampleAge.Add(L"SAMPLEID", SampleAges[i].SampleID, -1);
		 InsertSampleAge.Add(L"CHRONOLOGYID", ChronID, -1);
		 InsertSampleAge.AddDouble(L"AGE", SampleAges[i].Age);
		 InsertSampleAge.AddDouble(L"AGEYOUNGER", SampleAges[i].AgeYounger);
		 InsertSampleAge.AddDouble(L"AGEOLDER", SampleAges[i].AgeOlder);
		 ParentForm->StatusBar1->Panels->Items[0]->Text = L"InsertSampleAge";
		 InsertSampleAge.PostData();
		 if (InsertSampleAge.Post(newids, msg)) {
		   if (newids.size() == 1) {
			 upload = true;
			 ProfGrid1->AbsoluteCells[SampleAges[i].ACol][SampleAges[i].ARow]->Color = TColor(0x0099E6FF);  // yellow
			 }
		   else {
			 msg = L"Error inserting into SampleAges table!";
			 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			 Screen->Cursor = crDefault;
			 return false;
			 }
		   }
		 else {
		   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   Screen->Cursor = crDefault;
		   return false;
		   }
		 }
	   else {  // update age
		 UpdateData UpdateSampleAge(L"UpdateSampleAge", 4, ipsHTTPS1, ipsJSONS1, TcpClient1);
		 ParentForm->StatusBar1->Panels->Items[0]->Text = L"UpdateSampleAge";
		 UpdateSampleAge.Add(L"SAMPLEAGEID", SampleAges[i].SampleAgeID);
		 UpdateSampleAge.AddDouble(L"AGE", SampleAges[i].Age);
		 UpdateSampleAge.AddDouble(L"AGEYOUNGER", SampleAges[i].AgeYounger);
		 UpdateSampleAge.AddDouble(L"AGEOLDER", SampleAges[i].AgeOlder);
		 if (UpdateSampleAge.Post(msg)) {
		   update = true;
		   ProfGrid1->AbsoluteCells[SampleAges[i].ACol][SampleAges[i].ARow]->Color = TColor(0x00B4E0C6);  // light green
		   }
		 else {
		   msg += L"\nSample age not updated.";
		   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   Screen->Cursor = crDefault;
		   return false;
		   }
		 }
	   }

	 msg = L"Sample age";
	 if (SampleAges.size() > 1)
	   msg += L"s";
	 if (upload && update)
	   msg += L" uploaded/updated.";
	 else if (upload)
	   msg += L" uploaded.";
	 else if (update)
	   msg += L" updated.";
	 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
	 SampleAges.clear();
	 Screen->Cursor = crDefault;
   }
  return true;
}
//---------------------------------------------------------------------------

// This is on a paste operation. Can be both updated and uploaded (new) values
void TTilSpreadSheetForm::UploadDataValues(void)
{
   int ACol, ARow;
   unsigned int size;

   int DatasetIdx;
   int VariableID;
   NEOTOMAVARIABLEPARTS Variable;
   double Value;
   vector<int> newids;
   int nupdates = 0;
   int ndeletes = 0;
   UnicodeString msg, ErrorMsg;
   bool AllowZeroValues = false;
   bool ZeroQuery = false;
   int BadValues = 0;

   vector<pair<int,double> > InsertCells;  // col, value
   vector<pair<int,double> > UpdateCells;  // col, value
   vector<int> DeleteCells;                // col

   if (DownloadPasteCells.size() == 0)
	 return;

   if (!ValidateSteward(DatasetIdx))
	 return;

   int IRow = DownloadPasteCells[0].second;
   size = DownloadPasteCells.size();

   UnicodeString VarCode = ProfGrid1->AbsoluteCells[1][IRow]->Text;
   if (VarCode[1] == L'#') {
	 if (SameText(VarCode.SubString(1,6), L"#Chron")) {
	   vector<UPDSAMPLEAGE> SampleAges;
	   int ChronID;
	   for (unsigned int i=0; i<size; i++) {
		 ACol = DownloadPasteCells[i].first;
		 ARow = DownloadPasteCells[i].second;
		 if (ARow == IRow) {
		   if (UpdateSampleAge(VarCode, ProfGrid1->AbsoluteCells[ACol][ARow]->Text, ACol, ARow, SampleAges, ChronID, false))
			 DownloadPaste.n++;
		   else
			 break;
		   }
		 }
	   msg = L"Upload/update sample ages?";
	   UpdateSampleAge(SampleAges, ChronID, msg);

	   DownloadPasteCells.clear();
	   return;
	   }
	 else if (SameText(VarCode, L"#Samp.Analyst")) {
	   for (unsigned int i=0; i<size; i++) {
		 ACol = DownloadPasteCells[i].first;
		 ARow = DownloadPasteCells[i].second;
		 if (ARow == IRow) {
		   if (UpdateSampleAnalyst(ACol, ARow))
			 DownloadPaste.n++;
		   else
			 break;
		   }
		 }
	   DownloadPasteCells.clear();
	   return;
	   }
	 else if (SameText(VarCode, L"#Anal.Thick")) {
	   int rv;
	   for (unsigned int i=0; i<size; i++) {
		 ACol = DownloadPasteCells[i].first;
		 ARow = DownloadPasteCells[i].second;
		 if (i == 0)
		   rv = (ProfGrid1->Selection->Cells[0]->AbsoluteCol == ACol) ? mrIgnore : mrYesToAll;
		 if (ARow == IRow) {
		   UnicodeString Text = ProfGrid1->AbsoluteCells[ACol][ARow]->Text;
		   rv = UpdateAnalThickness(ACol, ARow, Text, rv);
		   if (rv == mrYes || rv == mrYesToAll)
			 DownloadPaste.n++;
		   else if (rv == mrCancel || rv == mrNoToAll)
			 break;
		   }
		 }
	   int lastcol = ProfGrid1->Selection->Cells[ProfGrid1->Selection->Count-1]->AbsoluteCol;
	   if (rv == mrYesToAll && ACol == lastcol) {
		 msg = L"Analysis unit thicknesses updated.";
		 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
		 }
	   DownloadPasteCells.clear();
	   return;
	   }
	 else {
	   MessageDlg(L"Neotoma updates not yet implemented for pastes.", mtInformation, TMsgDlgButtons() << mbOK, 0);
	   return;
	   }
	 }

   Screen->Cursor = crHourGlass;
   for (unsigned int i=0; i<DownloadPasteCells.size(); i++) {
	 ACol = DownloadPasteCells[i].first;
	 ARow = DownloadPasteCells[i].second;
	 if (ARow == IRow) {   // this should always be true, but...
	   UnicodeString Text = ProfGrid1->AbsoluteCells[ACol][IRow]->Text;
	   if (Text.IsEmpty()) {
		 DeleteCells.push_back(ACol);
		 }
	   else if (TryStrToFloat(Text,Value)) {
		 if (Value == 0) {
		   if (!ZeroQuery) {
			 if (MessageDlg(L"Upload zero values to Neotoma?", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes)
			   AllowZeroValues = true;
			   ZeroQuery = true;
			 }
		   if (!AllowZeroValues) {
			 DeleteCells.push_back(ACol);
			 continue;
			 }
		   }
		 if (ProfGrid1->AbsoluteCells[ACol][ARow]->CustomData.IsEmpty())
		   InsertCells.push_back(pair<int,double>(ACol,Value));
		 else
		   UpdateCells.push_back(pair<int,double>(ACol,Value));
		 }
	   else
		 BadValues++;
	   }
	 }

   DownloadPasteCells.clear();

   if (InsertCells.size() > 0) {
	 try {
	   // Check that downloaded Neotoma VariableID exists. If not, get it from Neotoma.
	   if (ProfGrid1->AbsoluteCells[1][IRow]->CustomData.IsEmpty()) {  // VariableID not present
		 GetSSVariable(IRow, Variable);
		 if (GetVariableID(Variable, DatasetIdx, false)) {
		   VariableID = Variable.VariableID;
		   ProfGrid1->AbsoluteCells[1][IRow]->CustomData = VariableID;
		   }
		 else {
		   Screen->Cursor = crDefault;
		   return;
		   }
		 }
	   else {
		 VariableID = GetSSDownloadVariableID(IRow);
		 }

	   if (VariableID != -1) {
		 int SampleRow = GetCurrentDatasetHeaderRow(IRow);
		 InsertData Insert_Data(L"InsertData", 3, ipsHTTPS1, ipsJSONS1, TcpClient1);
		 for (unsigned int i=0; i<InsertCells.size(); i++) {
		   // get SampleID
		   ACol = InsertCells[i].first;
		   int SampleID = ProfGrid1->AbsoluteCells[ACol][SampleRow]->CustomData;
		   Insert_Data.Add(L"SAMPLEID", SampleID, -1);
		   Insert_Data.Add(L"VARIABLEID", VariableID, -1);
		   Insert_Data.Add(L"VALUE", InsertCells[i].second);
		   }

		 // insert data values
		 ParentForm->StatusBar1->Panels->Items[0]->Text = L"InsertData";
		 Insert_Data.PostData();
		 if (Insert_Data.Post(newids, ErrorMsg)) {
		   if (newids.size() == InsertCells.size()) {
			 for (unsigned int i=0; i<InsertCells.size(); i++) {
			   ACol = InsertCells[i].first;
			   ProfGrid1->AbsoluteCells[ACol][IRow]->CustomData = newids[i];
			   ProfGrid1->AbsoluteCells[ACol][IRow]->Color = TColor(0x0099E6FF);  // yellow
			   }
			 }
		   else {
			 ErrorMsg = L"Error inserting into Data table!";
			 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			 }
		   }
		 else
		   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 }
	   }
	 __finally {
	   FocusControl(ProfGrid1);
	   }
	 }

   VariableID = -1;
   if (UpdateCells.size() > 0 || DeleteCells.size() > 0) {
     if (ProfGrid1->AbsoluteCells[1][IRow]->CustomData.IsEmpty()) {  // VariableID not present
	   msg = L"Neotoma VariableID not present.";
	   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   Screen->Cursor = crDefault;
	   return;
	   }
	 else {
	   VariableID = GetSSDownloadVariableID(IRow);
	   }
	 }

   if (VariableID != -1) {
	 if (DeleteCells.size() > 0) {
	   try {
		   for (unsigned int i=0; i<DeleteCells.size(); i++) {
			 ACol = DeleteCells[i];
			 int DataID = ProfGrid1->AbsoluteCells[ACol][IRow]->CustomData;
			 if (DataID > 0) {
			   ndeletes++;
			   DeleteData Delete_Data(L"DeleteData", 1, ipsHTTPS1, ipsJSONS1, TcpClient1);
			   Delete_Data.Add(L"DATAID", DataID);
			   ParentForm->StatusBar1->Panels->Items[0]->Text = L"DeleteData";
			   if (Delete_Data.Post(ErrorMsg)) {
				 ProfGrid1->AbsoluteCells[ACol][IRow]->Value = Unassigned();
				 ProfGrid1->AbsoluteCells[ACol][IRow]->Color = TColor(0x00B4E0C6);  // light green
				 }
			   else if (!ErrorMsg.IsEmpty()) {
				 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
				 break;
				 }
			   }
			 else {
			   ProfGrid1->AbsoluteCells[ACol][IRow]->Value = Unassigned();
               ProfGrid1->AbsoluteCells[ACol][IRow]->Color = clWhite;
			   }
			 }
		   }
	   __finally {
		   FocusControl(ProfGrid1);
		   }
	   }
	 if (UpdateCells.size() > 0) {
	   try {
		   for (unsigned int i=0; i<UpdateCells.size(); i++) {
			 ACol = UpdateCells[i].first;
			 int DataID = ProfGrid1->AbsoluteCells[ACol][IRow]->CustomData;
			 nupdates++;
			 UpdateData Update_Data(L"UpdateData", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
			 Update_Data.Add(L"DATAID", DataID);
			 Update_Data.Add(L"VALUE", UpdateCells[i].second);
			 ParentForm->StatusBar1->Panels->Items[0]->Text = L"UpdateData";
			 if (Update_Data.Post(ErrorMsg)) {
			   ProfGrid1->AbsoluteCells[ACol][IRow]->Color = TColor(0x00B4E0C6);  // light green
			   }
			 else if (!ErrorMsg.IsEmpty()) {
			   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			   break;
			   }
			 }
		   }
	   __finally {
		   FocusControl(ProfGrid1);
		   }
	   }
	 }

   // 20 data values inserted. 10 data values updated. 1 invalid value not uploaded.
   msg.SetLength(0);
   DownloadPaste.n = 0;
   if (newids.size() > 0) {
	 msg = (IntToStr((int)newids.size()) + L" data value");
	 if (newids.size() > 1)
	   msg += L"s";
	 msg += L" inserted.";
	 DownloadPaste.n += newids.size();
	 }
   if (nupdates > 0) {
	 if (msg.Length() > 0)
	   msg += L" ";
	 msg += (IntToStr(nupdates) + L" data value");
	 if (nupdates > 1)
	   msg += L"s";
	 msg += L" updated.";
	 DownloadPaste.n += nupdates;
	 }
   if (ndeletes > 0) {
	 if (msg.Length() > 0)
	   msg += L" ";
	 msg += (IntToStr(ndeletes) + L" data value");
	 if (ndeletes > 1)
	   msg += L"s";
	 msg += L" deleted.";
	 DownloadPaste.n += ndeletes;
     }
   if (BadValues > 0) {
	 if (msg.Length() > 0)
	   msg += L" ";
	 msg += (IntToStr(BadValues) + L" invalid value");
	 if (BadValues > 1)
	   msg += L"s";
	 msg += L" not uploaded.";
	 DownloadPaste.n += BadValues;
	 }
   Screen->Cursor = crDefault;
   MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::UpdateDataValue(int ACol, int ARow, UnicodeString Text)
{
   int DatasetIdx;
   int VariableID;
   NEOTOMAVARIABLEPARTS Variable;
   double Value;
   UnicodeString ErrorMsg;
   bool updated = false;

   try {
       if (!ValidateSteward(DatasetIdx))
		 return;

	   if (Text.IsEmpty() && !ProfGrid1->AbsoluteCells[1][ARow]->CustomData.IsEmpty()) {    // delete data value
		 int DataID = ProfGrid1->AbsoluteCells[ACol][ARow]->CustomData;
		 DeleteData DeleteDataVal(L"DeleteData", 1, ipsHTTPS1, ipsJSONS1, TcpClient1);
		 DeleteDataVal.Add(L"DATAID", DataID);
		 ParentForm->StatusBar1->Panels->Items[0]->Text = L"DeleteData";
		 if (DeleteDataVal.Post(ErrorMsg)) {
		   MessageDlg(L"Data value deleted from Neotoma.", mtInformation, TMsgDlgButtons() << mbOK, 0);
		   ProfGrid1->AbsoluteCells[ACol][ARow]->CustomData = Unassigned();
		   ProfGrid1->AbsoluteCells[ACol][ARow]->Color = TColor(0x00B4E0C6);  // light green
		   updated = true;
		   }
		 else {
		   UnicodeString msg = L"Attempt to delete from Neotoma failed.";;
		   if (!ErrorMsg.IsEmpty())
			 msg += (L": " + ErrorMsg);
		   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   return;
		   }
		 }
	   else {
		 if (!TryStrToFloat(Text,Value)) {
		   MessageDlg(L"Invalid data value.", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   return;
		  }

		 if (Value == 0) {
		   if (MessageDlg(L"Upload zero value to Neotoma?", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrNo)
			 return;
		   }

		 // Check that downloaded Neotoma VariableID exists. If not, get it from Neotoma.
		 if (ProfGrid1->AbsoluteCells[1][ARow]->CustomData.IsEmpty()) {  // VariableID not present
		   GetSSVariable(ARow, Variable);
		   if (GetVariableID(Variable, DatasetIdx, false)) {
			 VariableID = Variable.VariableID;
			 ProfGrid1->AbsoluteCells[1][ARow]->CustomData = VariableID;
			 }
		   else
			 return;
		   }
		 else {
		   VariableID = GetSSDownloadVariableID(ARow);
		   }

		 if (VariableID != -1) {
		   // update data value
		   int DataID = ProfGrid1->AbsoluteCells[ACol][ARow]->CustomData;
		   UpdateData Update_Data(L"UpdateData", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
		   Update_Data.Add(L"DATAID", DataID);
		   Update_Data.Add(L"VALUE", Value);
		   ParentForm->StatusBar1->Panels->Items[0]->Text = L"UpdateData";
		   if (Update_Data.Post(ErrorMsg)) {
			 ProfGrid1->AbsoluteCells[ACol][ARow]->Color = TColor(0x00B4E0C6);  // light green
			 updated = true;
			 }
		   else if (!ErrorMsg.IsEmpty()) {
			 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			 }
		   }
		 }
	   }
   __finally {
	   if (!updated)
		 ProfGrid1->AbsoluteCells[ACol][ARow]->Color = TColor(0x00ADCBF8);  // light orange
	   FocusControl(ProfGrid1);
	   }
}
//---------------------------------------------------------------------------

int TTilSpreadSheetForm::UpdateAnalThickness(int ACol, int ARow, UnicodeString ThickStr, int retval)
{
   UnicodeString msg, ErrorMsg;
   bool updated = true;
   double Thickness;
   int rv = retval;

   try {
	   int AnalysisUnitID = ProfGrid1->AbsoluteCells[ACol][2]->CustomData;
	   if (AnalysisUnitID <= 0)
		 return rv;

	   if (!TryStrToFloat(ThickStr,Thickness)) {
		 msg = L"Not a valid number.";
		 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 return mrCancel;
		 }

	   msg = L"Update Analysis Unit thickness in Neotoma?";
	   if (rv != mrYesToAll) {
		 if (ProfGrid1->Selection->Count > 1)
		   rv = MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbYesToAll << mbNo << mbNoToAll, 0);
		 else
		   rv = MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0);
		 if (rv != mrYes && rv != mrYesToAll) {
		   updated = false;
		   return rv;
		   }
		 }

	   Screen->Cursor = crHourGlass;
	   UpdateData UpdateAnalUnitThickness(L"UpdateAnalysisUnitThickness", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
	   UpdateAnalUnitThickness.Add(L"ANALYSISUNITID", AnalysisUnitID);
	   UpdateAnalUnitThickness.Add(L"THICKNESS", Thickness);
	   ParentForm->StatusBar1->Panels->Items[0]->Text = L"UpdateAnalysisUnitThickness";
	   if (UpdateAnalUnitThickness.Post(ErrorMsg)) {
		 ProfGrid1->AbsoluteCells[ACol][ARow]->Color = TColor(0x00B4E0C6);  // light green
		 if (rv != mrYesToAll && ProfGrid1->Selection->Count == 1) {
		   msg = L"Thickness of Analysis Unit " + IntToStr(AnalysisUnitID) + L" updated to " +
				 FloatToStr(Thickness) + L".";
		   MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
		   }
		 return rv;
		 }
	   else if (!ErrorMsg.IsEmpty()) {
		 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 updated = false;
		 return mrCancel;
		 }
	   }
   __finally {
	   if (!updated)
		 ProfGrid1->AbsoluteCells[ACol][ARow]->Color = TColor(0x00ADCBF8);  // light orange
	   FocusControl(ProfGrid1);
	   Screen->Cursor = crDefault;
	   }
   return rv;
}
//---------------------------------------------------------------------------

int TTilSpreadSheetForm::GetSampleID(int ACol, int ARow)
{
   UnicodeString msg, ErrorMsg;
   double dValue;
   NTMANALYSISUNIT AnalUnit;
   AnalUnit.AnalysisUnitID = -1;
   UnicodeString Text;
   int SampleID = -1;
   vector<int> newids;
   UnicodeString Blank;
   int row;
   bool newAnalUnit = false;
   //bool newSample = false;
   vector<int> NewMDRows;

   try {
	   int AnalysisUnitID = ProfGrid1->AbsoluteCells[ACol][2]->CustomData;
	   // validate analysus unit depth, name, and thickness
	   if (AnalysisUnitID == 0) {
		 Text = ProfGrid1->AbsoluteCells[ACol][1]->Text;
		 if (!Text.IsEmpty()) {
		   if (TryStrToFloat(Text,dValue))
			 AnalUnit.Depth = dValue;
		   else {
			 msg = L"Analysis unit depth in column " + ProfGrid1->AbsoluteCols[ACol]->A1Name +
				   L" is not a valid number.";
			 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			 return SampleID;
			 }
		   }
		 Text = ProfGrid1->AbsoluteCells[ACol][2]->Text;
		 if (!Text.IsEmpty())
		   AnalUnit.AnalysisUnitName = Text;
		 }

	   int thick_row = FindRowCodeIC("#Anal.Thick", ProfGrid1);
	   if (thick_row > 0) {
		 NewMDRows.push_back(thick_row);
		 Text = ProfGrid1->AbsoluteCells[ACol][thick_row]->Text;
		 if (TryStrToFloat(Text,dValue))
		   AnalUnit.Thickness = dValue;
		 }
	   VerifyAnalUnitForm = new TVerifyAnalUnitForm(AnalUnit.Depth, AnalUnit.AnalysisUnitName,
		  AnalUnit.Thickness, this);
	   int rv = VerifyAnalUnitForm->ShowModal();
	   if (rv == mrOk) {
		 if (AnalUnit.Depth != VerifyAnalUnitForm->AnalUnitDepth) {
		   AnalUnit.Depth = VerifyAnalUnitForm->AnalUnitDepth;
		   ProfGrid1->AbsoluteCells[ACol][1]->Value = AnalUnit.Depth;
		   }
		 if (AnalUnit.AnalysisUnitName != VerifyAnalUnitForm->AnalUnitName) {
		   AnalUnit.AnalysisUnitName = VerifyAnalUnitForm->AnalUnitName;
		   ProfGrid1->AbsoluteCells[ACol][2]->Value = WideString(AnalUnit.AnalysisUnitName);
		   }
		 if (AnalUnit.Thickness != VerifyAnalUnitForm->AnalUnitThick) {
		   AnalUnit.Thickness = VerifyAnalUnitForm->AnalUnitThick;
		   if (thick_row == 0 && !AnalUnit.Thickness.IsEmpty()) {
			 ProfGrid1->InsertRow(3);
			 ProfGrid1->AbsoluteCells[1][3]->Value = WideString(L"#Anal.Thick");
			 ProfGrid1->AbsoluteCells[2][3]->Value = WideString(L"Analysis Unit Thickness");
			 thick_row = 3;
			 }
		   ProfGrid1->AbsoluteCells[ACol][thick_row]->Value = AnalUnit.Thickness;
		   }
		 }
	   delete VerifyAnalUnitForm;
	   if (rv == mrCancel)
		 return SampleID;

	   if (Sites->Count == 1)
		 SitePtr = (SITE*)Sites->Items[0];
	   if (!GetCollPtr())
		 return SampleID;

	   if (AllAnalUnits.size() == 0) {
		 // get all analysis units for the collection unit
		 NeotomaGetAnalUnitsByCollUnitID AnalUnits(ipsJSONS1, TcpClient1);
		 AnalUnits.AddParam(L"COLLUNITID", CollPtr->NeotomaCollUnitID);
		 ParentForm->StatusBar1->Panels->Items[0]->Text = AnalUnits.WebServiceName();
		 if (AnalUnits.Execute()) {
		   if (AnalUnits.Size() > 0)
			 AllAnalUnits = AnalUnits.Items;
		   }
		 else
		   return SampleID;
		 }

	   bool depth_found = false;
	   int name_found = -1;
	   int analunit_found = -1;
	   bool depth_isempty = AnalUnit.Depth.IsEmpty();
	   bool name_isempty = AnalUnit.AnalysisUnitName.IsEmpty();
	   for (unsigned int i=0; i<AllAnalUnits.size(); i++) {
		 if (!depth_isempty && !AllAnalUnits[i].Depth.IsEmpty()) {
		   if (AnalUnit.Depth == AllAnalUnits[i].Depth) {
			 depth_found = true;
			 if (AnalUnit.AnalysisUnitName == AllAnalUnits[i].AnalysisUnitName &&
				 AnalUnit.Thickness == AllAnalUnits[i].Thickness) {
			   analunit_found = AllAnalUnits[i].AnalysisUnitID;
			   break;
			  }
			 }
		   }
		 if (!name_isempty && !AllAnalUnits[i].AnalysisUnitName.IsEmpty()) {
		   if (SameText(AnalUnit.AnalysisUnitName,AllAnalUnits[i].AnalysisUnitName)) {
			 name_found = AllAnalUnits[i].AnalysisUnitID;
			 }
		   }
		 }

	   if (analunit_found != -1) {
		 // matching analysis unit exists; see if it's in the spreadsheet
		 int found_col = -1;
		 int StartCol = AbsHeaderColCount(ProfGrid1);
		 int EndCol = AbsContentColCount(ProfGrid1);
		 for (int col=StartCol; col<=EndCol; col++) {
		   int analunit = ProfGrid1->AbsoluteCells[col][2]->CustomData;
		   if (analunit == analunit_found) {
			 found_col = col;
			 break;
			 }
		   }
		 msg = L"Analysis Unit " + IntToStr(analunit_found);
		 if (found_col != -1)
		   msg += (L" in column " + ProfGrid1->AbsoluteCols[found_col]->A1Name);
		 msg += L" matches one entered.";
		 if (found_col != -1) {
		   msg += L" Cannot enter duplicate.";
		   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   return SampleID;
		   }
		 else {
		   msg += L" Use this analysis unit?";
		   if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes) {
			 ProfGrid1->AbsoluteCells[ACol][2]->CustomData = analunit_found;
			 AnalUnit.AnalysisUnitID = analunit_found;
			 AllAnalUnits.push_back(AnalUnit);
			 msg = L"Analysis Unit " + IntToStr(AnalUnit.AnalysisUnitID) + L" assigned to column " +
				   ProfGrid1->AbsoluteCols[ACol]->A1Name + L".";
			 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
			 }
		   else {
			 msg += L"The new analysis unit will duplicate one already in Neotoma.";
			 msg += L" This may be valid if correlation of depths or thicknesses is uncertain.";
			 msg += L" Do you want to continue?";
			 if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) != mrYes)
			   return SampleID;
			 }
		   }
		 }
	   else if (name_found != -1) {
		 // see if already in spreadsheet, if not query if to use.
		 int found_col = -1;
		 int StartCol = AbsHeaderColCount(ProfGrid1);
		 int EndCol = AbsContentColCount(ProfGrid1);
		 for (int col=StartCol; col<=EndCol; col++) {
		   if (AnalUnit.AnalysisUnitName == ProfGrid1->AbsoluteCells[col][2]->Text) {
			 found_col = col;
			 break;
			 }
		   }
		 if (found_col != -1) {
		   msg = L"An Analysis Unit with the same name already exists in column " +
				 ProfGrid1->AbsoluteCols[found_col]->A1Name + L". Cannot enter duplicate.";
		   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   return SampleID;
		   }
		 else {
		   msg = L"Analysis Unit " + IntToStr(name_found) +
				 L" has the same name. Use this analysis unit?";
		   if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes) {
			 ProfGrid1->AbsoluteCells[ACol][2]->CustomData = name_found;
			 AnalUnit.AnalysisUnitID = name_found;
			 AllAnalUnits.push_back(AnalUnit);
			 msg = L"Analysis Unit " + IntToStr(AnalUnit.AnalysisUnitID) + L" assigned to column " +
				   ProfGrid1->AbsoluteCols[ACol]->A1Name + L".";
			 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
			 }
		   else {
			 msg - L"Analysis Unit names cannnot be duplicated in the same Collection Unit.";
			 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			 return SampleID;
			 }
		   }
		 }
	   else if (depth_found) {
		 // TODO: need to write this code. For matching depths only. Probably need new dialog box.
		 }

	   if (AnalUnit.AnalysisUnitID == -1) {
		 // upload a new analysis unit
		 InsertData InsertAnalysisUnit(L"InsertAnalysisUnit", 8, ipsHTTPS1, ipsJSONS1, TcpClient1);
		 InsertAnalysisUnit.Add(L"COLLECTIONUNITID", CollPtr->NeotomaCollUnitID);
		 InsertAnalysisUnit.Add(L"ANALYSISUNITNAME", AnalUnit.AnalysisUnitName);
		 InsertAnalysisUnit.AddDouble(L"DEPTH", AnalUnit.Depth);
		 InsertAnalysisUnit.AddDouble(L"THICKNESS", AnalUnit.Thickness);
		 InsertAnalysisUnit.Add(L"FACIESID", -1, -1);    // facies not processed for now
		 row = FindRowCodeIC("#Anal.Mixed", ProfGrid1);
		 bool Mixed = (row > 0) ? ProfGrid1->AbsoluteCells[ACol][row]->CheckBoxChecked : false;
		 if (row > 0) NewMDRows.push_back(row);
		 InsertAnalysisUnit.Add(L"MIXED", Mixed);
		 InsertAnalysisUnit.Add(L"IGSN", Blank);
		 row = FindRowCodeIC("#Anal.Notes", ProfGrid1);
		 Text = (row > 0) ? Text = ProfGrid1->AbsoluteCells[ACol][row]->Text : Blank;
         if (row > 0) NewMDRows.push_back(row);
		 InsertAnalysisUnit.Add(L"NOTES", Text);
		 newids.clear();
		 ParentForm->StatusBar1->Panels->Items[0]->Text = L"InsertAnalysisUnit";
		 InsertAnalysisUnit.PostData();
		 if (InsertAnalysisUnit.Post(newids, ErrorMsg)) {
		   if (newids.size() == 1) {
			 AnalUnit.AnalysisUnitID = newids[0];
			 newAnalUnit = true;
			 }
		   else {
			 ErrorMsg = L"Error inserting into AnalysisUnits table!";
			 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			 return SampleID;
			 }
		   }
		 else {
		   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   return SampleID;
		   }
		 }

	   // TODO: Upload new sample
	   int DatasetIdx = GetCurrentDataset(ARow);
	   int DatasetID = Datasets[DatasetIdx].NeotomaDatasetID;

	   InsertData InsertSample(L"InsertSample", 9, ipsHTTPS1, ipsJSONS1, TcpClient1);
	   InsertSample.Add(L"ANALYSISUNITID", AnalUnit.AnalysisUnitID);
	   InsertSample.Add(L"DATASETID", DatasetID);
	   row = FindRowCodeIC("#Samp.Name", ProfGrid1);
	   Text = (row > 0) ? (UnicodeString)ProfGrid1->AbsoluteCells[ACol][row]->Text : Blank;
	   if (row > 0) NewMDRows.push_back(row);
	   InsertSample.Add(L"SAMPLENAME", Text);
	   row = FindRowCodeIC("#Samp.DateSamp", ProfGrid1);
	   Text = (row > 0) ? DateStr(ProfGrid1->AbsoluteCells[ACol][row]->Value) : Blank;
	   if (row > 0) NewMDRows.push_back(row);
	   InsertSample.Add(L"SAMPLEDATE", Text);
	   row = FindRowCodeIC("#Samp.DateAnal", ProfGrid1);
	   Text = (row > 0) ? DateStr(ProfGrid1->AbsoluteCells[ACol][row]->Value) : Blank;
	   if (row > 0) NewMDRows.push_back(row);
	   InsertSample.Add(L"ANALYSISDATE", Text);
	   InsertSample.Add(L"TAXONID", -1, -1);
	   row = FindRowCodeIC("#Samp.LabNum", ProfGrid1);
	   Text = (row > 0) ? (UnicodeString)ProfGrid1->AbsoluteCells[ACol][row]->Text : Blank;
	   if (row > 0) NewMDRows.push_back(row);
	   InsertSample.Add(L"LABNUMBER", Text);
	   row = FindRowCodeIC("#Samp.Method", ProfGrid1);
	   Text = (row > 0) ? (UnicodeString)ProfGrid1->AbsoluteCells[ACol][row]->Text : Blank;
	   if (row > 0) NewMDRows.push_back(row);
	   InsertSample.Add(L"PREPMETHOD", Text);
	   row = FindRowCodeIC("#Samp.Notes", ProfGrid1);
	   Text = (row > 0) ? (UnicodeString)ProfGrid1->AbsoluteCells[ACol][row]->Text : Blank;
	   if (row > 0) NewMDRows.push_back(row);
	   InsertSample.Add(L"NOTES", Text);

	   bool newSample = false;
	   newids.clear();
	   ParentForm->StatusBar1->Panels->Items[0]->Text = L"InsertSample";
	   InsertSample.PostData();
	   if (InsertSample.Post(newids, ErrorMsg)) {
		 if (newids.size() == 1) {
		   SampleID = newids[0];
		   newSample = true;
		   }
		 else {
		   ErrorMsg = L"Error inserting into Samples table!";
		   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   return SampleID;
		   }
		 }
	   else {
		 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 return SampleID;
		 }
	   msg = Blank;
	   if (newAnalUnit) {
		 msg = L"New Analysis Unit uploaded: AnalysisUnitID = " + IntToStr(AnalUnit.AnalysisUnitID) + L".";
		 NewMDRows.push_back(1);
		 NewMDRows.push_back(2);
		 sort(NewMDRows.begin(),NewMDRows.end());
		 for (unsigned int i=0; i<NewMDRows.size(); i++) {
		   if (!ProfGrid1->AbsoluteCells[ACol][NewMDRows[i]]->Value.IsEmpty())
		     ProfGrid1->AbsoluteCells[ACol][NewMDRows[i]]->Color = TColor(0x0099E6FF);  // yellow
		   }
		 }
	   if (newSample) {
		 if (!msg.IsEmpty())
		   msg += L"\n";
		 msg += L"New Sample uploaded: SampleID = " + IntToStr(SampleID) + L".";
		 }
	   if (!msg.IsEmpty())
		 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
	   }
   __finally {
	   FocusControl(ProfGrid1);
	   Screen->Cursor = crDefault;
	   }

   return SampleID;
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::UpdateAnalysisUnitDepth(int ACol, int ARow, int AnalysisUnitID,
	UnicodeString DepthStr)
{
   UnicodeString msg, ErrorMsg;
   bool updated = true;
   double Depth;

   try {
	   if (!TryStrToFloat(DepthStr,Depth)) {
		 msg = L"Not a valid number.";
		 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 return;
		 }

	   msg = L"Update Analysis Unit depth in Neotoma?";
	   if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) != mrYes) {
		 updated = false;
		 return;
		 }

	   Screen->Cursor = crHourGlass;
	   UpdateData UpdateAnalUnitDepth(L"UpdateAnalysisUnitDepth", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
	   UpdateAnalUnitDepth.Add(L"ANALYSISUNITID", AnalysisUnitID);
	   UpdateAnalUnitDepth.Add(L"DEPTH", Depth);
	   ParentForm->StatusBar1->Panels->Items[0]->Text = L"UpdateAnalysisUnitDepth";
	   if (UpdateAnalUnitDepth.Post(ErrorMsg)) {
		 ProfGrid1->Cells[ACol][ARow]->Color = TColor(0x00B4E0C6);  // light green
		 msg = L"Depth of Analysis Unit " + IntToStr(AnalysisUnitID) + L" updated to " +
			   FloatToStr(Depth) + L".";
		 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
		 }
	   else if (!ErrorMsg.IsEmpty()) {
		 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
         updated = false;
		 }
	   }
   __finally {
	   if (!updated)
		 ProfGrid1->Cells[ACol][ARow]->Color = TColor(0x00ADCBF8);  // light orange
	   FocusControl(ProfGrid1);
	   Screen->Cursor = crDefault;
	   }
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::UpdateAnalysisUnitName(int ACol, int ARow, int AnalysisUnitID,
	UnicodeString AnalysisUnitName)
{
   UnicodeString msg, ErrorMsg;
   bool updated = false;

   try {
	   msg = L"Update Analysis Unit name in Neotoma?";
	   if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) != mrYes)
		 return;

	   Screen->Cursor = crHourGlass;
	   UpdateData UpdateAnalUnitName(L"UpdateAnalysisUnitName", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
	   UpdateAnalUnitName.Add(L"ANALYSISUNITID", AnalysisUnitID);
	   UpdateAnalUnitName.Add(L"ANALYSISUNITNAME", AnalysisUnitName);
	   ParentForm->StatusBar1->Panels->Items[0]->Text = L"UpdateAnalysisUnitName";
	   if (UpdateAnalUnitName.Post(ErrorMsg)) {
		 ProfGrid1->Cells[ACol][ARow]->Color = TColor(0x00B4E0C6);  // light green
		 updated = true;
		 msg = L"Name of Analysis Unit " + IntToStr(AnalysisUnitID) + L" updated to «" +
			   AnalysisUnitName + L"».";
		 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
		 }
	   else if (!ErrorMsg.IsEmpty()) {
		 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 }
	  }
   __finally {
	   if (!updated)
		 ProfGrid1->Cells[ACol][ARow]->Color = TColor(0x00ADCBF8);  // light orange
	   FocusControl(ProfGrid1);
	   Screen->Cursor = crDefault;
	   }
}
//---------------------------------------------------------------------------

bool TTilSpreadSheetForm::UpdateVariable(int DatasetID, int VariableID, int NewVariableID)
{
   UnicodeString ErrorMsg;

   if (NewVariableID == -1)
	 return false;

   NeotomaGetDatasetSampleIDs Samples(ipsJSONS1, TcpClient1);
   Samples.AddParam(L"DATASETID", DatasetID);
   ParentForm->StatusBar1->Panels->Items[0]->Text = Samples.WebServiceName();
   if (Samples.Execute()) {
	 if (Samples.Size() == 0)
	   return false;
	 }
   else
	 return false;

   int SampleID1 = Samples.Items[0];
   int SampleID2 = SampleID1;
   unsigned int size = Samples.Items.size();
   unsigned int i = 0;
   bool success = true;
   do {
	  while (i < size-1 && Samples.Items[i+1] == SampleID2+1) {
		SampleID2++;
		i++;
		}
	  UpdateData UpdateVariable(L"UpdateDatasetVariable", 4, ipsHTTPS1, ipsJSONS1, TcpClient1);
	  ParentForm->StatusBar1->SimpleText = L"UpdateDatasetVariable";
	  UpdateVariable.Add(L"OLDVARIABLEID", VariableID);
	  UpdateVariable.Add(L"NEWVARIABLEID", NewVariableID);
	  UpdateVariable.Add(L"SAMPLEID1", SampleID1);
	  UpdateVariable.Add(L"SAMPLEID2", SampleID2);
	  if (UpdateVariable.Post(ErrorMsg)) {
		i++;
		if (i < size) {
		  SampleID1 = Samples.Items[i];
		  SampleID2 = SampleID1;
		  }
		}
	  else {
		MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		success = false;
		}
	  } while (i < size && success);
   return success;
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::UploadNeotomaGeochron(GEOCHRON& Date)
{
   UnicodeString msg, ErrorMsg;
   int GeochronTypeID;
   int AgeTypeID;
   int DatasetID;
   int SampleID;
   set<int> Pubs;
   int AnalysisUnitID;
   vector<int> newids;
   bool success = false;

   // Get current collection unit
   if (!GetCollPtr())
	 return;
   msg = L"Upload geochronologic measurement to Collection Unit " +
		 IntToStr(CollPtr->NeotomaCollUnitID) + L", Handle: «" + CollPtr->NeotomaHandle +
		 L"»";
   if (!CollPtr->CollectionName.IsEmpty())
	 msg += (L", Name: «" + CollPtr->CollectionName +L"»");
   msg += L"?";
   if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) != mrYes)
	 return;

   if (!Login->IsLoggedIn) {
	 NeotomaLoginForm = new TNeotomaLoginForm(this);
	 NeotomaLoginForm->ShowModal();
	 delete NeotomaLoginForm;
	 }
   if (!Login->IsLoggedIn)
	 return;

   Screen->Cursor = crHourGlass;

   try {
	 if (!GetGeochronIDs(Date, GeochronTypeID, AgeTypeID))
	   return;

	 // validate publications and get set of PublicationIDs
	 for (unsigned int i=0; i < Date.publications.size(); i++) {
	   PUBLICATION* pub = Date.publications[i];
	   if (pub->NeotomaID != -1) {
		 Pubs.insert(pub->NeotomaID);
	   }
	   else {
		 msg = L"Publication «" + pub->GetShortCitation(false)  + L"» is not uploaded to Neotoma.";
		 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 return;
		 }
	   }

	 AnalysisUnitID = -1;
	 // check if analysis unit already exists
	 // must match by name or by depth and non-null thickness
	 if (!Date.AnalUnit.IsEmpty() || !Date.Thickness.IsEmpty()) {
	   if (!GetDateAnalysisUnitID(Date, AnalysisUnitID))
		 return;
	   }

	 if (AnalysisUnitID == -1) {  // upload new analysis unit
	   if (!UploadAnalysisUnit(Date, AnalysisUnitID))
		 return;
	   }

	 // get DatasetID
	 DatasetID = -1;
	 NeotomaGetDatasetIDByCollUnitAndType GetDatasetID(ipsJSONS1, TcpClient1);
	 GetDatasetID.AddParam(L"COLLUNITID", CollPtr->NeotomaCollUnitID);
	 GetDatasetID.AddParam(L"DATASETTYPEID", 1);
	 ParentForm->StatusBar1->Panels->Items[0]->Text = GetDatasetID.WebServiceName();
	 if (GetDatasetID.Execute()) {
	   if (GetDatasetID.Size() == 1)
		 DatasetID = GetDatasetID.Items[0];
	   }
	 else
	   return;

	 if (DatasetID == -1) {   // geochron dataset doesn't exist
	   // upload new geochron dataset
	   int DatasetTypeID = 1;
	   newids.clear();
	   InsertData InsertDataset(L"InsertDataset", 3, ipsHTTPS1, ipsJSONS1, TcpClient1);
	   InsertDataset.Add(L"COLLECTIONUNITID", CollPtr->NeotomaCollUnitID, -1);
	   InsertDataset.Add(L"DATASETTYPEID", DatasetTypeID, -1);
	   InsertDataset.Add(L"NOTES", cxBlobEdit1->Text);
	   ParentForm->StatusBar1->Panels->Items[0]->Text = L"InsertDataset";
	   InsertDataset.PostData();
	   if (InsertDataset.Post(newids, ErrorMsg)) {
		 if (newids.size() == 1)
		   DatasetID = newids[0];
		 else {
		   ErrorMsg = L"Error inserting into Datasets table!";
		   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   return;
		   }
		 }
	   else {
		 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 return;
		 }

	   // upload geochron dataset publications
	   if (Pubs.size() > 0) {
		 InsertData InsertDatasetPub(L"InsertDatasetPublication", 3, ipsHTTPS1, ipsJSONS1, TcpClient1);
		 bool primary = false;
		 for (set<int>::iterator itr = Pubs.begin(); itr != Pubs.end(); itr++) {
		   InsertDatasetPub.Add(L"DATASETID", DatasetID, -1);
		   InsertDatasetPub.Add(L"PUBLICATIONID", *itr, -1);
		   InsertDatasetPub.Add(L"PRIMARYPUB", primary);
		   }
		 ParentForm->StatusBar1->Panels->Items[0]->Text = L"InsertDatasetPublication";
		 InsertDatasetPub.PostData();
		 if (!InsertDatasetPub.Post(ErrorMsg)) {
		   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   return;
		   }
		 }

	   // upload investigators
	   if (GeochronDataset.Investigators.size() > 0) {
		 InsertData InsertDatasetPI(L"InsertDatasetPI", 3, ipsHTTPS1, ipsJSONS1, TcpClient1);
		 int order = 1;
		 for (unsigned int j=0; j<GeochronDataset.Investigators.size(); j++) {
		   if (GeochronDataset.Investigators[j]->NeotomaContactID != -1) {
			 InsertDatasetPI.Add(L"DATASETID", DatasetID, -1);
			 InsertDatasetPI.Add(L"CONTACTID", GeochronDataset.Investigators[j]->NeotomaContactID, -1);
			 InsertDatasetPI.Add(L"PIORDER", order++, -1);
			 }
		   else {
			 msg = L"Investigator " + GeochronDataset.Investigators[j]->ShortContactName +
				   L" not uploaded. Not matched with Neotoma ContactID.";
			 MessageDlg(msg, mtWarning, TMsgDlgButtons() << mbOK, 0);
			 }
		   }
		 if (order > 1) {
		   ParentForm->StatusBar1->Panels->Items[0]->Text = L"InsertDatasetPI";
		   InsertDatasetPI.PostData();
		   if (!InsertDatasetPI.Post(ErrorMsg)) {
			 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			 return;
			 }
		   }
		 }
	   }

	 // upload geochron sample
	 newids.clear();
	 NEOTOMASAMPLE Sample;  // blank sample
	 InsertData InsertSample(L"InsertSample", 9, ipsHTTPS1, ipsJSONS1, TcpClient1);
	 InsertSample.Add(L"ANALYSISUNITID", AnalysisUnitID);
	 InsertSample.Add(L"DATASETID", DatasetID);
	 InsertSample.Add(L"SAMPLENAME", Sample.SampleName);
	 InsertSample.Add(L"SAMPLEDATE", DateStr(Sample.DateSampled));
	 InsertSample.Add(L"ANALYSISDATE", DateStr(Sample.DateAnalyzed));
	 InsertSample.Add(L"TAXONID", Sample.TaxonID, -1);
	 InsertSample.Add(L"LABNUMBER", Date.LabNumber);
	 InsertSample.Add(L"PREPMETHOD", Sample.PrepMethod);
	 InsertSample.Add(L"NOTES", Date.Notes);
	 ParentForm->StatusBar1->Panels->Items[0]->Text = L"InsertSample";
	 InsertSample.PostData();
	 if (InsertSample.Post(newids, ErrorMsg)) {
	   if (newids.size() == 1)
		 SampleID = newids[0];
	   else {
		 ErrorMsg = L"Error inserting into Samples table!";
		 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 return;
		 }
	   }
	 else {
	   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return;
	   }

	 // upload new geochron measurement
	 InsertData InsertGeochron(L"InsertGeochron", 10, ipsHTTPS1, ipsJSONS1, TcpClient1);
	 InsertGeochron.Add(L"SAMPLEID", SampleID, -1);
	 InsertGeochron.Add(L"GEOCHRONTYPEID", GeochronTypeID, -1);
	 InsertGeochron.Add(L"AGETYPEID", AgeTypeID, -1);
	 InsertGeochron.AddDouble(L"AGE", Date.Age);
	 InsertGeochron.AddDouble(L"ERROROLDER", Date.ErrorOlder);
	 InsertGeochron.AddDouble(L"ERRORYOUNGER", Date.ErrorYounger);
	 InsertGeochron.Add(L"INFINITE", Date.GreaterThan);
	 InsertGeochron.Add(L"LABNUMBER", Date.LabNumber);
	 InsertGeochron.Add(L"MATERIALDATED", Date.MaterialDated);
	 InsertGeochron.Add(L"NOTES", Date.Notes);

	 newids.clear();
	 ParentForm->StatusBar1->Panels->Items[0]->Text = L"InsertGeochron";
	 InsertGeochron.PostData();
	 if (InsertGeochron.Post(newids, ErrorMsg)) {
	   if (newids.size() == 1) {
		 Date.NeotomaGeochronID = newids[0];
		 success = true;
		 }
	   else {
		 ErrorMsg = L"Error inserting into Geochronology table!";
		 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 return;
		 }
	   }
	 else {
	   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return;
	   }

	 // upload geochron pubs
	 if (Pubs.size() > 0) {
	   InsertData InsertGeochronPubs(L"InsertGeochronPublication", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
	   for (set<int>::iterator itr = Pubs.begin(); itr != Pubs.end(); itr++) {
		 InsertGeochronPubs.Add(L"GEOCHRONID", Date.NeotomaGeochronID, -1);
		 InsertGeochronPubs.Add(L"PUBLICATIONID", *itr, -1);
		 }
	   ParentForm->StatusBar1->Panels->Items[0]->Text = L"InsertGeochronPublication";
	   InsertGeochronPubs.PostData();
	   if (!InsertGeochronPubs.Post(ErrorMsg)) {
		 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 return;
		 }
	   }

	 // update geochron datasest publications
	 UpdateData UpdateDatasetPubs(L"UpdateGeochronDatasetPubs", 1, ipsHTTPS1, ipsJSONS1, TcpClient1);
	 ParentForm->StatusBar1->Panels->Items[0]->Text = L"UpdateGeochronDatasetPubs";
	 UpdateDatasetPubs.Add(L"DATASETID", DatasetID);
	 if (!UpdateDatasetPubs.Post(ErrorMsg))
	   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);

	 // upload radiocarbon parameters
	 if (SameText(Date.Method,L"Carbon-14") && Date.Parameters.size() > 0) {  // radiocarbon date has params
	   map<UnicodeString,double> RadiocarbonParams;
	   if (GetRadiocarbonParams(Date, RadiocarbonParams)) {
		 InsertData InsertRadiocarbon(L"InsertRadiocarbon", 10, ipsHTTPS1, ipsJSONS1, TcpClient1);
		 InsertRadiocarbon.Add(L"GEOCHRONID", Date.NeotomaGeochronID, -1);
		 InsertRadiocarbon.AddInt(L"RADIOCARBONMETHODID", GeochronParam(RadiocarbonParams, L"Method"));
		 InsertRadiocarbon.AddDouble(L"MASSCMG", GeochronParam(RadiocarbonParams, L"Mass C (mg)"));
		 InsertRadiocarbon.AddDouble(L"PERCENTC", GeochronParam(RadiocarbonParams, L"%C"));
		 InsertRadiocarbon.AddDouble(L"PERCENTN", GeochronParam(RadiocarbonParams, L"%N"));
		 InsertRadiocarbon.AddDouble(L"CNRATIO", GeochronParam(RadiocarbonParams, L"C:N"));
		 InsertRadiocarbon.AddDouble(L"DELTA13C", GeochronParam(RadiocarbonParams, L"δ13C"));
		 InsertRadiocarbon.AddDouble(L"DELTA15N", GeochronParam(RadiocarbonParams, L"δ15N"));
		 InsertRadiocarbon.AddDouble(L"PERCENTCOLLAGEN", GeochronParam(RadiocarbonParams, L"%collagen"));
		 InsertRadiocarbon.AddDouble(L"RESERVOIR", GeochronParam(RadiocarbonParams, L"Reservoir (yrs)"));
		 ParentForm->StatusBar1->Panels->Items[0]->Text = L"InsertRadiocarbon";
		 InsertRadiocarbon.PostData();
		 if (!InsertRadiocarbon.Post(ErrorMsg)) {
		   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   return;
		   }
		 }
	   }
	 }
   __finally {
	 if (success) {
	   msg = L"Success: Geochronologic measurment uploaded! GeochronID = " +
			 IntToStr(newids[0]) + L".";
	   MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
	   }
	 ParentForm->StatusBar1->Panels->Items[0]->Text = L"";
	 Screen->Cursor = crDefault;
	 }
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::DeleteGeochron(int GeochronID)
{
   UnicodeString ErrorMsg;

   UnicodeString msg = L"Delete geochronologic measurement from Neotoma?";
   if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) != mrYes)
	 return;

   if (!Login->IsLoggedIn) {
	 NeotomaLoginForm = new TNeotomaLoginForm(this);
	 NeotomaLoginForm->ShowModal();
	 delete NeotomaLoginForm;
	 }
   if (!Login->IsLoggedIn)
	 return;

   try {
	   DeleteData DeleteGeochron(L"DeleteGeochron", 1, ipsHTTPS1, ipsJSONS1, TcpClient1);
	   ParentForm->StatusBar1->Panels->Items[0]->Text = L"DeleteGeochron";
	   DeleteGeochron.Add(L"GEOCHRONID", GeochronID);
	   if (DeleteGeochron.Post(ErrorMsg)) {
		 msg = L"GeochronID " + IntToStr(GeochronID) + L" deleted from Geochronology table.";
		 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
		 }
	   else {
		 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 return;
		 }
	   }
   __finally {
       ParentForm->StatusBar1->Panels->Items[0]->Text = L"";
	   Screen->Cursor = crDefault;
	   }
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::UpdateGeochronPIs(set<int>& NewContactIDs)
{
   UnicodeString msg, ErrorMsg;

   if (!Login->IsLoggedIn) {
	 NeotomaLoginForm = new TNeotomaLoginForm(this);
	 NeotomaLoginForm->ShowModal();
	 delete NeotomaLoginForm;
	 }
   if (!Login->IsLoggedIn)
	 return;

   try {
	   NeotomaInvestigator Investigators(ipsJSONS1, TcpClient1);
	   Investigators.AddParam(L"DATASETID", GeochronDataset.NeotomaDatasetID);
	   ParentForm->StatusBar1->Panels->Items[0]->Text = Investigators.WebServiceName();
	   if (!Investigators.Execute())
		 return;

	   set<int> OldContactIDs;
	   if (Investigators.Size() > 0) {
		 for (unsigned int i=0; i<Investigators.Size(); i++)
		   OldContactIDs.insert(Investigators.Items[i].ContactID);
		 }

	   set<int>::iterator itr;

	   // upload new investigators
	   for (itr = NewContactIDs.begin(); itr != NewContactIDs.end(); itr++) {
		 if (OldContactIDs.count(*itr) == 0) {
		   InsertData InsertDatasetPI(L"InsertNewDatasetPI", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
		   InsertDatasetPI.Add(L"DATASETID", GeochronDataset.NeotomaDatasetID, -1);
		   InsertDatasetPI.Add(L"CONTACTID", *itr, -1);
		   ParentForm->StatusBar1->Panels->Items[0]->Text = L"InsertNewDatasetPI";
		   InsertDatasetPI.PostData();
		   if (!InsertDatasetPI.Post(ErrorMsg)) {
			 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			 return;
			 }
		   }
		 }

	   // delete investigators
	   for (itr = OldContactIDs.begin(); itr != OldContactIDs.end(); itr++) {
		 if (NewContactIDs.count(*itr) == 0) {
		   DeleteData DeleteDatasetPI(L"DeleteDatasetPI", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
		   ParentForm->StatusBar1->Panels->Items[0]->Text = L"DeleteDatasetPI";
		   DeleteDatasetPI.Add(L"DATASETID", GeochronDataset.NeotomaDatasetID);
		   DeleteDatasetPI.Add(L"CONTACTID", *itr);
		   if (!DeleteDatasetPI.Post(ErrorMsg)) {
			 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			 return;
			 }
		   }
		 }
	   MessageDlg(L"Geochronology investigators updated.", mtInformation, TMsgDlgButtons() << mbOK, 0);
	   }
   __finally {
	   ParentForm->StatusBar1->Panels->Items[0]->Text = L"";
	   Screen->Cursor = crDefault;
	   }
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::UpdateNeotomaGeochron(GEOCHRON& Date)
{
   UnicodeString msg, ErrorMsg;
   bool update_geochron;
   int NewAnalysisUnitID;
   NTMGEOCHRON NeotomaGeochron;
   set<int> NewPubs;
   set<int> OldPubs;
   set<int> UploadPubs;
   set<int> DeletePubs;
   set<int> DatasetPubs;
   set<int> Pubs;
   bool success = false;

   if (!Login->IsLoggedIn) {
	 NeotomaLoginForm = new TNeotomaLoginForm(this);
	 NeotomaLoginForm->ShowModal();
	 delete NeotomaLoginForm;
	 }
   if (!Login->IsLoggedIn)
	 return;

   Screen->Cursor = crHourGlass;

   // validate metadata
   try {
	   // get currently stored geochron from Neotoma
	   NeotomaGetGeochronByGeochronID GetGeochron(ipsJSONS1, TcpClient1);
	   GetGeochron.AddParam(L"GEOCHRONID", Date.NeotomaGeochronID);
	   ParentForm->StatusBar1->Panels->Items[0]->Text = GetGeochron.WebServiceName();
	   if (GetGeochron.Execute()) {
		 if (GetGeochron.Size() == 1) {
		   NeotomaGeochron = GetGeochron.Items[0];
		   update_geochron = !IsSameGeochron(NeotomaGeochron.GeochronTypeID, NeotomaGeochron.AgeTypeID, Date, GetGeochron.Items[0]);
		   }
		 else {  // this should never happen, but...
		   msg = L"ERROR: GeochronID " + IntToStr(Date.NeotomaGeochronID) + L" not found in Neotoma.";
		   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   return;
		   }
		 }
	   else
		 return;

	   if (update_geochron) {  // validate ages
		 if (!ValidateDate(Date))
		   return;
		 }

	   // validate publications
	   for (unsigned int i=0; i < Date.publications.size(); i++) {
		 PUBLICATION* pub = Date.publications[i];
		 if (pub->NeotomaID != -1) {
		   NewPubs.insert(pub->NeotomaID);
		   }
		 else {
		   msg = L"Publication «" + pub->GetShortCitation(false)  + L"» is not uploaded to Neotoma.";
		   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   return;
		   }
		 }
	   UnicodeString GeochronIDList = IntToStr(Date.NeotomaGeochronID);
	   NeotomaPublicationsByGeochronID GeochronPubIDs(ipsJSONS1, TcpClient1);
	   GeochronPubIDs.AddParam(L"GEOCHRONIDLIST", GeochronIDList);
	   ParentForm->StatusBar1->Panels->Items[0]->Text = GeochronPubIDs.WebServiceName();
	   if (!GeochronPubIDs.Execute())       // GeochronID, PublicationID
		 return;
	   for (unsigned int i=0; i < GeochronPubIDs.Items.size(); i++)
		 OldPubs.insert(GeochronPubIDs.Items[i].second);

	   // get pubs to be uploaded and deleted
	   set_difference(NewPubs.begin(), NewPubs.end(), OldPubs.begin(), OldPubs.end(), inserter(UploadPubs, UploadPubs.begin()));
	   set_difference(OldPubs.begin(), OldPubs.end(), NewPubs.begin(), NewPubs.end(), inserter(DeletePubs, DeletePubs.begin()));

	   // check differences in analysis unit
	   // check if depth or thickness has changed
	   NeotomaGetGeochronAnalysisUnit AnalUnit(ipsJSONS1, TcpClient1);
	   AnalUnit.AddParam(L"GEOCHRONID", Date.NeotomaGeochronID);
	   ParentForm->StatusBar1->Panels->Items[0]->Text = AnalUnit.WebServiceName();
	   if (AnalUnit.Execute()) {
		 if (AnalUnit.Size() == 0) {
		   UnicodeString msg = L"GeochronID " + IntToStr(Date.NeotomaGeochronID) + L" is not in Neotoma!";
		   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   return;
		   }
		 }
	   else
		 return;
	   ParentForm->StatusBar1->Panels->Items[0]->Text = "";

	   GEOCHRONANALUNIT& OldAnalUnit = AnalUnit.Items[0];

       // TODO: need to ensure geochron analysis unit isn't connected to other data

	   if (Date.Depth != OldAnalUnit.Depth || Date.Thickness != OldAnalUnit.Thickness || Date.AnalUnit != OldAnalUnit.AnalysisUnitName) {
		 if (!Date.Depth.IsEmpty())
			Date.Depth.ChangeType(varDouble);
		 if (!Date.Thickness.IsEmpty())
			Date.Thickness.ChangeType(varDouble);
		 UpdateData UpdateGeochronAnalUnit(L"UpdateGeochronAnalysisUnit", 5, ipsHTTPS1, ipsJSONS1, TcpClient1);
		 UpdateGeochronAnalUnit.Add(L"GEOCHRONID", Date.NeotomaGeochronID);
		 UpdateGeochronAnalUnit.Add(L"ANALYSISUNITID", OldAnalUnit.AnalysisUnitID);
		 UpdateGeochronAnalUnit.AddDouble(L"DEPTH", Date.Depth);
		 UpdateGeochronAnalUnit.AddDouble(L"THICKNESS", Date.Thickness);
		 UpdateGeochronAnalUnit.Add(L"ANALYSISUNITNAME", Date.AnalUnit);
		 ParentForm->StatusBar1->Panels->Items[0]->Text = L"UpdateGeochronAnalysisUnit";
		 if (!UpdateGeochronAnalUnit.Post(ErrorMsg)) {
		   msg = L"ERROR: " + ErrorMsg;
		   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   return;
		   }

		 msg = L"Anaysis unit updated for GeochronID " + IntToStr(Date.NeotomaGeochronID) + L".";
		 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);

		 if (Date.Depth != OldAnalUnit.Depth || Date.AnalUnit != OldAnalUnit.AnalysisUnitName) {
		   NeotomaGetGeochronControlCount GeochronControlCount(ipsJSONS1, TcpClient1);
		   GeochronControlCount.AddParam(L"GEOCHRONID", Date.NeotomaGeochronID);
		   ParentForm->StatusBar1->Panels->Items[0]->Text = GeochronControlCount.WebServiceName();
		   if (GeochronControlCount.Execute()) {
			 if (GeochronControlCount.Size() == 1) {
			   if (GeochronControlCount.Items[0] > 0) {
				 if (Date.Depth != OldAnalUnit.Depth)
				   msg = L"WARNING: Chronology controls are assigned to GeochronID " + IntToStr(Date.NeotomaGeochronID) +
						 L". Changing the depth may have implications for any chronologies based on this geochonologic measurement.";
				 else
				   msg = L"WARNING: Chronology controls are assigned to GeochronID " + IntToStr(Date.NeotomaGeochronID) +
						 L". Changing the Analysis Unit may have implications for any chronologies based on this geochonologic measurement.";
				 MessageDlg(msg, mtWarning, TMsgDlgButtons() << mbOK, 0);
				 }
			   }
			 }
		   else
			 return;
		   }
		 }

	   // check AgeType
	   int AgeTypeID = NeotomaGeochron.AgeTypeID;
	   if (!SameText(Date.AgeUnits, NeotomaGeochron.AgeType)) {
		 NeotomaAgeTypesTable AgeTypesTable(ipsJSONS1, TcpClient1);
		 //NeotomaAgeTypesTable AgeTypesTable(ipsJSONS1, TcpClient1);
		 ParentForm->StatusBar1->Panels->Items[0]->Text = AgeTypesTable.WebServiceName();
		 if (!AgeTypesTable.Execute())
		   return;
		 AgeTypeID = -1;
		 for (unsigned int i=0; i<AgeTypesTable.Size(); i++) {
		   if (SameText(Date.AgeUnits, AgeTypesTable.Items[i].AgeType)) {
			 AgeTypeID = AgeTypesTable.Items[i].AgeTypeID;
			 break;
			 }
		   }
		 if (AgeTypeID == -1) {
		   msg = L"ERROR: Age type «" + Date.AgeUnits + L"» not valid.";
		   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   return;
		   }
		 update_geochron = true;
		 }

	   // update geochronology
	   if (update_geochron) {
		 UpdateData UpdateGeochron(L"UpdateGeochron", 10, ipsHTTPS1, ipsJSONS1, TcpClient1);
		 UpdateGeochron.Add(L"GEOCHRONID", Date.NeotomaGeochronID);
		 UpdateGeochron.Add(L"GEOCHRONTYPEID", NeotomaGeochron.GeochronTypeID);
		 UpdateGeochron.Add(L"AGETYPEID", AgeTypeID);
		 UpdateGeochron.AddDouble(L"AGE", Date.Age);
		 UpdateGeochron.AddDouble(L"ERROROLDER", Date.ErrorOlder);
		 UpdateGeochron.AddDouble(L"ERRORYOUNGER", Date.ErrorYounger);
		 UpdateGeochron.Add(L"INFINITE", Date.GreaterThan);
		 UpdateGeochron.Add(L"LABNUMBER", Date.LabNumber);
		 UpdateGeochron.Add(L"MATERIALDATED", Date.MaterialDated);
		 UpdateGeochron.Add(L"NOTES", Date.Notes);
		 ParentForm->StatusBar1->Panels->Items[0]->Text = L"UpdateGeochron";
		 if (!UpdateGeochron.Post(ErrorMsg)) {
		   msg = L"ERROR: " + ErrorMsg;
		   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   return;
		   }
		 }

	   set<int>::iterator itr;
	   if (UploadPubs.size() > 0) {
		 InsertData InsertGeochronPubs(L"InsertGeochronPublication", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
		 for (itr = UploadPubs.begin(); itr != UploadPubs.end(); itr++) {
		   InsertGeochronPubs.Add(L"GEOCHRONID", Date.NeotomaGeochronID, -1);
		   InsertGeochronPubs.Add(L"PUBLICATIONID", *itr, -1);
		   }
		 ParentForm->StatusBar1->Panels->Items[0]->Text = L"InsertGeochronPublication";
		 InsertGeochronPubs.PostData();
		 if (!InsertGeochronPubs.Post(ErrorMsg)) {
		   msg = L"ERROR: " + ErrorMsg;
		   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   return;
		   }
		 }
	   if (DeletePubs.size() > 0) {
		 for (itr = DeletePubs.begin(); itr != DeletePubs.end(); itr++) {
		   DeleteData DeletePub(L"DeleteGeochronPublication", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
		   DeletePub.Add(L"GEOCHRONID", Date.NeotomaGeochronID);
		   DeletePub.Add(L"PUBLICATIONID", *itr);
		   ParentForm->StatusBar1->Panels->Items[0]->Text = L"DeleteGeochronPublication";
		   if (!DeletePub.Post(ErrorMsg)) {
			 msg = L"ERROR: " + ErrorMsg;
			 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			 return;
			 }
		   }
		 }

	   // update geochron datasest publications
	   UpdateData UpdateDatasetPubs(L"UpdateGeochronDatasetPubs", 1, ipsHTTPS1, ipsJSONS1, TcpClient1);
	   ParentForm->StatusBar1->Panels->Items[0]->Text = L"UpdateGeochronDatasetPubs";
	   UpdateDatasetPubs.Add(L"DATASETID", GeochronDataset.NeotomaDatasetID);
	   if (!UpdateDatasetPubs.Post(ErrorMsg)) {
		 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 return;
		 }

	   success = true;
	   }
   __finally {
	   ParentForm->StatusBar1->Panels->Items[0]->Text = L"";
	   Screen->Cursor = crDefault;
	   if (success) {
		 msg = L"Geochron updated. GeochronID = " + IntToStr(Date.NeotomaGeochronID) + L".";
		 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
		 }
   }
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::UploadTaxonDated(int GeochronID, TAXONDATED& TaxonDated)
{
   UnicodeString msg, ErrorMsg;
   bool uploaded = false;

   if (TaxonDated.Taxon.IsEmpty()) {
	 msg = L"Taxon name cannot be blank!";
	 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 return;
	 }

   if (!Login->IsLoggedIn) {
	 NeotomaLoginForm = new TNeotomaLoginForm(this);
	 NeotomaLoginForm->ShowModal();
	 delete NeotomaLoginForm;
	 }
   if (!Login->IsLoggedIn)
	 return;

   try {
	   int SpecimenID = -1;
	   int SampleID = -1;

	   if (!TaxonDated.UserSpecID.IsEmpty()) {
		 // Scenario 1a
		 // get SpecimenID
		 SpecimenID = TaxonDated.Specimen->NeotomaSpecimenID;

		 // get SampleID
		 NeotomaSpecimenSampleID SpecSample(ipsJSONS1, TcpClient1);
		 SpecSample.AddParam(L"SPECIMENID", SpecimenID);
		 ParentForm->StatusBar1->Panels->Items[0]->Text = SpecSample.WebServiceName();
		 if (!SpecSample.Execute())
		   return;
		 if (SpecSample.Size() == 1)
		   SampleID = SpecSample.Items[0];
		 else {
		   msg = L"SpecimenID " + TaxonDated.UserSpecID + L" is not valid.";
		   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   return;
		   }
		 }

	   // get TaxonID -- need this for all scenarios and for establsihing scenarios 3a and 3b
	   int TaxonID;
	   UnicodeString TaxaGroupID;
	   if (!GetTaxonID(TaxonDated.Taxon, TaxonID, TaxaGroupID))
		 return;

	   // get SampleID if not already defined (scenario 1a not met)
	   // For scenarios 3a and 3b, the sample may be in the spreadsheet, but if not,
	   // it may be in the database. For example, if the specimen is a plant macrofossi,
	   // the plant macrofossil dataset may or may not exist in the spreadsheet, e.g.
	   // a pollen dataset may have been downloaded, but not the plant macro dataset.
	   int DatasetID = -1;
	   int DatasetTypeID = -1;
	   if (SampleID == -1) {
		 // scenario 3a, get DatasetTypeID if for scenario 3b if necessary
		 // see if appropriate dataset type exists in spreadsheet
		 SPECIMENDATETAXAGROUPS TaxaGroupDatasetTypes;
		 for (unsigned int i=0; i<Datasets.size(); i++) {
		   if (TaxaGroupDatasetTypes.IsTaxaGroupInDatasetType(TaxaGroupID, Datasets[i].NeotomaDatasetTypeID)) {
			 DatasetID = Datasets[i].NeotomaDatasetID;
			 DatasetTypeID = Datasets[i].NeotomaDatasetTypeID;
			 break;
			 }
		   }

		 if (DatasetID != -1) {
		   // Specimen dataset type exists in spreadsheet, see if Sample for specimen
		   // dataset type exists for same analysis unit as date.
		   NeotomaSampleIDForDatasetIDFromGeochronAnalUnit DatasetSampleID(ipsJSONS1, TcpClient1);
		   DatasetSampleID.AddParam(L"GEOCHRONID", GeochronID);
		   DatasetSampleID.AddParam(L"DATASETID", DatasetID);
		   ParentForm->StatusBar1->Panels->Items[0]->Text = DatasetSampleID.WebServiceName();
		   if (!DatasetSampleID.Execute())
			 return;
		   if (DatasetSampleID.Size() ==  1)
			 SampleID = DatasetSampleID.Items[0];
		   }
		 else if (DatasetID == -1) {
		   // Dataset type for specimen is not in spreadsheeet, see if appropriate
		   // dataset type exists in Neotoma and get SampleID.
		   // get DatasetTypes for specimen's TaxaGroup
		   NeotomaDatasetTypesByTaxaGroupID DatasetTypeIDs(ipsJSONS1, TcpClient1);
		   DatasetTypeIDs.AddParam(L"TAXAGROUPID", TaxaGroupID);
		   ParentForm->StatusBar1->Panels->Items[0]->Text = DatasetTypeIDs.WebServiceName();
		   if (!DatasetTypeIDs.Execute())
			 return;
		   map<int,UnicodeString>::iterator itr;
		   // see if any of these DatasetTypes are valid for specimens
		   for (itr = DatasetTypeIDs.Items.begin(); itr != DatasetTypeIDs.Items.end(); itr++) {
			 if (TaxaGroupDatasetTypes.IsTaxaGroupInDatasetType(TaxaGroupID, itr->first)) {
			   DatasetTypeID = itr->first;
			   break;
			   }
			 }

		   if (DatasetTypeID != -1) {
			 NeotomaSampleIDForDatasetTypeIDFromGeochronAnalUnit DatasetSampleID(ipsJSONS1, TcpClient1);
			 DatasetSampleID.AddParam(L"GEOCHRONID", GeochronID);
			 DatasetSampleID.AddParam(L"DATASETTYPEID", DatasetTypeID);
			 ParentForm->StatusBar1->Panels->Items[0]->Text = DatasetSampleID.WebServiceName();
			 if (!DatasetSampleID.Execute())
			   return;
			 if (DatasetSampleID.Size() ==  1)
			   SampleID = DatasetSampleID.Items[0];
			 }
		   }
		 }

	   if (SampleID == -1 && DatasetTypeID != -1) {
		 // scenario 3b -- sample not found, but DatasetType exists
		 // get DatasetID if necessary
		 if (DatasetID == -1) {
		   NeotomaDatasetIDforDatasetTypeIDforGeochronAnalUnit DatasetTypeDatasetID(ipsJSONS1, TcpClient1);
		   DatasetTypeDatasetID.AddParam(L"GEOCHRONID", GeochronID);
		   DatasetTypeDatasetID.AddParam(L"DATASETTYPEID", DatasetTypeID);
		   ParentForm->StatusBar1->Panels->Items[0]->Text = DatasetTypeDatasetID.WebServiceName();
		   if (!DatasetTypeDatasetID.Execute())
			 return;
		   if (DatasetTypeDatasetID.Size() == 1)
			 DatasetID == DatasetTypeDatasetID.Items[0];
		   }
		 if (DatasetID != -1) {  // create SampleID
		   msg = L"Dataset type for dated specimen exists for the Geochonology collection unit, ";
		   msg += L"but no sample for for this dataset type exists for the Geochronology analysis unit.";
		   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   return;
		   }
		 }

	   if (SampleID == -1) {
		 msg = L"Dataset type for dated specimen does not exist for the Geochronology collection unit. ";
		 msg += L"This dataset must be created before dated specimen can be uploaded.";
		 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 return;
		 }

	   // check if taxon exists for sample, if not issue warning message
	   NeotomaSampleTaxonCount TaxonCount(ipsJSONS1, TcpClient1);
	   TaxonCount.AddParam(L"SAMPLEID", SampleID);
	   TaxonCount.AddParam(L"TAXONID", TaxonID);
	   ParentForm->StatusBar1->Panels->Items[0]->Text = TaxonCount.WebServiceName();
	   if (!TaxonCount.Execute())
		 return;
	   if (TaxonCount.Size() == 1) {    // should always be true
		 if (TaxonCount.Items[0] == 0) {
		   msg = L"Although sample for dataset type of dated specimen exists, ";
		   msg += L"dated taxon does not occur in this sample. Consider adding.";
		   MessageDlg(msg, mtWarning, TMsgDlgButtons() << mbOK, 0);
		   }
		 }

	   // get ElementTypeID
	   int ElementTypeID;
	   if (!GetElementTypeID(TaxonDated.Element, TaxonID, TaxonDated.Taxon, ElementTypeID))
		 return;

	   // get FractionID
	   int FractionID;
	   if (!GetFractionID(TaxonDated.Fraction, FractionID))
		 return;

	   vector<int> newids;
	   InsertData InsertSpecimenDate(L"InsertSpecimenDate", 7, ipsHTTPS1, ipsJSONS1, TcpClient1);
	   InsertSpecimenDate.Add(L"GEOCHRONID", GeochronID, -1);
	   InsertSpecimenDate.Add(L"SPECIMENID", SpecimenID, -1);
	   InsertSpecimenDate.Add(L"TAXONID", TaxonID, -1);
	   InsertSpecimenDate.Add(L"ELEMENTTYPEID", ElementTypeID, -1);
	   InsertSpecimenDate.Add(L"FRACTIONID", FractionID, -1);
	   InsertSpecimenDate.Add(L"SAMPLEID", SampleID, -1);
	   InsertSpecimenDate.Add(L"NOTES", TaxonDated.Notes);
	   ParentForm->StatusBar1->Panels->Items[0]->Text = L"InsertSpecimenDate";
	   InsertSpecimenDate.PostData();
	   if (InsertSpecimenDate.Post(newids, ErrorMsg)) {
		 if (newids.size() == 1) {
		   TaxonDated.NeotomaSpecimenDateID = newids[0];
		   msg = L"Specimen date uploaded to SpacimenDates table. ";
		   msg += L"SpecimenDateID = " + IntToStr(newids[0]);
		   MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
		   uploaded = true;
		   }
		 else {
		   ErrorMsg = L"Error inserting into SpecimenDates table!";
		   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   return;
		   }
		 }
	   else {
		 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 return;
		 }
	   }
   __finally {
	   ParentForm->StatusBar1->Panels->Items[0]->Text = L"";
	   Screen->Cursor = crDefault;
	   if (!uploaded) {
		 msg = L"Specimen date not uploaded to Neotoma.";
		 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 }
	   }
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::UpdateTaxonDated(TAXONDATED& TaxonDated)
{
   UnicodeString msg, ErrorMsg;
   bool updated = false;

   if (TaxonDated.Taxon.IsEmpty()) {
	 msg = L"Taxon name cannot be blank!";
	 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 return;
	 }

   if (!Login->IsLoggedIn) {
	 NeotomaLoginForm = new TNeotomaLoginForm(this);
	 NeotomaLoginForm->ShowModal();
	 delete NeotomaLoginForm;
	 }
   if (!Login->IsLoggedIn)
	 return;

   try {
	   int SpecimenID = -1;
	   int TaxonID;
	   UnicodeString TaxaGroupID;
	   int ElementTypeID;
	   int FractionID;
	   bool cal_age = false;
	   double aVal, aValOld, aValYoung;
	   Variant CalAge;
	   Variant CalAgeOlder;
	   Variant CalAgeYounger;
	   int CalCurveID = -1;
	   int CalProgID = -1;

	   Screen->Cursor = crHourGlass;

	   // get specimen date data currently in Neotoma
	   NeotomaSpecimenDateBySpecimenDateID SpecDate(ipsJSONS1, TcpClient1);
	   SpecDate.AddParam(L"SPECIMENDATEID", TaxonDated.NeotomaSpecimenDateID);
	   ParentForm->StatusBar1->Panels->Items[0]->Text = SpecDate.WebServiceName();
	   if (!SpecDate.Execute())
		 return;
	   if (SpecDate.Size() != 1) {
		 msg = L"Specimen date not found in Neotoma.";
		 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 }

	   // get calibrated specimen dates
	   NeotomaSpecimenDateCalBySpecimenDateID SpecDateCal(ipsJSONS1, TcpClient1);
	   SpecDateCal.AddParam(L"SPECIMENDATEID", TaxonDated.NeotomaSpecimenDateID);
	   ParentForm->StatusBar1->Panels->Items[0]->Text = SpecDateCal.WebServiceName();
	   if (!SpecDateCal.Execute())
		 return;

	   if (SameText(TaxonDated.Taxon, SpecDate.Items[0].TaxonName))
		 TaxonID = SpecDate.Items[0].TaxonID;
	   else if (!GetTaxonID(TaxonDated.Taxon, TaxonID, TaxaGroupID))
		 return;

	   if (!TaxonDated.Element.IsEmpty() && SameText(TaxonDated.Element, SpecDate.Items[0].ElementType))
		 ElementTypeID = SpecDate.Items[0].ElementTypeID;
	   else if (!GetElementTypeID(TaxonDated.Element, TaxonID, TaxonDated.Taxon, ElementTypeID))
		 return;

	   if (!TaxonDated.Fraction.IsEmpty() && SameText(TaxonDated.Fraction, SpecDate.Items[0].Fraction))
		 FractionID = SpecDate.Items[0].FractionID;
	   else if (!GetFractionID(TaxonDated.Fraction, FractionID))
		 return;

	   if (!TaxonDated.CalAgeMedian.IsEmpty()) {
		 // ShowMessage(VarToStr(TaxonDated.CalAgeMedian));
		 if (TryVariantToDouble(TaxonDated.CalAgeMedian, aVal))
		   CalAge = aVal;
		 else {
		   msg = L"Invalid value for calibrated age.";
		   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   return;
		   }
		 if (TaxonDated.CalAgeOlder.IsEmpty() || TaxonDated.CalAgeYounger.IsEmpty()) {
		   msg = L"Calibrated age must have older and younger bounds.";
		   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   return;
		   }
		 }

	   if (!TaxonDated.CalAgeOlder.IsEmpty() || !TaxonDated.CalAgeYounger.IsEmpty()) {
		 if (TaxonDated.CalAgeOlder.IsEmpty() || TaxonDated.CalAgeYounger.IsEmpty()) {
		   msg = L"Calibrated age must have both younger and older bounds.";
		   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   return;
		   }
		 if (TryVariantToDouble(TaxonDated.CalAgeOlder, aValOld))
		   CalAgeOlder = aValOld;
		 else {
		   msg = L"Invalid value for cal age older.";
		   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   return;
		   }
		 if (TryVariantToDouble(TaxonDated.CalAgeYounger, aValYoung))
		   CalAgeYounger = aValYoung;
		 else {
		   msg = L"Invalid value for cal age younger.";
		   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   return;
		   }
		 if (aValOld < aValYoung) {
		   msg = L"Older cal age must be older than younger cal age.";
           MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   return;
		   }
		 cal_age = true;
		 }

	   if (cal_age) {
		 // validate calibration curve
		 if (!TaxonDated.CalibCurve.IsEmpty()) {
		   if (SpecDateCal.Size() == 1 && SameText(TaxonDated.CalibCurve, SpecDateCal.Items[0].CalibrationCurve))
			 CalCurveID = SpecDateCal.Items[0].CalibrationCurveID;
		   else {
			 NeotomaCalibrationCurvesTable CalibCurves(ipsJSONS1, TcpClient1);
			 ParentForm->StatusBar1->Panels->Items[0]->Text = CalibCurves.WebServiceName();
			 if (!CalibCurves.Execute())
			   return;
			 for (unsigned int i=0; i<CalibCurves.Size(); i++) {
			   if (SameText(CalibCurves.Items[i].CalibrationCurve, TaxonDated.CalibCurve)) {
				CalCurveID = CalibCurves.Items[i].CalibrationCurveID;
				break;
				}
			   }
			 if (CalCurveID == -1) {
			   msg = L"Calibration curve is not in the Neotoma CalibrationCurves table.";
			   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			   return;
			   }
			 }
		   }
		 else {
		   msg = L"Calibration curve must be specified.";
		   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   return;
		   }

		 // validate calibration program
		 if (!TaxonDated.Calib.Program.IsEmpty() && !TaxonDated.Calib.Version.IsEmpty()) {
		   if (SpecDateCal.Size() == 1 && SameText(TaxonDated.Calib.Program, SpecDateCal.Items[0].CalibrationProgram) &&
			   SameText(TaxonDated.Calib.Version, SpecDateCal.Items[0].Version)) {
			 CalProgID = SpecDateCal.Items[0].CalibrationProgramID;
			 }
		   else {
			 NeotomaCalibrationProgramsTable CalibPrograms(ipsJSONS1, TcpClient1);
			 ParentForm->StatusBar1->Panels->Items[0]->Text = CalibPrograms.WebServiceName();
			 if (!CalibPrograms.Execute())
			   return;
			 for (unsigned int i=0; i<CalibPrograms.Size(); i++) {
			   if (SameText(CalibPrograms.Items[i].CalibrationProgram, TaxonDated.Calib.Program) &&
				   SameText(CalibPrograms.Items[i].Version, TaxonDated.Calib.Version)) {
				 CalProgID = CalibPrograms.Items[i].CalibrationProgramID;
				 break;
				}
			   }
			 if (CalProgID == -1) {
			   msg = L"Calibration program is not in the Neotoma CalibrationPrograms table.";
			   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbIgnore << mbAbort, 0);
			   return;
			   }
			 }
		   }
		 else {
		   msg = L"Calibration program must be specified.";
		   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbIgnore << mbAbort, 0);
		   return;
		   }
		 }

	   if (!TaxonDated.UserSpecID.IsEmpty()) {
		 SpecimenID = TaxonDated.Specimen->NeotomaSpecimenID;
		 if (SpecimenID != SpecDate.Items[0].SpecimenID) {
		   // ensure that new SpecimenID exists
		   NeotomaSpecimenByIDCount SpecExists(ipsJSONS1, TcpClient1);
		   SpecExists.AddParam(L"SPECIMENID", SpecimenID);
		   ParentForm->StatusBar1->Panels->Items[0]->Text = SpecExists.WebServiceName();
		   if (!SpecExists.Execute())
			 return;
		   if (SpecExists.Size() ==  1) {  // should always be true
			 if (SpecExists.Items[0] == 0) {
			   msg = L"SpecimenID " + IntToStr(SpecimenID) + L" does not exist in Neotoma.";
			   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			   return;
			   }
			 }
		   else
			 return;

		   // ensure that the taxon of the new SpecimenID matches the taxon of dated specimen
		   // if (SpecDate.Items[0].SpecimenID == -1) {  // the old SpecimenID was null
		   NeotomaSpecimenTaxonID SpecTaxon(ipsJSONS1, TcpClient1);
		   SpecTaxon.AddParam(L"SPECIMENID", SpecimenID);
		   ParentForm->StatusBar1->Panels->Items[0]->Text = SpecTaxon.WebServiceName();
		   if (!SpecTaxon.Execute())
			 return;
		   if (SpecTaxon.Size() == 1) {  // should always be true
			 if (SpecTaxon.Items[0] != TaxonID) {
			   msg = L"Taxon of SpecimenID " + IntToStr(SpecimenID) +
					 L" does not agree with dated taxon name.";
			   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			   return;
			   }
			 }
		   else
			 return;

		   // ensure that SampleID of new SpecimenID agrees with SampleID of dated specimen
		   NeotomaSpecimenSampleID SpecSample(ipsJSONS1, TcpClient1);
		   SpecSample.AddParam(L"SPECIMENID", SpecimenID);
		   ParentForm->StatusBar1->Panels->Items[0]->Text = SpecSample.WebServiceName();
		   if (!SpecSample.Execute())
			 return;
		   if (SpecSample.Size() == 1) {  // should always be true
			 if (SpecSample.Items[0] != SpecDate.Items[0].SampleID) {
			   msg = L"SampleID " + IntToStr(SpecSample.Items[0]) + L" of SpecimenID " +
					 IntToStr(SpecimenID) + L" does not match SampleID " +
					 IntToStr(SpecDate.Items[0].SampleID) + L" of dated specimen.";
			   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			   return;
			   }
			 }
		   else
			 return;
		   }
		 }
	   else if (SpecDate.Items[0].SpecimenID != -1) {  // UserSpecID is empty.
		 msg = L"SpecimenID was previously defined (SpecimenID = " +
			   IntToStr(SpecDate.Items[0].SpecimenID) +
			   L"). Do you want to unlink the dated specimen from SpecimenID " +
			   IntToStr(SpecDate.Items[0].SpecimenID) + L"?";
		 if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrNo)
		   return;
		 }

	   UpdateData UpdateSpecDate(L"UpdateSpecimenDate", 13, ipsHTTPS1, ipsJSONS1, TcpClient1);
	   UpdateSpecDate.Add(L"SPECIMENDATEID", TaxonDated.NeotomaSpecimenDateID);
	   UpdateSpecDate.Add(L"TAXONID", TaxonID);

	   Variant VSpecimenID = (SpecimenID == -1) ? Unassigned() : SpecimenID;
	   Variant VElementTypeID = (ElementTypeID == -1) ? Unassigned() : ElementTypeID;
	   Variant VFractionID = (FractionID == -1) ? Unassigned() : FractionID;
	   Variant VSpecimenDateCalID;
	   Variant VCalAge;
	   Variant VCalAgeOlder;
	   Variant VCalAgeYounger;
	   Variant VCalCurveID;
	   Variant VCalProgID;
	   UnicodeString VDateCalibrated;
	   if (cal_age) {
		 if (SpecDateCal.Size() == 1)
		   VSpecimenDateCalID = SpecDateCal.Items[0].SpecimenDateCalID;
		 VCalAge = CalAge;
		 VCalAgeOlder = CalAgeOlder;
		 VCalAgeYounger = CalAgeYounger;
		 if (CalCurveID != -1)
		   VCalCurveID = CalCurveID;
		 if (CalProgID != -1)
		   VCalProgID = CalProgID;
		 VDateCalibrated = DateStr(UTCDateTime());
		 }

	   /*
	   if (SpecimenID != -1)
		 UpdateSpecDate.Add(L"SPECIMENID", SpecimenID);
	   if (ElementTypeID != -1)
		 UpdateSpecDate.Add(L"ELEMENTTYPEID", ElementTypeID);
	   if (FractionID != -1)
		 UpdateSpecDate.Add(L"FRACTIONID", FractionID);
	   if (!TaxonDated.Notes.IsEmpty())
		 UpdateSpecDate.Add(L"NOTES", TaxonDated.Notes);
	   if (cal_age) {
		 if (SpecDateCal.Size() == 1)
		   UpdateSpecDate.Add(L"SPECIMENDATECALID", SpecDateCal.Items[0].SpecimenDateCalID);
		 if (!CalAge.IsEmpty())
		   UpdateSpecDate.AddDouble(L"CALAGE", CalAge);
		 if (!CalAgeOlder.IsEmpty())
		   UpdateSpecDate.AddDouble(L"CALAGEOLDER", CalAgeOlder);
		 if (!CalAgeYounger.IsEmpty())
		   UpdateSpecDate.AddDouble(L"CALAGEYOUNGER", CalAgeYounger);
		 if (CalCurveID != -1)
		   UpdateSpecDate.Add(L"CALCURVEID", CalCurveID);
		 if (CalProgID != -1)
		   UpdateSpecDate.Add(L"CALPROGID", CalProgID);
		 UpdateSpecDate.Add(L"DATECALIBRATED", DateStr(UTCDateTime()));
		 }
	   */

	   UpdateSpecDate.AddInt(L"SPECIMENID", VSpecimenID);
	   UpdateSpecDate.AddInt(L"ELEMENTTYPEID", VElementTypeID);
	   UpdateSpecDate.AddInt(L"FRACTIONID", VFractionID);
	   UpdateSpecDate.Add(L"NOTES", TaxonDated.Notes);
	   UpdateSpecDate.AddInt(L"SPECIMENDATECALID", VSpecimenDateCalID);
	   UpdateSpecDate.AddDouble(L"CALAGE", VCalAge);
	   UpdateSpecDate.AddDouble(L"CALAGEOLDER", VCalAgeOlder);
	   UpdateSpecDate.AddDouble(L"CALAGEYOUNGER", VCalAgeYounger);
	   UpdateSpecDate.AddInt(L"CALCURVEID", VCalCurveID);
	   UpdateSpecDate.AddInt(L"CALPROGID", VCalProgID);
	   UpdateSpecDate.Add(L"DATECALIBRATED", VDateCalibrated);

	   // vector<int> newids;
	   ParentForm->StatusBar1->Panels->Items[0]->Text = L"UpdateSpecimenDate";
	   if (UpdateSpecDate.Post(ErrorMsg)) {
		 msg = L"Specimen date updated.";
		 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
		 updated = true;
		 }
	   else {
		 if (!ErrorMsg.IsEmpty())
		   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 return;
		 }
	   }
   __finally {
	   ParentForm->StatusBar1->Panels->Items[0]->Text = L"";
	   Screen->Cursor = crDefault;
	   if (!updated) {
		 msg = L"Specimen date not updated.";
		 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 }
	   }
}
//---------------------------------------------------------------------------

bool TTilSpreadSheetForm::GetTaxonID(UnicodeString TaxonName, int& TaxonID, UnicodeString& TaxaGroupID)
{
   TaxonByName NeotomaTaxon(ipsJSONS1, TcpClient1);
   NeotomaTaxon.AddParam(L"TAXONNAME", TaxonName);
   ParentForm->StatusBar1->Panels->Items[0]->Text = NeotomaTaxon.WebServiceName();
   if (NeotomaTaxon.Execute()) {
	 if (NeotomaTaxon.Size() == 1) {
	   TaxonID = NeotomaTaxon.Items[0].TaxonID;
	   TaxaGroupID = NeotomaTaxon.Items[0].TaxaGroupID;
	   }
	 else {
	   UnicodeString msg = L"Taxon «" + TaxonName + L"» is not in Neotoma!";
	   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return false;
	   }
	 }
   else
	 return false;
   return true;
}
//---------------------------------------------------------------------------

bool TTilSpreadSheetForm::GetElementTypeID(UnicodeString ElementType, int TaxonID,
	UnicodeString TaxonName, int& ElementTypeID)
{
   ElementTypeID = -1;
   if (!ElementType.IsEmpty()) {
	 NeotomaElementTypesForTaxonTaxaGroup ElementTypes(ipsJSONS1, TcpClient1);
	 ElementTypes.AddParam(L"TAXONID", TaxonID);
	 ParentForm->StatusBar1->Panels->Items[0]->Text = ElementTypes.WebServiceName();
	 if (!ElementTypes.Execute())
	   return false;
	 map<int,UnicodeString>::iterator itr;
	 for (itr = ElementTypes.Items.begin(); itr != ElementTypes.Items.end(); itr++) {
	   if (SameText(itr->second,ElementType)) {
		 ElementTypeID = itr->first;
		 break;
		 }
	   }
	 if (ElementTypeID == -1) {
	   UnicodeString msg = L"Element «" + ElementType + L"» is not valid for Taxon «" +
			               TaxonName + L"».";
	   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return false;
	   }
	 }
   return true;
}
//---------------------------------------------------------------------------

bool TTilSpreadSheetForm::GetFractionID(UnicodeString Fraction, int& FractionID)
{
   FractionID = -1;
   if (!Fraction.IsEmpty()) {
	 NeotomaFractionDatedByName NtmFraction(ipsJSONS1, TcpClient1);
	 NtmFraction.AddParam(L"FRACTION", Fraction);
	 ParentForm->StatusBar1->Panels->Items[0]->Text = NtmFraction.WebServiceName();
	 if (!NtmFraction.Execute())
	   return false;
	 if (NtmFraction.Size() == 1)
	   FractionID = NtmFraction.Items.begin()->first;
	 else {
	   UnicodeString msg = L"Fraction «" + Fraction + L"» is not int the Neotoma FractionDated table.";
	   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return false;
	   }
	 }
   return true;
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::UploadChronControl(int ChronologyID, CHRON* ChronControl)
{

   UnicodeString msg, ErrorMsg;

   if (!Login->IsLoggedIn) {
	 NeotomaLoginForm = new TNeotomaLoginForm(this);
	 NeotomaLoginForm->ShowModal();
	 delete NeotomaLoginForm;
	 }
   if (!Login->IsLoggedIn)
	 return;

}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::InsertChronControl(CHRON* ChronControl, AGEMODEL* AgeModel)
{
   UnicodeString msg;

   // ShowMessage(L"ChronControl->Depth = " + FloatToStr((double)ChronControl->Depth));
   if (!Login->IsLoggedIn) {
	 NeotomaLoginForm = new TNeotomaLoginForm(this);
	 NeotomaLoginForm->ShowModal();
	 delete NeotomaLoginForm;
	 }
   if (!Login->IsLoggedIn)
	 return;

   // validate chron control
   Screen->Cursor = crHourGlass;
   int ChronNo = AgeModel->ChronNumber;

   try {
	 if (ChronControl->Depth.IsEmpty() && ChronControl->AnalUnit.IsEmpty()) {
	   msg = L"Chron control is not assigned depth or analysis unit.";
	   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   Screen->Cursor = crDefault;
	   return;
	   }

	 NEOTOMACHRONCONTROL NeotomaChronControl;
	   // assign temporary ChronControlID
	 NeotomaChronControl.ChronControlID = -1001;

	   // if ChronControlTypeID not already in list...
	   // if (NeotomaChronControl.ChronControlTypeID == -1) {   // B
		 bool found = false;
		 NeotomaChronControlTypeByName ChronControlType(ipsJSONS1, TcpClient1);
		 ChronControlType.AddParam(L"CHRONCONTROLTYPE", ChronControl->ControlType);
		 ParentForm->StatusBar1->Panels->Items[0]->Text = ChronControlType.WebServiceName();
		 if (ChronControlType.Execute()) {
		   if (ChronControlType.Size() == 1) {
			 found = true;
			 NeotomaChronControl.ChronControlTypeID = ChronControlType.Items[0].ChronControlTypeID;
			 //ChronControlTypes.insert(pair<int,UnicodeString>(NeotomaChronControl.ChronControlTypeID,ChronControl->ControlType));

			 //if (IsGeochronControlType(NeotomaChronControl.ChronControlTypeID))
			 //  GeochronControlTypeIDs.insert(NeotomaChronControl.ChronControlTypeID);

			 /*
			 if (!ValidateChronControlAnalUnit(ChronNo, NeotomaChronControl, ChronControl, IDByDepth)) {
			   Screen->Cursor = crDefault;
			   return false;
			   }
			 */

			 if (!ChronControl->Depth.IsEmpty()) {      // ages identified by depth, true if all chron controls have a depth
			   NeotomaChronControl.Depth = ChronControl->Depth;
			   if (!ChronControl->Thickness.IsEmpty()) {
				 NeotomaChronControl.Thickness = ChronControl->Thickness;
				 // check if analysis unit with same depth and thickness exists
				 // need to query Neotoma for this  GetAnalysisUnit
				 int AnalysisUnitID;
				 GEOCHRON Date;
				 Date.Depth = ChronControl->Depth;
				 Date.Thickness = ChronControl->Thickness;
				 if (GetDateAnalysisUnitID(Date, AnalysisUnitID))
				   NeotomaChronControl.AnalysisUnitID = AnalysisUnitID;
				 else
				   return;
				 }
			   }
			 else if (!ChronControl->AnalUnit.IsEmpty()) {   // Analysis Unit
               int AnalysisUnitID;
			   GEOCHRON Date;
			   Date.AnalUnit = ChronControl->AnalUnit;
               if (GetDateAnalysisUnitID(Date, AnalysisUnitID))
				 NeotomaChronControl.AnalysisUnitID = AnalysisUnitID;
			   else
				 return;
			   //ShowMessage(L"NeotomaChronControl.AnalysisUnitID = " + IntToStr(NeotomaChronControl.AnalysisUnitID));
			   }
			 else {
			   msg = L"Analysis unit not entered for Chron " + IntToStr(ChronNo) + L" .";
			   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			   return;
			   }
			 }
		   }
		 else {
		   Screen->Cursor = crDefault;
		   return;
		   }


		 // ShowMessage(L"CollPtr->NeotomaCollUnitID = " + IntToStr(CollPtr->NeotomaCollUnitID));

		 int EventID = -1;
		 if (!found) {  // check if ChronControlType is an event     // C
		   NeotomaEventChronControlTypeID Event(ipsJSONS1, TcpClient1);
		   Event.AddParam(L"EVENTNAME", ChronControl->ControlType);
		   ParentForm->StatusBar1->Panels->Items[0]->Text = Event.WebServiceName();
		   if (Event.Execute()) {
			 if (Event.Size() == 1) {      // EventID, ChronControlTypeID
			   EventID = Event.Items[0].first;
			   found = true;
			   NeotomaChronControl.ChronControlTypeID = Event.Items[0].second;

			   //ShowMessage(L"EventID = " + IntToStr(EventID));
			   //ShowMessage(L"NeotomaChronControl.ChronControlTypeID = " + IntToStr(NeotomaChronControl.ChronControlTypeID));

			   //ChronControlTypes.insert(pair<int,UnicodeString>(NeotomaChronControl.ChronControlTypeID,ChronControl.ControlType));
			   //if (!ValidateChronControlAnalUnit(ChronNo, NeotomaChronControl, ChronControl, IDByDepth)) {
			   //	 Screen->Cursor = crDefault;
			   //	 return false;
			   //	 }

			   if (NeotomaChronControl.ChronControlTypeID == 3) {  // ChronControl is a tephra
				 int TephraAnalUnitID = NeotomaChronControl.AnalysisUnitID;
				 /* this not needed
				 if (TephraAnalUnitID == -1) {
				   // see if tephra analysis unit already created for another chronology
				   if (NeotomaTephras.size() > 0) {
					 for (unsigned int k=0; k<NeotomaTephras.size(); k++) {
					   if (NeotomaTephras[k].EventID == EventID) {
						 TephraAnalUnitID = NeotomaTephras[k].AnalysisUnitID;
						 break;
						 }
					   }
					 }
				   }
				 */

				 if (TephraAnalUnitID == -1) {
				   // create AnalysisUnit for tephra
				   // TephraAnalUnitID = NextTempAnalUnitID();
				   NEOTOMAANALUNIT AnalUnit;
				   AnalUnit.Depth = ChronControl->Depth;
				   AnalUnit.Thickness = ChronControl->Thickness;
				   AnalUnit.AnalysisUnitName = ChronControl->ControlType;
				   AnalUnit.FaciesID = 46;

				   if (UploadAnalysisUnit(AnalUnit)) {
					 NeotomaChronControl.AnalysisUnitID = AnalUnit.AnalysisUnitID;
					 TephraAnalUnitID = AnalUnit.AnalysisUnitID;
					 }
				   else
					 return;

				   // NeotomaAnalysisUnits.push_back(AnalUnit);
				   msg = L"Analysis unit created for " + AnalUnit.AnalysisUnitName;
				   if (!SameText(AnalUnit.AnalysisUnitName, L"tephra"))
					 msg += L" tephra";
				   // OutputLine(msg);
				   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
				   }

				 // check if AnalysisUnitID has been assigned to tephra ChronControl
				 // if (NeotomaChronControl.AnalysisUnitID == -1)
				 //  NeotomaChronControl.AnalysisUnitID = TephraAnalUnitID;

				 // vector<NEOTOMATEPHRA> NeotomaTephras;
				 /* don't need this
				 NEOTOMATEPHRA Tephra;
				 Tephra.EventID = EventID;
				 Tephra.AnalysisUnitID = TephraAnalUnitID;  // temp value, may need to create!
				 Tephra.Notes = NeotomaChronControl.Notes;
				 NeotomaTephras.push_back(Tephra);
				 */

				 // vector<NEOTOMAEVENTCHRONOLOGY> NetomaEventChronology;
				 /*  don't need this
				 NEOTOMAEVENTCHRONOLOGY EventChron;
				 EventChron.AnalysisUnitID = TephraAnalUnitID;  // temp value, may need to create!
				 EventChron.EventID = EventID;
				 EventChron.ChronControlID  = NeotomaChronControl.ChronControlID;  // temp value
				 EventChron.Notes = NeotomaChronControl.Notes;
				 NetomaEventChronology.push_back(EventChron);
				 */

				 // create set of ChronNumbers for tephra map
				 /* don't need this
				 vector<pair<int,CHRON> > ChronControls;
				 ChronControls.push_back(pair<int,CHRON>(ChronNo,ChronControl));
				 ChronTephras[ChronControl.ControlType] = ChronControls;
				 */
				 }

			   // don't need this any longer
			   //else if (IsGeochronControlType(NeotomaChronControl.ChronControlTypeID))
			   //	 GeochronControlTypeIDs.insert(NeotomaChronControl.ChronControlTypeID);
			   }
			 }
		   else {
			 Screen->Cursor = crDefault;
			 return;
			 }
		   }     // C

		 // multimap<int,UnicodeString> ChronControlTypes;   // ChronControlTypeID, ControlType
		 // ControlType = e.g. Geologic time scale, ChronControlTypeID = 60
		 int RelativeAgeID = -1;
		 if (!found) {  // check if ChronControlType is a relative age    // D
		   NeotomaRelativeAgeByName RelativeAge(ipsJSONS1, TcpClient1);
		   RelativeAge.AddParam(L"RELATIVEAGE", ChronControl->ControlType);
		   ParentForm->StatusBar1->Panels->Items[0]->Text = RelativeAge.WebServiceName();
		   if (RelativeAge.Execute()) {  // E
			 if (RelativeAge.Size() == 1) { // relative age was found in the RelativeAges table   // F
			   RelativeAgeID = RelativeAge.Items[0].RelativeAgeID;

			   //if (!ValidateChronControlAnalUnit(ChronNo, NeotomaChronControl, ChronControl, IDByDepth)) {
			   //	 Screen->Cursor = crDefault;
			   //	 return false;
			   //	 }
			   if (NeotomaChronControl.AnalysisUnitID == -1) {
				 msg = L"Relative age «" + ChronControl->ControlType + L" is not assigned to an analysis unit.";
				 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
				 return;
				 }

			   msg = L"Relative age «" + ChronControl->ControlType +
					 L"» found in RelativeAges table, RelativeAgeID = " +
					 IntToStr(RelativeAgeID) + L".";
			   MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);

			   // first check if ChronControlType is in local ChronControlTypes list
			   /*
			   if (ChronControlTypes.size() > 0) {
				 multimap<int,UnicodeString>::iterator itr;
				 for (itr = ChronControlTypes.begin(); itr != ChronControlTypes.end(); itr++) {
				   if (SameText(ChronControl.ControlType, itr->second)) {
					 NeotomaChronControl.ChronControlTypeID = itr->first;
					 break;
					 }
				   }
				 }
			   */

			   // get the ChronControlTypeID for the RelativeAge, e.g. Geologic Time Scale
               // need process this stuff
			   /*
			   if (NeotomaChronControl.ChronControlTypeID == -1) {
				 NeotomaRelativeAgeChronControlType RelAgeChronControlType(ipsJSONS1, TcpClient1);
				 RelAgeChronControlType.AddParam(L"RELATIVEAGE", ChronControl.ControlType);
				 StatusBar1->SimpleText = RelAgeChronControlType.WebServiceName();
				 if (RelAgeChronControlType.Execute()) {
				   if (RelAgeChronControlType.Size() == 1) {
					 found = true;
					 NeotomaChronControl.ChronControlTypeID = RelAgeChronControlType.Items[0].first;
					 ChronControlTypes.insert(pair<int,UnicodeString>(NeotomaChronControl.ChronControlTypeID,ChronControl.ControlType));
					 msg = L"Relative age «" + ChronControl.ControlType + L"» is assigned to ChronControlType «" +
						   RelAgeChronControlType.Items[0].second + L"».";
					 OutputLine(msg);

					 // Insert NeotomaChronControl.AnalysisUnitID, RelativeAgeID, ChronControlID, and NeotomaChronControl.Notes into RelativeChronology table
					 NEOTOMARELAGE RelAge;
					 RelAge.RelativeAgeID = RelativeAgeID;
					 RelAge.AnalysisUnitID = NeotomaChronControl.AnalysisUnitID;   // = -1, will need to create!
					 // ShowMessage(L"XXX RelAge.AnalysisUnitID = " + IntToStr(RelAge.AnalysisUnitID));
					 RelAge.ChronControlID  = NeotomaChronControl.ChronControlID;  // = e.g. -1001, temp value
					 RelAge.Notes = NeotomaChronControl.Notes;
					 NeotomaRelAges.push_back(RelAge);
					 }
				   else {
					 msg = L"Relative age «" + ChronControl.ControlType + L"» is not assigned to a ChronControlType.";
					 OutputError(L"ERROR: " + msg);
					 if (MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbIgnore << mbAbort, 0) == mrAbort) {
					   Screen->Cursor = crDefault;
					   return false;
					   }
					 else
					   continue;
					 }
				   }
				 else {
				   Screen->Cursor = crDefault;
				   return false;
				   }
				 }
				 */
			   }  // F
			 else {
			   msg = L"Error: Relative age «" + ChronControl->ControlType +
					 L"» not found in RelativeAges table";
			   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			   }
			 }   // E
		   }   // D

		 if (!found) {  // CronControlType not found
		   msg = L"ChronControl type «" + ChronControl->ControlType + L"» is not in the Neotoma ChronControlTypes table.";
		   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   return;
		   }

		 // }   // B

	   // AgeControlType
	   if (SameText(ChronControl->AgeUnits, L"Radiocarbon"))
		 NeotomaChronControl.AgeTypeID = 4;
	   else if (SameText(ChronControl->AgeUnits, L"Calendar"))
		 NeotomaChronControl.AgeTypeID = 2;
	   else {
		 msg = L"WARNING: No Age Units entered for ChronControl in Chron " + IntToStr(ChronNo) + L".";
		 MessageDlg(msg, mtWarning, TMsgDlgButtons() << mbOK, 0);
		 }

	   // age
	   if (!ChronControl->AgeValue.IsEmpty())
		 NeotomaChronControl.Age = ChronControl->AgeValue;

	   if (!ChronControl->AgeLimitOlder.IsEmpty())
		 NeotomaChronControl.AgeLimitOlder = ChronControl->AgeLimitOlder;

	   if (!ChronControl->AgeLimitYounger.IsEmpty())
		 NeotomaChronControl.AgeLimitYounger = ChronControl->AgeLimitYounger;

	   bool age_error = false;
	   if (NeotomaChronControl.AgeLimitOlder.IsEmpty() && !ChronControl->AgeLimitYounger.IsEmpty()) {
		 age_error = true;
		 msg = L"AgeLimitOlder not set.";
		 }
	   else if (!NeotomaChronControl.AgeLimitOlder.IsEmpty() && ChronControl->AgeLimitYounger.IsEmpty()) {
		 age_error = true;
		 msg = L"AgeLimitYounger not set.";
		 }
	   else if (NeotomaChronControl.Age.IsEmpty() && NeotomaChronControl.AgeLimitOlder.IsEmpty() &&
				ChronControl->AgeLimitYounger.IsEmpty()) {
		 age_error = true;
		 msg = L"Neither age nor age limits set.";
		 }

	   // if AgeLimitOlder and AgeLimitYounger set, check that AgeLimitOlder >= AgeLimitYounger
	   if (!age_error) {
		 if (!NeotomaChronControl.AgeLimitOlder.IsEmpty() && !NeotomaChronControl.AgeLimitYounger.IsEmpty()) {
		   double AgeLimitOlder = NeotomaChronControl.AgeLimitOlder;
		   double AgeLimitYounger = NeotomaChronControl.AgeLimitYounger;

		   // get AgeTypeID
		   int AgeTypeID;
           NeotomaAgeTypesTable AgeTypesTable(ipsJSONS1, TcpClient1);
		   ParentForm->StatusBar1->Panels->Items[0]->Text = AgeTypesTable.WebServiceName();
		   if (!AgeTypesTable.Execute())
			 return;

		   for (unsigned int j=0; j<AgeTypesTable.Size(); j++) {
			 if (SameText(AgeModel->AgeUnits, AgeTypesTable.Items[j].AgeType)) {
			   AgeTypeID = AgeTypesTable.Items[j].AgeTypeID;
			   break;
			   }
			 }

		   if ((AgeTypeID == 1 && AgeLimitOlder > AgeLimitYounger) ||    // AD/BC
			   (AgeTypeID != 1 && AgeLimitOlder < AgeLimitYounger)) {
			 msg = L"Older and younger age limits are reversed.";
			 age_error = true;
			 }
		   }
		 }

	   if (age_error) {
		 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 return;
		 }

	   // notes
	   NeotomaChronControl.Notes = ChronControl->Notes;

	   // calibration curve
	   if (!ChronControl->CalibCurve.IsEmpty()) {
		 NeotomaCalibrationCurvesTable CalibCurves(ipsJSONS1, TcpClient1);
		 ParentForm->StatusBar1->Panels->Items[0]->Text = CalibCurves.WebServiceName();
		 if (!CalibCurves.Execute())
		   return;
		 for (unsigned int k=0; k<CalibCurves.Size(); k++) {
		   if (SameText(ChronControl->CalibCurve, CalibCurves.Items[k].CalibrationCurve)) {
			 NeotomaChronControl.CalibrationCurveID = CalibCurves.Items[k].CalibrationCurveID;
			 break;
			 }
		   }
		 if (NeotomaChronControl.CalibrationCurveID == -1) {
		   msg = L"Calibration curve «" + ChronControl->CalibCurve +
				 L"» is not in the Neotoma CalibrationCurves table.";
		   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   return;
		   }
		 }

	   // calibration programs
	   if (!ChronControl->Calib.Program.IsEmpty()) {
		 NeotomaCalibrationProgramsTable CalibPrograms(ipsJSONS1, TcpClient1);
		 ParentForm->StatusBar1->Panels->Items[0]->Text = CalibPrograms.WebServiceName();
		 if (!CalibPrograms.Execute())
		   return;
		 for (unsigned int k=0; k<CalibPrograms.Size(); k++) {
		   if (SameText(ChronControl->Calib.Program, CalibPrograms.Items[k].CalibrationProgram) &&
			   SameText(ChronControl->Calib.Version, CalibPrograms.Items[k].Version)) {
			 NeotomaChronControl.CalibrationProgramID = CalibPrograms.Items[k].CalibrationProgramID;
			 break;
			 }
		   }
		 if (NeotomaChronControl.CalibrationProgramID == -1) {
		   msg = L"Calibration program «" + ChronControl->Calib.Program;
		   if (!ChronControl->Calib.Version.IsEmpty())
			 msg += (L" " + ChronControl->Calib.Version);
		   msg += L" is not in the Neotoma CalibrationPrograms table.";
		   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   return;
		   }
		 }

	   // get GeoChronIDs
	   if (ChronControl->GeochronIDs.size() > 0) {
		 for (unsigned int k=0; k<ChronControl->GeochronIDs.size(); k++) {
		   int ID = ChronControl->GeochronIDs[k];
		   bool found = false;
		   for (int j=0; j<GeochronList->Count(); j++) {
			 if (ID == GeochronList->Dates[j].ID) {
			   found = true;
			   NeotomaChronControl.GeoChronIDs.push_back(GeochronList->Dates[j].NeotomaGeochronID);
			   break;
			   }
			 }
		   if (!found) {
			 msg = L"Linked date not in Geochronology tabsheet";
             MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		     return;
			 }
		   }
		 }
	   //else if (GeochronControlTypeIDs.count(NeotomaChronControl.ChronControlTypeID) > 0) {
	   //	 msg = L"WARNING: Geochronology links not set.";
	   // OutputWarning(msg);
	   //	 }
	   //NeotomaChrons[i].ChronControls.push_back(NeotomaChronControl);

	   // this added to account for relative ages for newly added chronologies
	   //if (NeotomaAnalUnitIDs.count(NeotomaChronControl.AnalysisUnitID) == 0)
	   //	 NeotomaAnalUnitIDs[NeotomaChronControl.AnalysisUnitID] = NeotomaChronControl.AnalysisUnitID;

	   // }  // A
	 // }

	   ShowMessage(L"Everything is hunky dory");


	   UnicodeString ErrorMsg;
	   vector<int> newids;
	   //vector<NEOTOMACALIB> CalibDates;
	   vector<pair<int,int> > GeochronControls;
	   InsertData InsertControl(L"InsertChronControl", 10, ipsHTTPS1, ipsJSONS1, TcpClient1);
		 // for (unsigned int j=0; j<NeotomaChrons[i].ChronControls.size(); j++) {
		   //NEOTOMACHRONCONTROL& ChronControl = NeotomaChrons[i].ChronControls[j];
		   // NeotomaChronControl
		   InsertControl.Add(L"CHRONOLOGYID", AgeModel->NeotomaChronologyID, -1);
		   InsertControl.Add(L"CHRONCONTROLTYPEID", NeotomaChronControl.ChronControlTypeID, -1);
		   InsertControl.Add(L"ANALYSISUNITID", NeotomaChronControl.AnalysisUnitID, -1);
		   InsertControl.AddDouble(L"DEPTH", NeotomaChronControl.Depth);
		   InsertControl.AddDouble(L"THICKNESS", NeotomaChronControl.Thickness);
		   InsertControl.AddInt(L"AGETYPEID", NeotomaChronControl.AgeTypeID);
		   InsertControl.AddDouble(L"AGE", NeotomaChronControl.Age);
		   InsertControl.AddDouble(L"AGELIMITYOUNGER", NeotomaChronControl.AgeLimitYounger);
		   InsertControl.AddDouble(L"AGELIMITOLDER", NeotomaChronControl.AgeLimitOlder);
		   InsertControl.Add(L"NOTES", NeotomaChronControl.Notes);
		   //if (NeotomaChronControl.CalibrationCurveID > -1 && NeotomaChronControl.CalibrationProgramID > -1) {
		   //	 NEOTOMACALIB CalibDate(NeotomaChronControl.ChronControlID,
		   //	   NeotomaChronControl.CalibrationCurveID,
		   //	   NeotomaChronControl.CalibrationProgramID);
		   //	   CalibDates.push_back(CalibDate);
		   //	 }

		   if (NeotomaChronControl.GeoChronIDs.size() > 0) {
			 for (unsigned int k=0; k<NeotomaChronControl.GeoChronIDs.size(); k++) {
			   int ChronControlID = NeotomaChronControl.ChronControlID;
			   int GeochronID = NeotomaChronControl.GeoChronIDs[k];          // TempGeochronID, NeotomaGeochronID
			   GeochronControls.push_back(pair<int,int>(ChronControlID,GeochronID));
			   }
			 }
		 //  }

		 ParentForm->StatusBar1->Panels->Items[0]->Text = L"InsertChronControl";
		 InsertControl.PostData();

		 newids.clear();
		 if (InsertControl.Post(newids, ErrorMsg)) {
		   if (newids.size() == 1) {
			 //for (unsigned int j=0; j<newids.size(); j++)
			 //  NeotomaChronControlIDs[NeotomaChrons[i].ChronControls[j].ChronControlID] = newids[j];
			 NeotomaChronControl.ChronControlID = newids[0];
			 msg = L"Chronology control uploaded to Neotoma: ChronControlID = " +
				   IntToStr(NeotomaChronControl.ChronControlID) + L".";
			 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
			 }
		   else {
			 ErrorMsg = L"Error inserting into ChronControls table!";
			 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			 return;
			 }
		   }
		 else {
		   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   return;
		   }

		 // upload calibration data
		 if (NeotomaChronControl.CalibrationCurveID > -1 && NeotomaChronControl.CalibrationProgramID > -1) {
		   InsertData InsertCalib(L"InsertChronControlCal14C", 3, ipsHTTPS1, ipsJSONS1, TcpClient1);
		   // for (unsigned int j=0; j<CalibDates.size(); j++) {
			 InsertCalib.Add(L"CHRONCONTROLID", NeotomaChronControl.ChronControlID, -1);
			 InsertCalib.Add(L"CALIBRATIONCURVEID", NeotomaChronControl.CalibrationCurveID, -1);
			 InsertCalib.Add(L"CALIBRATIONPROGRAMID", NeotomaChronControl.CalibrationProgramID, -1);
		   //	 }
		   ParentForm->StatusBar1->Panels->Items[0]->Text = L"InsertChronControlCal14C";
		   InsertCalib.PostData();
		   if (InsertCalib.Post(ErrorMsg)) {
			 msg = L"Calibrated radiocarbon date uploaded to ChronControlCal14C table.";
			 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
			 }
		   else {
			 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			 return;
			 }
		   }
		 //

	 if (EventID != -1 && NeotomaChronControl.AnalysisUnitID != -1) {
	 newids.clear();
	 InsertData InsertEventChron(L"InsertEventChronology", 4, ipsHTTPS1, ipsJSONS1, TcpClient1);
	 //for (unsigned int i=0; i<NetomaEventChronology.size(); i++) {
	   InsertEventChron.Add(L"ANALYSISUNITID", NeotomaChronControl.AnalysisUnitID, -1);
	   InsertEventChron.Add(L"EVENTID", EventID, -1);
	   // int ChronControlID = NeotomaChronControlIDs[NetomaEventChronology[i].ChronControlID];
	   InsertEventChron.Add(L"CHRONCONTROLID", NeotomaChronControl.ChronControlID, -1);
	   InsertEventChron.Add(L"NOTES", NeotomaChronControl.Notes);
	 //  }
	 ParentForm->StatusBar1->Panels->Items[0]->Text = L"InsertEventChronology";
	 InsertEventChron.PostData();
	 if (InsertEventChron.Post(newids, ErrorMsg)) {
	   if (newids.size() == 1) {
		 msg = L"Chronology event uploaded to EventChronology table: EventChronologyID = " +
			   IntToStr(newids[0]) + L".";
		 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
		 }
	   else {
		 ErrorMsg = L"Error inserting into EventChronology table!";
		 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 return;
		 }
	   }
	 else {
	   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return;
	   }
	 }

	 if (RelativeAgeID != -1 && NeotomaChronControl.AnalysisUnitID != -1) {   // relative ages exist
	 newids.clear();
	 InsertData InsertRelativeAge(L"InsertRelativeChronology", 4, ipsHTTPS1, ipsJSONS1, TcpClient1);
	 //for (unsigned int i=0; i<NeotomaRelAges.size(); i++) {
	   InsertRelativeAge.Add(L"ANALYSISUNITID", NeotomaChronControl.AnalysisUnitID, -1);
	   InsertRelativeAge.Add(L"RELATIVEAGEID", RelativeAgeID, -1);
	   InsertRelativeAge.Add(L"CHRONCONTROLID", NeotomaChronControl.ChronControlID, -1);
	   InsertRelativeAge.Add(L"NOTES", NeotomaChronControl.Notes);
	 //  }
	 ParentForm->StatusBar1->Panels->Items[0]->Text = L"InsertRelativeChronology";
	 InsertRelativeAge.PostData();
	 if (InsertRelativeAge.Post(newids, ErrorMsg)) {
	   if (newids.size() == 1) {
		 msg = L"Relative age uploaded to RelativeChronology table: RelativeChronID = " +
			   IntToStr(newids[0]) + L".";
		 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
		 }
	   else {
		 ErrorMsg = L"Error inserting into RelativeChronology table!";
		 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 return;
		 }
	   }
	 else {
	   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return;
	   }
	 }

	   }
   __finally {
	   ParentForm->StatusBar1->Panels->Items[0]->Text = L"";
	   Screen->Cursor = crDefault;
	   }
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::UpdateChronControl(CHRON* ChronControl, AGEMODEL* AgeModel)
{
   if (!Login->IsLoggedIn) {
	 NeotomaLoginForm = new TNeotomaLoginForm(this);
	 NeotomaLoginForm->ShowModal();
	 delete NeotomaLoginForm;
	 }
   if (!Login->IsLoggedIn)
	 return;

   UnicodeString msg, ErrorMsg;

   NeotomaChronoControlsByChronControlID NtmChronControl(ipsJSONS1, TcpClient1);
   NtmChronControl.AddParam(L"CHRONCONTROLID", ChronControl->NeotomaChronControlID);
   ParentForm->StatusBar1->Panels->Items[0]->Text = NtmChronControl.WebServiceName();
   if (!NtmChronControl.Execute())
	 return;
   if (NtmChronControl.Size() != 1) {
	 msg = L"ChronControlID " + IntToStr(ChronControl->NeotomaChronControlID) +
		   L" is not int the Neotoma ChronControls table.";
	 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 return;
	 }

   // easy fixes
   // age type changed
   NeotomaGetAgeTypeID AgeTypeID(ipsJSONS1, TcpClient1);
   UnicodeString AgeUnits = ChronControl->AgeUnits;
   if (SameText(AgeUnits, L"Calendar") || SameText(AgeUnits, L"Radiocarbon"))
	 AgeUnits += L" years BP";

   AgeTypeID.AddParam(L"AGETYPE", AgeUnits);
   ParentForm->StatusBar1->Panels->Items[0]->Text = AgeTypeID.WebServiceName();
   if (AgeTypeID.Execute()) {
	 if (AgeTypeID.Size() != 1) {
	   msg = L"ERROR: Age units «" + ChronControl->AgeUnits + L"» not valid.";
	   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return;
	   }
	 }
   else
	 return;
   if (AgeTypeID.Items[0] != NtmChronControl.Items[0].AgeTypeID) {
	 UpdateData UpdateAgeType(L"UpdateChronControlAgeType", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
	 UpdateAgeType.Add(L"CHRONCONTROLID", ChronControl->NeotomaChronControlID);
	 UpdateAgeType.Add(L"AGETYPEID", AgeTypeID.Items[0]);
	 ParentForm->StatusBar1->Panels->Items[0]->Text = L"UpdateChronControlAgeType";
	 if (!UpdateAgeType.Post(ErrorMsg)) {
	   if (!ErrorMsg.IsEmpty())
		 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return;
	   }
	 }

   // ages changed
   if (ChronControl->AgeValue != NtmChronControl.Items[0].Age ||
	   ChronControl->AgeLimitOlder != NtmChronControl.Items[0].AgeLimitOlder ||
	   ChronControl->AgeLimitYounger != NtmChronControl.Items[0].AgeLimitYounger)
	 {
	 double Age, AgeOlder, AgeYounger;
	 if (!ChronControl->AgeValue.IsEmpty()) {
	   Age = VariantToDouble(ChronControl->AgeValue,-99999);
	   if (Age == -99999) {
		 msg = L"Age value is invalid.";
		 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 return;
		 }
	   }
	 if (!ChronControl->AgeLimitOlder.IsEmpty()) {
	   AgeOlder = VariantToDouble(ChronControl->AgeLimitOlder,-99999);
	   if (AgeOlder == -99999) {
		 msg = L"Older Limit age value is invalid.";
		 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 return;
		 }
	   }
	 if (!ChronControl->AgeLimitYounger.IsEmpty()) {
	   AgeYounger = VariantToDouble(ChronControl->AgeLimitYounger,-99999);
	   if (AgeYounger == -99999) {
		 msg = L"Younger Limit age value is invalid.";
		 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 return;
		 }
	   }

	 if ((ChronControl->AgeLimitOlder.IsEmpty() && !ChronControl->AgeLimitYounger.IsEmpty()) ||
		 (!ChronControl->AgeLimitOlder.IsEmpty() && ChronControl->AgeLimitYounger.IsEmpty())) {
	   msg = L"The Older Limit and Younger Limit must both have values, or both may be empty.";
	   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return;
	   }

	 if (ChronControl->AgeValue.IsEmpty() && ChronControl->AgeLimitOlder.IsEmpty() && ChronControl->AgeLimitYounger.IsEmpty()) {
	   msg = L"Age, Age Older, and Age Younger may not all be empty.";
	   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return;
	   }

	 if (!ChronControl->AgeLimitOlder.IsEmpty() && !ChronControl->AgeLimitYounger.IsEmpty()) {
	   if (!IsAgeYounger(ChronControl->AgeLimitYounger, ChronControl->AgeLimitOlder, AgeModel->AgeUnits)) {
		 msg = L"Age Older and Age Younger are reversed.";
		 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 return;
		 }
	   }

	 // age changed
	 if (ChronControl->AgeValue != NtmChronControl.Items[0].Age) {
	   if (!ChronControl->AgeValue.IsEmpty()) {
		 if (!ChronControl->AgeLimitOlder.IsEmpty()) {
		   if (!IsAgeYounger(ChronControl->AgeValue, ChronControl->AgeLimitOlder, AgeModel->AgeUnits)) {
			 msg = L"Age Older is younger than Age.";
			 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			 return;
			 }
		   }
		 if (!ChronControl->AgeLimitYounger.IsEmpty()) {
		   if (!IsAgeOlder(ChronControl->AgeValue, ChronControl->AgeLimitYounger, AgeModel->AgeUnits)) {
			 msg = L"Age Younger is older than Age.";
			 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			 return;
			 }
		   }
		 }
	   UpdateData UpdateAge(L"UpdateChronControlAge", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
	   UpdateAge.Add(L"CHRONCONTROLID", ChronControl->NeotomaChronControlID);
	   UpdateAge.AddDouble(L"AGE", ChronControl->AgeValue);
	   ParentForm->StatusBar1->Panels->Items[0]->Text = L"UpdateChronControlAge";
	   if (!UpdateAge.Post(ErrorMsg)) {
		 if (!ErrorMsg.IsEmpty())
		  MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 return;
		 }
	   }

	 // age older changed
	 if (ChronControl->AgeLimitOlder != NtmChronControl.Items[0].AgeLimitOlder) {
	   if (!ChronControl->AgeLimitOlder.IsEmpty() && !ChronControl->AgeValue.IsEmpty()) {
		 if (!IsAgeOlder(ChronControl->AgeLimitOlder, ChronControl->AgeValue, AgeModel->AgeUnits)) {
		   msg = L"Age is older than Age Older.";
		   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   return;
		   }
		 }
	   UpdateData UpdateAgeOlder(L"UpdateChronControlAgeOlder", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
	   UpdateAgeOlder.Add(L"CHRONCONTROLID", ChronControl->NeotomaChronControlID);
	   UpdateAgeOlder.AddDouble(L"AGEOLDER", ChronControl->AgeLimitOlder);
	   ParentForm->StatusBar1->Panels->Items[0]->Text = L"UpdateChronControlAgeOlder";
	   if (!UpdateAgeOlder.Post(ErrorMsg)) {
		 if (!ErrorMsg.IsEmpty())
		   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 return;
		 }
	   }

	 // age younger changed
	 if (ChronControl->AgeLimitYounger != NtmChronControl.Items[0].AgeLimitYounger) {
	   if (!ChronControl->AgeLimitYounger.IsEmpty() && !ChronControl->AgeValue.IsEmpty()) {
		 if (!IsAgeYounger(ChronControl->AgeLimitYounger, ChronControl->AgeValue, AgeModel->AgeUnits)) {
		   msg = L"Age is younger than Age Younger.";
		   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   return;
		   }
		 }
	   UpdateData UpdateAgeYounger(L"UpdateChronControlAgeYounger", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
	   UpdateAgeYounger.Add(L"CHRONCONTROLID", ChronControl->NeotomaChronControlID);
	   UpdateAgeYounger.AddDouble(L"AGEYOUNGER", ChronControl->AgeLimitYounger);
	   ParentForm->StatusBar1->Panels->Items[0]->Text = L"UpdateChronControlAgeYounger";
	   if (!UpdateAgeYounger.Post(ErrorMsg)) {
		 if (!ErrorMsg.IsEmpty())
		   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 return;
		}
	   }
	 }

   // depth or thickness changed
   if (ChronControl->Depth != NtmChronControl.Items[0].Depth ||
	   ChronControl->Thickness != NtmChronControl.Items[0].Thickness) {
	 UpdateData UpdateDepthThick(L"UpdateChronControlDepthThickness", 4, ipsHTTPS1, ipsJSONS1, TcpClient1);
	 UpdateDepthThick.Add(L"CHRONCONTROLID", ChronControl->NeotomaChronControlID);
	 UpdateDepthThick.AddDouble(L"DEPTH", ChronControl->Depth);
	 UpdateDepthThick.AddDouble(L"THICKNESS", ChronControl->Thickness);
	 UpdateDepthThick.Add(L"ANALUNITID", ChronControl->NeotomaAnalUnitID);
	 ParentForm->StatusBar1->Panels->Items[0]->Text = L"UpdateChronControlDepthThickness";
	 if (!UpdateDepthThick.Post(ErrorMsg)) {
	   if (!ErrorMsg.IsEmpty())
		 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return;
	   }
	 }

   // notes changed
   if (ChronControl->Notes != NtmChronControl.Items[0].Notes) {
	 UpdateData UpdateNotes(L"UpdateChronControlNotes", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
	 UpdateNotes.Add(L"CHRONCONTROLID", ChronControl->NeotomaChronControlID);
	 UpdateNotes.Add(L"NOTES", ChronControl->Notes);
	 ParentForm->StatusBar1->Panels->Items[0]->Text = L"UpdateChronControlNotes";
	 if (!UpdateNotes.Post(ErrorMsg)) {
	   if (!ErrorMsg.IsEmpty())
		 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return;
	   }
	 }

   /*
   [TS].[UpdateChronControlAnalysisUnit](@CHRONCONTROLID int, @ANALUNITID int)
   UPDATE NDB.ChronControls
   SET AnalysisUnitID = @ANALUNITID
   WHERE ChronControlID = @CHRONCONTROLID
   */

   // harder fixes
   // Age Basis changed
   if (ChronControl->ControlType != NtmChronControl.Items[0].ChronControlType)
	 UpdateNeotomaAgeBasis(false);

   msg = L"ChronControl " + IntToStr(ChronControl->NeotomaChronControlID) + L" updated.";
   MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
}
//---------------------------------------------------------------------------

bool TTilSpreadSheetForm::UpdateNeotomaChronControlAnalUnit(CHRON* ChronControl)
{
   if (!Login->IsLoggedIn) {
	 NeotomaLoginForm = new TNeotomaLoginForm(this);
	 NeotomaLoginForm->ShowModal();
	 delete NeotomaLoginForm;
	 }
   if (!Login->IsLoggedIn)
	 return false;

   bool rv = true;
   UnicodeString ErrorMsg;
   UpdateData UpdateAnalUnit(L"UpdateChronControlAnalysisUnit", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
   UpdateAnalUnit.Add(L"CHRONCONTROLID", ChronControl->NeotomaChronControlID);
   UpdateAnalUnit.Add(L"ANALUNITID", ChronControl->NeotomaAnalUnitID);
   ParentForm->StatusBar1->Panels->Items[0]->Text = L"UpdateChronControlAnalysisUnit";
   if (!UpdateAnalUnit.Post(ErrorMsg)) {
	 if (!ErrorMsg.IsEmpty())
	   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 rv = false;
	 }
   ParentForm->StatusBar1->Panels->Items[0]->Text = L"";
   return rv;
}
//---------------------------------------------------------------------------

bool TTilSpreadSheetForm::UpdateNeotomaGeochronAnalUnit(GEOCHRON* Date)
{
   if (!Login->IsLoggedIn) {
	 NeotomaLoginForm = new TNeotomaLoginForm(this);
	 NeotomaLoginForm->ShowModal();
	 delete NeotomaLoginForm;
	 }
   if (!Login->IsLoggedIn)
	 return false;

   bool rv = true;
   UnicodeString ErrorMsg;
   UpdateData UpdateAnalUnit(L"UpdateGeochronAnalysisUnit", 5, ipsHTTPS1, ipsJSONS1, TcpClient1);
   UpdateAnalUnit.Add(L"GEOCHRONID", Date->NeotomaGeochronID);
   UpdateAnalUnit.Add(L"ANALYSISUNITID", Date->NeotomaAnalUnitID);
   UpdateAnalUnit.AddDouble(L"DEPTH", Date->Depth);
   UpdateAnalUnit.AddDouble(L"THICKNESS", Date->Thickness);
   UpdateAnalUnit.Add(L"ANALYSISUNITNAME", Date->AnalUnit);
   ParentForm->StatusBar1->Panels->Items[0]->Text = L"UpdateGeochronAnalysisUnit";
   if (!UpdateAnalUnit.Post(ErrorMsg)) {
	 if (!ErrorMsg.IsEmpty())
	   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 rv = false;
	 }
   ParentForm->StatusBar1->Panels->Items[0]->Text = L"";
   return rv;
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::UpdateNeotomaAgeBasis(bool query)
{
   CHRON* ChronControl;
   UnicodeString msg;
   UnicodeString ErrorMsg;

   if (Downloaded && tiLicense->Type() == verNEOTOMASTEWARD) {
	 int RecordIndex1 = cxGrid3TableView1->DataController->FocusedRecordIndex;
	 int RecordIndex2 = CurrentChronControlView->DataController->FocusedRecordIndex;

	 AGEMODEL* AgeModel = AgeModelList->AgeModels[RecordIndex1];
	 ChronControl = (CHRON*)AgeModel->ChronControls->Items[RecordIndex2];

	 if (SameText(InitChronControl->ControlType, ChronControl->ControlType))
	   return;

	 if (query) {
	   msg = L"Update Age Basis?";
	   if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) != mrYes)
	     return;
	   }

	 if (!Login->IsLoggedIn) {
	   NeotomaLoginForm = new TNeotomaLoginForm(this);
	   NeotomaLoginForm->ShowModal();
	   delete NeotomaLoginForm;
	   }
	 if (!Login->IsLoggedIn)
	   return;
	 }
   else
	 return;

   // get ChronControlTypeID for new age basis

   bool error = false;
   try {
	   bool found = false;
       int ChronControlTypeID = -1;
	   bool IsGeochronControlType = false;
	   int EventID = -1;
	   NeotomaChronControlTypeByName ChronControlType(ipsJSONS1, TcpClient1);
	   ChronControlType.AddParam(L"CHRONCONTROLTYPE", ChronControl->ControlType);
	   ParentForm->StatusBar1->Panels->Items[0]->Text = ChronControlType.WebServiceName();
	   if (ChronControlType.Execute()) {
		 if (ChronControlType.Size() == 1) {
		   found = true;  // chron control found
		   ChronControlTypeID = ChronControlType.Items[0].ChronControlTypeID;
		   // see if ChronControl is a Geochron control
		   NeotomaChronControlTypeHighestID IsGeochronControl(ipsJSONS1, TcpClient1);
		   IsGeochronControl.AddParam(L"CHRONCONTROLTYPEID", ChronControlTypeID);
		   ParentForm->StatusBar1->Panels->Items[0]->Text = IsGeochronControl.WebServiceName();
		   if (IsGeochronControl.Execute()) {
			 if (IsGeochronControl.Size() == 1) {
			   if (SameText(IsGeochronControl.Items[0].ChronControlType, L"Geochronologic"))
				 IsGeochronControlType = true;
			   }
			 }
		   else  {
			 error = true;
			 return;
			 }
		   }
		 }
	   else {
		 return;
		 }

	   if (!found) {
		 // see if ChronControl is an Event control
		 NeotomaEventChronControlTypeID Event(ipsJSONS1, TcpClient1);
		 Event.AddParam(L"EVENTNAME", ChronControl->ControlType);
		 ParentForm->StatusBar1->Panels->Items[0]->Text = Event.WebServiceName();
		 if (Event.Execute()) {
		   if (Event.Size() == 1) {
			 found = true;
			 EventID = Event.Items[0].first;
			 ChronControlTypeID = Event.Items[0].second;
			 }
		   }
		 }

	   if (!found) {   // TODO: ChronControl type not yet programmed -- relative ages
		 msg = L"Updating to chron control type «" + ChronControl->ControlType + L"» not yet implemented.";
		 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 error = true;
		 return;
		 }

	   if (ChronControlTypeID > -1) {
		 if (IsGeochronControlType)
		   // TODO: if a radiocarbon (geochron) date need to assign to an analysis unit
		   // if former date was event, need to remove
		   ShowMessage(L"GeochronControl: ChronControlTypeID = " + IntToStr(ChronControlTypeID));
		 else { // if (EventID != -1) [   // event control
		   UpdateData UpdateAgeBasis(L"UpdateChronControlAgeBasis", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
		   UpdateAgeBasis.Add(L"CHRONCONTROLID", ChronControl->NeotomaChronControlID);
		   UpdateAgeBasis.Add(L"CHRONCONTROLTYPEID", ChronControlTypeID);
		   ParentForm->StatusBar1->Panels->Items[0]->Text = L"UpdateChronControlAgeBasis";
		   if (!UpdateAgeBasis.Post(ErrorMsg)) {
			 if (!ErrorMsg.IsEmpty())
			   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			 error = true;
			 return;
			 }

		   if (EventID != -1) {  // update event
			 UpdateData UpdateEvent(L"UpdateChronControlEvent", 3, ipsHTTPS1, ipsJSONS1, TcpClient1);
			 UpdateEvent.Add(L"CHRONCONTROLID", ChronControl->NeotomaChronControlID);
			 UpdateEvent.Add(L"EVENTID", EventID);
			 UpdateEvent.Add(L"ANALYSISUNITID", ChronControl->NeotomaAnalUnitID, -1);
			 ParentForm->StatusBar1->Panels->Items[0]->Text = L"UpdateChronControlEvent";
			 if (!UpdateEvent.Post(ErrorMsg)) {
			   if (!ErrorMsg.IsEmpty())
				 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			   error = true;
			   return;
			   }
			 }
		   }
		 //else {
		 //  ShowMessage(L"ChronControlTypeID = " + IntToStr(ChronControlTypeID));
		 //  }
		 }
	   }
   __finally {
	   ParentForm->StatusBar1->Panels->Items[0]->Text = L"";
	   Screen->Cursor = crDefault;
	   if (!error) {
		 if (query) {
		   msg = L"Age Basis for ChronControl " + IntToStr(ChronControl->NeotomaChronControlID) +
				 L" updated to «" + ChronControl->ControlType + L"».";
		   MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
		   }
		 }
	   }
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::DeleteChronControl(int ChronControlID)
{
   UnicodeString msg, ErrorMsg;

   if (Downloaded && tiLicense->Type() == verNEOTOMASTEWARD) {
	 if (!Login->IsLoggedIn) {
	   NeotomaLoginForm = new TNeotomaLoginForm(this);
	   NeotomaLoginForm->ShowModal();
	   delete NeotomaLoginForm;
	 }
	 if (Login->IsLoggedIn) {
	   msg = L"Delete chronology control from Neotoma?";
	   if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo << mbCancel, 0) == mrYes) {
		 try {
			 Screen->Cursor = crHourGlass;
			 DeleteData DeleteControl(L"DeleteChronControl", 1, ipsHTTPS1, ipsJSONS1, TcpClient1);
			 ParentForm->StatusBar1->Panels->Items[0]->Text = L"DeleteChronControl";
			 DeleteControl.Add(L"CHRONCONTROLID", ChronControlID);
			 if (DeleteControl.Post(ErrorMsg)) {
			   msg = L"Chronology control " + IntToStr(ChronControlID) + L" deleted from Neotoma.";
			   MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
			   }
			 else {
			   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			   return;
			   }
			 }
		 __finally {
			 ParentForm->StatusBar1->Panels->Items[0]->Text = L"";
			 Screen->Cursor = crDefault;
			 }
		 }
	   }
	 }
}
//---------------------------------------------------------------------------

bool TTilSpreadSheetForm::UpdateSampleAnalysisUnit(GEOCHRON& Date, int SampleID,
	int NewAnalysisUnitID, int OldAnalysisUnitID)
{
   UnicodeString msg, ErrorMsg;

   UpdateData UpdateAnalUnit(L"UpdateSampleAnalysisUnit", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
   UpdateAnalUnit.Add(L"SAMPLEID", SampleID);
   UpdateAnalUnit.Add(L"ANALUNITID", NewAnalysisUnitID);
   ParentForm->StatusBar1->Panels->Items[0]->Text = L"UpdateSampleAnalysisUnit";
   if (UpdateAnalUnit.Post(ErrorMsg)) {
	 bool comma = false;
	 msg = L"Sample " + IntToStr(SampleID) + L" moved to Analysis Unit " +
		   IntToStr(NewAnalysisUnitID) + L": ";
	 if (!Date.AnalUnit.IsEmpty()) {
	   msg += (L"«" + Date.AnalUnit + L"»");
	   comma = true;
	   }
	 if (!Date.Depth.IsEmpty()) {
	   if (comma) msg += L", ";
	   msg += (L"Depth " + VarToStr(Date.Depth));
	   comma = true;
	   }
	 if (!Date.Thickness.IsEmpty()) {
	   if (comma) msg += L", ";
	   msg += (L"Thickness " + VarToStr(Date.Thickness));
	   }
	 msg += L".";
	 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
	 }
   else {
	 if (!ErrorMsg.IsEmpty())
	   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 return false;
   }

   // see if any samples are assigned to old analysis unit
   // if there are none, delete it.
   NeotomaGetAnalysisUnitSampleCount SampleCount(ipsJSONS1, TcpClient1);
   SampleCount.AddParam(L"ANALUNITID", OldAnalysisUnitID);
   ParentForm->StatusBar1->Panels->Items[0]->Text = SampleCount.WebServiceName();
   if (SampleCount.Execute()) {
	 if (SampleCount.Size() == 1) {
	   if (SampleCount.Items[0] == 0) {
		 // first see if any chron controls are assigned to analysis unit,
		 // if so move them to the new analysis unit
		 NeotomaGetAnalysisUnitSampleCount ChronControls(ipsJSONS1, TcpClient1);
		 ChronControls.AddParam(L"ANALUNITID", OldAnalysisUnitID);
		 ParentForm->StatusBar1->Panels->Items[0]->Text = ChronControls.WebServiceName();
		 if (ChronControls.Execute()) {
		   if (ChronControls.Size() > 0) {
			 for (unsigned int i = 0; i < ChronControls.Size(); i++) {
			   UpdateData UpdateChronControlAnalUnit(L"UpdateChronControlAnalysisUnit", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
			   UpdateChronControlAnalUnit.Add(L"CHRONCONTROLID", ChronControls.Items[i]);
			   UpdateChronControlAnalUnit.Add(L"ANALUNITID", NewAnalysisUnitID);
			   ParentForm->StatusBar1->Panels->Items[0]->Text = L"UpdateChronControlAnalysisUnit";
			   if (!UpdateChronControlAnalUnit.Post(ErrorMsg)) {
				 if (!ErrorMsg.IsEmpty())
				   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
				 return false;
				 }
			   }
			 }
		   }
		 else
		   return false;

		 // now delete analysis unit
		 DeleteData DeleteAnalUnit(L"DeleteAnalysisUnit", 1, ipsHTTPS1, ipsJSONS1, TcpClient1);
		 ParentForm->StatusBar1->Panels->Items[0]->Text = L"DeleteAnalysisUnit";
		 DeleteAnalUnit.Add(L"ANALUNITID", OldAnalysisUnitID);
		 if (DeleteAnalUnit.Post(ErrorMsg)) {
		   msg = L"AnalysisUnitID " + IntToStr(OldAnalysisUnitID) +
				 L" previously assigned to GeochronlogID " + IntToStr(Date.NeotomaGeochronID) +
				 L" had no other samples assigned and was deleted.";
		   MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
		   }
		 else {
		   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   return false;
		   }
		 }
	   }
	 }
   else
	 return false;

   return true;
}
//---------------------------------------------------------------------------

bool TTilSpreadSheetForm::ValidateDate(GEOCHRON& Date)
{
   UnicodeString msg;

   if (Date.Age.IsEmpty()) {
	 msg = L"Error: Age value missing.";
	 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 return false;
	 }
   if (!Date.GreaterThan) {
	 if (Date.ErrorOlder.IsEmpty() && Date.ErrorYounger.IsEmpty()) {
	   msg = L"WARNING: No error values entered.";
	   if (MessageDlg(msg, mtWarning, TMsgDlgButtons() << mbOK << mbAbort, 0) == mrAbort)
		 return false;
	   }
	 else if (Date.ErrorOlder.IsEmpty()) {
	   msg = L"ERROR: AgeYounger entered but not AgeOlder.";
	   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return false;
	   }
	 else if (Date.ErrorYounger.IsEmpty()) {
	   msg = L"ERROR: AgeOlder entered but not AgeYounger.";
	   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return false;
	   }
	 else {
	   double sigma = Date.Sigma;
	   Date.ErrorOlder = (double)Date.ErrorOlder/sigma;
	   Date.ErrorYounger = (double)Date.ErrorYounger/sigma;
	   }
	 }
   else if (!Date.ErrorOlder.IsEmpty() || !Date.ErrorYounger.IsEmpty()) {
	 msg = L"ERROR: «Greater than» dates cannot have error values.";
	 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 return false;
	 }

   return true;
}
//---------------------------------------------------------------------------

bool TTilSpreadSheetForm::GetDateAnalysisUnitID(GEOCHRON& Date, int& AnalysisUnitID)
{
   double Depth, Thickness;
   AnalysisUnitID = -1;

   NeotomaGetAnalysisUnit AnalUnit(ipsJSONS1, TcpClient1);
   AnalUnit.AddParam(L"COLLECTIONUNIID", CollPtr->NeotomaCollUnitID);
   if (!Date.AnalUnit.IsEmpty())
	 AnalUnit.AddParam(L"ANALUNITNAME", Date.AnalUnit);
   if (!Date.Depth.IsEmpty()) {
	 if (TryVariantToDouble(Date.Depth, Depth))
	   AnalUnit.AddParam(L"DEPTH", Depth);
	 }
   if (!Date.Thickness.IsEmpty()) {
	 if (TryVariantToDouble(Date.Thickness, Thickness))
	   AnalUnit.AddParam(L"THICKNESS", Thickness);
	 }
   ParentForm->StatusBar1->Panels->Items[0]->Text = AnalUnit.WebServiceName();
   if (AnalUnit.Execute()) {
	 if (AnalUnit.Size() == 1)
	   AnalysisUnitID = AnalUnit.Items[0];
	 }
   else
	 return false;
   return true;
}
//---------------------------------------------------------------------------

bool TTilSpreadSheetForm::GetRadiocarbonParams(GEOCHRON& Date, map<UnicodeString,double>& RadiocarbonParams)
{
   UnicodeString msg;
   int nparams = 0;

   // get needed parameters
   map<int,UnicodeString> RadiocarbonMethods;
   NeotomaRadiocarbonMethodsTable Methods(ipsJSONS1, TcpClient1);
   ParentForm->StatusBar1->Panels->Items[0]->Text = Methods.WebServiceName();
   if (Methods.Execute())
	 RadiocarbonMethods = Methods.Items;
   else
	 return false;

   map<UnicodeString,Variant>::iterator itr;
   for (itr = Date.Parameters.begin(); itr != Date.Parameters.end(); itr++) {
	 if (SameText(itr->first, L"Method")) {
	   UnicodeString C14Method = VarToStr(itr->second);
	   bool found = false;
	   map<int,UnicodeString>::iterator rit;
	   for (rit = RadiocarbonMethods.begin(); rit != RadiocarbonMethods.end(); rit++) {
		 if (SameText(C14Method, rit->second)) {
		   RadiocarbonParams[L"Method"] = rit->first;
		   nparams++;
		   found = true;
		   break;
		   }
		 }
	   if (!found) {
		 msg = L"Radiocarbon method " + C14Method + " is not valid.";
		 MessageDlg(msg, mtWarning, TMsgDlgButtons() << mbOK, 0);
		 }
	   }
	 else {
	   if (itr->second.Type() == varDouble) {
		 RadiocarbonParams[itr->first] = itr->second;
		 nparams++;
		 if (SameText(itr->first, L"δ13C")) {
		   double Delta13C = itr->second;
		   if (Delta13C > 0) {
			 msg = L"δ13C value is >0. Most δ13C values are negative.";
			 MessageDlg(msg, mtWarning, TMsgDlgButtons() << mbOK, 0);
			 }
		   }
		 }
	   else {
		 msg = L"Radiocarbon parameter value " + VarToStr(itr->second.Type()) +
			   L" is not a floating point number.";
		 MessageDlg(msg, mtWarning, TMsgDlgButtons() << mbOK, 0);
		 }
	   }
	 }
   return (nparams > 0);
}
//---------------------------------------------------------------------------

bool TTilSpreadSheetForm::UploadAnalysisUnit(NEOTOMAANALUNIT& AnalUnit)
{
				   // NEOTOMAANALUNIT() { AnalysisUnitID = -1; CollectionUnitID = -1; FaciesID = -1;
				   //	  DepAgentID = -1; Mixed = false; }
   UnicodeString ErrorMsg;
   vector<int> newids;

   InsertData InsertAnalysisUnit(L"InsertAnalysisUnit", 5, ipsHTTPS1, ipsJSONS1, TcpClient1);
   InsertAnalysisUnit.Add(L"COLLECTIONUNITID", CollPtr->NeotomaCollUnitID);
   if (!AnalUnit.AnalysisUnitName.IsEmpty())
	 InsertAnalysisUnit.Add(L"ANALYSISUNITNAME", AnalUnit.AnalysisUnitName);
   if (!AnalUnit.Depth.IsEmpty())
	 InsertAnalysisUnit.AddDouble(L"DEPTH", AnalUnit.Depth);
   if (!AnalUnit.Thickness.IsEmpty())
	 InsertAnalysisUnit.AddDouble(L"THICKNESS", AnalUnit.Thickness);
   InsertAnalysisUnit.Add(L"MIXED", AnalUnit.Mixed);
   if (!AnalUnit.FaciesID != -1)
	 InsertAnalysisUnit.AddInt(L"FACIESID",Variant(AnalUnit.FaciesID));
   if (!AnalUnit.DepAgentID != -1)

   ParentForm->StatusBar1->Panels->Items[0]->Text = L"InsertAnalysisUnit";
   InsertAnalysisUnit.PostData();
   if (InsertAnalysisUnit.Post(newids, ErrorMsg)) {
	 if (newids.size() == 1)
	   AnalUnit.AnalysisUnitID = newids[0];
	 else  {
	   ErrorMsg = L"Error inserting into AnalysisUnits table!";
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

bool TTilSpreadSheetForm::UploadAnalysisUnit(GEOCHRON& Date, int& AnalysisUnitID)
{
   UnicodeString ErrorMsg;
   vector<int> newids;

   InsertData InsertAnalysisUnit(L"InsertAnalysisUnit", 5, ipsHTTPS1, ipsJSONS1, TcpClient1);
   InsertAnalysisUnit.Add(L"COLLECTIONUNITID", CollPtr->NeotomaCollUnitID);
   InsertAnalysisUnit.Add(L"ANALYSISUNITNAME", Date.AnalUnit);
   InsertAnalysisUnit.AddDouble(L"DEPTH", Date.Depth);
   InsertAnalysisUnit.AddDouble(L"THICKNESS", Date.Thickness);
   InsertAnalysisUnit.Add(L"MIXED", false);

   ParentForm->StatusBar1->Panels->Items[0]->Text = L"InsertAnalysisUnit";
   InsertAnalysisUnit.PostData();
   if (InsertAnalysisUnit.Post(newids, ErrorMsg)) {
	 if (newids.size() == 1)
	   AnalysisUnitID = newids[0];
	 else  {
	   ErrorMsg = L"Error inserting into AnalysisUnits table!";
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

bool TTilSpreadSheetForm::GetGeochronIDs(GEOCHRON& Date, int& GeochronTypeID, int& AgeTypeID)
{
   UnicodeString msg;

   // validate method
   if (Date.Method.IsEmpty()) {
	 msg = L"ERROR: Geochron method cannot be blank.";
	 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 return false;
	 }
   NeotomaGetGeochronTypeID GetGeochronTypeID(ipsJSONS1, TcpClient1);
   GetGeochronTypeID.AddParam(L"GEOCHRONTYPE", Date.Method);
   ParentForm->StatusBar1->Panels->Items[0]->Text = GetGeochronTypeID.WebServiceName();
   if (GetGeochronTypeID.Execute()) {
	 if (GetGeochronTypeID.Size() == 1)
	   GeochronTypeID = GetGeochronTypeID.Items[0];
	 else {
	   msg = L"ERROR: Geochron method «" + Date.Method + L"» not valid.";
	   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return false;
	   }
	 }
   else
	 return false;

   // validate age type
   if (Date.AgeUnits.IsEmpty()) {
	 msg = L"ERROR: Geochron age  cannot be blank.";
	 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 return false;
	 }
   NeotomaGetAgeTypeID GetAgeTypeID(ipsJSONS1, TcpClient1);
   GetAgeTypeID.AddParam(L"AGETYPE", Date.AgeUnits);
   ParentForm->StatusBar1->Panels->Items[0]->Text = GetAgeTypeID.WebServiceName();
   if (GetAgeTypeID.Execute()) {
	 if (GetAgeTypeID.Size() == 1)
	   AgeTypeID = GetAgeTypeID.Items[0];
	 else {
	   msg = L"ERROR: Age units «" + Date.AgeUnits + L"» not valid.";
	   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return false;
	   }
	 }
   else
	 return false;

   return true;
}
//---------------------------------------------------------------------------

bool TTilSpreadSheetForm::IsSameGeochron(int GeochronTypeID, int AgeTypeID,
	GEOCHRON& Date, NTMGEOCHRON& NtmDate)
{
   if (GeochronTypeID != NtmDate.GeochronTypeID)
	 return false;
   else if (AgeTypeID != NtmDate.AgeTypeID)
	 return false;
   else if (Date.Age != NtmDate.Age)
	 return false;
   else if (Date.ErrorOlder != NtmDate.ErrorOlder)
	 return false;
   else if (Date.ErrorYounger != NtmDate.ErrorYounger)
	 return false;
   else if (Date.GreaterThan != NtmDate.Infinite)
	 return false;
   else if (Date.LabNumber != NtmDate.LabNumber)
	 return false;
   else if (Date.MaterialDated != NtmDate.MaterialDated)
	 return false;
   else if (Date.Notes != NtmDate.Notes)
	 return false;
   else
	 return true;
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::UpdateRadiocarbonParams(GEOCHRON& Date)
{
   int GeochronTypeID;
   int RadiocarbonMethodID;
   UnicodeString msg, ErrorMsg;

   if (!Login->IsLoggedIn) {
	 NeotomaLoginForm = new TNeotomaLoginForm(this);
	 NeotomaLoginForm->ShowModal();
	 delete NeotomaLoginForm;
	 }
   if (!Login->IsLoggedIn)
	 return;

   Screen->Cursor = crHourGlass;
   try {
   NeotomaGetGeochronTypeID GetGeochronTypeID(ipsJSONS1, TcpClient1);
   GetGeochronTypeID.AddParam(L"GEOCHRONTYPE", Date.Method);
   ParentForm->StatusBar1->Panels->Items[0]->Text = GetGeochronTypeID.WebServiceName();
   if (GetGeochronTypeID.Execute()) {
	 if (GetGeochronTypeID.Size() == 1)
	   GeochronTypeID = GetGeochronTypeID.Items[0];
	 else {
	   msg = L"ERROR: Geochron method «" + Date.Method + L"» not valid.";
	   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return;
	   }
	 }
   else
	 return;

   if (GeochronTypeID == 2) {
	 map<UnicodeString,Variant>::iterator itr;
	 if ((itr = Date.Parameters.find(L"Method")) != Date.Parameters.end()) {
	   NeotomaGetRadiocarbonMethodID Get14CMethodID(ipsJSONS1, TcpClient1);
	   Get14CMethodID.AddParam(L"RADIOCARBONMETHOD", VarToStr(itr->second));
	   ParentForm->StatusBar1->Panels->Items[0]->Text = Get14CMethodID.WebServiceName();
	   if (Get14CMethodID.Execute()) {
		 if (Get14CMethodID.Size() == 1)
		   RadiocarbonMethodID = Get14CMethodID.Items[0];
		 else {
		   msg = L"ERROR: Radiocarbon Method «" + itr->second + L"» not valid.";
		   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   return;
		   }
		 }
	   else
		 return;
	   }
	 else {
	   msg = L"ERROR: Radiocarbon param «Method» not entered.";
	   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return;
	   }

	 for (itr = Date.Parameters.begin(); itr != Date.Parameters.end(); itr++) {
	   if (!SameText(itr->first,L"Method")) {
		 if (itr->second.Type() == varDouble) {
			if (SameText(itr->first, L"δ13C")) {
			  double Delta13C = itr->second;
			  if (Delta13C > 0) {
				msg = L"WARNING: δ13C value is >0. Most δ13C values are negative.";
				if (MessageDlg(msg, mtWarning, TMsgDlgButtons() << mbOK << mbAbort, 0) == mrAbort)
				  return;
				}
			  }
			}
		  else {
			msg = L"ERROR: Radiocarbon parameter value for «" + itr->first +
				  L"» is not a floating point number.";
			return;
			}
		 }
	   }

	 // see if Radiocarbon param data already exist
	 bool exists = false;
	 NeotomaGetGeochronIDCount RadiocarbonCount(ipsJSONS1, TcpClient1);
	 RadiocarbonCount.AddParam(L"GEOCHRONID", Date.NeotomaGeochronID);
	 ParentForm->StatusBar1->Panels->Items[0]->Text = RadiocarbonCount.WebServiceName();
	 if (RadiocarbonCount.Execute()) {
	   if (RadiocarbonCount.Size() == 1) {
		 if (RadiocarbonCount.Items[0] == 1)
		   exists = true;
		 }
	   }
	 else
	   return;

	 if (exists) {
	   // update existing radiocarbon record
	   Variant MassCmg, PercentC, PercentN, CNRatio, Delta13C, Delta15N, PercentCollagen, Reservoir;
	   UpdateData UpdateRadiocarbon(L"UpdateRadiocarbon", 10, ipsHTTPS1, ipsJSONS1, TcpClient1);
	   UpdateRadiocarbon.Add(L"GEOCHRONID", Date.NeotomaGeochronID);
	   UpdateRadiocarbon.Add(L"RADIOCARBONMETHODID", RadiocarbonMethodID);
	   map<UnicodeString,Variant>::iterator itr;
	   /*
	   for (itr = Date.Parameters.begin(); itr != Date.Parameters.end(); itr++) {
		 if (SameText(itr->first,L"Mass C (mg)"))
		   UpdateRadiocarbon.AddDouble(L"MASSCMG",itr->second);
		 else if (SameText(itr->first,L"%C"))
		   UpdateRadiocarbon.AddDouble(L"PERCENTC",itr->second);
		 else if (SameText(itr->first,L"%N"))
		   UpdateRadiocarbon.AddDouble(L"PERCENTN",itr->second);
		 else if (SameText(itr->first,L"C:N"))
		   UpdateRadiocarbon.AddDouble(L"CNRATIO",itr->second);
		 else if (SameText(itr->first,L"δ13C"))
		   UpdateRadiocarbon.AddDouble(L"DELTA13C",itr->second);
		 else if (SameText(itr->first,L"δ15N"))
		   UpdateRadiocarbon.AddDouble(L"DELTA15N",itr->second);
		 else if (SameText(itr->first,L"%collagen"))
		   UpdateRadiocarbon.AddDouble(L"PERCENTCOLLAGEN",itr->second);
		 else if (SameText(itr->first,L"Reservoir (yrs)"))
		   UpdateRadiocarbon.AddDouble(L"RESERVOIR",itr->second);
		 }
	   */
	   for (itr = Date.Parameters.begin(); itr != Date.Parameters.end(); itr++) {
		 if (SameText(itr->first,L"Mass C (mg)"))
		   MassCmg = itr->second;
		 else if (SameText(itr->first,L"%C"))
		   PercentC = itr->second;
		 else if (SameText(itr->first,L"%N"))
		   PercentN = itr->second;
		 else if (SameText(itr->first,L"C:N"))
		   CNRatio = itr->second;
		 else if (SameText(itr->first,L"δ13C"))
		   Delta13C = itr->second;
		 else if (SameText(itr->first,L"δ15N"))
		   Delta15N = itr->second;
		 else if (SameText(itr->first,L"%collagen"))
		   PercentCollagen = itr->second;
		 else if (SameText(itr->first,L"Reservoir (yrs)"))
		   Reservoir = itr->second;
		 }
	   UpdateRadiocarbon.AddDouble(L"MASSCMG",MassCmg);
	   UpdateRadiocarbon.AddDouble(L"PERCENTC",PercentC);
	   UpdateRadiocarbon.AddDouble(L"PERCENTN",PercentN);
	   UpdateRadiocarbon.AddDouble(L"CNRATIO",CNRatio);
	   UpdateRadiocarbon.AddDouble(L"DELTA13C",Delta13C);
	   UpdateRadiocarbon.AddDouble(L"DELTA15N",Delta15N);
	   UpdateRadiocarbon.AddDouble(L"PERCENTCOLLAGEN",PercentCollagen);
	   UpdateRadiocarbon.AddDouble(L"RESERVOIR",Reservoir);

	   ParentForm->StatusBar1->Panels->Items[0]->Text = L"UpdateRadiocarbon";
	   if (UpdateRadiocarbon.Post(ErrorMsg)) {
		 msg = L"Radiocarbon parameters updated for GeochronID " + IntToStr(Date.NeotomaGeochronID) + L".";
		 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
		 }
	   else {
		 if (!ErrorMsg.IsEmpty())
		   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 return;
		 }
	   }
	 else {
	   // insert new radiocarbon record
	   InsertData InsertRadiocarbon(L"InsertRadiocarbon", 10, ipsHTTPS1, ipsJSONS1, TcpClient1);
	   InsertRadiocarbon.Add(L"GEOCHRONID", Date.NeotomaGeochronID);
	   InsertRadiocarbon.Add(L"RADIOCARBONMETHODID", RadiocarbonMethodID);
	   map<UnicodeString,Variant>::iterator itr;
	   Variant MassCmg, PercentC, PercentN, Delta13C, CN, Delta15N, PercentCollagen, Reservoir;
	   for (itr = Date.Parameters.begin(); itr != Date.Parameters.end(); itr++) {
		 if (SameText(itr->first,L"Mass C (mg)"))
		   MassCmg = itr->second;
		 else if (SameText(itr->first,L"%C"))
		   PercentC = itr->second;
		 else if (SameText(itr->first,L"%N"))
		   PercentN = itr->second;
		 else if (SameText(itr->first,L"C:N"))
		   CN = itr->second;
		 else if (SameText(itr->first,L"δ13C"))
		   Delta13C = itr->second;
		 else if (SameText(itr->first,L"δ15N"))
		   Delta15N = itr->second;
		 else if (SameText(itr->first,L"%collagen"))
		   PercentCollagen = itr->second;
		 else if (SameText(itr->first,L"Reservoir (yrs)"))
		   PercentCollagen = Reservoir;
		 }
	   InsertRadiocarbon.AddDouble(L"MASSCMG",MassCmg);
	   InsertRadiocarbon.AddDouble(L"PERCENTC",PercentC);
	   InsertRadiocarbon.AddDouble(L"PERCENTN",PercentN);
	   InsertRadiocarbon.AddDouble(L"CNRATIO",CN);
	   InsertRadiocarbon.AddDouble(L"DELTA13C",Delta13C);
	   InsertRadiocarbon.AddDouble(L"DELTA15N",Delta15N);
	   InsertRadiocarbon.AddDouble(L"PERCENTCOLLAGEN",PercentCollagen);
	   InsertRadiocarbon.AddDouble(L"RESERVOIR",Reservoir);
	   ParentForm->StatusBar1->Panels->Items[0]->Text = L"InsertRadiocarbon";
	   InsertRadiocarbon.PostData();
	   if (InsertRadiocarbon.Post(ErrorMsg)) {
		 msg = L"Radiocarbon parameters uploaded for GeochronID " + IntToStr(Date.NeotomaGeochronID) + L".";
		 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
		 }
	   else {
		 if (!ErrorMsg.IsEmpty())
		   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 return;
		 }
	   }
	 }
   }
   __finally {
   ParentForm->StatusBar1->Panels->Items[0]->Text = L"";
   Screen->Cursor = crDefault;
   }
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::UpdateNeotomaChronology(AGEMODEL* AgeModel)
{
   UnicodeString msg, ErrorMsg;

   if (!Login->IsLoggedIn) {
	 NeotomaLoginForm = new TNeotomaLoginForm(this);
	 NeotomaLoginForm->ShowModal();
	 delete NeotomaLoginForm;
	 }
   if (!Login->IsLoggedIn)
	 return;

   if (AgeModel->ChronologyName.IsEmpty()) {
	 msg = L"ERROR: Chronology name cannot be blank.";
	 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 return;
	 }

   if (AgeModel->AgeModel.IsEmpty()) {
	 msg = L"ERROR: Age Model cannot be blank.";
	 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 return;
	 }

   if (AgeModel->AgeBoundOlder.IsEmpty()) {
	 msg = L"ERROR: Older Age Bound not entered.";
	 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 return;
	 }

   if (AgeModel->AgeBoundYounger.IsEmpty()) {
	 msg = L"ERROR: Younger Age Bound not entered.";
	 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 return;
	 }

   int AgeBoundYounger = (int)AgeModel->AgeBoundYounger;
   int AgeBoundOlder = (int)AgeModel->AgeBoundOlder;
   if (AgeBoundYounger > AgeBoundOlder) {
	 msg = L"ERROR: Younger Age Bound is older than Older Age Bound.";
	 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 return;
	 }

   if (AgeModel->Preparers.size() > 1) {
	 msg = L"ERROR: At this time only one preparer can be designated for Neotoma.";
	 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 return;
	 }
   else if (AgeModel->Preparers.size() == 1) {
	 if (AgeModel->Preparers[0]->NeotomaContactID == -1) {
	   msg = L"ERROR: Chronology preparer not matched with Neotoma ContactID.";
	   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return;
	   }
	 }

   UnicodeString date_str;
   if (!AgeModel->DatePrepared.IsEmpty() && AgeModel->DatePrepared.Type() == varDate) {
	 TDateTime Date = AgeModel->DatePrepared;
	 date_str = Date.FormatString(L"yyyy-mm-dd");
	 }

   UpdateData UpdateChron(L"UpdateChronology", 10, ipsHTTPS1, ipsJSONS1, TcpClient1);
   ParentForm->StatusBar1->Panels->Items[0]->Text = L"UpdateChronology";
   UpdateChron.Add(L"CHRONOLOGYID", AgeModel->NeotomaChronologyID);
   UpdateChron.Add(L"AGETYPE", AgeModel->AgeUnits);
   Variant ContactID;
   if (AgeModel->Preparers.size() > 0)
	 ContactID = AgeModel->Preparers[0]->NeotomaContactID;
   UpdateChron.AddInt(L"CONTACTID", ContactID);
   UpdateChron.Add(L"ISDEFAULT", AgeModel->Default);
   UpdateChron.Add(L"CHRONOLOGYNAME", AgeModel->ChronologyName);
   UpdateChron.Add(L"DATEPREPARED", date_str);
   UpdateChron.Add(L"AGEMODEL", AgeModel->AgeModel);
   Variant VAgeBoundYounger, VAgeBoundOlder;
   if (!AgeModel->AgeBoundYounger.IsEmpty() && !AgeModel->AgeBoundOlder.IsEmpty()) {
	 //UpdateChron.Add(L"AGEBOUNDYOUNGER", AgeBoundYounger);
	 //UpdateChron.Add(L"AGEBOUNDOLDER", AgeBoundOlder);
	 VAgeBoundYounger = AgeBoundYounger;
	 VAgeBoundOlder = AgeBoundOlder;
	 }
   UpdateChron.AddDouble(L"AGEBOUNDYOUNGER", VAgeBoundYounger);
   UpdateChron.AddDouble(L"AGEBOUNDOLDER", AgeBoundOlder);
   UpdateChron.Add(L"NOTES", AgeModel->Notes);

   if (UpdateChron.Post(ErrorMsg)) {
	 msg = L"Success: Neotoma Chronology " + IntToStr(AgeModel->NeotomaChronologyID) + L" «" +
		   AgeModel->ChronologyName	+ L"» updated!";
	 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
	 }
   else if (!ErrorMsg.IsEmpty()) {
	 msg = ErrorMsg + L"\nChronology not updated.";
	 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 }
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::DeleteNeotomaChron(int ChronNo, int NeotomaChronologyID,
	UnicodeString ChronName)
{
   UnicodeString ErrorMsg;

   if (!Login->IsLoggedIn) {
	 NeotomaLoginForm = new TNeotomaLoginForm(this);
	 NeotomaLoginForm->ShowModal();
	 delete NeotomaLoginForm;
	 }
   if (!Login->IsLoggedIn)
	 return;

   Screen->Cursor = crHourGlass;
   DeleteData DeleteChron(L"DeleteChronology", 1, ipsHTTPS1, ipsJSONS1, TcpClient1);
   DeleteChron.Add(L"CHRONOLOGYID", NeotomaChronologyID);
   if (DeleteChron.Post(ErrorMsg)) {
	 // delete chron from spreadsheet
	 UnicodeString ChronCode = L"#Chron" + IntToStr(ChronNo);
	 int len = ChronCode.Length();
	 int RowCount = AbsContentRowCount(ProfGrid1);
	 for (int row = RowCount; row >= 3; row--) {
	   UnicodeString VarCode = ProfGrid1->AbsoluteCells[1][row]->Text;
	   if (SameText(ChronCode, VarCode.SubString(1,len)))
		 ProfGrid1->DeleteRow(row);
	   }

	 UnicodeString msg = L"Success! Chronology " + IntToStr(NeotomaChronologyID) +
		" «" + ChronName + L"» deleted from the Neotoma Chronologies table.";
	 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
	 }
   else {
	 UnicodeString msg = L"Attempt to delete record failed:";
	 if (!ErrorMsg.IsEmpty())
	   msg += (L": " + ErrorMsg);
	 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 }
   Screen->Cursor = crDefault;
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::UpdateDatasetType(int NeotomaDatasetID, UnicodeString NewDataType)
{
   UnicodeString msg, ErrorMsg;

   msg = L"Update DatasetID " + IntToStr(NeotomaDatasetID) + L" to «" + NewDataType + L"»?";
   if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) != mrYes)
	 return;

   if (!Login->IsLoggedIn) {
	 NeotomaLoginForm = new TNeotomaLoginForm(this);
	 NeotomaLoginForm->ShowModal();
	 delete NeotomaLoginForm;
	 }
   if (!Login->IsLoggedIn)
	 return;

   Screen->Cursor = crHourGlass;
   UpdateData UpdateDatasetType(L"UpdateDatasetType", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
   ParentForm->StatusBar1->Panels->Items[0]->Text = L"UpdateDatasetType";
   UpdateDatasetType.Add(L"DATASETID", NeotomaDatasetID);
   UpdateDatasetType.Add(L"DATASETTYPE", NewDataType);
   if (UpdateDatasetType.Post(ErrorMsg)) {
	 msg = L"Success: Dataset type for DatasetID " + IntToStr(NeotomaDatasetID) +
		   L" updated to «" + NewDataType + L"».";
	 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
	 }
   else if (!ErrorMsg.IsEmpty()) {
	 msg = ErrorMsg + L"\nDataset type not updated.";
	 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 }

   Screen->Cursor = crDefault;
}
//---------------------------------------------------------------------------

