// ---------------------------------------------------------------------------
#pragma hdrstop
#include "inifile.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

#pragma region "LoadIni"

// ---------------------------------------------------------------------------

void __fastcall TForm1::LoadIni() {
	TMemIniFile *ini = new TMemIniFile(IniFile);

	// path section
	edtDirectory->Text = ini->ReadString("Path", "Directory", ExtractFilePath(Application->ExeName));
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

// ---------------------------------------------------------------------------

void __fastcall TForm1::SaveIni() {
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

#pragma region "LangIni"

// ---------------------------------------------------------------------------

void __fastcall TForm1::LangIni() {
	if (TFile::Exists(LangFile)) {
		TStringList *sect = new TStringList();
		TMemIniFile *ini = new TMemIniFile(LangFile);

		ini->ReadSectionValues("TGroupBox", sect);
		for (int i = 0; i < sect->Count; ++i) {
			String key = sect->Names[i];
			String val = sect->Values[key];
			TGroupBox *item = static_cast<TGroupBox*>(Form1->FindComponent(key));
			if (item != NULL) {
				item->Caption = val;
			}
		}

		ini->ReadSectionValues("TLabel", sect);
		for (int i = 0; i < sect->Count; ++i) {
			String key = sect->Names[i];
			String val = sect->Values[key];
			TLabel *item = static_cast<TLabel*>(Form1->FindComponent(key));
			if (item != NULL) {
				item->Caption = val;
			}
		}

		ini->ReadSectionValues("TCheckBox", sect);
		for (int i = 0; i < sect->Count; ++i) {
			String key = sect->Names[i];
			String val = sect->Values[key];
			TCheckBox *item = static_cast<TCheckBox*>(Form1->FindComponent(key));
			if (item != NULL) {
				item->Caption = val;
			}
		}

		ini->ReadSectionValues("TButton", sect);
		for (int i = 0; i < sect->Count; ++i) {
			String key = sect->Names[i];
			String val = sect->Values[key];
			TButton *item = static_cast<TButton*>(Form1->FindComponent(key));
			if (item != NULL) {
				item->Caption = val;
			}
		}

//		ini->ReadSectionValues("TMenuItem", sect);
//		for (int i = 0; i < sect->Count; ++i) {
//			String key = sect->Names[i];
//			String val = sect->Values[key];
//			TMenuItem *item = static_cast<TMenuItem*>(Form1->FindComponent(key));
//			if (item != NULL) {
//				item->Caption = val;
//			}
//		}

		delete ini;
		delete sect;
	}
}

#pragma end_region
