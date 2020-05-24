/* 1) overview 
    - what is pointer
    - declaring pointer
    - storing addresses in pointers
    - dereferencing pointers
    - dynamic memory allocation
    - pointer arithmetic
    - pointers and arrays
    - pass by reference with pointers
    - const and pointers
    - using pointers to funcitons
    - potential pointer pitfalls
    - what is a reference
    - review passing reference to functions
    - const and references
    - reference variables in range based for loops
    - potential reference pitfalls
    - raw vs smart pointers

*/

/* 2) what is pointer? 
    - a variable 
        - whose value is an address
    - what can be at that address
        - another variable
        - a function
    - pointers point to variables or functions
    - if x is an integer variable and its value is 10 then i can declare a pointer that points to it
    - to use the data that pointer is pointing to you must know its type

    Why use pointers?
    can't I just use the variable or function itself?
    yes, but not always
    - inside functions, pointers can be used to access data that are defined outside the function. those variables may not be in scope so you can't access them by their name
    - pointers can be used to operate on arrays very efficiently
    - we can allocate memory dynamically on the heap or free store.
        - this memory doesn't even have a variable name
        - the only way to get to it is via a pointer
    - with oo. pointers are how polymorphism works
    - can access specific addresses in memory
        - useful in embedded and systems applications
    
*/


/* 3) declaring pointers 

    int *ptr {nullptr};    
    string *strptr {nullptr}; 

    - initializing pointer variables to point nowhere
        - always initialize pointers
        - uninitialized pointers contain garbage data and can point anywhere
        - initializing to zero or nullptr(c++11) represents address zero
            - implies that the pointer is pointing nowhere
        - if you don't initialize a pointer to point to a variable or function then you should initialize it to nullptr to 'make it null' 

*/


/* 4) accessing pointer address 

    the address operator

    - variables are stored in unique address
    - unary operator
    - evaluates to the address of its operand
        - operand cannot be constant or expression that evaluates to temp values
    
    int num{10};
    cout << num; // 10
    cout << sizeof(num); // 4
    cout << &num; // 0x61ff1c

    int *p; 
    cout << "value of p is" << p; // 0x61ff60 - garbage
    cout << "address of p is " << &p; // 0x61ff18
    cout << sizeof(p); // 4
    p = nullptr; // set p to point nowhere 
    cout << p ; // 0

    size of a pointer variable
    -------------------------
    - dont confuse the size of a pointer and the size of what it points to 
    - all pointers in a program have the same size
    - they may be pointing to very large or very small types

    storing and address in pointer variable?
    ---------------------------------------
    typed pointers
    - the compiler will make sure that the address stored in a pointer variable is of the correct type

    int score {10};
    double high_temp {100.7};
    int *score_ptr {nullptr};
    score_ptr = &score; // ok 
    score_ptr = &high_temp; // compiler error


    & the address operator
    ----------------------
    - pointers are variables so they can change
    - pointers can be null
    - pointers can be uninitialized


    // Simple pointers

    #include <iostream>
    #include <vector>
    #include <string>

    using namespace std;

    int main() {
        
        int num{10};
        cout << "Value of num is: " << num << endl;		
        cout << "sizeof of num is: " << sizeof num << endl; 	
        cout << "Address of num is: " << &num << endl;	 	

    //    int *p;
    //    cout << "\nValue of p is: " << p << endl;   // garbage
    //    cout << "Address of p is: " << &p << endl;
    //    cout << "sizeof of p is: " << sizeof p<< endl;
    //    
    //    p = nullptr;
    //    cout << "\nValue of p is: " << p << endl;


    //    int *p1 {nullptr};
    //    double *p2 {nullptr};
    //    unsigned long long *p3 {nullptr};
    //    vector<string>  *p4{nullptr};
    //    string *p5 {nullptr};
    //    
    //    cout << "\nsizeof p1 is: " << sizeof p1 << endl;
    //    cout << "sizeof p2 is: " << sizeof p2 << endl;
    //    cout << "sizeof p3 is: " << sizeof p3 << endl;
    //    cout << "sizeof p4 is: " << sizeof p4 << endl;
    //    cout << "sizeof p5 is: " << sizeof p5 << endl;
        
    //    int score{10};
    //    double high_temp{100.7};
    //    
    //    int *score_ptr {nullptr};
    //    
    //    score_ptr = &score;
    //    cout << "Value of score is: " << score << endl;
    //    cout << "Address of score is: " << &score << endl;
    //    cout << "Value of score_ptr is: " << score_ptr << endl;
    //
    //   // score_ptr = &high_temp;     // Compiler error

        cout  << endl;
        return 0;
    }

*/


