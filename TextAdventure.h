#pragma once
#include <stdio.h>

const unsigned char MAX_WORD_LENGTH = 16;
const unsigned char MAX_SENTENCE_LENGTH = 64;
const unsigned char MAX_VERB_COUNT = 10;
const unsigned char MAX_CONJUNCTION_COUNT = 10;
const unsigned char MAX_ROOM_COUNT = 10;
const unsigned char MAX_OBJECT_COUNT = 10;
const unsigned char MAX_CHARACTER_COUNT = 10;


enum WordType
{
	INVALID_WORD,
	VERB,
	ROOM,
	OBJECT,
	CHARACTER,
	CONJUNCTION
};

struct Noun
{
	char name[MAX_WORD_LENGTH] = {};
	char description[MAX_SENTENCE_LENGTH] = "";
};

enum RoomFlag
{
	INVALID_ROOM,
	LIT,
	LOCKED,
};

enum ObjectFlag
{
	INVALID_OBJECT,
	PICKUP,
	EQUIPTED,
};

enum CharacterFlag
{
	INVALID_CHARACTER,
};

struct Room : Noun
{
	Room* up = nullptr;
	Room* down = nullptr;
	Room* north = nullptr;
	Room* south = nullptr;
	Room* east = nullptr;
	Room* west = nullptr;
	int flags = INVALID_ROOM;
};

struct Object : Noun
{
	Room* room = nullptr;
	int flags = INVALID_OBJECT;
};

struct Character : Noun
{
	Room* room = nullptr;
	int health = 0;
	int flags = INVALID_CHARACTER;
};

void DisplayName(Noun* noun);
void DisplayDescription(Noun* noun);
void DisplayRoom(Room* room);
void DisplayUnknownWord(char* inputString);

void GetInput(char* inputString);
void LowerInput(char* inputString);
void ClearInput(char* inputString);

bool FindWord(char*& inputString);
bool FindWordType(char*& inputString, const char** verbs, const char** conjunctions, const char** rooms, const char** objects, 
	const char** characters, char*& newCurrentWord);

