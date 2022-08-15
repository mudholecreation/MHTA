#pragma once
#include "TextAdventure.h"



struct Game
{
	Game();
	char inputString[MAX_SENTENCE_LENGTH] = {};
	Character player = {};
	char* currentWord = nullptr;
	Room* currentRoom = nullptr;
	const char* verbs[MAX_VERB_COUNT] = {"jump", "go"};
};