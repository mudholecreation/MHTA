#include "TextAdventure.h"

int main()
{
	char inputString[MAX_INPUT_LENGTH] = "";

	Display(title);

	while (true)
	{
		GetInput(inputString);
		Lower(inputString);
		Execute(inputString);
		Clear(inputString);
	}
	return 0;
}