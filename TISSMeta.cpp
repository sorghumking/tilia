//---------------------------------------------------------------------------
#include <FileCtrl.hpp>
#define VCL_IOSTREAM
#include <vcl.h>
#include "pch.h"
#include "io.h"
#include <map>
#include <list>
#include <vector>
#include <iterator>
#include <algorithm>

#pragma hdrstop

#include "TISSMeta.h"
#include <DateUtils.hpp>
#include <Math.hpp>
#include <SysUtils.hpp>
#include "TISpread.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

void TTilSpreadSheetForm::GetSSSiteMetaData(void)
{
   int SiteNameRow;
   int SiteNo;

   SiteNameRow = FindRowMD(SITE_NAME);
   if (SiteNameRow > 0) {
	 int RowCount = ContentRowCount(ProfGrid1);
	 int ColCount = AbsContentColCount(ProfGrid1);
	 int StartCol = AbsHeaderColCount(ProfGrid1);
	 TProfGridRow* SSSiteNames = ProfGrid1->AbsoluteRows[SiteNameRow];
	 for (int col=StartCol; col<=ColCount; col++) {
	   UnicodeString SiteName = SSSiteNames->AbsoluteCells[col]->Text;
	   if (!SiteName.IsEmpty()) {
		 if ((SiteNo = FindSite(SiteName)) > 0) {
		   CELLOBJECT* CellObject = new CELLOBJECT((SITE*)Sites->Items[SiteNo]);
		   AddCellObject(SSSiteNames->AbsoluteCells[col], CellObject);
		   }
		 else {
		   SITE* Site = new SITE();
		   Site->SiteName = SiteName;
		   Sites->Add(Site);
		   CELLOBJECT* CellObject = new CELLOBJECT(Site);
		   AddCellObject(SSSiteNames->AbsoluteCells[col], CellObject);
		   }
		 }
	   }

	 // add rest of spreadsheet site metadata to sites
	 TProfGridColumn* CodeCol = ProfGrid1->AbsoluteCols[1];
	 for (int row=3; row<=RowCount; row++) {
	   UnicodeString Code = CodeCol->AbsoluteCells[row]->Value;
	   Code = Code.UpperCase();
	   if (SameText(Code.SubString(1,6), L"#SITE.")) {
		 Code.Delete(1,6);
		 TProfGridRow* MDRow = ProfGrid1->AbsoluteRows[row];
		 for (int col=StartCol; col<=ColCount; col++) {
		   Variant Value = MDRow->AbsoluteCells[col]->Value;
		   if (!Value.IsEmpty()) {
			 UnicodeString SiteName = ProfGrid1->AbsoluteCells[col][SiteNameRow]->Text;
			 if (!SiteName.IsEmpty()) {
			   if ((SiteNo = FindSite(SiteName)) > 0) {
				 SITE* site_ptr = (SITE*)Sites->Items[SiteNo];
				 if (SameText(Code, L"LATN"))
				   DecodeSSMD(site_ptr->LatNorth, Value);
				 else if (SameText(Code, L"LATS"))
				   DecodeSSMD(site_ptr->LatSouth, Value);
				 else if (SameText(Code, L"LONGE"))
				   DecodeSSMD(site_ptr->LongEast, Value);
				 else if (SameText(Code, L"LONGW"))
				   DecodeSSMD(site_ptr->LongWest, Value);
				 else if (SameText(Code, L"GEOPOL1"))
				   DecodeSSMD(site_ptr->Country, Value);
				 else if (SameText(Code, L"GEOPOL2"))
				   DecodeSSMD(site_ptr->State, Value);
				 else if (SameText(Code, L"GEOPOL3"))
				   DecodeSSMD(site_ptr->County, Value);
				 else if (SameText(Code, L"ADMIN"))
				   DecodeSSMD(site_ptr->AdminUnit, Value);
				 else if (SameText(Code, L"ALTITUDE"))
				   DecodeSSMD(site_ptr->Altitude, Value);
				 else if (SameText(Code, L"AREA"))
				   DecodeSSMD(site_ptr->Area, Value);
				 else if (SameText(Code, L"DESC"))
				   DecodeSSMD(site_ptr->SiteDescription, Value);
				 else if (SameText(Code, L"NOTES"))
				   DecodeSSMD(site_ptr->Notes, Value);
				 // >=version 2.0.2 should have all metadata items in all site
				 // columns, so don't need to iterate through all columns.
				 if (xml_Version >= VERSION(2,0,2))
				   break;
				 }
			   }
			 }
		   }
		 }
	   else if (SameText(Code.SubString(1,6), L"#LAKE.")) {
		 Code.Delete(1,6);
		 TProfGridRow* MDRow = ProfGrid1->AbsoluteRows[row];
		 for (int col=StartCol; col<=ColCount; col++) {
		   Variant Value = MDRow->AbsoluteCells[col]->Value;
		   if (!Value.IsEmpty()) {
			 UnicodeString SiteName = ProfGrid1->AbsoluteCells[col][SiteNameRow]->Text;
			 if (!SiteName.IsEmpty()) {
			   int i;
			   if ((i = FindSite(SiteName)) > -1) {
				 WideString LakeParamName;
				 list<LAKEPARAMETER>::iterator itr1 = LakeChar.begin();
				 while (itr1 != LakeChar.end()) {
				   UnicodeString LakeParamCode = (*itr1).Code;
				   if (SameText(Code, LakeParamCode)) {
					 LakeParamName = (*itr1).Name;
					 break;
					 }
				   itr1++;
				   }
				 // fill SSite->LakeParams
				 bool found = false;
				 SITE* site_ptr = (SITE*)Sites->Items[i];
				 vector<LAKEPARAM>::iterator itr = site_ptr->LakeParams.begin();
				 while (itr != site_ptr->LakeParams.end()) {
				   if (SameText(LakeParamName, (*itr).Name)) {
					 if (Value.IsEmpty())
					   site_ptr->LakeParams.erase(itr);
					 else
					   (*itr).Value = Value;
					 found = true;
					 break;
					 }
				   itr++;
				   }
				 if (!found) {
				   LAKEPARAM LakeParam;
				   LakeParam.Name = LakeParamName;
				   LakeParam.Value = Value;
				   site_ptr->LakeParams.push_back(LakeParam);
				   }
				 }
			   }
			 }
		   }
		 }
	   }
	 }
}
//---------------------------------------------------------------------------

