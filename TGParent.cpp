//---------------------------------------------------------------------------
// Note: Warning 8058 re. precompiled headers is disabled
#include <FileCtrl.hpp>
#include <vcl.h>
#include "pch.h"
#pragma hdrstop

#include "shlobj.h"
#include "TGParent.h"
#ifndef TIGlobalsH
#include "TIGlobals.h"
#endif
#ifndef TGraphicH
#include "TGraphic.h"
#endif
#ifndef TGUtilsH
#include "TGUtils.h"
#endif
#ifndef TGPrintH
#include "TGPrint.h"
#endif
#ifndef TGAboutH
#include "TGAbout.h"
#endif
#ifndef TISumsH
#include "TISums.h"
#endif
#ifndef TIErrFrmH
#include "TIErrFrm.h"
#endif
#ifndef TINtmDatH
#include "TINtmDat.h"
#endif
#include "TGSplash.h"
//#include "HtmlHelp.h"
#ifndef TGHelpH
#include "TGHelp.h"
#endif
#ifndef TNLoginH
#include "TNLogin.h"
#endif
#ifndef TINtmWebH
#include "TINtmWeb.h"
#endif
#ifndef TIGlobalsH
#include "TIGlobals.h"
#endif

#include "HTMLHelpViewer.hpp"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "HTMLHelpViewer"
//#pragma link "cdiroutl"
#pragma link "cxGraphics"
#pragma resource "*.dfm"

TParentForm *ParentForm;

// this prevents the custom cursor in the spreadsheet from appearing
LRESULT CALLBACK MouseProc(int nCode, WPARAM wParam, LPARAM lParam)
{
   if (ParentForm) {
     if (ParentForm->MainMenuClicked && wParam == WM_LBUTTONDOWN) {
       ParentForm->MainMenuClicked = false;
       //UnhookWindowsHookEx(ParentForm->HookID);
       }
     }
   return 0;
}
//---------------------------------------------------------------------------

__fastcall TParentForm::TParentForm(TComponent* Owner)
    : TForm(Owner)
{
   for (int i=0; i<33; i++) {
	 Graphics::TBitmap *bmp = new Graphics::TBitmap();
	 try
	   {
	   GKSImageList->GetBitmap(i, bmp);
	   GKSBitmaps.push_back(bmp);
	   }
	 catch (...)
	   {
		GKSBitmaps.push_back(bmp);
	   }
	 }
}
//---------------------------------------------------------------------------

void __fastcall TParentForm::FormCreate(TObject *Sender)
{
   //tiGlobals = new TIGLOBALS();
//#ifndef TSTESTING
//   TSServices1->Visible = false;
//#endif
#ifdef WHITMORE
   Whitmore1->Visible = true;
#endif

   if (tiLicense->Type() == verNEOTOMASTEWARD) {
	 Login = new NEOTOMALOGIN();
	 }
   else {
	 Login1->Visible = false;
	 WebServices1->Visible = false;
	 TSServices1->Visible = false;
	 }

   if (tiLicense->Type() == verFREE) {
	 ToolButtonSSGraphics->Visible = false;
	 ToolBarSpreadSheet->Width -= ToolButtonSSGraphics->Width;
	 }
   vector<TToolBar*> ToolBars;
   ToolBars.push_back(ToolBarFile);
   ToolBars.push_back(ToolBarHelp);
   ToolBars.push_back(ToolBarNeotoma);
   SetToolBars(ToolBars);

   ClientHeight = tiGlobals->ClientHeight;
   ClientWidth = tiGlobals->ClientWidth;

   CommandLineFileOpened = false;

   ZoomKey = false;
   IntlStrToDouble::SetDecimalSeparator();

   Screen->Cursors[crSelectCol] = LoadCursor(HInstance, L"SELECTCOL");
   Screen->Cursors[crSelectRow] = LoadCursor(HInstance, L"SELECTROW");

   MainMenuClicked = false;

   //HookID =
   //MouseHook pMouseProc = reinterpret_cast<MouseHook>(MouseProc);
   //SetWindowsHookEx(WH_MOUSE, pMouseProc, 0 ,GetCurrentThreadId());
}
//---------------------------------------------------------------------------

void TParentForm::SetToolBars(vector<TToolBar*>& ToolBars)
{
   ToolBarGraphics->Hide();
   ToolBarHelp->Hide();
   ToolBarZoomText->Hide();
   ToolBarZoomPlusMinus->Hide();
   ToolBarSpreadSheet->Hide();
   ToolBarNeotoma->Hide();

   ToolBars[0]->Top = 2;
   ToolBars[0]->Left = 11;
   for (unsigned int i=1; i<ToolBars.size(); i++) {
	 ToolBars[i]->Top = 2;
	 ToolBars[i]->Left = ToolBars[i-1]->Left + ToolBars[i-1]->Width + 13;
	 ToolBars[i]->Show();
	 }
}
//---------------------------------------------------------------------------

void __fastcall TParentForm::FormClose(TObject *Sender, TCloseAction &Action)
{
  //Help.CloseHTMLHelp();

  // close all child windows
  for (int i=0; i<MDIChildCount; i++) {
	AnsiString Name = MDIChildren[i]->Name;
	if (Name.SubString(1,9) == "TGDiagram") {
      TTGDiagram* TGDiagram = (TTGDiagram *)MDIChildren[i];
      TGDiagram->Close();
	  }
	else if (Name.SubString(1,14) == "TilSpreadSheet") {
	  TTilSpreadSheetForm* TSSForm = (TTilSpreadSheetForm*)MDIChildren[i];
	  TSSForm->Close();
	  }
    else if (Name == "ErrorListForm") {
      ErrorListForm = (TErrorListForm*)MDIChildren[i];
      ErrorListForm->Close();
      }
    }

  //for (int i=0; i<GKSBitmaps->Count; i++) [
  for (unsigned int i=0; i<GKSBitmaps.size(); i++) {
	//BrushBmp = (Graphics::TBitmap*)GKSBitmaps->Items[i];
	//delete BrushBmp;
	//GKSBitmaps->Items[i] = 0;
	delete GKSBitmaps[i];
	}
  //GKSBitmaps->Clear();
  //delete GKSBitmaps;

  tiGlobals->ClientHeight = ClientHeight;
  tiGlobals->ClientWidth = ClientWidth;

  delete Login;
  delete tiGlobals;
  //delete tiLicense;
}
//---------------------------------------------------------------------------

