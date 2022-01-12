//---------------------------------------------------------------------------

#include <vcl.h>
#include "pch.h"
#pragma hdrstop

//#include <System.hpp>
#include "TICalib.h"
#ifndef TIGlobalsH
#include "TIGlobals.h"
#endif
#ifndef TIChronH
#include "TIChron.h"
#endif
#ifndef TIMemoH
#include "TIMemo.h"
#endif
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxLabel"
#pragma link "cxTextEdit"
#pragma link "ipwhttp"
#pragma link "ipwjson"
#pragma link "AdvCGrid"
#pragma link "AdvGrid"
#pragma link "AdvObj"
#pragma link "BaseGrid"
#pragma link "cxDropDownEdit"
#pragma link "cxMaskEdit"
//#pragma link "AdvSprd"
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
#pragma link "UWebGMaps"
#pragma link "UWebGMapsCommon"
#pragma resource "*.dfm"
TCalibForm *CalibForm;
//---------------------------------------------------------------------------

Variant CALIBRANGE::DecodeInt(UnicodeString XText)
{
   Variant rv = Variant::Empty();
   if (!SameText(XText, L"null")) {
	 int iVal;
	 if (TryStrToInt(XText, iVal))
	   rv = iVal;
	 }
   return rv;
}
//---------------------------------------------------------------------------

Variant CALIBRANGE::DecodeFloat(UnicodeString XText)
{
   Variant rv = Variant::Empty();
   if (!SameText(XText, L"null")) {
	 double dVal;
	 if (TryStrToFloat(XText, dVal))
	   rv = dVal;
	 ShowMessage(XText  + L", " + FloatToStr(dVal));
	 }
   return rv;
}
//---------------------------------------------------------------------------

__fastcall TCalibForm::TCalibForm(TComponent* Owner)
	: TForm(Owner)
{
   for (int col=0; col<10; col++) {
	 AdvColumnGrid1->Cells[col][1] = AdvColumnGrid1->Cells[col][0];
	 AdvColumnGrid1->Cells[col][0] = L"";
	 }
   AdvColumnGrid1->MergeCells(1,0,3,1);
   AdvColumnGrid1->MergeCells(5,0,2,1);
   AdvColumnGrid1->MergeCells(7,0,3,1);
   AdvColumnGrid1->Cells[1][0] = L"Radiocarbon Age";
   AdvColumnGrid1->Cells[5][0] = L"95.4% Cal Range";
   AdvColumnGrid1->Cells[7][0] = L"Range 1";
   AdvColumnGrid1->FontColors[1][0] = clNavy;
   AdvColumnGrid1->FontColors[5][0] = clNavy;
   AdvColumnGrid1->FontColors[7][0] = clNavy;
   for (int row=2, n=1; row<AdvColumnGrid1->RowCount; row++, n++)
	 AdvColumnGrid1->Cells[0][row] = n;
}
//---------------------------------------------------------------------------

