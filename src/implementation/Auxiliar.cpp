#include <iostream> // cout
#include <string.h> // strcmp

#include "../headers/Auxiliar.h"

// Split the names in the input file.
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