void __fastcall TParentForm::DrawMenuItem(UnicodeString Caption, TCanvas *ACanvas,
      TRect &ARect, bool Selected)
{
   TPoint CursorPos = Mouse->CursorPos;

   bool OnTop = false;
   if (CursorPos.x >= Left+ARect.Left &&
       CursorPos.x < Left+ARect.Right &&
       CursorPos.y >= Top+ARect.Top &&
       CursorPos.y < Top+ARect.Bottom)
         OnTop = true;

   // APoint is draw area
   if (Selected || OnTop) {
     Canvas->Brush->Color = clMenuHighlight;
     ACanvas->FillRect(ARect);
     ACanvas->Font->Color = clHighlightText;
     ACanvas->TextOut(ARect.Left+6, ARect.Top+2, Caption);
     }
   else {
     ACanvas->Brush->Color = clBtnFace;
     ACanvas->FillRect(ARect);
     ACanvas->Font->Color = clMenuText;
     ACanvas->TextOut(ARect.Left+6, ARect.Top+2, Caption);
     }
}
//---------------------------------------------------------------------------

bool TParentForm::ValidFileExt(UnicodeString& FileName, short* FileType)
{
   UnicodeString msg;
   UnicodeString FileExt = ExtractFileExt(FileName);

   if (FileExt.CompareIC(".tgf") == 0 || FileExt.CompareIC(".tgx") == 0 ) {
	 if (tiLicense->Type() == verFREE) {
	   msg = L"Free version of Tilia cannot open " + FileExt + L" file!";
	   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return false;
	   }
	 else {
	   *FileType = TGDIAGRAM;
	   return true;
	   }
	 }

   if (FileExt.CompareIC(".til") == 0 ||
	   FileExt.CompareIC(".tlx") == 0 ||
	   FileExt.CompareIC(".xls") == 0) {
		 *FileType = TILSPREADSHEET;
		 return true;
		}
   else {
		 msg = FileName + " is not a valid file.";
		 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 return false;
		}
}

//---------------------------------------------------------------------------

void TParentForm::PrintDiagram(void)
{
   TTGDiagram* TGDiagram = GetTGForm();
   if (PrintDialog1->Execute())
	 TGDiagram->Picture->PrintOut();
   TGDiagram->Repaint();
}
//---------------------------------------------------------------------------

void TParentForm::OpenTGDiagramWindow(DiagramParams& Params)
{
   if (MDIChildCount == 0) {
	 CurrentChildPos.x = 0;
	 CurrentChildPos.y = 0;
	 }
   else {
	 CurrentChildPos.x = ActiveMDIChild->Left;
	 CurrentChildPos.y = ActiveMDIChild->Top;
	 }

   TTGDiagram *TGDiagram = new TTGDiagram(this);
   if (!TGDiagram->InitializeDiagram(Params)) {
	 Screen->Cursor = crDefault;
	 TGDiagram->Close();
	 return;
	 }

   ZoomOutButton1->Enabled = (TGDiagram->Picture->CurrentZoom() > 1.0) ? true : false;

   if (Params.ProfGrid == NULL) {
	 if (TGDiagram->file_loaded)
	   tiGlobals->InitialDirectory = ExtractFilePath(TGDiagram->TGFileName);
	 else
	   TGDiagram->Close();
	 }

   TGDiagram->TGBoxes1->Checked = TGDiagram->Boxes;
   TGDiagram->make_diagram();
   TGDiagram->Picture->OutputGraphicObjects(DISPLAY, TGDiagram);

   Screen->Cursor = crDefault;

  /*
  if (MDIChildCount == 0) {
	CurrentChildPos.x = 0;
	CurrentChildPos.y = 0;
	}
  else {
	CurrentChildPos.x = ActiveMDIChild->Left;
	CurrentChildPos.y = ActiveMDIChild->Top;
	}

  TTGDiagram *TGDiagram = new TTGDiagram(this);
  if (!TGDiagram->InitializeDiagram(Params.FileName, Params.ProfGrid, Params.VarNames)) {
	Screen->Cursor = crDefault;
	TGDiagram->Close();
	return;
	}

  ZoomOutButton1->Enabled = (TGDiagram->Picture->CurrentZoom() > 1.0) ? true : false;

  TGDiagram->TGBoxes1->Checked = TGDiagram->Boxes;
  TGDiagram->make_diagram();
  TGDiagram->Picture->OutputGraphicObjects(DISPLAY, TGDiagram);

  Screen->Cursor = crDefault;
  */
}
//---------------------------------------------------------------------------

void TParentForm::OpenSpreadSheetWindow(UnicodeString& FileName)
{
  Screen->Cursor = crHourGlass;
  if (MDIChildCount == 0) {
    CurrentChildPos.x = 0;
    CurrentChildPos.y = 0;
    }
  else {
    CurrentChildPos.x = ActiveMDIChild->Left;
    CurrentChildPos.y = ActiveMDIChild->Top;
    }

  TilSpreadSheetForm = new TTilSpreadSheetForm(this);
  if (TilSpreadSheetForm->FatalError) {
	delete TilSpreadSheetForm;
	Screen->Cursor = crDefault;
	return;
	}

  if (TilSpreadSheetForm->LoadData(FileName)) {
	//tiGlobals->SetInitialDirectory(ExtractFilePath(FileName));
    tiGlobals->InitialDirectory = ExtractFilePath(FileName);
	ParentForm->StatusBar1->Panels->Items[0]->Text =
        MinimizeName(FileName, ParentForm->StatusBar1->Canvas,
          ParentForm->StatusBar1->Panels->Items[0]->Width);
    TTilSpreadSheetForm* TilSpreadSheetForm =
      (TTilSpreadSheetForm *)ParentForm->ActiveMDIChild;
    TilSpreadSheetForm->Caption =
      MinimizeName(FileName, TilSpreadSheetForm->Canvas, TilSpreadSheetForm->Width);
    Screen->Cursor = crDefault;
    }
}
//---------------------------------------------------------------------------

TTilSpreadSheetForm* __fastcall TParentForm::GetSSForm(void)
{
   AnsiString FormType;

   if (ActiveMDIChild)
     FormType = ActiveMDIChild->ClassType()->ClassName();
   if (FormType == "TTilSpreadSheetForm")
     return ((TTilSpreadSheetForm *)ParentForm->ActiveMDIChild);
   else
     return NULL;
}
//---------------------------------------------------------------------------

TTGDiagram* __fastcall TParentForm::GetTGForm(void)
{
   AnsiString FormType = ActiveMDIChild->ClassType()->ClassName();
   if (FormType == "TTGDiagram")
     return ((TTGDiagram *)ParentForm->ActiveMDIChild);
   else
     return NULL;
}
//---------------------------------------------------------------------------

void __fastcall TParentForm::Close1Click(TObject *Sender)
{
   CloseChild();
}
//---------------------------------------------------------------------------

