//---------------------------------------------------------------------------
#include <vcl.h>
#include "pch.h"

#pragma hdrstop

#include "TNValSpc.h"
#ifndef TIUploadH
#include "TIUpload.h"
#endif
#ifndef TICommonH
#include "TICommon.h"
#endif

//---------------------------------------------------------------------------

#pragma package(smart_init)

bool TNeotomaUploadForm::ValidateSpecimens(void)
{
   map<int,UnicodeString> element_types;
   map<int,UnicodeString> symmetries;
   map<int,UnicodeString> portions;
   map<int,UnicodeString> maturities;
   map<int,UnicodeString> sex_types;
   map<int,UnicodeString> domestic_status_types;
   map<int,UnicodeString> repositories;
   map<int,map<int,UnicodeString> > TaphTypes;  // SystemID, <TypeID, Type>

   UnicodeString msg;
   bool lookup = false;
   int ID;
   int nspec = 0;
   // set<SPECIMEN*> all_specimens;

   // validate specimens
   list<CELLOBJECT*>::iterator itr;
   for (itr = TSSForm->CellObjects.begin(); itr != TSSForm->CellObjects.end(); itr++) {
	 if ((*itr)->ObjectType == CELLSPECIMENS) {
	   TList* Specimens = (TList*)(*itr)->Object;
	   if (Specimens->Count > 0) {
		 if (!lookup) {
		   lookup = GetSpecimenLookupItems(element_types, symmetries, portions,
					maturities, sex_types, domestic_status_types, repositories);
		   if (!lookup)
			 return false;
		   else
			 lookup = true;
		   }
		 for (int i=0; i<Specimens->Count; i++) {
		   SPECIMEN *Specimen = (SPECIMEN*)Specimens->Items[i];
		   all_specimens.insert(Specimen);
		   if (Validate(Specimen->Element, element_types, ID))
			 Specimen->NeotomaElementID = ID;
		   else {
			 OutputError(SpecimenErrMsg(*itr, L"Invalid specimen element «" + Specimen->Element + L"»"));
			 return false;
			 }

		   if (Validate(Specimen->Symmetry, symmetries, ID))
			 Specimen->NeotomaSymmetryID = ID;
		   else {
			 OutputError(SpecimenErrMsg(*itr, L"Invalid specimen symmetry «" + Specimen->Symmetry + L"»"));
			 return false;
			 }

		   if (Validate(Specimen->Portion, portions, ID))
			 Specimen->NeotomaPortionID = ID;
		   else {
			 OutputError(SpecimenErrMsg(*itr, L"Invalid specimen portion «" + Specimen->Portion + L"»"));
			 return false;
			 }

		   if (Validate(Specimen->Maturity, maturities, ID))
			 Specimen->NeotomaMaturityID = ID;
		   else {
			 OutputError(SpecimenErrMsg(*itr, L"Invalid specimen maturity «" + Specimen->Maturity + L"»"));
			 return false;
			 }

		   if (Validate(Specimen->Sex, sex_types, ID))
			 Specimen->NeotomaSexID = ID;
		   else {
			 OutputError(SpecimenErrMsg(*itr, L"Invalid specimen sex «" + Specimen->Sex + L"»"));
			 return false;
			 }

		   if (Validate(Specimen->DomesticStatus, domestic_status_types, ID))
			 Specimen->NeotomaDomesticStatusID = ID;
		   else {
			 OutputError(SpecimenErrMsg(*itr, L"Invalid specimen domestic status «" + Specimen->DomesticStatus + L"»"));
			 return false;
			 }

		   if (Validate(Specimen->Repository, repositories, ID))
			 Specimen->NeotomaRepositoryID = ID;
		   else {
			 OutputError(SpecimenErrMsg(*itr, L"Invalid specimen repository «" + Specimen->Repository + L"»"));
			 return false;
			 }

		   if (!Specimen->NISP.IsEmpty()) {
			 if (VarIsNumeric(Specimen->NISP)) {
			   double NISP = Specimen->NISP;
			   if (NISP < 0) {
				 OutputError(SpecimenErrMsg(*itr, L"Invalid specimen NISP value (<0) «" + Specimen->NISP + L"»"));
				 return false;
				 }
			   }
			 else {
			   OutputError(SpecimenErrMsg(*itr, L"Invalid specimen NISP value «" + Specimen->NISP + L"»"));
			   return false;
			   }
			 }

		   if (Specimen->Taphonomy.size() > 0) {
			 if (!ValidateSpecimenTaphonomy(Specimen, TaphTypes))
			   return false;
			 }

		   nspec++;
		   }
		 }
	   }
	 }

   if (nspec > 0) {
	 msg = IntToStr(nspec);
	 msg += L" specimen";
	 if (nspec > 1) msg += L"s";
	 msg += L" validated.";
	 }
   else
	 msg = L"No specimen data.";
   OutputLine(msg);

   // Check that Tilia specimen IDs in Geochronology tab are in spreadsheet
   int gspec = 0;
   bool error = false;
   for (int i=0; i<TSSForm->GeochronList->Count(); i++) {
	 GEOCHRON* Date = &TSSForm->GeochronList->Dates[i];
	 if (Date->TaxaDated.size() > 0) {
	   for (unsigned int j = 0; j < Date->TaxaDated.size(); j++) {
		 // if there are specimens, check if a Carbon-14 date is not linked to a specimen
		 if (nspec > 0 && Date->TaxaDated[j].Specimen == NULL && SameText(Date->Method, L"Carbon-14")) {
		   msg = L"WARNING: Specimens exist in spreadsheet, but for Carbon-14 date " +
				 DateDescript(Date) + L", specimen «" + Date->TaxaDated[j].Taxon +
				 L"» is not linked to a specimen.";
		   OutputWarning(msg);
		   }
		 else if (Date->TaxaDated[j].Specimen != NULL) {
		   // check that Specimen still occurs in spreadsheet
		   if (all_specimens.count(Date->TaxaDated[j].Specimen) == 0) {
			 error = true;
			 msg = L"ERROR: Specimen for date " + DateDescript(Date) + L", taxon «" +
				   Date->TaxaDated[j].Taxon + L"» does not occur in the spreadsheet.";
			 OutputError(msg);
			 }
		   else
			 gspec++;
		   }
		 }
	   }
	 }

   if (!error && gspec > 0) {
	 msg = IntToStr(gspec);
	 msg += L" specimen";
	 if (gspec > 1) msg += L"s";
	 msg += L" linked to geochronological measurements validated.";
	 OutputLine(msg);
	 }

   return true;
}
//---------------------------------------------------------------------------

