//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TNLookup.h"
#ifndef TIGlobalsH
#include "TIGlobals.h"
#endif
#ifndef TIXMLH
#include "TIXML.h"
#endif
#ifndef TIJSONH
#include "TIJSON.h"
#endif
#ifndef TNVarModsH
#include "TNVarMods.h"
#endif

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "ipwjson"
#pragma link "cxButtons"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxLabel"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxGroupBox"
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
#pragma link "ipsjsons"
#pragma resource "*.dfm"
TNeotomaWriteLookupForm *NeotomaWriteLookupForm;
//---------------------------------------------------------------------------

__fastcall TNeotomaWriteLookupForm::TNeotomaWriteLookupForm(short type, TComponent* Owner)
	: TForm(Owner)
{
   RatStart = 0;
   RatEnd = 336;
   RatPos = 0;
   Type = type;
   Activated = false;
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaWriteLookupForm::FormActivate(TObject *Sender)
{
   if (Activated) return;
   Activated = true;
   switch (Type) {
	case LTLOOKUP:
	  WriteLookup();
	  break;
	case LTGEOPOLITICAL:
	  WriteGeoPoliticalUnits();
	  break;
	case LTVARMODS:
	  WriteVarMods();
	  break;
	}
}
//---------------------------------------------------------------------------

void TNeotomaWriteLookupForm::WriteVarMods(void)
{
   Screen->Cursor = crHourGlass;
   UnicodeString LookupFileName = tiGlobals->AppDataTiliaLookupPath;
   LookupFileName += L"NeotomaVariableModifiers.xml";
   NeotomaVarModsLookupForm = new TNeotomaVarModsLookupForm(this);
   NeotomaVarModsLookupForm->WriteVarMods(StatusBar1, LookupFileName, false);
   Screen->Cursor = crDefault;
   cxLabel2->Visible = false;
   FLookupCreated = NeotomaVarModsLookupForm->LookupCreated;
   if (FLookupCreated)
	 cxLabel1->Caption = L"New NeotomaVariableModifiers lookup file generated from Neotoma";
   else
	 cxLabel1->Caption = L"Generation of new NeotomaVariableModifiers lookup file from Neotoma failed!";
   delete NeotomaVarModsLookupForm;
   cxLabel1->Left = (cxGroupBox1->Width - cxLabel1->Width)/2;
   cxLabel1->Visible = true;
   Timer1->Enabled = false;
   Image1->Visible = false;
   StatusBar1->Caption = L"";
   cxButton1->Visible = true;
}
//---------------------------------------------------------------------------

void TNeotomaWriteLookupForm::WriteGeoPoliticalUnits(void)
{
   bool success = true;
   Screen->Cursor = crHourGlass;

   UnicodeString LookupFileName = tiGlobals->AppDataTiliaLookupPath;
   LookupFileName += L"GeoPoliticalUnits.xml";

   WriteXML *xmlout = new WriteXML(LookupFileName);

   try {
   try {
	 xmlout->Declaration("1.0", "UTF-8", "yes");
	 xmlout->DateTime();
	 GeoPoliticalUnits GeoPolUnits(ipsJSONS1, TcpClient1);
	 StatusBar1->Caption = GeoPolUnits.WebServiceName();
	 if (GeoPolUnits.Execute()) {
	   GeoPolUnits.Sort();
	   xmlout->BeginTag("GeoPoliticalUnits");
	   for (unsigned int i=0; i<GeoPolUnits.Size(); i++) {
		 xmlout->BeginTag("GeoPolitical", "ID", GeoPolUnits.Items[i].GeoPoliticalID);
		 xmlout->Element("GeoPoliticalName", GeoPolUnits.Items[i].GeoPoliticalName);
		 xmlout->Element("GeoPoliticalUnit", GeoPolUnits.Items[i].GeoPoliticalUnit);
		 xmlout->Element("Rank", GeoPolUnits.Items[i].Rank);
		 xmlout->Element("HigherGeoPoliticalID", GeoPolUnits.Items[i].HigherGeoPoliticalID);
		 xmlout->EndTag("GeoPolitical");
		 }
	   xmlout->EndTag("GeoPoliticalUnits");
	   }
	 else {
	   success = false;
	   return;
	   }
	 xmlout->Finish();
	 }
   catch(Exception &e)
	 {
	 MessageDlg(e.Message, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 }
   }
   __finally
	 {
	 Screen->Cursor = crDefault;
	 delete xmlout;
	 cxLabel2->Visible = false;
	 FLookupCreated = success;
	 if (success)
	   cxLabel1->Caption = L"New GeoPoliticalUnits lookup file generated from Neotoma";
	 else
	   cxLabel1->Caption = L"Generation of new GeoPoliticalUnits lookup file from Neotoma failed!";
	 cxLabel1->Left = (cxGroupBox1->Width - cxLabel1->Width)/2;
	 cxLabel1->Visible = true;
	 Timer1->Enabled = false;
	 Image1->Visible = false;
	 StatusBar1->Caption = L"";
	 cxButton1->Visible = true;
	 }
}
//---------------------------------------------------------------------------

void TNeotomaWriteLookupForm::WriteLookup(void)
{
   map<int, UnicodeString>::iterator begin;
   map<int, UnicodeString>::iterator end;
   map<int, UnicodeString>::iterator itr;
   bool success = true;
   Screen->Cursor = crHourGlass;
   UnicodeString LookupVersion(L"8");

   UnicodeString LookupFileName = tiGlobals->AppDataTiliaLookupPath;
   LookupFileName += L"Lookup.xml";

   WriteXML *xmlout = new WriteXML(LookupFileName);

   try {
   try {
	 xmlout->Declaration("1.0", "UTF-8", "yes");
	 xmlout->DateTime();
	 xmlout->BeginTag("TiliaLookup");
	 xmlout->Element("Version", LookupVersion);

	 NeotomaDatasetTypesTable DatasetTypes(ipsJSONS1, TcpClient1);
	 StatusBar1->Caption = DatasetTypes.WebServiceName();
	 if (DatasetTypes.Execute()) {
	   xmlout->BeginTag("DatasetTypes");
	   begin = DatasetTypes.Items.begin();
	   end = DatasetTypes.Items.end();
	   for (itr = begin; itr != end; itr++) {
		 UnicodeString DatasetType = itr->second;
		 if (SameText(DatasetType, L"geochronologic")) continue;
		 if (SameText(DatasetType, L"isotope")) continue;
		 //if (SameText(DatasetType, L"loss-on-ignition")) continue;
		 UnicodeString FirstLetter = DatasetType.SubString(1,1).UpperCase();
		 DatasetType.Delete(1,1);
		 DatasetType.Insert(FirstLetter,1);
		 xmlout->Element("DatasetType", DatasetType);
		 }
	   xmlout->EndTag("DatasetTypes");
	   }
	 else {
	   success = false;
	   return;
	   }

	 NeotomaLakeParameterTypesTable LakeParameters(ipsJSONS1, TcpClient1);
	 StatusBar1->Caption = LakeParameters.WebServiceName();
	 if (LakeParameters.Execute()) {
	   xmlout->BeginTag("LakeParameters");
	   for (unsigned int i=0; i<LakeParameters.Size(); i++) {
		 xmlout->BeginTag("LakeParameter");
		 xmlout->Element("Code", LakeParameters.Items[i].LakeParameterCode);
		 xmlout->Element("Name", LakeParameters.Items[i].LakeParameter);
		 xmlout->Element("Menu", LakeParameters.Items[i].LakeParameterShortName);
		 xmlout->EndTag("LakeParameter");
		 }
	   xmlout->EndTag("LakeParameters");
	   }
	 else {
	   success = false;
	   return;
	   }

     NeotomaCollectionTypesTable CollectionTypes(ipsJSONS1, TcpClient1);
	 StatusBar1->Caption = CollectionTypes.WebServiceName();
	 if (CollectionTypes.Execute()) {
	   begin = CollectionTypes.Items.begin();
	   end = CollectionTypes.Items.end();
	   xmlout->BeginTag("CollectionTypes");
	   for (itr = begin; itr != end; itr++)
		 xmlout->Element("CollectionType", itr->second);
	   xmlout->EndTag("CollectionTypes");
	   }
	 else {
	   success = false;
	   return;
	   }

	 NeotomaDepEnvtTypesTable DepEnvtTypes(ipsJSONS1, TcpClient1);
	 StatusBar1->Caption = DepEnvtTypes.WebServiceName();
	 if (DepEnvtTypes.Execute()) {
	   xmlout->BeginTag("DepositionalEnvironments");
	   for (unsigned int i=0; i<DepEnvtTypes.Size(); i++) {
		 xmlout->BeginTag("Context", "ID", DepEnvtTypes.Items[i].DepEnvtID);
		 xmlout->Element("Name", DepEnvtTypes.Items[i].DepEnvt);
		 xmlout->Element("HigherID", DepEnvtTypes.Items[i].DepEnvtHigherID);
		 xmlout->EndTag("Context");
		 }
	   xmlout->EndTag("DepositionalEnvironments");
	   }
	 else {
	   success = false;
	   return;
	   }

	 NeotomaRockTypesTable RockTypes(ipsJSONS1, TcpClient1);
	 StatusBar1->Caption = RockTypes.WebServiceName();
	 if (RockTypes.Execute()) {
	   xmlout->BeginTag("Substrates");
	   for (unsigned int i=0; i<RockTypes.Size(); i++) {
		 xmlout->BeginTag("Substrate", "ID", RockTypes.Items[i].RockTypeID);
		 xmlout->Element("RockType", RockTypes.Items[i].RockType);
		 xmlout->Element("HigherID", RockTypes.Items[i].HigherRockTypeID);
		 xmlout->Element("Description", RockTypes.Items[i].Description);
		 xmlout->EndTag("Substrate");
		 }
	   xmlout->EndTag("Substrates");
	   }
	 else {
	   success = false;
	   return;
	   }

	 NeotomaFaciesTypesTable Facies(ipsJSONS1, TcpClient1);
	 StatusBar1->Caption = Facies.WebServiceName();
	 if (Facies.Execute()) {
	   xmlout->BeginTag("Facies");
	   begin = Facies.Items.begin();
	   end = Facies.Items.end();
	   for (itr = begin; itr != end; itr++)
		 xmlout->Element("FaciesType", itr->second);
	   xmlout->EndTag("Facies");
	   }
	 else {
	   success = false;
	   return;
	   }

	 NeotomaKeywordsTable Keywords(ipsJSONS1, TcpClient1);
	 StatusBar1->Caption = Keywords.WebServiceName();
	 if (Keywords.Execute()) {
	   xmlout->BeginTag("Keywords");
	   begin = Keywords.Items.begin();
	   end = Keywords.Items.end();
	   for (itr = begin; itr != end; itr++) {
		 xmlout->Element("Keword", itr->second);
		 }
	   xmlout->EndTag("Keywords");
	   }
	 else {
	   success = false;
	   return;
	   }

	 NeotomaDepAgentsTable DepAgents(ipsJSONS1, TcpClient1);
	 StatusBar1->Caption = DepAgents.WebServiceName();
	 if (DepAgents.Execute()) {
	   xmlout->BeginTag("DepAgents");
	   begin = DepAgents.Items.begin();
	   end = DepAgents.Items.end();
	   for (itr = begin; itr != end; itr++)
		 xmlout->Element("DepAgent", itr->second);
	   xmlout->EndTag("DepAgents");
	   }
	 else {
	   success = false;
	   return;
	   }

	 NeotomaAgeTypesTable AgeTypes(ipsJSONS1, TcpClient1);
	 //NeotomaAgeTypesTable AgeTypes(ipsJSONS1, TcpClient1);
	 StatusBar1->Caption = AgeTypes.WebServiceName();
	 if (AgeTypes.Execute()) {
	   xmlout->BeginTag("AgeTypes");
	   for (unsigned int i=0; i<AgeTypes.Size(); i++) {
         xmlout->BeginTag("AgeType");
		 xmlout->Element("LongName", AgeTypes.Items[i].AgeType);
		 xmlout->Element("ShortName", AgeTypes.Items[i].ShortAgeType);
		 xmlout->EndTag("AgeType");
	     }
	   xmlout->EndTag("AgeTypes");
	   }
	 else {
	   success = false;
	   return;
	   }

	 NeotomaAggregateOrderTypes AggregateOrderTypes(ipsJSONS1, TcpClient1);
	 StatusBar1->Caption = AggregateOrderTypes.WebServiceName();
	 if (AggregateOrderTypes.Execute()) {
	   xmlout->BeginTag("AggregateOrderTypes");
	   map<int,UnicodeString>::iterator itr;
	   map<int,UnicodeString>::iterator begin = AggregateOrderTypes.Items.begin();
	   map<int,UnicodeString>::iterator end = AggregateOrderTypes.Items.end();
	   for (itr = begin; itr != end; itr++)
		 xmlout->Element("AggregateOrderType", itr->second);
	   xmlout->EndTag("AggregateOrderTypes");
	   }
	 else {
	   success = false;
	   return;
	   }

	 NeotomaRepositoryInstitutionsTable Repositories(ipsJSONS1, TcpClient1);
	 StatusBar1->Caption = Repositories.WebServiceName();
	 if (Repositories.Execute()) {
	   xmlout->BeginTag("Repositories");
	   for (unsigned int i=0; i<Repositories.Size(); i++) {
		 xmlout->BeginTag("Repository");
		 xmlout->Element("Acronym", Repositories.Items[i].Acronym);
		 xmlout->Element("Institution", Repositories.Items[i].Repository);
		 xmlout->Element("Notes", Repositories.Items[i].Notes);
		 xmlout->EndTag("Repository");
		 }
	   xmlout->EndTag("Repositories");
	   }
	 else {
	   success = false;
	   return;
	   }

	 NeotomaGeochronTypesTable GeochronTypes(ipsJSONS1, TcpClient1);
	 StatusBar1->Caption = GeochronTypes.WebServiceName();
	 if (GeochronTypes.Execute()) {
	   xmlout->BeginTag(L"GeochronTypes");
	   begin = GeochronTypes.Items.begin();
	   end = GeochronTypes.Items.end();
	   for (itr = begin; itr != end; itr++) {
		 xmlout->BeginTag(L"GeochronType");
		 xmlout->Element(L"Type", itr->second);
		 if (SameText(itr->second, L"Carbon-14")) {
		   NeotomaRadiocarbonMethodsTable Methods(ipsJSONS1, TcpClient1);
		   StatusBar1->Caption = Methods.WebServiceName();
		   if (!Methods.Execute()) {
			 success = false;
			 return;
			 }
		   xmlout->BeginTag(L"Methods");
		   map<int,UnicodeString>::iterator it;
		   for (it = Methods.Items.begin(); it != Methods.Items.end(); it++)
			 xmlout->Element(L"Method", L"ID", it->first, it->second);
		   xmlout->EndTag(L"Methods");
		   }
		 xmlout->EndTag(L"GeochronType");
		 }
	   xmlout->EndTag("GeochronTypes");
	   }
	 else {
	   success = false;
	   return;
	   }

	 NeotomaFractionDatedTable Fraction(ipsJSONS1, TcpClient1);
	 StatusBar1->Caption = Fraction.WebServiceName();
	 if (Fraction.Execute()) {
	   xmlout->BeginTag("FractionDated");
	   begin = Fraction.Items.begin();
	   end = Fraction.Items.end();
	   for (itr = begin; itr != end; itr++)
		 xmlout->Element("Fraction", itr->second);
	   xmlout->EndTag("FractionDated");
	   }
	 else {
	   success = false;
	   return;
	   }

	 NeotomaChronControlTypesTable ChronControlTypes(ipsJSONS1, TcpClient1);
	 StatusBar1->Caption = ChronControlTypes.WebServiceName();
	 if (ChronControlTypes.Execute()) {
	   xmlout->BeginTag("ChronologyControls");
	   for (unsigned int i=0; i<ChronControlTypes.Size(); i++) {
		 xmlout->BeginTag("ChronControlType", "ID", ChronControlTypes.Items[i].ChronControlTypeID);
		 xmlout->Element("Name", ChronControlTypes.Items[i].ChronControlType);
		 xmlout->Element("HigherID", ChronControlTypes.Items[i].HigherChronControlTypeID);
		 xmlout->EndTag("ChronControlType");
		 }
	   xmlout->EndTag("ChronologyControls");
	   }
	 else {
	   success = false;
	   return;
	   }

	 NeotomaEventTypesTable EventTypes(ipsJSONS1, TcpClient1);
	 StatusBar1->Caption = EventTypes.WebServiceName();
	 if (!EventTypes.Execute()) {
	   success = false;
	   return;
	   }
	 NeotomaEventsTable Events(ipsJSONS1, TcpClient1);
	 StatusBar1->Caption = Events.WebServiceName();
	 if (!Events.Execute()) {
	   success = false;
	   return;
	   }

	 xmlout->BeginTag("Events");
	 begin = EventTypes.Items.begin();
	 end = EventTypes.Items.end();
	 for (itr = begin; itr != end; itr++) {
	   UnicodeString EventType = itr->second;
	   UnicodeString Tag = EventType;
	   int idx = 1;
	   int len = Tag.Length();
	   bool capitalize = false;
	   while (idx <= len) {
		 if (capitalize) {
		   UnicodeString CapLetter = Tag.SubString(idx,1).UpperCase();
		   Tag.Delete(idx,1);
		   Tag.Insert(CapLetter,idx);
		   capitalize = false;
		   }
		 if (Tag.SubString(idx,1) == L" ") {
		   Tag.Delete(idx,1);
		   len--;
		   capitalize = true;
		   }
		 else
		   idx++;
		 }
	   UnicodeString SortType = L"Null";
	   if (ContainsText(EventType, L"Tephra"))
		 SortType = L"Name";
	   else if (ContainsText(EventType, L"Geomagnetic"))
		 SortType = L"CalAge";

	   xmlout->BeginTag(Tag, "ChronologyControl", EventType, "Sort", SortType);
	   for (unsigned int i=0; i<Events.Size(); i++) {
		 if (Events.Items[i].EventTypeID == itr->first) {
		   xmlout->BeginTag("EventName");
		   xmlout->Element("Name", Events.Items[i].EventName);
		   xmlout->Element("C14Age", Events.Items[i].C14Age);
		   xmlout->Element("C14AgeYounger", Events.Items[i].C14AgeYounger);
		   xmlout->Element("C14AgeOlder", Events.Items[i].C14AgeOlder);
		   xmlout->Element("CalAge", Events.Items[i].CalAge);
		   xmlout->Element("CalAgeYounger", Events.Items[i].CalAgeYounger);
		   xmlout->Element("CalAgeOlder", Events.Items[i].CalAgeOlder);
		   xmlout->Element("Notes", Events.Items[i].Notes);
		   xmlout->EndTag("EventName");
		   }
		 }
	   xmlout->EndTag(Tag);
	   }
	 xmlout->EndTag("Events");

	 NeotomaRelativeAgeScalesTable RelativeAgeScales(ipsJSONS1, TcpClient1);
	 StatusBar1->Caption = RelativeAgeScales.WebServiceName();
	 if (!RelativeAgeScales.Execute()) {
	   success = false;
	   return;
	   }
	 NeotomaRelativeAgesTable RelativeAges(ipsJSONS1, TcpClient1);
	 StatusBar1->Caption = RelativeAges.WebServiceName();
	 if (!RelativeAges.Execute()) {
	   success = false;
	   return;
	   }

	 xmlout->BeginTag("RelativeAgeScales");
	 begin = RelativeAgeScales.Items.begin();
	 end = RelativeAgeScales.Items.end();
	 for (itr = begin; itr != end; itr++) {
	   xmlout->BeginTag("RelativeAgeScale", "Name", itr->second);
	   for (unsigned int i=0; i<RelativeAges.Size(); i++) {
		 if (RelativeAges.Items[i].RelativeAgeScaleID == itr->first) {
		   xmlout->BeginTag("RelativeAge");
		   xmlout->Element("Name", RelativeAges.Items[i].RelativeAge);
		   xmlout->Element("C14AgeYounger", RelativeAges.Items[i].C14AgeYounger);
		   xmlout->Element("C14AgeOlder", RelativeAges.Items[i].C14AgeOlder);
		   xmlout->Element("CalAgeYounger", RelativeAges.Items[i].CalAgeYounger);
		   xmlout->Element("CalAgeOlder", RelativeAges.Items[i].CalAgeOlder);
		   xmlout->Element("Notes", RelativeAges.Items[i].Notes);
		   xmlout->EndTag("RelativeAge");
		   }
		 }
	   xmlout->EndTag("RelativeAgeScale");
	   }
	 xmlout->EndTag("RelativeAgeScales");

	 NeotomaCalibrationCurvesTable CalibCurves(ipsJSONS1, TcpClient1);
	 StatusBar1->Caption = CalibCurves.WebServiceName();
	 if (CalibCurves.Execute()) {
	   xmlout->BeginTag("CalibrationCurves");
	   for (unsigned int i=0; i<CalibCurves.Size(); i++)
		 xmlout->Element("CalibrationCurve", CalibCurves.Items[i].CalibrationCurve);
	   xmlout->EndTag("CalibrationCurves");
	   }
	 else {
	   success = false;
	   return;
	   }

	 NeotomaCalibrationProgramsTable CalibProgs(ipsJSONS1, TcpClient1);
	 StatusBar1->Caption = CalibProgs.WebServiceName();
	 if (CalibProgs.Execute()) {
	   xmlout->BeginTag("CalibrationPrograms");
	   for (unsigned int i=0; i<CalibProgs.Size(); i++) {
		 xmlout->BeginTag("CalibrationProgram");
		 xmlout->Element("Name", CalibProgs.Items[i].CalibrationProgram);
		 xmlout->Element("Version", CalibProgs.Items[i].Version);
		 xmlout->EndTag("CalibrationProgram");
		 }
	   xmlout->EndTag("CalibrationPrograms");
	   }
	 else {
	   success = false;
	   return;
	   }

	 NeotomaSpecimenSexTypes Sex(ipsJSONS1, TcpClient1);
	 StatusBar1->Caption = Sex.WebServiceName();
	 if (Sex.Execute()) {
	   xmlout->BeginTag("SpecimenSex");
	   map<int,UnicodeString>::iterator itr;
	   map<int,UnicodeString>::iterator begin = Sex.Items.begin();
	   map<int,UnicodeString>::iterator end = Sex.Items.end();
	   for (itr = begin; itr != end; itr++)
		 xmlout->Element("Sex", itr->second);
	   xmlout->EndTag("SpecimenSex");
	   }
	 else {
	   success = false;
	   return;
	   }

	 NeotomaSpecimenDomStatTypes DomStatTypes(ipsJSONS1, TcpClient1);
	 StatusBar1->Caption = DomStatTypes.WebServiceName();
	 if (DomStatTypes.Execute()) {
	   xmlout->BeginTag("SpecimenDomesticStatus");
	   map<int,UnicodeString>::iterator itr;
	   map<int,UnicodeString>::iterator begin = DomStatTypes.Items.begin();
	   map<int,UnicodeString>::iterator end = DomStatTypes.Items.end();
	   for (itr = begin; itr != end; itr++)
		 xmlout->Element("DomesticStatus", itr->second);
	   xmlout->EndTag("SpecimenDomesticStatus");
	   }
	 else {
	   success = false;
	   return;
	   }

	 NeotomaGetIsoMaterialAnalyzedAndSubstrate MatAnal(ipsJSONS1, TcpClient1);
	 StatusBar1->Caption = MatAnal.WebServiceName();
	 if (MatAnal.Execute()) {
	   xmlout->BeginTag("IsoMaterialsAnalyzed");
	   multimap<UnicodeString,UnicodeString>::iterator itr;
	   multimap<UnicodeString,UnicodeString>::iterator begin = MatAnal.Items.begin();
	   multimap<UnicodeString,UnicodeString>::iterator end = MatAnal.Items.end();
	   for (itr = begin; itr != end; itr++) {
		 xmlout->BeginTag("IsoMaterialAnalyzed");
		 xmlout->Element("IsoMaterial", itr->first);
		 xmlout->Element("IsoSubstrate", itr->second);
		 xmlout->EndTag("IsoMaterialAnalyzed");
		 }
	   xmlout->EndTag("IsoMaterialsAnalyzed");
	   }
	 else {
	   success = false;
	   return;
	   }

	 NeotomaGetIsoPretreatmentTypes Pretreatments(ipsJSONS1, TcpClient1);
	 StatusBar1->Caption = Pretreatments.WebServiceName();
	 if (Pretreatments.Execute()) {
	   xmlout->BeginTag("IsoPretreatments");
	   for (unsigned int i=0; i<Pretreatments.Size(); i++) {
		 xmlout->BeginTag("IsoPretreatment");
		 xmlout->Element("IsoPretreatmentType", Pretreatments.Items[i].IsoPretreatmentType);
		 xmlout->Element("IsoPretreatmentQualifier", Pretreatments.Items[i].IsoPretreatmentQualifier);
		 xmlout->EndTag("IsoPretreatment");
		 }
	   xmlout->EndTag("IsoPretreatments");
	   }
	 else {
	   success = false;
	   return;
	   }

	 NeotomaSampleOriginTypes SampOrigins(ipsJSONS1, TcpClient1);
	 StatusBar1->Caption = SampOrigins.WebServiceName();
	 if (SampOrigins.Execute()) {
	   xmlout->BeginTag("IsoSamplingOrigins");
	   map<int,UnicodeString>::iterator itr;
	   map<int,UnicodeString>::iterator begin = SampOrigins.Items.begin();
	   map<int,UnicodeString>::iterator end = SampOrigins.Items.end();
	   for (itr = begin; itr != end; itr++)
		 xmlout->Element("IsoSamplingOrigin", itr->second);
	   xmlout->EndTag("IsoSamplingOrigins");
	   }
	 else {
	   success = false;
	   return;
	   }

	 NeotomaGetIsoBioMarkers BioMark(ipsJSONS1, TcpClient1);
	 StatusBar1->Caption = BioMark.WebServiceName();
	 if (BioMark.Execute()) {
	   xmlout->BeginTag("IsoBioMarkers");
	   multimap<UnicodeString,UnicodeString>::iterator itr;
	   multimap<UnicodeString,UnicodeString>::iterator begin = BioMark.Items.begin();
	   multimap<UnicodeString,UnicodeString>::iterator end = BioMark.Items.end();
	   for (itr = begin; itr != end; itr++) {
		 xmlout->BeginTag("IsoBioMarker");
		 xmlout->Element("IsoBioMarkerType", itr->first);
		 xmlout->Element("IsoBioMarkerBandType", itr->second);
		 xmlout->EndTag("IsoBioMarker");
		 }
	   xmlout->EndTag("IsoBioMarkers");
	   }
	 else {
	   success = false;
	   return;
	   }

	 NeotomaIsoInstrumentationTypes Instrument(ipsJSONS1, TcpClient1);
	 StatusBar1->Caption = Instrument.WebServiceName();
	 if (Instrument.Execute()) {
	   xmlout->BeginTag("IsoInstrumentation");
	   map<int,UnicodeString>::iterator itr;
	   map<int,UnicodeString>::iterator begin = Instrument.Items.begin();
	   map<int,UnicodeString>::iterator end = Instrument.Items.end();
	   for (itr = begin; itr != end; itr++)
		 xmlout->Element("IsoInstrument", itr->second);
	   xmlout->EndTag("IsoInstrumentation");
	   }
	 else {
	   success = false;
	   return;
	   }

	 NeotomaIsoSampleIntroSystemTypes IntroSys(ipsJSONS1, TcpClient1);
	 StatusBar1->Caption = IntroSys.WebServiceName();
	 if (IntroSys.Execute()) {
	   xmlout->BeginTag("IsoSampleIntroSystems");
	   map<int,UnicodeString>::iterator itr;
	   map<int,UnicodeString>::iterator begin = IntroSys.Items.begin();
	   map<int,UnicodeString>::iterator end = IntroSys.Items.end();
	   for (itr = begin; itr != end; itr++)
		 xmlout->Element("IsoSampleIntroSystem", itr->second);
	   xmlout->EndTag("IsoSampleIntroSystems");
	   }
	 else {
	   success = false;
	   return;
	   }

	 NeotomaIsoStandardTypes Standards(ipsJSONS1, TcpClient1);
	 StatusBar1->Caption = Standards.WebServiceName();
	 if (Standards.Execute()) {
	   xmlout->BeginTag("IsoStandards");
	   for (unsigned int i=0; i<Standards.Size(); i++) {
		 xmlout->BeginTag("IsoStandard");
		 xmlout->Element("IsoStandardName", Standards.Items[i].IsoStandardType);
		 xmlout->Element("IsoStandardMaterial", Standards.Items[i].IsoStandardMaterial);
		 xmlout->EndTag("IsoStandard");
		 }
	   xmlout->EndTag("IsoStandards");
	   }
	 else {
	   success = false;
	   return;
	   }

	 NeotomaGetIsoVariableScaleTypes IsoScale(ipsJSONS1, TcpClient1);
	 StatusBar1->Caption = IsoScale.WebServiceName();
	 if (IsoScale.Execute()) {
	   xmlout->BeginTag("IsoVariableScales");
	   multimap<UnicodeString,UnicodeString>::iterator itr;
	   multimap<UnicodeString,UnicodeString>::iterator begin = IsoScale.Items.begin();
	   multimap<UnicodeString,UnicodeString>::iterator end = IsoScale.Items.end();
	   for (itr = begin; itr != end; itr++) {
		 xmlout->BeginTag("IsoVariableScale");
		 xmlout->Element("IsoVariable", itr->first);
		 xmlout->Element("IsoScale", itr->second);
		 xmlout->EndTag("IsoVariableScale");
		 }
	   xmlout->EndTag("IsoVariableScales");
	   }
	 else {
	   success = false;
	   return;
	   }

	 xmlout->EndTag("TiliaLookup");
	 xmlout->Finish();
	 }
   catch(Exception &e)
	 {
	 MessageDlg(e.Message, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 }
   }
   __finally
	 {
	 Screen->Cursor = crDefault;
	 delete xmlout;
	 cxLabel2->Visible = false;
	 FLookupCreated = success;
	 if (success)
	   cxLabel1->Caption = L"New Lookup file generated from Neotoma";
	 else
	   cxLabel1->Caption = L"Generation of new lookup file from Neotoma failed!";
	 cxLabel1->Left = (cxGroupBox1->Width - cxLabel1->Width)/2;
	 cxLabel1->Visible = true;
	 Timer1->Enabled = false;
	 Image1->Visible = false;
	 StatusBar1->Caption = L"";
	 cxButton1->Visible = true;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaWriteLookupForm::Timer1Timer(TObject *Sender)
{
   RatPos += 48;
   if (RatPos > RatEnd)
	 RatPos = RatStart;
   Image1->Left = RatPos;
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaWriteLookupForm::ipsJSONS1SSLServerAuthentication(TObject *Sender,
          TipsJSONSSSLServerAuthenticationEventParams *e)
{
   e->Accept = true;
}
//---------------------------------------------------------------------------

