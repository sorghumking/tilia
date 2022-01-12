//---------------------------------------------------------------------------

#include <vcl.h>
#include "pch.h"
#pragma hdrstop

#include "TIWhitmore.h"
#ifndef TGParentH
#include "TGParent.h"
#endif
#ifndef TIGlobalsH
#include "TIGlobals.h"
#endif

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
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
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxLabel"
#pragma link "AdvCGrid"
#pragma link "AdvGrid"
#pragma link "AdvObj"
#pragma link "AdvUtil"
#pragma link "BaseGrid"
#pragma link "AdvCGrid"
#pragma link "AdvGrid"
#pragma link "AdvObj"
#pragma link "AdvUtil"
#pragma link "BaseGrid"
#pragma link "cxButtons"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "BaseGrid"
#pragma link "AdvCGrid"
#pragma link "AdvGrid"
#pragma link "AdvObj"
#pragma link "AdvUtil"
#pragma link "FlCtrlEx"
#pragma link "AdvNavBar"
#pragma link "AdvEdBtn"
#pragma link "AdvEdit"
#pragma link "AdvFileNameEdit"
#pragma resource "*.dfm"
TWhitmoreForm *WhitmoreForm;
//---------------------------------------------------------------------------
__fastcall TWhitmoreForm::TWhitmoreForm(TComponent* Owner)
	: TForm(Owner)
{
   CheckedRow = -1;
   activated = false;
   if (tiGlobals->WhitmorePath.IsEmpty())
	 cxButton1->Enabled = false;
   else
	 AdvFileNameEdit1->FileName = tiGlobals->WhitmorePath;
   WhitmoreAccess = NULL;
#ifdef ENASS
   CheckBox1->Visible = false;
   CheckBox2->Visible = false;
#endif
}
//---------------------------------------------------------------------------