bool TNeotomaUploadForm::ValidateSpecimenTaphonomy(SPECIMEN* Specimen,
	map<int,map<int,UnicodeString> >& TaphTypes)
{
   UnicodeString msg;

   TAPHONOMICSYSTEM& Taphonomy = Specimen->Taphonomy;

   if (NeotomaTaphSystems.size() == 0) {
	 NeotomaTaphonomicSystemsTable TaphonomicSystems(ipsJSONS1, TcpClient1);
	 StatusBar1->SimpleText = TaphonomicSystems.WebServiceName();
	 if (!TaphonomicSystems.Execute())
	   return false;
	 else
	   NeotomaTaphSystems = TaphonomicSystems.Items;
	 }

   if (NeotomaTaphDatasetTypes.size() == 0) {
	 NeotomaTaphonomicSystemsDatasetTypesTable DatasetTypeSystems(ipsJSONS1, TcpClient1);
	 StatusBar1->SimpleText = DatasetTypeSystems.WebServiceName();
	 if (!DatasetTypeSystems.Execute())
	   return false;
	 else
	   NeotomaTaphDatasetTypes = DatasetTypeSystems.Items;
	 }

   TAPHONOMICSYSTEM::iterator itr;
   for (itr = Taphonomy.begin(); itr != Taphonomy.end(); itr++) {
	 UnicodeString System = itr->first;
	 int SystemID = -1;
	 for (unsigned int i = 0; i < NeotomaTaphSystems.size(); i++) {
	   if (SameText(System, NeotomaTaphSystems[i].TaphonomicSystem)) {
		 SystemID = NeotomaTaphSystems[i].TaphonomicSystemID;
		 break;
		 }
	   }
	 if (SystemID == -1) {  // this should never happen, but..
	   msg = L"ERROR: Taphonomic system «" + System + L"» for specimen not found in Neotoma TaphonomicSystems table.";
	   OutputError(msg);
	   return false;
	   }

	 if (TaphTypes.count(SystemID) == 0) {
	   NeotomaTaphonomicTypesBySystem NeotomaTaphTypes(ipsJSONS1, TcpClient1);
	   StatusBar1->SimpleText = NeotomaTaphTypes.WebServiceName();
	   NeotomaTaphTypes.AddParam(L"TAPHONOMICSYSTEMID", SystemID);
	   if (!NeotomaTaphTypes.Execute())
		 return false;
	   for (unsigned int i = 0; i < NeotomaTaphTypes.Size(); i++)
		 TaphTypes[SystemID][NeotomaTaphTypes.Items[i].TaphonomicTypeID] = NeotomaTaphTypes.Items[i].TaphonomicType;
	   }

	 set<UnicodeString>& Types = itr->second;
	 set<UnicodeString>::iterator tit1;
	 for (tit1 = Types.begin(); tit1 != Types.end(); tit1++) {
	   int TypeID = -1;
	   map<int,UnicodeString>::iterator tit2;
	   for (tit2 = TaphTypes[SystemID].begin(); tit2 != TaphTypes[SystemID].end(); tit2++) {
		 if (SameText(*tit1,tit2->second)) {
		   TypeID = tit2->first;
		   break;
		   }
		 }
	   if (TypeID == -1) {  // this should never happen, but..
		 msg = L"ERROR: Taphonomic type «" + *tit1 + L"» for specimen not found in Neotoma TaphonomicSystems table.";
		 OutputError(msg);
		 return false;
		 }
	   Specimen->NeotomaTaphonomy.insert(TypeID);
	   }

	 }


   return true;
}
//---------------------------------------------------------------------------

