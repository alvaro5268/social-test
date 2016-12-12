#ifndef STORE_USERS_H // Guard for avoid double inclusion.
#define STORE_USERS_H
#include <string> // std::string
#include <set> // std::set

#include "User.h"

// Class for store all users of the social network.
// Provide functions for insert users and get the total of Users.
class StoreUsers
{

private:

    // List the friends of user.
    // 82178 is the number of different user.
    static const long int MAX_TABLE = 82178;
	std::set<User*,User>* users[MAX_TABLE];
	long int nUsers;

public:

	// Constructor.
	StoreUsers();

	// Destructor.
	~StoreUsers();

	std::set<User*,User>** getUsers();
	
	long int getNUsers();


	// Add 1 to nUsers.
	void setNUsers();

	// Calculate a hash number from a string.
	long int hash(std::string name);	

	// Return the size of a set in the table.
	long int bucketSize(std::string name);

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