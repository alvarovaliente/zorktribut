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
		if (ar.getNorth()->getDoor() == 0)
		{		
			this->setActualRoom(*ar.getNorth());
			this->lookAround(ar);
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
		if (ar.getSouth()->getDoor() == 0)
		{
			this->setActualRoom(*ar.getSouth());
			this->lookAround(ar);
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
		if (ar.getEast()->getDoor() == 0)
		{
			this->setActualRoom(*ar.getEast());
			this->lookAround(ar);
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
		if (ar.getWest()->getDoor() == 0)
		{
			this->setActualRoom(*ar.getWest());
			
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

