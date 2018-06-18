// sandbox.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <Engine.h>


int main(int argc, char* args[])
{
	
	engine::Engine E;
	if (E.init() > 0)
	{
		return -1;
	}

	E.run();

	
    return 0;
}

