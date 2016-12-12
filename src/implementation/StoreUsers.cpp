#include <iostream> // cout

#include "../headers/StoreUsers.h"

// Constructor.
// TODO: CREATE AS SINGLETON.
StoreUsers::StoreUsers(){
	
	for (int i = 0; i < MAX_TABLE; ++i)
	{
		this->users[i] = new std::set<User*,User> ;
	}

	this->nUsers = 0;
}


StoreUsers::~StoreUsers()
{

	// For every position of the table.
	for (int i = 0; i < MAX_TABLE; ++i)
	{
		// Retrieve the set of users.
		std::set<User*,User>* users =  this->users[i];
		std::set<User*,User>::iterator it ;

		// For every user in the set.
		for (it = users->begin(); it!=users->end(); ++it){
			// Clean the list of friends.
			(*it)->getFriends()->clear();
			// Delete the memory allocated with new 
			// when we create the list of friends.
			delete (*it)->getFriends();
			// Call the destructor of user.
			delete (*it);
		}

		// Delete the std::set allocated in the constructor.
		delete this->users[i];  	
	}
}


std::set<User*,User>** StoreUsers::getUsers()
{
	return this->users;
}

long int StoreUsers::bucketSize(std::string name){
	int long hash = this->hash(name);
	std::set<User*,User>* bucket = this->users[hash];

	return bucket->size();
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

long int StoreUsers::hash(std::string name)
{
	int addAscii = 0;
	int nameLength = name.length();

	// Iterate over the string.
	for (int i=0; i<nameLength;i++){
		// 37 is prime
		addAscii = (addAscii * 37 + name[i]);
	}
	// Adjust to the size of the table.
	addAscii = addAscii % MAX_TABLE;
	
	if (addAscii < 0) 
		addAscii = addAscii + MAX_TABLE;

	return addAscii ;
}	


// Insert an user.
void StoreUsers::insert(User* &user){

	std::string name = user->getName();
	int long hash = this->hash(name);
	std::set<User*,User>* bucket = this->users[hash];
	bucket->insert(user);

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
	int long hash = this->hash(name);
	std::set<User*,User>* bucket = this->users[hash];
	std::set<User*,User>::iterator result = bucket->find(&user);
	

	if (result == bucket->end())
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
	/*
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
	*/
}



