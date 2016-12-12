#include <iostream> // cout

#include "../headers/User.h"
#include "../headers/Auxiliar.h"


// Constructor empty and default.
User::User()
{

}


User::User(std::string name) 
{
	// User name.
	this->name = name;

	// Allocate memory for the pointer of User in friends.
	// TODO: This memory will be deleted by class "StoreUsers".
	this->friends = new std::set<User*,User>;
}


std::string User::getName()
{
	return this->name;
}


std::set<User*,User>* User::getFriends()
{
	return this->friends;
}

long User::getNFriends()
{
	return this->friends->size();
}
  

void User::insert(User* &_friend)
{
	// Avoid that one user could be his own friend.
	if (_friend->name != this->name)
		this->friends->insert(_friend);
	
}

// Operator that allow compare two users by name. 
// Useful for std::set can compare pointers to user.
bool User::operator()(User* const& userLeft,  User* const& userRight)
{
	return userLeft->name < userRight->name;
}


// Print all attributes of the User.
std::string User::toString()
{
	std::string out = "name: " + this->name + "\n";
	out += " friends: [" ;

	std::set<User*,User>::iterator it;	
    for (it= (this->friends)->begin(); it != (this->friends)->end(); ++it ){
	    //std::cout << (*it)->getName() << std::endl;
	    out += (*it)->getName();

    }
	out += "]" ;

	return out;
}





