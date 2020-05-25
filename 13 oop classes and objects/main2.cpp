/* 21) shallow copying with copy constructor 

    shallow vs deep copying 
    -----------------------
    - consider a class that contains a pointer as a datamember
    - constructor allocates storage dynamically and initializes the pointer
    - destructor releases the memory allocated by the constructor
    - what happens in the default copy constructor?


    Default copy constructor
    -------------------------
    - memberwise copy 
    - each data member is copied from the source object
    - the pointer is copied not what it points to(shallow copy)
    - problem: when we release the storage in the destructor, the other object still refers to the released storage


    shalow copy constructor
    -----------------------
    Shallow::Shallow(const Shallow &source)
        :data(source.data){
        cout << "copy constructor - shallow"
    }
    shallow copy - only the pointer is copied - not what it is pointing to 
    problem: source and the newly created object both point to the same data area!


    // Copy Constructor - Shallow Copy
    // Note: this program will crash
    #include <iostream>

    using namespace std;

    class Shallow {
    private:
        int *data;
    public:
        void set_data_value(int d) { *data = d; }
        int get_data_value() { return *data; }
        // Constructor
        Shallow(int d);
        // Copy Constructor
        Shallow(const Shallow &source);
        // Destructor
        ~Shallow();
    };

    Shallow::Shallow(int d) {
        data = new int;
        *data = d;
    }

    Shallow::Shallow(const Shallow &source) 
        : data(source.data) {
            cout << "Copy constructor  - shallow copy" << endl;
    }

    Shallow::~Shallow() {
        delete data;
        cout << "Destructor freeing data" << endl;
    }

    void display_shallow(Shallow s) {
        cout << s.get_data_value() << endl;
    }

    int main() {
        
        Shallow obj1 {100};
        display_shallow(obj1);
        
        Shallow obj2 {obj1};
        obj2.set_data_value(1000);
        
        return 0;
    }

*/



/* 22) deep copying with the copy constructor 

    - create a copy of the pointed to data
    - each copy will have a pointer to unique storage in the heap
    - deep copy when you have a raw pointer as a class data member

    no problem: since the storage being releases is unique to s

    Deep constructor
    ----------------
    Deep::Deep(const Deep &source){
        data = new int; // allocate storage
        *data = *source.data; 
        cout << "copy constructor deep "; 
    }


    // Copy Constructor - Deep Copy
    #include <iostream>

    using namespace std;

    class Deep {
    private:
        int *data;
    public:
        void set_data_value(int d) { *data = d; }
        int get_data_value() { return *data; }
        // Constructor
        Deep(int d);
        // Copy Constructor
        Deep(const Deep &source);
        // Destructor
        ~Deep();
    };

    Deep::Deep(int d) {
        data = new int;
        *data = d;
    }

    Deep::Deep(const Deep &source)
        : Deep {*source.data} {
        cout << "Copy constructor  - deep copy" << endl;
    }

    Deep::~Deep() {
        delete data;
        cout << "Destructor freeing data" << endl;
    }

    void display_deep(Deep s) {
        cout << s.get_data_value() << endl;
    }

    int main() {
        
        Deep obj1 {100};
        display_deep(obj1);
        
        Deep obj2 {obj1};
        
        obj2.set_data_value(1000);
    
        return 0;
    }

*/


