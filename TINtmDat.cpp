//---------------------------------------------------------------------------

#include <vcl.h>
//#include "pch.h"
#include "TIJSON.h"
#pragma hdrstop

#ifndef TIUtilsH
#include "TIUtils.h"
#endif
#ifndef TIGlobalsH
#include "TIGlobals.h"
#endif
#ifndef TIGetEPDH
#include "TIGetEPD.h"
#endif
#include "TINtmDat.h"
//using namespace IPWorks;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDropDownEdit"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxLabel"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "ipwjson"
#pragma link "UWebGMaps"
#pragma link "UWebGMapsCommon"
#pragma link "cxButtons"
#pragma link "cxButtons"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDropDownEdit"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxLabel"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "ipwjson"
#pragma link "UWebGMaps"
#pragma link "UWebGMapsCommon"
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
#pragma link "AdvCGrid"
#pragma link "AdvGrid"
#pragma link "AdvObj"
#pragma link "AdvUtil"
#pragma link "BaseGrid"
#pragma link "ipsjsons"
#pragma resource "*.dfm"
TNeotomaDataForm *NeotomaDataForm;
TEPDDataForm *EPDDataForm;

//---------------------------------------------------------------------------
__fastcall TNeotomaDataForm::TNeotomaDataForm(TComponent* Owner)
	: TForm(Owner)
{
   Launched = false;
   UseGoogleMaps = tiGlobals->UseGoogleMaps;
   Height = tiGlobals->GoogleMapHeight;
   Width = tiGlobals->GoogleMapWidth;

   if (UseGoogleMaps) {
	 WebGMaps1->Align = alClient;
	 WebGMaps1->MapOptions->ZoomMap = tiGlobals->GoogleMapZoomLevel;
	 WebGMaps1->MapOptions->DefaultLatitude = tiGlobals->GoogleMapLatitude;
	 WebGMaps1->MapOptions->DefaultLongitude = tiGlobals->GoogleMapLongitude;
	 }
   else {
	 WebGMaps1->Visible = false;
	 AdvColumnGrid1->Visible = true;
	 AdvColumnGrid1->Align = alClient;
	 }

   PleaseWaitGroupBox->Left = (Width - PleaseWaitGroupBox->Width)/2;
   PleaseWaitGroupBox->Top = int(0.4*(float)Height - 0.5*(float)PleaseWaitGroupBox->Height);
   RatStart = 0;
   RatEnd = PleaseWaitGroupBox->Width - Image1->Width - 8;
   RatPos = 0;
   AllContactsLoaded = false;
   AllAuthorsLoaded = false;
}
//---------------------------------------------------------------------------

void TNeotomaDataForm::ShowPleaseWait(UnicodeString msg)
{
   RatStart = 0;
   RatPos = 0;
   cxLabel7->Caption = msg;
   Timer1->Enabled = true;
   PleaseWaitGroupBox->Visible = true;
}
//---------------------------------------------------------------------------

