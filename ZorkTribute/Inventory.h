#pragma once
#include <vector>
#include "Object.h"
#include <iostream>


class Inventory
{

private:

	vector <Object> objectsIn;


public:

	vector <Object> const getObjectsIn();
	void setObjectsIn(vector <Object> oi);

	void addObjectToInventory(Object o);

	void const checkInventory();

	Object const getObjectByName(string n);


};