/* 1) overview 

    object oriented programming - classes and objects
    ----------------------------------------------
    - what is object oriented programming
    - what are classes and objects
    - declaring classes and creating objects
    - dot and pointer operators
    - public and private access modifiers
    - methods, constructors and destructors
        - class methods
        - default and overloaded constructors
        - copy and move constructors
        - shallow vs deep copying
        - this pointer
    - static class members
    - struct vs class
    - friend of a class

*/

/* 2) what is object oriented programming 

    - procedural programming
    - procedural programming limitations
    - oo programming concepts and their advantages
    - oo programming limitations

    procedural programming
    ------------------------
    - focus is on processes or actions that a program takes
    - programs are typically a collection of functions
    - data is declared separately
    - data is passes as arguments into functions
    - fairly easy to learn

    procedural programming limitations
    ----------------------------------
    - functions need to know the structure of the data
        - if the structure of the data changes many function must be changed
    - as programs get larger they become more
        - difficult to understand
        - difficult to maintain
        - difficult to extend
        - difficult to debug
        - difficult to reuse code
        - fragile and easier to break

    what is object oriented programming
    -----------------------------------
    - classes and objects
        - focus is on classes that model real world domain entities
        - allows developers to think at a higher level of abstraction
        - used successfully in very large programs
    
    - encapsulation
        - objects contain data and operations that work on that data
        - abstract data type

    - information hiding
        - implementation specific logic can be hidden
        - users of the class code to the interface since they don't need to know the implementation
        - more abstraction
        - easier to test, debug, maintain and extend

    - reusability
        - easier to reuse classes in other applications
        - faster development
        - higher quality

    - inheritance
        - can create new classes in term of existing classes
        - reusability 
        - polymorphic classes

    Limitations
    -------------
    - not a pancake 
        - oo programming won't make bad code better
        - not suitable for all types of problems
        - not everything decomposes to a class
    
    - learning curve
        - usually a steeper learning curve, especially for c++
        - many OO languages, many variations of OO concepts
    
    - design
        - usually more upfront design is necessary to create good models and hierarchy
    
    - programs can be
        - larger in size
        - slower 
        - more complex


*/


/* 3) classes and objects 

    classes
    -------
    - blueprint from which objects are created
    - a user defined datatype
    - has attributes (data)
    - has methods - functions
    - can hide data and methods
    - provides a public interface

    example classes
    ---------------
    - account
    - employee
    - image
    - std::vector
    - std::string

    objects
    ------
    - created from class
    - represents a specific instance of a class
    - can create many, many objects
    - each has its own identity
    - each can use the defined class methods

    example account objects
    ------------------------
    - frank' s account is an instance of an account
    - jim's accoutn is an instance of an account
    - each has its own balance, can make deposits, withdrawls etc. 


*/


/* 4) declaring a class 

    // Declare Classes and Objects
    #include <iostream>
    #include <string>
    #include <vector>

    using namespace std;

    class Player {
        // attributes
        string name {"Player"};
        int health {100};
        int xp {3};
        
        // methods
        void talk(string);
        bool is_dead();
    };

    class Account {
        // attributes
        string name {"Account"};
        double balance {0.0};
        
        // methods
        bool deposit(double);
        bool withdraw(double);
        
    };


    int main() {
        Account frank_account;
        Account jim_account;
        
        Player frank;
        Player hero;
        
        Player players[] {frank, hero};
        
        vector<Player> player_vec {frank};
        player_vec.push_back(hero);
        
        Player *enemy {nullptr};
        enemy = new Player;
        
        delete enemy;

        return 0;
    }

*/


/* 5) accessing class members 

    // Accessing Class Members
#include <iostream>
#include <string>

using namespace std;

class Player {
public:
    // attributes
    string name;
    int health;
    int xp;
    
    // methods
    void talk(string text_to_say) { cout << name << " says " << text_to_say << endl;  }
    bool is_dead();
};

class Account {
public:
    // attributes
    string name;
    double balance;
    
    // methods
    bool deposit(double bal) {balance += bal; cout << "In deposit" << endl; }
    bool withdraw(double bal) {balance -= bal; cout << "In withdraw" << endl;  }
    
};

int main() {
    Account frank_account;
    frank_account.name = "Frank's account";
    frank_account.balance = 5000.0;
    
    frank_account.deposit(1000.0);
    frank_account.withdraw(500.0);
    
    Player frank;
    frank.name = "Frank";
    frank.health = 100;
    frank.xp = 12;
    frank.talk("Hi there");
    
    Player *enemy = new Player;
    (*enemy).name = "Enemy";
    (*enemy).health = 100;
    enemy->xp = 15;
    
    enemy->talk("I will destroy you!");
    return 0;
}

*/



