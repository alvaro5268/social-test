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
}        //std::set<User>::iterator result = setUser.find(User(nameLeft));

int User::getFriendsSize(){

	return this->friends->size();

}
  

void User::insert(std::string friendName)
{
	this->friends->insert(friendName);

}

bool User::operator()(User* const& userLeft,  User* const& userRight)
{
	return userLeft->name < userRight->name;
}


// Print all attributes of the User.
// TODO: REMOVE COMMENTS.
std::string User::toString()
{

	//std::cout<< "User::toString->Name." << std::endl;		
	//std::cout<< this->name << std::endl;		
	//std::cout<< "User::toString->List of friends." << std::endl;
	std::string out = "name: " + this->name + "\n";
	std::string out += "friends: " ;

	std::set<std::string>::iterator it;	
    for (it= (this->friends)->begin(); it != (this->friends)->end(); ++it ){
	    //std::cout << (*it) << std::endl;
	    out += "["
	    out += (*it);
	    out += "] "

    }
	//std::cout<< "User::toString()->END List of friends." << std::endl;	

	return out;
}