/* 5) dereferencing a pointer  

    - access the data we're pointing to - dereferencing a pointer
        - if scoreptr is a pointer and has a valid address
        - then you can access the data at the address contained in the scoreptr using the dereferencing operator *

    // Dereferencing
    #include <iostream>
    #include <string>
    #include <vector>

    using namespace std;

    int main() {
        
        int score {100};
        int *score_ptr {&score};

        cout << *score_ptr << endl;		// 100

        *score_ptr = 200;
        
        cout << *score_ptr << endl;		// 200
        cout << score << endl; 			// 200

        cout << "\n------------------------------" << endl;
        double high_temp {100.7};
        double low_temp {37.4};			       
        double *temp_ptr {&high_temp};    

        cout << *temp_ptr << endl;   	// 100.7    	    
        temp_ptr = &low_temp;	
        cout << *temp_ptr << endl;   	// 37.4   	    

        cout << "\n------------------------------" << endl;

        string name {"Frank"};
        string *string_ptr {&name};

        cout << *string_ptr << endl;   	// Frank   
        name = "James"; 	    
        cout << *string_ptr << endl;   	// James  
    //
        cout << "\n------------------------------" << endl;
        vector<string> stooges {"Larry", "Moe", "Curly"};
        vector<string> *vector_ptr {nullptr};
        
        vector_ptr = &stooges;
        
        cout << "First stooge: " << (*vector_ptr).at(0) << endl;    // Larry
        
        cout << "Stooges: ";
        for (auto stooge: *vector_ptr)  
            cout << stooge << " ";
        cout << endl;
        
        cout << endl;
        return 0;
    }

*/


/* 6) dynamic memory allocation 

    - allocating storage from the heap at runtime
        - we often don't know how much storage we need until we need it
        - we can allocate storage for a variaable at runtime
        - recall c++ arrays
            - we had to explicitly provide the size and it was fixed
            - but vectors grow and shrink dynamically
        - we can use pointers to access newly allocated heap storage

    using new to allocate storage
    ------------------------------
    int *intptr {nullptr}; 
    intptr = new int; // allocate an integer on the heap
    cout << intptr; // 0x2747f28
    cout << *int_ptr; // garbage
    *int_ptr =100; 
    cout << *intptr; // 100

    delete intptr; // frees the allocated storage

    int *arrptr {nullptr}; 
    arrptr = new int[size]; // allocate array on the heap
    cout arrptr; // points to first address on the array
    delete [] arrptr; // free allocated storage

*/


/* 7) relation between arrays and pointers 
    - the value of an array name is the address of the first element in the array
    - the value of a pointer variable is an address
    - if the pointer points to the same data type as the array element then the pointer and array name can be used interchangeably (almost)

    int scores[] {100, 95, 89}
    cout << scores; // 0x61fec8
    cout << *scores; // 100
    int *score_ptr {scores}
    cout << score_ptr; // 0x61fec8
    cout << *score_ptr; // 100
    cout << *(score_ptr+1); // 95
    cout << *(score_ptr+2); // 89

    subscript notation          offset notation
    array_name[index]           *(array_name+index)
    pointer_name[index]         *(pointer_name+index)

*/

