#include "stdafx.h"
#include "Enemy.h"
#include <string>


Enemy::Enemy(string n, string d, int l, int pa)
{
	name = n;
	description = d;
	life = l;
	powerAttack = pa;
}


string const Enemy::getName()
{
	return name;
}

void Enemy::setName(string n)
{
	name = n;
}

string const Enemy::getDescription()
{
	return description;
}

void Enemy::setDescription(string d)
{
	description = d;
}

int const Enemy::getLife()
{
	return life;
}

void Enemy::setLife(int l)
{
	life = l;
}


int const Enemy::getPowerAttack()
{
	return powerAttack;
}

void Enemy::setPowerAttack(int pa)
{
	powerAttack = pa;
}

vector <Object> const Enemy::getDropObjects()
{
	return dropObjects;
}

void Enemy::setDropObjects(vector <Object> dropObj)
{
	dropObjects = dropObj;
}