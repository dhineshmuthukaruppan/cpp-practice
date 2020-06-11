/* 1) overview

    - what is an exception
    - what is exception handling
    - what do we throw and catch exceptions
    - how does it affect flow of control
    - defining our own exception classes
    - the standard library exception hierarchy
        - std::exception and what()

*/


/* 2) exception handling

    - basic concepts
    
    - exception handling
        - dealing with extraordinary situations
        - indicates that an extraordinary situation has been detected or has occured
        - program can deal with extraordinary situations in a suitable manner

    - what causes exceptions?
        - insufficient resources
        - missing resources
        - invalid operations
        - range violations
        - underflows and overflows
        - illegal data and many others

    - exception safe
        - when your code handles exceptions

    Terminology

    - exception
        - an object or primitive type that signals that an error has occured

    - throwing an exception (raising an exception)
        - your code detects that an error has occured or will occur
        - that place where the error occurred may not know how to handle the error
        - code can throw an exception describing the error to another part of the program that knows how to handle the error

    - catching an exception (handle the exception)
        - code that handles the exception
        - may or may not cause the program to terminate

    c++ syntax

    - throw
        - throws an exception
        - followed by an argument
    
    - try {code that may throw an exception}
        - you place code that may throw an exception in a try block
        - if the code throws an exception the try block is exited
        - the thrown exception is handled by a catch handler
        - if no catch handler exists the program terminates

    catch (Exception ex) {code to handle the exception}
        - code that handles the exception
        - can have multiple catch handlers
        - may or maynot cause the program to terminate

    int miles {};  
    int gallons {};
    double miles_per_gallon {};   

    try{
        if(gallons == 0)
            throw 0;  
        // miles_per_gallon = miles / gallons; // division by zero error  
        miles_per_gallon = static_cast<double>(miles) / gallons;  // inf if division by zero
    }catch(int &ex){
        std::cerr << "sorry, you can't divide by zero"
    }

*/


/* 3) throwing an exception from a function 

    - what do we do if total is zero?


    double calculate_avg(int sum, int total){
        if(total == 0){
            throw 0;
        }
        return static_cast<double>(sum) / total; 
    }

    double average {};

    try{
        average = calculate_avg(sum, total);
        cout << average; 
    }catch(int &ex){
        cerr << "you cant divide by zero"; 
    }

*/



/* 4) handling multiple exceptions 

    double calculate_avg(int sum, int total){
        if(total == 0){
            throw 0;
        }
        if(miles < 0 || gallons < 0){
            throw std::string{"negative value error"};  
        }
        return static_cast<double>(sum) / total; 
    }

    double average {};

    try{
        average = calculate_avg(sum, total);
        cout << average; 
    }catch(int &ex){
        cerr << "you cant divide by zero"; 
    }
    catch(std::string &ex){
        cerr << ex; 
    }
    catch(...){
        cerr << "unknown exception";
    }   

    // if we don't handle a particular exception here then c++ will terminate the function and proceed up the call stack looking for a handler until it finds
    // one or the program terminates. It's also possible to have a catch all handler. This catch handler will fire no matter what type of exception is thrown. 
    // If this is used, it's common to place it as the last of your catch blocks since it really serves to catch anything that wasn't handled before. 

*/



/* 5) stack unwinding and how it works 

    - if an exception is thrown but not caught in the current scope
        c++ tries to find a handler for the exception by unwinding the stack
    
    - function in which the exception was not caught terminate and is removed from the call stack
    - if a try block was used to then catch blocks are checked for a match
    - if no try block was used or the catch handler doesn't match stack unwinding occurs again
    - if the stack is unwound back to main and no catch handler handles the exception the program terminates


*/



/* 6) creating user defined exception classes 

    user defined exceptions
    - we can create exception classes and throw instances of those classes

    best practice:
    - throw an object not a primitive type
    - throw an object by value
    - catch an object by reference (or const reference)

    class DivideByZeroException {

    };

    class NegativeValueException{

    };   

    double calculate_mpg(int miles, int gallons){
        if(gallons == 0){
            throw DivideByZeroException();     
        }
        return static_cast<double>(miles) / gallons; 
    }    

    try{
        miles_per_gallon = calculate_mpg(miles, gallon); 
    }catch(const DivideByZeroException &ex){
        cerr << "you can't divide by zero";    
    }

*/


/* 7) class level exception  

    - exceptions can also be thrown from  with in a class
    - method 
        - these work the same way as they do for functions as we've seen

    - constructor
        - constructor may fail
        - constructors do not return any value
        - throw an exception in the constructor if you cannot initialize an object

    - destructor
        - do not throw exceptions from your destructor

    Account::Account(std::string name, double balance)
        :name{name}, balance{balance}{

            if(balance < 0/0){
                throw IllegalBalanceException {};
            }
    }

    try{
        std::unique_ptr<Account> moes_account = std::make_unique<Checking_Account>("Moe", -10.0); 
    }catch(const IllegalBalanceException &ex){
        cerr << "couldn't create account";
    }

*/



/* 8) c++ std exceptions 


    - c++ provides a class hierarchy of exception classes
        - std::exception is the base class
        - all subclasses implement the what() virtual function
        - we can create our own user-defined exception subclasses

        virtual const char *what() const noexcept;      



*/















#include <iostream>

using namespace std;  


double calculate_avg(int sum, int total){
    if(total == 0){
        throw 0;
    }
    return static_cast<double>(sum) / total; 
}

int main(){
    double average {};
    int sum {120};
    int total {0}; 

    try{
        average = calculate_avg(sum, total);
        cout << average; 
    }catch(int &ex){    
        cerr << "you cant divide by zero"; 
    }     

    return 0; 
}

