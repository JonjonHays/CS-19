// Jon Hays
// jhays
// mightyfancy@gmail.com
// BookCode.cpp
// Assignment 6 (CodeBreaker!)
// implementation file for BookCode class
// working/tested

#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>
#include <map>
#include "BookCode.h"

using std::ifstream;
using std::string;
using std::cout;
using std::cerr;
using std::endl;
using std::map;

BookCode::BookCode(const char* filename) {
  ifstream fin;
  string keyword;
  string pageStr;
  int pageNum;
  fin.open(filename);
  if (fin.fail()) {
    cout << "Error opening file: " << filename << endl;
    exit(1);
  }
  while(fin >> keyword) {
    fin >> pageStr;
    pageNum = stoi(pageStr);
    codeBook[pageNum] = keyword;
  }

}

string BookCode::lookup(int pageNum) {
  map<int, string>::iterator iter;
  iter = codeBook.find(pageNum);
  if (iter == codeBook.end()) {
    cerr << "Error: invalid page number entered." << endl;
    exit(EXIT_FAILURE);
  }
  string keyword = iter->second;
  return keyword;
}
