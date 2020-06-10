/* 1) polymorphism 

    - what is polymorphism
    - using base class pointers
    - static vs dynamic binding
    - virtual functions
    - virtual destructors
    - the override and final specifiers
    - using base class references
    - pure virtual functions and abstract classes
    - abstract classes as interfaces

*/


/* 2) what is polymorphism 

    Fundamental to object oriented programming

    Polymorphism 
        - compile-time/ early binding/ static binding
        - run time/ late binding/ dynamic binding
    
    runtime polymorphism
        - being able to assign different meanings to the same function at run time
    
    allows us to program more abstractly
        - think general vs specific
        - let c++ figure out which function to call at runtime
    
    not the default in c++, run time polymorphism is achieved via
        - inheritance
        - base class pointers or references
        - virtual functions

    
    polymorphism 
    1) compile time -> function overloading, operator overloading
    2) run time -> function overriding


    An non polymorphic example - static binding

    Account a; 
    a.withdraw(1000);  // Account::withdraw(); 

    Savings b; 
    b.withdraw(1000); // Savings::withdraw()

    Checking c; 
    c.withdraw(1000); // Checking::withdraw()

    Trust d; 
    d.withdraw(1000); // Trust::withdraw()

    Account *p = new Trust(); 
    p->withdraw(1000); // Account::withdraw()
                        // should be
                        // Trust::withdraw()


    - withdraw method is virtual in Account. The idea of virtual function tells the compiler not to bind the call compile time but instead
    defer the binding to runtine and at runtime a check will occur to see exactly what P is pointing to and then that object's method will 
    be called. 

    Then in that case - dynamic binding

    Account *p = new Trust(); 
    p->withdraw(1000); // Trust::withdraw() 





    // Section 16
    // The problem
    #include <iostream>
    #include <memory>

    class Base {
    public:
        void say_hello() const {
            std::cout << "Hello - I'm a Base class object" << std::endl;
        }
    };

    class Derived: public Base {
    public:
        void say_hello()  const {   
            std::cout << "Hello - I'm a Derived class object" << std::endl;
        }
    };

    void greetings(const Base &obj) {
        std::cout << "Greetings: " ;
        obj.say_hello();
    }

    int main() {
        Base b;
        b.say_hello(); // Im a base class object
        
        Derived d;
        d.say_hello(); // Im a derived class object
        
        greetings(b); // im a base class object
        greetings(d); // im a base class object
        
        Base *ptr = new Derived();
        ptr->say_hello(); // im a base class object
        
        std::unique_ptr<Base> ptr1 = std::make_unique<Derived>();
        ptr1->say_hello(); // im a base class object
        
        delete ptr;
        
        return 0;
    }

*/



/* 3) using base class pointer 

    - for dynamic polymorphism we must have
        - inheritance
        - base class pointer or base class reference
        - virtual functions

*/


/* 4) virtual functions 

    - redefined functions are bound statically
    - overridden functions are bound dynamically
    - virtual functions are overridden
    - allow us to treat all objects generarally as objects of the base class


    Declaring virtual functions
    - declare the function you want to override as virtual in the base class
    - virtual functions are virtual all the way down the hierarchy from this point
    - dynamic polymorphism only via account class pointer or reference

    class Account{

        public:
            virtual void withdraw(double amount);   
            ...
    }


    declaring virtual functions
    - override the function in the derived class
    - function signature and return type must match exactly
    - virtual keyword not required but is best practice
    - if you don't provide an overridden version it is inherited from it's base class

    class Checking : public Account{

        public:
            virtual void withdraw(double amount);    
    }


    // Section 16
    // Virtual functions

    #include <iostream>

    // This class uses dynamic polymorphism for the withdraw method
    class Account {
    public:
        virtual void withdraw(double amount) {
            std::cout << "In Account::withdraw" << std::endl;
        }
    };

    class Checking: public Account  {
    public:
        virtual void withdraw(double amount) {
            std::cout << "In Checking::withdraw" << std::endl;
        }
    };

    class Savings: public Account  {
    public:
        virtual void withdraw(double amount) {
            std::cout << "In Savings::withdraw" << std::endl;
        }
    };

    class Trust: public Account  {
    public:
        virtual void withdraw(double amount) {
            std::cout << "In Trust::withdraw" << std::endl;
        }
    };

    int main() {
        std::cout << "\n === Pointers ==== " << std::endl;
        Account *p1 = new Account();
        Account *p2 = new Savings();
        Account *p3 = new Checking();
        Account *p4 = new Trust();
        
        p1->withdraw(1000);
        p2->withdraw(1000);
        p3->withdraw(1000);
        p4->withdraw(1000);
        

        std::cout << "\n === Clean up ==== " << std::endl;
        delete p1;
        delete p2;
        delete p3;
        delete p4;
            
        return 0;
    }

*/



