#pragma once

#include <iostream>
#include <fstream>

class Log{
public:
	Log();
	~Log();
	void write(std::string output);
private:
	std::ofstream file;
};