void __fastcall TCalibForm::cxButton1Click(TObject *Sender)
{
   UnicodeString msg;
   Dates.clear();

   cxButton2->Enabled = false;
   int LastDataRow = 0;
   for (int row = AdvColumnGrid1->RowCount - 1; row >= 2; row--) {
	 for (int col=1; col<=3; col++) {
	   if (!AdvColumnGrid1->Cells[col][row].IsEmpty()) {
		 LastDataRow = row;
		 break;
		 }
	   }
	 if (LastDataRow > 0) break;
	 }
   if (LastDataRow == 0) {
	 MessageDlg(L"No dates to calibrate!", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 return;
	 }
   int iVal;
   for (int row=2; row<=LastDataRow; row++) {
	 CALIBDATE Date;
	 if (!AdvColumnGrid1->Cells[1][row].IsEmpty())
	   Date.LabNumber = AdvColumnGrid1->Cells[1][row];
	 else
	   {
	   msg = L"Lab Number cannot be blank!";
	   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return;
	   }
	 if (AdvColumnGrid1->Cells[2][row].IsEmpty()) {
	   msg = L"yr BP age cannot be empty!";
	   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return;
	   }
	 if (TryStrToInt(AdvColumnGrid1->Cells[2][row], iVal))
	   Date.Age = iVal;
	 else {
	   msg = L"yr BP in row " + IntToStr(row-1) + L" is not valid!";
	   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return;
	   }

	 if (AdvColumnGrid1->Cells[3][row].IsEmpty()) {
	   msg = L"SD cannot be empty!";
	   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return;
	   }
	 if (TryStrToInt(AdvColumnGrid1->Cells[3][row], iVal))
	   Date.SD = iVal;
	 else {
	   msg = L"SD in row " + IntToStr(row-1) + L" is not valid!";
	   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return;
	   }
	 Dates.push_back(Date);
	 }

   OXCAL OxCal(ipsJSONS1, TcpClient1);
   UnicodeString curve = cxComboBox1->Properties->Items->Strings[cxComboBox1->ItemIndex];
   if (!OxCal.Calibrate(curve, Dates))
	 return;

   AdvColumnGrid1->BeginUpdate();

   // format worksheet
   unsigned int nranges = 1;
   for (unsigned int i=0; i<Dates.size(); i++) {
	 if (Dates[i].Ranges.size() > nranges)
	  nranges = Dates[i].Ranges.size();
	 }

   AdvColumnGrid1->SplitAllCells();

   for (int col=4; col <= 9; col++) {
	 TGridColumnItem* Column = (TGridColumnItem*)AdvColumnGrid1->Columns->Items[col];
	 Column->Color = clWindow;
	 Column->ReadOnly = false;
	 }

   for (int col=1; col <= 9; col++)
     AdvColumnGrid1->Cells[col][0] = L"";
   AdvColumnGrid1->MergeCells(1,0,3,1);
   AdvColumnGrid1->MergeCells(5,0,2,1);
   AdvColumnGrid1->MergeCells(7,0,3,1);
   AdvColumnGrid1->Cells[1][0] = L"Radiocarbon Age";
   AdvColumnGrid1->Cells[5][0] = L"95.4% Cal Range";
   AdvColumnGrid1->Cells[7][0] = L"Range 1";

   if (nranges > 1) {
	 AdvColumnGrid1->ColCount += (3*(nranges-1));
	 int col = 10;
	 for (unsigned int range=2; range<=nranges; range++) {
	   AdvColumnGrid1->MergeCells(col,0,3,1);
	   AdvColumnGrid1->FontColors[col][0] = clNavy;
	   AdvColumnGrid1->FontStyles[col][0] = AdvColumnGrid1->FontStyles[col][1] << fsBold;
	   AdvColumnGrid1->Cells[col][0] = L"Range " + IntToStr((int)range);
	   AdvColumnGrid1->FontColors[col][1] = clNavy;
	   AdvColumnGrid1->FontStyles[col][1] = AdvColumnGrid1->FontStyles[col][1] << fsBold;
	   AdvColumnGrid1->Cells[col++][1] = L"Older";
	   AdvColumnGrid1->FontColors[col][1] = clNavy;
	   AdvColumnGrid1->FontStyles[col][1] = AdvColumnGrid1->FontStyles[col][1] << fsBold;
	   AdvColumnGrid1->Cells[col++][1] = L"Younger";
	   AdvColumnGrid1->FontColors[col][1] = clNavy;
	   AdvColumnGrid1->FontStyles[col][1] = AdvColumnGrid1->FontStyles[col][1] << fsBold;
	   AdvColumnGrid1->Cells[col++][1] = L"% Prob";
	   }
	 }

   for (unsigned int i=0, row=2; i<Dates.size(); i++, row++) {
	 AdvColumnGrid1->Cells[4][row] = OxCal.ConvertAge(Dates[i].Median,1);
	 AdvColumnGrid1->Cells[5][row] = OxCal.ConvertAge(Dates[i].Ranges[0].Older,1);
	 AdvColumnGrid1->Cells[6][row] = OxCal.ConvertAge(Dates[i].Ranges.back().Younger,1);
	 unsigned int nranges = Dates[i].Ranges.size();
	 int col = 7;
	 for (unsigned int j=0; j<nranges; j++) {
	   AdvColumnGrid1->Cells[col++][row] = OxCal.ConvertAge(Dates[i].Ranges[j].Older,1);
	   AdvColumnGrid1->Cells[col++][row] = OxCal.ConvertAge(Dates[i].Ranges[j].Younger,1);
	   AdvColumnGrid1->Cells[col++][row] = Dates[i].Ranges[j].Prob;
	   }
	 }

   AdvColumnGrid1->EndUpdate();

   cxLabel1->Visible = true;
   cxTextEdit1->Text = Dates[0].ProgramVersion;
   cxTextEdit1->Visible = true;
   cxButton2->Enabled = true;
}
//---------------------------------------------------------------------------

OXCAL::OXCAL(TipsJSONS *ipsjsons, TTcpClient *tcpclient)
{
   ipsJSONS1 = ipsjsons;
   TcpClient1 = tcpclient;
   if (tiGlobals->InternetTimeout > 60)
	 ipsJSONS1->Timeout = tiGlobals->InternetTimeout;
   ipsJSONS1->Config("KeepAlive=true");
   ipsJSONS1->Config("CodePage=65001");   // UTF-8 CodePage
   ipsJSONS1->BuildDOM = true;
   ipsJSONS1->LocalHost = TcpClient1->LocalHostAddr();
   ipsJSONS1->TransferredDataLimit = 0;
}
//---------------------------------------------------------------------------

bool OXCAL::Calibrate(UnicodeString Curve, vector<CALIBDATE>& Dates)
{
   Screen->Cursor = crHourGlass;
   // UnicodeString url = L"http://ceiwin10.cei.psu.edu:4090/Calibrate";

   //UnicodeString url = L"https://api.neotomadb.org/oxcal/Calibrate";
   UnicodeString url = tiGlobals->OxCalEndpoint + L"Calibrate";
   // UnicodeString url = L"https://neotomadb.org/api/oxcal/Calibrate";


   UnicodeString postdata = L"{\"curve\":\"";
   postdata += (Curve + L"\",\"bcad\":true,\"dates\":[");
   for (unsigned int i=0; i<Dates.size(); i++) {
	 if (i > 0) postdata += L",";
	 postdata += L"{\"name\":\"";
	 postdata += Dates[i].LabNumber;
	 postdata += L"\",\"date\":";
	 postdata += IntToStr(Dates[i].Age);
	 postdata += L",\"sd\":";
	 postdata += IntToStr(Dates[i].SD);
	 postdata += L"}";
	 }
   postdata += L"],\"round\":false}";

   //TMemoForm* MemoForm = new TMemoForm(L"OxCal URL", url, MemoFormOptions() << mfoReadOnly, NULL);
   //MemoForm->ShowModal();
   //delete MemoForm;

   //MemoForm = new TMemoForm(L"OxCal postdata", postdata, MemoFormOptions() << mfoReadOnly, NULL);
   //MemoForm->ShowModal();
   //delete MemoForm;

   //postdata += L"],\"round\":true}";

   // UnicodeString postdata = L"{\"curve\":\"IntCal13.14c\",\"bcad\":false,\"dates\":[{\"name\":\"TST1\",\"date\":1000,\"sd\":45}]}";
   // {"curve":"IntCal13.14c","bcad":false,"dates":[{"name":"CAMS-007","date":"1950","sd":"45"}],"round":true}



   ipsJSONS1->ContentType = L"application/json";
   ipsJSONS1->PostData = postdata;
   // ipsJSONS1->Post(url);  // temporarily commented out

   // for testing
   UnicodeString json = L"{\"success\":1,\"data\":[{\"median\":-773,\"oxcalVersion\":\"OxCal v4.4.2\",\"range\":[\"CAMS-007\",[[-803,-748,70.7],[-685,-666,8.2],[-636,-586,14.8],[-581,-569,1.8]]]},";
   json += L"{\"median\":-2098,\"oxcalVersion\":\"OxCal v4.4.2\",\"range\":[\"CAMS-008\",[[-2276,-2255,2.4],[-2207,-1960,93.0]]]}],\"message\":\"success message\"}";
   ipsJSONS1->TransferredData = json;
   MemoForm = new TMemoForm(L"Transferred Data", ipsJSONS1->TransferredData, MemoFormOptions() << mfoReadOnly, NULL);
   MemoForm->ShowModal();
   delete MemoForm;

   ipsJSONS1->BuildDOM = true;
   ipsJSONS1->Input(ipsJSONS1->TransferredData);

   ShowMessage(L"Breakpoint 1");

   ipsJSONS1->XPath = L"/json/success/";
   int success;
   if (!TryStrToInt(ipsJSONS1->XText, success))
	 return false;
   if (!success) {
	 ipsJSONS1->XPath = L"/json/message/";
	 //ErrorMsg = ipwJSON1->XText;
	 return false;
	 }

   ipsJSONS1->XPath = L"/json/data/";
   int ndates = ipsJSONS1->XChildrenCount;

   int iVal;
   double dVal;
   for (int i=1; i<=ndates; i++) {
	 UnicodeString XPath1 = L"/json/data/[" + IntToStr(i) + L"]/";
	 // parse median
	 UnicodeString XPath2 = XPath1 + L"median";
	 ipsJSONS1->XPath = XPath2;
	 if (TryStrToFloat(ipsJSONS1->XText, dVal))
	   Dates[i-1].Median = dVal;
	 ShowMessage(L"median = " + FloatToStr(dVal));
	 // parse program version
	 XPath2 = XPath1 + L"oxcalVersion";
	 ipsJSONS1->XPath = XPath2;
	 UnicodeString ProgVer = ipsJSONS1->XText;
	 ShowMessage(L"version = " + ProgVer);
	 if (ProgVer.SubString(1,1) == L"\"")
	   ProgVer.Delete(1,1);
	 if (*ProgVer.LastChar() == L'\"')
	   ProgVer.Delete(ProgVer.Length(),1);
	 Dates[i-1].ProgramVersion = ProgVer;
	 // get number of ranges
	 XPath2 = XPath1 + L"range/[2]/";
	 ipsJSONS1->XPath = XPath2;
	 int nranges = ipsJSONS1->XChildrenCount;
	 ShowMessage(L"nranges = " + IntToStr(nranges));

	 // iterate through ranges
	 for (int j=1; j<=nranges; j++) {
	   CALIBRANGE Range;
	   UnicodeString XPath3 = XPath2 + L"[" + IntToStr(j) + L"]/[";
	   UnicodeString XPath4 = XPath3 + L"1]";
	   ShowMessage(XPath3);
	   ShowMessage(XPath4);
	   ipsJSONS1->XPath = XPath4;
	   //ShowMessage(ipsJSONS1->XText);
	   Range.Older = Range.DecodeFloat(ipsJSONS1->XText);
	   XPath4 = XPath3 + L"2]";
	   ipsJSONS1->XPath = XPath4;
	   Range.Younger = Range.DecodeFloat(ipsJSONS1->XText);
	   XPath4 = XPath3 + L"3]";
	   ipsJSONS1->XPath = XPath4;
	   Range.Prob = Range.DecodeFloat(ipsJSONS1->XText);
	   Dates[i-1].Ranges.push_back(Range);
	   }
	 }
   Screen->Cursor = crDefault;
   return true;
}
//---------------------------------------------------------------------------

Variant OXCAL::ConvertAge(Variant Gage, short AgeType)
{
   // Gage is Gregorian fractional age
   // AgeTypes:
   // 1: cal BP
   // 2: BC/AD
   // 3: ±CE (ISO-8601)
   // 4: G (Gregorian fractional)

   if (Gage.IsEmpty())
	 return Gage;

   Variant Age;
   double age = Gage;
   switch (AgeType) {
	 case 1:
	   Age = 1951-Ceil(age);
	   break;
	 case 2:
	   Age = (age < 0) ? Ceil(age)-2 : Floor(age);
	   break;
	 case 3:
	   Age = Floor(age);
	   break;
	 case 4:
	   Age = age;
	   break;
	 }
   return Age;
}
//---------------------------------------------------------------------------

/*
CALIB::CALIB(TipwHTTP *ipwhttp, TTcpClient *tcpclient)
{
   ipwHTTP1 = ipwhttp;
   TcpClient1 = tcpclient;
   ipwHTTP1->ResetHeaders();
   if (tiGlobals->InternetTimeout > 60)
	 ipwHTTP1->Timeout = tiGlobals->InternetTimeout;
   ipwHTTP1->Config("KeepAlive=true");
   ipwHTTP1->LocalHost = TcpClient1->LocalHostAddr();
   ipwHTTP1->TransferredDataLimit = 0;
};
//---------------------------------------------------------------------------

bool CALIB::Calibrate(int Age, int Sigma, short calcurve)
{
   // UnicodeString url = L"http://depts.washington.edu/qil/tinycalib/tinycalib.cgi?Dataset=intcal13&Rage=1950&Sigma=55";
   UnicodeString url = L"http://depts.washington.edu/qil/tinycalib/tinycalib.cgi?Dataset=";
   switch (calcurve) {
	 case INTCAL13:
	   url += L"intcal13";
	   break;
	 case SHCAL13:
	   url += L"shcal13";
	   break;
	 }
   url += (L"&Rage=" + IntToStr(Age) + L"&Sigma=" + IntToStr(Sigma));

   try {
	   ipwHTTP1->Get(url);
	   }
   catch (const Exception &e) {
	   MessageDlg(e.Message, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return false;
	   }

   UnicodeString input = ipwHTTP1->TransferredData;

   int idx;
   while ((idx = input.Pos(L"&#")) > 0) {
	 int idx2 = 0;
	 for (int i=idx; i<=input.Length(); i++) {
	   if (input[i] == L';') {
		 idx2 = i;
		 break;
		 }
	   }
	 if (idx2 > 0) {
	   int nchar = idx2-idx+1;
	   int ndigits = nchar-3;
	   WideChar wch = input.SubString(idx+2,ndigits).ToInt();
	   UnicodeString uch(wch);
	   input.Delete(idx,nchar);
	   input.Insert(uch,idx);
	   }
	 }

   while ((idx = input.Pos(L"<br>")) > 0)
	 input.Delete(idx,4);

   vector<UnicodeString> lines;
   while ((idx = input.Pos(L"\n")) > 0) {
	 lines.push_back(input.SubString(1,idx-1));
	 input.Delete(1,idx);
	 }

   // CALIB7.0: calibration of 1950± 55 with intcal13.f14c,{cal BP 1902}
   bool error = false;
   program = lines[0].SubString(1,5);
   if (SameText(Program, L"CALIB")) {
	 idx = lines[0].Pos(L":");
	 version = lines[0].SubString(6,idx-6);
	 }
   else
	 error = true;

   // {cal BP 1902}
   if (!error) {
	 error = true;
	 UnicodeString line = lines[0];
	 idx = line.Pos(L"{cal BP");
	 if (idx > 0) {
	   line.Delete(1,idx+6);
	   idx = line.Pos(L"}");
	   if (idx > 0) {
		 line = line.SubString(1,idx-1);
		 median = line.ToDouble();
		 error = false;
		 }
	   }
	 }

   if (error) {
	 error_msg = L"Calibration error: " + lines[0];
	 MessageDlg(error_msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 return false;
	 }

   // TwoSigma
   // 0.991[cal BP 1736 :cal BP 2004]
   // 0.009[cal BP 2025 :cal BP 2036]

   unsigned int start = 0;
   for (unsigned int i=0; i<lines.size(); i++) {
	 if (ContainsText(lines[i], L"TwoSigma")) {
	   start = i+1;
	   break;
	   }
	 }

   //vector<CALIBRANGE> CalibRanges;

   for (unsigned int i=start; i<lines.size(); i++) {
	 error = true;
	 CALIBRANGE cr;
	 UnicodeString line = lines[i];
	 idx = line.Pos(L"[");
	 if (idx > 0) {
	   cr.Prob = line.SubString(1,idx-1).ToDouble();
	   line.Delete(1,idx+6);
	   idx = line.Pos(L":");
	   if (idx > 0) {
		 cr.Younger = line.SubString(1,idx-1).Trim().ToDouble();
		 line.Delete(1,idx+6);
		 idx = line.Pos(L"]");
		 if (idx > 0) {
		   cr.Older = line.SubString(1,idx-1).Trim().ToDouble();
		   CalibRanges.push_back(cr);
		   error = false;
		   }
		 }
	   }
	 if (error) {
	   error_msg = L"Calibration error: " + lines[i];
	   MessageDlg(error_msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return false;
	   }
	 }
   return true;
}
//---------------------------------------------------------------------------

void CALIB::GetConfLimits(pair<double,double>& ConfLimits)
{
   ConfLimits.first = CalibRanges[0].Younger;
   ConfLimits.second = CalibRanges[0].Older;
   if (CalibRanges.size() > 1) {
	 for (unsigned int i=1; i<CalibRanges.size(); i++) {
	   if (CalibRanges[i].Younger < ConfLimits.first)
		 ConfLimits.first = CalibRanges[i].Younger;
	   if (CalibRanges[i].Older > ConfLimits.second)
		 ConfLimits.second = CalibRanges[i].Older;
	   }
     }
}
//---------------------------------------------------------------------------
*/

void __fastcall TCalibForm::cxButton2Click(TObject *Sender)
{
   /*
   OxCal.html?Command= R_Date("OxA-3000",3000,30);R_Date("OxA-3001",3060,30);R_Date("OxA-3002",3100,30);
   OxCal.html?Command=Curve(" Marine04");Delta_R(100,20);R_Date("OxA-3000",3000,30);
   */

   //WideString url = L"https://c14.arch.ox.ac.uk/oxcal/OxCal.html?Command=R_Date(%22OxA-3000%22,3000,30);";

   WideString url = L"https://c14.arch.ox.ac.uk/oxcal/OxCal.html?Command=Curve(%22";
   WideString curve = cxComboBox1->Properties->Items->Strings[cxComboBox1->ItemIndex];
   url += curve;
   url += WideString(L"%22);");
   for (unsigned int i=0; i<Dates.size(); i++) {
	 WideString R_Date = L"R_Date(%22" + Dates[i].LabNumber + L"%22," + IntToStr(Dates[i].Age) +
						 L"," + IntToStr(Dates[i].SD) + L");";
	 url += R_Date;
	 }
   WideString Open = L"open";

   ShellExecute(NULL, Open.c_bstr(), url.c_bstr(), NULL, NULL, SW_SHOWNORMAL);
}
//---------------------------------------------------------------------------

// copy
void __fastcall TCalibForm::cxButton3Click(TObject *Sender)
{
   int rcount = 2 + Dates.size();
   AdvColumnGrid1->SelectRows(0,rcount);
   AdvColumnGrid1->CopySelectionToClipboard();
   MessageDlg(L"Worksheet copied to clipboard", mtInformation, TMsgDlgButtons() << mbOK, 0);
}
//---------------------------------------------------------------------------

void __fastcall TCalibForm::AdvColumnGrid1KeyUp(TObject *Sender, WORD &Key, TShiftState Shift)

{
   cxButton1->Enabled = (!AdvColumnGrid1->Cells[1][2].IsEmpty() &&
						 !AdvColumnGrid1->Cells[2][2].IsEmpty() &&
						 !AdvColumnGrid1->Cells[3][2].IsEmpty());
}
//---------------------------------------------------------------------------

void __fastcall TCalibForm::ipsJSONS1SSLServerAuthentication(TObject *Sender,
	TipsJSONSSSLServerAuthenticationEventParams *e)

{
   e->Accept = true;
}
//---------------------------------------------------------------------------

