#pragma once
#include <stdio.h>

namespace mha
{
	bool GetChar(char& c);
	bool GetString(char* str, size_t size);
	bool FindString(char* search, char* find);
}