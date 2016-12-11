astar.o: main.cpp
	g++ -g -O2 -std=gnu++11 main.cpp src/*.cpp -Isrc/include -Isrc/include/interfaces -o astar.o 
