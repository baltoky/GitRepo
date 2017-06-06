#include "Log.h"

namespace fission{
	void Log::setLog(LogT type, char* message){
		f_logType = type;
		f_log = message;
	}

	char* Log::getLog(){
		return f_log;
	}

	void Log::printLog(){
		switch(f_logType){
			case WarningLog:
				std::cout << "Warning: " << std::endl;
				break;
			case ErrorLog:
				std::cout << "Error: " << std::endl;
				break;
			case DebugLog:
				std::cout << "Debug: " << std::endl;
				break;
			default:
				break;
		}
		std::cout << f_log << std::endl;
	}

	void Log::printLogOnFile(ManipT manipType, const char* filepath){
		FileM file;
		file.startFile(manipType, filepath);
		switch(f_logType){
			case WarningLog:
				file.writeFile((char*)"Warning: \n");
				break;
			case ErrorLog:
				file.writeFile((char*)"Error: \n");
				break;
			case DebugLog:
				file.writeFile((char*)"Debug: \n");
				break;
			default:
				break;
		}
		file.writeFile(f_log);
		file.endFile();
	}
}
