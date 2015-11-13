#include "stdafx.h"
#include "Player.h"


using namespace std;


Player::Player(string n, int s, int m, Room &ac)
{
	name = n;
	score = s;
	moves = m;
	actualRoom = &ac;
	playerInventory = new Inventory();
}

string const Player::getName()
{
	return name;
}

void Player::setName(string n)
{
	name = n;
}

int const Player::getScore()
{
	return score;
}

void Player::setScore(int s)
{
	score = s;
}

int const Player::getMoves()
{
	return moves;
}

void Player::setMoves(int m)
{
	moves = m;
}

Room * const Player::getActualRoom()
{
	return actualRoom;
}

void Player::setActualRoom(Room &ar)
{
	actualRoom = &ar;
}

void  Player::goNorth(Room &ar)
{
	if (ar.getWalls()[0] == 0)
	{
		if (ar.getNorth()->getDoorOpen() == true)
		{		
			this->setActualRoom(*ar.getNorth());
			this->lookAround(ar);
		}
		else if(ar.getNorth()->getDoorOpen() == false)
		{
			cout << "\nThe door is closed!\n";
		}
	}
	else
	{
		this->itsWall();
	}


}
void Player::goSouth(Room &ar)
{
	if (ar.getWalls()[1] == 0)
	{
		if (ar.getSouth()->getDoorOpen() == true)
		{
			this->setActualRoom(*ar.getSouth());
			this->lookAround(ar);
		}
		else if (ar.getSouth()->getDoorOpen() == false)
		{
			cout << "\nThe door is closed!\n";
		}
	}
	else
	{
		this->itsWall();
	}
}

void Player::goEast(Room &ar)
{
	if (ar.getWalls()[2] == 0)
	{
		if (ar.getEast()->getDoorOpen() == true)
		{
			this->setActualRoom(*ar.getEast());
			this->lookAround(ar);
		}
		else if (ar.getEast()->getDoorOpen() == false && ar.getEast()->getDoor() == 1)//door closed, need to be opened manually
		{
			cout << "\nThe door is closed!\n";
		}
		else if (ar.getEast()->getDoorOpen() == false && ar.getEast()->getDoor() == 2)//dor closed by key
		{
			cout << "\nThe door seems to need a key to be opened!\n";
		}
	}
	else
	{
		this->itsWall();
	}
}

void Player::goWest(Room &ar)
{
	if (ar.getWalls()[3] == 0)
	{
		if (ar.getWest()->getDoorOpen() == true)
		{
			this->setActualRoom(*ar.getWest());
			this->lookAround(ar);
		}
		else if (ar.getWest()->getDoorOpen() == false)
		{
			cout << "\nThe door is closed!\n";
		}
	}
	else
	{
		this->itsWall();
	}
}

void const Player::lookAround(Room &ar)
{
	cout << "\nYou are in the " << this->getActualRoom()->getName() << "\n";
	cout << this->getActualRoom()->getDescription() << "\n";
	cout << "\n";

	this->getActualRoom()->listObjectsInRoom();
}

void Player::pickObject(string n)
{
	vector <Object> objectsInRoomAux = this->actualRoom->getObjectsInRoom();

	vector <Object>::iterator it = objectsInRoomAux.begin();

	for (it; it != objectsInRoomAux.end(); it++)
	{
		int check = it->getName().find(n);//check the first ocurrence of the word

		if (check >= 0) //means we have an ocurrence
		{
			//if the substring is equal the object can be picked
			if (it->getName().substr(check, it->getName().length()) == n)
			{
				playerInventory->addObjectToInventory(*it);
				actualRoom->removeObjectInRoomByName(it->getName());

				cout << "\n" << it->getName() << " picked!! \n";

				int scoreAux = this->getScore();
				this->setScore(scoreAux += 5);

				break;
			}
		}	
	}

	if (it == objectsInRoomAux.end()) {
		cout << "\n I don't see any object like this in this room!! \n";
	}
	
}

void Player::dropObject(string n)
{
	vector <Object> objectsInRoomAux = actualRoom->getObjectsInRoom();

	vector <Object> objectsInventary = playerInventory->getObjectsIn();

	vector <Object>::iterator it = objectsInventary.begin();

	int flag = 0;

	for (it; it != objectsInventary.end(); it++)
	{
		int check = it->getName().find(n);//check the first ocurrence of the word

		if (check >= 0) //means we have an ocurrence
		{
			//if the substring is equal the object can be droped
			if (it->getName().substr(check, it->getName().length()) == n)
			{
				objectsInRoomAux.push_back(*it);
				objectsInventary.erase(it);

				actualRoom->setObjectsInRoom(objectsInRoomAux);
				this->playerInventory->setObjectsIn(objectsInventary);

				cout << "\n" << n << " droped!! \n";
				flag = 1;
				break;
			}
		}
	}

	if (!flag) {
		cout << "\n I don't see any object like this in the inventory!! \n";
	}
}

