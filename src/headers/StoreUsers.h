#ifndef STORE_USERS_H // Guard for avoid double inclusion.
#define STORE_USERS_H
#include <string> // toString()
#include <set> // set

#include "User.h"


class StoreUsers
{

private:

    // List the friends of user..
	std::set<User*,User>* users;
	long nUsers;

public:

	// Constructor.
	StoreUsers();

	// Destructor.
	//~StoreUsers();

    // Return set with all User.
	std::set<User*,User>* getUsers();
	
	long getNUsers();

	// Add 1 to nUsers.
	void setNUsers();

	// Return total users.
	long size();

	// Insert an User.
	void insert(User* &user);

	// Find the list of friends by user name.
	void insert(User* &user, User* &_friend);

	// Find an User by name.
    User* find(std::string name);

	// Find the list of friends by user name.
    std::set<User*,User>* findFriends(std::string name); 


	// print all attributes of the User.
	std::string toString();



};


#endif