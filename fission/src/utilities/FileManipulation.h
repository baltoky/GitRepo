#pragma once
#include <cstdio>

namespace fission{
	typedef enum {
		FileRead,
		FileWrite,
		FileAppend
	}ManipT;

	class FileM{
		private:
			FILE* f_fp;
		public:
			void startFile(ManipT type, const char* filetype);
			void endFile();
			void writeFile(char* string);
			char* readFileToString();
	};
}
