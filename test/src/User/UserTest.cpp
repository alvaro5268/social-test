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

		/*

		void addFriendTrue()
		{
		 	std::string nameUser1 = "U1";
		 	std::string nameUser2 = "U2";
		 	
		 	User user1(nameUser1);
		 	User user2(nameUser2);

		 	user1.addFriend(&user2);
		 	std::set<User*> friends1 = user1.getFriends(); 

 			std::set<User*>::iterator it;

			for (it = friends1.begin(); it != friends1.end(); ++it){
			    bool assert = strcmp((*it)->getName(),nameUser2) == 0;
			    assert(assert);
			}


		}
	*/
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
	//test.addFriendTrue();



	return 0;
}


