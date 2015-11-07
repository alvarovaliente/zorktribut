// ZorkTribute.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <stdio.h>
#include "Player.h"
#include "Room.h"
#include <iostream>

using namespace std;


int main()
{
	Room *room1 = new Room("Living room", "It's a nice living room with a futuristic forniture \n\n Seems to be a door in the north ", false, 0, true);
	Room *room2 = new Room("Bed room", "A fucking awesome room with a nice bed to fuck \n \n Seems to be a door in the south", false, 1, false);
	Room *wall = new Room("Wall", "You can't pass! It's a wall", false, 0, true);

	Player *player = new Player("Player1", 0, 0, *room1);

	bool exitGame = false;
	string order1;
	string order2;
	string orderDirection;
	

	room1->createExits(*room2,*wall, *wall,*wall,0,1,1,1);
	room2->createExits(*wall,*room1,*wall,*wall,1,0,1,1);

	while (!exitGame)
	{
		cout << "\n Enter your order:";
		cin >> order1 >> order2;

		if (order1 == "go")
		{
			if (order2 == "north")
			{
				player->goNorth(*player->getActualRoom());
			}

			if (order2 == "south")
			{
				player->goSouth(*player->getActualRoom());
			}

			if (order2 == "east")
			{
				player->goEast(*player->getActualRoom());
			}

			if (order2 == "west")
			{
				player->goWest(*player->getActualRoom());
			}
		}

		if (order1 == "open")
		{
			if (order2 == "door")
			{
				cout << "\n Specify a direction to open the door!: ";
				cin >> orderDirection;
				player->openDoor(*player->getActualRoom(),orderDirection);
			}
		}

		if (order1 == "close")
		{
			if (order2 == "door")
			{
				cout << "\n Specify a direction to close the door!: ";
				cin >> orderDirection;
				player->closeDoor(*player->getActualRoom(), orderDirection);
			}
		}

		if (order1 == "look" && order2 == "around")
		{
			player->lookAround(*player->getActualRoom());
		}
		else
		{
			cout << "\n What should I look?! \n";
		}

		if (order1 == "exit")
		{
			exitGame = true;
			break;
		}
	}

	system("pause");
}

