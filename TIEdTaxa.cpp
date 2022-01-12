//---------------------------------------------------------------------------
#define VCL_IOSTREAM
#include <vcl.h>
#pragma hdrstop

#include "TIEdTaxa.h"
#ifndef TIEdGrpsH
#include "TIEdGrps.h"
#endif

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxClasses"
#pragma link "cxControls"
#pragma link "cxCustomData"
#pragma link "cxData"
#pragma link "cxDataStorage"
#pragma link "cxEdit"
#pragma link "cxFilter"
#pragma link "cxGraphics"
#pragma link "cxGrid"
#pragma link "cxGridCustomTableView"
#pragma link "cxGridCustomView"
#pragma link "cxGridLevel"
#pragma link "cxGridTableView"
#pragma link "cxStyles"
#pragma link "cxTextEdit"
#pragma link "cxDropDownEdit"
#pragma link "cxContainer"
#pragma link "cxMaskEdit"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxNavigator"
#pragma link "cxButtons"
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
#pragma resource "*.dfm"
TEditTaxaForm *EditTaxaForm;

TTaxaList::TTaxaList(TTaxaList* OldTaxaList)
{
   if (OldTaxaList) {
     for (int i=0; i<OldTaxaList->Count; i++) {
       TAXON* OldTaxon = OldTaxaList->Taxa[i];
       TAXON* NewTaxon = new TAXON;
       NewTaxon->ID = OldTaxon->ID;
       NewTaxon->HigherID = OldTaxon->HigherID;
       NewTaxon->Code = OldTaxon->Code;
	   NewTaxon->Name = OldTaxon->Name;
	   NewTaxon->Author = OldTaxon->Author;
       NewTaxon->TaxaGroup = OldTaxon->TaxaGroup;
	   NewTaxon->EcolGroup = OldTaxon->EcolGroup;
	   NewTaxon->Elements.assign(OldTaxon->Elements.begin(), OldTaxon->Elements.end());
	   Add(NewTaxon);
       }
     }
}
//---------------------------------------------------------------------------

bool TTaxaList::FindID(int id, int& index)
{
   int left = 0;
   int right = Count;
   int middle;

   while (left <= right) {
	 middle = (left + right)/2;
	 if (Taxa[middle]->ID == id) {
	   index = middle;
	   return true;
	   }
	 else if (Taxa[middle]->ID > id)
	   right = middle - 1;
	 else
	   left = middle + 1;
	 }
   return false;
}
//---------------------------------------------------------------------------

void TTaxaList::ReleaseAllTaxa()
{
  for (int i = 0; i < Count; i++)
    ReleaseTaxon(i);
}
//---------------------------------------------------------------------------

void TTaxaList::ReleaseTaxon(int AIndex)
{
  delete (TAXON*)Items[AIndex];
}
//---------------------------------------------------------------------------

TAXON* TTaxaList::GetTaxon(int AIndex)
{
  return (TAXON*)Items[AIndex];
}
//---------------------------------------------------------------------------

void __fastcall TTaxaList::Notify(void * Ptr, TListNotification Action)
{
  if (FOnNotify != NULL)
    FOnNotify(Ptr, Action);
}
//---------------------------------------------------------------------------

void __fastcall TTaxaList::Clear(void)
{
  ReleaseAllTaxa();
}
//---------------------------------------------------------------------------

void __fastcall TTaxaList::Add(TAXON* Taxon)
{
  TList::Add(Taxon);
}
//---------------------------------------------------------------------------

void TTaxaList::Delete(int AIndex)
{
  ReleaseTaxon(AIndex);
  TList::Delete(AIndex);
}
//---------------------------------------------------------------------------

void TTaxaList::Insert(int AIndex, TAXON* Taxon)
{
  TList::Insert(AIndex, Taxon);
}
//---------------------------------------------------------------------------

__fastcall TTaxaDataSource::TTaxaDataSource(TTaxaList* ATaxaList)
{
  FTaxa = ATaxaList;
  FTaxa->OnNotify = Notify;
}
//---------------------------------------------------------------------------

void __fastcall TTaxaDataSource::DeleteRecord(void * ARecordHandle)
{
  FTaxa->Delete((int)ARecordHandle);
}
//---------------------------------------------------------------------------

