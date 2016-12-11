#ifndef USER_COMPARATOR_H // Guard for avoid double inclusion.
#define USER_COMPARATOR_H

#include <iostream> // cout
#include <string> // toString()
#include <set> // set

#include "../headers/User.h"

// Class for Compare users by name.
class UserComparator
{
public:

	// Function for comparate 2 users by name.
	bool operator()(const User& userLeft, const User& userRight);
};

#endif