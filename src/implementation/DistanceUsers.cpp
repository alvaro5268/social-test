#include "../headers/DistanceUsers.h"


// Default Constructor.
DistanceUsers::DistanceUsers (User* user1, User* user2)
{
	std::set<User*,User>* friends1 = user1->getFriends();
	std::set<User*,User>* friends2 = user2->getFriends();
}


