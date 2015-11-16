#pragma once
#include "stdafx.h"
#include <string>
#include "Object.h"
#include <vector>
#include <iostream>
#include "Enemy.h"

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
	int door; //the room has a door to enter and depending on the number the door can be in different states 0= open, 1= close (have to open it), 2= need a key
	bool doorOpen; //true = door is open false = door is closed
	int walls[4];
	vector <Object> objectsInRoom;
	vector <Enemy> enemiesInRoom;
	
	


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

	vector <Enemy> const getEnemiesInRoom();
	void setEnemiesInRoom(vector <Enemy> &e);

	void const listEnemiesInRoom();
	
	//foar rooms conected to this room and the int values are 0 = no wall, 1 = wall
	void createExits(Room &north, Room &south, Room &east, Room &west, int n, int s, int e, int w);

	//Destructor
	~Room();
};
