#pragma once
#pragma warning(disable : C26812)
#include "TextAdventure.h"



struct Game
{
	Game();
	char inputString[MAX_SENTENCE_LENGTH] = {};
	Character player = {};
	Word* currentWord = nullptr;
	Room* currentRoom = nullptr;
	Word words[MAX_WORD_COUNT] = { "then", CONJUNCTION, "the", CONJUNCTION, "and", CONJUNCTION, "jump", VERB};

};