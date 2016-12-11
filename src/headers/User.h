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
				
	
	public:

		// Construct with name.
      	User(std::string); 	
		
		std::string getName();
		
		// print all attributes of the User.
		std::string toString();

/*
      	// Override comparation, now by name.
		bool operator==(User user);

      	// Override <, by aplhabetical order.
		bool operator<(User user);	

      	// Override >, by aplhabetical order.
		bool operator>(User user);			
*/
};


#endif