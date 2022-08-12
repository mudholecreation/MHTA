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

		char* sentence = game.inputString;
		while (*sentence != '\0')
		{
			if (!FindWord(sentence))
			{
				printf("Couldn't find any words.\n");
				break;
			}
			if (!FindWordType(sentence, game.words, game.currentWord))
			{
				printf("Couldn't find any words that I know.\n");
				break;
			}
			else
			{
				printf("found: %s\n", game.currentWord->string);
				break;
			}
			//if (!game.currentWord)
			//{
			//	//DisplayUnknownWord(game.inputString);
			//	game.inputString;
			//	break;
			//}
			//switch (game.currentWord->type)
			//{
			//	case WordType::VERB:


			//		break;
			//}
	//		FindItem(game);
	//		Execute(game);
		}
		ClearInput(game.inputString);
	}
	//Save(game);
	//Destroy(game);
	return 0;
}