int __fastcall TTaxaDataSource::GetRecordCount(void)
{
  return(FTaxa->Count);
}
//---------------------------------------------------------------------------

void __fastcall TTaxaDataSource::Notify(void * Ptr, TListNotification Action)
{
  DataChanged();
}
//---------------------------------------------------------------------------

void * __fastcall TTaxaDataSource::InsertRecord(void * ARecordHandle)
{
  TAXON* Taxon = new TAXON;
  FTaxa->Insert((int)ARecordHandle, Taxon);
  TcxDataRecordHandle* Result = (TcxDataRecordHandle*)ARecordHandle;
  return (Result);
}
//---------------------------------------------------------------------------

void * __fastcall TTaxaDataSource::AppendRecord(void)
{
  TcxDataRecordHandle* Result = (TcxDataRecordHandle*)FTaxa->Count;
  TAXON* Taxon = new TAXON;
  FTaxa->Add(Taxon);
  return (Result);
}
//---------------------------------------------------------------------------

Variant __fastcall TTaxaDataSource::GetValue(void * ARecordHandle, void * AItemHandle)
{
  int AColumnId = GetDefaultItemID((int)AItemHandle);
  TAXON* Taxon = FTaxa->Taxa[(int)ARecordHandle];
  Variant Result;
  switch (AColumnId) {
	case IndexOftxTaxonID:
	  Result = Taxon->ID;
	  break;
	case IndexOftxCode:
	  Result = Taxon->Code;
	  break;
    case IndexOftxName:
      Result = Taxon->Name;
      break;
    case IndexOftxHigherID:
	  if (Taxon->HigherID == -1)
        Result.ChangeType(varEmpty);
      else
        Result = Taxon->HigherID;
      break;
    case IndexOftxEcolGroup:
      Result = Taxon->EcolGroup;
      break;
  }
  return (Result);
}
//---------------------------------------------------------------------------

void __fastcall TTaxaDataSource::SetValue(void * ARecordHandle, void * AItemHandle, const Variant &AValue)
{
  Variant Blank;
  int AColumnId = GetDefaultItemID((int)AItemHandle);
  TAXON* Taxon = FTaxa->Taxa[(int)ARecordHandle];
  switch (AColumnId) {
	case IndexOftxTaxonID:
	  Taxon->ID = (AValue.IsNull()) ? -1 : AValue;
	  break;
	case IndexOftxCode:
	  Taxon->Code = (AValue.IsNull()) ? Blank : AValue;
	  break;
    case IndexOftxName:
	  Taxon->Name = (AValue.IsNull()) ? Blank : AValue;
      break;
    case IndexOftxHigherID:
	  Taxon->HigherID = (AValue.IsNull()) ? -1 : AValue;
      break;
	case IndexOftxEcolGroup:
	  Taxon->EcolGroup = (AValue.IsNull()) ? Blank : AValue;
      break;
  }
}
//---------------------------------------------------------------------------

int __fastcall TElementsDataSource::GetRecordCount(void)
{
  int Result = 0;
  int idx = GetMasterRecordIndex();
  if (idx >= 0) {
    TAXON *Taxon = (TAXON*)MasterDataSource->TaxaList->Taxa[idx];
    Result = Taxon->Elements.size();
    }
  return (Result);
}
//---------------------------------------------------------------------------

Variant __fastcall TElementsDataSource::GetValue(void * ARecordHandle, void * AItemHandle)
{
  int AColumnId = GetDefaultItemID(int(AItemHandle));
  TAXON *Taxon = (TAXON*)MasterDataSource->TaxaList->Taxa[GetMasterRecordIndex()];
  UnicodeString Element = Taxon->Elements[(int)ARecordHandle].Name;
  Variant Result;
  if (AColumnId == IndexOfelElement)
    Result = Element;
  return (Result);
}
//---------------------------------------------------------------------------

void __fastcall TElementsDataSource::SetValue(void * ARecordHandle, void * AItemHandle, const Variant &AValue)
{
  int AColumnId = GetDefaultItemID((int)AItemHandle);

  TAXON *Taxon = (TAXON*)MasterDataSource->TaxaList->Taxa[GetMasterRecordIndex()];
  UnicodeString Element;
  if (AColumnId == IndexOfelElement) {
	if (AValue.IsNull())
      Element.SetLength(0);
    else
      Element = AValue;
    Taxon->Elements[(int)ARecordHandle].Name = Element;
    }
}
//---------------------------------------------------------------------------

