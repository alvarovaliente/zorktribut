#pragma once
#include "stdafx.h"
#include <string>

using namespace std;

class Enemy
{
private:

	string name;
	string description;
	int life;
	int powerAttack;

public:

	//Constructor
	Enemy(string n, string d, int l, int pa);

	//Methods

	string const getName();
	void setName(string n);

	string const getDescription();
	void setDescription();

	int const getLife();
	void setLife(int l);

	int const getPowerAttack();
	void setPowerAttack(int pa);
	


	
};
