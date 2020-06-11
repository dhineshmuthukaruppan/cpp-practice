/* 

Sample Input

2 2
3 1 5 4
5 1 2 8 9 3
0 1
1 3

Sample Output

5
9

 */



#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    int q;

    cin >> n >> q;   

    vector<vector<int>> vec;   

    for(int i=0; i<n; i++){   
        int size;
        vector<int> temp;     
        cin >> size;   
        for(int j=0; j<size; j++){
            int temp_value;   
            cin >> temp_value;  
            temp.push_back(temp_value);    
        }
        vec.push_back(temp);   
    }

    for(int i=0; i<q; i++){
        int ithvector, jthelement;   
        cin >> ithvector >> jthelement; 

        cout << vec[ithvector][jthelement] << endl;    
    }


    return 0;
}