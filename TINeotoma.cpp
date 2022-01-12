//---------------------------------------------------------------------------
#include <vcl.h>
#include "pch.h"
#pragma hdrstop

#include "TINeotoma.h"
#ifndef TIShoMemH
#include "TIShoMem.h"
#endif
#ifndef TIXMLH
#include "TIXML.h"
#endif
#ifndef TIVersionH
#include "TIVersion.h"
#endif

//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
NEOTOMALOGIN *Login;
//---------------------------------------------------------------------------

NEOTOMALOGIN::NEOTOMALOGIN()
{
   FLoggedIn = false;
   FTaxonomyExpert = false;
   UserName = tiGlobals->NeotomaUserName;
   RememberMe = tiGlobals->NeotomaRememberMe;
   FDatabases = NULL;
};
//---------------------------------------------------------------------------

NEOTOMALOGIN::~NEOTOMALOGIN()
{
   if (FDatabases)
	 delete FDatabases;
}
//---------------------------------------------------------------------------

void NEOTOMALOGIN::Setup(TcxTextEdit* InputUserName, TcxTextEdit* InputPassword, TcxCheckBox* remember_me)
{
   if (!UserName.IsEmpty()) {
	 InputUserName->Text = UserName;
	 if (!Password.IsEmpty())
	   InputPassword->Text = Password;
	 }
   remember_me->Checked = RememberMe;
}
//---------------------------------------------------------------------------