int TTilSpreadSheetForm::FindRowMD(int Type)
{
   int Row = 0;
   if (HeaderRow2 == Type)
	 Row = 2;
   else {
	 switch (Type) {
	   case SITE_NAME:
		 Row = FindRowCodeIC(L"#Site.Name", ProfGrid1);
		 break;
	   case COLL_UNIT_NAME:
		 Row = FindRowCodeIC(L"#Coll.Name", ProfGrid1);
		 break;
	   case COLL_UNIT_HANDLE:
		 Row = FindRowCodeIC(L"#Coll.Handle", ProfGrid1);
		 break;
	   case ANAL_UNIT_NAME:
		 Row = FindRowCodeIC(L"#Anal.Name", ProfGrid1);
		 break;
	   }
	 }
   return Row;
}
//---------------------------------------------------------------------------


bool TTilSpreadSheetForm::DecodeSSMD(double& MDItem, Variant& Value)
{
   if (Value.IsEmpty()) {
	 MDItem = NaN;
	 return false;
	 }
   else {
	 MDItem = Value;
	 return true;
	 }
}
//---------------------------------------------------------------------------

bool TTilSpreadSheetForm::DecodeSSMD(Variant& MDItem, Variant& Value)
{
   if (Value.IsEmpty()) {
	 MDItem = Unassigned();
	 return false;
	 }
   else {
	 MDItem = Value;
	 return true;
	 }
}
//---------------------------------------------------------------------------

bool TTilSpreadSheetForm::DecodeSSMD(int& MDItem, Variant& Value)
{
   if (Value.IsEmpty()) {
	 MDItem = -1;
	 return false;
	 }
   else {
	 MDItem = Value;
	 return true;
	 }
}
//---------------------------------------------------------------------------

