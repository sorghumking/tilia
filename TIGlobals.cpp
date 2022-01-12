//---------------------------------------------------------------------------
#pragma hdrstop

#include "TIGlobals.h"
#ifndef TIVersionH
#include "TIVersion.h"
#endif
#ifndef TGUtilsH
#include "TGUtils.h"
#endif
//---------------------------------------------------------------------------

#pragma package(smart_init)

//---------------------------------------------------------------------------
TIGLOBALS *tiGlobals;
//---------------------------------------------------------------------------

TIGLOBALS::TIGLOBALS()
{
   FParentWindowHeight = 422;
   FParentWindowWidth = 672;
   FGoogleMapHeight = 554;
   FGoogleMapWidth = 800;
   FGoogleMapZoomLevel = 1;
   FGoogleMapLatitude = 45.0;
   FGoogleMapLongitude = 0.0;
   FSpecWindWidth = 832;
   FSpecWindHeight = 301;
   FOpenFileExt = TLX;
   FPercentDecimalPlaces = 1;
   FConcDecimalPlaces = 0;
   FInfluxDecimalPlaces = 0;
   FDatasetType = "Pollen";
   FInitialDirectory = "";
   FAppDataTiliaPath = "";
   FAppDataTiliaLookupPath = "";
   FMyLookupPath = "";
   FWhitmorePath = "";
   FDictionaryPath = "";
   FAddSynonyms = false;
   FNeotomaRememberMe = true;
   FUseGoogleMaps = true;
   FTaxaFile = "";
   FHierarchyFile = "";
   FSSFontName = "Arial";
   FNeotomaUserName = L"";
   FSSFontSize = 9;
   FSSDefaultColWidth = 64;
   FSSDefaultRowHeight = 18;
   FUndoLimit = 10;
   FInternetTimeout = 60;
   FFrozenBackgroundColor = clSilver;
   FRareColor = clRed;
   FReplaceVarCodes = SUBALL;
   FReplaceElements = SUBBLANK;
   FReplaceUnits  = SUBBLANK;
   FReplaceGroups = SUBALL;
   SSHide.Codes = true;
   SSHide.Elements = false;
   SSHide.Units = false;
   SSHide.Context = false;
   SSHide.Taphonomy = false;
   SSHide.Groups = true;
   CodeOptions.CheckDups = true;
   CodeOptions.CaseSensitive = false;
   FNeotomaEndpoint = L"https://tilia.neotomadb.org/api/";
   FOxCalEndpoint = L"https://api.neotomadb.org/oxcal/";

   TRegistry& regKey = *new TRegistry();
   regKey.Access = KEY_READ;
   bool keyGood = regKey.OpenKey(RegistryPath, false);
   if (keyGood)
	 {
	   if (regKey.ValueExists("InitialDirectory"))
		 FInitialDirectory = regKey.ReadString("InitialDirectory");
	   if (regKey.ValueExists("ParentWindowHeight"))
		 FParentWindowHeight = regKey.ReadInteger("ParentWindowHeight");
	   if (regKey.ValueExists("ParentWindowWidth"))
		 FParentWindowWidth = regKey.ReadInteger("ParentWindowWidth");
	   if (regKey.ValueExists("GoogleMapHeight"))
		 FGoogleMapHeight = regKey.ReadInteger("GoogleMapHeight");
	   if (regKey.ValueExists("GoogleMapWidth"))
		 FGoogleMapWidth = regKey.ReadInteger("GoogleMapWidth");
	   if (regKey.ValueExists("GoogleMapZoomLevel"))
		 FGoogleMapZoomLevel = regKey.ReadInteger("GoogleMapZoomLevel");
	   if (regKey.ValueExists("GoogleMapLatitude"))
		 FGoogleMapLatitude = regKey.ReadFloat("GoogleMapLatitude");
	   if (regKey.ValueExists("GoogleMapLongitude"))
		 FGoogleMapLongitude = regKey.ReadFloat("GoogleMapLongitude");
	   if (regKey.ValueExists("SpecWindWidth"))
		 FSpecWindWidth = regKey.ReadInteger("SpecWindWidth");
	   if (regKey.ValueExists("SpecWindHeight"))
		 FSpecWindHeight = regKey.ReadInteger("SpecWindHeight");
	   if (regKey.ValueExists("OpenFileExt"))
		 FOpenFileExt = regKey.ReadInteger("OpenFileExt");
	   if (regKey.ValueExists("PercentDecimalPlaces"))
		 FPercentDecimalPlaces = regKey.ReadInteger("PercentDecimalPlaces");
	   if (regKey.ValueExists("ConcDecimalPlaces"))
		 FConcDecimalPlaces = regKey.ReadInteger("ConcDecimalPlaces");
	   if (regKey.ValueExists("InfluxDecimalPlaces"))
		 FInfluxDecimalPlaces = regKey.ReadInteger("InfluxDecimalPlaces");
	   if (regKey.ValueExists("DatasetType"))
		 FDatasetType = regKey.ReadString("DatasetType");
	   if (regKey.ValueExists("MyLookupPath"))
		 FMyLookupPath = regKey.ReadString("MyLookupPath");

	   // if MyLookupPath is set to AppData or empty, reset to ProgramData
	   WCHAR szPath[MAX_PATH];
	   if (SHGetFolderPathW(NULL, CSIDL_LOCAL_APPDATA|CSIDL_FLAG_CREATE, NULL, 0, szPath) == S_OK) {
		 UnicodeString LookupPath = szPath;
		 LookupPath += L"\\Tilia\\Lookup\\";
		 if (SameText(LookupPath, FMyLookupPath) || FMyLookupPath.IsEmpty()) {
		   if (SHGetFolderPathW(NULL, CSIDL_COMMON_APPDATA|CSIDL_FLAG_CREATE, NULL, 0, szPath) == S_OK) {
			 LookupPath = szPath;
			 FMyLookupPath = LookupPath + L"\\Tilia\\Lookup\\";
			 }
		   }
		 }

	   if (regKey.ValueExists("WhitmorePath"))
		 FWhitmorePath = regKey.ReadString("WhitmorePath");
	   if (regKey.ValueExists("DictionaryPath"))
		 FDictionaryPath = regKey.ReadString("DictionaryPath");
	   if (regKey.ValueExists("NeotomaEndpoint"))                        // new
		 FNeotomaEndpoint = regKey.ReadString("NeotomaEndpoint");
	   if (regKey.ValueExists("OxCalEndpoint"))                        // new
		 FOxCalEndpoint = regKey.ReadString("OxCalEndpoint");
	   if (regKey.ValueExists("AddSynonyms"))
		 FAddSynonyms = (bool)regKey.ReadInteger("AddSynonyms");
	   if (regKey.ValueExists("NeotomaRememberMe"))
		 FNeotomaRememberMe = (bool)regKey.ReadInteger("NeotomaRememberMe");
	   if (regKey.ValueExists("UseGoogleMaps"))
		 FUseGoogleMaps = (bool)regKey.ReadInteger("UseGoogleMaps");
	   if (regKey.ValueExists("TaxaFile"))
		 FTaxaFile = regKey.ReadString("TaxaFile");
	   if (regKey.ValueExists("ElementsFile"))
		 FElementsFile = regKey.ReadString("ElementsFile");
	   if (regKey.ValueExists("UnitsFile"))
		 FUnitsFile = regKey.ReadString("UnitsFile");
	   if (regKey.ValueExists("ContextFile"))
		 FContextFile = regKey.ReadString("ContextFile");
	   if (regKey.ValueExists("TaphonomyFile"))
		 FTaphonomyFile = regKey.ReadString("TaphonomyFile");
	   if (regKey.ValueExists("BaconClamDir"))
		 FBaconClamDir = regKey.ReadString("BaconClamDir");
	   if (regKey.ValueExists("GroupCategory")) {
		 AnsiString Groups = regKey.ReadString("GroupCategory");
		 FTaxaGroups.clear();
		 int pos;
		 while ((pos = Groups.AnsiPos(";")) > 1) {
		   if (pos > 1)
			 FTaxaGroups.insert(Groups.SubString(1,pos-1));
		   Groups.Delete(1,pos);
		   }
		 if (!Groups.IsEmpty())
		   FTaxaGroups.insert(Groups);
		 }
	   if (regKey.ValueExists("HierarchyFile"))
		 FHierarchyFile = regKey.ReadString("HierarchyFile");
	   if (regKey.ValueExists("SSFontName"))
		 FSSFontName = regKey.ReadString("SSFontName");
	   if (regKey.ValueExists("NeotomaUserName"))
		 FNeotomaUserName = regKey.ReadString("NeotomaUserName");
	   if (regKey.ValueExists("SSFontSize"))
		 FSSFontSize = regKey.ReadInteger("SSFontSize");
	   if (regKey.ValueExists("SSDefaultColWidth"))
		 FSSDefaultColWidth = regKey.ReadInteger("SSDefaultColWidth");
	   if (regKey.ValueExists("SSDefaultRowHeight"))
		 FSSDefaultRowHeight = regKey.ReadInteger("SSDefaultRowHeight");
	   if (regKey.ValueExists("FrozenBackgroundColor"))
		 FFrozenBackgroundColor = (TColor)regKey.ReadInteger("FrozenBackgroundColor");
	   if (regKey.ValueExists("RareColor"))
		 FRareColor = (TColor)regKey.ReadInteger("RareColor");

	   if (regKey.ValueExists("CustomColors")) {
		 UnicodeString CustomColorStr = regKey.ReadString("CustomColors");
		 if (!CustomColorStr.IsEmpty()) {
		   vector<UnicodeString> Colors;
		   ParseParts(CustomColorStr, L",", Colors);
		   for (unsigned int i = 0; i < Colors.size(); i++) {
		     TColor AColor = (TColor)Colors[i].ToInt();
			 int blue = GetBValue(AColor);
			 int green = GetGValue(AColor);
			 int red = GetRValue(AColor);
			 UnicodeString AColorDescription = IntToStr(red) + L"." + IntToStr(green) + L"." + IntToStr(blue);
			 CustomColors.push_back(pair<TColor,UnicodeString>(AColor,AColorDescription));
		     }
		   }
		 }

	   if (regKey.ValueExists("HideSSCodes"))
		 SSHide.Codes = (bool)regKey.ReadInteger("HideSSCodes");
	   if (regKey.ValueExists("HideSSElements"))
		 SSHide.Elements = (bool)regKey.ReadInteger("HideSSElements");
	   if (regKey.ValueExists("HideSSUnits"))
		 SSHide.Units = (bool)regKey.ReadInteger("HideSSUnits");
	   if (regKey.ValueExists("HideSSContext"))
		 SSHide.Context = (bool)regKey.ReadInteger("HideSSContext");
	   if (regKey.ValueExists("HideSSTaphonomy"))
		 SSHide.Taphonomy = (bool)regKey.ReadInteger("HideSSTaphonomy");
	   if (regKey.ValueExists("HideSSGroups"))
		 SSHide.Groups = (bool)regKey.ReadInteger("HideSSGroups");

	   if (regKey.ValueExists("ReplaceVarCodes"))
		 FReplaceVarCodes = (short)regKey.ReadInteger("ReplaceVarCodes");
	   if (regKey.ValueExists("ReplaceElements"))
		 FReplaceElements = (short)regKey.ReadInteger("ReplaceElements");
	   if (regKey.ValueExists("ReplaceUnits"))
		 FReplaceUnits = (short)regKey.ReadInteger("ReplaceUnits");
	   if (regKey.ValueExists("ReplaceGroups"))
		 FReplaceGroups = (short)regKey.ReadInteger("ReplaceGroups");
	   if (regKey.ValueExists("CheckDupCodes"))
		 CodeOptions.CheckDups = (bool)regKey.ReadInteger("CheckDupCodes");
	   if (regKey.ValueExists("CaseSensitiveCodes"))
		 CodeOptions.CaseSensitive = (bool)regKey.ReadInteger("CaseSensitiveCodes");
	   if (regKey.ValueExists("UndoLimit"))
		 FUndoLimit = regKey.ReadInteger("UndoLimit");
	   if (regKey.ValueExists("InternetTimeout"))
		 FInternetTimeout = regKey.ReadInteger("InternetTimeout");
	 }
   else {
	 UnicodeString msg = L"Could not open registry key HKEY_CURRENT_USER\\" + RegistryPath +
	   L"\nProgram will probably not run correctly.";
	 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 }

   delete &regKey;

   WCHAR szPath[MAX_PATH];
   // if (SHGetFolderPathW(NULL, CSIDL_LOCAL_APPDATA|CSIDL_FLAG_CREATE, NULL, 0, szPath) == S_OK) [
   if (SHGetFolderPathW(NULL, CSIDL_COMMON_APPDATA|CSIDL_FLAG_CREATE, NULL, 0, szPath) == S_OK) {
	 FAppDataTiliaPath = szPath;
	 FAppDataTiliaPath += L"\\Tilia\\";
	 //ShowMessage(FAppDataTiliaPath);
	 FAppDataTiliaLookupPath = FAppDataTiliaPath + L"Lookup\\";
	 }
}
//---------------------------------------------------------------------------

