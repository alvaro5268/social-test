#include <iostream> // cout

#include "../headers/User.h"
#include "../headers/Auxiliar.h"


// Constructor.
User::User()
{

}


User::User(std::string name) 
{
	// User name.
	this->name = name;

	// This memory will be deleted by class "StoreUsers".
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

bool User::operator()(User* const& userLeft,  User* const& userRight)
{
	return userLeft->name < userRight->name;
}


// Print all attributes of the User.
// FIXME: Return the real string.
std::string User::toString()
{
	std::cout << "name: " << this->name << std::endl;
	std::cout << "friends: ["<< std::endl;

	//std::string out = "name: " + this->name + "\n";
	//out += " friends: [" ;

	std::set<User*,User>::iterator it;	
    for (it= (this->friends)->begin(); it != (this->friends)->end(); ++it ){
	    std::cout << (*it)->getName() << std::endl;
	    //out += (*it)->getName();

    }
	std::cout << "]" << std::endl;
	std::cout <<"Total: " << this->getNFriends() << std::endl;

	//return out;
	return "";
}





