#include "Log.h"

Log::Log()
{
	std::cout << "--ZDS version 0.01--" << std::endl;
	file.open("log.txt");
	file << "--Log File, ZDS version 0.01--\n";
}

Log::~Log()
{
	file.close();
}

void Log::write(std::string output)
{
	std::cout << output << std::endl;
	file << output << "\n";
}