/* 5) virtual destructors 
    - warning: deleting object of polymorphic class type Account which has non virtual destructor might cause undefined behaviour


    - problems can happen when we destroy polymorphic objects
    - if a derived class is destroyed by deleting its storage via the base class pointer and the class a non virtual destructor. 
    Then the behaviour is undefined in c++ standard
    - derived objects must be destroyed in the correct order starting at the correct destructor

    solution / rule
    -----------------
    - if a class has virtual functions
    - always provide a public virtual destructors
    - if a base class destructor is virtual then all derived class destructors are also virtual

    class Account{
        public:
            virtual void withdraw(double amount);
            virtual ~Account();     

    }



    // Section 16
    // Virtual destructors

    #include <iostream>

    // This class uses dynamic polymorphism for the withdraw method
    class Account {
    public:
        virtual void withdraw(double amount) {
            std::cout << "In Account::withdraw" << std::endl;
        }
        virtual ~Account() { std::cout << "Account:: destructor" << std::endl; }
    };

    class Checking: public Account  {
    public:
        virtual void withdraw(double amount) {
            std::cout << "In Checking::withdraw" << std::endl;
        }
        virtual ~Checking() { std::cout << "Checking:: destructor" << std::endl; }

    };

    class Savings: public Account  {
    public:
        virtual void withdraw(double amount) {
            std::cout << "In Savings::withdraw" << std::endl;
        }
        virtual ~Savings() { std::cout << "Savings:: destructor" << std::endl; }

    };

    class Trust: public Account  {
    public:
        virtual void withdraw(double amount) {
            std::cout << "In Trust::withdraw" << std::endl;
        }
        virtual ~Trust() { std::cout << "Trust:: destructor" << std::endl; }

    };

    int main() {

        std::cout << "\n === Pointers ==== " << std::endl;
        Account *p1 = new Account();
        Account *p2 = new Savings();
        Account *p3 = new Checking();
        Account *p4 = new Trust();
        
        p1->withdraw(1000);
        p2->withdraw(1000);
        p3->withdraw(1000);
        p4->withdraw(1000);
        

        std::cout << "\n === Clean up ==== " << std::endl;
        delete p1; // account destructor
        delete p2; // savings destructor
        delete p3; // checking destructor
        delete p4; // trust destructor
            
        return 0;
    }

*/


/* 6) using the override specifier 

    - we can override base class virtual functions
    - the function signature and return must be exactly the same
    - if they are different then we have redefinition not overriding
    - redefinition is statically bound  
    - overriding is dynamically bound
    - c++11 provides an override specifier to have the compiler ensure overriding


    // Section 16
    // Using override
    #include <iostream>

    class Base {
    public:
        virtual void say_hello() const {
            std::cout << "Hello - I'm a Base class object" << std::endl;
        }
        virtual ~Base() {}
    };

    class Derived: public Base {
    public:
        virtual void say_hello()  const override {             // Notice I forgot the const 
            std::cout << "Hello - I'm a Derived class object" << std::endl;
        }
        virtual ~Derived() {}
    };


    int main() {
        
        Base *p1 = new Base();      // Base::say_hello()
        p1->say_hello();
        
        Derived *p2 = new Derived();    // Derived::say_hello()
        p2->say_hello();
        
        Base *p3 = new Derived();   //  Base::say_hello()   ?????   I wanted Derived::say_hello()
        p3->say_hello();
        
    
        return 0;
    }

*/



/* 7) using the final specifier 

    - c++11 provides the final specifier
        - when used at the class level
        - prevents the class from being derived from
    
        - when used at the method level
        - prevents virtual methods from being overridden in derived class

    final class
    ----------

    class Myclass final{

    }
    class Derived final: public Base{
        ...
    };

    final method
    ------------
    class A{
        public:
            virtual void dosomething(); 
    }

    class B: public A{
        virtual void dosomething() final; // prevent further overriding

    }

    class C : public B{
        virtual void dosomething(); // compiler error can't override
    }

*/



