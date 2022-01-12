//---------------------------------------------------------------------------
#ifndef TIGlobalsH
#define TIGlobalsH
//---------------------------------------------------------------------------
//#include <vcl.h>
#include "pch.h"
#include <Classes.hpp>
#include <Graphics.hpp>
#include <Registry.hpp>
#include <set>
#include <list>
#include "shlobj.h"

#ifndef WHITMORE
#define WHITMORE
#endif
//#ifndef TSTESTING   // this is defined for testing ts functions
//#define TSTESTING
//#endif


//---------------------------------------------------------------------------
//const AnsiString RegistryPath = "Software\\Tilia\\Tilia";
enum FILEEXTENTIONS { TGF, TGX, TIL, TLX, XML, XLS };
enum SUBSTITUTEONCHECK { SUBALL, SUBBLANK, SUBNONE };
//---------------------------------------------------------------------------

class TIGLOBALS
{
private:
  UnicodeString FInitialDirectory;
  int FParentWindowHeight;
  int FParentWindowWidth;
  int FGoogleMapHeight;
  int FGoogleMapWidth;
  int FGoogleMapZoomLevel;
  double FGoogleMapLatitude;
  double FGoogleMapLongitude;
  int FOpenFileExt;
  int FPercentDecimalPlaces;
  int FConcDecimalPlaces;
  int FInfluxDecimalPlaces;
  int FSpecWindWidth;
  int FSpecWindHeight;
  UnicodeString FDatasetType;
  UnicodeString FAppDataTiliaPath;
  UnicodeString FAppDataTiliaLookupPath;
  UnicodeString FMyLookupPath;
  UnicodeString FWhitmorePath;
  UnicodeString FDictionaryPath;
  UnicodeString FTaxaFile;
  UnicodeString FElementsFile;
  UnicodeString FUnitsFile;
  UnicodeString FContextFile;
  UnicodeString FTaphonomyFile;
  UnicodeString FBaconClamDir;
  set<UnicodeString> FTaxaGroups;
  UnicodeString FHierarchyFile;
  UnicodeString FSSFontName;
  UnicodeString FNeotomaUserName;
  bool FAddSynonyms;
  bool FNeotomaRememberMe;
  bool FUseGoogleMaps;
  int FSSFontSize;
  int FSSDefaultColWidth;
  int FSSDefaultRowHeight;
  int FUndoLimit;
  int FInternetTimeout;
  short FReplaceVarCodes;
  short FReplaceElements;
  short FReplaceUnits;
  short FReplaceGroups;
  TColor FFrozenBackgroundColor;
  TColor FRareColor;
  list<pair<TColor,UnicodeString> > FCustomColors;
  struct
    {
    bool CheckDups;
	bool CaseSensitive;
	} CodeOptions;
  struct {
	bool Codes;
	bool Elements;
	bool Units;
	bool Context;
	bool Taphonomy;
	bool Groups;
	} SSHide;
  UnicodeString FNeotomaEndpoint;
  UnicodeString FOxCalEndpoint;

//private:
//  void GetDefaultLookupPath(void);
public:
  TIGLOBALS();
  ~TIGLOBALS();
  __property UnicodeString InitialDirectory = {read = FInitialDirectory, write = FInitialDirectory};
  __property int ClientHeight = {read = FParentWindowHeight, write = FParentWindowHeight};
  __property int ClientWidth = {read = FParentWindowWidth, write = FParentWindowWidth};
  __property int GoogleMapHeight = {read = FGoogleMapHeight, write = FGoogleMapHeight};
  __property int GoogleMapWidth = {read = FGoogleMapWidth, write = FGoogleMapWidth};
  __property int GoogleMapZoomLevel = {read = FGoogleMapZoomLevel, write = FGoogleMapZoomLevel};
  __property double GoogleMapLatitude = {read = FGoogleMapLatitude, write = FGoogleMapLatitude};
  __property double GoogleMapLongitude = {read = FGoogleMapLongitude, write = FGoogleMapLongitude};
  __property int OpenFileExt = {read = FOpenFileExt, write = FOpenFileExt};
  __property int PercentDecimalPlaces = {read = FPercentDecimalPlaces, write = FPercentDecimalPlaces};
  __property int ConcDecimalPlaces = {read = FConcDecimalPlaces, write = FConcDecimalPlaces};
  __property int InfluxDecimalPlaces = {read = FInfluxDecimalPlaces, write = FInfluxDecimalPlaces};
  __property int SpecWindWidth = {read = FSpecWindWidth, write = FSpecWindWidth};
  __property int SpecWindHeight = {read = FSpecWindHeight, write = FSpecWindHeight};
  __property UnicodeString DatasetType = {read = FDatasetType, write = FDatasetType};
  __property bool AddSynonyms = {read = FAddSynonyms, write = FAddSynonyms};
  __property bool NeotomaRememberMe = {read = FNeotomaRememberMe, write = FNeotomaRememberMe};
  __property bool UseGoogleMaps = {read = FUseGoogleMaps, write = FUseGoogleMaps};
  __property UnicodeString TaxaFile = {read = FTaxaFile, write = FTaxaFile};
  __property UnicodeString ElementsFile = {read = FElementsFile, write = FElementsFile};
  __property UnicodeString UnitsFile = {read = FUnitsFile, write = FUnitsFile};
  __property UnicodeString ContextFile = {read = FContextFile, write = FContextFile};
  __property UnicodeString TaphonomyFile = {read = FTaphonomyFile, write = FTaphonomyFile};
  __property UnicodeString BaconClamDir = {read = FBaconClamDir, write = FBaconClamDir};
  __property set<UnicodeString> TaxaGroups = {read = FTaxaGroups, write = FTaxaGroups};
  __property UnicodeString HierarchyFile = {read = FHierarchyFile, write = FHierarchyFile};
  __property UnicodeString SSFontName = {read = FSSFontName, write = FSSFontName};
  __property UnicodeString NeotomaUserName = {read = FNeotomaUserName, write = FNeotomaUserName};
  __property int SSFontSize = {read = FSSFontSize, write = FSSFontSize};
  __property int SSDefaultColWidth = {read = FSSDefaultColWidth, write = FSSDefaultColWidth};
  __property int SSDefaultRowHeight = {read = FSSDefaultRowHeight, write = FSSDefaultRowHeight};
  __property short ReplaceVarCodes = {read = FReplaceVarCodes, write = FReplaceVarCodes};
  __property short ReplaceElements = {read = FReplaceElements, write = FReplaceElements};
  __property short ReplaceUnits = {read = FReplaceUnits, write = FReplaceUnits};
  __property short ReplaceGroups = {read = FReplaceGroups, write = FReplaceGroups};
  __property TColor FrozenBackgroundColor = {read = FFrozenBackgroundColor, write = FFrozenBackgroundColor};
  __property TColor RareColor = {read = FRareColor, write = FRareColor};
  __property list<pair<TColor,UnicodeString> > CustomColors = {read = FCustomColors, write = FCustomColors};
  __property bool SSHideCodes = {read = SSHide.Codes, write = SSHide.Codes};
  __property bool SSHideElements = {read = SSHide.Elements, write = SSHide.Elements};
  __property bool SSHideUnits = {read = SSHide.Units, write = SSHide.Units};
  __property bool SSHideContext = {read = SSHide.Context, write = SSHide.Context};
  __property bool SSHideTaphonomy = {read = SSHide.Taphonomy, write = SSHide.Taphonomy};
  __property bool SSHideGroups = {read = SSHide.Groups, write = SSHide.Groups};
  __property bool CodeOptionDups = {read = CodeOptions.CheckDups, write = CodeOptions.CheckDups};
  __property bool CodeOptionCase = {read = CodeOptions.CaseSensitive, write = CodeOptions.CaseSensitive};
  __property int UndoLimit = {read = FUndoLimit, write = FUndoLimit};
  __property int InternetTimeout = {read = FInternetTimeout, write = FInternetTimeout};
  __property UnicodeString AppDataTiliaPath = {read = FAppDataTiliaPath};
  __property UnicodeString AppDataTiliaLookupPath = {read = FAppDataTiliaLookupPath};
  __property UnicodeString MyLookupPath = {read = FMyLookupPath, write = FMyLookupPath};
  __property UnicodeString WhitmorePath = {read = FWhitmorePath, write = FWhitmorePath};
  __property UnicodeString DictionaryPath = {read = FDictionaryPath, write = FDictionaryPath};
  __property UnicodeString NeotomaEndpoint = {read = FNeotomaEndpoint, write = FNeotomaEndpoint};
  __property UnicodeString OxCalEndpoint = {read = FOxCalEndpoint, write = FOxCalEndpoint};
};
//---------------------------------------------------------------------------
extern TIGLOBALS *tiGlobals;
//---------------------------------------------------------------------------
#endif
