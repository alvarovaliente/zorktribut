#pragma once
#include "stdafx.h"
#include "Room.h"
#include <iostream>
#include <string>

using namespace std;

class Player {

private:
	
	string name;
	int score;
	int moves;
	Room *actualRoom;

	
public:

	Player(string n, int s, int m, Room &ac);

	string const getName();
	void setName(string n);

	int const getScore();
	void setScore(int s);

	int const getMoves();
	void setMoves(int m);

	Room * const getActualRoom();
	void setActualRoom(Room &ar);

	void goNorth( Room &);
	void goSouth(Room &);
	void goEast(Room &);
	void goWest(Room &);

	void const lookAround(Room &ar);

	void const itsWall();

	void openDoor(Room &ar, string dir);
	void closeDoor(Room &ar, string dir);

	~Player();

};