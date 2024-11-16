.DEFAULT_GOAL := run

TARGETS = main

main: 
	g++ -o main.o -c main.cpp -std=c++17
	g++ -o main main.o -std=c++17

run_main: main
	./main

run: main
	./main

clean:
	rm -f *.o
	rm -f $(TARGETS)