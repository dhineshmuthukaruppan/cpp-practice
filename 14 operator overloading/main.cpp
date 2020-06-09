/* 1) overview

    Operator overloading
    - what is operator overloading
    - overloading the assignment operator (=)
        - copy semantics
        - move semantics
    - overloading operators as member functions
    - overloading operators as global functions
    - overloading stream insertion << and extraction operators >>
    
*/


/* 2) what is operator overloading 

    - using traditional operators such as +, =, * with user defined types
    - allows user defined types to behave similar to builtin types
    - can make code more readable and writable
    - not done automatically (except for the assignment operator). they must be explicitly defined

    suppose we have a number class that models any number

    - using function
        Number result = multiply(add(a, b), divide(c, d));

    - using member methods
        Number result = (a.add(b)).multiply(c.divide(d));   

    - using overloaded operators
        Number result = (a+b) * (c/d);   

    - majority of c++'s operators can be overloaded
    - the following operators cannot be overloaded 
        ::
        :?
        .*
        .
        sizeof
    
    some basic rules
    -----------------
    - precedence and associativity cannot be changed
    - arity cannot be changed ie. can't make the division operator unary
    - can't overload operators for primitive type eg. int, double etc.
    - cant create new operators
    - [], (), -> and the assignment operator (=) must be declared as member methods
    - other operators can be declared as member methods or global functions



    Mystring.h
    ------------
    #ifndef _MYSTRING_H_
    #define _MYSTRING_H_

    class Mystring
    {
    private:
        char *str;      // pointer to a char[] that holds a C-style string
    public:
        Mystring();                              // No-args contstructor
        Mystring(const char *s);                 // Overloaded contstructor              
        Mystring(const Mystring &source);        // Copy constructor
        ~Mystring();                             // Destructor
        void display() const;
        int get_length() const;                  // getters
        const char *get_str() const;
    
    };

    #endif // _MYSTRING_H_




    // Mystring - starting point - main.cpp
    #include <iostream>
    #include "Mystring.h"

    using namespace std;

    int main() {
        Mystring empty;                      // no-args constructor
        Mystring larry("Larry");             // overloaded constructor
        Mystring stooge {larry};            // copy constructor 
        
        empty.display();
        larry.display();
        stooge.display();
        
        return 0;
    }





    Mystring.cpp
    --------------
    #include <cstring>
    #include <iostream>
    #include "Mystring.h"

    // No-args constructor
    Mystring::Mystring() 
        : str{nullptr} {
        str = new char[1];
        *str = '\0';
    }

    // Overloaded constructor
    Mystring::Mystring(const char *s) 
        : str {nullptr} {
            if (s==nullptr) {
                str = new char[1];
                *str = '\0';
            } else {
                str = new char[std::strlen(s)+1];
                std::strcpy(str, s);
            }
    }

    // Copy constructor
    Mystring::Mystring(const Mystring &source) 
        : str{nullptr} {
            str = new char[std::strlen(source.str )+ 1];
            std::strcpy(str, source.str);
    }

    // Destructor
    Mystring::~Mystring() {
        delete [] str;
    }

    // Display method
    void Mystring::display() const {
        std::cout << str << " : " << get_length() << std::endl;
    }

    // length getter
    int Mystring::get_length() const { return std::strlen(str); }
    
    // string getter
    const char *Mystring::get_str() const { return str; }



*/


