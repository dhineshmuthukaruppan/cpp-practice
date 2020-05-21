/* 1) section overview

    Characters  and strings
    - character functions
    - c-style strings
    - working with c-style strings
    - c++ strigns
    - working with c++ strings


    Character functions
    -------------------
    #include <cctype>
    - function for testing characters and converting character case
        testing functions
        -----------------
        isalpha(c)
        isalnum(c)
        isdigit(c)
        islower(c)
        isprint(c) - true if c is a printable character
        ispunct(c) - true if c is a punctuation character
        isupper(c) - true if c is an uppercase letter
        isspace(c) - true if c is whitespace
        
        converting function
        ------------------
        tolower(c)
        toupper(c) 

*/


/* 3) cstyle strings

    cstyle strings
    --------------
    - In order to find the length of the cstyle strings we have to iterate through it until we reach null character. That's why c++ string comes to rescue.
    - sequence of characters
        - contiguous in memory
        - implemented as an array of characters
        - terminated by a null character(null)
            - null - character with a value of zero
        - referred to as zero or null terminated strings
    

    - string literal
        - sequence of characters in double quotes eg. "frank"
        - constant
        - terminated with null character

    "c++ is fun"
    0 1 2 3 4 5 6 7 8 9 10 
    c + +   i s   f u n \0


    char myname[] {"frank"}; 
    myname[5] = 'y'; // problem


    char myname[8] {"frank"}
    0 1 2 3 4 5  6  7
    f r a n k \0 \0 \0
    myname[5] = 'y'; // ok


    char myname[8]; // we are asking the compiler to allocate 8 characters and we don't initialize it and thsi could be 
                    // very problematic. because if you use this array as a string all c-style string functions expect to 
                    // find a null character and here there may or may not be. suppose we want to display the data. Now 
                    // how do you think this would happen. How do you think c style strings are displayed. well in this case
                    // we started in the first element of the array and we iterate through the array and every we see if it's null
                    // character and if is we stop since we reached the end of the string.
    myname="frank"; //error - you might think we can initialize cstyle strings using assignment operator just like we have with other types.
                    // but this won't work. if we try to assign the cstyle literal frank to myname, we will get a compiler error.
                    // array names and literal evaluate to their location in memory so were effectively assigning one location to 
                    // another which is illegal. Think of this as saying assign 10 to 12. In order to assign one string to another we need 
                    // to use a function called strcpy that copies c style literal frank to myname array.


    There are lots of cstyle functions which c++ brings in from c programming language
    ------------------------------------------------------------------------------- 
    #include <cstring>
    - functions that work with cstyle strings
    - copying
    - concatenation
    - comparison
    - searching
    - and others

        char str[80]; 
        strcpy(str, "hello"); // copy
        strcat(str, "there"); // concatenate
        cout << strlen(str); // 10
        strcmp(str, "Another"); // -1 
        strcmp - if 0 then both are same, else if -1 when first string lexically comes before second

    #include <cstdlib> // general purpose function - includes functions to convert cstyle strings to integer, float, long etc 

*/


/* 4) working with cstyle strings

#include <iostream>
#include <cctype> // for character based functions for testing characters and converting character case 
#include <cstring> // for cstyle string -  string copying, concatenation, comparison, searching and others 
#include <cstdlib> // general purpose function - includes functions to convert cstyle strings to integer, float, long etc 
#include <vector>


using namespace std;    


int main(){


    char firstname[20];
    char fullname[20];    

    // cout << firstname << endl; // will likely get garbage

    // cout << "enter your first name" << endl;       
    // cin >> firstname; //frank  
    // cout << "length of firstname is " << strlen(firstname) << endl; // 5 - size_t


    // strcpy(fullname, firstname); 
    // strcat(fullname, " "); 
    // strcat(fullname, "einstein");
    // cout << "your full name is " << fullname << endl;     

    cout << "enter your full name";
    cin.getline(fullname, 20);  // this works with cstyle strings 

    for(size_t i{0}; i<strlen(fullname); i++){
        if(isalpha(fullname[i])){
            fullname[i] = toupper(fullname[i]);  
        }
    }
    cout << "your full name is " << fullname << endl;  

    return 0;  

}  // end of main function 

*/






#include <iostream>
#include <cctype> /* for character based functions for testing characters and converting character case */
#include <cstring> /* for cstyle string -  string copying, concatenation, comparison, searching and others */
#include <cstdlib> /* general purpose function - includes functions to convert cstyle strings to integer, float, long etc */
#include <vector>


using namespace std;    


int main(){


    char firstname[20];
    char fullname[20];    

    // cout << firstname << endl; // will likely get garbage

    // cout << "enter your first name" << endl;       
    // cin >> firstname; //frank  
    // cout << "length of firstname is " << strlen(firstname) << endl; // 5 - size_t


    // strcpy(fullname, firstname); 
    // strcat(fullname, " "); 
    // strcat(fullname, "einstein");
    // cout << "your full name is " << fullname << endl;     

    cout << "enter your full name ";
    cin.getline(fullname, 20);  // this works with cstyle strings 

    for(size_t i{0}; i<strlen(fullname); i++){
        if(isalpha(fullname[i])){
            fullname[i] = toupper(fullname[i]);  
        }
    }
    cout << "your full name is " << fullname << endl;   


    return 0;  

}  /* end of main function */