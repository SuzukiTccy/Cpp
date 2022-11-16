.DEFAULT_GOAL :=run


object.o: object.cpp
	g++ -o object.o -c object.cpp -std=c++17

# say.o: say.cpp
# 	g++ -o say.o -c say.cpp

object: object.o
	g++ -o object object.o -std=c++17

run: object
	./object

clean:
	rm -r *.o
	rm -r object