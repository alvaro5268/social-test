#include "../headers/DistanceUsers.h"
#include "../headers/User.h"

#include <iostream> // cout
#include <string> //std::string
#include <set>  //std::set
#include <queue>  //std::queue



// Default Constructor.
DistanceUsers::DistanceUsers ()
{

}

// TODO: Comment and delete cout.
long DistanceUsers::calculate (User* user1, User* user2)
{

	// Set user 1 as target.
	std::string nameTarget = user1->getName();

	// Set user 2 how start point in the search.
	std::string nameStart = user2->getName();

	//std::cout<<"nameTarget: "<<nameTarget<<std::endl;
	//std::cout<<"nameStart: "<<nameStart<<std::endl;

	std::set<User*,User>::iterator it;

	int VOA = -1 ;

	std::queue<User*> queueUsers;
	std::queue<int> queueLevels;	

	std::set<User*,User> visited;
	bool isEnd = false;
	int level = 0;

	visited.insert(user2);
	
	queueUsers.push(user2);
	queueLevels.push(level);

	// while ! empty queueUsers
	while (! queueUsers.empty() && ! isEnd){
		//std::cout << "Queue front: " << queueUsers.front()->getName() << std::endl;
	    // Deque.
		User* frontUser = queueUsers.front();
    	level = queueLevels.front();
		
		std::set<User*,User>* frontUserFriends = frontUser->getFriends();

	    // Delete the front of queueUsers
		queueUsers.pop();	
    	queueLevels.pop();
		// Aument distance.
		//std::cout << "level WAS :" << level << std::endl;
    	level++;
		//std::cout << "level IS :" << level << std::endl;    	    

		for( it = frontUserFriends->begin(); it!=frontUserFriends->end(); ++it) {
			std::cout << "Current :" << (*it)->getName() << std::endl;
			std::string nameCurrent = (*it)->getName();

			std::set<User*,User>::iterator iteratorVisited = visited.find(*it);
			
			// if Visited...
			if (iteratorVisited != visited.end()){
				std::cout << "Node visited: " << (*iteratorVisited)->getName() << std::endl;
				continue;			
			}

			
			visited.insert(*it);
			queueUsers.push(*it);
			queueLevels.push(level);	

			// If its a solution.
			if (nameCurrent == nameTarget){
				std::cout << "Names coincidence :" << (*it)->getName() << std::endl;			
				// Store the level.
				VOA = level;
				// Mark for finish the execution
				isEnd = true;
				break;		
			}


		} // for

		//std::cout << "Visite todos friends of :" << frontUser->getName() << "or find solution"<< std::endl;
	} // while

	//std::cout << "La distncia encontrada es: " << VOA << std::endl;
	return VOA;
}

