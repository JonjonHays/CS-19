// Jon Hays
// jhays
// mightyfancy@gmail.com
// MonsterList.cpp
// assignment 5 (Care of Magical Creatures)
// MonsterList implementation file
// working/tested

#include <string>
#include <iostream>
#include "MonsterList.h"

using std::string;
using std::cin;
using std::cout;
using std::endl;

MonsterList::~MonsterList() {
  MonsterNode* temp = first;
  while(first) {
    temp = first;
    first = first->next;
    delete temp;
  }
}

void MonsterList::insertMonster(char monsterID) {
  if (!isalpha(monsterID))
    return;
  MonsterNode* temp = new MonsterNode();
  temp->id = monsterID;
  temp->next = first;
  first = temp;
  listSize++;
}

void MonsterList::printList() const {
  cout << '(' << getPopulation() << ')';
  MonsterNode* temp = first;
  while(temp) {
    cout << temp->id << ' ';
    temp = temp->next;
  } 
  cout << endl;
}

int MonsterList::removeMonsterType(char monsterID) {
  if (!isalpha(monsterID)) return 0; 
  if (listSize == 0) return 0;       // case 1: empty list
  MonsterNode* prev = first;
  MonsterNode* temp = first->next;
  int count = 0;
  while (tolower(prev->id) == tolower(monsterID)) { // case 2: first item(s) in
    delete prev;                                    // list matches key
    first = temp; prev = temp;
    count++; listSize--;
    if (temp==0) return count;
    temp = temp->next;
  }
  while (temp) {                // case 3: multiple items in list
    if (tolower(temp->id) == tolower(monsterID)) {
      prev->next = temp->next;
      delete temp;
      temp = prev->next;
      count++; listSize--;
    } 
    else {
      temp = temp->next;
      prev = prev->next;    
    } 
  }
  return count;
}

void MonsterList::merge(MonsterList& list1, MonsterList& list2) {
  if ((&list1 == &list2) || (listSize != 0) 
      || (this == &list1) || (this == &list2)) {
    return;
  }
  MonsterNode *prev1, *prev2, *temp1, *temp2;
  prev1 = list1.first;
  prev2 = list2.first;
  first = prev1;
  listSize = list1.listSize + list2.listSize;   // set this list size
  list1.first = 0; list2.first = 0; //set parameter lists to NULL
  list1.listSize = 0; list2.listSize = 0; //set parameter list sizes to 0
  if ((prev1 != 0) && (prev2 != 0)) { //if neither list is empty..
  temp1 = prev1->next;
  temp2 = prev2->next;
    while(true) {
      prev1->next = prev2;
      if ((temp1 != 0) && (temp2 != 0)) { 
	prev2->next = temp1;
	prev1 = temp1;                    
	prev2 = temp2;
	temp1 = temp1->next;
	temp2 = temp2->next;
      } //if-2
      else if (temp1 != 0) { // if temp1 != 0, then temp2 must = 0, reroute.. 
	prev2->next = temp1;
	return;
      } //else if
      else {                // if temp1 is 0, or both are 0, do nothing more..
	return;
      } //else
    } //while
  } //if-1
  else if (prev1 == 0) { //if list1 is empty, reroute to list 2..
    first = prev2;
  }
  else { //if list2 is empty, or both are empty, do nothing more..
    return;
  }
}


