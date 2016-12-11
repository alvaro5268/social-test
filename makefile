#### Path for source files.
# src/implementation/
# src/headers/

#### Debug segmentation faults 
# Configure GCC with --enable-checking. Compile it with -g -O0 so that you can use gdb.
# Compile your test case with -v -da -Q.
# -Q will show which function in the test case is causing it to crash.
# -v shows how cc1 was invoked (useful for invoking cc1 manually in gdb).
# -da dumps the RTL to a file after each stage.
# SocialNetwork.out: Auxiliar.o User.o StoreUsers.o
# g++ --enable-checking -g -O0  -v -da -Q


SocialNetwork.out: main.o  User.o StoreUsers.o Auxiliar.o
	g++ -g  -o bin/SocialNetwork.out build/main.o  build/User.o build/StoreUsers.o build/Auxiliar.o 

main.o: src/implementation/main.cpp
	g++ -g   -o build/main.o -c src/implementation/main.cpp

StoreUsers.o: src/implementation/StoreUsers.cpp src/headers/StoreUsers.h 
	g++ -g  -o build/StoreUsers.o -c src/implementation/StoreUsers.cpp

User.o: src/implementation/User.cpp src/headers/User.h
	g++ -g  -o build/User.o -c src/implementation/User.cpp	 

Auxiliar.o: src/implementation/Auxiliar.cpp src/headers/Auxiliar.h
	g++ -g  -o build/Auxiliar.o -c src/implementation/Auxiliar.cpp

clean:
	rm bin/SocialNetwork.out build/main.o  build/User.o StoreUsers.o build/Auxiliar.o      



