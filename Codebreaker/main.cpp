// Jon Hays
// jhays
// mightyfancy@gmail.com
// main.cpp
// assignment 6 (codebreaker!)
// main function for codebreaker project
// working/tested


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "Cryptor.h"

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

int main() {
  srand(time(0));
  Cryptor crypt;
  char mode;
  int pageNum;
  std::string input;
  cout << "Codebreaker! by Jon Hays" << endl;
  cout << "(e)ncrypt or (d)ecrypt? ";
  cin >> mode;
  mode = tolower(mode);
  if (mode == 'e') {
    cout << "page number? ";
    cin >> pageNum;
    cout << "string to encrypt? ";
    cin.ignore();
    getline(cin, input);
    cout << "encrypted message: " << endl;
    cout << crypt.encrypt(pageNum, input) << endl;
    exit(EXIT_SUCCESS);
  }
  if (mode == 'd') {
    cout << "string to decrypt? ";
    cin.ignore();
    getline(cin, input);
    cout << "decrypted message: " << endl;
    cout << crypt.decrypt(input) << endl;
    exit(EXIT_SUCCESS);
  }
  cerr << "Error: invalid entry" << endl;
}