/* 8) poiner arithmetic
    - pointers can be used in 
        - assignment expressions
        - arithmetic expressions
        - comparison expressions
    - c++ allows pointer arithmetic
    - pointer arithmetic only makes sense with raw arrays

    ++ and --
    ---------
    - ++ increments a pointer to point to the next array element
        intptr++
    - -- decrement a pointer to point to the previous array element
        intptr--
    
    + and -
    --------
    - ( + ) increment pointer by n * sizeof(type)
        intptr += n; 
    
    comparing two pointers == and !=
    -----------------------------------
    - determine if two pointers point to the same location
        - does not compare the date where they point
    
    string s1 {"frank"};
    string s2 {"frank"};

    string *p1 {&s1}; 
    string *p2 {&s2}; 
    string *p3 {&s1}; 

    cout << p1==p2; // false
    cout << p1==p3; // true

    cout << *p1 == *p2; // true
    cout << *p1 == *p3; // true


    // Pointer Arithmetic

    #include <iostream>

    using namespace std;

    int main() {
        
        int scores[] {100, 95, 89, 68, -1};
        int *score_ptr {scores};
        
        while (*score_ptr != -1) {
            cout << *score_ptr << endl;
            score_ptr++;
        }
        
        cout << "\n-------------------------" << endl;
        score_ptr = scores;
        while (*score_ptr != -1)
            cout << *score_ptr++ << endl;
            
        cout << "\n-------------------------" << endl;
        string s1 {"Frank"};
        string s2 {"Frank"};
        string s3 {"James"};

        string *p1 {&s1};		
        string *p2 {&s2};
        string *p3 {&s1};

        cout << boolalpha;
        cout << p1 << "==" << p2 << ": " << (p1 == p2) << endl;		// false
        cout << p1 << "==" << p3 << ": " << (p1 == p3) << endl;		// true

        cout << *p1 << "==" << *p2 << ": " << (*p1 == *p2) << endl;		// true
        cout << *p1 << "==" << *p3 << ": " << (*p1 == *p3) << endl;		// true
        
        p3 = &s3;   // point to James
        cout << *p1 << "==" << *p3 << ": " << (*p1 == *p3) << endl;		// false
        

        cout << "\n-------------------------" << endl;
        char name[]  {"Frank"};
        
        char *char_ptr1 {nullptr};
        char *char_ptr2{nullptr};
        
        char_ptr1 = &name[0];   // F
        char_ptr2 = &name[3];   // n

        cout << "In the string " << name << ",  " << *char_ptr2 << " is " << (char_ptr2 - char_ptr1) << " characters away from " <<  *char_ptr1  << endl; 
        
        cout << endl;
        return 0;
    }

*/


/* 9) const and pointers 

    - there are several ways to qualify pointers using const
        - pointer to constants
        - constant pointers
        - constant pointers to constants

    pointers to constants
    -----------------------
    - the data pointed to by the pointer is constant and cannot be changed
    - the pointer itself can change and point somewhere else

        int highscore {100};
        int lowscore {65};  
        const int *scoreptr {&highscore};
        *scoreptr = 86; // error
        scoreptr = &lowscore; // ok

    constant pointers
    ------------------
    - the data pointed to by the pointers can be changed
    - the pointer itself cannot change and point somewhere else

        int highscore {100}; 
        int lowscore {65};
        int *const scoreptr {&highscore};
        *scoreptr = 86; // ok
        scoreptr = &lowscore; // error

    constant pointers to constants
    -------------------------------
    - the data pointed to by the pointer is constant and cannot be changed
    - the pointer itself cannot change and point somewhere else

        int highscore {100}; 
        int lowscore {65};
        const int *const scoreptr {&highscore};
        *scoreptr = 86; // ok
        scoreptr = &lowscore; // error

*/


