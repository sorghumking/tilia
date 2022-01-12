//---------------------------------------------------------------------------

#include <vcl.h>
#include <math.h>
#include <algorithm>
#pragma hdrstop

#ifndef TILOWESSH
#include "TILOWESS.h"
#endif
#ifndef TIPolyH
#include "TIPoly.h"
#endif
#include "TIChron.h"
#ifndef TGUtilsH
#include "TGUtils.h"
#endif
#ifndef TIAgeResH
#include "TIAgeRes.h"
#endif

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxMaskEdit"
#pragma link "cxSpinEdit"
#pragma link "cxTextEdit"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
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
#pragma resource "*.dfm"
TChronForm *ChronForm;

//---------------------------------------------------------------------------
bool operator<(const AGEDEPTH &x, const AGEDEPTH &y)
{
   return x.Depth < y.Depth;
}
//---------------------------------------------------------------------------

//bool operator<(const double &x, const double &y)
//{
//   return x.Depth < y.Depth;
//}
//---------------------------------------------------------------------------

CHRONDATA::CHRONDATA(int n, UnicodeString name, UnicodeString units)
{
   ChronNumber = n;
   ChronName = name;
   AgeUnits = units;
   Row = -1;
}
//---------------------------------------------------------------------------

void CHRONDATA::alloc(int sz)
{
   if (!SampleAges.empty())
     SampleAges.clear();
   SAMPLEAGES Control;
   Control.Age = NaN;
   Control.AgeYounger = NaN;
   Control.AgeOlder = NaN;
   SampleAges.assign(sz, Control);
}
//---------------------------------------------------------------------------

void AGEMODELGRAPH::GetDepthMinMax(double& MinDepth, double& MaxDepth)
{
   vector<double> ChronControlDepths;
   for (int i=0; i<ChronControls->Count; i++) {
     CHRON* Chron = (CHRON*)ChronControls->Items[i];
     ChronControlDepths.push_back(Chron->Depth);
     }
   vector<double>::iterator itmin = min_element(ChronControlDepths.begin(), ChronControlDepths.end());
   vector<double>::iterator itmax = max_element(ChronControlDepths.begin(), ChronControlDepths.end());
   MinDepth = *itmin;
   MaxDepth = *itmax;
}
//---------------------------------------------------------------------------

void AGEMODELGRAPH::GetAgeMinMax(double& MinAge, double& MaxAge)
{
   vector<double> ChronControlAges;
   for (int i=0; i<ChronControls->Count; i++) {
     CHRON* Chron = (CHRON*)ChronControls->Items[i];
	 ChronControlAges.push_back(Chron->AgeValue);
     }
   vector<double>::iterator itmin = min_element(ChronControlAges.begin(), ChronControlAges.end());
   vector<double>::iterator itmax = max_element(ChronControlAges.begin(), ChronControlAges.end());
   MinAge = *itmin;
   MaxAge = *itmax;
}
//---------------------------------------------------------------------------

__fastcall TChronForm::TChronForm(TComponent* Owner)
        : TForm(Owner)
{
   SSForm = (TTilSpreadSheetForm*)Owner;
}
//---------------------------------------------------------------------------

void __fastcall TChronForm::FormCreate(TObject *Sender)
{
   Chrons = new TList;
   AgeModelMethod = -1;
   AgeModelList = new TList;
   Plot = true;
   fpoints = 100;
   lsmooth = 0.5;
   lsteps = 2;
   lSmoothType = LWS_PROP;
   lDepthWindow = NaN;
   lAgeWindow = NaN;
   CheckBoxChange = true;
   EditChange = true;
   ExtrapYounger = false;
   ExtrapOlder = false;
   MinDepthLimit = NaN;
   MaxDepthLimit = NaN;
   pDegree = 1;
   pFixYIntercept = false;
   pFixedY = NaN;
   pFitWithinLimits = false;
   Saved = false;
}
//---------------------------------------------------------------------------

void __fastcall TChronForm::FormDestroy(TObject *Sender)
{
   for (int i=0; i<Chrons->Count; i++) {
     CHRONDATA *ChronData = (CHRONDATA*)Chrons->Items[i];
     delete ChronData;
     Chrons->Items[i] = 0;
     }
   Chrons->Clear();
   delete Chrons;

   // remove ChronControls, but don't delete them
   for (int i=0; i<AgeModelList->Count; i++) {
     AGEMODELGRAPH* AgeModel = (AGEMODELGRAPH*)AgeModelList->Items[i];
     AgeModel->ChronControls->Clear();
     delete AgeModel;
     AgeModelList->Items[i] = 0;
     }
   AgeModelList->Clear();
   delete AgeModelList;
}
//---------------------------------------------------------------------------

void __fastcall TChronForm::FormActivate(TObject *Sender)
{
   double x, y, yy, yo;

   // Series 1 - ChronControl points
   AGEMODELGRAPH* AgeModel1 = (AGEMODELGRAPH*)AgeModelList->Items[0];

   for (int i=0; i<AgeModel1->ChronControls->Count; i++) {
     CHRON *Chron = (CHRON*)AgeModel1->ChronControls->Items[i];
	 if (!Chron->Depth.IsEmpty()) {
	   x = Chron->Depth;
	   if (AgeModel1->HasPoints) {
		 if (!Chron->AgeValue.IsEmpty()) {
		   y = Chron->AgeValue;
		   Series1->AddXY(x, y, FloatToStr(y), clRed);  // ChronControl points
		   }
		 }
	   else if (AgeModel1->HasLimits) {
		 if (!Chron->AgeLimitYounger.IsEmpty() && !Chron->AgeLimitOlder.IsEmpty()) {
		   yy = Chron->AgeLimitYounger;
		   yo = Chron->AgeLimitOlder;
           Series3->AddXY(x, yy, FloatToStr(yy), clRed);
           Series4->AddXY(x, yo, FloatToStr(yo), clRed);
		   }
         }
       }
     }

   if (AgeModel1->HasPoints)
     RadioGroup3->ItemIndex = 0;
   else if (AgeModel1->HasLimits)
     RadioGroup3->ItemIndex = 1;

   CHRONDATA *Y = (CHRONDATA*)Chrons->Items[0];
   if (Y->SampleAges.size() > 0)
     PlotSampleAges(Y);
   else
     EnableEditing();

   Chart1->LeftAxis->Title->Caption = AgeModel1->AgeUnits;
   LabeledEdit1->Text = AgeModel1->ChronologyName;
   LabeledEdit2->Text = AgeModel1->AgeModel;
}
//---------------------------------------------------------------------------

void TChronForm::EnableEditing(void)
{
   LabeledEdit1->ReadOnly = false;
   LabeledEdit1->Color = clWindow;
   LabeledEdit2->ReadOnly = false;
   LabeledEdit2->Color = clWindow;
   RadioGroup1->Enabled = true;
   RadioGroup2->Enabled = true;

   Plot = false;
   RadioGroup2->ItemIndex = -1;
   RadioGroup1->ItemIndex = -1;
}
//---------------------------------------------------------------------------

void TChronForm::DisableEditing(void)
{
   LabeledEdit1->ReadOnly = true;
   LabeledEdit1->Color = clBtnFace;
   LabeledEdit2->ReadOnly = true;
   LabeledEdit2->Color = clBtnFace;
   RadioGroup1->Enabled = false;
   RadioGroup2->Enabled = false;

   Plot = false;
   RadioGroup2->ItemIndex = -1;
   RadioGroup1->ItemIndex = -1;
}
//---------------------------------------------------------------------------

void TChronForm::SetAgeModelList(TAgeModelList* amlist)
{
   //MasterAgeModelList = amlist;
   for (int i=0; i<amlist->Count; i++) {
     AGEMODEL* AgeModel1 = amlist->AgeModels[i];
     AGEMODELGRAPH* AgeModel2 = new AGEMODELGRAPH;
     AgeModel2->ChronNumber = AgeModel1->ChronNumber;
     AgeModel2->ChronologyName = AgeModel1->ChronologyName;
     AgeModel2->AgeUnits = AgeModel1->AgeUnits;
     AgeModel2->DatePrepared = AgeModel1->DatePrepared;
     AgeModel2->AgeModel = AgeModel1->AgeModel;
     AgeModel2->ChronControls = new TList;
     AgeModel2->ChronControls->Assign(AgeModel1->ChronControls);

     AgeModel2->HasPoints = true;
     AgeModel2->HasLimits = true;
     for (int j=0; j<AgeModel2->ChronControls->Count; j++) {
	   CHRON *Chron = (CHRON*)AgeModel2->ChronControls->Items[j];
	   if (Chron->AgeValue.IsEmpty())
		 AgeModel2->HasPoints = false;
	   if (Chron->AgeLimitOlder.IsEmpty() || Chron->AgeLimitYounger.IsEmpty())
		 AgeModel2->HasLimits = false;
	   }

	 AgeModelList->Add(AgeModel2);
     }
}
//---------------------------------------------------------------------------

