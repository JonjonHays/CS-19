// Name: Jon Hays
// Pengo: jhays
// Email: mightyfancy@gmail.com
// Dictionary.h
// Assignment #4 -- Cinco
// Purpose: Dictionary class interface file
// Code status: Working/tested

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>
#include <vector>

// The dictionary class takes input from a textfile, and stores individual words
// in 'the dictionary'. This class contains functions for removing words from
// the dictionary based on the guidelines of the Cinco word game. 
class Dictionary {

 public:
  // constructor takes a text file name ("string literal") as input; text file should 
  // contain a list of words that have the same number of characters in each word. 
  Dictionary(const char* filename); 

  // get a random word from the list to be used as the computer's guess
  std::string getRandomWord() const;

  // remove guessWord from the dictionary as well as every word that
  // doesn't have the correct number of characters that are "matching" 
  // and characters that are "in-place" when compared to the guessWord
  void removeWords(std::string guessWord, int matching, int inplace);

  // remove all words in dictionary that have duplicate characters
  void removeDupeWords();

  // return the current number of words in the dictionary
  int getDictSize() const {return words.size();}

 private:
  // convert a character from its ASCII integer value to a value (0-25)
  // that corresponds to the character's postion in the alphabet
  // (Note: only lowercase alphabetical characters may be input
  // into this function)
  int char2alphaIndex(char letter) const;

  // count the number of distinctly matching characters in two strings
  int countMatching(std::string firstWord, std::string secondWord) const;

  // count the number of characters that have the same value and position
  // in two strings
  int countInPlace(std::string firstWord, std::string secondWord) const;

  // return true if word has duplicate characters; false if all characters
  // are unique
  bool hasDuplicates(std::string word) const;

  // remove word from dictionary at position "index"
  // NOTE: this function does not preserve the order of the "words"
  // vector; this function works by assigning the string in the vector
  // that is to be deleted with the string in the last position of the
  // vector, and then uses pop_back() to remove the last element
  void deleteWord(int index);

  std::vector<std::string> words; 
};


#endif