void * __fastcall TElementsDataSource::AppendRecord(void)
{
  TAXON *Taxon = (TAXON*)MasterDataSource->TaxaList->Taxa[GetMasterRecordIndex()];
  ELEMENT Element;
  Taxon->Elements.push_back(Element);
  int Result = Taxon->Elements.size() - 1;
  DataChanged();
  return ((void*)Result);
}
//---------------------------------------------------------------------------

void __fastcall TElementsDataSource::Notify(void * Ptr, TListNotification Action)
{
  DataChanged();
}
//---------------------------------------------------------------------------

void * __fastcall TElementsDataSource::InsertRecord(void * ARecordHandle)
{
  TAXON *Taxon = (TAXON*)MasterDataSource->TaxaList->Taxa[GetMasterRecordIndex()];
  ELEMENT Element;
  vector<ELEMENT>::iterator itr = Taxon->Elements.begin() + (int)ARecordHandle;
  Taxon->Elements.insert(itr, Element);
  void * Result = ARecordHandle;
  DataChanged();
  return (Result);
}
//---------------------------------------------------------------------------

void __fastcall TElementsDataSource::DeleteRecord(void * ARecordHandle)
{
  TAXON *Taxon = (TAXON*)MasterDataSource->TaxaList->Taxa[GetMasterRecordIndex()];
  vector<ELEMENT>::iterator itr = Taxon->Elements.begin() + (int)ARecordHandle;
  Taxon->Elements.erase(itr);
  DataChanged();
}
//---------------------------------------------------------------------------

int TElementsDataSource::GetMasterRecordIndex()
{
  return (DataController->GetMasterRecordIndex());
}
//---------------------------------------------------------------------------

void __fastcall TEditTaxaForm::TaxaGridTableView1DataControllerDetailExpanding(
      TcxCustomDataController *ADataController, int ARecordIndex,
      bool &AAllow)
{
  // need to collapse any expanded details when expanding a new tree
  ADataController->CollapseDetails();
  ADataController->FocusedRecordIndex = ARecordIndex;
}
//---------------------------------------------------------------------------

void __fastcall TEditTaxaForm::TaxaGridTableView2DataControllerDetailExpanded(
      TcxCustomDataController *ADataController, int ARecordIndex)
{
  // focus the current record
  ADataController->FocusedRecordIndex = ARecordIndex;
}
//---------------------------------------------------------------------------

int __fastcall TUnitsDataSource::GetRecordCount(void)
{
  int Result = 0;
  int idx2 = GetElementsMasterRecordIndex();
  if (idx2 >= 0) {
    int idx1 = GetTaxaMasterRecordIndex();
    TAXON *Taxon = (TAXON*)MasterDataSource->TaxaList->Taxa[idx1];
    Result = Taxon->Elements[idx2].Units.size();
    }
  return (Result);
}
//---------------------------------------------------------------------------

Variant __fastcall TUnitsDataSource::GetValue(void * ARecordHandle, void * AItemHandle)
{
  Variant Result;
  int AColumnId = GetDefaultItemID(int(AItemHandle));
  int idx1 = GetTaxaMasterRecordIndex();
  TAXON *Taxon = (TAXON*)MasterDataSource->TaxaList->Taxa[idx1];
  int idx2 = GetElementsMasterRecordIndex();
  UnicodeString Units = Taxon->Elements[idx2].Units[(int)ARecordHandle];
  if (AColumnId == IndexOfunUnits)
    Result = Units;
  return (Result);
}
//---------------------------------------------------------------------------

void __fastcall TUnitsDataSource::SetValue(void * ARecordHandle, void * AItemHandle, const Variant &AValue)
{
  UnicodeString Units;
  int AColumnId = GetDefaultItemID((int)AItemHandle);
  int idx1 = GetTaxaMasterRecordIndex();
  TAXON *Taxon = (TAXON*)MasterDataSource->TaxaList->Taxa[idx1];
  if (AColumnId == IndexOfunUnits) {
	if (AValue.IsNull())
      Units.SetLength(0);
    else
      Units = AValue;
    int idx2 = GetElementsMasterRecordIndex();
    Taxon->Elements[idx2].Units[(int)ARecordHandle] = Units;
    }
}
//---------------------------------------------------------------------------

