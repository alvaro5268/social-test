#include <iostream> // cout

#include "../headers/StoreUsers.h"

// Constructor.
// TODO: CREATE AS SINGLETON.
StoreUsers::StoreUsers(){
	this->users = new std::set<User*,User> ;
	this->nUsers = 0;
}


// FIXME
StoreUsers::~StoreUsers()
{
	
    /*
    std::set<User*,User>* users =  storeUsers.getUsers();
    std::set<User*,User>::iterator it;
    std::set<User*,User>::iterator it2;
    for( it = users->begin(); it!=users->end(); ++it) {
		delete (*it); // Call to ~User();
    }
	*/
	delete this->users;  	
}


std::set<User*,User>* StoreUsers::getUsers()
{
	return this->users;
}

long int StoreUsers::size(){
	return this->users->size();
}

long int StoreUsers::getNUsers()
{
	return this->nUsers;
}

// Add one in the users counter.
void StoreUsers::setNUsers()
{
	this->nUsers++;
}

// Insert an user.
void StoreUsers::insert(User* &user){

	this->users->insert(user);

}

// Insert an friends.
void StoreUsers::insert(User* &user,User* &_friend)
{
	user->insert(_friend);
}    

// Find an user by name.
User* StoreUsers::find(std::string name)
{
	User user(name);
	std::set<User*,User>::iterator result = this->users->find(&user);
	

	if (result == this->users->end())
		return NULL;

	User* userPointer = *result;

	return userPointer;

}

// Return the list of friends of a User by name.
std::set<User*,User>* StoreUsers::findFriends(std::string name)
{
	User* user = this->find(name);

	return user->getFriends();
}



// Print all attributes of the User.
// TODO: Delete comments.
// FIXME: Return the real string.
std::string StoreUsers::toString()
{
	std::cout<< "StoreUsers::toString()->List of store users." << std::endl;	
	std::set<User*,User>* users =  this->users;
	std::set<User*,User>::iterator it;

	//int currSize = 0;
	//int maxSize = 0;
	std::string out = "";
	for( it = users->begin(); it!=users->end(); ++it) {
	    //(*it)->toString();	
		//out += "User :";
		//out += (*it)->toString();
		(*it)->toString();
	    // Count the size of every user friend list.
		//currSize = (*it)->getNFriends();
		//if (currSize >= maxSize)
		//	maxSize = currSize;
		//out += "\n";		
	}  	

    //std::cout <<"The most friend size is : "<< maxSize <<std::endl;
	//return out;
	return "";
}



