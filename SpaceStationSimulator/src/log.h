#ifndef DEF_LOG_H
#define DEF_LOG_H

#include <fstream>
#include <mutex>

#include "format.h"

class Log {
public:
	void init();
	void close();
	void write(const std::string& str);
private:
	std::fstream _file;
	std::mutex _lock;
};

extern Log gLog;
#define LOG_OPEN_ERROR 1

//variadic macro
//## will delete the comma just before if the variables args are not supplied
#define LOG(x, ...) gLog.write(fmt::format(x, ## __VA_ARGS__)) 

#endif