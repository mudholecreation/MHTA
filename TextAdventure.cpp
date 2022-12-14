#include "TextAdventure.h"


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
bool FindType(char*& inputString, const char** strings, const unsigned int count, Word& word)
{
	for (size_t i = 0; i < count; i++)
	{
		if (!strings[i])
		{
			continue;
		}
		if (CompareString(inputString, strings[i]))
		{
			word.index = i;
			word.string = (char*)strings[i];
			return true;
		}
	}
	return false;
}
bool FindWordType(char*& inputString, const char** verbs, const char** conjunctions, const char** rooms, const char** objects,
	const char** characters, const char** prepositions, Word& word)
{
	//Search Verbs
	if (FindType(inputString, verbs, MAX_VERB_COUNT, word))
	{
		word.type = VERB;
		return true;
	}
	//Search Conjunctions
	if (FindType(inputString, conjunctions, MAX_CONJUNCTION_COUNT, word))
	{
		word.type = CONJUNCTION;
		return true;
	}
	//Search Rooms
	if (FindType(inputString, rooms, MAX_ROOM_COUNT, word))
	{
		word.type = ROOM;
		return true;
	}
	//Search Objects
	if (FindType(inputString, objects, MAX_OBJECT_COUNT, word))
	{
		word.type = OBJECT;
		return true;
	}
	//Search Characters
	if (FindType(inputString, characters, MAX_CHARACTER_COUNT, word))
	{
		word.type = CHARACTER;
		return true;
	}
	//Search prepositions
	if (FindType(inputString, prepositions, MAX_PREPOSITION_COUNT, word))
	{
		word.type = PREPOSITION;
		return true;
	}
	return false;
}

void AddWordToSubroutine(Word& word, bool sentence)
{

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


