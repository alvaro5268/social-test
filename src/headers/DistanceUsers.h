#ifndef DISTANCE_USER_H // Guard for avoid double inclusion.
#define DISTANCE_USER_H

#include "User.h"


class DistanceUsers
{
	
public:

	// Default and empty constructor
	DistanceUsers ();

	// Calculate distance between user 1 and user 2.
	long int calculate(User* user1, User* user2);

};


#endif