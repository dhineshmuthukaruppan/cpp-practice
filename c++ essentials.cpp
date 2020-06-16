#include <iostream>
#include <map>


using namespace std;

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
}