/* 1) overview 

    smart pointers
    --------------
    - issues with raw pointers
    - what are smart pointers
    - concept of ownership and RAII
    - C++ smart pointers
        - unique_ptr
        - shared_ptr
        - weak_ptr
    - custom deleters


*/


/* 2) issues with raw pointers 

    - c++ provides absolute flexibility with memory management
        - allocation 
        - deallocation
        - lifetime management
    
    - some potential serious problems
        - uninitialized (wild) pointers
        - memory leaks
        - dangling pointers
        - not exception safe

    - ownership?
        - who owns the pointer?
        - when should a pointer be deleted?



*/


/* 3) what is smart pointer ownership and RAII 

    what are they?
        - objects
        - can only point to heap allcated memory
        - automatically call delete when no longer needed
        - adhere to RAII principles
        - c++ smart pointers
            - unique_ptr
            - shared_ptr
            - weak_ptr
            - auto_ptr - deprecated


    #include <memory>

    - defined by class templates
        - wrapped around a raw pointer
        - overloaded operators
            - dereference (*)
            - member selection(->)
            - pointer arithmetic not supported (++, -- etc)

        - can have custom deleters


    {
        std::smart_pointer<someclass> ptr = ...
        ptr->method(); 
        cout<< (*ptr) << endl; 
    }
    // ptr will be destroyed automatically when
    // no longer needed


    RAII - resource acquisition is initialization
    ----------------------------------------------
    - common idiom or pattern used in software design based on container object lifetime
    - RAII objects are allocated on the stack
    - resource acquisition
        - open a file
        - allocate memory
        - acquire a lock
    - is initializtion
        - the resource is acquired in a constructor
    - resource relinquishing
        - happens in the destructor
            - close the file
            - deallocate the memory
            - release the lock

*/


/* 4) unique pointers 
    - simple smart pointer - very efficient

    - unique_ptr<T>
        - points to an object of type T on the heap
        - it is unique - there can only be one unique_ptr<T> pointing to the object on the heap
        - owns what it points to 
        - cannot be assigned or copied
        - can be moved
        - when the pointer is destroyed, what it points to is automatically destroyed


    unique_ptr - creating, initializing and using
    
    {
        std::unique_ptr<int> p1 {new int {100}}; 
        std::cout << *p1 << std::endl; // 100

        *p1 = 200; 
        std::cout << *p1; // 200
    } // automatically deleted


    unique_ptr - some other useful methods

    {
        std::unique_ptr<int> p1 {new int {100}};
        std::cout << p1.get(); // 0x564388
        p1.reset(); // p1 is now nullptr
        if(p1)  
            std::cout << *p1; // won't execute

    } // automatically deleted


    unique_ptr - user defined classes

    {
        std::unique_ptr<Accout> p1 {new Account{"Larry"}};
        std::cout << *p1; // display account

        p1->deposit(1000);
        p1->withdraw(500);    
    }


    unique_ptr - vectors and move

    {
        std::vector<std::unique_ptr<int>> vec; 
        std::unique_ptr<int> ptr {new int {100}}; 
        vec.push_back(ptr); // error - copy not allowed
        vec.push_back(std::move(ptr)); 
        
    } // automatically deleted



    // Section 17
    // Unique Pointers 
    #include <iostream>
    #include <memory>
    #include <vector>

    #include "Account.h"
    #include "Checking_Account.h"
    #include "Trust_Account.h"
    #include "Savings_Account.h"

    class Test {
    private:
        int data;
    public:
        Test() : data{0} { std::cout << "Test constructor (" << data << ")" << std::endl; }
        Test(int data) : data {data} { std::cout << "Test constructor (" << data << ")" << std::endl; }
        int get_data() const {return data; }
        ~Test() {std::cout << "Test destructor (" << data << ")" << std::endl; }
    };

    using namespace std;

    int main() {
    // Test *t1 = new Test {1000};
    //  delete t1;
    //   std::unique_ptr<Test> t1 {new Test{100}};
    //   std::unique_ptr<Test> t2 = std::make_unique<Test>(1000);
    //   
    //   std::unique_ptr<Test> t3;
    //   // t3 = t1; // compiler error can't copy
    //   t3 = std::move(t1);
    //   if (!t1)      
    //       std::cout << "t1 is nullptr" << std::endl;
        
        std::unique_ptr<Account> a1 = std::make_unique<Checking_Account>("Moe", 5000);
        std::cout << *a1 << std::endl;
        a1->deposit(5000);
        std::cout << *a1 << std::endl;

        std::vector<std::unique_ptr<Account>> accounts;

        accounts.push_back( make_unique<Checking_Account>("James", 1000));
        accounts.push_back( make_unique<Savings_Account>("Billy", 4000, 5.2));
        accounts.push_back( make_unique<Trust_Account>("Bobby", 5000, 4.5));

            for (const auto &acc: accounts)
                std::cout << *acc << std::endl;
        return 0;
    }


*/


