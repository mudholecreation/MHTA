#include "TextAdventure.h"


void DisplayName(Noun* noun)
{
	if (noun)
	{
		printf(noun->name);
	}
}

void DisplayDescription(Noun* noun)
{
	if (noun)
	{
		printf(noun->description);
	}
}

void DisplayRoom(Room* room)
{
	DisplayName(room);
	printf("\n");
	DisplayDescription(room);
	printf("\n");
}

void DisplayUnknownWord(char* inputString)
{
	printf("\n");
	printf("I don't know the word \"");

	for (; *inputString != '\0' && *inputString != ' '; inputString++)
	{
		printf("%c", *inputString);
	}
	printf("\" \n");
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
			if (i < MAX_SENTENCE_LENGTH - 1)
			{
				inputString[i] = c;
				i++;
			}
		}
	}
	printf("\n");
}

void LowerInput(char* inputString)
{
	while (*inputString != '\0')
	{
		if (*inputString >= 'A' && *inputString <= 'Z')
		{
			*inputString += 32;
		}
		inputString++;
	}
}

void ClearInput(char* inputString)
{
	for (size_t i = 0; i < MAX_SENTENCE_LENGTH; i++)
	{
		inputString[i] = '\0';
	}
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

bool FindWordType(char* inputString, Word* words, Word*& word)
{
	for (size_t i = 0; i < MAX_WORD_COUNT; i++)
	{
		if (words[i].type == WordType::INVALID_WORD)
		{
			return false;
		}
		if (CompareString(inputString, words[i].string))
		{
			word = &words[i];
			return true;
		}
	}
	return false;
}

bool FindWord(char*& inputString)
{
	while(*inputString != '\0')
	{
		if (*inputString < 'a' || *inputString > 'z')
		{
			inputString++;
			continue;
		}
		return true;
	}
	return false;
}	


