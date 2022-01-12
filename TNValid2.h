//---------------------------------------------------------------------------

#ifndef TNValid2H
#define TNValid2H

class SSAMPLEAGE
{
public:
	int AnalUnitID;
	int SampleID;
	double BP;
	double OldBP;
	double YoungBP;
	UnicodeString ControlType;
public:
	SSAMPLEAGE(int auid, int sid, UnicodeString type) { AnalUnitID = auid;
		SampleID = sid, BP = -9999; OldBP = -9999; YoungBP = -9999;
		ControlType = type; }
};
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#endif