/* 23) move constructor 
    c++ move constructor moves the object rather that copying it. Move constructors are optional, if you don't provide them then the copy  constructors will be called. 

    - sometimes when we execute code the compiler creates unnamed temporary values
        int total {0};
        total = 100 + 200;

        - 100 + 200 is evaluated and 300 stored in an unnamed temp value
        - the 300 is then stored in the variable total
        - then the temp value is discarded    
    - the same happens with objects as well


    when is it useful?
    - sometimes copy constructors are called many times automatically due to the copy semantics of c++
    - copy constructors doing deep copying can have a significant performance bottlenect
    - c++11 introduced move semantics and the move constructor
    - move constructor moves an object rather than copying it
    - optional but recommended when you have a raw pointer
    - copy elision- c++ may optimize copying away completely (RVO - return value optimization)     

    lvalue references are references to lvalues. l value references are declared using &. 

    r value references
    ------------------
    - used in moving semantics and perfect forwarding
    - move semantics is all about rvalue references
    - used by move constructor and move assignment operator to efficiently move an object rather than copying it
    - rvalue reference operator &&

        int x{100};
        int &l_ref = x; // lvalue reference
        l_ref = 10; // change x to 10
        int &&r_ref = 200; // rvalue ref
        r_ref = 300; // change r_ref to 300
        int &&x_ref = x; // compiler error

    lvalue reference parameters
    ---------------------------
    int x{100}; // x is an lvalue
    void func(int &num); // A
    func(x); // calls A - x is an lvalue
    func(200); // Error - 200 is an rvalue

    error: cannot bind non-const lvalue reference of type int& to an rvalue of type int 


    rvalue refernece parameters
    --------------------------
    int x{100}; // x is an lvalue
    void func(int &&num); //B
    func(200); // calls B- 200 is an rvalue
    func(x); // error - x is an lvalue

    error: cannot bind rvalue reference of type int&& to lvalue of type int 


    lvalue and rvalue reference parameters
    ---------------------------------------
    int x{100}; // x is an lvalue
    void func(int &num); // A
    void func(int &&num); // B

    func(x); // calls A- x is an lvalue
    func(200); // calls B - 200 is an rvalue


    Inefficient copying
    -------------------
        Vector<Move> vec; 
        vec.push_back(Move{10}); // Move{10} = notice there's no variable name so that's going to create a temporary object and an termporary object is a rvalue. so in this case
                                // it's going to use the copy constructor. we have created the temporary and needs to be copied into the vector.
        vec.push_back({Move{20}});

    copy constuctors will be called to copy the temps


    what does move constructor do?
    ------------------------------
    - instead of making deep copy of the move constructor
        - moves the resources
        - simply copies the address of the resource from source to the current object. steal the data and then null out the source pointer
        - and null out the pointer in the source pointer
    - very efficient
    - move constructors will be called for temp rvalues


    inefficient copying
    -------------------
    constructor for 10
    constructor for 10
    copy constructor - deep copy for 10
    destructor freeing data for 10
    constructor for 20
    constructor for 20
    copy constructor - deep copy for 20
    constructor for 10
    copy constructor - deep copy for 10
    destructor freeing data for 10
    destructor freeing data for 20



    efficient output
    =----------------
    constructor for 10
    move constructor - moving resource :10 
    destructor freeing data for nullptr
    constructor for 20
    move constructor - moving resource :20
    move constructor - moving resource: 10
    destructor freeing data for nullptr
    destructor freeing data for nullptr
    destructor freeing data for 10
    destructor freeing data for 20



    // Move Constructor 
    #include <iostream>
    #include <vector>

    using namespace std;

    class Move {
    private:
        int *data;
    public:
        void set_data_value(int d) { *data = d; }
        int get_data_value() { return *data; }
        // Constructor
        Move(int d);
        // Copy Constructor
        Move(const Move &source);
        // Move Constructor
        Move(Move &&source) noexcept;
        // Destructor
        ~Move();
    };

    Move::Move(int d)  {
        data = new int;
        *data = d;
        cout << "Constructor for: " << d << endl;
    }

    // Copy ctor
    Move::Move(const Move &source)
        : Move {*source.data} {
            cout << "Copy constructor  - deep copy for: " << *data << endl;
    }

    //Move ctor
    Move::Move(Move &&source) noexcept 
        : data {source.data} {
            source.data = nullptr;
            cout << "Move constructor - moving resource: " << *data << endl;
    }

    Move::~Move() {
        if (data != nullptr) {
            cout << "Destructor freeing data for: " << *data << endl;
        } else {
            cout << "Destructor freeing data for nullptr" << endl;
        }
        delete data;
    }

    int main() {
        vector<Move> vec;

        vec.push_back(Move{10});

        vec.push_back(Move{20});
        vec.push_back(Move{30});
        vec.push_back(Move{40});
        vec.push_back(Move{50});
        vec.push_back(Move{60});
        vec.push_back(Move{70});
        vec.push_back(Move{80});


        return 0;
    }

*/


