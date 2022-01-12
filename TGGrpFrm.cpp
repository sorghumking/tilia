//---------------------------------------------------------------------------

#include <vcl.h>
#include "pch.h"
#pragma hdrstop

#ifndef TGParentH
#include "TGParent.h"
#endif
#ifndef TGGrpFrmH
#include "TGGrpFrm.h"
#endif
#ifndef TGGrpOptH
#include "TGGrpOpt.h"
#endif
#ifndef TGUtilsH
#include "TGUtils.h"
#endif
#ifndef TGHelpH
#include "TGHelp.h"
#endif

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxClasses"
#pragma link "cxControls"
#pragma link "cxCustomData"
#pragma link "cxData"
#pragma link "cxDBData"
#pragma link "cxEdit"
#pragma link "cxFilter"
#pragma link "cxGraphics"
#pragma link "cxGrid"
#pragma link "cxGridCustomTableView"
#pragma link "cxGridCustomView"
#pragma link "cxGridDBTableView"
#pragma link "cxGridLevel"
#pragma link "cxGridTableView"
#pragma link "cxStyles"
#pragma link "cxButtonEdit"
#pragma link "cxDataStorage"
#pragma link "cxDropDownEdit"
#pragma link "cxTextEdit"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxNavigator"
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

TGroupForm *GroupForm;

//---------------------------------------------------------------------------
void TGroupList::ReleaseAllGroups()
{
  for (int i = 0; i < Count; i++)
    ReleaseGroup(i);
}
//---------------------------------------------------------------------------

void TGroupList::ReleaseGroup(int AIndex)
{
  delete (GROUPS*)Items[AIndex];
}
//---------------------------------------------------------------------------

GROUPS* TGroupList::GetGroup(int AIndex)
{
  return (GROUPS*)Items[AIndex];
}
//---------------------------------------------------------------------------

void __fastcall TGroupList::Notify(void * Ptr, TListNotification Action)
{
  if (FOnNotify != NULL)
    FOnNotify(Ptr, Action);
}
//---------------------------------------------------------------------------

void __fastcall TGroupList::Clear(void)
{
  ReleaseAllGroups();
}
//---------------------------------------------------------------------------

void TGroupList::Add(GROUPS* Group)
{
  TList::Add(Group);
}
//---------------------------------------------------------------------------

void TGroupList::Delete(int AIndex)
{
  ReleaseGroup(AIndex);
  TList::Delete(AIndex);
}
//---------------------------------------------------------------------------

void TGroupList::Insert(int AIndex, GROUPS* Group)
{
  TList::Insert(AIndex, Group);
}
//---------------------------------------------------------------------------

__fastcall TGroupDataSource::TGroupDataSource(TGroupList* AGroupList, GROUPS& DFG, TList* g)
{
  FGroups = AGroupList;
  DefaultGroup = DFG;
  grf = g;
  FGroups->OnNotify = Notify;
  TempGroup = NULL;
}
//---------------------------------------------------------------------------

void __fastcall TGroupDataSource::DeleteRecord(void * ARecordHandle)
{
  FGroups->Delete((int)ARecordHandle);
}
//---------------------------------------------------------------------------

int __fastcall TGroupDataSource::GetRecordCount(void)
{
  return(FGroups->Count);
}
//---------------------------------------------------------------------------

Variant __fastcall TGroupDataSource::GetValue(void * ARecordHandle, void * AItemHandle)
{
  // displays value in grid based on stored data
  int AColumnId = GetDefaultItemID((int)AItemHandle);
  GROUPS* Group = FGroups->Groups[(int)ARecordHandle];
  Variant Result;
  switch (AColumnId) {
    case IndexOfFirstGraph:  Result = GetVarName(Group->code1); break;
    case IndexOfSecondGraph: Result = GetVarName(Group->code2); break;
    case IndexOfGroupName:   Result = Group->name; break;
  }
  return (Result);
}
//---------------------------------------------------------------------------

void __fastcall TGroupDataSource::Notify(void * Ptr, TListNotification Action)
{
  DataChanged();
}
//---------------------------------------------------------------------------

void * __fastcall TGroupDataSource::InsertRecord(void * ARecordHandle)
{
  GROUPS* Group;

  if (TempGroup) {
    Group = new GROUPS(TempGroup);
    delete TempGroup;
    TempGroup = NULL;
    }
  else {
    Group = new GROUPS();
    *Group = DefaultGroup;
    }
    
  FGroups->Insert((int)ARecordHandle, Group);
  TcxDataRecordHandle* Result = (TcxDataRecordHandle*)ARecordHandle;
  return (Result);
}
//---------------------------------------------------------------------------

