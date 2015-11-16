#pragma once
#include "stdafx.h"
#include <string>
#include "Object.h"
#include <vector>

using namespace std;

class Enemy
{
private:

	string name;
	string description;
	int life;
	int powerAttack;
	vector <Object> dropObjects;

public:

	//Constructor
	Enemy(string n, string d, int l, int pa);

	//Methods

	string const getName();
	void setName(string n);

	string const getDescription();
	void setDescription(string d);

	int const getLife();
	void setLife(int l);

	int const getPowerAttack();
	void setPowerAttack(int pa);

	vector <Object> const getDropObjects();
	void setDropObjects(vector <Object> dropObj);

	


	
};
