/* 
https://www.geeksforgeeks.org/template-specialization-c/

https://www.geeksforgeeks.org/count-distinct-elements-in-an-array/

https://www.geeksforgeeks.org/initialize-a-vector-in-cpp-different-ways/

 */



/* 
MAPS
=====
int main()
{
    map<int, int> mp {{1,2}};    
    auto it = mp.begin(); 
    cout << it->first << endl;  // 1 - key   
    cout<< mp.size() << endl; // 1
    if(mp.begin() == mp.end()){
        cout << "container is empty" << endl;
    }else{
        cout << "container is not empty" << endl;       
    }
    auto it1 = mp.find(1); 
    if(it != mp.end()){
        cout << mp[1] << endl; // 2 - prints the value
        cout << it->second << endl; // 2 - also prints the value
            
    }
    return 0;            
} */


/* function pointers  
#include <iostream>
#include <vector>

using namespace std; 
void helloworld(){ 
    cout << "hello world \n"; 
}
void fun(int a){
    cout << a << endl; 
}
void printValue(int value){
    cout << "value" << value << endl; 
}
void ForEach(const vector<int> &values, void (*func)(int)){
    for(int value : values)
        func(value);   
}
int main(){

    (*helloworld)();  // working
    helloworld();    // working

    auto function = helloworld; 
    function();     // working
    auto function1 = &helloworld; 
    function1();    // working 

    void (*function2)(); 
    function2 = helloworld; 
    function2();   // working
    (*function2)(); // working

    typedef void(*Helloworldfunction)(); 
    Helloworldfunction function3 = helloworld; 
    function3(); 
    
    typedef void(*Funfunction)(int);
    Funfunction function4 = fun; 
    function4(5);    

    cout << "address of function2 pointer is " << &function2 << endl;  // 0x7ffe1c0f8308 
    printf("address of function 2 pointer is %p \n", &function2);  // 0x7ffe1c0f8308 
    printf("address of hello world function is %p \n", helloworld );  // 0x56309507aa0a
    printf("address pointed to by function 2 is %p \n", function2);   // 0x56309507aa0a   


    int a{4}; 
    cout << "address of a :" << &a << endl;  

    int *p {&a};   
    cout << "address of a pointed by p : " << p << endl; 
    cout << "address of p itself : " << &p << endl;     

    vector<int> values {1, 5, 4};
    ForEach(values, printValue);   

    ForEach(values, [](int value){cout << value << endl; });      

    return 0;   
}

*/

/* lambdas in c++ 
    
    #include <iostream>
    #include <vector>
    #include <algorithm>
    #include <functional>

    void forEach(const std::vector<int> &values, const std::function<void(int)> &func){
        for(int value: values){
            func(value); 
        }
    }

    int main(){

        std::vector<int> values = {1, 5, 4, 2, 3}; 
        auto it = std::find_if(values.begin(), values.end(), [](int value){return value > 3; }); 

        std::cout << *it << std::endl; 

        int a = 5; 
        auto lambda = [=](int value){std::cout << "value: " << a << std::endl; }

        ForEach(values, lambda); 
    
    
    }   


*/


/*  const and pointers 

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



/* dynamic casting in c++ 

    syntax: dynamic_cast <new type> (expression)

    1) dynamic cast is used at runtime to find out correct down cast
    note 0: need atleast one virtual function in base class
    note 1: if the cast is successful, dynamic cast returns a value of type new_type
    note 2: if the cast fails and new type is a pointer type, it returns null pointer of that type
    note 3: if the cast fails and new_type is a reference type, it throws an exception 
    that matches a handler of type std::bad_cast


*/

/* static cast
https://en.cppreference.com/w/cpp/language/static_cast
 */


/* preprocessors
https://www.geeksforgeeks.org/cc-preprocessors/

#include <iostream>
#define toStr(x) #x
using namespace std; 
int main(){
    cout << toStr(Result =)  << endl; 
    return 0;   
}

 */

/* we can subtract characters in c++
#include <iostream>
using namespace std; 
ostream& operator<<(ostream &out, const Person &p){  // we are not supposed to use const ostream &out
    out << "first_name="<< p.get_first_name() << ",last_name=" << p.get_last_name();
    return out;  
}
int main(){
    int a = 'a' - '0';
    cout << "value is " << a; 
    // while(s[i]!='+')
    // {
    //     v1=v1*10+s[i]-'0';
    //     i++;
    // }
    return 0;        
} */


/* enumeration
    https://www.geeksforgeeks.org/enum-classes-in-c-and-their-advantage-over-enum-datatype/

    an enumerated type declares an optional type name and set of zero or more identifiers that
    can be used as values of the type. each enumerator is a constant whose type is the enumeration
    - to create an enumeration requires the use of the keyword enum. The general form of enumeration
    type is 
        enum enum-name {list of names } var-list; 

    - here, the enum-name is the enumeration's type name. The list of names is comma separated
    - for example the following code defines an enumeration of colors called colors and the variable
        c of type color. finally c is assigned the value blue; 
            enum color {red, gree, blue } c; 
            c= blue; 
    - by default, the value of the first name is 0, the second name has the value 1, the
        third has the value 2, and so on. But you can give a name a specific value by adding
        an initializer. For example, in the following enumeration, green will have value 5
            enum color {red, green=5, blue}; 
    - here blue will have a value of 6 because each name will be one greater than the one
    that precedes it. 


    #include <iostream>
    using namespace std; 
    enum week {sunday, monday, tuesday, wednesday..., saturday}; 

    int main(){
        week currentday; 
        currentday = Wednesday; 
        cout << currentday; // 3 
        cout << currentday +1; // 4
        return 0; 
    }


    C++11 has introduced enum classes (also called scoped enumerations), that makes enumerations 
    both strongly typed and strongly scoped. Class enum doesn’t allow implicit conversion to int, 
    and also doesn’t compare enumerators from different enumerations.
    
    // Declaration
    enum class Color{ Red, Green, Blue};

    // Initialisation
    Color col = Color::Red;


    // C++ program to demonstrate working 
    // of Enum Classes 
    #include <iostream> 
    using namespace std; 
    int main() 
    { 
        enum class Color { Red, 
                        Green, 
                        Blue }; 
        enum class Color2 { Red, 
                            Black, 
                            White }; 
        enum class People { Good, 
                            Bad }; 
        // An enum value can now be used 
        // to create variables 
        int Green = 10; 

        // Instantiating the Enum Class 
        Color x = Color::Green; 
        // Comparison now is completely type-safe 
        if (x == Color::Red) 
            cout << "It's Red\n"; 
        else
            cout << "It's not Red\n"; 
    
        People p = People::Good; 
    
        if (p == People::Bad) 
            cout << "Bad people\n"; 
        else
            cout << "Good people\n"; 
    
        // gives an error 
        // if(x == p) 
        // cout<<"red is equal to good"; 
    
        // won't work as there is no 
        // implicit conversion to int 
        // cout<< x; 
    
        cout << int(x) << endl;

        int a = static_cast<int>(x);  
        cout << a << endl;    
    
        return 0; 
    } 

*/



/* namespaces in c++ 

    namespace orange{
        namespace functions{
            void print(){
                cout << "orange \n"; 
            }
        }

        void print_again(){

        }
    }
    // call like this - orange::functions::print(); 

    namespace apple{
        void print(){
            cout << "apple \n"; 
        }
    }
    int main(){
        orange::print();  
        using namespace apple; 
        print(); 

        using apple::print;
        print(); 

        namespace a = apple; 
        a::print("Hello");   
        
        return 0; 
    }
*/



/* function pointers in c++ 





*/



