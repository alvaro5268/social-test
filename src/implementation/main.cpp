#include <stdio.h>  // fopen
#include <stdlib.h>	// free, exit
#include <string.h> // strtok
#include <iostream> // cout
#include <set> // cout
#include "../headers/Auxiliar.h"
#include "../headers/User.h"
#include "../headers/UserComparator.h"





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
    std::set<User,UserComparator> setUser;

    while ((read = getline(&line, &lengthLine, fileDescriptor)) != -1) {
        //std::cout << "current line:" << line;
        char * nameLeft ;
        char * nameRight ;

        // extract left name in a line of file input.
        nameLeft = Auxiliar::splitNames(line,1);
        // extract right name in a line of file input.      
        nameRight = Auxiliar::splitNames(line,0);

        // Conversion char* to String.
        std::string stringNameLeft(nameLeft);
        std::string stringNameRight(nameRight);

        User userLeft(stringNameLeft);
        User userRight(stringNameRight);

        setUser.insert(userLeft);
        setUser.insert(userRight);        
        
    }

    int setSize = setUser.size();
    std::cout<< "the total size is: " << setSize << std::endl; 

    // Close File.
    fclose(fileDescriptor);

    if (line)
    	// Getline() called to malloc() with line.
        free(line);
}