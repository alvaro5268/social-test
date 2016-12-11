#ifndef USER_H // Guard for avoid double inclusion.
#define USER_H

#include <iostream> // cout
#include <string> // toString()
#include <set> // set
//#include "UserComparator.h"

class User
{

private:

	// User name.
	std::string name;

	
public:

	// Construct with name.
	User(std::string); 	

	std::string getName();

	// print all attributes of the User.
	std::string toString();

	// Class for Compare users by name.
	class UserComparator
	{

	public:

	// Function for comparate 2 users by name.
		bool operator()(const User& userLeft, const User& userRight);
	};


};


#endif