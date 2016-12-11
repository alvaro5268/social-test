#include "../headers/UserComparator.h"

bool UserComparator::operator()(const User& userLeft, const User& userRight)
{
    return userLeft.name < userRight.name;
}
