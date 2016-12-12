#include "../headers/DistanceUsers.h"
#include "../headers/User.h"

#include <iostream> // cout
#include <string> //std::string
#include <set>  //std::set
#include <queue>  //std::queue



// Calculate distance between user 1 and user 2.
DistanceUsers::DistanceUsers ()
{

}

// TODO: Comment and delete cout.
long int DistanceUsers::calculate (User* user1, User* user2)
{

	// Set user 1 as target.
	std::string nameTarget = user1->getName();

	// Set user 2 how start point in the search.
	std::string nameStart = user2->getName();
	
	// Distance cero between one user and him-self
	if (nameTarget == nameStart)
		return 0;

	//std::cout<<"nameTarget: "<<nameTarget<<std::endl;
	//std::cout<<"nameStart: "<<nameStart<<std::endl;


	std::set<User*,User> visited;
	
	std::queue<User*> queueUsers;
	std::queue<int> queueLevels;	

	std::set<User*,User>::iterator it;
	
	int solutionLevel = -1 ;
	bool isEnd = false;
	int level = 0;
	
	queueUsers.push(user2);
	queueLevels.push(level);
	visited.insert(user2);
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

		it = frontUserFriends->begin();

    	while (it != frontUserFriends->end() && ! isEnd){
			//std::cout << "Current :" << (*it)->getName() << std::endl;
			std::string nameCurrent = (*it)->getName();

			std::set<User*,User>::iterator iteratorVisited = visited.find(*it);
			
			// if Visited...
			if (iteratorVisited == visited.end()){
				//std::cout << "Node visited: " << (*iteratorVisited)->getName() << std::endl;
				visited.insert(*it);
				queueUsers.push(*it);
				queueLevels.push(level);	

				// If its a solution.
				if (nameCurrent == nameTarget){
					//std::cout << "Names coincidence :" << (*it)->getName() << std::endl;			
					// Store the level.
					solutionLevel = level;
					// Mark for finish the execution
					isEnd = true;
				}
			}

			++it;

		} // while

	} // while

	//std::cout << "La distncia encontrada es: " << solutionLevel << std::endl;
	return solutionLevel;
}


