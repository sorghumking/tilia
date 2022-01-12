//---------------------------------------------------------------------------
#include <vcl.h>
#include "pch.h"
#pragma hdrstop

#include "TITaph.h"
#ifndef TISpreadH
#include "TISpread.h"
#endif
//---------------------------------------------------------------------------

#pragma package(smart_init)

void TTilSpreadSheetForm::CreateTaphSystems(TAPHSYSTEMS** TaphSystems)
{
   *TaphSystems = new TAPHSYSTEMS();

   UnicodeString DatasetType = Datasets[DatasetNum].DatasetType.LowerCase();
   if (!TaphonomyLookup->DatasetTypeExists(DatasetType))
	 DatasetType = GenericDatasetType(DatasetType);
   (*TaphSystems)->DatasetType = DatasetType;
   set<UnicodeString> Systems;
   TaphonomyLookup->GetSystems(DatasetType, Systems);
   TAPHSYSTEM TaphSystem;
   TaphSystem.Name = L"none";
   (*TaphSystems)->Systems.push_back(TaphSystem);
   for (set<UnicodeString>::iterator itr = Systems.begin(); itr != Systems.end(); itr++) {
	 TAPHSYSTEM TaphSystem;
	 TaphSystem.Name = *itr;
	 (*TaphSystems)->Systems.push_back(TaphSystem);
	 }
}
//---------------------------------------------------------------------------

// checks taphonomy already entered before taphonomy lookup file was read
void TTilSpreadSheetForm::CheckTaphonomy(void)
{
   UnicodeString msg;

   int RowCount = ContentRowCount(ProfGrid1);
   int rv = -1;
   for (int row=3; row<=RowCount; row++) {
	 TProfGridCell* ACell = ProfGrid1->AbsoluteCells[6][row];
	 if (ACell->CellObject) {
	   CELLOBJECT* CellObject = (CELLOBJECT*)ACell->CellObject;
	   TAPHSYSTEMS* TaphSystems = (TAPHSYSTEMS*)CellObject->Object;
	   int idx = -1;
	   for (unsigned int i=0; i<TaphSystems->Systems.size(); i++) {
		 if (SameText(TaphSystems->Systems[i].Name, L"none")) {
		   idx = i;
		   break;
		   }
		 }
	   if (idx > -1) {
		 set<UnicodeString> Systems;
		 TaphonomyLookup->GetSystems(TaphSystems->DatasetType, Systems);
			bool done = false;
			set<UnicodeString>::iterator tbegin = TaphSystems->Systems[idx].Types.begin();
			set<UnicodeString>::iterator tend = TaphSystems->Systems[idx].Types.end();
			for (set<UnicodeString>::iterator titr = tbegin; titr != tend; titr++) {
			  UnicodeString Type = *titr;
			  for (set<UnicodeString>::iterator sitr = Systems.begin(); sitr != Systems.end(); sitr++) {
				UnicodeString System = *sitr;
				if (!SameText(System, L"none")) {
				  if (TaphonomyLookup->TypeExists(TaphSystems->DatasetType, System, Type)) {
					if (rv != mrYesToAll) {
					  msg = L"Taphonomic type «" + Type +
							L"» currently in system «none» is a member of taphonomic system «" +
							System + L"».\nTransfer type «" + Type + L"» to system «" + System + L"»?";
					  rv = MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo << mbYesToAll << mbNoToAll, 0);
					  }
					if (rv == mrYes || rv == mrYesToAll) {
					  //TaphSystems->RemoveType(L"none", Type);
					  TaphSystems->RemoveSystem(L"none");
					  TaphSystems->AddType(System, Type);
					  done = true;
					  }
					else if (rv == mrNoToAll)
					  return;
					break;
					}
				  }
				}
		 	  if (done) break;
			  }
		 ACell->Value = TaphSystems->Text();
		 }
	   }
	 }
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::PostTaphonomy(void)
{
   TAPHSYSTEMS* TaphSystems;
   int ACol = ProfGrid1->Cols[ProfGrid1->Col]->AbsoluteNumber;
   int ARow = ProfGrid1->Rows[ProfGrid1->Row]->AbsoluteNumber;
   TProfGridCell* ACell = ProfGrid1->AbsoluteCells[ACol][ARow];
   if (ACell->CellObject != NULL) {
	 DeleteCellObject(ACell);
	 }

   TaphSystems = new TAPHSYSTEMS(TempTaphSystems);
   CELLOBJECT* CellObject = new CELLOBJECT(TaphSystems);
   AddCellObject(ACell, CellObject);
   delete TempTaphSystems;
   TempTaphSystems = NULL;
   AdvControlDropDown3->Text = TaphSystems->Text();

   for (unsigned int i=0; i < TaphSystems->Systems.size(); i++) {
	 if (!SameText(TaphSystems->Systems[i].Name, L"none")) {
	   if (TaphSystems->Systems[i].Types.size() > 0) {
		 CurrentTaphSystem = TaphSystems->Systems[i].Name;
		 break;
		 }
	   }
	 }

   TaphonomyPosted = true;
}
//---------------------------------------------------------------------------


