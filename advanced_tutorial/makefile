.DEFAULT_GOAL :=run


CFLAG = -std=c++17 -lpthread
EXCUTABLE_FILE = ./bin/advanced
DEPS=advanced.h

SOURCE=$(wildcard ./src/*.cpp) ./advanced.cpp
OBJECT=$(patsubst %.cpp,%.o, $(SOURCE))


$(OBJECT):%.o:%.cpp
	g++ -o ./$@ -c ./$< $(CFLAG)

$(EXCUTABLE_FILE): $(OBJECT)
	g++ -o $@ $^ $(CFLAG)



run: ./bin/advanced
	./bin/advanced

clean:
	@rm -f ./bin/advanced
	@rm -f *.dat
	@rm -f ./src/*.o
	@rm -f ./*.o



