//---------------------------------------------------------------------------

#define VCL_IOSTREAM
#include <vcl.h>
//#include "pch.h"
#pragma hdrstop

#include <algorithm>
#include <time.h>

#include "TItlxout.h"
#ifndef TIGlobalsH
#include "TIGlobals.h"
#endif
#ifndef TGUtilsH
#include "TGUtils.h"
#endif
#ifndef TIXMLH
#include "TIXML.h"
#endif
#ifndef TIPubH
#include "TIPub.h"
#endif
#ifndef TISpecH
#include "TISpec.h"
#endif
#ifndef TICommonH
#include "TICommon.h"
#endif

//---------------------------------------------------------------------------

#pragma package(smart_init)

WriteTLX::WriteTLX(UnicodeString& fName, TTilSpreadSheetForm *tSpread)
{
  FileName = fName;
  TSSForm = tSpread;
  PBar = NULL;
}
//---------------------------------------------------------------------------

bool WriteTLX::WriteFile(void)
{
  Variant Value;
  CURRENTVERSION CurrentVersion;
  PUBTYPEDEFS PubTypeDefs;
  int NewSpecID = 1;
  map<int,int> NewSpecIDs;  // old SpecimenID, new SpecimenID

  cList = new TStringList();    // alphabatized contact list
  cList->CaseSensitive = false;
  TStringList *pList = new TStringList();    // alphabatized publication list
  pList->CaseSensitive = false;
  xmlout = new WriteXML(FileName);
  Screen->Cursor = crHourGlass;

  try
	{
	xmlout->Declaration("1.0", "UTF-8", "yes");
	xmlout->DateTime();
	xmlout->BeginTag("TiliaFile");

	UnicodeString FileName = ExtractFileName(Application->ExeName);
	int pos;
    if ((pos = FileName.Pos(".")) > 0)  // get rid of extension
      FileName.SetLength(pos-1);
	xmlout->BeginTag("Version");
	xmlout->Element("Application", FileName);
	xmlout->Element("MajorVersion", CurrentVersion.MajorVersion());
	xmlout->Element("MinorVersion", CurrentVersion.MinorVersion());
	xmlout->Element("Release", CurrentVersion.ReleaseNo());
	xmlout->EndTag("Version");

	// Contacts
	if (TSSForm->ContactList->Count) {
	  xmlout->BeginTag("Contacts");
	  UnicodeString Address;
      UnicodeString AddressLine;

	  for (int i=0; i<TSSForm->ContactList->Count; i++) {
		CONTACT *Contact = TSSForm->ContactList->Contacts[i];
		Contact->FormatContactName();
		try { cList->AddObject(Contact->FullContactName, (TObject*)Contact); }
		catch(...) {  }
		}
	  cList->CustomSort(NeotomaCompare);

	  for (int i=0; i<cList->Count; i++) {
		xmlout->BeginTag("Contact", "ID", i+1);
		CONTACT *Contact = (CONTACT*)cList->Objects[i];
		xmlout->Element("NeotomaContactID", Contact->NeotomaContactID);
		xmlout->Element("NeotomaAliasID", Contact->NeotomaAliasID);
		xmlout->Element("FullContactName", Contact->FullContactName);
		xmlout->Element("ShortContactName", Contact->ShortContactName);
		xmlout->Element("FamilyName", Contact->FamilyName);
		xmlout->Element("GivenNames", Contact->GivenNames);
		xmlout->Element("LeadingInitials", Contact->LeadingInitials);
		xmlout->Element("Suffix", Contact->Suffix);
		xmlout->Element("Title", Contact->Title);
		xmlout->Element("Status", Contact->Status);
		xmlout->Element("Telephone", Contact->Telephone);
		xmlout->Element("Fax", Contact->Fax);
		xmlout->Element("Email", Contact->Email);
		xmlout->Element("URL", Contact->URL);
		Address = Contact->Address.Trim();
		if (!Address.IsEmpty()) {
		  int pos;
		  xmlout->BeginTag("Address");
		  while ((pos = Address.Pos("\r\n")) > 0) {
			AddressLine = Address.SubString(1, pos-1);
			xmlout->Element("AddressLine", AddressLine);
			Address.Delete(1, pos+1);
			}
		  if (!Address.IsEmpty())
			xmlout->Element("AddressLine", Address);
		  xmlout->EndTag("Address");
		  }

		 //xmlout->Element("Country", Contact->Country);
		 xmlout->Element("Notes", Contact->Notes);
		 xmlout->EndTag("Contact");
         }
	  xmlout->EndTag("Contacts");
	  }

    // Publications
	if (TSSForm->Publications->Count) {
	  xmlout->BeginTag("Publications");

	  for (int i=0; i<TSSForm->Publications->Count; i++) {
        PUBLICATION* pub = (PUBLICATION*)TSSForm->Publications->Items[i];
		try {
            pList->AddObject(pub->Citation, (TObject*)pub);
            }
        catch(Exception &e) {
			MessageDlg(e.Message, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
            }
        }
      try {
          pList->CustomSort(NeotomaCompare);
          }
      catch(Exception &e) {
		 MessageDlg("Sort failed: " + e.Message, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
         }

      for (int i=0; i<pList->Count; i++) {
		PUBLICATION* pub = (PUBLICATION*)pList->Objects[i];
		xmlout->BeginTag("Publication", "ID", i+1, "Primary", (pub->Primary) ? "true" : "false");
		switch (pub->pub_type) {
		 case JOURNAL_ARTICLE:
		   WriteCommonPubFields(PubTypeDefs.Def[pub->pub_type], pub);
		   xmlout->Element("Title", pub->Title);
		   xmlout->Element("Journal", pub->Journal);
		   xmlout->Element("Volume", pub->Volume);
		   xmlout->Element("Issue", pub->Issue);
		   xmlout->Element("Pages", pub->Pages);
		   xmlout->Element("URL", pub->URL);
		   xmlout->Element("CitationNumber", pub->CitationNumber);
           break;
		 case BOOK_CHAPTER:
		   WriteCommonPubFields(PubTypeDefs.Def[pub->pub_type], pub);
		   xmlout->Element("Title", pub->Title);
		   WriteEditors(pub->EditorList);
		   xmlout->Element("BookTitle", pub->BookTitle);
		   xmlout->Element("Edition", pub->Edition);
		   xmlout->Element("NumVolumes", pub->NumVolumes);
		   xmlout->Element("Volume", pub->Volume);
		   xmlout->Element("VolumeTitle", pub->VolumeTitle);
		   xmlout->Element("SeriesTitle", pub->SeriesTitle);
		   xmlout->Element("SeriesNumber", pub->SeriesNumber);
		   xmlout->Element("Pages", pub->Pages);
		   xmlout->Element("Publisher", pub->Publisher);
		   xmlout->Element("City", pub->City);
		   xmlout->Element("State", pub->State);
		   xmlout->Element("Country", pub->Country);
		   WriteTranslators(pub->TranslatorList);
		   xmlout->Element("OrigLang", pub->OrigLang);
           break;
		 case AUTHORED_BOOK:
		 case EDITED_BOOK:
		   WriteCommonPubFields(PubTypeDefs.Def[pub->pub_type], pub);
		   xmlout->Element("BookTitle", pub->BookTitle);
		   xmlout->Element("Edition", pub->Edition);
		   xmlout->Element("NumVolumes", pub->NumVolumes);
		   xmlout->Element("Volume", pub->Volume);
		   xmlout->Element("VolumeTitle", pub->VolumeTitle);
		   xmlout->Element("SeriesTitle", pub->SeriesTitle);
		   xmlout->Element("SeriesNumber", pub->SeriesNumber);
		   xmlout->Element("Publisher", pub->Publisher);
		   xmlout->Element("City", pub->City);
		   xmlout->Element("State", pub->State);
		   xmlout->Element("Country", pub->Country);
		   WriteTranslators(pub->TranslatorList);
		   xmlout->Element("OrigLang", pub->OrigLang);
		   break;
		 case DOCTORAL_THESIS:
		 case MASTERS_THESIS:
		 case UNDERGRAD_THESIS:
		   WriteCommonPubFields(PubTypeDefs.Def[pub->pub_type], pub);
		   xmlout->Element("Title", pub->Title);
		   xmlout->Element("University", pub->University);
		   xmlout->Element("City", pub->City);
		   xmlout->Element("State", pub->State);
		   xmlout->Element("Country", pub->Country);
		   break;
		 case AUTHORED_REPORT:
		 case EDITED_REPORT:
		   WriteCommonPubFields(PubTypeDefs.Def[pub->pub_type], pub);
		   xmlout->Element("Title", pub->Title);
		   xmlout->Element("SeriesTitle", pub->SeriesTitle);
		   xmlout->Element("SeriesNumber", pub->SeriesNumber);
		   xmlout->Element("Publisher", pub->Publisher);
		   xmlout->Element("City", pub->City);
		   xmlout->Element("State", pub->State);
		   xmlout->Element("Country", pub->Country);
		   break;
		 case OTHER_AUTHORED:
		 case OTHER_EDITED:
		 case LEGACY:
		   WriteCommonPubFields(PubTypeDefs.Def[pub->pub_type], pub);
		   xmlout->Element("Title", pub->Title);
		   break;
		 case WEBSITE:
		   WriteCommonPubFields(PubTypeDefs.Def[pub->pub_type], pub);
		   xmlout->Element("Title", pub->Title);
		   xmlout->Element("URL", pub->URL);
		   break;
		 };
		xmlout->EndTag("Publication");
		}
	  xmlout->EndTag("Publications");
	  }

	// Specimens
	bool specimens_exist = false;
	list<CELLOBJECT*>::iterator spitr;
	list<CELLOBJECT*>::iterator spbegin = TSSForm->CellObjects.begin();
	list<CELLOBJECT*>::iterator spend = TSSForm->CellObjects.end();
	for (spitr = spbegin; spitr != spend; spitr++) {
	  if ((*spitr)->ObjectType == CELLSPECIMENS) {
		specimens_exist = true;
		break;
		}
	  }
	if (specimens_exist) {
	  xmlout->BeginTag(L"Specimens");
	  for (spitr = spbegin; spitr != spend; spitr++) {
		if ((*spitr)->ObjectType == CELLSPECIMENS) {
		  TList* Specimens = (TList*)(*spitr)->Object;
		  for (int i=0; i<Specimens->Count; i++) {
			SPECIMEN* Specimen = (SPECIMEN*)Specimens->Items[i];
			xmlout->BeginTag(L"Specimen", L"ID", NewSpecID);
			NewSpecIDs[Specimen->SpecimenID] = NewSpecID++;
			xmlout->Element("UserSpecID", Specimen->UserSpecimenID);
			xmlout->Element("Taxon", Specimen->Taxon);
			xmlout->Element("TaxaGroup", Specimen->TaxaGroup);
			xmlout->Element("Element", Specimen->Element);
			xmlout->Element("Symmetry", Specimen->Symmetry);
			xmlout->Element("Portion", Specimen->Portion);
			xmlout->Element("Maturity", Specimen->Maturity);
			xmlout->Element("Sex", Specimen->Sex);
			xmlout->Element("DomesticStatus", Specimen->DomesticStatus);
			xmlout->Element("Preservative", Specimen->Preservative);
			xmlout->Element("NISP", Specimen->NISP);
			xmlout->Element("Repository", Specimen->Repository);
			xmlout->Element("SpecNr", Specimen->SpecNr);
			xmlout->Element("FieldNr", Specimen->FieldNr);
			xmlout->Element("ArctosNr", Specimen->ArctosNr);
			if (Specimen->GenBankNrs.size() > 0) {
			  set<UnicodeString>::iterator itr;
			  for (itr = Specimen->GenBankNrs.begin(); itr != Specimen->GenBankNrs.end(); itr++)
				xmlout->Element("GenBankNr", *itr);
			  }
			xmlout->Element("Notes", Specimen->Notes);
			if (Specimen->Taphonomy.size() > 0) {
			  xmlout->BeginTag(L"Taphonomy");
			  TAPHONOMICSYSTEM::iterator sit;
			  for (sit = Specimen->Taphonomy.begin(); sit != Specimen->Taphonomy.end(); sit++) {
				UnicodeString System = sit->first;
				xmlout->BeginTag(L"System",L"Name",System);
				set<UnicodeString>& Types = sit->second;
				set<UnicodeString>::iterator tit;
				for (tit = Types.begin(); tit != Types.end(); tit++)
				  xmlout->Element("Type", *tit);
				xmlout->EndTag(L"System");
				}
			  xmlout->EndTag(L"Taphonomy");
			  }
			xmlout->EndTag(L"Specimen");
			}
		  }
		}
	  xmlout->EndTag(L"Specimens");
	  }
	// xmlout->BeginTag("Publication", "ID", i+1, "Primary", (pub->Primary) ? "true" : "false");

	// --------------------
	xmlout->BeginTag("SpreadSheetBook");
	xmlout->BeginTag("SpreadSheetOptions");
	xmlout->Element("HeaderRow", TSSForm->HeaderRow2);
	xmlout->Element("FontName", tiGlobals->SSFontName);
	xmlout->Element("FontSize", tiGlobals->SSFontSize);
	xmlout->Element("DefaultColWidth", tiGlobals->SSDefaultColWidth);
    xmlout->Element("DefaultRowHeight", tiGlobals->SSDefaultRowHeight);
	xmlout->Element("PercentDecimalPlaces", tiGlobals->PercentDecimalPlaces);
    xmlout->Element("CheckDupCodes", tiGlobals->CodeOptionDups);
    xmlout->Element("CaseSensitiveCodes", tiGlobals->CodeOptionCase);
    xmlout->Element("CodesVisible", tiGlobals->SSHideCodes);
	xmlout->Element("ElementsVisible", tiGlobals->SSHideElements);
	xmlout->Element("UnitsVisible", tiGlobals->SSHideUnits);
	xmlout->Element("ContextsVisible", tiGlobals->SSHideContext);
	xmlout->Element("TaphonomyVisible", tiGlobals->SSHideTaphonomy);
	xmlout->Element("GroupsVisible", tiGlobals->SSHideGroups);
	set<UnicodeString> TaxaGroups = tiGlobals->TaxaGroups;
	if (TaxaGroups.size() > 0) {
	  xmlout->BeginTag("GroupCategories");
	  set<UnicodeString>::iterator itr;
	  for (itr = TaxaGroups.begin(); itr != TaxaGroups.end(); itr++)
		xmlout->Element("GroupCategory", *itr);
	  xmlout->EndTag("GroupCategories");
	  }
	xmlout->EndTag("SpreadSheetOptions");

	for (int npages=0; npages<TSSForm->cxPageControl1->PageCount; npages++) {
	  TProfGrid* ProfGrid = TSSForm->Workbook->Sheets[TSSForm->cxPageControl1->Pages[npages]];
	  int ncol = TSSForm->AbsContentColCount(ProfGrid);
	  int nrow = TSSForm->AbsContentRowCount(ProfGrid);
	  int HeaderCols = TSSForm->AbsHeaderColCount(ProfGrid);
      int HeaderRows = TSSForm->AbsHeaderRowCount(ProfGrid);
	  if (ncol < HeaderCols && nrow < HeaderRows) continue;    // no data

	  UnicodeString Caption = TSSForm->cxPageControl1->Pages[npages]->Caption;
	  xmlout->BeginTag("SpreadSheet", "page", npages, "name", Caption);
	  TColor RareColor = tiGlobals->RareColor;
	  XMLATTR AttrRow("row");
	  XMLATTR AttrRare("rare", "True");
	  XMLATTR AttrFmt("format");
	  list<XMLATTR> Attributes;
	  for (int col=1; col<=ncol; col++) {
		bool ColEmpty = true;
		for (int row=1; row<=nrow; row++) {
		  if (col <= 7 && row <= 2) continue;      // TODO: use header numbers
		  TProfGridCell *ACell = ProfGrid->AbsoluteCells[col][row];
		  if (!ACell->IsEmpty() || ACell->CheckBox) {
			if (ColEmpty) {
			  xmlout->BeginTag("Col", "ID", col, "Width", ProfGrid->AbsoluteCols[col]->Width);
			  ColEmpty = false;
			  }
			// <cell row="22" rare="True" format="0.00">
			Attributes.clear();
			AttrRow.Value = IntToStr(row);
			Attributes.push_back(AttrRow);
			if (ACell->Font->Color == RareColor)
			  Attributes.push_back(AttrRare);
			if (!ACell->Format.IsEmpty()) {
			  AttrFmt.Value = ACell->Format;
			  Attributes.push_back(AttrFmt);
			  }
			xmlout->BeginTag("cell", Attributes);
			if (!ACell->Formula.IsEmpty()) {
			  xmlout->Element("formula", ACell->Formula);
			  }
			else if (ACell->CheckBox) {
			  UnicodeString utext = (ACell->CheckBoxChecked) ? "1" : "0";
			  xmlout->Element("bool", utext);
			  }
			else {
			  Value = ACell->Value;
			  int VarType = Value.Type();
			  switch (VarType)
			   {
			   case varDouble:
			   case varInteger:
				 xmlout->Element("value", (double)Value);
				 break;
			   case varOleStr:
				 xmlout->Element("text", ACell->Text);
				 break;
			   case varDate:
				 xmlout->Element("date", (double)Value);
				 break;
			   default:
				 Beep();
				 break;
			   };
			  }
			if (ACell->CellObject != NULL) {
			  CELLOBJECT* CellObject = (CELLOBJECT*)ACell->CellObject;
			  if (CellObject->ObjectType == CELLTAXONNOTES) {    // Name column
				TAXON_NOTES* TaxonNotes = (TAXON_NOTES*)CellObject->Object;
				if (!TaxonNotes->Notes.IsEmpty())
				  xmlout->Element("TaxonNotes", TaxonNotes->Notes);
				if (TaxonNotes->Synonymy.size() > 0) {
				  for (unsigned int i=0; i<TaxonNotes->Synonymy.size(); i++) {
					xmlout->BeginTag("Synonym");
					xmlout->Element("TaxonName", TaxonNotes->Synonymy[i].TaxonName);
					xmlout->Element("ContribName", TaxonNotes->Synonymy[i].Contrib);
					int idx = TSSForm->Publications->IndexOf(TaxonNotes->Synonymy[i].Pub);
					if (idx > -1)
					  xmlout->EmptyElement("publication", "ID", idx+1);
					xmlout->Element("SynonymNotes", TaxonNotes->Synonymy[i].Notes);
					xmlout->EndTag("Synonym");
					}
				  }
				}
			  else if (CellObject->ObjectType == CELLTAPHONOMY) {
				TAPHSYSTEMS* TaphSystems = (TAPHSYSTEMS*)CellObject->Object;
				for (unsigned int i=0; i<TaphSystems->Systems.size(); i++) {
				  if (TaphSystems->Systems[i].Types.size() > 0) {
					xmlout->BeginTag("Taphonomy", "DatasetType", TaphSystems->DatasetType, "System", TaphSystems->Systems[i].Name);
					set<UnicodeString>::iterator begin = TaphSystems->Systems[i].Types.begin();
					set<UnicodeString>::iterator end = TaphSystems->Systems[i].Types.end();
					for (set<UnicodeString>::iterator itr = begin; itr != end; itr++)
					  xmlout->Element("Type", *itr);
					xmlout->EndTag("Taphonomy");
					}
				  }
				}
			  else if (CellObject->ObjectType == CELLCONTACTS) {
				TList* SSContacts = (TList*)CellObject->Object;
				for (int i=0; i<SSContacts->Count; i++) {
				  CONTACT* Contact = (CONTACT*)SSContacts->Items[i];
				  for (int j=0; j<cList->Count; j++) {
					if (Contact == (CONTACT*)cList->Objects[j]) {
					  xmlout->EmptyElement("contact", "ID", j+1);
					  break;
					  }
					 }
				  }
				}
			  else if (CellObject->ObjectType == CELLPUBLICATIONS) {
				TList* SSPubs = (TList*)CellObject->Object;
				for (int i=0; i<SSPubs->Count; i++) {
				  PUBLICATION* Pub = (PUBLICATION*)SSPubs->Items[i];
				  for (int j=0; j<pList->Count; j++) {
					if (Pub == (PUBLICATION*)pList->Objects[j]) {
					  xmlout->EmptyElement("pub", "ID", j+1);
					  break;
					  }
					 }
				  }
				}
			  else if (CellObject->ObjectType == CELLSPECIMENS) {
				TList* Specimens = (TList*)CellObject->Object;
				if (Specimens->Count > 0) {
				  for (int i=0; i<Specimens->Count; i++) {
					SPECIMEN* Specimen = (SPECIMEN*)Specimens->Items[i];
					xmlout->EmptyElement("specimen", "ID", NewSpecIDs[Specimen->SpecimenID]);
					}
				  }
				}
			  }
			xmlout->EndTag("cell");
			}
		  }
		if (!ColEmpty)
		  xmlout->EndTag("Col");
		}
	  xmlout->EndTag("SpreadSheet");
	  }
	xmlout->EndTag("SpreadSheetBook");

	// Site metadata
	for (int site_no=0; site_no < TSSForm->Sites->Count; site_no++) {
	  SITE* SitePtr = (SITE*)TSSForm->Sites->Items[site_no];
	  xmlout->BeginTag("Site");
	  xmlout->Element("SiteName", SitePtr->SiteName);
	  if (TSSForm->EPD.SiteID > -1)
		xmlout->Element("EPDSiteID", TSSForm->EPD.SiteID);
	  xmlout->Element("LongEast", SitePtr->LongEast);
	  xmlout->Element("LongWest", SitePtr->LongWest);
	  xmlout->Element("LatNorth", SitePtr->LatNorth);
	  xmlout->Element("LatSouth", SitePtr->LatSouth);
	  xmlout->Element("Altitude", SitePtr->Altitude);
	  xmlout->Element("Area", SitePtr->Area);
	  xmlout->Element("Country", SitePtr->Country);
	  xmlout->Element("State", SitePtr->State);
	  xmlout->Element("County", SitePtr->County);
	  xmlout->Element("AdminUnit", SitePtr->AdminUnit);
	  xmlout->Element("SiteDescription", SitePtr->SiteDescription);
	  xmlout->Element("Notes", SitePtr->Notes);

	  if (SitePtr->LakeParams.size() > 0) {
		xmlout->BeginTag("LakeParameters");
		vector<LAKEPARAM>::iterator itr = SitePtr->LakeParams.begin();
		while (itr != SitePtr->LakeParams.end()) {
		  xmlout->BeginTag("LakeParameter");
		  xmlout->Element("Parameter", (*itr).Name);
		  double dValue = (*itr).Value;
		  xmlout->Element("Value", dValue);
		  xmlout->EndTag("LakeParameter");
		  itr++;
		  }
		xmlout->EndTag("LakeParameters");
		}
	  xmlout->EndTag("Site");
	  }

	// metadata for a single collection unit. Multi-collection units stored in spreadsheet
	SITE* SitePtr = (SITE*)TSSForm->Sites->Items[0];
	int coll_no = 0;
	xmlout->BeginTag("CollectionUnit");
	//ShowMessage(L"Breakpoint 1");
	xmlout->Element("Handle", SitePtr->CollUnits[coll_no].Handle);
	//ShowMessage(L"Breakpoint 2");
	if (TSSForm->EPD.SiteID > -1 && TSSForm->EPD.CollectionUnitID > -1)
	  xmlout->Element("EPDCollUnitID", TSSForm->EPD.CollectionUnitID);
	//ShowMessage(L"Breakpoint 3");
	//int WhitmoreID1 = TSSForm->SitePtr->CollUnits[coll_no].WhitmoreID1;
	//ShowMessage(L"WhitmoreID1 = " + IntToStr(WhitmoreID1));
	//if (TSSForm->SitePtr->CollUnits[coll_no].WhitmoreID1 > -1)
	//  xmlout->Element("WhitmoreID1", WhitmoreID1);
	//ShowMessage(L"Breakpoint 4");
	xmlout->Element("CollectionName", SitePtr->CollUnits[coll_no].CollectionName);
	xmlout->Element("CollectionType", SitePtr->CollUnits[coll_no].CollectionType);
	xmlout->Element("CollectionDevice", SitePtr->CollUnits[coll_no].CollectionDevice);
	//ShowMessage(L"Breakpoint 5");
	if (SitePtr->CollUnits[coll_no].Collectors.size() > 0) {
	  xmlout->BeginTag("Collectors");
	  for (unsigned int i=0; i<SitePtr->CollUnits[coll_no].Collectors.size(); i++) {
		int idx = cList->IndexOfObject((TObject*)SitePtr->CollUnits[coll_no].Collectors[i]) + 1;
		xmlout->EmptyElement("Contact", "ID", idx);
		}
	  xmlout->EndTag("Collectors");
	  }
	xmlout->Element("CollectionDate", SitePtr->CollUnits[coll_no].CollDate);
	xmlout->Element("Location", SitePtr->CollUnits[coll_no].Location);
	xmlout->Element("GPSLat", SitePtr->CollUnits[coll_no].GPSLat);
	xmlout->Element("GPSLong", SitePtr->CollUnits[coll_no].GPSLong);
	xmlout->Element("GPSError", SitePtr->CollUnits[coll_no].GPSError);
	xmlout->Element("GPSAltitude", SitePtr->CollUnits[coll_no].GPSAltitude);
	xmlout->Element("DepositionalEnvironment", SitePtr->CollUnits[coll_no].DepEnv);
	xmlout->Element("Substrate", SitePtr->CollUnits[coll_no].Substrate);
	xmlout->Element("SlopeAngle", SitePtr->CollUnits[coll_no].SlopeAngle);
	xmlout->Element("SlopeAspect", SitePtr->CollUnits[coll_no].SlopeAspect);
	xmlout->Element("WaterDepth", SitePtr->CollUnits[coll_no].WaterDepth);
	xmlout->Element("Notes", SitePtr->CollUnits[coll_no].Notes);
	xmlout->EndTag("CollectionUnit");

	//ShowMessage(L"Breakpoint 6");

	// Dataset metadata
	xmlout->BeginTag("Datasets");
	for (unsigned int dataset_no=0; dataset_no < TSSForm->Datasets.size(); dataset_no++) {
	  xmlout->BeginTag("Dataset");
	  xmlout->Element("DatasetType", TSSForm->Datasets[dataset_no].DatasetType);
	  if (TSSForm->EPD.SiteID > -1) {
		if (TSSForm->EPD.Datasets.count(3) == 1)
		  xmlout->Element("EPDDatasetID", TSSForm->EPD.Datasets[3]);
		}
	  xmlout->Element("Name", TSSForm->Datasets[dataset_no].Name);
	  xmlout->Element("Notes", TSSForm->Datasets[dataset_no].Notes);
	  xmlout->Element("IsSSamp", TSSForm->Datasets[dataset_no].IsSSamp);
	  xmlout->Element("WhitmoreData", TSSForm->Datasets[dataset_no].WhitmoreData);
	  xmlout->Element("IsAggregate", TSSForm->Datasets[dataset_no].IsAggregate);
      xmlout->Element("AggregateOrder", TSSForm->Datasets[dataset_no].AggregateOrder);

	  if (TSSForm->Datasets[dataset_no].Investigators.size() > 0) {
		xmlout->BeginTag("Investigators");
		for (unsigned int i=0; i<TSSForm->Datasets[dataset_no].Investigators.size(); i++) {
		  int idx = cList->IndexOfObject((TObject*)TSSForm->Datasets[dataset_no].Investigators[i]) + 1;
		  xmlout->EmptyElement("Contact", "ID", idx);
		  }
		xmlout->EndTag("Investigators");
		}

	  if (TSSForm->Datasets[dataset_no].Processors.size() > 0) {
		xmlout->BeginTag("Processors");
		for (unsigned int i=0; i<TSSForm->Datasets[dataset_no].Processors.size(); i++) {
		  int idx = cList->IndexOfObject((TObject*)TSSForm->Datasets[dataset_no].Processors[i]) + 1;
		  xmlout->EmptyElement("Contact", "ID", idx);
		  }
		xmlout->EndTag("Processors");
		}

	  if (TSSForm->Datasets[dataset_no].Publications.size() > 0) {
		xmlout->BeginTag("Publications");
		for (unsigned int i=0; i<TSSForm->Datasets[dataset_no].Publications.size(); i++) {
		  int idx = pList->IndexOfObject((TObject*)TSSForm->Datasets[dataset_no].Publications[i]) + 1;
		  xmlout->EmptyElement("Publication", "ID", idx);
		  }
		xmlout->EndTag("Publications");
		}

	  if (TSSForm->Datasets[dataset_no].Repositories.size() > 0) {
		xmlout->BeginTag("Repositories");
		vector<REPOSITORY>::iterator begin = TSSForm->Datasets[dataset_no].Repositories.begin();
		vector<REPOSITORY>::iterator end = TSSForm->Datasets[dataset_no].Repositories.end();
		vector<REPOSITORY>::iterator itr;
		for (itr = begin; itr != end; itr++) {
		  xmlout->BeginTag("Repository");
		  xmlout->Element("Acronym", itr->Acronym);
		  xmlout->Element("Repository", itr->Repository);
		  if (!itr->Notes.IsEmpty())
			xmlout->Element("Notes", itr->Notes);
		  if (!itr->SpecimenNotes.IsEmpty())
			xmlout->Element("SpecimenNotes", itr->SpecimenNotes);
		  xmlout->EndTag("Repository");
		  }
		xmlout->EndTag("Repositories");
		}

	  if (TSSForm->Datasets[dataset_no].Submissions.size() > 0) {
		xmlout->BeginTag("Submissions");
		for (unsigned int i=0; i<TSSForm->Datasets[dataset_no].Submissions.size(); i++) {
		  SUBMISSION &Submission = TSSForm->Datasets[dataset_no].Submissions[i];
		  xmlout->BeginTag("Submission");
		  xmlout->Element("Archived", Submission.Archived);
		  xmlout->Element("SubmittedForm", Submission.SubmittedForm);
		  xmlout->Element("SubmissionType", Submission.SubmissionType);
		  xmlout->Element("SubmissionDate", Submission.SubmissionDate);
		  xmlout->Element("Notes", Submission.Notes);
		  xmlout->Element("SubmittersText", Submission.SubmittersComboBoxText);
		  if (Submission.Submitters.size() > 0) {
			xmlout->BeginTag("Submitters");
			for (unsigned int i=0; i<Submission.Submitters.size(); i++) {
			  int idx = cList->IndexOfObject((TObject*)Submission.Submitters[i]) + 1;
			  xmlout->EmptyElement("Contact", "ID", idx);
			  }
			xmlout->EndTag("Submitters");
			}
		  xmlout->EndTag("Submission");
		  }
		xmlout->EndTag("Submissions");
		}
	  xmlout->EndTag("Dataset");
	  }
	xmlout->EndTag("Datasets");

    // Geochron metadata
	vector<GEOCHRON> GeochronVec;
	vector<GEOCHRON>::iterator start;
	vector<GEOCHRON>::iterator stop;
	vector<GEOCHRON>::iterator itr;

	short GeochronID;
	//map<int, GEOCHRON> GeochronOut;  // for Geochron links with age models
	map<int,int> GeochronOut; // oldID, newID
	if (!TSSForm->GeochronDataset.Notes.IsEmpty() ||
		 TSSForm->GeochronDataset.Investigators.size() > 0 ||
		 TSSForm->GeochronList->Count() > 0) {
	  xmlout->BeginTag("GeochronDataset");
	  if (TSSForm->EPD.SiteID > -1) {
		if (TSSForm->EPD.Datasets.count(1) == 1)
		  xmlout->Element("EPDDatasetID", TSSForm->EPD.Datasets[1]);
		}
	  if (!TSSForm->GeochronDataset.Notes.IsEmpty())
		xmlout->Element("Notes", TSSForm->GeochronDataset.Notes);
	  if (TSSForm->GeochronDataset.Investigators.size() > 0) {
        xmlout->BeginTag("Investigators");
		for (unsigned int i=0; i<TSSForm->GeochronDataset.Investigators.size(); i++) {
		  int idx = cList->IndexOfObject((TObject*)TSSForm->GeochronDataset.Investigators[i]) + 1;
		  xmlout->EmptyElement("Contact", "ID", idx);
		  }
		xmlout->EndTag("Investigators");
		}
	  if (TSSForm->GeochronList->Count() > 0) {
		int nanalunits = 0;
		int gcount = TSSForm->GeochronList->Count();
		for (int i=0; i<gcount; i++) {
		  GEOCHRON& Date = TSSForm->GeochronList->Dates[i];
		  GeochronVec.push_back(Date);
		  if (!Date.AnalUnit.IsEmpty())
			nanalunits++;
		  }
		GeochronID = (nanalunits == gcount) ? GEOCHRONNAME : GEOCHRONDEPTH;

		if (GeochronID == GEOCHRONDEPTH) {
		  sort(GeochronVec.begin(), GeochronVec.end(), TGeochronList::DepthCompare);
		  xmlout->BeginTag("Geochronology", "AnalysisUnitID", "Depth");
		  }
		else {
		  xmlout->BeginTag("Geochronology", "AnalysisUnitID", "Name");
		  }

		start = GeochronVec.begin();
		stop = GeochronVec.end();

		int NewID = 1;
		for (itr=start; itr != stop; itr++) {
		  GEOCHRON Date = *itr;
		  GeochronOut[Date.ID] = NewID;
		  xmlout->BeginTag("GeochronSample", "ID", NewID++);
		  xmlout->Element("Method", Date.Method);
		  xmlout->Element("AgeUnits", Date.AgeUnits);
		  xmlout->Element("Depth", Date.Depth);
		  xmlout->Element("Thickness", Date.Thickness);
		  xmlout->Element("AnalysisUnit", Date.AnalUnit);
		  xmlout->Element("LabNumber", Date.LabNumber);
		  xmlout->Element("Age", Date.Age);
		  xmlout->Element("ErrorOlder", Date.ErrorOlder);
		  xmlout->Element("ErrorYounger", Date.ErrorYounger);
		  xmlout->Element("Sigma", Date.Sigma);
		  xmlout->Element("StdDev", Date.StdDev);
		  xmlout->Element("GreaterThan", Date.GreaterThan);
		  if (Date.Parameters.size() > 0) {
			xmlout->BeginTag("Parameters");
			map<UnicodeString,Variant>::iterator itr;
			for (itr = Date.Parameters.begin(); itr != Date.Parameters.end(); itr++) {
			  xmlout->BeginTag("Parameter");
			  xmlout->Element("Name", itr->first);
			  if (SameText(Date.Method,L"Carbon-14")) {
				if (SameText(itr->first, L"Method"))
				  xmlout->Element("Value", VarToStr(itr->second));
				else
				  xmlout->Element("Value",VariantToDouble(itr->second, 0.0));
				}
			  xmlout->EndTag("Parameter");
			  }
			xmlout->EndTag("Parameters");
		    }

		  xmlout->Element("MaterialDated", Date.MaterialDated);
		  xmlout->Element("Notes", Date.Notes);
		  if (Date.publications.size() > 0) {
			xmlout->Element("PublicationsText", Date.PubComboBoxText);
			xmlout->BeginTag("Publications");
			int idx;
			for (unsigned int i=0; i<Date.publications.size(); i++) {
			  if ((idx = pList->IndexOfObject((TObject*)Date.publications[i])) >= 0)
				xmlout->EmptyElement("Publication", "ID", idx+1);
			  }
			xmlout->EndTag("Publications");
			}
		  if (Date.TaxaDated.size()) {    // taxa dated
			xmlout->BeginTag("TaxaDated");
			vector<TAXONDATED>::iterator itr = Date.TaxaDated.begin();
			while (itr != Date.TaxaDated.end()) {
			  TAXONDATED TaxonDated = *itr;
			  xmlout->BeginTag("TaxonDated");
			  //xmlout->Element("ID", itr->ID);
			  if (itr->Specimen != NULL)
				xmlout->Element("SpecimenID", NewSpecIDs[itr->Specimen->SpecimenID]);
			  else
				xmlout->Element("SpecimenID", -1);
			  xmlout->Element("SpecNr", itr->UserSpecID);
			  xmlout->Element("Taxon", itr->Taxon);
			  xmlout->Element("Element", itr->Element);
			  xmlout->Element("Fraction", itr->Fraction);
			  xmlout->Element("CalAgeMedian", itr->CalAgeMedian);
			  xmlout->Element("CalAgeOlder", itr->CalAgeOlder);
			  xmlout->Element("CalAgeYounger", itr->CalAgeYounger);
			  xmlout->Element("CalibCurve", itr->CalibCurve);
			  if (!itr->Calib.Program.IsEmpty()) {
				xmlout->BeginTag("CalibProgram");
				xmlout->Element("Program", itr->Calib.Program);
				if (!itr->Calib.Version.IsEmpty())
				  xmlout->Element("Version", itr->Calib.Version);
				xmlout->EndTag("CalibProgram");
				}
			  xmlout->Element("Notes", itr->Notes);
			  xmlout->EndTag("TaxonDated");
			  itr++;
			  }
			xmlout->EndTag("TaxaDated");
			}
		  xmlout->EndTag("GeochronSample");
		  }
		xmlout->EndTag("Geochronology");
		}
	  xmlout->EndTag("GeochronDataset");
	  }

	// Age model metadata
	if (TSSForm->AgeModelList->Count) {
	  short ChronControlID = GEOCHRONNONE;

	  int nanalunits = 0;
	  TList* controls = TSSForm->AgeModelList->AgeModels[0]->ChronControls;
	  if (controls != NULL) {
		for (int i=0; i<controls->Count; i++) {
		  CHRON* control = (CHRON*)controls->Items[i];
		  if (!control->AnalUnit.IsEmpty())
			nanalunits++;
		  }
		ChronControlID = (nanalunits == controls->Count) ? GEOCHRONNAME : GEOCHRONDEPTH;

		if (ChronControlID == GEOCHRONDEPTH) {      // ages identified by depth
		  ChronControlID = GEOCHRONDEPTH;
		  xmlout->BeginTag("AgeModels", "AnalysisUnitID", "Depth");
		  }
		else {
		  ChronControlID = GEOCHRONNAME;
		  xmlout->BeginTag("AgeModels", "AnalysisUnitID", "Name");
		  }
		}
	  else
		xmlout->BeginTag("AgeModels", "AnalysisUnitID", "None");

	  TList* LocalList = TSSForm->AgeModelList;
	  for (int i=0; i<LocalList->Count; i++) {
		AGEMODEL* AgeModel = (AGEMODEL*)LocalList->Items[i];
		xmlout->BeginTag("AgeModel");
		xmlout->Element("ChronNumber", AgeModel->ChronNumber);
		xmlout->Element("ChronologyName", AgeModel->ChronologyName);
		xmlout->Element("AgeUnits", AgeModel->AgeUnits);
		xmlout->Element("Default", AgeModel->Default);
		xmlout->Element("DatePrepared", AgeModel->DatePrepared);
		xmlout->Element("Model", AgeModel->AgeModel);
		xmlout->Element("AgeBoundOlder", AgeModel->AgeBoundOlder);
		xmlout->Element("AgeBoundYounger", AgeModel->AgeBoundYounger);
		xmlout->Element("Notes", AgeModel->Notes);
		if (AgeModel->Preparers.size()) {
		  xmlout->Element("PreparersText", AgeModel->PreparersComboBoxText);
		  xmlout->BeginTag("Preparers");
		  int idx;
		  for (unsigned int j=0; j<AgeModel->Preparers.size(); j++)
			if ((idx = cList->IndexOfObject((TObject*)AgeModel->Preparers[j])) >= 0)
			  xmlout->EmptyElement("Contact", "ID", idx+1);
		  xmlout->EndTag("Preparers");
		  }

		if (controls != NULL && AgeModel->ChronControls->Count > 0) {
		  TList* LocalChronList = new TList;
		  LocalChronList->Assign(AgeModel->ChronControls);
		  LocalChronList->Sort(AGEMODEL::ChronControlsDepthAgeCompare);
		  xmlout->BeginTag("ChronControls");
		  for (int j=0; j<LocalChronList->Count; j++) {
			CHRON* ChronControl = (CHRON*)LocalChronList->Items[j];
			xmlout->BeginTag("ChronControl");
			xmlout->Element("ControlType", ChronControl->ControlType);
			xmlout->Element("Depth", ChronControl->Depth);
			xmlout->Element("Thickness", ChronControl->Thickness);
			xmlout->Element("AnalysisUnit", ChronControl->AnalUnit);
			xmlout->Element("AgeUnits", ChronControl->AgeUnits);
			xmlout->Element("Age", ChronControl->AgeValue);
			xmlout->Element("AgeLimitOlder", ChronControl->AgeLimitOlder);
			xmlout->Element("AgeLimitYounger", ChronControl->AgeLimitYounger);
			xmlout->Element("CalibCurve", ChronControl->CalibCurve);
			if (!ChronControl->Calib.Program.IsEmpty()) {
			  xmlout->BeginTag("CalibProgram");
			  xmlout->Element("Program", ChronControl->Calib.Program);
			  if (!ChronControl->Calib.Version.IsEmpty())
				xmlout->Element("Version", ChronControl->Calib.Version);
			  xmlout->EndTag("CalibProgram");
			  }

			int size = ChronControl->GeochronIDs.size();
			if (size > 0) {
			  bool LinksStarted = false;
			  for (int i=0; i<size; i++) {
				int ID = ChronControl->GeochronIDs[i];
				map<int,int>::iterator itr = GeochronOut.find(ID);
				if (itr != GeochronOut.end()) {
                  if (!LinksStarted) {
					xmlout->BeginTag("GeochronLinks");
					LinksStarted = true;
					}
                  xmlout->EmptyElement("GeochronLink", "ID", itr->second);
				  }
				}
			  if (LinksStarted)
			    xmlout->EndTag("GeochronLinks");
			  }
			xmlout->Element("Notes", ChronControl->Notes);
			xmlout->EndTag("ChronControl");
			}
		  xmlout->EndTag("ChronControls");
		  delete LocalChronList;
		  }
		xmlout->EndTag("AgeModel");
		}
	  xmlout->EndTag("AgeModels");
	  }

	// Lithology metadata
	if (TSSForm->LithologyUnitList->Count) {
	  xmlout->BeginTag("Lithology");
	  for (int i=0; i<TSSForm->LithologyUnitList->Count; i++) {
        LITHOLOGYUNIT* LithUnit = (LITHOLOGYUNIT*)TSSForm->LithologyUnitList->LithologyUnits[i];
		xmlout->BeginTag("LithologyUnit");
		xmlout->Element("DepthTop", LithUnit->DepthTop);
        xmlout->Element("DepthBottom", LithUnit->DepthBottom);
		xmlout->Element("Description", LithUnit->UnitDescription);
		xmlout->Element("LowerBoundary", LithUnit->LowerBoundary);
		xmlout->EndTag("LithologyUnit");
		}
	  xmlout->EndTag("Lithology");
	  }

	// LOI data
	int LastRowContent = 0;
	for (int row = TSSForm->AdvColumnGrid5->RowCount-1; row > 0; row--) {
	  for (int col = 1; col < TSSForm->AdvColumnGrid5->ColCount; col++) {
		if (!TSSForm->AdvColumnGrid5->AllCells[col][row].IsEmpty()) {
		  LastRowContent = row;
		  break;
		  }
		}
	  if (LastRowContent > 1) break;
	  }

	if (LastRowContent > 0) {
	  xmlout->BeginTag("Loss-on-ignition");
	  if (TSSForm->loi.Submissions.size() > 0) {
		xmlout->BeginTag("Submissions");
		for (unsigned int i=0; i<TSSForm->loi.Submissions.size(); i++) {
		  SUBMISSION& Submission = TSSForm->loi.Submissions[i];
		  xmlout->BeginTag("Submission");
		  xmlout->Element("Archived", Submission.Archived);
		  xmlout->Element("SubmittedForm", Submission.SubmittedForm);
		  xmlout->Element("SubmissionType", Submission.SubmissionType);
		  xmlout->Element("SubmissionDate", Submission.SubmissionDate);
		  xmlout->Element("Notes", Submission.Notes);
		  xmlout->Element("SubmittersText", Submission.SubmittersComboBoxText);
		  if (Submission.Submitters.size() > 0) {
			xmlout->BeginTag("Submitters");
			for (unsigned int i=0; i<Submission.Submitters.size(); i++) {
			  int idx = cList->IndexOfObject((TObject*)Submission.Submitters[i]) + 1;
			  xmlout->EmptyElement("Contact", "ID", idx);
			  }
			xmlout->EndTag("Submitters");
			}
		  xmlout->EndTag("Submission");
		  }
		xmlout->EndTag("Submissions");
        }

	  if (TSSForm->loi.Investigators.size() > 0) {
		xmlout->BeginTag("Investigators");
		for (unsigned int i=0; i<TSSForm->loi.Investigators.size(); i++) {
		  int idx = cList->IndexOfObject((TObject*)TSSForm->loi.Investigators[i]) + 1;
		  xmlout->EmptyElement("Contact", "ID", idx);
		  }
		xmlout->EndTag("Investigators");
        }

	  if (TSSForm->loi.Publications.size()) {
		xmlout->BeginTag("Publications");
		for (unsigned int i=0; i<TSSForm->loi.Publications.size(); i++) {
		  int idx = pList->IndexOfObject((TObject*)TSSForm->loi.Publications[i]) + 1;
		  xmlout->EmptyElement("Publication", "ID", idx);
		  }
		xmlout->EndTag("Publications");
		}

	  xmlout->Element("OrganicLOITemp", TSSForm->ComboBox7->Text);
	  xmlout->Element("CarbonateLOITemp", TSSForm->ComboBox8->Text);

	  xmlout->BeginTag("LOISamples");

	  double dVal;
	  int iVal;
	  TDateTime date;
	  TAdvColumnGrid* LOIGrid = TSSForm->AdvColumnGrid5;
	  for (int row=1; row<LOIGrid->RowCount; row++) {
		bool content = false;
		for (int col=1; col<LOIGrid->ColCount; col++) {
		  if (!LOIGrid->AllCells[col][row].IsEmpty()) {
			content = true;
			break;
			}
		  }
		if (!content) continue;
		xmlout->BeginTag("LOISample");
		if (!LOIGrid->AllCells[1][row].IsEmpty()) {
		  if (TryStrToFloat(LOIGrid->AllCells[1][row],dVal))
			xmlout->Element("Depth", dVal);
		  }
		if (!LOIGrid->AllCells[2][row].IsEmpty()) {
		  if (TryStrToFloat(LOIGrid->AllCells[2][row],dVal))
			xmlout->Element("Thickness", dVal);
		  }
		if (!LOIGrid->AllCells[3][row].IsEmpty()) {
		  if (TryStrToInt(LOIGrid->AllCells[3][row],iVal))
			xmlout->Element("TempOrganic", iVal);
		  }
		if (!LOIGrid->AllCells[4][row].IsEmpty()) {
		  if (TryStrToFloat(LOIGrid->AllCells[4][row],dVal))
			xmlout->Element("LOIOrganic", dVal);
		  }
		if (!LOIGrid->AllCells[5][row].IsEmpty()) {
		  if (TryStrToInt(LOIGrid->AllCells[5][row],iVal))
			xmlout->Element("TempCarbonate", iVal);
		  }
		if (!LOIGrid->AllCells[6][row].IsEmpty()) {
		  if (TryStrToFloat(LOIGrid->AllCells[6][row],dVal))
			xmlout->Element("LOICarbonate", dVal);
		  }
		if (!LOIGrid->AllCells[7][row].IsEmpty()) {
		  if (TryStrToFloat(LOIGrid->AllCells[7][row],dVal))
			xmlout->Element("BulkDensity", dVal);
		  }
		if (!LOIGrid->AllCells[8][row].IsEmpty()) {
		  if (TryStrToDate(LOIGrid->AllCells[8][row],date)) {
			dVal = (double)date;
			xmlout->Element("DateDnalyzed", dVal);
			}
		  }
		if (!LOIGrid->AllCells[9][row].IsEmpty()) {
		  int ItemIndex = LOIGrid->Columns->Items[9]->ComboItems->IndexOf(LOIGrid->AllCells[9][row]);
		  if (ItemIndex != -1) {
			int idx = cList->IndexOfObject(LOIGrid->Columns->Items[9]->ComboItems->Objects[ItemIndex]) + 1;
			xmlout->EmptyElement("Analyst", "ID", idx);
			}
		  }
		xmlout->EndTag("LOISample");
		}
	  xmlout->EndTag("LOISamples");
	  xmlout->EndTag("Loss-on-ignition");
	  }

	// Isotope data
	if (!TSSForm->AdvIsotopeStringGrid->Cells[1][2].IsEmpty() ||
		!TSSForm->AdvIsotopeStringGrid->Cells[2][2].IsEmpty()) {
	  xmlout->BeginTag(L"IsotopeDataset");

	  // ISOMETADATA Metadata;
	  // TSSForm->IsoMetadata[Isotope] = Metadata;


	  xmlout->BeginTag(L"IsotopeMetadata");
	  map<short,ISOMETADATA>::iterator itr;
	  map<short,ISOMETADATA>::iterator begin = TSSForm->IsoMetadata.begin();
	  map<short,ISOMETADATA>::iterator end = TSSForm->IsoMetadata.end();
	  for (itr = begin; itr != end; itr++)
		WriteIsotopeMetadata(itr->first, itr->second);
	  xmlout->EndTag(L"IsotopeMetadata");

	  // write out specimens
	  xmlout->BeginTag(L"Specimens");
	  int serialcount = 0;
	  UnicodeString SampleType;
	  //SPECIMEN* Specimen;
	  for (int row = 2; row < TSSForm->AdvIsotopeStringGrid->RowCount; row++) {
		if (serialcount == 0) {
		  SPECIMEN* Specimen = (SPECIMEN*)TSSForm->AdvIsotopeStringGrid->Objects[0][row];
		  xmlout->BeginTag(L"Specimen", L"row", row, L"ID", NewSpecIDs[Specimen->SpecimenID]);
		  xmlout->Element(L"AnalUnitDepth", TSSForm->AdvIsotopeStringGrid->Cells[1][row]);
		  xmlout->Element(L"AnalUnitName", TSSForm->AdvIsotopeStringGrid->Cells[2][row]);
		  xmlout->Element(L"Taxon", TSSForm->AdvIsotopeStringGrid->Cells[3][row]);
		  xmlout->Element(L"Element", TSSForm->AdvIsotopeStringGrid->Cells[4][row]);
		  xmlout->Element(L"SpecID", TSSForm->AdvIsotopeStringGrid->Cells[5][row]);
		  SampleType = TSSForm->AdvIsotopeStringGrid->Cells[6][row];
		  xmlout->Element(L"SampleType", SampleType);
		  if (SameText(SampleType, L"serial")) {
			ISOTOPESERIES* IsoSer = (ISOTOPESERIES*)TSSForm->AdvIsotopeStringGrid->Objects[6][row];
			serialcount = IsoSer->NumberOfSamples - 1;
			xmlout->BeginTag(L"IsotopeSeries", L"ID", TSSForm->AdvIsotopeStringGrid->Cells[7][row]);
			xmlout->Element(L"Count", IsoSer->NumberOfSamples);
			xmlout->Element(L"Origin", IsoSer->SamplingOrigin);
			xmlout->Element(L"Units", IsoSer->SampleDistUnits);
			xmlout->Element(L"Interval", IsoSer->SampleInterval);
			xmlout->Element(L"TransectWidth", IsoSer->TransectWidth);
			xmlout->Element(L"DrillBitSize", IsoSer->DrillBitSize);
			xmlout->Element(L"BiolMarker", IsoSer->SampledBiolMarker);
			xmlout->BeginTag(L"IsotopeSeriesData");
			WriteIsotopeSample(row, true);
			}
		  else
			WriteIsotopeSample(row, false);
		  }
		else {
		  WriteIsotopeSample(row, true);
		  if (--serialcount == 0) {
			xmlout->EndTag(L"IsotopeSeriesData");
			xmlout->EndTag(L"IsotopeSeries");
			}
		  }
		if (serialcount == 0)
		  xmlout->EndTag(L"Specimen");
		}
	  xmlout->EndTag(L"Specimens");
	  xmlout->EndTag(L"IsotopeDataset");
	  }

	xmlout->EndTag(L"TiliaFile");
	xmlout->Finish();
	}
  __finally
	{
	delete cList;
	delete pList;
	delete xmlout;
	}
  return true;

}
//---------------------------------------------------------------------------

void WriteTLX::WriteIsotopeMetadata(short isotope, ISOMETADATA& IsoMetadata)
{
   switch (isotope) {
	 case isoCarbon:
	   xmlout->BeginTag(L"Isotope", L"type", L"Carbon");
	   break;
	 case isoNitrogen:
	   xmlout->BeginTag(L"Isotope", L"type", L"Nitrogen");
	   break;
	 case isoOxygen:
	   xmlout->BeginTag(L"Isotope", L"type", L"Oxygen");
	   break;
	 case isoHydrogen:
	   xmlout->BeginTag(L"Isotope", L"type", L"Hydrogen");
	   break;
	 case isoSulfur:
	   xmlout->BeginTag(L"Isotope", L"type", L"Sulfur");
	   break;
	 case isoStrontium:
	   xmlout->BeginTag(L"Isotope", L"type", L"Strontium");
	   break;
	 }

   xmlout->Element(L"TechError", IsoMetadata.TechError);
   xmlout->Element(L"TechErrorSD", IsoMetadata.TechErrorSD);
   xmlout->Element(L"LongTermError", IsoMetadata.LongTermError);
   xmlout->Element(L"Instrument", IsoMetadata.Instrument);
   xmlout->Element(L"IntroSystem", IsoMetadata.IntroSystem);
   if (IsoMetadata.Standards.size() > 0) {
	 xmlout->BeginTag(L"Standards");
	 for (unsigned int i=0; i<IsoMetadata.Standards.size(); i++) {
	   xmlout->BeginTag(L"Standard");
	   xmlout->Element(L"Name", IsoMetadata.Standards[i].first);
	   if (!IsoMetadata.Standards[i].second.IsEmpty())
		 xmlout->Element(L"Value", IsoMetadata.Standards[i].second);
	   else
		 xmlout->EmptyElement("Value");
	   xmlout->EndTag(L"Standard");
	   }
	 xmlout->EndTag(L"Standards");
	 }
   if (isotope == isoStrontium) {
	 xmlout->Element(L"SrLocalValue", IsoMetadata.SrLocalValue);
	 xmlout->Element(L"SrLocalValueSD", IsoMetadata.SrLocalValueSD);
	 xmlout->Element(L"SrLocalGeolContext", IsoMetadata.SrLocalGeolContext);
	 }
   xmlout->Element(L"Notes", IsoMetadata.Notes);
   xmlout->EndTag(L"Isotope");
}
//---------------------------------------------------------------------------

void WriteTLX::WriteIsotopeSample(int row, bool IsSeries)
{

   if (IsSeries) {
	 xmlout->BeginTag(L"IsotopeSeriesAnalysisUnit", L"row", row);
	 xmlout->Element(L"Distance", TSSForm->AdvIsotopeStringGrid->AllCells[8][row]);
	 xmlout->Element(L"Depth", TSSForm->AdvIsotopeStringGrid->AllCells[9][row]);
	 xmlout->Element(L"Band", TSSForm->AdvIsotopeStringGrid->AllCells[10][row]);
	 }

   xmlout->BeginTag(L"IsotopeData");
   if (TSSForm->HTMLCheckBox1->Checked)   // carbon
	 WriteIsotopeData(TSSForm->IsoCols[isoCarbon].first, row, isoCarbon);
   if (TSSForm->HTMLCheckBox1->Checked || TSSForm->HTMLCheckBox2->Checked) {   // C:N
	 xmlout->BeginTag(L"IsotopeMeasurement", L"type", L"C:N");
	 xmlout->Element(L"Value", TSSForm->AdvIsotopeStringGrid->AllCells[TSSForm->IsoCols[isoCNratio].first][row]);
	 xmlout->EndTag(L"IsotopeMeasurement");
	 }
   if (TSSForm->HTMLCheckBox2->Checked)   // nitrogen
	 WriteIsotopeData(TSSForm->IsoCols[isoNitrogen].first, row, isoNitrogen);
   if (TSSForm->HTMLCheckBox3->Checked)   // oxygen
	 WriteIsotopeData(TSSForm->IsoCols[isoOxygen].first, row, isoOxygen);
   if (TSSForm->HTMLCheckBox3->Checked || TSSForm->HTMLCheckBox5->Checked) {   // O:H
	 xmlout->BeginTag(L"IsotopeMeasurement", L"type", L"O:H");
	 xmlout->Element(L"Value", TSSForm->AdvIsotopeStringGrid->AllCells[TSSForm->IsoCols[isoOHratio].first][row]);
	 xmlout->EndTag(L"IsotopeMeasurement");
	 }
   if (TSSForm->HTMLCheckBox5->Checked)   // hydrogen
	 WriteIsotopeData(TSSForm->IsoCols[isoHydrogen].first, row, isoHydrogen);
   if (TSSForm->HTMLCheckBox4->Checked)   // sulfur
	 WriteIsotopeData(TSSForm->IsoCols[isoSulfur].first, row, isoSulfur);
   if (TSSForm->HTMLCheckBox6->Checked)   // strontium
	 WriteIsotopeData(TSSForm->IsoCols[isoStrontium].first, row, isoStrontium);
   xmlout->EndTag(L"IsotopeData");

   if (IsSeries)
	 xmlout->EndTag(L"IsotopeSeriesAnalysisUnit");
}
//---------------------------------------------------------------------------

void WriteTLX::WriteIsotopeData(int col, int row, short isotope)
{
   UnicodeString Variable;
   UnicodeString Isotope;
   switch (isotope) {
	 case isoCarbon:
	   Isotope = L"Carbon";
	   Variable = L"del13C";
	   break;
	 case isoNitrogen:
	   Isotope = L"Nitrogen";
	   Variable = L"del15N";
	   break;
	 case isoOxygen:
	   Isotope = L"Oxygen";
	   Variable = L"del18O";
	   break;
	 case isoHydrogen:
	   Isotope = L"Hydrogen";
	   Variable = L"delD";
	   break;
	 case isoSulfur:
	   Isotope = L"Sulfur";
	   Variable = L"del34S";
	   break;
	 case isoStrontium:
	   Isotope = L"Strontium";
	   Variable = L"Sr87Sr86";
	   break;
	 }

   xmlout->BeginTag(L"IsotopeMeasurement", L"type", Isotope);
   xmlout->Element(L"MaterialAnalyzed", TSSForm->AdvIsotopeStringGrid->AllCells[col++][row]);
   xmlout->Element(L"Substrate", TSSForm->AdvIsotopeStringGrid->AllCells[col++][row]);
   UnicodeString Pretreatments = TSSForm->AdvIsotopeStringGrid->AllCells[col++][row];
   if (!Pretreatments.IsEmpty()) {
	 xmlout->BeginTag(L"Pretreatments");
	 vector<UnicodeString> Treatments;
	 ParsePartsIC(Pretreatments, L";", Treatments);
	 // for (unsigned int i=0, row=1; i<Treatments.size(); i++, row++) [
	 for (unsigned int i=0; i<Treatments.size(); i++) {
	   vector<UnicodeString> Elements;
	   ParsePartsIC(Treatments[i], L",", Elements);
	   xmlout->BeginTag(L"Pretreatment");
	   xmlout->Element(L"Order", Elements[0]);
	   xmlout->Element(L"Treatment", Elements[1].SubString(2,Elements[1].Length()-2));
	   if (Elements[2].Length() > 2)
		 xmlout->Element(L"Qualifier", Elements[2].SubString(2,Elements[2].Length()-2));
	   if (Elements.size() == 4)
		 xmlout->Element(L"Value", Elements[3]);
	   xmlout->EndTag(L"Pretreatment");
	   }
	 xmlout->EndTag(L"Pretreatments");
	 }
   TObject* Analyst = TSSForm->AdvIsotopeStringGrid->AllObjects[col++][row];
   if (Analyst != NULL) {
	 int idx = cList->IndexOfObject(Analyst) + 1;
	 xmlout->EmptyElement("Analyst", "ID", idx);
	 }
   xmlout->Element(L"Lab", TSSForm->AdvIsotopeStringGrid->AllCells[col++][row]);
   xmlout->Element(L"LabNr", TSSForm->AdvIsotopeStringGrid->AllCells[col++][row]);
   xmlout->Element(L"Mass", TSSForm->AdvIsotopeStringGrid->AllCells[col++][row]);
   xmlout->Element(L"WeightPercent", TSSForm->AdvIsotopeStringGrid->AllCells[col++][row]);
   xmlout->Element(L"AtomicPercent", TSSForm->AdvIsotopeStringGrid->AllCells[col++][row]);
   if (isotope == isoStrontium)
	 xmlout->Element(L"TotalSr", TSSForm->AdvIsotopeStringGrid->AllCells[col++][row]);
   xmlout->Element(Variable, TSSForm->AdvIsotopeStringGrid->AllCells[col++][row]);
   xmlout->Element(L"SD", TSSForm->AdvIsotopeStringGrid->AllCells[col++][row]);
   if (isotope != isoStrontium)
	 xmlout->Element(L"Scale", TSSForm->AdvIsotopeStringGrid->AllCells[col++][row]);
   xmlout->Element(L"Reps", TSSForm->AdvIsotopeStringGrid->AllCells[col++][row]);
   xmlout->EndTag(L"IsotopeMeasurement");
}
//---------------------------------------------------------------------------

void WriteTLX::WriteCommonPubFields(UnicodeString PublicationType, PUBLICATION* pub)
{
   xmlout->Element("PublicationType", PublicationType);
   xmlout->Element("NeotomaID", pub->NeotomaID);
   xmlout->Element("DOI", pub->DOI);
   xmlout->Element("PublicationYear", pub->PublicationYear);
   xmlout->Element("Citation", pub->Citation);
   xmlout->Element("Notes", pub->Notes);
   WriteAuthors(pub->AuthorList);
}
//---------------------------------------------------------------------------

void WriteTLX::WriteAuthors(vector<AUTHOR>& AuthorList)
{
   if (AuthorList.size() == 0) return;

   xmlout->BeginTag("Authors");
   for (unsigned int i=0; i<AuthorList.size(); i++) {
	 xmlout->BeginTag("Author");
	 int idx = getAuthorContactId((CONTACT*)AuthorList[i].contact);
	 xmlout->EmptyElement("Contact", "ID", idx);
	 xmlout->Element("LastName", AuthorList[i].LastName);
	 xmlout->Element("Initials", AuthorList[i].Initials);
	 xmlout->Element("GivenNames", AuthorList[i].GivenNames);
	 xmlout->Element("Suffix", AuthorList[i].Suffix);
	 xmlout->EndTag("Author");
	 }
   xmlout->EndTag("Authors");
}
//---------------------------------------------------------------------------

void WriteTLX::WriteEditors(vector<EDITOR>& EditorList)
{
   if (EditorList.size() == 0) return;

   xmlout->BeginTag("Editors");
   for (unsigned int i=0; i<EditorList.size(); i++) {
	 xmlout->BeginTag("Editor");
	 xmlout->Element("LastName", EditorList[i].LastName);
	 xmlout->Element("Initials", EditorList[i].Initials);
	 xmlout->Element("Suffix", EditorList[i].Suffix);
	 xmlout->EndTag("Editor");
	 }
   xmlout->EndTag("Editors");
}
//---------------------------------------------------------------------------

void WriteTLX::WriteTranslators(vector<EDITOR>& EditorList)
{
   if (EditorList.size() == 0) return;

   xmlout->BeginTag("Translators");
   for (unsigned int i=0; i<EditorList.size(); i++) {
	 xmlout->BeginTag("Translator");
	 xmlout->Element("LastName", EditorList[i].LastName);
	 xmlout->Element("Initials", EditorList[i].Initials);
	 xmlout->Element("Suffix", EditorList[i].Suffix);
	 xmlout->EndTag("Translator");
	 }
   xmlout->EndTag("Translators");
}
//---------------------------------------------------------------------------

void WriteTLX::WriteEditors(UnicodeString& Editors)
{
   UnicodeString Editor;
   TStringList *eList = new TStringList;
   eList->Text = Editors;
   if (eList->Count > 0) {
	 xmlout->BeginTag("Editors");
	 for (int i=0; i<eList->Count; i++) {
	   Editor = eList->Strings[i];
	   xmlout->Element("Editor", Editor);
	   }
	 xmlout->EndTag("Editors");
	 }
   delete eList;
}
//---------------------------------------------------------------------------

int WriteTLX::getAuthorContactId(CONTACT* AuthorContact)
{
   int idx;
   if ((idx = cList->IndexOfObject((TObject*)AuthorContact)) == -1)
	 MessageDlg("Publication author not in contacts.", mtWarning, TMsgDlgButtons() << mbOK, 0);
   idx++;
   return idx;
}
//---------------------------------------------------------------------------

