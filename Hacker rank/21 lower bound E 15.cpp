/* http://www.cplusplus.com/reference/algorithm/lower_bound/ */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;




int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   


    int n, q, temp;   
    vector<int> vec;   
    vector<int>::iterator low; 
    cin >> n; 
    for(int i=0; i<n; i++){
        cin >> temp; 
        vec.push_back(temp);
    }


    cin >> q; 
    for(int i=0; i<q; i++){
        int temp; 
        cin >> temp; 
        low = lower_bound(vec.begin(), vec.end(), temp);   
        int pos = (low - vec.begin()) + 1; 
        
        if(pos > vec.size()){
            // element not found
            cout << "No " << pos << endl; 
        }else{
            // element found
            if(vec[pos-1] != temp){
                cout << "No " << pos << endl;       
            }else{
                cout << "Yes " << pos << endl; 
            }  
        }

    }



    return 0;
}