/* 3) overloading the assignment operator 

    - don't confuse assignment with initialization. Initialization is done by constructors when we create new objects. 

    copy assignment operator
    ----------------------------
    - c++ provides a default assignment operator used for assigning one object to another

    Mystring s1 {"frank"};
    Mystring s2 = s2; // not assignment
                        // same as Mystring s2{s1}

    s2 = s1; // assignment

    - default is memberwise assignment (shallow copy)
        - if we have raw pointer data member we must deep copy


    overloading the copy assignment operator (deep copy)
    ----------------------------------------------------
    Type &Type::operator=(const Type &rhs);

    s2 = s1; // we write this

    s2.operator=(s1); // operator= method is called

    code 
    -----
        Mystring &Mystring::operator=(const Mystring &rhs){
            if(this == &rhs){  // p1 = p1
                return *this;  // return current object
            }

            // deallocate storage for this->str since we are overwriting it
            delete [] str; 

            // allocate storage for deep copy
            str = new char[std::strlen(rhs.str)+1];

            // perform the copy
            std::strcpy(str, rhs.str);
            
            // return the current by reference to allow chain assignment
            return *this; 
        }

        // s1 = s2 = s3; 


    main.cpp
    ---------
    // Overloading copy assignment
    #include <iostream>
    #include <vector>
    #include "Mystring.h"

    using namespace std;

    int main() {
        Mystring a {"Hello"};                // overloaded constructor
        Mystring b;                             // no-args contructor
        b = a;                                      // copy assignment 
                                                    // b.operator=(a)  function is getting called
        
        b = "This is a test";  // b.operator=("This is a test");  - 17.00 minutes
                                // it will call the overloaded constructor which is going to create a temporary object and now that 
                                // temporary object will be assigned using copy assignment. After the copy assignment that temporary object 
                                // is deleted using destructor. 
    
        Mystring empty;                      // no-args constructor
        Mystring larry("Larry");             // overloaded constructor
        Mystring stooge {larry};            // copy constructor 
        Mystring stooges;                   // no-args constructor
        
        empty = stooge;                     // copy assignment operator
        
        empty.display();                      // Larry : 5
        larry.display();                         // Larry : 5
        stooge.display();                     // Larry : 5
        empty.display();                      // Larry : 5
        
        stooges = "Larry, Moe, and Curly";  
        stooges.display();                              // Larry, Moe, and Curly : 21
        
        vector<Mystring> stooges_vec;
        stooges_vec.push_back("Larry");
        stooges_vec.push_back("Moe");
        stooges_vec.push_back("Curly");
        
        cout << "=== Loop 1 ==================" << endl;
        for (const Mystring &s: stooges_vec) 
            s.display();                                        // Larry
                                                                    // Moe
                                                                    //Curly
        cout << "=== Loop 2 ==================" << endl;
        for (Mystring &s: stooges_vec)
            s = "Changed";                              // copy assignment
            
        cout << "=== Loop 3 ================" << endl;
        for (const Mystring &s: stooges_vec) 
            s.display();                                     // Changed
                                                                // Changed
                                                                // Changed
        
        return 0;
    }


    Mystring.cpp
    ------------
    #include <cstring>
    #include <iostream>
    #include "Mystring.h"

    // No-args constructor
    Mystring::Mystring() 
        : str{nullptr} {
        str = new char[1];
        *str = '\0';
    }

    // Overloaded constructor
    Mystring::Mystring(const char *s) 
        : str {nullptr} {
            if (s==nullptr) {
                str = new char[1];
                *str = '\0';
            } else {
                str = new char[std::strlen(s)+1];
                std::strcpy(str, s);
            }
    }

    // Copy constructor
    Mystring::Mystring(const Mystring &source) 
        : str{nullptr} {
            str = new char[std::strlen(source.str) + 1];
            std::strcpy(str, source.str);
    }

    // Destructor
    Mystring::~Mystring() {
        delete [] str;
    }

    // Copy assignment
    Mystring &Mystring::operator=(const Mystring &rhs) {
        std::cout << "Copy assignment" << std::endl;
        if (this == &rhs)
            return *this;
        delete [] this->str;
        str = new char[std::strlen(rhs.str) + 1];
        std::strcpy(this->str, rhs.str);
        return *this;
    }


    // Display method
    void Mystring::display() const {
        std::cout << str << " : " << get_length() << std::endl;
    }

    // getters
    int Mystring::get_length() const { return strlen(str); }
    const char *Mystring::get_str() const { return str; }



    Mystring.h
    -----------
    #ifndef _MYSTRING_H_
    #define _MYSTRING_H_

    class Mystring
    {
    private:
        char *str;      // pointer to a char[] that holds a C-style string
    public:
        Mystring();                                                         // No-args constructor
        Mystring(const char *s);                                     // Overloaded constructor
        Mystring(const Mystring &source);                    // Copy constructor
        ~Mystring();                                                      // Destructor
        
        Mystring &operator=(const Mystring &rhs);       // Copy assignment
        
        void display() const;

        int get_length() const;                                       // getters
        const char *get_str() const;
    };

    #endif // _MYSTRING_H_


*/



