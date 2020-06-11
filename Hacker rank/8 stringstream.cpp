




/* method 1 */
#include <sstream>
#include <vector>
#include <iostream>
#include <string>
using namespace std;

vector<int> parseInts(string str) {
	// Complete this function
    // str - 12,13
    vector<int> vec; 
    string s = ""; 
    for(int i=0; i<str.size(); i++){
        
        if(str[i] == ','){
            int temp = stoi(s);  
            vec.push_back(temp);
            s="";  

        }else{
            s+=str[i];   
        }
    } 

    int temp = stoi(s);
    vec.push_back(temp);
    
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