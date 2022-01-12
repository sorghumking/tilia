//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <algorithm>
#include <VarHlpr.hpp>
#include <Clipbrd.hpp>
#include "TINtmWeb.h"
#ifndef TIGlobalsH
#include "TIGlobals.h"
#endif
#ifndef TIMemoH
#include "TIMemo.h"
#endif
#ifndef TIShoMemH
#include "TIShoMem.h"
#endif
#ifndef TNLoginH
#include "TNLogin.h"
#endif

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "ipwjson"
#pragma link "AdvCGrid"
#pragma link "AdvGrid"
#pragma link "AdvObj"
#pragma link "AdvUtil"
#pragma link "BaseGrid"
#pragma link "cxButtons"
#pragma link "cxControls"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxSplitter"
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
#pragma link "dxSkinOffice2016Colorful"
#pragma link "dxSkinOffice2016Dark"
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
#pragma link "dxSkinVisualStudio2013Blue"
#pragma link "dxSkinVisualStudio2013Dark"
#pragma link "dxSkinVisualStudio2013Light"
#pragma link "dxSkinVS2010"
#pragma link "dxSkinWhiteprint"
#pragma link "dxSkinXmas2008Blue"
#pragma link "AdvEdit"
#pragma link "AdvPageControl"
#pragma link "AdvCGrid"
#pragma link "AdvEdit"
#pragma link "AdvGrid"
#pragma link "AdvObj"
#pragma link "AdvPageControl"
#pragma link "AdvUtil"
#pragma link "BaseGrid"
#pragma link "cxButtons"
#pragma link "cxControls"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxSplitter"
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
#pragma link "dxSkinOffice2016Colorful"
#pragma link "dxSkinOffice2016Dark"
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
#pragma link "dxSkinVisualStudio2013Blue"
#pragma link "dxSkinVisualStudio2013Dark"
#pragma link "dxSkinVisualStudio2013Light"
#pragma link "dxSkinVS2010"
#pragma link "dxSkinWhiteprint"
#pragma link "dxSkinXmas2008Blue"
#pragma link "ipwjson"
#pragma link "AdvMemo"
#pragma link "AdvMemoStylerManager"
#pragma link "advmjson"
#pragma link "cxRadioGroup"
#pragma link "cxContainer"
#pragma link "cxEdit"
#pragma link "cxLabel"
#pragma link "ipshttps"
#pragma link "ipsjsons"
#pragma link "ipscertmgr"
#pragma link "ipsipdaemons"
#pragma resource "*.dfm"
TWebServicesForm *WebServicesForm;
TTSServicesForm *TSServicesForm;

