#pragma once
#include <cstdio>

namespace fission{
	typedef enum {
		ReadFile,
		WriteFile,
		AppendFile
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
