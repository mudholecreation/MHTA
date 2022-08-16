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
int FindLength(const char* string)
{
	int size = 0;
	while (*string != '\0')
	{
		if (*string == ' ')
		{
			return size;
		}
		size++;
		string++;
	}
	return size;
}
bool CompareString(char*& str1, const char* str2)
{
	char* string = str1;
	while (*str2 != '\0')
	{
		if (*string != *str2)
		{
			return false;
		}
		string++;
		str2++;
	}
	if (*string == ' ' || *string == '\0')
	{
		str1 = string;
		return true;
	}
	return false;

}

bool FindWordType(char*& inputString, const char** verbs, const char** conjunctions, const char** rooms, char*& newCurrentWord)
{
	WordType type = INVALID_WORD;
	//Search Verbs
	for (size_t i = 0; i < MAX_VERB_COUNT; i++)
	{
		if (!verbs[i])
		{
			break;
		}
		if (CompareString(inputString, verbs[i]))
		{
			newCurrentWord = (char*)verbs[i];
			type = VERB;
			return true;
		}
	}
	//Search Conjunctions
	for (size_t i = 0; i < MAX_CONJUNCTION_COUNT; i++)
	{
		if (!conjunctions[i])
		{
			break;
		}
		if (CompareString(inputString, conjunctions[i]))
		{
			newCurrentWord = (char*)conjunctions[i];
			type = CONJUNCTION;
			return true;
		}
	}
	//Search Rooms
	for (size_t i = 0; i < MAX_ROOM_COUNT; i++)
	{
		if (!rooms[i])
		{
			break;
		}
		if (CompareString(inputString, rooms[i]))
		{
			newCurrentWord = (char*)rooms[i];
			type = ROOM;
			return true;
		}
	}
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


