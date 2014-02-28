main: e_driver.o Event.o Sender.o Packet.o Node.o
	g++ -o e_driver e_driver.o Event.o Sender.o Packet.o Node.o

e_driver.o: e_driver.cpp
	g++ -Wall -c e_driver.cpp

Event.o: Event.cpp
	g++ -Wall -c Event.cpp

Sender.o: Sender.cpp
	g++ -Wall -c Sender.cpp

Packet.o: Packet.cpp
	g++ -Wall -c Packet.cpp

Node.o: Node.cpp
	g++ -Wall -c Node.cpp

clean:
	rm *.o