SortingExec: main.o
	g++ main.o -o SortingExec

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm *.o SortingExec