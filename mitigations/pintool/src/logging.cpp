#include "logging.h"

#include <iostream>

FILE* SokLogging::mainLog;

std::string getCurDateAndTime() {
	time_t rawtime;
	struct tm * timeinfo;
	char buffer[80];
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	strftime(buffer, 80, "%Y_%m_%d_%I_%M_%S", timeinfo);
	return string(buffer);
}

VOID SokLogging::Init() {	
	string path = string(LOGPATH);
	mainLog = fopen(path.append(LOGNAME).c_str(), "a");
	LOG_AR("Starting analysis...");
}

VOID SokLogging::Shutdown() {
	fclose(SokLogging::mainLog);
}

VOID SokLogging::logMain(const char* fmt, ...) {
	if (!SokLogging::mainLog) return; // TODO shall we quit Pin instead?
	va_list args;
	va_start(args, fmt);
	vfprintf(SokLogging::mainLog, fmt, args);
	va_end(args);

	fflush(SokLogging::mainLog);
}
