#include "Log.h"

namespace fission{
	void setLog(MessageLog& log, LogType type, char* message){
		strcpy(log.f_message, "");
		addToLog(log, type, message);
	}
	void printLog(MessageLog& log){
		std::cout << log.f_message << std::endl;
	}
	void printLog(LogType type, char* message){
		MessageLog log;
		setLog(log, type, message);
		printLog(log);
	}
	void addToLog(MessageLog& log, LogType type,  char* message){
		switch(type){
			case WarningLog:
				strcat(log.f_message, "WARNING: ");
				break;
			case ErrorLog:
				strcat(log.f_message, "ERROR: ");
				break;
			case DebugLog:
				strcat(log.f_message, "DEBUG: ");
				break;
		}
		strcat(log.f_message, message);
	}

}
