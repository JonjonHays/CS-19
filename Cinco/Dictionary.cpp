// Name: Jon Hays
// Pengo: jhays
// Email: mightyfancy@gmail.com 
// Filename: Dictionary.cpp 
// Assignment #4 -- Cinco 
// Purpose: Dictionary class implementation file 
// Code status: Working/tested 

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "Dictionary.h"

using std::string;
using std::ifstream;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;

Dictionary::Dictionary(const char* filename) {
  string wordIn;
  ifstream fin;
  fin.open(filename);
  if (fin.fail()) {
    cerr << "Error opening " << filename << endl;
    exit(EXIT_FAILURE);
  } //if
  while (getline(fin, wordIn)) {
    words.push_back(wordIn);
  } // while 
  fin.close();
} //end Dictionary

string Dictionary::getRandomWord() const {
  return words[rand() % words.size()];
}

int Dictionary::char2alphaIndex(char letter) const {
  return letter - 'a';
} 

int Dictionary::countMatching(string firstWord, string secondWord) const {
  int alphaArray[26] = {0};           
  int count = 0;
  for (int i = 0; i < firstWord.length(); i++) {
    if (alphaArray[char2alphaIndex(firstWord[i])] == 0) { 
      alphaArray[char2alphaIndex(firstWord[i])]++;
    } //if
  } //for
  for (int i = 0; i < secondWord.length(); i++) {
    if (alphaArray[char2alphaIndex(secondWord[i])] == 1) {
      alphaArray[char2alphaIndex(secondWord[i])]++;
      count++;
    } //if
  } //for
  return count;
} //end countMatching

int Dictionary::countInPlace(string firstWord, string secondWord) const {
  int count = 0; 
  for (int i = 0; i < firstWord.length(); i++) {
    if (firstWord[i] == secondWord[i]) {
      count++; 
    } // if
  } //for i
  return count;
} // end countInPlace 

void Dictionary::deleteWord(int index) {
  words[index] = words[words.size() - 1];
  words.pop_back();
} //end deleteWord

bool Dictionary::hasDuplicates(string word) const {
  int alphaArray[26] = {0};
  for (int i = 0; i < word.length(); i++) {
    alphaArray[char2alphaIndex(word[i])]++;
  } //for
  for (int i = 0; i < word.length(); i++) {
    if (alphaArray[char2alphaIndex(word[i])] > 1)
      return true;
  } //for
  return false;
} //end hasDuplicates

void Dictionary::removeWords(string guessWord, int matching, int inPlace) {
  for(int i = words.size() - 1; i >= 0; i--) {
    if (words[i] == guessWord) {
      deleteWord(i);
    } //if
    else if ((matching != countMatching(guessWord, words[i])) 
	     || (inPlace != countInPlace(guessWord, words[i]))) {
      deleteWord(i);
    } //else if
  } //for
} // end removeWords

void Dictionary::removeDupeWords() {
  for(int i = words.size() - 1; i >= 0; i--) {
    if (hasDuplicates(words[i]))
      deleteWord(i);
  } //for
} //end removeDupeWords



