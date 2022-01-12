//---------------------------------------------------------------------------

#include <vcl.h>
#include <algorithm>
#include <iterator>
#include "pch.h"
#include <Filectrl.hpp>
#pragma hdrstop

#include "TIConFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "ta_struc.h"
#include "coniss.h"
#ifndef TGUtilsH
#include "TGUtils.h"
#endif

TConissForm *ConissForm;


//---------------------------------------------------------------------------
__fastcall TConissForm::TConissForm(TComponent* Owner)
        : TForm(Owner)
{
   TSSForm = (TTilSpreadSheetForm*)Owner;
}
//---------------------------------------------------------------------------

void __fastcall TConissForm::FormCreate(TObject *Sender)
{
   UnicodeString Path = ExtractFilePath(TSSForm->TilFileName);
   UnicodeString Name = ExtractFileName(TSSForm->TilFileName);
   Name.SetLength(Name.Pos(".") - 1);
   OutputFileName = Path + Name;
   Edit2->Text = Path + Name + ".dgx";
}
//---------------------------------------------------------------------------

void __fastcall TConissForm::SpeedButton2Click(TObject *Sender)
{
   OpenDialog1->Filter = "Tilia dendrogram files (*.dgx)|*.dgx";
   OpenDialog1->FileName = Edit2->Text;
   if (OpenDialog1->Execute())
     Edit2->Text = OpenDialog1->FileName;
}
//---------------------------------------------------------------------------

void __fastcall TConissForm::RadioGroup1Click(TObject *Sender)
{
   switch (RadioGroup1->ItemIndex) {
     case 0: CheckBox1->Enabled = true; break;
     case 1:
     case 2: CheckBox1->Enabled = false; break;
     }
}
//---------------------------------------------------------------------------