void * __fastcall TUnitsDataSource::AppendRecord(void)
{
  UnicodeString Units;
  int idx1 = GetTaxaMasterRecordIndex();
  TAXON *Taxon = (TAXON*)MasterDataSource->TaxaList->Taxa[idx1];
  int idx2 = GetElementsMasterRecordIndex();
  Taxon->Elements[idx2].Units.push_back(Units);
  int Result = Taxon->Elements[idx2].Units.size() - 1;
  DataChanged();
  return ((void*)Result);
}
//---------------------------------------------------------------------------

void __fastcall TUnitsDataSource::Notify(void * Ptr, TListNotification Action)
{
  DataChanged();
}
//---------------------------------------------------------------------------

void * __fastcall TUnitsDataSource::InsertRecord(void * ARecordHandle)
{
  int idx1 = GetTaxaMasterRecordIndex();
  TAXON *Taxon = (TAXON*)MasterDataSource->TaxaList->Taxa[idx1];
  int idx2 = GetElementsMasterRecordIndex();
  vector<UnicodeString>::iterator itr = Taxon->Elements[idx2].Units.begin() + (int)ARecordHandle;
  UnicodeString Units;
  Taxon->Elements[idx2].Units.insert(itr, Units);
  void * Result = ARecordHandle;
  DataChanged();
  return (Result);
}
//---------------------------------------------------------------------------

void __fastcall TUnitsDataSource::DeleteRecord(void * ARecordHandle)
{
  int idx1 = GetTaxaMasterRecordIndex();
  TAXON *Taxon = (TAXON*)MasterDataSource->TaxaList->Taxa[idx1];
  int idx2 = GetElementsMasterRecordIndex();
  vector<UnicodeString>::iterator itr = Taxon->Elements[idx2].Units.begin() + (int)ARecordHandle;
  Taxon->Elements[idx2].Units.erase(itr);
  DataChanged();
}
//---------------------------------------------------------------------------

int TUnitsDataSource::GetElementsMasterRecordIndex()
{
  return (DataController->GetMasterRecordIndex());
}
//---------------------------------------------------------------------------

int TUnitsDataSource::GetTaxaMasterRecordIndex()
{
  return (DataController->GetMasterDataController()->GetMasterRecordIndex());
}
//---------------------------------------------------------------------------

__fastcall TEditTaxaForm::TEditTaxaForm(TTaxaVector* TaxaListPtr,
	vector<TAXAECOLGROUPS>* TaxaEcolGroupsPtr, int max_id, bool new_taxa,
	TComponent* Owner) : TForm(Owner)
{
   OriginalTaxaEcolGroupsPtr = TaxaEcolGroupsPtr;
   TaxaEcolGroups = *TaxaEcolGroupsPtr;
   TaxaList = new TTaxaList();
   for (unsigned int i=0; i<TaxaListPtr->size(); i++) {
	 TAXON* Taxon = new TAXON(&TaxaListPtr->at(i));
	 TaxaList->Add(Taxon);
	 }

   NewTaxa = new_taxa;
   MaxID = max_id;

   // formerly in OnActivate
   TaxaDataSource = new TTaxaDataSource(TaxaList);
   ElementsDataSource = new TElementsDataSource(TaxaDataSource);
   UnitsDataSource = new TUnitsDataSource(TaxaDataSource);
   GenerateTaxaColumns();

   // Fill EcolGroup lookup list
   TcxComboBoxProperties* egp = (TcxComboBoxProperties*)(txEcolGroup->Properties);

   if (TaxaEcolGroups.size()) {
	 for (unsigned int i=0; i<TaxaEcolGroups.size(); i++) {
	   for (unsigned int j=0; j<TaxaEcolGroups[i].EcolGroups.size(); j++) {
		 UnicodeString Code = TaxaEcolGroups[i].EcolGroups[j].Code;
		 if (egp->Items->IndexOf(Code) == -1)
		   egp->Items->Add(Code);
		 }
	   }
	 }
   LabeledEdit1->Text = TaxaTitle;
}
//---------------------------------------------------------------------------

