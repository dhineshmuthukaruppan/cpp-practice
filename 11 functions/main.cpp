/* 1) overview

    functions
    - definition
    - prototype
    - parameters and passbyvalue
    - return statement
    - default parameter values
    - overloading
    - passing arrays to function
    - passbyreference
    - inline functions
    - auto return type
    - recursive functions


    - write your code to the function specification
    - understand what the function does
    - understand what information function needs
    - understand what functions returns
    - understand any errors the function may produce
    - understand any performance constraints
    - don't worry about how the function works internally
        - unless you are the one writing the function

    Example <cmath>
    - common mathematical calculations
    - global functions called as

    sqrt(400.0);
    pow(2.0, 3.0); 
    sin(num); 
    ceil(num); 
    floor(num);
    round(num);

*/


/* 4) defining functions

    - name 
        - the name of the funciton
        - same rules as for variables
        - should be meaningful
        - usually a very or verb phrase
    
    - parameter list
        - the variables passed into functions
        - their types must be specified
    
    - return type
        - the type of the data that is returned from the function
    
    - body
        - the statements that are executed when the funciton is called
        - in curly braces {}
    
    - calling functions
        - functions can call other functions
        - compiler must know the function details before it is called

*/


/* 5) function prototypes

    - the compiler must know about a function before it is used. 
    - define functions before calling them
        - ok for small programs
        - not a practical solutions for larger programs
    - use function prototypes
        - tells the compiler what it needs to know without a full function definition
        - also called forward declarations
        - placed at the beginning of the program
        - also used in our own header files .h 


        int function_name();  // prototype
        int function_name(int); // prototype 
                                // or 
        int function_name(int a); // prototype

        int function_name(int a){
            statemets(s);
            return 0; 
        }

    A function with no return type and no parameters

        void say_hello();    

*/

/* 6) function parameters and return statements

    - when we call a function we can pass in data to that function
    - in the function call they are called arguments
    - in the function definition they are called parameters
    - they must match in number, order and in type

    int add_numbers(int, int); //prototype
    int main(){
        int result {0};
        result = add_numbers(100, 200); //call - actual parameters
        return 0;   
    }
    int add_numbers(int a, int b){ // formal parameters - copy of actual 
        return a+b;    
    }

    pass-by-value
    - when you pass data into a function it is passed by value
    - a copy of data is passed to the function
    - whatever changes you make to the parameter in the function does not affect the argument that was passed in 
    - formal vs actual parameters
        - formal parameters - the parameters defined in the function header
        - actual parameters - the parameters used in the function call, the arguments. 

    function return statements
    -------------------------
    - if a function  returns a value then it must use a return statement that returns a value
    - if function does not return a value(void) then the return statement is optional
    - return statement can occur anywhere in the body of the function
    - return statement immediately exits the function
    - we can have multiple return statements in a function
        - avoid many return statements in a function
    - the return value is the result of the function call

    #include <iostream>
    #include <string>
    #include <vector>

    using namespace std;

    void pass_by_value1(int num);
    void pass_by_value2(string s);
    void pass_by_value3(vector<string> v);
    void print_vector(vector<string> v);

    void pass_by_value1(int num) {
        num = 1000;
    }

    void pass_by_value2(string s) {
        s = "Changed";
    }

    void pass_by_value3(vector<string> v) {
        v.clear();  // delete all vector elements
    }

    void print_vector(vector<string> v) {
        for (auto s: v) 
            cout << s << " ";
        cout << endl;
    }

    int main() {
        int num {10};
        int another_num {20};
        
        cout << "num before calling pass_by_value1: " << num << endl;
        pass_by_value1(num);
        cout << "num after calling pass_by_value1: " << num << endl;
        
        cout << "\nanother_num before calling pass_by_value1: " << another_num << endl;
        pass_by_value1(another_num);
        cout << "another_num after calling pass_by_value1: " << another_num << endl;

        string name {"Frank"};
        cout << "\nname before calling pass_by_value2: " << name << endl;
        pass_by_value2(name);
        cout << "name after calling pass_by_value2: " << name << endl;

        vector<string> stooges {"Larry", "Moe", "Curly"};
        cout << "\nstooges before calling pass_by_value3: ";
        print_vector(stooges);
        pass_by_value3(stooges);
        cout << "stooges after calling pass_by_value3: ";
        print_vector(stooges);
        
        cout << endl;
        return 0;
    }

*/


