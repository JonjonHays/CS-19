p5: main.o MonsterList.o 
	g++ -o p5 main.o MonsterList.o 

main.o: main.cpp MonsterList.h MonsterNode.h
	g++ -c main.cpp

MonsterList.o: MonsterList.cpp MonsterList.h MonsterNode.h
	g++ -c MonsterList.cpp

clean: 
	rm -f p5 *.o *~
