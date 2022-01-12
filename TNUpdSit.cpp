//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TNUpdSit.h"
#ifndef TNUtilsH
#include "TNUtils.h"
#endif
#ifndef TNLoginH
#include "TNLogin.h"
#endif
#ifndef TICommonH
#include "TICommon.h"
#endif

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvCGrid"
#pragma link "AdvGrid"
#pragma link "AdvObj"
#pragma link "BaseGrid"
#pragma link "AdvCGrid"
#pragma link "AdvGrid"
#pragma link "AdvObj"
#pragma link "BaseGrid"
#pragma link "cxGraphics"
#pragma link "ipwjson"
#pragma link "cxButtons"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxLabel"
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
#pragma link "AdvUtil"
#pragma link "dxSkinOffice2016Colorful"
#pragma link "dxSkinOffice2016Dark"
#pragma link "dxSkinVisualStudio2013Blue"
#pragma link "dxSkinVisualStudio2013Dark"
#pragma link "dxSkinVisualStudio2013Light"
#pragma link "ipsjsons"
#pragma resource "*.dfm"
TUpdateNeotomaSiteForm *UpdateNeotomaSiteForm;
TUpdateNeotomaCollUnitForm *UpdateNeotomaCollUnitForm;
TUpdateNeotomaDatasetForm *UpdateNeotomaDatasetForm;
TNeotomaSiteValidationForm *NeotomaSiteValidationForm;
TNeotomaCollUnitValidationForm *NeotomaCollUnitValidationForm;
TNeotomaDatasetValidationForm *NeotomaDatasetValidationForm;
//---------------------------------------------------------------------------

__fastcall TUpdateNeotomaSiteForm::TUpdateNeotomaSiteForm(SITE* sptr, bool update, TComponent* Owner)
	: TForm(Owner)
{
   TSSForm = (TTilSpreadSheetForm*)Owner;
   TUploadForm = NULL;
   site_ptr = sptr;
   activated = false;
   update_tilia = update;
   ArrowBmp = NULL;
}
//---------------------------------------------------------------------------

__fastcall TUpdateNeotomaSiteForm::TUpdateNeotomaSiteForm(SITE* sptr, bool update, TComponent* Parent, TComponent* Owner)
	: TForm(Owner)
{
   TSSForm = (TTilSpreadSheetForm*)Parent;
   TUploadForm = (TNeotomaUploadForm*)Owner;
   site_ptr = sptr;
   activated = false;
   update_tilia = update;
   ArrowBmp = NULL;
}
//---------------------------------------------------------------------------

void __fastcall TUpdateNeotomaSiteForm::FormCreate(TObject *Sender)
{
   AdvColumnGrid1->Cells[0][1] = L"Site Name";
   AdvColumnGrid1->Cells[0][2] = L"North Latitude";
   AdvColumnGrid1->Cells[0][3] = L"South Latitude";
   AdvColumnGrid1->Cells[0][4] = L"West Longitude";
   AdvColumnGrid1->Cells[0][5] = L"East Longitude";
   AdvColumnGrid1->Cells[0][6] = L"First Geopolitical";
   AdvColumnGrid1->Cells[0][7] = L"Second Geopolitical";
   AdvColumnGrid1->Cells[0][8] = L"Third Geopolitical";
   AdvColumnGrid1->Cells[0][9] = L"Administrative Unit";
   AdvColumnGrid1->Cells[0][10] = L"Altitude (m)";
   AdvColumnGrid1->Cells[0][11] = L"Area of Site (ha)";
   AdvColumnGrid1->Cells[0][12] = L"Site Description";
   AdvColumnGrid1->Cells[0][13] = L"Site Notes";

   AdvColumnGrid1->Cells[1][1] = site_ptr->SiteName;
   AdvColumnGrid1->Cells[1][2] = site_ptr->LatNorth;
   AdvColumnGrid1->Cells[1][3] = site_ptr->LatSouth;
   AdvColumnGrid1->Cells[1][4] = site_ptr->LongWest;
   AdvColumnGrid1->Cells[1][5] = site_ptr->LongEast;
   AdvColumnGrid1->Cells[1][6] = site_ptr->Country;
   AdvColumnGrid1->Cells[1][7] = site_ptr->State;
   AdvColumnGrid1->Cells[1][8] = site_ptr->County;
   AdvColumnGrid1->Cells[1][9] = site_ptr->AdminUnit;
   AdvColumnGrid1->Cells[1][10] = site_ptr->Altitude;
   AdvColumnGrid1->Cells[1][11] = site_ptr->Area;
   AdvColumnGrid1->Cells[1][12] = site_ptr->SiteDescription;
   AdvColumnGrid1->Cells[1][13] = site_ptr->Notes;
   // site_ptr->LakeParams[0].Name

   if (site_ptr->LakeParams.size() > 0) {
	 AdvColumnGrid1->RowCount += site_ptr->LakeParams.size();
	 for (unsigned int i=0, row=14; i<site_ptr->LakeParams.size(); i++, row++) {
	   AdvColumnGrid1->Cells[0][row] = site_ptr->LakeParams[i].Name;
	   AdvColumnGrid1->Cells[1][row] = site_ptr->LakeParams[i].Value;
	   }
	 }

   for (int row=1; row<=11; row++) {
	 AdvColumnGrid1->ReadOnly[1][row] = true;
	 AdvColumnGrid1->ReadOnly[3][row] = true;
	 }

   TiliaBmp = new Graphics::TBitmap;
   cxImageList2->GetBitmap(0,TiliaBmp);
   AdvColumnGrid1->AddBitmap(1,0,TiliaBmp,true,haBeforeText,TCellVAlign::vaCenter);
   AdvColumnGrid1->FontColors[1][0] = clNavy;

   RatBmp = new Graphics::TBitmap;
   cxImageList2->GetBitmap(1,RatBmp);
   AdvColumnGrid1->AddBitmap(3,0,RatBmp,true,haBeforeText,TCellVAlign::vaCenter);
   AdvColumnGrid1->FontColors[3][0] = clNavy;

   if (update_tilia) {
	 cxButton2->Width = 88;
	 cxButton2->Caption = L"Continue";
	 cxButton2->OptionsImage->ImageIndex = 3;
	 cxButton2->OptionsImage->Layout = Buttons::blGlyphRight;
	 }
   int ButtonWidth = cxButton1->Width + cxButton2->Width;
   FlowPanel1->Left = (Panel2->Width - ButtonWidth)/2;
}
//---------------------------------------------------------------------------

void __fastcall TUpdateNeotomaSiteForm::FormActivate(TObject *Sender)
{
   if (activated) return;

   if (!GetNeotomaSiteData())
	 return;

   if (AdvColumnGrid1->RowCount > 14) {
	 for (int row=14; row<=AdvColumnGrid1->RowCount ; row++) {
	   AdvColumnGrid1->ReadOnly[1][row] = true;
	   AdvColumnGrid1->ReadOnly[3][row] = true;
	   }
	 }

   if (ModalResult == mrClose)
	 PostMessage(Handle, WM_CLOSE, 0, 0);
}
//---------------------------------------------------------------------------

void __fastcall TUpdateNeotomaSiteForm::FormClose(TObject *Sender, TCloseAction &Action)
{
   delete TiliaBmp;
   delete RatBmp;
   if (ArrowBmp != NULL)
     delete ArrowBmp;
}
//---------------------------------------------------------------------------

void __fastcall TUpdateNeotomaSiteForm::AdvColumnGrid1GetEditorType(TObject *Sender,
		  int ACol, int ARow, TEditorType &AEditor)
{
   switch (ACol) {
	 case 1:
	   switch (ARow) {
		 case 12:
		 case 13:
		   AEditor = edMemoDropDown;
		   break;
		 default:
		   AEditor = edNormal;
		   break;
		 }
	   break;
	 case 3:
	   switch (ARow) {
		 case 12:
		 case 13:
		   AEditor = edMemoDropDown;
		   break;
		 default:
		   AEditor = edNormal;
		   break;
		 }
	   break;
	 default:
	   AEditor = edNormal;
	   break;
	 }
}
//---------------------------------------------------------------------------

