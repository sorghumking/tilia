//---------------------------------------------------------------------------
#pragma hdrstop
#include "shlobj.h"

#include "TIVersion.h"
// #include <IBUtils.hpp>
#ifndef TIUtilsH
#include "TIUtils.h"
#endif
#ifndef TGRegH
#include "TGReg.h"
#endif

//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
TILIALICENSE* tiLicense;
//---------------------------------------------------------------------------

TILIALICENSE::TILIALICENSE()
{
   GUIDS.push_back(VERSIONGUID("TGView 2.0.2", "36ECB5DB-1EDE-4B14-9D3D-F10B1D3C2787"));
   GUIDS.push_back(VERSIONGUID("Tilia 1.0.1",  "67078DEE-0AA2-4E02-92A5-69D0AD29D4C8"));
   GUIDS.push_back(VERSIONGUID("Tilia 1.4.9",  "3350A4F3-13E6-4F7D-9FB8-D7939A1B0352"));
   GUIDS.push_back(VERSIONGUID("Tilia 1.4.10", "B8694BF0-20C8-441D-A7B7-659A9660555F"));
   GUIDS.push_back(VERSIONGUID("Tilia 1.5.11", "9FC56D5A-834A-4085-A092-9EC416D7DD4C"));
   GUIDS.push_back(VERSIONGUID("Tilia 1.5.12", "B3DE017F-ACC0-43D3-AFBA-BDA0C273077D"));
   GUIDS.push_back(VERSIONGUID("Tilia 1.6.13", "6CDEB4E7-AB00-4F14-AA79-A3284723C801"));
   GUIDS.push_back(VERSIONGUID("Tilia 1.7.14", "B1CF5B81-6A09-4ADC-9A39-81477262F3FB"));
   GUIDS.push_back(VERSIONGUID("Tilia 1.7.15", "24AB5648-6B8D-46C1-8B8D-530E12B05AC8"));
   GUIDS.push_back(VERSIONGUID("Tilia 1.7.16", "6FC35511-B32A-42C3-ABBC-8D87786F9256"));
   GUIDS.push_back(VERSIONGUID("Tilia 1.8.17", "9C88C63E-5F05-4BBD-8102-1586D8445573"));
   GUIDS.push_back(VERSIONGUID("Tilia 2.0.1",  "C7F68A7B-D36B-450A-BE86-12DA87B34EDD"));
   GUIDS.push_back(VERSIONGUID("Tilia 2.0.3",  "9ED27D86-9959-4A00-A4E8-5DBCE16C8DF0"));
   GUIDS.push_back(VERSIONGUID("Tilia 2.0.4",  "49107BFF-F552-4693-9E83-08C84DAAFFFC"));
   GUIDS.push_back(VERSIONGUID("Tilia 2.0.5",  "027E2BD4-E730-42B2-B792-3A554E094786"));
   GUIDS.push_back(VERSIONGUID("Tilia 2.0.6",  "1F960FF7-C8B0-4B8E-B4AF-EF8FA751F53A"));
   GUIDS.push_back(VERSIONGUID("Tilia 2.0.7",  "8D1FD9C7-E5A7-475D-B332-9814873BE19E"));
   GUIDS.push_back(VERSIONGUID("Tilia 2.0.8",  "924857D9-1A74-4BC3-8779-C4C0F8D074D1"));
   GUIDS.push_back(VERSIONGUID("Tilia 2.0.9",  "0FBEE716-ADC8-4D4D-BAF0-8EF291F1A8C4"));
   GUIDS.push_back(VERSIONGUID("Tilia 2.0.10", "C3B55387-F1BF-4F61-9DE5-6E917EFFADDF"));
   GUIDS.push_back(VERSIONGUID("Tilia 2.0.11", "FE1EB2A2-8C78-4ABA-9065-BBB0D36CCCF3"));
   GUIDS.push_back(VERSIONGUID("Tilia 2.0.12", "6B169C15-2927-4B96-82EF-D3317171340D"));
   GUIDS.push_back(VERSIONGUID("Tilia 2.0.13", "98658455-6B4C-4027-914F-781A340DA205"));
   GUIDS.push_back(VERSIONGUID("Tilia 2.0.14", "380BF704-FA13-483F-B4F3-33E42BFA0093"));
   GUIDS.push_back(VERSIONGUID("Tilia 2.0.15", "0C360B3C-FB3F-46E6-83B5-B5AE5BF7BF4F"));
   GUIDS.push_back(VERSIONGUID("Tilia 2.0.16", "1553549B-D855-474A-97FE-A59FC679D322"));
   GUIDS.push_back(VERSIONGUID("Tilia 2.0.17", "6B7BE9F6-4FD9-4FC6-970C-B805E2CAA807"));
   GUIDS.push_back(VERSIONGUID("Tilia 2.0.18", "BBFD6E60-CD1A-4B73-AB15-8BD05C58D2CF"));
   GUIDS.push_back(VERSIONGUID("Tilia 2.0.19", "36C5E0C5-1BC3-4576-8755-13A39044AAE7"));
   GUIDS.push_back(VERSIONGUID("Tilia 2.0.20", "21895D76-FC22-430B-A755-4B75E1AE12AC"));
   GUIDS.push_back(VERSIONGUID("Tilia 2.0.21", "783D66DB-0710-4E29-A504-871C55E0D028"));
   GUIDS.push_back(VERSIONGUID("Tilia 2.0.22", "016A3B38-14F9-4B60-A485-B52EC6BBA929"));
   GUIDS.push_back(VERSIONGUID("Tilia 2.0.23", "26E40BD2-9E7A-45C4-8C98-BB61DD9F94C2"));
   GUIDS.push_back(VERSIONGUID("Tilia 2.0.24", "45152670-AE8B-474E-B941-693BA1FB5A44"));
   GUIDS.push_back(VERSIONGUID("Tilia 2.0.25", "2DA2C752-15D7-4C01-B3B0-4A839A1C16D4"));
   GUIDS.push_back(VERSIONGUID("Tilia 2.0.26", "E56B8A53-E1A5-4CAB-8ACC-6CB291092B7E"));
   GUIDS.push_back(VERSIONGUID("Tilia 2.0.27", "FA1553A5-F19B-4844-91E3-1028BC4C5944"));
   GUIDS.push_back(VERSIONGUID("Tilia 2.0.28", "AD41B325-4679-4B13-81C7-73345494D8A4"));
   GUIDS.push_back(VERSIONGUID("Tilia 2.0.29", "537D0102-5811-4A93-9DA4-8E5911FBF1FF"));
   GUIDS.push_back(VERSIONGUID("Tilia 2.0.30", "80398AB8-20DC-43E6-87A1-E591CB47332E"));
   GUIDS.push_back(VERSIONGUID("Tilia 2.0.31", "86D4800B-94CF-4ADC-9103-FEA9FDFED79E"));
   GUIDS.push_back(VERSIONGUID("Tilia 2.0.32", "208CD653-4768-4474-A063-F767F03794E6"));
   GUIDS.push_back(VERSIONGUID("Tilia 2.0.33", "6BA925D9-EC56-4DA9-B99A-59D13226DF6B"));
   GUIDS.push_back(VERSIONGUID("Tilia 2.0.34", "FCF56726-7D95-4AE3-9C23-AC38A8AE3AB9"));
   GUIDS.push_back(VERSIONGUID("Tilia 2.0.35", "96148665-024B-4FF5-9118-C86C0994ECEA"));
   GUIDS.push_back(VERSIONGUID("Tilia 2.0.36", "FD2E2E5E-5432-471D-905A-3BBA87F97239"));
   GUIDS.push_back(VERSIONGUID("Tilia 2.0.37", "375002A1-1131-45FB-B839-DCA5D141A86E"));
   GUIDS.push_back(VERSIONGUID("Tilia 2.0.38", "679300BE-A8FB-40A7-989F-2A71C1984E64"));
   GUIDS.push_back(VERSIONGUID("Tilia 2.0.39", "78A34378-D96A-48AF-99DC-4A0C5156E6A8"));
   GUIDS.push_back(VERSIONGUID("Tilia 2.0.40", "4E12C8EB-80B3-462F-AC0D-F2EC7C66B1B9"));
   GUIDS.push_back(VERSIONGUID("Tilia 2.0.41", "825E88C5-632E-4F89-B13E-C077F99FA0FB"));
   GUIDS.push_back(VERSIONGUID("Tilia 2.0.42", "9104478D-4A01-459E-9A16-47028C717C88"));
   GUIDS.push_back(VERSIONGUID("Tilia 2.0.43", "C59DAFA1-6FF4-4351-8A5A-54414B4A2192"));
   GUIDS.push_back(VERSIONGUID("Tilia 2.0.44", "044ED968-0B50-4FFE-A765-B6E2D5621C3B"));
   GUIDS.push_back(VERSIONGUID("Tilia 2.0.45", "E6FD51FD-BA23-48FD-A7D3-120851544CFB"));
   GUIDS.push_back(VERSIONGUID("Tilia 2.0.46", "68722ECD-01D5-42AA-B943-D626090AE905"));
   GUIDS.push_back(VERSIONGUID("Tilia 2.0.47", "CAC30F92-82CB-4C03-9888-FF96FC470B2F"));
   GUIDS.push_back(VERSIONGUID("Tilia 2.0.48", "42955B15-DDA4-4ED7-AD41-C2155C6F41D7"));
   GUIDS.push_back(VERSIONGUID("Tilia 2.0.49", "0C635EE0-FE64-4A81-8D9F-136D3D704D2F"));
   GUIDS.push_back(VERSIONGUID("Tilia 2.0.50", "462E2445-3D75-4AED-AD54-DDAEA085B340"));
   GUIDS.push_back(VERSIONGUID("Tilia 2.0.51", "73E9008B-31B3-4F76-8DA1-A87322F1CA34"));
   GUIDS.push_back(VERSIONGUID("Tilia 2.0.52", "335EF123-5312-4BD3-BBE0-0FDD52D26494"));
   GUIDS.push_back(VERSIONGUID("Tilia 2.0.53", "D8B3D765-F8A1-4E3E-9D71-9DE4285EB1B2"));
   GUIDS.push_back(VERSIONGUID("Tilia 2.0.54", "14957D2D-4ABD-4613-8859-9E12C2B1CDDB"));
   GUIDS.push_back(VERSIONGUID("Tilia 2.0.55", "2CD4789A-1772-4B0C-A236-66C9844CA16E"));
   GUIDS.push_back(VERSIONGUID("Tilia 2.0.56", "B69EC226-EBD0-4DE6-9D80-ADD10A391480"));
   GUIDS.push_back(VERSIONGUID("Tilia 2.0.57", "A2FCCEBC-779F-4434-88C7-F3087AD3B07E"));
   GUIDS.push_back(VERSIONGUID("Tilia 2.0.58", "5E7450B8-98F8-4C5F-8EA1-29E85DF1EA46"));
   GUIDS.push_back(VERSIONGUID("Tilia 2.0.59", "0AFABCA7-822C-4561-BDE8-9041FF51BEBE"));
   GUIDS.push_back(VERSIONGUID("Tilia 2.0.60", "49C40BB2-E473-4E44-8A1E-52A00647A813"));
   GUIDS.push_back(VERSIONGUID("Tilia 2.0.61", "0E3A8319-3654-46AD-ACF0-D130369B2CD3"));
   GUIDS.push_back(VERSIONGUID("Tilia 2.0.62", "E27C0C32-7CA7-46DE-B574-5720EAE5FB63"));
   GUIDS.push_back(VERSIONGUID("Tilia 2.1.1",  "7F9ABE73-1A71-4090-A715-A7283BB72418"));
   GUIDS.push_back(VERSIONGUID("Tilia 2.2.1",  "9B59C91B-7E81-45AC-82C6-D79D25B378F3"));
   GUIDS.push_back(VERSIONGUID("Tilia 2.3.1",  "1C4C961B-F199-4866-A511-711A52BA274C"));
   GUIDS.push_back(VERSIONGUID("Tilia 2.4.1",  "D3A9F3C7-0C5A-439D-8E0E-B0F46FA7E7DA"));
   GUIDS.push_back(VERSIONGUID("Tilia 2.5.1",  "46ACF5B8-833C-4223-9ED0-5B796CB498F6"));
   GUIDS.push_back(VERSIONGUID("Tilia 2.5.2",  "11AF1DD4-A01C-4C49-83D2-6B915AC0086F"));
   GUIDS.push_back(VERSIONGUID("Tilia 2.6.1",  "88FFA256-A7C1-46C4-9293-18BF303B49D3"));
   GUIDS.push_back(VERSIONGUID("Tilia 2.7.1",  "137358AE-6733-462B-98FB-694AD14AE803"));
   GUIDS.push_back(VERSIONGUID("Tilia 2.8.1",  "0940F7D7-796E-438A-AC04-8308BE37A6E8"));
   GUIDS.push_back(VERSIONGUID("Tilia 2.9.1",  "8EC094A4-6206-4300-B72B-7A14D64DB673"));
   GUIDS.push_back(VERSIONGUID("Tilia 3.0.1",  "86732A40-514B-4E86-A0EB-881F6FD5AEC0"));
}
//---------------------------------------------------------------------------

