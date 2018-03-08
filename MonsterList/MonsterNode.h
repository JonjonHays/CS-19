// Jon Hays
// jhays
// mightyfancy@gmail.com
// MonsterNode.h
// assignment 5 (Care of Magical Creatures)
// MonsterNode class interface/implementation file (complete class)
// working/tested

#ifndef MONSTERNODE_H
#define MONSTERNODE_H

class MonsterNode {
  friend class MonsterList;
 public:
  // Default constructor initializes node to null
  MonsterNode() {next = 0; id = '\0';}


  private:
    MonsterNode* next;
    char id;

};


#endif