/* 8) using base class reference 

    - we can also use base class references with dynamic polymorphism
    - useful when we pass objects to functions that expect a base class reference

    // Section 16
    // Using Base class references

    #include <iostream>

    // This class uses dynamic polymorphism for the withdraw method
    // We'll learn about virtual functions in the next video
    class Account {
    public:
        virtual void withdraw(double amount) {
            std::cout << "In Account::withdraw" << std::endl;
        }
        virtual ~Account() {  }
    };

    class Checking: public Account  {
    public:
        virtual void withdraw(double amount) {
            std::cout << "In Checking::withdraw" << std::endl;
        }
        virtual ~Checking() {  }
    };

    class Savings: public Account  {
    public:
        virtual void withdraw(double amount) {
            std::cout << "In Savings::withdraw" << std::endl;
        }
        virtual ~Savings() {  }
    };

    class Trust: public Account  {
    public:
        virtual void withdraw(double amount) {
            std::cout << "In Trust::withdraw" << std::endl;
        }
        virtual ~Trust() {  }
    };

    void do_withdraw(Account &account, double amount) {
        account.withdraw(amount);
    }

    int main() {

        Account a;
        Account &ref = a;
        ref.withdraw(1000);		    // In Account::withdraw

        Trust t;
        Account &ref1 = t;
        ref1.withdraw(1000);        // In Trust::withdraw

    Account a1;
    Savings a2;
    Checking a3;
    Trust a4;
    
    do_withdraw(a1, 1000);       // In Account::withdraw
    do_withdraw(a2, 2000);       // In Savings::withdraw
    do_withdraw(a3, 3000);       // In Checking::withdraw
    do_withdraw(a4,  4000);      // In Trust::withdraw


        return 0;
    }


*/



/* 9) pure virtual functions and abstract classes 

    abstract class
        - cannot instantiate objects
        - these classes are used as base classes in inheritance hierarchies
        - often referred to as abstract base classes

    concrete class
        - used to instantiate objects from
        - all their member functions are defined
            - checking account, savings account
            - faculty, staff
            - enemy, level boss

    - abstract base class
        - too generic to create objects from
            - shape, employee, account, player
        - serves as parent to derived classes that may have objects
        - contains atleast one pure virtual function

    - pure virtual function
        - used to make a class abstract
        - specified with "=0" in its declaration
            virtual void function () = 0; // pure virtual function
        - typically donot provide implementations

        - derived class must override the base class
        - if the derived class does not override then the derived class is also abstract
        - used when it doesn't make sense for a base class to have an implementation
            - but concrete classes must implement it

            virtual void draw() = 0; // shape
            virtual void defend() = 0; // player


    pure virtual functions and abstract classes

    class Shape {           // abstract

        private:
            // attributes common to all shapes

        public:
            virtual void draw() = 0; // pure virtual functions
            virtual void rotate() = 0; // pure virtual functions
            virtual ~Shape(); 
            ...
    }

    class Circle : public Shape{ // concrete
        private:
            // attributes for a circle
        
        public:
            virtual void draw() override{
                // code to draw a circle

            }

            virtual void rotate() override {
                // code to rotate a circle

            }

            virtual ~Circle(); 

            ...
    }



    Abstract base class
    - cannot be instantiated
        Shape shape; // error
        Shape *ptr = new Shape(); // error

    - we can use pointers and references to dynamicaaly refer to concrete classes derived from them 
        Shape *ptr = new Circle(); 
        ptr->draw(); 
        ptr->rotate();     // it has to work, because all concrete classes derive from shape must have overridden the draw and rotate    



    // Section 16
    // Pure virtual functions and abstract base classes
    #include <iostream>
    #include <vector>

    class Shape {			// Abstract Base class
    private:
        // attributes common to all shapes
    public:
        virtual void draw() = 0;	 // pure virtual function
        virtual void rotate() = 0;   // pure virtual function
        virtual ~Shape() { }
    };

    class Open_Shape: public Shape {    // Abstract class
    public:
        virtual ~Open_Shape() { }
    };

    class Closed_Shape : public Shape {  // Abstract class
    public:
        virtual ~Closed_Shape() { };
    };

    class Line: public Open_Shape {     // Concrete class
    public:
        virtual void draw() override {
            std::cout << "Drawing a line" << std::endl;
        }
        virtual void rotate() override {
            std::cout << "Rotating a line" << std::endl;
        }
        virtual ~Line() {}
    };

    class Circle: public Closed_Shape {     // Concrete class
    public:
        virtual void draw() override {
            std::cout << "Drawing a circle" << std::endl;
        }
        virtual void rotate() override {
            std::cout << "Rotating a circle" << std::endl;
        }
        virtual ~Circle() {}
    };

    class Square: public Closed_Shape {     // Concrete class
    public:
        virtual void draw() override {
            std::cout << "Drawing a square" << std::endl;
        }
        virtual void rotate() override {
            std::cout << "Rotating a square" << std::endl;
        }
        virtual ~Square() {}
    };


    void screen_refresh(const std::vector<Shape *> &shapes) {
        std::cout << "Refreshing" << std::endl;
        for (const auto p: shapes) 
            p->draw();
    }

    int main() {
    //    Shape s;
    //    Shape *p = new Shape();

    //        Circle c;
    //        c.draw();

    //    Shape *ptr = new Circle();
    //    ptr->draw();
    //    ptr->rotate();

        Shape *s1 = new Circle();
        Shape *s2 = new Line();
        Shape *s3 = new Square();
        
        std::vector<Shape *> shapes {s1,s2,s3};
        
    //    for (const auto p: shapes) 
    //        p->draw();
            
        screen_refresh(shapes);
        
        delete s1;
        delete s2;
        delete s3;
        
        return 0;
    }

*/


