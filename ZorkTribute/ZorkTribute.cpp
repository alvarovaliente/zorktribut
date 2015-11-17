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
#include "Inventory.h"
#include "Enemy.h"
#include <iomanip>


using namespace std;


int main()
{

	string order;
	string item;
	vector <string>  suborders;

	Room *destroyedRoom = new Room("Destroyed room", "A room where everything is a mess and is half destroyed \n\t - Seems to be a door in the east and another one in the north", false, 0, true);
	Room *bathRoom = new Room("Destroyed bath room", "It's a bathroom completely destroyed with a fluorescent light blinking \n \t - Seems to be a door in the south", false, 1, false);
	Room *corridor = new Room("Desolated corridor", "A corridor half iluminated with conections to other rooms \n \t - Seems to be a door in the north, south and east", false, 1, false);
	Room *testingRoom = new Room("Testing lab room", "A testing lab where the people that were here research with radiation an animals \n \t ", false, 0, true);
	Room *maintenanceRoom = new Room("Maintenance room", "A maintenance room where these people keep of the cientific stuff. Maybe you can find something useful here. \n \t", false, 2, false);
	Room *finalRoom = new Room("Exit room","A room with a exit sign in the east \n", false, 1, false);
	Room *exit = new Room("Outside world"," \n \t \t CONGRATULATIONS! you are in the outside world!!! \n",false ,3,false);

	Room *wall = new Room("Wall", "You can't pass! It's a wall", false, 0, true);

	vector <Object> objectsDestroyedRoom;
	vector <Object> objectsBathroom;

	vector <Object> objectstestingRoom;
	vector <Object> objectsMaintenanceRoom;
	vector <Object> objectsFinalRoom;

	vector <Enemy> enemiesTestingRoom;
	vector <Enemy> enemiesFinalRoom;
	vector <Enemy> enemiesBathRoom;

	vector <Object> mutantDogDrop;
	vector <Object> superMutantDrop;

	Enemy *mutantFly = new Enemy("mutant fly","That's a huge shiny fly! ",5,2);
	Enemy *mutantDog = new Enemy("mutant dog","A mutant dog with a big mouth full of huge teeths",10,4);
	Enemy *superMutant = new Enemy("Super mutant", "A huge super mutant with crazy eyes and death hungry!", 18, 7);

	Object *rustyKnife = new Object("rusty knife", "A rusty knife! Seems you can still doing some damage with it.");
	Object *shootgun = new Object("shootgun", "And old shootgun but seems still firing");
	Object *accesskey = new Object("key","A access key to open some lab doors");
	Object *masterKey = new Object("masterkey","This key open the exit door");
	Object *destroyedJournal = new Object("destroyed Journal","A journal from the past decade semi destroyed.");
	Object *conservedMeat = new Object("conserved meat", "Some conserver meat that can restore your life");
	Object *stimulant = new Object("stimulant", "A stimulant that can restore your life");
	Object *dnaTransmutter = new Object("dna transmutter","A Dna Transmutter that can change this in this world. Seems very important.");
	Object *boost = new Object("boost", "A boost that increse your attack power");
	Object *waterBottle = new Object("water bottle", "A glass bottle full of water");
	
	
	//set objects in destroyed room
	objectsDestroyedRoom.push_back(*destroyedJournal);
	objectsDestroyedRoom.push_back(*rustyKnife);
	destroyedRoom->setObjectsInRoom(objectsDestroyedRoom);

	//set objects in bathroom
	objectsBathroom.push_back(*waterBottle);
	bathRoom->setObjectsInRoom(objectsBathroom);

	//set objects in testing room
	objectstestingRoom.push_back(*dnaTransmutter);
	objectstestingRoom.push_back(*stimulant);
	testingRoom->setObjectsInRoom(objectstestingRoom);

	//set objects in maintenance room
	objectsMaintenanceRoom.push_back(*conservedMeat);
	objectsMaintenanceRoom.push_back(*shootgun);
	maintenanceRoom->setObjectsInRoom(objectsMaintenanceRoom);

	//set drop objects for the mutant dog
	mutantDogDrop.push_back(*boost);
	mutantDogDrop.push_back(*accesskey);
	mutantDog->setDropObjects(mutantDogDrop);

	//set drop objects for the super mutant
	superMutantDrop.push_back(*masterKey);
	superMutant->setDropObjects(superMutantDrop);
	
	//setting the enemies in the rooms
	enemiesTestingRoom.push_back(*mutantDog);
	testingRoom->setEnemiesInRoom(enemiesTestingRoom);

	enemiesFinalRoom.push_back(*superMutant);
	finalRoom->setEnemiesInRoom(enemiesFinalRoom);

	enemiesBathRoom.push_back(*mutantFly);
	bathRoom->setEnemiesInRoom(enemiesBathRoom);

	//create all the connected map
	destroyedRoom->createExits(*bathRoom, *wall, *corridor, *wall, 0, 1, 0, 1);
	bathRoom->createExits(*wall, *destroyedRoom, *wall, *wall, 1, 0, 1, 1);
	corridor->createExits(*testingRoom, *maintenanceRoom, *finalRoom, *destroyedRoom, 0, 0, 0, 0);
	testingRoom->createExits(*wall, *corridor, *wall, *wall, 1, 0, 1, 1);
	maintenanceRoom->createExits(*corridor, *wall, *wall, *wall, 0, 1, 1, 1);
	finalRoom->createExits(*wall, *wall, *exit, *corridor, 1, 1, 0, 0);


	Player *player = new Player("Nick Montana", 0, 0, 10, 3, *destroyedRoom);

	bool exitGame = false;
	string order1;
	string order2;
	string orderDirection;


	cout << " \t \t \t WELCOME TO ZORKALYPTIC \n";

	cout << " \n An apocalyptic text adventure game based on the idea of Zork and ambiented in a post-apocalyptic future by Alvaro Valiente. \n";

	cout << "\n You are in an abandoned laboratory, try to escape ;) \n";

	cout << "\n" << setfill('-') << setw(90);

	while (!exitGame)
	{
		cout << "\n\n MOVES: " << player->getMoves() << "\t SCORE: " << player->getScore() << "\t LIFE: " << player->getLife() << " ->";

		getline(cin, order);
	

		if (order == "") { order = "incorrect"; }
		
			
		istringstream iss(order);
			while (iss >> item)
				suborders.push_back(item);

			int nMovesAux = player->getMoves();
			player->setMoves(++nMovesAux);
		
		if (suborders.size() > 4) { suborders[0] = "incorrect"; }


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
					cout << "\n Specify a direction to open the door! \n";
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
				if (suborders[1] == "door" && suborders.size() >2)
				{
					if (suborders.size() > 2)
					{
						player->closeDoor(*player->getActualRoom(), suborders[2]);
					}
					else
					{
						cout << "\n Specify a direction to close the door! \n";
					}			
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
				cout << "\n What should I look bro?! \n";
			}
		}
		//Pick order
		else if (suborders[0] == "pick")
		{
			if (suborders.size() > 1)
			{
				player->pickObject(suborders[1]);
			}
			else
			{
				cout << "\n What should I pick bro?! \n";
			}
		}
		//Drop order
		else if (suborders[0] == "drop")
		{
			if (suborders.size() > 1)
			{
				player->dropObject(suborders[1]);
			}
			else
			{
				cout << "\n What should I drop bro?! \n";
			}
		}
		//Use order
		else if (suborders[0] == "use")
		{
			if (suborders.size() == 2)
			{
				player->useObject(suborders[1]);
			}
			else
			{
				cout << "\n What should I use bro?! \n";
			}
		}
		//Attack
		else if (suborders[0] == "attack")
		{
			if (suborders.size() == 2)
			{
				player->attack(suborders[1],"hands");
			}
			else if (suborders.size() > 2)
			{
				if (suborders[2] == "with")
				{
					player->attack(suborders[1], suborders[3]);
				}
				else
				{
					cout << "\n Which with weapon should I attack bro!?\n";
				}
			}
			else
			{
				cout << "\n What should I attack bro?! \n";
			}
		}
		//Inventory order
		else if (suborders[0] == "inventory")
		{
			Inventory inventoryAux = player->getInventory();
			
			inventoryAux.checkInventory();
		}
		//Exit game order
		else if (suborders[0] == "exit")
		{
			exitGame = true;
			break;
		}
		else
		{
			cout << "\n I don't recognise that order bro! \n";
		}

		iss.clear();
		suborders.clear();

		if (player->getLife() <= 0)
		{
			exitGame = true;
		}

		if (player->getActualRoom()->getName() == "Outside world")
		{
			exitGame = true;
		}
	}

	system("pause");
}




