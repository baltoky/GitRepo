#pragma once
#include <iostream>
#include <cstring>
#include "FileManipulation.h"

namespace fission{
	enum LogType{
		WarningLog,
		ErrorLog,
		DebugLog
	};

	struct MessageLog{
		char f_message[];
	};

	void setLog(MessageLog& log, LogType type, const char* message);
	void printLog(LogType type, const char* message);
	void printLog(MessageLog& log);
	void addToLog(MessageLog& log, LogType type,  const char* message);
	void printLogOnFile(MessageLog& log, const char* filepath);
	void printLogOnFile(LogType type, const char* message, const char* filepath);

}