// Change chronology
void __fastcall TChronForm::ComboBox1Change(TObject *Sender)
{
   double x, y, yy, yo;

   int ChronIndex = ComboBox1->ItemIndex;
   AGEMODELGRAPH* AgeModel = (AGEMODELGRAPH*)AgeModelList->Items[ChronIndex];
   Series1->Clear();
   Series2->Clear();
   Series3->Clear();
   Series4->Clear();

   // plot points or limits?
   bool Points = false;
   bool Limits = false;
   if (RadioGroup3->ItemIndex == 0) { // points
     if (AgeModel->HasPoints)
       Points = true;
     else if (AgeModel->HasLimits) {
       Limits = true;
       RadioGroup3->ItemIndex = 1;
       }
     else
       RadioGroup3->ItemIndex = -1;
     }
   else if (RadioGroup3->ItemIndex == 1) { // limits
     if (AgeModel->HasLimits)
       Limits = true;
     else if (AgeModel->HasPoints) {
       Points = true;
       RadioGroup3->ItemIndex = 0;
       }
     else
       RadioGroup3->ItemIndex = -1;
     }

   if (Points || Limits) {
     for (int i=0; i<AgeModel->ChronControls->Count; i++) {
       CHRON *Chron = (CHRON*)AgeModel->ChronControls->Items[i];
	   if (!Chron->Depth.IsEmpty()) {
		 x = Chron->Depth;
		 if (Points) {
		   if (!Chron->AgeValue.Empty()) {
			 y = Chron->AgeValue;
			 Series1->AddXY(x, y, FloatToStr(y), clRed);  // control points
			 }
		   }
		 else if (Limits) {
		   if (!Chron->AgeLimitYounger.IsEmpty() && !Chron->AgeLimitOlder.IsEmpty()) {
             yy = Chron->AgeLimitYounger;
		     yo = Chron->AgeLimitOlder;
			 Series3->AddXY(x, yy, FloatToStr(yy), clRed);
             Series4->AddXY(x, yo, FloatToStr(yo), clRed);
             }
           }
         }
       }
     }

   // plot sample ages from spreadsheet
   CHRONDATA *Y = (CHRONDATA*)Chrons->Items[ChronIndex];
   if (Y->SampleAges.size() > 0) {
     DisableEditing();
     PlotSampleAges(Y);
     }
   else
     EnableEditing();

   Chart1->LeftAxis->Title->Caption = AgeModel->AgeUnits;
   LabeledEdit1->Text = AgeModel->ChronologyName;
   LabeledEdit2->Text = AgeModel->AgeModel;
}
//---------------------------------------------------------------------------

void __fastcall TChronForm::cxButton3Click(TObject *Sender)
{
   EnableEditing();
   LabeledEdit2->Text = "";
   Series2->Clear();
}
//---------------------------------------------------------------------------

