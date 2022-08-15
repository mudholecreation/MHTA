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
}

void DisplayUnknownWord(char* inputString)
{
	printf("I don't know the word \"");
	for (; *inputString != '\0' && *inputString != ' '; inputString++)
	{
		printf("%c", *inputString);
	}
	printf("\" \n");
}

void GetInput(char* inputString)
{
	printf("\n>");
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
bool CompareString(char*& str1, const char* str2)
{
	char* string = str1;
	while (	*str1 != '\0' && *str1 != ' '  && *str2 != '\0')
	{
		if (*string != *str2)
		{
			return false;
		}
		string++;
		str2++;
	}
	str1 = string;
	return true;
}

bool FindWordType(char*& inputString, char** words, char*& newCurrentWord)
{
	WordType type = INVALID_WORD;
	//Search Verbs
	for (size_t i = 0; i < MAX_VERB_COUNT; i++)
	{
		if (!words[i])
		{
			break;
		}
		if (CompareString(inputString, words[i]))
		{
			newCurrentWord = words[i];
			type = VERB;
			return true;
		}
	}
	//Search Objects

	//Search Rooms

	//Search Characters




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