// gets called from Splash unit
bool TILIALICENSE::ValidateProductKey(void)
{
   UnicodeString Key, DateStr;

   Owner.SetLength(0);
   ProductKey.SetLength(0);

   UnicodeString Path = tiGlobals->AppDataTiliaPath;
   if (!Path.IsEmpty()) {
	 if (!AppDataTiliaPathExists()) {
	   MessageDlg(L"Error accessing %CSIDL_COMMON_APPDATA%\\Tilia", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return false;
	   }
	 Path += L"Tilia.INI";

	 if (FileExists(Path)) {
	   TIniFile *SettingsFile = new TIniFile(Path);
	   bool error = false;
	   try {
		   Owner = SettingsFile->ReadString(L"Registration", L"Owner", Owner);
		   ProductKey = SettingsFile->ReadString(L"Registration", L"ProductKey", ProductKey);
		   Hash = SettingsFile->ReadString(L"Registration", L"Hash", Hash);
		   }
	   catch(Exception &e) {
		   MessageDlg(e.Message, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   error = true;
		   }
	   delete SettingsFile;
	   if (error)
		 return false;
	   }
	 else {
	   if (!Register())
	   	 return false;
	   }
	 }
   else {
	 MessageDlg(L"Error accessing %CSIDL_COMMON_APPDATA%\\Tilia", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 return false;
	 }

   /*
   if (ProductKey == "verFREE") {
	 LicenseType = verFREE;
	 return true;
	 }
   */

   if (Owner.IsEmpty() || ProductKey.IsEmpty()) {    // not in Tilia.INI
	 if (!Register()) {
	   MessageDlg("Product not validated!", mtInformation, TMsgDlgButtons() << mbOK, 0);
	   return false;
	   }
	 }

   Key = ProductKey;

   Encryption Encrypt(Owner);
   if (ProductKey == "verFREE") {
	 LicenseType = verFREE;
	 Key = GUIDS[1].GUID;
	 }
   else {
	 // Encryption Encrypt(Owner);
	 if (Encrypt.Decrypt(Key)) {    // converts hex key to GUID
	   ParseProductKey(LicenseType, Key, DateStr);
	   if (!DateStr.IsEmpty()) {    // validate expiration date
		 TDateTime expiration_date = GetExpirationDate(DateStr, ExpirationDate);
		 if (CompareDate(expiration_date, Today()) == LessThanValue) {
		   if (!Register()) {
			 return false;
			 }
		   }
		 }
	   }
	 else {
	   MessageDlg("Product Key invalid.", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   if (!Register())
		return false;
	   }
	 }

   UnicodeString Prefix;
   //if (LicenseType == verLEGACY || LicenseType == verPROFESSIONAL ||
   //	 LicenseType == verMULTIUSE || LicenseType == verNEOTOMASTEWARD) {
	 if (Key != GUIDS.back().GUID) {  // check for previous registrations of Tilia
	   for (unsigned int i=1; i<GUIDS.size()-1; i++) {
		 if (Key == GUIDS[i].GUID) {
		   Key = GUIDS.back().GUID;
		   switch (LicenseType) {
			 case verPROFESSIONAL:
			 case verLEGACY:
			   Key.Insert("P:",1);
			   break;
			 case verMULTIUSE:
			   Key.Insert("M:",1);
			   break;
			 case verNEOTOMASTEWARD:
			   Key.Insert("N:",1);
			   break;
			 case verFREE:
			   Key.Insert("F:",1);
			   break;
			 case verSTUDENT:
			   Prefix = "S:" + DateStr + ":";
			   Key.Insert(Prefix,1);
			   break;
			 case verTRAINING:
			   Prefix = "T:" + DateStr + ":";
			   Key.Insert(Prefix,1);
			   break;
			 }
		   Encrypt.Encrypt(Key);
		   ProductKey = Key;
		   UpgradeRegistration(i, Owner, ProductKey);
		   break;
		   }
		 }
	   }
	 //  }
	// }

   return true;
}
//---------------------------------------------------------------------------

bool TILIALICENSE::AppDataTiliaPathExists(void)
{
   UnicodeString Dir = tiGlobals->AppDataTiliaPath;
   Dir.Delete(Dir.Length(),1);
   if (!DirectoryExists(Dir)) {
	 if (!CreateDir(Dir))
	   return false;
	 }
   return true;
}
//---------------------------------------------------------------------------

/*
void TILIALICENSE::RegisterFreeVersion(UnicodeString& Owner)
{
   ProductKey = "verFREE";

   UnicodeString Path = tiGlobals->AppDataTiliaPath;
   if (!Path.IsEmpty()) {
     if (!AppDataTiliaPathExists()) {
	   MessageDlg(L"Error accessing %CSIDL_COMMON_APPDATA%\\Tilia", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   }
	 Path += L"Tilia.INI";
	 TIniFile *SettingsFile = new TIniFile(Path);   // here's the fuck up
	 try {
		 SettingsFile->WriteString(L"Registration", L"Owner", Owner);
		 SettingsFile->WriteString(L"Registration", L"ProductKey", ProductKey);
		 MessageDlg("Free version of Tilia successfully registered!", mtInformation, TMsgDlgButtons() << mbOK, 0);
		 }
	 catch(Exception &e) {
		 MessageDlg(e.Message, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 }
	 delete SettingsFile;
	 }
   else {
	 MessageDlg(L"Error accessing %CSIDL_COMMON_APPDATA%\\Tilia", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 }
}
//---------------------------------------------------------------------------
*/

void TILIALICENSE::ParseProductKey(short& lt, UnicodeString& Key, UnicodeString& DateStr)
{
   DateStr.SetLength(0);
   if (Key.Length() < 36) {
	 lt = verFREE;
	 return;
	 }
   if (Key[2] != ':') {
	 lt = verLEGACY;
	 return;
	 }
   switch (Key[1]) {
	 case 'S':
	   lt = verSTUDENT;
	   DateStr = Key.SubString(3,6);
	   Key.Delete(1,9);
	   break;
	 case 'T':
	   lt = verTRAINING;
	   DateStr = Key.SubString(3,6);
	   Key.Delete(1,9);
	   break;
	 case 'L':
	   lt = verPROFESSIONAL;
	   Key.Delete(1,2);
	   break;
	 case 'P':
	   lt = verPROFESSIONAL;
	   Key.Delete(1,2);
	   break;
	 case 'M':
	   lt = verMULTIUSE;
	   Key.Delete(1,2);
	   break;
	 case 'N':
	   lt = verNEOTOMASTEWARD;
	   Key.Delete(1,2);
	   break;
	 case 'F':
	   lt = verFREE;
	   Key.Delete(1,2);
	   break;
	 default:
	   lt = verFREE;
	   break;
	 }
}
//---------------------------------------------------------------------------

TDateTime TILIALICENSE::GetExpirationDate(UnicodeString DateStr, UnicodeString& ExpirationDate)
{
   UnicodeString yrstr = "20" + DateStr.SubString(1,2);
   short year = StrToInt(yrstr);
   short month = StrToInt(DateStr.SubString(3,2));
   short day = StrToInt(DateStr.SubString(5,2));
   TDateTime expiration_date(year, month, day);
   DateTimeToString(ExpirationDate, L"dd-mmm-yyyy", expiration_date);
   return expiration_date;
}
//---------------------------------------------------------------------------

void TILIALICENSE::UpgradeRegistration(unsigned int OldVersion, UnicodeString& Owner, UnicodeString& ProductKey)
{
   UnicodeString Path = tiGlobals->AppDataTiliaPath;
   if (!Path.IsEmpty()) {
	 Path += L"Tilia.INI";
	 TIniFile *SettingsFile = new TIniFile(Path);
	 try {
		 SetOwner(Owner);  // sets Hash if empty
		 SettingsFile->WriteString(L"Registration", L"Owner", Owner);
		 SettingsFile->WriteString(L"Registration", L"ProductKey", ProductKey);
		 SettingsFile->WriteString(L"Registration", L"Hash", Hash);
		 UnicodeString msg = "Registration upgraded from " + GUIDS[OldVersion].VERSION +
		   " to " + GUIDS.back().VERSION + ".";
		 MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
		 tiGlobals->MyLookupPath = tiGlobals->AppDataTiliaLookupPath;
		 }
	 catch(Exception &e) {
		 MessageDlg(e.Message, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 }
	 delete SettingsFile;
	 }
   else {
	 MessageDlg(L"Error accessing %CSIDL_COMMON_APPDATA%\\Tilia", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 }
}
//---------------------------------------------------------------------------

bool TILIALICENSE::Register(void)
{
	bool rv = false;
	TRegistrationForm* RegForm = new TRegistrationForm(Owner, ProductKey, Application);
	int result = RegForm->ShowModal();
	if (result == mrOk) {
	  Owner = RegForm->GetProductOwner();
	  ProductKey = RegForm->GetProductKey();
	  rv = true;
	  }
	delete RegForm;
	return rv;
}
//---------------------------------------------------------------------------

void TILIALICENSE::SetOwner(UnicodeString owner)
{
   Owner = owner;

   if (Hash.IsEmpty()) {
	 UnicodeString HexChars = L"0123456789abcdef";
	 Randomize();
	 for (int i = 0; i < 32; i++) {
	   int idx = Random(16) + 1;
	   Hash += UnicodeString(HexChars[idx]);
	   }
	 }
}
//---------------------------------------------------------------------------

VERSION::VERSION(UnicodeString version)
{
   SetVersion(version);
}
//---------------------------------------------------------------------------

void VERSION::SetVersion(UnicodeString version)
{
   int pos;
   UnicodeString Version = version;

   if ((pos = Version.Pos(".")) > 0) {
     Major = Version.SubString(1, pos-1).ToInt();
     Version.Delete(1, pos);
	 if ((pos = Version.Pos(".")) > 0) {
       Minor = Version.SubString(1, pos-1).ToInt();
       Version.Delete(1, pos);
	   if ((pos = Version.Pos(".")) > 0) {
         Release = Version.SubString(1, pos-1).ToInt();
         Version.Delete(1, pos);
         if (Version.Length())
           Build = Version.ToInt();
         }
       }
     }
}
//---------------------------------------------------------------------------

bool VERSION::operator > (const VERSION& compare )
{
   if (this == &compare) return false;

   if (Major > compare.Major)
     return true;
   if (Major < compare.Major)
     return false;
   if (Minor > compare.Minor)   // Major == compare.Major)
     return true;
   if (Minor < compare.Minor)
     return false;
   if (Release > compare.Release)   // Minor == compare.Minor
     return true;
   else
     return false;   // Release <= compare.Release
}
//---------------------------------------------------------------------------

bool VERSION::operator >= (const VERSION& compare )
{
   if (Major == compare.Major && Minor == compare.Minor && Release == compare.Release)
     return true;
   if (Major > compare.Major)
     return true;
   if (Major < compare.Major)
     return false;
   if (Minor > compare.Minor)   // Major == compare.Major)
     return true;
   if (Minor < compare.Minor)
     return false;
   if (Release > compare.Release)   // Minor == compare.Minor
     return true;
   else
     return false;   // Release <= compare.Release
}
//---------------------------------------------------------------------------

bool VERSION::operator < (const VERSION& compare )
{
   if (this == &compare) return false;

   if (Major < compare.Major)
     return true;
   if (Major > compare.Major)
     return false;
   if (Minor < compare.Minor)   // Major == compare.Major)
     return true;
   if (Minor > compare.Minor)
     return false;
   if (Release < compare.Release)   // Minor == compare.Minor
     return true;
   else
     return false;   // Release >= compare.Release
}
//---------------------------------------------------------------------------

bool VERSION::operator == (const VERSION& compare )
{
   if (Major == compare.Major && Minor == compare.Minor && Release == compare.Release)
     return true;
   else
     return false;  
}
//---------------------------------------------------------------------------

UnicodeString VERSION::Version(void) const
{
   return (IntToStr(Major) + "." + IntToStr(Minor) + "." + IntToStr(Release));
}
//---------------------------------------------------------------------------

CURRENTVERSION::CURRENTVERSION()
{
   UnicodeString ExeName = Application->ExeName;
   DWORD n = GetFileVersionInfoSize(ExeName.c_str(), &n);
   if (n > 0) {
     LPVOID *pBuf = new LPVOID [n];
     LPVOID pValue;
     unsigned int Len;
	 GetFileVersionInfo(ExeName.w_str(), 0, n, pBuf);
	 VerQueryValue(pBuf, TEXT("\\StringFileInfo\\040904E4\\FileVersion"), &pValue, &Len);
	 SetVersion(UnicodeString((Char*)(pValue)));
     delete[] pBuf;
	 }
}
//---------------------------------------------------------------------------