/* 10) passing pointers to functions 
    - pass by reference with pointer parameters
    - we can use pointers and dereference operator to achieve pass by reference
    - the function parameter is a pointer
    - the actual parameter can be a pointer or address of a variable

    pass by reference with pointers - defining the function
    -------------------------------------------------------
        void doubledata(int *intptr){

            *intptr *= 2; 
        } 
        int value {10};   
        doubledata(&value);
    
    // Passing Pointers 1
    #include <iostream>

    using namespace std;

    void double_data(int *int_ptr) {
    *int_ptr *= 2;	
    }

    int main() {
        int value {10};
        int *int_ptr {nullptr};
        
        cout << "Value: " << value << endl;
        double_data(&value);
        cout << "Value: " << value << endl;

        cout << "-----------------------------" << endl;
        int_ptr = &value;
        double_data(int_ptr);
        cout << "Value: " << value << endl;

        cout  << endl;
        return 0;
    }


    // Passing Pointers 2
    #include <iostream>
    #include <string>
    #include <vector>

    using namespace std;

    void swap(int *a, int *b) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }

    int main() {
        int x {100}, y {200};
        cout << "\nx: " << x <<  endl;
        cout << "y: " << y <<  endl;
        
        swap(&x, &y);
        
        cout << "\nx: " << x <<  endl;
        cout << "y: " << y <<  endl;
        
        cout  << endl;
        return 0;
    }


    // Passing Pointers 3

    #include <iostream>
    #include <string>
    #include <vector>

    using namespace std;

    void display( const vector<string> *const  v) {
    //(*v).at(0) = "Funny";
        for (auto str: *v)
            cout << str << " ";
        cout << endl;
    
    //   v = nullptr;
    }

    void display(int *array, int sentinel) {
        while (*array != sentinel)
            cout << *array++ << " ";
        cout << endl;
    }

    int main() {

    //    cout << "-----------------------------" << endl;
    //    vector<string> stooges {"Larry", "Moe", "Curly"};
    //    display(&stooges);
    
        cout << "\n-----------------------------" << endl;
        int scores[] {100,98,97,79,85,-1};
        display(scores, -1);
        
        cout  << endl;
        return 0;
    }


*/



/* 11. returning a pointer from functions

    - functions  can also return pointers
        type *function();

    - should return pointers to 
        - memory dynamically allocated in the function
        - to data that was passed in 
    
    - never return a pointer to a local function variable

    int *largest_int(int *intptr1, int *intptr2){
        if(*intptr1 > *intptr2){
            return intptr1; 
        }else{
            return intptr2; 
        }
    }
    int main(){
        int a{100};
        int b{200}; 

        int *largestptr {nullptr};
        largestptr = largest_int(&a, &b);
        cout << *largestptr; // 200
        return 0; 
    }


    never return pointer to a local variable 
    ---------------------------------------
    - in both cases the address that's being returned is a stack variable or a function local variable

        int *dontdothis(){
            int size {}; 
            ...
            return &size; 
        }

        int *orthis(){
            int size{};
            int *intptr {&size};  
            ...
            return intptr;     
        }

    // Return Pointer
    #include <iostream>

    using namespace std;

    int *create_array(size_t size, int init_value = 0) {
    int *new_storage {nullptr};
    new_storage = new int[size];   
    for (size_t i{0}; i < size; ++i)
        *(new_storage + i) = init_value;
    return new_storage;
    }

    void display(const int *const array, size_t size) {
        for (size_t i{0}; i < size; ++i)
            cout << array[i] << " ";
        cout << endl;
    }
    int main() {
        int *my_array {nullptr};
        size_t size;
        int init_value {};
        
        cout << "\nHow many integers would you like to allocate? ";
        cin >> size;
        cout << "What value would you like them initialized to? ";
        cin >> init_value;
        
        my_array = create_array(size, init_value);
        cout << "\n--------------------------------------" << endl;

        display(my_array, size);
        delete [] my_array;
        return 0;
    }

*/


