#pragma once
#include <stdio.h>

const unsigned char MAX_WORD_LENGTH = 16;
const unsigned char MAX_SENTENCE_LENGTH = 64;
const unsigned char MAX_VERB_COUNT = 10;
const unsigned char MAX_CONJUNCTION_COUNT = 10;
const unsigned char MAX_ROOM_COUNT = 10;
const unsigned char MAX_OBJECT_COUNT = 10;
const unsigned char MAX_CHARACTER_COUNT = 10;
const unsigned char MAX_PREPOSITION_COUNT = 10;

const int INVALID = -1;
const int NONE = 0;

enum WordType
{
	VERB = 1,
	ROOM,
	OBJECT,
	CHARACTER,
	CONJUNCTION,
	PREPOSITION
};

struct Word
{
	int type = NONE;
	char* string;
	int index = INVALID;
};
struct Noun
{
	int name = INVALID;
	int description = INVALID;
};

enum RoomFlag
{
	LIT = 1,
	LOCKED,
};

enum ObjectFlag
{
	PICKUP = 1,
	EQUIPTED,
};

enum CharacterFlag
{
	
};

struct Room : Noun
{
	int up = INVALID;
	int down = INVALID;
	int north = INVALID;
	int south = INVALID;
	int east = INVALID;
	int west = INVALID;
	int flags = NONE;
};

struct Object : Noun
{
	int room = INVALID;
	int flags = NONE;
};

struct Character : Noun
{
	int room = INVALID;
	int health = 0;
	int flags = NONE;
};

void DisplayUnknownWord(char* inputString);

void GetInput(char* inputString);
void LowerInput(char* inputString);
void ClearInput(char* inputString);

bool FindWord(char*& inputString);
bool FindWordType(char*& inputString, const char** verbs, const char** conjunctions, const char** rooms, const char** objects, 
	const char** characters, const char** prepositions, Word& word);

void AddWordToSubroutine(Word& word, bool sentence);

