//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TICounter.h"
#ifndef TIGlobalsH
#include "TIGlobals.h"
#endif
#ifndef TICommonH
#include "TICommon.h"
#endif
#ifndef TIMemoH
#include "TIMemo.h"
#endif

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvCGrid"
#pragma link "AdvGrid"
#pragma link "AdvObj"
#pragma link "AdvUtil"
#pragma link "BaseGrid"
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
#pragma link "AdvToolBar"
#pragma link "AdvToolBarStylers"
#pragma link "AdvToolBtn"
#pragma link "ipwxmlp"
#pragma link "AdvMemo"
#pragma link "AdvMemoStylerManager"
#pragma link "Advmxml"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxLabel"
#pragma link "cxTextEdit"
#pragma link "AdvEdit"
#pragma link "AdvCombo"
#pragma link "AdvDateTimePicker"
#pragma link "AdvSplitter"
#pragma link "cxCalendar"
#pragma link "cxDateUtils"
#pragma link "cxDropDownEdit"
#pragma link "cxMaskEdit"
#pragma link "dxCore"
#pragma link "AdvPanel"
#pragma link "AdvMenus"
#pragma link "AdvPicture"
#pragma resource "*.dfm"
TCounterForm *CounterForm;

bool TAXACOUNT::operator == (const TAXACOUNT& comp)
{
   if (this == &comp) return true;
   return (FCode == comp.Code);
}
//---------------------------------------------------------------------------

bool TAXACOUNT::operator < (const TAXACOUNT& comp)
{
   if (this == &comp) return false;
   return (FCount > comp.Count);
}
//---------------------------------------------------------------------------

__fastcall TCounterForm::TCounterForm(TComponent* Owner)
	: TForm(Owner)
{
   UnicodeString Code, Taxon, Elem;
   TSSForm = (TTilSpreadSheetForm*)Owner;
   int row_beg = TSSForm->ProfGrid1->FixedRows;
   ssrow_end = TSSForm->AbsContentRowCount(TSSForm->ProfGrid1);
   for (int row = row_beg; row <= ssrow_end; row++) {
	 Code = TSSForm->ProfGrid1->AbsoluteCells[1][row]->Text;
	 if (Code.IsEmpty() || Code[1] != L'#') {
	   Taxon = TSSForm->ProfGrid1->AbsoluteCells[2][row]->Text;
	   if (!Taxon.IsEmpty()) {
		 Elem = TSSForm->ProfGrid1->AbsoluteCells[3][row]->Text;
		 //SSTaxa[te] = row;
		 SSTaxa.insert(pair<UnicodeString,int>(Taxon,row));
		 }
	   // ShowMessage(Taxon);
	   }
	 }

   PSUM = 0.0;
   TSUM = 0.0;
   nspike = 0;
   nslide = 0;
   ntrans = 0;
   Seconds = 0;
   editrow = -1;
   slide_query = false;
   conc_data = false;
   enter_spike = true;
   SpikeChar = L'.';  // get from globals
   ElemChar = L'/';
   ElemStr = L"/";

   ArrowBmp = new Graphics::TBitmap;
   cxImageList2->GetBitmap(0,ArrowBmp);
   Metadata.push_back(L"<Dictionary>");
   Metadata.push_back(L"<Site>");
   Metadata.push_back(L"<CollUnit>");
   Metadata.push_back(L"<Depth>");
   Metadata.push_back(L"<Thickness>");
   Metadata.push_back(L"<AnalUnitName>");
   Metadata.push_back(L"<SampName>");
   Metadata.push_back(L"<SampNotes>");
   Metadata.push_back(L"<SampAnalyst>");
   Metadata.push_back(L"<SampPrepDate>");
   Metadata.push_back(L"<SampQuant>");
   Metadata.push_back(L"<Spike>");

   if (TSSForm->ContactList->Count > 0) {
	 AdvComboBox4->Enabled = true;
	 for (int i=0; i<TSSForm->ContactList->Count; i++) {
	   CONTACT* Contact = TSSForm->ContactList->Contacts[i];
	   AdvComboBox4->Items->AddObject(Contact->ShortContactName, (TObject*)Contact);
	   }
	 }

   for (int i=0; i<Panel3->ControlCount; i++) {
	 TControl* Control = Panel3->Controls[i];
	 if (Control->Top < Bevel1->Top) {
	   MetadataControls.insert(pair<int,TControl*>(Control->Top+Control->Height,Control));
	   }
	 }

   for (int i=0; i<AdvStringGrid1->ColCount; i++) {
	 AdvStringGrid1->Alignments[i][0] = taCenter;
	 AdvStringGrid1->ReadOnly[i][0] = true;
	 AdvStringGrid1->ReadOnly[i][1] = true;
	 AdvStringGrid1->ReadOnly[i][2] = true;
	 AdvStringGrid1->ReadOnly[i][3] = true;

	 }
   for (int i=0; i<AdvColumnGrid3->ColCount; i++) {
	 AdvColumnGrid3->ReadOnly[i][1] = true;
	 }

   AdvColumnGrid3->AddImageIdx(2,0,3,TCellHAlign::haCenter,TCellVAlign::vaCenter);
   AdvColumnGrid3->AddImageIdx(3,0,3,TCellHAlign::haBeforeText,TCellVAlign::vaCenter);
   AdvColumnGrid3->AddImageIdx(4,0,4,TCellHAlign::haCenter,TCellVAlign::vaCenter);
   AdvColumnGrid3->AddImageIdx(6,0,5,TCellHAlign::haCenter,TCellVAlign::vaCenter);
}
//---------------------------------------------------------------------------

void __fastcall TCounterForm::FormClose(TObject *Sender, TCloseAction &Action)
{
   delete ArrowBmp;
}
//---------------------------------------------------------------------------

