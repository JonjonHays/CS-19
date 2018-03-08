p4: main.o Cinco.o Dictionary.o 
	g++ -o p4 main.o Cinco.o Dictionary.o

main.o: main.cpp Cinco.h Dictionary.h 
	g++ -c main.cpp

Cinco.o: Cinco.cpp Cinco.h Dictionary.h
	g++ -c Cinco.cpp

Dictionary.o: Dictionary.cpp Dictionary.h
	g++ -c Dictionary.cpp

clean: 
	rm -f p4 *.o *-


