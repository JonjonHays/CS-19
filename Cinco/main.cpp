// Name: Jon hays
// Pengo: jhays
// Email: mightyfancy@gmail.com
// main.cpp
// Assignment #4 -- Cinco
// Purpose: main function for Cinco assigment (plays one round then ends)
// Code status: working/tested

#include <cstdlib>
#include "Dictionary.h"
#include "Cinco.h"

int main(int argc, char **argv){
  srand(time(0));
  Cinco *c = new Cinco();
  if (argc == 2)  
    c->setQuickGuess(true); 
  c->play();
  return 0;
}
