#include <string> // toString()
#include "../headers/StoreUsers.h"

// Constructor.
StoreUsers::StoreUsers(){
	this->users = new std::set<User*,User> ;
	this->nUsers = 0;
}

StoreUsers::~StoreUsers()
{
	
	std::set<User*,User>* users =  this->users;
	std::set<User*,User>::iterator it;

	// FIXME: CHECK
	/*for( it = users->begin(); it!=users->end(); ++it) {
		if (it != users->end())
			delete *it;
	}*/
	
	delete this->users;  	
}


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

// Insert an user.
void StoreUsers::insert(User* user){

	this->users->insert(user);

}

// Insert an friends.
void StoreUsers::insert(User* user,User* _friend)
{
	user->insert(_friend);
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



