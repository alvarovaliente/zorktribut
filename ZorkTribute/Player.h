#pragma once
#include "stdafx.h"
#include "Room.h"
#include <iostream>
#include <string>
#include "Inventory.h"
#include <random>
#include <time.h>

using namespace std;

class Player {

private:
	
	string name;
	int score;
	int moves;
	int life;
	int powerAttack;
	Room *actualRoom;
	Inventory *playerInventory;

	
public:

	Player(string n, int s, int m, int l, int pa, Room &ac);

	string const getName();
	void setName(string n);

	int const getScore();
	void setScore(int s);

	int const getMoves();
	void setMoves(int m);

	int const getLife();
	void setLife(int l);

	int const getPowerAttack();
	void setPowerAttack(int pa);

	Room * const getActualRoom();
	void setActualRoom(Room &ar);

	void goNorth( Room &);
	void goSouth(Room &);
	void goEast(Room &);
	void goWest(Room &);

	void const lookAround(Room &ar);
	void const lookInventory();
	Inventory  const getInventory();

	void pickObject(string n);
	void dropObject(string n); 
	void useObject(string n);

	void attack(string n,string w);

	void const itsWall();

	void openDoor(Room &ar, string dir);
	void closeDoor(Room &ar, string dir);

	void openObject(string n);

	~Player();

};