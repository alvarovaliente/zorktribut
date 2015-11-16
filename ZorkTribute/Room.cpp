#include "stdafx.h"
#include "Room.h"

using namespace std;

Room::Room(string nm, string des, bool isInside, int d, bool dopen)
{
	name = nm;
	description = des;
	isPLayerInside = isInside;
	door = d;
	doorOpen = dopen;
}

string const Room::getName()
{
	return name;
}

void Room::setName(string n)
{
	name = n;
}

string const Room::getDescription()
{
	return description;
}

void Room::setDescription(string d)
{
	description = d;
}

Room * const Room:: getNorth()
{
	return north;
}

void Room::setNorth(Room &n)
{
	north = &n;
}

Room * const Room::getSouth()
{
	return south;
}

void Room::setSouth(Room &s)
{
	south = &s;
}

Room * const Room::getWest()
{
	return west;
}

void Room::setWest(Room &w)
{
	west = &w;
}

Room * const Room::getEast()
{
	return east;
}

void Room::setEast(Room &e)
{
	east = &e;
}

int const Room::getDoor()
{
	return door;
}

void Room::setDoor(int d)
{
	door = d;
}

bool const Room::getDoorOpen()
{
	return doorOpen;
}

void Room::setDoorOpen(bool d)
{
	doorOpen = d;
}

int * const Room::getWalls()
{
	return walls;
}

vector <Object> const Room::getObjectsInRoom()
{
	return objectsInRoom;
}

void Room::setObjectsInRoom(vector <Object> &o)
{
	objectsInRoom = o;
}

void const Room::listObjectsInRoom()
{
	vector <Object> objects = getObjectsInRoom();

	if (objects.size() > 0)
	{
		vector <Object>::iterator it = objects.begin();
		cout << "List of objects in this room: \n";

		for (it; it != objects.end(); it++)
		{
			cout << "\n";
			cout << "\t - ";
			cout << it->getName();
			cout << ": ";
			cout << it->getDescription();
		}
	}
}

void Room::removeObjectInRoomByName(string n)
{
	vector <Object> objectsAux = getObjectsInRoom();

	vector <Object>::iterator it = objectsAux.begin();

	for (it; it != objectsAux.end(); it++)
	{
		if (it->getName() == n)
		{
			objectsAux.erase(it);
			break;
		}
	}

	this->setObjectsInRoom(objectsAux);
}

void const Room::listEnemiesInRoom()
{
	vector <Enemy> enemiesAux = getEnemiesInRoom();

	if (enemiesAux.size() > 0)
	{
		vector <Enemy>::iterator it = enemiesAux.begin();

		cout << "Warning! Seems to be ememies in the room! \n";

		for (it; it != enemiesAux.end(); it++)
		{
			cout << "\n";
			cout << "\t - ";
			cout << it->getName();
			cout << ": ";
			cout << it->getDescription();
		}

	}

	
}

vector <Enemy> const Room::getEnemiesInRoom()
{
	return enemiesInRoom;
}

void Room::setEnemiesInRoom(vector <Enemy> &e)
{
	enemiesInRoom = e;
}


void Room::createExits(Room &n, Room &s, Room &e, Room &w, int nor, int sou, int ea, int we)
{
	north = &n;
	south = &s;
	west = &w;
	east = &e;

	//0 = no wall, 1 = wall
	walls[0] = nor;
	walls[1] = sou;
	walls[2] = ea;
	walls[3] = we;
}