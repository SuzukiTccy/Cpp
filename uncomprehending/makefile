.DEFAULT_GOAL :=run


uc.o: uncomprehending.cpp
	g++ -o uc.o -c uncomprehending.cpp

# say.o: say.cpp
# 	g++ -o say.o -c say.cpp

uc: uc.o
	g++ -o uc uc.o

run: uc
	./uc

clean:
	rm -r *.o
	rm -r uc