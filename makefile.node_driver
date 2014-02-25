main: node_driver.o Node.o
	g++ -o node_driver node_driver.o Node.o

node_driver.o: node_driver.cpp Node.h
	g++ -Wall -c node_driver.cpp

Node.o: Node.cpp Node.h
	g++ -Wall -c Node.cpp

clean:
	rm *.o