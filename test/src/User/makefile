UserTest.out: UserTest.o User.o Auxiliar.o
	g++ -o ../../bin/UserTest.out ../../build/UserTest.o ../../build/User.o ../../build/Auxiliar.o


UserTest.o: UserTest.cpp User.o
	g++ -o  ../../build/UserTest.o -c UserTest.cpp

User.o: ../../../src/implementation/User.cpp ../../../src/headers/User.h ../../../src/headers/Auxiliar.h
	g++ -o ../../build/User.o -c ../../../src/implementation/User.cpp

Auxiliar.o: ../../../src/implementation/Auxiliar.cpp ../../../src/headers/Auxiliar.h
	g++ -o ../../build/Auxiliar.o -c ../../../src/implementation/Auxiliar.cpp		

clean:
	rm ../../bin/UserTest.out ../../build/UserTest.o ../../build/User.o ../../build/Auxiliar