/* 4) overloading the assignment operator - move 

    move assignment operator (=)
    - you can choose to overload the move assignment operator
        - c++ will use the copy assignment operator if necessary
    
        Mystring s1; 
        s1 =  Mystring {"frank"}; // move assignment

    - if we have raw pointer we should overload the move assignment operator for efficiency

    Type &Type::operator=(Type &&rhs);  

    Mystring &Mystring::operator=(Mystring &&rhs);

    s1 = Mystring("joe"); // move operator= called
    s1 = "frank"; // move operator= called

    

    main.cpp
    --------
    // Overloading move constructor and move assignment operator
    #include <iostream>
    #include <vector>
    #include "Mystring.h"

    using namespace std;

    int main() {
        
        Mystring a{"Hello"};                // Overloaded constructor
        a = Mystring{"Hola"};              // Overloaded constructor then move assignment
        a = "Bonjour";                         // Overloaded constructor then move assignment
        
    
        Mystring empty;                      // no-args constructor
        Mystring larry("Larry");             // overloaded constructor
        Mystring stooge {larry};            // copy constructor 
        Mystring stooges;                   // no-args constructor
        
        empty = stooge;                     // copy assignment operator
                                                    // stooge is an l-value
        
        empty = "Funny";                    // move assignment operator
                                                    // "Funny" is an r-value
        
        empty.display();
        larry.display();
        stooge.display();
        empty.display();
        
        stooges = "Larry, Moe, and Curly";  
        stooges.display();
        
        vector<Mystring> stooges_vec;
        stooges_vec.push_back("Larry");                // Move constructor
        stooges_vec.push_back("Moe");                // Move constructor
        stooges_vec.push_back("Curly");              // Move constructor    
        
        cout << "=== Loop 1 ==================" << endl;
        for (const Mystring &s: stooges_vec) 
            s.display();
            
        cout << "=== Loop 2 ==================" << endl;
        for (Mystring &s: stooges_vec)
            s = "Changed";                                      // move assignment
            
        cout << "=== Loop 3 ==================" << endl;
        for (const Mystring &s: stooges_vec) 
            s.display();
            
        
        return 0;
    }


    Mystring.cpp
    -----------#include <iostream>
    #include <cstring>
    #include "Mystring.h"

    // No-args constructor
    Mystring::Mystring() 
        : str{nullptr} {
        str = new char[1];
        *str = '\0';
    }

    // Overloaded constructor
    Mystring::Mystring(const char *s) 
        : str {nullptr} {
            if (s==nullptr) {
                str = new char[1];
                *str = '\0';
            } else {
                str = new char[strlen(s)+1];
                strcpy(str, s);
            }
    }

    // Copy constructor
    Mystring::Mystring(const Mystring &source) 
        : str{nullptr} {
            str = new char[strlen(source.str)+ 1];
            strcpy(str, source.str);
            std::cout << "Copy constructor used" << std::endl;

    }

    // Move constructor
    Mystring::Mystring( Mystring &&source) 
        :str(source.str) {
            source.str = nullptr;
            std::cout << "Move constructor used" << std::endl;
    }

    // Destructor
    Mystring::~Mystring() {
        if (str == nullptr) {
            std::cout << "Calling destructor for Mystring : nullptr" << std::endl;
        } else {
            std::cout << "Calling destructor for Mystring : " << str << std::endl;
        }
        delete [] str;
    }

    // Copy assignment
    Mystring &Mystring::operator=(const Mystring &rhs) {
        std::cout << "Using copy assignment" << std::endl;

        if (this == &rhs) 
            return *this;
        delete [] str;
        str = new char[strlen(rhs.str) + 1];
        strcpy(str, rhs.str);
        return *this;
    }

    // Move assignment
    Mystring &Mystring::operator=(Mystring &&rhs) {
        std::cout << "Using move assignment" << std::endl;
        if (this == &rhs) 
            return *this;
        delete [] str;
        str = rhs.str;
        rhs.str = nullptr;
        return *this;
        
    }

    // Display method
    void Mystring::display() const {
        std::cout << str << " : " << get_length() << std::endl;
    }

    // getters
    int Mystring::get_length() const { return strlen(str); }
    const char *Mystring::get_str() const { return str; }


    Mystring.h
    -----------
    #ifndef _MYSTRING_H_
    #define _MYSTRING_H_

    class Mystring
    {
    private:
        char *str;      // pointer to a char[] that holds a C-style string
    public:
        Mystring();                                                         // No-args constructor
        Mystring(const char *s);                                     // Overloaded constructor
        Mystring(const Mystring &source);                    // Copy constructor
        Mystring( Mystring &&source);                         // Move constructor
        ~Mystring();                                                     // Destructor
        
        Mystring &operator=(const Mystring &rhs); // Copy assignment
        Mystring &operator=(Mystring &&rhs);        // Move assignment
        
        void display() const;
        
        int get_length() const;                                       // getters
        const char *get_str() const;
    };

    #endif // _MYSTRING_H_

*/



