/* 
Sample Input
7
1 Jesse 20
1 Jess 12
1 Jess 18
3 Jess
3 Jesse
2 Jess
3 Jess

Sample Output

30
20
0

*/


#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 

    int q, x, y;     
    string temp_str; 
    map<string, int> mp; 

    cin >> q; 
    for(int i=0; i<q; i++){
        cin >> x ; 
        
        if(x == 1){
            // Add the marks to the student whose name is temp_str
            cin >> temp_str >> y; 
            if(mp.find(temp_str) != mp.end()){
                // found
                mp[temp_str] += y; 
            }else{
                // not found
                mp[temp_str] = y;      
            }

        }else if(x == 2){
            // erase the  marks of hte student whose name is temp_str
            cin >> temp_str; 
            mp.erase(temp_str);   

        }else if(x == 3){
            // print the marks of the students whose name is temp_str
            cin >> temp_str; 
            if(mp.find(temp_str) != mp.end()){
                cout << mp[temp_str] << endl; 
            }else{
                cout << "0" << endl; 
            }
        }

    }

    return 0;
}
