/* method 1 */
// #include <sstream>
// #include <vector>
// #include <iostream>
// #include <string>
// using namespace std;

// vector<int> parseInts(string str) {
// 	// Complete this function
//     // str - 12,13
//     vector<int> vec; 
//     string s = ""; 
//     for(int i=0; i<str.size(); i++){
        
//         if(str[i] == ','){
//             int temp = stoi(s);  
//             vec.push_back(temp);
//             s="";  

//         }else{
//             s+=str[i];   
//         }
//     } 

//     int temp = stoi(s);
//     vec.push_back(temp);
    
//     return vec; 
// }

// int main() {
//     string str;
//     cin >> str;
//     vector<int> integers = parseInts(str);
//     for(int i = 0; i < integers.size(); i++) {
//         cout << integers[i] << "\n";
//     }
    
//     return 0;
// }



#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
	// Complete this function
    vector<int> vec; 

    stringstream ss{str};   


    // WORKING
    
    // int a, b, c, d; 
    // char ch;
    // ss >> a >> ch >> b >> ch;

    // if(ss >> c){   
    //     cout << "extracted" << endl;    
    // }

    // vec.push_back(a); 
    // vec.push_back(b);
    // vec.push_back(c); 

    // it will not execute because there is nothing to extract, so that operation returns false. So both the below if condition will not execute
    // if(ss >> ch){
    //     cout << "extracted" << endl;   
    // }
    // if(ss >> a){
    //     cout << "extracted" << endl;   
    // }

    // END OF WORKING





    // INPUT: 1,5,16,20
    int a; 
    char ch;
    bool condition = true;
    bool even = true;     
    while(ss >> a){ 
        vec.push_back(a);
        if(ss >> ch){
            cout << "hi" << endl;   
        } 
    } 

    // Expected o/p
    /* 
        hi
        hi
        hi
        1
        5
        16
        28
     */

    return vec;   
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    return 0;
}