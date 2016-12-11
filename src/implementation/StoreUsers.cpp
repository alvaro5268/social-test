#include <string> // toString()
#include "../headers/StoreUsers.h"

// Constructor.
StoreUsers::StoreUsers(){
	this->users = new std::set<User*,User> ;
	this->nUsers = 0;
}

//FIXME: CREATE DESTRUCTOR FOR FREE FRIENDS.

std::set<User*,User>* StoreUsers::getUsers()
{
	return this->users;
}

long StoreUsers::size(){
	return this->users->size();
}

long StoreUsers::getNUsers()
{
	return this->nUsers;
}

void StoreUsers::setNUsers()
{
	this->nUsers++;
}

void StoreUsers::insert(User* user){

	this->users->insert(user);

}

void StoreUsers::insert(User* user,std::string friendName)
{
	user->insert(friendName);
}    


User* StoreUsers::find(std::string name)
{
	User user(name);
    std::set<User*,User>::iterator result = this->users->find(&user);
	
    
    if (result == this->users->end())
    	return NULL;

    User* userPointer = *result;
    
    return userPointer;
    
}

std::set<std::string>* StoreUsers::findFriends(std::string name)
{
	User* user = this->find(name);

    return user->getFriends();
}



// Print all attributes of the User.
std::string StoreUsers::toString()
{
	//std::cout<< "StoreUsers::toString()->List of store users." << std::endl;	
	// Retrieve set. std::set<User,User> 
	std::set<User*,User>* users =  this->users;
    std::set<User*,User>::iterator it;

    int currSize = 0;
    int maxSize = 0;

	for( it = users->begin(); it!=users->end(); ++it) {
	    //(*it)->toString();	
	    currSize = (*it)->getFriendsSize();

    	if (currSize >= maxSize)
    		maxSize = currSize;
    }  	

    //std::cout <<"La lista mas grande ocupa: "<< maxSize <<std::endl;
	return "";
}



