#include "Utilities.h"
#include <cstring>


namespace fission{

	void openFile(CustomFile file, FileType type, const char* filepath){
		
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
