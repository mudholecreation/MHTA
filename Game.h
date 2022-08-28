#pragma once
#include "TextAdventure.h"


struct Game
{
	Game();
	void CreateRoom(int index, int name, int description, int up, int down, int north, int south, int east, int west, int flags);
	void CreateObject(int index, int name, int description, int room, int flags);
	bool ExecuteSubroutine();
	void DisplayRoom(int room);

	Character player = {};

	bool sentence = false;
	Word word = {};
	Room* room = nullptr;

	Character* characters[MAX_CHARACTER_COUNT] = {};
	Object* objects[MAX_OBJECT_COUNT] = {};
	Room* rooms[MAX_ROOM_COUNT] = {};

	char inputString[MAX_SENTENCE_LENGTH] = {};

	const char* verbStrings[MAX_VERB_COUNT] = { "go", "north", "south", "west", "east" };
	const char* conjunctionStrings[MAX_CONJUNCTION_COUNT] = { "and", "the", "then" };
	const char* roomNames[MAX_ROOM_COUNT] = { "front of house" };
	const char* roomDescriptions[MAX_ROOM_COUNT] = { "front of house" };

	const char* objectNames[MAX_OBJECT_COUNT] = { "lantern", "rusty sword", "rusty" };
	const char* characterNames[MAX_CHARACTER_COUNT] = { "monster" };
	const char* prepositionStrings[MAX_PREPOSITION_COUNT] = { "in", "with", "on" };
};