//---------------------------------------------------------------------------

#ifndef TIVersionH
#define TIVersionH
//---------------------------------------------------------------------------
#include <vcl.h>
#include "pch.h"
#include <vector>

/*
License Types:

  S: STUDENTVERSION
  // L: LICENSEDVERSION  demoted
  P: PROFESSIONALVERSION
  N: NEOTOMASTEWARDVERSION
  T: TRAININGVERSION

Example of Product Code for NEOTOMASTEWARDVERSION
N:49107BFF-F552-4693-9E83-08C84DAAFFFC

Example of Product Code for TRAININGVERSION
T:160604:49107BFF-F552-4693-9E83-08C84DAAFFFC    [2016-06-04] [yyyy-mm-dd]

STUDENTVERSION also has a expiry date
*/

enum TILIAVERSIONTYPES { verLEGACY, verFREE, verSTUDENT, verPROFESSIONAL,
						 verNEOTOMASTEWARD, verTRAINING, verMULTIUSE };
const UnicodeString RegistryPath = "Software\\Tilia\\Tilia";
//---------------------------------------------------------------------------

class VERSIONGUID
{
public:
	AnsiString VERSION;
	AnsiString GUID;
public:
	VERSIONGUID(AnsiString version, AnsiString guid) { VERSION = version; GUID = guid; }
};
//---------------------------------------------------------------------------

class TILIALICENSE
{
private:
	UnicodeString Owner;
	UnicodeString ProductKey;
	UnicodeString Hash;
	short LicenseType;
	UnicodeString ExpirationDate;
private:
	bool AppDataTiliaPathExists(void);
public:
	vector<VERSIONGUID> GUIDS;
public:
	TILIALICENSE();
	bool ValidateProductKey(void);
	bool Register(void);
	void UpgradeRegistration(unsigned int, UnicodeString&, UnicodeString&);
	short Type(void) { return LicenseType; }
	UnicodeString GetOwner(void) { return Owner; }
	UnicodeString GetExpirationDate(void) { return ExpirationDate; }
	TDateTime GetExpirationDate(UnicodeString DateStr, UnicodeString& ExpirationDate);
	void SetLicenseType(short lt) { LicenseType = lt; }
	void ParseProductKey(short& lt, UnicodeString& Key, UnicodeString& DateStr);
	//void RegisterFreeVersion(UnicodeString& Owner);
	//void SetOwner(UnicodeString owner) { Owner = owner; }
	void SetOwner(UnicodeString owner);
	void SetProductKey(UnicodeString key) { ProductKey = key; }
	UnicodeString GetHash(void) { return Hash; }
};
//---------------------------------------------------------------------------

class VERSION
{
private:
  int Major;
  int Minor;
  int Release;
  int Build;
public:
  VERSION() { Major = 0; Minor = 0; Release = 0; Build = 0; };
  VERSION(int major, int minor, int release)
    { Major = major; Minor = minor; Release = release; }
  VERSION(int major, int minor, int release, int build)
    { Major = major; Minor = minor; Release = release; Build = build; }
  VERSION(UnicodeString version);
  void SetVersion(UnicodeString version);
  int MajorVersion(void) const { return Major; }
  int MinorVersion(void) const { return Minor; }
  int ReleaseNo(void) const { return Release; }
  UnicodeString Version(void) const;
  void SetVersion(int major, int minor, int release)
    { Major = major; Minor = minor; Release = release; }
  void SetMajor(int major) { Major = major; }
  void SetMinor(int minor) { Minor = minor; }
  void SetRelease(int release) { Release = release; }
  bool operator > (const VERSION& compare );
  bool operator < (const VERSION& compare );
  bool operator == (const VERSION& compare );
  bool operator >= (const VERSION& compare );
};
//---------------------------------------------------------------------------

class CURRENTVERSION : public VERSION
{
public:
  CURRENTVERSION();
};
//---------------------------------------------------------------------------

extern PACKAGE TILIALICENSE *tiLicense;
//---------------------------------------------------------------------------
#endif