void __fastcall TEditTaxaForm::FormDestroy(TObject *Sender)
{
   delete TaxaList;
   delete TaxaDataSource;
   delete ElementsDataSource;
   delete UnitsDataSource;
}
//---------------------------------------------------------------------------

void __fastcall TEditTaxaForm::GenerateTaxaColumns()
{
   txCode->DataBinding->Data = (TObject *)IndexOftxCode;
   txName->DataBinding->Data = (TObject *)IndexOftxName;
   txHigherID->DataBinding->Data = (TObject *)IndexOftxHigherID;
   txEcolGroup->DataBinding->Data = (TObject *)IndexOftxEcolGroup;

   // this line is critical
   TaxaGridTableView1->DataController->CustomDataSource = TaxaDataSource;

   elElement->DataBinding->Data = (TObject*)IndexOfelElement;

   // this line is critical
   TaxaGridTableView2->DataController->CustomDataSource = ElementsDataSource;

   unUnits->DataBinding->Data = (TObject*)IndexOfunUnits;

   // this line is critical
   TaxaGridTableView3->DataController->CustomDataSource = UnitsDataSource;
}
//---------------------------------------------------------------------------

void __fastcall TEditTaxaForm::TaxaGridTableView1DataControllerBeforePost(
      TcxCustomDataController *ADataController)
{
   Variant Value;
   UnicodeString Taxon, Code;

   // if (ADataController->FocusedRowIndex == -1) [
   if (ADataController->FocusedRecordIndex == -1) {
     Value = ADataController->Values[-1][2];   // Name
	 if (Value.IsEmpty()) {
	   MessageDlg("No taxon name.", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
       ADataController->Cancel();
       return;
       }
     else {
       Taxon = Value;
       if (Taxon.IsEmpty()) {
		 MessageDlg("No taxon name.", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
         ADataController->Cancel();
         return;
         }
       else if (ADataController->FindRecordIndexByText(0, 2, Taxon, false, false, true) > -1) {
         MessageDlg("Taxon already exists", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
         ADataController->Cancel();
         return;
         }
       }
     Value = ADataController->Values[-1][1];  // Code
     if (Value.IsEmpty()) {
       Code = FormCode(ADataController, Taxon);
       ADataController->Values[-1][1] = Code;
       }

     MaxID++;
     ADataController->Values[-1][0] = MaxID;
     }
}
//---------------------------------------------------------------------------

UnicodeString TEditTaxaForm::FormCode(TcxCustomDataController *ADataController, UnicodeString Taxon)
{
   UnicodeString Code, TempCode, Genus, species, sCode;
   int pos, pos1, pos2, len, rec;
   bool family = false;
   bool order = false;
   bool cflead = false;
   bool cfmid = false;
   bool aff = false;
   bool question = false;
   bool type = false;
   bool undiff = false;
   bool sp = false;

   // take care of subg., subf., tribe, cf., aff., ?, -type, undiff., sp.

   if ((pos = Taxon.Pos(" subg. ")) > 0)
	 Taxon.Delete(pos,6);
   else if ((pos = Taxon.Pos(" subf. ")) > 0)
	 Taxon.Delete(pos,6);
   else if ((pos = Taxon.Pos(" tribe ")) > 0)
	 Taxon.Delete(pos,6);

   if (Taxon.Pos("cf. ") == 1) {
	 Taxon.Delete(1,4);
	 cflead = true;
	 }
   else if ((pos = Taxon.Pos(" cf. ")) > 0) {
     if (Taxon.SubString(pos+6,2) == ". ")
       Taxon.Delete(pos,7);
     else
       Taxon.Delete(pos,4);
     cfmid = true;
     }
   else if (Taxon.Pos("aff. ") == 1) {
	 Taxon.Delete(1,5);
	 aff = true;
	 }
   else if (Taxon.Pos("?") == 1) {
     Taxon.Delete(1,1);
     question = true;
     }

   if ((pos = Taxon.Pos("-type")) == Taxon.Length()-4) {
     Taxon.Delete(pos,5);
     type = true;
     }
   if ((pos = Taxon.Pos("undiff.")) == Taxon.Length()-6) {
     Taxon.Delete(pos,7);
     undiff = true;
     }
   else if ((pos = Taxon.Pos("sp.")) == Taxon.Length()-2) {
     Taxon.Delete(pos,3);
     sp = true;
     }

   if ((pos = Taxon.Pos(" ")) > 0) {
     Genus = Taxon.SubString(1, pos-1);
     species = Taxon.SubString(pos+1, Taxon.Length()-pos);
     }
   else
     Genus = Taxon;

   if ((rec = ADataController->FindRecordIndexByText(0, 2, Genus, false, false, true)) > -1)
     Code = ADataController->Values[rec][1];;

   if (Code.IsEmpty()) {
     len = Genus.Length();
     if (len >= 7) {
       if (Genus.SubString(len-4, 5) == "aceae") {
         Genus.Delete(len-4, 5);
         family = true;
         }
       else if (Genus.SubString(len-3, 4) == "ales") {
         Genus.Delete(len-3, 4);
         order = true;
         }
       }
     pos1 = 2;
     pos2 = 3;
     while (pos1 < len && pos2 <= len) {
      Code = Genus.SubString(1,1) + Genus.SubString(pos1,1) + Genus.SubString(pos2,1);
       if (ADataController->FindRecordIndexByText(0, 1, Code, false, false, true) == -1)
         break;
       else {
         Code.SetLength(0);
         pos2++;
         if (pos2 > len) {
           pos1++;
           pos2 = pos1 + 1;
           }
         }
       }
     }
   if (Code.IsEmpty())
     Code = Genus.SubString(1,1) + "xx";
   if (family)
     Code += "eae";
   else if (order)
     Code += "les";
     
   if (cflead)
     Code.Insert("cf.",1);
   else if (aff)
     Code.Insert("af.",1);
   else if (question)
     Code.Insert("?",1);

   if (!species.IsEmpty()) {
     pos1 = 2;
     len = species.Length();
     while (pos1 <= len) {
       sCode = species.SubString(1,1) + species.SubString(pos1,1);
       TempCode = Code + "." + sCode;
       if (ADataController->FindRecordIndexByText(0, 1, TempCode, false, false, true) == -1)
         break;
       else {
         sCode.SetLength(0);
         pos1++;
         }
       }
     if (sCode.IsEmpty())
       sCode = "xx";
     if (cfmid)
       Code += ".cf.";
     else
       Code += ".";
     Code += sCode;
     }

   if (type)
     Code += "-t";
   if (undiff)
     Code += ".ud";
   else if (sp)
     Code += ".sp";  

   return Code;
}
//---------------------------------------------------------------------------

// Find
void __fastcall TEditTaxaForm::ToolButton2Click(TObject *Sender)
{
   if (!FindText(0)) {
     Beep();
     MessageDlg("Search item not found.", mtInformation, TMsgDlgButtons() << mbOK, 0);
     }
}
//---------------------------------------------------------------------------

// Find next
void __fastcall TEditTaxaForm::ToolButton4Click(TObject *Sender)
{
   int StartRow;

   if (Forward1->Checked) {
     StartRow = TaxaGridTableView1->DataController->FocusedRowIndex + 1;
	 if (StartRow >= TaxaGridTableView1->DataController->RowCount)
       StartRow = 0;
     }
   else {
	 StartRow = TaxaGridTableView1->DataController->FocusedRowIndex - 1;
     if (StartRow < 0)
       StartRow = 0;
     }
   if (!FindText(StartRow)) {
     Beep();
     MessageDlg("Search item not found.", mtInformation, TMsgDlgButtons() << mbOK, 0);
     }
}
//---------------------------------------------------------------------------

bool TEditTaxaForm::FindText(int StartRow)
{
   int index;
   bool Forward = Forward1->Checked;
   bool found = false;

   UnicodeString Text = cxComboBox1->Text;
   if ((index = cxComboBox1->Properties->Items->IndexOf(Text)) == -1)
     cxComboBox1->Properties->Items->Insert(0, Text);
   else if (index > 0)
     cxComboBox1->Properties->Items->Move(index, 0);
   if (cxComboBox1->Properties->Items->Count == 21)
     cxComboBox1->Properties->Items->Delete(20);

   if (Text.IsEmpty()) {
     Beep();
     return true;
     }

   int item = TaxaGridTableView1->Controller->FocusedItemIndex;

   if (PartialCompare1->Checked) {
     if (Forward) {
       found = FindPartialTextForward(StartRow, TaxaGridTableView1->DataController->RowCount-1, item, Text);
       if (!found)
         found = FindPartialTextForward(0, StartRow, item, Text);
       }
     else {
       found = FindPartialTextBackward(StartRow, 0, item, Text);
       if (!found)
         found = FindPartialTextBackward(TaxaGridTableView1->DataController->RowCount-1, StartRow, item, Text);
       }
     }
   else {
     bool StartOfField = StartofField1->Checked;
     if ((index = TaxaGridTableView1->DataController->FindRecordIndexByText(
         StartRow, item, Text, StartOfField, true, Forward)) > -1)
       {
       TaxaGridTableView1->DataController->FocusedRecordIndex = index;
       found = true;
       }
     }
   return found;
}
//---------------------------------------------------------------------------

bool TEditTaxaForm::FindPartialTextForward(int StartRow, int EndRow, int item, UnicodeString Text)
{
   TcxRowInfo RowInfo;
   UnicodeString DisplayText;
   Text = Text.LowerCase();
   for (int index=StartRow; index<=EndRow; index++) {
     RowInfo = TaxaGridTableView1->DataController->GetRowInfo(index);
     DisplayText = TaxaGridTableView1->DataController->GetRowDisplayText(RowInfo, item);
     DisplayText = DisplayText.LowerCase();
	 if (DisplayText.Pos(Text)) {
       TaxaGridTableView1->DataController->FocusedRecordIndex = RowInfo.RecordIndex;
       return true;
       }
     }
   return false;
}
//---------------------------------------------------------------------------

bool TEditTaxaForm::FindPartialTextBackward(int StartRow, int EndRow, int item, UnicodeString Text)
{
   TcxRowInfo RowInfo;
   UnicodeString DisplayText;
   Text = Text.LowerCase();
   for (int index=StartRow; index>=EndRow; index--) {
     RowInfo = TaxaGridTableView1->DataController->GetRowInfo(index);
     DisplayText = TaxaGridTableView1->DataController->GetRowDisplayText(RowInfo, item);
     DisplayText = DisplayText.LowerCase();
	 if (DisplayText.Pos(Text)) {
       TaxaGridTableView1->DataController->FocusedRecordIndex = RowInfo.RecordIndex;
       return true;
       }
     }
   return false;
}
//---------------------------------------------------------------------------

/*
void __fastcall TEditTaxaForm::SpeedButton3Click(TObject *Sender)
{
   int x = SpeedButton3->ClientOrigin.x;
   int y = SpeedButton3->ClientOrigin.y + SpeedButton3->ClientHeight + 1;
   PopupMenu1->Popup(x,y);
}
//---------------------------------------------------------------------------
*/

void __fastcall TEditTaxaForm::Forward1Click(TObject *Sender)
{
   Forward1->Checked = true;
   Backward1->Checked = false;
}
//---------------------------------------------------------------------------

void __fastcall TEditTaxaForm::Backward1Click(TObject *Sender)
{
   Backward1->Checked = true;
   Forward1->Checked = false;
}
//---------------------------------------------------------------------------

void __fastcall TEditTaxaForm::WholeField1Click(TObject *Sender)
{
   WholeField1->Checked = true;
   PartialCompare1->Checked = false;
   StartofField1->Checked = false;
}
//---------------------------------------------------------------------------

void __fastcall TEditTaxaForm::PartialCompare1Click(TObject *Sender)
{
   WholeField1->Checked = false;
   PartialCompare1->Checked = true;
   StartofField1->Checked = false;
}
//---------------------------------------------------------------------------

void __fastcall TEditTaxaForm::StartofField1Click(TObject *Sender)
{
   WholeField1->Checked = false;
   PartialCompare1->Checked = false;
   StartofField1->Checked = true;
}
//---------------------------------------------------------------------------
 
void __fastcall TEditTaxaForm::txEcolGroupPropertiesNewLookupDisplayText(
      TObject *Sender, const TCaption AText)
{
   TcxComboBoxProperties* egp = (TcxComboBoxProperties*)(txEcolGroup->Properties);
   egp->Items->Append(AText);
}
//---------------------------------------------------------------------------

void __fastcall TEditTaxaForm::cxButton1Click(TObject *Sender)
{
   if (LabeledEdit1->Text.IsEmpty()) {
	 MessageDlg("Title is blank.", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
     return;
     }
   else
     TaxaTitle = LabeledEdit1->Text;

   Screen->Cursor = crHourGlass;

   // TODO: this is a temporary fix
   //vector<TAXON> vTaxaList;
   TTaxaVector vTaxaList;
   ConvertTaxaList(vTaxaList);

   SAVETAXALOOKUP* SaveTaxaLookup = new SAVETAXALOOKUP(TaxaFile, TaxaTitle,
	 &TaxaEcolGroups, &vTaxaList, this);
   SaveTaxaLookup->Save();
   delete SaveTaxaLookup;
   FocusControl(TaxaGrid);
   Screen->Cursor = crDefault;
}
//---------------------------------------------------------------------------

void __fastcall TEditTaxaForm::cxButton2Click(TObject *Sender)
{
   *OriginalTaxaEcolGroupsPtr = TaxaEcolGroups;

}
//---------------------------------------------------------------------------

// TODO: this is for a temporary fix until TaxaList converted to vector
//void TEditTaxaForm::ConvertTaxaList(vector<TAXON>& vTaxaList)
void TEditTaxaForm::ConvertTaxaList(TTaxaVector& vTaxaList)
{
   for (int i=0; i<TaxaList->Count; i++) {
	 TAXON Taxon(TaxaList->Taxa[i]);
	 vTaxaList.push_back(Taxon);
	 }
   vTaxaList.Index();
}
//---------------------------------------------------------------------------

void __fastcall TEditTaxaForm::FormResize(TObject *Sender)
{
   int width = EditTaxaForm->Width - 48;
   if (width > 100)
     LabeledEdit1->Width = width;
   width = EditTaxaForm->Width - 249;
   if (width > 100)
     cxComboBox1->Width = width;
}
//---------------------------------------------------------------------------

void __fastcall TEditTaxaForm::SpeedButton1Click(TObject *Sender)
{
   if (NewTaxa)
     NewGroups();
   else
     EditGroups();
}
//---------------------------------------------------------------------------

void TEditTaxaForm::NewGroups(void)
{
   TaxaEcolGroups.clear();

   EditGroupsForm = new TEditGroupsForm(&TaxaEcolGroups, this);

   // TODO: this is a temporary fix
   TTaxaVector vTaxaList;
   ConvertTaxaList(vTaxaList);

   EditGroupsForm->SetTaxa("", "", &vTaxaList);
   EditGroupsForm->ShowModal();
   delete EditGroupsForm;
}
//---------------------------------------------------------------------------

void TEditTaxaForm::EditGroups(void)
{
   EditGroupsForm = new TEditGroupsForm(&TaxaEcolGroups, this);

   // TODO: this is a temporary fix
   TTaxaVector vTaxaList;
   ConvertTaxaList(vTaxaList);

   EditGroupsForm->SetTaxa(TaxaFile, TaxaTitle, &vTaxaList);

   if (EditGroupsForm->ShowModal() == mrOk) {

	 //if (!LocalGroupCategoryList) {
	 //  delete GroupCategoryList;
	 //  GroupCategoryList = new TGroupCategoryList(EditGroupsForm->GroupCategoryList);
	 //  }
	 /*
	 TcxComboBoxProperties* egp = (TcxComboBoxProperties*)(txEcolGroup->Properties);
	 egp->Items->Clear();

	 for (int i=0; i<GroupCategoryList->Count(); i++) {
	   GROUPCATEGORY* gc = GroupCategoryList->Categories[i];
	   //for (int j=0; j<gc->EcolGroups->Count; j++) {
	   for (unsigned int j=0; j<gc->EcolGroups.size(); j++) {
		 //ECOLGROUP* eg =  (ECOLGROUP*)gc->EcolGroups->Items[j];
		 //if (egp->Items->IndexOf(eg->Code) == -1)
		 //  egp->Items->Add(eg->Code);
		 if (egp->Items->IndexOf(gc->EcolGroups[j].Code) == -1)
		   egp->Items->Add(gc->EcolGroups[j].Code);
		 }
	   }
	 }
	 */
	 }
   //if (LocalGroupCategoryList)
   //  delete GroupCategoryList;
   delete EditGroupsForm;
   FocusControl(TaxaGrid);
}
//---------------------------------------------------------------------------

