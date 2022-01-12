//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TINtmSitFrm.h"
#ifndef TINeotomaH
#include "TINeotoma.h"
#endif
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvGrid"
#pragma link "AdvObj"
#pragma link "BaseGrid"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDropDownEdit"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "AdvDropDown"
#pragma link "AdvControlDropDown"
#pragma link "frmctrllink"
#pragma link "cxButtons"
#pragma link "cxMemo"
#pragma link "cxBlobEdit"
#pragma link "cxCheckBox"
#pragma link "cxSpinEdit"
#pragma link "ipwjson"
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
#pragma link "cxRadioGroup"
#pragma link "ipsjsons"
#pragma resource "*.dfm"
TNeotomaSiteForm *NeotomaSiteForm;
TNeotomaSiteMetadataForm* NeotomaSiteMetadataForm;

//---------------------------------------------------------------------------
__fastcall TNeotomaSiteForm::TNeotomaSiteForm(TComponent* Owner)
	: TForm(Owner)
{
   UnicodeString ClassName = Owner->ClassName();
   if (SameText(ClassName, L"TNeotomaUploadForm")) {
	 upf = (TNeotomaUploadForm*)Owner;
	 site_ptr = upf->GetSitePtr();
	 Caption = site_ptr->SiteName;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaSiteForm::FormCreate(TObject *Sender)
{
   FlowPanel1->Left += cxButton5->Width;
   InitializeForm();
}
//---------------------------------------------------------------------------

void TNeotomaSiteForm::InitializeForm(void)
{
   int nsites = -1;
   InitializationSuccess = true;
   if (!SearchSiteName(site_ptr->SiteName, nsites)) {
	 InitializationSuccess = false;
	 return;
	 }
   SearchDistance(10,nsites+1);

   for (int i=0; i<AdvStringGrid1->ColCount; i++)
	 AdvStringGrid1->CellProperties[i][0]->Alignment = taCenter;
   for (int i=0; i<AdvStringGridDataset->ColCount; i++)
	 AdvStringGridDataset->CellProperties[i][0]->Alignment = taCenter;
   for (int i=0; i<AdvStringGridPub->ColCount; i++)
	 AdvStringGridPub->CellProperties[i][0]->Alignment = taCenter;

   AdvStringGrid1->BtnEdit->EditorEnabled = false;
   cxPubMemo->Width = 200;
   cxPubMemo->Height = 100;
   AdvStringGrid1->AddImageIdx(2, 0, 0, Advgrid::haRight, Advgrid::vaCenter);
   AdvStringGrid1->AddImageIdx(4, 0, 0, Advgrid::haRight, Advgrid::vaCenter);
   AdvStringGridDataset->AddImageIdx(2, 0, 0, Advgrid::haRight, Advgrid::vaCenter);
   AdvStringGridDataset->AddImageIdx(3, 0, 0, Advgrid::haRight, Advgrid::vaCenter);
   AdvStringGridPub->AddImageIdx(1, 0, 0, Advgrid::haRight, Advgrid::vaCenter);
}
//---------------------------------------------------------------------------

void TNeotomaSiteForm::DisplaySiteNameStatus(int size, UnicodeString SiteName)
{
   UnicodeString msg1, msg2, msg3;

   RichEdit1->Clear();
   msg1 = (SiteName.Pos(L"%") > 0) ? L"partial" : L"exact";
   msg2 =  L"is the same as the one being validated, click the checkbox in the ";
   msg2 += L"left column, then click the Continue button. ";
   msg3 =  L"see the tools below to ascertain whether the site is already in ";
   msg3 += L"the database, perhaps with a slightly different name. ";
   msg3 += L"If the site is not in Neotoma, check Site is not in Neotoma, ";
   msg3 += L"then click the Continue button.";

   if (size == 0) {
	 RichEdit1->Text = L"No site with the " + msg1 + L" name «" +  SiteName +
	   L"» is in the database. U" + msg3;
	 HighlightText(1, SiteName);
	 HighlightText(1, L"Continue");
	 HighlightText(2, L"Site is not in Neotoma");
	 }
   else if (size == 1) {
	 RichEdit1->Text = L"A site with the " + msg1 + L" name «" + SiteName +
	   L"» is already in the database. If this site " + msg2 +
	   L"If this site is not the same, u" + msg3;
	 HighlightText(1, SiteName);
	 HighlightText(1, L"Continue");
	 HighlightText(2, L"Continue");
	 HighlightText(2, L"Site is not in Neotoma");
	 }
   else {
	 RichEdit1->Text = L"More than one site with the " + msg1 + L" name «" + SiteName +
	   L"» is already in the database. If one of these sites " + msg2 +
	   L"If none of these sites is the same, u" + msg3;
	 HighlightText(1, SiteName);
     HighlightText(1, L"Continue");
	 HighlightText(2, L"Continue");
	 HighlightText(2, L"Site is not in Neotoma");
	 }

}
//---------------------------------------------------------------------------

bool TNeotomaSiteForm::SearchSiteName(UnicodeString SiteName, int& nsites)
{
   bool rv = true;
   bool ShowCount = (nsites > -1);

   Screen->Cursor = crHourGlass;
   if (upf != NULL)
	 upf->SetProgressBar(MARQUEE);

   AdvStringGrid1->ClearNormalCells();
   nsites = 0;

   // escape the '[' character, e.g. Luttersee [[]Lutteranger]
   int len = SiteName.Length();
   int idx = 1;
   while (idx < len) {
	 if (SiteName[idx] == L'[') {
	   SiteName.Insert(L"[]",idx+1);
	   idx += 3;
	   len += 2;
	   }
	 else
	   idx++;
	 }

   NeotomaGeoPolBySiteName SiteNames(ipsJSONS1, TcpClient1);
   SiteNames.AddParam(L"SITENAME", SiteName);
   SiteNames.AddParam(L"EAST", VariantToDouble(site_ptr->LongEast,0.0));
   SiteNames.AddParam(L"NORTH", VariantToDouble(site_ptr->LatNorth,0.0));
   SiteNames.AddParam(L"WEST", VariantToDouble(site_ptr->LongWest,0.0));
   SiteNames.AddParam(L"SOUTH", VariantToDouble(site_ptr->LatSouth,0.0));

   StatusBar1->SimpleText = SiteNames.WebServiceName();
   if (SiteNames.Execute()) {
	 if (SiteNames.Size() > 0) {
	   int row = 1;
	   AdvStringGrid1->RowCount = SiteNames.Size() + 1;
	   for (unsigned int i=0; i<SiteNames.Size(); i++) {
		   if (ShowCount)
			 RichEdit1->Text = L"Sites found: " + IntToStr(row);
		   AdvStringGrid1->Cells[1][row] = SiteNames.Items[i].SiteID;
		   AdvStringGrid1->Cells[2][row] = SiteNames.Items[i].SiteName;
		   AdvStringGrid1->Cells[3][row] = FormatDist(SiteNames.Items[i].DistKm);
		   AdvStringGrid1->Cells[4][row] = SiteNames.Items[i].Geopolitical;
		   row++;
		 }
	   AdvStringGrid1->RowCount = row;
	   for (int i=1; i<AdvStringGrid1->RowCount; i++)
		 AdvStringGrid1->AddCheckBox(0, i, false, false);

	   AdvStringGrid1->Row = 1;
	   Datasets.clear();
	   int SiteID = AdvStringGrid1->Cells[1][1].ToInt();
	   if (upf != NULL)
	     GetSiteDatasets(SiteID, &Datasets);
	   nsites = (int)SiteNames.Size();
	   }
	 else {  // no sites
	   AdvStringGrid1->RowCount = 2;
	   }
	 }
   else
	 rv = false;

   Screen->Cursor = crDefault;
   if (upf != NULL)
	 upf->SetProgressBar(CORE);
   StatusBar1->SimpleText = L"";
   return rv;
}
//---------------------------------------------------------------------------

// distance search
void __fastcall TNeotomaSiteForm::cxButton2Click(TObject *Sender)
{
   double km = cxSpinEdit1->EditValue;
   SearchDistance(km,1);
}
//---------------------------------------------------------------------------

void TNeotomaSiteForm::SearchDistance(double km, int StartRow)
{
   double dist;
   Screen->Cursor = crHourGlass;
   if (upf != NULL)
     upf->SetProgressBar(MARQUEE);
   AdvStringGrid1->Row = 1;
   if (StartRow == 1)
	 AdvStringGrid1->ClearNormalCells();
   int nsites = 0;

   set<UnicodeString> ExistingSites;
   if (StartRow > 1) {
	 for (int row = 1; row < StartRow; row++)
	   ExistingSites.insert(AdvStringGrid1->Cells[2][row]);
	 }

   NeotomaNearestSites NearestSites(ipsJSONS1, TcpClient1);
   NearestSites.AddParam(L"EAST", VariantToDouble(site_ptr->LongEast,0.0));
   NearestSites.AddParam(L"NORTH", VariantToDouble(site_ptr->LatNorth,0.0));
   NearestSites.AddParam(L"WEST", VariantToDouble(site_ptr->LongWest,0.0));
   NearestSites.AddParam(L"SOUTH", VariantToDouble(site_ptr->LatSouth,0.0));
   NearestSites.AddParam(L"DISTKM", km);
   StatusBar1->SimpleText = NearestSites.WebServiceName();
   if (NearestSites.Execute()) {
	 if (NearestSites.Size() > 0) {
	   nsites = NearestSites.Size();
	   int row = StartRow;
	   // AdvStringGrid1->RowCount = nsites + StartRow;
	   for (int i=0; i<nsites; i++) {
		 if (ExistingSites.count(NearestSites.Items[i].SiteName) == 0) {
		   AdvStringGrid1->Cells[3][row] = FormatDist(NearestSites.Items[i].DistKm);
		   // RichEdit1->Text = L"Sites found: " + IntToStr(nsites);
		   AdvStringGrid1->Cells[1][row] = NearestSites.Items[i].SiteID;
		   AdvStringGrid1->Cells[2][row] = NearestSites.Items[i].SiteName;
		   AdvStringGrid1->Cells[3][row] = FormatDist(NearestSites.Items[i].DistKm);
		   AdvStringGrid1->Cells[4][row] = NearestSites.Items[i].Geopolitical;
		   row++;
		   }
		 }
	   RichEdit1->Text = L"Sites found: " + IntToStr(row-1);
	   AdvStringGrid1->RowCount = row;
	   for (int i=1; i<AdvStringGrid1->RowCount; i++)
		 AdvStringGrid1->AddCheckBox(0, i, false, false);
	   }

	 UnicodeString skm = cxSpinEdit1->EditValue;
	 RichEdit1->Clear();
	 UnicodeString Text;
	 if (nsites == 0) {
	   Text =  L"No sites occur within " + skm + L" km.";
	   Text += L" Use the tools below to ascertain whether the site is already in the database, ";
	   Text += L"perhaps with a slightly different name. ";
	   Text += L"If the site is not in Neotoma, check Site is not in Neotoma, ";
	   Text += L"then click the Continue button.";
	   RichEdit1->Text = Text;
	   HighlightText(2, L"Site is not in Neotoma");
	   HighlightText(1, L"Continue");
	   }
	 else if (nsites == 1) {
	   Text =  L"One site occurs within " + skm + L" km. ";
	   Text += L"If this site is the same as the one being validated, ";
	   Text += L"click the checkbox in the left column, then click the Continue button. ";
	   Text += L"If this site is not the same, use the tools below to ascertain ";
	   Text += L"whether the site is already in the database, perhaps with a slightly different name. ";
	   Text += L"If the site is not in Neotoma, check Site is not in Neotoma, ";
	   Text += L"then click the Continue button.";
	   RichEdit1->Text = Text;
	   HighlightText(1, L"Continue");
	   HighlightText(2, L"Continue");
	   HighlightText(2, L"Site is not in Neotoma");
	   }
	 else {
	   Text  =  IntToStr(nsites) + L" sites occur within " + skm + L" km. ";
	   Text += L"If one of these sites is the same as the one being validated, ";
	   Text += L"click the checkbox in the left column, then click the Continue button. ";
	   Text += L"If none of these sites is the same, use the tools below to ascertain ";
	   Text += L"whether the site is already in the database, perhaps with a slightly different name. ";
	   Text += L"If the site is not in Neotoma, check Site is not in Neotoma, ";
	   Text += L"then click the Continue button.";
	   RichEdit1->Text = Text;
	   HighlightText(1, L"Continue");
	   HighlightText(2, L"Continue");
	   HighlightText(2, L"Site is not in Neotoma");
	   }
	 }

   Screen->Cursor = crDefault;
   if (upf != NULL)
     upf->SetProgressBar(CORE);
   StatusBar1->SimpleText = L"";
}
//---------------------------------------------------------------------------

UnicodeString TNeotomaSiteForm::FormatDist(double dist)
{
   UnicodeString formatted;
   if (dist == 0.0)
	 formatted = L"0";
   else if (dist > 1.0)
	 formatted = FormatFloat(L"0.0", dist);
   else if (dist > 0.001)
	 formatted = FormatFloat(L"0.000", dist);
   else
	 formatted = FormatFloat(L"0.#######", dist);
   return formatted;
}
//---------------------------------------------------------------------------

//SITEDATASET
bool TNeotomaSiteForm::GetSiteDatasets(int SiteID, vector<SITEDATASET>* SiteDatasets)
{
   bool rv = true;

   NeotomaSiteDatasets NtmSiteDatasets(ipsJSONS1, TcpClient1);
   NtmSiteDatasets.AddParam(L"SITEID", SiteID);
   StatusBar1->SimpleText = NtmSiteDatasets.WebServiceName();
   Screen->Cursor = crHourGlass;
   if (NtmSiteDatasets.Execute()) {
	 if (NtmSiteDatasets.Size() > 0) {
	   for (unsigned int i=0; i<NtmSiteDatasets.Size(); i++) {
		 UnicodeString DatasetType = NtmSiteDatasets.Items[i].DatasetType;
		 if (!SameText(DatasetType, L"geochronologic")) {
		   SITEDATASET Dataset;
		   Dataset.DatasetID = NtmSiteDatasets.Items[i].DatasetID;
		   Dataset.DatasetType = NtmSiteDatasets.Items[i].DatasetType;
		   if (!GetDatasetPIs(Dataset)) {
			 rv = mrAbort;
			 break;
			 }
		   if (!GetDatasetPubs(Dataset)) {
			 rv = mrAbort;
			 break;
			 }
		   SiteDatasets->push_back(Dataset);
		   }
		 }
	   }
	 }
   else
	 rv = false;

   Screen->Cursor = crDefault;
   StatusBar1->SimpleText = L"";
   return rv;
}
//---------------------------------------------------------------------------

bool TNeotomaSiteForm::GetDatasetPIs(SITEDATASET& Dataset)
{
   bool rv = false;

   Screen->Cursor = crHourGlass;
   NeotomaDatasetPIs NtmDatasetPIs(ipsJSONS1, TcpClient1);
   NtmDatasetPIs.AddParam(L"DATASETID", Dataset.DatasetID);
   StatusBar1->SimpleText = NtmDatasetPIs.WebServiceName();
   if (NtmDatasetPIs.Execute()) {
	 if (NtmDatasetPIs.Size() > 0) {
	   for (unsigned int i=0; i<NtmDatasetPIs.Size(); i++) {
		 DATASETPI DatasetPI;
		 DatasetPI.PIOrder = NtmDatasetPIs.Items[i].PIOrder;
		 DatasetPI.PIName = NtmDatasetPIs.Items[i].FamilyName;
		 DatasetPI.PIName += L", ";
		 DatasetPI.PIName += NtmDatasetPIs.Items[i].LeadingInitials;
		 Dataset.DatasetPIs.push_back(DatasetPI);
		 }
	   if (Dataset.DatasetPIs.size() > 1)
		 sort(Dataset.DatasetPIs.begin(), Dataset.DatasetPIs.end(), DatasetPIComp);
	   }
	 rv = true;
	 }
   StatusBar1->SimpleText = L"";
   Screen->Cursor = crDefault;
   return rv;
}
//---------------------------------------------------------------------------

bool TNeotomaSiteForm::GetDatasetPubs(SITEDATASET& Dataset)
{
   bool rv = false;

   Screen->Cursor = crHourGlass;
   NeotomaDatasetPubs NtmDatasetPubs(ipsJSONS1, TcpClient1);
   NtmDatasetPubs.AddParam(L"DATASETID", Dataset.DatasetID);
   StatusBar1->SimpleText = NtmDatasetPubs.WebServiceName();
   if (NtmDatasetPubs.Execute()) {
	 if (NtmDatasetPubs.Size() > 0) {
	   for (unsigned int i=0; i<NtmDatasetPubs.Size(); i++) {
		 DATASETPUB DatasetPub;
		 DatasetPub.PrimaryPub = false;
		 if (NtmDatasetPubs.Items[i].PrimaryPub.Type() == varBoolean)
		   DatasetPub.PrimaryPub = NtmDatasetPubs.Items[i].PrimaryPub;
		 DatasetPub.PublicationID = NtmDatasetPubs.Items[i].PublicationID;
		 DatasetPub.Citation = NtmDatasetPubs.Items[i].Citation;
		 Dataset.DatasetPubs.push_back(DatasetPub);
		 }
	   }
	 rv = true;
	 }
   StatusBar1->SimpleText = L"";
   Screen->Cursor = crDefault;
   return rv;
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaSiteForm::AdvStringGrid1GetEditorType(TObject *Sender, int ACol,
		  int ARow, TEditorType &AEditor)
{
   switch (ACol) {
	 case 2:
	   AEditor = edCustom;
	   AdvStringGrid1->EditLink = FormControlEditLinkDataset;
	   break;
	 case 4:
	   AEditor = edCustom;
	   AdvStringGrid1->EditLink = FormControlEditLinkGeoPol;
	   break;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaSiteForm::AdvStringGrid1RowChanging(TObject *Sender, int OldRow,
		  int NewRow, bool &Allow)
{
   Datasets.clear();
   int SiteID = AdvStringGrid1->Cells[1][NewRow].ToInt();
   GetSiteDatasets(SiteID, &Datasets);
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaSiteForm::AdvStringGrid1GetEditorProp(TObject *Sender, int ACol,
		  int ARow, TEditLink *AEditLink)
{
   int SiteID, Height, idx;
   int size, OldRowCount, NewRowCount;

   switch (ACol) {   // site name column, dataset dropdown
	 case 2:
	   AdvStringGridDataset->ClearNormalCells();
	   size = Datasets.size();
	   OldRowCount = AdvStringGridDataset->RowCount;
	   NewRowCount = size + 1;
	   AdjustStringGridRowCount(AdvStringGridDataset, OldRowCount, NewRowCount);
	   Height = (1+Datasets.size()) * (1+AdvStringGridDataset->DefaultRowHeight) + 1;
	   Height += AdvControlDropDownDataset->DropDownHeader->Height;
	   Height += AdvControlDropDownDataset->DropDownFooter->Height;
	   AdvControlDropDownDataset->DropDownHeight = Height + 2;

	   for (unsigned int i=0, row=1; i<Datasets.size(); i++, row++) {
		 AdvStringGridDataset->Cells[0][row] = Datasets[i].DatasetID;
		 AdvStringGridDataset->Cells[1][row] = Datasets[i].DatasetType;
		 UnicodeString PIs;
		 for (unsigned int j = 0; j<Datasets[i].DatasetPIs.size(); j++) {
		   if (j > 0) PIs += L"|";
		   PIs += Datasets[i].DatasetPIs[j].PIName;
		   }
		 if (PIs.IsEmpty())
		   PIs = L"null";
		 AdvStringGridDataset->Cells[2][row] = PIs;

		 UnicodeString PubIDs;
		 for (unsigned int j=0; j<Datasets[i].DatasetPubs.size(); j++) {
		   if (j > 0) PubIDs += L", ";
		   PubIDs += IntToStr(Datasets[i].DatasetPubs[j].PublicationID);
		   }
		 if (PubIDs.IsEmpty()) {
		   PubIDs = L"null";
		   }
		 AdvStringGridDataset->Cells[3][row] = PubIDs;
		 AdvStringGridDataset->Alignments[3][row] = taLeftJustify;
		 }
	   break;
	 case 4:
	   AdvStringGridGeoPol->Clear();
	   vector<UnicodeString> GeoPolUnits;
	   UnicodeString GeoPolStr = AdvStringGrid1->Cells[ACol][ARow];
	   int idx = GeoPolStr.Pos(L"|");
	   while (idx > 0) {
		 GeoPolUnits.push_back(GeoPolStr.SubString(1,idx-1));
		 GeoPolStr.Delete(1,idx);
		 idx = GeoPolStr.Pos(L"|");
		 }
	   GeoPolUnits.push_back(GeoPolStr);

	   AdjustStringGridRowCount(AdvStringGridGeoPol, AdvStringGridGeoPol->RowCount, GeoPolUnits.size());

	   AdvStringGridGeoPol->Width = AdvStringGrid1->ColWidths[4];
	   Height = GeoPolUnits.size() * (1+AdvStringGridGeoPol->DefaultRowHeight) + 1;
	   Height += AdvControlDropDownGeoPol->DropDownHeader->Height;
	   Height += AdvControlDropDownGeoPol->DropDownFooter->Height;
	   AdvControlDropDownGeoPol->DropDownHeight = Height + 2;

	   for (unsigned int i=0; i<GeoPolUnits.size(); i++)
		 AdvStringGridGeoPol->Cells[0][i] = GeoPolUnits[i];
	   break;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaSiteForm::AdvStringGridDatasetGetEditorType(TObject *Sender, int ACol,
		  int ARow, TEditorType &AEditor)
{
   switch (ACol) {
	 case 2:
	   AEditor = edCustom;
	   AdvStringGridDataset->EditLink = FormControlEditLinkPI;
	   break;
	 case 3:
	   AEditor = edCustom;
	   AdvStringGridDataset->EditLink = FormControlEditLinkPub;
	   break;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaSiteForm::AdvStringGridDatasetGetEditorProp(TObject *Sender, int ACol,
		  int ARow, TEditLink *AEditLink)
{
   int Height;

   if (ACol == 2) {    // PIs
	 int DatasetID = AdvStringGridDataset->Cells[0][ARow].ToInt();
	 for (unsigned int i=0; i<Datasets.size(); i++) {
	   if (DatasetID == Datasets[i].DatasetID) {
		 unsigned int nPIs = Datasets[i].DatasetPIs.size();
		 if (nPIs > 0) {
		   AdvStringGridPI->Clear();
		   AdjustStringGridRowCount(AdvStringGridPI, AdvStringGridPI->RowCount, nPIs);
		   AdvStringGridPI->Height = nPIs*(1+AdvStringGridPI->DefaultRowHeight) + 2;
		   for (unsigned int j=0; j<nPIs; j++)
			 AdvStringGridPI->Cells[0][j] = Datasets[i].DatasetPIs[j].PIName;
		   }
		 break;
		 }
	   }
	 }
   else if (ACol == 3) {  // Pubs
	 int DatasetID = AdvStringGridDataset->Cells[0][ARow].ToInt();
	 for (unsigned int i=0; i<Datasets.size(); i++) {
	   if (DatasetID == Datasets[i].DatasetID) {
		 unsigned int nPubs = Datasets[i].DatasetPubs.size();
		 if (nPubs > 0) {
		   AdvStringGridPub->ClearNormalCells();
		   AdjustStringGridRowCount(AdvStringGridPub, AdvStringGridPub->RowCount, nPubs+1);
		   AdvStringGridPub->Height = (1+nPubs)*(1+AdvStringGridPub->DefaultRowHeight) + 2;
		   for (unsigned int j=0, row=1; j<nPubs; j++, row++) {
			 AdvStringGridPub->Cells[0][row] = IntToStr(Datasets[i].DatasetPubs[j].PublicationID);
			 AdvStringGridPub->Cells[1][row] = Datasets[i].DatasetPubs[j].Citation;
			 }
		   }
		 break;
		 }
	   }

	 // TODO: write null if nothing
	 }
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaSiteForm::AdvStringGridPubGetEditorType(TObject *Sender, int ACol,
		  int ARow, TEditorType &AEditor)
{
   if (ACol == 1) {
	 AEditor = edCustom;
	 AdvStringGridPub->EditLink = FormControlEditLinkPubMemo;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaSiteForm::AdvStringGridPubGetEditorProp(TObject *Sender, int ACol,
		  int ARow, TEditLink *AEditLink)
{
   if (ACol == 1) {
	 cxPubMemo->Text = AdvStringGridPub->Cells[ACol][ARow];
	 }
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaSiteForm::AdvStringGrid1CheckBoxChange(TObject *Sender, int ACol,
		  int ARow, bool State)
{
   // uncheck all other rows
   if (State) {
	 bool state;
	 for (int row=1; row<AdvStringGrid1->RowCount; row++) {
	   if (row == ARow) continue;
	   AdvStringGrid1->GetCheckBoxState(0, row, state);
	   if (state)
		 AdvStringGrid1->SetCheckBoxState(0, row, false);
	   }
	 cxRadioButton1->Enabled = true;
	 cxRadioButton1->Checked = true;
	 }
   else {
	 cxRadioButton2->Checked = true;
	 cxRadioButton1->Enabled = false;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaSiteForm::cxRadioButton2Click(TObject *Sender)
{
   if (cxRadioButton2->Checked) {
	 AdvStringGrid1->UnCheckAll(0);
	 cxRadioButton1->Enabled = false;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaSiteForm::AdvStringGrid1CanEditCell(TObject *Sender, int ARow,
		  int ACol, bool &CanEdit)
{
   if (AdvStringGrid1->Cells[1][1].IsEmpty())
	 CanEdit = false;
   else if (ACol == 1 || ACol == 3)
	 CanEdit = false;
   else
	 CanEdit = true;
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaSiteForm::AdvStringGridDatasetCanEditCell(TObject *Sender, int ARow,
		  int ACol, bool &CanEdit)
{
  if (ARow == 0)
	CanEdit = false;
  else if (ACol <= 1)
	CanEdit = false;
  else if (ACol >= 2)   // PI column
	CanEdit = (AdvStringGridDataset->Cells[ACol][ARow] != L"null");
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaSiteForm::AdvStringGridPubCanEditCell(TObject *Sender, int ARow,
		  int ACol, bool &CanEdit)
{
   CanEdit = (ACol == 1);
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaSiteForm::FormControlEditLinkGeoPolGetEditorValue(TObject *Sender,
          TAdvStringGrid *Grid, UnicodeString &AValue)
{
   AValue = AdvControlDropDownGeoPol->Text;
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaSiteForm::FormControlEditLinkGeoPolSetEditorValue(TObject *Sender,
		  TAdvStringGrid *Grid, UnicodeString AValue)
{
   AdvControlDropDownGeoPol->Text = AValue;
}
//---------------------------------------------------------------------------

// gets value from the datasets dropdown editor after dropping up
void __fastcall TNeotomaSiteForm::FormControlEditLinkDatasetGetEditorValue(TObject *Sender,
		  TAdvStringGrid *Grid, UnicodeString &AValue)
{
   //TODO: deal with possiblity of no datasets
   AValue = AdvControlDropDownDataset->Text;
}
//---------------------------------------------------------------------------

// sets the value in the editor for the datasets dropdown
void __fastcall TNeotomaSiteForm::FormControlEditLinkDatasetSetEditorValue(TObject *Sender,
		  TAdvStringGrid *Grid, UnicodeString AValue)
{
   AdvControlDropDownDataset->Text = AValue;
}
//---------------------------------------------------------------------------

// control is AdvControlDropDown3, which contains AdvStringGridPI (for PI)
void __fastcall TNeotomaSiteForm::FormControlEditLinkPIGetEditorValue(TObject *Sender,
		  TAdvStringGrid *Grid, UnicodeString &AValue)
{
   //TODO: what if no PI?
   int ACol = AdvStringGrid1->Col;
   int ARow = AdvStringGrid1->Row;
   unsigned int idx = AdvStringGridDataset->Row - 1;

   UnicodeString PIs;

   unsigned int nPIs = Datasets[idx].DatasetPIs.size();
   if (nPIs > 0) {
	 for (unsigned int j=0; j<nPIs; j++) {
	   if (j > 0) PIs += L"|";
	   PIs += Datasets[idx].DatasetPIs[j].PIName;
	   }
	 }
   if (PIs.IsEmpty()) {
	 PIs = L"null";
	 }
   AValue = PIs;
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaSiteForm::FormControlEditLinkPISetEditorValue(TObject *Sender,
		  TAdvStringGrid *Grid, UnicodeString AValue)
{
   // set editor to list of PIs
   AdvControlDropDownPI->Text = AValue;
}
//---------------------------------------------------------------------------

// gets value from the publications dropdown editor after dropping up
void __fastcall TNeotomaSiteForm::FormControlEditLinkPubGetEditorValue(TObject *Sender,
		  TAdvStringGrid *Grid, UnicodeString &AValue)
{
   int ACol = AdvStringGrid1->Col;
   int ARow = AdvStringGrid1->Row;
   unsigned int idx = AdvStringGridDataset->Row - 1;

   UnicodeString PubIDs;

   unsigned int nPubs = Datasets[idx].DatasetPubs.size();
   if (nPubs > 0) {
	 for (unsigned int j=0; j<nPubs; j++) {
	   if (j > 0) PubIDs += L", ";
	   int PubID = Datasets[idx].DatasetPubs[j].PublicationID;
	   PubIDs += IntToStr(PubID);
	   }
	 }
   if (PubIDs.IsEmpty()) {
	 PubIDs = L"null";
	 }
   AValue = PubIDs;
}
//---------------------------------------------------------------------------

// sets the value in the editor for the publications dropdown
void __fastcall TNeotomaSiteForm::FormControlEditLinkPubSetEditorValue(TObject *Sender,
		  TAdvStringGrid *Grid, UnicodeString AValue)
{
   AdvControlDropDownPub->Text = AValue;
}
//---------------------------------------------------------------------------

// gets value from the publication dropdown editor after dropping up
void __fastcall TNeotomaSiteForm::FormControlEditLinkPubMemoGetEditorValue(TObject *Sender,
		  TAdvStringGrid *Grid, UnicodeString &AValue)
{
   AValue = cxPubMemo->Text;
}
//---------------------------------------------------------------------------

// sets the value in the editor for the publication dropdown memo
void __fastcall TNeotomaSiteForm::FormControlEditLinkPubMemoSetEditorValue(TObject *Sender,
		  TAdvStringGrid *Grid, UnicodeString AValue)
{
   AdvControlDropDownPubMemo->Text = AValue;
}
//---------------------------------------------------------------------------

void TNeotomaSiteForm::AdjustStringGridRowCount(TAdvStringGrid* Grid, int OldRowCount, int NewRowCount)
{
   if (NewRowCount != OldRowCount) {
	 Grid->BeginUpdate();
	 if (NewRowCount > OldRowCount)
	   Grid->InsertRows(OldRowCount-1, NewRowCount-OldRowCount, false);
	 else if (NewRowCount < OldRowCount)
	   Grid->RemoveRows(1, OldRowCount-NewRowCount);
	 Grid->EndUpdate();
	 }
}
//---------------------------------------------------------------------------

// name search
void __fastcall TNeotomaSiteForm::cxButton1Click(TObject *Sender)
{
   int nsites = 0;
   AdvStringGrid1->Row = 1;
   SearchSiteName(LabeledEdit1->Text, nsites);
   DisplaySiteNameStatus(nsites, LabeledEdit1->Text);
}
//---------------------------------------------------------------------------

void TNeotomaSiteForm::HighlightText(int position, UnicodeString Text)
{
   int pos;
   int StartPos = 0;
   int occurrence = 1;
   int TextLen = Text.Length();
   while (occurrence <= position) {
	 pos = RichEdit1->FindText(Text, StartPos, RichEdit1->Text.Length()-StartPos, TSearchTypes());
	 StartPos += (pos + TextLen);
	 occurrence++;
	 }

   RichEdit1->SelStart = pos;
   RichEdit1->SelLength = TextLen;
   TTextAttributes* tattrib = RichEdit1->SelAttributes;
   tattrib->Style = tattrib->Style << fsBold;
   tattrib->Color = clNavy;
}
//---------------------------------------------------------------------------

bool TNeotomaSiteForm::GetSiteGeoPolUnits(int SiteID, TStringList* GeoPolList)
{
   bool rv = true;

   GeoPolUnitsBySiteID SiteGeoPolUnits(ipsJSONS1, TcpClient1);
   SiteGeoPolUnits.AddParam(L"SITEID", SiteID);
   StatusBar1->SimpleText = SiteGeoPolUnits.WebServiceName();
   Screen->Cursor = crHourGlass;
   if (SiteGeoPolUnits.Execute()) {
	 if (SiteGeoPolUnits.Size() > 0) {
	   for (unsigned int i=0; i<SiteGeoPolUnits.Size(); i++)
		 GeoPolList->Add(SiteGeoPolUnits.Items[i].GeoPoliticalName);
	   }
	 }
   else
	 rv = false;

   Screen->Cursor = crDefault;
   return rv;
}
//---------------------------------------------------------------------------

// Continue button
void __fastcall TNeotomaSiteForm::cxButton3Click(TObject *Sender)
{
   NeotomaSiteID = -1;
   if (cxRadioButton1->Checked) {
	 bool state;
	 for (int row=1; row<AdvStringGrid1->RowCount; row++) {
	   AdvStringGrid1->GetCheckBoxState(0, row, state);
	   if (state) {
		 NeotomaSiteID = AdvStringGrid1->Cells[1][row].ToInt();
		 break;
		 }
	   }
	 if (NeotomaSiteID == -1) {
	   UnicodeString msg = L"No site selected and \"Site is not in Neotoma\" is not checked.";
	   if (MessageDlg(msg, mtWarning, TMsgDlgButtons() << mbRetry << mbCancel, 0) == mrRetry)
		 ModalResult = mrNone;
	   else
		 ModalResult = mrCancel;
	   }
	 }
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaSiteForm::AdvStringGrid1CellValidate(TObject *Sender, int ACol,
          int ARow, UnicodeString &Value, bool &Valid)
{
   Valid = false;  // this prevents any manual changes to the grid
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaSiteForm::AdvStringGrid1GetAlignment(TObject *Sender, int ARow,
		  int ACol, TAlignment &HAlign, TVAlignment &VAlign)
{
   if (ACol == 0)
	 HAlign = taCenter;
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaSiteForm::cxButton5Click(TObject *Sender)
{
   return;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

_fastcall TNeotomaSiteMetadataForm::TNeotomaSiteMetadataForm(SITE* siteptr, TComponent* Owner)
	: TNeotomaSiteForm(Owner)
{
   TSSForm = (TTilSpreadSheetForm*)Owner;
   upf = NULL;
   site_ptr = siteptr;
   Caption = site_ptr->SiteName;
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaSiteMetadataForm::FormCreate(TObject *Sender)
{
   cxRadioButton1->Visible = false;
   cxRadioButton2->Visible = false;
   cxButton3->Visible = false;
   cxButton5->Visible = true;
   FlowPanel1->Left = (Panel2->Width - cxButton5->Width - cxButton4->Width)/2;
   InitializeForm();
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaSiteMetadataForm::AdvStringGrid1CheckBoxChange(TObject *Sender, int ACol,
		  int ARow, bool State)
{
   // uncheck all other rows
   if (State) {
	 bool state;
	 for (int row=1; row<AdvStringGrid1->RowCount; row++) {
	   if (row == ARow) continue;
	   AdvStringGrid1->GetCheckBoxState(0, row, state);
	   if (state)
		 AdvStringGrid1->SetCheckBoxState(0, row, false);
	   }
	 }
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaSiteMetadataForm::AdvStringGrid1RowChanging(TObject *Sender, int OldRow,
		  int NewRow, bool &Allow)
{
   return;
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaSiteMetadataForm::cxButton5Click(TObject *Sender)
{
   UnicodeString SiteName;
   NeotomaSiteID = -1;
   bool state;
   for (int row=1; row<AdvStringGrid1->RowCount; row++) {
	 AdvStringGrid1->GetCheckBoxState(0, row, state);
	 if (state) {
	   NeotomaSiteID = AdvStringGrid1->Cells[1][row].ToInt();
	   SiteName = AdvStringGrid1->Cells[2][row];
	   break;
	   }
	 }

   if (NeotomaSiteID != -1) {
	 UnicodeString msg = L"Update Tilia with Neotoma site metadata from " + SiteName + L"?";
	 if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes) {
	   if (TSSForm->GetNeotomaSite(NeotomaSiteID, site_ptr, NULL))
		 ModalResult = mrOk;
	   }
	 }
}
//---------------------------------------------------------------------------

void __fastcall TNeotomaSiteForm::ipsJSONS1SSLServerAuthentication(TObject *Sender,
          TipsJSONSSSLServerAuthenticationEventParams *e)
{
   e->Accept = true;
}
//---------------------------------------------------------------------------

