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
#include <DateUtils.hpp>
#include <Math.hpp>
#include <SysUtils.hpp>

#include "TISpread2.h"
#ifndef TISynonymH
#include "TISynonym.h"
#endif
#ifndef TISpreadH
#include "TISpread.h"
#endif
#ifndef TIGlobalsH
#include "TIGlobals.h"
#endif
#ifndef TGH
#include "tg.h"
#endif
#ifndef TGTextH
#include "TGText.h"
#endif
#ifndef TGtgfioH
#include "Tgtgfio.h"
#endif
#ifndef TItlxioH
#include "TItlxout.h"
#endif
#ifndef TGUtilsH
#include "TGUtils.h"
#endif
#ifndef TIPublH
#include "TIPubl.h"
#endif
#ifndef TIMemoH
#include "TIMemo.h"
#endif
#ifndef TINewConH
#include "TINewCon.h"
#endif
#ifndef TIPubLnkH
#include "TIPubLnk.h"
#endif
#ifndef TIChkVarH
#include "TIChkVar.h"
#endif
#ifndef TIErrFrmH
#include "TIErrFrm.h"
#endif
#ifndef TIChronH
#include "TIChron.h"
#endif
//#ifndef TIVrLkUpH
//#include "TIVrLkUp.h"
//#endif
#ifndef TIEdtElmH
#include "TIEdtElm.h"
#endif
//#ifndef TSUtilsH
//#include "TSUtils.h"
//#endif
#ifndef TITrainH
#include "TITrain.h"
#endif
#ifndef TISeEcGrH
#include "TISeEcGr.h"
#endif
#ifndef TIAdmUntH
#include "TIAdmUnt.h"
#endif
//#ifndef TIAgeBasH
//#include "TIAgeBas.h"
//#endif
//#ifndef TIDepEnvH
//#include "TIDepEnv.h"
//#endif
#ifndef TICONShtH
#include "TICONSht.h"
#endif
#ifndef TISumsH
#include "TISums.h"
#endif
#ifndef TIEdTaxaH
#include "TIEdTaxa.h"
#endif
#ifndef TIEdtModH
#include "TIEdtMod.h"
#endif
#ifndef TIOptionH
#include "TIOption.h"
#endif
#ifndef TIEdtElmH
#include "TIEdtElm.h"
#endif
#ifndef TIConFrmH
#include "TIConFrm.h"
#endif
#ifndef TIDecH
#include "TIDec.h"
#endif
#ifndef TIPltModH
#include "TIPltMod.h"
#endif
//#ifndef TIOrigIDH
//#include "TIOrigID.h"
//#endif
#ifndef TIFuzzyH
#include "TIFuzzy.h"
#endif
#ifndef TIConcH
#include "TIConc.h"
#endif
//#ifndef TIAddCalH
//#include "TIAddCal.h"
//#endif
#ifndef TISlpAspH
#include "TISlpAsp.h"
#endif
#ifndef TIUploadH
#include "TIUpload.h"
#endif
//#ifndef TNTaxaH
//#include "TNTaxa.h"
//#endif
//#ifndef TNVarModsH
//#include "TNVarMods.h"
//#endif
#ifndef TIDelEmpH
#include "TIDelEmp.h"
#endif
#ifndef TISitHirH
#include "TISitHir.h"
#endif
#ifndef TIEdTreeH
#include "TIEdTree.h"
#endif
//#ifndef TIUpContactH
//#include "TIUpContact.h"
//#endif
#ifndef TNLoginH
#include "TNLogin.h"
#endif
#ifndef TINeotomaH
#include "TINeotoma.h"
#endif
#ifndef TITphChkH
#include "TITphChk.h"
#endif
#ifndef TIEdTaphH
#include "TIEdTaph.h"
#endif
#ifndef TNLookupH
#include "TNLookup.h"
#endif
//#ifndef TICalibH
//#include "TICalib.h"
//#endif
//#ifndef TIImpChrH
//#include "TIImpChr.h"
//#endif
//#ifndef TIExpChrH
//#include "TIExpChr.h"
//#endif
//#ifndef TIImpDatH
//#include "TIImpDat.h"
//#endif
//#ifndef TINwLkUpH
//#include "TINwLkUp.h"
//#endif
//#ifndef TINewTxnH
//#include "TINewTxn.h"
//#endif
//#ifndef TIChkHirH
//#include "TIChkHir.h"
//#endif
//#ifndef TIAUAgesH
//#include "TIAUAges.h"
//#endif
#ifndef TNUtilsH
#include "TNUtils.h"
#endif

//---------------------------------------------------------------------------

