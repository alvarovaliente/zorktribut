#pragma once
#include <string>

using namespace std;

class Object
{
private:

	string name;
	string description;


public:

	Object(string n, string d);

	string const getName();
	void setName(string n);

	string const getDescription();
	void setDescription(string d);

	//~Object();

};