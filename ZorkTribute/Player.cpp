#include "stdafx.h"
#include "Player.h"


using namespace std;


Player::Player(string n, int s, int m, Room &ac)
{
	name = n;
	score = s;
	moves = m;
	actualRoom = &ac;
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
		else if (ar.getEast()->getDoorOpen() == false)
		{
			cout << "\nThe door is closed!\n";
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
	cout << "\n You are in the " << this->getActualRoom()->getName() << "\n";
	cout << "\n" << this->getActualRoom()->getDescription() << "\n";
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
			if (ar.getNorth()->getDoor() == 1 || ar.getNorth()->getDoorOpen() == false)
			{
				ar.getNorth()->setDoorOpen(true);
				cout << "\n Door opened! You can enter now!\n";
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
			if (ar.getEast()->getDoor() == 1 || ar.getEast()->getDoorOpen() == false)
			{
				ar.getEast()->setDoorOpen(true);
				cout << "\n Door opened! You can enter now!\n";
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
			if (ar.getNorth()->getDoor() == 1 || ar.getNorth()->getDoorOpen() == true)
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

