main: main.o Event.o EventList.o Field.o Mule.o Node.o Packet.o Receiver.o Sender.o
	g++ -o program5 main.o Event.o EventList.o Field.o Mule.o Node.o Packet.o Receiver.o Sender.o

main.o: main.cpp
	g++ -Wall -c main.cpp

Event.o: Event.cpp
	g++ -Wall -c Event.cpp

Field.o: Field.cpp
	g++ -Wall -c Field.cpp

Mule.o:	Mule.cpp
	g++ -Wall -c Mule.cpp

Node.o: Node.cpp
	g++ -Wall -c Node.cpp

Packet.o: Packet.cpp
	g++ -Wall -c Packet.cpp

Receiver.o: Receiver.cpp
	g++ -Wall -c Receiver.cpp

Sender.o: Sender.cpp
	g++ -Wall -c Sender.cpp

clean:
	rm *.o