#ifndef USER_H // Guard for avoid double inclusion.
#define USER_H

#include <iostream> // cout
#include <string> // toString()
#include <set> // set

class User
{

public:

	// User name.
	std::string name;

    // List the friends of user..
	std::set<std::string>* friends;

	
public:


	// Default constructor.
	User(); 	

	// Construct with name.
	User(std::string); 	

    std::set<std::string>* getFriends();

	std::string getName();

	// print all attributes of the User.
	std::string toString();

	// Function for comparate 2 users by name.	
	bool operator()(const User& userLeft, const User& userRight);


};


#endif