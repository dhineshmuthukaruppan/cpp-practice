/* 
    - C++ standary header files are located in 
    /usr/include/c++/<version>
    /usr/include/ 

    open command pallette - ctrl + shift + p and then c++ edit configurations ui
    to set compiler paths and options. currently we are using c++17

    - To compile a c++ program, we have to type
    g++ filename.cpp -o filename
    
    - gcc is a compiler that we use for compiling c program



 */

/* 
    6) c++ primitive data types
    char - exactly one byte and it is enough to represent 256 characters
    char16_t
    char32_t 
    wchar_t - can represent the largest available character set

    Integer types - by default integers are signed. 
    ----------------------------------------------
    <un>signed short int - atleast 16 bits
    <un>signed int - atleast 16 bit
    <un>signed long int - atleast 32 bits
    <un>signed long long int - atleast 64 bits

    Floating point type
    -------------------
    - used to represent non-integer numbers
    - represented by mantissa and exponent (scientific notation)
    - precision is the number of digits in the mantissa
    - precision and size are compiler dependent

    float - 7 decimal digits - 1.2 * 10^-38 to 3.4 * 10^38
    double - 15 decimal digits
    long double - 19 decimal digits

    Boolean type
    -----------
    bool - usually 8 bits

 */

/* 
    7) sizeof operator

    It determines the size in bytes of a type or variable
    on 32 bit compiler on a 64 bit operating system. If we run 64 bit compiler these numbers will be different
    sizeof(char) - 1
    sizeof(int) - 4
    sizeof(unsigned int) - 4 
    sizeof(short) - 2
    sizeof(long) - 4
    sizeof(long long) - 8     

    sizeof(float) - 4
    sizeof(double) - 8
    sizeof(long double) - 12


    sizeof(some_variable) 

    <climits> and <cfloat>
    - includes files contain size and precision information about your implementation in c++
    INT_MAX
    INT_MIN = -2147483648
    LONG_MIN = -2147483648
    LONG_MAX
    FLT_MIN
    FLT_MAX
    CHAR_MIN = -128
    SHRT_MIN = -32768
    LLONG_MIN = -9223372036854775808

 */


/* 
    8) constants
    - their values cannot change once declared!
    Types of constants
        - literal contants  < 12, 12U, 23L, 23LL, 12.1 -  double, 12.1F - float, 12.1L - long double> 

        - declared constants
            - const  // keyword 
            const double pi {3.213}; 
            pi = 2.5; // compiler error

        - constant expressions
            - constexpr // keyword

        - enumerated constants
            - enum // keyword

        - Defined constants
            - #define pi 3.21 // don't use constants in modern c++

 */



#include <iostream>
#include <climits> //make sure you include climits for integer types 
// similar information for floating point numbers is contained in <cfloat>

using namespace std;   


/* unlike local variables global variables are automatically initialized to zero. When the compiler runs the 
program it checks for the local variable with that name first. If found global variable will not be used.  */
int age {18};    

int main(){

    // int age; // uninitialized
    // int age = 21;  // c like initialization
    // int age (21);  // constructor initialization

    int age {21}; // c++11 list initialization syntax and if we use this type of initialization, it will catch problems for us in the compile time

    int room_width {0};  
    cout << "Enter the width of the room " << endl;  
    cin >> room_width;    

    cout << "The width of the room is " << room_width << " and the age of the person living there is " << age << endl;    

    char middle_initial {'j'};    

    unsigned short int exam_score {55}; 
    long people_in_florida {2061000};   
    long long people_on_earth {7'6000'000'000}; 

    float car_payment {401.23};  
    
    bool game_over {true};        

    cout << "GAME STATUS " << game_over << endl;       

    cout << "size of int in bytes " << sizeof(int) << endl; // 4
    cout << "size of float in bytes " << sizeof(float) << endl; // 4
    cout << "size of double in bytes " << sizeof(double) << endl; // 8   


    return 0;       

}  /* end of main function  */


