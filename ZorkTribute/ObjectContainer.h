#pragma once
#include "Object.h"
#include <vector>
#include <string>

class ObjectContainer: public Object
{
private:

	vector <Object> objectsInContainer;

public:

	void const getObjectsInContainer();
	vector <Object> setObjectsInContainer(vector <Object> obs);



};