// open dictionary file
void __fastcall TCounterForm::AdvToolBarButton3Click(TObject *Sender)
{
   UnicodeString PathName;
   UnicodeString FileName;
   ParseXMLUnicode* xmlin;
   int count;
   UTF8String XPath, XPath1;
   UnicodeString Sum, Code, Name, Element, Group;

   if (!tiGlobals->DictionaryPath.IsEmpty()) {
	 OpenDialog1->InitialDir = ExtractFileDir(tiGlobals->DictionaryPath);
	 OpenDialog1->FileName = tiGlobals->DictionaryPath;
	 }
   else if (!tiGlobals->InitialDirectory.IsEmpty()) {
	 OpenDialog1->InitialDir = tiGlobals->InitialDirectory;
	 }

   if (OpenDialog1->Execute()) {
	 try {
	   ipwXMLp1->Config(L"CodePage=65001");
	   ipwXMLp1->ParseFile(OpenDialog1->FileName);
	   xmlin = new ParseXMLUnicode(ipwXMLp1);

	   if (!SameText(xmlin->RootElement(), "TiliaCounterDictionary"))
		 throw(Exception(OpenDialog1->FileName + L" is not a valid Tilia Counter Dictionary file."));
	   }
	 catch(...) {
	   MessageDlg("Cannot parse " + FileName, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return;
	   }

     XPath = L"/TiliaCounterDictionary/";
	 if (xmlin->ValidChild(XPath, L"Sum", count)) {
	   for (int i=0; i<count; i++) {
		 if (xmlin->GetChildText(i, Sum))
		   Sums.push_back(Sum);
		 }
	   }

	 if (xmlin->ValidChild(XPath, L"Elements", count)) {
	   AdvColumnGrid4->RowCount = count + 1;
	   XMLSubElement Taxa(L"/TiliaCounterDictionary/Elements/Element");
	   for (int i=1; i<=count; i++) {
		 XPath1 = Taxa.XPath(i);
		 xmlin->GetTextValue(XPath1, L"Code", Code);
		 xmlin->GetTextValue(XPath1, L"Name", Name);
		 AdvColumnGrid4->Cells[0][i] = Code;
		 AdvColumnGrid4->Cells[1][i] = Name;
		 AdvColumnGrid4->AddBitButton(2,i,14,14,L"",ArrowBmp,haFull,vaFull);
		 }
	   }

	 Panel4->Visible = true;
     AdvColumnGrid1->HideColumns(2,3);
	 AdvColumnGrid1->Visible = true;
	 if (xmlin->ValidChild(XPath, L"Taxa", count)) {
	   AdvColumnGrid1->RowCount = count + 1;
	   XMLSubElement Taxa(L"/TiliaCounterDictionary/Taxa/Taxon");
	   for (int i=1; i<=count; i++) {
		 XPath1 = Taxa.XPath(i);
		 xmlin->GetTextValue(XPath1, L"Code", Code);
		 xmlin->GetTextValue(XPath1, L"Name", Name);
		 xmlin->GetTextValue(XPath1, L"Element", Element);
		 xmlin->GetTextValue(XPath1, L"Group", Group);
		 AdvColumnGrid1->Cells[0][i] = Code;
		 AdvColumnGrid1->Cells[1][i] = Name;
		 AdvColumnGrid1->Cells[2][i] = Element;
		 AdvColumnGrid1->Cells[3][i] = Group;
		 for (int col=0; col<=3; col++)
           AdvColumnGrid1->ReadOnly[col][i] = true;
		 AdvColumnGrid1->AddBitButton(4,i,14,14,L"",ArrowBmp,haFull,vaFull);
		 InSum[Code] = (find(Sums.begin(),Sums.end(),Group) != Sums.end());
		 }
	   }
	 Dictionary = OpenDialog1->FileName;
	 tiGlobals->DictionaryPath = OpenDialog1->FileName;
	 AdvToolBarButton4->Enabled = true;
	 AdvToolBarButton3->Visible = false;
	 AdvToolBarButton9->Visible = true;
	 AdvToolBarButton11->Visible = true;
	 }
}
//---------------------------------------------------------------------------

// open count file
void __fastcall TCounterForm::AdvToolBarButton5Click(TObject *Sender)
{
   UnicodeString PathName;
   UnicodeString FileName;
   UnicodeString utext;
   UnicodeString AttrValue;
   ParseXMLUnicode* xmlin;
   int count;
   UTF8String XPath, XPath1, XPath2;
   UnicodeString ChildName;
   // UnicodeString Sum, Code, Name, Group;

   if (!tiGlobals->DictionaryPath.IsEmpty()) {
	 OpenDialog1->InitialDir = ExtractFileDir(tiGlobals->DictionaryPath);
	 //OpenDialog1->FileName = tiGlobals->DictionaryPath;
	 }

   if (OpenDialog1->Execute()) {
	 try {
	   ipwXMLp1->Config(L"CodePage=65001");
	   ipwXMLp1->ParseFile(OpenDialog1->FileName);
	   xmlin = new ParseXMLUnicode(ipwXMLp1);

	   if (!SameText(xmlin->RootElement(), "TiliaCount"))
		 throw(Exception(OpenDialog1->FileName + L" is not a valid Tilia Count file."));
	   XPath = L"/TiliaCount/";

	   /* if (xmlin->ValidChild(XPath, L"Sum", count)) {
		 for (int i=0; i<count; i++) {
		   if (xmlin->GetChildText(i, Sum))
			 Sums.push_back(Sum);
		   }
		 } */
	   }
	 catch(...) {
	   MessageDlg("Cannot parse " + FileName, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return;
	   }

	 Panel3->Visible = true;
     AdvMemo1->Visible = true;

	 // Panel4->Visible = true;   // save dictionary panel
	 // AdvColumnGrid1->Visible = true;  // dictionary grid
	 // AdvToolBarButton4->Enabled = true;  // new count
	 /* if (xmlin->ValidChild(XPath, L"Taxa", count)) {
	   AdvColumnGrid1->RowCount = count + 1;
	   XMLSubElement Taxa(L"/TiliaCounterDictionary/Taxa/Taxon");
	   for (int i=1; i<=count; i++) {
		 XPath = Taxa.XPath(i);
		 xmlin->GetTextValue(XPath, L"Code", Code);
		 xmlin->GetTextValue(XPath, L"Name", Name);
		 xmlin->GetTextValue(XPath, L"Group", Group);
		 AdvColumnGrid1->Cells[0][i] = Code;
		 AdvColumnGrid1->Cells[1][i] = Name;
		 AdvColumnGrid1->Cells[2][i] = Group;
		 AdvColumnGrid1->AddBitButton(3,i,14,14,L"",ArrowBmp,haFull,vaFull);
		 }
	   }  */



	 if (xmlin->GetTextValue(XPath, L"Site", utext))
	   AdvEdit1->Text = utext;

	 if (xmlin->ValidChild(XPath, L"Counts", count)) {
	   XMLSubElement Count(L"/TiliaCount/Counts/");
	   for (int i=0; i<count; i++) {
		 ChildName = xmlin->GetChildName(i);
		 ShowMessage(ChildName);
		 if (ChildName == L"Slide") {
		   xmlin->GetChildText(i, utext);
		   ShowMessage(utext);
		   }
		 else if (ChildName == L"Count") {
		   XPath2 = ipwXMLp1->XPath;
		   XPath1 = Count.XPath(i+1);
		   ShowMessage(XPath1);
		   if (xmlin->GetAttrStr(XPath1, L"code", AttrValue))
			 ShowMessage(AttrValue);
		   ipwXMLp1->XPath = XPath2;
		   }
		 }
	   }

	 // Dictionary = OpenDialog1->FileName;
	 // tiGlobals->DictionaryPath = OpenDialog1->FileName;
	 AdvToolBarButton3->Visible = false;
	 AdvToolBarButton9->Visible = true;  // Sum button
	 AdvToolBarButton11->Visible = true;
	 }
}
//---------------------------------------------------------------------------

// new file
void __fastcall TCounterForm::AdvToolBarButton4Click(TObject *Sender)
{
   unsigned short year, month, day, hour, min, sec, msec;
   UnicodeString line;

   Panel3->Visible = true;
   //AdvStringGrid1->Visible = true;
   AdvMemo1->Visible = true;
   //Panel5->Visible = true;
   AdvMemo1->Lines->Strings[0] = L"<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"yes\"?>";
   AdvMemo1->Lines->Add(L"<TiliaCount version=\"1.0\">");

   TDateTime Created = Now();
   Created.DecodeDate(&year, &month, &day);
   Created.DecodeTime(&hour, &min, &sec, &msec);
   AdvMemo1->Lines->Add(L"\t<DateCreated>" + EncodeXMLDateTime(year,month,day,hour,min,sec) +
	 L"</DateCreated>");
   AdvMemo1->Lines->Add(L"\t<Dictionary>" + Dictionary + L"</Dictionary>");
   AdvMemo1->Lines->Add(L"</TiliaCount>");

   SITE* Site = (SITE*)TSSForm->Sites->Items[0];
   if (!Site->SiteName.IsEmpty())
	 AdvEdit1->Text = Site->SiteName;
   if (!Site->CollUnits[0].CollectionName.IsEmpty())
	 AdvEdit2->Text = Site->CollUnits[0].CollectionName;
}
//---------------------------------------------------------------------------

// new slide
void __fastcall TCounterForm::AdvToolBarButton1Click(TObject *Sender)
{
   EnterSlide();
}
//---------------------------------------------------------------------------

void TCounterForm::EnterSlide(void)
{
   MemoForm = new TMemoForm(L"Slide", L"", MemoFormOptions() << mfoTextEdit << mfoCancelButton << mfoOkOnEnter, this);
   if (MemoForm->ShowModal() == mrOk) {
	 int row = FindXMLLine(L"</Counts>");
	 if (row != -1) {
	   UnicodeString Slide = L"\t\t<Slide>" + MemoForm->Text + L"</Slide>";
	   AdvMemo1->Lines->Insert(row,Slide);
	   }
	 SetActiveLine(row);
	 AdvColumnGrid3->Cells[0][1] = ++nslide;
	 AdvToolBarButton2->Enabled = true;
	 }
   delete MemoForm;
}
//---------------------------------------------------------------------------

void __fastcall TCounterForm::AdvToolBarButton2Click(TObject *Sender)
{
   EnterTransect();
}
//---------------------------------------------------------------------------

void TCounterForm::EnterTransect(void)
{
   MemoForm = new TMemoForm(L"Transect", L"", MemoFormOptions() << mfoTextEdit << mfoCancelButton << mfoOkOnEnter, this);
   if (MemoForm->ShowModal() == mrOk) {
	 int row = FindXMLLine(L"</Counts>");
	 if (row != -1) {
	   UnicodeString Transect = L"\t\t<Transect>" + MemoForm->Text + L"</Transect>";
	   AdvMemo1->Lines->Insert(row,Transect);
	   }
	 SetActiveLine(row);
	 AdvColumnGrid3->Cells[1][1] = ++ntrans;
	 }
   delete MemoForm;
}
//---------------------------------------------------------------------------

// enter comment
void __fastcall TCounterForm::AdvToolBarButton10Click(TObject *Sender)
{
   MemoForm = new TMemoForm(L"Comment", L"", MemoFormOptions() << mfoTextEdit << mfoCancelButton << mfoOkOnEnter, this);
   if (MemoForm->ShowModal() == mrOk) {
	 Comment = MemoForm->Text;
	 AdvToolBarButton10->ImageIndex = 6;
	 AdvPicture1->Visible = true;
	 }
   delete MemoForm;
   FocusControl(AdvEdit12);
}
//---------------------------------------------------------------------------

// Site
void __fastcall TCounterForm::AdvEdit1Exit(TObject *Sender)
{
   int row;
   
   InsertXMLLine(L"<Site>",AdvEdit1->Text);

   SITE* Site = (SITE*)TSSForm->Sites->Items[0];
   if (Site->SiteName != AdvEdit1->Text) {
	 if (!Site->SiteName.IsEmpty())
	   MessageDlg(L"Site name updated in Sites metadata tab.", mtInformation, TMsgDlgButtons() << mbOK, 0);
	 Site->SiteName = AdvEdit1->Text;
	 }
}
//---------------------------------------------------------------------------

// Collection unit
void __fastcall TCounterForm::AdvEdit2Exit(TObject *Sender)
{
   SITE* Site = (SITE*)TSSForm->Sites->Items[0];
   if (Site->CollUnits[0].CollectionName != AdvEdit2->Text) {
	 if (!Site->CollUnits[0].CollectionName.IsEmpty())
	   MessageDlg(L"Collection unit name updated in Collection Unit metadata tab.",
		 mtInformation, TMsgDlgButtons() << mbOK, 0);
	 Site->CollUnits[0].CollectionName = AdvEdit2->Text;
	 }
   InsertXMLLine(L"<CollUnit>",AdvEdit2->Text);
}
//---------------------------------------------------------------------------

// Depth
void __fastcall TCounterForm::AdvEdit3Exit(TObject *Sender)
{
   if (ValidAdvEditFloatValue(AdvEdit3))
	 InsertXMLLine(L"<Depth>",AdvEdit3->Text);
}
//---------------------------------------------------------------------------

// Thickness
void __fastcall TCounterForm::AdvEdit9Exit(TObject *Sender)
{
   if (ValidAdvEditFloatValue(AdvEdit9))
     InsertXMLLine(L"<Thickness>",AdvEdit9->Text);
}
//---------------------------------------------------------------------------

// Analysis unit name
void __fastcall TCounterForm::AdvEdit4Exit(TObject *Sender)
{
   InsertXMLLine(L"<AnalUnitName>",AdvEdit4->Text);
}
//---------------------------------------------------------------------------

// Sample name
void __fastcall TCounterForm::AdvEdit8Exit(TObject *Sender)
{
   InsertXMLLine(L"<SampName>",AdvEdit8->Text);
}
//---------------------------------------------------------------------------

// Sample notes
void __fastcall TCounterForm::AdvEdit10Exit(TObject *Sender)
{
   InsertXMLLine(L"<SampNotes>",AdvEdit10->Text);
}
//---------------------------------------------------------------------------

// Sample analyst
void __fastcall TCounterForm::AdvComboBox4Change(TObject *Sender)
{
   InsertXMLLine(L"<SampAnalyst>",AdvComboBox4->Text);
}
//---------------------------------------------------------------------------

// Prep date
void __fastcall TCounterForm::cxDateEdit1PropertiesChange(TObject *Sender)
{
   unsigned short year, month, day;
   if (!cxDateEdit1->Text.IsEmpty()) {
	 cxDateEdit1->Date.DecodeDate(&year, &month, &day);
	 InsertXMLLine(L"<SampPrepDate>", EncodeXMLDate(year, month, day));
	 }
}
//---------------------------------------------------------------------------

// sample quantity
void __fastcall TCounterForm::AdvEdit5Exit(TObject *Sender)
{
   if (ValidAdvEditFloatValue(AdvEdit5)) {
	 if (AdvComboBox2->ItemIndex != -1)
	   InsertXMLLine(L"<SampQuant>",AdvEdit5->Text,L"units",AdvComboBox2->Text);
	 }
}
//---------------------------------------------------------------------------

// sample quantity units
void __fastcall TCounterForm::AdvComboBox2Change(TObject *Sender)
{
   if (ValidAdvEditFloatValue(AdvEdit5)) {
	 if (AdvComboBox2->ItemIndex != -1)
	   InsertXMLLine(L"<SampQuant>",AdvEdit5->Text,L"units",AdvComboBox2->Text);
	 }
}
//---------------------------------------------------------------------------

// spike
void __fastcall TCounterForm::AdvComboBox1Change(TObject *Sender)
{
   InsertSpike();
}
//---------------------------------------------------------------------------

// spike tablets or suspension
void __fastcall TCounterForm::AdvComboBox3Change(TObject *Sender)
{
   InsertSpike();
}
//---------------------------------------------------------------------------

// spike quantity
void __fastcall TCounterForm::AdvEdit6Exit(TObject *Sender)
{
   if (ValidAdvEditFloatValue(AdvEdit6))
	 InsertSpike();
}
//---------------------------------------------------------------------------

// spike conc
void __fastcall TCounterForm::AdvEdit7Exit(TObject *Sender)
{
   if (ValidAdvEditFloatValue(AdvEdit7))
	 InsertSpike();
}
//---------------------------------------------------------------------------

void TCounterForm::InsertSpike(void)
{
   if (AdvComboBox1->ItemIndex != -1 && AdvComboBox3->ItemIndex != -1 &&
	   AdvComboBox5->ItemIndex != -1 &&	!AdvEdit6->Text.IsEmpty() && !AdvEdit7->Text.IsEmpty()) {
	 UnicodeString type = AdvComboBox1->Text + L" " + AdvComboBox3->Text;
	 UnicodeString tag = L"<Spike>";

	 int row = FindXMLLine(tag);
	 bool spike_exists = (row > -1);
	 InsertXMLLine(tag,type);
	 row = FindXMLLine(tag);

	 AdvMemo1->Lines->Strings[row++] = L"\t" + tag;
	 UnicodeString line = L"\t\t<Type>" + type + L"</Type>";
	 if (spike_exists)
	   AdvMemo1->Lines->Strings[row++] = line;
	 else
	   AdvMemo1->Lines->Insert(row++,line);
	 line = L"\t\t<Quantity units=\"" + AdvComboBox5->Text + L"\">" + AdvEdit6->Text + L"</Quantity>";
	 if (spike_exists)
	   AdvMemo1->Lines->Strings[row++] = line;
	 else
	   AdvMemo1->Lines->Insert(row++,line);
	 line = L"\t\t<Conc>" + AdvEdit7->Text + L"</Conc>";
	 if (spike_exists)
	   AdvMemo1->Lines->Strings[row++] = line;
	 else
	   AdvMemo1->Lines->Insert(row++,line);
	 line = L"\t" + tag.Insert(L"/",2);
	 if (spike_exists)
	   AdvMemo1->Lines->Strings[row++] = line;
	 else
	   AdvMemo1->Lines->Insert(row++,line);
	 // AdvMemo1->ActiveLine = row;
	 SetActiveLine(row);
	 }
}
//---------------------------------------------------------------------------

void TCounterForm::InsertXMLLine(UnicodeString tag, UnicodeString text,
	UnicodeString attrtag, UnicodeString attrval)
{
   UnicodeString endtag = tag;
   endtag.Insert(L"/",2);
   if (!attrtag.IsEmpty()) {
	 UnicodeString attr = L" " + attrtag + L"=\"" + attrval + L"\"";
	 tag.Insert(attr,tag.Length());
	 }
   UnicodeString line = L"\t" + tag + text + endtag;
   int row = FindXMLLine(tag);
   if (row != -1)
	 AdvMemo1->Lines->Strings[row] = line;
   else if (text.IsEmpty())
	 return;
   else {
	 vector<UnicodeString>::iterator itr = find(Metadata.begin(),Metadata.end(),tag);
	 do { itr--;
		  row = FindXMLLine(*itr);
		} while (row == -1 && itr != Metadata.begin());
	 if (row != -1)
	   AdvMemo1->Lines->Insert(row+1,line);
	 }
   //if (row != -1)
   //	 AdvMemo1->ActiveLine = row+1;
   SetActiveLine(row+1);
}
//---------------------------------------------------------------------------

UnicodeString TCounterForm::EncodeXMLDateTime(unsigned short year, unsigned short month,
	unsigned short day, unsigned short hour, unsigned short min, unsigned short sec)
{
   UnicodeString DateText = IntToStr((int)year) + L"/" + IntToStr((int)month) +
	 L"/" + IntToStr((int)day) + L" " + IntToStr((int)hour) + L":" +
	 IntToStr((int)min) + L":" + IntToStr((int)sec);
   return DateText;
}
//---------------------------------------------------------------------------

UnicodeString TCounterForm::EncodeXMLDate(unsigned short year, unsigned short month, unsigned short day)
{
   UnicodeString DateText = IntToStr((int)year) + L"/" + IntToStr((int)month) +
	 L"/" + IntToStr((int)day);
   return DateText;
}
//---------------------------------------------------------------------------

int TCounterForm::FindXMLLine(UnicodeString text)
{
   for (int i=0; i<AdvMemo1->Lines->Count; i++) {
	 if (ContainsText(AdvMemo1->Lines->Strings[i],text))
	   return i;
	 }
   return -1;
}
//---------------------------------------------------------------------------

// start button
void __fastcall TCounterForm::AdvToolBarButton6Click(TObject *Sender)
{
   ANALUNIT AnalUnit, SSAnalUnit;
   double SpikeQuant, SpikeConc, SampQuant;
   UnicodeString msg;
   bool found;

   // check that analysis unit depth or name entered
   if (AdvEdit3->Text.IsEmpty() && AdvEdit4->Text.IsEmpty()) {
	 msg = L"Analysis unit depth or name (or both) must be entered.";
	 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 return;
	 }
   if (AdvComboBox1->ItemIndex == -1 || AdvComboBox3->ItemIndex == -1) {
	 msg = L"Spike cannot be recorded unless entered";
	 AdvComboBox1->Color = clHighlight;
	 AdvComboBox3->Color = clHighlight;
	 if (MessageDlg(msg, mtWarning, TMsgDlgButtons() << mbRetry << mbIgnore, 0) == mrRetry) {
	   FocusControl(AdvComboBox1);
	   return;
	   }
	 else
	   enter_spike = false;
	 }

   int col_beg = TSSForm->AbsHeaderColCount(TSSForm->ProfGrid1);
   int col_end = TSSForm->AbsContentColCount(TSSForm->ProfGrid1);
   int thk_row = TSSForm->FindRowCodeIC("#Anal.Thick", TSSForm->ProfGrid1);

   // check for duplicate depths or analysis units
   found = false;
   vector<ANALUNIT> SSAnalUnits;
   for (int col = col_beg; col <= col_end; col++) {
	 SSAnalUnit.Depth = TSSForm->ProfGrid1->AbsoluteCells[col][1]->Value;
	 SSAnalUnit.Name = TSSForm->ProfGrid1->AbsoluteCells[col][2]->Value;
	 SSAnalUnit.Thickness = (thk_row > 0) ? TSSForm->ProfGrid1->AbsoluteCells[col][thk_row]->Value : Unassigned();
	 for (unsigned int i=0; i<SSAnalUnits.size(); i++) {
	   if (SSAnalUnit == SSAnalUnits[i]) {
		 found = true;
		 break;
		 }
	   }
	 if (found) {
	   if (!SSAnalUnit.Depth.IsEmpty() && !SSAnalUnit.Name.IsEmpty())
		 msg = L"Analysis unit with Depth «" + VarToStr(SSAnalUnit.Depth) +
			   L"», Name «" + SSAnalUnit.Name;
	   else if (!SSAnalUnit.Depth.IsEmpty())
		 msg = L"Analysis unit with Depth «" + VarToStr(SSAnalUnit.Depth);
	   else
		 msg = L"Analysis unit with Name «" + SSAnalUnit.Name;
	   msg += L"» is duplicated in spreadsheet.";
	   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return;
	   }
     SSAnalUnits.push_back(SSAnalUnit);
	 }


   Panel3->Height = 50;
   AdvPanel1->Visible = true;
   // AdvStringGrid1->Height = 42;
   AdvStringGrid1->Visible = true;
   int row = FindXMLLine(L"<Counts>");
   if (row == -1) {
	 int last_row = AdvMemo1->Lines->Count - 1;
	 AdvMemo1->Lines->Insert(last_row,L"\t</Counts>");
	 AdvMemo1->Lines->Insert(last_row,L"\t<Counts>");
	 AdvMemo1->Lines->Insert(last_row,L"\t</Taxa>");
	 AdvMemo1->Lines->Insert(last_row,L"\t<Taxa>");
	 }

   sscol = col_end + 1;

   if (!AdvEdit3->Text.IsEmpty())
	 AnalUnit.Depth = AdvEdit3->Text.ToDouble();
   if (!AdvEdit9->Text.IsEmpty())
	 AnalUnit.Thickness = AdvEdit9->Text.ToDouble();
   if (!AdvEdit4->Text.IsEmpty())
	 AnalUnit.Name = (WideString)AdvEdit4->Text;

   // see if analysis unit is already in spreadsheet
   found = false;
   int depth_col = 0;
   int ndep = 0;
   for (int col = col_beg; col <= col_end; col++) {
	 SSAnalUnit.Depth = TSSForm->ProfGrid1->AbsoluteCells[col][1]->Value;
	 SSAnalUnit.Name = TSSForm->ProfGrid1->AbsoluteCells[col][2]->Value;
	 SSAnalUnit.Thickness = (thk_row > 0) ? TSSForm->ProfGrid1->AbsoluteCells[col][thk_row]->Value : Unassigned();
	 if (SSAnalUnit.Depth == AnalUnit.Depth) {
	   depth_col = col;
	   ndep++;
	   }
	 if (SSAnalUnit == AnalUnit) {
	   sscol = col;
	   found = true;
	   break;
	   }
	 }
   if (!found && depth_col > 0 && ndep == 1) {    // this not working because depth can be duplicated with differnet names
	 if (ndep == 1) {
	   msg = L"Analysis unit with same depth found in spreadsheet but name or thickness do not match.";
	   msg += L"\nEnter counts into this analysis unit?";
	   if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes) {
		 sscol = depth_col;
		 found = true;
		 }
	   }
	 else {
	   msg = L"Multiple analysis units found in spreadsheet with the same depth.";
	   msg += L" Specify name or thickness to differentiate.";
       MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return;
	   }
	 }

   if (!found) {  // analysis unit not found
	 // see if all existing analysis units have depths
	 double Depth1;
	 int insert_col = sscol;   // last col + 1
	 bool depths_ascending = true;
	 for (int col = col_beg; col <= col_end; col++) {
	   UnicodeString sVal = TSSForm->ProfGrid1->AbsoluteCells[col][1]->Text;
	   if (!sVal.IsEmpty()) {
		 double dVal;
		 if (TryStrToFloat(sVal,dVal)) {
		   if (col == col_beg || dVal >= Depth1) {
			 Depth1 = dVal;
			 if (Depth1 > AnalUnit.Depth && insert_col == sscol) {
			   insert_col = col;
			   }
			 }
		   else {
			 depths_ascending = false;
			 break;
			 }
		   }
		 else {
		   depths_ascending = false;
		   break;
		   }
		 }
	   else {
		 depths_ascending = false;
		 break;
		 }
	   }
	 if (depths_ascending) {
	   if (insert_col != sscol) {
		 int vcol = insert_col - TSSForm->ProfGrid1->HiddenColCount;
		 TSSForm->ProfGrid1->InsertColumn(vcol);
		 sscol = insert_col;
		 }
	   }
	 if (!AnalUnit.Depth.IsEmpty())
	   TSSForm->ProfGrid1->AbsoluteCells[sscol][1]->Value = AnalUnit.Depth;
	 if (!AnalUnit.Name.IsEmpty())
	   TSSForm->ProfGrid1->AbsoluteCells[sscol][2]->Value = AnalUnit.Name;
	 if (!AnalUnit.Thickness.IsEmpty()) {
	   InsertSS(L"#Anal.Thick",L"Analysis Unit Thickness",AnalUnit.Thickness,row);
	   }
	 }

   if (!AdvEdit8->Text.IsEmpty()) {
	 InsertSS(L"#Samp.Name",L"Sample Name",AdvEdit8->Text,row);
	 }

   if (AdvComboBox4->ItemIndex != -1) {
	 InsertSS(L"#Samp.Analyst",L"Sample Analyst",AdvComboBox4->Text,row);
	 CONTACT *Contact = (CONTACT*)AdvComboBox4->Items->Objects[AdvComboBox4->ItemIndex];
	 TProfGridCell *ACell = TSSForm->ProfGrid1->Cells[sscol][row];
	 CELLOBJECT* CellObject;
	 if (ACell->CellObject != NULL)
	   CellObject = (CELLOBJECT*)ACell->CellObject;
	 else {
	   CellObject = new CELLOBJECT(CELLCONTACTS);
	   TSSForm->AddCellObject(ACell, CellObject);
	   }
	 TList* Contacts = (TList*)CellObject->Object;
	 Contacts->Add(Contact);
	 }

   if (!cxDateEdit1->Text.IsEmpty())
	 InsertSS(L"#Samp.DateSamp",L"Date Prepared",cxDateEdit1->Date,row);

   if (!AdvEdit5->Text.IsEmpty() && AdvComboBox2->ItemIndex != -1) {
	 UnicodeString Element = (AdvComboBox2->Text == L"ml") ? L"volume" : L"mass";
	 SampQuant = AdvEdit5->Text.ToDouble();
	 conc_data = true;
	 InsertSS(L"samp.quant", L"Sample quantity", SampQuant, row, Element,
		AdvComboBox2->Text, L"LABO");
	 }

   // if (AdvComboBox1->ItemIndex != -1 && AdvComboBox3->ItemIndex != -1 &&
   //	   AdvComboBox5->ItemIndex != -1 &&	!AdvEdit6->Text.IsEmpty() && !AdvEdit7->Text.IsEmpty()) [
   if (AdvComboBox1->ItemIndex != -1 && AdvComboBox3->ItemIndex != -1) {
	 UnicodeString Spike = AdvComboBox1->Text + L" " + AdvComboBox3->Text;
	 UnicodeString QuantCode, ConcCode, ConcUnits, SpikeCountedCode, SpikeCounted;
	 if (SameText(AdvComboBox1->Text,L"Lycopodium")) {
	   QuantCode = L"Lyc.:quant.add:";       // Lyc.tab:quant.add:n
	   ConcCode = L"Lyc.:conc:gr/";          // Lyc.tab:conc:gr/tab
	   SpikeCountedCode = L"Lyc.spik";
	   SpikeCounted = L"Lycopodium spike";
	   ConcUnits = L"grains/";
	   }
	 else if (SameText(AdvComboBox1->Text,L"Eucalyptus")) {
	   QuantCode = L"Euc.:quant.add:";
	   ConcCode = L"Euc.:conc:gr/";
	   SpikeCountedCode = L"Euc.spik";
	   SpikeCounted = L"Eucalyptus spike";
	   ConcUnits = L"grains/";
	   }
	 else if (SameText(AdvComboBox1->Text,L"Microsphere")) {
	   QuantCode = L"mic.:quant.add:";       // mic.susp:quant.add:ml
	   ConcCode = L"mic.:conc:n/";           // mic.susp:conc:n/ml
	   SpikeCountedCode = L"mic";
	   SpikeCounted = L"Microspheres";
	   ConcUnits = L"number/";
	   }

	 if (SameText(AdvComboBox3->Text,L"tablets")) {   // tablets, suspension
	   QuantCode.Insert(L"tab",5);
	   ConcCode.Insert(L"tab",5);
	   if (SameText(AdvComboBox5->Text,L"number")) {   // g, ml, number
		 QuantCode += L"n";
		 ConcUnits += L"tablet";
		 ConcCode += L"tab";
		 }
	   if (SameText(AdvComboBox5->Text,L"g")) {
		 QuantCode += L"g";
		 ConcUnits += L"g";
		 ConcCode += L"g";
		 }
	   if (SameText(AdvComboBox5->Text,L"ml")) {
		 QuantCode += L"ml";
		 ConcUnits += L"ml";
		 ConcCode += L"ml";
		 }
	   }
	 if (SameText(AdvComboBox3->Text,L"suspension")) {   // tablets, suspension
	   QuantCode.Insert(L"susp",5);
	   QuantCode += L"ml";
	   ConcCode.Insert(L"susp",5);
	   ConcCode += L"ml";
	   ConcUnits += L"ml";
	   }

	 if (!AdvEdit6->Text.IsEmpty() && AdvComboBox5->ItemIndex != -1) {
	   SpikeQuant = AdvEdit6->Text.ToDouble();
	   InsertSS(QuantCode, Spike, SpikeQuant, row, L"quantity added", AdvComboBox5->Text, L"CONC");
	   }
	 else
	   conc_data = false;
	 if (!AdvEdit7->Text.IsEmpty()) {
	   SpikeConc = AdvEdit7->Text.ToDouble();
	   InsertSS(ConcCode, Spike, SpikeConc, row, L"concentration", ConcUnits, L"CONC");
	   }
	 else
	   conc_data = false;
	 if (conc_data)
	   SpikeSampConc = (SpikeQuant*SpikeConc)/SampQuant;
	 InsertSS(SpikeCountedCode, SpikeCounted, 0, spike_row, L"counted", L"number", L"CONC");
	 }

   AdvToolBarButton6->Enabled = false;
   AdvToolBarButton7->Enabled = true;
   AdvToolBarButton8->Enabled = true;
   AdvToolBarButton1->Enabled = true;
   // AdvToolBarButton2->Enabled = true;

   Timer1->Enabled = true;
   FocusControl(AdvEdit12);
}
//---------------------------------------------------------------------------

void TCounterForm::InsertSS(UnicodeString Code, UnicodeString Name, Variant Value,
	int& row, UnicodeString Element, UnicodeString Units, UnicodeString Group)
{
   bool IsMetadata = (Code[1] == L'#');
   row = TSSForm->FindRowCodeIC(Code, TSSForm->ProfGrid1);
   if (row == 0) {
	 for (int i=3; i<TSSForm->ProfGrid1->RowCount; i++) {
	   UnicodeString sscode = TSSForm->ProfGrid1->AbsoluteCells[1][i]->Text;
	   if (sscode.IsEmpty()) {
		 row = i;
		 break;
		 }
	   else if (IsMetadata && sscode[1] != L'#') {
		 row = i;
		 break;
		 }
	   }
	 TSSForm->ProfGrid1->InsertRow(row);
	 TSSForm->ProfGrid1->AbsoluteCells[1][row]->Value = (WideString)Code;
	 TSSForm->ProfGrid1->AbsoluteCells[2][row]->Value = (WideString)Name;
	 if (!Element.IsEmpty())
	   TSSForm->ProfGrid1->AbsoluteCells[3][row]->Value = (WideString)Element;
	 if (!Units.IsEmpty())
	   TSSForm->ProfGrid1->AbsoluteCells[4][row]->Value = (WideString)Units;
	 if (!Group.IsEmpty())
	   TSSForm->ProfGrid1->AbsoluteCells[7][row]->Value = (WideString)Group;
	 }
   TSSForm->ProfGrid1->AbsoluteCells[sscol][row]->Value = Value;
   ssrow_end++;
}
//---------------------------------------------------------------------------

void __fastcall TCounterForm::AdvSplitter1DblClick(TObject *Sender)
{
   Panel3->Height = 50;
}
//---------------------------------------------------------------------------

void __fastcall TCounterForm::AdvSplitter1CanResize(TObject *Sender, int &NewSize,
		  bool &Accept)
{
   if (NewSize < 50)
	 Accept = false;
}
//---------------------------------------------------------------------------

void __fastcall TCounterForm::AdvEdit12KeyPress(TObject *Sender, wchar_t &Key)
{
   ProcessKey(Key);
}
//---------------------------------------------------------------------------

bool TCounterForm::ProcessKey(wchar_t &Key)
{
   bool valid_key = true;
   if (Key == VK_BACK)
	 return true;
   if (!IsUpper(Key) && !IsDigit(Key) && Key != VK_RETURN && Key != SpikeChar && Key != ElemChar)
	 valid_key = false;
   if (AdvEdit12->Text.IsEmpty() && !IsUpper(Key) && Key != SpikeChar)
	 valid_key = false;

   if (!valid_key) {
	 Beep();
	 Key = 0;
	 return false;
	 }

   if (Key == ElemChar)
	 return true;

   if (!slide_query) {
	 if (nslide == 0) {
	   UnicodeString msg = L"Slide has not been entered. Do you want to enter this slide?";
	   if (MessageDlg(msg, mtWarning, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes) {
		 EnterSlide();
		 }
	   }
	 if (nslide > 0 && ntrans == 0) {
	   UnicodeString msg = L"Transect has not been entered. Do you want to enter transect?";
	   if (MessageDlg(msg, mtWarning, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes) {
		 EnterTransect();
		 }
	   }
	 slide_query = true;
	 }

   UnicodeString Code = AdvEdit12->Text;
   UnicodeString Pres, Elem;
   int len;

   if (Key == VK_RETURN) {
	 ParseCode(Code,Pres,Elem);
	 if (!ValidateCode(Code, Key))
	   return false;
	 EnterCount(Code,Pres,Elem);
	 }
   else if (ContainsText(Code,ElemStr)) {
	 if (!ValidateElem(Code, Key))
	   return false;
	 }
   else if (!IsDigit(Key)) {
	 if ((len=Code.Length()) > 0) {
	   if (IsDigit(Code,len)) {
		 ParseCode(Code,Pres,Elem);
		 if (!ValidateCode(Code, Key))
		   return false;
		 EnterCount(Code,Pres,Elem);
		 }
	   }
	 if (IsUpper(Key)) {
	   AdvToolBarButton10->Enabled = true;
	   }
	 else if (Key == SpikeChar) {
	   EnterSpike();
	   Key = 0;
	   }
	 }
   return true;
}
//---------------------------------------------------------------------------

void TCounterForm::ParseCode(UnicodeString& Code, UnicodeString& Pres, UnicodeString& Elem)
{
   int len = Code.Length();
   set<int> scode;

   int pos = Code.Pos(ElemStr);
   if (pos > 0) {
	 Elem = Code.SubString(pos+1,len-pos);
	 Code.Delete(pos,len-pos+1);
	 len = Code.Length();
	 }

   if (IsDigit(Code,len)) {
	 for (int i=1; i<=len; i++) {
	   if (IsDigit(Code,i)) {
		 Pres = Code.SubString(i,len-i+1);
		 for (int idx=1; idx<=Pres.Length(); idx++) {
		   int icode = Pres.SubString(idx,1).ToInt();
		   scode.insert(icode);
		   }
		 set<int>::iterator itr;
		 Pres = L"";
		 for (itr = scode.begin(); itr != scode.end(); itr++)
		   Pres += IntToStr(*itr);
		 Code = Code.SubString(1,i-1);
		 break;
		 }
	   }
	 }

}
//---------------------------------------------------------------------------

void TCounterForm::EnterCount(UnicodeString Code, UnicodeString Pres, UnicodeString ElemCode)
{
   double count = 1.0;
   int row = AdvMemo1->Lines->Count - 2;
   UnicodeString Name, Element, Group;

   // <Count code="P" pres="1"/>

   UnicodeString line = L"\t\t<Count code=\"" + Code + L"\"";
   if (!Pres.IsEmpty()) {
	 line += L" pres=\"" + Pres + L"\"";
	 if (Pres[1] == L'0')
	   count = 0.5;
	 }
   if (!ElemCode.IsEmpty()) {
	 line += L" elem=\"" + ElemCode + L"\"";
	 for (int i=1; i<AdvColumnGrid4->RowCount; i++) {
	   if (ElemCode == AdvColumnGrid4->Cells[0][i]) {
		 Element = AdvColumnGrid4->Cells[1][i];
		 break;
	     }
	   }
	 }
   if (Comment.IsEmpty()) {
	 line += L"/>";
	 AdvMemo1->Lines->Insert(row,line);
	 }
   else {
	 line += L">";
	 AdvMemo1->Lines->Insert(row,line);
	 line = L"\t\t\t<Comment><![CDATA[" + Comment + L"]]></Comment>";
	 AdvMemo1->Lines->Insert(++row,line);
	 line = L"\t\t</Count>";
	 AdvMemo1->Lines->Insert(++row,line);
	 Comment = L"";
	 }
   SetActiveLine(row);

   AdvEdit12->Text = L"";

   for (int row = 1; row < AdvColumnGrid1->RowCount; row++) {
	 if (AdvColumnGrid1->Cells[0][row] == Code) {
	   Name = AdvColumnGrid1->Cells[1][row];
	   if (Element.IsEmpty())
		 Element = AdvColumnGrid1->Cells[2][row];
	   Group = AdvColumnGrid1->Cells[3][row];
	   break;
	   }
	 }
   int ssrow = 0;
   if (!Name.IsEmpty()) {
	 multimap<UnicodeString,int>::iterator itr;
	 pair<multimap<UnicodeString,int>::iterator, multimap<UnicodeString,int>::iterator> range;
	 range = SSTaxa.equal_range(Name);
	 for (itr = range.first; itr != range.second; itr++) {
	   int row = itr->second;
	   if (Element == TSSForm->ProfGrid1->AbsoluteCells[3][row]->Text) {
		 ssrow = row;
		 break;
		 }
	   }

	 if (ssrow == 0) {  // element not found in spreadsheet
	   ssrow_end++;
	   TSSForm->ProfGrid1->AbsoluteCells[1][ssrow_end]->Value = (WideString)Code;
	   TSSForm->ProfGrid1->AbsoluteCells[2][ssrow_end]->Value = (WideString)Name;
	   TSSForm->ProfGrid1->AbsoluteCells[3][ssrow_end]->Value = (WideString)Element;
	   TSSForm->ProfGrid1->AbsoluteCells[7][ssrow_end]->Value = (WideString)Group;
	   ssrow = ssrow_end;
	   SSTaxa.insert(pair<UnicodeString,int>(Name,ssrow));
	   }
	 double totcount = 0;
	 if (!TSSForm->ProfGrid1->AbsoluteCells[sscol][ssrow]->Value.IsEmpty())
	   totcount = (double)TSSForm->ProfGrid1->AbsoluteCells[sscol][ssrow]->Value;
	 TSSForm->ProfGrid1->AbsoluteCells[sscol][ssrow]->Value = totcount + count;
	 }
   else {
	 // error
	 }

   TSUM += count;
   if (InSum[Code])
	 PSUM += count;

   TAXACOUNT tc(Code,Name,count);
   vector<TAXACOUNT>::iterator itr = find(TaxaCounted.begin(), TaxaCounted.end(), tc);
   if (itr == TaxaCounted.end()) {
	 int row = FindXMLLine(L"</Taxa>");
	 UnicodeString line = L"\t\t<Taxon code=\"" + Code + "\">" + Name + L"</Taxon>";
	 AdvMemo1->Lines->Insert(row,line);
	 TaxaCounted.push_back(tc);
	 itr = find(TaxaCounted.begin(), TaxaCounted.end(), tc);
	 }
   else
	 itr->Count += count;  // TODO: check for non-pollen

   // tally preservation
   int ipres = Pres.ToInt();
   if (count == 0.5) {
	 if (itr->Pres.count(0) == 0)
	   itr->Pres[0] = 0.5;
	 else
	   itr->Pres[0] = itr->Pres[0] + 1.0;
	 }
   if (ipres > 0) {
	 if (itr->Pres.count(ipres) == 0)
	   itr->Pres[ipres] = count;
	 else
	   itr->Pres[ipres] = itr->Pres[ipres] + count;
	 }

   sort(TaxaCounted.begin(), TaxaCounted.end());

   for (unsigned int i=0; i<TaxaCounted.size(); i++) {
	 if (i == 255) break;
	 AdvStringGrid1->Cells[i][0] = TaxaCounted[i].Code;
	 AdvStringGrid1->Cells[i][1] = TaxaCounted[i].Count;
	 double SUM = (InSum[TaxaCounted[i].Code]) ? PSUM : TSUM;
	 AdvStringGrid1->Floats[i][2] = 100.0*TaxaCounted[i].Count/SUM;
	 AdvColumnGrid3->Cells[2][1] = PSUM;
	 AdvColumnGrid3->Cells[3][1] = TSUM;
	 }

   if (conc_data && nspike > 0)
	 AdvColumnGrid3->Cells[5][1] = SimpleRoundTo(SpikeSampConc*TSUM/(double)nspike,0);

   AdvToolBarButton10->ImageIndex = 5;
   AdvToolBarButton10->Enabled = false;
   AdvPicture1->Visible = false;
}
//---------------------------------------------------------------------------

void TCounterForm::EnterSpike(void)
{
   UnicodeString line;
   int ns;

   if (!enter_spike) {
	 Beep();
	 return;
	 }

   int row = AdvMemo1->Lines->Count - 3;
   line = AdvMemo1->Lines->Strings[row];
   if (ContainsText(line, L"<Spike n=")) {
	 ns = GetXMLSpikeCount(line) + 1;
	 line = L"\t\t<Spike n=\"" + IntToStr(ns) + L"\"/>";
	 AdvMemo1->Lines->Strings[row] = line;
	 }
   else {
	 line = L"\t\t<Spike n=\"1\"/>";     // <Spike n="1"/>
	 row++;
	 AdvMemo1->Lines->Insert(row,line);
	 }
   SetActiveLine(row);
   AdvEdit12->Text = L"";

   AdvColumnGrid3->Cells[4][1] = ++nspike;
   if (conc_data && TSUM > 0)
	 AdvColumnGrid3->Cells[5][1] = SimpleRoundTo(SpikeSampConc*TSUM/(double)nspike,0);

   double dspike = TSSForm->ProfGrid1->AbsoluteCells[sscol][spike_row]->Value;
   TSSForm->ProfGrid1->AbsoluteCells[sscol][spike_row]->Value = dspike+1;
   AdvToolBarButton10->Enabled = false;
   AdvPicture1->Visible = false;
}
//---------------------------------------------------------------------------

int TCounterForm::GetXMLSpikeCount(UnicodeString line)
{
   int pos = line.Pos(L"=");
   line.Delete(1,pos+1);
   pos = line.Pos(L"\"");
   return line.SubString(1,pos-1).ToInt();
}
//---------------------------------------------------------------------------

bool TCounterForm::ValidAdvEditFloatValue(TAdvEdit* AdvEdit)
{
   double Value;
   bool IsValid = true;
   if (!AdvEdit->Text.IsEmpty()) {
	 IsValid = TryStrToFloat(AdvEdit->Text,Value);
	 if (!IsValid)
	   AdvEdit->Text = L"";
	 }
   return IsValid;
}
//---------------------------------------------------------------------------

void __fastcall TCounterForm::AdvEditValueValidate(TObject *Sender, UnicodeString Value,
		  bool &IsValid)
{
   double dValue;
   if (!Value.IsEmpty())
	 IsValid = TryStrToFloat(Value,dValue);
}
//---------------------------------------------------------------------------

void __fastcall TCounterForm::Panel3Resize(TObject *Sender)
{
   int Height = Panel3->Height - Bevel1->Height - AdvDockPanel1->Height;
   multimap<int,TControl*>::iterator itr;
   for (itr = MetadataControls.begin(); itr != MetadataControls.end(); itr++) {
	 itr->second->Visible = (itr->first < Height);
	 }
}
//---------------------------------------------------------------------------

// pause counting
void __fastcall TCounterForm::AdvToolBarButton7Click(TObject *Sender)
{
   ShowMessage(L"Panel3->Height = " + IntToStr(Panel3->Height-Bevel1->Top-AdvDockPanel1->Height));
}
//---------------------------------------------------------------------------

// sums
void __fastcall TCounterForm::AdvToolBarButton9Click(TObject *Sender)
{
   if (AdvColumnGrid2->Visible) {
	 AdvColumnGrid2->Visible = false;
	 AdvToolBarButton11->Enabled = true;
	 return;
	 }

   set<UnicodeString> Groups;
   for (int row=1; row<AdvColumnGrid1->RowCount; row++) {
	 UnicodeString Group = AdvColumnGrid1->Cells[3][row];
	 if (Groups.count(Group) == 0)
	   Groups.insert(Group);
	 }
   AdvColumnGrid2->RowCount = Groups.size()+1;
   AdvColumnGrid2->AddCheckBoxColumn(0, false, false);
   AdvColumnGrid2->Height = Min(203,20*AdvColumnGrid2->RowCount+3);
   set<UnicodeString>::iterator itr;
   int row = 1;
   for (itr = Groups.begin(); itr != Groups.end(); itr++) {
	 AdvColumnGrid2->Cells[1][row] = *itr;
	 bool checked = (find(Sums.begin(),Sums.end(),*itr) != Sums.end());
	 AdvColumnGrid2->SetCheckBoxState(0,row,checked);
	 row++;
	 }
   AdvColumnGrid2->Top  = 30;
   AdvColumnGrid2->Visible = true;
   AdvToolBarButton11->Enabled = false;
   FocusControl(AdvColumnGrid2);
}
//---------------------------------------------------------------------------

// elements
void __fastcall TCounterForm::AdvToolBarButton11Click(TObject *Sender)
{
   if (AdvColumnGrid4->Visible) {
	 AdvColumnGrid4->Visible = false;
	 AdvToolBarButton9->Enabled = true;
	 }
   else {
	 AdvColumnGrid4->Height = Min(203,20*AdvColumnGrid4->RowCount+3);
	 AdvColumnGrid4->Visible = true;
	 AdvToolBarButton9->Enabled = false;
	 FocusControl(AdvColumnGrid4);
	 }
}
//---------------------------------------------------------------------------

void __fastcall TCounterForm::AdvColumnGrid2Exit(TObject *Sender)
{
   ResetSums();
   AdvColumnGrid2->Visible = false;
}
//---------------------------------------------------------------------------

void TCounterForm::ResetSums(void)
{
   bool state;
   Sums.clear();
   for (int row=1; row<AdvColumnGrid2->RowCount; row++) {
	 AdvColumnGrid2->GetCheckBoxState(0, row, state);
	 if (state)
	   Sums.push_back(AdvColumnGrid2->Cells[1][row]);
	 }

   // TODO: recalculate pollen sum
}
//---------------------------------------------------------------------------

void TCounterForm::SetActiveLine(int row)
{
   if (row != -1) {
	 if (AdvMemo1->Lines->Count > AdvMemo1->VisibleLineCount)
	   AdvMemo1->SetCursor(1,row);
	 AdvMemo1->ActiveLine = row;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TCounterForm::Timer1Timer(TObject *Sender)
{
   Seconds++;
   unsigned int hours = Math::Floor((double)Seconds/3600);
   unsigned int dsec = Seconds % 3600;
   unsigned int minutes = Math::Floor((double)dsec/60);
   dsec = dsec % 60;
   UnicodeString shour, smin, ssec;
   shour.sprintf(L"%03u",hours);
   if (shour[1] == L'0')
	 shour.Delete(1,1);
   AdvColumnGrid3->Cells[6][1] = shour + L":" + smin.sprintf(L"%02u",minutes) + L":" + ssec.sprintf(L"%02u",dsec);
}
//---------------------------------------------------------------------------

void __fastcall TCounterForm::AdvMemo1GutterRightClick(TObject *Sender, int LineNo)
{
   bool valid_edit = false;

   AdvMemo1->ActiveLine = LineNo;

   UnicodeString line = AdvMemo1->Lines->Strings[LineNo];

   int pos = line.Pos(L"<");
   if (pos > 0) {
	 if (line.SubString(pos+1,5) ==  L"Count") {
	   valid_edit = true;
	   Edit1->Caption = L"Edit Count";
	   Delete1->Caption = L"Delete Count";
	   }
	 }

   if (valid_edit) {
	 TPoint p_scr = Mouse->CursorPos;
	 AdvPopupMenu1->Popup(p_scr);
	 }
}
//---------------------------------------------------------------------------

void __fastcall TCounterForm::Edit1Click(TObject *Sender)
{
   if (ContainsText(Edit1->Caption, L"Edit Count")) {
	 EditCount();
	 }
}
//---------------------------------------------------------------------------

void __fastcall TCounterForm::Delete1Click(TObject *Sender)
{
   if (ContainsText(Delete1->Caption, L"Delete Count")) {
	 Beep();
	 }
}
//---------------------------------------------------------------------------

void TCounterForm::EditCount(void)
{
   int pos1, pos2, pos3;
   UnicodeString value, newvalue, leadingtabs;

   int LineNo = AdvMemo1->ActiveLine;

   UnicodeString line = AdvMemo1->Lines->Strings[LineNo];
   ShowMessage(line);
   int len = line.Length();

   // <Count code="AB" pres="0"/>

   pos1 = line.Pos(L"<");
   if (pos1 == 0)
	 return;

   leadingtabs = line.SubString(1,pos1-1);
   pos2 = line.Pos(L"code=");
   if (pos2 == 0)
	 return;

   // ShowMessage(line.SubString(pos2+6,len-pos2-5));
   pos3 = line.SubString(pos2+6,len-pos2-5).Pos(L"\"");
   value = line.SubString(pos2+6,pos3-1);
   pos2 = line.Pos(L"pres=");
   if (pos2 > 0) {
	 pos3 = line.SubString(pos2+6,len-pos2-5).Pos(L"\"");
	 value += line.SubString(pos2+6,pos3-1);
	 }

   ShowMessage(L"value = " + value);

   MemoForm = new TMemoForm(L"Edit Count", value, MemoFormOptions() << mfoTextEdit << mfoCancelButton, this);
   if (MemoForm->ShowModal() == mrOk) {
	 newvalue = MemoForm->cxTextEdit1->Text;
	 if (Caption == L"Edit Count") {
	   if (!newvalue.IsEmpty()) {
		 newvalue = newvalue.UpperCase();
		 if (newvalue != value) {
		   // TODO: test if valid count/preservation
		   // TODO: re-tally counts, sums,...
		   // AdvMemo1->Lines->Strings[LineNo] = newvalue;
		   }
		 }
	   else {
		 // TODO: delete count?
		 }
	   }
	 }
}
//---------------------------------------------------------------------------

void __fastcall TCounterForm::AdvComboBox1Enter(TObject *Sender)
{
   AdvComboBox1->Color = clWindow;
}
//---------------------------------------------------------------------------

void __fastcall TCounterForm::AdvComboBox3Enter(TObject *Sender)
{
   AdvComboBox3->Color = clWindow;
}
//---------------------------------------------------------------------------

void __fastcall TCounterForm::AdvColumnGrid1ButtonClick(TObject *Sender, int ACol,
          int ARow)
{
   wchar_t Key;
   UnicodeString Code = AdvColumnGrid1->Cells[0][ARow];
   if (!AdvEdit12->Text.IsEmpty()) {
	 Key = VK_RETURN;
	 ProcessKey(Key);
	 }
   if (ValidateCode(Code, Key)) {
	 AdvEdit12->Text = Code;
     AdvEdit12->SelStart = Code.Length();
	 }
   FocusControl(AdvEdit12);
}
//---------------------------------------------------------------------------

bool TCounterForm::ValidateCode(UnicodeString Code, wchar_t& Key)
{
   for (int i=1; i<AdvColumnGrid1->RowCount; i++) {
	 if (Code == AdvColumnGrid1->Cells[0][i])
	   return true;
	 }
   MessageBeep(MB_ICONERROR);
   MessageDlg(L"Code not in dictionary!", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
   Key = 0;
   return false;
}
//---------------------------------------------------------------------------

bool TCounterForm::ValidateElem(UnicodeString Code, wchar_t& Key)
{
   Code += Key;
   int pos = Code.Pos(ElemStr);
   UnicodeString Elem = Code.Delete(1,pos);
   int len = Elem.Length();
   for (int i=1; i<AdvColumnGrid4->RowCount; i++) {
	 UnicodeString ElemCode = AdvColumnGrid4->Cells[0][i];
	 if (len <= ElemCode.Length()) {
	   if (Elem == ElemCode.SubString(1,len))
		 return true;
	   }
	 }
   MessageBeep(MB_ICONERROR);
   UnicodeString msg = L"Element code is not valid. You must press the Enter key to post a count with element.";
   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
   Key = 0;
   return false;
}
//---------------------------------------------------------------------------

// edit taxa
void __fastcall TCounterForm::AdvToolBarButton13Click(TObject *Sender)
{
   AdvColumnGrid1->UnHideColumns(2,3);
   editrow = AdvColumnGrid1->Row;
   AdvColumnGrid1->Options >> goRowSelect;
   for (int col=0; col<=3; col++) {
	 AdvColumnGrid1->ReadOnly[col][editrow] = false;
	 AdvColumnGrid1->Colors[col][editrow] = TColor(0x00EACAB6);
	 }

   //AdvColumnGrid1->B
}
//---------------------------------------------------------------------------

void __fastcall TCounterForm::AdvColumnGrid1CanClickCell(TObject *Sender, int ARow,
		  int ACol, bool &Allow)
{
   if (editrow > -1 && ARow != editrow)
	 Allow = false;
}
//---------------------------------------------------------------------------

void __fastcall TCounterForm::AdvColumnGrid1CellChanging(TObject *Sender, int OldRow,
          int OldCol, int NewRow, int NewCol, bool &Allow)
{
   Beep();
}
//---------------------------------------------------------------------------

