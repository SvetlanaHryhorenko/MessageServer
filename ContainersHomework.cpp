// ContainersHomework.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Server.h"

#include <cstdlib>

int main()
{
	Server S;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 1000; j++)
		{
			S.send_message({ rand()%50, "Hello world!" });
		}
		S.new_day();
	}
    return 0;
}

