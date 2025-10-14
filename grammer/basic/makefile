.DEFAULT_GOAL :=run


hello_world.o: hello_world.cpp
	g++ -o hello_world.o -c hello_world.cpp -std=c++11

hello_world: hello_world.o
	g++ -o hello_world hello_world.o -std=c++11

gdb: hello_world
	g++ -g -gdwarf-5 hello_world.cpp -o hello_world -std=c++11
	gdb ./hello_world

run: hello_world
	./hello_world

clean:
	@if [ -e *.o ]; then \
		echo "Removing object files..."; \
		rm -r *.o; \
	fi

	@if [ -e hello_world ]; then \
		echo "Removing executable..."; \
		rm -r hello_world; \
	fi
	@if [ -e ./*.dSYM ]; then \
		echo "Removing debug symbols..."; \
		rm -rf ./*.dSYM; \
	fi