/* 5) overloading operators as member functions 

    unary operators as member methods (++, --, -, !)
    binary operators as member methods (+, -, ==, !=, <, >)   


    main.cpp
    ----------
    // Overloading operators as member methods
    #include <iostream>
    #include "Mystring.h"

    using namespace std;

    int main() {
        cout << boolalpha << endl;
        
        Mystring larry{"Larry"}; 
        Mystring moe{"Moe"};
        
        Mystring stooge = larry;
        larry.display();                                                                      // Larry
        moe.display();                                                                      // Moe
        
        cout << (larry == moe) << endl;                                         // false
        cout << (larry == stooge) << endl;                                      // true

        larry.display();                                                                    // Larry
        Mystring larry2 = -larry;
        larry2.display();                                                                    // larry
        
        Mystring stooges = larry + "Moe";                                     // ok with member function
        //Mystring stooges = "Larry" + moe;                                 // Compiler error
        
        Mystring two_stooges = moe + " " + "Larry";
        two_stooges.display();      
                                                    // Moe Larry
        Mystring three_stooges = moe + " " + larry + " " +  "Curly";
        three_stooges.display();                                                        //  Moe Larry Curly
        
        return 0;
    }


    Mystring.cpp
    ------------
    #include <iostream>
    #include <cstring>
    #include <cctype>
    #include "Mystring.h"

    // No-args constructor
    Mystring::Mystring() 
        : str{nullptr} {
        str = new char[1];
        *str = '\0';
    }

    // Overloaded constructor
    Mystring::Mystring(const char *s) 
        : str {nullptr} {
            if (s==nullptr) {
                str = new char[1];
                *str = '\0';
            } else {
                str = new char[std::strlen(s)+1];
                std::strcpy(str, s);
            }
    }

    // Copy constructor
    Mystring::Mystring(const Mystring &source) 
        : str{nullptr} {
            str = new char[std::strlen(source.str)+ 1];
            std::strcpy(str, source.str);
            std::cout << "Copy constructor used" << std::endl;
    }

    // Move constructor
    Mystring::Mystring( Mystring &&source) 
        :str(source.str) {
            source.str = nullptr;
            std::cout << "Move constructor used" << std::endl;
    }

    // Destructor
    Mystring::~Mystring() {
        delete [] str;
    }

    // Copy assignment operator
    Mystring &Mystring::operator=(const Mystring &rhs) {
        std::cout << "Using copy assignment" << std::endl;

        if (this == &rhs) 
            return *this;
        delete [] str;
        str = new char[std::strlen(rhs.str) + 1];
        std::strcpy(str, rhs.str);
        return *this;
    }

    // Move assignment operator
    Mystring &Mystring::operator=( Mystring &&rhs) {
        std::cout << "Using move assignment" << std::endl;
        if (this == &rhs) 
            return *this;
        delete [] str;
        str = rhs.str;
        rhs.str = nullptr;
        return *this;
    }

    // Equality
    bool Mystring::operator==(const Mystring &rhs) const {
        return (std::strcmp(str, rhs.str) == 0);
    }

    // Make lowercase
    Mystring Mystring::operator-() const {
        char *buff= new char[std::strlen(str) + 1];
        std::strcpy(buff, str);
        for (size_t i=0; i<std::strlen(buff); i++)
            buff[i] = std::tolower(buff[i]);
        Mystring temp {buff};
        delete [] buff;
        return temp;
    }

    // Concatentate
    Mystring Mystring::operator+(const Mystring &rhs) const {
        char *buff = new char[std::strlen(str) + std::strlen(rhs.str) + 1];
        std::strcpy(buff, str);
        std::strcat(buff, rhs.str);
        Mystring temp {buff};
        delete [] buff;
        return temp;
    }

    // Display method
    void Mystring::display() const {
        std::cout << str << " : " << get_length() << std::endl;
    }

    // length getter
    int Mystring::get_length() const { return std::strlen(str); }
    
    // string getter
    const char *Mystring::get_str() const { return str; }


    Mystring.h
    ---------
    #ifndef _MYSTRING_H_
    #define _MYSTRING_H_

    class Mystring
    {
    private:
        char *str;      // pointer to a char[] that hold a C-style string
    public:
        Mystring();                                                          // No-args constructor
        Mystring(const char *s);                                      // Overloaded constructor
        Mystring(const Mystring &source);                     // Copy constructor
        Mystring( Mystring &&source);                          // Move constructiror
        ~Mystring();                                                      // Destructor
        
        Mystring &operator=(const Mystring &rhs);    // Copy assignment
        Mystring &operator=(Mystring &&rhs);          // Move assignment

        Mystring operator-() const;                             // make lowercase
        Mystring operator+(const Mystring &rhs) const;        // concatenate
        bool operator==(const Mystring &rhs) const;
        
        void display() const;

        int get_length() const;                                        // getters
        const char *get_str() const;
    };

    #endif // _MYSTRING_H_


*/


