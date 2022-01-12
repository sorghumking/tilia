//---------------------------------------------------------------------------

#include <vcl.h>
#include "pch.h"
#pragma hdrstop

#include "TIExpChr.h"
#ifndef TIGlobalsH
#include "TIGlobals.h"
#endif
#ifndef TIShoMemH
#include "TIShoMem.h"
#endif
//#ifndef TIMemoH
//#include "TIMemo.h"
//#endif
#include <iostream.h>
#include <fstream.h>
#include <IOUtils.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxRadioGroup"
#pragma link "cxButtons"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxRadioGroup"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
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
#pragma link "AdvEdit"
#pragma link "cxLabel"
#pragma link "cxCheckBox"
#pragma resource "*.dfm"
TChronControlExportForm *ChronControlExportForm;
//---------------------------------------------------------------------------
__fastcall TChronControlExportForm::TChronControlExportForm(AGEMODEL* age_model,
	TGeochronList* geochron_list, TcxTreeView* tree_view, map<double,double>& depths, TComponent* Owner) :
	TForm(Owner)
{
   AgeModel = age_model;
   GeochronList = geochron_list;
   Depths = depths;

   for (int i=0; i<tree_view->Items->Count; i++) {
	 TTreeNode* Node = tree_view->Items->Item[i];
	 UnicodeString Text = Node->Text;
	 while (Node->Level > 0) {
	   TTreeNode* Parent = Node->Parent;
	   if (SameText(Parent->Text, L"Geochronologic")) {
		 GeochronControls.insert(Text);
		 break;
		 }
	   else
		 Node = Parent;
	   }
	 }
}
//---------------------------------------------------------------------------

void __fastcall TChronControlExportForm::cxRadioGroup1Click(TObject *Sender)
{
   switch (cxRadioGroup1->ItemIndex) {
	 case ccoClam:
	   cxRadioGroup2->Enabled = false;
	   cxGroupBox1->Visible = false;
	   cxButton1->Enabled = true;
	   break;
	 case ccoBacon:
	   cxRadioGroup2->Enabled = true;
	   cxGroupBox1->Visible = false;
	   cxButton1->Enabled = (cxRadioGroup2->ItemIndex > -1);
	   break;
	 case ccoBchron:
	   cxRadioGroup2->Enabled = true;
	   cxGroupBox1->Visible = false;
	   cxButton1->Enabled = (cxRadioGroup2->ItemIndex > -1);
	   break;
	 case ccoPSequence:
	   cxRadioGroup2->Enabled = true;
	   cxButton1->Enabled = (cxRadioGroup2->ItemIndex > -1);
	   SetOxCalInterval();
	   cxGroupBox1->Visible = true;
	   break;
	 }
}
//---------------------------------------------------------------------------

void TChronControlExportForm::SetOxCalInterval(void)
{
   double interval = (Depths.rbegin()->first - Depths.begin()->first)/100;
   int round_to = (int)Floor((Math::Log10(interval)));
   interval = SimpleRoundTo(interval,round_to);
   AdvEdit1->Text = FloatToStr(interval);
}
//---------------------------------------------------------------------------

