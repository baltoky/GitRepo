#include "FileManipulation.h"

namespace fission{
	void FileM::startFile(ManipT type, const char* filepath){
		switch(type){
		case ReadFile:
			f_fp = fopen(filepath, "r");
			break;
		case WriteFile:
			f_fp = fopen(filepath, "w");
			break;
		case AppendFile:
			f_fp = fopen(filepath, "a");
			break;
		default:
			break;
		}
	}

	void FileM::endFile(){
		fclose(f_fp);
	}

	void FileM::writeFile(char* string){
		fprintf(f_fp, "%s", string);
	}

	char* FileM::readFileToString(){
		char* string;
		int i = 0;
		while(fscanf(f_fp, "%c", &string[i]) != EOF){
			i++;
		}	
		return string;
	}
}