/* 8) default argiment value
    - when a function is called, all arguments must be supplied
    - sometimes some of the arguments have the same value most of the time
    - we can tell the compiler to use default values if the arguments are not supplied
    - default values can be in the prototype or definition, not both
        - best practice - in the prototype
        - must appear at the tail end of the parameter list
    - can have multiple default values
        - must appear consecutively at the tail end of the parameter list

    #include <iostream>
    #include <iomanip>
    #include <string>

    using namespace std;

    double calc_cost(double base_cost = 100.0, double tax_rate = 0.06, double shipping = 3.50);

    void greeting(string name,  string prefix = "Mr.", string suffix = "");

    double calc_cost(double base_cost, double tax_rate, double shipping) {
        return base_cost += (base_cost * tax_rate) + shipping;
    }

    void greeting(string name,  string prefix, string suffix) {
        cout << "Hello " << prefix + " " + name + " " + suffix << endl;
    }


    int main() {
        double cost{ 0 };
        cost = calc_cost(100.0, 0.08, 4.25);        // will use no defaults  100 + 8 + 4.25 
        
        cout << fixed << setprecision(2);
        cout << "Cost is: " << cost << endl;    // 112.25
        
        cost = calc_cost(100.0, 0.08);                  // will use default shipping  100 + 8 + 3.50 
        cout << "Cost is: " << cost << endl;    // 111.50

        cost = calc_cost(200.0);                         // will use default tax and shipping   200 + 12 + 3.50
        cout << "Cost is: " << cost << endl;    // 215.50
        
        cost = calc_cost();
        cout << "Cost is: " << cost << endl;    // 100 + 6 + 3.50
        
        greeting("Glenn Jones", "Dr.", "M.D.");
        greeting("James Rogers", "Professor", "Ph.D.");
        greeting("Frank Miller", "Dr.");
        greeting("William Smith");
        greeting("Mary Howard", "Mrs.", "Ph.D.");

        cout << endl;
        return 0;
    }
*/


/* 10) overloading functions
    - we can have functions that have different parameter lists that have the same name
    - abstraction mechanism since we can just think print for example
    - a type of polymorphism
        - we can have same name work with different data types to execute similar behaviour
    - the compiler must be able to tell the functions apart based on the parameter lists and arguments supplied

        void display(int n);
        void display(double d); 
        void display(std::string s);
        void display(std::string s, std::string t);
        void display(std::vector v);      

        - return type is not considered


        // Function Overloading
        #include <iostream>
        #include <string>
        #include <vector>

        using namespace std;

        void print(int);
        void print(double);
        void print(string);
        void print(string, string);
        void print(vector<string>);

        void print(int num) {
            cout << "Printing int: " << num << endl;
        }

        void print(double num) {
            cout << "Printing double: " << num << endl;
        }

        void print(string s) {
            cout << "Printing string: " << s << endl;
        }

        void print(string s, string t) {
            cout << "Printing 2 strings: " << s << " and " << t << endl;
        }

        void print(vector<string> v) {
            cout << "Printing vector of strings: " ;
            for (auto s: v )
                cout << s + " ";
            cout << endl;
        }

        int main() {
            print(100);    // int
            print('A');     //  character is always promoted to int should print 65 ASCII ('A')
            
            print(123.5);   // double
            print(123.3F);  // Float is promoted to double
            
            print("C-style string");  // C-style string is converted to a C++ string
            
            string s {"C++ string"};    
            print(s);       // C++ string
            
            print("C-style string", s); // First argument is converted to a C++ string
            
            vector<string> three_stooges {"Larry", "Moe", "Curly"};
            print(three_stooges);
            
            cout << endl;
            return 0;
        }

*/


/* 12) passing arrays to functions

    - we can pass an array to a function by providing square brackets in the formal parameter description
        void print_array(int numbers []);

    - the array elements are not copied
    - since the array name evaluates to the location of the array in memory- this address is what is copied
    - so the function has no idea how many elements are in the array since all it knows is the location of the first element(the name of the array)

    - since we are passing the location of the array
        - the function can modify the actual array
    
        void zero_array(int numbers [], size_t size){
            for(size_t i{0}; i<size; i++){
                numbers[i]=0; //zero out the array element
            }
        }

        int main(){
            int my_numbers[] {1,2,3,4,5}; 
            zero_array(my_numbers, 5);
            print_array(my_numbers, 5); // 0 0 0 0 0
            return 0;   
        }

    Const parameters
    -----------------
    - we can tell the compiler that function parameters are const (read-only)
    - this could be useful in the print_array function since it should not modify the array

    void print_array(const int numbers []){ 
        // any attempt to modify the array will result in compiler error
    }


    // Arrays and functions  
    #include <iostream>

    using namespace std;

    void print_array(const int arr[], size_t size);
    void set_array(int arr[], size_t size, int value);

    void print_array(const int arr[], size_t size) {  // const
        for (size_t i{0}; i < size; ++i)
            cout << arr[i] << " ";
        cout << endl;
    // arr[0] = 50000; // bug
    }

    // set each array element to value
    void set_array(int arr[], size_t size, int value) {
        for (size_t i{0}; i < size; ++i)
            arr[i] = value;
    }

    int main() {
        int my_scores[] {100, 98, 90, 86, 84};
        
        print_array(my_scores, 5);
        set_array(my_scores, 5, 100);
        print_array(my_scores, 5);
        print_array(my_scores, 5);
        
        cout << endl;
        return 0;
    }

*/


