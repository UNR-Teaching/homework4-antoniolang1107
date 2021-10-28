SortingExec: main.o sorts.o
	g++ main.o sorts.o -o SortingExec

main.o: main.cpp
	g++ -c main.cpp

sorts.o: sorts.cpp sorts.h
	g++ -c sorts.cpp

clean:
	rm *.o SortingExec