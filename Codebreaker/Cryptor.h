// Jon Hays
// jhays
// mightyfancy@gmail.com
// Cryptor.h
// Assignment 6 (codebreaker!)
// Cryptor class interface file
// working/tested

#ifndef CRYPTOR_H
#define CRYPTOR_H

#include <string>
#include "BookCode.h"

// The Cryptor class has public functions to be used by the user: encrypt and decrypt. 
// encrypt takes in a string of any length, and returns an encoded string (description 
// of the workings of this described below). The decrypt class takes an encoded string
// (input must be in the form that is output by the encrypt function) and returns 
// the re-ordered message; although it will be missing all punctuation, capitalization,
// and spaces in between words. 
class Cryptor {

 public:
  Cryptor(); 

  // Destructor intentionally left out; deallocation takes place within 
  // the delete2dArray function.

  // encrypt takes an integer "page number" input that corresponds
  // to a keyword in the BookCode class. The function takes 
  // a string as the second paramter that is to be encrypted.
  // returns a jumbled message in groups of five characters
  // delimeted by spaces, with two random groups at the beginning
  // and the encrypted page number as the third group.
  std::string encrypt(int pageNum, std::string input);

  // decrypt takes an input as described above, and returns 
  // the re-ordered message, however it is returned all 
  // lowercase and no separation (spaces) between words.
  std::string decrypt(std::string cryptMessage);

 private:
  // removes all non-letter chars and spaces from input,
  // and makes all characters lowercase. (helper for both
  // encrypt and decrypt)
  void simplify(std::string& input);

  // helper function for decrypt—removes first 3 groups 
  // from input, and all trailing xs at the end. 
  void trim(std::string& input);

  // allocates 2d array, "codeMatrix", to specified
  // number of rows and columns as entered in integer
  // input parameters
  void render2dArray(int numRows, int numCols);

  // deallocates codeMatrix and sets to NULL
  void delete2dArray(int numRows, int numCol);

  // "blocks out" positions of codeMatrix that correspond
  // to the alphabetical positions of the keyword's letters
  // blocking out is represented by the tilda character
  int blockOut(std::string keyword, int numRows, int numCols);

  // generates a random string of two five letter groups, separated
  // by a space and with a space at the end
  std::string randString();

  // takes pagenumber as input, and converts the pagenumber into an 
  // encoded group of five characters with space at the end
  std::string encryptKeyword(int pageNum);

  // takes a five letter group of encoded characters as just described, 
  // decodes and then returns the page number as an integer
  int decryptKeyword(std::string input);

  // helper function for encode function; populates codeMatrix and blocks out
  // remaining spaces, then extracts the jumbled message
  std::string popAndExtractEnc(int numRows, int numCols, std::string input);

  // helper function for decode function; populates codeMatrix and blocks out
  // remaining spaces, then extracts the re-ordered message
  std::string popAndExtractDec(int numRows, int numCols, 
			       int numBlocked,  std::string input);

  BookCode book;
  char** codeMatrix;
  };

#endif
