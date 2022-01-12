#define TGFormsH

typedef struct
{
int VarNum;
bool Checked;
AnsiString VarName;
} FORMVARLIST;

typedef struct
{
TColor value;
bool show;
} COLORSELECTION;