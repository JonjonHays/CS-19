// Name: Jon Hays
// Pengo: jhays
// Email: mightyfancy@gmail.com
// Filename: Cinco.cpp
// Assignment #4 -- Cinco
// Purpose: Cinco class implementation file
// Code status: working/tested

#include <iostream>
#include <cstdlib>
#include "Dictionary.h"
#include "Cinco.h"

using std::endl;
using std::cin;
using std::cout;
using std::cerr;
using std::string;

Cinco::Cinco(): dict("cinco-words.txt"), numguesses(0), quickGuess(false) {}

void Cinco::consoleUI() {
  string secretWord;
  string guessWord;
  int matching;
  int inPlace;
  cout << "CS19 Cinco";
  if (quickGuess) {       // initiate quick-guess mode--remove all words w/ duplicates
    dict.removeDupeWords();
    cout << " (quick-guess mode)";
  } //if
  cout << endl;
  cout << "by Jon Hays" << endl;
  cout << "Select your " << WORDSIZE << " letter word from the list..." << endl;
  cin >> secretWord;
  while (dict.getDictSize() > 0) {
    numguesses++;
    guessWord = dict.getRandomWord();
    cout << "I'm guessing: " << guessWord << endl;
    cout << "Matching? ";
    cin >> matching;
    cout << "In-Place? ";
    cin >> inPlace;
    if (matching == WORDSIZE && inPlace == WORDSIZE) {
      cout << "I got it in " << numguesses << " guesses.";
      exit(EXIT_SUCCESS);
    }
    dict.removeWords(guessWord, matching, inPlace);
  }
  cerr << "I have run out of guesses; You've either cheated or made a mistake.";
  exit(EXIT_FAILURE);
}


