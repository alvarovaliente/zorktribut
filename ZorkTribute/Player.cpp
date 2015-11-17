#include "stdafx.h"
#include "Player.h"


using namespace std;


Player::Player(string n, int s, int m, int l, int pa, Room &ac)
{
	name = n;
	score = s;
	moves = m;
	life = l;
	powerAttack = pa;
	actualRoom = &ac;
	playerInventory = new Inventory();
}

string const Player::getName()
{
	return name;
}

void Player::setName(string n)
{
	name = n;
}

int const Player::getScore()
{
	return score;
}

void Player::setScore(int s)
{
	score = s;
}

int const Player::getMoves()
{
	return moves;
}

void Player::setMoves(int m)
{
	moves = m;
}

int const Player::getLife()
{
	return life;
}

void Player::setLife(int l)
{
	life = l;
}

int const Player::getPowerAttack()
{
	return powerAttack;
}

void Player::setPowerAttack(int pa)
{
	powerAttack = pa;
}

Room * const Player::getActualRoom()
{
	return actualRoom;
}

void Player::setActualRoom(Room &ar)
{
	actualRoom = &ar;
}

void  Player::goNorth(Room &ar)
{
	//if there is no wall in the north..
	if (ar.getWalls()[0] == 0)
	{
		if (ar.getNorth()->getDoorOpen() == true)
		{		
			this->setActualRoom(*ar.getNorth());
			this->lookAround(ar);
		}//door closed, need to be opened manually
		else if (ar.getNorth()->getDoorOpen() == false && ar.getNorth()->getDoor() == 1)
		{
			cout << "\nThe door is closed!\n";
		}//door closed by key
		else if (ar.getNorth()->getDoorOpen() == false && ar.getNorth()->getDoor() == 2)
		{
			cout << "\nThe door seems to need a key to be opened!\n";
		}//closed by master key
		else if (ar.getNorth()->getDoorOpen() == false && ar.getNorth()->getDoor() == 3)
		{
			cout << "\nThe door seems to need a master key to be opened!\n";
		}
		
	}
	else
	{
		this->itsWall();
	}


}
void Player::goSouth(Room &ar)
{
	if (ar.getWalls()[1] == 0)
	{
		if (ar.getSouth()->getDoorOpen() == true)
		{
			this->setActualRoom(*ar.getSouth());
			this->lookAround(ar);
		}//door closed, need to be opened manually
		else if (ar.getSouth()->getDoorOpen() == false && ar.getSouth()->getDoor() == 1)
		{
			cout << "\nThe door is closed!\n";
		}//door closed by key
		else if (ar.getSouth()->getDoorOpen() == false && ar.getSouth()->getDoor() == 2)
		{
			cout << "\nThe door seems to need a key to be opened!\n";
		}//closed by master key
		else if (ar.getNorth()->getDoorOpen() == false && ar.getNorth()->getDoor() == 3)
		{
			cout << "\nThe door seems to need a master key to be opened!\n";
		}
	}
	else
	{
		this->itsWall();
	}
}

void Player::goEast(Room &ar)
{
	if (ar.getWalls()[2] == 0)
	{
		if (ar.getEast()->getDoorOpen() == true)
		{
			this->setActualRoom(*ar.getEast());
			this->lookAround(ar);
		}//door closed, need to be opened manually
		else if (ar.getEast()->getDoorOpen() == false && ar.getEast()->getDoor() == 1)
		{
			cout << "\nThe door is closed!\n";
		}//dor closed by key
		else if (ar.getEast()->getDoorOpen() == false && ar.getEast()->getDoor() == 2)
		{
			cout << "\nThe door seems to need a key to be opened!\n";
		}//closed by master key
		else if (ar.getNorth()->getDoorOpen() == false && ar.getNorth()->getDoor() == 3)
		{
			cout << "\nThe door seems to need a master key to be opened!\n";
		}
	}
	else
	{
		this->itsWall();
	}
}