/* 5) shared pointers 

    - provides shared ownership of heap objects

    - shared_ptr<T>
        - points to an object of type T on the heap
        - it is not unique - there can many shared_ptrs pointing to the same object on the heap
        - establishes shared ownership relationship
        - can be assigned and copied
        - can be moved
        - doesn't support managing arrays by default
        - when the use count is zero, the managed object on the heap is destroyed

    // Section 17
    // Shared Pointers
    #include <iostream>
    #include <memory>
    #include <vector>
    #include "Checking_Account.h"
    #include "Savings_Account.h"
    #include "Trust_Account.h"


    class Test {
    private:
        int data;
    public:
        Test() : data{0} { std::cout << "Test constructor (" << data << ")" << std::endl; }
        Test(int data) : data {data} { std::cout << "Test constructor (" << data << ")" << std::endl; }
        int get_data() const {return data; }
        ~Test() {std::cout << "Test destructor (" << data << ")" << std::endl; }
    };


    void func(std::shared_ptr<Test> p) {
        std::cout << "Use count: " << p.use_count() << std::endl;
    }

    int main() {
    
        // use_count – the number of shared_ptr objects
        // managing the heap object
    
    //    std::shared_ptr<int> p1 {new int {100} };
    //    std::cout << "Use count: "<< p1.use_count () << std::endl; 		// 1
    //   
    //    std::shared_ptr<int> p2 { p1 };			// shared ownwership
    //    std::cout << "Use count: "<< p1.use_count () << std::endl; 		// 2
    //
    //    p1.reset();	// decrement the use_count; p1 is nulled out
    //    std::cout << "Use count: "<< p1.use_count() << std::endl; 		// 0 
    //    std::cout << "Use count: "<< p2.use_count() << std::endl; 		// 1
        
    //    std::cout << "\n==========================================" << std::endl;
    //    std::shared_ptr<Test> ptr = std::make_shared<Test>(100);
    //    func(ptr);
    //    std::cout << "Use count: " << ptr.use_count() << std::endl;
    //    {
    //        std::shared_ptr<Test> ptr1 = ptr;
    //        std::cout << "Use count: " << ptr.use_count() << std::endl;
    //        {
    //            std::shared_ptr<Test> ptr2 = ptr;
    //            std::cout << "Use count: " << ptr.use_count() << std::endl;      
    //            ptr.reset();
    //        }
    //        std::cout << "Use count: " << ptr.use_count() << std::endl;      
    //
    //    }
    //    std::cout << "Use count: " << ptr.use_count() <<std:: endl;

        std::cout << "\n==========================================" << std::endl;
        std::shared_ptr<Account> acc1 = std::make_shared<Trust_Account>("Larry", 10000, 3.1);
        std::shared_ptr<Account> acc2 = std::make_shared<Checking_Account>("Moe", 5000);
        std::shared_ptr<Account> acc3 = std::make_shared<Savings_Account>("Curly", 6000);
        
        std::vector<std::shared_ptr<Account>> accounts;
        accounts.push_back(acc1);
        accounts.push_back(acc2);
        accounts.push_back(acc3);
        
        for (const auto &acc: accounts) {
            std::cout << *acc << std::endl;
            std::cout << "Use count: " << acc.use_count() << std::endl;
        }
        
        std::cout << "==========================================" << std::endl;
        return 0;
    }


*/


/* 6) weak pointers 

    - provides a non owning weak reference

    - weak_ptr<T>
        - points to an object of type T on the heap
        - does not participate in owning relationship
        - always created from shared_ptr
        - does not increment or decrement reference use count
        - used to prevent strong reference cycles which could prevent objects from being deleted


    weak_ptr - circular or cyclic reference
    - A refers to B
    - B refers to A
    - shared strong ownershiop prevents heap deallocation


    // Section 17
    // Weak Pointers
    #include <iostream>
    #include <memory>

    using namespace std;

    class B;    // forward declaration

    class A {
        std::shared_ptr<B> b_ptr;
    public:
        void set_B(std::shared_ptr<B> &b) {
            b_ptr = b;
        }
        A() { cout << "A Constructor" << endl; }
        ~A() { cout << "A Destructor" << endl; }
    };

    class B {
        std::weak_ptr<A> a_ptr;     // make weak to break the strong circular reference
    public:
        void set_A(std::shared_ptr<A> &a) {
            a_ptr = a;
        }
        B() { cout << "B Constructor" << endl; }
        ~B() { cout << "B Destructor" << endl; }
    };

    int main() {
        shared_ptr<A> a  = make_shared<A>();
        shared_ptr<B> b = make_shared<B>();
        a->set_B(b);
        b->set_A(a);
        
        return 0;
    }


*/



/* 7) custom deleters 

    - sometimes when we destroy a smart pointer we need more than to just destroy the object on the heap
    - these are special use cases
    - c++ smart pointers allow you to provide custom deleters
    - lots of way to achieve this
        - functions
        - lambdas
        - others...


    // Section 17
    // Custom deleters
    #include <iostream>
    #include <memory>

    class Test {
    private:
        int data;
    public:
        Test() : data{0} { std::cout << "\tTest constructor (" << data << ")" << std::endl; }
        Test(int data) : data {data} { std::cout << "\tTest constructor (" << data << ")" << std::endl; }
        int get_data() const {return data; }
        ~Test() {std::cout << "\tTest destructor (" << data << ")" << std::endl; }
    };

    void my_deleter(Test *ptr) {
        std::cout << "\tUsing my custom function deleter" << std::endl;
        delete ptr;
    }

    int main() {

        {
            // Using a function 
            std::shared_ptr<Test> ptr1 {new Test{100}, my_deleter };
        }

        std::cout << "====================" << std::endl;
        {
            // Using a Lambda expression
            std::shared_ptr<Test> ptr2 (new Test{1000}, 
                [] (Test *ptr)  {
                    std::cout << "\tUsing my custom lamdba deleter" << std::endl;
                    delete ptr;
                });
        }
        
        return 0;
    }

*/

