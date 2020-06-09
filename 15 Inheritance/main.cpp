/* 1) overview

    - what is inheritance
        - why is it useful
    - termilogy and notation
    - inheritance vs composition
    - deriving classes from existing classes
        - types of inheritance
    - protected members and class access
    - constructors and destructors
        - passing arguments to base class contructors
        - order of constructor and destructor calls
    - redefining base class methods
    - class hierarchies
    - multiple inheritance


*/


/* 2) what is inheritance 

    - provides a method for creating new classes from existing classes
    - the new class contains the data and behaviors of the existing class
    - allow for reuse of existing classes
    - allows us to focus on the common attributes among a set of classes
    - allows new classes to modify behaviors of existing classes to make it unique
        - without actually modifying the original class


    Related classes
    ---------------
    - player, enemy, level boss, hero, super player , etc. 
    - account, savings account, checking account, trust account, etc. 
    - shape, line, oval, circle, square, etc. 
    - person, employee, student, faculty, staff, administration, etc.



*/


/* 3) terminology and notations 
    - inheritance 
        - process of creating new classes from existing classes
        - reuse mechanism
    - single inheritance
        - a new class is created from another 'single' class
    - multiple inheritance
        - a new  class is created from two or more classes


    - Base class(parent class, super class)
        - the class being extended or inherited from
    - derived class (child class, sub class)
        - the class being inherited from the base class
        - will inherit attributes and operations from base class

    - 'IS- A' relationship
        - public inheritance
        - derived classes are subtypes of their base classes
        - can use a derived class object wherever we use a base class object.
    - generalization
        - combining similar classes into a single, more general class based on common attributes. 
    
    - specilization
        - creating new classes from existing classes providing more specialized attributes or operations
    - inheritance or class hierarchies
        - organization of our inheritance relationships


                person

    employee            student

faculty     staff

    classes
    -------
    - person
    - employee is derived from person
    - student is derived from person
    - faculty is derived from employee
    - staff is derived from employee

*/


/* 4) inheritance vs composition 

    public inheritance vs composition
    
    - both allow reuse of existing classes
    - public inheritance
        - 'is-a' relationship
            - employee is a person
            - checking account is a account
            - circle is a shape
    
    - composition
        - has a relationship
            - person has a account
            - player has a special attack
            - circle has a location

    employee is a person whereas person has a account

*/


/* 5) deriving classes from existing classes 

    c++ derivation syntax

    class Base{
        // base class members . . . 

    }

    class Derived: access-specifier Base{
        // derived class members
    }

    Access specifiers can be public, private, or protected

    types of inheritance in c++
    ----------------------------
    - public
        - most common
        - establishes is-a relationship between derived and base classes
    
    - private and pretected
        - establishes "derived class has a base class" relationship
        - "is implemented in terms of " relationship
        - different from composition


*/


/* 6) protected members and class access 

    A protected member variable or function is very similar to a private member but it provided one additional benefit that they can be accessed in 
    child classes which are called derived classes.

    class Base{
        protected:
            // protected base class members


    };

    - accessible from the base class itself
    - accessible from classes derived from base
    - not accessible by objects of base or derived


    access with public inheritance
    -----------------------------

        base class                  access in derived class
        -------------------------------------------------------------
        public: a                   public:a
        protected:b                 protected:b
        private:c                   c: no access

    access with protected inheritance
    ----------------------------------

        base class                  access in derived class
        ---------------------------------------------------
        public: a                   protected: a
        protected: b                protected: b
        private: c                  c: no access

    access with private inheritance
    -------------------------------

        base class                  access in derived class
        --------------------------------------------------
        public: a                   private: a
        protected: b                private: b
        private: c                  c: no access



    

    // Section 15
    // Protected members and class access
    #include <iostream>

    using namespace std;

    class Base {
        // Note friends of Base have access to all 
    public:
        int a {0};
        void display() { std::cout << a << ", " << b << ", " << c << endl; } // member method has access to all
    protected:
        int b {0};
    private:
        int c {0};
    };

    class Derived: public Base {
        // Note friends of Derived have access to only what Derived has access to

        // a will be public
        // b will be protected
        // c will not be accessible
    public:
        void access_base_members() {
            a = 100;    // OK
            b = 200;    // OK
        //   c = 300;    // not accessible
        }
        
    };

    int main() {
        
        cout << "=== Base member access from base objects ===========" << endl;
        Base base;
        base.a = 100;   // OK
    //    base.b = 200;   // Compiler Error
    //    base.c = 300;   // Compiler Error
        
        cout << "=== Base member access from derived objects ===========" << endl;
        Derived d;
        d.a = 100;  // OK
    //    d.b = 200;  // Compiler Error
    //    d.c = 300;  // Compiler Error
        return 0;
    }

*/



