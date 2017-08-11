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
		fprintf(file, "%s ", message);
		closeFile(file);
	}

	void appendFile(const char* filepath, const char* message){
		CustomFile file = openFile(AppendFile, filepath);
		fprintf(file, "%s ", message);
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
}
