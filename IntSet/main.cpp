// Name: Jon Hays          
// Pengo: jhays    
// Email: mightyfancy@gmail.com   
// Filename: IntSet.cpp                                                  
// Assignment #3 (Integer Sets)
// Purpose: working (test) file for IntSet class
// Code tatus: working/tested

#include <iostream>
#include <cstdlib>
#include "IntSet.h"
using std::cin;
using std::cout;
using std::endl;
using std::rand;

int main(){
  IntSet is1,is2(1,2,5),is3;
  cout << "CS19 Program #3 Integer Set Class"<<endl;
  cout << "Jon Hays -- mightyfancy@gmail.com" <<endl; 
  is1.insertElement(2);    is1.insertElement(4);
  is1.insertElement(2);    is1.insertElement(3);
  is1.insertElement(5);    is1.insertElement(7);
  is1.deleteElement(3);    is1.deleteElement(7);
  is1.deleteElement(9);

  for(int i=0; i < (is3.getMax()*0.10); i++)
    is3.insertElement( rand()%is3.getMax() );
  cout << "is3 (random): ";
  cout << is3.toString();
  cout <<endl;

  is3.unionOf(is1,is2);
  cout << "is3 (union): ";
  cout << is3.toString();
  cout <<endl;

  is3.intersectionOf(is1,is2);
  cout << "is3 (intersection): ";
  cout << is3.toString();
  cout << endl;

  if (is3.equals(is3))
    cout << "is3.equals(is3)"<<endl;
  if (is1.equals(is2))
    cout << "is1.equals(is2)"<<endl;
  if (is3.equals(is2))
    cout << "is3.equals(is2)"<<endl;
  if (is2.equals(is2))
    cout << "is2.equals(is2)"<<endl;
  
  cout << "is1: ";
  cout << is1.toString();
  cout << endl;

  if (is1.hasElement(5) ){
    cout <<"is1 contains 5"  << endl;
  } else {
    cout <<"is1 does not contain 5"  << endl;
  }
  if (is1.hasElement(7) ){
    cout <<"is1 contains 7"  << endl;
  } else {
    cout <<"is1 does not contain 7"  << endl;
  }


}
