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