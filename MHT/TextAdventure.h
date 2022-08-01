#pragma once
#include "Game.h"
#include <stdio.h>

void Display(const char* string)
{
	printf(string);
}
void DisplayFirstWord(char* word)
{
	for (; *word != '\0' && *word != ' '; word++)
	{
		printf("%c", *word);
	}
	printf("\n");
}
void GetInput(char* inputString)
{
	printf(">");
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
	printf("\n");
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
	int size = sizeof(nouns) / MAX_WORD_LENGTH;
	for (size_t i = 0; i < size; i++)
	{
		if (CompareString(word, nouns[i]))
		{
			noun = i;
			return true;
		}
	}

	return false;
}

bool FindVerb(char* word, int& verb)
{
	int size = sizeof(verbs) / MAX_WORD_LENGTH;
	for (size_t i = 0; i < size; i++)
	{
		if (CompareString(word, verbs[i]))
		{
			verb = i;
			return true;
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
void Clear(char* string)
{
	for (size_t i = 0; i < MAX_INPUT_LENGTH; i++)
	{
		string[i] = '\0';
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
			continue;
		}

		if (FindVerb(pos, verb))
		{
			printf("Found Verb: ");
			DisplayFirstWord(pos);
		}

		if (FindNoun(pos, noun))
		{
			printf("Found Noun: ");
			DisplayFirstWord(pos);
		}
		Advance(pos);
	}

}
