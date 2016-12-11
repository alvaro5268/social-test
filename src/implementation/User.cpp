#include <string> // toString()
#include "../headers/User.h"
#include "../headers/Auxiliar.h"


// Constructor.
User::User(std::string name) 
{
	this->name = name;
}


std::string User::getName()
{
	return this->name;
}


// Print all attributes of the User.
std::string User::toString()
{
	std::string name(this->name);
	std::string out = name ;    
	return out;
}

bool User::UserComparator::operator()(const User& userLeft, const User& userRight)
{
	return userLeft.name < userRight.name;
}