/* 7) public and private 

    class member access modifiers
    ------------------------------
    public 
        - accessible everywhere
    private
        - accessible only by members or friend of the class
    protected
        - used with inheritance 

    // Access Modifers
    #include <iostream>
    #include <string>

    using namespace std;

    class Player {
    private:
        // attributes
        string name {"Player"};
        int health;
        int xp;
    public:
        // methods
        void talk(string text_to_say) { cout << name << " says " << text_to_say << endl;  }
        bool is_dead();
    };

    int main() {
        Player frank;
    //  frank.name = "Frank";
    //  cout << frank.health << endl;
        frank.talk("Hello there");
        return 0;
    }

*/


/* 8) implementing member methods 

    - very similar to how we implemented functions
    - member methods have access to member attibutes
        - so you don't need to pass them as arguments
    - can be implemented inside class declaration
        - implicitly inline
    - can be implemented outside the class declaration
        - need to use class_name::method_name
    - can separate specification from implementaion
        - .h file for class declaration
        - .cpp file for class implementation


    // Implementing member methods 1 
    #include <iostream>
    #include <string>

    using namespace std;

    class Account {
    private:
        // attributes
        string name;
        double balance;
        
    public:
        // methods
        // declared inline
        void set_balance(double bal) { balance = bal; }
        double get_balance() { return balance; }
        
        // methods will be declared outside the class declaration
        void set_name(string n);
        string get_name();
        
        bool deposit(double amount);
        bool withdraw(double amount);
    };

    void Account::set_name(string n) {
        name = n;
    }

    string Account::get_name() {
        return name;
    }

    bool Account::deposit(double amount) {
        // if verify amount
        balance += amount;
        return true;
    }

    bool Account::withdraw(double amount) {
        if (balance-amount >= 0) {
            balance -= amount;
            return true;
        } else {
            return false;
        }
    }


    int main() {
        Account frank_account;
        frank_account.set_name("Frank's account");
        frank_account.set_balance(1000.0);
        
        if (frank_account.deposit(200.0))
            cout << "Deposit OK" << endl;
        else 
            cout << "Deposit Not allowed" << endl;
            
        if (frank_account.withdraw(500.0))
            cout << "Withdrawal OK" << endl;
        else
            cout << "Not sufficient funds" << endl;
            
        if (frank_account.withdraw(1500.0))
            cout << "Withdraw OK" << endl;
        else
            cout << "Not sufficient funds" << endl;
        
        return 0;
    }

    // Implementing member methods 2
    #include <iostream>
    #include "Account.h"

    using namespace std;

    int main() {
        Account frank_account;
        frank_account.set_name("Frank's account");
        frank_account.set_balance(1000.0);
        
        if (frank_account.deposit(200.0))
            cout << "Deposit OK" << endl;
        else 
            cout << "Deposit Not allowed" << endl;
            
        if (frank_account.withdraw(500.0))
            cout << "Withdrawal OK" << endl;
        else
            cout << "Not sufficient funds" << endl;
            
        if (frank_account.withdraw(1500.0))
            cout << "Withdraw OK" << endl;
        else
            cout << "Not sufficient funds" << endl; 
        
        return 0;
    }

    Account.h
    -----------
    #ifndef _ACCOUNT_H_
    #define _ACCOUNT_H_
    #include <string>

    class Account {
    private:
        // attributes
        std::string name;
        double balance;
        
    public:
        // methods
        // declared inline
        void set_balance(double bal) { balance = bal; }
        double get_balance() { return balance; }
        
        // methods will be declared outside the class declaration
        void set_name(std::string n);
        std::string get_name();
        
        bool deposit(double amount);
        bool withdraw(double amount);
    };

    #endif // _ACCOUNT_H_


    Account.cpp
    -------------
    #include "Account.h"

    void Account::set_name(std::string n) {
        name = n;
    }

    std::string Account::get_name() {
        return name;
    }

    bool Account::deposit(double amount) {
        // if verify amount
        balance += amount;
        return true;
    }

    bool Account::withdraw(double amount) {
        if (balance-amount >= 0) {
            balance -= amount;
            return true;
        } else {
            return false;
        }
    }

*/