/* 24) this pointer 
    - this is a reserved keyword
    - contains the address of the object - so it's a pointer to the object
    - can only be used in class scope
    - all member access is done via this pointer
    - can be used by the programmer
        - to access data member and methods
        - to determine if two objects are the same 
        - can be derefenced(*this) to yield the current object

    void Account::set_Balance(double balance){
        this->balance = balance; // unambiguous
    }

    To determine object identity
    ---------------------------
    - sometimes its useful to know if two objects are the same object

            int Account::compare_balance(const Account &other){ 
                if(this == &other){
                    // same objects
                }
            }
            frank_account.compare(frank_account);

    - we'll use the this pointer again when we overload the assignment operator

*/



/* 26) static class members 

    - class data members can be declared as static
        - a single data member that belongs to the class, not the objects
        - useful to store class-wide information
    - class functions can be declared as static
        - independent of any objects
        - can be called using the class name
        - this function has access to only static data members
    
    c++ forbids inclass initialization of nonconst static members

    // Static class members -  main.cpp
    #include <iostream>
    #include "Player.h"

    using namespace std;

    void display_active_players() {
        cout << "Active players: " << Player::get_num_players() << endl;
    }

    int main() {
        display_active_players();
        Player hero{"Hero"};
        display_active_players();
        
        {
            Player frank{"Frank"};
            display_active_players();
        }
        display_active_players();
        
        Player *enemy = new Player("Enemy", 100, 100);
        display_active_players();
        delete enemy;
        display_active_players();    


        return 0;
    }

    Player.h
    ---------
    #ifndef _PLAYER_H_
    #define _PLAYER_H_
    #include <string>

    class Player
    {
    private:
    static int num_players;
    std::string name;
    int health;
    int xp;
    public:
        std::string get_name() { return name; }
        int get_health() { return health; }
        int get_xp() {return xp; } 
        Player(std::string name_val ="None", int health_val = 0, int xp_val = 0);
        // Copy constructor
        Player(const Player &source);
        // Destructor
        ~Player();
        
        static int get_num_players(); // can only access static data members
        
    };

    #endif // _PLAYER_H_


    Player.cpp
    ----------------
    #include "Player.h"

    int Player::num_players {0};

    Player::Player(std::string name_val, int health_val, int xp_val) 
        : name{name_val}, health{health_val}, xp{xp_val} {
            ++num_players;
    }

    Player::Player(const Player &source)
        : Player {source.name, source.health, source.xp}  {
    }

    Player::~Player() {
        --num_players;
    }

    int Player::get_num_players() {
        return num_players;
    }
*/


/* 27) struct vs classes 

    - in addition to define a class we can declare a struct
    - struct comes from c programming language
    - essentially the same as a class expect
        - members are public by default
    
    some general guidelines
    -----------------------
    struct
        - use struct for passive objects with public access
        - don't declare methods in struct
    
    class
        - use class for active objects with private access
        - implement getters / setters as needed
        - implement member methods as needed


*/


/* 28) friends of a class 

    Friend 
        - a function or class that has access to private class member
        - and, that function of or class is not a member of the class it is accessing
    
    function
        - can be regular non member functions
        - can be member methods of another class
    
    class
        - another class can have access to private class members


    Friends of class
    ----------------
    - friendship must be granted not taken
        - declared explicitly in the class that is granting friendship
        - declared in the function prototype with the keyword friend
    - friendship is symmetric
        - must be explicitly granted
            - if A is a friend of B
            - B is not a friend of A
    - friendship is not transitive
        - must be explicitly granted
            - if A is friend of B and 
            - B is a friend of c
            - then A is not a friend of C

*/


