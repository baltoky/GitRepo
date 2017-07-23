#pragma once
#include <cstdio>

namespace fission{

	enum FileType{
		ReadFile,
		WriteFile,
		AppendFile
	};

	//TODO: FIX ME!!!!
	
	typedef FILE* CustomFile;

	void openFile(CustomFile file, FileType type, const char* filepath);
	CustomFile openFile(FileType type, char* filepath);
	void closeFile(CustomFile file);
	int getFileSize(CustomFile file);
	void writeFile(CustomFile file, char* message);
	void appendFile(CustomFile file, const* message);
	char* readToString(CustomFile file);

	/*
	void openFile(FileT type, const char* filepath);
	void endFile();
	void writeFile(FileT type, const char* filepath, const char* message);
	char* readFileToString();
	*/
}
