#pragma once
#include <ostream>
#include "SDL.h"
class Logger
{
public:
	static void getError(std::ostream &os, const char* msg);
};