bool TUpdateNeotomaSiteForm::GetNeotomaSiteData(void)
{
   UnicodeString ConnectError = L"Error connecting to Neotoma server.";

   bool success = true;
   Screen->Cursor = crHourGlass;
   try {
	   // Site data
	   NeotomaSiteMetaDataBySiteID SiteData(ipsJSONS1, TcpClient1);
	   SiteData.AddParam(L"SITEID", site_ptr->NeotomaSiteID);
	   StatusBar1->SimpleText = SiteData.WebServiceName();
	   if (SiteData.Execute()) {
		 if (SiteData.Size() > 0) {
		   AdvColumnGrid1->Cells[3][1] = SiteData.Items[0].SiteName;
		   AdvColumnGrid1->Cells[3][2] = SiteData.Items[0].LatitudeNorth;
		   AdvColumnGrid1->Cells[3][3] = SiteData.Items[0].LatitudeSouth;
		   AdvColumnGrid1->Cells[3][4] = SiteData.Items[0].LongitudeWest;
		   AdvColumnGrid1->Cells[3][5] = SiteData.Items[0].LongitudeEast;
		   AdvColumnGrid1->Cells[3][10] = VarToStr(SiteData.Items[0].Altitude);
		   AdvColumnGrid1->Cells[3][11] = VarToStr(SiteData.Items[0].Area);
		   AdvColumnGrid1->Cells[3][12] = SiteData.Items[0].SiteDescription;
		   AdvColumnGrid1->Cells[3][13] = SiteData.Items[0].Notes;
		   }
		 }
	   else {
		 return (success = false);
		 }

	   // GeoPolitical data
	   GeoPolID[NTM_COUNTRY] = -1;
	   GeoPolID[NTM_STATE] = -1;
	   GeoPolID[NTM_COUNTY] = -1;
	   GeoPolID[NTM_ADMINUNIT] = -1;
	   GeoPolUnitsBySiteID SiteGeoPolUnits(ipsJSONS1, TcpClient1);
	   SiteGeoPolUnits.AddParam(L"SITEID", site_ptr->NeotomaSiteID);
	   StatusBar1->SimpleText = SiteGeoPolUnits.WebServiceName();
	   if (SiteGeoPolUnits.Execute()) {
		 if (SiteGeoPolUnits.Size() > 0) {
		   for (unsigned int i=0; i<SiteGeoPolUnits.Size(); i++) {
			 switch (SiteGeoPolUnits.Items[i].Rank) {
			   case 1:
				 AdvColumnGrid1->Cells[3][6] = SiteGeoPolUnits.Items[i].GeoPoliticalName;
				 GeoPolID[NTM_COUNTRY] = SiteGeoPolUnits.Items[i].GeoPoliticalID;
				 break;
			   case 2:
				 AdvColumnGrid1->Cells[3][7] = SiteGeoPolUnits.Items[i].GeoPoliticalName;
				 GeoPolID[NTM_STATE] = SiteGeoPolUnits.Items[i].GeoPoliticalID;
				 break;
			   case 3:
				 AdvColumnGrid1->Cells[3][8] = SiteGeoPolUnits.Items[i].GeoPoliticalName;
				 GeoPolID[NTM_COUNTY] = SiteGeoPolUnits.Items[i].GeoPoliticalID;
				 break;
			   case 4:
				 AdvColumnGrid1->Cells[3][9] = SiteGeoPolUnits.Items[i].GeoPoliticalName;
				 GeoPolID[NTM_ADMINUNIT] = SiteGeoPolUnits.Items[i].GeoPoliticalID;
				 break;
			   }
			 }
		   }
		 }
	   else
		 return (success = false);

	   // get lake parameters
	   NeotomaSiteLakeParams LakeParams(ipsJSONS1, TcpClient1);
	   LakeParams.AddParam(L"SITEID", site_ptr->NeotomaSiteID);
	   StatusBar1->SimpleText = LakeParams.WebServiceName();
	   if (LakeParams.Execute()) {
		 if (LakeParams.Size() > 0) {
		   for (unsigned int i=0; i<LakeParams.Size(); i++) {
			 LAKEPARAM LakeParam;
			 LakeParam.Name = LakeParams.Items[i].first;
			 LakeParam.Value = LakeParams.Items[i].second;
			 bool found = false;
			 for (int row=14; row<AdvColumnGrid1->RowCount; row++) {
			   if (SameText(AdvColumnGrid1->Cells[0][row], LakeParam.Name)) {
				 AdvColumnGrid1->Cells[3][row] = LakeParam.Value;
				 found = true;
				 break;
				 }
			   }
			 if (!found) {
			   int row = AdvColumnGrid1->RowCount;
			   AdvColumnGrid1->RowCount = row + 1;
			   AdvColumnGrid1->Cells[0][row] = LakeParam.Name;
			   AdvColumnGrid1->Cells[3][row] = LakeParam.Value;
			   }
			 }
		   }
		 }
	   else
		 return (success = false);

	   bool data_same = true;
	   for (int row=1; row<AdvColumnGrid1->RowCount; row++) {
		 if (AdvColumnGrid1->Cells[1][row] != AdvColumnGrid1->Cells[3][row]) {
		   AdvColumnGrid1->Colors[1][row] = (TColor)0x006EBBFF;
		   AdvColumnGrid1->Colors[3][row] = (TColor)0x006EBBFF;
		   if (update_tilia) {
			 ArrowBmp = new Graphics::TBitmap;
			 cxImageList1->GetBitmap(0,ArrowBmp);
			 AdvColumnGrid1->AddBitButton(2,row,16,9,L"",ArrowBmp,haFull,vaFull);
             }
		   data_same = false;
		   }
		 }

	   if (data_same) {
		 MessageDlg(L"Site metadata in Tilia and Neotoma are the same. No need to update.",
		   mtInformation, TMsgDlgButtons() << mbOK, 0);
		 ModalResult = mrClose;
		 }
	   else
		 cxButton1->Enabled = true;
	   }
   __finally {
	   StatusBar1->SimpleText = L"";
	   Screen->Cursor = crDefault;
	   if (!success)
		 MessageDlg(ConnectError, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   }

   return success;
}
//---------------------------------------------------------------------------

void __fastcall TUpdateNeotomaSiteForm::AdvColumnGrid1CellValidate(TObject *Sender,
          int ACol, int ARow, UnicodeString &Value, bool &Valid)
{
   Valid = false;
}
//---------------------------------------------------------------------------

void __fastcall TUpdateNeotomaSiteForm::AdvColumnGrid1ButtonClick(TObject *Sender,
		  int ACol, int ARow)
{
   AdvColumnGrid1->Cells[1][ARow] = AdvColumnGrid1->Cells[3][ARow];
   AdvColumnGrid1->Colors[1][ARow] = clWindow;
   AdvColumnGrid1->Colors[3][ARow] = clWindow;
   AdvColumnGrid1->RemoveBitButton(2,ARow);

   map<UnicodeString, int> MDRows;
   map<UnicodeString, int> LakeMDRows;

   int SiteCol = 0;
   int SiteRow = TSSForm->FindRowMD(SITE_NAME);
   if (SiteRow > 0) {
	 int ColCount = TSSForm->AbsContentColCount(TSSForm->ProfGrid1);
	 int StartCol = TSSForm->AbsHeaderColCount(TSSForm->ProfGrid1);
	 for (int col=StartCol; col<=ColCount; col++) {
	   if (TSSForm->ProfGrid1->AbsoluteCells[col][SiteRow]->CellObject != NULL) {
		 CELLOBJECT* CellObject = (CELLOBJECT*)TSSForm->ProfGrid1->AbsoluteCells[col][SiteRow]->CellObject;
		 if (site_ptr == (SITE*)CellObject->Object) {
		   SiteCol = col;
		   TSSForm->GetMetaDataRows(L"#SITE.", MDRows);
		   TSSForm->GetMetaDataRows(L"#LAKE.", LakeMDRows);
		   break;
		   }
		 }
	   }
	 }

   bool SSSite = (SiteCol > 0 && SiteRow > 0);

   LAKEPARAM LakeParam;
   switch (ARow) {
	 case 1:
	   site_ptr->SiteName = AdvColumnGrid1->Cells[3][1];
	   UpdateSSMetadata(SSSite, MDRows, L"#Site.Name", L"Site Name", SiteCol, site_ptr->SiteName);
	   break;
	 case 2:
	   site_ptr->LatNorth = AdvColumnGrid1->Cells[3][2].ToDouble();
	   UpdateSSMetadata(SSSite, MDRows, L"#Site.LatN", L"North Latitude", SiteCol, site_ptr->LatNorth);
	   break;
	 case 3:
	   site_ptr->LatSouth = AdvColumnGrid1->Cells[3][3].ToDouble();
	   UpdateSSMetadata(SSSite, MDRows, L"#Site.LatS", L"South Latitude", SiteCol, site_ptr->LatSouth);
	   break;
	 case 4:
	   site_ptr->LongWest = AdvColumnGrid1->Cells[3][4].ToDouble();
	   UpdateSSMetadata(SSSite, MDRows, L"#Site.LongW", L"West Longitude", SiteCol, site_ptr->LongWest);
	   break;
	 case 5:
	   site_ptr->LongEast = AdvColumnGrid1->Cells[3][5].ToDouble();
	   UpdateSSMetadata(SSSite, MDRows, L"#Site.LongE", L"East Longitude", SiteCol, site_ptr->LongEast);
	   break;
	 case 6:
	   site_ptr->Country = AdvColumnGrid1->Cells[3][6];
	   UpdateSSMetadata(SSSite, MDRows, L"#Site.GeoPol1", L"First Geopolitical Division", SiteCol, site_ptr->Country);
	   break;
	 case 7:
	   site_ptr->State = AdvColumnGrid1->Cells[3][7];
	   UpdateSSMetadata(SSSite, MDRows, L"#Site.GeoPol2", L"Second Geopolitical Division", SiteCol, site_ptr->State);
	   break;
	 case 8:
	   site_ptr->County = AdvColumnGrid1->Cells[3][8];
	   UpdateSSMetadata(SSSite, MDRows, L"#Site.GeoPol3", L"Third Geopolitical Division", SiteCol, site_ptr->County);
	   break;
	 case 9:
	   site_ptr->AdminUnit = AdvColumnGrid1->Cells[3][9];
	   UpdateSSMetadata(SSSite, MDRows, L"#Site.Admin", L"Administrative Unit", SiteCol, site_ptr->AdminUnit);
	   break;
	 case 10:
	   site_ptr->Altitude = AdvColumnGrid1->Cells[3][10].ToDouble();
	   UpdateSSMetadata(SSSite, MDRows, L"#Site.Altitude", L"Altitude (m)", SiteCol, site_ptr->Altitude);
	   break;
	 case 11:
	   site_ptr->Area = AdvColumnGrid1->Cells[3][11].ToDouble();
	   UpdateSSMetadata(SSSite, MDRows, L"#Site.Area",  L"Area of Site (ha)", SiteCol, site_ptr->Area);
	   break;
	 case 12:
	   site_ptr->SiteDescription = AdvColumnGrid1->Cells[3][12];
	   UpdateSSMetadata(SSSite, MDRows, L"#Site.Desc", L"Site Description", SiteCol, site_ptr->SiteDescription);
	   break;
	 case 13:
	   site_ptr->Notes = AdvColumnGrid1->Cells[3][13];
	   UpdateSSMetadata(SSSite, MDRows, L"#Site.Notes", L"Site Notes", SiteCol, site_ptr->Notes);
	   break;
	 default:  // lake parameters
	   LakeParam.Name = AdvColumnGrid1->Cells[0][ARow];
	   LakeParam.Value = AdvColumnGrid1->Cells[3][ARow].ToDouble();
	   bool found = false;
	   list<LAKEPARAMETER>::iterator it;
	   for (it = TSSForm->LakeChar.begin(); it != TSSForm->LakeChar.end(); it++) {
		 if (SameText(LakeParam.Name, it->Name)) {
		   site_ptr->LakeParams.push_back(LakeParam);
		   UpdateSSLakeMetadata(SSSite, MDRows, LakeMDRows, LakeParam, SiteCol);
		   found = true;
		   break;
		   }
		 }
	   if (!found)
		 site_ptr->LakeParams.push_back(LakeParam);
	   break;
	 }

   bool has_buttons = false;
   for (int row=1; row<AdvColumnGrid1->RowCount; row++) {
	 if (AdvColumnGrid1->HasButton(2,row)) {
	   has_buttons = true;
	   break;
	   }
	 }
   if (!has_buttons) {
	 cxButton1->Enabled = false;
	 MessageDlg(L"Site metadata in Tilia and Neotoma are now the same. No need to update.",
	   mtInformation, TMsgDlgButtons() << mbOK, 0);
	 ModalResult = mrClose;
	 Close();
	 }
}
//---------------------------------------------------------------------------

void TUpdateNeotomaSiteForm::UpdateSSMetadata(bool ssmd, map<UnicodeString, int>& MDRows,
	UnicodeString Code, UnicodeString Name, int ACol, UnicodeString& Value)
{
   // int ARow;
   UnicodeString UCode = Code.UpperCase();
   int pos = UCode.Pos(L".");
   UCode.Delete(1,pos);

   if (ssmd) {
	 if (MDRows.find(UCode) == MDRows.end())   // get last row of SS params from MDRows
	   MDRows[UCode] = InsertNewSSMetaDataRow(MDRows, Code, Name);
	 if (MDRows.find(UCode) != MDRows.end()) {
	   int ARow = MDRows[UCode];
	   TSSForm->ProfGrid1->AbsoluteCells[ACol][ARow]->Value = Value;
	   }
	 }
}
//---------------------------------------------------------------------------

void TUpdateNeotomaSiteForm::UpdateSSMetadata(bool ssmd, map<UnicodeString, int>& MDRows,
	UnicodeString Code, UnicodeString Name, int ACol, double Value)
{
   UnicodeString UCode = Code.UpperCase();
   int pos = UCode.Pos(L".");
   UCode.Delete(1,pos);

   if (ssmd) {
	 if (MDRows.find(UCode) == MDRows.end())
	   MDRows[UCode] = InsertNewSSMetaDataRow(MDRows, Code, Name);
	 if (MDRows.find(UCode) != MDRows.end()) {
	   int ARow = MDRows[UCode];
	   TSSForm->ProfGrid1->AbsoluteCells[ACol][ARow]->Value = Value;
	   }
	 }
}
//---------------------------------------------------------------------------

void TUpdateNeotomaSiteForm::UpdateSSLakeMetadata(bool ssmd, map<UnicodeString, int>& MDRows,
	map<UnicodeString, int>& LakeMDRows, LAKEPARAM& LakeParam, int ACol)
{
   int ARow;
   UnicodeString Code, UCode;

   if (ssmd) {
	 list<LAKEPARAMETER>::iterator it;
	 for (it = TSSForm->LakeChar.begin(); it != TSSForm->LakeChar.end(); it++) {
	   if (SameText(LakeParam.Name, it->Name)) {
		 Code = it->Code;
		 UCode = Code.UpperCase();
		 break;
		 }
	   }

	 if (LakeMDRows.find(UCode) == LakeMDRows.end()) {
	   if (LakeMDRows.size() > 0)  // get last row of SS lake params
		 ARow = InsertNewSSMetaDataRow(LakeMDRows, L"#Lake." + Code, LakeParam.Name);
	   else   // get last row of SS site params
		 ARow = InsertNewSSMetaDataRow(MDRows, L"#Lake." + Code, LakeParam.Name);
	   LakeMDRows[UCode] = ARow;
	   }

	 if (LakeMDRows.find(UCode) != LakeMDRows.end()) {
	   ARow = LakeMDRows[UCode];
	   TSSForm->ProfGrid1->AbsoluteCells[ACol][ARow]->Value = LakeParam.Value;
	   }
	 }
}
//---------------------------------------------------------------------------

int TUpdateNeotomaSiteForm::InsertNewSSMetaDataRow(map<UnicodeString, int>& mdrows,
	UnicodeString Code, UnicodeString Name)
{
   map<UnicodeString, int>::iterator itr;
   map<UnicodeString, int>::iterator begin = mdrows.begin();
   int lastrow = begin->second;
   begin++;
   for (itr = begin; itr != mdrows.end(); itr++) {
	 if (itr->second > lastrow)
	   lastrow = itr->second;
	 }
   int ARow = lastrow + 1;

   // insert new row above last row from above
   TSSForm->ProfGrid1->DisableControls();
   TSSForm->ProfGrid1->SpreadsheetEnabled = false;
   TSSForm->ProfGrid1->InsertRow(ARow);
   // enter new param
   TSSForm->ProfGrid1->AbsoluteCells[1][ARow]->Value = Code;
   TSSForm->ProfGrid1->AbsoluteCells[2][ARow]->Value = Name;
   TSSForm->ProfGrid1->SpreadsheetEnabled = true;
   TSSForm->ProfGrid1->EnableControls();
   TSSForm->SpreadSheetChanged = true;

   if (TUploadForm != NULL) {
	 for (unsigned int i = 0; i < TUploadForm->SSVarList.size(); i++) {
	   if (TUploadForm->SSVarList[i].row >= ARow); {
		 TUploadForm->SSVarList[i].row++;
		 }
	   }
	 map<int,NEOTOMAVARIABLE> TempNeotomaVariables = TUploadForm->NeotomaVariables;
	 TUploadForm->NeotomaVariables.clear();
	 map<int,NEOTOMAVARIABLE>::iterator itr;
	 for (itr = TempNeotomaVariables.begin(); itr != TempNeotomaVariables.end(); itr++) {
	   int row = itr->first;
	   if (row >= ARow)
		 row++;
	   TUploadForm->NeotomaVariables[row] = itr->second;
	   }
	 }

   return ARow;
}
//---------------------------------------------------------------------------

// update Neotoma site metadata
void __fastcall TUpdateNeotomaSiteForm::cxButton1Click(TObject *Sender)
{
   UnicodeString msg = L"Update site metadata in Neotoma with data from the Tilia column?";
   if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) != mrYes)
	 return;

   NeotomaSiteValidationForm = new TNeotomaSiteValidationForm(site_ptr, AdvColumnGrid1, GeoPolID, TSSForm);
   NeotomaSiteValidationForm->ShowModal();
   delete NeotomaSiteValidationForm;

   ModalResult = mrOk;
}

//---------------------------------------------------------------------------