bool TTilSpreadSheetForm::DecodeSSMD(UnicodeString& MDItem, Variant& Value)
{
   if (Value.IsEmpty()) {
     MDItem = "";
     return false;
     }
   else {
     MDItem = Value;
     return true;
     }
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::DecodeSSContacts(vector<CONTACT*>& contact_ptrs, int ACol, int ARow)
{
   contact_ptrs.clear();

   TProfGridCell* ACell = ProfGrid1->Cells[ACol][ARow];
   if (ACell->CellObject != NULL) {
	 CELLOBJECT* CellObject = (CELLOBJECT*)ACell->CellObject;
	 TList* CellContacts = (TList*)CellObject->Object;
	 for (int i=0; i<CellContacts->Count; i++) {
	   CONTACT* Contact = (CONTACT*)CellContacts->Items[i];
	   contact_ptrs.push_back(Contact);
	   }
	 }
}
//---------------------------------------------------------------------------

int TTilSpreadSheetForm::FindSite(UnicodeString& SiteName)
{
   // interate through the Sites list
   for (int i=0; i<Sites->Count; i++) {
	 SITE* site_ptr = (SITE*)Sites->Items[i];
	 if (SameText(site_ptr->SiteName, SiteName))
	   return(i);
	 }
   return -1;
}
//---------------------------------------------------------------------------


int TTilSpreadSheetForm::GetMetaDataRows(UnicodeString MDType, map<UnicodeString, int>& MDRows, int start_row)
{
   int lastrow = 0;
   TProfGridColumn* CodeCol = ProfGrid1->AbsoluteCols[1];

   int end_row;
   if (start_row == 3 && ContainsText(Datasets[0].DatasetType, L"top-bottom"))
	 end_row = FindRowCodeIC(L"#Anal.Bottom", ProfGrid1) - 1;
   else
	 end_row = ContentRowCount(ProfGrid1);

   int lt = MDType.Length();

   for (int row=start_row; row<=end_row; row++) {
	 UnicodeString Code = CodeCol->Cells[row]->Value;
	 if (SameText(Code.SubString(1,lt), MDType)) {
	   Code.Delete(1,lt);
	   if (MDRows.find(Code.UpperCase()) == MDRows.end()) {
		 MDRows[Code.UpperCase()] = row;
		 lastrow = row;
		 }
	   }
	 }
   return lastrow;
}
//---------------------------------------------------------------------------

bool TTilSpreadSheetForm::MetaDataBounds(UnicodeString MDType, int& firstrow, int& lastrow)
{
   firstrow = 0;
   lastrow = 0;
   TProfGridColumn* CodeCol = ProfGrid1->AbsoluteCols[1];
   int RowCount = ContentRowCount(ProfGrid1);
   int lt = MDType.Length();

   for (int row=3; row<=RowCount; row++) {
	 UnicodeString Code = CodeCol->Cells[row]->Value;
	 if (SameText(Code.SubString(1,lt), MDType)) {
	   if (!firstrow) {
		 firstrow = row;
		 lastrow = row;
		 }
	   else
		 lastrow = row;
	   }
	 }
   return (firstrow > 0);
}
//---------------------------------------------------------------------------

// transfers collection unit metadata to spreadsheet
void TTilSpreadSheetForm::CollUnitMetaDataToSS(int ACol)
{
   int row;
   int lastrow;

   map<UnicodeString, int> MDRows;
   vector<int> CollUnitCols;
   int RowCount = ContentRowCount(ProfGrid1);

   // get all site metadata rows
   lastrow = GetMetaDataRows(L"#COLL.", MDRows);
   lastrow++;

   ProfGrid1->DisableControls();
   ProfGrid1->SpreadsheetEnabled = false;

   row = 0;
   if (MDRows.find(L"HANDLE") != MDRows.end())
	 row = MDRows[L"HANDLE"];

   if (row > 0) {
	 UnicodeString Handle = ProfGrid1->AbsoluteCells[ACol][row]->Text;
	 // get all columns with the same old site name, and potentially replace with new name
	 int StartCol = AbsHeaderColCount(ProfGrid1);
	 int EndCol = AbsContentColCount(ProfGrid1);
	 for (int col=StartCol; col<=EndCol; col++) {
	   TProfGridCell *ACell = ProfGrid1->AbsoluteCells[col][row];
	   if (SameText(Handle, ACell->Text)) {
		 CollUnitCols.push_back(col);
		 }
	   }
	 }
   else
	 return;    // this should never happen, but is a precaution

   UpdateSSMD(L"TYPE", L"#Coll.Type", L"Collection Unit Type",
			  CollPtr->CollectionType, lastrow, RowCount, CollUnitCols, MDRows);
   UpdateSSMD(L"DEVICE", L"#Coll.Device", L"Collection Device",
			  CollPtr->CollectionDevice, lastrow, RowCount, CollUnitCols, MDRows);
   UpdateSSMD(L"DATE", L"#Coll.Date", L"Date Collected",
			  CollPtr->CollDate, lastrow, RowCount, CollUnitCols, MDRows);
   UpdateSSMD(L"LOC", L"#Coll.Loc", L"Location in Site",
			  CollPtr->Location, lastrow, RowCount, CollUnitCols, MDRows);
   UpdateSSMD(L"GPSLAT", L"#Coll.GPSLat", L"GPS Latitude",
			  CollPtr->GPSLat, lastrow, RowCount, CollUnitCols, MDRows);
   UpdateSSMD(L"GPSLONG", L"#Coll.GPSLong", L"GPS Longitude",
			  CollPtr->GPSLong, lastrow, RowCount, CollUnitCols, MDRows);
   UpdateSSMD(L"GPSERR", L"#Coll.GPSErr", L"GPS Error",
			  CollPtr->GPSError, lastrow, RowCount, CollUnitCols, MDRows);
   UpdateSSMD(L"GPSALT", L"#Coll.GPSAlt", L"GPS Altitude",
			  CollPtr->GPSAltitude, lastrow, RowCount, CollUnitCols, MDRows);
   UpdateSSMD(L"DEPENV", L"#Coll.DepEnv", L"Depositional Environment",
			  CollPtr->DepEnv, lastrow, RowCount, CollUnitCols, MDRows);
   UpdateSSMD(L"SUBSTRATE", L"#Coll.Substrate", L"Substrate",
			  CollPtr->Substrate, lastrow, RowCount, CollUnitCols, MDRows);
   UpdateSSMD(L"ANGLE", L"#Coll.Angle", L"Slope Angle",
			  CollPtr->SlopeAngle, lastrow, RowCount, CollUnitCols, MDRows);
   UpdateSSMD(L"ASPECT", L"#Coll.Aspect", L"Slope Aspect",
			  CollPtr->SlopeAspect, lastrow, RowCount, CollUnitCols, MDRows);
   UpdateSSMD(L"WATERDEP", L"#Coll.WaterDep", L"Water Depth",
			  CollPtr->WaterDepth, lastrow, RowCount, CollUnitCols, MDRows);
   UpdateSSMD(L"NOTES", L"#Coll.Notes", L"Collection Unit Notes",
			  CollPtr->Notes, lastrow, RowCount, CollUnitCols, MDRows);
   UnicodeString contacts = cxCheckComboBox1->Text;
   UpdateSSMD(L"CONTACTS", L"#Coll.Contacts", L"Collectors",
			  contacts, lastrow, RowCount, CollUnitCols, MDRows);

   if (MDRows.find(L"CONTACTS") != MDRows.end()) {
	 int row = MDRows[L"CONTACTS"];
	 int nCols = CollUnitCols.size();
	 for (int i=0; i<nCols; i++) {
	   TProfGridCell *ACell = ProfGrid1->AbsoluteCells[CollUnitCols[i]][row];
	   ACell->Value = contacts;
	   TList* Contacts;
	   if (ACell->CellObject) {
		 CELLOBJECT* CellObject = (CELLOBJECT*)ACell->CellObject;
		 Contacts = (TList*)CellObject->Object;
		 Contacts->Clear();
		 }
	   else {
		 CELLOBJECT* CellObject = new CELLOBJECT(CELLCONTACTS);
		 AddCellObject(ACell, CellObject);
		 }
	   for (unsigned int i = 0; i < CollPtr->Collectors.size(); i++)
		 Contacts->Add(CollPtr->Collectors[i]);
	   }
	 }

   ProfGrid1->SpreadsheetEnabled = true;
   ProfGrid1->EnableControls();
}
//---------------------------------------------------------------------------

// transfers site metadata to spreadsheet
void TTilSpreadSheetForm::SiteMetaDataToSS(int ACol)
{
   int row;
   int lastrow;
   TProfGridCell *ACell;

   map<UnicodeString, int> MDRows;
   vector<int> SiteCols;
   int RowCount = ContentRowCount(ProfGrid1);

   // get all site metadata rows
   lastrow = GetMetaDataRows(L"#SITE.", MDRows);
   lastrow++;

   ProfGrid1->DisableControls();
   ProfGrid1->SpreadsheetEnabled = false;

   row = 0;
   if (HeaderRow2 == SITE_NAME)
	 row = 2;
   else if (MDRows.find(L"NAME") != MDRows.end())
	 row = MDRows[L"NAME"];

   if (row > 0) {
	 // get all columns with the same old site name, and potentially replace with new name
	 SiteCols.push_back(ACol);
	 }
   else  {
	 ProfGrid1->SpreadsheetEnabled = true;
	 ProfGrid1->EnableControls();
	 return;    // this should never happen, but is a precaution
	 }

   UpdateSSMD(L"LATN", L"#Site.LatN", L"North Latitude",
			  SitePtr->LatNorth, lastrow, RowCount, SiteCols, MDRows);
   UpdateSSMD(L"LATS", L"#Site.LatS", L"South Latitude",
			  SitePtr->LatSouth, lastrow, RowCount, SiteCols, MDRows);
   UpdateSSMD(L"LONGW", L"#Site.LongW", L"West Longitude",
			  SitePtr->LongWest, lastrow, RowCount, SiteCols, MDRows);
   UpdateSSMD(L"LONGE", L"#Site.LongE", L"East Longitude",
			  SitePtr->LongEast, lastrow, RowCount, SiteCols, MDRows);
   UpdateSSMD(L"GEOPOL1", L"#Site.GeoPol1", L"First Geopolitical Division",
			  SitePtr->Country, lastrow, RowCount, SiteCols, MDRows);
   UpdateSSMD(L"GEOPOL2", L"#Site.GeoPol2", L"Second Geopolitical Division",
			  SitePtr->State, lastrow, RowCount, SiteCols, MDRows);
   UpdateSSMD(L"GEOPOL3", L"#Site.GeoPol3", L"Third Geopolitical Division",
			  SitePtr->County, lastrow, RowCount, SiteCols, MDRows);
   UpdateSSMD(L"ADMIN", L"#Site.Admin", L"Administrative Unit",
			  SitePtr->AdminUnit, lastrow, RowCount, SiteCols, MDRows);
   UpdateSSMD(L"ALTITUDE", L"#Site.Altitude", L"Altitude (m)",
			  SitePtr->Altitude, lastrow, RowCount, SiteCols, MDRows);
   UpdateSSMD(L"AREA", L"#Site.Area", L"Area of Site (ha)",
			  SitePtr->Area, lastrow, RowCount, SiteCols, MDRows);
   UpdateSSMD(L"DESC", L"#Site.Description", L"Site Description",
			  SitePtr->SiteDescription, lastrow, RowCount, SiteCols, MDRows);
   UpdateSSMD(L"NOTES", L"#Site.Notes", L"Site Notes",
			  SitePtr->Notes, lastrow, RowCount, SiteCols, MDRows);

   // get all site metadata rows
   MDRows.clear();
   lastrow = GetMetaDataRows(L"#LAKE.", MDRows);
   lastrow++;

   UnicodeString LakeParamName;
   UnicodeString LakeParamCode;
   vector<LAKEPARAM>::iterator itr = SitePtr->LakeParams.begin();
   while (itr != SitePtr->LakeParams.end()) {
	 list<LAKEPARAMETER>::iterator lp_itr = LakeChar.begin();
	 LakeParamName = itr->Name;
	 bool found = false;
	 while (lp_itr != LakeChar.end()) {
	   if (SameText(LakeParamName, lp_itr->Name)) {
		 LakeParamCode = lp_itr->Code;
		 found = true;
		 break;
		 }
	   lp_itr++;
	   }
	 if (found) UpdateSSMD(LakeParamCode.UpperCase(), L"#Lake."+LakeParamCode,
				LakeParamName, itr->Value, lastrow, RowCount, SiteCols, MDRows);
	 itr++;
	 }

   ProfGrid1->SpreadsheetEnabled = true;
   ProfGrid1->EnableControls();
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::UpdateSSMD(UnicodeString MDItem, UnicodeString MDCode,
	  UnicodeString MDName, double& MDValue, int& lastrow, int& RowCount,
	  vector<int>& UpdateCols, map<UnicodeString, int>& MDRows)
{
   int nCols = UpdateCols.size();
   if (MDRows.find(MDItem.UpperCase()) != MDRows.end()) {
	 int row = MDRows[MDItem.UpperCase()];
	 for (int i=0; i<nCols; i++) {
	   TProfGridCell *ACell = ProfGrid1->AbsoluteCells[UpdateCols[i]][row];
	   if (IsNan(MDValue))
		 ACell->Value = Unassigned();
	   else
		 ACell->Value = MDValue;
	   }
	 }
   else if (!IsNan(MDValue)) {  // item set in metadata, but no row in SS
	 if (lastrow <= RowCount) {
	   ProfGrid1->InsertRow(lastrow);
	   RowCount++;
	   }
	 MDRows[MDItem] = lastrow;
	 ProfGrid1->AbsoluteCells[1][lastrow]->Value = MDCode;
	 ProfGrid1->AbsoluteCells[2][lastrow]->Value = MDName;
	 for (int i=0; i<nCols; i++) {
	   TProfGridCell *ACell = ProfGrid1->AbsoluteCells[UpdateCols[i]][lastrow];
	   ACell->Value = MDValue;
	   }
	 lastrow++;
	 }
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::UpdateSSMD(UnicodeString MDItem, UnicodeString MDCode,
	  UnicodeString MDName, UnicodeString& MDValue, int& lastrow, int& RowCount,
	  vector<int>& UpdateCols, map<UnicodeString, int>& MDRows)
{
   int nCols = UpdateCols.size();
   if (MDRows.find(MDItem.UpperCase()) != MDRows.end()) {
	 int row = MDRows[MDItem.UpperCase()];
	 for (int i=0; i<nCols; i++) {
	   TProfGridCell *ACell = ProfGrid1->AbsoluteCells[UpdateCols[i]][row];
	   ACell->Value = MDValue;
	   }
	 }
   else if (!MDValue.IsEmpty()) {  // item set in metadata, but no row in SS
	 if (lastrow <= RowCount) {
	   ProfGrid1->InsertRow(lastrow);
	   RowCount++;
	   }
	 MDRows[MDItem] = lastrow;
	 ProfGrid1->AbsoluteCells[1][lastrow]->Value = MDCode;
	 ProfGrid1->AbsoluteCells[2][lastrow]->Value = MDName;
	 for (int i=0; i<nCols; i++) {
	   TProfGridCell *ACell = ProfGrid1->AbsoluteCells[UpdateCols[i]][lastrow];
	   ACell->Value = MDValue;
	   }
	 lastrow++;
	 }
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::UpdateSSMD(UnicodeString MDItem, UnicodeString MDCode,
	  UnicodeString MDName, Variant& MDValue, int& lastrow, int& RowCount,
	  vector<int>& UpdateCols, map<UnicodeString, int>& MDRows)
{
   int nCols = UpdateCols.size();
   if (MDRows.find(MDItem.UpperCase()) != MDRows.end()) {
	 int row = MDRows[MDItem.UpperCase()];
	 for (int i=0; i<nCols; i++) {
	   TProfGridCell *ACell = ProfGrid1->AbsoluteCells[UpdateCols[i]][row];
	   ACell->Value = MDValue;
	   }
	 }
   else if (!MDValue.IsEmpty()) {  // item set in metadata, but no row in SS
	 if (lastrow <= RowCount) {
	   ProfGrid1->InsertRow(lastrow);
	   RowCount++;
	   }
	 MDRows[MDItem] = lastrow;
	 ProfGrid1->AbsoluteCells[1][lastrow]->Value = MDCode;
	 ProfGrid1->AbsoluteCells[2][lastrow]->Value = MDName;
	 for (int i=0; i<nCols; i++) {
	   TProfGridCell *ACell = ProfGrid1->AbsoluteCells[UpdateCols[i]][lastrow];
	   ACell->Value = MDValue;
	   }
	 lastrow++;
	 }
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::GetSSMetaDataItems(UnicodeString ItemType, TStringList* MDItems)
{
   int len = ItemType.Length();
   MDItems->Sorted = true;
   int RowCount = ContentRowCount(ProfGrid1);
   TProfGridColumn* CodeCol = ProfGrid1->AbsoluteCols[1];
   for (int row=3; row<=RowCount; row++) {
     UnicodeString Code = CodeCol->Cells[row]->Value;
	 //Code = Code.UpperCase();
	 if (SameText(Code.SubString(1,len), ItemType))
	   MDItems->Add(Code.Delete(1,len));
	 }
}
//---------------------------------------------------------------------------

