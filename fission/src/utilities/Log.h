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

	void setLog(MessageLog& log, LogType type, char* message);
	void printLog(LogType type, char* message);
	void printLog(MessageLog& log);
	void addToLog(MessageLog& log, LogType type,  char* message);
	//void printLogOnFile(MessageLog* log); TODO

}