void __fastcall TWhitmoreForm::FormActivate(TObject *Sender)
{
   if (!activated) {
	 if (tiGlobals->WhitmorePath.IsEmpty())
	   FocusControl(AdvFileNameEdit1);
	 else
	   FocusControl(cxButton1);
	 activated = true;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TWhitmoreForm::FormClose(TObject *Sender, TCloseAction &Action)
{
   if (WhitmoreAccess != NULL)
	 delete WhitmoreAccess;
}
//---------------------------------------------------------------------------

void __fastcall TWhitmoreForm::AdvFileNameEdit1ValueValidate(TObject *Sender, UnicodeString Value,
		  bool &IsValid)
{
   UnicodeString ext = ExtractFileExt(Value);
   if (SameText(ext,L".mdb"))
	 cxButton1->Enabled = FileExists(Value);
}
//---------------------------------------------------------------------------

bool TWhitmoreForm::ConnectToWhitmore(void)
{
   WhitmoreAccess = new Access(ADOConnection1, AdvFileNameEdit1->FileName);
   if (!WhitmoreAccess->Connect())
	 return false;

   try
	{
		ADODataSet1->Active = true;
	}
	catch (EADOError *e)
	{
		MessageDlg("Error while connecting to ADODataset1", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		return false;
	}

   tiGlobals->WhitmorePath = AdvFileNameEdit1->FileName;
   return true;
}
//---------------------------------------------------------------------------

void __fastcall TWhitmoreForm::cxButton1Click(TObject *Sender)
{
   UnicodeString SQL;

   /*
   SELECT Whitmore.ID1, Whitmore.AuthYr, Whitmore.Citation
   FROM Whitmore
   WHERE (((Whitmore.Removed)=False) AND ((Whitmore.NeotomaSampleID) Is Null) AND ((Whitmore.AuthYr) Is Not Null) AND ((Whitmore.LONDD)>-100));
   */

#ifdef ENASS
   SQL =  L"SELECT Whitmore.ID1, Whitmore.AuthYr, Whitmore.Citation ";
   SQL += L"FROM Whitmore ";
   SQL += L"WHERE (((Whitmore.Removed)=False) AND ((Whitmore.NeotomaSampleID) Is Null) ";
   // SQL += L"WHERE (((Whitmore.Removed)=False) AND ((Whitmore.NeotomaSampleID) Is Null) ";
   SQL += L"AND ((Whitmore.AuthYr) Is Not Null) AND ((Whitmore.LONDD)>-100));";
#else
   SQL =  L"SELECT Whitmore.ID1, Whitmore.AuthYr, Whitmore.Citation ";
   SQL += L"FROM Whitmore ";
   SQL += L"WHERE (";
   if (!CheckBox1->Checked)
	 SQL += L"((Whitmore.Removed)=False) AND ";
   SQL += L"((Whitmore.NeotomaSampleID) Is Null) ";
   SQL += L"AND ((Whitmore.AuthYr) Is Not Null)";
   if (CheckBox2->Checked)
	 SQL += L"AND ((Whitmore.LONDD)>-100)";
   SQL += L");";
#endif

   WideString WSQL = WideString(SQL);
   ADODataSet1->CommandText = WSQL;
   if (!ConnectToWhitmore())
	 return;

   ADODataSet1->Open();
   int RecCount = ADODataSet1->RecordCount;
   ADODataSet1->First();

   for (int i=0; i<=RecCount; i++) {
	 try {
		 CITATION Citation;
		 Citation.ID1 = ADODataSet1->FindField(L"ID1")->Value;
		 Citation.AuthYr = ADODataSet1->FindField(L"AuthYr")->Value;
		 Citation.Citation = ADODataSet1->FindField(L"Citation")->Value;
		 Citations.push_back(Citation);
		 if (UniqueCitations.count(Citation.AuthYr) == 0)
		   UniqueCitations[Citation.AuthYr] = Citation.Citation;
		 }
	 catch (...) {
		 UnicodeString msg = L"Error parsing Whitmore record. ID1 = «" +
			VarToStr(ADODataSet1->FindField(L"ID1")->Value) + L"», AuthYr = «" +
			VarToStr(ADODataSet1->FindField(L"AuthYr")->Value) + L"», Citation = «" +
			VarToStr(ADODataSet1->FindField(L"Citation")->Value) + L"»";
		 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 return;
		 }
	 ADODataSet1->Next();
	 }
   AdvColumnGrid1->RowCount = UniqueCitations.size() + 1;
   AdvColumnGrid1->AddCheckBoxColumn(0, false, false);
   map<UnicodeString,UnicodeString>::iterator itr;
   int row = 1;
   for (itr = UniqueCitations.begin(); itr != UniqueCitations.end(); itr++) {
	 AdvColumnGrid1->Cells[1][row] = itr->first;
	 AdvColumnGrid1->Cells[2][row] = itr->second;
	 row++;
	 }
   cxButton1->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TWhitmoreForm::AdvColumnGrid1CheckBoxClick(TObject *Sender, int ACol,
          int ARow, bool State)
{
   if (State) {
	 if (CheckedRow != -1)
	   AdvColumnGrid1->SetCheckBoxState(0,CheckedRow,false);
	 CheckedRow = ARow;
	 cxButton2->Enabled = true;
	 }
   else {
	 CheckedRow = -1;
	 cxButton2->Enabled = false;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TWhitmoreForm::AdvColumnGrid1ClickSort(TObject *Sender, int ACol)
{
   bool state;
   for (int row=1; row<AdvColumnGrid1->RowCount; row++) {
	 AdvColumnGrid1->GetCheckBoxState(0, row, state);
	 if (state) {
	   CheckedRow = row;
	   return;
	   }
	 }
}
//---------------------------------------------------------------------------

void __fastcall TWhitmoreForm::cxButton2Click(TObject *Sender)
{
   // get ID1 values
   TSSForm = ParentForm->NewSpreadSheetForm();
   if (TSSForm == NULL) return;

   TSSForm->Datasets[0].DatasetType = L"Pollen surface sample";
   TSSForm->ProfGrid1->AbsoluteCells[1][1]->Value = L"Pollen surface sample";
   UnicodeString AuthYr = AdvColumnGrid1->Cells[1][CheckedRow];

   vector<int> ID1;
   for (unsigned int i = 0; i < Citations.size(); i++) {
	 if (SameText(AuthYr,Citations[i].AuthYr))
	   ID1.push_back(Citations[i].ID1);
	 }

   UnicodeString SQL1;
   SQL1 =  L"SELECT Whitmore.ID1, Whitmore.SITECODE, Whitmore.SITENAME, Whitmore.LONDD, Whitmore.LATDD, Whitmore.ELEVATION";
   SQL1 += L", Whitmore.COLLECTOR, Whitmore.DescrEnv, Whitmore.DepthAtLoc, Whitmore.princinvest, Whitmore.YrOfSamp";
   SQL1 += L", Whitmore.Notes ";
   SQL1 += L"FROM Whitmore ";
   SQL1 += L"WHERE (((Whitmore.ID1)=?));";


   UnicodeString DataTable = (CheckBox1->Checked) ? L"Whitmore_Data_All" : L"Whitmore_Data";
   UnicodeString SQL2;
   SQL2 =  L"SELECT Taxa.TaxonCode, Taxa.TaxonName, VariableElements.VariableElement, VariableUnits.VariableUnits, ";
   SQL2 += (L"EcolGroups.EcolGroupID, " + DataTable + L".Value ");
   SQL2 += L"FROM VariableUnits INNER JOIN (VariableElements ";
   SQL2 += L"INNER JOIN ((Taxa INNER JOIN EcolGroups ON (Taxa.TaxonID = EcolGroups.TaxonID) AND ";
   SQL2 += L"(Taxa.TaxonID = EcolGroups.TaxonID)) ";
   SQL2 += (L"INNER JOIN (" + DataTable + " INNER JOIN Variables ON " + DataTable + L".VariableID = Variables.VariableID) ");
   SQL2 += L"ON (Taxa.TaxonID = Variables.TaxonID) AND (Taxa.TaxonID = Variables.TaxonID)) ";
   SQL2 += L"ON (VariableElements.VariableElementID = Variables.VariableElementID) AND ";
   SQL2 += L"(VariableElements.VariableElementID = Variables.VariableElementID)) ON ";
   SQL2 += L"(VariableUnits.VariableUnitsID = Variables.VariableUnitsID) AND ";
   SQL2 += L"(VariableUnits.VariableUnitsID = Variables.VariableUnitsID) ";
   SQL2 += L"WHERE (((" + DataTable + L".ID1)=?))";

   UnicodeString SQL3;
   SQL3 =  L"SELECT Whitmore_AltSiteNames.AltSiteName ";
   SQL3 += L"FROM Whitmore_AltSiteNames ";
   SQL3 += L"WHERE (((Whitmore_AltSiteNames.ID1)=?))";

   md[L"sampname"] = WMETADATA(3,L"#Samp.Name",L"Sample Name");
   md[L"analyst"]  = WMETADATA(4,L"#Samp.Analyst",L"Sample Analyst");
   md[L"sitename"] = WMETADATA(5,L"#Site.Name",L"Site name");
   md[L"latn"]     = WMETADATA(6,L"#Site.LatN",L"North Latitude");
   md[L"lats"]     = WMETADATA(7,L"#Site.LatS",L"South Latitude");
   md[L"longw"]    = WMETADATA(8,L"#Site.LongW",L"West Longitude");
   md[L"longe"]    = WMETADATA(9,L"#Site.LongE",L"East Longitude");
   md[L"geopol1"]  = WMETADATA(10,L"#Site.GeoPol1",L"First Geopolitical Division");
   md[L"geopol2"]  = WMETADATA(11,L"#Site.GeoPol2",L"Second Geopolitical Division");
   md[L"geopol3"]  = WMETADATA(12,L"#Site.GeoPol3",L"Third Geopolitical Division");
   md[L"admin"]    = WMETADATA(13,L"#Site.Admin",L"Administrative Unit");
   md[L"altitude"] = WMETADATA(14,L"#Site.Altitude",L"Altitude (m)");
   md[L"area"]     = WMETADATA(15,L"#Site.Area",L"Area of Site (ha)");
   md[L"desc"]     = WMETADATA(16,L"#Site.Desc",L"Site Description");
   md[L"snotes"]   = WMETADATA(17,L"#Site.Notes",L"Site Notes");
   md[L"handle"]   = WMETADATA(18,L"#Coll.Handle",L"Handle");
   md[L"collname"] = WMETADATA(19,L"#Coll.Name",L"Collection Unit Name");
   md[L"type"]     = WMETADATA(20,L"#Coll.Type",L"Collection Unit Type");
   md[L"device"]   = WMETADATA(21,L"#Coll.Device",L"Collection Device");
   md[L"contacts"] = WMETADATA(22,L"#Coll.Contacts",L"Collectors");
   md[L"date"]     = WMETADATA(23,L"#Coll.Date",L"Date Collected");
   md[L"loc"]      = WMETADATA(24,L"#Coll.Loc",L"Location in Site");
   md[L"depenv"]   = WMETADATA(25,L"#Coll.DepEnv",L"Depositional Environment");
   md[L"waterdep"] = WMETADATA(26,L"#Coll.WaterDep",L"Water Depth");
   md[L"cnotes"]   = WMETADATA(27,L"#Coll.Notes",L"Collection Unit Notes");
   int current_row = 28;

   vector<pair<UnicodeString,UnicodeString> > de;
   de.push_back(pair<UnicodeString,UnicodeString>(L"Bog",L"Bog"));
   de.push_back(pair<UnicodeString,UnicodeString>(L"glacial origin, natural open water",L"Glacial Origin Lake"));
   de.push_back(pair<UnicodeString,UnicodeString>(L"Humus",L"Humus"));
   de.push_back(pair<UnicodeString,UnicodeString>(L"Lacustrine",L"Lacustrine"));
   de.push_back(pair<UnicodeString,UnicodeString>(L"Lake - Ekman dredge",L"Lacustrine"));
   de.push_back(pair<UnicodeString,UnicodeString>(L"Marsh",L"Marsh"));
   de.push_back(pair<UnicodeString,UnicodeString>(L"Mire",L"Mire"));
   de.push_back(pair<UnicodeString,UnicodeString>(L"Moist soil",L"Moist Soil"));
   de.push_back(pair<UnicodeString,UnicodeString>(L"Moss polster",L"Moss Polster"));
   de.push_back(pair<UnicodeString,UnicodeString>(L"Natural open water",L"Natural Lake"));
   de.push_back(pair<UnicodeString,UnicodeString>(L"Pond",L"Pond"));
   de.push_back(pair<UnicodeString,UnicodeString>(L"RV Dep, Oxbow Lake",L"Oxbow Lake"));
   de.push_back(pair<UnicodeString,UnicodeString>(L"swamp",L"Swamp"));
   de.push_back(pair<UnicodeString,UnicodeString>(L"Tarn-lake",L"Cirque Lake"));
   de.push_back(pair<UnicodeString,UnicodeString>(L"Wet soil",L"Moist Soil"));

   current_col = 8;

   map<UnicodeString,WHITMOREVAR> wdata;  // TaxonName, WHITMOREVAR
   UnicodeString SiteCode;

   if (ID1.size() == 1) {
	 TSSForm->ProfGrid1->AbsoluteCells[1][3]->Value = WideString(md[L"sampname"].Code);
	 TSSForm->ProfGrid1->AbsoluteCells[2][3]->Value = WideString(md[L"sampname"].Name);
	 TSSForm->ProfGrid1->AbsoluteCells[current_col][md[L"sampname"].Row]->Value = ID1[0];
	 current_row = 4;
	 //TSSForm->Datasets[0].WhitmoreID1 = ID1[0];
	 TSSForm->Datasets[0].WhitmoreData = true;
	 RunQuery(ID1[0], SQL1);
	 SITE* Site = (SITE*)TSSForm->Sites->Items[0];
	 GetSiteMetadata(Site, SiteCode);
	 TSSForm->ProfGrid1->AbsoluteCells[8][2]->Value = WideString(SiteCode);
	 GetCollUnitMetadata(Site->CollUnits[0], ID1[0], SiteCode, de);
	 GetDatasetMetadata(AuthYr);

	 RunQuery(ID1[0], SQL2);
	 GetData(8, wdata);

	 RunQuery(ID1[0], SQL3);
	 GetAltSiteName(Site);
	 }
   else if (ID1.size() > 1) {
	 // enter spreadsheet metadata records
	 map<UnicodeString,WMETADATA>::iterator itr;
	 for (itr = md.begin(); itr != md.end(); itr++) {
	   TSSForm->ProfGrid1->AbsoluteCells[1][itr->second.Row]->Value = WideString(itr->second.Code);
	   TSSForm->ProfGrid1->AbsoluteCells[2][itr->second.Row]->Value = WideString(itr->second.Name);
	   }

	 // get metadata and data for each sample
	 for (unsigned i=0; i<ID1.size(); i++) {
	   //TSSForm->Datasets[0].WhitmoreID1 = ID1[i];
	   int nc = 1;
	   TSSForm->Datasets[0].WhitmoreData = true;
	   RunQuery(ID1[i], SQL1);

	   SITE* Site = new SITE();
	   TSSForm->Sites->Add(Site);

	   COLLECTION CollUnit;
	   Site->CollUnits.push_back(CollUnit);

	   GetSiteMetadata(Site, SiteCode);

	   CELLOBJECT* CellObject = new CELLOBJECT(Site);
	   TProfGridCell* ACell = TSSForm->ProfGrid1->AbsoluteCells[current_col][md[L"sitename"].Row];
	   TSSForm->AddCellObject(ACell, CellObject);

	   ACell->Value = WideString(Site->SiteName);
	   TSSForm->ProfGrid1->AbsoluteCells[current_col][2]->Value = WideString(SiteCode);
	   TSSForm->ProfGrid1->AbsoluteCells[current_col][md[L"sampname"].Row]->Value = ID1[i];
	   TSSForm->ProfGrid1->AbsoluteCells[current_col][md[L"longw"].Row]->Value = Site->LongWest;
	   TSSForm->ProfGrid1->AbsoluteCells[current_col][md[L"longe"].Row]->Value = Site->LongEast;
	   TSSForm->ProfGrid1->AbsoluteCells[current_col][md[L"latn"].Row]->Value = Site->LatNorth;
	   TSSForm->ProfGrid1->AbsoluteCells[current_col][md[L"lats"].Row]->Value = Site->LatSouth;
	   TSSForm->ProfGrid1->AbsoluteCells[current_col][md[L"altitude"].Row]->Value = Site->Altitude;

	   GetCollUnitMetadata(Site->CollUnits[nc], ID1[i], SiteCode, de);
	   TSSForm->ProfGrid1->AbsoluteCells[current_col][md[L"handle"].Row]->Value = WideString(SiteCode);
	   TSSForm->ProfGrid1->AbsoluteCells[current_col][md[L"collname"].Row]->Value = WideString(SiteCode);
	   TSSForm->ProfGrid1->AbsoluteCells[current_col][md[L"type"].Row]->Value = WideString(L"Modern");
	   TSSForm->ProfGrid1->AbsoluteCells[current_col][md[L"depenv"].Row]->Value = WideString(Site->CollUnits[nc].DepEnv);
	   TSSForm->ProfGrid1->AbsoluteCells[current_col][md[L"device"].Row]->Value = WideString(Site->CollUnits[nc].CollectionDevice);
	   TSSForm->ProfGrid1->AbsoluteCells[current_col][md[L"waterdep"].Row]->Value = Site->CollUnits[nc].WaterDepth;
	   TSSForm->ProfGrid1->AbsoluteCells[current_col][md[L"date"].Row]->Value = Site->CollUnits[nc].CollDate;
	   TSSForm->ProfGrid1->AbsoluteCells[current_col][md[L"snotes"].Row]->Value = WideString(Site->CollUnits[nc].Notes);
	   if (Site->CollUnits[nc].Collectors.size() > 0) {
		 CONTACT* Contact = Site->CollUnits[nc].Collectors[0];
		 ACell = TSSForm->ProfGrid1->AbsoluteCells[current_col][md[L"contacts"].Row];
		 CellObject = new CELLOBJECT(CELLCONTACTS);
		 TSSForm->AddCellObject(ACell, CellObject);
		 TList* CellContacts = (TList*)CellObject->Object;
		 CellContacts->Add(Contact);
		 ACell->Value = Contact->ShortContactName;
		 }

	   GetDatasetMetadata(AuthYr);

	   // get data
	   RunQuery(ID1[i], SQL2);
	   GetData(current_col, wdata);

	   // check for alterntive site name
	   RunQuery(ID1[i], SQL3);
	   if (GetAltSiteName(Site))
		 TSSForm->ProfGrid1->AbsoluteCells[current_col][md[L"sitename"].Row]->Value = WideString(Site->SiteName);

	   current_col++;
	   }
	 }

   // write data to spreadsheet
   vector<UnicodeString> EcolGroupTypes;
   EcolGroupTypes.push_back(L"TRSH");
   EcolGroupTypes.push_back(L"UPHE");
   EcolGroupTypes.push_back(L"VACR");
   EcolGroupTypes.push_back(L"AQBR");

   map<UnicodeString,WHITMOREVAR>::iterator itr;
   for (unsigned int i = 0; i < EcolGroupTypes.size(); i++) {
	 for (itr = wdata.begin(); itr != wdata.end(); itr++) {
	   if (itr->second.EcolGroup == EcolGroupTypes[i]) {
		 TSSForm->ProfGrid1->AbsoluteCells[1][current_row]->Value = WideString(itr->second.TaxonCode);
		 TSSForm->ProfGrid1->AbsoluteCells[2][current_row]->Value = WideString(itr->first);
		 TSSForm->ProfGrid1->AbsoluteCells[3][current_row]->Value = WideString(itr->second.Element);
		 TSSForm->ProfGrid1->AbsoluteCells[4][current_row]->Value = WideString(itr->second.Units);
		 TSSForm->ProfGrid1->AbsoluteCells[7][current_row]->Value = WideString(itr->second.EcolGroup);
		 map<int,double>::iterator it;
		 for (it = itr->second.Values.begin(); it != itr->second.Values.end(); it++)
		   TSSForm->ProfGrid1->AbsoluteCells[it->first][current_row]->Value = it->second;
		 current_row++;
		 }
	   }
	 }

   ModalResult = mrOk;
}
//---------------------------------------------------------------------------

void TWhitmoreForm::RunQuery(int ID1, UnicodeString SQL)
{
   ADODataSet1->Close();
   UnicodeString sql = SQL;
   UnicodeString ID = IntToStr(ID1);
   int pos = sql.Pos(L"?");
   sql.Delete(pos,1);
   sql.Insert(ID,pos);
   WideString WSQL = WideString(sql);
   ADODataSet1->CommandText = WSQL;
   ADODataSet1->Open();
   ADODataSet1->First();
}
//---------------------------------------------------------------------------

void TWhitmoreForm::GetSiteMetadata(SITE* Site, UnicodeString& SiteCode)
{
   UnicodeString SiteName = VarToStr(ADODataSet1->FindField(L"SITENAME")->Value);
   Site->SiteName = SiteName;
   SiteCode = ADODataSet1->FindField(L"SITECODE")->Value;
   double londd = ADODataSet1->FindField(L"LONDD")->Value;
   Site->LongWest = londd;
   Site->LongEast = londd;
   double latdd = ADODataSet1->FindField(L"LATDD")->Value;
   Site->LatNorth = latdd;
   Site->LatSouth = latdd;
   double altitude = ADODataSet1->FindField(L"ELEVATION")->Value;
   Site->Altitude = altitude;
}
//---------------------------------------------------------------------------

bool TWhitmoreForm::GetAltSiteName(SITE* Site)
{
   int RecCount = ADODataSet1->RecordCount;
   if (RecCount == 1) {
	 UnicodeString AltSiteName = VarToStr(ADODataSet1->FindField(L"AltSiteName")->Value);
	 if (!SameText(AltSiteName,L"No name")) {
	   Site->SiteName = AltSiteName;
	   return true;
	   }
	 }
   return false;
}
//---------------------------------------------------------------------------

void TWhitmoreForm::GetCollUnitMetadata(COLLECTION& CollUnit, int ID1, UnicodeString SiteCode,
	vector<pair<UnicodeString,UnicodeString> >& de)
{
   CollUnit.Handle = SiteCode;
   CollUnit.CollectionName = SiteCode;
   CollUnit.CollectionType = L"Modern";

   UnicodeString Collector = VarToStr(ADODataSet1->FindField(L"COLLECTOR")->Value);
   AddCollector(Collector, CollUnit);

   UnicodeString DescrEnv = VarToStr(ADODataSet1->FindField(L"DescrEnv")->Value);
   UnicodeString DepEnv;
   UnicodeString Device;
   for (unsigned int j=0; j<de.size(); j++) {
	 if (SameText(DescrEnv,de[j].first)) {
	   DepEnv = de[j].second;
	   if (SameText(DescrEnv,L"Lake - Ekman dredge"))
		 Device = L"Ekman dredge";
	   break;
	   }
	 }
   if (!DepEnv.IsEmpty()) {
	 CollUnit.DepEnv = DepEnv;
	 if (!Device.IsEmpty())
	   CollUnit.CollectionDevice = Device;
	 }

   double Depth;
   Variant var = ADODataSet1->FindField(L"DepthAtLoc")->Value;
   if (TryVariantToDouble(var,Depth)) {
	 if (Depth >= 100) Depth /= 100;
	 CollUnit.WaterDepth = Depth;
	 }

   var = ADODataSet1->FindField(L"YrOfSamp")->Value;
   double dyear;
   if (TryVariantToDouble(var,dyear)) {
	 unsigned short year = dyear;
	 unsigned short month = 1;
	 unsigned short day = 1;
	 TDateTime Date = TDateTime(year, month, day);
	 CollUnit.CollDate = Date;
	 }

   UnicodeString Notes = VarToStr(ADODataSet1->FindField(L"Notes")->Value);
   if (!Notes.IsEmpty())
	 CollUnit.Notes = Notes;
}
//---------------------------------------------------------------------------

void TWhitmoreForm::GetDatasetMetadata(UnicodeString AuthYr)
{
   UnicodeString PubYear;

   UnicodeString Investigator = VarToStr(ADODataSet1->FindField(L"princinvest")->Value);
   AddPI(Investigator);

   if (TSSForm->Publications->Count == 0) {
	 GetPubYear(AuthYr, PubYear);
	 if (!PubYear.IsEmpty()) {
	   PUBLICATION* pub = new PUBLICATION(OTHER_AUTHORED);
	   pub->PublicationYear = PubYear;
	   pub->Title = AdvColumnGrid1->Cells[2][CheckedRow];
	   pub->Citation = AdvColumnGrid1->Cells[2][CheckedRow];
	   TSSForm->Publications->Add(pub);
	   TSSForm->AdvColumnGrid4->RowCount = 2;
	   TSSForm->AdvColumnGrid4->Cells[1][1] = pub->Citation;
	   TSSForm->AdvColumnGrid4->Objects[1][1] = (TObject*)pub;
	   }
	 }

   TSSForm->Datasets[0].Notes = L"Data imported from the Whitmore database.";
}
//---------------------------------------------------------------------------

void TWhitmoreForm::GetPubYear(UnicodeString AuthYr, UnicodeString& PubYear)
{
   UnicodeString digits = L"0123456789";
   // IsDelimiter(const UnicodeString& delimiters, int index)
   PubYear = L"";
   int len = AuthYr.Length() - 3;
   for (int idx = 1; idx <= len; idx++) {
	 if (AuthYr.IsDelimiter(digits,idx)) {
	   if (AuthYr.IsDelimiter(digits,idx+1) &&
		   AuthYr.IsDelimiter(digits,idx+2) &&
		   AuthYr.IsDelimiter(digits,idx+3)) {
		 PubYear = AuthYr.SubString(idx,4);
		 return;
		 }
	   }
	 }
}
//---------------------------------------------------------------------------

void TWhitmoreForm::GetData(int col, map<UnicodeString,WHITMOREVAR>& wdata)
{
   set<UnicodeString> EcolGroups;
   int RecCount = ADODataSet1->RecordCount;
   for (int i=0; i<=RecCount; i++) {
	 UnicodeString TaxonName = VarToStr(ADODataSet1->FindField(L"TaxonName")->Value);
	 if (wdata.count(TaxonName) == 0) {
	   WHITMOREVAR wvar;
	   wvar.TaxonCode = VarToStr(ADODataSet1->FindField(L"TaxonCode")->Value);
	   wvar.Element = VarToStr(ADODataSet1->FindField(L"VariableElement")->Value);
	   wvar.Units = VarToStr(ADODataSet1->FindField(L"VariableUnits")->Value);
	   wvar.EcolGroup = VarToStr(ADODataSet1->FindField(L"EcolGroupID")->Value);
	   if (EcolGroups.count(wvar.EcolGroup) == 0)
		 EcolGroups.insert(wvar.EcolGroup);
	   wdata[TaxonName] = wvar;
	   }
	 Variant Value = ADODataSet1->FindField(L"Value")->Value;
	 if (!Value.IsNull())
	   wdata[TaxonName].Values[current_col] = ADODataSet1->FindField(L"Value")->Value;
	 ADODataSet1->Next();
	 }
}
//---------------------------------------------------------------------------

void TWhitmoreForm::AddCollector(UnicodeString Collector, COLLECTION& CollUnit)
{
   CONTACT* Contact = NULL;

   if (Collector.IsEmpty())
	 return;
   if (People.count(Collector) == 0) {
	 Contact = new CONTACT;
	 ParseName(Collector, Contact);
	 }
   else {
	 map<UnicodeString,CONTACT*>::iterator itr = People.find(Collector);
	 if (itr != People.end())
	   Contact = itr->second;
	 }

   if (Contact != NULL)
	 CollUnit.Collectors.push_back(Contact);
}
//---------------------------------------------------------------------------

void TWhitmoreForm::AddPI(UnicodeString Investigator)
{
   if (Investigator.IsEmpty())
	 return;

   CONTACT* Contact = NULL;
   if (People.count(Investigator) == 0) {
	 Contact = new CONTACT;
	 ParseName(Investigator, Contact);
	 }
   else {
	 map<UnicodeString,CONTACT*>::iterator itr = People.find(Investigator);
	 if (itr != People.end())
	   Contact = itr->second;
	 }

   if (Contact != NULL)
	 TSSForm->Datasets[0].Investigators.push_back(Contact);
}
//---------------------------------------------------------------------------

void TWhitmoreForm::ParseName(UnicodeString Name, CONTACT* Contact)
{
   UnicodeString LastName, FirstName, Initials;

   int pos = Name.Pos(L",");
   LastName = Name.SubString(1,pos-1);
   FirstName = Name;
   FirstName.Delete(1,pos);
   Initials = FirstName.SubString(1,1);
   Initials += L".";
   int len = FirstName.Length();
   int j = 1;
   while (j <= len) {
	 if (FirstName[j] == L' ') {
	   j++;
	   if (j < len) {
		 Initials += FirstName.SubString(j,1);
		 Initials += L".";
		 }
	   }
	 j++;
	 }

   Contact->FamilyName = LastName;
   Contact->GivenNames = FirstName;
   Contact->LeadingInitials = Initials;
   Contact->FormatContactName();
   TSSForm->ContactList->Add(Contact);
   People[Name] = Contact;
}
//---------------------------------------------------------------------------

