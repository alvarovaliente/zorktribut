#pragma once
#include "stdafx.h"
#include <string>
#include "Object.h"
#include <vector>
#include <iostream>

using namespace std;

class Room {

private:
	//Members
	string name;
	string description;
	bool isPLayerInside;
	Room *north;
	Room *south;
	Room *west;
	Room *east;
	int door; //depending on the number the door can be in different states 0= open, 1= close (have to open it), 2= have to force it
	bool doorOpen;
	int walls[4];
	vector <Object> objectsInRoom;
	


public:

	//Constructor
	Room(string name, string description, bool isInside, int d, bool dopen);

	//Methods
	string const getName();
	void setName(string );

	string const getDescription();
	void setDescription(string);

	Room * const getNorth();
	void setNorth(Room &n);

	Room * const getSouth();
	void setSouth(Room &s);

	Room * const getWest();
	void setWest(Room &w);

	Room * const getEast();
	void setEast(Room &e);

	int const getDoor();
	void setDoor(int);

	bool const getDoorOpen();
	void setDoorOpen(bool);

	int * const getWalls();
	void setWalls(int *);

	vector <Object> const getObjectsInRoom();
	void setObjectsInRoom(vector <Object> &o);

	void const listObjectsInRoom();
	void removeObjectInRoomByName(string n); 

	void createExits(Room &north, Room &south, Room &east, Room &west, int n, int s, int e, int w);

	//Destructor
	~Room();
};