void __fastcall TChronControlExportForm::cxRadioGroup2Click(TObject *Sender)
{
   switch (cxRadioGroup1->ItemIndex) {
	 case ccoBacon:
	 case ccoBchron:
	 case ccoPSequence:
	   cxButton1->Enabled = (cxRadioGroup2->ItemIndex > -1);
	   break;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TChronControlExportForm::cxButton1Click(TObject *Sender)
{
   AnsiString line;
   AnsiString text;
   AnsiString comma(",");
   UnicodeString msg;
   multimap<double,int> index;  // depth, index in AgeModel->ChronControls
   multimap<double,int>::iterator itr;
   multimap<double,int>::reverse_iterator ritr;
   list<OXCALSCRIPT> OxCal;
   UnicodeString Name;
   UnicodeString calcurve;
   double age;
   double ageold;
   double ageyoung;
   double sd;
   double thickness;
   double depth;
   double error;
   int k;
   double thick;
   double interval;
   int reservoir;
   bool jiggle = false;
   UnicodeString Directory;
   UnicodeString DepthsFileName;
   bool topboundary = false;

   if (!tiGlobals->BaconClamDir.IsEmpty()) {
	 if (DirectoryExists(tiGlobals->BaconClamDir, true))
	   SaveDialog1->InitialDir = tiGlobals->BaconClamDir;
	 }

   if (cxRadioGroup1->ItemIndex == ccoPSequence) {
	 if (cxRadioButton2->Checked && Depths.size() > (unsigned int)3*AgeModel->ChronControls->Count) {
	   msg = L"A large number of Date() functions will greatly increase run time, ";
	   msg += L"and the model may not converge. Consider using interpolation.";
	   if (MessageDlg(msg, mtWarning, TMsgDlgButtons() << mbOK << mbCancel, 0) == mrCancel)
		 return;
	   }
	 SaveDialog1->DefaultExt = L".oxcal";
	 SaveDialog1->Filter = L"OxCal input file|*.oxcal";
	 }

   if (SaveDialog1->Execute()) {
	 UnicodeString FileName = SaveDialog1->FileName;
	 UnicodeString FileExt = LowerCase(ExtractFileExt(FileName));
	 switch (cxRadioGroup1->ItemIndex) {
	   case ccoClam:
	   case ccoBacon:
	   case ccoBchron:
		 if (!SameText(FileExt,L".csv"))
		   FileName = ExtractFilePath(FileName) + ExtractFileName(FileName) + ".csv";
		 break;
	   case ccoPSequence:
		 if (!SameText(FileExt,L".oxcal"))
		   FileName = ExtractFilePath(FileName) + ExtractFileName(FileName) + ".oxcal";
		 break;
	   }

	 UnicodeString tname = TPath::GetGUIDFileName(false);
	 UnicodeString TempFileName = ExtractFilePath(FileName) + tname + ExtractFileExt(FileName);
	 TFileStream*  TempFileStream = new TFileStream(TempFileName, fmCreate);
	 TStreamWriter* writer = new TStreamWriter(TempFileStream, TEncoding::ASCII, 1024);

	 // obtain index to ChronControls ordered by depth
	 for (int i=0; i<AgeModel->ChronControls->Count; i++) {
	   CHRON* ChronControl = (CHRON*)AgeModel->ChronControls->Items[i];
	   if (ChronControl->Depth.IsEmpty() || ChronControl->Depth.IsNull())
		 continue;
	   double depth = (double)ChronControl->Depth;
	   index.insert(pair<double,int>(depth,i));
	   }

	 switch (cxRadioGroup1->ItemIndex) {
	   case ccoClam:
		 line = "\"ID\",\"C14_age\",\"cal_BP\",\"error\",\"reservoir\",\"depth\"";
		 writer->WriteLine(line);
		 for (itr = index.begin(); itr != index.end(); itr++) {
		   int i = itr->second;
		   CHRON* ChronControl = (CHRON*)AgeModel->ChronControls->Items[i];
		   if (!GetAge(ChronControl, age))
			 continue;
		   if (!GetError(ChronControl, error))
			 continue;
		   Name = GetName(ChronControl);
		   reservoir = GetReservoir(ChronControl);
		   line = "\"" + Name + "\",";
		   writer->Write(line);
		   if (SameText(ChronControl->AgeUnits, L"Radiocarbon")) {
			 writer->Write(age);
			 writer->Write(AnsiString(",,"));
			 }
		   else {
			 writer->Write(comma);
			 writer->Write(age);
			 writer->Write(comma);
			 }
		   writer->Write(error);
		   writer->Write(comma);
		   if (reservoir > 0)
			 writer->Write(reservoir);
		   writer->Write(comma);
		   writer->Write(itr->first);
		   writer->WriteLine();
		   }
		 break;
	   case ccoBacon:
		 line = "labID,age,error,depth,cc";
		 writer->WriteLine(line);
		 for (itr = index.begin(); itr != index.end(); itr++) {
		   int i = itr->second;
		   CHRON* ChronControl = (CHRON*)AgeModel->ChronControls->Items[i];
		   if (!GetAge(ChronControl, age))
			 continue;
		   if (!GetError(ChronControl, error))
			 continue;
		   Name = GetName(ChronControl);
		   writer->Write(Name);
		   writer->Write(comma);
		   writer->Write(age);
		   writer->Write(comma);
		   writer->Write(error);
		   writer->Write(comma);
		   writer->Write(itr->first);
		   writer->Write(comma);
		   if (SameText(ChronControl->AgeUnits, L"Radiocarbon")) {
			 switch (cxRadioGroup2->ItemIndex) {
			   case cchIntCal:
				 writer->Write(AnsiString("1"));
				 break;
			   case cchSHCal:
				 writer->Write(AnsiString("3"));
				 break;
			   case cchMarine:
				 writer->Write(AnsiString("2"));
				 break;
			   }
			 }
		   else
			 writer->Write(AnsiString("0"));
		   writer->WriteLine();
		   }
		 break;
	   case ccoBchron:
		 line = "\"id\",\"age\",\"ageSd\",\"position\",\"thickness\",\"calCurve\"";
		 writer->WriteLine(line);
		 for (itr = index.begin(); itr != index.end(); itr++) {
		   int i = itr->second;
		   CHRON* ChronControl = (CHRON*)AgeModel->ChronControls->Items[i];
		   if (!GetAge(ChronControl, age))
			 continue;
		   if (!GetError(ChronControl, error))
			 continue;
		   Name = GetName(ChronControl);
		   line = "\"" + Name + "\"";
		   writer->Write(line);
		   writer->Write(comma);
		   writer->Write(age);
		   writer->Write(comma);
		   writer->Write(error);
		   writer->Write(comma);
		   writer->Write(itr->first);
		   writer->Write(comma);
		   writer->Write(GetThickness(ChronControl));
		   writer->Write(comma);
		   if (SameText(ChronControl->AgeUnits, L"Radiocarbon")) {
			 switch (cxRadioGroup2->ItemIndex) {
			   case cchIntCal:
				 calcurve = L"\"intcal20\"";
				 break;
			   case cchSHCal:
				 calcurve = L"\"shcal20\"";
				 break;
			   case cchMarine:
				 calcurve = L"\"marine20\"";
				 break;
			   }
			 }
		   else
			 calcurve = L"\"normal\"";
		   writer->Write(calcurve);
		   writer->WriteLine();
		   }
		 break;
	   case ccoPSequence:
		 k = (cxRadioGroup3->ItemIndex == 0) ? 1 : 100;
		 thick = SimpleRoundTo((Depths.rbegin()->first-Depths.begin()->first)/100.0,0);
		 if (cxRadioGroup3->ItemIndex == 0) {
		   k = 1;
		   if (thick > 10)
			 thick = 10;
		   else if (thick < 1)
			 thick = 1;
		   }
		 else {
		   k = 100;
		   if (thick > 0.1)
			 thick = 0.1;
		   else if (thick < 0.01)
			 thick = 0.01;
		   }
		 interval = AdvEdit1->Text.ToDouble();
		 if (interval > 0) {
		   interval = 1.0/interval;
		   int round_to = (int)Floor((Math::Log10(interval)));
		   interval = SimpleRoundTo(interval,round_to);
		   }

		 // the R_Date and C_Date chron controls
		 for (ritr = index.rbegin(); ritr != index.rend(); ritr++) {
		   CHRON* ChronControl = (CHRON*)AgeModel->ChronControls->Items[ritr->second];
		   if (!ChronControl->AgeValue.IsEmpty() && !ChronControl->AgeValue.IsNull())
			 age = ChronControl->AgeValue;
		   else
			 continue;
		   if (!ChronControl->AgeLimitOlder.IsEmpty() && !ChronControl->AgeLimitOlder.IsNull())
			 ageold = ChronControl->AgeLimitOlder - age;
		   else
			 continue;
		   if (!ChronControl->AgeLimitYounger.IsEmpty() && !ChronControl->AgeLimitYounger.IsNull())
			 ageyoung = age - ChronControl->AgeLimitYounger;
		   else
			 continue;
		   sd = Max(ageold,ageyoung);

		   Name = GetName(ChronControl);
		   if (SameText(Name,L"Core top") && SameText(ChronControl->AgeUnits,L"Calendar")) {
			 line = "   Boundary(\"Top\", C_Date(" + FloatToStr(age) + "," + FloatToStr(sd) +
					")) { z=" + FloatToStr(ritr->first) + "; };";
			 topboundary = true;
			 }
		   else {
			 line = (SameText(ChronControl->AgeUnits,L"Calendar")) ? "   C_Date" : "   R_Date";
			 line += "(\"";
			 line += (Name + "\"," + FloatToStr(age) + "," + FloatToStr(sd) + ") { z=" + FloatToStr(ritr->first) + ";");
			 if (SameText(ChronControl->AgeUnits,L"Radiocarbon"))
			   line += " Outlier(0.05);";
			 line += " };";
			 }
		   OxCal.push_back(OXCALSCRIPT(ritr->first,line));
		   }

		 // combine any dates at same depths
		 list<OXCALSCRIPT>::iterator it = OxCal.begin();
		 do {
			list<OXCALSCRIPT>::iterator it1 = it;
			list<OXCALSCRIPT>::iterator it2 = it;
			do {
			   if (++it != OxCal.end()) {
				 if (it->Depth == it1->Depth)
				   it2++;
				 }
			   } while (it != OxCal.end() && it->Depth == it1->Depth);
			if (it1 != it2) {
			  line = "   Combine(\"" + FloatToStr(it1->Depth) + "\")";
			  OxCal.insert(it1,OXCALSCRIPT(it1->Depth,line));
			  line = "   {";
			  OxCal.insert(it1,OXCALSCRIPT(it1->Depth,line));
			  it2++;
			  for (it = it1; it != it2; it++) {
				it->Line.Insert(" ",1);
				int posz = it->Line.Pos("z=");
				int poso = it->Line.Pos("Outlier");
				it->Line.Delete(posz,poso-posz);
				}
			  line = "    z=" + FloatToStr(it1->Depth) + ";";
			  OxCal.insert(it2,OXCALSCRIPT(it1->Depth,line));
			  line = "   };";
			  OxCal.insert(it2,OXCALSCRIPT(it1->Depth,line));
			  it = it2;
			  }
		   } while (it != OxCal.end());

		 // create boundaries
		 depth = Max(Depths.rbegin()->first, OxCal.front().Depth) + thick;
		 line = "   Boundary(\"Bottom\") { z=" + FloatToStr(depth) + "; };";
		 OxCal.push_front(OXCALSCRIPT(depth,line));
		 if (!topboundary) {
		   depth = Min(Depths.begin()->first, OxCal.back().Depth) - thick;
		   line = "   Boundary(\"Top\") { z=" + FloatToStr(depth) + "; };";
		   OxCal.push_back(OXCALSCRIPT(depth,line));
		   }

		 // Date functions
   /*
   R_Date("CAMS-70483",11270,50) { z=1173; Outlier(0.05); };
   Combine("1158")
   {
	R_Date("CAMS-70482",10240,60) { Outlier(0.05); };
	R_Date("FAKE-001",10200,50) { Outlier(0.05); };
	z=1158;
   };
   R_Date("CAMS-76111",8920,60) { z=1101.5; Outlier(0.05); };
   R_Date("CAMS-70481",8170,50) { z=1073; Outlier(0.05); };

   C_Date("Ambrosia rise",120,10) { z=166; };
   Boundary("Top", C_Date(-38,1)) { z=118; };
   */

   // Date("1490 cm") { z=1490; };
   // Date("1482 cm") { z=1482; };

		 if (cxRadioButton2->Checked) {
		   map<double,double>::iterator dit;
		   for (dit = Depths.begin(); dit != Depths.end(); dit++) {
			 line = "   Date(\"" + FloatToStr(dit->first) + " cm\") { z=" +
					FloatToStr(dit->first) + "; };";
			 if (dit->first < OxCal.back().Depth)
			   OxCal.insert(OxCal.end(),OXCALSCRIPT(dit->first,line));
			 else {
			   for (it = OxCal.begin(); it != OxCal.end(); it++) {
				 if (it->Depth == dit->first)
				   break;
				 else if (it->Depth < dit->first) {
				   OxCal.insert(it,OXCALSCRIPT(dit->first,line));
				   break;
				   }
				 }
			   }
			 }
		   }

		 UnicodeString FName = ExtractFileName(FileName);
		 int pos = FName.Pos(L".oxcal");
		 FName = FName.SubString(1,pos-1);
		 line = "Options()";
		 writer->WriteLine(line);
		 line = L" {";
		 writer->WriteLine(line);
		 line = L"  BCAD=FALSE;";
		 writer->WriteLine(line);
		 switch (cxRadioGroup2->ItemIndex) {
		   case cchIntCal:
			 calcurve = L"intcal20.14c";
			 break;
		   case cchSHCal:
			 calcurve = L"shcal20.14c";
			 break;
		   case cchMarine:
			 calcurve = L"marine20.14c";
			 break;
		   }
		 line = L"  Curve(\"" + calcurve + L"\",\"" + calcurve + L"\");";
		 writer->WriteLine(line);
		 line = L"  SD1=FALSE;";
		 writer->WriteLine(line);
		 line = L"  SD2=TRUE;";
		 writer->WriteLine(line);
		 line = L" };";
		 writer->WriteLine(line);
		 line = L" Plot()";
		 writer->WriteLine(line);
		 line = L" {";
		 writer->WriteLine(line);
		 line = L"  Outlier_Model(\"General\", T(5), U(0,4),\"t\");";
		 writer->WriteLine(line);
		 // P_Sequence("NELSON88",1,,U(-2,2))
		 line = L"  P_Sequence(\"" + FName + L"\"," + IntToStr(k) + "," +
				FloatToStr(interval) + L",U(-2,2))";
		 writer->WriteLine(line);
		 line = L"  {";
		 writer->WriteLine(line);

		 for (it = OxCal.begin(); it != OxCal.end(); it++)
		   writer->WriteLine(it->Line);

		 line = L"  };";
		 writer->WriteLine(line);
		 line = L" };";
		 writer->WriteLine(line);
		 break;
	   }

	 writer->Flush();
	 writer->Close();
	 delete writer;
	 delete TempFileStream;
	 if (FileExists(FileName))
	   DeleteFileW(FileName);
	 bool success = RenameFile(TempFileName, FileName);
	 if (success) {
	   switch (cxRadioGroup1->ItemIndex) {
		 case ccoClam: msg = L"Clam"; break;
		 case ccoBacon: msg = L"Bacon"; break;
		 case ccoBchron: msg = L"Bchron"; break;
		 case ccoPSequence: msg = L"Oxcal P_Sequence"; break;
		 }
	   msg += (L" file " + FileName + L" written.");

	   DepthsFileName = FileName;
	   if (WriteDepths(DepthsFileName))
		 msg += (L"\nDepths file " + DepthsFileName + L" written.");
	   MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);

	   if (cxRadioGroup1->ItemIndex == ccoBchron) {
		 for (itr = index.begin(); itr != index.end(); itr++) {
		   if (index.count(itr->first) > 1) {
			 jiggle = true;
			 break;
			 }
		   }
		 UnicodeString Name = ExtractFileName(FileName);
		 UnicodeString filename = Name;
		 UnicodeString depthsfilename = ExtractFileName(DepthsFileName);
		 int pos = Name.LowerCase().Pos(".csv");
		 if (pos > 0)
		   Name = Name.SubString(1,pos-1);
		 ShowMemoForm = new TShowMemoForm(L"Bchron commands", L"", NULL);
		 TcxRichEdit* RichEdit = ShowMemoForm->cxRichEdit1;
		 RichEdit->Properties->WordWrap = false;
		 msg = L"Suggested Bchron commands:";
		 ShowMemoForm->AddLine(msg, TFontStyles() << fsUnderline);
		 msg = L"\ninput = read.csv('" + filename + "',header=TRUE)";
		 ShowMemoForm->AddLine(msg);
		 msg = L"bchron = Bchronology(id=input$id,ages=input$age,ageSds=input$ageSd,";
		 msg += L"positions=input$position,positionThickness=input$thickness,calCurves=input$calCurve";
		 if (jiggle)
		   msg += L",jitterPositions=TRUE";
		 msg += L")";
		 ShowMemoForm->AddLine(msg);
		 msg = L"plot(bchron)";
		 ShowMemoForm->AddLine(msg);
		 msg = L"depths = read.csv('" + depthsfilename + "',header=TRUE)";
		 ShowMemoForm->AddLine(msg);
		 msg = L"predictAges = predict(bchron,newPositions=depths$Depth,newPositionThicknesses=depths$Thickness)";
		 ShowMemoForm->AddLine(msg);
		 msg = L"write.csv(t(summary(predictAges)),'" + Name + "_predict_ages.csv')";
		 ShowMemoForm->AddLine(msg);
		 ShowMemoForm->ShowModal();
		 delete ShowMemoForm;
		 }

	   tiGlobals->BaconClamDir = ExtractFileDir(FileName);
	   }
	 }
   ModalResult = mrOk;
}
//---------------------------------------------------------------------------

bool TChronControlExportForm::WriteDepths(UnicodeString& FileName)
{
   AnsiString comma(",");

   if (Depths.size() == 0)
	 return false;

   UnicodeString line;
   UnicodeString path = ExtractFilePath(FileName);
   UnicodeString fname = ExtractFileName(FileName);
   UnicodeString ext = ExtractFileExt(FileName);
   if (!ext.IsEmpty()) {
	 int pos = fname.Pos(ext);
	 fname = fname.SubString(1,pos-1);
	 }

   UnicodeString TempFileName;
   UnicodeString tname = TPath::GetGUIDFileName(false);

   switch (cxRadioGroup1->ItemIndex) {
	 case ccoClam:
	 case ccoBacon:
	   FileName = path + fname + L"_depths.txt";
	   TempFileName = path + tname + L".txt";
	   break;
	 case ccoBchron:
	 case ccoPSequence:
	   FileName = path + fname + L"_depths.csv";
	   TempFileName = path + tname + L".csv";
	   break;
	 }

   TFileStream*  TempFileStream = new TFileStream(TempFileName, fmCreate);
   TStreamWriter* writer = new TStreamWriter(TempFileStream, TEncoding::ASCII, 1024);

   if (cxRadioGroup1->ItemIndex == ccoBchron) {
	 line = "\"Depth\",\"Thickness\"";
	 writer->Write(line);
	 writer->WriteLine();
	 }
   else if (cxRadioGroup1->ItemIndex == ccoPSequence) {
	 line = "z";
     writer->Write(line);
	 writer->WriteLine();
	 }

   map<double,double>::iterator itr;

   switch (cxRadioGroup1->ItemIndex) {
	 case ccoClam:
	 case ccoBacon:
	 case ccoPSequence:
	   for (itr = Depths.begin(); itr != Depths.end(); itr++) {
		 writer->Write(itr->first);
		 writer->WriteLine();
		 }
	   break;
	 case ccoBchron:
	   for (itr = Depths.begin(); itr != Depths.end(); itr++) {
		 writer->Write(itr->first);
		 writer->Write(comma);
		 writer->Write(itr->second);
		 writer->WriteLine();
		 }
	   break;
	 }

   writer->Flush();
   writer->Close();
   delete writer;
   delete TempFileStream;
   if (FileExists(FileName))
	 DeleteFileW(FileName);
   bool success = RenameFile(TempFileName, FileName);
   return success;
}
//---------------------------------------------------------------------------

GEOCHRON* TChronControlExportForm::GetDate(int ID)
{
   GEOCHRON* Date = NULL;
   for (int i=0; i<GeochronList->Count(); i++) {
	 if (ID == GeochronList->Dates[i].ID) {
	   Date = &GeochronList->Dates[i];
	   break;
	   }
	 }
   return Date;
}
//---------------------------------------------------------------------------

bool TChronControlExportForm::GetAge(CHRON* ChronControl, double& age)
{
   if (ChronControl->AgeValue.IsEmpty() || ChronControl->AgeValue.IsNull())
	 return false;
   else {
	 age = (double)ChronControl->AgeValue;
	 return true;
	 }
}
//---------------------------------------------------------------------------

double TChronControlExportForm::GetThickness(CHRON* ChronControl)
{
   double thickness;
   if (ChronControl->AgeValue.IsEmpty() || ChronControl->AgeValue.IsNull())
	 thickness = 0;
   else
	 thickness = (double)ChronControl->Thickness;
   return thickness;
}
//---------------------------------------------------------------------------

bool TChronControlExportForm::GetError(CHRON* ChronControl, double& error)
{
   double error_older;
   double error_younger;

   if (ChronControl->AgeLimitOlder.IsEmpty() || ChronControl->AgeLimitOlder.IsNull())
	 return false;
   else
	 error_older = ChronControl->AgeLimitOlder - ChronControl->AgeValue;

   if (ChronControl->AgeLimitYounger.IsEmpty() || ChronControl->AgeLimitYounger.IsNull())
	 return false;
   else
	 error_younger = ChronControl->AgeValue - ChronControl->AgeLimitYounger;

   error = Max(error_older, error_younger);
   return true;
}
//---------------------------------------------------------------------------

UnicodeString TChronControlExportForm::GetName(CHRON* ChronControl)
{
   UnicodeString Name;

   if (GeochronControls.count(ChronControl->ControlType) > 0) {
	 for (unsigned int j=0; j<ChronControl->GeochronIDs.size(); j++) {
	   GEOCHRON* Date = GetDate(ChronControl->GeochronIDs[j]);
	   if (Date == NULL) {
		 UnicodeString msg = L"Date: " + VarToStr(ChronControl->AgeValue) +
		   L". Link to Geochronology form is is broken.";
		 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 }
	   else {
		 if (!Name.IsEmpty())
		   Name += L"/";
		 Name += Date->LabNumber;
		 }
	   }
	 }
   if (Name.IsEmpty())
	 Name = ChronControl->ControlType;
   int pos = Name.Pos(L",");
   while (pos>0) {
	 Name.Delete(pos,1);
     pos = Name.Pos(L",");
	 }
   return(Name);
}
//---------------------------------------------------------------------------

int TChronControlExportForm::GetReservoir(CHRON* ChronControl)
{
   int reservoir = -1;

   if (GeochronControls.count(ChronControl->ControlType) > 0) {
	 for (unsigned int j=0; j<ChronControl->GeochronIDs.size(); j++) {
	   GEOCHRON* Date = GetDate(ChronControl->GeochronIDs[j]);
	   if (Date != NULL) {
		 if (j == 0) {
		   if (Date->Parameters.size() > 0) {
			 map<UnicodeString,Variant>::iterator it = Date->Parameters.find(L"Reservoir (yrs)");
			 if (it != Date->Parameters.end())
			   reservoir = (int)VariantToDouble(it->second, -1.0);
			 }
		   }
		 else
		   reservoir = -1;
		 }
	   }
	 }
   return reservoir;
}
//---------------------------------------------------------------------------

void __fastcall TChronControlExportForm::cxRadioGroup3Click(TObject *Sender)
{
   cxLabel1->Caption = (cxRadioGroup3->ItemIndex == 1) ? L"m" : L"cm";
   SetOxCalInterval();
}
//---------------------------------------------------------------------------

void __fastcall TChronControlExportForm::cxRadioButton1Click(TObject *Sender)
{
   SetOxCalInterval();
   AdvEdit1->Enabled = true;
   cxLabel1->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TChronControlExportForm::cxRadioButton2Click(TObject *Sender)
{
   AdvEdit1->Text = 0;
   AdvEdit1->Enabled = false;
   cxLabel1->Enabled = false;
}
//---------------------------------------------------------------------------

