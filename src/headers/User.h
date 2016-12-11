#ifndef USER_H // Guard for avoid double inclusion.
#define USER_H

#include <iostream> // cout
#include <string> // toString()
#include <set> // set

class User
{
	
private:

	// User name.
	std::string name;

    // List the friends of user..
	std::set<std::string>* friends;

	
public:


	// Default constructor.
	User(); 	

	// Construct with name.
	User(std::string); 	

	std::string getName();
    
    std::set<std::string>* getFriends();

    // Get the set friends. 
    int getFriendsSize();


	void insert(std::string friendName);


	// print all attributes of the User.
	std::string toString();

	// Function for comparate 2 users by name.	
	bool operator()(User* const& userLeft,  User* const& userRight);


};


#endif