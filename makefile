main: p_driver.o Packet.o Node.o
	g++ -o p_driver p_driver.o Packet.o Node.o

p_driver.o: p_driver.cpp Packet.h Node.h
	g++ -Wall -c p_driver.cpp

Packet.o: Packet.cpp Packet.h Node.h
	g++ -Wall -c Packet.cpp

Node.o: Node.cpp Node.h
	g++ -Wall -c Node.cpp

clean:
	rm *.o