#include <stdio.h>  // fopen
#include <stdlib.h>	// free, exit
#include <string.h> // strtok
#include <iostream> // cout
#include <set> // cout
#include "../headers/Auxiliar.h"
#include "../headers/User.h"





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

    // Set for insert and count the users.
    std::set<User,User> setUser;

    //int counter = 1;

    while ((read = getline(&line, &lengthLine, fileDescriptor)) != -1) {
        char * nameLeft ;
        char * nameRight ;

        // extract left name in a line of file input.
        nameLeft = Auxiliar::splitNames(line,1);
        // extract right name in a line of file input.      
        nameRight = Auxiliar::splitNames(line,0);

        // Conversion char* to String.
        std::string stringNameLeft(nameLeft);
        std::string stringNameRight(nameRight);

        // Create users with name.
        User userLeft(stringNameLeft);
        User userRight(stringNameRight);

        // Insert users in a set.
        setUser.insert(userLeft);
        setUser.insert(userRight);

        // Find user left in the set.
        std::set<User>::iterator result = setUser.find(User(nameLeft));

        // Iterator for user.friends.
        std::set<std::string>* friends = (*result).friends;


        // Add friend in the list of user friends.
        friends->insert(stringNameRight);


        
        //Debug
        /*if (counter == 2)
            break;
        counter++;
        */
        
    }

    std::set<User>::iterator result = setUser.find(User("MYLES_JEFFCOAT"));

    if (result == setUser.end())
        std::cout << "User not found" <<std::endl;

    else{
        std::set<std::string>* friends = (*result).friends;

        std::cout << "Name find: " <<(*result).name << std::endl; 
        
        std::cout << "List of friends" << std::endl;       
        
      
        std::set<std::string>::iterator it;
        for(it=(*friends).begin(); it!=(*friends).end();++it) {
            std::cout<< " f: " <<*it << " " << std::endl;
        }   
        //std::cout << "nFriends: " << friends->size() <<endl;

  
    }       




    int setSize = setUser.size();
    std::cout<< "the total size is: " << setSize << std::endl; 

    // Close File.
    fclose(fileDescriptor);

    if (line)
    	// Getline() called to malloc() with line.
        free(line);

}