void Player::goWest(Room &ar)
{
	if (ar.getWalls()[3] == 0)
	{
		if (ar.getWest()->getDoorOpen() == true)
		{
			this->setActualRoom(*ar.getWest());
			this->lookAround(ar);
		}//door closed, need to be opened manually
		else if (ar.getWest()->getDoorOpen() == false && ar.getWest()->getDoor() == 1)
		{
			cout << "\nThe door is closed!\n";
		}//dor closed by key
		else if (ar.getWest()->getDoorOpen() == false && ar.getWest()->getDoor() == 2)
		{
			cout << "\nThe door seems to need a key to be opened!\n";
		}//closed by master key
		else if (ar.getNorth()->getDoorOpen() == false && ar.getNorth()->getDoor() == 3)
		{
			cout << "\nThe door seems to need a master key to be opened!\n";
		}
	}
	else
	{
		this->itsWall();
	}
}

void const Player::lookAround(Room &ar)
{
	cout << "\nYou are in the " << this->getActualRoom()->getName() << "\n";
	cout << this->getActualRoom()->getDescription() << "\n";
	cout << "\n";

	this->getActualRoom()->listObjectsInRoom();

	this->getActualRoom()->listEnemiesInRoom();
}

void Player::pickObject(string n)
{
	vector <Object> objectsInRoomAux = this->actualRoom->getObjectsInRoom();

	vector <Object>::iterator it = objectsInRoomAux.begin();

	for (it; it != objectsInRoomAux.end(); it++)
	{
		int check = it->getName().find(n);//check the first ocurrence of the word

		if (check >= 0)//means we have an ocurrence
		{
			//if the substring is equal the object can be picked
			if (it->getName().substr(check, it->getName().length()) == n)
			{
				playerInventory->addObjectToInventory(*it);
				actualRoom->removeObjectInRoomByName(it->getName());

				cout << "\n" << it->getName() << " picked!! \n";

				int scoreAux = this->getScore();
				this->setScore(scoreAux += 5);

				break;
			}
		}	
	}

	if (it == objectsInRoomAux.end()) {
		cout << "\n I don't see any object like this in this room bro! \n";
	}
	
}

void Player::dropObject(string n)
{
	vector <Object> objectsInRoomAux = actualRoom->getObjectsInRoom();

	vector <Object> objectsInventary = playerInventory->getObjectsIn();

	vector <Object>::iterator it = objectsInventary.begin();

	int flag = 0;

	for (it; it != objectsInventary.end(); it++)
	{
		int check = it->getName().find(n);//check the first ocurrence of the word

		if (check >= 0) //means we have an ocurrence
		{
			//if the substring is equal the object can be droped
			if (it->getName().substr(check, it->getName().length()) == n)
			{
				objectsInRoomAux.push_back(*it);
				objectsInventary.erase(it);

				actualRoom->setObjectsInRoom(objectsInRoomAux);
				this->playerInventory->setObjectsIn(objectsInventary);

				cout << "\n" << n << " droped!! \n";
				flag = 1;
				break;
			}
		}
	}

	if (!flag) {
		cout << "\n I don't see any object like this in the inventory bro!! \n";
	}
}

