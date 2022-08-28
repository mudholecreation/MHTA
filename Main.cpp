#pragma once
#include "Game.h"

int main()
{
	Game game = {};
	game.DisplayRoom(game.player.room);

	while (true)
	{
		GetInput(game.inputString);
		LowerInput(game.inputString);
		char* input = game.inputString;
		game.word = {};

		do
		{
			if (!FindWord(input))
			{
				if (game.word.type == INVALID)
				{
					printf("I couldn't find any words.\n");
				}
				break;
			}
			if (!FindWordType(input, game.verbStrings, game.conjunctionStrings, game.roomNames, game.objectNames,
				game.characterNames, game.prepositionStrings, game.word))
			{
				DisplayUnknownWord(input);
				break;
			}
			else
			{
				printf("Found: %s\n", game.word.string);
				AddWordToSubroutine(game.word, game.sentence);
			}
		} while (*input != '\0');

		if (!game.ExecuteSubroutine())
		{

		}
		ClearInput(game.inputString);
	}
	return 0;
}