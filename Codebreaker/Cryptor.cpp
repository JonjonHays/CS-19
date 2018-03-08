// Jon Hays
// jhays
// mightyfancy@gmail.com
// Cryptor.cpp
// assignment 6 (codebreaker!)
// Cryptor class implementation file
// working/tested

#include <string>
#include <cstdlib>
#include "BookCode.h"
#include "Cryptor.h"

using std::string;
using std::to_string;
using std::stoi;

Cryptor::Cryptor() : book("codebreaker-words.txt"), codeMatrix(0) {}

void Cryptor::simplify(string& input) {
  string simplified = "";
  for (int i = 0; i < input.length(); i++) {
    if (isalpha(input[i])) 
      simplified += tolower(input[i]);
  }
  input = simplified;
}

void Cryptor::trim(string& input) {
  // trim first 15 characters off jumbled message
  input = input.substr(15, input.length() - 15);
  // trim off 'x's at the end of jumbled message
  while (input.back() == 'x')
    input.pop_back();
}

void Cryptor::render2dArray(int numRows, int numCols) {
  codeMatrix = new char*[numRows];
  for (int i = 0; i < numRows; i++) {
    codeMatrix[i] = new char[numCols];  
  }
  // initialize array with whitespace
  for (int i = 0; i < numRows; i++) 
    for (int j = 0; j < numCols; j++)
      codeMatrix[i][j] = ' ';
}

void Cryptor::delete2dArray(int numRows, int numCols) {
  for (int i = 0; i < numRows; i++) 
    delete [] codeMatrix[i];
  delete [] codeMatrix; codeMatrix = 0;
}


int Cryptor::blockOut(string keyword, int numRows, int numCols) {
  int row = 0;
  int col = 0;
  int position = -1;
  int keyIndex = 0;
  int keySize = keyword.length();
  int numElements = numRows*numCols;
  int count = 0;
  position += (keyword[keyIndex] - 'a') + 1;
  while (position < numElements && keyIndex < keySize) {
    row = position / numCols;
    col = position % numCols;
    codeMatrix[row][col] = '~';  // '~' represents a space thats "blocked out"
    keyIndex++;    
    position += (keyword[keyIndex] - 'a') + 1;
    count++;
  } 
  return count;
}

string Cryptor::randString() {
  string randString = "";  
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 5; j++) {
      randString += ('a' + rand()%26); 
    }
    randString += ' ';
  }
  return randString;
}

string Cryptor::encryptKeyword(int pageNum) {
  string cryptKey = "";
  cryptKey += to_string(pageNum);
  int size = cryptKey.length();
  // convert number chars to letter chars:
  for (int i = 0; i < size; i++) {
    if (cryptKey[i] == '0')
      cryptKey[i] = 'k'; 
    else 
      cryptKey[i] = cryptKey[i] + '0';
  }
  while (size < 5) {
    cryptKey.insert(rand()%size, "x");
    size++;
  }
  int x = '1';
  cryptKey += ' ';
  return cryptKey;
}

int Cryptor::decryptKeyword(string input) {
  string decryptKey = "";
  input = input.substr(10, 5);
  int size = input.length();
  for (int i = 0; i < size; i++) 
    if (input[i] != 'x')
      decryptKey += input[i];
  // convert letter chars to number chars:
  size = decryptKey.length();
  for (int i = 0; i < size; i++) 
    if (decryptKey[i] == 'k')
      decryptKey[i] = '0';
    else 
      decryptKey[i] = decryptKey[i] - '0';
  return stoi(decryptKey);
}


string Cryptor::popAndExtractEnc(int numRows, int numCols, string input) {
  //populate codeMatrix 
  int size = input.length();
  int count = 0;
  for (int i = 0; i < numRows; i++) {
    for (int j = 0; j < numCols; j++) {
      if (codeMatrix[i][j] != '~' && count < size) {
	codeMatrix[i][j] = input[count];
	count++;
      }
      else { 
	codeMatrix[i][j] = '~';
      }
    }
  }
  //extract jumbled message
  count = 0;
  string jumbled = "";
  for (int j = 0; j < numCols; j++) {
    for (int i = 0; i < numRows; i++) {
      if (codeMatrix[i][j] != '~' && count < size) {
  	jumbled += codeMatrix[i][j];
  	count++;
  	if (count % 5 == 0)
  	  jumbled += ' ';	
      }
      else if (count >= size) {
  	while (count % 5 != 0) {
  	  jumbled += 'x';
  	  count++;
  	}
      }
    }
  }
  // return jumbled message
  return jumbled;
}

string Cryptor::popAndExtractDec(int numRows, int numCols, 
				 int numBlocked,  string input) {
  string ordered = "";
  int size = input.length();
  int count = 0;
  int numExtra = numRows*numCols - (size + numBlocked);
  int row = numRows - 1;
  int col = numCols - 1;
  // block out extra spaces:  
  while (count < numExtra && row >=0) {
    if (codeMatrix[row][col] != '~')    {
      codeMatrix[row][col] = '~'; count++;
    }
    if (col == 0) {
      row--;
      col = numCols;
    }
    col--;
  }
  // populate codeMatrix
  count = 0;
  for (int j = 0; j < numCols; j++) {
    for (int i = 0; i < numRows; i++) {
      if (codeMatrix[i][j] != '~' && count < size) {
	codeMatrix[i][j] = input[count];
	count++;
      }
    }
  }
  // extract decrypted message
  count = 0;
  for (int i = 0; i < numRows; i++) {
    for (int j = 0; j < numCols; j++) {
      if (codeMatrix[i][j] != '~') {
	ordered += codeMatrix[i][j];
	count++;
      }
      if (count == size) return ordered;
    }
  }
}

string Cryptor::encrypt(int pageNum, string input) {
  simplify(input);
  string encrypted = "";    
  string keyword = book.lookup(pageNum);
  //minimum number of spaces needed in codeMatrix
  int minMatrixSize = input.length() + keyword.length(); 
  int numCols = keyword.length();
  int numRows = (minMatrixSize) / numCols;
  // required number of spaces == keyword size + message size
  if (minMatrixSize % numCols != 0)
    numRows++;
  render2dArray(numRows, numCols);
  blockOut(keyword, numRows, numCols);
  encrypted += (randString() + encryptKeyword(pageNum)
  		+ popAndExtractEnc(numRows, numCols, input));
  popAndExtractEnc(numRows, numCols, input);
  delete2dArray(numRows, numCols);
  return encrypted;
}

string Cryptor::decrypt(string input) {
  simplify(input);
  string decrypted = "";
  int pageNum = decryptKeyword(input);
  string keyword = book.lookup(pageNum);
  trim(input);
  int minMatrixSize = input.length() + keyword.length();
  int numCols = keyword.length();
  int numRows = (minMatrixSize) / numCols;
  if (minMatrixSize % numCols != 0)
    numRows++;
  render2dArray(numRows, numCols);
  int numBlocked = blockOut(keyword, numRows, numCols);
  decrypted += popAndExtractDec(numRows, numCols, numBlocked, input);
  delete2dArray(numRows, numCols);
  return decrypted;
}


