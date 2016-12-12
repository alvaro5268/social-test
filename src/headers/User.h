#ifndef USER_H // Guard for avoid double inclusion.
#define USER_H

#include <string> // std::string
#include <set> // std::set

class User
{
	
private:

	// User name.
	std::string name;

    // List the friends of user..
	std::set<User*,User>* friends;

	
public:


	// Default constructor.
	User();

	// Construct with name.
	User(std::string); 	

	std::string getName();
    
    std::set<User*,User>* getFriends();

    // Get the set friends. 
    long int getNFriends();


	void insert(User* &_friend);


	// print all attributes of the User.
	std::string toString();

	// Function for comparate 2 users by name.	
	bool operator()(User* const& userLeft,  User* const& userRight);


};


#endif