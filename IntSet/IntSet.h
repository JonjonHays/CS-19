// Name: Jon Hays
// Pengo acct: jhays
// Email: mightyfancy@gmail.com
// Filename: IntSet.h
// Assignment #3 (Integer Sets)
// Purpose: Header file for integer set class
// Code Status: working/tested

#ifndef INTSET__H
#define INTSET__H

// CS19: C++ Integer Sets Program
// Starter Code by Steve J. Hodges
// The IntSet class renders integer set objects that are comprised 
// of distinct elements; this class' member functions include 
// implementation of standard set operations like intersectionOf,
// unionOf, equals, etc. Sets can be initialized with between 
// 0 to 5 elements, and elements can fall in the range of 0 
// to MAXSETVAL (default==1000).  

class IntSet {
 public:
  // Overloaded defualt constructor; uses default parameters (in header)          
  // to  allow between 0 and 5 parameters to serve as the set object's            
  // initial elements. Defualt values are invalid values (-1); invalid            
  // values are simply ommitted from the integer set.  
  IntSet(int =-1,int =-1, int =-1, int =-1, int =-1);

  // Takes one integer value as input  that will be inserted into the set         
  // object that this function was invoked upon.     
  void insertElement(int);

  // Takes one integer value as input that will be removed from the set           
  // object (if value is present) that this function was invoked upon. 
  void deleteElement(int);

  // Converts the boolean array that represents the integer set into string format
  // using standard set notation; i.e. "{1, 2, 3}".  
  std::string toString() const;

  // Takes two IntSet objects as input: is1 and is2. After function is
  // invoked, the object which it was invoked upon will contain all
  // elements that reside in either is1 or is2—this is the standard
  // unionOf set function.
  void unionOf(IntSet &, IntSet &);

  // Takes two IntSet objects as input: is1 and is2. After function is
  // invoked, the object which it was invoked upon will contain all
  // elements that reside in both is1 and  is2—this is the standard
  // intersectionOf set function.
  void intersectionOf(IntSet &, IntSet &);

  // Checks to see if a given element is present in an IntSet object; returns
  // boolean true if element is present, false if not.
  bool equals(IntSet) const;

  // Checks to see if every element in two IntSet objects  is equal;  
  // one IntSet object is taken as the only parameter, and the other
  // is the object which the function is invoked upon. Returns
  // boolean true if the two IntSets are equal, and false if not. 
  bool hasElement(int) const;

  // Returns maximum integer set value.
  int static getMax(){ return MAXSETVAL; } 

 private:
  static const int MAXSETVAL=1000;
  bool data[MAXSETVAL+1];
};


#endif



