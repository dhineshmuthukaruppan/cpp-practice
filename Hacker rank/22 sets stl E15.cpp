#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

    int n, y, x;    
    set<int> s; 
    cin >> n; 
    for(int i=0; i<n; i++){
        cin >> y >> x; 
        if(y == 1){
            // add an element x to the set
            s.insert(x);    
        }else if(y == 2){
            // delete an element x from the set (if the x is not present then do nothing)
            s.erase(x);    

        }else if(y == 3){
            // if the number is present in the set then print "Yes" else "No"
            if(s.find(x) != s.end()){
                cout << "Yes" << endl; 
            }else{
                cout << "No" << endl; 
            }
        }
    }

    return 0;
}
