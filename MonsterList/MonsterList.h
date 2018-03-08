// Jon Hays
// jhays
// mightyfancy@gmail.com
// MonsterList.h
// assignment 5 (Care of Magical Creatures)
// MonsterList class interface file
// working/tested

#ifndef MONSTERLIST_H
#define MONSTERLIST_H

#include "MonsterNode.h"

class MonsterList {

 public:
  // Default constructor initializes list to 0
  MonsterList() {first = 0; listSize = 0;}

  // Destructor deallocates all nodes
  ~MonsterList();

  int getPopulation() const {return listSize;}

  // insert new node at beginning of list, and set 'id' equal to 
  // this functions parameter
  void insertMonster(char);

  // print items in list from first to last, preceded by the size of 
  // the list
  void printList() const;

  // remove all items in list that match the parameter in a case-
  // insensitive manner, then return number of items removed
  int removeMonsterType(char);

  // merge two lists onto the list invoked upon (one from first list,
  // one from second list, etc.). Both parameter lists will be empty
  // after funciton is run. If one list is longer than the other,the end
  // of the merged list will simply look like the end of the longer list
  void merge(MonsterList&, MonsterList&);


 private:
  MonsterNode* first;
  int listSize;
};


#endif