#pragma package(smart_init)
#pragma link "cxControls"
#pragma link "ipwCore"
#pragma link "ipwxmlp"
#pragma link "cxClasses"
#pragma link "cxCustomData"
#pragma link "cxData"
#pragma link "cxDataStorage"
#pragma link "cxEdit"
#pragma link "cxFilter"
#pragma link "cxGraphics"
#pragma link "cxGrid"
#pragma link "cxGridCardView"
#pragma link "cxGridCustomTableView"
#pragma link "cxGridCustomView"
#pragma link "cxGridLevel"
#pragma link "cxStyles"
#pragma link "cxGridTableView"
#pragma link "cxTextEdit"
#pragma link "cxBlobEdit"
#pragma link "cxMemo"
#pragma link "cxRichEdit"
#pragma link "cxDropDownEdit"
#pragma link "cxCheckComboBox"
#pragma link "cxContainer"
#pragma link "cxMaskEdit"
#pragma link "cxCheckListBox"
#pragma link "cxButtonEdit"
#pragma link "cxCheckBox"
#pragma link "cxCalendar"
#pragma link "cxPC"
#pragma link "ProfGrid"
#pragma link "cxTreeView"
#pragma link "cxLabel"
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxDBExtLookupComboBox"
#pragma link "cxSpinEdit"
#pragma link "cxLookAndFeels"
#pragma link "ipworks"
#pragma link "cxImage"
#pragma link "cxCalc"
#pragma link "AdvControlDropDown"
#pragma link "AdvDropDown"
#pragma link "cxGridCustomLayoutView"
#pragma link "dxCore"
#pragma link "dxdbtrel"
#pragma link "AdvMultiColumnDropDown"
#pragma link "AdvCustomGridDropDown"
#pragma link "AdvGridDropDown"
#pragma link "AdvGrid"
#pragma link "AdvObj"
#pragma link "BaseGrid"
#pragma link "AdvGrid"
#pragma link "AdvObj"
#pragma link "cxDateUtils"
#pragma link "cxNavigator"
#pragma link "AdvCGrid"
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxCheckComboBox8PropertiesCloseUp(TObject *Sender)
{
   set<UnicodeString> NewTaxaGroups;
   for (int i=0; i<cxCheckComboBox8->Properties->Items->Count; i++) {
	 if (cxCheckComboBox8->States[i] == cbsChecked)
	   NewTaxaGroups.insert(cxCheckComboBox8->Properties->Items->Items[i]->Description);
	 }
   tiGlobals->TaxaGroups = NewTaxaGroups;
   FillEcolGroupsGrid(&NewTaxaGroups);
   SetEcolGroupsGridRow();
   cxCheckComboBox8->Visible = false;
   AdvColumnGrid1->Top = 0;
   AdvColumnGrid1->Height = Panel7->Height - 3;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxComboBox15Exit(TObject *Sender)
{
   ProfGrid1->RowHeights[ProfGrid1->Row] = CurrentRowHeight;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::Synonyms1Click(TObject *Sender)
{
   TPoint pnt = ProfGrid1->ClientToScreen(TPoint(0,0));
   TaxonNotesPos.X = pnt.x + ProfGrid1->GetX(2);
   TaxonNotesPos.Y = pnt.y + ProfGrid1->GetY(ProfGrid1->Row) + ProfGrid1->Rows[ProfGrid1->Row]->Height;

   TProfGridCell* ACell = ProfGrid1->AbsoluteCells[2][ProfGrid1->Row];
   CELLOBJECT* CellObject;
   TAXON_NOTES* TaxonNotes;
   TAXON_NOTES* OldTaxonNotes = NULL;

   if (ACell->CellObject != NULL) {
	 CellObject = (CELLOBJECT*)ACell->CellObject;
	 TaxonNotes = (TAXON_NOTES*)CellObject->Object;
	 OldTaxonNotes = new TAXON_NOTES(TaxonNotes);
	 }
   else {
	 CellObject = new CELLOBJECT(CELLTAXONNOTES);
	 TaxonNotes = (TAXON_NOTES*)CellObject->Object;
	 }

   SynonymForm = new TSynonymForm(TaxonNotes, TaxonNotesPos, this);

   if (SynonymForm->ShowModal() == mrOk)
	 ProcessTaxonNotes(ProfGrid1->Row, CellObject);
   else if (OldTaxonNotes != NULL)
	 *TaxonNotes = *OldTaxonNotes;
   else
	 delete CellObject;

   if (OldTaxonNotes != NULL)
	 delete OldTaxonNotes;
   delete SynonymForm;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::TaxonNotes1Click(TObject *Sender)
{
   UnicodeString msg, ErrorMsg;
   int NeotomaDatasetID = -1;

   TPoint pnt = ProfGrid1->ClientToScreen(TPoint(0,0));
   TaxonNotesPos.X = pnt.x + ProfGrid1->GetX(2);
   TaxonNotesPos.Y = pnt.y + ProfGrid1->GetY(ProfGrid1->Row) + ProfGrid1->Rows[ProfGrid1->Row]->Height;

   TProfGridCell* ACell = ProfGrid1->AbsoluteCells[2][ProfGrid1->Row];

   CELLOBJECT* CellObject;
   TAXON_NOTES* TaxonNotes;
   TAXON_NOTES* OldTaxonNotes = NULL;

   if (ACell->CellObject != NULL) {
	 CellObject = (CELLOBJECT*)ACell->CellObject;
	 TaxonNotes = (TAXON_NOTES*)CellObject->Object;
	 OldTaxonNotes = new TAXON_NOTES(TaxonNotes);
	 }
   else {
	 CellObject = new CELLOBJECT(CELLTAXONNOTES);
	 TaxonNotes = (TAXON_NOTES*)CellObject->Object;
	 }

   UnicodeString Caption = L"Notes | " + ProfGrid1->AbsoluteCells[2][ProfGrid1->Row]->Text;

   int NeotomaVariableID;
   int DatasetIdx;
   bool steward = false;

   if (Downloaded && tiLicense->Type() == verNEOTOMASTEWARD) {
	 steward = ValidateSteward(DatasetIdx);
	 NeotomaVariableID = GetSSDownloadVariableID(ProfGrid1->Row);
	 if (NeotomaVariableID == -1)   // this should never happen, but...
	   return;
	 }

   if (steward) {
	 NeotomaDatasetID = Datasets[DatasetIdx].NeotomaDatasetID;
	 TaxonNotesForm = new TTaxonNotesForm(Caption, TaxonNotes->Notes,
		MemoFormOptions() << mfoCancelButton << mfoBlankButton, TaxonNotesPos, this);
	 }
   else {
	 TaxonNotesForm = new TTaxonNotesForm(Caption, TaxonNotes->Notes,
		MemoFormOptions() << mfoCancelButton, TaxonNotesPos, this);
	 }

   int rv = TaxonNotesForm->ShowModal();

   if (steward && rv == mrYes) {
	 if (TaxonNotes->Notes == TaxonNotesForm->Text) {
	   msg = L"Notes not changed. Update not made.";
	   MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
	   }
	 else {  // update       // NeotomaDatasetID
	   UnicodeString StatusBarText = ParentForm->StatusBar1->Panels->Items[0]->Text;
	   NeotomaVariableTaxonID VarTaxonID(ipsJSONS1, TcpClient1);
	   VarTaxonID.AddParam(L"VARIABLEID", NeotomaVariableID);
	   ParentForm->StatusBar1->Panels->Items[0]->Text = VarTaxonID.WebServiceName();
	   Screen->Cursor = crHourGlass;
	   if (VarTaxonID.Execute()) {
		 int TaxonID = VarTaxonID.Items[0];
		 // see if note already exists in Neotoma
		 NeotomaDatasetTaxonNotesByTaxonID DatasetTaxonNotes(ipsJSONS1, TcpClient1);
		 DatasetTaxonNotes.AddParam(L"DATASETID", NeotomaDatasetID);
		 DatasetTaxonNotes.AddParam(L"TAXONID", TaxonID);
		 ParentForm->StatusBar1->Panels->Items[0]->Text = DatasetTaxonNotes.WebServiceName();
		 if (DatasetTaxonNotes.Execute()) {
		   if (DatasetTaxonNotes.Size() == 0) {  // new note
			 InsertData InsertTaxonNotes(L"InsertDatasetTaxonNotes", 6, ipsHTTPS1, ipsJSONS1, TcpClient1);
			 InsertTaxonNotes.Add(L"DATASETID", NeotomaDatasetID, -1);
			 InsertTaxonNotes.Add(L"TAXONID", TaxonID, -1);
			 InsertTaxonNotes.Add(L"CONTACTID", Login->ContactID, -1);
			 InsertTaxonNotes.Add(L"DATE", UTCDateTime().FormatString(L"yyyy-mm-dd"));
			 InsertTaxonNotes.Add(L"NOTES", TaxonNotesForm->Text);
			 InsertTaxonNotes.Add(L"UPDATE", true);
			 ParentForm->StatusBar1->Panels->Items[0]->Text = L"InsertDatasetTaxonNotes";
			 InsertTaxonNotes.PostData();
			 ErrorMsg = L"";
			 if (InsertTaxonNotes.Post(ErrorMsg)) {
			   msg = L"Notes inserted into DatasetTaxonNotes table.";
			   MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
			   }
			 else {
			   msg = ErrorMsg + L"\nNotes not inserted into DatasetTaxonNotes table.";
			   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			   }
			 }
		   else {  // note already exists
			 if (TaxonNotesForm->Text.IsEmpty()) {  // delete note
			   DeleteData DeleteTaxonNotes(L"DeleteDatasetTaxonNotes", 3, ipsHTTPS1, ipsJSONS1, TcpClient1);
			   ParentForm->StatusBar1->Panels->Items[0]->Text = L"DeleteDatasetTaxonNotes";
			   DeleteTaxonNotes.Add(L"DATASETID", NeotomaDatasetID);
			   DeleteTaxonNotes.Add(L"TAXONID", TaxonID);
			   DeleteTaxonNotes.Add(L"CONTACTID", Login->ContactID);
			   ErrorMsg = L"";
			   if (DeleteTaxonNotes.Post(ErrorMsg)) {
				 UnicodeString msg = L"Note deleted from DatasetTaxonNotes table.";
				 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
				 }
			   else {
				 msg = ErrorMsg + L"\nNotes not deleted from DatasetTaxonNotes table.";
				 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
				 }
			   }
			 else {  // update note
			   UpdateData UpdateTaxonNotes(L"UpdateDatasetTaxonNotes", 5, ipsHTTPS1, ipsJSONS1, TcpClient1);
			   ParentForm->StatusBar1->Panels->Items[0]->Text = L"UpdateDatasetTaxonNotes";
			   UpdateTaxonNotes.Add(L"DATASETID", NeotomaDatasetID);
			   UpdateTaxonNotes.Add(L"TAXONID", TaxonID);
			   UpdateTaxonNotes.Add(L"CONTACTID", Login->ContactID);
			   UpdateTaxonNotes.Add(L"DATE", UTCDateTime().FormatString(L"yyyy-mm-dd"));
			   UpdateTaxonNotes.Add(L"NOTES", TaxonNotesForm->Text);
			   ErrorMsg = L"";
			   if (UpdateTaxonNotes.Post(ErrorMsg)) {
				 UnicodeString msg = L"Notes updated in DatasetTaxonNotes table.";
				 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
				 }
			   else {
				 msg = ErrorMsg + L"\nNotes not updated in DatasetTaxonNotes table.";
				 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
				 }
			   }
			 }
		   }
		 }
	   ParentForm->StatusBar1->Panels->Items[0]->Text = StatusBarText;
	   Screen->Cursor = crDefault;
	   }
	 }

   if (rv == mrOk || rv == mrYes) {
	 TaxonNotes->Notes = TaxonNotesForm->Text;
	 ProcessTaxonNotes(ProfGrid1->Row, CellObject);
	 }
   else if (OldTaxonNotes != NULL) {
	 *TaxonNotes = *OldTaxonNotes;
	 }
   else
	 delete CellObject;

   if (OldTaxonNotes != NULL)
	 delete OldTaxonNotes;
   delete TaxonNotesForm;
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::ProcessTaxonNotes(int ARow, CELLOBJECT* CellObject)
{
   TAXON_NOTES* TaxonNotes = (TAXON_NOTES*)CellObject->Object;
   bool NotesEmpty = TaxonNotes->Notes.IsEmpty() && TaxonNotes->Synonymy.size() == 0;

   TProfGridCell* ACell = ProfGrid1->AbsoluteCells[2][ARow];
   if (NotesEmpty) {
	 if (ACell->CellObject != NULL)
	   DeleteCellObject(ACell);
	 else {
	   delete CellObject;
	   CellObject = NULL;
	   }
	 }
   else {
	 if (ACell->CellObject == NULL)
	   AddCellObject(ACell, CellObject);
	 }

   CELLOBJECT* CellObject2;
   UnicodeString TaxonName = ACell->Text;

   int StartRow = AbsHeaderRowCount(ProfGrid1);
   int RowCount = AbsContentRowCount(ProfGrid1);
   for (int row=StartRow; row<=RowCount; row++) {
	 if (row == ProfGrid1->Row) continue;
	 ACell = ProfGrid1->AbsoluteCells[2][row];
	 if (SameText(TaxonName, ACell->Text)) {
	   if (ACell->CellObject == NULL) {
		 if (CellObject != NULL) {
		   CellObject2 = new CELLOBJECT(CellObject);
		   AddCellObject(ACell, CellObject2);
		   }
		 }
	   else {
		 CellObject2 = (CELLOBJECT*)ACell->CellObject;
		 if (CellObject != NULL) {
		   *CellObject2 = *CellObject;
		   AddTaxonNotesIcon(ACell);
		   }
		 else   // delete TaxonNotes2
		   DeleteCellObject(ACell);
		 }
	   }
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::NeotomaLookupAction1Execute(TObject *Sender)
{
   NeotomaWriteLookupForm = new TNeotomaWriteLookupForm(LTLOOKUP, this);
   NeotomaWriteLookupForm->ShowModal();
   delete NeotomaWriteLookupForm;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::NeotomaGeoPoliticalLookupAction1Execute(TObject *Sender)
{
   NeotomaWriteLookupForm = new TNeotomaWriteLookupForm(LTGEOPOLITICAL, this);
   NeotomaWriteLookupForm->ShowModal();
   delete NeotomaWriteLookupForm;
}
//---------------------------------------------------------------------------

typedef pair<UnicodeString,UnicodeString> EPAIR;

void TTilSpreadSheetForm::ReformatElements(void)
{
   if (xml_Version > VERSION(2,0,4)) return;

   multimap<UnicodeString, UnicodeString> elems;
   elems.insert(EPAIR("frontal", "antler"));
   elems.insert(EPAIR("frontal", "horn core"));
   elems.insert(EPAIR("frontal", "pedicle"));
   elems.insert(EPAIR("mandibular ramus", "edentulous"));
   elems.insert(EPAIR("mandibular ramus", "teeth"));
   elems.insert(EPAIR("maxilla", "edentulous"));
   elems.insert(EPAIR("maxilla", "teeth"));
   elems.insert(EPAIR("palate", "edentulous"));
   elems.insert(EPAIR("palate", "teeth"));
   elems.insert(EPAIR("premaxilla", "edentulous"));
   elems.insert(EPAIR("premaxilla", "teeth"));
   elems.insert(EPAIR("skull", "edentulous"));
   elems.insert(EPAIR("skull", "teeth"));
   elems.insert(EPAIR("tooth", "canine"));
   elems.insert(EPAIR("tooth", "crown"));
   elems.insert(EPAIR("tooth", "deciduous"));
   elems.insert(EPAIR("tooth", "deciduous canine"));
   elems.insert(EPAIR("tooth", "deciduous incisor"));
   elems.insert(EPAIR("tooth", "deciduous premolar"));
   elems.insert(EPAIR("tooth", "fifth incisor"));
   elems.insert(EPAIR("tooth", "first deciduous incisor"));
   elems.insert(EPAIR("tooth", "first deciduous premolar"));
   elems.insert(EPAIR("tooth", "first incisor"));
   elems.insert(EPAIR("tooth", "first molar"));
   elems.insert(EPAIR("tooth", "first premolar"));
   elems.insert(EPAIR("tooth", "fourth deciduous premolar"));
   elems.insert(EPAIR("tooth", "fourth incisor"));
   elems.insert(EPAIR("tooth", "fourth molar"));
   elems.insert(EPAIR("tooth", "fourth premolar"));
   elems.insert(EPAIR("tooth", "incisor"));
   elems.insert(EPAIR("tooth", "molar"));
   elems.insert(EPAIR("tooth", "premolar"));
   elems.insert(EPAIR("tooth", "root"));
   elems.insert(EPAIR("tooth", "second deciduous incisor"));
   elems.insert(EPAIR("tooth", "second deciduous premolar"));
   elems.insert(EPAIR("tooth", "second incisor"));
   elems.insert(EPAIR("tooth", "second molar"));
   elems.insert(EPAIR("tooth", "second premolar"));
   elems.insert(EPAIR("tooth", "third deciduous incisor"));
   elems.insert(EPAIR("tooth", "third deciduous premolar"));
   elems.insert(EPAIR("tooth", "third incisor"));
   elems.insert(EPAIR("tooth", "third molar"));
   elems.insert(EPAIR("tooth", "third premolar"));
   elems.insert(EPAIR("vertebra", "atlas"));
   elems.insert(EPAIR("vertebra", "axis"));
   elems.insert(EPAIR("vertebra", "caudal"));
   elems.insert(EPAIR("vertebra", "cervical"));
   elems.insert(EPAIR("vertebra", "lumbar"));
   elems.insert(EPAIR("vertebra", "sacrum"));
   elems.insert(EPAIR("vertebra", "thoracic"));

   map<UnicodeString,UnicodeString> numbered_elems;
   numbered_elems[L"metacarpal i"]   = L"metacarpal, first";
   numbered_elems[L"metacarpal ii"]  = L"metacarpal, second";
   numbered_elems[L"metacarpal iii"] = L"metacarpal, third";
   numbered_elems[L"metacarpal iv"]  = L"metacarpal, fourth";
   numbered_elems[L"metacarpal v"]   = L"metacarpal, fifth";
   numbered_elems[L"metatarsal i"]   = L"metatarsal, first";
   numbered_elems[L"metatarsal ii"]  = L"metatarsal, second";
   numbered_elems[L"metatarsal iii"] = L"metatarsal, third";
   numbered_elems[L"metatarsal iv"]  = L"metatarsal, fourth";
   numbered_elems[L"metatarsal v"]   = L"metatarsal, fifth";
   numbered_elems[L"phalanx i"]      = L"phalanx, first";
   numbered_elems[L"phalanx ii"]     = L"phalanx, second";
   numbered_elems[L"phalanx iii"]    = L"phalanx, third";
   numbered_elems[L"phalanx iv"]     = L"phalanx, fourth";
   numbered_elems[L"phalanx v"]      = L"phalanx, fifth";

   pair<multimap<UnicodeString,UnicodeString>::iterator, multimap<UnicodeString,UnicodeString>::iterator> range;
   multimap<UnicodeString,UnicodeString>::iterator itr;

   int HeaderRows = AbsHeaderRowCount(ProfGrid1);
   int RowCount = AbsContentRowCount(ProfGrid1);
   for (int row=HeaderRows; row<=RowCount; row++) {
	 bool new_element = false;
	 UnicodeString Element = ProfGrid1->AbsoluteCells[3][row]->Value;
	 if (Element.IsEmpty())
	   continue;
	 vector<UnicodeString> parts;
	 if (Element.Pos(L";") == 0) {   // not already using semi-colon separators
	   ParseParts(Element, L",", parts);
	   bool elem_pair = false;
	   // find element pairs
	   if (parts.size() > 1 && elems.count(parts[0]) > 0) {
		 range = elems.equal_range(parts[0]);
		 for (itr = range.first; itr != range.second; itr++) {
		   if (SameText(parts[1], itr->second)) {
			 elem_pair = true;
			 break;
			 }
		   }
		 }
	   int start = 1;
	   if (elem_pair) {
		 Element = parts[0] + L"," + parts[1];
		 start = 2;
		 }
	   else {
		 Element = parts[0];
		 map<UnicodeString,UnicodeString>::iterator nitr;
		 if ((nitr = numbered_elems.find(Element.LowerCase())) != numbered_elems.end())
		   Element = nitr->second;
		 }
	   // delimit remaining parts with semi-colons
	   for (unsigned int i=start; i<parts.size(); i++)
		 Element += (L";" + parts[i]);
	   new_element = true;
	   ProfGrid1->AbsoluteCells[3][row]->Value = Element;
	   }
	 parts.clear();
	 ParseParts(Element, L";", parts);
	 if (parts.size() > 2) {
	   UnicodeString Symmetry;
	   vector<UnicodeString>::iterator itr;
	   if ((itr = find(parts.begin(), parts.end(), L"lower")) != parts.end()) {
		 Symmetry = L"lower";
		 parts.erase(itr);
		 }
	   else if ((itr = find(parts.begin(), parts.end(), L"upper")) != parts.end()) {
		 Symmetry = L"upper";
		 parts.erase(itr);
		 }
	   if (!Symmetry.IsEmpty()) {
		 if ((itr = find(parts.begin(), parts.end(), L"left")) != parts.end()) {
		   Symmetry += L" left";
		   parts.erase(itr);
		   }
		 else if ((itr = find(parts.begin(), parts.end(), L"right")) != parts.end()) {
		   Symmetry += L" right";
		   parts.erase(itr);
		   }
		 Element = parts[0] + L"; " + Symmetry;
		 for (unsigned int i=1; i<parts.size(); i++)
		   Element += L";" + parts[i];
		 new_element = true;
		 }
	   }

	 if (new_element)
	   ProfGrid1->AbsoluteCells[3][row]->Value = Element;
	 }
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::EditFacies(void)
{
   EditFaciesForm = new TEditFaciesForm(FaciesTypes, L"", this, this);
   EditFaciesForm->ShowModal();
   delete EditFaciesForm;
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::EditDepAgents(void)
{
   EditDepAgentsForm = new TEditDepAgentsForm(DepAgents, L"", this, this);
   EditDepAgentsForm->ShowModal();
   delete EditDepAgentsForm;
}
//---------------------------------------------------------------------------

bool TTilSpreadSheetForm::GetTaxon(int ARow, TAXON& Taxon)
{
   bool rv = false;
   if (TaxaLookupOpen) {
	 int AbsRow = ProfGrid1->Rows[ARow]->AbsoluteNumber;
	 TProfGridCell* ACell = ProfGrid1->AbsoluteCells[2][AbsRow];
	 if (!ACell->IsEmpty()) {
	   UnicodeString TaxonName = ACell->Text;
	   vector<TAXON> TaxaFound;
	   if (TaxaList.FindName(TaxonName, TaxaFound) > 0) {
		 if (TaxaFound.size() > 0) {
		   // TODO: deal with >1 taxon with same name -- rare;
		   Taxon = TaxaFound[0];
		   }
		 else
		   Taxon = TaxaFound[0];
		 rv = true;
		 }
	   }
	 }
   return rv;
}
//---------------------------------------------------------------------------

bool TTilSpreadSheetForm::GetTaxon(UnicodeString TaxonName, TAXON& Taxon)
{
   bool rv = false;
   if (TaxaLookupOpen) {
	 vector<TAXON> TaxaFound;
	 if (TaxaList.FindName(TaxonName, TaxaFound) > 0) {
	   if (TaxaFound.size() > 0) {
		 // TODO: deal with >1 taxon with same name -- rare;
		 Taxon = TaxaFound[0];
		 }
	   else
		 Taxon = TaxaFound[0];
	   rv = true;
	   }
	 }
   return rv;
}
//---------------------------------------------------------------------------

bool TTilSpreadSheetForm::GetGeochronTaxon(UnicodeString TaxonName, TAXON& Taxon)
{
   bool rv = false;
   if (GeochronTaxaOpen) {
	 vector<TAXON> TaxaFound;
	 if (GeochronTaxaList.FindName(TaxonName, TaxaFound) > 0) {
	   if (TaxaFound.size() > 0) {
		 // TODO: deal with >1 taxon with same name -- rare;
		 Taxon = TaxaFound[0];
		 }
	   else
		 Taxon = TaxaFound[0];
	   rv = true;
	   }
	 }
   return rv;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxComboBox12Click(TObject *Sender)
{
   if (ModifierType == MODELEMENT) {
	 if (VarLookup->ElementOpen()) {
	   UnicodeString TaxaGroup = cxComboBox12->Properties->Items->Strings[cxComboBox12->ItemIndex];
	   CurrentTaxaGroup = TaxaGroup;
	   vector<UnicodeString> Elements;
	   ElementLookup->GetElements(Datasets[DatasetNum].DatasetType, TaxaGroup, Elements);
	   cxCheckListBox1->Items->BeginUpdate();
	   cxCheckListBox1->Clear();
	   for (unsigned int i=0; i<Elements.size(); i++) {
		 TcxCheckListBoxItem* Item = cxCheckListBox1->Items->Add();
		 Item->Text = Elements[i];
		 }
	   cxCheckListBox1->Items->EndUpdate();
	   }
	 }
   else if (ModifierType == MODTAPH) {
	 UnicodeString System = cxComboBox12->Properties->Items->Strings[cxComboBox12->ItemIndex];
	 set<UnicodeString> Types;
	 TaphonomyLookup->GetTypes(TempTaphSystems->DatasetType, System, Types);
	 cxCheckListBox1->Items->Clear();
	 set<UnicodeString>::iterator itr;
	 cxCheckListBox1->Items->BeginUpdate();
	 int idx = -1;
	 for (unsigned int i=0; i<TempTaphSystems->Systems.size(); i++) {
	   if (SameText(TempTaphSystems->Systems[i].Name, System)) {
		 idx = i;
		 break;
		 }
	   }
	 for (itr = Types.begin(); itr != Types.end(); itr++) {
	   TcxCheckListBoxItem* Item = cxCheckListBox1->Items->Add();
	   Item->Text = *itr;
	   if (idx > -1)
		 Item->Checked = (TempTaphSystems->Systems[idx].Types.count(*itr) > 0);
	   else
		 Item->Checked = false;
	   }
	 cxCheckListBox1->Items->EndUpdate();
	 }
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::UpdatePublications(TcxCheckComboBox* CheckComboBox, vector<PUBLICATION*>& PubSubset)
{
   UnicodeString Description;

   CheckComboBox->Properties->Items->Clear();
   vector<PUBCITATION> PubList;

   // get initial list of publications
   for (int i=0; i<Publications->Count; i++) {
	 PUBLICATION *pubptr = (PUBLICATION*)Publications->Items[i];
	 PUBCITATION Pub(getPubShortDescription(pubptr), pubptr);
	 if (!Pub.Citation.IsEmpty())
	   PubList.push_back(Pub);
	 }

   // check for duplicates and add lowercase letters
   CheckDuplicateCitations(PubList);
   // now assign descriptions and pub pointers

   TcxCheckComboBoxItems* CheckComboBoxItems = CheckComboBox->Properties->Items;

   for (unsigned int i=0; i<PubList.size(); i++) {
	 TcxCheckComboBoxItem* Item = CheckComboBoxItems->AddCheckItem(PubList[i].Citation, PubList[i].Citation);
	 Item->Tag = (Longint)PubList[i].PubPtr;
	 }

   for (int i=0; i<CheckComboBox->Properties->Items->Count; i++) {
	 TcxCheckComboBoxItem* Item = CheckComboBox->Properties->Items->Items[i];
	 PUBLICATION *pub = (PUBLICATION*)Item->Tag;
	 for (unsigned int idx=0; idx<PubSubset.size(); idx++) {
	   if (PubSubset[idx] == pub) {
		 CheckComboBox->States[i] = cbsChecked;
		 break;
		 }
	   }
	 }
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::UpdatePublications(TcxCheckComboBoxItems* CheckComboBoxItems,
     TStringList* MasterPubList)
{
   UnicodeString Description;

   CheckComboBoxItems->Clear();
   MasterPubList->Clear();
   vector<PUBCITATION> PubList;

   // get initial list of publications
   for (int i=0; i<Publications->Count; i++) {
	 PUBLICATION *pubptr = (PUBLICATION*)Publications->Items[i];
	 PUBCITATION Pub(getPubShortDescription(pubptr), pubptr);
	 if (!Pub.Citation.IsEmpty())
	   PubList.push_back(Pub);
	 }

   // check for duplicates and add lowercase letters
   CheckDuplicateCitations(PubList);
   // now assign descriptions and pub pointers
   for (unsigned int i=0; i<PubList.size(); i++) {
	 CheckComboBoxItems->AddCheckItem(PubList[i].Citation, PubList[i].Citation);
	 MasterPubList->AddObject(PubList[i].Citation, (TObject*)PubList[i].PubPtr);
	 }
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::UpdatePublications(TcxCheckComboBoxItems* CheckComboBoxItems,
	 map<UnicodeString, PUBLICATION*>& MasterPubList)
{
   UnicodeString Description;

   CheckComboBoxItems->Clear();
   MasterPubList.clear();
   vector<PUBCITATION> PubList;

   // get initial list of publications
   for (int i=0; i<Publications->Count; i++) {
	 PUBLICATION *pubptr = (PUBLICATION*)Publications->Items[i];
	 PUBCITATION Pub(getPubShortDescription(pubptr), pubptr);
	 if (!Pub.Citation.IsEmpty())
	   PubList.push_back(Pub);
	 }

   // check for duplicates and add lowercase letters
   CheckDuplicateCitations(PubList);
   // now assign descriptions and pub pointers
   for (unsigned int i=0; i<PubList.size(); i++) {
	 CheckComboBoxItems->AddCheckItem(PubList[i].Citation, PubList[i].Citation);
	 MasterPubList[PubList[i].Citation] = PubList[i].PubPtr;
	 }
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::UpdatePublications(TStrings* ComboBoxItems,
	 map<UnicodeString, PUBLICATION*>& MasterPubList)
{
   UnicodeString Description;

   ComboBoxItems->Clear();
   MasterPubList.clear();
   vector<PUBCITATION> PubList;

   // get initial list of publications
   for (int i=0; i<Publications->Count; i++) {
	 PUBLICATION *pubptr = (PUBLICATION*)Publications->Items[i];
	 PUBCITATION Pub(getPubShortDescription(pubptr), pubptr);
	 if (!Pub.Citation.IsEmpty())
	   PubList.push_back(Pub);
	 }

   // check for duplicates and add lowercase letters
   CheckDuplicateCitations(PubList);
   // now assign descriptions and pub pointers
   for (unsigned int i=0; i<PubList.size(); i++) {
	 ComboBoxItems->Add(PubList[i].Citation);
	 MasterPubList[PubList[i].Citation] = PubList[i].PubPtr;
	 }
}
//---------------------------------------------------------------------------

UnicodeString __fastcall TTilSpreadSheetForm::getPubShortDescription(PUBLICATION* pub)
{
   UnicodeString Description;
   Description.SetLength(0);

   if (pub->pub_type == NOTSELECTED) return Description;

   AUTHOR Author;
   if (pub->AuthorList.size() == 1) {
	 Description = pub->AuthorList[0].LastName;
	 if (pub->pub_type == EDITEDBOOK)
	   Description += ", ed.";
	 Description += (" " + pub->PublicationYear);
	 }
   else if (pub->AuthorList.size() == 2) {
	 Description = pub->AuthorList[0].LastName + " and " + pub->AuthorList[1].LastName;
	 if (pub->pub_type == EDITEDBOOK)
	   Description += ", eds.";
	 Description += (" " + pub->PublicationYear);
	 }
   else if (pub->AuthorList.size() > 2) {
	 Description = pub->AuthorList[0].LastName + " et al.";
     if (pub->pub_type == EDITEDBOOK)
       Description += ", eds.";
     Description += (" " + pub->PublicationYear);
     }
   return Description;
}
//---------------------------------------------------------------------------

// For duplicate citations (of e.g. Smith, 1980) assigns a letter (e.g. Smith, 1980a)
void __fastcall TTilSpreadSheetForm::CheckDuplicateCitations(vector<PUBCITATION>& PubList)
{
   if (PubList.size() == 0) return;

   PUBLETTERS letters;
   for (unsigned int i=0; i<PubList.size()-1; i++) {
	 UnicodeString base = PubList[i].Citation;
	 for (unsigned int j=i+1, idx=1; j<PubList.size(); j++, idx++) {
	   if (SameText(PubList[j].Citation, base)) {
		 if (idx == 1)
		   PubList[i].Citation = base + letters.NextLetter();
		 PubList[j].Citation = base + letters.NextLetter();
		 }
	   }
	 }
}
//---------------------------------------------------------------------------

CONTACT* TTilSpreadSheetForm::NewContact(void)
{
   return NewContact(L"", L"");
}
//---------------------------------------------------------------------------

CONTACT* TTilSpreadSheetForm::NewContact(UnicodeString Name)
{
   UnicodeString FamilyName, Initials;
   int pos = Name.Pos(L",");
   if (pos > 0) {
	 FamilyName = Name.SubString(1,pos-1).Trim();
	 Initials = Name.Delete(1,pos).Trim();
	 }
   return NewContact(FamilyName, Initials);
}
//---------------------------------------------------------------------------

CONTACT* TTilSpreadSheetForm::NewContact(UnicodeString FamilyName, UnicodeString Initials)
{
   CONTACT* new_contact = NULL;
   CONTACT* old_contact;
   if (FamilyName.IsEmpty() && Initials.IsEmpty())
	 NewContactForm = new TNewContactForm(&new_contact, this);
   else
	 NewContactForm = new TNewContactForm(FamilyName, Initials, &new_contact, this);

   if (NewContactForm->ShowModal()== mrOk) {
	 if (new_contact != NULL) {
	   bool found = false;
	   for (int i=0; i<ContactList->Count; i++) {
		 old_contact = ContactList->Contacts[i];
		 if (SameText(old_contact->FamilyName, new_contact->FamilyName) &&
			 SameText(old_contact->LeadingInitials, new_contact->LeadingInitials)) {
		   found = true;
		   break;
		   }
		 }
	   if (found) {
		 *old_contact = *new_contact;
		 delete new_contact;
		 new_contact = old_contact;
		 }
	   else
		 ContactList->Add(new_contact);
	   }
	 }
   delete NewContactForm;
   return new_contact;
}
//---------------------------------------------------------------------------

// start Dataset tabsheet
void TTilSpreadSheetForm::FillDatasetMetaData(int dataset_num)
{
   if (Downloaded) {
	 AdvPanel9->Visible = true;
	 Label36->Caption = L"Neotoma DatesetID: " + IntToStr(Datasets[dataset_num].NeotomaDatasetID);
	 }

   cxComboBox13->Clear();
   cxComboBox13->Properties->Items->Clear();
   for (unsigned int i=0; i<Datasets.size(); i++)
	 cxComboBox13->Properties->Items->Add(Datasets[i].DatasetType);
   cxComboBox13->ItemIndex = cxComboBox13->Properties->Items->IndexOf(Datasets[dataset_num].DatasetType);

   cxCheckBox1->Checked = Datasets[dataset_num].IsSSamp;
   cxCheckBox4->Checked = Datasets[dataset_num].IsAggregate;
   cxComboBox14->ItemIndex = cxComboBox14->Properties->Items->IndexOf(Datasets[dataset_num].AggregateOrder);
   Edit15->Text = Datasets[dataset_num].Name;
   Memo2->Text = Datasets[dataset_num].Notes;
   UpdateContacts(cxCheckComboBox2, Datasets[dataset_num].Investigators);
   UpdateContacts(cxCheckComboBox9, Datasets[dataset_num].Processors);
   cxPopupEdit12->Text = Datasets[dataset_num].RepositoryText();
   UnicodeString pubs;
   for (unsigned int i=0; i<Datasets[dataset_num].Publications.size(); i++) {
	 PUBLICATION *pub = Datasets[dataset_num].Publications[i];
	 if (i > 0)
	   pubs += ";";
	 pubs += pub->GetShortCitation(false);
	 }
   cxPopupEdit1->Text = pubs;
}
//---------------------------------------------------------------------------

int TTilSpreadSheetForm::DatasetTabsheetNum(void)
{
   UnicodeString DatasetType = cxComboBox13->Text;
   for (unsigned int i=0; i<Datasets.size(); i++) {
	 if (SameText(DatasetType, Datasets[i].DatasetType))
	   return i;
	 }
   return 0;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxComboBox13PropertiesCloseUp(TObject *Sender)
{
   UnicodeString DatasetType = cxComboBox13->Properties->Items->Strings[cxComboBox13->ItemIndex];
   for (unsigned int i = 0; i < Datasets.size(); i++) {
	 if (SameText(DatasetType, Datasets[i].DatasetType)) {
	   FillDatasetMetaData(i);
	   return;
	   }
	 }
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::Edit15Exit(TObject *Sender)
{
   Datasets[DatasetTabsheetNum()].Name = Edit15->Text;
}
//---------------------------------------------------------------------------

// investigators
void __fastcall TTilSpreadSheetForm::cxCheckComboBox2PropertiesInitPopup(
	  TObject *Sender)
{
   UpdateContacts(cxCheckComboBox2, Datasets[DatasetTabsheetNum()].Investigators);
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxCheckComboBox2PropertiesPopup(
	  TObject *Sender)
{
   cxButton21->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxCheckComboBox2PropertiesCloseUp(
	  TObject *Sender)
{
   int dataset_num = DatasetTabsheetNum();
   Datasets[dataset_num].Investigators.clear();
   for (int i=0; i<cxCheckComboBox2->Properties->Items->Count; i++) {
	 if (cxCheckComboBox2->States[i] == cbsChecked) {
	   TcxCheckComboBoxItem* Item = cxCheckComboBox2->Properties->Items->Items[i];
	   CONTACT* Contact = (CONTACT*)Item->Tag;
	   Datasets[dataset_num].Investigators.push_back(Contact);
	   }
	 }
   cxButton21->Visible = false;
}
//---------------------------------------------------------------------------

// new contact for investigator
void __fastcall TTilSpreadSheetForm::cxButton21Click(TObject *Sender)
{
   int ItemIndex = cxCheckComboBox2->ItemIndex;
   if (NewContact())
	 UpdateContacts(cxCheckComboBox2, Datasets[DatasetTabsheetNum()].Investigators);
   FocusControl(cxCheckComboBox2);
   cxCheckComboBox2->DroppedDown = true;
   cxCheckComboBox2->ItemIndex = ItemIndex;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxCheckComboBox10PropertiesInitPopup(TObject *Sender)
{
   UpdateContacts(cxCheckComboBox10, GeochronDataset.Investigators);
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxCheckComboBox10PropertiesCloseUp(TObject *Sender)
{
   UnicodeString msg;
   set<int> OldContactIDs;
   set<int> NewContactIDs;

   bool update = (Downloaded && tiLicense->Type() == verNEOTOMASTEWARD);

   if (GeochronDataset.Investigators.size() > 0 && update) {
	 for (unsigned int i = 0; i < GeochronDataset.Investigators.size(); i++)
	   OldContactIDs.insert(GeochronDataset.Investigators[i]->NeotomaContactID);
	 }

   GeochronDataset.Investigators.clear();
   for (int i=0; i<cxCheckComboBox10->Properties->Items->Count; i++) {
	 if (cxCheckComboBox10->States[i] == cbsChecked) {
	   TcxCheckComboBoxItem* Item = cxCheckComboBox10->Properties->Items->Items[i];
	   CONTACT* Contact = (CONTACT*)Item->Tag;
	   GeochronDataset.Investigators.push_back(Contact);
	   if (update)
		 NewContactIDs.insert(Contact->NeotomaContactID);
	   }
	 }

   if (update && NewContactIDs != OldContactIDs) {
	 msg = L"Update investigators in Neotoma?";
	 if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes)
	   UpdateGeochronPIs(NewContactIDs);
	 }
}
//---------------------------------------------------------------------------

// data processors
void __fastcall TTilSpreadSheetForm::cxCheckComboBox9PropertiesInitPopup(TObject *Sender)
{
   UpdateContacts(cxCheckComboBox9, Datasets[DatasetTabsheetNum()].Processors);
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxCheckComboBox9PropertiesPopup(TObject *Sender)
{
   cxButton22->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxCheckComboBox9PropertiesCloseUp(TObject *Sender)
{
   for (unsigned int i=0; i<Datasets.size(); i++) {
	 Datasets[i].Processors.clear();
	 for (int j=0; j<cxCheckComboBox9->Properties->Items->Count; j++) {
	   if (cxCheckComboBox9->States[j] == cbsChecked) {
		 TcxCheckComboBoxItem* Item = cxCheckComboBox9->Properties->Items->Items[j];
		 CONTACT* Contact = (CONTACT*)Item->Tag;
		 Datasets[i].Processors.push_back(Contact);
		 }
	   }
	 }
   cxButton22->Visible = false;
}
//---------------------------------------------------------------------------

// new contact for data processor
void __fastcall TTilSpreadSheetForm::cxButton22Click(TObject *Sender)
{
   int ItemIndex = cxCheckComboBox9->ItemIndex;
   if (NewContact())
	 UpdateContacts(cxCheckComboBox9, Datasets[DatasetTabsheetNum()].Processors);
   FocusControl(cxCheckComboBox9);
   cxCheckComboBox9->DroppedDown = true;
   cxCheckComboBox9->ItemIndex = ItemIndex;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxCheckBox1Click(TObject *Sender)
{
   if (PageControl2->ActivePage != TabSheetDataset)
	 return;
   if (!cxCheckBox1->Focused())
	 return;

   set<UnicodeString> Keywords;
   set<UnicodeString>::iterator itr;

   int DatasetNo = DatasetTabsheetNum();
   Datasets[DatasetNo].IsSSamp = cxCheckBox1->Checked;

   // find keyword row
   pair<int,int> DatasetRows;  // top (header row), bottom
   GetDatasetRows(DatasetNo,DatasetRows);
   int KeywordRow = 0;
   for (int row=DatasetRows.first; row<=DatasetRows.second; row++) {
	 UnicodeString Code = ProfGrid1->AbsoluteCells[1][row]->Text;
	 if (SameText(Code,L"#Samp.Keywords")) {
	   KeywordRow = row;
	   break;
	   }
	 }

   // find sample column (TopCol) with minumum depth
   int TopCol = GetColMinDepth();
   if (TopCol == 0)
	 return;

   if (KeywordRow > 0) {
	 UnicodeString KeywordList = ProfGrid1->AbsoluteCells[TopCol][KeywordRow]->Text;
	 if (!KeywordList.IsEmpty())
	   ParsePartsIC(KeywordList, L";", Keywords);
	 }

   if (cxCheckBox1->Checked) {
	 if (KeywordRow == 0) {  // keyword row doesn't exist
	   for (int row=DatasetRows.first; row<=DatasetRows.second; row++) {
		 UnicodeString Code = ProfGrid1->AbsoluteCells[1][row]->Text;
		 if (Code[1] != L'#') {
		   KeywordRow = row;
		   break;
		   }
		 }
	   if (KeywordRow == 0)
		 KeywordRow = DatasetRows.second + 1;
	   if (KeywordRow <= AbsContentRowCount(ProfGrid1))
		 ProfGrid1->InsertRow(KeywordRow);
	   ProfGrid1->AbsoluteCells[1][KeywordRow]->Value = WideString("#Samp.Keywords");
	   ProfGrid1->AbsoluteCells[2][KeywordRow]->Value = WideString("Sample Keywords");
	   }
	 if (Keywords.size() == 0)
	   Keywords.insert(L"modern");
	 else {
	   if (Keywords.count(L"modern") == 0) // modern keyword does not exist
		 Keywords.insert(L"modern");
	   }
	 }
   else if (KeywordRow > 0) {   // IsSSamp unchecked && keyword row exists && min depth col exists
	 if (Keywords.size() > 0) {
	   itr = Keywords.find(L"modern");
	   if (itr != Keywords.end())   // modern keyword exists
		 Keywords.erase(itr);
	   }
	 }

   UnicodeString CellText;
   if (Keywords.size() > 0) {
	 for (itr = Keywords.begin(); itr != Keywords.end(); itr++) {
	   if (!CellText.IsEmpty())
		 CellText += L";";
	   CellText += *itr;
	   }
	 }
   ProfGrid1->AbsoluteCells[TopCol][KeywordRow]->Value = WideString(CellText);
}
//---------------------------------------------------------------------------

int TTilSpreadSheetForm::GetColMinDepth(void)
{
   // returns 0 if no depths entered, otherwise returns absolute cell column
   int TopCol = 0;
   int ColCount = AbsContentColCount(ProfGrid1);
   int StartCol = AbsHeaderColCount(ProfGrid1);
   double mindepth;
   double depth;
   for (int col=StartCol; col<=ColCount; col++) {
	 UnicodeString DepthStr = ProfGrid1->AbsoluteCells[col][1]->Text;
	 if (!DepthStr.IsEmpty()) {
	   if (TryStrToFloat(DepthStr,depth)) {
		 if (TopCol == 0) {
		   mindepth = depth;
		   TopCol = col;
		   }
		 else if (depth < mindepth) {
		   mindepth = depth;
		   TopCol = col;
		   }
		 }
	   }
	 }
   return TopCol;
}
//---------------------------------------------------------------------------

// aggregate dataset checkbox
void __fastcall TTilSpreadSheetForm::cxCheckBox4Click(TObject *Sender)
{
  if (cxCheckBox4->Checked) {
	Datasets[DatasetTabsheetNum()].IsAggregate = true;
	cxGroupBox4->Style->BorderStyle = ebsSingle;
	Label22->Caption = L"Aggregate Dataset Name:";
	Label35->Visible = true;
	cxComboBox14->Visible = true;
	}
  else {
	Datasets[DatasetTabsheetNum()].IsAggregate = false;
	cxGroupBox4->Style->BorderStyle = ebsNone;
	Label22->Caption = L"Dataset Name:";
	Label35->Visible = false;
	cxComboBox14->Visible = false;
	}
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::cxComboBox14Click(TObject *Sender)
{
   Datasets[DatasetTabsheetNum()].AggregateOrder = cxComboBox14->Properties->Items->Strings[cxComboBox14->ItemIndex];
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::Memo2Exit(TObject *Sender)
{
   Datasets[DatasetTabsheetNum()].Notes = Memo2->Text;
}
//---------------------------------------------------------------------------

void __fastcall TTilSpreadSheetForm::PasteGrid(TcxCustomGridTableView *Grid)
{
   UnicodeString Text;
   UnicodeString RecordText, ItemText;
   int posi, posr;
   Variant Value;
   double dValue;
   __int64 iValue;
   bool bValue;
   TDateTime dateValue;
   UnicodeString aValue;
   bool updating = false;

   // first get current cell location, number of records, and number of items
   int FocusedRecordIndex = Grid->Controller->FocusedRecordIndex;
   int FocusedItemIndex = Grid->Controller->FocusedItemIndex;
   unsigned int RecordCount = Grid->DataController->RecordCount;
   unsigned int ItemCount = Grid->ItemCount;

   Clipboard()->Open();
   try
   {
     try
     {
       int TextHandle = Clipboard()->GetAsHandle(CF_TEXT);
       char *pText = (char *)GlobalLock((HGLOBAL)TextHandle);
       Text = pText;
       GridPaste = pText;
       GlobalUnlock((HGLOBAL)TextHandle);

	   Text = Text.Trim();
	   if (!Text.IsEmpty()) {
		   // parse values from clipboard to array of variants
           vector< vector<Variant> > PasteCells;
           int nrec = 0;
		   while ((posr = Text.Pos("\r\n")) > 0) {
             RecordText = Text.SubString(1, posr-1);
             PasteCells.resize(++nrec);
             while ((posi = RecordText.Pos("\t")) > 0) {
               ItemText = RecordText.SubString(1, posi-1);
			   Value = ItemText;
               if (ItemText.IsEmpty())
				 Value.ChangeType(varEmpty);
               PasteCells.at(nrec-1).push_back(Value);
               RecordText = RecordText.SubString(posi+1, RecordText.Length()-posi);
               }
             if (RecordText.Length() > 0) {
			   Value = RecordText;
               PasteCells.at(nrec-1).push_back(Value);
               }
             Text = Text.SubString(posr+2, Text.Length()-posr);
             }
           if (Text.Length() > 0) {
             RecordText = Text;
             PasteCells.resize(++nrec);
             while ((posi = RecordText.Pos("\t")) > 0) {
               ItemText = RecordText.SubString(1, posi-1);
               Value = ItemText;
               if (ItemText.IsEmpty())
                 Value.ChangeType(varEmpty);
               PasteCells.at(nrec-1).push_back(Value);
               RecordText = RecordText.SubString(posi+1, RecordText.Length()-posi);
               }
             if (RecordText.Length() > 0) {
               Value = RecordText;
               PasteCells.at(nrec-1).push_back(Value);
               }
             Text = Text.SubString(posr+2, Text.Length()-posr);
             }

           // check for value type incompatibilies
           TcxCustomGridTableItem* ErrorColumn = NULL;
           for (unsigned int row=0, rec=FocusedRecordIndex; row<PasteCells.size(); row++, rec++) {
			 unsigned int item = FocusedItemIndex;
             unsigned int it = 0;
             while (it < item) {
               if (!Grid->Items[it++]->Visible)
                 item++;
               }
             for (unsigned int col=0; col<PasteCells.at(row).size(); col++) {
               //while (!Grid->Items[item]->Visible && item < ItemCount)
               //  item++;
               while (item < ItemCount && !Grid->Items[item]->Visible)
                 item++;
               if (item >= ItemCount) break;
			   UnicodeString ValueType = Grid->Items[item]->DataBinding->ValueType;
			   Value = PasteCells.at(row).at(col);
			   if (!Value.IsEmpty()) {
                 aValue = Value;
				 if (SameText(ValueType, L"Float")) {
                   if (aValue.IsEmpty())
					 Value.Clear();
				   else if (TryStrToFloat(aValue, dValue))
					 Value.ChangeType(varDouble);
                   else
                     ErrorColumn = Grid->Items[item];
                   }
                 else if (SameText(ValueType, L"Integer")) {
                   if (aValue.IsEmpty())
                     Value.Clear();
                   else if (TryStrToInt64(aValue, iValue))
                     Value.ChangeType(varInt64);
                   else
                     ErrorColumn = Grid->Items[item];
                   }
                 else if (SameText(ValueType, L"Boolean")) {
                   if (aValue.IsEmpty())
                     Value.Clear();
                   else if (TryStrToBool(aValue, bValue))
                     Value.ChangeType(varBoolean);
                   else
                     ErrorColumn = Grid->Items[item];
                   }
                 else if (SameText(ValueType, L"DateTime")) {
                   if (aValue.IsEmpty())
                     Value.Clear();
                   else if (TryStrToDate(aValue, dateValue))
                     Value.ChangeType(varDate);
                   else
                     ErrorColumn = Grid->Items[item];
                   }
                 if (ErrorColumn) break;
                 }
               PasteCells.at(row).at(col) = Value;
               item++;
               }
             if (ErrorColumn) {
               Grid->Controller->EditingController->HideEdit(false);
               MessageDlg("Paste value \"" + Value + "\" incompatible in \"" +
                          ErrorColumn->Caption + "\" column." , Dialogs::mtError,
                          TMsgDlgButtons() << mbOK, 0);
               break;
               }
             }

           // copy values to grid
		   TcxRowInfo RowInfo;
		   int reci;
		   if (!ErrorColumn) {
			 Grid->BeginUpdate();
			 updating = true;
			 for (unsigned int row=0, rec=FocusedRecordIndex; row<PasteCells.size(); row++, rec++) {
			   if (FocusedRecordIndex == -1)
				 reci = Grid->DataController->AppendRecord();
			   else if (rec < RecordCount) {
				 RowInfo = Grid->DataController->GetRowInfo(rec);
				 reci = RowInfo.RecordIndex;
				 }
			   else
				 reci = Grid->DataController->AppendRecord();
			   unsigned int item = FocusedItemIndex;
			   unsigned int it = 0;
			   while (it < item) {
				 if (!Grid->Items[it++]->Visible)
				   item++;
				 }
			   for (unsigned int col=0; col<PasteCells.at(row).size(); col++) {
				 while (item < ItemCount && !Grid->Items[item]->Visible) item++;
				 if (item >= ItemCount) break;
				 Value = PasteCells.at(row).at(col);
				 Grid->DataController->SetValue(reci, item++, Value);
				 }
               }
             if (FocusedRecordIndex == -1)
               Grid->Controller->EditingController->HideEdit(false);
             Grid->EndUpdate();
             updating = false;
			 }
           else
             GridPaste.SetLength(0);
           }
		 }
     catch (...)
     {
     if (updating) {
       Grid->EndUpdate();
       updating = false;
       }
     }
   }
   __finally
   {
     if (updating)
	   Grid->EndUpdate();
     Clipboard()->Close();
   }
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::AddCellObject(TProfGridCell* ACell, CELLOBJECT* CellObject)
{
   ACell->CellObject = (TObject*)CellObject;
   CellObjects.push_back(CellObject);

   switch (CellObject->ObjectType) {
	 case CELLSPECIMENS:
	   ACell->Color = (TColor)RGB(255, 204, 204);
	   break;
	 case CELLTAXONNOTES:
	   AddTaxonNotesIcon(ACell);
	   break;
	 }
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::DeleteCellObject(TProfGridCell* ACell)
{
   TList* Specimens;
   bool specimen_link = false;

   if (ACell->CellObject == NULL)
	 return;

   CELLOBJECT* CellObject = (CELLOBJECT*)ACell->CellObject;

   switch (CellObject->ObjectType) {
	 case CELLSPECIMENS:
	   ACell->Color = clWindow;
	   Specimens = (TList*)CellObject->Object;
	   for (int i=0; i<Specimens->Count; i++) {
		 SPECIMEN* Specimen = (SPECIMEN*)Specimens->Items[i];
		 if (DeleteGeochronLink(Specimen))
		   specimen_link = true;
		 }
	   if (specimen_link) {
		 UnicodeString msg = L"Specimen link to dated taxon under Geochronology tab deleted.";
		 MessageDlg(msg, mtWarning, TMsgDlgButtons() << mbOK, 0);
		 }
	   break;
	 case CELLTAXONNOTES:
	   ACell->Graphic = NULL;
	   break;
	 }

   CellObjects.remove(CellObject);
   delete CellObject;
   ACell->CellObject = NULL;
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::AddTaxonNotesIcon(TProfGridCell* ACell)
{
   Graphics::TBitmap *IdentifiedAsBmp = new Graphics::TBitmap;
   cxImageList1->GetBitmap(45,IdentifiedAsBmp);
   IdentifiedAsBmp->Transparent = true;
   ACell->GraphicAlignment = taRightJustify;
   ACell->GraphicLayout = tlTop;
   ACell->Graphic = IdentifiedAsBmp;
   delete IdentifiedAsBmp;
}
//---------------------------------------------------------------------------

bool TTilSpreadSheetForm::HasGeochronLink(SPECIMEN* Specimen)
{
   for (int i=0; i<GeochronList->Count(); i++) {
	 GEOCHRON Date = GeochronList->Dates[i];
	 for (unsigned int j=0; j<Date.TaxaDated.size(); j++) {
	   if (Date.TaxaDated[j].Specimen == Specimen)
		 return true;
	   }
	 }
   return false;
}
//---------------------------------------------------------------------------

bool TTilSpreadSheetForm::DeleteGeochronLink(SPECIMEN* Specimen)
{
   bool rv = false;
   for (int i=0; i<GeochronList->Count(); i++) {
	 GEOCHRON Date = GeochronList->Dates[i];
	 for (unsigned int j=0; j<Date.TaxaDated.size(); j++) {
	   if (Date.TaxaDated[j].Specimen == Specimen) {
		 Date.TaxaDated[j].UserSpecID = L"";
         Date.TaxaDated[j].Specimen = NULL;
		 rv = true;
		 }
	   }
	 }
   return rv;
}
//---------------------------------------------------------------------------

