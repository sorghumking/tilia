//---------------------------------------------------------------------------


#pragma hdrstop
#include "TIGetFM2.h"
#include "TISpread.h"
#ifndef TGParentH
#include "TGParent.h"
#endif
#ifndef TIJSONH
#include "TIJSON.h"
#endif
#ifndef TIMemoH
#include "TIMemo.h"
#endif
#include "TIGetEPD.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

bool EPDDecodeDateStr(UnicodeString DateStr, TDateTime& Date)
{
   // 1964-10-15
   unsigned short year;
   unsigned short month;
   unsigned short day;
   int iVal;

   if (DateStr.Length() != 10)
	 return false;
   if (DateStr.SubString(5,1) != L"-" || DateStr.SubString(8,1) != L"-")
	 return false;

   if (TryStrToInt(DateStr.SubString(1,4),iVal))
	 year = iVal;
   else
	 return false;
   if (year > 0) {
	 if (TryStrToInt(DateStr.SubString(6,2),iVal))
	   month = iVal;
	 else
	   return false;
	 if (month > 0) {
	   if (TryStrToInt(DateStr.SubString(9,2),iVal))
		 day = iVal;
	   else
		 return false;
	   if (day == 0)
		 day = 1;
	   }
	 else {
	   month = 1;
	   day = 1;
	   }
	 Date = TDateTime(year, month, day);
	 }
   else
	 return false;

   return true;
 }
//---------------------------------------------------------------------------

EPDGetCountriesWithSitesNotInNeotoma::EPDGetCountriesWithSitesNotInNeotoma(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"EPD_GetCountriesWithSitesNotInNeotoma";
   AddField("PolDiv1", varOleStr);
   AddField("GeoPoliticalID", varInteger);
}
//---------------------------------------------------------------------------

void EPDGetCountriesWithSitesNotInNeotoma::AddRecord(vector<Variant>& Record)
{
   UnicodeString PolDiv1 = VarToStr(Record[0]);
   int GeoPoliticalID = VariantToInt(Record[1], -1);
   Items[PolDiv1] = GeoPoliticalID;
}
//---------------------------------------------------------------------------

EPDGetSiteBase::EPDGetSiteBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   AddField("Site#", varInteger);
   AddField("SiteName", varOleStr);
   AddField("LatDD", varDouble);
   AddField("LonDD", varDouble);
   AddField("Elevation", varDouble);
   AddField("AreaOfSite", varDouble);
   AddField("PolDiv1", varOleStr);
   AddField("PolDiv2", varOleStr);
   AddField("PolDiv3", varOleStr);
   AddField("UseStatus", varOleStr);
}
//---------------------------------------------------------------------------

void EPDGetSiteBase::AddRecord(vector<Variant>& Record)
{
   EPDSITELOC sl;
   int SiteNr = VariantToInt(Record[0], -1);
   sl.SiteName = VarToStr(Record[1]);
   sl.LatDD = Record[2];
   sl.LonDD = Record[3];
   sl.Elevation = Record[4];
   sl.AreaOfSite = Record[5];
   sl.PolDiv1 = VarToStr(Record[6]);
   sl.PolDiv2 = VarToStr(Record[7]);
   sl.PolDiv3 = VarToStr(Record[8]);
   sl.UseStatus = VarToStr(Record[9]);
   Items[SiteNr] = sl;
}
//---------------------------------------------------------------------------

