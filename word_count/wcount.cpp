// Name: Jon Hays
// Pengo: jhays
// email: mightyfancy@gmail.com
// filename: wcount.cpp
// assign. name: Word Counter
// assign. #: 2
// purpose: count the number of instances of each distinct word in a passage, and then sort alphabetically
// status: working/tested

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// removes end punctuation, and converts all uppercase letters to lowercase for a single-word string
string clean_in(string raw_input);

// uses call-by-reference to check if a word is in the 'input_vector', if word is not in input
// vector, it is added to the vector. This function also keeps track of the count of each word 
// and appends values to the 'count_vector' appropriately. 
void wcount(string word, vector<string>& input_vector, vector<int>& count_vector);

// bubble sort that uses call-by-reference to sort 'input_vector' alphabetically while
// simultaneously sorting the 'count_vector'
void dubble_bubble(vector<string>& input_vector, vector<int>& count_vector);

main() {
  string input;
  vector<string> input_vector;
  vector<int> count_vector;
  while (cin >> input) {
    input = clean_in(input);
    wcount(input, input_vector, count_vector);
  }   // while
  dubble_bubble(input_vector, count_vector);
  for (int i = 0; i < input_vector.size(); i++) { 
    cout << input_vector[i] << ' ' << count_vector[i] << endl;
  } // for
} // main
 
// removes end punctuation, and converts all uppercase letters to lowercase for a single-word string
string clean_in(string raw_input) {
  if (ispunct(raw_input[raw_input.size() - 1])) { 
      raw_input = raw_input.substr(0, raw_input.size() - 1);
    } // if
    for (int i = 0; i < raw_input.size(); i++) {
      if (isupper(raw_input[i])) {
	raw_input[i] = tolower(raw_input[i]);
      } // if
    } // for
    return raw_input;
} // clean_in end

// uses call-by-reference to check if a word is in the 'input_vector', if word is not in input
// vector, it is added to the vector. This function also keeps track of the count of each word 
// and appends values to the 'count_vector' appropriately. 
void wcount(string word, vector<string>& input_vector, vector<int>& count_vector) {
  if (input_vector.size() == 0) { // If input vector is empty, this will automatically add first 
    input_vector.push_back(word); // word instead of entering for loop.
    count_vector.push_back(1);
  }
  else {
    int count = 0;		
    for (int i = 0; i < input_vector.size(); i++) {
      if (word == input_vector[i]) { 
	count_vector[i]++;	   
      } // if
      else {
	count++;
      } // else 2
    } // for
    if (count == input_vector.size()) {
      input_vector.push_back(word); 
      count_vector.push_back(1);
    } // if
  } // else 1
} // wcount end

// bubble sort that uses call-by-reference to sort 'input_vector' alphabetically while
// simultaneously sorting the 'count_vector'
void dubble_bubble(vector<string>& input_vector, vector<int>& count_vector) {
  string temp1;
  int temp2;
  for(int j = input_vector.size() - 1; j > 0; j--) {
    for(int i = 0; i < j; i++) {
      if (input_vector[i] > input_vector[i + 1]) {
	temp1 = input_vector[i];
	temp2 = count_vector[i];
	input_vector[i] = input_vector[i + 1];
	count_vector[i] = count_vector[i + 1];
	input_vector[i + 1] = temp1;
	count_vector[i + 1] = temp2;
      }	// if
    }	// for i
  }	// for j
}	// end dubble_bubble


