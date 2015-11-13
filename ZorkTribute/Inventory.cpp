#include "stdafx.h"
#include "Inventory.h"


vector <Object> const Inventory::getObjectsIn()
{
	return objectsIn;
}

void Inventory::setObjectsIn(vector <Object> oi)
{
	objectsIn = oi;
}

Object const Inventory::getObjectByName(string n)
{
	vector <Object> objectsAux = this->getObjectsIn();

	if (objectsAux.size() > 0)
	{
		vector <Object>::iterator it = objectsAux.begin();

		for (it; it != objectsAux.end(); it++)
		{
			if (it->getName() == n)
			{
				return *it;
			}
		}

		cout << "\n You don't have that object in the inventory bro!! \n";
	}
	else
	{
		cout << "\n Your inventory is empty bro!! \n";
	}
}

void Inventory::addObjectToInventory(Object o) 
{
	vector <Object> objectsInAux = this->getObjectsIn();

	objectsInAux.push_back(o);

	this->setObjectsIn(objectsInAux);

}

void const Inventory::checkInventory()
{
	vector <Object> objectsInAux = this->getObjectsIn();

	vector <Object>::iterator it = objectsInAux.begin();

	if (objectsInAux.size() > 0)
	{
		cout << "\nInventory list:\n";

		for (it; it != objectsInAux.end(); it++)
		{
			cout << it->getName();
			cout << "\n";
		}
	}
	else
	{
		cout << "\n No objects in the inventory! \n";
	}

}