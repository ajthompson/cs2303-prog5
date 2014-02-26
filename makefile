main: s_driver.o Sender.o Packet.o Node.o
	g++ -o s_driver s_driver.o Sender.o Packet.o Node.o

s_driver.o: s_driver.cpp Sender.h Packet.h Node.h
	g++ -Wall -c s_driver.cpp

Sender.o: Sender.cpp Sender.h Packet.h Node.h
	g++ -Wall -c Sender.cpp

Packet.o: Packet.cpp Packet.h Node.h
	g++ -Wall -c Packet.cpp

Node.o: Node.cpp Node.h
	g++ -Wall -c Node.cpp

clean:
	rm *.o