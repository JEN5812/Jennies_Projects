// header files
#include "Console_IO_Utility.h"
#include <math.h>
#include <stdio.h>

// global constants
const double PERCENTAGE_CONVERSION = .01;

const int MONTHS_IN_YEAR = 12;
const int TWO_DIGITS = 2;
const int TWO_ENDLINES = 2;

const char PERCENT_CHAR = '%';

// prototypes
   // none

// main program
int main()
   {
    // initialize function/variables

       // initialize variables
       double purchasePrice, downPayment, interestRate, borrowedAmount;
       double monthlyInterest, paymentNumerator, paymentDenominator;
       double monthlyPayment, totalOfPayments, interestPaid, totalPurchasePrice; 
       int numYears, numPayments;

       // show title
          // function: printString, printEndline(s)
       printEndline();
       printString( "Monthly Payment Calculator" );
       printEndline();
       printString( "==========================" );
       printEndlines( TWO_ENDLINES );

    // get input

       // show data entry
          // function: printString, printEndline(s)
       printString( "Data Entry" );
       printEndline();
       printString( "----------" );
       printEndlines( TWO_ENDLINES);
       
       // get purchase price
          // function: promptForDouble
       purchasePrice = promptForDouble( "Enter the purchase price       ($): " );

       // get down payment
          // function: promptForDouble
       downPayment = promptForDouble(  "Enter the down payment         ($): " );

       // get annual interest rate
          // function: promptForDouble
       interestRate = promptForDouble(  "Enter the annual interest rate (%): " );

       // get number of years
          // function: promptForInteger
       numYears = promptForInteger(  "Enter the number of years      (Y): " );

    // TODO: process data, calculate payment

       // calculate borrowed amount (aka principal) &good
    borrowedAmount = purchasePrice - downPayment;
       
       // calculate monthly interest &good
    monthlyInterest = interestRate/100 / 12;
    
       // calculate number of payments &good
    numPayments = numYears * 12;
       
       // calculate payment numerator
    paymentNumerator = borrowedAmount*monthlyInterest;

       // calculate payment denominator
    paymentDenominator =1-(1/pow(1+monthlyInterest, numPayments));
          // function: pow
       
       // calculate payment
    monthlyPayment = paymentNumerator/paymentDenominator;
    
       // calculate total of all payments &good
    totalOfPayments = monthlyPayment*numPayments;

       // calculate interest paid &good
    interestPaid = monthlyPayment*numPayments-borrowedAmount;
       
       // calculate total purchase price &good
    totalPurchasePrice = borrowedAmount+downPayment+interestPaid;
       

    // show results

       // show title
          // functions: printString, printEndline(s)
       printEndline();
       printString( "Calculation Results" );
       printEndline();
       printString( "-------------------" );
       printEndline();
 
       // show total purchase price
          // functions: printString, printDouble, printEndline(s)
       printEndline();
       printString( "Total Principal       : $" );
       printDouble( borrowedAmount, TWO_DIGITS );
       printEndline();

       // show down payment
          // functions: printString, printDouble, printEndline(s)
       printEndline();
       printString( "Down Payment          : $" );
       printDouble( downPayment, TWO_DIGITS );
       printEndline();

       // show annual interest rate
          // functions: printString, printDouble, printCharacter, printEndline(s)
       printEndline();
       printString( "Annual Interest Rate  : " );
       printDouble( interestRate, TWO_DIGITS );
       printCharacter( PERCENT_CHAR );
       printEndline();

       // show total number of payments
          // functions: printString, printInteger, printEndline(s)
       printEndline();
       printString( "Number of Payments    : " );
       printInteger( numPayments );
       printEndline();
       
       // show monthly payment
          // functions: printString, printDouble, printEndline(s)
       printEndline();
       printString( "Monthly Payment       : $" );
       printDouble( monthlyPayment, TWO_DIGITS );
       printEndline();

       // show total interest paid
          // functions: printString, printDouble, printEndline(s)
       printEndline();
       printString( "Total Interest Paid   : $" );
       printDouble( interestPaid, TWO_DIGITS );
       printEndline();

       // show total cost of loan
          // functions: printString, printDouble, printEndline(s)
       printEndline();
       printString( "Total Cost of Loan    : $" );
       printDouble( totalOfPayments, TWO_DIGITS );
       printEndline();

       // show total purchase price
          // functions: printString, printDouble, printEndline(s)
       printEndline();
       printString( "Total Purchase Price  : $" );
       printDouble( totalPurchasePrice, TWO_DIGITS );
       printEndline();

    // end program

       // show end program
          // function: printString, printEndline
       printEndline();
       printString( "End Program" );
       printEndline();

       // return program success
       return 0;
   }


// supporting functions
   // none




