//---------------------------------------------------------------------------

#include <vcl.h>
#include "pch.h"
#pragma hdrstop

#include "TIMetDat.h"
#ifndef TISpreadH
#include "TISpread.h"
#endif
#ifndef TICommonH
#include "TICommon.h"
#endif

//---------------------------------------------------------------------------

#pragma package(smart_init)

// processes metadata item after entered into a spreadsheet cell
void TTilSpreadSheetForm::EnterSSMetaData(UnicodeString& Code, Variant& Value, int ACol, int ARow)
{
   int SiteRow, CollRow;
   TProfGridCell *CurCell = ProfGrid1->Cells[ACol][ARow];
   int StartCol = AbsHeaderColCount(ProfGrid1);
   int EndCol = AbsContentColCount(ProfGrid1);
   int CurCol = CurCell->AbsoluteCol;
   SITE* site_ptr;
   SITE* col_site_ptr;

   if (SameText(Code.SubString(1,6), L"#SITE.") || SameText(Code.SubString(1,6), L"#LAKE.")) {
	 if (SameText(Code, L"#SITE.NAME"))
	   EnterSSSite(Value, ACol, ARow);
	 else {     // #Site metadata besides #Site.Name
	   if ((site_ptr = GetSSSitePtr(ACol, SiteRow)) == NULL) {
		 Value = Unassigned();
		 return;
		 }

	   if (SameText(Code.SubString(1,6), L"#SITE.")) {
		 Code.Delete(1,6);
		 if (SameText(Code, L"LATN"))
		   DecodeSSMD(site_ptr->LatNorth, Value);
		 else if (SameText(Code, L"LATS"))
		   DecodeSSMD(site_ptr->LatSouth, Value);
		 else if (SameText(Code, L"LONGW"))
		   DecodeSSMD(site_ptr->LongWest, Value);
		 else if (SameText(Code, L"LONGE"))
		   DecodeSSMD(site_ptr->LongEast, Value);
		 else if (SameText(Code, L"ALTITUDE"))
		   DecodeSSMD(site_ptr->Altitude, Value);
		 else if (SameText(Code, L"AREA"))
		   DecodeSSMD(site_ptr->Area, Value);
		 else if (SameText(Code, L"GEOPOL1")) {
		   if (DecodeSSMD(site_ptr->Country, Value)) {
			 GeoPolUnits->SetGeoPolRec1(site_ptr->Country);
			 int row1 = FindRowCodeIC(L"#SITE.GEOPOL2", ProfGrid1);
			 if (row1)
			   ProfGrid1->Cells[ACol][row1]->Value = Unassigned();
			 row1 = FindRowCodeIC(L"#SITE.GEOPOL3", ProfGrid1);
			 if (row1)
			   ProfGrid1->Cells[ACol][row1]->Value = Unassigned();
			 }
		   }
		 else if (SameText(Code, L"GEOPOL2")) {
		   if (DecodeSSMD(site_ptr->State, Value)) {
			 if (GeoPolUnits->SetGeoPol2())
			   GeoPolUnits->SetGeoPolRec2(site_ptr->State);
			 int row1 = FindRowCodeIC(L"#SITE.GEOPOL3", ProfGrid1);
			 if (row1)
			   ProfGrid1->Cells[ACol][row1]->Value = Unassigned();
			 }
		   }
		 else if (SameText(Code, L"GEOPOL3")) {
		   if (!site_ptr->Country.IsEmpty() && !site_ptr->State.IsEmpty()) {
			 GeoPolUnits->SetGeoPolRec1(site_ptr->Country);
			 if (GeoPolUnits->SetGeoPol2()) {
			   GeoPolUnits->SetGeoPolRec2(site_ptr->State);
			   GeoPolUnits->SetGeoPol3();
			   }
			 DecodeSSMD(site_ptr->County, Value);
			 }
		   }
		 else if (SameText(Code, L"ADMIN")) {
		   DecodeSSMD(site_ptr->AdminUnit, Value);
		   }
		 else if (SameText(Code, L"NOTES")) {
		   DecodeSSMD(site_ptr->Notes, Value);
		   ProfGrid1->RowHeights[ARow] = CurrentRowHeight;
		   }
		 else if (SameText(Code, L"DESC")) {
		   DecodeSSMD(site_ptr->SiteDescription, Value);
		   ProfGrid1->RowHeights[ARow] = CurrentRowHeight;
		   }
		 }
	   else if (SameText(Code.SubString(1,6), L"#LAKE.")) {
		 Code.Delete(1,6);
		 WideString LakeParamName;
		 list<LAKEPARAMETER>::iterator lp_itr = LakeChar.begin();
		 // get LakeParamName that matches code
		 while (lp_itr != LakeChar.end()) {
		   UnicodeString LakeParamCode = lp_itr->Code;
		   if (SameText(Code, LakeParamCode)) {
			 LakeParamName = lp_itr->Name;
			 break;
			 }
		   lp_itr++;
		   }
		 // fill SSite->LakeParams
		 bool found = false;
		 vector<LAKEPARAM>::iterator itr = site_ptr->LakeParams.begin();
		 while (itr != site_ptr->LakeParams.end()) {
		   if (SameText(LakeParamName, itr->Name)) {
			 if (Value.IsEmpty())
			   site_ptr->LakeParams.erase(itr);
			 else
			   itr->Value = Value;
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
	   // add metadata value to all other columns with this site
	   int Col = StartCol;
	   while ((col_site_ptr = GetNextColSitePtr(CurCol, Col, EndCol, SiteRow)) != NULL) {
		 if (col_site_ptr == site_ptr)
		   ProfGrid1->AbsoluteCells[Col][ARow]->Value = Value;
		 Col++;
		 }
	   }
	 }
   else if (SameText(Code.SubString(1,6), L"#COLL.")) {
	 Code.Delete(1,6);
	 if (SameText(Code, L"NAME"))
	   EnterSSCollUnit(Value, ACol, ARow);
	 else if ((CollRow = FindRowMD(COLL_UNIT_NAME)) > 0) {
	   if ((site_ptr = GetSSSitePtr(ACol, SiteRow)) == NULL)
		 site_ptr = (SITE*)Sites->Items[0];
	   vector<COLLECTION>::pointer coll_ptr = NULL;
	   UnicodeString CollName = ProfGrid1->Cells[ACol][CollRow]->Text;
	   for (unsigned int i=1; i<site_ptr->CollUnits.size(); i++) {
		 if (SameText(CollName, site_ptr->CollUnits[i].CollectionName)) {
		   coll_ptr = &site_ptr->CollUnits[i];
		   break;
		   }
		 }
	   if (coll_ptr == NULL) {
		 if (SameText(Code, L"HANDLE")) {  // Handle can be entered with no Coll.Name yet
		   // Check if Coll.Name assigned to any other column with this handle.
		   // If so, assign to this handle.
		   UnicodeString Handle = Value;
		   int Col = StartCol;
		   while ((col_site_ptr = GetNextColSitePtr(CurCol, Col, EndCol, SiteRow)) != NULL) {
			 if (col_site_ptr == site_ptr) {
			   Variant CollValue = ProfGrid1->AbsoluteCells[Col][CollRow]->Value;
			   UnicodeString CollName = CollValue;
			   UnicodeString CurHandle = ProfGrid1->AbsoluteCells[Col][ARow]->Text;
			   if (SameText(Handle, CurHandle) && !CollName.IsEmpty()) {
				 ProfGrid1->Cells[ACol][CollRow]->Value = CollValue;
				 EnterSSCollUnit(CollValue, ACol, CollRow);
				 break;
				 }
			   }
			 Col++;
			 }
		   }
		 else {
		   UnicodeString msg;
		   if (CollName.IsEmpty()) {
			 msg = L"Collection Unit name not yet entered.";
			 }
		   else
			 msg = L"Collection Unit \"" + CollName + L"\" not assigned to Site \"" + site_ptr->SiteName +L"\".";
		   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   Value = Unassigned();
		   }
		 return;
		 }

	   if (SameText(Code, L"HANDLE"))
		 DecodeSSMD(coll_ptr->Handle, Value);
	   else if (SameText(Code, L"TYPE"))
		 DecodeSSMD(coll_ptr->CollectionType, Value);
	   else if (SameText(Code, L"DEVICE"))
		 DecodeSSMD(coll_ptr->CollectionDevice, Value);
	   else if (SameText(Code, L"DATE"))
		 DecodeSSMD(coll_ptr->CollDate, Value);
	   else if (SameText(Code, L"LOC"))
		 DecodeSSMD(coll_ptr->Location, Value);
	   else if (SameText(Code, L"GPSLAT"))
		 DecodeSSMD(coll_ptr->GPSLat, Value);
	   else if (SameText(Code, L"GPSLONG"))
		 DecodeSSMD(coll_ptr->GPSLong, Value);
	   else if (SameText(Code, L"GPSERR"))
		 DecodeSSMD(coll_ptr->GPSError, Value);
	   else if (SameText(Code, L"GPSALT"))
		 DecodeSSMD(coll_ptr->GPSAltitude, Value);
	   else if (SameText(Code, L"DEPENV"))
		 DecodeSSMD(coll_ptr->DepEnv, Value);
	   else if (SameText(Code, L"SUBSTRATE"))
		 DecodeSSMD(coll_ptr->Substrate, Value);
	   else if (SameText(Code, L"ANGLE"))
		 DecodeSSMD(coll_ptr->SlopeAngle, Value);
	   else if (SameText(Code, L"ASPECT"))
		 DecodeSSMD(coll_ptr->SlopeAspect, Value);
	   else if (SameText(Code, L"WATERDEP"))
		 DecodeSSMD(coll_ptr->WaterDepth, Value);
	   else if (SameText(Code, L"NOTES"))
		 DecodeSSMD(coll_ptr->Notes, Value);
	   else if (SameText(Code, L"CONTACTS")) {
		 ProfGrid1->RowHeights[ARow] = CurrentRowHeight;
		 DecodeSSContacts(coll_ptr->Collectors, ACol, ARow);
		 }

	   // add metadata value to all other columns for this collection unit
	   int Col = StartCol;
	   CELLOBJECT* CellObject = (CELLOBJECT*)CurCell->CellObject;
	   while ((col_site_ptr = GetNextColSitePtr(CurCol, Col, EndCol, SiteRow)) != NULL) {
		 if (col_site_ptr == site_ptr) {
		   UnicodeString NextCollName = ProfGrid1->AbsoluteCells[Col][CollRow]->Text;
		   if (SameText(NextCollName, CollName)) {
			 ProfGrid1->AbsoluteCells[Col][ARow]->Value = Value;
			 CELLOBJECT* NewCellObject = new CELLOBJECT(CellObject);
			 AddCellObject(CurCell, NewCellObject);
			 }
		   }
		 Col++;
		 }
	   }
	 }
   else if (SameText(Code, L"#Samp.Analyst")) {
	 ProfGrid1->RowHeights[ARow] = CurrentRowHeight;
	 }
   else if (SameText(Code, L"#SAMP.KEYWORDS")) {
	 UnicodeString KeywordsText = cxCheckComboBox4->Text;
	 ProfGrid1->Cells[ACol][ARow]->Value = KeywordsText;
	 ProfGrid1->RowHeights[ARow] = CurrentRowHeight;
	 if (CurCol == GetColMinDepth()) {
	   if (KeywordsText.IsEmpty())
		 Datasets[DatasetNum].IsSSamp = false;
	   else {
		 set<UnicodeString> Keywords;
		 ParsePartsIC(cxCheckComboBox4->Text, L";", Keywords);
		 Datasets[DatasetNum].IsSSamp = (Keywords.count(L"modern") > 0);
		 }
	   }
	 }
}
//---------------------------------------------------------------------------

TList* TTilSpreadSheetForm::InitCellContactsList(TProfGridCell* ACell)
{
   CELLOBJECT* CellObject;
   if (ACell->CellObject != NULL)
	 CellObject = (CELLOBJECT*)ACell->CellObject;
   else {
	 CellObject = new CELLOBJECT(CELLCONTACTS);
	 AddCellObject(ACell, CellObject);
	 }
   TList* CellContacts = (TList*)CellObject->Object;
   CellContacts->Clear();
   return CellContacts;
}
//---------------------------------------------------------------------------

bool TTilSpreadSheetForm::EnterSSCollUnit(Variant& Value, int ACol, int ARow)
{
   int SiteRow, CollRow;
   TProfGridCell *CurCell = ProfGrid1->Cells[ACol][ARow];
   int StartCol = AbsHeaderColCount(ProfGrid1);
   int EndCol = AbsContentColCount(ProfGrid1);
   int CurCol = CurCell->AbsoluteCol;
   SITE* site_ptr;
   SITE* col_site_ptr;

   if ((site_ptr = GetSSSitePtr(ACol, SiteRow)) == NULL)
	 site_ptr = (SITE*)Sites->Items[0];

   if (HeaderRow2 == COLL_UNIT_NAME)
	 CollRow = 2;
   else
	 CollRow = ARow;

   //UnicodeString OldCollName = UnDo.back().Cells.front().Value;
   UnicodeString OldCollName = InitialCollName;
   UnicodeString NewCollName = Value;

   // deal with deleted collection unit name
   if (NewCollName.IsEmpty()) {
	 if (!OldCollName.IsEmpty())
	   DeleteSSCollName(Value, site_ptr, CurCell, OldCollName, SiteRow, ACol, CollRow, true);
	 return false;
	 }

   if (!OldCollName.IsEmpty()) {
	 if (NewCollName != OldCollName) {
	   // check if new NewCollName already exists for a different collection unit in same site
	   bool found = false;
	   int Col = StartCol;
	   while ((col_site_ptr = GetNextColSitePtr(CurCol, Col, EndCol, SiteRow)) != NULL) {
		 if (col_site_ptr == site_ptr) {
		   UnicodeString NextCollName = ProfGrid1->AbsoluteCells[Col][CollRow]->Text;
		   if (SameText(NewCollName, NextCollName)) {
			 found = true;
			 break;
			 }
		   }
		 Col++;
		 }

	   if (found) {
		 // new name already exists for a different collection unit, so delete old name,
		 // then add new name, which will create a new instance of that collection unit (or bail)
		 UnicodeString site_name = site_ptr->SiteName;
		 if (site_name.IsEmpty())
		   site_name = L"<Unnamed>";
		 UnicodeString msg = L"Collection Unit \"" + NewCollName +
		   L"\" already exists for Site \"" + site_name +
		   L"\".\nAny Collection Unit metadata in current column will be " +
		   L"\nreplaced with data from existing collection unit";
		 if (MessageDlg(msg, mtWarning, TMsgDlgButtons() << mbOK << mbCancel, 0) == mrOk) {
		   DeleteSSCollName(Value, site_ptr, CurCell, OldCollName, SiteRow, ACol, CollRow, false);
		   Value = NewCollName;
		   CurCell->Value = Value;
		   AddSSCollName(site_ptr, NewCollName, CurCell, SiteRow, CollRow);
		   }
		 else {
		   Value = OldCollName;
		   CurCell->Value = Value;
		   return false;
		   }
		 }
	   else {
		 // name does not exist for a different collection unit, so change name and
		 // change name for all other instances of that collection unit
		 for (unsigned int i=1; i<site_ptr->CollUnits.size(); i++) {
		   if (SameText(OldCollName, site_ptr->CollUnits[i].CollectionName)) {
			 site_ptr->CollUnits[i].CollectionName = NewCollName;
			 break;
			 }
		   }
		 bool query = true;
		 Col = StartCol;
		 while ((col_site_ptr = GetNextColSitePtr(CurCol, Col, EndCol, SiteRow)) != NULL) {
		   if (col_site_ptr == site_ptr) {
			 TProfGridCell* ACell = ProfGrid1->AbsoluteCells[Col][CollRow];
			 UnicodeString NextCollName = ACell->Text;
			 if (SameText(OldCollName, NextCollName)) {
			   if (query) {
				 UnicodeString site_name = site_ptr->SiteName;
				 if (site_name.IsEmpty())
				   site_name = L"<Unnamed>";
				 UnicodeString msg = L"Other columns for Collection Unit \"" +
				   OldCollName + L"\" also exist for Site \"" + site_name +
				   L"\".\nChange Collection Unit name in these other columns to \"" +
				   NewCollName + "\" as well?" +
				   L"\n\nNote: The names of any Collection Units with the same Handle will always be changed.";
				 int rv = MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo << mbCancel, 0);
				 if (rv == mrNo) {
				   // this is a new Collection Unit rather than name change, so add to site
				   AddSSCollName(site_ptr, NewCollName, CurCell, SiteRow, CollRow);
				   break;
				   }
				 else if (rv == mrCancel) {
				   Value = OldCollName;
				   CurCell->Value = Value;
				   return false;
				   }
				 query = false;
				 }
			   ACell->Value = NewCollName;
			   }
			 }
		   Col++;
		   }
		 }
	   }
	 }
   else {  // OldCollName is empty, so add NewCollName
	 AddSSCollName(site_ptr, NewCollName, CurCell, SiteRow, CollRow);
	 }
   return true;
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::AddSSCollName(SITE* site_ptr, UnicodeString NewCollName,
	   TProfGridCell* CurCell, int SiteRow, int CollRow)
{
   int StartCol = AbsHeaderColCount(ProfGrid1);
   int EndCol = AbsContentColCount(ProfGrid1);
   int CurCol = CurCell->AbsoluteCol;

   // check if NewCollName already exists for site
   bool found = false;
   SITE* col_site_ptr;
   int Col = StartCol;
   while ((col_site_ptr = GetNextColSitePtr(CurCol, Col, EndCol, SiteRow)) != NULL) {
	 if (site_ptr == col_site_ptr) {
	   UnicodeString NextCollName = ProfGrid1->AbsoluteCells[Col][CollRow]->Text;
	   if (SameText(NextCollName, NewCollName)) {
		 found = true;
		 break;
		 }
	   }
	 Col++;
	 }

   if (found) {  // NewCollName already exists for site, so copy metadata items
	 map<UnicodeString, int> MDRows;
	 if (GetMetaDataRows(L"#COLL.", MDRows) > 0) {
	   map<UnicodeString, int>::iterator itr;
	   for (itr = MDRows.begin(); itr != MDRows.end(); itr++) {
		 if (itr->second != CollRow) {
		   ProfGrid1->AbsoluteCells[CurCol][itr->second]->Value =
		   ProfGrid1->AbsoluteCells[Col][itr->second]->Value;
		   }
		 }
	   }
	 }
   else {  // NewCollName is a new collection unit for site
	 COLLECTION CollUnit;
	 CollUnit.CollectionName = NewCollName;

	 // check if handle has already been entered for this collection unit
	 UnicodeString Handle;
	 int HandleRow = FindRowMD(COLL_UNIT_HANDLE);
	 if (HandleRow > 0) {
	   Handle = ProfGrid1->AbsoluteCells[CurCol][HandleRow]->Text;
	   if (!Handle.IsEmpty()) {
		 CollUnit.Handle = Handle;
		 // If Handle not empty, assign CollUnit to any columns with blank Name and same Handle
		 int Col = StartCol;
		 while ((col_site_ptr = GetNextColSitePtr(CurCol, Col, EndCol, SiteRow)) != NULL) {
		   if (site_ptr == col_site_ptr) {
			 UnicodeString ColHandle = ProfGrid1->AbsoluteCells[Col][HandleRow]->Text;
			 if (SameText(Handle, ColHandle))
			   ProfGrid1->AbsoluteCells[Col][CollRow]->Value = NewCollName;
			 }
		   Col++;
		   }
		 }
	   }

	 site_ptr->CollUnits.push_back(CollUnit);
	 }
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::DeleteSSCollName(Variant& Value, SITE* site_ptr,
  TProfGridCell *CurCell, UnicodeString OldCollName, int SiteRow, int ACol,
  int CollRow, bool Query)
{
   int StartCol = AbsHeaderColCount(ProfGrid1);
   int EndCol = AbsContentColCount(ProfGrid1);
   int CurCol = CurCell->AbsoluteCol;

   UnicodeString msg = L"Deleting Collection Unit name will delete all associated metadata.";
   int rv;
   if (!Query || MessageDlg(msg, mtWarning, TMsgDlgButtons() << mbOK << mbCancel, 0) == mrOk) {
	 // delete all collection unit metadata items in column
	 if (HeaderRow2 == COLL_UNIT_NAME || HeaderRow2 == COLL_UNIT_HANDLE)
	   ProfGrid1->Cells[ACol][2]->Value = Unassigned();
	 int RowCount = ContentRowCount(ProfGrid1);
	 TProfGridColumn* CodeCol = ProfGrid1->AbsoluteCols[1];
	 for (int row=3; row<=RowCount; row++) {
	   UnicodeString Code = CodeCol->AbsoluteCells[row]->Value;
	   Code = Code.UpperCase();
	   if (SameText(Code.SubString(1,6), L"#COLL."))
		 ProfGrid1->Cells[ACol][row]->Value = Unassigned();
	   }
	 // if last occurrence of this collection unit, then delete from site_ptr
	 bool found = false;
	 int Col = StartCol;
	 SITE* col_site_ptr;
	 while ((col_site_ptr = GetNextColSitePtr(CurCol, Col, EndCol, SiteRow)) != NULL) {
	   if (col_site_ptr == site_ptr) {
		 UnicodeString CurCollName = ProfGrid1->AbsoluteCells[Col][CollRow]->Text;
		 if (SameText(OldCollName, CurCollName)) {
		   found = true;
		   break;
		   }
		 }
	   Col++;
	   }
	 if (!found) {
	   vector<COLLECTION>::iterator itr;
	   vector<COLLECTION>::iterator begin = site_ptr->CollUnits.begin();
	   vector<COLLECTION>::iterator end = site_ptr->CollUnits.end();
	   for (itr=begin; itr != end; itr++) {
		 if (SameText(OldCollName, itr->CollectionName)) {
		   site_ptr->CollUnits.erase(itr);
		   break;
		   }
		 }
	   }
	 }
   else {  // cancel deletion of CollName
	 Value = OldCollName;
	 CurCell->Value = Value;
	 }
}
//---------------------------------------------------------------------------

bool TTilSpreadSheetForm::EnterSSSite(Variant& Value, int ACol, int ARow, bool Query)
{
   SITE* site_ptr;
   SITE* col_site_ptr;
   TProfGridCell *CurCell = ProfGrid1->Cells[ACol][ARow];
   int StartCol = AbsHeaderColCount(ProfGrid1);
   int EndCol = AbsContentColCount(ProfGrid1);
   int CurCol = CurCell->AbsoluteCol;

   UnicodeString NewSiteName = Value;
   int SiteRow = ARow;

   // TODO: also warn about not being able to undo?
   // If new SiteName is empty, check if site name has been deleted, in which
   // case delete site instance, otherwise simply return.
   if (NewSiteName.IsEmpty()) {
	 if (CurCell->CellObject != NULL) {
	   CELLOBJECT* CellObject = (CELLOBJECT*)CurCell->CellObject;
	   //if (CellObjects[CurCell->CellObject] == CELLSITE)
	   if (CellObject->ObjectType == CELLSITE)
		 DeleteSSSiteName(Value, CurCell, ACol, ARow, true);
	   }
	 return false;
	 }

   // If site_ptr already exists for column, check to see if name
   // has been changed, and if so check if new name already exists in another column.
   if (CurCell->CellObject != NULL) {
	 CELLOBJECT* CellObject = (CELLOBJECT*)CurCell->CellObject;
	 if (CellObject->ObjectType == CELLSITE) {
	   site_ptr = (SITE*)CellObject->Object;
	   if (site_ptr->SiteName != NewSiteName) {  // name has been changed
		 // check if new site name already exists for a different SitePtr
		 bool SameName = false;
		 int Col = StartCol;
		 while ((col_site_ptr = GetNextColSitePtr(CurCol, Col, EndCol, SiteRow)) != NULL) {
		   if (col_site_ptr != site_ptr) {
			 if (SameText(NewSiteName, col_site_ptr->SiteName)) {
			   SameName = true;
			   break;
			   }
			 }
		   Col++;
		   }

		 if (SameName) {
		   // new name already exists for a different site, so delete old name,
		   // then add new name, which will create a new instance of that site_ptr (or bale)
		   UnicodeString msg = L"Site name is being changed to a name that already exists in another column.";
		   msg += L"\nAny site metadata in current column will be replaced with data from other column.";
		   if (MessageDlg(msg, mtWarning, TMsgDlgButtons() << mbOK << mbCancel, 0) == mrOk) {
			 DeleteSSSiteName(Value, CurCell, ACol, ARow, false);
			 Value = NewSiteName;
			 CurCell->Value = Value;
			 AddSSSiteName(NewSiteName, CurCell, ARow);
			 }
		   else {
			 Value = site_ptr->SiteName;
			 CurCell->Value = Value;
			 return false;
			 }
		   }
		 else {
		   // name does not exist for a different site, so change name and
		   // change name for all other instances of that site_ptr
		   UnicodeString OldSiteName = site_ptr->SiteName;
		   site_ptr->SiteName = NewSiteName;
		   bool query = true;
		   Col = StartCol;
		   while ((col_site_ptr = GetNextColSitePtr(CurCol, Col, EndCol, SiteRow)) != NULL) {
			 if (col_site_ptr == site_ptr) {
			   if (query) {
				 UnicodeString msg = L"Other columns exist for site \"" +
				   OldSiteName + L"\".\nChange site name in these columns as well?";
				 if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrNo) {
				   AddSSSiteName(NewSiteName, CurCell, ARow);
				   break;
				   }
				 query = false;
				 }
			   TProfGridCell* ACell = ProfGrid1->AbsoluteCells[Col][SiteRow];
			   ACell->Value = NewSiteName;
			   }
			 Col++;
			 }
		   }
		 }
	   }
	 else
	   return false;
	 }
   else {   // a site_ptr does not exist yet for cell
	 AddSSSiteName(NewSiteName, CurCell, ARow);
	 }
   return true;
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::AddSSSiteName(UnicodeString NewSiteName, TProfGridCell *CurCell, int ARow)
{
   SITE* site_ptr = NULL;
   SITE* col_site_ptr;
   map<UnicodeString, int> MDRows;

   int AbsCol = CurCell->AbsoluteCol;
   int StartCol = AbsHeaderColCount(ProfGrid1);
   int EndCol = AbsContentColCount(ProfGrid1);
   int CurCol = CurCell->AbsoluteCol;
   int SiteRow = ARow;

   // if name already exists in Sites list, assign SitePtr to cell
   bool found = false;
   for (int i=1; i<Sites->Count; i++) {
	 site_ptr = (SITE*)Sites->Items[i];
	 if (SameText(NewSiteName, site_ptr->SiteName)) {
	   CELLOBJECT* CellObject = new CELLOBJECT(site_ptr);
	   AddCellObject(CurCell, CellObject);
	   found = true;
	   break;
	   }
	 }
   if (found) {    // name exists, fill out other metadata items
	 // find another column for this site
	 int SiteCol = 0;
	 int Col = StartCol;
	 while ((col_site_ptr = GetNextColSitePtr(CurCol, Col, EndCol, SiteRow)) != NULL) {
	   if (col_site_ptr == site_ptr) {
		 SiteCol = Col;
		 break;
		 }
	   Col++;
	   }
	 if (SiteCol > 0 && GetMetaDataRows(L"#SITE.", MDRows) > 0) {
	   map<UnicodeString, int>::iterator itr;
	   for (itr = MDRows.begin(); itr != MDRows.end(); itr++) {
		 if (itr->second != SiteRow) {
		   ProfGrid1->AbsoluteCells[AbsCol][itr->second]->Value =
		   ProfGrid1->AbsoluteCells[SiteCol][itr->second]->Value;
		   }
		 }
	   }
	 }
   else {	 // SiteName is new
	 site_ptr = new SITE();
	 site_ptr->SiteName = NewSiteName;
	 Sites->Add(site_ptr);
	 CELLOBJECT* CellObject = new CELLOBJECT(site_ptr);
	 AddCellObject(CurCell, CellObject);
	 }

   if (site_ptr) {   // should alwasys be true, but a precaution
	 // check if a collection unit already exists for column, if so assign to site
	 int CollRow;
	 if ((CollRow = FindRowMD(COLL_UNIT_NAME)) == 0)
	   return;

	 UnicodeString CollName = ProfGrid1->AbsoluteCells[AbsCol][CollRow]->Text;
	 if (CollName.IsEmpty()) {
	   // check if Coll.Name exists for any other column with same Handle
	   int HandleRow;
	   if ((HandleRow = FindRowMD(COLL_UNIT_HANDLE)) > 0) {
		 UnicodeString Handle = ProfGrid1->AbsoluteCells[AbsCol][HandleRow]->Text;
		 if (!Handle.IsEmpty()) {
		   UnicodeString ColHandle;
		   int Col = StartCol;
		   while ((col_site_ptr = GetNextColSitePtr(CurCol, Col, EndCol, SiteRow)) != NULL) {
			 if (col_site_ptr == site_ptr) {
			   ColHandle = ProfGrid1->AbsoluteCells[Col][HandleRow]->Text;
			   if (SameText(Handle, ColHandle)) {
				 CollName = ProfGrid1->AbsoluteCells[Col][CollRow]->Text;
				 ProfGrid1->AbsoluteCells[AbsCol][CollRow]->Value = CollName;
				 break;
				 }
			   }
			 Col++;
			 }
		   }
		 }
	   }

	 if (!CollName.IsEmpty())
	   AddSSCollName(site_ptr, CollName, CurCell, SiteRow, CollRow);
	 }
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::ResetSSMetadata(void)
{
   SITE *site_ptr;
   int SiteNameRow = FindRowMD(SITE_NAME);
   int CollNameRow = FindRowMD(COLL_UNIT_NAME);
   int StartCol = AbsHeaderColCount(ProfGrid1);
   int EndCol = AbsContentColCount(ProfGrid1);

   bool site_found = false;
   if (SiteNameRow > 0) {
	 for (int col=StartCol; col<=EndCol; col++) {
	   TProfGridCell* ACell = ProfGrid1->AbsoluteCells[col][SiteNameRow];
	   if (!ACell->Text.IsEmpty())
		 site_found = true;
	   if (ACell->CellObject != NULL) {
		 DeleteCellObject(ACell);
		 }
	   }
	 }

   if (site_found) {
	 for (int i=0; i<Sites->Count; i++) {
	   site_ptr = (SITE*)Sites->Items[i];
	   delete site_ptr;
	   Sites->Items[i] = 0;
	   }
	 Sites->Clear();
	 site_ptr = new SITE();
	 Sites->Add(site_ptr);

	 map<UnicodeString, int> SiteMDRows;
	 GetMetaDataRows(L"#SITE.", SiteMDRows);
	 map<UnicodeString, int> LakeMDRows;
	 GetMetaDataRows(L"#LAKE.", LakeMDRows);

	 for (int col=StartCol; col<=EndCol; col++) {
	   int ACol = col - ProfGrid1->HiddenColCount;
	   TProfGridCell* ACell = ProfGrid1->AbsoluteCells[col][SiteNameRow];
	   if (!ACell->Text.IsEmpty()) {
		 bool found = false;
		 for (int i=1; i<Sites->Count; i++) {
		   site_ptr = (SITE*)Sites->Items[i];
		   if (SameText(ACell->Text, site_ptr->SiteName)) {
			 CELLOBJECT* CellObject;
			 if (ACell->CellObject == NULL) {
			   CellObject = new CELLOBJECT(site_ptr);
			   AddCellObject(ACell, CellObject);
			   }
			 else {
			   CellObject = (CELLOBJECT*)ACell->CellObject;
			   CellObject->Object = (TObject*)site_ptr;
			   }
			 found = true;
			 break;
			 }
		   }
		 if (!found) {
		   site_ptr = new SITE();
		   site_ptr->SiteName = ACell->Text;
		   Sites->Add(site_ptr);
		   CELLOBJECT* CellObject = new CELLOBJECT(site_ptr);
		   AddCellObject(ACell, CellObject);
		   map<int, Variant> MDValues;
		   map<UnicodeString, int>::iterator itr;
		   for (itr = SiteMDRows.begin(); itr != SiteMDRows.end(); itr++) {
			 if (SameText(itr->first, L"NAME")) continue;
			 MDValues[itr->second] = ProfGrid1->Cells[ACol][itr->second]->Value;
			 }
		   for (itr = SiteMDRows.begin(); itr != SiteMDRows.end(); itr++) {
			 if (SameText(itr->first, L"NAME")) continue;
			 UnicodeString Code = L"#SITE." + itr->first;
			 Variant Value = MDValues[itr->second];
			 if (!Value.IsEmpty()) {
			   ProfGrid1->Cells[ACol][itr->second]->Value = Value;
			   EnterSSMetaData(Code, Value, ACol, itr->second);
			   }
			 }

		   MDValues.clear();
		   for (itr = LakeMDRows.begin(); itr != LakeMDRows.end(); itr++)
			 MDValues[itr->second] = ProfGrid1->Cells[ACol][itr->second]->Value;
		   for (itr = LakeMDRows.begin(); itr != LakeMDRows.end(); itr++) {
			 UnicodeString Code = L"#LAKE." + itr->first;
			 Variant Value = MDValues[itr->second];
			 if (!Value.IsEmpty()) {
			   ProfGrid1->Cells[ACol][itr->second]->Value = Value;
			   EnterSSMetaData(Code, Value, ACol, itr->second);
			   }
			 }
		   }
		 }
	   }
	 }

   bool coll_found = false;
   if (CollNameRow > 0) {
	 for (int col=StartCol; col<=EndCol; col++) {
	   TProfGridCell* ACell = ProfGrid1->AbsoluteCells[col][CollNameRow];
	   if (!ACell->Text.IsEmpty()) {
		 coll_found = true;
		 break;
		 }
	   }
	 }

   if (coll_found) {
	 map<UnicodeString, int> CollMDRows;
	 GetMetaDataRows(L"#COLL.", CollMDRows);
	 for (int col=StartCol; col<=EndCol; col++) {
	   int ACol = col - ProfGrid1->HiddenColCount;
	   TProfGridCell* ACell = ProfGrid1->AbsoluteCells[col][CollNameRow];
	   UnicodeString CollName = ACell->Text;
	   if (!CollName.IsEmpty()) {
		 if (Sites->Count == 1)
		   site_ptr = (SITE*)Sites->Items[0];
		 else {
		   CELLOBJECT* CellObject = (CELLOBJECT*)ProfGrid1->AbsoluteCells[col][SiteNameRow]->CellObject;
		   site_ptr = (SITE*)CellObject->Object;
		   }
		 if (!site_ptr) continue;  // this shouldn't happen
		 bool found = false;
		 for (unsigned int i=1; i<site_ptr->CollUnits.size(); i++) {
		   if (SameText(CollName, site_ptr->CollUnits[i].CollectionName)) {
			 found = true;
			 break;
			 }
		   }
		 if (!found) {
		   COLLECTION CollUnit;
		   CollUnit.CollectionName = CollName;

		   int HandleRow;
		   if ((HandleRow = FindRowMD(COLL_UNIT_HANDLE)) > 0) {
			 Variant Handle = ProfGrid1->Cells[ACol][HandleRow]->Text;
			 if (!Handle.IsEmpty())
			   CollUnit.Handle = Handle;
			 }
		   site_ptr->CollUnits.push_back(CollUnit);

		   map<int, Variant> MDValues;
		   map<UnicodeString, int>::iterator itr;
		   for (itr = CollMDRows.begin(); itr != CollMDRows.end(); itr++) {
			 if (SameText(itr->first, L"NAME") || SameText(itr->first, L"HANDLE")) continue;
			 MDValues[itr->second] = ProfGrid1->Cells[ACol][itr->second]->Value;
			 }

		   for (itr = CollMDRows.begin(); itr != CollMDRows.end(); itr++) {
			 if (SameText(itr->first, L"NAME") || SameText(itr->first, L"HANDLE")) continue;
			 UnicodeString Code = L"#COLL." + itr->first;
			 Variant Value = MDValues[itr->second];
			 if (!Value.IsEmpty()) {
			   EnterSSMetaData(Code, Value, ACol, itr->second);
			   }
			 }
		   }
		 }
	   }
	 }
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::DeleteSSSiteName(Variant& Value, TProfGridCell *CurCell,
   int ACol, int ARow, bool Query)
{
   int StartCol = AbsHeaderColCount(ProfGrid1);
   int EndCol = AbsContentColCount(ProfGrid1);
   int CurCol = CurCell->AbsoluteCol;
   int SiteRow = ARow;
   int CollRow;

   CELLOBJECT* CellObject = (CELLOBJECT*)CurCell->CellObject;
   SITE* site_ptr = (SITE*)CellObject->Object;
   UnicodeString msg = L"Deleting Site Name will delete all associated site metadata.";
   int rv;
   if (!Query || MessageDlg(msg, mtWarning, TMsgDlgButtons() << mbOK << mbCancel, 0) == mrOk) {
	 // first delete collection unit for this column if it exists
	 if ((CollRow = FindRowMD(COLL_UNIT_NAME)) > 0) {
	   TProfGridCell *CollCell = ProfGrid1->AbsoluteCells[CurCol][CollRow];
	   UnicodeString CollName = CollCell->Text;
	   if (!CollName.IsEmpty()) {
		 Variant CollValue = CollCell->Value;
		 DeleteSSCollName(CollValue, site_ptr, CollCell, CollName, SiteRow,
		   ACol, CollRow, false);
		 }
	   }

	 // delete all site metadata items in column
	 if (CurCell->CellObject != NULL) {
	   DeleteCellObject(CurCell);
	   }
	 if (HeaderRow2 == SITE_NAME)
	   ProfGrid1->Cells[ACol][2]->Value = Unassigned();
	 int RowCount = ContentRowCount(ProfGrid1);
	 TProfGridColumn* CodeCol = ProfGrid1->AbsoluteCols[1];
	 for (int row=3; row<=RowCount; row++) {
	   UnicodeString Code = CodeCol->AbsoluteCells[row]->Value;
	   Code = Code.UpperCase();
	   if (SameText(Code.SubString(1,6), L"#SITE.") || SameText(Code.SubString(1,6), L"#LAKE."))
		 ProfGrid1->Cells[ACol][row]->Value = Unassigned();
	   }
	 // if last instance of this site, then delete site
	 bool found = false;
	 int Col = StartCol;
	 SITE* col_site_ptr;
	 while ((col_site_ptr = GetNextColSitePtr(CurCol, Col, EndCol, SiteRow)) != NULL) {
	   if (col_site_ptr == site_ptr) {
		 found = true;
		 break;
		 }
	   Col++;
	   }
	 if (!found) {
	   Sites->Remove(site_ptr);
	   delete site_ptr;
	   }
	 SitePtr = NULL;
	 }
   else {  // cancel deletion of SiteName
	 Value = site_ptr->SiteName;
	 CurCell->Value = Value;
	 }
}
//---------------------------------------------------------------------------

SITE* TTilSpreadSheetForm::GetNextColSitePtr(int CurCol, int& StartCol,
	  int EndCol, int SiteRow)
{
   if (SiteRow == 0) {
	 if (StartCol == CurCol)
	   StartCol++;
	 if (StartCol <= EndCol) {

	   return (SITE*)Sites->Items[0];
	   }
	 else
	   return NULL;
	 }
   for (int col=StartCol; col<=EndCol; col++) {
	 if (CurCol == col)
	   continue;
	 TProfGridCell* ACell = ProfGrid1->AbsoluteCells[col][SiteRow];
	 if (ACell->CellObject != NULL) {
	   CELLOBJECT* CellObject = (CELLOBJECT*)ACell->CellObject;
	   if (CellObject->ObjectType == CELLSITE) {
		 StartCol = col;
		 return (SITE*)CellObject->Object;
		 }
	   }
	 }
   return NULL;
}
//---------------------------------------------------------------------------

SITE* TTilSpreadSheetForm::GetSSSitePtr(int ACol, int& SiteRow)
{
   SITE* site_ptr = NULL;
   SiteRow = FindRowMD(SITE_NAME);
   if (SiteRow > 0) {
	 if (ProfGrid1->Cells[ACol][SiteRow]->CellObject != NULL) {
	   CELLOBJECT* CellObject = (CELLOBJECT*)ProfGrid1->Cells[ACol][SiteRow]->CellObject;
	   site_ptr = (SITE*)CellObject->Object;
	   }
	 }
   return site_ptr;
}
//---------------------------------------------------------------------------