void Player::useObject(string n)
{
	vector <Object> objectsInventary = playerInventory->getObjectsIn();

	vector <Object>::iterator it = objectsInventary.begin();

	int flag = 0;

	for (it; it != objectsInventary.end(); it++)
	{
		int check = it->getName().find(n);//check the first ocurrence of the word

		if (check >= 0) //means we have an ocurrence
		{
			//if the substring is equal the object means we have it in the inventory
			if (it->getName().substr(check, it->getName().length()) == n)
			{
				flag = 1;

				if (it->getName().substr(check, it->getName().length()) == "key")
				{
					//check the directions if we have a door that can be openened with a key and we open it
					if (this->actualRoom->getNorth()->getDoor() == 2)
					{
						if (this->actualRoom->getNorth()->getDoorOpen() == false)
						{
							this->actualRoom->getNorth()->setDoorOpen(true);
							cout << "\nSeems like the key just opened the north door!\n";

							int scoreAux = this->getScore();
							scoreAux += 5;
							this->setScore(scoreAux);
						}
					}
					else if (this->actualRoom->getSouth()->getDoor() == 2)
					{
						if (this->actualRoom->getSouth()->getDoorOpen() == false)
						{
							this->actualRoom->getSouth()->setDoorOpen(true);
							cout << "\nSeems like the key just opened the south door!\n";

							int scoreAux = this->getScore();
							scoreAux += 5;
							this->setScore(scoreAux);
						}
					}
					else if (this->actualRoom->getEast()->getDoor() == 2)
					{
						if (this->actualRoom->getEast()->getDoorOpen() == false)
						{
							this->actualRoom->getEast()->setDoorOpen(true);
							cout << "\nSeems like the key just opened the east door!\n";

							int scoreAux = this->getScore();
							scoreAux += 5;
							this->setScore(scoreAux);
						}
					}
					else if (this->actualRoom->getWest()->getDoor() == 2)
					{
						if (this->actualRoom->getWest()->getDoorOpen() == false)
						{
							this->actualRoom->getWest()->setDoorOpen(true);
							cout << "\nSeems like the key just opened the west door!\n";

							int scoreAux = this->getScore();
							scoreAux += 5;
							this->setScore(scoreAux);
						}
					}
					else
					{
						cout << "\n Seems nothing happens. \n";
					}
				}

				if (it->getName().substr(check, it->getName().length()) == "masterkey")
				{
					//check the directions if we have a door that can be openened with a master key and we open it
					if (this->actualRoom->getNorth()->getDoor() == 3)
					{
						if (this->actualRoom->getNorth()->getDoorOpen() == false)
						{
							this->actualRoom->getNorth()->setDoorOpen(true);
							cout << "\nSeems like the master key just opened the north door!\n";

							int scoreAux = this->getScore();
							scoreAux += 10;
							this->setScore(scoreAux);
						}
					}
					else if (this->actualRoom->getSouth()->getDoor() == 3)
					{
						if (this->actualRoom->getSouth()->getDoorOpen() == false)
						{
							this->actualRoom->getSouth()->setDoorOpen(true);
							cout << "\nSeems like the master key just opened the south door!\n";

							int scoreAux = this->getScore();
							scoreAux += 10;
							this->setScore(scoreAux);
						}
					}
					else if (this->actualRoom->getEast()->getDoor() == 3)
					{
						if (this->actualRoom->getEast()->getDoorOpen() == false)
						{
							this->actualRoom->getEast()->setDoorOpen(true);
							cout << "\nSeems like the master key just opened the east door!\n";

							int scoreAux = this->getScore();
							scoreAux += 10;
							this->setScore(scoreAux);
						}
					}
					else if (this->actualRoom->getWest()->getDoor() == 3)
					{
						if (this->actualRoom->getWest()->getDoorOpen() == false)
						{
							this->actualRoom->getWest()->setDoorOpen(true);
							cout << "\nSeems like the master key just opened the west door!\n";

							int scoreAux = this->getScore();
							scoreAux += 10;
							this->setScore(scoreAux);
						}
					}
					else
					{
						cout << "\n Seems nothing happens. \n";
					}
				}

				if (it->getName().substr(check, it->getName().length()) == "bottle")
				{
					cout << "\nYou drink fresk water! \n";
				}

				if (it->getName().substr(check, it->getName().length()) == "knife")
				{
					cout << "\nYou play with the knife between your fingers. \n";
				}

				if (it->getName().substr(check, it->getName().length()) == "journal")
				{
					cout << "\nYou read the journal, at least part of it. It writes about what happened. \n";
				}

				if (it->getName().substr(check, it->getName().length()) == "transmutter")
				{
					cout << "\nYou turn it on and it started to glow in different colours and you started to fell weird. Better turn it off again. \n";
				}

				if (it->getName().substr(check, it->getName().length()) == "meat")
				{
					cout << "\nYou eat the meat and restore part of your life! \n";

					int lifeAux = this->getLife();
					lifeAux += 5;
					if (lifeAux > 10)
					{
						this->setLife(10);
					}
					else
					{
						this->setLife(lifeAux);
					}
					
					objectsInventary.erase(it);
					playerInventory->setObjectsIn(objectsInventary);
					break;
				}

				if (it->getName().substr(check, it->getName().length()) == "stimulant")
				{
					cout << "\nYou use the stimulant and it restore your full life! Awesome! \n";

					this->setLife(10);
					objectsInventary.erase(it);
					playerInventory->setObjectsIn(objectsInventary);
					break;
				}

				if (it->getName().substr(check, it->getName().length()) == "boost")
				{
					cout << "\nYour power attack increases!! Let's kill mutants!! \n";
					
					int powerAttackAux = this->getPowerAttack();
					this->setPowerAttack(powerAttackAux += 5);
					objectsInventary.erase(it);
					playerInventory->setObjectsIn(objectsInventary);
					break;
				}


			}
		}
	}

	if (!flag) {
		cout << "\n I don't see any object like this in the inventory bro!! \n";
	}
}

