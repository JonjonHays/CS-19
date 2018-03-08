p6: main.o Cryptor.o BookCode.o
	g++ -o p6 main.o Cryptor.o BookCode.o

main.o: main.cpp Cryptor.h BookCode.h
	g++ -c -std=c++11 main.cpp

Cryptor.o: Cryptor.cpp Cryptor.h BookCode.h
	g++ -c -std=c++11 Cryptor.cpp

BookCode.o: BookCode.cpp BookCode.h
	g++ -c -std=c++11 BookCode.cpp

clean:
	rm -f p6 *.o *~

