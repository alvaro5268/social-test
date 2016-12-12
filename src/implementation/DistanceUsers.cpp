#include "../headers/DistanceUsers.h"
#include "../headers/User.h"

#include <iostream> // cout
#include <string>
#include <set>
#include <queue>




// Default Constructor.
DistanceUsers::DistanceUsers ()
{

}

long DistanceUsers::calculate (User* user1, User* user2)
{

	// Set user 1 as target.
	std::string nameTarget = user1->getName();

	// Set user 2 how start point in the search.
	std::string nameStart = user2->getName();

	std::cout<<"nameTarget: "<<nameTarget<<std::endl;
	std::cout<<"nameStart: "<<nameStart<<std::endl;


	std::set<User*,User>::iterator it;

	//std::string out = "";
	//std::set<std::string> solucion;


	int long level = 0;
	int long VOA = -1 ;
	std::queue<User*> queue;
	std::set<User*,User> visited;
	bool isEnd = false;
	visited.insert(user2);
	queue.push(user2);

	// while ! empty queue
	while (! queue.empty() && ! isEnd){
		std::cout << "Cola front: " << queue.front()->getName() << std::endl;
	    // Deque.
		User* frontUser = queue.front();
		
		std::set<User*,User>* frontUserFriends = frontUser->getFriends();

	    // Delete the front of queue
		queue.pop();	



		for( it = frontUserFriends->begin(); it!=frontUserFriends->end(); ++it) {
			std::cout << "Busco a :" << nameTarget << std::endl;
			std::cout << "Current :" << (*it)->getName() << std::endl;
			std::string nameCurrent = (*it)->getName();



			std::set<User*,User>::iterator iteratorVisited = visited.find(*it);
			
			// if Visited...
			if (iteratorVisited != visited.end()){
				std::cout << "ya visite este nodo: " << (*iteratorVisited)->getName() << std::endl;
				continue;			
			}

			
			visited.insert(*it);
			queue.push(*it);

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

		// TODO: ¿Que pasa si me dices que busque el mismo user?
		// Insertar el usuario en vez de los amigos.
		std::cout << "Visite todos friends of :" << frontUser->getName() << std::endl;
		std::cout << "or last name is a solution" << std::endl;

		visited.insert(frontUser);	

		// Aument distance.
		std::cout << "Current distance is :" << level << std::endl;
		level ++;
		
	} // while

	std::cout << "La distncia encontrada es: " << VOA << std::endl;
	return VOA;
}


