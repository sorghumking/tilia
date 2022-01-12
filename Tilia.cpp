//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
#include "TGSplash.h"
#ifndef TIVersionH
#include "TIVersion.h"
#endif
#include "TIGlobals.h"
//---------------------------------------------------------------------------
USEFORM("TISitHir.cpp", SiteHierarchyForm);
USEFORM("TIShoMem.cpp", ShowMemoForm);
USEFORM("TIsoSer.cpp", IsotopeSeriesForm);
USEFORM("TIsoDat.cpp", IsoDatasetMetadataForm);
USEFORM("TIQuery.cpp", QueryForm);
USEFORM("TIPubLnk.cpp", PubLinkForm);
USEFORM("TIPubl.cpp", PubForm);
USEFORM("TISelSpe.cpp", SelectSpecimensForm);
USEFORM("TISeEcGr.cpp", SelectEcolGroupsForm);
USEFORM("TISrtFrm.cpp", SortForm);
USEFORM("TISynonym.cpp", SynonymForm);
USEFORM("TISynFrm.cpp", SynonymsForm);
USEFORM("TISums.cpp", SumsForm);
USEFORM("TISpread.cpp", TilSpreadSheetForm);
USEFORM("TISpec.cpp", SpecimenForm);
USEFORM("TIMemo.cpp", MemoForm);
USEFORM("TIMapSit.cpp", MapSiteForm);
USEFORM("TILOWESS.cpp", LOWESSOptionsForm);
USEFORM("TINewAnl.cpp", NewAnalystForm);
USEFORM("TINewCon.cpp", NewContactForm);
USEFORM("TIOption.cpp", SSOptionsForm);
USEFORM("TIOpnXLS.cpp", ImportExcelForm);
USEFORM("TINwLkUp.cpp", NewLookupItemForm);
USEFORM("TIPoly.cpp", PolynomialOptionsForm);
USEFORM("TIPltMod.cpp", PlotModsForm);
USEFORM("TINtmDat.cpp", NeotomaDataForm);
USEFORM("TINoUnits.cpp", ConfirmNoUnitsForm);
USEFORM("TINewTxn.cpp", NewTaxonForm);
USEFORM("TINtmWeb.cpp", WebServicesForm);
USEFORM("TINtmSitFrm.cpp", NeotomaSiteForm);
USEFORM("TINtmLOI.cpp", DownloadLOIForm);
USEFORM("TNSSAge.cpp", SurfaceSampleAgeForm);
USEFORM("TNSelItm.cpp", SelectItemForm);
USEFORM("TNNewTaxGrp.cpp", NewTaxaGroupForm);
USEFORM("TNTaxa.cpp", NeotomaTaxaLookupForm);
USEFORM("TNSynInfo.cpp", SynonymInfoForm);
USEFORM("TNSubmit.cpp", SubmitForm);
USEFORM("TNLookup.cpp", NeotomaWriteLookupForm);
USEFORM("TNLogin.cpp", NeotomaLoginForm);
USEFORM("TNFindTaxon.cpp", FindTaxonForm);
USEFORM("TNNewSyn.cpp", NewSynTypeForm);
USEFORM("TNNewElm.cpp", NewElementsForm);
USEFORM("TNNewEcGr.cpp", NewEcolGroupForm);
USEFORM("TNtmPubs.cpp", NeotomaContactPubForm);
USEFORM("TNVerAnUn.cpp", VerifyAnalUnitForm);
USEFORM("TNVarMods.cpp", NeotomaVarModsLookupForm);
USEFORM("TNUpdSit.cpp", UpdateNeotomaSiteForm);
USEFORM("TIUpload.cpp", NeotomaUploadForm);
USEFORM("TIUpLatLong.cpp", ValidateLatLongForm);
USEFORM("TIUpDepEnv.cpp", NewDepEnvtForm);
USEFORM("TIUpContact.cpp", NeotomaContactForm);
USEFORM("TITrain.cpp", TrainForm);
USEFORM("TITphChk.cpp", ConvertTaphForm);
USEFORM("TNConDst.cpp", NeotomaContactDatasetsForm);
USEFORM("TNColUnt.cpp", NeotomaCollUnitForm);
USEFORM("TNAnlUnt.cpp", AnalUnitMatchForm);
USEFORM("TNDatTyp.cpp", ReassignDatasetTypeForm);
USEFORM("TNConfTaxNamChng.cpp", ConfirmReplaceTaxonForm);
USEFORM("TNConfElm.cpp", ConfirmElementUploadForm);
USEFORM("TIWhitRem.cpp", WhitmoreRemoveSampleForm);
USEFORM("TIWhitmore.cpp", WhitmoreForm);
USEFORM("TIVrLkUp.cpp", VarLookupForm);
USEFORM("TIWhitSmpID.cpp", WhitmoreSampleIDForm);
USEFORM("TGPrint.cpp", PrintForm);
USEFORM("TGReg.cpp", RegistrationForm);
USEFORM("TGRare.cpp", RareForm);
USEFORM("TGNewTxt.cpp", NewTextForm);
USEFORM("TGLthFrm.cpp", LithForm);
USEFORM("TGPatt.cpp", PatternForm);
USEFORM("TGParent.cpp", ParentForm);
USEFORM("TGOrder.cpp", OrderForm);
USEFORM("TGSelVar.cpp", SelectVariableForm);
USEFORM("TGTxtFrm.cpp", TextForm);
USEFORM("TGYaxFrm.cpp", YaxesForm);
USEFORM("TGXaxFrm.cpp", XaxesForm);
USEFORM("TGStyle.cpp", StyleForm);
USEFORM("TGSplash.cpp", SplashForm);
USEFORM("TGColors.cpp", ColorsForm);
USEFORM("TGAbout.cpp", AboutBox);
USEFORM("TGDgrFrm.cpp", DendrogramForm);
USEFORM("TGDatFrm.cpp", DatesForm);
USEFORM("TGDiagrm.cpp", TGDiagram);
USEFORM("TGGrpOpt.cpp", GroupOptionsForm);
USEFORM("TGGrpFrm.cpp", GroupForm);
USEFORM("TGLinWid.cpp", LineWidthForm);
USEFORM("TGItalic.cpp", ItalicsForm);
USEFORM("TGFntDlg.cpp", FontDialogBox);
USEFORM("TGGreek.cpp", GreekForm);
USEFORM("TGFrame.cpp", FrameForm);
USEFORM("TIEdTree.cpp", EditTreeForm);
USEFORM("TIEdtMod.cpp", EditModifiersForm);
USEFORM("TIEdtElm.cpp", EditElementsForm);
USEFORM("TIExpChr.cpp", ChronControlExportForm);
USEFORM("TIErrFrm.cpp", ErrorListForm);
USEFORM("TIElmFrm.cpp", ElementForm);
USEFORM("TIDelEmp.cpp", DelEmptyRowColForm);
USEFORM("TIDec.cpp", SSFormatForm);
USEFORM("TIEdTaxa.cpp", EditTaxaForm);
USEFORM("TIEdTaph.cpp", EditTaphonomyForm);
USEFORM("TIEdGrps.cpp", EditGroupsForm);
USEFORM("TIFluxFm.cpp", InfluxForm);
USEFORM("TIImpDat.cpp", ImportGeochronForm);
USEFORM("TIImpChr.cpp", ImportChronForm);
USEFORM("TIGooMap.cpp", GoogleMapForm);
USEFORM("TIFuzzy.cpp", FuzzyForm);
USEFORM("TIFndPub.cpp", FindPubForm);
USEFORM("TIGeocod.cpp", GoogleGeocodesForm);
USEFORM("TIAgeRes.cpp", AgeModelResultsForm);
USEFORM("TIAgeBas.cpp", ChronControlForm);
USEFORM("TIChkHir.cpp", CheckHierarchyForm);
USEFORM("TICalib.cpp", CalibForm);
USEFORM("TIAUAges.cpp", ImportChronTabsheetForm);
USEFORM("TGZoneSc.cpp", ZoneScreenForm);
USEFORM("TGZoneOp.cpp", ZoneForm);
USEFORM("TGZoneLi.cpp", ZoneLineForm);
USEFORM("TIAdmUnt.cpp", NewAdminUnit);
USEFORM("TIAddRep.cpp", AddRepositoryForm);
USEFORM("TIAddCal.cpp", AddCalibProgForm);
USEFORM("TIChkVar.cpp", CheckVarForm);
USEFORM("TIConOut.cpp", CONISSOutput);
USEFORM("TIConFrm.cpp", ConissForm);
USEFORM("TIConcFm.cpp", ConcForm);
USEFORM("TICtbFrm.cpp", SubmissionForm);
USEFORM("TICONSht.cpp", NewCONISSSheetForm);
USEFORM("TIChkVarUnitsFrm.cpp", CheckVarUnitsForm);
USEFORM("TIChkVarFrm.cpp", CheckListVarForm);
USEFORM("TIChron.cpp", ChronForm);
USEFORM("TICounter.cpp", CounterForm);
//---------------------------------------------------------------------------
WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;

		tiLicense = new TILIALICENSE();
		tiGlobals = new TIGLOBALS();
		if (!tiLicense->ValidateProductKey()) {
		  delete tiLicense;
		  delete tiGlobals;
		  return 0;
		  }
		SplashForm = new TSplashForm(Application);
		//Application->CreateForm(__classid(TSplashForm), &SplashForm);
		SplashForm->Show();
		SplashForm->Update();

		Application->ShowHint = true;
		Application->Title = "Tilia";
		Application->CreateForm(__classid(TParentForm), &ParentForm);
		Application->HelpFile = ExtractFilePath(Application->ExeName) + "Tilia.chm";
		Sleep(3000);
		delete SplashForm;
		Application->Run();

		delete tiLicense;
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
