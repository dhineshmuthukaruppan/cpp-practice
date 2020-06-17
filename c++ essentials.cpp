/* 
https://www.geeksforgeeks.org/template-specialization-c/



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
    
        cout << int(x); 
    
        return 0; 
    } 
*/




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

