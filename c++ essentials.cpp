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

