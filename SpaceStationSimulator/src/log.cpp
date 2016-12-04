#include "log.h"

#include <iostream>
#include <time.h>

Log gLog;

void Log::init()
{
	//_file.open("App.log", std::fstream::in | std::fstream::out | std::fstream::app); //append
	//if (!_file) throw LOG_OPEN_ERROR;
}

void Log::close()
{
	_file.close();
}

void Log::write(const std::string & str)
{
	_lock.lock();
	time_t t = time(nullptr);
	char bstr[100];

#ifdef _MSC_VER
	struct tm buf;
	localtime_s(&buf, &t);
	strftime(bstr, sizeof(bstr), "[%m/%d/%Y] %H:%M:%S: ", &buf);
#else
	struct tm* buf;
	buf = localtime(&t);
	strftime(bstr, sizeof(bstr), "[%m/%d/%Y] %H:%M:%S: ", buf);
#endif
	std::string logString = std::string(bstr) + str;
	/*_file << logString;*/
	std::cout << logString << "\n";
	_lock.unlock();
}
