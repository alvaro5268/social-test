#include <string> // toString()
#include "../headers/User.h"
#include "../headers/Auxiliar.h"


// Constructor.
User::User(){

}


User::User(std::string name) 
{
	this->name = name;
	this->friends = new std::set<std::string>;

}

//TODO: CREATE DESTRUCTOR FOR FREE FRIENDS.


std::string User::getName()
{
	return this->name;
}


std::set<std::string>* User::getFriends()
{
	return this->friends;
}

// Print all attributes of the User.
std::string User::toString()
{
	std::string name(this->name);
	std::string out = name ;    
	return out;
}

bool User::operator()(const User& userLeft, const User& userRight)
{
	return userLeft.name < userRight.name;
}