/* 7) overloading operators as global functions 

    ReturnType operatorOp(Type &obj);

    Number operator-(const Number &obj);
    Number operator++(Number &obj); // pre increment
    Number operator++(Number &obj, int); // post increment
    bool operator!(const Number &obj);   

    Number n1 {100};
    Number n2 = -n1; // operator-(n1)
    n2 = ++n1; // operator++(n1)
    n2 = n1++; // operator++(n1, int)

    operator overloading
    -----------------------
    - often declared as friend function in the class declaration
    - we can't have both the member and nonmember version of this overloaded operator at the same time

    Mystring operator-(const Mystring &obj){
        char *buff = new char[std::strlen(obj.str)+1];
        std::strcpy(buff, obj.str);
        for(size_t i=0; i<std::strlen(buff); i++)
            buff[i]=std::tolower(buff[i])
        Mystring temp{buff}; 
        delete [] buff; 
        return temp; 
    }


    Binary operators as global functions(+, -, ==, !=, <, >, etc)
    ==============================================================
        ReturnType operatorOp(const &Type lhs, const &Type rhs);
        
            Number n3 = n1 + n2; // operator+(n1, n2)
            n3 = n1 - n2; // operator-(n1, n2)
            if(n1 == n2) // operator==(n1, n2)

            bool operator==(const Mystring &lhs, const Mystring &rhs){
                if(std::strcmp(lhs.str, rhs.str) == 0){
                    return true; 
                }else{
                    return false; 
                }
            }
        - if declared as a friend of Mystring can access private str attribute
        - otherwise must use getter methods

        


*/








