//---------------------------------------------------------------------------
#include <vcl.h>
#include "pch.h"
#pragma hdrstop

#include "TISynonym.h"
#ifndef TINeotomaH
#include "TINeotoma.h"
#endif
#ifndef TIJSONH
#include "TIJSON.h"
#endif
#ifndef TNUtilsH
#include "TNUtils.h"
#endif

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxBlobEdit"
#pragma link "cxCheckBox"
#pragma link "cxClasses"
#pragma link "cxControls"
#pragma link "cxCustomData"
#pragma link "cxData"
#pragma link "cxDataStorage"
#pragma link "cxDropDownEdit"
#pragma link "cxEdit"
#pragma link "cxFilter"
#pragma link "cxGraphics"
#pragma link "cxGrid"
#pragma link "cxGridCustomTableView"
#pragma link "cxGridCustomView"
#pragma link "cxGridLevel"
#pragma link "cxGridTableView"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxNavigator"
#pragma link "cxStyles"
#pragma link "cxButtons"
#pragma link "cxBlobEdit"
#pragma link "cxButtons"
#pragma link "cxCheckBox"
#pragma link "cxClasses"
#pragma link "cxControls"
#pragma link "cxCustomData"
#pragma link "cxData"
#pragma link "cxDataStorage"
#pragma link "cxDropDownEdit"
#pragma link "cxEdit"
#pragma link "cxFilter"
#pragma link "cxGraphics"
#pragma link "cxGrid"
#pragma link "cxGridCustomTableView"
#pragma link "cxGridCustomView"
#pragma link "cxGridLevel"
#pragma link "cxGridTableView"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxNavigator"
#pragma link "cxStyles"
#pragma link "ipwjson"
#pragma link "ipshttps"
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
#pragma link "dxSkinscxPCPainter"
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
TSynonymForm *SynonymForm;
//---------------------------------------------------------------------------
__fastcall TSynonymForm::TSynonymForm(TAXON_NOTES* edit_taxon_notes, TPoint& pos,
	TComponent* Owner) : TForm(Owner)
{
   TSSForm = (TTilSpreadSheetForm*)Owner;
   Position = pos;

   Caption = L"Synonyms | " + TSSForm->ProfGrid1->AbsoluteCells[2][TSSForm->ProfGrid1->Row]->Text;

   EditTaxonNotes = edit_taxon_notes;
   EditSynonymy = new TSynonymy(EditTaxonNotes->Synonymy);
   SynonymyDataSource = new TSynonymyDataSource(EditSynonymy);

   synName->DataBinding->Data = (TObject*)IndexOfsynName;
   synContrib->DataBinding->Data = (TObject*)IndexOfsynContrib;
   synPub->DataBinding->Data = (TObject*)IndexOfsynPub;
   synNotes->DataBinding->Data = (TObject*)IndexOfsynNotes;
   // this line is critical
   cxGrid5TableView1->DataController->CustomDataSource = SynonymyDataSource;

   TcxComboBoxProperties* SynTaxaList = (TcxComboBoxProperties*)(synName->Properties);
   SynTaxaList->Items->BeginUpdate();
   SynTaxaList->Items->Clear();
   for (unsigned int i=0; i<TSSForm->TaxaList.size(); i++)
	 SynTaxaList->Items->Add(TSSForm->TaxaList[i].Name);
   map<UnicodeString, int>::iterator itr;
   for (itr=TSSForm->Synonyms.begin(); itr != TSSForm->Synonyms.end(); itr++)
	 SynTaxaList->Items->Add(itr->first);
   SynTaxaList->Sorted = true;
   SynTaxaList->Items->EndUpdate();

   TStrings* ComboBoxItems =
	 (TStrings*)(((TcxCustomComboBoxProperties*)(synPub->Properties))->Items);
   TSSForm->UpdatePublications(ComboBoxItems, EditSynonymy->Publications);

   int DatasetIdx;
   // if (TSSForm->ValidateSteward(NeotomaVariableID, DatasetIdx)) {
   if (TSSForm->ValidateSteward(DatasetIdx)) {
	 NeotomaVariableID = TSSForm->GetSSDownloadVariableID(TSSForm->ProfGrid1->Row);
	 if (NeotomaVariableID != -1) {
	   NeotomaDatasetID = TSSForm->Datasets[DatasetIdx].NeotomaDatasetID;
	   cxButton3->Visible = true;
	   FlowPanel1->Left = (Panel1->Width - 3*cxButton1->Width)/2;
	   }
	 }
}
//---------------------------------------------------------------------------

