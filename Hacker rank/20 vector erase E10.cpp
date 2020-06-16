/* 

Sample Input

6
1 4 6 2 8 9
2    - deletes the element on the 2nd position
2 4  - deletes the element from 2nd position and 3rd position. inclusive start and exclusive end. 

Sample Output

3
1 8 9


 */



#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  

    int temp, temp1, n; 
    vector<int> vec; 

    cin >> n; 

    for(int i=0; i<n; i++){
        cin >> temp; 
        vec.push_back(temp);  
    }

    cin >> temp; 
    vec.erase(vec.begin() + (temp -1));       

    cin >> temp >> temp1;   
    vec.erase(vec.begin() + (temp - 1), vec.begin() + (temp1 - 1));     

    cout << vec.size() << endl;   
    
    auto it = vec.begin(); 
    while(it != vec.end()){
        cout << *it << " "; 
        ++it; 
    }

    return 0;
}