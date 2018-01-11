#include "LifeUniverseEverythingMirror.h"
#include <string>
#include <iostream>
#ifndef STOP_READ_CONST
#define STOP_READ_CONST "42"
#endif
/*Solution for the http://www.spoj.com/problems/TEST/ */
void LifeUniverseEverythingMirror::Run()
{
	std::string input;
	std::cin >> input;
	while (input != STOP_READ_CONST)
	{
		std::cout <<  input << std::endl;
		std::cin >> input;
	}
}
