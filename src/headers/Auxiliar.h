#ifndef AUXILIAR_H // Guard for avoid double inclusion.
#define AUXILIAR_H

class Auxiliar{

	public:

		// Alphabetical comparation:
		// return 1 if name1 < name2
		// return 2 if name1 > name2
		// return 0 fi name1 == name2.
		static int nameComparing(char* name1, char* name2);
		static char * splitNames(char *pairUsers, bool isLeft);


};

#endif