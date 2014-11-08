//---------------------------------------------------------------------------
#pragma hdrstop
#include "inifile.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

#pragma region "LoadIni"

//---------------------------------------------------------------------------

void __fastcall TForm1::LoadIni()
{
	TMemIniFile *ini = new TMemIniFile(IniFile);

	// path section
	edtDirectory->Text = ini->ReadString("Path", "Directory",
		ExtractFilePath(Application->ExeName));
	edtPattern->Text = ini->ReadString("Path", "Pattern", "*.*");

	// Option section
	chbSort->Checked = ini->ReadBool("Option", "Sort", true);
	chbSubDirectory->Checked = ini->ReadBool("Option", "SubDirectory", true);
	chbMinimized->Checked = ini->ReadBool("Option", "Minimized", false);
	if (chbMinimized->Checked) {
		this->Visible = False;
		this->WindowState = wsMinimized;
	}

	delete ini;
}

#pragma end_region

#pragma region "SaveIni"

//---------------------------------------------------------------------------

void __fastcall TForm1::SaveIni()
{
	TMemIniFile *ini = new TMemIniFile(IniFile);

	// path section
	ini->WriteString("Path", "Directory", edtDirectory->Text);
	ini->WriteString("Path", "Pattern", edtPattern->Text);

	// Option section
	ini->WriteBool("Option", "Sort", chbSort->Checked);
	ini->WriteBool("Option", "SubDirectory", chbSubDirectory->Checked);
	ini->WriteBool("Option", "Minimized", chbMinimized->Checked);

	ini->UpdateFile();

	delete ini;
}

#pragma end_region
