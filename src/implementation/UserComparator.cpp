#include "../headers/UserComparator.h"

// Function for comparate 2 users by name.
bool UserComparator::operator()(const User& userLeft, const User& userRight)
{
	return userLeft.name < userRight.name;
}
