main: f_driver.o Field.o
	g++ -o f_driver f_driver.o Field.o

f_driver.o: f_driver.cpp Field.h
	g++ -Wall -c f_driver.cpp

Field.o: Field.cpp Field.h
	g++ -Wall -c Field.cpp

clean:
	rm *.o