void TParentForm::CloseChild(void)
{
  AnsiString FormType = ActiveMDIChild->ClassType()->ClassName();
  if (FormType == "TTGDiagram") {
    TTGDiagram* TGDiagram = (TTGDiagram *)ActiveMDIChild;
    if (TGDiagram)
      TGDiagram->Close();
    }
  else if (FormType == "TTilSpreadSheetForm") {
    TTilSpreadSheetForm* TilSpreadSheet = (TTilSpreadSheetForm*)ActiveMDIChild;
    if (TilSpreadSheet)
      TilSpreadSheet->Close();
    }
  else if (FormType == "TErrorListForm") {
    ErrorListForm = (TErrorListForm*)ActiveMDIChild;
    if (ErrorListForm)
      ErrorListForm->Close();
    }

  StatusBar1->Panels->Items[0]->Text = "";
  StatusBar1->Panels->Items[1]->Text = "";
  StatusBar1->Panels->Items[2]->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TParentForm::PrintClick(TObject *Sender)
{
   PrintDiagram();
}
//---------------------------------------------------------------------------

void __fastcall TParentForm::PrintOptions1Click(TObject *Sender)
{
   PrintForm = new TPrintForm(this);

   int result = PrintForm->ShowModal();
   if (result == mrOk) {
      //TTGDiagram* TGDiagram = (TTGDiagram *)ActiveMDIChild;
      TTGDiagram* TGDiagram = GetTGForm();
      PRINTOPTIONS *PrintOptions = &TGDiagram->Picture->PrintOptions;
      PrintOptions->Option = PrintForm->RadioGroup1->ItemIndex;
      PrintOptions->DiagramHeight = PrintForm->getDiagramHeight();
      PrintOptions->YaxisHeight = PrintForm->getYaxisHeight();
      PrintOptions->Units = PrintForm->RadioGroup2->ItemIndex;
      PrintOptions->Overlap = (double)PrintForm->getOverlap();
      PrintOptions->Orientation = PrintForm->RadioGroup3->ItemIndex;

      if (PrintOptions->Option == 2) {
        PrintOptions->Inches = PrintOptions->DiagramHeight;
        if (PrintOptions->Units == 1) PrintOptions->Inches /= 2.54;
        if (PrintOptions->DiagramHeight == 0)
          PrintOptions->Option = 0;
        }
      else if (PrintOptions->Option == 3) {
        PrintOptions->Inches = PrintOptions->YaxisHeight;
        if (PrintOptions->Units == 1) PrintOptions->Inches /= 2.54;
        if (PrintOptions->YaxisHeight == 0)
          PrintOptions->Option = 0;
        }

      if (PrintForm->PrintButtonClicked) {
        if (PrintDialog1->Execute()) {
          TGDiagram->Picture->PrintOut();
          TGDiagram->Picture->OutputGraphicObjects(DISPLAY, TGDiagram);
		  }
        }
   }

   delete PrintForm;
}
//---------------------------------------------------------------------------

void __fastcall TParentForm::FormActivate(TObject *Sender)
{
  short FileType;
  // UnicodeString FileName;
  DiagramParams Params;

  if (!CommandLineFileOpened && ParamCount() > 0) {
    if (FileExists(ParamStr(1))) {
	  Params.FileName = ParamStr(1);
	  if (ValidFileExt(Params.FileName, &FileType)) {
      // TODO: Eventually change this for Diagram or Spreadsheet file
        if (FileType == TGDIAGRAM || FileType == TILSPREADSHEET) {
          CommandLineFileOpened = true;
		  // OpenTGDiagramWindow(FileName);
		  OpenTGDiagramWindow(Params);
		  }
        }
      }
   }
}
//---------------------------------------------------------------------------

void __fastcall TParentForm::ZoomInButtonClick(TObject *Sender)
{
   double ZoomFactor;
   int idx;

   TTGDiagram* TGDiagram = GetTGForm();

   switch (TGDiagram->Picture->GetZoomIndex())
   {
   case 0:
     ZoomFactor = TGDiagram->Picture->GetToHeightZoom();
     if (ZoomFactor > 1.0)
       TGDiagram->Picture->Zoom(ZoomFactor, 1);
     else
       TGDiagram->Picture->Zoom(2.0, 3);
     ZoomOutButton1->Enabled = true;
     break;
   case 1:
     ZoomFactor = floor(TGDiagram->Picture->CurrentZoom())+1.0;
     if (ZoomFactor == 2.0)
       idx = 3;
     else if (ZoomFactor == 3.0)
       idx = 4;
     else if (ZoomFactor == 4.0)
       idx = 5;
     else if (ZoomFactor == 5.0)
       idx = 6;
     else if (ZoomFactor == 6.0)
       idx = 7;
     else
       idx = -1;
     TGDiagram->Picture->Zoom(ZoomFactor, idx);
     break;
   case 2:
     TGDiagram->Picture->Zoom(2.0, 3);
     break;
   case 3:
     TGDiagram->Picture->Zoom(3.0, 4);
     break;
   case 4:
     TGDiagram->Picture->Zoom(4.0, 5);
     break;
   case 5:
     TGDiagram->Picture->Zoom(5.0, 6);
     break;
   case 6:
     TGDiagram->Picture->Zoom(6.0, 7);
     break;
   case 7:
     TGDiagram->Picture->Zoom(7.0, -1);
     break;
   default:
     TGDiagram->Picture->Zoom(floor(TGDiagram->Picture->CurrentZoom())+1.0, -1);
     break;
   };

   ZoomComboBox->Text =  IntToStr(nint(100.0*TGDiagram->Picture->CurrentZoom())) + "%";

   if (!TGDiagram->ActiveSegment.IsEmpty()) {
     TGDiagram->ToolBar1->Hide();
     TGDiagram->Picture->ResetEditSegment();
     TGDiagram->ActiveSegment = "";
     }

   TGDiagram->Picture->OutputGraphicObjects(DISPLAY, TGDiagram);
}
//---------------------------------------------------------------------------

void __fastcall TParentForm::ZoomOutButtonClick(TObject *Sender)
{
   double ZoomFactor;
   int idx;

   //TTGDiagram* TGDiagram = (TTGDiagram *)ActiveMDIChild;
   TTGDiagram* TGDiagram = GetTGForm();
   double ToHeightZoom = TGDiagram->Picture->GetToHeightZoom();

   switch (TGDiagram->Picture->GetZoomIndex())
   {
   case 1:
     TGDiagram->Picture->Zoom(1.0, 0);
     break;
   case 2:
   case 3:
     if (TGDiagram->Picture->CurrentZoom() > ToHeightZoom)
       TGDiagram->Picture->Zoom(ToHeightZoom, 1);
     else
       TGDiagram->Picture->Zoom(1.0, 0);
     break;
   case 4:
     if (ToHeightZoom > 2.0)
       TGDiagram->Picture->Zoom(ToHeightZoom, 1);
     else
       TGDiagram->Picture->Zoom(2.0, 3);
     break;
   case 5:   // 400%
     if (ToHeightZoom > 3.0)
       TGDiagram->Picture->Zoom(ToHeightZoom, 1);
     else
       TGDiagram->Picture->Zoom(3.0, 4);
     break;
   case 6:   // 500%
     if (ToHeightZoom > 4.0)
       TGDiagram->Picture->Zoom(ToHeightZoom, 1);
     else
       TGDiagram->Picture->Zoom(4.0, 5);
     break;
   case 7:  // 6005
     if (ToHeightZoom > 5.0)
       TGDiagram->Picture->Zoom(ToHeightZoom, 1);
     else
       TGDiagram->Picture->Zoom(5.0, 6);
     break;
   default:
     ZoomFactor = floor(TGDiagram->Picture->CurrentZoom());
     if (TGDiagram->Picture->CurrentZoom() - ZoomFactor == 0.0)
       ZoomFactor -= 1.0;
     if (ToHeightZoom > ZoomFactor)
       TGDiagram->Picture->Zoom(ToHeightZoom, 1);
     else {
       if (ZoomFactor == 2.0)
         idx = 3;
       else if (ZoomFactor == 3.0)
         idx = 4;
       else if (ZoomFactor == 4.0)
         idx = 5;
       else if (ZoomFactor == 5.0)
         idx = 6;
       else if (ZoomFactor == 6.0)
         idx = 7;
       else
         idx = -1;
       //TGDiagram->Picture->Zoom(100.0*ZoomFactor, idx);
       TGDiagram->Picture->Zoom(ZoomFactor, idx);
       }
     break;
   };

   ZoomComboBox->Text =  IntToStr(nint(100.0*TGDiagram->Picture->CurrentZoom())) + "%";
   ZoomOutButton1->Enabled = (TGDiagram->Picture->CurrentZoom() > 1.0) ? true : false;

   if (!TGDiagram->ActiveSegment.IsEmpty()) {
     TGDiagram->ToolBar1->Hide();
     TGDiagram->Picture->ResetEditSegment();
     TGDiagram->ActiveSegment = "";
     }

   TGDiagram->Picture->OutputGraphicObjects(DISPLAY, TGDiagram);
}
//---------------------------------------------------------------------------

void __fastcall TParentForm::HideButtonClick(TObject *Sender)
{
  //TTGDiagram* TGDiagram = (TTGDiagram *)ActiveMDIChild;
  TTGDiagram* TGDiagram = GetTGForm();

  TGDiagram->ToolBar1->Hide();
  TGDiagram->Picture->ResetEditSegment();
  TGDiagram->ActiveSegment = "";
  HideButton1->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TParentForm::ZoomComboBoxChange(TObject *Sender)
{
  double ZoomFactor;
  //TTGDiagram* TGDiagram;
  
  if (!ZoomKey) {
    switch (ZoomComboBox->ItemIndex) {
      case 0:   // Fit
        ZoomFactor = 1.0;
        break;
      case 1:   // Height
        //TGDiagram = (TTGDiagram *)ParentForm->ActiveMDIChild;
        //TGDiagram = GetTGForm();
        //ZoomFactor = TGDiagram->Picture->GetToHeightZoom();
        ZoomFactor = GetTGForm()->Picture->GetToHeightZoom();
        break;
      case 2:
        ZoomFactor = 1.5;
        break;
      case 3:
        ZoomFactor = 2.0;
        break;
      case 4:
        ZoomFactor = 3.0;
        break;
      case 5:
        ZoomFactor = 4.0;
        break;
      case 6:
        ZoomFactor = 5.0;
        break;
      case 7:
        ZoomFactor = 6.0;
        break;
      default:
        //TGDiagram = (TTGDiagram *)ParentForm->ActiveMDIChild;
        //TGDiagram = GetTGForm();
        //double z = TGDiagram->Picture->CurrentZoom();
        double z = GetTGForm()->Picture->CurrentZoom();
        ZoomFactor = z;
        break;
      };
    Zoom(ZoomFactor);
    ZoomKey = false;
    }
}
//---------------------------------------------------------------------------

void __fastcall TParentForm::ZoomComboBoxKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
  double ZoomFactor;
  AnsiString ztext;

  if (Key == VK_RETURN)
    SetZoom();
  else
    ZoomKey = true;

}
//---------------------------------------------------------------------------

void TParentForm::SetZoom(void)
{
  double ZoomFactor;
  UnicodeString ztext;

  ztext = ZoomComboBox->Text;
  if (ztext == "Fit")
    ZoomFactor = 1.0;
  else if (ztext == "Height") {
    //TTGDiagram* TGDiagram = (TTGDiagram *)ParentForm->ActiveMDIChild;
    //ZoomFactor = TGDiagram->Picture->GetToHeightZoom();
    ZoomFactor = GetTGForm()->Picture->GetToHeightZoom();
    }
  else {
    try
      {
      int pos;
      if ((pos = ztext.Pos("%")) > 0)
        ztext.SetLength(pos-1);
      double z = IntlStrToDouble::GetDouble(ztext);
      ZoomFactor = z/100.0;
      }
    catch ( ... )
      {
      ZoomFactor = 1.0;
      }
    }
  ZoomKey = false;
  if (ZoomFactor < 1.0) ZoomFactor = 1.0;
  ztext.sprintf(L"%d\%", (int)(100.0*ZoomFactor));
  //TODO: put ztext in the TGParent.h
  ZoomComboBox->Text = ztext;
  Zoom(ZoomFactor);
}
//---------------------------------------------------------------------------

void TParentForm::Zoom(double ZoomFactor)
{
   //TTGDiagram* TGDiagram = (TTGDiagram *)ActiveMDIChild;

   TTGDiagram* TGDiagram = GetTGForm();
   TGDiagram->Picture->Zoom(ZoomFactor);

   if (!TGDiagram->ActiveSegment.IsEmpty()) {
     TGDiagram->ToolBar1->Hide();
     TGDiagram->Picture->ResetEditSegment();
     TGDiagram->ActiveSegment = "";
     }

   TGDiagram->Picture->OutputGraphicObjects(DISPLAY, TGDiagram);

   ZoomOutButton1->Enabled =
     (TGDiagram->Picture->CurrentZoom() > 1.0) ? true : false;

   ControlBar1->SetFocus();   // remove focus from ZoomComboBox
}
//---------------------------------------------------------------------------

void __fastcall TParentForm::Test1Click(TObject *Sender)
{
   GetSSForm()->Test();
}
//---------------------------------------------------------------------------

void __fastcall TParentForm::File1Click(TObject *Sender)
{
   MainMenuClicked = true;
   //MouseHook pMouseProc = reinterpret_cast<MouseHook>(MouseProc);
   //DWORD CurrentThreadId = GetCurrentThreadId();
   //HookID = SetWindowsHookEx(WH_MOUSE, pMouseProc, 0, CurrentThreadId);
}
//---------------------------------------------------------------------------

int __fastcall TParentForm::ActiveMDIFormType(void)
{
   AnsiString FormType = ActiveMDIChild->ClassType()->ClassName();
   int rv;
   if (FormType == "TTGDiagram")
     rv = TGDIAGRAM;
   else if (FormType == "TTilSpreadSheetForm")
     rv = TILSPREADSHEET;
   return rv;
}
//---------------------------------------------------------------------------

int __fastcall TParentForm::MDIFormType(int ChildNum)
{
   AnsiString FormType = MDIChildren[ChildNum]->ClassType()->ClassName();
   int rv;
   if (FormType == "TTGDiagram")
     rv = TGDIAGRAM;
   else if (FormType == "TTilSpreadSheetForm")
     rv = TILSPREADSHEET;
   return rv;
}
//---------------------------------------------------------------------------

void TParentForm::ActivateSpreadsheetMenu(bool Status, TPageControl* Page1,
     TcxPageControl* DataPage, TPageControl* Page2)
{
   TTilSpreadSheetForm* SSForm;

   if ((SSForm = GetSSForm()) == NULL) return;

   SaveButton1->Enabled = Status;
   ToolBarSpreadSheet->Visible = Status;
   if (Status) {
     //SaveButton1->Action = SSForm->FileSaveAction1;
     if (Page1->ActivePageIndex == 0) {                // Data tabsheet
       if (DataPage->ActivePageIndex == 0) {           // Counts worksheet
		 ToolButtonSSSum->Enabled = true;
		 ToolButtonSSCheckVars->Enabled = true;
		 ToolButtonSSPercent->Enabled = true;
		 ToolButtonSSLookup->Enabled = true;
		 ToolButtonSSEditLookup->Enabled = true;
		 ToolButtonSSCheckVars->Enabled = true;
		 DisableMenuItem(SSForm->DeleteWorksheet1, -1);
		 EnableMenuItem(SSForm->SS_CalcSums, 31);
		 EnableMenuItem(SSForm->SS_CalcPercents, 38);
		 //EnableMenuItem(SSForm->SS_CalcConc, 43);
		 //EnableMenuItem(SSForm->SS_CalcInflux, 44);
		 SSForm->SetConcFluxMenuItems(true);
		 EnableMenuItem(SSForm->SS_VariableLookup, 39);
		 EnableMenuItem(SSForm->SS_EditVariableLookup, 40);
		 EnableMenuItem(SSForm->SS_NewVariableLookup, -1);
		 EnableMenuItem(SSForm->SS_CheckVariables, 32);
		 EnableMenuItem(SSForm->SS_Chronology, 42);
		 }
	   else {                                          // any other worksheet
		 ToolButtonSSSum->Enabled = false;
		 ToolButtonSSCheckVars->Enabled = false;
		 ToolButtonSSPercent->Enabled = false;
		 ToolButtonSSLookup->Enabled = false;
		 ToolButtonSSEditLookup->Enabled = false;
		 ToolButtonSSCheckVars->Enabled = false;
		 EnableMenuItem(SSForm->DeleteWorksheet1, -1);
		 DisableMenuItem(SSForm->SS_CalcSums, 31);
		 DisableMenuItem(SSForm->SS_CalcPercents, 38);
		 //DisableMenuItem(SSForm->SS_CalcConc, 43);
		 //DisableMenuItem(SSForm->SS_CalcInflux, 44);
		 SSForm->SetConcFluxMenuItems(true);
		 DisableMenuItem(SSForm->SS_VariableLookup, 39);
		 DisableMenuItem(SSForm->SS_EditVariableLookup, 40);
		 DisableMenuItem(SSForm->SS_NewVariableLookup, -1);
		 DisableMenuItem(SSForm->SS_CheckVariables, 32);
         DisableMenuItem(SSForm->SS_Chronology, 42);
         }
       ToolButtonSSInsertRow->Enabled = true;
       ToolButtonSSDeleteRow->Enabled = true;
       ToolButtonSSInsertColumn->Enabled = true;
       ToolButtonSSDeleteColumn->Enabled = true;
       ToolButtonSSSort->Enabled = true;
       ToolButtonSSCut->Enabled = true;
       ToolButtonSSCopy->Enabled = true;
       ToolButtonSSPaste->Enabled = true;
       ToolButtonSSGraphics->Enabled = true;
       EnableMenuItem(SSForm->SS_CopyAll, -1);
       EnableMenuItem(SSForm->SS_ClearAll, 41);
       EnableMenuItem(SSForm->SS_Sort, 34);
       EnableMenuItem(SSForm->SS_ToggleRare, 24);
       EnableMenuItem(SSForm->SS_InsertRow, 27);
       EnableMenuItem(SSForm->DeleteRow1, 28);
       EnableMenuItem(SSForm->SS_InsertColumn, 29);
       EnableMenuItem(SSForm->DeleteColumn1, 30);
       EnableMenuItem(SSForm->SS_InsertWorksheet, -1);
       EnableMenuItem(SSForm->SS_Diagram, 7);
       if (DataPage->ActivePage->Caption.SubString(1,6) == "CONISS")
         EnableMenuItem(SSForm->SS_ClusterAnalysis, 26);
       else
         DisableMenuItem(SSForm->SS_ClusterAnalysis, 26);
       }
     else {    // Metadata tabsheet
       ToolButtonSSInsertColumn->Enabled = false;
       ToolButtonSSDeleteColumn->Enabled = false;
       ToolButtonSSSort->Enabled = false;
	   ToolButtonSSSum->Enabled = false;
	   ToolButtonSSCheckVars->Enabled = false;
       ToolButtonSSPercent->Enabled = false;
       ToolButtonSSCheckVars->Enabled = false;
       ToolButtonSSGraphics->Enabled = false;
       ToolButtonSSLookup->Enabled = false;
       ToolButtonSSEditLookup->Enabled = false;
       ToolButtonSSInsertRow->Enabled = false;
       ToolButtonSSDeleteRow->Enabled = false;
       DisableMenuItem(SSForm->SS_CopyAll, -1);
       DisableMenuItem(SSForm->SS_ClearAll, 41);
       DisableMenuItem(SSForm->SS_Sort, 34);
       DisableMenuItem(SSForm->SS_ToggleRare, 24);
       DisableMenuItem(SSForm->SS_InsertRow, 27);
       DisableMenuItem(SSForm->DeleteRow1, 28);
       DisableMenuItem(SSForm->SS_InsertColumn, 29);
       DisableMenuItem(SSForm->DeleteColumn1, 30);
       DisableMenuItem(SSForm->SS_InsertWorksheet, -1);
       DisableMenuItem(SSForm->DeleteWorksheet1, -1);
       DisableMenuItem(SSForm->SS_CalcSums, 31);
       DisableMenuItem(SSForm->SS_CalcPercents, 38);
       //DisableMenuItem(SSForm->SS_CalcConc, 43);
       //DisableMenuItem(SSForm->SS_CalcInflux, 44);
       SSForm->SetConcFluxMenuItems(false);
       DisableMenuItem(SSForm->SS_VariableLookup, 39);
       DisableMenuItem(SSForm->SS_EditVariableLookup, 40);
       DisableMenuItem(SSForm->SS_NewVariableLookup, -1);
       DisableMenuItem(SSForm->SS_CheckVariables, 32);
       DisableMenuItem(SSForm->SS_Chronology, 42);
       DisableMenuItem(SSForm->SS_Diagram, 7);
       DisableMenuItem(SSForm->SS_ClusterAnalysis, 26);
       }
   }
}
//---------------------------------------------------------------------------

void TParentForm::EnableMenuItem(TMenuItem* MenuItem, int ImageNo)
{
   MenuItem->Enabled = true;
   //if (ImageNo < 0) return;
   //Graphics::TBitmap* pBitmap = MenuItem->Bitmap;
   //pBitmap->Canvas->Brush->Color = clWhite;
   //pBitmap->Canvas->FillRect(Rect(0,0,16,16));
   //ImageList1->GetBitmap(ImageNo, MenuItem->Bitmap);
}
//---------------------------------------------------------------------------

void TParentForm::DisableMenuItem(TMenuItem* MenuItem, int ImageNo)
{
   MenuItem->Enabled = false;
   //if (ImageNo < 0) return;
   //Graphics::TBitmap* pBitmap = MenuItem->Bitmap;
   //pBitmap->Canvas->Brush->Color = clWhite;
   //pBitmap->Canvas->FillRect(Rect(0,0,16,16));
   //ImageList2->GetBitmap(ImageNo, MenuItem->Bitmap);
}
//---------------------------------------------------------------------------

void TParentForm::ActivateDiagramMenu(bool Status)
{
   //Tools1->Visible = false;
   //Graphics1->Enabled = Status;
   //TMenuItem *NewItem = new TMenuItem(ParentForm); // create the new item
   //MainMenu1->Items->Add(NewItem);// add it to the MainMenu
   //NewItem->Caption = "Herbie";


   ToolBarGraphics->Visible = Status;
   ToolBarZoomPlusMinus->Visible = Status;
   ToolBarZoomText->Visible = Status;
   SaveButton1->Enabled = Status;
   PrintButton1->Enabled = Status;
}
//---------------------------------------------------------------------------

// remove graph edit toolbar if activated. This is done when a new diagram
// or spreadsheet form is activated
void TParentForm::RemoveTGEditToolBar(TForm* ChildForm)
{
   for (int i=0; i<MDIChildCount; i++) {
	 if (MDIChildren[i]->Name.SubString(1,9) != "TGDiagram") continue;
	 TTGDiagram* TGDiagram = (TTGDiagram *)MDIChildren[i];
     if (TGDiagram == (TTGDiagram*)ChildForm) continue;
	 if (!TGDiagram->ActiveSegment.IsEmpty()) {
       TGDiagram->ToolBar1->Visible = false;
       TGDiagram->Picture->ResetEditSegment();
       TGDiagram->ActiveSegment = "";
       TGDiagram->Picture->OutputGraphicObjects(DISPLAY, TGDiagram);
       HideButton1->Enabled = false;
       break;
       }
     }
}
//---------------------------------------------------------------------------

void __fastcall TParentForm::ToolButtonSSCopyClick(TObject *Sender)
{
   GetSSForm()->SSCopyAction1Execute(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TParentForm::ToolButtonSSCutClick(TObject *Sender)
{
   GetSSForm()->SSCutAction1Execute(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TParentForm::ToolButtonSSPasteClick(TObject *Sender)
{
   GetSSForm()->SSPasteAction1Execute(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TParentForm::ToolButtonSSInsertRowClick(TObject *Sender)
{
   GetSSForm()->InsertRowAction1Execute(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TParentForm::ToolButtonSSDeleteRowClick(TObject *Sender)
{
   GetSSForm()->DeleteRowAction1Execute(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TParentForm::ToolButtonSSInsertColumnClick(TObject *Sender)
{
   GetSSForm()->InsertColumnAction1Execute(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TParentForm::ToolButtonSSDeleteColumnClick(TObject *Sender)
{
   GetSSForm()->DeleteColumnAction1Execute(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TParentForm::ToolButtonSSSortClick(TObject *Sender)
{
   GetSSForm()->SortAction1Execute(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TParentForm::ToolButtonSSSumClick(TObject *Sender)
{
   GetSSForm()->SumsAction1Execute(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TParentForm::ToolButtonSSPercentClick(TObject *Sender)
{
   GetSSForm()->PercentsAction1Execute(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TParentForm::ToolButtonSSLookupClick(TObject *Sender)
{
   GetSSForm()->VariableLookupAction1Execute(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TParentForm::ToolButtonSSCheckVarsClick(TObject *Sender)
{
   GetSSForm()->CheckVariablesAction1Execute(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TParentForm::ToolButtonSSGraphicsClick(TObject *Sender)
{
   GetSSForm()->DiagramAction1Execute(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TParentForm::DefaultDiagram1Click(TObject *Sender)
{
   GetSSForm()->DefaultDiagramAction1Execute(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TParentForm::TIEditTaxa2Click(TObject *Sender)
{
   GetSSForm()->EditTaxaAction1Execute(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TParentForm::TIEditGroups2Click(TObject *Sender)
{
   GetSSForm()->EditGroupsAction1Execute(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TParentForm::TIEditElements1Click(TObject *Sender)
{
   GetSSForm()->EditElementsAction1Execute(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TParentForm::TIEditUnits1Click(TObject *Sender)
{
   GetSSForm()->EditUnitsAction1Execute(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TParentForm::TIEditContexts2Click(TObject *Sender)
{
   GetSSForm()->EditContextsAction1Execute(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TParentForm::TIEditTaphonomy1Click(TObject *Sender)
{
   GetSSForm()->EditTaphonomyAction1Execute(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TParentForm::FileOpenAction1Execute(TObject *Sender)
{
  short FileType;
  UnicodeString FileName, PathName, InitialDir;

  //if (!tiGlobals->GetInitialDirectory().IsEmpty())
  //	OpenDialog1->InitialDir = tiGlobals->GetInitialDirectory();
  if (!tiGlobals->InitialDirectory.IsEmpty())
	OpenDialog1->InitialDir = tiGlobals->InitialDirectory;

  FileName = OpenDialog1->FileName;
  PathName = ExtractFilePath(FileName);
  InitialDir = OpenDialog1->InitialDir + "\\";

  if (PathName != InitialDir)
	OpenDialog1->FileName = "";

  int OpenFileExt = tiGlobals->OpenFileExt;

//#ifdef paidversion
  if (tiLicense->Type() != verFREE) {
	OpenDialog1->Filter = "All formats|*.tlx;*.tgx;*.xls;*.til;*.tgf";
	OpenDialog1->Filter += "|Tilia spreadsheet (*.tlx)|*.tlx";
	OpenDialog1->Filter += "|Tilia diagram (*.tgx)|*.tgx";
	OpenDialog1->Filter += "|Microsoft Excel Workbook (*.xls)|*.xls";
	OpenDialog1->Filter += "|Tilia for DOS (*.til)|*.til";
	OpenDialog1->Filter += "|TiliaGraph for DOS (*.tgf)|*.tgf";

	switch (OpenFileExt)
	 {
	 case TLX:
	   OpenDialog1->FilterIndex = 2;
	   OpenDialog1->DefaultExt = "tlx";
	   break;
	 case TGX:
	   OpenDialog1->FilterIndex = 3;
	   OpenDialog1->DefaultExt = "tgx";
	   break;
	 case XLS:
	   OpenDialog1->FilterIndex = 4;
	   OpenDialog1->DefaultExt = "xls";
	   break;
	 case TIL:
	   OpenDialog1->FilterIndex = 5;
	   OpenDialog1->DefaultExt = "til";
	   break;
	 case TGF:
	   OpenDialog1->FilterIndex = 6;
	   OpenDialog1->DefaultExt = "tgf";
	   break;
	 default:
	   OpenDialog1->FilterIndex = 1;
	   OpenDialog1->DefaultExt = "";
	 };
	}
//#else
  else {
	OpenDialog1->Filter = "All formats|*.tlx;*.til;*.xls";
	OpenDialog1->Filter += "|Tilia spreadsheet (*.tlx)|*.tlx";
	OpenDialog1->Filter += "|Tilia for DOS (*.til)|*.til";
	OpenDialog1->Filter += "|Microsoft Excel Workbook (*.xls)|*.xls";

	switch (OpenFileExt)
	 {
	 case TLX:
	   OpenDialog1->FilterIndex = 2;
	   OpenDialog1->DefaultExt = "tlx";
	   break;
	 case TIL:
	   OpenDialog1->FilterIndex = 3;
	   OpenDialog1->DefaultExt = "til";
	   break;
	 case XLS:
	   OpenDialog1->FilterIndex = 4;
	   OpenDialog1->DefaultExt = "xls";
	   break;
	 default:
	   OpenDialog1->FilterIndex = 1;
	   OpenDialog1->DefaultExt = "";
	 };
   }
//#endif

  if (OpenDialog1->Execute()) {
	FileName = OpenDialog1->FileName;
    if (ValidFileExt(FileName, &FileType)) {
      if (FileType == TGDIAGRAM) {
		// OpenTGDiagramWindow(FileName);
		DiagramParams Params(FileName);
		OpenTGDiagramWindow(Params);
        ZoomComboBox->Text = "Fit";
        }
      else if (FileType == TILSPREADSHEET) {
		OpenSpreadSheetWindow(FileName);
        }
      }
    }
}
//---------------------------------------------------------------------------

void __fastcall TParentForm::FileNewAction1Execute(TObject *Sender)
{
   NewSpreadSheetForm();
}
//---------------------------------------------------------------------------

TTilSpreadSheetForm* TParentForm::NewSpreadSheetForm(void)
{
   if (MDIChildCount == 0) {
	 CurrentChildPos.x = 0;
	 CurrentChildPos.y = 0;
	 }
   else {
	 CurrentChildPos.x = ActiveMDIChild->Left;
	 CurrentChildPos.y = ActiveMDIChild->Top;
	 }

   TilSpreadSheetForm = new TTilSpreadSheetForm(this);
   if (TilSpreadSheetForm->FatalError) {
	 delete TilSpreadSheetForm;
	 Screen->Cursor = crDefault;
	 return NULL;
	 }

   TilSpreadSheetForm->ProfGrid1->Cells[1][1]->Value =
	 TilSpreadSheetForm->Datasets[0].DatasetType;
   TilSpreadSheetForm->FormatWorksheet(TilSpreadSheetForm->ProfGrid1);
   return(TilSpreadSheetForm);
}
//---------------------------------------------------------------------------

void __fastcall TParentForm::SaveButton1Click(TObject *Sender)
{
   int FormType = ActiveMDIFormType();
   if (FormType == TGDIAGRAM)
     GetTGForm()->Save();
   else if (FormType == TILSPREADSHEET)
     GetSSForm()->Save();
}
//---------------------------------------------------------------------------

void __fastcall TParentForm::ExitAction1Execute(TObject *Sender)
{
   Close();
}
//---------------------------------------------------------------------------

void __fastcall TParentForm::HelpTopicsAction1Execute(TObject *Sender)
{
   Application->HelpContext(IDH_Introduction);
}
//---------------------------------------------------------------------------

void __fastcall TParentForm::AboutAction1Execute(TObject *Sender)
{
   AboutBox = new TAboutBox(this);
   AboutBox->ShowModal();
   delete AboutBox;
}
//---------------------------------------------------------------------------

void __fastcall TParentForm::RegistrationAction1Execute(TObject *Sender)
{
   if (MDIChildCount > 0) {
	 MessageDlg(L"Close all child windows before viewing or changing registration.",
	   mtWarning, TMsgDlgButtons() << mbOK, 0);
	 return;
	 }
   tiLicense->Register();
   if (tiLicense->Type() == verFREE) {
	 ToolButtonSSGraphics->Visible = false;
	 ToolBarSpreadSheet->Width -= ToolButtonSSGraphics->Width;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TParentForm::YaxisButton1Click(TObject *Sender)
{
   GetTGForm()->YaxesAction1Execute(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TParentForm::XaxisButton1Click(TObject *Sender)
{
   GetTGForm()->XaxesAction1Execute(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TParentForm::GraphStyleButton1Click(TObject *Sender)
{
   GetTGForm()->GraphStyleAction1Execute(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TParentForm::VariablesButton1Click(TObject *Sender)
{
   GetTGForm()->VariablesAction1Execute(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TParentForm::ZoneButton1Click(TObject *Sender)
{
   GetTGForm()->ZonesAction1Execute(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TParentForm::GroupButton1Click(TObject *Sender)
{
   GetTGForm()->GroupsAction1Execute(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TParentForm::DatesButton1Click(TObject *Sender)
{
  GetTGForm()->DatesAction1Execute(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TParentForm::LithButton1Click(TObject *Sender)
{
   GetTGForm()->LithologyAction1Execute(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TParentForm::TextButton1Click(TObject *Sender)
{
   GetTGForm()->TextAction1Execute(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TParentForm::AddTextButtonClick(TObject *Sender)
{
   GetTGForm()->InteractiveText();
}
//---------------------------------------------------------------------------
void __fastcall TParentForm::FrameButton1Click(TObject *Sender)
{
   GetTGForm()->FrameAction1Execute(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TParentForm::RareButton1Click(TObject *Sender)
{
   GetTGForm()->RareAction1Execute(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TParentForm::DendrogramButton1Click(TObject *Sender)
{
   GetTGForm()->ClusterAnalysisAction1Execute(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TParentForm::ColorButton1Click(TObject *Sender)
{
   GetTGForm()->ColorsAction1Execute(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TParentForm::Linewidths1Click(TObject *Sender)
{
   GetTGForm()->LineWidthsAction1Execute(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TParentForm::FontButton1Click(TObject *Sender)
{
   GetTGForm()->FontAction1Execute(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TParentForm::Login1Click(TObject *Sender)
{
   NeotomaLogin();
}
//---------------------------------------------------------------------------

void TParentForm::NeotomaLogin(void)
{
   if (!Login->IsLoggedIn) {
	 NeotomaLoginForm = new TNeotomaLoginForm(this);
	 NeotomaLoginForm->ShowModal();
	 delete NeotomaLoginForm;
	 if (Login->IsLoggedIn) {
	   Login1->Caption = L"&Logout";
	   for (int i=0; i<MDIChildCount; i++) {
		 if (SameText(MDIChildren[i]->Name.SubString(1,14), L"TilSpreadSheet")) {
		   TTilSpreadSheetForm* TSSForm = (TTilSpreadSheetForm*)MDIChildren[i];
		   TSSForm->Login1->Caption = L"&Logout";
		   }
		 }
	   // EPD module available if login database is EPD or Neotoma
	   EPD1->Visible = (Login->DatabaseID == 3 || Login->DatabaseID == 11);
	   // ts services available if login database is Neotoma
	   TSServices1->Visible = (Login->DatabaseID == 11);
	   }
	 }
   else {
	 Login->Logout();
	 Login1->Caption = L"&Login";
	 for (int i=0; i<MDIChildCount; i++) {
	   if (SameText(MDIChildren[i]->Name.SubString(1,14), L"TilSpreadSheet")) {
		 TTilSpreadSheetForm* TSSForm = (TTilSpreadSheetForm*)MDIChildren[i];
		 TSSForm->Login1->Caption = L"&Login";
		 }
	   }
	 EPD1->Visible = false;
	 TSServices1->Visible = false;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TParentForm::NeotomaAction1Execute(TObject *Sender)
{
   map<int,vector<MAPDATASET> > CollUnitDatasets;

   NeotomaDataForm = new TNeotomaDataForm(this);
   NeotomaDataForm->ShowModal();

   const vector<MAPDATASET>& SelectedDatasets = NeotomaDataForm->SelectedDatasets;

   for (unsigned int i=0; i<SelectedDatasets.size(); i++) {
	 int CollUnitID = SelectedDatasets[i].CollUnitID;
	 if (CollUnitDatasets.count(CollUnitID) == 0) {
	   vector<MAPDATASET> Datasets;
	   CollUnitDatasets[CollUnitID] = Datasets;
	   }
	 CollUnitDatasets[CollUnitID].push_back(SelectedDatasets[i]);
	 }
   delete NeotomaDataForm;

   if (CollUnitDatasets.size() > 0) {
	 map<int,vector<MAPDATASET> >::iterator itr;
	 for (itr = CollUnitDatasets.begin(); itr != CollUnitDatasets.end(); itr++) {
	   TTilSpreadSheetForm* TSSForm = NewSpreadSheetForm();
	   if (TSSForm != NULL)
		 TSSForm->DownloadNeotomaData(itr->second);
	   }
	 }
}
//---------------------------------------------------------------------------

void __fastcall TParentForm::EPDAction1Execute(TObject *Sender)
{
   EPDSITELOC EPDSiteLoc;
   int EPDSiteNr = -1;
   int EPDENr;

   EPDDataForm = new TEPDDataForm(this);
   EPDDataForm->ShowModal();
   if (EPDDataForm->SiteNr != -1) {
	 EPDSiteNr = EPDDataForm->SiteNr;
	 EPDENr = EPDDataForm->ENr;
	 EPDSiteLoc = EPDDataForm->EPDSiteLoc;
	 }
   delete EPDDataForm;

   if (EPDSiteNr != -1) {
	 TTilSpreadSheetForm* TSSForm = NewSpreadSheetForm();
	 if (TSSForm != NULL)
	   TSSForm->DownloadEPDData(EPDSiteNr, EPDENr, EPDSiteLoc);
	 }
}
//---------------------------------------------------------------------------

void __fastcall TParentForm::WhitmoreAction1Execute(TObject *Sender)
{
   WhitmoreForm = new TWhitmoreForm(this);
   WhitmoreForm->ShowModal();
   delete WhitmoreForm;
}
//---------------------------------------------------------------------------

void __fastcall TParentForm::WebServices1Click(TObject *Sender)
{
   WebServicesForm = new TWebServicesForm(this);
   WebServicesForm->ShowModal();
   delete WebServicesForm;
}
//---------------------------------------------------------------------------

void __fastcall TParentForm::TSServices1Click(TObject *Sender)
{
   TSServicesForm = new TTSServicesForm(this);
   TSServicesForm->ShowModal();
   delete TSServicesForm;
}
//---------------------------------------------------------------------------

