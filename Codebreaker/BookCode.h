// Jon Hays
// jhays
// mightyfancy@gmail.com
// BookCode.h
// Assignment 6 (Codebreaker!)
// interface file for BookCode class
// working/tested

#ifndef BOOKCODE_H
#define BOOKCODE_H

#include <string>
#include <map>

// The BookCode class works like a pretend book
/// to be used in the Crytpor class. The first word
// of each "page" in the book is stord along with its
// page number in a map, with the page number as the key.
class BookCode {

 public:
  // constructor takes the code book text
  // file as input and loads it into the map
  BookCode(const char* filename);

  // Takes int page number as input and returns
  // string containingkeyword
  std::string lookup(int pageNum);

 private:
  std::map<int, std::string> codeBook;
};



#endif
