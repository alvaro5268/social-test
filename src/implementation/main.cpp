#include <stdio.h>  // fopen
#include <stdlib.h>	// free, exit
#include <string.h> // strtok
#include <iostream> // cout
#include <set> // cout
#include "../headers/Auxiliar.h"
#include "../headers/User.h"
#include "../headers/StoreUsers.h"





int main(void)
{


    FILE * fileDescriptor;
    // Open file.
    fileDescriptor = fopen("../input/SocialNetwork.txt", "r");
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
    
    int counter = 1;

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
        userLeft->insert(stringNameRight);
        userRight->insert(stringNameLeft);

            
        //Debug
        //if (counter == 2)
        //    break;
        //counter++;
        
        
    }

    storeUsers.toString();
    std::cout << "size std::set: " << storeUsers.size() <<std::endl;
    std::cout << "size manual: " << storeUsers.getNUsers() <<std::endl;
       
    // Close File.
    fclose(fileDescriptor);

    if (line)
    	// Getline() called to malloc() with line.
        free(line);

}