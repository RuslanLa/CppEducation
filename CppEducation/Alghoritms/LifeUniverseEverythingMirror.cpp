#include "LifeUniverseEverythingMirror.h"
#ifndef STOP_READ_CONST
#define STOP_READ_CONST "42"
#endif
/*Solution for the http://www.spoj.com/problems/TEST/ */
void LifeUniverseEverythingMirror::Run()
{
	string input;
	cin >> input;
	while (input != STOP_READ_CONST)
	{
		cout <<  input << endl;
		cin >> input;
	}
}