void TNeotomaDataForm::HidePleaseWait()
{
   Timer1->Enabled = false;
   PleaseWaitGroupBox->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaDataForm::FormClose(TObject *Sender, TCloseAction &Action)
{
   if (UseGoogleMaps) {
	 tiGlobals->GoogleMapHeight = Height;
	 tiGlobals->GoogleMapWidth = Width;
	 tiGlobals->GoogleMapZoomLevel = WebGMaps1->MapOptions->ZoomMap;
	 tiGlobals->GoogleMapLatitude = WebGMaps1->MapOptions->DefaultLatitude;
     tiGlobals->GoogleMapLongitude = WebGMaps1->MapOptions->DefaultLongitude;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaDataForm::FormActivate(TObject *Sender)
{
   UnicodeString msg;

   if (!Launched) {
	 //using namespace Dxuxtheme;
	 //using namespace IPWorks;
	 Timer1->Enabled = true;
	 bool error = false;
	 Screen->Cursor = crHourGlass;

	 NeotomaDatasetTypesHavingData NeotomaDatasetTypes(ipsJSONS1, TcpClient1);
	 StatusBar1->SimpleText = NeotomaDatasetTypes.WebServiceName();
	 if (NeotomaDatasetTypes.Execute()) {
	   map<int,UnicodeString>::iterator itr;
	   for (itr = NeotomaDatasetTypes.Items.begin(); itr != NeotomaDatasetTypes.Items.end(); itr++)
		 DatasetTypes[itr->second] = itr->first;
	   for (map<UnicodeString,int>::iterator mitr = DatasetTypes.begin(); mitr != DatasetTypes.end(); mitr++)
		 cxComboBox1->Properties->Items->Add(mitr->first);
	   }
	 else {
	   msg = L"Error executing Tilia API web service " + NeotomaDatasetTypes.WebServiceName();
	   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   error = true;
	   }

	 if (!error) {
	   GeoPolUnitsByRank Countries(ipsJSONS1, TcpClient1);
	   Countries.AddParam(L"RANK", 1);
	   StatusBar1->SimpleText = Countries.WebServiceName();
	   if (Countries.Execute()) {
		 for (unsigned int i=0; i<Countries.Size(); i++)
		   GeoPol1[Countries.Items[i].GeoPoliticalName] = Countries.Items[i].GeoPoliticalID;
		 map<UnicodeString,int>::iterator itr;
		 for (itr = GeoPol1.begin(); itr != GeoPol1.end(); itr++)
		   cxComboBox2->Properties->Items->Add(itr->first);
		 }
	   else {
		 msg = L"Error executing Tilia API web service " + Countries.WebServiceName();
	     MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 error = true;
		 }
	   }

	 if (!error) {
	   try {
		   Panel1->Enabled = true;
		   }
	   catch(Exception &e) {
		   MessageDlg(e.Message, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   }
	   }

	 HidePleaseWait();
	 StatusBar1->SimpleText = L"";
	 Screen->Cursor = crDefault;
	 Launched = true;
	 }
}
//---------------------------------------------------------------------------

void TNeotomaDataForm::GetDatasetTypeIDList(map<int,set<UnicodeString> >& DatasetContactMap,
	 UnicodeString& DatasetTypeIDList)
{
   if (DatasetContactMap.size() > 0) {  // some DatasetTypes already selected
	 map<UnicodeString,int>::iterator itr;
	 for (itr = DatasetTypes.begin(); itr != DatasetTypes.end(); itr++) {
	   if (DatasetContactMap.count(itr->second) == 0) {
		 if (!DatasetTypeIDList.IsEmpty()) DatasetTypeIDList += L",";
		 DatasetTypeIDList += IntToStr(itr->second);
		 }
	   }
	 }
}
//---------------------------------------------------------------------------

void TNeotomaDataForm::AddAliasNames(TcxComboBox* cxComboBox,
	map<UnicodeString,map<int,set<int> > >& ContactMap)
{
   for (unsigned int i=0; i<AliasNames.size(); i++) {
	 if (cxComboBox->Properties->Items->IndexOf(AliasNames[i].AliasContactName) == -1) {
	   if (cxComboBox->Properties->Items->IndexOf(AliasNames[i].CurrentContactName) > -1)
		 cxComboBox->Properties->Items->Add(AliasNames[i].AliasContactName);
	   }
	 }
}
//---------------------------------------------------------------------------

// search button
void __fastcall TNeotomaDataForm::cxButton1Click(TObject *Sender)
{
   UnicodeString msg;
   int row;

   if (UseGoogleMaps) {
	 WebGMaps1->DeleteAllMapMarker();
     WebGMaps1->Markers->Clear();
	 }
   Sites.clear();
   UnicodeString DatasetType = cxComboBox1->Text;
   UnicodeString SiteName = cxTextEdit1->Text;
   UnicodeString Country = cxComboBox2->Text;
   UnicodeString State = cxComboBox3->Text;
   UnicodeString County = cxComboBox4->Text;
   UnicodeString AdminUnit = cxComboBox5->Text;
   UnicodeString PIName = cxComboBox6->Text;
   UnicodeString AuthorName = cxComboBox7->Text;
   UnicodeString ContactName;

   int GeoPolID = -1;
   if (cxComboBox5->Enabled && !AdminUnit.IsEmpty())
	 GeoPolID = GeoPol4[AdminUnit];
   else if (cxComboBox4->Enabled && !County.IsEmpty())
	 GeoPolID = GeoPol3[County];
   else if (cxComboBox3->Enabled && !State.IsEmpty())
	 GeoPolID = GeoPol2[State];
   else if (!Country.IsEmpty())
	 GeoPolID = GeoPol1[Country];


   // map<int,map<UnicodeString,set<int> > > DatasetTypeMap; // DatasetTypeID, ContactName, DatasetID
   // map<UnicodeString,map<int,set<int> > > ContactMap;     // ContactName, DatasetTypeID, DatasetID
   // map<int,map<UnicodeString,set<int> > > DatasetTypeMap; // DatasetTypeID, ContactName, DatasetID

   int ContactID = -1;
   if (!PIName.IsEmpty())   // PI selected
	 ContactName = PIName;
   else if (!AuthorName.IsEmpty())
	 ContactName = AuthorName;

   if (!ContactName.IsEmpty()) {
	 NeotomaContactByContactName Contact(ipsJSONS1, TcpClient1);
	 Contact.AddParam(L"CONTACTNAME", ContactName);
	 StatusBar1->SimpleText = Contact.WebServiceName();
	 if (Contact.Execute()) {
	   if (Contact.Size() == 1)
		 ContactID = Contact.Items[0].AliasID;
	   }
	 else {
	   msg = L"Error executing Tilia API web service " + Contact.WebServiceName();
	   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return;
	   }
	 }

   NeotomaSites GetSites(ipsJSONS1, TcpClient1);
   if (!DatasetType.IsEmpty() && !SameText(DatasetType, L"All Dataset Types"))
	 GetSites.AddParam(L"DATASETTYPEID", DatasetTypes[DatasetType]);
   if (!SiteName.IsEmpty())
	 GetSites.AddParam(L"SITENAME", SiteName);
   if (GeoPolID > -1)
	 GetSites.AddParam(L"GEOPOLITICALID", GeoPolID);
   if (!PIName.IsEmpty())
	 GetSites.AddParam(L"CONTACTID", ContactID);
   else if (!AuthorName.IsEmpty())
	 GetSites.AddParam(L"AUTHORID", ContactID);

   StatusBar1->SimpleText = GetSites.WebServiceName();
   if (GetSites.Execute()) {
	 if (GetSites.Items.size() > 0)
	   Sites = GetSites.Items;
	 else
	   MessageDlg(L"No sites found!", mtInformation, TMsgDlgButtons() << mbOK, 0);
	 }
   else {
	 msg = L"Error executing Tilia API web service " + GetSites.WebServiceName();
	 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 }

   if (Sites.size() > 0) {
	 if (!UseGoogleMaps) {
	   AdvColumnGrid1->RowCount = Sites.size() + 1;
	   row = 1;
	   }
	 map<int,NEOTOMASITELOC>::iterator itr;
	 for (itr = Sites.begin(); itr != Sites.end(); itr++) {
	   double latitude = (itr->second.LatitudeNorth + itr->second.LatitudeSouth)/2.0;
	   double longitude = (itr->second.LongitudeEast + itr->second.LongitudeWest)/2.0;
	   //UnicodeString Icon = L"http://icons.iconarchive.com/icons/icons-land/vista-map-markers/16/Map-Marker-Bubble-Azure-icon.png";
	   UnicodeString Icon = L"";
	   if (UseGoogleMaps) {
		 TMarker* Marker = WebGMaps1->Markers->Add(latitude, longitude, itr->second.SiteName, Icon,
		   false, true, true, true, false, 0);
		 Marker->Tag = itr->first;
		 }
	   else {
		 AdvColumnGrid1->Cells[0][row] = itr->first;
		 AdvColumnGrid1->Cells[1][row] = itr->second.SiteName;
		 AdvColumnGrid1->Cells[2][row] = FloatToStr((itr->second.LatitudeNorth + itr->second.LatitudeSouth)/2.0);
		 AdvColumnGrid1->Cells[3][row] = FloatToStr((itr->second.LongitudeEast + itr->second.LongitudeWest)/2.0);
		 AdvColumnGrid1->Cells[4][row] = itr->second.GeoPolName1;
         AdvColumnGrid1->Cells[5][row++] = itr->second.GeoPolName2;
		 }
	   }
	 UnicodeString Text = IntToStr((int)Sites.size()) + L" site";
	 if (Sites.size() > 1) Text += L"s";
	 Text += L" found";
	 StatusBar1->SimpleText = Text;
	 }
   else
	 StatusBar1->SimpleText = L"";
}
//---------------------------------------------------------------------------

// select country
void __fastcall TNeotomaDataForm::cxComboBox2Click(TObject *Sender)
{
   Screen->Cursor = crHourGlass;
   GeoPol2.clear();
   GeoPol14.clear();
   GeoPol24.clear();
   GeoPol34.clear();
   cxComboBox3->Clear();
   cxComboBox3->Properties->Items->Clear();
   GeoPolUnitByHigherID CountrySubDivs(ipsJSONS1, TcpClient1);
   CountrySubDivs.AddParam(L"HIGHERGEOPOLID", GeoPol1[cxComboBox2->Text]);
   StatusBar1->SimpleText = CountrySubDivs.WebServiceName();
   if (CountrySubDivs.Execute()) {
	 for (unsigned int i=0; i<CountrySubDivs.Items.size(); i++) {
	   if (CountrySubDivs.Items[i].Rank == 2)
		 GeoPol2[CountrySubDivs.Items[i].GeoPoliticalName] = CountrySubDivs.Items[i].GeoPoliticalID;
	   else if (CountrySubDivs.Items[i].Rank == 4)
		 GeoPol14[CountrySubDivs.Items[i].GeoPoliticalName] = CountrySubDivs.Items[i].GeoPoliticalID;
	   }
	 if (GeoPol2.size() > 0) {
	   map<UnicodeString,int>::iterator itr;
	   for (itr = GeoPol2.begin(); itr != GeoPol2.end(); itr++)
		 cxComboBox3->Properties->Items->Add(itr->first);
	   cxLabel4->Enabled = true;
	   cxComboBox3->Enabled = true;
	   FillGeoPol4();
	   }
	 else {
	   cxLabel4->Enabled = false;
	   cxComboBox3->Enabled = false;
	   }
	 }
   else {
	 UnicodeString msg = L"Error executing Tilia API web service " + CountrySubDivs.WebServiceName();
	 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 cxLabel4->Enabled = false;
	 cxComboBox3->Enabled = false;
	 }
   Screen->Cursor = crDefault;
}
//---------------------------------------------------------------------------

// select state
void __fastcall TNeotomaDataForm::cxComboBox3Click(TObject *Sender)
{
   Screen->Cursor = crHourGlass;
   GeoPol3.clear();
   GeoPol24.clear();
   GeoPol34.clear();
   cxComboBox4->Clear();
   cxComboBox4->Properties->Items->Clear();
   GeoPolUnitByHigherID StateSubDivs(ipsJSONS1, TcpClient1);
   StateSubDivs.AddParam(L"HIGHERGEOPOLID", GeoPol2[cxComboBox3->Text]);
   StatusBar1->SimpleText = StateSubDivs.WebServiceName();
   if (StateSubDivs.Execute()) {
	 for (unsigned int i=0; i<StateSubDivs.Items.size(); i++) {
	   if (StateSubDivs.Items[i].Rank == 3)
		 GeoPol3[StateSubDivs.Items[i].GeoPoliticalName] = StateSubDivs.Items[i].GeoPoliticalID;
	   else if (StateSubDivs.Items[i].Rank == 4)
		 GeoPol24[StateSubDivs.Items[i].GeoPoliticalName] = StateSubDivs.Items[i].GeoPoliticalID;
	   }
	 if (GeoPol3.size() > 0) {
	   map<UnicodeString,int>::iterator itr;
	   for (itr = GeoPol3.begin(); itr != GeoPol3.end(); itr++)
		 cxComboBox4->Properties->Items->Add(itr->first);
	   cxLabel5->Enabled = true;
	   cxComboBox4->Enabled = true;
	   FillGeoPol4();
	   }
	 else {
	   cxLabel5->Enabled = false;
	   cxComboBox4->Enabled = false;
	   }
	 }
   else {
	 UnicodeString msg = L"Error executing Tilia API web service " + StateSubDivs.WebServiceName();
	 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 cxLabel5->Enabled = false;
	 cxComboBox4->Enabled = false;
	 }
   Screen->Cursor = crDefault;
}
//---------------------------------------------------------------------------

void TNeotomaDataForm::FillGeoPol4(void)
{
   Screen->Cursor = crHourGlass;
   GeoPol4.clear();
   cxComboBox5->Clear();
   cxComboBox5->Properties->Items->Clear();

   if (GeoPol14.size() > 0)
	 GeoPol4.insert(GeoPol14.begin(), GeoPol14.end());
   if (GeoPol24.size() > 0)
	 GeoPol4.insert(GeoPol24.begin(), GeoPol24.end());
   if (GeoPol34.size() > 0)
	 GeoPol4.insert(GeoPol34.begin(), GeoPol34.end());

   if (GeoPol4.size() > 0) {
	 map<UnicodeString,int>::iterator itr;
	 for (itr = GeoPol4.begin(); itr != GeoPol4.end(); itr++)
	   cxComboBox5->Properties->Items->Add(itr->first);
	 cxLabel6->Enabled = true;
	 cxComboBox5->Enabled = true;
	 }
   else {
	 cxLabel6->Enabled = false;
	 cxComboBox5->Enabled = false;
	 }
   Screen->Cursor = crDefault;
}
//---------------------------------------------------------------------------

// reset button
void __fastcall TNeotomaDataForm::cxButton2Click(TObject *Sender)
{
   FSelectedDatasets.clear();
   if (UseGoogleMaps) {
	 WebGMaps1->DeleteAllMapMarker();
     WebGMaps1->Markers->Clear();
	 }
   else {
	 AdvColumnGrid1->ClearNormalCells();
	 }
   Sites.clear();

   cxComboBox1->ItemIndex = -1;
   cxComboBox1->Clear();
   cxTextEdit1->Clear();

   cxComboBox2->ItemIndex = -1;
   cxComboBox2->Clear();

   cxComboBox3->ItemIndex = -1;
   cxComboBox3->Clear();
   cxComboBox3->Properties->Items->Clear();
   GeoPol2.clear();
   cxLabel4->Enabled = false;
   cxComboBox3->Enabled = false;

   cxComboBox4->ItemIndex = -1;
   cxComboBox4->Clear();
   cxComboBox4->Properties->Items->Clear();
   GeoPol3.clear();
   cxLabel5->Enabled = false;
   cxComboBox4->Enabled = false;

   cxComboBox5->ItemIndex = -1;
   cxComboBox5->Clear();
   cxComboBox5->Properties->Items->Clear();
   GeoPol4.clear();
   GeoPol14.clear();
   GeoPol24.clear();
   GeoPol34.clear();
   cxLabel6->Enabled = false;
   cxComboBox5->Enabled = false;

   cxComboBox6->ItemIndex = -1;
   cxComboBox7->ItemIndex = -1;
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaDataForm::WebGMaps1MarkerClick(TObject *Sender, UnicodeString MarkerTitle,
          int IdMarker, double Latitude, double Longitude, TMouseButton Button)
{
   if (Button == mbLeft) {
	 int SiteID = -1;
	 UnicodeString SiteName;
	 for (int i=0; i<WebGMaps1->Markers->Count; i++) {
	   TMarker* Marker = WebGMaps1->Markers->Items[i];
	   int idx = Marker->Index;
	   if (Marker->Index == IdMarker) {
		 SiteID = Marker->Tag;
		 SiteName = Marker->Title;
		 break;
		 }
	   }
	 if (SiteID > -1)
	   DownloadData(SiteID, SiteName);
	 }
}
//---------------------------------------------------------------------------

void TNeotomaDataForm::DownloadData(int SiteID, UnicodeString SiteName)
{
   vector<MAPDATASET> MapDatasets;
   NeotomaSiteDatasets SiteDatasets(ipsJSONS1, TcpClient1);
   SiteDatasets.AddParam(L"SITEID", SiteID);
   StatusBar1->SimpleText = SiteDatasets.WebServiceName();
   if (SiteDatasets.Execute()) {
	 if (SiteDatasets.Size() > 0) {
	   set<int> DatasetIDs;
	   if (!cxComboBox6->Text.IsEmpty()) {   // ContactName
		 UnicodeString ContactName = cxComboBox6->Text;
		 if (!cxComboBox1->Text.IsEmpty() && DatasetTypes.count(cxComboBox1->Text) == 1) {
		   int DatasetTypeID = DatasetTypes[cxComboBox1->Text];
		   DatasetIDs = ContactMap[ContactName][DatasetTypeID];
		   }
		 else {
		   map<int,set<int> >::iterator itr;
		   for (itr = ContactMap[ContactName].begin(); itr != ContactMap[ContactName].end(); itr++)
			 DatasetIDs.insert(itr->second.begin(), itr->second.end());
		   }
		 }

	   set<int> mdDatasetIDs;
	   set<int> mdCollUnitIDs;
	   for (unsigned int i=0; i<SiteDatasets.Size(); i++) {
		 int DatasetID = VariantToInt(SiteDatasets.Items[i].DatasetID, -1);
		 if (DatasetIDs.size() > 0) {
		   if (DatasetIDs.count(DatasetID) == 0)
			 continue;
		   }
		 MAPDATASET md;
		 md.SiteID = SiteID;
		 md.CollUnitID = VariantToInt(SiteDatasets.Items[i].CollectionUnitID, -1);
		 md.DatasetID = DatasetID;
		 md.DatasetType = VarToStr(SiteDatasets.Items[i].DatasetType);
		 md.CollUnitName = VarToStr(SiteDatasets.Items[i].CollUnitName);
		 MapDatasets.push_back(md);
		 mdDatasetIDs.insert(md.DatasetID);
		 mdCollUnitIDs.insert(md.CollUnitID);
		 }
	   // pickup geochron and LOI datasets associated with collection units
	   for (unsigned int i=0; i<SiteDatasets.Size(); i++) {
		 UnicodeString DatasetType = VarToStr(SiteDatasets.Items[i].DatasetType);
		 if (SameText(DatasetType, L"geochronologic") || SameText(DatasetType, L"loss-on-ignition")) {
		   int DatasetID = VariantToInt(SiteDatasets.Items[i].DatasetID, -1);
		   if (mdDatasetIDs.count(DatasetID) == 0) {
			 int CollUnitID = VariantToInt(SiteDatasets.Items[i].CollectionUnitID, -1);
			 if (mdCollUnitIDs.count(CollUnitID) > 0) {
			   MAPDATASET md;
			   md.SiteID = SiteID;
			   md.CollUnitID = CollUnitID;
			   md.DatasetID = DatasetID;
			   md.DatasetType = DatasetType;
			   md.CollUnitName = VarToStr(SiteDatasets.Items[i].CollUnitName);
			   MapDatasets.push_back(md);
			   mdDatasetIDs.insert(md.DatasetID);
			   mdCollUnitIDs.insert(md.CollUnitID);
			   }
			 }
		   }
		 }

	   MapSiteForm = new TMapSiteForm(SiteID, SiteName, MapDatasets, this);
	   int rv = MapSiteForm->ShowModal();
	   FSelectedDatasets.clear();
	   if (rv == mrOk)
		 FSelectedDatasets = MapSiteForm->SelectedDatasets;
	   delete MapSiteForm;
	   if (rv == mrOk) {
		 ModalResult = mrOk;
		 Close();
		 }
	   }
	 }
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaDataForm::Timer1Timer(TObject *Sender)
{
   RatPos += 48;
   if (RatPos > RatEnd)
	 RatPos = RatStart;
   Image1->Left = RatPos;
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaDataForm::cxComboBox6KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
   if (Key == VK_DELETE) {
	 cxComboBox6->ItemIndex = -1;
	 cxComboBox6->Clear();
	 }
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaDataForm::cxComboBox1KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
   if (Key == VK_DELETE) {
	 cxComboBox1->ItemIndex = -1;
	 cxComboBox1->Clear();
	 }
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaDataForm::cxComboBox7KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
   if (Key == VK_DELETE) {
	 cxComboBox7->ItemIndex = -1;
	 cxComboBox7->Clear();
	 }
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaDataForm::cxComboBox1PropertiesChange(TObject *Sender)
{
   cxComboBox6->ItemIndex = -1;
   cxComboBox6->Clear();
   cxComboBox6->Properties->Items->Clear();

   int DatasetTypeID = -1;
   if (cxComboBox1->Text.IsEmpty())
	 DatasetTypeID = 0;
   else if (DatasetTypes.count(cxComboBox1->Text) == 1)
	 DatasetTypeID = DatasetTypes[cxComboBox1->Text];

   set<UnicodeString>::iterator itr;
   if (DatasetTypeID == 0 && AllContactsLoaded) {
	 map<UnicodeString,map<int,set<int> > >::iterator itr;
	 for (itr = ContactMap.begin(); itr != ContactMap.end(); itr++)
	   cxComboBox6->Properties->Items->Add(itr->first);
	 }
   else if (DatasetContactMap.count(DatasetTypeID) == 1) {
	 for (itr = DatasetContactMap[DatasetTypeID].begin(); itr != DatasetContactMap[DatasetTypeID].end(); itr++) {
	   cxComboBox6->Properties->Items->Add(*itr);
	   }
	 }
   AddAliasNames(cxComboBox6, ContactMap);

   cxComboBox7->ItemIndex = -1;
   cxComboBox7->Clear();
   cxComboBox7->Properties->Items->Clear();

   if (DatasetTypeID == 0 && AllAuthorsLoaded) {
	 map<UnicodeString,map<int,set<int> > >::iterator itr;
	 for (itr = AuthorMap.begin(); itr != AuthorMap.end(); itr++)
	   cxComboBox7->Properties->Items->Add(itr->first);
	 }
   else if (DatasetAuthorMap.count(DatasetTypeID) == 1) {
	 for (itr = DatasetAuthorMap[DatasetTypeID].begin(); itr != DatasetAuthorMap[DatasetTypeID].end(); itr++) {
	   cxComboBox7->Properties->Items->Add(*itr);
	   }
	 }
   AddAliasNames(cxComboBox7, AuthorMap);
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaDataForm::cxComboBox6PropertiesChange(TObject *Sender)
{
   if (!cxComboBox6->Text.IsEmpty()) {
	 cxComboBox7->ItemIndex = -1;
	 cxComboBox7->Clear();
	 }
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaDataForm::cxComboBox7PropertiesEditValueChanged(TObject *Sender)
{
   if (!cxComboBox7->Text.IsEmpty()) {
	 cxComboBox6->ItemIndex = -1;
	 cxComboBox6->Clear();
	 }
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaDataForm::cxButton4Click(TObject *Sender)
{
   // get PI list
   Screen->Cursor = crHourGlass;
   NeotomaAllDatasetPIs DatasetPIs(ipsJSONS1, TcpClient1);
   StatusBar1->SimpleText = DatasetPIs.WebServiceName();
   if (DatasetPIs.Execute()) {
	 for (unsigned int i=0; i<DatasetPIs.Size(); i++)
	   cxComboBox6->Properties->Items->Add(DatasetPIs.Items[i]);
	 cxButton4->Visible = false;
	 cxComboBox6->Enabled = true;
	 cxComboBox6->Width = 178;
	 }
   else {
	 UnicodeString msg = L"Error executing Tilia API web service " + DatasetPIs.WebServiceName();
	 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 }
   StatusBar1->SimpleText = L"";
   Screen->Cursor = crDefault;
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaDataForm::cxButton5Click(TObject *Sender)
{
   // get Author list
   Screen->Cursor = crHourGlass;
   NeotomaAllDatasetAuthors DatasetAuthors(ipsJSONS1, TcpClient1);
   StatusBar1->SimpleText = DatasetAuthors.WebServiceName();
   if (DatasetAuthors.Execute()) {
	 for (unsigned int i=0; i<DatasetAuthors.Size(); i++)
	   cxComboBox7->Properties->Items->Add(DatasetAuthors.Items[i]);
	 cxButton5->Visible = false;
	 cxComboBox7->Enabled = true;
	 cxComboBox7->Width = 178;
	 }
   else {
	 UnicodeString msg = L"Error executing Tilia API web service " + DatasetAuthors.WebServiceName();
	 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 }
   StatusBar1->SimpleText = L"";
   Screen->Cursor = crDefault;
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaDataForm::cxButton7Click(TObject *Sender)
{
   return;
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaDataForm::cxButton6Click(TObject *Sender)
{
   return;
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaDataForm::AdvColumnGrid1HoverButtonClick(TObject *Sender,
		  int ARow, THoverButtonsCollectionItem *AButton)
{
   int SiteID = AdvColumnGrid1->Cells[0][ARow].ToInt();
   UnicodeString SiteName = AdvColumnGrid1->Cells[1][ARow];
   DownloadData(SiteID, SiteName);
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

__fastcall TEPDDataForm::TEPDDataForm(TComponent* Owner)
	: TNeotomaDataForm(Owner)
{
   cxLabel1->Visible = false;
   cxComboBox1->Visible = false;
   FlowPanel2->Visible = true;
   FlowPanel2->Top = 16;
   cxLabel4->Visible = false;
   cxComboBox3->Visible = false;
   cxLabel5->Visible = false;
   cxComboBox4->Visible = false;
   cxLabel6->Visible = false;
   cxComboBox5->Visible = false;
   cxLabel8->Visible = false;
   cxComboBox6->Visible = false;
   cxLabel9->Visible = false;
   cxComboBox7->Visible = false;
   cxButton4->Visible = false;
   cxButton5->Visible = false;
   FSiteNr = -1;
}
//---------------------------------------------------------------------------

void __fastcall TEPDDataForm::FormActivate(TObject *Sender)
{
   if (!Launched) {
	 Timer1->Enabled = true;
	 bool error = false;
	 Screen->Cursor = crHourGlass;

	 EPDGetCountriesWithSitesNotInNeotoma Countries(ipsJSONS1, TcpClient1);
	 StatusBar1->SimpleText = Countries.WebServiceName();
	 Countries.AddParam(L"NEW", 1);
	 if (Countries.Execute()) {
	   NewCountries = Countries.Items;
	   map<UnicodeString,int>::iterator itr;
	   for (itr = NewCountries.begin(); itr != NewCountries.end(); itr++)
		 cxComboBox2->Properties->Items->Add(itr->first);
	   }
	 else {
	   UnicodeString msg = L"Error executing Tilia API web service " + Countries.WebServiceName();
	   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   error = true;
	   }

	 if (!error) {
	   EPDGetCountriesWithSitesNotInNeotoma oldCountries(ipsJSONS1, TcpClient1);
	   StatusBar1->SimpleText = oldCountries.WebServiceName();
	   oldCountries.AddParam(L"NEW", 0);
	   if (oldCountries.Execute()) {
		 OldCountries = oldCountries.Items;
		 }
	   else {
		 UnicodeString msg = L"Error executing Tilia API web service " + oldCountries.WebServiceName();
	     MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 error = true;
		 }
	   }

	 if (!error) {
	   try {
		   Panel1->Enabled = true;
		   }
	   catch(Exception &e) {
		   MessageDlg(e.Message, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   }
	   }

	 HidePleaseWait();
	 Screen->Cursor = crDefault;
	 Launched = true;
	 }
}
//---------------------------------------------------------------------------

// select country
void __fastcall TEPDDataForm::cxComboBox2Click(TObject *Sender)
{
   return;
}
//---------------------------------------------------------------------------

// search button
void __fastcall TEPDDataForm::cxButton1Click(TObject *Sender)
{
   UnicodeString msg;

   WebGMaps1->DeleteAllMapMarker();
   WebGMaps1->Markers->Clear();
   Sites.clear();
   UnicodeString SiteName = cxTextEdit1->Text;
   UnicodeString Country = cxComboBox2->Text;

   if (!SiteName.IsEmpty()) {
	 EPDGetSiteByName EPDSite(ipsJSONS1, TcpClient1);
	 EPDSite.AddParam(L"SITENAME", SiteName);
	 EPDSite.AddParam(L"NEW", cxButton7->Down);
	 Screen->Cursor = crHourGlass;
	 StatusBar1->SimpleText = EPDSite.WebServiceName();
	 if (EPDSite.Execute()) {
	   if (EPDSite.Size() > 0)
		 Sites = EPDSite.Items;
	   else
		 MessageDlg(L"No sites found!", mtInformation, TMsgDlgButtons() << mbOK, 0);
	   }
	 else {
	   Screen->Cursor = crDefault;
	   msg = L"Error executing Tilia API web service " + EPDSite.WebServiceName();
	   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return;
	   }
	 }
   else if (!Country.IsEmpty()) {
	 EPDGetSitesNotInNeotomaByCountry EPDSites(ipsJSONS1, TcpClient1);
	 EPDSites.AddParam(L"COUNTRY", Country);
	 EPDSites.AddParam(L"NEW", cxButton7->Down);
	 Screen->Cursor = crHourGlass;
	 StatusBar1->SimpleText = EPDSites.WebServiceName();
	 if (EPDSites.Execute()) {
	   if (EPDSites.Size() > 0)
		 Sites = EPDSites.Items;
	   else
		 MessageDlg(L"No sites found!", mtInformation, TMsgDlgButtons() << mbOK, 0);
	   }
	 else {
	   Screen->Cursor = crDefault;
	   msg = L"Error executing Tilia API web service " + EPDSites.WebServiceName();
	   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return;
	   }
	 }

   if (Sites.size() > 0) {
	 int unrestricted = 0;
	 map<int,EPDSITELOC>::iterator itr;
	 for (itr = Sites.begin(); itr != Sites.end(); itr++) {
	   if (SameText(itr->second.UseStatus, L"U")) {
		 unrestricted++;
		 double latitude = itr->second.LatDD;
		 double longitude = itr->second.LonDD;
		 UnicodeString Icon = L"";
		 TMarkerIconColor IconColor = (cxButton6->Down) ? icBlue : icRed;
		 TMarker* Marker = WebGMaps1->Markers->Add(latitude, longitude, itr->second.SiteName, Icon,
		   false, true, true, true, false, 0, IconColor);
		 Marker->Tag = itr->first;
		 }
	   }
	 UnicodeString Text = IntToStr((int)unrestricted) + L" site";
	 if (unrestricted > 1) Text += L"s";
	 Text += L" found";
	 StatusBar1->SimpleText = Text;
	 }
   else
	 StatusBar1->SimpleText = L"";

   Screen->Cursor = crDefault;
}
//---------------------------------------------------------------------------

void __fastcall TEPDDataForm::WebGMaps1MarkerClick(TObject *Sender, UnicodeString MarkerTitle,
          int IdMarker, double Latitude, double Longitude, TMouseButton Button)
{
   if (Button == mbLeft) {
	 FSiteNr = -1;
	 UnicodeString SiteName;
	 for (int i=0; i<WebGMaps1->Markers->Count; i++) {
	   TMarker* Marker = WebGMaps1->Markers->Items[i];
	   int idx = Marker->Index;
	   if (Marker->Index == IdMarker) {
		 FSiteNr = Marker->Tag;
		 SiteName = Marker->Title;
		 break;
		 }
	   }

	 if (FSiteNr > -1) {
	   EPDGetEntitiesBySiteNr Entities(ipsJSONS1, TcpClient1);
	   Entities.AddParam(L"SITENR", FSiteNr);
	   Entities.AddParam(L"NEW", cxButton7->Down);
	   StatusBar1->SimpleText = Entities.WebServiceName();
	   if (Entities.Execute()) {
		 if (Entities.Size() > 0) {
		   EPDMapSiteForm = new TEPDMapSiteForm(SiteName, Entities.Items, this);
		   int rv = EPDMapSiteForm->ShowModal();
		   if (rv == mrOk) {
			 FEPDSiteLoc = Sites[FSiteNr];
			 FENr = EPDMapSiteForm->ENr;
			 }
		   else
			 FSiteNr = -1;
		   delete EPDMapSiteForm;
           if (rv == mrOk) {
			 ModalResult = mrOk;
			 Close();
			 }
		   }
		 }
	   StatusBar1->SimpleText = L"";
	   }
	 }
}
//---------------------------------------------------------------------------

// new sites
void __fastcall TEPDDataForm::cxButton7Click(TObject *Sender)
{
   if (cxButton7->Down) {
	 cxComboBox2->Properties->Items->Clear();
	 map<UnicodeString,int>::iterator itr;
	 for (itr = NewCountries.begin(); itr != NewCountries.end(); itr++)
	   cxComboBox2->Properties->Items->Add(itr->first);
	 }
}
//---------------------------------------------------------------------------

// old sites
void __fastcall TEPDDataForm::cxButton6Click(TObject *Sender)
{
   if (cxButton6->Down) {
	 cxComboBox2->Properties->Items->Clear();
	 map<UnicodeString,int>::iterator itr;
	 for (itr = OldCountries.begin(); itr != OldCountries.end(); itr++)
	   cxComboBox2->Properties->Items->Add(itr->first);
	 }
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaDataForm::ipsJSONS1SSLServerAuthentication(TObject *Sender,
          TipsJSONSSSLServerAuthenticationEventParams *e)
{
   e->Accept = true;
}
//---------------------------------------------------------------------------

