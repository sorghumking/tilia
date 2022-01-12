//---------------------------------------------------------------------------

#ifndef TIloiH
#define TIloiH
#ifndef TICtbFrmH
#include "TICtbFrm.h"
#endif


// typedef void __fastcall (__closure *TcxNotifyEvent)(void * Ptr, TListNotification Action);

//---------------------------------------------------------------------------

class LOI
{
public:
  SUBMISSION Submission;    // current submission, not saved
  vector<SUBMISSION> Submissions;
  vector<CONTACT*> Investigators;
  vector<PUBLICATION*> Publications;
public:
  LOI() { };
};
//---------------------------------------------------------------------------

class LOISAMPLE
{
public:
  Variant Thickness;
  Variant TempOrg;
  Variant LOIOrg;
  Variant TempCarb;
  Variant LOICarb;
  Variant BulkDens;
  Variant DateAnal;
  CONTACT* Analyst;
public:
  LOISAMPLE();
};
//---------------------------------------------------------------------------

typedef struct
{
  int analyst;
  int date;
  map<int,int> temps;  // temp, col
  int bulkdens;
} LOIROW;
//---------------------------------------------------------------------------

#endif