Inventory const  Player::getInventory()
{
	return *playerInventory;
}

void const Player::itsWall()
{
	cout << "\nYou can't go over there! There is a wall! \n";
}

void Player::openDoor(Room &ar, string dir)
{
	if (dir == "north")
	{
		//0 means no door for the room
		if (ar.getNorth()->getDoor() != 0)
		{
			if (ar.getNorth()->getDoorOpen() == true)
			{
				cout << "\n The door it's already open!\n";
			}
			else
			{	//there is door and the door is closed, so the player open it
				if (ar.getNorth()->getDoor() == 1 && ar.getNorth()->getDoorOpen() == false)
				{
					ar.getNorth()->setDoorOpen(true);
					cout << "\n Door opened! You can enter now!\n";

					int scoreAux = this->getScore();
					this->setScore(scoreAux += 5);
				}//there is door but you need to use a key to open it
				else if (ar.getNorth()->getDoor() == 2 && ar.getNorth()->getDoorOpen() == false)
				{
					cout << "\n The door seems to need a key to be opened!.";
				}
			}
		}
		else
		{
			cout << "\nThere is no door to be open!\n";
		}
		
	}
	else if (dir == "south")
	{
		//0 means no door for the room
		if (ar.getSouth()->getDoor() != 0)
		{
			if (ar.getSouth()->getDoorOpen() == true)
			{
				cout << "\n The door it's already open!\n";
			}
			else
			{	//there is door and the door is closed, so the player open it
				if (ar.getSouth()->getDoor() == 1 && ar.getSouth()->getDoorOpen() == false)
				{
					ar.getSouth()->setDoorOpen(true);
					cout << "\n Door opened! You can enter now!\n";

					int scoreAux = this->getScore();
					this->setScore(scoreAux += 5);
				}//there is door but you need to use a key to open it
				else if (ar.getSouth()->getDoor() == 2 && ar.getSouth()->getDoorOpen() == false)
				{
					cout << "\n The door seems to need a key to be opened! \n";
				}
				
			}
		}
		else
		{
			cout << "\nThere is no door to be open!\n";
		}
	}
	else if (dir == "east")
	{	//0 means no door for the room
		if (ar.getEast()->getDoor() != 0)
		{
			if (ar.getEast()->getDoorOpen() == true)
			{
				cout << "\n The door it's already open!\n";
			}
			else
			{	//there is door and the door is closed, so the player open it
				if (ar.getEast()->getDoor() == 1 && ar.getEast()->getDoorOpen() == false)
				{
					ar.getEast()->setDoorOpen(true);
					cout << "\n Door opened! You can enter now!\n";

					int scoreAux = this->getScore();
					this->setScore(scoreAux += 5);
				}//there is door but you need to use a key to open it
				else if (ar.getEast()->getDoor() == 2 && ar.getEast()->getDoorOpen() == false)
				{
					cout << "\n The door seems to need a key to be opened! \n";
				}
			}
		}
		else
		{
			cout << "\nThere is no door to be opened!\n";
		}
	}
	else if (dir == "west")
	{	//0 means no door for the room
		if(ar.getWest()->getDoor() != 0)
		{
			if (ar.getWest()->getDoorOpen() == true)
			{
				cout << "\n The door it's already open!\n";
			}
			else
			{	//there is door and the door is closed, so the player open it
				if (ar.getWest()->getDoor() == 1 || ar.getWest()->getDoorOpen() == false)
				{
					ar.getWest()->setDoorOpen(true);
					cout << "\n Door opened! You can enter now!\n";

					int scoreAux = this->getScore();
					this->setScore(scoreAux += 5);
				}//there is door but you need to use a key to open it
				else if (ar.getWest()->getDoor() == 2 && ar.getWest()->getDoorOpen() == false)
				{
					cout << "\n The door seems to need a key to be opened! \n";
				}		
			}
		}
		else
		{
			cout << "\nThere is no door to be open!\n";
		}
	}
	else
	{
		cout << "\nI don't recognise that direction bro!\n";
	}

}

