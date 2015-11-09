#pragma once
#include <vector>
#include "Object.h"
#include <iostream>


class Inventory
{

private:

	vector <Object> objectsIn;


public:

	Inventory();

	vector <Object> const getObjectsIn();
	void setObjectsIn(vector <Object> oi);

	void addObjectToInventory(Object o);

	Object const getObjectByName(string n);

	~Inventory();
};