/* 12) potential pointer pitfalls 
    - uninitialized pointers
    - dangling pointers
    - not checking if new failed to allocate memory
    - leaking memory

    uninitialized pointers
    ----------------------
    int *intptr; // pointing anywhere
    ...
    *intptr = 100; // hopefully a crash

    dangling pointer
    -----------------
    - pointer that is pointing to released memory
        - for example, 2 pointers point to the same data
        - 1 pointer releases the data with delete
        - the other pointer access the released data
    - pointer that points to memory that is invalid
        - we saw this when we returned a pointer to a function local variable


    not checking if new fails
    -----------------------
    - if new fails an exception is thrown
    - we can use exception handling to catch exceptions
    - dereferencing a null pointer will cause your program to crash

    leaking memory
    -------------
    - forgetting to release allocated memory with delete
    - if you lose your pointer to the storage allocated on the heap you have not way to get to that storage again
    - the memory is orphaned or leaked
    - one of the most common pointer problems

*/



/* 13) what is reference 
    - an alias for a variable
    - must be initialized to a variable when declared
    - cannot be null
    - once initialized cannot be made to refer to a different variable
    - very useful as function parameters
    - might be helpful to think of a reference as a constant pointer that is automatically dereferenced

    // References
    // Please see the section 11 examples for references as function paramters
    #include <iostream>
    #include <string>
    #include <vector>

    using namespace std;

    int main() {
        
        int num {100};
        int &ref {num};
        
        cout << num << endl;
        cout << ref << endl;
        
        num  = 200;
        cout << "\n---------------------------------" << endl;
        cout << num << endl;
        cout << ref << endl;
        
        ref = 300;
        cout << "\n---------------------------------" << endl;
        cout << num << endl;
        cout << ref << endl;
        
        cout << "\n---------------------------------" << endl;
        vector<string> stooges {"Larry", "Moe", "Curly"};

        for (auto str: stooges)     
            str = "Funny";              // str is a COPY of the each vector element
        
        for (auto str:stooges)        // No change
            cout << str << endl;
    
        cout << "\n---------------------------------" << endl;
        for (auto &str: stooges)  // str is a reference to each vector element
            str = "Funny";
        
        for (auto const &str:stooges)   // notice we are using const
            cout << str << endl;            // now the vector elements have changed
        
        cout << endl;
        return 0;
    }

*/



/* 14) lvalues and rvalues  

    lvalues
    --------
        - values that have names and are addressable
        - modifiable if they are not constants

        int x{100}; // x is an lvalue
        x=1000; 
        x=1000+20; 
        string name; // name is an lvalue
        name="frank"; 

        100 = x; // 100 is not an lvalue

    rvalues
    ---------
    - rvalue (non addressable and non assignable)
        - a value that's not an lvalue
            - on the right hand side of an assignment expression
            - a literal
            - a temporary which is intended to be non modifiable
        - rvalues can be assigned to lvalues explicitly

    lvalue references
    ------------------
    - the references we've used are lvalue references
        - because we are referencing lvalues
        
        int x{100};
        int &ref1 = x; // ref1 is reference to lvalue
        ref1 = 1000; 
        int &ref2 = 100; // error 100 is an rvalue

*/







#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    
    vector<string> stooges {"Larry", "Moe", "Curly"};
    vector<string> *vector_ptr {nullptr};      
    
    vector_ptr = &stooges;
    
    cout << "First stooge: " << (*vector_ptr).at(0) << endl;    // Larry
    
    cout << "Stooges: ";
    for (auto stooge: *vector_ptr)  
        cout << stooge << " ";
    cout << endl;
    
    cout << "address of stooges will be pointing to different than first element's address unlike array for vectors " << &stooges << endl;  //  0x7ffd9f5f07a0
    cout << "address of stooges's first element " << &stooges[0] << endl; // 0x55aed1516e70      
    cout << "value of stooges first element " << stooges[0] << endl;   

    cout << endl;

    int array[] {1, 2, 3};
    cout << "address of array is " << &array << endl;  // 0x7ffd9f5f07c0
    cout << "address of first array element is " << &array[0] << endl; // 0x7ffd9f5f07c0  
    cout << "the second array element usign offset notation " << *(array+1); // 2



    return 0;
}

