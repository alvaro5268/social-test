#include <iostream> // cout
#include <string.h> // strtok

#include "../headers/Auxiliar.h"

// Split the lines of the input file for obtain two names per line.
char * Auxiliar::splitNames(char *pairUsers, bool isLeft)
{
	// Split the char* when find "\n" or ","
	const char delimiter[] = "\n ,";
	if(isLeft){
		// return left side of "," in input file.
		return strtok(pairUsers, delimiter);
	}else{
		// return right side of "," in input file without \n.
		return strtok(NULL,delimiter);
	}
}