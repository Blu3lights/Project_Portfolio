/******************************************************************************

This is a Mortgage Payment calculator, menu options to select 15yr, 20yr 30yr. (choice)
Rate is different per choice.  


*******************************************************************************/

#include <string>
#include <iostream> 
#include <cmath> // for pow()

using namespace std;

/******************************************************************************
* 
* --------------------------- prototype function------------------------------ 
******************************************************************************/

int getTerm(); // shows and return the selected mortgage term
double getLoanAmount(); // gets the loan amount
double assignRate(int choice); // assigns the rate to the term selected 
double showMonthlyPayment(double rate, int term, double amount); // reurtns the monthly P&I payments



/*****************************************************************************
 * ----------------------------------main------------------------------------- 
 * 
 * **************************************************************************/

int main() {
    
    
// first atmept that was not correct     
    // getTerm();
    // getLoanAmount();
    // choice = getTerm();
    // assignRate(choice);
    
    // correct way
    int choice = getTerm();
    double amount = getLoanAmount();
    double rate = assignRate(choice);
    
    double monthlyPayment = showMonthlyPayment(rate, choice, amount);
    
    cout << "Your monthly payment is: $" << monthlyPayment << endl;
    

    return 0;
}// end main 

/*****************************************************************************
 * 
 *  -------------------------------Functions----------------------------------
 * 
 * ***************************************************************************/

  int getTerm() {
     int term;
     
     cout << "Select on the of following mortgage terms" << endl;
     cout << "Enter the corrisponding number for the Selection" << endl;
     cout << "1. 15 year mortgage" << endl;
     cout << "2. 20 year mortgage" << endl;
     cout << "3. 30 year mortgage" << endl;
     cin >> term;
     if (term < 1 || term > 3 ) {
         cout << "invalid Selection" << endl;
         return -1;
     }
     else {
         return term;
     }
  }
  
 
 double getLoanAmount() {
     double amount; 
     cout << "enter the loan amount" << endl;
     cin >> amount; 
     
     if (amount <= 0 ) {
         cout << "Enter a loan amount greater than zero" << endl;
         return 0;
     }
     else{ 
         return amount;
     }
 }
 
 double assignRate(int choice) {
     double rate;
     
     if (choice == 1 ){ 
         rate = 0.0600;
     }
     else if (choice == 2){
             rate = 0.0625;
         }
         else {
             rate = 0.0650;
         }
        
     return rate;
 }
 
 double showMonthlyPayment(double rate, int choice, double  amount) {
     int years;
    if (choice == 1) years = 15;
    else if (choice == 2) years = 20;
    else years = 30;

    int n = years * 12;        // total months
    double r = rate / 12.0;    // monthly interest rate

    return amount * (r * pow(1 + r, n)) / (pow(1 + r, n) - 1);
 }