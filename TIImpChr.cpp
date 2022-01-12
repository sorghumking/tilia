//---------------------------------------------------------------------------

#include <vcl.h>
#include "pch.h"
#pragma hdrstop

#include "TIImpChr.h"
#ifndef TIGlobalsH
#include "TIGlobals.h"
#endif
#ifndef TGUtilsH
#include "TGUtils.h"
#endif
#include <map>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxGroupBox"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxMaskEdit"
#pragma link "cxRadioGroup"
#pragma link "cxSpinEdit"
#pragma link "cxTextEdit"
#pragma link "cxButtons"
#pragma link "cxButtons"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxGroupBox"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxMaskEdit"
#pragma link "cxRadioGroup"
#pragma link "cxSpinEdit"
#pragma link "cxTextEdit"
#pragma link "cxCheckBox"
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
#pragma resource "*.dfm"
TImportChronForm *ImportChronForm;
TImportClamForm *ImportClamForm;
TImportBaconForm *ImportBaconForm;
TImportBchronForm *ImportBchronForm;
TImportOxCalForm *ImportOxCalForm;

//---------------------------------------------------------------------------

__fastcall TImportChronForm::TImportChronForm(TComponent* Owner)
	: TForm(Owner)
{
   TSSForm = (TTilSpreadSheetForm*)Owner;
}
//---------------------------------------------------------------------------

// Ok button
void __fastcall TImportChronForm::cxButton1Click(TObject *Sender)
{
   return;
}
//---------------------------------------------------------------------------

bool TImportChronForm::OpenFile(UnicodeString& FileName)
{
   if (!tiGlobals->BaconClamDir.IsEmpty()) {
	 if (DirectoryExists(tiGlobals->BaconClamDir, true))
	   OpenDialog1->InitialDir = tiGlobals->BaconClamDir;
	 }
   if (OpenDialog1->Execute()) {
	 FileName = OpenDialog1->FileName;
	 UnicodeString FileExt = LowerCase(ExtractFileExt(FileName));
	 if (FileExt != InputFileExt) {
	   UnicodeString msg = L"File" + FileName + L" is not a " + InputFileExt + L" file!";
	   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return false;
	   }
	 }
   else
     return false;
   return true;
}
//---------------------------------------------------------------------------

void TImportChronForm::CloseFile(void)
{
   reader->Close();
   delete reader;
   delete InputFileStream;
}
//---------------------------------------------------------------------------

bool TImportChronForm::GetTabbedValue(AnsiString& line, double& value)
{
   int pos = line.Pos("\t");
   if (pos > 0) {
	 if (!TryStrToFloat(line.SubString(1,pos-1), value))
	   return false;
	 line.Delete(1,pos);
	 }
   else if (!TryStrToFloat(line, value))
	 return false;
   return true;
}
//---------------------------------------------------------------------------

