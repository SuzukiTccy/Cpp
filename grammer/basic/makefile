.DEFAULT_GOAL :=run


hello_world.o: hello_world.cpp
	g++ -o hello_world.o -c hello_world.cpp -std=c++11

hello_world: hello_world.o
	g++ -o hello_world hello_world.o -std=c++11

run: hello_world
	./hello_world

clean:
	rm -r *.o
	rm -r hello_world