void Player::closeDoor(Room &ar, string dir)
{
	if (dir == "north")
	{
		if (ar.getNorth()->getDoorOpen() == false)
		{
			cout << "\n The door it's already closed!\n";
		}
		else
		{	
			if (ar.getNorth()->getDoor() == 1 && ar.getNorth()->getDoorOpen() == true)
			{
				ar.getNorth()->setDoorOpen(false);
				cout << "\n Door closed!\n";
			}
			else
			{
				cout << "\nThere is no door to be closed!\n";
			}
		}

	}
	else if (dir == "south")
	{
		if (ar.getSouth()->getDoorOpen() == false)
		{
			cout << "\n The door it's already closed!\n";
		}
		else
		{
			if (ar.getSouth()->getDoor() == 1 && ar.getSouth()->getDoorOpen() == true)
			{
				ar.getSouth()->setDoorOpen(false);
				cout << "\n Door closed!\n";
			}
			else
			{
				cout << "\nThere is no door to be closed!\n";
			}
		}
	}
	else if (dir == "east")
	{
		if (ar.getEast()->getDoorOpen() == false)
		{
			cout << "\n The door it's already closed!\n";
		}
		else
		{
			if (ar.getEast()->getDoor() == 1 && ar.getEast()->getDoorOpen() == true)
			{
				ar.getEast()->setDoorOpen(false);
				cout << "\n Door closed!\n";
			}
			else
			{
				cout << "\nThere is no door to be closed!\n";
			}
		}
	}
	else if (dir == "west")
	{
		if (ar.getWest()->getDoorOpen() == false)
		{
			cout << "\n The door it's already closed!\n";
		}
		else
		{
			if (ar.getEast()->getDoor() == 1 && ar.getEast()->getDoorOpen() == true)
			{
				ar.getEast()->setDoorOpen(false);
				cout << "\n Door closed!\n";
			}
			else
			{
				cout << "\nThere is no door to be closed!\n";
			}
		}

	}
	else
	{
		cout << "\nI don't recognise that direction bro!\n";
	}
}

