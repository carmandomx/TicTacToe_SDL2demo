#include "Logger.h"

void Logger::getError(std::ostream &os, const char* msg)
{
	os << msg << "[Error] " << SDL_GetError() << std::endl;
}
