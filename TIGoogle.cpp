//---------------------------------------------------------------------------


#pragma hdrstop

#include "TIGoogle.h"
#include "TISpread.h"
#ifndef TIGlobalsH
#include "TIGlobals.h"
#endif
#ifndef TIGooMapH
#include "TIGooMap.h"
#endif
#ifndef TIGeocodH
#include "TIGeocod.h"
#endif
#ifndef TIShoMemH
#include "TIShoMem.h"
#endif

//---------------------------------------------------------------------------

#pragma package(smart_init)

// Google map button
void __fastcall TTilSpreadSheetForm::cxButton27Click(TObject *Sender)
{
   GoogleMapForm = new TGoogleMapForm(cxRadioButton1->Checked, SitePtr->LatNorth,
	 SitePtr->LatSouth, SitePtr->LongWest, SitePtr->LongEast, this);

   if (GoogleMapForm->ShowModal() == mrOk) {
	 SitePtr->LatNorth = GoogleMapForm->LatNorth;
	 SitePtr->LatSouth = GoogleMapForm->LatSouth;
	 SitePtr->LongWest = GoogleMapForm->LongWest;
	 SitePtr->LongEast = GoogleMapForm->LongEast;
	 cxPopupEdit4->Text = VarToStr(SitePtr->LatNorth);
	 cxPopupEdit5->Text = VarToStr(SitePtr->LatSouth);
	 cxPopupEdit6->Text = VarToStr(SitePtr->LongWest);
	 cxPopupEdit7->Text = VarToStr(SitePtr->LongEast);
	 if (GoogleMapForm->point()) {
	   if (!cxRadioButton1->Checked)
		 cxRadioButton1->Checked = true;
	   }
	 else if (!cxRadioButton2->Checked)
	   cxRadioButton2->Checked = true;
	 }
   delete GoogleMapForm;
}
//---------------------------------------------------------------------------

// Google geocoding button
void __fastcall TTilSpreadSheetForm::cxButton33Click(TObject *Sender)
{
   double latitude, longitude, lat1, lat2, lon1, lon2;
   UnicodeString ErrMsg = L"Invalid latitude/longitude value.";

   ipsJSONS1->Reset();
   if (tiGlobals->InternetTimeout > 60)
	 ipsJSONS1->Timeout = tiGlobals->InternetTimeout;
   ipsJSONS1->Config("KeepAlive=true");
   ipsJSONS1->Config("CodePage=65001");   // UTF-8 CodePage
   ipsJSONS1->BuildDOM = true;
   ipsJSONS1->LocalHost = TcpClient1->LocalHostAddr();
   ipsJSONS1->TransferredDataLimit = 0;

   if (cxPopupEdit4->Text.IsEmpty() || cxPopupEdit6->Text.IsEmpty()) {
	 MessageDlg(ErrMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 return;
	 }
   if (!TryStrToFloat(cxPopupEdit4->Text, lat1) || !TryStrToFloat(cxPopupEdit6->Text, lon1)) {
	 MessageDlg(ErrMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 return;
	 }
   if (cxRadioButton1->Checked) {   // point
	 latitude = lat1;
	 longitude = lon1;
	 }
   else {
	 if (!TryStrToFloat(cxPopupEdit5->Text, lat2) || !TryStrToFloat(cxPopupEdit7->Text, lon2)) {
	   MessageDlg(ErrMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return;
	   }
	 latitude = (lat1 + lat2)/2;
	 longitude = (lon1 + lon2)/2;
	 }

   if (latitude > 90.0 || latitude < -90.0 || longitude > 180.0 || longitude < -180.0) {
     MessageDlg(ErrMsg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 return;
	 }

   // https://maps.googleapis.com/maps/api/geocode/json?key=AIzaSyAjlZDXT0ZiuAjv4fJ89wbxJaA_iTZQTmc&latlng=45.0,-93.0

   UnicodeString url = L"https://maps.googleapis.com/maps/api/geocode/json?key=AIzaSyAjlZDXT0ZiuAjv4fJ89wbxJaA_iTZQTmc&latlng=" +
					   FloatToStr(latitude) + L"," + FloatToStr(longitude);

   //ShowMemoForm = new TShowMemoForm(L"URL", url, NULL);
   //ShowMemoForm->ShowModal();
   //delete ShowMemoForm;

   try {
	   ipsJSONS1->Get(url);
	   }
   catch (const Exception &e) {
	   MessageDlg(e.Message, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return;
	   }

   UnicodeString XPath = "/json/results";
   UnicodeString XPath1;
   UnicodeString XPath2;

   ipsJSONS1->XPath = XPath;

   map<UnicodeString,UnicodeString> PoliticalUnits;

   //ShowMessage(L"XChildrenCount = " + IntToStr(ipsJSONS1->XChildrenCount));
   for (int k=1; k<=ipsJSONS1->XChildrenCount; k++) {
	 // XPath = L"/json/results/[" + IntToStr(k) + L"]/[1]";
	 XPath = L"/json/results/[" + IntToStr(k) + L"]/address_components";
	 ipsJSONS1->XPath = XPath;
	 //ShowMessage(XPath);
	 int numChildren = ipsJSONS1->XChildrenCount;
	 //ShowMessage(L"numChildren = " + IntToStr(numChildren));
	 for (int i=1; i<=numChildren; i++) {
	   XPath1 = XPath + L"/[" + IntToStr(i) + L"]";
	   ipsJSONS1->XPath = XPath1;
	   //ShowMessage(XPath1);
	   int nc = ipsJSONS1->XChildrenCount;
	   UnicodeString long_name;
	   UnicodeString type;
	   UnicodeString type_name;
	   bool political = false;
	   //ShowMessage(L"nc = " + IntToStr(nc));
	   for (int j=0; j<nc; j++) {
		 if (SameText(ipsJSONS1->XChildName[j], L"long_name")) {
		   long_name = StripTextQuotes(ipsJSONS1->XChildXText[j]);
		   //ShowMessage(long_name);
		   }
		 else if (SameText(ipsJSONS1->XChildName[j], L"types")) {
		   XPath2 = XPath1 + L"/types";
		   ipsJSONS1->XPath = XPath2;
		   switch (ipsJSONS1->XChildrenCount) {
			 case 2:
			   type = StripTextQuotes(ipsJSONS1->XChildXText[1]);
			   if (SameText(type, L"political")) {
				 type_name = StripTextQuotes(ipsJSONS1->XChildXText[0]);
				 political = true;
				 }
			   break;
			 case 1:
			   type = StripTextQuotes(ipsJSONS1->XChildXText[0]);
			   if (SameText(type ,L"political"))
				 political = true;
			   break;
			 }
		   }
		 }
	   if (political)
		 PoliticalUnits[long_name] = type_name;
	   }
	 }

   GoogleGeocodesForm = new TGoogleGeocodesForm(latitude, longitude, PoliticalUnits, this);
   GoogleGeocodesForm->ShowModal();
   delete GoogleGeocodesForm;
}
//---------------------------------------------------------------------------

