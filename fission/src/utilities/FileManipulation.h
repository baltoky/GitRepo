#pragma once
#include <cstdio>
#include <cstdlib>

namespace fission{

	enum FileType{
		ReadFile,
		WriteFile,
		AppendFile
	};

	//TODO: FIX ME!!!!
	//On track, Focus on treating the file as an object.
	//------------------
	
	typedef FILE* CustomFile;

	/*
	 * Opens a filepath and sets a custom file
	 * 	as the pointer for that file.
	 * */
	void openFile(CustomFile& file, FileType type, const char* filepath);
	CustomFile openFile(FileType type, const char* filepath);

	/*
	 * Closes a file that was given a certain
	 * 	file pointer.
	 * */
	void closeFile(CustomFile file);

	/*
	 * Returns the size of a file with
	 * 	a certain file path.
	 * 	The file must be closed.
	 * */
	int getFileSize(const char* filepath);

	/*
	 * Returns the size of a file with
	 * 	a certain file pointer.
	 * 	The file must be open on read.
	 * */
	int getFileSize(CustomFile file);

	/*
	 * Writes on a file, the file must be closed.
	 * */
	void writeFile(const char* filepath, const char* message);

	/*
	 * Appends to a file, the file must be closed.
	 * */
	void appendFile(const char* filepath, const char* message);

	/*
	 * Reads a file to a string, the file must be closed.
	 * */
	char* readFileToString(const char* filepath);

}