void * __fastcall TGroupDataSource::AppendRecord(void)
{
  GROUPS* Group;

  TcxDataRecordHandle* Result = (TcxDataRecordHandle*)FGroups->Count;

  if (TempGroup) {
    Group = new GROUPS(TempGroup);
    delete TempGroup;
    TempGroup = NULL;
    }
  else {
    Group = new GROUPS();
    *Group = DefaultGroup;
    }

  FGroups->Add(Group);
  return (Result);
}
//---------------------------------------------------------------------------

void __fastcall TGroupDataSource::SetValue(void * ARecordHandle, void * AItemHandle, const Variant &AValue)
{
  // gets values from grid and stores them
  int AColumnId = GetDefaultItemID((int)AItemHandle);
  GROUPS* Group = FGroups->Groups[(int)ARecordHandle];
  UnicodeString Name;
  Name = VarToStr(AValue);
  switch (AColumnId) {
    case IndexOfFirstGraph: Group->code1 = GetVarCode(Name); break;
    case IndexOfSecondGraph: Group->code2 = GetVarCode(Name); break;
	case IndexOfGroupName: Group->name = Name; break;
  }
}
//---------------------------------------------------------------------------

UnicodeString __fastcall TGroupDataSource::GetVarCode(UnicodeString& Name)
{
  UnicodeString VarCode;
  for (int i=0; i<grf->Count; i++) {
    GRAPH* g = (GRAPH*)grf->Items[i];
    if (Name == PlainText(g->name)) {
      VarCode = g->code;
      break;
      }
    }
  return VarCode;
}

//---------------------------------------------------------------------------

UnicodeString __fastcall TGroupDataSource::GetVarName(UnicodeString& Code)
{
  UnicodeString VarName;
  for (int i=0; i<grf->Count; i++) {
    GRAPH* g = (GRAPH*)grf->Items[i];
    if (Code == g->code) {
      VarName = PlainText(g->name);
      break;
      }
    }
  return VarName;
}

//---------------------------------------------------------------------------
__fastcall TGroupForm::TGroupForm(TComponent* Owner)
        : TForm(Owner)
{
  Diag = (TTGDiagram*)Owner;
  DoubleBuffered = true;
}
//---------------------------------------------------------------------------

void __fastcall TGroupForm::FormActivate(TObject *Sender)
{
   int i, j;

   FocusControl(GroupsGrid);

   TcxComboBoxProperties* fgp = (TcxComboBoxProperties*)(grFirstGraph->Properties);
   TcxComboBoxProperties* sgp = (TcxComboBoxProperties*)(grSecondGraph->Properties);

   // fill DevExpress comboboxes
   FirstGraph = 0;
   GRAPH *g = (GRAPH*)Diag->grf->Items[FirstGraph];
   while (!Diag->BaseGraph(g) && FirstGraph < (Diag->grf->Count-1)) {
     FirstGraph++;
     g = (GRAPH*)Diag->grf->Items[FirstGraph];
     }

   UnicodeString name = PlainText(g->name);
   fgp->Items->Add(name);
   sgp->Items->Add(name);

   for (i=FirstGraph+1; i<Diag->grf->Count; i++) {
     g = (GRAPH*)Diag->grf->Items[i];
     if (Diag->BaseGraph(g)) {
       name = PlainText(g->name);
       fgp->Items->Add(name);
       sgp->Items->Add(name);
       }
     }

   DefaultGroup = Diag->Default.GroupAttr;
   GroupList = new TGroupList();
   GroupDataSource = new TGroupDataSource(GroupList, DefaultGroup, Diag->grf);
   GenerateGroupColumns();
   LoadGroupData();

   GroupsGridTableView->Controller->FocusedRecordIndex = InitialRow;
   GroupsGridTableView->Controller->MakeFocusedRecordVisible();

   GroupOptionsForm = new TGroupOptionsForm(this);

   Screen->Cursor = crDefault;
}
//---------------------------------------------------------------------------

void __fastcall TGroupForm::GenerateGroupColumns()
{
   grFirstGraph->DataBinding->Data = (void*)IndexOfFirstGraph;
   grSecondGraph->DataBinding->Data = (TObject*)IndexOfSecondGraph;
   grName->DataBinding->Data = (TObject*)IndexOfGroupName;
   // this line is critical
   GroupsGridTableView->DataController->CustomDataSource = GroupDataSource;
}
//---------------------------------------------------------------------------

