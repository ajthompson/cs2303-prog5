main: main.o Event.o EventList.o Field.o Mule.o Node.o Packet.o Receiver.o Sender.o
	g++ -g -o program5 main.o Event.o EventList.o Field.o Mule.o Node.o Packet.o Receiver.o Sender.o

main.o: main.cpp
	g++ -g -Wall -c main.cpp

Event.o: Event.cpp
	g++ -g -Wall -c Event.cpp

Field.o: Field.cpp
	g++ -g -Wall -c Field.cpp

Mule.o:	Mule.cpp
	g++ -g -Wall -c Mule.cpp

Node.o: Node.cpp
	g++ -g -Wall -c Node.cpp

Packet.o: Packet.cpp
	g++ -g -Wall -c Packet.cpp

Receiver.o: Receiver.cpp
	g++ -g -Wall -c Receiver.cpp

Sender.o: Sender.cpp
	g++ -g -Wall -c Sender.cpp

clean:
	rm *.o