bool NEOTOMALOGIN::Execute(UnicodeString user_name, UnicodeString password,
	bool remember_me, TcxCheckListBox* cxCheckListBox, // TipsJSONS *ipsJSONS,
	TipsJSONS *ipsJSONS, TTcpClient *TcpClient, TPanel *StatusBar)
{
   bool error = false;
   // validate user name
   ValidateUserName validate_user_name(ipsJSONS, TcpClient);
   validate_user_name.AddParam(L"USERNAME", user_name);

   StatusBar->Caption = validate_user_name.WebServiceName();
   Screen->Cursor = crHourGlass;
   if (validate_user_name.Execute()) {
	 if (validate_user_name.Items.size() == 0) {
	   UnicodeString msg = user_name + L" is not a valid User Name";
	   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   error = true;
	   }
	 }
   else {
	 error = true;
	 MessageDlg(L"Cannot validate user name", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 }

   // validate password
   if (!error) {
	 ValidatedDatabases Validated(ipsJSONS, TcpClient);
	 Validated.AddParam(L"USERNAME", user_name);
	 Validated.AddParam(L"PWD", password);
	 StatusBar->Caption = Validated.WebServiceName();

	 if (Validated.Execute()) {
	   if (Validated.Size() == 0) {
		 MessageDlg(L"Invalid password!", Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		 error = true;
		 }
	   else {
		 if (FDatabases) {
		   delete FDatabases;
		   FDatabases = NULL;
		   }
		 FDatabases = new ConstituentDatabases(ipsJSONS, TcpClient);
		 StatusBar->Caption = FDatabases->WebServiceName();
		 if (FDatabases->Execute()) {
		   cxCheckListBox->Clear();
		   for (unsigned int i=0; i<Validated.Items.size(); i++) {
			 TcxCheckListBoxItem* Item = cxCheckListBox->Items->Add();
			 Item->Text = FDatabases->Items[Validated.Items[i]];
			 }
		   cxCheckListBox->Sort();
		   if (cxCheckListBox->Count == 1)
			 cxCheckListBox->Items->Items[0]->Checked = true;
		   }
		 else
		   error = true;
		 }
	   }
	 else
	   error = true;
	 }

   StatusBar->Caption = L"";

   if (!error) {
	 if (remember_me != RememberMe)
	   tiGlobals->NeotomaRememberMe = remember_me;
	 if (remember_me) {
	   if (user_name != UserName)
		 tiGlobals->NeotomaUserName = user_name;
	   }
	 else
	   tiGlobals->NeotomaUserName = L"";

	 UserName = user_name;
	 map<int,bool>::iterator itr = validate_user_name.Items.begin();
	 FContactID = itr->first;
	 FTaxonomyExpert = itr->second;
	 Password = password;
	 RememberMe = remember_me;
	 FLoggedIn = true;
	 }
   else {
	 FLoggedIn = false;
	 }

   Screen->Cursor = crDefault;
   return !error;
}
//---------------------------------------------------------------------------

void NEOTOMALOGIN::SetDatabaseID(UnicodeString DatabaseName)
{
   map<int, UnicodeString>::iterator itr;
   map<int, UnicodeString>::iterator begin = FDatabases->Items.begin();
   map<int, UnicodeString>::iterator end = FDatabases->Items.end();
   for (itr=begin; itr != end; itr++) {
	 if (itr->second == DatabaseName) {
	   Login->DatabaseID = itr->first;
	   break;
	   }
	 }
}
//---------------------------------------------------------------------------

NeotomaPut::NeotomaPut(TipsHTTPS* ipshttps, TipsJSONS* ipsjsons, TTcpClient* tcpclient)
{
   ipsHTTPS = ipshttps;
   ipsJSONS = ipsjsons;
   TcpClient = tcpclient;


   //OtherHeaders = L"username:" + Login->UserName + L"\r\npwd:" + L"football" +
   //				  L"\r\nconstituentDatabase:" + IntToStr(Login->DatabaseID);
   //OtherHeaders = L"username:" + Login->UserName + L"\r\npwd:" + Login->Password +
   //				  L"\r\nconstituentDatabase:" + IntToStr(Login->DatabaseID);

	 // configure the IP*Works! JSON Component for uploading data to Neotoma
	 // ipsJSONS->Reset();

   CURRENTVERSION CurrentVersion;
   // UnicodeString UserAgent = L"UserAgent=Tilia " + CurrentVersion.Version();
   UnicodeString UserAgent = L"UserAgent={\"program\":\"Tilia\",\"version\":\"" +
	  CurrentVersion.Version() + L"\",\"hash\":\"" + tiLicense->GetHash() + L"\"}";

   ipsHTTPS->ResetHeaders();
   ipsHTTPS->OnError = ipsHTTPS1Error;

   UnicodeString cert = "MIIEFjCCAv6gAwIBAgICIncwDQYJKoZIhvcNAQELBQAwgb8xCzAJBgNVBAYTAi0t";
   cert += L"MRIwEAYDVQQIDAlTb21lU3RhdGUxETAPBgNVBAcMCFNvbWVDaXR5MRkwFwYDVQQK";
   cert += L"DBBTb21lT3JnYW5pemF0aW9uMR8wHQYDVQQLDBZTb21lT3JnYW5pemF0aW9uYWxV";
   cert += L"bml0MSAwHgYDVQQDDBd1dGlsd3d3LWVlZC5lbXMucHN1LmVkdTErMCkGCSqGSIb3";
   cert += L"DQEJARYccm9vdEB1dGlsd3d3LWVlZC5lbXMucHN1LmVkdTAeFw0xNDA5MTIxNzQ3";
   cert += L"NDRaFw0xNTA5MTIxNzQ3NDRaMIG/MQswCQYDVQQGEwItLTESMBAGA1UECAwJU29t";
   cert += L"ZVN0YXRlMREwDwYDVQQHDAhTb21lQ2l0eTEZMBcGA1UECgwQU29tZU9yZ2FuaXph";
   cert += L"dGlvbjEfMB0GA1UECwwWU29tZU9yZ2FuaXphdGlvbmFsVW5pdDEgMB4GA1UEAwwX";
   cert += L"dXRpbHd3dy1lZWQuZW1zLnBzdS5lZHUxKzApBgkqhkiG9w0BCQEWHHJvb3RAdXRp";
   cert += L"bHd3dy1lZWQuZW1zLnBzdS5lZHUwggEiMA0GCSqGSIb3DQEBAQUAA4IBDwAwggEK";
   cert += L"AoIBAQDE4Ua+P2BmRiwSBI6LFbDJZryQMj5FCc3Nvx2G4G/5VmdpRZE5uNNJqrcs";
   cert += L"J6c41UW2hDaNF98GoqILJrSWvmBbWfcyqYEtmBCiy2BQP9mnkmEUprnlo7CV4YbA";
   cert += L"c1s82PyPb/AhaZDNJpjN/3eWDICzG0xIuFnJFgnYjUCi9UDl1+aZjDfhoz/1bzBw";
   cert += L"+13n75uOSKsR7/fbF///vyYAKiWa4rvrcnSuUNiG83WehgpyYK4OFZ5Lf4UmJwH/";
   cert += L"3cc8oNOqwcm7eKG1UXdZg8s4WhKWDz4XR8sYp/EocnrNUFGbI6tguOFhUdDu2jSx";
   cert += L"+nDhhUSkpkX2/I4dH1BgrcBGXRjzAgMBAAGjGjAYMAkGA1UdEwQCMAAwCwYDVR0P";
   cert += L"BAQDAgXgMA0GCSqGSIb3DQEBCwUAA4IBAQAYfHIypYa/fE8yve4zkGOlicI+CrPP";
   cert += L"eg43JcM/UiS7qYz+dmPULcSgzwx83Jhin4E886HZnQSY2ONTApfIyNSohG2rFtrC";
   cert += L"VYTvvVIrry6Xkw19wfp4vXSH3NLQX73uu0CQ2aHB2ImGCzSJ9lMsFt5z4SuGzVW/";
   cert += L"DiLHw6CUSCjq7B0Mp3N8s3qJswK2pSkM/DkuHlLX0ATG5rWMuVmL7EPo/AxMIbVH";
   cert += L"j6VyIBfqomlzgaqPxfs2fHqExxkTFoyNmcFjK3gdB1ZkYZvQlggF8shoqkN2tHbg";
   cert += L"2pdVerkYGk2KpzwdIkwNxZHO06TwiqAWcoJMLHH63EIc+3G2uzb+mbt+";
   ipsHTTPS->SSLAcceptServerCertEncoded = cert;

   ipsHTTPS->Config("KeepAlive=true");
   ipsHTTPS->Config("CodePage=65001");   // UTF-8 CodePage
   ipsHTTPS->Config("SSLEnabledProtocols=3072");  // 4032
   ipsHTTPS->Config(UserAgent);
   ipsHTTPS->ContentType = L"application/json";
   ipsHTTPS->User = Login->UserName;
   ipsHTTPS->Password = Login->Password;
   ipsHTTPS->LocalHost = TcpClient->LocalHostAddr();
   ipsHTTPS->TransferredDataLimit = 0;
   ipsHTTPS->Timeout = tiGlobals->InternetTimeout;
   //OtherHeaders = L"username:" + Login->UserName + L"\r\npwd:" + Login->Password+
   //				L"\r\nconstituentDatabase:" + IntToStr(Login->DatabaseID);
   OtherHeaders = L"username:" + Login->UserName + L"\r\npwd:" + Login->Password;
   ipsHTTPS->OtherHeaders = OtherHeaders;

   /*
   else {  // SQL Server
	 // configure the IP*Works! HTTPS Component for uploading data to Neotoma
	 ipsHTTPS->ResetHeaders();
	 ipsHTTPS->Config("KeepAlive=true");
	 ipsHTTPS->Config("CodePage=65001");   // UTF-8 CodePage
	 ipsHTTPS->LocalHost = TcpClient->LocalHostAddr();
	 ipsHTTPS->TransferredDataLimit = 0;
	 ipsHTTPS->Timeout = tiGlobals->InternetTimeout;
	 OtherHeaders = L"username:" + Login->UserName + L"\r\npwd:" + Login->Password +
					L"\r\nconstituentDatabase:" + IntToStr(Login->DatabaseID);
	 ipsHTTPS->OtherHeaders = OtherHeaders;
	 ipsHTTPS->OnError = ipsHTTPS1Error;
	 }
   */
   //ShowMemoForm = new TShowMemoForm(L"OtherHeaders", OtherHeaders, NULL);
   //ShowMemoForm->ShowModal();
   //delete ShowMemoForm;

}
//---------------------------------------------------------------------------

void __fastcall NeotomaPut::ipsHTTPS1Error(TObject *Sender, TipsHTTPSErrorEventParams *e)
{
   UnicodeString msg = L"Error Code " + IntToStr(e->ErrorCode) + L": " + e->Description;
   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
}
//---------------------------------------------------------------------------

void __fastcall NeotomaPut::ipsJSONS1Error(TObject *Sender, TipsJSONSErrorEventParams *e)
{
   UnicodeString msg = L"Error Code " + IntToStr(e->ErrorCode) + L": " + e->Description;
   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
}
//---------------------------------------------------------------------------

bool NeotomaPut::PostURL(UnicodeString URL, vector<int>& newids, UnicodeString& ErrorMsg)
{
   bool rv;
   try {
	   //if (ContainsText(ipsHTTPS->PostData,L"insertdata")) {
		 //ShowMemoForm = new TShowMemoForm(L"URL", URL, NULL);
		 //ShowMemoForm->ShowModal();
		 //delete ShowMemoForm;

		 //ShowMemoForm = new TShowMemoForm(L"UserAgent", ipsHTTPS->Config("UserAgent"), NULL);
		 //ShowMemoForm->ShowModal();
		 //delete ShowMemoForm;

		 //ShowMemoForm = new TShowMemoForm(L"Other Headers", ipsHTTPS->OtherHeaders, NULL);
		 //ShowMemoForm->ShowModal();
		 //delete ShowMemoForm;

		 //ShowMemoForm = new TShowMemoForm(L"PostData", ipsHTTPS->PostData, NULL);
		 //ShowMemoForm->ShowModal();
		 //delete ShowMemoForm;
		 //}


	   ipsHTTPS->Post(URL);
	   rv = ParseUploadResponse(newids, ErrorMsg);
	   }
   catch (const Exception &e) {
	   ErrorMsg = e.Message;
	   rv = false;
	   }
   return rv;
}
//---------------------------------------------------------------------------

bool NeotomaPut::PostURL(UnicodeString URL, UnicodeString& ErrorMsg)
{
   bool rv;

   //UnicodeString msg = URL + L"\n" + ipsHTTPS->PostData;
   //ShowMemoForm = new TShowMemoForm(L"POST", msg, NULL);
   //ShowMemoForm->ShowModal();
   //delete ShowMemoForm;
		 /*
		 ShowMemoForm = new TShowMemoForm(L"URL", URL, NULL);
		 ShowMemoForm->ShowModal();
		 delete ShowMemoForm;

		 ShowMemoForm = new TShowMemoForm(L"UserAgent", ipsHTTPS->Config("UserAgent"), NULL);
		 ShowMemoForm->ShowModal();
		 delete ShowMemoForm;

		 ShowMemoForm = new TShowMemoForm(L"Other Headers", ipsHTTPS->OtherHeaders, NULL);
		 ShowMemoForm->ShowModal();
		 delete ShowMemoForm;

		 ShowMemoForm = new TShowMemoForm(L"PostData", ipsHTTPS->PostData, NULL);
		 ShowMemoForm->ShowModal();
		 delete ShowMemoForm;
         */
   try {
	   ipsHTTPS->Post(URL);
	   rv = ParseUploadResponse(ErrorMsg);
	   }
   catch (const Exception &e) {
	   //ShowMessage(L"Breakpoint 2");
	   ErrorMsg = e.Message;
	   rv = false;
	   }
   return rv;
}
//---------------------------------------------------------------------------

bool NeotomaPut::ParseUploadResponse(UnicodeString& ErrorMsg)
{
   //if (tiGlobals->RDMS == SQLServer) {
	 ResetJSONParser();
	 ipsJSONS->Input(ipsHTTPS->TransferredData);
   //	 }

   //ShowMemoForm = new TShowMemoForm(L"TransferredData", ipsHTTPS->TransferredData, NULL);
   //ShowMemoForm->ShowModal();
   //delete ShowMemoForm;

   /*
   {"status":"success","data":[null],"message":"Called batch 1 times for method ts.insertnewdatasetpi"}
   */

   ipsJSONS->XPath = "/json/status";
   UnicodeString success = ipsJSONS->XText;
   success = StripTextQuotes(success);
   if (!SameText(success,L"success")) {
	 ipsJSONS->XPath = "/json/message";
	 ErrorMsg = ipsJSONS->XText;
	 return false;
	 }

   /*
   else {
	 ipsJSONS->XPath = L"/json/success/";
	 int success;
	 if (!TryStrToInt(ipsJSONS->XText, success))
	   return false;
	 if (!success) {
	   ipsJSONS->XPath = L"/json/message/";
	   ErrorMsg = ipsJSONS->XText;
	   return false;
	   }
	 }
   */
   return true;
}
//---------------------------------------------------------------------------

bool NeotomaPut::ParseUploadResponse(vector<int>& newids, UnicodeString& ErrorMsg)
{
   //ShowMemoForm = new TShowMemoForm(L"TransferredData", ipsHTTPS->TransferredData, NULL);
   //ShowMemoForm->ShowModal();
   //delete ShowMemoForm;

   newids.clear();
   ResetJSONParser();
   ipsJSONS->Input(ipsHTTPS->TransferredData);

   ipsJSONS->XPath = "/json/status";
   UnicodeString success = ipsJSONS->XText;
   success = StripTextQuotes(success);
   if (!SameText(success,L"success")) {
	 ipsJSONS->XPath = "/json/message";
	 ErrorMsg = ipsJSONS->XText;
	 return false;
	 }

   /*
   else {
	 ipsJSONS->XPath = L"/json/success/";
	 int success;
	 if (!TryStrToInt(ipsJSONS->XText, success))
	   return false;
	 if (!success) {
	   ipsJSONS->XPath = L"/json/message/";
	   ErrorMsg = ipsJSONS->XText;
	   return false;
	   }
	 }
   */
/*
{"status":"success","data":[{"insertvariableunits":208}],"message":"Called Method ts.insertvariableunits"}

{
  "status": "success",
  "data": [
	{
	  "insertvariableunits": 208
	}
  ],
  "message": "Called Method ts.insertvariableunits"
}
*/

   ipsJSONS->XPath = L"/json/";
   int count = ipsJSONS->XChildrenCount;
   if (count > 1) {
	 ipsJSONS->XPath = L"/json/data/";
	 count = ipsJSONS->XChildrenCount;
	 int newid;
	 for (int i=1; i<=count; i++) {
	   ipsJSONS->XPath = L"/json/data/[" + IntToStr(i) + L"]/";
	   if (TryStrToInt(ipsJSONS->XText, newid))
		 newids.push_back(newid);
	   else
		 return false;
	   }
	 }

   /*
   else {
	 ipsJSONS->XPath = L"/json/";
	 int count = ipsJSONS->XChildrenCount;
	 if (count > 1) {
	   ipsJSONS->XPath = L"/json/newids/";
	   count = ipsJSONS->XChildrenCount;
	   int newid;
	   for (int i=1; i<=count; i++) {
		 ipsJSONS->XPath = L"/json/newids/[" + IntToStr(i) + L"]/";
		 if (TryStrToInt(ipsJSONS->XText, newid))
		   newids.push_back(newid);
		 else
		   return false;
		 }
	   }
	 }
   */
   return true;
}
//---------------------------------------------------------------------------

void NeotomaPut::ResetJSONParser(void)
{
   ipsJSONS->Reset();
   ipsJSONS->Config("KeepAlive=true");
   ipsJSONS->Config("CodePage=65001");   // UTF-8 CodePage
   ipsJSONS->BuildDOM = true;
   ipsJSONS->LocalHost = TcpClient->LocalHostAddr();
   ipsJSONS->TransferredDataLimit = 0;
}
//---------------------------------------------------------------------------

RetrieveURL::RetrieveURL(UnicodeString method)
{
// this is commented out for testing
/*
   if (tiGlobals->RDMS == PostgreSQL) {
	 url = L"https://tilia-dev.neotomadb.org/api/?method=ti." + method.LowerCase();
	 //ShowMemoForm = new TShowMemoForm(L"neotomadev url", url, NULL);
	 //ShowMemoForm->ShowModal();
	 //delete ShowMemoForm;
	 }
   else {
	 url = L"http://tilia.neotomadb.org/retrieve/?method=" + method;
	 }
*/
}
//---------------------------------------------------------------------------

RetrieveSecureURL::RetrieveSecureURL(UnicodeString method) : RetrieveURL()
{
   if (SameText(method.SubString(1,3),L"ts."))
	 url = tiGlobals->NeotomaEndpoint + L"?method=" + method.LowerCase();
   else
	 url = tiGlobals->NeotomaEndpoint + L"?method=ti." + method.LowerCase();

   //ShowMemoForm = new TShowMemoForm(L"neotomadev url", url, NULL);
   //ShowMemoForm->ShowModal();
   //delete ShowMemoForm;


   /*
   else {
	 if (SameText(method.SubString(1,3),L"ts.")) {
	   method = method.Delete(1,3);
	   // url = L"https://tilia.neotomadb.org/update/get.ashx/?method=" + method;
	   url = tiGlobals->NeotomaEndpoint + L"update/get.ashx/?method=" + method;
	   }
	 else
	   // url = L"https://tilia.neotomadb.org/retrieve/?method=" + method;
	   url = tiGlobals->NeotomaEndpoint + L"retrieve/?method=" + method;
	 }
   */
}
//---------------------------------------------------------------------------

void RetrieveURL::EncodeSpace(UnicodeString& value)
{
   int pos;
   while ((pos = value.Pos(L" ")) > 0) {
	 value.Delete(pos, 1);
	 value.Insert(L"%20", pos);
	 }
}
//---------------------------------------------------------------------------

void RetrieveURL::Add(UnicodeString name, UnicodeString value)
{
   UnicodeString param;
   EncodeSpace(value);
   param = L"&_" + name.LowerCase() + L"=" + value;
   //else
   //	 param = L"&" + name + L"=" + value;
   url += param;
}
//------------------------------------------------------------------------

// #ifdef TSTESTING
UpdateData::UpdateData(UnicodeString method, int np, TipsHTTPS* ipshttps, TipsJSONS* ipsjsons,
	TTcpClient* tcpclient) : InsertData(method, np, ipshttps, ipsjsons, tcpclient)
{
   /*
   // {"method":"InsertEcolGroup","data":[{"TAXONID":40529,"ECOLSETID":1,"ECOLGROUPID":"TRSH"}]}
   postdata = L"{\"method\":\"" + method + L"\",\"data\":[";
   */
   // ShowMessage(L"UpdataData constructor called");
   //ShowMemoForm = new TShowMemoForm(L"url: ", url, NULL);
   //ShowMemoForm->ShowModal();
   //delete ShowMemoForm;
}

//------------------------------------------------------------------------
bool UpdateData::Post(UnicodeString& ErrorMsg)
{
   PostData();
   return PostURL(url, ErrorMsg);
}

/*
#else
UpdateData::UpdateData(UnicodeString method, int np, TipsHTTPS* ipshttps, TipsJSONS* ipsjsons,
	TTcpClient* tcpclient) : NeotomaPut(ipshttps, ipsjsons, tcpclient)
{
   url = tiGlobals->NeotomaEndpoint + L"update/?method=" + method;
}
//---------------------------------------------------------------------------

void UpdateData::Add(UnicodeString name, UnicodeString value)
{
   if (!value.IsEmpty()) {
	 //UnicodeString param;
	 //param = L"&" + name + L"=" + encode_url.Encode(value);
	 //url += param;
	 Append(name,encode_url.Encode(value));
	 }
}
//---------------------------------------------------------------------------

void UpdateData::Add(UnicodeString name, int value)
{
   //UnicodeString param;
   //param = L"&" + name + L"=" + IntToStr(value);
   //url += param;
   Append(name,IntToStr(value));
}
//---------------------------------------------------------------------------

void UpdateData::Add(UnicodeString name, bool value)
{
   //UnicodeString param;
   //param = L"&" + name + L"=" + ((value) ? L"1" : L"0");
   //url += param;
   Append(name,((value) ? L"1" : L"0"));
}
//---------------------------------------------------------------------------

void UpdateData::Add(UnicodeString name, int value, int null_value)
{
   if (value != null_value) {
	 //UnicodeString param;
	 //param = L"&" + name + L"=" + IntToStr(value);
	 //url += param;
	 Append(name,IntToStr(value));
	 }
}
//---------------------------------------------------------------------------

void UpdateData::Add(UnicodeString name, double value)
{
   //UnicodeString param;
   //param = L"&" + name + L"=" + USFloatToStr(value);
   //url += param;
   Append(name,USFloatToStr(value));
}
//---------------------------------------------------------------------------

void UpdateData::AddDouble(UnicodeString name, Variant value)
{
   if (!value.IsEmpty() && !value.IsNull()) {
	 try {
		 double dVal;
		 if (TryVariantToDouble(value, dVal)) {
		   //UnicodeString param;
		   //param = L"&" + name + L"=" + USFloatToStr(dVal);
		   //url += param;
		   Append(name,USFloatToStr(dVal));
		   }
		 }
	 catch (...) {
		 }
	 }
}
//---------------------------------------------------------------------------

void UpdateData::AddInt(UnicodeString name, Variant value)
{
   if (!value.IsEmpty() && !value.IsNull()) {
	 try {
		 int iVal = (int)value;
		 //UnicodeString param;
		 //param = L"&" + name + L"=" + IntToStr(iVal);
		 //url += param;
		 Append(name,IntToStr(iVal));
		 }
	 catch (...) {
		 }
	 }

}
//---------------------------------------------------------------------------

void UpdateData::Append(UnicodeString name, UnicodeString value)
{
   UnicodeString param;
   param = L"&_" + name + L"=" + value;
   //else
   //	 param = L"&" + name + L"=" + value;
   url += param;
}
//---------------------------------------------------------------------------

bool UpdateData::Post(UnicodeString& ErrorMsg)
{
   vector<int> newids;
   //ShowMessage(L"User = " + ipsHTTPS->User + L", Password = " + ipsHTTPS->Password);

   ipsHTTPS->PostData = L"";  // use blank postdata for updates
   return PostURL(url, ErrorMsg);


   //else {
   //	 ipsHTTPS->PostData = L"";  // use blank postdata for updates
   //	 return PostURL(url, newids, ErrorMsg);
   //	 }

}
//---------------------------------------------------------------------------
#endif
*/


// #ifdef TSTESTING
DeleteData::DeleteData(UnicodeString method, int np, TipsHTTPS* ipshttps, TipsJSONS* ipsjsons,
	TTcpClient* tcpclient) : InsertData(method, np, ipshttps, ipsjsons, tcpclient)
{
}
//---------------------------------------------------------------------------

bool DeleteData::Post(UnicodeString& ErrorMsg)
{
   PostData();
   return PostURL(url, ErrorMsg);
}
//---------------------------------------------------------------------------

/*
#else
DeleteData::DeleteData(UnicodeString method, int np, TipsHTTPS* ipshttps, TipsJSONS* ipsjsons,
	TTcpClient* tcpclient) : NeotomaPut(ipshttps, ipsjsons, tcpclient)
{
   // url = L"https://tilia.neotomadb.org/update/?method=" + method;
   url = tiGlobals->NeotomaEndpoint + L"update/?method=" + method;
}
//---------------------------------------------------------------------------

void DeleteData::Add(UnicodeString name, UnicodeString value)
{
   if (!value.IsEmpty()) {
	 UnicodeString param;
	 param = L"&" + name + L"=" + encode_url.Encode(value);
	 url += param;
	 }
}
//---------------------------------------------------------------------------

void DeleteData::Add(UnicodeString name, int value)
{
   UnicodeString param;
   param = L"&" + name + L"=" + IntToStr(value);
   url += param;
}
//---------------------------------------------------------------------------

bool DeleteData::Post(UnicodeString& ErrorMsg)
{
   vector<int> newids;
   ipsHTTPS->PostData = L"";  // use blank postdata for deletes
   return PostURL(url, newids, ErrorMsg);
}
//---------------------------------------------------------------------------
#endif
*/

InsertData::InsertData(UnicodeString method, int np, TipsHTTPS* ipshttps,
	TipsJSONS* ipsjsons, TTcpClient* tcpclient) : NeotomaPut(ipshttps, ipsjsons, tcpclient)
{
   nrecs = 0;
   nparams = np;
   maxparams = np;
   n = 1;

   // {"method":"InsertEcolGroup","data":[{"TAXONID":40529,"ECOLSETID":1,"ECOLGROUPID":"TRSH"}]}

   url = tiGlobals->NeotomaEndpoint + L"update/write/";
   method = "ts." + method.LowerCase();

   /*
   else
	 url = tiGlobals->NeotomaEndpoint + L"update/write.ashx";
   */
   postdata = L"{\"method\":\"" + method + L"\",\"data\":[";
}
//---------------------------------------------------------------------------

void InsertData::Add(UnicodeString name, UnicodeString value)
{
   UnicodeString Value;

   if (value.IsEmpty()) {
	 if (nparams == n)
	   EndRecord();
	 else
	   nparams--;
	 // return;
	 }
   else {
	 // escape double quotes with \"
	 int len = value.Length();
	 int pos = 1;
	 while (pos <= len) {
	   if (value[pos] == L'\"') {
		 value.Insert(L"\\",pos);
		 len++;
		 pos += 2;
		 }
	   else
		 pos++;
	   }

	 len = value.Length();
	 pos = 1;
	 while (pos <= len) {
	   if (value.SubString(pos,2) == L"\r\n") {
		 //ShowMemoForm = new TShowMemoForm(L"Value", value.SubString(1,pos), NULL);
		 //ShowMemoForm->ShowModal();
		 //delete ShowMemoForm;

		 value.Delete(pos,2);
		 value.Insert(L"\\r\\n",pos);
		 len += 2;
		 pos += 4;
		 }
	   else
		 pos++;
	   }

	 Value = L"\"" + value + L"\"";
	 // Value = L"\"" + encode_url.Encode(value) + L"\"";
	 Append(name, Value);
	 }
   // Append(name, Value);
}
//---------------------------------------------------------------------------

void InsertData::Add(UnicodeString name, int value)
{
   Add(name, value, -1);;
}
//---------------------------------------------------------------------------

void InsertData::Add(UnicodeString name, int value, int null_value)
{
   if (value == null_value) {
	 if (nparams == n)
	   EndRecord();
	 else
	   nparams--;
	 }
   else
	 Append(name, IntToStr(value));
}
//---------------------------------------------------------------------------

void InsertData::Add(UnicodeString name, bool value)
{
   UnicodeString Value;
   Value = (value) ? L"\"true\"" : L"\"false\"";

   //else
   //	 Value = (value) ? L"1" : L"0";
   Append(name, Value);
}
//---------------------------------------------------------------------------

void InsertData::Add(UnicodeString name, double value)
{
   if (IsNan(value)) {
	 if (nparams == n)
	   EndRecord();
	 else
	   nparams--;
	 }
   else
	 Append(name, USFloatToStr(value));
}
//---------------------------------------------------------------------------

void InsertData::AddDouble(UnicodeString name, Variant value)
{
   if (value.Type() != varDouble && value.Type() != varInteger) {
	 if (nparams == n)
	   EndRecord();
	 else
	   nparams--;
	 }
   else
	 Append(name, USFloatToStr((double)value));
}
//---------------------------------------------------------------------------

void InsertData::AddInt(UnicodeString name, Variant value)
{
   if (value.Type() != varInteger && value.Type() != varDouble) {
	 if (nparams == n)
	   EndRecord();
	 else
	   nparams--;
	 }
   else
	 Append(name, IntToStr((int)value));
}
//---------------------------------------------------------------------------

void InsertData::Append(UnicodeString name, UnicodeString value)
{
   // {"method":"ts.insertvariableunits","data":[{"_units":"test7"}]}

   if (n == 1)
	 record = L"{";
   else
	 record += L",";

   name = L"_" + name.LowerCase();

   UnicodeString param = L"\"" + name + L"\":" + value;
   record += param;
   if (n++ == nparams)
	 EndRecord();
}
//---------------------------------------------------------------------------

void InsertData::EndRecord(void)
{
   record += L"}";
   if (nrecs > 0)
	 postdata += L",";
   postdata += record;
   nrecs++;
   n = 1;
   nparams = maxparams;
}
//---------------------------------------------------------------------------

void InsertData::PostData(void)
{
   postdata += L"]}";
   ipsHTTPS->PostData = postdata;
   //else
   //	 ipsHTTPS->PostData = postdata;

   //ShowMemoForm = new TShowMemoForm(L"PostData", postdata, NULL);
   //ShowMemoForm->ShowModal();
   //delete ShowMemoForm;
}
//---------------------------------------------------------------------------

bool InsertData::Post(vector<int>& newids, UnicodeString& ErrorMsg)
{
   /*
   if (ContainsText(ipsHTTPS->PostData,L"ts.insertchronology")) {
	 UnicodeString msg = url + L"\n" + ipsHTTPS->PostData;
	 ShowMemoForm = new TShowMemoForm(L"insert url", msg, NULL);
	 ShowMemoForm->ShowModal();
	 delete ShowMemoForm;
	 }
   */

   return PostURL(url, newids, ErrorMsg);
}
//---------------------------------------------------------------------------

bool InsertData::Post(UnicodeString& ErrorMsg)
{
   return PostURL(url, ErrorMsg);
}
//---------------------------------------------------------------------------