/* 7) constructors and destructors 

    - constructors and class initialization
        - A derived class inherits from its base class
        - the base part of the derived class must be initialized before the derived class is initialized
        - when a derived object is created
            - base class constructor executes then
            - derived class constructor executes
            

    Destructors
    -----------
    - class destructors are invoked in the reverse order as constructors
    - The derived part of the derived class must be destroyed before the base class destructor is invoked
    - when a derived object is destroyed
        - derived class destructor executes then
        - base class destructor executes
        - each destructor should free resources allocated in it's own constructors


    constructors and class initialization
    -------------------------------------
    - a derived class does not inherit
        - base class constructors
        - base class destructors
        - base class overloaded assignment operators
        - base class friend functions
    - however, the base class constructors, destructors, and overloaded assignment operators can invoke the base class versions
    - c++11 allows explicit inheritance of base 'non special' constructors with
        - using Base::Base; anywhere in the derived class declaration
        - lots of rule involved, often better to define constructors yourself

    // Section 15
    // Constructors and Destructors
    #include <iostream>

    using namespace std;

    class Base {
    private:
        int value;
    public:
    Base() : value{0} { cout << "Base no-args constructor" << endl; }
    Base(int x) : value{x} { cout << "Base (int) overloaded constructor" << endl; }
    ~Base(){ cout << "Base destructor" << endl; }
    };

    class Derived : public Base {
        using Base::Base;
    private:
        int doubled_value;
    public:
        Derived() : doubled_value {0} { cout << "Derived no-args constructor " << endl; } 
        Derived(int x) : doubled_value {x*2}  { cout << "Derived (int) overloaded constructor" << endl; }
        ~Derived() { cout << "Derived destructor " << endl; } 
    };

    int main() {
    //   Base b;
    //    Base b{100};
    //   Derived d;
    Derived d {1000};   // base no args constructor
                        // derived int overloaded constructor
                        // derived destructor
                        // base destructor    

        
        return 0;
    }

*/


/* 8) passing arguments to base class constructor 

    - base part of a derived class must be initialized first
    - how can we control exactly which base class constructor is used during initialization?
    - we can invoke the whichever base class constructor we wish in the initialization list of the derived class


    // Section 15
    // Base class initialization
    #include <iostream>

    using namespace std;

    class Base {
    private:
        int value;
    public:
    Base() : value {0}  { 
                cout << "Base no-args constructor" << endl; 
        }
        Base(int x)  : value {x} { 
                cout << "Base (int) overloaded constructor" << endl;
        }
    ~Base() { 
        cout << "Base destructor" << endl;
        }
    };

    class Derived : public Base {
    private:
        int doubled_value;
    public:
        Derived()
            :Base {}, doubled_value {0} {
                cout << "Derived no-args constructor " << endl; 
        }
        Derived(int x) 
            :  Base{x},  doubled_value {x * 2} { 
                cout << "Derived (int) constructor" << endl; 
        }
        ~Derived() { 
            cout << "Derived destructor " << endl; 
        } 
    };

    int main() {
    //  Derived d;
    Derived d {1000};
        return 0;
    }

*/



