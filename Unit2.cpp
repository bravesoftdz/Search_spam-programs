//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "System.hpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;

//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormCreate(TObject *Sender)
{
	//StringGrid1->ColWidths[1] = -1;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::StringGrid1DblClick(TObject *Sender)
{
int i;
AnsiString Str;

int Top = StringGrid1->Selection.Top+1;
Str=StringGrid1->Cells[1][Top];

while (Str.Pos('"'))
	{
		i=Str.Pos('"');
		Str.Delete(i,1);
	}

Str="start "+Str;
system(Str.c_str());
}
//---------------------------------------------------------------------------