TIGLOBALS::~TIGLOBALS()
{
   TRegistry& regKey = *new TRegistry();
   bool keyGood = regKey.OpenKey(RegistryPath, true);
   if (keyGood) {
	 if (!InitialDirectory.IsEmpty())
	   regKey.WriteString("InitialDirectory", FInitialDirectory);
	 regKey.WriteInteger("ParentWindowHeight", FParentWindowHeight);
	 regKey.WriteInteger("ParentWindowWidth", FParentWindowWidth);
	 regKey.WriteInteger("GoogleMapHeight", FGoogleMapHeight);
	 regKey.WriteInteger("GoogleMapWidth", FGoogleMapWidth);
	 regKey.WriteInteger("GoogleMapZoomLevel", FGoogleMapZoomLevel);
	 regKey.WriteFloat("GoogleMapLatitude", FGoogleMapLatitude);
	 regKey.WriteFloat("GoogleMapLongitude", FGoogleMapLongitude);
	 regKey.WriteInteger("SpecWindWidth", FSpecWindWidth);
	 regKey.WriteInteger("SpecWindHeight", FSpecWindHeight);
	 regKey.WriteInteger("OpenFileExt", FOpenFileExt);
	 regKey.WriteInteger("PercentDecimalPlaces", FPercentDecimalPlaces);
	 regKey.WriteInteger("ConcDecimalPlaces", FConcDecimalPlaces);
	 regKey.WriteInteger("InfluxDecimalPlaces", FInfluxDecimalPlaces);
	 regKey.WriteString("DatasetType", FDatasetType);
	 regKey.WriteInteger("AddSynonyms", (int)FAddSynonyms);
	 regKey.WriteInteger("NeotomaRememberMe", (int)FNeotomaRememberMe);
	 regKey.WriteInteger("UseGoogleMaps", (int)FUseGoogleMaps);
	 regKey.WriteString("MyLookupPath", FMyLookupPath);
	 regKey.WriteString("WhitmorePath", FWhitmorePath);
	 regKey.WriteString("DictionaryPath", FDictionaryPath);
	 regKey.WriteString("NeotomaEndpoint", FNeotomaEndpoint);      // new
	 regKey.WriteString("OxCalEndpoint", FOxCalEndpoint);          // new
	 regKey.WriteString("TaxaFile", FTaxaFile);
	 regKey.WriteString("ElementsFile", FElementsFile);
	 regKey.WriteString("UnitsFile", FUnitsFile);
	 regKey.WriteString("ContextFile", FContextFile);
	 regKey.WriteString("TaphonomyFile", FTaphonomyFile);
	 regKey.WriteString("BaconClamDir", FBaconClamDir);

	 AnsiString Groups;
	 if (TaxaGroups.size() > 0) {
	   set<UnicodeString>::iterator itr;
	   set<UnicodeString>::iterator begin = FTaxaGroups.begin();
	   Groups = *begin;
	   begin++;
	   for (itr = begin; itr != FTaxaGroups.end(); itr++) {
		 Groups += ";";
		 Groups += *itr;
		 }
	   }
	 regKey.WriteString("GroupCategory", Groups);
	 regKey.WriteString("HierarchyFile", FHierarchyFile);
	 regKey.WriteString("SSFontName", FSSFontName);
	 regKey.WriteString("NeotomaUserName", FNeotomaUserName);
	 regKey.WriteInteger("SSFontSize", FSSFontSize);
	 regKey.WriteInteger("SSDefaultColWidth", FSSDefaultColWidth);
	 regKey.WriteInteger("SSDefaultRowHeight", FSSDefaultRowHeight);
	 regKey.WriteInteger("FrozenBackgroundColor", (int)FFrozenBackgroundColor);
	 regKey.WriteInteger("RareColor", (int)FRareColor);

	 UnicodeString CustomColorStr;
	 if (CustomColors.size() > 0) {
	   list<pair<TColor,UnicodeString> >::iterator itr;
	   for (itr = CustomColors.begin(); itr != CustomColors.end(); itr++) {
		 if (!CustomColorStr.IsEmpty())
		   CustomColorStr += L",";
		 CustomColorStr += IntToStr((int)itr->first);
		 }
	   }
	 regKey.WriteString("CustomColors", CustomColorStr);

	 //regKey.WriteInteger("HideSSColumnsRows", (int)SSHide.Byte);
	 regKey.WriteInteger("HideSSCodes", (int)SSHide.Codes);
	 regKey.WriteInteger("HideSSElements", (int)SSHide.Elements);
	 regKey.WriteInteger("HideSSUnits", (int)SSHide.Units);
	 regKey.WriteInteger("HideSSContext", (int)SSHide.Context);
	 regKey.WriteInteger("HideSSTaphonomy", (int)SSHide.Taphonomy);
	 regKey.WriteInteger("HideSSGroups", (int)SSHide.Groups);

	 regKey.WriteInteger("ReplaceVarCodes", (int)FReplaceVarCodes);
	 regKey.WriteInteger("ReplaceElements", (int)FReplaceElements);
	 regKey.WriteInteger("ReplaceUnits", (int)FReplaceUnits);
	 regKey.WriteInteger("ReplaceGroups", (int)FReplaceGroups);

	 regKey.WriteInteger("CheckDupCodes", (int)CodeOptions.CheckDups);
	 regKey.WriteInteger("CaseSensitiveCodes", (int)CodeOptions.CaseSensitive);
	 regKey.WriteInteger("UndoLimit", FUndoLimit);
	 regKey.WriteInteger("InternetTimeout", FInternetTimeout);
}
   delete &regKey;
}
//---------------------------------------------------------------------------

