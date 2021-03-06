// Name: Jon Hays
// Pengo: jhays
// Email: mightyfancy@gmail.com
// Filename: IntSet.cpp
// Assignment #3 (Integer Sets)
// Purpose: source (.cpp) file for IntSet class
// Code tatus: working/tested

#include <string>
#include <sstream>
#include "IntSet.h"
using std::string;
using std::stringstream;

IntSet::IntSet(int elem1, int elem2, int elem3, int elem4, int elem5) { 
  for (int i = 0; i <= MAXSETVAL; i++) {
    data[i] = false;
  } //for
  insertElement(elem1);
  insertElement(elem2);
  insertElement(elem3);
  insertElement(elem4);
  insertElement(elem5); 
}

void IntSet::insertElement(int element) {
  if ((element > -1) && (element <= 1000)) {
    data[element] = true; 
  } //if  
} //end insertElement()

void IntSet::deleteElement(int element) {
  if ((element > -1) && (element <= 1000)) {
    data[element] = false;
  } //if
} //end deletElement()

string IntSet::toString() const {
  string str = "{";
  string elem = "";
  stringstream ss;
  int setSize = 0;
  int count = 0;
  ss.clear();
  ss.str("");
  for (int i = 0; i <= MAXSETVAL; i++) {
    if (data[i] == true) {
      ss << i << " ";
      setSize++;
    } //if
  } //for
  while (ss >> elem) {
    str += elem;
    count++;
    if (count < setSize) {
      str += ", ";
    } //if
  } //while
  str += "}";
  return str;
} //end toString()

void IntSet::unionOf(IntSet &is1, IntSet &is2) {
  for (int i = 0; i <= MAXSETVAL; i++) {
    if (is1.data[i] || is2.data[i]) {
      data[i] = true;
    } //if
    else {
      data[i] = false;
    } //else
  } //for 
} //end unionOf()

void IntSet::intersectionOf(IntSet &is1, IntSet &is2) {
  for (int i = 0; i <= MAXSETVAL; i++) {
    if (is1.data[i] && is2.data[i]) {
      data[i] = true;
    } //if
    else {
      data[i] = false;
    } //else
  } //for 
} //end intersectionOf() 

bool IntSet::hasElement(int elem) const {
  for (int i = 0; i <= MAXSETVAL; i++) {
    if (data[i] && i == elem) {
      return true;
    } //if
  } //for 
  return false;
} //end hasElement()

bool IntSet::equals(IntSet is1) const { 
  int setSize1 = 0;
  int setSize2 = 0;
  int equalCount = 0;
  for (int i = 0; i <= MAXSETVAL; i++) {
    if (data[i]) {
      setSize1++;
    } //if 
    if(is1.data[i]) {
      setSize2++;
      } //if
    if (data[i] && is1.data[i]) {
      equalCount++; 
    } //if
  } //for
  if (setSize1 == equalCount && setSize2 == equalCount) {
    return true;
  } //if
  return false;
} //end equals()


