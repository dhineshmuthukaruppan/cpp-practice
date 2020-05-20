
/* 2) expression and statements

    expressions
    -----------
    - The most basic building blocks of a program
    - "a sequence of operators and operands that specifies a computation"
    -  computes a value from a number of operands

        32 // literal
        1 + 2 // addition
        a > b // relational
        a = b // assignment

    statements
    ----------
    - complete line of code that performs some action
    - usually terminated with a semicolon
    - usually contain expressions
    - c++ has many types of statements
        - expression, null, compound, selection, iteration, declaration, jump, try blocks and others

    int x; // declaration
    1 + 2; // expression
    x=2*5; // assignment
    if(a>b) cout << "a is greater than b"; // if
    ; // null statement

*/


/* 3) using operators

    Assignment operator = 
    ------------------------
    lhs = rhs
    - rhs is an expression that is evaluated to a value
    - the value of the rhs is stored to the lhs
    - the value of the rhs must be type compatible with lhs
    - lhs must be assignable
    - assignment expression is evaluated to what was just assigned
    - more than one variable can be assigned in a single statement

    int num1 {10};  
    num1=100;    
    num1=num2=1000; // r-> l associativity

    100=num1; // error: lvalue required as left operand of assignment
*/



/* 4) arithmetic operators

    + addition
    - subtraction
    * multiplication
    / division
    % modulo
*/

/* 
    8) increment and decrement operators
    ++ increment operator
    -- decrement operator

    increments or decrements its operand by 1
    can be used with integers, floating point types and pointers

    prefix ++num
    postfix --num

    don't overuse this operator
    alert!! never use it twice for the same variable in the same statement

    int counter {10};  
    counter = counter + 1; 
    counter++;    

    example 2 - preincrement
    ---------
    counter = 10;  
    result = 0; 
    result = ++counter; // result will be set to 11

    result = ++counter + 10;  // result will be set to 22

    example 3 - post increment
    ---------------------------
    counter = 10; 
    result = 0; 
    result = counter++; // result will still be 10
    result = counter++ + 10; // result will be set to 21

*/


/* 9) mixed expressions and converstions

    - c++ operations occur on same type operands
    - if operands are of different types, c++ will convert one
    - important! since it could affect calculation results
    - c++ will attempt to automatically convert types(coercion). If it can't compiler error will occur.

    Mixed type expressions
    -----------------------
    conversions
    - higher vs lower types are based on the size of the values the type can hold. 
        - long double, double, float, unsigned long, long, unsigned int, int
        - short and char types are always converted to int
    
    - type coercion: conversion of one operand to another data type
    - promotion - conversion to a higher type
        - used in mathematical expression
    - demotion - conversion to a lower type
        used with assignment to lower type

    - lower op higher - the lower is promoted to a higher
        2 * 5.2
    - 2 is promoted to 2.0

    - lower = higher - higher is demoted to a lower
        int num {0}
        num = 100.2; 

    Explicit type casting
    ---------------------
    int total_amount {100}; 
    int total_number {8}; 
    double average {0.0};  

    average = total_amount / total_number; 
    cout << average << endl; // displays 12

    average =  static_cast<double> (total_amount) / total_number; 
        older c code 
        ------------
        average = (double)total/count;    

    cout << average; // displays 12.5

    int total {}; // total will be initialized to zero
    int num1; // num 1 is undefined

*/

/*  10) testing the equality

    == and != operators
    - compares the value of 2 expressions
    - evaluate to a boolean
    - commonly used in control flow statements

    expr1 == expr2
*/

/*  11) relational operators

    > 
    >=
    <
    <=
    <=> three way comparison

    cout << boolalpha; 
    cout << 1 == 1 << endl; // true
    cout << boolalpha; 
*/

/* 12) logical operators
    ! negation
    && and
    || or

    compound assignment operators
    ------------------------------
    +=
    -=
    *=
    /=
    %=
    >>=
    <<=
    &=
    ^=
    |=

*/


/* 14) operator precedence

    [] -> . ()                      lr
    ++ -- not -(unary) sizeof       rl
    * / %                           lr
    + - 
    << >>
    < <= > >=
    == !=
    &
    ^
    |
    &&
    ||
    = op= ?:                        rl


    what is associativity?
    - use precedence rules when adjacent operators are different
        expr op1 expr2 op2 expr3 // precedence
    - use associativity rules when adjacent operators have same precedence
        expr1 op1 expr2 op1 expr3 // associativity
    - use parenthesis to absolutely remove any doubt



*/


#include <iostream>
#include <vector>


using namespace std;    


int main(){





    return 0;  

}  /* end of main function */