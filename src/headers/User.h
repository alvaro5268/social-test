#ifndef USER_H // Guard for avoid double inclusion.
#define USER_H

#include <string> // std::string
#include <set> // std::set

// Store an user and his list of friends.
class User
{
	
private:

	// User name.
	std::string name;

    // Friends of the User.
	std::set<User*,User>* friends;

	
public:


	// Default constructor.
	User();

	// Construct with name.
	User(std::string); 	

	std::string getName();
    
    std::set<User*,User>* getFriends();

    // Get number of User friends. 
    long int getNFriends();

    // Insert friend.
	void insert(User* &_friend);

	// Function for comparate 2 users by name.	
	bool operator()(User* const& userLeft,  User* const& userRight);

	// Print all attributes of the User.
	std::string toString();

};


#endif