/* 10) abstract classes as interfaces 

    - an abstract class that has only pure virtual functions
    - these functions provide a general set of services to the user of the class
    - provided as public
    - each subclass is free to implement these service as needed
    - every service (method ) must be implemented
    - the service type information is strictly enforced

    A printable example
    -------------------
    - c++ does not provide true interfaces
    - we use abstract classes and pure virtual functions to achieve it
    - suppose we want to be able to provice printable support for any object we wish without knowing it's implementations at compile time
        std::cout << any_object << std::endl;
        - any object must conform to the printable interface


    // Section 16
    // Interfaces - start

    #include <iostream>

    class Account  {
        friend std::ostream &operator<<(std::ostream &os, const Account &acc);
    public:
        virtual void withdraw(double amount) {
            std::cout << "In Account::withdraw" << std::endl;
        }
        virtual ~Account() {  }
    };

    std::ostream &operator<<(std::ostream &os, const Account &acc) {
        os << "Account display";
        return os;
    }

    class Checking: public Account  {
        friend std::ostream &operator<<(std::ostream &os, const Checking &acc);
    public:
        virtual void withdraw(double amount) {
            std::cout << "In Checking::withdraw" << std::endl;
        }
        virtual ~Checking() {  }
    };

    std::ostream &operator<<(std::ostream &os, const Checking &acc) {
        os << "Checking display";
        return os;
    }

    class Savings: public Account {
        friend std::ostream &operator<<(std::ostream &os, const Savings &acc);
    public:
        virtual void withdraw(double amount) {
            std::cout << "In Savings::withdraw" << std::endl;
        }
        virtual ~Savings() {  }
    };

    std::ostream &operator<<(std::ostream &os, const Savings &acc) {
        os << "Savings display";
        return os;
    }
    class Trust: public Account  {
        friend std::ostream &operator<<(std::ostream &os, const Trust &acc);
    public:
        virtual void withdraw(double amount) {
            std::cout << "In Trust::withdraw" << std::endl;
        }
        virtual ~Trust() {  }
    };

    std::ostream &operator<<(std::ostream &os, const Trust &acc) {
        os << "Trust display";
        return os;
    }

    int main() {
        Account *p1 = new Account();
        std::cout << *p1<< std::endl;

        Account *p2 = new Checking();
        std::cout << *p2<< std::endl;
    
    //    Account a;
    //    std::cout << a<< std::endl;
    //    
    //    Checking c;
    //    std::cout << c << std::endl;
    //
    //    Savings s;
    //    std::cout << s << std::endl;
    //    
    //    Trust t;
    //    std::cout << t << std::endl;

        delete p1;  
        delete p2;
        return 0;
    }




    // Section 16
    // Interfaces - complete

    #include <iostream>

    class I_Printable {
        friend std::ostream &operator<<(std::ostream &os, const I_Printable &obj);
    public:
        virtual void print(std::ostream &os) const = 0;
        virtual ~I_Printable {};
    };

    std::ostream &operator<<(std::ostream &os, const I_Printable &obj) {
        obj.print(os);
        return os;
    }


    class Account : public I_Printable {
    public:
        virtual void withdraw(double amount) {
            std::cout << "In Account::withdraw" << std::endl;
        }
        virtual void print(std::ostream &os) const override {
            os << "Account display";
        }
        virtual ~Account() {  }
    };

    class Checking: public Account  {
    public:
        virtual void withdraw(double amount) {
            std::cout << "In Checking::withdraw" << std::endl;
        }
        virtual void print(std::ostream &os) const override {
            os << "Checking display";
        }
        virtual ~Checking() {  }
    };


    class Savings: public Account {
    public:
        virtual void withdraw(double amount) {
            std::cout << "In Savings::withdraw" << std::endl;
        }
        virtual void print(std::ostream &os) const override {
            os << "Savings display";
        }
        virtual ~Savings() {  }
    };

    class Trust: public Account  {
    public:
        virtual void withdraw(double amount) {
            std::cout << "In Trust::withdraw" << std::endl;
        }
        virtual void print(std::ostream &os) const override {
            os << "Trust display";
        }
        virtual ~Trust() {  }
    };

    class Dog : public I_Printable {
    public:
    virtual void print(std::ostream &os) const override {
            os << "Woof woof";
        } 
    };

    void print(const I_Printable &obj) {
        std::cout << obj << std::endl;
    }


    int main() {
        
        Dog *dog = new Dog();
        std::cout << *dog<< std::endl;  
        
        print(*dog);
        
        Account *p1 = new Account();
        std::cout << *p1<< std::endl;
            
        Account *p2 = new Checking();
        std::cout << *p2<< std::endl;  

    //    Account a;
    //    std::cout << a<< std::endl;
    //    
    //    Checking c;
    //    std::cout << c << std::endl;
    //
    //    Savings s;
    //    std::cout << s << std::endl;
    //    
    //    Trust t;
    //    std::cout << t << std::endl;
            
        delete p1;
        delete p2;
        delete dog;
        return 0;
    }




*/





