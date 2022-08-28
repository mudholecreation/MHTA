#include "Game.h"

Game::Game()
{
	CreateRoom(0, 0, 0, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, NONE);
	CreateObject(0, 1, 1, 2, NONE);
}
void Game::CreateRoom(int index, int name, int description, int up, int down, int north, int south, int east, int west, int flags)
{

}

void Game::CreateObject(int index, int name, int description, int room, int flags)
{
}

bool Game::ExecuteSubroutine()
{
	switch (sentence)
	{
		case 0:return true;
		default: return false;
	}
	return false;
}

void Game::DisplayRoom(int room)
{
	if (room == INVALID)
	{
		printf("INVALID Room\n");
		return;
	}
	if (rooms[room]->name == INVALID)
	{
		printf("INVALID Room Name\n");
		return;
	}
	if (rooms[room]->description == INVALID)
	{
		printf("INVALID Room Description\n");
		return;
	}
	printf(roomNames[rooms[room]->name]);
	printf("\n");
	printf(roomDescriptions[rooms[room]->description]);
	printf("\n");
}

