#pragma once
#include <iostream>
#include "FileManipulation.h"

namespace fission{
	typedef enum{
		WarningLog,
		ErrorLog,
		DebugLog
	}LogT;

	class Log{
		private:
			char* f_log;
			LogT f_logType;
		public:
			void setLog(LogT type, char* message);
			char* getLog();
			void printLog();
			void printLogOnFile(ManipT manipType, const char* filepath);
	};
}
