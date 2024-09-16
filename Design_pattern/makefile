.DEFAULT_GOAL := run

TARGETS = singleton

singleton: 
	g++ -o singleton.o -c singleton.cpp -std=c++17
	g++ -o singleton singleton.o -std=c++17

run_singleton: singleton
	./singleton

run: singleton
	./singleton

clean:
	rm -f *.o
	rm -f $(TARGETS)