/* 14) pass by reference

    - sometimes we want to be able to change the actual parameter from within the function body
    - inorder to achieve this we need the location or address of the actual parameter
    - we saw how this is the effect with array, but what about other variable types?
    - we can use reference parameters to tell the compiler to pass in a reference to the actual parameter
    - the formal parameter will now be an alias for the actual parameter

        void swap(int &a, int &b){
            int temp = a; 
            a = b; 
            b = temp; 
        }

        int main(){
            int x{10}, y{20}; 
            swap(x, y);

            return 0;  
        }

    vector example - pass by value
    ------------------------------
    - notice that in this case we're using pass by value inside the print function
    - but there's one issue that is we're using pass by value so we're making a complete copy of the vector object in the function.
    - so the formal parameter v will be a copy of the actual parameter data. 
    - In this case in order to make a copy we need to allocate storage and copy values over. 
    - if the vector is very large we could run into performance and storage issues.
    
        void print(std::vector<int> v);
        int main(){
            std::vector<int> data {1, 2, 3, 4, 5}; 
            print(data);
            return 0;  
        }

        void print(std::vector<int> v){
            for(auto num: v){
                cout << num << endl; 
            }
        }


    vector example - pass by reference
    -----------------------------------
        void print(std::vector<int> &v);
        int main(){
            std::vector<int> data {1, 2, 3, 4, 5}; 
            print(data);
            return 0;  
        }

        void print(std::vector<int> &v){
            for(auto num: v){
                cout << num << endl; 
            }
        }

    vector exmaple - pass by const reference
    ---------------------------------------
        void print(const std::vector<int> &v);
        int main(){
            std::vector<int> data {1, 2, 3, 4, 5}; 
            print(data);
            return 0;  
        }

        void print(const std::vector<int> &v){
            v.at(0) = 200; // error
            for(auto num: v){
                cout << num << endl; 
            }
        }


    // Pass-by-reference

    #include <iostream>
    #include <string>
    #include <vector>

    using namespace std;

    void pass_by_ref1(int &num);
    void pass_by_ref2(string &s);
    void pass_by_ref3(vector<string> &v);
    void print_vector(const vector<string> &v);  // const

    void pass_by_ref1(int &num) {
        num = 1000;
    }

    void pass_by_ref2(string &s) {
        s = "Changed";
    }

    void pass_by_ref3(vector<string> &v) {
        v.clear();  // delete all vector elements
    }

    void print_vector( const vector<string> &v)  {
        for (auto s: v) 
            cout << s << " ";
        cout << endl;
    }

    int main() {
        int num {10};
        int another_num {20};
        
        cout << "num before calling pass_by_ref1: " << num << endl;
        pass_by_ref1(num);
        cout << "num after calling pass_by_ref1: " << num << endl;
        
        cout << "\nanother_num before calling pass_by_ref1: " << another_num << endl;
        pass_by_ref1(another_num);
        cout << "another_num after calling pass_by_ref1: " << another_num << endl;

        string name {"Frank"};
        cout << "\nname before calling pass_by_ref2: " << name << endl;
        pass_by_ref2(name);
        cout << "name after calling pass_by_ref2: " << name << endl;

        vector<string> stooges {"Larry", "Moe", "Curly"};
        cout << "\nstooges before calling pass_by_ref3: ";
        print_vector(stooges);
        pass_by_ref3(stooges);
        cout << "stooges after calling pass_by_ref3: ";
        print_vector(stooges);
        
        cout << endl;
        return 0;
    }

*/