void TImportChronForm::WriteToSpreadsheet(UnicodeString Model)
{
   UnicodeString msg;
   int AgeValueType;

   switch (cxRadioGroup1->ItemIndex) {
	 case 0:
	   AgeValueType = avtMedian;
	   break;
	 case 1:
	   AgeValueType = avtWeightedMean;
	   break;
	 }

   UnicodeString ChronNo = VarToStr(cxSpinEdit1->Value);
   UnicodeString VarCodeOlder = L"#Chron" + ChronNo + L".Old";
   int ChronRowOlder = TSSForm->FindRowCodeIC(VarCodeOlder, TSSForm->ProfGrid1);
   if (ChronRowOlder == 0) {
	 msg = Model + L" max age";
	 TSSForm->EnterSSMetadataCode(VarCodeOlder, msg);
	 }

   UnicodeString VarCodeYounger = L"#Chron" + ChronNo + L".Young";
   int ChronRowYounger = TSSForm->FindRowCodeIC(VarCodeYounger, TSSForm->ProfGrid1);
   if (ChronRowYounger == 0) {
	 msg = Model + L" min age";
	 TSSForm->EnterSSMetadataCode(VarCodeYounger, msg);
	 }

   UnicodeString VarCodeAge = L"#Chron" + ChronNo;
   int ChronRow = TSSForm->FindRowCodeIC(VarCodeAge, TSSForm->ProfGrid1);
   if (ChronRow == 0) {
	 switch (AgeValueType) {
	   case avtMedian:
		 msg = Model + L" median age";
		 TSSForm->EnterSSMetadataCode(VarCodeAge, msg);
		 break;
	   case avtWeightedMean:
		 msg = Model + L" weighted mean age";
		 TSSForm->EnterSSMetadataCode(VarCodeAge, msg);
		 break;
	   }
	 }

   ChronRow = TSSForm->FindRowCodeIC(VarCodeAge, TSSForm->ProfGrid1);
   ChronRowOlder = TSSForm->FindRowCodeIC(VarCodeOlder, TSSForm->ProfGrid1);
   ChronRowYounger = TSSForm->FindRowCodeIC(VarCodeYounger, TSSForm->ProfGrid1);

   bool round = cxCheckBox1->Checked;
   double Value;

   int StartCol = TSSForm->AbsHeaderColCount(TSSForm->ProfGrid1);
   int EndCol = TSSForm->AbsContentColCount(TSSForm->ProfGrid1);
   for (int col=StartCol; col<=EndCol; col++) {
	 double Depth = TSSForm->ProfGrid1->AbsoluteCells[col][1]->Value;
	 map<double,BACON>::iterator itr = Bacon.find(Depth);
	 if (itr != Bacon.end()) {
	   switch (AgeValueType) {
		 case avtMedian:
		   Value = (round) ? SimpleRoundTo(itr->second.median,0) : itr->second.median;
		   TSSForm->ProfGrid1->AbsoluteCells[col][ChronRow]->Value = Value;
		   break;
		 case avtWeightedMean:
		   Value = (round) ? SimpleRoundTo(itr->second.wmean,0) : itr->second.wmean;
		   TSSForm->ProfGrid1->AbsoluteCells[col][ChronRow]->Value = Value;
		   break;
		 }
	   Value = (round) ? SimpleRoundTo(itr->second.min,0) : itr->second.min;
	   TSSForm->ProfGrid1->AbsoluteCells[col][ChronRowYounger]->Value = Value;
	   Value = (round) ? SimpleRoundTo(itr->second.max,0) : itr->second.max;
	   TSSForm->ProfGrid1->AbsoluteCells[col][ChronRowOlder]->Value = Value;
	   }
	 }
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

__fastcall TImportClamForm::TImportClamForm(TComponent* Owner)
	: TImportChronForm(Owner)
{
   Caption = L"Import Clam Chronology";
   cxRadioGroup1->Visible = false;
   InputFileExt = L".txt";
}
//---------------------------------------------------------------------------

void __fastcall TImportClamForm::cxButton1Click(TObject *Sender)
{
   if (ImportClam())
	 ModalResult = mrOk;
}
//---------------------------------------------------------------------------

bool TImportClamForm::ImportClam(void)
{
   UnicodeString FileName;
   UnicodeString msg;
   map<double,CLAM> Clam;

   if (!OpenFile(FileName))
	 return false;

   InputFileStream = new TFileStream(FileName, fmOpenRead);
   reader = new TStreamReader(InputFileStream, TEncoding::ASCII);

   /*
   depth	min95%	max95%	best	accrate
   0	-67	39	-42	28.54
   1	-39	66	-14	28.53
   */

   AnsiString line;
   line = reader->ReadLine(); // header line
   int errors = 0;
   double depth;
   while (reader->Peek() >= 0) {
	 line = reader->ReadLine();
	 CLAM clam;
	 errors++;
	 if (!GetTabbedValue(line, depth))
	   continue;
	 if (!GetTabbedValue(line, clam.min))
	   continue;
	 if (!GetTabbedValue(line, clam.max))
	   continue;
	 if (!GetTabbedValue(line, clam.best))
	   continue;
	 //if (!GetTabbedValue(line, clam.accrate))
	 //  continue;
	 errors--;
	 Clam[depth] = clam;
	 }

   CloseFile();

   UnicodeString ChronNo = VarToStr(cxSpinEdit1->Value);
   UnicodeString VarCodeOlder = L"#Chron" + ChronNo + L".Old";
   int ChronRowOlder = TSSForm->FindRowCodeIC(VarCodeOlder, TSSForm->ProfGrid1);
   if (ChronRowOlder == 0)
	 TSSForm->EnterSSMetadataCode(VarCodeOlder, L"Clam max age");

   UnicodeString VarCodeYounger = L"#Chron" + ChronNo + L".Young";
   int ChronRowYounger = TSSForm->FindRowCodeIC(VarCodeYounger, TSSForm->ProfGrid1);
   if (ChronRowYounger == 0)
	 TSSForm->EnterSSMetadataCode(VarCodeYounger, L"Clam min age");

   UnicodeString VarCodeAge = L"#Chron" + ChronNo;
   int ChronRow = TSSForm->FindRowCodeIC(VarCodeAge, TSSForm->ProfGrid1);
   if (ChronRow == 0)
	 TSSForm->EnterSSMetadataCode(VarCodeAge, L"Clam best age");

   ChronRow = TSSForm->FindRowCodeIC(VarCodeAge, TSSForm->ProfGrid1);
   ChronRowOlder = TSSForm->FindRowCodeIC(VarCodeOlder, TSSForm->ProfGrid1);
   ChronRowYounger = TSSForm->FindRowCodeIC(VarCodeYounger, TSSForm->ProfGrid1);

   bool round = cxCheckBox1->Checked;
   double Value;

   int StartCol = TSSForm->AbsHeaderColCount(TSSForm->ProfGrid1);
   int EndCol = TSSForm->AbsContentColCount(TSSForm->ProfGrid1);
   for (int col=StartCol; col<=EndCol; col++) {
	 double Depth = TSSForm->ProfGrid1->AbsoluteCells[col][1]->Value;
	 map<double,CLAM>::iterator itr = Clam.find(Depth);
	 if (itr != Clam.end()) {
	   Value = (round) ? SimpleRoundTo(itr->second.best,0) : itr->second.best;
	   TSSForm->ProfGrid1->AbsoluteCells[col][ChronRow]->Value = Value;
	   Value = (round) ? SimpleRoundTo(itr->second.min,0) : itr->second.min;
	   TSSForm->ProfGrid1->AbsoluteCells[col][ChronRowYounger]->Value = Value;
	   Value = (round) ? SimpleRoundTo(itr->second.max,0) : itr->second.max;
	   TSSForm->ProfGrid1->AbsoluteCells[col][ChronRowOlder]->Value = Value;
	   }
	 }

   if (errors > 0) {
	 msg = L"Clam ages imported, but errors were encounterd while reading the file.";
	 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 }

   return true;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

__fastcall TImportBaconForm::TImportBaconForm(TComponent* Owner)
	: TImportChronForm(Owner)
{
   Caption = L"Import Bacon Chronology";
   InputFileExt = L".txt";
}
//---------------------------------------------------------------------------

void __fastcall TImportBaconForm::cxButton1Click(TObject *Sender)
{
   if (ImportBacon())
	 ModalResult = mrOk;
}
//---------------------------------------------------------------------------

bool TImportBaconForm::ImportBacon(void)
{
   UnicodeString FileName;
   UnicodeString msg;

   if (!OpenFile(FileName))
	 return false;

   InputFileStream = new TFileStream(FileName, fmOpenRead);
   reader = new TStreamReader(InputFileStream, TEncoding::ASCII);

   /*
   depth	min	max	median	wmean
   1	-60	20.8	-34.6	-30
   4	-54.3	242.8	22.9	43.7
   */

   AnsiString line;
   line = reader->ReadLine(); // header line
   int errors = 0;
   double depth;
   while (reader->Peek() >= 0) {
	 line = reader->ReadLine();
	 BACON bacon;
	 errors++;
	 if (!GetTabbedValue(line, depth))
	   continue;
	 if (!GetTabbedValue(line, bacon.min))
	   continue;
	 if (!GetTabbedValue(line, bacon.max))
	   continue;
	 if (!GetTabbedValue(line, bacon.median))
	   continue;
	 if (!GetTabbedValue(line, bacon.wmean))
	   continue;
	 errors--;
	 Bacon[depth] = bacon;
	 }

   CloseFile();
   WriteToSpreadsheet(L"Bacon");
   if (errors > 0) {
	 msg = L"Bacon ages imported, but errors were encounterd while reading the file.";
	 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 }
   return true;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

__fastcall TImportBchronForm::TImportBchronForm(TComponent* Owner)
	: TImportChronForm(Owner)
{
   Caption = L"Import Bchron Chronology";
   InputFileExt = L".csv";
}
//---------------------------------------------------------------------------

void __fastcall TImportBchronForm::cxButton1Click(TObject *Sender)
{
   if (ImportBchron())
	 ModalResult = mrOk;
}
//---------------------------------------------------------------------------

bool TImportBchronForm::ImportBchron(void)
{
   UnicodeString FileName;
   UnicodeString msg;

   if (!OpenFile(FileName))
	 return false;

   InputFileStream = new TFileStream(FileName, fmOpenRead);
   reader = new TStreamReader(InputFileStream, TEncoding::ASCII);

   AnsiString line;
   line = reader->ReadLine(); // header line
   int errors = 0;
   double depth;
   AnsiString depstr;
   while (reader->Peek() >= 0) {
	 line = reader->ReadLine();
	 BACON bacon;
	 errors++;
	 // "    Pos43","Min.   : 662  ","1st Qu.:1078  ","Median :1095  ","Mean   :1094  ","3rd Qu.:1132  ","Max.   :1223  "
	 int start = line.Pos("Pos") + 3;
	 int count = 1;
	 int idx = start + 1;
	 while (line[idx++] != '\"')
	   count++;
	 if (!TryStrToFloat(line.SubString(start,count),depth))
	   continue;
	 if (!GetBchron(line,"Min.",bacon.min))
	   continue;
	 if (!GetBchron(line,"Median",bacon.median))
	   continue;
	 if (!GetBchron(line,"Mean",bacon.wmean))
	   continue;
	 if (!GetBchron(line,"Max.",bacon.max))
	   continue;
	 errors--;
	 Bacon[depth] = bacon;
	 }

   CloseFile();
   WriteToSpreadsheet(L"Bchron");
   if (errors > 0) {
	 msg = L"Bchron ages imported, but errors were encounterd while reading the file.";
	 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 }
   return true;
}
//---------------------------------------------------------------------------

bool TImportBchronForm::GetBchron(AnsiString line, AnsiString param, double& value)
{
   int idx;
   if ((idx = line.Pos(param)) == 0)
	 return false;
   idx += param.Length();
   while (line[idx++] != ':');
   int start = idx++;
   int count = 1;
   while (line[idx++] != '\"')
	 count++;
   //ShowMessage(L"start = " + IntToStr(start) + L", count = " + IntToStr(count) + L", " + line.SubString(start,count).Trim());
   return (TryStrToFloat(line.SubString(start,count).Trim(),value));
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

__fastcall TImportOxCalForm::TImportOxCalForm(TComponent* Owner)
	: TImportChronForm(Owner)
{
   Caption = L"Import OxCal Chronology";
   InputFileExt = L".csv";
}
//---------------------------------------------------------------------------

void __fastcall TImportOxCalForm::cxButton1Click(TObject *Sender)
{
   if (ImportOxCal())
	 ModalResult = mrOk;
}
//---------------------------------------------------------------------------

bool TImportOxCalForm::ImportOxCal(void)
{
   UnicodeString FileName;
   UnicodeString msg;
   vector<UnicodeString> elements;
   UnicodeString delimiter = L",";
   int from = 0;
   int to = 0;
   int mu = 0;
   int median = 0;
   int z = 0;
   double depth;
   double error;

   if (!OpenFile(FileName))
	 return false;

   InputFileStream = new TFileStream(FileName, fmOpenRead);
   reader = new TStreamReader(InputFileStream, TEncoding::ASCII);

   // "intcal20_t","intcal20_dt","z","mu","median","sed","from_95_4","to_95_4",
   // "name","z","mu","median","from_95_4","to_95_4",
   AnsiString line;
   line = reader->ReadLine(); // header line
   ParseDelimitedList(line, elements, delimiter);
   for (unsigned int i=0; i<elements.size(); i++) {
	 if (SameText(elements[i],L"z"))
	   z = i;
	 else if (SameText(elements[i],L"mu"))
	   mu = i;
	 else if (SameText(elements[i],L"median"))
	   median = i;
	 else if (SameText(elements[i],L"from_95_4"))
	   from = i;
	 else if (SameText(elements[i],L"to_95_4"))
	   to = i;
	 }

   if (z == 0 || from == 0 || to == 0) {
	 msg = L"Format of OxCal output file not recognized.";
	 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 CloseFile();
	 return false;
	 }
   if (mu == 0 && median == 0) {
	 msg = L"OxCal output file is missing both mu and median.";
	 if (MessageDlg(msg, mtWarning, TMsgDlgButtons() << mbOK << mbCancel, 0) == mrCancel) {
	   CloseFile();
	   return false;
	   }
	 }

   // -3766,277.3,794,5717,5725,0.14,6220,5209,
   // "794 cm",794,5708,5709,5999,5412,

   int errors = 0;
   AnsiString depstr;
   while (reader->Peek() >= 0) {
	 line = reader->ReadLine();
	 ParseDelimitedList(line, elements, delimiter);
	 BACON bacon;
	 errors++;
	 if (!TryStrToFloat(elements[z],depth))
	   continue;
	 if (!TryStrToFloat(elements[from],bacon.max))
	   continue;
	 if (!TryStrToFloat(elements[to],bacon.min))
	   continue;
	 if (mu > 0) {
	   if (!TryStrToFloat(elements[mu],bacon.wmean))
		 continue;
	   }
	 if (median > 0) {
	   if (!TryStrToFloat(elements[median],bacon.median))
		 continue;
	   }
	 errors--;
	 Bacon[depth] = bacon;
	 }

   CloseFile();
   WriteToSpreadsheet(L"OxCal");
   if (errors > 0) {
	 msg = L"OxCal ages imported, but errors were encounterd while reading the file.";
	 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 }
   return true;
}
//---------------------------------------------------------------------------