void __fastcall TSynonymForm::FormActivate(TObject *Sender)
{
   Left = Position.X;
   Top = Position.Y;
}
//---------------------------------------------------------------------------

void __fastcall TSynonymForm::FormClose(TObject *Sender, TCloseAction &Action)
{
   delete EditSynonymy;
   delete SynonymyDataSource;
}
//---------------------------------------------------------------------------

// Ok button
void __fastcall TSynonymForm::cxButton1Click(TObject *Sender)
{
   EditTaxonNotes->Synonymy.clear();
   EditTaxonNotes->Synonymy = EditSynonymy->Synonyms;
}
//---------------------------------------------------------------------------

// update Neotoma
void __fastcall TSynonymForm::cxButton3Click(TObject *Sender)
{
   UnicodeString msg;

   // check that NeotomaPubID's exist for all publications
   for (unsigned int j=0; j<EditSynonymy->Synonyms.size(); j++) {
	 SYNONYMY& Synonymy = EditSynonymy->Synonyms[j];
	 if (Synonymy.Pub != NULL) {
	   int NeotomaPubID = Synonymy.NeotomaPubID();
	   if (NeotomaPubID == -1) {
		 msg = L"Neotoma PublicationID not acquired for «" + Synonymy.Pub->GetShortCitation(true) + L"»";
		 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 return;
	     }
	   }
	 }

   // get synonymy for current dataset and variable
   NeotomaDatasetVariableSynonyms DatasetVarSynonyms(ipsJSONS1, TcpClient1);
   DatasetVarSynonyms.AddParam(L"DATASETID", NeotomaDatasetID);
   DatasetVarSynonyms.AddParam(L"VARIABLEID", NeotomaVariableID);
   StatusBar1->SimpleText = DatasetVarSynonyms.WebServiceName();
   if (!DatasetVarSynonyms.Execute()) {
	 StatusBar1->SimpleText = L"";
	 return;
	 }
   StatusBar1->SimpleText = L"";

   // check for deletions and updates
   vector<int> Deletions;
   vector<unsigned int> Updates;
   for (unsigned int i=0; i<DatasetVarSynonyms.Size(); i++) {
	 DATASETVARSYNONYM& NeotomaSyn = DatasetVarSynonyms.Items[i];
	 bool found = false;
	 for (unsigned int j=0; j<EditSynonymy->Synonyms.size(); j++) {
	   SYNONYMY& EditSyn = EditSynonymy->Synonyms[j];
	   if (EditSyn.NeotomaSynonymyID == NeotomaSyn.SynonymyID) {
		 found = true;
		 int NeotomaSynPubID = VariantToInt(NeotomaSyn.PublicationID, -1);
		 if (!SameText(EditSyn.TaxonName, NeotomaSyn.RefTaxonName) ||
			 EditSyn.Contrib != NeotomaSyn.FromContributor ||
			 EditSyn.NeotomaPubID() != NeotomaSynPubID ||
			 EditSyn.Notes != NeotomaSyn.Notes) {
		   Updates.push_back(j);
		   }
		 break;
		 }
	   }
	 if (!found)
	   Deletions.push_back(DatasetVarSynonyms.Items[i].SynonymyID);
	 }

   // check for additions
   vector<unsigned int> Additions;
   for (unsigned int j=0; j<EditSynonymy->Synonyms.size(); j++) {
	 if (EditSynonymy->Synonyms[j].NeotomaSynonymyID == -1)
	   Additions.push_back(j);
	 }

   // check all ref taxa names for additions and updates
   map<UnicodeString,int> RefTaxonIDMap;  // Taxon name, TaxonID
   if (!ValidateRefTaxaNames(Additions, RefTaxonIDMap))
	 return;
   if (!ValidateRefTaxaNames(Updates, RefTaxonIDMap))
	 return;

   // get valid TaxonID for additions and updates
   int TaxonID;
   if (Additions.size() > 0 || Updates.size() > 0) {
	 if (!GetVariableTaxonID(TaxonID))
	   return;
	 }

   vector<UnicodeString> Messages;
   // make deletions
   UnicodeString ErrorMsg;
   for (unsigned int i=0; i<Deletions.size(); i++) {
	 DeleteData DeleteSynonymy(L"DeleteSynonymy", 2, ipsHTTPS1, ipsJSONS1, TcpClient1);
	 StatusBar1->SimpleText = L"DeleteSynonymy";
	 DeleteSynonymy.Add(L"SYNONYMYID", Deletions[i]);
	 DeleteSynonymy.Add(L"CONTACTID", Login->ContactID);
	 if (DeleteSynonymy.Post(ErrorMsg)) {
	   UnicodeString msg = L"SynonymyID " + IntToStr(Deletions[i]) + L" deleted.";
	   Messages.push_back(msg);
	   }
	 else {
	   UnicodeString msg = L"Attempt to delete Synonymy record failed:";
	   if (!ErrorMsg.IsEmpty())
		 msg += (L": " + ErrorMsg);
	   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   }
	 StatusBar1->SimpleText = L"";
	 }

   // make additions
   if (Additions.size() > 0) {
	 for (unsigned int i=0; i<Additions.size(); i++) {
	   // upload new synonym
	   SYNONYMY& Synonymy = EditSynonymy->Synonyms[Additions[i]];
	   int RefTaxonID = RefTaxonIDMap[Synonymy.TaxonName];

	   vector<int> newids;
	   newids.clear();
	   InsertData InsertSynonymy(L"InsertSynonymy", 8, ipsHTTPS1, ipsJSONS1, TcpClient1);
	   InsertSynonymy.Add(L"DATASETID", NeotomaDatasetID, -1);
	   InsertSynonymy.Add(L"TAXONID", TaxonID, -1);
	   InsertSynonymy.Add(L"REFTAXONID", RefTaxonID, -1);
	   InsertSynonymy.Add(L"FROMCONTRIBUTOR", Synonymy.Contrib);
	   InsertSynonymy.Add(L"PUBLICATIONID", Synonymy.NeotomaPubID(), -1);
	   InsertSynonymy.Add(L"NOTES", Synonymy.Notes);
	   InsertSynonymy.Add(L"CONTACTID", Login->ContactID, -1);
	   InsertSynonymy.Add(L"DATESYNONYMIZED", UTCDateTime().FormatString(L"yyyy-mm-dd"));
	   StatusBar1->SimpleText = L"InsertSynonymy";
	   InsertSynonymy.PostData();
	   if (InsertSynonymy.Post(newids, ErrorMsg)) {
		 if (newids.size() == 1)
		   msg = L"New synonym «" + Synonymy.TaxonName + L"» inserted into Synonymy table.";
		 else
		   msg = L"Error: synonym «" + Synonymy.TaxonName + L"» not inserted into Synonymy table.";
		 }
	   else
		 msg = L"Error: synonym «" + Synonymy.TaxonName + L"» not inserted into Synonymy table.";
	   Messages.push_back(msg);
	   }
	 StatusBar1->SimpleText = L"";
	 }

   // make updates
   if (Updates.size() > 0) {
	 for (unsigned int i=0; i<Updates.size(); i++) {
	   SYNONYMY& Synonymy = EditSynonymy->Synonyms[Updates[i]];
	   int RefTaxonID = RefTaxonIDMap[Synonymy.TaxonName];
	   int PubID = Synonymy.NeotomaPubID();
	   Variant NeotomaPubID;
	   if (PubID != -1)
		 NeotomaPubID = PubID;

	   UpdateData UpdateSynonymy(L"UpdateSynonymy", 7, ipsHTTPS1, ipsJSONS1, TcpClient1);
	   StatusBar1->SimpleText = L"UpdateSynonymy";
	   UpdateSynonymy.Add(L"SYNONYMYID", Synonymy.NeotomaSynonymyID);
	   UpdateSynonymy.Add(L"REFTAXONID", RefTaxonID);
	   UpdateSynonymy.Add(L"FROMCONTRIBUTOR", Synonymy.Contrib);
	   UpdateSynonymy.AddInt(L"PUBLICATIONID", NeotomaPubID);
	   UpdateSynonymy.Add(L"NOTES", Synonymy.Notes);
	   UpdateSynonymy.Add(L"CONTACTID", Login->ContactID);
	   UpdateSynonymy.Add(L"DATESYNONYMIZED", UTCDateTime().FormatString(L"yyyy-mm-dd"));

	   ErrorMsg = L"";
	   if (UpdateSynonymy.Post(ErrorMsg))
		 msg = L"SynonymyID " + IntToStr(Synonymy.NeotomaSynonymyID) + L", " +
			   Synonymy.TaxonName + L" updated.";
	   else if (!ErrorMsg.IsEmpty())
		 msg = L"Error: SynonymyID " + IntToStr(Synonymy.NeotomaSynonymyID) + L", " +
			   Synonymy.TaxonName + L"not updated.";
	   Messages.push_back(msg);
	   }
	 StatusBar1->SimpleText = L"";
	 }

   msg = L"";
   if (Messages.size() > 0) {
	 for (unsigned int i=0; i<Messages.size(); i++) {
	   if (i > 0) msg += L"\n";
	   msg += Messages[i];
	   }
	 }
   else
	 msg = L"Synonymy is current with Neotoma. No updates made.";
   MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
}
//---------------------------------------------------------------------------