// Run Analysis
void __fastcall TConissForm::Button1Click(TObject *Sender)
{
  UnicodeString FileName;
  UnicodeString FileExt;
  UnicodeString Temp;

  FileName = ExtractFileName(Edit2->Text);
  if (FileName.IsEmpty()) {
	MessageDlg("No dgx file designated", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
    return;
    }
  Temp = ExtractFileExt(Edit2->Text);
  FileExt = Temp.LowerCase();

  if (FileExt.IsEmpty())
    Edit2->Text = Edit2->Text + ".dgx";
  else if (FileExt != ".dgx") {
    UnicodeString msg = "Extension " + FileExt + " not valid for .dgx file";
    MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
    return;
    }

  int rv = mrOk;
  if (RadioGroup3->ItemIndex == 1) {
    rv = MessageDlg("Unconstrained analysis will reorder sample numbers in CONISS worksheet.\nSamples should have names to identify them.",
         mtInformation, TMsgDlgButtons() << mbOK << mbCancel << mbAbort, 0);
    }

  if (rv == mrOk) {
    CONISS coniss(TSSForm, OutputFileName, Edit2->Text, RadioGroup1->ItemIndex,
                  CheckBox1->Checked, RadioGroup2->ItemIndex,
                  RadioGroup3->ItemIndex, this);
    if (coniss.ReadData()) {
      coniss.run();
      if (RadioGroup3->ItemIndex == 1)  // if unconstrained, get copy of order
        order = coniss.nord;
      }
    else
      Close();
    }
  else if (rv == mrAbort)
    Close();  
}
//---------------------------------------------------------------------------

bool TConissForm::Unconstrained(void)
{
   return (bool)RadioGroup3->ItemIndex;
}
//---------------------------------------------------------------------------

CONISS::CONISS(TTilSpreadSheetForm* ssform, UnicodeString outfile, UnicodeString dfile,
               int DataType, bool prp, int trans, int unconstrained, TConissForm* cf)
{
   TSSForm = ssform;
   OutputFileName = outfile;
   ConissForm = cf;

   DGXFile = dfile;

   counts = false;
   perc = false;
   prop = false;
   switch (DataType) {
     case 0:
       counts = true;
       prop = prp;
       break;
     case 1:
       perc = true;
       prop = true;
       break;
     case 2:
       prop = true;
       break;
     }

   srt = false;
   stand = false;
   norm = false;
   switch (trans) {
     case 0: srt = true; break;
     case 1: norm = true; break;
     case 2: stand = true; break;
     }

   con = (!unconstrained);
}
//---------------------------------------------------------------------------

bool CONISS::ReadData(void)
{
   int len, errors;
   double sum, x;
   unsigned long maxl, maxt, nelem, size_dist;
   UnicodeString msg;
   Variant Value;

   ProfGrid = NULL;
   for (int i=0; i<TSSForm->cxPageControl1->PageCount; i++) {
     TcxTabSheet* TabSheet = TSSForm->cxPageControl1->Pages[i];
     if (TabSheet->Caption.SubString(1,6) == "CONISS") {
       ProfGrid = TSSForm->Workbook->Sheets[TabSheet];
       break;
       }
     }
   if (ProfGrid == NULL) {
     msg = "CONISS worksheet not found";
     MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
     return false;
     }

   int ncols = TSSForm->AbsContentColCount(ProfGrid);
   int nrows = TSSForm->AbsContentRowCount(ProfGrid);
   int hcols = TSSForm->AbsHeaderColCount(ProfGrid) - 1;
   int hrows = TSSForm->AbsHeaderRowCount(ProfGrid) - 1;
   nlevs = ncols - hcols;
   nvars = nrows - hrows;

   maxl = nlevs;
   maxt = nvars;
   nelem = maxl*maxt;
   size_dist = (maxl*(maxl-1))/2;

   dist_array.assign(size_dist, 0.0L);
   data_array.assign(nelem, 0.0);

   for (int i=hrows+1; i<=nrows; i++) {
	 UnicodeString VarCode = ProfGrid->AbsoluteCells[1][i]->Value;
     if (VarCode.SubString(1,1) == "#") {
       msg = "Code <" + VarCode + "> in row " + IntToStr(i) +
             " ususally not appropriate in a cluster analysis.\nAbort analysis?";
       if (MessageDlg(msg, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes)
         return false;
       }
     }

   for (int col=hcols+1, j=0; col<=ncols; col++, j++) {   // samples
     x = ProfGrid->AbsoluteCells[col][1]->Value;
     levels.push_back(x);
     }

   for (int row=hrows+1, i=0; row<=nrows; row++, i++) {
     for (int col=hcols+1, j=0; col<=ncols; col++, j++) {
       Value = ProfGrid->AbsoluteCells[col][row]->Value;
       if (Value.Type() != varDouble) {
         msg = "Non-numerical value in cell " + ProfGrid->AbsoluteCells[col][row]->A1Name +
               ". Analysis aborted.";
		 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
         return false;
         }
       x = (double)Value;
       if (x < 0.0) {
         msg = "Negative number in cell " + ProfGrid->AbsoluteCells[col][row]->A1Name +
               ". Analysis aborted.";
         MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
         return false;
         }
       data_array[nlevs*i + j] = x;
       }
     }

  errors = 0;
  for (int j=0; j<nlevs; j++) {
    sum = 0.0;
    for (int i=0; i<nvars; i++)
      sum += data_array[nlevs*i + j];
    if (sum == 0.0) {
      UnicodeString msg = "No data in column " +
                       ProfGrid->AbsoluteCols[j+hcols+1]->A1Name +
                       ". Analysis aborted.";
	  MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
      if (++errors == 10) break;
      }
    }
  if (errors) {
    UnicodeString msg = "Errors in worksheet. Analysis aborted.";
    MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
    return false;
    }
  return true;
}
//---------------------------------------------------------------------------

void CONISS::run(void)
{
  int i, j, k;
  unsigned long id;
  long double sum, xlevs, xlevs1, sx, sx2, xij, xbar, sd, sumsq;
  long double dsqd, xijk;
  UnicodeString Line;

  ConissOutput = new TCONISSOutput(ConissForm);
  ConissOutput->OutputFileName = OutputFileName;
  ConissOutput->Show();

  Screen->Cursor = crHourGlass;
  FormatSettings.ShortDateFormat = "d mmm yyyy";
  Line = "Tilia Program CONISS     " + DateToStr(Date()) + "  " +
         TimeToStr(Time());
  ConissOutput->RichEdit1->Lines->Add(Line);
  Line = "Number of samples = ";
  Line.cat_printf(L"%d", nlevs);
  ConissOutput->RichEdit1->Lines->Add(Line);
  Line = "Number of variables = ";
  Line.cat_printf(L"%d", nvars);
  ConissOutput->RichEdit1->Lines->Add(Line);

  for (i=0; i<nlevs; i++)
    name.push_back(i);
  if (prop) {          // convert data to proportions
    if (counts) {
      for (j=0; j<nlevs; j++) {
        sum = 0.0;
	for (i=0; i<nvars; i++)
          sum += data_array[nlevs*i + j];
	for (i=0; i<nvars; i++)
          data_array[nlevs*i + j] /= sum;
	}
      ConissOutput->RichEdit1->Lines->Add("Data converted to proportions");
      }
    else if (perc) {
      for (j=0; j<nlevs; j++)
        for (i=0; i<nvars; i++)
          data_array[nlevs*i + j] *= 0.01;
      ConissOutput->RichEdit1->Lines->Add("Data converted to proportions");
      }
    }

  if (srt) {
    for (j=0; j<nlevs; j++)
      for (i=0; i<nvars; i++)
        data_array[nlevs*i + j] = sqrtl(data_array[nlevs*i + j]);
    ConissOutput->RichEdit1->Lines->Add("Square root transformation");
    if (prop)
      ConissOutput->RichEdit1->Lines->Add("Dissimilarity coefficient is Edwards and Cavalli-Sforza's chord distance");
    else
      ConissOutput->RichEdit1->Lines->Add("Dissimilarity coefficient is Euclidian distance");
    }
  else if (stand) {
    xlevs = (float)nlevs;
    xlevs1 = xlevs-1.0;
    for (i=0; i<nvars; i++) {
      sx = 0.0;
      sx2 = 0.0;
      for (j=0; j<nlevs; j++) {
        xij = data_array[nlevs*i + j];
        sx += xij;
        sx2 += (xij*xij);
        }
      if (sx > 0.0) {
        xbar = sx/xlevs;
        sumsq = sx2-sx*sx/xlevs;
        if (sumsq > 0.0) {
          sd = sqrtl(sumsq/xlevs1);
          for (j=0; j<nlevs; j++)
            data_array[nlevs*i + j] = (data_array[nlevs*i + j] - xbar)/sd;
          }
        else
          for (j=0; j<nlevs; j++)
            data_array[nlevs*i + j] = 0.0;
        }
      }
    ConissOutput->RichEdit1->Lines->Add("Variables standardized to mean 0, standard deviation 1");
    ConissOutput->RichEdit1->Lines->Add("Dissimilarity coefficient is standardized Euclidian distance");
    }
  else if (norm) {
    for (j=0; j<nlevs; j++) {
      sx2 = 0.0;
      for (i=0; i<nvars; i++) {
        xij = data_array[nlevs*i + j];
	sx2 += (xij*xij);
	}
      sx = sqrtl(sx2);
      for (i=0; i<nvars; i++)
        data_array[nlevs*i + j] /= sx;
      }
    ConissOutput->RichEdit1->Lines->Add("Sample vectors normalized to length 1");
    ConissOutput->RichEdit1->Lines->Add("Dissimilarity coefficient is Orloci's chord distance");
    }
  else  {
    ConissOutput->RichEdit1->Lines->Add("No data transformation");
    ConissOutput->RichEdit1->Lines->Add("Dissimilarity coefficient is Euclidian distance");
    }

  id = -1;
  for (i=1; i<nlevs; i++) {
    for (j=0; j<i; j++) {
      dsqd = 0.0;
      for (k=0; k<nvars; k++) {
        xijk = (long double)(data_array[nlevs*k + i]) -
               (long double)(data_array[nlevs*k + j]);
        dsqd += (xijk*xijk);
        }
      id++;
	  dist_array[id] = dsqd;
      }
    }

  if (con)
    constrained_cluster_analysis();
  else
    unconstrained_cluster_analysis();

  ConissOutput->RichEdit1->Lines->Add(EmptyStr);
  ConissOutput->RichEdit1->Lines->Add(EmptyStr);
  ConissOutput->RichEdit1->Lines->Add("Sample numbers");
  if (con) {
    for (i=0; i<nlevs; i++) {
	  Line.printf(L"%5d%10.7g", i+1, levels[i]);
      ConissOutput->RichEdit1->Lines->Add(Line);
      }
    }
  else {
    for (i=1; i<=nlevs; i++) {
	  Line.printf(L"%5d%10d", i, i);
      ConissOutput->RichEdit1->Lines->Add(Line);
      }
    }

  write_dgx_file();
  Screen->Cursor = crDefault;
}
//---------------------------------------------------------------------------

void CONISS::constrained_cluster_analysis(void)
{
  int iter;
  unsigned long r, msiz, n, namp, namq;
  unsigned long i, j, id, ij, i1j, ip, iq, ir;
  long double e, de;
  UnicodeString Iteration;
  DISPERSION ES;

  // Initialize arrays and variables

  nclus.assign(nlevs, 1);
  ess.assign(nlevs, 0.0);
  msiz = nlevs-1;
  e = 0.0;

  // Begin clustering

  for (iter=0; iter<nlevs-1; iter++) {
    // Find most similar clusters
    dshort = dist_array[0];
    p = 1;
    id = 1;
    for (n=2; n<=msiz; n++) {
      id +=n;
      if (dist_array[id-1] < dshort) {
	dshort = dist_array[id-1];
	p = n;
        }
      }
    q = p+1;
    namp = name[p-1];
    namq = name[q-1];
    namep.push_back(namp);
    nameq.push_back(namq);
    np = nclus[namp];
    nq = nclus[namq];

    // Calculate merge data

    de = 0.5*dshort;
    e += de;
    ess[namp] += (ess[namq] + de);
    ES.Increase = de;
    ES.Total = e;
    ES.Within = ess[namp];
    ES.MeanWithin = ess[namp]/(long double)(np+nq);
    es.push_back(ES);

    // Update distance matrix

    ip = (p-1)*(p-2)/2;
    iq = (q-1)*(q-2)/2;
    for (j=1; j<=p-1; j++) {
      id = ip+j;
      dist_array[id-1] = update(j);
      for (i=q; i<=msiz; i++) {
        ij = j+(i-1)*(i-2)/2;
        i1j = ij+i-1;
        dist_array[ij-1] = dist_array[i1j-1];
        }
      }
    ir = iq-q+2;
    for (i=q; i<=msiz; i++) {
      ir = ir+i-2;
      id = ir+p;
      dist_array[id-1] = update(i+1);
      }
    for (j=q; j<=msiz-1; j++) {
      for (i=j+1; i<=msiz; i++) {
	ij = j+(i-1)*(i-2)/2;
	i1j = ij+i;
	dist_array[ij-1] = dist_array[i1j-1];
	}
      }
    vector<int>::iterator itr = name.begin() + (q-1);
    name.erase(itr);
    nclus[namp] = np+nq;
    msiz--;
    }

  ConissOutput->RichEdit1->Lines->Add(EmptyStr);
  ConissOutput->RichEdit1->Lines->Add(EmptyStr);
  ConissOutput->RichEdit1->Lines->Add("Constrained Incremental Sum of Squares Cluster Analysis");
  ConissOutput->RichEdit1->Lines->Add(EmptyStr);
  output_results();
}
//---------------------------------------------------------------------------

// carries out unconstrained cluster analysis
void CONISS::unconstrained_cluster_analysis(void)
{
  unsigned long msiz, iter, namp, namq, m;
  unsigned long i, j, id, ij, i1j, ip;
  long double e, de;
  DISPERSION ES;

  // Initialize arrays and variables

  nclus.assign(nlevs, 1);
  ess.assign(nlevs, 0.0);
  msiz = nlevs-1;
  e = 0.0;

  // Begin clustering
  for (iter=0; iter<(unsigned long)nlevs-1; iter++) {
    // Find most similar clusters
    dshort = dist_array[0];
    p = 1;
    q = 2;
    id = 1;
    for (i=3; i<=msiz+1; i++) {
      for (j=1; j<=i-1; j++) {
        id++;
        if (dist_array[id-1] < dshort) {
          dshort = dist_array[id-1];
          p = j;
          q = i;
          }
        }
      }
    namp = name[p-1];
    namq = name[q-1];
    namep.push_back(namp);
    nameq.push_back(namq);
    np = nclus[namp];
    nq = nclus[namq];

    // Calculate merge data

    de = 0.5*dshort;
    e += de;
    ess[namp] += (ess[namq] + de);
    ES.Increase = de;
    ES.Total = e;
    ES.Within = ess[namp];
    ES.MeanWithin = ess[namp]/(long double)(np+nq);
    es.push_back(ES);

    // Update distance matrix

    ip = (p-1)*(p-2)/2;
    for (j=1; j<=p-1; j++) {
      id = ip+j;
      dist_array[id-1] = update(j);
      for (i=q; i<=msiz; i++) {
        ij = j+(i-1)*(i-2)/2;
	i1j = ij+i-1;
	dist_array[ij-1] = dist_array[i1j-1];
	}
      }
    for (i=p+1; i<=q-1; i++) {
      id = p+(i-1)*(i-2)/2;
      dist_array[id-1] = update(i);
      }
    for (i=q; i<=msiz; i++) {
      id = p+(i-1)*(i-2)/2;
      dist_array[id-1] = update(i+1);
      }
    for (j=p+1; j<=q-1; j++) {
      for (i=q; i<=msiz; i++) {
	ij = j+(i-1)*(i-2)/2;
	i1j = ij+i-1;
	dist_array[ij-1] = dist_array[i1j-1];
	}
      }
    for (j=q; j<=msiz-1; j++) {
      for (i=j+1; i<=msiz; i++) {
	ij = j+(i-1)*(i-2)/2;
	i1j = ij+i;
	dist_array[ij-1] = dist_array[i1j-1];
	}
      }
    vector<int>::iterator itr = name.begin() + (q-1);
    name.erase(itr);
    nclus[namp] = np+nq;
    msiz--;
    }

  dendrogram_order();
  ConissOutput->RichEdit1->Lines->Add(EmptyStr);
  ConissOutput->RichEdit1->Lines->Add(EmptyStr);
  ConissOutput->RichEdit1->Lines->Add("Unconstrained Incremental Sum of Squares Cluster Analysis");
  ConissOutput->RichEdit1->Lines->Add(EmptyStr);
  output_results();
}
//---------------------------------------------------------------------------

// establishes order of samples on dendrogram for unconstrained analysis
void CONISS::dendrogram_order(void)
{
  int i, j, k, n, ik, jk, no, klast, ilk, jlk;
  bool repeat = false;
  vector<int> il;
  vector<int> jl;
  vector<int> last;
  vector<int> next;

  il.assign(nlevs, 0);
  jl.assign(nlevs, 0);
  last.assign(nlevs, 0);
  next.assign(nlevs, 0);
  nord.assign(nlevs, 0);

  n = nlevs-1;

  for (k=1; k<=n; k++) {
    ik = namep[k-1];
    jk = nameq[k-1];
    il[k-1] = last[ik];
    jl[k-1] = last[jk];
    last[ik] = k;
    next[il[k-1]] = k;
    next[jl[k-1]] = k;
    }
  next[n] = 0;
  k = 1;
  no = 0;

  while (1) {
    ik = namep[k-1];
    jk = nameq[k-1];
    if (il[k-1] == 0) {
      no++;
      nord[no-1] = ik;
      }
    if (jl[k-1] == 0) {
      no++;
      nord[no-1] = jk;
      }
    klast = k;
    k = next[k];
    if (k <= n && k >= 1) {
      if (il[k-1] <= 0) {
        il[k-1] = -il[k-1];
        continue;
        }
      if (jl[k-1] <= 0) {
        jl[k-1] = -jl[k-1];
        continue;
        }
      if (il[k-1] != klast) {
        jl[k-1] = -jl[k-1];
        k = il[k-1];
        }
      else {
        il[k-1] = -il[k-1];
        k = jl[k-1];
        }
      while (1) {
        ilk = il[k-1];
        jlk = jl[k-1];
        if (ilk < jlk)
          k = (ilk == 0) ? jlk : ilk;
        else if (ilk > jlk)
          k = (jlk == 0) ? ilk : jlk;
        else {
          repeat = true;
          break;
          }
        }
      }
    if (repeat)
      repeat = false;
    else
      break;
    }
  ConissOutput->RichEdit1->Lines->Add(EmptyStr);
  ConissOutput->RichEdit1->Lines->Add(EmptyStr);
  ConissOutput->RichEdit1->Lines->Add("Order of samples on dendrogram");
  ConissOutput->RichEdit1->Lines->Add(EmptyStr);
  j = 1;
  UnicodeString Line;
  for (i=1; i<=no; i++) {
    if (j == 1)
	  Line.printf(L"%4d", nord[i-1]+1);
	else
      Line.cat_printf(L"%4d", nord[i-1]+1);
    if (j == 20) {
      ConissOutput->RichEdit1->Lines->Add(Line);
      j = 1;
      }
    else
      j++;
    }
  if (j > 1)
    ConissOutput->RichEdit1->Lines->Add(Line);
}
//---------------------------------------------------------------------------

// solves the update equation
long double CONISS::update(unsigned long r)
{
  long double xr, xp, xq, up;
  xr = (long double)nclus[name[r-1]];
  xp = (long double)np;
  xq = (long double)nq;
  up = ((xr+xp)*d2(r,p)+(xr+xq)*d2(r,q)-xr*dshort)/(xr+xp+xq);
  return(up);
}
//---------------------------------------------------------------------------

// locates value in lower half matrix
long double CONISS::d2(unsigned long i, unsigned long j)
{
  unsigned long id;
  if (i > j)
    id = (i-1)*(i-2)/2 + j;
  else
    id = (j-1)*(j-2)/2 + i;
  return(dist_array[id-1]);
}
//---------------------------------------------------------------------------

// outputs results to file out1
void CONISS::output_results(void)
{
  int np, nq;
  vector<int>::iterator itr;
  UnicodeString Line;

  ConissOutput->RichEdit1->Lines->Add("                                                                Mean");
  ConissOutput->RichEdit1->Lines->Add("                                                 Within-        within-");
  ConissOutput->RichEdit1->Lines->Add("        Clusters   Increase in    Total          cluster        cluster");
  ConissOutput->RichEdit1->Lines->Add("Stage   merged     dispersion     dispersion     dispersion     dispersion");
  for (int i=0; i<nlevs-1; i++) {
    if (con) {
      np = namep[i]+1;
      nq = nameq[i]+1;
      }
    else {
      itr = find(nord.begin(), nord.end(), namep[i]);
      np = distance(nord.begin(), itr) + 1;
      itr = find(nord.begin(), nord.end(), nameq[i]);
      nq = distance(nord.begin(), itr) + 1;
      }
    Line.printf(L"%5d%5d%5d    %-15.7Lg%-15.7Lg%-15.7Lg%-15.7Lg",
      i+1, np, nq, es[i].Increase, es[i].Total, es[i].Within, es[i].MeanWithin);
    ConissOutput->RichEdit1->Lines->Add(Line);
    }
}
//---------------------------------------------------------------------------

bool CONISS::write_dgx_file(void)
{
  int i;
  int dp, dq;
  short s;
  float x;
  bool rv = true;
  UnicodeString ustr;
  vector<int>::iterator itr;

  WriteXML* xmlout = new WriteXML(DGXFile);

  try {
  try {
  xmlout->Declaration("1.0", "UTF-8", "yes");
  xmlout->DateTime();
  xmlout->BeginTag("CONISS");
  xmlout->Element("NumberOfLevels", nlevs);
  if (con)
	ustr = "Constrained";
  else
	ustr = "Unconstrained";
  xmlout->Element("AnalysisType", ustr);
  xmlout->BeginTag("Dendrogram");
  for (i=0; i<nlevs-1; i++) {
	xmlout->BeginTag("Cluster");
	if (con) {
	  xmlout->Element("Cluster1", namep[i]);
	  xmlout->Element("Cluster2", nameq[i]);
	  }
	else {
	  itr = find(nord.begin(), nord.end(), namep[i]);
	  dp = distance(nord.begin(), itr);
	  itr = find(nord.begin(), nord.end(), nameq[i]);
	  dq = distance(nord.begin(), itr);
	  xmlout->Element("Cluster1", dp);
	  xmlout->Element("Cluster2", dq);
	  }
	xmlout->Element("ISS", es[i].Increase);
	xmlout->Element("TSS", es[i].Total);
	xmlout->Element("WSS", es[i].Within);
	xmlout->Element("MSS", es[i].MeanWithin);
	xmlout->EndTag("Cluster");
	}
  xmlout->EndTag("Dendrogram");
  xmlout->BeginTag("Levels");
  if (con) {
	for (i=0; i<nlevs; i++)
	  xmlout->Element("Depth", levels[i]);
	}
  else {
	for (i=1; i<=nlevs; i++)
	  xmlout->Element("Depth", i);
	}
  xmlout->EndTag("Levels");
  xmlout->BeginTag("DendrogramOrder");
  for (i=0; i<nlevs; i++)
	xmlout->Element("DO", i);
  xmlout->EndTag("DendrogramOrder");
  xmlout->EndTag("CONISS");
  xmlout->Finish();
  }
  catch(Exception &e) {
	MessageDlg(e.Message, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	rv = false;
	}
  }
  __finally
	{
	delete xmlout;
	}

  return rv;
}
//---------------------------------------------------------------------------

