
//Jon Hays
//Pengo: jhays
//Email: mightyfancy@gmail.com
//Filename: loan.cpp
//Assignment #: 1 
//Assignment name: loan
//Purpose: calculate loan payment and total amount to be paid back
//Status: working (tested)

#include <iostream>
#include <iomanip>  // in/output manipulation (used for adjusting number of decimals in output)
#include <math.h>

using namespace std;

double amt_per_payment(double, double, int, int);

int main() {

  double amt;
  double interest;
  int n_payments;
  int n_years;

  cout << "Name: Jon Hays; Pengo Username: jhays; email: mightyfancy@yahoo.com " << endl;
  cout << "Assignment #1; title: loan.cpp; due: sept 6 " << endl;

  cout << "Please enter the amount to be borrowed in USD." << endl;
  cin >> amt;

  cout << "Please enter the annual interest rate as a whole percent value (i.e. 100% = 100). " << endl;
  cin >> interest;

  cout << "Please enter the number of payments to be made each year (positve integer). " << endl;
  cin >> n_payments;

  cout << "Please enter the number of years before loan is paid off (positive integer). " << endl;
  cin >> n_years;

  double payment = amt_per_payment(amt, interest, n_payments, n_years);
  double total_repaid = payment * n_payments * n_years;

  cout << fixed << setprecision(2);   // sets output to two decimal places 
  cout << "Each payment is " << "$" << payment << ". ";
  cout << "The total amount repaid is " << "$" << total_repaid << endl;
}

// Calculates and returns amount paid per loan payment. This function takes four inputs: 
// amt (total amount to be borrowed), interest (interest rate as whole number percent), 
// n_payments (number of payments per year), and n_years (number of years before loan
// is paid off). 
double amt_per_payment(double amt, double interest, int n_payments, int n_years) {

  double int_per_payment = (interest / 100) / n_payments; // interest rate per payment in decimal form
  int total_payments = n_payments * n_years;
  
  double payment = amt / ((1 -pow((1 + int_per_payment), -total_payments)) / int_per_payment);

  return payment; 
}
