#include <iostream> // cout
#include <assert.h>     /* assert */
#include <string>
#include "../../../src/headers/User.h"


//TODO NAME VARIABLES
class UserTest
{

	public:

		void createUserAndCheckNameTrue()
		{

		 	std::string nameUser = "U1";
		 	
		 	User user1(nameUser);

		 	std::string nameGet = user1.getName();

		 	bool assert = (nameUser == nameGet);

			assert (assert);
		}

		void createUserAndCheckNameFalse()
		{
		 	std::string nameUser = "U1";
		 	
		 	User user1(nameUser);

		 	std::string nameGet = user1.getName();

		 	std::string nameFake = "U2";


		 	bool assert = (nameFake == nameGet);
			assert (! assert);
		}	

		void compareUserTrue(){
			std::string name1 = "name1";
			std::string name2 = "name1";

			User u1(name1);
			User u2(name2);

			bool assert = u1 == u2;
			assert(assert);

		}	

		void compareUserFalse(){
			std::string name1 = "name1";
			std::string name2 = "name2";

			User u1(name1);
			User u2(name2);

			bool assert = u1 == u2;
			assert(!assert);
		}

		void compareLessTrue(){
			std::string name1 = "name1";
			std::string name2 = "name2";

			User u1(name1);
			User u2(name2);

			bool assert = u1 < u2;
			assert(assert);
		}	

		void compareLessFalse(){
			std::string name1 = "name1";
			std::string name2 = "name2";

			User u1(name1);
			User u2(name2);

			bool assert = u2 < u1;
			assert(!assert);
		}

		void compareGreaterTrue(){
			std::string name1 = "name1";
			std::string name2 = "name2";

			User u1(name1);
			User u2(name2);

			bool assert = u2 > u1;
			assert(assert);
		}	

		void compareGreaterFalse(){
			std::string name1 = "name1";
			std::string name2 = "name2";

			User u1(name1);
			User u2(name2);

			bool assert = u1 > u2;
			assert(!assert);
		}							


};

int main(){

	UserTest test;

	test.createUserAndCheckNameTrue();
	test.createUserAndCheckNameFalse();
	test.compareUserTrue();
	test.compareUserFalse();
	test.compareUserFalse();
	test.compareLessTrue();
	test.compareLessFalse();
	test.compareGreaterTrue();
	test.compareGreaterFalse();	

	return 0;
}


