#include "../headers/DistanceUsers.h"
#include "../headers/User.h"

#include <iostream> // cout
#include <string> //std::string
#include <set>  //std::set
#include <queue>  //std::queue

// TODO: CREATE AS A SINGLETON.


// This function implements a Breadth-first search for
// Return the distance between two users or -1 if the 
// users do not have any connection.
long int DistanceUsers::calculate (User* user1, User* user2)
{

	// Set one user as target.
	std::string nameTarget = user1->getName();

	// Set other user how start point in the search.
	std::string nameStart = user2->getName();
	
	// Distance cero between one user and him-self.
	if (nameTarget == nameStart)
		return 0;

	// Store the visited nodes.
	std::set<User*,User> visited;
	
	// Queue for exploring users.	
	std::queue<User*> queueUsers;

	// Queue for store current depth level.		
	std::queue<int> queueLevels;	

	// Iterator over the friends of the explored User.
	std::set<User*,User>::iterator it;
	
	// -1 means that there is not solution.
	int solutionLevel = -1 ;

	// Condition for finish the execution when a solution is find.
	bool isSoultion = false;

	// Current depth level in the "tree generated".
	int level = 0;
	
	// Initialize with the user "root"
	queueUsers.push(user2);

	// Initialize with level 0;
	queueLevels.push(level);
	
	// Mark this User how visited for avoid cycles.
	visited.insert(user2);

	while (! queueUsers.empty() && ! isSoultion){
	    
	    // Deque the front of the queue.
		User* frontUser = queueUsers.front();
    	
		// Deque the current depth level.
    	level = queueLevels.front();
		
	    // Get the friends of the current User explored.		
		std::set<User*,User>* frontUserFriends = frontUser->getFriends();

	    // Delete the front of queueUsers
		queueUsers.pop();

	    // Delete the front of queueUsers			
    	queueLevels.pop();

		// Aument depth level.
    	level++;

    	// Init the iterador to UserFriends.
		it = frontUserFriends->begin();

		// While there are friends o not find the solution.
    	while (it != frontUserFriends->end() && ! isSoultion){

			// Search the current user in the visited set.
			std::set<User*,User>::iterator iteratorVisited = visited.find(*it);
			
			// If NOT is visited the user.
			if (iteratorVisited == visited.end()){

				visited.insert(*it);
				
				// Add to the queue for explore.
				queueUsers.push(*it);

				// Add the current level to the queue.				
				queueLevels.push(level);	


				std::string nameCurrent = (*it)->getName();
				// If its a solution.
				if (nameCurrent == nameTarget){
					solutionLevel = level;
					// Mark for finish the execution
					isSoultion = true;
				}
			}

			++it;

		} // while

	} // while

	return solutionLevel;
}