void __fastcall TUpdateNeotomaSiteForm::cxButton2Click(TObject *Sender)
{
   return;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

__fastcall TUpdateNeotomaCollUnitForm::TUpdateNeotomaCollUnitForm(SITE* sptr,
	vector<COLLECTION>::pointer cptr, bool update, TComponent* Owner)
	: TUpdateNeotomaSiteForm(sptr, update, Owner)
{
   TSSForm = (TTilSpreadSheetForm*)Owner;
   TUploadForm = NULL;
   coll_ptr = cptr;
   activated = false;
   update_tilia = update;
   ArrowBmp = NULL;
   Caption = L"Update Collection Unit Metadata";
};
//---------------------------------------------------------------------------

__fastcall TUpdateNeotomaCollUnitForm::TUpdateNeotomaCollUnitForm(SITE* sptr,
	vector<COLLECTION>::pointer cptr, bool update, TComponent* Parent, TComponent* Owner)
	: TUpdateNeotomaSiteForm(sptr, update, Parent, Owner)
{
   TSSForm = (TTilSpreadSheetForm*)Parent;
   TUploadForm = (TNeotomaUploadForm*)Owner;
   coll_ptr = cptr;
   activated = false;
   update_tilia = update;
   ArrowBmp = NULL;
   Caption = L"Update Collection Unit Metadata";
};
//---------------------------------------------------------------------------

void __fastcall TUpdateNeotomaCollUnitForm::FormCreate(TObject *Sender)
{
   AdvColumnGrid1->RowCount = 18;
   AdvColumnGrid1->Cells[0][1] = L"Handle";
   AdvColumnGrid1->Cells[0][2] = L"Collection Unit Type";
   AdvColumnGrid1->Cells[0][3] = L"Collection Unit Name";
   AdvColumnGrid1->Cells[0][4] = L"Collection Device";
   AdvColumnGrid1->Cells[0][5] = L"Collectors";
   AdvColumnGrid1->Cells[0][6] = L"Location in Site";
   AdvColumnGrid1->Cells[0][7] = L"Date Collected";
   AdvColumnGrid1->Cells[0][8] = L"Depositional Environment";
   AdvColumnGrid1->Cells[0][9] = L"GPS Latitude";
   AdvColumnGrid1->Cells[0][10] = L"GPS Longitude";
   AdvColumnGrid1->Cells[0][11] = L"GPS Error";
   AdvColumnGrid1->Cells[0][12] = L"GPS Altitude";
   AdvColumnGrid1->Cells[0][13] = L"Substrate";
   AdvColumnGrid1->Cells[0][14] = L"Slope Angle";
   AdvColumnGrid1->Cells[0][15] = L"Slope Aspect";
   AdvColumnGrid1->Cells[0][16] = L"Water Depth";
   AdvColumnGrid1->Cells[0][17] = L"Collection Unit Notes";

   AdvColumnGrid1->Cells[1][1] = coll_ptr->Handle;
   AdvColumnGrid1->Cells[1][2] = coll_ptr->CollectionType;
   AdvColumnGrid1->Cells[1][3] = coll_ptr->CollectionName;
   AdvColumnGrid1->Cells[1][4] = coll_ptr->CollectionDevice;
   UnicodeString Collectors;
   set<UnicodeString> CollectorSet;
   for (unsigned int i=0; i<coll_ptr->Collectors.size(); i++)
	 CollectorSet.insert(coll_ptr->Collectors[i]->ShortContactName);
   for (set<UnicodeString>::iterator itr = CollectorSet.begin(); itr != CollectorSet.end(); itr++) {
	 if (itr != CollectorSet.begin()) Collectors += L";";
	 Collectors += *itr;
	 }
   AdvColumnGrid1->Cells[1][5] = Collectors;
   AdvColumnGrid1->Cells[1][6] = coll_ptr->Location;
   AdvColumnGrid1->Cells[1][7] = VarToStr(coll_ptr->CollDate);
   AdvColumnGrid1->Cells[1][8] = coll_ptr->DepEnv;
   AdvColumnGrid1->Cells[1][9] = VarToStr(coll_ptr->GPSLat);
   AdvColumnGrid1->Cells[1][10] = VarToStr(coll_ptr->GPSLong);
   AdvColumnGrid1->Cells[1][11] = VarToStr(coll_ptr->GPSError);
   AdvColumnGrid1->Cells[1][12] = VarToStr(coll_ptr->GPSAltitude);
   AdvColumnGrid1->Cells[1][13] = coll_ptr->Substrate;
   AdvColumnGrid1->Cells[1][14] = VarToStr(coll_ptr->SlopeAngle);
   AdvColumnGrid1->Cells[1][15] = VarToStr(coll_ptr->SlopeAspect);
   AdvColumnGrid1->Cells[1][16] = VarToStr(coll_ptr->WaterDepth);
   AdvColumnGrid1->Cells[1][17] = coll_ptr->Notes;

   for (int row=1; row<=17; row++) {
	 AdvColumnGrid1->ReadOnly[1][row] = true;
	 AdvColumnGrid1->ReadOnly[3][row] = true;
	 }

   TiliaBmp = new Graphics::TBitmap;
   cxImageList2->GetBitmap(0,TiliaBmp);
   AdvColumnGrid1->AddBitmap(1,0,TiliaBmp,true,haBeforeText,TCellVAlign::vaCenter);
   AdvColumnGrid1->FontColors[1][0] = clNavy;

   RatBmp = new Graphics::TBitmap;
   cxImageList2->GetBitmap(1,RatBmp);
   AdvColumnGrid1->AddBitmap(3,0,RatBmp,true,haBeforeText,TCellVAlign::vaCenter);
   AdvColumnGrid1->FontColors[3][0] = clNavy;

   if (update_tilia) {
	 cxButton2->Width = 88;
	 cxButton2->Caption = L"Continue";
	 cxButton2->OptionsImage->ImageIndex = 3;
	 cxButton2->OptionsImage->Layout = Buttons::blGlyphRight;
	 }
   int ButtonWidth = cxButton1->Width + cxButton2->Width;
   FlowPanel1->Left = (Panel2->Width - ButtonWidth)/2;
}
//---------------------------------------------------------------------------

void __fastcall TUpdateNeotomaCollUnitForm::FormActivate(TObject *Sender)
{
   if (activated) return;

   if (!GetNeotomaCollUnitData())
	 return;

   if (ModalResult == mrClose)
	 PostMessage(Handle, WM_CLOSE, 0, 0);
}
//---------------------------------------------------------------------------

void __fastcall TUpdateNeotomaCollUnitForm::AdvColumnGrid1GetEditorType(TObject *Sender,
		  int ACol, int ARow, TEditorType &AEditor)
{
   switch (ACol) {
	 case 1:
	   switch (ARow) {
		 case 6:
		 case 17:
		   AEditor = edMemoDropDown;
		   break;
		 default:
		   AEditor = edNormal;
		   break;
		 }
	   break;
	 case 3:
	   switch (ARow) {
		 case 6:
		 case 17:
		   AEditor = edMemoDropDown;
		   break;
		 default:
		   AEditor = edNormal;
		   break;
		 }
	   break;
	 default:
	   AEditor = edNormal;
	   break;
	 }
}
//---------------------------------------------------------------------------

bool TUpdateNeotomaCollUnitForm::GetNeotomaCollUnitData(void)
{
   UnicodeString ConnectError = L"Error connecting to Neotoma server.";

   bool success = true;
   Screen->Cursor = crHourGlass;
   try {
	   // Collection unit data
	   NeotomaCollUnitByID CollUnit(ipsJSONS1, TcpClient1);
	   CollUnit.AddParam(L"COLLECTIONUNITID", coll_ptr->NeotomaCollUnitID);
	   StatusBar1->SimpleText = CollUnit.WebServiceName();
	   if (CollUnit.Execute()) {
		 if (CollUnit.Size() > 0) {
		   AdvColumnGrid1->Cells[3][1] = CollUnit.Items[0].Handle;

		   if (update_tilia)
			 coll_ptr->NeotomaHandle = CollUnit.Items[0].Handle;

		   // Collection type
		   int CollTypeID = CollUnit.Items[0].CollTypeID;
		   if (CollTypeID > -1) {
			 NeotomaCollectionTypeByID CollUnitType(ipsJSONS1, TcpClient1);
			 CollUnitType.AddParam(L"COLLTYPEID", CollTypeID);
			 StatusBar1->SimpleText = CollUnitType.WebServiceName();
			 if (CollUnitType.Execute()) {
			   if (CollUnitType.Items.count(CollTypeID) == 1)
				 AdvColumnGrid1->Cells[3][2] = CollUnitType.Items[CollTypeID];
			   }
			 else
			   return (success = false);
			 }

		   AdvColumnGrid1->Cells[3][3] = CollUnit.Items[0].CollUnitName;
		   AdvColumnGrid1->Cells[3][4] = CollUnit.Items[0].CollDevice;

		   // Collectors
		   NeotomaCollector Collectors(ipsJSONS1, TcpClient1);
		   Collectors.AddParam(L"COLLECTIONUNITID", coll_ptr->NeotomaCollUnitID);
		   StatusBar1->SimpleText = Collectors.WebServiceName();
		   if (Collectors.Execute()) {
			 if (Collectors.Size() > 0) {
			   NtmCollectors = Collectors.Items;
			   set<UnicodeString> CollectorSet;
			   for (unsigned int i=0; i<Collectors.Size(); i++) {
				 UnicodeString Collector;
				 Collector = Collectors.Items[i].FamilyName + L", " + Collectors.Items[i].LeadingInitials;
				 CollectorSet.insert(Collector);
				 }
			   UnicodeString Collectors;
			   set<UnicodeString>::iterator itr;
			   for (itr = CollectorSet.begin(); itr != CollectorSet.end(); itr++) {
				 if (itr != CollectorSet.begin()) Collectors += L";";
				 Collectors += *itr;
				 }
			   AdvColumnGrid1->Cells[3][5] = Collectors;
			   }
			 }
		   else
			 return (success = false);

		   AdvColumnGrid1->Cells[3][6] = CollUnit.Items[0].Location;
		   AdvColumnGrid1->Cells[3][7] = VarToStr(CollUnit.Items[0].CollDate);

		   // DepEnvt type
		   int DepEnvtID = CollUnit.Items[0].DepEnvtID;
		   if (DepEnvtID > -1) {
			 NeotomaDepEnvtTypeByID DepEnvtType(ipsJSONS1, TcpClient1);
			 DepEnvtType.AddParam(L"DEPENVTID", DepEnvtID);
			 StatusBar1->SimpleText = DepEnvtType.WebServiceName();
			 if (DepEnvtType.Execute()) {
			   if (DepEnvtType.Size() > 0)
				 AdvColumnGrid1->Cells[3][8] = DepEnvtType.Items[0].DepEnvt;
			   }
			 else
			   return (success = false);
			 }

		   AdvColumnGrid1->Cells[3][9] = VarToStr(CollUnit.Items[0].GPSLatitude);
		   AdvColumnGrid1->Cells[3][10] = VarToStr(CollUnit.Items[0].GPSLongitude);
		   AdvColumnGrid1->Cells[3][11] = VarToStr(CollUnit.Items[0].GPSError);
		   AdvColumnGrid1->Cells[3][12] = VarToStr(CollUnit.Items[0].GPSAltitude);

		   //AdvColumnGrid1->Cells[3][13] = CollUnit.Items[0].  SubstrateID

		   // Substrate
		   int RockTypeID = CollUnit.Items[0].SubstrateID;
		   if (RockTypeID > -1) {
			 NeotomaRockTypeByID RockType(ipsJSONS1, TcpClient1);
			 RockType.AddParam(L"ROCKTYPEID", RockTypeID);
			 StatusBar1->SimpleText = RockType.WebServiceName();
			 if (RockType.Execute()) {
			   if (RockType.Size() > 0)
				 AdvColumnGrid1->Cells[3][13] = RockType.Items[0].RockType;
			   }
			 else
			   return (success = false);
			 }

		   AdvColumnGrid1->Cells[3][14] = VarToStr(CollUnit.Items[0].SlopeAngle);
		   AdvColumnGrid1->Cells[3][15] = VarToStr(CollUnit.Items[0].SlopeAspect);
		   AdvColumnGrid1->Cells[3][16] = VarToStr(CollUnit.Items[0].WaterDepth);
		   AdvColumnGrid1->Cells[3][17] = CollUnit.Items[0].Notes;

		   }
		 }
	   else
		 return (success = false);

	   bool data_same = true;
	   for (int row=1; row<AdvColumnGrid1->RowCount; row++) {
		 if (AdvColumnGrid1->Cells[1][row] != AdvColumnGrid1->Cells[3][row]) {
		   AdvColumnGrid1->Colors[1][row] = (TColor)0x006EBBFF;
		   AdvColumnGrid1->Colors[3][row] = (TColor)0x006EBBFF;
		   if (update_tilia) {
			 ArrowBmp = new Graphics::TBitmap;
			 cxImageList1->GetBitmap(0,ArrowBmp);
			 AdvColumnGrid1->AddBitButton(2,row,16,9,L"",ArrowBmp,haFull,vaFull);
			 }
		   data_same = false;
		   }
		 }

	   if (data_same) {
		 MessageDlg(L"Collection unit metadata in Tilia and Neotoma are the same. No need to update.",
		   mtInformation, TMsgDlgButtons() << mbOK, 0);
		 ModalResult = mrClose;
		 // Close();
		 }
	   else
		 cxButton1->Enabled = true;
	   }
   __finally {
	   StatusBar1->SimpleText = L"";
	   Screen->Cursor = crDefault;
	   if (!success)
		 MessageDlg(ConnectError, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   }

   return success;
}
//---------------------------------------------------------------------------

void __fastcall TUpdateNeotomaCollUnitForm::AdvColumnGrid1ButtonClick(TObject *Sender,
		  int ACol, int ARow)
{
   AdvColumnGrid1->Cells[1][ARow] = AdvColumnGrid1->Cells[3][ARow];
   AdvColumnGrid1->Colors[1][ARow] = clWindow;
   AdvColumnGrid1->Colors[3][ARow] = clWindow;
   AdvColumnGrid1->RemoveBitButton(2,ARow);

   map<UnicodeString, int> MDRows;

   int CollCol = 0;
   int SiteCol = 0;
   int SiteRow = TSSForm->FindRowMD(SITE_NAME);
   int HandleRow = TSSForm->FindRowMD(COLL_UNIT_HANDLE);
   if (SiteRow > 0) {
	 int ColCount = TSSForm->AbsContentColCount(TSSForm->ProfGrid1);
	 int StartCol = TSSForm->AbsHeaderColCount(TSSForm->ProfGrid1);
	 for (int col=StartCol; col<=ColCount; col++) {
	   if (TSSForm->ProfGrid1->AbsoluteCells[col][SiteRow]->CellObject != NULL) {
		 CELLOBJECT* CellObject = (CELLOBJECT*)TSSForm->ProfGrid1->AbsoluteCells[col][SiteRow]->CellObject;
		 SITE* site_ptr = (SITE*)CellObject->Object;
		 for (unsigned int i=0; i<site_ptr->CollUnits.size(); i++) {
		   vector<COLLECTION>::pointer ptr = &site_ptr->CollUnits[i];
		   if (ptr == coll_ptr) {
			 CollCol = col;
			 TSSForm->GetMetaDataRows(L"#COLL.", MDRows);
			 break;
			 }
		   }
		 if (CollCol > 0) break;
		 }
	   }
	 }

   bool SSColl = (CollCol > 0 && HandleRow > 0);

   switch (ARow) {
	 case 1:
	   coll_ptr->Handle = AdvColumnGrid1->Cells[3][1];
	   break;
	 case 2:
	   coll_ptr->CollectionType = AdvColumnGrid1->Cells[3][2];
	   UpdateSSMetadata(SSColl, MDRows, L"#Coll.Type", L"Collection Unit Type", CollCol, coll_ptr->CollectionType);
	   break;
	 case 3:
	   coll_ptr->CollectionName = AdvColumnGrid1->Cells[3][3];
	   break;
	 case 4:
	   coll_ptr->CollectionDevice = AdvColumnGrid1->Cells[3][4];
	   break;
	 case 5:
	   coll_ptr->Collectors.clear();
	   if (NtmCollectors.size() > 0) {
		 set<UnicodeString> Collectors;
		 set<UnicodeString>::iterator itr;
		 UnicodeString CollectorsText;
		 for (unsigned int i=0; i<NtmCollectors.size(); i++) {
		   CONTACT* Contact = TSSForm->GetNeotomaContact(NtmCollectors[i]);
		   coll_ptr->Collectors.push_back(Contact);
		   Collectors.insert(Contact->ShortContactName);
		   }
		 for (itr = Collectors.begin(); itr != Collectors.end(); itr++) {
		   if (!CollectorsText.IsEmpty())
			 CollectorsText += L";";
		   CollectorsText += *itr;
		   }
		 UpdateSSMetadata(SSColl, MDRows, L"#Coll.Contacts", L"Collectors", CollCol, CollectorsText);
		 if (MDRows.find(L"CONTACTS") != MDRows.end()) {
		   int row = MDRows[L"CONTACTS"];
		   CELLOBJECT* CellObject;
		   TProfGridCell *ACell = TSSForm->ProfGrid1->AbsoluteCells[CollCol][row];
		   if (ACell->CellObject == NULL) {
			 CellObject = new CELLOBJECT(CELLCONTACTS);
			 TSSForm->AddCellObject(ACell, CellObject);
			 }
		   else
			 CellObject = (CELLOBJECT*)ACell->CellObject;
		   TList* CellContacts = (TList*)CellObject->Object;
		   CellContacts->Clear();
		   for (unsigned int i = 0; i < coll_ptr->Collectors.size(); i++)
			 CellContacts->Add(coll_ptr->Collectors[i]);
		   }
		 }
	   break;
	 case 6:
	   coll_ptr->Location = AdvColumnGrid1->Cells[3][6];
	   break;
	 case 7:
	   coll_ptr->CollDate = StrToDate(AdvColumnGrid1->Cells[3][7]);
	   break;
	 case 8:
	   coll_ptr->DepEnv = AdvColumnGrid1->Cells[3][8];
	   break;
	 case 9:
	   coll_ptr->GPSLat = AdvColumnGrid1->Cells[3][9].ToDouble();
	   break;
	 case 10:
	   coll_ptr->GPSLong = AdvColumnGrid1->Cells[3][10].ToDouble();
	   break;
	 case 11:
	   coll_ptr->GPSError = AdvColumnGrid1->Cells[3][11].ToDouble();
	   break;
	 case 12:
	   coll_ptr->GPSAltitude = AdvColumnGrid1->Cells[3][12].ToDouble();
	   break;
	 case 13:
	   coll_ptr->Substrate = AdvColumnGrid1->Cells[3][13];
	   break;
	 case 14:
	   coll_ptr->SlopeAngle = AdvColumnGrid1->Cells[3][14].ToInt();
	   break;
	 case 15:
	   coll_ptr->SlopeAspect = AdvColumnGrid1->Cells[3][15].ToInt();
	   break;
	 case 16:
	   coll_ptr->WaterDepth = AdvColumnGrid1->Cells[3][16].ToDouble();
	   break;
	 case 17:
	   coll_ptr->Notes = AdvColumnGrid1->Cells[3][17];
	   break;
	 }

   bool has_buttons = false;
   for (int row=1; row<AdvColumnGrid1->RowCount; row++) {
	 if (AdvColumnGrid1->HasButton(2,row)) {
	   has_buttons = true;
	   break;
	   }
	 }
   if (!has_buttons) {
	 cxButton1->Enabled = false;
	 UnicodeString msg = L"Collection unit metadata in Tilia and Neotoma are now the same. No need to update.";
	 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
	 ModalResult = mrClose;
	 Close();
	 }
}
//---------------------------------------------------------------------------

void __fastcall TUpdateNeotomaCollUnitForm::cxButton2Click(TObject *Sender)
{
   ModalResult = mrClose;
   if (update_tilia) {
	 bool has_buttons = false;
	 for (int row=1; row<AdvColumnGrid1->RowCount; row++) {
	   if (AdvColumnGrid1->HasButton(2,row)) {
		 has_buttons = true;
		 break;
		 }
	   }
	 if (has_buttons) {
	   UnicodeString msg = L"Metadata items in Tilia form differ from those in Neotoma. Neotoma metadata will be retained.";
	   if (MessageDlg(msg, mtWarning, TMsgDlgButtons() << mbRetry << mbOK, 0) == mrRetry)
		 ModalResult = mrNone;
	   }
	 }
}
//---------------------------------------------------------------------------

// update Neotoma collection unit metadata
void __fastcall TUpdateNeotomaCollUnitForm::cxButton1Click(TObject *Sender)
{
   UnicodeString msg = L"Update collection unit metadata in Neotoma with data from the Tilia column?";
   if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) != mrYes)
	 return;

   NeotomaCollUnitValidationForm = new TNeotomaCollUnitValidationForm(coll_ptr, AdvColumnGrid1, TSSForm);
   NeotomaCollUnitValidationForm->ShowModal();
   delete NeotomaCollUnitValidationForm;

   ModalResult = mrOk;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

__fastcall TUpdateNeotomaDatasetForm::TUpdateNeotomaDatasetForm(SITE* sptr,
	DATASET* dptr, bool update, TComponent* Owner) :
	TUpdateNeotomaSiteForm(sptr, update, Owner)
{
   TSSForm = (TTilSpreadSheetForm*)Owner;
   dataset_ptr = dptr;
   activated = false;
   update_tilia = update;
   ArrowBmp = NULL;
   Caption = L"Update Dataset Metadata";
};
//---------------------------------------------------------------------------

void __fastcall TUpdateNeotomaDatasetForm::FormCreate(TObject *Sender)
{
   AdvColumnGrid1->RowCount = 8;
   AdvColumnGrid1->Cells[0][1] = L"Dataset Name";
   AdvColumnGrid1->Cells[0][2] = L"Investigators";
   AdvColumnGrid1->Cells[0][3] = L"Publications";
   AdvColumnGrid1->Cells[0][4] = L"Repository";
   AdvColumnGrid1->Cells[0][5] = L"Data Processors";
   AdvColumnGrid1->Cells[0][6] = L"Is Surface Sample";
   AdvColumnGrid1->Cells[0][7] = L"Dataset Notes";

   DatasetPubs = new TList;

   AdvColumnGrid1->Cells[1][1] = dataset_ptr->Name;

   UnicodeString Investigators;
   set<UnicodeString> InvestigatorSet;
   for (unsigned int i=0; i<dataset_ptr->Investigators.size(); i++)
	 InvestigatorSet.insert(dataset_ptr->Investigators[i]->ShortContactName);
   for (set<UnicodeString>::iterator itr = InvestigatorSet.begin(); itr != InvestigatorSet.end(); itr++) {
	 if (itr != InvestigatorSet.begin()) Investigators += L";";
	 Investigators += *itr;
	 }
   AdvColumnGrid1->Cells[1][2] = Investigators;

   UnicodeString Pubs;
   set<UnicodeString> PubSet;
   for (unsigned int i=0; i<dataset_ptr->Publications.size(); i++) {
	 UnicodeString pub = dataset_ptr->Publications[i]->GetShortCitation(false);
	 pub += L",";
	 pub += (dataset_ptr->Publications[i]->Primary) ? L"1" : L"0";
	 PubSet.insert(pub);
	 }
   for (set<UnicodeString>::iterator itr = PubSet.begin(); itr != PubSet.end(); itr++) {
	 if (itr != PubSet.begin()) Pubs += L";";
	 Pubs += *itr;
	 }
   AdvColumnGrid1->Cells[1][3] = Pubs;

   UnicodeString Repositories;
   for (unsigned int i=0; i<dataset_ptr->Repositories.size(); i++)
	 TilRepositories[dataset_ptr->Repositories[i].Acronym] = dataset_ptr->Repositories[i].SpecimenNotes;
   for (map<UnicodeString,UnicodeString>::iterator itr = TilRepositories.begin(); itr != TilRepositories.end(); itr++) {
	 if (itr != TilRepositories.begin())
	   Repositories += L";";
	 Repositories += itr->first;
	 }
   AdvColumnGrid1->Cells[1][4] = Repositories;

   UnicodeString Processors;
   set<UnicodeString> ProcessorSet;
   for (unsigned int i=0; i<dataset_ptr->Processors.size(); i++)
	 ProcessorSet.insert(dataset_ptr->Processors[i]->ShortContactName);
   for (set<UnicodeString>::iterator itr = ProcessorSet.begin(); itr != ProcessorSet.end(); itr++) {
	 if (itr != ProcessorSet.begin()) Processors += L";";
	 Processors += *itr;
	 }
   AdvColumnGrid1->Cells[1][5] = Processors;

   AdvColumnGrid1->Cells[1][6] = (dataset_ptr->IsSSamp) ? L"true" : L"false";
   AdvColumnGrid1->Cells[1][7] = dataset_ptr->Notes;

   for (int row=1; row<=7; row++) {
	 AdvColumnGrid1->ReadOnly[1][row] = true;
	 AdvColumnGrid1->ReadOnly[3][row] = true;
	 }

   TiliaBmp = new Graphics::TBitmap;
   cxImageList2->GetBitmap(0,TiliaBmp);
   AdvColumnGrid1->AddBitmap(1,0,TiliaBmp,true,haBeforeText,TCellVAlign::vaCenter);
   AdvColumnGrid1->FontColors[1][0] = clNavy;

   RatBmp = new Graphics::TBitmap;
   cxImageList2->GetBitmap(1,RatBmp);
   AdvColumnGrid1->AddBitmap(3,0,RatBmp,true,haBeforeText,TCellVAlign::vaCenter);
   AdvColumnGrid1->FontColors[3][0] = clNavy;

   if (update_tilia) {
	 cxButton2->Width = 88;
	 cxButton2->Caption = L"Continue";
	 cxButton2->OptionsImage->ImageIndex = 3;
	 cxButton2->OptionsImage->Layout = Buttons::blGlyphRight;
	 }
   int ButtonWidth = cxButton1->Width + cxButton2->Width;
   FlowPanel1->Left = (Panel2->Width - ButtonWidth)/2;
}
//---------------------------------------------------------------------------

void __fastcall TUpdateNeotomaDatasetForm::FormActivate(TObject *Sender)
{
   if (activated) return;

   if (!GetNeotomaDatasetData())
	 return;
}
//---------------------------------------------------------------------------

void __fastcall TUpdateNeotomaDatasetForm::FormClose(TObject *Sender, TCloseAction &Action)
{
   for (int i=0; i<DatasetPubs->Count; i++) {
	 PUBLICATION *pub = (PUBLICATION*)DatasetPubs->Items[i];
     delete pub;
	 DatasetPubs->Items[i] = 0;
     }
   DatasetPubs->Clear();
   delete DatasetPubs;
   delete TiliaBmp;
   delete RatBmp;
   if (ArrowBmp != NULL)
	 delete ArrowBmp;
}
//---------------------------------------------------------------------------

void __fastcall TUpdateNeotomaDatasetForm::AdvColumnGrid1GetEditorType(TObject *Sender,
		  int ACol, int ARow, TEditorType &AEditor)
{
   switch (ACol) {
	 case 1:
	   switch (ARow) {
		 case 2:
		 case 3:
		 case 7:
		   AEditor = edMemoDropDown;
		   break;
		 default:
		   AEditor = edNormal;
		   break;
		 }
	   break;
	 case 3:
	   switch (ARow) {
		 case 2:
		 case 3:
		 case 7:
		   AEditor = edMemoDropDown;
		   break;
		 default:
		   AEditor = edNormal;
		   break;
		 }
	   break;
	 default:
	   AEditor = edNormal;
	   break;
	 }
}
//---------------------------------------------------------------------------

bool TUpdateNeotomaDatasetForm::GetNeotomaDatasetData(void)
{
   UnicodeString ConnectError = L"Error connecting to Neotoma server.";

   bool success = true;
   Screen->Cursor = crHourGlass;
   try {
	   vector<DATASET> Datasets;
	   DATASET dataset;
	   Datasets.push_back(dataset);
	   vector<MAPDATASET> MapDatasets;
	   MAPDATASET MapDataset;
	   MapDataset.DatasetID = dataset_ptr->NeotomaDatasetID;
	   MapDatasets.push_back(MapDataset);
	   vector<NTMDATASET> NeotomaDatasets;

	   // get dataset metadata from Neotoma
	   if (!TSSForm->GetNeotomaDatasets(Datasets, MapDatasets, NeotomaDatasets, DatasetPubs))
		 return (success = false);
	   ntmdataset = Datasets[0];

	   AdvColumnGrid1->Cells[3][1] = Datasets[0].Name;

	   UnicodeString Investigators;
	   set<UnicodeString> InvestigatorSet;
	   for (unsigned int i=0; i<Datasets[0].Investigators.size(); i++)
		 InvestigatorSet.insert(Datasets[0].Investigators[i]->ShortContactName);
	   for (set<UnicodeString>::iterator itr = InvestigatorSet.begin(); itr != InvestigatorSet.end(); itr++) {
		 if (itr != InvestigatorSet.begin()) Investigators += L";";
		 Investigators += *itr;
		 }
	   AdvColumnGrid1->Cells[3][2] = Investigators;

	   UnicodeString Pubs;
	   set<UnicodeString> PubSet;
	   for (unsigned int i=0; i<Datasets[0].Publications.size(); i++) {
		 UnicodeString pub = Datasets[0].Publications[i]->GetShortCitation(false);
		 pub += L",";
		 pub += (Datasets[0].Publications[i]->Primary) ? L"1" : L"0";
		 PubSet.insert(pub);
		 }
	   for (set<UnicodeString>::iterator itr = PubSet.begin(); itr != PubSet.end(); itr++) {
		 if (itr != PubSet.begin()) Pubs += L";";
		 Pubs += *itr;
		 }
	   AdvColumnGrid1->Cells[3][3] = Pubs;

	   UnicodeString Repositories;
	   map<UnicodeString,UnicodeString> NtmRepositories;
	   for (unsigned int i=0; i<Datasets[0].Repositories.size(); i++)
		 NtmRepositories[Datasets[0].Repositories[i].Acronym] = Datasets[0].Repositories[i].SpecimenNotes;
	   for (map<UnicodeString,UnicodeString>::iterator itr = NtmRepositories.begin(); itr != NtmRepositories.end(); itr++) {
		 if (itr != NtmRepositories.begin())
		   Repositories += L";";
		 Repositories += itr->first;
		 }
	   AdvColumnGrid1->Cells[3][4] = Repositories;

       UnicodeString Processors;
	   set<UnicodeString> ProcessorSet;
	   for (unsigned int i=0; i<Datasets[0].Processors.size(); i++)
		 ProcessorSet.insert(Datasets[0].Processors[i]->ShortContactName);
	   for (set<UnicodeString>::iterator itr = ProcessorSet.begin(); itr != ProcessorSet.end(); itr++) {
		 if (itr != ProcessorSet.begin()) Processors += L";";
		 Processors += *itr;
		 }
	   AdvColumnGrid1->Cells[3][5] = Processors;

	   // get sample keywords
	   Datasets[0].IsSSamp = false;
	   NeotomaDatasetSampleKeywords NtmSampleKeywords(ipsJSONS1, TcpClient1);
	   NtmSampleKeywords.AddParam(L"DATASETID", Datasets[0].NeotomaDatasetID);
	   ParentForm->StatusBar1->Panels->Items[0]->Text = NtmSampleKeywords.WebServiceName();
	   if (!NtmSampleKeywords.Execute())
		 return (success = false);
	   multimap<int,UnicodeString>::iterator itr;      // SampleID, Keyword
	   for (itr = NtmSampleKeywords.Items.begin(); itr != NtmSampleKeywords.Items.end(); itr++) {
		 // if (SameText(itr->second, L"modern sample")) [
		 if (SameText(itr->second, L"modern")) {
		   Datasets[0].IsSSamp = true;
		   break;
		   }
		 }

	   AdvColumnGrid1->Cells[3][6] = (Datasets[0].IsSSamp) ? L"true" : L"false";
	   AdvColumnGrid1->Cells[3][7] = Datasets[0].Notes;

	   // list any repositories for which specimen notes differ
	   for (map<UnicodeString,UnicodeString>::iterator itr = TilRepositories.begin(); itr != TilRepositories.end(); itr++) {
		 if (NtmRepositories.count(itr->first) > 0) {  // the Tilia dataset repository exists in Neotoma
		   if (itr->second != NtmRepositories[itr->first]) {  // specimen repository notes differ
			 int row = AdvColumnGrid1->RowCount;
			 AdvColumnGrid1->RowCount++;
			 AdvColumnGrid1->Cells[0][row] = itr->first + L" Specimen Notes";
			 AdvColumnGrid1->Cells[1][row] = itr->second;
			 AdvColumnGrid1->Cells[3][row] = NtmRepositories[itr->first];
		     }
		   }
		 }

	   bool data_same = true;
	   for (int row=1; row<AdvColumnGrid1->RowCount; row++) {
		 if (AdvColumnGrid1->Cells[1][row] != AdvColumnGrid1->Cells[3][row]) {
		   AdvColumnGrid1->Colors[1][row] = (TColor)0x006EBBFF;
		   AdvColumnGrid1->Colors[3][row] = (TColor)0x006EBBFF;
		   if (update_tilia) {
			 ArrowBmp = new Graphics::TBitmap;
			 cxImageList1->GetBitmap(0,ArrowBmp);
			 AdvColumnGrid1->AddBitButton(2,row,16,9,L"",ArrowBmp,haFull,vaFull);
			 }
		   data_same = false;
		   }
		 }

	   if (data_same) {
		 MessageDlg(L"Dataset metadata in Tilia and Neotoma are the same. No need to update.",
		   mtInformation, TMsgDlgButtons() << mbOK, 0);
		 ModalResult = mrClose;
		 Close();
		 }
	   else
		 cxButton1->Enabled = true;
	   }
   __finally {
	   StatusBar1->SimpleText = L"";
	   if (!success)
		 MessageDlg(ConnectError, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   Screen->Cursor = crDefault;
	   }

   return success;
}
//---------------------------------------------------------------------------

// update Neotoma dataset metadata
void __fastcall TUpdateNeotomaDatasetForm::cxButton1Click(TObject *Sender)
{
   UnicodeString msg = L"Update metadata for " + dataset_ptr->DatasetType +
     " dataset in Neotoma with data from the Tilia column?";
   if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) != mrYes)
	 return;

   NeotomaDatasetValidationForm = new TNeotomaDatasetValidationForm(dataset_ptr,
	  ntmdataset, AdvColumnGrid1, TSSForm);
   NeotomaDatasetValidationForm->ShowModal();
   delete NeotomaDatasetValidationForm;

   ModalResult = mrOk;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

__fastcall TNeotomaSiteValidationForm::TNeotomaSiteValidationForm(SITE* sptr,
	TAdvColumnGrid* grid, map<int,int>& geopol_id, TComponent* Owner)
	: TNeotomaUploadForm(Owner)
{
   site_ptr = sptr;
   AdvColumnGrid1 = grid;
   GeoPolID = geopol_id;
   cxButton2->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaSiteValidationForm::FormCreate(TObject *Sender)
{
   Step = 0;
   nSteps = 6;
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaSiteValidationForm::FormActivate(TObject *Sender)
{
   if (!Activated) {
	 Activated = true;
	 Validate();
	 }
}
//---------------------------------------------------------------------------

void TNeotomaSiteValidationForm::Validate(void)
{
   int rv = RunValidation();
   if (rv == mrAbort) {
	 OutputError(L"VALIDATION ABORTED");
	 cxButton4->Visible = true;
	 cxButton1->Visible = true;
	 cxButton3->Visible = true;
	 }
   else if (rv == mrOk) {
	 UpdateSiteData();
	 cxButton4->Visible = true;
	 cxButton1->Visible = true;
	 cxButton3->Visible = true;
	 }
}
//---------------------------------------------------------------------------

int TNeotomaSiteValidationForm::RunValidation(void)
{
   // validate site metadata
   int success = mrOk;
   try {
	   site_ptr->NeotomaGeoPolID.clear();
	   site_ptr->NeotomaLakeParams.clear();
	   OutputBoldLine(L"Site Metadata validation:");
	   CheckSiteName(site_ptr);
	   if (!CheckSiteLatLong(site_ptr))
		 return(success = mrAbort);
	   if (CheckGeoPolUnits(site_ptr) == mrAbort)
		 return(success = mrAbort);
	   CheckSiteAltitude(site_ptr);
	   CheckSiteArea(site_ptr);
	   CheckLakeParameters(site_ptr);
	   NewMessages.SetMessages(TotalMessages, ArchiveMessages);
	   OutputBoldLine(L"Site metadata validation completed: " + ValidationMsg(NewMessages));

	   if (TotalMessages.Errors > 0)
		 return(success = mrAbort);
	   else if (TotalMessages.Warnings > 0 || TotalMessages.Notes > 0) {
		 cxButton2->Caption = L"Update Neotoma";
		 cxButton2->Visible = true;
		 cxButton3->Visible = true;
		 cxButton1->Visible = true;
		 cxButton4->Visible = true;
		 UnicodeString msg = L"Review warnings or notes. Click the \"Update Neotoma\" button to proceed with update.";
		 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
		 return(success = mrRetry);
		 }
	   }
   __finally {
	   SetProgressBar(CORE);
	   Screen->Cursor = crDefault;
	   StatusBar1->SimpleText = L"";
	   }
   return success;
}
//---------------------------------------------------------------------------

// upload button
void __fastcall TNeotomaSiteValidationForm::cxButton2Click(TObject *Sender)
{
   cxButton2->Enabled = false;
   UpdateSiteData();
   cxButton4->Visible = true;
   cxButton1->Visible = true;
   cxButton3->Visible = true;
}
//---------------------------------------------------------------------------

void TNeotomaSiteValidationForm::UpdateSiteData(void)
{
   UnicodeString ErrorMsg;
   bool success = true;

   if (!Login->IsLoggedIn) {
	 NeotomaLoginForm = new TNeotomaLoginForm(this);
	 NeotomaLoginForm->ShowModal();
	 delete NeotomaLoginForm;
	 }
   if (!Login->IsLoggedIn)
	 return;

   Screen->Cursor = crHourGlass;
   OutputBoldLine(L"\nBegin Update");

   UpdateData UpdateSite(L"UpdateSite", 11, ipsHTTPS1, ipsJSONS1, TcpClient1);
   StatusBar1->SimpleText = L"UpdateSite";
   UpdateSite.Add(L"SITEID", site_ptr->NeotomaSiteID);
   UpdateSite.Add(L"STEWARDCONTACTID", Login->ContactID);
   UpdateSite.Add(L"SITENAME", site_ptr->SiteName);
   UpdateSite.AddDouble(L"EAST", site_ptr->LongEast);
   UpdateSite.AddDouble(L"NORTH", site_ptr->LatNorth);
   UpdateSite.AddDouble(L"WEST", site_ptr->LongWest);
   UpdateSite.AddDouble(L"SOUTH", site_ptr->LatSouth);
   UpdateSite.AddDouble(L"ALTITUDE", site_ptr->Altitude);
   UpdateSite.AddDouble(L"AREA", site_ptr->Area);
   UpdateSite.Add(L"DESCRIPT", site_ptr->SiteDescription);
   UpdateSite.Add(L"NOTES", site_ptr->Notes);

   if (UpdateSite.Post(ErrorMsg))
	 OutputLine(L"Site metadata updated.");
   else if (!ErrorMsg.IsEmpty()) {
	 success = false;
	 OutputError(L"ERROR: " + ErrorMsg);
	 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 }

   if (success && AdvColumnGrid1->RowCount > 14) {
	 //LakeParam.Name = AdvColumnGrid1->Cells[0][ARow];
	 for (int row=14; row<AdvColumnGrid1->RowCount; row++) {
	   if (AdvColumnGrid1->Cells[1][row] != AdvColumnGrid1->Cells[3][row]) {
		 bool good_to_go = true;
		 Variant Value = Unassigned();
		 if (!AdvColumnGrid1->Cells[1][row].IsEmpty()) {
		   double dValue;
		   if (TryStrToFloat(AdvColumnGrid1->Cells[1][row],dValue))
			 Value = dValue;
		   else
			 good_to_go = false;
		   }
		 if (good_to_go) {
		   UpdateData UpdateLakeParam(L"UpdateLakeParam", 4, ipsHTTPS1, ipsJSONS1, TcpClient1);
		   StatusBar1->SimpleText = L"UpdateLakeParam";
		   UpdateLakeParam.Add(L"SITEID", site_ptr->NeotomaSiteID);
		   UpdateLakeParam.Add(L"STEWARDCONTACTID", Login->ContactID);
		   UpdateLakeParam.Add(L"LAKEPARAMETER", AdvColumnGrid1->Cells[0][row]);
		   UpdateLakeParam.AddDouble(L"VALUE", Value);

		   if (UpdateLakeParam.Post(ErrorMsg))
			 OutputLine(L"Lake parameter «" + AdvColumnGrid1->Cells[0][row] + L"» updated.");
		   else if (!ErrorMsg.IsEmpty()) {
			 success = false;
			 OutputError(L"ERROR: " + ErrorMsg + L" Attempting to update lake parameter «" +
			   AdvColumnGrid1->Cells[0][row] + L"».");
			 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			 break;
			 }
		   }
		 }
	   }
	 }

   // update site geopolitical units
   if (success) {
	 if (site_ptr->NeotomaGeoPolID.count(NTM_COUNTRY) == 1) {   // should always be true
	   if (site_ptr->NeotomaGeoPolID[NTM_COUNTRY] != GeoPolID[NTM_COUNTRY]) {
		 if (GeoPolID[NTM_COUNTRY] > -1)   // GeoPol1 already exists in Neotoma
		   success = UpdateGeoPol(NTM_COUNTRY, L"First geopolitical division", site_ptr->Country);
		 else   // insert new record for GeoPol1 (probably should never happen)
		   success = InsertGeoPol(NTM_COUNTRY, L"First geopolitical division", site_ptr->Country);
		 }
	   }
	 }

   if (success) {
	 if (site_ptr->NeotomaGeoPolID.count(NTM_STATE) == 1) {   // GeoPol2 designated
	   if (site_ptr->NeotomaGeoPolID[NTM_STATE] != GeoPolID[NTM_STATE]) {
		 if (GeoPolID[NTM_STATE] > -1)   // GeoPol2 already exists in Neotoma
		   success = UpdateGeoPol(NTM_STATE, L"Second geopolitical division", site_ptr->State);
		 else
		   success = InsertGeoPol(NTM_STATE, L"Second geopolitical division", site_ptr->State);
		 }
	   }
	 else if (GeoPolID[NTM_STATE] > -1) {  // GeoPol2 not designated, but exists in neotoma
	   success = DeleteGeoPol(NTM_STATE, L"Second geopolitical division", site_ptr->State);
	   }
	 }

   if (success) {
	 if (site_ptr->NeotomaGeoPolID.count(NTM_COUNTY) == 1) {   // GeoPol3 designated
	   if (site_ptr->NeotomaGeoPolID[NTM_COUNTY] != GeoPolID[NTM_COUNTY]) {
		 if (GeoPolID[NTM_COUNTY] > -1)   // GeoPol3 already exists in Neotoma
		   success = UpdateGeoPol(NTM_COUNTY, L"Third geopolitical division", site_ptr->County);
		 else
		   success = InsertGeoPol(NTM_COUNTY, L"Third geopolitical division", site_ptr->County);
		 }
	   }
	 else if (GeoPolID[NTM_COUNTY] > -1) {  // GeoPol3 not designated, but exists in neotoma
	   success = DeleteGeoPol(NTM_COUNTY, L"Third geopolitical division", site_ptr->County);
	   }
	 }

   if (success) {
	 if (site_ptr->NeotomaGeoPolID.count(NTM_ADMINUNIT) == 1) {   // GeoPol3 designated
	   if (site_ptr->NeotomaGeoPolID[NTM_ADMINUNIT] != GeoPolID[NTM_ADMINUNIT]) {
		 if (GeoPolID[NTM_ADMINUNIT] > -1)   // GeoPol3 already exists in Neotoma
		   success = UpdateGeoPol(NTM_ADMINUNIT, L"Administrative Unit", site_ptr->AdminUnit);
		 else
		   success = InsertGeoPol(NTM_ADMINUNIT, L"Administrative Unit", site_ptr->AdminUnit);
		 }
	   }
	 else if (GeoPolID[NTM_ADMINUNIT] > -1) {  // GeoPol3 not designated, but exists in neotoma
	   success = DeleteGeoPol(NTM_ADMINUNIT, L"Administrative Unit", site_ptr->AdminUnit);
	   }
	 }

   if (success) {
	 UnicodeString msg = L"Success: All site metadata updated!";
	 OutputLine(msg + L" " + DateTimeStr(UTCDateTime()) + L" UTC");
	 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
	 }

   StatusBar1->SimpleText = L"";
   Screen->Cursor = crDefault;
   cxButton2->Visible = false;
}
//---------------------------------------------------------------------------

bool TNeotomaSiteValidationForm::UpdateGeoPol(int rank, UnicodeString Division, UnicodeString GeopolUnit)
{
   UnicodeString ErrorMsg;
   bool success = true;

   UpdateData UpdateSiteGeoPol(L"UpdateSiteGeoPol", 4, ipsHTTPS1, ipsJSONS1, TcpClient1);
   StatusBar1->SimpleText = L"UpdateSiteGeoPol";
   UpdateSiteGeoPol.Add(L"SITEID", site_ptr->NeotomaSiteID);
   UpdateSiteGeoPol.Add(L"STEWARDCONTACTID", Login->ContactID);
   UpdateSiteGeoPol.Add(L"OLDGEOPOLID", GeoPolID[rank]);
   UpdateSiteGeoPol.Add(L"NEWGEOPOLID", site_ptr->NeotomaGeoPolID[rank]);
   if (UpdateSiteGeoPol.Post(ErrorMsg))
	 OutputLine(Division + L" updated to «" + GeopolUnit + L"».");
   else if (!ErrorMsg.IsEmpty()) {
	 success = false;
	 OutputError(L"ERROR: " + ErrorMsg + L" Attempting to update " + Division.LowerCase() +
	   L" to «" + GeopolUnit + L"».");
	 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 }
   return success;
}
//---------------------------------------------------------------------------

bool TNeotomaSiteValidationForm::InsertGeoPol(int rank, UnicodeString Division, UnicodeString GeopolUnit)
{
   UnicodeString ErrorMsg;
   bool success = true;

   UpdateData InsertGeoPol(L"UpdateSiteGeoPolInsert", 3, ipsHTTPS1, ipsJSONS1, TcpClient1);
   InsertGeoPol.Add(L"SITEID", site_ptr->NeotomaSiteID);
   InsertGeoPol.Add(L"STEWARDCONTACTID", Login->ContactID);
   InsertGeoPol.Add(L"GEOPOLITICALID", site_ptr->NeotomaGeoPolID[rank]);
   StatusBar1->SimpleText = L"UpdateSiteGeoPolInsert";
   if (InsertGeoPol.Post(ErrorMsg))
	 OutputLine(Division + L" «" + GeopolUnit + L"» uploaded to SiteGeoPolitical table.");
   else {
	 OutputError(L"ERROR: " + ErrorMsg);
	 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 success = false;
	 }
   return success;
}
//---------------------------------------------------------------------------

bool TNeotomaSiteValidationForm::DeleteGeoPol(int rank, UnicodeString Division, UnicodeString GeopolUnit)
{
   UnicodeString ErrorMsg;
   bool success = true;

   UpdateData DeleteGeoPol(L"UpdateSiteGeoPolDelete", 3, ipsHTTPS1, ipsJSONS1, TcpClient1);
   StatusBar1->SimpleText = L"UpdateSiteGeoPolDelete";
   DeleteGeoPol.Add(L"STEWARDCONTACTID", Login->ContactID);
   DeleteGeoPol.Add(L"SITEID", site_ptr->NeotomaSiteID);
   DeleteGeoPol.Add(L"GEOPOLITICALID", site_ptr->NeotomaGeoPolID[rank]);
   if (DeleteGeoPol.Post(ErrorMsg))
	 OutputLine(Division + L" «" + GeopolUnit + L"» deleted.");
   else if (!ErrorMsg.IsEmpty()) {
	 success = false;
	 OutputError(L"ERROR: " + ErrorMsg + L" Attempting to delete " + Division.LowerCase() +
	   L" «" + GeopolUnit + L"».");
	 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 }
   return success;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

__fastcall TNeotomaCollUnitValidationForm::TNeotomaCollUnitValidationForm(
	vector<COLLECTION>::pointer cptr, TAdvColumnGrid* grid, TComponent* Owner)
	: TNeotomaUploadForm(Owner)
{
   site_ptr = TSSForm->SitePtr;
   coll_ptr = cptr;
   AdvColumnGrid1 = grid;
   cxButton2->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaCollUnitValidationForm::FormCreate(TObject *Sender)
{
   Step = 0;
   nSteps = 1;
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaCollUnitValidationForm::FormActivate(TObject *Sender)
{
   if (!Activated) {
	 Activated = true;
	 Validate();
	 }
}
//---------------------------------------------------------------------------

void TNeotomaCollUnitValidationForm::Validate(void)
{
   int rv = RunValidation();
   if (rv == mrAbort) {
	 OutputError(L"VALIDATION ABORTED");
	 cxButton4->Visible = true;
	 cxButton1->Visible = true;
	 cxButton3->Visible = true;
	 }
   else if (rv == mrOk) {
	 UpdateCollUnitData();
	 cxButton4->Visible = true;
	 cxButton1->Visible = true;
	 cxButton3->Visible = true;
	 }
}
//---------------------------------------------------------------------------

int TNeotomaCollUnitValidationForm::RunValidation(void)
{
   // validate collection unit metadata
   UnicodeString msg, ErrorMsg;
   int success = mrOk;

   try {
	   OutputBoldLine(L"Collection Unit Metadata validation:");
	   if (!ValidateHandle(coll_ptr))
		 return(success = mrAbort);
	   if (!ValidateCollUnitType(coll_ptr))
		 return(success = mrAbort);
	   ValidateCollUnitName(coll_ptr);
	   if (!ValidateCollUnitGPS(coll_ptr, site_ptr))
		 return(success = mrAbort);

	   // depositional environments
	   int rv;
	   do {
		  rv = ValidateCollUnitDepEnvt(coll_ptr, site_ptr);
		  } while (rv == mrRetry);
	   if (rv == mrAbort)
		 return(success = mrAbort);

	   if (!ValidateCollUnitSubstrate(coll_ptr))
		 return(success = mrAbort);

	   // check that all collectors in Neotoma
	   if (coll_ptr->Collectors.size() > 0) {
		 for (unsigned int i=0; i<coll_ptr->Collectors.size(); i++) {
		   if (coll_ptr->Collectors[i]->NeotomaContactID == -1) {
			 msg = L"Collector «" + coll_ptr->Collectors[i]->ShortContactName +
				   L"» not uploaded to Neotoma.";
			 OutputError(L"ERROR: " + msg);
			 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			 return(success = mrAbort);
			 }
		   }
		 }

	   NewMessages.SetMessages(TotalMessages, ArchiveMessages);
	   OutputBoldLine(L"Collection unit metadata validation completed: " + ValidationMsg(NewMessages));

	   if (TotalMessages.Errors > 0)
		 return(success = mrAbort);
	   else if (TotalMessages.Warnings > 0 || TotalMessages.Notes > 0) {
		 cxButton2->Caption = L"Update Neotoma";
		 cxButton2->Visible = true;
		 cxButton3->Visible = true;
		 cxButton1->Visible = true;
		 cxButton4->Visible = true;
		 UnicodeString msg = L"Review warnings or notes. Click the \"Update Neotoma\" button to proceed with update.";
		 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
		 return(success = mrRetry);
		 }
	   }
   __finally {
	   SetProgressBar(CORE);
	   Screen->Cursor = crDefault;
	   StatusBar1->SimpleText = L"";
	   }

   return success;
}
//---------------------------------------------------------------------------

// upload button
void __fastcall TNeotomaCollUnitValidationForm::cxButton2Click(TObject *Sender)
{
   cxButton2->Enabled = false;
   UpdateCollUnitData();
   cxButton4->Visible = true;
   cxButton1->Visible = true;
   cxButton3->Visible = true;
}
//---------------------------------------------------------------------------

void TNeotomaCollUnitValidationForm::UpdateCollUnitData(void)
{
   UnicodeString ErrorMsg;
   bool success = true;

   if (!Login->IsLoggedIn) {
	 NeotomaLoginForm = new TNeotomaLoginForm(this);
	 NeotomaLoginForm->ShowModal();
	 delete NeotomaLoginForm;
	 }
   if (!Login->IsLoggedIn)
	 return;

   Screen->Cursor = crHourGlass;
   OutputBoldLine(L"\nBegin Update");

   UpdateData UpdateCollUnit(L"UpdateCollectionUnit", 18, ipsHTTPS1, ipsJSONS1, TcpClient1);
   StatusBar1->SimpleText = L"UpdateCollectionUnit";
   UpdateCollUnit.Add(L"COLLUNITID", coll_ptr->NeotomaCollUnitID);
   UpdateCollUnit.Add(L"STEWARDCONTACTID", Login->ContactID);
   UpdateCollUnit.Add(L"HANDLE", coll_ptr->Handle);
   UpdateCollUnit.Add(L"COLLTYPEID", coll_ptr->NeotomaCollTypeID);
   UpdateCollUnit.Add(L"DEPENVTID", coll_ptr->NeotomaDepEnvtID, -1);
   UpdateCollUnit.Add(L"COLLUNITNAME", coll_ptr->CollectionName);
   UpdateCollUnit.Add(L"COLLDATE", DateStr(coll_ptr->CollDate));
   UpdateCollUnit.Add(L"COLLDEVICE", coll_ptr->CollectionDevice);
   UpdateCollUnit.AddDouble(L"GPSLATITUDE", coll_ptr->GPSLat);
   UpdateCollUnit.AddDouble(L"GPSLONGITUDE", coll_ptr->GPSLong);
   UpdateCollUnit.AddDouble(L"GPSALTITUDE", coll_ptr->GPSAltitude);
   UpdateCollUnit.AddDouble(L"GPSERROR", coll_ptr->GPSError);
   UpdateCollUnit.AddDouble(L"WATERDEPTH", coll_ptr->WaterDepth);
   UpdateCollUnit.Add(L"SUBSTRATEID", coll_ptr->NeotomaRockTypeID, -1);
   UpdateCollUnit.AddInt(L"SLOPEASPECT", coll_ptr->SlopeAspect);
   UpdateCollUnit.AddInt(L"SLOPEANGLE", coll_ptr->SlopeAngle);
   UpdateCollUnit.Add(L"LOCATION", coll_ptr->Location);
   UpdateCollUnit.Add(L"NOTES", coll_ptr->Notes);

   if (UpdateCollUnit.Post(ErrorMsg)) {
	 OutputLine(L"Collection unit metadata updated.");
	 coll_ptr->NeotomaHandle = coll_ptr->Handle;
	 }
   else if (!ErrorMsg.IsEmpty()) {
	 success = false;
	 OutputError(L"ERROR: " + ErrorMsg);
	 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 }

   // collectors
   if (success && AdvColumnGrid1->Cells[1][5] != AdvColumnGrid1->Cells[3][5]) {
	 // delete current collectors
	 DeleteData DeleteCollectors(L"DeleteCollectors", 1, ipsHTTPS1, ipsJSONS1, TcpClient1);
	 StatusBar1->SimpleText = L"DeleteCollectors";
	 DeleteCollectors.Add(L"COLLUNITID", coll_ptr->NeotomaCollUnitID);
	 if (!DeleteCollectors.Post(ErrorMsg)) {
	   UnicodeString msg = L"Update of collectors aborted";
	   if (!ErrorMsg.IsEmpty())
		 msg += (L": " + ErrorMsg);
	   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   success = false;
	   }
	 
	 // add new collectors       
	 if (success && coll_ptr->Collectors.size() > 0) {
	   int order = 1;
	   InsertData InsertCollector(L"InsertCollector", 3, ipsHTTPS1, ipsJSONS1, TcpClient1);
	   for (unsigned int i=0; i<coll_ptr->Collectors.size(); i++) {
		 InsertCollector.Add(L"COLLUNITID", coll_ptr->NeotomaCollUnitID, -1);
		 InsertCollector.Add(L"CONTACTID", coll_ptr->Collectors[i]->NeotomaContactID, -1);
		 InsertCollector.Add(L"COLLECTORORDER", order++, -1);
		 }
	   StatusBar1->SimpleText = L"InsertCollector";
	   InsertCollector.PostData();
	   vector<int> newids;
	   if (InsertCollector.Post(newids, ErrorMsg)) {
		 if (newids.size() == coll_ptr->Collectors.size()) {
		   for (unsigned int i=0; i<newids.size(); i++) {    
			 OutputLine(L"Collector «" + coll_ptr->Collectors[i]->ShortContactName +
			   L"» uploaded to Collectors table: CollectorID = " + IntToStr(newids[i]) + L".");
			 }
		   }
		 else {
		   ErrorMsg = L"Error inserting into Collectors table!";
		   OutputError(L"ERROR: " + ErrorMsg);
		   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   success = false;
		   }
		 }
	   else {
		 OutputError(L"ERROR: " + ErrorMsg);
		 MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 success = false;
		 }
	   }
	 
	 }

   if (success) {
	 UnicodeString msg = L"Success: Collection unit metadata updated!";
	 OutputLine(msg + L" " + DateTimeStr(UTCDateTime()) + L" UTC");
	 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
	 }

   StatusBar1->SimpleText = L"";
   Screen->Cursor = crDefault;
   cxButton2->Visible = false;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

__fastcall TNeotomaDatasetValidationForm::TNeotomaDatasetValidationForm(
	DATASET* dptr, DATASET& nd, TAdvColumnGrid* grid, TComponent* Owner)
	: TNeotomaUploadForm(Owner)
{
   site_ptr = TSSForm->SitePtr;
   dataset_ptr = dptr;
   ntmdataset = nd;
   AdvColumnGrid1 = grid;
   cxButton2->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaDatasetValidationForm::FormCreate(TObject *Sender)
{
   Step = 0;
   nSteps = 1;
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaDatasetValidationForm::FormActivate(TObject *Sender)
{
   if (!Activated) {
	 Activated = true;
	 Validate();
	 }
}
//---------------------------------------------------------------------------

void TNeotomaDatasetValidationForm::Validate(void)
{
   int rv = RunValidation();
   if (rv == mrAbort) {
	 OutputError(L"VALIDATION ABORTED");
	 cxButton4->Visible = true;
	 cxButton1->Visible = true;
	 cxButton3->Visible = true;
	 }
   else if (rv == mrOk) {
	 UpdateDatasetData();
	 cxButton4->Visible = true;
	 cxButton1->Visible = true;
	 cxButton3->Visible = true;
	 }
}
//---------------------------------------------------------------------------

int TNeotomaDatasetValidationForm::RunValidation(void)
{
   // validate dataset metadata
   UnicodeString msg;
   int rv = mrOk;

   try {
	   OutputBoldLine(L"Dataset Metadata validation:");
	   if (dataset_ptr->Name.IsEmpty())
		 OutputNote(L"NOTE: «" + dataset_ptr->DatasetType.LowerCase() + L"» dataset has no name.");
	   else
		 OutputLine(L"«" + dataset_ptr->DatasetType + L"» dataset name is «" + dataset_ptr->Name + L"».");
	   for (unsigned int i = 0; i < dataset_ptr->Investigators.size(); i++) {
		 if (dataset_ptr->Investigators[i]->NeotomaContactID ==  -1) {
		   msg =  L"ERROR: Investigator «" + dataset_ptr->Investigators[i]->ShortContactName +
				  L"» has not been uploaded to Neotoma.";
		   OutputError(msg);
		   return(rv = mrAbort);
		   }
		 }
	   if (!ValidateDatasetInvestigators(dataset_ptr, valWARNING))
		 return(rv = mrAbort);
	   if (!ValidateDatasetProcessors(dataset_ptr, valWARNING))
		 return(rv = mrAbort);
	   if (!ValidateDatasetPubs(dataset_ptr))
		 return(rv = mrAbort);
	   if (!ValidateDatasetRepositories(dataset_ptr))
		 return(rv = mrAbort);
	   if (dataset_ptr->IsSSamp)
		 OutputLine("Top sample is a modern surface sample.");
	   else
		 OutputLine("Top sample is not designated as a modern surface sample.");
	   }
   __finally {
	   SetProgressBar(CORE);
	   Screen->Cursor = crDefault;
	   StatusBar1->SimpleText = L"";
	   }
   return rv;
}
//---------------------------------------------------------------------------

// upload button
void __fastcall TNeotomaDatasetValidationForm::cxButton2Click(TObject *Sender)
{
   cxButton2->Enabled = false;
   UpdateDatasetData();
   cxButton4->Visible = true;
   cxButton1->Visible = true;
   cxButton3->Visible = true;
}
//---------------------------------------------------------------------------

void TNeotomaDatasetValidationForm::UpdateDatasetData(void)
{
   UnicodeString msg, ErrorMsg;
   bool success = true;

   if (!Login->IsLoggedIn) {
	 NeotomaLoginForm = new TNeotomaLoginForm(this);
	 NeotomaLoginForm->ShowModal();
	 delete NeotomaLoginForm;
	 }
   if (!Login->IsLoggedIn)
	 return;

   Screen->Cursor = crHourGlass;
   OutputBoldLine(L"\nBegin Update");

   /*
   AdvColumnGrid1->Cells[0][1] = L"Dataset Name";
   AdvColumnGrid1->Cells[0][2] = L"Investigators";
   AdvColumnGrid1->Cells[0][3] = L"Publications";
   AdvColumnGrid1->Cells[0][4] = L"Repository";
   AdvColumnGrid1->Cells[0][5] = L"Data Processors";
   AdvColumnGrid1->Cells[0][6] = L"Is Surface Sample";
   AdvColumnGrid1->Cells[0][7] = L"Dataset Notes";
   */

   try {
	   if (AdvColumnGrid1->Cells[1][1] != AdvColumnGrid1->Cells[3][1]) {  // update dataset name
		 UpdateData UpdateDatasetName(L"UpdateDatasetName", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
		 StatusBar1->SimpleText = L"UpdateDatasetName";
		 UpdateDatasetName.Add(L"DATASETID", dataset_ptr->NeotomaDatasetID);
		 UpdateDatasetName.Add(L"DATASETNAME", dataset_ptr->Name);
		 if (UpdateDatasetName.Post(ErrorMsg)) {
		   msg = L"Dataset name updated to «" + dataset_ptr->Name + L"».";
		   OutputLine(msg);
		   }
		 else {
		   OutputError(L"ERROR: " + ErrorMsg);
		   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   success = false;
		   return;
		   }
		 }

	   if (AdvColumnGrid1->Cells[1][2] != AdvColumnGrid1->Cells[3][2]) {  // update investigators
		 vector<CONTACT*>::iterator itr;
		 for (unsigned int i=0; i<dataset_ptr->Investigators.size(); i++) {
		   itr = find(ntmdataset.Investigators.begin(), ntmdataset.Investigators.end(), dataset_ptr->Investigators[i]);
		   if (itr == ntmdataset.Investigators.end()) {  // new investigator in dataset_ptr
			 InsertData InsertDatasetPI(L"InsertNewDatasetPI", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
			 InsertDatasetPI.Add(L"DATASETID", dataset_ptr->NeotomaDatasetID, -1);
			 InsertDatasetPI.Add(L"CONTACTID", dataset_ptr->Investigators[i]->NeotomaContactID, -1);
			 StatusBar1->SimpleText = L"InsertNewDatasetPI";
			 InsertDatasetPI.PostData();
			 if (InsertDatasetPI.Post(ErrorMsg)) {
			   msg = L"Dataset investigator uploaded: " + dataset_ptr->Investigators[i]->ShortContactName;
			   OutputLine(msg);
			   }
			 else {
			   OutputError(L"ERROR: " + ErrorMsg);
			   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			   success = false;
			   return;
			   }
			 }
		   }
		 for (unsigned int i=0; i<ntmdataset.Investigators.size(); i++) {
		   itr = find(dataset_ptr->Investigators.begin(), dataset_ptr->Investigators.end(), ntmdataset.Investigators[i]);
		   if (itr == dataset_ptr->Investigators.end()) {  // delete ntmdataset investigator
			 DeleteData DeleteDatasetPI(L"DeleteDatasetPI", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
			 StatusBar1->SimpleText = L"DeleteDatasetPI";
			 DeleteDatasetPI.Add(L"DATASETID", dataset_ptr->NeotomaDatasetID);
			 DeleteDatasetPI.Add(L"CONTACTID", ntmdataset.Investigators[i]->NeotomaContactID);
			 if (DeleteDatasetPI.Post(ErrorMsg)) {
			   msg = L"Dataset investigator deleted: " + ntmdataset.Investigators[i]->ShortContactName;
			   OutputLine(msg);
			   }
			 else
			   {
			   OutputError(L"ERROR: " + ErrorMsg);
			   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			   success = false;
			   return;
			   }
			 }
		   }
		 }

	   if (AdvColumnGrid1->Cells[1][3] != AdvColumnGrid1->Cells[3][3]) {  // update publications
		 for (unsigned int i=0; i<dataset_ptr->Publications.size(); i++) {
		   bool found = false;
		   for (unsigned int j=0; j<ntmdataset.Publications.size(); j++) {
			 if (ntmdataset.Publications[j]->NeotomaID == dataset_ptr->Publications[i]->NeotomaID) {
			   found = true;
			   break;
			   }
			 }
		   if (!found) {
			 InsertData InsertDatasetPub(L"InsertDatasetPublication", 3, ipsHTTPS1, ipsJSONS1, TcpClient1);
			 InsertDatasetPub.Add(L"DATASETID", dataset_ptr->NeotomaDatasetID, -1);
			 InsertDatasetPub.Add(L"PUBLICATIONID", dataset_ptr->Publications[i]->NeotomaID, -1);
			 InsertDatasetPub.Add(L"PRIMARYPUB", dataset_ptr->Publications[i]->Primary);
			 StatusBar1->SimpleText = L"InsertDatasetPublication";
			 InsertDatasetPub.PostData();
			 if (InsertDatasetPub.Post(ErrorMsg)) {
			   msg = L"Dataset publication uploaded: " + dataset_ptr->Publications[i]->GetShortCitation(false);
			   OutputLine(msg);
			   }
			 else {
			   OutputError(L"ERROR: " + ErrorMsg);
			   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			   success = false;
			   return;
			   }
			 }
		   }
		 for (unsigned int i=0; i<ntmdataset.Publications.size(); i++) {
		   bool found = false;
		   for (unsigned int j=0; j<dataset_ptr->Publications.size(); j++) {
			 if (ntmdataset.Publications[i]->NeotomaID == dataset_ptr->Publications[j]->NeotomaID) {
			   found = true;
			   break;
			   }
			 }
		   if (!found) {
			 DeleteData DeleteDatasetPub(L"DeleteDatasetPublication", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
			 StatusBar1->SimpleText = L"DeleteDatasetPublication";
			 DeleteDatasetPub.Add(L"DATASETID", dataset_ptr->NeotomaDatasetID);
			 DeleteDatasetPub.Add(L"PUBLICATIONID", ntmdataset.Publications[i]->NeotomaID);
			 if (DeleteDatasetPub.Post(ErrorMsg)) {
			   msg = L"Dataset publication deleted: " + ntmdataset.Publications[i]->GetShortCitation(false);
			   OutputLine(msg);
			   }
			 else
			   {
			   OutputError(L"ERROR: " + ErrorMsg);
			   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			   success = false;
			   return;
			   }
			 }
		   }
		 // update any primary status changes
		 for (unsigned int i=0; i<dataset_ptr->Publications.size(); i++) {
		   for (unsigned int j=0; j<ntmdataset.Publications.size(); j++) {
			 if (ntmdataset.Publications[j]->NeotomaID == dataset_ptr->Publications[i]->NeotomaID) {
			   if (dataset_ptr->Publications[i]->Primary != ntmdataset.Publications[j]->Primary) {
				 UpdateData UpdatePrimary(L"UpdateDatasetPubPrimary", 3, ipsHTTPS1, ipsJSONS1, TcpClient1);
				 StatusBar1->SimpleText = L"UpdateDatasetPubPrimary";
				 UpdatePrimary.Add(L"DATASETID", dataset_ptr->NeotomaDatasetID);
				 UpdatePrimary.Add(L"PUBLICATIONID", dataset_ptr->Publications[i]->NeotomaID);
				 UpdatePrimary.Add(L"PRIMARY", dataset_ptr->Publications[i]->Primary);
				 if (UpdatePrimary.Post(ErrorMsg)) {
				   msg = L"Primary status of publication " + dataset_ptr->Publications[i]->GetShortCitation(true) +
						 L" updated to " + ((dataset_ptr->Publications[i]->Primary) ? L"true" : L"false") + L".";
				   OutputLine(msg);
				   }
				 else {
				   OutputError(L"ERROR: " + ErrorMsg);
				   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
				   success = false;
				   return;
				   }
				 }
			   break;
			   }
			 }
		   }
		 }

	   if (AdvColumnGrid1->Cells[1][4] != AdvColumnGrid1->Cells[3][4]) {  // update repositories
		 vector<REPOSITORY>::iterator itr;
		 for (unsigned int i=0; i<dataset_ptr->Repositories.size(); i++) {
		   bool found = false;
		   for (unsigned int j=0; j<ntmdataset.Repositories.size(); j++) {
			 if (dataset_ptr->Repositories[i].RepositoryID == ntmdataset.Repositories[j].RepositoryID) {
			   found = true;
			   break;
			   }
			 }
		   if (!found) {
			 // InsertDatasetRepository (@DATASETID int, @REPOSITORYID int, @NOTES nvarchar(MAX) = null)
			 InsertData InsertDatasetRepository(L"InsertDatasetRepository", 3, ipsHTTPS1, ipsJSONS1, TcpClient1);
			 InsertDatasetRepository.Add(L"DATASETID", dataset_ptr->NeotomaDatasetID, -1);
			 InsertDatasetRepository.Add(L"REPOSITORYID", dataset_ptr->Repositories[i].RepositoryID, -1);
			 InsertDatasetRepository.Add(L"NOTES", dataset_ptr->Repositories[i].SpecimenNotes);
			 StatusBar1->SimpleText = L"InsertDatasetRepository";
			 InsertDatasetRepository.PostData();
			 if (InsertDatasetRepository.Post(ErrorMsg)) {
			   msg = L"Dataset repository uploaded to RepositorySpecimens table: RepositoryID = " +
				 IntToStr(dataset_ptr->Repositories[i].RepositoryID) + L".";
			   OutputLine(msg);
			   }
			 else {
			   OutputError(L"ERROR: " + ErrorMsg);
			   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			   success = false;
			   return;
			   }
			 }
		   }

		 for (unsigned int i=0; i<ntmdataset.Repositories.size(); i++) {
		   bool found = false;
		   for (unsigned int j=0; j<dataset_ptr->Repositories.size(); j++) {
			 if (dataset_ptr->Repositories[j].RepositoryID == ntmdataset.Repositories[i].RepositoryID) {
			   found = true;
			   break;
			   }
			 }
		   if (!found) {
			 // DeleteRepositorySpecimen @DATASETID, @REPOSITORYID
			 DeleteData DeleteRepositorySpec(L"DeleteRepositorySpecimen", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
			 StatusBar1->SimpleText = L"DeleteRepositorySpecimen";
			 DeleteRepositorySpec.Add(L"DATASETID", dataset_ptr->NeotomaDatasetID);
			 DeleteRepositorySpec.Add(L"REPOSITORYID", ntmdataset.Repositories[i].RepositoryID);
			 if (DeleteRepositorySpec.Post(ErrorMsg)) {
			   msg = L"Dataset repository deleted: " + ntmdataset.Repositories[i].Repository;
			   OutputLine(msg);
			   }
			 else
			   {
			   OutputError(L"ERROR: " + ErrorMsg);
			   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			   success = false;
			   return;
			   }
			 }
		   }
		 }

	   // update repository specimen notes
	   if (AdvColumnGrid1->RowCount > 8) {
		 for (int row=8; row<AdvColumnGrid1->RowCount; row++) {
		   UnicodeString Acronym = AdvColumnGrid1->Cells[0][row];
		   int pos = Acronym.Pos(L" ");
		   Acronym = Acronym.SubString(1,pos-1);
		   UnicodeString Notes = AdvColumnGrid1->Cells[1][row];
		   int RepositoryID = -1;
		   for (unsigned int i=0; i<dataset_ptr->Repositories.size(); i++) {
			 if (SameText(dataset_ptr->Repositories[i].Acronym, Acronym)) {
			   RepositoryID = dataset_ptr->Repositories[i].RepositoryID;
			   break;
			   }
			 }

		   if (RepositoryID > -1) {
			 // UpdateDatasetRepositoryNotes](@DATASETID int, @REPOSITORYID int, @NOTES nvarchar(MAX) = null
			 UpdateData UpdateRepositoryNotes(L"UpdateDatasetRepositoryNotes", 3, ipsHTTPS1, ipsJSONS1, TcpClient1);
			 StatusBar1->SimpleText = L"UpdateDatasetRepositoryNotes";
			 UpdateRepositoryNotes.Add(L"DATASETID", dataset_ptr->NeotomaDatasetID);
			 UpdateRepositoryNotes.Add(L"REPOSITORYID", RepositoryID);
			 // if (!Notes.IsEmpty())
			 UpdateRepositoryNotes.Add(L"NOTES", Notes);
			 if (UpdateRepositoryNotes.Post(ErrorMsg)) {
			   msg = L"Specimen notes for repository " + Acronym + L" updated.";
			   OutputLine(msg);
			   }
			 else {
			   OutputError(L"ERROR: " + ErrorMsg);
			   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			   success = false;
			   return;
			   }
			 }
		   }
		 }

	   if (AdvColumnGrid1->Cells[1][5] != AdvColumnGrid1->Cells[3][5]) {  // update processors
		 vector<CONTACT*>::iterator itr;
		 for (unsigned int i=0; i<dataset_ptr->Processors.size(); i++) {
		   itr = find(ntmdataset.Processors.begin(), ntmdataset.Processors.end(), dataset_ptr->Processors[i]);
		   if (itr == ntmdataset.Processors.end()) {  // new processor in dataset_ptr
			 InsertData InsertDataProcessor(L"InsertDataProcessor", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
			 InsertDataProcessor.Add(L"DATASETID", dataset_ptr->NeotomaDatasetID, -1);
			 InsertDataProcessor.Add(L"CONTACTID", dataset_ptr->Processors[i]->NeotomaContactID, -1);
			 StatusBar1->SimpleText = L"InsertDataProcessor";
			 InsertDataProcessor.PostData();
			 if (InsertDataProcessor.Post(ErrorMsg)) {
			   msg = L"Data processor uploaded: " + dataset_ptr->Processors[i]->ShortContactName;
			   OutputLine(msg);
			   }
			 else {
			   OutputError(L"ERROR: " + ErrorMsg);
			   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			   success = false;
			   return;
			   }
			 }
		   }
		 for (unsigned int i=0; i<ntmdataset.Processors.size(); i++) {
		   itr = find(dataset_ptr->Processors.begin(), dataset_ptr->Processors.end(), ntmdataset.Processors[i]);
		   if (itr == dataset_ptr->Processors.end()) {  // delete processor investigator
			 DeleteData DeleteDataProcessor(L"DeleteDataProcessor", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
			 StatusBar1->SimpleText = L"DeleteDataProcessor";
			 DeleteDataProcessor.Add(L"DATASETID", dataset_ptr->NeotomaDatasetID);
			 DeleteDataProcessor.Add(L"CONTACTID", ntmdataset.Processors[i]->NeotomaContactID);
			 if (DeleteDataProcessor.Post(ErrorMsg)) {
			   msg = L"Dataset processor deleted: " + ntmdataset.Processors[i]->ShortContactName;
			   OutputLine(msg);
			   }
			 else
			   {
			   OutputError(L"ERROR: " + ErrorMsg);
			   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			   success = false;
			   return;
			   }
			 }
		   }
		 }

	   // UpdateIsSurfaceSample @DATASETID int, @ISSAMP bit
	   if (AdvColumnGrid1->Cells[1][6] != AdvColumnGrid1->Cells[3][6]) {   // IsSSamp
		 UpdateData UpdateIsSSamp(L"UpdateIsSurfaceSample", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
		 StatusBar1->SimpleText = L"UpdateIsSurfaceSample";
		 UpdateIsSSamp.Add(L"DATASETID", dataset_ptr->NeotomaDatasetID);
		 UpdateIsSSamp.Add(L"ISSAMP", dataset_ptr->IsSSamp);
		 if (UpdateIsSSamp.Post(ErrorMsg)) {
		   if (dataset_ptr->IsSSamp)
			 msg = L"Top sample designated with key word «modern».";
		   else
			 msg = L"Keyword «modern» removed from top sample.";
		   OutputLine(msg);
		   }
		 else {
		   OutputError(L"ERROR: " + ErrorMsg);
		   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   success = false;
		   return;
		   }
		 }

	   if (AdvColumnGrid1->Cells[1][7] != AdvColumnGrid1->Cells[3][7]) {   // Notes
		 UpdateData UpdateDatasetNotes(L"UpdateDatasetNotes", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
		 StatusBar1->SimpleText = L"UpdateDatasetNotes";
		 UpdateDatasetNotes.Add(L"DATASETID", dataset_ptr->NeotomaDatasetID);
		 UpdateDatasetNotes.Add(L"DATASETNOTES", dataset_ptr->Notes);
		 if (UpdateDatasetNotes.Post(ErrorMsg)) {
		   msg = L"Dataset notes updated.";
		   OutputLine(msg);
		   }
		 else {
		   OutputError(L"ERROR: " + ErrorMsg);
		   MessageDlg(ErrorMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   success = false;
		   return;
		   }
		 }
	   }
   __finally {
	   StatusBar1->SimpleText = L"";
	   if (success) {
		 UnicodeString msg = L"Success: Datasest metadata updated!";
		 OutputLine(msg + L" " + DateTimeStr(UTCDateTime()) + L" UTC");
		 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
		 Screen->Cursor = crDefault;
		 cxButton2->Visible = false;
		 }
	   }

   // be sure to update dataset_ptr if necessary
}
//---------------------------------------------------------------------------

void __fastcall TUpdateNeotomaSiteForm::ipsJSONS1SSLServerAuthentication(TObject *Sender,
          TipsJSONSSSLServerAuthenticationEventParams *e)
{
   e->Accept = true;
}
//---------------------------------------------------------------------------