void Player::attack(string n, string w)
{
	vector <Enemy> enemiesInRoomAux = this->actualRoom->getEnemiesInRoom();

	vector <Enemy>::iterator it = enemiesInRoomAux.begin();

	int enemyLifeAux;
	int powerAttackAux;

	srand(time(NULL));

	int flag = 0;

	for (it; it != enemiesInRoomAux.end(); it++)
	{
		int check = it->getName().find(n);//check the first ocurrence of the word

		if (check >= 0) //means we have an ocurrence
		{
			//if the substring is equal the enemy can be attacked
			if (it->getName().substr(check, it->getName().length()) == n)
			{
				flag = 1;
				
				enemyLifeAux = it->getLife();

				powerAttackAux = this->getPowerAttack();

				if (w == "hands")
				{
					int randonDamage = rand() % powerAttackAux;

					if (randonDamage > 0)
					{
						enemyLifeAux -= randonDamage;
						cout << "\n You've made " << randonDamage << " on the enemy\n";
					}
					else
					{
						cout << "\nYou've failed your attack! \n";
					}
					


				}
				else if (w == "knife")
				{
					vector <Object> objectsInventary = playerInventory->getObjectsIn();

					vector <Object>::iterator it = objectsInventary.begin();

					int flag = 0;
				
					for (it; it != objectsInventary.end(); it++)
					{
						int check = it->getName().find(w);//check the first ocurrence of the word

						if (check >= 0) //means we have an ocurrence
						{
							//if the substring is equal the object can be droped
							if (it->getName().substr(check, it->getName().length()) == w)
							{
								flag = 1;
								
								int randonDamage = rand() % (powerAttackAux +3);
								if (randonDamage > 0)
								{
									enemyLifeAux -= randonDamage;
									cout << "\n You've made " << randonDamage << " on the enemy\n";
								}
								else
								{
									cout << "\n You've failed your attack! \n";
								}
						
							}
						}
					}

				}
				else if (w == "shootgun")
				{
					vector <Object> objectsInventary = playerInventory->getObjectsIn();

					vector <Object>::iterator it = objectsInventary.begin();

					int flag = 0;

					for (it; it != objectsInventary.end(); it++)
					{
						int check = it->getName().find(w);//check the first ocurrence of the word

						if (check >= 0) //means we have an ocurrence
						{
							//if the substring is equal the object can be droped
							if (it->getName().substr(check, it->getName().length()) == w)
							{
								flag = 1;
								
								powerAttackAux += 10;

								int randonDamage = rand() % powerAttackAux + 5;
								if (randonDamage > 0)
								{
									enemyLifeAux -= randonDamage;
									cout << "\n You've made " << randonDamage << " on the enemy \n";
								}
								else
								{
									cout << " \nYou've failed your attack! \n";
								}

							}
						}
					}
				}

				if (flag == 0)
				{
					cout << "\n I don't have any weapon like that one to attack bro!! \n";
				}


				it->setLife(enemyLifeAux);

				if (enemyLifeAux <= 0) //enemy down
				{
					cout << "\n You've killed the " << it->getName() << "!! \n";

					int scoreAux = this->getScore();
					this->setScore(scoreAux += 10);		

					//look for the drop and set it in the room

					vector <Object> dropAux = it->getDropObjects();
					vector <Object> objectsInRoomAux = this->getActualRoom()->getObjectsInRoom();

					if (dropAux.size() > 0)
					{
						cout << " \n Seems like the enemy dropped something! \n";
						vector <Object>::iterator itDrop = dropAux.begin();

						for (itDrop; itDrop != dropAux.end(); itDrop++)
						{
							cout << "\n \t" << itDrop->getName() << ": " << itDrop->getDescription();
							objectsInRoomAux.push_back(*itDrop);
							
						}

						this->getActualRoom()->setObjectsInRoom(objectsInRoomAux);
						dropAux.clear();
					}

					enemiesInRoomAux.erase(it);
					break;
				}
				else
				{
					cout << "\n Life's enemy is "<< it->getLife() << " and seems like still having gains to fight! Keep attacking!! \n";

					//enemy attack

					int playerLifeAux = this->getLife();

					int randonEnemyDamage = rand() % it->getPowerAttack();
					if (randonEnemyDamage > 0)
					{
						playerLifeAux -= randonEnemyDamage;

						this->setLife(playerLifeAux);

						cout << " " << it->getName() << " hits you with a damage of " << randonEnemyDamage << "\n";

						if (this->getLife() <= 0)
						{
							cout << "\n\n\n \t \t YOU DIED! END OF THE GAME MOTHER/&/·&$ER!\n";
						}

					}
					else
					{
						cout << "\n " << it->getName() << " fails his attack! \n";
					}

				}

			}
		}
	}

	this->actualRoom->setEnemiesInRoom(enemiesInRoomAux);

	if (flag == 0) {
		cout << "\n I don't see any enemy like this in this room!! \n";
	}
}