/* 9) copy move constructors and operators 

    copy move constructors and overloaded operator=

    - not inherited from the base class
    - you may not need to provide your own
        - compiler provided versions may be just fine
    - we can explicitly invoke the base class versions from the derived class

    copy constructor
    ----------------
    - can invoke base copy constructor explicitly
        - derived object 'other' will be sliced
    
    class Base{
        int value; 

        public:
            // same constructors as previous example

            Base(const Base &other) :value{other.value} {
                cout << "base copy constructor" << endl; 
            }

    };

    class Derived : public Base {
        int doubled_value; 

        public:
            // same constructors as previous example

            Derived(const Derived &other)
                :Base(other), doubled_value {other.doubled_value}
            {
                cout << "derived copy constructor";   
            }

    }


    // Derived::Derived(const Derived &other)
    //     : Base(other), {Derived initialization list}
    // {
    //     // code
    // }



    copy / move constructors and overloaded operator=
    - often you do not need to provide your own
    - if you donot define them in derived
        - then the compiler will create them and automatically and call the base class's version
    - if you do provide derived versions
        - then you must invoke the base versions explicitly yourself
    - be careful with raw pointers
        - especially if base and derived each have raw pointers
        - provide them with deep copy semantics


    // Section 15
    // Copy constructor and operator=
    #include <iostream>

    using namespace std;

    class Base {
    private:
        int value;
    public:
    Base()
            : value {0}  { 
                cout << "Base no-args constructor" << endl; 
        }
        Base(int x) 
            : value {x} { 
                cout << "int Base constructor" << endl;
        }
        Base(const Base &other) 
            : value {other.value} {
            cout << "Base copy constructor" << endl;     
        }
            
        Base &operator=(const Base &rhs)  {
        cout << "Base operator=" << endl;
            if (this == &rhs)
                return *this;
            value = rhs.value;
            return *this;
        }
                
    ~Base(){ cout << "Base destructor" << endl; }
    };

    class Derived : public Base {
    private:
        int doubled_value;
    public:
        Derived() : 
            Base {}  {
                cout << "Derived no-args constructor " << endl; 
        }
        Derived(int x) 
            : Base{x} , doubled_value {x * 2} { 
                cout << "int Derived constructor" << endl; 
        }
        Derived(const Derived &other)
            : Base(other), doubled_value {other.doubled_value} {
            cout << "Derived copy constructor" << endl;     
        }
        
        Derived &operator=(const Derived &rhs) {
                cout << "Derived operator=" << endl;
            if (this == &rhs)
                return *this;
            Base::operator=(rhs);
            doubled_value = rhs.doubled_value;
            return *this;
        }
    ~Derived(){ cout << "Derived destructor " << endl; } 
    };


    int main() {
    //    Base b {100};   // Overloaded constructor
    //    Base b1 {b};    // Copy constructor
    //    b = b1;          //   Copy assignment

        Derived d {100};    // Overloaded constructor
        Derived d1 {d};     // Copy constructor
        d = d1;                // Copy assignment
        
        return 0;
    }
*/