bool TSynonymForm::ValidateRefTaxaNames(vector<unsigned int>& Records, map<UnicodeString,int>& RefTaxonIDMap)
{
   if (Records.size() > 0) {
	 for (unsigned int i=0; i<Records.size(); i++) {
	   SYNONYMY& Synonymy = EditSynonymy->Synonyms[Records[i]];
	   int RefTaxonID = -1;
	   TaxonByName NeotomaTaxon(ipsJSONS1, TcpClient1);
	   NeotomaTaxon.AddParam(L"TAXONNAME", Synonymy.TaxonName);
	   StatusBar1->SimpleText = NeotomaTaxon.WebServiceName();
	   if (NeotomaTaxon.Execute()) {
		 if (NeotomaTaxon.Size() > 0) {
			RefTaxonID = NeotomaTaxon.Items[0].TaxonID;
			RefTaxonIDMap[Synonymy.TaxonName] = RefTaxonID;
			}
		  }
	   StatusBar1->SimpleText = L"";
	   if (RefTaxonID == -1) {
		 UnicodeString msg = L"ERROR: Synonym name «" + Synonymy.TaxonName + L"» not found in the Neotoma Taxa table.";
		 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 return false;
		 }
	   }
	 }
   return true;
}
//---------------------------------------------------------------------------

bool TSynonymForm::GetVariableTaxonID(int& TaxonID)
{
   bool rv = true;
   // get TaxonID
   NeotomaVariableTaxonID VarTaxonID(ipsJSONS1, TcpClient1);
   VarTaxonID.AddParam(L"VARIABLEID", NeotomaVariableID);
   StatusBar1->SimpleText = VarTaxonID.WebServiceName();
   if (VarTaxonID.Execute())
	 TaxonID = VarTaxonID.Items[0];
   else
	 rv = false;
   StatusBar1->SimpleText = L"";
   return rv;
}
//---------------------------------------------------------------------------

void __fastcall TSynonymForm::ipsJSONS1SSLServerAuthentication(TObject *Sender, TipsJSONSSSLServerAuthenticationEventParams *e)
{
   e->Accept = true;
}
//---------------------------------------------------------------------------