EPDGetSiteByName::EPDGetSiteByName(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: EPDGetSiteBase(ipsjsons, tcpClient)
{
   webservice = L"EPD_GetSiteByName";
}
//---------------------------------------------------------------------------

EPDGetSitesNotInNeotomaByCountry::EPDGetSitesNotInNeotomaByCountry(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: EPDGetSiteBase(ipsjsons, tcpClient)
{
   webservice = L"EPD_GetSitesNotInNeotomaByCountry";
}
//---------------------------------------------------------------------------

EPDGetEntitiesBySiteNr::EPDGetEntitiesBySiteNr(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"EPD_GetEntitiesBySiteNr";
   AddField("E#", varInteger);
   AddField("Sigle", varOleStr);
   AddField("Name", varOleStr);
}
//---------------------------------------------------------------------------

void EPDGetEntitiesBySiteNr::AddRecord(vector<Variant>& Record)
{
   int ENr = VariantToInt(Record[0], -1);
   UnicodeString Sigle = VarToStr(Record[1]);
   UnicodeString Name = VarToStr(Record[2]);
   Items[ENr] = pair<UnicodeString,UnicodeString>(Sigle,Name);
}
//---------------------------------------------------------------------------

EPDGetSiteDescription::EPDGetSiteDescription(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"EPD_GetSiteDescription";
   AddField("SiteDescript", varOleStr);
   AddField("Physiography", varOleStr);
   AddField("SurroundVeg", varOleStr);
   AddField("VegFormation", varOleStr);
}
//---------------------------------------------------------------------------

void EPDGetSiteDescription::AddRecord(vector<Variant>& Record)
{
   EPDSITEDESC desc;
   desc.SiteDescript = VarToStr(Record[0]);
   desc.Physiography = VarToStr(Record[1]);
   desc.SurroundVeg = VarToStr(Record[2]);
   desc.VegFormation = VarToStr(Record[3]);
   Items.push_back(desc);
}
//---------------------------------------------------------------------------

EPDGetEntity::EPDGetEntity(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"EPD_GetEntity";
   AddField("Sigle", varOleStr);
   AddField("Name", varOleStr);
   AddField("IsCore", varOleStr);
   AddField("IsSect", varOleStr);
   AddField("IsSSamp", varOleStr);
   AddField("DepEnvt", varOleStr);
   AddField("EntLoc", varOleStr);
   AddField("LocalVeg", varOleStr);
   AddField("Coll#", varInteger);
   AddField("SampDate", varOleStr);
   AddField("DepthAtLoc", varDouble);
   AddField("SampDevice", varOleStr);
   AddField("CoreDiamCM", varDouble);
   AddField("Notes", varOleStr);
}
//---------------------------------------------------------------------------

void EPDGetEntity::AddRecord(vector<Variant>& Record)
{
   TDateTime Date;
   EPDENTITY ent;

   ent.Sigle = VarToStr(Record[0]);
   ent.Name = VarToStr(Record[1]);
   ent.IsCore = (VarToStr(Record[2]) == L"Y");
   ent.IsSect = (VarToStr(Record[3]) == L"Y");
   ent.IsSSamp = (VarToStr(Record[4]) == L"Y");
   ent.DepEnvt = VarToStr(Record[5]);
   ent.EntLoc = VarToStr(Record[6]);
   ent.LocalVeg = VarToStr(Record[7]);
   ent.CollNr = Record[8];
   UnicodeString SampDate = VarToStr(Record[9]);     // 1964-10-15
   if (EPDDecodeDateStr(SampDate,Date))
	 ent.SampDate = Date;
   else
     ent.SampDate.ChangeType(varEmpty);
   ent.DepthAtLoc = Record[10];
   ent.SampDevice = VarToStr(Record[11]);
   ent.CoreDiamCM = Record[12];
   ent.Notes = VarToStr(Record[13]);
   Items.push_back(ent);
}
//---------------------------------------------------------------------------

EPDGetWorker::EPDGetWorker(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"EPD_GetWorker";
   AddField("Status", varOleStr);
   AddField("LastName", varOleStr);
   AddField("Initials", varOleStr);
   AddField("FirstName", varOleStr);
   AddField("Suffix", varOleStr);
   AddField("Title", varOleStr);
   AddField("Country", varOleStr);
   AddField("Phone", varOleStr);
   AddField("Fax", varOleStr);
   AddField("EMailAddr", varOleStr);
   AddField("Address", varOleStr);
}
//---------------------------------------------------------------------------

void EPDGetWorker::AddRecord(vector<Variant>& Record)
{
   EPDWORKER work;
   work.Status = VarToStr(Record[0]);
   work.LastName = VarToStr(Record[1]);
   work.Initials = VarToStr(Record[2]);
   work.FirstName = VarToStr(Record[3]);
   work.Suffix = VarToStr(Record[4]);
   work.Title = VarToStr(Record[5]);
   work.Country = VarToStr(Record[6]);
   work.Phone = VarToStr(Record[7]);
   work.Fax = VarToStr(Record[8]);
   work.EMailAddr = VarToStr(Record[9]);
   work.Address = VarToStr(Record[10]);
   Items.push_back(work);
}
//---------------------------------------------------------------------------

EPDGetPublBase::EPDGetPublBase(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   AddField("Publ#", varInteger);
   AddField("YearOfPubl", varOleStr);
   AddField("Citation", varOleStr);
}
//---------------------------------------------------------------------------

void EPDGetPublBase::AddRecord(vector<Variant>& Record)
{
   EPDPUBL pub;
   pub.PublNr = VariantToInt(Record[0], -1);
   pub.YearOfPubl = VarToStr(Record[1]);
   pub.Citation = VarToStr(Record[2]);
   Items.push_back(pub);
}
//---------------------------------------------------------------------------

EPDGetPublEnt::EPDGetPublEnt(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: EPDGetPublBase(ipsjsons, tcpClient)
{
   webservice = L"EPD_GetPublEnt";
}
//---------------------------------------------------------------------------

EPDGetPubl::EPDGetPubl(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: EPDGetPublBase(ipsjsons, tcpClient)
{
   webservice = L"EPD_GetPubl";
}
//---------------------------------------------------------------------------

EPDGetAuthors::EPDGetAuthors(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"EPD_GetAuthors";
   AddField("Order", varInteger);
   AddField("Worker#", varInteger);
}
//---------------------------------------------------------------------------

void EPDGetAuthors::AddRecord(vector<Variant>& Record)
{
   int Order = VariantToInt(Record[0], -1);
   int WorkerNr = VariantToInt(Record[1], -1);
   Items[Order] = WorkerNr;
}
//---------------------------------------------------------------------------

EPDGetPEntity::EPDGetPEntity(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"EPD_GetPEntity";
   AddField("Contact#", varInteger);
   AddField("DataSource", varOleStr);
}
//---------------------------------------------------------------------------

void EPDGetPEntity::AddRecord(vector<Variant>& Record)
{
   EPDPENTITY pent;
   pent.ContactNr = VariantToInt(Record[0], -1);
   pent.DataSource = VarToStr(Record[1]);
   Items.push_back(pent);
}
//---------------------------------------------------------------------------

EPDGetPSample::EPDGetPSample(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"EPD_GetPSample";
   AddField("Sample#", varInteger);
   AddField("DepthCM", varDouble);
   AddField("Thickness", varDouble);
   AddField("Analyst#", varInteger);
   AddField("AnalyDate", varOleStr);
   AddField("Notes", varOleStr);
}
//---------------------------------------------------------------------------

void EPDGetPSample::AddRecord(vector<Variant>& Record)
{
   EPDPSAMPLE samp;
   samp.SampleNr = VariantToInt(Record[0], -1);
   samp.DepthCM = VariantToDouble(Record[1],0.0);
   samp.Thickness = Record[2];
   samp.AnalystNr = Record[3];
   samp.AnalyDate = VarToStr(Record[4]);
   samp.Notes = VarToStr(Record[5]);
   Items.push_back(samp);
}
//---------------------------------------------------------------------------

EPDGetPVars::EPDGetPVars(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"EPD_GetPVars";
   AddField("Var#", varInteger);
   AddField("VarName", varOleStr);
   AddField("TaxonCode", varOleStr);
   AddField("TaxonName", varOleStr);
   AddField("Element", varOleStr);
   AddField("Units", varOleStr);
   AddField("Context", varOleStr);
   AddField("Taphonomy", varOleStr);
   AddField("EcolGroup", varOleStr);
}
//---------------------------------------------------------------------------

void EPDGetPVars::AddRecord(vector<Variant>& Record)
{
   EPDPVAR var;
   var.VarNr = VariantToInt(Record[0], -1);
   var.VarName = VarToStr(Record[1]);
   var.TaxonCode = VarToStr(Record[2]);
   var.TaxonName = VarToStr(Record[3]);
   var.Element = VarToStr(Record[4]);
   var.Units = VarToStr(Record[5]);
   var.Context = VarToStr(Record[6]);
   var.Taphonomy = VarToStr(Record[7]);
   var.EcolGroup = VarToStr(Record[8]);
   Items.push_back(var);
}
//---------------------------------------------------------------------------

EPDGetPCounts::EPDGetPCounts(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"EPD_GetPCounts";
   AddField("Sample#", varInteger);
   AddField("Var#", varInteger);
   AddField("Count", varDouble);
}
//---------------------------------------------------------------------------

void EPDGetPCounts::AddRecord(vector<Variant>& Record)
{
   EPDPCOUNT count;
   count.SampleNr = VariantToInt(Record[0], -1);
   count.VarNr = VariantToInt(Record[1], -1);
   count.Count = VariantToDouble(Record[2],0.0);
   Items.push_back(count);
}
//---------------------------------------------------------------------------

EPDGetGeochron::EPDGetGeochron(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"EPD_GetGeochron";
   AddField("Sample#", varInteger);
   AddField("Method", varOleStr);
   AddField("DepthCM", varDouble);
   AddField("Thickness", varDouble);
   AddField("MaterialDated", varOleStr);
   AddField("Publ#", varInteger);
}
//---------------------------------------------------------------------------

void EPDGetGeochron::AddRecord(vector<Variant>& Record)
{
   EPDGEOCHRON gch;
   gch.SampleNr = VariantToInt(Record[0], -1);
   UnicodeString Method = VarToStr(Record[1]);
   if (!Method.IsEmpty()) {
	 char method = Method[1];
	 switch (method) {
	   case 'A':
		 gch.Method = L"Argon-argon";
		 break;
	   case 'C':
		 gch.Method = L"Carbon-14";
		 break;
	   case 'E':
		 gch.Method = L"Electron spin resonance";
		 break;
	   case 'F':
		 gch.Method = L"Fission track";
		 break;
	   case 'K':
		 gch.Method = L"Potassium-argon";
		 break;
	   case 'P':
		 gch.Method = L"Lead-210";
		 break;
	   case 'S':
		 gch.Method = L"Silicon-32";
		 break;
	   case 'T':
		 gch.Method = L"Thermoluminescence";
		 break;
	   case 'U':
		 gch.Method = L"Uranium series";
		 break;
	   }
	 }
   gch.DepthCM = VariantToDouble(Record[2],0.0);
   gch.Thickness = Record[3];
   gch.MaterialDated = VarToStr(Record[4]);
   gch.PublNr = Record[5];
   Items.push_back(gch);
}
//---------------------------------------------------------------------------

EPDGetC14::EPDGetC14(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"EPD_GetC14";
   AddField("Sample#", varInteger);
   AddField("AgeBP", varDouble);
   AddField("AgeSDUp", varDouble);
   AddField("AgeSDLo", varDouble);
   AddField("GrThanAge", varOleStr);   // Y,N,NULL
   AddField("Basis", varOleStr);
   AddField("LabNumber", varOleStr);
   AddField("DeltaC13", varDouble);
   AddField("Notes", varOleStr);
}
//---------------------------------------------------------------------------

void EPDGetC14::AddRecord(vector<Variant>& Record)
{
   EPDC14 C14;
   int SampleNr = VariantToInt(Record[0], -1);
   C14.AgeBP = Record[1];
   C14.AgeSDUp = Record[2];
   C14.AgeSDLo = Record[3];
   UnicodeString GrThanAge = VarToStr(Record[4]);
   C14.GrThanAge = SameText(GrThanAge, L"Y");
   UnicodeString Basis = VarToStr(Record[5]);
   if (!Basis.IsEmpty()) {
	 char basis = Basis[1];
	 switch (basis) {
	   case 'A':
		 C14.Basis = L"accelerator mass spectrometry";
		 break;
	   case 'G':
		 C14.Basis = L"proportional gas counting";
		 break;
	   case 'L':
		 C14.Basis = L"liquid scintillation";
		 break;
	   case 'U':
		 C14.Basis = L"conventional radiometric";
		 break;
	   default:
		 C14.Basis = L"unspecified";
		 break;
	   }
	 }
   else
	 C14.Basis = L"unspecified";
   C14.LabNumber = VarToStr(Record[6]);
   C14.DeltaC13 = Record[7];
   C14.Notes = VarToStr(Record[8]);
   Items[SampleNr] = C14;
}
//---------------------------------------------------------------------------

EPDGetPb210::EPDGetPb210(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"EPD_GetPb210";
   AddField("Sample#", varInteger);
   AddField("AgeAD", varDouble);
   AddField("AgeSE", varDouble);
   AddField("GrThanAge", varOleStr);   // Y,N,NULL
   AddField("Notes", varOleStr);
}
//---------------------------------------------------------------------------

void EPDGetPb210::AddRecord(vector<Variant>& Record)
{
   EPDPB210 PB210;
   int SampleNr = VariantToInt(Record[0], -1);
   PB210.AgeAD = Record[1];
   PB210.AgeSE = Record[2];
   UnicodeString GrThanAge = VarToStr(Record[3]);
   PB210.GrThanAge = SameText(GrThanAge, L"Y");
   PB210.Notes = VarToStr(Record[4]);
   Items[SampleNr] = PB210;
}
//---------------------------------------------------------------------------

EPDGetTL::EPDGetTL(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"EPD_GetTL";
   AddField("Sample#", varInteger);
   AddField("AgeBP", varDouble);
   AddField("ErrorLimits", varDouble);
   AddField("GrainSize", varOleStr);
   AddField("LabNumber", varOleStr);
   AddField("Notes", varOleStr);
}
//---------------------------------------------------------------------------

void EPDGetTL::AddRecord(vector<Variant>& Record)
{
   EPDTL TL;
   int SampleNr = VariantToInt(Record[0], -1);
   TL.AgeBP = Record[1];
   TL.ErrorLimits = Record[2];
   TL.GrainSize = VarToStr(Record[3]);
   TL.LabNumber = VarToStr(Record[4]);
   TL.Notes = VarToStr(Record[5]);
   Items[SampleNr] = TL;
}
//---------------------------------------------------------------------------

EPDGetUSeries::EPDGetUSeries(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"EPD_GetUSeries";
   AddField("Sample#", varInteger);
   AddField("AgeBP", varDouble);
   AddField("ErrorLimits", varDouble);
   AddField("LabNumber", varOleStr);
   AddField("Notes", varOleStr);
}
//---------------------------------------------------------------------------

void EPDGetUSeries::AddRecord(vector<Variant>& Record)
{
   EPDUSERIES Us;
   int SampleNr = VariantToInt(Record[0], -1);
   Us.AgeBP = Record[1];
   Us.ErrorLimits = Record[2];
   Us.LabNumber = VarToStr(Record[3]);
   Us.Notes = VarToStr(Record[4]);
   Items[SampleNr] = Us;
}
//---------------------------------------------------------------------------

EPDGetChron::EPDGetChron(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"EPD_GetChron";
   AddField("Chron#", varInteger);
   AddField("Default", varOleStr);
   AddField("Name", varOleStr);
   AddField("DatePrepared", varOleStr);
   AddField("Model", varOleStr);
   AddField("Notes", varOleStr);
   AddField("NeotomaContactID", varInteger);
   AddField("Worker#", varInteger);
   AddField("Top", varDouble);
   AddField("Bottom", varDouble);
}
//---------------------------------------------------------------------------

void EPDGetChron::AddRecord(vector<Variant>& Record)
{
   TDateTime Date;
   EPDCHRON chron;

   chron.ChronNr = VariantToInt(Record[0], -1);
   UnicodeString Default = VarToStr(Record[1]);
   chron.Default = SameText(Default, L"Y");
   chron.Name = VarToStr(Record[2]);
   UnicodeString DatePrep = VarToStr(Record[3]);     // 1964-10-15
   if (EPDDecodeDateStr(DatePrep,Date))
	 chron.DatePrepared = Date;
   else
	 chron.DatePrepared.ChangeType(varEmpty);
   chron.Model = VarToStr(Record[4]);
   chron.Notes = VarToStr(Record[5]);
   chron.NeotomaContactID = Record[6];
   chron.WorkerNr = Record[7];
   chron.Top = Record[8];
   chron.Bottom = Record[9];
   Items.push_back(chron);
}
//---------------------------------------------------------------------------

EPDGetAgeBasis::EPDGetAgeBasis(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"EPD_GetAgeBasis";
   AddField("DepthCM", varDouble);
   AddField("Thickness", varDouble);
   AddField("Age", varDouble);
   AddField("AgeUp", varDouble);
   AddField("AgeLo", varDouble);
   AddField("RCode", varOleStr);
}
//---------------------------------------------------------------------------

void EPDGetAgeBasis::AddRecord(vector<Variant>& Record)
{
   EPDAGEBASIS ab;
   ab.DepthCM = VariantToDouble(Record[0],0.0);
   ab.Thickness = Record[1];
   ab.Age = Record[2];
   ab.AgeUp = Record[3];
   ab.AgeLo = Record[4];
   ab.RCode = VarToStr(Record[5]);
   Items.push_back(ab);
}
//---------------------------------------------------------------------------

EPDGetSynEvent::EPDGetSynEvent(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"EPD_GetSynEvent";
   AddField("DepthCM", varDouble);
   AddField("Thickness", varDouble);
   AddField("Name", varOleStr);
   AddField("AgeBP", varDouble);
   AddField("AgeUncertUp", varDouble);
   AddField("AgeUncertLo", varDouble);
}
//---------------------------------------------------------------------------

void EPDGetSynEvent::AddRecord(vector<Variant>& Record)
{
   EPDSYNEVENT syn;
   syn.DepthCM = VariantToDouble(Record[0],0.0);
   syn.Thickness = Record[1];
   syn.Name = VarToStr(Record[2]);
   syn.AgeBP = Record[3];
   syn.AgeUncertUp = Record[4];
   syn.AgeUncertLo = Record[5];
   Items.push_back(syn);
}
//---------------------------------------------------------------------------

EPDGetPAgeDpt::EPDGetPAgeDpt(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"EPD_GetPAgeDpt";
   AddField("Sample#", varInteger);
   AddField("AgeBP", varDouble);
   AddField("AgeUp", varDouble);
   AddField("AgeLo", varDouble);
}
//---------------------------------------------------------------------------

void EPDGetPAgeDpt::AddRecord(vector<Variant>& Record)
{
   EPDGETPAGEDPT ad;
   int SampleNr = VariantToInt(Record[0], -1);
   ad.AgeBP = Record[1];
   ad.AgeUp = Record[2];
   ad.AgeLo = Record[3];
   Items[SampleNr] = ad;
}
//---------------------------------------------------------------------------

EPDGetLithology::EPDGetLithology(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"EPD_GetLithology";
   AddField("Descript", varOleStr);
   AddField("DepthTopCM", varDouble);
   AddField("DepthBotCM", varDouble);
   AddField("LoBoundary", varOleStr);
}
//---------------------------------------------------------------------------

void EPDGetLithology::AddRecord(vector<Variant>& Record)
{
   EPDLITHOLOGY lith;
   lith.Descript = VarToStr(Record[0]);
   lith.DepthTopCM = VariantToDouble(Record[1],0.0);
   lith.DepthBotCM = VariantToDouble(Record[2],0.0);
   lith.LoBoundary = VarToStr(Record[3]);
   Items.push_back(lith);
}
//---------------------------------------------------------------------------

EPDGetLOI::EPDGetLOI(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"EPD_GetLOI";
   AddField("DepthCM", varDouble);
   AddField("Thickness", varDouble);
   AddField("TempLo", varInteger);
   AddField("LOILo", varDouble);
   AddField("TempHi", varInteger);
   AddField("LOIHi", varDouble);
   AddField("BulkDens", varDouble);
}
//---------------------------------------------------------------------------

void EPDGetLOI::AddRecord(vector<Variant>& Record)
{
   EPDLOI loi;
   loi.DepthCM = VariantToDouble(Record[0],0.0);
   loi.Thickness = Record[1];
   loi.TempLo = Record[2];
   loi.LOILo = Record[3];
   loi.TempHi = Record[4];
   loi.LOIHi = Record[5];
   loi.BulkDens = Record[6];
   Items.push_back(loi);
}
//---------------------------------------------------------------------------

EPDGetMADCAPAgeModel::EPDGetMADCAPAgeModel(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"EPD_GetMADCAPAgeModel";
   AddField("AgeModelType", varInteger);
}
//---------------------------------------------------------------------------

void EPDGetMADCAPAgeModel::AddRecord(vector<Variant>& Record)
{
   int AgeModelType = VariantToInt(Record[0], -1);
   Items.push_back(AgeModelType);
}
//---------------------------------------------------------------------------

EPDGetMADCAPChronControls::EPDGetMADCAPChronControls(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"EPD_GetMADCAPChronControls";
   AddField("DepthCM", varDouble);
   AddField("Thickness", varDouble);
   AddField("RCode", varOleStr);
   AddField("LabNr", varOleStr);
   AddField("Age14C", varDouble);
   AddField("AgeCal", varDouble);
   AddField("SD", varDouble);
   AddField("Reservoir", varDouble);
}
//---------------------------------------------------------------------------

void EPDGetMADCAPChronControls::AddRecord(vector<Variant>& Record)
{
   MADCAPCHRONCONTROL cc;
   cc.DepthCM = VariantToDouble(Record[0],0.0);
   cc.Thickness = Record[1];
   cc.RCode = VarToStr(Record[2]);
   cc.LabNr = VarToStr(Record[3]);
   cc.Age14C = Record[4];
   cc.AgeCal = Record[5];
   cc.SD = Record[6];
   cc.Reservoir = Record[7];
   Items.push_back(cc);
}
//---------------------------------------------------------------------------

EPDGetMADCAPContactNotes::EPDGetMADCAPContactNotes(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"EPD_GetMADCAPContactNotes";
   AddField("WorkerNr", varInteger);
   AddField("Notes", varOleStr);
}
//---------------------------------------------------------------------------

void EPDGetMADCAPContactNotes::AddRecord(vector<Variant>& Record)
{
   int WorkerNr = VariantToInt(Record[0], -1);
   UnicodeString Notes = VarToStr(Record[1]);
   Items.push_back(pair<int,UnicodeString>(WorkerNr,Notes));
}
//---------------------------------------------------------------------------

EPDGetMADCAPReliableAges::EPDGetMADCAPReliableAges(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"EPD_GetMADCAPReliableAges";
   AddField("MinAge", varDouble);
   AddField("MaxAge", varDouble);
}
//---------------------------------------------------------------------------

void EPDGetMADCAPReliableAges::AddRecord(vector<Variant>& Record)
{
   Items.push_back(pair<Variant,Variant>(Record[0],Record[1]));
}
//---------------------------------------------------------------------------

EPDGetMADCAPSampleAges::EPDGetMADCAPSampleAges(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"EPD_GetMADCAPSampleAges";
   AddField("DepthCM", varDouble);
   AddField("Age", varDouble);
   AddField("AgeMin", varDouble);
   AddField("AgeMax", varDouble);
}
//---------------------------------------------------------------------------

void EPDGetMADCAPSampleAges::AddRecord(vector<Variant>& Record)
{
   MADCAPSAMPLEAGE age;
   double DepthCM = VariantToDouble(Record[0],0.0);
   age.Age = VariantToDouble(Record[1],0.0);
   age.AgeMin = VariantToDouble(Record[2],0.0);
   age.AgeMax = VariantToDouble(Record[3],0.0);
   Items[DepthCM] = age;
}
//---------------------------------------------------------------------------

EPDGetNeotomaSiteCollUnitIDs::EPDGetNeotomaSiteCollUnitIDs(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"EPD_GetNeotomaSiteCollUnitIDs";
   AddField("SiteID", varInteger);
   AddField("CollectionUnitID", varInteger);
}
//---------------------------------------------------------------------------

void EPDGetNeotomaSiteCollUnitIDs::AddRecord(vector<Variant>& Record)
{
   int SiteID = VariantToInt(Record[0], -1);
   int CollectionUnitID = VariantToInt(Record[1], -1);
   Items.push_back(pair<int,int>(SiteID,CollectionUnitID));
}
//---------------------------------------------------------------------------

EPDGetNeotomaDatasetIDs::EPDGetNeotomaDatasetIDs(TipsJSONS *ipsjsons, TTcpClient *tcpClient)
	: SJSONTABLE(ipsjsons, tcpClient)
{
   webservice = L"EPD_GetNeotomaDatasetIDs";
   AddField("DatasetID", varInteger);
   AddField("DatasetTypeID", varInteger);
}
//---------------------------------------------------------------------------

void EPDGetNeotomaDatasetIDs::AddRecord(vector<Variant>& Record)
{
   int DatasetID = VariantToInt(Record[0], -1);
   int DatasetTypeID = VariantToInt(Record[1], -1);
   Items[DatasetTypeID] = DatasetID;
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::DownloadEPDData(int EPDSiteNr, int EPDENr, EPDSITELOC& EPDSiteLoc)
{
   UnicodeString msg;
   TDateTime Date;
   map<int,CONTACT*> Workers;   // Worker#, CONTACT pointer
   map<int,int> Samples;        // Sample#, column
   map<int,int> Vars;           // Var#, row
   map<int,PUBLICATION*> Pubs;  // Publ#, PUBLICATION pointer
   set<int> ChronNr;
   int MADCAPChronNr = 1;

   Screen->Cursor = crHourGlass;

   SITE* SitePtr = (SITE*)Sites->Items[0];
   SitePtr->SiteName = EPDSiteLoc.SiteName;
   SitePtr->Country = EPDSiteLoc.PolDiv1;
   if (!EPDSiteLoc.LatDD.IsEmpty()) {
	 SitePtr->LatNorth = EPDSiteLoc.LatDD;
	 SitePtr->LatSouth = EPDSiteLoc.LatDD;
	 }
   if (!EPDSiteLoc.LonDD.IsEmpty()) {
	 SitePtr->LongEast = EPDSiteLoc.LonDD;
	 SitePtr->LongWest = EPDSiteLoc.LonDD;
	 }
   if (!EPDSiteLoc.Elevation.IsEmpty())
	 SitePtr->Altitude = EPDSiteLoc.Elevation;
   if (!EPDSiteLoc.AreaOfSite.IsEmpty())
	 SitePtr->Area = EPDSiteLoc.AreaOfSite;

   if (!EPDSiteLoc.PolDiv2.IsEmpty()) {
	 NeotomaNextLowerGeoPolCountByNames GeoPol2Count(ipsJSONS1, TcpClient1);
	 GeoPol2Count.AddParam(L"NAME1", EPDSiteLoc.PolDiv1);
	 GeoPol2Count.AddParam(L"RANK1", 1);
	 GeoPol2Count.AddParam(L"NAME2", EPDSiteLoc.PolDiv2);
	 GeoPol2Count.AddParam(L"RANK2", 2);
	 XMLParsingStatus(GeoPol2Count.WebServiceName());
	 if (GeoPol2Count.Execute()) {
	   if (GeoPol2Count.Size() == 1) {
		 if (GeoPol2Count.Items[0] == 0) {
		   msg = L"Geopolitical Unit «" + EPDSiteLoc.PolDiv2 +
				 L"» in EPD is not a Rank 2 subdivision of Rank 1 GeoPolitial Unit «" + EPDSiteLoc.PolDiv1 + L"».";
		   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   }
		 else
		   SitePtr->State = EPDSiteLoc.PolDiv2;
		 }
	   }
	 else {
	   msg = L"Error executing service NeotomaNextLowerGeoPolCountByNames.";
	   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   }
	 }

   // get site description
   EPDGetSiteDescription SiteDesc(ipsJSONS1, TcpClient1);
   SiteDesc.AddParam(L"SITENR", EPDSiteNr);
   XMLParsingStatus(SiteDesc.WebServiceName());
   if (SiteDesc.Execute()) {
	 if (SiteDesc.Size() == 1) {
	   if (!SiteDesc.Items[0].SiteDescript.IsEmpty())
		 SitePtr->SiteDescription = MakeSentence(SiteDesc.Items[0].SiteDescript);
	   if (!SiteDesc.Items[0].Physiography.IsEmpty()) {
		 if (!SitePtr->SiteDescription.IsEmpty())
		   SitePtr->SiteDescription += L" ";
		 SitePtr->SiteDescription += L"Physiography: " + MakeSentence(SiteDesc.Items[0].Physiography);
		 }
	   if (!SiteDesc.Items[0].SurroundVeg.IsEmpty()) {
		 if (!SitePtr->SiteDescription.IsEmpty())
		   SitePtr->SiteDescription += L" ";
		 SitePtr->SiteDescription += L"Surrounding vegetation: " + MakeSentence(SiteDesc.Items[0].SurroundVeg);
		 }
	   if (!SiteDesc.Items[0].VegFormation.IsEmpty()) {
		 if (!SitePtr->SiteDescription.IsEmpty())
		   SitePtr->SiteDescription += L" ";
		 SitePtr->SiteDescription += L"Vegetation formation: " + MakeSentence(SiteDesc.Items[0].VegFormation);
		 }
	   }
	 }

   DATASET& Dataset = Datasets[0];
   Dataset.DatasetType = L"Pollen";
   ProfGrid1->Cells[1][1]->Value = L"Pollen";
   Dataset.Name = L"EPD E# " + IntToStr(EPDENr);
   Edit15->Enabled = false;

   // get entity/collection unit metadata
   EPDGetEntity Entity(ipsJSONS1, TcpClient1);
   Entity.AddParam(L"ENTITYNR", EPDENr);
   XMLParsingStatus(Entity.WebServiceName());
   if (Entity.Execute()) {
	 if (Entity.Size() == 1) {
	   COLLECTION& coll = SitePtr->CollUnits[0];
	   coll.Handle = Entity.Items[0].Sigle;
	   coll.CollectionName = Entity.Items[0].Name;
	   if (Entity.Items[0].IsCore)
		 coll.CollectionType = L"Core";
	   else if (Entity.Items[0].IsSect)
		 coll.CollectionType = L"Section";
	   Dataset.IsSSamp = Entity.Items[0].IsSSamp;
	   coll.DepEnv = Entity.Items[0].DepEnvt;
	   coll.Location = Entity.Items[0].EntLoc;
	   if (!Entity.Items[0].LocalVeg.IsEmpty())
		 coll.Notes = L"Local vegetation: " + MakeSentence(Entity.Items[0].LocalVeg);
	   if (!Entity.Items[0].SampDate.IsEmpty())
	     coll.CollDate = Entity.Items[0].SampDate;
	   if (!Entity.Items[0].DepthAtLoc.IsEmpty()) {
		 double depth = Entity.Items[0].DepthAtLoc;
		 if (depth > 30) {
		   msg = L"Water depth " + FloatToStr(depth);
		   depth /= 100;
		   msg += (L" converted to " + FloatToStr(depth) + L".");
		   coll.WaterDepth = depth;
		   }
		 else {
		   msg = L"Water depth " + FloatToStr(depth) + L" not converted.";
		   coll.WaterDepth = depth;
		   }
         MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
		 }

	   coll.CollectionDevice = Entity.Items[0].SampDevice;
	   if (!Entity.Items[0].CoreDiamCM.IsEmpty()) {
		 if (!coll.CollectionDevice.IsEmpty())
		   coll.CollectionDevice += L" ";
		 double diam = Entity.Items[0].CoreDiamCM;
		 coll.CollectionDevice += (FloatToStr(diam) + L" cm diameter.");
		 }
	   if (!Entity.Items[0].Notes.IsEmpty()) {
		 if (!coll.Notes.IsEmpty())
		   coll.Notes += L" ";
		 coll.Notes += MakeSentence(Entity.Items[0].Notes);
		 }
	   if (!Entity.Items[0].CollNr.IsEmpty()) {
		 int WorkerNr = Entity.Items[0].CollNr;
		 EPDWorker(WorkerNr, Workers);
		 if (Workers.count(WorkerNr) > 0)
		   coll.Collectors.push_back(Workers[WorkerNr]);
		 }
	   }
	 }

   if (EPDENr <= 722) {   // old set, get IDs
	 UnicodeString Sigle = SitePtr->CollUnits[0].Handle;
	 EPDGetNeotomaSiteCollUnitIDs SiteColl(ipsJSONS1, TcpClient1);
	 SiteColl.AddParam(L"SIGLE", Sigle);
	 XMLParsingStatus(SiteColl.WebServiceName());
	 if (SiteColl.Execute()) {
	   EPD.SiteID = SiteColl.Items[0].first;
	   EPD.CollectionUnitID = SiteColl.Items[0].second;
	   }
	 if (EPD.SiteID == -1 || EPD.CollectionUnitID == -1) {
	   msg = L"Error retrieving Neotoma SiteID or CollectionUnitID for EPD Sigle «" +
			 Sigle + L"». Download aborted.";
	   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return;
	   }
	 else {
	   SitePtr->NeotomaSiteID = EPD.SiteID;
	   SitePtr->CollUnits[0].NeotomaCollUnitID = EPD.CollectionUnitID;
	   }

	 EPDGetNeotomaDatasetIDs DatasetIDs(ipsJSONS1, TcpClient1);
	 DatasetIDs.AddParam(L"SIGLE", Sigle);
	 XMLParsingStatus(DatasetIDs.WebServiceName());
	 if (DatasetIDs.Execute())
	   EPD.Datasets = DatasetIDs.Items;
	 if (DatasetIDs.Size() == 0) {
	   msg = L"No datasets in Neotoma for EPD Sigle «" + Sigle + L"». Download aborted.";
	   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   return;
	   }
	 else {
	   msg = L"Metadata for EPD Sigle «" + Sigle + L"» found in Neotoma. SiteID = " +
			 IntToStr(EPD.SiteID) + L". CollectionUnitID = " + IntToStr(EPD.CollectionUnitID) +
			 L". DatasetIDs = ";
	   map<int,int>::iterator itr;
	   for (itr = EPD.Datasets.begin(); itr != EPD.Datasets.end(); itr++) {
		 if (itr != EPD.Datasets.begin())
		   msg += L",";
		 msg += (L"(" + IntToStr(itr->first) + L":" + IntToStr(itr->second) + L")");
		 }
	   MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
	   }
	 }

   // get p_entity dataset data
   EPDGetPEntity PEntity(ipsJSONS1, TcpClient1);
   PEntity.AddParam(L"ENTITYNR", EPDENr);
   XMLParsingStatus(PEntity.WebServiceName());
   if (PEntity.Execute()) {
	 if (PEntity.Size() == 1) {
	   int ContactNr = PEntity.Items[0].ContactNr;
	   EPDWorker(ContactNr, Workers);
	   if (Workers.count(ContactNr) > 0)
		 Datasets[0].Investigators.push_back(Workers[ContactNr]);
	   if (!PEntity.Items[0].DataSource.IsEmpty())
		 Datasets[0].Notes = L"Data contributed by " + PEntity.Items[0].DataSource;
	   if (*Datasets[0].Notes.LastChar() != L'.')
		 Datasets[0].Notes += L".";
	   }
	 }

   // get publications

   EPDGetPublEnt Publ(ipsJSONS1, TcpClient1);
   Publ.AddParam(L"ENTITYNR", EPDENr);
   XMLParsingStatus(Publ.WebServiceName());
   if (Publ.Execute()) {
	 if (Publ.Size() > 0) {
	   for (unsigned int i = 0; i < Publ.Size(); i++) {
		 PUBLICATION* pub = new PUBLICATION(OTHER_AUTHORED);
		 EPDPublToPub(Publ.Items[i], pub, Workers);
		 Pubs[Publ.Items[i].PublNr] = pub;
		 pub->PublicationYear = Publ.Items[i].YearOfPubl;
		 pub->Title = Publ.Items[i].Citation;
		 Publications->Add(pub);
		 Datasets[0].Publications.push_back(pub);
		 }
	   Publications->Sort(CitationCompare);
	   }
	 }
   else {
	 msg = L"Error executing service EPD_GetPublEnt.";
	 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 }

   // get geochron

   map<int,GEOCHRON> Dates;  // SampleNr, GEOCHRON
   set<UnicodeString> Methods;
   EPDGetGeochron Geochron(ipsJSONS1, TcpClient1);
   Geochron.AddParam(L"ENTITYNR", EPDENr);
   XMLParsingStatus(Geochron.WebServiceName());
   if (Geochron.Execute()) {
	 if (Geochron.Size() > 0) {
	   for (unsigned int i=0; i < Geochron.Size(); i++) {
		 GEOCHRON date;
		 int SampleNr = Geochron.Items[i].SampleNr;
		 date.Method = Geochron.Items[i].Method;
		 if (Methods.count(date.Method) == 0)
		   Methods.insert(date.Method);
		 date.Depth = Geochron.Items[i].DepthCM;
		 if (!Geochron.Items[i].Thickness.IsEmpty())
		   date.Thickness = Geochron.Items[i].Thickness;
		 if (!Geochron.Items[i].MaterialDated.IsEmpty())
		   date.MaterialDated = Geochron.Items[i].MaterialDated;
		 if (!Geochron.Items[i].PublNr.IsEmpty()) {
		   int PublNr = Geochron.Items[i].PublNr;
		   if (Pubs.count(PublNr) > 0)
			 date.publications.push_back(Pubs[PublNr]);
		   else {
			 EPDGetPubl Publ(ipsJSONS1, TcpClient1);
			 Publ.AddParam(L"PUBLNR", PublNr);
			 XMLParsingStatus(Publ.WebServiceName());
			 if (Publ.Execute()) {
			   if (Publ.Size() == 1) {
				 PUBLICATION* pub = new PUBLICATION(OTHER);
				 EPDPublToPub(Publ.Items[0], pub, Workers);
				 Pubs[PublNr] = pub;
				 Publications->Add(pub);
				 date.publications.push_back(pub);
				 }
			   }
			 }
		   }
		 Dates[SampleNr] = date;
		 }

	   // get specific date-method data
	   if (Methods.count(L"Carbon-14") > 0) {
		 EPDGetC14 C14(ipsJSONS1, TcpClient1);
		 C14.AddParam(L"ENTITYNR", EPDENr);
		 XMLParsingStatus(C14.WebServiceName());
		 if (C14.Execute()) {
		   if (C14.Size() > 0) {
			 map<int,EPDC14>::iterator itr;
			 for (itr = C14.Items.begin(); itr != C14.Items.end(); itr++) {
			   int SampleNr = itr->first;
			   EPDC14& C14 = itr->second;
			   GEOCHRON& Date = Dates[SampleNr];
			   Date.AgeUnits = L"Radiocarbon years BP";
			   if (!C14.AgeBP.IsEmpty())
				 Date.Age = C14.AgeBP;
			   if (!C14.AgeSDUp.IsEmpty())
				 Date.ErrorOlder = C14.AgeSDUp;
			   if (!C14.AgeSDLo.IsEmpty())
				 Date.ErrorYounger = C14.AgeSDLo;
			   if (!C14.AgeSDUp.IsEmpty() && !C14.AgeSDLo.IsEmpty() && Date.ErrorOlder == Date.ErrorYounger)
				 Date.StdDev = Date.ErrorOlder;
			   Date.GreaterThan = C14.GrThanAge;
			   Date.LabNumber = C14.LabNumber;
			   if (!C14.Basis.IsEmpty())
				 Date.Parameters[L"Method"] = C14.Basis;
			   if (!C14.DeltaC13.IsEmpty())
				 Date.Parameters[L"δ13C"] = C14.DeltaC13;
			   Date.Notes = C14.Notes;
			   }
			 }
		   }
		 else {
		   msg = L"Error executing service EPD_GetC14.";
		   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   }
		 }

	   if (Methods.count(L"Lead-210") > 0) {
		 EPDGetPb210 Pb210(ipsJSONS1, TcpClient1);
		 Pb210.AddParam(L"ENTITYNR", EPDENr);
		 XMLParsingStatus(Pb210.WebServiceName());
		 if (Pb210.Execute()) {
		   if (Pb210.Size() > 0) {
			 map<int,EPDPB210>::iterator itr;
			 for (itr = Pb210.Items.begin(); itr != Pb210.Items.end(); itr++) {
			   int SampleNr = itr->first;
			   EPDPB210& PB210 = itr->second;
			   GEOCHRON& Date = Dates[SampleNr];
			   Date.AgeUnits = L"Calendar years AD/BC";
			   if (!PB210.AgeAD.IsEmpty())
				 Date.Age = PB210.AgeAD;
			   if (!PB210.AgeSE.IsEmpty()) {
				 Date.ErrorOlder = PB210.AgeSE;
				 Date.ErrorYounger = PB210.AgeSE;
				 if (Date.ErrorOlder == Date.ErrorYounger)
				   Date.StdDev = Date.ErrorOlder;
				 }
			   Date.GreaterThan = PB210.GrThanAge;
			   Date.Notes = PB210.Notes;
			   }
			 }
		   }
		 else {
		   msg = L"Error executing service EPD_GetPb210.";
		   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   }
		 }

	   if (Methods.count(L"Thermoluminescence") > 0) {
		 EPDGetTL TL(ipsJSONS1, TcpClient1);
		 TL.AddParam(L"ENTITYNR", EPDENr);
		 XMLParsingStatus(TL.WebServiceName());
		 if (TL.Execute()) {
		   if (TL.Size() > 0) {
			 map<int,EPDTL>::iterator itr;
			 for (itr = TL.Items.begin(); itr != TL.Items.end(); itr++) {
			   int SampleNr = itr->first;
			   EPDTL TL = itr->second;
			   GEOCHRON& Date = Dates[SampleNr];
			   Date.AgeUnits = L"Calendar years BP";
			   if (!TL.AgeBP.IsEmpty())
				 Date.Age = TL.AgeBP;
			   if (!TL.ErrorLimits.IsEmpty()) {
				 Date.ErrorOlder = TL.ErrorLimits;
				 Date.ErrorYounger = TL.ErrorLimits;
				 if (Date.ErrorOlder == Date.ErrorYounger)
				   Date.StdDev = Date.ErrorOlder;
				 }
			   Date.LabNumber = TL.LabNumber;
			   if (!TL.GrainSize.IsEmpty()) {
				 if (!Date.MaterialDated.IsEmpty()) {
				   if (*Date.MaterialDated.LastChar() != L'.')
					 Date.MaterialDated += L".";
				   Date.MaterialDated += L" ";
				   }
				 Date.MaterialDated += (L"Grain size: " + TL.GrainSize);
				 }
			   Date.Notes = TL.Notes;
			   }
			 }
		   }
		 else {
		   msg = L"Error executing service EPD_GetTL.";
		   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   }
		 }

	   if (Methods.count(L"Uranium series") > 0) {
		 EPDGetUSeries USeries(ipsJSONS1, TcpClient1);
		 USeries.AddParam(L"ENTITYNR", EPDENr);
		 XMLParsingStatus(USeries.WebServiceName());
		 if (USeries.Execute()) {
		   if (USeries.Size() > 0) {
			 map<int,EPDUSERIES>::iterator itr;
			 for (itr = USeries.Items.begin(); itr != USeries.Items.end(); itr++) {
			   int SampleNr = itr->first;
			   EPDUSERIES US = itr->second;
			   GEOCHRON& Date = Dates[SampleNr];
			   Date.AgeUnits = L"Calendar years BP";
			   if (!US.AgeBP.IsEmpty())
				 Date.Age = US.AgeBP;
			   if (!US.ErrorLimits.IsEmpty()) {
				 Date.ErrorOlder = US.ErrorLimits;
				 Date.ErrorYounger = US.ErrorLimits;
				 if (Date.ErrorOlder == Date.ErrorYounger)
				   Date.StdDev = Date.ErrorOlder;
				 }
			   Date.LabNumber = US.LabNumber;
			   Date.Notes = US.Notes;
			   }
			 }
		   }
		 else {
		   msg = L"Error executing service EPD_GetUSeries.";
		   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   }
		 }

	   map<int,GEOCHRON>::iterator itr;
	   for (itr = Dates.begin(); itr != Dates.end(); itr++) {
		 UnicodeString PubComboBoxText;
		 for (unsigned int k=0; k<itr->second.publications.size(); k++) {
		   if (k > 0) PubComboBoxText += L";";
			 PubComboBoxText += getPubShortDescription(itr->second.publications[k]);
		   }
		 itr->second.PubComboBoxText = PubComboBoxText;
		 GeochronList->Add(itr->second);
		 }
	   GeochronDataSource->DataChanged();

	   // geochron investigators
	   GeochronDataset.Investigators = Datasets[0].Investigators;
	   }
	 }
   else {
	 msg = L"Error executing service EPD_GetGeochron.";
	 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 }

   // get chronologies

   map<UnicodeString,UnicodeString> RCode;
   RCode[L"AAR"] = L"Argon-argon";
   RCode[L"ANL"] = L"Annual laminations (varves)";
   RCode[L"ATL"] = L"Boreal/Atlantic";
   RCode[L"BOT"] = L"Core bottom";
   RCode[L"C13"] = L"Radiocarbon";
   RCode[L"C14"] = L"Radiocarbon";
   RCode[L"CAJ"] = L"Radiocarbon, reservoir correction";
   RCode[L"CAL"] = L"Radiocarbon, calibrated";
   RCode[L"CAV"] = L"Radiocarbon, average of two or more dates";
   RCode[L"CGT"] = L"Radiocarbon, infinite";
   RCode[L"CSM"] = L"Caesium-137: atmospheric nuclear bomb tests";
   RCode[L"DEN"] = L"Radiocarbon, calibrated";
   RCode[L"EXT"] = L"Extrapolated";
   RCode[L"FIR"] = L"Firbas pollen-zone boundary";
   RCode[L"GUE"] = L"Guess";
   RCode[L"H&W"] = L"Heeb & Welten (1972) pollen boundary";
   RCode[L"HOL"] = L"Pleistocene/Holocene";
   RCode[L"INT"] = L"Interpolated";
   RCode[L"LOW"] = L"ALPADABA pollen boundary";
   RCode[L"LST"] = L"Laacher See";
   RCode[L"MAG"] = L"Palaeomagnetic";
   RCode[L"O18"] = L"Oxygen-18";
   RCode[L"OSL"] = L"Optically stimulated luminescence";
   RCode[L"OTH"] = L"Other dating methods";
   RCode[L"PB2"] = L"Lead-210";
   RCode[L"POL"] = L"Biostratigraphic, pollen";
   RCode[L"RCY"] = L"Radiocarbon, calibrated from calendar years";
   RCode[L"SED"] = L"Sediment stratigraphic";
   RCode[L"TEF"] = L"Tephra";
   RCode[L"THL"] = L"Thermoluminescence";
   RCode[L"TOP"] = L"Core top";
   RCode[L"USE"] = L"Uranium-series";
   RCode[L"WEL"] = L"Welten (1982) pollen boundary";
   RCode[L"WOK"] = L"W.O. van der Knaap pollen boundary";
   // new Giesecke et al. codes
   RCode[L"AL"] = L"Older Dryas/Allerød";
   RCode[L"AMR"] = L"Ambrosia rise";
   RCode[L"BOL"] = L"Oldest Dryas/Bølling";
   RCode[L"HIS"] = L"Historical documentation";
   RCode[L"HOL_A"] = L"Pleistocene/Holocene, locally defined";
   RCode[L"HOL_B"] = L"	Pleistocene/Holocene, regionally defined, well constrained";
   RCode[L"HOL_C"] = L"Pleistocene/Holocene, regionally defined, poorly constrained";
   RCode[L"POL_A"] = L"Biostratigraphic, pollen, local";
   RCode[L"POL_B"] = L"Biostratigraphic, pollen, regional";
   RCode[L"YDO"] = L"Allerød/Younger Dryas";
   RCode[L"TOP_A"] = L"Core top, year of sampling";
   RCode[L"TOP_B"] = L"Core top, not year of sampling";
   RCode[L"TOP_C"] = L"Core top, estimated";

   EPDGetChron Chron(ipsJSONS1, TcpClient1);
   Chron.AddParam(L"ENTITYNR", EPDENr);
   XMLParsingStatus(Chron.WebServiceName());
   if (Chron.Execute()) {
	 if (Chron.Size() > 0) {
	   for (unsigned int i = 0; i < Chron.Size(); i++) {
		 AGEMODEL* agemodel = new AGEMODEL();
		 agemodel->ChronNumber = Chron.Items[i].ChronNr;
		 ChronNr.insert(agemodel->ChronNumber);
		 agemodel->Default = Chron.Items[i].Default;
		 agemodel->ChronologyName = Chron.Items[i].Name;
		 if (!Chron.Items[i].WorkerNr.IsEmpty()) {
		   int WorkerNr = Chron.Items[i].WorkerNr;
		   EPDWorker(WorkerNr, Workers);
		   if (Workers.count(WorkerNr) > 0) {
			 agemodel->Preparers.push_back(Workers[WorkerNr]);
			 agemodel->PreparersComboBoxText = Workers[WorkerNr]->ShortContactName;
			 }
		   }
		 else {
		   if (!Chron.Items[i].NeotomaContactID.IsEmpty()) {
			 int NeotomaContactID = Chron.Items[i].NeotomaContactID;
			 NeotomaContactByID NeotomaContact(ipsJSONS1, TcpClient1);
			 NeotomaContact.AddParam(L"CONTACTID", NeotomaContactID);
			 XMLParsingStatus(NeotomaContact.WebServiceName());
			 if (NeotomaContact.Execute()) {
			   if (NeotomaContact.Size() > 0) {
				 CONTACT* Contact = new CONTACT();
				 Contact->FamilyName = NeotomaContact.Items[0].FamilyName;
				 Contact->GivenNames = NeotomaContact.Items[0].GivenNames;
				 Contact->LeadingInitials = NeotomaContact.Items[0].LeadingInitials;
				 Contact->Suffix = NeotomaContact.Items[0].Suffix;
				 Contact->Title = NeotomaContact.Items[0].Title;
				 Contact->Telephone = NeotomaContact.Items[0].Phone;
				 Contact->Fax = NeotomaContact.Items[0].Fax;
				 Contact->Email = NeotomaContact.Items[0].Email;
				 Contact->Address = NeotomaContact.Items[0].Address;
				 Contact->URL = NeotomaContact.Items[0].URL;
				 Contact->FormatContactName();
				 ContactList->Add(Contact);
				 agemodel->Preparers.push_back(Contact);
				 agemodel->PreparersComboBoxText = Contact->ShortContactName;
				 }
			   }
			 else {
			   msg = L"Error executing service GetContactByID.";
			   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
			   }
			 }
		   }
		 if (!Chron.Items[i].DatePrepared.IsEmpty())
		   agemodel->DatePrepared = Chron.Items[i].DatePrepared;
		 agemodel->AgeModel = Chron.Items[i].Model;
		 agemodel->Notes = Chron.Items[i].Notes;
		 if (!Chron.Items[i].Top.IsEmpty())
		   agemodel->AgeBoundYounger = Chron.Items[i].Top;
		 if (!Chron.Items[i].Bottom.IsEmpty())
		   agemodel->AgeBoundOlder = Chron.Items[i].Bottom;
		 if (ContainsText(agemodel->AgeModel, L"Bacon"))
		   agemodel->AgeUnits = L"Calibrated radiocarbon years BP";
		 else if (ContainsText(agemodel->Notes, L"clam"))
		   agemodel->AgeUnits = L"Calibrated radiocarbon years BP";
		 else
		   agemodel->AgeUnits = L"Radiocarbon years BP";

		 bool calibrated = false;
		 EPDGetAgeBasis AgeBasis(ipsJSONS1, TcpClient1);
		 AgeBasis.AddParam(L"ENTITYNR", EPDENr);
		 AgeBasis.AddParam(L"CHRONNR", agemodel->ChronNumber);
		 XMLParsingStatus(AgeBasis.WebServiceName());
		 if (AgeBasis.Execute()) {
		   if (AgeBasis.Size() > 0) {
			 for (unsigned int i = 0; i < AgeBasis.Size(); i++) {
			   CHRON* chron = new CHRON();
			   chron->Depth = AgeBasis.Items[i].DepthCM;
			   if (!AgeBasis.Items[i].Thickness.IsEmpty())
				 chron->Thickness = AgeBasis.Items[i].Thickness;
			   if (!AgeBasis.Items[i].Age.IsEmpty())
				 chron->AgeValue = AgeBasis.Items[i].Age;
			   if (!AgeBasis.Items[i].AgeUp.IsEmpty())
				 chron->AgeLimitOlder = AgeBasis.Items[i].AgeUp;
			   if (!AgeBasis.Items[i].AgeLo.IsEmpty())
				 chron->AgeLimitYounger = AgeBasis.Items[i].AgeLo;
			   chron->ControlType =  RCode[AgeBasis.Items[i].RCode];
			   if (SameText(chron->ControlType, L"Radiocarbon, calibrated"))
				 calibrated = true;
			   agemodel->ChronControls->Add(chron);
			   }
			 }
		   }
		 else {
		   msg = L"Error executing service EPD_GetAgeBasis.";
		   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		   }
		 if (calibrated)
		   agemodel->AgeUnits = L"Calibrated radiocarbon years BP";
		 AgeModelList->Add(agemodel);
		 }
	   }
	 AgeModelDataSource->DataChanged();
	 }
   else {
	 msg = L"Error executing service EPD_GetChron.";
	 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 }

   // get synevents

   EPDGetSynEvent SynEvent(ipsJSONS1, TcpClient1);
   SynEvent.AddParam(L"ENTITYNR", EPDENr);
   XMLParsingStatus(SynEvent.WebServiceName());
   if (SynEvent.Execute()) {
	 if (SynEvent.Size() > 0) {
	   for (unsigned int i = 0; i < SynEvent.Size(); i++) {
		 for (int j = 0; j < AgeModelList->Count; j++) {
		   AGEMODEL* AgeModel = AgeModelList->AgeModels[j];
		   CHRON* chron = new CHRON();
		   chron->Depth = SynEvent.Items[i].DepthCM;
		   if (!SynEvent.Items[i].Thickness.IsEmpty())
			 chron->Thickness = SynEvent.Items[i].Thickness;
		   if (!SynEvent.Items[i].AgeBP.IsEmpty())
			 chron->AgeValue = SynEvent.Items[i].AgeBP;
		   if (!SynEvent.Items[i].AgeUncertUp.IsEmpty())
			 chron->AgeLimitOlder = SynEvent.Items[i].AgeUncertUp;
		   if (!SynEvent.Items[i].AgeUncertLo.IsEmpty())
			 chron->AgeLimitYounger = SynEvent.Items[i].AgeUncertLo;
		   chron->ControlType = SynEvent.Items[i].Name;
		   AgeModel->ChronControls->Add(chron);
		   msg = L"SynEvent «" + SynEvent.Items[i].Name + L"» added to Chron" + IntToStr(AgeModel->ChronNumber) + L".";
		   MessageDlg(msg, mtInformation, TMsgDlgButtons() << mbOK, 0);
		   }
		 }
	   AgeModelDataSource->DataChanged();
	   }
	 }
   else {
	 msg = L"Error executing service EPD_GetSynEvent.";
	 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 }

   // get MADCAP age model if it exists

   int clamModelType = -1;
   bool madcap = false;

   EPDGetMADCAPAgeModel MADCAP(ipsJSONS1, TcpClient1);
   MADCAP.AddParam(L"SIGLE", SitePtr->CollUnits[0].Handle);
   XMLParsingStatus(MADCAP.WebServiceName());
   if (MADCAP.Execute()) {
	 if (MADCAP.Size() > 0) {
	   madcap = true;
	   clamModelType = MADCAP.Items[0];
	   }
	 }
   else {
	 msg = L"Error executing service EPD_GetMADCAPAgeModel.";
	 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 }

   if (madcap) {
	 ShowMessage(L"MADCAP age model exists.");
	 EPDGetMADCAPChronControls MADCAPChronControls(ipsJSONS1, TcpClient1);
	 MADCAPChronControls.AddParam(L"SIGLE", SitePtr->CollUnits[0].Handle);
	 XMLParsingStatus(MADCAPChronControls.WebServiceName());
	 if (MADCAPChronControls.Execute()) {
	   if (MADCAPChronControls.Size() > 0) {
         AGEMODEL* agemodel = new AGEMODEL();
		 for (int i=0; i<AgeModelList->Count; i++) {
		   AGEMODEL* AgeModel = AgeModelList->AgeModels[i];
		   if (AgeModel->ChronNumber >= MADCAPChronNr)
			 MADCAPChronNr = AgeModel->ChronNumber + 1;
		   }
		 agemodel->ChronNumber = MADCAPChronNr;
		 agemodel->Default = true;
		 agemodel->ChronologyName = L"Giesecke et al. 2014 (MADCAP)";
		 agemodel->DatePrepared = TDateTime(2011,1,1);
		 agemodel->AgeModel = L"clam";
		 agemodel->AgeUnits = L"Calibrated radiocarbon years BP";
		 switch (clamModelType) {
		   case 1:
			 agemodel->Notes = L"Linear age model. ";
			 break;
		   case 2:
			 agemodel->Notes = L"Smooth spline age model. ";
			 break;
		   }
		 agemodel->Notes += L"Based on IntCal09 calibration curve.";

		 EPDGetMADCAPContactNotes MADCAPContactNotes(ipsJSONS1, TcpClient1);
		 MADCAPContactNotes.AddParam(L"SIGLE", SitePtr->CollUnits[0].Handle);
		 XMLParsingStatus(MADCAPContactNotes.WebServiceName());
		 if (MADCAPContactNotes.Execute()) {
		   if (MADCAPContactNotes.Size() > 0) {
			 int WorkerNr = MADCAPContactNotes.Items[0].first;
			 EPDWorker(WorkerNr, Workers);
			 if (Workers.count(WorkerNr) > 0) {
			   agemodel->Preparers.push_back(Workers[WorkerNr]);
			   agemodel->PreparersComboBoxText = Workers[WorkerNr]->ShortContactName;
			   }
			 UnicodeString Notes = MADCAPContactNotes.Items[0].second;
			 if (!Notes.IsEmpty()) {
			   UnicodeString FirstLetter = Notes.SubString(1,1).UpperCase();
			   Notes.Delete(1,1);
			   Notes.Insert(FirstLetter,1);
			   agemodel->Notes += (L" Preparer notes: " + Notes);
			   }
			 }
		   }
		 else {
		   msg = L"Error executing service EPD_GetMADCAPContactNotes.";
		   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		  }

		 EPDGetMADCAPReliableAges MADCAPReliableAges(ipsJSONS1, TcpClient1);
		 MADCAPReliableAges.AddParam(L"SIGLE", SitePtr->CollUnits[0].Handle);
		 XMLParsingStatus(MADCAPReliableAges.WebServiceName());
		 if (MADCAPReliableAges.Execute()) {
		   if (MADCAPReliableAges.Size() > 0) {
             double value;
			 double rounded;
			 if (!MADCAPReliableAges.Items[0].first.IsEmpty()) {
			   value = MADCAPReliableAges.Items[0].first;
			   rounded = RoundTo(value,1);
			   if (rounded > value)
				 rounded -= 10;
			   agemodel->AgeBoundYounger = rounded;
			   }
			 if (!MADCAPReliableAges.Items[0].second.IsEmpty()) {
			   value = MADCAPReliableAges.Items[0].second;
			   rounded = RoundTo(value,1);
			   if (rounded < value)
				 rounded += 10;
			   agemodel->AgeBoundOlder = rounded;
			   }
			 }
		   }
		 else {
		   msg = L"Error executing service EPD_GetMADCAPReliableAges.";
		   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
		  }

		 for (unsigned int i=0; i<MADCAPChronControls.Size(); i++) {
           CHRON* chron = new CHRON();
		   chron->Depth = MADCAPChronControls.Items[i].DepthCM;
		   if (!MADCAPChronControls.Items[i].Thickness.IsEmpty())
			 chron->Thickness = MADCAPChronControls.Items[i].Thickness;

		   if (!MADCAPChronControls.Items[i].Age14C.IsEmpty()) {
			 chron->AgeValue = MADCAPChronControls.Items[i].Age14C;
			 chron->AgeUnits = L"Radiocarbon";
			 }
		   else if (!MADCAPChronControls.Items[i].AgeCal.IsEmpty()) {
			 chron->AgeValue = MADCAPChronControls.Items[i].AgeCal;
			 chron->AgeUnits = L"Calendar";
			 }
		   if (!MADCAPChronControls.Items[i].SD.IsEmpty()) {
			 chron->AgeLimitOlder = MADCAPChronControls.Items[i].Age14C + MADCAPChronControls.Items[i].SD;
			 chron->AgeLimitYounger = MADCAPChronControls.Items[i].Age14C - MADCAPChronControls.Items[i].SD;
			 }
		   if (RCode.count(MADCAPChronControls.Items[i].RCode) == 1)
			 chron->ControlType =  RCode[MADCAPChronControls.Items[i].RCode];
		   else {
			 msg = L"MADCAP RCode «" + MADCAPChronControls.Items[i].RCode + L"» not found!";
			 MessageDlg(msg, mtWarning, TMsgDlgButtons() << mbOK, 0);
			 }
		   // chron->CalibCurve = L"IntCal98";
		   agemodel->ChronControls->Add(chron);
		   }
		 AgeModelList->Add(agemodel);
		 }
	   }
	 else {
	   msg = L"Error executing service EPD_GetMADCAPChronControls.";
	   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   }
	 }

   // get samples

   ProfGrid1->DisableControls();
   ProfGrid1->SpreadsheetEnabled = false;
   int row = 3;
   EPDGetPSample Sample(ipsJSONS1, TcpClient1);
   Sample.AddParam(L"ENTITYNR", EPDENr);
   XMLParsingStatus(Sample.WebServiceName());
   if (Sample.Execute()) {
	 if (Sample.Size() > 0) {
	   int size = Sample.Size();
	   if (size > ProfGrid1->ColCount-8) {
		 int ColCount = ProfGrid1->ColCount;
		 while (ColCount < size+8)
		   ColCount += 256;
         ProfGrid1->ColCount = ColCount;
	     }
	   for (unsigned int i=0, col=8; i < Sample.Size(); i++, col++) {
		 ProfGrid1->AbsoluteCells[col][1]->Value = Sample.Items[i].DepthCM;
		 Samples[Sample.Items[i].SampleNr] = col;
		 }
	   // #Anal.Thick	Analysis Unit Thickness
	   bool found = false;
	   for (unsigned int i=0; i < Sample.Size(); i++) {
		 if (!Sample.Items[i].Thickness.IsEmpty()) {
		   found = true;
		   break;
		   }
		 }
	   if (found) {
		 ProfGrid1->AbsoluteCells[1][row]->Value = WideString("#Anal.Thick");
		 ProfGrid1->AbsoluteCells[2][row]->Value = WideString("Analysis Unit Thickness");
		 for (unsigned int i=0, col=8; i < Sample.Size(); i++, col++) {
		   if (!Sample.Items[i].Thickness.IsEmpty())
			 ProfGrid1->AbsoluteCells[col][row]->Value = Sample.Items[i].Thickness;
		   }
		 row++;
		 }

	   // #Samp.Analyst	Sample Analyst
	   found = false;
	   for (unsigned int i=0; i < Sample.Size(); i++) {
		 if (!Sample.Items[i].AnalystNr.IsEmpty()) {
		   found = true;
		   break;
		   }
		 }
	   if (found) {
		 ProfGrid1->AbsoluteCells[1][row]->Value = WideString("#Samp.Analyst");
		 ProfGrid1->AbsoluteCells[2][row]->Value = WideString("Sample Analyst");
		 for (unsigned int i=0, col=8; i < Sample.Size(); i++, col++) {
		   if (!Sample.Items[i].AnalystNr.IsEmpty()) {
			 int AnalystNr = Sample.Items[i].AnalystNr;
			 EPDWorker(AnalystNr, Workers);
			 if (Workers.count(AnalystNr) > 0) {
			   TProfGridCell *ACell = ProfGrid1->AbsoluteCells[col][row];
			   CELLOBJECT* CellObject = new CELLOBJECT(CELLCONTACTS);
			   AddCellObject(ACell, CellObject);
			   TList* Contacts = (TList*)CellObject->Object;
			   Contacts->Add(Workers[AnalystNr]);
			   ACell->Value = Workers[AnalystNr]->ShortContactName;
			   }
			 }
		   }
		 row++;
		 }

	   // #Samp.DateAnal	Date Analyzed
	   found = false;
	   for (unsigned int i=0; i < Sample.Size(); i++) {
		 if (EPDDecodeDateStr(Sample.Items[i].AnalyDate, Date)) {
		   found = true;
		   break;
		   }
		 }
	   if (found) {
		 ProfGrid1->AbsoluteCells[1][row]->Value = WideString("#Samp.DateAnal");
		 ProfGrid1->AbsoluteCells[2][row]->Value = WideString("Date Analyzed");
		 for (unsigned int i=0, col=8; i < Sample.Size(); i++, col++) {
		   if (EPDDecodeDateStr(Sample.Items[i].AnalyDate, Date))
			 ProfGrid1->AbsoluteCells[col][row]->Value = Date;
		   }
		 row++;
		 }

	   // #Samp.Notes	Sample Notes
	   // #Samp.Method	Preparation Method
	   TStringList* Lines = new TStringList();
	   for (unsigned int i=0; i < Sample.Size(); i++) {
		 if (!Sample.Items[i].Notes.IsEmpty())
		   Lines->Add(Sample.Items[i].Notes);
		 }
	   if (Lines->Count > 0) {
		 EPDNotesPrepForm = new TEPDNotesPrepForm(L"Sample Notes or Prep?", Lines->Text,
			 MemoFormOptions() << mfoBlankButton, this);
		 EPDNotesPrepForm->ShowModal();
		 int CommentType = EPDNotesPrepForm->CommentType;
		 delete EPDNotesPrepForm;
		 switch (CommentType) {
		   case 1:  // Sample Notes
			 ProfGrid1->AbsoluteCells[1][row]->Value = WideString("#Samp.Notes");
			 ProfGrid1->AbsoluteCells[2][row]->Value = WideString("Sample Notes");
			 break;
		   case 2:  // Preparation Method
			 ProfGrid1->AbsoluteCells[1][row]->Value = WideString("#Samp.Method");
			 ProfGrid1->AbsoluteCells[2][row]->Value = WideString("Preparation Method");
			 break;
		   }
		 for (unsigned int i=0, col=8; i < Sample.Size(); i++, col++) {
		   if (!Sample.Items[i].Notes.IsEmpty())
			 ProfGrid1->AbsoluteCells[col][row]->Value = WideString(Sample.Items[i].Notes);
		   }
		 row++;
		 }
	   delete Lines;
	   }
	 }
   else {
	 msg = L"Error executing service EPD_GetPSample.";
	 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 }

   // get non-MADCAP sample ages

   for (set<int>::iterator itr = ChronNr.begin(); itr != ChronNr.end(); itr++) {
	 EPDGetPAgeDpt PAgeDpt(ipsJSONS1, TcpClient1);
	 PAgeDpt.AddParam(L"ENTITYNR", EPDENr);
	 PAgeDpt.AddParam(L"CHRONNR", *itr);
	 XMLParsingStatus(PAgeDpt.WebServiceName());
	 if (PAgeDpt.Execute()) {
	   if (PAgeDpt.Size() > 0) {
		 int AgeRow = 0;
		 int AgeRowOld = 0;
		 int AgeRowYoung = 0;
		 UnicodeString ChronStr = IntToStr(*itr);
		 map<int,EPDGETPAGEDPT>::iterator it;
		 for (it = PAgeDpt.Items.begin(); it != PAgeDpt.Items.end(); it++) {
		   if (AgeRow == 0 && !it->second.AgeBP.IsEmpty()) {
			 ProfGrid1->AbsoluteCells[1][row]->Value = L"#Chron" + ChronStr;
			 ProfGrid1->AbsoluteCells[2][row]->Value = L"Age (Chron" + ChronStr + L")";
			 AgeRow = row++;
			 }
		   if (AgeRowOld == 0 && !it->second.AgeUp.IsEmpty()) {
			 ProfGrid1->AbsoluteCells[1][row]->Value = L"#Chron" + ChronStr + L".Old";
			 ProfGrid1->AbsoluteCells[2][row]->Value = L"Age (Chron" + ChronStr + L" Older Bound)";
			 AgeRowOld = row++;
			 }
		   if (AgeRowYoung == 0 && !it->second.AgeLo.IsEmpty()) {
			 ProfGrid1->AbsoluteCells[1][row]->Value = L"#Chron" + ChronStr + L".Young";
			 ProfGrid1->AbsoluteCells[2][row]->Value = L"Age (Chron" + ChronStr + L" Younger Bound)";
			 AgeRowYoung = row++;
			 }
		   if (AgeRow > 0 && AgeRowOld > 0 && AgeRowYoung > 0)
			 break;
		   }

		 // map<int,int> Samples;        // Sample#, column
		 map<int,int>::iterator sampitr;
		 for (sampitr = Samples.begin(); sampitr != Samples.end(); sampitr++) {
		   if ((it = PAgeDpt.Items.find(sampitr->first)) != PAgeDpt.Items.end()) {
			 if (!it->second.AgeBP.IsEmpty())
			   ProfGrid1->AbsoluteCells[sampitr->second][AgeRow]->Value = it->second.AgeBP;
			 if (!it->second.AgeUp.IsEmpty())
			   ProfGrid1->AbsoluteCells[sampitr->second][AgeRowOld]->Value = it->second.AgeUp;
			 if (!it->second.AgeLo.IsEmpty())
			   ProfGrid1->AbsoluteCells[sampitr->second][AgeRowYoung]->Value = it->second.AgeLo;
			 }
		   }
		 }
	   }
	 else {
	   msg = L"Error executing service EPD_GetPAgeDpt.";
	   MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	   }
	 }

   // get MADCAP sample ages
   if (madcap) {
	 EPDGetMADCAPSampleAges SampleAges(ipsJSONS1, TcpClient1);
	 SampleAges.AddParam(L"SIGLE", SitePtr->CollUnits[0].Handle);
	 XMLParsingStatus(SampleAges.WebServiceName());
	 if (SampleAges.Execute()) {
	   if (SampleAges.Size() > 0) {
		 UnicodeString ChronStr = IntToStr(MADCAPChronNr);
		 ProfGrid1->AbsoluteCells[1][row]->Value = L"#Chron" + ChronStr;
		 ProfGrid1->AbsoluteCells[2][row]->Value = L"Age (MADCAP)";
		 int AgeRow = row++;

		 ProfGrid1->AbsoluteCells[1][row]->Value = L"#Chron" + ChronStr + L".Old";
		 ProfGrid1->AbsoluteCells[2][row]->Value = L"Age (MADCAP Older Bound)";
		 int AgeRowOld = row++;

		 ProfGrid1->AbsoluteCells[1][row]->Value = L"#Chron" + ChronStr + L".Young";
		 ProfGrid1->AbsoluteCells[2][row]->Value = L"Age (MADCAP Younger Bound)";
		 int AgeRowYoung = row++;

		 map<double,int> SampleDepths;   // depth, col
		 map<int,int>::iterator sampitr;
		 for (sampitr = Samples.begin(); sampitr != Samples.end(); sampitr++) {
		   int col = sampitr->second;
		   double depth = ProfGrid1->AbsoluteCells[col][1]->Value;
		   SampleDepths[depth] = col;
		   }
		 unsigned int nMadCapAges = 0;
		 map<double,MADCAPSAMPLEAGE>::iterator saitr;
		 for (saitr = SampleAges.Items.begin(); saitr != SampleAges.Items.end(); saitr++) {
		   double depth = saitr->first;
		   map<double,int>::iterator depitr = SampleDepths.find(depth);
		   if (depitr != SampleDepths.end()) {
			 int col = depitr->second;
			 ProfGrid1->AbsoluteCells[col][AgeRow]->Value = saitr->second.Age;
			 ProfGrid1->AbsoluteCells[col][AgeRowOld]->Value = saitr->second.AgeMax;
			 ProfGrid1->AbsoluteCells[col][AgeRowYoung]->Value = saitr->second.AgeMin;
			 nMadCapAges++;
			 }
		   else { // see if a depth is within 0.05 cm
			 bool found = false;
			 for (depitr = SampleDepths.begin(); depitr != SampleDepths.end(); depitr++) {
			   if (fabs(depitr->first - depth) < 0.051) {
				 int col = depitr->second;
				 ProfGrid1->AbsoluteCells[col][AgeRow]->Value = saitr->second.Age;
				 ProfGrid1->AbsoluteCells[col][AgeRowOld]->Value = saitr->second.AgeMax;
				 ProfGrid1->AbsoluteCells[col][AgeRowYoung]->Value = saitr->second.AgeMin;
				 found = true;
				 nMadCapAges++;
				 }
			   }
			 if (!found) {
			   msg = L"Depth " + FloatToStr(depth) + L" in MADCAP_AllAges table not in spreadsheet.";
			   MessageDlg(msg, mtWarning, TMsgDlgButtons() << mbOK, 0);
			   }
			 }
		   }
		 /*
		 bool all_found = true;
		 map<double,int>::iterator sditr;
		 for (sditr = SampleDepths.begin(); sditr != SampleDepths.end(); sditr++) {
		   double depth = sditr->first;
		   if (SampleAges.Items.find(depth) == SampleAges.Items.end()) {
			 all_found = false;
			 break;
			 }
		   }
		 */
		 //if (!all_found) {
		 if (SampleDepths.size() > nMadCapAges) {
		   msg = L"Not all sample depths in spreadsheet are in the MADCAP_AllAges table.";
		   MessageDlg(msg, mtWarning, TMsgDlgButtons() << mbOK, 0);
		   }
		 }
	   }
	 }

   // get variables

   //ShowMessage(L"Breakpoint 1");
   EPDGetPVars PVars(ipsJSONS1, TcpClient1);
   PVars.AddParam(L"ENTITYNR", EPDENr);
   XMLParsingStatus(Sample.WebServiceName());
   if (PVars.Execute()) {
	 if (PVars.Size() > 0) {
	   for (unsigned int i=0; i < PVars.Size(); i++) {
		 Vars[PVars.Items[i].VarNr] = row;
		 ProfGrid1->AbsoluteCells[1][row]->Value =  WideString(PVars.Items[i].TaxonCode);
		 ProfGrid1->AbsoluteCells[2][row]->Value = PVars.Items[i].TaxonName;
		 //ShowMessage(PVars.Items[i].TaxonName + L", " + PVars.Items[i].VarName);
		 if (!PVars.Items[i].Element.IsEmpty())
		   ProfGrid1->AbsoluteCells[3][row]->Value = PVars.Items[i].Element;
		 if (!PVars.Items[i].Units.IsEmpty())
		   ProfGrid1->AbsoluteCells[4][row]->Value = PVars.Items[i].Units;
		 if (!PVars.Items[i].Context.IsEmpty())
		   ProfGrid1->AbsoluteCells[5][row]->Value = PVars.Items[i].Context;
		 if (!PVars.Items[i].Taphonomy.IsEmpty())
		   ProfGrid1->AbsoluteCells[6][row]->Value = PVars.Items[i].Taphonomy;
		 if (!PVars.Items[i].EcolGroup.IsEmpty())
		   ProfGrid1->AbsoluteCells[7][row]->Value = PVars.Items[i].EcolGroup;
		 if (!PVars.Items[i].VarName.IsEmpty()) {
		   TProfGridCell* ACell = ProfGrid1->AbsoluteCells[2][row];
		   CELLOBJECT* CellObject;
		   TAXON_NOTES* TaxonNotes;
		   CellObject = new CELLOBJECT(CELLTAXONNOTES);
		   TaxonNotes = (TAXON_NOTES*)CellObject->Object;
		   SYNONYMY Synonym;
		   Synonym.TaxonName = PVars.Items[i].VarName;
		   Synonym.Contrib = true;
		   TaxonNotes->Synonymy.push_back(Synonym);
		   AddCellObject(ACell, CellObject);
		   AddTaxonNotesIcon(ACell);
		   }
		 row++;
		 }
	   }
	 }
   else {
	 msg = L"Error executing service EPD_GetPVars.";
	 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 }

   // get counts
   EPDGetPCounts Counts(ipsJSONS1, TcpClient1);
   Counts.AddParam(L"ENTITYNR", EPDENr);
   XMLParsingStatus(Counts.WebServiceName());
   if (Counts.Execute()) {
	 if (Counts.Size() > 0) {
	   for (unsigned int i=0; i < Counts.Size(); i++) {
		 int col = Samples[Counts.Items[i].SampleNr];
		 int row = Vars[Counts.Items[i].VarNr];
		 ProfGrid1->AbsoluteCells[col][row]->Value = Counts.Items[i].Count;
		 }
	   }
	 }
   else {
	 msg = L"Error executing service EPD_GetPCounts.";
	 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 }
   ProfGrid1->SpreadsheetEnabled = true;
   ProfGrid1->EnableControls();

   // Lithology

   EPDGetLithology Lithology(ipsJSONS1, TcpClient1);
   Lithology.AddParam(L"ENTITYNR", EPDENr);
   XMLParsingStatus(Lithology.WebServiceName());
   if (Lithology.Execute()) {
	 if (Lithology.Size() > 0) {
	   for (unsigned int i = 0; i < Lithology.Size(); i++) {
		 LITHOLOGYUNIT* lithunit = new LITHOLOGYUNIT();
		 lithunit->UnitDescription = Lithology.Items[i].Descript;
		 lithunit->DepthTop = Lithology.Items[i].DepthTopCM;
		 lithunit->DepthBottom = Lithology.Items[i].DepthBotCM;
		 lithunit->LowerBoundary = Lithology.Items[i].LoBoundary;
		 LithologyUnitList->Add(lithunit);
		 }
	   }
	 }
   else {
	 msg = L"Error executing service EPD_GetLithology.";
	 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 }

   // LOI


   EPDGetLOI LOI(ipsJSONS1, TcpClient1);
   LOI.AddParam(L"ENTITYNR", EPDENr);
   XMLParsingStatus(LOI.WebServiceName());
   if (LOI.Execute()) {
	 if (LOI.Size() > 0) {
	   set<int> LoTemps;
	   set<int> HiTemps;
	   for (unsigned int i=0, row=1; i < LOI.Size(); i++, row++) {
		 AdvColumnGrid5->AllCells[1][row] = LOI.Items[i].DepthCM;
		 if (!LOI.Items[i].Thickness.IsEmpty())
		   AdvColumnGrid5->AllCells[2][row] = LOI.Items[i].Thickness;
		 if (!LOI.Items[i].TempLo.IsEmpty()) {
		   AdvColumnGrid5->AllCells[3][row] = LOI.Items[i].TempLo;
		   LoTemps.insert(LOI.Items[i].TempLo);
		   }
		 if (!LOI.Items[i].LOILo.IsEmpty())
		   AdvColumnGrid5->AllCells[4][row] = LOI.Items[i].LOILo;
		 if (!LOI.Items[i].TempHi.IsEmpty()) {
		   AdvColumnGrid5->AllCells[5][row] = LOI.Items[i].TempHi;
		   HiTemps.insert(LOI.Items[i].TempHi);
		   }
		 if (!LOI.Items[i].LOIHi.IsEmpty())
		   AdvColumnGrid5->AllCells[6][row] = LOI.Items[i].LOIHi;
		 if (!LOI.Items[i].BulkDens.IsEmpty())
		   AdvColumnGrid5->AllCells[7][row] = LOI.Items[i].BulkDens;
		 }
	   if (LoTemps.size() == 1) {
		 ComboBox7->Text = *LoTemps.begin();
		 ExitLOITemp(ComboBox7,3);
		 }
	   if (HiTemps.size() == 1) {
		 ComboBox8->Text = *HiTemps.begin();
		 ExitLOITemp(ComboBox8,5);
		 }
	   loi.Investigators = Datasets[0].Investigators;
	   }
	 }
   else {
	 msg = L"Error executing service EPD_GetLOI.";
	 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 }

   FillMetaData();
   ParentForm->StatusBar1->Panels->Items[0]->Text = L"";
   Screen->Cursor = crDefault;
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::EPDWorker(int WorkerNr, map<int,CONTACT*>& Workers)
{
   if (Workers.count(WorkerNr) > 0)
	 return;

   // get worker
   EPDGetWorker Worker(ipsJSONS1, TcpClient1);
   Worker.AddParam(L"WORKERNR", WorkerNr);
   XMLParsingStatus(Worker.WebServiceName());
   if (Worker.Execute()) {
	 if (Worker.Size() == 1) {
	   CONTACT* Contact = new CONTACT();
	   Contact->FamilyName = Worker.Items[0].LastName;
	   Contact->LeadingInitials = Worker.Items[0].Initials;
	   Contact->GivenNames = Worker.Items[0].FirstName;
	   Contact->Suffix = Worker.Items[0].Suffix;
	   Contact->Title = Worker.Items[0].Title;
	   char status = Worker.Items[0].Status[1];
	   switch (status) {
		 case 'A':
		   Contact->Status = L"Active";
		   break;
		 case 'D':
		   Contact->Status = L"Deceased";
		   break;
		 case 'U':
		   Contact->Status = L"Unknown";
		   break;
		 case 'I':
		   Contact->Status = L"Inactive";
		   break;
		 default:
		   Contact->Status = L"Unknown";
		   break;
		 }
	   Contact->Telephone = Worker.Items[0].Phone;
	   Contact->Fax = Worker.Items[0].Fax;
	   Contact->Email = Worker.Items[0].EMailAddr;
	   Contact->Address = Worker.Items[0].Address;

	   int pos = Contact->Address.Pos(L"\\n");
	   while (pos > 0) {
		 Contact->Address.Delete(pos,2);
		 Contact->Address.Insert(L"\r\n",pos);
         pos = Contact->Address.Pos(L"\\n");
		 }

	   Contact->FormatContactName();
	   ContactList->Add(Contact);
	   Workers[WorkerNr] = Contact;
	   }
	 }
}
//---------------------------------------------------------------------------

void TTilSpreadSheetForm::EPDPublToPub(EPDPUBL& Publ, PUBLICATION* pub, map<int,CONTACT*>& Workers)
{
   pub->Primary = false;
   pub->PublicationYear = Publ.YearOfPubl;
   pub->Citation = Publ.Citation;
   EPDGetAuthors Authors(ipsJSONS1, TcpClient1);
   Authors.AddParam(L"PUBLNR", Publ.PublNr);
   XMLParsingStatus(Authors.WebServiceName());
   if (Authors.Execute()) {
	 if (Authors.Size() > 0) {
	   map<int,int>::iterator itr;
	   for (itr = Authors.Items.begin(); itr != Authors.Items.end(); itr++) {
		 EPDWorker(itr->second, Workers);
		 if (Workers.count(itr->second) > 0) {
		   CONTACT* Contact = Workers[itr->second];
		   AUTHOR author;
		   author.LastName = Contact->FamilyName;
		   author.Initials = Contact->LeadingInitials;
		   author.GivenNames = Contact->GivenNames;
		   author.Suffix = Contact->Suffix;
		   pub->AuthorList.push_back(author);
		   }
		 }
	   }
	 }
   else {
	 UnicodeString msg = L"Error executing service EPD_GetAuthors.";
	 MessageDlg(msg, Dialogs::mtError, TMsgDlgButtons() << mbOK, 0);
	 }
}
//---------------------------------------------------------------------------

UnicodeString TTilSpreadSheetForm::MakeSentence(UnicodeString phrase)
{
   UnicodeString cap = phrase.SubString(1,1).UpperCase();
   phrase.Delete(1,1);
   phrase.Insert(cap,1);
   if (*phrase.LastChar() != L'.')
	 phrase += L".";
   return phrase;
}
//---------------------------------------------------------------------------


