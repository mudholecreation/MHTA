#pragma once
#include "TextAdventure.h"



struct Game
{
	Game();
	char inputString[MAX_SENTENCE_LENGTH] = {};
	Character player = {};
	Word* currentWord = nullptr;
	Room* currentRoom = nullptr;
	Word words[MAX_WORD_COUNT] = { "jump", VERB, "the", CONJUCTION, "and", CONJUCTION};

};