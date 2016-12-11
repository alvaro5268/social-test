#ifndef USER_COMPARATOR_H // Guard for avoid double inclusion.
#define USER_COMPARATOR_H

#include <iostream> // cout
#include <string> // toString()
#include <set> // set

#include "../headers/User.h"

class UserComparator
{
public:
    bool operator()(const User& userLeft, const User& userRight);
};

#endif