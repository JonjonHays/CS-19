// Name: Jon Hays
// Pengo: jhays
// Email: mightyfancy@gmail.com
// Filename: Dictionary.cpp
// Assignment #4 -- Cinco
// Purpose: Cinco class interface file
// Code status: working/tested

#ifndef CINCO_H
#define CINCO_H

#include "Dictionary.h"

// Cinco is a word guessing game in which the user chooses a word from 'the
// dictionary' that contains no duplicate characters. The computer then
// guesses a word, and then asks how many characters in the guessed word
// match the characters in the user's secret word, and how many characters
// are exactly in place. The Cinco class is responsible for handling the 
// user interface and contains the function for the main game loop.
class Cinco {
 public:
  Cinco(); 

  // start game
  void play(){ consoleUI(); }  
  
  // main game loop and console i/o
  void consoleUI(); 

  // sets quickGuess boolean; this setter function is used by the user
  // to initiate the quick-guess mode, in which all items in the 
  // dictionary with duplicate characters are deleted before the 
  // game begins
  void setQuickGuess(bool isQuick) {quickGuess = isQuick;}  

 private:
  Dictionary dict;
  int numguesses;
  static const int WORDSIZE = 5;
  bool quickGuess;    
};

#endif


