#pragma once
#include "Game.h"
#include <stdio.h>

void Display(const char* displayString)
{
	printf(displayString);
}

void GetInput(char* inputString)
{
	Display(">");
	char c = 0;
	size_t i = 0;
	while (true)
	{
		c = getchar();
		if (c == '\n')
		{
			break;
		}
		else
		{
			if (i < MAX_INPUT_LENGTH - 1)
			{
				inputString[i] = c;
				i++;
			}
		}
	}
	Display("\n");
}

bool CompareString(const char* str1, const char* str2)
{
	while (*str1 != '\0' && *str2 != '\0')
	{
		if (*str1 != *str2)
		{
			return false;
		}
		str1++;
		str2++;
	}
	return true;
}

bool FindNoun(char* word, int& noun)
{
	for (size_t i = 0; i < sizeof(nouns); i++)
	{
		if (CompareString(word, nouns[i]))
		{
			noun = i;
			return true;
			break;
		}
	}

	return false;
}

bool FindVerb(char* word, int& verb)
{
	for (size_t i = 0; i < sizeof(verbs); i++)
	{
		if (CompareString(word, verbs[i]))
		{
			verb = i;
			return true;
			break;
		}
	}
	return false;
}

void Advance(char*& pos)
{
	while (*pos != '\0')
	{
		pos++;
		if (*pos == ' ')
		{
			break;
		}
	}
}

void Lower(char* pos)
{
	while (*pos != '\0')
	{
		if (*pos >= 'A' && *pos <= 'Z')
		{
			*pos += 32;
		}
		pos++;
	}
}
bool FindWord(char* pos)
{
	if (*pos >= 'a' && *pos <= 'z')
	{
		return true;
	}
	return false;
}
void Clear(char* inputString)
{
	for (size_t i = 0; i < MAX_INPUT_LENGTH; i++)
	{
		inputString[i] = '\0';
	}
}
void Execute(char* inputString)
{
	int verb = -1;
	int noun = -1;

	char* pos = &inputString[0];

	while (*pos != '\0')
	{
		if (!FindWord(pos))
		{
			pos++;
			printf("wars\n");
			continue;
		}

		//if (FindVerb(word, verb))
		//{

		//}

		//if (FindNoun(word, noun))
		//{

		//}
		printf("%s\n", pos);
		Advance(pos);
	}

}