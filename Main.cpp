#pragma once
#include "Game.h"

int main()
{
	Game game = {};
	DisplayRoom(game.player.room);

	while (true)
	{
		GetInput(game.inputString);
		LowerInput(game.inputString);
		char* input = game.inputString;
		game.currentWord = nullptr;
		do
		{
			if (!FindWord(input))
			{
				if (!game.currentWord)
				{
					printf("I couldn't find any words.\n");
				}
				break;
			}
			if (!FindWordType(input, game.words, game.currentWord))
			{
				DisplayUnknownWord(input);
				break;
			}
			else
			{
				printf("Found: %s\n", game.currentWord->string);
			}
		} while (*input != '\0');
		ClearInput(game.inputString);
	}
	return 0;
}