void Player::useObject(string n)
{
	vector <Object> objectsInventary = playerInventory->getObjectsIn();

	vector <Object>::iterator it = objectsInventary.begin();

	int flag = 0;

	for (it; it != objectsInventary.end(); it++)
	{
		int check = it->getName().find(n);//check the first ocurrence of the word

		if (check >= 0) //means we have an ocurrence
		{
			//if the substring is equal the object means we have it in the inventory
			if (it->getName().substr(check, it->getName().length()) == n)
			{
				flag = 1;

				if (it->getName().substr(check, it->getName().length()) == "key")
				{
					string dirAux;
					cout << "\n Which direction should I use the key? \n";
					cout << "->";
					cin >> dirAux;

					if (dirAux == "north")
					{
						
					}
					else if (dirAux == "south")
					{

					}
					else if (dirAux == "east")
					{
						if (this->actualRoom->getEast()->getDoor() == 2) //means that the door needs a key to be open
						{
							if (this->actualRoom->getEast()->getDoorOpen() == false)
							{
								this->actualRoom->getEast()->setDoorOpen(true);
								cout << "\n Door opened! You can enter now!\n";							
							}
							else
							{
								cout << "\n The door it's already open! \n";
							}
						}
					}
					else if (dirAux == "west")
					{

					}
					else
					{
						cout << "\n I don't recognise that direction! \n";
					}
					

				}

				if (it->getName().substr(check, it->getName().length()) == "bottle")
				{
					cout << "\nYou drink fresk water! \n";
				}
			}

		}
	}

	if (!flag) {
		cout << "\n I don't see any object like this in the inventory!! \n";
	}
}

Inventory const  Player::getInventory()
{
	return *playerInventory;
}

void const Player::itsWall()
{
	cout << "\nYou can't go over there! There is a wall! \n";
}

void Player::openDoor(Room &ar, string dir)
{
	if (dir == "north")
	{
		if (ar.getNorth()->getDoorOpen() == true)
		{
			cout << "\n The door it's already open!\n";
		}
		else
		{
			if (ar.getNorth()->getDoor() == 1 && ar.getNorth()->getDoorOpen() == false) 
			{
				ar.getNorth()->setDoorOpen(true);
				cout << "\n Door opened! You can enter now!\n";

				int scoreAux = this->getScore();
				this->setScore(scoreAux+=5);
			}
			else
			{
				cout << "\nThere is no door to be open!\n";
			}
		}
		
	}
	else if (dir == "south")
	{
		if (ar.getSouth()->getDoorOpen() == true)
		{
			cout << "\n The door it's already open!\n";
		}
		else
		{
			if (ar.getSouth()->getDoor() == 1 || ar.getSouth()->getDoorOpen() == false)
			{
				ar.getSouth()->setDoorOpen(true);
				cout << "\n Door opened! You can enter now!\n";

				int scoreAux = this->getScore();
				this->setScore(scoreAux += 5);
			}
			else
			{
				cout << "\nThere is no door to be open!\n";
			}
		}
	}
	else if (dir == "east")
	{
		if (ar.getEast()->getDoorOpen() == true)
		{
			cout << "\n The door it's already open!\n";
		}
		else
		{
			if (ar.getEast()->getDoor() == 1 && ar.getEast()->getDoorOpen() == false)
			{
				ar.getEast()->setDoorOpen(true);
				cout << "\n Door opened! You can enter now!\n";

				int scoreAux = this->getScore();
				this->setScore(scoreAux += 5);
			}
			else
			{
				cout << "\nThere is no door to be open!\n";
			}
		}
	}
	else if (dir == "west")
	{
		if (ar.getWest()->getDoorOpen() == true)
		{
			cout << "\n The door it's already open!\n";
		}
		else
		{
			if (ar.getEast()->getDoor() == 1 || ar.getEast()->getDoorOpen() == false)
			{
				ar.getEast()->setDoorOpen(true);
				cout << "\n Door opened! You can enter now!\n";

				int scoreAux = this->getScore();
				this->setScore(scoreAux += 5);
			}
			else
			{
				cout << "\nThere is no door to be open!\n";
			}
		}

	}
	else
	{
		cout << "\nI don't recognise that direction!\n";
	}

}

void Player::closeDoor(Room &ar, string dir)
{
	if (dir == "north")
	{
		if (ar.getNorth()->getDoorOpen() == false)
		{
			cout << "\n The door it's already closed!\n";
		}
		else
		{
			if (ar.getNorth()->getDoor() == 1 && ar.getNorth()->getDoorOpen() == true)
			{
				ar.getNorth()->setDoorOpen(false);
				cout << "\n Door closed!\n";
			}
			else
			{
				cout << "\nThere is no door to be closed!\n";
			}
		}

	}
	else if (dir == "south")
	{
		if (ar.getSouth()->getDoorOpen() == false)
		{
			cout << "\n The door it's already closed!\n";
		}
		else
		{
			if (ar.getSouth()->getDoor() == 1 || ar.getSouth()->getDoorOpen() == true)
			{
				ar.getSouth()->setDoorOpen(false);
				cout << "\n Door closed!\n";
			}
			else
			{
				cout << "\nThere is no door to be closed!\n";
			}
		}
	}
	else if (dir == "east")
	{
		if (ar.getEast()->getDoorOpen() == false)
		{
			cout << "\n The door it's already closed!\n";
		}
		else
		{
			if (ar.getEast()->getDoor() == 1 || ar.getEast()->getDoorOpen() == true)
			{
				ar.getEast()->setDoorOpen(false);
				cout << "\n Door closed!\n";
			}
			else
			{
				cout << "\nThere is no door to be closed!\n";
			}
		}
	}
	else if (dir == "west")
	{
		if (ar.getWest()->getDoorOpen() == false)
		{
			cout << "\n The door it's already closed!\n";
		}
		else
		{
			if (ar.getEast()->getDoor() == 1 || ar.getEast()->getDoorOpen() == true)
			{
				ar.getEast()->setDoorOpen(false);
				cout << "\n Door closed!\n";
			}
			else
			{
				cout << "\nThere is no door to be closed!\n";
			}
		}

	}
	else
	{
		cout << "\nI don't recognise that direction!\n";
	}
}

