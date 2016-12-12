DistanceUsersTest.out: DistanceUsersTest.o DistanceUsers.o StoreUsers.o User.o Auxiliar.o
	g++ -o ../../bin/DistanceUsersTest.out ../../build/DistanceUsersTest.o ../../build/DistanceUsers.o ../../build/StoreUsers.o ../../build/User.o ../../build/Auxiliar.o

DistanceUsersTest.o: DistanceUsersTest.cpp ../../../src/headers/DistanceUsers.h 
	g++ -o  ../../build/DistanceUsersTest.o -c DistanceUsersTest.cpp

DistanceUsers.o: ../../../src/implementation/DistanceUsers.cpp ../../../src/headers/DistanceUsers.h 
	g++ -o ../../build/DistanceUsers.o -c ../../../src/implementation/DistanceUsers.cpp	

StoreUsers.o: ../../../src/implementation/StoreUsers.cpp ../../../src/headers/StoreUsers.h 
	g++ -o ../../build/StoreUsers.o -c ../../../src/implementation/StoreUsers.cpp		

User.o: ../../../src/implementation/User.cpp ../../../src/headers/User.h ../../../src/headers/Auxiliar.h
	g++ -o ../../build/User.o -c ../../../src/implementation/User.cpp

Auxiliar.o: ../../../src/implementation/Auxiliar.cpp ../../../src/headers/Auxiliar.h
	g++ -o ../../build/Auxiliar.o -c ../../../src/implementation/Auxiliar.cpp		

clean:
	rm ../../bin/DistanceUsersTest.out ../../build/DistanceUsersTest.o ../../build/DistanceUsers.o ../../build/User.o ../../build/StoreUsers.o ../../build/Auxiliar