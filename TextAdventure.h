#pragma once
#include <stdio.h>

const unsigned char MAX_WORD_LENGTH = 16;
const unsigned char MAX_SENTENCE_LENGTH = 64;
const unsigned char MAX_WORD_COUNT = 32;

enum class WordType
{
	INVALID_WORD,
	VERB,
	ROOM,
	OBJECT,
	CHARACTER,
	CONJUCTION
};

struct Word
{
	char string[MAX_WORD_LENGTH] = {};
	WordType type = WordType::INVALID_WORD;
};

struct Noun
{
	char name[MAX_WORD_LENGTH] = {};
	char description[MAX_SENTENCE_LENGTH] = "";
};

enum RoomFlag
{
	INVALID_ROOM,
	LIT,
	LOCKED,
};

enum ObjectFlag
{
	INVALID_OBJECT,
	PICKUP,
	EQUIPTED,
};

enum CharacterFlag
{
	INVALID_CHARACTER,
};


struct Room : Noun
{
	Room* up = nullptr;
	Room* down = nullptr;
	Room* north = nullptr;
	Room* south = nullptr;
	Room* east = nullptr;
	Room* west = nullptr;
	int flags = INVALID_ROOM;
};

struct Object : Noun
{
	Room* room = nullptr;
	int flags = INVALID_OBJECT;
};

struct Character : Noun
{
	Room* room = nullptr;
	int health = 0;
	int flags = INVALID_CHARACTER;
};

void DisplayName(Noun* noun);
void DisplayDescription(Noun* noun);
void DisplayRoom(Room* room);
void DisplayUnknownWord(char* inputString);

void GetInput(char* inputString);
void LowerInput(char* inputString);
void ClearInput(char* inputString);

bool FindWordType(char* inputString, Word* words, Word*& word);
bool FindWord(char*& inputString);

//struct Pickup : Noun
//{
//	Room* room = nullptr;
//
//};
//
//struct Weapon : Pickup
//{
//	unsigned char damage = 0;
//};
//
//struct Lock : Noun
//{
//
//};
//
//struct Key : Pickup
//{
//	//ToDo:
//};
//
//struct Entity : Noun
//{
//	Room* room = nullptr;
//	unsigned char health = 0;
//};
//
//struct Enemy : Entity
//{
//};
//
//struct Player : Entity
//{
//};
//
//Game* Create()
//{
//	return new Game();
//}
//void Save(Game* game)
//{
//}
//void Destroy(Game* game)
//{
//}
//bool Execute(Game* game)
//{
//	return false;
//}
//bool FindNoun(Game* game)
//{
//	return false;
//}
//bool FindVerb(Game* game)
//{
//	return false;
//}



///////////////////////////////////////////////////////////////////////////////////////////////////////////
//Issues 
//Light, Maybe a timer for the sun
//Locations of rooms


///////////////////////////////////////////////////////////////////////////////////////////////////////////
//int size = sizeof(verbs) / MAX_WORD_LENGTH;
//for (size_t i = 0; i < size; i++)
//{
//	if (CompareString(word, verbs[i]))
//	{
//		verb = i;
//		return true;
//	}
//}
//void DisplayFirstWord(char* word)
//{
//	for (; *word != '\0' && *word != ' '; word++)
//	{
//		printf("%c", *word);
//	}
//	printf("\n");
//}

//

//
////bool FindSubject(char* word, int& subject)
////{
////	int size = sizeof(nouns) / MAX_WORD_LENGTH;
////	for (size_t i = 0; i < size; i++)
////	{
////		if (CompareString(word, nouns[i]))
////		{
////			noun = i;
////			return true;
////		}
////	}
////
////	return false;
////}
////
////bool FindVerb(char* word, int& verb)
////{
////	int size = sizeof(verbs) / MAX_WORD_LENGTH;
////	for (size_t i = 0; i < size; i++)
////	{
////		if (CompareString(word, verbs[i]))
////		{
////			verb = i;
////			return true;
////		}
////	}
////	return false;
////}
//
//void Advance(char*& pos)
//{
//	while (*pos != '\0')
//	{
//		pos++;
//		if (*pos == ' ')
//		{
//			break;
//		}
//	}
//}
//


//void Clear(char* string)
//{

//}
//
//void Execute(char* inputString)
//{
//	int verb = -1;
//	int noun = -1;
//
//	char* pos = &inputString[0];
//
//	while (*pos != '\0')
//	{
//		if (!FindWord(pos))
//		{
//			pos++;
//			continue;
//		}
//
//		//if (FindVerb(pos, verb))
//		//{
//		//	printf("Found Verb: ");
//		//	DisplayFirstWord(pos);
//		//}
//
//		//if (FindSubject(pos, noun))
//		//{
//		//	printf("Found Subject: ");
//		//	DisplayFirstWord(pos);
//		//}
//
//		//if (FindObject(pos, noun))
//		//{
//		//	printf("Found Subject: ");
//		//	DisplayFirstWord(pos);
//		//}
//
//		//if (!Decipher(verb, noun))
//		//{
//		//	printf("I don't understand.\n");
//		//}
//		Advance(pos);
//	}
//
//}




///////////////////////////////////////////////////////////////////////////////////////////////////////////
//Zork 3
// 
//#1 know every word
// 
//I dont know the word "blank"
//There is no verb in the sentence
//only one direction
//you used "verb" in a way I dont understand
//Only one word per word type if not ^
//Equipt last item picked up
//"Turn on lamp", took lamp and turned it on
//"Take lamp and turn on", took lamp and turned it on.
//2 verbs in a row, "You used the word "2nd verb" in a way that I dont understand."
//lksdfj drop, drop lksdfj, I dont know the word "lksjdf"