/* 16) scope rules 
    - c++ scope rules to determine where an identifier can be used
    - c++ uses static or lexical scoping
    - local or block scope
    - global scope

    local or block scope
    ---------------------
    - identifiers declared in a block {}
    - function parameters have block scope
    - only visible within the block {} where declared
    - function local variables are only active while the function is executing
    - local variables are not preserved between function calls
    - with nested blocks inner blocs can 'see' but outer blocs cannot 'see' in

    static local variables
    ----------------------
    - declared with static qualifier
        static int value {10}; 

    - value is preserved between function calls
    - only initialized the first time the function is called 

    global scope
    -----------
    - identifier declared outside any function or class
    - visible to all parts of the program after the global identifier has been declared 
    - global constants are ok
    - best practice - don't use global variables


    // Scope example
    #include <iostream>

    using namespace std;

    void local_example();
    void global_example();
    void static_local_example();

    int num {300};    // Global variable - declared outside any class or function

    void global_example() {
        cout << "\nGlobal num is: " << num << " in global_example - start" << endl;
        num *= 2;
        cout << "Global num is: " << num << " in global_example - end" << endl;
    }

    void local_example(int x) {
        int num {1000};     // local to local_example
        cout << "\nLocal num is: " << num << " in local_example - start" << endl;
        num=x;
        cout << "Local num is: " << num << " in local_example - end" << endl;
        // num1 in main is not within scope - so it can't be used here.
    }

    void static_local_example() {
        static int num {5000};      // local to static_local_example static - retains it value between calls
        cout << "\nLocal static  num is: " << num << " in static_local_example - start" << endl;
        num += 1000;
        cout << "Local static  num is: " << num << " in static_local_example - end" << endl;
    }

    int main() {
        
        int num {100};  // Local to main
        int num1 {500}; // Local to main
        
        cout << "Local num is : " << num << " in main" << endl;
        
        {   // creates a new level of scope
            int num {200};  // local to this inner block
            cout << "Local num is: " << num << " in inner block in main" << endl;
            cout << "Inner block in main can see out - num1 is: " << num1 << endl;
        }
        
        cout << "Local num is : " << num << " in main" << endl;

        local_example(10);
        local_example(20);
        
        global_example();
        global_example();
        
        static_local_example();
    //    static_local_example();
    //    static_local_example();

        cout << endl;
        return 0;
    }

*/



/* 17) how do function calls works 
    - functions use the "function call stack"
        - analogous to a stack of books
        - LIFO
        - push and pop
    
    - stack frame or activation record
        - functions must return control to function that called it
        - each time a function is called we create an new activation record and push it on stack
        - when function terminates we pop the activation record and return
        - local variables and function parameters are allocated on the stack
    - stack size is finite - stack overflow

    memory
    ------
    1) heap
    2) stack
    3) static variables
    4) code area


    stack
    ------
    func2 x= alias of result, y=10, z=20
    func1 a=10, b=20, result=30
    main x=10, y=20, z=0


    // How function calls work
    // The call stack
    #include <iostream>

    using namespace std;

    void func2(int &x, int y, int z) {
        x+= y + z;
    }

    int func1(int a, int b) {
        int result {};
        result = a + b;
        func2(result, a , b);
        return result;
    }

    int main() {
        int x {10};
        int y{20};
        int z{};
        z = func1(x,y);
        cout << z << endl;
        return 0;
    }

    What typically happens when main calls func1 (or any function calls another) ?
    There are other ways to acheive the same results :)
    
    main:
        push space for the return value
        push space for the parameters
        push the return address
        transfer control to func1 (jmp)
    func1:
        push the address of the previous activation record
        push any register values that will need to be restored before returning to the caller
        perform the code in func1
        restore the register values
        restore the previous activation record (move the stack pointer)
        store any function result
        transfer control to the return address (jmp)
    main:
        pop the parameters
        pop the return value
*/


/* 18) inline functions 
    - function calls have a certain amount of overhead
    - you saw what happens on the call stack
    - sometimes we have simple functions
    - we can suggest to the compiler to compile them inline
        - avoid function call overhead
        - generate inline assembly code
        - faster 
        - could cause code bloat
    - compilers optimizations are very sophisticated
        -will likely inline even without your suggestion

*/


/* 19) recursive functions  
    - a recursive function is a function that calls itself
        - either directly or indirectly through another function
    - recursive problem solving
        - base case
        - divide the rest of problem into subproblem and do recursive call
    - there are many problems that lend themselves to recursive solutions
    - mathematic - factorial, fibonacci, fractals
    - searching and sorting - binary search, search trees

    base case 
        factorial(0) = 1
    
    recursive case
        factorial(n) = n * factorial(n-1)    

    important notes
    ---------------
    - if recursion doesn't eventually stop you will have infinite recursion
    - recursion can be resource intensive
    - remember the base case
        - it terminates the recursion
    - only use recursive solutions when it makes sense
    - anything that can be done recursively can be done iteratively
        - stackoverflw error

*/


#include <iostream> 
#include <cmath>
#include <cstdlib> // reguired for rand()
#include <ctime> // required for time()

using namespace std;   

const double pi {3.14}; 

double calc_area_circle(double radius); 


int main(){
    int random_number {};  
    size_t count {10};  
    int min {1};
    int max {6}; 

    // seed the random number generator
    // if you don't seed the generator you will get the same sequence random number every run

    cout << RAND_MAX << endl; 

    srand(time(nullptr)); 

    for(size_t i{1}; i<=count; i++){
        random_number =  rand() % max + min; // generates a random number [ min, max ]
        cout << random_number << endl;   
    } 

    cout << calc_area_circle(5) << endl;         
    
    return 0;   

}  /* end of main function */

double calc_area_circle(double radius){
    return pi * radius * radius;    

}

