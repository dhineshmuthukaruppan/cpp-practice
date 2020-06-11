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