// select age model method
void __fastcall TChronForm::RadioGroup1Click(TObject *Sender)
{
   int ChronIndex = ComboBox1->ItemIndex;
   AGEMODELGRAPH* AgeModel = (AGEMODELGRAPH*)AgeModelList->Items[ChronIndex];

   if (AgeModel->ChronControls->Count < 2) {
	 MessageDlg("At least two chronology controls required.", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
     RadioGroup1->ItemIndex = -1;
     cxButton6->Enabled = false;
	 return;
     }

   if (!AgeModel->HasPoints) {
     MessageDlg("No age points entered.", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
     RadioGroup1->ItemIndex = -1;
     cxButton6->Enabled = false;
     return;
     }
   cxButton6->Enabled = true;

   double MinDepth;
   double MaxDepth;
   AgeModel->GetDepthMinMax(MinDepth, MaxDepth);

   switch (RadioGroup1->ItemIndex) {
     case 0:               // linear interpolation
     case 1:               // polynomial
     case 3:               // cubic B-spline
     case 4:               // LOWESS
       if (Depths.front() < MinDepth)
         CheckBox2->Enabled = true;
       if (Depths.back() > MaxDepth)
         CheckBox3->Enabled = true;
       break;
     case 2:               // cubic spline
       CheckBox2->Enabled = false;
       CheckBox3->Enabled = false;
       break;
     }
   LabeledEdit3->Enabled = true;
   LabeledEdit4->Enabled = true;
   LabeledEdit3->Color = clWindow;
   LabeledEdit4->Color = clWindow;
   LabeledEdit3->Text = FloatToStr(MinDepth);
   LabeledEdit4->Text = FloatToStr(MaxDepth);
}
//---------------------------------------------------------------------------

// Go button
void __fastcall TChronForm::cxButton6Click(TObject *Sender)
{
   double MinDepth, MaxDepth, MinAge, MaxAge;
   int ns;
   int ChronIndex = ComboBox1->ItemIndex;
   AGEMODELGRAPH* AgeModel = (AGEMODELGRAPH*)AgeModelList->Items[ChronIndex];
   TPolynomialOptionsForm *PolyOptionsForm;
   TLOWESSOptionsForm *LOWESSOptionsForm;

   vector<AGEDEPTH> ChronControls;
   AGEDEPTH ChronControl;
   for (int i=0; i<AgeModel->ChronControls->Count; i++) {
     CHRON* Chron = (CHRON*)AgeModel->ChronControls->Items[i];
     ChronControl.Depth = Chron->Depth;
	 ChronControl.Age = Chron->AgeValue;
     ChronControls.push_back(ChronControl);
     }
   sort(ChronControls.begin(), ChronControls.end());

   ExtrapYounger = CheckBox2->Checked;
   ExtrapOlder = CheckBox3->Checked;

   CHRONDATA *Y = (CHRONDATA*)Chrons->Items[ChronIndex];

   switch (RadioGroup1->ItemIndex) {
     case 0:                        // linear interpolation
       if (LinearInterp(ChronControls, Y))
         NewAgeModel(Y);
       switch (RadioGroup2->ItemIndex) {
         case -1:
           RadioGroup2->ItemIndex = 0;
         case 0:
           PlotLinearInterp(AgeModel);
           break;
         case 1:
           PlotSampleAges(Y);
           break;
         }
       LabeledEdit2->Text = "linear interpolation";
       AgeModel->AgeModel = "linear interpolation";
       break;
     case 1:                // polynomial
       PolyOptionsForm = new TPolynomialOptionsForm(this);
	   PolyOptionsForm->cxSpinEdit1->Properties->MaxValue = min((unsigned int)10, ChronControls.size()-1);
       if (PolyOptionsForm->cxSpinEdit1->Properties->MaxValue == 1)
         PolyOptionsForm->cxSpinEdit1->Enabled = false;
       PolyOptionsForm->cxSpinEdit1->Value = pDegree;
       PolyOptionsForm->CheckBox1->Checked = pFixYIntercept;
       PolyOptionsForm->CheckBox2->Checked = pFitWithinLimits;
       if (IsNan(pFixedY))
         pFixedY = ChronControls.front().Age;
       PolyOptionsForm->pFixedY = pFixedY;
       PolyOptionsForm->pY0 = ChronControls.front().Age;
       if (PolyOptionsForm->ShowModal() == mrOk) {
         pDegree = PolyOptionsForm->cxSpinEdit1->Value;
         pFixYIntercept = PolyOptionsForm->CheckBox1->Checked;
         pFixedY = PolyOptionsForm->pFixedY;
         pFitWithinLimits = PolyOptionsForm->CheckBox2->Checked;
         delete PolyOptionsForm;
         }
       else {
         delete PolyOptionsForm;
         return;
         }

       if (PolynomialInterp(ChronControls, Y))
         NewAgeModel(Y);
       switch (RadioGroup2->ItemIndex) {
         case -1:
           RadioGroup2->ItemIndex = 0;
         case 0:
           PlotFunction(Y);
           break;
         case 1:
           PlotSampleAges(Y);
           break;
         }
       LabeledEdit2->Text = "polynomial interpolation";
       AgeModel->AgeModel = "polynomial interpolation";
       break;
     case 2:                // cubic spline
       if (CubicSplineInterp(ChronControls, Y))
         NewAgeModel(Y);
       switch (RadioGroup2->ItemIndex) {
         case -1:
           RadioGroup2->ItemIndex = 0;
         case 0:
           PlotFunction(Y);
           break;
         case 1:
           PlotSampleAges(Y);
           break;
         }
       LabeledEdit2->Text = "cubic spline interpolation";
       AgeModel->AgeModel = "cubic spline interpolation";
       break;
     case 3:               // cubic B-spline
       if (BSpline(ChronControls, Y))
         NewAgeModel(Y);
       switch (RadioGroup2->ItemIndex) {
         case -1:
           RadioGroup2->ItemIndex = 0;
         case 0:
           PlotFunction(Y);
           break;
         case 1:
           PlotSampleAges(Y);
           break;
         }
       LabeledEdit2->Text = "cubic B-spline approximation";
       AgeModel->AgeModel = "cubic B-spline approximation";
       break;
     case 4:               // LOWESS
       AgeModel->GetDepthMinMax(MinDepth, MaxDepth);
       AgeModel->GetAgeMinMax(MinAge, MaxAge);
       ns = 0;
       for (unsigned int i=0; i<Depths.size(); i++) {
         if (Depths[i] > MaxDepth) break;
         if (Depths[i] > MinDepth) ns++;
         }
       LOWESSOptionsForm = new TLOWESSOptionsForm(this);
       LOWESSOptionsForm->cxSpinEdit1->Value = lsmooth;
       LOWESSOptionsForm->cxSpinEdit2->Value = lsteps;
       LOWESSOptionsForm->SetMinMax(ChronControls.size(), MinDepth, MaxDepth, MinAge, MaxAge);
       LOWESSOptionsForm->DepthWindow = lDepthWindow;
       LOWESSOptionsForm->AgeWindow = lAgeWindow;
       LOWESSOptionsForm->RadioGroup1->ItemIndex = lSmoothType;
       if (LOWESSOptionsForm->ShowModal() == mrOk) {
         lSmoothType = LOWESSOptionsForm->RadioGroup1->ItemIndex;
         lsmooth = LOWESSOptionsForm->cxSpinEdit1->Value;
         lsteps = LOWESSOptionsForm->cxSpinEdit2->Value;
         lDepthWindow = LOWESSOptionsForm->DepthWindow;
         lAgeWindow = LOWESSOptionsForm->AgeWindow;
         delete LOWESSOptionsForm;
         }
       else {
         delete LOWESSOptionsForm;
         return;
         }
       if (LowessInterp(ChronControls, Y))
         NewAgeModel(Y);
       switch (RadioGroup2->ItemIndex) {
         case -1:
           RadioGroup2->ItemIndex = 0;
         case 0:
           PlotFunction(Y);
           break;
         case 1:
           PlotSampleAges(Y);
           break;
         }
       LabeledEdit2->Text = "LOWESS interpolation";
       AgeModel->AgeModel = "LOWESS interpolation";
       break;
     }
   TestMonotonicity(Y);
   AgeModelMethod = RadioGroup1->ItemIndex;
}
//---------------------------------------------------------------------------

// plot function or sample ages
void __fastcall TChronForm::RadioGroup2Click(TObject *Sender)
{
   if (!Plot) {
     Plot = true;
     return;
     }
   if (RadioGroup1->ItemIndex == -1)
     return;

   int ChronIndex = ComboBox1->ItemIndex;
   AGEMODELGRAPH* AgeModel = (AGEMODELGRAPH*)AgeModelList->Items[ChronIndex];
   CHRONDATA *Y = (CHRONDATA*)Chrons->Items[ChronIndex];
   Series2->Clear();

   switch (RadioGroup2->ItemIndex) {
     case 0:                         // function
       switch (RadioGroup1->ItemIndex) {
         case 0:   // linear interpolation
           PlotLinearInterp(AgeModel);
           break;
         case 1:
         case 2:
         case 3:
         case 4:
           PlotFunction(Y);
           break;
         }
       break;
     case 1:                          // sample ages
       PlotSampleAges(Y);
       break;
     }
}
//---------------------------------------------------------------------------

void TChronForm::PlotLinearInterp(AGEMODELGRAPH* AgeModel)
{
   double x, y;
   
   Series2->Clear();
   for (int i=0; i<AgeModel->ChronControls->Count; i++) {
     CHRON *Chron = (CHRON*)AgeModel->ChronControls->Items[i];
	 if (!Chron->Depth.IsEmpty() && !Chron->AgeValue.IsEmpty()) {
	   x = Chron->Depth;
	   y = Chron->AgeValue;
	   Series2->AddXY(x, y, FloatToStr(y), clRed);  // age model
	   }
     }
}
//---------------------------------------------------------------------------

void TChronForm::PlotSampleAges(CHRONDATA* Y)
{
   double x, y;

   Series2->Clear();
   if (Depths.size() == Y->SampleAges.size()) {
     for (unsigned int i=0; i<Depths.size(); i++) {
       y = Y->SampleAges[i].Age;
       if (!IsNan(y)) {
         x = Depths[i];
         Series2->AddXY(x, y, FloatToStr(y), clRed);  // age model
         }
       }
     }
}
//---------------------------------------------------------------------------

void TChronForm::PlotFunction(CHRONDATA* Y)
{
   Series2->Clear();
   for (unsigned int i=0; i<Y->Function.size(); i++)
     Series2->AddXY(Y->Function[i].Depth, Y->Function[i].Age,
                    FloatToStr(Y->Function[i].Age), clRed);  // age model
}
//---------------------------------------------------------------------------

void __fastcall TChronForm::RadioGroup3Click(TObject *Sender)
{
   double x, y, yy, yo;
   int ChronIndex = ComboBox1->ItemIndex;
   AGEMODELGRAPH* AgeModel = (AGEMODELGRAPH*)AgeModelList->Items[ChronIndex];

   if (RadioGroup3->ItemIndex == 0) {  // points
     if (AgeModel->HasPoints) {
       Series1->Clear();
       Series3->Clear();
       Series4->Clear();
       for (int i=0; i<AgeModel->ChronControls->Count; i++) {
         CHRON *Chron = (CHRON*)AgeModel->ChronControls->Items[i];
		 if (!Chron->Depth.IsEmpty()) {
		   x = Chron->Depth;
		   if (!Chron->AgeValue.IsEmpty()) {
			 y = Chron->AgeValue;
			 Series1->AddXY(x, y, FloatToStr(y), clRed);  // control points
			 }
		   }
		 }
	   }
     else {
       MessageDlg("No age points entered.", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
       RadioGroup3->ItemIndex = 1;
       }
     }
   if (RadioGroup3->ItemIndex == 1) {  // limits
     if (AgeModel->HasLimits) {
       Series1->Clear();
       Series3->Clear();
       Series4->Clear();
       for (int i=0; i<AgeModel->ChronControls->Count; i++) {
		 CHRON *Chron = (CHRON*)AgeModel->ChronControls->Items[i];
		 if (!Chron->Depth.IsEmpty()) {
		   x = Chron->Depth;
		   if (!Chron->AgeLimitYounger.IsEmpty() && !Chron->AgeLimitOlder.IsEmpty()) {
             yy = Chron->AgeLimitYounger;
			 yo = Chron->AgeLimitOlder;
			 Series3->AddXY(x, yy, FloatToStr(yy), clRed);
             Series4->AddXY(x, yo, FloatToStr(yo), clRed);
			 }
           }
         }
       }
     else  {
       MessageDlg("No age limits entered.", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
       RadioGroup3->ItemIndex = 0;
       }
     }
}
//---------------------------------------------------------------------------

void TChronForm::GetLimits(vector<AGEDEPTH>& ChronControls, double& MinLimit, double& MaxLimit)
{
   if (ExtrapYounger)
     MinLimit = Depths.front();
   else if (!IsNan(MinDepthLimit))
     MinLimit = MinDepthLimit;
   else
     MinLimit = ChronControls.front().Depth;
   if (ExtrapOlder)
     MaxLimit = Depths.back();
   else if (!IsNan(MaxDepthLimit))
     MaxLimit = MaxDepthLimit;
   else
     MaxLimit = ChronControls.back().Depth;
}
//---------------------------------------------------------------------------

void TChronForm::TestMonotonicity(CHRONDATA* Y)
{
   bool NonMonotonicSampleAges = false;
   bool NonMonotonicFunction = false;
   double LastAge;
   bool FirstFound = false;
   for (unsigned int i=0; i<Y->SampleAges.size(); i++) {
     if (FirstFound) {
       if (IsNan(Y->SampleAges[i].Age)) break;
       if (Y->SampleAges[i].Age < LastAge) {
         NonMonotonicSampleAges = true;
         break;
         }
       else
         LastAge = Y->SampleAges[i].Age;
       }
     else if (!IsNan(Y->SampleAges[i].Age)) {
       LastAge = Y->SampleAges[i].Age;
       FirstFound = true;
       }
     }

   if (Y->Function.size() > 0) {
     LastAge = Y->Function[0].Age;
     for (unsigned int i=1; i<Y->Function.size(); i++) {
       if (Y->Function[i].Age < LastAge) {
         NonMonotonicFunction = true;
         break;
         }
       else
         LastAge = Y->Function[i].Age;
       }
     }

   if (NonMonotonicSampleAges)
     MessageDlg("Sample ages are not monotonically increasing.", mtWarning, TMsgDlgButtons() << mbOK, 0);
   else if (NonMonotonicFunction)
     MessageDlg("Age model function is not monotonically increasing, although sample ages are.", mtWarning, TMsgDlgButtons() << mbOK, 0);
}
//---------------------------------------------------------------------------

bool TChronForm::LinearInterp(vector<AGEDEPTH>& ChronControls, CHRONDATA* Y)
{
   unsigned int i, j;
   double x1, x2, y1, y2, m, b, value;
   unsigned int jb = 0;
   double MinLimit, MaxLimit;
   //bool extrap_younger = false;
   //bool extrap_older = false;

   int ndates = ChronControls.size();

   Y->SampleAges.clear();
   Y->alloc(Depths.size());

   if (IsNan(ChronControls[0].Depth) || IsNan(ChronControls[0].Age)) {
	 MessageDlg("Missing depth or age value.", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
     return false;
     }

   GetLimits(ChronControls, MinLimit, MaxLimit);

   //for (int k=0; k<AgeModel->ChronControls->Count-1; k++) {
   for (int k=0; k<ndates-1; k++) {
     // check for missing values
     if (IsNan(ChronControls[k+1].Depth) || IsNan(ChronControls[k+1].Age)) {
       MessageDlg("Missing depth or age value.", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
       return false;
       }

     //CHRON *Chron1 = (CHRON*)AgeModel->ChronControls->Items[k];
     //CHRON *Chron2 = (CHRON*)AgeModel->ChronControls->Items[k+1];
     //x1 = Chron1->Depth;
     //x2 = Chron2->Depth;
     //y1 = Chron1->AgeValue;
     //y2 = Chron2->AgeValue;

     x1 = ChronControls[k].Depth;
     x2 = ChronControls[k+1].Depth;
     y1 = ChronControls[k].Age;
     y2 = ChronControls[k+1].Age;

     //if (IsNan(x1) || IsNan(x2) || IsNan(y1) || IsNan(y2)) {
     //  MessageDlg("Missing depth or age value.", mtError, TMsgDlgButtons() << mbOK, 0);
     //  return false;
     //  }

     m = (y2-y1)/(x2-x1);
     b = y1 - m*x1;
     for (j=jb; j<Depths.size(); j++)
       if (Depths[j] >= x1) break;

     if (j == Depths.size())
       break;

     if (k == 0 && j > 0) {
       for (i=0; i<j; i++) {
         if (Depths[i] >= MinLimit && Depths[i] <= MaxLimit)
           Y->SampleAges[i].Age = m*Depths[i] + b;
         }
       }
     jb = j;
     for (j=jb; j<Depths.size(); j++) {
       if (Depths[j] <= x2) {
         value = m*Depths[j] + b;
         if (fabs(value) < 1.0e-10) value = 0.0;
         if (Depths[j] >= MinLimit && Depths[j] <= MaxLimit)
           Y->SampleAges[j].Age = value;
         }
       else
         break;
       }
     }
   // samples beyond last date
   if (j < Depths.size()) {
     for (unsigned int k=j; k<Depths.size(); k++) {
       if (Depths[k] >= MinLimit && Depths[k] <= MaxLimit)
         Y->SampleAges[k].Age = m*Depths[k] + b;
       }
     }

   /*
   GetLimits(ChronControls, MinLimit, MaxLimit);
   for (unsigned int j=0; j<Depths.size(); j++) {
     if (Depths[j] >= MinLimit && Depths[j] <= MaxLimit)
       Y->SampleAges[j].Age = CubicSpline.splint(Depths[j]);
     }
   */
   //ExtrapWarnings(extrap_younger, extrap_older);
   return true;
}


/*
bool TChronForm::LinearInterp(AGEMODELGRAPH* AgeModel, CHRONDATA* Y)
{
  unsigned int i, j;
  double x1, x2, y1, y2, m, b, value;
  unsigned int jb = 0;
  bool extrap_younger = false;
  bool extrap_older = false;

  Y->SampleAges.clear();
  Y->alloc(Depths.size());

  for (int k=0; k<AgeModel->ChronControls->Count-1; k++) {
    CHRON *Chron1 = (CHRON*)AgeModel->ChronControls->Items[k];
    CHRON *Chron2 = (CHRON*)AgeModel->ChronControls->Items[k+1];
    x1 = Chron1->Depth;
    x2 = Chron2->Depth;
    y1 = Chron1->AgeValue;
    y2 = Chron2->AgeValue;
    if (IsNan(x1) || IsNan(x2) || IsNan(y1) || IsNan(y2)) {
      MessageDlg("Missing depth or age value.", mtError, TMsgDlgButtons() << mbOK, 0);
      return false;
      }

    m = (y2-y1)/(x2-x1);
    b = y1 - m*x1;
    for (j=jb; j<Depths.size(); j++)
      if (Depths[j] >= x1) break;

    if (j == Depths.size())
      break;

    if (k == 0 && j > 0) {
      extrap_younger = true;
      for (i=0; i<j; i++)
        Y->SampleAges[i].Age = m*Depths[i] + b;
      }
    jb = j;
    for (j=jb; j<Depths.size(); j++) {
      if (Depths[j] <= x2) {
        value = m*Depths[j] + b;
        if (fabs(value) < 1.0e-10) value = 0.0;
        Y->SampleAges[j].Age = value;
        }
      else
        break;
      }
    }
  // samples beyond last date
  if (j < Depths.size()) {
    extrap_older = true;
    for (unsigned int k=j; k<Depths.size(); k++)
      Y->SampleAges[k].Age = m*Depths[k] + b;
    }

  ExtrapWarnings(extrap_younger, extrap_older);
  return true;
}
*/
//---------------------------------------------------------------------------

bool TChronForm::CubicSplineInterp(vector<AGEDEPTH>& ChronControls, CHRONDATA* Y)
{
   vector<double> x;
   vector<double> y;
   double MinLimit;
   double MaxLimit;

   int ndates = ChronControls.size();

   // check for missing values
   for (int i=0; i<ndates; i++) {
    if (IsNan(ChronControls[i].Depth) || IsNan(ChronControls[i].Age)) {
	  MessageDlg("Missing depth or age value.", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
      return false;
      }
    }

   // check for chron contorls with same depths
   for (int i=0; i<ndates-1; i++) {
    if (ChronControls[i].Depth == ChronControls[i+1].Depth) {
	  MessageDlg("Cubic spline cannot have two Chronology Controls at the same depth.",
	    Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
      return false;
      }
    }

   Y->SampleAges.clear();
   Y->alloc(Depths.size());

   for (int i=0; i<ndates; i++) {
     x.push_back(ChronControls[i].Depth);
     y.push_back(ChronControls[i].Age);
     }

   CUBICSPLINE CubicSpline(ndates, &x, &y);
   CubicSpline.run();

   GetLimits(ChronControls, MinLimit, MaxLimit);
   for (unsigned int j=0; j<Depths.size(); j++) {
     if (Depths[j] >= MinLimit && Depths[j] <= MaxLimit)
       Y->SampleAges[j].Age = CubicSpline.splint(Depths[j]);
     }

   Y->Function.clear();
   double xlen = MaxLimit - MinLimit;
   double ninc = (double)(fpoints - 1);
   AGEDEPTH AgeDepth;
   for (unsigned int j=0; j<fpoints; j++) {
     double Depth = MinLimit + ((double)j/ninc)*xlen;
     if (Depth >= MinLimit && Depth <= MaxLimit) {
       AgeDepth.Depth = Depth;
       AgeDepth.Age = CubicSpline.splint(AgeDepth.Depth);
       Y->Function.push_back(AgeDepth);
       }
     }
   return true;
}
//---------------------------------------------------------------------------

// Arrays x and y of length n contain the original x,y coordinates.
CUBICSPLINE::CUBICSPLINE(int _n, vector<double>* _x, vector<double>* _y)
{
   n = _n;
   x = _x;
   y = _y;
   y2.assign(n+1, 0.0);
}
//---------------------------------------------------------------------------

// Returns array y2, which contains second derivatives of the
// interpolating function at the points x[i]
void CUBICSPLINE::run(void)
{
  int i, k;
  double sig, p, qn, un;

  vector<double> u(n+1, 0.0);

  for (i=1; i<n-1; i++) {
    sig = ((*x)[i] - (*x)[i-1])/((*x)[i+1] - (*x)[i-1]);
    p = sig*y2[i-1]+2;
    y2[i] = (sig-1.0)/p;
    u[i] = (6.0*(((*y)[i+1] - (*y)[i])/((*x)[i+1] - (*x)[i]) - ((*y)[i] - (*y)[i-1])/
           ((*x)[i] - (*x)[i-1]))/((*x)[i+1] - (*x)[i-1]) - sig*u[i-1])/p;
    }

  qn = 0.0;
  un = 0.0;

  y2[n] = (un-qn*u[n-1])/(qn*y2[n-1]+1.0);
  for (k=n-2; k>=0; k--)
    y2[k] = y2[k]*y2[k+1]+u[k];
}
//---------------------------------------------------------------------------

// Returns cubic spline interpolated value for given x
double CUBICSPLINE::splint(double xi)
{
  int k, klo, khi;
  double h, a, b, yi;

  klo = 1;
  khi = n;

  while (khi-klo > 1) {
    k = (khi+klo)/2;
    if ((*x)[k-1] > xi)
      khi = k;
     else
      klo = k;
    }
  khi--;
  klo--;

  h = (*x)[khi] - (*x)[klo];
  a = ((*x)[khi] - xi)/h;
  b = (xi - (*x)[klo])/h;
  yi = a*(*y)[klo] + b*(*y)[khi] +
      ((pow(a,3)- a)*y2[klo] + (pow(b,3) - b)*y2[khi])*(h*h)/6.0;

  return(yi);
}
//---------------------------------------------------------------------------

bool TChronForm::BSpline(vector<AGEDEPTH>& ChronControls, CHRONDATA* Y)
{
   vector<double> x;
   vector<double> y;
   double MinLimit;
   double MaxLimit;

   int ndates = ChronControls.size();

   // check for missing values
   for (int i=0; i<ndates; i++) {
    if (IsNan(ChronControls[i].Depth) || IsNan(ChronControls[i].Age)) {
      MessageDlg("Missing depth or age value.", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
      return false;
      }
    }

   Y->SampleAges.clear();
   Y->alloc(Depths.size());

   for (int i=0; i<ndates; i++) {
     x.push_back(ChronControls[i].Depth);
     y.push_back(ChronControls[i].Age);
     }

   GetLimits(ChronControls, MinLimit, MaxLimit);
   BSPLINE BSpline(ndates, &x, &y);

   for (unsigned int j=0; j<Depths.size(); j++) {
     if (Depths[j] >= MinLimit && Depths[j] <= MaxLimit)
       Y->SampleAges[j].Age = BSpline.Interp(Depths[j]);
     }

   Y->Function.clear();
   double xlen = MaxLimit - MinLimit;
   double ninc = (double)(fpoints - 1);
   AGEDEPTH AgeDepth;
   for (unsigned int j=0; j<fpoints; j++) {
     double Depth = MinLimit + ((double)j/ninc)*xlen;
     if (Depth >= MinLimit && Depth <= MaxLimit) {
       AgeDepth.Depth = Depth;
       AgeDepth.Age = BSpline.Interp(AgeDepth.Depth);
       Y->Function.push_back(AgeDepth);
       }
     }
   return true;
}
//---------------------------------------------------------------------------

BSPLINE::BSPLINE(int _n, vector<double>* _x, vector<double>* _y)
{
   n = _n;
   x = _x;
   y = _y;
}
//---------------------------------------------------------------------------

// B spline basis interpolation
// Carl deBoor. 2001. A Practical Guide to Splines. Springer.
double BSPLINE::Interp(double xval)
{
  double bval;
  int left;
  int right;
  double u;
  double yval;

   // Find the nearest interval [ x(left), x(right) ] to xval.
   Bracket(xval, &left, &right);

   // Evaluate the 5 nonzero B spline basis functions in the interval,
   // weighted by their corresponding data values.
   u = (xval - (*x)[left])/((*x)[right] - (*x)[left]);
   yval = 0.0;

   // B function associated with node left - 1, (or "phantom node"),
   // evaluated in its 4th interval.

   bval = (((-1.0*u + 3.0)*u - 3.0)*u + 1.0)/6.0;

   if (0 < left)
     yval = yval + (*y)[left-1]*bval;
   else
     yval = yval + (2.0*(*y)[0] - (*y)[1])*bval;

   // B function associated with node left, evaluated in its third interval.

   bval = (((3.0*u - 6.0)*u + 0.0)*u + 4.0)/6.0;
   yval = yval + (*y)[left]*bval;

   // B function associated with node right, evaluated in its second interval.

   bval = (((-3.0*u + 3.0)*u + 3.0)*u + 1.0)/6.0;
   yval = yval + (*y)[right]*bval;

   // B function associated with node right+1, (or "phantom node"),
   // evaluated in its first interval.

   bval = pow(u,3)/6.0;

   if (right+1 < n)
     yval = yval + (*y)[right+1]*bval;
   else
     yval = yval + (2.0*(*y)[n-1] - (*y)[n-2])*bval;

   return yval;
}

//---------------------------------------------------------------------------
void BSPLINE::Bracket(double xval, int *left, int *right)
{
  for (int i=1; i<n-1; i++) {
    if (xval < (*x)[i]) {
      *left = i - 1;
      *right = i;
      return;
      }
    }
  *left = n - 2;
  *right = n - 1;
  return;
}
//---------------------------------------------------------------------------

bool TChronForm::LowessInterp(vector<AGEDEPTH>& ChronControls, CHRONDATA* Y)
{
   int ndates = ChronControls.size();
   vector<double> x(ndates, 0.0);
   vector<double> y(ndates, 0.0);
   vector<double> iAges;
   vector<double> iDepths;
   vector<double> fAges;
   vector<double> fDepths;
   double MinLimit, MaxLimit;

   // check for missing values
   for (int i=0; i<ndates; i++) {
    if (IsNan(ChronControls[i].Depth) || IsNan(ChronControls[i].Age)) {
	  MessageDlg("Missing depth or age value.", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	  return false;
      }
    }

   Y->SampleAges.clear();
   Y->alloc(Depths.size());

   for (int i=0; i<ndates; i++) {
     x[i] = ChronControls[i].Depth;
     y[i] = ChronControls[i].Age;
     }

   GetLimits(ChronControls, MinLimit, MaxLimit);
   LOWESS lowess(&x, &y, lSmoothType, lDepthWindow, lAgeWindow);

   for (unsigned int j=0; j<Depths.size(); j++) {
     if (Depths[j] >= MinLimit && Depths[j] <= MaxLimit)
       iDepths.push_back(Depths[j]);
     }
   iAges.assign(iDepths.size(), 0.0);

   if (lowess.run(lsmooth, lsteps, 0.0)) {
     lowess.interp(iDepths, iAges);
     int i = 0;
     for (unsigned int j=0; j<Depths.size(); j++) {
       if (Depths[j] >= MinLimit && Depths[j] <= MaxLimit)
         Y->SampleAges[j].Age = iAges[i++];
       }

     Y->Function.clear();
     double xlen = MaxLimit - MinLimit;
     double ninc = (double)(fpoints - 1);
     for (unsigned int j=0; j<fpoints; j++)
       fDepths.push_back(MinLimit + ((double)j/ninc)*xlen);

     fAges.assign(fDepths.size(), 0.0);
     lowess.interp(fDepths, fAges);
     AGEDEPTH AgeDepth;
     for (unsigned int j=0; j<fpoints; j++) {
       AgeDepth.Depth = fDepths[j];
       AgeDepth.Age = fAges[j];
       Y->Function.push_back(AgeDepth);
       }
     }
   else {
     return false;
     }

   return true;
}
//---------------------------------------------------------------------------

LOWESS::LOWESS(vector<double>* _x, vector<double>* _y, int stype, double xwin, double ywin)
{
   SmoothType = stype;
   xwind = xwin;
   ywind = ywin;
   x = _x;
   y = _y;
   n = x->size();    // change if 0 based
   ys.assign(n, 0.0);
   resw.assign(n, 0.0);
   res.assign(n, 0.0);
}
//---------------------------------------------------------------------------

bool LOWESS::run(double f, int nsteps, double delta)
{
   bool ok;
   int ns, iw;
   double halfwind, windleft;
   double d1, d2;

   if (n < 2){
     ys[1] = (*y)[1];
     return false;
     }

   switch (SmoothType) {
     case LWS_PROP:
       ns = max(min((int)floor(f*(double)n) ,n) ,2);
       break;
     case LWS_XWIN:
       halfwind = xwind/2.0;
       windleft = (*x)[0];
       iw = 1;
       while (iw < n && ((*x)[iw] - windleft) <= xwind)
         iw++;
       ns = max(iw, 2);
       break;
     case LWS_YWIN:
       halfwind = ywind/2.0;
       windleft = (*y)[0];
       iw = 1;
       while (iw < n && ((*y)[iw] - windleft) <= ywind)
         iw++;
       ns = max(iw, 2);
       break;
     }

   for (iter=1; iter<=nsteps+1; iter++) {      // robustness iterations
     int nleft = 0;
     int nright = ns-1;
     int last = -1;        // index of prev estimated point
     int i = 0;

     Left.clear();
     Right.clear();

     do {
         switch (SmoothType) {
           case LWS_PROP:
             while(nright < n-1){
               // move nleft, nright to right if radius decreases
               d1 = (*x)[i] - (*x)[nleft];
               d2 = (*x)[nright+1] - (*x)[i];
               // if d1 <= d2 with x(nright+1)==x(nright), lowest fixes
               if (d1 <= d2) break;
               // radius will not decrease by move right
               nleft++;
               nright++;
               }
             break;
           case LWS_XWIN:
             while (nleft > 0 && ((*x)[i] - (*x)[nleft]) < halfwind)
               nleft--;
             if (((*x)[i] - (*x)[nleft]) > halfwind)
               nleft++;
             if (((*x)[nright] - (*x)[nleft]) < xwind) {
               while (nright < n-1 && ((*x)[nright] - (*x)[nleft]) < xwind)
                 nright++;
               }
             if (((*x)[nright] - (*x)[nleft]) > xwind)
               nright--;
             if (nright == n-1) {
               while (nleft > 0 && ((*x)[nright] - (*x)[nleft]) < xwind)
                 nleft--;
               if (((*x)[nright] - (*x)[nleft]) > xwind)
                 nleft++;
               }
             break;
           case LWS_YWIN:
             while (nleft > 0 && ((*y)[i] - (*y)[nleft]) < halfwind)
               nleft--;
             if (((*y)[i] - (*y)[nleft]) > halfwind)
               nleft++;
             if (((*y)[nright] - (*y)[nleft]) < ywind) {
               while (nright < n-1 && ((*y)[nright] - (*y)[nleft]) < ywind)
                 nright++;
               }
             if (((*y)[nright] - (*y)[nleft]) > ywind)
               nright--;
             if (nright == n-1) {
               while (nleft > 0 && ((*y)[nright] - (*y)[nleft]) < ywind)
                 nleft--;
               if (((*y)[nright] - (*y)[nleft]) > ywind)
                 nleft++;
               }
             break;
           }


         Left.push_back(nleft);
         Right.push_back(nright);

         ok = lowest((*x)[i], ys[i], nleft, nright, iter>1, res, resw);
         // fitted value at x(i)
         if (!ok)
           ys[i] = (*y)[i];

         // all weights zero - copy over value (all resw == 0)
         if (last < i-1) {             // skipped points -- interpolate
           double denom = (*x)[i] - (*x)[last];    // non-zero - proof?
           for(int j=last+1; j<i; j++){
             double alpha = ((*x)[j] - (*x)[last])/denom;
             ys[j] = alpha*ys[i] + (1.0 - alpha)*ys[last];
             }
           }
         last = i;                           // last point actually estimated
         double cut = (*x)[last] + delta;    //  x coord of close points

         for(i=last+1; i<n; i++){           // find close points
           if ((*x)[i] > cut) break;         // i one beyond last pt within cut
           if ((*x)[i] == (*x)[last]) {      // exact match in x
             ys[i] = ys[last];
             last = i;
             }
           }

         i = max(last+1, i-1);
         // back 1 point so interpolation within delta, but always go forward
        } while (last < n-1);

     for (i=0; i<n; i++)
       res[i] = (*y)[i] - ys[i];

     if (iter > nsteps) break;  // compute robustness weights except last time
     for (i=0; i<n; i++)
       resw[i] = fabs(res[i]);

     sort(resw.begin(), resw.end());

     int m1 = n/2;
     int m2 = n - m1 - 1;
     double cmad = 3.0*(resw[m1] + resw[m2]);    // 6 median abs resid
     double c9 = 0.999*cmad;
     double c1 = 0.001*cmad;

     for (i=0; i<n; i++) {
       double r = fabs(res[i]);
       if (r <= c1)
         resw[i] = 1.0;      // near 0, avoid underflow
       else if (r > c9)
         resw[i] = 0.0;      // near 1, avoid underflow
       else
         resw[i] = pow(1.0 - pow((r/cmad), 2), 2) ;
       }
     }
   return true;
}
//---------------------------------------------------------------------------

bool LOWESS::lowest(double xs, double &ys, int nleft, int nright, bool userw,
                    vector<double> &w, vector<double> &rw)
{
   bool ok;

   double range = (*x)[n-1] - (*x)[0];
   double h = max(xs-(*x)[nleft], (*x)[nright]-xs);
   double h9 = 0.999*h;
   double h1 = 0.001*h;
   double a = 0.0;        // sum of weights
   int j;
   for(j=nleft; j<n; j++){     // compute weights (pick up all ties on right)
     w[j] = 0.0;
     double r = fabs((*x)[j] - xs);
     if (r <= h9) {    // small enough for non-zero weight
       if (r > h1)
         w[j] = pow(1.0 - pow(r/h, 3), 3);
       else
         w[j] = 1.0;
       if (userw)
         w[j] *= rw[j];
       a += w[j];
       }
     else if ((*x)[j] > xs) {  // get out at first zero wt on right
       break;
       }
     }

   int nrt = j - 1;  //rightmost pt (may be greater than nright because of ties)
   if ( a <= 0.0)
     ok = false;
   else {                    // weighted least squares
     ok = true;
     for (j=nleft; j<=nrt; j++)
        w[j] /= a;               // make sum of w(j) == 1
     if (h > 0.0) {              // use linear fit
        a = 0.0;
        for (j=nleft; j<=nrt; j++)
          a += (w[j]*(*x)[j]);   // weighted center of x values
        double b = xs-a;
        double c = 0.0;
        for (j=nleft; j<=nrt; j++)
          c += (w[j]*pow((*x)[j]-a, 2));
        if(sqrt(c) > 0.001*range) {
          // points are spread out enough to compute slope
          b /= c;
          for (j=nleft; j<=nrt; j++)
             w[j] *= (1.0 + b*((*x)[j]-a));
          }
        }

     ys = 0.0;
     for (j=nleft; j<=nrt; j++)
       ys += (w[j]*(*y)[j]);
     }
   return ok;
}
//---------------------------------------------------------------------------

void LOWESS::interp(vector<double>& xi, vector<double>& yi)
{
   bool ok;

   vector<double> rwi(resw);
   vector<double> wi(res);

   for (unsigned int i=0; i<xi.size(); i++) {
     double d = fabs(xi[i] - (*x)[0]);
     int nearest = 0;
     for (int j=1; j<n; j++) {
       double dt = fabs(xi[i] - (*x)[j]);
       if (dt < d) {
         d = dt;
         nearest = j;
         }
       }

     ok = lowest(xi[i], yi[i], Left[nearest], Right[nearest], iter>1, wi, rwi);
     if (!ok)
       yi[i] = 0;
     }
}
//---------------------------------------------------------------------------

bool TChronForm::PolynomialInterp(vector<AGEDEPTH>& ChronControls, CHRONDATA* Y)
{
   double MinLimit, MaxLimit;

   int ndates = ChronControls.size();

   // check for missing values
   for (int i=0; i<ndates; i++) {
    if (IsNan(ChronControls[i].Depth) || IsNan(ChronControls[i].Age)) {
      MessageDlg("Missing depth or age value.", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
      return false;
      }
    }

   Y->SampleAges.clear();
   Y->alloc(Depths.size());

   GetLimits(ChronControls, MinLimit, MaxLimit);

   if (pFitWithinLimits) {
     if (MinLimit < ChronControls.back().Depth) {
       while (ChronControls.front().Depth < MinLimit)
         ChronControls.erase(ChronControls.begin());
       }
     if (MaxLimit > ChronControls.front().Depth) {
       while (ChronControls.back().Depth > MaxLimit)
         ChronControls.erase(ChronControls.end()-1);
       }

     if (ChronControls.size() < 2) {
       MessageDlg("At least two dates must lie between limits to fit polynomial.",
         Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
       return false;
       }
     }

   POLYNOMIAL Polynom(&ChronControls);
   if (Polynom.run(pDegree, pFixYIntercept, pFixedY)) {     //ncol, fixed_intercept, b0
     for (unsigned int j=0; j<Depths.size(); j++) {
       if (Depths[j] >= MinLimit && Depths[j] <= MaxLimit)
         Y->SampleAges[j].Age = Polynom.calc_y(Depths[j]);
       }
     }

   Y->Function.clear();
   double xlen = MaxLimit - MinLimit;
   double ninc = (double)(fpoints - 1);
   AGEDEPTH AgeDepth;
   for (unsigned int j=0; j<fpoints; j++) {
     double Depth = MinLimit + ((double)j/ninc)*xlen;
     if (Depth >= MinLimit && Depth <= MaxLimit) {
       AgeDepth.Depth = Depth;
       AgeDepth.Age = Polynom.calc_y(Depth);
       Y->Function.push_back(AgeDepth);
       }
     }

   zero_adjust = Polynom.zero_adjust;
   Coefs = Polynom.coef;
   return true;
}
//---------------------------------------------------------------------------

POLYNOMIAL::POLYNOMIAL(vector<AGEDEPTH>* cc)
{
   ChronControls = cc;
   ndates = (*ChronControls).size();
}
//---------------------------------------------------------------------------

bool POLYNOMIAL::run(int order, bool fixed_intercept, double b0)
{
  bool extrap;
  double xi, power;
  long double sumy, sumy2, srs, see, x;
  double yc, yi, res;

  ncol = order;

  maxc = ++ncol;
  maxr = ndates;

  xmatr.assign(maxr*maxc, 0.0);
  a.assign(maxc*maxc, 0.0);
  coef.assign(maxc, 0.0);
  ycalc.assign(maxr, 0.0);
  resid.assign(maxr, 0.0);
  sig.assign(maxc, 0.0);

  zero_adjust = 0.0;

  if (fixed_intercept) {
    if ((*ChronControls).front().Depth != 0.0)
      zero_adjust = (*ChronControls).front().Depth;
    }

  for (int i=0; i<ndates; i++) {
    xi = (*ChronControls)[i].Depth - zero_adjust;
    xmatr[maxc*i] = 1.0;
    for (int j=1; j<ncol; j++) {
      power = j;
      xmatr[maxc*i + j] = pow(xi, power);
      }
    }

  square();

  if (fixed_intercept) {
    for (int i=1; i<ncol; i++)
      coef[i-1] = coef[i] - b0 * a[maxc*i];
    for (int j=1; j<ncol; j++)
      for (int i=1; i<ncol; i++)
        a[maxc*(i-1) + j-1] = a[maxc*i + j];
    ncol--;
    }

  if (!gaussj())
    return false;

  if (fixed_intercept) {
    ncol++;
    for (int i=ncol-2; i>=0; i--)
      coef[i+1] = coef[i];
    coef[0] = b0;
    }

  sumy = 0.0;
  sumy2 = 0.0;
  srs = 0.0;

  for (int i=0; i<ndates; i++) {
    yi = (*ChronControls)[i].Age;
    yc = 0.0;
    for (int j=0; j<ncol; j++)
      yc += (coef[j] * xmatr[maxc*i + j]);
    ycalc[i] = yc;
    res = yc - yi;
    resid[i] = res;
    srs += res*res;
    sumy += yi;
    sumy2 += yi*yi;
    }


  x = 1.0 - srs/(sumy2-sumy*sumy/(long double)ndates);
  if (x < 0.0) {
    MessageDlg("Due to rounding error you cannot calculate a polynomial of this order.",
	  Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
    return false;
    }
  correl = sqrtl(x);

  if (ndates == ncol) {
    if (srs < 0.0) {
      MessageDlg("Due to rounding error you cannot calculate a polynomial of this order.",
		Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
      return false;
      }
    see = sqrtl(srs);
    }
  else  {
    x = srs/(long double)(ndates - ncol);
    if (x < 0.0) {
      MessageDlg("Due to rounding error you cannot calculate a polynomial of this order.",
        Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
      return false;
      }
    see = sqrtl(x);
    }
  for (int i=0; i<ncol; i++) {
    x = a[maxc*i + i];
    if (x < 0.0) {
      MessageDlg("Due to rounding error you cannot calculate a polynomial of this order.",
        Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
      return false;
      }
    sig[i] = see*sqrtl(x);
    }

  if (fixed_intercept) {
    for (int i=ncol-1; i>0; i--)
      sig[i] = sig[i-1];
    sig[0] = 0.0;
    }
  return true;
}
//---------------------------------------------------------------------------

double POLYNOMIAL::calc_y(double x)
{
   double y = coef[0];
   for (int i=1; i<ncol; i++)
     y += (coef[i] * pow(x-zero_adjust, (double)i));
   return y;
}
//---------------------------------------------------------------------------

// matrix multiplication routine
// a = transpose x times x
// g = y times x
// square(             xmatr,              a,           coef, ncol, maxc, nd);
void POLYNOMIAL::square(void)
{
   for (int k=0; k<ncol; k++) {
     for (int l=0; l<=k; l++) {
       a[maxc*k + l] = 0.0;
       for (int i=0; i<ndates; i++) {
         a[maxc*k + l] += (xmatr[maxc*i + l] * xmatr[maxc*i + k]);
         if (k != l)
           a[maxc*l + k] = a[maxc*k + l];
         }
       coef[k] = 0.0;
       for (int i=0; i<ndates; i++)
         coef[k] += ((*ChronControls)[i].Age * xmatr[maxc*i + k]);
       }
     }
}
//---------------------------------------------------------------------------

bool POLYNOMIAL::gaussj(void)
{
  int icol, irow;
  long double pivot, big, t;

  vector< vector<int> > index(maxc, vector<int>(3,0));

  for (int i=0; i<ncol; i++) {
    big = 0.0;
    for (int j=0; j<ncol; j++) {
      if (index[j][2] != 1) {
        for (int k=0; k<ncol; k++) {
          if (index[k][2] > 1) {
            MessageDlg("Matrix singular!", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
            return false;
            }
          else if (index[k][2] == 1)
            continue;
          else if (fabs(a[maxc*j + k]) <= big)
            continue;
          else {
            irow = j;
            icol = k;
            big = fabs(a[maxc*j + k]);
            }
          }
        }
      }
    index[icol][2]++;
    index[i][0] = irow;
    index[i][1] = icol;
    if (irow != icol) {
      for (int l=0; l<ncol; l++)
        swap(a, maxc*irow + l, maxc*icol + l);
      swap(coef, irow, icol);
      }
    pivot = a[maxc*icol + icol];
    a[maxc*icol + icol] = 1.0;
    for (int l=0; l<ncol; l++)
      a[maxc*icol + l] /= pivot;
    coef[icol] /= pivot;
    for (int l1=0; l1<ncol; l1++) {
      if (l1 != icol) {
        t = a[maxc*l1 + icol];
        a[maxc*l1 + icol] = 0.0;
        for (int l=0; l<ncol; l++)
          a[maxc*l1 + l] -= (a[maxc*icol + l] * t);
        coef[l1] -= (coef[icol] * t);
        }
      }
    }

  for (int i=0; i<ncol; i++) {
    int l = ncol - i - 1;
    if (index[l][0] != index[l][1]) {
      irow = index[l][0];
      icol = index[l][1];
      for (int k=0; k<ncol; k++)
        swap(a, maxc*k + irow, maxc*k + icol);
      }
    }

  for (int k=0; k<ncol; k++)
    if (index[k][2] != 1) {
      MessageDlg("Matrix singular!", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
      return false;
      }

  return true;
}


//---------------------------------------------------------------------------

void POLYNOMIAL::swap(vector<long double>& vec, int i, int j)
{
  long double hold = vec[i];
  vec[i] = vec[j];
  vec[j] = hold;
}
//---------------------------------------------------------------------------

void __fastcall TChronForm::Chart1Scroll(TObject *Sender)
{
   Screen->Cursor = crHandPoint;
}
//---------------------------------------------------------------------------

void __fastcall TChronForm::Chart1MouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
   Screen->Cursor = crDefault;
}
//---------------------------------------------------------------------------

void __fastcall TChronForm::Chart1MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
   if (Button == mbLeft)
     Screen->Cursor = crCross;
}
//---------------------------------------------------------------------------

void __fastcall TChronForm::Chart1Zoom(TObject *Sender)
{
   cxButton4->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TChronForm::cxButton4Click(TObject *Sender)
{
   Chart1->UndoZoom();
   cxButton4->Enabled = false;
}
//---------------------------------------------------------------------------

// Results button
void __fastcall TChronForm::cxButton5Click(TObject *Sender)
{
   UnicodeString Text;
   WideString Format;

   TAgeModelResultsForm *ResultsForm = new TAgeModelResultsForm(this);
   if (RadioGroup1->ItemIndex == 1) {  // polynomial
     ResultsForm->Memo1->Lines->Add("Y = Age");
     if (pFixYIntercept && zero_adjust != 0.0)
       Text = "X = Depth - " + FloatToStr(zero_adjust);
     else
       Text = "X = Depth";
     ResultsForm->Memo1->Lines->Add(Text);
     Text = "Y = ";
     if (Coefs[0] != 0.0)
       Text += (FloatToStr(Coefs[0]) + " + ");
     Text += (FloatToStr(Coefs[1]) + "*X");
     for (unsigned int i=2; i<Coefs.size(); i++) {
       if (Coefs[i] > 0.0)
         Text +=  " + ";
       else
         Text +=  " - ";
       Text += (FloatToStr(fabsl(Coefs[i])) + "*X" + "^" + IntToStr((int)i));
       }
     ResultsForm->Memo1->Lines->Add(Text);
     }
   else
     ResultsForm->Memo1->Height = 0;

   int ChronIndex = ComboBox1->ItemIndex;
   CHRONDATA *Y = (CHRONDATA*)Chrons->Items[ChronIndex];

   int dec = ResultsForm->cxSpinEdit1->Value;
   Format = "0.";
   for (int i=0; i<dec; i++)
     Format += "0";

   if (Depths.size() == Y->SampleAges.size()) {
     ResultsForm->ProfGrid1->RowCount = Depths.size() + 1;
     for (unsigned int i=0; i<Depths.size(); i++) {
       ResultsForm->ProfGrid1->Cells[1][i+1]->Value = Depths[i];
       double y = Y->SampleAges[i].Age;
       if (!IsNan(y)) {
         ResultsForm->ProfGrid1->Cells[2][i+1]->Format = Format;
         ResultsForm->ProfGrid1->Cells[2][i+1]->Value = y;
         }
       }
     }

   ResultsForm->ShowModal();
   delete ResultsForm;
}
//---------------------------------------------------------------------------

void __fastcall TChronForm::CheckBox2Click(TObject *Sender)
{
   if (EditChange) {
     CheckBoxChange = false;
     LabeledEdit3->Text = "";
     MinDepthLimit = NaN;
     CheckBoxChange = true;
     }
}
//---------------------------------------------------------------------------

void __fastcall TChronForm::CheckBox3Click(TObject *Sender)
{
   if (EditChange) {
     CheckBoxChange = false;
     LabeledEdit4->Text = "";
     MaxDepthLimit = NaN;
     CheckBoxChange = true;
     }
}
//---------------------------------------------------------------------------

void __fastcall TChronForm::LabeledEdit3Change(TObject *Sender)
{
   if (CheckBoxChange) {
     EditChange = false;
     CheckBox2->Checked = false;
     EditChange = true;
     }
}
//---------------------------------------------------------------------------

void __fastcall TChronForm::LabeledEdit4Change(TObject *Sender)
{
   if (CheckBoxChange) {
     EditChange = false;
     CheckBox3->Checked = false;
     EditChange = true;
     }
}
//---------------------------------------------------------------------------

// minimum depth value for age model
void __fastcall TChronForm::LabeledEdit3Exit(TObject *Sender)
{
   double Value, MinControlDepth, MaxControlDepth;

   if (LabeledEdit3->Text.IsEmpty())
     MinDepthLimit = NaN;
   else {
     if (TryStrToFloat(LabeledEdit3->Text, Value)) {
       int ChronIndex = ComboBox1->ItemIndex;
       AGEMODELGRAPH* AgeModel = (AGEMODELGRAPH*)AgeModelList->Items[ChronIndex];
       AgeModel->GetDepthMinMax(MinControlDepth, MaxControlDepth);

       if (RadioGroup1->ItemIndex == 2) {  // cubic spline
         if (Value < MinControlDepth) {
           MessageDlg("Minimum depth limit cannot be less than minimum depth of chronology controls.\nReset minimum limit to "
                      + FloatToStr(MinControlDepth) + ".", mtWarning, TMsgDlgButtons() << mbOK, 0);
           Value = MinControlDepth;
           LabeledEdit3->Text = FloatToStr(Value);
           }
         }
       else {
         if (MinControlDepth <= Depths.front() && Value < MinControlDepth) {
           MessageDlg("Minimum depth limit cannot be less than minimum depth of chronology controls.\nReset minimum limit to "
                      + FloatToStr(MinControlDepth) + ".", mtWarning, TMsgDlgButtons() << mbOK, 0);
           Value = MinControlDepth;
           LabeledEdit3->Text = FloatToStr(Value);
           }
         else if (Depths.front() < MinControlDepth && Value < Depths.front()) {
           MessageDlg("Minimum depth limit cannot be less than minimum sample depth.\nReset minimum limit to "
                      + FloatToStr(Depths.front()) + ".", mtWarning, TMsgDlgButtons() << mbOK, 0);
           Value = Depths.front();
           LabeledEdit3->Text = FloatToStr(Value);
           }
         }
       MinDepthLimit = Value;
       }
     else {
       MinDepthLimit = NaN;
       MessageDlg("Invalid input value. Must be numerical value.", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
       LabeledEdit3->Text = "";
       }
     }
}
//---------------------------------------------------------------------------

// maximum depth value for age model
void __fastcall TChronForm::LabeledEdit4Exit(TObject *Sender)
{
   double Value, MinControlDepth, MaxControlDepth;

   if (LabeledEdit4->Text.IsEmpty())
     MaxDepthLimit = NaN;
   else {
     if (TryStrToFloat(LabeledEdit4->Text, Value)) {
       int ChronIndex = ComboBox1->ItemIndex;
       AGEMODELGRAPH* AgeModel = (AGEMODELGRAPH*)AgeModelList->Items[ChronIndex];
       AgeModel->GetDepthMinMax(MinControlDepth, MaxControlDepth);

       if (RadioGroup1->ItemIndex == 2) {  // cubic spline
         if (Value > MaxControlDepth) {
           MessageDlg("Maximum depth limit cannot be greater than maximum depth of chronology controls.\nReset maximum limit to "
                      + FloatToStr(MaxControlDepth) + ".", mtWarning, TMsgDlgButtons() << mbOK, 0);
           Value = MaxControlDepth;
           LabeledEdit4->Text = FloatToStr(Value);
           }
         }
       else {
         if (MaxControlDepth >= Depths.back() && Value > MaxControlDepth) {
           MessageDlg("Maximum depth limit cannot be greater than maximum depth of chronology controls.\nReset maximum limit to "
                      + FloatToStr(MaxControlDepth) + ".", mtWarning, TMsgDlgButtons() << mbOK, 0);
           Value = MaxControlDepth;
           LabeledEdit4->Text = FloatToStr(Value);
           }
         else if (Depths.back() > MaxControlDepth && Value > Depths.back()) {
           MessageDlg("Maximum depth limit cannot be greater than maximum sample depth.\nReset maximum limit to "
                      + FloatToStr(Depths.back()) + ".", mtWarning, TMsgDlgButtons() << mbOK, 0);
           Value = Depths.back();
           LabeledEdit4->Text = FloatToStr(Value);
           }
         }
       MaxDepthLimit = Value;
       }
     else {
       MaxDepthLimit = NaN;
	   MessageDlg("Invalid input value. Must be numerical value.", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
       LabeledEdit4->Text = "";
       }
     }
}
//---------------------------------------------------------------------------

void TChronForm::NewAgeModel(CHRONDATA* Y)
{
   Y->NewAges = true;
   cxButton1->Enabled = true;
   cxButton5->Enabled = true;
}
//---------------------------------------------------------------------------

// save to spreadsheet
void __fastcall TChronForm::cxButton1Click(TObject *Sender)
{
   int ChronIndex = ComboBox1->ItemIndex;
   CHRONDATA *ChronData = (CHRONDATA*)Chrons->Items[ChronIndex];

   if (ChronData->NewAges) {
	 Screen->Cursor = crHourGlass;
	 SaveToWorksheet(SSForm->ProfGrid1, ChronData);
	 if (SSForm->ProfGrid2)  // percents worksheet
	   SaveToWorksheet(SSForm->ProfGrid2, ChronData);
	 Screen->Cursor = crDefault;
	 Saved = true;
	 MessageDlg(ComboBox1->Text + " saved to spreadsheet.", mtInformation,
	   TMsgDlgButtons() << mbOK, 0);
	 }
}
//---------------------------------------------------------------------------

void TChronForm::SaveToWorksheet(TProfGrid* ProfGrid, CHRONDATA* ChronData)
{
   int row, nrows, start, ChronNo;
   bool found = false;
   UnicodeString VarCode;
   Variant Value1, Value2;

   ProfGrid->DisableControls();
   ProfGrid->SpreadsheetEnabled = false;

   row = -1;
   if (ProfGrid == SSForm->ProfGrid1 && ChronData->Row > 2) {    // ProfGrid1
     row = ChronData->Row;
     found = true;
     }
   else if (ProfGrid != SSForm->ProfGrid1) {
     int col1 = SSForm->AbsHeaderColCount(SSForm->ProfGrid1);
     int col2 = SSForm->AbsHeaderColCount(ProfGrid);
     int ncols = SSForm->AbsContentColCount(SSForm->ProfGrid1);
     for (int j1=col1, j2=col2; j1<=ncols; j1++, j2++) {
	   Value1 = SSForm->ProfGrid1->AbsoluteCells[j1][1]->Value;
       Value2 = ProfGrid->AbsoluteCells[j2][1]->Value;
       if (Value1 != Value2) {
         UnicodeString Caption;
         map<TcxTabSheet*, TProfGrid*>::iterator begin = SSForm->Workbook->Sheets.begin();
         map<TcxTabSheet*, TProfGrid*>::iterator end = SSForm->Workbook->Sheets.end();
         map<TcxTabSheet*, TProfGrid*>::iterator itr;
         for (itr=begin; itr != end; itr++) {
           if (ProfGrid == (*itr).second) {
             TcxTabSheet* TabSheet = (*itr).first;
             Caption = TabSheet->Caption;
             break;
             }
           }
		 UnicodeString msg = "Ages not written to " + Caption +
           " worksheet because depths differ from Data worksheet.";
         MessageDlg(msg, mtWarning, TMsgDlgButtons() << mbOK, 0);
         ProfGrid->SpreadsheetEnabled = true;
         ProfGrid->EnableControls();
         return;
         }
       }

     nrows = SSForm->AbsContentRowCount(ProfGrid);
     start = SSForm->AbsHeaderRowCount(ProfGrid);
     for (int irow=start; irow<=nrows; irow++) {
       VarCode = ProfGrid->AbsoluteCells[1][irow]->Text;
       if (VarCode.SubString(1,6).CompareIC("#Chron") == 0) {
         row = irow;
         try {
             ChronNo = StrToInt(VarCode.SubString(7, VarCode.Length()-6));
             }
         catch ( ... ) {
             ChronNo = -1;
             }
         if (ChronNo == ChronData->ChronNumber) {
           found = true;
           break;
           }
         }
       }
     }

   if (row == -1) {    // Chron doesn't exist in worksheet
     nrows = SSForm->AbsContentRowCount(ProfGrid);
     start = SSForm->AbsHeaderRowCount(ProfGrid);
     for (int irow=start; irow<=nrows; irow++) {
       VarCode = ProfGrid->AbsoluteCells[1][irow]->Text;
       if (VarCode.SubString(1,6).CompareIC("#Chron") == 0)
         row = irow;
       }
     }

   if (!found) {
     if (row > -1)
       row++;
     else
       row = start;
     ProfGrid->InsertRow(row);
     ProfGrid->AbsoluteCells[1][row]->Value =
       WideString("#Chron" + IntToStr(ChronData->ChronNumber));
     }

   ChronData->ChronName = LabeledEdit1->Text;
   ProfGrid->AbsoluteCells[2][row]->Value = "Sample age (" + ChronData->ChronName + ")";
   //ProfGrid->AbsoluteCells[4][row]->Value = ChronData->AgeUnits;
   // use short name for age units
   ProfGrid->AbsoluteCells[4][row]->Value = SSForm->AgeUnits[ChronData->AgeUnits];
   for (int i=0; i<SSForm->AgeModelList->Count; i++) {
     AGEMODEL* AgeModel = SSForm->AgeModelList->AgeModels[i];
     if (AgeModel->ChronNumber == ChronData->ChronNumber) {
       SSForm->cxGrid3TableView1->BeginUpdate();
       AgeModel->ChronologyName = ChronData->ChronName;
       AgeModel->AgeModel = LabeledEdit2->Text;
       SSForm->cxGrid3TableView1->EndUpdate();
       break;
       }
     }

   int ndec = 1;
   int col_beg = ProfGrid->FixedCols;
   int col_end = ProfGrid->ColCount-1;
   while (col_end > 0 && ProfGrid->ColumnIsEmpty(col_end))
     col_end--;

   if (col_end >= col_beg) {
     if (CheckBox1->State == cbChecked) {
       ndec = cxSpinEdit1->Value;
       if (ndec > 0) ndec *= -1;
       }
     for (int col=col_beg, j=0; col<=col_end; col++, j++) {
       double Age = ChronData->SampleAges[j].Age;
       if (IsNan(Age)) {
         if (CheckBox4->Checked) {
           ProfGrid->Cells[col][row]->Value = Variant::Empty();
           }
         }
       else {
         if (ndec == 1)
           ProfGrid->Cells[col][row]->Value = Age;
         else {
           if (Age - Floor(Age) == 0.0)
             ProfGrid->Cells[col][row]->Value = Age;
           else
             ProfGrid->Cells[col][row]->Value = SimpleRoundTo(Age, ndec);
           }
         }
       }
     }
   ProfGrid->SpreadsheetEnabled = true;
   ProfGrid->EnableControls();
}
//---------------------------------------------------------------------------


