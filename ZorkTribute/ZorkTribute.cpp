// ZorkTribute.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <stdio.h>
#include "Player.h"
#include "Room.h"
#include "Object.h"
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>


using namespace std;


int main()
{

	string order;
	string item;
	vector <string>  suborders;

	Room *room1 = new Room("Living room", "It's a nice living room with a futuristic forniture \n\n Seems to be a door in the north ", false, 0, true);
	Room *room2 = new Room("Bed room", "A fucking awesome room with a nice bed to fuck \n \n Seems to be a door in the south", false, 1, false);
	Room *wall = new Room("Wall", "You can't pass! It's a wall", false, 0, true);

	vector <Object> objectsRoom2;
	Object *key = new Object("Key", "A key for open some doors.");
	Object *waterBottle = new Object("Water Bottle", "A glass bottle full of water");

	objectsRoom2.push_back(*key);
	objectsRoom2.push_back(*waterBottle);

	room2->setObjectsInRoom(objectsRoom2);


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

		getline(cin, order);

		istringstream iss(order);


		while (iss >> item)
			suborders.push_back(item);


		//Go order
		if (suborders[0] == "go")
		{
			if (suborders.size() > 1)
			{
				if (suborders[1] == "north")
				{
					player->goNorth(*player->getActualRoom());
				}
				else if (suborders[1] == "south")
				{
					player->goSouth(*player->getActualRoom());
				}
				else if (suborders[1] == "east")
				{
					player->goEast(*player->getActualRoom());
				}
				else if (suborders[1] == "west")
				{
					player->goWest(*player->getActualRoom());
				}
			}
			else
			{
				cout << "\n I don't know where you wanna go! Be more explicit! \n";
			}
			
		}
		//Open order
		else if (suborders[0] == "open")
		{
			if (suborders.size() > 1)
			{
				if (suborders[1] == "door" && suborders.size() >2)
				{
					if (suborders.size() > 2)
					{
						player->openDoor(*player->getActualRoom(), suborders[2]);
					}
						
				}
				else
				{
					cout << "\n Specify a direction to open the door!";
				}
			}
			else
			{
				cout << "\n What do u wanna open mate?! \n";
			}
		}
		//Close order
		else if (suborders[0] == "close")
		{
			if (suborders.size() > 1)
			{
				if (suborders[1] == "door")
				{
					cout << "\n Specify a direction to close the door!: ";
					cin >> orderDirection;
					player->closeDoor(*player->getActualRoom(), orderDirection);
				}
			}
			else
			{
				cout << "\n What do u wanna close mate!?\n";
			}
		}
		//Look order
		else if (suborders[0] == "look")
		{
			if (suborders.size() > 1)
			{
				if (suborders[1] == "around")
				{
					player->lookAround(*player->getActualRoom());
				}
			}	
			else
			{
				cout << "\n What should I look?! \n";
			}
		}
		//Exit game order
		else if (suborders[0] == "exit")
		{
			exitGame = true;
			break;
		}

		else
		{
			cout << "\n I don't recognise that order bru! \n";
		}

		iss.clear();
		suborders.clear();
	}

	system("pause");
}



