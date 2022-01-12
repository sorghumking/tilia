//---------------------------------------------------------------------------

#ifndef TINeotomaH
#define TINeotomaH
//---------------------------------------------------------------------------
#include <vector>
#include <map>
#include "ipshttps.h"
#include "ipsjsons.h"
#include "ipwjson.h"
#include "cxTextEdit.hpp"
#include "cxCheckBox.hpp"
#include "cxCheckListBox.hpp"
#include <Sockets.hpp>
#include <ComCtrls.hpp>
#ifndef TIGlobalsH
#include "TIGlobals.h"
#endif
#ifndef TIJSONH
#include "TIJSON.h"
#endif

//---------------------------------------------------------------------------
enum NEOTOMAGEOPOLIDS { NTM_COUNTRY, NTM_STATE, NTM_COUNTY, NTM_ADMINUNIT };
//---------------------------------------------------------------------------

class NEOTOMALOGIN
{
private:
	bool FLoggedIn;
	bool RememberMe;
	int FContactID;
	bool FTaxonomyExpert;
	ConstituentDatabases *FDatabases;
public:
	UnicodeString UserName;
	UnicodeString Password;
	int DatabaseID;
public:
	NEOTOMALOGIN();
	~NEOTOMALOGIN();
	//bool IsLoggedIn(void) { return LoggedIn; }
	void Setup(TcxTextEdit* InputUserName, TcxTextEdit* InputPassword,
		TcxCheckBox* remember_me);
	bool Execute(UnicodeString user_name, UnicodeString password,
		bool remember_me, TcxCheckListBox* cxCheckListBox, // TipsJSONS *ipsJSONS,
		TipsJSONS *ipsjsons, TTcpClient *TcpClient, TPanel *StatusBar);
	void SetDatabaseID(UnicodeString DatabaseName);
	void Logout(void) { FLoggedIn = false; };
	__property bool IsLoggedIn = {read = FLoggedIn};
	__property int ContactID = {read = FContactID};
	__property bool IsTaxonomyExpert = {read = FTaxonomyExpert};
	__property ConstituentDatabases* Databases = {read = FDatabases};
};
//---------------------------------------------------------------------------

class NeotomaPut
{
protected:
	TipsHTTPS* ipsHTTPS;
	TipsJSONS* ipsJSONS;
	UnicodeString url;
protected:
	bool PostURL(UnicodeString url, vector<int>& newids, UnicodeString& ErrorMsg);
	bool PostURL(UnicodeString url, UnicodeString& ErrorMsg);
	EncodeURL encode_url;
private:
	TTcpClient* TcpClient;
	UnicodeString OtherHeaders;
private:
	void __fastcall ipsHTTPS1Error(TObject *Sender, TipsHTTPSErrorEventParams *e);
	void __fastcall ipsJSONS1Error(TObject *Sender, TipsJSONSErrorEventParams *e);
	bool ParseUploadResponse(vector<int>& newids, UnicodeString& ErrorMsg);
	bool ParseUploadResponse(UnicodeString& ErrorMsg);
	void ResetJSONParser(void);
public:
	NeotomaPut(TipsHTTPS*, TipsJSONS*, TTcpClient*);
	__property UnicodeString URL = {read = url};
};
//---------------------------------------------------------------------------

class RetrieveURL
{
protected:
	UnicodeString url;
private:
	void EncodeSpace(UnicodeString& value);
public:
	RetrieveURL() { }
	RetrieveURL(UnicodeString method);
	void Add(UnicodeString name, UnicodeString value);
	UnicodeString URL(void) { return url; }
};
//---------------------------------------------------------------------------

class RetrieveSecureURL : public RetrieveURL
{
public:
	RetrieveSecureURL(UnicodeString method);
};
//---------------------------------------------------------------------------

// class for inserting new records into Neotoma
// nparams is the number of parameters per record
class InsertData : public NeotomaPut
{
private:
	int nrecs;
	int nparams;
	int maxparams;
	int n;
	UnicodeString record;
	//UnicodeString postdata;
	UTF8String postdata;
	vector<UnicodeString> Params;
private:
	void Append(UnicodeString name, UnicodeString value);
	void EndRecord(void);
public:
	InsertData(UnicodeString method, int np, TipsHTTPS* ipshttps,
		TipsJSONS* ipwjsons, TTcpClient* tcpclient);
	void Add(UnicodeString name, UnicodeString value);
	void Add(UnicodeString name, int value);
	void Add(UnicodeString name, int value, int null_value);
	void Add(UnicodeString name, bool value);
	void Add(UnicodeString name, double value);
	void AddDouble(UnicodeString name, Variant value);
	void AddInt(UnicodeString name, Variant value);
	void PostData(void);
	bool Post(vector<int>& newids, UnicodeString& ErrorMsg);
	bool Post(UnicodeString& ErrorMsg);  // for tables without a single primary key
	// __property UnicodeString POSTDATA = {read = postdata};
	int Length(void) { return postdata.Length(); }
};
//---------------------------------------------------------------------------

// #ifdef TSTESTING
class UpdateData : public InsertData
{
public:
	UpdateData(UnicodeString method, int np, TipsHTTPS* ipshttps, TipsJSONS* ipsjsons, TTcpClient* tcpclient);
	bool Post(UnicodeString& ErrorMsg);
};
/*
#else
class UpdateData : public NeotomaPut
{
private:
	void Append(UnicodeString name, UnicodeString value);
public:
	UpdateData(UnicodeString method, int np, TipsHTTPS* ipshttps, TipsJSONS* ipwjson, TTcpClient* tcpclient);
	void Add(UnicodeString name, UnicodeString value);
	void Add(UnicodeString name, int value);
	void Add(UnicodeString name, int value, int null_value);
	void Add(UnicodeString name, bool value);
	void Add(UnicodeString name, double value);
	void AddDouble(UnicodeString name, Variant value);
	void AddInt(UnicodeString name, Variant value);
	bool Post(UnicodeString& ErrorMsg);
};
#endif
*/
//---------------------------------------------------------------------------

// #ifdef TSTESTING
class DeleteData : public InsertData
{
public:
	DeleteData(UnicodeString method, int np, TipsHTTPS* ipshttps, TipsJSONS* ipwjson, TTcpClient* tcpclient);
	bool Post(UnicodeString& ErrorMsg);
};
/*
#else
class DeleteData : public NeotomaPut
{
public:
	DeleteData(UnicodeString method, int np, TipsHTTPS* ipshttps, TipsJSONS* ipwjson, TTcpClient* tcpclient);
	void Add(UnicodeString name, UnicodeString value);
	void Add(UnicodeString name, int value);
	bool Post(UnicodeString& ErrorMsg);
};
#endif
*/
//---------------------------------------------------------------------------
extern NEOTOMALOGIN *Login;
//---------------------------------------------------------------------------

#endif
