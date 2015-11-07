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

void Room::createExits(Room &n, Room &s, Room &e, Room &w, int nor, int sou, int ea, int we)
{
	north = &n;
	south = &s;
	west = &w;
	east = &e;

	walls[0] = nor;
	walls[1] = sou;
	walls[2] = ea;
	walls[3] = we;
}