//---------------------------------------------------------------------------
template <class T> service<T>::service(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
{
   name = new T(ipsjsons, tcpClient);
}
//---------------------------------------------------------------------------

bool compstric (UnicodeString str1, UnicodeString str2) { return (str1.LowerCase() < str2.LowerCase()); }
//---------------------------------------------------------------------------

__fastcall TWebServicesForm::TWebServicesForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TWebServicesForm::FormCreate(TObject *Sender)
{
   Schema = L"TI.";
   vector<UnicodeString> serv;

   serv.push_back(L"GetAggregateChronByDatasetID");
   serv.push_back(L"GetAggregateDatasetByName");
   serv.push_back(L"GetAggregateOrderTypes");
   serv.push_back(L"GetAnalysisUnit");
   serv.push_back(L"GetSites");
   serv.push_back(L"GetTaxaByNameList");
   serv.push_back(L"GetContactByFamilyName");
   serv.push_back(L"GetAgeTypesTable");
   serv.push_back(L"GetAgeTypeID");
   serv.push_back(L"GetAliasContactNames");
   serv.push_back(L"GetAllDatasetAuthors");
   serv.push_back(L"GetAllDatasetPIs");
   serv.push_back(L"GetAnalysisUnitByID");
   serv.push_back(L"GetAnalysisUnitSampleCount");
   serv.push_back(L"GetAnalysisUnitsByCollUnitID");
   serv.push_back(L"GetCalibrationCurvesTable");
   serv.push_back(L"GetCalibrationProgramsTable");
   serv.push_back(L"GetChildTaxa");
   serv.push_back(L"GetChildTaxaCount");
   serv.push_back(L"GetChildTaxaForAllSites");
   serv.push_back(L"GetChronConrolTypeByName");
   serv.push_back(L"GetChronControlsByChronControlID");
   serv.push_back(L"GetChronControlTypeHighestID");
   serv.push_back(L"GetChronControlTypesTable");
   serv.push_back(L"GetChronoControlsByAnalysisUnitID");
   serv.push_back(L"GetChronoControlsByChronologyID");
   serv.push_back(L"GetChronologiesByCollUnitID");
   serv.push_back(L"GetCollectionTypeByID");
   serv.push_back(L"GetCollectionTypesTable");
   serv.push_back(L"GetCollector");
   serv.push_back(L"GetCollUnitByID");
   serv.push_back(L"GetCollUnitHandleCount");
   serv.push_back(L"GetCollUnitsBySiteID");
   serv.push_back(L"GetCollUnitSummaryBySiteID");
   serv.push_back(L"GetConstituentDatabaseNameByID");
   serv.push_back(L"GetConstituentDatabases");
   serv.push_back(L"GetContactByContactName");
   serv.push_back(L"GetContactByFamilyNameAndInitials");
   serv.push_back(L"GetContactByID");
   serv.push_back(L"GetContactStatusesTable");
   serv.push_back(L"GetContextDatasetTypeCount");
   serv.push_back(L"GetContextsDatasetTypesTable");
   serv.push_back(L"GetDataProcessor");
   serv.push_back(L"GetDatasetAuthorsDatasetTypes");
   serv.push_back(L"GetDatasetChrons");
   serv.push_back(L"GetDatasetCitations");
   serv.push_back(L"GetDatasetData");
   serv.push_back(L"GetDatasetDatabase");
   serv.push_back(L"GetDatasetIDByCollUnitAndType");
   serv.push_back(L"GetDatasetIDforDatasetTypeIDforGeochronAnalUnit");
   serv.push_back(L"GetDatasetIDsByTaxonID");
   serv.push_back(L"GetDatasetPIs");
   serv.push_back(L"GetDatasetPIsDatasetTypes");
   serv.push_back(L"GetDatasetPublicationIDs");
   serv.push_back(L"GetDatasetPublications");
   serv.push_back(L"GetDatasetPublicationStatus");
   serv.push_back(L"GetDatasetRepository");
   serv.push_back(L"GetDatasetRepositorySpecimenNotes");
   serv.push_back(L"GetDatasetSampleAnalysts");
   serv.push_back(L"GetDatasetSampleDepAgents");
   serv.push_back(L"GetDatasetSampleIDs");
   serv.push_back(L"GetDatasetSampleKeywords");
   serv.push_back(L"GetDatasetSamples");
   serv.push_back(L"GetDatasetsByContactID");
   serv.push_back(L"GetDatasetsByID");
   serv.push_back(L"GetDatasetsBySiteID");
   serv.push_back(L"GetDatasetSpecimenGenBankNrs");
   serv.push_back(L"GetDatasetSpecimens");
   serv.push_back(L"GetDatasetSpecimenTaphonomy");
   serv.push_back(L"GetDatasetSynonyms");
   serv.push_back(L"GetDatasetTaxonNotes");
   serv.push_back(L"GetDatasetTaxonNotesByTaxonID");
   serv.push_back(L"GetDatasetTypes");
   serv.push_back(L"GetDatasetTypesByName");
   serv.push_back(L"GetDatasetTypesByTaxaGroupID");
   serv.push_back(L"GetDatasetTypesHavingData");
   serv.push_back(L"GetDatasetVariables");
   serv.push_back(L"GetDatasetVariableSynonyms");
   serv.push_back(L"GetDepAgentByName");
   serv.push_back(L"GetDepAgentsTypesTable");
   serv.push_back(L"GetDepEnvtByID");
   serv.push_back(L"GetDepEnvtTypesTable");
   serv.push_back(L"GetEcolGroupsByEcolSetID");
   serv.push_back(L"GetEcolGroupsByTaxaGroupIDList");
   serv.push_back(L"GetEcolGroupsByVariableIDList");
   serv.push_back(L"GetEcolGroupsTable");
   serv.push_back(L"GetEcolGroupTypesTable");
   serv.push_back(L"GetEcolSetCountsByTaxaGroupID");
   serv.push_back(L"GetEcolSetsGroupsByTaxonID");
   serv.push_back(L"GetEcolSetTypesTable");
   serv.push_back(L"GetElementDatasetTaxaGroupCount");
   serv.push_back(L"GetElementDatasetTaxaGroupsTable");
   serv.push_back(L"GetElementMaturitiesTable");
   serv.push_back(L"GetElementMaturityByName");
   serv.push_back(L"GetElementPartID");
   serv.push_back(L"GetElementPortionByName");
   serv.push_back(L"GetElementPortionsTable");
   serv.push_back(L"GetElementsByTaxonID");
   serv.push_back(L"GetElementSymmetriesTable");
   serv.push_back(L"GetElementSymmetryByName");
   serv.push_back(L"GetElementTaxaGroupID");
   serv.push_back(L"GetElementTaxaGroupMaturitiesTable");
   serv.push_back(L"GetElementTaxaGroupPortionsTable");
   serv.push_back(L"GetElementTaxaGroupsTable");
   serv.push_back(L"GetElementTaxaGroupSymmetriesTable");
   serv.push_back(L"GetElementTypeByName");
   serv.push_back(L"GetElementTypeFromVariableElement");
   serv.push_back(L"GetElementTypesByNameList");
   serv.push_back(L"GetElementTypesByTaxaGroupID");
   serv.push_back(L"GetElementTypesForTaxonTaxaGroup");
   serv.push_back(L"GetElementTypesTable");
   serv.push_back(L"GetEventByName");
   serv.push_back(L"GetEventChronControlTypeID");
   serv.push_back(L"GetEventPublications");
   serv.push_back(L"GetEventsByChronologyID");
   serv.push_back(L"GetEventsTable");
   serv.push_back(L"GetEventTypeByName");
   serv.push_back(L"GetEventTypesTable");
   serv.push_back(L"GetFaciesTypeByName");
   serv.push_back(L"GetFaciesTypesTable");
   serv.push_back(L"GetFractionDatedByName");
   serv.push_back(L"GetFractionDatedTable");
   serv.push_back(L"GetFractionsDatedByList");
   serv.push_back(L"GetGeochronAnalysisUnit");
   serv.push_back(L"GetGeochronAnalysisUnitsByDatasetID");
   serv.push_back(L"GetGeochronByDatasetID");
   serv.push_back(L"GetGeochronByGeochronID");
   serv.push_back(L"GetGeochronControlCount");
   serv.push_back(L"GetGeoChronControlsByChronologyID");
   serv.push_back(L"GetGeochronIDCount");
   serv.push_back(L"GetGeochronTypeID");
   serv.push_back(L"GetGeochronTypesTable");
   serv.push_back(L"GetGeoPolBySiteName");
   serv.push_back(L"GetGeoPoliticalUnitsTable");
   serv.push_back(L"GetGeoPolNumberOfSubdivs");
   serv.push_back(L"GetGeoPolUnitByHigherID");
   serv.push_back(L"GetGeoPolUnitByID");
   serv.push_back(L"GetGeoPolUnitByNameAndHigherID");
   serv.push_back(L"GetGeoPolUnitByNameAndRank");
   serv.push_back(L"GetGeoPolUnitByRank");
   serv.push_back(L"GetGeoPolUnitsBySiteID");
   serv.push_back(L"GetInvalidTaxaByTaxaGroupID");
   serv.push_back(L"GetInvalidTaxaByTaxaGroupIDList");
   serv.push_back(L"GetInvalidTaxonByName");
   serv.push_back(L"GetInvalidTaxonSynonymyCount");
   serv.push_back(L"GetInvestigator");
   serv.push_back(L"GetIsoBioMarkers");
   serv.push_back(L"GetIsoInstrumentationTypes");
   serv.push_back(L"GetIsoMaterialAnalyzedAndSubstrate");
   serv.push_back(L"GetIsoMaterialAnalyzedTypes");
   serv.push_back(L"GetIsoPretreatmentTypes");
   serv.push_back(L"GetIsoSampleIntroSystemTypes");
   serv.push_back(L"GetIsoSampleOriginTypes");
   serv.push_back(L"GetIsoStandardTypes");
   serv.push_back(L"GetIsoSubstrates");
   serv.push_back(L"GetIsoVariableScaleIDs");
   serv.push_back(L"GetIsoVariableScaleTypes");
   serv.push_back(L"GetKeywordsTable");
   serv.push_back(L"GetLakeParameterTypesTable");
   serv.push_back(L"GetLakeParamsBySiteID");
   serv.push_back(L"GetLithologyByCollUnitID");
   serv.push_back(L"GetMaxPubIDByPubIDType");
   serv.push_back(L"GetMinPubIDByPubIDType");
   serv.push_back(L"GetNearestSites");
   serv.push_back(L"GetNextLowerGeoPolCountByNames");
   serv.push_back(L"GetNextPublicationByID");
   serv.push_back(L"GetNextPublicationByIDAndPubTypeID");
   serv.push_back(L"GetPollenSporeHigherTaxa");
   serv.push_back(L"GetPredefinedTaxaEcolGroupsByDatasetTypeList");
   serv.push_back(L"GetPreviousPublicationByID");
   serv.push_back(L"GetPreviousPublicationByIDAndPubTypeID");
   serv.push_back(L"GetProcedureInputParams");
   serv.push_back(L"GetPublicationAuthors");
   serv.push_back(L"GetPublicationByCitation");
   serv.push_back(L"GetPublicationByFamilyName");
   serv.push_back(L"GetPublicationByID");
   serv.push_back(L"GetPublicationByIDList");
   serv.push_back(L"GetPublicationEditors");
   serv.push_back(L"GetPublicationsByContactID");
   serv.push_back(L"GetPublicationsByGeochronID");
   serv.push_back(L"GetPublicationsTable");
   serv.push_back(L"GetPublicationTranslators");
   serv.push_back(L"GetPublicationTypesTable");
   serv.push_back(L"GetRadiocarbonByGeochronID");
   serv.push_back(L"GetRadiocarbonMethodID");
   serv.push_back(L"GetRadiocarbonMethodsTable");
   serv.push_back(L"GetRecentUploads");
   serv.push_back(L"GetRecentUploadsv1");
   serv.push_back(L"GetRelativeAgeByName");
   serv.push_back(L"GetRelativeAgeChronControlType");
   serv.push_back(L"GetRelativeAgePublications");
   serv.push_back(L"GetRelativeAgesByChronologyID");
   serv.push_back(L"GetRelativeAgeScaleByName");
   serv.push_back(L"GetRelativeAgeScalesTable");
   serv.push_back(L"GetRelativeAgesTable");
   serv.push_back(L"GetRelativeAgeUnitsByAgeScale");
   serv.push_back(L"GetRepositoryInstitution");
   serv.push_back(L"GetRepositoryInstitutionsTable");
   serv.push_back(L"GetRockTypeByID");
   serv.push_back(L"GetRockTypeByName");
   serv.push_back(L"GetRockTypesTable");
   serv.push_back(L"GetSampleAge");
   serv.push_back(L"GetSampleAgesByChronID");
   serv.push_back(L"GetSampleIDForDatasetIDFromGeochronAnalUnit");
   serv.push_back(L"GetSampleIDForDatasetTypeIDFromGeochronAnalUnit");
   serv.push_back(L"GetSampleKeywords");
   serv.push_back(L"GetSampleParents");
   serv.push_back(L"GetSampleTaxonCount");
   serv.push_back(L"GetSiteMetaData");
   serv.push_back(L"GetSitesByDatabaseAndDatasetType");
   serv.push_back(L"GetSitesByDatasetType");
   serv.push_back(L"GetSpecimenByIDCount");
   serv.push_back(L"GetSpecimenDateBySpecimenDateID");
   serv.push_back(L"GetSpecimenDateCalBySpecimenDateID");
   serv.push_back(L"GetSpecimenDatesByGeochronDatasetID");
   serv.push_back(L"GetSpecimenDatesByTaxonID");
   serv.push_back(L"GetSpecimenDomesticStatusByName");
   serv.push_back(L"GetSpecimenDomesticStatusTypes");
   serv.push_back(L"GetSpecimenIsotopeDataset");
   serv.push_back(L"GetSpecimenSampleID");
   serv.push_back(L"GetSpecimenSexByName");
   serv.push_back(L"GetSpecimenSexTypes");
   serv.push_back(L"GetSpecimenTaxonID");
   serv.push_back(L"GetSynonymsForInvalidTaxonID");
   serv.push_back(L"GetSynonymsForValidTaxonID");
   serv.push_back(L"GetSynonymType");
   serv.push_back(L"GetSynonymTypesTable");
   serv.push_back(L"GetTableMaxID");
   serv.push_back(L"GetTableMinID");
   serv.push_back(L"GetTableRecordCount");
   serv.push_back(L"GetTaphonomicSystemByName");
   serv.push_back(L"GetTaphonomicSystemsByDatasetType");
   serv.push_back(L"GetTaphonomicSystemsDatasetTypesTable");
   serv.push_back(L"GetTaphonomicSystemsTable");
   serv.push_back(L"GetTaphonomicTypeID");
   serv.push_back(L"GetTaphonomicTypesByIDList");
   serv.push_back(L"GetTaphonomicTypesBySystem");
   serv.push_back(L"GetTaphonomicTypesTable");
   serv.push_back(L"GetTaxaByCodeAndTaxaGroupID");
   serv.push_back(L"GetTaxaByNamesCount");
   serv.push_back(L"GetTaxaByTaxaGroupID");
   serv.push_back(L"GetTaxaEcolGroupsByDatasetTypeList");
   serv.push_back(L"GetTaxaGroupByID");
   serv.push_back(L"GetTaxaGroupElementTypes");
   serv.push_back(L"GetTaxaGroupID");
   serv.push_back(L"GetTaxaGroupsForDatasetType");
   serv.push_back(L"GetTaxaGroupTypes");
   serv.push_back(L"GetTaxaLookupSynonymyByTaxaGroupIDList");
   serv.push_back(L"GetTaxonByID");
   serv.push_back(L"GetTaxonByName");
   serv.push_back(L"GetTaxonDataRecordsCount");
   serv.push_back(L"GetTaxonHierarchy");
   serv.push_back(L"GetTaxonSpecimenDatesCount");
   serv.push_back(L"GetTaxonSynonymsCount");
   serv.push_back(L"GetTaxonSynonymyCount");
   serv.push_back(L"GetTaxonVarElements");
   serv.push_back(L"GetTaxonVarUnits");
   serv.push_back(L"GetUnitsDatasetTypeCount");
   serv.push_back(L"GetUnitsDatasetTypesTable");
   serv.push_back(L"GetValidSynonymByInvalidTaxonID");
   serv.push_back(L"GetValidTaxaByTaxaGroupID");
   serv.push_back(L"GetValidTaxaByTaxaGroupIDList");
   serv.push_back(L"GetValidTaxonByName");
   serv.push_back(L"GetVarElemsByDatasetTypeAndTaxaIDList");
   serv.push_back(L"GetVariableByComponentNames");
   serv.push_back(L"GetVariableByComponents");
   serv.push_back(L"GetVariableByID");
   serv.push_back(L"GetVariableContextID");
   serv.push_back(L"GetVariableContextsTable");
   serv.push_back(L"GetVariableContextsTableByDatasetTypeID");
   serv.push_back(L"GetVariableDataRecordsCount");
   serv.push_back(L"GetVariableElementByName");
   serv.push_back(L"GetVariableElementByPartIDs");
   serv.push_back(L"GetVariableElementsTable");
   serv.push_back(L"GetVariablesByTaxaGroupIDList");
   serv.push_back(L"GetVariablesByTaxonID");
   serv.push_back(L"GetVariableTaxonID");
   serv.push_back(L"GetVariableTextByID");
   serv.push_back(L"GetVariableUnitsID");
   serv.push_back(L"GetVariableUnitsTable");
   serv.push_back(L"GetVariableUnitsTableByDatasetTypeID");
   // serv.push_back(L"ValidateUserName");

   // serv.push_back(L"");

   sort(serv.begin(), serv.end(), compstric);

   for (unsigned int i=0; i<serv.size(); i++)
	 ListBox1->Items->Add(serv[i]);

   AdvColumnGrid1->AddCheckBoxColumn(2, false, false);

   DefineTypes();
}
//---------------------------------------------------------------------------

void TWebServicesForm::DefineTypes(void)
{
   typemap[L"int"] = varInteger;
   typemap[L"integer"] = varInteger;           // postgres
   typemap[L"float"] = varDouble;
   typemap[L"double precision"] = varDouble;   // postgres
   typemap[L"numeric"] = varDouble;            // postgres
   typemap[L"nvarchar"] = varOleStr;
   typemap[L"varchar"] = varOleStr;
   typemap[L"character"] = varOleStr;          // postgres
   typemap[L"character varying"] = varOleStr;  // postgres
   typemap[L"text"] = varOleStr;               // postgres
   typemap[L"bit"] = varBoolean;
   typemap[L"boolean"] = varBoolean;           // postgres
   typemap[L"date"] = varDate;                 // postgres
}
//---------------------------------------------------------------------------

void __fastcall TWebServicesForm::ListBox1Click(TObject *Sender)
{
   SetupRequest();
}
//---------------------------------------------------------------------------

void TWebServicesForm::SetupRequest(void)
{
   vector<pair<UnicodeString,UnicodeString> > params;  // service, value

   if (ListBox1->ItemIndex == -1)
	 return;

   Screen->Cursor = crHourGlass;
   WebService = ListBox1->Items->Strings[ListBox1->ItemIndex];
   if (WebService != CurrentService) {
	 CurrentService = WebService;
	 }
   else {
	 if (AdvColumnGrid1->Cells[0][1] != L"no input parameters") {
	   for (int row = 1; row < AdvColumnGrid1->RowCount; row++)
		 params.push_back(pair<UnicodeString,UnicodeString>(AdvColumnGrid1->Cells[0][row],AdvColumnGrid1->Cells[3][row]));
	   }
	 }

   if (AdvColumnGrid1->Cells[0][1] != L"no input parameters")
	 AdvColumnGrid1->ClearNormalCells();

   if (AdvTabSheet1->Visible) {
	 AdvColumnGrid2->Clear();
	 cxLabel1->Clear();
	 }
   AdvEdit1->Clear();
   AdvMemo1->Clear();
   cxButton1->Enabled = true;

   NeotomaFuncInputParams InputParams(ipsJSONS1, TcpClient1);
   InputParams.AddParam(L"procedurename", LowerCase(Schema+WebService));

   if (InputParams.Execute()) {
	 AdvColumnGrid1->RowCount = Max(2,InputParams.Size() + 1);
	 AdvColumnGrid1->Height = Min(AdvColumnGrid1->RowCount,8) * AdvColumnGrid1->DefaultRowHeight + 4;
	 AdvColumnGrid1->AddCheckBoxColumn(2, false, false);
	 int row = 1;
	 if (InputParams.Items.size() == 0) {
	   AdvColumnGrid1->Cells[0][row] = L"no input parameters";
	   AdvColumnGrid1->FontColors[0][row] = clDkGray;
	   }
	 else {
	   AdvColumnGrid1->FontColors[0][row] = clBlack;
	   map<int,INPUTPARAMS>::iterator itr;
	   for (itr = InputParams.Items.begin(); itr != InputParams.Items.end(); itr++) {
		 UnicodeString param = itr->second.name;
		 if (param[1] != L'_') {
		   UnicodeString msg = L"Parameter «" + param + L"» is missing leading underscore.";
		   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   }
		 param.Delete(1,1);
		 AdvColumnGrid1->Cells[0][row] = param;
		 AdvColumnGrid1->SetCheckBoxState(2,row,!itr->second.has_default_value);
		 AdvColumnGrid1->Cells[1][row++] = itr->second.type.LowerCase();
		 }
	   }

	 if (params.size() > 0) {
	   for (int row = 1; row < AdvColumnGrid1->RowCount; row++) {
		 UnicodeString name = AdvColumnGrid1->Cells[0][row];
		 for (unsigned int i = 0; i < params.size(); i++) {
		   if (SameText(name, params[i].first)) {
			 AdvColumnGrid1->Cells[3][row] = params[i].second;
			 break;
			 }
		   }
	     }
	   }
	 }
   else  {
	 Screen->Cursor = crDefault;
	 return;
	 }
   Screen->Cursor = crDefault;
}
//---------------------------------------------------------------------------

void __fastcall TWebServicesForm::cxButton1Click(TObject *Sender)
{
   UnicodeString msg;
   bool state;
   if (AdvColumnGrid1->Cells[0][1] != L"no input parameters") {  // at least one input param exists
	 for (int row = 1; row < AdvColumnGrid1->RowCount; row++) {
	   AdvColumnGrid1->GetCheckBoxState(2,row,state);
	   if (state) {
		 if (AdvColumnGrid1->Cells[3][row].IsEmpty()) {
		   msg = L"Paramter value required for «" + AdvColumnGrid1->Cells[0][row] + L"».";
		   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   return;
		   }
		 }
	   }
	 }

   GetData();
}
//---------------------------------------------------------------------------

void TWebServicesForm::GetData(void)
{
   UnicodeString Text;

   Screen->Cursor = crHourGlass;
   if (SameText(WebService, L"GetAnalysisUnit")) {
	 service<NeotomaGetAnalysisUnit> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetSites")) {
	 service<NeotomaSites> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetTaxaByNameList")) {
	 service<NeotomaTaxaByNameList> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetContactByFamilyName")) {
	 service<NeotomaContactByFamilyName> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetAgeTypesTable")) {
	 service<NeotomaAgeTypesTable> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetAgeTypeID")) {
	 service<NeotomaGetAgeTypeID> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetAliasContactNames")) {
	 service<NeotomaAliasContactNames> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetAllDatasetAuthors")) {
	 service<NeotomaAllDatasetAuthors> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetAllDatasetPIs")) {
	 service<NeotomaAllDatasetPIs> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetAnalysisUnitByID")) {
	 service<NeotomaGetAnalUnitByID> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetAnalysisUnitSampleCount")) {
	 service<NeotomaGetAnalysisUnitSampleCount> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetAnalysisUnitsByCollUnitID")) {
	 service<NeotomaGetAnalUnitsByCollUnitID> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetCalibrationCurvesTable")) {
	 service<NeotomaCalibrationCurvesTable> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetCalibrationProgramsTable")) {
	 service<NeotomaCalibrationProgramsTable> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetChildTaxa")) {
	 service<NeotomaChildTaxa> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetChildTaxaCount")) {
	 service<NeotomaChildTaxaCount> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetChildTaxaForAllSites")) {
	 service<NeotomaChildTaxaSites> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetChronConrolTypeByName")) {
	 service<NeotomaChronControlTypeByName> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetChronControlsByChronControlID")) {
	 service<NeotomaChronoControlsByChronControlID> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetChronControlTypeHighestID")) {
	 service<NeotomaChronControlTypeHighestID> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetChronControlTypesTable")) {
	 service<NeotomaChronControlTypesTable> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetChronoControlsByAnalysisUnitID")) {
	 service<NeotomaGetChronoControlsByAnalUnitID> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetChronoControlsByChronologyID")) {
	 service<NeotomaChronoControlsByChronologyID> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetChronologiesByCollUnitID")) {
	 service<NeotomaChronologiesByCollUnitID> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetCollectionTypeByID")) {
	 service<NeotomaCollectionTypeByID> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetCollectionTypesTable")) {
	 service<NeotomaCollectionTypesTable> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetCollector")) {
	 service<NeotomaCollector> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetCollUnitByID")) {
	 service<NeotomaCollUnitByID> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetCollUnitHandleCount")) {
	 service<NeotomaCollUnitHandleCount> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetCollUnitsBySiteID")) {
	 service<NeotomaCollUnitsBySiteID> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetCollUnitSummaryBySiteID")) {
	 service<NeotomaCollUnitSummaryBySiteID> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetConstituentDatabaseNameByID")) {
	 service<ConstituentDatabaseNameByID> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetConstituentDatabases")) {
	 service<ConstituentDatabases> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetContactByContactName")) {
	 service<NeotomaContactByContactName> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetContactByFamilyNameAndInitials")) {
	 service<NeotomaContactByFamilyNameAndInitials> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetContactByID")) {
	 service<NeotomaContactByID> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetContactStatusesTable")) {
	 service<NeotomaContactStatusesTable> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
   	 }
   else if (SameText(WebService, L"GetContextDatasetTypeCount")) {
	 service<NeotomaContextDatasetTypeCount> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetContextsDatasetTypesTable")) {
	 service<NeotomaContextsDatasetTypesTable> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetDataProcessor")) {
	 service<NeotomaDataProcessor> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetDatasetAuthorsDatasetTypes")) {
	 service<NeotomaDatasetAuthorsDatasetTypes> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetDatasetChrons")) {
	 service<NeotomaDatasetChrons> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetDatasetCitations")) {
	 service<NeotomaDatasetPubs> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetDatasetData")) {
	 service<NeotomaDatasetData> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetDatasetDatabase")) {
	 service<NeotomaDatasetDatabase> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetDatasetIDByCollUnitAndType")) {
	 service<NeotomaGetDatasetIDByCollUnitAndType> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetDatasetIDforDatasetTypeIDforGeochronAnalUnit")) {
	 service<NeotomaDatasetIDforDatasetTypeIDforGeochronAnalUnit> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetDatasetIDsByTaxonID")) {
	 service<NeotomaDatasetIDsByTaxonID> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetDatasetPIs")) {
	 service<NeotomaDatasetPIs> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetDatasetPIsDatasetTypes")) {
	 service<NeotomaDatasetPIsDatasetTypes> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetDatasetPublicationIDs")) {
	 service<NeotomaGetDatasetPublicationIDs> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetDatasetPublications")) {
	 service<NeotomaDatasetPublications> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetDatasetPublicationStatus")) {
	 service<NeotomaGetDatasetPublicationStatus> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetDatasetRepository")) {
	 service<NeotomaDatasetRepository> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetDatasetRepositorySpecimenNotes")) {
	 service<NeotomaDatasetRepositorySpecimenNotes> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetDatasetSampleAnalysts")) {
	 service<NeotomaDatasetSampleAnalysts> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetDatasetSampleDepAgents")) {
	 service<NeotomaDatasetSampleDepAgents> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetDatasetSampleIDs")) {
	 service<NeotomaGetDatasetSampleIDs> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetDatasetSampleKeywords")) {
	 service<NeotomaDatasetSampleKeywords> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetDatasetSamples")) {
	 service<NeotomaSampleAnalUnits> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetDatasetsByContactID")) {
	 service<NeotomaContactDatasets> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetDatasetsByID")) {
	 service<NeotomaDatasetsByID> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetDatasetsBySiteID")) {
	 service<NeotomaSiteDatasets> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetDatasetSpecimenGenBankNrs")) {
	 service<NeotomaDatasetSpecimenGenBankNrs> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetDatasetSpecimens")) {
	 service<NeotomaDatasetSpecimens> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetDatasetSpecimenTaphonomy")) {
	 service<NeotomaDatasetSpecimenTaphonomy> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetDatasetSynonyms")) {
	 service<NeotomaDatasetSynonyms> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetDatasetTaxonNotes")) {
	 service<NeotomaDatasetTaxonNotes> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetDatasetTaxonNotesByTaxonID")) {
	 service<NeotomaDatasetTaxonNotesByTaxonID> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetDatasetTypes")) {
	 service<NeotomaDatasetTypesTable> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetDatasetTypesByName")) {
	 service<NeotomaDatasetTypesByName> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetDatasetTypesByTaxaGroupID")) {
	 service<NeotomaDatasetTypesByTaxaGroupID> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetDatasetTypesHavingData")) {
	 service<NeotomaDatasetTypesHavingData> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetDatasetVariables")) {
	 service<NeotomaDatasetVariables> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetDatasetVariableSynonyms")) {
	 service<NeotomaDatasetVariableSynonyms> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetDepAgentByName")) {
	 service<NeotomaDepAgentByName> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetDepAgentsTypesTable")) {
	 service<NeotomaDepAgentsTable> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetDepEnvtByID")) {
	 service<NeotomaDepEnvtTypeByID> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetDepEnvtTypesTable")) {
	 service<NeotomaDepEnvtTypesTable> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetEcolGroupsByEcolSetID")) {
	 service<NeotomaEcolGroupsByEcolSetID> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetEcolGroupsByTaxaGroupIDList")) {
	 service<NeotomaEcolGroupsByTaxaGroupIDList> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetEcolGroupsByVariableIDList")) {
	 service<NeotomaEcolGroupsByVariableIDList> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetEcolGroupsTable")) {
	 service<NeotomaEcolGroupsTable> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetEcolGroupTypesTable")) {
	 service<NeotomaEcolGroupTypesTable> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetEcolSetCountsByTaxaGroupID")) {
	 service<NeotomaEcolSetCounts> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetEcolSetsGroupsByTaxonID")) {
	 service<NeotomaEcolSetsGroups> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetEcolSetTypesTable")) {
	 service<NeotomaEcolSetTypesTable> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetElementDatasetTaxaGroupCount")) {
	 service<NeotomaElementDatasetTaxaGroupCount> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetElementDatasetTaxaGroupsTable")) {
	 service<NeotomaElementDatasetTaxaGroupsTable> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetElementMaturitiesTable")) {
	 service<NeotomaElementMaturitiesTable> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetElementMaturityByName")) {
	 service<NeotomaElementMaturityByName> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetElementPartID")) {
	 service<NeotomaGetElementPartID> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetElementPortionByName")) {
	 service<NeotomaElementPortionByName> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetElementPortionsTable")) {
	 service<NeotomaElementPortionsTable> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetElementsByTaxonID")) {
	 service<NeotomaGetElementByTaxonID> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetElementSymmetriesTable")) {
	 service<NeotomaElementSymmetriesTable> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetElementSymmetryByName")) {
	 service<NeotomaElementSymmetryByName> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetElementTaxaGroupID")) {
	 service<NeotomaElementTaxaGroupID> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetElementTaxaGroupMaturitiesTable")) {
	 service<NeotomaElementTaxaGroupMaturitiesTable> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetElementTaxaGroupPortionsTable")) {
	 service<NeotomaElementTaxaGroupPortionsTable> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetElementTaxaGroupsTable")) {
	 service<NeotomaElementTaxaGroupsTable> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetElementTaxaGroupSymmetriesTable")) {
	 service<NeotomaElementTaxaGroupSymmetriesTable> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetElementTypeByName")) {
	 service<NeotomaElementTypeByName> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetElementTypeFromVariableElement")) {
	 service<NeotomaElementTypeFromVariableElement> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetElementTypesByNameList")) {
	 service<NeotomaElementTypesByNameList> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetElementTypesByTaxaGroupID")) {
	 service<NeotomaElementTypesByTaxaGroupID> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetElementTypesForTaxonTaxaGroup")) {
	 service<NeotomaElementTypesForTaxonTaxaGroup> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetElementTypesTable")) {
	 service<NeotomaElementTypesTable> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetEventByName")) {
	 service<NeotomaEventByName> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetEventChronControlTypeID")) {
	 service<NeotomaEventChronControlTypeID> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetEventPublications")) {
	 service<NeotomaEventPublications> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetEventsByChronologyID")) {
	 service<NeotomaEventsByChronologyID> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetEventsTable")) {
	 service<NeotomaEventsTable> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetEventTypeByName")) {
	 service<NeotomaEventTypeByName> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetEventTypesTable")) {
	 service<NeotomaEventTypesTable> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetFaciesTypeByName")) {
	 service<NeotomaFaciesTypeByName> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetFaciesTypesTable")) {
	 service<NeotomaFaciesTypesTable> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetFractionDatedByName")) {
	 service<NeotomaFractionDatedByName> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetFractionDatedTable")) {
	 service<NeotomaFractionDatedTable> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetFractionsDatedByList")) {
	 service<NeotomaFractionsDatedByList> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetGeochronAnalysisUnit")) {
	 service<NeotomaGetGeochronAnalysisUnit> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetGeochronAnalysisUnitsByDatasetID")) {
	 service<NeotomaGetGeochronAnalysisUnitByDatasetID> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetGeochronByDatasetID")) {
	 service<NeotomaGeochronByDatasetID> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetGeochronByGeochronID")) {
	 service<NeotomaGetGeochronByGeochronID> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetGeochronControlCount")) {
	 service<NeotomaGetGeochronControlCount> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetGeoChronControlsByChronologyID")) {
	 service<NeotomaGeoChronControlsByChronologyID> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetGeochronIDCount")) {
	 service<NeotomaGetGeochronIDCount> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetGeochronTypeID")) {
	 service<NeotomaGetGeochronTypeID> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetGeochronTypesTable")) {
	 service<NeotomaGeochronTypesTable> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetGeoPolBySiteName")) {
	 service<NeotomaGeoPolBySiteName> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetGeoPoliticalUnitsTable")) {
	 service<GeoPoliticalUnits> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetGeoPolNumberOfSubdivs")) {
	 service<NumberOfGeoPolSubdivs> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetGeoPolUnitByHigherID")) {
	 service<GeoPolUnitByHigherID> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetGeoPolUnitByID")) {
	 service<GeoPolUnitByID> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetGeoPolUnitByNameAndHigherID")) {
	 service<GeoPolUnitByNameAndHigherID> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetGeoPolUnitByNameAndRank")) {
	 service<GeoPolUnitsByNameAndRank> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetGeoPolUnitByRank")) {
	 service<GeoPolUnitsByRank> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetGeoPolUnitsBySiteID")) {
	 service<GeoPolUnitsBySiteID> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetInvalidTaxaByTaxaGroupID")) {
	 service<NeotomaInvalidTaxaByTaxaGroupID> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetInvalidTaxaByTaxaGroupIDList")) {
	 service<NeotomaInvalidTaxaByTaxaGroupIDList> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetInvalidTaxonByName")) {
	 service<InvalidTaxonByName> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetInvalidTaxonSynonymyCount")) {
	 service<NeotomaInvalidTaxonSynonymyCount> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetInvestigator")) {
	 service<NeotomaInvestigator> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetIsoBioMarkers")) {
	 service<NeotomaGetIsoBioMarkers> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetIsoInstrumentationTypes")) {
	 service<NeotomaIsoInstrumentationTypes> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetIsoMaterialAnalyzedAndSubstrate")) {
	 service<NeotomaGetIsoMaterialAnalyzedAndSubstrate> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetIsoMaterialAnalyzedTypes")) {
	 service<NeotomaGetIsoMaterialAnalyzedTypes> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetIsoPretreatmentTypes")) {
	 service<NeotomaGetIsoPretreatmentTypes> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetIsoSampleIntroSystemTypes")) {
	 service<NeotomaIsoSampleIntroSystemTypes> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetIsoSampleOriginTypes")) {
	 service<NeotomaSampleOriginTypes> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetIsoStandardTypes")) {
	 service<NeotomaIsoStandardTypes> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetIsoSubstrates")) {
	 service<NeotomaGetIsoSubstrates> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetIsoVariableScaleIDs")) {
	 service<NeotomaGetIsoVariableScaleIDs> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetIsoVariableScaleTypes")) {
	 service<NeotomaGetIsoVariableScaleTypes> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetKeywordsTable")) {
	 service<NeotomaKeywordsTable> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetLakeParameterTypesTable")) {
	 service<NeotomaLakeParameterTypesTable> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetLakeParamsBySiteID")) {
	 service<NeotomaSiteLakeParams> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetLithologyByCollUnitID")) {
	 service<NeotomaLithologyByCollUnitID> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetMaxPubIDByPubIDType")) {
	 service<NeotomaGetMaxPubIDByPubIDType> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetMinPubIDByPubIDType")) {
	 service<NeotomaGetMinPubIDByPubIDType> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetNearestSites")) {
	 service<NeotomaNearestSites> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetNextLowerGeoPolCountByNames")) {
	 service<NeotomaNextLowerGeoPolCountByNames> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetNextPublicationByID")) {
	 service<NeotomaNextPublicationByID> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetNextPublicationByIDAndPubTypeID")) {
	 service<NeotomaNextPublicationByIDAndPubTypeID> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetPollenSporeHigherTaxa")) {
	 service<NeotomaGetPollenSporeHigherTaxa> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetPredefinedTaxaEcolGroupsByDatasetTypeList")) {
	 service<NeotomaPredefinedTaxaGroupCodes> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetPreviousPublicationByID")) {
	 service<NeotomaPreviousPublicationByID> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetPreviousPublicationByIDAndPubTypeID")) {
	 service<NeotomaPreviousPublicationByIDAndPubTypeID> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetProcedureInputParams")) {
	 service<NeotomaFuncInputParams> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetPublicationAuthors")) {
	 service<NeotomaPublicationAuthors> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetPublicationByCitation")) {
	 service<NeotomaPublicationsByCitation> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetPublicationByFamilyName")) {
	 service<NeotomaPublicationsByFamilyName> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetPublicationByID")) {
	 service<NeotomaPublicationsByPubID> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetPublicationByIDList")) {
	 service<NeotomaPublicationsByPubIDList> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetPublicationEditors")) {
	 service<NeotomaPublicationEditors> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetPublicationsByContactID")) {
	 service<NeotomaPublicationsByContactID> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetPublicationsByGeochronID")) {
	 service<NeotomaPublicationsByGeochronID> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetPublicationTranslators")) {
	 service<NeotomaPublicationTranslators> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetPublicationTypesTable")) {
	 service<NeotomaPublicationTypesTable> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetRadiocarbonByGeochronID")) {
	 service<NeotomaRadiocarbonByGeochronID> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetRadiocarbonMethodID")) {
	 service<NeotomaGetRadiocarbonMethodID> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetRadiocarbonMethodsTable")) {
	 service<NeotomaRadiocarbonMethodsTable> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetRecentUploads")) {
	 service<NeotomaGetRecentUploads400> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetRecentUploadsv1")) {
	 service<NeotomaGetRecentUploads> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetRelativeAgeByName")) {
	 service<NeotomaRelativeAgeByName> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetRelativeAgeChronControlType")) {
	 service<NeotomaRelativeAgeChronControlType> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetRelativeAgePublications")) {
	 service<NeotomaRelativeAgePublications> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetRelativeAgesByChronologyID")) {
	 service<NeotomaRelativeAgesByChronologyID> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetRelativeAgeScaleByName")) {
	 service<NeotomaRelativeAgeScaleByName> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetRelativeAgeScalesTable")) {
	 service<NeotomaRelativeAgeScalesTable> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetRelativeAgesTable")) {
	 service<NeotomaRelativeAgesTable> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetRelativeAgeUnitsByAgeScale")) {
	 service<NeotomaRelativeAgeUnitsByAgeScale> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetRepositoryInstitution")) {
	 service<NeotomaRepositoryInstitution> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetRepositoryInstitutionsTable")) {
	 service<NeotomaRepositoryInstitutionsTable> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetRockTypeByID")) {
	 service<NeotomaRockTypeByID> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetRockTypeByName")) {
	 service<NeotomaRockTypeByName> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetRockTypesTable")) {
	 service<NeotomaRockTypesTable> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetSampleAge")) {
	 service<NeotomaSampleAge> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetSampleAgesByChronID")) {
	 service<NeotomaSampleAgesByChronID> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetSampleIDForDatasetIDFromGeochronAnalUnit")) {
	 service<NeotomaSampleIDForDatasetIDFromGeochronAnalUnit> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetSampleIDForDatasetTypeIDFromGeochronAnalUnit")) {
	 service<NeotomaSampleIDForDatasetTypeIDFromGeochronAnalUnit> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetSampleKeywords")) {
	 service<NeotomaSampleKeywords> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetSampleParents")) {
	 service<NeotomaSampleParents> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetSampleTaxonCount")) {
	 service<NeotomaSampleTaxonCount> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetSiteMetaData")) {
	 service<NeotomaSiteMetaDataBySiteID> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetSitesByDatabaseAndDatasetType")) {
	 service<NeotomaSitesByDatabaseAndDatasetType> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetSitesByDatasetType")) {
	 service<NeotomaSitesByDatasetType> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetSpecimenByIDCount")) {
	 service<NeotomaSpecimenByIDCount> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetSpecimenDateBySpecimenDateID")) {
	 service<NeotomaSpecimenDateBySpecimenDateID> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetSpecimenDateCalBySpecimenDateID")) {
	 service<NeotomaSpecimenDateCalBySpecimenDateID> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetSpecimenDatesByGeochronDatasetID")) {
	 service<NeotomaGeochronDatasetSpecimenDates> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetSpecimenDatesByTaxonID")) {
	 service<NeotomaSpecimenDatesByTaxonID> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetSpecimenDomesticStatusByName")) {
	 service<NeotomaSpecimenDomStatByName> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetSpecimenDomesticStatusTypes")) {
	 service<NeotomaSpecimenDomStatTypes> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetSpecimenIsotopeDataset")) {
	 service<NeotomaSpecimenIsotopeDataset> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetSpecimenSampleID")) {
	 service<NeotomaSpecimenSampleID> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetSpecimenSexByName")) {
	 service<NeotomaSpecimenSexByName> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetSpecimenSexTypes")) {
	 service<NeotomaSpecimenSexTypes> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetSpecimenTaxonID")) {
	 service<NeotomaSpecimenTaxonID> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetSynonymsForInvalidTaxonID")) {
	 service<NeotomaSynonymsForInvalidTaxonID> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetSynonymsForValidTaxonID")) {
	 service<NeotomaSynonymsForValidTaxonID> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetSynonymType")) {
	 service<NeotomaSynonymType> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetSynonymTypesTable")) {
	 service<NeotomaSynonymTypesTable> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetTableMaxID")) {
	 service<NeotomaTableMaxID> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetTableMinID")) {
	 service<NeotomaTableMinID> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetTableRecordCount")) {
	 service<NeotomaTableRecordCount> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetTaphonomicSystemByName")) {
	 service<NeotomaTaphonomicSystemByName> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetTaphonomicSystemsByDatasetType")) {
	 service<NeotomaTaphonomicSystemsByDatasetType> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetTaphonomicSystemsDatasetTypesTable")) {
	 service<NeotomaTaphonomicSystemsDatasetTypesTable> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetTaphonomicSystemsTable")) {
	 service<NeotomaTaphonomicSystemsTable> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetTaphonomicTypeID")) {
	 service<NeotomaTaphonomicTypeID> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetTaphonomicTypesByIDList")) {
	 service<NeotomaTaphonomicTypesByIDList> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetTaphonomicTypesBySystem")) {
	 service<NeotomaTaphonomicTypesBySystem> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetTaphonomicTypesTable")) {
	 service<NeotomaTaphonomicTypesTable> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetTaxaByCodeAndTaxaGroupID")) {
	 service<NeotomaTaxaByCodeAndTaxaGroupID> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetTaxaByNamesCount")) {
	 service<NeotomaTaxaByNamesCount> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetTaxaByTaxaGroupID")) {
	 service<NeotomaTaxaByTaxaGroupID> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetTaxaEcolGroupsByDatasetTypeList")) {
	 service<NeotomaDynamicTaxaGroupCodes> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetTaxaGroupByID")) {
	 service<NeotomaGetTaxaGroupByID> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetTaxaGroupElementTypes")) {
	 service<NeotomaTaxaGroupElementTypes> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetTaxaGroupID")) {
	 service<NeotomaGetTaxaGroupID> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetTaxaGroupsForDatasetType")) {
	 service<TaxaGroupsForDatasetType> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetTaxaGroupTypes")) {
	 service<NeotomaTaxaGroupTypesTable> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetTaxaLookupSynonymyByTaxaGroupIDList")) {
	 service<NeotomaLookupSynonym> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetTaxonByID")) {
	 service<NeotomaTaxonByID> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetTaxonByName")) {
	 service<TaxonByName> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetTaxonDataRecordsCount")) {
	 service<NeotomaTaxonDataRecordsCount> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetTaxonHierarchy")) {
	 service<NeotomaTaxonHierarchy> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetTaxonSpecimenDatesCount")) {
	 service<NeotomaTaxonSpecimenDatesCount> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetTaxonSynonymsCount")) {
	 service<NeotomaTaxonSynonymsCount> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetTaxonSynonymyCount")) {
	 service<NeotomaTaxonSynonymyCount> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetTaxonVarElements")) {
	 service<NeotomaTaxonElements> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetTaxonVarUnits")) {
	 service<NeotomaTaxonUnits> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetUnitsDatasetTypeCount")) {
	 service<NeotomaUnitsDatasetTypeCount> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetUnitsDatasetTypesTable")) {
	 service<NeotomaUnitsDatasetTypesTable> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetValidSynonymByInvalidTaxonID")) {
	 service<NeotomaSynonym> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetValidTaxaByTaxaGroupID")) {
	 service<NeotomaValidTaxaByTaxaGroupID> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetValidTaxaByTaxaGroupIDList")) {
	 service<NeotomaValidTaxaByTaxaGroupIDList> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetValidTaxonByName")) {
	 service<ValidTaxonByName> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetVarElemsByDatasetTypeAndTaxaIDList")) {
	 service<NeotomaTaxaElements> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetVariableByComponentNames")) {
	 service<NeotomaVariableByComponentNames> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetVariableByComponents")) {
	 service<NeotomaVariableByComponents> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetVariableByID")) {
	 service<NeotomaVariableByID> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetVariableContextID")) {
	 service<NeotomaVariableContextID> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetVariableContextsTable")) {
	 service<NeotomaVariableContextsTable> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetVariableContextsTableByDatasetTypeID")) {
	 service<NeotomaVariableContextsTableByDatasetTypeID> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetVariableDataRecordsCount")) {
	 service<NeotomaVariableDataRecordsCount> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetVariableElementByName")) {
	 service<NeotomaGetVariableElementByName> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetVariableElementByPartIDs")) {
	 service<NeotomaVariableElementByPartIDs> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetVariableElementsTable")) {
	 service<NeotomaVariableElementsTable> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetVariablesByTaxaGroupIDList")) {
	 service<NeotomaVariablesByTaxaGroupIDList> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetVariablesByTaxonID")) {
	 service<NeotomaVariablesByTaxonID> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetVariableTaxonID")) {
	 service<NeotomaVariableTaxonID> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetVariableTextByID")) {
	 service<NeotomaVariableTextByID> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetVariableUnitsID")) {
	 service<NeotomaVariableUnitsID> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetVariableUnitsTable")) {
	 service<NeotomaVariableUnitsTable> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetVariableUnitsTableByDatasetTypeID")) {
	 service<NeotomaVariableUnitsTableByDatasetTypeID> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   //else if (SameText(WebService, L"ValidateUserName")) {
   //	 service<ValidateUserName> webserv(ipsJSONS1, TcpClient1);
   //	 MakeRequest((SJSONTABLE*)&(*webserv.name));
   //	 }
   else if (SameText(WebService, L"GetAggregateChronByDatasetID")) {
	 service<NeotomaAggregateChronByDatasetID> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetAggregateDatasetByName")) {
	 service<NeotomaAggregateDatasetByName> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   else if (SameText(WebService, L"GetAggregateOrderTypes")) {
	 service<NeotomaAggregateOrderTypes> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }

   /*
   else if (SameText(WebService, L"")) {
	 service<> webserv(ipsJSONS1, TcpClient1);
	 MakeRequest((SJSONTABLE*)&(*webserv.name));
	 }
   */

   AdvColumnGrid2->Clear();
   cxLabel1->Clear();
   // AdvEdit1->Clear();

   unsigned int nfields = Fields.size();
   AdvColumnGrid2->ColCount = nfields;
   AdvColumnGrid2->RowCount = Max(2,Table.size() + 1);
   for (unsigned int i=0; i<nfields; i++) {
	 TGridColumnItem* Col = AdvColumnGrid2->Columns->Items[i];
	 Col->Header = Fields[i].Name;
	 Col->HeaderAlignment = taCenter;
	 Col->ReadOnly = true;
	 }

   for (unsigned int r=0,row=1; r<Table.size(); r++,row++) {
	 for (unsigned int c=0; c<nfields; c++) {
	   VariantToUnicodeString(Table[r][c], Text);
	   AdvColumnGrid2->Cells[c][row] = Text;
	   }
	 }

   AdvColumnGrid2->AutoSize = true;
   for (int i = 0; i < AdvColumnGrid2->ColCount; i++) {
	 TGridColumnItem* Col = AdvColumnGrid2->Columns->Items[i];
	 if (Col->Width > 200)
	   Col->Width = 200;
	 }

   cxLabel1->Caption = L" " + IntToStr((int)Table.size()) + L" rows";
   Screen->Cursor = crDefault;
}
//---------------------------------------------------------------------------

void TWebServicesForm::MakeRequest(SJSONTABLE* func)
{
   double dval;
   int ival;
   boolean bval;
   UnicodeString msg;
   bool error = false;

   Parameters = (*func).Parameters;

   if (AdvColumnGrid1->Cells[0][1] != L"no input parameters") {
	 for (int i = 1; i < AdvColumnGrid1->RowCount; i++) {
	   UnicodeString param = AdvColumnGrid1->Cells[0][i];
	   UnicodeString type = AdvColumnGrid1->Cells[1][i];
	   UnicodeString value = AdvColumnGrid1->Cells[3][i];

	   if (!value.IsEmpty()) {
		 // ShowMessage(L"type = " + type + L", typemap[type] = " + IntToStr(typemap[type]));
		 switch (typemap[type]) {
		   case varOleStr:
		   case varDate:
			 (*func).AddParam(param,value);
			 break;
		   case varDouble:
			 if (TryStrToFloat(value,dval))
			   (*func).AddParam(param,dval);
			 else {
			   msg = L"Expected " + type + L" value for param «" + param + L"». Got «" + value + L"».";
			   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			   error = true;
			   }
			 break;
		   case varInteger:
			 if (TryStrToInt(value,ival))
			   (*func).AddParam(param,ival);
			 else {
			   msg = L"Expected " + type + L" value for param «" + param + L"». Got «" + value + L"».";
			   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			   error = true;
			   }
			 break;
		   case varBoolean:
		      msg = L"Boolean input paramaeter not programmed.";
			  MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			  error = true;
			 if (TryStrToInt(value,ival)) {

			   }
			 break;
		   default:
			 msg = L"Data type «" + type + L"» not recognized.";
			 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			 error = true;
			 break;
		   }
		 }
	   }
	 }

   if (!error) {
	 (*func).Execute();
	 Fields = (*func).Fields;
	 Table = (*func).Table;
	 AdvEdit1->Text = (*func).url;
	 AdvMemo1->Lines->Text = (*func).TransferredData();
	 PrettyJSON();
	 }
}
//---------------------------------------------------------------------------

void TWebServicesForm::PrettyJSON(void)
{
   UnicodeString text, line;
   int pos, leftbracepos, rightbracepos, commapos, quotepos, rightbracketpos;

   int count = AdvMemo1->Lines->Count;
   for (int i=0; i<count; i++)
	 text += AdvMemo1->Lines->Strings[i];

   TStringList *lines = new TStringList;

   // ShowMessage(text);

   // {"success":1,"data":[{"Address"
   // {"status":"success","data":[{"contactid"

   lines->Add(text.SubString(1,1));          // left brace
   text.Delete(1,1);
   pos = text.Pos(L",");
   if (pos > 0) {
	 line = L"\t" + text.SubString(1,pos);
	 lines->Add(line);                       // "success":1,
	 text.Delete(1,pos);
	 }
   pos = text.Pos(L"[");
   if (pos > 0) {
	 line = L"\t" + text.SubString(1,pos);   // "data":[
	 lines->Add(line);
	 text.Delete(1,pos);
	 }
   leftbracepos = text.Pos(L"{");
   int rec = 1;

   while (leftbracepos == 1) {
	 line = L"\t\t" + text.SubString(1,1);
	 lines->Add(line);

	 text.Delete(1,1);
	 while (text[1] != L'}') {
	   pos = QuotePos(text);
	   if (pos == 1) {
		 line = L"\t\t\t" + text.SubString(1,1);
		 text.Delete(1,1);
		 pos = text.Pos(L":");
		 if (pos > 0) {
		   line += text.SubString(1,pos);
		   text.Delete(1,pos);
		   if (text[1] == L'\"') {   // string var
			 line += text.SubString(1,1);
			 text.Delete(1,1);
			 pos = QuotePos(text);
			 if (pos > 0) {
			   line += text.SubString(1,pos);
			   text.Delete(1,pos);
			   }
			 if (text[1] == L',') {
			   line += text.SubString(1,1);
			   text.Delete(1,1);
			   }
			 lines->Add(line);
			 }
		   else {
			 commapos = text.Pos(L",");  // {
			 quotepos = QuotePos(text);
			 rightbracketpos = text.Pos(L"]");
			 if (commapos < rightbracketpos && quotepos == commapos+1) {   // ,"
			   line += text.SubString(1,commapos);
			   text.Delete(1,commapos);
			   lines->Add(line);
			   }
			 else {
			   rightbracepos = text.Pos(L"}");
			   if (commapos != 0 && commapos < rightbracepos) {
				 line += text.SubString(1,commapos);
				 lines->Add(line);
				 text.Delete(1,commapos);
				 }
			   else {
				 line += text.SubString(1,rightbracepos-1);
				 lines->Add(line);
				 text.Delete(1,rightbracepos-1);
				 }
			   }
			 }
		   }
		 }
	   }

	 if (text[1] == L'}') {
	   line = L"\t\t" + text.SubString(1,1);
	   text.Delete(1,1);
	   if (text[1] == L',') {
		 line += text.SubString(1,1);
		 text.Delete(1,1);
		 }
	   lines->Add(line);
	   }
	 leftbracepos = text.Pos(L"{");
	 }

   line = L"\t" + text.SubString(1,2);    // ]
   lines->Add(line);
   text.Delete(1,2);
   int len = text.Length();
   line = L"\t" + text.SubString(1,len-1);
   lines->Add(line);
   text.Delete(1,len-1);
   lines->Add(text);

   AdvMemo1->Lines->Clear();
   AdvMemo1->WordWrap = wwNone;
   AdvMemo1->Lines->Assign(lines);
   delete lines;
}
//---------------------------------------------------------------------------

int TWebServicesForm::QuotePos(UnicodeString& Text)
{
   // pos = text.Pos(L"\"");
   WideChar ch1 = L' ';
   WideChar ch2;
   int pos = 0;
   int len = Text.Length();
   int idx = 0;
   while (pos == 0 && idx < len) {
	 idx++;
	 ch2 = Text[idx];
	 if (ch2 == L'\"' && ch1 != L'\\')
	   pos = idx;
	 else
	   ch1 = ch2;
	 }
   return pos;
}
//---------------------------------------------------------------------------

void __fastcall TWebServicesForm::Panel2Resize(TObject *Sender)
{
   cxButton1->Left = (Panel2->Width - cxButton1->Width)/2;
}
//---------------------------------------------------------------------------

void __fastcall TWebServicesForm::cxButton2Click(TObject *Sender)
{
   AdvColumnGrid2->CopyToClipBoard();
}
//---------------------------------------------------------------------------

void __fastcall TWebServicesForm::cxButton3Click(TObject *Sender)
{
   AdvColumnGrid2->CopySelectionToClipboard();
}
//---------------------------------------------------------------------------

void __fastcall TWebServicesForm::Copy1Click(TObject *Sender)
{
   Clipboard()->Open();
   Clipboard()->SetTextBuf(ListBox1->Items->Strings[ListBox1->ItemIndex].c_str());
   Clipboard()->Close();
}
//---------------------------------------------------------------------------

void __fastcall TWebServicesForm::CopyLowercase1Click(TObject *Sender)
{
   Clipboard()->Open();
   WideString Text = ListBox1->Items->Strings[ListBox1->ItemIndex].c_str();
   Clipboard()->SetTextBuf(Text.LowerCase().c_bstr());
   Clipboard()->Close();
}
//---------------------------------------------------------------------------

void __fastcall TWebServicesForm::PopupMenu1Popup(TObject *Sender)
{
   Copy1->Enabled = (ListBox1->ItemIndex > -1);
}
//---------------------------------------------------------------------------

void __fastcall TWebServicesForm::Copy2Click(TObject *Sender)
{
   Clipboard()->Open();
   WideString Text = AdvColumnGrid1->Cells[AdvColumnGrid1->Col][AdvColumnGrid1->Row];
   Clipboard()->SetTextBuf(Text.c_bstr());
   Clipboard()->Close();
}
//---------------------------------------------------------------------------

void __fastcall TWebServicesForm::CopyLowercase2Click(TObject *Sender)
{
   Clipboard()->Open();
   WideString Text = AdvColumnGrid1->Cells[AdvColumnGrid1->Col][AdvColumnGrid1->Row];
   Clipboard()->SetTextBuf(Text.LowerCase().c_bstr());
   Clipboard()->Close();
}
//---------------------------------------------------------------------------

void __fastcall TWebServicesForm::AdvColumnGrid1CheckBoxCanToggle(TObject *Sender,
		  int ACol, int ARow, bool State, bool &Allow)
{
   Allow = false;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

__fastcall TTSServicesForm::TTSServicesForm(TComponent* Owner)
		: TWebServicesForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TTSServicesForm::FormCreate(TObject *Sender)
{
   Schema = L"ts.";

   // func[L"CheckSteward"] = false;
   func[L"CombineContacts"] = false;
   func[L"DeleteAnalysisUnit"] = false;
   func[L"DeleteChronology"] = false;
   func[L"DeleteCollectionUnit"] = false;
   func[L"DeleteCollectors"] = false;
   func[L"DeleteData"] = false;
   func[L"DeleteDataProcessor"] = false;
   func[L"DeleteDataset"] = false;
   func[L"DeleteDatasetPI"] = false;
   func[L"DeleteDatasetPublication"] = false;
   func[L"DeleteDatasetTaxonNotes"] = false;
   func[L"DeleteDatasetVariable"] = false;
   func[L"DeleteDepEnvtType"] = false;
   func[L"DeleteEcolGroup"] = false;
   func[L"DeleteEventPublication"] = false;
   func[L"DeleteGeochron"] = false;
   func[L"DeleteGeochronControl"] = false;
   func[L"DeleteGeochronPublication"] = false;
   func[L"DeletePublicationAuthor"] = false;
   func[L"DeletePublicationEditor"] = false;
   func[L"DeletePublicationTranslator"] = false;
   func[L"DeleteRelativeAgePublication"] = false;
   func[L"DeleteRepositorySpecimen"] = false;
   func[L"DeleteSample"] = false;
   func[L"DeleteSampleAnalysts"] = false;
   func[L"DeleteSite"] = false;
   func[L"DeleteSynonymy"] = false;
   func[L"DeleteTaxon"] = false;
   func[L"DeleteVariableByVariableID"] = false;
   func[L"DeleteVariableContext"] = false;
   func[L"DeleteVariablesByTaxonID"] = false;
   // func[L""] = false;

   func[L"InsertAggregateChronology"] = true;
   func[L"InsertAggregateDataset"] = true;
   func[L"InsertAggregateSample"] = false;
   func[L"InsertAggregateSampleAges"] = false;
   func[L"InsertAnalysisUnit"] = true;
   func[L"InsertAnalysisUnitAltDepth"] = false;
   func[L"InsertAnalysisUnitAltDepthScale"] = true;
   func[L"InsertCalibrationProgram"] = true;
   func[L"InsertChronControl"] = true;
   func[L"InsertChronControlCal14C"] = false;
   func[L"InsertChronControlType"] = true;
   func[L"InsertChronology"] = true;
   func[L"InsertCollectionUnit"] = true;
   func[L"InsertCollector"] = true;
   func[L"InsertContact"] = true;
   func[L"InsertContextDatasetTypes"] = false;
   func[L"InsertData"] = true;
   func[L"InsertDataProcessor"] = false;
   func[L"InsertDataset"] = true;
   func[L"InsertDatasetDatabase"] = false;
   func[L"InsertDatasetPI"] = false;
   func[L"InsertDatasetPublication"] = false;
   func[L"InsertDatasetRepository"] = false;
   func[L"InsertDatasetSubmission"] = true;
   func[L"InsertDatasetTaxonNotes"] = false;
   func[L"InsertDepAgent"] = false;
   func[L"InsertDepEnvtType"] = true;
   func[L"InsertDepAgentTypes"] = true;
   func[L"InsertEcolGroup"] = false;
   func[L"InsertEcolGroupType"] = false;
   func[L"InsertElementDatasetTaxaGroups"] = false;
   func[L"InsertElementMaturity"] = true;
   func[L"InsertElementPortion"] = true;
   func[L"InsertElementSymmetry"] = true;
   func[L"InsertElementTaxaGroupMaturity"] = false;
   func[L"InsertElementTaxaGroupPortion"] = false;
   func[L"InsertElementTaxaGroups"] = true;
   func[L"InsertElementTaxaGroupSymmetry"] = false;
   func[L"InsertElementType"] = true;
   func[L"InsertEvent"] = true;
   func[L"InsertEventChronology"] = true;
   func[L"InsertEventPublication"] = false;
   func[L"InsertFaciesTypes"] = true;
   func[L"InsertFormTaxon"] = true;
   func[L"InsertFractionDated"] = true;
   func[L"InsertGeochron"] = true;
   func[L"InsertGeoChronControl"] = false;
   func[L"InsertLakeParameter"] = false;
   func[L"InsertPublication"] = true;
   func[L"InsertPublicationAuthors"] = true;
   func[L"InsertRepositoryInstitution"] = true;
   func[L"InsertSample"] = true;
   func[L"InsertSampleAge"] = true;       // chron needs to be uploaded first
   func[L"InsertSampleAnalyst"] = true;
   func[L"InsertSampleKeyword"] = false;
   func[L"InsertSite"] = true;
   func[L"InsertSiteGeoPol"] = true;
   func[L"InsertTaxaGroup"] = false;
   func[L"InsertTaxon"] = true;
   func[L"InsertUnitsDatasetTypes"] = false;
   func[L"InsertVariable"] = true;
   func[L"InsertVariableContext"] = true;
   func[L"InsertVariableElement"] = true;
   func[L"InsertVariableUnits"] = true;
   func[L"InsertGeochronPublication"] = false;
   func[L"InsertGeoPoliticalUnit"] = true;
   func[L"InsertSpecimen"] = true;
   func[L"InsertSpecimenDate"] = true;
   func[L"InsertSpecimenDateCal"] = true;
   func[L"InsertSpecimenGenBankNr"] = false;
   func[L"InsertSpecimenTaphonomy"] = false;
   func[L"InsertSampleAge"] = true;
   func[L"InsertSteward"] = true;
   func[L"InsertSummaryDataTaphonomy"] = false;
   func[L"InsertSynonym"] = true;
   func[L"InsertSynonymType"] = true;
   func[L"InsertSynonymy"] = true;
   func[L"InsertTaphonomicSystem"] = true;
   func[L"InsertTaphonomicSystemDatasetType"] = false;
   func[L"InsertTaphonomicType"] = false;
   func[L"InsertTephra"] = true;
   func[L"InsertLithology"] = true;
   func[L"InsertNewDatasetPI"] = false;
   func[L"InsertPublicationEditors"] = true;
   func[L"InsertPublicationTranslators"] = true;
   func[L"InsertRadiocarbon"] = false;
   func[L"InsertRelativeAge"] = true;
   func[L"InsertRelativeAgePublication"] = false;
   func[L"InsertRelativeChronology"] = true;
   func[L"InsertIsoInstrumention"] = false;
   func[L"InsertIsoMetadata"] = false;
   func[L"InsertIsoSamplePretreatments"] = false;
   func[L"InsertIsoSpecimenData"] = false;
   func[L"InsertIsoSrMetadata"] = false;
   func[L"InsertIsoStandards"] = false;
   func[L"InsertIsoStratData"] = false;

   // func[L"linkhigher"] = false;

   func[L"UpdateAnalysisUnitDepth"] = false;
   func[L"UpdateAnalysisUnitName"] = false;
   func[L"UpdateAnalysisUnitThickness"] = false;
   func[L"UpdateChronControlAge"] = false;
   func[L"UpdateChronControlAgeBasis"] = false;
   func[L"UpdateChronControlAgeOlder"] = false;
   func[L"UpdateChronControlAgeType"] = false;
   func[L"UpdateChronControlAgeYounger"] = false;
   func[L"UpdateChronControlAnalysisUnit"] = false;
   func[L"UpdateChronControlDepthThickness"] = false;
   func[L"UpdateChronControlEvent"] = false;
   func[L"UpdateChronControlNotes"] = false;
   func[L"UpdateChronControlType"] = false;
   func[L"UpdateChronology"] = false;
   func[L"UpdateCollectionUnit"] = false;
   func[L"UpdateContact"] = false;
   func[L"UpdateContactAliasID"] = false;
   func[L"UpdateData"] = false;
   func[L"UpdateDatasetName"] = false;
   func[L"UpdateDatasetNotes"] = false;
   func[L"UpdateDatasetPubPrimary"] = false;
   func[L"UpdateDatasetRepositoryNotes"] = false;
   func[L"UpdateDatasetTaxonNotes"] = false;
   func[L"UpdateDatasetVariable"] = false;
   func[L"UpdateDataVariable"] = false;
   func[L"UpdateDataVariableID"] = false;
   func[L"UpdateDataVariableID_DeleteVariable"] = false;
   func[L"UpdateDepEnvtHigherID"] = false;
   func[L"UpdateDepEnvtType"] = false;
   func[L"UpdateElementPollenToSpore"] = false;
   func[L"UpdateElementSporeToPollen"] = false;
   func[L"UpdateEvent"] = false;
   func[L"UpdateGeochron"] = false;
   func[L"UpdateGeochronAnalysisUnit"] = false;
   func[L"UpdateIsSurfaceSample"] = false;
   func[L"UpdateLakeParam"] = false;
   func[L"UpdatePublication"] = false;
   func[L"UpdatePublicationAuthor"] = false;
   func[L"UpdatePublicationEditor"] = false;
   func[L"UpdatePublicationTranslator"] = false;
   func[L"UpdateRadiocarbon"] = false;
   func[L"UpdateRelativeAge"] = false;
   func[L"UpdateReplacePublicationID"] = false;
   func[L"UpdateSampleAge"] = false;
   func[L"UpdateSampleAnalysisUnit"] = false;
   func[L"UpdateSampleLabNumber"] = false;
   func[L"UpdateSite"] = false;
   func[L"UpdateSiteGeoPol"] = false;
   func[L"UpdateSiteGeoPolDelete"] = false;
   func[L"UpdateSiteGeoPolInsert"] = false;
   func[L"UpdateSiteLatLon"] = false;
   func[L"UpdateSpecimenDateTaxonID"] = false;
   func[L"UpdateSpecimenNISP"] = false;
   func[L"UpdateSynonymTypeID"] = false;
   func[L"UpdateSynonymy"] = false;
   func[L"UpdateTaphonomicSystemNotes"] = false;
   func[L"UpdateTaxonAuthor"] = false;
   func[L"UpdateTaxonCode"] = false;
   func[L"UpdateTaxonExtinct"] = false;
   func[L"UpdateTaxonHigherTaxonID"] = false;
   func[L"UpdateTaxonHigherTaxonIDToNull"] = false;
   func[L"UpdateTaxonName"] = false;
   func[L"UpdateTaxonNotes"] = false;
   func[L"UpdateTaxonPublicationID"] = false;
   func[L"UpdateTaxonValidation"] = false;
   func[L"UpdateTaxonValidity"] = false;
   func[L"UpdateVariableTaxonID"] = false;

   map<UnicodeString,bool>::iterator itr;
   for (itr = func.begin(); itr != func.end(); itr++)
	 ListBox1->Items->Add(itr->first);

   AdvColumnGrid1->AddCheckBoxColumn(2, false, false);

   DefineTypes();

   AdvPageControl1->ActivePage = AdvTabSheet2;
   AdvPageControl1->CloseOpenedTab(AdvTabSheet1);
   AdvTabSheet2->Caption = L"Result";
   AdvMemo1->Gutter->Visible = false;
   AdvMemo1->WordWrap = wwRightMargin;
}
//---------------------------------------------------------------------------

void __fastcall TTSServicesForm::cxButton1Click(TObject *Sender)
{
   UnicodeString msg;
   bool state;
   if (AdvColumnGrid1->Cells[0][1] != L"no input parameters") {  // at least one input param exists
	 for (int row = 1; row < AdvColumnGrid1->RowCount; row++) {
	   AdvColumnGrid1->GetCheckBoxState(2,row,state);
	   if (state) {
		 if (AdvColumnGrid1->Cells[3][row].IsEmpty()) {
		   msg = L"Paramter value required for «" + AdvColumnGrid1->Cells[0][row] + L"».";
		   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   return;
		   }
		 }
	   }
	 }

   PutData();
}
//---------------------------------------------------------------------------

void TTSServicesForm::PutData(void)
{
   if (!Login->IsLoggedIn) {
	 NeotomaLoginForm = new TNeotomaLoginForm(this);
	 NeotomaLoginForm->ShowModal();
	 delete NeotomaLoginForm;
	 }
   if (!Login->IsLoggedIn)
	 return;

   Screen->Cursor = crHourGlass;

   RunInsertFunc();
   /*
   if (SameText(WebService.SubString(1,6),L"Insert")) {
	 //WebService = Schema + WebService;
	 RunInsertFunc();
	 }
   if (SameText(WebService.SubString(1,6),L"Update")) {
	 //RunUpdateFunc();
	 RunInsertFunc();
	 }
   */

   Screen->Cursor = crDefault;
}
//---------------------------------------------------------------------------

/*
void TTSServicesForm::RunUpdateFunc(void)
{
   UnicodeString msg, ErrorMsg, line;
   bool error = false;
   Variant Value;
   double dval;
   int ival;

   // ShowMessage(WebService);
   WebService = L"ts." + WebService.LowerCase();
   UpdateData UpdateFunc(WebService, ipsHTTPS1, ipsJSONS1, TcpClient1);

   for (int i = 1; i < AdvColumnGrid1->RowCount; i++) {
	 UnicodeString param = AdvColumnGrid1->Cells[0][i];
	 UnicodeString type = AdvColumnGrid1->Cells[1][i];
	 UnicodeString value = AdvColumnGrid1->Cells[3][i];

	 switch (typemap[type]) {
	   case varOleStr:
	   case varDate:
		 UpdateFunc.Add(param, value);
		 break;
	   case varInteger:
		 if (value.IsEmpty())
			 UpdateFunc.AddInt(param,Unassigned());
		 else if (TryStrToInt(value,ival)) {
		   Value = ival;
		   UpdateFunc.AddInt(param,Value);
		   }
		 else {
		   msg = L"Expected " + type + L" value for param «" + param + L"». Got «" + value + L"».";
		   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   error = true;
		   }
		 break;
	   case varDouble:
		 if (value.IsEmpty())
		   UpdateFunc.AddDouble(param,Unassigned());
		 else if (TryStrToFloat(value,dval)) {
		   Value = dval;
		   UpdateFunc.AddDouble(param,Value);
		   }
		 else {
		   msg = L"Expected " + type + L" value for param «" + param + L"». Got «" + value + L"».";
		   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   error = true;
		   }
		 break;
	   case varBoolean:
		 if (value.IsEmpty()) {
		   msg = L"Boolean param «" + param + L"» cannot be empty. Must be «true» or «false».";
		   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   error = true;
		   }
		 else if (SameText(value,L"true")) {
		   UpdateFunc.Add(param,true);
		   }
		 else if (SameText(value,L"false")) {
		   UpdateFunc.Add(param,false);
		   }
		 else {
		   msg = L"Boolean param «" + param + L"» cannot be empty. Must be «true» or «false».";
		   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   error = true;
		   }
		 break;
	   }
	 }

   if (!error) {
	 AdvEdit1->Text = UpdateFunc.URL;
	 //UpdateFunc.PostData();
	 if (UpdateFunc.Post(ErrorMsg)) {
	   line = L"Update successful!";
	   AdvMemo1->Lines->Add(line);
	   MessageDlg(line, mtInformation, TMsgDlgButtons() << mbOK, 0);
	   }
	 else {
	   line = L"Update failed :-(";
	   line = L"Post error: " + ErrorMsg;
	   AdvMemo1->Lines->Add(line);
	   }
	 }
}
//---------------------------------------------------------------------------
*/

void TTSServicesForm::RunInsertFunc(void)
{
   UnicodeString msg, ErrorMsg, line;
   bool error = false;
   Variant Value;
   double dval;
   int ival;
   vector<int> newids;

   int nparams = AdvColumnGrid1->RowCount - 1;
   InsertData InsertFunc(WebService, nparams, ipsHTTPS1, ipsJSONS1, TcpClient1);

   if (AdvColumnGrid1->Cells[0][1] != L"no input parameters") {
	 for (int i = 1; i < AdvColumnGrid1->RowCount; i++) {
	   UnicodeString param = AdvColumnGrid1->Cells[0][i];
	   UnicodeString type = AdvColumnGrid1->Cells[1][i];
	   UnicodeString value = AdvColumnGrid1->Cells[3][i];

	   switch (typemap[type]) {
		 case varOleStr:
		 case varDate:
		   InsertFunc.Add(param, value);
		   break;
		 case varDouble:
		   if (value.IsEmpty())
			 InsertFunc.AddDouble(param,Unassigned());
		   else if (TryStrToFloat(value,dval)) {
			 Value = dval;
			 InsertFunc.AddDouble(param,Value);
			 }
		   else {
			 msg = L"Expected " + type + L" value for param «" + param + L"». Got «" + value + L"».";
			 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			 error = true;
			 }
		   break;
		 case varInteger:
		   if (value.IsEmpty())
			 InsertFunc.AddInt(param,Unassigned());
		   else if (TryStrToInt(value,ival)) {
			 Value = ival;
			 InsertFunc.AddInt(param,Value);
			 }
		   else {
			 msg = L"Expected " + type + L" value for param «" + param + L"». Got «" + value + L"».";
			 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			 error = true;
			 }
		   break;
		 case varBoolean:
		   if (value.IsEmpty()) {
			 msg = L"Boolean param «" + param + L"» cannot be empty. Must be «true» or «false».";
			 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			 error = true;
			 }
		   else if (SameText(value,L"true")) {
			 InsertFunc.Add(param,true);
			 }
		   else if (SameText(value,L"false")) {
			 InsertFunc.Add(param,false);
			 }
		   else {
             msg = L"Boolean param «" + param + L"» cannot be empty. Must be «true» or «false».";
			 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			 error = true;
			 }
		   break;
		 }
	   }
	 }

   if (!error) {
	 AdvEdit1->Text = InsertFunc.URL;
	 UnicodeString FuncType;
	 if (ContainsText(WebService,L"insert"))
	   FuncType = L"Insert";
	 else if (ContainsText(WebService,L"update"))
	   FuncType = L"Update";
	 else if (ContainsText(WebService,L"delete"))
	   FuncType = L"Delete";
	 else
	   FuncType = L"Function execution";

	 InsertFunc.PostData();
	 if (func[WebService]) {   // returns an ID
	   if (InsertFunc.Post(newids, ErrorMsg)) {
		 if (newids.size() == 1) {
		   line = FuncType + L" successful!";
		   AdvMemo1->Lines->Add(line);
		   line = L"new id = " + IntToStr(newids[0]);
		   AdvMemo1->Lines->Add(line);
		   msg = FuncType + L" successful! New id = " + IntToStr(newids[0]) + L".";
		   MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
		   }
		 else {
		   line = FuncType + L" failed :-(";
		   AdvMemo1->Lines->Add(line);
		   }
		 }
	   else {
		 line = L"Post error: " + ErrorMsg;
		 AdvMemo1->Lines->Add(line);
		 }
	   }
	 else {   // doesn't reuurn an id
	   if (InsertFunc.Post(ErrorMsg)) {
		 line = FuncType + L" successful!";
		 AdvMemo1->Lines->Add(line);
		 MessageDlg(line, mtInformation, TMsgDlgButtons() << mbOK, 0);
		 }
	   else {
		 line = FuncType + L" failed :-(";
		 line = L"Post error: " + ErrorMsg;
		 AdvMemo1->Lines->Add(line);
		 }
	   }
	 }
}
//---------------------------------------------------------------------------

void __fastcall TWebServicesForm::ipsJSONS1SSLServerAuthentication(TObject *Sender,
          TipsJSONSSSLServerAuthenticationEventParams *e)
{
   e->Accept = true;
}
//---------------------------------------------------------------------------

void __fastcall TWebServicesForm::ipsHTTPS1SSLServerAuthentication(TObject *Sender,
          TipsHTTPSSSLServerAuthenticationEventParams *e)
{
   e->Accept = true;
}
//---------------------------------------------------------------------------

void __fastcall TWebServicesForm::ipsHTTPS1Header(TObject *Sender, TipsHTTPSHeaderEventParams *e)
{
   AdvMemo1->Lines->Add(L"Header = " + e->Field + L": " + e->Value);
}
//---------------------------------------------------------------------------

void __fastcall TWebServicesForm::ipsHTTPS1ConnectionStatus(TObject *Sender, TipsHTTPSConnectionStatusEventParams *e)
{
   AdvMemo1->Lines->Add(L"Connection Event: " + e->ConnectionEvent);
   AdvMemo1->Lines->Add(L"Description: " + e->Description);
}
//---------------------------------------------------------------------------

void __fastcall TWebServicesForm::ipsHTTPS1SSLStatus(TObject *Sender, TipsHTTPSSSLStatusEventParams *e)
{
   AdvMemo1->Lines->Add(L"Status: " + e->Message);
}
//---------------------------------------------------------------------------

void __fastcall TWebServicesForm::ipsHTTPS1Status(TObject *Sender, TipsHTTPSStatusEventParams *e)
{
   AdvMemo1->Lines->Add(L"HTTPVersion: " + e->HTTPVersion);
   AdvMemo1->Lines->Add(L"Description: " + e->Description);
}
//---------------------------------------------------------------------------

