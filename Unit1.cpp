#include <vcl.h>
#pragma hdrstop
#include "registry.hpp"
#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

TStringList *All = new TStringList;
TStringList *All_two = new TStringList;
TStringList *Temp = new TStringList;
TStringList *Temp_two = new TStringList;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	int i,j,k=0, II=0, JJ=0;
	Form2->StringGrid1->RowCount=1;
	FindReg(HKEY_LOCAL_MACHINE);
	FindReg(HKEY_CURRENT_USER);
	for(i = 0; i < All->Count; i++)
	if(Temp->IndexOf(All->Strings[i]) == -1)
		{
			Temp->Add(All->Strings[i]);
			Temp_two->Add(All_two->Strings[i]);
		}

	for(i = 0; i < Temp->Count; i++)
	{
		ADOTable1->First();
		for(j = 0; j < ADOTable1->RecordCount;j++)
			{
				if(LowerCase(Temp->Strings[i]).Pos(LowerCase(ADOTable1->FieldByName("Name_2")->AsString)))
					{
						if(k!=0) Form2->StringGrid1->RowCount+=1;
						Form2->StringGrid1->Cells[0][k]=Temp->Strings[i];
						Form2->StringGrid1->Cells[1][k]=Temp_two->Strings[i];
						k++;
					}
				ADOTable1->Next();
			}
	}
	Memo1->Text=Temp->Text;
	Form2->Caption="������������ ����������: "+IntToStr(k);
	if(k==0)
		{
			Form2->StringGrid1->Cells[0][0]="���������� �� �������.";
			Form2->StringGrid1->Cells[0][1]="";
		}

	Form2->Show();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FindReg(HKEY rKey)
{
  String Path, Values, Unist;
  TRegistry *reg = new TRegistry();
  reg->RootKey = rKey;
  Path = "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\";
  TStringList *l = new TStringList;
  reg->OpenKey(Path, 0);
  reg->GetKeyNames(l);
  for(int i = 0; i < l->Count; i++)
   {
	 String SubPath = Path + l->Strings[i];
	 reg->OpenKey(SubPath, false);
	 if(reg->ValueExists("DisplayName"))
		 {
			  Values = reg->ReadString("DisplayName");
			 if(reg->ValueExists("UninstallString"))
			  Unist = reg->ReadString("UninstallString");
			 else Unist = "Not";
		 }
	 All->Add(Values);
	 All_two->Add(Unist);
     reg->CloseKey();
   }
  delete l;
  delete reg;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
  delete All;
  delete All_two;
  delete Temp;
  delete Temp_two;
}

void __fastcall TForm1::FormCreate(TObject *Sender)
{
//Form2->StringGrid1->ColWidths[1]=0;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button2Click(TObject *Sender)
{
int g;
AnsiString ttt;
g=Memo1->Text.Pos(ADOTable1->FieldByName("Name_2")->AsString);
			Memo1->Text=Memo1->Text.Delete(1,g-1);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
	TRegistry *reg = new TRegistry();
	TStringList *Programs = new TStringList;

	reg->RootKey = HKEY_LOCAL_MACHINE;
	reg->OpenKey("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall",0);
	reg->GetKeyNames(Programs);
	reg->CloseKey();

	for(int i = 0; i < Programs->Count; i++)
		{
			reg->OpenKeyReadOnly("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\"+Programs->Strings[2]+"");
			//if(reg->ReadString("DisplayName") != "")
				{
					Memo1->Lines->Add(reg->ReadString("DisplayName"));
				}
			reg->CloseKey();
		}
	delete reg;
	delete Programs;
	Button3->Caption=Memo1->Lines->Count;
}
//---------------------------------------------------------------------------

