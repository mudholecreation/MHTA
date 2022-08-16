#pragma once
#include "TextAdventure.h"



struct Game
{
	Game();
	char inputString[MAX_SENTENCE_LENGTH] = {};
	Character player = {};
	char* currentWord = nullptr;
	Room* currentRoom = nullptr;
	const char* verbs[MAX_VERB_COUNT] = {"go", "north", "south", "west", "east"};
	const char* conjunctions[MAX_CONJUNCTION_COUNT] = {  "and", "the", "then"};
	const char* rooms[MAX_ROOM_COUNT] = { "front of house"};
	const char* objects[MAX_OBJECT_COUNT] = { "lantern" };
	const char* characters[MAX_CHARACTER_COUNT] = { "monster" };

};