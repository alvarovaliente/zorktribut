#include "stdafx.h"
#include "Object.h"

Object::Object(string n, string d)
{
	name = n;
	description = d;
}

string const Object::getName()
{
	return name;
}

void Object::setName(string n)
{
	name = n;
}

string const Object::getDescription()
{
	return description;
}

void Object::setDescription(string d)
{
	description = d;
}