#include <iostream> // cout
#include <assert.h>     /* assert */
#include <string>
#include <stdio.h>  // fopen
#include <stdlib.h>	// free, exit

#include "../../../src/headers/User.h"
#include "../../../src/headers/Auxiliar.h"
#include "../../../src/headers/StoreUsers.h"
#include "../../../src/headers/DistanceUsers.h"


//TODO NAME VARIABLES
class DistanceUserTest
{

	public:

		void testDistance(char * nameFile,long expectedOutcome, std::string nameTarget, std::string nameStart)
		{

		    FILE * fileDescriptor;
		    // Open file.

		    fileDescriptor = fopen(nameFile, "r");
		    if (fileDescriptor == NULL){
		        std::cout << "File not found" << std::endl;
		    	// Finish execution.
		        exit(EXIT_FAILURE);
		    }

		    size_t lengthLine = 0;
		    ssize_t read;

		    // Store one line of de input.
		    char * line = NULL;

		    // Insert and count the users.
		    StoreUsers storeUsers;
		    
		    //Debug
		    //int counter = 1;

		    // While lines of file input...
		    while ((read = getline(&line, &lengthLine, fileDescriptor)) != -1) {
		        char * nameLeft ;
		        char * nameRight ;
		        
		        // Extract left name in a line of file input.
		        nameLeft = Auxiliar::splitNames(line,1);
		        // Extract right name in a line of file input.      
		        nameRight = Auxiliar::splitNames(line,0);

		        // Conversion char* to String.
		        std::string stringNameLeft(nameLeft);
		        std::string stringNameRight(nameRight);

		        // Find users retrieved.
		        User* userLeft = storeUsers.find(stringNameLeft);
		        User* userRight = storeUsers.find(stringNameRight);

		        // If the user retrieved does not exist...
		        if (userLeft == NULL){
		            // Create user.
		            userLeft = new User(stringNameLeft);
		            // Insert user.
		            storeUsers.insert(userLeft);
		            storeUsers.setNUsers();

		        }      

		        // If the user retrieved does not exist...
		        if(userRight == NULL){
		            userRight = new User(stringNameRight);
		            storeUsers.insert(userRight);
		            storeUsers.setNUsers();

		        }

		        // Add the friends for every user.
		        userLeft->insert(userRight);
		        userRight->insert(userLeft);

		            
		        //Debug
		        //if (counter == 3)
		        //    break;
		        //counter++;
		        
		    }

		    // Close File.
		    fclose(fileDescriptor);
		    
		    User* user1 = storeUsers.find(nameTarget);
		    User* user2 = storeUsers.find(nameStart);

		    // Calculate distance between two peers.
		    DistanceUsers distanceUser;
		    long distanceCalculated = distanceUser.calculate(user1,user2);
		 	bool assert = (expectedOutcome == distanceCalculated);

			assert (assert);
		}



};

int main(){

	DistanceUserTest test;
	
	
	char test1[] = "../../input/test1.txt";
	long expectedOutcome1 = 1;
	std::string nameTarget1 = "MYLES_JEFFCOAT";
	std::string nameStart1 = "LANNY_TIBURCIO";	
	std::cout << "Running test1" << std::endl;
	test.testDistance(test1, expectedOutcome1, nameTarget1, nameStart1);
	

	std::cout << "Running test2" << std::endl;	
	char test2[] = "../../input/test2.txt";
	long expectedOutcome2 = -1;
	std::string nameTarget2 = "MYLES_JEFFCOAT";
	std::string nameStart2 = "USER_3";	

	test.testDistance(test2, expectedOutcome2, nameTarget2, nameStart2);	
	
	std::cout << "Running test3" << std::endl;	
	char test3[] = "../../input/test3.txt";
	long expectedOutcome3 = 3;
	std::string nameTarget3 = "USER_1";
	std::string nameStart3 = "USER_7";	

	test.testDistance(test3, expectedOutcome3, nameTarget3, nameStart3);	
	


	return 0;
}