void __fastcall TGroupForm::LoadGroupData()
{
  for (int i=0; i<Diag->Groups->Count; i++) {
    GROUPS *Group = new GROUPS((GROUPS*)Diag->Groups->Items[i]);
    GroupList->Add(Group);
    }
}
//---------------------------------------------------------------------------

void __fastcall TGroupForm::FormDeactivate(TObject *Sender)
{
  delete GroupOptionsForm;
  delete GroupList;
  delete GroupDataSource;
}
//---------------------------------------------------------------------------

// OK button
void __fastcall TGroupForm::Button1Click(TObject *Sender)
{
  int i;
  GROUPS* Group;

  Diag->Modified = true;
  // delete old groups
  if (Diag->Groups->Count > 0) {
     for (i=0; i<Diag->Groups->Count; i++) {
       Group = (GROUPS*)Diag->Groups->Items[i];
       delete Group;
       Diag->Groups->Items[i] = 0;
       }
     Diag->Groups->Clear();
     Diag->Groups->Capacity = 10;
     }

  if (GroupList->Count > 0) {
    for (i=0; i<GroupList->Count; i++) {
      Group = (GROUPS*)GroupList->Groups[i];
      if (!Group->code1.IsEmpty() && !Group->code2.IsEmpty()) {
        Group = new GROUPS(GroupList->Groups[i]);
        Diag->Groups->Add(Group);
        }
      }  
    }
}
//---------------------------------------------------------------------------

void __fastcall TGroupForm::grOptionsPropertiesButtonClick(TObject *Sender,
      int AButtonIndex)
{
   GROUPS* Group;

   TcxCustomGridRecord *AFocusedRecord =
       GroupsGridTableView->Controller->FocusedRecord;

   if (AFocusedRecord->RecordIndex == -1) {
     GroupDataSource->TempGroup = new GROUPS();
     Group = GroupDataSource->TempGroup;
     *Group = DefaultGroup;
     }
   else
     Group = GroupList->Groups[AFocusedRecord->RecordIndex];

   GroupOptionsForm->RadioGroup1->ItemIndex = (Group->Position==INLINE) ? 0 : 1;
   GroupOptionsForm->GrupLineWidthComboBox->SetLineWidth(Group->LineWidth);
   Diag->SetColorBox(GroupOptionsForm->ColorBox2, (TColor)Group->Color);
   GroupOptionsForm->GroupFont = Group->Font;

   if (GroupOptionsForm->ShowModal() == mrOk) {
     double LineWidth;
     LineWidth = GroupOptionsForm->GrupLineWidthComboBox->GetLineWidth();

     Group->Position = (GroupOptionsForm->RadioGroup1->ItemIndex) ? ABOVELINE : INLINE;
     Group->Font = GroupOptionsForm->GroupFont;
     Group->LineWidth = LineWidth;
     Group->Color = GroupOptionsForm->ColorBox2->Selected;

     if (GroupOptionsForm->CheckBox1->Checked) {  // apply to all groups
	   Diag->Default.GroupAttr.Position = (GroupOptionsForm->RadioGroup1->ItemIndex) ? ABOVELINE : INLINE;
	   Diag->Default.GroupAttr.Color = GroupOptionsForm->ColorBox2->Selected;
	   Diag->Default.GroupAttr.LineWidth = LineWidth;
	   Diag->Default.GroupAttr.Font = GroupOptionsForm->GroupFont;

       for (int i=0; i<GroupList->Count; i++) {
         GROUPS* Groupi = GroupList->Groups[i];
         Groupi->Position = (GroupOptionsForm->RadioGroup1->ItemIndex) ? ABOVELINE : INLINE;
         Groupi->Font = GroupOptionsForm->GroupFont;
         Groupi->LineWidth = LineWidth;
         Groupi->Color = GroupOptionsForm->ColorBox2->Selected;
         }

       }
     }
}
//---------------------------------------------------------------------------

// Help button
void __fastcall TGroupForm::Button3Click(TObject *Sender)
{
   Application->HelpContext(IDH_Groups_Dialog_Box);
}
//---------------------------------------------------------------------------

bool __fastcall TGroupForm::FormHelp(WORD Command, int Data, bool &CallHelp)
{
   return true;
}
//---------------------------------------------------------------------------

