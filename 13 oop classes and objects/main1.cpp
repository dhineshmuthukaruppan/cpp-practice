/* 11) constructors and destructors 

    constructors
    -------------
    - special member method
    - invoked during object creation
    - useful for initialization
    - same name as the class
    - no return type is specified
    - can be overloaded

    destructors
    -----------
    - special member method
    - same name as the class proceeded with a tilde (~)
    - invoked automatically when an object is destroyed
    - no return type and no parameters
    - only 1 destructor is allowed per class - cannot be overloaded
    - useful to release memory and other resources


    // Constructors and Destructors

    #include <iostream>
    #include <string>

    using namespace std;

    class Player
    {
    private:
    std::string name;
    int health;
    int xp;
    public:
        void set_name(std::string name_val) { 
            name = name_val; 
        }
        // Overloaded Constructors
        Player() { 
            cout << "No args constructor called"<< endl;
        }
        Player(std::string name) { 
            cout << "String arg constructor called"<< endl;
        }
        Player(std::string name, int health, int xp) {
            cout << "Three args constructor called"<< endl; 
        }
        ~Player() { 
            cout << "Destructor called for " << name << endl; 
        }
    };

    int main() {

        {
            Player slayer;
            slayer.set_name("Slayer");
        }
        
        {
            Player frank;
            frank.set_name("Frank");
            Player hero("Hero");
            hero.set_name("Hero");
            Player villain("Villain", 100, 12);
            villain.set_name("Villain");
        }
        
        Player *enemy = new Player;
        enemy->set_name("Enemy");
        
        Player *level_boss = new Player("Level Boss", 1000, 300);
        level_boss->set_name("Level Boss");
        
        delete enemy;
        delete level_boss;
        
        return 0;
    }

*/


/* 12) default constructor

    - does not expect any arguments
        - also called no args constructor
    - if you write no constructors at all for a class
        - c++ will generate a default constructor that does nothing
    - called when you instantiate a new object with no arguments

    - However once we define a constructor for our class c++ will now not generate the no args constructor automatically

    Using the default constructor
    ----------------------------
        Player frank; 
        Player *enemy = new Player;     
        delete enemy;    

    Account - user defined no args constructor
    --------------------------------------------
        class Account {

            private:
                std::string name; 
                double balance; 
            public:
                Account(){
                    name = "None"; 
                    balance = 0.0; 
                }
                bool withdraw(double amount);
                bool deposit(double amount);  
        };  

    // Default Constructors
    #include <iostream>
    #include <string>

    using namespace std;

    class Player
    {
    private:
    std::string name;
    int health;
    int xp;
    public:
        void set_name(std::string name_val) { 
            name = name_val; 
        }
        std::string get_name() {
            return name;
        }
        Player() {
            name = "None";
            health = 100;
            xp = 3;
        }
        Player(std::string name_val, int health_val, int xp_val) {
            name = name_val;
            health = health_val;
            xp = xp_val;
        }
        
    };

    int main() {
        Player hero;
        Player frank {"Frank", 100, 13};
        frank.set_name("Frank");
        cout << frank.get_name() << endl;
        return 0;
    }

*/


/* 14) overloading constructors 
    - classes can have as many constructors as necessary
    - each must have a unique signature
    - default constructor is no longer compiler generated once another constructor is declared

    creating objects
    ----------------
    Player empty; // none, 0, 0
    Player hero {"hero"}; // hero, 0, 0
    Player frank {"frank", 100, 4}; // frank, 100, 4
    Player *enemy = new Player("Enemy", 1000, 0); // Enemy, 1000, 0
    delete enemy;    

*/


/* 16) constructor initialization lists

    - so far, all data member values have been set in the constructor body
    - constructor initialization lists
        - are moreefficient
        - initialization list immediately follows the parameter list
        - initializes the data member as the object is created instead of assigning it to already existing data
        - order of initialization is the order of declaration in the class
        

    // Constructor Initialization Lists
    #include <iostream>
    #include <string>

    using namespace std;

    class Player
    {
    private:
    std::string name {"XXXXXXX"};
    int health;
    int xp;
    public:
    // Overloaded Constructors
        Player();
        Player(std::string name_val);
        Player(std::string name_val, int health_val, int xp_val);
    };

    Player::Player() 
        : name{"None"}, health{0}, xp{0} {
    }

    Player::Player(std::string name_val) 
    : name{name_val}, health{0}, xp{0} {
    }
    
    Player::Player(std::string name_val, int health_val, int xp_val) 
        : name{name_val}, health{health_val}, xp{xp_val} {
        
    }

    int main() {
        
        Player empty;
        Player frank {"Frank"};
        Player villain {"Villain", 100, 55};
        
        return 0;
    }

*/