// Section 16
// Using Base class references

    #include <iostream>

    // This class uses dynamic polymorphism for the withdraw method
    // We'll learn about virtual functions in the next video
    class Account {
    public:
        virtual void withdraw(double amount) {
            std::cout << "In Account::withdraw" << std::endl;
        }
        virtual ~Account() {  }
    };

    class Checking: public Account  {
    public:
        virtual void withdraw(double amount) {
            std::cout << "In Checking::withdraw" << std::endl;
        }
        virtual ~Checking() {  }
    };

    class Savings: public Account  {
    public:
        virtual void withdraw(double amount) {
            std::cout << "In Savings::withdraw" << std::endl;
        }
        virtual ~Savings() {  }
    };

    class Trust: public Account  {
    public:
        virtual void withdraw(double amount) {
            std::cout << "In Trust::withdraw" << std::endl;
        }
        virtual ~Trust() {  }
    };

    void do_withdraw(Account &account, double amount) {
        account.withdraw(amount);
    }

    int main() {

        Account a;
        Account &ref = a;
        ref.withdraw(1000);		    // In Account::withdraw

        Trust t;
        Account &ref1 = t;
        ref1.withdraw(1000);        // In Trust::withdraw


        Trust t1;
        Account at1 = t1;   
        at1.withdraw(1000);        // In Account::withdraw   

        Account a1;    
        Savings a2;
        Checking a3;
        Trust a4;
        
        do_withdraw(a1, 1000);       // In Account::withdraw
        do_withdraw(a2, 2000);       // In Savings::withdraw
        do_withdraw(a3, 3000);       // In Checking::withdraw
        do_withdraw(a4,  4000);      // In Trust::withdraw


        return 0;
    }
