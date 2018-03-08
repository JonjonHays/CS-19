// Jon Hays
// jhays
// mightyfancy@gmail.com
// main.cpp
// assignment 5 (Care of Magical Creatures)
// main program file
// working/tested

#include <string>
#include <vector>
#include <iostream>
#include "MonsterNode.h"
#include "MonsterList.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
  MonsterList list0;
  MonsterList list1;
  MonsterList comboList;
  vector<string> input;
  string next;
  while(cin >> next) {
    input.push_back(next);
  }
  int inputSize = input.size();
  char monsterID;
  for (int i = 0; i < inputSize; i = i + 3) {
    monsterID = input[i + 1][0];
    if (input[i] == "0") {
      if (input[i + 2] == "add") {
	list0.insertMonster(monsterID);
      } else {
	list0.removeMonsterType(monsterID);
      }
    }
    if (input[i] == "1") {
      if (input[i + 2] == "add") {
	list1.insertMonster(monsterID);
      } else {
	list1.removeMonsterType(monsterID);
      }
    }
  }
  cout << "CS19 MonsterList" << endl;
  cout << "Jon Hays mightyfancy@gmail.com" << endl;
  cout << "After reading all input..." << endl;
  cout << "list 0:";
  list0.printList();
  cout << "list 1:";
  list1.printList();
  comboList.merge(list0, list1);
  cout << "After merge..." << endl << "list 0:";
  list0.printList();
  cout << "list 1:";
  list1.printList();
  cout << "combined list:";
  comboList.printList();
}