/* 17) delegating constructors 

    - often the code for constructor is very similar
    - duplicated code can lead to errors
    - c++ allows delegating constructors
        - code for one constructor can call another in the initialization list
        - avoids duplicating code

    // Delegating Constructors
    #include <iostream>
    #include <string>

    using namespace std;

    class Player
    {
    private:
    std::string name;
    int health;
    int xp;
    public:
    // Overloaded Constructors
        Player();
        Player(std::string name_val);
        Player(std::string name_val, int health_val, int xp_val);
    };

    Player::Player() 
        : Player {"None",0,0} {
            cout << "No-args constructor" << endl;
    }

    Player::Player(std::string name_val) 
    : Player {name_val,0, 0}  {
            cout << "One-arg constructor" << endl;
    }
    
    Player::Player(std::string name_val, int health_val, int xp_val) 
        : name{name_val}, health{health_val}, xp{xp_val} {
                cout << "Three-args constructor" << endl;
    }

    int main() {
        
        Player empty;
        Player frank {"Frank"};
        Player villain {"Villain", 100, 55};
        
        return 0;
    }

*/


/* 18) constructor parameters and default values 

    - can often simplify our code and reduct the number of overloaded constructors
    - same rules apply as we learned with nonmember functions

    // Default Constructor Parameters
    #include <iostream>
    #include <string>

    using namespace std;

    class Player
    {
    private:
    std::string name;
    int health;
    int xp;
    public:
        Player(std::string name_val ="None", int health_val = 0, int xp_val = 0);
    //  Player() {}    // Will cause a compiler error
    };
    
    Player::Player(std::string name_val, int health_val, int xp_val) 
        : name{name_val}, health{health_val}, xp{xp_val} {
                cout << "Three-args constructor" << endl;
    }

    int main() {
        
        Player empty;
        Player frank {"Frank"};
        Player hero {"Hero", 100};
        Player villain {"Villain", 100, 55};
        
        return 0;
    }

*/


/* 19) copy constructor 

    - when objects are copied c++ must create a new object from an existing object
    - when is a copy of an object made?
        - passing object by value as a parameter
        - returning an object from a function by value
        - constructing one object based on another of the same class

    - c++ must have a way of accomplishing this so it provides a compiler defined copy constructor if you don't

    pass object by value
    ---------------------
    Player hero {"Hero", 100, 20}
    void display(Player p){
        // p is a copy of the hero in this example
        // use p
        // destructor for p will be called
    }
    display(hero); 


    return object by value
    ----------------------
    Player enemy; 
    Player create_super_enemy(){
        Player anenemy{"super enemy", 1000, 1000}
        return anenemy; // copy of an enemy is returned
    }
    enemy = create_super_enemy();   


    construct one object based on another
    --------------------------------------
    Player hero {"hero", 100, 100};
    Player another_hero {hero}; // a copy of hero is made

    
    copy constructor
    ----------------
    - if you dont provide your own way of copying objects by value then the compiler provides a default way of copying objects
    - copies the values of each data member to the new object
        - default memberwise copy
    - perfectly fine in many cases
    - beware if you have a pointer data member
        - pointer will be copied
        - not what it is pointing to 
        - shallow vs deep copying 

    Best practices
    -------------
    - provide a copy constructor when your class has raw pointer members
    - provide the copy constructor with a const reference parameter
    - user STL classes as they already provide copy constructors
    - avoid using raw pointer data members if possible

    Declaring the copy constructor
    ------------------------------
    Type::Type(const Type &source);
    Player::Player(const Player &source)
        :   name{source.name}, 
            health{source.health}, 
            xp {source.xp}
    {
        // code or initialization list to copy the object- we are initializing the newly created object based on the existing source object
    } 



    // Copy Constructor
    #include <iostream>
    #include <string>

    using namespace std;

    class Player
    {
    private:
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
        ~Player() { cout << "Destructor called for: " << name << endl; }
    };

    Player::Player(std::string name_val, int health_val, int xp_val) 
        : name{name_val}, health{health_val}, xp{xp_val} {
                cout << "Three-args constructor for " + name << endl;
    }

    Player::Player(const Player &source)
    // : name(source.name), health(source.health), xp{source.xp} {
        : Player {source.name, source.health, source.xp}  {
            cout << "Copy constructor - made copy of: " << source.name << endl; 
    }

    void display_player(Player p) {
        cout << "Name: " << p.get_name() << endl;
        cout << "Health: " << p.get_health() << endl;
        cout << "XP: " << p.get_xp() << endl;    
    }

    int main() {    
        Player empty {"XXXXXX", 100, 50};
        
        Player my_new_object {empty};
        
        display_player(empty);
        
        Player frank {"Frank"};
        Player hero {"Hero", 100};
        Player villain {"Villain", 100, 55};
            
        return 0;
    }

*/





