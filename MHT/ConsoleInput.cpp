#include "ConsoleInput.h"

bool mha::GetChar(char & c)
{
	c = getchar();
	if (c == '\n')
	{
		return false;
	}
	while (getchar() != '\n');
	return true;
}

bool mha::GetString(char* str, size_t size)
{
	char c = 0;
	size_t i = 0;
	while (true)
	{
		c = getchar();
		if (c == '\n')
		{
			if (i == 0)
			{
				return false;
			}
			else
			{
				break;
			}
		}
		else
		{
			if (i < size - 1)
			{
				str[i] = c;
				i++;
			}
		}
	}
	return true;
}

bool mha::FindString(char* search, char* find)
{

	return false;
}
