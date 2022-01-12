//---------------------------------------------------------------------------

#include <vcl.h>
#include "pch.h"
#pragma hdrstop

#include <System.hpp>
#include <HTTPApp.hpp>
#include "TIJSON.h"
#ifndef TINeotomaH
#include "TINeotoma.h"
#endif
#ifndef TIGlobalsH
#include "TIGlobals.h"
#endif
#ifndef TIUtilsH
#include "TIUtils.h"
#endif
#ifndef TIMemoH
#include "TIMemo.h"
#endif
#ifndef TIXMLH
#include "TIXML.h"
#endif
#ifndef TNUtilsH
#include "TNUtils.h"
#endif
#ifndef TIVersionH
#include "TIVersion.h"
#endif

//---------------------------------------------------------------------------

#pragma package(smart_init)

//---------------------------------------------------------------------------
//"Hell\u0027sKitchen Lake"
UnicodeString TransJSONescapes(UnicodeString ustr)
{
   UnicodeString EscSeq;
   int pos;
   while ((pos = ustr.Pos(L"\\u")) > 0) {
	 EscSeq = L"0x" + ustr.SubString(pos+2, 4);
	 wchar_t ws = EscSeq.ToInt();
	 ustr.Delete(pos, 6);
	 ustr.Insert(UnicodeString(ws), pos);
	 }
   return ustr;
}
//---------------------------------------------------------------------------

UnicodeString TransJSONescapes(Variant value)
{
   UnicodeString ustr = value;
   return TransJSONescapes(ustr);
}
//---------------------------------------------------------------------------

EncodeURL::EncodeURL()
{
   // url encodings for reserved and unsafe characters
   delimiters = L" $&+,/:;=?@'\"<>#%{}|\\^~[]`\r\n";
   //delimiters = L" $&+,/:;=?@\"<>#%{}|\\^~[]`\r\nü";
   SafeCodes[L" "] = L"%20";
   SafeCodes[L"$"] = L"%24";
   SafeCodes[L"&"] = L"%26";
   SafeCodes[L"'"] = L"%27%27";
   SafeCodes[L"+"] = L"%2B";
   SafeCodes[L","] = L"%2C";
   SafeCodes[L"/"] = L"%2F";
   SafeCodes[L":"] = L"%3A";
   SafeCodes[L";"] = L"%3B";
   SafeCodes[L"="] = L"%3D";
   SafeCodes[L"?"] = L"%3F";
   SafeCodes[L"@"] = L"%40";
   SafeCodes[L"\""] = L"%22";
   SafeCodes[L"<"] = L"%3C";
   SafeCodes[L">"] = L"%3E";
   SafeCodes[L"#"] = L"%23";
   SafeCodes[L"%"] = L"%25";
   SafeCodes[L"{"] = L"%7B";
   SafeCodes[L"}"] = L"%7D";
   SafeCodes[L"|"] = L"%7C";
   SafeCodes[L"\\"] = L"%5C";
   SafeCodes[L"^"] = L"%5E";
   SafeCodes[L"~"] = L"%7E";
   SafeCodes[L"["] = L"%5B";
   SafeCodes[L"]"] = L"%5D";
   SafeCodes[L"`"] = L"%60";
   SafeCodes[L"\r"] = L"%0D";
   SafeCodes[L"\n"] = L"%0A";

   //SafeCodes[L"ü"] = L"%C3%BC";
}
//---------------------------------------------------------------------------

UnicodeString EncodeURL::Encode(UnicodeString Value)
{
   UnicodeString NewValue = Value.Trim();

   /*
   for (int i = 1; i <= NewValue.Length(); i++) {
	 NewValue.c_str()
	 AnsiString astr = NewValue.SubString(i,1);
	 ShowMessage(astr);
	 //if (astr.Length() > 1)
	 //  ShowMessage(L"Multibyte charcter in " + NewValue);
	 }
   */

   int count = NewValue.Length();
   int idx;
   while (count > 0 && (idx = NewValue.SubString(1,count).LastDelimiter(delimiters)) > 0) {
	 UnicodeString UnsafeChar = NewValue.SubString(idx,1);
	 UnicodeString SafeCode = SafeCodes[UnsafeChar];
	 NewValue.Delete(idx,1);
	 NewValue.Insert(SafeCode,idx);
	 count = idx - 1;
	 }
   return NewValue;
   // Allard, Jane -> Allard%2C%20Jane
}
//---------------------------------------------------------------------------

JSONTABLE::JSONTABLE(TipwJSON *ipwjson, TTcpClient *tcpClient)
{
   int ErrorCode;
   char name[256];

   ipwJSON = ipwjson;
   ipwJSON->Reset();
   if (tiGlobals->InternetTimeout > 60)
	 ipwJSON->Timeout = tiGlobals->InternetTimeout;
   ipwJSON->Config("KeepAlive=true");
   ipwJSON->Config("CodePage=65001");   // UTF-8 CodePage
   //ipwJSON->Config("SSLEnabledProtocols=3072");
   ipwJSON->BuildDOM = true;
   ipwJSON->LocalHost = tcpClient->LocalHostAddr();
   ipwJSON->TransferredDataLimit = 0;
}
//---------------------------------------------------------------------------

void JSONTABLE::AddParam(UnicodeString Param, UnicodeString Value)
{
   Value = encode_url.Encode(Value);
   //ShowMessage(L"Value = " + Value);
   Value = L"%27" + Value + L"%27";    // %27 = single quote
   Parameters[Param] = Value;

   // Parameters[Param] = encode_url.Encode(Value);
}
//---------------------------------------------------------------------------

//TODO: look into making Parameters a map<UnicodeString, Variant>, then using actual int and double values
void JSONTABLE::AddParam(UnicodeString Param, int Value)
{
   Parameters[Param] = IntToStr(Value);
}
//---------------------------------------------------------------------------

void JSONTABLE::AddParam(UnicodeString Param, bool Value)
{
   Parameters[Param] = (Value) ? L"1" : L"0";
}
//---------------------------------------------------------------------------

void JSONTABLE::AddParam(UnicodeString Param, double Value)
{
   Parameters[Param] = USFloatToStr(Value);
}
//---------------------------------------------------------------------------

int JSONTABLE::Find(UnicodeString FieldName, UnicodeString Value, vector<void*>& vptrs)
{
   int count = 0;
   int idx;
   int pos = FieldPos[FieldName];
   vptrs.clear();
   multimap<UnicodeString, void*, mapSameText>::iterator itr;
   pair<multimap<UnicodeString, void*, mapSameText>::iterator, multimap<UnicodeString, void*, mapSameText>::iterator> range;
   range = Fields[pos].SIndex.equal_range(Value);
   if (range.first != Fields[pos].SIndex.end()) {
	 for (itr=range.first; itr!=range.second; itr++) {
	   vptrs.push_back(itr->second);
	   count++;
	   }
	 }
   return count;
}
//---------------------------------------------------------------------------

int JSONTABLE::Find(UnicodeString FieldName, int ID, vector<void*>& vptrs)
{
   int count = 0;
   int idx;
   int pos = FieldPos[FieldName];
   vptrs.clear();
   multimap<int, void*>::iterator itr;
   pair<multimap<int, void*>::iterator, multimap<int, void*>::iterator> range;
   range = Fields[pos].Index.equal_range(ID);
   if (range.first != Fields[pos].Index.end()) {
	 for (itr=range.first; itr!=range.second; itr++) {
	   vptrs.push_back(itr->second);
	   count++;
	   }
	 }
   return count;
}
//---------------------------------------------------------------------------

int JSONTABLE::FindID(int id)
{
   int left = 0;
   int right = Size() - 1;
   int middle;

   // int TaxonIDPos = FieldPos["TaxonID"];
   // int GetID(int idx) { return Items[idx].TaxonID; }

   while (left <= right) {
	 middle = (left + right)/2;
	 if (GetID(middle) == id)
	   return middle;
	 else if (GetID(middle) > id)
	   right = middle - 1;
	 else
	   left = middle + 1;
	 }
   return -1;
}
//---------------------------------------------------------------------------

void JSONTABLE::AddField(UnicodeString Name, int Type)
{
   JSONFIELD Field;
   Field.Name = Name;
   Field.Type = Type;
   Fields.push_back(Field);
   FieldPos[Name] = Fields.size() - 1;
}
//---------------------------------------------------------------------------