/* 10) redefining base class methiods

    - derived class can directly invoke base class methods
    - derived class can override or redefine base class methods
    - very powerful in the context of polymorphism


    static binding of methods calls
    - binding of which method to use is done at compile time
        - default binding for c++ is static
        - derived class objects will use Derived::deposit
        - but, we can explicitly invoke Base::deposit from Derived::deposit
        - ok, but limited - much more powerful approach is dynamic binding 

    Base b; 
    b.deposit(1000);     // Base::deposit

    Derived d; 
    d.deposit(1000);     // Derived::deposit

    Base *ptr = new Derived(); 
    ptr->deposit(1000);   // Base::deposit  ????




    Account.h
    -----------
    #ifndef _ACCOUNT_H_
    #define _ACCOUNT_H_
    #include <iostream>

    // Simple Account class
    class Account {
        friend std::ostream &operator<<(std::ostream &os, const Account &account);
    protected:
        double balance;
    public:
        Account();
        Account(double balance);            
        void deposit(double amount); 
        void withdraw(double amount);
    };

    #endif // _ACCOUNT_H_


    Account.cpp
    -------------
    #include "Account.h"
    // Simple Account class

    Account::Account() 
        : Account(0.0) {    // delegating constructor
    }
            
    Account::Account(double balance)
        : balance(balance) { 
    }
                
    void Account::deposit(double amount) {   
        balance += amount;
    }
        
    void Account::withdraw(double amount) {
        if (balance-amount >= 0)
            balance-=amount;
        else    
            std::cout << "Insufficient funds" << std::endl;
    }

    std::ostream &operator<<(std::ostream &os, const Account &account) {
        os <<  "Account balance: " << account.balance;
        return os;
    }



    Savings.h
    ---------
    #ifndef _SAVINGS_ACCOUNT_H_
    #define _SAVINGS_ACCOUNT_H_
    #include "Account.h"

    // Savings Account class 
    // Deposit method increments amount to be deposited by amount * int_rate percentage!!
    // So a 1000 deposit at 5% interest rate will deposit 1000 + 50 = 1050

    // Withdraw method does not specialize

    class Savings_Account: public Account {
        friend std::ostream &operator<<(std::ostream &os, const Savings_Account &account);
    protected:
        double int_rate;
    public:
        Savings_Account();
        Savings_Account(double balance, double int_rate);
        void deposit(double amount);
        // Withdraw is inherited
    };

    #endif // _SAVINGS_ACCOUNT_H_


    Savings_Account.cpp
    -------------------
    #include "Savings_Account.h"

    Savings_Account::Savings_Account(double balance, double int_rate)
        : Account(balance), int_rate{int_rate} {
            
        }

    Savings_Account::Savings_Account() 
        : Savings_Account{0.0, 0.0} {
            
        }
        
    void Savings_Account::deposit(double amount) {
        amount = amount + (amount * int_rate/100);
        Account::deposit(amount);
    }

    std::ostream &operator<<(std::ostream &os, const Savings_Account &account) {
        os << "Savings account balance: " << account.balance << " Interest rate: " << account.int_rate;
        return os;
    }

    main.cpp
    ---------
    // Section 15
    // Redefining and Using Base Class Methods
    #include <iostream>
    #include "Savings_Account.h"

    using namespace std;


    int main() {
        cout << "\n===== Account class ===================" << endl;
        Account a1 {1000.0};
        cout << a1 << endl;         // Account balance: 1000
        
        a1.deposit(500.0);
        cout << a1 << endl;         // Account balance: 1500
        
        a1.withdraw(1000);            // Account balance: 500
        cout << a1 << endl;
        
        a1.withdraw(5000.0);         // Insufficient funds
        cout << a1 << endl;         // Account balance: 500

    cout << "\n===== Savings Account class ===========" << endl;
        Savings_Account s1 {1000, 5.0}; 
        cout << s1 << endl;         // Savings Account balance: 1000, Interest rate: 5
        
        s1.deposit(1000);
        cout << s1 << endl;          // Savings Account balance: 2050, Interest rate: 5
        
        s1.withdraw(2000);
        cout << s1 << endl;          // Savings Account balance: 50, Interest rate: 5
        
        s1.withdraw(1000);            // Insufficient funds
        cout << s1 << endl;         // Savings Account balance: 50, Interest rate: 5
        
        
        return 0;
    }


*/




/* 11) multiple inheritance in cpp

    - A derived class inherits from two or more base classes at the same time
    - the base classes may belong to unrelated class hierarchies
    - A department chair
        - is a faculty and
        - is a administrator


    class Department_chair:
        public Faculty, public Administrator{
            ...

        }

*/




