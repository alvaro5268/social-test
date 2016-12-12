#include <stdio.h>  // fopen
#include <stdlib.h> // free, exit
#include <string>   // std::string
#include <iostream> // std::cout

#include "../headers/Auxiliar.h"
#include "../headers/User.h"
#include "../headers/StoreUsers.h"
#include "../headers/DistanceUsers.h"


int main(void)
{


    FILE * fileDescriptor;
    // Open file.
    fileDescriptor = fopen("input/SocialNetwork.txt", "r");
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

    // While lines of file input...
    User* userLeft;
    User* userRight;
    char * nameLeft ;
    char * nameRight ;
    while ((read = getline(&line, &lengthLine, fileDescriptor)) != -1) {
        
        // Extract left name in a line of file input.
        nameLeft = Auxiliar::splitNames(line,1);
        // Extract right name in a line of file input.      
        nameRight = Auxiliar::splitNames(line,0);

        // Conversion char* to String.
        std::string stringNameLeft(nameLeft);
        std::string stringNameRight(nameRight);

        // Find users retrieved.
        userLeft = storeUsers.find(stringNameLeft);
        userRight = storeUsers.find(stringNameRight);

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
        
    }

    // Close File.
    fclose(fileDescriptor);
    
    std::cout << "There are: " << storeUsers.getNUsers() <<" different ussers in the file SocialNetwork.txt."<<std::endl;

    User* user1 = storeUsers.find("STACEY_STRIMPLE");
    User* user2 = storeUsers.find("RICH_OMLI");

    // Calculate distance between two peers.
    DistanceUsers distanceUser;
    long int nTies = distanceUser.calculate(user1,user2);
    std::cout << "The number of ties between STACEY_STRIMPLE and RICH_OMLI is: " << nTies << std::endl;

    if (line)
        // Getline() called to malloc() with line.
        free(line);

}