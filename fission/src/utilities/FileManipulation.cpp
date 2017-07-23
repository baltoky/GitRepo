#include "Utilities.h"
#include <cstring>


namespace fission{

	void openFile(CustomFile& file, FileType type, const char* filepath){
		switch(type){
			case ReadFile:
				file = fopen(filepath, "rb");
				break;
			case WriteFile:
				file = fopen(filepath, "wb");
				break;
			case AppendFile:
				file = fopen(filepath, "ab");
				break;
			default:
				printLog(ErrorLog, "The file type was not accepted.");
				break;
		}
	}

	CustomFile openFile(FileType type, const char* filepath){
		switch(type){
			case ReadFile:
				return fopen(filepath, "rb");
				break;
			case WriteFile:
				return fopen(filepath, "wb");
				break;
			case AppendFile:
				return fopen(filepath, "ab");
				break;
			default:
				printLog(ErrorLog, "The file type was not accepted.");
				break;
		}
		return 0;
	}

	void closeFile(CustomFile file){
		fclose(file);
	}

	int getFileSize(const char* filepath){
		CustomFile file = openFile(ReadFile, filepath);
		int sizeOfFile = 0;
		fseek(file, 0, SEEK_END);
		sizeOfFile = (int)ftell(file);
		closeFile(file);
		return sizeOfFile;
	}

	int getFileSize(CustomFile file){
		int sizeOfFile = 0;
		fseek(file, 0, SEEK_END);
		sizeOfFile = (int)ftell(file);
		fseek(file, 0, SEEK_SET);
		return sizeOfFile;
	}

	void writeFile(const char* filepath, const char* message){
		CustomFile file = openFile(WriteFile, filepath);
		fprintf(file, "%s", message);
		closeFile(file);
	}

	void appendFile(const char* filepath, const char* message){
		CustomFile file = openFile(AppendFile, filepath);
		fprintf(file, "%s", message);
		closeFile(file);
	}

	char* readFileToString(const char* filepath){
		char* buffer = 0;
		CustomFile file = openFile(ReadFile, filepath);
		int size = getFileSize(file);

		buffer = (char*) malloc(size);
		if(buffer){
			fread(buffer, 1, size, file);
		}
		closeFile(file);
		return buffer;
	}

	/*
	void openFile(FileT type, const char* filepath){

		switch(type){
			case ReadFile:
				FilePointer = fopen(filepath, "r");
				break;
			case WriteFile:
				FilePointer = fopen(filepath, "w");
				break;
			case AppendFile:
				FilePointer = fopen(filepath, "a");
				break;
			default:
				// TODO: set a message on the log system.
				break;
		}
		if(FilePointer == 0){
			// TODO: set the log system!
		}
	}

	void endFile(){
		fclose(FilePointer);
	}

	//Must only be used when writing a file.
	void writeFile(FileT type, const char* filepath, const  char* message){
		if(type != ReadFile){
			openFile(type, filepath);
			fprintf(FilePointer, "%s", message);
			endFile();
		}
		else{
			// TODO: set an error message with the log system.
		}
	}

	// Must only be used while reading a file.
	char* readFileToString(FileT type, const char* filepath){
		char* string;
		if(type == ReadFile){

		char temp;
		int sizeOfFile = 0;

		openFile(type, filepath);
		while(fscanf(FilePointer, "%c", &temp) != EOF){
			sizeOfFile++;
		}
		endFile();

		string = new char[sizeOfFile];

		openFile(type, filepath);
		int i = 0;
		while(fscanf(FilePointer, "%c", &string[i]) != EOF){
			i++;
		}
		endFile();

		}
		else{
			// TODO: log an error message.
		}
		return string;
	}
	*/
}
