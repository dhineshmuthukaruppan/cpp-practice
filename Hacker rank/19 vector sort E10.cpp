#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

    int temp, n;
    vector<int> vec;  
    cin >> n; 
    for(int i=0; i<n; i++){
        cin >> temp; 
        vec.push_back(temp);    
    }

    sort(vec.begin(), vec.end());  
    auto it = vec.begin(); 
    while(it != vec.end()){
        cout << *it << " ";
        it++; 
    } 

    return 0;
}
