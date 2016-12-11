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

/*
// Print all attributes of the User.
std::string User::toString()
{
    std::string name(this->name);
    std::string out = name ;    
	return out;
}

// Override operator comparation for compare users by name
bool User::operator==(User user)
{
	std::string name1 = this-> name;
	std::string name2 = user.name;
	return name1 == name2;
}

// Override operator comparation for compare users by name
bool User::operator<(User user)
{
	std::string name1 = this-> name;
	std::string name2= user.name;
	return name1 < name2;
}

// Override operator comparation for compare users by name
bool User::operator>(User user)
{
	std::string name1 = this-> name;
	std::string name2 = user.name;
	return name1 > name2;

}
*/