bool JSONTABLE::Get(UnicodeString url)
 {
   bool success;
   try {
	   ipwJSON->Get(url);
	   success = Parse();
	   }
   catch (const Exception &e) {
	   MessageDlg(WebServiceName() + L": " + e.Message, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   success = false;
	   }
   return success;
 }
//---------------------------------------------------------------------------

bool JSONTABLE::Parse(void)
{
   int numChildren;
   UnicodeString XPath, XPath1;
   UnicodeString msg;

   //{"success":1,"data":[]}

   /*
   TMemoForm* MemoForm = new TMemoForm(L"Transferred Data", ipwJSON->TransferredData,
	   MemoFormOptions() << mfoReadOnly, NULL);
   MemoForm->ShowModal();
   delete MemoForm;
   */

   // this works with an error message
   ipwJSON->XPath = "/json/status";
   UnicodeString success = ipwJSON->XText;
   success = StripTextQuotes(success);
   if (!SameText(success,L"success")) {
	 //TMemoForm* MemoForm = new TMemoForm(L"URL", url, MemoFormOptions() << mfoReadOnly, NULL);
	 //MemoForm->ShowModal();
	 //delete MemoForm;
	 ipwJSON->XPath = "/json/message";
	 MessageDlg(WebServiceName() + L": " + ipwJSON->XText, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 return false;
	 }

   /*
   else {
	 ipwJSON->XPath = "/json/success";
	 int success = ipwJSON->XText.ToInt();
	 if (success == 0) {
	   ipwJSON->XPath = "/json/message";
	   MessageDlg(ipwJSON->XText, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return false;
	   }
	 }
   */
   XPath = "/json/data";
   ipwJSON->XPath = XPath;

   numChildren = ipwJSON->XChildrenCount;

   // ShowMessage(L"numChildren = " + IntToStr(numChildren));

   if (numChildren == 0)
	 return true;

   int pos, position;
   UnicodeString Text;
   JSONFIELD Field;
   int size = Fields.size();

   // TMemoForm* MemoForm = new TMemoForm(L"JSON", ipwJSON->TransferredData, MemoFormOptions() << mfoReadOnly, NULL);
   // MemoForm->ShowModal();
   // delete MemoForm;

   for (int i=1; i<=numChildren; i++) {
	 vector<Variant> Record(size, Variant::Empty());

	 // /json/data/[1]/GeoPolName1
	 UnicodeString XPath1 = XPath + "/[" + IntToStr(i) + "]";
	 ipwJSON->XPath = XPath1;
	 int nparams = ipwJSON->XChildrenCount;

	 if (nparams < size) {
	   msg = L"Error in Tilia API web service " + webservice + L". n";
	   msg += L"Number of parameters in repsonse is less than number expected. ";
	   msg += (IntToStr(nparams) + L" parameter(s) in response.  ");
	   msg += (IntToStr(size) + L" parameter(s) expected.");
	   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);

	   return false;
	   }

	 for (position=0; position<size; position++) {
	   //if (i < 10)
	   //	 ShowMessage(L"position = " + IntToStr(position));
	   Field = Fields[position];
	   ipwJSON->XPath = XPath1 + "/" + Field.Name + "/";

	   //if (i < 10)
	   //	 ShowMessage(ipwJSON->XPath);

	   if (ipwJSON->XText == L"null")
		 Record[position].ChangeType(varEmpty);
	   else {
		 switch (Field.Type) {
		   case varOleStr:
		   case varDate:
			 Text = ipwJSON->XText;
			 if (Text.IsEmpty())
			   Record[position].ChangeType(varEmpty);
			 else {
			   Text = StripTextQuotes(Text);
			   while ((pos = Text.Pos("\\\"")) > 0)
				 Text.Delete(pos,1);

			   if (Field.Type == varOleStr) {
				 //if (i < 10)
				 //  ShowMessage(L"varOleStr 1: " + Text);
				 Record[position].ChangeType(varOleStr);
				 Record[position] = TransJSONescapes(Text);
				 //if (i < 10)
				 //  ShowMessage(L"varOleStr 2: " + Text);
				 }
			   else {
				 //if (i < 10)
				 //  ShowMessage(L"varDate: " + Text);
				 short year = Text.SubString(1,4).ToInt();
				 short month = Text.SubString(6,2).ToInt();
				 short day = Text.SubString(9,2).ToInt();
				 TDateTime date(year, month, day);
				 Record[position].ChangeType(varDate);
				 Record[position] = date;
				 }
			   }
			 break;
		   case varDouble:
			 //if (i < 10)
			 //  ShowMessage(ipwJSON->XText);
			 Record[position].ChangeType(varDouble);
			 try {
				 Record[position] = GetDoubleFromText(ipwJSON->XText, 0);
				 }
			 catch (const Exception &e) {
				 Record[position].ChangeType(varEmpty);
				 if (MessageDlg(e.Message + "\nAttempting to parse field <" + Field.Name + ">",
					 Dialogs::mtError, TMsgDlgButtons() << mbOK << mbAbort, 0) == mrAbort) return false;
				 }
			 break;
		   case varInteger:
			 //if (i < 10)
			 //  ShowMessage(ipwJSON->XText);
			 Record[position].ChangeType(varInteger);
			 try {
				 Record[position] = ipwJSON->XText.ToInt();
				 }
			 catch (const Exception &e) {
				 Record[position].ChangeType(varEmpty);
				 if (MessageDlg(e.Message + "\nAttempting to parse field <" + Field.Name + ">",
					 Dialogs::mtError, TMsgDlgButtons() << mbOK << mbAbort, 0) == mrAbort) return false;
				 }
			 break;
		   case varBoolean:
			 //if (i < 10)
			 //  ShowMessage(ipwJSON->XText);
			 Record[position].ChangeType(varBoolean);
			 if (ipwJSON->XText.CompareIC(L"true") == 0)
			   Record[position] = true;
			 else if (ipwJSON->XText.CompareIC(L"false") == 0)
			   Record[position] = false;
			 else {
			   Record[position].ChangeType(varEmpty);
			   if (MessageDlg("Invalid boolean value \"" + Record[position] + "\"\nAttempting to parse field <" + Field.Name + ">",
				 Dialogs::mtError, TMsgDlgButtons() << mbOK << mbAbort, 0) == mrAbort) return false;
			   }
			 break;
		   }
		 }
	   }
	 Table.push_back(Record);
	 AddRecord(Record);
	 }
   IndexItems();

   // ShowMessage(L"json parsed");

   return true;
}
//---------------------------------------------------------------------------

bool JSONTABLE::Execute(void)
{
   bool rv;

   try {
	   RetrieveURL URL(webservice);
	   if (Parameters.size() > 0) {
		 map<UnicodeString, UnicodeString>::iterator itr;
		 for (itr = Parameters.begin(); itr != Parameters.end(); itr++)
		   URL.Add(itr->first, itr->second);
		 }
	   url = URL.URL();
	   rv = Get(url);
	   }
   catch (Exception& e)
	   {
	   MessageDlg(WebServiceName() + L": " +  e.Message, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);

	   //TMemoForm* MemoForm = new TMemoForm(L"URL", url, MemoFormOptions() << mfoReadOnly, NULL);
	   //MemoForm->ShowModal();
	   //delete MemoForm;

	   rv = false;
	   }
   return rv;
}
//---------------------------------------------------------------------------

SJSONTABLE::SJSONTABLE(TipsJSONS *ipsjsons, TTcpClient *tcpClient) : JSONTABLE()
{
   int ErrorCode;
   char name[256];

   ipsJSONS = ipsjsons;
   ipsJSONS->Reset();
   if (tiGlobals->InternetTimeout > 60)
	 ipsJSONS->Timeout = tiGlobals->InternetTimeout;

   CURRENTVERSION CurrentVersion;
   UnicodeString UserAgent = L"UserAgent={\"program\":\"Tilia\",\"version\":\"" +
	  CurrentVersion.Version() + L"\",\"hash\":\"" + tiLicense->GetHash() + L"\"}";

   // TMemoForm* MemoForm = new TMemoForm(L"UserAgent", UserAgent, MemoFormOptions() << mfoReadOnly, NULL);
   // MemoForm->ShowModal();
   // delete MemoForm;

   ipsJSONS->Config("KeepAlive=true");
   ipsJSONS->Config("CodePage=65001");   // UTF-8 CodePage
   ipsJSONS->Config("SSLEnabledProtocols=3072");
   ipsJSONS->Config(UserAgent);
   ipsJSONS->ContentType = L"application/json";
   ipsJSONS->BuildDOM = true;
   ipsJSONS->LocalHost = tcpClient->LocalHostAddr();
   ipsJSONS->TransferredDataLimit = 0;
}
//---------------------------------------------------------------------------

bool SJSONTABLE::Execute(void)
{
   bool rv;
   try {
	   RetrieveSecureURL URL(webservice);
	   if (Parameters.size() > 0) {
		 map<UnicodeString, UnicodeString>::iterator itr;
		 for (itr = Parameters.begin(); itr != Parameters.end(); itr++)
		   URL.Add(itr->first, itr->second);
		 }
	   url = URL.URL();

	   // TMemoForm* MemoForm = new TMemoForm(L"URL", url, MemoFormOptions() << mfoReadOnly, NULL);
	   // MemoForm->ShowModal();
	   // delete MemoForm;

	   // TBytes ByteArray = url.BytesOf();  // this returns single byte for umlaut u

	   UTF8String url8 = url;
	   TBytes ByteArray = url8.BytesOf();
	   url8 = L"";
	   for (int i = 0; i < ByteArray.Length; i++) {
		 int n = ByteArray[i];
		 if (n > 127)
		   url8 += ("%" + IntToHex(n,2));
		 else
		   url8 += AnsiString((char)ByteArray[i]);
		 }

	   //TMemoForm* MemoForm = new TMemoForm(L"UTF-8", url8, MemoFormOptions() << mfoReadOnly, NULL);
	   //MemoForm->ShowModal();
	   //delete MemoForm;

	   rv = Get(url8);
	   // rv = Get(url);
	   }
   catch (Exception& e)
	   {
	   MessageDlg(e.Message, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   rv = false;
	   }
   return rv;
}
//---------------------------------------------------------------------------

bool SJSONTABLE::Get(UnicodeString url)
 {
   UnicodeString msg;
   bool success = true;
   bool retry = false;
   int maxcalls = 2;
   int ncalls = 0;
   int ndoms = 0;

   // do {
	  do {
		 ncalls++;
		 try {
			 ipsJSONS->BuildDOM = true;
			 ipsJSONS->Get(url);
			 success = true;
			 }
		 catch (const Exception &e) {
			 if (ncalls < maxcalls && ContainsText(e.Message,L"Connection timed out"))
			   retry = true;
			 else {
			   success = false;
			   retry = false;
			   msg = L"Error fetching webservice " + webservice + L"\n\n";
			   msg += (L"Returned error message: " + e.Message + L"\n\n");
			   msg += (L"Time: " + DateTimeToStr(UTCDateTime()) + L" UTC\n\n");
			   msg += (L"URL: " + url);
			   TMemoForm* MemoForm = new TMemoForm(L"ERROR", msg, MemoFormOptions() << mfoReadOnly, NULL);
			   MemoForm->ShowModal();
			   delete MemoForm;
			   }
			 }
		 } while (retry && ncalls < maxcalls);

	  if (success) {
		retry = false;
		do {
		//ncalls = 0;
		ndoms++;
		try {
			// ShowMessage(L"Attempt parse " + webservice);
			//ipsJSONS->BuildDOM = true;
			UnicodeString TransferredData = ipsJSONS->TransferredData;
			// ShowMessage(TransferredData);
			// ipsJSONS->TransferredData = TransferredData;

			// ResetJSONParser();


			ipsJSONS->Reset();
			ipsJSONS->Config("KeepAlive=true");
			ipsJSONS->Config("CodePage=65001");   // UTF-8 CodePage
			ipsJSONS->BuildDOM = true;
			//ipsJSONS->LocalHost = TcpClient->LocalHostAddr();
			ipsJSONS->TransferredDataLimit = 0;

			ipsJSONS->TransferredData = TransferredData;
			ipsJSONS->Input(TransferredData);
			success = Parse();
			}
		catch (const Exception &e) {
			success = false;
			if (ndoms < maxcalls && ContainsText(e.Message,L"10234: DOM tree unavailable")) {
			  ipsJSONS->BuildDOM = true;
			  UnicodeString TransferredData = ipsJSONS->TransferredData;
			  ipsJSONS->TransferredData = TransferredData;
			  retry = true;
			  //ShowMessage(L"Retrying DOM tree");
			  }
			else {
			  success = false;
			  retry = false;
			  msg = L"Webservice " + webservice + L"\n" + e.Message;
			  MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			  TMemoForm* MemoForm = new TMemoForm(L"ERROR", msg, MemoFormOptions() << mfoReadOnly, NULL);
			  MemoForm->ShowModal();
			  delete MemoForm;
			  }
			}
		} while (retry && ndoms < maxcalls);
		}
   //	  } while (retry && ndoms < maxcalls);

   return success;
 }
//---------------------------------------------------------------------------

bool SJSONTABLE::Parse(void)
{
   int numChildren;
   UnicodeString XPath, msg;

   // this works with an error message

   // TMemoForm* MemoForm = new TMemoForm(L"TransferredData", ipsJSONS->TransferredData, MemoFormOptions() << mfoReadOnly, NULL);
   // MemoForm->ShowModal();
   // delete MemoForm;


   //ipsJSONS->BuildDOM = true;
   ipsJSONS->XPath = "/json/status";
   UnicodeString success = ipsJSONS->XText;
   success = StripTextQuotes(success);
   // ShowMessage(success);
   if (!SameText(success,L"success")) {
	 ipsJSONS->XPath = "/json/message";
	 return false;
	 }

   /*
   else {
	 ipsJSONS->XPath = "/json/success";
	 int success = ipsJSONS->XText.ToInt();
	 if (success == 0) {
	   ipsJSONS->XPath = "/json/message";
	   MessageDlg(ipsJSONS->XText, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return false;
	   }
	 }
   */
   //	   }
   /*
   catch (const Exception &e) {
	   if (ContainsText(e.Message,L"DOM tree unavailable")) {
		 MemoForm = new TMemoForm(L"Transferred Data", ipsJSONS->TransferredData, MemoFormOptions() << mfoReadOnly, NULL);
		 MemoForm->ShowModal();
		 delete MemoForm;
		 }
	   MessageDlg(e.Message, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   }
   */

   XPath = "/json/data";
   ipsJSONS->XPath = XPath;
   numChildren = ipsJSONS->XChildrenCount;

   int pos, position;
   UnicodeString Text;
   JSONFIELD Field;
   int size = Fields.size();

   for (int i=1; i<=numChildren; i++) {
	 vector<Variant> Record(size, Variant::Empty());
	 UnicodeString XPath1 = XPath + "/[" + IntToStr(i) + "]";
	 ipsJSONS->XPath = XPath1;
	 int nparams = ipsJSONS->XChildrenCount;

	 if (nparams < size) {
	   msg = L"Error in Tilia API web service " + webservice + L". n";
	   msg += L"Number of parameters in repsonse is less than number expected. ";
	   msg += (IntToStr(nparams) + L" parameter(s) in response.  ");
	   msg += (IntToStr(size) + L" parameter(s) expected.");
	   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return false;
	   }

	 for (position=0; position<size; position++) {
	   Field = Fields[position];
	   ipsJSONS->XPath = XPath1 + "/" + Field.Name + "/";

	   if (ipsJSONS->XText == L"null")
		 Record[position].ChangeType(varEmpty);
	   else {
	     // ShowMessage(ipsJSONS->XText);
		 switch (Field.Type) {
		   case varOleStr:
		   case varDate:
			 Text = ipsJSONS->XText;
			 if (Text.IsEmpty())
			   Record[position].ChangeType(varEmpty);
			 else {
			   Text = StripTextQuotes(Text);
			   while ((pos = Text.Pos("\\\"")) > 0)
				 Text.Delete(pos,1);

			   if (Field.Type == varOleStr) {
				 Record[position].ChangeType(varOleStr);
				 Record[position] = TransJSONescapes(Text);
				 }
			   else {
				 short year = Text.SubString(1,4).ToInt();
				 short month = Text.SubString(6,2).ToInt();
				 short day = Text.SubString(9,2).ToInt();
				 TDateTime date(year, month, day);
				 Record[position].ChangeType(varDate);
				 Record[position] = date;
				 }
			   }
			 break;
		   case varDouble:
			 //if (i < 10)
			 //  ShowMessage(ipsJSONS->XText);
			 Record[position].ChangeType(varDouble);
			 try {
				 Record[position] = GetDoubleFromText(ipsJSONS->XText, 0);
				 }
			 catch (const Exception &e) {
				 Record[position].ChangeType(varEmpty);
				 if (MessageDlg(e.Message + "\nAttempting to parse field <" + Field.Name + ">",
					 Dialogs::mtError, TMsgDlgButtons() << mbOK << mbAbort, 0) == mrAbort) return false;
				 }
			 break;
		   case varInteger:
			 Record[position].ChangeType(varInteger);
			 try {
				 Record[position] = ipsJSONS->XText.ToInt();
				 }
			 catch (const Exception &e) {
				 Record[position].ChangeType(varEmpty);
				 if (MessageDlg(e.Message + "\nAttempting to parse field <" + Field.Name + ">",
					 Dialogs::mtError, TMsgDlgButtons() << mbOK << mbAbort, 0) == mrAbort) return false;
				 }
			 break;
		   case varBoolean:
			 Record[position].ChangeType(varBoolean);
			 if (ipsJSONS->XText.CompareIC(L"true") == 0)
			   Record[position] = true;
			 else if (ipsJSONS->XText.CompareIC(L"false") == 0)
			   Record[position] = false;
			 else {
			   Record[position].ChangeType(varEmpty);
			   if (MessageDlg("Invalid boolean value \"" + Record[position] + "\"\nAttempting to parse field <" + Field.Name + ">",
				 Dialogs::mtError, TMsgDlgButtons() << mbOK << mbAbort, 0) == mrAbort) return false;
			   }
			 break;
		   }
		 }
	   }
	 Table.push_back(Record);
	 AddRecord(Record);
	 }

   IndexItems();
   return true;
}
//---------------------------------------------------------------------------

NeotomaTaxaBase::NeotomaTaxaBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient) : SJSONTABLE(ipsjsons, tcpClient)
{
   //webservice = L"GetTaxaTable";
   AddField("TaxonID", varInteger);
   AddField("TaxonCode", varOleStr);
   AddField("TaxonName", varOleStr);
   AddField("Author", varOleStr);
   AddField("Valid", varBoolean);
   AddField("HigherTaxonID", varInteger);
   AddField("Extinct", varBoolean);
   AddField("TaxaGroupID", varOleStr);
   AddField("PublicationID", varInteger);
   AddField("ValidatorID", varInteger);
   AddField("ValidateDate", varDate);
   AddField("Notes", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaTaxaBase::AddRecord(vector<Variant>& Record)
{
   TAXONRECORD taxon;
   taxon.TaxonID = Record[0];
   taxon.TaxonCode = Record[1];
   taxon.TaxonName = Record[2];
   taxon.Author = Record[3];
   taxon.Valid = Record[4];
   taxon.HigherTaxonID = Record[5];
   taxon.Extinct = Record[6];
   taxon.TaxaGroupID = Record[7];
   taxon.PublicationID = Record[8];
   taxon.ValidatorID = Record[9];
   taxon.ValidateDate = Record[10];
   taxon.Notes = Record[11];
   Items.push_back(taxon);
}
//---------------------------------------------------------------------------

void NeotomaTaxaBase::IndexItems(void)
{
   vector<TAXONRECORD>::pointer ptr;
   int nItems = Items.size();
   int TaxonIDPos = FieldPos["TaxonID"];
   int TaxonCodePos = FieldPos["TaxonCode"];
   int TaxonNamePos = FieldPos["TaxonName"];
   for (int i=0; i<nItems; i++) {
	 ptr = &Items[i];
	 Fields[TaxonIDPos].Index.insert(pair<int, void*>(Items[i].TaxonID, (void*)ptr));
	 Fields[TaxonCodePos].SIndex.insert(pair<UnicodeString, void*>(Items[i].TaxonCode, (void*)ptr));
	 Fields[TaxonNamePos].SIndex.insert(pair<UnicodeString, void*>(Items[i].TaxonName, (void*)ptr));
	 }
}
//---------------------------------------------------------------------------

TAXONRECORD* NeotomaTaxaBase::FindID(int id)
{
   int pos = FieldPos["TaxonID"];
   multimap<int,void*>::iterator itr = Fields[pos].Index.find(id);
   return (itr != Fields[pos].Index.end()) ? (TAXONRECORD*)(itr->second) : NULL;
}
//---------------------------------------------------------------------------

NeotomaTaxaTable::NeotomaTaxaTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaTaxaBase(ipsjsons, tcpClient)
{
   webservice = L"GetTaxaTable";
}
//---------------------------------------------------------------------------

NeotomaTaxaByTaxaGroupID::NeotomaTaxaByTaxaGroupID(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaTaxaBase(ipsjsons, tcpClient)
{
   webservice = L"GetTaxaByTaxaGroupID";
}
//---------------------------------------------------------------------------

NeotomaTaxaByNameList::NeotomaTaxaByNameList(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaTaxaBase(ipsjsons, tcpClient)
{
   webservice = L"GetTaxaByNameList";
}
//---------------------------------------------------------------------------

NeotomaValidTaxaByTaxaGroupIDList::NeotomaValidTaxaByTaxaGroupIDList(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaTaxaBase(ipsjsons, tcpClient)
{
   webservice = L"GetValidTaxaByTaxaGroupIDList";
}
//---------------------------------------------------------------------------

NeotomaInvalidTaxaByTaxaGroupIDList::NeotomaInvalidTaxaByTaxaGroupIDList(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaTaxaBase(ipsjsons, tcpClient)
{
   webservice = L"GetInvalidTaxaByTaxaGroupIDList";
}
//---------------------------------------------------------------------------

NeotomaValidTaxaByTaxaGroupID::NeotomaValidTaxaByTaxaGroupID(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaTaxaBase(ipsjsons, tcpClient)
{
   webservice = L"GetValidTaxaByTaxaGroupID";
}
//---------------------------------------------------------------------------

NeotomaInvalidTaxaByTaxaGroupID::NeotomaInvalidTaxaByTaxaGroupID(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaTaxaBase(ipsjsons, tcpClient)
{
   webservice = L"GetInvalidTaxaByTaxaGroupID";
}
//---------------------------------------------------------------------------

NeotomaTaxonByID::NeotomaTaxonByID(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaTaxaBase(ipsjsons, tcpClient)
{
   webservice = L"GetTaxonByID";
}
//---------------------------------------------------------------------------

TaxonByName::TaxonByName(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaTaxaBase(ipsjsons, tcpClient)
{
   webservice = L"GetTaxonByName";
}
//---------------------------------------------------------------------------

ValidTaxonByName::ValidTaxonByName(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaTaxaBase(ipsjsons, tcpClient)
{
   webservice = L"GetValidTaxonByName";
}
//---------------------------------------------------------------------------

InvalidTaxonByName::InvalidTaxonByName(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaTaxaBase(ipsjsons, tcpClient)
{
   webservice = L"GetInvalidTaxonByName";
}
//---------------------------------------------------------------------------

NeotomaTaxaByCodeAndTaxaGroupID::NeotomaTaxaByCodeAndTaxaGroupID(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaTaxaBase(ipsjsons, tcpClient)
{
   webservice = L"GetTaxaByCodeAndTaxaGroupID";
}
//---------------------------------------------------------------------------

NeotomaSynonymsBase::NeotomaSynonymsBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   AddField("TaxonID", varInteger);
   AddField("TaxonCode", varOleStr);
   AddField("TaxonName", varOleStr);
   AddField("Author", varOleStr);
   AddField("Valid", varBoolean);
   AddField("HigherTaxonID", varInteger);
   AddField("Extinct", varBoolean);
   AddField("TaxaGroupID", varOleStr);
   AddField("PublicationID", varInteger);
   AddField("ValidatorID", varInteger);
   AddField("ValidateDate", varDate);
   AddField("Notes", varOleStr);
   AddField("SynonymTypeID", varInteger);
}
//---------------------------------------------------------------------------

void NeotomaSynonymsBase::AddRecord(vector<Variant>& Record)
{
   SYNONYMTAXONRECORD syn;
   syn.TaxonID = Record[0];
   syn.TaxonCode = Record[1];
   syn.TaxonName = Record[2];
   syn.Author = Record[3];
   syn.Valid = Record[4];
   syn.HigherTaxonID = Record[5];
   syn.Extinct = Record[6];
   syn.TaxaGroupID = Record[7];
   syn.PublicationID = Record[8];
   syn.ValidatorID = Record[9];
   syn.ValidateDate = Record[10];
   syn.Notes = Record[11];
   syn.SynonymTypeID = Record[12];
   Items.push_back(syn);
}
//---------------------------------------------------------------------------

NeotomaSynonymsForValidTaxonID::NeotomaSynonymsForValidTaxonID(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaSynonymsBase(ipsjsons, tcpClient)
{
   webservice = L"GetSynonymsForValidTaxonID";
}
//---------------------------------------------------------------------------

NeotomaSynonymsForInvalidTaxonID::NeotomaSynonymsForInvalidTaxonID(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaSynonymsBase(ipsjsons, tcpClient)
{
   webservice = L"GetSynonymsForInvalidTaxonID";
}
//---------------------------------------------------------------------------

NeotomaDatasetTypesBase::NeotomaDatasetTypesBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   AddField("DatasetTypeID", varInteger);
   AddField("DatasetType", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaDatasetTypesBase::AddRecord(vector<Variant>& Record)
{
   int DatasetTypeID = VariantToInt(Record[0], -1);
   UnicodeString DatasetType = VarToStr(Record[1]);
   Items[DatasetTypeID] = DatasetType;
}
//---------------------------------------------------------------------------

NeotomaDatasetTypesTable::NeotomaDatasetTypesTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaDatasetTypesBase(ipsjsons, tcpClient)
{
   webservice = L"GetDatasetTypes";
}
//---------------------------------------------------------------------------

NeotomaDatasetTypesHavingData::NeotomaDatasetTypesHavingData(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaDatasetTypesBase(ipsjsons, tcpClient)
{
   webservice = L"GetDatasetTypesHavingData";
}
//---------------------------------------------------------------------------

NeotomaDatasetTypesByTaxaGroupID::NeotomaDatasetTypesByTaxaGroupID(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaDatasetTypesBase(ipsjsons, tcpClient)
{
   webservice = L"GetDatasetTypesByTaxaGroupID";
}
//---------------------------------------------------------------------------

NeotomaDatasetTypesByName::NeotomaDatasetTypesByName(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaDatasetTypesBase(ipsjsons, tcpClient)
{
   webservice = L"GetDatasetTypesByName";
}
//---------------------------------------------------------------------------

TaxaGroupsBase::TaxaGroupsBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   AddField("TaxaGroupID", varOleStr);
   AddField("TaxaGroup", varOleStr);
}
//---------------------------------------------------------------------------

void TaxaGroupsBase::AddRecord(vector<Variant>& Record)
{
   UnicodeString TaxaGroupID = VarToStr(Record[0]);
   UnicodeString TaxaGroup = VarToStr(Record[1]);
   Items[TaxaGroupID] = TaxaGroup;
}
//---------------------------------------------------------------------------

TaxaGroupsForDatasetType::TaxaGroupsForDatasetType(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: TaxaGroupsBase(ipsjsons, tcpClient)
{
   webservice = L"GetTaxaGroupsForDatasetType";
}
//---------------------------------------------------------------------------

NeotomaGetTaxaGroupID::NeotomaGetTaxaGroupID(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: TaxaGroupsBase(ipsjsons, tcpClient)
{
   webservice = L"GetTaxaGroupID";
}
//---------------------------------------------------------------------------

NeotomaGetTaxaGroupByID::NeotomaGetTaxaGroupByID(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: TaxaGroupsBase(ipsjsons, tcpClient)
{
   webservice = L"GetTaxaGroupByID";
}
//---------------------------------------------------------------------------


/*
//{"TaxaGroup":"Vascular plants","TaxaGroupID":"VPL"}
TaxaGroupsView::TaxaGroupsView(TipwJSON *ipwjson, TTcpClient *tcpClient) : JSONTABLE(ipwjson, tcpClient)
{
   AddField("TaxaGroupID", varOleStr);
   AddField("TaxaGroup", varOleStr);
}
//---------------------------------------------------------------------------

void TaxaGroupsView::AddRecord(vector<Variant>& Record)
{
   TAXAGROUPRECORD tgr;
   tgr.TaxaGroupID = Record[0];
   tgr.TaxaGroup = Record[1];
   Items.push_back(tgr);
}
//---------------------------------------------------------------------------
*/

/*
NeotomaTaxaGroupCodes::NeotomaTaxaGroupCodes(TipwJSON *ipwjson, TTcpClient *tcpClient) : JSONTABLE(ipwjson, tcpClient)
{
   webservice = L"GetTaxaGroupCodes";
   AddField("TaxaGroupID", varOleStr);
   AddField("TaxaGroup", varOleStr);
   AddField("EcolSetID", varInteger);
   AddField("EcolSetName", varOleStr);
   AddField("EcolGroupID", varOleStr);
   AddField("EcolGroup", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaTaxaGroupCodes::AddRecord(vector<Variant>& Record)
{
   TAXAGROUPCODERECORD tgcr;
   tgcr.TaxaGroupID = Record[0];
   tgcr.TaxaGroup = Record[1];
   tgcr.EcolSetID = Record[2];
   tgcr.EcolSetName = Record[3];
   tgcr.EcolGroupID = Record[4];
   tgcr.EcolGroup = Record[5];
   Items.push_back(tgcr);
}
//---------------------------------------------------------------------------
*/

NeotomaTaxaGroupCodesBase::NeotomaTaxaGroupCodesBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient) : SJSONTABLE(ipsjsons, tcpClient)
{
   AddField("TaxaGroupID", varOleStr);
   AddField("TaxaGroup", varOleStr);
   AddField("EcolGroupID", varOleStr);
   AddField("EcolGroup", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaTaxaGroupCodesBase::AddRecord(vector<Variant>& Record)
{
   TAXAGROUPCODERECORD tgcr;
   tgcr.TaxaGroupID = Record[0];
   tgcr.TaxaGroup = Record[1];
   tgcr.EcolGroupID = Record[2];
   tgcr.EcolGroup = Record[3];
   Items.push_back(tgcr);
}
//---------------------------------------------------------------------------

NeotomaDynamicTaxaGroupCodes::NeotomaDynamicTaxaGroupCodes(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaTaxaGroupCodesBase(ipsjsons, tcpClient)
{
   webservice = L"GetTaxaEcolGroupsByDatasetTypeList";
}
//---------------------------------------------------------------------------

NeotomaPredefinedTaxaGroupCodes::NeotomaPredefinedTaxaGroupCodes(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaTaxaGroupCodesBase(ipsjsons, tcpClient)
{
   webservice = L"GetPredefinedTaxaEcolGroupsByDatasetTypeList";
}
//---------------------------------------------------------------------------

//{"EcolSetID":2,"TaxonID":8005,"EcolGroupID":"ACCI"}
NeotomaEcolGroupsTableBase::NeotomaEcolGroupsTableBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
    : SJSONTABLE(ipsjsons, tcpClient)
{
   AddField("EcolSetID", varInteger);
   AddField("TaxonID", varInteger);
   AddField("EcolGroupID", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaEcolGroupsTableBase::AddRecord(vector<Variant>& Record)
{
   ECOLGROUPRECORD egr;
   egr.EcolSetID = Record[0];
   egr.TaxonID = Record[1];
   egr.EcolGroupID = Record[2];
   Items.push_back(egr);
}
//---------------------------------------------------------------------------

void NeotomaEcolGroupsTableBase::IndexItems(void)
{
   vector<ECOLGROUPRECORD>::pointer ptr;
   int nItems = Items.size();
   int TaxonIDPos = FieldPos["TaxonID"];
   for (int i=0; i<nItems; i++) {
	 ptr = &Items[i];
	 Fields[TaxonIDPos].Index.insert(pair<int, void*>(Items[i].TaxonID, (void*)ptr));
	 }
}
//---------------------------------------------------------------------------

NeotomaEcolGroupsTable::NeotomaEcolGroupsTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaEcolGroupsTableBase(ipsjsons, tcpClient)
{
   webservice = L"GetEcolGroupsTable";
}
//---------------------------------------------------------------------------

NeotomaEcolGroupsByTaxaGroupIDList::NeotomaEcolGroupsByTaxaGroupIDList(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaEcolGroupsTableBase(ipsjsons, tcpClient)
{
   webservice = L"GetEcolGroupsByTaxaGroupIDList";
}
//---------------------------------------------------------------------------

NeotomaVariableElementsTable::NeotomaVariableElementsTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient) : SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetVariableElementsTable";
   AddField("VariableElementID", varInteger);
   AddField("VariableElement", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaVariableElementsTable::AddRecord(vector<Variant>& Record)
{
   int VariableElementID = Record[0];
   UnicodeString VariableElement = Record[1];
   Items[VariableElementID] = VariableElement;
}
//---------------------------------------------------------------------------

NeotomaVariableUnitsTable::NeotomaVariableUnitsTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetVariableUnitsTable";
   AddField("VariableUnitsID", varInteger);
   AddField("VariableUnits", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaVariableUnitsTable::AddRecord(vector<Variant>& Record)
{
   int VariableUnitsID = VariantToInt(Record[0], -1);
   UnicodeString VariableUnits = VarToStr(Record[1]);
   Items[VariableUnitsID] = VariableUnits;
}
//---------------------------------------------------------------------------

NeotomaVariableContextsTable::NeotomaVariableContextsTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetVariableContextsTable";
   AddField("VariableContextID", varInteger);
   AddField("VariableContext", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaVariableContextsTable::AddRecord(vector<Variant>& Record)
{
   int VariableContextID = VariantToInt(Record[0], -1);
   UnicodeString VariableContext = VarToStr(Record[1]);
   Items[VariableContextID] = VariableContext;
}
//---------------------------------------------------------------------------

NeotomaVariablesBase::NeotomaVariablesBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   AddField("VariableID", varInteger);
   AddField("TaxonID", varInteger);
   AddField("VariableElementID", varInteger);
   AddField("VariableUnitsID", varInteger);
   AddField("VariableContextID", varInteger);
}
//---------------------------------------------------------------------------

void NeotomaVariablesBase::AddRecord(vector<Variant>& Record)
{
   VARIABLERECORD var;
   var.VariableID = VariantToInt(Record[0], -1);
   var.TaxonID = VariantToInt(Record[1], -1);
   var.VariableElementID = VariantToInt(Record[2], -1);
   var.VariableUnitsID = VariantToInt(Record[3], -1);
   var.VariableContextID = VariantToInt(Record[4], -1);
   Items.push_back(var);
}
//---------------------------------------------------------------------------

void NeotomaVariablesBase::IndexItems(void)
{
   vector<VARIABLERECORD>::pointer ptr;
   int nItems = Items.size();
   int TaxonIDPos = FieldPos["TaxonID"];
   for (int i=0; i<nItems; i++) {
	 ptr = &Items[i];
	 Fields[TaxonIDPos].Index.insert(pair<int, void*>(Items[i].TaxonID, (void*)ptr));
	 }
}
//---------------------------------------------------------------------------

/*
NeotomaVariablesTable::NeotomaVariablesTable(TipwJSON *ipwjson, TTcpClient *tcpClient)
	: NeotomaVariablesBase(ipsjsons, tcpClient)
{
   webservice = L"GetVariablesTable";
}
//---------------------------------------------------------------------------
*/

NeotomaVariablesByTaxaGroupIDList::NeotomaVariablesByTaxaGroupIDList(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaVariablesBase(ipsjsons, tcpClient)
{
   webservice = L"GetVariablesByTaxaGroupIDList";
}
//---------------------------------------------------------------------------

NeotomaVariablesByTaxonID::NeotomaVariablesByTaxonID(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaVariablesBase(ipsjsons, tcpClient)
{
   webservice = L"GetVariablesByTaxonID";
}
//---------------------------------------------------------------------------

NeotomaVariableByComponents::NeotomaVariableByComponents(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaVariablesBase(ipsjsons, tcpClient)
{
   webservice = L"GetVariableByComponents";
}
//---------------------------------------------------------------------------

NeotomaVariableByID::NeotomaVariableByID(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaVariablesBase(ipsjsons, tcpClient)
{
   webservice = L"GetVariableByID";
}
//---------------------------------------------------------------------------

NeotomaCollectionTypesBase::NeotomaCollectionTypesBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient) : SJSONTABLE(ipsjsons, tcpClient)
{
   AddField("CollTypeID", varInteger);
   AddField("CollType", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaCollectionTypesBase::AddRecord(vector<Variant>& Record)
{
   int CollTypeID = Record[0];
   UnicodeString CollType = Record[1];
   Items[CollTypeID] = CollType;
}
//---------------------------------------------------------------------------

NeotomaCollectionTypesTable::NeotomaCollectionTypesTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaCollectionTypesBase(ipsjsons, tcpClient)
{
   webservice = L"GetCollectionTypesTable";
}
//---------------------------------------------------------------------------

NeotomaCollectionTypeByID::NeotomaCollectionTypeByID(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaCollectionTypesBase(ipsjsons, tcpClient)
{
   webservice = L"GetCollectionTypeByID";
}
//---------------------------------------------------------------------------

NeotomaDepEnvtTypeBase::NeotomaDepEnvtTypeBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient) : SJSONTABLE(ipsjsons, tcpClient)
{
   AddField("DepEnvtID", varInteger);
   AddField("DepEnvt", varOleStr);
   AddField("DepEnvtHigherID", varInteger);
}
//---------------------------------------------------------------------------

void NeotomaDepEnvtTypeBase::AddRecord(vector<Variant>& Record)
{
   DEPENVTRECORD der;
   der.DepEnvtID = VariantToInt(Record[0], -1);
   der.DepEnvt = VarToStr(Record[1]);
   der.DepEnvtHigherID = VariantToInt(Record[2], -1);
   Items.push_back(der);
}
//---------------------------------------------------------------------------

void NeotomaDepEnvtTypeBase::IndexItems(void)
{
   vector<DEPENVTRECORD>::pointer ptr;
   int nItems = Items.size();
   int DepEnvtIDPos = FieldPos["DepEnvtID"];
   int DepEnvtPos = FieldPos["DepEnvt"];
   int DepEnvtHigherIDPos = FieldPos["DepEnvtHigherID"];
   for (int i=0; i<nItems; i++) {
	 ptr = &Items[i];
	 Fields[DepEnvtIDPos].Index.insert(pair<int, void*>(Items[i].DepEnvtID, (void*)ptr));
	 Fields[DepEnvtPos].SIndex.insert(pair<UnicodeString, void*>(Items[i].DepEnvt, (void*)ptr));
	 Fields[DepEnvtHigherIDPos].Index.insert(pair<int, void*>(Items[i].DepEnvtHigherID, (void*)ptr));
	 }
}
//---------------------------------------------------------------------------

NeotomaDepEnvtTypesTable::NeotomaDepEnvtTypesTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaDepEnvtTypeBase(ipsjsons, tcpClient)
{
   webservice = L"GetDepEnvtTypesTable";
}
//---------------------------------------------------------------------------

NeotomaDepEnvtTypeByID::NeotomaDepEnvtTypeByID(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaDepEnvtTypeBase(ipsjsons, tcpClient)
{
   webservice = L"GetDepEnvtByID";
}
//---------------------------------------------------------------------------

ConstituentDatabases::ConstituentDatabases(TipsJSONS *ipsjsons, TTcpClient *tcpClient) : SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetConstituentDatabases";
   AddField("DatabaseID", varInteger);
   AddField("DatabaseName", varOleStr);
}
//---------------------------------------------------------------------------

void ConstituentDatabases::AddRecord(vector<Variant>& Record)
{
   //TODO: make variant conversions elsewhere as below
   int DatabaseID = VariantToInt(Record[0], -1);
   UnicodeString DatabaseName = VarToStr(Record[1]);
   Items[DatabaseID] = DatabaseName;
}
//---------------------------------------------------------------------------

SSL_ConstituentDatabases::SSL_ConstituentDatabases(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   // webservice = L"ts.GetConstituentDatabases";
   webservice = L"GetConstituentDatabases";
   AddField("DatabaseID", varInteger);
   AddField("DatabaseName", varOleStr);
}
//---------------------------------------------------------------------------

void SSL_ConstituentDatabases::AddRecord(vector<Variant>& Record)
{
   int DatabaseID = VariantToInt(Record[0], -1);
   UnicodeString DatabaseName = VarToStr(Record[1]);
   Items[DatabaseID] = DatabaseName;
}
//---------------------------------------------------------------------------

ConstituentDatabaseNameByID::ConstituentDatabaseNameByID(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetConstituentDatabaseNameByID";
   AddField("DatabaseName", varOleStr);
}
//---------------------------------------------------------------------------

void ConstituentDatabaseNameByID::AddRecord(vector<Variant>& Record)
{
   UnicodeString DatabaseName = VarToStr(Record[0]);
   Items.push_back(DatabaseName);
}
//---------------------------------------------------------------------------

ValidatedDatabases::ValidatedDatabases(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"ts.ValidateSteward";
   AddField("DatabaseID", varInteger);
}
//---------------------------------------------------------------------------

void ValidatedDatabases::AddRecord(vector<Variant>& Record)
{
   int DatabaseID = Record[0];
   Items.push_back(DatabaseID);
}
//---------------------------------------------------------------------------

ValidateUserName::ValidateUserName(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"ts.ValidateUserName";
   //webservice = L"ValidateUserName";
   AddField("ContactID", varInteger);
   AddField("TaxonomyExpert", varBoolean);
}
//---------------------------------------------------------------------------

void ValidateUserName::AddRecord(vector<Variant>& Record)
{
   int ContactID = VariantToInt(Record[0], -1);
   bool TaxonomyExpert = VariantToBool(Record[1], false);
   Items[ContactID] = TaxonomyExpert;
}
//---------------------------------------------------------------------------

GeoPoliticalUnits::GeoPoliticalUnits(TipsJSONS *ipsjsons, TTcpClient *tcpClient) : SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetGeoPoliticalUnitsTable";
   AddField("GeoPoliticalID", varInteger);
   AddField("GeoPoliticalName", varOleStr);
   AddField("GeoPoliticalUnit", varOleStr);
   AddField("Rank", varInteger);
   AddField("HigherGeoPoliticalID", varInteger);
}
//---------------------------------------------------------------------------

void GeoPoliticalUnits::AddRecord(vector<Variant>& Record)
{
   NTMGEOPOLRECORD gp;
   gp.GeoPoliticalID = Record[0];
   gp.GeoPoliticalName = Record[1];
   gp.GeoPoliticalUnit = Record[2];
   gp.Rank = Record[3];
   gp.HigherGeoPoliticalID = Record[4];
   Items.push_back(gp);
}
//---------------------------------------------------------------------------

void GeoPoliticalUnits::Sort(void)
{
  std::sort(Items.begin(), Items.end(), GeoPoliticalUnits::GeoPolComp);
}
//---------------------------------------------------------------------------

GeoPolUnitsByRank::GeoPolUnitsByRank(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: GeoPoliticalUnits(ipsjsons, tcpClient)
{
   webservice = L"GetGeoPolUnitByRank";
}
//---------------------------------------------------------------------------

GeoPolUnitsByNameAndRank::GeoPolUnitsByNameAndRank(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: GeoPoliticalUnits(ipsjsons, tcpClient)
{
   webservice = L"GetGeoPolUnitByNameAndRank";
}
//---------------------------------------------------------------------------

GeoPolUnitByNameAndHigherID::GeoPolUnitByNameAndHigherID(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: GeoPoliticalUnits(ipsjsons, tcpClient)
{
   webservice = L"GetGeoPolUnitByNameAndHigherID";
}
//---------------------------------------------------------------------------

GeoPolUnitByID::GeoPolUnitByID(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: GeoPoliticalUnits(ipsjsons, tcpClient)
{
   webservice = L"GetGeoPolUnitByID";
}
//---------------------------------------------------------------------------

GeoPolUnitByHigherID::GeoPolUnitByHigherID(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: GeoPoliticalUnits(ipsjsons, tcpClient)
{
   webservice = L"GetGeoPolUnitByHigherID";
}
//---------------------------------------------------------------------------

GeoPolUnitsBySiteID::GeoPolUnitsBySiteID(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: GeoPoliticalUnits(ipsjsons, tcpClient)
{
   webservice = L"GetGeoPolUnitsBySiteID";
}
//---------------------------------------------------------------------------

NumberOfGeoPolSubdivs::NumberOfGeoPolSubdivs(TipsJSONS *ipsjsons, TTcpClient *tcpClient) : SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetGeoPolNumberOfSubdivs";
   AddField("NumberOfSubdivs", varInteger);
}
//---------------------------------------------------------------------------

void NumberOfGeoPolSubdivs::AddRecord(vector<Variant>& Record)
{
   NumberOfSubdivs = Record[0];
}
//---------------------------------------------------------------------------

NeotomaLakeParameterTypesTable::NeotomaLakeParameterTypesTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient) : SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetLakeParameterTypesTable";
   AddField("LakeParameterID", varInteger);
   AddField("LakeParameterCode", varOleStr);
   AddField("LakeParameter", varOleStr);
   AddField("LakeParameterShortName", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaLakeParameterTypesTable::AddRecord(vector<Variant>& Record)
{
   LAKEPARAMRECORD lpr;
   lpr.LakeParameterID = VariantToInt(Record[0], -1);
   lpr.LakeParameterCode = VarToStr(Record[1]);
   lpr.LakeParameter = VarToStr(Record[2]);
   lpr.LakeParameterShortName = VarToStr(Record[3]);
   Items.push_back(lpr);
}
//---------------------------------------------------------------------------

void NeotomaLakeParameterTypesTable::IndexItems(void)
{
   vector<LAKEPARAMRECORD>::pointer ptr;
   int nItems = Items.size();
   int LakeParameterPos = FieldPos["LakeParameter"];
   for (int i=0; i<nItems; i++) {
	 ptr = &Items[i];
	 Fields[LakeParameterPos].SIndex.insert(pair<UnicodeString, void*>(Items[i].LakeParameter, (void*)ptr));
	 }
}
//---------------------------------------------------------------------------

NeotomaSiteLakeParams::NeotomaSiteLakeParams(TipsJSONS *ipsjsons, TTcpClient *tcpClient) : SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetLakeParamsBySiteID";
   AddField("LakeParameter", varOleStr);
   AddField("Value", varDouble);
}
//---------------------------------------------------------------------------

void NeotomaSiteLakeParams::AddRecord(vector<Variant>& Record)
{
   UnicodeString LakeParameter = VarToStr(Record[0]);
   double Value = VariantToDouble(Record[1],0.0);
   Items.push_back(pair<UnicodeString,double>(LakeParameter,Value));
}
//---------------------------------------------------------------------------

NeotomaSiteGeoPolBase::NeotomaSiteGeoPolBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient) : SJSONTABLE(ipsjsons, tcpClient)
{
   AddField("SiteID", varInteger);
   AddField("SiteName", varOleStr);
   AddField("DistKm", varDouble);
   AddField("Geopolitical", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaSiteGeoPolBase::AddRecord(vector<Variant>& Record)
{
   NEOTOMASITE ns;
   ns.SiteID = VariantToInt(Record[0], -1);
   ns.SiteName = VarToStr(Record[1]);
   ns.DistKm = VariantToDouble(Record[2], 0.0);
   ns.Geopolitical = VarToStr(Record[3]);
   Items.push_back(ns);
}
//---------------------------------------------------------------------------

NeotomaGeoPolBySiteName::NeotomaGeoPolBySiteName(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaSiteGeoPolBase(ipsjsons, tcpClient)
{
   webservice = L"GetGeoPolBySiteName";
}
//---------------------------------------------------------------------------

NeotomaNearestSites::NeotomaNearestSites(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaSiteGeoPolBase(ipsjsons, tcpClient)
{
   webservice = L"GetNearestSites";
}
//---------------------------------------------------------------------------

void DecodeGeog(UnicodeString geog, double& East, double& North, double& West, double& South)
{
   // POINT (-122.55 44.35)
   // ShowMessage(L"geog: " + geog);
   if (SameText(geog.SubString(1,5), L"POINT")) {
	 int idx = geog.Pos(L"(");
	 geog.Delete(1,idx);
	 idx = geog.Pos(L")");
	 geog = geog.SubString(1,idx-1);
	 idx = geog.Pos(L" ");
	 //East = geog.SubString(1,idx-1).ToDouble();
	 East = GetDoubleFromText(geog.SubString(1,idx-1), 0);
	 West = East;
	 geog.Delete(1,idx);
	 //North = geog.ToDouble();
	 North = GetDoubleFromText(geog, 0);
	 South = North;
	 }
   // POLYGON ((-68.07328 44.37285, -68.07192 44.37285, -68.07192 44.37371, -68.07328 44.37371, -68.07328 44.37285))
   else if (SameText(geog.SubString(1,7), L"POLYGON")) {
	 // ShowMessage(geog);
	 int idx = geog.Pos(L"((");
	 geog.Delete(1,idx+1);
	 idx = geog.Pos(L"))");
	 geog = geog.SubString(1,idx-1);
	 vector<pair<double,double> > coords;   // long, lat
	 idx = geog.Pos(L",");
	 int pos;
	 double lon, lat;
	 while (idx > 0) {
	   UnicodeString lonlat = geog.SubString(1,idx-1);
	   pos = lonlat.Pos(L" ");
	   // lon = lonlat.SubString(1,pos-1).ToDouble();
	   lon = GetDoubleFromText(lonlat.SubString(1,pos-1), 0);
	   lonlat.Delete(1,pos);
	   //lat = lonlat.ToDouble();
	   lat = GetDoubleFromText(lonlat, 0);
	   coords.push_back(pair<double,double>(lon,lat));
	   geog.Delete(1,idx);
	   geog = geog.TrimLeft();
	   idx = geog.Pos(L",");
	   }
	 pos = geog.Pos(L" ");
	 //lon = geog.SubString(1,pos-1).ToDouble();
	 lon = GetDoubleFromText(geog.SubString(1,pos-1), 0);
	 geog.Delete(1,pos);
	 //lat = geog.ToDouble();
	 lat = GetDoubleFromText(geog, 0);
	 coords.push_back(pair<double,double>(lon,lat));
	 East = coords[0].first;
	 West = East;
	 North = coords[0].second;
	 South = North;
	 for (unsigned int i=1; i<coords.size(); i++) {
	   if (coords[i].first > East)
		 East = coords[i].first;
	   else if (coords[i].first < West)
		 West = coords[i].first;
	   if (coords[i].second > North)
		 North = coords[i].second;
	   else if (coords[i].second < South)
		 South = coords[i].second;
	   }
	 }
}
//---------------------------------------------------------------------------

NeotomaSiteMetaDataBase::NeotomaSiteMetaDataBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   AddField("SiteID", varInteger);
   AddField("SiteName", varOleStr);
   AddField("geog", varOleStr);
   AddField("Altitude", varDouble);
   AddField("Area", varDouble);
   AddField("SiteDescription", varOleStr);
   AddField("Notes", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaSiteMetaDataBase::AddRecord(vector<Variant>& Record)
{
   NEOTOMASITEMETADATA md;
   md.SiteID = VariantToInt(Record[0], -1);
   md.SiteName = VarToStr(Record[1]);
   DecodeGeog(VarToStr(Record[2]), md.LongitudeEast, md.LatitudeNorth, md.LongitudeWest, md.LatitudeSouth);
   md.Altitude = Record[3];
   md.Area = Record[4];
   md.SiteDescription = VarToStr(Record[5]);
   md.Notes = VarToStr(Record[6]);
   Items.push_back(md);
}
//---------------------------------------------------------------------------

NeotomaSiteMetaDataBySiteID::NeotomaSiteMetaDataBySiteID(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaSiteMetaDataBase(ipsjsons, tcpClient)
{
   webservice = L"GetSiteMetaData";
}
//---------------------------------------------------------------------------

NeotomaSiteLocBase::NeotomaSiteLocBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient) : SJSONTABLE(ipsjsons, tcpClient)
{
   AddField("SiteID", varInteger);
   AddField("SiteName", varOleStr);
   AddField("geog", varOleStr);
   AddField("GeoPolName1", varOleStr);
   AddField("GeoPolName2", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaSiteLocBase::AddRecord(vector<Variant>& Record)
{
   NEOTOMASITELOC nsl;
   int SiteID = VariantToInt(Record[0], -1);
   nsl.SiteName = VarToStr(Record[1]);
   DecodeGeog(VarToStr(Record[2]), nsl.LongitudeEast, nsl.LatitudeNorth, nsl.LongitudeWest, nsl.LatitudeSouth);
   nsl.GeoPolName1 = VarToStr(Record[3]);
   nsl.GeoPolName2 = VarToStr(Record[4]);
   Items[SiteID] = nsl;
}
//---------------------------------------------------------------------------

NeotomaSites::NeotomaSites(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaSiteLocBase(ipsjsons, tcpClient)
{
   webservice = L"GetSites";
}
//---------------------------------------------------------------------------

NeotomaSiteBase::NeotomaSiteBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient) :
	SJSONTABLE(ipsjsons, tcpClient)
{
   AddField("SiteID", varInteger);
   AddField("SiteName", varOleStr);
   AddField("Longitude", varDouble);
   AddField("Latitude", varDouble);
   AddField("Area", varDouble);
   AddField("Altitude", varDouble);
}
//---------------------------------------------------------------------------

void NeotomaSiteBase::AddRecord(vector<Variant>& Record)
{
   NEOTOMASITELOC2 nsl;
   nsl.SiteID = VariantToInt(Record[0], -1);
   nsl.SiteName = VarToStr(Record[1]);
   nsl.Longitude = Record[2];
   nsl.Latitude = Record[3];
   nsl.Area = Record[4];
   nsl.Altitude = Record[5];
   Items.push_back(nsl);
}
//---------------------------------------------------------------------------

NeotomaSitesByDatabaseAndDatasetType::NeotomaSitesByDatabaseAndDatasetType(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaSiteBase(ipsjsons, tcpClient)
{
   webservice = L"GetSitesByDatabaseAndDatasetType";
}
//---------------------------------------------------------------------------

NeotomaSitesByDatasetType::NeotomaSitesByDatasetType(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaSiteBase(ipsjsons, tcpClient)
{
   webservice = L"GetSitesByDatasetType";
}
//---------------------------------------------------------------------------

NeotomaSiteDatasets::NeotomaSiteDatasets(TipsJSONS *ipsjsons, TTcpClient *tcpClient) : SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetDatasetsBySiteID";
   AddField("CollectionUnitID", varInteger);
   AddField("CollUnitName", varOleStr);
   AddField("DatasetID", varInteger);
   AddField("DatasetType", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaSiteDatasets::AddRecord(vector<Variant>& Record)
{
   NTMSITEDATASETS nsd;
   nsd.CollectionUnitID = Record[0];
   nsd.CollUnitName = Record[1];
   nsd.DatasetID = Record[2];
   nsd.DatasetType = Record[3];
   Items.push_back(nsd);
}
//---------------------------------------------------------------------------

NeotomaDatasetPIsBase::NeotomaDatasetPIsBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   AddField("PIOrder", varInteger);
   AddField("FamilyName", varOleStr);
   AddField("LeadingInitials", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaDatasetPIsBase::AddRecord(vector<Variant>& Record)
{
   NTMDATASETPIS dpi;
   dpi.PIOrder = Record[0];
   dpi.FamilyName = Record[1];
   dpi.LeadingInitials = Record[2];
   Items.push_back(dpi);
}
//---------------------------------------------------------------------------

NeotomaDatasetPIs::NeotomaDatasetPIs(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaDatasetPIsBase(ipsjsons, tcpClient)
{
   webservice = L"GetDatasetPIs";
}
//---------------------------------------------------------------------------

NeotomaDatasetPubs::NeotomaDatasetPubs(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetDatasetCitations";
   AddField("PrimaryPub", varBoolean);
   AddField("PublicationID", varInteger);
   AddField("Citation", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaDatasetPubs::AddRecord(vector<Variant>& Record)
{
   NTMDATASETPUBS dpub;
   dpub.PrimaryPub = Record[0];
   dpub.PublicationID = Record[1];
   dpub.Citation = Record[2];
   Items.push_back(dpub);
}
//---------------------------------------------------------------------------

NeotomaTaxonUnits::NeotomaTaxonUnits(TipsJSONS *ipsjsons, TTcpClient *tcpClient) : SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetTaxonVarUnits";
   AddField("VariableUnits", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaTaxonUnits::AddRecord(vector<Variant>& Record)
{
   UnicodeString Units = VarToStr(Record[0]);
   Items.push_back(Units);
}
//---------------------------------------------------------------------------

NeotomaTaxonElements::NeotomaTaxonElements(TipsJSONS *ipsjsons, TTcpClient *tcpClient) : SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetTaxonVarElements";
   AddField("VariableElement", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaTaxonElements::AddRecord(vector<Variant>& Record)
{
   UnicodeString Elements = Record[0];
   Items.push_back(Elements);
}
//---------------------------------------------------------------------------


NeotomaTaxaGroupTypesTable::NeotomaTaxaGroupTypesTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetTaxaGroupTypes";
   AddField("TaxaGroupID", varOleStr);
   AddField("TaxaGroup", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaTaxaGroupTypesTable::AddRecord(vector<Variant>& Record)
{
   UnicodeString TaxaGroupID = Record[0];
   UnicodeString TaxaGroup = Record[1];
   Items[TaxaGroupID] = TaxaGroup;
}
//---------------------------------------------------------------------------

NeotomaPublicationsBase::NeotomaPublicationsBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   AddField("PublicationID", varInteger);
   AddField("PubTypeID", varInteger);
   AddField("Year", varOleStr);
   AddField("Citation", varOleStr);
   AddField("ArticleTitle", varOleStr);
   AddField("Journal", varOleStr);
   AddField("Volume", varOleStr);
   AddField("Issue", varOleStr);
   AddField("Pages", varOleStr);
   AddField("CitationNumber", varOleStr);
   AddField("DOI", varOleStr);
   AddField("BookTitle", varOleStr);
   AddField("Edition", varOleStr);
   AddField("VolumeTitle", varOleStr);
   AddField("NumVolumes", varOleStr);
   AddField("SeriesTitle", varOleStr);
   AddField("SeriesVolume", varOleStr);
   AddField("Publisher", varOleStr);
   AddField("URL", varOleStr);
   AddField("City", varOleStr);
   AddField("State", varOleStr);
   AddField("Country", varOleStr);
   AddField("OriginalLanguage", varOleStr);
   AddField("Notes", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaPublicationsBase::AddRecord(vector<Variant>& Record)
{
   NTMPUBLICATION pub;
   pub.PublicationID = VariantToInt(Record[0], -1);
   pub.PubTypeID = VariantToInt(Record[1], -1);
   pub.Year = VarToStr(Record[2]);
   pub.Citation = VarToStr(Record[3]);
   pub.ArticleTitle = VarToStr(Record[4]);
   pub.Journal = VarToStr(Record[5]);
   pub.Volume = VarToStr(Record[6]);
   pub.Issue = VarToStr(Record[7]);
   pub.Pages = VarToStr(Record[8]);
   pub.CitationNumber = VarToStr(Record[9]);
   pub.DOI = VarToStr(Record[10]);
   pub.BookTitle = VarToStr(Record[11]);
   pub.Edition = VarToStr(Record[12]);
   pub.VolumeTitle = VarToStr(Record[13]);
   pub.NumVolumes = VarToStr(Record[14]);
   pub.SeriesTitle = VarToStr(Record[15]);
   pub.SeriesVolume = VarToStr(Record[16]);
   pub.Publisher = VarToStr(Record[17]);
   pub.URL = VarToStr(Record[18]);
   pub.City = VarToStr(Record[19]);
   pub.State = VarToStr(Record[20]);
   pub.Country = VarToStr(Record[21]);
   pub.OriginalLanguage = VarToStr(Record[22]);
   pub.Notes = VarToStr(Record[23]);
   Items.push_back(pub);
}
//---------------------------------------------------------------------------

void NeotomaPublicationsBase::IndexItems(void)
{
   vector<NTMPUBLICATION>::pointer ptr;
   int nItems = Items.size();
   int PublicationIDPos = FieldPos["PublicationID"];
   for (int i=0; i<nItems; i++) {
	 ptr = &Items[i];
	 Fields[PublicationIDPos].Index.insert(pair<int, void*>(Items[i].PublicationID, (void*)ptr));
	 }
}
//---------------------------------------------------------------------------

NeotomaPublicationsByPubID::NeotomaPublicationsByPubID(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaPublicationsBase(ipsjsons, tcpClient)
{
   webservice = L"GetPublicationByID";
}
//---------------------------------------------------------------------------

NeotomaPublicationsByPubIDList::NeotomaPublicationsByPubIDList(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaPublicationsBase(ipsjsons, tcpClient)
{
   webservice = L"GetPublicationByIDList";
}
//---------------------------------------------------------------------------

NeotomaPublicationsByCitation::NeotomaPublicationsByCitation(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaPublicationsBase(ipsjsons, tcpClient)
{
   webservice = L"GetPublicationByCitation";
}
//---------------------------------------------------------------------------

NeotomaPublicationsByFamilyName::NeotomaPublicationsByFamilyName(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaPublicationsBase(ipsjsons, tcpClient)
{
   webservice = L"GetPublicationByFamilyName";
}
//---------------------------------------------------------------------------

NeotomaPublicationsByContactID::NeotomaPublicationsByContactID(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaPublicationsBase(ipsjsons, tcpClient)
{
   webservice = L"GetPublicationsByContactID";
}
//---------------------------------------------------------------------------

NeotomaNextPublicationByID::NeotomaNextPublicationByID(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaPublicationsBase(ipsjsons, tcpClient)
{
   webservice = L"GetNextPublicationByID";
}
//---------------------------------------------------------------------------

NeotomaPreviousPublicationByID::NeotomaPreviousPublicationByID(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaPublicationsBase(ipsjsons, tcpClient)
{
   webservice = L"GetPreviousPublicationByID";
}
//---------------------------------------------------------------------------

NeotomaNextPublicationByIDAndPubTypeID::NeotomaNextPublicationByIDAndPubTypeID(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaPublicationsBase(ipsjsons, tcpClient)
{
   webservice = L"GetNextPublicationByIDAndPubTypeID";
}
//---------------------------------------------------------------------------

NeotomaPreviousPublicationByIDAndPubTypeID::NeotomaPreviousPublicationByIDAndPubTypeID(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaPublicationsBase(ipsjsons, tcpClient)
{
   webservice = L"GetPreviousPublicationByIDAndPubTypeID";
}
//---------------------------------------------------------------------------

NeotomaEventPublications::NeotomaEventPublications(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaPublicationsBase(ipsjsons, tcpClient)
{
   webservice = L"GetEventPublications";
}
//---------------------------------------------------------------------------

NeotomaRelativeAgePublications::NeotomaRelativeAgePublications(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaPublicationsBase(ipsjsons, tcpClient)
{
   webservice = L"GetRelativeAgePublications";
}
//---------------------------------------------------------------------------

NeotomaDatasetPublications::NeotomaDatasetPublications(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaPublicationsBase(ipsjsons, tcpClient)
{
   webservice = L"GetDatasetPublications";
}
//---------------------------------------------------------------------------

NeotomaPublicationAuthors::NeotomaPublicationAuthors(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetPublicationAuthors";
   AddField("AuthorID", varInteger);
   AddField("PublicationID", varInteger);
   AddField("AuthorOrder", varInteger);
   AddField("FamilyName", varOleStr);
   AddField("Initials", varOleStr);
   AddField("Suffix", varOleStr);
   AddField("ContactID", varInteger);
}
//---------------------------------------------------------------------------

void NeotomaPublicationAuthors::AddRecord(vector<Variant>& Record)
{
   NTMAUTHOR auth;
   auth.AuthorID = VariantToInt(Record[0], -1);
   auth.PublicationID = VariantToInt(Record[1], -1);
   auth.AuthorOrder = VariantToInt(Record[2], -1);
   auth.FamilyName = VarToStr(Record[3]);
   auth.Initials = VarToStr(Record[4]);
   auth.Suffix = VarToStr(Record[5]);
   auth.ContactID = VariantToInt(Record[6], -1);
   Items.push_back(auth);
}
//---------------------------------------------------------------------------

NeotomaPublicationEditors::NeotomaPublicationEditors(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetPublicationEditors";
   AddField("EditorID", varInteger);
   AddField("PublicationID", varInteger);
   AddField("EditorOrder", varInteger);
   AddField("FamilyName", varOleStr);
   AddField("Initials", varOleStr);
   AddField("Suffix", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaPublicationEditors::AddRecord(vector<Variant>& Record)
{
   NTMEDITOR editor;
   editor.EditorID = VariantToInt(Record[0], -1);
   editor.PublicationID = VariantToInt(Record[1], -1);
   editor.EditorOrder = VariantToInt(Record[2], -1);
   editor.FamilyName = VarToStr(Record[3]);
   editor.Initials = VarToStr(Record[4]);
   editor.Suffix = VarToStr(Record[5]);
   Items.push_back(editor);
}
//---------------------------------------------------------------------------

NeotomaPublicationTranslators::NeotomaPublicationTranslators(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetPublicationTranslators";
   AddField("TranslatorID", varInteger);
   AddField("PublicationID", varInteger);
   AddField("TranslatorOrder", varInteger);
   AddField("FamilyName", varOleStr);
   AddField("Initials", varOleStr);
   AddField("Suffix", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaPublicationTranslators::AddRecord(vector<Variant>& Record)
{
   NTMTRANSLATOR translator;
   translator.TranslatorID = VariantToInt(Record[0], -1);
   translator.PublicationID = VariantToInt(Record[1], -1);
   translator.TranslatorOrder = VariantToInt(Record[2], -1);
   translator.FamilyName = VarToStr(Record[3]);
   translator.Initials = VarToStr(Record[4]);
   translator.Suffix = VarToStr(Record[5]);
   Items.push_back(translator);
}
//---------------------------------------------------------------------------

NeotomaContactBase::NeotomaContactBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   AddField("ContactID", varInteger);
   AddField("AliasID", varInteger);
   AddField("ContactStatusID", varInteger);
   AddField("ContactName", varOleStr);
   AddField("FamilyName", varOleStr);
   AddField("GivenNames", varOleStr);
   AddField("LeadingInitials", varOleStr);
   AddField("Suffix", varOleStr);
   AddField("Title", varOleStr);
   AddField("Email", varOleStr);
   AddField("Phone", varOleStr);
   AddField("Fax", varOleStr);
   AddField("URL", varOleStr);
   AddField("Address", varOleStr);
   AddField("Notes", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaContactBase::AddRecord(vector<Variant>& Record)
{
   NTMCONTACT contact;
   contact.ContactID = VariantToInt(Record[0], -1);
   contact.AliasID = VariantToInt(Record[1], -1);
   contact.ContactStatusID = VariantToInt(Record[2], -1);
   contact.ContactName = VarToStr(Record[3]);
   contact.FamilyName = VarToStr(Record[4]);
   contact.GivenNames = VarToStr(Record[5]);
   contact.LeadingInitials = VarToStr(Record[6]);
   contact.Suffix = VarToStr(Record[7]);
   contact.Title = VarToStr(Record[8]);
   contact.Email = VarToStr(Record[9]);
   contact.Phone = VarToStr(Record[10]);
   contact.Fax = VarToStr(Record[11]);
   contact.URL = VarToStr(Record[12]);
   contact.Address = VarToStr(Record[13]);
   contact.Notes = VarToStr(Record[14]);
   Items.push_back(contact);
}
//---------------------------------------------------------------------------

NeotomaContactByID::NeotomaContactByID(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaContactBase(ipsjsons, tcpClient)
{
   webservice = L"GetContactByID";
}
//---------------------------------------------------------------------------

NeotomaContactByFamilyName::NeotomaContactByFamilyName(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaContactBase(ipsjsons, tcpClient)
{
   webservice = L"GetContactByFamilyName";
}
//---------------------------------------------------------------------------

NeotomaContactByFamilyNameAndInitials::NeotomaContactByFamilyNameAndInitials(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaContactBase(ipsjsons, tcpClient)
{
   webservice = L"GetContactByFamilyNameAndInitials";
}
//---------------------------------------------------------------------------

NeotomaContactByContactName::NeotomaContactByContactName(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaContactBase(ipsjsons, tcpClient)
{
   webservice = L"GetContactByContactName";
}
//---------------------------------------------------------------------------

NeotomaCollector::NeotomaCollector(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaContactBase(ipsjsons, tcpClient)
{
   webservice = L"GetCollector";
}
//---------------------------------------------------------------------------

NeotomaInvestigator::NeotomaInvestigator(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaContactBase(ipsjsons, tcpClient)
{
   webservice = L"GetInvestigator";
}
//---------------------------------------------------------------------------

NeotomaDataProcessor::NeotomaDataProcessor(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaContactBase(ipsjsons, tcpClient)
{
   webservice = L"GetDataProcessor";
}
//---------------------------------------------------------------------------

//NeotomaContactStatusesTable::NeotomaContactStatusesTable(TipwJSON *ipwjson, TTcpClient *tcpClient) : JSONTABLE(ipwjson, tcpClient)
NeotomaContactStatusesTable::NeotomaContactStatusesTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetContactStatusesTable";
   AddField("ContactStatusID", varInteger);
   AddField("ContactStatus", varOleStr);
   AddField("StatusDescription", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaContactStatusesTable::AddRecord(vector<Variant>& Record)
{
   NTMCONTACTSTATUS cs;
   cs.ContactStatusID = VariantToInt(Record[0], -1);
   cs.ContactStatus = VarToStr(Record[1]);
   cs.StatusDescription = VarToStr(Record[2]);
   Items.push_back(cs);
}
//---------------------------------------------------------------------------

void NeotomaContactStatusesTable::IndexItems(void)
{
   vector<NTMCONTACTSTATUS>::pointer ptr;
   int nItems = Items.size();
   int StatusPos = FieldPos["ContactStatus"];
   for (int i=0; i<nItems; i++) {
	 ptr = &Items[i];
	 Fields[StatusPos].SIndex.insert(pair<UnicodeString, void*>(Items[i].ContactStatus, (void*)ptr));
	 }
}
//---------------------------------------------------------------------------

NeotomaContactDatasets::NeotomaContactDatasets(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetDatasetsByContactID";
   AddField("DatasetID", varInteger);
   AddField("SiteID", varInteger);
   AddField("DatasetType", varOleStr);
   AddField("SiteName", varOleStr);
   AddField("GeoPolName1", varOleStr);
   AddField("GeoPolName2", varOleStr);
   AddField("GeoPolName3", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaContactDatasets::AddRecord(vector<Variant>& Record)
{
   NTMCONTACTDATASET cds;
   cds.DatasetID = Record[0];
   cds.SiteID = Record[1];
   cds.DatasetType = Record[2];
   cds.SiteName = Record[3];
   cds.GeoPolName1 = Record[4];
   cds.GeoPolName2 = Record[5];
   cds.GeoPolName3 = Record[6];
   Items.push_back(cds);
}
//---------------------------------------------------------------------------

NeotomaTaxaElements::NeotomaTaxaElements(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetVarElemsByDatasetTypeAndTaxaIDList";
   AddField("TaxonID", varInteger);
   AddField("VariableElement", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaTaxaElements::AddRecord(vector<Variant>& Record)
{
   int TaxonID = VariantToInt(Record[0], -1);
   UnicodeString Element = VarToStr(Record[1]);
   Items.insert(pair<int,UnicodeString>(TaxonID,Element));
}
//---------------------------------------------------------------------------

NeotomaElementDatasetTaxaGroupsTable::NeotomaElementDatasetTaxaGroupsTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetElementDatasetTaxaGroupsTable";
   AddField("DatasetTypeID", varInteger);
   AddField("TaxaGroupID", varOleStr);
   AddField("ElementTypeID", varInteger);
}
//---------------------------------------------------------------------------

void NeotomaElementDatasetTaxaGroupsTable::AddRecord(vector<Variant>& Record)
{
   NTMDATASETTAXAGROUPELEMET edtg;
   edtg.DatasetTypeID = Record[0];
   edtg.TaxaGroupID = Record[1];
   edtg.ElementTypeID = Record[2];
   Items.push_back(edtg);
}
//---------------------------------------------------------------------------

NeotomaElementTypesBase::NeotomaElementTypesBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   AddField("ElementTypeID", varInteger);
   AddField("ElementType", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaElementTypesBase::AddRecord(vector<Variant>& Record)
{
   int ElementTypeID = VariantToInt(Record[0], -1);
   UnicodeString ElementType = VarToStr(Record[1]);
   Items[ElementTypeID] = ElementType;
}
//---------------------------------------------------------------------------

NeotomaElementTypesTable::NeotomaElementTypesTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaElementTypesBase(ipsjsons, tcpClient)
{
   webservice = L"GetElementTypesTable";
}
//---------------------------------------------------------------------------

NeotomaElementTypeByName::NeotomaElementTypeByName(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaElementTypesBase(ipsjsons, tcpClient)
{
   webservice = L"GetElementTypeByName";
}
//---------------------------------------------------------------------------

NeotomaElementTypesByTaxaGroupID::NeotomaElementTypesByTaxaGroupID(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaElementTypesBase(ipsjsons, tcpClient)
{
   webservice = L"GetElementTypesByTaxaGroupID";
}
//---------------------------------------------------------------------------

NeotomaElementTypeFromVariableElement::NeotomaElementTypeFromVariableElement(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaElementTypesBase(ipsjsons, tcpClient)
{
   webservice = L"GetElementTypeFromVariableElement";
}
//---------------------------------------------------------------------------

NeotomaElementTypesByNameList::NeotomaElementTypesByNameList(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaElementTypesBase(ipsjsons, tcpClient)
{
   webservice = L"GetElementTypesByNameList";
}
//---------------------------------------------------------------------------

NeotomaElementTaxaGroupsTable::NeotomaElementTaxaGroupsTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetElementTaxaGroupsTable";
   AddField("ElementTaxaGroupID", varInteger);
   AddField("TaxaGroupID", varOleStr);
   AddField("ElementTypeID", varInteger);
}
//---------------------------------------------------------------------------

void NeotomaElementTaxaGroupsTable::AddRecord(vector<Variant>& Record)
{
   NTMELEMENTTAXAGROUPS etg;
   etg.ElementTaxaGroupID = Record[0];
   etg.TaxaGroupID = Record[1];
   etg.ElementTypeID = Record[2];
   Items.push_back(etg);
}
//---------------------------------------------------------------------------

NeotomaElementSymmetriesBase::NeotomaElementSymmetriesBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   AddField("SymmetryID", varInteger);
   AddField("Symmetry", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaElementSymmetriesBase::AddRecord(vector<Variant>& Record)
{
   int SymmetryID = VariantToInt(Record[0], -1);
   UnicodeString Symmetry = VarToStr(Record[1]);
   Items[SymmetryID] = Symmetry;
}
//---------------------------------------------------------------------------

NeotomaElementSymmetriesTable::NeotomaElementSymmetriesTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaElementSymmetriesBase(ipsjsons, tcpClient)
{
   webservice = L"GetElementSymmetriesTable";
}
//---------------------------------------------------------------------------

NeotomaElementSymmetryByName::NeotomaElementSymmetryByName(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaElementSymmetriesBase(ipsjsons, tcpClient)
{
   webservice = L"GetElementSymmetryByName";
}
//---------------------------------------------------------------------------

NeotomaElementTaxaGroupSymmetriesTable::NeotomaElementTaxaGroupSymmetriesTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetElementTaxaGroupSymmetriesTable";
   AddField("ElementTaxaGroupID", varInteger);
   AddField("SymmetryID", varInteger);
}
//---------------------------------------------------------------------------

void NeotomaElementTaxaGroupSymmetriesTable::AddRecord(vector<Variant>& Record)
{
   int ElementTaxaGroupID = VariantToInt(Record[0], -1);
   int SymmetryID = VariantToInt(Record[1], -1);
   Items.insert(pair<int,int>(ElementTaxaGroupID,SymmetryID));
}
//---------------------------------------------------------------------------

NeotomaElementPortionsBase::NeotomaElementPortionsBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   AddField("PortionID", varInteger);
   AddField("Portion", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaElementPortionsBase::AddRecord(vector<Variant>& Record)
{
   int PortionID = VariantToInt(Record[0], -1);
   UnicodeString Portion = VarToStr(Record[1]);
   Items[PortionID] = Portion;
}
//---------------------------------------------------------------------------

NeotomaElementPortionsTable::NeotomaElementPortionsTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaElementPortionsBase(ipsjsons, tcpClient)
{
   webservice = L"GetElementPortionsTable";
}
//---------------------------------------------------------------------------

NeotomaElementPortionByName::NeotomaElementPortionByName(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaElementPortionsBase(ipsjsons, tcpClient)
{
   webservice = L"GetElementPortionByName";
}
//---------------------------------------------------------------------------

NeotomaElementTaxaGroupPortionsTable::NeotomaElementTaxaGroupPortionsTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetElementTaxaGroupPortionsTable";
   AddField("ElementTaxaGroupID", varInteger);
   AddField("PortionID", varInteger);
}
//---------------------------------------------------------------------------

void NeotomaElementTaxaGroupPortionsTable::AddRecord(vector<Variant>& Record)
{
   int ElementTaxaGroupID = VariantToInt(Record[0], -1);
   int PortionID = VariantToInt(Record[1], -1);
   Items.insert(pair<int,int>(ElementTaxaGroupID,PortionID));
}
//---------------------------------------------------------------------------

NeotomaElementMaturitiesBase::NeotomaElementMaturitiesBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   AddField("MaturityID", varInteger);
   AddField("Maturity", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaElementMaturitiesBase::AddRecord(vector<Variant>& Record)
{
   int MaturityID = VariantToInt(Record[0], -1);
   UnicodeString Maturity = VarToStr(Record[1]);
   Items[MaturityID] = Maturity;
}
//---------------------------------------------------------------------------

NeotomaElementMaturitiesTable::NeotomaElementMaturitiesTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaElementMaturitiesBase(ipsjsons, tcpClient)
{
   webservice = L"GetElementMaturitiesTable";
}
//---------------------------------------------------------------------------

NeotomaElementMaturityByName::NeotomaElementMaturityByName(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaElementMaturitiesBase(ipsjsons, tcpClient)
{
   webservice = L"GetElementMaturityByName";
}
//---------------------------------------------------------------------------

NeotomaElementTaxaGroupMaturitiesTable::NeotomaElementTaxaGroupMaturitiesTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetElementTaxaGroupMaturitiesTable";
   AddField("ElementTaxaGroupID", varInteger);
   AddField("MaturityID", varInteger);
}
//---------------------------------------------------------------------------

void NeotomaElementTaxaGroupMaturitiesTable::AddRecord(vector<Variant>& Record)
{
   int ElementTaxaGroupID = VariantToInt(Record[0], -1);
   int MaturityID = VariantToInt(Record[1], -1);
   Items.insert(pair<int,int>(ElementTaxaGroupID,MaturityID));
}
//---------------------------------------------------------------------------

NeotomaUnitsDatasetTypesTable::NeotomaUnitsDatasetTypesTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetUnitsDatasetTypesTable";
   AddField("DatasetTypeID", varInteger);
   AddField("VariableUnitsID", varInteger);
}
//---------------------------------------------------------------------------

void NeotomaUnitsDatasetTypesTable::AddRecord(vector<Variant>& Record)
{
   int DatasetTypeID = VariantToInt(Record[0], -1);
   int VariableUnitsID = VariantToInt(Record[1], -1);
   Items.insert(pair<int,int>(DatasetTypeID,VariableUnitsID));
}
//---------------------------------------------------------------------------

NeotomaContextsDatasetTypesTable::NeotomaContextsDatasetTypesTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetContextsDatasetTypesTable";
   AddField("DatasetTypeID", varInteger);
   AddField("VariableContextID", varInteger);
}
//---------------------------------------------------------------------------

void NeotomaContextsDatasetTypesTable::AddRecord(vector<Variant>& Record)
{
   int DatasetTypeID = VariantToInt(Record[0], -1);
   int VariableContextID = VariantToInt(Record[1], -1);
   Items.insert(pair<int,int>(DatasetTypeID,VariableContextID));
}
//---------------------------------------------------------------------------

NeotomaTaphonomicSystemsBase::NeotomaTaphonomicSystemsBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   AddField("TaphonomicSystemID", varInteger);
   AddField("TaphonomicSystem", varOleStr);
   AddField("Notes", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaTaphonomicSystemsBase::AddRecord(vector<Variant>& Record)
{
   NTMTAPHONOMICSYSTEMS ts;
   ts.TaphonomicSystemID = VariantToInt(Record[0], -1);
   ts.TaphonomicSystem = VarToStr(Record[1]);
   ts.Notes = VarToStr(Record[2]);
   Items.push_back(ts);
}
//---------------------------------------------------------------------------

void NeotomaTaphonomicSystemsBase::IndexItems(void)
{
   vector<NTMTAPHONOMICSYSTEMS>::pointer ptr;
   int nItems = Items.size();
   int TaphNamePos = FieldPos["TaphonomicSystem"];
   for (int i=0; i<nItems; i++) {
	 ptr = &Items[i];
	 Fields[TaphNamePos].SIndex.insert(pair<UnicodeString, void*>(Items[i].TaphonomicSystem, (void*)ptr));
	 }
}
//---------------------------------------------------------------------------

NeotomaTaphonomicSystemsTable::NeotomaTaphonomicSystemsTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaTaphonomicSystemsBase(ipsjsons, tcpClient)
{
   webservice = L"GetTaphonomicSystemsTable";
}
//---------------------------------------------------------------------------

NeotomaTaphonomicSystemsByDatasetType::NeotomaTaphonomicSystemsByDatasetType(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaTaphonomicSystemsBase(ipsjsons, tcpClient)
{
   webservice = L"GetTaphonomicSystemsByDatasetType";
}
//---------------------------------------------------------------------------

NeotomaTaphonomicSystemByName::NeotomaTaphonomicSystemByName(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaTaphonomicSystemsBase(ipsjsons, tcpClient)
{
   webservice = L"GetTaphonomicSystemByName";
}
//---------------------------------------------------------------------------

NeotomaTaphonomicSystemsDatasetTypesTable::NeotomaTaphonomicSystemsDatasetTypesTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetTaphonomicSystemsDatasetTypesTable";
   AddField("DatasetTypeID", varInteger);
   AddField("TaphonomicSystemID", varInteger);
}
//---------------------------------------------------------------------------

void NeotomaTaphonomicSystemsDatasetTypesTable::AddRecord(vector<Variant>& Record)
{
   int DatasetTypeID = VariantToInt(Record[0], -1);
   int TaphonomicSystemID = VariantToInt(Record[1], -1);
   Items.insert(pair<int,int>(DatasetTypeID,TaphonomicSystemID));
}
//---------------------------------------------------------------------------

NeotomaTaphonomicTypesBase::NeotomaTaphonomicTypesBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{

   AddField("TaphonomicTypeID", varInteger);
   AddField("TaphonomicSystemID", varInteger);
   AddField("TaphonomicType", varOleStr);
   AddField("Notes", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaTaphonomicTypesBase::AddRecord(vector<Variant>& Record)
{
   NTMTAPHONOMICTYPES tt;
   tt.TaphonomicTypeID = VariantToInt(Record[0], -1);
   tt.TaphonomicSystemID = VariantToInt(Record[1], -1);
   tt.TaphonomicType = VarToStr(Record[2]);
   tt.Notes = VarToStr(Record[3]);
   Items.push_back(tt);
}
//---------------------------------------------------------------------------

NeotomaTaphonomicTypesTable::NeotomaTaphonomicTypesTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaTaphonomicTypesBase(ipsjsons, tcpClient)
{
   webservice = L"GetTaphonomicTypesTable";
}
//---------------------------------------------------------------------------

NeotomaTaphonomicTypesBySystem::NeotomaTaphonomicTypesBySystem(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaTaphonomicTypesBase(ipsjsons, tcpClient)
{
   webservice = L"GetTaphonomicTypesBySystem";
}
//---------------------------------------------------------------------------

void NeotomaTaphonomicTypesBySystem::IndexItems(void)
{
   vector<NTMTAPHONOMICTYPES>::pointer ptr;
   int nItems = Items.size();
   int TaphTypePos = FieldPos["TaphonomicType"];
   for (int i=0; i<nItems; i++) {
	 ptr = &Items[i];
	 Fields[TaphTypePos].SIndex.insert(pair<UnicodeString, void*>(Items[i].TaphonomicType, (void*)ptr));
	 }
}
//---------------------------------------------------------------------------

NeotomaSynonym::NeotomaSynonym(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetValidSynonymByInvalidTaxonID";
   AddField("SynonymID", varInteger);
   AddField("InvalidTaxonID", varInteger);
   AddField("ValidTaxonID", varInteger);
   AddField("SynonymTypeID", varInteger);
}
//---------------------------------------------------------------------------

void NeotomaSynonym::AddRecord(vector<Variant>& Record)
{
   NTMSYNONYM syn;
   syn.SynonymID = VariantToInt(Record[0], -1);
   syn.InvalidTaxonID = VariantToInt(Record[1], -1);
   syn.ValidTaxonID = VariantToInt(Record[2], -1);
   syn.SynonymTypeID = VariantToInt(Record[3], -1);
   Items.push_back(syn);
}
//---------------------------------------------------------------------------

NeotomaLookupSynonym::NeotomaLookupSynonym(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetTaxaLookupSynonymyByTaxaGroupIDList";
   AddField("TaxonID", varInteger);
   AddField("TaxonName", varOleStr);
   AddField("ValidTaxonID", varInteger);
}
//---------------------------------------------------------------------------

void NeotomaLookupSynonym::AddRecord(vector<Variant>& Record)
{
   NTMLOOKUPSYNONYM lusyn;
   lusyn.TaxonID = VariantToInt(Record[0], -1);
   lusyn.TaxonName = VarToStr(Record[1]);
   lusyn.ValidTaxonID = VariantToInt(Record[2], -1);
   Items.push_back(lusyn);
}
//---------------------------------------------------------------------------

NeotomaElementTaxaGroupID::NeotomaElementTaxaGroupID(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetElementTaxaGroupID";
   AddField("ElementTaxaGroupID", varInteger);
}
//---------------------------------------------------------------------------

void NeotomaElementTaxaGroupID::AddRecord(vector<Variant>& Record)
{
   int ElementTaxaGroupID = VariantToInt(Record[0], -1);
   Items.push_back(ElementTaxaGroupID);
}
//---------------------------------------------------------------------------

NeotomaVariableUnitsTableByDatasetTypeID::NeotomaVariableUnitsTableByDatasetTypeID(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetVariableUnitsTableByDatasetTypeID";
   AddField("VariableUnits", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaVariableUnitsTableByDatasetTypeID::AddRecord(vector<Variant>& Record)
{
   UnicodeString Units = VarToStr(Record[0]);
   Items.insert(Units);
}
//---------------------------------------------------------------------------

NeotomaVariableUnitsID::NeotomaVariableUnitsID(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetVariableUnitsID";
   AddField("VariableUnitsID", varInteger);
}
//---------------------------------------------------------------------------

void NeotomaVariableUnitsID::AddRecord(vector<Variant>& Record)
{
   int VariableUnitsID = VariantToInt(Record[0], -1);
   Items.push_back(VariableUnitsID);
}
//---------------------------------------------------------------------------

NeotomaVariableContextsTableByDatasetTypeID::NeotomaVariableContextsTableByDatasetTypeID(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetVariableContextsTableByDatasetTypeID";
   AddField("VariableContext", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaVariableContextsTableByDatasetTypeID::AddRecord(vector<Variant>& Record)
{
   UnicodeString Context = VarToStr(Record[0]);
   Items.insert(Context);
}
//---------------------------------------------------------------------------

NeotomaVariableContextID::NeotomaVariableContextID(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetVariableContextID";
   AddField("VariableContextID", varInteger);
}
//---------------------------------------------------------------------------

void NeotomaVariableContextID::AddRecord(vector<Variant>& Record)
{
   int VariableContextID = VariantToInt(Record[0], -1);
   Items.push_back(VariableContextID);
}
//---------------------------------------------------------------------------

NeotomaRockTypesBase::NeotomaRockTypesBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   AddField("RockTypeID", varInteger);
   AddField("RockType", varOleStr);
   AddField("HigherRockTypeID", varInteger);
   AddField("Description", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaRockTypesBase::AddRecord(vector<Variant>& Record)
{
   ROCKTYPE rt;
   rt.RockTypeID = VariantToInt(Record[0], -1);
   rt.RockType = VarToStr(Record[1]);
   rt.HigherRockTypeID = VariantToInt(Record[2], -1);
   rt.Description = VarToStr(Record[3]);
   Items.push_back(rt);
}
//---------------------------------------------------------------------------

NeotomaRockTypesTable::NeotomaRockTypesTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaRockTypesBase(ipsjsons, tcpClient)
{
   webservice = L"GetRockTypesTable";
}
//---------------------------------------------------------------------------

NeotomaRockTypeByName::NeotomaRockTypeByName(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaRockTypesBase(ipsjsons, tcpClient)
{
   webservice = L"GetRockTypeByName";
}
//---------------------------------------------------------------------------

NeotomaRockTypeByID::NeotomaRockTypeByID(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaRockTypesBase(ipsjsons, tcpClient)
{
   webservice = L"GetRockTypeByID";
}
//---------------------------------------------------------------------------

NeotomaFaciesTypesBase::NeotomaFaciesTypesBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   AddField("FaciesID", varInteger);
   AddField("Facies", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaFaciesTypesBase::AddRecord(vector<Variant>& Record)
{
   int FaciesID = VariantToInt(Record[0], -1);
   UnicodeString Facies = VarToStr(Record[1]);
   Items[FaciesID] = Facies;
}
//---------------------------------------------------------------------------

NeotomaFaciesTypesTable::NeotomaFaciesTypesTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaFaciesTypesBase(ipsjsons, tcpClient)
{
   webservice = L"GetFaciesTypesTable";
}
//---------------------------------------------------------------------------

NeotomaFaciesTypeByName::NeotomaFaciesTypeByName(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaFaciesTypesBase(ipsjsons, tcpClient)
{
   webservice = L"GetFaciesTypeByName";
}
//---------------------------------------------------------------------------

NeotomaDepAgentsBase::NeotomaDepAgentsBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   AddField("DepAgentID", varInteger);
   AddField("DepAgent", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaDepAgentsBase::AddRecord(vector<Variant>& Record)
{
   int DepAgentID = VariantToInt(Record[0], -1);
   UnicodeString DepAgent = VarToStr(Record[1]);
   Items[DepAgentID] = DepAgent;
}
//---------------------------------------------------------------------------

NeotomaDepAgentsTable::NeotomaDepAgentsTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaDepAgentsBase(ipsjsons, tcpClient)
{
   webservice = L"GetDepAgentsTypesTable";
}
//---------------------------------------------------------------------------

NeotomaDepAgentByName::NeotomaDepAgentByName(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaDepAgentsBase(ipsjsons, tcpClient)
{
   webservice = L"GetDepAgentByName";
}
//---------------------------------------------------------------------------

NeotomaRepositoryInstitutionBase::NeotomaRepositoryInstitutionBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   AddField("RepositoryID", varInteger);
   AddField("Acronym", varOleStr);
   AddField("Repository", varOleStr);
   AddField("Notes", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaRepositoryInstitutionBase::AddRecord(vector<Variant>& Record)
{
   REPOSITORY rep;
   rep.RepositoryID = VariantToInt(Record[0], -1);
   rep.Acronym = VarToStr(Record[1]);
   rep.Repository = VarToStr(Record[2]);
   rep.Notes = VarToStr(Record[3]);
   Items.push_back(rep);
}
//---------------------------------------------------------------------------

NeotomaRepositoryInstitutionsTable::NeotomaRepositoryInstitutionsTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaRepositoryInstitutionBase(ipsjsons, tcpClient)
{
   webservice = L"GetRepositoryInstitutionsTable";
}
//---------------------------------------------------------------------------

NeotomaDatasetRepository::NeotomaDatasetRepository(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaRepositoryInstitutionBase(ipsjsons, tcpClient)
{
   webservice = L"GetDatasetRepository";
}
//---------------------------------------------------------------------------

NeotomaRepositoryInstitution::NeotomaRepositoryInstitution(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaRepositoryInstitutionBase(ipsjsons, tcpClient)
{
   webservice = L"GetRepositoryInstitution";
}
//---------------------------------------------------------------------------

NeotomaGeochronTypesTable::NeotomaGeochronTypesTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetGeochronTypesTable";
   AddField("GeochronTypeID", varInteger);
   AddField("GeochronType", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaGeochronTypesTable::AddRecord(vector<Variant>& Record)
{
   int GeochronTypeID = VariantToInt(Record[0], -1);
   UnicodeString GeochronType = VarToStr(Record[1]);
   Items[GeochronTypeID] = GeochronType;
}
//---------------------------------------------------------------------------

NeotomaRadiocarbonMethodsTable::NeotomaRadiocarbonMethodsTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetRadiocarbonMethodsTable";
   AddField("RadiocarbonMethodID", varInteger);
   AddField("RadiocarbonMethod", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaRadiocarbonMethodsTable::AddRecord(vector<Variant>& Record)
{
   int RadiocarbonMethodID = VariantToInt(Record[0], -1);
   UnicodeString RadiocarbonMethod = VarToStr(Record[1]);
   Items[RadiocarbonMethodID] = RadiocarbonMethod;
}
//---------------------------------------------------------------------------

NeotomaFractionDatedBase::NeotomaFractionDatedBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   AddField("FractionID", varInteger);
   AddField("Fraction", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaFractionDatedBase::AddRecord(vector<Variant>& Record)
{
   int FractionID = VariantToInt(Record[0], -1);
   UnicodeString Fraction = VarToStr(Record[1]);
   Items[FractionID] = Fraction;
}
//---------------------------------------------------------------------------

NeotomaFractionDatedTable::NeotomaFractionDatedTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaFractionDatedBase(ipsjsons, tcpClient)
{
   webservice = L"GetFractionDatedTable";
}
//---------------------------------------------------------------------------

NeotomaFractionsDatedByList::NeotomaFractionsDatedByList(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaFractionDatedBase(ipsjsons, tcpClient)
{
   webservice = L"GetFractionsDatedByList";
}
//---------------------------------------------------------------------------

NeotomaFractionDatedByName::NeotomaFractionDatedByName(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaFractionDatedBase(ipsjsons, tcpClient)
{
   webservice = L"GetFractionDatedByName";
}
//---------------------------------------------------------------------------


NeotomaChronControlTypesBase::NeotomaChronControlTypesBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   AddField("ChronControlTypeID", varInteger);
   AddField("ChronControlType", varOleStr);
   AddField("HigherChronControlTypeID", varInteger);
}
//---------------------------------------------------------------------------

void NeotomaChronControlTypesBase::AddRecord(vector<Variant>& Record)
{
   CHRONCONTROLTYPE cct;
   cct.ChronControlTypeID = VariantToInt(Record[0], -1);
   cct.ChronControlType = VarToStr(Record[1]);
   cct.HigherChronControlTypeID = VariantToInt(Record[2], -1);
   Items.push_back(cct);
}
//---------------------------------------------------------------------------

NeotomaChronControlTypesTable::NeotomaChronControlTypesTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaChronControlTypesBase(ipsjsons, tcpClient)
{
   webservice = L"GetChronControlTypesTable";
}
//---------------------------------------------------------------------------

NeotomaChronControlTypeByName::NeotomaChronControlTypeByName(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaChronControlTypesBase(ipsjsons, tcpClient)
{
   webservice = L"GetChronConrolTypeByName";
}
//---------------------------------------------------------------------------

NeotomaChronControlTypeHighestID::NeotomaChronControlTypeHighestID(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaChronControlTypesBase(ipsjsons, tcpClient)
{
   webservice = L"GetChronControlTypeHighestID";
}
//---------------------------------------------------------------------------

NeotomaEventTypesBase::NeotomaEventTypesBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   AddField("EventTypeID", varInteger);
   AddField("EventType", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaEventTypesBase::AddRecord(vector<Variant>& Record)
{
   int EventTypeID = VariantToInt(Record[0], -1);
   UnicodeString EventType = VarToStr(Record[1]);
   Items[EventTypeID] = EventType;
}
//---------------------------------------------------------------------------

NeotomaEventTypesTable::NeotomaEventTypesTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaEventTypesBase(ipsjsons, tcpClient)
{
   webservice = L"GetEventTypesTable";
};
//---------------------------------------------------------------------------

NeotomaEventTypeByName::NeotomaEventTypeByName(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaEventTypesBase(ipsjsons, tcpClient)
{
   webservice = L"GetEventTypeByName";
};
//---------------------------------------------------------------------------

NeotomaEventsBase::NeotomaEventsBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   AddField("EventID", varInteger);
   AddField("EventTypeID", varInteger);
   AddField("EventName", varOleStr);
   AddField("C14Age", varDouble);
   AddField("C14AgeYounger", varDouble);
   AddField("C14AgeOlder", varDouble);
   AddField("CalAge", varDouble);
   AddField("CalAgeYounger", varDouble);
   AddField("CalAgeOlder", varDouble);
   AddField("Notes", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaEventsBase::AddRecord(vector<Variant>& Record)
{
   NTMEVENT event;
   event.EventID = VariantToInt(Record[0], -1);
   event.EventTypeID = VariantToInt(Record[1], -1);
   event.EventName = VarToStr(Record[2]);
   event.C14Age = Record[3];
   event.C14AgeYounger = Record[4];
   event.C14AgeOlder = Record[5];
   event.CalAge = Record[6];
   event.CalAgeYounger = Record[7];
   event.CalAgeOlder = Record[8];
   event.Notes = VarToStr(Record[9]);
   Items.push_back(event);
}
//---------------------------------------------------------------------------

NeotomaEventsTable::NeotomaEventsTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaEventsBase(ipsjsons, tcpClient)
{
   webservice = L"GetEventsTable";
};
//---------------------------------------------------------------------------

NeotomaEventByName::NeotomaEventByName(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaEventsBase(ipsjsons, tcpClient)
{
   webservice = L"GetEventByName";
};
//---------------------------------------------------------------------------

NeotomaAgeTypesTable::NeotomaAgeTypesTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetAgeTypesTable";
   AddField("AgeTypeID", varInteger);
   AddField("AgeType", varOleStr);
   AddField("ShortAgeType", varOleStr);
   AddField("Precedence", varInteger);
}
//---------------------------------------------------------------------------

void NeotomaAgeTypesTable::AddRecord(vector<Variant>& Record)
{
   AGETYPE at;
   at.AgeTypeID = VariantToInt(Record[0], -1);
   at.AgeType = VarToStr(Record[1]);
   at.ShortAgeType = VarToStr(Record[2]);
   at.Precedence = VariantToInt(Record[3], -1);
   Items.push_back(at);
}
//---------------------------------------------------------------------------

NeotomaRelativeAgeScalesBase::NeotomaRelativeAgeScalesBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   AddField("RelativeAgeScaleID", varInteger);
   AddField("RelativeAgeScale", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaRelativeAgeScalesBase::AddRecord(vector<Variant>& Record)
{
   int RelativeAgeScaleID = VariantToInt(Record[0], -1);
   UnicodeString RelativeAgeScale = VarToStr(Record[1]);
   Items[RelativeAgeScaleID] = RelativeAgeScale;
}
//---------------------------------------------------------------------------

NeotomaRelativeAgeScalesTable::NeotomaRelativeAgeScalesTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaRelativeAgeScalesBase(ipsjsons, tcpClient)
{
   webservice = L"GetRelativeAgeScalesTable";
}
//---------------------------------------------------------------------------

NeotomaRelativeAgeScaleByName::NeotomaRelativeAgeScaleByName(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaRelativeAgeScalesBase(ipsjsons, tcpClient)
{
   webservice = L"GetRelativeAgeScaleByName";
}
//---------------------------------------------------------------------------

NeotomaRelativeAgesBase::NeotomaRelativeAgesBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   AddField("RelativeAgeID", varInteger);
   AddField("RelativeAgeUnitID", varInteger);
   AddField("RelativeAgeScaleID", varInteger);
   AddField("RelativeAge", varOleStr);
   AddField("C14AgeYounger", varDouble);
   AddField("C14AgeOlder", varDouble);
   AddField("CalAgeYounger", varDouble);
   AddField("CalAgeOlder", varDouble);
   AddField("Notes", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaRelativeAgesBase::AddRecord(vector<Variant>& Record)
{
   NTMRELATIVEAGE ra;
   ra.RelativeAgeID = VariantToInt(Record[0], -1);
   ra.RelativeAgeUnitID = VariantToInt(Record[1], -1);
   ra.RelativeAgeScaleID = VariantToInt(Record[2], -1);
   ra.RelativeAge = VarToStr(Record[3]);
   ra.C14AgeYounger = Record[4];
   ra.C14AgeOlder = Record[5];
   ra.CalAgeYounger = Record[6];
   ra.CalAgeOlder = Record[7];
   ra.Notes = VarToStr(Record[8]);
   Items.push_back(ra);
}
//---------------------------------------------------------------------------

NeotomaRelativeAgesTable::NeotomaRelativeAgesTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaRelativeAgesBase(ipsjsons, tcpClient)
{
   webservice = L"GetRelativeAgesTable";
}
//---------------------------------------------------------------------------

NeotomaRelativeAgeByName::NeotomaRelativeAgeByName(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaRelativeAgesBase(ipsjsons, tcpClient)
{
   webservice = L"GetRelativeAgeByName";
}
//---------------------------------------------------------------------------

NeotomaCalibrationCurvesTable::NeotomaCalibrationCurvesTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetCalibrationCurvesTable";
   AddField("CalibrationCurveID", varInteger);
   AddField("CalibrationCurve", varOleStr);
   AddField("PublicationID", varInteger);
}
//---------------------------------------------------------------------------

void NeotomaCalibrationCurvesTable::AddRecord(vector<Variant>& Record)
{
   CALIBRATIONCURVE cc;
   cc.CalibrationCurveID = VariantToInt(Record[0], -1);
   cc.CalibrationCurve = VarToStr(Record[1]);
   cc.PublicationID = VariantToInt(Record[2], -1);
   Items.push_back(cc);
}
//---------------------------------------------------------------------------

NeotomaCalibrationProgramsTable::NeotomaCalibrationProgramsTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetCalibrationProgramsTable";
   AddField("CalibrationProgramID", varInteger);
   AddField("CalibrationProgram", varOleStr);
   AddField("Version", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaCalibrationProgramsTable::AddRecord(vector<Variant>& Record)
{
   CALIBRATIONPROGRAM cp;
   cp.CalibrationProgramID = VariantToInt(Record[0], -1);
   cp.CalibrationProgram = VarToStr(Record[1]);
   cp.Version = VarToStr(Record[2]);
   Items.push_back(cp);
}
//---------------------------------------------------------------------------

NeotomaTaxaGroupElementTypes::NeotomaTaxaGroupElementTypes(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetTaxaGroupElementTypes";
   AddField("TaxaGroupID", varOleStr);
   AddField("ElementType", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaTaxaGroupElementTypes::AddRecord(vector<Variant>& Record)
{
   UnicodeString TaxaGroupID = VarToStr(Record[0]);
   UnicodeString ElementType = VarToStr(Record[1]);
   Items.insert(pair<UnicodeString,UnicodeString>(TaxaGroupID,ElementType));
}
//---------------------------------------------------------------------------

NeotomaEcolSetsGroups::NeotomaEcolSetsGroups(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetEcolSetsGroupsByTaxonID";
   AddField("TaxonID", varInteger);
   AddField("EcolSetID", varInteger);
   AddField("EcolSetName", varOleStr);
   AddField("EcolGroupID", varOleStr);
   AddField("EcolGroup", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaEcolSetsGroups::AddRecord(vector<Variant>& Record)
{
   ECOLSETGROUP esg;
   esg.TaxonID = VariantToInt(Record[0], -1);
   esg.EcolSetID = VariantToInt(Record[1], -1);
   esg.EcolSetName = VarToStr(Record[2]);
   esg.EcolGroupID = VarToStr(Record[3]);
   esg.EcolGroup = VarToStr(Record[4]);
   Items.push_back(esg);
}
//---------------------------------------------------------------------------

NeotomaEcolSetTypesTable::NeotomaEcolSetTypesTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetEcolSetTypesTable";
   AddField("EcolSetID", varInteger);
   AddField("EcolSetName", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaEcolSetTypesTable::AddRecord(vector<Variant>& Record)
{
   int EcolSetID = VariantToInt(Record[0], -1);
   UnicodeString EcolSetName = VarToStr(Record[1]);
   Items[EcolSetID] = EcolSetName;
}
//---------------------------------------------------------------------------

NeotomaEcolSetCounts::NeotomaEcolSetCounts(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetEcolSetCountsByTaxaGroupID";
   AddField("EcolSetID", varInteger);
   AddField("EcolSetName", varOleStr);
   AddField("Count", varInteger);
}
//---------------------------------------------------------------------------

void NeotomaEcolSetCounts::AddRecord(vector<Variant>& Record)
{
   ECOLSETCOUNT esc;
   esc.EcolSetID = VariantToInt(Record[0], -1);
   esc.EcolSetName = VarToStr(Record[1]);
   esc.Count = VariantToInt(Record[2], -1);
   Items.push_back(esc);
}
//---------------------------------------------------------------------------

NeotomaEcolGroupsByEcolSetID::NeotomaEcolGroupsByEcolSetID(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetEcolGroupsByEcolSetID";
   AddField("EcolGroupID", varOleStr);
   AddField("EcolGroup", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaEcolGroupsByEcolSetID::AddRecord(vector<Variant>& Record)
{
   UnicodeString EcolGroupID = VarToStr(Record[0]);
   UnicodeString EcolGroup = VarToStr(Record[1]);
   Items[EcolGroupID] = EcolGroup;
}
//---------------------------------------------------------------------------

NeotomaEcolGroupTypesTable::NeotomaEcolGroupTypesTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetEcolGroupTypesTable";
   AddField("EcolGroupID", varOleStr);
   AddField("EcolGroup", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaEcolGroupTypesTable::AddRecord(vector<Variant>& Record)
{
   UnicodeString EcolGroupID = VarToStr(Record[0]);
   UnicodeString EcolGroup = VarToStr(Record[1]);
   Items[EcolGroupID] = EcolGroup;
}
//---------------------------------------------------------------------------

NeotomaSynonymTypesTable::NeotomaSynonymTypesTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetSynonymTypesTable";
   AddField("SynonymTypeID", varInteger);
   AddField("SynonymType", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaSynonymTypesTable::AddRecord(vector<Variant>& Record)
{
   int SynonymTypeID = VariantToInt(Record[0], -1);
   UnicodeString SynonymType = VarToStr(Record[1]);
   Items[SynonymTypeID] = SynonymType;
}
//---------------------------------------------------------------------------

NeotomaSynonymType::NeotomaSynonymType(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaSynonymTypesTable(ipsjsons, tcpClient)
{
   webservice = L"GetSynonymType";
}
//---------------------------------------------------------------------------

NeotomaCount::NeotomaCount(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   AddField("Count", varInteger);
}
//---------------------------------------------------------------------------

void NeotomaCount::AddRecord(vector<Variant>& Record)
{
   int Count = VariantToInt(Record[0], -1);
   Items.push_back(Count);
}
//---------------------------------------------------------------------------

NeotomaTaxaByNamesCount::NeotomaTaxaByNamesCount(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaCount(ipsjsons, tcpClient)
{
   webservice = L"GetTaxaByNamesCount";
}
//---------------------------------------------------------------------------

NeotomaTableRecordCount::NeotomaTableRecordCount(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaCount(ipsjsons, tcpClient)
{
   webservice = L"GetTableRecordCount";
}
//---------------------------------------------------------------------------

NeotomaChildTaxaCount::NeotomaChildTaxaCount(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaCount(ipsjsons, tcpClient)
{
   webservice = L"GetChildTaxaCount";
}
//---------------------------------------------------------------------------

NeotomaTaxonDataRecordsCount::NeotomaTaxonDataRecordsCount(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaCount(ipsjsons, tcpClient)
{
   webservice = L"GetTaxonDataRecordsCount";
}
//---------------------------------------------------------------------------

NeotomaVariableDataRecordsCount::NeotomaVariableDataRecordsCount(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaCount(ipsjsons, tcpClient)
{
   webservice = L"GetVariableDataRecordsCount";
}
//---------------------------------------------------------------------------

NeotomaTaxonSpecimenDatesCount::NeotomaTaxonSpecimenDatesCount(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaCount(ipsjsons, tcpClient)
{
   webservice = L"GetTaxonSpecimenDatesCount";
}
//---------------------------------------------------------------------------

NeotomaTaxonSynonymsCount::NeotomaTaxonSynonymsCount(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaCount(ipsjsons, tcpClient)
{
   webservice = L"GetTaxonSynonymsCount";
}
//---------------------------------------------------------------------------

NeotomaTaxonSynonymyCount::NeotomaTaxonSynonymyCount(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaCount(ipsjsons, tcpClient)
{
   webservice = L"GetTaxonSynonymyCount";
}
//---------------------------------------------------------------------------

NeotomaInvalidTaxonSynonymyCount::NeotomaInvalidTaxonSynonymyCount(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaCount(ipsjsons, tcpClient)
{
   webservice = L"GetInvalidTaxonSynonymyCount";
}
//---------------------------------------------------------------------------

NeotomaElementDatasetTaxaGroupCount::NeotomaElementDatasetTaxaGroupCount(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaCount(ipsjsons, tcpClient)
{
   webservice = L"GetElementDatasetTaxaGroupCount";
}
//---------------------------------------------------------------------------

NeotomaUnitsDatasetTypeCount::NeotomaUnitsDatasetTypeCount(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaCount(ipsjsons, tcpClient)
{
   webservice = L"GetUnitsDatasetTypeCount";
}
//---------------------------------------------------------------------------

NeotomaContextDatasetTypeCount::NeotomaContextDatasetTypeCount(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaCount(ipsjsons, tcpClient)
{
   webservice = L"GetContextDatasetTypeCount";
}
//---------------------------------------------------------------------------

NeotomaCollUnitHandleCount::NeotomaCollUnitHandleCount(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaCount(ipsjsons, tcpClient)
{
   webservice = L"GetCollUnitHandleCount";
}
//---------------------------------------------------------------------------

NeotomaNextLowerGeoPolCountByNames::NeotomaNextLowerGeoPolCountByNames(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaCount(ipsjsons, tcpClient)
{
   webservice = L"GetNextLowerGeoPolCountByNames";
}
//---------------------------------------------------------------------------

NeotomaSpecimenByIDCount::NeotomaSpecimenByIDCount(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaCount(ipsjsons, tcpClient)
{
   webservice = L"GetSpecimenByIDCount";
}
//---------------------------------------------------------------------------

NeotomaSampleTaxonCount::NeotomaSampleTaxonCount(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaCount(ipsjsons, tcpClient)
{
   webservice = L"GetSampleTaxonCount";
}
//---------------------------------------------------------------------------

NeotomaPublicationTypesTable::NeotomaPublicationTypesTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetPublicationTypesTable";
   AddField("PubTypeID", varInteger);
   AddField("PubType", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaPublicationTypesTable::AddRecord(vector<Variant>& Record)
{
   int PubTypeID = VariantToInt(Record[0], -1);
   UnicodeString PubType = VarToStr(Record[1]);
   Items[PubTypeID] = PubType;
}
//---------------------------------------------------------------------------

NeotomaTableMinID::NeotomaTableMinID(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetTableMinID";
   AddField("MinID", varInteger);
}
//---------------------------------------------------------------------------

void NeotomaTableMinID::AddRecord(vector<Variant>& Record)
{
   int MinID = VariantToInt(Record[0], -1);
   Items.push_back(MinID);
}
//---------------------------------------------------------------------------

NeotomaTableMaxID::NeotomaTableMaxID(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetTableMaxID";
   AddField("MaxID", varInteger);
}
//---------------------------------------------------------------------------

void NeotomaTableMaxID::AddRecord(vector<Variant>& Record)
{
   int MaxID = VariantToInt(Record[0], -1);
   Items.push_back(MaxID);
}
//---------------------------------------------------------------------------

NeotomaGetMinPubIDByPubIDType::NeotomaGetMinPubIDByPubIDType(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetMinPubIDByPubIDType";
   AddField("MinPubID", varInteger);
}
//---------------------------------------------------------------------------

void NeotomaGetMinPubIDByPubIDType::AddRecord(vector<Variant>& Record)
{
   int MinPubID = VariantToInt(Record[0], -1);
   Items.push_back(MinPubID);
}
//---------------------------------------------------------------------------

NeotomaGetMaxPubIDByPubIDType::NeotomaGetMaxPubIDByPubIDType(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetMaxPubIDByPubIDType";
   AddField("MaxPubID", varInteger);
}
//---------------------------------------------------------------------------

void NeotomaGetMaxPubIDByPubIDType::AddRecord(vector<Variant>& Record)
{
   int MaxPubID = VariantToInt(Record[0], -1);
   Items.push_back(MaxPubID);
}
//---------------------------------------------------------------------------

NeotomaGetElementByTaxonID::NeotomaGetElementByTaxonID(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetElementsByTaxonID";
   AddField("VariableElementID", varInteger);
   AddField("ElementType", varOleStr);
   AddField("Symmetry", varOleStr);
   AddField("Portion", varOleStr);
   AddField("Maturity", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaGetElementByTaxonID::AddRecord(vector<Variant>& Record)
{
   NEOTOMAELEMENT elem;
   elem.VariableElementID = VariantToInt(Record[0], -1);
   elem.ElementType = VarToStr(Record[1]);
   elem.Symmetry = VarToStr(Record[2]);
   elem.Portion = VarToStr(Record[3]);
   elem.Maturity = VarToStr(Record[4]);
   Items.push_back(elem);
}
//---------------------------------------------------------------------------

NeotomaGetVariableElementByName::NeotomaGetVariableElementByName(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetVariableElementByName";
   AddField("VariableElementID", varInteger);
   AddField("ElementTypeID", varInteger);
   AddField("SymmetryID", varInteger);
   AddField("PortionID", varInteger);
   AddField("MaturityID", varInteger);
}
//---------------------------------------------------------------------------

void NeotomaGetVariableElementByName::AddRecord(vector<Variant>& Record)
{
   NEOTOMAVARIABLEELEMENTIDS vids;
   vids.VariableElementID = VariantToInt(Record[0], -1);
   vids.ElementTypeID = VariantToInt(Record[1], -1);
   vids.SymmetryID = VariantToInt(Record[2], -1);
   vids.PortionID = VariantToInt(Record[3], -1);
   vids.MaturityID = VariantToInt(Record[4], -1);
   Items.push_back(vids);
}
//---------------------------------------------------------------------------

NeotomaGetElementPartID::NeotomaGetElementPartID(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetElementPartID";
   AddField("SymmetryID", varInteger);
   AddField("PortionID", varInteger);
   AddField("MaturityID", varInteger);
}
//---------------------------------------------------------------------------

void NeotomaGetElementPartID::AddRecord(vector<Variant>& Record)
{
   NEOTOMAELEMENTPARTIDS part;
   part.SymmetryID = VariantToInt(Record[0], -1);
   part.PortionID = VariantToInt(Record[1], -1);
   part.MaturityID = VariantToInt(Record[2], -1);
   Items.push_back(part);
}
//---------------------------------------------------------------------------

NeotomaVariableElementByPartIDs::NeotomaVariableElementByPartIDs(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetVariableElementByPartIDs";
   AddField("VariableElementID", varInteger);
}
//---------------------------------------------------------------------------

void NeotomaVariableElementByPartIDs::AddRecord(vector<Variant>& Record)
{
   int VarElemID = VariantToInt(Record[0], -1);
   Items.push_back(VarElemID);
}
//---------------------------------------------------------------------------

NeotomaSpecimenDatesBase::NeotomaSpecimenDatesBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   AddField("SpecimenDateID", varInteger);
   AddField("GeochronID", varInteger);
   AddField("TaxonID", varInteger);
   AddField("FractionID", varInteger);
   AddField("SampleID", varInteger);
   AddField("ElementTypeID", varInteger);
   AddField("Notes", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaSpecimenDatesBase::AddRecord(vector<Variant>& Record)
{
   NEOTOMASPECIMENDATE date;
   date.SpecimenDateID = VariantToInt(Record[0], -1);
   date.GeochronID = VariantToInt(Record[1], -1);
   date.TaxonID = VariantToInt(Record[2], -1);
   date.FractionID = VariantToInt(Record[3], -1);
   date.SampleID = VariantToInt(Record[4], -1);
   date.ElementTypeID = VariantToInt(Record[5], -1);
   date.Notes = VarToStr(Record[6]);
   Items.push_back(date);
}
//---------------------------------------------------------------------------

NeotomaSpecimenDatesByTaxonID::NeotomaSpecimenDatesByTaxonID(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaSpecimenDatesBase(ipsjsons, tcpClient)
{
   webservice = L"GetSpecimenDatesByTaxonID";
}
//---------------------------------------------------------------------------

NeotomaDatasetIDsByTaxonID::NeotomaDatasetIDsByTaxonID(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetDatasetIDsByTaxonID";
   AddField("DatasetID", varInteger);
}
//---------------------------------------------------------------------------

void NeotomaDatasetIDsByTaxonID::AddRecord(vector<Variant>& Record)
{
   int DatasetID = VariantToInt(Record[0], -1);
   Items.push_back(DatasetID);
}
//---------------------------------------------------------------------------

NeotomaRelativeAgeUnitsByAgeScale::NeotomaRelativeAgeUnitsByAgeScale(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetRelativeAgeUnitsByAgeScale";
   AddField("RelativeAgeUnitID", varInteger);
   AddField("RelativeAgeUnit", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaRelativeAgeUnitsByAgeScale::AddRecord(vector<Variant>& Record)
{
   int RelativeAgeUnitID = VariantToInt(Record[0], -1);
   UnicodeString RelativeAgeUnit = VarToStr(Record[1]);
   Items[RelativeAgeUnitID] = RelativeAgeUnit;
}
//---------------------------------------------------------------------------

NeotomaTaxonHierarchy::NeotomaTaxonHierarchy(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetTaxonHierarchy";
   AddField("TaxonID", varInteger);
   AddField("TaxonName", varOleStr);
   AddField("Valid", varBoolean);
   AddField("HigherTaxonID", varInteger);
}
//---------------------------------------------------------------------------

void NeotomaTaxonHierarchy::AddRecord(vector<Variant>& Record)
{
   NEOTOMATAXONHIERARCHY taxon;
   taxon.TaxonID = VariantToInt(Record[0], -1);
   taxon.TaxonName = VarToStr(Record[1]);
   taxon.Valid = VariantToBool(Record[2], false);
   taxon.HigherTaxonID = VariantToInt(Record[3], -1);
   Items.push_back(taxon);
}
//---------------------------------------------------------------------------

NeotomaKeywordsTable::NeotomaKeywordsTable(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetKeywordsTable";
   AddField("KeywordID", varInteger);
   AddField("Keyword", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaKeywordsTable::AddRecord(vector<Variant>& Record)
{
   int KeywordID = VariantToInt(Record[0], -1);
   UnicodeString Keyword = VarToStr(Record[1]);
   Items[KeywordID] = Keyword;
}
//---------------------------------------------------------------------------

NeotomaSampleKeywords::NeotomaSampleKeywords(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetSampleKeywords";
   AddField("KeywordID", varInteger);
   AddField("Keyword", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaSampleKeywords::AddRecord(vector<Variant>& Record)
{
   int KeywordID = VariantToInt(Record[0], -1);
   UnicodeString Keyword = VarToStr(Record[1]);
   Items[KeywordID] = Keyword;
}
//---------------------------------------------------------------------------

NeotomaCollUnitBase::NeotomaCollUnitBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient) : SJSONTABLE(ipsjsons, tcpClient)
{
   AddField("CollectionUnitID", varInteger);
   AddField("Handle", varOleStr);
   AddField("SiteID", varInteger);
   AddField("CollTypeID", varInteger);
   AddField("DepEnvtID", varInteger);
   AddField("CollUnitName", varOleStr);
   AddField("CollDate", varDate);
   AddField("CollDevice", varOleStr);
   AddField("GPSLatitude", varDouble);
   AddField("GPSLongitude", varDouble);
   AddField("GPSAltitude", varDouble);
   AddField("GPSError", varDouble);
   AddField("WaterDepth", varDouble);
   AddField("SubstrateID", varInteger);
   AddField("SlopeAspect", varInteger);
   AddField("SlopeAngle", varInteger);
   AddField("Location", varOleStr);
   AddField("Notes", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaCollUnitBase::AddRecord(vector<Variant>& Record)
{
   NEOTOMACOLLUNIT cu;
   cu.CollectionUnitID = VariantToInt(Record[0], -1);
   cu.Handle = VarToStr(Record[1]);
   cu.SiteID = VariantToInt(Record[2], -1);
   cu.CollTypeID = VariantToInt(Record[3], -1);
   cu.DepEnvtID = VariantToInt(Record[4], -1);
   cu.CollUnitName = VarToStr(Record[5]);
   cu.CollDate = Record[6];
   cu.CollDevice = VarToStr(Record[7]);
   cu.GPSLatitude = Record[8];
   cu.GPSLongitude = Record[9];
   cu.GPSAltitude = Record[10];
   cu.GPSError = Record[11];
   cu.WaterDepth = Record[12];
   cu.SubstrateID = VariantToInt(Record[13], -1);
   cu.SlopeAspect = Record[14];
   cu.SlopeAngle = Record[15];
   cu.Location = VarToStr(Record[16]);
   cu.Notes = VarToStr(Record[17]);
   Items.push_back(cu);
}
//---------------------------------------------------------------------------

NeotomaCollUnitByID::NeotomaCollUnitByID(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaCollUnitBase(ipsjsons, tcpClient)
{
   webservice = L"GetCollUnitByID";
}
//---------------------------------------------------------------------------

NeotomaCollUnitsBySiteID::NeotomaCollUnitsBySiteID(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaCollUnitBase(ipsjsons, tcpClient)
{
   webservice = L"GetCollUnitsBySiteID";
}
//---------------------------------------------------------------------------

NeotomaCollUnitSummaryBySiteID::NeotomaCollUnitSummaryBySiteID(TipsJSONS *ipsjsons, TTcpClient *tcpClient) : SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetCollUnitSummaryBySiteID";
   AddField("CollectionUnitID", varInteger);
   AddField("Handle", varOleStr);
   AddField("CollUnitName", varOleStr);
   AddField("CollType", varOleStr);
   AddField("CollDate", varDate);
}
//---------------------------------------------------------------------------

void NeotomaCollUnitSummaryBySiteID::AddRecord(vector<Variant>& Record)
{
   NTMCOLLUNITSUMMARY cu;
   cu.CollectionUnitID = VariantToInt(Record[0], -1);
   cu.Handle = VarToStr(Record[1]);
   cu.CollUnitName = VarToStr(Record[2]);
   cu.CollType = VarToStr(Record[3]);
   cu.CollDate = Record[4];
   Items.push_back(cu);
}
//---------------------------------------------------------------------------

NeotomaDatasetsBase::NeotomaDatasetsBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   AddField("DatasetID", varInteger);
   AddField("CollectionUnitID", varInteger);
   AddField("DatasetTypeID", varInteger);
   AddField("DatasetType", varOleStr);
   AddField("DatasetName", varOleStr);
   AddField("Notes", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaDatasetsBase::AddRecord(vector<Variant>& Record)
{
   NTMDATASET ds;
   ds.DatasetID = VariantToInt(Record[0], -1);
   ds.CollectionUnitID = VariantToInt(Record[1], -1);
   ds.DatasetTypeID = VariantToInt(Record[2], -1);
   ds.DatasetType = VarToStr(Record[3]);
   ds.DatasetName = VarToStr(Record[4]);
   ds.Notes = VarToStr(Record[5]);
   Items.push_back(ds);
}
//---------------------------------------------------------------------------

NeotomaDatasetsByID::NeotomaDatasetsByID(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaDatasetsBase(ipsjsons, tcpClient)
{
   webservice = L"GetDatasetsByID";
}
//---------------------------------------------------------------------------

NeotomaSampleAnalUnits::NeotomaSampleAnalUnits(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetDatasetSamples";
   AddField("SampleID", varInteger);
   AddField("SampleName", varOleStr);
   AddField("SampleDate", varDate);
   AddField("AnalysisDate", varDate);
   AddField("LabNumber", varOleStr);
   AddField("PreparationMethod", varOleStr);
   AddField("SampleNotes", varOleStr);
   AddField("AnalysisUnitID", varInteger);
   AddField("AnalysisUnitName", varOleStr);
   AddField("Depth", varDouble);
   AddField("Thickness", varDouble);
   AddField("FaciesID", varInteger);
   AddField("Facies", varOleStr);
   AddField("Mixed", varBoolean);
   AddField("IGSN", varOleStr);
   AddField("AnalUnitNotes", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaSampleAnalUnits::AddRecord(vector<Variant>& Record)
{
   NTMSAMPLEANALUNIT samp;
   samp.SampleID = VariantToInt(Record[0], -1);
   samp.SampleName = VarToStr(Record[1]);
   samp.SampleDate = Record[2];
   samp.AnalysisDate = Record[3];
   samp.LabNumber = VarToStr(Record[4]);
   samp.PreparationMethod = VarToStr(Record[5]);
   samp.SampleNotes = VarToStr(Record[6]);
   samp.AnalysisUnitID = VariantToInt(Record[7], -1);
   samp.AnalysisUnitName = VarToStr(Record[8]);
   samp.Depth = Record[9];
   samp.Thickness = Record[10];
   samp.FaciesID = VariantToInt(Record[11], -1);
   samp.Facies = VarToStr(Record[12]);
   samp.Mixed = VariantToBool(Record[13], false);
   samp.IGSN = VarToStr(Record[14]);
   samp.AnalUnitNotes = VarToStr(Record[15]);
   Items.push_back(samp);
}
//---------------------------------------------------------------------------

bool NeotomaSampleAnalUnits::compare_depths(NTMSAMPLEANALUNIT Samp1, NTMSAMPLEANALUNIT Samp2)
{
  return (Samp1.Depth < Samp2.Depth);
}
//---------------------------------------------------------------------------

void NeotomaSampleAnalUnits::SortSampleDepths(void)
{
   sort(Items.begin(), Items.end(), compare_depths);
}
//---------------------------------------------------------------------------

NeotomaDatasetSampleAnalysts::NeotomaDatasetSampleAnalysts(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetDatasetSampleAnalysts";
   AddField("SampleID", varInteger);
   AddField("ContactID", varInteger);
}
//---------------------------------------------------------------------------

void NeotomaDatasetSampleAnalysts::AddRecord(vector<Variant>& Record)
{
   int SampleID = VariantToInt(Record[0], -1);
   int ContactID = VariantToInt(Record[1], -1);
   Items.insert(pair<int,int>(SampleID,ContactID));
}
//---------------------------------------------------------------------------

NeotomaDatasetSampleKeywords::NeotomaDatasetSampleKeywords(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetDatasetSampleKeywords";
   AddField("SampleID", varInteger);
   AddField("Keyword", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaDatasetSampleKeywords::AddRecord(vector<Variant>& Record)
{
   int SampleID = VariantToInt(Record[0], -1);
   UnicodeString Keyword = VarToStr(Record[1]);
   Items.insert(pair<int,UnicodeString>(SampleID,Keyword));
}
//---------------------------------------------------------------------------

NeotomaDatasetSampleDepAgents::NeotomaDatasetSampleDepAgents(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetDatasetSampleDepAgents";
   AddField("SampleID", varInteger);
   AddField("DepAgent", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaDatasetSampleDepAgents::AddRecord(vector<Variant>& Record)
{
   int SampleID = VariantToInt(Record[0], -1);
   UnicodeString DepAgent = VarToStr(Record[1]);
   Items.insert(pair<int,UnicodeString>(SampleID,DepAgent));
}
//---------------------------------------------------------------------------

NeotomaDatasetChrons::NeotomaDatasetChrons(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetDatasetChrons";
   AddField("ChronologyID", varInteger);
   AddField("ChronologyName", varOleStr);
   AddField("ShortAgeType", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaDatasetChrons::AddRecord(vector<Variant>& Record)
{
   NTMDATASETCHRON chron;
   chron.ChronologyID = VariantToInt(Record[0], -1);
   chron.ChronologyName = VarToStr(Record[1]);
   chron.ShortAgeType = VarToStr(Record[2]);
   Items.push_back(chron);
}
//---------------------------------------------------------------------------

NeotomaSampleAgesByChronID::NeotomaSampleAgesByChronID(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetSampleAgesByChronID";
   AddField("SampleID", varInteger);
   AddField("Age", varDouble);
   AddField("AgeYounger", varDouble);
   AddField("AgeOlder", varDouble);
}
//---------------------------------------------------------------------------

void NeotomaSampleAgesByChronID::AddRecord(vector<Variant>& Record)
{
   NTMSAMPLEAGE age;
   int SampleID = VariantToInt(Record[0], -1);
   age.Age = Record[1];
   age.AgeYounger = Record[2];
   age.AgeOlder = Record[3];
   Items[SampleID] = age;
}
//---------------------------------------------------------------------------

NeotomaSampleAge::NeotomaSampleAge(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetSampleAge";
   AddField("SampleAgeID", varInteger);
   AddField("Age", varDouble);
   AddField("AgeYounger", varDouble);
   AddField("AgeOlder", varDouble);
}
//---------------------------------------------------------------------------

void NeotomaSampleAge::AddRecord(vector<Variant>& Record)
{
   NTMSAMPLEAGE age;
   int SampleAgeID = VariantToInt(Record[0], -1);
   age.Age = Record[1];
   age.AgeYounger = Record[2];
   age.AgeOlder = Record[3];
   Items[SampleAgeID] = age;
}
//---------------------------------------------------------------------------

NeotomaDatasetVariables::NeotomaDatasetVariables(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetDatasetVariables";
   AddField("VariableID", varInteger);
   AddField("TaxonCode", varOleStr);
   AddField("TaxonName", varOleStr);
   AddField("Author", varOleStr);
   AddField("VariableElement", varOleStr);
   AddField("VariableUnits", varOleStr);
   AddField("VariableContext", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaDatasetVariables::AddRecord(vector<Variant>& Record)
{
   NTMDATASETVARIABLE var;
   var.VariableID = VariantToInt(Record[0], -1);
   var.TaxonCode = VarToStr(Record[1]);
   var.TaxonName = VarToStr(Record[2]);
   var.Author = VarToStr(Record[3]);
   var.VariableElement = VarToStr(Record[4]);
   var.VariableUnits = VarToStr(Record[5]);
   var.VariableContext = VarToStr(Record[6]);
   Items.push_back(var);
}
//---------------------------------------------------------------------------

NeotomaDatasetData::NeotomaDatasetData(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetDatasetData";
   AddField("DataID", varInteger);
   AddField("SampleID", varInteger);
   AddField("VariableID", varInteger);
   AddField("Value", varDouble);
   AddField("TaphonomicTypeID", varInteger);
}
//---------------------------------------------------------------------------

void NeotomaDatasetData::AddRecord(vector<Variant>& Record)
{
   NTMDATASETDATA data;
   data.DataID = VariantToInt(Record[0], -1);
   data.SampleID = VariantToInt(Record[1], -1);
   data.VariableID = VariantToInt(Record[2], -1);
   data.Value = Record[3];
   // East = GetDoubleFromText(geog.SubString(1,idx-1), 0);
   // data.Value = VariantToDouble(Record[3],0.0);
   data.TaphonomicTypeID = VariantToInt(Record[4], -1);
   Items.push_back(data);
}
//---------------------------------------------------------------------------

NeotomaTaphonomicTypesByIDList::NeotomaTaphonomicTypesByIDList(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetTaphonomicTypesByIDList";
   AddField("TaphonomicTypeID", varInteger);
   AddField("TaphonomicType", varOleStr);
   AddField("TaphonomicSystem", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaTaphonomicTypesByIDList::AddRecord(vector<Variant>& Record)
{
   NTMTAPHTYPE taph;
   int TaphonomicTypeID = VariantToInt(Record[0], -1);
   taph.TaphonomicType = VarToStr(Record[1]);
   taph.TaphonomicSystem = VarToStr(Record[2]);
   Items[TaphonomicTypeID] = taph;
}
//---------------------------------------------------------------------------

NeotomaEcolGroupsByVariableIDList::NeotomaEcolGroupsByVariableIDList(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetEcolGroupsByVariableIDList";
   AddField("VariableID", varInteger);
   AddField("TaxaGroupID", varOleStr);
   AddField("EcolSetName", varOleStr);
   AddField("EcolGroupID", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaEcolGroupsByVariableIDList::AddRecord(vector<Variant>& Record)
{
   NTMVARECOLGROUP eg;
   eg.VariableID = VariantToInt(Record[0], -1);
   eg.TaxaGroupID = VarToStr(Record[1]);
   eg.EcolSetName = VarToStr(Record[2]);
   eg.EcolGroupID = VarToStr(Record[3]);
   Items.push_back(eg);
}
//---------------------------------------------------------------------------

NeotomaGeochronByDatasetID::NeotomaGeochronByDatasetID(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetGeochronByDatasetID";
   AddField("GeochronID", varInteger);
   AddField("GeochronTypeID", varInteger);
   AddField("GeochronType", varOleStr);
   AddField("AgeType", varOleStr);
   AddField("Depth", varDouble);
   AddField("Thickness", varDouble);
   AddField("AnalysisUnitID", varInteger);
   AddField("AnalysisUnitName", varOleStr);
   AddField("Age", varDouble);
   AddField("ErrorOlder", varDouble);
   AddField("ErrorYounger", varDouble);
   AddField("Infinite", varBoolean);
   AddField("LabNumber", varOleStr);
   AddField("MaterialDated", varOleStr);
   AddField("Notes", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaGeochronByDatasetID::AddRecord(vector<Variant>& Record)
{
   NTMGEOCHRON date;
   date.GeochronID = VariantToInt(Record[0], -1);
   date.GeochronTypeID = VariantToInt(Record[1], -1);
   date.GeochronType = VarToStr(Record[2]);
   date.AgeType = VarToStr(Record[3]);
   date.Depth = Record[4];
   date.Thickness = Record[5];
   date.AnalysisUnitID = VariantToInt(Record[6], -1);
   date.AnalysisUnitName = VarToStr(Record[7]);
   date.Age = Record[8];
   date.ErrorOlder = Record[9];
   date.ErrorYounger = Record[10];
   date.Infinite = VariantToBool(Record[11], false);
   date.LabNumber = VarToStr(Record[12]);
   date.MaterialDated = VarToStr(Record[13]);
   date.Notes = VarToStr(Record[14]);
   Items.push_back(date);
}
//---------------------------------------------------------------------------

NeotomaGetGeochronByGeochronID::NeotomaGetGeochronByGeochronID(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetGeochronByGeochronID";
   AddField("SampleID", varInteger);
   AddField("GeochronTypeID", varInteger);
   AddField("AgeTypeID", varInteger);
   AddField("Age", varDouble);
   AddField("ErrorOlder", varDouble);
   AddField("ErrorYounger", varDouble);
   AddField("Infinite", varBoolean);
   AddField("LabNumber", varOleStr);
   AddField("MaterialDated", varOleStr);
   AddField("Notes", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaGetGeochronByGeochronID::AddRecord(vector<Variant>& Record)
{
   NTMGEOCHRON date;
   date.SampleID = VariantToInt(Record[0], -1);
   date.GeochronTypeID = VariantToInt(Record[1], -1);
   date.AgeTypeID = VariantToInt(Record[2], -1);
   date.Age = Record[3];
   date.ErrorOlder = Record[4];
   date.ErrorYounger = Record[5];
   date.Infinite = VariantToBool(Record[6], false);
   date.LabNumber = VarToStr(Record[7]);
   date.MaterialDated = VarToStr(Record[8]);
   date.Notes = VarToStr(Record[9]);
   Items.push_back(date);
}
//---------------------------------------------------------------------------

NeotomaRadiocarbonByGeochronID::NeotomaRadiocarbonByGeochronID(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetRadiocarbonByGeochronID";
   AddField("GeochronID", varInteger);
   AddField("RadiocarbonMethod", varOleStr);
   AddField("MassCmg", varDouble);
   AddField("PercentC", varDouble);
   AddField("PercentN", varDouble);
   AddField("CNRatio", varDouble);
   AddField("Delta13C", varDouble);
   AddField("Delta15N", varDouble);
   AddField("PercentCollagen", varDouble);
   AddField("Reservoir", varDouble);
}
//---------------------------------------------------------------------------

void NeotomaRadiocarbonByGeochronID::AddRecord(vector<Variant>& Record)
{
   NTMRADIOCARBON rad;
   int GeochronID = VariantToInt(Record[0], -1);
   rad.RadiocarbonMethod = VarToStr(Record[1]);
   rad.MassCmg = Record[2];
   rad.PercentC = Record[3];
   rad.PercentN = Record[4];
   rad.CNRatio = Record[5];
   rad.Delta13C = Record[6];
   rad.Delta15N = Record[7];
   rad.PercentCollagen = Record[8];
   rad.Reservoir = Record[9];
   Items[GeochronID] = rad;
}
//---------------------------------------------------------------------------

NeotomaPublicationsByGeochronID::NeotomaPublicationsByGeochronID(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetPublicationsByGeochronID";
   AddField("GeochronID", varInteger);
   AddField("PublicationID", varInteger);
}
//---------------------------------------------------------------------------

void NeotomaPublicationsByGeochronID::AddRecord(vector<Variant>& Record)
{
   int GeochronID = VariantToInt(Record[0], -1);
   int PublicationID = VariantToInt(Record[1], -1);
   Items.push_back(pair<int,int>(GeochronID,PublicationID));
}
//---------------------------------------------------------------------------

NeotomaChronologiesByCollUnitID::NeotomaChronologiesByCollUnitID(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetChronologiesByCollUnitID";
   AddField("ChronologyID", varInteger);
   AddField("AgeType", varOleStr);
   AddField("ChronologyName", varOleStr);
   AddField("IsDefault", varBoolean);
   AddField("AgeModel", varOleStr);
   AddField("AgeBoundOlder", varDouble);
   AddField("AgeBoundYounger", varDouble);
   AddField("ContactID", varInteger);
   AddField("DatePrepared", varDate);
   AddField("Notes", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaChronologiesByCollUnitID::AddRecord(vector<Variant>& Record)
{
   NTMCHRONOLOGY chron;
   chron.ChronologyID = VariantToInt(Record[0], -1);
   chron.AgeType = VarToStr(Record[1]);
   chron.ChronologyName = VarToStr(Record[2]);
   chron.IsDefault = VariantToBool(Record[3], false);
   chron.AgeModel = VarToStr(Record[4]);
   chron.AgeBoundOlder = Record[5];
   chron.AgeBoundYounger = Record[6];
   chron.ContactID = VariantToInt(Record[7], -1);
   chron.DatePrepared = Record[8];
   chron.Notes = VarToStr(Record[9]);
   Items.push_back(chron);
}
//---------------------------------------------------------------------------

NeotomaChronoControlsBase::NeotomaChronoControlsBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   AddField("ChronControlID", varInteger);
   AddField("ChronControlTypeID", varInteger);
   AddField("ChronControlType", varOleStr);
   AddField("Depth", varDouble);
   AddField("Thickness", varDouble);
   AddField("AnalysisUnitID", varInteger);
   AddField("AnalysisUnitName", varOleStr);
   AddField("AgeTypeID", varInteger);
   AddField("Age", varDouble);
   AddField("AgeLimitYounger", varDouble);
   AddField("AgeLimitOlder", varDouble);
   AddField("Notes", varOleStr);
   AddField("CalibrationCurve", varOleStr);
   AddField("CalibrationProgram", varOleStr);
   AddField("Version", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaChronoControlsBase::AddRecord(vector<Variant>& Record)
{
   NTMCHRONCONTROL cc;
   cc.ChronControlID = VariantToInt(Record[0], -1);
   cc.ChronControlTypeID = VariantToInt(Record[1], -1);
   cc.ChronControlType = VarToStr(Record[2]);
   cc.Depth = Record[3];
   cc.Thickness = Record[4];
   cc.AnalysisUnitID = VariantToInt(Record[5], -1);
   cc.AnalysisUnitName = VarToStr(Record[6]);
   cc.AgeTypeID = VariantToInt(Record[7], -1);
   cc.Age = Record[8];
   cc.AgeLimitYounger = Record[9];
   cc.AgeLimitOlder = Record[10];
   cc.Notes = VarToStr(Record[11]);
   cc.CalibrationCurve = VarToStr(Record[12]);
   cc.CalibrationProgram = VarToStr(Record[13]);
   cc.Version = VarToStr(Record[14]);
   Items.push_back(cc);
}
//---------------------------------------------------------------------------

NeotomaChronoControlsByChronologyID::NeotomaChronoControlsByChronologyID(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaChronoControlsBase(ipsjsons, tcpClient)
{
   webservice = L"GetChronoControlsByChronologyID";
}
//---------------------------------------------------------------------------

NeotomaChronoControlsByChronControlID::NeotomaChronoControlsByChronControlID(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaChronoControlsBase(ipsjsons, tcpClient)
{
   webservice = L"GetChronControlsByChronControlID";
}
//---------------------------------------------------------------------------

NeotomaGeoChronControlsByChronologyID::NeotomaGeoChronControlsByChronologyID(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetGeoChronControlsByChronologyID";
   AddField("ChronControlID", varInteger);
   AddField("GeochronID", varInteger);
}
//---------------------------------------------------------------------------

void NeotomaGeoChronControlsByChronologyID::AddRecord(vector<Variant>& Record)
{
   int ChronControlID = VariantToInt(Record[0], -1);
   int GeochronID = VariantToInt(Record[1], -1);
   Items.insert(pair<int,int>(ChronControlID,GeochronID));
}
//---------------------------------------------------------------------------

NeotomaRelativeAgesByChronologyID::NeotomaRelativeAgesByChronologyID(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetRelativeAgesByChronologyID";
   AddField("ChronControlID", varInteger);
   AddField("RelativeAge", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaRelativeAgesByChronologyID::AddRecord(vector<Variant>& Record)
{
   int ChronControlID = VariantToInt(Record[0], -1);
   UnicodeString RelativeAge = VarToStr(Record[1]);
   Items[ChronControlID] = RelativeAge;
}
//---------------------------------------------------------------------------

NeotomaDatasetContactsDatasetTypesBase::NeotomaDatasetContactsDatasetTypesBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   AddField("ContactID", varInteger);
   AddField("ContactName", varOleStr);
   AddField("DatasetID", varInteger);
   AddField("DatasetTypeID", varInteger);
}
//---------------------------------------------------------------------------

void NeotomaDatasetContactsDatasetTypesBase::AddRecord(vector<Variant>& Record)
{
   NTMPIAUTHORDATASET cdid;
   cdid.ContactID = VariantToInt(Record[0], -1);
   cdid.ContactName = VarToStr(Record[1]);
   cdid.DatasetID = VariantToInt(Record[2], -1);
   cdid.DatasetTypeID = VariantToInt(Record[3], -1);
   Items.push_back(cdid);
}
//---------------------------------------------------------------------------

NeotomaDatasetPIsDatasetTypes::NeotomaDatasetPIsDatasetTypes(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaDatasetContactsDatasetTypesBase(ipsjsons, tcpClient)
{
   webservice = L"GetDatasetPIsDatasetTypes";
}
//---------------------------------------------------------------------------

NeotomaDatasetAuthorsDatasetTypes::NeotomaDatasetAuthorsDatasetTypes(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaDatasetContactsDatasetTypesBase(ipsjsons, tcpClient)
{
   webservice = L"GetDatasetAuthorsDatasetTypes";
}
//---------------------------------------------------------------------------

NeotomaAliasContactNames::NeotomaAliasContactNames(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetAliasContactNames";
   AddField("AliasContactID", varInteger);
   AddField("AliasContactName", varOleStr);
   AddField("CurrentContactID", varInteger);
   AddField("CurrentContactName", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaAliasContactNames::AddRecord(vector<Variant>& Record)
{
   NTMALIASNAME alias;
   alias.AliasContactID = VariantToInt(Record[0], -1);
   alias.AliasContactName = VarToStr(Record[1]);
   alias.CurrentContactID = VariantToInt(Record[2], -1);
   alias.CurrentContactName = VarToStr(Record[3]);
   Items.push_back(alias);
}
//---------------------------------------------------------------------------

NeotomaEventChronControlTypeID::NeotomaEventChronControlTypeID(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetEventChronControlTypeID";
   AddField("EventID", varInteger);
   AddField("ChronControlTypeID", varInteger);
}
//---------------------------------------------------------------------------

void NeotomaEventChronControlTypeID::AddRecord(vector<Variant>& Record)
{
   int EventID = VariantToInt(Record[0], -1);
   int ChronControlTypeID = VariantToInt(Record[1], -1);
   Items.push_back(pair<int,int>(EventID,ChronControlTypeID));
}
//---------------------------------------------------------------------------

NeotomaEventsByChronologyID::NeotomaEventsByChronologyID(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetEventsByChronologyID";
   AddField("ChronControlID", varInteger);
   AddField("EventName", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaEventsByChronologyID::AddRecord(vector<Variant>& Record)
{
   int ChronControlID = VariantToInt(Record[0], -1);
   UnicodeString EventName = VarToStr(Record[1]);
   Items[ChronControlID] = EventName;
}
//---------------------------------------------------------------------------

NeotomaAllDatasetContacts::NeotomaAllDatasetContacts(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   AddField("ContactName", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaAllDatasetContacts::AddRecord(vector<Variant>& Record)
{
   UnicodeString ContactName = VarToStr(Record[0]);
   Items.push_back(ContactName);
}
//---------------------------------------------------------------------------

NeotomaAllDatasetPIs::NeotomaAllDatasetPIs(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaAllDatasetContacts(ipsjsons, tcpClient)
{
   webservice = L"GetAllDatasetPIs";
}
//---------------------------------------------------------------------------

NeotomaAllDatasetAuthors::NeotomaAllDatasetAuthors(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaAllDatasetContacts(ipsjsons, tcpClient)
{
   webservice = L"GetAllDatasetAuthors";
}
//---------------------------------------------------------------------------

NeotomaRelativeAgeChronControlType::NeotomaRelativeAgeChronControlType(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetRelativeAgeChronControlType";
   AddField("ChronControlTypeID", varInteger);
   AddField("ChronControlType", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaRelativeAgeChronControlType::AddRecord(vector<Variant>& Record)
{
   int ChronControlTypeID = VariantToInt(Record[0], -1);
   UnicodeString ChronControlType = VarToStr(Record[1]);
   Items.push_back(pair<int,UnicodeString>(ChronControlTypeID,ChronControlType));
}
//---------------------------------------------------------------------------

NeotomaDatasetSynonyms::NeotomaDatasetSynonyms(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetDatasetSynonyms";
   AddField("SynonymyID", varInteger);
   AddField("ValidName", varOleStr);
   AddField("RefName", varOleStr);
   AddField("FromContributor", varBoolean);
   AddField("PublicationID", varInteger);
   AddField("Notes", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaDatasetSynonyms::AddRecord(vector<Variant>& Record)
{
   DATASETSYNONYM dsym;
   dsym.SynonymyID = VariantToInt(Record[0], -1);
   dsym.ValidName = VarToStr(Record[1]);
   dsym.RefName = VarToStr(Record[2]);
   dsym.FromContributor = VariantToBool(Record[3], false);
   dsym.PublicationID = Record[4];
   dsym.Notes = VarToStr(Record[5]);
   Items.push_back(dsym);
}
//---------------------------------------------------------------------------

NeotomaDatasetVariableSynonyms::NeotomaDatasetVariableSynonyms(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetDatasetVariableSynonyms";
   AddField("SynonymyID", varInteger);
   AddField("RefTaxonName", varOleStr);
   AddField("FromContributor", varBoolean);
   AddField("PublicationID", varInteger);
   AddField("Notes", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaDatasetVariableSynonyms::AddRecord(vector<Variant>& Record)
{
   DATASETVARSYNONYM dvs;
   dvs.SynonymyID = VariantToInt(Record[0], -1);
   dvs.RefTaxonName = VarToStr(Record[1]);
   dvs.FromContributor = VariantToBool(Record[2], false);
   dvs.PublicationID = Record[3];
   dvs.Notes = VarToStr(Record[4]);
   Items.push_back(dvs);
}
//---------------------------------------------------------------------------

NeotomaVariableTaxonID::NeotomaVariableTaxonID(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetVariableTaxonID";
   AddField("TaxonID", varInteger);
}
//---------------------------------------------------------------------------

void NeotomaVariableTaxonID::AddRecord(vector<Variant>& Record)
{
   int TaxonID = VariantToInt(Record[0], -1);
   Items.push_back(TaxonID);
}
//---------------------------------------------------------------------------

NeotomaDatasetTaxonNotesBase::NeotomaDatasetTaxonNotesBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   AddField("TaxonID", varInteger);
   AddField("TaxonName", varOleStr);
   AddField("Notes", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaDatasetTaxonNotesBase::AddRecord(vector<Variant>& Record)
{
   DATASETTAXONNOTES dtn;
   dtn.TaxonID = VariantToInt(Record[0], -1);
   dtn.TaxonName = VarToStr(Record[1]);
   dtn.Notes = VarToStr(Record[2]);
   Items.push_back(dtn);
}
//---------------------------------------------------------------------------

NeotomaDatasetTaxonNotes::NeotomaDatasetTaxonNotes(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaDatasetTaxonNotesBase(ipsjsons, tcpClient)
{
   webservice = L"GetDatasetTaxonNotes";
}
//---------------------------------------------------------------------------

NeotomaDatasetTaxonNotesByTaxonID::NeotomaDatasetTaxonNotesByTaxonID(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaDatasetTaxonNotesBase(ipsjsons, tcpClient)
{
   webservice = L"GetDatasetTaxonNotesByTaxonID";
}
//---------------------------------------------------------------------------

NeotomaDatasetDatabase::NeotomaDatasetDatabase(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetDatasetDatabase";
   AddField("DatabaseID", varInteger);
   AddField("DatabaseName", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaDatasetDatabase::AddRecord(vector<Variant>& Record)
{
   int DatabaseID = VariantToInt(Record[0], -1);
   UnicodeString DatabaseName = VarToStr(Record[1]);
   Items[DatabaseID] = DatabaseName;
}
//---------------------------------------------------------------------------

NeotomaVariableTextByID::NeotomaVariableTextByID(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetVariableTextByID";
   AddField("TaxonName", varOleStr);
   AddField("VariableElement", varOleStr);
   AddField("VariableUnits", varOleStr);
   AddField("VariableContext", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaVariableTextByID::AddRecord(vector<Variant>& Record)
{
   VARIABLETEXT vt;
   vt.TaxonName = VarToStr(Record[0]);
   vt.VariableElement = VarToStr(Record[1]);
   vt.VariableUnits = VarToStr(Record[2]);
   vt.VariableContext = VarToStr(Record[3]);
   Items.push_back(vt);
}
//---------------------------------------------------------------------------

NeotomaLithologyByCollUnitID::NeotomaLithologyByCollUnitID(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetLithologyByCollUnitID";
   AddField("LithologyID", varInteger);
   AddField("DepthTop", varDouble);
   AddField("DepthBottom", varDouble);
   AddField("LowerBoundary", varOleStr);
   AddField("Description", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaLithologyByCollUnitID::AddRecord(vector<Variant>& Record)
{
   NEOTOMALITH lt;
   lt.LithologyID = VariantToInt(Record[0], -1);
   lt.DepthTop = VariantToDouble(Record[1], 0.0);
   lt.DepthBottom = VariantToDouble(Record[2], 0.0);
   lt.LowerBoundary = VarToStr(Record[3]);
   lt.Description = VarToStr(Record[4]);
   Items.push_back(lt);
}
//---------------------------------------------------------------------------

NeotomaGetIsoMaterialAnalyzedAndSubstrate::NeotomaGetIsoMaterialAnalyzedAndSubstrate(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetIsoMaterialAnalyzedAndSubstrate";
   AddField("IsoMaterialAnalyzedType", varOleStr);
   AddField("IsoSubstrateType", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaGetIsoMaterialAnalyzedAndSubstrate::AddRecord(vector<Variant>& Record)
{
   UnicodeString IsoMaterialAnalyzedType = VarToStr(Record[0]);
   UnicodeString IsoSubstrateType = VarToStr(Record[1]);
   Items.insert(pair<UnicodeString,UnicodeString>(IsoMaterialAnalyzedType,IsoSubstrateType));
}
//---------------------------------------------------------------------------

NeotomaGetIsoMaterialAnalyzedTypes::NeotomaGetIsoMaterialAnalyzedTypes(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetIsoMaterialAnalyzedTypes";
   AddField("IsoMatAnalTypeID", varInteger);
   AddField("IsoMaterialAnalyzedType", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaGetIsoMaterialAnalyzedTypes::AddRecord(vector<Variant>& Record)
{
   int IsoMatAnalTypeID = VariantToInt(Record[0], -1);
   UnicodeString IsoMaterialAnalyzedType = VarToStr(Record[1]);
   Items[IsoMatAnalTypeID] = IsoMaterialAnalyzedType;
}
//---------------------------------------------------------------------------

NeotomaGetIsoSubstrates::NeotomaGetIsoSubstrates(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetIsoSubstrates";
   AddField("IsoSubstrateTypeID", varInteger);
   AddField("IsoMatAnalTypeID", varInteger);
   AddField("IsoSubstrateType", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaGetIsoSubstrates::AddRecord(vector<Variant>& Record)
{
   int IsoSubstrateTypeID = VariantToInt(Record[0], -1);
   int IsoMatAnalTypeID = VariantToInt(Record[1], -1);
   UnicodeString IsoSubstrateType = VarToStr(Record[2]);
   Items.insert(pair<int,pair<int,UnicodeString> >(IsoMatAnalTypeID, pair<int,UnicodeString>(IsoSubstrateTypeID,IsoSubstrateType)));
}
//---------------------------------------------------------------------------

NeotomaGetIsoPretreatmentTypes::NeotomaGetIsoPretreatmentTypes(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetIsoPretreatmentTypes";
   AddField("IsoPretreatmentTypeID", varInteger);
   AddField("IsoPretreatmentType", varOleStr);
   AddField("IsoPretreatmentQualifier", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaGetIsoPretreatmentTypes::AddRecord(vector<Variant>& Record)
{
   NEOTOMAPRETREATMENT pt;
   pt.IsoPretreatmentTypeID = VariantToInt(Record[0], -1);
   pt.IsoPretreatmentType = VarToStr(Record[1]);
   pt.IsoPretreatmentQualifier = VarToStr(Record[2]);
   Items.push_back(pt);
}
//---------------------------------------------------------------------------

NeotomaSampleOriginTypes::NeotomaSampleOriginTypes(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetIsoSampleOriginTypes";
   AddField("IsoSampleOriginTypeID", varInteger);
   AddField("IsoSampleOriginType", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaSampleOriginTypes::AddRecord(vector<Variant>& Record)
{
   int IsoSampleOriginTypeID = VariantToInt(Record[0], -1);
   UnicodeString IsoSampleOriginType = VarToStr(Record[1]);
   Items[IsoSampleOriginTypeID] = IsoSampleOriginType;
}
//---------------------------------------------------------------------------

NeotomaGetIsoBioMarkers::NeotomaGetIsoBioMarkers(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetIsoBioMarkers";
   AddField("IsoBioMarkerType", varOleStr);
   AddField("IsoBioMarkerBandType", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaGetIsoBioMarkers::AddRecord(vector<Variant>& Record)
{
   UnicodeString IsoBioMarkerType = VarToStr(Record[0]);
   UnicodeString IsoBioMarkerBandType = VarToStr(Record[1]);
   Items.insert(pair<UnicodeString,UnicodeString>(IsoBioMarkerType,IsoBioMarkerBandType));
}
//---------------------------------------------------------------------------

NeotomaGetIDMapBase::NeotomaGetIDMapBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
}
//---------------------------------------------------------------------------

void NeotomaGetIDMapBase::AddRecord(vector<Variant>& Record)
{
   int ID = VariantToInt(Record[0], -1);
   UnicodeString Param = VarToStr(Record[1]);
   Items[ID] = Param;
}
//---------------------------------------------------------------------------

NeotomaIsoInstrumentationTypes::NeotomaIsoInstrumentationTypes(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaGetIDMapBase(ipsjsons, tcpClient)
{
   webservice = L"GetIsoInstrumentationTypes";
   AddField("IsoInstrumentationTypeID", varInteger);
   AddField("IsoInstrumentationType", varOleStr);
}
//---------------------------------------------------------------------------

NeotomaIsoSampleIntroSystemTypes::NeotomaIsoSampleIntroSystemTypes(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaGetIDMapBase(ipsjsons, tcpClient)
{
   webservice = L"GetIsoSampleIntroSystemTypes";
   AddField("IsoSampleIntroSystemTypeID", varInteger);
   AddField("IsoSampleIntroSystemType", varOleStr);
}
//---------------------------------------------------------------------------

NeotomaIsoStandardTypes::NeotomaIsoStandardTypes(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetIsoStandardTypes";
   AddField("IsoStandardTypeID", varInteger);
   AddField("IsoStandardType", varOleStr);
   AddField("IsoStandardMaterial", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaIsoStandardTypes::AddRecord(vector<Variant>& Record)
{
   NEOTOMAISOSTANDARD ist;
   ist.IsoStandardTypeID = VariantToInt(Record[0], -1);
   ist.IsoStandardType = VarToStr(Record[1]);
   ist.IsoStandardMaterial = VarToStr(Record[2]);
   Items.push_back(ist);
}
//---------------------------------------------------------------------------

NeotomaGetIsoVariableScaleTypes::NeotomaGetIsoVariableScaleTypes(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetIsoVariableScaleTypes";
   AddField("IsoVariable", varOleStr);
   AddField("IsoScaleAcronym", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaGetIsoVariableScaleTypes::AddRecord(vector<Variant>& Record)
{
   UnicodeString IsoVariable = VarToStr(Record[0]);
   UnicodeString IsoScaleAcronym = VarToStr(Record[1]);
   Items.insert(pair<UnicodeString,UnicodeString>(IsoVariable,IsoScaleAcronym));
}
//---------------------------------------------------------------------------

NeotomaGetIsoVariableScaleIDs::NeotomaGetIsoVariableScaleIDs(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetIsoVariableScaleIDs";
   AddField("IsoVariable", varOleStr);
   AddField("IsoScaleTypeID", varInteger);
   AddField("IsoScaleAcronym", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaGetIsoVariableScaleIDs::AddRecord(vector<Variant>& Record)
{
   UnicodeString IsoVariable = VarToStr(Record[0]);
   int IsoScaleTypeID = VariantToInt(Record[1], -1);
   UnicodeString IsoScaleAcronym = VarToStr(Record[2]);
   Items.insert(pair<UnicodeString,pair<int,UnicodeString> >(IsoVariable,pair<int,UnicodeString>(IsoScaleTypeID,IsoScaleAcronym)));
}
//---------------------------------------------------------------------------

NeotomaSpecimenIsotopeDataset::NeotomaSpecimenIsotopeDataset(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetSpecimenIsotopeDataset";
   AddField("SpecimenID", varInteger);
   AddField("AnalysisUnit", varOleStr);
   AddField("Depth", varOleStr);
   AddField("Thickness", varOleStr);
   AddField("Taxon", varOleStr);
   AddField("Element", varOleStr);
   AddField("Variable", varOleStr);
   AddField("Units", varOleStr);
   AddField("Value", varOleStr);
   AddField("SD", varOleStr);
   AddField("MaterialAnalyzed", varOleStr);
   AddField("Substrate", varOleStr);
   AddField("Pretreatments", varOleStr);
   AddField("Analyst", varOleStr);
   AddField("Lab", varOleStr);
   AddField("LabNumber", varOleStr);
   AddField("Mass_mg", varOleStr);
   AddField("WeightPercent", varOleStr);
   AddField("AtomicPercent", varOleStr);
   AddField("Reps", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaSpecimenIsotopeDataset::AddRecord(vector<Variant>& Record)
{
   NTMISODATASET id;
   UnicodeString str;
   double dval;
   int ival;

   id.SpecimenID = VariantToInt(Record[0], -1);
   id.AnalysisUnit = VarToStr(Record[1]);
   if (!Record[2].IsEmpty()) {
	 str = Record[2];
	 if (TryStrToFloat(str,dval))
	   id.Depth = dval;
	 }
   if (!Record[3].IsEmpty()) {
	 str = Record[3];
	 if (TryStrToFloat(str,dval))
	   id.Thickness = dval;
	 }
   id.Taxon = VarToStr(Record[4]);
   id.Element = VarToStr(Record[5]);
   id.Variable = VarToStr(Record[6]);
   id.Units = VarToStr(Record[7]);
   if (!Record[8].IsEmpty()) {
	 str = Record[8];
	 if (TryStrToFloat(str,dval))
	   id.Value = dval;
	 }
   if (!Record[9].IsEmpty()) {
	 str = Record[9];
	 if (TryStrToFloat(str,dval))
	   id.SD = dval;
	 }
   id.MaterialAnalyzed = VarToStr(Record[10]);
   id.Substrate = VarToStr(Record[11]);
   id.Pretreatments = VarToStr(Record[12]);
   id.Analyst = VarToStr(Record[13]);
   id.Lab = VarToStr(Record[14]);
   id.LabNumber = VarToStr(Record[15]);
   if (!Record[16].IsEmpty()) {
	 str = Record[16];
	 if (TryStrToFloat(str,dval))
	   id.Mass_mg = dval;
	 }
   if (!Record[17].IsEmpty()) {
	 str = Record[17];
	 if (TryStrToFloat(str,dval))
	   id.WeightPercent = dval;
	 }
   if (!Record[18].IsEmpty()) {
	 str = Record[18];
	 if (TryStrToFloat(str,dval))
	   id.AtomicPercent = dval;
	 }
   if (!Record[19].IsEmpty()) {
	 str = Record[19];
	 if (TryStrToInt(str,ival))
	   id.Reps = ival;
	 }
   Items.push_back(id);
}
//---------------------------------------------------------------------------

NeotomaSpecimenSexBase::NeotomaSpecimenSexBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   AddField("SexID", varInteger);
   AddField("Sex", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaSpecimenSexBase::AddRecord(vector<Variant>& Record)
{
   int SexID = VariantToInt(Record[0], -1);
   UnicodeString Sex = VarToStr(Record[1]);
   Items[SexID] = Sex;
}
//---------------------------------------------------------------------------

NeotomaSpecimenSexTypes::NeotomaSpecimenSexTypes(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaSpecimenSexBase(ipsjsons, tcpClient)
{
   webservice = L"GetSpecimenSexTypes";
}
//---------------------------------------------------------------------------

NeotomaSpecimenSexByName::NeotomaSpecimenSexByName(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaSpecimenSexBase(ipsjsons, tcpClient)
{
   webservice = L"GetSpecimenSexByName";
}
//---------------------------------------------------------------------------


NeotomaSpecimenDomStatBase::NeotomaSpecimenDomStatBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   AddField("DomesticStatusID", varInteger);
   AddField("DomesticStatus", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaSpecimenDomStatBase::AddRecord(vector<Variant>& Record)
{
   int DomesticStatusID = VariantToInt(Record[0], -1);
   UnicodeString DomesticStatus = VarToStr(Record[1]);
   Items[DomesticStatusID] = DomesticStatus;
}
//---------------------------------------------------------------------------

NeotomaSpecimenDomStatTypes::NeotomaSpecimenDomStatTypes(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaSpecimenDomStatBase(ipsjsons, tcpClient)
{
   webservice = L"GetSpecimenDomesticStatusTypes";
}
//---------------------------------------------------------------------------

NeotomaSpecimenDomStatByName::NeotomaSpecimenDomStatByName(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaSpecimenDomStatBase(ipsjsons, tcpClient)
{
   webservice = L"GetSpecimenDomesticStatusByName";
}
//---------------------------------------------------------------------------

NeotomaGetDatasetSampleIDs::NeotomaGetDatasetSampleIDs(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetDatasetSampleIDs";
   AddField("SampleID", varInteger);
}
//---------------------------------------------------------------------------

void NeotomaGetDatasetSampleIDs::AddRecord(vector<Variant>& Record)
{
   int SampleID = VariantToInt(Record[0], -1);
   Items.push_back(SampleID);
}
//---------------------------------------------------------------------------

NeotomaGetGeochronAnalysisUnitBase::NeotomaGetGeochronAnalysisUnitBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   // webservice = L"GetGeochronAnalysisUnit";
   AddField("SampleID", varInteger);
   AddField("CollectionUnitID", varInteger);
   AddField("AnalysisUnitID", varInteger);
   AddField("AnalysisUnitName", varOleStr);
   AddField("Depth", varDouble);
   AddField("Thickness", varDouble);

}
//---------------------------------------------------------------------------

void NeotomaGetGeochronAnalysisUnitBase::AddRecord(vector<Variant>& Record)
{
   GEOCHRONANALUNIT gau;
   gau.SampleID = VariantToInt(Record[0], -1);
   gau.CollectionUnitID = VariantToInt(Record[1], -1);
   gau.AnalysisUnitID = VariantToInt(Record[2], -1);
   gau.AnalysisUnitName = VarToStr(Record[3]);
   gau.Depth = Record[4];
   gau.Thickness = Record[5];
   Items.push_back(gau);
}
//---------------------------------------------------------------------------

NeotomaGetGeochronAnalysisUnit::NeotomaGetGeochronAnalysisUnit(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaGetGeochronAnalysisUnitBase(ipsjsons, tcpClient)
{
   webservice = L"GetGeochronAnalysisUnit";
}
//---------------------------------------------------------------------------

NeotomaGetGeochronAnalysisUnitByDatasetID::NeotomaGetGeochronAnalysisUnitByDatasetID(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaGetGeochronAnalysisUnitBase(ipsjsons, tcpClient)
{
   webservice = L"GetGeochronAnalysisUnitsByDatasetID";
}
//---------------------------------------------------------------------------

NeotomaGetAnalysisUnit::NeotomaGetAnalysisUnit(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetAnalysisUnit";
   AddField("AnalysisUnitID", varInteger);
}
//---------------------------------------------------------------------------

void NeotomaGetAnalysisUnit::AddRecord(vector<Variant>& Record)
{
   int AnalysisUnitID = VariantToInt(Record[0], -1);
   Items.push_back(AnalysisUnitID);
}
//---------------------------------------------------------------------------

NeotomaGetAnalUnitBase::NeotomaGetAnalUnitBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   AddField("AnalysisUnitID", varInteger);
   AddField("Depth", varDouble);
   AddField("Thickness", varDouble);
   AddField("AnalysisUnitName", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaGetAnalUnitBase::AddRecord(vector<Variant>& Record)
{
   NTMANALYSISUNIT au;
   au.AnalysisUnitID = VariantToInt(Record[0], -1);
   au.Depth = Record[1];
   au.Thickness = Record[2];
   au.AnalysisUnitName = VarToStr(Record[3]);
   Items.push_back(au);
}
//---------------------------------------------------------------------------

NeotomaGetAnalUnitsByCollUnitID::NeotomaGetAnalUnitsByCollUnitID(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaGetAnalUnitBase(ipsjsons, tcpClient)
{
   webservice = L"GetAnalysisUnitsByCollUnitID";
}
//---------------------------------------------------------------------------

/*
NeotomaGetAnalUnitByID::NeotomaGetAnalUnitByID(TipwJSON *ipwjson, TTcpClient *tcpClient)
	: NeotomaGetAnalUnitBase(ipsjsons, tcpClient)
{
   webservice = L"GetAnalysisUnitByID";
}
//---------------------------------------------------------------------------
*/

NeotomaGetAnalUnitByID::NeotomaGetAnalUnitByID(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetAnalysisUnitByID";
   AddField("CollectionUnitID", varInteger);
   AddField("Depth", varDouble);
   AddField("Thickness", varDouble);
   AddField("AnalysisUnitName", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaGetAnalUnitByID::AddRecord(vector<Variant>& Record)
{
   NTMANALYSISUNIT au;
   au.CollectionUnitID = VariantToInt(Record[0], -1);
   au.Depth = Record[1];
   au.Thickness = Record[2];
   au.AnalysisUnitName = VarToStr(Record[3]);
   Items.push_back(au);
}
//---------------------------------------------------------------------------

NeotomaGetCountBase::NeotomaGetCountBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   AddField("Count", varInteger);
}
//---------------------------------------------------------------------------

void NeotomaGetCountBase::AddRecord(vector<Variant>& Record)
{
   int Count = VariantToInt(Record[0], -1);
   Items.push_back(Count);
}
//---------------------------------------------------------------------------

NeotomaGetAnalysisUnitSampleCount::NeotomaGetAnalysisUnitSampleCount(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaGetCountBase(ipsjsons, tcpClient)
{
   webservice = L"GetAnalysisUnitSampleCount";
}
//---------------------------------------------------------------------------

NeotomaGetGeochronControlCount::NeotomaGetGeochronControlCount(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaGetCountBase(ipsjsons, tcpClient)
{
   webservice = L"GetGeochronControlCount";
}
//---------------------------------------------------------------------------

NeotomaGetGeochronIDCount::NeotomaGetGeochronIDCount(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaGetCountBase(ipsjsons, tcpClient)
{
   webservice = L"GetGeochronIDCount";
}
//---------------------------------------------------------------------------

NeotomaGetIDBase::NeotomaGetIDBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
}
//---------------------------------------------------------------------------

void NeotomaGetIDBase::AddRecord(vector<Variant>& Record)
{
   int ID = VariantToInt(Record[0], -1);
   Items.push_back(ID);
}
//---------------------------------------------------------------------------

NeotomaGetAgeTypeID::NeotomaGetAgeTypeID(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaGetIDBase(ipsjsons, tcpClient)
{
   webservice = L"GetAgeTypeID";
   AddField(L"AgeTypeID", varInteger);
}
//---------------------------------------------------------------------------

NeotomaGetGeochronTypeID::NeotomaGetGeochronTypeID(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaGetIDBase(ipsjsons, tcpClient)
{
   webservice = L"GetGeochronTypeID";
   AddField(L"GeochronTypeID", varInteger);
}
//---------------------------------------------------------------------------

NeotomaGetRadiocarbonMethodID::NeotomaGetRadiocarbonMethodID(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaGetIDBase(ipsjsons, tcpClient)
{
   webservice = L"GetRadiocarbonMethodID";
   AddField(L"RadiocarbonMethodID", varInteger);
}
//---------------------------------------------------------------------------

NeotomaGetDatasetPublicationIDs::NeotomaGetDatasetPublicationIDs(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaGetIDBase(ipsjsons, tcpClient)
{
   webservice = L"GetDatasetPublicationIDs";
   AddField(L"PublicationID", varInteger);
}
//---------------------------------------------------------------------------

NeotomaVariableByComponentNames::NeotomaVariableByComponentNames(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaGetIDBase(ipsjsons, tcpClient)
{
   webservice = L"GetVariableByComponentNames";
   AddField(L"VariableID", varInteger);
}
//---------------------------------------------------------------------------

NeotomaTaphonomicTypeID::NeotomaTaphonomicTypeID(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaGetIDBase(ipsjsons, tcpClient)
{
   webservice = L"GetTaphonomicTypeID";
   AddField(L"TaphonomicTypeID", varInteger);
}
//---------------------------------------------------------------------------


NeotomaDatasetSpecimens::NeotomaDatasetSpecimens(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetDatasetSpecimens";
   AddField("DataID", varInteger);
   AddField("SpecimenID", varInteger);
   AddField("ElementType", varOleStr);
   AddField("Symmetry", varOleStr);
   AddField("Portion", varOleStr);
   AddField("Maturity", varOleStr);
   AddField("Sex", varOleStr);
   AddField("DomesticStatus", varOleStr);
   AddField("Preservative", varOleStr);
   AddField("NISP", varDouble);
   AddField("Repository", varOleStr);
   AddField("SpecimenNr", varOleStr);
   AddField("FieldNr", varOleStr);
   AddField("ArctosNr", varOleStr);
   AddField("Notes", varOleStr);
   AddField("TaxonName", varOleStr);
   AddField("TaxaGroup", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaDatasetSpecimens::AddRecord(vector<Variant>& Record)
{
   DATASETSPECIMEN spec;
   int DataID = VariantToInt(Record[0], -1);
   spec.SpecimenID = VariantToInt(Record[1], -1);
   spec.ElementType = VarToStr(Record[2]);
   spec.Symmetry = VarToStr(Record[3]);
   spec.Portion = VarToStr(Record[4]);
   spec.Maturity = VarToStr(Record[5]);
   spec.Sex = VarToStr(Record[6]);
   spec.DomesticStatus = VarToStr(Record[7]);
   spec.Preservative = VarToStr(Record[8]);
   spec.NISP = VariantToDouble(Record[9], 0.0);
   spec.Repository = VarToStr(Record[10]);
   spec.SpecimenNr = VarToStr(Record[11]);
   spec.FieldNr = VarToStr(Record[12]);
   spec.ArctosNr = VarToStr(Record[13]);
   spec.Notes = VarToStr(Record[14]);
   spec.TaxonName = VarToStr(Record[15]);
   spec.TaxaGroup = LowerCase(VarToStr(Record[16]));
   Items.insert(pair<int,DATASETSPECIMEN>(DataID,spec));
}
//---------------------------------------------------------------------------

NeotomaDatasetSpecimenGenBankNrs::NeotomaDatasetSpecimenGenBankNrs(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetDatasetSpecimenGenBankNrs";
   AddField("SpecimenID", varInteger);
   AddField("GenBankNr", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaDatasetSpecimenGenBankNrs::AddRecord(vector<Variant>& Record)
{
   int SpecimenID = VariantToInt(Record[0], -1);
   UnicodeString GenBankNr = VarToStr(Record[1]);
   Items.insert(pair<int,UnicodeString>(SpecimenID,GenBankNr));
}
//---------------------------------------------------------------------------

NeotomaDatasetSpecimenTaphonomy::NeotomaDatasetSpecimenTaphonomy(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetDatasetSpecimenTaphonomy";
   AddField("SpecimenID", varInteger);
   AddField("TaphonomicSystem", varOleStr);
   AddField("TaphonomicType", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaDatasetSpecimenTaphonomy::AddRecord(vector<Variant>& Record)
{
   int SpecimenID = VariantToInt(Record[0], -1);
   UnicodeString TaphonomicSystem = VarToStr(Record[1]);
   UnicodeString TaphonomicType = VarToStr(Record[2]);
   Items.insert(pair<int,pair<UnicodeString,UnicodeString> >(SpecimenID,pair<UnicodeString,UnicodeString>(TaphonomicSystem,TaphonomicType)));
}
//---------------------------------------------------------------------------

NeotomaGetDatasetIDByCollUnitAndType::NeotomaGetDatasetIDByCollUnitAndType(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetDatasetIDByCollUnitAndType";
   AddField("DatasetID", varInteger);
}
//---------------------------------------------------------------------------

void NeotomaGetDatasetIDByCollUnitAndType::AddRecord(vector<Variant>& Record)
{
   int DatasetID = VariantToInt(Record[0], -1);
   Items.push_back(DatasetID);
}
//---------------------------------------------------------------------------

NeotomaGetChronoControlsByAnalUnitID::NeotomaGetChronoControlsByAnalUnitID(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetChronoControlsByAnalysisUnitID";
   AddField("ChronControlID", varInteger);
}
//---------------------------------------------------------------------------

void NeotomaGetChronoControlsByAnalUnitID::AddRecord(vector<Variant>& Record)
{
   int ChronControlID = VariantToInt(Record[0], -1);
   Items.push_back(ChronControlID);
}
//---------------------------------------------------------------------------

NeotomaGetPollenSporeHigherTaxa::NeotomaGetPollenSporeHigherTaxa(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetPollenSporeHigherTaxa";
   AddField("TaxonID", varInteger);
   AddField("HigherTaxonID", varInteger);
}
//---------------------------------------------------------------------------

void NeotomaGetPollenSporeHigherTaxa::AddRecord(vector<Variant>& Record)
{
   int TaxonID = VariantToInt(Record[0], -1);
   int HigherTaxonID = VariantToInt(Record[1], -1);
   // Items.push_back(pair<int,int>(TaxonID,HigherTaxonID));
   Items[TaxonID] = HigherTaxonID;
}
//---------------------------------------------------------------------------

NeotomaGetDatasetPublicationStatus::NeotomaGetDatasetPublicationStatus(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetDatasetPublicationStatus";
   AddField("PrimaryPub", varBoolean);
}
//---------------------------------------------------------------------------

void NeotomaGetDatasetPublicationStatus::AddRecord(vector<Variant>& Record)
{
   bool PrimaryPub = VariantToBool(Record[0], false);
   Items.push_back(PrimaryPub);
}
//---------------------------------------------------------------------------

NeotomaDatasetRepositorySpecimenNotes::NeotomaDatasetRepositorySpecimenNotes(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetDatasetRepositorySpecimenNotes";
   AddField("RepositoryID", varInteger);
   AddField("Notes", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaDatasetRepositorySpecimenNotes::AddRecord(vector<Variant>& Record)
{
   int RepositoryID = VariantToInt(Record[0], -1);
   UnicodeString Notes = VarToStr(Record[1]);
   Items[RepositoryID] = Notes;
}
//---------------------------------------------------------------------------

NeotomaAggregateDatasetBase::NeotomaAggregateDatasetBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   AddField("AggregateDatasetID", varInteger);
   AddField("AggregateDatasetName", varOleStr);
   AddField("AggregateOrderTypeID", varInteger);
   AddField("Notes", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaAggregateDatasetBase::AddRecord(vector<Variant>& Record)
{
   AGGREGATEDATASET agd;
   agd.AggregateDatasetID = VariantToInt(Record[0], -1);
   agd.AggregateDatasetName = VarToStr(Record[1]);
   agd.AggregateOrderTypeID = VariantToInt(Record[2], -1);
   agd.Notes = VarToStr(Record[3]);
   Items.push_back(agd);
}
//---------------------------------------------------------------------------

NeotomaAggregateDatasetByName::NeotomaAggregateDatasetByName(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaAggregateDatasetBase(ipsjsons, tcpClient)
{
   webservice = L"GetAggregateDatasetByName";
}
//---------------------------------------------------------------------------

NeotomaAggregateOrderTypes::NeotomaAggregateOrderTypes(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetAggregateOrderTypes";
   AddField("AggregateOrderTypeID", varInteger);
   AddField("AggregateOrderType", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaAggregateOrderTypes::AddRecord(vector<Variant>& Record)
{
   int AggregateOrderTypeID = VariantToInt(Record[0], -1);
   UnicodeString AggregateOrderType = VarToStr(Record[1]);
   Items[AggregateOrderTypeID] = AggregateOrderType;
}
//---------------------------------------------------------------------------

NeotomaAggregateChronBase::NeotomaAggregateChronBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   AddField("AggregateChronID", varInteger);
   AddField("AggregateDatasetID", varInteger);
   AddField("AgeTypeID", varInteger);
   AddField("IsDefault", varBoolean);
   AddField("ChronologyName", varOleStr);
   AddField("AgeBoundYounger", varInteger);
   AddField("AgeBoundOlder", varInteger);
   AddField("Notes", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaAggregateChronBase::AddRecord(vector<Variant>& Record)
{
   AGGREGATECHRON agc;
   agc.AggregateChronID = VariantToInt(Record[0], -1);
   agc.AggregateDatasetID = VariantToInt(Record[1], -1);
   agc.AgeTypeID = VariantToInt(Record[2], -1);
   agc.IsDefault = VariantToBool(Record[3], false);
   agc.ChronologyName = VarToStr(Record[4]);
   agc.AgeBoundYounger = VariantToInt(Record[5], -1);
   agc.AgeBoundOlder = VariantToInt(Record[6], -1);
   agc.Notes = VarToStr(Record[7]);
   Items.push_back(agc);
}
//---------------------------------------------------------------------------

NeotomaAggregateChronByDatasetID::NeotomaAggregateChronByDatasetID(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaAggregateChronBase(ipsjsons, tcpClient)
{
   webservice = L"GetAggregateChronByDatasetID";
}
//---------------------------------------------------------------------------

NeotomaElementTypesForTaxonTaxaGroup::NeotomaElementTypesForTaxonTaxaGroup(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetElementTypesForTaxonTaxaGroup";
   AddField("ElementTypeID", varInteger);
   AddField("ElementType", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaElementTypesForTaxonTaxaGroup::AddRecord(vector<Variant>& Record)
{
   int ElementTypeID = VariantToInt(Record[0], -1);
   UnicodeString ElementType = VarToStr(Record[1]);
   Items.insert(pair<int,UnicodeString>(ElementTypeID,ElementType));
}
//---------------------------------------------------------------------------

NeotomaSampleIDBase::NeotomaSampleIDBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   AddField("SampleID", varInteger);
}
//---------------------------------------------------------------------------

void NeotomaSampleIDBase::AddRecord(vector<Variant>& Record)
{
   int SampleID = VariantToInt(Record[0], -1);
   Items.push_back(SampleID);
}
//---------------------------------------------------------------------------

NeotomaSpecimenSampleID::NeotomaSpecimenSampleID(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaSampleIDBase(ipsjsons, tcpClient)
{
   webservice = L"GetSpecimenSampleID";
}
//---------------------------------------------------------------------------

NeotomaSampleIDForDatasetIDFromGeochronAnalUnit::NeotomaSampleIDForDatasetIDFromGeochronAnalUnit(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaSampleIDBase(ipsjsons, tcpClient)
{
   webservice = L"GetSampleIDForDatasetIDFromGeochronAnalUnit";
}
//---------------------------------------------------------------------------

NeotomaSampleIDForDatasetTypeIDFromGeochronAnalUnit::NeotomaSampleIDForDatasetTypeIDFromGeochronAnalUnit(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaSampleIDBase(ipsjsons, tcpClient)
{
   webservice = L"GetSampleIDForDatasetTypeIDFromGeochronAnalUnit";
}
//---------------------------------------------------------------------------

NeotomaDatasetIDforDatasetTypeIDforGeochronAnalUnit::NeotomaDatasetIDforDatasetTypeIDforGeochronAnalUnit(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetDatasetIDforDatasetTypeIDforGeochronAnalUnit";
   AddField("DatasetID", varInteger);
}
//---------------------------------------------------------------------------

void NeotomaDatasetIDforDatasetTypeIDforGeochronAnalUnit::AddRecord(vector<Variant>& Record)
{
   int DatasetID = VariantToInt(Record[0], -1);
   Items.push_back(DatasetID);
}
//---------------------------------------------------------------------------

NeotomaGeochronDatasetSpecimenDates::NeotomaGeochronDatasetSpecimenDates(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetSpecimenDatesByGeochronDatasetID";
   AddField("SpecimenDateID", varInteger);
   AddField("SpecimenID", varInteger);
   AddField("GeochronID", varInteger);
   AddField("SampleID", varInteger);
   AddField("TaxonName", varOleStr);
   AddField("ElementType", varOleStr);
   AddField("Fraction", varOleStr);
   AddField("Notes", varOleStr);
   AddField("CalAge", varDouble);
   AddField("CalAgeOlder", varDouble);
   AddField("CalAgeYounger", varDouble);
   AddField("CalibrationCurve", varOleStr);
   AddField("CalibrationProgram", varOleStr);
   AddField("Version", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaGeochronDatasetSpecimenDates::AddRecord(vector<Variant>& Record)
{
   SPECIMENDATE date;
   date.SpecimenDateID = VariantToInt(Record[0], -1);
   date.SpecimenID = VariantToInt(Record[1], -1);
   date.GeochronID = VariantToInt(Record[2], -1);
   date.SampleID = VariantToInt(Record[3], -1);
   date.TaxonName = VarToStr(Record[4]);
   date.ElementType = VarToStr(Record[5]);
   date.Fraction = VarToStr(Record[6]);
   date.Notes = VarToStr(Record[7]);
   date.CalAge = Record[8];
   date.CalAgeOlder = Record[9];
   date.CalAgeYounger = Record[10];
   date.CalibrationCurve = VarToStr(Record[11]);
   date.CalibrationProgram = VarToStr(Record[12]);
   date.Version = VarToStr(Record[13]);
   Items.push_back(date);
}
//---------------------------------------------------------------------------

NeotomaSpecimenDateBySpecimenDateID::NeotomaSpecimenDateBySpecimenDateID(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetSpecimenDateBySpecimenDateID";
   AddField("SpecimenID", varInteger);
   AddField("TaxonID", varInteger);
   AddField("TaxonName", varOleStr);
   AddField("ElementTypeID", varInteger);
   AddField("ElementType", varOleStr);
   AddField("FractionID", varInteger);
   AddField("Fraction", varOleStr);
   AddField("SampleID", varInteger);
   AddField("Notes", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaSpecimenDateBySpecimenDateID::AddRecord(vector<Variant>& Record)
{
   SPECIMENDATEUPDATE date;
   date.SpecimenID = VariantToInt(Record[0], -1);
   date.TaxonID = VariantToInt(Record[1], -1);
   date.TaxonName = VarToStr(Record[2]);
   date.ElementTypeID = VariantToInt(Record[3], -1);
   date.ElementType = VarToStr(Record[4]);
   date.FractionID = VariantToInt(Record[5], -1);
   date.Fraction = VarToStr(Record[6]);
   date.SampleID = VariantToInt(Record[7], -1);
   date.Notes = VarToStr(Record[8]);
   Items.push_back(date);
}
//---------------------------------------------------------------------------

NeotomaSpecimenDateCalBySpecimenDateID::NeotomaSpecimenDateCalBySpecimenDateID(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetSpecimenDateCalBySpecimenDateID";
   AddField("SpecimenDateCalID", varInteger);
   AddField("CalAge", varDouble);
   AddField("CalAgeOlder", varDouble);
   AddField("CalAgeYounger", varDouble);
   AddField("CalibrationCurveID", varInteger);
   AddField("CalibrationCurve", varOleStr);
   AddField("CalibrationProgramID", varInteger);
   AddField("CalibrationProgram", varOleStr);
   AddField("Version", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaSpecimenDateCalBySpecimenDateID::AddRecord(vector<Variant>& Record)
{
   SPECIMENCALDATE cal;
   cal.SpecimenDateCalID = VariantToInt(Record[0], -1);
   cal.CalAge = Record[1];
   cal.CalAgeOlder = Record[2];
   cal.CalAgeYounger = Record[3];
   cal.CalibrationCurveID = VariantToInt(Record[4], -1);
   cal.CalibrationCurve = VarToStr(Record[5]);
   cal.CalibrationProgramID = VariantToInt(Record[6], -1);
   cal.CalibrationProgram = VarToStr(Record[7]);
   cal.Version = VarToStr(Record[8]);
   Items.push_back(cal);
}
//---------------------------------------------------------------------------

NeotomaSpecimenTaxonID::NeotomaSpecimenTaxonID(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetSpecimenTaxonID";
   AddField("TaxonID", varInteger);
}
//---------------------------------------------------------------------------

void NeotomaSpecimenTaxonID::AddRecord(vector<Variant>& Record)
{
   int TaxonID = VariantToInt(Record[0], -1);
   Items.push_back(TaxonID);
}
//---------------------------------------------------------------------------

NeotomaSampleParents::NeotomaSampleParents(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetSampleParents";
   AddField("SiteID", varInteger);
   AddField("SiteName", varOleStr);
   AddField("CollectionUnitID", varInteger);
   AddField("Handle", varOleStr);
   AddField("AnalysisUnitID", varInteger);
   AddField("Depth", varDouble);
}
//---------------------------------------------------------------------------

void NeotomaSampleParents::AddRecord(vector<Variant>& Record)
{
   SAMPLEPARENT sp;
   sp.SiteID = VariantToInt(Record[0], -1);
   sp.SiteName = VarToStr(Record[1]);
   sp.CollectionUnitID = VariantToInt(Record[2], -1);
   sp.Handle = VarToStr(Record[3]);
   sp.AnalysisUnitID = VariantToInt(Record[4], -1);
   sp.Depth = Record[5];
   Items.push_back(sp);
}
//---------------------------------------------------------------------------

NeotomaChildTaxa::NeotomaChildTaxa(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetChildTaxa";
   AddField("TaxonID", varInteger);
   AddField("TaxonName", varOleStr);
   AddField("Author", varOleStr);
   AddField("level", varInteger);
   AddField("HigherTaxonID", varInteger);
}
//---------------------------------------------------------------------------

void NeotomaChildTaxa::AddRecord(vector<Variant>& Record)
{
   CHILDTAXA ct;
   ct.TaxonID = VariantToInt(Record[0], -1);
   ct.TaxonName = VarToStr(Record[1]);
   ct.Author = VarToStr(Record[2]);
   ct.level = VariantToInt(Record[3], -1);
   ct.HigherTaxonID = VariantToInt(Record[4], -1);
   Items.push_back(ct);
}
//---------------------------------------------------------------------------

NeotomaChildTaxaSites::NeotomaChildTaxaSites(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetChildTaxaForAllSites";
   AddField("TaxonID", varInteger);
   AddField("TaxonName", varOleStr);
   AddField("SiteName", varOleStr);
}
//---------------------------------------------------------------------------

void NeotomaChildTaxaSites::AddRecord(vector<Variant>& Record)
{
   CHILDTAXASITES cts;
   cts.TaxonID = VariantToInt(Record[0], -1);
   cts.TaxonName = VarToStr(Record[1]);
   cts.SiteName = VarToStr(Record[2]);
   Items.push_back(cts);
}
//---------------------------------------------------------------------------

NeotomaFuncInputParams::NeotomaFuncInputParams(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"GetProcedureInputParams";
   /*
   if (tiGlobals->RDMS == SQLServer) {
	 AddField("name", varOleStr);
	 AddField("type", varOleStr);
	 AddField("has_default_value", varBoolean);
	 AddField("order", varInteger);
	 }
   else {
   */
   // {"status":"success","data":[{"name":"_taxonname","type":"character varying","isdefault":false,"paramorder":1}],"message":"Retrieved all tables"}
   AddField("name", varOleStr);
   AddField("type", varOleStr);
   AddField("isdefault", varBoolean);
   AddField("paramorder", varInteger);
}
//---------------------------------------------------------------------------

void NeotomaFuncInputParams::AddRecord(vector<Variant>& Record)
{
   int order;
   INPUTPARAMS ip;
   //int has_default_value;
   /*
   if (tiGlobals->RDMS == SQLServer) {
	 ip.name = VarToStr(Record[0]);
	 ip.type = VarToStr(Record[1]);
	 ip.has_default_value = Record[2];
	 order = VariantToInt(Record[3], -1);
	 }
   else {
   */
   if (Record[0].IsEmpty())
	 return;
   ip.name = VarToStr(Record[0]);
   ip.type = VarToStr(Record[1]);
   bool isdefault = Record[2];
   ip.has_default_value = isdefault;
   order = VariantToInt(Record[3], -1);

   Items[order] = ip;
}
//---------------------------------------------------------------------------

NeotomaGetRecentUploadsBase::NeotomaGetRecentUploadsBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   //ShowMessage(L"base constructor");
   AddField("DatasetID", varInteger);
   AddField("DatasetType", varOleStr);
   AddField("SiteName", varOleStr);
   AddField("GeoPolitical", varOleStr);
   AddField("DatabaseName", varOleStr);
   AddField("Investigator", varOleStr);
   AddField("RecDateCreated", varOleStr);
   AddField("Steward", varOleStr);
   //AddField("SiteID", varInteger);
}
//---------------------------------------------------------------------------

void NeotomaGetRecentUploadsBase::AddRecord(vector<Variant>& Record)
{
   NTMRECENTUPLOADS upl;
   //ShowMessage(L"add record");
   upl.DatasetID = VariantToInt(Record[0], -1);
   upl.DatasetType = VarToStr(Record[1]);
   upl.SiteName = VarToStr(Record[2]);
   upl.GeoPolitical = VarToStr(Record[3]);
   upl.DatabaseName = VarToStr(Record[4]);
   upl.Investigator = VarToStr(Record[5]);
   upl.RecDateCreated = VarToStr(Record[6]);
   upl.Steward = VarToStr(Record[7]);
   //upl.SiteID = VariantToInt(Record[8], -1);
   Items.push_back(upl);
}
//---------------------------------------------------------------------------

NeotomaGetRecentUploads400::NeotomaGetRecentUploads400(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaGetRecentUploadsBase(ipsjsons, tcpClient)
{
   webservice = L"GetRecentUploads";
}
//---------------------------------------------------------------------------

NeotomaGetRecentUploads::NeotomaGetRecentUploads(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: NeotomaGetRecentUploadsBase(ipsjsons, tcpClient)
{
   webservice = L"GetRecentUploadsv1";
   AddField("SiteID", varInteger);
}
//---------------------------------------------------------------------------

void NeotomaGetRecentUploads::AddRecord(vector<Variant>& Record)
{
   NTMRECENTUPLOADS upl;
   //ShowMessage(L"add record");
   upl.DatasetID = VariantToInt(Record[0], -1);
   upl.DatasetType = VarToStr(Record[1]);
   upl.SiteName = VarToStr(Record[2]);
   upl.GeoPolitical = VarToStr(Record[3]);
   upl.DatabaseName = VarToStr(Record[4]);
   upl.Investigator = VarToStr(Record[5]);
   upl.RecDateCreated = VarToStr(Record[6]);
   upl.Steward = VarToStr(Record[7]);
   upl.SiteID = VariantToInt(Record[8], -1);
   Items.push_back(upl);
}
//---------------------------------------------------------------------------