bool TNeotomaUploadForm::GetSpecimenLookupItems(map<int,UnicodeString>& element_types,
	map<int,UnicodeString>& symmetries, map<int,UnicodeString>& portions,
	map<int,UnicodeString>& maturities, map<int,UnicodeString>& sex_types,
	map<int,UnicodeString>& domestic_status_types, map<int,UnicodeString>& repositories)
{
   NeotomaElementTypesTable ElementTypes(ipsJSONS1, TcpClient1);
   StatusBar1->SimpleText = ElementTypes.WebServiceName();
   if (ElementTypes.Execute())
	 element_types = ElementTypes.Items;
   else
	 return false;

   NeotomaElementSymmetriesTable Symmetries(ipsJSONS1, TcpClient1);
   StatusBar1->SimpleText = Symmetries.WebServiceName();
   if (Symmetries.Execute())
	 symmetries = Symmetries.Items;
   else
	 return false;

   NeotomaElementPortionsTable Portions(ipsJSONS1, TcpClient1);
   StatusBar1->SimpleText = Portions.WebServiceName();
   if (Portions.Execute())
	 portions = Portions.Items;
   else
	 return false;

   NeotomaElementMaturitiesTable Maturities(ipsJSONS1, TcpClient1);
   StatusBar1->SimpleText = Maturities.WebServiceName();
   if (Maturities.Execute())
	 maturities = Maturities.Items;
   else
	 return false;

   NeotomaSpecimenSexTypes SexTypes(ipsJSONS1, TcpClient1);
   StatusBar1->SimpleText = SexTypes.WebServiceName();
   if (SexTypes.Execute())
	 sex_types = SexTypes.Items;
   else
	 return false;

   NeotomaSpecimenDomStatTypes DomStatTypes(ipsJSONS1, TcpClient1);
   StatusBar1->SimpleText = DomStatTypes.WebServiceName();
   if (DomStatTypes.Execute())
	 domestic_status_types = DomStatTypes.Items;
   else
	 return false;

   NeotomaRepositoryInstitutionsTable Repositories(ipsJSONS1, TcpClient1);
   StatusBar1->SimpleText = Repositories.WebServiceName();
   if (Repositories.Execute()) {
	 for (unsigned int i = 0; i < Repositories.Size(); i++)
	   repositories[Repositories.Items[i].RepositoryID] = Repositories.Items[i].Repository;
	 }
   else
	 return false;

   return true;
}
//---------------------------------------------------------------------------

bool TNeotomaUploadForm::Validate(UnicodeString Item, map<int,UnicodeString>& Items, int& ID)
{
   if (Item.IsEmpty()) {
	 ID = -1;
	 return true;
	 }

   map<int,UnicodeString>::iterator itr;
   for (itr = Items.begin(); itr != Items.end(); itr++) {
	 if (SameText(Item, itr->second)) {
	   ID = itr->first;
	   return true;
	   }
	 }
   return false;
}
//---------------------------------------------------------------------------

UnicodeString TNeotomaUploadForm::SpecimenErrMsg(CELLOBJECT* CellObject, UnicodeString ErrMsg)
{
   UnicodeString msg = L"ERROR: " + ErrMsg;

   bool found = false;
   int StartCol = TSSForm->AbsHeaderColCount(TSSForm->ProfGrid1);
   int EndCol = TSSForm->AbsContentColCount(TSSForm->ProfGrid1);
   int StartRow = TSSForm->AbsHeaderRowCount(TSSForm->ProfGrid1);
   int EndRow = TSSForm->AbsContentRowCount(TSSForm->ProfGrid1);
   for (int col=StartCol; col<=EndCol; col++) {
	 for (int row=StartRow; row<=EndRow; row++) {
	   TProfGridCell* ACell = TSSForm->ProfGrid1->AbsoluteCells[col][row];
	   if (ACell->CellObject == (TObject*)CellObject) {
		 msg += (L" in cell " + ACell->A1Name + L".");
		 found = true;
		 break;
		 }
	   }
	 if (found) break;
	 }
   return msg;
 }
 //---------------------------------------------------------------------------

